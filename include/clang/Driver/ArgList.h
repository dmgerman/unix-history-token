begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===--- ArgList.h - Argument List Management ----------*- C++ -*-===//
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
name|CLANG_DRIVER_ARGLIST_H_
end_ifndef

begin_define
define|#
directive|define
name|CLANG_DRIVER_ARGLIST_H_
end_define

begin_include
include|#
directive|include
file|"clang/Driver/Options.h"
end_include

begin_include
include|#
directive|include
file|"clang/Driver/Util.h"
end_include

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
file|<list>
end_include

begin_include
include|#
directive|include
file|<string>
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|Twine
decl_stmt|;
block|}
end_decl_stmt

begin_decl_stmt
name|namespace
name|clang
block|{
name|namespace
name|driver
block|{
name|class
name|Arg
decl_stmt|;
comment|/// ArgList - Ordered collection of driver arguments.
comment|///
comment|/// The ArgList class manages a list of Arg instances as well as
comment|/// auxiliary data and convenience methods to allow Tools to quickly
comment|/// check for the presence of Arg instances for a particular Option
comment|/// and to iterate over groups of arguments.
name|class
name|ArgList
block|{
name|public
label|:
typedef|typedef
name|llvm
operator|::
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
comment|/// The full list of arguments.
name|arglist_type
modifier|&
name|Args
decl_stmt|;
name|protected
label|:
name|ArgList
argument_list|(
name|arglist_type
operator|&
name|Args
argument_list|)
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
comment|/// append - Append \arg A to the arg list.
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
comment|/// hasArg - Does the arg list contain any option matching \arg Id.
comment|///
comment|/// \arg Claim Whether the argument should be claimed, if it exists.
name|bool
name|hasArg
argument_list|(
name|options
operator|::
name|ID
name|Id
argument_list|,
name|bool
name|Claim
operator|=
name|true
argument_list|)
decl|const
block|{
return|return
name|getLastArg
argument_list|(
name|Id
argument_list|,
name|Claim
argument_list|)
operator|!=
literal|0
return|;
block|}
name|bool
name|hasArg
argument_list|(
name|options
operator|::
name|ID
name|Id0
argument_list|,
name|options
operator|::
name|ID
name|Id1
argument_list|,
name|bool
name|Claim
operator|=
name|true
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
name|Claim
argument_list|)
operator|!=
literal|0
return|;
block|}
comment|/// getLastArg - Return the last argument matching \arg Id, or null.
comment|///
comment|/// \arg Claim Whether the argument should be claimed, if it exists.
name|Arg
modifier|*
name|getLastArg
argument_list|(
name|options
operator|::
name|ID
name|Id
argument_list|,
name|bool
name|Claim
operator|=
name|true
argument_list|)
decl|const
decl_stmt|;
name|Arg
modifier|*
name|getLastArg
argument_list|(
name|options
operator|::
name|ID
name|Id0
argument_list|,
name|options
operator|::
name|ID
name|Id1
argument_list|,
name|bool
name|Claim
operator|=
name|true
argument_list|)
decl|const
decl_stmt|;
name|Arg
modifier|*
name|getLastArg
argument_list|(
name|options
operator|::
name|ID
name|Id0
argument_list|,
name|options
operator|::
name|ID
name|Id1
argument_list|,
name|options
operator|::
name|ID
name|Id2
argument_list|,
name|bool
name|Claim
operator|=
name|true
argument_list|)
decl|const
decl_stmt|;
comment|/// getArgString - Return the input argument string at \arg Index.
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
comment|/// @name Translation Utilities
comment|/// @{
comment|/// hasFlag - Given an option \arg Pos and its negative form \arg
comment|/// Neg, return true if the option is present, false if the
comment|/// negation is present, and \arg Default if neither option is
comment|/// given. If both the option and its negation are present, the
comment|/// last one wins.
name|bool
name|hasFlag
argument_list|(
name|options
operator|::
name|ID
name|Pos
argument_list|,
name|options
operator|::
name|ID
name|Neg
argument_list|,
name|bool
name|Default
operator|=
name|true
argument_list|)
decl|const
decl_stmt|;
comment|/// AddLastArg - Render only the last argument match \arg Id0, if
comment|/// present.
name|void
name|AddLastArg
argument_list|(
name|ArgStringList
operator|&
name|Output
argument_list|,
name|options
operator|::
name|ID
name|Id0
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
name|options
operator|::
name|ID
name|Id0
argument_list|)
decl|const
decl_stmt|;
name|void
name|AddAllArgs
argument_list|(
name|ArgStringList
operator|&
name|Output
argument_list|,
name|options
operator|::
name|ID
name|Id0
argument_list|,
name|options
operator|::
name|ID
name|Id1
argument_list|)
decl|const
decl_stmt|;
name|void
name|AddAllArgs
argument_list|(
name|ArgStringList
operator|&
name|Output
argument_list|,
name|options
operator|::
name|ID
name|Id0
argument_list|,
name|options
operator|::
name|ID
name|Id1
argument_list|,
name|options
operator|::
name|ID
name|Id2
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
name|options
operator|::
name|ID
name|Id0
argument_list|)
decl|const
decl_stmt|;
name|void
name|AddAllArgValues
argument_list|(
name|ArgStringList
operator|&
name|Output
argument_list|,
name|options
operator|::
name|ID
name|Id0
argument_list|,
name|options
operator|::
name|ID
name|Id1
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
name|options
operator|::
name|ID
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
name|options
operator|::
name|ID
name|Id0
argument_list|)
decl|const
decl_stmt|;
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
name|llvm
operator|::
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
name|llvm
operator|::
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
name|llvm
operator|::
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
name|llvm
operator|::
name|Twine
operator|&
name|Str
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
comment|/// The internal list of arguments.
name|arglist_type
name|ActualArgs
block|;
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
operator|*
name|ArgBegin
argument_list|,
specifier|const
name|char
operator|*
operator|*
name|ArgEnd
argument_list|)
block|;
name|InputArgList
argument_list|(
specifier|const
name|ArgList
operator|&
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
comment|/// getNumInputArgStrings - Return the number of original input
comment|/// argument strings.
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
argument|llvm::StringRef String0
argument_list|)
specifier|const
block|;
name|unsigned
name|MakeIndex
argument_list|(
argument|llvm::StringRef String0
argument_list|,
argument|llvm::StringRef String1
argument_list|)
specifier|const
block|;
name|virtual
specifier|const
name|char
operator|*
name|MakeArgString
argument_list|(
argument|llvm::StringRef Str
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
name|InputArgList
operator|&
name|BaseArgs
block|;
comment|/// The internal list of arguments.
name|arglist_type
name|ActualArgs
block|;
comment|/// The list of arguments we synthesized.
name|arglist_type
name|SynthesizedArgs
block|;
comment|/// Is this only a proxy for the base ArgList?
name|bool
name|OnlyProxy
block|;
name|public
operator|:
comment|/// Construct a new derived arg list from \arg BaseArgs.
comment|///
comment|/// \param OnlyProxy - If true, this is only a proxy for the base
comment|/// list (to adapt the type), and it's Args list is unused.
name|DerivedArgList
argument_list|(
argument|InputArgList&BaseArgs
argument_list|,
argument|bool OnlyProxy
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
comment|/// @name Arg Synthesis
comment|/// @{
name|virtual
specifier|const
name|char
operator|*
name|MakeArgString
argument_list|(
argument|llvm::StringRef Str
argument_list|)
specifier|const
block|;
comment|/// MakeFlagArg - Construct a new FlagArg for the given option
comment|/// \arg Id.
name|Arg
operator|*
name|MakeFlagArg
argument_list|(
argument|const Arg *BaseArg
argument_list|,
argument|const Option *Opt
argument_list|)
specifier|const
block|;
comment|/// MakePositionalArg - Construct a new Positional arg for the
comment|/// given option \arg Id, with the provided \arg Value.
name|Arg
operator|*
name|MakePositionalArg
argument_list|(
argument|const Arg *BaseArg
argument_list|,
argument|const Option *Opt
argument_list|,
argument|llvm::StringRef Value
argument_list|)
specifier|const
block|;
comment|/// MakeSeparateArg - Construct a new Positional arg for the
comment|/// given option \arg Id, with the provided \arg Value.
name|Arg
operator|*
name|MakeSeparateArg
argument_list|(
argument|const Arg *BaseArg
argument_list|,
argument|const Option *Opt
argument_list|,
argument|llvm::StringRef Value
argument_list|)
specifier|const
block|;
comment|/// MakeJoinedArg - Construct a new Positional arg for the
comment|/// given option \arg Id, with the provided \arg Value.
name|Arg
operator|*
name|MakeJoinedArg
argument_list|(
argument|const Arg *BaseArg
argument_list|,
argument|const Option *Opt
argument_list|,
argument|llvm::StringRef Value
argument_list|)
specifier|const
block|;
comment|/// @}
block|}
decl_stmt|;
block|}
comment|// end namespace driver
block|}
end_decl_stmt

begin_comment
comment|// end namespace clang
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

