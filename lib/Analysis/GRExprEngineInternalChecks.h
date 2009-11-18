begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//=-- GRExprEngineInternalChecks.h- Builtin GRExprEngine Checks -----*- C++ -*-=
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
comment|//  checks in GRExprEngine.
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
name|LLVM_CLANG_GREXPRENGINE_INTERNAL_CHECKS
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_GREXPRENGINE_INTERNAL_CHECKS
end_define

begin_decl_stmt
name|namespace
name|clang
block|{
name|class
name|GRExprEngine
decl_stmt|;
name|void
name|RegisterAttrNonNullChecker
parameter_list|(
name|GRExprEngine
modifier|&
name|Eng
parameter_list|)
function_decl|;
name|void
name|RegisterBadCallChecker
parameter_list|(
name|GRExprEngine
modifier|&
name|Eng
parameter_list|)
function_decl|;
name|void
name|RegisterDereferenceChecker
parameter_list|(
name|GRExprEngine
modifier|&
name|Eng
parameter_list|)
function_decl|;
name|void
name|RegisterDivZeroChecker
parameter_list|(
name|GRExprEngine
modifier|&
name|Eng
parameter_list|)
function_decl|;
name|void
name|RegisterReturnPointerRangeChecker
parameter_list|(
name|GRExprEngine
modifier|&
name|Eng
parameter_list|)
function_decl|;
name|void
name|RegisterReturnStackAddressChecker
parameter_list|(
name|GRExprEngine
modifier|&
name|Eng
parameter_list|)
function_decl|;
name|void
name|RegisterReturnUndefChecker
parameter_list|(
name|GRExprEngine
modifier|&
name|Eng
parameter_list|)
function_decl|;
name|void
name|RegisterVLASizeChecker
parameter_list|(
name|GRExprEngine
modifier|&
name|Eng
parameter_list|)
function_decl|;
name|void
name|RegisterPointerSubChecker
parameter_list|(
name|GRExprEngine
modifier|&
name|Eng
parameter_list|)
function_decl|;
name|void
name|RegisterPointerArithChecker
parameter_list|(
name|GRExprEngine
modifier|&
name|Eng
parameter_list|)
function_decl|;
name|void
name|RegisterFixedAddressChecker
parameter_list|(
name|GRExprEngine
modifier|&
name|Eng
parameter_list|)
function_decl|;
name|void
name|RegisterCastToStructChecker
parameter_list|(
name|GRExprEngine
modifier|&
name|Eng
parameter_list|)
function_decl|;
name|void
name|RegisterUndefinedArgChecker
parameter_list|(
name|GRExprEngine
modifier|&
name|Eng
parameter_list|)
function_decl|;
name|void
name|RegisterArrayBoundChecker
parameter_list|(
name|GRExprEngine
modifier|&
name|Eng
parameter_list|)
function_decl|;
name|void
name|RegisterUndefinedArraySubscriptChecker
parameter_list|(
name|GRExprEngine
modifier|&
name|Eng
parameter_list|)
function_decl|;
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

