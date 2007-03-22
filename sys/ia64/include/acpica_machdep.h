begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2002 Mitsuru IWASAKI  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_comment
comment|/******************************************************************************  *  * Name: acpica_machdep.h - arch-specific defines, etc.  *       $Revision$  *  *****************************************************************************/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__ACPICA_MACHDEP_H__
end_ifndef

begin_define
define|#
directive|define
name|__ACPICA_MACHDEP_H__
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_define
define|#
directive|define
name|_IA64
end_define

begin_comment
comment|/*  * Calling conventions:  *  * ACPI_SYSTEM_XFACE        - Interfaces to host OS (handlers, threads)  * ACPI_EXTERNAL_XFACE      - External ACPI interfaces   * ACPI_INTERNAL_XFACE      - Internal ACPI interfaces  * ACPI_INTERNAL_VAR_XFACE  - Internal variable-parameter list interfaces  */
end_comment

begin_define
define|#
directive|define
name|ACPI_SYSTEM_XFACE
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
end_define

begin_comment
comment|/* Asm macros */
end_comment

begin_define
define|#
directive|define
name|ACPI_ASM_MACROS
end_define

begin_define
define|#
directive|define
name|BREAKPOINT3
end_define

begin_define
define|#
directive|define
name|ACPI_DISABLE_IRQS
parameter_list|()
value|disable_intr()
end_define

begin_define
define|#
directive|define
name|ACPI_ENABLE_IRQS
parameter_list|()
value|enable_intr()
end_define

begin_define
define|#
directive|define
name|ACPI_FLUSH_CPU_CACHE
parameter_list|()
end_define

begin_comment
comment|/* XXX ia64_fc()? */
end_comment

begin_comment
comment|/* Section 5.2.9.1:  global lock acquire/release functions */
end_comment

begin_function_decl
specifier|extern
name|int
name|acpi_acquire_global_lock
parameter_list|(
name|uint32_t
modifier|*
name|lock
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|acpi_release_global_lock
parameter_list|(
name|uint32_t
modifier|*
name|lock
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
value|do {			\ 	(Acq) = acpi_acquire_global_lock(&((GLptr)->GlobalLock));	\ } while (0)
end_define

begin_define
define|#
directive|define
name|ACPI_RELEASE_GLOBAL_LOCK
parameter_list|(
name|GLptr
parameter_list|,
name|Acq
parameter_list|)
value|do {			\ 	(Acq) = acpi_release_global_lock(&((GLptr)->GlobalLock));	\ } while (0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _KERNEL */
end_comment

begin_define
define|#
directive|define
name|ACPI_MACHINE_WIDTH
value|64
end_define

begin_define
define|#
directive|define
name|COMPILER_DEPENDENT_INT64
value|long
end_define

begin_define
define|#
directive|define
name|COMPILER_DEPENDENT_UINT64
value|unsigned long
end_define

begin_function_decl
name|void
name|acpi_cpu_c1
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __ACPICA_MACHDEP_H__ */
end_comment

end_unit

