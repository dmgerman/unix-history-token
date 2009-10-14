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
comment|// This file implements a POSIX regular expression matcher.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

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
block|}
enum|;
comment|/// Compiles the given POSIX Extended Regular Expression \arg Regex.
comment|/// This implementation supports regexes and matching strings with embedded
comment|/// NUL characters.
name|Regex
argument_list|(
argument|const StringRef&Regex
argument_list|,
argument|unsigned Flags = NoFlags
argument_list|)
empty_stmt|;
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
decl_stmt|;
comment|/// getNumMatches - In a valid regex, return the number of parenthesized
comment|/// matches it contains.  The number filled in by match will include this
comment|/// many entries plus one for the whole regex (as element 0).
name|unsigned
name|getNumMatches
argument_list|()
specifier|const
expr_stmt|;
comment|/// matches - Match the regex against a given \arg String.
comment|///
comment|/// \param Matches - If given, on a succesful match this will be filled in
comment|/// with references to the matched group expressions (inside \arg String),
comment|/// the first group is always the entire pattern.
comment|///
comment|/// This returns true on a successful match.
name|bool
name|match
argument_list|(
specifier|const
name|StringRef
operator|&
name|String
argument_list|,
name|SmallVectorImpl
operator|<
name|StringRef
operator|>
operator|*
name|Matches
operator|=
literal|0
argument_list|)
decl_stmt|;
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

end_unit

