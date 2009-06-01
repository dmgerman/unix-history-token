begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/******************************************************************************  *  * Name: actypes.h - Common data types for the entire ACPI subsystem  *       $Revision: 1.316 $  *  *****************************************************************************/
end_comment

begin_comment
comment|/******************************************************************************  *  * 1. Copyright Notice  *  * Some or all of this work - Copyright (c) 1999 - 2007, Intel Corp.  * All rights reserved.  *  * 2. License  *  * 2.1. This is your license from Intel Corp. under its intellectual property  * rights.  You may have additional license terms from the party that provided  * you this software, covering your right to use that party's intellectual  * property rights.  *  * 2.2. Intel grants, free of charge, to any person ("Licensee") obtaining a  * copy of the source code appearing in this file ("Covered Code") an  * irrevocable, perpetual, worldwide license under Intel's copyrights in the  * base code distributed originally by Intel ("Original Intel Code") to copy,  * make derivatives, distribute, use and display any portion of the Covered  * Code in any form, with the right to sublicense such rights; and  *  * 2.3. Intel grants Licensee a non-exclusive and non-transferable patent  * license (with the right to sublicense), under only those claims of Intel  * patents that are infringed by the Original Intel Code, to make, use, sell,  * offer to sell, and import the Covered Code and derivative works thereof  * solely to the minimum extent necessary to exercise the above copyright  * license, and in no event shall the patent license extend to any additions  * to or modifications of the Original Intel Code.  No other license or right  * is granted directly or by implication, estoppel or otherwise;  *  * The above copyright and patent license is granted only if the following  * conditions are met:  *  * 3. Conditions  *  * 3.1. Redistribution of Source with Rights to Further Distribute Source.  * Redistribution of source code of any substantial portion of the Covered  * Code or modification with rights to further distribute source must include  * the above Copyright Notice, the above License, this list of Conditions,  * and the following Disclaimer and Export Compliance provision.  In addition,  * Licensee must cause all Covered Code to which Licensee contributes to  * contain a file documenting the changes Licensee made to create that Covered  * Code and the date of any change.  Licensee must include in that file the  * documentation of any changes made by any predecessor Licensee.  Licensee  * must include a prominent statement that the modification is derived,  * directly or indirectly, from Original Intel Code.  *  * 3.2. Redistribution of Source with no Rights to Further Distribute Source.  * Redistribution of source code of any substantial portion of the Covered  * Code or modification without rights to further distribute source must  * include the following Disclaimer and Export Compliance provision in the  * documentation and/or other materials provided with distribution.  In  * addition, Licensee may not authorize further sublicense of source of any  * portion of the Covered Code, and must include terms to the effect that the  * license from Licensee to its licensee is limited to the intellectual  * property embodied in the software Licensee provides to its licensee, and  * not to intellectual property embodied in modifications its licensee may  * make.  *  * 3.3. Redistribution of Executable. Redistribution in executable form of any  * substantial portion of the Covered Code or modification must reproduce the  * above Copyright Notice, and the following Disclaimer and Export Compliance  * provision in the documentation and/or other materials provided with the  * distribution.  *  * 3.4. Intel retains all right, title, and interest in and to the Original  * Intel Code.  *  * 3.5. Neither the name Intel nor any other trademark owned or controlled by  * Intel shall be used in advertising or otherwise to promote the sale, use or  * other dealings in products derived from or relating to the Covered Code  * without prior written authorization from Intel.  *  * 4. Disclaimer and Export Compliance  *  * 4.1. INTEL MAKES NO WARRANTY OF ANY KIND REGARDING ANY SOFTWARE PROVIDED  * HERE.  ANY SOFTWARE ORIGINATING FROM INTEL OR DERIVED FROM INTEL SOFTWARE  * IS PROVIDED "AS IS," AND INTEL WILL NOT PROVIDE ANY SUPPORT,  ASSISTANCE,  * INSTALLATION, TRAINING OR OTHER SERVICES.  INTEL WILL NOT PROVIDE ANY  * UPDATES, ENHANCEMENTS OR EXTENSIONS.  INTEL SPECIFICALLY DISCLAIMS ANY  * IMPLIED WARRANTIES OF MERCHANTABILITY, NONINFRINGEMENT AND FITNESS FOR A  * PARTICULAR PURPOSE.  *  * 4.2. IN NO EVENT SHALL INTEL HAVE ANY LIABILITY TO LICENSEE, ITS LICENSEES  * OR ANY OTHER THIRD PARTY, FOR ANY LOST PROFITS, LOST DATA, LOSS OF USE OR  * COSTS OF PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES, OR FOR ANY INDIRECT,  * SPECIAL OR CONSEQUENTIAL DAMAGES ARISING OUT OF THIS AGREEMENT, UNDER ANY  * CAUSE OF ACTION OR THEORY OF LIABILITY, AND IRRESPECTIVE OF WHETHER INTEL  * HAS ADVANCE NOTICE OF THE POSSIBILITY OF SUCH DAMAGES.  THESE LIMITATIONS  * SHALL APPLY NOTWITHSTANDING THE FAILURE OF THE ESSENTIAL PURPOSE OF ANY  * LIMITED REMEDY.  *  * 4.3. Licensee shall not export, either directly or indirectly, any of this  * software or system incorporating such software without first obtaining any  * required license or other approval from the U. S. Department of Commerce or  * any other agency or department of the United States Government.  In the  * event Licensee exports any such software from the United States or  * re-exports any such software from a foreign destination, Licensee shall  * ensure that the distribution and export/re-export of the software is in  * compliance with all laws, regulations, orders, or other restrictions of the  * U.S. Export Administration Regulations. Licensee agrees that neither it nor  * any of its subsidiaries will export/re-export any technical data, process,  * software, or service, directly or indirectly, to any country for which the  * United States government or any agency thereof requires an export license,  * other governmental approval, or letter of assurance, without first obtaining  * such license, approval or letter.  *  *****************************************************************************/
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
comment|/*  * ACPI_MACHINE_WIDTH must be specified in an OS- or compiler-dependent header  * and must be either 32 or 64. 16-bit ACPICA is no longer supported, as of  * 12/2006.  */
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
comment|/*! [Begin] no source code translation */
end_comment

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
comment|/*  * Architecture-specific ACPICA Subsystem Data Types  *  * The goal of these types is to provide source code portability across  * 16-bit, 32-bit, and 64-bit targets.  *  * 1) The following types are of fixed size for all targets (16/32/64):  *  * BOOLEAN      Logical boolean  *  * UINT8        8-bit  (1 byte) unsigned value  * UINT16       16-bit (2 byte) unsigned value  * UINT32       32-bit (4 byte) unsigned value  * UINT64       64-bit (8 byte) unsigned value  *  * INT16        16-bit (2 byte) signed value  * INT32        32-bit (4 byte) signed value  * INT64        64-bit (8 byte) signed value  *  * COMPILER_DEPENDENT_UINT64/INT64 - These types are defined in the  * compiler-dependent header(s) and were introduced because there is no common  * 64-bit integer type across the various compilation models, as shown in  * the table below.  *  * Datatype  LP64 ILP64 LLP64 ILP32 LP32 16bit  * char      8    8     8     8     8    8  * short     16   16    16    16    16   16  * _int32         32  * int       32   64    32    32    16   16  * long      64   64    32    32    32   32  * long long            64    64  * pointer   64   64    64    32    32   32  *  * Note: ILP64 and LP32 are currently not supported.  *  *  * 2) These types represent the native word size of the target mode of the  * processor, and may be 16-bit, 32-bit, or 64-bit as required. They are  * usually used for memory allocation, efficient loop counters, and array  * indexes. The types are similar to the size_t type in the C library and are  * required because there is no C type that consistently represents the native  * data width.  *  * ACPI_SIZE        16/32/64-bit unsigned value  * ACPI_NATIVE_UINT 16/32/64-bit unsigned value  * ACPI_NATIVE_INT  16/32/64-bit signed value  *  */
end_comment

begin_comment
comment|/*******************************************************************************  *  * Common types for all compilers, all targets  *  ******************************************************************************/
end_comment

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

begin_comment
comment|/*! [End] no source code translation !*/
end_comment

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

begin_comment
comment|/*! [Begin] no source code translation (keep the typedefs as-is) */
end_comment

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

begin_comment
comment|/*! [End] no source code translation !*/
end_comment

begin_typedef
typedef|typedef
name|UINT64
name|ACPI_NATIVE_UINT
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|INT64
name|ACPI_NATIVE_INT
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
comment|/*  * In the case of the Itanium Processor Family (IPF), the hardware does not  * support misaligned memory transfers. Set the MISALIGNMENT_NOT_SUPPORTED flag  * to indicate that special precautions must be taken to avoid alignment faults.  * (IA64 or ia64 is currently used by existing compilers to indicate IPF.)  *  * Note: EM64T and other X86-64 processors support misaligned transfers,  * so there is no need to define this flag.  */
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

begin_comment
comment|/*! [Begin] no source code translation (keep the typedefs as-is) */
end_comment

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

begin_comment
comment|/*! [End] no source code translation !*/
end_comment

begin_typedef
typedef|typedef
name|UINT32
name|ACPI_NATIVE_UINT
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|INT32
name|ACPI_NATIVE_INT
typedef|;
end_typedef

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
comment|/* Variable-width type, used instead of clib size_t */
end_comment

begin_typedef
typedef|typedef
name|ACPI_NATIVE_UINT
name|ACPI_SIZE
typedef|;
end_typedef

begin_comment
comment|/*******************************************************************************  *  * OS-dependent and compiler-dependent types  *  * If the defaults below are not appropriate for the host system, they can  * be defined in the compiler-specific or OS-specific header, and this will  * take precedence.  *  ******************************************************************************/
end_comment

begin_comment
comment|/* Value returned by AcpiOsGetThreadId */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|ACPI_THREAD_ID
end_ifndef

begin_define
define|#
directive|define
name|ACPI_THREAD_ID
value|ACPI_NATIVE_UINT
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Object returned from AcpiOsCreateLock */
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
value|ACPI_NATIVE_UINT
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

begin_define
define|#
directive|define
name|ACPI_CACHE_T
value|ACPI_MEMORY_LIST
end_define

begin_endif
endif|#
directive|endif
end_endif

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
comment|/*  * Some compilers complain about unused variables. Sometimes we don't want to  * use all the variables (for example, _AcpiModuleName). This allows us  * to to tell the compiler in a per-variable manner that a variable  * is unused  */
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
comment|/*  * All ACPICA functions that are available to the rest of the kernel are  * tagged with this macro which can be defined as appropriate for the host.  */
end_comment

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
comment|/*  * Mescellaneous types  */
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

begin_typedef
typedef|typedef
struct|struct
name|uint64_struct
block|{
name|UINT32
name|Lo
decl_stmt|;
name|UINT32
name|Hi
decl_stmt|;
block|}
name|UINT64_STRUCT
typedef|;
end_typedef

begin_typedef
typedef|typedef
union|union
name|uint64_overlay
block|{
name|UINT64
name|Full
decl_stmt|;
name|UINT64_STRUCT
name|Part
decl_stmt|;
block|}
name|UINT64_OVERLAY
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|uint32_struct
block|{
name|UINT32
name|Lo
decl_stmt|;
name|UINT32
name|Hi
decl_stmt|;
block|}
name|UINT32_STRUCT
typedef|;
end_typedef

begin_comment
comment|/* Synchronization objects */
end_comment

begin_define
define|#
directive|define
name|ACPI_MUTEX
value|void *
end_define

begin_define
define|#
directive|define
name|ACPI_SEMAPHORE
value|void *
end_define

begin_comment
comment|/*  * Acpi integer width. In ACPI version 1, integers are 32 bits.  In ACPI  * version 2, integers are 64 bits. Note that this pertains to the ACPI integer  * type only, not other integers used in the implementation of the ACPI CA  * subsystem.  */
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

begin_if
if|#
directive|if
name|ACPI_MACHINE_WIDTH
operator|==
literal|64
end_if

begin_define
define|#
directive|define
name|ACPI_USE_NATIVE_DIVIDE
end_define

begin_comment
comment|/* Use compiler native 64-bit divide */
end_comment

begin_endif
endif|#
directive|endif
end_endif

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
value|(UINT8) 0
end_define

begin_define
define|#
directive|define
name|ACPI_NOTIFY_DEVICE_CHECK
value|(UINT8) 1
end_define

begin_define
define|#
directive|define
name|ACPI_NOTIFY_DEVICE_WAKE
value|(UINT8) 2
end_define

begin_define
define|#
directive|define
name|ACPI_NOTIFY_EJECT_REQUEST
value|(UINT8) 3
end_define

begin_define
define|#
directive|define
name|ACPI_NOTIFY_DEVICE_CHECK_LIGHT
value|(UINT8) 4
end_define

begin_define
define|#
directive|define
name|ACPI_NOTIFY_FREQUENCY_MISMATCH
value|(UINT8) 5
end_define

begin_define
define|#
directive|define
name|ACPI_NOTIFY_BUS_MODE_MISMATCH
value|(UINT8) 6
end_define

begin_define
define|#
directive|define
name|ACPI_NOTIFY_POWER_FAULT
value|(UINT8) 7
end_define

begin_comment
comment|/*  * Types associated with ACPI names and objects.  The first group of  * values (up to ACPI_TYPE_EXTERNAL_MAX) correspond to the definition  * of the ACPI ObjectType() operator (See the ACPI Spec).  Therefore,  * only add to the first group if the spec changes.  *  * NOTE: Types must be kept in sync with the global AcpiNsProperties  * and AcpiNsTypeNames arrays.  */
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

begin_comment
comment|/*  * These are object types that do not map directly to the ACPI  * ObjectType() operator. They are used for various internal purposes only.  * If new predefined ACPI_TYPEs are added (via the ACPI specification), these  * internal types must move upwards. (There is code that depends on these  * values being contiguous with the external types above.)  */
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

begin_comment
comment|/*  * These are special object types that never appear in  * a Namespace node, only in an ACPI_OPERAND_OBJECT  */
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
comment|/*  * Event Status - Per event  * -------------  * The encoding of ACPI_EVENT_STATUS is illustrated below.  * Note that a set bit (1) indicates the property is TRUE  * (e.g. if bit 0 is set then the event is enabled).  * +-------------+-+-+-+  * |   Bits 31:3 |2|1|0|  * +-------------+-+-+-+  *          |     | | |  *          |     | | +- Enabled?  *          |     | +--- Enabled for wake?  *          |     +----- Set?  *          +-----------<Reserved>  */
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
name|ACPI_EVENT_FLAG_SET
value|(ACPI_EVENT_STATUS) 0x04
end_define

begin_comment
comment|/*  * General Purpose Events (GPE)  */
end_comment

begin_define
define|#
directive|define
name|ACPI_GPE_INVALID
value|0xFF
end_define

begin_define
define|#
directive|define
name|ACPI_GPE_MAX
value|0xFF
end_define

begin_define
define|#
directive|define
name|ACPI_NUM_GPE
value|256
end_define

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

begin_comment
comment|/*  * GPE info flags - Per GPE  * +-+-+-+---+---+-+  * |7|6|5|4:3|2:1|0|  * +-+-+-+---+---+-+  *  | | |  |   |  |  *  | | |  |   |  +--- Interrupt type: Edge or Level Triggered  *  | | |  |   +--- Type: Wake-only, Runtime-only, or wake/runtime  *  | | |  +--- Type of dispatch -- to method, handler, or none  *  | | +--- Enabled for runtime?  *  | +--- Enabled for wake?  *  +--- Unused  */
end_comment

begin_define
define|#
directive|define
name|ACPI_GPE_XRUPT_TYPE_MASK
value|(UINT8) 0x01
end_define

begin_define
define|#
directive|define
name|ACPI_GPE_LEVEL_TRIGGERED
value|(UINT8) 0x01
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
name|ACPI_GPE_TYPE_MASK
value|(UINT8) 0x06
end_define

begin_define
define|#
directive|define
name|ACPI_GPE_TYPE_WAKE_RUN
value|(UINT8) 0x06
end_define

begin_define
define|#
directive|define
name|ACPI_GPE_TYPE_WAKE
value|(UINT8) 0x02
end_define

begin_define
define|#
directive|define
name|ACPI_GPE_TYPE_RUNTIME
value|(UINT8) 0x04
end_define

begin_comment
comment|/* Default */
end_comment

begin_define
define|#
directive|define
name|ACPI_GPE_DISPATCH_MASK
value|(UINT8) 0x18
end_define

begin_define
define|#
directive|define
name|ACPI_GPE_DISPATCH_HANDLER
value|(UINT8) 0x08
end_define

begin_define
define|#
directive|define
name|ACPI_GPE_DISPATCH_METHOD
value|(UINT8) 0x10
end_define

begin_define
define|#
directive|define
name|ACPI_GPE_DISPATCH_NOT_USED
value|(UINT8) 0x00
end_define

begin_comment
comment|/* Default */
end_comment

begin_define
define|#
directive|define
name|ACPI_GPE_RUN_ENABLE_MASK
value|(UINT8) 0x20
end_define

begin_define
define|#
directive|define
name|ACPI_GPE_RUN_ENABLED
value|(UINT8) 0x20
end_define

begin_define
define|#
directive|define
name|ACPI_GPE_RUN_DISABLED
value|(UINT8) 0x00
end_define

begin_comment
comment|/* Default */
end_comment

begin_define
define|#
directive|define
name|ACPI_GPE_WAKE_ENABLE_MASK
value|(UINT8) 0x40
end_define

begin_define
define|#
directive|define
name|ACPI_GPE_WAKE_ENABLED
value|(UINT8) 0x40
end_define

begin_define
define|#
directive|define
name|ACPI_GPE_WAKE_DISABLED
value|(UINT8) 0x00
end_define

begin_comment
comment|/* Default */
end_comment

begin_define
define|#
directive|define
name|ACPI_GPE_ENABLE_MASK
value|(UINT8) 0x60
end_define

begin_comment
comment|/* Both run/wake */
end_comment

begin_comment
comment|/*  * Flags for GPE and Lock interfaces  */
end_comment

begin_define
define|#
directive|define
name|ACPI_EVENT_WAKE_ENABLE
value|0x2
end_define

begin_comment
comment|/* AcpiGpeEnable */
end_comment

begin_define
define|#
directive|define
name|ACPI_EVENT_WAKE_DISABLE
value|0x2
end_define

begin_comment
comment|/* AcpiGpeDisable */
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
value|0x3
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
name|ACPI_MAX_SYS_NOTIFY
value|0x7f
end_define

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
name|ACPI_ADR_SPACE_DATA_TABLE
value|(ACPI_ADR_SPACE_TYPE) 7
end_define

begin_define
define|#
directive|define
name|ACPI_ADR_SPACE_FIXED_HARDWARE
value|(ACPI_ADR_SPACE_TYPE) 127
end_define

begin_comment
comment|/*  * BitRegister IDs  * These are bitfields defined within the full ACPI registers  */
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
name|ACPI_BITREG_WAKE_ENABLE
value|0x0D
end_define

begin_define
define|#
directive|define
name|ACPI_BITREG_PCIEXP_WAKE_DISABLE
value|0x0E
end_define

begin_define
define|#
directive|define
name|ACPI_BITREG_SCI_ENABLE
value|0x0F
end_define

begin_define
define|#
directive|define
name|ACPI_BITREG_BUS_MASTER_RLD
value|0x10
end_define

begin_define
define|#
directive|define
name|ACPI_BITREG_GLOBAL_LOCK_RELEASE
value|0x11
end_define

begin_define
define|#
directive|define
name|ACPI_BITREG_SLEEP_TYPE_A
value|0x12
end_define

begin_define
define|#
directive|define
name|ACPI_BITREG_SLEEP_TYPE_B
value|0x13
end_define

begin_define
define|#
directive|define
name|ACPI_BITREG_SLEEP_ENABLE
value|0x14
end_define

begin_define
define|#
directive|define
name|ACPI_BITREG_ARB_DISABLE
value|0x15
end_define

begin_define
define|#
directive|define
name|ACPI_BITREG_MAX
value|0x15
end_define

begin_define
define|#
directive|define
name|ACPI_NUM_BITREG
value|ACPI_BITREG_MAX + 1
end_define

begin_comment
comment|/*  * External ACPI object definition  */
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
name|ACPI_INTEGER
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
name|UINT32
name|Fill1
decl_stmt|;
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

begin_define
define|#
directive|define
name|ACPI_ALLOCATE_BUFFER
value|(ACPI_SIZE) (-1)
end_define

begin_define
define|#
directive|define
name|ACPI_ALLOCATE_LOCAL_BUFFER
value|(ACPI_SIZE) (-2)
end_define

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
name|ACPI_NAME_TYPE_MAX
value|1
end_define

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
name|UINT32
name|Function
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
name|ACPI_INTEGER
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
name|ObjHandle
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
comment|/* Common string version of device HIDs and UIDs */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|acpi_device_id
block|{
name|char
name|Value
index|[
name|ACPI_DEVICE_ID_LENGTH
index|]
decl_stmt|;
block|}
name|ACPI_DEVICE_ID
typedef|;
end_typedef

begin_comment
comment|/* Common string version of device CIDs */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|acpi_compatible_id
block|{
name|char
name|Value
index|[
name|ACPI_MAX_CID_LENGTH
index|]
decl_stmt|;
block|}
name|ACPI_COMPATIBLE_ID
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|acpi_compatible_id_list
block|{
name|UINT32
name|Count
decl_stmt|;
name|UINT32
name|Size
decl_stmt|;
name|ACPI_COMPATIBLE_ID
name|Id
index|[
literal|1
index|]
decl_stmt|;
block|}
name|ACPI_COMPATIBLE_ID_LIST
typedef|;
end_typedef

begin_comment
comment|/* Structure and flags for AcpiGetObjectInfo */
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
value|0x0010
end_define

begin_define
define|#
directive|define
name|ACPI_VALID_SXDS
value|0x0020
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

begin_define
define|#
directive|define
name|ACPI_COMMON_OBJ_INFO
define|\
value|ACPI_OBJECT_TYPE                Type;
comment|/* ACPI object type */
value|\     ACPI_NAME                       Name
end_define

begin_comment
comment|/* ACPI object Name */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|acpi_obj_info_header
block|{
name|ACPI_COMMON_OBJ_INFO
expr_stmt|;
block|}
name|ACPI_OBJ_INFO_HEADER
typedef|;
end_typedef

begin_comment
comment|/* Structure returned from Get Object Info */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|acpi_device_info
block|{
name|ACPI_COMMON_OBJ_INFO
expr_stmt|;
name|UINT32
name|Valid
decl_stmt|;
comment|/* Indicates which fields below are valid */
name|UINT32
name|CurrentStatus
decl_stmt|;
comment|/* _STA value */
name|ACPI_INTEGER
name|Address
decl_stmt|;
comment|/* _ADR value if any */
name|ACPI_DEVICE_ID
name|HardwareId
decl_stmt|;
comment|/* _HID value if any */
name|ACPI_DEVICE_ID
name|UniqueId
decl_stmt|;
comment|/* _UID value if any */
name|UINT8
name|HighestDstates
index|[
literal|4
index|]
decl_stmt|;
comment|/* _SxD values: 0xFF indicates not valid */
name|ACPI_COMPATIBLE_ID_LIST
name|CompatibilityId
decl_stmt|;
comment|/* List of _CIDs if any */
block|}
name|ACPI_DEVICE_INFO
typedef|;
end_typedef

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
comment|/*  * Definitions for Resource Attributes  */
end_comment

begin_typedef
typedef|typedef
name|UINT16
name|ACPI_RS_LENGTH
typedef|;
end_typedef

begin_comment
comment|/* Resource Length field is fixed at 16 bits */
end_comment

begin_typedef
typedef|typedef
name|UINT32
name|ACPI_RSDESC_SIZE
typedef|;
end_typedef

begin_comment
comment|/* Max Resource Descriptor size is (Length+3) = (64K-1)+3 */
end_comment

begin_comment
comment|/*  *  Memory Attributes  */
end_comment

begin_define
define|#
directive|define
name|ACPI_READ_ONLY_MEMORY
value|(UINT8) 0x00
end_define

begin_define
define|#
directive|define
name|ACPI_READ_WRITE_MEMORY
value|(UINT8) 0x01
end_define

begin_define
define|#
directive|define
name|ACPI_NON_CACHEABLE_MEMORY
value|(UINT8) 0x00
end_define

begin_define
define|#
directive|define
name|ACPI_CACHABLE_MEMORY
value|(UINT8) 0x01
end_define

begin_define
define|#
directive|define
name|ACPI_WRITE_COMBINING_MEMORY
value|(UINT8) 0x02
end_define

begin_define
define|#
directive|define
name|ACPI_PREFETCHABLE_MEMORY
value|(UINT8) 0x03
end_define

begin_comment
comment|/*  *  IO Attributes  *  The ISA IO ranges are:     n000-n0FFh,  n400-n4FFh, n800-n8FFh, nC00-nCFFh.  *  The non-ISA IO ranges are: n100-n3FFh,  n500-n7FFh, n900-nBFFh, nCD0-nFFFh.  */
end_comment

begin_define
define|#
directive|define
name|ACPI_NON_ISA_ONLY_RANGES
value|(UINT8) 0x01
end_define

begin_define
define|#
directive|define
name|ACPI_ISA_ONLY_RANGES
value|(UINT8) 0x02
end_define

begin_define
define|#
directive|define
name|ACPI_ENTIRE_RANGE
value|(ACPI_NON_ISA_ONLY_RANGES | ACPI_ISA_ONLY_RANGES)
end_define

begin_comment
comment|/* Type of translation - 1=Sparse, 0=Dense */
end_comment

begin_define
define|#
directive|define
name|ACPI_SPARSE_TRANSLATION
value|(UINT8) 0x01
end_define

begin_comment
comment|/*  *  IO Port Descriptor Decode  */
end_comment

begin_define
define|#
directive|define
name|ACPI_DECODE_10
value|(UINT8) 0x00
end_define

begin_comment
comment|/* 10-bit IO address decode */
end_comment

begin_define
define|#
directive|define
name|ACPI_DECODE_16
value|(UINT8) 0x01
end_define

begin_comment
comment|/* 16-bit IO address decode */
end_comment

begin_comment
comment|/*  *  IRQ Attributes  */
end_comment

begin_define
define|#
directive|define
name|ACPI_LEVEL_SENSITIVE
value|(UINT8) 0x00
end_define

begin_define
define|#
directive|define
name|ACPI_EDGE_SENSITIVE
value|(UINT8) 0x01
end_define

begin_define
define|#
directive|define
name|ACPI_ACTIVE_HIGH
value|(UINT8) 0x00
end_define

begin_define
define|#
directive|define
name|ACPI_ACTIVE_LOW
value|(UINT8) 0x01
end_define

begin_define
define|#
directive|define
name|ACPI_EXCLUSIVE
value|(UINT8) 0x00
end_define

begin_define
define|#
directive|define
name|ACPI_SHARED
value|(UINT8) 0x01
end_define

begin_comment
comment|/*  *  DMA Attributes  */
end_comment

begin_define
define|#
directive|define
name|ACPI_COMPATIBILITY
value|(UINT8) 0x00
end_define

begin_define
define|#
directive|define
name|ACPI_TYPE_A
value|(UINT8) 0x01
end_define

begin_define
define|#
directive|define
name|ACPI_TYPE_B
value|(UINT8) 0x02
end_define

begin_define
define|#
directive|define
name|ACPI_TYPE_F
value|(UINT8) 0x03
end_define

begin_define
define|#
directive|define
name|ACPI_NOT_BUS_MASTER
value|(UINT8) 0x00
end_define

begin_define
define|#
directive|define
name|ACPI_BUS_MASTER
value|(UINT8) 0x01
end_define

begin_define
define|#
directive|define
name|ACPI_TRANSFER_8
value|(UINT8) 0x00
end_define

begin_define
define|#
directive|define
name|ACPI_TRANSFER_8_16
value|(UINT8) 0x01
end_define

begin_define
define|#
directive|define
name|ACPI_TRANSFER_16
value|(UINT8) 0x02
end_define

begin_comment
comment|/*  * Start Dependent Functions Priority definitions  */
end_comment

begin_define
define|#
directive|define
name|ACPI_GOOD_CONFIGURATION
value|(UINT8) 0x00
end_define

begin_define
define|#
directive|define
name|ACPI_ACCEPTABLE_CONFIGURATION
value|(UINT8) 0x01
end_define

begin_define
define|#
directive|define
name|ACPI_SUB_OPTIMAL_CONFIGURATION
value|(UINT8) 0x02
end_define

begin_comment
comment|/*  *  16, 32 and 64-bit Address Descriptor resource types  */
end_comment

begin_define
define|#
directive|define
name|ACPI_MEMORY_RANGE
value|(UINT8) 0x00
end_define

begin_define
define|#
directive|define
name|ACPI_IO_RANGE
value|(UINT8) 0x01
end_define

begin_define
define|#
directive|define
name|ACPI_BUS_NUMBER_RANGE
value|(UINT8) 0x02
end_define

begin_define
define|#
directive|define
name|ACPI_ADDRESS_NOT_FIXED
value|(UINT8) 0x00
end_define

begin_define
define|#
directive|define
name|ACPI_ADDRESS_FIXED
value|(UINT8) 0x01
end_define

begin_define
define|#
directive|define
name|ACPI_POS_DECODE
value|(UINT8) 0x00
end_define

begin_define
define|#
directive|define
name|ACPI_SUB_DECODE
value|(UINT8) 0x01
end_define

begin_define
define|#
directive|define
name|ACPI_PRODUCER
value|(UINT8) 0x00
end_define

begin_define
define|#
directive|define
name|ACPI_CONSUMER
value|(UINT8) 0x01
end_define

begin_comment
comment|/*  * If possible, pack the following structures to byte alignment  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|ACPI_MISALIGNMENT_NOT_SUPPORTED
end_ifndef

begin_pragma
pragma|#
directive|pragma
name|pack
name|(
name|1
name|)
end_pragma

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* UUID data structures for use in vendor-defined resource descriptors */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|acpi_uuid
block|{
name|UINT8
name|Data
index|[
name|ACPI_UUID_LENGTH
index|]
decl_stmt|;
block|}
name|ACPI_UUID
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|acpi_vendor_uuid
block|{
name|UINT8
name|Subtype
decl_stmt|;
name|UINT8
name|Data
index|[
name|ACPI_UUID_LENGTH
index|]
decl_stmt|;
block|}
name|ACPI_VENDOR_UUID
typedef|;
end_typedef

begin_comment
comment|/*  *  Structures used to describe device resources  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|acpi_resource_irq
block|{
name|UINT8
name|Triggering
decl_stmt|;
name|UINT8
name|Polarity
decl_stmt|;
name|UINT8
name|Sharable
decl_stmt|;
name|UINT8
name|InterruptCount
decl_stmt|;
name|UINT8
name|Interrupts
index|[
literal|1
index|]
decl_stmt|;
block|}
name|ACPI_RESOURCE_IRQ
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|ACPI_RESOURCE_DMA
block|{
name|UINT8
name|Type
decl_stmt|;
name|UINT8
name|BusMaster
decl_stmt|;
name|UINT8
name|Transfer
decl_stmt|;
name|UINT8
name|ChannelCount
decl_stmt|;
name|UINT8
name|Channels
index|[
literal|1
index|]
decl_stmt|;
block|}
name|ACPI_RESOURCE_DMA
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|acpi_resource_start_dependent
block|{
name|UINT8
name|CompatibilityPriority
decl_stmt|;
name|UINT8
name|PerformanceRobustness
decl_stmt|;
block|}
name|ACPI_RESOURCE_START_DEPENDENT
typedef|;
end_typedef

begin_comment
comment|/*  * END_DEPENDENT_FUNCTIONS_RESOURCE struct is not  * needed because it has no fields  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|acpi_resource_io
block|{
name|UINT8
name|IoDecode
decl_stmt|;
name|UINT8
name|Alignment
decl_stmt|;
name|UINT8
name|AddressLength
decl_stmt|;
name|UINT16
name|Minimum
decl_stmt|;
name|UINT16
name|Maximum
decl_stmt|;
block|}
name|ACPI_RESOURCE_IO
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|acpi_resource_fixed_io
block|{
name|UINT16
name|Address
decl_stmt|;
name|UINT8
name|AddressLength
decl_stmt|;
block|}
name|ACPI_RESOURCE_FIXED_IO
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|acpi_resource_vendor
block|{
name|UINT16
name|ByteLength
decl_stmt|;
name|UINT8
name|ByteData
index|[
literal|1
index|]
decl_stmt|;
block|}
name|ACPI_RESOURCE_VENDOR
typedef|;
end_typedef

begin_comment
comment|/* Vendor resource with UUID info (introduced in ACPI 3.0) */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|acpi_resource_vendor_typed
block|{
name|UINT16
name|ByteLength
decl_stmt|;
name|UINT8
name|UuidSubtype
decl_stmt|;
name|UINT8
name|Uuid
index|[
name|ACPI_UUID_LENGTH
index|]
decl_stmt|;
name|UINT8
name|ByteData
index|[
literal|1
index|]
decl_stmt|;
block|}
name|ACPI_RESOURCE_VENDOR_TYPED
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|acpi_resource_end_tag
block|{
name|UINT8
name|Checksum
decl_stmt|;
block|}
name|ACPI_RESOURCE_END_TAG
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|acpi_resource_memory24
block|{
name|UINT8
name|WriteProtect
decl_stmt|;
name|UINT16
name|Minimum
decl_stmt|;
name|UINT16
name|Maximum
decl_stmt|;
name|UINT16
name|Alignment
decl_stmt|;
name|UINT16
name|AddressLength
decl_stmt|;
block|}
name|ACPI_RESOURCE_MEMORY24
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|acpi_resource_memory32
block|{
name|UINT8
name|WriteProtect
decl_stmt|;
name|UINT32
name|Minimum
decl_stmt|;
name|UINT32
name|Maximum
decl_stmt|;
name|UINT32
name|Alignment
decl_stmt|;
name|UINT32
name|AddressLength
decl_stmt|;
block|}
name|ACPI_RESOURCE_MEMORY32
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|acpi_resource_fixed_memory32
block|{
name|UINT8
name|WriteProtect
decl_stmt|;
name|UINT32
name|Address
decl_stmt|;
name|UINT32
name|AddressLength
decl_stmt|;
block|}
name|ACPI_RESOURCE_FIXED_MEMORY32
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|acpi_memory_attribute
block|{
name|UINT8
name|WriteProtect
decl_stmt|;
name|UINT8
name|Caching
decl_stmt|;
name|UINT8
name|RangeType
decl_stmt|;
name|UINT8
name|Translation
decl_stmt|;
block|}
name|ACPI_MEMORY_ATTRIBUTE
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|acpi_io_attribute
block|{
name|UINT8
name|RangeType
decl_stmt|;
name|UINT8
name|Translation
decl_stmt|;
name|UINT8
name|TranslationType
decl_stmt|;
name|UINT8
name|Reserved1
decl_stmt|;
block|}
name|ACPI_IO_ATTRIBUTE
typedef|;
end_typedef

begin_typedef
typedef|typedef
union|union
name|acpi_resource_attribute
block|{
name|ACPI_MEMORY_ATTRIBUTE
name|Mem
decl_stmt|;
name|ACPI_IO_ATTRIBUTE
name|Io
decl_stmt|;
comment|/* Used for the *WordSpace macros */
name|UINT8
name|TypeSpecific
decl_stmt|;
block|}
name|ACPI_RESOURCE_ATTRIBUTE
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|acpi_resource_source
block|{
name|UINT8
name|Index
decl_stmt|;
name|UINT16
name|StringLength
decl_stmt|;
name|char
modifier|*
name|StringPtr
decl_stmt|;
block|}
name|ACPI_RESOURCE_SOURCE
typedef|;
end_typedef

begin_comment
comment|/* Fields common to all address descriptors, 16/32/64 bit */
end_comment

begin_define
define|#
directive|define
name|ACPI_RESOURCE_ADDRESS_COMMON
define|\
value|UINT8                           ResourceType; \     UINT8                           ProducerConsumer; \     UINT8                           Decode; \     UINT8                           MinAddressFixed; \     UINT8                           MaxAddressFixed; \     ACPI_RESOURCE_ATTRIBUTE         Info;
end_define

begin_typedef
typedef|typedef
struct|struct
name|acpi_resource_address
block|{
name|ACPI_RESOURCE_ADDRESS_COMMON
block|}
name|ACPI_RESOURCE_ADDRESS
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|acpi_resource_address16
block|{
name|ACPI_RESOURCE_ADDRESS_COMMON
name|UINT16
name|Granularity
decl_stmt|;
name|UINT16
name|Minimum
decl_stmt|;
name|UINT16
name|Maximum
decl_stmt|;
name|UINT16
name|TranslationOffset
decl_stmt|;
name|UINT16
name|AddressLength
decl_stmt|;
name|ACPI_RESOURCE_SOURCE
name|ResourceSource
decl_stmt|;
block|}
name|ACPI_RESOURCE_ADDRESS16
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|acpi_resource_address32
block|{
name|ACPI_RESOURCE_ADDRESS_COMMON
name|UINT32
name|Granularity
decl_stmt|;
name|UINT32
name|Minimum
decl_stmt|;
name|UINT32
name|Maximum
decl_stmt|;
name|UINT32
name|TranslationOffset
decl_stmt|;
name|UINT32
name|AddressLength
decl_stmt|;
name|ACPI_RESOURCE_SOURCE
name|ResourceSource
decl_stmt|;
block|}
name|ACPI_RESOURCE_ADDRESS32
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|acpi_resource_address64
block|{
name|ACPI_RESOURCE_ADDRESS_COMMON
name|UINT64
name|Granularity
decl_stmt|;
name|UINT64
name|Minimum
decl_stmt|;
name|UINT64
name|Maximum
decl_stmt|;
name|UINT64
name|TranslationOffset
decl_stmt|;
name|UINT64
name|AddressLength
decl_stmt|;
name|ACPI_RESOURCE_SOURCE
name|ResourceSource
decl_stmt|;
block|}
name|ACPI_RESOURCE_ADDRESS64
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|acpi_resource_extended_address64
block|{
name|ACPI_RESOURCE_ADDRESS_COMMON
name|UINT8
name|RevisionID
decl_stmt|;
name|UINT64
name|Granularity
decl_stmt|;
name|UINT64
name|Minimum
decl_stmt|;
name|UINT64
name|Maximum
decl_stmt|;
name|UINT64
name|TranslationOffset
decl_stmt|;
name|UINT64
name|AddressLength
decl_stmt|;
name|UINT64
name|TypeSpecific
decl_stmt|;
block|}
name|ACPI_RESOURCE_EXTENDED_ADDRESS64
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|acpi_resource_extended_irq
block|{
name|UINT8
name|ProducerConsumer
decl_stmt|;
name|UINT8
name|Triggering
decl_stmt|;
name|UINT8
name|Polarity
decl_stmt|;
name|UINT8
name|Sharable
decl_stmt|;
name|UINT8
name|InterruptCount
decl_stmt|;
name|ACPI_RESOURCE_SOURCE
name|ResourceSource
decl_stmt|;
name|UINT32
name|Interrupts
index|[
literal|1
index|]
decl_stmt|;
block|}
name|ACPI_RESOURCE_EXTENDED_IRQ
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|acpi_resource_generic_register
block|{
name|UINT8
name|SpaceId
decl_stmt|;
name|UINT8
name|BitWidth
decl_stmt|;
name|UINT8
name|BitOffset
decl_stmt|;
name|UINT8
name|AccessSize
decl_stmt|;
name|UINT64
name|Address
decl_stmt|;
block|}
name|ACPI_RESOURCE_GENERIC_REGISTER
typedef|;
end_typedef

begin_comment
comment|/* ACPI_RESOURCE_TYPEs */
end_comment

begin_define
define|#
directive|define
name|ACPI_RESOURCE_TYPE_IRQ
value|0
end_define

begin_define
define|#
directive|define
name|ACPI_RESOURCE_TYPE_DMA
value|1
end_define

begin_define
define|#
directive|define
name|ACPI_RESOURCE_TYPE_START_DEPENDENT
value|2
end_define

begin_define
define|#
directive|define
name|ACPI_RESOURCE_TYPE_END_DEPENDENT
value|3
end_define

begin_define
define|#
directive|define
name|ACPI_RESOURCE_TYPE_IO
value|4
end_define

begin_define
define|#
directive|define
name|ACPI_RESOURCE_TYPE_FIXED_IO
value|5
end_define

begin_define
define|#
directive|define
name|ACPI_RESOURCE_TYPE_VENDOR
value|6
end_define

begin_define
define|#
directive|define
name|ACPI_RESOURCE_TYPE_END_TAG
value|7
end_define

begin_define
define|#
directive|define
name|ACPI_RESOURCE_TYPE_MEMORY24
value|8
end_define

begin_define
define|#
directive|define
name|ACPI_RESOURCE_TYPE_MEMORY32
value|9
end_define

begin_define
define|#
directive|define
name|ACPI_RESOURCE_TYPE_FIXED_MEMORY32
value|10
end_define

begin_define
define|#
directive|define
name|ACPI_RESOURCE_TYPE_ADDRESS16
value|11
end_define

begin_define
define|#
directive|define
name|ACPI_RESOURCE_TYPE_ADDRESS32
value|12
end_define

begin_define
define|#
directive|define
name|ACPI_RESOURCE_TYPE_ADDRESS64
value|13
end_define

begin_define
define|#
directive|define
name|ACPI_RESOURCE_TYPE_EXTENDED_ADDRESS64
value|14
end_define

begin_comment
comment|/* ACPI 3.0 */
end_comment

begin_define
define|#
directive|define
name|ACPI_RESOURCE_TYPE_EXTENDED_IRQ
value|15
end_define

begin_define
define|#
directive|define
name|ACPI_RESOURCE_TYPE_GENERIC_REGISTER
value|16
end_define

begin_define
define|#
directive|define
name|ACPI_RESOURCE_TYPE_MAX
value|16
end_define

begin_typedef
typedef|typedef
union|union
name|acpi_resource_data
block|{
name|ACPI_RESOURCE_IRQ
name|Irq
decl_stmt|;
name|ACPI_RESOURCE_DMA
name|Dma
decl_stmt|;
name|ACPI_RESOURCE_START_DEPENDENT
name|StartDpf
decl_stmt|;
name|ACPI_RESOURCE_IO
name|Io
decl_stmt|;
name|ACPI_RESOURCE_FIXED_IO
name|FixedIo
decl_stmt|;
name|ACPI_RESOURCE_VENDOR
name|Vendor
decl_stmt|;
name|ACPI_RESOURCE_VENDOR_TYPED
name|VendorTyped
decl_stmt|;
name|ACPI_RESOURCE_END_TAG
name|EndTag
decl_stmt|;
name|ACPI_RESOURCE_MEMORY24
name|Memory24
decl_stmt|;
name|ACPI_RESOURCE_MEMORY32
name|Memory32
decl_stmt|;
name|ACPI_RESOURCE_FIXED_MEMORY32
name|FixedMemory32
decl_stmt|;
name|ACPI_RESOURCE_ADDRESS16
name|Address16
decl_stmt|;
name|ACPI_RESOURCE_ADDRESS32
name|Address32
decl_stmt|;
name|ACPI_RESOURCE_ADDRESS64
name|Address64
decl_stmt|;
name|ACPI_RESOURCE_EXTENDED_ADDRESS64
name|ExtAddress64
decl_stmt|;
name|ACPI_RESOURCE_EXTENDED_IRQ
name|ExtendedIrq
decl_stmt|;
name|ACPI_RESOURCE_GENERIC_REGISTER
name|GenericReg
decl_stmt|;
comment|/* Common fields */
name|ACPI_RESOURCE_ADDRESS
name|Address
decl_stmt|;
comment|/* Common 16/32/64 address fields */
block|}
name|ACPI_RESOURCE_DATA
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|acpi_resource
block|{
name|UINT32
name|Type
decl_stmt|;
name|UINT32
name|Length
decl_stmt|;
name|ACPI_RESOURCE_DATA
name|Data
decl_stmt|;
block|}
name|ACPI_RESOURCE
typedef|;
end_typedef

begin_comment
comment|/* restore default alignment */
end_comment

begin_pragma
pragma|#
directive|pragma
name|pack
name|(
name|)
end_pragma

begin_define
define|#
directive|define
name|ACPI_RS_SIZE_MIN
value|12
end_define

begin_define
define|#
directive|define
name|ACPI_RS_SIZE_NO_DATA
value|8
end_define

begin_comment
comment|/* Id + Length fields */
end_comment

begin_define
define|#
directive|define
name|ACPI_RS_SIZE
parameter_list|(
name|Type
parameter_list|)
value|(UINT32) (ACPI_RS_SIZE_NO_DATA + sizeof (Type))
end_define

begin_define
define|#
directive|define
name|ACPI_NEXT_RESOURCE
parameter_list|(
name|Res
parameter_list|)
value|(ACPI_RESOURCE *)((UINT8 *) Res + Res->Length)
end_define

begin_typedef
typedef|typedef
struct|struct
name|acpi_pci_routing_table
block|{
name|UINT32
name|Length
decl_stmt|;
name|UINT32
name|Pin
decl_stmt|;
name|ACPI_INTEGER
name|Address
decl_stmt|;
comment|/* here for 64-bit alignment */
name|UINT32
name|SourceIndex
decl_stmt|;
name|char
name|Source
index|[
literal|4
index|]
decl_stmt|;
comment|/* pad to 64 bits so sizeof() works in all cases */
block|}
name|ACPI_PCI_ROUTING_TABLE
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __ACTYPES_H__ */
end_comment

end_unit

