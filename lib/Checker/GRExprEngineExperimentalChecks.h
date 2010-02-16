begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//=-- GRExprEngineExperimentalChecks.h ------------------------------*- C++ -*-=
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
comment|//  This file defines functions to instantiate and register experimental
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
name|LLVM_CLANG_GREXPRENGINE_EXPERIMENTAL_CHECKS
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_GREXPRENGINE_EXPERIMENTAL_CHECKS
end_define

begin_decl_stmt
name|namespace
name|clang
block|{
name|class
name|GRExprEngine
decl_stmt|;
name|void
name|RegisterPthreadLockChecker
parameter_list|(
name|GRExprEngine
modifier|&
name|Eng
parameter_list|)
function_decl|;
name|void
name|RegisterMallocChecker
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

