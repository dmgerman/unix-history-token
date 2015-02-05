begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/******************************************************************************  *  * Name: acwin.h - OS specific defines, etc.  *  *****************************************************************************/
end_comment

begin_comment
comment|/*  * Copyright (C) 2000 - 2015, Intel Corp.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions, and the following disclaimer,  *    without modification.  * 2. Redistributions in binary form must reproduce at minimum a disclaimer  *    substantially similar to the "NO WARRANTY" disclaimer below  *    ("Disclaimer") and any redistribution must be conditioned upon  *    including a substantially similar Disclaimer requirement for further  *    binary redistribution.  * 3. Neither the names of the above-listed copyright holders nor the names  *    of any contributors may be used to endorse or promote products derived  *    from this software without specific prior written permission.  *  * Alternatively, this software may be distributed under the terms of the  * GNU General Public License ("GPL") version 2 as published by the Free  * Software Foundation.  *  * NO WARRANTY  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT  * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTIBILITY AND FITNESS FOR  * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT  * HOLDERS OR CONTRIBUTORS BE LIABLE FOR SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,  * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING  * IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  * POSSIBILITY OF SUCH DAMAGES.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__ACWIN_H__
end_ifndef

begin_define
define|#
directive|define
name|__ACWIN_H__
end_define

begin_comment
comment|/*! [Begin] no source code translation (Keep the include) */
end_comment

begin_comment
comment|/* Windows uses VC */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|_MSC_VER
end_ifdef

begin_include
include|#
directive|include
file|"acmsvc.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*! [End] no source code translation !*/
end_comment

begin_define
define|#
directive|define
name|ACPI_MACHINE_WIDTH
value|32
end_define

begin_define
define|#
directive|define
name|ACPI_USE_STANDARD_HEADERS
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|ACPI_DEFINE_ALTERNATE_TYPES
end_ifdef

begin_comment
comment|/*  * Types used only in (Linux) translated source, defined here to enable  * cross-platform compilation (i.e., generate the Linux code on Windows,  * for test purposes only)  */
end_comment

begin_typedef
typedef|typedef
name|int
name|s32
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|char
name|u8
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|short
name|u16
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|int
name|u32
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|COMPILER_DEPENDENT_UINT64
name|u64
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Handle platform- and compiler-specific assembly language differences.  *  * Notes:  * 1) Interrupt 3 is used to break into a debugger  * 2) Interrupts are turned off during ACPI register setup  */
end_comment

begin_comment
comment|/*! [Begin] no source code translation  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|ACPI_APPLICATION
end_ifdef

begin_define
define|#
directive|define
name|ACPI_FLUSH_CPU_CACHE
parameter_list|()
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|ACPI_FLUSH_CPU_CACHE
parameter_list|()
value|__asm {WBINVD}
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|_DEBUG
end_ifdef

begin_define
define|#
directive|define
name|ACPI_SIMPLE_RETURN_MACROS
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*! [End] no source code translation !*/
end_comment

begin_comment
comment|/*  * Global Lock acquire/release code  *  * Note: Handles case where the FACS pointer is null  */
end_comment

begin_define
define|#
directive|define
name|ACPI_ACQUIRE_GLOBAL_LOCK
parameter_list|(
name|FacsPtr
parameter_list|,
name|Acq
parameter_list|)
value|__asm \ {                                                   \         __asm mov           eax, 0xFF               \         __asm mov           ecx, FacsPtr            \         __asm or            ecx, ecx                \         __asm jz            exit_acq                \         __asm lea           ecx, [ecx].GlobalLock   \                                                     \         __asm acq10:                                \         __asm mov           eax, [ecx]              \         __asm mov           edx, eax                \         __asm and           edx, 0xFFFFFFFE         \         __asm bts           edx, 1                  \         __asm adc           edx, 0                  \         __asm lock cmpxchg  dword ptr [ecx], edx    \         __asm jnz           acq10                   \                                                     \         __asm cmp           dl, 3                   \         __asm sbb           eax, eax                \                                                     \         __asm exit_acq:                             \         __asm mov           Acq, al                 \ }
end_define

begin_define
define|#
directive|define
name|ACPI_RELEASE_GLOBAL_LOCK
parameter_list|(
name|FacsPtr
parameter_list|,
name|Pnd
parameter_list|)
value|__asm \ {                                                   \         __asm xor           eax, eax                \         __asm mov           ecx, FacsPtr            \         __asm or            ecx, ecx                \         __asm jz            exit_rel                \         __asm lea           ecx, [ecx].GlobalLock   \                                                     \         __asm Rel10:                                \         __asm mov           eax, [ecx]              \         __asm mov           edx, eax                \         __asm and           edx, 0xFFFFFFFC         \         __asm lock cmpxchg  dword ptr [ecx], edx    \         __asm jnz           Rel10                   \                                                     \         __asm cmp           dl, 3                   \         __asm and           eax, 1                  \                                                     \         __asm exit_rel:                             \         __asm mov           Pnd, al                 \ }
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __ACWIN_H__ */
end_comment

end_unit

