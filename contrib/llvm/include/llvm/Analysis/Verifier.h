begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- llvm/Analysis/Verifier.h - LLVM IR Verifier -------------*- C++ -*-===//
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
name|LLVM_ANALYSIS_VERIFIER_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_ANALYSIS_VERIFIER_H
end_define

begin_include
include|#
directive|include
file|<string>
end_include

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
comment|/// @brief An enumeration to specify the action to be taken if errors found.
comment|///
comment|/// This enumeration is used in the functions below to indicate what should
comment|/// happen if the verifier finds errors. Each of the functions that uses
comment|/// this enumeration as an argument provides a default value for it. The
comment|/// actions are listed below.
enum|enum
name|VerifierFailureAction
block|{
name|AbortProcessAction
block|,
comment|///< verifyModule will print to stderr and abort()
name|PrintMessageAction
block|,
comment|///< verifyModule will print to stderr and return true
name|ReturnStatusAction
comment|///< verifyModule will just return true
block|}
enum|;
comment|/// @brief Create a verifier pass.
comment|///
comment|/// Check a module or function for validity.  When the pass is used, the
comment|/// action indicated by the \p action argument will be used if errors are
comment|/// found.
name|FunctionPass
modifier|*
name|createVerifierPass
parameter_list|(
name|VerifierFailureAction
name|action
init|=
name|AbortProcessAction
comment|///< Action to take
parameter_list|)
function_decl|;
comment|/// @brief Check a module for errors.
comment|///
comment|/// If there are no errors, the function returns false. If an error is found,
comment|/// the action taken depends on the \p action parameter.
comment|/// This should only be used for debugging, because it plays games with
comment|/// PassManagers and stuff.
name|bool
name|verifyModule
argument_list|(
specifier|const
name|Module
operator|&
name|M
argument_list|,
comment|///< The module to be verified
name|VerifierFailureAction
name|action
operator|=
name|AbortProcessAction
argument_list|,
comment|///< Action to take
name|std
operator|::
name|string
operator|*
name|ErrorInfo
operator|=
literal|0
comment|///< Information about failures.
argument_list|)
decl_stmt|;
comment|// verifyFunction - Check a function for errors, useful for use when debugging a
comment|// pass.
name|bool
name|verifyFunction
parameter_list|(
specifier|const
name|Function
modifier|&
name|F
parameter_list|,
comment|///< The function to be verified
name|VerifierFailureAction
name|action
init|=
name|AbortProcessAction
comment|///< Action to take
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

