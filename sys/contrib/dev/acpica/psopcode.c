begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/******************************************************************************  *  * Module Name: psopcode - Parser/Interpreter opcode information table  *              $Revision: 64 $  *  *****************************************************************************/
end_comment

begin_comment
comment|/******************************************************************************  *  * 1. Copyright Notice  *  * Some or all of this work - Copyright (c) 1999 - 2002, Intel Corp.  * All rights reserved.  *  * 2. License  *  * 2.1. This is your license from Intel Corp. under its intellectual property  * rights.  You may have additional license terms from the party that provided  * you this software, covering your right to use that party's intellectual  * property rights.  *  * 2.2. Intel grants, free of charge, to any person ("Licensee") obtaining a  * copy of the source code appearing in this file ("Covered Code") an  * irrevocable, perpetual, worldwide license under Intel's copyrights in the  * base code distributed originally by Intel ("Original Intel Code") to copy,  * make derivatives, distribute, use and display any portion of the Covered  * Code in any form, with the right to sublicense such rights; and  *  * 2.3. Intel grants Licensee a non-exclusive and non-transferable patent  * license (with the right to sublicense), under only those claims of Intel  * patents that are infringed by the Original Intel Code, to make, use, sell,  * offer to sell, and import the Covered Code and derivative works thereof  * solely to the minimum extent necessary to exercise the above copyright  * license, and in no event shall the patent license extend to any additions  * to or modifications of the Original Intel Code.  No other license or right  * is granted directly or by implication, estoppel or otherwise;  *  * The above copyright and patent license is granted only if the following  * conditions are met:  *  * 3. Conditions  *  * 3.1. Redistribution of Source with Rights to Further Distribute Source.  * Redistribution of source code of any substantial portion of the Covered  * Code or modification with rights to further distribute source must include  * the above Copyright Notice, the above License, this list of Conditions,  * and the following Disclaimer and Export Compliance provision.  In addition,  * Licensee must cause all Covered Code to which Licensee contributes to  * contain a file documenting the changes Licensee made to create that Covered  * Code and the date of any change.  Licensee must include in that file the  * documentation of any changes made by any predecessor Licensee.  Licensee  * must include a prominent statement that the modification is derived,  * directly or indirectly, from Original Intel Code.  *  * 3.2. Redistribution of Source with no Rights to Further Distribute Source.  * Redistribution of source code of any substantial portion of the Covered  * Code or modification without rights to further distribute source must  * include the following Disclaimer and Export Compliance provision in the  * documentation and/or other materials provided with distribution.  In  * addition, Licensee may not authorize further sublicense of source of any  * portion of the Covered Code, and must include terms to the effect that the  * license from Licensee to its licensee is limited to the intellectual  * property embodied in the software Licensee provides to its licensee, and  * not to intellectual property embodied in modifications its licensee may  * make.  *  * 3.3. Redistribution of Executable. Redistribution in executable form of any  * substantial portion of the Covered Code or modification must reproduce the  * above Copyright Notice, and the following Disclaimer and Export Compliance  * provision in the documentation and/or other materials provided with the  * distribution.  *  * 3.4. Intel retains all right, title, and interest in and to the Original  * Intel Code.  *  * 3.5. Neither the name Intel nor any other trademark owned or controlled by  * Intel shall be used in advertising or otherwise to promote the sale, use or  * other dealings in products derived from or relating to the Covered Code  * without prior written authorization from Intel.  *  * 4. Disclaimer and Export Compliance  *  * 4.1. INTEL MAKES NO WARRANTY OF ANY KIND REGARDING ANY SOFTWARE PROVIDED  * HERE.  ANY SOFTWARE ORIGINATING FROM INTEL OR DERIVED FROM INTEL SOFTWARE  * IS PROVIDED "AS IS," AND INTEL WILL NOT PROVIDE ANY SUPPORT,  ASSISTANCE,  * INSTALLATION, TRAINING OR OTHER SERVICES.  INTEL WILL NOT PROVIDE ANY  * UPDATES, ENHANCEMENTS OR EXTENSIONS.  INTEL SPECIFICALLY DISCLAIMS ANY  * IMPLIED WARRANTIES OF MERCHANTABILITY, NONINFRINGEMENT AND FITNESS FOR A  * PARTICULAR PURPOSE.  *  * 4.2. IN NO EVENT SHALL INTEL HAVE ANY LIABILITY TO LICENSEE, ITS LICENSEES  * OR ANY OTHER THIRD PARTY, FOR ANY LOST PROFITS, LOST DATA, LOSS OF USE OR  * COSTS OF PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES, OR FOR ANY INDIRECT,  * SPECIAL OR CONSEQUENTIAL DAMAGES ARISING OUT OF THIS AGREEMENT, UNDER ANY  * CAUSE OF ACTION OR THEORY OF LIABILITY, AND IRRESPECTIVE OF WHETHER INTEL  * HAS ADVANCE NOTICE OF THE POSSIBILITY OF SUCH DAMAGES.  THESE LIMITATIONS  * SHALL APPLY NOTWITHSTANDING THE FAILURE OF THE ESSENTIAL PURPOSE OF ANY  * LIMITED REMEDY.  *  * 4.3. Licensee shall not export, either directly or indirectly, any of this  * software or system incorporating such software without first obtaining any  * required license or other approval from the U. S. Department of Commerce or  * any other agency or department of the United States Government.  In the  * event Licensee exports any such software from the United States or  * re-exports any such software from a foreign destination, Licensee shall  * ensure that the distribution and export/re-export of the software is in  * compliance with all laws, regulations, orders, or other restrictions of the  * U.S. Export Administration Regulations. Licensee agrees that neither it nor  * any of its subsidiaries will export/re-export any technical data, process,  * software, or service, directly or indirectly, to any country for which the  * United States government or any agency thereof requires an export license,  * other governmental approval, or letter of assurance, without first obtaining  * such license, approval or letter.  *  *****************************************************************************/
end_comment

begin_include
include|#
directive|include
file|"acpi.h"
end_include

begin_include
include|#
directive|include
file|"acparser.h"
end_include

begin_include
include|#
directive|include
file|"amlcode.h"
end_include

begin_define
define|#
directive|define
name|_COMPONENT
value|ACPI_PARSER
end_define

begin_macro
name|ACPI_MODULE_NAME
argument_list|(
literal|"psopcode"
argument_list|)
end_macro

begin_define
define|#
directive|define
name|_UNK
value|0x6B
end_define

begin_comment
comment|/*  * Reserved ASCII characters.  Do not use any of these for  * internal opcodes, since they are used to differentiate  * name strings from AML opcodes  */
end_comment

begin_define
define|#
directive|define
name|_ASC
value|0x6C
end_define

begin_define
define|#
directive|define
name|_NAM
value|0x6C
end_define

begin_define
define|#
directive|define
name|_PFX
value|0x6D
end_define

begin_define
define|#
directive|define
name|_UNKNOWN_OPCODE
value|0x02
end_define

begin_comment
comment|/* An example unknown opcode */
end_comment

begin_define
define|#
directive|define
name|MAX_EXTENDED_OPCODE
value|0x88
end_define

begin_define
define|#
directive|define
name|NUM_EXTENDED_OPCODE
value|MAX_EXTENDED_OPCODE + 1
end_define

begin_define
define|#
directive|define
name|MAX_INTERNAL_OPCODE
end_define

begin_define
define|#
directive|define
name|NUM_INTERNAL_OPCODE
value|MAX_INTERNAL_OPCODE + 1
end_define

begin_comment
comment|/*******************************************************************************  *  * NAME:        AcpiGbl_AmlOpInfo  *  * DESCRIPTION: Opcode table. Each entry contains<opcode, type, name, operands>  *              The name is a simple ascii string, the operand specifier is an  *              ascii string with one letter per operand.  The letter specifies  *              the operand type.  *  ******************************************************************************/
end_comment

begin_comment
comment|/*  * All AML opcodes and the parse-time arguments for each.  Used by the AML parser  Each list is compressed  * into a 32-bit number and stored in the master opcode table at the end of this file.  */
end_comment

begin_define
define|#
directive|define
name|ARGP_ACCESSFIELD_OP
value|ARGP_LIST1 (ARGP_NAMESTRING)
end_define

begin_define
define|#
directive|define
name|ARGP_ACQUIRE_OP
value|ARGP_LIST2 (ARGP_SUPERNAME,  ARGP_WORDDATA)
end_define

begin_define
define|#
directive|define
name|ARGP_ADD_OP
value|ARGP_LIST3 (ARGP_TERMARG,    ARGP_TERMARG,       ARGP_TARGET)
end_define

begin_define
define|#
directive|define
name|ARGP_ALIAS_OP
value|ARGP_LIST2 (ARGP_NAMESTRING, ARGP_NAME)
end_define

begin_define
define|#
directive|define
name|ARGP_ARG0
value|ARG_NONE
end_define

begin_define
define|#
directive|define
name|ARGP_ARG1
value|ARG_NONE
end_define

begin_define
define|#
directive|define
name|ARGP_ARG2
value|ARG_NONE
end_define

begin_define
define|#
directive|define
name|ARGP_ARG3
value|ARG_NONE
end_define

begin_define
define|#
directive|define
name|ARGP_ARG4
value|ARG_NONE
end_define

begin_define
define|#
directive|define
name|ARGP_ARG5
value|ARG_NONE
end_define

begin_define
define|#
directive|define
name|ARGP_ARG6
value|ARG_NONE
end_define

begin_define
define|#
directive|define
name|ARGP_BANK_FIELD_OP
value|ARGP_LIST6 (ARGP_PKGLENGTH,  ARGP_NAMESTRING,    ARGP_NAMESTRING,ARGP_TERMARG,   ARGP_BYTEDATA,  ARGP_FIELDLIST)
end_define

begin_define
define|#
directive|define
name|ARGP_BIT_AND_OP
value|ARGP_LIST3 (ARGP_TERMARG,    ARGP_TERMARG,       ARGP_TARGET)
end_define

begin_define
define|#
directive|define
name|ARGP_BIT_NAND_OP
value|ARGP_LIST3 (ARGP_TERMARG,    ARGP_TERMARG,       ARGP_TARGET)
end_define

begin_define
define|#
directive|define
name|ARGP_BIT_NOR_OP
value|ARGP_LIST3 (ARGP_TERMARG,    ARGP_TERMARG,       ARGP_TARGET)
end_define

begin_define
define|#
directive|define
name|ARGP_BIT_NOT_OP
value|ARGP_LIST2 (ARGP_TERMARG,    ARGP_TARGET)
end_define

begin_define
define|#
directive|define
name|ARGP_BIT_OR_OP
value|ARGP_LIST3 (ARGP_TERMARG,    ARGP_TERMARG,       ARGP_TARGET)
end_define

begin_define
define|#
directive|define
name|ARGP_BIT_XOR_OP
value|ARGP_LIST3 (ARGP_TERMARG,    ARGP_TERMARG,       ARGP_TARGET)
end_define

begin_define
define|#
directive|define
name|ARGP_BREAK_OP
value|ARG_NONE
end_define

begin_define
define|#
directive|define
name|ARGP_BREAK_POINT_OP
value|ARG_NONE
end_define

begin_define
define|#
directive|define
name|ARGP_BUFFER_OP
value|ARGP_LIST3 (ARGP_PKGLENGTH,  ARGP_TERMARG,       ARGP_BYTELIST)
end_define

begin_define
define|#
directive|define
name|ARGP_BYTE_OP
value|ARGP_LIST1 (ARGP_BYTEDATA)
end_define

begin_define
define|#
directive|define
name|ARGP_BYTELIST_OP
value|ARGP_LIST1 (ARGP_NAMESTRING)
end_define

begin_define
define|#
directive|define
name|ARGP_CONCAT_OP
value|ARGP_LIST3 (ARGP_TERMARG,    ARGP_TERMARG,       ARGP_TARGET)
end_define

begin_define
define|#
directive|define
name|ARGP_CONCAT_RES_OP
value|ARGP_LIST3 (ARGP_TERMARG,    ARGP_TERMARG,       ARGP_TARGET)
end_define

begin_define
define|#
directive|define
name|ARGP_COND_REF_OF_OP
value|ARGP_LIST2 (ARGP_SUPERNAME,  ARGP_SUPERNAME)
end_define

begin_define
define|#
directive|define
name|ARGP_CONTINUE_OP
value|ARG_NONE
end_define

begin_define
define|#
directive|define
name|ARGP_COPY_OP
value|ARGP_LIST2 (ARGP_SUPERNAME,  ARGP_SIMPLENAME)
end_define

begin_define
define|#
directive|define
name|ARGP_CREATE_BIT_FIELD_OP
value|ARGP_LIST3 (ARGP_TERMARG,    ARGP_TERMARG,       ARGP_NAME)
end_define

begin_define
define|#
directive|define
name|ARGP_CREATE_BYTE_FIELD_OP
value|ARGP_LIST3 (ARGP_TERMARG,    ARGP_TERMARG,       ARGP_NAME)
end_define

begin_define
define|#
directive|define
name|ARGP_CREATE_DWORD_FIELD_OP
value|ARGP_LIST3 (ARGP_TERMARG,    ARGP_TERMARG,       ARGP_NAME)
end_define

begin_define
define|#
directive|define
name|ARGP_CREATE_FIELD_OP
value|ARGP_LIST4 (ARGP_TERMARG,    ARGP_TERMARG,       ARGP_TERMARG,   ARGP_NAME)
end_define

begin_define
define|#
directive|define
name|ARGP_CREATE_QWORD_FIELD_OP
value|ARGP_LIST3 (ARGP_TERMARG,    ARGP_TERMARG,       ARGP_NAME)
end_define

begin_define
define|#
directive|define
name|ARGP_CREATE_WORD_FIELD_OP
value|ARGP_LIST3 (ARGP_TERMARG,    ARGP_TERMARG,       ARGP_NAME)
end_define

begin_define
define|#
directive|define
name|ARGP_DATA_REGION_OP
value|ARGP_LIST4 (ARGP_NAME,       ARGP_TERMARG,       ARGP_TERMARG,   ARGP_TERMARG)
end_define

begin_define
define|#
directive|define
name|ARGP_DEBUG_OP
value|ARG_NONE
end_define

begin_define
define|#
directive|define
name|ARGP_DECREMENT_OP
value|ARGP_LIST1 (ARGP_SUPERNAME)
end_define

begin_define
define|#
directive|define
name|ARGP_DEREF_OF_OP
value|ARGP_LIST1 (ARGP_TERMARG)
end_define

begin_define
define|#
directive|define
name|ARGP_DEVICE_OP
value|ARGP_LIST3 (ARGP_PKGLENGTH,  ARGP_NAME,          ARGP_OBJLIST)
end_define

begin_define
define|#
directive|define
name|ARGP_DIVIDE_OP
value|ARGP_LIST4 (ARGP_TERMARG,    ARGP_TERMARG,       ARGP_TARGET,    ARGP_TARGET)
end_define

begin_define
define|#
directive|define
name|ARGP_DWORD_OP
value|ARGP_LIST1 (ARGP_DWORDDATA)
end_define

begin_define
define|#
directive|define
name|ARGP_ELSE_OP
value|ARGP_LIST2 (ARGP_PKGLENGTH,  ARGP_TERMLIST)
end_define

begin_define
define|#
directive|define
name|ARGP_EVENT_OP
value|ARGP_LIST1 (ARGP_NAME)
end_define

begin_define
define|#
directive|define
name|ARGP_FATAL_OP
value|ARGP_LIST3 (ARGP_BYTEDATA,   ARGP_DWORDDATA,     ARGP_TERMARG)
end_define

begin_define
define|#
directive|define
name|ARGP_FIELD_OP
value|ARGP_LIST4 (ARGP_PKGLENGTH,  ARGP_NAMESTRING,    ARGP_BYTEDATA,  ARGP_FIELDLIST)
end_define

begin_define
define|#
directive|define
name|ARGP_FIND_SET_LEFT_BIT_OP
value|ARGP_LIST2 (ARGP_TERMARG,    ARGP_TARGET)
end_define

begin_define
define|#
directive|define
name|ARGP_FIND_SET_RIGHT_BIT_OP
value|ARGP_LIST2 (ARGP_TERMARG,    ARGP_TARGET)
end_define

begin_define
define|#
directive|define
name|ARGP_FROM_BCD_OP
value|ARGP_LIST2 (ARGP_TERMARG,    ARGP_TARGET)
end_define

begin_define
define|#
directive|define
name|ARGP_IF_OP
value|ARGP_LIST3 (ARGP_PKGLENGTH,  ARGP_TERMARG,       ARGP_TERMLIST)
end_define

begin_define
define|#
directive|define
name|ARGP_INCREMENT_OP
value|ARGP_LIST1 (ARGP_SUPERNAME)
end_define

begin_define
define|#
directive|define
name|ARGP_INDEX_FIELD_OP
value|ARGP_LIST5 (ARGP_PKGLENGTH,  ARGP_NAMESTRING,    ARGP_NAMESTRING,ARGP_BYTEDATA,  ARGP_FIELDLIST)
end_define

begin_define
define|#
directive|define
name|ARGP_INDEX_OP
value|ARGP_LIST3 (ARGP_TERMARG,    ARGP_TERMARG,       ARGP_TARGET)
end_define

begin_define
define|#
directive|define
name|ARGP_LAND_OP
value|ARGP_LIST2 (ARGP_TERMARG,    ARGP_TERMARG)
end_define

begin_define
define|#
directive|define
name|ARGP_LEQUAL_OP
value|ARGP_LIST2 (ARGP_TERMARG,    ARGP_TERMARG)
end_define

begin_define
define|#
directive|define
name|ARGP_LGREATER_OP
value|ARGP_LIST2 (ARGP_TERMARG,    ARGP_TERMARG)
end_define

begin_define
define|#
directive|define
name|ARGP_LGREATEREQUAL_OP
value|ARGP_LIST2 (ARGP_TERMARG,    ARGP_TERMARG)
end_define

begin_define
define|#
directive|define
name|ARGP_LLESS_OP
value|ARGP_LIST2 (ARGP_TERMARG,    ARGP_TERMARG)
end_define

begin_define
define|#
directive|define
name|ARGP_LLESSEQUAL_OP
value|ARGP_LIST2 (ARGP_TERMARG,    ARGP_TERMARG)
end_define

begin_define
define|#
directive|define
name|ARGP_LNOT_OP
value|ARGP_LIST1 (ARGP_TERMARG)
end_define

begin_define
define|#
directive|define
name|ARGP_LNOTEQUAL_OP
value|ARGP_LIST2 (ARGP_TERMARG,    ARGP_TERMARG)
end_define

begin_define
define|#
directive|define
name|ARGP_LOAD_OP
value|ARGP_LIST2 (ARGP_NAMESTRING, ARGP_SUPERNAME)
end_define

begin_define
define|#
directive|define
name|ARGP_LOAD_TABLE_OP
value|ARGP_LIST6 (ARGP_TERMARG,    ARGP_TERMARG,       ARGP_TERMARG,   ARGP_TERMARG,  ARGP_TERMARG,   ARGP_TERMARG)
end_define

begin_define
define|#
directive|define
name|ARGP_LOCAL0
value|ARG_NONE
end_define

begin_define
define|#
directive|define
name|ARGP_LOCAL1
value|ARG_NONE
end_define

begin_define
define|#
directive|define
name|ARGP_LOCAL2
value|ARG_NONE
end_define

begin_define
define|#
directive|define
name|ARGP_LOCAL3
value|ARG_NONE
end_define

begin_define
define|#
directive|define
name|ARGP_LOCAL4
value|ARG_NONE
end_define

begin_define
define|#
directive|define
name|ARGP_LOCAL5
value|ARG_NONE
end_define

begin_define
define|#
directive|define
name|ARGP_LOCAL6
value|ARG_NONE
end_define

begin_define
define|#
directive|define
name|ARGP_LOCAL7
value|ARG_NONE
end_define

begin_define
define|#
directive|define
name|ARGP_LOR_OP
value|ARGP_LIST2 (ARGP_TERMARG,    ARGP_TERMARG)
end_define

begin_define
define|#
directive|define
name|ARGP_MATCH_OP
value|ARGP_LIST6 (ARGP_TERMARG,    ARGP_BYTEDATA,      ARGP_TERMARG,   ARGP_BYTEDATA,  ARGP_TERMARG,   ARGP_TERMARG)
end_define

begin_define
define|#
directive|define
name|ARGP_METHOD_OP
value|ARGP_LIST4 (ARGP_PKGLENGTH,  ARGP_NAME,          ARGP_BYTEDATA,  ARGP_TERMLIST)
end_define

begin_define
define|#
directive|define
name|ARGP_METHODCALL_OP
value|ARGP_LIST1 (ARGP_NAMESTRING)
end_define

begin_define
define|#
directive|define
name|ARGP_MID_OP
value|ARGP_LIST4 (ARGP_TERMARG,    ARGP_TERMARG,       ARGP_TERMARG,   ARGP_TARGET)
end_define

begin_define
define|#
directive|define
name|ARGP_MOD_OP
value|ARGP_LIST3 (ARGP_TERMARG,    ARGP_TERMARG,       ARGP_TARGET)
end_define

begin_define
define|#
directive|define
name|ARGP_MULTIPLY_OP
value|ARGP_LIST3 (ARGP_TERMARG,    ARGP_TERMARG,       ARGP_TARGET)
end_define

begin_define
define|#
directive|define
name|ARGP_MUTEX_OP
value|ARGP_LIST2 (ARGP_NAME,       ARGP_BYTEDATA)
end_define

begin_define
define|#
directive|define
name|ARGP_NAME_OP
value|ARGP_LIST2 (ARGP_NAME,       ARGP_DATAOBJ)
end_define

begin_define
define|#
directive|define
name|ARGP_NAMEDFIELD_OP
value|ARGP_LIST1 (ARGP_NAMESTRING)
end_define

begin_define
define|#
directive|define
name|ARGP_NAMEPATH_OP
value|ARGP_LIST1 (ARGP_NAMESTRING)
end_define

begin_define
define|#
directive|define
name|ARGP_NOOP_OP
value|ARG_NONE
end_define

begin_define
define|#
directive|define
name|ARGP_NOTIFY_OP
value|ARGP_LIST2 (ARGP_SUPERNAME,  ARGP_TERMARG)
end_define

begin_define
define|#
directive|define
name|ARGP_ONE_OP
value|ARG_NONE
end_define

begin_define
define|#
directive|define
name|ARGP_ONES_OP
value|ARG_NONE
end_define

begin_define
define|#
directive|define
name|ARGP_PACKAGE_OP
value|ARGP_LIST3 (ARGP_PKGLENGTH,  ARGP_BYTEDATA,      ARGP_DATAOBJLIST)
end_define

begin_define
define|#
directive|define
name|ARGP_POWER_RES_OP
value|ARGP_LIST5 (ARGP_PKGLENGTH,  ARGP_NAME,          ARGP_BYTEDATA,  ARGP_WORDDATA,  ARGP_OBJLIST)
end_define

begin_define
define|#
directive|define
name|ARGP_PROCESSOR_OP
value|ARGP_LIST6 (ARGP_PKGLENGTH,  ARGP_NAME,          ARGP_BYTEDATA,  ARGP_DWORDDATA, ARGP_BYTEDATA,  ARGP_OBJLIST)
end_define

begin_define
define|#
directive|define
name|ARGP_QWORD_OP
value|ARGP_LIST1 (ARGP_QWORDDATA)
end_define

begin_define
define|#
directive|define
name|ARGP_REF_OF_OP
value|ARGP_LIST1 (ARGP_SUPERNAME)
end_define

begin_define
define|#
directive|define
name|ARGP_REGION_OP
value|ARGP_LIST4 (ARGP_NAME,       ARGP_BYTEDATA,      ARGP_TERMARG,   ARGP_TERMARG)
end_define

begin_define
define|#
directive|define
name|ARGP_RELEASE_OP
value|ARGP_LIST1 (ARGP_SUPERNAME)
end_define

begin_define
define|#
directive|define
name|ARGP_RESERVEDFIELD_OP
value|ARGP_LIST1 (ARGP_NAMESTRING)
end_define

begin_define
define|#
directive|define
name|ARGP_RESET_OP
value|ARGP_LIST1 (ARGP_SUPERNAME)
end_define

begin_define
define|#
directive|define
name|ARGP_RETURN_OP
value|ARGP_LIST1 (ARGP_TERMARG)
end_define

begin_define
define|#
directive|define
name|ARGP_REVISION_OP
value|ARG_NONE
end_define

begin_define
define|#
directive|define
name|ARGP_SCOPE_OP
value|ARGP_LIST3 (ARGP_PKGLENGTH,  ARGP_NAME,          ARGP_TERMLIST)
end_define

begin_define
define|#
directive|define
name|ARGP_SHIFT_LEFT_OP
value|ARGP_LIST3 (ARGP_TERMARG,    ARGP_TERMARG,       ARGP_TARGET)
end_define

begin_define
define|#
directive|define
name|ARGP_SHIFT_RIGHT_OP
value|ARGP_LIST3 (ARGP_TERMARG,    ARGP_TERMARG,       ARGP_TARGET)
end_define

begin_define
define|#
directive|define
name|ARGP_SIGNAL_OP
value|ARGP_LIST1 (ARGP_SUPERNAME)
end_define

begin_define
define|#
directive|define
name|ARGP_SIZE_OF_OP
value|ARGP_LIST1 (ARGP_SUPERNAME)
end_define

begin_define
define|#
directive|define
name|ARGP_SLEEP_OP
value|ARGP_LIST1 (ARGP_TERMARG)
end_define

begin_define
define|#
directive|define
name|ARGP_STALL_OP
value|ARGP_LIST1 (ARGP_TERMARG)
end_define

begin_define
define|#
directive|define
name|ARGP_STATICSTRING_OP
value|ARGP_LIST1 (ARGP_NAMESTRING)
end_define

begin_define
define|#
directive|define
name|ARGP_STORE_OP
value|ARGP_LIST2 (ARGP_TERMARG,    ARGP_SUPERNAME)
end_define

begin_define
define|#
directive|define
name|ARGP_STRING_OP
value|ARGP_LIST1 (ARGP_CHARLIST)
end_define

begin_define
define|#
directive|define
name|ARGP_SUBTRACT_OP
value|ARGP_LIST3 (ARGP_TERMARG,    ARGP_TERMARG,       ARGP_TARGET)
end_define

begin_define
define|#
directive|define
name|ARGP_THERMAL_ZONE_OP
value|ARGP_LIST3 (ARGP_PKGLENGTH,  ARGP_NAME,          ARGP_OBJLIST)
end_define

begin_define
define|#
directive|define
name|ARGP_TO_BCD_OP
value|ARGP_LIST2 (ARGP_TERMARG,    ARGP_TARGET)
end_define

begin_define
define|#
directive|define
name|ARGP_TO_BUFFER_OP
value|ARGP_LIST2 (ARGP_TERMARG,    ARGP_TARGET)
end_define

begin_define
define|#
directive|define
name|ARGP_TO_DEC_STR_OP
value|ARGP_LIST2 (ARGP_TERMARG,    ARGP_TARGET)
end_define

begin_define
define|#
directive|define
name|ARGP_TO_HEX_STR_OP
value|ARGP_LIST2 (ARGP_TERMARG,    ARGP_TARGET)
end_define

begin_define
define|#
directive|define
name|ARGP_TO_INTEGER_OP
value|ARGP_LIST2 (ARGP_TERMARG,    ARGP_TARGET)
end_define

begin_define
define|#
directive|define
name|ARGP_TO_STRING_OP
value|ARGP_LIST3 (ARGP_TERMARG,    ARGP_TERMARG,       ARGP_TARGET)
end_define

begin_define
define|#
directive|define
name|ARGP_TYPE_OP
value|ARGP_LIST1 (ARGP_SUPERNAME)
end_define

begin_define
define|#
directive|define
name|ARGP_UNLOAD_OP
value|ARGP_LIST1 (ARGP_SUPERNAME)
end_define

begin_define
define|#
directive|define
name|ARGP_VAR_PACKAGE_OP
value|ARGP_LIST3 (ARGP_PKGLENGTH,  ARGP_TERMARG,       ARGP_DATAOBJLIST)
end_define

begin_define
define|#
directive|define
name|ARGP_WAIT_OP
value|ARGP_LIST2 (ARGP_SUPERNAME,  ARGP_TERMARG)
end_define

begin_define
define|#
directive|define
name|ARGP_WHILE_OP
value|ARGP_LIST3 (ARGP_PKGLENGTH,  ARGP_TERMARG,       ARGP_TERMLIST)
end_define

begin_define
define|#
directive|define
name|ARGP_WORD_OP
value|ARGP_LIST1 (ARGP_WORDDATA)
end_define

begin_define
define|#
directive|define
name|ARGP_ZERO_OP
value|ARG_NONE
end_define

begin_comment
comment|/*  * All AML opcodes and the runtime arguments for each.  Used by the AML interpreter  Each list is compressed  * into a 32-bit number and stored in the master opcode table at the end of this file.  *  * (Used by PrepOperands procedure and the ASL Compiler)  */
end_comment

begin_define
define|#
directive|define
name|ARGI_ACCESSFIELD_OP
value|ARGI_INVALID_OPCODE
end_define

begin_define
define|#
directive|define
name|ARGI_ACQUIRE_OP
value|ARGI_LIST2 (ARGI_MUTEX,      ARGI_INTEGER)
end_define

begin_define
define|#
directive|define
name|ARGI_ADD_OP
value|ARGI_LIST3 (ARGI_INTEGER,    ARGI_INTEGER,       ARGI_TARGETREF)
end_define

begin_define
define|#
directive|define
name|ARGI_ALIAS_OP
value|ARGI_INVALID_OPCODE
end_define

begin_define
define|#
directive|define
name|ARGI_ARG0
value|ARG_NONE
end_define

begin_define
define|#
directive|define
name|ARGI_ARG1
value|ARG_NONE
end_define

begin_define
define|#
directive|define
name|ARGI_ARG2
value|ARG_NONE
end_define

begin_define
define|#
directive|define
name|ARGI_ARG3
value|ARG_NONE
end_define

begin_define
define|#
directive|define
name|ARGI_ARG4
value|ARG_NONE
end_define

begin_define
define|#
directive|define
name|ARGI_ARG5
value|ARG_NONE
end_define

begin_define
define|#
directive|define
name|ARGI_ARG6
value|ARG_NONE
end_define

begin_define
define|#
directive|define
name|ARGI_BANK_FIELD_OP
value|ARGI_INVALID_OPCODE
end_define

begin_define
define|#
directive|define
name|ARGI_BIT_AND_OP
value|ARGI_LIST3 (ARGI_INTEGER,    ARGI_INTEGER,       ARGI_TARGETREF)
end_define

begin_define
define|#
directive|define
name|ARGI_BIT_NAND_OP
value|ARGI_LIST3 (ARGI_INTEGER,    ARGI_INTEGER,       ARGI_TARGETREF)
end_define

begin_define
define|#
directive|define
name|ARGI_BIT_NOR_OP
value|ARGI_LIST3 (ARGI_INTEGER,    ARGI_INTEGER,       ARGI_TARGETREF)
end_define

begin_define
define|#
directive|define
name|ARGI_BIT_NOT_OP
value|ARGI_LIST2 (ARGI_INTEGER,    ARGI_TARGETREF)
end_define

begin_define
define|#
directive|define
name|ARGI_BIT_OR_OP
value|ARGI_LIST3 (ARGI_INTEGER,    ARGI_INTEGER,       ARGI_TARGETREF)
end_define

begin_define
define|#
directive|define
name|ARGI_BIT_XOR_OP
value|ARGI_LIST3 (ARGI_INTEGER,    ARGI_INTEGER,       ARGI_TARGETREF)
end_define

begin_define
define|#
directive|define
name|ARGI_BREAK_OP
value|ARG_NONE
end_define

begin_define
define|#
directive|define
name|ARGI_BREAK_POINT_OP
value|ARG_NONE
end_define

begin_define
define|#
directive|define
name|ARGI_BUFFER_OP
value|ARGI_INVALID_OPCODE
end_define

begin_define
define|#
directive|define
name|ARGI_BYTE_OP
value|ARGI_INVALID_OPCODE
end_define

begin_define
define|#
directive|define
name|ARGI_BYTELIST_OP
value|ARGI_INVALID_OPCODE
end_define

begin_define
define|#
directive|define
name|ARGI_CONCAT_OP
value|ARGI_LIST3 (ARGI_COMPUTEDATA,ARGI_COMPUTEDATA,   ARGI_TARGETREF)
end_define

begin_define
define|#
directive|define
name|ARGI_CONCAT_RES_OP
value|ARGI_LIST3 (ARGI_BUFFER,     ARGI_BUFFER,        ARGI_TARGETREF)
end_define

begin_define
define|#
directive|define
name|ARGI_COND_REF_OF_OP
value|ARGI_LIST2 (ARGI_OBJECT_REF, ARGI_TARGETREF)
end_define

begin_define
define|#
directive|define
name|ARGI_CONTINUE_OP
value|ARGI_INVALID_OPCODE
end_define

begin_define
define|#
directive|define
name|ARGI_COPY_OP
value|ARGI_LIST2 (ARGI_ANYTYPE,    ARGI_SIMPLE_TARGET)
end_define

begin_define
define|#
directive|define
name|ARGI_CREATE_BIT_FIELD_OP
value|ARGI_LIST3 (ARGI_BUFFER,     ARGI_INTEGER,       ARGI_REFERENCE)
end_define

begin_define
define|#
directive|define
name|ARGI_CREATE_BYTE_FIELD_OP
value|ARGI_LIST3 (ARGI_BUFFER,     ARGI_INTEGER,       ARGI_REFERENCE)
end_define

begin_define
define|#
directive|define
name|ARGI_CREATE_DWORD_FIELD_OP
value|ARGI_LIST3 (ARGI_BUFFER,     ARGI_INTEGER,       ARGI_REFERENCE)
end_define

begin_define
define|#
directive|define
name|ARGI_CREATE_FIELD_OP
value|ARGI_LIST4 (ARGI_BUFFER,     ARGI_INTEGER,       ARGI_INTEGER,      ARGI_REFERENCE)
end_define

begin_define
define|#
directive|define
name|ARGI_CREATE_QWORD_FIELD_OP
value|ARGI_LIST3 (ARGI_BUFFER,     ARGI_INTEGER,       ARGI_REFERENCE)
end_define

begin_define
define|#
directive|define
name|ARGI_CREATE_WORD_FIELD_OP
value|ARGI_LIST3 (ARGI_BUFFER,     ARGI_INTEGER,       ARGI_REFERENCE)
end_define

begin_define
define|#
directive|define
name|ARGI_DATA_REGION_OP
value|ARGI_LIST3 (ARGI_STRING,     ARGI_STRING,       ARGI_STRING)
end_define

begin_define
define|#
directive|define
name|ARGI_DEBUG_OP
value|ARG_NONE
end_define

begin_define
define|#
directive|define
name|ARGI_DECREMENT_OP
value|ARGI_LIST1 (ARGI_INTEGER_REF)
end_define

begin_define
define|#
directive|define
name|ARGI_DEREF_OF_OP
value|ARGI_LIST1 (ARGI_REF_OR_STRING)
end_define

begin_define
define|#
directive|define
name|ARGI_DEVICE_OP
value|ARGI_INVALID_OPCODE
end_define

begin_define
define|#
directive|define
name|ARGI_DIVIDE_OP
value|ARGI_LIST4 (ARGI_INTEGER,    ARGI_INTEGER,       ARGI_TARGETREF,    ARGI_TARGETREF)
end_define

begin_define
define|#
directive|define
name|ARGI_DWORD_OP
value|ARGI_INVALID_OPCODE
end_define

begin_define
define|#
directive|define
name|ARGI_ELSE_OP
value|ARGI_INVALID_OPCODE
end_define

begin_define
define|#
directive|define
name|ARGI_EVENT_OP
value|ARGI_INVALID_OPCODE
end_define

begin_define
define|#
directive|define
name|ARGI_FATAL_OP
value|ARGI_LIST3 (ARGI_INTEGER,    ARGI_INTEGER,       ARGI_INTEGER)
end_define

begin_define
define|#
directive|define
name|ARGI_FIELD_OP
value|ARGI_INVALID_OPCODE
end_define

begin_define
define|#
directive|define
name|ARGI_FIND_SET_LEFT_BIT_OP
value|ARGI_LIST2 (ARGI_INTEGER,    ARGI_TARGETREF)
end_define

begin_define
define|#
directive|define
name|ARGI_FIND_SET_RIGHT_BIT_OP
value|ARGI_LIST2 (ARGI_INTEGER,    ARGI_TARGETREF)
end_define

begin_define
define|#
directive|define
name|ARGI_FROM_BCD_OP
value|ARGI_LIST2 (ARGI_INTEGER,    ARGI_TARGETREF)
end_define

begin_define
define|#
directive|define
name|ARGI_IF_OP
value|ARGI_INVALID_OPCODE
end_define

begin_define
define|#
directive|define
name|ARGI_INCREMENT_OP
value|ARGI_LIST1 (ARGI_INTEGER_REF)
end_define

begin_define
define|#
directive|define
name|ARGI_INDEX_FIELD_OP
value|ARGI_INVALID_OPCODE
end_define

begin_define
define|#
directive|define
name|ARGI_INDEX_OP
value|ARGI_LIST3 (ARGI_COMPLEXOBJ, ARGI_INTEGER,       ARGI_TARGETREF)
end_define

begin_define
define|#
directive|define
name|ARGI_LAND_OP
value|ARGI_LIST2 (ARGI_INTEGER,    ARGI_INTEGER)
end_define

begin_define
define|#
directive|define
name|ARGI_LEQUAL_OP
value|ARGI_LIST2 (ARGI_INTEGER,    ARGI_INTEGER)
end_define

begin_define
define|#
directive|define
name|ARGI_LGREATER_OP
value|ARGI_LIST2 (ARGI_INTEGER,    ARGI_INTEGER)
end_define

begin_define
define|#
directive|define
name|ARGI_LGREATEREQUAL_OP
value|ARGI_INVALID_OPCODE
end_define

begin_define
define|#
directive|define
name|ARGI_LLESS_OP
value|ARGI_LIST2 (ARGI_INTEGER,    ARGI_INTEGER)
end_define

begin_define
define|#
directive|define
name|ARGI_LLESSEQUAL_OP
value|ARGI_INVALID_OPCODE
end_define

begin_define
define|#
directive|define
name|ARGI_LNOT_OP
value|ARGI_LIST1 (ARGI_INTEGER)
end_define

begin_define
define|#
directive|define
name|ARGI_LNOTEQUAL_OP
value|ARGI_INVALID_OPCODE
end_define

begin_define
define|#
directive|define
name|ARGI_LOAD_OP
value|ARGI_LIST2 (ARGI_REGION,     ARGI_TARGETREF)
end_define

begin_define
define|#
directive|define
name|ARGI_LOAD_TABLE_OP
value|ARGI_LIST6 (ARGI_STRING,     ARGI_STRING,        ARGI_STRING,       ARGI_STRING,    ARGI_STRING, ARGI_ANYTYPE)
end_define

begin_define
define|#
directive|define
name|ARGI_LOCAL0
value|ARG_NONE
end_define

begin_define
define|#
directive|define
name|ARGI_LOCAL1
value|ARG_NONE
end_define

begin_define
define|#
directive|define
name|ARGI_LOCAL2
value|ARG_NONE
end_define

begin_define
define|#
directive|define
name|ARGI_LOCAL3
value|ARG_NONE
end_define

begin_define
define|#
directive|define
name|ARGI_LOCAL4
value|ARG_NONE
end_define

begin_define
define|#
directive|define
name|ARGI_LOCAL5
value|ARG_NONE
end_define

begin_define
define|#
directive|define
name|ARGI_LOCAL6
value|ARG_NONE
end_define

begin_define
define|#
directive|define
name|ARGI_LOCAL7
value|ARG_NONE
end_define

begin_define
define|#
directive|define
name|ARGI_LOR_OP
value|ARGI_LIST2 (ARGI_INTEGER,    ARGI_INTEGER)
end_define

begin_define
define|#
directive|define
name|ARGI_MATCH_OP
value|ARGI_LIST6 (ARGI_PACKAGE,    ARGI_INTEGER,       ARGI_INTEGER,      ARGI_INTEGER,   ARGI_INTEGER,   ARGI_INTEGER)
end_define

begin_define
define|#
directive|define
name|ARGI_METHOD_OP
value|ARGI_INVALID_OPCODE
end_define

begin_define
define|#
directive|define
name|ARGI_METHODCALL_OP
value|ARGI_INVALID_OPCODE
end_define

begin_define
define|#
directive|define
name|ARGI_MID_OP
value|ARGI_LIST4 (ARGI_BUFFERSTRING,ARGI_INTEGER,      ARGI_INTEGER,      ARGI_TARGETREF)
end_define

begin_define
define|#
directive|define
name|ARGI_MOD_OP
value|ARGI_LIST3 (ARGI_INTEGER,    ARGI_INTEGER,       ARGI_TARGETREF)
end_define

begin_define
define|#
directive|define
name|ARGI_MULTIPLY_OP
value|ARGI_LIST3 (ARGI_INTEGER,    ARGI_INTEGER,       ARGI_TARGETREF)
end_define

begin_define
define|#
directive|define
name|ARGI_MUTEX_OP
value|ARGI_INVALID_OPCODE
end_define

begin_define
define|#
directive|define
name|ARGI_NAME_OP
value|ARGI_INVALID_OPCODE
end_define

begin_define
define|#
directive|define
name|ARGI_NAMEDFIELD_OP
value|ARGI_INVALID_OPCODE
end_define

begin_define
define|#
directive|define
name|ARGI_NAMEPATH_OP
value|ARGI_INVALID_OPCODE
end_define

begin_define
define|#
directive|define
name|ARGI_NOOP_OP
value|ARG_NONE
end_define

begin_define
define|#
directive|define
name|ARGI_NOTIFY_OP
value|ARGI_LIST2 (ARGI_DEVICE_REF, ARGI_INTEGER)
end_define

begin_define
define|#
directive|define
name|ARGI_ONE_OP
value|ARG_NONE
end_define

begin_define
define|#
directive|define
name|ARGI_ONES_OP
value|ARG_NONE
end_define

begin_define
define|#
directive|define
name|ARGI_PACKAGE_OP
value|ARGI_INVALID_OPCODE
end_define

begin_define
define|#
directive|define
name|ARGI_POWER_RES_OP
value|ARGI_INVALID_OPCODE
end_define

begin_define
define|#
directive|define
name|ARGI_PROCESSOR_OP
value|ARGI_INVALID_OPCODE
end_define

begin_define
define|#
directive|define
name|ARGI_QWORD_OP
value|ARGI_INVALID_OPCODE
end_define

begin_define
define|#
directive|define
name|ARGI_REF_OF_OP
value|ARGI_LIST1 (ARGI_OBJECT_REF)
end_define

begin_define
define|#
directive|define
name|ARGI_REGION_OP
value|ARGI_LIST2 (ARGI_INTEGER,    ARGI_INTEGER)
end_define

begin_define
define|#
directive|define
name|ARGI_RELEASE_OP
value|ARGI_LIST1 (ARGI_MUTEX)
end_define

begin_define
define|#
directive|define
name|ARGI_RESERVEDFIELD_OP
value|ARGI_INVALID_OPCODE
end_define

begin_define
define|#
directive|define
name|ARGI_RESET_OP
value|ARGI_LIST1 (ARGI_EVENT)
end_define

begin_define
define|#
directive|define
name|ARGI_RETURN_OP
value|ARGI_INVALID_OPCODE
end_define

begin_define
define|#
directive|define
name|ARGI_REVISION_OP
value|ARG_NONE
end_define

begin_define
define|#
directive|define
name|ARGI_SCOPE_OP
value|ARGI_INVALID_OPCODE
end_define

begin_define
define|#
directive|define
name|ARGI_SHIFT_LEFT_OP
value|ARGI_LIST3 (ARGI_INTEGER,    ARGI_INTEGER,       ARGI_TARGETREF)
end_define

begin_define
define|#
directive|define
name|ARGI_SHIFT_RIGHT_OP
value|ARGI_LIST3 (ARGI_INTEGER,    ARGI_INTEGER,       ARGI_TARGETREF)
end_define

begin_define
define|#
directive|define
name|ARGI_SIGNAL_OP
value|ARGI_LIST1 (ARGI_EVENT)
end_define

begin_define
define|#
directive|define
name|ARGI_SIZE_OF_OP
value|ARGI_LIST1 (ARGI_DATAOBJECT)
end_define

begin_define
define|#
directive|define
name|ARGI_SLEEP_OP
value|ARGI_LIST1 (ARGI_INTEGER)
end_define

begin_define
define|#
directive|define
name|ARGI_STALL_OP
value|ARGI_LIST1 (ARGI_INTEGER)
end_define

begin_define
define|#
directive|define
name|ARGI_STATICSTRING_OP
value|ARGI_INVALID_OPCODE
end_define

begin_define
define|#
directive|define
name|ARGI_STORE_OP
value|ARGI_LIST2 (ARGI_ANYTYPE,    ARGI_TARGETREF)
end_define

begin_define
define|#
directive|define
name|ARGI_STRING_OP
value|ARGI_INVALID_OPCODE
end_define

begin_define
define|#
directive|define
name|ARGI_SUBTRACT_OP
value|ARGI_LIST3 (ARGI_INTEGER,    ARGI_INTEGER,       ARGI_TARGETREF)
end_define

begin_define
define|#
directive|define
name|ARGI_THERMAL_ZONE_OP
value|ARGI_INVALID_OPCODE
end_define

begin_define
define|#
directive|define
name|ARGI_TO_BCD_OP
value|ARGI_LIST2 (ARGI_INTEGER,    ARGI_FIXED_TARGET)
end_define

begin_define
define|#
directive|define
name|ARGI_TO_BUFFER_OP
value|ARGI_LIST2 (ARGI_COMPUTEDATA,ARGI_FIXED_TARGET)
end_define

begin_define
define|#
directive|define
name|ARGI_TO_DEC_STR_OP
value|ARGI_LIST2 (ARGI_COMPUTEDATA,ARGI_FIXED_TARGET)
end_define

begin_define
define|#
directive|define
name|ARGI_TO_HEX_STR_OP
value|ARGI_LIST2 (ARGI_COMPUTEDATA,ARGI_FIXED_TARGET)
end_define

begin_define
define|#
directive|define
name|ARGI_TO_INTEGER_OP
value|ARGI_LIST2 (ARGI_COMPUTEDATA,ARGI_FIXED_TARGET)
end_define

begin_define
define|#
directive|define
name|ARGI_TO_STRING_OP
value|ARGI_LIST3 (ARGI_BUFFER,     ARGI_INTEGER,       ARGI_FIXED_TARGET)
end_define

begin_define
define|#
directive|define
name|ARGI_TYPE_OP
value|ARGI_LIST1 (ARGI_ANYTYPE)
end_define

begin_define
define|#
directive|define
name|ARGI_UNLOAD_OP
value|ARGI_LIST1 (ARGI_DDBHANDLE)
end_define

begin_define
define|#
directive|define
name|ARGI_VAR_PACKAGE_OP
value|ARGI_INVALID_OPCODE
end_define

begin_define
define|#
directive|define
name|ARGI_WAIT_OP
value|ARGI_LIST2 (ARGI_EVENT,      ARGI_INTEGER)
end_define

begin_define
define|#
directive|define
name|ARGI_WHILE_OP
value|ARGI_INVALID_OPCODE
end_define

begin_define
define|#
directive|define
name|ARGI_WORD_OP
value|ARGI_INVALID_OPCODE
end_define

begin_define
define|#
directive|define
name|ARGI_ZERO_OP
value|ARG_NONE
end_define

begin_comment
comment|/*  * Summary of opcode types/flags  */
end_comment

begin_comment
comment|/******************************************************************************   Opcodes that have associated namespace objects (AML_NSOBJECT flag)      AML_SCOPE_OP     AML_DEVICE_OP     AML_THERMAL_ZONE_OP     AML_METHOD_OP     AML_POWER_RES_OP     AML_PROCESSOR_OP     AML_FIELD_OP     AML_INDEX_FIELD_OP     AML_BANK_FIELD_OP     AML_NAME_OP     AML_ALIAS_OP     AML_MUTEX_OP     AML_EVENT_OP     AML_REGION_OP     AML_CREATE_FIELD_OP     AML_CREATE_BIT_FIELD_OP     AML_CREATE_BYTE_FIELD_OP     AML_CREATE_WORD_FIELD_OP     AML_CREATE_DWORD_FIELD_OP     AML_CREATE_QWORD_FIELD_OP     AML_INT_NAMEDFIELD_OP     AML_INT_METHODCALL_OP     AML_INT_NAMEPATH_OP    Opcodes that are "namespace" opcodes (AML_NSOPCODE flag)      AML_SCOPE_OP     AML_DEVICE_OP     AML_THERMAL_ZONE_OP     AML_METHOD_OP     AML_POWER_RES_OP     AML_PROCESSOR_OP     AML_FIELD_OP     AML_INDEX_FIELD_OP     AML_BANK_FIELD_OP     AML_NAME_OP     AML_ALIAS_OP     AML_MUTEX_OP     AML_EVENT_OP     AML_REGION_OP     AML_INT_NAMEDFIELD_OP    Opcodes that have an associated namespace node (AML_NSNODE flag)      AML_SCOPE_OP     AML_DEVICE_OP     AML_THERMAL_ZONE_OP     AML_METHOD_OP     AML_POWER_RES_OP     AML_PROCESSOR_OP     AML_NAME_OP     AML_ALIAS_OP     AML_MUTEX_OP     AML_EVENT_OP     AML_REGION_OP     AML_CREATE_FIELD_OP     AML_CREATE_BIT_FIELD_OP     AML_CREATE_BYTE_FIELD_OP     AML_CREATE_WORD_FIELD_OP     AML_CREATE_DWORD_FIELD_OP     AML_CREATE_QWORD_FIELD_OP     AML_INT_NAMEDFIELD_OP     AML_INT_METHODCALL_OP     AML_INT_NAMEPATH_OP    Opcodes that define named ACPI objects (AML_NAMED flag)      AML_SCOPE_OP     AML_DEVICE_OP     AML_THERMAL_ZONE_OP     AML_METHOD_OP     AML_POWER_RES_OP     AML_PROCESSOR_OP     AML_NAME_OP     AML_ALIAS_OP     AML_MUTEX_OP     AML_EVENT_OP     AML_REGION_OP     AML_INT_NAMEDFIELD_OP    Opcodes that contain executable AML as part of the definition that   must be deferred until needed      AML_METHOD_OP     AML_VAR_PACKAGE_OP     AML_CREATE_FIELD_OP     AML_CREATE_BIT_FIELD_OP     AML_CREATE_BYTE_FIELD_OP     AML_CREATE_WORD_FIELD_OP     AML_CREATE_DWORD_FIELD_OP     AML_CREATE_QWORD_FIELD_OP     AML_REGION_OP    Field opcodes      AML_CREATE_FIELD_OP     AML_FIELD_OP     AML_INDEX_FIELD_OP     AML_BANK_FIELD_OP    Field "Create" opcodes      AML_CREATE_FIELD_OP     AML_CREATE_BIT_FIELD_OP     AML_CREATE_BYTE_FIELD_OP     AML_CREATE_WORD_FIELD_OP     AML_CREATE_DWORD_FIELD_OP     AML_CREATE_QWORD_FIELD_OP  ******************************************************************************/
end_comment

begin_comment
comment|/*  * Master Opcode information table.  A summary of everything we know about each opcode, all in one place.  */
end_comment

begin_decl_stmt
specifier|static
specifier|const
name|ACPI_OPCODE_INFO
name|AcpiGbl_AmlOpInfo
index|[]
init|=
block|{
comment|/*! [Begin] no source code translation */
comment|/* Index           Name                 Parser Args               Interpreter Args                ObjectType                Class                      Type                  Flags */
comment|/* 00 */
name|ACPI_OP
argument_list|(
literal|"Zero"
argument_list|,
name|ARGP_ZERO_OP
argument_list|,
name|ARGI_ZERO_OP
argument_list|,
name|INTERNAL_TYPE_REFERENCE
argument_list|,
name|AML_CLASS_ARGUMENT
argument_list|,
name|AML_TYPE_CONSTANT
argument_list|,
literal|0
argument_list|)
block|,
comment|/* 01 */
name|ACPI_OP
argument_list|(
literal|"One"
argument_list|,
name|ARGP_ONE_OP
argument_list|,
name|ARGI_ONE_OP
argument_list|,
name|INTERNAL_TYPE_REFERENCE
argument_list|,
name|AML_CLASS_ARGUMENT
argument_list|,
name|AML_TYPE_CONSTANT
argument_list|,
literal|0
argument_list|)
block|,
comment|/* 02 */
name|ACPI_OP
argument_list|(
literal|"Alias"
argument_list|,
name|ARGP_ALIAS_OP
argument_list|,
name|ARGI_ALIAS_OP
argument_list|,
name|INTERNAL_TYPE_ALIAS
argument_list|,
name|AML_CLASS_NAMED_OBJECT
argument_list|,
name|AML_TYPE_NAMED_SIMPLE
argument_list|,
name|AML_HAS_ARGS
operator||
name|AML_NSOBJECT
operator||
name|AML_NSOPCODE
operator||
name|AML_NSNODE
operator||
name|AML_NAMED
argument_list|)
block|,
comment|/* 03 */
name|ACPI_OP
argument_list|(
literal|"Name"
argument_list|,
name|ARGP_NAME_OP
argument_list|,
name|ARGI_NAME_OP
argument_list|,
name|ACPI_TYPE_ANY
argument_list|,
name|AML_CLASS_NAMED_OBJECT
argument_list|,
name|AML_TYPE_NAMED_COMPLEX
argument_list|,
name|AML_HAS_ARGS
operator||
name|AML_NSOBJECT
operator||
name|AML_NSOPCODE
operator||
name|AML_NSNODE
operator||
name|AML_NAMED
argument_list|)
block|,
comment|/* 04 */
name|ACPI_OP
argument_list|(
literal|"ByteConst"
argument_list|,
name|ARGP_BYTE_OP
argument_list|,
name|ARGI_BYTE_OP
argument_list|,
name|ACPI_TYPE_INTEGER
argument_list|,
name|AML_CLASS_ARGUMENT
argument_list|,
name|AML_TYPE_LITERAL
argument_list|,
literal|0
argument_list|)
block|,
comment|/* 05 */
name|ACPI_OP
argument_list|(
literal|"WordConst"
argument_list|,
name|ARGP_WORD_OP
argument_list|,
name|ARGI_WORD_OP
argument_list|,
name|ACPI_TYPE_INTEGER
argument_list|,
name|AML_CLASS_ARGUMENT
argument_list|,
name|AML_TYPE_LITERAL
argument_list|,
literal|0
argument_list|)
block|,
comment|/* 06 */
name|ACPI_OP
argument_list|(
literal|"DwordConst"
argument_list|,
name|ARGP_DWORD_OP
argument_list|,
name|ARGI_DWORD_OP
argument_list|,
name|ACPI_TYPE_INTEGER
argument_list|,
name|AML_CLASS_ARGUMENT
argument_list|,
name|AML_TYPE_LITERAL
argument_list|,
literal|0
argument_list|)
block|,
comment|/* 07 */
name|ACPI_OP
argument_list|(
literal|"String"
argument_list|,
name|ARGP_STRING_OP
argument_list|,
name|ARGI_STRING_OP
argument_list|,
name|ACPI_TYPE_STRING
argument_list|,
name|AML_CLASS_ARGUMENT
argument_list|,
name|AML_TYPE_LITERAL
argument_list|,
literal|0
argument_list|)
block|,
comment|/* 08 */
name|ACPI_OP
argument_list|(
literal|"Scope"
argument_list|,
name|ARGP_SCOPE_OP
argument_list|,
name|ARGI_SCOPE_OP
argument_list|,
name|INTERNAL_TYPE_SCOPE
argument_list|,
name|AML_CLASS_NAMED_OBJECT
argument_list|,
name|AML_TYPE_NAMED_NO_OBJ
argument_list|,
name|AML_HAS_ARGS
operator||
name|AML_NSOBJECT
operator||
name|AML_NSOPCODE
operator||
name|AML_NSNODE
operator||
name|AML_NAMED
argument_list|)
block|,
comment|/* 09 */
name|ACPI_OP
argument_list|(
literal|"Buffer"
argument_list|,
name|ARGP_BUFFER_OP
argument_list|,
name|ARGI_BUFFER_OP
argument_list|,
name|ACPI_TYPE_BUFFER
argument_list|,
name|AML_CLASS_ARGUMENT
argument_list|,
name|AML_TYPE_DATA_TERM
argument_list|,
name|AML_HAS_ARGS
argument_list|)
block|,
comment|/* 0A */
name|ACPI_OP
argument_list|(
literal|"Package"
argument_list|,
name|ARGP_PACKAGE_OP
argument_list|,
name|ARGI_PACKAGE_OP
argument_list|,
name|ACPI_TYPE_PACKAGE
argument_list|,
name|AML_CLASS_ARGUMENT
argument_list|,
name|AML_TYPE_DATA_TERM
argument_list|,
name|AML_HAS_ARGS
argument_list|)
block|,
comment|/* 0B */
name|ACPI_OP
argument_list|(
literal|"Method"
argument_list|,
name|ARGP_METHOD_OP
argument_list|,
name|ARGI_METHOD_OP
argument_list|,
name|ACPI_TYPE_METHOD
argument_list|,
name|AML_CLASS_NAMED_OBJECT
argument_list|,
name|AML_TYPE_NAMED_COMPLEX
argument_list|,
name|AML_HAS_ARGS
operator||
name|AML_NSOBJECT
operator||
name|AML_NSOPCODE
operator||
name|AML_NSNODE
operator||
name|AML_NAMED
operator||
name|AML_DEFER
argument_list|)
block|,
comment|/* 0C */
name|ACPI_OP
argument_list|(
literal|"Local0"
argument_list|,
name|ARGP_LOCAL0
argument_list|,
name|ARGI_LOCAL0
argument_list|,
name|INTERNAL_TYPE_REFERENCE
argument_list|,
name|AML_CLASS_ARGUMENT
argument_list|,
name|AML_TYPE_LOCAL_VARIABLE
argument_list|,
literal|0
argument_list|)
block|,
comment|/* 0D */
name|ACPI_OP
argument_list|(
literal|"Local1"
argument_list|,
name|ARGP_LOCAL1
argument_list|,
name|ARGI_LOCAL1
argument_list|,
name|INTERNAL_TYPE_REFERENCE
argument_list|,
name|AML_CLASS_ARGUMENT
argument_list|,
name|AML_TYPE_LOCAL_VARIABLE
argument_list|,
literal|0
argument_list|)
block|,
comment|/* 0E */
name|ACPI_OP
argument_list|(
literal|"Local2"
argument_list|,
name|ARGP_LOCAL2
argument_list|,
name|ARGI_LOCAL2
argument_list|,
name|INTERNAL_TYPE_REFERENCE
argument_list|,
name|AML_CLASS_ARGUMENT
argument_list|,
name|AML_TYPE_LOCAL_VARIABLE
argument_list|,
literal|0
argument_list|)
block|,
comment|/* 0F */
name|ACPI_OP
argument_list|(
literal|"Local3"
argument_list|,
name|ARGP_LOCAL3
argument_list|,
name|ARGI_LOCAL3
argument_list|,
name|INTERNAL_TYPE_REFERENCE
argument_list|,
name|AML_CLASS_ARGUMENT
argument_list|,
name|AML_TYPE_LOCAL_VARIABLE
argument_list|,
literal|0
argument_list|)
block|,
comment|/* 10 */
name|ACPI_OP
argument_list|(
literal|"Local4"
argument_list|,
name|ARGP_LOCAL4
argument_list|,
name|ARGI_LOCAL4
argument_list|,
name|INTERNAL_TYPE_REFERENCE
argument_list|,
name|AML_CLASS_ARGUMENT
argument_list|,
name|AML_TYPE_LOCAL_VARIABLE
argument_list|,
literal|0
argument_list|)
block|,
comment|/* 11 */
name|ACPI_OP
argument_list|(
literal|"Local5"
argument_list|,
name|ARGP_LOCAL5
argument_list|,
name|ARGI_LOCAL5
argument_list|,
name|INTERNAL_TYPE_REFERENCE
argument_list|,
name|AML_CLASS_ARGUMENT
argument_list|,
name|AML_TYPE_LOCAL_VARIABLE
argument_list|,
literal|0
argument_list|)
block|,
comment|/* 12 */
name|ACPI_OP
argument_list|(
literal|"Local6"
argument_list|,
name|ARGP_LOCAL6
argument_list|,
name|ARGI_LOCAL6
argument_list|,
name|INTERNAL_TYPE_REFERENCE
argument_list|,
name|AML_CLASS_ARGUMENT
argument_list|,
name|AML_TYPE_LOCAL_VARIABLE
argument_list|,
literal|0
argument_list|)
block|,
comment|/* 13 */
name|ACPI_OP
argument_list|(
literal|"Local7"
argument_list|,
name|ARGP_LOCAL7
argument_list|,
name|ARGI_LOCAL7
argument_list|,
name|INTERNAL_TYPE_REFERENCE
argument_list|,
name|AML_CLASS_ARGUMENT
argument_list|,
name|AML_TYPE_LOCAL_VARIABLE
argument_list|,
literal|0
argument_list|)
block|,
comment|/* 14 */
name|ACPI_OP
argument_list|(
literal|"Arg0"
argument_list|,
name|ARGP_ARG0
argument_list|,
name|ARGI_ARG0
argument_list|,
name|INTERNAL_TYPE_REFERENCE
argument_list|,
name|AML_CLASS_ARGUMENT
argument_list|,
name|AML_TYPE_METHOD_ARGUMENT
argument_list|,
literal|0
argument_list|)
block|,
comment|/* 15 */
name|ACPI_OP
argument_list|(
literal|"Arg1"
argument_list|,
name|ARGP_ARG1
argument_list|,
name|ARGI_ARG1
argument_list|,
name|INTERNAL_TYPE_REFERENCE
argument_list|,
name|AML_CLASS_ARGUMENT
argument_list|,
name|AML_TYPE_METHOD_ARGUMENT
argument_list|,
literal|0
argument_list|)
block|,
comment|/* 16 */
name|ACPI_OP
argument_list|(
literal|"Arg2"
argument_list|,
name|ARGP_ARG2
argument_list|,
name|ARGI_ARG2
argument_list|,
name|INTERNAL_TYPE_REFERENCE
argument_list|,
name|AML_CLASS_ARGUMENT
argument_list|,
name|AML_TYPE_METHOD_ARGUMENT
argument_list|,
literal|0
argument_list|)
block|,
comment|/* 17 */
name|ACPI_OP
argument_list|(
literal|"Arg3"
argument_list|,
name|ARGP_ARG3
argument_list|,
name|ARGI_ARG3
argument_list|,
name|INTERNAL_TYPE_REFERENCE
argument_list|,
name|AML_CLASS_ARGUMENT
argument_list|,
name|AML_TYPE_METHOD_ARGUMENT
argument_list|,
literal|0
argument_list|)
block|,
comment|/* 18 */
name|ACPI_OP
argument_list|(
literal|"Arg4"
argument_list|,
name|ARGP_ARG4
argument_list|,
name|ARGI_ARG4
argument_list|,
name|INTERNAL_TYPE_REFERENCE
argument_list|,
name|AML_CLASS_ARGUMENT
argument_list|,
name|AML_TYPE_METHOD_ARGUMENT
argument_list|,
literal|0
argument_list|)
block|,
comment|/* 19 */
name|ACPI_OP
argument_list|(
literal|"Arg5"
argument_list|,
name|ARGP_ARG5
argument_list|,
name|ARGI_ARG5
argument_list|,
name|INTERNAL_TYPE_REFERENCE
argument_list|,
name|AML_CLASS_ARGUMENT
argument_list|,
name|AML_TYPE_METHOD_ARGUMENT
argument_list|,
literal|0
argument_list|)
block|,
comment|/* 1A */
name|ACPI_OP
argument_list|(
literal|"Arg6"
argument_list|,
name|ARGP_ARG6
argument_list|,
name|ARGI_ARG6
argument_list|,
name|INTERNAL_TYPE_REFERENCE
argument_list|,
name|AML_CLASS_ARGUMENT
argument_list|,
name|AML_TYPE_METHOD_ARGUMENT
argument_list|,
literal|0
argument_list|)
block|,
comment|/* 1B */
name|ACPI_OP
argument_list|(
literal|"Store"
argument_list|,
name|ARGP_STORE_OP
argument_list|,
name|ARGI_STORE_OP
argument_list|,
name|ACPI_TYPE_ANY
argument_list|,
name|AML_CLASS_EXECUTE
argument_list|,
name|AML_TYPE_EXEC_1A_1T_1R
argument_list|,
name|AML_FLAGS_EXEC_1A_1T_1R
argument_list|)
block|,
comment|/* 1C */
name|ACPI_OP
argument_list|(
literal|"RefOf"
argument_list|,
name|ARGP_REF_OF_OP
argument_list|,
name|ARGI_REF_OF_OP
argument_list|,
name|ACPI_TYPE_ANY
argument_list|,
name|AML_CLASS_EXECUTE
argument_list|,
name|AML_TYPE_EXEC_1A_0T_1R
argument_list|,
name|AML_FLAGS_EXEC_1A_0T_1R
argument_list|)
block|,
comment|/* 1D */
name|ACPI_OP
argument_list|(
literal|"Add"
argument_list|,
name|ARGP_ADD_OP
argument_list|,
name|ARGI_ADD_OP
argument_list|,
name|ACPI_TYPE_ANY
argument_list|,
name|AML_CLASS_EXECUTE
argument_list|,
name|AML_TYPE_EXEC_2A_1T_1R
argument_list|,
name|AML_FLAGS_EXEC_2A_1T_1R
operator||
name|AML_MATH
argument_list|)
block|,
comment|/* 1E */
name|ACPI_OP
argument_list|(
literal|"Concatenate"
argument_list|,
name|ARGP_CONCAT_OP
argument_list|,
name|ARGI_CONCAT_OP
argument_list|,
name|ACPI_TYPE_ANY
argument_list|,
name|AML_CLASS_EXECUTE
argument_list|,
name|AML_TYPE_EXEC_2A_1T_1R
argument_list|,
name|AML_FLAGS_EXEC_2A_1T_1R
argument_list|)
block|,
comment|/* 1F */
name|ACPI_OP
argument_list|(
literal|"Subtract"
argument_list|,
name|ARGP_SUBTRACT_OP
argument_list|,
name|ARGI_SUBTRACT_OP
argument_list|,
name|ACPI_TYPE_ANY
argument_list|,
name|AML_CLASS_EXECUTE
argument_list|,
name|AML_TYPE_EXEC_2A_1T_1R
argument_list|,
name|AML_FLAGS_EXEC_2A_1T_1R
operator||
name|AML_MATH
argument_list|)
block|,
comment|/* 20 */
name|ACPI_OP
argument_list|(
literal|"Increment"
argument_list|,
name|ARGP_INCREMENT_OP
argument_list|,
name|ARGI_INCREMENT_OP
argument_list|,
name|ACPI_TYPE_ANY
argument_list|,
name|AML_CLASS_EXECUTE
argument_list|,
name|AML_TYPE_EXEC_1A_0T_1R
argument_list|,
name|AML_FLAGS_EXEC_1A_0T_1R
argument_list|)
block|,
comment|/* 21 */
name|ACPI_OP
argument_list|(
literal|"Decrement"
argument_list|,
name|ARGP_DECREMENT_OP
argument_list|,
name|ARGI_DECREMENT_OP
argument_list|,
name|ACPI_TYPE_ANY
argument_list|,
name|AML_CLASS_EXECUTE
argument_list|,
name|AML_TYPE_EXEC_1A_0T_1R
argument_list|,
name|AML_FLAGS_EXEC_1A_0T_1R
argument_list|)
block|,
comment|/* 22 */
name|ACPI_OP
argument_list|(
literal|"Multiply"
argument_list|,
name|ARGP_MULTIPLY_OP
argument_list|,
name|ARGI_MULTIPLY_OP
argument_list|,
name|ACPI_TYPE_ANY
argument_list|,
name|AML_CLASS_EXECUTE
argument_list|,
name|AML_TYPE_EXEC_2A_1T_1R
argument_list|,
name|AML_FLAGS_EXEC_2A_1T_1R
operator||
name|AML_MATH
argument_list|)
block|,
comment|/* 23 */
name|ACPI_OP
argument_list|(
literal|"Divide"
argument_list|,
name|ARGP_DIVIDE_OP
argument_list|,
name|ARGI_DIVIDE_OP
argument_list|,
name|ACPI_TYPE_ANY
argument_list|,
name|AML_CLASS_EXECUTE
argument_list|,
name|AML_TYPE_EXEC_2A_2T_1R
argument_list|,
name|AML_FLAGS_EXEC_2A_2T_1R
argument_list|)
block|,
comment|/* 24 */
name|ACPI_OP
argument_list|(
literal|"ShiftLeft"
argument_list|,
name|ARGP_SHIFT_LEFT_OP
argument_list|,
name|ARGI_SHIFT_LEFT_OP
argument_list|,
name|ACPI_TYPE_ANY
argument_list|,
name|AML_CLASS_EXECUTE
argument_list|,
name|AML_TYPE_EXEC_2A_1T_1R
argument_list|,
name|AML_FLAGS_EXEC_2A_1T_1R
operator||
name|AML_MATH
argument_list|)
block|,
comment|/* 25 */
name|ACPI_OP
argument_list|(
literal|"ShiftRight"
argument_list|,
name|ARGP_SHIFT_RIGHT_OP
argument_list|,
name|ARGI_SHIFT_RIGHT_OP
argument_list|,
name|ACPI_TYPE_ANY
argument_list|,
name|AML_CLASS_EXECUTE
argument_list|,
name|AML_TYPE_EXEC_2A_1T_1R
argument_list|,
name|AML_FLAGS_EXEC_2A_1T_1R
operator||
name|AML_MATH
argument_list|)
block|,
comment|/* 26 */
name|ACPI_OP
argument_list|(
literal|"And"
argument_list|,
name|ARGP_BIT_AND_OP
argument_list|,
name|ARGI_BIT_AND_OP
argument_list|,
name|ACPI_TYPE_ANY
argument_list|,
name|AML_CLASS_EXECUTE
argument_list|,
name|AML_TYPE_EXEC_2A_1T_1R
argument_list|,
name|AML_FLAGS_EXEC_2A_1T_1R
operator||
name|AML_MATH
argument_list|)
block|,
comment|/* 27 */
name|ACPI_OP
argument_list|(
literal|"NAnd"
argument_list|,
name|ARGP_BIT_NAND_OP
argument_list|,
name|ARGI_BIT_NAND_OP
argument_list|,
name|ACPI_TYPE_ANY
argument_list|,
name|AML_CLASS_EXECUTE
argument_list|,
name|AML_TYPE_EXEC_2A_1T_1R
argument_list|,
name|AML_FLAGS_EXEC_2A_1T_1R
operator||
name|AML_MATH
argument_list|)
block|,
comment|/* 28 */
name|ACPI_OP
argument_list|(
literal|"Or"
argument_list|,
name|ARGP_BIT_OR_OP
argument_list|,
name|ARGI_BIT_OR_OP
argument_list|,
name|ACPI_TYPE_ANY
argument_list|,
name|AML_CLASS_EXECUTE
argument_list|,
name|AML_TYPE_EXEC_2A_1T_1R
argument_list|,
name|AML_FLAGS_EXEC_2A_1T_1R
operator||
name|AML_MATH
argument_list|)
block|,
comment|/* 29 */
name|ACPI_OP
argument_list|(
literal|"NOr"
argument_list|,
name|ARGP_BIT_NOR_OP
argument_list|,
name|ARGI_BIT_NOR_OP
argument_list|,
name|ACPI_TYPE_ANY
argument_list|,
name|AML_CLASS_EXECUTE
argument_list|,
name|AML_TYPE_EXEC_2A_1T_1R
argument_list|,
name|AML_FLAGS_EXEC_2A_1T_1R
operator||
name|AML_MATH
argument_list|)
block|,
comment|/* 2A */
name|ACPI_OP
argument_list|(
literal|"XOr"
argument_list|,
name|ARGP_BIT_XOR_OP
argument_list|,
name|ARGI_BIT_XOR_OP
argument_list|,
name|ACPI_TYPE_ANY
argument_list|,
name|AML_CLASS_EXECUTE
argument_list|,
name|AML_TYPE_EXEC_2A_1T_1R
argument_list|,
name|AML_FLAGS_EXEC_2A_1T_1R
operator||
name|AML_MATH
argument_list|)
block|,
comment|/* 2B */
name|ACPI_OP
argument_list|(
literal|"Not"
argument_list|,
name|ARGP_BIT_NOT_OP
argument_list|,
name|ARGI_BIT_NOT_OP
argument_list|,
name|ACPI_TYPE_ANY
argument_list|,
name|AML_CLASS_EXECUTE
argument_list|,
name|AML_TYPE_EXEC_1A_1T_1R
argument_list|,
name|AML_FLAGS_EXEC_1A_1T_1R
argument_list|)
block|,
comment|/* 2C */
name|ACPI_OP
argument_list|(
literal|"FindSetLeftBit"
argument_list|,
name|ARGP_FIND_SET_LEFT_BIT_OP
argument_list|,
name|ARGI_FIND_SET_LEFT_BIT_OP
argument_list|,
name|ACPI_TYPE_ANY
argument_list|,
name|AML_CLASS_EXECUTE
argument_list|,
name|AML_TYPE_EXEC_1A_1T_1R
argument_list|,
name|AML_FLAGS_EXEC_1A_1T_1R
argument_list|)
block|,
comment|/* 2D */
name|ACPI_OP
argument_list|(
literal|"FindSetRightBit"
argument_list|,
name|ARGP_FIND_SET_RIGHT_BIT_OP
argument_list|,
name|ARGI_FIND_SET_RIGHT_BIT_OP
argument_list|,
name|ACPI_TYPE_ANY
argument_list|,
name|AML_CLASS_EXECUTE
argument_list|,
name|AML_TYPE_EXEC_1A_1T_1R
argument_list|,
name|AML_FLAGS_EXEC_1A_1T_1R
argument_list|)
block|,
comment|/* 2E */
name|ACPI_OP
argument_list|(
literal|"DerefOf"
argument_list|,
name|ARGP_DEREF_OF_OP
argument_list|,
name|ARGI_DEREF_OF_OP
argument_list|,
name|ACPI_TYPE_ANY
argument_list|,
name|AML_CLASS_EXECUTE
argument_list|,
name|AML_TYPE_EXEC_1A_0T_1R
argument_list|,
name|AML_FLAGS_EXEC_1A_0T_1R
argument_list|)
block|,
comment|/* 2F */
name|ACPI_OP
argument_list|(
literal|"Notify"
argument_list|,
name|ARGP_NOTIFY_OP
argument_list|,
name|ARGI_NOTIFY_OP
argument_list|,
name|ACPI_TYPE_ANY
argument_list|,
name|AML_CLASS_EXECUTE
argument_list|,
name|AML_TYPE_EXEC_2A_0T_0R
argument_list|,
name|AML_FLAGS_EXEC_2A_0T_0R
argument_list|)
block|,
comment|/* 30 */
name|ACPI_OP
argument_list|(
literal|"SizeOf"
argument_list|,
name|ARGP_SIZE_OF_OP
argument_list|,
name|ARGI_SIZE_OF_OP
argument_list|,
name|ACPI_TYPE_ANY
argument_list|,
name|AML_CLASS_EXECUTE
argument_list|,
name|AML_TYPE_EXEC_1A_0T_1R
argument_list|,
name|AML_FLAGS_EXEC_1A_0T_1R
argument_list|)
block|,
comment|/* 31 */
name|ACPI_OP
argument_list|(
literal|"Index"
argument_list|,
name|ARGP_INDEX_OP
argument_list|,
name|ARGI_INDEX_OP
argument_list|,
name|ACPI_TYPE_ANY
argument_list|,
name|AML_CLASS_EXECUTE
argument_list|,
name|AML_TYPE_EXEC_2A_1T_1R
argument_list|,
name|AML_FLAGS_EXEC_2A_1T_1R
argument_list|)
block|,
comment|/* 32 */
name|ACPI_OP
argument_list|(
literal|"Match"
argument_list|,
name|ARGP_MATCH_OP
argument_list|,
name|ARGI_MATCH_OP
argument_list|,
name|ACPI_TYPE_ANY
argument_list|,
name|AML_CLASS_EXECUTE
argument_list|,
name|AML_TYPE_EXEC_6A_0T_1R
argument_list|,
name|AML_FLAGS_EXEC_6A_0T_1R
argument_list|)
block|,
comment|/* 33 */
name|ACPI_OP
argument_list|(
literal|"CreateDWordField"
argument_list|,
name|ARGP_CREATE_DWORD_FIELD_OP
argument_list|,
name|ARGI_CREATE_DWORD_FIELD_OP
argument_list|,
name|ACPI_TYPE_BUFFER_FIELD
argument_list|,
name|AML_CLASS_CREATE
argument_list|,
name|AML_TYPE_CREATE_FIELD
argument_list|,
name|AML_HAS_ARGS
operator||
name|AML_NSOBJECT
operator||
name|AML_NSNODE
operator||
name|AML_DEFER
operator||
name|AML_CREATE
argument_list|)
block|,
comment|/* 34 */
name|ACPI_OP
argument_list|(
literal|"CreateWordField"
argument_list|,
name|ARGP_CREATE_WORD_FIELD_OP
argument_list|,
name|ARGI_CREATE_WORD_FIELD_OP
argument_list|,
name|ACPI_TYPE_BUFFER_FIELD
argument_list|,
name|AML_CLASS_CREATE
argument_list|,
name|AML_TYPE_CREATE_FIELD
argument_list|,
name|AML_HAS_ARGS
operator||
name|AML_NSOBJECT
operator||
name|AML_NSNODE
operator||
name|AML_DEFER
operator||
name|AML_CREATE
argument_list|)
block|,
comment|/* 35 */
name|ACPI_OP
argument_list|(
literal|"CreateByteField"
argument_list|,
name|ARGP_CREATE_BYTE_FIELD_OP
argument_list|,
name|ARGI_CREATE_BYTE_FIELD_OP
argument_list|,
name|ACPI_TYPE_BUFFER_FIELD
argument_list|,
name|AML_CLASS_CREATE
argument_list|,
name|AML_TYPE_CREATE_FIELD
argument_list|,
name|AML_HAS_ARGS
operator||
name|AML_NSOBJECT
operator||
name|AML_NSNODE
operator||
name|AML_DEFER
operator||
name|AML_CREATE
argument_list|)
block|,
comment|/* 36 */
name|ACPI_OP
argument_list|(
literal|"CreateBitField"
argument_list|,
name|ARGP_CREATE_BIT_FIELD_OP
argument_list|,
name|ARGI_CREATE_BIT_FIELD_OP
argument_list|,
name|ACPI_TYPE_BUFFER_FIELD
argument_list|,
name|AML_CLASS_CREATE
argument_list|,
name|AML_TYPE_CREATE_FIELD
argument_list|,
name|AML_HAS_ARGS
operator||
name|AML_NSOBJECT
operator||
name|AML_NSNODE
operator||
name|AML_DEFER
operator||
name|AML_CREATE
argument_list|)
block|,
comment|/* 37 */
name|ACPI_OP
argument_list|(
literal|"ObjectType"
argument_list|,
name|ARGP_TYPE_OP
argument_list|,
name|ARGI_TYPE_OP
argument_list|,
name|ACPI_TYPE_ANY
argument_list|,
name|AML_CLASS_EXECUTE
argument_list|,
name|AML_TYPE_EXEC_1A_0T_1R
argument_list|,
name|AML_FLAGS_EXEC_1A_0T_1R
argument_list|)
block|,
comment|/* 38 */
name|ACPI_OP
argument_list|(
literal|"LAnd"
argument_list|,
name|ARGP_LAND_OP
argument_list|,
name|ARGI_LAND_OP
argument_list|,
name|ACPI_TYPE_ANY
argument_list|,
name|AML_CLASS_EXECUTE
argument_list|,
name|AML_TYPE_EXEC_2A_0T_1R
argument_list|,
name|AML_FLAGS_EXEC_2A_0T_1R
operator||
name|AML_LOGICAL
argument_list|)
block|,
comment|/* 39 */
name|ACPI_OP
argument_list|(
literal|"LOr"
argument_list|,
name|ARGP_LOR_OP
argument_list|,
name|ARGI_LOR_OP
argument_list|,
name|ACPI_TYPE_ANY
argument_list|,
name|AML_CLASS_EXECUTE
argument_list|,
name|AML_TYPE_EXEC_2A_0T_1R
argument_list|,
name|AML_FLAGS_EXEC_2A_0T_1R
operator||
name|AML_LOGICAL
argument_list|)
block|,
comment|/* 3A */
name|ACPI_OP
argument_list|(
literal|"LNot"
argument_list|,
name|ARGP_LNOT_OP
argument_list|,
name|ARGI_LNOT_OP
argument_list|,
name|ACPI_TYPE_ANY
argument_list|,
name|AML_CLASS_EXECUTE
argument_list|,
name|AML_TYPE_EXEC_1A_0T_1R
argument_list|,
name|AML_FLAGS_EXEC_1A_0T_1R
argument_list|)
block|,
comment|/* 3B */
name|ACPI_OP
argument_list|(
literal|"LEqual"
argument_list|,
name|ARGP_LEQUAL_OP
argument_list|,
name|ARGI_LEQUAL_OP
argument_list|,
name|ACPI_TYPE_ANY
argument_list|,
name|AML_CLASS_EXECUTE
argument_list|,
name|AML_TYPE_EXEC_2A_0T_1R
argument_list|,
name|AML_FLAGS_EXEC_2A_0T_1R
operator||
name|AML_LOGICAL
argument_list|)
block|,
comment|/* 3C */
name|ACPI_OP
argument_list|(
literal|"LGreater"
argument_list|,
name|ARGP_LGREATER_OP
argument_list|,
name|ARGI_LGREATER_OP
argument_list|,
name|ACPI_TYPE_ANY
argument_list|,
name|AML_CLASS_EXECUTE
argument_list|,
name|AML_TYPE_EXEC_2A_0T_1R
argument_list|,
name|AML_FLAGS_EXEC_2A_0T_1R
operator||
name|AML_LOGICAL
argument_list|)
block|,
comment|/* 3D */
name|ACPI_OP
argument_list|(
literal|"LLess"
argument_list|,
name|ARGP_LLESS_OP
argument_list|,
name|ARGI_LLESS_OP
argument_list|,
name|ACPI_TYPE_ANY
argument_list|,
name|AML_CLASS_EXECUTE
argument_list|,
name|AML_TYPE_EXEC_2A_0T_1R
argument_list|,
name|AML_FLAGS_EXEC_2A_0T_1R
operator||
name|AML_LOGICAL
argument_list|)
block|,
comment|/* 3E */
name|ACPI_OP
argument_list|(
literal|"If"
argument_list|,
name|ARGP_IF_OP
argument_list|,
name|ARGI_IF_OP
argument_list|,
name|ACPI_TYPE_ANY
argument_list|,
name|AML_CLASS_CONTROL
argument_list|,
name|AML_TYPE_CONTROL
argument_list|,
name|AML_HAS_ARGS
argument_list|)
block|,
comment|/* 3F */
name|ACPI_OP
argument_list|(
literal|"Else"
argument_list|,
name|ARGP_ELSE_OP
argument_list|,
name|ARGI_ELSE_OP
argument_list|,
name|ACPI_TYPE_ANY
argument_list|,
name|AML_CLASS_CONTROL
argument_list|,
name|AML_TYPE_CONTROL
argument_list|,
name|AML_HAS_ARGS
argument_list|)
block|,
comment|/* 40 */
name|ACPI_OP
argument_list|(
literal|"While"
argument_list|,
name|ARGP_WHILE_OP
argument_list|,
name|ARGI_WHILE_OP
argument_list|,
name|ACPI_TYPE_ANY
argument_list|,
name|AML_CLASS_CONTROL
argument_list|,
name|AML_TYPE_CONTROL
argument_list|,
name|AML_HAS_ARGS
argument_list|)
block|,
comment|/* 41 */
name|ACPI_OP
argument_list|(
literal|"Noop"
argument_list|,
name|ARGP_NOOP_OP
argument_list|,
name|ARGI_NOOP_OP
argument_list|,
name|ACPI_TYPE_ANY
argument_list|,
name|AML_CLASS_CONTROL
argument_list|,
name|AML_TYPE_CONTROL
argument_list|,
literal|0
argument_list|)
block|,
comment|/* 42 */
name|ACPI_OP
argument_list|(
literal|"Return"
argument_list|,
name|ARGP_RETURN_OP
argument_list|,
name|ARGI_RETURN_OP
argument_list|,
name|ACPI_TYPE_ANY
argument_list|,
name|AML_CLASS_CONTROL
argument_list|,
name|AML_TYPE_CONTROL
argument_list|,
name|AML_HAS_ARGS
argument_list|)
block|,
comment|/* 43 */
name|ACPI_OP
argument_list|(
literal|"Break"
argument_list|,
name|ARGP_BREAK_OP
argument_list|,
name|ARGI_BREAK_OP
argument_list|,
name|ACPI_TYPE_ANY
argument_list|,
name|AML_CLASS_CONTROL
argument_list|,
name|AML_TYPE_CONTROL
argument_list|,
literal|0
argument_list|)
block|,
comment|/* 44 */
name|ACPI_OP
argument_list|(
literal|"BreakPoint"
argument_list|,
name|ARGP_BREAK_POINT_OP
argument_list|,
name|ARGI_BREAK_POINT_OP
argument_list|,
name|ACPI_TYPE_ANY
argument_list|,
name|AML_CLASS_CONTROL
argument_list|,
name|AML_TYPE_CONTROL
argument_list|,
literal|0
argument_list|)
block|,
comment|/* 45 */
name|ACPI_OP
argument_list|(
literal|"Ones"
argument_list|,
name|ARGP_ONES_OP
argument_list|,
name|ARGI_ONES_OP
argument_list|,
name|INTERNAL_TYPE_REFERENCE
argument_list|,
name|AML_CLASS_ARGUMENT
argument_list|,
name|AML_TYPE_CONSTANT
argument_list|,
literal|0
argument_list|)
block|,
comment|/* Prefixed opcodes (Two-byte opcodes with a prefix op) */
comment|/* 46 */
name|ACPI_OP
argument_list|(
literal|"Mutex"
argument_list|,
name|ARGP_MUTEX_OP
argument_list|,
name|ARGI_MUTEX_OP
argument_list|,
name|ACPI_TYPE_MUTEX
argument_list|,
name|AML_CLASS_NAMED_OBJECT
argument_list|,
name|AML_TYPE_NAMED_SIMPLE
argument_list|,
name|AML_HAS_ARGS
operator||
name|AML_NSOBJECT
operator||
name|AML_NSOPCODE
operator||
name|AML_NSNODE
operator||
name|AML_NAMED
argument_list|)
block|,
comment|/* 47 */
name|ACPI_OP
argument_list|(
literal|"Event"
argument_list|,
name|ARGP_EVENT_OP
argument_list|,
name|ARGI_EVENT_OP
argument_list|,
name|ACPI_TYPE_EVENT
argument_list|,
name|AML_CLASS_NAMED_OBJECT
argument_list|,
name|AML_TYPE_NAMED_SIMPLE
argument_list|,
name|AML_NSOBJECT
operator||
name|AML_NSOPCODE
operator||
name|AML_NSNODE
operator||
name|AML_NAMED
argument_list|)
block|,
comment|/* 48 */
name|ACPI_OP
argument_list|(
literal|"CondRefOf"
argument_list|,
name|ARGP_COND_REF_OF_OP
argument_list|,
name|ARGI_COND_REF_OF_OP
argument_list|,
name|ACPI_TYPE_ANY
argument_list|,
name|AML_CLASS_EXECUTE
argument_list|,
name|AML_TYPE_EXEC_1A_1T_1R
argument_list|,
name|AML_FLAGS_EXEC_1A_1T_1R
argument_list|)
block|,
comment|/* 49 */
name|ACPI_OP
argument_list|(
literal|"CreateField"
argument_list|,
name|ARGP_CREATE_FIELD_OP
argument_list|,
name|ARGI_CREATE_FIELD_OP
argument_list|,
name|ACPI_TYPE_BUFFER_FIELD
argument_list|,
name|AML_CLASS_CREATE
argument_list|,
name|AML_TYPE_CREATE_FIELD
argument_list|,
name|AML_HAS_ARGS
operator||
name|AML_NSOBJECT
operator||
name|AML_NSNODE
operator||
name|AML_DEFER
operator||
name|AML_FIELD
operator||
name|AML_CREATE
argument_list|)
block|,
comment|/* 4A */
name|ACPI_OP
argument_list|(
literal|"Load"
argument_list|,
name|ARGP_LOAD_OP
argument_list|,
name|ARGI_LOAD_OP
argument_list|,
name|ACPI_TYPE_ANY
argument_list|,
name|AML_CLASS_EXECUTE
argument_list|,
name|AML_TYPE_EXEC_1A_1T_0R
argument_list|,
name|AML_FLAGS_EXEC_1A_1T_0R
argument_list|)
block|,
comment|/* 4B */
name|ACPI_OP
argument_list|(
literal|"Stall"
argument_list|,
name|ARGP_STALL_OP
argument_list|,
name|ARGI_STALL_OP
argument_list|,
name|ACPI_TYPE_ANY
argument_list|,
name|AML_CLASS_EXECUTE
argument_list|,
name|AML_TYPE_EXEC_1A_0T_0R
argument_list|,
name|AML_FLAGS_EXEC_1A_0T_0R
argument_list|)
block|,
comment|/* 4C */
name|ACPI_OP
argument_list|(
literal|"Sleep"
argument_list|,
name|ARGP_SLEEP_OP
argument_list|,
name|ARGI_SLEEP_OP
argument_list|,
name|ACPI_TYPE_ANY
argument_list|,
name|AML_CLASS_EXECUTE
argument_list|,
name|AML_TYPE_EXEC_1A_0T_0R
argument_list|,
name|AML_FLAGS_EXEC_1A_0T_0R
argument_list|)
block|,
comment|/* 4D */
name|ACPI_OP
argument_list|(
literal|"Acquire"
argument_list|,
name|ARGP_ACQUIRE_OP
argument_list|,
name|ARGI_ACQUIRE_OP
argument_list|,
name|ACPI_TYPE_ANY
argument_list|,
name|AML_CLASS_EXECUTE
argument_list|,
name|AML_TYPE_EXEC_2A_0T_1R
argument_list|,
name|AML_FLAGS_EXEC_2A_0T_1R
argument_list|)
block|,
comment|/* 4E */
name|ACPI_OP
argument_list|(
literal|"Signal"
argument_list|,
name|ARGP_SIGNAL_OP
argument_list|,
name|ARGI_SIGNAL_OP
argument_list|,
name|ACPI_TYPE_ANY
argument_list|,
name|AML_CLASS_EXECUTE
argument_list|,
name|AML_TYPE_EXEC_1A_0T_0R
argument_list|,
name|AML_FLAGS_EXEC_1A_0T_0R
argument_list|)
block|,
comment|/* 4F */
name|ACPI_OP
argument_list|(
literal|"Wait"
argument_list|,
name|ARGP_WAIT_OP
argument_list|,
name|ARGI_WAIT_OP
argument_list|,
name|ACPI_TYPE_ANY
argument_list|,
name|AML_CLASS_EXECUTE
argument_list|,
name|AML_TYPE_EXEC_2A_0T_1R
argument_list|,
name|AML_FLAGS_EXEC_2A_0T_1R
argument_list|)
block|,
comment|/* 50 */
name|ACPI_OP
argument_list|(
literal|"Reset"
argument_list|,
name|ARGP_RESET_OP
argument_list|,
name|ARGI_RESET_OP
argument_list|,
name|ACPI_TYPE_ANY
argument_list|,
name|AML_CLASS_EXECUTE
argument_list|,
name|AML_TYPE_EXEC_1A_0T_0R
argument_list|,
name|AML_FLAGS_EXEC_1A_0T_0R
argument_list|)
block|,
comment|/* 51 */
name|ACPI_OP
argument_list|(
literal|"Release"
argument_list|,
name|ARGP_RELEASE_OP
argument_list|,
name|ARGI_RELEASE_OP
argument_list|,
name|ACPI_TYPE_ANY
argument_list|,
name|AML_CLASS_EXECUTE
argument_list|,
name|AML_TYPE_EXEC_1A_0T_0R
argument_list|,
name|AML_FLAGS_EXEC_1A_0T_0R
argument_list|)
block|,
comment|/* 52 */
name|ACPI_OP
argument_list|(
literal|"FromBCD"
argument_list|,
name|ARGP_FROM_BCD_OP
argument_list|,
name|ARGI_FROM_BCD_OP
argument_list|,
name|ACPI_TYPE_ANY
argument_list|,
name|AML_CLASS_EXECUTE
argument_list|,
name|AML_TYPE_EXEC_1A_1T_1R
argument_list|,
name|AML_FLAGS_EXEC_1A_1T_1R
argument_list|)
block|,
comment|/* 53 */
name|ACPI_OP
argument_list|(
literal|"ToBCD"
argument_list|,
name|ARGP_TO_BCD_OP
argument_list|,
name|ARGI_TO_BCD_OP
argument_list|,
name|ACPI_TYPE_ANY
argument_list|,
name|AML_CLASS_EXECUTE
argument_list|,
name|AML_TYPE_EXEC_1A_1T_1R
argument_list|,
name|AML_FLAGS_EXEC_1A_1T_1R
argument_list|)
block|,
comment|/* 54 */
name|ACPI_OP
argument_list|(
literal|"Unload"
argument_list|,
name|ARGP_UNLOAD_OP
argument_list|,
name|ARGI_UNLOAD_OP
argument_list|,
name|ACPI_TYPE_ANY
argument_list|,
name|AML_CLASS_EXECUTE
argument_list|,
name|AML_TYPE_EXEC_1A_0T_0R
argument_list|,
name|AML_FLAGS_EXEC_1A_0T_0R
argument_list|)
block|,
comment|/* 55 */
name|ACPI_OP
argument_list|(
literal|"Revision"
argument_list|,
name|ARGP_REVISION_OP
argument_list|,
name|ARGI_REVISION_OP
argument_list|,
name|INTERNAL_TYPE_REFERENCE
argument_list|,
name|AML_CLASS_ARGUMENT
argument_list|,
name|AML_TYPE_CONSTANT
argument_list|,
literal|0
argument_list|)
block|,
comment|/* 56 */
name|ACPI_OP
argument_list|(
literal|"Debug"
argument_list|,
name|ARGP_DEBUG_OP
argument_list|,
name|ARGI_DEBUG_OP
argument_list|,
name|INTERNAL_TYPE_REFERENCE
argument_list|,
name|AML_CLASS_ARGUMENT
argument_list|,
name|AML_TYPE_CONSTANT
argument_list|,
literal|0
argument_list|)
block|,
comment|/* 57 */
name|ACPI_OP
argument_list|(
literal|"Fatal"
argument_list|,
name|ARGP_FATAL_OP
argument_list|,
name|ARGI_FATAL_OP
argument_list|,
name|ACPI_TYPE_ANY
argument_list|,
name|AML_CLASS_EXECUTE
argument_list|,
name|AML_TYPE_EXEC_3A_0T_0R
argument_list|,
name|AML_FLAGS_EXEC_3A_0T_0R
argument_list|)
block|,
comment|/* 58 */
name|ACPI_OP
argument_list|(
literal|"OperationRegion"
argument_list|,
name|ARGP_REGION_OP
argument_list|,
name|ARGI_REGION_OP
argument_list|,
name|ACPI_TYPE_REGION
argument_list|,
name|AML_CLASS_NAMED_OBJECT
argument_list|,
name|AML_TYPE_NAMED_COMPLEX
argument_list|,
name|AML_HAS_ARGS
operator||
name|AML_NSOBJECT
operator||
name|AML_NSOPCODE
operator||
name|AML_NSNODE
operator||
name|AML_NAMED
operator||
name|AML_DEFER
argument_list|)
block|,
comment|/* 59 */
name|ACPI_OP
argument_list|(
literal|"Field"
argument_list|,
name|ARGP_FIELD_OP
argument_list|,
name|ARGI_FIELD_OP
argument_list|,
name|INTERNAL_TYPE_FIELD_DEFN
argument_list|,
name|AML_CLASS_NAMED_OBJECT
argument_list|,
name|AML_TYPE_NAMED_FIELD
argument_list|,
name|AML_HAS_ARGS
operator||
name|AML_NSOBJECT
operator||
name|AML_NSOPCODE
operator||
name|AML_FIELD
argument_list|)
block|,
comment|/* 5A */
name|ACPI_OP
argument_list|(
literal|"Device"
argument_list|,
name|ARGP_DEVICE_OP
argument_list|,
name|ARGI_DEVICE_OP
argument_list|,
name|ACPI_TYPE_DEVICE
argument_list|,
name|AML_CLASS_NAMED_OBJECT
argument_list|,
name|AML_TYPE_NAMED_NO_OBJ
argument_list|,
name|AML_HAS_ARGS
operator||
name|AML_NSOBJECT
operator||
name|AML_NSOPCODE
operator||
name|AML_NSNODE
operator||
name|AML_NAMED
argument_list|)
block|,
comment|/* 5B */
name|ACPI_OP
argument_list|(
literal|"Processor"
argument_list|,
name|ARGP_PROCESSOR_OP
argument_list|,
name|ARGI_PROCESSOR_OP
argument_list|,
name|ACPI_TYPE_PROCESSOR
argument_list|,
name|AML_CLASS_NAMED_OBJECT
argument_list|,
name|AML_TYPE_NAMED_SIMPLE
argument_list|,
name|AML_HAS_ARGS
operator||
name|AML_NSOBJECT
operator||
name|AML_NSOPCODE
operator||
name|AML_NSNODE
operator||
name|AML_NAMED
argument_list|)
block|,
comment|/* 5C */
name|ACPI_OP
argument_list|(
literal|"PowerResource"
argument_list|,
name|ARGP_POWER_RES_OP
argument_list|,
name|ARGI_POWER_RES_OP
argument_list|,
name|ACPI_TYPE_POWER
argument_list|,
name|AML_CLASS_NAMED_OBJECT
argument_list|,
name|AML_TYPE_NAMED_SIMPLE
argument_list|,
name|AML_HAS_ARGS
operator||
name|AML_NSOBJECT
operator||
name|AML_NSOPCODE
operator||
name|AML_NSNODE
operator||
name|AML_NAMED
argument_list|)
block|,
comment|/* 5D */
name|ACPI_OP
argument_list|(
literal|"ThermalZone"
argument_list|,
name|ARGP_THERMAL_ZONE_OP
argument_list|,
name|ARGI_THERMAL_ZONE_OP
argument_list|,
name|ACPI_TYPE_THERMAL
argument_list|,
name|AML_CLASS_NAMED_OBJECT
argument_list|,
name|AML_TYPE_NAMED_NO_OBJ
argument_list|,
name|AML_HAS_ARGS
operator||
name|AML_NSOBJECT
operator||
name|AML_NSOPCODE
operator||
name|AML_NSNODE
operator||
name|AML_NAMED
argument_list|)
block|,
comment|/* 5E */
name|ACPI_OP
argument_list|(
literal|"IndexField"
argument_list|,
name|ARGP_INDEX_FIELD_OP
argument_list|,
name|ARGI_INDEX_FIELD_OP
argument_list|,
name|INTERNAL_TYPE_INDEX_FIELD_DEFN
argument_list|,
name|AML_CLASS_NAMED_OBJECT
argument_list|,
name|AML_TYPE_NAMED_FIELD
argument_list|,
name|AML_HAS_ARGS
operator||
name|AML_NSOBJECT
operator||
name|AML_NSOPCODE
operator||
name|AML_FIELD
argument_list|)
block|,
comment|/* 5F */
name|ACPI_OP
argument_list|(
literal|"BankField"
argument_list|,
name|ARGP_BANK_FIELD_OP
argument_list|,
name|ARGI_BANK_FIELD_OP
argument_list|,
name|INTERNAL_TYPE_BANK_FIELD_DEFN
argument_list|,
name|AML_CLASS_NAMED_OBJECT
argument_list|,
name|AML_TYPE_NAMED_FIELD
argument_list|,
name|AML_HAS_ARGS
operator||
name|AML_NSOBJECT
operator||
name|AML_NSOPCODE
operator||
name|AML_FIELD
argument_list|)
block|,
comment|/* Internal opcodes that map to invalid AML opcodes */
comment|/* 60 */
name|ACPI_OP
argument_list|(
literal|"LNotEqual"
argument_list|,
name|ARGP_LNOTEQUAL_OP
argument_list|,
name|ARGI_LNOTEQUAL_OP
argument_list|,
name|ACPI_TYPE_ANY
argument_list|,
name|AML_CLASS_INTERNAL
argument_list|,
name|AML_TYPE_BOGUS
argument_list|,
name|AML_HAS_ARGS
argument_list|)
block|,
comment|/* 61 */
name|ACPI_OP
argument_list|(
literal|"LLessEqual"
argument_list|,
name|ARGP_LLESSEQUAL_OP
argument_list|,
name|ARGI_LLESSEQUAL_OP
argument_list|,
name|ACPI_TYPE_ANY
argument_list|,
name|AML_CLASS_INTERNAL
argument_list|,
name|AML_TYPE_BOGUS
argument_list|,
name|AML_HAS_ARGS
argument_list|)
block|,
comment|/* 62 */
name|ACPI_OP
argument_list|(
literal|"LGreaterEqual"
argument_list|,
name|ARGP_LGREATEREQUAL_OP
argument_list|,
name|ARGI_LGREATEREQUAL_OP
argument_list|,
name|ACPI_TYPE_ANY
argument_list|,
name|AML_CLASS_INTERNAL
argument_list|,
name|AML_TYPE_BOGUS
argument_list|,
name|AML_HAS_ARGS
argument_list|)
block|,
comment|/* 63 */
name|ACPI_OP
argument_list|(
literal|"[NamePath]"
argument_list|,
name|ARGP_NAMEPATH_OP
argument_list|,
name|ARGI_NAMEPATH_OP
argument_list|,
name|INTERNAL_TYPE_REFERENCE
argument_list|,
name|AML_CLASS_ARGUMENT
argument_list|,
name|AML_TYPE_LITERAL
argument_list|,
name|AML_NSOBJECT
operator||
name|AML_NSNODE
argument_list|)
block|,
comment|/* 64 */
name|ACPI_OP
argument_list|(
literal|"[MethodCall]"
argument_list|,
name|ARGP_METHODCALL_OP
argument_list|,
name|ARGI_METHODCALL_OP
argument_list|,
name|ACPI_TYPE_METHOD
argument_list|,
name|AML_CLASS_METHOD_CALL
argument_list|,
name|AML_TYPE_METHOD_CALL
argument_list|,
name|AML_HAS_ARGS
operator||
name|AML_NSOBJECT
operator||
name|AML_NSNODE
argument_list|)
block|,
comment|/* 65 */
name|ACPI_OP
argument_list|(
literal|"[ByteList]"
argument_list|,
name|ARGP_BYTELIST_OP
argument_list|,
name|ARGI_BYTELIST_OP
argument_list|,
name|ACPI_TYPE_ANY
argument_list|,
name|AML_CLASS_ARGUMENT
argument_list|,
name|AML_TYPE_LITERAL
argument_list|,
literal|0
argument_list|)
block|,
comment|/* 66 */
name|ACPI_OP
argument_list|(
literal|"[ReservedField]"
argument_list|,
name|ARGP_RESERVEDFIELD_OP
argument_list|,
name|ARGI_RESERVEDFIELD_OP
argument_list|,
name|ACPI_TYPE_ANY
argument_list|,
name|AML_CLASS_INTERNAL
argument_list|,
name|AML_TYPE_BOGUS
argument_list|,
literal|0
argument_list|)
block|,
comment|/* 67 */
name|ACPI_OP
argument_list|(
literal|"[NamedField]"
argument_list|,
name|ARGP_NAMEDFIELD_OP
argument_list|,
name|ARGI_NAMEDFIELD_OP
argument_list|,
name|ACPI_TYPE_ANY
argument_list|,
name|AML_CLASS_INTERNAL
argument_list|,
name|AML_TYPE_BOGUS
argument_list|,
name|AML_NSOBJECT
operator||
name|AML_NSOPCODE
operator||
name|AML_NSNODE
operator||
name|AML_NAMED
argument_list|)
block|,
comment|/* 68 */
name|ACPI_OP
argument_list|(
literal|"[AccessField]"
argument_list|,
name|ARGP_ACCESSFIELD_OP
argument_list|,
name|ARGI_ACCESSFIELD_OP
argument_list|,
name|ACPI_TYPE_ANY
argument_list|,
name|AML_CLASS_INTERNAL
argument_list|,
name|AML_TYPE_BOGUS
argument_list|,
literal|0
argument_list|)
block|,
comment|/* 69 */
name|ACPI_OP
argument_list|(
literal|"[StaticString"
argument_list|,
name|ARGP_STATICSTRING_OP
argument_list|,
name|ARGI_STATICSTRING_OP
argument_list|,
name|ACPI_TYPE_ANY
argument_list|,
name|AML_CLASS_INTERNAL
argument_list|,
name|AML_TYPE_BOGUS
argument_list|,
literal|0
argument_list|)
block|,
comment|/* 6A */
name|ACPI_OP
argument_list|(
literal|"[Return Value]"
argument_list|,
name|ARG_NONE
argument_list|,
name|ARG_NONE
argument_list|,
name|ACPI_TYPE_ANY
argument_list|,
name|AML_CLASS_RETURN_VALUE
argument_list|,
name|AML_TYPE_RETURN
argument_list|,
name|AML_HAS_ARGS
operator||
name|AML_HAS_RETVAL
argument_list|)
block|,
comment|/* 6B */
name|ACPI_OP
argument_list|(
literal|"UNKNOWN_OP!"
argument_list|,
name|ARG_NONE
argument_list|,
name|ARG_NONE
argument_list|,
name|INTERNAL_TYPE_INVALID
argument_list|,
name|AML_CLASS_UNKNOWN
argument_list|,
name|AML_TYPE_BOGUS
argument_list|,
name|AML_HAS_ARGS
argument_list|)
block|,
comment|/* 6C */
name|ACPI_OP
argument_list|(
literal|"ASCII_ONLY!"
argument_list|,
name|ARG_NONE
argument_list|,
name|ARG_NONE
argument_list|,
name|ACPI_TYPE_ANY
argument_list|,
name|AML_CLASS_ASCII
argument_list|,
name|AML_TYPE_BOGUS
argument_list|,
name|AML_HAS_ARGS
argument_list|)
block|,
comment|/* 6D */
name|ACPI_OP
argument_list|(
literal|"PREFIX_ONLY!"
argument_list|,
name|ARG_NONE
argument_list|,
name|ARG_NONE
argument_list|,
name|ACPI_TYPE_ANY
argument_list|,
name|AML_CLASS_PREFIX
argument_list|,
name|AML_TYPE_BOGUS
argument_list|,
name|AML_HAS_ARGS
argument_list|)
block|,
comment|/* ACPI 2.0 opcodes */
comment|/* 6E */
name|ACPI_OP
argument_list|(
literal|"QwordConst"
argument_list|,
name|ARGP_QWORD_OP
argument_list|,
name|ARGI_QWORD_OP
argument_list|,
name|ACPI_TYPE_INTEGER
argument_list|,
name|AML_CLASS_ARGUMENT
argument_list|,
name|AML_TYPE_LITERAL
argument_list|,
literal|0
argument_list|)
block|,
comment|/* 6F */
name|ACPI_OP
argument_list|(
literal|"Package /*Var*/"
argument_list|,
name|ARGP_VAR_PACKAGE_OP
argument_list|,
name|ARGI_VAR_PACKAGE_OP
argument_list|,
name|ACPI_TYPE_PACKAGE
argument_list|,
name|AML_CLASS_ARGUMENT
argument_list|,
name|AML_TYPE_DATA_TERM
argument_list|,
name|AML_HAS_ARGS
operator||
name|AML_DEFER
argument_list|)
block|,
comment|/* 70 */
name|ACPI_OP
argument_list|(
literal|"ConcatenateResTemplate"
argument_list|,
name|ARGP_CONCAT_RES_OP
argument_list|,
name|ARGI_CONCAT_RES_OP
argument_list|,
name|ACPI_TYPE_ANY
argument_list|,
name|AML_CLASS_EXECUTE
argument_list|,
name|AML_TYPE_EXEC_2A_1T_1R
argument_list|,
name|AML_FLAGS_EXEC_2A_1T_1R
argument_list|)
block|,
comment|/* 71 */
name|ACPI_OP
argument_list|(
literal|"Mod"
argument_list|,
name|ARGP_MOD_OP
argument_list|,
name|ARGI_MOD_OP
argument_list|,
name|ACPI_TYPE_ANY
argument_list|,
name|AML_CLASS_EXECUTE
argument_list|,
name|AML_TYPE_EXEC_2A_1T_1R
argument_list|,
name|AML_FLAGS_EXEC_2A_1T_1R
argument_list|)
block|,
comment|/* 72 */
name|ACPI_OP
argument_list|(
literal|"CreateQWordField"
argument_list|,
name|ARGP_CREATE_QWORD_FIELD_OP
argument_list|,
name|ARGI_CREATE_QWORD_FIELD_OP
argument_list|,
name|ACPI_TYPE_BUFFER_FIELD
argument_list|,
name|AML_CLASS_CREATE
argument_list|,
name|AML_TYPE_CREATE_FIELD
argument_list|,
name|AML_HAS_ARGS
operator||
name|AML_NSOBJECT
operator||
name|AML_NSNODE
operator||
name|AML_DEFER
operator||
name|AML_CREATE
argument_list|)
block|,
comment|/* 73 */
name|ACPI_OP
argument_list|(
literal|"ToBuffer"
argument_list|,
name|ARGP_TO_BUFFER_OP
argument_list|,
name|ARGI_TO_BUFFER_OP
argument_list|,
name|ACPI_TYPE_ANY
argument_list|,
name|AML_CLASS_EXECUTE
argument_list|,
name|AML_TYPE_EXEC_1A_1T_1R
argument_list|,
name|AML_FLAGS_EXEC_1A_1T_1R
argument_list|)
block|,
comment|/* 74 */
name|ACPI_OP
argument_list|(
literal|"ToDecimalString"
argument_list|,
name|ARGP_TO_DEC_STR_OP
argument_list|,
name|ARGI_TO_DEC_STR_OP
argument_list|,
name|ACPI_TYPE_ANY
argument_list|,
name|AML_CLASS_EXECUTE
argument_list|,
name|AML_TYPE_EXEC_1A_1T_1R
argument_list|,
name|AML_FLAGS_EXEC_1A_1T_1R
argument_list|)
block|,
comment|/* 75 */
name|ACPI_OP
argument_list|(
literal|"ToHexString"
argument_list|,
name|ARGP_TO_HEX_STR_OP
argument_list|,
name|ARGI_TO_HEX_STR_OP
argument_list|,
name|ACPI_TYPE_ANY
argument_list|,
name|AML_CLASS_EXECUTE
argument_list|,
name|AML_TYPE_EXEC_1A_1T_1R
argument_list|,
name|AML_FLAGS_EXEC_1A_1T_1R
argument_list|)
block|,
comment|/* 76 */
name|ACPI_OP
argument_list|(
literal|"ToInteger"
argument_list|,
name|ARGP_TO_INTEGER_OP
argument_list|,
name|ARGI_TO_INTEGER_OP
argument_list|,
name|ACPI_TYPE_ANY
argument_list|,
name|AML_CLASS_EXECUTE
argument_list|,
name|AML_TYPE_EXEC_1A_1T_1R
argument_list|,
name|AML_FLAGS_EXEC_1A_1T_1R
argument_list|)
block|,
comment|/* 77 */
name|ACPI_OP
argument_list|(
literal|"ToString"
argument_list|,
name|ARGP_TO_STRING_OP
argument_list|,
name|ARGI_TO_STRING_OP
argument_list|,
name|ACPI_TYPE_ANY
argument_list|,
name|AML_CLASS_EXECUTE
argument_list|,
name|AML_TYPE_EXEC_2A_1T_1R
argument_list|,
name|AML_FLAGS_EXEC_2A_1T_1R
argument_list|)
block|,
comment|/* 78 */
name|ACPI_OP
argument_list|(
literal|"CopyObject"
argument_list|,
name|ARGP_COPY_OP
argument_list|,
name|ARGI_COPY_OP
argument_list|,
name|ACPI_TYPE_ANY
argument_list|,
name|AML_CLASS_EXECUTE
argument_list|,
name|AML_TYPE_EXEC_1A_1T_1R
argument_list|,
name|AML_FLAGS_EXEC_1A_1T_1R
argument_list|)
block|,
comment|/* 79 */
name|ACPI_OP
argument_list|(
literal|"Mid"
argument_list|,
name|ARGP_MID_OP
argument_list|,
name|ARGI_MID_OP
argument_list|,
name|ACPI_TYPE_ANY
argument_list|,
name|AML_CLASS_EXECUTE
argument_list|,
name|AML_TYPE_EXEC_3A_1T_1R
argument_list|,
name|AML_FLAGS_EXEC_3A_1T_1R
argument_list|)
block|,
comment|/* 7A */
name|ACPI_OP
argument_list|(
literal|"Continue"
argument_list|,
name|ARGP_CONTINUE_OP
argument_list|,
name|ARGI_CONTINUE_OP
argument_list|,
name|ACPI_TYPE_ANY
argument_list|,
name|AML_CLASS_CONTROL
argument_list|,
name|AML_TYPE_CONTROL
argument_list|,
literal|0
argument_list|)
block|,
comment|/* 7B */
name|ACPI_OP
argument_list|(
literal|"LoadTable"
argument_list|,
name|ARGP_LOAD_TABLE_OP
argument_list|,
name|ARGI_LOAD_TABLE_OP
argument_list|,
name|ACPI_TYPE_ANY
argument_list|,
name|AML_CLASS_EXECUTE
argument_list|,
name|AML_TYPE_EXEC_6A_0T_1R
argument_list|,
name|AML_FLAGS_EXEC_6A_0T_1R
argument_list|)
block|,
comment|/* 7C */
name|ACPI_OP
argument_list|(
literal|"DataTableRegion"
argument_list|,
name|ARGP_DATA_REGION_OP
argument_list|,
name|ARGI_DATA_REGION_OP
argument_list|,
name|ACPI_TYPE_REGION
argument_list|,
name|AML_CLASS_NAMED_OBJECT
argument_list|,
name|AML_TYPE_NAMED_SIMPLE
argument_list|,
name|AML_HAS_ARGS
operator||
name|AML_NSOBJECT
operator||
name|AML_NSOPCODE
operator||
name|AML_NSNODE
operator||
name|AML_NAMED
argument_list|)
block|,
comment|/*! [End] no source code translation !*/
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * This table is directly indexed by the opcodes, and returns an  * index into the table above  */
end_comment

begin_decl_stmt
specifier|static
specifier|const
name|UINT8
name|AcpiGbl_ShortOpIndex
index|[
literal|256
index|]
init|=
block|{
comment|/*              0     1     2     3     4     5     6     7  */
comment|/*              8     9     A     B     C     D     E     F  */
comment|/* 0x00 */
literal|0x00
block|,
literal|0x01
block|,
name|_UNK
block|,
name|_UNK
block|,
name|_UNK
block|,
name|_UNK
block|,
literal|0x02
block|,
name|_UNK
block|,
comment|/* 0x08 */
literal|0x03
block|,
name|_UNK
block|,
literal|0x04
block|,
literal|0x05
block|,
literal|0x06
block|,
literal|0x07
block|,
literal|0x6E
block|,
name|_UNK
block|,
comment|/* 0x10 */
literal|0x08
block|,
literal|0x09
block|,
literal|0x0a
block|,
literal|0x6F
block|,
literal|0x0b
block|,
name|_UNK
block|,
name|_UNK
block|,
name|_UNK
block|,
comment|/* 0x18 */
name|_UNK
block|,
name|_UNK
block|,
name|_UNK
block|,
name|_UNK
block|,
name|_UNK
block|,
name|_UNK
block|,
name|_UNK
block|,
name|_UNK
block|,
comment|/* 0x20 */
name|_UNK
block|,
name|_UNK
block|,
name|_UNK
block|,
name|_UNK
block|,
name|_UNK
block|,
name|_UNK
block|,
name|_UNK
block|,
name|_UNK
block|,
comment|/* 0x28 */
name|_UNK
block|,
name|_UNK
block|,
name|_UNK
block|,
name|_UNK
block|,
name|_UNK
block|,
literal|0x63
block|,
name|_PFX
block|,
name|_PFX
block|,
comment|/* 0x30 */
literal|0x67
block|,
literal|0x66
block|,
literal|0x68
block|,
literal|0x65
block|,
literal|0x69
block|,
literal|0x64
block|,
literal|0x6A
block|,
name|_UNK
block|,
comment|/* 0x38 */
name|_UNK
block|,
name|_UNK
block|,
name|_UNK
block|,
name|_UNK
block|,
name|_UNK
block|,
name|_UNK
block|,
name|_UNK
block|,
name|_UNK
block|,
comment|/* 0x40 */
name|_UNK
block|,
name|_ASC
block|,
name|_ASC
block|,
name|_ASC
block|,
name|_ASC
block|,
name|_ASC
block|,
name|_ASC
block|,
name|_ASC
block|,
comment|/* 0x48 */
name|_ASC
block|,
name|_ASC
block|,
name|_ASC
block|,
name|_ASC
block|,
name|_ASC
block|,
name|_ASC
block|,
name|_ASC
block|,
name|_ASC
block|,
comment|/* 0x50 */
name|_ASC
block|,
name|_ASC
block|,
name|_ASC
block|,
name|_ASC
block|,
name|_ASC
block|,
name|_ASC
block|,
name|_ASC
block|,
name|_ASC
block|,
comment|/* 0x58 */
name|_ASC
block|,
name|_ASC
block|,
name|_ASC
block|,
name|_UNK
block|,
name|_PFX
block|,
name|_UNK
block|,
name|_PFX
block|,
name|_ASC
block|,
comment|/* 0x60 */
literal|0x0c
block|,
literal|0x0d
block|,
literal|0x0e
block|,
literal|0x0f
block|,
literal|0x10
block|,
literal|0x11
block|,
literal|0x12
block|,
literal|0x13
block|,
comment|/* 0x68 */
literal|0x14
block|,
literal|0x15
block|,
literal|0x16
block|,
literal|0x17
block|,
literal|0x18
block|,
literal|0x19
block|,
literal|0x1a
block|,
name|_UNK
block|,
comment|/* 0x70 */
literal|0x1b
block|,
literal|0x1c
block|,
literal|0x1d
block|,
literal|0x1e
block|,
literal|0x1f
block|,
literal|0x20
block|,
literal|0x21
block|,
literal|0x22
block|,
comment|/* 0x78 */
literal|0x23
block|,
literal|0x24
block|,
literal|0x25
block|,
literal|0x26
block|,
literal|0x27
block|,
literal|0x28
block|,
literal|0x29
block|,
literal|0x2a
block|,
comment|/* 0x80 */
literal|0x2b
block|,
literal|0x2c
block|,
literal|0x2d
block|,
literal|0x2e
block|,
literal|0x70
block|,
literal|0x71
block|,
literal|0x2f
block|,
literal|0x30
block|,
comment|/* 0x88 */
literal|0x31
block|,
literal|0x32
block|,
literal|0x33
block|,
literal|0x34
block|,
literal|0x35
block|,
literal|0x36
block|,
literal|0x37
block|,
literal|0x72
block|,
comment|/* 0x90 */
literal|0x38
block|,
literal|0x39
block|,
literal|0x3a
block|,
literal|0x3b
block|,
literal|0x3c
block|,
literal|0x3d
block|,
literal|0x73
block|,
literal|0x74
block|,
comment|/* 0x98 */
literal|0x75
block|,
literal|0x76
block|,
name|_UNK
block|,
name|_UNK
block|,
literal|0x77
block|,
literal|0x78
block|,
literal|0x79
block|,
literal|0x7A
block|,
comment|/* 0xA0 */
literal|0x3e
block|,
literal|0x3f
block|,
literal|0x40
block|,
literal|0x41
block|,
literal|0x42
block|,
literal|0x43
block|,
literal|0x60
block|,
literal|0x61
block|,
comment|/* 0xA8 */
literal|0x62
block|,
name|_UNK
block|,
name|_UNK
block|,
name|_UNK
block|,
name|_UNK
block|,
name|_UNK
block|,
name|_UNK
block|,
name|_UNK
block|,
comment|/* 0xB0 */
name|_UNK
block|,
name|_UNK
block|,
name|_UNK
block|,
name|_UNK
block|,
name|_UNK
block|,
name|_UNK
block|,
name|_UNK
block|,
name|_UNK
block|,
comment|/* 0xB8 */
name|_UNK
block|,
name|_UNK
block|,
name|_UNK
block|,
name|_UNK
block|,
name|_UNK
block|,
name|_UNK
block|,
name|_UNK
block|,
name|_UNK
block|,
comment|/* 0xC0 */
name|_UNK
block|,
name|_UNK
block|,
name|_UNK
block|,
name|_UNK
block|,
name|_UNK
block|,
name|_UNK
block|,
name|_UNK
block|,
name|_UNK
block|,
comment|/* 0xC8 */
name|_UNK
block|,
name|_UNK
block|,
name|_UNK
block|,
name|_UNK
block|,
literal|0x44
block|,
name|_UNK
block|,
name|_UNK
block|,
name|_UNK
block|,
comment|/* 0xD0 */
name|_UNK
block|,
name|_UNK
block|,
name|_UNK
block|,
name|_UNK
block|,
name|_UNK
block|,
name|_UNK
block|,
name|_UNK
block|,
name|_UNK
block|,
comment|/* 0xD8 */
name|_UNK
block|,
name|_UNK
block|,
name|_UNK
block|,
name|_UNK
block|,
name|_UNK
block|,
name|_UNK
block|,
name|_UNK
block|,
name|_UNK
block|,
comment|/* 0xE0 */
name|_UNK
block|,
name|_UNK
block|,
name|_UNK
block|,
name|_UNK
block|,
name|_UNK
block|,
name|_UNK
block|,
name|_UNK
block|,
name|_UNK
block|,
comment|/* 0xE8 */
name|_UNK
block|,
name|_UNK
block|,
name|_UNK
block|,
name|_UNK
block|,
name|_UNK
block|,
name|_UNK
block|,
name|_UNK
block|,
name|_UNK
block|,
comment|/* 0xF0 */
name|_UNK
block|,
name|_UNK
block|,
name|_UNK
block|,
name|_UNK
block|,
name|_UNK
block|,
name|_UNK
block|,
name|_UNK
block|,
name|_UNK
block|,
comment|/* 0xF8 */
name|_UNK
block|,
name|_UNK
block|,
name|_UNK
block|,
name|_UNK
block|,
name|_UNK
block|,
name|_UNK
block|,
name|_UNK
block|,
literal|0x45
block|, }
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|UINT8
name|AcpiGbl_LongOpIndex
index|[
name|NUM_EXTENDED_OPCODE
index|]
init|=
block|{
comment|/*              0     1     2     3     4     5     6     7  */
comment|/*              8     9     A     B     C     D     E     F  */
comment|/* 0x00 */
name|_UNK
block|,
literal|0x46
block|,
literal|0x47
block|,
name|_UNK
block|,
name|_UNK
block|,
name|_UNK
block|,
name|_UNK
block|,
name|_UNK
block|,
comment|/* 0x08 */
name|_UNK
block|,
name|_UNK
block|,
name|_UNK
block|,
name|_UNK
block|,
name|_UNK
block|,
name|_UNK
block|,
name|_UNK
block|,
name|_UNK
block|,
comment|/* 0x10 */
name|_UNK
block|,
name|_UNK
block|,
literal|0x48
block|,
literal|0x49
block|,
name|_UNK
block|,
name|_UNK
block|,
name|_UNK
block|,
name|_UNK
block|,
comment|/* 0x18 */
name|_UNK
block|,
name|_UNK
block|,
name|_UNK
block|,
name|_UNK
block|,
name|_UNK
block|,
name|_UNK
block|,
name|_UNK
block|,
literal|0x7B
block|,
comment|/* 0x20 */
literal|0x4a
block|,
literal|0x4b
block|,
literal|0x4c
block|,
literal|0x4d
block|,
literal|0x4e
block|,
literal|0x4f
block|,
literal|0x50
block|,
literal|0x51
block|,
comment|/* 0x28 */
literal|0x52
block|,
literal|0x53
block|,
literal|0x54
block|,
name|_UNK
block|,
name|_UNK
block|,
name|_UNK
block|,
name|_UNK
block|,
name|_UNK
block|,
comment|/* 0x30 */
literal|0x55
block|,
literal|0x56
block|,
literal|0x57
block|,
name|_UNK
block|,
name|_UNK
block|,
name|_UNK
block|,
name|_UNK
block|,
name|_UNK
block|,
comment|/* 0x38 */
name|_UNK
block|,
name|_UNK
block|,
name|_UNK
block|,
name|_UNK
block|,
name|_UNK
block|,
name|_UNK
block|,
name|_UNK
block|,
name|_UNK
block|,
comment|/* 0x40 */
name|_UNK
block|,
name|_UNK
block|,
name|_UNK
block|,
name|_UNK
block|,
name|_UNK
block|,
name|_UNK
block|,
name|_UNK
block|,
name|_UNK
block|,
comment|/* 0x48 */
name|_UNK
block|,
name|_UNK
block|,
name|_UNK
block|,
name|_UNK
block|,
name|_UNK
block|,
name|_UNK
block|,
name|_UNK
block|,
name|_UNK
block|,
comment|/* 0x50 */
name|_UNK
block|,
name|_UNK
block|,
name|_UNK
block|,
name|_UNK
block|,
name|_UNK
block|,
name|_UNK
block|,
name|_UNK
block|,
name|_UNK
block|,
comment|/* 0x58 */
name|_UNK
block|,
name|_UNK
block|,
name|_UNK
block|,
name|_UNK
block|,
name|_UNK
block|,
name|_UNK
block|,
name|_UNK
block|,
name|_UNK
block|,
comment|/* 0x60 */
name|_UNK
block|,
name|_UNK
block|,
name|_UNK
block|,
name|_UNK
block|,
name|_UNK
block|,
name|_UNK
block|,
name|_UNK
block|,
name|_UNK
block|,
comment|/* 0x68 */
name|_UNK
block|,
name|_UNK
block|,
name|_UNK
block|,
name|_UNK
block|,
name|_UNK
block|,
name|_UNK
block|,
name|_UNK
block|,
name|_UNK
block|,
comment|/* 0x70 */
name|_UNK
block|,
name|_UNK
block|,
name|_UNK
block|,
name|_UNK
block|,
name|_UNK
block|,
name|_UNK
block|,
name|_UNK
block|,
name|_UNK
block|,
comment|/* 0x78 */
name|_UNK
block|,
name|_UNK
block|,
name|_UNK
block|,
name|_UNK
block|,
name|_UNK
block|,
name|_UNK
block|,
name|_UNK
block|,
name|_UNK
block|,
comment|/* 0x80 */
literal|0x58
block|,
literal|0x59
block|,
literal|0x5a
block|,
literal|0x5b
block|,
literal|0x5c
block|,
literal|0x5d
block|,
literal|0x5e
block|,
literal|0x5f
block|,
comment|/* 0x88 */
literal|0x7C
block|, }
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*******************************************************************************  *  * FUNCTION:    AcpiPsGetOpcodeInfo  *  * PARAMETERS:  Opcode              - The AML opcode  *  * RETURN:      A pointer to the info about the opcode.  NULL if the opcode was  *              not found in the table.  *  * DESCRIPTION: Find AML opcode description based on the opcode.  *              NOTE: This procedure must ALWAYS return a valid pointer!  *  ******************************************************************************/
end_comment

begin_function
specifier|const
name|ACPI_OPCODE_INFO
modifier|*
name|AcpiPsGetOpcodeInfo
parameter_list|(
name|UINT16
name|Opcode
parameter_list|)
block|{
name|ACPI_FUNCTION_NAME
argument_list|(
literal|"PsGetOpcodeInfo"
argument_list|)
expr_stmt|;
comment|/*      * Detect normal 8-bit opcode or extended 16-bit opcode      */
switch|switch
condition|(
call|(
name|UINT8
call|)
argument_list|(
name|Opcode
operator|>>
literal|8
argument_list|)
condition|)
block|{
case|case
literal|0
case|:
comment|/* Simple (8-bit) opcode: 0-255, can't index beyond table  */
return|return
operator|(
operator|&
name|AcpiGbl_AmlOpInfo
index|[
name|AcpiGbl_ShortOpIndex
index|[
operator|(
name|UINT8
operator|)
name|Opcode
index|]
index|]
operator|)
return|;
case|case
name|AML_EXTOP
case|:
comment|/* Extended (16-bit, prefix+opcode) opcode */
if|if
condition|(
operator|(
operator|(
name|UINT8
operator|)
name|Opcode
operator|)
operator|<=
name|MAX_EXTENDED_OPCODE
condition|)
block|{
return|return
operator|(
operator|&
name|AcpiGbl_AmlOpInfo
index|[
name|AcpiGbl_LongOpIndex
index|[
operator|(
name|UINT8
operator|)
name|Opcode
index|]
index|]
operator|)
return|;
block|}
comment|/* Else fall through to error case below */
default|default:
name|ACPI_DEBUG_PRINT
argument_list|(
operator|(
name|ACPI_DB_ERROR
operator|,
literal|"Unknown extended opcode [%X]\n"
operator|,
name|Opcode
operator|)
argument_list|)
expr_stmt|;
break|break;
block|}
comment|/* Default is "unknown opcode" */
return|return
operator|(
operator|&
name|AcpiGbl_AmlOpInfo
index|[
name|_UNK
index|]
operator|)
return|;
block|}
end_function

begin_comment
comment|/*******************************************************************************  *  * FUNCTION:    AcpiPsGetOpcodeName  *  * PARAMETERS:  Opcode              - The AML opcode  *  * RETURN:      A pointer to the name of the opcode (ASCII String)  *              Note: Never returns NULL.  *  * DESCRIPTION: Translate an opcode into a human-readable string  *  ******************************************************************************/
end_comment

begin_function
name|NATIVE_CHAR
modifier|*
name|AcpiPsGetOpcodeName
parameter_list|(
name|UINT16
name|Opcode
parameter_list|)
block|{
ifdef|#
directive|ifdef
name|ACPI_DEBUG
specifier|const
name|ACPI_OPCODE_INFO
modifier|*
name|Op
decl_stmt|;
name|Op
operator|=
name|AcpiPsGetOpcodeInfo
argument_list|(
name|Opcode
argument_list|)
expr_stmt|;
comment|/* Always guaranteed to return a valid pointer */
return|return
operator|(
name|Op
operator|->
name|Name
operator|)
return|;
else|#
directive|else
return|return
operator|(
literal|"AE_NOT_CONFIGURED"
operator|)
return|;
endif|#
directive|endif
block|}
end_function

end_unit

