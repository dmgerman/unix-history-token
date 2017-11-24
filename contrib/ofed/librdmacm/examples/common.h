begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2005-2012 Intel Corporation.  All rights reserved.  *  * This software is available to you under a choice of one of two  * licenses.  You may choose to be licensed under the terms of the GNU  * General Public License (GPL) Version 2, available from the file  * COPYING in the main directory of this source tree, or the  * OpenIB.org BSD license below:  *  *     Redistribution and use in source and binary forms, with or  *     without modification, are permitted provided that the following  *     conditions are met:  *  *      - Redistributions of source code must retain the above  *        copyright notice, this list of conditions and the following  *        disclaimer.  *  *      - Redistributions in binary form must reproduce the above  *        copyright notice, this list of conditions and the following  *        disclaimer in the documentation and/or other materials  *        provided with the distribution.  *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,  * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF  * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND  * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS  * BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN  * ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN  * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE  * SOFTWARE.  *  * $Id$  */
end_comment

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<infiniband/endian.h>
end_include

begin_include
include|#
directive|include
file|<poll.h>
end_include

begin_include
include|#
directive|include
file|<rdma/rdma_cma.h>
end_include

begin_include
include|#
directive|include
file|<rdma/rsocket.h>
end_include

begin_include
include|#
directive|include
file|<infiniband/ib.h>
end_include

begin_decl_stmt
specifier|extern
name|int
name|use_rs
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|rs_socket
parameter_list|(
name|f
parameter_list|,
name|t
parameter_list|,
name|p
parameter_list|)
value|use_rs ? rsocket(f,t,p)  : socket(f,t,p)
end_define

begin_define
define|#
directive|define
name|rs_bind
parameter_list|(
name|s
parameter_list|,
name|a
parameter_list|,
name|l
parameter_list|)
value|use_rs ? rbind(s,a,l)    : bind(s,a,l)
end_define

begin_define
define|#
directive|define
name|rs_listen
parameter_list|(
name|s
parameter_list|,
name|b
parameter_list|)
value|use_rs ? rlisten(s,b)    : listen(s,b)
end_define

begin_define
define|#
directive|define
name|rs_connect
parameter_list|(
name|s
parameter_list|,
name|a
parameter_list|,
name|l
parameter_list|)
value|use_rs ? rconnect(s,a,l) : connect(s,a,l)
end_define

begin_define
define|#
directive|define
name|rs_accept
parameter_list|(
name|s
parameter_list|,
name|a
parameter_list|,
name|l
parameter_list|)
value|use_rs ? raccept(s,a,l)  : accept(s,a,l)
end_define

begin_define
define|#
directive|define
name|rs_shutdown
parameter_list|(
name|s
parameter_list|,
name|h
parameter_list|)
value|use_rs ? rshutdown(s,h)  : shutdown(s,h)
end_define

begin_define
define|#
directive|define
name|rs_close
parameter_list|(
name|s
parameter_list|)
value|use_rs ? rclose(s)       : close(s)
end_define

begin_define
define|#
directive|define
name|rs_recv
parameter_list|(
name|s
parameter_list|,
name|b
parameter_list|,
name|l
parameter_list|,
name|f
parameter_list|)
value|use_rs ? rrecv(s,b,l,f)  : recv(s,b,l,f)
end_define

begin_define
define|#
directive|define
name|rs_send
parameter_list|(
name|s
parameter_list|,
name|b
parameter_list|,
name|l
parameter_list|,
name|f
parameter_list|)
value|use_rs ? rsend(s,b,l,f)  : send(s,b,l,f)
end_define

begin_define
define|#
directive|define
name|rs_recvfrom
parameter_list|(
name|s
parameter_list|,
name|b
parameter_list|,
name|l
parameter_list|,
name|f
parameter_list|,
name|a
parameter_list|,
name|al
parameter_list|)
define|\
value|use_rs ? rrecvfrom(s,b,l,f,a,al) : recvfrom(s,b,l,f,a,al)
end_define

begin_define
define|#
directive|define
name|rs_sendto
parameter_list|(
name|s
parameter_list|,
name|b
parameter_list|,
name|l
parameter_list|,
name|f
parameter_list|,
name|a
parameter_list|,
name|al
parameter_list|)
define|\
value|use_rs ? rsendto(s,b,l,f,a,al)   : sendto(s,b,l,f,a,al)
end_define

begin_define
define|#
directive|define
name|rs_poll
parameter_list|(
name|f
parameter_list|,
name|n
parameter_list|,
name|t
parameter_list|)
value|use_rs ? rpoll(f,n,t)	   : poll(f,n,t)
end_define

begin_define
define|#
directive|define
name|rs_fcntl
parameter_list|(
name|s
parameter_list|,
name|c
parameter_list|,
name|p
parameter_list|)
value|use_rs ? rfcntl(s,c,p)   : fcntl(s,c,p)
end_define

begin_define
define|#
directive|define
name|rs_setsockopt
parameter_list|(
name|s
parameter_list|,
name|l
parameter_list|,
name|n
parameter_list|,
name|v
parameter_list|,
name|ol
parameter_list|)
define|\
value|use_rs ? rsetsockopt(s,l,n,v,ol) : setsockopt(s,l,n,v,ol)
end_define

begin_define
define|#
directive|define
name|rs_getsockopt
parameter_list|(
name|s
parameter_list|,
name|l
parameter_list|,
name|n
parameter_list|,
name|v
parameter_list|,
name|ol
parameter_list|)
define|\
value|use_rs ? rgetsockopt(s,l,n,v,ol) : getsockopt(s,l,n,v,ol)
end_define

begin_union
union|union
name|socket_addr
block|{
name|struct
name|sockaddr
name|sa
decl_stmt|;
name|struct
name|sockaddr_in
name|sin
decl_stmt|;
name|struct
name|sockaddr_in6
name|sin6
decl_stmt|;
block|}
union|;
end_union

begin_enum
enum|enum
name|rs_optimization
block|{
name|opt_mixed
block|,
name|opt_latency
block|,
name|opt_bandwidth
block|}
enum|;
end_enum

begin_function_decl
name|int
name|get_rdma_addr
parameter_list|(
specifier|const
name|char
modifier|*
name|src
parameter_list|,
specifier|const
name|char
modifier|*
name|dst
parameter_list|,
specifier|const
name|char
modifier|*
name|port
parameter_list|,
name|struct
name|rdma_addrinfo
modifier|*
name|hints
parameter_list|,
name|struct
name|rdma_addrinfo
modifier|*
modifier|*
name|rai
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|size_str
parameter_list|(
name|char
modifier|*
name|str
parameter_list|,
name|size_t
name|ssize
parameter_list|,
name|long
name|long
name|size
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|cnt_str
parameter_list|(
name|char
modifier|*
name|str
parameter_list|,
name|size_t
name|ssize
parameter_list|,
name|long
name|long
name|cnt
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|size_to_count
parameter_list|(
name|int
name|size
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|format_buf
parameter_list|(
name|void
modifier|*
name|buf
parameter_list|,
name|int
name|size
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|verify_buf
parameter_list|(
name|void
modifier|*
name|buf
parameter_list|,
name|int
name|size
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|do_poll
parameter_list|(
name|struct
name|pollfd
modifier|*
name|fds
parameter_list|,
name|int
name|timeout
parameter_list|)
function_decl|;
end_function_decl

end_unit

