begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/******************************************************************************  *  * Module Name: acapps - common include for ACPI applications/tools  *  *****************************************************************************/
end_comment

begin_comment
comment|/*  * Copyright (C) 2000 - 2017, Intel Corp.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions, and the following disclaimer,  *    without modification.  * 2. Redistributions in binary form must reproduce at minimum a disclaimer  *    substantially similar to the "NO WARRANTY" disclaimer below  *    ("Disclaimer") and any redistribution must be conditioned upon  *    including a substantially similar Disclaimer requirement for further  *    binary redistribution.  * 3. Neither the names of the above-listed copyright holders nor the names  *    of any contributors may be used to endorse or promote products derived  *    from this software without specific prior written permission.  *  * Alternatively, this software may be distributed under the terms of the  * GNU General Public License ("GPL") version 2 as published by the Free  * Software Foundation.  *  * NO WARRANTY  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT  * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTIBILITY AND FITNESS FOR  * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT  * HOLDERS OR CONTRIBUTORS BE LIABLE FOR SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,  * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING  * IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  * POSSIBILITY OF SUCH DAMAGES.  */
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

