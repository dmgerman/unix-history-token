begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/******************************************************************************  *  * Name: actypes.h - Common data types for the entire ACPI subsystem  *  *****************************************************************************/
end_comment

begin_comment
comment|/******************************************************************************  *  * 1. Copyright Notice  *  * Some or all of this work - Copyright (c) 1999 - 2017, Intel Corp.  * All rights reserved.  *  * 2. License  *  * 2.1. This is your license from Intel Corp. under its intellectual property  * rights. You may have additional license terms from the party that provided  * you this software, covering your right to use that party's intellectual  * property rights.  *  * 2.2. Intel grants, free of charge, to any person ("Licensee") obtaining a  * copy of the source code appearing in this file ("Covered Code") an  * irrevocable, perpetual, worldwide license under Intel's copyrights in the  * base code distributed originally by Intel ("Original Intel Code") to copy,  * make derivatives, distribute, use and display any portion of the Covered  * Code in any form, with the right to sublicense such rights; and  *  * 2.3. Intel grants Licensee a non-exclusive and non-transferable patent  * license (with the right to sublicense), under only those claims of Intel  * patents that are infringed by the Original Intel Code, to make, use, sell,  * offer to sell, and import the Covered Code and derivative works thereof  * solely to the minimum extent necessary to exercise the above copyright  * license, and in no event shall the patent license extend to any additions  * to or modifications of the Original Intel Code. No other license or right  * is granted directly or by implication, estoppel or otherwise;  *  * The above copyright and patent license is granted only if the following  * conditions are met:  *  * 3. Conditions  *  * 3.1. Redistribution of Source with Rights to Further Distribute Source.  * Redistribution of source code of any substantial portion of the Covered  * Code or modification with rights to further distribute source must include  * the above Copyright Notice, the above License, this list of Conditions,  * and the following Disclaimer and Export Compliance provision. In addition,  * Licensee must cause all Covered Code to which Licensee contributes to  * contain a file documenting the changes Licensee made to create that Covered  * Code and the date of any change. Licensee must include in that file the  * documentation of any changes made by any predecessor Licensee. Licensee  * must include a prominent statement that the modification is derived,  * directly or indirectly, from Original Intel Code.  *  * 3.2. Redistribution of Source with no Rights to Further Distribute Source.  * Redistribution of source code of any substantial portion of the Covered  * Code or modification without rights to further distribute source must  * include the following Disclaimer and Export Compliance provision in the  * documentation and/or other materials provided with distribution. In  * addition, Licensee may not authorize further sublicense of source of any  * portion of the Covered Code, and must include terms to the effect that the  * license from Licensee to its licensee is limited to the intellectual  * property embodied in the software Licensee provides to its licensee, and  * not to intellectual property embodied in modifications its licensee may  * make.  *  * 3.3. Redistribution of Executable. Redistribution in executable form of any  * substantial portion of the Covered Code or modification must reproduce the  * above Copyright Notice, and the following Disclaimer and Export Compliance  * provision in the documentation and/or other materials provided with the  * distribution.  *  * 3.4. Intel retains all right, title, and interest in and to the Original  * Intel Code.  *  * 3.5. Neither the name Intel nor any other trademark owned or controlled by  * Intel shall be used in advertising or otherwise to promote the sale, use or  * other dealings in products derived from or relating to the Covered Code  * without prior written authorization from Intel.  *  * 4. Disclaimer and Export Compliance  *  * 4.1. INTEL MAKES NO WARRANTY OF ANY KIND REGARDING ANY SOFTWARE PROVIDED  * HERE. ANY SOFTWARE ORIGINATING FROM INTEL OR DERIVED FROM INTEL SOFTWARE  * IS PROVIDED "AS IS," AND INTEL WILL NOT PROVIDE ANY SUPPORT, ASSISTANCE,  * INSTALLATION, TRAINING OR OTHER SERVICES. INTEL WILL NOT PROVIDE ANY  * UPDATES, ENHANCEMENTS OR EXTENSIONS. INTEL SPECIFICALLY DISCLAIMS ANY  * IMPLIED WARRANTIES OF MERCHANTABILITY, NONINFRINGEMENT AND FITNESS FOR A  * PARTICULAR PURPOSE.  *  * 4.2. IN NO EVENT SHALL INTEL HAVE ANY LIABILITY TO LICENSEE, ITS LICENSEES  * OR ANY OTHER THIRD PARTY, FOR ANY LOST PROFITS, LOST DATA, LOSS OF USE OR  * COSTS OF PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES, OR FOR ANY INDIRECT,  * SPECIAL OR CONSEQUENTIAL DAMAGES ARISING OUT OF THIS AGREEMENT, UNDER ANY  * CAUSE OF ACTION OR THEORY OF LIABILITY, AND IRRESPECTIVE OF WHETHER INTEL  * HAS ADVANCE NOTICE OF THE POSSIBILITY OF SUCH DAMAGES. THESE LIMITATIONS  * SHALL APPLY NOTWITHSTANDING THE FAILURE OF THE ESSENTIAL PURPOSE OF ANY  * LIMITED REMEDY.  *  * 4.3. Licensee shall not export, either directly or indirectly, any of this  * software or system incorporating such software without first obtaining any  * required license or other approval from the U. S. Department of Commerce or  * any other agency or department of the United States Government. In the  * event Licensee exports any such software from the United States or  * re-exports any such software from a foreign destination, Licensee shall  * ensure that the distribution and export/re-export of the software is in  * compliance with all laws, regulations, orders, or other restrictions of the  * U.S. Export Administration Regulations. Licensee agrees that neither it nor  * any of its subsidiaries will export/re-export any technical data, process,  * software, or service, directly or indirectly, to any country for which the  * United States government or any agency thereof requires an export license,  * other governmental approval, or letter of assurance, without first obtaining  * such license, approval or letter.  *  *****************************************************************************  *  * Alternatively, you may choose to be licensed under the terms of the  * following license:  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions, and the following disclaimer,  *    without modification.  * 2. Redistributions in binary form must reproduce at minimum a disclaimer  *    substantially similar to the "NO WARRANTY" disclaimer below  *    ("Disclaimer") and any redistribution must be conditioned upon  *    including a substantially similar Disclaimer requirement for further  *    binary redistribution.  * 3. Neither the names of the above-listed copyright holders nor the names  *    of any contributors may be used to endorse or promote products derived  *    from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT  * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR  * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT  * OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,  * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT  * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE  * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * Alternatively, you may choose to be licensed under the terms of the  * GNU General Public License ("GPL") version 2 as published by the Free  * Software Foundation.  *  *****************************************************************************/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__ACTYPES_H__
end_ifndef

begin_define
define|#
directive|define
name|__ACTYPES_H__
end_define

begin_comment
comment|/* acpisrc:StructDefs -- for acpisrc conversion */
end_comment

begin_comment
comment|/*  * ACPI_MACHINE_WIDTH must be specified in an OS- or compiler-dependent  * header and must be either 32 or 64. 16-bit ACPICA is no longer  * supported, as of 12/2006.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|ACPI_MACHINE_WIDTH
end_ifndef

begin_error
error|#
directive|error
error|ACPI_MACHINE_WIDTH not defined
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Data type ranges  * Note: These macros are designed to be compiler independent as well as  * working around problems that some 32-bit compilers have with 64-bit  * constants.  */
end_comment

begin_define
define|#
directive|define
name|ACPI_UINT8_MAX
value|(UINT8) (~((UINT8)  0))
end_define

begin_comment
comment|/* 0xFF               */
end_comment

begin_define
define|#
directive|define
name|ACPI_UINT16_MAX
value|(UINT16)(~((UINT16) 0))
end_define

begin_comment
comment|/* 0xFFFF             */
end_comment

begin_define
define|#
directive|define
name|ACPI_UINT32_MAX
value|(UINT32)(~((UINT32) 0))
end_define

begin_comment
comment|/* 0xFFFFFFFF         */
end_comment

begin_define
define|#
directive|define
name|ACPI_UINT64_MAX
value|(UINT64)(~((UINT64) 0))
end_define

begin_comment
comment|/* 0xFFFFFFFFFFFFFFFF */
end_comment

begin_define
define|#
directive|define
name|ACPI_ASCII_MAX
value|0x7F
end_define

begin_comment
comment|/*  * Architecture-specific ACPICA Subsystem Data Types  *  * The goal of these types is to provide source code portability across  * 16-bit, 32-bit, and 64-bit targets.  *  * 1) The following types are of fixed size for all targets (16/32/64):  *  * BOOLEAN      Logical boolean  *  * UINT8        8-bit  (1 byte) unsigned value  * UINT16       16-bit (2 byte) unsigned value  * UINT32       32-bit (4 byte) unsigned value  * UINT64       64-bit (8 byte) unsigned value  *  * INT16        16-bit (2 byte) signed value  * INT32        32-bit (4 byte) signed value  * INT64        64-bit (8 byte) signed value  *  * COMPILER_DEPENDENT_UINT64/INT64 - These types are defined in the  * compiler-dependent header(s) and were introduced because there is no  * common 64-bit integer type across the various compilation models, as  * shown in the table below.  *  * Datatype  LP64 ILP64 LLP64 ILP32 LP32 16bit  * char      8    8     8     8     8    8  * short     16   16    16    16    16   16  * _int32         32  * int       32   64    32    32    16   16  * long      64   64    32    32    32   32  * long long            64    64  * pointer   64   64    64    32    32   32  *  * Note: ILP64 and LP32 are currently not supported.  *  *  * 2) These types represent the native word size of the target mode of the  * processor, and may be 16-bit, 32-bit, or 64-bit as required. They are  * usually used for memory allocation, efficient loop counters, and array  * indexes. The types are similar to the size_t type in the C library and  * are required because there is no C type that consistently represents the  * native data width. ACPI_SIZE is needed because there is no guarantee  * that a kernel-level C library is present.  *  * ACPI_SIZE        16/32/64-bit unsigned value  * ACPI_NATIVE_INT  16/32/64-bit signed value  */
end_comment

begin_comment
comment|/*******************************************************************************  *  * Common types for all compilers, all targets  *  ******************************************************************************/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|ACPI_USE_SYSTEM_INTTYPES
end_ifndef

begin_typedef
typedef|typedef
name|unsigned
name|char
name|BOOLEAN
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|char
name|UINT8
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|short
name|UINT16
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|short
name|INT16
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|COMPILER_DEPENDENT_UINT64
name|UINT64
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|COMPILER_DEPENDENT_INT64
name|INT64
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ACPI_USE_SYSTEM_INTTYPES */
end_comment

begin_comment
comment|/*  * Value returned by AcpiOsGetThreadId. There is no standard "thread_id"  * across operating systems or even the various UNIX systems. Since ACPICA  * only needs the thread ID as a unique thread identifier, we use a UINT64  * as the only common data type - it will accommodate any type of pointer or  * any type of integer. It is up to the host-dependent OSL to cast the  * native thread ID type to a UINT64 (in AcpiOsGetThreadId).  */
end_comment

begin_define
define|#
directive|define
name|ACPI_THREAD_ID
value|UINT64
end_define

begin_comment
comment|/*******************************************************************************  *  * Types specific to 64-bit targets  *  ******************************************************************************/
end_comment

begin_if
if|#
directive|if
name|ACPI_MACHINE_WIDTH
operator|==
literal|64
end_if

begin_ifndef
ifndef|#
directive|ifndef
name|ACPI_USE_SYSTEM_INTTYPES
end_ifndef

begin_typedef
typedef|typedef
name|unsigned
name|int
name|UINT32
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|int
name|INT32
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ACPI_USE_SYSTEM_INTTYPES */
end_comment

begin_typedef
typedef|typedef
name|INT64
name|ACPI_NATIVE_INT
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|UINT64
name|ACPI_SIZE
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|UINT64
name|ACPI_IO_ADDRESS
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|UINT64
name|ACPI_PHYSICAL_ADDRESS
typedef|;
end_typedef

begin_define
define|#
directive|define
name|ACPI_MAX_PTR
value|ACPI_UINT64_MAX
end_define

begin_define
define|#
directive|define
name|ACPI_SIZE_MAX
value|ACPI_UINT64_MAX
end_define

begin_define
define|#
directive|define
name|ACPI_USE_NATIVE_DIVIDE
end_define

begin_comment
comment|/* Has native 64-bit integer support */
end_comment

begin_comment
comment|/*  * In the case of the Itanium Processor Family (IPF), the hardware does not  * support misaligned memory transfers. Set the MISALIGNMENT_NOT_SUPPORTED  * flag to indicate that special precautions must be taken to avoid alignment  * faults. (IA64 or ia64 is currently used by existing compilers to indicate  * IPF.)  *  * Note: EM64T and other X86-64 processors support misaligned transfers,  * so there is no need to define this flag.  */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__IA64__
argument_list|)
operator|||
name|defined
argument_list|(
name|__ia64__
argument_list|)
end_if

begin_define
define|#
directive|define
name|ACPI_MISALIGNMENT_NOT_SUPPORTED
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*******************************************************************************  *  * Types specific to 32-bit targets  *  ******************************************************************************/
end_comment

begin_elif
elif|#
directive|elif
name|ACPI_MACHINE_WIDTH
operator|==
literal|32
end_elif

begin_ifndef
ifndef|#
directive|ifndef
name|ACPI_USE_SYSTEM_INTTYPES
end_ifndef

begin_typedef
typedef|typedef
name|unsigned
name|int
name|UINT32
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|int
name|INT32
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ACPI_USE_SYSTEM_INTTYPES */
end_comment

begin_typedef
typedef|typedef
name|INT32
name|ACPI_NATIVE_INT
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|UINT32
name|ACPI_SIZE
typedef|;
end_typedef

begin_ifdef
ifdef|#
directive|ifdef
name|ACPI_32BIT_PHYSICAL_ADDRESS
end_ifdef

begin_comment
comment|/*  * OSPMs can define this to shrink the size of the structures for 32-bit  * none PAE environment. ASL compiler may always define this to generate  * 32-bit OSPM compliant tables.  */
end_comment

begin_typedef
typedef|typedef
name|UINT32
name|ACPI_IO_ADDRESS
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|UINT32
name|ACPI_PHYSICAL_ADDRESS
typedef|;
end_typedef

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* ACPI_32BIT_PHYSICAL_ADDRESS */
end_comment

begin_comment
comment|/*  * It is reported that, after some calculations, the physical addresses can  * wrap over the 32-bit boundary on 32-bit PAE environment.  * https://bugzilla.kernel.org/show_bug.cgi?id=87971  */
end_comment

begin_typedef
typedef|typedef
name|UINT64
name|ACPI_IO_ADDRESS
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|UINT64
name|ACPI_PHYSICAL_ADDRESS
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ACPI_32BIT_PHYSICAL_ADDRESS */
end_comment

begin_define
define|#
directive|define
name|ACPI_MAX_PTR
value|ACPI_UINT32_MAX
end_define

begin_define
define|#
directive|define
name|ACPI_SIZE_MAX
value|ACPI_UINT32_MAX
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* ACPI_MACHINE_WIDTH must be either 64 or 32 */
end_comment

begin_error
error|#
directive|error
error|unknown ACPI_MACHINE_WIDTH
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*******************************************************************************  *  * OS-dependent types  *  * If the defaults below are not appropriate for the host system, they can  * be defined in the OS-specific header, and this will take precedence.  *  ******************************************************************************/
end_comment

begin_comment
comment|/* Flags for AcpiOsAcquireLock/AcpiOsReleaseLock */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|ACPI_CPU_FLAGS
end_ifndef

begin_define
define|#
directive|define
name|ACPI_CPU_FLAGS
value|ACPI_SIZE
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Object returned from AcpiOsCreateCache */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|ACPI_CACHE_T
end_ifndef

begin_ifdef
ifdef|#
directive|ifdef
name|ACPI_USE_LOCAL_CACHE
end_ifdef

begin_define
define|#
directive|define
name|ACPI_CACHE_T
value|ACPI_MEMORY_LIST
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|ACPI_CACHE_T
value|void *
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
comment|/*  * Synchronization objects - Mutexes, Semaphores, and SpinLocks  */
end_comment

begin_if
if|#
directive|if
operator|(
name|ACPI_MUTEX_TYPE
operator|==
name|ACPI_BINARY_SEMAPHORE
operator|)
end_if

begin_comment
comment|/*  * These macros are used if the host OS does not support a mutex object.  * Map the OSL Mutex interfaces to binary semaphores.  */
end_comment

begin_define
define|#
directive|define
name|ACPI_MUTEX
value|ACPI_SEMAPHORE
end_define

begin_define
define|#
directive|define
name|AcpiOsCreateMutex
parameter_list|(
name|OutHandle
parameter_list|)
value|AcpiOsCreateSemaphore (1, 1, OutHandle)
end_define

begin_define
define|#
directive|define
name|AcpiOsDeleteMutex
parameter_list|(
name|Handle
parameter_list|)
value|(void) AcpiOsDeleteSemaphore (Handle)
end_define

begin_define
define|#
directive|define
name|AcpiOsAcquireMutex
parameter_list|(
name|Handle
parameter_list|,
name|Time
parameter_list|)
value|AcpiOsWaitSemaphore (Handle, 1, Time)
end_define

begin_define
define|#
directive|define
name|AcpiOsReleaseMutex
parameter_list|(
name|Handle
parameter_list|)
value|(void) AcpiOsSignalSemaphore (Handle, 1)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Configurable types for synchronization objects */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|ACPI_SPINLOCK
end_ifndef

begin_define
define|#
directive|define
name|ACPI_SPINLOCK
value|void *
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ACPI_SEMAPHORE
end_ifndef

begin_define
define|#
directive|define
name|ACPI_SEMAPHORE
value|void *
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ACPI_MUTEX
end_ifndef

begin_define
define|#
directive|define
name|ACPI_MUTEX
value|void *
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*******************************************************************************  *  * Compiler-dependent types  *  * If the defaults below are not appropriate for the host compiler, they can  * be defined in the compiler-specific header, and this will take precedence.  *  ******************************************************************************/
end_comment

begin_comment
comment|/* Use C99 uintptr_t for pointer casting if available, "void *" otherwise */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|ACPI_UINTPTR_T
end_ifndef

begin_define
define|#
directive|define
name|ACPI_UINTPTR_T
value|void *
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * ACPI_PRINTF_LIKE is used to tag functions as "printf-like" because  * some compilers can catch printf format string problems  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|ACPI_PRINTF_LIKE
end_ifndef

begin_define
define|#
directive|define
name|ACPI_PRINTF_LIKE
parameter_list|(
name|c
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Some compilers complain about unused variables. Sometimes we don't want  * to use all the variables (for example, _AcpiModuleName). This allows us  * to tell the compiler in a per-variable manner that a variable  * is unused  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|ACPI_UNUSED_VAR
end_ifndef

begin_define
define|#
directive|define
name|ACPI_UNUSED_VAR
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * All ACPICA external functions that are available to the rest of the  * kernel are tagged with these macros which can be defined as appropriate  * for the host.  *  * Notes:  * ACPI_EXPORT_SYMBOL_INIT is used for initialization and termination  * interfaces that may need special processing.  * ACPI_EXPORT_SYMBOL is used for all other public external functions.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|ACPI_EXPORT_SYMBOL_INIT
end_ifndef

begin_define
define|#
directive|define
name|ACPI_EXPORT_SYMBOL_INIT
parameter_list|(
name|Symbol
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ACPI_EXPORT_SYMBOL
end_ifndef

begin_define
define|#
directive|define
name|ACPI_EXPORT_SYMBOL
parameter_list|(
name|Symbol
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Compiler/Clibrary-dependent debug initialization. Used for ACPICA  * utilities only.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|ACPI_DEBUG_INITIALIZE
end_ifndef

begin_define
define|#
directive|define
name|ACPI_DEBUG_INITIALIZE
parameter_list|()
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*******************************************************************************  *  * Configuration  *  ******************************************************************************/
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|ACPI_NO_MEM_ALLOCATIONS
end_ifdef

begin_define
define|#
directive|define
name|ACPI_ALLOCATE
parameter_list|(
name|a
parameter_list|)
value|NULL
end_define

begin_define
define|#
directive|define
name|ACPI_ALLOCATE_ZEROED
parameter_list|(
name|a
parameter_list|)
value|NULL
end_define

begin_define
define|#
directive|define
name|ACPI_FREE
parameter_list|(
name|a
parameter_list|)
end_define

begin_define
define|#
directive|define
name|ACPI_MEM_TRACKING
parameter_list|(
name|a
parameter_list|)
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* ACPI_NO_MEM_ALLOCATIONS */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|ACPI_DBG_TRACK_ALLOCATIONS
end_ifdef

begin_comment
comment|/*  * Memory allocation tracking (used by AcpiExec to detect memory leaks)  */
end_comment

begin_define
define|#
directive|define
name|ACPI_MEM_PARAMETERS
value|_COMPONENT, _AcpiModuleName, __LINE__
end_define

begin_define
define|#
directive|define
name|ACPI_ALLOCATE
parameter_list|(
name|a
parameter_list|)
value|AcpiUtAllocateAndTrack ((ACPI_SIZE) (a), ACPI_MEM_PARAMETERS)
end_define

begin_define
define|#
directive|define
name|ACPI_ALLOCATE_ZEROED
parameter_list|(
name|a
parameter_list|)
value|AcpiUtAllocateZeroedAndTrack ((ACPI_SIZE) (a), ACPI_MEM_PARAMETERS)
end_define

begin_define
define|#
directive|define
name|ACPI_FREE
parameter_list|(
name|a
parameter_list|)
value|AcpiUtFreeAndTrack (a, ACPI_MEM_PARAMETERS)
end_define

begin_define
define|#
directive|define
name|ACPI_MEM_TRACKING
parameter_list|(
name|a
parameter_list|)
value|a
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/*  * Normal memory allocation directly via the OS services layer  */
end_comment

begin_define
define|#
directive|define
name|ACPI_ALLOCATE
parameter_list|(
name|a
parameter_list|)
value|AcpiOsAllocate ((ACPI_SIZE) (a))
end_define

begin_define
define|#
directive|define
name|ACPI_ALLOCATE_ZEROED
parameter_list|(
name|a
parameter_list|)
value|AcpiOsAllocateZeroed ((ACPI_SIZE) (a))
end_define

begin_define
define|#
directive|define
name|ACPI_FREE
parameter_list|(
name|a
parameter_list|)
value|AcpiOsFree (a)
end_define

begin_define
define|#
directive|define
name|ACPI_MEM_TRACKING
parameter_list|(
name|a
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ACPI_DBG_TRACK_ALLOCATIONS */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ACPI_NO_MEM_ALLOCATIONS */
end_comment

begin_comment
comment|/******************************************************************************  *  * ACPI Specification constants (Do not change unless the specification  * changes)  *  *****************************************************************************/
end_comment

begin_comment
comment|/* Number of distinct FADT-based GPE register blocks (GPE0 and GPE1) */
end_comment

begin_define
define|#
directive|define
name|ACPI_MAX_GPE_BLOCKS
value|2
end_define

begin_comment
comment|/* Default ACPI register widths */
end_comment

begin_define
define|#
directive|define
name|ACPI_GPE_REGISTER_WIDTH
value|8
end_define

begin_define
define|#
directive|define
name|ACPI_PM1_REGISTER_WIDTH
value|16
end_define

begin_define
define|#
directive|define
name|ACPI_PM2_REGISTER_WIDTH
value|8
end_define

begin_define
define|#
directive|define
name|ACPI_PM_TIMER_WIDTH
value|32
end_define

begin_define
define|#
directive|define
name|ACPI_RESET_REGISTER_WIDTH
value|8
end_define

begin_comment
comment|/* Names within the namespace are 4 bytes long */
end_comment

begin_define
define|#
directive|define
name|ACPI_NAME_SIZE
value|4
end_define

begin_define
define|#
directive|define
name|ACPI_PATH_SEGMENT_LENGTH
value|5
end_define

begin_comment
comment|/* 4 chars for name + 1 char for separator */
end_comment

begin_define
define|#
directive|define
name|ACPI_PATH_SEPARATOR
value|'.'
end_define

begin_comment
comment|/* Sizes for ACPI table headers */
end_comment

begin_define
define|#
directive|define
name|ACPI_OEM_ID_SIZE
value|6
end_define

begin_define
define|#
directive|define
name|ACPI_OEM_TABLE_ID_SIZE
value|8
end_define

begin_comment
comment|/* ACPI/PNP hardware IDs */
end_comment

begin_define
define|#
directive|define
name|PCI_ROOT_HID_STRING
value|"PNP0A03"
end_define

begin_define
define|#
directive|define
name|PCI_EXPRESS_ROOT_HID_STRING
value|"PNP0A08"
end_define

begin_comment
comment|/* PM Timer ticks per second (HZ) */
end_comment

begin_define
define|#
directive|define
name|ACPI_PM_TIMER_FREQUENCY
value|3579545
end_define

begin_comment
comment|/*******************************************************************************  *  * Independent types  *  ******************************************************************************/
end_comment

begin_comment
comment|/* Logical defines and NULL */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|FALSE
end_ifdef

begin_undef
undef|#
directive|undef
name|FALSE
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|FALSE
value|(1 == 0)
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|TRUE
end_ifdef

begin_undef
undef|#
directive|undef
name|TRUE
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|TRUE
value|(1 == 1)
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|NULL
end_ifndef

begin_define
define|#
directive|define
name|NULL
value|(void *) 0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Miscellaneous types  */
end_comment

begin_typedef
typedef|typedef
name|UINT32
name|ACPI_STATUS
typedef|;
end_typedef

begin_comment
comment|/* All ACPI Exceptions */
end_comment

begin_typedef
typedef|typedef
name|UINT32
name|ACPI_NAME
typedef|;
end_typedef

begin_comment
comment|/* 4-byte ACPI name */
end_comment

begin_typedef
typedef|typedef
name|char
modifier|*
name|ACPI_STRING
typedef|;
end_typedef

begin_comment
comment|/* Null terminated ASCII string */
end_comment

begin_typedef
typedef|typedef
name|void
modifier|*
name|ACPI_HANDLE
typedef|;
end_typedef

begin_comment
comment|/* Actually a ptr to a NS Node */
end_comment

begin_comment
comment|/* Time constants for timer calculations */
end_comment

begin_define
define|#
directive|define
name|ACPI_MSEC_PER_SEC
value|1000L
end_define

begin_define
define|#
directive|define
name|ACPI_USEC_PER_MSEC
value|1000L
end_define

begin_define
define|#
directive|define
name|ACPI_USEC_PER_SEC
value|1000000L
end_define

begin_define
define|#
directive|define
name|ACPI_100NSEC_PER_USEC
value|10L
end_define

begin_define
define|#
directive|define
name|ACPI_100NSEC_PER_MSEC
value|10000L
end_define

begin_define
define|#
directive|define
name|ACPI_100NSEC_PER_SEC
value|10000000L
end_define

begin_define
define|#
directive|define
name|ACPI_NSEC_PER_USEC
value|1000L
end_define

begin_define
define|#
directive|define
name|ACPI_NSEC_PER_MSEC
value|1000000L
end_define

begin_define
define|#
directive|define
name|ACPI_NSEC_PER_SEC
value|1000000000L
end_define

begin_comment
comment|/* Owner IDs are used to track namespace nodes for selective deletion */
end_comment

begin_typedef
typedef|typedef
name|UINT8
name|ACPI_OWNER_ID
typedef|;
end_typedef

begin_define
define|#
directive|define
name|ACPI_OWNER_ID_MAX
value|0xFF
end_define

begin_define
define|#
directive|define
name|ACPI_INTEGER_BIT_SIZE
value|64
end_define

begin_define
define|#
directive|define
name|ACPI_MAX_DECIMAL_DIGITS
value|20
end_define

begin_comment
comment|/* 2^64 = 18,446,744,073,709,551,616 */
end_comment

begin_define
define|#
directive|define
name|ACPI_MAX64_DECIMAL_DIGITS
value|20
end_define

begin_define
define|#
directive|define
name|ACPI_MAX32_DECIMAL_DIGITS
value|10
end_define

begin_define
define|#
directive|define
name|ACPI_MAX16_DECIMAL_DIGITS
value|5
end_define

begin_define
define|#
directive|define
name|ACPI_MAX8_DECIMAL_DIGITS
value|3
end_define

begin_comment
comment|/*  * Constants with special meanings  */
end_comment

begin_define
define|#
directive|define
name|ACPI_ROOT_OBJECT
value|ACPI_ADD_PTR (ACPI_HANDLE, NULL, ACPI_MAX_PTR)
end_define

begin_define
define|#
directive|define
name|ACPI_WAIT_FOREVER
value|0xFFFF
end_define

begin_comment
comment|/* UINT16, as per ACPI spec */
end_comment

begin_define
define|#
directive|define
name|ACPI_DO_NOT_WAIT
value|0
end_define

begin_comment
comment|/*  * Obsolete: Acpi integer width. In ACPI version 1 (1996), integers are  * 32 bits. In ACPI version 2 (2000) and later, integers are max 64 bits.  * Note that this pertains to the ACPI integer type only, not to other  * integers used in the implementation of the ACPICA subsystem.  *  * 01/2010: This type is obsolete and has been removed from the entire ACPICA  * code base. It remains here for compatibility with device drivers that use  * the type. However, it will be removed in the future.  */
end_comment

begin_typedef
typedef|typedef
name|UINT64
name|ACPI_INTEGER
typedef|;
end_typedef

begin_define
define|#
directive|define
name|ACPI_INTEGER_MAX
value|ACPI_UINT64_MAX
end_define

begin_comment
comment|/*******************************************************************************  *  * Commonly used macros  *  ******************************************************************************/
end_comment

begin_comment
comment|/* Data manipulation */
end_comment

begin_define
define|#
directive|define
name|ACPI_LOBYTE
parameter_list|(
name|Integer
parameter_list|)
value|((UINT8)   (UINT16)(Integer))
end_define

begin_define
define|#
directive|define
name|ACPI_HIBYTE
parameter_list|(
name|Integer
parameter_list|)
value|((UINT8) (((UINT16)(Integer))>> 8))
end_define

begin_define
define|#
directive|define
name|ACPI_LOWORD
parameter_list|(
name|Integer
parameter_list|)
value|((UINT16)  (UINT32)(Integer))
end_define

begin_define
define|#
directive|define
name|ACPI_HIWORD
parameter_list|(
name|Integer
parameter_list|)
value|((UINT16)(((UINT32)(Integer))>> 16))
end_define

begin_define
define|#
directive|define
name|ACPI_LODWORD
parameter_list|(
name|Integer64
parameter_list|)
value|((UINT32)  (UINT64)(Integer64))
end_define

begin_define
define|#
directive|define
name|ACPI_HIDWORD
parameter_list|(
name|Integer64
parameter_list|)
value|((UINT32)(((UINT64)(Integer64))>> 32))
end_define

begin_define
define|#
directive|define
name|ACPI_SET_BIT
parameter_list|(
name|target
parameter_list|,
name|bit
parameter_list|)
value|((target) |= (bit))
end_define

begin_define
define|#
directive|define
name|ACPI_CLEAR_BIT
parameter_list|(
name|target
parameter_list|,
name|bit
parameter_list|)
value|((target)&= ~(bit))
end_define

begin_define
define|#
directive|define
name|ACPI_MIN
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|(((a)<(b))?(a):(b))
end_define

begin_define
define|#
directive|define
name|ACPI_MAX
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|(((a)>(b))?(a):(b))
end_define

begin_comment
comment|/* Size calculation */
end_comment

begin_define
define|#
directive|define
name|ACPI_ARRAY_LENGTH
parameter_list|(
name|x
parameter_list|)
value|(sizeof(x) / sizeof((x)[0]))
end_define

begin_comment
comment|/* Pointer manipulation */
end_comment

begin_define
define|#
directive|define
name|ACPI_CAST_PTR
parameter_list|(
name|t
parameter_list|,
name|p
parameter_list|)
value|((t *) (ACPI_UINTPTR_T) (p))
end_define

begin_define
define|#
directive|define
name|ACPI_CAST_INDIRECT_PTR
parameter_list|(
name|t
parameter_list|,
name|p
parameter_list|)
value|((t **) (ACPI_UINTPTR_T) (p))
end_define

begin_define
define|#
directive|define
name|ACPI_ADD_PTR
parameter_list|(
name|t
parameter_list|,
name|a
parameter_list|,
name|b
parameter_list|)
value|ACPI_CAST_PTR (t, (ACPI_CAST_PTR (UINT8, (a)) + (ACPI_SIZE)(b)))
end_define

begin_define
define|#
directive|define
name|ACPI_SUB_PTR
parameter_list|(
name|t
parameter_list|,
name|a
parameter_list|,
name|b
parameter_list|)
value|ACPI_CAST_PTR (t, (ACPI_CAST_PTR (UINT8, (a)) - (ACPI_SIZE)(b)))
end_define

begin_define
define|#
directive|define
name|ACPI_PTR_DIFF
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|(ACPI_SIZE) (ACPI_CAST_PTR (UINT8, (a)) - ACPI_CAST_PTR (UINT8, (b)))
end_define

begin_comment
comment|/* Pointer/Integer type conversions */
end_comment

begin_define
define|#
directive|define
name|ACPI_TO_POINTER
parameter_list|(
name|i
parameter_list|)
value|ACPI_ADD_PTR (void, (void *) NULL,(ACPI_SIZE) i)
end_define

begin_define
define|#
directive|define
name|ACPI_TO_INTEGER
parameter_list|(
name|p
parameter_list|)
value|ACPI_PTR_DIFF (p, (void *) NULL)
end_define

begin_define
define|#
directive|define
name|ACPI_OFFSET
parameter_list|(
name|d
parameter_list|,
name|f
parameter_list|)
value|ACPI_PTR_DIFF (&(((d *) 0)->f), (void *) NULL)
end_define

begin_define
define|#
directive|define
name|ACPI_PHYSADDR_TO_PTR
parameter_list|(
name|i
parameter_list|)
value|ACPI_TO_POINTER(i)
end_define

begin_define
define|#
directive|define
name|ACPI_PTR_TO_PHYSADDR
parameter_list|(
name|i
parameter_list|)
value|ACPI_TO_INTEGER(i)
end_define

begin_comment
comment|/* Optimizations for 4-character (32-bit) ACPI_NAME manipulation */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|ACPI_MISALIGNMENT_NOT_SUPPORTED
end_ifndef

begin_define
define|#
directive|define
name|ACPI_COMPARE_NAME
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|(*ACPI_CAST_PTR (UINT32, (a)) == *ACPI_CAST_PTR (UINT32, (b)))
end_define

begin_define
define|#
directive|define
name|ACPI_MOVE_NAME
parameter_list|(
name|dest
parameter_list|,
name|src
parameter_list|)
value|(*ACPI_CAST_PTR (UINT32, (dest)) = *ACPI_CAST_PTR (UINT32, (src)))
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|ACPI_COMPARE_NAME
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|(!strncmp (ACPI_CAST_PTR (char, (a)), ACPI_CAST_PTR (char, (b)), ACPI_NAME_SIZE))
end_define

begin_define
define|#
directive|define
name|ACPI_MOVE_NAME
parameter_list|(
name|dest
parameter_list|,
name|src
parameter_list|)
value|(strncpy (ACPI_CAST_PTR (char, (dest)), ACPI_CAST_PTR (char, (src)), ACPI_NAME_SIZE))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Support for the special RSDP signature (8 characters) */
end_comment

begin_define
define|#
directive|define
name|ACPI_VALIDATE_RSDP_SIG
parameter_list|(
name|a
parameter_list|)
value|(!strncmp (ACPI_CAST_PTR (char, (a)), ACPI_SIG_RSDP, 8))
end_define

begin_define
define|#
directive|define
name|ACPI_MAKE_RSDP_SIG
parameter_list|(
name|dest
parameter_list|)
value|(memcpy (ACPI_CAST_PTR (char, (dest)), ACPI_SIG_RSDP, 8))
end_define

begin_comment
comment|/*******************************************************************************  *  * Miscellaneous constants  *  ******************************************************************************/
end_comment

begin_comment
comment|/*  * Initialization sequence  */
end_comment

begin_define
define|#
directive|define
name|ACPI_FULL_INITIALIZATION
value|0x00
end_define

begin_define
define|#
directive|define
name|ACPI_NO_ADDRESS_SPACE_INIT
value|0x01
end_define

begin_define
define|#
directive|define
name|ACPI_NO_HARDWARE_INIT
value|0x02
end_define

begin_define
define|#
directive|define
name|ACPI_NO_EVENT_INIT
value|0x04
end_define

begin_define
define|#
directive|define
name|ACPI_NO_HANDLER_INIT
value|0x08
end_define

begin_define
define|#
directive|define
name|ACPI_NO_ACPI_ENABLE
value|0x10
end_define

begin_define
define|#
directive|define
name|ACPI_NO_DEVICE_INIT
value|0x20
end_define

begin_define
define|#
directive|define
name|ACPI_NO_OBJECT_INIT
value|0x40
end_define

begin_define
define|#
directive|define
name|ACPI_NO_FACS_INIT
value|0x80
end_define

begin_comment
comment|/*  * Initialization state  */
end_comment

begin_define
define|#
directive|define
name|ACPI_SUBSYSTEM_INITIALIZE
value|0x01
end_define

begin_define
define|#
directive|define
name|ACPI_INITIALIZED_OK
value|0x02
end_define

begin_comment
comment|/*  * Power state values  */
end_comment

begin_define
define|#
directive|define
name|ACPI_STATE_UNKNOWN
value|(UINT8) 0xFF
end_define

begin_define
define|#
directive|define
name|ACPI_STATE_S0
value|(UINT8) 0
end_define

begin_define
define|#
directive|define
name|ACPI_STATE_S1
value|(UINT8) 1
end_define

begin_define
define|#
directive|define
name|ACPI_STATE_S2
value|(UINT8) 2
end_define

begin_define
define|#
directive|define
name|ACPI_STATE_S3
value|(UINT8) 3
end_define

begin_define
define|#
directive|define
name|ACPI_STATE_S4
value|(UINT8) 4
end_define

begin_define
define|#
directive|define
name|ACPI_STATE_S5
value|(UINT8) 5
end_define

begin_define
define|#
directive|define
name|ACPI_S_STATES_MAX
value|ACPI_STATE_S5
end_define

begin_define
define|#
directive|define
name|ACPI_S_STATE_COUNT
value|6
end_define

begin_define
define|#
directive|define
name|ACPI_STATE_D0
value|(UINT8) 0
end_define

begin_define
define|#
directive|define
name|ACPI_STATE_D1
value|(UINT8) 1
end_define

begin_define
define|#
directive|define
name|ACPI_STATE_D2
value|(UINT8) 2
end_define

begin_define
define|#
directive|define
name|ACPI_STATE_D3
value|(UINT8) 3
end_define

begin_define
define|#
directive|define
name|ACPI_D_STATES_MAX
value|ACPI_STATE_D3
end_define

begin_define
define|#
directive|define
name|ACPI_D_STATE_COUNT
value|4
end_define

begin_define
define|#
directive|define
name|ACPI_STATE_C0
value|(UINT8) 0
end_define

begin_define
define|#
directive|define
name|ACPI_STATE_C1
value|(UINT8) 1
end_define

begin_define
define|#
directive|define
name|ACPI_STATE_C2
value|(UINT8) 2
end_define

begin_define
define|#
directive|define
name|ACPI_STATE_C3
value|(UINT8) 3
end_define

begin_define
define|#
directive|define
name|ACPI_C_STATES_MAX
value|ACPI_STATE_C3
end_define

begin_define
define|#
directive|define
name|ACPI_C_STATE_COUNT
value|4
end_define

begin_comment
comment|/*  * Sleep type invalid value  */
end_comment

begin_define
define|#
directive|define
name|ACPI_SLEEP_TYPE_MAX
value|0x7
end_define

begin_define
define|#
directive|define
name|ACPI_SLEEP_TYPE_INVALID
value|0xFF
end_define

begin_comment
comment|/*  * Standard notify values  */
end_comment

begin_define
define|#
directive|define
name|ACPI_NOTIFY_BUS_CHECK
value|(UINT8) 0x00
end_define

begin_define
define|#
directive|define
name|ACPI_NOTIFY_DEVICE_CHECK
value|(UINT8) 0x01
end_define

begin_define
define|#
directive|define
name|ACPI_NOTIFY_DEVICE_WAKE
value|(UINT8) 0x02
end_define

begin_define
define|#
directive|define
name|ACPI_NOTIFY_EJECT_REQUEST
value|(UINT8) 0x03
end_define

begin_define
define|#
directive|define
name|ACPI_NOTIFY_DEVICE_CHECK_LIGHT
value|(UINT8) 0x04
end_define

begin_define
define|#
directive|define
name|ACPI_NOTIFY_FREQUENCY_MISMATCH
value|(UINT8) 0x05
end_define

begin_define
define|#
directive|define
name|ACPI_NOTIFY_BUS_MODE_MISMATCH
value|(UINT8) 0x06
end_define

begin_define
define|#
directive|define
name|ACPI_NOTIFY_POWER_FAULT
value|(UINT8) 0x07
end_define

begin_define
define|#
directive|define
name|ACPI_NOTIFY_CAPABILITIES_CHECK
value|(UINT8) 0x08
end_define

begin_define
define|#
directive|define
name|ACPI_NOTIFY_DEVICE_PLD_CHECK
value|(UINT8) 0x09
end_define

begin_define
define|#
directive|define
name|ACPI_NOTIFY_RESERVED
value|(UINT8) 0x0A
end_define

begin_define
define|#
directive|define
name|ACPI_NOTIFY_LOCALITY_UPDATE
value|(UINT8) 0x0B
end_define

begin_define
define|#
directive|define
name|ACPI_NOTIFY_SHUTDOWN_REQUEST
value|(UINT8) 0x0C
end_define

begin_define
define|#
directive|define
name|ACPI_NOTIFY_AFFINITY_UPDATE
value|(UINT8) 0x0D
end_define

begin_define
define|#
directive|define
name|ACPI_NOTIFY_MEMORY_UPDATE
value|(UINT8) 0x0E
end_define

begin_define
define|#
directive|define
name|ACPI_GENERIC_NOTIFY_MAX
value|0x0E
end_define

begin_define
define|#
directive|define
name|ACPI_SPECIFIC_NOTIFY_MAX
value|0x84
end_define

begin_comment
comment|/*  * Types associated with ACPI names and objects. The first group of  * values (up to ACPI_TYPE_EXTERNAL_MAX) correspond to the definition  * of the ACPI ObjectType() operator (See the ACPI Spec). Therefore,  * only add to the first group if the spec changes.  *  * NOTE: Types must be kept in sync with the global AcpiNsProperties  * and AcpiNsTypeNames arrays.  */
end_comment

begin_typedef
typedef|typedef
name|UINT32
name|ACPI_OBJECT_TYPE
typedef|;
end_typedef

begin_define
define|#
directive|define
name|ACPI_TYPE_ANY
value|0x00
end_define

begin_define
define|#
directive|define
name|ACPI_TYPE_INTEGER
value|0x01
end_define

begin_comment
comment|/* Byte/Word/Dword/Zero/One/Ones */
end_comment

begin_define
define|#
directive|define
name|ACPI_TYPE_STRING
value|0x02
end_define

begin_define
define|#
directive|define
name|ACPI_TYPE_BUFFER
value|0x03
end_define

begin_define
define|#
directive|define
name|ACPI_TYPE_PACKAGE
value|0x04
end_define

begin_comment
comment|/* ByteConst, multiple DataTerm/Constant/SuperName */
end_comment

begin_define
define|#
directive|define
name|ACPI_TYPE_FIELD_UNIT
value|0x05
end_define

begin_define
define|#
directive|define
name|ACPI_TYPE_DEVICE
value|0x06
end_define

begin_comment
comment|/* Name, multiple Node */
end_comment

begin_define
define|#
directive|define
name|ACPI_TYPE_EVENT
value|0x07
end_define

begin_define
define|#
directive|define
name|ACPI_TYPE_METHOD
value|0x08
end_define

begin_comment
comment|/* Name, ByteConst, multiple Code */
end_comment

begin_define
define|#
directive|define
name|ACPI_TYPE_MUTEX
value|0x09
end_define

begin_define
define|#
directive|define
name|ACPI_TYPE_REGION
value|0x0A
end_define

begin_define
define|#
directive|define
name|ACPI_TYPE_POWER
value|0x0B
end_define

begin_comment
comment|/* Name,ByteConst,WordConst,multi Node */
end_comment

begin_define
define|#
directive|define
name|ACPI_TYPE_PROCESSOR
value|0x0C
end_define

begin_comment
comment|/* Name,ByteConst,DWordConst,ByteConst,multi NmO */
end_comment

begin_define
define|#
directive|define
name|ACPI_TYPE_THERMAL
value|0x0D
end_define

begin_comment
comment|/* Name, multiple Node */
end_comment

begin_define
define|#
directive|define
name|ACPI_TYPE_BUFFER_FIELD
value|0x0E
end_define

begin_define
define|#
directive|define
name|ACPI_TYPE_DDB_HANDLE
value|0x0F
end_define

begin_define
define|#
directive|define
name|ACPI_TYPE_DEBUG_OBJECT
value|0x10
end_define

begin_define
define|#
directive|define
name|ACPI_TYPE_EXTERNAL_MAX
value|0x10
end_define

begin_define
define|#
directive|define
name|ACPI_NUM_TYPES
value|(ACPI_TYPE_EXTERNAL_MAX + 1)
end_define

begin_comment
comment|/*  * These are object types that do not map directly to the ACPI  * ObjectType() operator. They are used for various internal purposes  * only. If new predefined ACPI_TYPEs are added (via the ACPI  * specification), these internal types must move upwards. (There  * is code that depends on these values being contiguous with the  * external types above.)  */
end_comment

begin_define
define|#
directive|define
name|ACPI_TYPE_LOCAL_REGION_FIELD
value|0x11
end_define

begin_define
define|#
directive|define
name|ACPI_TYPE_LOCAL_BANK_FIELD
value|0x12
end_define

begin_define
define|#
directive|define
name|ACPI_TYPE_LOCAL_INDEX_FIELD
value|0x13
end_define

begin_define
define|#
directive|define
name|ACPI_TYPE_LOCAL_REFERENCE
value|0x14
end_define

begin_comment
comment|/* Arg#, Local#, Name, Debug, RefOf, Index */
end_comment

begin_define
define|#
directive|define
name|ACPI_TYPE_LOCAL_ALIAS
value|0x15
end_define

begin_define
define|#
directive|define
name|ACPI_TYPE_LOCAL_METHOD_ALIAS
value|0x16
end_define

begin_define
define|#
directive|define
name|ACPI_TYPE_LOCAL_NOTIFY
value|0x17
end_define

begin_define
define|#
directive|define
name|ACPI_TYPE_LOCAL_ADDRESS_HANDLER
value|0x18
end_define

begin_define
define|#
directive|define
name|ACPI_TYPE_LOCAL_RESOURCE
value|0x19
end_define

begin_define
define|#
directive|define
name|ACPI_TYPE_LOCAL_RESOURCE_FIELD
value|0x1A
end_define

begin_define
define|#
directive|define
name|ACPI_TYPE_LOCAL_SCOPE
value|0x1B
end_define

begin_comment
comment|/* 1 Name, multiple ObjectList Nodes */
end_comment

begin_define
define|#
directive|define
name|ACPI_TYPE_NS_NODE_MAX
value|0x1B
end_define

begin_comment
comment|/* Last typecode used within a NS Node */
end_comment

begin_define
define|#
directive|define
name|ACPI_TOTAL_TYPES
value|(ACPI_TYPE_NS_NODE_MAX + 1)
end_define

begin_comment
comment|/*  * These are special object types that never appear in  * a Namespace node, only in an object of ACPI_OPERAND_OBJECT  */
end_comment

begin_define
define|#
directive|define
name|ACPI_TYPE_LOCAL_EXTRA
value|0x1C
end_define

begin_define
define|#
directive|define
name|ACPI_TYPE_LOCAL_DATA
value|0x1D
end_define

begin_define
define|#
directive|define
name|ACPI_TYPE_LOCAL_MAX
value|0x1D
end_define

begin_comment
comment|/* All types above here are invalid */
end_comment

begin_define
define|#
directive|define
name|ACPI_TYPE_INVALID
value|0x1E
end_define

begin_define
define|#
directive|define
name|ACPI_TYPE_NOT_FOUND
value|0xFF
end_define

begin_define
define|#
directive|define
name|ACPI_NUM_NS_TYPES
value|(ACPI_TYPE_INVALID + 1)
end_define

begin_comment
comment|/*  * All I/O  */
end_comment

begin_define
define|#
directive|define
name|ACPI_READ
value|0
end_define

begin_define
define|#
directive|define
name|ACPI_WRITE
value|1
end_define

begin_define
define|#
directive|define
name|ACPI_IO_MASK
value|1
end_define

begin_comment
comment|/*  * Event Types: Fixed& General Purpose  */
end_comment

begin_typedef
typedef|typedef
name|UINT32
name|ACPI_EVENT_TYPE
typedef|;
end_typedef

begin_comment
comment|/*  * Fixed events  */
end_comment

begin_define
define|#
directive|define
name|ACPI_EVENT_PMTIMER
value|0
end_define

begin_define
define|#
directive|define
name|ACPI_EVENT_GLOBAL
value|1
end_define

begin_define
define|#
directive|define
name|ACPI_EVENT_POWER_BUTTON
value|2
end_define

begin_define
define|#
directive|define
name|ACPI_EVENT_SLEEP_BUTTON
value|3
end_define

begin_define
define|#
directive|define
name|ACPI_EVENT_RTC
value|4
end_define

begin_define
define|#
directive|define
name|ACPI_EVENT_MAX
value|4
end_define

begin_define
define|#
directive|define
name|ACPI_NUM_FIXED_EVENTS
value|ACPI_EVENT_MAX + 1
end_define

begin_comment
comment|/*  * Event Status - Per event  * -------------  * The encoding of ACPI_EVENT_STATUS is illustrated below.  * Note that a set bit (1) indicates the property is TRUE  * (e.g. if bit 0 is set then the event is enabled).  * +-------------+-+-+-+-+-+-+  * |   Bits 31:6 |5|4|3|2|1|0|  * +-------------+-+-+-+-+-+-+  *          |     | | | | | |  *          |     | | | | | +- Enabled?  *          |     | | | | +--- Enabled for wake?  *          |     | | | +----- Status bit set?  *          |     | | +------- Enable bit set?  *          |     | +--------- Has a handler?  *          |     +----------- Masked?  *          +-----------------<Reserved>  */
end_comment

begin_typedef
typedef|typedef
name|UINT32
name|ACPI_EVENT_STATUS
typedef|;
end_typedef

begin_define
define|#
directive|define
name|ACPI_EVENT_FLAG_DISABLED
value|(ACPI_EVENT_STATUS) 0x00
end_define

begin_define
define|#
directive|define
name|ACPI_EVENT_FLAG_ENABLED
value|(ACPI_EVENT_STATUS) 0x01
end_define

begin_define
define|#
directive|define
name|ACPI_EVENT_FLAG_WAKE_ENABLED
value|(ACPI_EVENT_STATUS) 0x02
end_define

begin_define
define|#
directive|define
name|ACPI_EVENT_FLAG_STATUS_SET
value|(ACPI_EVENT_STATUS) 0x04
end_define

begin_define
define|#
directive|define
name|ACPI_EVENT_FLAG_ENABLE_SET
value|(ACPI_EVENT_STATUS) 0x08
end_define

begin_define
define|#
directive|define
name|ACPI_EVENT_FLAG_HAS_HANDLER
value|(ACPI_EVENT_STATUS) 0x10
end_define

begin_define
define|#
directive|define
name|ACPI_EVENT_FLAG_MASKED
value|(ACPI_EVENT_STATUS) 0x20
end_define

begin_define
define|#
directive|define
name|ACPI_EVENT_FLAG_SET
value|ACPI_EVENT_FLAG_STATUS_SET
end_define

begin_comment
comment|/* Actions for AcpiSetGpe, AcpiGpeWakeup, AcpiHwLowSetGpe */
end_comment

begin_define
define|#
directive|define
name|ACPI_GPE_ENABLE
value|0
end_define

begin_define
define|#
directive|define
name|ACPI_GPE_DISABLE
value|1
end_define

begin_define
define|#
directive|define
name|ACPI_GPE_CONDITIONAL_ENABLE
value|2
end_define

begin_comment
comment|/*  * GPE info flags - Per GPE  * +---+-+-+-+---+  * |7:6|5|4|3|2:0|  * +---+-+-+-+---+  *   |  | | |  |  *   |  | | |  +-- Type of dispatch:to method, handler, notify, or none  *   |  | | +----- Interrupt type: edge or level triggered  *   |  | +------- Is a Wake GPE  *   |  +--------- Is GPE masked by the software GPE masking mechanism  *   +------------<Reserved>  */
end_comment

begin_define
define|#
directive|define
name|ACPI_GPE_DISPATCH_NONE
value|(UINT8) 0x00
end_define

begin_define
define|#
directive|define
name|ACPI_GPE_DISPATCH_METHOD
value|(UINT8) 0x01
end_define

begin_define
define|#
directive|define
name|ACPI_GPE_DISPATCH_HANDLER
value|(UINT8) 0x02
end_define

begin_define
define|#
directive|define
name|ACPI_GPE_DISPATCH_NOTIFY
value|(UINT8) 0x03
end_define

begin_define
define|#
directive|define
name|ACPI_GPE_DISPATCH_RAW_HANDLER
value|(UINT8) 0x04
end_define

begin_define
define|#
directive|define
name|ACPI_GPE_DISPATCH_MASK
value|(UINT8) 0x07
end_define

begin_define
define|#
directive|define
name|ACPI_GPE_DISPATCH_TYPE
parameter_list|(
name|flags
parameter_list|)
value|((UINT8) ((flags)& ACPI_GPE_DISPATCH_MASK))
end_define

begin_define
define|#
directive|define
name|ACPI_GPE_LEVEL_TRIGGERED
value|(UINT8) 0x08
end_define

begin_define
define|#
directive|define
name|ACPI_GPE_EDGE_TRIGGERED
value|(UINT8) 0x00
end_define

begin_define
define|#
directive|define
name|ACPI_GPE_XRUPT_TYPE_MASK
value|(UINT8) 0x08
end_define

begin_define
define|#
directive|define
name|ACPI_GPE_CAN_WAKE
value|(UINT8) 0x10
end_define

begin_comment
comment|/*  * Flags for GPE and Lock interfaces  */
end_comment

begin_define
define|#
directive|define
name|ACPI_NOT_ISR
value|0x1
end_define

begin_define
define|#
directive|define
name|ACPI_ISR
value|0x0
end_define

begin_comment
comment|/* Notify types */
end_comment

begin_define
define|#
directive|define
name|ACPI_SYSTEM_NOTIFY
value|0x1
end_define

begin_define
define|#
directive|define
name|ACPI_DEVICE_NOTIFY
value|0x2
end_define

begin_define
define|#
directive|define
name|ACPI_ALL_NOTIFY
value|(ACPI_SYSTEM_NOTIFY | ACPI_DEVICE_NOTIFY)
end_define

begin_define
define|#
directive|define
name|ACPI_MAX_NOTIFY_HANDLER_TYPE
value|0x3
end_define

begin_define
define|#
directive|define
name|ACPI_NUM_NOTIFY_TYPES
value|2
end_define

begin_define
define|#
directive|define
name|ACPI_MAX_SYS_NOTIFY
value|0x7F
end_define

begin_define
define|#
directive|define
name|ACPI_MAX_DEVICE_SPECIFIC_NOTIFY
value|0xBF
end_define

begin_define
define|#
directive|define
name|ACPI_SYSTEM_HANDLER_LIST
value|0
end_define

begin_comment
comment|/* Used as index, must be SYSTEM_NOTIFY -1 */
end_comment

begin_define
define|#
directive|define
name|ACPI_DEVICE_HANDLER_LIST
value|1
end_define

begin_comment
comment|/* Used as index, must be DEVICE_NOTIFY -1 */
end_comment

begin_comment
comment|/* Address Space (Operation Region) Types */
end_comment

begin_typedef
typedef|typedef
name|UINT8
name|ACPI_ADR_SPACE_TYPE
typedef|;
end_typedef

begin_define
define|#
directive|define
name|ACPI_ADR_SPACE_SYSTEM_MEMORY
value|(ACPI_ADR_SPACE_TYPE) 0
end_define

begin_define
define|#
directive|define
name|ACPI_ADR_SPACE_SYSTEM_IO
value|(ACPI_ADR_SPACE_TYPE) 1
end_define

begin_define
define|#
directive|define
name|ACPI_ADR_SPACE_PCI_CONFIG
value|(ACPI_ADR_SPACE_TYPE) 2
end_define

begin_define
define|#
directive|define
name|ACPI_ADR_SPACE_EC
value|(ACPI_ADR_SPACE_TYPE) 3
end_define

begin_define
define|#
directive|define
name|ACPI_ADR_SPACE_SMBUS
value|(ACPI_ADR_SPACE_TYPE) 4
end_define

begin_define
define|#
directive|define
name|ACPI_ADR_SPACE_CMOS
value|(ACPI_ADR_SPACE_TYPE) 5
end_define

begin_define
define|#
directive|define
name|ACPI_ADR_SPACE_PCI_BAR_TARGET
value|(ACPI_ADR_SPACE_TYPE) 6
end_define

begin_define
define|#
directive|define
name|ACPI_ADR_SPACE_IPMI
value|(ACPI_ADR_SPACE_TYPE) 7
end_define

begin_define
define|#
directive|define
name|ACPI_ADR_SPACE_GPIO
value|(ACPI_ADR_SPACE_TYPE) 8
end_define

begin_define
define|#
directive|define
name|ACPI_ADR_SPACE_GSBUS
value|(ACPI_ADR_SPACE_TYPE) 9
end_define

begin_define
define|#
directive|define
name|ACPI_ADR_SPACE_PLATFORM_COMM
value|(ACPI_ADR_SPACE_TYPE) 10
end_define

begin_define
define|#
directive|define
name|ACPI_NUM_PREDEFINED_REGIONS
value|11
end_define

begin_comment
comment|/*  * Special Address Spaces  *  * Note: A Data Table region is a special type of operation region  * that has its own AML opcode. However, internally, the AML  * interpreter simply creates an operation region with an an address  * space type of ACPI_ADR_SPACE_DATA_TABLE.  */
end_comment

begin_define
define|#
directive|define
name|ACPI_ADR_SPACE_DATA_TABLE
value|(ACPI_ADR_SPACE_TYPE) 0x7E
end_define

begin_comment
comment|/* Internal to ACPICA only */
end_comment

begin_define
define|#
directive|define
name|ACPI_ADR_SPACE_FIXED_HARDWARE
value|(ACPI_ADR_SPACE_TYPE) 0x7F
end_define

begin_comment
comment|/* Values for _REG connection code */
end_comment

begin_define
define|#
directive|define
name|ACPI_REG_DISCONNECT
value|0
end_define

begin_define
define|#
directive|define
name|ACPI_REG_CONNECT
value|1
end_define

begin_comment
comment|/*  * BitRegister IDs  *  * These values are intended to be used by the hardware interfaces  * and are mapped to individual bitfields defined within the ACPI  * registers. See the AcpiGbl_BitRegisterInfo global table in utglobal.c  * for this mapping.  */
end_comment

begin_comment
comment|/* PM1 Status register */
end_comment

begin_define
define|#
directive|define
name|ACPI_BITREG_TIMER_STATUS
value|0x00
end_define

begin_define
define|#
directive|define
name|ACPI_BITREG_BUS_MASTER_STATUS
value|0x01
end_define

begin_define
define|#
directive|define
name|ACPI_BITREG_GLOBAL_LOCK_STATUS
value|0x02
end_define

begin_define
define|#
directive|define
name|ACPI_BITREG_POWER_BUTTON_STATUS
value|0x03
end_define

begin_define
define|#
directive|define
name|ACPI_BITREG_SLEEP_BUTTON_STATUS
value|0x04
end_define

begin_define
define|#
directive|define
name|ACPI_BITREG_RT_CLOCK_STATUS
value|0x05
end_define

begin_define
define|#
directive|define
name|ACPI_BITREG_WAKE_STATUS
value|0x06
end_define

begin_define
define|#
directive|define
name|ACPI_BITREG_PCIEXP_WAKE_STATUS
value|0x07
end_define

begin_comment
comment|/* PM1 Enable register */
end_comment

begin_define
define|#
directive|define
name|ACPI_BITREG_TIMER_ENABLE
value|0x08
end_define

begin_define
define|#
directive|define
name|ACPI_BITREG_GLOBAL_LOCK_ENABLE
value|0x09
end_define

begin_define
define|#
directive|define
name|ACPI_BITREG_POWER_BUTTON_ENABLE
value|0x0A
end_define

begin_define
define|#
directive|define
name|ACPI_BITREG_SLEEP_BUTTON_ENABLE
value|0x0B
end_define

begin_define
define|#
directive|define
name|ACPI_BITREG_RT_CLOCK_ENABLE
value|0x0C
end_define

begin_define
define|#
directive|define
name|ACPI_BITREG_PCIEXP_WAKE_DISABLE
value|0x0D
end_define

begin_comment
comment|/* PM1 Control register */
end_comment

begin_define
define|#
directive|define
name|ACPI_BITREG_SCI_ENABLE
value|0x0E
end_define

begin_define
define|#
directive|define
name|ACPI_BITREG_BUS_MASTER_RLD
value|0x0F
end_define

begin_define
define|#
directive|define
name|ACPI_BITREG_GLOBAL_LOCK_RELEASE
value|0x10
end_define

begin_define
define|#
directive|define
name|ACPI_BITREG_SLEEP_TYPE
value|0x11
end_define

begin_define
define|#
directive|define
name|ACPI_BITREG_SLEEP_ENABLE
value|0x12
end_define

begin_comment
comment|/* PM2 Control register */
end_comment

begin_define
define|#
directive|define
name|ACPI_BITREG_ARB_DISABLE
value|0x13
end_define

begin_define
define|#
directive|define
name|ACPI_BITREG_MAX
value|0x13
end_define

begin_define
define|#
directive|define
name|ACPI_NUM_BITREG
value|ACPI_BITREG_MAX + 1
end_define

begin_comment
comment|/* Status register values. A 1 clears a status bit. 0 = no effect */
end_comment

begin_define
define|#
directive|define
name|ACPI_CLEAR_STATUS
value|1
end_define

begin_comment
comment|/* Enable and Control register values */
end_comment

begin_define
define|#
directive|define
name|ACPI_ENABLE_EVENT
value|1
end_define

begin_define
define|#
directive|define
name|ACPI_DISABLE_EVENT
value|0
end_define

begin_comment
comment|/* Sleep function dispatch */
end_comment

begin_typedef
typedef|typedef
name|ACPI_STATUS
function_decl|(
modifier|*
name|ACPI_SLEEP_FUNCTION
function_decl|)
parameter_list|(
name|UINT8
name|SleepState
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|acpi_sleep_functions
block|{
name|ACPI_SLEEP_FUNCTION
name|LegacyFunction
decl_stmt|;
name|ACPI_SLEEP_FUNCTION
name|ExtendedFunction
decl_stmt|;
block|}
name|ACPI_SLEEP_FUNCTIONS
typedef|;
end_typedef

begin_comment
comment|/*  * External ACPI object definition  */
end_comment

begin_comment
comment|/*  * Note: Type == ACPI_TYPE_ANY (0) is used to indicate a NULL package  * element or an unresolved named reference.  */
end_comment

begin_typedef
typedef|typedef
union|union
name|acpi_object
block|{
name|ACPI_OBJECT_TYPE
name|Type
decl_stmt|;
comment|/* See definition of AcpiNsType for values */
struct|struct
block|{
name|ACPI_OBJECT_TYPE
name|Type
decl_stmt|;
comment|/* ACPI_TYPE_INTEGER */
name|UINT64
name|Value
decl_stmt|;
comment|/* The actual number */
block|}
name|Integer
struct|;
struct|struct
block|{
name|ACPI_OBJECT_TYPE
name|Type
decl_stmt|;
comment|/* ACPI_TYPE_STRING */
name|UINT32
name|Length
decl_stmt|;
comment|/* # of bytes in string, excluding trailing null */
name|char
modifier|*
name|Pointer
decl_stmt|;
comment|/* points to the string value */
block|}
name|String
struct|;
struct|struct
block|{
name|ACPI_OBJECT_TYPE
name|Type
decl_stmt|;
comment|/* ACPI_TYPE_BUFFER */
name|UINT32
name|Length
decl_stmt|;
comment|/* # of bytes in buffer */
name|UINT8
modifier|*
name|Pointer
decl_stmt|;
comment|/* points to the buffer */
block|}
name|Buffer
struct|;
struct|struct
block|{
name|ACPI_OBJECT_TYPE
name|Type
decl_stmt|;
comment|/* ACPI_TYPE_PACKAGE */
name|UINT32
name|Count
decl_stmt|;
comment|/* # of elements in package */
name|union
name|acpi_object
modifier|*
name|Elements
decl_stmt|;
comment|/* Pointer to an array of ACPI_OBJECTs */
block|}
name|Package
struct|;
struct|struct
block|{
name|ACPI_OBJECT_TYPE
name|Type
decl_stmt|;
comment|/* ACPI_TYPE_LOCAL_REFERENCE */
name|ACPI_OBJECT_TYPE
name|ActualType
decl_stmt|;
comment|/* Type associated with the Handle */
name|ACPI_HANDLE
name|Handle
decl_stmt|;
comment|/* object reference */
block|}
name|Reference
struct|;
struct|struct
block|{
name|ACPI_OBJECT_TYPE
name|Type
decl_stmt|;
comment|/* ACPI_TYPE_PROCESSOR */
name|UINT32
name|ProcId
decl_stmt|;
name|ACPI_IO_ADDRESS
name|PblkAddress
decl_stmt|;
name|UINT32
name|PblkLength
decl_stmt|;
block|}
name|Processor
struct|;
struct|struct
block|{
name|ACPI_OBJECT_TYPE
name|Type
decl_stmt|;
comment|/* ACPI_TYPE_POWER */
name|UINT32
name|SystemLevel
decl_stmt|;
name|UINT32
name|ResourceOrder
decl_stmt|;
block|}
name|PowerResource
struct|;
block|}
name|ACPI_OBJECT
typedef|;
end_typedef

begin_comment
comment|/*  * List of objects, used as a parameter list for control method evaluation  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|acpi_object_list
block|{
name|UINT32
name|Count
decl_stmt|;
name|ACPI_OBJECT
modifier|*
name|Pointer
decl_stmt|;
block|}
name|ACPI_OBJECT_LIST
typedef|;
end_typedef

begin_comment
comment|/*  * Miscellaneous common Data Structures used by the interfaces  */
end_comment

begin_define
define|#
directive|define
name|ACPI_NO_BUFFER
value|0
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|ACPI_NO_MEM_ALLOCATIONS
end_ifdef

begin_define
define|#
directive|define
name|ACPI_ALLOCATE_BUFFER
value|(ACPI_SIZE) (0)
end_define

begin_define
define|#
directive|define
name|ACPI_ALLOCATE_LOCAL_BUFFER
value|(ACPI_SIZE) (0)
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* ACPI_NO_MEM_ALLOCATIONS */
end_comment

begin_define
define|#
directive|define
name|ACPI_ALLOCATE_BUFFER
value|(ACPI_SIZE) (-1)
end_define

begin_comment
comment|/* Let ACPICA allocate buffer */
end_comment

begin_define
define|#
directive|define
name|ACPI_ALLOCATE_LOCAL_BUFFER
value|(ACPI_SIZE) (-2)
end_define

begin_comment
comment|/* For internal use only (enables tracking) */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ACPI_NO_MEM_ALLOCATIONS */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|acpi_buffer
block|{
name|ACPI_SIZE
name|Length
decl_stmt|;
comment|/* Length in bytes of the buffer */
name|void
modifier|*
name|Pointer
decl_stmt|;
comment|/* pointer to buffer */
block|}
name|ACPI_BUFFER
typedef|;
end_typedef

begin_comment
comment|/*  * NameType for AcpiGetName  */
end_comment

begin_define
define|#
directive|define
name|ACPI_FULL_PATHNAME
value|0
end_define

begin_define
define|#
directive|define
name|ACPI_SINGLE_NAME
value|1
end_define

begin_define
define|#
directive|define
name|ACPI_FULL_PATHNAME_NO_TRAILING
value|2
end_define

begin_define
define|#
directive|define
name|ACPI_NAME_TYPE_MAX
value|2
end_define

begin_comment
comment|/*  * Predefined Namespace items  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|acpi_predefined_names
block|{
specifier|const
name|char
modifier|*
name|Name
decl_stmt|;
name|UINT8
name|Type
decl_stmt|;
name|char
modifier|*
name|Val
decl_stmt|;
block|}
name|ACPI_PREDEFINED_NAMES
typedef|;
end_typedef

begin_comment
comment|/*  * Structure and flags for AcpiGetSystemInfo  */
end_comment

begin_define
define|#
directive|define
name|ACPI_SYS_MODE_UNKNOWN
value|0x0000
end_define

begin_define
define|#
directive|define
name|ACPI_SYS_MODE_ACPI
value|0x0001
end_define

begin_define
define|#
directive|define
name|ACPI_SYS_MODE_LEGACY
value|0x0002
end_define

begin_define
define|#
directive|define
name|ACPI_SYS_MODES_MASK
value|0x0003
end_define

begin_comment
comment|/*  * System info returned by AcpiGetSystemInfo()  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|acpi_system_info
block|{
name|UINT32
name|AcpiCaVersion
decl_stmt|;
name|UINT32
name|Flags
decl_stmt|;
name|UINT32
name|TimerResolution
decl_stmt|;
name|UINT32
name|Reserved1
decl_stmt|;
name|UINT32
name|Reserved2
decl_stmt|;
name|UINT32
name|DebugLevel
decl_stmt|;
name|UINT32
name|DebugLayer
decl_stmt|;
block|}
name|ACPI_SYSTEM_INFO
typedef|;
end_typedef

begin_comment
comment|/*  * System statistics returned by AcpiGetStatistics()  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|acpi_statistics
block|{
name|UINT32
name|SciCount
decl_stmt|;
name|UINT32
name|GpeCount
decl_stmt|;
name|UINT32
name|FixedEventCount
index|[
name|ACPI_NUM_FIXED_EVENTS
index|]
decl_stmt|;
name|UINT32
name|MethodCount
decl_stmt|;
block|}
name|ACPI_STATISTICS
typedef|;
end_typedef

begin_comment
comment|/*  * Types specific to the OS service interfaces  */
end_comment

begin_typedef
typedef|typedef
name|UINT32
function_decl|(
name|ACPI_SYSTEM_XFACE
modifier|*
name|ACPI_OSD_HANDLER
function_decl|)
parameter_list|(
name|void
modifier|*
name|Context
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|void
function_decl|(
name|ACPI_SYSTEM_XFACE
modifier|*
name|ACPI_OSD_EXEC_CALLBACK
function_decl|)
parameter_list|(
name|void
modifier|*
name|Context
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/*  * Various handlers and callback procedures  */
end_comment

begin_typedef
typedef|typedef
name|UINT32
function_decl|(
modifier|*
name|ACPI_SCI_HANDLER
function_decl|)
parameter_list|(
name|void
modifier|*
name|Context
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|ACPI_GBL_EVENT_HANDLER
function_decl|)
parameter_list|(
name|UINT32
name|EventType
parameter_list|,
name|ACPI_HANDLE
name|Device
parameter_list|,
name|UINT32
name|EventNumber
parameter_list|,
name|void
modifier|*
name|Context
parameter_list|)
function_decl|;
end_typedef

begin_define
define|#
directive|define
name|ACPI_EVENT_TYPE_GPE
value|0
end_define

begin_define
define|#
directive|define
name|ACPI_EVENT_TYPE_FIXED
value|1
end_define

begin_typedef
typedef|typedef
name|UINT32
function_decl|(
modifier|*
name|ACPI_EVENT_HANDLER
function_decl|)
parameter_list|(
name|void
modifier|*
name|Context
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|UINT32
function_decl|(
modifier|*
name|ACPI_GPE_HANDLER
function_decl|)
parameter_list|(
name|ACPI_HANDLE
name|GpeDevice
parameter_list|,
name|UINT32
name|GpeNumber
parameter_list|,
name|void
modifier|*
name|Context
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|ACPI_NOTIFY_HANDLER
function_decl|)
parameter_list|(
name|ACPI_HANDLE
name|Device
parameter_list|,
name|UINT32
name|Value
parameter_list|,
name|void
modifier|*
name|Context
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|ACPI_OBJECT_HANDLER
function_decl|)
parameter_list|(
name|ACPI_HANDLE
name|Object
parameter_list|,
name|void
modifier|*
name|Data
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|ACPI_STATUS
function_decl|(
modifier|*
name|ACPI_INIT_HANDLER
function_decl|)
parameter_list|(
name|ACPI_HANDLE
name|Object
parameter_list|,
name|UINT32
name|Function
parameter_list|)
function_decl|;
end_typedef

begin_define
define|#
directive|define
name|ACPI_INIT_DEVICE_INI
value|1
end_define

begin_typedef
typedef|typedef
name|ACPI_STATUS
function_decl|(
modifier|*
name|ACPI_EXCEPTION_HANDLER
function_decl|)
parameter_list|(
name|ACPI_STATUS
name|AmlStatus
parameter_list|,
name|ACPI_NAME
name|Name
parameter_list|,
name|UINT16
name|Opcode
parameter_list|,
name|UINT32
name|AmlOffset
parameter_list|,
name|void
modifier|*
name|Context
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/* Table Event handler (Load, LoadTable, etc.) and types */
end_comment

begin_typedef
typedef|typedef
name|ACPI_STATUS
function_decl|(
modifier|*
name|ACPI_TABLE_HANDLER
function_decl|)
parameter_list|(
name|UINT32
name|Event
parameter_list|,
name|void
modifier|*
name|Table
parameter_list|,
name|void
modifier|*
name|Context
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/* Table Event Types */
end_comment

begin_define
define|#
directive|define
name|ACPI_TABLE_EVENT_LOAD
value|0x0
end_define

begin_define
define|#
directive|define
name|ACPI_TABLE_EVENT_UNLOAD
value|0x1
end_define

begin_define
define|#
directive|define
name|ACPI_TABLE_EVENT_INSTALL
value|0x2
end_define

begin_define
define|#
directive|define
name|ACPI_TABLE_EVENT_UNINSTALL
value|0x3
end_define

begin_define
define|#
directive|define
name|ACPI_NUM_TABLE_EVENTS
value|4
end_define

begin_comment
comment|/* Address Spaces (For Operation Regions) */
end_comment

begin_typedef
typedef|typedef
name|ACPI_STATUS
function_decl|(
modifier|*
name|ACPI_ADR_SPACE_HANDLER
function_decl|)
parameter_list|(
name|UINT32
name|Function
parameter_list|,
name|ACPI_PHYSICAL_ADDRESS
name|Address
parameter_list|,
name|UINT32
name|BitWidth
parameter_list|,
name|UINT64
modifier|*
name|Value
parameter_list|,
name|void
modifier|*
name|HandlerContext
parameter_list|,
name|void
modifier|*
name|RegionContext
parameter_list|)
function_decl|;
end_typedef

begin_define
define|#
directive|define
name|ACPI_DEFAULT_HANDLER
value|NULL
end_define

begin_comment
comment|/* Special Context data for GenericSerialBus/GeneralPurposeIo (ACPI 5.0) */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|acpi_connection_info
block|{
name|UINT8
modifier|*
name|Connection
decl_stmt|;
name|UINT16
name|Length
decl_stmt|;
name|UINT8
name|AccessLength
decl_stmt|;
block|}
name|ACPI_CONNECTION_INFO
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|ACPI_STATUS
function_decl|(
modifier|*
name|ACPI_ADR_SPACE_SETUP
function_decl|)
parameter_list|(
name|ACPI_HANDLE
name|RegionHandle
parameter_list|,
name|UINT32
name|Function
parameter_list|,
name|void
modifier|*
name|HandlerContext
parameter_list|,
name|void
modifier|*
modifier|*
name|RegionContext
parameter_list|)
function_decl|;
end_typedef

begin_define
define|#
directive|define
name|ACPI_REGION_ACTIVATE
value|0
end_define

begin_define
define|#
directive|define
name|ACPI_REGION_DEACTIVATE
value|1
end_define

begin_typedef
typedef|typedef
name|ACPI_STATUS
function_decl|(
modifier|*
name|ACPI_WALK_CALLBACK
function_decl|)
parameter_list|(
name|ACPI_HANDLE
name|Object
parameter_list|,
name|UINT32
name|NestingLevel
parameter_list|,
name|void
modifier|*
name|Context
parameter_list|,
name|void
modifier|*
modifier|*
name|ReturnValue
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|UINT32
function_decl|(
modifier|*
name|ACPI_INTERFACE_HANDLER
function_decl|)
parameter_list|(
name|ACPI_STRING
name|InterfaceName
parameter_list|,
name|UINT32
name|Supported
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/* Interrupt handler return values */
end_comment

begin_define
define|#
directive|define
name|ACPI_INTERRUPT_NOT_HANDLED
value|0x00
end_define

begin_define
define|#
directive|define
name|ACPI_INTERRUPT_HANDLED
value|0x01
end_define

begin_comment
comment|/* GPE handler return values */
end_comment

begin_define
define|#
directive|define
name|ACPI_REENABLE_GPE
value|0x80
end_define

begin_comment
comment|/* Length of 32-bit EISAID values when converted back to a string */
end_comment

begin_define
define|#
directive|define
name|ACPI_EISAID_STRING_SIZE
value|8
end_define

begin_comment
comment|/* Includes null terminator */
end_comment

begin_comment
comment|/* Length of UUID (string) values */
end_comment

begin_define
define|#
directive|define
name|ACPI_UUID_LENGTH
value|16
end_define

begin_comment
comment|/* Length of 3-byte PCI class code values when converted back to a string */
end_comment

begin_define
define|#
directive|define
name|ACPI_PCICLS_STRING_SIZE
value|7
end_define

begin_comment
comment|/* Includes null terminator */
end_comment

begin_comment
comment|/* Structures used for device/processor HID, UID, CID */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|acpi_pnp_device_id
block|{
name|UINT32
name|Length
decl_stmt|;
comment|/* Length of string + null */
name|char
modifier|*
name|String
decl_stmt|;
block|}
name|ACPI_PNP_DEVICE_ID
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|acpi_pnp_device_id_list
block|{
name|UINT32
name|Count
decl_stmt|;
comment|/* Number of IDs in Ids array */
name|UINT32
name|ListSize
decl_stmt|;
comment|/* Size of list, including ID strings */
name|ACPI_PNP_DEVICE_ID
name|Ids
index|[
literal|1
index|]
decl_stmt|;
comment|/* ID array */
block|}
name|ACPI_PNP_DEVICE_ID_LIST
typedef|;
end_typedef

begin_comment
comment|/*  * Structure returned from AcpiGetObjectInfo.  * Optimized for both 32-bit and 64-bit builds.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|acpi_device_info
block|{
name|UINT32
name|InfoSize
decl_stmt|;
comment|/* Size of info, including ID strings */
name|UINT32
name|Name
decl_stmt|;
comment|/* ACPI object Name */
name|ACPI_OBJECT_TYPE
name|Type
decl_stmt|;
comment|/* ACPI object Type */
name|UINT8
name|ParamCount
decl_stmt|;
comment|/* If a method, required parameter count */
name|UINT16
name|Valid
decl_stmt|;
comment|/* Indicates which optional fields are valid */
name|UINT8
name|Flags
decl_stmt|;
comment|/* Miscellaneous info */
name|UINT8
name|HighestDstates
index|[
literal|4
index|]
decl_stmt|;
comment|/* _SxD values: 0xFF indicates not valid */
name|UINT8
name|LowestDstates
index|[
literal|5
index|]
decl_stmt|;
comment|/* _SxW values: 0xFF indicates not valid */
name|UINT32
name|CurrentStatus
decl_stmt|;
comment|/* _STA value */
name|UINT64
name|Address
decl_stmt|;
comment|/* _ADR value */
name|ACPI_PNP_DEVICE_ID
name|HardwareId
decl_stmt|;
comment|/* _HID value */
name|ACPI_PNP_DEVICE_ID
name|UniqueId
decl_stmt|;
comment|/* _UID value */
name|ACPI_PNP_DEVICE_ID
name|ClassCode
decl_stmt|;
comment|/* _CLS value */
name|ACPI_PNP_DEVICE_ID_LIST
name|CompatibleIdList
decl_stmt|;
comment|/* _CID list<must be last> */
block|}
name|ACPI_DEVICE_INFO
typedef|;
end_typedef

begin_comment
comment|/* Values for Flags field above (AcpiGetObjectInfo) */
end_comment

begin_define
define|#
directive|define
name|ACPI_PCI_ROOT_BRIDGE
value|0x01
end_define

begin_comment
comment|/* Flags for Valid field above (AcpiGetObjectInfo) */
end_comment

begin_define
define|#
directive|define
name|ACPI_VALID_STA
value|0x0001
end_define

begin_define
define|#
directive|define
name|ACPI_VALID_ADR
value|0x0002
end_define

begin_define
define|#
directive|define
name|ACPI_VALID_HID
value|0x0004
end_define

begin_define
define|#
directive|define
name|ACPI_VALID_UID
value|0x0008
end_define

begin_define
define|#
directive|define
name|ACPI_VALID_CID
value|0x0020
end_define

begin_define
define|#
directive|define
name|ACPI_VALID_CLS
value|0x0040
end_define

begin_define
define|#
directive|define
name|ACPI_VALID_SXDS
value|0x0100
end_define

begin_define
define|#
directive|define
name|ACPI_VALID_SXWS
value|0x0200
end_define

begin_comment
comment|/* Flags for _STA method */
end_comment

begin_define
define|#
directive|define
name|ACPI_STA_DEVICE_PRESENT
value|0x01
end_define

begin_define
define|#
directive|define
name|ACPI_STA_DEVICE_ENABLED
value|0x02
end_define

begin_define
define|#
directive|define
name|ACPI_STA_DEVICE_UI
value|0x04
end_define

begin_define
define|#
directive|define
name|ACPI_STA_DEVICE_FUNCTIONING
value|0x08
end_define

begin_define
define|#
directive|define
name|ACPI_STA_DEVICE_OK
value|0x08
end_define

begin_comment
comment|/* Synonym */
end_comment

begin_define
define|#
directive|define
name|ACPI_STA_BATTERY_PRESENT
value|0x10
end_define

begin_comment
comment|/* Context structs for address space handlers */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|acpi_pci_id
block|{
name|UINT16
name|Segment
decl_stmt|;
name|UINT16
name|Bus
decl_stmt|;
name|UINT16
name|Device
decl_stmt|;
name|UINT16
name|Function
decl_stmt|;
block|}
name|ACPI_PCI_ID
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|acpi_mem_space_context
block|{
name|UINT32
name|Length
decl_stmt|;
name|ACPI_PHYSICAL_ADDRESS
name|Address
decl_stmt|;
name|ACPI_PHYSICAL_ADDRESS
name|MappedPhysicalAddress
decl_stmt|;
name|UINT8
modifier|*
name|MappedLogicalAddress
decl_stmt|;
name|ACPI_SIZE
name|MappedLength
decl_stmt|;
block|}
name|ACPI_MEM_SPACE_CONTEXT
typedef|;
end_typedef

begin_comment
comment|/*  * ACPI_MEMORY_LIST is used only if the ACPICA local cache is enabled  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|acpi_memory_list
block|{
specifier|const
name|char
modifier|*
name|ListName
decl_stmt|;
name|void
modifier|*
name|ListHead
decl_stmt|;
name|UINT16
name|ObjectSize
decl_stmt|;
name|UINT16
name|MaxDepth
decl_stmt|;
name|UINT16
name|CurrentDepth
decl_stmt|;
ifdef|#
directive|ifdef
name|ACPI_DBG_TRACK_ALLOCATIONS
comment|/* Statistics for debug memory tracking only */
name|UINT32
name|TotalAllocated
decl_stmt|;
name|UINT32
name|TotalFreed
decl_stmt|;
name|UINT32
name|MaxOccupied
decl_stmt|;
name|UINT32
name|TotalSize
decl_stmt|;
name|UINT32
name|CurrentTotalSize
decl_stmt|;
name|UINT32
name|Requests
decl_stmt|;
name|UINT32
name|Hits
decl_stmt|;
endif|#
directive|endif
block|}
name|ACPI_MEMORY_LIST
typedef|;
end_typedef

begin_comment
comment|/* Definitions of trace event types */
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|ACPI_TRACE_AML_METHOD
block|,
name|ACPI_TRACE_AML_OPCODE
block|,
name|ACPI_TRACE_AML_REGION
block|}
name|ACPI_TRACE_EVENT_TYPE
typedef|;
end_typedef

begin_comment
comment|/* Definitions of _OSI support */
end_comment

begin_define
define|#
directive|define
name|ACPI_VENDOR_STRINGS
value|0x01
end_define

begin_define
define|#
directive|define
name|ACPI_FEATURE_STRINGS
value|0x02
end_define

begin_define
define|#
directive|define
name|ACPI_ENABLE_INTERFACES
value|0x00
end_define

begin_define
define|#
directive|define
name|ACPI_DISABLE_INTERFACES
value|0x04
end_define

begin_define
define|#
directive|define
name|ACPI_DISABLE_ALL_VENDOR_STRINGS
value|(ACPI_DISABLE_INTERFACES | ACPI_VENDOR_STRINGS)
end_define

begin_define
define|#
directive|define
name|ACPI_DISABLE_ALL_FEATURE_STRINGS
value|(ACPI_DISABLE_INTERFACES | ACPI_FEATURE_STRINGS)
end_define

begin_define
define|#
directive|define
name|ACPI_DISABLE_ALL_STRINGS
value|(ACPI_DISABLE_INTERFACES | ACPI_VENDOR_STRINGS | ACPI_FEATURE_STRINGS)
end_define

begin_define
define|#
directive|define
name|ACPI_ENABLE_ALL_VENDOR_STRINGS
value|(ACPI_ENABLE_INTERFACES | ACPI_VENDOR_STRINGS)
end_define

begin_define
define|#
directive|define
name|ACPI_ENABLE_ALL_FEATURE_STRINGS
value|(ACPI_ENABLE_INTERFACES | ACPI_FEATURE_STRINGS)
end_define

begin_define
define|#
directive|define
name|ACPI_ENABLE_ALL_STRINGS
value|(ACPI_ENABLE_INTERFACES | ACPI_VENDOR_STRINGS | ACPI_FEATURE_STRINGS)
end_define

begin_define
define|#
directive|define
name|ACPI_OSI_WIN_2000
value|0x01
end_define

begin_define
define|#
directive|define
name|ACPI_OSI_WIN_XP
value|0x02
end_define

begin_define
define|#
directive|define
name|ACPI_OSI_WIN_XP_SP1
value|0x03
end_define

begin_define
define|#
directive|define
name|ACPI_OSI_WINSRV_2003
value|0x04
end_define

begin_define
define|#
directive|define
name|ACPI_OSI_WIN_XP_SP2
value|0x05
end_define

begin_define
define|#
directive|define
name|ACPI_OSI_WINSRV_2003_SP1
value|0x06
end_define

begin_define
define|#
directive|define
name|ACPI_OSI_WIN_VISTA
value|0x07
end_define

begin_define
define|#
directive|define
name|ACPI_OSI_WINSRV_2008
value|0x08
end_define

begin_define
define|#
directive|define
name|ACPI_OSI_WIN_VISTA_SP1
value|0x09
end_define

begin_define
define|#
directive|define
name|ACPI_OSI_WIN_VISTA_SP2
value|0x0A
end_define

begin_define
define|#
directive|define
name|ACPI_OSI_WIN_7
value|0x0B
end_define

begin_define
define|#
directive|define
name|ACPI_OSI_WIN_8
value|0x0C
end_define

begin_define
define|#
directive|define
name|ACPI_OSI_WIN_10
value|0x0D
end_define

begin_comment
comment|/* Definitions of getopt */
end_comment

begin_define
define|#
directive|define
name|ACPI_OPT_END
value|-1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __ACTYPES_H__ */
end_comment

end_unit

