begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- llvm/Support/PointerLikeTypeTraits.h - Pointer Traits ----*- C++ -*-===//
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
comment|// This file defines the PointerLikeTypeTraits class.  This allows data
end_comment

begin_comment
comment|// structures to reason about pointers and other things that are pointer sized.
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
name|LLVM_SUPPORT_POINTERLIKETYPETRAITS_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_SUPPORT_POINTERLIKETYPETRAITS_H
end_define

begin_include
include|#
directive|include
file|"llvm/Support/DataTypes.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
comment|/// PointerLikeTypeTraits - This is a traits object that is used to handle
comment|/// pointer types and things that are just wrappers for pointers as a uniform
comment|/// entity.
name|template
operator|<
name|typename
name|T
operator|>
name|class
name|PointerLikeTypeTraits
block|{
comment|// getAsVoidPointer
comment|// getFromVoidPointer
comment|// getNumLowBitsAvailable
block|}
expr_stmt|;
comment|// Provide PointerLikeTypeTraits for non-cvr pointers.
name|template
operator|<
name|typename
name|T
operator|>
name|class
name|PointerLikeTypeTraits
operator|<
name|T
operator|*
operator|>
block|{
name|public
operator|:
specifier|static
specifier|inline
name|void
operator|*
name|getAsVoidPointer
argument_list|(
argument|T* P
argument_list|)
block|{
return|return
name|P
return|;
block|}
specifier|static
specifier|inline
name|T
operator|*
name|getFromVoidPointer
argument_list|(
argument|void *P
argument_list|)
block|{
return|return
name|static_cast
operator|<
name|T
operator|*
operator|>
operator|(
name|P
operator|)
return|;
block|}
comment|/// Note, we assume here that malloc returns objects at least 8-byte aligned.
comment|/// However, this may be wrong, or pointers may be from something other than
comment|/// malloc.  In this case, you should specialize this template to reduce this.
comment|///
comment|/// All clients should use assertions to do a run-time check to ensure that
comment|/// this is actually true.
expr|enum
block|{
name|NumLowBitsAvailable
operator|=
literal|2
block|}
block|; }
expr_stmt|;
comment|// Provide PointerLikeTypeTraits for const pointers.
name|template
operator|<
name|typename
name|T
operator|>
name|class
name|PointerLikeTypeTraits
operator|<
specifier|const
name|T
operator|*
operator|>
block|{
typedef|typedef
name|PointerLikeTypeTraits
operator|<
name|T
operator|*
operator|>
name|NonConst
expr_stmt|;
name|public
operator|:
specifier|static
specifier|inline
specifier|const
name|void
operator|*
name|getAsVoidPointer
argument_list|(
argument|const T* P
argument_list|)
block|{
return|return
name|NonConst
operator|::
name|getAsVoidPointer
argument_list|(
name|const_cast
operator|<
name|T
operator|*
operator|>
operator|(
name|P
operator|)
argument_list|)
return|;
block|}
specifier|static
specifier|inline
specifier|const
name|T
operator|*
name|getFromVoidPointer
argument_list|(
argument|const void *P
argument_list|)
block|{
return|return
name|NonConst
operator|::
name|getFromVoidPointer
argument_list|(
name|const_cast
operator|<
name|void
operator|*
operator|>
operator|(
name|P
operator|)
argument_list|)
return|;
block|}
block|enum
block|{
name|NumLowBitsAvailable
operator|=
name|NonConst
operator|::
name|NumLowBitsAvailable
block|}
expr_stmt|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|// Provide PointerLikeTypeTraits for uintptr_t.
end_comment

begin_expr_stmt
name|template
operator|<
operator|>
name|class
name|PointerLikeTypeTraits
operator|<
name|uintptr_t
operator|>
block|{
name|public
operator|:
specifier|static
specifier|inline
name|void
operator|*
name|getAsVoidPointer
argument_list|(
argument|uintptr_t P
argument_list|)
block|{
return|return
name|reinterpret_cast
operator|<
name|void
operator|*
operator|>
operator|(
name|P
operator|)
return|;
block|}
specifier|static
specifier|inline
name|uintptr_t
name|getFromVoidPointer
argument_list|(
argument|void *P
argument_list|)
block|{
return|return
name|reinterpret_cast
operator|<
name|uintptr_t
operator|>
operator|(
name|P
operator|)
return|;
block|}
end_expr_stmt

begin_comment
comment|// No bits are available!
end_comment

begin_enum
enum|enum
block|{
name|NumLowBitsAvailable
init|=
literal|0
block|}
enum|;
end_enum

begin_comment
unit|};    }
comment|// end namespace llvm
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

