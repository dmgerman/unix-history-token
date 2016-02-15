begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (C) 2008 MARVELL INTERNATIONAL LTD.  * All rights reserved.  *  * Developed by Semihalf.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. Neither the name of MARVELL nor the names of contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_TWSI_H_
end_ifndef

begin_define
define|#
directive|define
name|_TWSI_H_
end_define

begin_struct
struct|struct
name|twsi_baud_rate
block|{
name|uint32_t
name|raw
decl_stmt|;
name|int
name|param
decl_stmt|;
name|int
name|m
decl_stmt|;
name|int
name|n
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|twsi_softc
block|{
name|device_t
name|dev
decl_stmt|;
name|struct
name|resource
modifier|*
name|res
index|[
literal|1
index|]
decl_stmt|;
comment|/* SYS_RES_MEMORY */
name|struct
name|mtx
name|mutex
decl_stmt|;
name|device_t
name|iicbus
decl_stmt|;
name|bus_size_t
name|reg_data
decl_stmt|;
name|bus_size_t
name|reg_slave_addr
decl_stmt|;
name|bus_size_t
name|reg_slave_ext_addr
decl_stmt|;
name|bus_size_t
name|reg_control
decl_stmt|;
name|bus_size_t
name|reg_status
decl_stmt|;
name|bus_size_t
name|reg_baud_rate
decl_stmt|;
name|bus_size_t
name|reg_soft_reset
decl_stmt|;
name|struct
name|twsi_baud_rate
name|baud_rate
index|[
name|IIC_FASTEST
operator|+
literal|1
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_expr_stmt
name|DECLARE_CLASS
argument_list|(
name|twsi_driver
argument_list|)
expr_stmt|;
end_expr_stmt

begin_define
define|#
directive|define
name|TWSI_BAUD_RATE_PARAM
parameter_list|(
name|M
parameter_list|,
name|N
parameter_list|)
value|((((M)<< 3) | ((N)& 0x7))& 0x7f)
end_define

begin_function_decl
name|int
name|twsi_attach
parameter_list|(
name|device_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|twsi_detach
parameter_list|(
name|device_t
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _TWSI_H_ */
end_comment

end_unit

