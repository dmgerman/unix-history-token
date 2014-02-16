begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===--- ArgList.h - Argument List Management -------------------*- C++ -*-===//
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
name|LLVM_OPTION_ARGLIST_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_OPTION_ARGLIST_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/SmallVector.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/StringRef.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Option/OptSpecifier.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Option/Option.h"
end_include

begin_include
include|#
directive|include
file|<list>
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
name|namespace
name|opt
block|{
name|class
name|Arg
decl_stmt|;
name|class
name|ArgList
decl_stmt|;
name|class
name|Option
decl_stmt|;
comment|/// arg_iterator - Iterates through arguments stored inside an ArgList.
name|class
name|arg_iterator
block|{
comment|/// The current argument.
name|SmallVectorImpl
operator|<
name|Arg
operator|*
operator|>
operator|::
name|const_iterator
name|Current
expr_stmt|;
comment|/// The argument list we are iterating over.
specifier|const
name|ArgList
modifier|&
name|Args
decl_stmt|;
comment|/// Optional filters on the arguments which will be match. Most clients
comment|/// should never want to iterate over arguments without filters, so we won't
comment|/// bother to factor this into two separate iterator implementations.
comment|//
comment|// FIXME: Make efficient; the idea is to provide efficient iteration over
comment|// all arguments which match a particular id and then just provide an
comment|// iterator combinator which takes multiple iterators which can be
comment|// efficiently compared and returns them in order.
name|OptSpecifier
name|Id0
decl_stmt|,
name|Id1
decl_stmt|,
name|Id2
decl_stmt|;
name|void
name|SkipToNextArg
parameter_list|()
function_decl|;
name|public
label|:
typedef|typedef
name|Arg
modifier|*
specifier|const
modifier|*
name|value_type
typedef|;
typedef|typedef
name|Arg
modifier|*
specifier|const
modifier|&
name|reference
typedef|;
typedef|typedef
name|Arg
modifier|*
specifier|const
modifier|*
name|pointer
typedef|;
typedef|typedef
name|std
operator|::
name|forward_iterator_tag
name|iterator_category
expr_stmt|;
typedef|typedef
name|std
operator|::
name|ptrdiff_t
name|difference_type
expr_stmt|;
name|arg_iterator
argument_list|(
argument|SmallVectorImpl<Arg*>::const_iterator it
argument_list|,
argument|const ArgList&_Args
argument_list|,
argument|OptSpecifier _Id0 =
literal|0U
argument_list|,
argument|OptSpecifier _Id1 =
literal|0U
argument_list|,
argument|OptSpecifier _Id2 =
literal|0U
argument_list|)
block|:
name|Current
argument_list|(
name|it
argument_list|)
operator|,
name|Args
argument_list|(
name|_Args
argument_list|)
operator|,
name|Id0
argument_list|(
name|_Id0
argument_list|)
operator|,
name|Id1
argument_list|(
name|_Id1
argument_list|)
operator|,
name|Id2
argument_list|(
argument|_Id2
argument_list|)
block|{
name|SkipToNextArg
argument_list|()
block|;   }
name|operator
specifier|const
name|Arg
operator|*
operator|(
operator|)
block|{
return|return
operator|*
name|Current
return|;
block|}
name|reference
name|operator
operator|*
operator|(
operator|)
specifier|const
block|{
return|return
operator|*
name|Current
return|;
block|}
name|pointer
name|operator
operator|->
expr|(
block|)
decl|const
block|{
return|return
name|Current
return|;
block|}
name|arg_iterator
operator|&
name|operator
operator|++
operator|(
operator|)
block|{
operator|++
name|Current
block|;
name|SkipToNextArg
argument_list|()
block|;
return|return
operator|*
name|this
return|;
block|}
name|arg_iterator
name|operator
operator|++
operator|(
name|int
operator|)
block|{
name|arg_iterator
name|tmp
argument_list|(
operator|*
name|this
argument_list|)
block|;
operator|++
operator|(
operator|*
name|this
operator|)
block|;
return|return
name|tmp
return|;
block|}
name|friend
name|bool
name|operator
operator|==
operator|(
name|arg_iterator
name|LHS
operator|,
name|arg_iterator
name|RHS
operator|)
block|{
return|return
name|LHS
operator|.
name|Current
operator|==
name|RHS
operator|.
name|Current
return|;
block|}
name|friend
name|bool
name|operator
operator|!=
operator|(
name|arg_iterator
name|LHS
operator|,
name|arg_iterator
name|RHS
operator|)
block|{
return|return
operator|!
operator|(
name|LHS
operator|==
name|RHS
operator|)
return|;
block|}
block|}
empty_stmt|;
comment|/// ArgList - Ordered collection of driver arguments.
comment|///
comment|/// The ArgList class manages a list of Arg instances as well as
comment|/// auxiliary data and convenience methods to allow Tools to quickly
comment|/// check for the presence of Arg instances for a particular Option
comment|/// and to iterate over groups of arguments.
name|class
name|ArgList
block|{
name|private
label|:
name|ArgList
argument_list|(
argument|const ArgList&
argument_list|)
name|LLVM_DELETED_FUNCTION
expr_stmt|;
name|void
name|operator
init|=
operator|(
specifier|const
name|ArgList
operator|&
operator|)
name|LLVM_DELETED_FUNCTION
decl_stmt|;
name|public
label|:
typedef|typedef
name|SmallVector
operator|<
name|Arg
operator|*
operator|,
literal|16
operator|>
name|arglist_type
expr_stmt|;
typedef|typedef
name|arglist_type
operator|::
name|iterator
name|iterator
expr_stmt|;
typedef|typedef
name|arglist_type
operator|::
name|const_iterator
name|const_iterator
expr_stmt|;
typedef|typedef
name|arglist_type
operator|::
name|reverse_iterator
name|reverse_iterator
expr_stmt|;
typedef|typedef
name|arglist_type
operator|::
name|const_reverse_iterator
name|const_reverse_iterator
expr_stmt|;
name|private
label|:
comment|/// The internal list of arguments.
name|arglist_type
name|Args
decl_stmt|;
name|protected
label|:
name|ArgList
argument_list|()
expr_stmt|;
name|public
label|:
name|virtual
operator|~
name|ArgList
argument_list|()
expr_stmt|;
comment|/// @name Arg Access
comment|/// @{
comment|/// append - Append \p A to the arg list.
name|void
name|append
parameter_list|(
name|Arg
modifier|*
name|A
parameter_list|)
function_decl|;
name|arglist_type
modifier|&
name|getArgs
parameter_list|()
block|{
return|return
name|Args
return|;
block|}
specifier|const
name|arglist_type
operator|&
name|getArgs
argument_list|()
specifier|const
block|{
return|return
name|Args
return|;
block|}
name|unsigned
name|size
argument_list|()
specifier|const
block|{
return|return
name|Args
operator|.
name|size
argument_list|()
return|;
block|}
comment|/// @}
comment|/// @name Arg Iteration
comment|/// @{
name|iterator
name|begin
parameter_list|()
block|{
return|return
name|Args
operator|.
name|begin
argument_list|()
return|;
block|}
name|iterator
name|end
parameter_list|()
block|{
return|return
name|Args
operator|.
name|end
argument_list|()
return|;
block|}
name|reverse_iterator
name|rbegin
parameter_list|()
block|{
return|return
name|Args
operator|.
name|rbegin
argument_list|()
return|;
block|}
name|reverse_iterator
name|rend
parameter_list|()
block|{
return|return
name|Args
operator|.
name|rend
argument_list|()
return|;
block|}
name|const_iterator
name|begin
argument_list|()
specifier|const
block|{
return|return
name|Args
operator|.
name|begin
argument_list|()
return|;
block|}
name|const_iterator
name|end
argument_list|()
specifier|const
block|{
return|return
name|Args
operator|.
name|end
argument_list|()
return|;
block|}
name|const_reverse_iterator
name|rbegin
argument_list|()
specifier|const
block|{
return|return
name|Args
operator|.
name|rbegin
argument_list|()
return|;
block|}
name|const_reverse_iterator
name|rend
argument_list|()
specifier|const
block|{
return|return
name|Args
operator|.
name|rend
argument_list|()
return|;
block|}
name|arg_iterator
name|filtered_begin
argument_list|(
name|OptSpecifier
name|Id0
operator|=
literal|0U
argument_list|,
name|OptSpecifier
name|Id1
operator|=
literal|0U
argument_list|,
name|OptSpecifier
name|Id2
operator|=
literal|0U
argument_list|)
decl|const
block|{
return|return
name|arg_iterator
argument_list|(
name|Args
operator|.
name|begin
argument_list|()
argument_list|,
operator|*
name|this
argument_list|,
name|Id0
argument_list|,
name|Id1
argument_list|,
name|Id2
argument_list|)
return|;
block|}
name|arg_iterator
name|filtered_end
argument_list|()
specifier|const
block|{
return|return
name|arg_iterator
argument_list|(
name|Args
operator|.
name|end
argument_list|()
argument_list|,
operator|*
name|this
argument_list|)
return|;
block|}
comment|/// @}
comment|/// @name Arg Removal
comment|/// @{
comment|/// eraseArg - Remove any option matching \p Id.
name|void
name|eraseArg
parameter_list|(
name|OptSpecifier
name|Id
parameter_list|)
function_decl|;
comment|/// @}
comment|/// @name Arg Access
comment|/// @{
comment|/// hasArg - Does the arg list contain any option matching \p Id.
comment|///
comment|/// \p Claim Whether the argument should be claimed, if it exists.
name|bool
name|hasArgNoClaim
argument_list|(
name|OptSpecifier
name|Id
argument_list|)
decl|const
block|{
return|return
name|getLastArgNoClaim
argument_list|(
name|Id
argument_list|)
operator|!=
literal|0
return|;
block|}
name|bool
name|hasArg
argument_list|(
name|OptSpecifier
name|Id
argument_list|)
decl|const
block|{
return|return
name|getLastArg
argument_list|(
name|Id
argument_list|)
operator|!=
literal|0
return|;
block|}
name|bool
name|hasArg
argument_list|(
name|OptSpecifier
name|Id0
argument_list|,
name|OptSpecifier
name|Id1
argument_list|)
decl|const
block|{
return|return
name|getLastArg
argument_list|(
name|Id0
argument_list|,
name|Id1
argument_list|)
operator|!=
literal|0
return|;
block|}
name|bool
name|hasArg
argument_list|(
name|OptSpecifier
name|Id0
argument_list|,
name|OptSpecifier
name|Id1
argument_list|,
name|OptSpecifier
name|Id2
argument_list|)
decl|const
block|{
return|return
name|getLastArg
argument_list|(
name|Id0
argument_list|,
name|Id1
argument_list|,
name|Id2
argument_list|)
operator|!=
literal|0
return|;
block|}
comment|/// getLastArg - Return the last argument matching \p Id, or null.
comment|///
comment|/// \p Claim Whether the argument should be claimed, if it exists.
name|Arg
modifier|*
name|getLastArgNoClaim
argument_list|(
name|OptSpecifier
name|Id
argument_list|)
decl|const
decl_stmt|;
name|Arg
modifier|*
name|getLastArg
argument_list|(
name|OptSpecifier
name|Id
argument_list|)
decl|const
decl_stmt|;
name|Arg
modifier|*
name|getLastArg
argument_list|(
name|OptSpecifier
name|Id0
argument_list|,
name|OptSpecifier
name|Id1
argument_list|)
decl|const
decl_stmt|;
name|Arg
modifier|*
name|getLastArg
argument_list|(
name|OptSpecifier
name|Id0
argument_list|,
name|OptSpecifier
name|Id1
argument_list|,
name|OptSpecifier
name|Id2
argument_list|)
decl|const
decl_stmt|;
name|Arg
modifier|*
name|getLastArg
argument_list|(
name|OptSpecifier
name|Id0
argument_list|,
name|OptSpecifier
name|Id1
argument_list|,
name|OptSpecifier
name|Id2
argument_list|,
name|OptSpecifier
name|Id3
argument_list|)
decl|const
decl_stmt|;
name|Arg
modifier|*
name|getLastArg
argument_list|(
name|OptSpecifier
name|Id0
argument_list|,
name|OptSpecifier
name|Id1
argument_list|,
name|OptSpecifier
name|Id2
argument_list|,
name|OptSpecifier
name|Id3
argument_list|,
name|OptSpecifier
name|Id4
argument_list|)
decl|const
decl_stmt|;
name|Arg
modifier|*
name|getLastArg
argument_list|(
name|OptSpecifier
name|Id0
argument_list|,
name|OptSpecifier
name|Id1
argument_list|,
name|OptSpecifier
name|Id2
argument_list|,
name|OptSpecifier
name|Id3
argument_list|,
name|OptSpecifier
name|Id4
argument_list|,
name|OptSpecifier
name|Id5
argument_list|)
decl|const
decl_stmt|;
name|Arg
modifier|*
name|getLastArg
argument_list|(
name|OptSpecifier
name|Id0
argument_list|,
name|OptSpecifier
name|Id1
argument_list|,
name|OptSpecifier
name|Id2
argument_list|,
name|OptSpecifier
name|Id3
argument_list|,
name|OptSpecifier
name|Id4
argument_list|,
name|OptSpecifier
name|Id5
argument_list|,
name|OptSpecifier
name|Id6
argument_list|)
decl|const
decl_stmt|;
name|Arg
modifier|*
name|getLastArg
argument_list|(
name|OptSpecifier
name|Id0
argument_list|,
name|OptSpecifier
name|Id1
argument_list|,
name|OptSpecifier
name|Id2
argument_list|,
name|OptSpecifier
name|Id3
argument_list|,
name|OptSpecifier
name|Id4
argument_list|,
name|OptSpecifier
name|Id5
argument_list|,
name|OptSpecifier
name|Id6
argument_list|,
name|OptSpecifier
name|Id7
argument_list|)
decl|const
decl_stmt|;
comment|/// getArgString - Return the input argument string at \p Index.
name|virtual
specifier|const
name|char
modifier|*
name|getArgString
argument_list|(
name|unsigned
name|Index
argument_list|)
decl|const
init|=
literal|0
decl_stmt|;
comment|/// getNumInputArgStrings - Return the number of original argument strings,
comment|/// which are guaranteed to be the first strings in the argument string
comment|/// list.
name|virtual
name|unsigned
name|getNumInputArgStrings
argument_list|()
specifier|const
operator|=
literal|0
expr_stmt|;
comment|/// @}
comment|/// @name Argument Lookup Utilities
comment|/// @{
comment|/// getLastArgValue - Return the value of the last argument, or a default.
name|StringRef
name|getLastArgValue
argument_list|(
name|OptSpecifier
name|Id
argument_list|,
name|StringRef
name|Default
operator|=
literal|""
argument_list|)
decl|const
decl_stmt|;
comment|/// getAllArgValues - Get the values of all instances of the given argument
comment|/// as strings.
name|std
operator|::
name|vector
operator|<
name|std
operator|::
name|string
operator|>
name|getAllArgValues
argument_list|(
argument|OptSpecifier Id
argument_list|)
specifier|const
expr_stmt|;
comment|/// @}
comment|/// @name Translation Utilities
comment|/// @{
comment|/// hasFlag - Given an option \p Pos and its negative form \p Neg, return
comment|/// true if the option is present, false if the negation is present, and
comment|/// \p Default if neither option is given. If both the option and its
comment|/// negation are present, the last one wins.
name|bool
name|hasFlag
argument_list|(
name|OptSpecifier
name|Pos
argument_list|,
name|OptSpecifier
name|Neg
argument_list|,
name|bool
name|Default
operator|=
name|true
argument_list|)
decl|const
decl_stmt|;
comment|/// hasFlag - Given an option \p Pos, an alias \p PosAlias and its negative
comment|/// form \p Neg, return true if the option or its alias is present, false if
comment|/// the negation is present, and \p Default if none of the options are
comment|/// given. If multiple options are present, the last one wins.
name|bool
name|hasFlag
argument_list|(
name|OptSpecifier
name|Pos
argument_list|,
name|OptSpecifier
name|PosAlias
argument_list|,
name|OptSpecifier
name|Neg
argument_list|,
name|bool
name|Default
operator|=
name|true
argument_list|)
decl|const
decl_stmt|;
comment|/// AddLastArg - Render only the last argument match \p Id0, if present.
name|void
name|AddLastArg
argument_list|(
name|ArgStringList
operator|&
name|Output
argument_list|,
name|OptSpecifier
name|Id0
argument_list|)
decl|const
decl_stmt|;
name|void
name|AddLastArg
argument_list|(
name|ArgStringList
operator|&
name|Output
argument_list|,
name|OptSpecifier
name|Id0
argument_list|,
name|OptSpecifier
name|Id1
argument_list|)
decl|const
decl_stmt|;
comment|/// AddAllArgs - Render all arguments matching the given ids.
name|void
name|AddAllArgs
argument_list|(
name|ArgStringList
operator|&
name|Output
argument_list|,
name|OptSpecifier
name|Id0
argument_list|,
name|OptSpecifier
name|Id1
operator|=
literal|0U
argument_list|,
name|OptSpecifier
name|Id2
operator|=
literal|0U
argument_list|)
decl|const
decl_stmt|;
comment|/// AddAllArgValues - Render the argument values of all arguments
comment|/// matching the given ids.
name|void
name|AddAllArgValues
argument_list|(
name|ArgStringList
operator|&
name|Output
argument_list|,
name|OptSpecifier
name|Id0
argument_list|,
name|OptSpecifier
name|Id1
operator|=
literal|0U
argument_list|,
name|OptSpecifier
name|Id2
operator|=
literal|0U
argument_list|)
decl|const
decl_stmt|;
comment|/// AddAllArgsTranslated - Render all the arguments matching the
comment|/// given ids, but forced to separate args and using the provided
comment|/// name instead of the first option value.
comment|///
comment|/// \param Joined - If true, render the argument as joined with
comment|/// the option specifier.
name|void
name|AddAllArgsTranslated
argument_list|(
name|ArgStringList
operator|&
name|Output
argument_list|,
name|OptSpecifier
name|Id0
argument_list|,
specifier|const
name|char
operator|*
name|Translation
argument_list|,
name|bool
name|Joined
operator|=
name|false
argument_list|)
decl|const
decl_stmt|;
comment|/// ClaimAllArgs - Claim all arguments which match the given
comment|/// option id.
name|void
name|ClaimAllArgs
argument_list|(
name|OptSpecifier
name|Id0
argument_list|)
decl|const
decl_stmt|;
comment|/// ClaimAllArgs - Claim all arguments.
comment|///
name|void
name|ClaimAllArgs
argument_list|()
specifier|const
expr_stmt|;
comment|/// @}
comment|/// @name Arg Synthesis
comment|/// @{
comment|/// MakeArgString - Construct a constant string pointer whose
comment|/// lifetime will match that of the ArgList.
name|virtual
specifier|const
name|char
modifier|*
name|MakeArgString
argument_list|(
name|StringRef
name|Str
argument_list|)
decl|const
init|=
literal|0
decl_stmt|;
specifier|const
name|char
modifier|*
name|MakeArgString
argument_list|(
specifier|const
name|char
operator|*
name|Str
argument_list|)
decl|const
block|{
return|return
name|MakeArgString
argument_list|(
name|StringRef
argument_list|(
name|Str
argument_list|)
argument_list|)
return|;
block|}
specifier|const
name|char
modifier|*
name|MakeArgString
argument_list|(
name|std
operator|::
name|string
name|Str
argument_list|)
decl|const
block|{
return|return
name|MakeArgString
argument_list|(
name|StringRef
argument_list|(
name|Str
argument_list|)
argument_list|)
return|;
block|}
specifier|const
name|char
modifier|*
name|MakeArgString
argument_list|(
specifier|const
name|Twine
operator|&
name|Str
argument_list|)
decl|const
decl_stmt|;
comment|/// \brief Create an arg string for (\p LHS + \p RHS), reusing the
comment|/// string at \p Index if possible.
specifier|const
name|char
modifier|*
name|GetOrMakeJoinedArgString
argument_list|(
name|unsigned
name|Index
argument_list|,
name|StringRef
name|LHS
argument_list|,
name|StringRef
name|RHS
argument_list|)
decl|const
decl_stmt|;
comment|/// @}
block|}
empty_stmt|;
name|class
name|InputArgList
range|:
name|public
name|ArgList
block|{
name|private
operator|:
comment|/// List of argument strings used by the contained Args.
comment|///
comment|/// This is mutable since we treat the ArgList as being the list
comment|/// of Args, and allow routines to add new strings (to have a
comment|/// convenient place to store the memory) via MakeIndex.
name|mutable
name|ArgStringList
name|ArgStrings
block|;
comment|/// Strings for synthesized arguments.
comment|///
comment|/// This is mutable since we treat the ArgList as being the list
comment|/// of Args, and allow routines to add new strings (to have a
comment|/// convenient place to store the memory) via MakeIndex.
name|mutable
name|std
operator|::
name|list
operator|<
name|std
operator|::
name|string
operator|>
name|SynthesizedStrings
block|;
comment|/// The number of original input argument strings.
name|unsigned
name|NumInputArgStrings
block|;
name|public
operator|:
name|InputArgList
argument_list|(
specifier|const
name|char
operator|*
specifier|const
operator|*
name|ArgBegin
argument_list|,
specifier|const
name|char
operator|*
specifier|const
operator|*
name|ArgEnd
argument_list|)
block|;
operator|~
name|InputArgList
argument_list|()
block|;
name|virtual
specifier|const
name|char
operator|*
name|getArgString
argument_list|(
argument|unsigned Index
argument_list|)
specifier|const
block|{
return|return
name|ArgStrings
index|[
name|Index
index|]
return|;
block|}
name|virtual
name|unsigned
name|getNumInputArgStrings
argument_list|()
specifier|const
block|{
return|return
name|NumInputArgStrings
return|;
block|}
comment|/// @name Arg Synthesis
comment|/// @{
name|public
operator|:
comment|/// MakeIndex - Get an index for the given string(s).
name|unsigned
name|MakeIndex
argument_list|(
argument|StringRef String0
argument_list|)
specifier|const
block|;
name|unsigned
name|MakeIndex
argument_list|(
argument|StringRef String0
argument_list|,
argument|StringRef String1
argument_list|)
specifier|const
block|;
name|virtual
specifier|const
name|char
operator|*
name|MakeArgString
argument_list|(
argument|StringRef Str
argument_list|)
specifier|const
block|;
comment|/// @}
block|}
decl_stmt|;
comment|/// DerivedArgList - An ordered collection of driver arguments,
comment|/// whose storage may be in another argument list.
name|class
name|DerivedArgList
range|:
name|public
name|ArgList
block|{
specifier|const
name|InputArgList
operator|&
name|BaseArgs
block|;
comment|/// The list of arguments we synthesized.
name|mutable
name|arglist_type
name|SynthesizedArgs
block|;
name|public
operator|:
comment|/// Construct a new derived arg list from \p BaseArgs.
name|DerivedArgList
argument_list|(
specifier|const
name|InputArgList
operator|&
name|BaseArgs
argument_list|)
block|;
operator|~
name|DerivedArgList
argument_list|()
block|;
name|virtual
specifier|const
name|char
operator|*
name|getArgString
argument_list|(
argument|unsigned Index
argument_list|)
specifier|const
block|{
return|return
name|BaseArgs
operator|.
name|getArgString
argument_list|(
name|Index
argument_list|)
return|;
block|}
name|virtual
name|unsigned
name|getNumInputArgStrings
argument_list|()
specifier|const
block|{
return|return
name|BaseArgs
operator|.
name|getNumInputArgStrings
argument_list|()
return|;
block|}
specifier|const
name|InputArgList
operator|&
name|getBaseArgs
argument_list|()
specifier|const
block|{
return|return
name|BaseArgs
return|;
block|}
comment|/// @name Arg Synthesis
comment|/// @{
comment|/// AddSynthesizedArg - Add a argument to the list of synthesized arguments
comment|/// (to be freed).
name|void
name|AddSynthesizedArg
argument_list|(
argument|Arg *A
argument_list|)
block|{
name|SynthesizedArgs
operator|.
name|push_back
argument_list|(
name|A
argument_list|)
block|;   }
name|virtual
specifier|const
name|char
operator|*
name|MakeArgString
argument_list|(
argument|StringRef Str
argument_list|)
specifier|const
block|;
comment|/// AddFlagArg - Construct a new FlagArg for the given option \p Id and
comment|/// append it to the argument list.
name|void
name|AddFlagArg
argument_list|(
argument|const Arg *BaseArg
argument_list|,
argument|const Option Opt
argument_list|)
block|{
name|append
argument_list|(
name|MakeFlagArg
argument_list|(
name|BaseArg
argument_list|,
name|Opt
argument_list|)
argument_list|)
block|;   }
comment|/// AddPositionalArg - Construct a new Positional arg for the given option
comment|/// \p Id, with the provided \p Value and append it to the argument
comment|/// list.
name|void
name|AddPositionalArg
argument_list|(
argument|const Arg *BaseArg
argument_list|,
argument|const Option Opt
argument_list|,
argument|StringRef Value
argument_list|)
block|{
name|append
argument_list|(
name|MakePositionalArg
argument_list|(
name|BaseArg
argument_list|,
name|Opt
argument_list|,
name|Value
argument_list|)
argument_list|)
block|;   }
comment|/// AddSeparateArg - Construct a new Positional arg for the given option
comment|/// \p Id, with the provided \p Value and append it to the argument
comment|/// list.
name|void
name|AddSeparateArg
argument_list|(
argument|const Arg *BaseArg
argument_list|,
argument|const Option Opt
argument_list|,
argument|StringRef Value
argument_list|)
block|{
name|append
argument_list|(
name|MakeSeparateArg
argument_list|(
name|BaseArg
argument_list|,
name|Opt
argument_list|,
name|Value
argument_list|)
argument_list|)
block|;   }
comment|/// AddJoinedArg - Construct a new Positional arg for the given option
comment|/// \p Id, with the provided \p Value and append it to the argument list.
name|void
name|AddJoinedArg
argument_list|(
argument|const Arg *BaseArg
argument_list|,
argument|const Option Opt
argument_list|,
argument|StringRef Value
argument_list|)
block|{
name|append
argument_list|(
name|MakeJoinedArg
argument_list|(
name|BaseArg
argument_list|,
name|Opt
argument_list|,
name|Value
argument_list|)
argument_list|)
block|;   }
comment|/// MakeFlagArg - Construct a new FlagArg for the given option \p Id.
name|Arg
operator|*
name|MakeFlagArg
argument_list|(
argument|const Arg *BaseArg
argument_list|,
argument|const Option Opt
argument_list|)
specifier|const
block|;
comment|/// MakePositionalArg - Construct a new Positional arg for the
comment|/// given option \p Id, with the provided \p Value.
name|Arg
operator|*
name|MakePositionalArg
argument_list|(
argument|const Arg *BaseArg
argument_list|,
argument|const Option Opt
argument_list|,
argument|StringRef Value
argument_list|)
specifier|const
block|;
comment|/// MakeSeparateArg - Construct a new Positional arg for the
comment|/// given option \p Id, with the provided \p Value.
name|Arg
operator|*
name|MakeSeparateArg
argument_list|(
argument|const Arg *BaseArg
argument_list|,
argument|const Option Opt
argument_list|,
argument|StringRef Value
argument_list|)
specifier|const
block|;
comment|/// MakeJoinedArg - Construct a new Positional arg for the
comment|/// given option \p Id, with the provided \p Value.
name|Arg
operator|*
name|MakeJoinedArg
argument_list|(
argument|const Arg *BaseArg
argument_list|,
argument|const Option Opt
argument_list|,
argument|StringRef Value
argument_list|)
specifier|const
block|;
comment|/// @}
block|}
decl_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// end namespace opt
end_comment

begin_comment
unit|}
comment|// end namespace llvm
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

