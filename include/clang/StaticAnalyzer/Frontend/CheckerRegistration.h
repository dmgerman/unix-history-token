begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- CheckerRegistration.h - Checker Registration Function ---*- C++ -*-===//
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
name|LLVM_CLANG_STATICANALYZER_FRONTEND_CHECKERREGISTRATION_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_STATICANALYZER_FRONTEND_CHECKERREGISTRATION_H
end_define

begin_include
include|#
directive|include
file|"clang/Basic/LLVM.h"
end_include

begin_include
include|#
directive|include
file|<memory>
end_include

begin_include
include|#
directive|include
file|<string>
end_include

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
name|DiagnosticsEngine
decl_stmt|;
name|namespace
name|ento
block|{
name|class
name|CheckerManager
decl_stmt|;
name|std
operator|::
name|unique_ptr
operator|<
name|CheckerManager
operator|>
name|createCheckerManager
argument_list|(
name|AnalyzerOptions
operator|&
name|opts
argument_list|,
specifier|const
name|LangOptions
operator|&
name|langOpts
argument_list|,
name|ArrayRef
operator|<
name|std
operator|::
name|string
operator|>
name|plugins
argument_list|,
name|DiagnosticsEngine
operator|&
name|diags
argument_list|)
expr_stmt|;
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

