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
name|StringRef
decl_stmt|;
name|template
operator|<
name|typename
name|T
operator|>
name|class
name|SmallVectorImpl
expr_stmt|;
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
name|LLVMContext
argument_list|()
expr_stmt|;
operator|~
name|LLVMContext
argument_list|()
expr_stmt|;
comment|/// getMDKindID - Return a unique non-zero ID for the specified metadata kind.
comment|/// This ID is uniqued across modules in the current LLVMContext.
name|unsigned
name|getMDKindID
argument_list|(
name|StringRef
name|Name
argument_list|)
decl|const
decl_stmt|;
comment|/// getMDKindNames - Populate client supplied SmallVector with the name for
comment|/// custom metadata IDs registered in this LLVMContext.   ID #0 is not used,
comment|/// so it is filled in as an empty string.
name|void
name|getMDKindNames
argument_list|(
name|SmallVectorImpl
operator|<
name|StringRef
operator|>
operator|&
name|Result
argument_list|)
decl|const
decl_stmt|;
block|}
empty_stmt|;
comment|/// getGlobalContext - Returns a global context.  This is for LLVM clients that
comment|/// only care about operating on a single thread.
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

