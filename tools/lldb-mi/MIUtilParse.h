begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- MIUtilParse.h ------------------------------------------*- C++ -*-===//
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
file|"../lib/Support/regex_impl.h"
end_include

begin_comment
comment|// In-house headers:
end_comment

begin_include
include|#
directive|include
file|"MIUtilString.h"
end_include

begin_decl_stmt
name|namespace
name|MIUtilParse
block|{
comment|//++ ============================================================================
comment|// Details: MI common code utility class. Used to parse the output
comment|//          returned from lldb commands using regex.
comment|//--
name|class
name|CRegexParser
block|{
name|public
label|:
comment|// Helper class for keeping track of regex matches.
name|class
name|Match
block|{
name|friend
name|CRegexParser
decl_stmt|;
name|public
label|:
comment|/* ctor */
name|explicit
name|Match
argument_list|(
argument|size_t nmatches
argument_list|)
block|:
name|m_matchStrs
argument_list|(
name|nmatches
argument_list|)
operator|,
name|m_maxMatches
argument_list|(
argument|nmatches
argument_list|)
block|{         }
name|size_t
name|GetMatchCount
argument_list|()
specifier|const
block|{
return|return
name|m_matchStrs
operator|.
name|size
argument_list|()
return|;
block|}
name|CMIUtilString
name|GetMatchAtIndex
argument_list|(
name|size_t
name|i
argument_list|)
decl|const
block|{
if|if
condition|(
name|m_matchStrs
operator|.
name|size
argument_list|()
operator|>
name|i
condition|)
return|return
name|m_matchStrs
index|[
name|i
index|]
return|;
return|return
name|CMIUtilString
argument_list|()
return|;
block|}
name|private
label|:
name|CMIUtilString
operator|::
name|VecString_t
name|m_matchStrs
expr_stmt|;
specifier|const
name|size_t
name|m_maxMatches
decl_stmt|;
block|}
empty_stmt|;
comment|// Methods:
comment|// Compile the regular expression.
comment|/* ctor */
name|explicit
name|CRegexParser
parameter_list|(
specifier|const
name|char
modifier|*
name|regexStr
parameter_list|)
function_decl|;
comment|// Free the memory used by the regular expression.
comment|/* dtor */
operator|~
name|CRegexParser
argument_list|()
expr_stmt|;
comment|// No copies
name|CRegexParser
argument_list|(
specifier|const
name|CRegexParser
operator|&
argument_list|)
operator|=
name|delete
expr_stmt|;
name|void
name|operator
init|=
operator|(
name|CRegexParser
operator|&
operator|)
operator|=
name|delete
decl_stmt|;
comment|// Return the match at the index.
name|int
name|GetMatchCount
argument_list|(
specifier|const
name|Match
operator|&
name|match
argument_list|)
decl|const
block|{
if|if
condition|(
name|m_isValid
condition|)
return|return
name|match
operator|.
name|GetMatchCount
argument_list|()
return|;
return|return
literal|0
return|;
block|}
name|bool
name|IsValid
argument_list|()
specifier|const
block|{
return|return
name|m_isValid
return|;
block|}
comment|// Match the input against the regular expression.  Return an error
comment|// if the number of matches is less than minMatches.  If the default
comment|// minMatches value of 0 is passed, an error will be returned if
comment|// the number of matches is less than the maxMatches value used to
comment|// initialize Match.
name|bool
name|Execute
parameter_list|(
specifier|const
name|char
modifier|*
name|input
parameter_list|,
name|Match
modifier|&
name|match
parameter_list|,
name|size_t
name|minMatches
init|=
literal|0
parameter_list|)
function_decl|;
name|private
label|:
name|llvm_regex_t
name|m_emma
decl_stmt|;
specifier|const
name|bool
name|m_isValid
decl_stmt|;
block|}
empty_stmt|;
block|}
end_decl_stmt

end_unit

