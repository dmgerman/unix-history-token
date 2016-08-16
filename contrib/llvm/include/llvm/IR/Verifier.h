begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- Verifier.h - LLVM IR Verifier ----------------------------*- C++ -*-===//
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
comment|// This file defines the function verifier interface, that can be used for some
end_comment

begin_comment
comment|// sanity checking of input to the system, and for checking that transformations
end_comment

begin_comment
comment|// haven't done something bad.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Note that this does not provide full 'java style' security and verifications,
end_comment

begin_comment
comment|// instead it just tries to ensure that code is well formed.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// To see what specifically is checked, look at the top of Verifier.cpp
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
name|LLVM_IR_VERIFIER_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_IR_VERIFIER_H
end_define

begin_include
include|#
directive|include
file|"llvm/IR/PassManager.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|Function
decl_stmt|;
name|class
name|FunctionPass
decl_stmt|;
name|class
name|ModulePass
decl_stmt|;
name|class
name|Module
decl_stmt|;
name|class
name|raw_ostream
decl_stmt|;
comment|/// \brief Check a function for errors, useful for use when debugging a
comment|/// pass.
comment|///
comment|/// If there are no errors, the function returns false. If an error is found,
comment|/// a message describing the error is written to OS (if non-null) and true is
comment|/// returned.
name|bool
name|verifyFunction
parameter_list|(
specifier|const
name|Function
modifier|&
name|F
parameter_list|,
name|raw_ostream
modifier|*
name|OS
init|=
name|nullptr
parameter_list|)
function_decl|;
comment|/// \brief Check a module for errors.
comment|///
comment|/// If there are no errors, the function returns false. If an error is
comment|/// found, a message describing the error is written to OS (if
comment|/// non-null) and true is returned.
comment|///
comment|/// \return true if the module is broken. If BrokenDebugInfo is
comment|/// supplied, DebugInfo verification failures won't be considered as
comment|/// error and instead *BrokenDebugInfo will be set to true. Debug
comment|/// info errors can be "recovered" from by stripping the debug info.
name|bool
name|verifyModule
parameter_list|(
specifier|const
name|Module
modifier|&
name|M
parameter_list|,
name|raw_ostream
modifier|*
name|OS
init|=
name|nullptr
parameter_list|,
name|bool
modifier|*
name|BrokenDebugInfo
init|=
name|nullptr
parameter_list|)
function_decl|;
name|FunctionPass
modifier|*
name|createVerifierPass
parameter_list|(
name|bool
name|FatalErrors
init|=
name|true
parameter_list|)
function_decl|;
comment|/// Check a module for errors, and report separate error states for IR
comment|/// and debug info errors.
name|class
name|VerifierAnalysis
range|:
name|public
name|AnalysisInfoMixin
operator|<
name|VerifierAnalysis
operator|>
block|{
name|friend
name|AnalysisInfoMixin
operator|<
name|VerifierAnalysis
operator|>
block|;
specifier|static
name|char
name|PassID
block|;
name|public
operator|:
expr|struct
name|Result
block|{
name|bool
name|IRBroken
block|,
name|DebugInfoBroken
block|;   }
block|;
specifier|static
name|void
operator|*
name|ID
argument_list|()
block|{
return|return
operator|(
name|void
operator|*
operator|)
operator|&
name|PassID
return|;
block|}
name|Result
name|run
argument_list|(
name|Module
operator|&
name|M
argument_list|,
name|ModuleAnalysisManager
operator|&
argument_list|)
block|;
name|Result
name|run
argument_list|(
name|Function
operator|&
name|F
argument_list|,
name|FunctionAnalysisManager
operator|&
argument_list|)
block|; }
decl_stmt|;
comment|/// Check a module for errors, but report debug info errors separately.
comment|/// Otherwise behaves as the normal verifyModule. Debug info errors can be
comment|/// "recovered" from by stripping the debug info.
name|bool
name|verifyModule
parameter_list|(
name|bool
modifier|&
name|BrokenDebugInfo
parameter_list|,
specifier|const
name|Module
modifier|&
name|M
parameter_list|,
name|raw_ostream
modifier|*
name|OS
parameter_list|)
function_decl|;
comment|/// \brief Create a verifier pass.
comment|///
comment|/// Check a module or function for validity. This is essentially a pass wrapped
comment|/// around the above verifyFunction and verifyModule routines and
comment|/// functionality. When the pass detects a verification error it is always
comment|/// printed to stderr, and by default they are fatal. You can override that by
comment|/// passing \c false to \p FatalErrors.
comment|///
comment|/// Note that this creates a pass suitable for the legacy pass manager. It has
comment|/// nothing to do with \c VerifierPass.
name|class
name|VerifierPass
range|:
name|public
name|PassInfoMixin
operator|<
name|VerifierPass
operator|>
block|{
name|bool
name|FatalErrors
block|;
name|public
operator|:
name|explicit
name|VerifierPass
argument_list|(
argument|bool FatalErrors = true
argument_list|)
operator|:
name|FatalErrors
argument_list|(
argument|FatalErrors
argument_list|)
block|{}
name|PreservedAnalyses
name|run
argument_list|(
name|Module
operator|&
name|M
argument_list|,
name|ModuleAnalysisManager
operator|&
name|AM
argument_list|)
block|;
name|PreservedAnalyses
name|run
argument_list|(
name|Function
operator|&
name|F
argument_list|,
name|FunctionAnalysisManager
operator|&
name|AM
argument_list|)
block|; }
decl_stmt|;
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

