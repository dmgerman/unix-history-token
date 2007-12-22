begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*      $NetBSD: sa11x0_var.h,v 1.4 2003/04/14 14:18:41 rjs Exp $        */
end_comment

begin_comment
comment|/*-  * Copyright (c) 2001, The NetBSD Foundation, Inc.  All rights reserved.  *  * This code is derived from software contributed to The NetBSD Foundation  * by IWAMOTO Toshihiro and Ichiro FUKUHARA.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *      This product includes software developed by the NetBSD  *      Foundation, Inc. and its contributors.  * 4. Neither the name of The NetBSD Foundation nor the names of its  *    contributors may be used to endorse or promote products derived  *    from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SA11X0_VAR_H
end_ifndef

begin_define
define|#
directive|define
name|_SA11X0_VAR_H
end_define

begin_include
include|#
directive|include
file|<sys/conf.h>
end_include

begin_include
include|#
directive|include
file|<sys/bus.h>
end_include

begin_include
include|#
directive|include
file|<machine/bus.h>
end_include

begin_include
include|#
directive|include
file|<sys/rman.h>
end_include

begin_struct
struct|struct
name|sa11x0_softc
block|{
name|device_t
name|sc_dev
decl_stmt|;
name|bus_space_tag_t
name|sc_iot
decl_stmt|;
name|bus_space_handle_t
name|sc_ioh
decl_stmt|;
name|bus_space_handle_t
name|sc_gpioh
decl_stmt|;
name|bus_space_handle_t
name|sc_ppch
decl_stmt|;
name|bus_space_handle_t
name|sc_dmach
decl_stmt|;
name|bus_space_handle_t
name|sc_reseth
decl_stmt|;
name|u_int32_t
name|sc_intrmask
decl_stmt|;
name|struct
name|rman
name|sa11x0_rman
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* Attach args all devices */
end_comment

begin_typedef
typedef|typedef
name|void
modifier|*
name|sa11x0_chipset_tag_t
typedef|;
end_typedef

begin_decl_stmt
specifier|extern
name|struct
name|bus_space
name|sa11x0_bs_tag
decl_stmt|;
end_decl_stmt

begin_function_decl
name|void
modifier|*
name|sa11x0_intr_establish
parameter_list|(
name|sa11x0_chipset_tag_t
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|,
name|int
function_decl|(
modifier|*
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|)
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|sa11x0_intr_disestablish
parameter_list|(
name|sa11x0_chipset_tag_t
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _SA11X0_VAR_H */
end_comment

end_unit

