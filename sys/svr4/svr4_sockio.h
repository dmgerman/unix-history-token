begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1998 Mark Newton  * Copyright (c) 1995 Christos Zoulas  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. The name of the author may not be used to endorse or promote products  *    derived from this software without specific prior written permission  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *   * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SVR4_SOCKIO_H_
end_ifndef

begin_define
define|#
directive|define
name|_SVR4_SOCKIO_H_
end_define

begin_define
define|#
directive|define
name|SVR4_IFF_UP
value|0x0001
end_define

begin_define
define|#
directive|define
name|SVR4_IFF_BROADCAST
value|0x0002
end_define

begin_define
define|#
directive|define
name|SVR4_IFF_DEBUG
value|0x0004
end_define

begin_define
define|#
directive|define
name|SVR4_IFF_LOOPBACK
value|0x0008
end_define

begin_define
define|#
directive|define
name|SVR4_IFF_POINTOPOINT
value|0x0010
end_define

begin_define
define|#
directive|define
name|SVR4_IFF_NOTRAILERS
value|0x0020
end_define

begin_define
define|#
directive|define
name|SVR4_IFF_RUNNING
value|0x0040
end_define

begin_define
define|#
directive|define
name|SVR4_IFF_NOARP
value|0x0080
end_define

begin_define
define|#
directive|define
name|SVR4_IFF_PROMISC
value|0x0100
end_define

begin_define
define|#
directive|define
name|SVR4_IFF_ALLMULTI
value|0x0200
end_define

begin_define
define|#
directive|define
name|SVR4_IFF_INTELLIGENT
value|0x0400
end_define

begin_define
define|#
directive|define
name|SVR4_IFF_MULTICAST
value|0x0800
end_define

begin_define
define|#
directive|define
name|SVR4_IFF_MULTI_BCAST
value|0x1000
end_define

begin_define
define|#
directive|define
name|SVR4_IFF_UNNUMBERED
value|0x2000
end_define

begin_define
define|#
directive|define
name|SVR4_IFF_PRIVATE
value|0x8000
end_define

begin_struct
struct|struct
name|svr4_ifreq
block|{
define|#
directive|define
name|SVR4_IFNAMSIZ
value|16
name|char
name|svr4_ifr_name
index|[
name|SVR4_IFNAMSIZ
index|]
decl_stmt|;
union|union
block|{
name|struct
name|osockaddr
name|ifru_addr
decl_stmt|;
name|struct
name|osockaddr
name|ifru_dstaddr
decl_stmt|;
name|struct
name|osockaddr
name|ifru_broadaddr
decl_stmt|;
name|short
name|ifru_flags
decl_stmt|;
name|int
name|ifru_metric
decl_stmt|;
name|char
name|ifru_data
decl_stmt|;
name|char
name|ifru_enaddr
index|[
literal|6
index|]
decl_stmt|;
name|int
name|if_muxid
index|[
literal|2
index|]
decl_stmt|;
block|}
name|ifr_ifru
union|;
define|#
directive|define
name|svr4_ifr_addr
value|ifr_ifru.ifru_addr
define|#
directive|define
name|svr4_ifr_dstaddr
value|ifr_ifru.ifru_dstaddr
define|#
directive|define
name|svr4_ifr_broadaddr
value|ifr_ifru.ifru_broadaddr
define|#
directive|define
name|svr4_ifr_flags
value|ifr_ifru.ifru_flags
define|#
directive|define
name|svr4_ifr_metric
value|ifr_ifru.ifru_metric
define|#
directive|define
name|svr4_ifr_data
value|ifr_ifru.ifru_data
define|#
directive|define
name|svr4_ifr_enaddr
value|ifr_ifru.ifru_enaddr
define|#
directive|define
name|svr4_ifr_muxid
value|ifr_ifru.ifru_muxid
block|}
struct|;
end_struct

begin_struct
struct|struct
name|svr4_ifconf
block|{
name|int
name|svr4_ifc_len
decl_stmt|;
union|union
block|{
name|caddr_t
name|ifcu_buf
decl_stmt|;
name|struct
name|svr4_ifreq
modifier|*
name|ifcu_req
decl_stmt|;
block|}
name|ifc_ifcu
union|;
define|#
directive|define
name|svr4_ifc_buf
value|ifc_ifcu.ifcu_buf
define|#
directive|define
name|svr4_ifc_req
value|ifc_ifcu.ifcu_req
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|SVR4_SIOC
value|('i'<< 8)
end_define

begin_define
define|#
directive|define
name|SVR4_SIOCGIFFLAGS
value|SVR4_IOWR('i', 17, struct svr4_ifreq)
end_define

begin_define
define|#
directive|define
name|SVR4_SIOCGIFCONF
value|SVR4_IOWR('i', 20, struct svr4_ifconf)
end_define

begin_define
define|#
directive|define
name|SVR4_SIOCGIFNUM
value|SVR4_IOR('i', 87, int)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_SVR4_SOCKIO_H_ */
end_comment

end_unit

