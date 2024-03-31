FROM ubuntu:22.04

RUN apt-get update && \
  apt-get install -y pkg-config build-essential cmake wget && \
  rm -rf /var/lib/apt/lists/*


COPY envsetup.sh ./
COPY entrypoint.sh ./
RUN chmod +x envsetup.sh entrypoint.sh
RUN ./envsetup.sh

WORKDIR /app

ENTRYPOINT ["/entrypoint.sh"]