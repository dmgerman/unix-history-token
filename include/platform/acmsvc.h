begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/******************************************************************************  *  * Name: acmsvc.h - VC specific defines, etc.  *  *****************************************************************************/
end_comment

begin_comment
comment|/*  * Copyright (C) 2000 - 2011, Intel Corp.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions, and the following disclaimer,  *    without modification.  * 2. Redistributions in binary form must reproduce at minimum a disclaimer  *    substantially similar to the "NO WARRANTY" disclaimer below  *    ("Disclaimer") and any redistribution must be conditioned upon  *    including a substantially similar Disclaimer requirement for further  *    binary redistribution.  * 3. Neither the names of the above-listed copyright holders nor the names  *    of any contributors may be used to endorse or promote products derived  *    from this software without specific prior written permission.  *  * Alternatively, this software may be distributed under the terms of the  * GNU General Public License ("GPL") version 2 as published by the Free  * Software Foundation.  *  * NO WARRANTY  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT  * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTIBILITY AND FITNESS FOR  * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT  * HOLDERS OR CONTRIBUTORS BE LIABLE FOR SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,  * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING  * IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  * POSSIBILITY OF SUCH DAMAGES.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__ACMSVC_H__
end_ifndef

begin_define
define|#
directive|define
name|__ACMSVC_H__
end_define

begin_comment
comment|/* Eliminate warnings for "old" (non-secure) versions of clib functions */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_CRT_SECURE_NO_WARNINGS
end_ifndef

begin_define
define|#
directive|define
name|_CRT_SECURE_NO_WARNINGS
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Eliminate warnings for POSIX clib function names (open, write, etc.) */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_CRT_NONSTDC_NO_DEPRECATE
end_ifndef

begin_define
define|#
directive|define
name|_CRT_NONSTDC_NO_DEPRECATE
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|COMPILER_DEPENDENT_INT64
value|__int64
end_define

begin_define
define|#
directive|define
name|COMPILER_DEPENDENT_UINT64
value|unsigned __int64
end_define

begin_define
define|#
directive|define
name|ACPI_INLINE
value|__inline
end_define

begin_comment
comment|/*  * Calling conventions:  *  * ACPI_SYSTEM_XFACE        - Interfaces to host OS (handlers, threads)  * ACPI_EXTERNAL_XFACE      - External ACPI interfaces  * ACPI_INTERNAL_XFACE      - Internal ACPI interfaces  * ACPI_INTERNAL_VAR_XFACE  - Internal variable-parameter list interfaces  */
end_comment

begin_define
define|#
directive|define
name|ACPI_SYSTEM_XFACE
value|__cdecl
end_define

begin_define
define|#
directive|define
name|ACPI_EXTERNAL_XFACE
end_define

begin_define
define|#
directive|define
name|ACPI_INTERNAL_XFACE
end_define

begin_define
define|#
directive|define
name|ACPI_INTERNAL_VAR_XFACE
value|__cdecl
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|_LINT
end_ifndef

begin_comment
comment|/*  * Math helper functions  */
end_comment

begin_define
define|#
directive|define
name|ACPI_DIV_64_BY_32
parameter_list|(
name|n_hi
parameter_list|,
name|n_lo
parameter_list|,
name|d32
parameter_list|,
name|q32
parameter_list|,
name|r32
parameter_list|)
define|\
value|{                           \     __asm mov    edx, n_hi  \     __asm mov    eax, n_lo  \     __asm div    d32        \     __asm mov    q32, eax   \     __asm mov    r32, edx   \ }
end_define

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
value|{                           \     __asm shr    n_hi, 1    \     __asm rcr    n_lo, 1    \ }
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* Fake versions to make lint happy */
end_comment

begin_define
define|#
directive|define
name|ACPI_DIV_64_BY_32
parameter_list|(
name|n_hi
parameter_list|,
name|n_lo
parameter_list|,
name|d32
parameter_list|,
name|q32
parameter_list|,
name|r32
parameter_list|)
define|\
value|{                           \     q32 = n_hi / d32;       \     r32 = n_lo / d32;       \ }
end_define

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
value|{                           \     n_hi>>= 1;    \     n_lo>>= 1;    \ }
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* warn C4100: unreferenced formal parameter */
end_comment

begin_pragma
pragma|#
directive|pragma
name|warning
name|(
name|disable
name|:
name|4100
name|)
end_pragma

begin_comment
comment|/* warn C4127: conditional expression is constant */
end_comment

begin_pragma
pragma|#
directive|pragma
name|warning
name|(
name|disable
name|:
name|4127
name|)
end_pragma

begin_comment
comment|/* warn C4706: assignment within conditional expression */
end_comment

begin_pragma
pragma|#
directive|pragma
name|warning
name|(
name|disable
name|:
name|4706
name|)
end_pragma

begin_comment
comment|/* warn C4131: uses old-style declarator (iASL compiler only) */
end_comment

begin_pragma
pragma|#
directive|pragma
name|warning
name|(
name|disable
name|:
name|4131
name|)
end_pragma

begin_if
if|#
directive|if
name|_MSC_VER
operator|>
literal|1200
end_if

begin_comment
comment|/* Versions above VC++ 6 */
end_comment

begin_pragma
pragma|#
directive|pragma
name|warning
name|(
name|disable
name|:
name|4295
name|)
end_pragma

begin_comment
comment|/* needed for acpredef.h array */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __ACMSVC_H__ */
end_comment

end_unit

