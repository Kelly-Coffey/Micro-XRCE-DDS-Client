// Copyright 2018 Proyectos y Sistemas de Mantenimiento SL (eProsima).
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#ifndef _MICRORTPS_CLIENT_PROFILE_COMMUNICATION_UDP_TRANSPORT_H_
#define _MICRORTPS_CLIENT_PROFILE_COMMUNICATION_UDP_TRANSPORT_H_

#ifdef __cplusplus
extern "C"
{
#endif
    
#include <micrortps/client/communication/transport_layer.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define UDP_TRANSPORT_LINUX_MTU 512

typedef struct UDPTransport UDPTransport;
struct UDPTransport
{
    TransportLayer* transport_layer;
    uint8_t buffer[UDP_TRANSPORT_LINUX_MTU];
    int socketfd;
    struct sockaddr remote_addr;
};

int init_udp_transport(UDPTransport* udp_transport, const char* ip, uint16_t port);

#ifdef __cplusplus
}
#endif

#endif //_MICRORTPS_CLIENT_PROFILE_COMMUNICATION_UDP_TRANSPORT_H_