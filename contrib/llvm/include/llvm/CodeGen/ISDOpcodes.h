begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- llvm/CodeGen/ISDOpcodes.h - CodeGen opcodes -------------*- C++ -*-===//
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
comment|// This file declares codegen opcodes and related utilities.
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
name|LLVM_CODEGEN_ISDOPCODES_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CODEGEN_ISDOPCODES_H
end_define

begin_decl_stmt
name|namespace
name|llvm
block|{
comment|/// ISD namespace - This namespace contains an enum which represents all of the
comment|/// SelectionDAG node types and value types.
comment|///
name|namespace
name|ISD
block|{
comment|//===--------------------------------------------------------------------===//
comment|/// ISD::NodeType enum - This enum defines the target-independent operators
comment|/// for a SelectionDAG.
comment|///
comment|/// Targets may also define target-dependent operator codes for SDNodes. For
comment|/// example, on x86, these are the enum values in the X86ISD namespace.
comment|/// Targets should aim to use target-independent operators to model their
comment|/// instruction sets as much as possible, and only use target-dependent
comment|/// operators when they have special requirements.
comment|///
comment|/// Finally, during and after selection proper, SNodes may use special
comment|/// operator codes that correspond directly with MachineInstr opcodes. These
comment|/// are used to represent selected instructions. See the isMachineOpcode()
comment|/// and getMachineOpcode() member functions of SDNode.
comment|///
enum|enum
name|NodeType
block|{
comment|// DELETED_NODE - This is an illegal value that is used to catch
comment|// errors.  This opcode is not a legal opcode for any node.
name|DELETED_NODE
block|,
comment|// EntryToken - This is the marker used to indicate the start of the region.
name|EntryToken
block|,
comment|// TokenFactor - This node takes multiple tokens as input and produces a
comment|// single token result.  This is used to represent the fact that the operand
comment|// operators are independent of each other.
name|TokenFactor
block|,
comment|// AssertSext, AssertZext - These nodes record if a register contains a
comment|// value that has already been zero or sign extended from a narrower type.
comment|// These nodes take two operands.  The first is the node that has already
comment|// been extended, and the second is a value type node indicating the width
comment|// of the extension
name|AssertSext
block|,
name|AssertZext
block|,
comment|// Various leaf nodes.
name|BasicBlock
block|,
name|VALUETYPE
block|,
name|CONDCODE
block|,
name|Register
block|,
name|Constant
block|,
name|ConstantFP
block|,
name|GlobalAddress
block|,
name|GlobalTLSAddress
block|,
name|FrameIndex
block|,
name|JumpTable
block|,
name|ConstantPool
block|,
name|ExternalSymbol
block|,
name|BlockAddress
block|,
comment|// The address of the GOT
name|GLOBAL_OFFSET_TABLE
block|,
comment|// FRAMEADDR, RETURNADDR - These nodes represent llvm.frameaddress and
comment|// llvm.returnaddress on the DAG.  These nodes take one operand, the index
comment|// of the frame or return address to return.  An index of zero corresponds
comment|// to the current function's frame or return address, an index of one to the
comment|// parent's frame or return address, and so on.
name|FRAMEADDR
block|,
name|RETURNADDR
block|,
comment|// FRAME_TO_ARGS_OFFSET - This node represents offset from frame pointer to
comment|// first (possible) on-stack argument. This is needed for correct stack
comment|// adjustment during unwind.
name|FRAME_TO_ARGS_OFFSET
block|,
comment|// RESULT, OUTCHAIN = EXCEPTIONADDR(INCHAIN) - This node represents the
comment|// address of the exception block on entry to an landing pad block.
name|EXCEPTIONADDR
block|,
comment|// RESULT, OUTCHAIN = LSDAADDR(INCHAIN) - This node represents the
comment|// address of the Language Specific Data Area for the enclosing function.
name|LSDAADDR
block|,
comment|// RESULT, OUTCHAIN = EHSELECTION(INCHAIN, EXCEPTION) - This node represents
comment|// the selection index of the exception thrown.
name|EHSELECTION
block|,
comment|// OUTCHAIN = EH_RETURN(INCHAIN, OFFSET, HANDLER) - This node represents
comment|// 'eh_return' gcc dwarf builtin, which is used to return from
comment|// exception. The general meaning is: adjust stack by OFFSET and pass
comment|// execution to HANDLER. Many platform-related details also :)
name|EH_RETURN
block|,
comment|// OUTCHAIN = EH_SJLJ_SETJMP(INCHAIN, buffer)
comment|// This corresponds to the eh.sjlj.setjmp intrinsic.
comment|// It takes an input chain and a pointer to the jump buffer as inputs
comment|// and returns an outchain.
name|EH_SJLJ_SETJMP
block|,
comment|// OUTCHAIN = EH_SJLJ_LONGJMP(INCHAIN, buffer)
comment|// This corresponds to the eh.sjlj.longjmp intrinsic.
comment|// It takes an input chain and a pointer to the jump buffer as inputs
comment|// and returns an outchain.
name|EH_SJLJ_LONGJMP
block|,
comment|// OUTCHAIN = EH_SJLJ_DISPATCHSETUP(INCHAIN, context)
comment|// This corresponds to the eh.sjlj.dispatchsetup intrinsic. It takes an
comment|// input chain and a pointer to the sjlj function context as inputs and
comment|// returns an outchain. By default, this does nothing. Targets can lower
comment|// this to unwind setup code if needed.
name|EH_SJLJ_DISPATCHSETUP
block|,
comment|// TargetConstant* - Like Constant*, but the DAG does not do any folding,
comment|// simplification, or lowering of the constant. They are used for constants
comment|// which are known to fit in the immediate fields of their users, or for
comment|// carrying magic numbers which are not values which need to be materialized
comment|// in registers.
name|TargetConstant
block|,
name|TargetConstantFP
block|,
comment|// TargetGlobalAddress - Like GlobalAddress, but the DAG does no folding or
comment|// anything else with this node, and this is valid in the target-specific
comment|// dag, turning into a GlobalAddress operand.
name|TargetGlobalAddress
block|,
name|TargetGlobalTLSAddress
block|,
name|TargetFrameIndex
block|,
name|TargetJumpTable
block|,
name|TargetConstantPool
block|,
name|TargetExternalSymbol
block|,
name|TargetBlockAddress
block|,
comment|/// RESULT = INTRINSIC_WO_CHAIN(INTRINSICID, arg1, arg2, ...)
comment|/// This node represents a target intrinsic function with no side effects.
comment|/// The first operand is the ID number of the intrinsic from the
comment|/// llvm::Intrinsic namespace.  The operands to the intrinsic follow.  The
comment|/// node returns the result of the intrinsic.
name|INTRINSIC_WO_CHAIN
block|,
comment|/// RESULT,OUTCHAIN = INTRINSIC_W_CHAIN(INCHAIN, INTRINSICID, arg1, ...)
comment|/// This node represents a target intrinsic function with side effects that
comment|/// returns a result.  The first operand is a chain pointer.  The second is
comment|/// the ID number of the intrinsic from the llvm::Intrinsic namespace.  The
comment|/// operands to the intrinsic follow.  The node has two results, the result
comment|/// of the intrinsic and an output chain.
name|INTRINSIC_W_CHAIN
block|,
comment|/// OUTCHAIN = INTRINSIC_VOID(INCHAIN, INTRINSICID, arg1, arg2, ...)
comment|/// This node represents a target intrinsic function with side effects that
comment|/// does not return a result.  The first operand is a chain pointer.  The
comment|/// second is the ID number of the intrinsic from the llvm::Intrinsic
comment|/// namespace.  The operands to the intrinsic follow.
name|INTRINSIC_VOID
block|,
comment|// CopyToReg - This node has three operands: a chain, a register number to
comment|// set to this value, and a value.
name|CopyToReg
block|,
comment|// CopyFromReg - This node indicates that the input value is a virtual or
comment|// physical register that is defined outside of the scope of this
comment|// SelectionDAG.  The register is available from the RegisterSDNode object.
name|CopyFromReg
block|,
comment|// UNDEF - An undefined node
name|UNDEF
block|,
comment|// EXTRACT_ELEMENT - This is used to get the lower or upper (determined by
comment|// a Constant, which is required to be operand #1) half of the integer or
comment|// float value specified as operand #0.  This is only for use before
comment|// legalization, for values that will be broken into multiple registers.
name|EXTRACT_ELEMENT
block|,
comment|// BUILD_PAIR - This is the opposite of EXTRACT_ELEMENT in some ways.  Given
comment|// two values of the same integer value type, this produces a value twice as
comment|// big.  Like EXTRACT_ELEMENT, this can only be used before legalization.
name|BUILD_PAIR
block|,
comment|// MERGE_VALUES - This node takes multiple discrete operands and returns
comment|// them all as its individual results.  This nodes has exactly the same
comment|// number of inputs and outputs. This node is useful for some pieces of the
comment|// code generator that want to think about a single node with multiple
comment|// results, not multiple nodes.
name|MERGE_VALUES
block|,
comment|// Simple integer binary arithmetic operators.
name|ADD
block|,
name|SUB
block|,
name|MUL
block|,
name|SDIV
block|,
name|UDIV
block|,
name|SREM
block|,
name|UREM
block|,
comment|// SMUL_LOHI/UMUL_LOHI - Multiply two integers of type iN, producing
comment|// a signed/unsigned value of type i[2*N], and return the full value as
comment|// two results, each of type iN.
name|SMUL_LOHI
block|,
name|UMUL_LOHI
block|,
comment|// SDIVREM/UDIVREM - Divide two integers and produce both a quotient and
comment|// remainder result.
name|SDIVREM
block|,
name|UDIVREM
block|,
comment|// CARRY_FALSE - This node is used when folding other nodes,
comment|// like ADDC/SUBC, which indicate the carry result is always false.
name|CARRY_FALSE
block|,
comment|// Carry-setting nodes for multiple precision addition and subtraction.
comment|// These nodes take two operands of the same value type, and produce two
comment|// results.  The first result is the normal add or sub result, the second
comment|// result is the carry flag result.
name|ADDC
block|,
name|SUBC
block|,
comment|// Carry-using nodes for multiple precision addition and subtraction.  These
comment|// nodes take three operands: The first two are the normal lhs and rhs to
comment|// the add or sub, and the third is the input carry flag.  These nodes
comment|// produce two results; the normal result of the add or sub, and the output
comment|// carry flag.  These nodes both read and write a carry flag to allow them
comment|// to them to be chained together for add and sub of arbitrarily large
comment|// values.
name|ADDE
block|,
name|SUBE
block|,
comment|// RESULT, BOOL = [SU]ADDO(LHS, RHS) - Overflow-aware nodes for addition.
comment|// These nodes take two operands: the normal LHS and RHS to the add. They
comment|// produce two results: the normal result of the add, and a boolean that
comment|// indicates if an overflow occured (*not* a flag, because it may be stored
comment|// to memory, etc.).  If the type of the boolean is not i1 then the high
comment|// bits conform to getBooleanContents.
comment|// These nodes are generated from the llvm.[su]add.with.overflow intrinsics.
name|SADDO
block|,
name|UADDO
block|,
comment|// Same for subtraction
name|SSUBO
block|,
name|USUBO
block|,
comment|// Same for multiplication
name|SMULO
block|,
name|UMULO
block|,
comment|// Simple binary floating point operators.
name|FADD
block|,
name|FSUB
block|,
name|FMUL
block|,
name|FDIV
block|,
name|FREM
block|,
comment|// FCOPYSIGN(X, Y) - Return the value of X with the sign of Y.  NOTE: This
comment|// DAG node does not require that X and Y have the same type, just that they
comment|// are both floating point.  X and the result must have the same type.
comment|// FCOPYSIGN(f32, f64) is allowed.
name|FCOPYSIGN
block|,
comment|// INT = FGETSIGN(FP) - Return the sign bit of the specified floating point
comment|// value as an integer 0/1 value.
name|FGETSIGN
block|,
comment|/// BUILD_VECTOR(ELT0, ELT1, ELT2, ELT3,...) - Return a vector with the
comment|/// specified, possibly variable, elements.  The number of elements is
comment|/// required to be a power of two.  The types of the operands must all be
comment|/// the same and must match the vector element type, except that integer
comment|/// types are allowed to be larger than the element type, in which case
comment|/// the operands are implicitly truncated.
name|BUILD_VECTOR
block|,
comment|/// INSERT_VECTOR_ELT(VECTOR, VAL, IDX) - Returns VECTOR with the element
comment|/// at IDX replaced with VAL.  If the type of VAL is larger than the vector
comment|/// element type then VAL is truncated before replacement.
name|INSERT_VECTOR_ELT
block|,
comment|/// EXTRACT_VECTOR_ELT(VECTOR, IDX) - Returns a single element from VECTOR
comment|/// identified by the (potentially variable) element number IDX.  If the
comment|/// return type is an integer type larger than the element type of the
comment|/// vector, the result is extended to the width of the return type.
name|EXTRACT_VECTOR_ELT
block|,
comment|/// CONCAT_VECTORS(VECTOR0, VECTOR1, ...) - Given a number of values of
comment|/// vector type with the same length and element type, this produces a
comment|/// concatenated vector result value, with length equal to the sum of the
comment|/// lengths of the input vectors.
name|CONCAT_VECTORS
block|,
comment|/// INSERT_SUBVECTOR(VECTOR1, VECTOR2, IDX) - Returns a vector
comment|/// with VECTOR2 inserted into VECTOR1 at the (potentially
comment|/// variable) element number IDX, which must be a multiple of the
comment|/// VECTOR2 vector length.  The elements of VECTOR1 starting at
comment|/// IDX are overwritten with VECTOR2.  Elements IDX through
comment|/// vector_length(VECTOR2) must be valid VECTOR1 indices.
name|INSERT_SUBVECTOR
block|,
comment|/// EXTRACT_SUBVECTOR(VECTOR, IDX) - Returns a subvector from VECTOR (an
comment|/// vector value) starting with the element number IDX, which must be a
comment|/// constant multiple of the result vector length.
name|EXTRACT_SUBVECTOR
block|,
comment|/// VECTOR_SHUFFLE(VEC1, VEC2) - Returns a vector, of the same type as
comment|/// VEC1/VEC2.  A VECTOR_SHUFFLE node also contains an array of constant int
comment|/// values that indicate which value (or undef) each result element will
comment|/// get.  These constant ints are accessible through the
comment|/// ShuffleVectorSDNode class.  This is quite similar to the Altivec
comment|/// 'vperm' instruction, except that the indices must be constants and are
comment|/// in terms of the element size of VEC1/VEC2, not in terms of bytes.
name|VECTOR_SHUFFLE
block|,
comment|/// SCALAR_TO_VECTOR(VAL) - This represents the operation of loading a
comment|/// scalar value into element 0 of the resultant vector type.  The top
comment|/// elements 1 to N-1 of the N-element vector are undefined.  The type
comment|/// of the operand must match the vector element type, except when they
comment|/// are integer types.  In this case the operand is allowed to be wider
comment|/// than the vector element type, and is implicitly truncated to it.
name|SCALAR_TO_VECTOR
block|,
comment|// MULHU/MULHS - Multiply high - Multiply two integers of type iN, producing
comment|// an unsigned/signed value of type i[2*N], then return the top part.
name|MULHU
block|,
name|MULHS
block|,
comment|/// Bitwise operators - logical and, logical or, logical xor.
name|AND
block|,
name|OR
block|,
name|XOR
block|,
comment|/// Shift and rotation operations.  After legalization, the type of the
comment|/// shift amount is known to be TLI.getShiftAmountTy().  Before legalization
comment|/// the shift amount can be any type, but care must be taken to ensure it is
comment|/// large enough.  TLI.getShiftAmountTy() is i8 on some targets, but before
comment|/// legalization, types like i1024 can occur and i8 doesn't have enough bits
comment|/// to represent the shift amount.  By convention, DAGCombine and
comment|/// SelectionDAGBuilder forces these shift amounts to i32 for simplicity.
comment|///
name|SHL
block|,
name|SRA
block|,
name|SRL
block|,
name|ROTL
block|,
name|ROTR
block|,
comment|/// Byte Swap and Counting operators.
name|BSWAP
block|,
name|CTTZ
block|,
name|CTLZ
block|,
name|CTPOP
block|,
comment|// Select(COND, TRUEVAL, FALSEVAL).  If the type of the boolean COND is not
comment|// i1 then the high bits must conform to getBooleanContents.
name|SELECT
block|,
comment|// Select with condition operator - This selects between a true value and
comment|// a false value (ops #2 and #3) based on the boolean result of comparing
comment|// the lhs and rhs (ops #0 and #1) of a conditional expression with the
comment|// condition code in op #4, a CondCodeSDNode.
name|SELECT_CC
block|,
comment|// SetCC operator - This evaluates to a true value iff the condition is
comment|// true.  If the result value type is not i1 then the high bits conform
comment|// to getBooleanContents.  The operands to this are the left and right
comment|// operands to compare (ops #0, and #1) and the condition code to compare
comment|// them with (op #2) as a CondCodeSDNode.
name|SETCC
block|,
comment|// RESULT = VSETCC(LHS, RHS, COND) operator - This evaluates to a vector of
comment|// integer elements with all bits of the result elements set to true if the
comment|// comparison is true or all cleared if the comparison is false.  The
comment|// operands to this are the left and right operands to compare (LHS/RHS) and
comment|// the condition code to compare them with (COND) as a CondCodeSDNode.
name|VSETCC
block|,
comment|// SHL_PARTS/SRA_PARTS/SRL_PARTS - These operators are used for expanded
comment|// integer shift operations, just like ADD/SUB_PARTS.  The operation
comment|// ordering is:
comment|//       [Lo,Hi] = op [LoLHS,HiLHS], Amt
name|SHL_PARTS
block|,
name|SRA_PARTS
block|,
name|SRL_PARTS
block|,
comment|// Conversion operators.  These are all single input single output
comment|// operations.  For all of these, the result type must be strictly
comment|// wider or narrower (depending on the operation) than the source
comment|// type.
comment|// SIGN_EXTEND - Used for integer types, replicating the sign bit
comment|// into new bits.
name|SIGN_EXTEND
block|,
comment|// ZERO_EXTEND - Used for integer types, zeroing the new bits.
name|ZERO_EXTEND
block|,
comment|// ANY_EXTEND - Used for integer types.  The high bits are undefined.
name|ANY_EXTEND
block|,
comment|// TRUNCATE - Completely drop the high bits.
name|TRUNCATE
block|,
comment|// [SU]INT_TO_FP - These operators convert integers (whose interpreted sign
comment|// depends on the first letter) to floating point.
name|SINT_TO_FP
block|,
name|UINT_TO_FP
block|,
comment|// SIGN_EXTEND_INREG - This operator atomically performs a SHL/SRA pair to
comment|// sign extend a small value in a large integer register (e.g. sign
comment|// extending the low 8 bits of a 32-bit register to fill the top 24 bits
comment|// with the 7th bit).  The size of the smaller type is indicated by the 1th
comment|// operand, a ValueType node.
name|SIGN_EXTEND_INREG
block|,
comment|/// FP_TO_[US]INT - Convert a floating point value to a signed or unsigned
comment|/// integer.
name|FP_TO_SINT
block|,
name|FP_TO_UINT
block|,
comment|/// X = FP_ROUND(Y, TRUNC) - Rounding 'Y' from a larger floating point type
comment|/// down to the precision of the destination VT.  TRUNC is a flag, which is
comment|/// always an integer that is zero or one.  If TRUNC is 0, this is a
comment|/// normal rounding, if it is 1, this FP_ROUND is known to not change the
comment|/// value of Y.
comment|///
comment|/// The TRUNC = 1 case is used in cases where we know that the value will
comment|/// not be modified by the node, because Y is not using any of the extra
comment|/// precision of source type.  This allows certain transformations like
comment|/// FP_EXTEND(FP_ROUND(X,1)) -> X which are not safe for
comment|/// FP_EXTEND(FP_ROUND(X,0)) because the extra bits aren't removed.
name|FP_ROUND
block|,
comment|// FLT_ROUNDS_ - Returns current rounding mode:
comment|// -1 Undefined
comment|//  0 Round to 0
comment|//  1 Round to nearest
comment|//  2 Round to +inf
comment|//  3 Round to -inf
name|FLT_ROUNDS_
block|,
comment|/// X = FP_ROUND_INREG(Y, VT) - This operator takes an FP register, and
comment|/// rounds it to a floating point value.  It then promotes it and returns it
comment|/// in a register of the same size.  This operation effectively just
comment|/// discards excess precision.  The type to round down to is specified by
comment|/// the VT operand, a VTSDNode.
name|FP_ROUND_INREG
block|,
comment|/// X = FP_EXTEND(Y) - Extend a smaller FP type into a larger FP type.
name|FP_EXTEND
block|,
comment|// BITCAST - This operator converts between integer, vector and FP
comment|// values, as if the value was stored to memory with one type and loaded
comment|// from the same address with the other type (or equivalently for vector
comment|// format conversions, etc).  The source and result are required to have
comment|// the same bit size (e.g.  f32<-> i32).  This can also be used for
comment|// int-to-int or fp-to-fp conversions, but that is a noop, deleted by
comment|// getNode().
name|BITCAST
block|,
comment|// CONVERT_RNDSAT - This operator is used to support various conversions
comment|// between various types (float, signed, unsigned and vectors of those
comment|// types) with rounding and saturation. NOTE: Avoid using this operator as
comment|// most target don't support it and the operator might be removed in the
comment|// future. It takes the following arguments:
comment|//   0) value
comment|//   1) dest type (type to convert to)
comment|//   2) src type (type to convert from)
comment|//   3) rounding imm
comment|//   4) saturation imm
comment|//   5) ISD::CvtCode indicating the type of conversion to do
name|CONVERT_RNDSAT
block|,
comment|// FP16_TO_FP32, FP32_TO_FP16 - These operators are used to perform
comment|// promotions and truncation for half-precision (16 bit) floating
comment|// numbers. We need special nodes since FP16 is a storage-only type with
comment|// special semantics of operations.
name|FP16_TO_FP32
block|,
name|FP32_TO_FP16
block|,
comment|// FNEG, FABS, FSQRT, FSIN, FCOS, FPOWI, FPOW,
comment|// FLOG, FLOG2, FLOG10, FEXP, FEXP2,
comment|// FCEIL, FTRUNC, FRINT, FNEARBYINT, FFLOOR - Perform various unary floating
comment|// point operations. These are inspired by libm.
name|FNEG
block|,
name|FABS
block|,
name|FSQRT
block|,
name|FSIN
block|,
name|FCOS
block|,
name|FPOWI
block|,
name|FPOW
block|,
name|FLOG
block|,
name|FLOG2
block|,
name|FLOG10
block|,
name|FEXP
block|,
name|FEXP2
block|,
name|FCEIL
block|,
name|FTRUNC
block|,
name|FRINT
block|,
name|FNEARBYINT
block|,
name|FFLOOR
block|,
comment|// LOAD and STORE have token chains as their first operand, then the same
comment|// operands as an LLVM load/store instruction, then an offset node that
comment|// is added / subtracted from the base pointer to form the address (for
comment|// indexed memory ops).
name|LOAD
block|,
name|STORE
block|,
comment|// DYNAMIC_STACKALLOC - Allocate some number of bytes on the stack aligned
comment|// to a specified boundary.  This node always has two return values: a new
comment|// stack pointer value and a chain. The first operand is the token chain,
comment|// the second is the number of bytes to allocate, and the third is the
comment|// alignment boundary.  The size is guaranteed to be a multiple of the stack
comment|// alignment, and the alignment is guaranteed to be bigger than the stack
comment|// alignment (if required) or 0 to get standard stack alignment.
name|DYNAMIC_STACKALLOC
block|,
comment|// Control flow instructions.  These all have token chains.
comment|// BR - Unconditional branch.  The first operand is the chain
comment|// operand, the second is the MBB to branch to.
name|BR
block|,
comment|// BRIND - Indirect branch.  The first operand is the chain, the second
comment|// is the value to branch to, which must be of the same type as the target's
comment|// pointer type.
name|BRIND
block|,
comment|// BR_JT - Jumptable branch. The first operand is the chain, the second
comment|// is the jumptable index, the last one is the jumptable entry index.
name|BR_JT
block|,
comment|// BRCOND - Conditional branch.  The first operand is the chain, the
comment|// second is the condition, the third is the block to branch to if the
comment|// condition is true.  If the type of the condition is not i1, then the
comment|// high bits must conform to getBooleanContents.
name|BRCOND
block|,
comment|// BR_CC - Conditional branch.  The behavior is like that of SELECT_CC, in
comment|// that the condition is represented as condition code, and two nodes to
comment|// compare, rather than as a combined SetCC node.  The operands in order are
comment|// chain, cc, lhs, rhs, block to branch to if condition is true.
name|BR_CC
block|,
comment|// INLINEASM - Represents an inline asm block.  This node always has two
comment|// return values: a chain and a flag result.  The inputs are as follows:
comment|//   Operand #0   : Input chain.
comment|//   Operand #1   : a ExternalSymbolSDNode with a pointer to the asm string.
comment|//   Operand #2   : a MDNodeSDNode with the !srcloc metadata.
comment|//   Operand #3   : HasSideEffect, IsAlignStack bits.
comment|//   After this, it is followed by a list of operands with this format:
comment|//     ConstantSDNode: Flags that encode whether it is a mem or not, the
comment|//                     of operands that follow, etc.  See InlineAsm.h.
comment|//     ... however many operands ...
comment|//   Operand #last: Optional, an incoming flag.
comment|//
comment|// The variable width operands are required to represent target addressing
comment|// modes as a single "operand", even though they may have multiple
comment|// SDOperands.
name|INLINEASM
block|,
comment|// EH_LABEL - Represents a label in mid basic block used to track
comment|// locations needed for debug and exception handling tables.  These nodes
comment|// take a chain as input and return a chain.
name|EH_LABEL
block|,
comment|// STACKSAVE - STACKSAVE has one operand, an input chain.  It produces a
comment|// value, the same type as the pointer type for the system, and an output
comment|// chain.
name|STACKSAVE
block|,
comment|// STACKRESTORE has two operands, an input chain and a pointer to restore to
comment|// it returns an output chain.
name|STACKRESTORE
block|,
comment|// CALLSEQ_START/CALLSEQ_END - These operators mark the beginning and end of
comment|// a call sequence, and carry arbitrary information that target might want
comment|// to know.  The first operand is a chain, the rest are specified by the
comment|// target and not touched by the DAG optimizers.
comment|// CALLSEQ_START..CALLSEQ_END pairs may not be nested.
name|CALLSEQ_START
block|,
comment|// Beginning of a call sequence
name|CALLSEQ_END
block|,
comment|// End of a call sequence
comment|// VAARG - VAARG has four operands: an input chain, a pointer, a SRCVALUE,
comment|// and the alignment. It returns a pair of values: the vaarg value and a
comment|// new chain.
name|VAARG
block|,
comment|// VACOPY - VACOPY has five operands: an input chain, a destination pointer,
comment|// a source pointer, a SRCVALUE for the destination, and a SRCVALUE for the
comment|// source.
name|VACOPY
block|,
comment|// VAEND, VASTART - VAEND and VASTART have three operands: an input chain, a
comment|// pointer, and a SRCVALUE.
name|VAEND
block|,
name|VASTART
block|,
comment|// SRCVALUE - This is a node type that holds a Value* that is used to
comment|// make reference to a value in the LLVM IR.
name|SRCVALUE
block|,
comment|// MDNODE_SDNODE - This is a node that holdes an MDNode*, which is used to
comment|// reference metadata in the IR.
name|MDNODE_SDNODE
block|,
comment|// PCMARKER - This corresponds to the pcmarker intrinsic.
name|PCMARKER
block|,
comment|// READCYCLECOUNTER - This corresponds to the readcyclecounter intrinsic.
comment|// The only operand is a chain and a value and a chain are produced.  The
comment|// value is the contents of the architecture specific cycle counter like
comment|// register (or other high accuracy low latency clock source)
name|READCYCLECOUNTER
block|,
comment|// HANDLENODE node - Used as a handle for various purposes.
name|HANDLENODE
block|,
comment|// TRAMPOLINE - This corresponds to the init_trampoline intrinsic.
comment|// It takes as input a token chain, the pointer to the trampoline,
comment|// the pointer to the nested function, the pointer to pass for the
comment|// 'nest' parameter, a SRCVALUE for the trampoline and another for
comment|// the nested function (allowing targets to access the original
comment|// Function*).  It produces the result of the intrinsic and a token
comment|// chain as output.
name|TRAMPOLINE
block|,
comment|// TRAP - Trapping instruction
name|TRAP
block|,
comment|// PREFETCH - This corresponds to a prefetch intrinsic. It takes chains are
comment|// their first operand. The other operands are the address to prefetch,
comment|// read / write specifier, and locality specifier.
name|PREFETCH
block|,
comment|// OUTCHAIN = MEMBARRIER(INCHAIN, load-load, load-store, store-load,
comment|//                       store-store, device)
comment|// This corresponds to the memory.barrier intrinsic.
comment|// it takes an input chain, 4 operands to specify the type of barrier, an
comment|// operand specifying if the barrier applies to device and uncached memory
comment|// and produces an output chain.
name|MEMBARRIER
block|,
comment|// Val, OUTCHAIN = ATOMIC_CMP_SWAP(INCHAIN, ptr, cmp, swap)
comment|// this corresponds to the atomic.lcs intrinsic.
comment|// cmp is compared to *ptr, and if equal, swap is stored in *ptr.
comment|// the return is always the original value in *ptr
name|ATOMIC_CMP_SWAP
block|,
comment|// Val, OUTCHAIN = ATOMIC_SWAP(INCHAIN, ptr, amt)
comment|// this corresponds to the atomic.swap intrinsic.
comment|// amt is stored to *ptr atomically.
comment|// the return is always the original value in *ptr
name|ATOMIC_SWAP
block|,
comment|// Val, OUTCHAIN = ATOMIC_LOAD_[OpName](INCHAIN, ptr, amt)
comment|// this corresponds to the atomic.load.[OpName] intrinsic.
comment|// op(*ptr, amt) is stored to *ptr atomically.
comment|// the return is always the original value in *ptr
name|ATOMIC_LOAD_ADD
block|,
name|ATOMIC_LOAD_SUB
block|,
name|ATOMIC_LOAD_AND
block|,
name|ATOMIC_LOAD_OR
block|,
name|ATOMIC_LOAD_XOR
block|,
name|ATOMIC_LOAD_NAND
block|,
name|ATOMIC_LOAD_MIN
block|,
name|ATOMIC_LOAD_MAX
block|,
name|ATOMIC_LOAD_UMIN
block|,
name|ATOMIC_LOAD_UMAX
block|,
comment|/// BUILTIN_OP_END - This must be the last enum value in this list.
comment|/// The target-specific pre-isel opcode values start here.
name|BUILTIN_OP_END
block|}
enum|;
comment|/// FIRST_TARGET_MEMORY_OPCODE - Target-specific pre-isel operations
comment|/// which do not reference a specific memory location should be less than
comment|/// this value. Those that do must not be less than this value, and can
comment|/// be used with SelectionDAG::getMemIntrinsicNode.
specifier|static
specifier|const
name|int
name|FIRST_TARGET_MEMORY_OPCODE
init|=
name|BUILTIN_OP_END
operator|+
literal|150
decl_stmt|;
comment|//===--------------------------------------------------------------------===//
comment|/// MemIndexedMode enum - This enum defines the load / store indexed
comment|/// addressing modes.
comment|///
comment|/// UNINDEXED    "Normal" load / store. The effective address is already
comment|///              computed and is available in the base pointer. The offset
comment|///              operand is always undefined. In addition to producing a
comment|///              chain, an unindexed load produces one value (result of the
comment|///              load); an unindexed store does not produce a value.
comment|///
comment|/// PRE_INC      Similar to the unindexed mode where the effective address is
comment|/// PRE_DEC      the value of the base pointer add / subtract the offset.
comment|///              It considers the computation as being folded into the load /
comment|///              store operation (i.e. the load / store does the address
comment|///              computation as well as performing the memory transaction).
comment|///              The base operand is always undefined. In addition to
comment|///              producing a chain, pre-indexed load produces two values
comment|///              (result of the load and the result of the address
comment|///              computation); a pre-indexed store produces one value (result
comment|///              of the address computation).
comment|///
comment|/// POST_INC     The effective address is the value of the base pointer. The
comment|/// POST_DEC     value of the offset operand is then added to / subtracted
comment|///              from the base after memory transaction. In addition to
comment|///              producing a chain, post-indexed load produces two values
comment|///              (the result of the load and the result of the base +/- offset
comment|///              computation); a post-indexed store produces one value (the
comment|///              the result of the base +/- offset computation).
enum|enum
name|MemIndexedMode
block|{
name|UNINDEXED
init|=
literal|0
block|,
name|PRE_INC
block|,
name|PRE_DEC
block|,
name|POST_INC
block|,
name|POST_DEC
block|,
name|LAST_INDEXED_MODE
block|}
enum|;
comment|//===--------------------------------------------------------------------===//
comment|/// LoadExtType enum - This enum defines the three variants of LOADEXT
comment|/// (load with extension).
comment|///
comment|/// SEXTLOAD loads the integer operand and sign extends it to a larger
comment|///          integer result type.
comment|/// ZEXTLOAD loads the integer operand and zero extends it to a larger
comment|///          integer result type.
comment|/// EXTLOAD  is used for two things: floating point extending loads and
comment|///          integer extending loads [the top bits are undefined].
enum|enum
name|LoadExtType
block|{
name|NON_EXTLOAD
init|=
literal|0
block|,
name|EXTLOAD
block|,
name|SEXTLOAD
block|,
name|ZEXTLOAD
block|,
name|LAST_LOADEXT_TYPE
block|}
enum|;
comment|//===--------------------------------------------------------------------===//
comment|/// ISD::CondCode enum - These are ordered carefully to make the bitfields
comment|/// below work out, when considering SETFALSE (something that never exists
comment|/// dynamically) as 0.  "U" -> Unsigned (for integer operands) or Unordered
comment|/// (for floating point), "L" -> Less than, "G" -> Greater than, "E" -> Equal
comment|/// to.  If the "N" column is 1, the result of the comparison is undefined if
comment|/// the input is a NAN.
comment|///
comment|/// All of these (except for the 'always folded ops') should be handled for
comment|/// floating point.  For integer, only the SETEQ,SETNE,SETLT,SETLE,SETGT,
comment|/// SETGE,SETULT,SETULE,SETUGT, and SETUGE opcodes are used.
comment|///
comment|/// Note that these are laid out in a specific order to allow bit-twiddling
comment|/// to transform conditions.
enum|enum
name|CondCode
block|{
comment|// Opcode          N U L G E       Intuitive operation
name|SETFALSE
block|,
comment|//    0 0 0 0       Always false (always folded)
name|SETOEQ
block|,
comment|//    0 0 0 1       True if ordered and equal
name|SETOGT
block|,
comment|//    0 0 1 0       True if ordered and greater than
name|SETOGE
block|,
comment|//    0 0 1 1       True if ordered and greater than or equal
name|SETOLT
block|,
comment|//    0 1 0 0       True if ordered and less than
name|SETOLE
block|,
comment|//    0 1 0 1       True if ordered and less than or equal
name|SETONE
block|,
comment|//    0 1 1 0       True if ordered and operands are unequal
name|SETO
block|,
comment|//    0 1 1 1       True if ordered (no nans)
name|SETUO
block|,
comment|//    1 0 0 0       True if unordered: isnan(X) | isnan(Y)
name|SETUEQ
block|,
comment|//    1 0 0 1       True if unordered or equal
name|SETUGT
block|,
comment|//    1 0 1 0       True if unordered or greater than
name|SETUGE
block|,
comment|//    1 0 1 1       True if unordered, greater than, or equal
name|SETULT
block|,
comment|//    1 1 0 0       True if unordered or less than
name|SETULE
block|,
comment|//    1 1 0 1       True if unordered, less than, or equal
name|SETUNE
block|,
comment|//    1 1 1 0       True if unordered or not equal
name|SETTRUE
block|,
comment|//    1 1 1 1       Always true (always folded)
comment|// Don't care operations: undefined if the input is a nan.
name|SETFALSE2
block|,
comment|//  1 X 0 0 0       Always false (always folded)
name|SETEQ
block|,
comment|//  1 X 0 0 1       True if equal
name|SETGT
block|,
comment|//  1 X 0 1 0       True if greater than
name|SETGE
block|,
comment|//  1 X 0 1 1       True if greater than or equal
name|SETLT
block|,
comment|//  1 X 1 0 0       True if less than
name|SETLE
block|,
comment|//  1 X 1 0 1       True if less than or equal
name|SETNE
block|,
comment|//  1 X 1 1 0       True if not equal
name|SETTRUE2
block|,
comment|//  1 X 1 1 1       Always true (always folded)
name|SETCC_INVALID
comment|// Marker value.
block|}
enum|;
comment|/// isSignedIntSetCC - Return true if this is a setcc instruction that
comment|/// performs a signed comparison when used with integer operands.
specifier|inline
name|bool
name|isSignedIntSetCC
parameter_list|(
name|CondCode
name|Code
parameter_list|)
block|{
return|return
name|Code
operator|==
name|SETGT
operator|||
name|Code
operator|==
name|SETGE
operator|||
name|Code
operator|==
name|SETLT
operator|||
name|Code
operator|==
name|SETLE
return|;
block|}
comment|/// isUnsignedIntSetCC - Return true if this is a setcc instruction that
comment|/// performs an unsigned comparison when used with integer operands.
specifier|inline
name|bool
name|isUnsignedIntSetCC
parameter_list|(
name|CondCode
name|Code
parameter_list|)
block|{
return|return
name|Code
operator|==
name|SETUGT
operator|||
name|Code
operator|==
name|SETUGE
operator|||
name|Code
operator|==
name|SETULT
operator|||
name|Code
operator|==
name|SETULE
return|;
block|}
comment|/// isTrueWhenEqual - Return true if the specified condition returns true if
comment|/// the two operands to the condition are equal.  Note that if one of the two
comment|/// operands is a NaN, this value is meaningless.
specifier|inline
name|bool
name|isTrueWhenEqual
parameter_list|(
name|CondCode
name|Cond
parameter_list|)
block|{
return|return
operator|(
operator|(
name|int
operator|)
name|Cond
operator|&
literal|1
operator|)
operator|!=
literal|0
return|;
block|}
comment|/// getUnorderedFlavor - This function returns 0 if the condition is always
comment|/// false if an operand is a NaN, 1 if the condition is always true if the
comment|/// operand is a NaN, and 2 if the condition is undefined if the operand is a
comment|/// NaN.
specifier|inline
name|unsigned
name|getUnorderedFlavor
parameter_list|(
name|CondCode
name|Cond
parameter_list|)
block|{
return|return
operator|(
operator|(
name|int
operator|)
name|Cond
operator|>>
literal|3
operator|)
operator|&
literal|3
return|;
block|}
comment|/// getSetCCInverse - Return the operation corresponding to !(X op Y), where
comment|/// 'op' is a valid SetCC operation.
name|CondCode
name|getSetCCInverse
parameter_list|(
name|CondCode
name|Operation
parameter_list|,
name|bool
name|isInteger
parameter_list|)
function_decl|;
comment|/// getSetCCSwappedOperands - Return the operation corresponding to (Y op X)
comment|/// when given the operation for (X op Y).
name|CondCode
name|getSetCCSwappedOperands
parameter_list|(
name|CondCode
name|Operation
parameter_list|)
function_decl|;
comment|/// getSetCCOrOperation - Return the result of a logical OR between different
comment|/// comparisons of identical values: ((X op1 Y) | (X op2 Y)).  This
comment|/// function returns SETCC_INVALID if it is not possible to represent the
comment|/// resultant comparison.
name|CondCode
name|getSetCCOrOperation
parameter_list|(
name|CondCode
name|Op1
parameter_list|,
name|CondCode
name|Op2
parameter_list|,
name|bool
name|isInteger
parameter_list|)
function_decl|;
comment|/// getSetCCAndOperation - Return the result of a logical AND between
comment|/// different comparisons of identical values: ((X op1 Y)& (X op2 Y)).  This
comment|/// function returns SETCC_INVALID if it is not possible to represent the
comment|/// resultant comparison.
name|CondCode
name|getSetCCAndOperation
parameter_list|(
name|CondCode
name|Op1
parameter_list|,
name|CondCode
name|Op2
parameter_list|,
name|bool
name|isInteger
parameter_list|)
function_decl|;
comment|//===--------------------------------------------------------------------===//
comment|/// CvtCode enum - This enum defines the various converts CONVERT_RNDSAT
comment|/// supports.
enum|enum
name|CvtCode
block|{
name|CVT_FF
block|,
comment|// Float from Float
name|CVT_FS
block|,
comment|// Float from Signed
name|CVT_FU
block|,
comment|// Float from Unsigned
name|CVT_SF
block|,
comment|// Signed from Float
name|CVT_UF
block|,
comment|// Unsigned from Float
name|CVT_SS
block|,
comment|// Signed from Signed
name|CVT_SU
block|,
comment|// Signed from Unsigned
name|CVT_US
block|,
comment|// Unsigned from Signed
name|CVT_UU
block|,
comment|// Unsigned from Unsigned
name|CVT_INVALID
comment|// Marker - Invalid opcode
block|}
enum|;
block|}
comment|// end llvm::ISD namespace
block|}
end_decl_stmt

begin_comment
comment|// end llvm namespace
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

