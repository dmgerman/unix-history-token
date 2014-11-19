begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2014 Ian Lepore<ian@freebsd.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|DEV_FDT_CLOCK_H
end_ifndef

begin_define
define|#
directive|define
name|DEV_FDT_CLOCK_H
end_define

begin_include
include|#
directive|include
file|"fdt_clock_if.h"
end_include

begin_comment
comment|/*  * Get info about the Nth clock listed in consumer's "clocks" property.  *  * Returns 0 on success, ENXIO if clock #n not found.  */
end_comment

begin_function_decl
name|int
name|fdt_clock_get_info
parameter_list|(
name|device_t
name|consumer
parameter_list|,
name|int
name|n
parameter_list|,
name|struct
name|fdt_clock_info
modifier|*
name|info
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Look up "clocks" property in consumer's fdt data and enable or disable all  * configured clocks.  */
end_comment

begin_function_decl
name|int
name|fdt_clock_enable_all
parameter_list|(
name|device_t
name|consumer
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|fdt_clock_disable_all
parameter_list|(
name|device_t
name|consumer
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * [Un]register the given device instance as a driver that implements the  * fdt_clock interface.  */
end_comment

begin_function_decl
name|void
name|fdt_clock_register_provider
parameter_list|(
name|device_t
name|provider
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|fdt_clock_unregister_provider
parameter_list|(
name|device_t
name|provider
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* DEV_FDT_CLOCK_H */
end_comment

end_unit

