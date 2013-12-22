begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- llvm/ADT/OwningPtr.h - Smart ptr that owns the pointee ---*- C++ -*-===//
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
comment|// This file defines and implements the OwningPtr class.
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
name|LLVM_ADT_OWNINGPTR_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_ADT_OWNINGPTR_H
end_define

begin_include
include|#
directive|include
file|"llvm/Support/Compiler.h"
end_include

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
comment|/// OwningPtr smart pointer - OwningPtr mimics a built-in pointer except that it
comment|/// guarantees deletion of the object pointed to, either on destruction of the
comment|/// OwningPtr or via an explicit reset().  Once created, ownership of the
comment|/// pointee object can be taken away from OwningPtr by using the take method.
name|template
operator|<
name|class
name|T
operator|>
name|class
name|OwningPtr
block|{
name|OwningPtr
argument_list|(
argument|OwningPtr const&
argument_list|)
name|LLVM_DELETED_FUNCTION
block|;
name|OwningPtr
operator|&
name|operator
operator|=
operator|(
name|OwningPtr
specifier|const
operator|&
operator|)
name|LLVM_DELETED_FUNCTION
block|;
name|T
operator|*
name|Ptr
block|;
name|public
operator|:
name|explicit
name|OwningPtr
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
if|#
directive|if
name|LLVM_HAS_RVALUE_REFERENCES
name|OwningPtr
argument_list|(
name|OwningPtr
operator|&&
name|Other
argument_list|)
operator|:
name|Ptr
argument_list|(
argument|Other.take()
argument_list|)
block|{}
name|OwningPtr
operator|&
name|operator
operator|=
operator|(
name|OwningPtr
operator|&&
name|Other
operator|)
block|{
name|reset
argument_list|(
name|Other
operator|.
name|take
argument_list|()
argument_list|)
block|;
return|return
operator|*
name|this
return|;
block|}
endif|#
directive|endif
operator|~
name|OwningPtr
argument_list|()
block|{
name|delete
name|Ptr
block|;   }
comment|/// reset - Change the current pointee to the specified pointer.  Note that
comment|/// calling this with any pointer (including a null pointer) deletes the
comment|/// current pointer.
name|void
name|reset
argument_list|(
argument|T *P =
literal|0
argument_list|)
block|{
if|if
condition|(
name|P
operator|==
name|Ptr
condition|)
return|return;
name|T
operator|*
name|Tmp
operator|=
name|Ptr
block|;
name|Ptr
operator|=
name|P
block|;
name|delete
name|Tmp
block|;   }
comment|/// take - Reset the owning pointer to null and return its pointer.  This does
comment|/// not delete the pointer before returning it.
name|T
operator|*
name|take
argument_list|()
block|{
name|T
operator|*
name|Tmp
operator|=
name|Ptr
block|;
name|Ptr
operator|=
literal|0
block|;
return|return
name|Tmp
return|;
block|}
name|T
operator|&
name|operator
operator|*
operator|(
operator|)
specifier|const
block|{
name|assert
argument_list|(
name|Ptr
operator|&&
literal|"Cannot dereference null pointer"
argument_list|)
block|;
return|return
operator|*
name|Ptr
return|;
block|}
name|T
operator|*
name|operator
operator|->
expr|(
block|)
decl|const
block|{
return|return
name|Ptr
return|;
block|}
end_decl_stmt

begin_expr_stmt
name|T
operator|*
name|get
argument_list|()
specifier|const
block|{
return|return
name|Ptr
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|LLVM_EXPLICIT
name|operator
name|bool
argument_list|()
specifier|const
block|{
return|return
name|Ptr
operator|!=
literal|0
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|bool
name|operator
operator|!
operator|(
operator|)
specifier|const
block|{
return|return
name|Ptr
operator|==
literal|0
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|bool
name|isValid
argument_list|()
specifier|const
block|{
return|return
name|Ptr
operator|!=
literal|0
return|;
block|}
end_expr_stmt

begin_function
name|void
name|swap
parameter_list|(
name|OwningPtr
modifier|&
name|RHS
parameter_list|)
block|{
name|T
modifier|*
name|Tmp
init|=
name|RHS
operator|.
name|Ptr
decl_stmt|;
name|RHS
operator|.
name|Ptr
operator|=
name|Ptr
expr_stmt|;
name|Ptr
operator|=
name|Tmp
expr_stmt|;
block|}
end_function

begin_expr_stmt
unit|};
name|template
operator|<
name|class
name|T
operator|>
specifier|inline
name|void
name|swap
argument_list|(
argument|OwningPtr<T>&a
argument_list|,
argument|OwningPtr<T>&b
argument_list|)
block|{
name|a
operator|.
name|swap
argument_list|(
name|b
argument_list|)
block|; }
comment|/// OwningArrayPtr smart pointer - OwningArrayPtr provides the same
comment|///  functionality as OwningPtr, except that it works for array types.
name|template
operator|<
name|class
name|T
operator|>
name|class
name|OwningArrayPtr
block|{
name|OwningArrayPtr
argument_list|(
argument|OwningArrayPtr const&
argument_list|)
name|LLVM_DELETED_FUNCTION
block|;
name|OwningArrayPtr
operator|&
name|operator
operator|=
operator|(
name|OwningArrayPtr
specifier|const
operator|&
operator|)
name|LLVM_DELETED_FUNCTION
block|;
name|T
operator|*
name|Ptr
block|;
name|public
operator|:
name|explicit
name|OwningArrayPtr
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
if|#
directive|if
name|LLVM_HAS_RVALUE_REFERENCES
name|OwningArrayPtr
argument_list|(
name|OwningArrayPtr
operator|&&
name|Other
argument_list|)
operator|:
name|Ptr
argument_list|(
argument|Other.take()
argument_list|)
block|{}
name|OwningArrayPtr
operator|&
name|operator
operator|=
operator|(
name|OwningArrayPtr
operator|&&
name|Other
operator|)
block|{
name|reset
argument_list|(
name|Other
operator|.
name|take
argument_list|()
argument_list|)
block|;
return|return
operator|*
name|this
return|;
block|}
endif|#
directive|endif
operator|~
name|OwningArrayPtr
argument_list|()
block|{
name|delete
index|[]
name|Ptr
block|;   }
comment|/// reset - Change the current pointee to the specified pointer.  Note that
comment|/// calling this with any pointer (including a null pointer) deletes the
comment|/// current pointer.
name|void
name|reset
argument_list|(
argument|T *P =
literal|0
argument_list|)
block|{
if|if
condition|(
name|P
operator|==
name|Ptr
condition|)
return|return;
name|T
operator|*
name|Tmp
operator|=
name|Ptr
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|Ptr
operator|=
name|P
expr_stmt|;
end_expr_stmt

begin_decl_stmt
name|delete
index|[]
name|Tmp
decl_stmt|;
end_decl_stmt

begin_comment
unit|}
comment|/// take - Reset the owning pointer to null and return its pointer.  This does
end_comment

begin_comment
comment|/// not delete the pointer before returning it.
end_comment

begin_expr_stmt
unit|T
operator|*
name|take
argument_list|()
block|{
name|T
operator|*
name|Tmp
operator|=
name|Ptr
block|;
name|Ptr
operator|=
literal|0
block|;
return|return
name|Tmp
return|;
block|}
end_expr_stmt

begin_decl_stmt
name|T
modifier|&
name|operator
index|[]
argument_list|(
name|std
operator|::
name|ptrdiff_t
name|i
argument_list|)
decl|const
block|{
name|assert
argument_list|(
name|Ptr
operator|&&
literal|"Cannot dereference null pointer"
argument_list|)
expr_stmt|;
return|return
name|Ptr
index|[
name|i
index|]
return|;
block|}
end_decl_stmt

begin_expr_stmt
name|T
operator|*
name|get
argument_list|()
specifier|const
block|{
return|return
name|Ptr
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|LLVM_EXPLICIT
name|operator
name|bool
argument_list|()
specifier|const
block|{
return|return
name|Ptr
operator|!=
literal|0
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|bool
name|operator
operator|!
operator|(
operator|)
specifier|const
block|{
return|return
name|Ptr
operator|==
literal|0
return|;
block|}
end_expr_stmt

begin_function
name|void
name|swap
parameter_list|(
name|OwningArrayPtr
modifier|&
name|RHS
parameter_list|)
block|{
name|T
modifier|*
name|Tmp
init|=
name|RHS
operator|.
name|Ptr
decl_stmt|;
name|RHS
operator|.
name|Ptr
operator|=
name|Ptr
expr_stmt|;
name|Ptr
operator|=
name|Tmp
expr_stmt|;
block|}
end_function

begin_expr_stmt
unit|};
name|template
operator|<
name|class
name|T
operator|>
specifier|inline
name|void
name|swap
argument_list|(
argument|OwningArrayPtr<T>&a
argument_list|,
argument|OwningArrayPtr<T>&b
argument_list|)
block|{
name|a
operator|.
name|swap
argument_list|(
name|b
argument_list|)
block|; }
end_expr_stmt

begin_comment
unit|}
comment|// end namespace llvm
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

