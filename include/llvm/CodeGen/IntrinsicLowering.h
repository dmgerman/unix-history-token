begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- IntrinsicLowering.h - Intrinsic Function Lowering -------*- C++ -*-===//
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
comment|// This file defines the IntrinsicLowering interface.  This interface allows
end_comment

begin_comment
comment|// addition of domain-specific or front-end specific intrinsics to LLVM without
end_comment

begin_comment
comment|// having to modify all of the C backend or interpreter.
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
name|LLVM_CODEGEN_INTRINSICLOWERING_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CODEGEN_INTRINSICLOWERING_H
end_define

begin_include
include|#
directive|include
file|"llvm/Intrinsics.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|CallInst
decl_stmt|;
name|class
name|Module
decl_stmt|;
name|class
name|TargetData
decl_stmt|;
name|class
name|IntrinsicLowering
block|{
specifier|const
name|TargetData
modifier|&
name|TD
decl_stmt|;
name|public
label|:
name|explicit
name|IntrinsicLowering
argument_list|(
specifier|const
name|TargetData
operator|&
name|td
argument_list|)
operator|:
name|TD
argument_list|(
argument|td
argument_list|)
block|{}
comment|/// AddPrototypes - This method, if called, causes all of the prototypes
comment|/// that might be needed by an intrinsic lowering implementation to be
comment|/// inserted into the module specified.
name|void
name|AddPrototypes
argument_list|(
name|Module
operator|&
name|M
argument_list|)
expr_stmt|;
comment|/// LowerIntrinsicCall - This method replaces a call with the LLVM function
comment|/// which should be used to implement the specified intrinsic function call.
comment|/// If an intrinsic function must be implemented by the code generator
comment|/// (such as va_start), this function should print a message and abort.
comment|///
comment|/// Otherwise, if an intrinsic function call can be lowered, the code to
comment|/// implement it (often a call to a non-intrinsic function) is inserted
comment|/// _after_ the call instruction and the call is deleted.  The caller must
comment|/// be capable of handling this kind of change.
comment|///
name|void
name|LowerIntrinsicCall
parameter_list|(
name|CallInst
modifier|*
name|CI
parameter_list|)
function_decl|;
block|}
empty_stmt|;
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

