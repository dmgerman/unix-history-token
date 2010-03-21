begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//=- AnalysisBasedWarnings.h - Sema warnings based on libAnalysis -*- C++ -*-=//
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
comment|// This file defines AnalysisBasedWarnings, a worker object used by Sema
end_comment

begin_comment
comment|// that issues warnings based on dataflow-analysis.
end_comment

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|LLVM_CLANG_SEMA_ANALYSIS_WARNINGS_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_SEMA_ANALYSIS_WARNINGS_H
end_define

begin_decl_stmt
name|namespace
name|clang
block|{
name|namespace
name|sema
block|{
name|class
name|AnalysisBasedWarnings
block|{
name|Sema
modifier|&
name|S
decl_stmt|;
comment|// The warnings to run.
name|unsigned
name|enableCheckFallThrough
range|:
literal|1
decl_stmt|;
name|unsigned
name|enableCheckUnreachable
range|:
literal|1
decl_stmt|;
name|public
label|:
name|AnalysisBasedWarnings
argument_list|(
name|Sema
operator|&
name|s
argument_list|)
expr_stmt|;
name|void
name|IssueWarnings
parameter_list|(
specifier|const
name|Decl
modifier|*
name|D
parameter_list|,
name|QualType
name|BlockTy
init|=
name|QualType
argument_list|()
parameter_list|)
function_decl|;
name|void
name|disableCheckFallThrough
parameter_list|()
block|{
name|enableCheckFallThrough
operator|=
literal|0
expr_stmt|;
block|}
block|}
empty_stmt|;
block|}
block|}
end_decl_stmt

begin_comment
comment|// end namespace clang::sema
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

