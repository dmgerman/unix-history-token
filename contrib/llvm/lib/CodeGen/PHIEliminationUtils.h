begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//=- PHIEliminationUtils.h - Helper functions for PHI elimination -*- C++ -*-=//
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
name|LLVM_CODEGEN_PHIELIMINATIONUTILS_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CODEGEN_PHIELIMINATIONUTILS_H
end_define

begin_include
include|#
directive|include
file|"llvm/CodeGen/MachineBasicBlock.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
comment|/// findPHICopyInsertPoint - Find a safe place in MBB to insert a copy from
comment|/// SrcReg when following the CFG edge to SuccMBB. This needs to be after
comment|/// any def of SrcReg, but before any subsequent point where control flow
comment|/// might jump out of the basic block.
name|MachineBasicBlock
operator|::
name|iterator
name|findPHICopyInsertPoint
argument_list|(
argument|MachineBasicBlock* MBB
argument_list|,
argument|MachineBasicBlock* SuccMBB
argument_list|,
argument|unsigned SrcReg
argument_list|)
expr_stmt|;
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

