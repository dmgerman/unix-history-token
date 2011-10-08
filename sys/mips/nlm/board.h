begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright 2003-2011 Netlogic Microsystems (Netlogic). All rights  * reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions are  * met:  *  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in  *    the documentation and/or other materials provided with the  *    distribution.  *  * THIS SOFTWARE IS PROVIDED BY Netlogic Microsystems ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR  * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL NETLOGIC OR CONTRIBUTORS BE  * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN  * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF  * THE POSSIBILITY OF SUCH DAMAGE.  *  * NETLOGIC_BSD  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__NLM_BOARD_H__
end_ifndef

begin_define
define|#
directive|define
name|__NLM_BOARD_H__
end_define

begin_define
define|#
directive|define
name|XLP_NAE_NBLOCKS
value|5
end_define

begin_define
define|#
directive|define
name|XLP_NAE_NPORTS
value|4
end_define

begin_define
define|#
directive|define
name|XLP_I2C_MAXDEVICES
value|8
end_define

begin_struct
struct|struct
name|xlp_i2c_devinfo
block|{
name|u_int
name|addr
decl_stmt|;
comment|/* keep first, for i2c ivars to work */
name|int
name|bus
decl_stmt|;
name|char
modifier|*
name|device
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|xlp_port_ivars
block|{
name|int
name|port
decl_stmt|;
name|int
name|block
decl_stmt|;
name|int
name|type
decl_stmt|;
name|int
name|phy_addr
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|xlp_block_ivars
block|{
name|int
name|block
decl_stmt|;
name|int
name|type
decl_stmt|;
name|u_int
name|portmask
decl_stmt|;
name|struct
name|xlp_port_ivars
name|port_ivars
index|[
name|XLP_NAE_NPORTS
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|xlp_nae_ivars
block|{
name|int
name|node
decl_stmt|;
name|u_int
name|blockmask
decl_stmt|;
name|struct
name|xlp_block_ivars
name|block_ivars
index|[
name|XLP_NAE_NBLOCKS
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|xlp_board_info
block|{
name|u_int
name|nodemask
decl_stmt|;
struct|struct
name|xlp_node_info
block|{
name|struct
name|xlp_i2c_devinfo
name|i2c_devs
index|[
name|XLP_I2C_MAXDEVICES
index|]
decl_stmt|;
name|struct
name|xlp_nae_ivars
name|nae_ivars
decl_stmt|;
block|}
name|nodes
index|[
name|XLP_MAX_NODES
index|]
struct|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|struct
name|xlp_board_info
name|xlp_board_info
decl_stmt|;
end_decl_stmt

begin_function_decl
name|int
name|nlm_board_info_setup
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

end_unit

