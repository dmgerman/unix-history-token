begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- MIUtilString.h ------------------------------------------*- C++ -*-===//
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//                     The LLVM Compiler Infrastructure
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// This file is distributed under the University of Illinois Open Source
end_comment

begin_comment
comment|// License. See LICENSE.TXT for details.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_pragma
pragma|#
directive|pragma
name|once
end_pragma

begin_comment
comment|// Third party headers:
end_comment

begin_include
include|#
directive|include
file|<cinttypes>
end_include

begin_include
include|#
directive|include
file|<cstdarg>
end_include

begin_include
include|#
directive|include
file|<string>
end_include

begin_include
include|#
directive|include
file|<vector>
end_include

begin_comment
comment|// In-house headers:
end_comment

begin_include
include|#
directive|include
file|"MIDataTypes.h"
end_include

begin_comment
comment|//++
end_comment

begin_comment
comment|//============================================================================
end_comment

begin_comment
comment|// Details: MI common code utility class. Used to help handle text.
end_comment

begin_comment
comment|//          Derived from std::string
end_comment

begin_comment
comment|//--
end_comment

begin_decl_stmt
name|class
name|CMIUtilString
range|:
name|public
name|std
operator|::
name|string
block|{
comment|// Typedefs:
name|public
operator|:
typedef|typedef
name|std
operator|::
name|vector
operator|<
name|CMIUtilString
operator|>
name|VecString_t
expr_stmt|;
comment|// Static method:
name|public
operator|:
specifier|static
name|CMIUtilString
name|Format
argument_list|(
specifier|const
name|char
operator|*
name|vFormating
argument_list|,
operator|...
argument_list|)
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|static
name|CMIUtilString
name|FormatBinary
parameter_list|(
specifier|const
name|MIuint64
name|vnDecimal
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|CMIUtilString
name|FormatValist
parameter_list|(
specifier|const
name|CMIUtilString
modifier|&
name|vrFormating
parameter_list|,
name|va_list
name|vArgs
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|bool
name|IsAllValidAlphaAndNumeric
parameter_list|(
specifier|const
name|char
modifier|*
name|vpText
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|bool
name|Compare
parameter_list|(
specifier|const
name|CMIUtilString
modifier|&
name|vrLhs
parameter_list|,
specifier|const
name|CMIUtilString
modifier|&
name|vrRhs
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|CMIUtilString
name|ConvertToPrintableASCII
parameter_list|(
specifier|const
name|char
name|vChar
parameter_list|,
name|bool
name|bEscapeQuotes
init|=
name|false
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|CMIUtilString
name|ConvertToPrintableASCII
parameter_list|(
specifier|const
name|char16_t
name|vChar16
parameter_list|,
name|bool
name|bEscapeQuotes
init|=
name|false
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|CMIUtilString
name|ConvertToPrintableASCII
parameter_list|(
specifier|const
name|char32_t
name|vChar32
parameter_list|,
name|bool
name|bEscapeQuotes
init|=
name|false
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|// Methods:
end_comment

begin_label
name|public
label|:
end_label

begin_comment
comment|/* ctor */
end_comment

begin_expr_stmt
name|CMIUtilString
argument_list|()
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* ctor */
end_comment

begin_expr_stmt
name|CMIUtilString
argument_list|(
specifier|const
name|char
operator|*
name|vpData
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* ctor */
end_comment

begin_expr_stmt
name|CMIUtilString
argument_list|(
specifier|const
name|std
operator|::
name|string
operator|&
name|vrStr
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|//
end_comment

begin_decl_stmt
name|bool
name|ExtractNumber
argument_list|(
name|MIint64
operator|&
name|vwrNumber
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|CMIUtilString
name|FindAndReplace
argument_list|(
specifier|const
name|CMIUtilString
operator|&
name|vFind
argument_list|,
specifier|const
name|CMIUtilString
operator|&
name|vReplaceWith
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|bool
name|IsNumber
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|bool
name|IsHexadecimalNumber
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|bool
name|IsQuoted
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt

begin_function_decl
name|CMIUtilString
name|RemoveRepeatedCharacters
parameter_list|(
specifier|const
name|char
name|vChar
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
name|size_t
name|Split
argument_list|(
specifier|const
name|CMIUtilString
operator|&
name|vDelimiter
argument_list|,
name|VecString_t
operator|&
name|vwVecSplits
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|size_t
name|SplitConsiderQuotes
argument_list|(
specifier|const
name|CMIUtilString
operator|&
name|vDelimiter
argument_list|,
name|VecString_t
operator|&
name|vwVecSplits
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|size_t
name|SplitLines
argument_list|(
name|VecString_t
operator|&
name|vwVecSplits
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|CMIUtilString
name|StripCREndOfLine
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|CMIUtilString
name|StripCRAll
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|CMIUtilString
name|Trim
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt

begin_decl_stmt
name|CMIUtilString
name|Trim
argument_list|(
specifier|const
name|char
name|vChar
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|size_t
name|FindFirst
argument_list|(
specifier|const
name|CMIUtilString
operator|&
name|vrPattern
argument_list|,
name|size_t
name|vnPos
operator|=
literal|0
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|size_t
name|FindFirst
argument_list|(
specifier|const
name|CMIUtilString
operator|&
name|vrPattern
argument_list|,
name|bool
name|vbSkipQuotedText
argument_list|,
name|bool
operator|&
name|vrwbNotFoundClosedQuote
argument_list|,
name|size_t
name|vnPos
operator|=
literal|0
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|size_t
name|FindFirstNot
argument_list|(
specifier|const
name|CMIUtilString
operator|&
name|vrPattern
argument_list|,
name|size_t
name|vnPos
operator|=
literal|0
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|CMIUtilString
name|Escape
argument_list|(
name|bool
name|vbEscapeQuotes
operator|=
name|false
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|CMIUtilString
name|AddSlashes
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|CMIUtilString
name|StripSlashes
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt

begin_comment
comment|//
end_comment

begin_decl_stmt
name|CMIUtilString
modifier|&
name|operator
init|=
operator|(
specifier|const
name|char
operator|*
name|vpRhs
operator|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|CMIUtilString
modifier|&
name|operator
init|=
operator|(
specifier|const
name|std
operator|::
name|string
operator|&
name|vrRhs
operator|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|// Overrideable:
end_comment

begin_label
name|public
label|:
end_label

begin_comment
comment|/* dtor */
end_comment

begin_expr_stmt
name|virtual
operator|~
name|CMIUtilString
argument_list|()
expr_stmt|;
end_expr_stmt

begin_comment
comment|// Static method:
end_comment

begin_label
name|private
label|:
end_label

begin_function_decl
specifier|static
name|CMIUtilString
name|FormatPriv
parameter_list|(
specifier|const
name|CMIUtilString
modifier|&
name|vrFormat
parameter_list|,
name|va_list
name|vArgs
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|CMIUtilString
name|ConvertCharValueToPrintableASCII
parameter_list|(
name|char
name|vChar
parameter_list|,
name|bool
name|bEscapeQuotes
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|// Methods:
end_comment

begin_label
name|private
label|:
end_label

begin_decl_stmt
name|bool
name|ExtractNumberFromHexadecimal
argument_list|(
name|MIint64
operator|&
name|vwrNumber
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_function_decl
name|CMIUtilString
name|RemoveRepeatedCharacters
parameter_list|(
name|size_t
name|vnPos
parameter_list|,
specifier|const
name|char
name|vChar
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
name|size_t
name|FindFirstQuote
argument_list|(
name|size_t
name|vnPos
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

unit|};
end_unit

