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
name|LLVM_SUPPORT_MANAGED_STATIC_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_SUPPORT_MANAGED_STATIC_H
end_define

begin_include
include|#
directive|include
file|"llvm/System/Atomic.h"
end_include

begin_include
include|#
directive|include
file|"llvm/System/Threading.h"
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
name|void
operator|*
name|object_creator
argument_list|()
block|{
return|return
name|new
name|C
argument_list|()
return|;
block|}
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
argument|void * Ptr
argument_list|)
block|{
name|delete
argument_list|(
argument|T*
argument_list|)
name|Ptr
block|; }
block|}
expr_stmt|;
name|template
operator|<
name|typename
name|T
operator|,
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
argument|void * Ptr
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
expr_stmt|;
comment|/// ManagedStaticBase - Common base class for ManagedStatic instances.
name|class
name|ManagedStaticBase
block|{
name|protected
label|:
comment|// This should only be used as a static variable, which guarantees that this
comment|// will be zero initialized.
name|mutable
name|void
modifier|*
name|Ptr
decl_stmt|;
name|mutable
name|void
function_decl|(
modifier|*
name|DeleterFn
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
name|mutable
specifier|const
name|ManagedStaticBase
modifier|*
name|Next
decl_stmt|;
name|void
name|RegisterManagedStatic
argument_list|(
name|void
operator|*
call|(
modifier|*
name|creator
call|)
argument_list|()
argument_list|,
name|void
argument_list|(
operator|*
name|deleter
argument_list|)
argument_list|(
name|void
operator|*
argument_list|)
argument_list|)
decl|const
decl_stmt|;
name|public
label|:
comment|/// isConstructed - Return true if this object has not been created yet.
name|bool
name|isConstructed
argument_list|()
specifier|const
block|{
return|return
name|Ptr
operator|!=
literal|0
return|;
block|}
name|void
name|destroy
argument_list|()
specifier|const
expr_stmt|;
block|}
empty_stmt|;
comment|/// ManagedStatic - This transparently changes the behavior of global statics to
comment|/// be lazily constructed on demand (good for reducing startup times of dynamic
comment|/// libraries that link in LLVM components) and for making destruction be
comment|/// explicit through the llvm_shutdown() function call.
comment|///
name|template
operator|<
name|class
name|C
operator|>
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
name|tmp
operator|=
name|Ptr
block|;
if|if
condition|(
name|llvm_is_multithreaded
argument_list|()
condition|)
name|sys
operator|::
name|MemoryFence
argument_list|()
expr_stmt|;
if|if
condition|(
operator|!
name|tmp
condition|)
name|RegisterManagedStatic
argument_list|(
name|object_creator
operator|<
name|C
operator|>
argument_list|,
name|object_deleter
operator|<
name|C
operator|>
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
operator|)
return|;
block|}
end_decl_stmt

begin_expr_stmt
name|C
operator|*
name|operator
operator|->
expr|(
end_expr_stmt

begin_block
unit|)
block|{
name|void
modifier|*
name|tmp
init|=
name|Ptr
decl_stmt|;
if|if
condition|(
name|llvm_is_multithreaded
argument_list|()
condition|)
name|sys
operator|::
name|MemoryFence
argument_list|()
expr_stmt|;
if|if
condition|(
operator|!
name|tmp
condition|)
name|RegisterManagedStatic
argument_list|(
name|object_creator
operator|<
name|C
operator|>
argument_list|,
name|object_deleter
operator|<
name|C
operator|>
operator|::
name|call
argument_list|)
expr_stmt|;
return|return
name|static_cast
operator|<
name|C
operator|*
operator|>
operator|(
name|Ptr
operator|)
return|;
block|}
end_block

begin_expr_stmt
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
name|tmp
operator|=
name|Ptr
block|;
if|if
condition|(
name|llvm_is_multithreaded
argument_list|()
condition|)
name|sys
operator|::
name|MemoryFence
argument_list|()
expr_stmt|;
end_expr_stmt

begin_if
if|if
condition|(
operator|!
name|tmp
condition|)
name|RegisterManagedStatic
argument_list|(
name|object_creator
operator|<
name|C
operator|>
argument_list|,
name|object_deleter
operator|<
name|C
operator|>
operator|::
name|call
argument_list|)
expr_stmt|;
end_if

begin_return
return|return
operator|*
name|static_cast
operator|<
name|C
operator|*
operator|>
operator|(
name|Ptr
operator|)
return|;
end_return

begin_expr_stmt
unit|}   const
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
name|void
operator|*
name|tmp
operator|=
name|Ptr
block|;
if|if
condition|(
name|llvm_is_multithreaded
argument_list|()
condition|)
name|sys
operator|::
name|MemoryFence
argument_list|()
expr_stmt|;
end_expr_stmt

begin_if
if|if
condition|(
operator|!
name|tmp
condition|)
name|RegisterManagedStatic
argument_list|(
name|object_creator
operator|<
name|C
operator|>
argument_list|,
name|object_deleter
operator|<
name|C
operator|>
operator|::
name|call
argument_list|)
expr_stmt|;
end_if

begin_return
return|return
name|static_cast
operator|<
name|C
operator|*
operator|>
operator|(
name|Ptr
operator|)
return|;
end_return

begin_empty_stmt
unit|} }
empty_stmt|;
end_empty_stmt

begin_expr_stmt
name|template
operator|<
name|void
argument_list|(
operator|*
name|CleanupFn
argument_list|)
argument_list|(
name|void
operator|*
argument_list|)
operator|>
name|class
name|ManagedCleanup
operator|:
name|public
name|ManagedStaticBase
block|{
name|public
operator|:
name|void
name|Register
argument_list|()
block|{
name|RegisterManagedStatic
argument_list|(
literal|0
argument_list|,
name|CleanupFn
argument_list|)
block|; }
block|}
expr_stmt|;
end_expr_stmt

begin_comment
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
block|{ }
name|explicit
name|llvm_shutdown_obj
parameter_list|(
name|bool
name|multithreaded
parameter_list|)
block|{
if|if
condition|(
name|multithreaded
condition|)
name|llvm_start_multithreaded
argument_list|()
expr_stmt|;
block|}
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

begin_endif
unit|}
endif|#
directive|endif
end_endif

end_unit

