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
name|LLVM_LIB_TARGET_X86_X86ISELLOWERING_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_LIB_TARGET_X86_X86ISELLOWERING_H
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
enum|:
name|unsigned
block|{
comment|// Start the numbering where the builtin ops leave off.
name|FIRST_NUMBER
init|=
name|ISD
operator|::
name|BUILTIN_OP_END
block|,
comment|/// Bit scan forward.
name|BSF
block|,
comment|/// Bit scan reverse.
name|BSR
block|,
comment|/// Double shift instructions. These correspond to
comment|/// X86::SHLDxx and X86::SHRDxx instructions.
name|SHLD
block|,
name|SHRD
block|,
comment|/// Bitwise logical AND of floating point values. This corresponds
comment|/// to X86::ANDPS or X86::ANDPD.
name|FAND
block|,
comment|/// Bitwise logical OR of floating point values. This corresponds
comment|/// to X86::ORPS or X86::ORPD.
name|FOR
block|,
comment|/// Bitwise logical XOR of floating point values. This corresponds
comment|/// to X86::XORPS or X86::XORPD.
name|FXOR
block|,
comment|///  Bitwise logical ANDNOT of floating point values. This
comment|/// corresponds to X86::ANDNPS or X86::ANDNPD.
name|FANDN
block|,
comment|/// These operations represent an abstract X86 call
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
comment|/// This operation implements the lowering for readcyclecounter
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
comment|/// Return from interrupt. Operand 0 is the number of bytes to pop.
name|IRET
block|,
comment|/// Repeat fill, corresponds to X86::REP_STOSx.
name|REP_STOS
block|,
comment|/// Repeat move, corresponds to X86::REP_MOVSx.
name|REP_MOVS
block|,
comment|/// On Darwin, this node represents the result of the popl
comment|/// at function entry, used for PIC code.
name|GlobalBaseReg
block|,
comment|/// A wrapper node for TargetConstantPool,
comment|/// TargetExternalSymbol, and TargetGlobalAddress.
name|Wrapper
block|,
comment|/// Special wrapper used under X86-64 PIC mode for RIP
comment|/// relative displacements.
name|WrapperRIP
block|,
comment|/// Copies a 64-bit value from the low word of an XMM vector
comment|/// to an MMX vector.  If you think this is too close to the previous
comment|/// mnemonic, so do I; blame Intel.
name|MOVDQ2Q
block|,
comment|/// Copies a 32-bit value from the low word of a MMX
comment|/// vector to a GPR.
name|MMX_MOVD2W
block|,
comment|/// Copies a GPR into the low 32-bit word of a MMX vector
comment|/// and zero out the high word.
name|MMX_MOVW2D
block|,
comment|/// Extract an 8-bit value from a vector and zero extend it to
comment|/// i32, corresponds to X86::PEXTRB.
name|PEXTRB
block|,
comment|/// Extract a 16-bit value from a vector and zero extend it to
comment|/// i32, corresponds to X86::PEXTRW.
name|PEXTRW
block|,
comment|/// Insert any element of a 4 x float vector into any element
comment|/// of a destination 4 x floatvector.
name|INSERTPS
block|,
comment|/// Insert the lower 8-bits of a 32-bit value to a vector,
comment|/// corresponds to X86::PINSRB.
name|PINSRB
block|,
comment|/// Insert the lower 16-bits of a 32-bit value to a vector,
comment|/// corresponds to X86::PINSRW.
name|PINSRW
block|,
name|MMX_PINSRW
block|,
comment|/// Shuffle 16 8-bit values within a vector.
name|PSHUFB
block|,
comment|/// Compute Sum of Absolute Differences.
name|PSADBW
block|,
comment|/// Compute Double Block Packed Sum-Absolute-Differences
name|DBPSADBW
block|,
comment|/// Bitwise Logical AND NOT of Packed FP values.
name|ANDNP
block|,
comment|/// Copy integer sign.
name|PSIGN
block|,
comment|/// Blend where the selector is an immediate.
name|BLENDI
block|,
comment|/// Blend where the condition has been shrunk.
comment|/// This is used to emphasize that the condition mask is
comment|/// no more valid for generic VSELECT optimizations.
name|SHRUNKBLEND
block|,
comment|/// Combined add and sub on an FP vector.
name|ADDSUB
block|,
comment|//  FP vector ops with rounding mode.
name|FADD_RND
block|,
name|FSUB_RND
block|,
name|FMUL_RND
block|,
name|FDIV_RND
block|,
name|FMAX_RND
block|,
name|FMIN_RND
block|,
name|FSQRT_RND
block|,
comment|// FP vector get exponent
name|FGETEXP_RND
block|,
comment|// Extract Normalized Mantissas
name|VGETMANT
block|,
comment|// FP Scale
name|SCALEF
block|,
comment|// Integer add/sub with unsigned saturation.
name|ADDUS
block|,
name|SUBUS
block|,
comment|// Integer add/sub with signed saturation.
name|ADDS
block|,
name|SUBS
block|,
comment|// Unsigned Integer average
name|AVG
block|,
comment|/// Integer horizontal add.
name|HADD
block|,
comment|/// Integer horizontal sub.
name|HSUB
block|,
comment|/// Floating point horizontal add.
name|FHADD
block|,
comment|/// Floating point horizontal sub.
name|FHSUB
block|,
comment|// Integer absolute value
name|ABS
block|,
comment|// Detect Conflicts Within a Vector
name|CONFLICT
block|,
comment|/// Floating point max and min.
name|FMAX
block|,
name|FMIN
block|,
comment|/// Commutative FMIN and FMAX.
name|FMAXC
block|,
name|FMINC
block|,
comment|/// Floating point reciprocal-sqrt and reciprocal approximation.
comment|/// Note that these typically require refinement
comment|/// in order to obtain suitable precision.
name|FRSQRT
block|,
name|FRCP
block|,
comment|// Thread Local Storage.
name|TLSADDR
block|,
comment|// Thread Local Storage. A call to get the start address
comment|// of the TLS block for the current module.
name|TLSBASEADDR
block|,
comment|// Thread Local Storage.  When calling to an OS provided
comment|// thunk at the address from an earlier relocation.
name|TLSCALL
block|,
comment|// Exception Handling helpers.
name|EH_RETURN
block|,
comment|// SjLj exception handling setjmp.
name|EH_SJLJ_SETJMP
block|,
comment|// SjLj exception handling longjmp.
name|EH_SJLJ_LONGJMP
block|,
comment|/// Tail call return. See X86TargetLowering::LowerCall for
comment|/// the list of operands.
name|TC_RETURN
block|,
comment|// Vector move to low scalar and zero higher vector elements.
name|VZEXT_MOVL
block|,
comment|// Vector integer zero-extend.
name|VZEXT
block|,
comment|// Vector integer signed-extend.
name|VSEXT
block|,
comment|// Vector integer truncate.
name|VTRUNC
block|,
comment|// Vector integer truncate with unsigned/signed saturation.
name|VTRUNCUS
block|,
name|VTRUNCS
block|,
comment|// Vector FP extend.
name|VFPEXT
block|,
comment|// Vector FP round.
name|VFPROUND
block|,
comment|// Vector signed/unsigned integer to double.
name|CVTDQ2PD
block|,
name|CVTUDQ2PD
block|,
comment|// Convert a vector to mask, set bits base on MSB.
name|CVT2MASK
block|,
comment|// 128-bit vector logical left / right shift
name|VSHLDQ
block|,
name|VSRLDQ
block|,
comment|// Vector shift elements
name|VSHL
block|,
name|VSRL
block|,
name|VSRA
block|,
comment|// Vector shift elements by immediate
name|VSHLI
block|,
name|VSRLI
block|,
name|VSRAI
block|,
comment|// Bit rotate by immediate
name|VROTLI
block|,
name|VROTRI
block|,
comment|// Vector packed double/float comparison.
name|CMPP
block|,
comment|// Vector integer comparisons.
name|PCMPEQ
block|,
name|PCMPGT
block|,
comment|// Vector integer comparisons, the result is in a mask vector.
name|PCMPEQM
block|,
name|PCMPGTM
block|,
comment|/// Vector comparison generating mask bits for fp and
comment|/// integer signed and unsigned data types.
name|CMPM
block|,
name|CMPMU
block|,
comment|// Vector comparison with rounding mode for FP values
name|CMPM_RND
block|,
comment|// Arithmetic operations with FLAGS results.
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
comment|// Bit field extract
name|UMUL
block|,
comment|// LOW, HI, FLAGS = umul LHS, RHS
comment|// 8-bit SMUL/UMUL - AX, FLAGS = smul8/umul8 AL, RHS
name|SMUL8
block|,
name|UMUL8
block|,
comment|// 8-bit divrem that zero-extend the high result (AH).
name|UDIVREM8_ZEXT_HREG
block|,
name|SDIVREM8_SEXT_HREG
block|,
comment|// X86-specific multiply by immediate.
name|MUL_IMM
block|,
comment|// Vector bitwise comparisons.
name|PTEST
block|,
comment|// Vector packed fp sign bitwise comparisons.
name|TESTP
block|,
comment|// Vector "test" in AVX-512, the result is in a mask vector.
name|TESTM
block|,
name|TESTNM
block|,
comment|// OR/AND test for masks
name|KORTEST
block|,
name|KTEST
block|,
comment|// Several flavors of instructions with vector shuffle behaviors.
name|PACKSS
block|,
name|PACKUS
block|,
comment|// Intra-lane alignr
name|PALIGNR
block|,
comment|// AVX512 inter-lane alignr
name|VALIGN
block|,
name|PSHUFD
block|,
name|PSHUFHW
block|,
name|PSHUFLW
block|,
name|SHUFP
block|,
comment|//Shuffle Packed Values at 128-bit granularity
name|SHUF128
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
name|VPERMILPV
block|,
name|VPERMILPI
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
comment|// Bitwise ternary logic
name|VPTERNLOG
block|,
comment|// Fix Up Special Packed Float32/64 values
name|VFIXUPIMM
block|,
comment|// Range Restriction Calculation For Packed Pairs of Float32/64 values
name|VRANGE
block|,
comment|// Reduce - Perform Reduction Transformation on scalar\packed FP
name|VREDUCE
block|,
comment|// RndScale - Round FP Values To Include A Given Number Of Fraction Bits
name|VRNDSCALE
block|,
comment|// VFPCLASS - Tests Types Of a FP Values for packed types.
name|VFPCLASS
block|,
comment|// VFPCLASSS - Tests Types Of a FP Values for scalar types.
name|VFPCLASSS
block|,
comment|// Broadcast scalar to vector
name|VBROADCAST
block|,
comment|// Broadcast mask to vector
name|VBROADCASTM
block|,
comment|// Broadcast subvector to vector
name|SUBV_BROADCAST
block|,
comment|// Insert/Extract vector element
name|VINSERT
block|,
name|VEXTRACT
block|,
comment|/// SSE4A Extraction and Insertion.
name|EXTRQI
block|,
name|INSERTQI
block|,
comment|// XOP variable/immediate rotations
name|VPROT
block|,
name|VPROTI
block|,
comment|// XOP arithmetic/logical shifts
name|VPSHA
block|,
name|VPSHL
block|,
comment|// XOP signed/unsigned integer comparisons
name|VPCOM
block|,
name|VPCOMU
block|,
comment|// Vector multiply packed unsigned doubleword integers
name|PMULUDQ
block|,
comment|// Vector multiply packed signed doubleword integers
name|PMULDQ
block|,
comment|// Vector Multiply Packed UnsignedIntegers with Round and Scale
name|MULHRS
block|,
comment|// Multiply and Add Packed Integers
name|VPMADDUBSW
block|,
name|VPMADDWD
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
comment|// FMA with rounding mode
name|FMADD_RND
block|,
name|FNMADD_RND
block|,
name|FMSUB_RND
block|,
name|FNMSUB_RND
block|,
name|FMADDSUB_RND
block|,
name|FMSUBADD_RND
block|,
comment|// Compress and expand
name|COMPRESS
block|,
name|EXPAND
block|,
comment|//Convert Unsigned/Integer to Scalar Floating-Point Value
comment|//with rounding mode
name|SINT_TO_FP_RND
block|,
name|UINT_TO_FP_RND
block|,
comment|// Vector float/double to signed/unsigned integer.
name|FP_TO_SINT_RND
block|,
name|FP_TO_UINT_RND
block|,
comment|// Save xmm argument registers to the stack, according to %al. An operator
comment|// is needed so that this can be expanded with control flow.
name|VASTART_SAVE_XMM_REGS
block|,
comment|// Windows's _chkstk call to do stack probing.
name|WIN_ALLOCA
block|,
comment|// For allocating variable amounts of stack space when using
comment|// segmented stacks. Check if the current stacklet has enough space, and
comment|// falls back to heap allocation if not.
name|SEG_ALLOCA
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
comment|// Store FP status word into i16 register.
name|FNSTSW16r
block|,
comment|// Store contents of %ah into %eflags.
name|SAHF
block|,
comment|// Get a random integer and indicate whether it is valid in CF.
name|RDRAND
block|,
comment|// Get a NIST SP800-90B& C compliant random integer and
comment|// indicate whether it is valid in CF.
name|RDSEED
block|,
name|PCMPISTRI
block|,
name|PCMPESTRI
block|,
comment|// Test if in transactional execution.
name|XTEST
block|,
comment|// ERI instructions
name|RSQRT28
block|,
name|RCP28
block|,
name|EXP2
block|,
comment|// Compare and swap.
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
comment|// Load, scalar_to_vector, and zero extend.
name|VZEXT_LOAD
block|,
comment|// Store FP control world into i16 memory.
name|FNSTCW16m
block|,
comment|/// This instruction implements FP_TO_SINT with the
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
comment|/// This instruction implements SINT_TO_FP with the
comment|/// integer source in memory and FP reg result.  This corresponds to the
comment|/// X86::FILD*m instructions. It has three inputs (token chain, address,
comment|/// and source type) and two outputs (FP value and token chain). FILD_FLAG
comment|/// also produces a flag).
name|FILD
block|,
name|FILD_FLAG
block|,
comment|/// This instruction implements an extending load to FP stack slots.
comment|/// This corresponds to the X86::FLD32m / X86::FLD64m. It takes a chain
comment|/// operand, ptr to load from, and a ValueType node indicating the type
comment|/// to load to.
name|FLD
block|,
comment|/// This instruction implements a truncating store to FP stack
comment|/// slots. This corresponds to the X86::FST32m / X86::FST64m. It takes a
comment|/// chain operand, value to store, address, and a ValueType to store it
comment|/// as.
name|FST
block|,
comment|/// This instruction grabs the address of the next argument
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
comment|/// Return true if the specified
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
comment|/// Return true if the specified
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
comment|/// Return true if the specified
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
comment|/// Return true if the specified
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
comment|/// Return the appropriate
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
comment|/// Return the appropriate
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
comment|/// Return the appropriate
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
comment|/// Return the appropriate
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
comment|/// Returns true if Elt is a constant zero or floating point constant +0.0.
name|bool
name|isZeroNode
parameter_list|(
name|SDValue
name|Elt
parameter_list|)
function_decl|;
comment|/// Returns true of the given offset can be
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
comment|/// Determines whether the callee is required to pop its
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
comment|//  X86 Implementation of the TargetLowering interface
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
specifier|const
name|X86TargetMachine
operator|&
name|TM
argument_list|,
specifier|const
name|X86Subtarget
operator|&
name|STI
argument_list|)
block|;
name|unsigned
name|getJumpTableEncoding
argument_list|()
specifier|const
name|override
block|;
name|bool
name|useSoftFloat
argument_list|()
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
comment|/// Returns relocation base for the given PIC jumptable.
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
comment|/// Return the desired alignment for ByVal aggregate
comment|/// function arguments in the caller parameter area. For X86, aggregates
comment|/// that contains are placed at 16-byte boundaries while the rest are at
comment|/// 4-byte boundaries.
name|unsigned
name|getByValTypeAlignment
argument_list|(
argument|Type *Ty
argument_list|,
argument|const DataLayout&DL
argument_list|)
specifier|const
name|override
block|;
comment|/// Returns the target specific optimal type for load
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
comment|/// Returns true if it's safe to use load / store of the
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
comment|/// Returns true if the target allows unaligned memory accesses of the
comment|/// specified type. Returns whether it is "fast" in the last argument.
name|bool
name|allowsMisalignedMemoryAccesses
argument_list|(
argument|EVT VT
argument_list|,
argument|unsigned AS
argument_list|,
argument|unsigned Align
argument_list|,
argument|bool *Fast
argument_list|)
specifier|const
name|override
block|;
comment|/// Provide custom lowering hooks for some operations.
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
comment|/// Replace the results of node with an illegal result
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
comment|/// Return true if the target has native support for
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
comment|/// Return true if the target has native support for the
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
comment|/// Return true if the MachineFunction contains a COPY which would imply
comment|/// HasOpaqueSPAdjustment.
name|bool
name|hasCopyImplyingStackAdjustment
argument_list|(
argument|MachineFunction *MF
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
comment|/// This method returns the name of a target specific DAG node.
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
comment|/// Return the value type to use for ISD::SETCC.
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
comment|/// Determine which of the bits specified in Mask are known to be either
comment|/// zero or one and return them in the KnownZero/KnownOne bitsets.
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
comment|/// Determine the number of bits in the operation that are sign bits.
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
comment|/// Lower the specified operand into the Ops vector. If it is invalid, don't
comment|/// add anything to Ops. If hasMemory is true it means one of the asm
comment|/// constraint of the inline asm instruction being processed is 'm'.
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
literal|"i"
condition|)
return|return
name|InlineAsm
operator|::
name|Constraint_i
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
literal|"v"
condition|)
return|return
name|InlineAsm
operator|::
name|Constraint_v
return|;
elseif|else
if|if
condition|(
name|ConstraintCode
operator|==
literal|"X"
condition|)
return|return
name|InlineAsm
operator|::
name|Constraint_X
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
comment|/// Given a physical register constraint
comment|/// (e.g. {edx}), return the register number and the register class for the
comment|/// register.  This should only be used for C_Register constraints.  On
comment|/// error, this returns a register number of 0.
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
comment|/// Return true if the addressing mode represented
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
comment|/// Return true if the specified immediate is legal
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
comment|/// Return true if the specified immediate is legal
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
comment|/// \brief Return the cost of the scaling factor used in the addressing
comment|/// mode represented by AM for this target, for a load/store
comment|/// of the specified type.
comment|/// If the AM is supported, the return value must be>= 0.
comment|/// If the AM is not supported, it returns a negative value.
name|int
name|getScalingFactorCost
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
name|isVectorShiftByScalarCheap
argument_list|(
name|Type
operator|*
name|Ty
argument_list|)
decl|const
name|override
decl_stmt|;
comment|/// Return true if it's free to truncate a value of
comment|/// type Ty1 to type Ty2. e.g. On x86 it's free to truncate a i32 value in
comment|/// register EAX to i16 by referencing its sub-register AX.
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
name|allowTruncateForTailCall
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
comment|/// Return true if any actual instruction that defines a
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
name|isZExtFree
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
comment|/// Return true if folding a vector load into ExtVal (a sign, zero, or any
comment|/// extend node) is profitable.
name|bool
name|isVectorLoadExtDesirable
argument_list|(
name|SDValue
argument_list|)
decl|const
name|override
decl_stmt|;
comment|/// Return true if an FMA operation is faster than a pair of fmul and fadd
comment|/// instructions. fmuladd intrinsics will be expanded to FMAs when this
comment|/// method returns true, otherwise fmuladd is expanded to fmul + fadd.
name|bool
name|isFMAFasterThanFMulAndFAdd
argument_list|(
name|EVT
name|VT
argument_list|)
decl|const
name|override
decl_stmt|;
comment|/// Return true if it's profitable to narrow
comment|/// operations of type VT1 to VT2. e.g. on x86, it's profitable to narrow
comment|/// from i32 to i8 but not from i32 to i16.
name|bool
name|isNarrowingProfitable
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
comment|/// Given an intrinsic, checks if on the target the intrinsic will need to map
comment|/// to a MemIntrinsicNode (touches memory). If this is the case, it returns
comment|/// true and stores the intrinsic information into the IntrinsicInfo that was
comment|/// passed to the function.
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
comment|/// Returns true if the target can instruction select the
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
comment|/// Targets can use this to indicate that they only support *some*
comment|/// VECTOR_SHUFFLE operations, those with specific masks. By default, if a
comment|/// target supports the VECTOR_SHUFFLE node, all mask values are assumed to
comment|/// be legal.
name|bool
name|isShuffleMaskLegal
argument_list|(
specifier|const
name|SmallVectorImpl
operator|<
name|int
operator|>
operator|&
name|Mask
argument_list|,
name|EVT
name|VT
argument_list|)
decl|const
name|override
decl_stmt|;
comment|/// Similar to isShuffleMaskLegal. This is used by Targets can use this to
comment|/// indicate if there is a suitable VECTOR_SHUFFLE that can be used to
comment|/// replace a VAND with a constant pool entry.
name|bool
name|isVectorClearMaskLegal
argument_list|(
specifier|const
name|SmallVectorImpl
operator|<
name|int
operator|>
operator|&
name|Mask
argument_list|,
name|EVT
name|VT
argument_list|)
decl|const
name|override
decl_stmt|;
comment|/// If true, then instruction selection should
comment|/// seek to shrink the FP constant of the specified type to a smaller type
comment|/// in order to save space and / or reduce runtime.
name|bool
name|ShouldShrinkFPConstant
argument_list|(
name|EVT
name|VT
argument_list|)
decl|const
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
comment|/// Return true if we believe it is correct and profitable to reduce the
comment|/// load node to a smaller type.
name|bool
name|shouldReduceLoadWidth
argument_list|(
name|SDNode
operator|*
name|Load
argument_list|,
name|ISD
operator|::
name|LoadExtType
name|ExtTy
argument_list|,
name|EVT
name|NewVT
argument_list|)
decl|const
name|override
decl_stmt|;
comment|/// Return true if the specified scalar FP type is computed in an SSE
comment|/// register, not on the X87 floating point stack.
name|bool
name|isScalarFPTypeInSSEReg
argument_list|(
name|EVT
name|VT
argument_list|)
decl|const
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
comment|/// Return true if EXTRACT_SUBVECTOR is cheap for this result type
comment|/// with this index.
name|bool
name|isExtractSubvectorCheap
argument_list|(
name|EVT
name|ResVT
argument_list|,
name|unsigned
name|Index
argument_list|)
decl|const
name|override
decl_stmt|;
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
comment|/// This method returns a target specific FastISel object,
comment|/// or null if the target does not support "fast" ISel.
name|FastISel
modifier|*
name|createFastISel
argument_list|(
name|FunctionLoweringInfo
operator|&
name|funcInfo
argument_list|,
specifier|const
name|TargetLibraryInfo
operator|*
name|libInfo
argument_list|)
decl|const
name|override
decl_stmt|;
comment|/// Return true if the target stores stack protector cookies at a fixed
comment|/// offset in some non-standard address space, and populates the address
comment|/// space and offset as appropriate.
name|bool
name|getStackCookieLocation
argument_list|(
name|unsigned
operator|&
name|AddressSpace
argument_list|,
name|unsigned
operator|&
name|Offset
argument_list|)
decl|const
name|override
decl_stmt|;
comment|/// Return true if the target stores SafeStack pointer at a fixed offset in
comment|/// some non-standard address space, and populates the address space and
comment|/// offset as appropriate.
name|Value
modifier|*
name|getSafeStackPointerLocation
argument_list|(
name|IRBuilder
operator|<
operator|>
operator|&
name|IRB
argument_list|)
decl|const
name|override
decl_stmt|;
name|SDValue
name|BuildFILD
argument_list|(
name|SDValue
name|Op
argument_list|,
name|EVT
name|SrcVT
argument_list|,
name|SDValue
name|Chain
argument_list|,
name|SDValue
name|StackSlot
argument_list|,
name|SelectionDAG
operator|&
name|DAG
argument_list|)
decl|const
decl_stmt|;
name|bool
name|isNoopAddrSpaceCast
argument_list|(
name|unsigned
name|SrcAS
argument_list|,
name|unsigned
name|DestAS
argument_list|)
decl|const
name|override
decl_stmt|;
name|bool
name|useLoadStackGuardNode
argument_list|()
specifier|const
name|override
expr_stmt|;
comment|/// \brief Customize the preferred legalization strategy for certain types.
name|LegalizeTypeAction
name|getPreferredVectorAction
argument_list|(
name|EVT
name|VT
argument_list|)
decl|const
name|override
decl_stmt|;
name|bool
name|isIntDivCheap
argument_list|(
name|EVT
name|VT
argument_list|,
name|AttributeSet
name|Attr
argument_list|)
decl|const
name|override
decl_stmt|;
name|protected
label|:
name|std
operator|::
name|pair
operator|<
specifier|const
name|TargetRegisterClass
operator|*
operator|,
name|uint8_t
operator|>
name|findRepresentativeClass
argument_list|(
argument|const TargetRegisterInfo *TRI
argument_list|,
argument|MVT VT
argument_list|)
specifier|const
name|override
expr_stmt|;
name|private
label|:
comment|/// Keep a pointer to the X86Subtarget around so that we can
comment|/// make the right decision when generating code for different targets.
specifier|const
name|X86Subtarget
modifier|*
name|Subtarget
decl_stmt|;
comment|/// Select between SSE or x87 floating point ops.
comment|/// When SSE is available, use it for f32 operations.
comment|/// When SSE2 is available, use it for f64 operations.
name|bool
name|X86ScalarSSEf32
decl_stmt|;
name|bool
name|X86ScalarSSEf64
decl_stmt|;
comment|/// A list of legal FP immediates.
name|std
operator|::
name|vector
operator|<
name|APFloat
operator|>
name|LegalFPImmediates
expr_stmt|;
comment|/// Indicate that this x86 target can instruction
comment|/// select the specified FP immediate natively.
name|void
name|addLegalFPImmediate
parameter_list|(
specifier|const
name|APFloat
modifier|&
name|Imm
parameter_list|)
block|{
name|LegalFPImmediates
operator|.
name|push_back
argument_list|(
name|Imm
argument_list|)
expr_stmt|;
block|}
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
name|SDLoc
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
name|SDValue
name|LowerMemArgument
argument_list|(
name|SDValue
name|Chain
argument_list|,
name|CallingConv
operator|::
name|ID
name|CallConv
argument_list|,
specifier|const
name|SmallVectorImpl
operator|<
name|ISD
operator|::
name|InputArg
operator|>
operator|&
name|ArgInfo
argument_list|,
name|SDLoc
name|dl
argument_list|,
name|SelectionDAG
operator|&
name|DAG
argument_list|,
specifier|const
name|CCValAssign
operator|&
name|VA
argument_list|,
name|MachineFrameInfo
operator|*
name|MFI
argument_list|,
name|unsigned
name|i
argument_list|)
decl|const
decl_stmt|;
name|SDValue
name|LowerMemOpCallTo
argument_list|(
name|SDValue
name|Chain
argument_list|,
name|SDValue
name|StackPtr
argument_list|,
name|SDValue
name|Arg
argument_list|,
name|SDLoc
name|dl
argument_list|,
name|SelectionDAG
operator|&
name|DAG
argument_list|,
specifier|const
name|CCValAssign
operator|&
name|VA
argument_list|,
name|ISD
operator|::
name|ArgFlagsTy
name|Flags
argument_list|)
decl|const
decl_stmt|;
comment|// Call lowering helpers.
comment|/// Check whether the call is eligible for tail call optimization. Targets
comment|/// that want to do tail call optimization should implement this function.
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
name|bool
name|isCalleeStructRet
argument_list|,
name|bool
name|isCallerStructRet
argument_list|,
name|Type
operator|*
name|RetTy
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
name|SelectionDAG
operator|&
name|DAG
argument_list|)
decl|const
decl_stmt|;
name|SDValue
name|EmitTailCallLoadRetAddr
argument_list|(
name|SelectionDAG
operator|&
name|DAG
argument_list|,
name|SDValue
operator|&
name|OutRetAddr
argument_list|,
name|SDValue
name|Chain
argument_list|,
name|bool
name|IsTailCall
argument_list|,
name|bool
name|Is64Bit
argument_list|,
name|int
name|FPDiff
argument_list|,
name|SDLoc
name|dl
argument_list|)
decl|const
decl_stmt|;
name|unsigned
name|GetAlignedArgumentStackSize
argument_list|(
name|unsigned
name|StackSize
argument_list|,
name|SelectionDAG
operator|&
name|DAG
argument_list|)
decl|const
decl_stmt|;
name|std
operator|::
name|pair
operator|<
name|SDValue
operator|,
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
expr_stmt|;
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
name|SDValue
name|LowerBUILD_VECTORvXi1
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
name|SDValue
name|LowerVSELECT
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
name|SDValue
name|ExtractBitFromMaskVector
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
name|SDValue
name|InsertBitToMaskVector
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
name|SDValue
name|LowerGlobalAddress
argument_list|(
specifier|const
name|GlobalValue
operator|*
name|GV
argument_list|,
name|SDLoc
name|dl
argument_list|,
name|int64_t
name|Offset
argument_list|,
name|SelectionDAG
operator|&
name|DAG
argument_list|)
decl|const
decl_stmt|;
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
name|SDValue
name|LowerExternalSymbol
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
name|SDValue
name|LowerSINT_TO_FP
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
name|SDValue
name|LowerUINT_TO_FP
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
name|SDValue
name|LowerUINT_TO_FP_i64
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
name|SDValue
name|LowerUINT_TO_FP_i32
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
name|SDValue
name|lowerUINT_TO_FP_vec
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
name|SDValue
name|LowerFP_TO_SINT
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
name|SDValue
name|LowerFP_TO_UINT
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
name|SDValue
name|LowerToBT
argument_list|(
name|SDValue
name|And
argument_list|,
name|ISD
operator|::
name|CondCode
name|CC
argument_list|,
name|SDLoc
name|dl
argument_list|,
name|SelectionDAG
operator|&
name|DAG
argument_list|)
decl|const
decl_stmt|;
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
name|SDValue
name|LowerSETCCE
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
name|SDValue
name|LowerSELECT
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
name|SDValue
name|LowerBRCOND
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
name|SDValue
name|LowerFRAME_TO_ARGS_OFFSET
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
name|SDValue
name|LowerEH_RETURN
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
name|SDValue
name|LowerWin64_i128OP
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
name|SDValue
name|LowerGC_TRANSITION_START
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
name|SDValue
name|LowerGC_TRANSITION_END
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
name|SDLoc
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
name|SDValue
name|LowerCall
argument_list|(
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
name|SDLoc
name|dl
argument_list|,
name|SelectionDAG
operator|&
name|DAG
argument_list|)
decl|const
name|override
decl_stmt|;
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
name|bool
name|isUsedByReturnOnly
argument_list|(
name|SDNode
operator|*
name|N
argument_list|,
name|SDValue
operator|&
name|Chain
argument_list|)
decl|const
name|override
decl_stmt|;
name|bool
name|mayBeEmittedAsTailCall
argument_list|(
name|CallInst
operator|*
name|CI
argument_list|)
decl|const
name|override
decl_stmt|;
name|EVT
name|getTypeForExtArgOrReturn
argument_list|(
name|LLVMContext
operator|&
name|Context
argument_list|,
name|EVT
name|VT
argument_list|,
name|ISD
operator|::
name|NodeType
name|ExtendKind
argument_list|)
decl|const
name|override
decl_stmt|;
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
name|TargetLoweringBase
operator|::
name|AtomicExpansionKind
name|shouldExpandAtomicLoadInIR
argument_list|(
argument|LoadInst *SI
argument_list|)
specifier|const
name|override
expr_stmt|;
name|bool
name|shouldExpandAtomicStoreInIR
argument_list|(
name|StoreInst
operator|*
name|SI
argument_list|)
decl|const
name|override
decl_stmt|;
name|TargetLoweringBase
operator|::
name|AtomicExpansionKind
name|shouldExpandAtomicRMWInIR
argument_list|(
argument|AtomicRMWInst *AI
argument_list|)
specifier|const
name|override
expr_stmt|;
name|LoadInst
modifier|*
name|lowerIdempotentRMWIntoFencedLoad
argument_list|(
name|AtomicRMWInst
operator|*
name|AI
argument_list|)
decl|const
name|override
decl_stmt|;
name|bool
name|needsCmpXchgNb
argument_list|(
name|Type
operator|*
name|MemType
argument_list|)
decl|const
decl_stmt|;
comment|// Utility function to emit the low-level va_arg code for X86-64.
name|MachineBasicBlock
modifier|*
name|EmitVAARG64WithCustomInserter
argument_list|(
name|MachineInstr
operator|*
name|MI
argument_list|,
name|MachineBasicBlock
operator|*
name|MBB
argument_list|)
decl|const
decl_stmt|;
comment|/// Utility function to emit the xmm reg save portion of va_start.
name|MachineBasicBlock
modifier|*
name|EmitVAStartSaveXMMRegsWithCustomInserter
argument_list|(
name|MachineInstr
operator|*
name|BInstr
argument_list|,
name|MachineBasicBlock
operator|*
name|BB
argument_list|)
decl|const
decl_stmt|;
name|MachineBasicBlock
modifier|*
name|EmitLoweredSelect
argument_list|(
name|MachineInstr
operator|*
name|I
argument_list|,
name|MachineBasicBlock
operator|*
name|BB
argument_list|)
decl|const
decl_stmt|;
name|MachineBasicBlock
modifier|*
name|EmitLoweredAtomicFP
argument_list|(
name|MachineInstr
operator|*
name|I
argument_list|,
name|MachineBasicBlock
operator|*
name|BB
argument_list|)
decl|const
decl_stmt|;
name|MachineBasicBlock
modifier|*
name|EmitLoweredWinAlloca
argument_list|(
name|MachineInstr
operator|*
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
name|EmitLoweredCatchRet
argument_list|(
name|MachineInstr
operator|*
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
name|EmitLoweredCatchPad
argument_list|(
name|MachineInstr
operator|*
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
name|EmitLoweredSegAlloca
argument_list|(
name|MachineInstr
operator|*
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
name|EmitLoweredTLSAddr
argument_list|(
name|MachineInstr
operator|*
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
name|EmitLoweredTLSCall
argument_list|(
name|MachineInstr
operator|*
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
name|emitEHSjLjSetJmp
argument_list|(
name|MachineInstr
operator|*
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
operator|*
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
name|emitFMA3Instr
argument_list|(
name|MachineInstr
operator|*
name|MI
argument_list|,
name|MachineBasicBlock
operator|*
name|MBB
argument_list|)
decl|const
decl_stmt|;
comment|/// Emit nodes that will be selected as "test Op0,Op0", or something
comment|/// equivalent, for use with the given x86 condition code.
name|SDValue
name|EmitTest
argument_list|(
name|SDValue
name|Op0
argument_list|,
name|unsigned
name|X86CC
argument_list|,
name|SDLoc
name|dl
argument_list|,
name|SelectionDAG
operator|&
name|DAG
argument_list|)
decl|const
decl_stmt|;
comment|/// Emit nodes that will be selected as "cmp Op0,Op1", or something
comment|/// equivalent, for use with the given x86 condition code.
name|SDValue
name|EmitCmp
argument_list|(
name|SDValue
name|Op0
argument_list|,
name|SDValue
name|Op1
argument_list|,
name|unsigned
name|X86CC
argument_list|,
name|SDLoc
name|dl
argument_list|,
name|SelectionDAG
operator|&
name|DAG
argument_list|)
decl|const
decl_stmt|;
comment|/// Convert a comparison if required by the subtarget.
name|SDValue
name|ConvertCmpIfNecessary
argument_list|(
name|SDValue
name|Cmp
argument_list|,
name|SelectionDAG
operator|&
name|DAG
argument_list|)
decl|const
decl_stmt|;
comment|/// Use rsqrt* to speed up sqrt calculations.
name|SDValue
name|getRsqrtEstimate
argument_list|(
name|SDValue
name|Operand
argument_list|,
name|DAGCombinerInfo
operator|&
name|DCI
argument_list|,
name|unsigned
operator|&
name|RefinementSteps
argument_list|,
name|bool
operator|&
name|UseOneConstNR
argument_list|)
decl|const
name|override
decl_stmt|;
comment|/// Use rcp* to speed up fdiv calculations.
name|SDValue
name|getRecipEstimate
argument_list|(
name|SDValue
name|Operand
argument_list|,
name|DAGCombinerInfo
operator|&
name|DCI
argument_list|,
name|unsigned
operator|&
name|RefinementSteps
argument_list|)
decl|const
name|override
decl_stmt|;
comment|/// Reassociate floating point divisions into multiply by reciprocal.
name|unsigned
name|combineRepeatedFPDivisors
argument_list|()
specifier|const
name|override
expr_stmt|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_decl_stmt
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
end_decl_stmt

begin_endif
unit|}
endif|#
directive|endif
end_endif

begin_comment
comment|// X86ISELLOWERING_H
end_comment

end_unit

