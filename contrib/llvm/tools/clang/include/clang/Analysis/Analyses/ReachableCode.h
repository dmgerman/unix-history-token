begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- ReachableCode.h -----------------------------------------*- C++ --*-===//
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
comment|// A flow-sensitive, path-insensitive analysis of unreachable code.
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
name|LLVM_CLANG_ANALYSIS_ANALYSES_REACHABLECODE_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_ANALYSIS_ANALYSES_REACHABLECODE_H
end_define

begin_include
include|#
directive|include
file|"clang/Basic/SourceLocation.h"
end_include

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_comment
comment|// Forward declarations.
end_comment

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|BitVector
decl_stmt|;
block|}
end_decl_stmt

begin_decl_stmt
name|namespace
name|clang
block|{
name|class
name|AnalysisDeclContext
decl_stmt|;
name|class
name|CFGBlock
decl_stmt|;
name|class
name|Preprocessor
decl_stmt|;
block|}
end_decl_stmt

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_comment
comment|// API.
end_comment

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_decl_stmt
name|namespace
name|clang
block|{
name|namespace
name|reachable_code
block|{
comment|/// Classifications of unreachable code.
enum|enum
name|UnreachableKind
block|{
name|UK_Return
block|,
name|UK_Break
block|,
name|UK_Loop_Increment
block|,
name|UK_Other
block|}
enum|;
name|class
name|Callback
block|{
name|virtual
name|void
name|anchor
parameter_list|()
function_decl|;
name|public
label|:
name|virtual
operator|~
name|Callback
argument_list|()
block|{}
name|virtual
name|void
name|HandleUnreachable
argument_list|(
argument|UnreachableKind UK
argument_list|,
argument|SourceLocation L
argument_list|,
argument|SourceRange ConditionVal
argument_list|,
argument|SourceRange R1
argument_list|,
argument|SourceRange R2
argument_list|)
operator|=
literal|0
expr_stmt|;
block|}
empty_stmt|;
comment|/// ScanReachableFromBlock - Mark all blocks reachable from Start.
comment|/// Returns the total number of blocks that were marked reachable.
name|unsigned
name|ScanReachableFromBlock
argument_list|(
specifier|const
name|CFGBlock
operator|*
name|Start
argument_list|,
name|llvm
operator|::
name|BitVector
operator|&
name|Reachable
argument_list|)
decl_stmt|;
name|void
name|FindUnreachableCode
parameter_list|(
name|AnalysisDeclContext
modifier|&
name|AC
parameter_list|,
name|Preprocessor
modifier|&
name|PP
parameter_list|,
name|Callback
modifier|&
name|CB
parameter_list|)
function_decl|;
block|}
block|}
end_decl_stmt

begin_comment
comment|// end namespace clang::reachable_code
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

