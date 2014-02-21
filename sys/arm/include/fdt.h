begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2010 The FreeBSD Foundation  * All rights reserved.  *  * This software was developed by Semihalf under sponsorship from  * the FreeBSD Foundation.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED. IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_MACHINE_FDT_H_
end_ifndef

begin_define
define|#
directive|define
name|_MACHINE_FDT_H_
end_define

begin_include
include|#
directive|include
file|<dev/ofw/openfirm.h>
end_include

begin_include
include|#
directive|include
file|<vm/vm.h>
end_include

begin_include
include|#
directive|include
file|<vm/pmap.h>
end_include

begin_include
include|#
directive|include
file|<machine/bus.h>
end_include

begin_include
include|#
directive|include
file|<machine/intr.h>
end_include

begin_comment
comment|/* Max interrupt number */
end_comment

begin_define
define|#
directive|define
name|FDT_INTR_MAX
value|NIRQ
end_define

begin_comment
comment|/* Map phandle/intpin pair to global IRQ number */
end_comment

begin_define
define|#
directive|define
name|FDT_MAP_IRQ
parameter_list|(
name|node
parameter_list|,
name|pin
parameter_list|)
value|(pin)
end_define

begin_comment
comment|/*  * Bus space tag. XXX endianess info needs to be derived from the blob.  */
end_comment

begin_decl_stmt
specifier|extern
name|bus_space_tag_t
name|fdtbus_bs_tag
decl_stmt|;
end_decl_stmt

begin_struct_decl
struct_decl|struct
name|arm_devmap_entry
struct_decl|;
end_struct_decl

begin_function_decl
name|int
name|fdt_localbus_devmap
parameter_list|(
name|phandle_t
parameter_list|,
name|struct
name|arm_devmap_entry
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _MACHINE_FDT_H_ */
end_comment

end_unit

