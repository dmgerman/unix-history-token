begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- UsuallyTinyPtrVector.h - Pointer vector class -----------*- C++ -*-===//
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
comment|//  This file defines the UsuallyTinyPtrVector class, which is a vector that
end_comment

begin_comment
comment|//  optimizes the case where there is only one element.
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
name|LLVM_CLANG_AST_USUALLY_TINY_PTR_VECTOR_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_AST_USUALLY_TINY_PTR_VECTOR_H
end_define

begin_include
include|#
directive|include
file|<vector>
end_include

begin_decl_stmt
name|namespace
name|clang
block|{
comment|/// \brief A vector class template that is optimized for storing a single
comment|/// pointer element.
name|template
operator|<
name|typename
name|T
operator|>
name|class
name|UsuallyTinyPtrVector
block|{
comment|/// \brief Storage for the vector.
comment|///
comment|/// When the low bit is zero, this is a T *. When the
comment|/// low bit is one, this is a std::vector<T *> *.
name|mutable
name|uintptr_t
name|Storage
block|;
typedef|typedef
name|std
operator|::
name|vector
operator|<
name|T
operator|*
operator|>
name|vector_type
expr_stmt|;
name|public
operator|:
name|UsuallyTinyPtrVector
argument_list|()
operator|:
name|Storage
argument_list|(
literal|0
argument_list|)
block|{ }
name|explicit
name|UsuallyTinyPtrVector
argument_list|(
name|T
operator|*
name|Element
argument_list|)
operator|:
name|Storage
argument_list|(
argument|reinterpret_cast<uintptr_t>(Element)
argument_list|)
block|{ }
name|bool
name|empty
argument_list|()
specifier|const
block|{
return|return
operator|!
name|Storage
return|;
block|}
typedef|typedef
specifier|const
name|T
modifier|*
modifier|*
name|iterator
typedef|;
name|iterator
name|begin
argument_list|()
specifier|const
expr_stmt|;
name|iterator
name|end
argument_list|()
specifier|const
expr_stmt|;
name|void
name|push_back
parameter_list|(
name|T
modifier|*
name|Method
parameter_list|)
function_decl|;
name|void
name|Destroy
parameter_list|()
function_decl|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|>
name|typename
name|UsuallyTinyPtrVector
operator|<
name|T
operator|>
operator|::
name|iterator
name|UsuallyTinyPtrVector
operator|<
name|T
operator|>
operator|::
name|begin
argument_list|()
specifier|const
block|{
if|if
condition|(
operator|(
name|Storage
operator|&
literal|0x01
operator|)
operator|==
literal|0
condition|)
return|return
name|reinterpret_cast
operator|<
name|iterator
operator|>
operator|(
operator|&
name|Storage
operator|)
return|;
name|vector_type
operator|*
name|Vec
operator|=
name|reinterpret_cast
operator|<
name|vector_type
operator|*
operator|>
operator|(
name|Storage
operator|&
operator|~
literal|0x01
operator|)
expr_stmt|;
end_expr_stmt

begin_return
return|return
operator|&
name|Vec
operator|->
name|front
argument_list|()
return|;
end_return

begin_expr_stmt
unit|}   template
operator|<
name|typename
name|T
operator|>
name|typename
name|UsuallyTinyPtrVector
operator|<
name|T
operator|>
operator|::
name|iterator
name|UsuallyTinyPtrVector
operator|<
name|T
operator|>
operator|::
name|end
argument_list|()
specifier|const
block|{
if|if
condition|(
operator|(
name|Storage
operator|&
literal|0x01
operator|)
operator|==
literal|0
condition|)
block|{
if|if
condition|(
name|Storage
operator|==
literal|0
condition|)
return|return
name|reinterpret_cast
operator|<
name|iterator
operator|>
operator|(
operator|&
name|Storage
operator|)
return|;
return|return
name|reinterpret_cast
operator|<
name|iterator
operator|>
operator|(
operator|&
name|Storage
operator|)
operator|+
literal|1
return|;
block|}
name|vector_type
operator|*
name|Vec
operator|=
name|reinterpret_cast
operator|<
name|vector_type
operator|*
operator|>
operator|(
name|Storage
operator|&
operator|~
literal|0x01
operator|)
expr_stmt|;
end_expr_stmt

begin_return
return|return
operator|&
name|Vec
operator|->
name|front
argument_list|()
operator|+
name|Vec
operator|->
name|size
argument_list|()
return|;
end_return

begin_expr_stmt
unit|}  template
operator|<
name|typename
name|T
operator|>
name|void
name|UsuallyTinyPtrVector
operator|<
name|T
operator|>
operator|::
name|push_back
argument_list|(
argument|T *Element
argument_list|)
block|{
if|if
condition|(
name|Storage
operator|==
literal|0
condition|)
block|{
comment|// 0 -> 1 element.
name|Storage
operator|=
name|reinterpret_cast
operator|<
name|uintptr_t
operator|>
operator|(
name|Element
operator|)
expr_stmt|;
return|return;
block|}
name|vector_type
operator|*
name|Vec
expr_stmt|;
end_expr_stmt

begin_if
if|if
condition|(
operator|(
name|Storage
operator|&
literal|0x01
operator|)
operator|==
literal|0
condition|)
block|{
comment|// 1 -> 2 elements. Allocate a new vector and push the element into that
comment|// vector.
name|Vec
operator|=
name|new
name|vector_type
expr_stmt|;
name|Vec
operator|->
name|push_back
argument_list|(
name|reinterpret_cast
operator|<
name|T
operator|*
operator|>
operator|(
name|Storage
operator|)
argument_list|)
expr_stmt|;
name|Storage
operator|=
name|reinterpret_cast
operator|<
name|uintptr_t
operator|>
operator|(
name|Vec
operator|)
operator||
literal|0x01
expr_stmt|;
block|}
else|else
name|Vec
operator|=
name|reinterpret_cast
operator|<
name|vector_type
operator|*
operator|>
operator|(
name|Storage
operator|&
operator|~
literal|0x01
operator|)
expr_stmt|;
end_if

begin_comment
comment|// Add the new element to the vector.
end_comment

begin_expr_stmt
name|Vec
operator|->
name|push_back
argument_list|(
name|Element
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
unit|}  template
operator|<
name|typename
name|T
operator|>
name|void
name|UsuallyTinyPtrVector
operator|<
name|T
operator|>
operator|::
name|Destroy
argument_list|()
block|{
if|if
condition|(
name|Storage
operator|&
literal|0x01
condition|)
name|delete
name|reinterpret_cast
operator|<
name|vector_type
operator|*
operator|>
operator|(
name|Storage
operator|&
operator|~
literal|0x01
operator|)
expr_stmt|;
name|Storage
operator|=
literal|0
expr_stmt|;
end_expr_stmt

begin_endif
unit|}  }
endif|#
directive|endif
end_endif

end_unit

