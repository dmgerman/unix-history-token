begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/******************************************************************************  *  * Name: acgcc.h - GCC specific defines, etc.  *  *****************************************************************************/
end_comment

begin_comment
comment|/*  * Copyright (C) 2000 - 2014, Intel Corp.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions, and the following disclaimer,  *    without modification.  * 2. Redistributions in binary form must reproduce at minimum a disclaimer  *    substantially similar to the "NO WARRANTY" disclaimer below  *    ("Disclaimer") and any redistribution must be conditioned upon  *    including a substantially similar Disclaimer requirement for further  *    binary redistribution.  * 3. Neither the names of the above-listed copyright holders nor the names  *    of any contributors may be used to endorse or promote products derived  *    from this software without specific prior written permission.  *  * Alternatively, this software may be distributed under the terms of the  * GNU General Public License ("GPL") version 2 as published by the Free  * Software Foundation.  *  * NO WARRANTY  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT  * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTIBILITY AND FITNESS FOR  * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT  * HOLDERS OR CONTRIBUTORS BE LIABLE FOR SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,  * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING  * IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  * POSSIBILITY OF SUCH DAMAGES.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__ACGCC_H__
end_ifndef

begin_define
define|#
directive|define
name|__ACGCC_H__
end_define

begin_define
define|#
directive|define
name|ACPI_INLINE
value|__inline__
end_define

begin_comment
comment|/* Function name is used for debug output. Non-ANSI, compiler-dependent */
end_comment

begin_define
define|#
directive|define
name|ACPI_GET_FUNCTION_NAME
value|__func__
end_define

begin_comment
comment|/*  * This macro is used to tag functions as "printf-like" because  * some compilers (like GCC) can catch printf format string problems.  */
end_comment

begin_define
define|#
directive|define
name|ACPI_PRINTF_LIKE
parameter_list|(
name|c
parameter_list|)
value|__attribute__ ((__format__ (__printf__, c, c+1)))
end_define

begin_comment
comment|/*  * Some compilers complain about unused variables. Sometimes we don't want to  * use all the variables (for example, _AcpiModuleName). This allows us  * to tell the compiler warning in a per-variable manner that a variable  * is unused.  */
end_comment

begin_define
define|#
directive|define
name|ACPI_UNUSED_VAR
value|__attribute__ ((unused))
end_define

begin_comment
comment|/*  * Some versions of gcc implement strchr() with a buggy macro. So,  * undef it here. Prevents error messages of this form (usually from the  * file getopt.c):  *  * error: logical '&&' with non-zero constant will always evaluate as true  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|strchr
end_ifdef

begin_undef
undef|#
directive|undef
name|strchr
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __ACGCC_H__ */
end_comment

end_unit

