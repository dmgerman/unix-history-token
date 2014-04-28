begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2013 Ian Lepore<ian@freebsd.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|IMX_MACHDEP_H
end_ifndef

begin_define
define|#
directive|define
name|IMX_MACHDEP_H
end_define

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_comment
comment|/* Common functions, implemented in imx_machdep.c. */
end_comment

begin_function_decl
name|void
name|imx_wdog_cpu_reset
parameter_list|(
name|vm_offset_t
name|_wdcr_phys
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(__noreturn__
end_function_decl

begin_empty_stmt
unit|))
empty_stmt|;
end_empty_stmt

begin_comment
comment|/* From here down, routines are implemented in imxNN_machdep.c. */
end_comment

begin_comment
comment|/*  * SoC identity.  * According to the documentation, there is such a thing as an i.MX6 Dual  * (non-lite flavor).  However, Freescale doesn't seem to have assigned it a  * number in their code for determining the SoC type in u-boot.  *  * To-do: put silicon revision numbers into the low-order bits somewhere.  */
end_comment

begin_define
define|#
directive|define
name|IMXSOC_51
value|0x51000000
end_define

begin_define
define|#
directive|define
name|IMXSOC_53
value|0x53000000
end_define

begin_define
define|#
directive|define
name|IMXSOC_6SL
value|0x60000000
end_define

begin_define
define|#
directive|define
name|IMXSOC_6DL
value|0x61000000
end_define

begin_define
define|#
directive|define
name|IMXSOC_6S
value|0x62000000
end_define

begin_define
define|#
directive|define
name|IMXSOC_6Q
value|0x63000000
end_define

begin_define
define|#
directive|define
name|IMXSOC_FAMSHIFT
value|28
end_define

begin_function_decl
name|u_int
name|imx_soc_type
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|u_int
name|imx_soc_family
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

