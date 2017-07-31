begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/******************************************************************************  *  * Module Name: asldefine.h - Common defines for the iASL compiler  *  *****************************************************************************/
end_comment

begin_comment
comment|/******************************************************************************  *  * 1. Copyright Notice  *  * Some or all of this work - Copyright (c) 1999 - 2017, Intel Corp.  * All rights reserved.  *  * 2. License  *  * 2.1. This is your license from Intel Corp. under its intellectual property  * rights. You may have additional license terms from the party that provided  * you this software, covering your right to use that party's intellectual  * property rights.  *  * 2.2. Intel grants, free of charge, to any person ("Licensee") obtaining a  * copy of the source code appearing in this file ("Covered Code") an  * irrevocable, perpetual, worldwide license under Intel's copyrights in the  * base code distributed originally by Intel ("Original Intel Code") to copy,  * make derivatives, distribute, use and display any portion of the Covered  * Code in any form, with the right to sublicense such rights; and  *  * 2.3. Intel grants Licensee a non-exclusive and non-transferable patent  * license (with the right to sublicense), under only those claims of Intel  * patents that are infringed by the Original Intel Code, to make, use, sell,  * offer to sell, and import the Covered Code and derivative works thereof  * solely to the minimum extent necessary to exercise the above copyright  * license, and in no event shall the patent license extend to any additions  * to or modifications of the Original Intel Code. No other license or right  * is granted directly or by implication, estoppel or otherwise;  *  * The above copyright and patent license is granted only if the following  * conditions are met:  *  * 3. Conditions  *  * 3.1. Redistribution of Source with Rights to Further Distribute Source.  * Redistribution of source code of any substantial portion of the Covered  * Code or modification with rights to further distribute source must include  * the above Copyright Notice, the above License, this list of Conditions,  * and the following Disclaimer and Export Compliance provision. In addition,  * Licensee must cause all Covered Code to which Licensee contributes to  * contain a file documenting the changes Licensee made to create that Covered  * Code and the date of any change. Licensee must include in that file the  * documentation of any changes made by any predecessor Licensee. Licensee  * must include a prominent statement that the modification is derived,  * directly or indirectly, from Original Intel Code.  *  * 3.2. Redistribution of Source with no Rights to Further Distribute Source.  * Redistribution of source code of any substantial portion of the Covered  * Code or modification without rights to further distribute source must  * include the following Disclaimer and Export Compliance provision in the  * documentation and/or other materials provided with distribution. In  * addition, Licensee may not authorize further sublicense of source of any  * portion of the Covered Code, and must include terms to the effect that the  * license from Licensee to its licensee is limited to the intellectual  * property embodied in the software Licensee provides to its licensee, and  * not to intellectual property embodied in modifications its licensee may  * make.  *  * 3.3. Redistribution of Executable. Redistribution in executable form of any  * substantial portion of the Covered Code or modification must reproduce the  * above Copyright Notice, and the following Disclaimer and Export Compliance  * provision in the documentation and/or other materials provided with the  * distribution.  *  * 3.4. Intel retains all right, title, and interest in and to the Original  * Intel Code.  *  * 3.5. Neither the name Intel nor any other trademark owned or controlled by  * Intel shall be used in advertising or otherwise to promote the sale, use or  * other dealings in products derived from or relating to the Covered Code  * without prior written authorization from Intel.  *  * 4. Disclaimer and Export Compliance  *  * 4.1. INTEL MAKES NO WARRANTY OF ANY KIND REGARDING ANY SOFTWARE PROVIDED  * HERE. ANY SOFTWARE ORIGINATING FROM INTEL OR DERIVED FROM INTEL SOFTWARE  * IS PROVIDED "AS IS," AND INTEL WILL NOT PROVIDE ANY SUPPORT, ASSISTANCE,  * INSTALLATION, TRAINING OR OTHER SERVICES. INTEL WILL NOT PROVIDE ANY  * UPDATES, ENHANCEMENTS OR EXTENSIONS. INTEL SPECIFICALLY DISCLAIMS ANY  * IMPLIED WARRANTIES OF MERCHANTABILITY, NONINFRINGEMENT AND FITNESS FOR A  * PARTICULAR PURPOSE.  *  * 4.2. IN NO EVENT SHALL INTEL HAVE ANY LIABILITY TO LICENSEE, ITS LICENSEES  * OR ANY OTHER THIRD PARTY, FOR ANY LOST PROFITS, LOST DATA, LOSS OF USE OR  * COSTS OF PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES, OR FOR ANY INDIRECT,  * SPECIAL OR CONSEQUENTIAL DAMAGES ARISING OUT OF THIS AGREEMENT, UNDER ANY  * CAUSE OF ACTION OR THEORY OF LIABILITY, AND IRRESPECTIVE OF WHETHER INTEL  * HAS ADVANCE NOTICE OF THE POSSIBILITY OF SUCH DAMAGES. THESE LIMITATIONS  * SHALL APPLY NOTWITHSTANDING THE FAILURE OF THE ESSENTIAL PURPOSE OF ANY  * LIMITED REMEDY.  *  * 4.3. Licensee shall not export, either directly or indirectly, any of this  * software or system incorporating such software without first obtaining any  * required license or other approval from the U. S. Department of Commerce or  * any other agency or department of the United States Government. In the  * event Licensee exports any such software from the United States or  * re-exports any such software from a foreign destination, Licensee shall  * ensure that the distribution and export/re-export of the software is in  * compliance with all laws, regulations, orders, or other restrictions of the  * U.S. Export Administration Regulations. Licensee agrees that neither it nor  * any of its subsidiaries will export/re-export any technical data, process,  * software, or service, directly or indirectly, to any country for which the  * United States government or any agency thereof requires an export license,  * other governmental approval, or letter of assurance, without first obtaining  * such license, approval or letter.  *  *****************************************************************************  *  * Alternatively, you may choose to be licensed under the terms of the  * following license:  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions, and the following disclaimer,  *    without modification.  * 2. Redistributions in binary form must reproduce at minimum a disclaimer  *    substantially similar to the "NO WARRANTY" disclaimer below  *    ("Disclaimer") and any redistribution must be conditioned upon  *    including a substantially similar Disclaimer requirement for further  *    binary redistribution.  * 3. Neither the names of the above-listed copyright holders nor the names  *    of any contributors may be used to endorse or promote products derived  *    from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT  * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR  * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT  * OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,  * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT  * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE  * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * Alternatively, you may choose to be licensed under the terms of the  * GNU General Public License ("GPL") version 2 as published by the Free  * Software Foundation.  *  *****************************************************************************/
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
name|ASL_COMPILER_NAME
value|"ASL+ Optimizing Compiler/Disassembler"
end_define

begin_define
define|#
directive|define
name|AML_DISASSEMBLER_NAME
value|"AML/ASL+ Disassembler"
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
name|ASL_DEFINE
value|"__IASL__"
end_define

begin_define
define|#
directive|define
name|ASL_PREFIX
value|"iASL: "
end_define

begin_define
define|#
directive|define
name|ASL_COMPLIANCE
value|"Supports ACPI Specification Revision 6.2"
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
name|ASL_INPUT_TYPE_BINARY_ACPI_TABLE
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

begin_define
define|#
directive|define
name|ASL_IGNORE_LINE
value|(ACPI_UINT32_MAX -1)
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

begin_comment
comment|/*  * Macros for debug output  */
end_comment

begin_define
define|#
directive|define
name|DEBUG_MAX_LINE_LENGTH
value|61
end_define

begin_define
define|#
directive|define
name|DEBUG_SPACES_PER_INDENT
value|3
end_define

begin_define
define|#
directive|define
name|DEBUG_FULL_LINE_LENGTH
value|71
end_define

begin_define
define|#
directive|define
name|ASL_PARSE_TREE_FULL_LINE
value|"\n%71.71s"
end_define

begin_comment
comment|/* Header/Trailer for original parse tree directly from the parser */
end_comment

begin_define
define|#
directive|define
name|ASL_PARSE_TREE_HEADER1
define|\
value|"%*s Value P_Op Flags     Line#  End# LogL# EndL#\n", 65, " "
end_define

begin_define
define|#
directive|define
name|ASL_PARSE_TREE_DEBUG1
define|\
value|" %4.4X %8.8X %5d %5d %5d %5d"
end_define

begin_comment
comment|/* Header/Trailer for processed parse tree used for AML generation */
end_comment

begin_define
define|#
directive|define
name|ASL_PARSE_TREE_HEADER2
define|\
value|"%*s NameString Value    P_Op A_Op OpLen PByts Len  SubLen PSubLen OpPtr"\     "    Parent   Child    Next     Flags    AcTyp    Final Col"\     " Line#  End# LogL# EndL#\n", 60, " "
end_define

begin_define
define|#
directive|define
name|ASL_PARSE_TREE_DEBUG2
define|\
value|" %08X %04X %04X %01X     %04X  %04X %05X  %05X   "\     "%08X %08X %08X %08X %08X %08X %04X  %02d  %5d %5d %5d %5d"
end_define

begin_comment
comment|/*  * Macros for ASL/ASL+ converter  */
end_comment

begin_define
define|#
directive|define
name|COMMENT_CAPTURE_ON
value|Gbl_CommentState.CaptureComments = TRUE;
end_define

begin_define
define|#
directive|define
name|COMMENT_CAPTURE_OFF
value|Gbl_CommentState.CaptureComments = FALSE;
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ASLDEFINE.H */
end_comment

end_unit

