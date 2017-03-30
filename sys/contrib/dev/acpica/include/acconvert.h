begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/******************************************************************************  *  * Module Name: acapps - common include for ACPI applications/tools  *  *****************************************************************************/
end_comment

begin_comment
comment|/******************************************************************************  *  * 1. Copyright Notice  *  * Some or all of this work - Copyright (c) 1999 - 2017, Intel Corp.  * All rights reserved.  *  * 2. License  *  * 2.1. This is your license from Intel Corp. under its intellectual property  * rights. You may have additional license terms from the party that provided  * you this software, covering your right to use that party's intellectual  * property rights.  *  * 2.2. Intel grants, free of charge, to any person ("Licensee") obtaining a  * copy of the source code appearing in this file ("Covered Code") an  * irrevocable, perpetual, worldwide license under Intel's copyrights in the  * base code distributed originally by Intel ("Original Intel Code") to copy,  * make derivatives, distribute, use and display any portion of the Covered  * Code in any form, with the right to sublicense such rights; and  *  * 2.3. Intel grants Licensee a non-exclusive and non-transferable patent  * license (with the right to sublicense), under only those claims of Intel  * patents that are infringed by the Original Intel Code, to make, use, sell,  * offer to sell, and import the Covered Code and derivative works thereof  * solely to the minimum extent necessary to exercise the above copyright  * license, and in no event shall the patent license extend to any additions  * to or modifications of the Original Intel Code. No other license or right  * is granted directly or by implication, estoppel or otherwise;  *  * The above copyright and patent license is granted only if the following  * conditions are met:  *  * 3. Conditions  *  * 3.1. Redistribution of Source with Rights to Further Distribute Source.  * Redistribution of source code of any substantial portion of the Covered  * Code or modification with rights to further distribute source must include  * the above Copyright Notice, the above License, this list of Conditions,  * and the following Disclaimer and Export Compliance provision. In addition,  * Licensee must cause all Covered Code to which Licensee contributes to  * contain a file documenting the changes Licensee made to create that Covered  * Code and the date of any change. Licensee must include in that file the  * documentation of any changes made by any predecessor Licensee. Licensee  * must include a prominent statement that the modification is derived,  * directly or indirectly, from Original Intel Code.  *  * 3.2. Redistribution of Source with no Rights to Further Distribute Source.  * Redistribution of source code of any substantial portion of the Covered  * Code or modification without rights to further distribute source must  * include the following Disclaimer and Export Compliance provision in the  * documentation and/or other materials provided with distribution. In  * addition, Licensee may not authorize further sublicense of source of any  * portion of the Covered Code, and must include terms to the effect that the  * license from Licensee to its licensee is limited to the intellectual  * property embodied in the software Licensee provides to its licensee, and  * not to intellectual property embodied in modifications its licensee may  * make.  *  * 3.3. Redistribution of Executable. Redistribution in executable form of any  * substantial portion of the Covered Code or modification must reproduce the  * above Copyright Notice, and the following Disclaimer and Export Compliance  * provision in the documentation and/or other materials provided with the  * distribution.  *  * 3.4. Intel retains all right, title, and interest in and to the Original  * Intel Code.  *  * 3.5. Neither the name Intel nor any other trademark owned or controlled by  * Intel shall be used in advertising or otherwise to promote the sale, use or  * other dealings in products derived from or relating to the Covered Code  * without prior written authorization from Intel.  *  * 4. Disclaimer and Export Compliance  *  * 4.1. INTEL MAKES NO WARRANTY OF ANY KIND REGARDING ANY SOFTWARE PROVIDED  * HERE. ANY SOFTWARE ORIGINATING FROM INTEL OR DERIVED FROM INTEL SOFTWARE  * IS PROVIDED "AS IS," AND INTEL WILL NOT PROVIDE ANY SUPPORT, ASSISTANCE,  * INSTALLATION, TRAINING OR OTHER SERVICES. INTEL WILL NOT PROVIDE ANY  * UPDATES, ENHANCEMENTS OR EXTENSIONS. INTEL SPECIFICALLY DISCLAIMS ANY  * IMPLIED WARRANTIES OF MERCHANTABILITY, NONINFRINGEMENT AND FITNESS FOR A  * PARTICULAR PURPOSE.  *  * 4.2. IN NO EVENT SHALL INTEL HAVE ANY LIABILITY TO LICENSEE, ITS LICENSEES  * OR ANY OTHER THIRD PARTY, FOR ANY LOST PROFITS, LOST DATA, LOSS OF USE OR  * COSTS OF PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES, OR FOR ANY INDIRECT,  * SPECIAL OR CONSEQUENTIAL DAMAGES ARISING OUT OF THIS AGREEMENT, UNDER ANY  * CAUSE OF ACTION OR THEORY OF LIABILITY, AND IRRESPECTIVE OF WHETHER INTEL  * HAS ADVANCE NOTICE OF THE POSSIBILITY OF SUCH DAMAGES. THESE LIMITATIONS  * SHALL APPLY NOTWITHSTANDING THE FAILURE OF THE ESSENTIAL PURPOSE OF ANY  * LIMITED REMEDY.  *  * 4.3. Licensee shall not export, either directly or indirectly, any of this  * software or system incorporating such software without first obtaining any  * required license or other approval from the U. S. Department of Commerce or  * any other agency or department of the United States Government. In the  * event Licensee exports any such software from the United States or  * re-exports any such software from a foreign destination, Licensee shall  * ensure that the distribution and export/re-export of the software is in  * compliance with all laws, regulations, orders, or other restrictions of the  * U.S. Export Administration Regulations. Licensee agrees that neither it nor  * any of its subsidiaries will export/re-export any technical data, process,  * software, or service, directly or indirectly, to any country for which the  * United States government or any agency thereof requires an export license,  * other governmental approval, or letter of assurance, without first obtaining  * such license, approval or letter.  *  *****************************************************************************  *  * Alternatively, you may choose to be licensed under the terms of the  * following license:  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions, and the following disclaimer,  *    without modification.  * 2. Redistributions in binary form must reproduce at minimum a disclaimer  *    substantially similar to the "NO WARRANTY" disclaimer below  *    ("Disclaimer") and any redistribution must be conditioned upon  *    including a substantially similar Disclaimer requirement for further  *    binary redistribution.  * 3. Neither the names of the above-listed copyright holders nor the names  *    of any contributors may be used to endorse or promote products derived  *    from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT  * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR  * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT  * OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,  * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT  * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE  * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * Alternatively, you may choose to be licensed under the terms of the  * GNU General Public License ("GPL") version 2 as published by the Free  * Software Foundation.  *  *****************************************************************************/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_ACCONVERT
end_ifndef

begin_define
define|#
directive|define
name|_ACCONVERT
end_define

begin_comment
comment|/* Definitions for comment state */
end_comment

begin_define
define|#
directive|define
name|ASL_COMMENT_STANDARD
value|1
end_define

begin_define
define|#
directive|define
name|ASLCOMMENT_INLINE
value|2
end_define

begin_define
define|#
directive|define
name|ASL_COMMENT_OPEN_PAREN
value|3
end_define

begin_define
define|#
directive|define
name|ASL_COMMENT_CLOSE_PAREN
value|4
end_define

begin_define
define|#
directive|define
name|ASL_COMMENT_CLOSE_BRACE
value|5
end_define

begin_comment
comment|/* Definitions for comment print function*/
end_comment

begin_define
define|#
directive|define
name|AML_COMMENT_STANDARD
value|1
end_define

begin_define
define|#
directive|define
name|AMLCOMMENT_INLINE
value|2
end_define

begin_define
define|#
directive|define
name|AML_COMMENT_END_NODE
value|3
end_define

begin_define
define|#
directive|define
name|AML_NAMECOMMENT
value|4
end_define

begin_define
define|#
directive|define
name|AML_COMMENT_CLOSE_BRACE
value|5
end_define

begin_define
define|#
directive|define
name|AML_COMMENT_ENDBLK
value|6
end_define

begin_define
define|#
directive|define
name|AML_COMMENT_INCLUDE
value|7
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|ACPI_ASL_COMPILER
end_ifdef

begin_comment
comment|/*  * cvcompiler  */
end_comment

begin_function_decl
name|void
name|CvProcessComment
parameter_list|(
name|ASL_COMMENT_STATE
name|CurrentState
parameter_list|,
name|char
modifier|*
name|StringBuffer
parameter_list|,
name|int
name|c1
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|CvProcessCommentType2
parameter_list|(
name|ASL_COMMENT_STATE
name|CurrentState
parameter_list|,
name|char
modifier|*
name|StringBuffer
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|UINT32
name|CvCalculateCommentLengths
parameter_list|(
name|ACPI_PARSE_OBJECT
modifier|*
name|Op
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|CvProcessCommentState
parameter_list|(
name|char
name|input
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|CvAppendInlineComment
parameter_list|(
name|char
modifier|*
name|InlineComment
parameter_list|,
name|char
modifier|*
name|ToAdd
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|CvAddToCommentList
parameter_list|(
name|char
modifier|*
name|ToAdd
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|CvPlaceComment
parameter_list|(
name|UINT8
name|Type
parameter_list|,
name|char
modifier|*
name|CommentString
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|UINT32
name|CvParseOpBlockType
parameter_list|(
name|ACPI_PARSE_OBJECT
modifier|*
name|Op
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ACPI_COMMENT_NODE
modifier|*
name|CvCommentNodeCalloc
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|CgWriteAmlDefBlockComment
parameter_list|(
name|ACPI_PARSE_OBJECT
modifier|*
name|Op
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|CgWriteOneAmlComment
parameter_list|(
name|ACPI_PARSE_OBJECT
modifier|*
name|Op
parameter_list|,
name|char
modifier|*
name|CommentToPrint
parameter_list|,
name|UINT8
name|InputOption
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|CgWriteAmlComment
parameter_list|(
name|ACPI_PARSE_OBJECT
modifier|*
name|Op
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * cvparser  */
end_comment

begin_function_decl
name|void
name|CvInitFileTree
parameter_list|(
name|ACPI_TABLE_HEADER
modifier|*
name|Table
parameter_list|,
name|UINT8
modifier|*
name|AmlStart
parameter_list|,
name|UINT32
name|AmlLength
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|CvClearOpComments
parameter_list|(
name|ACPI_PARSE_OBJECT
modifier|*
name|Op
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ACPI_FILE_NODE
modifier|*
name|CvFilenameExists
parameter_list|(
name|char
modifier|*
name|Filename
parameter_list|,
name|ACPI_FILE_NODE
modifier|*
name|Head
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|CvLabelFileNode
parameter_list|(
name|ACPI_PARSE_OBJECT
modifier|*
name|Op
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|CvCaptureListComments
parameter_list|(
name|ACPI_PARSE_STATE
modifier|*
name|ParserState
parameter_list|,
name|ACPI_COMMENT_NODE
modifier|*
name|ListHead
parameter_list|,
name|ACPI_COMMENT_NODE
modifier|*
name|ListTail
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|CvCaptureCommentsOnly
parameter_list|(
name|ACPI_PARSE_STATE
modifier|*
name|ParserState
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|CvCaptureComments
parameter_list|(
name|ACPI_WALK_STATE
modifier|*
name|WalkState
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|CvTransferComments
parameter_list|(
name|ACPI_PARSE_OBJECT
modifier|*
name|Op
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * cvdisasm  */
end_comment

begin_function_decl
name|void
name|CvSwitchFiles
parameter_list|(
name|UINT32
name|level
parameter_list|,
name|ACPI_PARSE_OBJECT
modifier|*
name|op
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|BOOLEAN
name|CvFileHasSwitched
parameter_list|(
name|ACPI_PARSE_OBJECT
modifier|*
name|Op
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|CvCloseParenWriteComment
parameter_list|(
name|ACPI_PARSE_OBJECT
modifier|*
name|Op
parameter_list|,
name|UINT32
name|Level
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|CvCloseBraceWriteComment
parameter_list|(
name|ACPI_PARSE_OBJECT
modifier|*
name|Op
parameter_list|,
name|UINT32
name|Level
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|CvPrintOneCommentList
parameter_list|(
name|ACPI_COMMENT_NODE
modifier|*
name|CommentList
parameter_list|,
name|UINT32
name|Level
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|CvPrintOneCommentType
parameter_list|(
name|ACPI_PARSE_OBJECT
modifier|*
name|Op
parameter_list|,
name|UINT8
name|CommentType
parameter_list|,
name|char
modifier|*
name|EndStr
parameter_list|,
name|UINT32
name|Level
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _ACCONVERT */
end_comment

end_unit

