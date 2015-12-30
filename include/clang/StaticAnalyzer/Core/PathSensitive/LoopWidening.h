begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===--- LoopWidening.h - Widen loops ---------------------------*- C++ -*-===//
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
comment|///
end_comment

begin_comment
comment|/// This header contains the declarations of functions which are used to widen
end_comment

begin_comment
comment|/// loops which do not otherwise exit. The widening is done by invalidating
end_comment

begin_comment
comment|/// anything which might be modified by the body of the loop.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|LLVM_CLANG_STATICANALYZER_CORE_PATHSENSITIVE_LOOPWIDENING_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_STATICANALYZER_CORE_PATHSENSITIVE_LOOPWIDENING_H
end_define

begin_include
include|#
directive|include
file|"clang/Analysis/CFG.h"
end_include

begin_include
include|#
directive|include
file|"clang/StaticAnalyzer/Core/PathSensitive/ProgramState.h"
end_include

begin_decl_stmt
name|namespace
name|clang
block|{
name|namespace
name|ento
block|{
comment|/// \brief Get the states that result from widening the loop.
comment|///
comment|/// Widen the loop by invalidating anything that might be modified
comment|/// by the loop body in any iteration.
name|ProgramStateRef
name|getWidenedLoopState
parameter_list|(
name|ProgramStateRef
name|PrevState
parameter_list|,
specifier|const
name|LocationContext
modifier|*
name|LCtx
parameter_list|,
name|unsigned
name|BlockCount
parameter_list|,
specifier|const
name|Stmt
modifier|*
name|LoopStmt
parameter_list|)
function_decl|;
block|}
comment|// end namespace ento
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

