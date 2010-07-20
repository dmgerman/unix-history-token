begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===--- AnalysisConsumer.h - Front-end Analysis Engine Hooks ---*- C++ -*-===//
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
comment|// This header contains the functions necessary for a front-end to run various
end_comment

begin_comment
comment|// analyses.
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
name|LLVM_CLANG_CHECKER_ANALYSISCONSUMER_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_CHECKER_ANALYSISCONSUMER_H
end_define

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
name|ASTConsumer
decl_stmt|;
name|class
name|Preprocessor
decl_stmt|;
comment|/// CreateAnalysisConsumer - Creates an ASTConsumer to run various code
comment|/// analysis passes.  (The set of analyses run is controlled by command-line
comment|/// options.)
name|ASTConsumer
modifier|*
name|CreateAnalysisConsumer
argument_list|(
specifier|const
name|Preprocessor
operator|&
name|pp
argument_list|,
specifier|const
name|std
operator|::
name|string
operator|&
name|output
argument_list|,
specifier|const
name|AnalyzerOptions
operator|&
name|Opts
argument_list|)
decl_stmt|;
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

