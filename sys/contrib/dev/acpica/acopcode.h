begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/******************************************************************************  *  * Name: acopcode.h - AML opcode information for the AML parser and interpreter  *       $Revision: 1.7 $  *  *****************************************************************************/
end_comment

begin_comment
comment|/******************************************************************************  *  * 1. Copyright Notice  *  * Some or all of this work - Copyright (c) 1999 - 2007, Intel Corp.  * All rights reserved.  *  * 2. License  *  * 2.1. This is your license from Intel Corp. under its intellectual property  * rights.  You may have additional license terms from the party that provided  * you this software, covering your right to use that party's intellectual  * property rights.  *  * 2.2. Intel grants, free of charge, to any person ("Licensee") obtaining a  * copy of the source code appearing in this file ("Covered Code") an  * irrevocable, perpetual, worldwide license under Intel's copyrights in the  * base code distributed originally by Intel ("Original Intel Code") to copy,  * make derivatives, distribute, use and display any portion of the Covered  * Code in any form, with the right to sublicense such rights; and  *  * 2.3. Intel grants Licensee a non-exclusive and non-transferable patent  * license (with the right to sublicense), under only those claims of Intel  * patents that are infringed by the Original Intel Code, to make, use, sell,  * offer to sell, and import the Covered Code and derivative works thereof  * solely to the minimum extent necessary to exercise the above copyright  * license, and in no event shall the patent license extend to any additions  * to or modifications of the Original Intel Code.  No other license or right  * is granted directly or by implication, estoppel or otherwise;  *  * The above copyright and patent license is granted only if the following  * conditions are met:  *  * 3. Conditions  *  * 3.1. Redistribution of Source with Rights to Further Distribute Source.  * Redistribution of source code of any substantial portion of the Covered  * Code or modification with rights to further distribute source must include  * the above Copyright Notice, the above License, this list of Conditions,  * and the following Disclaimer and Export Compliance provision.  In addition,  * Licensee must cause all Covered Code to which Licensee contributes to  * contain a file documenting the changes Licensee made to create that Covered  * Code and the date of any change.  Licensee must include in that file the  * documentation of any changes made by any predecessor Licensee.  Licensee  * must include a prominent statement that the modification is derived,  * directly or indirectly, from Original Intel Code.  *  * 3.2. Redistribution of Source with no Rights to Further Distribute Source.  * Redistribution of source code of any substantial portion of the Covered  * Code or modification without rights to further distribute source must  * include the following Disclaimer and Export Compliance provision in the  * documentation and/or other materials provided with distribution.  In  * addition, Licensee may not authorize further sublicense of source of any  * portion of the Covered Code, and must include terms to the effect that the  * license from Licensee to its licensee is limited to the intellectual  * property embodied in the software Licensee provides to its licensee, and  * not to intellectual property embodied in modifications its licensee may  * make.  *  * 3.3. Redistribution of Executable. Redistribution in executable form of any  * substantial portion of the Covered Code or modification must reproduce the  * above Copyright Notice, and the following Disclaimer and Export Compliance  * provision in the documentation and/or other materials provided with the  * distribution.  *  * 3.4. Intel retains all right, title, and interest in and to the Original  * Intel Code.  *  * 3.5. Neither the name Intel nor any other trademark owned or controlled by  * Intel shall be used in advertising or otherwise to promote the sale, use or  * other dealings in products derived from or relating to the Covered Code  * without prior written authorization from Intel.  *  * 4. Disclaimer and Export Compliance  *  * 4.1. INTEL MAKES NO WARRANTY OF ANY KIND REGARDING ANY SOFTWARE PROVIDED  * HERE.  ANY SOFTWARE ORIGINATING FROM INTEL OR DERIVED FROM INTEL SOFTWARE  * IS PROVIDED "AS IS," AND INTEL WILL NOT PROVIDE ANY SUPPORT,  ASSISTANCE,  * INSTALLATION, TRAINING OR OTHER SERVICES.  INTEL WILL NOT PROVIDE ANY  * UPDATES, ENHANCEMENTS OR EXTENSIONS.  INTEL SPECIFICALLY DISCLAIMS ANY  * IMPLIED WARRANTIES OF MERCHANTABILITY, NONINFRINGEMENT AND FITNESS FOR A  * PARTICULAR PURPOSE.  *  * 4.2. IN NO EVENT SHALL INTEL HAVE ANY LIABILITY TO LICENSEE, ITS LICENSEES  * OR ANY OTHER THIRD PARTY, FOR ANY LOST PROFITS, LOST DATA, LOSS OF USE OR  * COSTS OF PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES, OR FOR ANY INDIRECT,  * SPECIAL OR CONSEQUENTIAL DAMAGES ARISING OUT OF THIS AGREEMENT, UNDER ANY  * CAUSE OF ACTION OR THEORY OF LIABILITY, AND IRRESPECTIVE OF WHETHER INTEL  * HAS ADVANCE NOTICE OF THE POSSIBILITY OF SUCH DAMAGES.  THESE LIMITATIONS  * SHALL APPLY NOTWITHSTANDING THE FAILURE OF THE ESSENTIAL PURPOSE OF ANY  * LIMITED REMEDY.  *  * 4.3. Licensee shall not export, either directly or indirectly, any of this  * software or system incorporating such software without first obtaining any  * required license or other approval from the U. S. Department of Commerce or  * any other agency or department of the United States Government.  In the  * event Licensee exports any such software from the United States or  * re-exports any such software from a foreign destination, Licensee shall  * ensure that the distribution and export/re-export of the software is in  * compliance with all laws, regulations, orders, or other restrictions of the  * U.S. Export Administration Regulations. Licensee agrees that neither it nor  * any of its subsidiaries will export/re-export any technical data, process,  * software, or service, directly or indirectly, to any country for which the  * United States government or any agency thereof requires an export license,  * other governmental approval, or letter of assurance, without first obtaining  * such license, approval or letter.  *  *****************************************************************************/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__ACOPCODE_H__
end_ifndef

begin_define
define|#
directive|define
name|__ACOPCODE_H__
end_define

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
value|(MAX_EXTENDED_OPCODE + 1)
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
value|(MAX_INTERNAL_OPCODE + 1)
end_define

begin_comment
comment|/* Used for non-assigned opcodes */
end_comment

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

begin_comment
comment|/*  * All AML opcodes and the parse-time arguments for each.  Used by the AML  * parser  Each list is compressed into a 32-bit number and stored in the  * master opcode table (in psopcode.c).  */
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
value|ARGP_LIST2 (ARGP_TERMARG,    ARGP_SIMPLENAME)
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
name|ARGP_TIMER_OP
value|ARG_NONE
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
comment|/*  * All AML opcodes and the runtime arguments for each.  Used by the AML  * interpreter  Each list is compressed into a 32-bit number and stored  * in the master opcode table (in psopcode.c).  *  * (Used by PrepOperands procedure and the ASL Compiler)  */
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
value|ARGI_LIST1 (ARGI_INTEGER)
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
value|ARGI_LIST3 (ARGI_STRING,     ARGI_STRING,        ARGI_STRING)
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
value|ARGI_LIST2 (ARGI_INTEGER,    ARGI_FIXED_TARGET)
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
value|ARGI_LIST2 (ARGI_COMPUTEDATA,ARGI_COMPUTEDATA)
end_define

begin_define
define|#
directive|define
name|ARGI_LGREATER_OP
value|ARGI_LIST2 (ARGI_COMPUTEDATA,ARGI_COMPUTEDATA)
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
value|ARGI_LIST2 (ARGI_COMPUTEDATA,ARGI_COMPUTEDATA)
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
value|ARGI_LIST2 (ARGI_REGION_OR_BUFFER,ARGI_TARGETREF)
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
value|ARGI_LIST6 (ARGI_PACKAGE,    ARGI_INTEGER,   ARGI_COMPUTEDATA,      ARGI_INTEGER,ARGI_COMPUTEDATA,ARGI_INTEGER)
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
value|ARGI_LIST4 (ARGI_BUFFER_OR_STRING,ARGI_INTEGER,  ARGI_INTEGER,      ARGI_TARGETREF)
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
value|ARGI_LIST1 (ARGI_INTEGER)
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
value|ARGI_LIST2 (ARGI_DATAREFOBJ, ARGI_TARGETREF)
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
name|ARGI_TIMER_OP
value|ARG_NONE
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
value|ARGI_LIST1 (ARGI_INTEGER)
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

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __ACOPCODE_H__ */
end_comment

end_unit

