begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- llvm/Analysis/Lint.h - LLVM IR Lint ---------------------*- C++ -*-===//
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
comment|// This file defines lint interfaces that can be used for some sanity checking
end_comment

begin_comment
comment|// of input to the system, and for checking that transformations
end_comment

begin_comment
comment|// haven't done something bad. In contrast to the Verifier, the Lint checker
end_comment

begin_comment
comment|// checks for undefined behavior or constructions with likely unintended
end_comment

begin_comment
comment|// behavior.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// To see what specifically is checked, look at Lint.cpp
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
name|LLVM_ANALYSIS_LINT_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_ANALYSIS_LINT_H
end_define

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|FunctionPass
decl_stmt|;
name|class
name|Module
decl_stmt|;
name|class
name|Function
decl_stmt|;
comment|/// @brief Create a lint pass.
comment|///
comment|/// Check a module or function.
name|FunctionPass
modifier|*
name|createLintPass
parameter_list|()
function_decl|;
comment|/// @brief Check a module.
comment|///
comment|/// This should only be used for debugging, because it plays games with
comment|/// PassManagers and stuff.
name|void
name|lintModule
parameter_list|(
specifier|const
name|Module
modifier|&
name|M
comment|///< The module to be checked
parameter_list|)
function_decl|;
comment|// lintFunction - Check a function.
name|void
name|lintFunction
parameter_list|(
specifier|const
name|Function
modifier|&
name|F
comment|///< The function to be checked
parameter_list|)
function_decl|;
block|}
end_decl_stmt

begin_comment
comment|// End llvm namespace
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

