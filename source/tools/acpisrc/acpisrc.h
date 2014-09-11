begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/******************************************************************************  *  * Module Name: acpisrc.h - Include file for AcpiSrc utility  *  *****************************************************************************/
end_comment

begin_comment
comment|/*  * Copyright (C) 2000 - 2014, Intel Corp.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions, and the following disclaimer,  *    without modification.  * 2. Redistributions in binary form must reproduce at minimum a disclaimer  *    substantially similar to the "NO WARRANTY" disclaimer below  *    ("Disclaimer") and any redistribution must be conditioned upon  *    including a substantially similar Disclaimer requirement for further  *    binary redistribution.  * 3. Neither the names of the above-listed copyright holders nor the names  *    of any contributors may be used to endorse or promote products derived  *    from this software without specific prior written permission.  *  * Alternatively, this software may be distributed under the terms of the  * GNU General Public License ("GPL") version 2 as published by the Free  * Software Foundation.  *  * NO WARRANTY  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT  * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTIBILITY AND FITNESS FOR  * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT  * HOLDERS OR CONTRIBUTORS BE LIABLE FOR SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,  * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING  * IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  * POSSIBILITY OF SUCH DAMAGES.  */
end_comment

begin_include
include|#
directive|include
file|"acpi.h"
end_include

begin_include
include|#
directive|include
file|"accommon.h"
end_include

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<sys/stat.h>
end_include

begin_include
include|#
directive|include
file|<errno.h>
end_include

begin_comment
comment|/* mkdir support */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|WIN32
end_ifdef

begin_include
include|#
directive|include
file|<direct.h>
end_include

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|mkdir
parameter_list|(
name|x
parameter_list|)
value|mkdir(x, 0770)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Constants */
end_comment

begin_define
define|#
directive|define
name|LINES_IN_LEGAL_HEADER
value|105
end_define

begin_comment
comment|/* See above */
end_comment

begin_define
define|#
directive|define
name|LEGAL_HEADER_SIGNATURE
value|" * 2.1. This is your license from Intel Corp. under its intellectual property"
end_define

begin_define
define|#
directive|define
name|LINES_IN_LINUX_HEADER
value|34
end_define

begin_define
define|#
directive|define
name|LINUX_HEADER_SIGNATURE
value|" * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS"
end_define

begin_define
define|#
directive|define
name|LINES_IN_ASL_HEADER
value|29
end_define

begin_comment
comment|/* Header as output from disassembler */
end_comment

begin_define
define|#
directive|define
name|ASRC_MAX_FILE_SIZE
value|(1024 * 100)
end_define

begin_define
define|#
directive|define
name|FILE_TYPE_SOURCE
value|1
end_define

begin_define
define|#
directive|define
name|FILE_TYPE_HEADER
value|2
end_define

begin_define
define|#
directive|define
name|FILE_TYPE_DIRECTORY
value|3
end_define

begin_define
define|#
directive|define
name|FILE_TYPE_PATCH
value|4
end_define

begin_define
define|#
directive|define
name|CVT_COUNT_TABS
value|0x00000001
end_define

begin_define
define|#
directive|define
name|CVT_COUNT_NON_ANSI_COMMENTS
value|0x00000002
end_define

begin_define
define|#
directive|define
name|CVT_TRIM_LINES
value|0x00000004
end_define

begin_define
define|#
directive|define
name|CVT_CHECK_BRACES
value|0x00000008
end_define

begin_define
define|#
directive|define
name|CVT_COUNT_LINES
value|0x00000010
end_define

begin_define
define|#
directive|define
name|CVT_BRACES_ON_SAME_LINE
value|0x00000020
end_define

begin_define
define|#
directive|define
name|CVT_MIXED_CASE_TO_UNDERSCORES
value|0x00000040
end_define

begin_define
define|#
directive|define
name|CVT_LOWER_CASE_IDENTIFIERS
value|0x00000080
end_define

begin_define
define|#
directive|define
name|CVT_REMOVE_DEBUG_MACROS
value|0x00000100
end_define

begin_define
define|#
directive|define
name|CVT_TRIM_WHITESPACE
value|0x00000200
end_define

begin_comment
comment|/* Should be after all line removal */
end_comment

begin_define
define|#
directive|define
name|CVT_REMOVE_EMPTY_BLOCKS
value|0x00000400
end_define

begin_comment
comment|/* Should be after trimming lines */
end_comment

begin_define
define|#
directive|define
name|CVT_REDUCE_TYPEDEFS
value|0x00000800
end_define

begin_define
define|#
directive|define
name|CVT_COUNT_SHORTMULTILINE_COMMENTS
value|0x00001000
end_define

begin_define
define|#
directive|define
name|CVT_SPACES_TO_TABS4
value|0x40000000
end_define

begin_comment
comment|/* Tab conversion should be last */
end_comment

begin_define
define|#
directive|define
name|CVT_SPACES_TO_TABS8
value|0x80000000
end_define

begin_comment
comment|/* Tab conversion should be last */
end_comment

begin_define
define|#
directive|define
name|FLG_DEFAULT_FLAGS
value|0x00000000
end_define

begin_define
define|#
directive|define
name|FLG_NO_CARRIAGE_RETURNS
value|0x00000001
end_define

begin_define
define|#
directive|define
name|FLG_NO_FILE_OUTPUT
value|0x00000002
end_define

begin_define
define|#
directive|define
name|FLG_LOWERCASE_DIRNAMES
value|0x00000004
end_define

begin_define
define|#
directive|define
name|AS_START_IGNORE
value|"/*!"
end_define

begin_define
define|#
directive|define
name|AS_STOP_IGNORE
value|"!*/"
end_define

begin_comment
comment|/* Globals */
end_comment

begin_decl_stmt
specifier|extern
name|UINT32
name|Gbl_Files
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|UINT32
name|Gbl_MissingBraces
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|UINT32
name|Gbl_Tabs
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|UINT32
name|Gbl_NonAnsiComments
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|UINT32
name|Gbl_SourceLines
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|UINT32
name|Gbl_WhiteLines
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|UINT32
name|Gbl_CommentLines
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|UINT32
name|Gbl_LongLines
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|UINT32
name|Gbl_TotalLines
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|UINT32
name|Gbl_HeaderSize
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|UINT32
name|Gbl_HeaderLines
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|stat
name|Gbl_StatBuf
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|Gbl_FileBuffer
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|UINT32
name|Gbl_TotalSize
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|UINT32
name|Gbl_FileSize
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|UINT32
name|Gbl_FileType
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|BOOLEAN
name|Gbl_VerboseMode
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|BOOLEAN
name|Gbl_QuietMode
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|BOOLEAN
name|Gbl_BatchMode
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|BOOLEAN
name|Gbl_MadeChanges
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|BOOLEAN
name|Gbl_Overwrite
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|BOOLEAN
name|Gbl_WidenDeclarations
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|BOOLEAN
name|Gbl_IgnoreLoneLineFeeds
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|BOOLEAN
name|Gbl_HasLoneLineFeeds
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|BOOLEAN
name|Gbl_Cleanup
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|BOOLEAN
name|Gbl_IgnoreTranslationEscapes
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
modifier|*
name|Gbl_StructDefs
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|PARAM_LIST
parameter_list|(
name|pl
parameter_list|)
value|pl
end_define

begin_define
define|#
directive|define
name|TERSE_PRINT
parameter_list|(
name|a
parameter_list|)
value|if (!Gbl_VerboseMode) printf PARAM_LIST(a)
end_define

begin_define
define|#
directive|define
name|VERBOSE_PRINT
parameter_list|(
name|a
parameter_list|)
value|if (Gbl_VerboseMode) printf PARAM_LIST(a)
end_define

begin_define
define|#
directive|define
name|REPLACE_WHOLE_WORD
value|0x00
end_define

begin_define
define|#
directive|define
name|REPLACE_SUBSTRINGS
value|0x01
end_define

begin_define
define|#
directive|define
name|REPLACE_MASK
value|0x01
end_define

begin_define
define|#
directive|define
name|EXTRA_INDENT_C
value|0x02
end_define

begin_comment
comment|/* Conversion table structs */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|acpi_string_table
block|{
name|char
modifier|*
name|Target
decl_stmt|;
name|char
modifier|*
name|Replacement
decl_stmt|;
name|UINT8
name|Type
decl_stmt|;
block|}
name|ACPI_STRING_TABLE
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|acpi_typed_identifier_table
block|{
name|char
modifier|*
name|Identifier
decl_stmt|;
name|UINT8
name|Type
decl_stmt|;
block|}
name|ACPI_TYPED_IDENTIFIER_TABLE
typedef|;
end_typedef

begin_define
define|#
directive|define
name|SRC_TYPE_SIMPLE
value|0
end_define

begin_define
define|#
directive|define
name|SRC_TYPE_STRUCT
value|1
end_define

begin_define
define|#
directive|define
name|SRC_TYPE_UNION
value|2
end_define

begin_typedef
typedef|typedef
struct|struct
name|acpi_identifier_table
block|{
name|char
modifier|*
name|Identifier
decl_stmt|;
block|}
name|ACPI_IDENTIFIER_TABLE
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|acpi_conversion_table
block|{
name|char
modifier|*
name|NewHeader
decl_stmt|;
name|UINT32
name|Flags
decl_stmt|;
name|ACPI_TYPED_IDENTIFIER_TABLE
modifier|*
name|LowerCaseTable
decl_stmt|;
name|ACPI_STRING_TABLE
modifier|*
name|SourceStringTable
decl_stmt|;
name|ACPI_IDENTIFIER_TABLE
modifier|*
name|SourceLineTable
decl_stmt|;
name|ACPI_IDENTIFIER_TABLE
modifier|*
name|SourceConditionalTable
decl_stmt|;
name|ACPI_IDENTIFIER_TABLE
modifier|*
name|SourceMacroTable
decl_stmt|;
name|ACPI_TYPED_IDENTIFIER_TABLE
modifier|*
name|SourceStructTable
decl_stmt|;
name|ACPI_IDENTIFIER_TABLE
modifier|*
name|SourceSpecialMacroTable
decl_stmt|;
name|UINT32
name|SourceFunctions
decl_stmt|;
name|ACPI_STRING_TABLE
modifier|*
name|HeaderStringTable
decl_stmt|;
name|ACPI_IDENTIFIER_TABLE
modifier|*
name|HeaderLineTable
decl_stmt|;
name|ACPI_IDENTIFIER_TABLE
modifier|*
name|HeaderConditionalTable
decl_stmt|;
name|ACPI_IDENTIFIER_TABLE
modifier|*
name|HeaderMacroTable
decl_stmt|;
name|ACPI_TYPED_IDENTIFIER_TABLE
modifier|*
name|HeaderStructTable
decl_stmt|;
name|ACPI_IDENTIFIER_TABLE
modifier|*
name|HeaderSpecialMacroTable
decl_stmt|;
name|UINT32
name|HeaderFunctions
decl_stmt|;
name|ACPI_STRING_TABLE
modifier|*
name|PatchStringTable
decl_stmt|;
name|ACPI_IDENTIFIER_TABLE
modifier|*
name|PatchLineTable
decl_stmt|;
name|ACPI_IDENTIFIER_TABLE
modifier|*
name|PatchConditionalTable
decl_stmt|;
name|ACPI_IDENTIFIER_TABLE
modifier|*
name|PatchMacroTable
decl_stmt|;
name|ACPI_TYPED_IDENTIFIER_TABLE
modifier|*
name|PatchStructTable
decl_stmt|;
name|ACPI_IDENTIFIER_TABLE
modifier|*
name|PatchSpecialMacroTable
decl_stmt|;
name|UINT32
name|PatchFunctions
decl_stmt|;
block|}
name|ACPI_CONVERSION_TABLE
typedef|;
end_typedef

begin_comment
comment|/* Conversion tables */
end_comment

begin_decl_stmt
specifier|extern
name|ACPI_CONVERSION_TABLE
name|LinuxConversionTable
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|ACPI_CONVERSION_TABLE
name|CleanupConversionTable
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|ACPI_CONVERSION_TABLE
name|StatsConversionTable
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|ACPI_CONVERSION_TABLE
name|CustomConversionTable
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|ACPI_CONVERSION_TABLE
name|LicenseConversionTable
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|ACPI_CONVERSION_TABLE
name|IndentConversionTable
decl_stmt|;
end_decl_stmt

begin_typedef
typedef|typedef
name|char
modifier|*
function_decl|(
modifier|*
name|AS_SCAN_CALLBACK
function_decl|)
parameter_list|(
name|char
modifier|*
name|Buffer
parameter_list|,
name|char
modifier|*
name|Filename
parameter_list|,
name|UINT32
name|LineNumber
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|as_brace_info
block|{
name|char
modifier|*
name|Operator
decl_stmt|;
name|UINT32
name|Length
decl_stmt|;
block|}
name|AS_BRACE_INFO
typedef|;
end_typedef

begin_comment
comment|/* Prototypes */
end_comment

begin_function_decl
name|char
modifier|*
name|AsSkipUntilChar
parameter_list|(
name|char
modifier|*
name|Buffer
parameter_list|,
name|char
name|Target
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|AsSkipPastChar
parameter_list|(
name|char
modifier|*
name|Buffer
parameter_list|,
name|char
name|Target
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|AsReplaceData
parameter_list|(
name|char
modifier|*
name|Buffer
parameter_list|,
name|UINT32
name|LengthToRemove
parameter_list|,
name|char
modifier|*
name|BufferToAdd
parameter_list|,
name|UINT32
name|LengthToAdd
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|AsReplaceString
parameter_list|(
name|char
modifier|*
name|Target
parameter_list|,
name|char
modifier|*
name|Replacement
parameter_list|,
name|UINT8
name|Type
parameter_list|,
name|char
modifier|*
name|Buffer
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|AsLowerCaseString
parameter_list|(
name|char
modifier|*
name|Target
parameter_list|,
name|char
modifier|*
name|Buffer
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|AsRemoveLine
parameter_list|(
name|char
modifier|*
name|Buffer
parameter_list|,
name|char
modifier|*
name|Keyword
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|AsRemoveMacro
parameter_list|(
name|char
modifier|*
name|Buffer
parameter_list|,
name|char
modifier|*
name|Keyword
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|AsCheckForBraces
parameter_list|(
name|char
modifier|*
name|Buffer
parameter_list|,
name|char
modifier|*
name|Filename
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|AsTrimLines
parameter_list|(
name|char
modifier|*
name|Buffer
parameter_list|,
name|char
modifier|*
name|Filename
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|AsMixedCaseToUnderscores
parameter_list|(
name|char
modifier|*
name|Buffer
parameter_list|,
name|char
modifier|*
name|Filename
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|AsCountTabs
parameter_list|(
name|char
modifier|*
name|Buffer
parameter_list|,
name|char
modifier|*
name|Filename
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|AsBracesOnSameLine
parameter_list|(
name|char
modifier|*
name|Buffer
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|AsLowerCaseIdentifiers
parameter_list|(
name|char
modifier|*
name|Buffer
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|AsReduceTypedefs
parameter_list|(
name|char
modifier|*
name|Buffer
parameter_list|,
name|char
modifier|*
name|Keyword
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|AsRemoveDebugMacros
parameter_list|(
name|char
modifier|*
name|Buffer
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|AsRemoveEmptyBlocks
parameter_list|(
name|char
modifier|*
name|Buffer
parameter_list|,
name|char
modifier|*
name|Filename
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|AsCleanupSpecialMacro
parameter_list|(
name|char
modifier|*
name|Buffer
parameter_list|,
name|char
modifier|*
name|Keyword
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|AsCountSourceLines
parameter_list|(
name|char
modifier|*
name|Buffer
parameter_list|,
name|char
modifier|*
name|Filename
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|AsCountNonAnsiComments
parameter_list|(
name|char
modifier|*
name|Buffer
parameter_list|,
name|char
modifier|*
name|Filename
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|AsTrimWhitespace
parameter_list|(
name|char
modifier|*
name|Buffer
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|AsTabify4
parameter_list|(
name|char
modifier|*
name|Buffer
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|AsTabify8
parameter_list|(
name|char
modifier|*
name|Buffer
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|AsRemoveConditionalCompile
parameter_list|(
name|char
modifier|*
name|Buffer
parameter_list|,
name|char
modifier|*
name|Keyword
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ACPI_NATIVE_INT
name|AsProcessTree
parameter_list|(
name|ACPI_CONVERSION_TABLE
modifier|*
name|ConversionTable
parameter_list|,
name|char
modifier|*
name|SourcePath
parameter_list|,
name|char
modifier|*
name|TargetPath
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|AsGetFile
parameter_list|(
name|char
modifier|*
name|FileName
parameter_list|,
name|char
modifier|*
modifier|*
name|FileBuffer
parameter_list|,
name|UINT32
modifier|*
name|FileSize
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|AsPutFile
parameter_list|(
name|char
modifier|*
name|Pathname
parameter_list|,
name|char
modifier|*
name|FileBuffer
parameter_list|,
name|UINT32
name|SystemFlags
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|AsReplaceHeader
parameter_list|(
name|char
modifier|*
name|Buffer
parameter_list|,
name|char
modifier|*
name|NewHeader
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|AsConvertFile
parameter_list|(
name|ACPI_CONVERSION_TABLE
modifier|*
name|ConversionTable
parameter_list|,
name|char
modifier|*
name|FileBuffer
parameter_list|,
name|char
modifier|*
name|Filename
parameter_list|,
name|ACPI_NATIVE_INT
name|FileType
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ACPI_NATIVE_INT
name|AsProcessOneFile
parameter_list|(
name|ACPI_CONVERSION_TABLE
modifier|*
name|ConversionTable
parameter_list|,
name|char
modifier|*
name|SourcePath
parameter_list|,
name|char
modifier|*
name|TargetPath
parameter_list|,
name|int
name|MaxPathLength
parameter_list|,
name|char
modifier|*
name|Filename
parameter_list|,
name|ACPI_NATIVE_INT
name|FileType
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ACPI_NATIVE_INT
name|AsCheckForDirectory
parameter_list|(
name|char
modifier|*
name|SourceDirPath
parameter_list|,
name|char
modifier|*
name|TargetDirPath
parameter_list|,
name|char
modifier|*
name|Filename
parameter_list|,
name|char
modifier|*
modifier|*
name|SourcePath
parameter_list|,
name|char
modifier|*
modifier|*
name|TargetPath
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|AsRemoveExtraLines
parameter_list|(
name|char
modifier|*
name|FileBuffer
parameter_list|,
name|char
modifier|*
name|Filename
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|AsRemoveSpacesAfterPeriod
parameter_list|(
name|char
modifier|*
name|FileBuffer
parameter_list|,
name|char
modifier|*
name|Filename
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|BOOLEAN
name|AsMatchExactWord
parameter_list|(
name|char
modifier|*
name|Word
parameter_list|,
name|UINT32
name|WordLength
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|AsPrint
parameter_list|(
name|char
modifier|*
name|Message
parameter_list|,
name|UINT32
name|Count
parameter_list|,
name|char
modifier|*
name|Filename
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|AsInsertPrefix
parameter_list|(
name|char
modifier|*
name|Buffer
parameter_list|,
name|char
modifier|*
name|Keyword
parameter_list|,
name|UINT8
name|Type
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|AsInsertData
parameter_list|(
name|char
modifier|*
name|Buffer
parameter_list|,
name|char
modifier|*
name|BufferToAdd
parameter_list|,
name|UINT32
name|LengthToAdd
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|AsRemoveData
parameter_list|(
name|char
modifier|*
name|StartPointer
parameter_list|,
name|char
modifier|*
name|EndPointer
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|AsInsertCarriageReturns
parameter_list|(
name|char
modifier|*
name|Buffer
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|AsConvertToLineFeeds
parameter_list|(
name|char
modifier|*
name|Buffer
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|AsStrlwr
parameter_list|(
name|char
modifier|*
name|SrcString
parameter_list|)
function_decl|;
end_function_decl

end_unit

