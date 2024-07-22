FROM ubuntu:20.04

ENV DEBIAN_FRONTEND=noninteractive

RUN apt-get clean && \
    apt-get autoclean

# install ros noetic
RUN apt update && \ 
    apt install  -y \
    curl \
    lsb-release \
    gnupg gnupg1 gnupg2 \
    gdb 

# curl: 用于从URL下载文件的命令行工具 
# lsb-release: 用于打印发行版特定信息的命令
# gnupg gnupg1 gnupg2: 安装 GNU Privacy Guard (GnuPG) 软件包，用于加密和签名数据


# 添加 ROS 密钥
RUN apt-key adv --keyserver 'hkp://keyserver.ubuntu.com:80' --recv-key C1CF6E31E6BADE8868B172B4F42ED6FBAB17C654
# apt-key adv: 用于管理 APT 软件包管理器的密钥。
# --keyserver 'hkp://keyserver.ubuntu.com:80': 指定从 Ubuntu 密钥服务器获取密钥。
# --recv-key C1CF6E31E6BADE8868B172B4F42ED6FBAB17C654: 接收并添加指定的 ROS 密钥，用于验证 ROS 软件包的来源

# 添加 ROS 软件源
RUN  sh -c '. /etc/lsb-release && echo "deb http://mirrors.tuna.tsinghua.edu.cn/ros/ubuntu/ `lsb_release -cs` main" > /etc/apt/sources.list.d/ros-latest.list'

# # 更新软件包列表并安装 ROS Noetic 及相关依赖项
RUN apt update && \
    apt install -y  ros-noetic-desktop-full \
    python3-rosdep python3-rosinstall python3-rosinstall-generator python3-wstool build-essential

# # 将 ROS Noetic 的环境设置脚本添加到 ~/.bashrc
RUN echo "source /opt/ros/noetic/setup.bash" >> ~/.bashrc


# 第三方库
RUN apt update && \
    apt install -y \
    vim \
    htop \
    apt-utils \
    curl \
    cmake \
    net-tools

# 宿主机拷贝到容器
COPY install/abseil /tmp/install/abseil
RUN /tmp/install/abseil/install_abseil.sh

COPY install/protobuf /tmp/install/protobuf
RUN /tmp/install/protobuf/install_protobuf.sh

RUN echo "source /work/devel/setup.bash" >> ~/.bashrc
# 通过这条命令，确保每次打开一个新的 shell 会话时，都会自动加载 /work/devel/setup.bash 中的配置，这样你在这个工作空间中的 ROS 包和其他资源就会被正确加载和使用

WORKDIR /work


