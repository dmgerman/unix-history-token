begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/******************************************************************************  *  * Name: actypes.h - Common data types for the entire ACPI subsystem  *       $Revision: 224 $  *  *****************************************************************************/
end_comment

begin_comment
comment|/******************************************************************************  *  * 1. Copyright Notice  *  * Some or all of this work - Copyright (c) 1999 - 2002, Intel Corp.  * All rights reserved.  *  * 2. License  *  * 2.1. This is your license from Intel Corp. under its intellectual property  * rights.  You may have additional license terms from the party that provided  * you this software, covering your right to use that party's intellectual  * property rights.  *  * 2.2. Intel grants, free of charge, to any person ("Licensee") obtaining a  * copy of the source code appearing in this file ("Covered Code") an  * irrevocable, perpetual, worldwide license under Intel's copyrights in the  * base code distributed originally by Intel ("Original Intel Code") to copy,  * make derivatives, distribute, use and display any portion of the Covered  * Code in any form, with the right to sublicense such rights; and  *  * 2.3. Intel grants Licensee a non-exclusive and non-transferable patent  * license (with the right to sublicense), under only those claims of Intel  * patents that are infringed by the Original Intel Code, to make, use, sell,  * offer to sell, and import the Covered Code and derivative works thereof  * solely to the minimum extent necessary to exercise the above copyright  * license, and in no event shall the patent license extend to any additions  * to or modifications of the Original Intel Code.  No other license or right  * is granted directly or by implication, estoppel or otherwise;  *  * The above copyright and patent license is granted only if the following  * conditions are met:  *  * 3. Conditions  *  * 3.1. Redistribution of Source with Rights to Further Distribute Source.  * Redistribution of source code of any substantial portion of the Covered  * Code or modification with rights to further distribute source must include  * the above Copyright Notice, the above License, this list of Conditions,  * and the following Disclaimer and Export Compliance provision.  In addition,  * Licensee must cause all Covered Code to which Licensee contributes to  * contain a file documenting the changes Licensee made to create that Covered  * Code and the date of any change.  Licensee must include in that file the  * documentation of any changes made by any predecessor Licensee.  Licensee  * must include a prominent statement that the modification is derived,  * directly or indirectly, from Original Intel Code.  *  * 3.2. Redistribution of Source with no Rights to Further Distribute Source.  * Redistribution of source code of any substantial portion of the Covered  * Code or modification without rights to further distribute source must  * include the following Disclaimer and Export Compliance provision in the  * documentation and/or other materials provided with distribution.  In  * addition, Licensee may not authorize further sublicense of source of any  * portion of the Covered Code, and must include terms to the effect that the  * license from Licensee to its licensee is limited to the intellectual  * property embodied in the software Licensee provides to its licensee, and  * not to intellectual property embodied in modifications its licensee may  * make.  *  * 3.3. Redistribution of Executable. Redistribution in executable form of any  * substantial portion of the Covered Code or modification must reproduce the  * above Copyright Notice, and the following Disclaimer and Export Compliance  * provision in the documentation and/or other materials provided with the  * distribution.  *  * 3.4. Intel retains all right, title, and interest in and to the Original  * Intel Code.  *  * 3.5. Neither the name Intel nor any other trademark owned or controlled by  * Intel shall be used in advertising or otherwise to promote the sale, use or  * other dealings in products derived from or relating to the Covered Code  * without prior written authorization from Intel.  *  * 4. Disclaimer and Export Compliance  *  * 4.1. INTEL MAKES NO WARRANTY OF ANY KIND REGARDING ANY SOFTWARE PROVIDED  * HERE.  ANY SOFTWARE ORIGINATING FROM INTEL OR DERIVED FROM INTEL SOFTWARE  * IS PROVIDED "AS IS," AND INTEL WILL NOT PROVIDE ANY SUPPORT,  ASSISTANCE,  * INSTALLATION, TRAINING OR OTHER SERVICES.  INTEL WILL NOT PROVIDE ANY  * UPDATES, ENHANCEMENTS OR EXTENSIONS.  INTEL SPECIFICALLY DISCLAIMS ANY  * IMPLIED WARRANTIES OF MERCHANTABILITY, NONINFRINGEMENT AND FITNESS FOR A  * PARTICULAR PURPOSE.  *  * 4.2. IN NO EVENT SHALL INTEL HAVE ANY LIABILITY TO LICENSEE, ITS LICENSEES  * OR ANY OTHER THIRD PARTY, FOR ANY LOST PROFITS, LOST DATA, LOSS OF USE OR  * COSTS OF PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES, OR FOR ANY INDIRECT,  * SPECIAL OR CONSEQUENTIAL DAMAGES ARISING OUT OF THIS AGREEMENT, UNDER ANY  * CAUSE OF ACTION OR THEORY OF LIABILITY, AND IRRESPECTIVE OF WHETHER INTEL  * HAS ADVANCE NOTICE OF THE POSSIBILITY OF SUCH DAMAGES.  THESE LIMITATIONS  * SHALL APPLY NOTWITHSTANDING THE FAILURE OF THE ESSENTIAL PURPOSE OF ANY  * LIMITED REMEDY.  *  * 4.3. Licensee shall not export, either directly or indirectly, any of this  * software or system incorporating such software without first obtaining any  * required license or other approval from the U. S. Department of Commerce or  * any other agency or department of the United States Government.  In the  * event Licensee exports any such software from the United States or  * re-exports any such software from a foreign destination, Licensee shall  * ensure that the distribution and export/re-export of the software is in  * compliance with all laws, regulations, orders, or other restrictions of the  * U.S. Export Administration Regulations. Licensee agrees that neither it nor  * any of its subsidiaries will export/re-export any technical data, process,  * software, or service, directly or indirectly, to any country for which the  * United States government or any agency thereof requires an export license,  * other governmental approval, or letter of assurance, without first obtaining  * such license, approval or letter.  *  *****************************************************************************/
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
comment|/*! [Begin] no source code translation (keep the typedefs) */
end_comment

begin_comment
comment|/*  * Data types - Fixed across all compilation models  *  * BOOLEAN      Logical Boolean.  *              1 byte value containing a 0 for FALSE or a 1 for TRUE.  *              Other values are undefined.  *  * INT8         8-bit  (1 byte) signed value  * UINT8        8-bit  (1 byte) unsigned value  * INT16        16-bit (2 byte) signed value  * UINT16       16-bit (2 byte) unsigned value  * INT32        32-bit (4 byte) signed value  * UINT32       32-bit (4 byte) unsigned value  * INT64        64-bit (8 byte) signed value  * UINT64       64-bit (8 byte) unsigned value  * NATIVE_INT   32-bit on IA-32, 64-bit on IA-64 signed value  * NATIVE_UINT  32-bit on IA-32, 64-bit on IA-64 unsigned value  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|_IA64
end_ifdef

begin_comment
comment|/*  * 64-bit type definitions  */
end_comment

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
name|char
name|BOOLEAN
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
name|int
name|INT32
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|int
name|UINT32
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
name|UINT64
name|NATIVE_UINT
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|UINT64
name|NATIVE_INT
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|NATIVE_UINT
name|ACPI_TBLPTR
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

begin_typedef
typedef|typedef
name|UINT64
name|ACPI_SIZE
typedef|;
end_typedef

begin_define
define|#
directive|define
name|ALIGNED_ADDRESS_BOUNDARY
value|0x00000008
end_define

begin_comment
comment|/* No hardware alignment support in IA64 */
end_comment

begin_define
define|#
directive|define
name|ACPI_USE_NATIVE_DIVIDE
end_define

begin_comment
comment|/* Native 64-bit integer support */
end_comment

begin_define
define|#
directive|define
name|ACPI_MAX_PTR
value|0xFFFFFFFFFFFFFFFF
end_define

begin_elif
elif|#
directive|elif
name|_IA16
end_elif

begin_comment
comment|/*  * 16-bit type definitions  */
end_comment

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
name|char
name|BOOLEAN
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|int
name|UINT16
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|long
name|INT32
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|int
name|INT16
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|long
name|UINT32
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT32
name|Lo
decl_stmt|;
name|UINT32
name|Hi
decl_stmt|;
block|}
name|UINT64
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|UINT16
name|NATIVE_UINT
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|INT16
name|NATIVE_INT
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|UINT32
name|ACPI_TBLPTR
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
name|char
modifier|*
name|ACPI_PHYSICAL_ADDRESS
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|UINT32
name|ACPI_SIZE
typedef|;
end_typedef

begin_define
define|#
directive|define
name|ALIGNED_ADDRESS_BOUNDARY
value|0x00000002
end_define

begin_define
define|#
directive|define
name|_HW_ALIGNMENT_SUPPORT
end_define

begin_define
define|#
directive|define
name|ACPI_USE_NATIVE_DIVIDE
end_define

begin_comment
comment|/* No 64-bit integers, ok to use native divide */
end_comment

begin_define
define|#
directive|define
name|ACPI_MAX_PTR
value|0xFFFF
end_define

begin_comment
comment|/*  * (16-bit only) internal integers must be 32-bits, so  * 64-bit integers cannot be supported  */
end_comment

begin_define
define|#
directive|define
name|ACPI_NO_INTEGER64_SUPPORT
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/*  * 32-bit type definitions (default)  */
end_comment

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
name|char
name|BOOLEAN
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
name|int
name|INT32
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|int
name|UINT32
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
name|UINT32
name|NATIVE_UINT
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|INT32
name|NATIVE_INT
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|NATIVE_UINT
name|ACPI_TBLPTR
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
name|UINT64
name|ACPI_PHYSICAL_ADDRESS
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|UINT32
name|ACPI_SIZE
typedef|;
end_typedef

begin_define
define|#
directive|define
name|ALIGNED_ADDRESS_BOUNDARY
value|0x00000004
end_define

begin_define
define|#
directive|define
name|_HW_ALIGNMENT_SUPPORT
end_define

begin_define
define|#
directive|define
name|ACPI_MAX_PTR
value|0xFFFFFFFF
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Miscellaneous common types  */
end_comment

begin_typedef
typedef|typedef
name|UINT32
name|UINT32_BIT
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|NATIVE_UINT
name|ACPI_PTRDIFF
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|char
name|NATIVE_CHAR
typedef|;
end_typedef

begin_comment
comment|/*  * Data type ranges  */
end_comment

begin_define
define|#
directive|define
name|ACPI_UINT8_MAX
value|(UINT8)  0xFF
end_define

begin_define
define|#
directive|define
name|ACPI_UINT16_MAX
value|(UINT16) 0xFFFF
end_define

begin_define
define|#
directive|define
name|ACPI_UINT32_MAX
value|(UINT32) 0xFFFFFFFF
end_define

begin_define
define|#
directive|define
name|ACPI_UINT64_MAX
value|(UINT64) 0xFFFFFFFFFFFFFFFF
end_define

begin_define
define|#
directive|define
name|ACPI_ASCII_MAX
value|0x7F
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|DEFINE_ALTERNATE_TYPES
end_ifdef

begin_comment
comment|/*  * Types used only in translated source, defined here to enable  * cross-platform compilation only.  */
end_comment

begin_typedef
typedef|typedef
name|INT32
name|s32
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|UINT8
name|u8
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|UINT16
name|u16
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|UINT32
name|u32
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|UINT64
name|u64
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*! [End] no source code translation !*/
end_comment

begin_comment
comment|/*  * Useful defines  */
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
comment|/*  * Local datatypes  */
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
comment|/* Actually a ptr to an Node */
end_comment

begin_typedef
typedef|typedef
struct|struct
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

begin_comment
comment|/*  * Acpi integer width. In ACPI version 1, integers are  * 32 bits.  In ACPI version 2, integers are 64 bits.  * Note that this pertains to the ACPI integer type only, not  * other integers used in the implementation of the ACPI CA  * subsystem.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|ACPI_NO_INTEGER64_SUPPORT
end_ifdef

begin_comment
comment|/* 32-bit integers only, no 64-bit support */
end_comment

begin_typedef
typedef|typedef
name|UINT32
name|ACPI_INTEGER
typedef|;
end_typedef

begin_define
define|#
directive|define
name|ACPI_INTEGER_MAX
value|ACPI_UINT32_MAX
end_define

begin_define
define|#
directive|define
name|ACPI_INTEGER_BIT_SIZE
value|32
end_define

begin_define
define|#
directive|define
name|ACPI_MAX_BCD_VALUE
value|99999999
end_define

begin_define
define|#
directive|define
name|ACPI_MAX_BCD_DIGITS
value|8
end_define

begin_define
define|#
directive|define
name|ACPI_MAX_DECIMAL_DIGITS
value|10
end_define

begin_define
define|#
directive|define
name|ACPI_USE_NATIVE_DIVIDE
end_define

begin_comment
comment|/* Use compiler native 32-bit divide */
end_comment

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* 64-bit integers */
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
name|ACPI_MAX_BCD_VALUE
value|9999999999999999
end_define

begin_define
define|#
directive|define
name|ACPI_MAX_BCD_DIGITS
value|16
end_define

begin_define
define|#
directive|define
name|ACPI_MAX_DECIMAL_DIGITS
value|19
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|_IA64
end_ifdef

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

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Constants with special meanings  */
end_comment

begin_define
define|#
directive|define
name|ACPI_ROOT_OBJECT
value|(ACPI_HANDLE) ACPI_PTR_ADD (char, NULL, ACPI_UINT32_MAX)
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
name|ACPI_INITIALIZED_OK
value|0x01
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
comment|/*  *  Table types.  These values are passed to the table related APIs  */
end_comment

begin_typedef
typedef|typedef
name|UINT32
name|ACPI_TABLE_TYPE
typedef|;
end_typedef

begin_define
define|#
directive|define
name|ACPI_TABLE_RSDP
value|(ACPI_TABLE_TYPE) 0
end_define

begin_define
define|#
directive|define
name|ACPI_TABLE_DSDT
value|(ACPI_TABLE_TYPE) 1
end_define

begin_define
define|#
directive|define
name|ACPI_TABLE_FADT
value|(ACPI_TABLE_TYPE) 2
end_define

begin_define
define|#
directive|define
name|ACPI_TABLE_FACS
value|(ACPI_TABLE_TYPE) 3
end_define

begin_define
define|#
directive|define
name|ACPI_TABLE_PSDT
value|(ACPI_TABLE_TYPE) 4
end_define

begin_define
define|#
directive|define
name|ACPI_TABLE_SSDT
value|(ACPI_TABLE_TYPE) 5
end_define

begin_define
define|#
directive|define
name|ACPI_TABLE_XSDT
value|(ACPI_TABLE_TYPE) 6
end_define

begin_define
define|#
directive|define
name|ACPI_TABLE_MAX
value|6
end_define

begin_define
define|#
directive|define
name|NUM_ACPI_TABLES
value|(ACPI_TABLE_MAX+1)
end_define

begin_comment
comment|/*  * Types associated with names.  The first group of  * values correspond to the definition of the ACPI  * ObjectType operator (See the ACPI Spec).  Therefore,  * only add to the first group if the spec changes.  *  * Types must be kept in sync with the AcpiNsProperties  * and AcpiNsTypeNames arrays  */
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
name|ACPI_TYPE_MAX
value|0x10
end_define

begin_comment
comment|/*  * This section contains object types that do not relate to the ACPI ObjectType operator.  * They are used for various internal purposes only.  If new predefined ACPI_TYPEs are  * added (via the ACPI specification), these internal types must move upwards.  * Also, values exceeding the largest official ACPI ObjectType must not overlap with  * defined AML opcodes.  */
end_comment

begin_define
define|#
directive|define
name|INTERNAL_TYPE_BEGIN
value|0x11
end_define

begin_define
define|#
directive|define
name|INTERNAL_TYPE_REGION_FIELD
value|0x11
end_define

begin_define
define|#
directive|define
name|INTERNAL_TYPE_BANK_FIELD
value|0x12
end_define

begin_define
define|#
directive|define
name|INTERNAL_TYPE_INDEX_FIELD
value|0x13
end_define

begin_define
define|#
directive|define
name|INTERNAL_TYPE_REFERENCE
value|0x14
end_define

begin_comment
comment|/* Arg#, Local#, Name, Debug; used only in descriptors */
end_comment

begin_define
define|#
directive|define
name|INTERNAL_TYPE_ALIAS
value|0x15
end_define

begin_define
define|#
directive|define
name|INTERNAL_TYPE_NOTIFY
value|0x16
end_define

begin_define
define|#
directive|define
name|INTERNAL_TYPE_ADDRESS_HANDLER
value|0x17
end_define

begin_define
define|#
directive|define
name|INTERNAL_TYPE_RESOURCE
value|0x18
end_define

begin_define
define|#
directive|define
name|INTERNAL_TYPE_RESOURCE_FIELD
value|0x19
end_define

begin_define
define|#
directive|define
name|INTERNAL_TYPE_NODE_MAX
value|0x19
end_define

begin_comment
comment|/* These are pseudo-types because there are never any namespace nodes with these types */
end_comment

begin_define
define|#
directive|define
name|INTERNAL_TYPE_FIELD_DEFN
value|0x1A
end_define

begin_comment
comment|/* Name, ByteConst, multiple FieldElement */
end_comment

begin_define
define|#
directive|define
name|INTERNAL_TYPE_BANK_FIELD_DEFN
value|0x1B
end_define

begin_comment
comment|/* 2 Name,DWordConst,ByteConst,multi FieldElement */
end_comment

begin_define
define|#
directive|define
name|INTERNAL_TYPE_INDEX_FIELD_DEFN
value|0x1C
end_define

begin_comment
comment|/* 2 Name, ByteConst, multiple FieldElement */
end_comment

begin_define
define|#
directive|define
name|INTERNAL_TYPE_IF
value|0x1D
end_define

begin_define
define|#
directive|define
name|INTERNAL_TYPE_ELSE
value|0x1E
end_define

begin_define
define|#
directive|define
name|INTERNAL_TYPE_WHILE
value|0x1F
end_define

begin_define
define|#
directive|define
name|INTERNAL_TYPE_SCOPE
value|0x20
end_define

begin_comment
comment|/* Name, multiple Node */
end_comment

begin_define
define|#
directive|define
name|INTERNAL_TYPE_DEF_ANY
value|0x21
end_define

begin_comment
comment|/* type is Any, suppress search of enclosing scopes */
end_comment

begin_define
define|#
directive|define
name|INTERNAL_TYPE_EXTRA
value|0x22
end_define

begin_define
define|#
directive|define
name|INTERNAL_TYPE_DATA
value|0x23
end_define

begin_define
define|#
directive|define
name|INTERNAL_TYPE_MAX
value|0x23
end_define

begin_define
define|#
directive|define
name|INTERNAL_TYPE_INVALID
value|0x24
end_define

begin_define
define|#
directive|define
name|ACPI_TYPE_NOT_FOUND
value|0xFF
end_define

begin_comment
comment|/*  * Bitmapped ACPI types  * Used internally only  */
end_comment

begin_define
define|#
directive|define
name|ACPI_BTYPE_ANY
value|0x00000000
end_define

begin_define
define|#
directive|define
name|ACPI_BTYPE_INTEGER
value|0x00000001
end_define

begin_define
define|#
directive|define
name|ACPI_BTYPE_STRING
value|0x00000002
end_define

begin_define
define|#
directive|define
name|ACPI_BTYPE_BUFFER
value|0x00000004
end_define

begin_define
define|#
directive|define
name|ACPI_BTYPE_PACKAGE
value|0x00000008
end_define

begin_define
define|#
directive|define
name|ACPI_BTYPE_FIELD_UNIT
value|0x00000010
end_define

begin_define
define|#
directive|define
name|ACPI_BTYPE_DEVICE
value|0x00000020
end_define

begin_define
define|#
directive|define
name|ACPI_BTYPE_EVENT
value|0x00000040
end_define

begin_define
define|#
directive|define
name|ACPI_BTYPE_METHOD
value|0x00000080
end_define

begin_define
define|#
directive|define
name|ACPI_BTYPE_MUTEX
value|0x00000100
end_define

begin_define
define|#
directive|define
name|ACPI_BTYPE_REGION
value|0x00000200
end_define

begin_define
define|#
directive|define
name|ACPI_BTYPE_POWER
value|0x00000400
end_define

begin_define
define|#
directive|define
name|ACPI_BTYPE_PROCESSOR
value|0x00000800
end_define

begin_define
define|#
directive|define
name|ACPI_BTYPE_THERMAL
value|0x00001000
end_define

begin_define
define|#
directive|define
name|ACPI_BTYPE_BUFFER_FIELD
value|0x00002000
end_define

begin_define
define|#
directive|define
name|ACPI_BTYPE_DDB_HANDLE
value|0x00004000
end_define

begin_define
define|#
directive|define
name|ACPI_BTYPE_DEBUG_OBJECT
value|0x00008000
end_define

begin_define
define|#
directive|define
name|ACPI_BTYPE_REFERENCE
value|0x00010000
end_define

begin_define
define|#
directive|define
name|ACPI_BTYPE_RESOURCE
value|0x00020000
end_define

begin_define
define|#
directive|define
name|ACPI_BTYPE_COMPUTE_DATA
value|(ACPI_BTYPE_INTEGER | ACPI_BTYPE_STRING | ACPI_BTYPE_BUFFER)
end_define

begin_define
define|#
directive|define
name|ACPI_BTYPE_DATA
value|(ACPI_BTYPE_COMPUTE_DATA  | ACPI_BTYPE_PACKAGE)
end_define

begin_define
define|#
directive|define
name|ACPI_BTYPE_DATA_REFERENCE
value|(ACPI_BTYPE_DATA | ACPI_BTYPE_REFERENCE | ACPI_BTYPE_DDB_HANDLE)
end_define

begin_define
define|#
directive|define
name|ACPI_BTYPE_DEVICE_OBJECTS
value|(ACPI_BTYPE_DEVICE | ACPI_BTYPE_THERMAL | ACPI_BTYPE_PROCESSOR)
end_define

begin_define
define|#
directive|define
name|ACPI_BTYPE_OBJECTS_AND_REFS
value|0x0001FFFF
end_define

begin_comment
comment|/* ARG or LOCAL */
end_comment

begin_define
define|#
directive|define
name|ACPI_BTYPE_ALL_OBJECTS
value|0x0000FFFF
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

begin_comment
comment|/*  * AcpiEvent Types: Fixed& General Purpose  */
end_comment

begin_typedef
typedef|typedef
name|UINT32
name|ACPI_EVENT_TYPE
typedef|;
end_typedef

begin_define
define|#
directive|define
name|ACPI_EVENT_FIXED
value|0
end_define

begin_define
define|#
directive|define
name|ACPI_EVENT_GPE
value|1
end_define

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
name|ACPI_EVENT_LEVEL_TRIGGERED
value|1
end_define

begin_define
define|#
directive|define
name|ACPI_EVENT_EDGE_TRIGGERED
value|2
end_define

begin_comment
comment|/*  * GPEs  */
end_comment

begin_define
define|#
directive|define
name|ACPI_EVENT_WAKE_ENABLE
value|0x1
end_define

begin_define
define|#
directive|define
name|ACPI_EVENT_WAKE_DISABLE
value|0x1
end_define

begin_comment
comment|/*  * AcpiEvent Status:  * -------------  * The encoding of ACPI_EVENT_STATUS is illustrated below.  * Note that a set bit (1) indicates the property is TRUE  * (e.g. if bit 0 is set then the event is enabled).  * +-------------+-+-+-+  * |   Bits 31:3 |2|1|0|  * +-------------+-+-+-+  *          |     | | |  *          |     | | +- Enabled?  *          |     | +--- Enabled for wake?  *          |     +----- Set?  *          +-----------<Reserved>  */
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
comment|/* Notify types */
end_comment

begin_define
define|#
directive|define
name|ACPI_SYSTEM_NOTIFY
value|0
end_define

begin_define
define|#
directive|define
name|ACPI_DEVICE_NOTIFY
value|1
end_define

begin_define
define|#
directive|define
name|ACPI_MAX_NOTIFY_HANDLER_TYPE
value|1
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

begin_comment
comment|/*  * External ACPI object definition  */
end_comment

begin_typedef
typedef|typedef
union|union
name|AcpiObj
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
name|NATIVE_CHAR
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
name|AcpiObj
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
name|AcpiObjList
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
comment|/*  * ACPI Table Info.  One per ACPI table _type_  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|AcpiTableInfo
block|{
name|UINT32
name|Count
decl_stmt|;
block|}
name|ACPI_TABLE_INFO
typedef|;
end_typedef

begin_comment
comment|/*  * System info returned by AcpiGetSystemInfo()  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_AcpiSysInfo
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
name|UINT32
name|NumTableTypes
decl_stmt|;
name|ACPI_TABLE_INFO
name|TableInfo
index|[
name|NUM_ACPI_TABLES
index|]
decl_stmt|;
block|}
name|ACPI_SYSTEM_INFO
typedef|;
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
name|ACPI_GPE_HANDLER
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

begin_comment
comment|/* Address Spaces (Operation Regions */
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
value|((ACPI_ADR_SPACE_HANDLER) NULL)
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
comment|/* Structure and flags for AcpiGetDeviceInfo */
end_comment

begin_define
define|#
directive|define
name|ACPI_VALID_HID
value|0x1
end_define

begin_define
define|#
directive|define
name|ACPI_VALID_UID
value|0x2
end_define

begin_define
define|#
directive|define
name|ACPI_VALID_ADR
value|0x4
end_define

begin_define
define|#
directive|define
name|ACPI_VALID_STA
value|0x8
end_define

begin_define
define|#
directive|define
name|ACPI_COMMON_OBJ_INFO
define|\
value|ACPI_OBJECT_TYPE            Type;
comment|/* ACPI object type */
value|\     ACPI_NAME                   Name
end_define

begin_comment
comment|/* ACPI object Name */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|ACPI_COMMON_OBJ_INFO
expr_stmt|;
block|}
name|ACPI_OBJ_INFO_HEADER
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|ACPI_COMMON_OBJ_INFO
expr_stmt|;
name|UINT32
name|Valid
decl_stmt|;
comment|/*  Are the next bits legit? */
name|NATIVE_CHAR
name|HardwareId
index|[
literal|9
index|]
decl_stmt|;
comment|/*  _HID value if any */
name|NATIVE_CHAR
name|UniqueId
index|[
literal|9
index|]
decl_stmt|;
comment|/*  _UID value if any */
name|ACPI_INTEGER
name|Address
decl_stmt|;
comment|/*  _ADR value if any */
name|UINT32
name|CurrentStatus
decl_stmt|;
comment|/*  _STA value */
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
name|UINT32
name|MappedLength
decl_stmt|;
block|}
name|ACPI_MEM_SPACE_CONTEXT
typedef|;
end_typedef

begin_comment
comment|/* Sleep states */
end_comment

begin_define
define|#
directive|define
name|ACPI_NUM_SLEEP_STATES
value|7
end_define

begin_comment
comment|/*  * Definitions for Resource Attributes  */
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
name|ACPI_EDGE_SENSITIVE
value|(UINT8) 0x00
end_define

begin_define
define|#
directive|define
name|ACPI_LEVEL_SENSITIVE
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
comment|/*  *  Structures used to describe device resources  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT32
name|EdgeLevel
decl_stmt|;
name|UINT32
name|ActiveHighLow
decl_stmt|;
name|UINT32
name|SharedExclusive
decl_stmt|;
name|UINT32
name|NumberOfInterrupts
decl_stmt|;
name|UINT32
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
block|{
name|UINT32
name|Type
decl_stmt|;
name|UINT32
name|BusMaster
decl_stmt|;
name|UINT32
name|Transfer
decl_stmt|;
name|UINT32
name|NumberOfChannels
decl_stmt|;
name|UINT32
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
block|{
name|UINT32
name|CompatibilityPriority
decl_stmt|;
name|UINT32
name|PerformanceRobustness
decl_stmt|;
block|}
name|ACPI_RESOURCE_START_DPF
typedef|;
end_typedef

begin_comment
comment|/*  * END_DEPENDENT_FUNCTIONS_RESOURCE struct is not  *  needed because it has no fields  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT32
name|IoDecode
decl_stmt|;
name|UINT32
name|MinBaseAddress
decl_stmt|;
name|UINT32
name|MaxBaseAddress
decl_stmt|;
name|UINT32
name|Alignment
decl_stmt|;
name|UINT32
name|RangeLength
decl_stmt|;
block|}
name|ACPI_RESOURCE_IO
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT32
name|BaseAddress
decl_stmt|;
name|UINT32
name|RangeLength
decl_stmt|;
block|}
name|ACPI_RESOURCE_FIXED_IO
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT32
name|Length
decl_stmt|;
name|UINT8
name|Reserved
index|[
literal|1
index|]
decl_stmt|;
block|}
name|ACPI_RESOURCE_VENDOR
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
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
block|{
name|UINT32
name|ReadWriteAttribute
decl_stmt|;
name|UINT32
name|MinBaseAddress
decl_stmt|;
name|UINT32
name|MaxBaseAddress
decl_stmt|;
name|UINT32
name|Alignment
decl_stmt|;
name|UINT32
name|RangeLength
decl_stmt|;
block|}
name|ACPI_RESOURCE_MEM24
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT32
name|ReadWriteAttribute
decl_stmt|;
name|UINT32
name|MinBaseAddress
decl_stmt|;
name|UINT32
name|MaxBaseAddress
decl_stmt|;
name|UINT32
name|Alignment
decl_stmt|;
name|UINT32
name|RangeLength
decl_stmt|;
block|}
name|ACPI_RESOURCE_MEM32
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT32
name|ReadWriteAttribute
decl_stmt|;
name|UINT32
name|RangeBaseAddress
decl_stmt|;
name|UINT32
name|RangeLength
decl_stmt|;
block|}
name|ACPI_RESOURCE_FIXED_MEM32
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT16
name|CacheAttribute
decl_stmt|;
name|UINT16
name|ReadWriteAttribute
decl_stmt|;
block|}
name|ACPI_MEMORY_ATTRIBUTE
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT16
name|RangeAttribute
decl_stmt|;
name|UINT16
name|Reserved
decl_stmt|;
block|}
name|ACPI_IO_ATTRIBUTE
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT16
name|Reserved1
decl_stmt|;
name|UINT16
name|Reserved2
decl_stmt|;
block|}
name|ACPI_BUS_ATTRIBUTE
typedef|;
end_typedef

begin_typedef
typedef|typedef
union|union
block|{
name|ACPI_MEMORY_ATTRIBUTE
name|Memory
decl_stmt|;
name|ACPI_IO_ATTRIBUTE
name|Io
decl_stmt|;
name|ACPI_BUS_ATTRIBUTE
name|Bus
decl_stmt|;
block|}
name|ACPI_RESOURCE_ATTRIBUTE
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT32
name|Index
decl_stmt|;
name|UINT32
name|StringLength
decl_stmt|;
name|NATIVE_CHAR
modifier|*
name|StringPtr
decl_stmt|;
block|}
name|ACPI_RESOURCE_SOURCE
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT32
name|ResourceType
decl_stmt|;
name|UINT32
name|ProducerConsumer
decl_stmt|;
name|UINT32
name|Decode
decl_stmt|;
name|UINT32
name|MinAddressFixed
decl_stmt|;
name|UINT32
name|MaxAddressFixed
decl_stmt|;
name|ACPI_RESOURCE_ATTRIBUTE
name|Attribute
decl_stmt|;
name|UINT32
name|Granularity
decl_stmt|;
name|UINT32
name|MinAddressRange
decl_stmt|;
name|UINT32
name|MaxAddressRange
decl_stmt|;
name|UINT32
name|AddressTranslationOffset
decl_stmt|;
name|UINT32
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
block|{
name|UINT32
name|ResourceType
decl_stmt|;
name|UINT32
name|ProducerConsumer
decl_stmt|;
name|UINT32
name|Decode
decl_stmt|;
name|UINT32
name|MinAddressFixed
decl_stmt|;
name|UINT32
name|MaxAddressFixed
decl_stmt|;
name|ACPI_RESOURCE_ATTRIBUTE
name|Attribute
decl_stmt|;
name|UINT32
name|Granularity
decl_stmt|;
name|UINT32
name|MinAddressRange
decl_stmt|;
name|UINT32
name|MaxAddressRange
decl_stmt|;
name|UINT32
name|AddressTranslationOffset
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
block|{
name|UINT32
name|ResourceType
decl_stmt|;
name|UINT32
name|ProducerConsumer
decl_stmt|;
name|UINT32
name|Decode
decl_stmt|;
name|UINT32
name|MinAddressFixed
decl_stmt|;
name|UINT32
name|MaxAddressFixed
decl_stmt|;
name|ACPI_RESOURCE_ATTRIBUTE
name|Attribute
decl_stmt|;
name|UINT64
name|Granularity
decl_stmt|;
name|UINT64
name|MinAddressRange
decl_stmt|;
name|UINT64
name|MaxAddressRange
decl_stmt|;
name|UINT64
name|AddressTranslationOffset
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
block|{
name|UINT32
name|ProducerConsumer
decl_stmt|;
name|UINT32
name|EdgeLevel
decl_stmt|;
name|UINT32
name|ActiveHighLow
decl_stmt|;
name|UINT32
name|SharedExclusive
decl_stmt|;
name|UINT32
name|NumberOfInterrupts
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
name|ACPI_RESOURCE_EXT_IRQ
typedef|;
end_typedef

begin_comment
comment|/* ACPI_RESOURCE_TYPEs */
end_comment

begin_define
define|#
directive|define
name|ACPI_RSTYPE_IRQ
value|0
end_define

begin_define
define|#
directive|define
name|ACPI_RSTYPE_DMA
value|1
end_define

begin_define
define|#
directive|define
name|ACPI_RSTYPE_START_DPF
value|2
end_define

begin_define
define|#
directive|define
name|ACPI_RSTYPE_END_DPF
value|3
end_define

begin_define
define|#
directive|define
name|ACPI_RSTYPE_IO
value|4
end_define

begin_define
define|#
directive|define
name|ACPI_RSTYPE_FIXED_IO
value|5
end_define

begin_define
define|#
directive|define
name|ACPI_RSTYPE_VENDOR
value|6
end_define

begin_define
define|#
directive|define
name|ACPI_RSTYPE_END_TAG
value|7
end_define

begin_define
define|#
directive|define
name|ACPI_RSTYPE_MEM24
value|8
end_define

begin_define
define|#
directive|define
name|ACPI_RSTYPE_MEM32
value|9
end_define

begin_define
define|#
directive|define
name|ACPI_RSTYPE_FIXED_MEM32
value|10
end_define

begin_define
define|#
directive|define
name|ACPI_RSTYPE_ADDRESS16
value|11
end_define

begin_define
define|#
directive|define
name|ACPI_RSTYPE_ADDRESS32
value|12
end_define

begin_define
define|#
directive|define
name|ACPI_RSTYPE_ADDRESS64
value|13
end_define

begin_define
define|#
directive|define
name|ACPI_RSTYPE_EXT_IRQ
value|14
end_define

begin_typedef
typedef|typedef
name|UINT32
name|ACPI_RESOURCE_TYPE
typedef|;
end_typedef

begin_typedef
typedef|typedef
union|union
block|{
name|ACPI_RESOURCE_IRQ
name|Irq
decl_stmt|;
name|ACPI_RESOURCE_DMA
name|Dma
decl_stmt|;
name|ACPI_RESOURCE_START_DPF
name|StartDpf
decl_stmt|;
name|ACPI_RESOURCE_IO
name|Io
decl_stmt|;
name|ACPI_RESOURCE_FIXED_IO
name|FixedIo
decl_stmt|;
name|ACPI_RESOURCE_VENDOR
name|VendorSpecific
decl_stmt|;
name|ACPI_RESOURCE_END_TAG
name|EndTag
decl_stmt|;
name|ACPI_RESOURCE_MEM24
name|Memory24
decl_stmt|;
name|ACPI_RESOURCE_MEM32
name|Memory32
decl_stmt|;
name|ACPI_RESOURCE_FIXED_MEM32
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
name|ACPI_RESOURCE_EXT_IRQ
name|ExtendedIrq
decl_stmt|;
block|}
name|ACPI_RESOURCE_DATA
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|AcpiResource
block|{
name|ACPI_RESOURCE_TYPE
name|Id
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

begin_define
define|#
directive|define
name|ACPI_RESOURCE_LENGTH
value|12
end_define

begin_define
define|#
directive|define
name|ACPI_RESOURCE_LENGTH_NO_DATA
value|8
end_define

begin_comment
comment|/* Id + Length fields */
end_comment

begin_define
define|#
directive|define
name|ACPI_SIZEOF_RESOURCE
parameter_list|(
name|Type
parameter_list|)
value|(ACPI_RESOURCE_LENGTH_NO_DATA + sizeof (Type))
end_define

begin_define
define|#
directive|define
name|ACPI_NEXT_RESOURCE
parameter_list|(
name|Res
parameter_list|)
value|(ACPI_RESOURCE *)((UINT8 *) Res + Res->length)
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|_HW_ALIGNMENT_SUPPORT
end_ifdef

begin_define
define|#
directive|define
name|ACPI_ALIGN_RESOURCE_SIZE
parameter_list|(
name|Length
parameter_list|)
value|(Length)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|ACPI_ALIGN_RESOURCE_SIZE
parameter_list|(
name|Length
parameter_list|)
value|ACPI_ROUND_UP_TO_NATIVE_WORD(Length)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * END: of definitions for Resource Attributes  */
end_comment

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
name|NATIVE_CHAR
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

begin_comment
comment|/*  * END: of definitions for PCI Routing tables  */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __ACTYPES_H__ */
end_comment

end_unit

