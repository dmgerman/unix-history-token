begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2005 Olivier Houchard.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_AT91VAR_H_
end_ifndef

begin_define
define|#
directive|define
name|_AT91VAR_H_
end_define

begin_include
include|#
directive|include
file|<sys/bus.h>
end_include

begin_include
include|#
directive|include
file|<sys/rman.h>
end_include

begin_include
include|#
directive|include
file|<arm/at91/at91reg.h>
end_include

begin_struct
struct|struct
name|at91_softc
block|{
name|device_t
name|dev
decl_stmt|;
name|bus_space_tag_t
name|sc_st
decl_stmt|;
name|bus_space_handle_t
name|sc_sh
decl_stmt|;
name|bus_space_handle_t
name|sc_aic_sh
decl_stmt|;
name|struct
name|rman
name|sc_irq_rman
decl_stmt|;
name|struct
name|rman
name|sc_mem_rman
decl_stmt|;
name|uint32_t
name|sc_irq_system
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|at91_ivar
block|{
name|struct
name|resource_list
name|resources
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|cpu_devs
block|{
specifier|const
name|char
modifier|*
name|name
decl_stmt|;
name|int
name|unit
decl_stmt|;
name|bus_addr_t
name|mem_base
decl_stmt|;
name|bus_size_t
name|mem_len
decl_stmt|;
name|int
name|irq0
decl_stmt|;
name|int
name|irq1
decl_stmt|;
name|int
name|irq2
decl_stmt|;
specifier|const
name|char
modifier|*
name|parent_clk
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|uint32_t
name|at91_chip_id
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|static
specifier|inline
name|int
name|at91_is_rm92
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
specifier|inline
name|int
name|at91_is_sam9
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
specifier|inline
name|int
name|at91_cpu_is
parameter_list|(
name|u_int
name|cpu
parameter_list|)
function_decl|;
end_function_decl

begin_function
specifier|static
specifier|inline
name|int
name|at91_is_rm92
parameter_list|(
name|void
parameter_list|)
block|{
return|return
operator|(
name|AT91_ARCH
argument_list|(
name|at91_chip_id
argument_list|)
operator|==
name|AT91_ARCH_RM92
operator|)
return|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|int
name|at91_is_sam9
parameter_list|(
name|void
parameter_list|)
block|{
return|return
operator|(
name|AT91_ARCH
argument_list|(
name|at91_chip_id
argument_list|)
operator|==
name|AT91_ARCH_SAM9
operator|)
return|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|int
name|at91_cpu_is
parameter_list|(
name|u_int
name|cpu
parameter_list|)
block|{
return|return
operator|(
name|AT91_CPU
argument_list|(
name|at91_chip_id
argument_list|)
operator|==
name|cpu
operator|)
return|;
block|}
end_function

begin_decl_stmt
specifier|extern
name|uint32_t
name|at91_irq_system
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|uint32_t
name|at91_master_clock
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _AT91VAR_H_ */
end_comment

end_unit

