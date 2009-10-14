begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- llvm/ADT/SmallString.h - 'Normally small' strings --------*- C++ -*-===//
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
comment|// This file defines the SmallString class.
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
name|LLVM_ADT_SMALLSTRING_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_ADT_SMALLSTRING_H
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

begin_decl_stmt
name|namespace
name|llvm
block|{
comment|/// SmallString - A SmallString is just a SmallVector with methods and accessors
comment|/// that make it work better as a string (e.g. operator+ etc).
name|template
operator|<
name|unsigned
name|InternalLen
operator|>
name|class
name|SmallString
operator|:
name|public
name|SmallVector
operator|<
name|char
operator|,
name|InternalLen
operator|>
block|{
name|public
operator|:
comment|// Default ctor - Initialize to empty.
name|SmallString
argument_list|()
block|{}
comment|// Initialize with a range.
name|template
operator|<
name|typename
name|ItTy
operator|>
name|SmallString
argument_list|(
argument|ItTy S
argument_list|,
argument|ItTy E
argument_list|)
operator|:
name|SmallVector
operator|<
name|char
block|,
name|InternalLen
operator|>
operator|(
name|S
operator|,
name|E
operator|)
block|{}
comment|// Copy ctor.
name|SmallString
argument_list|(
specifier|const
name|SmallString
operator|&
name|RHS
argument_list|)
operator|:
name|SmallVector
operator|<
name|char
block|,
name|InternalLen
operator|>
operator|(
name|RHS
operator|)
block|{}
comment|// Extra methods.
name|StringRef
name|str
argument_list|()
specifier|const
block|{
return|return
name|StringRef
argument_list|(
name|this
operator|->
name|begin
argument_list|()
argument_list|,
name|this
operator|->
name|size
argument_list|()
argument_list|)
return|;
block|}
specifier|const
name|char
operator|*
name|c_str
argument_list|()
block|{
name|this
operator|->
name|push_back
argument_list|(
literal|0
argument_list|)
block|;
name|this
operator|->
name|pop_back
argument_list|()
block|;
return|return
name|this
operator|->
name|data
argument_list|()
return|;
block|}
comment|// Extra operators.
specifier|const
name|SmallString
operator|&
name|operator
operator|=
operator|(
name|StringRef
name|RHS
operator|)
block|{
name|this
operator|->
name|clear
argument_list|()
block|;
return|return
operator|*
name|this
operator|+=
name|RHS
return|;
block|}
name|SmallString
operator|&
name|operator
operator|+=
operator|(
name|StringRef
name|RHS
operator|)
block|{
name|this
operator|->
name|append
argument_list|(
name|RHS
operator|.
name|begin
argument_list|()
argument_list|,
name|RHS
operator|.
name|end
argument_list|()
argument_list|)
block|;
return|return
operator|*
name|this
return|;
block|}
name|SmallString
operator|&
name|operator
operator|+=
operator|(
name|char
name|C
operator|)
block|{
name|this
operator|->
name|push_back
argument_list|(
name|C
argument_list|)
block|;
return|return
operator|*
name|this
return|;
block|}
expr|}
block|;  }
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

