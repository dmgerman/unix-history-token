begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===--- Option.h - Abstract Driver Options ---------------------*- C++ -*-===//
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
name|CLANG_DRIVER_OPTION_H_
end_ifndef

begin_define
define|#
directive|define
name|CLANG_DRIVER_OPTION_H_
end_define

begin_include
include|#
directive|include
file|"clang/Driver/OptSpecifier.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/Casting.h"
end_include

begin_expr_stmt
name|using
name|llvm
operator|::
name|isa
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|llvm
operator|::
name|cast
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|llvm
operator|::
name|cast_or_null
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|llvm
operator|::
name|dyn_cast
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|llvm
operator|::
name|dyn_cast_or_null
expr_stmt|;
end_expr_stmt

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
name|class
name|InputArgList
decl_stmt|;
name|class
name|OptionGroup
decl_stmt|;
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
name|SeparateClass
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
name|private
label|:
name|OptionClass
name|Kind
decl_stmt|;
comment|/// The option ID.
name|OptSpecifier
name|ID
decl_stmt|;
comment|/// The option name.
specifier|const
name|char
modifier|*
name|Name
decl_stmt|;
comment|/// Group this option is a member of, if any.
specifier|const
name|OptionGroup
modifier|*
name|Group
decl_stmt|;
comment|/// Option that this is an alias for, if any.
specifier|const
name|Option
modifier|*
name|Alias
decl_stmt|;
comment|/// Unsupported options will not be rejected.
name|bool
name|Unsupported
range|:
literal|1
decl_stmt|;
comment|/// Treat this option like a linker input?
name|bool
name|LinkerInput
range|:
literal|1
decl_stmt|;
comment|/// When rendering as an input, don't render the option.
comment|// FIXME: We should ditch the render/renderAsInput distinction.
name|bool
name|NoOptAsInput
range|:
literal|1
decl_stmt|;
comment|/// Always render this option as separate form its value.
name|bool
name|ForceSeparateRender
range|:
literal|1
decl_stmt|;
comment|/// Always render this option joined with its value.
name|bool
name|ForceJoinedRender
range|:
literal|1
decl_stmt|;
comment|/// This option is only consumed by the driver.
name|bool
name|DriverOption
range|:
literal|1
decl_stmt|;
comment|/// This option should not report argument unused errors.
name|bool
name|NoArgumentUnused
range|:
literal|1
decl_stmt|;
name|protected
label|:
name|Option
argument_list|(
argument|OptionClass Kind
argument_list|,
argument|OptSpecifier ID
argument_list|,
argument|const char *Name
argument_list|,
argument|const OptionGroup *Group
argument_list|,
argument|const Option *Alias
argument_list|)
empty_stmt|;
name|public
label|:
name|virtual
operator|~
name|Option
argument_list|()
expr_stmt|;
name|unsigned
name|getID
argument_list|()
specifier|const
block|{
return|return
name|ID
operator|.
name|getID
argument_list|()
return|;
block|}
name|OptionClass
name|getKind
argument_list|()
specifier|const
block|{
return|return
name|Kind
return|;
block|}
specifier|const
name|char
operator|*
name|getName
argument_list|()
specifier|const
block|{
return|return
name|Name
return|;
block|}
specifier|const
name|OptionGroup
operator|*
name|getGroup
argument_list|()
specifier|const
block|{
return|return
name|Group
return|;
block|}
specifier|const
name|Option
operator|*
name|getAlias
argument_list|()
specifier|const
block|{
return|return
name|Alias
return|;
block|}
name|bool
name|isUnsupported
argument_list|()
specifier|const
block|{
return|return
name|Unsupported
return|;
block|}
name|void
name|setUnsupported
parameter_list|(
name|bool
name|Value
parameter_list|)
block|{
name|Unsupported
operator|=
name|Value
expr_stmt|;
block|}
name|bool
name|isLinkerInput
argument_list|()
specifier|const
block|{
return|return
name|LinkerInput
return|;
block|}
name|void
name|setLinkerInput
parameter_list|(
name|bool
name|Value
parameter_list|)
block|{
name|LinkerInput
operator|=
name|Value
expr_stmt|;
block|}
name|bool
name|hasNoOptAsInput
argument_list|()
specifier|const
block|{
return|return
name|NoOptAsInput
return|;
block|}
name|void
name|setNoOptAsInput
parameter_list|(
name|bool
name|Value
parameter_list|)
block|{
name|NoOptAsInput
operator|=
name|Value
expr_stmt|;
block|}
name|bool
name|hasForceSeparateRender
argument_list|()
specifier|const
block|{
return|return
name|ForceSeparateRender
return|;
block|}
name|void
name|setForceSeparateRender
parameter_list|(
name|bool
name|Value
parameter_list|)
block|{
name|ForceSeparateRender
operator|=
name|Value
expr_stmt|;
block|}
name|bool
name|hasForceJoinedRender
argument_list|()
specifier|const
block|{
return|return
name|ForceJoinedRender
return|;
block|}
name|void
name|setForceJoinedRender
parameter_list|(
name|bool
name|Value
parameter_list|)
block|{
name|ForceJoinedRender
operator|=
name|Value
expr_stmt|;
block|}
name|bool
name|isDriverOption
argument_list|()
specifier|const
block|{
return|return
name|DriverOption
return|;
block|}
name|void
name|setDriverOption
parameter_list|(
name|bool
name|Value
parameter_list|)
block|{
name|DriverOption
operator|=
name|Value
expr_stmt|;
block|}
name|bool
name|hasNoArgumentUnused
argument_list|()
specifier|const
block|{
return|return
name|NoArgumentUnused
return|;
block|}
name|void
name|setNoArgumentUnused
parameter_list|(
name|bool
name|Value
parameter_list|)
block|{
name|NoArgumentUnused
operator|=
name|Value
expr_stmt|;
block|}
name|bool
name|hasForwardToGCC
argument_list|()
specifier|const
block|{
return|return
operator|!
name|DriverOption
operator|&&
operator|!
name|LinkerInput
return|;
block|}
comment|/// getUnaliasedOption - Return the final option this option
comment|/// aliases (itself, if the option has no alias).
specifier|const
name|Option
operator|*
name|getUnaliasedOption
argument_list|()
specifier|const
block|{
if|if
condition|(
name|Alias
condition|)
return|return
name|Alias
operator|->
name|getUnaliasedOption
argument_list|()
return|;
return|return
name|this
return|;
block|}
comment|/// getRenderName - Return the name to use when rendering this
comment|/// option.
specifier|const
name|char
operator|*
name|getRenderName
argument_list|()
specifier|const
block|{
return|return
name|getUnaliasedOption
argument_list|()
operator|->
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
name|virtual
name|Arg
modifier|*
name|accept
argument_list|(
specifier|const
name|InputArgList
operator|&
name|Args
argument_list|,
name|unsigned
operator|&
name|Index
argument_list|)
decl|const
init|=
literal|0
decl_stmt|;
name|void
name|dump
argument_list|()
specifier|const
expr_stmt|;
specifier|static
name|bool
name|classof
parameter_list|(
specifier|const
name|Option
modifier|*
parameter_list|)
block|{
return|return
name|true
return|;
block|}
block|}
empty_stmt|;
comment|/// OptionGroup - A set of options which are can be handled uniformly
comment|/// by the driver.
name|class
name|OptionGroup
range|:
name|public
name|Option
block|{
name|public
operator|:
name|OptionGroup
argument_list|(
argument|OptSpecifier ID
argument_list|,
argument|const char *Name
argument_list|,
argument|const OptionGroup *Group
argument_list|)
block|;
name|virtual
name|Arg
operator|*
name|accept
argument_list|(
argument|const InputArgList&Args
argument_list|,
argument|unsigned&Index
argument_list|)
specifier|const
block|;
specifier|static
name|bool
name|classof
argument_list|(
argument|const Option *O
argument_list|)
block|{
return|return
name|O
operator|->
name|getKind
argument_list|()
operator|==
name|Option
operator|::
name|GroupClass
return|;
block|}
specifier|static
name|bool
name|classof
argument_list|(
argument|const OptionGroup *
argument_list|)
block|{
return|return
name|true
return|;
block|}
expr|}
block|;
comment|// Dummy option classes.
comment|/// InputOption - Dummy option class for representing driver inputs.
name|class
name|InputOption
operator|:
name|public
name|Option
block|{
name|public
operator|:
name|InputOption
argument_list|(
argument|OptSpecifier ID
argument_list|)
block|;
name|virtual
name|Arg
operator|*
name|accept
argument_list|(
argument|const InputArgList&Args
argument_list|,
argument|unsigned&Index
argument_list|)
specifier|const
block|;
specifier|static
name|bool
name|classof
argument_list|(
argument|const Option *O
argument_list|)
block|{
return|return
name|O
operator|->
name|getKind
argument_list|()
operator|==
name|Option
operator|::
name|InputClass
return|;
block|}
specifier|static
name|bool
name|classof
argument_list|(
argument|const InputOption *
argument_list|)
block|{
return|return
name|true
return|;
block|}
expr|}
block|;
comment|/// UnknownOption - Dummy option class for represent unknown arguments.
name|class
name|UnknownOption
operator|:
name|public
name|Option
block|{
name|public
operator|:
name|UnknownOption
argument_list|(
argument|OptSpecifier ID
argument_list|)
block|;
name|virtual
name|Arg
operator|*
name|accept
argument_list|(
argument|const InputArgList&Args
argument_list|,
argument|unsigned&Index
argument_list|)
specifier|const
block|;
specifier|static
name|bool
name|classof
argument_list|(
argument|const Option *O
argument_list|)
block|{
return|return
name|O
operator|->
name|getKind
argument_list|()
operator|==
name|Option
operator|::
name|UnknownClass
return|;
block|}
specifier|static
name|bool
name|classof
argument_list|(
argument|const UnknownOption *
argument_list|)
block|{
return|return
name|true
return|;
block|}
expr|}
block|;
comment|// Normal options.
name|class
name|FlagOption
operator|:
name|public
name|Option
block|{
name|public
operator|:
name|FlagOption
argument_list|(
argument|OptSpecifier ID
argument_list|,
argument|const char *Name
argument_list|,
argument|const OptionGroup *Group
argument_list|,
argument|const Option *Alias
argument_list|)
block|;
name|virtual
name|Arg
operator|*
name|accept
argument_list|(
argument|const InputArgList&Args
argument_list|,
argument|unsigned&Index
argument_list|)
specifier|const
block|;
specifier|static
name|bool
name|classof
argument_list|(
argument|const Option *O
argument_list|)
block|{
return|return
name|O
operator|->
name|getKind
argument_list|()
operator|==
name|Option
operator|::
name|FlagClass
return|;
block|}
specifier|static
name|bool
name|classof
argument_list|(
argument|const FlagOption *
argument_list|)
block|{
return|return
name|true
return|;
block|}
expr|}
block|;
name|class
name|JoinedOption
operator|:
name|public
name|Option
block|{
name|public
operator|:
name|JoinedOption
argument_list|(
argument|OptSpecifier ID
argument_list|,
argument|const char *Name
argument_list|,
argument|const OptionGroup *Group
argument_list|,
argument|const Option *Alias
argument_list|)
block|;
name|virtual
name|Arg
operator|*
name|accept
argument_list|(
argument|const InputArgList&Args
argument_list|,
argument|unsigned&Index
argument_list|)
specifier|const
block|;
specifier|static
name|bool
name|classof
argument_list|(
argument|const Option *O
argument_list|)
block|{
return|return
name|O
operator|->
name|getKind
argument_list|()
operator|==
name|Option
operator|::
name|JoinedClass
return|;
block|}
specifier|static
name|bool
name|classof
argument_list|(
argument|const JoinedOption *
argument_list|)
block|{
return|return
name|true
return|;
block|}
expr|}
block|;
name|class
name|SeparateOption
operator|:
name|public
name|Option
block|{
name|public
operator|:
name|SeparateOption
argument_list|(
argument|OptSpecifier ID
argument_list|,
argument|const char *Name
argument_list|,
argument|const OptionGroup *Group
argument_list|,
argument|const Option *Alias
argument_list|)
block|;
name|virtual
name|Arg
operator|*
name|accept
argument_list|(
argument|const InputArgList&Args
argument_list|,
argument|unsigned&Index
argument_list|)
specifier|const
block|;
specifier|static
name|bool
name|classof
argument_list|(
argument|const Option *O
argument_list|)
block|{
return|return
name|O
operator|->
name|getKind
argument_list|()
operator|==
name|Option
operator|::
name|SeparateClass
return|;
block|}
specifier|static
name|bool
name|classof
argument_list|(
argument|const SeparateOption *
argument_list|)
block|{
return|return
name|true
return|;
block|}
expr|}
block|;
name|class
name|CommaJoinedOption
operator|:
name|public
name|Option
block|{
name|public
operator|:
name|CommaJoinedOption
argument_list|(
argument|OptSpecifier ID
argument_list|,
argument|const char *Name
argument_list|,
argument|const OptionGroup *Group
argument_list|,
argument|const Option *Alias
argument_list|)
block|;
name|virtual
name|Arg
operator|*
name|accept
argument_list|(
argument|const InputArgList&Args
argument_list|,
argument|unsigned&Index
argument_list|)
specifier|const
block|;
specifier|static
name|bool
name|classof
argument_list|(
argument|const Option *O
argument_list|)
block|{
return|return
name|O
operator|->
name|getKind
argument_list|()
operator|==
name|Option
operator|::
name|CommaJoinedClass
return|;
block|}
specifier|static
name|bool
name|classof
argument_list|(
argument|const CommaJoinedOption *
argument_list|)
block|{
return|return
name|true
return|;
block|}
expr|}
block|;
comment|// FIXME: Fold MultiArgOption into SeparateOption?
comment|/// MultiArgOption - An option which takes multiple arguments (these
comment|/// are always separate arguments).
name|class
name|MultiArgOption
operator|:
name|public
name|Option
block|{
name|unsigned
name|NumArgs
block|;
name|public
operator|:
name|MultiArgOption
argument_list|(
argument|OptSpecifier ID
argument_list|,
argument|const char *Name
argument_list|,
argument|const OptionGroup *Group
argument_list|,
argument|const Option *Alias
argument_list|,
argument|unsigned NumArgs
argument_list|)
block|;
name|unsigned
name|getNumArgs
argument_list|()
specifier|const
block|{
return|return
name|NumArgs
return|;
block|}
name|virtual
name|Arg
operator|*
name|accept
argument_list|(
argument|const InputArgList&Args
argument_list|,
argument|unsigned&Index
argument_list|)
specifier|const
block|;
specifier|static
name|bool
name|classof
argument_list|(
argument|const Option *O
argument_list|)
block|{
return|return
name|O
operator|->
name|getKind
argument_list|()
operator|==
name|Option
operator|::
name|MultiArgClass
return|;
block|}
specifier|static
name|bool
name|classof
argument_list|(
argument|const MultiArgOption *
argument_list|)
block|{
return|return
name|true
return|;
block|}
expr|}
block|;
comment|/// JoinedOrSeparateOption - An option which either literally
comment|/// prefixes its (non-empty) value, or is follwed by a value.
name|class
name|JoinedOrSeparateOption
operator|:
name|public
name|Option
block|{
name|public
operator|:
name|JoinedOrSeparateOption
argument_list|(
argument|OptSpecifier ID
argument_list|,
argument|const char *Name
argument_list|,
argument|const OptionGroup *Group
argument_list|,
argument|const Option *Alias
argument_list|)
block|;
name|virtual
name|Arg
operator|*
name|accept
argument_list|(
argument|const InputArgList&Args
argument_list|,
argument|unsigned&Index
argument_list|)
specifier|const
block|;
specifier|static
name|bool
name|classof
argument_list|(
argument|const Option *O
argument_list|)
block|{
return|return
name|O
operator|->
name|getKind
argument_list|()
operator|==
name|Option
operator|::
name|JoinedOrSeparateClass
return|;
block|}
specifier|static
name|bool
name|classof
argument_list|(
argument|const JoinedOrSeparateOption *
argument_list|)
block|{
return|return
name|true
return|;
block|}
expr|}
block|;
comment|/// JoinedAndSeparateOption - An option which literally prefixes its
comment|/// value and is followed by another value.
name|class
name|JoinedAndSeparateOption
operator|:
name|public
name|Option
block|{
name|public
operator|:
name|JoinedAndSeparateOption
argument_list|(
argument|OptSpecifier ID
argument_list|,
argument|const char *Name
argument_list|,
argument|const OptionGroup *Group
argument_list|,
argument|const Option *Alias
argument_list|)
block|;
name|virtual
name|Arg
operator|*
name|accept
argument_list|(
argument|const InputArgList&Args
argument_list|,
argument|unsigned&Index
argument_list|)
specifier|const
block|;
specifier|static
name|bool
name|classof
argument_list|(
argument|const Option *O
argument_list|)
block|{
return|return
name|O
operator|->
name|getKind
argument_list|()
operator|==
name|Option
operator|::
name|JoinedAndSeparateClass
return|;
block|}
specifier|static
name|bool
name|classof
argument_list|(
argument|const JoinedAndSeparateOption *
argument_list|)
block|{
return|return
name|true
return|;
block|}
expr|}
block|;  }
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

