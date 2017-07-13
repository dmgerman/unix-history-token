begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- SafepointIRVerifier.h - Checks for GC relocation problems *- C++ -*-===//
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
comment|// This file defines a verifier which is useful for enforcing the relocation
end_comment

begin_comment
comment|// properties required by a relocating GC.  Specifically, it looks for uses of
end_comment

begin_comment
comment|// the unrelocated value of pointer SSA values after a possible safepoint. It
end_comment

begin_comment
comment|// attempts to report no false negatives, but may end up reporting false
end_comment

begin_comment
comment|// positives in rare cases (see the note at the top of the corresponding cpp
end_comment

begin_comment
comment|// file.)
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
name|LLVM_IR_SAFEPOINT_IR_VERIFIER
end_ifndef

begin_define
define|#
directive|define
name|LLVM_IR_SAFEPOINT_IR_VERIFIER
end_define

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
comment|/// Run the safepoint verifier over a single function.  Crashes on failure.
name|void
name|verifySafepointIR
parameter_list|(
name|Function
modifier|&
name|F
parameter_list|)
function_decl|;
comment|/// Create an instance of the safepoint verifier pass which can be added to
comment|/// a pass pipeline to check for relocation bugs.
name|FunctionPass
modifier|*
name|createSafepointIRVerifierPass
parameter_list|()
function_decl|;
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// LLVM_IR_SAFEPOINT_IR_VERIFIER
end_comment

end_unit

