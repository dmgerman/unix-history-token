begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- CheckerRegistration.h - Checker Registration Function-------*- C++ -*-===//
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

begin_ifndef
ifndef|#
directive|ifndef
name|LLVM_CLANG_SA_FRONTEND_CHECKERREGISTRATION_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_SA_FRONTEND_CHECKERREGISTRATION_H
end_define

begin_decl_stmt
name|namespace
name|clang
block|{
name|class
name|AnalyzerOptions
decl_stmt|;
name|class
name|LangOptions
decl_stmt|;
name|class
name|Diagnostic
decl_stmt|;
name|namespace
name|ento
block|{
name|class
name|CheckerManager
decl_stmt|;
name|CheckerManager
modifier|*
name|registerCheckers
parameter_list|(
specifier|const
name|AnalyzerOptions
modifier|&
name|opts
parameter_list|,
specifier|const
name|LangOptions
modifier|&
name|langOpts
parameter_list|,
name|Diagnostic
modifier|&
name|diags
parameter_list|)
function_decl|;
block|}
comment|// end ento namespace
block|}
end_decl_stmt

begin_comment
comment|// end namespace clang
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

