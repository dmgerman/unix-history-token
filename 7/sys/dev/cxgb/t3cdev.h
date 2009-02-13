begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2007-2008, Chelsio Inc.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions are met:  *  * 1. Redistributions of source code must retain the above copyright notice,  *    this list of conditions and the following disclaimer.  *  * 2. Neither the name of the Chelsio Corporation nor the names of its  *    contributors may be used to endorse or promote products derived from  *    this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"  * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE  * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN  * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  * POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_T3CDEV_H_
end_ifndef

begin_define
define|#
directive|define
name|_T3CDEV_H_
end_define

begin_define
define|#
directive|define
name|T3CNAMSIZ
value|16
end_define

begin_comment
comment|/* Get the t3cdev associated with an ifnet */
end_comment

begin_define
define|#
directive|define
name|T3CDEV
parameter_list|(
name|ifp
parameter_list|)
value|(&(((struct port_info *)(ifp)->if_softc))->adapter->tdev)
end_define

begin_struct_decl
struct_decl|struct
name|cxgb3_client
struct_decl|;
end_struct_decl

begin_enum
enum|enum
name|t3ctype
block|{
name|T3A
init|=
literal|0
block|,
name|T3B
block|,
name|T3C
block|}
enum|;
end_enum

begin_struct
struct|struct
name|t3cdev
block|{
name|char
name|name
index|[
name|T3CNAMSIZ
index|]
decl_stmt|;
comment|/* T3C device name */
name|enum
name|t3ctype
name|type
decl_stmt|;
name|TAILQ_ENTRY
argument_list|(
argument|t3cdev
argument_list|)
name|entry
expr_stmt|;
comment|/* for list linking */
name|struct
name|ifnet
modifier|*
name|lldev
decl_stmt|;
comment|/* LL dev associated with T3C messages */
name|struct
name|adapter
modifier|*
name|adapter
decl_stmt|;
name|int
function_decl|(
modifier|*
name|send
function_decl|)
parameter_list|(
name|struct
name|t3cdev
modifier|*
name|dev
parameter_list|,
name|struct
name|mbuf
modifier|*
name|m
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|recv
function_decl|)
parameter_list|(
name|struct
name|t3cdev
modifier|*
name|dev
parameter_list|,
name|struct
name|mbuf
modifier|*
modifier|*
name|m
parameter_list|,
name|int
name|n
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|ctl
function_decl|)
parameter_list|(
name|struct
name|t3cdev
modifier|*
name|dev
parameter_list|,
name|unsigned
name|int
name|req
parameter_list|,
name|void
modifier|*
name|data
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|arp_update
function_decl|)
parameter_list|(
name|struct
name|t3cdev
modifier|*
name|dev
parameter_list|,
name|struct
name|rtentry
modifier|*
name|neigh
parameter_list|,
name|uint8_t
modifier|*
name|enaddr
parameter_list|,
name|struct
name|sockaddr
modifier|*
name|sa
parameter_list|)
function_decl|;
name|void
modifier|*
name|priv
decl_stmt|;
comment|/* driver private data */
name|void
modifier|*
name|l2opt
decl_stmt|;
comment|/* optional layer 2 data */
name|void
modifier|*
name|l3opt
decl_stmt|;
comment|/* optional layer 3 data */
name|void
modifier|*
name|l4opt
decl_stmt|;
comment|/* optional layer 4 data */
name|void
modifier|*
name|ulp
decl_stmt|;
comment|/* ulp stuff */
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _T3CDEV_H_ */
end_comment

end_unit

