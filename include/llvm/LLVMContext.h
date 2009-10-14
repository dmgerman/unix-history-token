begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- llvm/LLVMContext.h - Class for managing "global" state --*- C++ -*-===//
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
comment|// This file declares LLVMContext, a container of "global" state in LLVM, such
end_comment

begin_comment
comment|// as the global type and constant uniquing tables.
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
name|LLVM_LLVMCONTEXT_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_LLVMCONTEXT_H
end_define

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|LLVMContextImpl
decl_stmt|;
name|class
name|MetadataContext
decl_stmt|;
comment|/// This is an important class for using LLVM in a threaded context.  It
comment|/// (opaquely) owns and manages the core "global" data of LLVM's core
comment|/// infrastructure, including the type and constant uniquing tables.
comment|/// LLVMContext itself provides no locking guarantees, so you should be careful
comment|/// to have one context per thread.
name|class
name|LLVMContext
block|{
comment|// DO NOT IMPLEMENT
name|LLVMContext
argument_list|(
name|LLVMContext
operator|&
argument_list|)
expr_stmt|;
name|void
name|operator
init|=
operator|(
name|LLVMContext
operator|&
operator|)
decl_stmt|;
name|public
label|:
name|LLVMContextImpl
modifier|*
specifier|const
name|pImpl
decl_stmt|;
name|MetadataContext
modifier|&
name|getMetadata
parameter_list|()
function_decl|;
name|bool
name|RemoveDeadMetadata
parameter_list|()
function_decl|;
name|LLVMContext
argument_list|()
expr_stmt|;
operator|~
name|LLVMContext
argument_list|()
expr_stmt|;
block|}
empty_stmt|;
comment|/// FOR BACKWARDS COMPATIBILITY - Returns a global context.
specifier|extern
name|LLVMContext
modifier|&
name|getGlobalContext
parameter_list|()
function_decl|;
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

