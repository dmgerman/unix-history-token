begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===---------------- lib/CodeGen/CalcSpillWeights.h ------------*- C++ -*-===//
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
name|LLVM_CODEGEN_CALCSPILLWEIGHTS_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CODEGEN_CALCSPILLWEIGHTS_H
end_define

begin_include
include|#
directive|include
file|"llvm/CodeGen/MachineFunctionPass.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|LiveInterval
decl_stmt|;
comment|/// CalculateSpillWeights - Compute spill weights for all virtual register
comment|/// live intervals.
name|class
name|CalculateSpillWeights
range|:
name|public
name|MachineFunctionPass
block|{
name|public
operator|:
specifier|static
name|char
name|ID
block|;
name|CalculateSpillWeights
argument_list|()
operator|:
name|MachineFunctionPass
argument_list|(
argument|&ID
argument_list|)
block|{}
name|virtual
name|void
name|getAnalysisUsage
argument_list|(
argument|AnalysisUsage&au
argument_list|)
specifier|const
block|;
name|virtual
name|bool
name|runOnMachineFunction
argument_list|(
name|MachineFunction
operator|&
name|fn
argument_list|)
block|;
name|private
operator|:
comment|/// Returns true if the given live interval is zero length.
name|bool
name|isZeroLengthInterval
argument_list|(
argument|LiveInterval *li
argument_list|)
specifier|const
block|;   }
decl_stmt|;
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// LLVM_CODEGEN_CALCSPILLWEIGHTS_H
end_comment

end_unit

