begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- llvm/Support/ManagedStatic.h - Static Global wrapper ----*- C++ -*-===//
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
comment|// This file defines the ManagedStatic class and the llvm_shutdown() function.
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
name|LLVM_SUPPORT_MANAGEDSTATIC_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_SUPPORT_MANAGEDSTATIC_H
end_define

begin_include
include|#
directive|include
file|<atomic>
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
comment|/// object_creator - Helper method for ManagedStatic.
name|template
operator|<
name|class
name|C
operator|>
expr|struct
name|object_creator
block|{
specifier|static
name|void
operator|*
name|call
argument_list|()
block|{
return|return
name|new
name|C
argument_list|()
return|;
block|}
expr|}
block|;
comment|/// object_deleter - Helper method for ManagedStatic.
comment|///
name|template
operator|<
name|typename
name|T
operator|>
expr|struct
name|object_deleter
block|{
specifier|static
name|void
name|call
argument_list|(
argument|void *Ptr
argument_list|)
block|{
name|delete
argument_list|(
argument|T *
argument_list|)
name|Ptr
block|; }
block|}
block|;
name|template
operator|<
name|typename
name|T
block|,
name|size_t
name|N
operator|>
expr|struct
name|object_deleter
operator|<
name|T
index|[
name|N
index|]
operator|>
block|{
specifier|static
name|void
name|call
argument_list|(
argument|void *Ptr
argument_list|)
block|{
name|delete
index|[]
operator|(
name|T
operator|*
operator|)
name|Ptr
block|; }
block|}
block|;
comment|/// ManagedStaticBase - Common base class for ManagedStatic instances.
name|class
name|ManagedStaticBase
block|{
name|protected
operator|:
comment|// This should only be used as a static variable, which guarantees that this
comment|// will be zero initialized.
name|mutable
name|std
operator|::
name|atomic
operator|<
name|void
operator|*
operator|>
name|Ptr
block|;
name|mutable
name|void
argument_list|(
operator|*
name|DeleterFn
argument_list|)
argument_list|(
name|void
operator|*
argument_list|)
block|;
name|mutable
specifier|const
name|ManagedStaticBase
operator|*
name|Next
block|;
name|void
name|RegisterManagedStatic
argument_list|(
argument|void *(*creator)()
argument_list|,
argument|void (*deleter)(void*)
argument_list|)
specifier|const
block|;
name|public
operator|:
comment|/// isConstructed - Return true if this object has not been created yet.
name|bool
name|isConstructed
argument_list|()
specifier|const
block|{
return|return
name|Ptr
operator|!=
name|nullptr
return|;
block|}
name|void
name|destroy
argument_list|()
specifier|const
block|; }
block|;
comment|/// ManagedStatic - This transparently changes the behavior of global statics to
comment|/// be lazily constructed on demand (good for reducing startup times of dynamic
comment|/// libraries that link in LLVM components) and for making destruction be
comment|/// explicit through the llvm_shutdown() function call.
comment|///
name|template
operator|<
name|class
name|C
block|,
name|class
name|Creator
operator|=
name|object_creator
operator|<
name|C
operator|>
block|,
name|class
name|Deleter
operator|=
name|object_deleter
operator|<
name|C
operator|>>
name|class
name|ManagedStatic
operator|:
name|public
name|ManagedStaticBase
block|{
name|public
operator|:
comment|// Accessors.
name|C
operator|&
name|operator
operator|*
operator|(
operator|)
block|{
name|void
operator|*
name|Tmp
operator|=
name|Ptr
operator|.
name|load
argument_list|(
name|std
operator|::
name|memory_order_acquire
argument_list|)
block|;
if|if
condition|(
operator|!
name|Tmp
condition|)
name|RegisterManagedStatic
argument_list|(
name|Creator
operator|::
name|call
argument_list|,
name|Deleter
operator|::
name|call
argument_list|)
expr_stmt|;
return|return
operator|*
name|static_cast
operator|<
name|C
operator|*
operator|>
operator|(
name|Ptr
operator|.
name|load
argument_list|(
name|std
operator|::
name|memory_order_relaxed
argument_list|)
operator|)
return|;
block|}
name|C
operator|*
name|operator
operator|->
expr|(
block|)
block|{
return|return
operator|&
operator|*
operator|*
name|this
return|;
block|}
specifier|const
name|C
operator|&
name|operator
operator|*
operator|(
operator|)
specifier|const
block|{
name|void
operator|*
name|Tmp
operator|=
name|Ptr
operator|.
name|load
argument_list|(
name|std
operator|::
name|memory_order_acquire
argument_list|)
block|;
if|if
condition|(
operator|!
name|Tmp
condition|)
name|RegisterManagedStatic
argument_list|(
name|Creator
operator|::
name|call
argument_list|,
name|Deleter
operator|::
name|call
argument_list|)
expr_stmt|;
return|return
operator|*
name|static_cast
operator|<
name|C
operator|*
operator|>
operator|(
name|Ptr
operator|.
name|load
argument_list|(
name|std
operator|::
name|memory_order_relaxed
argument_list|)
operator|)
return|;
block|}
end_decl_stmt

begin_expr_stmt
specifier|const
name|C
operator|*
name|operator
operator|->
expr|(
end_expr_stmt

begin_expr_stmt
unit|)
specifier|const
block|{
return|return
operator|&
operator|*
operator|*
name|this
return|;
block|}
end_expr_stmt

begin_comment
unit|};
comment|/// llvm_shutdown - Deallocate and destroy all ManagedStatic variables.
end_comment

begin_function_decl
name|void
name|llvm_shutdown
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/// llvm_shutdown_obj - This is a simple helper class that calls
end_comment

begin_comment
comment|/// llvm_shutdown() when it is destroyed.
end_comment

begin_struct
struct|struct
name|llvm_shutdown_obj
block|{
name|llvm_shutdown_obj
argument_list|()
operator|=
expr|default
expr_stmt|;
operator|~
name|llvm_shutdown_obj
argument_list|()
block|{
name|llvm_shutdown
argument_list|()
block|; }
block|}
struct|;
end_struct

begin_comment
unit|}
comment|// end namespace llvm
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// LLVM_SUPPORT_MANAGEDSTATIC_H
end_comment

end_unit

