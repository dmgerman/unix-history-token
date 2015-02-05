begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/******************************************************************************  *  * Name: acos2.h - OS/2 specific defines, etc.  *  *****************************************************************************/
end_comment

begin_comment
comment|/*  * Copyright (C) 2000 - 2015, Intel Corp.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions, and the following disclaimer,  *    without modification.  * 2. Redistributions in binary form must reproduce at minimum a disclaimer  *    substantially similar to the "NO WARRANTY" disclaimer below  *    ("Disclaimer") and any redistribution must be conditioned upon  *    including a substantially similar Disclaimer requirement for further  *    binary redistribution.  * 3. Neither the names of the above-listed copyright holders nor the names  *    of any contributors may be used to endorse or promote products derived  *    from this software without specific prior written permission.  *  * Alternatively, this software may be distributed under the terms of the  * GNU General Public License ("GPL") version 2 as published by the Free  * Software Foundation.  *  * NO WARRANTY  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT  * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTIBILITY AND FITNESS FOR  * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT  * HOLDERS OR CONTRIBUTORS BE LIABLE FOR SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,  * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING  * IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  * POSSIBILITY OF SUCH DAMAGES.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__ACOS2_H__
end_ifndef

begin_define
define|#
directive|define
name|__ACOS2_H__
end_define

begin_define
define|#
directive|define
name|INCL_LONGLONG
end_define

begin_include
include|#
directive|include
file|<os2.h>
end_include

begin_define
define|#
directive|define
name|ACPI_MACHINE_WIDTH
value|32
end_define

begin_define
define|#
directive|define
name|COMPILER_DEPENDENT_INT64
value|long long
end_define

begin_define
define|#
directive|define
name|COMPILER_DEPENDENT_UINT64
value|unsigned long long
end_define

begin_define
define|#
directive|define
name|ACPI_USE_NATIVE_DIVIDE
end_define

begin_define
define|#
directive|define
name|ACPI_SYSTEM_XFACE
value|APIENTRY
end_define

begin_define
define|#
directive|define
name|ACPI_EXTERNAL_XFACE
value|APIENTRY
end_define

begin_define
define|#
directive|define
name|ACPI_INTERNAL_XFACE
value|APIENTRY
end_define

begin_define
define|#
directive|define
name|ACPI_INTERNAL_VAR_XFACE
value|APIENTRY
end_define

begin_comment
comment|/*  * Some compilers complain about unused variables. Sometimes we don't want to  * use all the variables (most specifically for _THIS_MODULE). This allow us  * to to tell the compiler warning in a per-variable manner that a variable  * is unused.  */
end_comment

begin_define
define|#
directive|define
name|ACPI_UNUSED_VAR
end_define

begin_define
define|#
directive|define
name|ACPI_USE_STANDARD_HEADERS
end_define

begin_include
include|#
directive|include
file|<io.h>
end_include

begin_define
define|#
directive|define
name|ACPI_FLUSH_CPU_CACHE
parameter_list|()
value|Wbinvd()
end_define

begin_function_decl
name|void
name|Wbinvd
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|ACPI_ACQUIRE_GLOBAL_LOCK
parameter_list|(
name|GLptr
parameter_list|,
name|Acq
parameter_list|)
value|Acq = OSPMAcquireGlobalLock(GLptr)
end_define

begin_define
define|#
directive|define
name|ACPI_RELEASE_GLOBAL_LOCK
parameter_list|(
name|GLptr
parameter_list|,
name|Pnd
parameter_list|)
value|Pnd = OSPMReleaseGlobalLock(GLptr)
end_define

begin_function_decl
name|unsigned
name|short
name|OSPMAcquireGlobalLock
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|unsigned
name|short
name|OSPMReleaseGlobalLock
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|ACPI_SHIFT_RIGHT_64
parameter_list|(
name|n_hi
parameter_list|,
name|n_lo
parameter_list|)
define|\
value|{ \     unsigned long long val = 0LL; \     val = n_lo | ( ((unsigned long long)h_hi)<< 32 ); \     __llrotr (val,1); \     n_hi = (unsigned long)((val>> 32 )& 0xffffffff ); \     n_lo = (unsigned long)(val& 0xffffffff); \ }
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|ACPI_ASL_COMPILER
end_ifndef

begin_define
define|#
directive|define
name|ACPI_USE_LOCAL_CACHE
end_define

begin_undef
undef|#
directive|undef
name|ACPI_DEBUGGER
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
comment|/* __ACOS2_H__ */
end_comment

end_unit

