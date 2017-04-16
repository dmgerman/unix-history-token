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
name|LLVM_CODEGEN_SELECTIONDAGISEL_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CODEGEN_SELECTIONDAGISEL_H
end_define

begin_include
include|#
directive|include
file|"llvm/CodeGen/MachineFunctionPass.h"
end_include

begin_include
include|#
directive|include
file|"llvm/CodeGen/SelectionDAG.h"
end_include

begin_include
include|#
directive|include
file|"llvm/IR/BasicBlock.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Pass.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Target/TargetSubtargetInfo.h"
end_include

begin_include
include|#
directive|include
file|<memory>
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|FastISel
decl_stmt|;
name|class
name|SelectionDAGBuilder
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
name|OptimizationRemarkEmitter
decl_stmt|;
name|class
name|TargetLowering
decl_stmt|;
name|class
name|TargetLibraryInfo
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
name|class
name|LoadInst
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
name|TargetMachine
operator|&
name|TM
block|;
specifier|const
name|TargetLibraryInfo
operator|*
name|LibInfo
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
name|SelectionDAGBuilder
operator|*
name|SDB
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
specifier|const
name|TargetInstrInfo
operator|*
name|TII
block|;
specifier|const
name|TargetLowering
operator|*
name|TLI
block|;
name|bool
name|FastISelFailed
block|;
name|SmallPtrSet
operator|<
specifier|const
name|Instruction
operator|*
block|,
literal|4
operator|>
name|ElidedArgCopyInstrs
block|;
comment|/// Current optimization remark emitter.
comment|/// Used to report things like combines and FastISel failures.
name|std
operator|::
name|unique_ptr
operator|<
name|OptimizationRemarkEmitter
operator|>
name|ORE
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
operator|~
name|SelectionDAGISel
argument_list|()
name|override
block|;
specifier|const
name|TargetLowering
operator|*
name|getTargetLowering
argument_list|()
specifier|const
block|{
return|return
name|TLI
return|;
block|}
name|void
name|getAnalysisUsage
argument_list|(
argument|AnalysisUsage&AU
argument_list|)
specifier|const
name|override
block|;
name|bool
name|runOnMachineFunction
argument_list|(
argument|MachineFunction&MF
argument_list|)
name|override
block|;
name|virtual
name|void
name|EmitFunctionEntryCode
argument_list|()
block|{}
comment|/// PreprocessISelDAG - This hook allows targets to hack on the graph before
comment|/// instruction selection starts.
name|virtual
name|void
name|PreprocessISelDAG
argument_list|()
block|{}
comment|/// PostprocessISelDAG() - This hook allows the target to hack on the graph
comment|/// right after selection.
name|virtual
name|void
name|PostprocessISelDAG
argument_list|()
block|{}
comment|/// Main hook for targets to transform nodes into machine nodes.
name|virtual
name|void
name|Select
argument_list|(
name|SDNode
operator|*
name|N
argument_list|)
operator|=
literal|0
block|;
comment|/// SelectInlineAsmMemoryOperand - Select the specified address as a target
comment|/// addressing mode, according to the specified constraint.  If this does
comment|/// not match or is not implemented, return true.  The resultant operands
comment|/// (which will appear in the machine instruction) should be added to the
comment|/// OutOps vector.
name|virtual
name|bool
name|SelectInlineAsmMemoryOperand
argument_list|(
argument|const SDValue&Op
argument_list|,
argument|unsigned ConstraintID
argument_list|,
argument|std::vector<SDValue>&OutOps
argument_list|)
block|{
return|return
name|true
return|;
block|}
comment|/// IsProfitableToFold - Returns true if it's profitable to fold the specific
comment|/// operand node N of U during instruction selection that starts at Root.
name|virtual
name|bool
name|IsProfitableToFold
argument_list|(
argument|SDValue N
argument_list|,
argument|SDNode *U
argument_list|,
argument|SDNode *Root
argument_list|)
specifier|const
block|;
comment|/// IsLegalToFold - Returns true if the specific operand node N of
comment|/// U can be folded during instruction selection that starts at Root.
comment|/// FIXME: This is a static member function because the MSP430/X86
comment|/// targets, which uses it during isel.  This could become a proper member.
specifier|static
name|bool
name|IsLegalToFold
argument_list|(
argument|SDValue N
argument_list|,
argument|SDNode *U
argument_list|,
argument|SDNode *Root
argument_list|,
argument|CodeGenOpt::Level OptLevel
argument_list|,
argument|bool IgnoreChains = false
argument_list|)
block|;
comment|// Opcodes used by the DAG state machine:
block|enum
name|BuiltinOpcodes
block|{
name|OPC_Scope
block|,
name|OPC_RecordNode
block|,
name|OPC_RecordChild0
block|,
name|OPC_RecordChild1
block|,
name|OPC_RecordChild2
block|,
name|OPC_RecordChild3
block|,
name|OPC_RecordChild4
block|,
name|OPC_RecordChild5
block|,
name|OPC_RecordChild6
block|,
name|OPC_RecordChild7
block|,
name|OPC_RecordMemRef
block|,
name|OPC_CaptureGlueInput
block|,
name|OPC_MoveChild
block|,
name|OPC_MoveChild0
block|,
name|OPC_MoveChild1
block|,
name|OPC_MoveChild2
block|,
name|OPC_MoveChild3
block|,
name|OPC_MoveChild4
block|,
name|OPC_MoveChild5
block|,
name|OPC_MoveChild6
block|,
name|OPC_MoveChild7
block|,
name|OPC_MoveParent
block|,
name|OPC_CheckSame
block|,
name|OPC_CheckChild0Same
block|,
name|OPC_CheckChild1Same
block|,
name|OPC_CheckChild2Same
block|,
name|OPC_CheckChild3Same
block|,
name|OPC_CheckPatternPredicate
block|,
name|OPC_CheckPredicate
block|,
name|OPC_CheckOpcode
block|,
name|OPC_SwitchOpcode
block|,
name|OPC_CheckType
block|,
name|OPC_SwitchType
block|,
name|OPC_CheckChild0Type
block|,
name|OPC_CheckChild1Type
block|,
name|OPC_CheckChild2Type
block|,
name|OPC_CheckChild3Type
block|,
name|OPC_CheckChild4Type
block|,
name|OPC_CheckChild5Type
block|,
name|OPC_CheckChild6Type
block|,
name|OPC_CheckChild7Type
block|,
name|OPC_CheckInteger
block|,
name|OPC_CheckChild0Integer
block|,
name|OPC_CheckChild1Integer
block|,
name|OPC_CheckChild2Integer
block|,
name|OPC_CheckChild3Integer
block|,
name|OPC_CheckChild4Integer
block|,
name|OPC_CheckCondCode
block|,
name|OPC_CheckValueType
block|,
name|OPC_CheckComplexPat
block|,
name|OPC_CheckAndImm
block|,
name|OPC_CheckOrImm
block|,
name|OPC_CheckFoldableChainNode
block|,
name|OPC_EmitInteger
block|,
name|OPC_EmitRegister
block|,
name|OPC_EmitRegister2
block|,
name|OPC_EmitConvertToTarget
block|,
name|OPC_EmitMergeInputChains
block|,
name|OPC_EmitMergeInputChains1_0
block|,
name|OPC_EmitMergeInputChains1_1
block|,
name|OPC_EmitMergeInputChains1_2
block|,
name|OPC_EmitCopyToReg
block|,
name|OPC_EmitNodeXForm
block|,
name|OPC_EmitNode
block|,
comment|// Space-optimized forms that implicitly encode number of result VTs.
name|OPC_EmitNode0
block|,
name|OPC_EmitNode1
block|,
name|OPC_EmitNode2
block|,
name|OPC_MorphNodeTo
block|,
comment|// Space-optimized forms that implicitly encode number of result VTs.
name|OPC_MorphNodeTo0
block|,
name|OPC_MorphNodeTo1
block|,
name|OPC_MorphNodeTo2
block|,
name|OPC_CompleteMatch
block|,
comment|// Contains offset in table for pattern being selected
name|OPC_Coverage
block|}
block|;    enum
block|{
name|OPFL_None
operator|=
literal|0
block|,
comment|// Node has no chain or glue input and isn't variadic.
name|OPFL_Chain
operator|=
literal|1
block|,
comment|// Node has a chain input.
name|OPFL_GlueInput
operator|=
literal|2
block|,
comment|// Node has a glue input.
name|OPFL_GlueOutput
operator|=
literal|4
block|,
comment|// Node has a glue output.
name|OPFL_MemRefs
operator|=
literal|8
block|,
comment|// Node gets accumulated MemRefs.
name|OPFL_Variadic0
operator|=
literal|1
operator|<<
literal|4
block|,
comment|// Node is variadic, root has 0 fixed inputs.
name|OPFL_Variadic1
operator|=
literal|2
operator|<<
literal|4
block|,
comment|// Node is variadic, root has 1 fixed inputs.
name|OPFL_Variadic2
operator|=
literal|3
operator|<<
literal|4
block|,
comment|// Node is variadic, root has 2 fixed inputs.
name|OPFL_Variadic3
operator|=
literal|4
operator|<<
literal|4
block|,
comment|// Node is variadic, root has 3 fixed inputs.
name|OPFL_Variadic4
operator|=
literal|5
operator|<<
literal|4
block|,
comment|// Node is variadic, root has 4 fixed inputs.
name|OPFL_Variadic5
operator|=
literal|6
operator|<<
literal|4
block|,
comment|// Node is variadic, root has 5 fixed inputs.
name|OPFL_Variadic6
operator|=
literal|7
operator|<<
literal|4
block|,
comment|// Node is variadic, root has 6 fixed inputs.
name|OPFL_VariadicInfo
operator|=
name|OPFL_Variadic6
block|}
block|;
comment|/// getNumFixedFromVariadicInfo - Transform an EmitNode flags word into the
comment|/// number of fixed arity values that should be skipped when copying from the
comment|/// root.
specifier|static
specifier|inline
name|int
name|getNumFixedFromVariadicInfo
argument_list|(
argument|unsigned Flags
argument_list|)
block|{
return|return
operator|(
operator|(
name|Flags
operator|&
name|OPFL_VariadicInfo
operator|)
operator|>>
literal|4
operator|)
operator|-
literal|1
return|;
block|}
name|protected
operator|:
comment|/// DAGSize - Size of DAG being instruction selected.
comment|///
name|unsigned
name|DAGSize
block|;
comment|/// ReplaceUses - replace all uses of the old node F with the use
comment|/// of the new node T.
name|void
name|ReplaceUses
argument_list|(
argument|SDValue F
argument_list|,
argument|SDValue T
argument_list|)
block|{
name|CurDAG
operator|->
name|ReplaceAllUsesOfValueWith
argument_list|(
name|F
argument_list|,
name|T
argument_list|)
block|;   }
comment|/// ReplaceUses - replace all uses of the old nodes F with the use
comment|/// of the new nodes T.
name|void
name|ReplaceUses
argument_list|(
argument|const SDValue *F
argument_list|,
argument|const SDValue *T
argument_list|,
argument|unsigned Num
argument_list|)
block|{
name|CurDAG
operator|->
name|ReplaceAllUsesOfValuesWith
argument_list|(
name|F
argument_list|,
name|T
argument_list|,
name|Num
argument_list|)
block|;   }
comment|/// ReplaceUses - replace all uses of the old node F with the use
comment|/// of the new node T.
name|void
name|ReplaceUses
argument_list|(
argument|SDNode *F
argument_list|,
argument|SDNode *T
argument_list|)
block|{
name|CurDAG
operator|->
name|ReplaceAllUsesWith
argument_list|(
name|F
argument_list|,
name|T
argument_list|)
block|;   }
comment|/// Replace all uses of \c F with \c T, then remove \c F from the DAG.
name|void
name|ReplaceNode
argument_list|(
argument|SDNode *F
argument_list|,
argument|SDNode *T
argument_list|)
block|{
name|CurDAG
operator|->
name|ReplaceAllUsesWith
argument_list|(
name|F
argument_list|,
name|T
argument_list|)
block|;
name|CurDAG
operator|->
name|RemoveDeadNode
argument_list|(
name|F
argument_list|)
block|;   }
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
argument_list|,
specifier|const
name|SDLoc
operator|&
name|DL
argument_list|)
block|;
comment|/// getPatternForIndex - Patterns selected by tablegen during ISEL
name|virtual
name|StringRef
name|getPatternForIndex
argument_list|(
argument|unsigned index
argument_list|)
block|{
name|llvm_unreachable
argument_list|(
literal|"Tblgen should generate the implementation of this!"
argument_list|)
block|;   }
comment|/// getIncludePathForIndex - get the td source location of pattern instantiation
name|virtual
name|StringRef
name|getIncludePathForIndex
argument_list|(
argument|unsigned index
argument_list|)
block|{
name|llvm_unreachable
argument_list|(
literal|"Tblgen should generate the implementation of this!"
argument_list|)
block|;   }
name|public
operator|:
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
comment|/// CheckPatternPredicate - This function is generated by tblgen in the
comment|/// target.  It runs the specified pattern predicate and returns true if it
comment|/// succeeds or false if it fails.  The number is a private implementation
comment|/// detail to the code tblgen produces.
name|virtual
name|bool
name|CheckPatternPredicate
argument_list|(
argument|unsigned PredNo
argument_list|)
specifier|const
block|{
name|llvm_unreachable
argument_list|(
literal|"Tblgen should generate the implementation of this!"
argument_list|)
block|;   }
comment|/// CheckNodePredicate - This function is generated by tblgen in the target.
comment|/// It runs node predicate number PredNo and returns true if it succeeds or
comment|/// false if it fails.  The number is a private implementation
comment|/// detail to the code tblgen produces.
name|virtual
name|bool
name|CheckNodePredicate
argument_list|(
argument|SDNode *N
argument_list|,
argument|unsigned PredNo
argument_list|)
specifier|const
block|{
name|llvm_unreachable
argument_list|(
literal|"Tblgen should generate the implementation of this!"
argument_list|)
block|;   }
name|virtual
name|bool
name|CheckComplexPattern
argument_list|(
argument|SDNode *Root
argument_list|,
argument|SDNode *Parent
argument_list|,
argument|SDValue N
argument_list|,
argument|unsigned PatternNo
argument_list|,
argument|SmallVectorImpl<std::pair<SDValue
argument_list|,
argument|SDNode*>>&Result
argument_list|)
block|{
name|llvm_unreachable
argument_list|(
literal|"Tblgen should generate the implementation of this!"
argument_list|)
block|;   }
name|virtual
name|SDValue
name|RunSDNodeXForm
argument_list|(
argument|SDValue V
argument_list|,
argument|unsigned XFormNo
argument_list|)
block|{
name|llvm_unreachable
argument_list|(
literal|"Tblgen should generate this!"
argument_list|)
block|;   }
name|void
name|SelectCodeCommon
argument_list|(
argument|SDNode *NodeToMatch
argument_list|,
argument|const unsigned char *MatcherTable
argument_list|,
argument|unsigned TableSize
argument_list|)
block|;
comment|/// \brief Return true if complex patterns for this target can mutate the
comment|/// DAG.
name|virtual
name|bool
name|ComplexPatternFuncMutatesDAG
argument_list|()
specifier|const
block|{
return|return
name|false
return|;
block|}
name|private
operator|:
comment|// Calls to these functions are generated by tblgen.
name|void
name|Select_INLINEASM
argument_list|(
name|SDNode
operator|*
name|N
argument_list|)
block|;
name|void
name|Select_READ_REGISTER
argument_list|(
name|SDNode
operator|*
name|N
argument_list|)
block|;
name|void
name|Select_WRITE_REGISTER
argument_list|(
name|SDNode
operator|*
name|N
argument_list|)
block|;
name|void
name|Select_UNDEF
argument_list|(
name|SDNode
operator|*
name|N
argument_list|)
block|;
name|void
name|CannotYetSelect
argument_list|(
name|SDNode
operator|*
name|N
argument_list|)
block|;
name|private
operator|:
name|void
name|DoInstructionSelection
argument_list|()
block|;
name|SDNode
operator|*
name|MorphNode
argument_list|(
argument|SDNode *Node
argument_list|,
argument|unsigned TargetOpc
argument_list|,
argument|SDVTList VTs
argument_list|,
argument|ArrayRef<SDValue> Ops
argument_list|,
argument|unsigned EmitNodeInfo
argument_list|)
block|;
name|SDNode
operator|*
name|MutateStrictFPToFP
argument_list|(
argument|SDNode *Node
argument_list|,
argument|unsigned NewOpc
argument_list|)
block|;
comment|/// Prepares the landing pad to take incoming values or do other EH
comment|/// personality specific tasks. Returns true if the block should be
comment|/// instruction selected, false if no code should be emitted for it.
name|bool
name|PrepareEHLandingPad
argument_list|()
block|;
comment|/// \brief Perform instruction selection on all basic blocks in the function.
name|void
name|SelectAllBasicBlocks
argument_list|(
specifier|const
name|Function
operator|&
name|Fn
argument_list|)
block|;
comment|/// \brief Perform instruction selection on a single basic block, for
comment|/// instructions between \p Begin and \p End.  \p HadTailCall will be set
comment|/// to true if a call in the block was translated as a tail call.
name|void
name|SelectBasicBlock
argument_list|(
argument|BasicBlock::const_iterator Begin
argument_list|,
argument|BasicBlock::const_iterator End
argument_list|,
argument|bool&HadTailCall
argument_list|)
block|;
name|void
name|FinishBasicBlock
argument_list|()
block|;
name|void
name|CodeGenAndEmitDAG
argument_list|()
block|;
comment|/// \brief Generate instructions for lowering the incoming arguments of the
comment|/// given function.
name|void
name|LowerArguments
argument_list|(
specifier|const
name|Function
operator|&
name|F
argument_list|)
block|;
name|void
name|ComputeLiveOutVRegInfo
argument_list|()
block|;
comment|/// Create the scheduler. If a specific scheduler was specified
comment|/// via the SchedulerRegistry, use it, otherwise select the
comment|/// one preferred by the target.
comment|///
name|ScheduleDAGSDNodes
operator|*
name|CreateScheduler
argument_list|()
block|;
comment|/// OpcodeOffset - This is a cache used to dispatch efficiently into isel
comment|/// state machines that start with a OPC_SwitchOpcode node.
name|std
operator|::
name|vector
operator|<
name|unsigned
operator|>
name|OpcodeOffset
block|;
name|void
name|UpdateChains
argument_list|(
argument|SDNode *NodeToMatch
argument_list|,
argument|SDValue InputChain
argument_list|,
argument|SmallVectorImpl<SDNode *>&ChainNodesMatched
argument_list|,
argument|bool isMorphNodeTo
argument_list|)
block|; }
decl_stmt|;
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* LLVM_CODEGEN_SELECTIONDAGISEL_H */
end_comment

end_unit

