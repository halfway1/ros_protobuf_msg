#!/usr/bin/env bash

# 源码目录
MONITOR_HOME_DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )/../.." && pwd )"

# 为了ros相关工具的界面显示
display=""
if [ -z ${DISPLAY} ];then
    display=":1"
else
    display="${DISPLAY}"
fi

# 本质是为了和宿主机的文件属性一致
local_host="$(hostname)"
user="${USER}"
uid="$(id -u)"
group="$(id -g -n)"
gid="$(id -g)"


echo "stop and rm docker" 
docker stop ros_noetic_proto > /dev/null
docker rm -v -f ros_noetic_proto > /dev/null

echo "start docker"
docker run -it -d \
--privileged=true \
--name ros_noetic_proto \
-e DISPLAY=$display \
-e DOCKER_USER="${user}" \
-e USER="${user}" \
-e DOCKER_USER_ID="${uid}" \
-e DOCKER_GRP="${group}" \
-e DOCKER_GRP_ID="${gid}" \
-e XDG_RUNTIME_DIR=$XDG_RUNTIME_DIR \
-v ${MONITOR_HOME_DIR}:/work \
-v ${XDG_RUNTIME_DIR}:${XDG_RUNTIME_DIR} \
--network host \
ros_protobuf:noetic
# 镜像文件名