begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//=-- ExperimentalChecks.h ----------------------------------------*- C++ -*-=//
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
name|LLVM_CLANG_GR_ExprEngine_EXPERIMENTAL_CHECKS
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_GR_ExprEngine_EXPERIMENTAL_CHECKS
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
name|void
name|RegisterAnalyzerStatsChecker
parameter_list|(
name|ExprEngine
modifier|&
name|Eng
parameter_list|)
function_decl|;
name|void
name|RegisterMallocChecker
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

