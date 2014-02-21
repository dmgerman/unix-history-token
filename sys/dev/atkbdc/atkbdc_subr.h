begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1999 Kazutaka YOKOTA<yokota@zodiac.mech.utsunomiya-u.ac.jp>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer as  *    the first lines of this file unmodified.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHORS ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHORS BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  *	from: FreeBSD: src/sys/isa/atkbdc_isa.c,v 1.31 2005/05/29 04:42:28 nyan Exp  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_DEV_ATKBDC_ATKBDC_SUBR_H_
end_ifndef

begin_define
define|#
directive|define
name|_DEV_ATKBDC_ATKBDC_SUBR_H_
end_define

begin_expr_stmt
name|MALLOC_DECLARE
argument_list|(
name|M_ATKBDDEV
argument_list|)
expr_stmt|;
end_expr_stmt

begin_decl_stmt
specifier|extern
name|devclass_t
name|atkbdc_devclass
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* children */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|atkbdc_device
block|{
name|struct
name|resource_list
name|resources
decl_stmt|;
name|int
name|rid
decl_stmt|;
name|u_int32_t
name|vendorid
decl_stmt|;
name|u_int32_t
name|serial
decl_stmt|;
name|u_int32_t
name|logicalid
decl_stmt|;
name|u_int32_t
name|compatid
decl_stmt|;
block|}
name|atkbdc_device_t
typedef|;
end_typedef

begin_comment
comment|/* kbdc */
end_comment

begin_function_decl
name|int
name|atkbdc_print_child
parameter_list|(
name|device_t
name|bus
parameter_list|,
name|device_t
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|atkbdc_read_ivar
parameter_list|(
name|device_t
name|bus
parameter_list|,
name|device_t
name|dev
parameter_list|,
name|int
name|index
parameter_list|,
name|uintptr_t
modifier|*
name|val
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|atkbdc_write_ivar
parameter_list|(
name|device_t
name|bus
parameter_list|,
name|device_t
name|dev
parameter_list|,
name|int
name|index
parameter_list|,
name|uintptr_t
name|val
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|resource_list
modifier|*
name|atkbdc_get_resource_list
parameter_list|(
name|device_t
name|bus
parameter_list|,
name|device_t
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_DEV_ATKBDC_ATKBDC_SUBR_H_ */
end_comment

end_unit

