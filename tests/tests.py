from zipkinStubServer import ServerGuard, ZipkinStubServer
import _cppkin
from _cppkin import Trace, CppkinParams, Logger
import unittest
from Queue import Queue
from threading import Event

outQueue = None
startEvent = None

class TestCppkin(unittest.TestCase):
    def setUp(self):
        params = CppkinParams()
        params.add_str(_cppkin.HOST_ADDRESS, "127.0.0.1")
        params.add_int(_cppkin.PORT, 9411)
        params.add_str(_cppkin.SERVICE_NAME, "cppkinTest")
        params.add_bool(_cppkin.DEBUG, True)
        params.add_str(_cppkin.TRANSPORT_TYPE, "Http Transport")
        params.add_int(_cppkin.SAMPLE_COUNT, 1)

        _cppkin.init( params )

class TestCppkinTrace(TestCppkin):
    def runTest(self):
        trace = Trace("TestTrace")
        trace.submit()

        global outQueue
        spans = outQueue.get()
        self.assertEqual(len(spans), 1, "The amount of received spans dosn't match expected {0} != {1}". format(len(spans), 1))
        self.assertEqual(spans[0].name, "TestTrace", "Trace name dosn't match {0} != {1}".format(spans[0].name, "TestTrace"))
        self.assertEqual(spans[0].id, spans[0].traceId, "Trace id dosn't match id {0} != {1}".format(spans[0].id, spans[0].traceId))


class TestCppkinTraceSpanRelation(TestCppkin):
    def runTest(self):
        trace = Trace("TestTrace")
        span = trace.createSpan("TestSpan", _cppkin.SERVER_RECEIVE)
        span.submit()
        trace.submit()

        global outQueue
        spans = []
        while(len(spans) != 2):
            spans.extend(outQueue.get())

        self.assertEqual(len(spans), 2, "The amount of received spans dosn't match expected {0} != {1}". format(len(spans), 1))
        self.assertEqual(spans[0].name, "TestSpan", "Span name dosn't match {0} != {1}".format(spans[0].name, "TestSpan"))
        self.assertEqual(spans[0].traceId, spans[1].id, "Span trace id dosn't match trace's id {0} != {1}".format(spans[0].traceId, spans[1].id))
        self.assertEqual(spans[0].parentId, spans[1].id, "Span parent id dosn't match trace's id {0} != {1}".format(spans[0].parentId, spans[1].id))

def main():
    global outQueue
    global startEvent
    server = ZipkinStubServer()
    outQueue = Queue()
    startEvent = Event()
    with ServerGuard(ZipkinStubServer.spawn, server, outQueue, startEvent):
        unittest.main(exit=False)
        server.stop()


if __name__ == "__main__":
    Logger.instance().start(_cppkin.TraceSeverity.Info)
    main()