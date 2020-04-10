set -e

edited_tag=$(echo $2 | sed 's/\//\_/g')
docker build -t registry.devel.b1ops.net/b1automation/$1:$edited_tag .
docker push registry.devel.b1ops.net/b1automation/$1:$edited_tag
docker rmi registry.devel.b1ops.net/b1automation/$1:$edited_tag
