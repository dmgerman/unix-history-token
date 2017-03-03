begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/******************************************************************************  *  * Name: aclinuxex.h - Extra OS specific defines, etc. for Linux  *  *****************************************************************************/
end_comment

begin_comment
comment|/******************************************************************************  *  * 1. Copyright Notice  *  * Some or all of this work - Copyright (c) 1999 - 2017, Intel Corp.  * All rights reserved.  *  * 2. License  *  * 2.1. This is your license from Intel Corp. under its intellectual property  * rights. You may have additional license terms from the party that provided  * you this software, covering your right to use that party's intellectual  * property rights.  *  * 2.2. Intel grants, free of charge, to any person ("Licensee") obtaining a  * copy of the source code appearing in this file ("Covered Code") an  * irrevocable, perpetual, worldwide license under Intel's copyrights in the  * base code distributed originally by Intel ("Original Intel Code") to copy,  * make derivatives, distribute, use and display any portion of the Covered  * Code in any form, with the right to sublicense such rights; and  *  * 2.3. Intel grants Licensee a non-exclusive and non-transferable patent  * license (with the right to sublicense), under only those claims of Intel  * patents that are infringed by the Original Intel Code, to make, use, sell,  * offer to sell, and import the Covered Code and derivative works thereof  * solely to the minimum extent necessary to exercise the above copyright  * license, and in no event shall the patent license extend to any additions  * to or modifications of the Original Intel Code. No other license or right  * is granted directly or by implication, estoppel or otherwise;  *  * The above copyright and patent license is granted only if the following  * conditions are met:  *  * 3. Conditions  *  * 3.1. Redistribution of Source with Rights to Further Distribute Source.  * Redistribution of source code of any substantial portion of the Covered  * Code or modification with rights to further distribute source must include  * the above Copyright Notice, the above License, this list of Conditions,  * and the following Disclaimer and Export Compliance provision. In addition,  * Licensee must cause all Covered Code to which Licensee contributes to  * contain a file documenting the changes Licensee made to create that Covered  * Code and the date of any change. Licensee must include in that file the  * documentation of any changes made by any predecessor Licensee. Licensee  * must include a prominent statement that the modification is derived,  * directly or indirectly, from Original Intel Code.  *  * 3.2. Redistribution of Source with no Rights to Further Distribute Source.  * Redistribution of source code of any substantial portion of the Covered  * Code or modification without rights to further distribute source must  * include the following Disclaimer and Export Compliance provision in the  * documentation and/or other materials provided with distribution. In  * addition, Licensee may not authorize further sublicense of source of any  * portion of the Covered Code, and must include terms to the effect that the  * license from Licensee to its licensee is limited to the intellectual  * property embodied in the software Licensee provides to its licensee, and  * not to intellectual property embodied in modifications its licensee may  * make.  *  * 3.3. Redistribution of Executable. Redistribution in executable form of any  * substantial portion of the Covered Code or modification must reproduce the  * above Copyright Notice, and the following Disclaimer and Export Compliance  * provision in the documentation and/or other materials provided with the  * distribution.  *  * 3.4. Intel retains all right, title, and interest in and to the Original  * Intel Code.  *  * 3.5. Neither the name Intel nor any other trademark owned or controlled by  * Intel shall be used in advertising or otherwise to promote the sale, use or  * other dealings in products derived from or relating to the Covered Code  * without prior written authorization from Intel.  *  * 4. Disclaimer and Export Compliance  *  * 4.1. INTEL MAKES NO WARRANTY OF ANY KIND REGARDING ANY SOFTWARE PROVIDED  * HERE. ANY SOFTWARE ORIGINATING FROM INTEL OR DERIVED FROM INTEL SOFTWARE  * IS PROVIDED "AS IS," AND INTEL WILL NOT PROVIDE ANY SUPPORT, ASSISTANCE,  * INSTALLATION, TRAINING OR OTHER SERVICES. INTEL WILL NOT PROVIDE ANY  * UPDATES, ENHANCEMENTS OR EXTENSIONS. INTEL SPECIFICALLY DISCLAIMS ANY  * IMPLIED WARRANTIES OF MERCHANTABILITY, NONINFRINGEMENT AND FITNESS FOR A  * PARTICULAR PURPOSE.  *  * 4.2. IN NO EVENT SHALL INTEL HAVE ANY LIABILITY TO LICENSEE, ITS LICENSEES  * OR ANY OTHER THIRD PARTY, FOR ANY LOST PROFITS, LOST DATA, LOSS OF USE OR  * COSTS OF PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES, OR FOR ANY INDIRECT,  * SPECIAL OR CONSEQUENTIAL DAMAGES ARISING OUT OF THIS AGREEMENT, UNDER ANY  * CAUSE OF ACTION OR THEORY OF LIABILITY, AND IRRESPECTIVE OF WHETHER INTEL  * HAS ADVANCE NOTICE OF THE POSSIBILITY OF SUCH DAMAGES. THESE LIMITATIONS  * SHALL APPLY NOTWITHSTANDING THE FAILURE OF THE ESSENTIAL PURPOSE OF ANY  * LIMITED REMEDY.  *  * 4.3. Licensee shall not export, either directly or indirectly, any of this  * software or system incorporating such software without first obtaining any  * required license or other approval from the U. S. Department of Commerce or  * any other agency or department of the United States Government. In the  * event Licensee exports any such software from the United States or  * re-exports any such software from a foreign destination, Licensee shall  * ensure that the distribution and export/re-export of the software is in  * compliance with all laws, regulations, orders, or other restrictions of the  * U.S. Export Administration Regulations. Licensee agrees that neither it nor  * any of its subsidiaries will export/re-export any technical data, process,  * software, or service, directly or indirectly, to any country for which the  * United States government or any agency thereof requires an export license,  * other governmental approval, or letter of assurance, without first obtaining  * such license, approval or letter.  *  *****************************************************************************  *  * Alternatively, you may choose to be licensed under the terms of the  * following license:  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions, and the following disclaimer,  *    without modification.  * 2. Redistributions in binary form must reproduce at minimum a disclaimer  *    substantially similar to the "NO WARRANTY" disclaimer below  *    ("Disclaimer") and any redistribution must be conditioned upon  *    including a substantially similar Disclaimer requirement for further  *    binary redistribution.  * 3. Neither the names of the above-listed copyright holders nor the names  *    of any contributors may be used to endorse or promote products derived  *    from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT  * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR  * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT  * OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,  * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT  * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE  * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * Alternatively, you may choose to be licensed under the terms of the  * GNU General Public License ("GPL") version 2 as published by the Free  * Software Foundation.  *  *****************************************************************************/
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
name|ACPI_INIT_FUNCTION
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

begin_function
specifier|static
specifier|inline
name|BOOLEAN
name|AcpiOsReadable
parameter_list|(
name|void
modifier|*
name|Pointer
parameter_list|,
name|ACPI_SIZE
name|Length
parameter_list|)
block|{
return|return
name|TRUE
return|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|ACPI_STATUS
name|AcpiOsInitializeDebugger
parameter_list|(
name|void
parameter_list|)
block|{
return|return
name|AE_OK
return|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|void
name|AcpiOsTerminateDebugger
parameter_list|(
name|void
parameter_list|)
block|{
return|return;
block|}
end_function

begin_comment
comment|/*  * OSL interfaces added by Linux  */
end_comment

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

