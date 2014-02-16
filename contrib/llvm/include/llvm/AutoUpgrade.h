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
comment|//  These functions are implemented by lib/IR/AutoUpgrade.cpp.
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
name|CallInst
decl_stmt|;
name|class
name|Constant
decl_stmt|;
name|class
name|Function
decl_stmt|;
name|class
name|Instruction
decl_stmt|;
name|class
name|Module
decl_stmt|;
name|class
name|GlobalVariable
decl_stmt|;
name|class
name|Type
decl_stmt|;
name|class
name|Value
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
comment|/// This checks for global variables which should be upgraded. It returns true
comment|/// if it requires upgrading.
name|bool
name|UpgradeGlobalVariable
parameter_list|(
name|GlobalVariable
modifier|*
name|GV
parameter_list|)
function_decl|;
comment|/// If the TBAA tag for the given instruction uses the scalar TBAA format,
comment|/// we upgrade it to the struct-path aware TBAA format.
name|void
name|UpgradeInstWithTBAATag
parameter_list|(
name|Instruction
modifier|*
name|I
parameter_list|)
function_decl|;
comment|/// This is an auto-upgrade for bitcast between pointers with different
comment|/// address spaces: the instruction is replaced by a pair ptrtoint+inttoptr.
name|Instruction
modifier|*
name|UpgradeBitCastInst
parameter_list|(
name|unsigned
name|Opc
parameter_list|,
name|Value
modifier|*
name|V
parameter_list|,
name|Type
modifier|*
name|DestTy
parameter_list|,
name|Instruction
modifier|*
modifier|&
name|Temp
parameter_list|)
function_decl|;
comment|/// This is an auto-upgrade for bitcast constant expression between pointers
comment|/// with different address spaces: the instruction is replaced by a pair
comment|/// ptrtoint+inttoptr.
name|Value
modifier|*
name|UpgradeBitCastExpr
parameter_list|(
name|unsigned
name|Opc
parameter_list|,
name|Constant
modifier|*
name|C
parameter_list|,
name|Type
modifier|*
name|DestTy
parameter_list|)
function_decl|;
comment|/// Check the debug info version number, if it is out-dated, drop the debug
comment|/// info. Return true if module is modified.
name|bool
name|UpgradeDebugInfo
parameter_list|(
name|Module
modifier|&
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

