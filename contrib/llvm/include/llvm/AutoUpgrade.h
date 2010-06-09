begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- llvm/AutoUpgrade.h - AutoUpgrade Helpers ----------------*- C++ -*-===//
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
comment|//  These functions are implemented by lib/VMCore/AutoUpgrade.cpp.
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
name|LLVM_AUTOUPGRADE_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_AUTOUPGRADE_H
end_define

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|Module
decl_stmt|;
name|class
name|Function
decl_stmt|;
name|class
name|CallInst
decl_stmt|;
comment|/// This is a more granular function that simply checks an intrinsic function
comment|/// for upgrading, and returns true if it requires upgrading. It may return
comment|/// null in NewFn if the all calls to the original intrinsic function
comment|/// should be transformed to non-function-call instructions.
name|bool
name|UpgradeIntrinsicFunction
parameter_list|(
name|Function
modifier|*
name|F
parameter_list|,
name|Function
modifier|*
modifier|&
name|NewFn
parameter_list|)
function_decl|;
comment|/// This is the complement to the above, replacing a specific call to an
comment|/// intrinsic function with a call to the specified new function.
name|void
name|UpgradeIntrinsicCall
parameter_list|(
name|CallInst
modifier|*
name|CI
parameter_list|,
name|Function
modifier|*
name|NewFn
parameter_list|)
function_decl|;
comment|/// This is an auto-upgrade hook for any old intrinsic function syntaxes
comment|/// which need to have both the function updated as well as all calls updated
comment|/// to the new function. This should only be run in a post-processing fashion
comment|/// so that it can update all calls to the old function.
name|void
name|UpgradeCallsToIntrinsic
parameter_list|(
name|Function
modifier|*
name|F
parameter_list|)
function_decl|;
comment|/// This function checks debug info intrinsics. If an intrinsic is invalid
comment|/// then this function simply removes the intrinsic.
name|void
name|CheckDebugInfoIntrinsics
parameter_list|(
name|Module
modifier|*
name|M
parameter_list|)
function_decl|;
block|}
end_decl_stmt

begin_comment
comment|// End llvm namespace
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

