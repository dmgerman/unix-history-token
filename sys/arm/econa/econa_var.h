begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2009 Yohanes Nugroho<yohanes@gmail.com>.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_ARM_ECONA_VAR_H
end_ifndef

begin_define
define|#
directive|define
name|_ARM_ECONA_VAR_H
end_define

begin_decl_stmt
specifier|extern
name|bus_space_tag_t
name|obio_tag
decl_stmt|;
end_decl_stmt

begin_struct
struct|struct
name|econa_softc
block|{
name|device_t
name|dev
decl_stmt|;
name|bus_space_tag_t
name|ec_st
decl_stmt|;
name|bus_space_handle_t
name|ec_sh
decl_stmt|;
name|bus_space_handle_t
name|ec_sys_sh
decl_stmt|;
name|bus_space_handle_t
name|ec_system_sh
decl_stmt|;
name|struct
name|rman
name|ec_irq_rman
decl_stmt|;
name|struct
name|rman
name|ec_mem_rman
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|econa_ivar
block|{
name|struct
name|resource_list
name|resources
decl_stmt|;
block|}
struct|;
end_struct

begin_function_decl
name|void
name|power_on_network_interface
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|unsigned
name|int
name|get_tclk
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

