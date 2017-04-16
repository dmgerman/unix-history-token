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
name|LLVM_LIB_TARGET_MIPS_MIPSISELLOWERING_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_LIB_TARGET_MIPS_MIPSISELLOWERING_H
end_define

begin_include
include|#
directive|include
file|"MCTargetDesc/MipsABIInfo.h"
end_include

begin_include
include|#
directive|include
file|"MCTargetDesc/MipsBaseInfo.h"
end_include

begin_include
include|#
directive|include
file|"Mips.h"
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
enum|:
name|unsigned
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
comment|// Get the Highest (63-48) 16 bits from a 64-bit immediate
name|Highest
block|,
comment|// Get the Higher (47-32) 16 bits from a 64-bit immediate
name|Higher
block|,
comment|// Get the High 16 bits from a 32/64-bit immediate
comment|// No relation with Mips Hi register
name|Hi
block|,
comment|// Get the Lower 16 bits from a 32/64-bit immediate
comment|// No relation with Mips Lo register
name|Lo
block|,
comment|// Get the High 16 bits from a 32 bit immediate for accessing the GOT.
name|GotHi
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
comment|// Interrupt, exception, error trap Return
name|ERet
block|,
comment|// Software Exception Return.
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
name|CIns
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
comment|// Vector Lane Copy
name|INSVE
block|,
comment|// Copy element from one vector to another
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
name|MipsSubtarget
decl_stmt|;
name|class
name|MipsCCState
decl_stmt|;
name|class
name|MipsTargetLowering
range|:
name|public
name|TargetLowering
block|{
name|bool
name|isMicroMips
block|;
name|public
operator|:
name|explicit
name|MipsTargetLowering
argument_list|(
specifier|const
name|MipsTargetMachine
operator|&
name|TM
argument_list|,
specifier|const
name|MipsSubtarget
operator|&
name|STI
argument_list|)
block|;
specifier|static
specifier|const
name|MipsTargetLowering
operator|*
name|create
argument_list|(
specifier|const
name|MipsTargetMachine
operator|&
name|TM
argument_list|,
specifier|const
name|MipsSubtarget
operator|&
name|STI
argument_list|)
block|;
comment|/// createFastISel - This method returns a target specific FastISel object,
comment|/// or null if the target does not support "fast" ISel.
name|FastISel
operator|*
name|createFastISel
argument_list|(
argument|FunctionLoweringInfo&funcInfo
argument_list|,
argument|const TargetLibraryInfo *libInfo
argument_list|)
specifier|const
name|override
block|;
name|MVT
name|getScalarShiftAmountTy
argument_list|(
argument|const DataLayout&
argument_list|,
argument|EVT
argument_list|)
specifier|const
name|override
block|{
return|return
name|MVT
operator|::
name|i32
return|;
block|}
name|bool
name|isCheapToSpeculateCttz
argument_list|()
specifier|const
name|override
block|;
name|bool
name|isCheapToSpeculateCtlz
argument_list|()
specifier|const
name|override
block|;
name|ISD
operator|::
name|NodeType
name|getExtendForAtomicOps
argument_list|()
specifier|const
name|override
block|{
return|return
name|ISD
operator|::
name|SIGN_EXTEND
return|;
block|}
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
name|override
block|;
comment|/// LowerOperation - Provide custom lowering hooks for some operations.
name|SDValue
name|LowerOperation
argument_list|(
argument|SDValue Op
argument_list|,
argument|SelectionDAG&DAG
argument_list|)
specifier|const
name|override
block|;
comment|/// ReplaceNodeResults - Replace the results of node with an illegal result
comment|/// type with new values built out of custom code.
comment|///
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
name|override
block|;
comment|/// getTargetNodeName - This method returns the name of a target specific
comment|//  DAG node.
specifier|const
name|char
operator|*
name|getTargetNodeName
argument_list|(
argument|unsigned Opcode
argument_list|)
specifier|const
name|override
block|;
comment|/// getSetCCResultType - get the ISD::SETCC result ValueType
name|EVT
name|getSetCCResultType
argument_list|(
argument|const DataLayout&DL
argument_list|,
argument|LLVMContext&Context
argument_list|,
argument|EVT VT
argument_list|)
specifier|const
name|override
block|;
name|SDValue
name|PerformDAGCombine
argument_list|(
argument|SDNode *N
argument_list|,
argument|DAGCombinerInfo&DCI
argument_list|)
specifier|const
name|override
block|;
name|MachineBasicBlock
operator|*
name|EmitInstrWithCustomInserter
argument_list|(
argument|MachineInstr&MI
argument_list|,
argument|MachineBasicBlock *MBB
argument_list|)
specifier|const
name|override
block|;
name|void
name|HandleByVal
argument_list|(
argument|CCState *
argument_list|,
argument|unsigned&
argument_list|,
argument|unsigned
argument_list|)
specifier|const
name|override
block|;
name|unsigned
name|getRegisterByName
argument_list|(
argument|const char* RegName
argument_list|,
argument|EVT VT
argument_list|,
argument|SelectionDAG&DAG
argument_list|)
specifier|const
name|override
block|;
comment|/// If a physical register, this returns the register that receives the
comment|/// exception address on entry to an EH pad.
name|unsigned
name|getExceptionPointerRegister
argument_list|(
argument|const Constant *PersonalityFn
argument_list|)
specifier|const
name|override
block|{
return|return
name|ABI
operator|.
name|IsN64
argument_list|()
operator|?
name|Mips
operator|::
name|A0_64
operator|:
name|Mips
operator|::
name|A0
return|;
block|}
comment|/// If a physical register, this returns the register that receives the
comment|/// exception typeid on entry to a landing pad.
name|unsigned
name|getExceptionSelectorRegister
argument_list|(
argument|const Constant *PersonalityFn
argument_list|)
specifier|const
name|override
block|{
return|return
name|ABI
operator|.
name|IsN64
argument_list|()
condition|?
name|Mips
operator|::
name|A1_64
else|:
name|Mips
operator|::
name|A1
return|;
block|}
comment|/// Returns true if a cast between SrcAS and DestAS is a noop.
name|bool
name|isNoopAddrSpaceCast
argument_list|(
argument|unsigned SrcAS
argument_list|,
argument|unsigned DestAS
argument_list|)
specifier|const
name|override
block|{
comment|// Mips doesn't have any special address spaces so we just reserve
comment|// the first 256 for software use (e.g. OpenCL) and treat casts
comment|// between them as noops.
return|return
name|SrcAS
operator|<
literal|256
operator|&&
name|DestAS
operator|<
literal|256
return|;
block|}
name|bool
name|isJumpTableRelative
argument_list|()
specifier|const
name|override
block|{
return|return
name|getTargetMachine
argument_list|()
operator|.
name|isPositionIndependent
argument_list|()
return|;
block|}
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
argument|const SDLoc&DL
argument_list|,
argument|EVT Ty
argument_list|,
argument|SelectionDAG&DAG
argument_list|,
argument|bool IsN32OrN64
argument_list|)
specifier|const
block|{
name|unsigned
name|GOTFlag
operator|=
name|IsN32OrN64
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
argument_list|(
name|DAG
operator|.
name|getMachineFunction
argument_list|()
argument_list|)
argument_list|)
block|;
name|unsigned
name|LoFlag
operator|=
name|IsN32OrN64
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
argument|const SDLoc&DL
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
argument|const SDLoc&DL
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
name|SDValue
name|Hi
operator|=
name|DAG
operator|.
name|getNode
argument_list|(
name|MipsISD
operator|::
name|GotHi
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
argument_list|)
return|;
block|}
comment|// This method creates the following nodes, which are necessary for
comment|// computing a symbol's address in non-PIC mode:
comment|//
comment|// (add %hi(sym), %lo(sym))
comment|//
comment|// This method covers O32, N32 and N64 in sym32 mode.
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
argument|const SDLoc&DL
argument_list|,
argument|EVT Ty
argument_list|,
argument|SelectionDAG&DAG
argument_list|)
specifier|const
block|{
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
comment|// This method creates the following nodes, which are necessary for
comment|// computing a symbol's address in non-PIC mode for N64.
comment|//
comment|// (add (shl (add (shl (add %highest(sym), %higher(sim)), 16), %high(sym)),
comment|//            16), %lo(%sym))
comment|//
comment|// FIXME: This method is not efficent for (micro)MIPS64R6.
name|template
operator|<
name|class
name|NodeTy
operator|>
name|SDValue
name|getAddrNonPICSym64
argument_list|(
argument|NodeTy *N
argument_list|,
argument|const SDLoc&DL
argument_list|,
argument|EVT Ty
argument_list|,
argument|SelectionDAG&DAG
argument_list|)
specifier|const
block|{
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
name|SDValue
name|Highest
operator|=
name|DAG
operator|.
name|getNode
argument_list|(
name|MipsISD
operator|::
name|Highest
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
name|MipsII
operator|::
name|MO_HIGHEST
argument_list|)
argument_list|)
block|;
name|SDValue
name|Higher
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
name|MO_HIGHER
argument_list|)
block|;
name|SDValue
name|HigherPart
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
name|Highest
argument_list|,
name|DAG
operator|.
name|getNode
argument_list|(
name|MipsISD
operator|::
name|Higher
argument_list|,
name|DL
argument_list|,
name|Ty
argument_list|,
name|Higher
argument_list|)
argument_list|)
block|;
name|SDValue
name|Cst
operator|=
name|DAG
operator|.
name|getConstant
argument_list|(
literal|16
argument_list|,
name|DL
argument_list|,
name|MVT
operator|::
name|i32
argument_list|)
block|;
name|SDValue
name|Shift
operator|=
name|DAG
operator|.
name|getNode
argument_list|(
name|ISD
operator|::
name|SHL
argument_list|,
name|DL
argument_list|,
name|Ty
argument_list|,
name|HigherPart
argument_list|,
name|Cst
argument_list|)
block|;
name|SDValue
name|Add
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
name|Shift
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
argument_list|)
block|;
name|SDValue
name|Shift2
operator|=
name|DAG
operator|.
name|getNode
argument_list|(
name|ISD
operator|::
name|SHL
argument_list|,
name|DL
argument_list|,
name|Ty
argument_list|,
name|Add
argument_list|,
name|Cst
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
name|Shift2
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
comment|// This method creates the following nodes, which are necessary for
comment|// computing a symbol's address using gp-relative addressing:
comment|//
comment|// (add $gp, %gp_rel(sym))
name|template
operator|<
name|class
name|NodeTy
operator|>
name|SDValue
name|getAddrGPRel
argument_list|(
argument|NodeTy *N
argument_list|,
argument|const SDLoc&DL
argument_list|,
argument|EVT Ty
argument_list|,
argument|SelectionDAG&DAG
argument_list|)
specifier|const
block|{
name|assert
argument_list|(
name|Ty
operator|==
name|MVT
operator|::
name|i32
argument_list|)
block|;
name|SDValue
name|GPRel
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
name|MO_GPREL
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
name|getRegister
argument_list|(
name|Mips
operator|::
name|GP
argument_list|,
name|Ty
argument_list|)
argument_list|,
name|DAG
operator|.
name|getNode
argument_list|(
name|MipsISD
operator|::
name|GPRel
argument_list|,
name|DL
argument_list|,
name|DAG
operator|.
name|getVTList
argument_list|(
name|Ty
argument_list|)
argument_list|,
name|GPRel
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
argument|bool IsCallReloc
argument_list|,
argument|CallLoweringInfo&CLI
argument_list|,
argument|SDValue Callee
argument_list|,
argument|SDValue Chain
argument_list|)
specifier|const
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
operator|&
name|Subtarget
block|;
comment|// Cache the ABI from the TargetMachine, we use it everywhere.
specifier|const
name|MipsABIInfo
operator|&
name|ABI
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
argument|const SDLoc&dl
argument_list|,
argument|SelectionDAG&DAG
argument_list|,
argument|SmallVectorImpl<SDValue>&InVals
argument_list|,
argument|TargetLowering::CallLoweringInfo&CLI
argument_list|)
specifier|const
block|;
comment|// Lower Operand specifics
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
name|lowerVAARG
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
name|lowerEH_DWARF_CFA
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
argument|const CCState&CCInfo
argument_list|,
argument|unsigned NextStackOffset
argument_list|,
argument|const MipsFunctionInfo&FI
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
argument|const SDLoc&DL
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
argument|unsigned FirstReg
argument_list|,
argument|unsigned LastReg
argument_list|,
argument|const CCValAssign&VA
argument_list|,
argument|MipsCCState&State
argument_list|)
specifier|const
block|;
comment|/// passByValArg - Pass a byval argument in registers or on stack.
name|void
name|passByValArg
argument_list|(
argument|SDValue Chain
argument_list|,
argument|const SDLoc&DL
argument_list|,
argument|std::deque<std::pair<unsigned
argument_list|,
argument|SDValue>>&RegsToPass
argument_list|,
argument|SmallVectorImpl<SDValue>&MemOpChains
argument_list|,
argument|SDValue StackPtr
argument_list|,
argument|MachineFrameInfo&MFI
argument_list|,
argument|SelectionDAG&DAG
argument_list|,
argument|SDValue Arg
argument_list|,
argument|unsigned FirstReg
argument_list|,
argument|unsigned LastReg
argument_list|,
argument|const ISD::ArgFlagsTy&Flags
argument_list|,
argument|bool isLittle
argument_list|,
argument|const CCValAssign&VA
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
argument|SDValue Chain
argument_list|,
argument|const SDLoc&DL
argument_list|,
argument|SelectionDAG&DAG
argument_list|,
argument|CCState&State
argument_list|)
specifier|const
block|;
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
argument|const SDLoc&dl
argument_list|,
argument|SelectionDAG&DAG
argument_list|,
argument|SmallVectorImpl<SDValue>&InVals
argument_list|)
specifier|const
name|override
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
argument|const SDLoc&DL
argument_list|,
argument|bool IsTailCall
argument_list|,
argument|SelectionDAG&DAG
argument_list|)
specifier|const
block|;
name|SDValue
name|LowerCall
argument_list|(
argument|TargetLowering::CallLoweringInfo&CLI
argument_list|,
argument|SmallVectorImpl<SDValue>&InVals
argument_list|)
specifier|const
name|override
block|;
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
name|override
block|;
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
argument|const SDLoc&dl
argument_list|,
argument|SelectionDAG&DAG
argument_list|)
specifier|const
name|override
block|;
name|SDValue
name|LowerInterruptReturn
argument_list|(
argument|SmallVectorImpl<SDValue>&RetOps
argument_list|,
argument|const SDLoc&DL
argument_list|,
argument|SelectionDAG&DAG
argument_list|)
specifier|const
block|;
name|bool
name|shouldSignExtendTypeInLibCall
argument_list|(
argument|EVT Type
argument_list|,
argument|bool IsSigned
argument_list|)
specifier|const
name|override
block|;
comment|// Inline asm support
name|ConstraintType
name|getConstraintType
argument_list|(
argument|StringRef Constraint
argument_list|)
specifier|const
name|override
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
name|override
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
argument|StringRef C
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
argument|const TargetRegisterInfo *TRI
argument_list|,
argument|StringRef Constraint
argument_list|,
argument|MVT VT
argument_list|)
specifier|const
name|override
block|;
comment|/// LowerAsmOperandForConstraint - Lower the specified operand into the Ops
comment|/// vector.  If it is invalid, don't add anything to Ops. If hasMemory is
comment|/// true it means one of the asm constraint of the inline asm instruction
comment|/// being processed is 'm'.
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
name|override
block|;
name|unsigned
name|getInlineAsmMemConstraint
argument_list|(
argument|StringRef ConstraintCode
argument_list|)
specifier|const
name|override
block|{
if|if
condition|(
name|ConstraintCode
operator|==
literal|"R"
condition|)
return|return
name|InlineAsm
operator|::
name|Constraint_R
return|;
elseif|else
if|if
condition|(
name|ConstraintCode
operator|==
literal|"ZC"
condition|)
return|return
name|InlineAsm
operator|::
name|Constraint_ZC
return|;
return|return
name|TargetLowering
operator|::
name|getInlineAsmMemConstraint
argument_list|(
name|ConstraintCode
argument_list|)
return|;
block|}
name|bool
name|isLegalAddressingMode
argument_list|(
specifier|const
name|DataLayout
operator|&
name|DL
argument_list|,
specifier|const
name|AddrMode
operator|&
name|AM
argument_list|,
name|Type
operator|*
name|Ty
argument_list|,
name|unsigned
name|AS
argument_list|)
decl|const
name|override
decl_stmt|;
name|bool
name|isOffsetFoldingLegal
argument_list|(
specifier|const
name|GlobalAddressSDNode
operator|*
name|GA
argument_list|)
decl|const
name|override
decl_stmt|;
name|EVT
name|getOptimalMemOpType
argument_list|(
name|uint64_t
name|Size
argument_list|,
name|unsigned
name|DstAlign
argument_list|,
name|unsigned
name|SrcAlign
argument_list|,
name|bool
name|IsMemset
argument_list|,
name|bool
name|ZeroMemset
argument_list|,
name|bool
name|MemcpyStrSrc
argument_list|,
name|MachineFunction
operator|&
name|MF
argument_list|)
decl|const
name|override
decl_stmt|;
comment|/// isFPImmLegal - Returns true if the target can instruction select the
comment|/// specified FP immediate natively. If false, the legalizer will
comment|/// materialize the FP immediate as a load from a constant pool.
name|bool
name|isFPImmLegal
argument_list|(
specifier|const
name|APFloat
operator|&
name|Imm
argument_list|,
name|EVT
name|VT
argument_list|)
decl|const
name|override
decl_stmt|;
name|unsigned
name|getJumpTableEncoding
argument_list|()
specifier|const
name|override
expr_stmt|;
name|bool
name|useSoftFloat
argument_list|()
specifier|const
name|override
expr_stmt|;
name|bool
name|shouldInsertFencesForAtomic
argument_list|(
specifier|const
name|Instruction
operator|*
name|I
argument_list|)
decl|const
name|override
block|{
return|return
name|true
return|;
block|}
comment|/// Emit a sign-extension using sll/sra, seb, or seh appropriately.
name|MachineBasicBlock
modifier|*
name|emitSignExtendToI32InReg
argument_list|(
name|MachineInstr
operator|&
name|MI
argument_list|,
name|MachineBasicBlock
operator|*
name|BB
argument_list|,
name|unsigned
name|Size
argument_list|,
name|unsigned
name|DstReg
argument_list|,
name|unsigned
name|SrcRec
argument_list|)
decl|const
decl_stmt|;
name|MachineBasicBlock
modifier|*
name|emitAtomicBinary
argument_list|(
name|MachineInstr
operator|&
name|MI
argument_list|,
name|MachineBasicBlock
operator|*
name|BB
argument_list|,
name|unsigned
name|Size
argument_list|,
name|unsigned
name|BinOpcode
argument_list|,
name|bool
name|Nand
operator|=
name|false
argument_list|)
decl|const
decl_stmt|;
name|MachineBasicBlock
modifier|*
name|emitAtomicBinaryPartword
argument_list|(
name|MachineInstr
operator|&
name|MI
argument_list|,
name|MachineBasicBlock
operator|*
name|BB
argument_list|,
name|unsigned
name|Size
argument_list|,
name|unsigned
name|BinOpcode
argument_list|,
name|bool
name|Nand
operator|=
name|false
argument_list|)
decl|const
decl_stmt|;
name|MachineBasicBlock
modifier|*
name|emitAtomicCmpSwap
argument_list|(
name|MachineInstr
operator|&
name|MI
argument_list|,
name|MachineBasicBlock
operator|*
name|BB
argument_list|,
name|unsigned
name|Size
argument_list|)
decl|const
decl_stmt|;
name|MachineBasicBlock
modifier|*
name|emitAtomicCmpSwapPartword
argument_list|(
name|MachineInstr
operator|&
name|MI
argument_list|,
name|MachineBasicBlock
operator|*
name|BB
argument_list|,
name|unsigned
name|Size
argument_list|)
decl|const
decl_stmt|;
name|MachineBasicBlock
modifier|*
name|emitSEL_D
argument_list|(
name|MachineInstr
operator|&
name|MI
argument_list|,
name|MachineBasicBlock
operator|*
name|BB
argument_list|)
decl|const
decl_stmt|;
name|MachineBasicBlock
modifier|*
name|emitPseudoSELECT
argument_list|(
name|MachineInstr
operator|&
name|MI
argument_list|,
name|MachineBasicBlock
operator|*
name|BB
argument_list|,
name|bool
name|isFPCmp
argument_list|,
name|unsigned
name|Opc
argument_list|)
decl|const
decl_stmt|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|/// Create MipsTargetLowering objects.
end_comment

begin_function_decl
specifier|const
name|MipsTargetLowering
modifier|*
name|createMips16TargetLowering
parameter_list|(
specifier|const
name|MipsTargetMachine
modifier|&
name|TM
parameter_list|,
specifier|const
name|MipsSubtarget
modifier|&
name|STI
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|const
name|MipsTargetLowering
modifier|*
name|createMipsSETargetLowering
parameter_list|(
specifier|const
name|MipsTargetMachine
modifier|&
name|TM
parameter_list|,
specifier|const
name|MipsSubtarget
modifier|&
name|STI
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
name|namespace
name|Mips
block|{
name|FastISel
modifier|*
name|createFastISel
parameter_list|(
name|FunctionLoweringInfo
modifier|&
name|funcInfo
parameter_list|,
specifier|const
name|TargetLibraryInfo
modifier|*
name|libInfo
parameter_list|)
function_decl|;
block|}
end_decl_stmt

begin_endif
unit|}
endif|#
directive|endif
end_endif

end_unit

