begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- MachineFunctionAnalysis.h - Owner of MachineFunctions ----*-C++ -*-===//
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
comment|// This file declares the MachineFunctionAnalysis class.
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
name|LLVM_CODEGEN_MACHINEFUNCTIONANALYSIS_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CODEGEN_MACHINEFUNCTIONANALYSIS_H
end_define

begin_include
include|#
directive|include
file|"llvm/Pass.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|MachineFunction
decl_stmt|;
name|class
name|TargetMachine
decl_stmt|;
comment|/// MachineFunctionAnalysis - This class is a Pass that manages a
comment|/// MachineFunction object.
name|struct
name|MachineFunctionAnalysis
range|:
name|public
name|FunctionPass
block|{
name|private
operator|:
specifier|const
name|TargetMachine
operator|&
name|TM
block|;
name|MachineFunction
operator|*
name|MF
block|;
name|unsigned
name|NextFnNum
block|;
name|public
operator|:
specifier|static
name|char
name|ID
block|;
name|explicit
name|MachineFunctionAnalysis
argument_list|(
specifier|const
name|TargetMachine
operator|&
name|tm
argument_list|)
block|;
operator|~
name|MachineFunctionAnalysis
argument_list|()
block|;
name|MachineFunction
operator|&
name|getMF
argument_list|()
specifier|const
block|{
return|return
operator|*
name|MF
return|;
block|}
specifier|const
name|char
operator|*
name|getPassName
argument_list|()
specifier|const
name|override
block|{
return|return
literal|"Machine Function Analysis"
return|;
block|}
name|private
operator|:
name|bool
name|doInitialization
argument_list|(
argument|Module&M
argument_list|)
name|override
block|;
name|bool
name|runOnFunction
argument_list|(
argument|Function&F
argument_list|)
name|override
block|;
name|void
name|releaseMemory
argument_list|()
name|override
block|;
name|void
name|getAnalysisUsage
argument_list|(
argument|AnalysisUsage&AU
argument_list|)
specifier|const
name|override
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

