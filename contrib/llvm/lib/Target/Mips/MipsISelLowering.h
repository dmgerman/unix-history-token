begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- MipsISelLowering.h - Mips DAG Lowering Interface --------*- C++ -*-===//
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
comment|// This file defines the interfaces that Mips uses to lower LLVM code into a
end_comment

begin_comment
comment|// selection DAG.
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
name|MipsISELLOWERING_H
end_ifndef

begin_define
define|#
directive|define
name|MipsISELLOWERING_H
end_define

begin_include
include|#
directive|include
file|"Mips.h"
end_include

begin_include
include|#
directive|include
file|"MipsSubtarget.h"
end_include

begin_include
include|#
directive|include
file|"MCTargetDesc/MipsBaseInfo.h"
end_include

begin_include
include|#
directive|include
file|"llvm/CodeGen/CallingConvLower.h"
end_include

begin_include
include|#
directive|include
file|"llvm/CodeGen/SelectionDAG.h"
end_include

begin_include
include|#
directive|include
file|"llvm/IR/Function.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Target/TargetLowering.h"
end_include

begin_include
include|#
directive|include
file|<deque>
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
name|namespace
name|MipsISD
block|{
enum|enum
name|NodeType
block|{
comment|// Start the numbering from where ISD NodeType finishes.
name|FIRST_NUMBER
init|=
name|ISD
operator|::
name|BUILTIN_OP_END
block|,
comment|// Jump and link (call)
name|JmpLink
block|,
comment|// Tail call
name|TailCall
block|,
comment|// Get the Higher 16 bits from a 32-bit immediate
comment|// No relation with Mips Hi register
name|Hi
block|,
comment|// Get the Lower 16 bits from a 32-bit immediate
comment|// No relation with Mips Lo register
name|Lo
block|,
comment|// Handle gp_rel (small data/bss sections) relocation.
name|GPRel
block|,
comment|// Thread Pointer
name|ThreadPointer
block|,
comment|// Floating Point Branch Conditional
name|FPBrcond
block|,
comment|// Floating Point Compare
name|FPCmp
block|,
comment|// Floating Point Conditional Moves
name|CMovFP_T
block|,
name|CMovFP_F
block|,
comment|// FP-to-int truncation node.
name|TruncIntFP
block|,
comment|// Return
name|Ret
block|,
name|EH_RETURN
block|,
comment|// Node used to extract integer from accumulator.
name|MFHI
block|,
name|MFLO
block|,
comment|// Node used to insert integers to accumulator.
name|MTLOHI
block|,
comment|// Mult nodes.
name|Mult
block|,
name|Multu
block|,
comment|// MAdd/Sub nodes
name|MAdd
block|,
name|MAddu
block|,
name|MSub
block|,
name|MSubu
block|,
comment|// DivRem(u)
name|DivRem
block|,
name|DivRemU
block|,
name|DivRem16
block|,
name|DivRemU16
block|,
name|BuildPairF64
block|,
name|ExtractElementF64
block|,
name|Wrapper
block|,
name|DynAlloc
block|,
name|Sync
block|,
name|Ext
block|,
name|Ins
block|,
comment|// EXTR.W instrinsic nodes.
name|EXTP
block|,
name|EXTPDP
block|,
name|EXTR_S_H
block|,
name|EXTR_W
block|,
name|EXTR_R_W
block|,
name|EXTR_RS_W
block|,
name|SHILO
block|,
name|MTHLIP
block|,
comment|// DPA.W intrinsic nodes.
name|MULSAQ_S_W_PH
block|,
name|MAQ_S_W_PHL
block|,
name|MAQ_S_W_PHR
block|,
name|MAQ_SA_W_PHL
block|,
name|MAQ_SA_W_PHR
block|,
name|DPAU_H_QBL
block|,
name|DPAU_H_QBR
block|,
name|DPSU_H_QBL
block|,
name|DPSU_H_QBR
block|,
name|DPAQ_S_W_PH
block|,
name|DPSQ_S_W_PH
block|,
name|DPAQ_SA_L_W
block|,
name|DPSQ_SA_L_W
block|,
name|DPA_W_PH
block|,
name|DPS_W_PH
block|,
name|DPAQX_S_W_PH
block|,
name|DPAQX_SA_W_PH
block|,
name|DPAX_W_PH
block|,
name|DPSX_W_PH
block|,
name|DPSQX_S_W_PH
block|,
name|DPSQX_SA_W_PH
block|,
name|MULSA_W_PH
block|,
name|MULT
block|,
name|MULTU
block|,
name|MADD_DSP
block|,
name|MADDU_DSP
block|,
name|MSUB_DSP
block|,
name|MSUBU_DSP
block|,
comment|// DSP shift nodes.
name|SHLL_DSP
block|,
name|SHRA_DSP
block|,
name|SHRL_DSP
block|,
comment|// DSP setcc and select_cc nodes.
name|SETCC_DSP
block|,
name|SELECT_CC_DSP
block|,
comment|// Vector comparisons.
comment|// These take a vector and return a boolean.
name|VALL_ZERO
block|,
name|VANY_ZERO
block|,
name|VALL_NONZERO
block|,
name|VANY_NONZERO
block|,
comment|// These take a vector and return a vector bitmask.
name|VCEQ
block|,
name|VCLE_S
block|,
name|VCLE_U
block|,
name|VCLT_S
block|,
name|VCLT_U
block|,
comment|// Element-wise vector max/min.
name|VSMAX
block|,
name|VSMIN
block|,
name|VUMAX
block|,
name|VUMIN
block|,
comment|// Vector Shuffle with mask as an operand
name|VSHF
block|,
comment|// Generic shuffle
name|SHF
block|,
comment|// 4-element set shuffle.
name|ILVEV
block|,
comment|// Interleave even elements
name|ILVOD
block|,
comment|// Interleave odd elements
name|ILVL
block|,
comment|// Interleave left elements
name|ILVR
block|,
comment|// Interleave right elements
name|PCKEV
block|,
comment|// Pack even elements
name|PCKOD
block|,
comment|// Pack odd elements
comment|// Combined (XOR (OR $a, $b), -1)
name|VNOR
block|,
comment|// Extended vector element extraction
name|VEXTRACT_SEXT_ELT
block|,
name|VEXTRACT_ZEXT_ELT
block|,
comment|// Load/Store Left/Right nodes.
name|LWL
init|=
name|ISD
operator|::
name|FIRST_TARGET_MEMORY_OPCODE
block|,
name|LWR
block|,
name|SWL
block|,
name|SWR
block|,
name|LDL
block|,
name|LDR
block|,
name|SDL
block|,
name|SDR
block|}
enum|;
block|}
comment|//===--------------------------------------------------------------------===//
comment|// TargetLowering Implementation
comment|//===--------------------------------------------------------------------===//
name|class
name|MipsFunctionInfo
decl_stmt|;
name|class
name|MipsTargetLowering
range|:
name|public
name|TargetLowering
block|{
name|public
operator|:
name|explicit
name|MipsTargetLowering
argument_list|(
name|MipsTargetMachine
operator|&
name|TM
argument_list|)
block|;
specifier|static
specifier|const
name|MipsTargetLowering
operator|*
name|create
argument_list|(
name|MipsTargetMachine
operator|&
name|TM
argument_list|)
block|;
name|virtual
name|MVT
name|getScalarShiftAmountTy
argument_list|(
argument|EVT LHSTy
argument_list|)
specifier|const
block|{
return|return
name|MVT
operator|::
name|i32
return|;
block|}
name|virtual
name|void
name|LowerOperationWrapper
argument_list|(
argument|SDNode *N
argument_list|,
argument|SmallVectorImpl<SDValue>&Results
argument_list|,
argument|SelectionDAG&DAG
argument_list|)
specifier|const
block|;
comment|/// LowerOperation - Provide custom lowering hooks for some operations.
name|virtual
name|SDValue
name|LowerOperation
argument_list|(
argument|SDValue Op
argument_list|,
argument|SelectionDAG&DAG
argument_list|)
specifier|const
block|;
comment|/// ReplaceNodeResults - Replace the results of node with an illegal result
comment|/// type with new values built out of custom code.
comment|///
name|virtual
name|void
name|ReplaceNodeResults
argument_list|(
argument|SDNode *N
argument_list|,
argument|SmallVectorImpl<SDValue>&Results
argument_list|,
argument|SelectionDAG&DAG
argument_list|)
specifier|const
block|;
comment|/// getTargetNodeName - This method returns the name of a target specific
comment|//  DAG node.
name|virtual
specifier|const
name|char
operator|*
name|getTargetNodeName
argument_list|(
argument|unsigned Opcode
argument_list|)
specifier|const
block|;
comment|/// getSetCCResultType - get the ISD::SETCC result ValueType
name|EVT
name|getSetCCResultType
argument_list|(
argument|LLVMContext&Context
argument_list|,
argument|EVT VT
argument_list|)
specifier|const
block|;
name|virtual
name|SDValue
name|PerformDAGCombine
argument_list|(
argument|SDNode *N
argument_list|,
argument|DAGCombinerInfo&DCI
argument_list|)
specifier|const
block|;
name|virtual
name|MachineBasicBlock
operator|*
name|EmitInstrWithCustomInserter
argument_list|(
argument|MachineInstr *MI
argument_list|,
argument|MachineBasicBlock *MBB
argument_list|)
specifier|const
block|;      struct
name|LTStr
block|{
name|bool
name|operator
argument_list|()
operator|(
specifier|const
name|char
operator|*
name|S1
expr|,
specifier|const
name|char
operator|*
name|S2
operator|)
specifier|const
block|{
return|return
name|strcmp
argument_list|(
name|S1
argument_list|,
name|S2
argument_list|)
operator|<
literal|0
return|;
block|}
expr|}
block|;
name|protected
operator|:
name|SDValue
name|getGlobalReg
argument_list|(
argument|SelectionDAG&DAG
argument_list|,
argument|EVT Ty
argument_list|)
specifier|const
block|;
comment|// This method creates the following nodes, which are necessary for
comment|// computing a local symbol's address:
comment|//
comment|// (add (load (wrapper $gp, %got(sym)), %lo(sym))
name|template
operator|<
name|class
name|NodeTy
operator|>
name|SDValue
name|getAddrLocal
argument_list|(
argument|NodeTy *N
argument_list|,
argument|EVT Ty
argument_list|,
argument|SelectionDAG&DAG
argument_list|,
argument|bool HasMips64
argument_list|)
specifier|const
block|{
name|SDLoc
name|DL
argument_list|(
name|N
argument_list|)
block|;
name|unsigned
name|GOTFlag
operator|=
name|HasMips64
condition|?
name|MipsII
operator|::
name|MO_GOT_PAGE
else|:
name|MipsII
operator|::
name|MO_GOT
block|;
name|SDValue
name|GOT
operator|=
name|DAG
operator|.
name|getNode
argument_list|(
name|MipsISD
operator|::
name|Wrapper
argument_list|,
name|DL
argument_list|,
name|Ty
argument_list|,
name|getGlobalReg
argument_list|(
name|DAG
argument_list|,
name|Ty
argument_list|)
argument_list|,
name|getTargetNode
argument_list|(
name|N
argument_list|,
name|Ty
argument_list|,
name|DAG
argument_list|,
name|GOTFlag
argument_list|)
argument_list|)
block|;
name|SDValue
name|Load
operator|=
name|DAG
operator|.
name|getLoad
argument_list|(
name|Ty
argument_list|,
name|DL
argument_list|,
name|DAG
operator|.
name|getEntryNode
argument_list|()
argument_list|,
name|GOT
argument_list|,
name|MachinePointerInfo
operator|::
name|getGOT
argument_list|()
argument_list|,
name|false
argument_list|,
name|false
argument_list|,
name|false
argument_list|,
literal|0
argument_list|)
block|;
name|unsigned
name|LoFlag
operator|=
name|HasMips64
condition|?
name|MipsII
operator|::
name|MO_GOT_OFST
else|:
name|MipsII
operator|::
name|MO_ABS_LO
block|;
name|SDValue
name|Lo
operator|=
name|DAG
operator|.
name|getNode
argument_list|(
name|MipsISD
operator|::
name|Lo
argument_list|,
name|DL
argument_list|,
name|Ty
argument_list|,
name|getTargetNode
argument_list|(
name|N
argument_list|,
name|Ty
argument_list|,
name|DAG
argument_list|,
name|LoFlag
argument_list|)
argument_list|)
block|;
return|return
name|DAG
operator|.
name|getNode
argument_list|(
name|ISD
operator|::
name|ADD
argument_list|,
name|DL
argument_list|,
name|Ty
argument_list|,
name|Load
argument_list|,
name|Lo
argument_list|)
return|;
block|}
comment|// This method creates the following nodes, which are necessary for
comment|// computing a global symbol's address:
comment|//
comment|// (load (wrapper $gp, %got(sym)))
name|template
operator|<
name|class
name|NodeTy
operator|>
name|SDValue
name|getAddrGlobal
argument_list|(
argument|NodeTy *N
argument_list|,
argument|EVT Ty
argument_list|,
argument|SelectionDAG&DAG
argument_list|,
argument|unsigned Flag
argument_list|,
argument|SDValue Chain
argument_list|,
argument|const MachinePointerInfo&PtrInfo
argument_list|)
specifier|const
block|{
name|SDLoc
name|DL
argument_list|(
name|N
argument_list|)
block|;
name|SDValue
name|Tgt
operator|=
name|DAG
operator|.
name|getNode
argument_list|(
name|MipsISD
operator|::
name|Wrapper
argument_list|,
name|DL
argument_list|,
name|Ty
argument_list|,
name|getGlobalReg
argument_list|(
name|DAG
argument_list|,
name|Ty
argument_list|)
argument_list|,
name|getTargetNode
argument_list|(
name|N
argument_list|,
name|Ty
argument_list|,
name|DAG
argument_list|,
name|Flag
argument_list|)
argument_list|)
block|;
return|return
name|DAG
operator|.
name|getLoad
argument_list|(
name|Ty
argument_list|,
name|DL
argument_list|,
name|Chain
argument_list|,
name|Tgt
argument_list|,
name|PtrInfo
argument_list|,
name|false
argument_list|,
name|false
argument_list|,
name|false
argument_list|,
literal|0
argument_list|)
return|;
block|}
comment|// This method creates the following nodes, which are necessary for
comment|// computing a global symbol's address in large-GOT mode:
comment|//
comment|// (load (wrapper (add %hi(sym), $gp), %lo(sym)))
name|template
operator|<
name|class
name|NodeTy
operator|>
name|SDValue
name|getAddrGlobalLargeGOT
argument_list|(
argument|NodeTy *N
argument_list|,
argument|EVT Ty
argument_list|,
argument|SelectionDAG&DAG
argument_list|,
argument|unsigned HiFlag
argument_list|,
argument|unsigned LoFlag
argument_list|,
argument|SDValue Chain
argument_list|,
argument|const MachinePointerInfo&PtrInfo
argument_list|)
specifier|const
block|{
name|SDLoc
name|DL
argument_list|(
name|N
argument_list|)
block|;
name|SDValue
name|Hi
operator|=
name|DAG
operator|.
name|getNode
argument_list|(
name|MipsISD
operator|::
name|Hi
argument_list|,
name|DL
argument_list|,
name|Ty
argument_list|,
name|getTargetNode
argument_list|(
name|N
argument_list|,
name|Ty
argument_list|,
name|DAG
argument_list|,
name|HiFlag
argument_list|)
argument_list|)
block|;
name|Hi
operator|=
name|DAG
operator|.
name|getNode
argument_list|(
name|ISD
operator|::
name|ADD
argument_list|,
name|DL
argument_list|,
name|Ty
argument_list|,
name|Hi
argument_list|,
name|getGlobalReg
argument_list|(
name|DAG
argument_list|,
name|Ty
argument_list|)
argument_list|)
block|;
name|SDValue
name|Wrapper
operator|=
name|DAG
operator|.
name|getNode
argument_list|(
name|MipsISD
operator|::
name|Wrapper
argument_list|,
name|DL
argument_list|,
name|Ty
argument_list|,
name|Hi
argument_list|,
name|getTargetNode
argument_list|(
name|N
argument_list|,
name|Ty
argument_list|,
name|DAG
argument_list|,
name|LoFlag
argument_list|)
argument_list|)
block|;
return|return
name|DAG
operator|.
name|getLoad
argument_list|(
name|Ty
argument_list|,
name|DL
argument_list|,
name|Chain
argument_list|,
name|Wrapper
argument_list|,
name|PtrInfo
argument_list|,
name|false
argument_list|,
name|false
argument_list|,
name|false
argument_list|,
literal|0
argument_list|)
return|;
block|}
comment|// This method creates the following nodes, which are necessary for
comment|// computing a symbol's address in non-PIC mode:
comment|//
comment|// (add %hi(sym), %lo(sym))
name|template
operator|<
name|class
name|NodeTy
operator|>
name|SDValue
name|getAddrNonPIC
argument_list|(
argument|NodeTy *N
argument_list|,
argument|EVT Ty
argument_list|,
argument|SelectionDAG&DAG
argument_list|)
specifier|const
block|{
name|SDLoc
name|DL
argument_list|(
name|N
argument_list|)
block|;
name|SDValue
name|Hi
operator|=
name|getTargetNode
argument_list|(
name|N
argument_list|,
name|Ty
argument_list|,
name|DAG
argument_list|,
name|MipsII
operator|::
name|MO_ABS_HI
argument_list|)
block|;
name|SDValue
name|Lo
operator|=
name|getTargetNode
argument_list|(
name|N
argument_list|,
name|Ty
argument_list|,
name|DAG
argument_list|,
name|MipsII
operator|::
name|MO_ABS_LO
argument_list|)
block|;
return|return
name|DAG
operator|.
name|getNode
argument_list|(
name|ISD
operator|::
name|ADD
argument_list|,
name|DL
argument_list|,
name|Ty
argument_list|,
name|DAG
operator|.
name|getNode
argument_list|(
name|MipsISD
operator|::
name|Hi
argument_list|,
name|DL
argument_list|,
name|Ty
argument_list|,
name|Hi
argument_list|)
argument_list|,
name|DAG
operator|.
name|getNode
argument_list|(
name|MipsISD
operator|::
name|Lo
argument_list|,
name|DL
argument_list|,
name|Ty
argument_list|,
name|Lo
argument_list|)
argument_list|)
return|;
block|}
comment|/// This function fills Ops, which is the list of operands that will later
comment|/// be used when a function call node is created. It also generates
comment|/// copyToReg nodes to set up argument registers.
name|virtual
name|void
name|getOpndList
argument_list|(
argument|SmallVectorImpl<SDValue>&Ops
argument_list|,
argument|std::deque< std::pair<unsigned
argument_list|,
argument|SDValue>>&RegsToPass
argument_list|,
argument|bool IsPICCall
argument_list|,
argument|bool GlobalOrExternal
argument_list|,
argument|bool InternalLinkage
argument_list|,
argument|CallLoweringInfo&CLI
argument_list|,
argument|SDValue Callee
argument_list|,
argument|SDValue Chain
argument_list|)
specifier|const
block|;
comment|/// ByValArgInfo - Byval argument information.
block|struct
name|ByValArgInfo
block|{
name|unsigned
name|FirstIdx
block|;
comment|// Index of the first register used.
name|unsigned
name|NumRegs
block|;
comment|// Number of registers used for this argument.
name|unsigned
name|Address
block|;
comment|// Offset of the stack area used to pass this argument.
name|ByValArgInfo
argument_list|()
operator|:
name|FirstIdx
argument_list|(
literal|0
argument_list|)
block|,
name|NumRegs
argument_list|(
literal|0
argument_list|)
block|,
name|Address
argument_list|(
literal|0
argument_list|)
block|{}
block|}
block|;
comment|/// MipsCC - This class provides methods used to analyze formal and call
comment|/// arguments and inquire about calling convention information.
name|class
name|MipsCC
block|{
name|public
operator|:
expr|enum
name|SpecialCallingConvType
block|{
name|Mips16RetHelperConv
block|,
name|NoSpecialCallingConv
block|}
block|;
name|MipsCC
argument_list|(
argument|CallingConv::ID CallConv
argument_list|,
argument|bool IsO32
argument_list|,
argument|bool IsFP64
argument_list|,
argument|CCState&Info
argument_list|,
argument|SpecialCallingConvType SpecialCallingConv = NoSpecialCallingConv
argument_list|)
block|;
name|void
name|analyzeCallOperands
argument_list|(
argument|const SmallVectorImpl<ISD::OutputArg>&Outs
argument_list|,
argument|bool IsVarArg
argument_list|,
argument|bool IsSoftFloat
argument_list|,
argument|const SDNode *CallNode
argument_list|,
argument|std::vector<ArgListEntry>&FuncArgs
argument_list|)
block|;
name|void
name|analyzeFormalArguments
argument_list|(
argument|const SmallVectorImpl<ISD::InputArg>&Ins
argument_list|,
argument|bool IsSoftFloat
argument_list|,
argument|Function::const_arg_iterator FuncArg
argument_list|)
block|;
name|void
name|analyzeCallResult
argument_list|(
argument|const SmallVectorImpl<ISD::InputArg>&Ins
argument_list|,
argument|bool IsSoftFloat
argument_list|,
argument|const SDNode *CallNode
argument_list|,
argument|const Type *RetTy
argument_list|)
specifier|const
block|;
name|void
name|analyzeReturn
argument_list|(
argument|const SmallVectorImpl<ISD::OutputArg>&Outs
argument_list|,
argument|bool IsSoftFloat
argument_list|,
argument|const Type *RetTy
argument_list|)
specifier|const
block|;
specifier|const
name|CCState
operator|&
name|getCCInfo
argument_list|()
specifier|const
block|{
return|return
name|CCInfo
return|;
block|}
comment|/// hasByValArg - Returns true if function has byval arguments.
name|bool
name|hasByValArg
argument_list|()
specifier|const
block|{
return|return
operator|!
name|ByValArgs
operator|.
name|empty
argument_list|()
return|;
block|}
comment|/// regSize - Size (in number of bits) of integer registers.
name|unsigned
name|regSize
argument_list|()
specifier|const
block|{
return|return
name|IsO32
condition|?
literal|4
else|:
literal|8
return|;
block|}
comment|/// numIntArgRegs - Number of integer registers available for calls.
name|unsigned
name|numIntArgRegs
argument_list|()
specifier|const
block|;
comment|/// reservedArgArea - The size of the area the caller reserves for
comment|/// register arguments. This is 16-byte if ABI is O32.
name|unsigned
name|reservedArgArea
argument_list|()
specifier|const
block|;
comment|/// Return pointer to array of integer argument registers.
specifier|const
name|uint16_t
operator|*
name|intArgRegs
argument_list|()
specifier|const
block|;
typedef|typedef
name|SmallVectorImpl
operator|<
name|ByValArgInfo
operator|>
operator|::
name|const_iterator
name|byval_iterator
expr_stmt|;
name|byval_iterator
name|byval_begin
argument_list|()
specifier|const
block|{
return|return
name|ByValArgs
operator|.
name|begin
argument_list|()
return|;
block|}
name|byval_iterator
name|byval_end
argument_list|()
specifier|const
block|{
return|return
name|ByValArgs
operator|.
name|end
argument_list|()
return|;
block|}
name|private
operator|:
name|void
name|handleByValArg
argument_list|(
argument|unsigned ValNo
argument_list|,
argument|MVT ValVT
argument_list|,
argument|MVT LocVT
argument_list|,
argument|CCValAssign::LocInfo LocInfo
argument_list|,
argument|ISD::ArgFlagsTy ArgFlags
argument_list|)
block|;
comment|/// useRegsForByval - Returns true if the calling convention allows the
comment|/// use of registers to pass byval arguments.
name|bool
name|useRegsForByval
argument_list|()
specifier|const
block|{
return|return
name|CallConv
operator|!=
name|CallingConv
operator|::
name|Fast
return|;
block|}
comment|/// Return the function that analyzes fixed argument list functions.
name|llvm
operator|::
name|CCAssignFn
operator|*
name|fixedArgFn
argument_list|()
specifier|const
block|;
comment|/// Return the function that analyzes variable argument list functions.
name|llvm
operator|::
name|CCAssignFn
operator|*
name|varArgFn
argument_list|()
specifier|const
block|;
specifier|const
name|uint16_t
operator|*
name|shadowRegs
argument_list|()
specifier|const
block|;
name|void
name|allocateRegs
argument_list|(
argument|ByValArgInfo&ByVal
argument_list|,
argument|unsigned ByValSize
argument_list|,
argument|unsigned Align
argument_list|)
block|;
comment|/// Return the type of the register which is used to pass an argument or
comment|/// return a value. This function returns f64 if the argument is an i64
comment|/// value which has been generated as a result of softening an f128 value.
comment|/// Otherwise, it just returns VT.
name|MVT
name|getRegVT
argument_list|(
argument|MVT VT
argument_list|,
argument|const Type *OrigTy
argument_list|,
argument|const SDNode *CallNode
argument_list|,
argument|bool IsSoftFloat
argument_list|)
specifier|const
block|;
name|template
operator|<
name|typename
name|Ty
operator|>
name|void
name|analyzeReturn
argument_list|(
argument|const SmallVectorImpl<Ty>&RetVals
argument_list|,
argument|bool IsSoftFloat
argument_list|,
argument|const SDNode *CallNode
argument_list|,
argument|const Type *RetTy
argument_list|)
specifier|const
block|;
name|CCState
operator|&
name|CCInfo
block|;
name|CallingConv
operator|::
name|ID
name|CallConv
block|;
name|bool
name|IsO32
block|,
name|IsFP64
block|;
name|SpecialCallingConvType
name|SpecialCallingConv
block|;
name|SmallVector
operator|<
name|ByValArgInfo
block|,
literal|2
operator|>
name|ByValArgs
block|;     }
block|;
name|protected
operator|:
name|SDValue
name|lowerLOAD
argument_list|(
argument|SDValue Op
argument_list|,
argument|SelectionDAG&DAG
argument_list|)
specifier|const
block|;
name|SDValue
name|lowerSTORE
argument_list|(
argument|SDValue Op
argument_list|,
argument|SelectionDAG&DAG
argument_list|)
specifier|const
block|;
comment|// Subtarget Info
specifier|const
name|MipsSubtarget
operator|*
name|Subtarget
block|;
name|bool
name|HasMips64
block|,
name|IsN64
block|,
name|IsO32
block|;
name|private
operator|:
comment|// Create a TargetGlobalAddress node.
name|SDValue
name|getTargetNode
argument_list|(
argument|GlobalAddressSDNode *N
argument_list|,
argument|EVT Ty
argument_list|,
argument|SelectionDAG&DAG
argument_list|,
argument|unsigned Flag
argument_list|)
specifier|const
block|;
comment|// Create a TargetExternalSymbol node.
name|SDValue
name|getTargetNode
argument_list|(
argument|ExternalSymbolSDNode *N
argument_list|,
argument|EVT Ty
argument_list|,
argument|SelectionDAG&DAG
argument_list|,
argument|unsigned Flag
argument_list|)
specifier|const
block|;
comment|// Create a TargetBlockAddress node.
name|SDValue
name|getTargetNode
argument_list|(
argument|BlockAddressSDNode *N
argument_list|,
argument|EVT Ty
argument_list|,
argument|SelectionDAG&DAG
argument_list|,
argument|unsigned Flag
argument_list|)
specifier|const
block|;
comment|// Create a TargetJumpTable node.
name|SDValue
name|getTargetNode
argument_list|(
argument|JumpTableSDNode *N
argument_list|,
argument|EVT Ty
argument_list|,
argument|SelectionDAG&DAG
argument_list|,
argument|unsigned Flag
argument_list|)
specifier|const
block|;
comment|// Create a TargetConstantPool node.
name|SDValue
name|getTargetNode
argument_list|(
argument|ConstantPoolSDNode *N
argument_list|,
argument|EVT Ty
argument_list|,
argument|SelectionDAG&DAG
argument_list|,
argument|unsigned Flag
argument_list|)
specifier|const
block|;
name|MipsCC
operator|::
name|SpecialCallingConvType
name|getSpecialCallingConv
argument_list|(
argument|SDValue Callee
argument_list|)
specifier|const
block|;
comment|// Lower Operand helpers
name|SDValue
name|LowerCallResult
argument_list|(
argument|SDValue Chain
argument_list|,
argument|SDValue InFlag
argument_list|,
argument|CallingConv::ID CallConv
argument_list|,
argument|bool isVarArg
argument_list|,
argument|const SmallVectorImpl<ISD::InputArg>&Ins
argument_list|,
argument|SDLoc dl
argument_list|,
argument|SelectionDAG&DAG
argument_list|,
argument|SmallVectorImpl<SDValue>&InVals
argument_list|,
argument|const SDNode *CallNode
argument_list|,
argument|const Type *RetTy
argument_list|)
specifier|const
block|;
comment|// Lower Operand specifics
name|SDValue
name|lowerBR_JT
argument_list|(
argument|SDValue Op
argument_list|,
argument|SelectionDAG&DAG
argument_list|)
specifier|const
block|;
name|SDValue
name|lowerBRCOND
argument_list|(
argument|SDValue Op
argument_list|,
argument|SelectionDAG&DAG
argument_list|)
specifier|const
block|;
name|SDValue
name|lowerConstantPool
argument_list|(
argument|SDValue Op
argument_list|,
argument|SelectionDAG&DAG
argument_list|)
specifier|const
block|;
name|SDValue
name|lowerGlobalAddress
argument_list|(
argument|SDValue Op
argument_list|,
argument|SelectionDAG&DAG
argument_list|)
specifier|const
block|;
name|SDValue
name|lowerBlockAddress
argument_list|(
argument|SDValue Op
argument_list|,
argument|SelectionDAG&DAG
argument_list|)
specifier|const
block|;
name|SDValue
name|lowerGlobalTLSAddress
argument_list|(
argument|SDValue Op
argument_list|,
argument|SelectionDAG&DAG
argument_list|)
specifier|const
block|;
name|SDValue
name|lowerJumpTable
argument_list|(
argument|SDValue Op
argument_list|,
argument|SelectionDAG&DAG
argument_list|)
specifier|const
block|;
name|SDValue
name|lowerSELECT
argument_list|(
argument|SDValue Op
argument_list|,
argument|SelectionDAG&DAG
argument_list|)
specifier|const
block|;
name|SDValue
name|lowerSELECT_CC
argument_list|(
argument|SDValue Op
argument_list|,
argument|SelectionDAG&DAG
argument_list|)
specifier|const
block|;
name|SDValue
name|lowerSETCC
argument_list|(
argument|SDValue Op
argument_list|,
argument|SelectionDAG&DAG
argument_list|)
specifier|const
block|;
name|SDValue
name|lowerVASTART
argument_list|(
argument|SDValue Op
argument_list|,
argument|SelectionDAG&DAG
argument_list|)
specifier|const
block|;
name|SDValue
name|lowerFCOPYSIGN
argument_list|(
argument|SDValue Op
argument_list|,
argument|SelectionDAG&DAG
argument_list|)
specifier|const
block|;
name|SDValue
name|lowerFABS
argument_list|(
argument|SDValue Op
argument_list|,
argument|SelectionDAG&DAG
argument_list|)
specifier|const
block|;
name|SDValue
name|lowerFRAMEADDR
argument_list|(
argument|SDValue Op
argument_list|,
argument|SelectionDAG&DAG
argument_list|)
specifier|const
block|;
name|SDValue
name|lowerRETURNADDR
argument_list|(
argument|SDValue Op
argument_list|,
argument|SelectionDAG&DAG
argument_list|)
specifier|const
block|;
name|SDValue
name|lowerEH_RETURN
argument_list|(
argument|SDValue Op
argument_list|,
argument|SelectionDAG&DAG
argument_list|)
specifier|const
block|;
name|SDValue
name|lowerATOMIC_FENCE
argument_list|(
argument|SDValue Op
argument_list|,
argument|SelectionDAG& DAG
argument_list|)
specifier|const
block|;
name|SDValue
name|lowerShiftLeftParts
argument_list|(
argument|SDValue Op
argument_list|,
argument|SelectionDAG& DAG
argument_list|)
specifier|const
block|;
name|SDValue
name|lowerShiftRightParts
argument_list|(
argument|SDValue Op
argument_list|,
argument|SelectionDAG& DAG
argument_list|,
argument|bool IsSRA
argument_list|)
specifier|const
block|;
name|SDValue
name|lowerADD
argument_list|(
argument|SDValue Op
argument_list|,
argument|SelectionDAG&DAG
argument_list|)
specifier|const
block|;
name|SDValue
name|lowerFP_TO_SINT
argument_list|(
argument|SDValue Op
argument_list|,
argument|SelectionDAG&DAG
argument_list|)
specifier|const
block|;
comment|/// isEligibleForTailCallOptimization - Check whether the call is eligible
comment|/// for tail call optimization.
name|virtual
name|bool
name|isEligibleForTailCallOptimization
argument_list|(
argument|const MipsCC&MipsCCInfo
argument_list|,
argument|unsigned NextStackOffset
argument_list|,
argument|const MipsFunctionInfo& FI
argument_list|)
specifier|const
operator|=
literal|0
block|;
comment|/// copyByValArg - Copy argument registers which were used to pass a byval
comment|/// argument to the stack. Create a stack frame object for the byval
comment|/// argument.
name|void
name|copyByValRegs
argument_list|(
argument|SDValue Chain
argument_list|,
argument|SDLoc DL
argument_list|,
argument|std::vector<SDValue>&OutChains
argument_list|,
argument|SelectionDAG&DAG
argument_list|,
argument|const ISD::ArgFlagsTy&Flags
argument_list|,
argument|SmallVectorImpl<SDValue>&InVals
argument_list|,
argument|const Argument *FuncArg
argument_list|,
argument|const MipsCC&CC
argument_list|,
argument|const ByValArgInfo&ByVal
argument_list|)
specifier|const
block|;
comment|/// passByValArg - Pass a byval argument in registers or on stack.
name|void
name|passByValArg
argument_list|(
argument|SDValue Chain
argument_list|,
argument|SDLoc DL
argument_list|,
argument|std::deque< std::pair<unsigned
argument_list|,
argument|SDValue>>&RegsToPass
argument_list|,
argument|SmallVectorImpl<SDValue>&MemOpChains
argument_list|,
argument|SDValue StackPtr
argument_list|,
argument|MachineFrameInfo *MFI
argument_list|,
argument|SelectionDAG&DAG
argument_list|,
argument|SDValue Arg
argument_list|,
argument|const MipsCC&CC
argument_list|,
argument|const ByValArgInfo&ByVal
argument_list|,
argument|const ISD::ArgFlagsTy&Flags
argument_list|,
argument|bool isLittle
argument_list|)
specifier|const
block|;
comment|/// writeVarArgRegs - Write variable function arguments passed in registers
comment|/// to the stack. Also create a stack frame object for the first variable
comment|/// argument.
name|void
name|writeVarArgRegs
argument_list|(
argument|std::vector<SDValue>&OutChains
argument_list|,
argument|const MipsCC&CC
argument_list|,
argument|SDValue Chain
argument_list|,
argument|SDLoc DL
argument_list|,
argument|SelectionDAG&DAG
argument_list|)
specifier|const
block|;
name|virtual
name|SDValue
name|LowerFormalArguments
argument_list|(
argument|SDValue Chain
argument_list|,
argument|CallingConv::ID CallConv
argument_list|,
argument|bool isVarArg
argument_list|,
argument|const SmallVectorImpl<ISD::InputArg>&Ins
argument_list|,
argument|SDLoc dl
argument_list|,
argument|SelectionDAG&DAG
argument_list|,
argument|SmallVectorImpl<SDValue>&InVals
argument_list|)
specifier|const
block|;
name|SDValue
name|passArgOnStack
argument_list|(
argument|SDValue StackPtr
argument_list|,
argument|unsigned Offset
argument_list|,
argument|SDValue Chain
argument_list|,
argument|SDValue Arg
argument_list|,
argument|SDLoc DL
argument_list|,
argument|bool IsTailCall
argument_list|,
argument|SelectionDAG&DAG
argument_list|)
specifier|const
block|;
name|virtual
name|SDValue
name|LowerCall
argument_list|(
argument|TargetLowering::CallLoweringInfo&CLI
argument_list|,
argument|SmallVectorImpl<SDValue>&InVals
argument_list|)
specifier|const
block|;
name|virtual
name|bool
name|CanLowerReturn
argument_list|(
argument|CallingConv::ID CallConv
argument_list|,
argument|MachineFunction&MF
argument_list|,
argument|bool isVarArg
argument_list|,
argument|const SmallVectorImpl<ISD::OutputArg>&Outs
argument_list|,
argument|LLVMContext&Context
argument_list|)
specifier|const
block|;
name|virtual
name|SDValue
name|LowerReturn
argument_list|(
argument|SDValue Chain
argument_list|,
argument|CallingConv::ID CallConv
argument_list|,
argument|bool isVarArg
argument_list|,
argument|const SmallVectorImpl<ISD::OutputArg>&Outs
argument_list|,
argument|const SmallVectorImpl<SDValue>&OutVals
argument_list|,
argument|SDLoc dl
argument_list|,
argument|SelectionDAG&DAG
argument_list|)
specifier|const
block|;
comment|// Inline asm support
name|ConstraintType
name|getConstraintType
argument_list|(
argument|const std::string&Constraint
argument_list|)
specifier|const
block|;
comment|/// Examine constraint string and operand type and determine a weight value.
comment|/// The operand object must already have been set up with the operand type.
name|ConstraintWeight
name|getSingleConstraintMatchWeight
argument_list|(
argument|AsmOperandInfo&info
argument_list|,
argument|const char *constraint
argument_list|)
specifier|const
block|;
comment|/// This function parses registers that appear in inline-asm constraints.
comment|/// It returns pair (0, 0) on failure.
name|std
operator|::
name|pair
operator|<
name|unsigned
block|,
specifier|const
name|TargetRegisterClass
operator|*
operator|>
name|parseRegForInlineAsmConstraint
argument_list|(
argument|const StringRef&C
argument_list|,
argument|MVT VT
argument_list|)
specifier|const
block|;
name|std
operator|::
name|pair
operator|<
name|unsigned
block|,
specifier|const
name|TargetRegisterClass
operator|*
operator|>
name|getRegForInlineAsmConstraint
argument_list|(
argument|const std::string&Constraint
argument_list|,
argument|MVT VT
argument_list|)
specifier|const
block|;
comment|/// LowerAsmOperandForConstraint - Lower the specified operand into the Ops
comment|/// vector.  If it is invalid, don't add anything to Ops. If hasMemory is
comment|/// true it means one of the asm constraint of the inline asm instruction
comment|/// being processed is 'm'.
name|virtual
name|void
name|LowerAsmOperandForConstraint
argument_list|(
argument|SDValue Op
argument_list|,
argument|std::string&Constraint
argument_list|,
argument|std::vector<SDValue>&Ops
argument_list|,
argument|SelectionDAG&DAG
argument_list|)
specifier|const
block|;
name|virtual
name|bool
name|isLegalAddressingMode
argument_list|(
argument|const AddrMode&AM
argument_list|,
argument|Type *Ty
argument_list|)
specifier|const
block|;
name|virtual
name|bool
name|isOffsetFoldingLegal
argument_list|(
argument|const GlobalAddressSDNode *GA
argument_list|)
specifier|const
block|;
name|virtual
name|EVT
name|getOptimalMemOpType
argument_list|(
argument|uint64_t Size
argument_list|,
argument|unsigned DstAlign
argument_list|,
argument|unsigned SrcAlign
argument_list|,
argument|bool IsMemset
argument_list|,
argument|bool ZeroMemset
argument_list|,
argument|bool MemcpyStrSrc
argument_list|,
argument|MachineFunction&MF
argument_list|)
specifier|const
block|;
comment|/// isFPImmLegal - Returns true if the target can instruction select the
comment|/// specified FP immediate natively. If false, the legalizer will
comment|/// materialize the FP immediate as a load from a constant pool.
name|virtual
name|bool
name|isFPImmLegal
argument_list|(
argument|const APFloat&Imm
argument_list|,
argument|EVT VT
argument_list|)
specifier|const
block|;
name|virtual
name|unsigned
name|getJumpTableEncoding
argument_list|()
specifier|const
block|;
name|MachineBasicBlock
operator|*
name|emitAtomicBinary
argument_list|(
argument|MachineInstr *MI
argument_list|,
argument|MachineBasicBlock *BB
argument_list|,
argument|unsigned Size
argument_list|,
argument|unsigned BinOpcode
argument_list|,
argument|bool Nand = false
argument_list|)
specifier|const
block|;
name|MachineBasicBlock
operator|*
name|emitAtomicBinaryPartword
argument_list|(
argument|MachineInstr *MI
argument_list|,
argument|MachineBasicBlock *BB
argument_list|,
argument|unsigned Size
argument_list|,
argument|unsigned BinOpcode
argument_list|,
argument|bool Nand = false
argument_list|)
specifier|const
block|;
name|MachineBasicBlock
operator|*
name|emitAtomicCmpSwap
argument_list|(
argument|MachineInstr *MI
argument_list|,
argument|MachineBasicBlock *BB
argument_list|,
argument|unsigned Size
argument_list|)
specifier|const
block|;
name|MachineBasicBlock
operator|*
name|emitAtomicCmpSwapPartword
argument_list|(
argument|MachineInstr *MI
argument_list|,
argument|MachineBasicBlock *BB
argument_list|,
argument|unsigned Size
argument_list|)
specifier|const
block|;   }
decl_stmt|;
comment|/// Create MipsTargetLowering objects.
specifier|const
name|MipsTargetLowering
modifier|*
name|createMips16TargetLowering
parameter_list|(
name|MipsTargetMachine
modifier|&
name|TM
parameter_list|)
function_decl|;
specifier|const
name|MipsTargetLowering
modifier|*
name|createMipsSETargetLowering
parameter_list|(
name|MipsTargetMachine
modifier|&
name|TM
parameter_list|)
function_decl|;
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// MipsISELLOWERING_H
end_comment

end_unit

