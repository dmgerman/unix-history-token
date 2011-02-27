begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//=-- InternalChecks.h- Builtin ExprEngine Checks -------------------*- C++ -*-=
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
comment|//  This file defines functions to instantiate and register the "built-in"
end_comment

begin_comment
comment|//  checks in ExprEngine.
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
name|LLVM_CLANG_GR_ExprEngine_INTERNAL_CHECKS
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_GR_ExprEngine_INTERNAL_CHECKS
end_define

begin_decl_stmt
name|namespace
name|clang
block|{
name|namespace
name|ento
block|{
name|class
name|ExprEngine
decl_stmt|;
comment|// Foundational checks that handle basic semantics.
name|void
name|RegisterAdjustedReturnValueChecker
parameter_list|(
name|ExprEngine
modifier|&
name|Eng
parameter_list|)
function_decl|;
name|void
name|RegisterArrayBoundCheckerV2
parameter_list|(
name|ExprEngine
modifier|&
name|Eng
parameter_list|)
function_decl|;
name|void
name|RegisterAttrNonNullChecker
parameter_list|(
name|ExprEngine
modifier|&
name|Eng
parameter_list|)
function_decl|;
name|void
name|RegisterBuiltinFunctionChecker
parameter_list|(
name|ExprEngine
modifier|&
name|Eng
parameter_list|)
function_decl|;
name|void
name|RegisterCallAndMessageChecker
parameter_list|(
name|ExprEngine
modifier|&
name|Eng
parameter_list|)
function_decl|;
name|void
name|RegisterDereferenceChecker
parameter_list|(
name|ExprEngine
modifier|&
name|Eng
parameter_list|)
function_decl|;
name|void
name|RegisterDivZeroChecker
parameter_list|(
name|ExprEngine
modifier|&
name|Eng
parameter_list|)
function_decl|;
name|void
name|RegisterNoReturnFunctionChecker
parameter_list|(
name|ExprEngine
modifier|&
name|Eng
parameter_list|)
function_decl|;
name|void
name|RegisterReturnUndefChecker
parameter_list|(
name|ExprEngine
modifier|&
name|Eng
parameter_list|)
function_decl|;
name|void
name|RegisterUndefBranchChecker
parameter_list|(
name|ExprEngine
modifier|&
name|Eng
parameter_list|)
function_decl|;
name|void
name|RegisterUndefCapturedBlockVarChecker
parameter_list|(
name|ExprEngine
modifier|&
name|Eng
parameter_list|)
function_decl|;
name|void
name|RegisterUndefResultChecker
parameter_list|(
name|ExprEngine
modifier|&
name|Eng
parameter_list|)
function_decl|;
name|void
name|RegisterUndefinedArraySubscriptChecker
parameter_list|(
name|ExprEngine
modifier|&
name|Eng
parameter_list|)
function_decl|;
name|void
name|RegisterUndefinedAssignmentChecker
parameter_list|(
name|ExprEngine
modifier|&
name|Eng
parameter_list|)
function_decl|;
name|void
name|RegisterVLASizeChecker
parameter_list|(
name|ExprEngine
modifier|&
name|Eng
parameter_list|)
function_decl|;
comment|// API checks.
name|void
name|RegisterOSAtomicChecker
parameter_list|(
name|ExprEngine
modifier|&
name|Eng
parameter_list|)
function_decl|;
block|}
comment|// end GR namespace
block|}
end_decl_stmt

begin_comment
comment|// end clang namespace
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

