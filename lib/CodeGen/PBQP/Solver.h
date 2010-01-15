begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- Solver.h ------- PBQP solver interface ------------------*- C++ -*-===//
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
name|LLVM_CODEGEN_PBQP_SOLVER_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CODEGEN_PBQP_SOLVER_H
end_define

begin_include
include|#
directive|include
file|"SimpleGraph.h"
end_include

begin_include
include|#
directive|include
file|"Solution.h"
end_include

begin_decl_stmt
name|namespace
name|PBQP
block|{
comment|/// \brief Interface for solver classes.
name|class
name|Solver
block|{
name|public
label|:
name|virtual
operator|~
name|Solver
argument_list|()
operator|=
literal|0
expr_stmt|;
name|virtual
name|Solution
name|solve
argument_list|(
specifier|const
name|SimpleGraph
operator|&
name|orig
argument_list|)
decl|const
init|=
literal|0
decl_stmt|;
block|}
empty_stmt|;
name|Solver
operator|::
operator|~
name|Solver
argument_list|()
block|{}
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// LLVM_CODEGEN_PBQP_SOLVER_H
end_comment

end_unit

