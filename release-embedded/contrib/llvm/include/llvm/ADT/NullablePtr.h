begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- llvm/ADT/NullablePtr.h - A pointer that allows null ------*- C++ -*-===//
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
comment|// This file defines and implements the NullablePtr class.
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
name|LLVM_ADT_NULLABLEPTR_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_ADT_NULLABLEPTR_H
end_define

begin_include
include|#
directive|include
file|<cassert>
end_include

begin_include
include|#
directive|include
file|<cstddef>
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
comment|/// NullablePtr pointer wrapper - NullablePtr is used for APIs where a
comment|/// potentially-null pointer gets passed around that must be explicitly handled
comment|/// in lots of places.  By putting a wrapper around the null pointer, it makes
comment|/// it more likely that the null pointer case will be handled correctly.
name|template
operator|<
name|class
name|T
operator|>
name|class
name|NullablePtr
block|{
name|T
operator|*
name|Ptr
block|;
name|public
operator|:
name|NullablePtr
argument_list|(
name|T
operator|*
name|P
operator|=
literal|0
argument_list|)
operator|:
name|Ptr
argument_list|(
argument|P
argument_list|)
block|{}
name|bool
name|isNull
argument_list|()
specifier|const
block|{
return|return
name|Ptr
operator|==
literal|0
return|;
block|}
name|bool
name|isNonNull
argument_list|()
specifier|const
block|{
return|return
name|Ptr
operator|!=
literal|0
return|;
block|}
comment|/// get - Return the pointer if it is non-null.
specifier|const
name|T
operator|*
name|get
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
name|Ptr
operator|&&
literal|"Pointer wasn't checked for null!"
argument_list|)
block|;
return|return
name|Ptr
return|;
block|}
comment|/// get - Return the pointer if it is non-null.
name|T
operator|*
name|get
argument_list|()
block|{
name|assert
argument_list|(
name|Ptr
operator|&&
literal|"Pointer wasn't checked for null!"
argument_list|)
block|;
return|return
name|Ptr
return|;
block|}
name|T
operator|*
name|getPtrOrNull
argument_list|()
block|{
return|return
name|Ptr
return|;
block|}
specifier|const
name|T
operator|*
name|getPtrOrNull
argument_list|()
specifier|const
block|{
return|return
name|Ptr
return|;
block|}
expr|}
block|;    }
end_decl_stmt

begin_comment
comment|// end namespace llvm
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

