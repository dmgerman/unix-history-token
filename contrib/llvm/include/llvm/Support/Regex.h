begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- Regex.h - Regular Expression matcher implementation -*- C++ -*-----===//
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

begin_comment
comment|//
end_comment

begin_comment
comment|// This file implements a POSIX regular expression matcher.  Both Basic and
end_comment

begin_comment
comment|// Extended POSIX regular expressions (ERE) are supported.  EREs were extended
end_comment

begin_comment
comment|// to support backreferences in matches.
end_comment

begin_comment
comment|// This implementation also supports matching strings with embedded NUL chars.
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
name|LLVM_SUPPORT_REGEX_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_SUPPORT_REGEX_H
end_define

begin_include
include|#
directive|include
file|<string>
end_include

begin_struct_decl
struct_decl|struct
name|llvm_regex
struct_decl|;
end_struct_decl

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|StringRef
decl_stmt|;
name|template
operator|<
name|typename
name|T
operator|>
name|class
name|SmallVectorImpl
expr_stmt|;
name|class
name|Regex
block|{
name|public
label|:
enum|enum
block|{
name|NoFlags
init|=
literal|0
block|,
comment|/// Compile for matching that ignores upper/lower case distinctions.
name|IgnoreCase
init|=
literal|1
block|,
comment|/// Compile for newline-sensitive matching. With this flag '[^' bracket
comment|/// expressions and '.' never match newline. A ^ anchor matches the
comment|/// null string after any newline in the string in addition to its normal
comment|/// function, and the $ anchor matches the null string before any
comment|/// newline in the string in addition to its normal function.
name|Newline
init|=
literal|2
block|,
comment|/// By default, the POSIX extended regular expression (ERE) syntax is
comment|/// assumed. Pass this flag to turn on basic regular expressions (BRE)
comment|/// instead.
name|BasicRegex
init|=
literal|4
block|}
enum|;
name|Regex
argument_list|()
expr_stmt|;
comment|/// Compiles the given regular expression \p Regex.
name|Regex
argument_list|(
argument|StringRef Regex
argument_list|,
argument|unsigned Flags = NoFlags
argument_list|)
empty_stmt|;
name|Regex
argument_list|(
specifier|const
name|Regex
operator|&
argument_list|)
operator|=
name|delete
expr_stmt|;
name|Regex
modifier|&
name|operator
init|=
operator|(
name|Regex
name|regex
operator|)
block|{
name|std
operator|::
name|swap
argument_list|(
name|preg
argument_list|,
name|regex
operator|.
name|preg
argument_list|)
block|;
name|std
operator|::
name|swap
argument_list|(
name|error
argument_list|,
name|regex
operator|.
name|error
argument_list|)
block|;
return|return
operator|*
name|this
return|;
block|}
name|Regex
argument_list|(
name|Regex
operator|&&
name|regex
argument_list|)
expr_stmt|;
operator|~
name|Regex
argument_list|()
expr_stmt|;
comment|/// isValid - returns the error encountered during regex compilation, or
comment|/// matching, if any.
name|bool
name|isValid
argument_list|(
name|std
operator|::
name|string
operator|&
name|Error
argument_list|)
decl|const
decl_stmt|;
comment|/// getNumMatches - In a valid regex, return the number of parenthesized
comment|/// matches it contains.  The number filled in by match will include this
comment|/// many entries plus one for the whole regex (as element 0).
name|unsigned
name|getNumMatches
argument_list|()
specifier|const
expr_stmt|;
comment|/// matches - Match the regex against a given \p String.
comment|///
comment|/// \param Matches - If given, on a successful match this will be filled in
comment|/// with references to the matched group expressions (inside \p String),
comment|/// the first group is always the entire pattern.
comment|///
comment|/// This returns true on a successful match.
name|bool
name|match
argument_list|(
name|StringRef
name|String
argument_list|,
name|SmallVectorImpl
operator|<
name|StringRef
operator|>
operator|*
name|Matches
operator|=
name|nullptr
argument_list|)
decl_stmt|;
comment|/// sub - Return the result of replacing the first match of the regex in
comment|/// \p String with the \p Repl string. Backreferences like "\0" in the
comment|/// replacement string are replaced with the appropriate match substring.
comment|///
comment|/// Note that the replacement string has backslash escaping performed on
comment|/// it. Invalid backreferences are ignored (replaced by empty strings).
comment|///
comment|/// \param Error If non-null, any errors in the substitution (invalid
comment|/// backreferences, trailing backslashes) will be recorded as a non-empty
comment|/// string.
name|std
operator|::
name|string
name|sub
argument_list|(
argument|StringRef Repl
argument_list|,
argument|StringRef String
argument_list|,
argument|std::string *Error = nullptr
argument_list|)
expr_stmt|;
comment|/// \brief If this function returns true, ^Str$ is an extended regular
comment|/// expression that matches Str and only Str.
specifier|static
name|bool
name|isLiteralERE
parameter_list|(
name|StringRef
name|Str
parameter_list|)
function_decl|;
comment|/// \brief Turn String into a regex by escaping its special characters.
specifier|static
name|std
operator|::
name|string
name|escape
argument_list|(
argument|StringRef String
argument_list|)
expr_stmt|;
name|private
label|:
name|struct
name|llvm_regex
modifier|*
name|preg
decl_stmt|;
name|int
name|error
decl_stmt|;
block|}
empty_stmt|;
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// LLVM_SUPPORT_REGEX_H
end_comment

end_unit

