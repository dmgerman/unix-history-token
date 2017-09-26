begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- Option.h - Abstract Driver Options -----------------------*- C++ -*-===//
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
name|LLVM_OPTION_OPTION_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_OPTION_OPTION_H
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
file|"llvm/Option/OptTable.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/ErrorHandling.h"
end_include

begin_include
include|#
directive|include
file|<cassert>
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
name|raw_ostream
decl_stmt|;
name|namespace
name|opt
block|{
name|class
name|Arg
decl_stmt|;
name|class
name|ArgList
decl_stmt|;
comment|/// ArgStringList - Type used for constructing argv lists for subprocesses.
name|using
name|ArgStringList
init|=
name|SmallVector
operator|<
specifier|const
name|char
operator|*
decl_stmt|, 16>;
comment|/// Base flags for all options. Custom flags may be added after.
enum|enum
name|DriverFlag
block|{
name|HelpHidden
init|=
operator|(
literal|1
operator|<<
literal|0
operator|)
block|,
name|RenderAsInput
init|=
operator|(
literal|1
operator|<<
literal|1
operator|)
block|,
name|RenderJoined
init|=
operator|(
literal|1
operator|<<
literal|2
operator|)
block|,
name|RenderSeparate
init|=
operator|(
literal|1
operator|<<
literal|3
operator|)
block|}
enum|;
comment|/// Option - Abstract representation for a single form of driver
comment|/// argument.
comment|///
comment|/// An Option class represents a form of option that the driver
comment|/// takes, for example how many arguments the option has and how
comment|/// they can be provided. Individual option instances store
comment|/// additional information about what group the option is a member
comment|/// of (if any), if the option is an alias, and a number of
comment|/// flags. At runtime the driver parses the command line into
comment|/// concrete Arg instances, each of which corresponds to a
comment|/// particular Option instance.
name|class
name|Option
block|{
name|public
label|:
enum|enum
name|OptionClass
block|{
name|GroupClass
init|=
literal|0
block|,
name|InputClass
block|,
name|UnknownClass
block|,
name|FlagClass
block|,
name|JoinedClass
block|,
name|ValuesClass
block|,
name|SeparateClass
block|,
name|RemainingArgsClass
block|,
name|RemainingArgsJoinedClass
block|,
name|CommaJoinedClass
block|,
name|MultiArgClass
block|,
name|JoinedOrSeparateClass
block|,
name|JoinedAndSeparateClass
block|}
enum|;
enum|enum
name|RenderStyleKind
block|{
name|RenderCommaJoinedStyle
block|,
name|RenderJoinedStyle
block|,
name|RenderSeparateStyle
block|,
name|RenderValuesStyle
block|}
enum|;
name|protected
label|:
specifier|const
name|OptTable
operator|::
name|Info
operator|*
name|Info
expr_stmt|;
specifier|const
name|OptTable
modifier|*
name|Owner
decl_stmt|;
name|public
label|:
name|Option
argument_list|(
specifier|const
name|OptTable
operator|::
name|Info
operator|*
name|Info
argument_list|,
specifier|const
name|OptTable
operator|*
name|Owner
argument_list|)
expr_stmt|;
name|bool
name|isValid
argument_list|()
specifier|const
block|{
return|return
name|Info
operator|!=
name|nullptr
return|;
block|}
name|unsigned
name|getID
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
name|Info
operator|&&
literal|"Must have a valid info!"
argument_list|)
block|;
return|return
name|Info
operator|->
name|ID
return|;
block|}
name|OptionClass
name|getKind
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
name|Info
operator|&&
literal|"Must have a valid info!"
argument_list|)
block|;
return|return
name|OptionClass
argument_list|(
name|Info
operator|->
name|Kind
argument_list|)
return|;
block|}
comment|/// \brief Get the name of this option without any prefix.
name|StringRef
name|getName
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
name|Info
operator|&&
literal|"Must have a valid info!"
argument_list|)
block|;
return|return
name|Info
operator|->
name|Name
return|;
block|}
specifier|const
name|Option
name|getGroup
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
name|Info
operator|&&
literal|"Must have a valid info!"
argument_list|)
block|;
name|assert
argument_list|(
name|Owner
operator|&&
literal|"Must have a valid owner!"
argument_list|)
block|;
return|return
name|Owner
operator|->
name|getOption
argument_list|(
name|Info
operator|->
name|GroupID
argument_list|)
return|;
block|}
specifier|const
name|Option
name|getAlias
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
name|Info
operator|&&
literal|"Must have a valid info!"
argument_list|)
block|;
name|assert
argument_list|(
name|Owner
operator|&&
literal|"Must have a valid owner!"
argument_list|)
block|;
return|return
name|Owner
operator|->
name|getOption
argument_list|(
name|Info
operator|->
name|AliasID
argument_list|)
return|;
block|}
comment|/// \brief Get the alias arguments as a \0 separated list.
comment|/// E.g. ["foo", "bar"] would be returned as "foo\0bar\0".
specifier|const
name|char
operator|*
name|getAliasArgs
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
name|Info
operator|&&
literal|"Must have a valid info!"
argument_list|)
block|;
name|assert
argument_list|(
operator|(
operator|!
name|Info
operator|->
name|AliasArgs
operator|||
name|Info
operator|->
name|AliasArgs
index|[
literal|0
index|]
operator|!=
literal|0
operator|)
operator|&&
literal|"AliasArgs should be either 0 or non-empty."
argument_list|)
block|;
return|return
name|Info
operator|->
name|AliasArgs
return|;
block|}
comment|/// \brief Get the default prefix for this option.
name|StringRef
name|getPrefix
argument_list|()
specifier|const
block|{
specifier|const
name|char
operator|*
name|Prefix
operator|=
operator|*
name|Info
operator|->
name|Prefixes
block|;
return|return
name|Prefix
condition|?
name|Prefix
else|:
name|StringRef
argument_list|()
return|;
block|}
comment|/// \brief Get the name of this option with the default prefix.
name|std
operator|::
name|string
name|getPrefixedName
argument_list|()
specifier|const
block|{
name|std
operator|::
name|string
name|Ret
operator|=
name|getPrefix
argument_list|()
block|;
name|Ret
operator|+=
name|getName
argument_list|()
block|;
return|return
name|Ret
return|;
block|}
name|unsigned
name|getNumArgs
argument_list|()
specifier|const
block|{
return|return
name|Info
operator|->
name|Param
return|;
block|}
name|bool
name|hasNoOptAsInput
argument_list|()
specifier|const
block|{
return|return
name|Info
operator|->
name|Flags
operator|&
name|RenderAsInput
return|;
block|}
name|RenderStyleKind
name|getRenderStyle
argument_list|()
specifier|const
block|{
if|if
condition|(
name|Info
operator|->
name|Flags
operator|&
name|RenderJoined
condition|)
return|return
name|RenderJoinedStyle
return|;
if|if
condition|(
name|Info
operator|->
name|Flags
operator|&
name|RenderSeparate
condition|)
return|return
name|RenderSeparateStyle
return|;
switch|switch
condition|(
name|getKind
argument_list|()
condition|)
block|{
case|case
name|GroupClass
case|:
case|case
name|InputClass
case|:
case|case
name|UnknownClass
case|:
return|return
name|RenderValuesStyle
return|;
case|case
name|JoinedClass
case|:
case|case
name|JoinedAndSeparateClass
case|:
return|return
name|RenderJoinedStyle
return|;
case|case
name|CommaJoinedClass
case|:
return|return
name|RenderCommaJoinedStyle
return|;
case|case
name|FlagClass
case|:
case|case
name|ValuesClass
case|:
case|case
name|SeparateClass
case|:
case|case
name|MultiArgClass
case|:
case|case
name|JoinedOrSeparateClass
case|:
case|case
name|RemainingArgsClass
case|:
case|case
name|RemainingArgsJoinedClass
case|:
return|return
name|RenderSeparateStyle
return|;
block|}
name|llvm_unreachable
argument_list|(
literal|"Unexpected kind!"
argument_list|)
expr_stmt|;
block|}
comment|/// Test if this option has the flag \a Val.
name|bool
name|hasFlag
argument_list|(
name|unsigned
name|Val
argument_list|)
decl|const
block|{
return|return
name|Info
operator|->
name|Flags
operator|&
name|Val
return|;
block|}
comment|/// getUnaliasedOption - Return the final option this option
comment|/// aliases (itself, if the option has no alias).
specifier|const
name|Option
name|getUnaliasedOption
argument_list|()
specifier|const
block|{
specifier|const
name|Option
name|Alias
operator|=
name|getAlias
argument_list|()
block|;
if|if
condition|(
name|Alias
operator|.
name|isValid
argument_list|()
condition|)
return|return
name|Alias
operator|.
name|getUnaliasedOption
argument_list|()
return|;
return|return
operator|*
name|this
return|;
block|}
comment|/// getRenderName - Return the name to use when rendering this
comment|/// option.
name|StringRef
name|getRenderName
argument_list|()
specifier|const
block|{
return|return
name|getUnaliasedOption
argument_list|()
operator|.
name|getName
argument_list|()
return|;
block|}
comment|/// matches - Predicate for whether this option is part of the
comment|/// given option (which may be a group).
comment|///
comment|/// Note that matches against options which are an alias should never be
comment|/// done -- aliases do not participate in matching and so such a query will
comment|/// always be false.
name|bool
name|matches
argument_list|(
name|OptSpecifier
name|ID
argument_list|)
decl|const
decl_stmt|;
comment|/// accept - Potentially accept the current argument, returning a
comment|/// new Arg instance, or 0 if the option does not accept this
comment|/// argument (or the argument is missing values).
comment|///
comment|/// If the option accepts the current argument, accept() sets
comment|/// Index to the position where argument parsing should resume
comment|/// (even if the argument is missing values).
comment|///
comment|/// \param ArgSize The number of bytes taken up by the matched Option prefix
comment|///                and name. This is used to determine where joined values
comment|///                start.
name|Arg
modifier|*
name|accept
argument_list|(
specifier|const
name|ArgList
operator|&
name|Args
argument_list|,
name|unsigned
operator|&
name|Index
argument_list|,
name|unsigned
name|ArgSize
argument_list|)
decl|const
decl_stmt|;
name|void
name|print
argument_list|(
name|raw_ostream
operator|&
name|O
argument_list|)
decl|const
decl_stmt|;
name|void
name|dump
argument_list|()
specifier|const
expr_stmt|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
unit|}
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

begin_comment
comment|// LLVM_OPTION_OPTION_H
end_comment

end_unit

