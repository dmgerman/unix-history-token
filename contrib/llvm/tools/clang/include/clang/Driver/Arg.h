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
file|"Util.h"
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
name|Arg
argument_list|(
specifier|const
name|Arg
operator|&
argument_list|)
expr_stmt|;
comment|// DO NOT IMPLEMENT
name|void
name|operator
init|=
operator|(
specifier|const
name|Arg
operator|&
operator|)
decl_stmt|;
comment|// DO NOT IMPLEMENT
name|private
label|:
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
comment|/// Was this argument used to effect compilation; used for generating
comment|/// "argument unused" diagnostics.
name|mutable
name|unsigned
name|Claimed
range|:
literal|1
decl_stmt|;
comment|/// Does this argument own its values.
name|mutable
name|unsigned
name|OwnsValues
range|:
literal|1
decl_stmt|;
comment|/// The argument values, as C strings.
name|llvm
operator|::
name|SmallVector
operator|<
specifier|const
name|char
operator|*
operator|,
literal|2
operator|>
name|Values
expr_stmt|;
name|public
label|:
name|Arg
argument_list|(
argument|const Option *Opt
argument_list|,
argument|unsigned Index
argument_list|,
argument|const Arg *BaseArg =
literal|0
argument_list|)
empty_stmt|;
name|Arg
argument_list|(
argument|const Option *Opt
argument_list|,
argument|unsigned Index
argument_list|,
argument|const char *Value0
argument_list|,
argument|const Arg *BaseArg =
literal|0
argument_list|)
empty_stmt|;
name|Arg
argument_list|(
argument|const Option *Opt
argument_list|,
argument|unsigned Index
argument_list|,
argument|const char *Value0
argument_list|,
argument|const char *Value1
argument_list|,
argument|const Arg *BaseArg =
literal|0
argument_list|)
empty_stmt|;
operator|~
name|Arg
argument_list|()
expr_stmt|;
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
name|getOwnsValues
argument_list|()
specifier|const
block|{
return|return
name|OwnsValues
return|;
block|}
name|void
name|setOwnsValues
argument_list|(
name|bool
name|Value
argument_list|)
decl|const
block|{
name|OwnsValues
operator|=
name|Value
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
block|{
return|return
name|Values
index|[
name|N
index|]
return|;
block|}
name|llvm
operator|::
name|SmallVectorImpl
operator|<
specifier|const
name|char
operator|*
operator|>
operator|&
name|getValues
argument_list|()
block|{
return|return
name|Values
return|;
block|}
name|bool
name|containsValue
argument_list|(
name|llvm
operator|::
name|StringRef
name|Value
argument_list|)
decl|const
block|{
for|for
control|(
name|unsigned
name|i
init|=
literal|0
init|,
name|e
init|=
name|getNumValues
argument_list|()
init|;
name|i
operator|!=
name|e
condition|;
operator|++
name|i
control|)
if|if
condition|(
name|Values
index|[
name|i
index|]
operator|==
name|Value
condition|)
return|return
name|true
return|;
return|return
name|false
return|;
block|}
comment|/// render - Append the argument onto the given array as strings.
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

