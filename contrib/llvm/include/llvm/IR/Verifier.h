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
file|"llvm/ADT/StringRef.h"
end_include

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
name|PreservedAnalyses
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
comment|/// If there are no errors, the function returns false. If an error is found,
comment|/// a message describing the error is written to OS (if non-null) and true is
comment|/// returned.
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
comment|/// Note that this creates a pass suitable for the legacy pass manager. It has nothing to do with \c VerifierPass.
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
comment|/// \brief Create a debug-info verifier pass.
comment|///
comment|/// Check a module for validity of debug info. This is essentially a pass
comment|/// wrapped around the debug-info parts of \a verifyModule().  When the pass
comment|/// detects a verification error it is always printed to stderr, and by default
comment|/// they are fatal. You can override that by passing \c false to \p
comment|/// FatalErrors.
comment|///
comment|/// Note that this creates a pass suitable for the legacy pass manager. It has
comment|/// nothing to do with \c VerifierPass.
name|ModulePass
modifier|*
name|createDebugInfoVerifierPass
parameter_list|(
name|bool
name|FatalErrors
init|=
name|true
parameter_list|)
function_decl|;
name|class
name|VerifierPass
block|{
name|bool
name|FatalErrors
decl_stmt|;
name|public
label|:
name|explicit
name|VerifierPass
argument_list|(
argument|bool FatalErrors = true
argument_list|)
block|:
name|FatalErrors
argument_list|(
argument|FatalErrors
argument_list|)
block|{}
name|PreservedAnalyses
name|run
parameter_list|(
name|Module
modifier|*
name|M
parameter_list|)
function_decl|;
name|PreservedAnalyses
name|run
parameter_list|(
name|Function
modifier|*
name|F
parameter_list|)
function_decl|;
specifier|static
name|StringRef
name|name
parameter_list|()
block|{
return|return
literal|"VerifierPass"
return|;
block|}
block|}
empty_stmt|;
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

