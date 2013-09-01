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
name|liblldb_DBRegex_h_
end_ifndef

begin_define
define|#
directive|define
name|liblldb_DBRegex_h_
end_define

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__cplusplus
argument_list|)
end_if

begin_include
include|#
directive|include
file|<regex.h>
end_include

begin_include
include|#
directive|include
file|<stdint.h>
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

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|StringRef
decl_stmt|;
block|}
end_decl_stmt

begin_decl_stmt
name|namespace
name|lldb_private
block|{
comment|//----------------------------------------------------------------------
comment|/// @class RegularExpression RegularExpression.h "lldb/Core/RegularExpression.h"
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
if|if
condition|(
name|m_matches
operator|.
name|empty
argument_list|()
condition|)
return|return
name|NULL
return|;
return|return
name|m_matches
operator|.
name|data
argument_list|()
return|;
block|}
name|bool
name|GetMatchAtIndex
argument_list|(
specifier|const
name|char
operator|*
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
specifier|const
name|char
operator|*
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
specifier|const
name|char
operator|*
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
comment|//------------------------------------------------------------------
comment|/// Constructor that takes a regulare expression with flags.
comment|///
comment|/// Constructor that compiles \a re using \a flags and stores the
comment|/// resulting compiled regular expression into this object.
comment|///
comment|/// @param[in] re
comment|///     A c string that represents the regular expression to
comment|///     compile.
comment|///
comment|/// @param[in] flags
comment|///     Flags that are passed the the \c regcomp() function.
comment|//------------------------------------------------------------------
name|explicit
name|RegularExpression
parameter_list|(
specifier|const
name|char
modifier|*
name|re
parameter_list|,
name|int
name|flags
parameter_list|)
function_decl|;
comment|// This one uses flags = REG_EXTENDED.
name|explicit
name|RegularExpression
parameter_list|(
specifier|const
name|char
modifier|*
name|re
parameter_list|)
function_decl|;
comment|//------------------------------------------------------------------
comment|/// Destructor.
comment|///
comment|/// Any previosuly compiled regular expression contained in this
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
comment|/// expression text and flags. The compied regular expression lives
comment|/// in this object so that it can be readily used for regular
comment|/// expression matches. Execute() can be called after the regular
comment|/// expression is compiled. Any previosuly compiled regular
comment|/// expression contained in this object will be freed.
comment|///
comment|/// @param[in] re
comment|///     A NULL terminated C string that represents the regular
comment|///     expression to compile.
comment|///
comment|/// @param[in] flags
comment|///     Flags that are passed the the \c regcomp() function.
comment|///
comment|/// @return
comment|///     \b true if the regular expression compiles successfully,
comment|///     \b false otherwise.
comment|//------------------------------------------------------------------
name|bool
name|Compile
parameter_list|(
specifier|const
name|char
modifier|*
name|re
parameter_list|)
function_decl|;
name|bool
name|Compile
parameter_list|(
specifier|const
name|char
modifier|*
name|re
parameter_list|,
name|int
name|flags
parameter_list|)
function_decl|;
comment|//------------------------------------------------------------------
comment|/// Executes a regular expression.
comment|///
comment|/// Execute a regular expression match using the compiled regular
comment|/// expression that is already in this object against the match
comment|/// string \a s. If any parens are used for regular expression
comment|/// matches \a match_count should indicate the number of regmatch_t
comment|/// values that are present in \a match_ptr. The regular expression
comment|/// will be executed using the \a execute_flags
comment|///
comment|/// @param[in] string
comment|///     The string to match against the compile regular expression.
comment|///
comment|/// @param[in] match
comment|///     A pointer to a RegularExpression::Match structure that was
comment|///     properly initialized with the desired number of maximum
comment|///     matches, or NULL if no parenthesized matching is needed.
comment|///
comment|/// @param[in] execute_flags
comment|///     Flags to pass to the \c regexec() function.
comment|///
comment|/// @return
comment|///     \b true if \a string matches the compiled regular
comment|///     expression, \b false otherwise.
comment|//------------------------------------------------------------------
name|bool
name|Execute
argument_list|(
specifier|const
name|char
operator|*
name|string
argument_list|,
name|Match
operator|*
name|match
operator|=
name|NULL
argument_list|,
name|int
name|execute_flags
operator|=
literal|0
argument_list|)
decl|const
decl_stmt|;
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
specifier|const
name|char
operator|*
name|GetText
argument_list|()
specifier|const
expr_stmt|;
name|int
name|GetCompileFlags
argument_list|()
specifier|const
block|{
return|return
name|m_compile_flags
return|;
block|}
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
name|m_compile_flags
operator|=
literal|0
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
comment|///< Error code for the regular expression compilation
name|regex_t
name|m_preg
decl_stmt|;
comment|///< The compiled regular expression
name|int
name|m_compile_flags
decl_stmt|;
comment|///< Stores the flags from the last compile.
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
comment|// #if defined(__cplusplus)
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// liblldb_DBRegex_h_
end_comment

end_unit

