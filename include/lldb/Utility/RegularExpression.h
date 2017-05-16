begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- RegularExpression.h -------------------------------------*- C++ -*-===//
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

begin_ifndef
ifndef|#
directive|ifndef
name|liblldb_RegularExpression_h_
end_ifndef

begin_define
define|#
directive|define
name|liblldb_RegularExpression_h_
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|_WIN32
end_ifdef

begin_include
include|#
directive|include
file|"../lib/Support/regex_impl.h"
end_include

begin_typedef
typedef|typedef
name|llvm_regmatch_t
name|regmatch_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|llvm_regex_t
name|regex_t
typedef|;
end_typedef

begin_function
specifier|inline
name|int
name|regcomp
parameter_list|(
name|llvm_regex_t
modifier|*
name|a
parameter_list|,
specifier|const
name|char
modifier|*
name|b
parameter_list|,
name|int
name|c
parameter_list|)
block|{
return|return
name|llvm_regcomp
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|)
return|;
block|}
end_function

begin_function
specifier|inline
name|size_t
name|regerror
parameter_list|(
name|int
name|a
parameter_list|,
specifier|const
name|llvm_regex_t
modifier|*
name|b
parameter_list|,
name|char
modifier|*
name|c
parameter_list|,
name|size_t
name|d
parameter_list|)
block|{
return|return
name|llvm_regerror
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|,
name|d
argument_list|)
return|;
block|}
end_function

begin_function
specifier|inline
name|int
name|regexec
parameter_list|(
specifier|const
name|llvm_regex_t
modifier|*
name|a
parameter_list|,
specifier|const
name|char
modifier|*
name|b
parameter_list|,
name|size_t
name|c
parameter_list|,
name|llvm_regmatch_t
name|d
index|[]
parameter_list|,
name|int
name|e
parameter_list|)
block|{
return|return
name|llvm_regexec
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|,
name|d
argument_list|,
name|e
argument_list|)
return|;
block|}
end_function

begin_function
specifier|inline
name|void
name|regfree
parameter_list|(
name|llvm_regex_t
modifier|*
name|a
parameter_list|)
block|{
name|llvm_regfree
argument_list|(
name|a
argument_list|)
expr_stmt|;
block|}
end_function

begin_else
else|#
directive|else
end_else

begin_ifdef
ifdef|#
directive|ifdef
name|__ANDROID__
end_ifdef

begin_include
include|#
directive|include
file|<regex>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<regex.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

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

begin_include
include|#
directive|include
file|<stddef.h>
end_include

begin_comment
comment|// for size_t
end_comment

begin_include
include|#
directive|include
file|<stdint.h>
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|StringRef
decl_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// namespace llvm
end_comment

begin_decl_stmt
name|namespace
name|lldb_private
block|{
comment|//----------------------------------------------------------------------
comment|/// @class RegularExpression RegularExpression.h
comment|/// "lldb/Utility/RegularExpression.h"
comment|/// @brief A C++ wrapper class for regex.
comment|///
comment|/// This regular expression class wraps the posix regex functions
comment|/// \c regcomp(), \c regerror(), \c regexec(), and \c regfree() from
comment|/// the header file in \c /usr/include/regex\.h.
comment|//----------------------------------------------------------------------
name|class
name|RegularExpression
block|{
name|public
label|:
name|class
name|Match
block|{
name|public
label|:
name|Match
argument_list|(
argument|uint32_t max_matches
argument_list|)
block|:
name|m_matches
argument_list|()
block|{
if|if
condition|(
name|max_matches
operator|>
literal|0
condition|)
name|m_matches
operator|.
name|resize
argument_list|(
name|max_matches
operator|+
literal|1
argument_list|)
expr_stmt|;
block|}
name|void
name|Clear
parameter_list|()
block|{
specifier|const
name|size_t
name|num_matches
init|=
name|m_matches
operator|.
name|size
argument_list|()
decl_stmt|;
name|regmatch_t
name|invalid_match
init|=
block|{
operator|-
literal|1
block|,
operator|-
literal|1
block|}
decl_stmt|;
for|for
control|(
name|size_t
name|i
init|=
literal|0
init|;
name|i
operator|<
name|num_matches
condition|;
operator|++
name|i
control|)
name|m_matches
index|[
name|i
index|]
operator|=
name|invalid_match
expr_stmt|;
block|}
name|size_t
name|GetSize
argument_list|()
specifier|const
block|{
return|return
name|m_matches
operator|.
name|size
argument_list|()
return|;
block|}
name|regmatch_t
modifier|*
name|GetData
parameter_list|()
block|{
return|return
operator|(
name|m_matches
operator|.
name|empty
argument_list|()
condition|?
name|nullptr
else|:
name|m_matches
operator|.
name|data
argument_list|()
operator|)
return|;
block|}
name|bool
name|GetMatchAtIndex
argument_list|(
name|llvm
operator|::
name|StringRef
name|s
argument_list|,
name|uint32_t
name|idx
argument_list|,
name|std
operator|::
name|string
operator|&
name|match_str
argument_list|)
decl|const
decl_stmt|;
name|bool
name|GetMatchAtIndex
argument_list|(
name|llvm
operator|::
name|StringRef
name|s
argument_list|,
name|uint32_t
name|idx
argument_list|,
name|llvm
operator|::
name|StringRef
operator|&
name|match_str
argument_list|)
decl|const
decl_stmt|;
name|bool
name|GetMatchSpanningIndices
argument_list|(
name|llvm
operator|::
name|StringRef
name|s
argument_list|,
name|uint32_t
name|idx1
argument_list|,
name|uint32_t
name|idx2
argument_list|,
name|llvm
operator|::
name|StringRef
operator|&
name|match_str
argument_list|)
decl|const
decl_stmt|;
name|protected
label|:
name|std
operator|::
name|vector
operator|<
name|regmatch_t
operator|>
name|m_matches
expr_stmt|;
comment|///< Where parenthesized subexpressions results are stored
block|}
empty_stmt|;
comment|//------------------------------------------------------------------
comment|/// Default constructor.
comment|///
comment|/// The default constructor that initializes the object state such
comment|/// that it contains no compiled regular expression.
comment|//------------------------------------------------------------------
name|RegularExpression
argument_list|()
expr_stmt|;
name|explicit
name|RegularExpression
argument_list|(
name|llvm
operator|::
name|StringRef
name|string
argument_list|)
decl_stmt|;
comment|//------------------------------------------------------------------
comment|/// Destructor.
comment|///
comment|/// Any previously compiled regular expression contained in this
comment|/// object will be freed.
comment|//------------------------------------------------------------------
operator|~
name|RegularExpression
argument_list|()
expr_stmt|;
name|RegularExpression
argument_list|(
specifier|const
name|RegularExpression
operator|&
name|rhs
argument_list|)
expr_stmt|;
specifier|const
name|RegularExpression
modifier|&
name|operator
init|=
operator|(
specifier|const
name|RegularExpression
operator|&
name|rhs
operator|)
decl_stmt|;
comment|//------------------------------------------------------------------
comment|/// Compile a regular expression.
comment|///
comment|/// Compile a regular expression using the supplied regular
comment|/// expression text. The compiled regular expression lives
comment|/// in this object so that it can be readily used for regular
comment|/// expression matches. Execute() can be called after the regular
comment|/// expression is compiled. Any previously compiled regular
comment|/// expression contained in this object will be freed.
comment|///
comment|/// @param[in] re
comment|///     A NULL terminated C string that represents the regular
comment|///     expression to compile.
comment|///
comment|/// @return
comment|///     \b true if the regular expression compiles successfully,
comment|///     \b false otherwise.
comment|//------------------------------------------------------------------
name|bool
name|Compile
argument_list|(
name|llvm
operator|::
name|StringRef
name|string
argument_list|)
decl_stmt|;
name|bool
name|Compile
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
init|=
name|delete
function_decl|;
comment|//------------------------------------------------------------------
comment|/// Executes a regular expression.
comment|///
comment|/// Execute a regular expression match using the compiled regular
comment|/// expression that is already in this object against the match
comment|/// string \a s. If any parens are used for regular expression
comment|/// matches \a match_count should indicate the number of regmatch_t
comment|/// values that are present in \a match_ptr.
comment|///
comment|/// @param[in] string
comment|///     The string to match against the compile regular expression.
comment|///
comment|/// @param[in] match
comment|///     A pointer to a RegularExpression::Match structure that was
comment|///     properly initialized with the desired number of maximum
comment|///     matches, or nullptr if no parenthesized matching is needed.
comment|///
comment|/// @return
comment|///     \b true if \a string matches the compiled regular
comment|///     expression, \b false otherwise.
comment|//------------------------------------------------------------------
name|bool
name|Execute
argument_list|(
name|llvm
operator|::
name|StringRef
name|string
argument_list|,
name|Match
operator|*
name|match
operator|=
name|nullptr
argument_list|)
decl|const
decl_stmt|;
name|bool
name|Execute
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|Match
modifier|*
init|=
name|nullptr
parameter_list|)
init|=
name|delete
function_decl|;
name|size_t
name|GetErrorAsCString
argument_list|(
name|char
operator|*
name|err_str
argument_list|,
name|size_t
name|err_str_max_len
argument_list|)
decl|const
decl_stmt|;
comment|//------------------------------------------------------------------
comment|/// Free the compiled regular expression.
comment|///
comment|/// If this object contains a valid compiled regular expression,
comment|/// this function will free any resources it was consuming.
comment|//------------------------------------------------------------------
name|void
name|Free
parameter_list|()
function_decl|;
comment|//------------------------------------------------------------------
comment|/// Access the regular expression text.
comment|///
comment|/// Returns the text that was used to compile the current regular
comment|/// expression.
comment|///
comment|/// @return
comment|///     The NULL terminated C string that was used to compile the
comment|///     current regular expression
comment|//------------------------------------------------------------------
name|llvm
operator|::
name|StringRef
name|GetText
argument_list|()
specifier|const
expr_stmt|;
comment|//------------------------------------------------------------------
comment|/// Test if valid.
comment|///
comment|/// Test if this object contains a valid regular expression.
comment|///
comment|/// @return
comment|///     \b true if the regular expression compiled and is ready
comment|///     for execution, \b false otherwise.
comment|//------------------------------------------------------------------
name|bool
name|IsValid
argument_list|()
specifier|const
expr_stmt|;
name|void
name|Clear
parameter_list|()
block|{
name|Free
argument_list|()
expr_stmt|;
name|m_re
operator|.
name|clear
argument_list|()
expr_stmt|;
name|m_comp_err
operator|=
literal|1
expr_stmt|;
block|}
name|int
name|GetErrorCode
argument_list|()
specifier|const
block|{
return|return
name|m_comp_err
return|;
block|}
name|bool
name|operator
operator|<
operator|(
specifier|const
name|RegularExpression
operator|&
name|rhs
operator|)
specifier|const
expr_stmt|;
name|private
label|:
comment|//------------------------------------------------------------------
comment|// Member variables
comment|//------------------------------------------------------------------
name|std
operator|::
name|string
name|m_re
expr_stmt|;
comment|///< A copy of the original regular expression text
name|int
name|m_comp_err
decl_stmt|;
comment|///< Status code for the regular expression compilation
name|regex_t
name|m_preg
decl_stmt|;
comment|///< The compiled regular expression
block|}
empty_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// namespace lldb_private
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// liblldb_RegularExpression_h_
end_comment

end_unit

