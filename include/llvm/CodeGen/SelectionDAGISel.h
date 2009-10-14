begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- llvm/CodeGen/SelectionDAGISel.h - Common Base Class------*- C++ -*-===//
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
comment|// This file implements the SelectionDAGISel class, which is used as the common
end_comment

begin_comment
comment|// base class for SelectionDAG-based instruction selectors.
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
name|LLVM_CODEGEN_SELECTIONDAG_ISEL_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CODEGEN_SELECTIONDAG_ISEL_H
end_define

begin_include
include|#
directive|include
file|"llvm/BasicBlock.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Pass.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Constant.h"
end_include

begin_include
include|#
directive|include
file|"llvm/CodeGen/SelectionDAG.h"
end_include

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
name|FastISel
decl_stmt|;
name|class
name|SelectionDAGLowering
decl_stmt|;
name|class
name|SDValue
decl_stmt|;
name|class
name|MachineRegisterInfo
decl_stmt|;
name|class
name|MachineBasicBlock
decl_stmt|;
name|class
name|MachineFunction
decl_stmt|;
name|class
name|MachineInstr
decl_stmt|;
name|class
name|MachineModuleInfo
decl_stmt|;
name|class
name|DwarfWriter
decl_stmt|;
name|class
name|TargetLowering
decl_stmt|;
name|class
name|TargetInstrInfo
decl_stmt|;
name|class
name|FunctionLoweringInfo
decl_stmt|;
name|class
name|ScheduleHazardRecognizer
decl_stmt|;
name|class
name|GCFunctionInfo
decl_stmt|;
name|class
name|ScheduleDAGSDNodes
decl_stmt|;
comment|/// SelectionDAGISel - This is the common base class used for SelectionDAG-based
comment|/// pattern-matching instruction selectors.
name|class
name|SelectionDAGISel
range|:
name|public
name|MachineFunctionPass
block|{
name|public
operator|:
specifier|const
name|TargetMachine
operator|&
name|TM
block|;
name|TargetLowering
operator|&
name|TLI
block|;
name|FunctionLoweringInfo
operator|*
name|FuncInfo
block|;
name|MachineFunction
operator|*
name|MF
block|;
name|MachineRegisterInfo
operator|*
name|RegInfo
block|;
name|SelectionDAG
operator|*
name|CurDAG
block|;
name|SelectionDAGLowering
operator|*
name|SDL
block|;
name|MachineBasicBlock
operator|*
name|BB
block|;
name|AliasAnalysis
operator|*
name|AA
block|;
name|GCFunctionInfo
operator|*
name|GFI
block|;
name|CodeGenOpt
operator|::
name|Level
name|OptLevel
block|;
specifier|static
name|char
name|ID
block|;
name|explicit
name|SelectionDAGISel
argument_list|(
argument|TargetMachine&tm
argument_list|,
argument|CodeGenOpt::Level OL = CodeGenOpt::Default
argument_list|)
block|;
name|virtual
operator|~
name|SelectionDAGISel
argument_list|()
block|;
name|TargetLowering
operator|&
name|getTargetLowering
argument_list|()
block|{
return|return
name|TLI
return|;
block|}
name|virtual
name|void
name|getAnalysisUsage
argument_list|(
argument|AnalysisUsage&AU
argument_list|)
specifier|const
block|;
name|virtual
name|bool
name|runOnMachineFunction
argument_list|(
name|MachineFunction
operator|&
name|MF
argument_list|)
block|;
name|unsigned
name|MakeReg
argument_list|(
argument|EVT VT
argument_list|)
block|;
name|virtual
name|void
name|EmitFunctionEntryCode
argument_list|(
argument|Function&Fn
argument_list|,
argument|MachineFunction&MF
argument_list|)
block|{}
name|virtual
name|void
name|InstructionSelect
argument_list|()
operator|=
literal|0
block|;
name|void
name|SelectRootInit
argument_list|()
block|{
name|DAGSize
operator|=
name|CurDAG
operator|->
name|AssignTopologicalOrder
argument_list|()
block|;   }
comment|/// SelectInlineAsmMemoryOperand - Select the specified address as a target
comment|/// addressing mode, according to the specified constraint code.  If this does
comment|/// not match or is not implemented, return true.  The resultant operands
comment|/// (which will appear in the machine instruction) should be added to the
comment|/// OutOps vector.
name|virtual
name|bool
name|SelectInlineAsmMemoryOperand
argument_list|(
argument|const SDValue&Op
argument_list|,
argument|char ConstraintCode
argument_list|,
argument|std::vector<SDValue>&OutOps
argument_list|)
block|{
return|return
name|true
return|;
block|}
comment|/// IsLegalAndProfitableToFold - Returns true if the specific operand node N of
comment|/// U can be folded during instruction selection that starts at Root and
comment|/// folding N is profitable.
name|virtual
name|bool
name|IsLegalAndProfitableToFold
argument_list|(
argument|SDNode *N
argument_list|,
argument|SDNode *U
argument_list|,
argument|SDNode *Root
argument_list|)
specifier|const
block|;
comment|/// CreateTargetHazardRecognizer - Return a newly allocated hazard recognizer
comment|/// to use for this target when scheduling the DAG.
name|virtual
name|ScheduleHazardRecognizer
operator|*
name|CreateTargetHazardRecognizer
argument_list|()
block|;
name|protected
operator|:
comment|/// DAGSize - Size of DAG being instruction selected.
comment|///
name|unsigned
name|DAGSize
block|;
comment|/// SelectInlineAsmMemoryOperands - Calls to this are automatically generated
comment|/// by tblgen.  Others should not call it.
name|void
name|SelectInlineAsmMemoryOperands
argument_list|(
name|std
operator|::
name|vector
operator|<
name|SDValue
operator|>
operator|&
name|Ops
argument_list|)
block|;
comment|// Calls to these predicates are generated by tblgen.
name|bool
name|CheckAndMask
argument_list|(
argument|SDValue LHS
argument_list|,
argument|ConstantSDNode *RHS
argument_list|,
argument|int64_t DesiredMaskS
argument_list|)
specifier|const
block|;
name|bool
name|CheckOrMask
argument_list|(
argument|SDValue LHS
argument_list|,
argument|ConstantSDNode *RHS
argument_list|,
argument|int64_t DesiredMaskS
argument_list|)
specifier|const
block|;
name|private
operator|:
name|void
name|SelectAllBasicBlocks
argument_list|(
name|Function
operator|&
name|Fn
argument_list|,
name|MachineFunction
operator|&
name|MF
argument_list|,
name|MachineModuleInfo
operator|*
name|MMI
argument_list|,
name|DwarfWriter
operator|*
name|DW
argument_list|,
specifier|const
name|TargetInstrInfo
operator|&
name|TII
argument_list|)
block|;
name|void
name|FinishBasicBlock
argument_list|()
block|;
name|void
name|SelectBasicBlock
argument_list|(
argument|BasicBlock *LLVMBB
argument_list|,
argument|BasicBlock::iterator Begin
argument_list|,
argument|BasicBlock::iterator End
argument_list|)
block|;
name|void
name|CodeGenAndEmitDAG
argument_list|()
block|;
name|void
name|LowerArguments
argument_list|(
name|BasicBlock
operator|*
name|BB
argument_list|)
block|;
name|void
name|ComputeLiveOutVRegInfo
argument_list|()
block|;
name|void
name|HandlePHINodesInSuccessorBlocks
argument_list|(
name|BasicBlock
operator|*
name|LLVMBB
argument_list|)
block|;
name|bool
name|HandlePHINodesInSuccessorBlocksFast
argument_list|(
name|BasicBlock
operator|*
name|LLVMBB
argument_list|,
name|FastISel
operator|*
name|F
argument_list|)
block|;
comment|/// Create the scheduler. If a specific scheduler was specified
comment|/// via the SchedulerRegistry, use it, otherwise select the
comment|/// one preferred by the target.
comment|///
name|ScheduleDAGSDNodes
operator|*
name|CreateScheduler
argument_list|()
block|; }
decl_stmt|;
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* LLVM_CODEGEN_SELECTIONDAG_ISEL_H */
end_comment

end_unit

