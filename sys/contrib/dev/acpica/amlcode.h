begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/******************************************************************************  *  * Name: amlcode.h - Definitions for AML, as included in "definition blocks"  *                   Declarations and definitions contained herein are derived  *                   directly from the ACPI specification.  *       $Revision: 1.86 $  *  *****************************************************************************/
end_comment

begin_comment
comment|/******************************************************************************  *  * 1. Copyright Notice  *  * Some or all of this work - Copyright (c) 1999 - 2007, Intel Corp.  * All rights reserved.  *  * 2. License  *  * 2.1. This is your license from Intel Corp. under its intellectual property  * rights.  You may have additional license terms from the party that provided  * you this software, covering your right to use that party's intellectual  * property rights.  *  * 2.2. Intel grants, free of charge, to any person ("Licensee") obtaining a  * copy of the source code appearing in this file ("Covered Code") an  * irrevocable, perpetual, worldwide license under Intel's copyrights in the  * base code distributed originally by Intel ("Original Intel Code") to copy,  * make derivatives, distribute, use and display any portion of the Covered  * Code in any form, with the right to sublicense such rights; and  *  * 2.3. Intel grants Licensee a non-exclusive and non-transferable patent  * license (with the right to sublicense), under only those claims of Intel  * patents that are infringed by the Original Intel Code, to make, use, sell,  * offer to sell, and import the Covered Code and derivative works thereof  * solely to the minimum extent necessary to exercise the above copyright  * license, and in no event shall the patent license extend to any additions  * to or modifications of the Original Intel Code.  No other license or right  * is granted directly or by implication, estoppel or otherwise;  *  * The above copyright and patent license is granted only if the following  * conditions are met:  *  * 3. Conditions  *  * 3.1. Redistribution of Source with Rights to Further Distribute Source.  * Redistribution of source code of any substantial portion of the Covered  * Code or modification with rights to further distribute source must include  * the above Copyright Notice, the above License, this list of Conditions,  * and the following Disclaimer and Export Compliance provision.  In addition,  * Licensee must cause all Covered Code to which Licensee contributes to  * contain a file documenting the changes Licensee made to create that Covered  * Code and the date of any change.  Licensee must include in that file the  * documentation of any changes made by any predecessor Licensee.  Licensee  * must include a prominent statement that the modification is derived,  * directly or indirectly, from Original Intel Code.  *  * 3.2. Redistribution of Source with no Rights to Further Distribute Source.  * Redistribution of source code of any substantial portion of the Covered  * Code or modification without rights to further distribute source must  * include the following Disclaimer and Export Compliance provision in the  * documentation and/or other materials provided with distribution.  In  * addition, Licensee may not authorize further sublicense of source of any  * portion of the Covered Code, and must include terms to the effect that the  * license from Licensee to its licensee is limited to the intellectual  * property embodied in the software Licensee provides to its licensee, and  * not to intellectual property embodied in modifications its licensee may  * make.  *  * 3.3. Redistribution of Executable. Redistribution in executable form of any  * substantial portion of the Covered Code or modification must reproduce the  * above Copyright Notice, and the following Disclaimer and Export Compliance  * provision in the documentation and/or other materials provided with the  * distribution.  *  * 3.4. Intel retains all right, title, and interest in and to the Original  * Intel Code.  *  * 3.5. Neither the name Intel nor any other trademark owned or controlled by  * Intel shall be used in advertising or otherwise to promote the sale, use or  * other dealings in products derived from or relating to the Covered Code  * without prior written authorization from Intel.  *  * 4. Disclaimer and Export Compliance  *  * 4.1. INTEL MAKES NO WARRANTY OF ANY KIND REGARDING ANY SOFTWARE PROVIDED  * HERE.  ANY SOFTWARE ORIGINATING FROM INTEL OR DERIVED FROM INTEL SOFTWARE  * IS PROVIDED "AS IS," AND INTEL WILL NOT PROVIDE ANY SUPPORT,  ASSISTANCE,  * INSTALLATION, TRAINING OR OTHER SERVICES.  INTEL WILL NOT PROVIDE ANY  * UPDATES, ENHANCEMENTS OR EXTENSIONS.  INTEL SPECIFICALLY DISCLAIMS ANY  * IMPLIED WARRANTIES OF MERCHANTABILITY, NONINFRINGEMENT AND FITNESS FOR A  * PARTICULAR PURPOSE.  *  * 4.2. IN NO EVENT SHALL INTEL HAVE ANY LIABILITY TO LICENSEE, ITS LICENSEES  * OR ANY OTHER THIRD PARTY, FOR ANY LOST PROFITS, LOST DATA, LOSS OF USE OR  * COSTS OF PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES, OR FOR ANY INDIRECT,  * SPECIAL OR CONSEQUENTIAL DAMAGES ARISING OUT OF THIS AGREEMENT, UNDER ANY  * CAUSE OF ACTION OR THEORY OF LIABILITY, AND IRRESPECTIVE OF WHETHER INTEL  * HAS ADVANCE NOTICE OF THE POSSIBILITY OF SUCH DAMAGES.  THESE LIMITATIONS  * SHALL APPLY NOTWITHSTANDING THE FAILURE OF THE ESSENTIAL PURPOSE OF ANY  * LIMITED REMEDY.  *  * 4.3. Licensee shall not export, either directly or indirectly, any of this  * software or system incorporating such software without first obtaining any  * required license or other approval from the U. S. Department of Commerce or  * any other agency or department of the United States Government.  In the  * event Licensee exports any such software from the United States or  * re-exports any such software from a foreign destination, Licensee shall  * ensure that the distribution and export/re-export of the software is in  * compliance with all laws, regulations, orders, or other restrictions of the  * U.S. Export Administration Regulations. Licensee agrees that neither it nor  * any of its subsidiaries will export/re-export any technical data, process,  * software, or service, directly or indirectly, to any country for which the  * United States government or any agency thereof requires an export license,  * other governmental approval, or letter of assurance, without first obtaining  * such license, approval or letter.  *  *****************************************************************************/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__AMLCODE_H__
end_ifndef

begin_define
define|#
directive|define
name|__AMLCODE_H__
end_define

begin_comment
comment|/* primary opcodes */
end_comment

begin_define
define|#
directive|define
name|AML_NULL_CHAR
value|(UINT16) 0x00
end_define

begin_define
define|#
directive|define
name|AML_ZERO_OP
value|(UINT16) 0x00
end_define

begin_define
define|#
directive|define
name|AML_ONE_OP
value|(UINT16) 0x01
end_define

begin_define
define|#
directive|define
name|AML_UNASSIGNED
value|(UINT16) 0x02
end_define

begin_define
define|#
directive|define
name|AML_ALIAS_OP
value|(UINT16) 0x06
end_define

begin_define
define|#
directive|define
name|AML_NAME_OP
value|(UINT16) 0x08
end_define

begin_define
define|#
directive|define
name|AML_BYTE_OP
value|(UINT16) 0x0a
end_define

begin_define
define|#
directive|define
name|AML_WORD_OP
value|(UINT16) 0x0b
end_define

begin_define
define|#
directive|define
name|AML_DWORD_OP
value|(UINT16) 0x0c
end_define

begin_define
define|#
directive|define
name|AML_STRING_OP
value|(UINT16) 0x0d
end_define

begin_define
define|#
directive|define
name|AML_QWORD_OP
value|(UINT16) 0x0e
end_define

begin_comment
comment|/* ACPI 2.0 */
end_comment

begin_define
define|#
directive|define
name|AML_SCOPE_OP
value|(UINT16) 0x10
end_define

begin_define
define|#
directive|define
name|AML_BUFFER_OP
value|(UINT16) 0x11
end_define

begin_define
define|#
directive|define
name|AML_PACKAGE_OP
value|(UINT16) 0x12
end_define

begin_define
define|#
directive|define
name|AML_VAR_PACKAGE_OP
value|(UINT16) 0x13
end_define

begin_comment
comment|/* ACPI 2.0 */
end_comment

begin_define
define|#
directive|define
name|AML_METHOD_OP
value|(UINT16) 0x14
end_define

begin_define
define|#
directive|define
name|AML_DUAL_NAME_PREFIX
value|(UINT16) 0x2e
end_define

begin_define
define|#
directive|define
name|AML_MULTI_NAME_PREFIX_OP
value|(UINT16) 0x2f
end_define

begin_define
define|#
directive|define
name|AML_NAME_CHAR_SUBSEQ
value|(UINT16) 0x30
end_define

begin_define
define|#
directive|define
name|AML_NAME_CHAR_FIRST
value|(UINT16) 0x41
end_define

begin_define
define|#
directive|define
name|AML_EXTENDED_OP_PREFIX
value|(UINT16) 0x5b
end_define

begin_define
define|#
directive|define
name|AML_ROOT_PREFIX
value|(UINT16) 0x5c
end_define

begin_define
define|#
directive|define
name|AML_PARENT_PREFIX
value|(UINT16) 0x5e
end_define

begin_define
define|#
directive|define
name|AML_LOCAL_OP
value|(UINT16) 0x60
end_define

begin_define
define|#
directive|define
name|AML_LOCAL0
value|(UINT16) 0x60
end_define

begin_define
define|#
directive|define
name|AML_LOCAL1
value|(UINT16) 0x61
end_define

begin_define
define|#
directive|define
name|AML_LOCAL2
value|(UINT16) 0x62
end_define

begin_define
define|#
directive|define
name|AML_LOCAL3
value|(UINT16) 0x63
end_define

begin_define
define|#
directive|define
name|AML_LOCAL4
value|(UINT16) 0x64
end_define

begin_define
define|#
directive|define
name|AML_LOCAL5
value|(UINT16) 0x65
end_define

begin_define
define|#
directive|define
name|AML_LOCAL6
value|(UINT16) 0x66
end_define

begin_define
define|#
directive|define
name|AML_LOCAL7
value|(UINT16) 0x67
end_define

begin_define
define|#
directive|define
name|AML_ARG_OP
value|(UINT16) 0x68
end_define

begin_define
define|#
directive|define
name|AML_ARG0
value|(UINT16) 0x68
end_define

begin_define
define|#
directive|define
name|AML_ARG1
value|(UINT16) 0x69
end_define

begin_define
define|#
directive|define
name|AML_ARG2
value|(UINT16) 0x6a
end_define

begin_define
define|#
directive|define
name|AML_ARG3
value|(UINT16) 0x6b
end_define

begin_define
define|#
directive|define
name|AML_ARG4
value|(UINT16) 0x6c
end_define

begin_define
define|#
directive|define
name|AML_ARG5
value|(UINT16) 0x6d
end_define

begin_define
define|#
directive|define
name|AML_ARG6
value|(UINT16) 0x6e
end_define

begin_define
define|#
directive|define
name|AML_STORE_OP
value|(UINT16) 0x70
end_define

begin_define
define|#
directive|define
name|AML_REF_OF_OP
value|(UINT16) 0x71
end_define

begin_define
define|#
directive|define
name|AML_ADD_OP
value|(UINT16) 0x72
end_define

begin_define
define|#
directive|define
name|AML_CONCAT_OP
value|(UINT16) 0x73
end_define

begin_define
define|#
directive|define
name|AML_SUBTRACT_OP
value|(UINT16) 0x74
end_define

begin_define
define|#
directive|define
name|AML_INCREMENT_OP
value|(UINT16) 0x75
end_define

begin_define
define|#
directive|define
name|AML_DECREMENT_OP
value|(UINT16) 0x76
end_define

begin_define
define|#
directive|define
name|AML_MULTIPLY_OP
value|(UINT16) 0x77
end_define

begin_define
define|#
directive|define
name|AML_DIVIDE_OP
value|(UINT16) 0x78
end_define

begin_define
define|#
directive|define
name|AML_SHIFT_LEFT_OP
value|(UINT16) 0x79
end_define

begin_define
define|#
directive|define
name|AML_SHIFT_RIGHT_OP
value|(UINT16) 0x7a
end_define

begin_define
define|#
directive|define
name|AML_BIT_AND_OP
value|(UINT16) 0x7b
end_define

begin_define
define|#
directive|define
name|AML_BIT_NAND_OP
value|(UINT16) 0x7c
end_define

begin_define
define|#
directive|define
name|AML_BIT_OR_OP
value|(UINT16) 0x7d
end_define

begin_define
define|#
directive|define
name|AML_BIT_NOR_OP
value|(UINT16) 0x7e
end_define

begin_define
define|#
directive|define
name|AML_BIT_XOR_OP
value|(UINT16) 0x7f
end_define

begin_define
define|#
directive|define
name|AML_BIT_NOT_OP
value|(UINT16) 0x80
end_define

begin_define
define|#
directive|define
name|AML_FIND_SET_LEFT_BIT_OP
value|(UINT16) 0x81
end_define

begin_define
define|#
directive|define
name|AML_FIND_SET_RIGHT_BIT_OP
value|(UINT16) 0x82
end_define

begin_define
define|#
directive|define
name|AML_DEREF_OF_OP
value|(UINT16) 0x83
end_define

begin_define
define|#
directive|define
name|AML_CONCAT_RES_OP
value|(UINT16) 0x84
end_define

begin_comment
comment|/* ACPI 2.0 */
end_comment

begin_define
define|#
directive|define
name|AML_MOD_OP
value|(UINT16) 0x85
end_define

begin_comment
comment|/* ACPI 2.0 */
end_comment

begin_define
define|#
directive|define
name|AML_NOTIFY_OP
value|(UINT16) 0x86
end_define

begin_define
define|#
directive|define
name|AML_SIZE_OF_OP
value|(UINT16) 0x87
end_define

begin_define
define|#
directive|define
name|AML_INDEX_OP
value|(UINT16) 0x88
end_define

begin_define
define|#
directive|define
name|AML_MATCH_OP
value|(UINT16) 0x89
end_define

begin_define
define|#
directive|define
name|AML_CREATE_DWORD_FIELD_OP
value|(UINT16) 0x8a
end_define

begin_define
define|#
directive|define
name|AML_CREATE_WORD_FIELD_OP
value|(UINT16) 0x8b
end_define

begin_define
define|#
directive|define
name|AML_CREATE_BYTE_FIELD_OP
value|(UINT16) 0x8c
end_define

begin_define
define|#
directive|define
name|AML_CREATE_BIT_FIELD_OP
value|(UINT16) 0x8d
end_define

begin_define
define|#
directive|define
name|AML_TYPE_OP
value|(UINT16) 0x8e
end_define

begin_define
define|#
directive|define
name|AML_CREATE_QWORD_FIELD_OP
value|(UINT16) 0x8f
end_define

begin_comment
comment|/* ACPI 2.0 */
end_comment

begin_define
define|#
directive|define
name|AML_LAND_OP
value|(UINT16) 0x90
end_define

begin_define
define|#
directive|define
name|AML_LOR_OP
value|(UINT16) 0x91
end_define

begin_define
define|#
directive|define
name|AML_LNOT_OP
value|(UINT16) 0x92
end_define

begin_define
define|#
directive|define
name|AML_LEQUAL_OP
value|(UINT16) 0x93
end_define

begin_define
define|#
directive|define
name|AML_LGREATER_OP
value|(UINT16) 0x94
end_define

begin_define
define|#
directive|define
name|AML_LLESS_OP
value|(UINT16) 0x95
end_define

begin_define
define|#
directive|define
name|AML_TO_BUFFER_OP
value|(UINT16) 0x96
end_define

begin_comment
comment|/* ACPI 2.0 */
end_comment

begin_define
define|#
directive|define
name|AML_TO_DECSTRING_OP
value|(UINT16) 0x97
end_define

begin_comment
comment|/* ACPI 2.0 */
end_comment

begin_define
define|#
directive|define
name|AML_TO_HEXSTRING_OP
value|(UINT16) 0x98
end_define

begin_comment
comment|/* ACPI 2.0 */
end_comment

begin_define
define|#
directive|define
name|AML_TO_INTEGER_OP
value|(UINT16) 0x99
end_define

begin_comment
comment|/* ACPI 2.0 */
end_comment

begin_define
define|#
directive|define
name|AML_TO_STRING_OP
value|(UINT16) 0x9c
end_define

begin_comment
comment|/* ACPI 2.0 */
end_comment

begin_define
define|#
directive|define
name|AML_COPY_OP
value|(UINT16) 0x9d
end_define

begin_comment
comment|/* ACPI 2.0 */
end_comment

begin_define
define|#
directive|define
name|AML_MID_OP
value|(UINT16) 0x9e
end_define

begin_comment
comment|/* ACPI 2.0 */
end_comment

begin_define
define|#
directive|define
name|AML_CONTINUE_OP
value|(UINT16) 0x9f
end_define

begin_comment
comment|/* ACPI 2.0 */
end_comment

begin_define
define|#
directive|define
name|AML_IF_OP
value|(UINT16) 0xa0
end_define

begin_define
define|#
directive|define
name|AML_ELSE_OP
value|(UINT16) 0xa1
end_define

begin_define
define|#
directive|define
name|AML_WHILE_OP
value|(UINT16) 0xa2
end_define

begin_define
define|#
directive|define
name|AML_NOOP_OP
value|(UINT16) 0xa3
end_define

begin_define
define|#
directive|define
name|AML_RETURN_OP
value|(UINT16) 0xa4
end_define

begin_define
define|#
directive|define
name|AML_BREAK_OP
value|(UINT16) 0xa5
end_define

begin_define
define|#
directive|define
name|AML_BREAK_POINT_OP
value|(UINT16) 0xcc
end_define

begin_define
define|#
directive|define
name|AML_ONES_OP
value|(UINT16) 0xff
end_define

begin_comment
comment|/* prefixed opcodes */
end_comment

begin_define
define|#
directive|define
name|AML_EXTENDED_OPCODE
value|(UINT16) 0x5b00
end_define

begin_comment
comment|/* prefix for 2-byte opcodes */
end_comment

begin_define
define|#
directive|define
name|AML_MUTEX_OP
value|(UINT16) 0x5b01
end_define

begin_define
define|#
directive|define
name|AML_EVENT_OP
value|(UINT16) 0x5b02
end_define

begin_define
define|#
directive|define
name|AML_SHIFT_RIGHT_BIT_OP
value|(UINT16) 0x5b10
end_define

begin_define
define|#
directive|define
name|AML_SHIFT_LEFT_BIT_OP
value|(UINT16) 0x5b11
end_define

begin_define
define|#
directive|define
name|AML_COND_REF_OF_OP
value|(UINT16) 0x5b12
end_define

begin_define
define|#
directive|define
name|AML_CREATE_FIELD_OP
value|(UINT16) 0x5b13
end_define

begin_define
define|#
directive|define
name|AML_LOAD_TABLE_OP
value|(UINT16) 0x5b1f
end_define

begin_comment
comment|/* ACPI 2.0 */
end_comment

begin_define
define|#
directive|define
name|AML_LOAD_OP
value|(UINT16) 0x5b20
end_define

begin_define
define|#
directive|define
name|AML_STALL_OP
value|(UINT16) 0x5b21
end_define

begin_define
define|#
directive|define
name|AML_SLEEP_OP
value|(UINT16) 0x5b22
end_define

begin_define
define|#
directive|define
name|AML_ACQUIRE_OP
value|(UINT16) 0x5b23
end_define

begin_define
define|#
directive|define
name|AML_SIGNAL_OP
value|(UINT16) 0x5b24
end_define

begin_define
define|#
directive|define
name|AML_WAIT_OP
value|(UINT16) 0x5b25
end_define

begin_define
define|#
directive|define
name|AML_RESET_OP
value|(UINT16) 0x5b26
end_define

begin_define
define|#
directive|define
name|AML_RELEASE_OP
value|(UINT16) 0x5b27
end_define

begin_define
define|#
directive|define
name|AML_FROM_BCD_OP
value|(UINT16) 0x5b28
end_define

begin_define
define|#
directive|define
name|AML_TO_BCD_OP
value|(UINT16) 0x5b29
end_define

begin_define
define|#
directive|define
name|AML_UNLOAD_OP
value|(UINT16) 0x5b2a
end_define

begin_define
define|#
directive|define
name|AML_REVISION_OP
value|(UINT16) 0x5b30
end_define

begin_define
define|#
directive|define
name|AML_DEBUG_OP
value|(UINT16) 0x5b31
end_define

begin_define
define|#
directive|define
name|AML_FATAL_OP
value|(UINT16) 0x5b32
end_define

begin_define
define|#
directive|define
name|AML_TIMER_OP
value|(UINT16) 0x5b33
end_define

begin_comment
comment|/* ACPI 3.0 */
end_comment

begin_define
define|#
directive|define
name|AML_REGION_OP
value|(UINT16) 0x5b80
end_define

begin_define
define|#
directive|define
name|AML_FIELD_OP
value|(UINT16) 0x5b81
end_define

begin_define
define|#
directive|define
name|AML_DEVICE_OP
value|(UINT16) 0x5b82
end_define

begin_define
define|#
directive|define
name|AML_PROCESSOR_OP
value|(UINT16) 0x5b83
end_define

begin_define
define|#
directive|define
name|AML_POWER_RES_OP
value|(UINT16) 0x5b84
end_define

begin_define
define|#
directive|define
name|AML_THERMAL_ZONE_OP
value|(UINT16) 0x5b85
end_define

begin_define
define|#
directive|define
name|AML_INDEX_FIELD_OP
value|(UINT16) 0x5b86
end_define

begin_define
define|#
directive|define
name|AML_BANK_FIELD_OP
value|(UINT16) 0x5b87
end_define

begin_define
define|#
directive|define
name|AML_DATA_REGION_OP
value|(UINT16) 0x5b88
end_define

begin_comment
comment|/* ACPI 2.0 */
end_comment

begin_comment
comment|/*  * Combination opcodes (actually two one-byte opcodes)  * Used by the disassembler and iASL compiler  */
end_comment

begin_define
define|#
directive|define
name|AML_LGREATEREQUAL_OP
value|(UINT16) 0x9295
end_define

begin_define
define|#
directive|define
name|AML_LLESSEQUAL_OP
value|(UINT16) 0x9294
end_define

begin_define
define|#
directive|define
name|AML_LNOTEQUAL_OP
value|(UINT16) 0x9293
end_define

begin_comment
comment|/*  * Internal opcodes  * Use only "Unknown" AML opcodes, don't attempt to use  * any valid ACPI ASCII values (A-Z, 0-9, '-')  */
end_comment

begin_define
define|#
directive|define
name|AML_INT_NAMEPATH_OP
value|(UINT16) 0x002d
end_define

begin_define
define|#
directive|define
name|AML_INT_NAMEDFIELD_OP
value|(UINT16) 0x0030
end_define

begin_define
define|#
directive|define
name|AML_INT_RESERVEDFIELD_OP
value|(UINT16) 0x0031
end_define

begin_define
define|#
directive|define
name|AML_INT_ACCESSFIELD_OP
value|(UINT16) 0x0032
end_define

begin_define
define|#
directive|define
name|AML_INT_BYTELIST_OP
value|(UINT16) 0x0033
end_define

begin_define
define|#
directive|define
name|AML_INT_STATICSTRING_OP
value|(UINT16) 0x0034
end_define

begin_define
define|#
directive|define
name|AML_INT_METHODCALL_OP
value|(UINT16) 0x0035
end_define

begin_define
define|#
directive|define
name|AML_INT_RETURN_VALUE_OP
value|(UINT16) 0x0036
end_define

begin_define
define|#
directive|define
name|AML_INT_EVAL_SUBTREE_OP
value|(UINT16) 0x0037
end_define

begin_define
define|#
directive|define
name|ARG_NONE
value|0x0
end_define

begin_comment
comment|/*  * Argument types for the AML Parser  * Each field in the ArgTypes UINT32 is 5 bits, allowing for a maximum of 6 arguments.  * There can be up to 31 unique argument types  * Zero is reserved as end-of-list indicator  */
end_comment

begin_define
define|#
directive|define
name|ARGP_BYTEDATA
value|0x01
end_define

begin_define
define|#
directive|define
name|ARGP_BYTELIST
value|0x02
end_define

begin_define
define|#
directive|define
name|ARGP_CHARLIST
value|0x03
end_define

begin_define
define|#
directive|define
name|ARGP_DATAOBJ
value|0x04
end_define

begin_define
define|#
directive|define
name|ARGP_DATAOBJLIST
value|0x05
end_define

begin_define
define|#
directive|define
name|ARGP_DWORDDATA
value|0x06
end_define

begin_define
define|#
directive|define
name|ARGP_FIELDLIST
value|0x07
end_define

begin_define
define|#
directive|define
name|ARGP_NAME
value|0x08
end_define

begin_define
define|#
directive|define
name|ARGP_NAMESTRING
value|0x09
end_define

begin_define
define|#
directive|define
name|ARGP_OBJLIST
value|0x0A
end_define

begin_define
define|#
directive|define
name|ARGP_PKGLENGTH
value|0x0B
end_define

begin_define
define|#
directive|define
name|ARGP_SUPERNAME
value|0x0C
end_define

begin_define
define|#
directive|define
name|ARGP_TARGET
value|0x0D
end_define

begin_define
define|#
directive|define
name|ARGP_TERMARG
value|0x0E
end_define

begin_define
define|#
directive|define
name|ARGP_TERMLIST
value|0x0F
end_define

begin_define
define|#
directive|define
name|ARGP_WORDDATA
value|0x10
end_define

begin_define
define|#
directive|define
name|ARGP_QWORDDATA
value|0x11
end_define

begin_define
define|#
directive|define
name|ARGP_SIMPLENAME
value|0x12
end_define

begin_comment
comment|/*  * Resolved argument types for the AML Interpreter  * Each field in the ArgTypes UINT32 is 5 bits, allowing for a maximum of 6 arguments.  * There can be up to 31 unique argument types (0 is end-of-arg-list indicator)  *  * Note1: These values are completely independent from the ACPI_TYPEs  *        i.e., ARGI_INTEGER != ACPI_TYPE_INTEGER  *  * Note2: If and when 5 bits becomes insufficient, it would probably be best  * to convert to a 6-byte array of argument types, allowing 8 bits per argument.  */
end_comment

begin_comment
comment|/* Single, simple types */
end_comment

begin_define
define|#
directive|define
name|ARGI_ANYTYPE
value|0x01
end_define

begin_comment
comment|/* Don't care */
end_comment

begin_define
define|#
directive|define
name|ARGI_PACKAGE
value|0x02
end_define

begin_define
define|#
directive|define
name|ARGI_EVENT
value|0x03
end_define

begin_define
define|#
directive|define
name|ARGI_MUTEX
value|0x04
end_define

begin_define
define|#
directive|define
name|ARGI_DDBHANDLE
value|0x05
end_define

begin_comment
comment|/* Interchangeable types (via implicit conversion) */
end_comment

begin_define
define|#
directive|define
name|ARGI_INTEGER
value|0x06
end_define

begin_define
define|#
directive|define
name|ARGI_STRING
value|0x07
end_define

begin_define
define|#
directive|define
name|ARGI_BUFFER
value|0x08
end_define

begin_define
define|#
directive|define
name|ARGI_BUFFER_OR_STRING
value|0x09
end_define

begin_comment
comment|/* Used by MID op only */
end_comment

begin_define
define|#
directive|define
name|ARGI_COMPUTEDATA
value|0x0A
end_define

begin_comment
comment|/* Buffer, String, or Integer */
end_comment

begin_comment
comment|/* Reference objects */
end_comment

begin_define
define|#
directive|define
name|ARGI_INTEGER_REF
value|0x0B
end_define

begin_define
define|#
directive|define
name|ARGI_OBJECT_REF
value|0x0C
end_define

begin_define
define|#
directive|define
name|ARGI_DEVICE_REF
value|0x0D
end_define

begin_define
define|#
directive|define
name|ARGI_REFERENCE
value|0x0E
end_define

begin_define
define|#
directive|define
name|ARGI_TARGETREF
value|0x0F
end_define

begin_comment
comment|/* Target, subject to implicit conversion */
end_comment

begin_define
define|#
directive|define
name|ARGI_FIXED_TARGET
value|0x10
end_define

begin_comment
comment|/* Target, no implicit conversion */
end_comment

begin_define
define|#
directive|define
name|ARGI_SIMPLE_TARGET
value|0x11
end_define

begin_comment
comment|/* Name, Local, Arg -- no implicit conversion */
end_comment

begin_comment
comment|/* Multiple/complex types */
end_comment

begin_define
define|#
directive|define
name|ARGI_DATAOBJECT
value|0x12
end_define

begin_comment
comment|/* Buffer, String, package or reference to a Node - Used only by SizeOf operator*/
end_comment

begin_define
define|#
directive|define
name|ARGI_COMPLEXOBJ
value|0x13
end_define

begin_comment
comment|/* Buffer, String, or package (Used by INDEX op only) */
end_comment

begin_define
define|#
directive|define
name|ARGI_REF_OR_STRING
value|0x14
end_define

begin_comment
comment|/* Reference or String (Used by DEREFOF op only) */
end_comment

begin_define
define|#
directive|define
name|ARGI_REGION_OR_BUFFER
value|0x15
end_define

begin_comment
comment|/* Used by LOAD op only */
end_comment

begin_define
define|#
directive|define
name|ARGI_DATAREFOBJ
value|0x16
end_define

begin_comment
comment|/* Note: types above can expand to 0x1F maximum */
end_comment

begin_define
define|#
directive|define
name|ARGI_INVALID_OPCODE
value|0xFFFFFFFF
end_define

begin_comment
comment|/*  * hash offsets  */
end_comment

begin_define
define|#
directive|define
name|AML_EXTOP_HASH_OFFSET
value|22
end_define

begin_define
define|#
directive|define
name|AML_LNOT_HASH_OFFSET
value|19
end_define

begin_comment
comment|/*  * opcode groups and types  */
end_comment

begin_define
define|#
directive|define
name|OPGRP_NAMED
value|0x01
end_define

begin_define
define|#
directive|define
name|OPGRP_FIELD
value|0x02
end_define

begin_define
define|#
directive|define
name|OPGRP_BYTELIST
value|0x04
end_define

begin_comment
comment|/*  * Opcode information  */
end_comment

begin_comment
comment|/* Opcode flags */
end_comment

begin_define
define|#
directive|define
name|AML_LOGICAL
value|0x0001
end_define

begin_define
define|#
directive|define
name|AML_LOGICAL_NUMERIC
value|0x0002
end_define

begin_define
define|#
directive|define
name|AML_MATH
value|0x0004
end_define

begin_define
define|#
directive|define
name|AML_CREATE
value|0x0008
end_define

begin_define
define|#
directive|define
name|AML_FIELD
value|0x0010
end_define

begin_define
define|#
directive|define
name|AML_DEFER
value|0x0020
end_define

begin_define
define|#
directive|define
name|AML_NAMED
value|0x0040
end_define

begin_define
define|#
directive|define
name|AML_NSNODE
value|0x0080
end_define

begin_define
define|#
directive|define
name|AML_NSOPCODE
value|0x0100
end_define

begin_define
define|#
directive|define
name|AML_NSOBJECT
value|0x0200
end_define

begin_define
define|#
directive|define
name|AML_HAS_RETVAL
value|0x0400
end_define

begin_define
define|#
directive|define
name|AML_HAS_TARGET
value|0x0800
end_define

begin_define
define|#
directive|define
name|AML_HAS_ARGS
value|0x1000
end_define

begin_define
define|#
directive|define
name|AML_CONSTANT
value|0x2000
end_define

begin_define
define|#
directive|define
name|AML_NO_OPERAND_RESOLVE
value|0x4000
end_define

begin_comment
comment|/* Convenient flag groupings */
end_comment

begin_define
define|#
directive|define
name|AML_FLAGS_EXEC_0A_0T_1R
value|AML_HAS_RETVAL
end_define

begin_define
define|#
directive|define
name|AML_FLAGS_EXEC_1A_0T_0R
value|AML_HAS_ARGS
end_define

begin_comment
comment|/* Monadic1  */
end_comment

begin_define
define|#
directive|define
name|AML_FLAGS_EXEC_1A_0T_1R
value|AML_HAS_ARGS |                  AML_HAS_RETVAL
end_define

begin_comment
comment|/* Monadic2  */
end_comment

begin_define
define|#
directive|define
name|AML_FLAGS_EXEC_1A_1T_0R
value|AML_HAS_ARGS | AML_HAS_TARGET
end_define

begin_define
define|#
directive|define
name|AML_FLAGS_EXEC_1A_1T_1R
value|AML_HAS_ARGS | AML_HAS_TARGET | AML_HAS_RETVAL
end_define

begin_comment
comment|/* Monadic2R */
end_comment

begin_define
define|#
directive|define
name|AML_FLAGS_EXEC_2A_0T_0R
value|AML_HAS_ARGS
end_define

begin_comment
comment|/* Dyadic1   */
end_comment

begin_define
define|#
directive|define
name|AML_FLAGS_EXEC_2A_0T_1R
value|AML_HAS_ARGS |                  AML_HAS_RETVAL
end_define

begin_comment
comment|/* Dyadic2   */
end_comment

begin_define
define|#
directive|define
name|AML_FLAGS_EXEC_2A_1T_1R
value|AML_HAS_ARGS | AML_HAS_TARGET | AML_HAS_RETVAL
end_define

begin_comment
comment|/* Dyadic2R  */
end_comment

begin_define
define|#
directive|define
name|AML_FLAGS_EXEC_2A_2T_1R
value|AML_HAS_ARGS | AML_HAS_TARGET | AML_HAS_RETVAL
end_define

begin_define
define|#
directive|define
name|AML_FLAGS_EXEC_3A_0T_0R
value|AML_HAS_ARGS
end_define

begin_define
define|#
directive|define
name|AML_FLAGS_EXEC_3A_1T_1R
value|AML_HAS_ARGS | AML_HAS_TARGET | AML_HAS_RETVAL
end_define

begin_define
define|#
directive|define
name|AML_FLAGS_EXEC_6A_0T_1R
value|AML_HAS_ARGS |                  AML_HAS_RETVAL
end_define

begin_comment
comment|/*  * The opcode Type is used in a dispatch table, do not change  * without updating the table.  */
end_comment

begin_define
define|#
directive|define
name|AML_TYPE_EXEC_0A_0T_1R
value|0x00
end_define

begin_define
define|#
directive|define
name|AML_TYPE_EXEC_1A_0T_0R
value|0x01
end_define

begin_comment
comment|/* Monadic1  */
end_comment

begin_define
define|#
directive|define
name|AML_TYPE_EXEC_1A_0T_1R
value|0x02
end_define

begin_comment
comment|/* Monadic2  */
end_comment

begin_define
define|#
directive|define
name|AML_TYPE_EXEC_1A_1T_0R
value|0x03
end_define

begin_define
define|#
directive|define
name|AML_TYPE_EXEC_1A_1T_1R
value|0x04
end_define

begin_comment
comment|/* Monadic2R */
end_comment

begin_define
define|#
directive|define
name|AML_TYPE_EXEC_2A_0T_0R
value|0x05
end_define

begin_comment
comment|/* Dyadic1   */
end_comment

begin_define
define|#
directive|define
name|AML_TYPE_EXEC_2A_0T_1R
value|0x06
end_define

begin_comment
comment|/* Dyadic2   */
end_comment

begin_define
define|#
directive|define
name|AML_TYPE_EXEC_2A_1T_1R
value|0x07
end_define

begin_comment
comment|/* Dyadic2R  */
end_comment

begin_define
define|#
directive|define
name|AML_TYPE_EXEC_2A_2T_1R
value|0x08
end_define

begin_define
define|#
directive|define
name|AML_TYPE_EXEC_3A_0T_0R
value|0x09
end_define

begin_define
define|#
directive|define
name|AML_TYPE_EXEC_3A_1T_1R
value|0x0A
end_define

begin_define
define|#
directive|define
name|AML_TYPE_EXEC_6A_0T_1R
value|0x0B
end_define

begin_comment
comment|/* End of types used in dispatch table */
end_comment

begin_define
define|#
directive|define
name|AML_TYPE_LITERAL
value|0x0B
end_define

begin_define
define|#
directive|define
name|AML_TYPE_CONSTANT
value|0x0C
end_define

begin_define
define|#
directive|define
name|AML_TYPE_METHOD_ARGUMENT
value|0x0D
end_define

begin_define
define|#
directive|define
name|AML_TYPE_LOCAL_VARIABLE
value|0x0E
end_define

begin_define
define|#
directive|define
name|AML_TYPE_DATA_TERM
value|0x0F
end_define

begin_comment
comment|/* Generic for an op that returns a value */
end_comment

begin_define
define|#
directive|define
name|AML_TYPE_METHOD_CALL
value|0x10
end_define

begin_comment
comment|/* Misc */
end_comment

begin_define
define|#
directive|define
name|AML_TYPE_CREATE_FIELD
value|0x11
end_define

begin_define
define|#
directive|define
name|AML_TYPE_CREATE_OBJECT
value|0x12
end_define

begin_define
define|#
directive|define
name|AML_TYPE_CONTROL
value|0x13
end_define

begin_define
define|#
directive|define
name|AML_TYPE_NAMED_NO_OBJ
value|0x14
end_define

begin_define
define|#
directive|define
name|AML_TYPE_NAMED_FIELD
value|0x15
end_define

begin_define
define|#
directive|define
name|AML_TYPE_NAMED_SIMPLE
value|0x16
end_define

begin_define
define|#
directive|define
name|AML_TYPE_NAMED_COMPLEX
value|0x17
end_define

begin_define
define|#
directive|define
name|AML_TYPE_RETURN
value|0x18
end_define

begin_define
define|#
directive|define
name|AML_TYPE_UNDEFINED
value|0x19
end_define

begin_define
define|#
directive|define
name|AML_TYPE_BOGUS
value|0x1A
end_define

begin_comment
comment|/* AML Package Length encodings */
end_comment

begin_define
define|#
directive|define
name|ACPI_AML_PACKAGE_TYPE1
value|0x40
end_define

begin_define
define|#
directive|define
name|ACPI_AML_PACKAGE_TYPE2
value|0x4000
end_define

begin_define
define|#
directive|define
name|ACPI_AML_PACKAGE_TYPE3
value|0x400000
end_define

begin_define
define|#
directive|define
name|ACPI_AML_PACKAGE_TYPE4
value|0x40000000
end_define

begin_comment
comment|/*  * Opcode classes  */
end_comment

begin_define
define|#
directive|define
name|AML_CLASS_EXECUTE
value|0x00
end_define

begin_define
define|#
directive|define
name|AML_CLASS_CREATE
value|0x01
end_define

begin_define
define|#
directive|define
name|AML_CLASS_ARGUMENT
value|0x02
end_define

begin_define
define|#
directive|define
name|AML_CLASS_NAMED_OBJECT
value|0x03
end_define

begin_define
define|#
directive|define
name|AML_CLASS_CONTROL
value|0x04
end_define

begin_define
define|#
directive|define
name|AML_CLASS_ASCII
value|0x05
end_define

begin_define
define|#
directive|define
name|AML_CLASS_PREFIX
value|0x06
end_define

begin_define
define|#
directive|define
name|AML_CLASS_INTERNAL
value|0x07
end_define

begin_define
define|#
directive|define
name|AML_CLASS_RETURN_VALUE
value|0x08
end_define

begin_define
define|#
directive|define
name|AML_CLASS_METHOD_CALL
value|0x09
end_define

begin_define
define|#
directive|define
name|AML_CLASS_UNKNOWN
value|0x0A
end_define

begin_comment
comment|/* Predefined Operation Region SpaceIDs */
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|REGION_MEMORY
init|=
literal|0
block|,
name|REGION_IO
block|,
name|REGION_PCI_CONFIG
block|,
name|REGION_EC
block|,
name|REGION_SMBUS
block|,
name|REGION_CMOS
block|,
name|REGION_PCI_BAR
block|,
name|REGION_DATA_TABLE
block|,
comment|/* Internal use only */
name|REGION_FIXED_HW
init|=
literal|0x7F
block|}
name|AML_REGION_TYPES
typedef|;
end_typedef

begin_comment
comment|/* Comparison operation codes for MatchOp operator */
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|MATCH_MTR
init|=
literal|0
block|,
name|MATCH_MEQ
init|=
literal|1
block|,
name|MATCH_MLE
init|=
literal|2
block|,
name|MATCH_MLT
init|=
literal|3
block|,
name|MATCH_MGE
init|=
literal|4
block|,
name|MATCH_MGT
init|=
literal|5
block|}
name|AML_MATCH_OPERATOR
typedef|;
end_typedef

begin_define
define|#
directive|define
name|MAX_MATCH_OPERATOR
value|5
end_define

begin_comment
comment|/*  * FieldFlags  *  * This byte is extracted from the AML and includes three separate  * pieces of information about the field:  * 1) The field access type  * 2) The field update rule  * 3) The lock rule for the field  *  * Bits 00 - 03 : AccessType (AnyAcc, ByteAcc, etc.)  *      04      : LockRule (1 == Lock)  *      05 - 06 : UpdateRule  */
end_comment

begin_define
define|#
directive|define
name|AML_FIELD_ACCESS_TYPE_MASK
value|0x0F
end_define

begin_define
define|#
directive|define
name|AML_FIELD_LOCK_RULE_MASK
value|0x10
end_define

begin_define
define|#
directive|define
name|AML_FIELD_UPDATE_RULE_MASK
value|0x60
end_define

begin_comment
comment|/* 1) Field Access Types */
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|AML_FIELD_ACCESS_ANY
init|=
literal|0x00
block|,
name|AML_FIELD_ACCESS_BYTE
init|=
literal|0x01
block|,
name|AML_FIELD_ACCESS_WORD
init|=
literal|0x02
block|,
name|AML_FIELD_ACCESS_DWORD
init|=
literal|0x03
block|,
name|AML_FIELD_ACCESS_QWORD
init|=
literal|0x04
block|,
comment|/* ACPI 2.0 */
name|AML_FIELD_ACCESS_BUFFER
init|=
literal|0x05
comment|/* ACPI 2.0 */
block|}
name|AML_ACCESS_TYPE
typedef|;
end_typedef

begin_comment
comment|/* 2) Field Lock Rules */
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|AML_FIELD_LOCK_NEVER
init|=
literal|0x00
block|,
name|AML_FIELD_LOCK_ALWAYS
init|=
literal|0x10
block|}
name|AML_LOCK_RULE
typedef|;
end_typedef

begin_comment
comment|/* 3) Field Update Rules */
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|AML_FIELD_UPDATE_PRESERVE
init|=
literal|0x00
block|,
name|AML_FIELD_UPDATE_WRITE_AS_ONES
init|=
literal|0x20
block|,
name|AML_FIELD_UPDATE_WRITE_AS_ZEROS
init|=
literal|0x40
block|}
name|AML_UPDATE_RULE
typedef|;
end_typedef

begin_comment
comment|/*  * Field Access Attributes.  * This byte is extracted from the AML via the  * AccessAs keyword  */
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|AML_FIELD_ATTRIB_SMB_QUICK
init|=
literal|0x02
block|,
name|AML_FIELD_ATTRIB_SMB_SEND_RCV
init|=
literal|0x04
block|,
name|AML_FIELD_ATTRIB_SMB_BYTE
init|=
literal|0x06
block|,
name|AML_FIELD_ATTRIB_SMB_WORD
init|=
literal|0x08
block|,
name|AML_FIELD_ATTRIB_SMB_BLOCK
init|=
literal|0x0A
block|,
name|AML_FIELD_ATTRIB_SMB_WORD_CALL
init|=
literal|0x0C
block|,
name|AML_FIELD_ATTRIB_SMB_BLOCK_CALL
init|=
literal|0x0D
block|}
name|AML_ACCESS_ATTRIBUTE
typedef|;
end_typedef

begin_comment
comment|/* Bit fields in MethodFlags byte */
end_comment

begin_define
define|#
directive|define
name|AML_METHOD_ARG_COUNT
value|0x07
end_define

begin_define
define|#
directive|define
name|AML_METHOD_SERIALIZED
value|0x08
end_define

begin_define
define|#
directive|define
name|AML_METHOD_SYNCH_LEVEL
value|0xF0
end_define

begin_comment
comment|/* METHOD_FLAGS_ARG_COUNT is not used internally, define additional flags */
end_comment

begin_define
define|#
directive|define
name|AML_METHOD_INTERNAL_ONLY
value|0x01
end_define

begin_define
define|#
directive|define
name|AML_METHOD_RESERVED1
value|0x02
end_define

begin_define
define|#
directive|define
name|AML_METHOD_RESERVED2
value|0x04
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __AMLCODE_H__ */
end_comment

end_unit

