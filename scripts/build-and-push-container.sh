set -e

edited_tag=$(echo $3 | sed 's/\//\_/g')
docker build -t registry.devel.b1ops.net/b1automation/$1_$2:$edited_tag . -f $2.Dockerfile
docker push registry.devel.b1ops.net/b1automation/$1_$2:$edited_tag
docker rmi registry.devel.b1ops.net/b1automation/$1_$2:$edited_tag
