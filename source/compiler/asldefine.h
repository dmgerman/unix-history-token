begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/******************************************************************************  *  * Module Name: asldefine.h - Common defines for the iASL compiler  *  *****************************************************************************/
end_comment

begin_comment
comment|/*  * Copyright (C) 2000 - 2014, Intel Corp.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions, and the following disclaimer,  *    without modification.  * 2. Redistributions in binary form must reproduce at minimum a disclaimer  *    substantially similar to the "NO WARRANTY" disclaimer below  *    ("Disclaimer") and any redistribution must be conditioned upon  *    including a substantially similar Disclaimer requirement for further  *    binary redistribution.  * 3. Neither the names of the above-listed copyright holders nor the names  *    of any contributors may be used to endorse or promote products derived  *    from this software without specific prior written permission.  *  * Alternatively, this software may be distributed under the terms of the  * GNU General Public License ("GPL") version 2 as published by the Free  * Software Foundation.  *  * NO WARRANTY  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT  * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTIBILITY AND FITNESS FOR  * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT  * HOLDERS OR CONTRIBUTORS BE LIABLE FOR SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,  * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING  * IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  * POSSIBILITY OF SUCH DAMAGES.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__ASLDEFINE_H
end_ifndef

begin_define
define|#
directive|define
name|__ASLDEFINE_H
end_define

begin_comment
comment|/*  * Compiler versions and names  */
end_comment

begin_define
define|#
directive|define
name|ASL_REVISION
value|ACPI_CA_VERSION
end_define

begin_define
define|#
directive|define
name|ASL_COMPILER_NAME
value|"ASL Optimizing Compiler"
end_define

begin_define
define|#
directive|define
name|AML_DISASSEMBLER_NAME
value|"AML Disassembler"
end_define

begin_define
define|#
directive|define
name|ASL_INVOCATION_NAME
value|"iasl"
end_define

begin_define
define|#
directive|define
name|ASL_CREATOR_ID
value|"INTL"
end_define

begin_define
define|#
directive|define
name|ASL_COMPLIANCE
value|"Supports ACPI Specification Revision 5.1"
end_define

begin_comment
comment|/* Configuration constants */
end_comment

begin_define
define|#
directive|define
name|ASL_MAX_ERROR_COUNT
value|200
end_define

begin_define
define|#
directive|define
name|ASL_PARSEOP_CACHE_SIZE
value|(1024 * 16)
end_define

begin_define
define|#
directive|define
name|ASL_STRING_CACHE_SIZE
value|(1024 * 64)
end_define

begin_define
define|#
directive|define
name|ASL_FIRST_PARSE_OPCODE
value|PARSEOP_ACCESSAS
end_define

begin_define
define|#
directive|define
name|ASL_PARSE_OPCODE_BASE
value|PARSEOP_ACCESSAS
end_define

begin_comment
comment|/* First Lex type */
end_comment

begin_comment
comment|/*  * Per-parser-generator configuration. These values are used to cheat and  * directly access the bison/yacc token name table (yyname or yytname).  * Note: These values are the index in yyname for the first lex token  * (PARSEOP_ACCCESSAS).  */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|YYBISON
argument_list|)
end_if

begin_define
define|#
directive|define
name|ASL_YYTNAME_START
value|3
end_define

begin_comment
comment|/* Bison */
end_comment

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|YYBYACC
argument_list|)
end_elif

begin_define
define|#
directive|define
name|ASL_YYTNAME_START
value|257
end_define

begin_comment
comment|/* Berkeley yacc */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Macros  */
end_comment

begin_define
define|#
directive|define
name|ASL_RESDESC_OFFSET
parameter_list|(
name|m
parameter_list|)
value|ACPI_OFFSET (AML_RESOURCE, m)
end_define

begin_define
define|#
directive|define
name|ASL_PTR_DIFF
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|((UINT8 *)(b) - (UINT8 *)(a))
end_define

begin_define
define|#
directive|define
name|ASL_PTR_ADD
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|((UINT8 *)(a) = ((UINT8 *)(a) + (b)))
end_define

begin_define
define|#
directive|define
name|ASL_GET_CHILD_NODE
parameter_list|(
name|a
parameter_list|)
value|(a)->Asl.Child
end_define

begin_define
define|#
directive|define
name|ASL_GET_PEER_NODE
parameter_list|(
name|a
parameter_list|)
value|(a)->Asl.Next
end_define

begin_define
define|#
directive|define
name|OP_TABLE_ENTRY
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|,
name|d
parameter_list|)
value|{b,d,a,c}
end_define

begin_comment
comment|/* Internal AML opcodes */
end_comment

begin_define
define|#
directive|define
name|AML_RAW_DATA_BYTE
value|(UINT16) 0xAA01
end_define

begin_comment
comment|/* write one raw byte */
end_comment

begin_define
define|#
directive|define
name|AML_RAW_DATA_WORD
value|(UINT16) 0xAA02
end_define

begin_comment
comment|/* write 2 raw bytes */
end_comment

begin_define
define|#
directive|define
name|AML_RAW_DATA_DWORD
value|(UINT16) 0xAA04
end_define

begin_comment
comment|/* write 4 raw bytes */
end_comment

begin_define
define|#
directive|define
name|AML_RAW_DATA_QWORD
value|(UINT16) 0xAA08
end_define

begin_comment
comment|/* write 8 raw bytes */
end_comment

begin_define
define|#
directive|define
name|AML_RAW_DATA_BUFFER
value|(UINT16) 0xAA0B
end_define

begin_comment
comment|/* raw buffer with length */
end_comment

begin_define
define|#
directive|define
name|AML_RAW_DATA_CHAIN
value|(UINT16) 0xAA0C
end_define

begin_comment
comment|/* chain of raw buffers */
end_comment

begin_define
define|#
directive|define
name|AML_PACKAGE_LENGTH
value|(UINT16) 0xAA10
end_define

begin_define
define|#
directive|define
name|AML_UNASSIGNED_OPCODE
value|(UINT16) 0xEEEE
end_define

begin_define
define|#
directive|define
name|AML_DEFAULT_ARG_OP
value|(UINT16) 0xDDDD
end_define

begin_comment
comment|/* filename suffixes for output files */
end_comment

begin_define
define|#
directive|define
name|FILE_SUFFIX_PREPROCESSOR
value|"i"
end_define

begin_define
define|#
directive|define
name|FILE_SUFFIX_AML_CODE
value|"aml"
end_define

begin_define
define|#
directive|define
name|FILE_SUFFIX_MAP
value|"map"
end_define

begin_define
define|#
directive|define
name|FILE_SUFFIX_LISTING
value|"lst"
end_define

begin_define
define|#
directive|define
name|FILE_SUFFIX_HEX_DUMP
value|"hex"
end_define

begin_define
define|#
directive|define
name|FILE_SUFFIX_DEBUG
value|"txt"
end_define

begin_define
define|#
directive|define
name|FILE_SUFFIX_SOURCE
value|"src"
end_define

begin_define
define|#
directive|define
name|FILE_SUFFIX_NAMESPACE
value|"nsp"
end_define

begin_define
define|#
directive|define
name|FILE_SUFFIX_ASM_SOURCE
value|"asm"
end_define

begin_define
define|#
directive|define
name|FILE_SUFFIX_C_SOURCE
value|"c"
end_define

begin_define
define|#
directive|define
name|FILE_SUFFIX_DISASSEMBLY
value|"dsl"
end_define

begin_define
define|#
directive|define
name|FILE_SUFFIX_ASM_INCLUDE
value|"inc"
end_define

begin_define
define|#
directive|define
name|FILE_SUFFIX_C_INCLUDE
value|"h"
end_define

begin_define
define|#
directive|define
name|FILE_SUFFIX_ASL_CODE
value|"asl"
end_define

begin_define
define|#
directive|define
name|FILE_SUFFIX_C_OFFSET
value|"offset.h"
end_define

begin_comment
comment|/* Types for input files */
end_comment

begin_define
define|#
directive|define
name|ASL_INPUT_TYPE_BINARY
value|0
end_define

begin_define
define|#
directive|define
name|ASL_INPUT_TYPE_ACPI_TABLE
value|1
end_define

begin_define
define|#
directive|define
name|ASL_INPUT_TYPE_ASCII_ASL
value|2
end_define

begin_define
define|#
directive|define
name|ASL_INPUT_TYPE_ASCII_DATA
value|3
end_define

begin_comment
comment|/* Misc */
end_comment

begin_define
define|#
directive|define
name|ASL_EXTERNAL_METHOD
value|255
end_define

begin_define
define|#
directive|define
name|ASL_ABORT
value|TRUE
end_define

begin_define
define|#
directive|define
name|ASL_NO_ABORT
value|FALSE
end_define

begin_define
define|#
directive|define
name|ASL_EOF
value|ACPI_UINT32_MAX
end_define

begin_comment
comment|/* Listings */
end_comment

begin_define
define|#
directive|define
name|ASL_LISTING_LINE_PREFIX
value|":  "
end_define

begin_comment
comment|/* Support for reserved method names */
end_comment

begin_define
define|#
directive|define
name|ACPI_VALID_RESERVED_NAME_MAX
value|0x80000000
end_define

begin_define
define|#
directive|define
name|ACPI_NOT_RESERVED_NAME
value|ACPI_UINT32_MAX
end_define

begin_define
define|#
directive|define
name|ACPI_PREDEFINED_NAME
value|(ACPI_UINT32_MAX - 1)
end_define

begin_define
define|#
directive|define
name|ACPI_EVENT_RESERVED_NAME
value|(ACPI_UINT32_MAX - 2)
end_define

begin_define
define|#
directive|define
name|ACPI_COMPILER_RESERVED_NAME
value|(ACPI_UINT32_MAX - 3)
end_define

begin_comment
comment|/* String to Integer conversion */
end_comment

begin_define
define|#
directive|define
name|NEGATIVE
value|1
end_define

begin_define
define|#
directive|define
name|POSITIVE
value|0
end_define

begin_comment
comment|/* Helper macros for resource tag creation */
end_comment

begin_define
define|#
directive|define
name|RsCreateMultiBitField
define|\
value|RsCreateResourceField
end_define

begin_define
define|#
directive|define
name|RsCreateBitField
parameter_list|(
name|Op
parameter_list|,
name|Name
parameter_list|,
name|ByteOffset
parameter_list|,
name|BitOffset
parameter_list|)
define|\
value|RsCreateResourceField (Op, Name, ByteOffset, BitOffset, 1)
end_define

begin_define
define|#
directive|define
name|RsCreateByteField
parameter_list|(
name|Op
parameter_list|,
name|Name
parameter_list|,
name|ByteOffset
parameter_list|)
define|\
value|RsCreateResourceField (Op, Name, ByteOffset, 0, 8);
end_define

begin_define
define|#
directive|define
name|RsCreateWordField
parameter_list|(
name|Op
parameter_list|,
name|Name
parameter_list|,
name|ByteOffset
parameter_list|)
define|\
value|RsCreateResourceField (Op, Name, ByteOffset, 0, 16);
end_define

begin_define
define|#
directive|define
name|RsCreateDwordField
parameter_list|(
name|Op
parameter_list|,
name|Name
parameter_list|,
name|ByteOffset
parameter_list|)
define|\
value|RsCreateResourceField (Op, Name, ByteOffset, 0, 32);
end_define

begin_define
define|#
directive|define
name|RsCreateQwordField
parameter_list|(
name|Op
parameter_list|,
name|Name
parameter_list|,
name|ByteOffset
parameter_list|)
define|\
value|RsCreateResourceField (Op, Name, ByteOffset, 0, 64);
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ASLDEFINE.H */
end_comment

end_unit

