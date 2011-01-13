begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/******************************************************************************  *  * Name: aclinux.h - OS specific defines, etc. for Linux  *  *****************************************************************************/
end_comment

begin_comment
comment|/*  * Copyright (C) 2000 - 2011, Intel Corp.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions, and the following disclaimer,  *    without modification.  * 2. Redistributions in binary form must reproduce at minimum a disclaimer  *    substantially similar to the "NO WARRANTY" disclaimer below  *    ("Disclaimer") and any redistribution must be conditioned upon  *    including a substantially similar Disclaimer requirement for further  *    binary redistribution.  * 3. Neither the names of the above-listed copyright holders nor the names  *    of any contributors may be used to endorse or promote products derived  *    from this software without specific prior written permission.  *  * Alternatively, this software may be distributed under the terms of the  * GNU General Public License ("GPL") version 2 as published by the Free  * Software Foundation.  *  * NO WARRANTY  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT  * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTIBILITY AND FITNESS FOR  * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT  * HOLDERS OR CONTRIBUTORS BE LIABLE FOR SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,  * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING  * IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  * POSSIBILITY OF SUCH DAMAGES.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__ACLINUX_H__
end_ifndef

begin_define
define|#
directive|define
name|__ACLINUX_H__
end_define

begin_comment
comment|/* Common (in-kernel/user-space) ACPICA configuration */
end_comment

begin_define
define|#
directive|define
name|ACPI_USE_SYSTEM_CLIBRARY
end_define

begin_define
define|#
directive|define
name|ACPI_USE_DO_WHILE_0
end_define

begin_define
define|#
directive|define
name|ACPI_MUTEX_TYPE
value|ACPI_BINARY_SEMAPHORE
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|__KERNEL__
end_ifdef

begin_include
include|#
directive|include
file|<linux/string.h>
end_include

begin_include
include|#
directive|include
file|<linux/kernel.h>
end_include

begin_include
include|#
directive|include
file|<linux/module.h>
end_include

begin_include
include|#
directive|include
file|<linux/ctype.h>
end_include

begin_include
include|#
directive|include
file|<linux/sched.h>
end_include

begin_include
include|#
directive|include
file|<asm/system.h>
end_include

begin_include
include|#
directive|include
file|<asm/atomic.h>
end_include

begin_include
include|#
directive|include
file|<asm/div64.h>
end_include

begin_include
include|#
directive|include
file|<asm/acpi.h>
end_include

begin_include
include|#
directive|include
file|<linux/slab.h>
end_include

begin_include
include|#
directive|include
file|<linux/spinlock_types.h>
end_include

begin_include
include|#
directive|include
file|<asm/current.h>
end_include

begin_comment
comment|/* Host-dependent types and defines for in-kernel ACPICA */
end_comment

begin_define
define|#
directive|define
name|ACPI_MACHINE_WIDTH
value|BITS_PER_LONG
end_define

begin_define
define|#
directive|define
name|ACPI_EXPORT_SYMBOL
parameter_list|(
name|symbol
parameter_list|)
value|EXPORT_SYMBOL(symbol);
end_define

begin_define
define|#
directive|define
name|strtoul
value|simple_strtoul
end_define

begin_define
define|#
directive|define
name|ACPI_CACHE_T
value|struct kmem_cache
end_define

begin_define
define|#
directive|define
name|ACPI_SPINLOCK
value|spinlock_t *
end_define

begin_define
define|#
directive|define
name|ACPI_CPU_FLAGS
value|unsigned long
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* !__KERNEL__ */
end_comment

begin_include
include|#
directive|include
file|<stdarg.h>
end_include

begin_include
include|#
directive|include
file|<string.h>
end_include

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_include
include|#
directive|include
file|<ctype.h>
end_include

begin_include
include|#
directive|include
file|<unistd.h>
end_include

begin_comment
comment|/* Host-dependent types and defines for user-space ACPICA */
end_comment

begin_define
define|#
directive|define
name|ACPI_FLUSH_CPU_CACHE
parameter_list|()
end_define

begin_define
define|#
directive|define
name|ACPI_CAST_PTHREAD_T
parameter_list|(
name|pthread
parameter_list|)
value|((ACPI_THREAD_ID) (pthread))
end_define

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__ia64__
argument_list|)
operator|||
name|defined
argument_list|(
name|__x86_64__
argument_list|)
end_if

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

begin_else
else|#
directive|else
end_else

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

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|__cdecl
end_ifndef

begin_define
define|#
directive|define
name|__cdecl
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __KERNEL__ */
end_comment

begin_comment
comment|/* Linux uses GCC */
end_comment

begin_include
include|#
directive|include
file|"acgcc.h"
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|__KERNEL__
end_ifdef

begin_comment
comment|/*  * Overrides for in-kernel ACPICA  */
end_comment

begin_function
specifier|static
specifier|inline
name|acpi_thread_id
name|acpi_os_get_thread_id
parameter_list|(
name|void
parameter_list|)
block|{
return|return
name|current
return|;
block|}
end_function

begin_comment
comment|/*  * The irqs_disabled() check is for resume from RAM.  * Interrupts are off during resume, just like they are for boot.  * However, boot has  (system_state != SYSTEM_RUNNING)  * to quiet __might_sleep() in kmalloc() and resume does not.  */
end_comment

begin_include
include|#
directive|include
file|<acpi/actypes.h>
end_include

begin_function
specifier|static
specifier|inline
name|void
modifier|*
name|acpi_os_allocate
parameter_list|(
name|acpi_size
name|size
parameter_list|)
block|{
return|return
name|kmalloc
argument_list|(
name|size
argument_list|,
name|irqs_disabled
argument_list|()
condition|?
name|GFP_ATOMIC
else|:
name|GFP_KERNEL
argument_list|)
return|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|void
modifier|*
name|acpi_os_allocate_zeroed
parameter_list|(
name|acpi_size
name|size
parameter_list|)
block|{
return|return
name|kzalloc
argument_list|(
name|size
argument_list|,
name|irqs_disabled
argument_list|()
condition|?
name|GFP_ATOMIC
else|:
name|GFP_KERNEL
argument_list|)
return|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|void
modifier|*
name|acpi_os_acquire_object
parameter_list|(
name|acpi_cache_t
modifier|*
name|cache
parameter_list|)
block|{
return|return
name|kmem_cache_zalloc
argument_list|(
name|cache
argument_list|,
name|irqs_disabled
argument_list|()
condition|?
name|GFP_ATOMIC
else|:
name|GFP_KERNEL
argument_list|)
return|;
block|}
end_function

begin_define
define|#
directive|define
name|ACPI_ALLOCATE
parameter_list|(
name|a
parameter_list|)
value|acpi_os_allocate(a)
end_define

begin_define
define|#
directive|define
name|ACPI_ALLOCATE_ZEROED
parameter_list|(
name|a
parameter_list|)
value|acpi_os_allocate_zeroed(a)
end_define

begin_define
define|#
directive|define
name|ACPI_FREE
parameter_list|(
name|a
parameter_list|)
value|kfree(a)
end_define

begin_comment
comment|/* Used within ACPICA to show where it is safe to preempt execution */
end_comment

begin_define
define|#
directive|define
name|ACPI_PREEMPTION_POINT
parameter_list|()
define|\
value|do { \         if (!irqs_disabled()) \             cond_resched(); \     } while (0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __KERNEL__ */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __ACLINUX_H__ */
end_comment

end_unit

