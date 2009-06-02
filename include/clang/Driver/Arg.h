begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===--- Arg.h - Parsed Argument Classes ------------------------*- C++ -*-===//
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
name|CLANG_DRIVER_ARG_H_
end_ifndef

begin_define
define|#
directive|define
name|CLANG_DRIVER_ARG_H_
end_define

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

begin_include
include|#
directive|include
file|"Util.h"
end_include

begin_include
include|#
directive|include
file|<vector>
end_include

begin_include
include|#
directive|include
file|<string>
end_include

begin_decl_stmt
name|namespace
name|clang
block|{
name|namespace
name|driver
block|{
name|class
name|ArgList
decl_stmt|;
name|class
name|Option
decl_stmt|;
comment|/// Arg - A concrete instance of a particular driver option.
comment|///
comment|/// The Arg class encodes just enough information to be able to
comment|/// derive the argument values efficiently. In addition, Arg
comment|/// instances have an intrusive double linked list which is used by
comment|/// ArgList to provide efficient iteration over all instances of a
comment|/// particular option.
name|class
name|Arg
block|{
name|public
label|:
enum|enum
name|ArgClass
block|{
name|FlagClass
init|=
literal|0
block|,
name|PositionalClass
block|,
name|JoinedClass
block|,
name|SeparateClass
block|,
name|CommaJoinedClass
block|,
name|JoinedAndSeparateClass
block|}
enum|;
name|private
label|:
name|ArgClass
name|Kind
decl_stmt|;
comment|/// The option this argument is an instance of.
specifier|const
name|Option
modifier|*
name|Opt
decl_stmt|;
comment|/// The argument this argument was derived from (during tool chain
comment|/// argument translation), if any.
specifier|const
name|Arg
modifier|*
name|BaseArg
decl_stmt|;
comment|/// The index at which this argument appears in the containing
comment|/// ArgList.
name|unsigned
name|Index
decl_stmt|;
comment|/// Flag indicating whether this argument was used to effect
comment|/// compilation; used for generating "argument unused"
comment|/// diagnostics.
name|mutable
name|bool
name|Claimed
decl_stmt|;
name|protected
label|:
name|Arg
argument_list|(
argument|ArgClass Kind
argument_list|,
argument|const Option *Opt
argument_list|,
argument|unsigned Index
argument_list|,
argument|const Arg *BaseArg =
literal|0
argument_list|)
empty_stmt|;
name|public
label|:
name|Arg
argument_list|(
specifier|const
name|Arg
operator|&
argument_list|)
expr_stmt|;
name|virtual
operator|~
name|Arg
argument_list|()
expr_stmt|;
name|ArgClass
name|getKind
argument_list|()
specifier|const
block|{
return|return
name|Kind
return|;
block|}
specifier|const
name|Option
operator|&
name|getOption
argument_list|()
specifier|const
block|{
return|return
operator|*
name|Opt
return|;
block|}
name|unsigned
name|getIndex
argument_list|()
specifier|const
block|{
return|return
name|Index
return|;
block|}
comment|/// getBaseArg - Return the base argument which generated this
comment|/// arg; this is either the argument itself or the argument it was
comment|/// derived from during tool chain specific argument translation.
specifier|const
name|Arg
operator|&
name|getBaseArg
argument_list|()
specifier|const
block|{
return|return
name|BaseArg
operator|?
operator|*
name|BaseArg
operator|:
operator|*
name|this
return|;
block|}
name|void
name|setBaseArg
parameter_list|(
specifier|const
name|Arg
modifier|*
name|_BaseArg
parameter_list|)
block|{
name|BaseArg
operator|=
name|_BaseArg
expr_stmt|;
block|}
name|bool
name|isClaimed
argument_list|()
specifier|const
block|{
return|return
name|getBaseArg
argument_list|()
operator|.
name|Claimed
return|;
block|}
comment|/// claim - Set the Arg claimed bit.
comment|// FIXME: We need to deal with derived arguments and set the bit
comment|// in the original argument; not the derived one.
name|void
name|claim
argument_list|()
specifier|const
block|{
name|getBaseArg
argument_list|()
operator|.
name|Claimed
operator|=
name|true
block|; }
name|virtual
name|unsigned
name|getNumValues
argument_list|()
specifier|const
operator|=
literal|0
expr_stmt|;
name|virtual
specifier|const
name|char
modifier|*
name|getValue
argument_list|(
specifier|const
name|ArgList
operator|&
name|Args
argument_list|,
name|unsigned
name|N
operator|=
literal|0
argument_list|)
decl|const
init|=
literal|0
decl_stmt|;
comment|/// render - Append the argument onto the given array as strings.
name|virtual
name|void
name|render
argument_list|(
specifier|const
name|ArgList
operator|&
name|Args
argument_list|,
name|ArgStringList
operator|&
name|Output
argument_list|)
decl|const
init|=
literal|0
decl_stmt|;
comment|/// renderAsInput - Append the argument, render as an input, onto
comment|/// the given array as strings. The distinction is that some
comment|/// options only render their values when rendered as a input
comment|/// (e.g., Xlinker).
name|void
name|renderAsInput
argument_list|(
specifier|const
name|ArgList
operator|&
name|Args
argument_list|,
name|ArgStringList
operator|&
name|Output
argument_list|)
decl|const
decl_stmt|;
specifier|static
name|bool
name|classof
parameter_list|(
specifier|const
name|Arg
modifier|*
parameter_list|)
block|{
return|return
name|true
return|;
block|}
name|void
name|dump
argument_list|()
specifier|const
expr_stmt|;
comment|/// getAsString - Return a formatted version of the argument and
comment|/// its values, for debugging and diagnostics.
name|std
operator|::
name|string
name|getAsString
argument_list|(
argument|const ArgList&Args
argument_list|)
specifier|const
expr_stmt|;
block|}
empty_stmt|;
comment|/// FlagArg - An argument with no value.
name|class
name|FlagArg
range|:
name|public
name|Arg
block|{
name|public
operator|:
name|FlagArg
argument_list|(
argument|const Option *Opt
argument_list|,
argument|unsigned Index
argument_list|,
argument|const Arg *BaseArg =
literal|0
argument_list|)
block|;
name|virtual
name|void
name|render
argument_list|(
argument|const ArgList&Args
argument_list|,
argument|ArgStringList&Output
argument_list|)
specifier|const
block|;
name|virtual
name|unsigned
name|getNumValues
argument_list|()
specifier|const
block|{
return|return
literal|0
return|;
block|}
name|virtual
specifier|const
name|char
operator|*
name|getValue
argument_list|(
argument|const ArgList&Args
argument_list|,
argument|unsigned N=
literal|0
argument_list|)
specifier|const
block|;
specifier|static
name|bool
name|classof
argument_list|(
argument|const Arg *A
argument_list|)
block|{
return|return
name|A
operator|->
name|getKind
argument_list|()
operator|==
name|Arg
operator|::
name|FlagClass
return|;
block|}
specifier|static
name|bool
name|classof
argument_list|(
argument|const FlagArg *
argument_list|)
block|{
return|return
name|true
return|;
block|}
expr|}
block|;
comment|/// PositionalArg - A simple positional argument.
name|class
name|PositionalArg
operator|:
name|public
name|Arg
block|{
name|public
operator|:
name|PositionalArg
argument_list|(
argument|const Option *Opt
argument_list|,
argument|unsigned Index
argument_list|,
argument|const Arg *BaseArg =
literal|0
argument_list|)
block|;
name|virtual
name|void
name|render
argument_list|(
argument|const ArgList&Args
argument_list|,
argument|ArgStringList&Output
argument_list|)
specifier|const
block|;
name|virtual
name|unsigned
name|getNumValues
argument_list|()
specifier|const
block|{
return|return
literal|1
return|;
block|}
name|virtual
specifier|const
name|char
operator|*
name|getValue
argument_list|(
argument|const ArgList&Args
argument_list|,
argument|unsigned N=
literal|0
argument_list|)
specifier|const
block|;
specifier|static
name|bool
name|classof
argument_list|(
argument|const Arg *A
argument_list|)
block|{
return|return
name|A
operator|->
name|getKind
argument_list|()
operator|==
name|Arg
operator|::
name|PositionalClass
return|;
block|}
specifier|static
name|bool
name|classof
argument_list|(
argument|const PositionalArg *
argument_list|)
block|{
return|return
name|true
return|;
block|}
expr|}
block|;
comment|/// JoinedArg - A single value argument where the value is joined
comment|/// (suffixed) to the option.
name|class
name|JoinedArg
operator|:
name|public
name|Arg
block|{
name|public
operator|:
name|JoinedArg
argument_list|(
argument|const Option *Opt
argument_list|,
argument|unsigned Index
argument_list|,
argument|const Arg *BaseArg =
literal|0
argument_list|)
block|;
name|virtual
name|void
name|render
argument_list|(
argument|const ArgList&Args
argument_list|,
argument|ArgStringList&Output
argument_list|)
specifier|const
block|;
name|virtual
name|unsigned
name|getNumValues
argument_list|()
specifier|const
block|{
return|return
literal|1
return|;
block|}
name|virtual
specifier|const
name|char
operator|*
name|getValue
argument_list|(
argument|const ArgList&Args
argument_list|,
argument|unsigned N=
literal|0
argument_list|)
specifier|const
block|;
specifier|static
name|bool
name|classof
argument_list|(
argument|const Arg *A
argument_list|)
block|{
return|return
name|A
operator|->
name|getKind
argument_list|()
operator|==
name|Arg
operator|::
name|JoinedClass
return|;
block|}
specifier|static
name|bool
name|classof
argument_list|(
argument|const JoinedArg *
argument_list|)
block|{
return|return
name|true
return|;
block|}
expr|}
block|;
comment|/// SeparateArg - An argument where one or more values follow the
comment|/// option specifier immediately in the argument vector.
name|class
name|SeparateArg
operator|:
name|public
name|Arg
block|{
name|unsigned
name|NumValues
block|;
name|public
operator|:
name|SeparateArg
argument_list|(
argument|const Option *Opt
argument_list|,
argument|unsigned Index
argument_list|,
argument|unsigned NumValues
argument_list|,
argument|const Arg *BaseArg =
literal|0
argument_list|)
block|;
name|virtual
name|void
name|render
argument_list|(
argument|const ArgList&Args
argument_list|,
argument|ArgStringList&Output
argument_list|)
specifier|const
block|;
name|virtual
name|unsigned
name|getNumValues
argument_list|()
specifier|const
block|{
return|return
name|NumValues
return|;
block|}
name|virtual
specifier|const
name|char
operator|*
name|getValue
argument_list|(
argument|const ArgList&Args
argument_list|,
argument|unsigned N=
literal|0
argument_list|)
specifier|const
block|;
specifier|static
name|bool
name|classof
argument_list|(
argument|const Arg *A
argument_list|)
block|{
return|return
name|A
operator|->
name|getKind
argument_list|()
operator|==
name|Arg
operator|::
name|SeparateClass
return|;
block|}
specifier|static
name|bool
name|classof
argument_list|(
argument|const SeparateArg *
argument_list|)
block|{
return|return
name|true
return|;
block|}
expr|}
block|;
comment|/// CommaJoinedArg - An argument with multiple values joined by
comment|/// commas and joined (suffixed) to the option specifier.
comment|///
comment|/// The key point of this arg is that it renders its values into
comment|/// separate arguments, which allows it to be used as a generic
comment|/// mechanism for passing arguments through to tools.
name|class
name|CommaJoinedArg
operator|:
name|public
name|Arg
block|{
name|std
operator|::
name|vector
operator|<
name|std
operator|::
name|string
operator|>
name|Values
block|;
name|public
operator|:
name|CommaJoinedArg
argument_list|(
argument|const Option *Opt
argument_list|,
argument|unsigned Index
argument_list|,
argument|const char *Str
argument_list|,
argument|const Arg *BaseArg =
literal|0
argument_list|)
block|;
name|virtual
name|void
name|render
argument_list|(
argument|const ArgList&Args
argument_list|,
argument|ArgStringList&Output
argument_list|)
specifier|const
block|;
name|virtual
name|unsigned
name|getNumValues
argument_list|()
specifier|const
block|{
return|return
name|Values
operator|.
name|size
argument_list|()
return|;
block|}
name|virtual
specifier|const
name|char
operator|*
name|getValue
argument_list|(
argument|const ArgList&Args
argument_list|,
argument|unsigned N=
literal|0
argument_list|)
specifier|const
block|;
specifier|static
name|bool
name|classof
argument_list|(
argument|const Arg *A
argument_list|)
block|{
return|return
name|A
operator|->
name|getKind
argument_list|()
operator|==
name|Arg
operator|::
name|CommaJoinedClass
return|;
block|}
specifier|static
name|bool
name|classof
argument_list|(
argument|const CommaJoinedArg *
argument_list|)
block|{
return|return
name|true
return|;
block|}
expr|}
block|;
comment|/// JoinedAndSeparateArg - An argument with both joined and separate
comment|/// values.
name|class
name|JoinedAndSeparateArg
operator|:
name|public
name|Arg
block|{
name|public
operator|:
name|JoinedAndSeparateArg
argument_list|(
argument|const Option *Opt
argument_list|,
argument|unsigned Index
argument_list|,
argument|const Arg *BaseArg =
literal|0
argument_list|)
block|;
name|virtual
name|void
name|render
argument_list|(
argument|const ArgList&Args
argument_list|,
argument|ArgStringList&Output
argument_list|)
specifier|const
block|;
name|virtual
name|unsigned
name|getNumValues
argument_list|()
specifier|const
block|{
return|return
literal|2
return|;
block|}
name|virtual
specifier|const
name|char
operator|*
name|getValue
argument_list|(
argument|const ArgList&Args
argument_list|,
argument|unsigned N=
literal|0
argument_list|)
specifier|const
block|;
specifier|static
name|bool
name|classof
argument_list|(
argument|const Arg *A
argument_list|)
block|{
return|return
name|A
operator|->
name|getKind
argument_list|()
operator|==
name|Arg
operator|::
name|JoinedAndSeparateClass
return|;
block|}
specifier|static
name|bool
name|classof
argument_list|(
argument|const JoinedAndSeparateArg *
argument_list|)
block|{
return|return
name|true
return|;
block|}
expr|}
block|; }
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

