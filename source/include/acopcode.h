begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/******************************************************************************  *  * Name: acopcode.h - AML opcode information for the AML parser and interpreter  *  *****************************************************************************/
end_comment

begin_comment
comment|/*  * Copyright (C) 2000 - 2014, Intel Corp.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions, and the following disclaimer,  *    without modification.  * 2. Redistributions in binary form must reproduce at minimum a disclaimer  *    substantially similar to the "NO WARRANTY" disclaimer below  *    ("Disclaimer") and any redistribution must be conditioned upon  *    including a substantially similar Disclaimer requirement for further  *    binary redistribution.  * 3. Neither the names of the above-listed copyright holders nor the names  *    of any contributors may be used to endorse or promote products derived  *    from this software without specific prior written permission.  *  * Alternatively, this software may be distributed under the terms of the  * GNU General Public License ("GPL") version 2 as published by the Free  * Software Foundation.  *  * NO WARRANTY  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT  * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTIBILITY AND FITNESS FOR  * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT  * HOLDERS OR CONTRIBUTORS BE LIABLE FOR SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,  * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING  * IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  * POSSIBILITY OF SUCH DAMAGES.  */
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
comment|/*  * Reserved ASCII characters. Do not use any of these for  * internal opcodes, since they are used to differentiate  * name strings from AML opcodes  */
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
comment|/*  * All AML opcodes and the parse-time arguments for each. Used by the AML  * parser  Each list is compressed into a 32-bit number and stored in the  * master opcode table (in psopcode.c).  */
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
name|ARGP_CONNECTFIELD_OP
value|ARGP_LIST1 (ARGP_NAMESTRING)
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
name|ARGP_SERIALFIELD_OP
value|ARGP_LIST1 (ARGP_NAMESTRING)
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
comment|/*  * All AML opcodes and the runtime arguments for each. Used by the AML  * interpreter  Each list is compressed into a 32-bit number and stored  * in the master opcode table (in psopcode.c).  *  * (Used by PrepOperands procedure and the ASL Compiler)  */
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
name|ARGI_CONNECTFIELD_OP
value|ARGI_INVALID_OPCODE
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
value|ARGI_LIST1 (ARGI_TARGETREF)
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
value|ARGI_LIST1 (ARGI_TARGETREF)
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
name|ARGI_SERIALFIELD_OP
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

