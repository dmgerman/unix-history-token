begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- ManagerRegistry.h - Pluggable analyzer module registry --*- C++ -*-===//
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
comment|// This file defines the ManagerRegistry and Register* classes.
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
name|LLVM_CLANG_ANALYSIS_MANAGER_REGISTRY_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_ANALYSIS_MANAGER_REGISTRY_H
end_define

begin_include
include|#
directive|include
file|"clang/Analysis/PathSensitive/GRState.h"
end_include

begin_decl_stmt
name|namespace
name|clang
block|{
comment|/// ManagerRegistry - This class records manager creators registered at
comment|/// runtime. The information is communicated to AnalysisManager through static
comment|/// members. Better design is expected.
name|class
name|ManagerRegistry
block|{
name|public
label|:
specifier|static
name|StoreManagerCreator
name|StoreMgrCreator
decl_stmt|;
specifier|static
name|ConstraintManagerCreator
name|ConstraintMgrCreator
decl_stmt|;
block|}
empty_stmt|;
comment|/// RegisterConstraintManager - This class is used to setup the constraint
comment|/// manager of the static analyzer. The constructor takes a creator function
comment|/// pointer for creating the constraint manager.
comment|///
comment|/// It is used like this:
comment|///
comment|/// class MyConstraintManager {};
comment|/// ConstraintManager* CreateMyConstraintManager(GRStateManager& statemgr) {
comment|///  return new MyConstraintManager(statemgr);
comment|/// }
comment|/// RegisterConstraintManager X(CreateMyConstraintManager);
name|class
name|RegisterConstraintManager
block|{
name|public
label|:
name|RegisterConstraintManager
argument_list|(
argument|ConstraintManagerCreator CMC
argument_list|)
block|{
name|assert
argument_list|(
name|ManagerRegistry
operator|::
name|ConstraintMgrCreator
operator|==
literal|0
operator|&&
literal|"ConstraintMgrCreator already set!"
argument_list|)
expr_stmt|;
name|ManagerRegistry
operator|::
name|ConstraintMgrCreator
operator|=
name|CMC
expr_stmt|;
block|}
block|}
empty_stmt|;
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

