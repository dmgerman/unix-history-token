begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/******************************************************************************  *  * Name: aclinuxex.h - Extra OS specific defines, etc. for Linux  *  *****************************************************************************/
end_comment

begin_comment
comment|/*  * Copyright (C) 2000 - 2014, Intel Corp.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions, and the following disclaimer,  *    without modification.  * 2. Redistributions in binary form must reproduce at minimum a disclaimer  *    substantially similar to the "NO WARRANTY" disclaimer below  *    ("Disclaimer") and any redistribution must be conditioned upon  *    including a substantially similar Disclaimer requirement for further  *    binary redistribution.  * 3. Neither the names of the above-listed copyright holders nor the names  *    of any contributors may be used to endorse or promote products derived  *    from this software without specific prior written permission.  *  * Alternatively, this software may be distributed under the terms of the  * GNU General Public License ("GPL") version 2 as published by the Free  * Software Foundation.  *  * NO WARRANTY  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT  * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTIBILITY AND FITNESS FOR  * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT  * HOLDERS OR CONTRIBUTORS BE LIABLE FOR SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,  * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING  * IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  * POSSIBILITY OF SUCH DAMAGES.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__ACLINUXEX_H__
end_ifndef

begin_define
define|#
directive|define
name|__ACLINUXEX_H__
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|__KERNEL__
end_ifdef

begin_ifndef
ifndef|#
directive|ifndef
name|ACPI_USE_NATIVE_DIVIDE
end_ifndef

begin_ifndef
ifndef|#
directive|ifndef
name|ACPI_DIV_64_BY_32
end_ifndef

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
value|do { \         UINT64 (__n) = ((UINT64) n_hi)<< 32 | (n_lo); \         (r32) = do_div ((__n), (d32)); \         (q32) = (UINT32) (__n); \     } while (0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ACPI_SHIFT_RIGHT_64
end_ifndef

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
value|do { \         (n_lo)>>= 1; \         (n_lo) |= (((n_hi)& 1)<< 31); \         (n_hi)>>= 1; \     } while (0)
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
comment|/*  * Overrides for in-kernel ACPICA  */
end_comment

begin_function_decl
name|ACPI_STATUS
name|__init
name|AcpiOsInitialize
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ACPI_STATUS
name|AcpiOsTerminate
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * The irqs_disabled() check is for resume from RAM.  * Interrupts are off during resume, just like they are for boot.  * However, boot has  (system_state != SYSTEM_RUNNING)  * to quiet __might_sleep() in kmalloc() and resume does not.  */
end_comment

begin_function
specifier|static
specifier|inline
name|void
modifier|*
name|AcpiOsAllocate
parameter_list|(
name|ACPI_SIZE
name|Size
parameter_list|)
block|{
return|return
name|kmalloc
argument_list|(
name|Size
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
name|AcpiOsAllocateZeroed
parameter_list|(
name|ACPI_SIZE
name|Size
parameter_list|)
block|{
return|return
name|kzalloc
argument_list|(
name|Size
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
name|AcpiOsFree
parameter_list|(
name|void
modifier|*
name|Memory
parameter_list|)
block|{
name|kfree
argument_list|(
name|Memory
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|void
modifier|*
name|AcpiOsAcquireObject
parameter_list|(
name|ACPI_CACHE_T
modifier|*
name|Cache
parameter_list|)
block|{
return|return
name|kmem_cache_zalloc
argument_list|(
name|Cache
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
name|ACPI_THREAD_ID
name|AcpiOsGetThreadId
parameter_list|(
name|void
parameter_list|)
block|{
return|return
operator|(
name|ACPI_THREAD_ID
operator|)
operator|(
name|unsigned
name|long
operator|)
name|current
return|;
block|}
end_function

begin_comment
comment|/*  * When lockdep is enabled, the spin_lock_init() macro stringifies it's  * argument and uses that as a name for the lock in debugging.  * By executing spin_lock_init() in a macro the key changes from "lock" for  * all locks to the name of the argument of acpi_os_create_lock(), which  * prevents lockdep from reporting false positives for ACPICA locks.  */
end_comment

begin_define
define|#
directive|define
name|AcpiOsCreateLock
parameter_list|(
name|__Handle
parameter_list|)
define|\
value|({ \         spinlock_t *Lock = ACPI_ALLOCATE(sizeof(*Lock)); \         if (Lock) { \             *(__Handle) = Lock; \             spin_lock_init(*(__Handle)); \         } \         Lock ? AE_OK : AE_NO_MEMORY; \     })
end_define

begin_comment
comment|/*  * OSL interfaces added by Linux  */
end_comment

begin_function_decl
name|void
name|EarlyAcpiOsUnmapMemory
parameter_list|(
name|void
name|__iomem
modifier|*
name|Virt
parameter_list|,
name|ACPI_SIZE
name|Size
parameter_list|)
function_decl|;
end_function_decl

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
comment|/* __ACLINUXEX_H__ */
end_comment

end_unit

