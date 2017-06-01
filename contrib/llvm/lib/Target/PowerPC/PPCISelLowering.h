begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- PPCISelLowering.h - PPC32 DAG Lowering Interface --------*- C++ -*-===//
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
comment|// This file defines the interfaces that PPC uses to lower LLVM code into a
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
name|LLVM_LIB_TARGET_POWERPC_PPCISELLOWERING_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_LIB_TARGET_POWERPC_PPCISELLOWERING_H
end_define

begin_include
include|#
directive|include
file|"PPC.h"
end_include

begin_include
include|#
directive|include
file|"PPCInstrInfo.h"
end_include

begin_include
include|#
directive|include
file|"llvm/CodeGen/CallingConvLower.h"
end_include

begin_include
include|#
directive|include
file|"llvm/CodeGen/MachineFunction.h"
end_include

begin_include
include|#
directive|include
file|"llvm/CodeGen/MachineMemOperand.h"
end_include

begin_include
include|#
directive|include
file|"llvm/CodeGen/MachineValueType.h"
end_include

begin_include
include|#
directive|include
file|"llvm/CodeGen/SelectionDAG.h"
end_include

begin_include
include|#
directive|include
file|"llvm/CodeGen/SelectionDAGNodes.h"
end_include

begin_include
include|#
directive|include
file|"llvm/CodeGen/ValueTypes.h"
end_include

begin_include
include|#
directive|include
file|"llvm/IR/Attributes.h"
end_include

begin_include
include|#
directive|include
file|"llvm/IR/CallingConv.h"
end_include

begin_include
include|#
directive|include
file|"llvm/IR/Function.h"
end_include

begin_include
include|#
directive|include
file|"llvm/IR/InlineAsm.h"
end_include

begin_include
include|#
directive|include
file|"llvm/IR/Metadata.h"
end_include

begin_include
include|#
directive|include
file|"llvm/IR/Type.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Target/TargetLowering.h"
end_include

begin_include
include|#
directive|include
file|<utility>
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|namespace
name|PPCISD
block|{
enum|enum
name|NodeType
enum|:
name|unsigned
block|{
comment|// Start the numbering where the builtin ops and target ops leave off.
name|FIRST_NUMBER
init|=
name|ISD
operator|::
name|BUILTIN_OP_END
block|,
comment|/// FSEL - Traditional three-operand fsel node.
comment|///
name|FSEL
block|,
comment|/// FCFID - The FCFID instruction, taking an f64 operand and producing
comment|/// and f64 value containing the FP representation of the integer that
comment|/// was temporarily in the f64 operand.
name|FCFID
block|,
comment|/// Newer FCFID[US] integer-to-floating-point conversion instructions for
comment|/// unsigned integers and single-precision outputs.
name|FCFIDU
block|,
name|FCFIDS
block|,
name|FCFIDUS
block|,
comment|/// FCTI[D,W]Z - The FCTIDZ and FCTIWZ instructions, taking an f32 or f64
comment|/// operand, producing an f64 value containing the integer representation
comment|/// of that FP value.
name|FCTIDZ
block|,
name|FCTIWZ
block|,
comment|/// Newer FCTI[D,W]UZ floating-point-to-integer conversion instructions for
comment|/// unsigned integers with round toward zero.
name|FCTIDUZ
block|,
name|FCTIWUZ
block|,
comment|/// VEXTS, ByteWidth - takes an input in VSFRC and produces an output in
comment|/// VSFRC that is sign-extended from ByteWidth to a 64-byte integer.
name|VEXTS
block|,
comment|/// Reciprocal estimate instructions (unary FP ops).
name|FRE
block|,
name|FRSQRTE
block|,
comment|// VMADDFP, VNMSUBFP - The VMADDFP and VNMSUBFP instructions, taking
comment|// three v4f32 operands and producing a v4f32 result.
name|VMADDFP
block|,
name|VNMSUBFP
block|,
comment|/// VPERM - The PPC VPERM Instruction.
comment|///
name|VPERM
block|,
comment|/// XXSPLT - The PPC VSX splat instructions
comment|///
name|XXSPLT
block|,
comment|/// XXINSERT - The PPC VSX insert instruction
comment|///
name|XXINSERT
block|,
comment|/// VECSHL - The PPC VSX shift left instruction
comment|///
name|VECSHL
block|,
comment|/// XXPERMDI - The PPC XXPERMDI instruction
comment|///
name|XXPERMDI
block|,
comment|/// The CMPB instruction (takes two operands of i32 or i64).
name|CMPB
block|,
comment|/// Hi/Lo - These represent the high and low 16-bit parts of a global
comment|/// address respectively.  These nodes have two operands, the first of
comment|/// which must be a TargetGlobalAddress, and the second of which must be a
comment|/// Constant.  Selected naively, these turn into 'lis G+C' and 'li G+C',
comment|/// though these are usually folded into other nodes.
name|Hi
block|,
name|Lo
block|,
comment|/// The following two target-specific nodes are used for calls through
comment|/// function pointers in the 64-bit SVR4 ABI.
comment|/// OPRC, CHAIN = DYNALLOC(CHAIN, NEGSIZE, FRAME_INDEX)
comment|/// This instruction is lowered in PPCRegisterInfo::eliminateFrameIndex to
comment|/// compute an allocation on the stack.
name|DYNALLOC
block|,
comment|/// This instruction is lowered in PPCRegisterInfo::eliminateFrameIndex to
comment|/// compute an offset from native SP to the address  of the most recent
comment|/// dynamic alloca.
name|DYNAREAOFFSET
block|,
comment|/// GlobalBaseReg - On Darwin, this node represents the result of the mflr
comment|/// at function entry, used for PIC code.
name|GlobalBaseReg
block|,
comment|/// These nodes represent PPC shifts.
comment|///
comment|/// For scalar types, only the last `n + 1` bits of the shift amounts
comment|/// are used, where n is log2(sizeof(element) * 8). See sld/slw, etc.
comment|/// for exact behaviors.
comment|///
comment|/// For vector types, only the last n bits are used. See vsld.
name|SRL
block|,
name|SRA
block|,
name|SHL
block|,
comment|/// The combination of sra[wd]i and addze used to implemented signed
comment|/// integer division by a power of 2. The first operand is the dividend,
comment|/// and the second is the constant shift amount (representing the
comment|/// divisor).
name|SRA_ADDZE
block|,
comment|/// CALL - A direct function call.
comment|/// CALL_NOP is a call with the special NOP which follows 64-bit
comment|/// SVR4 calls.
name|CALL
block|,
name|CALL_NOP
block|,
comment|/// CHAIN,FLAG = MTCTR(VAL, CHAIN[, INFLAG]) - Directly corresponds to a
comment|/// MTCTR instruction.
name|MTCTR
block|,
comment|/// CHAIN,FLAG = BCTRL(CHAIN, INFLAG) - Directly corresponds to a
comment|/// BCTRL instruction.
name|BCTRL
block|,
comment|/// CHAIN,FLAG = BCTRL(CHAIN, ADDR, INFLAG) - The combination of a bctrl
comment|/// instruction and the TOC reload required on SVR4 PPC64.
name|BCTRL_LOAD_TOC
block|,
comment|/// Return with a flag operand, matched by 'blr'
name|RET_FLAG
block|,
comment|/// R32 = MFOCRF(CRREG, INFLAG) - Represents the MFOCRF instruction.
comment|/// This copies the bits corresponding to the specified CRREG into the
comment|/// resultant GPR.  Bits corresponding to other CR regs are undefined.
name|MFOCRF
block|,
comment|/// Direct move from a VSX register to a GPR
name|MFVSR
block|,
comment|/// Direct move from a GPR to a VSX register (algebraic)
name|MTVSRA
block|,
comment|/// Direct move from a GPR to a VSX register (zero)
name|MTVSRZ
block|,
comment|/// Extract a subvector from signed integer vector and convert to FP.
comment|/// It is primarily used to convert a (widened) illegal integer vector
comment|/// type to a legal floating point vector type.
comment|/// For example v2i32 -> widened to v4i32 -> v2f64
name|SINT_VEC_TO_FP
block|,
comment|/// Extract a subvector from unsigned integer vector and convert to FP.
comment|/// As with SINT_VEC_TO_FP, used for converting illegal types.
name|UINT_VEC_TO_FP
block|,
comment|// FIXME: Remove these once the ANDI glue bug is fixed:
comment|/// i1 = ANDIo_1_[EQ|GT]_BIT(i32 or i64 x) - Represents the result of the
comment|/// eq or gt bit of CR0 after executing andi. x, 1. This is used to
comment|/// implement truncation of i32 or i64 to i1.
name|ANDIo_1_EQ_BIT
block|,
name|ANDIo_1_GT_BIT
block|,
comment|// READ_TIME_BASE - A read of the 64-bit time-base register on a 32-bit
comment|// target (returns (Lo, Hi)). It takes a chain operand.
name|READ_TIME_BASE
block|,
comment|// EH_SJLJ_SETJMP - SjLj exception handling setjmp.
name|EH_SJLJ_SETJMP
block|,
comment|// EH_SJLJ_LONGJMP - SjLj exception handling longjmp.
name|EH_SJLJ_LONGJMP
block|,
comment|/// RESVEC = VCMP(LHS, RHS, OPC) - Represents one of the altivec VCMP*
comment|/// instructions.  For lack of better number, we use the opcode number
comment|/// encoding for the OPC field to identify the compare.  For example, 838
comment|/// is VCMPGTSH.
name|VCMP
block|,
comment|/// RESVEC, OUTFLAG = VCMPo(LHS, RHS, OPC) - Represents one of the
comment|/// altivec VCMP*o instructions.  For lack of better number, we use the
comment|/// opcode number encoding for the OPC field to identify the compare.  For
comment|/// example, 838 is VCMPGTSH.
name|VCMPo
block|,
comment|/// CHAIN = COND_BRANCH CHAIN, CRRC, OPC, DESTBB [, INFLAG] - This
comment|/// corresponds to the COND_BRANCH pseudo instruction.  CRRC is the
comment|/// condition register to branch on, OPC is the branch opcode to use (e.g.
comment|/// PPC::BLE), DESTBB is the destination block to branch to, and INFLAG is
comment|/// an optional input flag argument.
name|COND_BRANCH
block|,
comment|/// CHAIN = BDNZ CHAIN, DESTBB - These are used to create counter-based
comment|/// loops.
name|BDNZ
block|,
name|BDZ
block|,
comment|/// F8RC = FADDRTZ F8RC, F8RC - This is an FADD done with rounding
comment|/// towards zero.  Used only as part of the long double-to-int
comment|/// conversion sequence.
name|FADDRTZ
block|,
comment|/// F8RC = MFFS - This moves the FPSCR (not modeled) into the register.
name|MFFS
block|,
comment|/// TC_RETURN - A tail call return.
comment|///   operand #0 chain
comment|///   operand #1 callee (register or absolute)
comment|///   operand #2 stack adjustment
comment|///   operand #3 optional in flag
name|TC_RETURN
block|,
comment|/// ch, gl = CR6[UN]SET ch, inglue - Toggle CR bit 6 for SVR4 vararg calls
name|CR6SET
block|,
name|CR6UNSET
block|,
comment|/// GPRC = address of _GLOBAL_OFFSET_TABLE_. Used by initial-exec TLS
comment|/// on PPC32.
name|PPC32_GOT
block|,
comment|/// GPRC = address of _GLOBAL_OFFSET_TABLE_. Used by general dynamic and
comment|/// local dynamic TLS on PPC32.
name|PPC32_PICGOT
block|,
comment|/// G8RC = ADDIS_GOT_TPREL_HA %X2, Symbol - Used by the initial-exec
comment|/// TLS model, produces an ADDIS8 instruction that adds the GOT
comment|/// base to sym\@got\@tprel\@ha.
name|ADDIS_GOT_TPREL_HA
block|,
comment|/// G8RC = LD_GOT_TPREL_L Symbol, G8RReg - Used by the initial-exec
comment|/// TLS model, produces a LD instruction with base register G8RReg
comment|/// and offset sym\@got\@tprel\@l.  This completes the addition that
comment|/// finds the offset of "sym" relative to the thread pointer.
name|LD_GOT_TPREL_L
block|,
comment|/// G8RC = ADD_TLS G8RReg, Symbol - Used by the initial-exec TLS
comment|/// model, produces an ADD instruction that adds the contents of
comment|/// G8RReg to the thread pointer.  Symbol contains a relocation
comment|/// sym\@tls which is to be replaced by the thread pointer and
comment|/// identifies to the linker that the instruction is part of a
comment|/// TLS sequence.
name|ADD_TLS
block|,
comment|/// G8RC = ADDIS_TLSGD_HA %X2, Symbol - For the general-dynamic TLS
comment|/// model, produces an ADDIS8 instruction that adds the GOT base
comment|/// register to sym\@got\@tlsgd\@ha.
name|ADDIS_TLSGD_HA
block|,
comment|/// %X3 = ADDI_TLSGD_L G8RReg, Symbol - For the general-dynamic TLS
comment|/// model, produces an ADDI8 instruction that adds G8RReg to
comment|/// sym\@got\@tlsgd\@l and stores the result in X3.  Hidden by
comment|/// ADDIS_TLSGD_L_ADDR until after register assignment.
name|ADDI_TLSGD_L
block|,
comment|/// %X3 = GET_TLS_ADDR %X3, Symbol - For the general-dynamic TLS
comment|/// model, produces a call to __tls_get_addr(sym\@tlsgd).  Hidden by
comment|/// ADDIS_TLSGD_L_ADDR until after register assignment.
name|GET_TLS_ADDR
block|,
comment|/// G8RC = ADDI_TLSGD_L_ADDR G8RReg, Symbol, Symbol - Op that
comment|/// combines ADDI_TLSGD_L and GET_TLS_ADDR until expansion following
comment|/// register assignment.
name|ADDI_TLSGD_L_ADDR
block|,
comment|/// G8RC = ADDIS_TLSLD_HA %X2, Symbol - For the local-dynamic TLS
comment|/// model, produces an ADDIS8 instruction that adds the GOT base
comment|/// register to sym\@got\@tlsld\@ha.
name|ADDIS_TLSLD_HA
block|,
comment|/// %X3 = ADDI_TLSLD_L G8RReg, Symbol - For the local-dynamic TLS
comment|/// model, produces an ADDI8 instruction that adds G8RReg to
comment|/// sym\@got\@tlsld\@l and stores the result in X3.  Hidden by
comment|/// ADDIS_TLSLD_L_ADDR until after register assignment.
name|ADDI_TLSLD_L
block|,
comment|/// %X3 = GET_TLSLD_ADDR %X3, Symbol - For the local-dynamic TLS
comment|/// model, produces a call to __tls_get_addr(sym\@tlsld).  Hidden by
comment|/// ADDIS_TLSLD_L_ADDR until after register assignment.
name|GET_TLSLD_ADDR
block|,
comment|/// G8RC = ADDI_TLSLD_L_ADDR G8RReg, Symbol, Symbol - Op that
comment|/// combines ADDI_TLSLD_L and GET_TLSLD_ADDR until expansion
comment|/// following register assignment.
name|ADDI_TLSLD_L_ADDR
block|,
comment|/// G8RC = ADDIS_DTPREL_HA %X3, Symbol - For the local-dynamic TLS
comment|/// model, produces an ADDIS8 instruction that adds X3 to
comment|/// sym\@dtprel\@ha.
name|ADDIS_DTPREL_HA
block|,
comment|/// G8RC = ADDI_DTPREL_L G8RReg, Symbol - For the local-dynamic TLS
comment|/// model, produces an ADDI8 instruction that adds G8RReg to
comment|/// sym\@got\@dtprel\@l.
name|ADDI_DTPREL_L
block|,
comment|/// VRRC = VADD_SPLAT Elt, EltSize - Temporary node to be expanded
comment|/// during instruction selection to optimize a BUILD_VECTOR into
comment|/// operations on splats.  This is necessary to avoid losing these
comment|/// optimizations due to constant folding.
name|VADD_SPLAT
block|,
comment|/// CHAIN = SC CHAIN, Imm128 - System call.  The 7-bit unsigned
comment|/// operand identifies the operating system entry point.
name|SC
block|,
comment|/// CHAIN = CLRBHRB CHAIN - Clear branch history rolling buffer.
name|CLRBHRB
block|,
comment|/// GPRC, CHAIN = MFBHRBE CHAIN, Entry, Dummy - Move from branch
comment|/// history rolling buffer entry.
name|MFBHRBE
block|,
comment|/// CHAIN = RFEBB CHAIN, State - Return from event-based branch.
name|RFEBB
block|,
comment|/// VSRC, CHAIN = XXSWAPD CHAIN, VSRC - Occurs only for little
comment|/// endian.  Maps to an xxswapd instruction that corrects an lxvd2x
comment|/// or stxvd2x instruction.  The chain is necessary because the
comment|/// sequence replaces a load and needs to provide the same number
comment|/// of outputs.
name|XXSWAPD
block|,
comment|/// An SDNode for swaps that are not associated with any loads/stores
comment|/// and thereby have no chain.
name|SWAP_NO_CHAIN
block|,
comment|/// QVFPERM = This corresponds to the QPX qvfperm instruction.
name|QVFPERM
block|,
comment|/// QVGPCI = This corresponds to the QPX qvgpci instruction.
name|QVGPCI
block|,
comment|/// QVALIGNI = This corresponds to the QPX qvaligni instruction.
name|QVALIGNI
block|,
comment|/// QVESPLATI = This corresponds to the QPX qvesplati instruction.
name|QVESPLATI
block|,
comment|/// QBFLT = Access the underlying QPX floating-point boolean
comment|/// representation.
name|QBFLT
block|,
comment|/// CHAIN = STBRX CHAIN, GPRC, Ptr, Type - This is a
comment|/// byte-swapping store instruction.  It byte-swaps the low "Type" bits of
comment|/// the GPRC input, then stores it through Ptr.  Type can be either i16 or
comment|/// i32.
name|STBRX
init|=
name|ISD
operator|::
name|FIRST_TARGET_MEMORY_OPCODE
block|,
comment|/// GPRC, CHAIN = LBRX CHAIN, Ptr, Type - This is a
comment|/// byte-swapping load instruction.  It loads "Type" bits, byte swaps it,
comment|/// then puts it in the bottom bits of the GPRC.  TYPE can be either i16
comment|/// or i32.
name|LBRX
block|,
comment|/// STFIWX - The STFIWX instruction.  The first operand is an input token
comment|/// chain, then an f64 value to store, then an address to store it to.
name|STFIWX
block|,
comment|/// GPRC, CHAIN = LFIWAX CHAIN, Ptr - This is a floating-point
comment|/// load which sign-extends from a 32-bit integer value into the
comment|/// destination 64-bit register.
name|LFIWAX
block|,
comment|/// GPRC, CHAIN = LFIWZX CHAIN, Ptr - This is a floating-point
comment|/// load which zero-extends from a 32-bit integer value into the
comment|/// destination 64-bit register.
name|LFIWZX
block|,
comment|/// GPRC, CHAIN = LXSIZX, CHAIN, Ptr, ByteWidth - This is a load of an
comment|/// integer smaller than 64 bits into a VSR. The integer is zero-extended.
comment|/// This can be used for converting loaded integers to floating point.
name|LXSIZX
block|,
comment|/// STXSIX - The STXSI[bh]X instruction. The first operand is an input
comment|/// chain, then an f64 value to store, then an address to store it to,
comment|/// followed by a byte-width for the store.
name|STXSIX
block|,
comment|/// VSRC, CHAIN = LXVD2X_LE CHAIN, Ptr - Occurs only for little endian.
comment|/// Maps directly to an lxvd2x instruction that will be followed by
comment|/// an xxswapd.
name|LXVD2X
block|,
comment|/// CHAIN = STXVD2X CHAIN, VSRC, Ptr - Occurs only for little endian.
comment|/// Maps directly to an stxvd2x instruction that will be preceded by
comment|/// an xxswapd.
name|STXVD2X
block|,
comment|/// QBRC, CHAIN = QVLFSb CHAIN, Ptr
comment|/// The 4xf32 load used for v4i1 constants.
name|QVLFSb
block|,
comment|/// GPRC = TOC_ENTRY GA, TOC
comment|/// Loads the entry for GA from the TOC, where the TOC base is given by
comment|/// the last operand.
name|TOC_ENTRY
block|}
enum|;
block|}
comment|// end namespace PPCISD
comment|/// Define some predicates that are used for node matching.
name|namespace
name|PPC
block|{
comment|/// isVPKUHUMShuffleMask - Return true if this is the shuffle mask for a
comment|/// VPKUHUM instruction.
name|bool
name|isVPKUHUMShuffleMask
parameter_list|(
name|ShuffleVectorSDNode
modifier|*
name|N
parameter_list|,
name|unsigned
name|ShuffleKind
parameter_list|,
name|SelectionDAG
modifier|&
name|DAG
parameter_list|)
function_decl|;
comment|/// isVPKUWUMShuffleMask - Return true if this is the shuffle mask for a
comment|/// VPKUWUM instruction.
name|bool
name|isVPKUWUMShuffleMask
parameter_list|(
name|ShuffleVectorSDNode
modifier|*
name|N
parameter_list|,
name|unsigned
name|ShuffleKind
parameter_list|,
name|SelectionDAG
modifier|&
name|DAG
parameter_list|)
function_decl|;
comment|/// isVPKUDUMShuffleMask - Return true if this is the shuffle mask for a
comment|/// VPKUDUM instruction.
name|bool
name|isVPKUDUMShuffleMask
parameter_list|(
name|ShuffleVectorSDNode
modifier|*
name|N
parameter_list|,
name|unsigned
name|ShuffleKind
parameter_list|,
name|SelectionDAG
modifier|&
name|DAG
parameter_list|)
function_decl|;
comment|/// isVMRGLShuffleMask - Return true if this is a shuffle mask suitable for
comment|/// a VRGL* instruction with the specified unit size (1,2 or 4 bytes).
name|bool
name|isVMRGLShuffleMask
parameter_list|(
name|ShuffleVectorSDNode
modifier|*
name|N
parameter_list|,
name|unsigned
name|UnitSize
parameter_list|,
name|unsigned
name|ShuffleKind
parameter_list|,
name|SelectionDAG
modifier|&
name|DAG
parameter_list|)
function_decl|;
comment|/// isVMRGHShuffleMask - Return true if this is a shuffle mask suitable for
comment|/// a VRGH* instruction with the specified unit size (1,2 or 4 bytes).
name|bool
name|isVMRGHShuffleMask
parameter_list|(
name|ShuffleVectorSDNode
modifier|*
name|N
parameter_list|,
name|unsigned
name|UnitSize
parameter_list|,
name|unsigned
name|ShuffleKind
parameter_list|,
name|SelectionDAG
modifier|&
name|DAG
parameter_list|)
function_decl|;
comment|/// isVMRGEOShuffleMask - Return true if this is a shuffle mask suitable for
comment|/// a VMRGEW or VMRGOW instruction
name|bool
name|isVMRGEOShuffleMask
parameter_list|(
name|ShuffleVectorSDNode
modifier|*
name|N
parameter_list|,
name|bool
name|CheckEven
parameter_list|,
name|unsigned
name|ShuffleKind
parameter_list|,
name|SelectionDAG
modifier|&
name|DAG
parameter_list|)
function_decl|;
comment|/// isXXSLDWIShuffleMask - Return true if this is a shuffle mask suitable
comment|/// for a XXSLDWI instruction.
name|bool
name|isXXSLDWIShuffleMask
parameter_list|(
name|ShuffleVectorSDNode
modifier|*
name|N
parameter_list|,
name|unsigned
modifier|&
name|ShiftElts
parameter_list|,
name|bool
modifier|&
name|Swap
parameter_list|,
name|bool
name|IsLE
parameter_list|)
function_decl|;
comment|/// isXXPERMDIShuffleMask - Return true if this is a shuffle mask suitable
comment|/// for a XXPERMDI instruction.
name|bool
name|isXXPERMDIShuffleMask
parameter_list|(
name|ShuffleVectorSDNode
modifier|*
name|N
parameter_list|,
name|unsigned
modifier|&
name|ShiftElts
parameter_list|,
name|bool
modifier|&
name|Swap
parameter_list|,
name|bool
name|IsLE
parameter_list|)
function_decl|;
comment|/// isVSLDOIShuffleMask - If this is a vsldoi shuffle mask, return the
comment|/// shift amount, otherwise return -1.
name|int
name|isVSLDOIShuffleMask
parameter_list|(
name|SDNode
modifier|*
name|N
parameter_list|,
name|unsigned
name|ShuffleKind
parameter_list|,
name|SelectionDAG
modifier|&
name|DAG
parameter_list|)
function_decl|;
comment|/// isSplatShuffleMask - Return true if the specified VECTOR_SHUFFLE operand
comment|/// specifies a splat of a single element that is suitable for input to
comment|/// VSPLTB/VSPLTH/VSPLTW.
name|bool
name|isSplatShuffleMask
parameter_list|(
name|ShuffleVectorSDNode
modifier|*
name|N
parameter_list|,
name|unsigned
name|EltSize
parameter_list|)
function_decl|;
comment|/// isXXINSERTWMask - Return true if this VECTOR_SHUFFLE can be handled by
comment|/// the XXINSERTW instruction introduced in ISA 3.0. This is essentially any
comment|/// shuffle of v4f32/v4i32 vectors that just inserts one element from one
comment|/// vector into the other. This function will also set a couple of
comment|/// output parameters for how much the source vector needs to be shifted and
comment|/// what byte number needs to be specified for the instruction to put the
comment|/// element in the desired location of the target vector.
name|bool
name|isXXINSERTWMask
parameter_list|(
name|ShuffleVectorSDNode
modifier|*
name|N
parameter_list|,
name|unsigned
modifier|&
name|ShiftElts
parameter_list|,
name|unsigned
modifier|&
name|InsertAtByte
parameter_list|,
name|bool
modifier|&
name|Swap
parameter_list|,
name|bool
name|IsLE
parameter_list|)
function_decl|;
comment|/// getVSPLTImmediate - Return the appropriate VSPLT* immediate to splat the
comment|/// specified isSplatShuffleMask VECTOR_SHUFFLE mask.
name|unsigned
name|getVSPLTImmediate
parameter_list|(
name|SDNode
modifier|*
name|N
parameter_list|,
name|unsigned
name|EltSize
parameter_list|,
name|SelectionDAG
modifier|&
name|DAG
parameter_list|)
function_decl|;
comment|/// get_VSPLTI_elt - If this is a build_vector of constants which can be
comment|/// formed by using a vspltis[bhw] instruction of the specified element
comment|/// size, return the constant being splatted.  The ByteSize field indicates
comment|/// the number of bytes of each element [124] -> [bhw].
name|SDValue
name|get_VSPLTI_elt
parameter_list|(
name|SDNode
modifier|*
name|N
parameter_list|,
name|unsigned
name|ByteSize
parameter_list|,
name|SelectionDAG
modifier|&
name|DAG
parameter_list|)
function_decl|;
comment|/// If this is a qvaligni shuffle mask, return the shift
comment|/// amount, otherwise return -1.
name|int
name|isQVALIGNIShuffleMask
parameter_list|(
name|SDNode
modifier|*
name|N
parameter_list|)
function_decl|;
block|}
comment|// end namespace PPC
name|class
name|PPCTargetLowering
range|:
name|public
name|TargetLowering
block|{
specifier|const
name|PPCSubtarget
operator|&
name|Subtarget
block|;
name|public
operator|:
name|explicit
name|PPCTargetLowering
argument_list|(
specifier|const
name|PPCTargetMachine
operator|&
name|TM
argument_list|,
specifier|const
name|PPCSubtarget
operator|&
name|STI
argument_list|)
block|;
comment|/// getTargetNodeName() - This method returns the name of a target specific
comment|/// DAG node.
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
comment|/// getPreferredVectorAction - The code we generate when vector types are
comment|/// legalized by promoting the integer element type is often much worse
comment|/// than code we generate if we widen the type for applicable vector types.
comment|/// The issue with promoting is that the vector is scalaraized, individual
comment|/// elements promoted and then the vector is rebuilt. So say we load a pair
comment|/// of v4i8's and shuffle them. This will turn into a mess of 8 extending
comment|/// loads, moves back into VSR's (or memory ops if we don't have moves) and
comment|/// then the VPERM for the shuffle. All in all a very slow sequence.
name|TargetLoweringBase
operator|::
name|LegalizeTypeAction
name|getPreferredVectorAction
argument_list|(
argument|EVT VT
argument_list|)
specifier|const
name|override
block|{
if|if
condition|(
name|VT
operator|.
name|getScalarSizeInBits
argument_list|()
operator|%
literal|8
operator|==
literal|0
condition|)
return|return
name|TypeWidenVector
return|;
return|return
name|TargetLoweringBase
operator|::
name|getPreferredVectorAction
argument_list|(
name|VT
argument_list|)
return|;
block|}
name|bool
name|useSoftFloat
argument_list|()
specifier|const
name|override
expr_stmt|;
name|MVT
name|getScalarShiftAmountTy
argument_list|(
specifier|const
name|DataLayout
operator|&
argument_list|,
name|EVT
argument_list|)
decl|const
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
block|{
return|return
name|true
return|;
block|}
name|bool
name|isCheapToSpeculateCtlz
argument_list|()
specifier|const
name|override
block|{
return|return
name|true
return|;
block|}
name|bool
name|isCtlzFast
argument_list|()
specifier|const
name|override
block|{
return|return
name|true
return|;
block|}
name|bool
name|hasAndNotCompare
argument_list|(
name|SDValue
argument_list|)
decl|const
name|override
block|{
return|return
name|true
return|;
block|}
name|bool
name|convertSetCCLogicToBitwiseLogic
argument_list|(
name|EVT
name|VT
argument_list|)
decl|const
name|override
block|{
return|return
name|VT
operator|.
name|isScalarInteger
argument_list|()
return|;
block|}
name|bool
name|supportSplitCSR
argument_list|(
name|MachineFunction
operator|*
name|MF
argument_list|)
decl|const
name|override
block|{
return|return
name|MF
operator|->
name|getFunction
argument_list|()
operator|->
name|getCallingConv
argument_list|()
operator|==
name|CallingConv
operator|::
name|CXX_FAST_TLS
operator|&&
name|MF
operator|->
name|getFunction
argument_list|()
operator|->
name|hasFnAttribute
argument_list|(
name|Attribute
operator|::
name|NoUnwind
argument_list|)
return|;
block|}
name|void
name|initializeSplitCSR
argument_list|(
name|MachineBasicBlock
operator|*
name|Entry
argument_list|)
decl|const
name|override
decl_stmt|;
name|void
name|insertCopiesSplitCSR
argument_list|(
name|MachineBasicBlock
operator|*
name|Entry
argument_list|,
specifier|const
name|SmallVectorImpl
operator|<
name|MachineBasicBlock
operator|*
operator|>
operator|&
name|Exits
argument_list|)
decl|const
name|override
decl_stmt|;
comment|/// getSetCCResultType - Return the ISD::SETCC ValueType
name|EVT
name|getSetCCResultType
argument_list|(
specifier|const
name|DataLayout
operator|&
name|DL
argument_list|,
name|LLVMContext
operator|&
name|Context
argument_list|,
name|EVT
name|VT
argument_list|)
decl|const
name|override
decl_stmt|;
comment|/// Return true if target always beneficiates from combining into FMA for a
comment|/// given value type. This must typically return false on targets where FMA
comment|/// takes more cycles to execute than FADD.
name|bool
name|enableAggressiveFMAFusion
argument_list|(
name|EVT
name|VT
argument_list|)
decl|const
name|override
decl_stmt|;
comment|/// getPreIndexedAddressParts - returns true by value, base pointer and
comment|/// offset pointer and addressing mode by reference if the node's address
comment|/// can be legally represented as pre-indexed load / store address.
name|bool
name|getPreIndexedAddressParts
argument_list|(
name|SDNode
operator|*
name|N
argument_list|,
name|SDValue
operator|&
name|Base
argument_list|,
name|SDValue
operator|&
name|Offset
argument_list|,
name|ISD
operator|::
name|MemIndexedMode
operator|&
name|AM
argument_list|,
name|SelectionDAG
operator|&
name|DAG
argument_list|)
decl|const
name|override
decl_stmt|;
comment|/// SelectAddressRegReg - Given the specified addressed, check to see if it
comment|/// can be represented as an indexed [r+r] operation.  Returns false if it
comment|/// can be more efficiently represented with [r+imm].
name|bool
name|SelectAddressRegReg
argument_list|(
name|SDValue
name|N
argument_list|,
name|SDValue
operator|&
name|Base
argument_list|,
name|SDValue
operator|&
name|Index
argument_list|,
name|SelectionDAG
operator|&
name|DAG
argument_list|)
decl|const
decl_stmt|;
comment|/// SelectAddressRegImm - Returns true if the address N can be represented
comment|/// by a base register plus a signed 16-bit displacement [r+imm], and if it
comment|/// is not better represented as reg+reg.  If Aligned is true, only accept
comment|/// displacements suitable for STD and friends, i.e. multiples of 4.
name|bool
name|SelectAddressRegImm
argument_list|(
name|SDValue
name|N
argument_list|,
name|SDValue
operator|&
name|Disp
argument_list|,
name|SDValue
operator|&
name|Base
argument_list|,
name|SelectionDAG
operator|&
name|DAG
argument_list|,
name|bool
name|Aligned
argument_list|)
decl|const
decl_stmt|;
comment|/// SelectAddressRegRegOnly - Given the specified addressed, force it to be
comment|/// represented as an indexed [r+r] operation.
name|bool
name|SelectAddressRegRegOnly
argument_list|(
name|SDValue
name|N
argument_list|,
name|SDValue
operator|&
name|Base
argument_list|,
name|SDValue
operator|&
name|Index
argument_list|,
name|SelectionDAG
operator|&
name|DAG
argument_list|)
decl|const
decl_stmt|;
name|Sched
operator|::
name|Preference
name|getSchedulingPreference
argument_list|(
argument|SDNode *N
argument_list|)
specifier|const
name|override
expr_stmt|;
comment|/// LowerOperation - Provide custom lowering hooks for some operations.
comment|///
name|SDValue
name|LowerOperation
argument_list|(
name|SDValue
name|Op
argument_list|,
name|SelectionDAG
operator|&
name|DAG
argument_list|)
decl|const
name|override
decl_stmt|;
comment|/// ReplaceNodeResults - Replace the results of node with an illegal result
comment|/// type with new values built out of custom code.
comment|///
name|void
name|ReplaceNodeResults
argument_list|(
name|SDNode
operator|*
name|N
argument_list|,
name|SmallVectorImpl
operator|<
name|SDValue
operator|>
operator|&
name|Results
argument_list|,
name|SelectionDAG
operator|&
name|DAG
argument_list|)
decl|const
name|override
decl_stmt|;
name|SDValue
name|expandVSXLoadForLE
argument_list|(
name|SDNode
operator|*
name|N
argument_list|,
name|DAGCombinerInfo
operator|&
name|DCI
argument_list|)
decl|const
decl_stmt|;
name|SDValue
name|expandVSXStoreForLE
argument_list|(
name|SDNode
operator|*
name|N
argument_list|,
name|DAGCombinerInfo
operator|&
name|DCI
argument_list|)
decl|const
decl_stmt|;
name|SDValue
name|PerformDAGCombine
argument_list|(
name|SDNode
operator|*
name|N
argument_list|,
name|DAGCombinerInfo
operator|&
name|DCI
argument_list|)
decl|const
name|override
decl_stmt|;
name|SDValue
name|BuildSDIVPow2
argument_list|(
name|SDNode
operator|*
name|N
argument_list|,
specifier|const
name|APInt
operator|&
name|Divisor
argument_list|,
name|SelectionDAG
operator|&
name|DAG
argument_list|,
name|std
operator|::
name|vector
operator|<
name|SDNode
operator|*
operator|>
operator|*
name|Created
argument_list|)
decl|const
name|override
decl_stmt|;
name|unsigned
name|getRegisterByName
argument_list|(
specifier|const
name|char
operator|*
name|RegName
argument_list|,
name|EVT
name|VT
argument_list|,
name|SelectionDAG
operator|&
name|DAG
argument_list|)
decl|const
name|override
decl_stmt|;
name|void
name|computeKnownBitsForTargetNode
argument_list|(
specifier|const
name|SDValue
name|Op
argument_list|,
name|KnownBits
operator|&
name|Known
argument_list|,
specifier|const
name|APInt
operator|&
name|DemandedElts
argument_list|,
specifier|const
name|SelectionDAG
operator|&
name|DAG
argument_list|,
name|unsigned
name|Depth
operator|=
literal|0
argument_list|)
decl|const
name|override
decl_stmt|;
name|unsigned
name|getPrefLoopAlignment
argument_list|(
name|MachineLoop
operator|*
name|ML
argument_list|)
decl|const
name|override
decl_stmt|;
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
name|Instruction
modifier|*
name|emitLeadingFence
argument_list|(
name|IRBuilder
operator|<
operator|>
operator|&
name|Builder
argument_list|,
name|Instruction
operator|*
name|Inst
argument_list|,
name|AtomicOrdering
name|Ord
argument_list|)
decl|const
name|override
decl_stmt|;
name|Instruction
modifier|*
name|emitTrailingFence
argument_list|(
name|IRBuilder
operator|<
operator|>
operator|&
name|Builder
argument_list|,
name|Instruction
operator|*
name|Inst
argument_list|,
name|AtomicOrdering
name|Ord
argument_list|)
decl|const
name|override
decl_stmt|;
name|MachineBasicBlock
modifier|*
name|EmitInstrWithCustomInserter
argument_list|(
name|MachineInstr
operator|&
name|MI
argument_list|,
name|MachineBasicBlock
operator|*
name|MBB
argument_list|)
decl|const
name|override
decl_stmt|;
name|MachineBasicBlock
modifier|*
name|EmitAtomicBinary
argument_list|(
name|MachineInstr
operator|&
name|MI
argument_list|,
name|MachineBasicBlock
operator|*
name|MBB
argument_list|,
name|unsigned
name|AtomicSize
argument_list|,
name|unsigned
name|BinOpcode
argument_list|,
name|unsigned
name|CmpOpcode
operator|=
literal|0
argument_list|,
name|unsigned
name|CmpPred
operator|=
literal|0
argument_list|)
decl|const
decl_stmt|;
name|MachineBasicBlock
modifier|*
name|EmitPartwordAtomicBinary
argument_list|(
name|MachineInstr
operator|&
name|MI
argument_list|,
name|MachineBasicBlock
operator|*
name|MBB
argument_list|,
name|bool
name|is8bit
argument_list|,
name|unsigned
name|Opcode
argument_list|,
name|unsigned
name|CmpOpcode
operator|=
literal|0
argument_list|,
name|unsigned
name|CmpPred
operator|=
literal|0
argument_list|)
decl|const
decl_stmt|;
name|MachineBasicBlock
modifier|*
name|emitEHSjLjSetJmp
argument_list|(
name|MachineInstr
operator|&
name|MI
argument_list|,
name|MachineBasicBlock
operator|*
name|MBB
argument_list|)
decl|const
decl_stmt|;
name|MachineBasicBlock
modifier|*
name|emitEHSjLjLongJmp
argument_list|(
name|MachineInstr
operator|&
name|MI
argument_list|,
name|MachineBasicBlock
operator|*
name|MBB
argument_list|)
decl|const
decl_stmt|;
name|ConstraintType
name|getConstraintType
argument_list|(
name|StringRef
name|Constraint
argument_list|)
decl|const
name|override
decl_stmt|;
comment|/// Examine constraint string and operand type and determine a weight value.
comment|/// The operand object must already have been set up with the operand type.
name|ConstraintWeight
name|getSingleConstraintMatchWeight
argument_list|(
name|AsmOperandInfo
operator|&
name|info
argument_list|,
specifier|const
name|char
operator|*
name|constraint
argument_list|)
decl|const
name|override
decl_stmt|;
name|std
operator|::
name|pair
operator|<
name|unsigned
operator|,
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
expr_stmt|;
comment|/// getByValTypeAlignment - Return the desired alignment for ByVal aggregate
comment|/// function arguments in the caller parameter area.  This is the actual
comment|/// alignment, not its logarithm.
name|unsigned
name|getByValTypeAlignment
argument_list|(
name|Type
operator|*
name|Ty
argument_list|,
specifier|const
name|DataLayout
operator|&
name|DL
argument_list|)
decl|const
name|override
decl_stmt|;
comment|/// LowerAsmOperandForConstraint - Lower the specified operand into the Ops
comment|/// vector.  If it is invalid, don't add anything to Ops.
name|void
name|LowerAsmOperandForConstraint
argument_list|(
name|SDValue
name|Op
argument_list|,
name|std
operator|::
name|string
operator|&
name|Constraint
argument_list|,
name|std
operator|::
name|vector
operator|<
name|SDValue
operator|>
operator|&
name|Ops
argument_list|,
name|SelectionDAG
operator|&
name|DAG
argument_list|)
decl|const
name|override
decl_stmt|;
name|unsigned
name|getInlineAsmMemConstraint
argument_list|(
name|StringRef
name|ConstraintCode
argument_list|)
decl|const
name|override
block|{
if|if
condition|(
name|ConstraintCode
operator|==
literal|"es"
condition|)
return|return
name|InlineAsm
operator|::
name|Constraint_es
return|;
elseif|else
if|if
condition|(
name|ConstraintCode
operator|==
literal|"o"
condition|)
return|return
name|InlineAsm
operator|::
name|Constraint_o
return|;
elseif|else
if|if
condition|(
name|ConstraintCode
operator|==
literal|"Q"
condition|)
return|return
name|InlineAsm
operator|::
name|Constraint_Q
return|;
elseif|else
if|if
condition|(
name|ConstraintCode
operator|==
literal|"Z"
condition|)
return|return
name|InlineAsm
operator|::
name|Constraint_Z
return|;
elseif|else
if|if
condition|(
name|ConstraintCode
operator|==
literal|"Zy"
condition|)
return|return
name|InlineAsm
operator|::
name|Constraint_Zy
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
comment|/// isLegalAddressingMode - Return true if the addressing mode represented
comment|/// by AM is legal for this target, for a load/store of the specified type.
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
comment|/// isLegalICmpImmediate - Return true if the specified immediate is legal
comment|/// icmp immediate, that is the target has icmp instructions which can
comment|/// compare a register against the immediate without having to materialize
comment|/// the immediate into a register.
name|bool
name|isLegalICmpImmediate
argument_list|(
name|int64_t
name|Imm
argument_list|)
decl|const
name|override
decl_stmt|;
comment|/// isLegalAddImmediate - Return true if the specified immediate is legal
comment|/// add immediate, that is the target has add instructions which can
comment|/// add a register and the immediate without having to materialize
comment|/// the immediate into a register.
name|bool
name|isLegalAddImmediate
argument_list|(
name|int64_t
name|Imm
argument_list|)
decl|const
name|override
decl_stmt|;
comment|/// isTruncateFree - Return true if it's free to truncate a value of
comment|/// type Ty1 to type Ty2. e.g. On PPC it's free to truncate a i64 value in
comment|/// register X1 to i32 by referencing its sub-register R1.
name|bool
name|isTruncateFree
argument_list|(
name|Type
operator|*
name|Ty1
argument_list|,
name|Type
operator|*
name|Ty2
argument_list|)
decl|const
name|override
decl_stmt|;
name|bool
name|isTruncateFree
argument_list|(
name|EVT
name|VT1
argument_list|,
name|EVT
name|VT2
argument_list|)
decl|const
name|override
decl_stmt|;
name|bool
name|isZExtFree
argument_list|(
name|SDValue
name|Val
argument_list|,
name|EVT
name|VT2
argument_list|)
decl|const
name|override
decl_stmt|;
name|bool
name|isFPExtFree
argument_list|(
name|EVT
name|VT
argument_list|)
decl|const
name|override
decl_stmt|;
comment|/// \brief Returns true if it is beneficial to convert a load of a constant
comment|/// to just the constant itself.
name|bool
name|shouldConvertConstantLoadToIntImm
argument_list|(
specifier|const
name|APInt
operator|&
name|Imm
argument_list|,
name|Type
operator|*
name|Ty
argument_list|)
decl|const
name|override
decl_stmt|;
name|bool
name|convertSelectOfConstantsToMath
argument_list|()
specifier|const
name|override
block|{
return|return
name|true
return|;
block|}
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
name|bool
name|getTgtMemIntrinsic
argument_list|(
name|IntrinsicInfo
operator|&
name|Info
argument_list|,
specifier|const
name|CallInst
operator|&
name|I
argument_list|,
name|unsigned
name|Intrinsic
argument_list|)
decl|const
name|override
decl_stmt|;
comment|/// getOptimalMemOpType - Returns the target specific optimal type for load
comment|/// and store operations as a result of memset, memcpy, and memmove
comment|/// lowering. If DstAlign is zero that means it's safe to destination
comment|/// alignment can satisfy any constraint. Similarly if SrcAlign is zero it
comment|/// means there isn't a need to check it against alignment requirement,
comment|/// probably because the source does not need to be loaded. If 'IsMemset' is
comment|/// true, that means it's expanding a memset. If 'ZeroMemset' is true, that
comment|/// means it's a memset of zero. 'MemcpyStrSrc' indicates whether the memcpy
comment|/// source is constant so it does not need to be loaded.
comment|/// It returns EVT::Other if the type should be determined using generic
comment|/// target-independent logic.
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
comment|/// Is unaligned memory access allowed for the given type, and is it fast
comment|/// relative to software emulation.
name|bool
name|allowsMisalignedMemoryAccesses
argument_list|(
name|EVT
name|VT
argument_list|,
name|unsigned
name|AddrSpace
argument_list|,
name|unsigned
name|Align
operator|=
literal|1
argument_list|,
name|bool
operator|*
name|Fast
operator|=
name|nullptr
argument_list|)
decl|const
name|override
decl_stmt|;
comment|/// isFMAFasterThanFMulAndFAdd - Return true if an FMA operation is faster
comment|/// than a pair of fmul and fadd instructions. fmuladd intrinsics will be
comment|/// expanded to FMAs when this method returns true, otherwise fmuladd is
comment|/// expanded to fmul + fadd.
name|bool
name|isFMAFasterThanFMulAndFAdd
argument_list|(
name|EVT
name|VT
argument_list|)
decl|const
name|override
decl_stmt|;
specifier|const
name|MCPhysReg
modifier|*
name|getScratchRegisters
argument_list|(
name|CallingConv
operator|::
name|ID
name|CC
argument_list|)
decl|const
name|override
decl_stmt|;
comment|// Should we expand the build vector with shuffles?
name|bool
name|shouldExpandBuildVectorWithShuffles
argument_list|(
name|EVT
name|VT
argument_list|,
name|unsigned
name|DefinedValues
argument_list|)
decl|const
name|override
decl_stmt|;
comment|/// createFastISel - This method returns a target-specific FastISel object,
comment|/// or null if the target does not support "fast" instruction selection.
name|FastISel
modifier|*
name|createFastISel
argument_list|(
name|FunctionLoweringInfo
operator|&
name|FuncInfo
argument_list|,
specifier|const
name|TargetLibraryInfo
operator|*
name|LibInfo
argument_list|)
decl|const
name|override
decl_stmt|;
comment|/// \brief Returns true if an argument of type Ty needs to be passed in a
comment|/// contiguous block of registers in calling convention CallConv.
name|bool
name|functionArgumentNeedsConsecutiveRegisters
argument_list|(
name|Type
operator|*
name|Ty
argument_list|,
name|CallingConv
operator|::
name|ID
name|CallConv
argument_list|,
name|bool
name|isVarArg
argument_list|)
decl|const
name|override
block|{
comment|// We support any array type as "consecutive" block in the parameter
comment|// save area.  The element type defines the alignment requirement and
comment|// whether the argument should go in GPRs, FPRs, or VRs if available.
comment|//
comment|// Note that clang uses this capability both to implement the ELFv2
comment|// homogeneous float/vector aggregate ABI, and to avoid having to use
comment|// "byval" when passing aggregates that might fully fit in registers.
return|return
name|Ty
operator|->
name|isArrayTy
argument_list|()
return|;
block|}
comment|/// If a physical register, this returns the register that receives the
comment|/// exception address on entry to an EH pad.
name|unsigned
name|getExceptionPointerRegister
argument_list|(
specifier|const
name|Constant
operator|*
name|PersonalityFn
argument_list|)
decl|const
name|override
decl_stmt|;
comment|/// If a physical register, this returns the register that receives the
comment|/// exception typeid on entry to a landing pad.
name|unsigned
name|getExceptionSelectorRegister
argument_list|(
specifier|const
name|Constant
operator|*
name|PersonalityFn
argument_list|)
decl|const
name|override
decl_stmt|;
comment|/// Override to support customized stack guard loading.
name|bool
name|useLoadStackGuardNode
argument_list|()
specifier|const
name|override
expr_stmt|;
name|void
name|insertSSPDeclarations
argument_list|(
name|Module
operator|&
name|M
argument_list|)
decl|const
name|override
decl_stmt|;
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
name|isJumpTableRelative
argument_list|()
specifier|const
name|override
expr_stmt|;
name|SDValue
name|getPICJumpTableRelocBase
argument_list|(
name|SDValue
name|Table
argument_list|,
name|SelectionDAG
operator|&
name|DAG
argument_list|)
decl|const
name|override
decl_stmt|;
specifier|const
name|MCExpr
modifier|*
name|getPICJumpTableRelocBaseExpr
argument_list|(
specifier|const
name|MachineFunction
operator|*
name|MF
argument_list|,
name|unsigned
name|JTI
argument_list|,
name|MCContext
operator|&
name|Ctx
argument_list|)
decl|const
name|override
decl_stmt|;
name|private
label|:
struct|struct
name|ReuseLoadInfo
block|{
name|SDValue
name|Ptr
decl_stmt|;
name|SDValue
name|Chain
decl_stmt|;
name|SDValue
name|ResChain
decl_stmt|;
name|MachinePointerInfo
name|MPI
decl_stmt|;
name|bool
name|IsDereferenceable
init|=
name|false
decl_stmt|;
name|bool
name|IsInvariant
init|=
name|false
decl_stmt|;
name|unsigned
name|Alignment
init|=
literal|0
decl_stmt|;
name|AAMDNodes
name|AAInfo
decl_stmt|;
specifier|const
name|MDNode
modifier|*
name|Ranges
init|=
name|nullptr
decl_stmt|;
name|ReuseLoadInfo
argument_list|()
operator|=
expr|default
expr_stmt|;
name|MachineMemOperand
operator|::
name|Flags
name|MMOFlags
argument_list|()
specifier|const
block|{
name|MachineMemOperand
operator|::
name|Flags
name|F
operator|=
name|MachineMemOperand
operator|::
name|MONone
block|;
if|if
condition|(
name|IsDereferenceable
condition|)
name|F
operator||=
name|MachineMemOperand
operator|::
name|MODereferenceable
expr_stmt|;
if|if
condition|(
name|IsInvariant
condition|)
name|F
operator||=
name|MachineMemOperand
operator|::
name|MOInvariant
expr_stmt|;
return|return
name|F
return|;
block|}
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_decl_stmt
name|bool
name|canReuseLoadAddress
argument_list|(
name|SDValue
name|Op
argument_list|,
name|EVT
name|MemVT
argument_list|,
name|ReuseLoadInfo
operator|&
name|RLI
argument_list|,
name|SelectionDAG
operator|&
name|DAG
argument_list|,
name|ISD
operator|::
name|LoadExtType
name|ET
operator|=
name|ISD
operator|::
name|NON_EXTLOAD
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|spliceIntoChain
argument_list|(
name|SDValue
name|ResChain
argument_list|,
name|SDValue
name|NewResChain
argument_list|,
name|SelectionDAG
operator|&
name|DAG
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|LowerFP_TO_INTForReuse
argument_list|(
name|SDValue
name|Op
argument_list|,
name|ReuseLoadInfo
operator|&
name|RLI
argument_list|,
name|SelectionDAG
operator|&
name|DAG
argument_list|,
specifier|const
name|SDLoc
operator|&
name|dl
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|SDValue
name|LowerFP_TO_INTDirectMove
argument_list|(
name|SDValue
name|Op
argument_list|,
name|SelectionDAG
operator|&
name|DAG
argument_list|,
specifier|const
name|SDLoc
operator|&
name|dl
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|bool
name|directMoveIsProfitable
argument_list|(
specifier|const
name|SDValue
operator|&
name|Op
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|SDValue
name|LowerINT_TO_FPDirectMove
argument_list|(
name|SDValue
name|Op
argument_list|,
name|SelectionDAG
operator|&
name|DAG
argument_list|,
specifier|const
name|SDLoc
operator|&
name|dl
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|SDValue
name|getFramePointerFrameIndex
argument_list|(
name|SelectionDAG
operator|&
name|DAG
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|SDValue
name|getReturnAddrFrameIndex
argument_list|(
name|SelectionDAG
operator|&
name|DAG
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|bool
name|IsEligibleForTailCallOptimization
argument_list|(
name|SDValue
name|Callee
argument_list|,
name|CallingConv
operator|::
name|ID
name|CalleeCC
argument_list|,
name|bool
name|isVarArg
argument_list|,
specifier|const
name|SmallVectorImpl
operator|<
name|ISD
operator|::
name|InputArg
operator|>
operator|&
name|Ins
argument_list|,
name|SelectionDAG
operator|&
name|DAG
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|bool
name|IsEligibleForTailCallOptimization_64SVR4
argument_list|(
name|SDValue
name|Callee
argument_list|,
name|CallingConv
operator|::
name|ID
name|CalleeCC
argument_list|,
name|ImmutableCallSite
operator|*
name|CS
argument_list|,
name|bool
name|isVarArg
argument_list|,
specifier|const
name|SmallVectorImpl
operator|<
name|ISD
operator|::
name|OutputArg
operator|>
operator|&
name|Outs
argument_list|,
specifier|const
name|SmallVectorImpl
operator|<
name|ISD
operator|::
name|InputArg
operator|>
operator|&
name|Ins
argument_list|,
name|SelectionDAG
operator|&
name|DAG
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|SDValue
name|EmitTailCallLoadFPAndRetAddr
argument_list|(
name|SelectionDAG
operator|&
name|DAG
argument_list|,
name|int
name|SPDiff
argument_list|,
name|SDValue
name|Chain
argument_list|,
name|SDValue
operator|&
name|LROpOut
argument_list|,
name|SDValue
operator|&
name|FPOpOut
argument_list|,
specifier|const
name|SDLoc
operator|&
name|dl
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|SDValue
name|LowerRETURNADDR
argument_list|(
name|SDValue
name|Op
argument_list|,
name|SelectionDAG
operator|&
name|DAG
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|SDValue
name|LowerFRAMEADDR
argument_list|(
name|SDValue
name|Op
argument_list|,
name|SelectionDAG
operator|&
name|DAG
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|SDValue
name|LowerConstantPool
argument_list|(
name|SDValue
name|Op
argument_list|,
name|SelectionDAG
operator|&
name|DAG
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|SDValue
name|LowerBlockAddress
argument_list|(
name|SDValue
name|Op
argument_list|,
name|SelectionDAG
operator|&
name|DAG
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|SDValue
name|LowerGlobalTLSAddress
argument_list|(
name|SDValue
name|Op
argument_list|,
name|SelectionDAG
operator|&
name|DAG
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|SDValue
name|LowerGlobalAddress
argument_list|(
name|SDValue
name|Op
argument_list|,
name|SelectionDAG
operator|&
name|DAG
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|SDValue
name|LowerJumpTable
argument_list|(
name|SDValue
name|Op
argument_list|,
name|SelectionDAG
operator|&
name|DAG
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|SDValue
name|LowerSETCC
argument_list|(
name|SDValue
name|Op
argument_list|,
name|SelectionDAG
operator|&
name|DAG
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|SDValue
name|LowerINIT_TRAMPOLINE
argument_list|(
name|SDValue
name|Op
argument_list|,
name|SelectionDAG
operator|&
name|DAG
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|SDValue
name|LowerADJUST_TRAMPOLINE
argument_list|(
name|SDValue
name|Op
argument_list|,
name|SelectionDAG
operator|&
name|DAG
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|SDValue
name|LowerVASTART
argument_list|(
name|SDValue
name|Op
argument_list|,
name|SelectionDAG
operator|&
name|DAG
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|SDValue
name|LowerVAARG
argument_list|(
name|SDValue
name|Op
argument_list|,
name|SelectionDAG
operator|&
name|DAG
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|SDValue
name|LowerVACOPY
argument_list|(
name|SDValue
name|Op
argument_list|,
name|SelectionDAG
operator|&
name|DAG
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|SDValue
name|LowerSTACKRESTORE
argument_list|(
name|SDValue
name|Op
argument_list|,
name|SelectionDAG
operator|&
name|DAG
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|SDValue
name|LowerGET_DYNAMIC_AREA_OFFSET
argument_list|(
name|SDValue
name|Op
argument_list|,
name|SelectionDAG
operator|&
name|DAG
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|SDValue
name|LowerDYNAMIC_STACKALLOC
argument_list|(
name|SDValue
name|Op
argument_list|,
name|SelectionDAG
operator|&
name|DAG
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|SDValue
name|LowerEH_DWARF_CFA
argument_list|(
name|SDValue
name|Op
argument_list|,
name|SelectionDAG
operator|&
name|DAG
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|SDValue
name|LowerLOAD
argument_list|(
name|SDValue
name|Op
argument_list|,
name|SelectionDAG
operator|&
name|DAG
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|SDValue
name|LowerSTORE
argument_list|(
name|SDValue
name|Op
argument_list|,
name|SelectionDAG
operator|&
name|DAG
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|SDValue
name|LowerTRUNCATE
argument_list|(
name|SDValue
name|Op
argument_list|,
name|SelectionDAG
operator|&
name|DAG
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|SDValue
name|LowerSELECT_CC
argument_list|(
name|SDValue
name|Op
argument_list|,
name|SelectionDAG
operator|&
name|DAG
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|SDValue
name|LowerFP_TO_INT
argument_list|(
name|SDValue
name|Op
argument_list|,
name|SelectionDAG
operator|&
name|DAG
argument_list|,
specifier|const
name|SDLoc
operator|&
name|dl
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|SDValue
name|LowerINT_TO_FP
argument_list|(
name|SDValue
name|Op
argument_list|,
name|SelectionDAG
operator|&
name|DAG
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|SDValue
name|LowerFLT_ROUNDS_
argument_list|(
name|SDValue
name|Op
argument_list|,
name|SelectionDAG
operator|&
name|DAG
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|SDValue
name|LowerSHL_PARTS
argument_list|(
name|SDValue
name|Op
argument_list|,
name|SelectionDAG
operator|&
name|DAG
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|SDValue
name|LowerSRL_PARTS
argument_list|(
name|SDValue
name|Op
argument_list|,
name|SelectionDAG
operator|&
name|DAG
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|SDValue
name|LowerSRA_PARTS
argument_list|(
name|SDValue
name|Op
argument_list|,
name|SelectionDAG
operator|&
name|DAG
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|SDValue
name|LowerBUILD_VECTOR
argument_list|(
name|SDValue
name|Op
argument_list|,
name|SelectionDAG
operator|&
name|DAG
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|SDValue
name|LowerVECTOR_SHUFFLE
argument_list|(
name|SDValue
name|Op
argument_list|,
name|SelectionDAG
operator|&
name|DAG
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|SDValue
name|LowerINSERT_VECTOR_ELT
argument_list|(
name|SDValue
name|Op
argument_list|,
name|SelectionDAG
operator|&
name|DAG
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|SDValue
name|LowerEXTRACT_VECTOR_ELT
argument_list|(
name|SDValue
name|Op
argument_list|,
name|SelectionDAG
operator|&
name|DAG
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|SDValue
name|LowerINTRINSIC_WO_CHAIN
argument_list|(
name|SDValue
name|Op
argument_list|,
name|SelectionDAG
operator|&
name|DAG
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|SDValue
name|LowerINTRINSIC_VOID
argument_list|(
name|SDValue
name|Op
argument_list|,
name|SelectionDAG
operator|&
name|DAG
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|SDValue
name|LowerSCALAR_TO_VECTOR
argument_list|(
name|SDValue
name|Op
argument_list|,
name|SelectionDAG
operator|&
name|DAG
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|SDValue
name|LowerSIGN_EXTEND_INREG
argument_list|(
name|SDValue
name|Op
argument_list|,
name|SelectionDAG
operator|&
name|DAG
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|SDValue
name|LowerMUL
argument_list|(
name|SDValue
name|Op
argument_list|,
name|SelectionDAG
operator|&
name|DAG
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|SDValue
name|LowerVectorLoad
argument_list|(
name|SDValue
name|Op
argument_list|,
name|SelectionDAG
operator|&
name|DAG
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|SDValue
name|LowerVectorStore
argument_list|(
name|SDValue
name|Op
argument_list|,
name|SelectionDAG
operator|&
name|DAG
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|SDValue
name|LowerCallResult
argument_list|(
name|SDValue
name|Chain
argument_list|,
name|SDValue
name|InFlag
argument_list|,
name|CallingConv
operator|::
name|ID
name|CallConv
argument_list|,
name|bool
name|isVarArg
argument_list|,
specifier|const
name|SmallVectorImpl
operator|<
name|ISD
operator|::
name|InputArg
operator|>
operator|&
name|Ins
argument_list|,
specifier|const
name|SDLoc
operator|&
name|dl
argument_list|,
name|SelectionDAG
operator|&
name|DAG
argument_list|,
name|SmallVectorImpl
operator|<
name|SDValue
operator|>
operator|&
name|InVals
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|SDValue
name|FinishCall
argument_list|(
name|CallingConv
operator|::
name|ID
name|CallConv
argument_list|,
specifier|const
name|SDLoc
operator|&
name|dl
argument_list|,
name|bool
name|isTailCall
argument_list|,
name|bool
name|isVarArg
argument_list|,
name|bool
name|isPatchPoint
argument_list|,
name|bool
name|hasNest
argument_list|,
name|SelectionDAG
operator|&
name|DAG
argument_list|,
name|SmallVector
operator|<
name|std
operator|::
name|pair
operator|<
name|unsigned
argument_list|,
name|SDValue
operator|>
argument_list|,
literal|8
operator|>
operator|&
name|RegsToPass
argument_list|,
name|SDValue
name|InFlag
argument_list|,
name|SDValue
name|Chain
argument_list|,
name|SDValue
name|CallSeqStart
argument_list|,
name|SDValue
operator|&
name|Callee
argument_list|,
name|int
name|SPDiff
argument_list|,
name|unsigned
name|NumBytes
argument_list|,
specifier|const
name|SmallVectorImpl
operator|<
name|ISD
operator|::
name|InputArg
operator|>
operator|&
name|Ins
argument_list|,
name|SmallVectorImpl
operator|<
name|SDValue
operator|>
operator|&
name|InVals
argument_list|,
name|ImmutableCallSite
operator|*
name|CS
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|SDValue
name|LowerFormalArguments
argument_list|(
name|SDValue
name|Chain
argument_list|,
name|CallingConv
operator|::
name|ID
name|CallConv
argument_list|,
name|bool
name|isVarArg
argument_list|,
specifier|const
name|SmallVectorImpl
operator|<
name|ISD
operator|::
name|InputArg
operator|>
operator|&
name|Ins
argument_list|,
specifier|const
name|SDLoc
operator|&
name|dl
argument_list|,
name|SelectionDAG
operator|&
name|DAG
argument_list|,
name|SmallVectorImpl
operator|<
name|SDValue
operator|>
operator|&
name|InVals
argument_list|)
decl|const
name|override
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|SDValue
name|LowerCall
argument_list|(
name|TargetLowering
operator|::
name|CallLoweringInfo
operator|&
name|CLI
argument_list|,
name|SmallVectorImpl
operator|<
name|SDValue
operator|>
operator|&
name|InVals
argument_list|)
decl|const
name|override
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|bool
name|CanLowerReturn
argument_list|(
name|CallingConv
operator|::
name|ID
name|CallConv
argument_list|,
name|MachineFunction
operator|&
name|MF
argument_list|,
name|bool
name|isVarArg
argument_list|,
specifier|const
name|SmallVectorImpl
operator|<
name|ISD
operator|::
name|OutputArg
operator|>
operator|&
name|Outs
argument_list|,
name|LLVMContext
operator|&
name|Context
argument_list|)
decl|const
name|override
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|SDValue
name|LowerReturn
argument_list|(
name|SDValue
name|Chain
argument_list|,
name|CallingConv
operator|::
name|ID
name|CallConv
argument_list|,
name|bool
name|isVarArg
argument_list|,
specifier|const
name|SmallVectorImpl
operator|<
name|ISD
operator|::
name|OutputArg
operator|>
operator|&
name|Outs
argument_list|,
specifier|const
name|SmallVectorImpl
operator|<
name|SDValue
operator|>
operator|&
name|OutVals
argument_list|,
specifier|const
name|SDLoc
operator|&
name|dl
argument_list|,
name|SelectionDAG
operator|&
name|DAG
argument_list|)
decl|const
name|override
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|SDValue
name|extendArgForPPC64
argument_list|(
name|ISD
operator|::
name|ArgFlagsTy
name|Flags
argument_list|,
name|EVT
name|ObjectVT
argument_list|,
name|SelectionDAG
operator|&
name|DAG
argument_list|,
name|SDValue
name|ArgVal
argument_list|,
specifier|const
name|SDLoc
operator|&
name|dl
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|SDValue
name|LowerFormalArguments_Darwin
argument_list|(
name|SDValue
name|Chain
argument_list|,
name|CallingConv
operator|::
name|ID
name|CallConv
argument_list|,
name|bool
name|isVarArg
argument_list|,
specifier|const
name|SmallVectorImpl
operator|<
name|ISD
operator|::
name|InputArg
operator|>
operator|&
name|Ins
argument_list|,
specifier|const
name|SDLoc
operator|&
name|dl
argument_list|,
name|SelectionDAG
operator|&
name|DAG
argument_list|,
name|SmallVectorImpl
operator|<
name|SDValue
operator|>
operator|&
name|InVals
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|SDValue
name|LowerFormalArguments_64SVR4
argument_list|(
name|SDValue
name|Chain
argument_list|,
name|CallingConv
operator|::
name|ID
name|CallConv
argument_list|,
name|bool
name|isVarArg
argument_list|,
specifier|const
name|SmallVectorImpl
operator|<
name|ISD
operator|::
name|InputArg
operator|>
operator|&
name|Ins
argument_list|,
specifier|const
name|SDLoc
operator|&
name|dl
argument_list|,
name|SelectionDAG
operator|&
name|DAG
argument_list|,
name|SmallVectorImpl
operator|<
name|SDValue
operator|>
operator|&
name|InVals
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|SDValue
name|LowerFormalArguments_32SVR4
argument_list|(
name|SDValue
name|Chain
argument_list|,
name|CallingConv
operator|::
name|ID
name|CallConv
argument_list|,
name|bool
name|isVarArg
argument_list|,
specifier|const
name|SmallVectorImpl
operator|<
name|ISD
operator|::
name|InputArg
operator|>
operator|&
name|Ins
argument_list|,
specifier|const
name|SDLoc
operator|&
name|dl
argument_list|,
name|SelectionDAG
operator|&
name|DAG
argument_list|,
name|SmallVectorImpl
operator|<
name|SDValue
operator|>
operator|&
name|InVals
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|SDValue
name|createMemcpyOutsideCallSeq
argument_list|(
name|SDValue
name|Arg
argument_list|,
name|SDValue
name|PtrOff
argument_list|,
name|SDValue
name|CallSeqStart
argument_list|,
name|ISD
operator|::
name|ArgFlagsTy
name|Flags
argument_list|,
name|SelectionDAG
operator|&
name|DAG
argument_list|,
specifier|const
name|SDLoc
operator|&
name|dl
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|SDValue
name|LowerCall_Darwin
argument_list|(
name|SDValue
name|Chain
argument_list|,
name|SDValue
name|Callee
argument_list|,
name|CallingConv
operator|::
name|ID
name|CallConv
argument_list|,
name|bool
name|isVarArg
argument_list|,
name|bool
name|isTailCall
argument_list|,
name|bool
name|isPatchPoint
argument_list|,
specifier|const
name|SmallVectorImpl
operator|<
name|ISD
operator|::
name|OutputArg
operator|>
operator|&
name|Outs
argument_list|,
specifier|const
name|SmallVectorImpl
operator|<
name|SDValue
operator|>
operator|&
name|OutVals
argument_list|,
specifier|const
name|SmallVectorImpl
operator|<
name|ISD
operator|::
name|InputArg
operator|>
operator|&
name|Ins
argument_list|,
specifier|const
name|SDLoc
operator|&
name|dl
argument_list|,
name|SelectionDAG
operator|&
name|DAG
argument_list|,
name|SmallVectorImpl
operator|<
name|SDValue
operator|>
operator|&
name|InVals
argument_list|,
name|ImmutableCallSite
operator|*
name|CS
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|SDValue
name|LowerCall_64SVR4
argument_list|(
name|SDValue
name|Chain
argument_list|,
name|SDValue
name|Callee
argument_list|,
name|CallingConv
operator|::
name|ID
name|CallConv
argument_list|,
name|bool
name|isVarArg
argument_list|,
name|bool
name|isTailCall
argument_list|,
name|bool
name|isPatchPoint
argument_list|,
specifier|const
name|SmallVectorImpl
operator|<
name|ISD
operator|::
name|OutputArg
operator|>
operator|&
name|Outs
argument_list|,
specifier|const
name|SmallVectorImpl
operator|<
name|SDValue
operator|>
operator|&
name|OutVals
argument_list|,
specifier|const
name|SmallVectorImpl
operator|<
name|ISD
operator|::
name|InputArg
operator|>
operator|&
name|Ins
argument_list|,
specifier|const
name|SDLoc
operator|&
name|dl
argument_list|,
name|SelectionDAG
operator|&
name|DAG
argument_list|,
name|SmallVectorImpl
operator|<
name|SDValue
operator|>
operator|&
name|InVals
argument_list|,
name|ImmutableCallSite
operator|*
name|CS
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|SDValue
name|LowerCall_32SVR4
argument_list|(
name|SDValue
name|Chain
argument_list|,
name|SDValue
name|Callee
argument_list|,
name|CallingConv
operator|::
name|ID
name|CallConv
argument_list|,
name|bool
name|isVarArg
argument_list|,
name|bool
name|isTailCall
argument_list|,
name|bool
name|isPatchPoint
argument_list|,
specifier|const
name|SmallVectorImpl
operator|<
name|ISD
operator|::
name|OutputArg
operator|>
operator|&
name|Outs
argument_list|,
specifier|const
name|SmallVectorImpl
operator|<
name|SDValue
operator|>
operator|&
name|OutVals
argument_list|,
specifier|const
name|SmallVectorImpl
operator|<
name|ISD
operator|::
name|InputArg
operator|>
operator|&
name|Ins
argument_list|,
specifier|const
name|SDLoc
operator|&
name|dl
argument_list|,
name|SelectionDAG
operator|&
name|DAG
argument_list|,
name|SmallVectorImpl
operator|<
name|SDValue
operator|>
operator|&
name|InVals
argument_list|,
name|ImmutableCallSite
operator|*
name|CS
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|SDValue
name|lowerEH_SJLJ_SETJMP
argument_list|(
name|SDValue
name|Op
argument_list|,
name|SelectionDAG
operator|&
name|DAG
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|SDValue
name|lowerEH_SJLJ_LONGJMP
argument_list|(
name|SDValue
name|Op
argument_list|,
name|SelectionDAG
operator|&
name|DAG
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|SDValue
name|DAGCombineExtBoolTrunc
argument_list|(
name|SDNode
operator|*
name|N
argument_list|,
name|DAGCombinerInfo
operator|&
name|DCI
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|SDValue
name|DAGCombineBuildVector
argument_list|(
name|SDNode
operator|*
name|N
argument_list|,
name|DAGCombinerInfo
operator|&
name|DCI
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|SDValue
name|DAGCombineTruncBoolExt
argument_list|(
name|SDNode
operator|*
name|N
argument_list|,
name|DAGCombinerInfo
operator|&
name|DCI
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|SDValue
name|combineFPToIntToFP
argument_list|(
name|SDNode
operator|*
name|N
argument_list|,
name|DAGCombinerInfo
operator|&
name|DCI
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|SDValue
name|combineSHL
argument_list|(
name|SDNode
operator|*
name|N
argument_list|,
name|DAGCombinerInfo
operator|&
name|DCI
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|SDValue
name|combineSRA
argument_list|(
name|SDNode
operator|*
name|N
argument_list|,
name|DAGCombinerInfo
operator|&
name|DCI
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|SDValue
name|combineSRL
argument_list|(
name|SDNode
operator|*
name|N
argument_list|,
name|DAGCombinerInfo
operator|&
name|DCI
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// ConvertSETCCToSubtract - looks at SETCC that compares ints. It replaces
end_comment

begin_comment
comment|/// SETCC with integer subtraction when (1) there is a legal way of doing it
end_comment

begin_comment
comment|/// (2) keeping the result of comparison in GPR has performance benefit.
end_comment

begin_decl_stmt
name|SDValue
name|ConvertSETCCToSubtract
argument_list|(
name|SDNode
operator|*
name|N
argument_list|,
name|DAGCombinerInfo
operator|&
name|DCI
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|SDValue
name|getSqrtEstimate
argument_list|(
name|SDValue
name|Operand
argument_list|,
name|SelectionDAG
operator|&
name|DAG
argument_list|,
name|int
name|Enabled
argument_list|,
name|int
operator|&
name|RefinementSteps
argument_list|,
name|bool
operator|&
name|UseOneConstNR
argument_list|,
name|bool
name|Reciprocal
argument_list|)
decl|const
name|override
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|SDValue
name|getRecipEstimate
argument_list|(
name|SDValue
name|Operand
argument_list|,
name|SelectionDAG
operator|&
name|DAG
argument_list|,
name|int
name|Enabled
argument_list|,
name|int
operator|&
name|RefinementSteps
argument_list|)
decl|const
name|override
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|unsigned
name|combineRepeatedFPDivisors
argument_list|()
specifier|const
name|override
expr_stmt|;
end_expr_stmt

begin_decl_stmt
name|CCAssignFn
modifier|*
name|useFastISelCCs
argument_list|(
name|unsigned
name|Flag
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|SDValue
name|combineElementTruncationToVectorTruncation
argument_list|(
name|SDNode
operator|*
name|N
argument_list|,
name|DAGCombinerInfo
operator|&
name|DCI
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_decl_stmt
unit|};
name|namespace
name|PPC
block|{
name|FastISel
modifier|*
name|createFastISel
parameter_list|(
name|FunctionLoweringInfo
modifier|&
name|FuncInfo
parameter_list|,
specifier|const
name|TargetLibraryInfo
modifier|*
name|LibInfo
parameter_list|)
function_decl|;
block|}
end_decl_stmt

begin_comment
comment|// end namespace PPC
end_comment

begin_decl_stmt
name|bool
name|CC_PPC32_SVR4_Custom_Dummy
argument_list|(
name|unsigned
operator|&
name|ValNo
argument_list|,
name|MVT
operator|&
name|ValVT
argument_list|,
name|MVT
operator|&
name|LocVT
argument_list|,
name|CCValAssign
operator|::
name|LocInfo
operator|&
name|LocInfo
argument_list|,
name|ISD
operator|::
name|ArgFlagsTy
operator|&
name|ArgFlags
argument_list|,
name|CCState
operator|&
name|State
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|bool
name|CC_PPC32_SVR4_Custom_AlignArgRegs
argument_list|(
name|unsigned
operator|&
name|ValNo
argument_list|,
name|MVT
operator|&
name|ValVT
argument_list|,
name|MVT
operator|&
name|LocVT
argument_list|,
name|CCValAssign
operator|::
name|LocInfo
operator|&
name|LocInfo
argument_list|,
name|ISD
operator|::
name|ArgFlagsTy
operator|&
name|ArgFlags
argument_list|,
name|CCState
operator|&
name|State
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|bool
name|CC_PPC32_SVR4_Custom_SkipLastArgRegsPPCF128
argument_list|(
name|unsigned
operator|&
name|ValNo
argument_list|,
name|MVT
operator|&
name|ValVT
argument_list|,
name|MVT
operator|&
name|LocVT
argument_list|,
name|CCValAssign
operator|::
name|LocInfo
operator|&
name|LocInfo
argument_list|,
name|ISD
operator|::
name|ArgFlagsTy
operator|&
name|ArgFlags
argument_list|,
name|CCState
operator|&
name|State
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|bool
name|CC_PPC32_SVR4_Custom_AlignFPArgRegs
argument_list|(
name|unsigned
operator|&
name|ValNo
argument_list|,
name|MVT
operator|&
name|ValVT
argument_list|,
name|MVT
operator|&
name|LocVT
argument_list|,
name|CCValAssign
operator|::
name|LocInfo
operator|&
name|LocInfo
argument_list|,
name|ISD
operator|::
name|ArgFlagsTy
operator|&
name|ArgFlags
argument_list|,
name|CCState
operator|&
name|State
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
unit|}
comment|// end namespace llvm
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// LLVM_TARGET_POWERPC_PPC32ISELLOWERING_H
end_comment

end_unit

