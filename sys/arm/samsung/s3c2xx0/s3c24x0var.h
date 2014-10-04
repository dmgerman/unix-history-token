begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $NetBSD: s3c24x0var.h,v 1.1 2003/07/31 19:49:44 bsh Exp $ */
end_comment

begin_comment
comment|/*-  * Copyright (c) 2003  Genetec corporation.  All rights reserved.  * Written by Hiroyuki Bessho for Genetec corporation.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. The name of Genetec corporation may not be used to endorse  *    or promote products derived from this software without specific prior  *    written permission.  *  * THIS SOFTWARE IS PROVIDED BY GENETEC CORP. ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED  * TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR  * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL GENETEC CORP.  * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN  * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  * POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_ARM_S3C24X0VAR_H_
end_ifndef

begin_define
define|#
directive|define
name|_ARM_S3C24X0VAR_H_
end_define

begin_include
include|#
directive|include
file|<arm/samsung/s3c2xx0/s3c2xx0var.h>
end_include

begin_struct
struct|struct
name|s3c24x0_softc
block|{
name|struct
name|s3c2xx0_softc
name|sc_sx
decl_stmt|;
name|bus_space_handle_t
name|sc_timer_ioh
decl_stmt|;
comment|/* Timer control registers */
block|}
struct|;
end_struct

begin_function_decl
name|void
name|s3c24x0_clock_freq
parameter_list|(
name|struct
name|s3c2xx0_softc
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|s3c2410_clock_freq2
parameter_list|(
name|vm_offset_t
parameter_list|,
name|int
modifier|*
parameter_list|,
name|int
modifier|*
parameter_list|,
name|int
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|s3c2440_clock_freq2
parameter_list|(
name|vm_offset_t
parameter_list|,
name|int
modifier|*
parameter_list|,
name|int
modifier|*
parameter_list|,
name|int
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|s3c24x0_sleep
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _ARM_S3C24X0VAR_H_ */
end_comment

end_unit

