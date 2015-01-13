begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- X86ISelLowering.h - X86 DAG Lowering Interface ----------*- C++ -*-===//
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
comment|// This file defines the interfaces that X86 uses to lower LLVM code into a
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
name|X86ISELLOWERING_H
end_ifndef

begin_define
define|#
directive|define
name|X86ISELLOWERING_H
end_define

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
file|"llvm/Target/TargetLowering.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Target/TargetOptions.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|X86Subtarget
decl_stmt|;
name|class
name|X86TargetMachine
decl_stmt|;
name|namespace
name|X86ISD
block|{
comment|// X86 Specific DAG Nodes
enum|enum
name|NodeType
block|{
comment|// Start the numbering where the builtin ops leave off.
name|FIRST_NUMBER
init|=
name|ISD
operator|::
name|BUILTIN_OP_END
block|,
comment|/// BSF - Bit scan forward.
comment|/// BSR - Bit scan reverse.
name|BSF
block|,
name|BSR
block|,
comment|/// SHLD, SHRD - Double shift instructions. These correspond to
comment|/// X86::SHLDxx and X86::SHRDxx instructions.
name|SHLD
block|,
name|SHRD
block|,
comment|/// FAND - Bitwise logical AND of floating point values. This corresponds
comment|/// to X86::ANDPS or X86::ANDPD.
name|FAND
block|,
comment|/// FOR - Bitwise logical OR of floating point values. This corresponds
comment|/// to X86::ORPS or X86::ORPD.
name|FOR
block|,
comment|/// FXOR - Bitwise logical XOR of floating point values. This corresponds
comment|/// to X86::XORPS or X86::XORPD.
name|FXOR
block|,
comment|/// FANDN - Bitwise logical ANDNOT of floating point values. This
comment|/// corresponds to X86::ANDNPS or X86::ANDNPD.
name|FANDN
block|,
comment|/// FSRL - Bitwise logical right shift of floating point values. These
comment|/// corresponds to X86::PSRLDQ.
name|FSRL
block|,
comment|/// CALL - These operations represent an abstract X86 call
comment|/// instruction, which includes a bunch of information.  In particular the
comment|/// operands of these node are:
comment|///
comment|///     #0 - The incoming token chain
comment|///     #1 - The callee
comment|///     #2 - The number of arg bytes the caller pushes on the stack.
comment|///     #3 - The number of arg bytes the callee pops off the stack.
comment|///     #4 - The value to pass in AL/AX/EAX (optional)
comment|///     #5 - The value to pass in DL/DX/EDX (optional)
comment|///
comment|/// The result values of these nodes are:
comment|///
comment|///     #0 - The outgoing token chain
comment|///     #1 - The first register result value (optional)
comment|///     #2 - The second register result value (optional)
comment|///
name|CALL
block|,
comment|/// RDTSC_DAG - This operation implements the lowering for
comment|/// readcyclecounter
name|RDTSC_DAG
block|,
comment|/// X86 Read Time-Stamp Counter and Processor ID.
name|RDTSCP_DAG
block|,
comment|/// X86 Read Performance Monitoring Counters.
name|RDPMC_DAG
block|,
comment|/// X86 compare and logical compare instructions.
name|CMP
block|,
name|COMI
block|,
name|UCOMI
block|,
comment|/// X86 bit-test instructions.
name|BT
block|,
comment|/// X86 SetCC. Operand 0 is condition code, and operand 1 is the EFLAGS
comment|/// operand, usually produced by a CMP instruction.
name|SETCC
block|,
comment|/// X86 Select
name|SELECT
block|,
comment|// Same as SETCC except it's materialized with a sbb and the value is all
comment|// one's or all zero's.
name|SETCC_CARRY
block|,
comment|// R = carry_bit ? ~0 : 0
comment|/// X86 FP SETCC, implemented with CMP{cc}SS/CMP{cc}SD.
comment|/// Operands are two FP values to compare; result is a mask of
comment|/// 0s or 1s.  Generally DTRT for C/C++ with NaNs.
name|FSETCC
block|,
comment|/// X86 MOVMSK{pd|ps}, extracts sign bits of two or four FP values,
comment|/// result in an integer GPR.  Needs masking for scalar result.
name|FGETSIGNx86
block|,
comment|/// X86 conditional moves. Operand 0 and operand 1 are the two values
comment|/// to select from. Operand 2 is the condition code, and operand 3 is the
comment|/// flag operand produced by a CMP or TEST instruction. It also writes a
comment|/// flag result.
name|CMOV
block|,
comment|/// X86 conditional branches. Operand 0 is the chain operand, operand 1
comment|/// is the block to branch if condition is true, operand 2 is the
comment|/// condition code, and operand 3 is the flag operand produced by a CMP
comment|/// or TEST instruction.
name|BRCOND
block|,
comment|/// Return with a flag operand. Operand 0 is the chain operand, operand
comment|/// 1 is the number of bytes of stack to pop.
name|RET_FLAG
block|,
comment|/// REP_STOS - Repeat fill, corresponds to X86::REP_STOSx.
name|REP_STOS
block|,
comment|/// REP_MOVS - Repeat move, corresponds to X86::REP_MOVSx.
name|REP_MOVS
block|,
comment|/// GlobalBaseReg - On Darwin, this node represents the result of the popl
comment|/// at function entry, used for PIC code.
name|GlobalBaseReg
block|,
comment|/// Wrapper - A wrapper node for TargetConstantPool,
comment|/// TargetExternalSymbol, and TargetGlobalAddress.
name|Wrapper
block|,
comment|/// WrapperRIP - Special wrapper used under X86-64 PIC mode for RIP
comment|/// relative displacements.
name|WrapperRIP
block|,
comment|/// MOVDQ2Q - Copies a 64-bit value from the low word of an XMM vector
comment|/// to an MMX vector.  If you think this is too close to the previous
comment|/// mnemonic, so do I; blame Intel.
name|MOVDQ2Q
block|,
comment|/// MMX_MOVD2W - Copies a 32-bit value from the low word of a MMX
comment|/// vector to a GPR.
name|MMX_MOVD2W
block|,
comment|/// PEXTRB - Extract an 8-bit value from a vector and zero extend it to
comment|/// i32, corresponds to X86::PEXTRB.
name|PEXTRB
block|,
comment|/// PEXTRW - Extract a 16-bit value from a vector and zero extend it to
comment|/// i32, corresponds to X86::PEXTRW.
name|PEXTRW
block|,
comment|/// INSERTPS - Insert any element of a 4 x float vector into any element
comment|/// of a destination 4 x floatvector.
name|INSERTPS
block|,
comment|/// PINSRB - Insert the lower 8-bits of a 32-bit value to a vector,
comment|/// corresponds to X86::PINSRB.
name|PINSRB
block|,
comment|/// PINSRW - Insert the lower 16-bits of a 32-bit value to a vector,
comment|/// corresponds to X86::PINSRW.
name|PINSRW
block|,
name|MMX_PINSRW
block|,
comment|/// PSHUFB - Shuffle 16 8-bit values within a vector.
name|PSHUFB
block|,
comment|/// ANDNP - Bitwise Logical AND NOT of Packed FP values.
name|ANDNP
block|,
comment|/// PSIGN - Copy integer sign.
name|PSIGN
block|,
comment|/// BLENDV - Blend where the selector is a register.
name|BLENDV
block|,
comment|/// BLENDI - Blend where the selector is an immediate.
name|BLENDI
block|,
comment|// SUBUS - Integer sub with unsigned saturation.
name|SUBUS
block|,
comment|/// HADD - Integer horizontal add.
name|HADD
block|,
comment|/// HSUB - Integer horizontal sub.
name|HSUB
block|,
comment|/// FHADD - Floating point horizontal add.
name|FHADD
block|,
comment|/// FHSUB - Floating point horizontal sub.
name|FHSUB
block|,
comment|/// UMAX, UMIN - Unsigned integer max and min.
name|UMAX
block|,
name|UMIN
block|,
comment|/// SMAX, SMIN - Signed integer max and min.
name|SMAX
block|,
name|SMIN
block|,
comment|/// FMAX, FMIN - Floating point max and min.
comment|///
name|FMAX
block|,
name|FMIN
block|,
comment|/// FMAXC, FMINC - Commutative FMIN and FMAX.
name|FMAXC
block|,
name|FMINC
block|,
comment|/// FRSQRT, FRCP - Floating point reciprocal-sqrt and reciprocal
comment|/// approximation.  Note that these typically require refinement
comment|/// in order to obtain suitable precision.
name|FRSQRT
block|,
name|FRCP
block|,
comment|// TLSADDR - Thread Local Storage.
name|TLSADDR
block|,
comment|// TLSBASEADDR - Thread Local Storage. A call to get the start address
comment|// of the TLS block for the current module.
name|TLSBASEADDR
block|,
comment|// TLSCALL - Thread Local Storage.  When calling to an OS provided
comment|// thunk at the address from an earlier relocation.
name|TLSCALL
block|,
comment|// EH_RETURN - Exception Handling helpers.
name|EH_RETURN
block|,
comment|// EH_SJLJ_SETJMP - SjLj exception handling setjmp.
name|EH_SJLJ_SETJMP
block|,
comment|// EH_SJLJ_LONGJMP - SjLj exception handling longjmp.
name|EH_SJLJ_LONGJMP
block|,
comment|/// TC_RETURN - Tail call return. See X86TargetLowering::LowerCall for
comment|/// the list of operands.
name|TC_RETURN
block|,
comment|// VZEXT_MOVL - Vector move to low scalar and zero higher vector elements.
name|VZEXT_MOVL
block|,
comment|// VZEXT - Vector integer zero-extend.
name|VZEXT
block|,
comment|// VSEXT - Vector integer signed-extend.
name|VSEXT
block|,
comment|// VTRUNC - Vector integer truncate.
name|VTRUNC
block|,
comment|// VTRUNC - Vector integer truncate with mask.
name|VTRUNCM
block|,
comment|// VFPEXT - Vector FP extend.
name|VFPEXT
block|,
comment|// VFPROUND - Vector FP round.
name|VFPROUND
block|,
comment|// VSHL, VSRL - 128-bit vector logical left / right shift
name|VSHLDQ
block|,
name|VSRLDQ
block|,
comment|// VSHL, VSRL, VSRA - Vector shift elements
name|VSHL
block|,
name|VSRL
block|,
name|VSRA
block|,
comment|// VSHLI, VSRLI, VSRAI - Vector shift elements by immediate
name|VSHLI
block|,
name|VSRLI
block|,
name|VSRAI
block|,
comment|// CMPP - Vector packed double/float comparison.
name|CMPP
block|,
comment|// PCMP* - Vector integer comparisons.
name|PCMPEQ
block|,
name|PCMPGT
block|,
comment|// PCMP*M - Vector integer comparisons, the result is in a mask vector.
name|PCMPEQM
block|,
name|PCMPGTM
block|,
comment|/// CMPM, CMPMU - Vector comparison generating mask bits for fp and
comment|/// integer signed and unsigned data types.
name|CMPM
block|,
name|CMPMU
block|,
comment|// ADD, SUB, SMUL, etc. - Arithmetic operations with FLAGS results.
name|ADD
block|,
name|SUB
block|,
name|ADC
block|,
name|SBB
block|,
name|SMUL
block|,
name|INC
block|,
name|DEC
block|,
name|OR
block|,
name|XOR
block|,
name|AND
block|,
name|BEXTR
block|,
comment|// BEXTR - Bit field extract
name|UMUL
block|,
comment|// LOW, HI, FLAGS = umul LHS, RHS
comment|// MUL_IMM - X86 specific multiply by immediate.
name|MUL_IMM
block|,
comment|// PTEST - Vector bitwise comparisons.
name|PTEST
block|,
comment|// TESTP - Vector packed fp sign bitwise comparisons.
name|TESTP
block|,
comment|// TESTM, TESTNM - Vector "test" in AVX-512, the result is in a mask vector.
name|TESTM
block|,
name|TESTNM
block|,
comment|// OR/AND test for masks
name|KORTEST
block|,
comment|// Several flavors of instructions with vector shuffle behaviors.
name|PACKSS
block|,
name|PACKUS
block|,
name|PALIGNR
block|,
name|PSHUFD
block|,
name|PSHUFHW
block|,
name|PSHUFLW
block|,
name|SHUFP
block|,
name|MOVDDUP
block|,
name|MOVSHDUP
block|,
name|MOVSLDUP
block|,
name|MOVLHPS
block|,
name|MOVLHPD
block|,
name|MOVHLPS
block|,
name|MOVLPS
block|,
name|MOVLPD
block|,
name|MOVSD
block|,
name|MOVSS
block|,
name|UNPCKL
block|,
name|UNPCKH
block|,
name|VPERMILP
block|,
name|VPERMV
block|,
name|VPERMV3
block|,
name|VPERMIV3
block|,
name|VPERMI
block|,
name|VPERM2X128
block|,
name|VBROADCAST
block|,
comment|// masked broadcast
name|VBROADCASTM
block|,
comment|// Insert/Extract vector element
name|VINSERT
block|,
name|VEXTRACT
block|,
comment|// PMULUDQ - Vector multiply packed unsigned doubleword integers
name|PMULUDQ
block|,
comment|// PMULUDQ - Vector multiply packed signed doubleword integers
name|PMULDQ
block|,
comment|// FMA nodes
name|FMADD
block|,
name|FNMADD
block|,
name|FMSUB
block|,
name|FNMSUB
block|,
name|FMADDSUB
block|,
name|FMSUBADD
block|,
comment|// VASTART_SAVE_XMM_REGS - Save xmm argument registers to the stack,
comment|// according to %al. An operator is needed so that this can be expanded
comment|// with control flow.
name|VASTART_SAVE_XMM_REGS
block|,
comment|// WIN_ALLOCA - Windows's _chkstk call to do stack probing.
name|WIN_ALLOCA
block|,
comment|// SEG_ALLOCA - For allocating variable amounts of stack space when using
comment|// segmented stacks. Check if the current stacklet has enough space, and
comment|// falls back to heap allocation if not.
name|SEG_ALLOCA
block|,
comment|// WIN_FTOL - Windows's _ftol2 runtime routine to do fptoui.
name|WIN_FTOL
block|,
comment|// Memory barrier
name|MEMBARRIER
block|,
name|MFENCE
block|,
name|SFENCE
block|,
name|LFENCE
block|,
comment|// FNSTSW16r - Store FP status word into i16 register.
name|FNSTSW16r
block|,
comment|// SAHF - Store contents of %ah into %eflags.
name|SAHF
block|,
comment|// RDRAND - Get a random integer and indicate whether it is valid in CF.
name|RDRAND
block|,
comment|// RDSEED - Get a NIST SP800-90B& C compliant random integer and
comment|// indicate whether it is valid in CF.
name|RDSEED
block|,
comment|// PCMP*STRI
name|PCMPISTRI
block|,
name|PCMPESTRI
block|,
comment|// XTEST - Test if in transactional execution.
name|XTEST
block|,
comment|// LCMPXCHG_DAG, LCMPXCHG8_DAG, LCMPXCHG16_DAG - Compare and swap.
name|LCMPXCHG_DAG
init|=
name|ISD
operator|::
name|FIRST_TARGET_MEMORY_OPCODE
block|,
name|LCMPXCHG8_DAG
block|,
name|LCMPXCHG16_DAG
block|,
comment|// VZEXT_LOAD - Load, scalar_to_vector, and zero extend.
name|VZEXT_LOAD
block|,
comment|// FNSTCW16m - Store FP control world into i16 memory.
name|FNSTCW16m
block|,
comment|/// FP_TO_INT*_IN_MEM - This instruction implements FP_TO_SINT with the
comment|/// integer destination in memory and a FP reg source.  This corresponds
comment|/// to the X86::FIST*m instructions and the rounding mode change stuff. It
comment|/// has two inputs (token chain and address) and two outputs (int value
comment|/// and token chain).
name|FP_TO_INT16_IN_MEM
block|,
name|FP_TO_INT32_IN_MEM
block|,
name|FP_TO_INT64_IN_MEM
block|,
comment|/// FILD, FILD_FLAG - This instruction implements SINT_TO_FP with the
comment|/// integer source in memory and FP reg result.  This corresponds to the
comment|/// X86::FILD*m instructions. It has three inputs (token chain, address,
comment|/// and source type) and two outputs (FP value and token chain). FILD_FLAG
comment|/// also produces a flag).
name|FILD
block|,
name|FILD_FLAG
block|,
comment|/// FLD - This instruction implements an extending load to FP stack slots.
comment|/// This corresponds to the X86::FLD32m / X86::FLD64m. It takes a chain
comment|/// operand, ptr to load from, and a ValueType node indicating the type
comment|/// to load to.
name|FLD
block|,
comment|/// FST - This instruction implements a truncating store to FP stack
comment|/// slots. This corresponds to the X86::FST32m / X86::FST64m. It takes a
comment|/// chain operand, value to store, address, and a ValueType to store it
comment|/// as.
name|FST
block|,
comment|/// VAARG_64 - This instruction grabs the address of the next argument
comment|/// from a va_list. (reads and modifies the va_list in memory)
name|VAARG_64
comment|// WARNING: Do not add anything in the end unless you want the node to
comment|// have memop! In fact, starting from ATOMADD64_DAG all opcodes will be
comment|// thought as target memory ops!
block|}
enum|;
block|}
comment|/// Define some predicates that are used for node matching.
name|namespace
name|X86
block|{
comment|/// isVEXTRACT128Index - Return true if the specified
comment|/// EXTRACT_SUBVECTOR operand specifies a vector extract that is
comment|/// suitable for input to VEXTRACTF128, VEXTRACTI128 instructions.
name|bool
name|isVEXTRACT128Index
parameter_list|(
name|SDNode
modifier|*
name|N
parameter_list|)
function_decl|;
comment|/// isVINSERT128Index - Return true if the specified
comment|/// INSERT_SUBVECTOR operand specifies a subvector insert that is
comment|/// suitable for input to VINSERTF128, VINSERTI128 instructions.
name|bool
name|isVINSERT128Index
parameter_list|(
name|SDNode
modifier|*
name|N
parameter_list|)
function_decl|;
comment|/// isVEXTRACT256Index - Return true if the specified
comment|/// EXTRACT_SUBVECTOR operand specifies a vector extract that is
comment|/// suitable for input to VEXTRACTF64X4, VEXTRACTI64X4 instructions.
name|bool
name|isVEXTRACT256Index
parameter_list|(
name|SDNode
modifier|*
name|N
parameter_list|)
function_decl|;
comment|/// isVINSERT256Index - Return true if the specified
comment|/// INSERT_SUBVECTOR operand specifies a subvector insert that is
comment|/// suitable for input to VINSERTF64X4, VINSERTI64X4 instructions.
name|bool
name|isVINSERT256Index
parameter_list|(
name|SDNode
modifier|*
name|N
parameter_list|)
function_decl|;
comment|/// getExtractVEXTRACT128Immediate - Return the appropriate
comment|/// immediate to extract the specified EXTRACT_SUBVECTOR index
comment|/// with VEXTRACTF128, VEXTRACTI128 instructions.
name|unsigned
name|getExtractVEXTRACT128Immediate
parameter_list|(
name|SDNode
modifier|*
name|N
parameter_list|)
function_decl|;
comment|/// getInsertVINSERT128Immediate - Return the appropriate
comment|/// immediate to insert at the specified INSERT_SUBVECTOR index
comment|/// with VINSERTF128, VINSERT128 instructions.
name|unsigned
name|getInsertVINSERT128Immediate
parameter_list|(
name|SDNode
modifier|*
name|N
parameter_list|)
function_decl|;
comment|/// getExtractVEXTRACT256Immediate - Return the appropriate
comment|/// immediate to extract the specified EXTRACT_SUBVECTOR index
comment|/// with VEXTRACTF64X4, VEXTRACTI64x4 instructions.
name|unsigned
name|getExtractVEXTRACT256Immediate
parameter_list|(
name|SDNode
modifier|*
name|N
parameter_list|)
function_decl|;
comment|/// getInsertVINSERT256Immediate - Return the appropriate
comment|/// immediate to insert at the specified INSERT_SUBVECTOR index
comment|/// with VINSERTF64x4, VINSERTI64x4 instructions.
name|unsigned
name|getInsertVINSERT256Immediate
parameter_list|(
name|SDNode
modifier|*
name|N
parameter_list|)
function_decl|;
comment|/// isZeroNode - Returns true if Elt is a constant zero or a floating point
comment|/// constant +0.0.
name|bool
name|isZeroNode
parameter_list|(
name|SDValue
name|Elt
parameter_list|)
function_decl|;
comment|/// isOffsetSuitableForCodeModel - Returns true of the given offset can be
comment|/// fit into displacement field of the instruction.
name|bool
name|isOffsetSuitableForCodeModel
argument_list|(
name|int64_t
name|Offset
argument_list|,
name|CodeModel
operator|::
name|Model
name|M
argument_list|,
name|bool
name|hasSymbolicDisplacement
operator|=
name|true
argument_list|)
decl_stmt|;
comment|/// isCalleePop - Determines whether the callee is required to pop its
comment|/// own arguments. Callee pop is necessary to support tail calls.
name|bool
name|isCalleePop
argument_list|(
name|CallingConv
operator|::
name|ID
name|CallingConv
argument_list|,
name|bool
name|is64Bit
argument_list|,
name|bool
name|IsVarArg
argument_list|,
name|bool
name|TailCallOpt
argument_list|)
decl_stmt|;
block|}
comment|//===--------------------------------------------------------------------===//
comment|//  X86TargetLowering - X86 Implementation of the TargetLowering interface
name|class
name|X86TargetLowering
name|final
range|:
name|public
name|TargetLowering
block|{
name|public
operator|:
name|explicit
name|X86TargetLowering
argument_list|(
name|X86TargetMachine
operator|&
name|TM
argument_list|)
block|;
name|unsigned
name|getJumpTableEncoding
argument_list|()
specifier|const
name|override
block|;
name|MVT
name|getScalarShiftAmountTy
argument_list|(
argument|EVT LHSTy
argument_list|)
specifier|const
name|override
block|{
return|return
name|MVT
operator|::
name|i8
return|;
block|}
specifier|const
name|MCExpr
operator|*
name|LowerCustomJumpTableEntry
argument_list|(
argument|const MachineJumpTableInfo *MJTI
argument_list|,
argument|const MachineBasicBlock *MBB
argument_list|,
argument|unsigned uid
argument_list|,
argument|MCContext&Ctx
argument_list|)
specifier|const
name|override
block|;
comment|/// getPICJumpTableRelocaBase - Returns relocation base for the given PIC
comment|/// jumptable.
name|SDValue
name|getPICJumpTableRelocBase
argument_list|(
argument|SDValue Table
argument_list|,
argument|SelectionDAG&DAG
argument_list|)
specifier|const
name|override
block|;
specifier|const
name|MCExpr
operator|*
name|getPICJumpTableRelocBaseExpr
argument_list|(
argument|const MachineFunction *MF
argument_list|,
argument|unsigned JTI
argument_list|,
argument|MCContext&Ctx
argument_list|)
specifier|const
name|override
block|;
comment|/// getByValTypeAlignment - Return the desired alignment for ByVal aggregate
comment|/// function arguments in the caller parameter area. For X86, aggregates
comment|/// that contains are placed at 16-byte boundaries while the rest are at
comment|/// 4-byte boundaries.
name|unsigned
name|getByValTypeAlignment
argument_list|(
argument|Type *Ty
argument_list|)
specifier|const
name|override
block|;
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
name|override
block|;
comment|/// isSafeMemOpType - Returns true if it's safe to use load / store of the
comment|/// specified type to expand memcpy / memset inline. This is mostly true
comment|/// for all types except for some special cases. For example, on X86
comment|/// targets without SSE2 f64 load / store are done with fldl / fstpl which
comment|/// also does type conversion. Note the specified type doesn't have to be
comment|/// legal as the hook is used before type legalization.
name|bool
name|isSafeMemOpType
argument_list|(
argument|MVT VT
argument_list|)
specifier|const
name|override
block|;
comment|/// allowsUnalignedMemoryAccesses - Returns true if the target allows
comment|/// unaligned memory accesses. of the specified type. Returns whether it
comment|/// is "fast" by reference in the second argument.
name|bool
name|allowsUnalignedMemoryAccesses
argument_list|(
argument|EVT VT
argument_list|,
argument|unsigned AS
argument_list|,
argument|bool *Fast
argument_list|)
specifier|const
name|override
block|;
comment|/// LowerOperation - Provide custom lowering hooks for some operations.
comment|///
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
comment|/// isTypeDesirableForOp - Return true if the target has native support for
comment|/// the specified value type and it is 'desirable' to use the type for the
comment|/// given node type. e.g. On x86 i16 is legal, but undesirable since i16
comment|/// instruction encodings are longer and some i16 instructions are slow.
name|bool
name|isTypeDesirableForOp
argument_list|(
argument|unsigned Opc
argument_list|,
argument|EVT VT
argument_list|)
specifier|const
name|override
block|;
comment|/// isTypeDesirable - Return true if the target has native support for the
comment|/// specified value type and it is 'desirable' to use the type. e.g. On x86
comment|/// i16 is legal, but undesirable since i16 instruction encodings are longer
comment|/// and some i16 instructions are slow.
name|bool
name|IsDesirableToPromoteOp
argument_list|(
argument|SDValue Op
argument_list|,
argument|EVT&PVT
argument_list|)
specifier|const
name|override
block|;
name|MachineBasicBlock
operator|*
name|EmitInstrWithCustomInserter
argument_list|(
argument|MachineInstr *MI
argument_list|,
argument|MachineBasicBlock *MBB
argument_list|)
specifier|const
name|override
block|;
comment|/// getTargetNodeName - This method returns the name of a target specific
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
comment|/// getSetCCResultType - Return the value type to use for ISD::SETCC.
name|EVT
name|getSetCCResultType
argument_list|(
argument|LLVMContext&Context
argument_list|,
argument|EVT VT
argument_list|)
specifier|const
name|override
block|;
comment|/// computeKnownBitsForTargetNode - Determine which of the bits specified
comment|/// in Mask are known to be either zero or one and return them in the
comment|/// KnownZero/KnownOne bitsets.
name|void
name|computeKnownBitsForTargetNode
argument_list|(
argument|const SDValue Op
argument_list|,
argument|APInt&KnownZero
argument_list|,
argument|APInt&KnownOne
argument_list|,
argument|const SelectionDAG&DAG
argument_list|,
argument|unsigned Depth =
literal|0
argument_list|)
specifier|const
name|override
block|;
comment|// ComputeNumSignBitsForTargetNode - Determine the number of bits in the
comment|// operation that are sign bits.
name|unsigned
name|ComputeNumSignBitsForTargetNode
argument_list|(
argument|SDValue Op
argument_list|,
argument|const SelectionDAG&DAG
argument_list|,
argument|unsigned Depth
argument_list|)
specifier|const
name|override
block|;
name|bool
name|isGAPlusOffset
argument_list|(
argument|SDNode *N
argument_list|,
argument|const GlobalValue*&GA
argument_list|,
argument|int64_t&Offset
argument_list|)
specifier|const
name|override
block|;
name|SDValue
name|getReturnAddressFrameIndex
argument_list|(
argument|SelectionDAG&DAG
argument_list|)
specifier|const
block|;
name|bool
name|ExpandInlineAsm
argument_list|(
argument|CallInst *CI
argument_list|)
specifier|const
name|override
block|;
name|ConstraintType
name|getConstraintType
argument_list|(
argument|const std::string&Constraint
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
specifier|const
name|char
operator|*
name|LowerXConstraint
argument_list|(
argument|EVT ConstraintVT
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
comment|/// getRegForInlineAsmConstraint - Given a physical register constraint
comment|/// (e.g. {edx}), return the register number and the register class for the
comment|/// register.  This should only be used for C_Register constraints.  On
comment|/// error, this returns a register number of 0.
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
name|override
block|;
comment|/// isLegalAddressingMode - Return true if the addressing mode represented
comment|/// by AM is legal for this target, for a load/store of the specified type.
name|bool
name|isLegalAddressingMode
argument_list|(
argument|const AddrMode&AM
argument_list|,
argument|Type *Ty
argument_list|)
specifier|const
name|override
block|;
comment|/// isLegalICmpImmediate - Return true if the specified immediate is legal
comment|/// icmp immediate, that is the target has icmp instructions which can
comment|/// compare a register against the immediate without having to materialize
comment|/// the immediate into a register.
name|bool
name|isLegalICmpImmediate
argument_list|(
argument|int64_t Imm
argument_list|)
specifier|const
name|override
block|;
comment|/// isLegalAddImmediate - Return true if the specified immediate is legal
comment|/// add immediate, that is the target has add instructions which can
comment|/// add a register and the immediate without having to materialize
comment|/// the immediate into a register.
name|bool
name|isLegalAddImmediate
argument_list|(
argument|int64_t Imm
argument_list|)
specifier|const
name|override
block|;
comment|/// \brief Return the cost of the scaling factor used in the addressing
comment|/// mode represented by AM for this target, for a load/store
comment|/// of the specified type.
comment|/// If the AM is supported, the return value must be>= 0.
comment|/// If the AM is not supported, it returns a negative value.
name|int
name|getScalingFactorCost
argument_list|(
argument|const AddrMode&AM
argument_list|,
argument|Type *Ty
argument_list|)
specifier|const
name|override
block|;
name|bool
name|isVectorShiftByScalarCheap
argument_list|(
argument|Type *Ty
argument_list|)
specifier|const
name|override
block|;
comment|/// isTruncateFree - Return true if it's free to truncate a value of
comment|/// type Ty1 to type Ty2. e.g. On x86 it's free to truncate a i32 value in
comment|/// register EAX to i16 by referencing its sub-register AX.
name|bool
name|isTruncateFree
argument_list|(
argument|Type *Ty1
argument_list|,
argument|Type *Ty2
argument_list|)
specifier|const
name|override
block|;
name|bool
name|isTruncateFree
argument_list|(
argument|EVT VT1
argument_list|,
argument|EVT VT2
argument_list|)
specifier|const
name|override
block|;
name|bool
name|allowTruncateForTailCall
argument_list|(
argument|Type *Ty1
argument_list|,
argument|Type *Ty2
argument_list|)
specifier|const
name|override
block|;
comment|/// isZExtFree - Return true if any actual instruction that defines a
comment|/// value of type Ty1 implicit zero-extends the value to Ty2 in the result
comment|/// register. This does not necessarily include registers defined in
comment|/// unknown ways, such as incoming arguments, or copies from unknown
comment|/// virtual registers. Also, if isTruncateFree(Ty2, Ty1) is true, this
comment|/// does not necessarily apply to truncate instructions. e.g. on x86-64,
comment|/// all instructions that define 32-bit values implicit zero-extend the
comment|/// result out to 64 bits.
name|bool
name|isZExtFree
argument_list|(
argument|Type *Ty1
argument_list|,
argument|Type *Ty2
argument_list|)
specifier|const
name|override
block|;
name|bool
name|isZExtFree
argument_list|(
argument|EVT VT1
argument_list|,
argument|EVT VT2
argument_list|)
specifier|const
name|override
block|;
name|bool
name|isZExtFree
argument_list|(
argument|SDValue Val
argument_list|,
argument|EVT VT2
argument_list|)
specifier|const
name|override
block|;
comment|/// isFMAFasterThanFMulAndFAdd - Return true if an FMA operation is faster
comment|/// than a pair of fmul and fadd instructions. fmuladd intrinsics will be
comment|/// expanded to FMAs when this method returns true, otherwise fmuladd is
comment|/// expanded to fmul + fadd.
name|bool
name|isFMAFasterThanFMulAndFAdd
argument_list|(
argument|EVT VT
argument_list|)
specifier|const
name|override
block|;
comment|/// isNarrowingProfitable - Return true if it's profitable to narrow
comment|/// operations of type VT1 to VT2. e.g. on x86, it's profitable to narrow
comment|/// from i32 to i8 but not from i32 to i16.
name|bool
name|isNarrowingProfitable
argument_list|(
argument|EVT VT1
argument_list|,
argument|EVT VT2
argument_list|)
specifier|const
name|override
block|;
comment|/// isFPImmLegal - Returns true if the target can instruction select the
comment|/// specified FP immediate natively. If false, the legalizer will
comment|/// materialize the FP immediate as a load from a constant pool.
name|bool
name|isFPImmLegal
argument_list|(
argument|const APFloat&Imm
argument_list|,
argument|EVT VT
argument_list|)
specifier|const
name|override
block|;
comment|/// isShuffleMaskLegal - Targets can use this to indicate that they only
comment|/// support *some* VECTOR_SHUFFLE operations, those with specific masks.
comment|/// By default, if a target supports the VECTOR_SHUFFLE node, all mask
comment|/// values are assumed to be legal.
name|bool
name|isShuffleMaskLegal
argument_list|(
argument|const SmallVectorImpl<int>&Mask
argument_list|,
argument|EVT VT
argument_list|)
specifier|const
name|override
block|;
comment|/// isVectorClearMaskLegal - Similar to isShuffleMaskLegal. This is
comment|/// used by Targets can use this to indicate if there is a suitable
comment|/// VECTOR_SHUFFLE that can be used to replace a VAND with a constant
comment|/// pool entry.
name|bool
name|isVectorClearMaskLegal
argument_list|(
argument|const SmallVectorImpl<int>&Mask
argument_list|,
argument|EVT VT
argument_list|)
specifier|const
name|override
block|;
comment|/// ShouldShrinkFPConstant - If true, then instruction selection should
comment|/// seek to shrink the FP constant of the specified type to a smaller type
comment|/// in order to save space and / or reduce runtime.
name|bool
name|ShouldShrinkFPConstant
argument_list|(
argument|EVT VT
argument_list|)
specifier|const
name|override
block|{
comment|// Don't shrink FP constpool if SSE2 is available since cvtss2sd is more
comment|// expensive than a straight movsd. On the other hand, it's important to
comment|// shrink long double fp constant since fldt is very slow.
return|return
operator|!
name|X86ScalarSSEf64
operator|||
name|VT
operator|==
name|MVT
operator|::
name|f80
return|;
block|}
specifier|const
name|X86Subtarget
operator|*
name|getSubtarget
argument_list|()
specifier|const
block|{
return|return
name|Subtarget
return|;
block|}
comment|/// isScalarFPTypeInSSEReg - Return true if the specified scalar FP type is
comment|/// computed in an SSE register, not on the X87 floating point stack.
name|bool
name|isScalarFPTypeInSSEReg
argument_list|(
argument|EVT VT
argument_list|)
specifier|const
block|{
return|return
operator|(
name|VT
operator|==
name|MVT
operator|::
name|f64
operator|&&
name|X86ScalarSSEf64
operator|)
operator|||
comment|// f64 is when SSE2
operator|(
name|VT
operator|==
name|MVT
operator|::
name|f32
operator|&&
name|X86ScalarSSEf32
operator|)
return|;
comment|// f32 is when SSE1
block|}
comment|/// isTargetFTOL - Return true if the target uses the MSVC _ftol2 routine
comment|/// for fptoui.
name|bool
name|isTargetFTOL
argument_list|()
specifier|const
block|;
comment|/// isIntegerTypeFTOL - Return true if the MSVC _ftol2 routine should be
comment|/// used for fptoui to the given type.
name|bool
name|isIntegerTypeFTOL
argument_list|(
argument|EVT VT
argument_list|)
specifier|const
block|{
return|return
name|isTargetFTOL
argument_list|()
operator|&&
name|VT
operator|==
name|MVT
operator|::
name|i64
return|;
block|}
comment|/// \brief Returns true if it is beneficial to convert a load of a constant
comment|/// to just the constant itself.
name|bool
name|shouldConvertConstantLoadToIntImm
argument_list|(
argument|const APInt&Imm
argument_list|,
argument|Type *Ty
argument_list|)
specifier|const
name|override
block|;
comment|/// Intel processors have a unified instruction and data cache
specifier|const
name|char
operator|*
name|getClearCacheBuiltinName
argument_list|()
specifier|const
name|override
block|{
return|return
name|nullptr
return|;
comment|// nothing to do, move along.
block|}
name|unsigned
name|getRegisterByName
argument_list|(
argument|const char* RegName
argument_list|,
argument|EVT VT
argument_list|)
specifier|const
name|override
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
comment|/// getStackCookieLocation - Return true if the target stores stack
comment|/// protector cookies at a fixed offset in some non-standard address
comment|/// space, and populates the address space and offset as
comment|/// appropriate.
name|bool
name|getStackCookieLocation
argument_list|(
argument|unsigned&AddressSpace
argument_list|,
argument|unsigned&Offset
argument_list|)
specifier|const
name|override
block|;
name|SDValue
name|BuildFILD
argument_list|(
argument|SDValue Op
argument_list|,
argument|EVT SrcVT
argument_list|,
argument|SDValue Chain
argument_list|,
argument|SDValue StackSlot
argument_list|,
argument|SelectionDAG&DAG
argument_list|)
specifier|const
block|;
name|bool
name|isNoopAddrSpaceCast
argument_list|(
argument|unsigned SrcAS
argument_list|,
argument|unsigned DestAS
argument_list|)
specifier|const
name|override
block|;
comment|/// \brief Reset the operation actions based on target options.
name|void
name|resetOperationActions
argument_list|()
name|override
block|;
comment|/// \brief Customize the preferred legalization strategy for certain types.
name|LegalizeTypeAction
name|getPreferredVectorAction
argument_list|(
argument|EVT VT
argument_list|)
specifier|const
name|override
block|;
name|protected
operator|:
name|std
operator|::
name|pair
operator|<
specifier|const
name|TargetRegisterClass
operator|*
block|,
name|uint8_t
operator|>
name|findRepresentativeClass
argument_list|(
argument|MVT VT
argument_list|)
specifier|const
name|override
block|;
name|private
operator|:
comment|/// Subtarget - Keep a pointer to the X86Subtarget around so that we can
comment|/// make the right decision when generating code for different targets.
specifier|const
name|X86Subtarget
operator|*
name|Subtarget
block|;
specifier|const
name|DataLayout
operator|*
name|TD
block|;
comment|/// Used to store the TargetOptions so that we don't waste time resetting
comment|/// the operation actions unless we have to.
name|TargetOptions
name|TO
block|;
comment|/// X86ScalarSSEf32, X86ScalarSSEf64 - Select between SSE or x87
comment|/// floating point ops.
comment|/// When SSE is available, use it for f32 operations.
comment|/// When SSE2 is available, use it for f64 operations.
name|bool
name|X86ScalarSSEf32
block|;
name|bool
name|X86ScalarSSEf64
block|;
comment|/// LegalFPImmediates - A list of legal fp immediates.
name|std
operator|::
name|vector
operator|<
name|APFloat
operator|>
name|LegalFPImmediates
block|;
comment|/// addLegalFPImmediate - Indicate that this x86 target can instruction
comment|/// select the specified FP immediate natively.
name|void
name|addLegalFPImmediate
argument_list|(
argument|const APFloat& Imm
argument_list|)
block|{
name|LegalFPImmediates
operator|.
name|push_back
argument_list|(
name|Imm
argument_list|)
block|;     }
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
argument_list|)
specifier|const
block|;
name|SDValue
name|LowerMemArgument
argument_list|(
argument|SDValue Chain
argument_list|,
argument|CallingConv::ID CallConv
argument_list|,
argument|const SmallVectorImpl<ISD::InputArg>&ArgInfo
argument_list|,
argument|SDLoc dl
argument_list|,
argument|SelectionDAG&DAG
argument_list|,
argument|const CCValAssign&VA
argument_list|,
argument|MachineFrameInfo *MFI
argument_list|,
argument|unsigned i
argument_list|)
specifier|const
block|;
name|SDValue
name|LowerMemOpCallTo
argument_list|(
argument|SDValue Chain
argument_list|,
argument|SDValue StackPtr
argument_list|,
argument|SDValue Arg
argument_list|,
argument|SDLoc dl
argument_list|,
argument|SelectionDAG&DAG
argument_list|,
argument|const CCValAssign&VA
argument_list|,
argument|ISD::ArgFlagsTy Flags
argument_list|)
specifier|const
block|;
comment|// Call lowering helpers.
comment|/// IsEligibleForTailCallOptimization - Check whether the call is eligible
comment|/// for tail call optimization. Targets which want to do tail call
comment|/// optimization should implement this function.
name|bool
name|IsEligibleForTailCallOptimization
argument_list|(
argument|SDValue Callee
argument_list|,
argument|CallingConv::ID CalleeCC
argument_list|,
argument|bool isVarArg
argument_list|,
argument|bool isCalleeStructRet
argument_list|,
argument|bool isCallerStructRet
argument_list|,
argument|Type *RetTy
argument_list|,
argument|const SmallVectorImpl<ISD::OutputArg>&Outs
argument_list|,
argument|const SmallVectorImpl<SDValue>&OutVals
argument_list|,
argument|const SmallVectorImpl<ISD::InputArg>&Ins
argument_list|,
argument|SelectionDAG& DAG
argument_list|)
specifier|const
block|;
name|bool
name|IsCalleePop
argument_list|(
argument|bool isVarArg
argument_list|,
argument|CallingConv::ID CallConv
argument_list|)
specifier|const
block|;
name|SDValue
name|EmitTailCallLoadRetAddr
argument_list|(
argument|SelectionDAG&DAG
argument_list|,
argument|SDValue&OutRetAddr
argument_list|,
argument|SDValue Chain
argument_list|,
argument|bool IsTailCall
argument_list|,
argument|bool Is64Bit
argument_list|,
argument|int FPDiff
argument_list|,
argument|SDLoc dl
argument_list|)
specifier|const
block|;
name|unsigned
name|GetAlignedArgumentStackSize
argument_list|(
argument|unsigned StackSize
argument_list|,
argument|SelectionDAG&DAG
argument_list|)
specifier|const
block|;
name|std
operator|::
name|pair
operator|<
name|SDValue
block|,
name|SDValue
operator|>
name|FP_TO_INTHelper
argument_list|(
argument|SDValue Op
argument_list|,
argument|SelectionDAG&DAG
argument_list|,
argument|bool isSigned
argument_list|,
argument|bool isReplace
argument_list|)
specifier|const
block|;
name|SDValue
name|LowerBUILD_VECTOR
argument_list|(
argument|SDValue Op
argument_list|,
argument|SelectionDAG&DAG
argument_list|)
specifier|const
block|;
name|SDValue
name|LowerBUILD_VECTORvXi1
argument_list|(
argument|SDValue Op
argument_list|,
argument|SelectionDAG&DAG
argument_list|)
specifier|const
block|;
name|SDValue
name|LowerVECTOR_SHUFFLE
argument_list|(
argument|SDValue Op
argument_list|,
argument|SelectionDAG&DAG
argument_list|)
specifier|const
block|;
name|SDValue
name|LowerVSELECT
argument_list|(
argument|SDValue Op
argument_list|,
argument|SelectionDAG&DAG
argument_list|)
specifier|const
block|;
name|SDValue
name|LowerEXTRACT_VECTOR_ELT
argument_list|(
argument|SDValue Op
argument_list|,
argument|SelectionDAG&DAG
argument_list|)
specifier|const
block|;
name|SDValue
name|ExtractBitFromMaskVector
argument_list|(
argument|SDValue Op
argument_list|,
argument|SelectionDAG&DAG
argument_list|)
specifier|const
block|;
name|SDValue
name|InsertBitToMaskVector
argument_list|(
argument|SDValue Op
argument_list|,
argument|SelectionDAG&DAG
argument_list|)
specifier|const
block|;
name|SDValue
name|LowerINSERT_VECTOR_ELT
argument_list|(
argument|SDValue Op
argument_list|,
argument|SelectionDAG&DAG
argument_list|)
specifier|const
block|;
name|SDValue
name|LowerConstantPool
argument_list|(
argument|SDValue Op
argument_list|,
argument|SelectionDAG&DAG
argument_list|)
specifier|const
block|;
name|SDValue
name|LowerBlockAddress
argument_list|(
argument|SDValue Op
argument_list|,
argument|SelectionDAG&DAG
argument_list|)
specifier|const
block|;
name|SDValue
name|LowerGlobalAddress
argument_list|(
argument|const GlobalValue *GV
argument_list|,
argument|SDLoc dl
argument_list|,
argument|int64_t Offset
argument_list|,
argument|SelectionDAG&DAG
argument_list|)
specifier|const
block|;
name|SDValue
name|LowerGlobalAddress
argument_list|(
argument|SDValue Op
argument_list|,
argument|SelectionDAG&DAG
argument_list|)
specifier|const
block|;
name|SDValue
name|LowerGlobalTLSAddress
argument_list|(
argument|SDValue Op
argument_list|,
argument|SelectionDAG&DAG
argument_list|)
specifier|const
block|;
name|SDValue
name|LowerExternalSymbol
argument_list|(
argument|SDValue Op
argument_list|,
argument|SelectionDAG&DAG
argument_list|)
specifier|const
block|;
name|SDValue
name|LowerSINT_TO_FP
argument_list|(
argument|SDValue Op
argument_list|,
argument|SelectionDAG&DAG
argument_list|)
specifier|const
block|;
name|SDValue
name|LowerUINT_TO_FP
argument_list|(
argument|SDValue Op
argument_list|,
argument|SelectionDAG&DAG
argument_list|)
specifier|const
block|;
name|SDValue
name|LowerUINT_TO_FP_i64
argument_list|(
argument|SDValue Op
argument_list|,
argument|SelectionDAG&DAG
argument_list|)
specifier|const
block|;
name|SDValue
name|LowerUINT_TO_FP_i32
argument_list|(
argument|SDValue Op
argument_list|,
argument|SelectionDAG&DAG
argument_list|)
specifier|const
block|;
name|SDValue
name|lowerUINT_TO_FP_vec
argument_list|(
argument|SDValue Op
argument_list|,
argument|SelectionDAG&DAG
argument_list|)
specifier|const
block|;
name|SDValue
name|LowerTRUNCATE
argument_list|(
argument|SDValue Op
argument_list|,
argument|SelectionDAG&DAG
argument_list|)
specifier|const
block|;
name|SDValue
name|LowerFP_TO_SINT
argument_list|(
argument|SDValue Op
argument_list|,
argument|SelectionDAG&DAG
argument_list|)
specifier|const
block|;
name|SDValue
name|LowerFP_TO_UINT
argument_list|(
argument|SDValue Op
argument_list|,
argument|SelectionDAG&DAG
argument_list|)
specifier|const
block|;
name|SDValue
name|LowerToBT
argument_list|(
argument|SDValue And
argument_list|,
argument|ISD::CondCode CC
argument_list|,
argument|SDLoc dl
argument_list|,
argument|SelectionDAG&DAG
argument_list|)
specifier|const
block|;
name|SDValue
name|LowerSETCC
argument_list|(
argument|SDValue Op
argument_list|,
argument|SelectionDAG&DAG
argument_list|)
specifier|const
block|;
name|SDValue
name|LowerSELECT
argument_list|(
argument|SDValue Op
argument_list|,
argument|SelectionDAG&DAG
argument_list|)
specifier|const
block|;
name|SDValue
name|LowerBRCOND
argument_list|(
argument|SDValue Op
argument_list|,
argument|SelectionDAG&DAG
argument_list|)
specifier|const
block|;
name|SDValue
name|LowerMEMSET
argument_list|(
argument|SDValue Op
argument_list|,
argument|SelectionDAG&DAG
argument_list|)
specifier|const
block|;
name|SDValue
name|LowerJumpTable
argument_list|(
argument|SDValue Op
argument_list|,
argument|SelectionDAG&DAG
argument_list|)
specifier|const
block|;
name|SDValue
name|LowerDYNAMIC_STACKALLOC
argument_list|(
argument|SDValue Op
argument_list|,
argument|SelectionDAG&DAG
argument_list|)
specifier|const
block|;
name|SDValue
name|LowerVASTART
argument_list|(
argument|SDValue Op
argument_list|,
argument|SelectionDAG&DAG
argument_list|)
specifier|const
block|;
name|SDValue
name|LowerVAARG
argument_list|(
argument|SDValue Op
argument_list|,
argument|SelectionDAG&DAG
argument_list|)
specifier|const
block|;
name|SDValue
name|LowerRETURNADDR
argument_list|(
argument|SDValue Op
argument_list|,
argument|SelectionDAG&DAG
argument_list|)
specifier|const
block|;
name|SDValue
name|LowerFRAMEADDR
argument_list|(
argument|SDValue Op
argument_list|,
argument|SelectionDAG&DAG
argument_list|)
specifier|const
block|;
name|SDValue
name|LowerFRAME_TO_ARGS_OFFSET
argument_list|(
argument|SDValue Op
argument_list|,
argument|SelectionDAG&DAG
argument_list|)
specifier|const
block|;
name|SDValue
name|LowerEH_RETURN
argument_list|(
argument|SDValue Op
argument_list|,
argument|SelectionDAG&DAG
argument_list|)
specifier|const
block|;
name|SDValue
name|lowerEH_SJLJ_SETJMP
argument_list|(
argument|SDValue Op
argument_list|,
argument|SelectionDAG&DAG
argument_list|)
specifier|const
block|;
name|SDValue
name|lowerEH_SJLJ_LONGJMP
argument_list|(
argument|SDValue Op
argument_list|,
argument|SelectionDAG&DAG
argument_list|)
specifier|const
block|;
name|SDValue
name|LowerINIT_TRAMPOLINE
argument_list|(
argument|SDValue Op
argument_list|,
argument|SelectionDAG&DAG
argument_list|)
specifier|const
block|;
name|SDValue
name|LowerFLT_ROUNDS_
argument_list|(
argument|SDValue Op
argument_list|,
argument|SelectionDAG&DAG
argument_list|)
specifier|const
block|;
name|SDValue
name|LowerSIGN_EXTEND_INREG
argument_list|(
argument|SDValue Op
argument_list|,
argument|SelectionDAG&DAG
argument_list|)
specifier|const
block|;
name|SDValue
name|LowerWin64_i128OP
argument_list|(
argument|SDValue Op
argument_list|,
argument|SelectionDAG&DAG
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
argument|SDLoc dl
argument_list|,
argument|SelectionDAG&DAG
argument_list|,
argument|SmallVectorImpl<SDValue>&InVals
argument_list|)
specifier|const
name|override
block|;
name|SDValue
name|LowerCall
argument_list|(
argument|CallLoweringInfo&CLI
argument_list|,
argument|SmallVectorImpl<SDValue>&InVals
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
argument|SDLoc dl
argument_list|,
argument|SelectionDAG&DAG
argument_list|)
specifier|const
name|override
block|;
name|bool
name|isUsedByReturnOnly
argument_list|(
argument|SDNode *N
argument_list|,
argument|SDValue&Chain
argument_list|)
specifier|const
name|override
block|;
name|bool
name|mayBeEmittedAsTailCall
argument_list|(
argument|CallInst *CI
argument_list|)
specifier|const
name|override
block|;
name|MVT
name|getTypeForExtArgOrReturn
argument_list|(
argument|MVT VT
argument_list|,
argument|ISD::NodeType ExtendKind
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
specifier|const
name|MCPhysReg
operator|*
name|getScratchRegisters
argument_list|(
argument|CallingConv::ID CC
argument_list|)
specifier|const
name|override
block|;
comment|/// Utility function to emit atomic-load-arith operations (and, or, xor,
comment|/// nand, max, min, umax, umin). It takes the corresponding instruction to
comment|/// expand, the associated machine basic block, and the associated X86
comment|/// opcodes for reg/reg.
name|MachineBasicBlock
operator|*
name|EmitAtomicLoadArith
argument_list|(
argument|MachineInstr *MI
argument_list|,
argument|MachineBasicBlock *MBB
argument_list|)
specifier|const
block|;
comment|/// Utility function to emit atomic-load-arith operations (and, or, xor,
comment|/// nand, add, sub, swap) for 64-bit operands on 32-bit target.
name|MachineBasicBlock
operator|*
name|EmitAtomicLoadArith6432
argument_list|(
argument|MachineInstr *MI
argument_list|,
argument|MachineBasicBlock *MBB
argument_list|)
specifier|const
block|;
comment|// Utility function to emit the low-level va_arg code for X86-64.
name|MachineBasicBlock
operator|*
name|EmitVAARG64WithCustomInserter
argument_list|(
argument|MachineInstr *MI
argument_list|,
argument|MachineBasicBlock *MBB
argument_list|)
specifier|const
block|;
comment|/// Utility function to emit the xmm reg save portion of va_start.
name|MachineBasicBlock
operator|*
name|EmitVAStartSaveXMMRegsWithCustomInserter
argument_list|(
argument|MachineInstr *BInstr
argument_list|,
argument|MachineBasicBlock *BB
argument_list|)
specifier|const
block|;
name|MachineBasicBlock
operator|*
name|EmitLoweredSelect
argument_list|(
argument|MachineInstr *I
argument_list|,
argument|MachineBasicBlock *BB
argument_list|)
specifier|const
block|;
name|MachineBasicBlock
operator|*
name|EmitLoweredWinAlloca
argument_list|(
argument|MachineInstr *MI
argument_list|,
argument|MachineBasicBlock *BB
argument_list|)
specifier|const
block|;
name|MachineBasicBlock
operator|*
name|EmitLoweredSegAlloca
argument_list|(
argument|MachineInstr *MI
argument_list|,
argument|MachineBasicBlock *BB
argument_list|,
argument|bool Is64Bit
argument_list|)
specifier|const
block|;
name|MachineBasicBlock
operator|*
name|EmitLoweredTLSCall
argument_list|(
argument|MachineInstr *MI
argument_list|,
argument|MachineBasicBlock *BB
argument_list|)
specifier|const
block|;
name|MachineBasicBlock
operator|*
name|emitLoweredTLSAddr
argument_list|(
argument|MachineInstr *MI
argument_list|,
argument|MachineBasicBlock *BB
argument_list|)
specifier|const
block|;
name|MachineBasicBlock
operator|*
name|emitEHSjLjSetJmp
argument_list|(
argument|MachineInstr *MI
argument_list|,
argument|MachineBasicBlock *MBB
argument_list|)
specifier|const
block|;
name|MachineBasicBlock
operator|*
name|emitEHSjLjLongJmp
argument_list|(
argument|MachineInstr *MI
argument_list|,
argument|MachineBasicBlock *MBB
argument_list|)
specifier|const
block|;
name|MachineBasicBlock
operator|*
name|emitFMA3Instr
argument_list|(
argument|MachineInstr *MI
argument_list|,
argument|MachineBasicBlock *MBB
argument_list|)
specifier|const
block|;
comment|/// Emit nodes that will be selected as "test Op0,Op0", or something
comment|/// equivalent, for use with the given x86 condition code.
name|SDValue
name|EmitTest
argument_list|(
argument|SDValue Op0
argument_list|,
argument|unsigned X86CC
argument_list|,
argument|SDLoc dl
argument_list|,
argument|SelectionDAG&DAG
argument_list|)
specifier|const
block|;
comment|/// Emit nodes that will be selected as "cmp Op0,Op1", or something
comment|/// equivalent, for use with the given x86 condition code.
name|SDValue
name|EmitCmp
argument_list|(
argument|SDValue Op0
argument_list|,
argument|SDValue Op1
argument_list|,
argument|unsigned X86CC
argument_list|,
argument|SDLoc dl
argument_list|,
argument|SelectionDAG&DAG
argument_list|)
specifier|const
block|;
comment|/// Convert a comparison if required by the subtarget.
name|SDValue
name|ConvertCmpIfNecessary
argument_list|(
argument|SDValue Cmp
argument_list|,
argument|SelectionDAG&DAG
argument_list|)
specifier|const
block|;   }
decl_stmt|;
name|namespace
name|X86
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
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// X86ISELLOWERING_H
end_comment

end_unit

