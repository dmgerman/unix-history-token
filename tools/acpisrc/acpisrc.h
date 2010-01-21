begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/******************************************************************************  *  * Module Name: acpisrc.h - Include file for AcpiSrc utility  *  *****************************************************************************/
end_comment

begin_comment
comment|/******************************************************************************  *  * 1. Copyright Notice  *  * Some or all of this work - Copyright (c) 1999 - 2010, Intel Corp.  * All rights reserved.  *  * 2. License  *  * 2.1. This is your license from Intel Corp. under its intellectual property  * rights.  You may have additional license terms from the party that provided  * you this software, covering your right to use that party's intellectual  * property rights.  *  * 2.2. Intel grants, free of charge, to any person ("Licensee") obtaining a  * copy of the source code appearing in this file ("Covered Code") an  * irrevocable, perpetual, worldwide license under Intel's copyrights in the  * base code distributed originally by Intel ("Original Intel Code") to copy,  * make derivatives, distribute, use and display any portion of the Covered  * Code in any form, with the right to sublicense such rights; and  *  * 2.3. Intel grants Licensee a non-exclusive and non-transferable patent  * license (with the right to sublicense), under only those claims of Intel  * patents that are infringed by the Original Intel Code, to make, use, sell,  * offer to sell, and import the Covered Code and derivative works thereof  * solely to the minimum extent necessary to exercise the above copyright  * license, and in no event shall the patent license extend to any additions  * to or modifications of the Original Intel Code.  No other license or right  * is granted directly or by implication, estoppel or otherwise;  *  * The above copyright and patent license is granted only if the following  * conditions are met:  *  * 3. Conditions  *  * 3.1. Redistribution of Source with Rights to Further Distribute Source.  * Redistribution of source code of any substantial portion of the Covered  * Code or modification with rights to further distribute source must include  * the above Copyright Notice, the above License, this list of Conditions,  * and the following Disclaimer and Export Compliance provision.  In addition,  * Licensee must cause all Covered Code to which Licensee contributes to  * contain a file documenting the changes Licensee made to create that Covered  * Code and the date of any change.  Licensee must include in that file the  * documentation of any changes made by any predecessor Licensee.  Licensee  * must include a prominent statement that the modification is derived,  * directly or indirectly, from Original Intel Code.  *  * 3.2. Redistribution of Source with no Rights to Further Distribute Source.  * Redistribution of source code of any substantial portion of the Covered  * Code or modification without rights to further distribute source must  * include the following Disclaimer and Export Compliance provision in the  * documentation and/or other materials provided with distribution.  In  * addition, Licensee may not authorize further sublicense of source of any  * portion of the Covered Code, and must include terms to the effect that the  * license from Licensee to its licensee is limited to the intellectual  * property embodied in the software Licensee provides to its licensee, and  * not to intellectual property embodied in modifications its licensee may  * make.  *  * 3.3. Redistribution of Executable. Redistribution in executable form of any  * substantial portion of the Covered Code or modification must reproduce the  * above Copyright Notice, and the following Disclaimer and Export Compliance  * provision in the documentation and/or other materials provided with the  * distribution.  *  * 3.4. Intel retains all right, title, and interest in and to the Original  * Intel Code.  *  * 3.5. Neither the name Intel nor any other trademark owned or controlled by  * Intel shall be used in advertising or otherwise to promote the sale, use or  * other dealings in products derived from or relating to the Covered Code  * without prior written authorization from Intel.  *  * 4. Disclaimer and Export Compliance  *  * 4.1. INTEL MAKES NO WARRANTY OF ANY KIND REGARDING ANY SOFTWARE PROVIDED  * HERE.  ANY SOFTWARE ORIGINATING FROM INTEL OR DERIVED FROM INTEL SOFTWARE  * IS PROVIDED "AS IS," AND INTEL WILL NOT PROVIDE ANY SUPPORT,  ASSISTANCE,  * INSTALLATION, TRAINING OR OTHER SERVICES.  INTEL WILL NOT PROVIDE ANY  * UPDATES, ENHANCEMENTS OR EXTENSIONS.  INTEL SPECIFICALLY DISCLAIMS ANY  * IMPLIED WARRANTIES OF MERCHANTABILITY, NONINFRINGEMENT AND FITNESS FOR A  * PARTICULAR PURPOSE.  *  * 4.2. IN NO EVENT SHALL INTEL HAVE ANY LIABILITY TO LICENSEE, ITS LICENSEES  * OR ANY OTHER THIRD PARTY, FOR ANY LOST PROFITS, LOST DATA, LOSS OF USE OR  * COSTS OF PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES, OR FOR ANY INDIRECT,  * SPECIAL OR CONSEQUENTIAL DAMAGES ARISING OUT OF THIS AGREEMENT, UNDER ANY  * CAUSE OF ACTION OR THEORY OF LIABILITY, AND IRRESPECTIVE OF WHETHER INTEL  * HAS ADVANCE NOTICE OF THE POSSIBILITY OF SUCH DAMAGES.  THESE LIMITATIONS  * SHALL APPLY NOTWITHSTANDING THE FAILURE OF THE ESSENTIAL PURPOSE OF ANY  * LIMITED REMEDY.  *  * 4.3. Licensee shall not export, either directly or indirectly, any of this  * software or system incorporating such software without first obtaining any  * required license or other approval from the U. S. Department of Commerce or  * any other agency or department of the United States Government.  In the  * event Licensee exports any such software from the United States or  * re-exports any such software from a foreign destination, Licensee shall  * ensure that the distribution and export/re-export of the software is in  * compliance with all laws, regulations, orders, or other restrictions of the  * U.S. Export Administration Regulations. Licensee agrees that neither it nor  * any of its subsidiaries will export/re-export any technical data, process,  * software, or service, directly or indirectly, to any country for which the  * United States government or any agency thereof requires an export license,  * other governmental approval, or letter of assurance, without first obtaining  * such license, approval or letter.  *  *****************************************************************************/
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
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<fcntl.h>
end_include

begin_include
include|#
directive|include
file|<ctype.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|WIN32
end_ifdef

begin_include
include|#
directive|include
file|<io.h>
end_include

begin_include
include|#
directive|include
file|<direct.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<errno.h>
end_include

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

begin_comment
comment|/* Fixups for non-Win32 compilation */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|WIN32
end_ifndef

begin_ifndef
ifndef|#
directive|ifndef
name|O_BINARY
end_ifndef

begin_define
define|#
directive|define
name|O_BINARY
value|0x0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|mkdir
parameter_list|(
name|x
parameter_list|)
value|mkdir(x, 0770)
end_define

begin_function_decl
name|char
modifier|*
name|strlwr
parameter_list|(
name|char
modifier|*
name|str
parameter_list|)
function_decl|;
end_function_decl

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
name|UINT32
name|HeaderFunctions
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

end_unit

