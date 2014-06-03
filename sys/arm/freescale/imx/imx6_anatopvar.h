begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2013 Ian Lepore<ian@freebsd.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|IMX6_ANATOPVAR_H
end_ifndef

begin_define
define|#
directive|define
name|IMX6_ANATOPVAR_H
end_define

begin_comment
comment|/*  * All registers controlling various analog aspects of the SoC (such as PLLs or  * voltage regulators or USB VBUS detection) are gathered together under the  * anatop device (because of newbus hierarchical resource management), but other  * drivers such as CMM or USBPHY need access to these registers.  These  * functions let them have at the hardware directly.  No effort is made by these  * functions to mediate concurrent access.  */
end_comment

begin_function_decl
name|uint32_t
name|imx6_anatop_read_4
parameter_list|(
name|bus_size_t
name|_offset
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|imx6_anatop_write_4
parameter_list|(
name|bus_size_t
name|_offset
parameter_list|,
name|uint32_t
name|_value
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|uint32_t
name|imx6_get_cpu_clock
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

