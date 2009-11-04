begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- llvm/CodeGen/SelectionDAGNodes.h - SelectionDAG Nodes ---*- C++ -*-===//
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
comment|// This file declares the SDNode class and derived classes, which are used to
end_comment

begin_comment
comment|// represent the nodes and operations present in a SelectionDAG.  These nodes
end_comment

begin_comment
comment|// and operations are machine code level operations, with some similarities to
end_comment

begin_comment
comment|// the GCC RTL representation.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Clients should include the SelectionDAG.h file instead of this file directly.
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
name|LLVM_CODEGEN_SELECTIONDAGNODES_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CODEGEN_SELECTIONDAGNODES_H
end_define

begin_include
include|#
directive|include
file|"llvm/Constants.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/FoldingSet.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/GraphTraits.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/ilist_node.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/SmallVector.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/STLExtras.h"
end_include

begin_include
include|#
directive|include
file|"llvm/CodeGen/ValueTypes.h"
end_include

begin_include
include|#
directive|include
file|"llvm/CodeGen/MachineMemOperand.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/MathExtras.h"
end_include

begin_include
include|#
directive|include
file|"llvm/System/DataTypes.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/DebugLoc.h"
end_include

begin_include
include|#
directive|include
file|<cassert>
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|SelectionDAG
decl_stmt|;
name|class
name|GlobalValue
decl_stmt|;
name|class
name|MachineBasicBlock
decl_stmt|;
name|class
name|MachineConstantPoolValue
decl_stmt|;
name|class
name|SDNode
decl_stmt|;
name|class
name|Value
decl_stmt|;
name|template
operator|<
name|typename
name|T
operator|>
expr|struct
name|DenseMapInfo
expr_stmt|;
name|template
operator|<
name|typename
name|T
operator|>
expr|struct
name|simplify_type
expr_stmt|;
name|template
operator|<
name|typename
name|T
operator|>
expr|struct
name|ilist_traits
expr_stmt|;
comment|/// SDVTList - This represents a list of ValueType's that has been intern'd by
comment|/// a SelectionDAG.  Instances of this simple value class are returned by
comment|/// SelectionDAG::getVTList(...).
comment|///
struct|struct
name|SDVTList
block|{
specifier|const
name|EVT
modifier|*
name|VTs
decl_stmt|;
name|unsigned
name|int
name|NumVTs
decl_stmt|;
block|}
struct|;
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
comment|// TargetConstant* - Like Constant*, but the DAG does not do any folding or
comment|// simplification of the constant.
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
comment|/// node has returns the result of the intrinsic.
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
comment|/// EXTRACT_SUBVECTOR(VECTOR, IDX) - Returns a subvector from VECTOR (an
comment|/// vector value) starting with the (potentially variable) element number
comment|/// IDX, which must be a multiple of the result vector length.
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
comment|// Bitwise operators - logical and, logical or, logical xor, shift left,
comment|// shift right algebraic (shift in sign bits), shift right logical (shift in
comment|// zeroes), rotate left, rotate right, and byteswap.
name|AND
block|,
name|OR
block|,
name|XOR
block|,
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
name|BSWAP
block|,
comment|// Counting operators
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
comment|// BIT_CONVERT - Theis operator converts between integer and FP values, as
comment|// if one was stored to memory as integer and the other was loaded from the
comment|// same address (or equivalently for vector format conversions, etc).  The
comment|// source and result are required to have the same bit size (e.g.
comment|// f32<-> i32).  This can also be used for int-to-int or fp-to-fp
comment|// conversions, but that is a noop, deleted by getNode().
name|BIT_CONVERT
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
comment|//   Operand #2n+2: A RegisterNode.
comment|//   Operand #2n+3: A TargetConstant, indicating if the reg is a use/def
comment|//   Operand #last: Optional, an incoming flag.
name|INLINEASM
block|,
comment|// DBG_LABEL, EH_LABEL - Represents a label in mid basic block used to track
comment|// locations needed for debug and exception handling tables.  These nodes
comment|// take a chain as input and return a chain.
name|DBG_LABEL
block|,
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
comment|// VAARG - VAARG has three operands: an input chain, a pointer, and a
comment|// SRCVALUE.  It returns a pair of values: the vaarg value and a new chain.
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
comment|// DBG_STOPPOINT - This node is used to represent a source location for
comment|// debug info.  It takes token chain as input, and carries a line number,
comment|// column number, and a pointer to a CompileUnit object identifying
comment|// the containing compilation unit.  It produces a token chain as output.
name|DBG_STOPPOINT
block|,
comment|// DEBUG_LOC - This node is used to represent source line information
comment|// embedded in the code.  It takes a token chain as input, then a line
comment|// number, then a column then a file id (provided by MachineModuleInfo.) It
comment|// produces a token chain as output.
name|DEBUG_LOC
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
literal|1
operator|<<
literal|14
decl_stmt|;
comment|/// Node predicates
comment|/// isBuildVectorAllOnes - Return true if the specified node is a
comment|/// BUILD_VECTOR where all of the elements are ~0 or undef.
name|bool
name|isBuildVectorAllOnes
parameter_list|(
specifier|const
name|SDNode
modifier|*
name|N
parameter_list|)
function_decl|;
comment|/// isBuildVectorAllZeros - Return true if the specified node is a
comment|/// BUILD_VECTOR where all of the elements are 0 or undef.
name|bool
name|isBuildVectorAllZeros
parameter_list|(
specifier|const
name|SDNode
modifier|*
name|N
parameter_list|)
function_decl|;
comment|/// isScalarToVector - Return true if the specified node is a
comment|/// ISD::SCALAR_TO_VECTOR node or a BUILD_VECTOR node where only the low
comment|/// element is not an undef.
name|bool
name|isScalarToVector
parameter_list|(
specifier|const
name|SDNode
modifier|*
name|N
parameter_list|)
function_decl|;
comment|/// isDebugLabel - Return true if the specified node represents a debug
comment|/// label (i.e. ISD::DBG_LABEL or TargetInstrInfo::DBG_LABEL node).
name|bool
name|isDebugLabel
parameter_list|(
specifier|const
name|SDNode
modifier|*
name|N
parameter_list|)
function_decl|;
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
comment|///
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
comment|/// EXTLOAD  is used for three things: floating point extending loads,
comment|///          integer extending loads [the top bits are undefined], and vector
comment|///          extending loads [load into low elt].
comment|///
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
comment|//===----------------------------------------------------------------------===//
comment|/// SDValue - Unlike LLVM values, Selection DAG nodes may return multiple
comment|/// values as the result of a computation.  Many nodes return multiple values,
comment|/// from loads (which define a token and a return value) to ADDC (which returns
comment|/// a result and a carry value), to calls (which may return an arbitrary number
comment|/// of values).
comment|///
comment|/// As such, each use of a SelectionDAG computation must indicate the node that
comment|/// computes it as well as which return value to use from that node.  This pair
comment|/// of information is represented with the SDValue value type.
comment|///
name|class
name|SDValue
block|{
name|SDNode
modifier|*
name|Node
decl_stmt|;
comment|// The node defining the value we are using.
name|unsigned
name|ResNo
decl_stmt|;
comment|// Which return value of the node we are using.
name|public
label|:
name|SDValue
argument_list|()
operator|:
name|Node
argument_list|(
literal|0
argument_list|)
operator|,
name|ResNo
argument_list|(
literal|0
argument_list|)
block|{}
name|SDValue
argument_list|(
argument|SDNode *node
argument_list|,
argument|unsigned resno
argument_list|)
operator|:
name|Node
argument_list|(
name|node
argument_list|)
operator|,
name|ResNo
argument_list|(
argument|resno
argument_list|)
block|{}
comment|/// get the index which selects a specific result in the SDNode
name|unsigned
name|getResNo
argument_list|()
specifier|const
block|{
return|return
name|ResNo
return|;
block|}
comment|/// get the SDNode which holds the desired result
name|SDNode
operator|*
name|getNode
argument_list|()
specifier|const
block|{
return|return
name|Node
return|;
block|}
comment|/// set the SDNode
name|void
name|setNode
parameter_list|(
name|SDNode
modifier|*
name|N
parameter_list|)
block|{
name|Node
operator|=
name|N
expr_stmt|;
block|}
name|bool
name|operator
operator|==
operator|(
specifier|const
name|SDValue
operator|&
name|O
operator|)
specifier|const
block|{
return|return
name|Node
operator|==
name|O
operator|.
name|Node
operator|&&
name|ResNo
operator|==
name|O
operator|.
name|ResNo
return|;
block|}
name|bool
name|operator
operator|!=
operator|(
specifier|const
name|SDValue
operator|&
name|O
operator|)
specifier|const
block|{
return|return
operator|!
name|operator
operator|==
operator|(
name|O
operator|)
return|;
block|}
name|bool
name|operator
operator|<
operator|(
specifier|const
name|SDValue
operator|&
name|O
operator|)
specifier|const
block|{
return|return
name|Node
operator|<
name|O
operator|.
name|Node
operator|||
operator|(
name|Node
operator|==
name|O
operator|.
name|Node
operator|&&
name|ResNo
operator|<
name|O
operator|.
name|ResNo
operator|)
return|;
block|}
name|SDValue
name|getValue
argument_list|(
name|unsigned
name|R
argument_list|)
decl|const
block|{
return|return
name|SDValue
argument_list|(
name|Node
argument_list|,
name|R
argument_list|)
return|;
block|}
comment|// isOperandOf - Return true if this node is an operand of N.
name|bool
name|isOperandOf
argument_list|(
name|SDNode
operator|*
name|N
argument_list|)
decl|const
decl_stmt|;
comment|/// getValueType - Return the ValueType of the referenced return value.
comment|///
specifier|inline
name|EVT
name|getValueType
argument_list|()
specifier|const
expr_stmt|;
comment|/// getValueSizeInBits - Returns the size of the value in bits.
comment|///
name|unsigned
name|getValueSizeInBits
argument_list|()
specifier|const
block|{
return|return
name|getValueType
argument_list|()
operator|.
name|getSizeInBits
argument_list|()
return|;
block|}
comment|// Forwarding methods - These forward to the corresponding methods in SDNode.
specifier|inline
name|unsigned
name|getOpcode
argument_list|()
specifier|const
expr_stmt|;
specifier|inline
name|unsigned
name|getNumOperands
argument_list|()
specifier|const
expr_stmt|;
specifier|inline
specifier|const
name|SDValue
modifier|&
name|getOperand
argument_list|(
name|unsigned
name|i
argument_list|)
decl|const
decl_stmt|;
specifier|inline
name|uint64_t
name|getConstantOperandVal
argument_list|(
name|unsigned
name|i
argument_list|)
decl|const
decl_stmt|;
specifier|inline
name|bool
name|isTargetMemoryOpcode
argument_list|()
specifier|const
expr_stmt|;
specifier|inline
name|bool
name|isTargetOpcode
argument_list|()
specifier|const
expr_stmt|;
specifier|inline
name|bool
name|isMachineOpcode
argument_list|()
specifier|const
expr_stmt|;
specifier|inline
name|unsigned
name|getMachineOpcode
argument_list|()
specifier|const
expr_stmt|;
specifier|inline
specifier|const
name|DebugLoc
name|getDebugLoc
argument_list|()
specifier|const
expr_stmt|;
comment|/// reachesChainWithoutSideEffects - Return true if this operand (which must
comment|/// be a chain) reaches the specified operand without crossing any
comment|/// side-effecting instructions.  In practice, this looks through token
comment|/// factors and non-volatile loads.  In order to remain efficient, this only
comment|/// looks a couple of nodes in, it does not do an exhaustive search.
name|bool
name|reachesChainWithoutSideEffects
argument_list|(
name|SDValue
name|Dest
argument_list|,
name|unsigned
name|Depth
operator|=
literal|2
argument_list|)
decl|const
decl_stmt|;
comment|/// use_empty - Return true if there are no nodes using value ResNo
comment|/// of Node.
comment|///
specifier|inline
name|bool
name|use_empty
argument_list|()
specifier|const
expr_stmt|;
comment|/// hasOneUse - Return true if there is exactly one node using value
comment|/// ResNo of Node.
comment|///
specifier|inline
name|bool
name|hasOneUse
argument_list|()
specifier|const
expr_stmt|;
block|}
empty_stmt|;
name|template
operator|<
operator|>
expr|struct
name|DenseMapInfo
operator|<
name|SDValue
operator|>
block|{
specifier|static
specifier|inline
name|SDValue
name|getEmptyKey
argument_list|()
block|{
return|return
name|SDValue
argument_list|(
operator|(
name|SDNode
operator|*
operator|)
operator|-
literal|1
argument_list|,
operator|-
literal|1U
argument_list|)
return|;
block|}
specifier|static
specifier|inline
name|SDValue
name|getTombstoneKey
argument_list|()
block|{
return|return
name|SDValue
argument_list|(
operator|(
name|SDNode
operator|*
operator|)
operator|-
literal|1
argument_list|,
literal|0
argument_list|)
return|;
block|}
specifier|static
name|unsigned
name|getHashValue
argument_list|(
argument|const SDValue&Val
argument_list|)
block|{
return|return
operator|(
call|(
name|unsigned
call|)
argument_list|(
operator|(
name|uintptr_t
operator|)
name|Val
operator|.
name|getNode
argument_list|()
operator|>>
literal|4
argument_list|)
operator|^
call|(
name|unsigned
call|)
argument_list|(
operator|(
name|uintptr_t
operator|)
name|Val
operator|.
name|getNode
argument_list|()
operator|>>
literal|9
argument_list|)
operator|)
operator|+
name|Val
operator|.
name|getResNo
argument_list|()
return|;
block|}
specifier|static
name|bool
name|isEqual
argument_list|(
argument|const SDValue&LHS
argument_list|,
argument|const SDValue&RHS
argument_list|)
block|{
return|return
name|LHS
operator|==
name|RHS
return|;
block|}
specifier|static
name|bool
name|isPod
argument_list|()
block|{
return|return
name|true
return|;
block|}
expr|}
block|;
comment|/// simplify_type specializations - Allow casting operators to work directly on
comment|/// SDValues as if they were SDNode*'s.
name|template
operator|<
operator|>
expr|struct
name|simplify_type
operator|<
name|SDValue
operator|>
block|{
typedef|typedef
name|SDNode
modifier|*
name|SimpleType
typedef|;
specifier|static
name|SimpleType
name|getSimplifiedValue
argument_list|(
argument|const SDValue&Val
argument_list|)
block|{
return|return
name|static_cast
operator|<
name|SimpleType
operator|>
operator|(
name|Val
operator|.
name|getNode
argument_list|()
operator|)
return|;
block|}
expr|}
block|;
name|template
operator|<
operator|>
expr|struct
name|simplify_type
operator|<
specifier|const
name|SDValue
operator|>
block|{
typedef|typedef
name|SDNode
modifier|*
name|SimpleType
typedef|;
specifier|static
name|SimpleType
name|getSimplifiedValue
argument_list|(
argument|const SDValue&Val
argument_list|)
block|{
return|return
name|static_cast
operator|<
name|SimpleType
operator|>
operator|(
name|Val
operator|.
name|getNode
argument_list|()
operator|)
return|;
block|}
expr|}
block|;
comment|/// SDUse - Represents a use of a SDNode. This class holds an SDValue,
comment|/// which records the SDNode being used and the result number, a
comment|/// pointer to the SDNode using the value, and Next and Prev pointers,
comment|/// which link together all the uses of an SDNode.
comment|///
name|class
name|SDUse
block|{
comment|/// Val - The value being used.
name|SDValue
name|Val
block|;
comment|/// User - The user of this value.
name|SDNode
operator|*
name|User
block|;
comment|/// Prev, Next - Pointers to the uses list of the SDNode referred by
comment|/// this operand.
name|SDUse
operator|*
operator|*
name|Prev
block|,
operator|*
name|Next
block|;
name|SDUse
argument_list|(
specifier|const
name|SDUse
operator|&
name|U
argument_list|)
block|;
comment|// Do not implement
name|void
name|operator
operator|=
operator|(
specifier|const
name|SDUse
operator|&
name|U
operator|)
block|;
comment|// Do not implement
name|public
operator|:
name|SDUse
argument_list|()
operator|:
name|Val
argument_list|()
block|,
name|User
argument_list|(
name|NULL
argument_list|)
block|,
name|Prev
argument_list|(
name|NULL
argument_list|)
block|,
name|Next
argument_list|(
argument|NULL
argument_list|)
block|{}
comment|/// Normally SDUse will just implicitly convert to an SDValue that it holds.
name|operator
specifier|const
name|SDValue
operator|&
operator|(
operator|)
specifier|const
block|{
return|return
name|Val
return|;
block|}
comment|/// If implicit conversion to SDValue doesn't work, the get() method returns
comment|/// the SDValue.
specifier|const
name|SDValue
operator|&
name|get
argument_list|()
specifier|const
block|{
return|return
name|Val
return|;
block|}
comment|/// getUser - This returns the SDNode that contains this Use.
name|SDNode
operator|*
name|getUser
argument_list|()
block|{
return|return
name|User
return|;
block|}
comment|/// getNext - Get the next SDUse in the use list.
name|SDUse
operator|*
name|getNext
argument_list|()
specifier|const
block|{
return|return
name|Next
return|;
block|}
comment|/// getNode - Convenience function for get().getNode().
name|SDNode
operator|*
name|getNode
argument_list|()
specifier|const
block|{
return|return
name|Val
operator|.
name|getNode
argument_list|()
return|;
block|}
comment|/// getResNo - Convenience function for get().getResNo().
name|unsigned
name|getResNo
argument_list|()
specifier|const
block|{
return|return
name|Val
operator|.
name|getResNo
argument_list|()
return|;
block|}
comment|/// getValueType - Convenience function for get().getValueType().
name|EVT
name|getValueType
argument_list|()
specifier|const
block|{
return|return
name|Val
operator|.
name|getValueType
argument_list|()
return|;
block|}
comment|/// operator== - Convenience function for get().operator==
name|bool
name|operator
operator|==
operator|(
specifier|const
name|SDValue
operator|&
name|V
operator|)
specifier|const
block|{
return|return
name|Val
operator|==
name|V
return|;
block|}
comment|/// operator!= - Convenience function for get().operator!=
name|bool
name|operator
operator|!=
operator|(
specifier|const
name|SDValue
operator|&
name|V
operator|)
specifier|const
block|{
return|return
name|Val
operator|!=
name|V
return|;
block|}
comment|/// operator< - Convenience function for get().operator<
name|bool
name|operator
operator|<
operator|(
specifier|const
name|SDValue
operator|&
name|V
operator|)
specifier|const
block|{
return|return
name|Val
operator|<
name|V
return|;
block|}
name|private
operator|:
name|friend
name|class
name|SelectionDAG
block|;
name|friend
name|class
name|SDNode
block|;
name|void
name|setUser
argument_list|(
argument|SDNode *p
argument_list|)
block|{
name|User
operator|=
name|p
block|; }
comment|/// set - Remove this use from its existing use list, assign it the
comment|/// given value, and add it to the new value's node's use list.
specifier|inline
name|void
name|set
argument_list|(
specifier|const
name|SDValue
operator|&
name|V
argument_list|)
block|;
comment|/// setInitial - like set, but only supports initializing a newly-allocated
comment|/// SDUse with a non-null value.
specifier|inline
name|void
name|setInitial
argument_list|(
specifier|const
name|SDValue
operator|&
name|V
argument_list|)
block|;
comment|/// setNode - like set, but only sets the Node portion of the value,
comment|/// leaving the ResNo portion unmodified.
specifier|inline
name|void
name|setNode
argument_list|(
name|SDNode
operator|*
name|N
argument_list|)
block|;
name|void
name|addToList
argument_list|(
argument|SDUse **List
argument_list|)
block|{
name|Next
operator|=
operator|*
name|List
block|;
if|if
condition|(
name|Next
condition|)
name|Next
operator|->
name|Prev
operator|=
operator|&
name|Next
expr_stmt|;
name|Prev
operator|=
name|List
block|;
operator|*
name|List
operator|=
name|this
block|;   }
name|void
name|removeFromList
argument_list|()
block|{
operator|*
name|Prev
operator|=
name|Next
block|;
if|if
condition|(
name|Next
condition|)
name|Next
operator|->
name|Prev
operator|=
name|Prev
expr_stmt|;
block|}
expr|}
block|;
comment|/// simplify_type specializations - Allow casting operators to work directly on
comment|/// SDValues as if they were SDNode*'s.
name|template
operator|<
operator|>
expr|struct
name|simplify_type
operator|<
name|SDUse
operator|>
block|{
typedef|typedef
name|SDNode
modifier|*
name|SimpleType
typedef|;
specifier|static
name|SimpleType
name|getSimplifiedValue
argument_list|(
argument|const SDUse&Val
argument_list|)
block|{
return|return
name|static_cast
operator|<
name|SimpleType
operator|>
operator|(
name|Val
operator|.
name|getNode
argument_list|()
operator|)
return|;
block|}
expr|}
block|;
name|template
operator|<
operator|>
expr|struct
name|simplify_type
operator|<
specifier|const
name|SDUse
operator|>
block|{
typedef|typedef
name|SDNode
modifier|*
name|SimpleType
typedef|;
specifier|static
name|SimpleType
name|getSimplifiedValue
argument_list|(
argument|const SDUse&Val
argument_list|)
block|{
return|return
name|static_cast
operator|<
name|SimpleType
operator|>
operator|(
name|Val
operator|.
name|getNode
argument_list|()
operator|)
return|;
block|}
expr|}
block|;
comment|/// SDNode - Represents one node in the SelectionDAG.
comment|///
name|class
name|SDNode
operator|:
name|public
name|FoldingSetNode
block|,
name|public
name|ilist_node
operator|<
name|SDNode
operator|>
block|{
name|private
operator|:
comment|/// NodeType - The operation that this node performs.
comment|///
name|int16_t
name|NodeType
block|;
comment|/// OperandsNeedDelete - This is true if OperandList was new[]'d.  If true,
comment|/// then they will be delete[]'d when the node is destroyed.
name|uint16_t
name|OperandsNeedDelete
operator|:
literal|1
block|;
name|protected
operator|:
comment|/// SubclassData - This member is defined by this class, but is not used for
comment|/// anything.  Subclasses can use it to hold whatever state they find useful.
comment|/// This field is initialized to zero by the ctor.
name|uint16_t
name|SubclassData
operator|:
literal|15
block|;
name|private
operator|:
comment|/// NodeId - Unique id per SDNode in the DAG.
name|int
name|NodeId
block|;
comment|/// OperandList - The values that are used by this operation.
comment|///
name|SDUse
operator|*
name|OperandList
block|;
comment|/// ValueList - The types of the values this node defines.  SDNode's may
comment|/// define multiple values simultaneously.
specifier|const
name|EVT
operator|*
name|ValueList
block|;
comment|/// UseList - List of uses for this SDNode.
name|SDUse
operator|*
name|UseList
block|;
comment|/// NumOperands/NumValues - The number of entries in the Operand/Value list.
name|unsigned
name|short
name|NumOperands
block|,
name|NumValues
block|;
comment|/// debugLoc - source line information.
name|DebugLoc
name|debugLoc
block|;
comment|/// getValueTypeList - Return a pointer to the specified value type.
specifier|static
specifier|const
name|EVT
operator|*
name|getValueTypeList
argument_list|(
argument|EVT VT
argument_list|)
block|;
name|friend
name|class
name|SelectionDAG
block|;
name|friend
expr|struct
name|ilist_traits
operator|<
name|SDNode
operator|>
block|;
name|public
operator|:
comment|//===--------------------------------------------------------------------===//
comment|//  Accessors
comment|//
comment|/// getOpcode - Return the SelectionDAG opcode value for this node. For
comment|/// pre-isel nodes (those for which isMachineOpcode returns false), these
comment|/// are the opcode values in the ISD and<target>ISD namespaces. For
comment|/// post-isel opcodes, see getMachineOpcode.
name|unsigned
name|getOpcode
argument_list|()
specifier|const
block|{
return|return
operator|(
name|unsigned
name|short
operator|)
name|NodeType
return|;
block|}
comment|/// isTargetOpcode - Test if this node has a target-specific opcode (in the
comment|/// \<target\>ISD namespace).
name|bool
name|isTargetOpcode
argument_list|()
specifier|const
block|{
return|return
name|NodeType
operator|>=
name|ISD
operator|::
name|BUILTIN_OP_END
return|;
block|}
comment|/// isTargetMemoryOpcode - Test if this node has a target-specific
comment|/// memory-referencing opcode (in the \<target\>ISD namespace and
comment|/// greater than FIRST_TARGET_MEMORY_OPCODE).
name|bool
name|isTargetMemoryOpcode
argument_list|()
specifier|const
block|{
return|return
name|NodeType
operator|>=
name|ISD
operator|::
name|FIRST_TARGET_MEMORY_OPCODE
return|;
block|}
comment|/// isMachineOpcode - Test if this node has a post-isel opcode, directly
comment|/// corresponding to a MachineInstr opcode.
name|bool
name|isMachineOpcode
argument_list|()
specifier|const
block|{
return|return
name|NodeType
operator|<
literal|0
return|;
block|}
comment|/// getMachineOpcode - This may only be called if isMachineOpcode returns
comment|/// true. It returns the MachineInstr opcode value that the node's opcode
comment|/// corresponds to.
name|unsigned
name|getMachineOpcode
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
name|isMachineOpcode
argument_list|()
operator|&&
literal|"Not a MachineInstr opcode!"
argument_list|)
block|;
return|return
operator|~
name|NodeType
return|;
block|}
comment|/// use_empty - Return true if there are no uses of this node.
comment|///
name|bool
name|use_empty
argument_list|()
specifier|const
block|{
return|return
name|UseList
operator|==
name|NULL
return|;
block|}
comment|/// hasOneUse - Return true if there is exactly one use of this node.
comment|///
name|bool
name|hasOneUse
argument_list|()
specifier|const
block|{
return|return
operator|!
name|use_empty
argument_list|()
operator|&&
name|next
argument_list|(
name|use_begin
argument_list|()
argument_list|)
operator|==
name|use_end
argument_list|()
return|;
block|}
comment|/// use_size - Return the number of uses of this node. This method takes
comment|/// time proportional to the number of uses.
comment|///
name|size_t
name|use_size
argument_list|()
specifier|const
block|{
return|return
name|std
operator|::
name|distance
argument_list|(
name|use_begin
argument_list|()
argument_list|,
name|use_end
argument_list|()
argument_list|)
return|;
block|}
comment|/// getNodeId - Return the unique node id.
comment|///
name|int
name|getNodeId
argument_list|()
specifier|const
block|{
return|return
name|NodeId
return|;
block|}
comment|/// setNodeId - Set unique node id.
name|void
name|setNodeId
argument_list|(
argument|int Id
argument_list|)
block|{
name|NodeId
operator|=
name|Id
block|; }
comment|/// getDebugLoc - Return the source location info.
specifier|const
name|DebugLoc
name|getDebugLoc
argument_list|()
specifier|const
block|{
return|return
name|debugLoc
return|;
block|}
comment|/// setDebugLoc - Set source location info.  Try to avoid this, putting
comment|/// it in the constructor is preferable.
name|void
name|setDebugLoc
argument_list|(
argument|const DebugLoc dl
argument_list|)
block|{
name|debugLoc
operator|=
name|dl
block|; }
comment|/// use_iterator - This class provides iterator support for SDUse
comment|/// operands that use a specific SDNode.
name|class
name|use_iterator
operator|:
name|public
name|std
operator|::
name|iterator
operator|<
name|std
operator|::
name|forward_iterator_tag
block|,
name|SDUse
block|,
name|ptrdiff_t
operator|>
block|{
name|SDUse
operator|*
name|Op
block|;
name|explicit
name|use_iterator
argument_list|(
name|SDUse
operator|*
name|op
argument_list|)
operator|:
name|Op
argument_list|(
argument|op
argument_list|)
block|{     }
name|friend
name|class
name|SDNode
block|;
name|public
operator|:
typedef|typedef
name|std
operator|::
name|iterator
operator|<
name|std
operator|::
name|forward_iterator_tag
operator|,
name|SDUse
operator|,
name|ptrdiff_t
operator|>
operator|::
name|reference
name|reference
expr_stmt|;
typedef|typedef
name|std
operator|::
name|iterator
operator|<
name|std
operator|::
name|forward_iterator_tag
operator|,
name|SDUse
operator|,
name|ptrdiff_t
operator|>
operator|::
name|pointer
name|pointer
expr_stmt|;
name|use_iterator
argument_list|(
specifier|const
name|use_iterator
operator|&
name|I
argument_list|)
operator|:
name|Op
argument_list|(
argument|I.Op
argument_list|)
block|{}
name|use_iterator
argument_list|()
operator|:
name|Op
argument_list|(
literal|0
argument_list|)
block|{}
name|bool
name|operator
operator|==
operator|(
specifier|const
name|use_iterator
operator|&
name|x
operator|)
specifier|const
block|{
return|return
name|Op
operator|==
name|x
operator|.
name|Op
return|;
block|}
name|bool
name|operator
operator|!=
operator|(
specifier|const
name|use_iterator
operator|&
name|x
operator|)
specifier|const
block|{
return|return
operator|!
name|operator
operator|==
operator|(
name|x
operator|)
return|;
block|}
comment|/// atEnd - return true if this iterator is at the end of uses list.
name|bool
name|atEnd
argument_list|()
specifier|const
block|{
return|return
name|Op
operator|==
literal|0
return|;
block|}
comment|// Iterator traversal: forward iteration only.
name|use_iterator
operator|&
name|operator
operator|++
operator|(
operator|)
block|{
comment|// Preincrement
name|assert
argument_list|(
name|Op
operator|&&
literal|"Cannot increment end iterator!"
argument_list|)
block|;
name|Op
operator|=
name|Op
operator|->
name|getNext
argument_list|()
block|;
return|return
operator|*
name|this
return|;
block|}
name|use_iterator
name|operator
operator|++
operator|(
name|int
operator|)
block|{
comment|// Postincrement
name|use_iterator
name|tmp
operator|=
operator|*
name|this
block|;
operator|++
operator|*
name|this
block|;
return|return
name|tmp
return|;
block|}
comment|/// Retrieve a pointer to the current user node.
name|SDNode
operator|*
name|operator
operator|*
operator|(
operator|)
specifier|const
block|{
name|assert
argument_list|(
name|Op
operator|&&
literal|"Cannot dereference end iterator!"
argument_list|)
block|;
return|return
name|Op
operator|->
name|getUser
argument_list|()
return|;
block|}
name|SDNode
operator|*
name|operator
operator|->
expr|(
block|)
specifier|const
block|{
return|return
name|operator
operator|*
operator|(
operator|)
return|;
block|}
name|SDUse
operator|&
name|getUse
argument_list|()
specifier|const
block|{
return|return
operator|*
name|Op
return|;
block|}
comment|/// getOperandNo - Retrieve the operand # of this use in its user.
comment|///
name|unsigned
name|getOperandNo
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
name|Op
operator|&&
literal|"Cannot dereference end iterator!"
argument_list|)
block|;
return|return
call|(
name|unsigned
call|)
argument_list|(
name|Op
operator|-
name|Op
operator|->
name|getUser
argument_list|()
operator|->
name|OperandList
argument_list|)
return|;
block|}
block|}
empty_stmt|;
comment|/// use_begin/use_end - Provide iteration support to walk over all uses
comment|/// of an SDNode.
name|use_iterator
name|use_begin
argument_list|()
specifier|const
block|{
return|return
name|use_iterator
argument_list|(
name|UseList
argument_list|)
return|;
block|}
specifier|static
name|use_iterator
name|use_end
parameter_list|()
block|{
return|return
name|use_iterator
argument_list|(
literal|0
argument_list|)
return|;
block|}
comment|/// hasNUsesOfValue - Return true if there are exactly NUSES uses of the
comment|/// indicated value.  This method ignores uses of other values defined by this
comment|/// operation.
name|bool
name|hasNUsesOfValue
argument_list|(
name|unsigned
name|NUses
argument_list|,
name|unsigned
name|Value
argument_list|)
decl|const
decl_stmt|;
comment|/// hasAnyUseOfValue - Return true if there are any use of the indicated
comment|/// value. This method ignores uses of other values defined by this operation.
name|bool
name|hasAnyUseOfValue
argument_list|(
name|unsigned
name|Value
argument_list|)
decl|const
decl_stmt|;
comment|/// isOnlyUserOf - Return true if this node is the only use of N.
comment|///
name|bool
name|isOnlyUserOf
argument_list|(
name|SDNode
operator|*
name|N
argument_list|)
decl|const
decl_stmt|;
comment|/// isOperandOf - Return true if this node is an operand of N.
comment|///
name|bool
name|isOperandOf
argument_list|(
name|SDNode
operator|*
name|N
argument_list|)
decl|const
decl_stmt|;
comment|/// isPredecessorOf - Return true if this node is a predecessor of N. This
comment|/// node is either an operand of N or it can be reached by recursively
comment|/// traversing up the operands.
comment|/// NOTE: this is an expensive method. Use it carefully.
name|bool
name|isPredecessorOf
argument_list|(
name|SDNode
operator|*
name|N
argument_list|)
decl|const
decl_stmt|;
comment|/// getNumOperands - Return the number of values used by this operation.
comment|///
name|unsigned
name|getNumOperands
argument_list|()
specifier|const
block|{
return|return
name|NumOperands
return|;
block|}
comment|/// getConstantOperandVal - Helper method returns the integer value of a
comment|/// ConstantSDNode operand.
name|uint64_t
name|getConstantOperandVal
argument_list|(
name|unsigned
name|Num
argument_list|)
decl|const
decl_stmt|;
specifier|const
name|SDValue
modifier|&
name|getOperand
argument_list|(
name|unsigned
name|Num
argument_list|)
decl|const
block|{
name|assert
argument_list|(
name|Num
operator|<
name|NumOperands
operator|&&
literal|"Invalid child # of SDNode!"
argument_list|)
expr_stmt|;
return|return
name|OperandList
index|[
name|Num
index|]
return|;
block|}
typedef|typedef
name|SDUse
modifier|*
name|op_iterator
typedef|;
name|op_iterator
name|op_begin
argument_list|()
specifier|const
block|{
return|return
name|OperandList
return|;
block|}
name|op_iterator
name|op_end
argument_list|()
specifier|const
block|{
return|return
name|OperandList
operator|+
name|NumOperands
return|;
block|}
name|SDVTList
name|getVTList
argument_list|()
specifier|const
block|{
name|SDVTList
name|X
operator|=
block|{
name|ValueList
block|,
name|NumValues
block|}
block|;
return|return
name|X
return|;
block|}
empty_stmt|;
comment|/// getFlaggedNode - If this node has a flag operand, return the node
comment|/// to which the flag operand points. Otherwise return NULL.
name|SDNode
operator|*
name|getFlaggedNode
argument_list|()
specifier|const
block|{
if|if
condition|(
name|getNumOperands
argument_list|()
operator|!=
literal|0
operator|&&
name|getOperand
argument_list|(
name|getNumOperands
argument_list|()
operator|-
literal|1
argument_list|)
operator|.
name|getValueType
argument_list|()
operator|.
name|getSimpleVT
argument_list|()
operator|==
name|MVT
operator|::
name|Flag
condition|)
return|return
name|getOperand
argument_list|(
name|getNumOperands
argument_list|()
operator|-
literal|1
argument_list|)
operator|.
name|getNode
argument_list|()
return|;
return|return
literal|0
return|;
block|}
end_decl_stmt

begin_comment
comment|// If this is a pseudo op, like copyfromreg, look to see if there is a
end_comment

begin_comment
comment|// real target node flagged to it.  If so, return the target node.
end_comment

begin_expr_stmt
specifier|const
name|SDNode
operator|*
name|getFlaggedMachineNode
argument_list|()
specifier|const
block|{
specifier|const
name|SDNode
operator|*
name|FoundNode
operator|=
name|this
block|;
comment|// Climb up flag edges until a machine-opcode node is found, or the
comment|// end of the chain is reached.
while|while
condition|(
operator|!
name|FoundNode
operator|->
name|isMachineOpcode
argument_list|()
condition|)
block|{
specifier|const
name|SDNode
modifier|*
name|N
init|=
name|FoundNode
operator|->
name|getFlaggedNode
argument_list|()
decl_stmt|;
if|if
condition|(
operator|!
name|N
condition|)
break|break;
name|FoundNode
operator|=
name|N
expr_stmt|;
block|}
end_expr_stmt

begin_return
return|return
name|FoundNode
return|;
end_return

begin_comment
unit|}
comment|/// getNumValues - Return the number of values defined/returned by this
end_comment

begin_comment
comment|/// operator.
end_comment

begin_comment
comment|///
end_comment

begin_macro
unit|unsigned
name|getNumValues
argument_list|()
end_macro

begin_expr_stmt
specifier|const
block|{
return|return
name|NumValues
return|;
block|}
end_expr_stmt

begin_comment
comment|/// getValueType - Return the type of a specified result.
end_comment

begin_comment
comment|///
end_comment

begin_decl_stmt
name|EVT
name|getValueType
argument_list|(
name|unsigned
name|ResNo
argument_list|)
decl|const
block|{
name|assert
argument_list|(
name|ResNo
operator|<
name|NumValues
operator|&&
literal|"Illegal result number!"
argument_list|)
expr_stmt|;
return|return
name|ValueList
index|[
name|ResNo
index|]
return|;
block|}
end_decl_stmt

begin_comment
comment|/// getValueSizeInBits - Returns MVT::getSizeInBits(getValueType(ResNo)).
end_comment

begin_comment
comment|///
end_comment

begin_decl_stmt
name|unsigned
name|getValueSizeInBits
argument_list|(
name|unsigned
name|ResNo
argument_list|)
decl|const
block|{
return|return
name|getValueType
argument_list|(
name|ResNo
argument_list|)
operator|.
name|getSizeInBits
argument_list|()
return|;
block|}
end_decl_stmt

begin_typedef
typedef|typedef
specifier|const
name|EVT
modifier|*
name|value_iterator
typedef|;
end_typedef

begin_expr_stmt
name|value_iterator
name|value_begin
argument_list|()
specifier|const
block|{
return|return
name|ValueList
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|value_iterator
name|value_end
argument_list|()
specifier|const
block|{
return|return
name|ValueList
operator|+
name|NumValues
return|;
block|}
end_expr_stmt

begin_comment
comment|/// getOperationName - Return the opcode of this operation for printing.
end_comment

begin_comment
comment|///
end_comment

begin_expr_stmt
name|std
operator|::
name|string
name|getOperationName
argument_list|(
argument|const SelectionDAG *G =
literal|0
argument_list|)
specifier|const
expr_stmt|;
end_expr_stmt

begin_decl_stmt
specifier|static
specifier|const
name|char
modifier|*
name|getIndexedModeName
argument_list|(
name|ISD
operator|::
name|MemIndexedMode
name|AM
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|print_types
argument_list|(
name|raw_ostream
operator|&
name|OS
argument_list|,
specifier|const
name|SelectionDAG
operator|*
name|G
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|print_details
argument_list|(
name|raw_ostream
operator|&
name|OS
argument_list|,
specifier|const
name|SelectionDAG
operator|*
name|G
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|print
argument_list|(
name|raw_ostream
operator|&
name|OS
argument_list|,
specifier|const
name|SelectionDAG
operator|*
name|G
operator|=
literal|0
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|printr
argument_list|(
name|raw_ostream
operator|&
name|OS
argument_list|,
specifier|const
name|SelectionDAG
operator|*
name|G
operator|=
literal|0
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|void
name|dump
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|void
name|dumpr
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt

begin_decl_stmt
name|void
name|dump
argument_list|(
specifier|const
name|SelectionDAG
operator|*
name|G
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|dumpr
argument_list|(
specifier|const
name|SelectionDAG
operator|*
name|G
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_function
specifier|static
name|bool
name|classof
parameter_list|(
specifier|const
name|SDNode
modifier|*
parameter_list|)
block|{
return|return
name|true
return|;
block|}
end_function

begin_comment
comment|/// Profile - Gather unique data for the node.
end_comment

begin_comment
comment|///
end_comment

begin_decl_stmt
name|void
name|Profile
argument_list|(
name|FoldingSetNodeID
operator|&
name|ID
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// addUse - This method should only be used by the SDUse class.
end_comment

begin_comment
comment|///
end_comment

begin_function
name|void
name|addUse
parameter_list|(
name|SDUse
modifier|&
name|U
parameter_list|)
block|{
name|U
operator|.
name|addToList
argument_list|(
operator|&
name|UseList
argument_list|)
expr_stmt|;
block|}
end_function

begin_label
name|protected
label|:
end_label

begin_function
specifier|static
name|SDVTList
name|getSDVTList
parameter_list|(
name|EVT
name|VT
parameter_list|)
block|{
name|SDVTList
name|Ret
init|=
block|{
name|getValueTypeList
argument_list|(
name|VT
argument_list|)
block|,
literal|1
block|}
decl_stmt|;
return|return
name|Ret
return|;
block|}
end_function

begin_macro
name|SDNode
argument_list|(
argument|unsigned Opc
argument_list|,
argument|const DebugLoc dl
argument_list|,
argument|SDVTList VTs
argument_list|,
argument|const SDValue *Ops
argument_list|,
argument|unsigned NumOps
argument_list|)
end_macro

begin_expr_stmt
unit|:
name|NodeType
argument_list|(
name|Opc
argument_list|)
operator|,
name|OperandsNeedDelete
argument_list|(
name|true
argument_list|)
operator|,
name|SubclassData
argument_list|(
literal|0
argument_list|)
operator|,
name|NodeId
argument_list|(
operator|-
literal|1
argument_list|)
operator|,
name|OperandList
argument_list|(
argument|NumOps ? new SDUse[NumOps] :
literal|0
argument_list|)
operator|,
name|ValueList
argument_list|(
name|VTs
operator|.
name|VTs
argument_list|)
operator|,
name|UseList
argument_list|(
name|NULL
argument_list|)
operator|,
name|NumOperands
argument_list|(
name|NumOps
argument_list|)
operator|,
name|NumValues
argument_list|(
name|VTs
operator|.
name|NumVTs
argument_list|)
operator|,
name|debugLoc
argument_list|(
argument|dl
argument_list|)
block|{
for|for
control|(
name|unsigned
name|i
init|=
literal|0
init|;
name|i
operator|!=
name|NumOps
condition|;
operator|++
name|i
control|)
block|{
name|OperandList
index|[
name|i
index|]
operator|.
name|setUser
argument_list|(
name|this
argument_list|)
expr_stmt|;
name|OperandList
index|[
name|i
index|]
operator|.
name|setInitial
argument_list|(
name|Ops
index|[
name|i
index|]
argument_list|)
expr_stmt|;
block|}
end_expr_stmt

begin_comment
unit|}
comment|/// This constructor adds no operands itself; operands can be
end_comment

begin_comment
comment|/// set later with InitOperands.
end_comment

begin_expr_stmt
unit|SDNode
operator|(
name|unsigned
name|Opc
operator|,
specifier|const
name|DebugLoc
name|dl
operator|,
name|SDVTList
name|VTs
operator|)
operator|:
name|NodeType
argument_list|(
name|Opc
argument_list|)
operator|,
name|OperandsNeedDelete
argument_list|(
name|false
argument_list|)
operator|,
name|SubclassData
argument_list|(
literal|0
argument_list|)
operator|,
name|NodeId
argument_list|(
operator|-
literal|1
argument_list|)
operator|,
name|OperandList
argument_list|(
literal|0
argument_list|)
operator|,
name|ValueList
argument_list|(
name|VTs
operator|.
name|VTs
argument_list|)
operator|,
name|UseList
argument_list|(
name|NULL
argument_list|)
operator|,
name|NumOperands
argument_list|(
literal|0
argument_list|)
operator|,
name|NumValues
argument_list|(
name|VTs
operator|.
name|NumVTs
argument_list|)
operator|,
name|debugLoc
argument_list|(
argument|dl
argument_list|)
block|{}
comment|/// InitOperands - Initialize the operands list of this with 1 operand.
name|void
name|InitOperands
argument_list|(
argument|SDUse *Ops
argument_list|,
argument|const SDValue&Op0
argument_list|)
block|{
name|Ops
index|[
literal|0
index|]
operator|.
name|setUser
argument_list|(
name|this
argument_list|)
block|;
name|Ops
index|[
literal|0
index|]
operator|.
name|setInitial
argument_list|(
name|Op0
argument_list|)
block|;
name|NumOperands
operator|=
literal|1
block|;
name|OperandList
operator|=
name|Ops
block|;   }
comment|/// InitOperands - Initialize the operands list of this with 2 operands.
name|void
name|InitOperands
argument_list|(
argument|SDUse *Ops
argument_list|,
argument|const SDValue&Op0
argument_list|,
argument|const SDValue&Op1
argument_list|)
block|{
name|Ops
index|[
literal|0
index|]
operator|.
name|setUser
argument_list|(
name|this
argument_list|)
block|;
name|Ops
index|[
literal|0
index|]
operator|.
name|setInitial
argument_list|(
name|Op0
argument_list|)
block|;
name|Ops
index|[
literal|1
index|]
operator|.
name|setUser
argument_list|(
name|this
argument_list|)
block|;
name|Ops
index|[
literal|1
index|]
operator|.
name|setInitial
argument_list|(
name|Op1
argument_list|)
block|;
name|NumOperands
operator|=
literal|2
block|;
name|OperandList
operator|=
name|Ops
block|;   }
comment|/// InitOperands - Initialize the operands list of this with 3 operands.
name|void
name|InitOperands
argument_list|(
argument|SDUse *Ops
argument_list|,
argument|const SDValue&Op0
argument_list|,
argument|const SDValue&Op1
argument_list|,
argument|const SDValue&Op2
argument_list|)
block|{
name|Ops
index|[
literal|0
index|]
operator|.
name|setUser
argument_list|(
name|this
argument_list|)
block|;
name|Ops
index|[
literal|0
index|]
operator|.
name|setInitial
argument_list|(
name|Op0
argument_list|)
block|;
name|Ops
index|[
literal|1
index|]
operator|.
name|setUser
argument_list|(
name|this
argument_list|)
block|;
name|Ops
index|[
literal|1
index|]
operator|.
name|setInitial
argument_list|(
name|Op1
argument_list|)
block|;
name|Ops
index|[
literal|2
index|]
operator|.
name|setUser
argument_list|(
name|this
argument_list|)
block|;
name|Ops
index|[
literal|2
index|]
operator|.
name|setInitial
argument_list|(
name|Op2
argument_list|)
block|;
name|NumOperands
operator|=
literal|3
block|;
name|OperandList
operator|=
name|Ops
block|;   }
comment|/// InitOperands - Initialize the operands list of this with 4 operands.
name|void
name|InitOperands
argument_list|(
argument|SDUse *Ops
argument_list|,
argument|const SDValue&Op0
argument_list|,
argument|const SDValue&Op1
argument_list|,
argument|const SDValue&Op2
argument_list|,
argument|const SDValue&Op3
argument_list|)
block|{
name|Ops
index|[
literal|0
index|]
operator|.
name|setUser
argument_list|(
name|this
argument_list|)
block|;
name|Ops
index|[
literal|0
index|]
operator|.
name|setInitial
argument_list|(
name|Op0
argument_list|)
block|;
name|Ops
index|[
literal|1
index|]
operator|.
name|setUser
argument_list|(
name|this
argument_list|)
block|;
name|Ops
index|[
literal|1
index|]
operator|.
name|setInitial
argument_list|(
name|Op1
argument_list|)
block|;
name|Ops
index|[
literal|2
index|]
operator|.
name|setUser
argument_list|(
name|this
argument_list|)
block|;
name|Ops
index|[
literal|2
index|]
operator|.
name|setInitial
argument_list|(
name|Op2
argument_list|)
block|;
name|Ops
index|[
literal|3
index|]
operator|.
name|setUser
argument_list|(
name|this
argument_list|)
block|;
name|Ops
index|[
literal|3
index|]
operator|.
name|setInitial
argument_list|(
name|Op3
argument_list|)
block|;
name|NumOperands
operator|=
literal|4
block|;
name|OperandList
operator|=
name|Ops
block|;   }
comment|/// InitOperands - Initialize the operands list of this with N operands.
name|void
name|InitOperands
argument_list|(
argument|SDUse *Ops
argument_list|,
argument|const SDValue *Vals
argument_list|,
argument|unsigned N
argument_list|)
block|{
for|for
control|(
name|unsigned
name|i
init|=
literal|0
init|;
name|i
operator|!=
name|N
condition|;
operator|++
name|i
control|)
block|{
name|Ops
index|[
name|i
index|]
operator|.
name|setUser
argument_list|(
name|this
argument_list|)
expr_stmt|;
name|Ops
index|[
name|i
index|]
operator|.
name|setInitial
argument_list|(
name|Vals
index|[
name|i
index|]
argument_list|)
expr_stmt|;
block|}
name|NumOperands
operator|=
name|N
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|OperandList
operator|=
name|Ops
expr_stmt|;
end_expr_stmt

begin_comment
unit|}
comment|/// DropOperands - Release the operands and set this node to have
end_comment

begin_comment
comment|/// zero operands.
end_comment

begin_expr_stmt
unit|void
name|DropOperands
argument_list|()
expr_stmt|;
end_expr_stmt

begin_comment
unit|};
comment|// Define inline functions from the SDValue class.
end_comment

begin_expr_stmt
specifier|inline
name|unsigned
name|SDValue
operator|::
name|getOpcode
argument_list|()
specifier|const
block|{
return|return
name|Node
operator|->
name|getOpcode
argument_list|()
return|;
block|}
end_expr_stmt

begin_expr_stmt
specifier|inline
name|EVT
name|SDValue
operator|::
name|getValueType
argument_list|()
specifier|const
block|{
return|return
name|Node
operator|->
name|getValueType
argument_list|(
name|ResNo
argument_list|)
return|;
block|}
end_expr_stmt

begin_expr_stmt
specifier|inline
name|unsigned
name|SDValue
operator|::
name|getNumOperands
argument_list|()
specifier|const
block|{
return|return
name|Node
operator|->
name|getNumOperands
argument_list|()
return|;
block|}
end_expr_stmt

begin_expr_stmt
specifier|inline
specifier|const
name|SDValue
operator|&
name|SDValue
operator|::
name|getOperand
argument_list|(
argument|unsigned i
argument_list|)
specifier|const
block|{
return|return
name|Node
operator|->
name|getOperand
argument_list|(
name|i
argument_list|)
return|;
block|}
end_expr_stmt

begin_expr_stmt
specifier|inline
name|uint64_t
name|SDValue
operator|::
name|getConstantOperandVal
argument_list|(
argument|unsigned i
argument_list|)
specifier|const
block|{
return|return
name|Node
operator|->
name|getConstantOperandVal
argument_list|(
name|i
argument_list|)
return|;
block|}
end_expr_stmt

begin_expr_stmt
specifier|inline
name|bool
name|SDValue
operator|::
name|isTargetOpcode
argument_list|()
specifier|const
block|{
return|return
name|Node
operator|->
name|isTargetOpcode
argument_list|()
return|;
block|}
end_expr_stmt

begin_expr_stmt
specifier|inline
name|bool
name|SDValue
operator|::
name|isTargetMemoryOpcode
argument_list|()
specifier|const
block|{
return|return
name|Node
operator|->
name|isTargetMemoryOpcode
argument_list|()
return|;
block|}
end_expr_stmt

begin_expr_stmt
specifier|inline
name|bool
name|SDValue
operator|::
name|isMachineOpcode
argument_list|()
specifier|const
block|{
return|return
name|Node
operator|->
name|isMachineOpcode
argument_list|()
return|;
block|}
end_expr_stmt

begin_expr_stmt
specifier|inline
name|unsigned
name|SDValue
operator|::
name|getMachineOpcode
argument_list|()
specifier|const
block|{
return|return
name|Node
operator|->
name|getMachineOpcode
argument_list|()
return|;
block|}
end_expr_stmt

begin_expr_stmt
specifier|inline
name|bool
name|SDValue
operator|::
name|use_empty
argument_list|()
specifier|const
block|{
return|return
operator|!
name|Node
operator|->
name|hasAnyUseOfValue
argument_list|(
name|ResNo
argument_list|)
return|;
block|}
end_expr_stmt

begin_expr_stmt
specifier|inline
name|bool
name|SDValue
operator|::
name|hasOneUse
argument_list|()
specifier|const
block|{
return|return
name|Node
operator|->
name|hasNUsesOfValue
argument_list|(
literal|1
argument_list|,
name|ResNo
argument_list|)
return|;
block|}
end_expr_stmt

begin_expr_stmt
specifier|inline
specifier|const
name|DebugLoc
name|SDValue
operator|::
name|getDebugLoc
argument_list|()
specifier|const
block|{
return|return
name|Node
operator|->
name|getDebugLoc
argument_list|()
return|;
block|}
end_expr_stmt

begin_comment
comment|// Define inline functions from the SDUse class.
end_comment

begin_expr_stmt
specifier|inline
name|void
name|SDUse
operator|::
name|set
argument_list|(
argument|const SDValue&V
argument_list|)
block|{
if|if
condition|(
name|Val
operator|.
name|getNode
argument_list|()
condition|)
name|removeFromList
argument_list|()
expr_stmt|;
name|Val
operator|=
name|V
expr_stmt|;
end_expr_stmt

begin_if
if|if
condition|(
name|V
operator|.
name|getNode
argument_list|()
condition|)
name|V
operator|.
name|getNode
argument_list|()
operator|->
name|addUse
argument_list|(
operator|*
name|this
argument_list|)
expr_stmt|;
end_if

begin_expr_stmt
unit|}  inline
name|void
name|SDUse
operator|::
name|setInitial
argument_list|(
argument|const SDValue&V
argument_list|)
block|{
name|Val
operator|=
name|V
block|;
name|V
operator|.
name|getNode
argument_list|()
operator|->
name|addUse
argument_list|(
operator|*
name|this
argument_list|)
block|; }
specifier|inline
name|void
name|SDUse
operator|::
name|setNode
argument_list|(
argument|SDNode *N
argument_list|)
block|{
if|if
condition|(
name|Val
operator|.
name|getNode
argument_list|()
condition|)
name|removeFromList
argument_list|()
expr_stmt|;
name|Val
operator|.
name|setNode
argument_list|(
name|N
argument_list|)
expr_stmt|;
end_expr_stmt

begin_if
if|if
condition|(
name|N
condition|)
name|N
operator|->
name|addUse
argument_list|(
operator|*
name|this
argument_list|)
expr_stmt|;
end_if

begin_comment
unit|}
comment|/// UnarySDNode - This class is used for single-operand SDNodes.  This is solely
end_comment

begin_comment
comment|/// to allow co-allocation of node operands with the node itself.
end_comment

begin_label
unit|class
name|UnarySDNode
label|:
end_label

begin_decl_stmt
name|public
name|SDNode
block|{
name|SDUse
name|Op
decl_stmt|;
name|public
label|:
name|UnarySDNode
argument_list|(
argument|unsigned Opc
argument_list|,
argument|DebugLoc dl
argument_list|,
argument|SDVTList VTs
argument_list|,
argument|SDValue X
argument_list|)
block|:
name|SDNode
argument_list|(
argument|Opc
argument_list|,
argument|dl
argument_list|,
argument|VTs
argument_list|)
block|{
name|InitOperands
argument_list|(
operator|&
name|Op
argument_list|,
name|X
argument_list|)
expr_stmt|;
block|}
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|/// BinarySDNode - This class is used for two-operand SDNodes.  This is solely
end_comment

begin_comment
comment|/// to allow co-allocation of node operands with the node itself.
end_comment

begin_decl_stmt
name|class
name|BinarySDNode
range|:
name|public
name|SDNode
block|{
name|SDUse
name|Ops
index|[
literal|2
index|]
block|;
name|public
operator|:
name|BinarySDNode
argument_list|(
argument|unsigned Opc
argument_list|,
argument|DebugLoc dl
argument_list|,
argument|SDVTList VTs
argument_list|,
argument|SDValue X
argument_list|,
argument|SDValue Y
argument_list|)
operator|:
name|SDNode
argument_list|(
argument|Opc
argument_list|,
argument|dl
argument_list|,
argument|VTs
argument_list|)
block|{
name|InitOperands
argument_list|(
name|Ops
argument_list|,
name|X
argument_list|,
name|Y
argument_list|)
block|;   }
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// TernarySDNode - This class is used for three-operand SDNodes. This is solely
end_comment

begin_comment
comment|/// to allow co-allocation of node operands with the node itself.
end_comment

begin_decl_stmt
name|class
name|TernarySDNode
range|:
name|public
name|SDNode
block|{
name|SDUse
name|Ops
index|[
literal|3
index|]
block|;
name|public
operator|:
name|TernarySDNode
argument_list|(
argument|unsigned Opc
argument_list|,
argument|DebugLoc dl
argument_list|,
argument|SDVTList VTs
argument_list|,
argument|SDValue X
argument_list|,
argument|SDValue Y
argument_list|,
argument|SDValue Z
argument_list|)
operator|:
name|SDNode
argument_list|(
argument|Opc
argument_list|,
argument|dl
argument_list|,
argument|VTs
argument_list|)
block|{
name|InitOperands
argument_list|(
name|Ops
argument_list|,
name|X
argument_list|,
name|Y
argument_list|,
name|Z
argument_list|)
block|;   }
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// HandleSDNode - This class is used to form a handle around another node that
end_comment

begin_comment
comment|/// is persistant and is updated across invocations of replaceAllUsesWith on its
end_comment

begin_comment
comment|/// operand.  This node should be directly created by end-users and not added to
end_comment

begin_comment
comment|/// the AllNodes list.
end_comment

begin_decl_stmt
name|class
name|HandleSDNode
range|:
name|public
name|SDNode
block|{
name|SDUse
name|Op
block|;
name|public
operator|:
comment|// FIXME: Remove the "noinline" attribute once<rdar://problem/5852746> is
comment|// fixed.
ifdef|#
directive|ifdef
name|__GNUC__
name|explicit
name|__attribute__
argument_list|(
argument|(__noinline__)
argument_list|)
name|HandleSDNode
argument_list|(
argument|SDValue X
argument_list|)
else|#
directive|else
name|explicit
name|HandleSDNode
argument_list|(
argument|SDValue X
argument_list|)
endif|#
directive|endif
operator|:
name|SDNode
argument_list|(
argument|ISD::HANDLENODE
argument_list|,
argument|DebugLoc::getUnknownLoc()
argument_list|,
argument|getSDVTList(MVT::Other)
argument_list|)
block|{
name|InitOperands
argument_list|(
operator|&
name|Op
argument_list|,
name|X
argument_list|)
block|;   }
operator|~
name|HandleSDNode
argument_list|()
block|;
specifier|const
name|SDValue
operator|&
name|getValue
argument_list|()
specifier|const
block|{
return|return
name|Op
return|;
block|}
expr|}
block|;
comment|/// Abstact virtual class for operations for memory operations
name|class
name|MemSDNode
operator|:
name|public
name|SDNode
block|{
name|private
operator|:
comment|// MemoryVT - VT of in-memory value.
name|EVT
name|MemoryVT
block|;
name|protected
operator|:
comment|/// MMO - Memory reference information.
name|MachineMemOperand
operator|*
name|MMO
block|;
name|public
operator|:
name|MemSDNode
argument_list|(
argument|unsigned Opc
argument_list|,
argument|DebugLoc dl
argument_list|,
argument|SDVTList VTs
argument_list|,
argument|EVT MemoryVT
argument_list|,
argument|MachineMemOperand *MMO
argument_list|)
block|;
name|MemSDNode
argument_list|(
argument|unsigned Opc
argument_list|,
argument|DebugLoc dl
argument_list|,
argument|SDVTList VTs
argument_list|,
argument|const SDValue *Ops
argument_list|,
argument|unsigned NumOps
argument_list|,
argument|EVT MemoryVT
argument_list|,
argument|MachineMemOperand *MMO
argument_list|)
block|;
name|bool
name|readMem
argument_list|()
specifier|const
block|{
return|return
name|MMO
operator|->
name|isLoad
argument_list|()
return|;
block|}
name|bool
name|writeMem
argument_list|()
specifier|const
block|{
return|return
name|MMO
operator|->
name|isStore
argument_list|()
return|;
block|}
comment|/// Returns alignment and volatility of the memory access
name|unsigned
name|getOriginalAlignment
argument_list|()
specifier|const
block|{
return|return
name|MMO
operator|->
name|getBaseAlignment
argument_list|()
return|;
block|}
name|unsigned
name|getAlignment
argument_list|()
specifier|const
block|{
return|return
name|MMO
operator|->
name|getAlignment
argument_list|()
return|;
block|}
comment|/// getRawSubclassData - Return the SubclassData value, which contains an
comment|/// encoding of the volatile flag, as well as bits used by subclasses. This
comment|/// function should only be used to compute a FoldingSetNodeID value.
name|unsigned
name|getRawSubclassData
argument_list|()
specifier|const
block|{
return|return
name|SubclassData
return|;
block|}
name|bool
name|isVolatile
argument_list|()
specifier|const
block|{
return|return
operator|(
name|SubclassData
operator|>>
literal|5
operator|)
operator|&
literal|1
return|;
block|}
comment|/// Returns the SrcValue and offset that describes the location of the access
specifier|const
name|Value
operator|*
name|getSrcValue
argument_list|()
specifier|const
block|{
return|return
name|MMO
operator|->
name|getValue
argument_list|()
return|;
block|}
name|int64_t
name|getSrcValueOffset
argument_list|()
specifier|const
block|{
return|return
name|MMO
operator|->
name|getOffset
argument_list|()
return|;
block|}
comment|/// getMemoryVT - Return the type of the in-memory value.
name|EVT
name|getMemoryVT
argument_list|()
specifier|const
block|{
return|return
name|MemoryVT
return|;
block|}
comment|/// getMemOperand - Return a MachineMemOperand object describing the memory
comment|/// reference performed by operation.
name|MachineMemOperand
operator|*
name|getMemOperand
argument_list|()
specifier|const
block|{
return|return
name|MMO
return|;
block|}
comment|/// refineAlignment - Update this MemSDNode's MachineMemOperand information
comment|/// to reflect the alignment of NewMMO, if it has a greater alignment.
comment|/// This must only be used when the new alignment applies to all users of
comment|/// this MachineMemOperand.
name|void
name|refineAlignment
argument_list|(
argument|const MachineMemOperand *NewMMO
argument_list|)
block|{
name|MMO
operator|->
name|refineAlignment
argument_list|(
name|NewMMO
argument_list|)
block|;   }
specifier|const
name|SDValue
operator|&
name|getChain
argument_list|()
specifier|const
block|{
return|return
name|getOperand
argument_list|(
literal|0
argument_list|)
return|;
block|}
specifier|const
name|SDValue
operator|&
name|getBasePtr
argument_list|()
specifier|const
block|{
return|return
name|getOperand
argument_list|(
name|getOpcode
argument_list|()
operator|==
name|ISD
operator|::
name|STORE
operator|?
literal|2
operator|:
literal|1
argument_list|)
return|;
block|}
comment|// Methods to support isa and dyn_cast
specifier|static
name|bool
name|classof
argument_list|(
argument|const MemSDNode *
argument_list|)
block|{
return|return
name|true
return|;
block|}
specifier|static
name|bool
name|classof
argument_list|(
argument|const SDNode *N
argument_list|)
block|{
comment|// For some targets, we lower some target intrinsics to a MemIntrinsicNode
comment|// with either an intrinsic or a target opcode.
return|return
name|N
operator|->
name|getOpcode
argument_list|()
operator|==
name|ISD
operator|::
name|LOAD
operator|||
name|N
operator|->
name|getOpcode
argument_list|()
operator|==
name|ISD
operator|::
name|STORE
operator|||
name|N
operator|->
name|getOpcode
argument_list|()
operator|==
name|ISD
operator|::
name|ATOMIC_CMP_SWAP
operator|||
name|N
operator|->
name|getOpcode
argument_list|()
operator|==
name|ISD
operator|::
name|ATOMIC_SWAP
operator|||
name|N
operator|->
name|getOpcode
argument_list|()
operator|==
name|ISD
operator|::
name|ATOMIC_LOAD_ADD
operator|||
name|N
operator|->
name|getOpcode
argument_list|()
operator|==
name|ISD
operator|::
name|ATOMIC_LOAD_SUB
operator|||
name|N
operator|->
name|getOpcode
argument_list|()
operator|==
name|ISD
operator|::
name|ATOMIC_LOAD_AND
operator|||
name|N
operator|->
name|getOpcode
argument_list|()
operator|==
name|ISD
operator|::
name|ATOMIC_LOAD_OR
operator|||
name|N
operator|->
name|getOpcode
argument_list|()
operator|==
name|ISD
operator|::
name|ATOMIC_LOAD_XOR
operator|||
name|N
operator|->
name|getOpcode
argument_list|()
operator|==
name|ISD
operator|::
name|ATOMIC_LOAD_NAND
operator|||
name|N
operator|->
name|getOpcode
argument_list|()
operator|==
name|ISD
operator|::
name|ATOMIC_LOAD_MIN
operator|||
name|N
operator|->
name|getOpcode
argument_list|()
operator|==
name|ISD
operator|::
name|ATOMIC_LOAD_MAX
operator|||
name|N
operator|->
name|getOpcode
argument_list|()
operator|==
name|ISD
operator|::
name|ATOMIC_LOAD_UMIN
operator|||
name|N
operator|->
name|getOpcode
argument_list|()
operator|==
name|ISD
operator|::
name|ATOMIC_LOAD_UMAX
operator|||
name|N
operator|->
name|isTargetMemoryOpcode
argument_list|()
return|;
block|}
expr|}
block|;
comment|/// AtomicSDNode - A SDNode reprenting atomic operations.
comment|///
name|class
name|AtomicSDNode
operator|:
name|public
name|MemSDNode
block|{
name|SDUse
name|Ops
index|[
literal|4
index|]
block|;
name|public
operator|:
comment|// Opc:   opcode for atomic
comment|// VTL:    value type list
comment|// Chain:  memory chain for operaand
comment|// Ptr:    address to update as a SDValue
comment|// Cmp:    compare value
comment|// Swp:    swap value
comment|// SrcVal: address to update as a Value (used for MemOperand)
comment|// Align:  alignment of memory
name|AtomicSDNode
argument_list|(
argument|unsigned Opc
argument_list|,
argument|DebugLoc dl
argument_list|,
argument|SDVTList VTL
argument_list|,
argument|EVT MemVT
argument_list|,
argument|SDValue Chain
argument_list|,
argument|SDValue Ptr
argument_list|,
argument|SDValue Cmp
argument_list|,
argument|SDValue Swp
argument_list|,
argument|MachineMemOperand *MMO
argument_list|)
operator|:
name|MemSDNode
argument_list|(
argument|Opc
argument_list|,
argument|dl
argument_list|,
argument|VTL
argument_list|,
argument|MemVT
argument_list|,
argument|MMO
argument_list|)
block|{
name|assert
argument_list|(
name|readMem
argument_list|()
operator|&&
literal|"Atomic MachineMemOperand is not a load!"
argument_list|)
block|;
name|assert
argument_list|(
name|writeMem
argument_list|()
operator|&&
literal|"Atomic MachineMemOperand is not a store!"
argument_list|)
block|;
name|InitOperands
argument_list|(
name|Ops
argument_list|,
name|Chain
argument_list|,
name|Ptr
argument_list|,
name|Cmp
argument_list|,
name|Swp
argument_list|)
block|;   }
name|AtomicSDNode
argument_list|(
argument|unsigned Opc
argument_list|,
argument|DebugLoc dl
argument_list|,
argument|SDVTList VTL
argument_list|,
argument|EVT MemVT
argument_list|,
argument|SDValue Chain
argument_list|,
argument|SDValue Ptr
argument_list|,
argument|SDValue Val
argument_list|,
argument|MachineMemOperand *MMO
argument_list|)
operator|:
name|MemSDNode
argument_list|(
argument|Opc
argument_list|,
argument|dl
argument_list|,
argument|VTL
argument_list|,
argument|MemVT
argument_list|,
argument|MMO
argument_list|)
block|{
name|assert
argument_list|(
name|readMem
argument_list|()
operator|&&
literal|"Atomic MachineMemOperand is not a load!"
argument_list|)
block|;
name|assert
argument_list|(
name|writeMem
argument_list|()
operator|&&
literal|"Atomic MachineMemOperand is not a store!"
argument_list|)
block|;
name|InitOperands
argument_list|(
name|Ops
argument_list|,
name|Chain
argument_list|,
name|Ptr
argument_list|,
name|Val
argument_list|)
block|;   }
specifier|const
name|SDValue
operator|&
name|getBasePtr
argument_list|()
specifier|const
block|{
return|return
name|getOperand
argument_list|(
literal|1
argument_list|)
return|;
block|}
specifier|const
name|SDValue
operator|&
name|getVal
argument_list|()
specifier|const
block|{
return|return
name|getOperand
argument_list|(
literal|2
argument_list|)
return|;
block|}
name|bool
name|isCompareAndSwap
argument_list|()
specifier|const
block|{
name|unsigned
name|Op
operator|=
name|getOpcode
argument_list|()
block|;
return|return
name|Op
operator|==
name|ISD
operator|::
name|ATOMIC_CMP_SWAP
return|;
block|}
comment|// Methods to support isa and dyn_cast
specifier|static
name|bool
name|classof
argument_list|(
argument|const AtomicSDNode *
argument_list|)
block|{
return|return
name|true
return|;
block|}
specifier|static
name|bool
name|classof
argument_list|(
argument|const SDNode *N
argument_list|)
block|{
return|return
name|N
operator|->
name|getOpcode
argument_list|()
operator|==
name|ISD
operator|::
name|ATOMIC_CMP_SWAP
operator|||
name|N
operator|->
name|getOpcode
argument_list|()
operator|==
name|ISD
operator|::
name|ATOMIC_SWAP
operator|||
name|N
operator|->
name|getOpcode
argument_list|()
operator|==
name|ISD
operator|::
name|ATOMIC_LOAD_ADD
operator|||
name|N
operator|->
name|getOpcode
argument_list|()
operator|==
name|ISD
operator|::
name|ATOMIC_LOAD_SUB
operator|||
name|N
operator|->
name|getOpcode
argument_list|()
operator|==
name|ISD
operator|::
name|ATOMIC_LOAD_AND
operator|||
name|N
operator|->
name|getOpcode
argument_list|()
operator|==
name|ISD
operator|::
name|ATOMIC_LOAD_OR
operator|||
name|N
operator|->
name|getOpcode
argument_list|()
operator|==
name|ISD
operator|::
name|ATOMIC_LOAD_XOR
operator|||
name|N
operator|->
name|getOpcode
argument_list|()
operator|==
name|ISD
operator|::
name|ATOMIC_LOAD_NAND
operator|||
name|N
operator|->
name|getOpcode
argument_list|()
operator|==
name|ISD
operator|::
name|ATOMIC_LOAD_MIN
operator|||
name|N
operator|->
name|getOpcode
argument_list|()
operator|==
name|ISD
operator|::
name|ATOMIC_LOAD_MAX
operator|||
name|N
operator|->
name|getOpcode
argument_list|()
operator|==
name|ISD
operator|::
name|ATOMIC_LOAD_UMIN
operator|||
name|N
operator|->
name|getOpcode
argument_list|()
operator|==
name|ISD
operator|::
name|ATOMIC_LOAD_UMAX
return|;
block|}
expr|}
block|;
comment|/// MemIntrinsicSDNode - This SDNode is used for target intrinsics that touch
comment|/// memory and need an associated MachineMemOperand. Its opcode may be
comment|/// INTRINSIC_VOID, INTRINSIC_W_CHAIN, or a target-specific opcode with a
comment|/// value not less than FIRST_TARGET_MEMORY_OPCODE.
name|class
name|MemIntrinsicSDNode
operator|:
name|public
name|MemSDNode
block|{
name|public
operator|:
name|MemIntrinsicSDNode
argument_list|(
argument|unsigned Opc
argument_list|,
argument|DebugLoc dl
argument_list|,
argument|SDVTList VTs
argument_list|,
argument|const SDValue *Ops
argument_list|,
argument|unsigned NumOps
argument_list|,
argument|EVT MemoryVT
argument_list|,
argument|MachineMemOperand *MMO
argument_list|)
operator|:
name|MemSDNode
argument_list|(
argument|Opc
argument_list|,
argument|dl
argument_list|,
argument|VTs
argument_list|,
argument|Ops
argument_list|,
argument|NumOps
argument_list|,
argument|MemoryVT
argument_list|,
argument|MMO
argument_list|)
block|{   }
comment|// Methods to support isa and dyn_cast
specifier|static
name|bool
name|classof
argument_list|(
argument|const MemIntrinsicSDNode *
argument_list|)
block|{
return|return
name|true
return|;
block|}
specifier|static
name|bool
name|classof
argument_list|(
argument|const SDNode *N
argument_list|)
block|{
comment|// We lower some target intrinsics to their target opcode
comment|// early a node with a target opcode can be of this class
return|return
name|N
operator|->
name|getOpcode
argument_list|()
operator|==
name|ISD
operator|::
name|INTRINSIC_W_CHAIN
operator|||
name|N
operator|->
name|getOpcode
argument_list|()
operator|==
name|ISD
operator|::
name|INTRINSIC_VOID
operator|||
name|N
operator|->
name|isTargetMemoryOpcode
argument_list|()
return|;
block|}
expr|}
block|;
comment|/// ShuffleVectorSDNode - This SDNode is used to implement the code generator
comment|/// support for the llvm IR shufflevector instruction.  It combines elements
comment|/// from two input vectors into a new input vector, with the selection and
comment|/// ordering of elements determined by an array of integers, referred to as
comment|/// the shuffle mask.  For input vectors of width N, mask indices of 0..N-1
comment|/// refer to elements from the LHS input, and indices from N to 2N-1 the RHS.
comment|/// An index of -1 is treated as undef, such that the code generator may put
comment|/// any value in the corresponding element of the result.
name|class
name|ShuffleVectorSDNode
operator|:
name|public
name|SDNode
block|{
name|SDUse
name|Ops
index|[
literal|2
index|]
block|;
comment|// The memory for Mask is owned by the SelectionDAG's OperandAllocator, and
comment|// is freed when the SelectionDAG object is destroyed.
specifier|const
name|int
operator|*
name|Mask
block|;
name|protected
operator|:
name|friend
name|class
name|SelectionDAG
block|;
name|ShuffleVectorSDNode
argument_list|(
argument|EVT VT
argument_list|,
argument|DebugLoc dl
argument_list|,
argument|SDValue N1
argument_list|,
argument|SDValue N2
argument_list|,
argument|const int *M
argument_list|)
operator|:
name|SDNode
argument_list|(
name|ISD
operator|::
name|VECTOR_SHUFFLE
argument_list|,
name|dl
argument_list|,
name|getSDVTList
argument_list|(
name|VT
argument_list|)
argument_list|)
block|,
name|Mask
argument_list|(
argument|M
argument_list|)
block|{
name|InitOperands
argument_list|(
name|Ops
argument_list|,
name|N1
argument_list|,
name|N2
argument_list|)
block|;   }
name|public
operator|:
name|void
name|getMask
argument_list|(
argument|SmallVectorImpl<int>&M
argument_list|)
specifier|const
block|{
name|EVT
name|VT
operator|=
name|getValueType
argument_list|(
literal|0
argument_list|)
block|;
name|M
operator|.
name|clear
argument_list|()
block|;
for|for
control|(
name|unsigned
name|i
init|=
literal|0
init|,
name|e
init|=
name|VT
operator|.
name|getVectorNumElements
argument_list|()
init|;
name|i
operator|!=
name|e
condition|;
operator|++
name|i
control|)
name|M
operator|.
name|push_back
argument_list|(
name|Mask
index|[
name|i
index|]
argument_list|)
expr_stmt|;
block|}
name|int
name|getMaskElt
argument_list|(
argument|unsigned Idx
argument_list|)
specifier|const
block|{
name|assert
argument_list|(
name|Idx
operator|<
name|getValueType
argument_list|(
literal|0
argument_list|)
operator|.
name|getVectorNumElements
argument_list|()
operator|&&
literal|"Idx out of range!"
argument_list|)
block|;
return|return
name|Mask
index|[
name|Idx
index|]
return|;
block|}
name|bool
name|isSplat
argument_list|()
specifier|const
block|{
return|return
name|isSplatMask
argument_list|(
name|Mask
argument_list|,
name|getValueType
argument_list|(
literal|0
argument_list|)
argument_list|)
return|;
block|}
name|int
name|getSplatIndex
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
name|isSplat
argument_list|()
operator|&&
literal|"Cannot get splat index for non-splat!"
argument_list|)
block|;
return|return
name|Mask
index|[
literal|0
index|]
return|;
block|}
specifier|static
name|bool
name|isSplatMask
argument_list|(
argument|const int *Mask
argument_list|,
argument|EVT VT
argument_list|)
block|;
specifier|static
name|bool
name|classof
argument_list|(
argument|const ShuffleVectorSDNode *
argument_list|)
block|{
return|return
name|true
return|;
block|}
specifier|static
name|bool
name|classof
argument_list|(
argument|const SDNode *N
argument_list|)
block|{
return|return
name|N
operator|->
name|getOpcode
argument_list|()
operator|==
name|ISD
operator|::
name|VECTOR_SHUFFLE
return|;
block|}
expr|}
block|;
name|class
name|ConstantSDNode
operator|:
name|public
name|SDNode
block|{
specifier|const
name|ConstantInt
operator|*
name|Value
block|;
name|friend
name|class
name|SelectionDAG
block|;
name|ConstantSDNode
argument_list|(
argument|bool isTarget
argument_list|,
argument|const ConstantInt *val
argument_list|,
argument|EVT VT
argument_list|)
operator|:
name|SDNode
argument_list|(
name|isTarget
condition|?
name|ISD
operator|::
name|TargetConstant
else|:
name|ISD
operator|::
name|Constant
argument_list|,
name|DebugLoc
operator|::
name|getUnknownLoc
argument_list|()
argument_list|,
name|getSDVTList
argument_list|(
name|VT
argument_list|)
argument_list|)
block|,
name|Value
argument_list|(
argument|val
argument_list|)
block|{   }
name|public
operator|:
specifier|const
name|ConstantInt
operator|*
name|getConstantIntValue
argument_list|()
specifier|const
block|{
return|return
name|Value
return|;
block|}
specifier|const
name|APInt
operator|&
name|getAPIntValue
argument_list|()
specifier|const
block|{
return|return
name|Value
operator|->
name|getValue
argument_list|()
return|;
block|}
name|uint64_t
name|getZExtValue
argument_list|()
specifier|const
block|{
return|return
name|Value
operator|->
name|getZExtValue
argument_list|()
return|;
block|}
name|int64_t
name|getSExtValue
argument_list|()
specifier|const
block|{
return|return
name|Value
operator|->
name|getSExtValue
argument_list|()
return|;
block|}
name|bool
name|isNullValue
argument_list|()
specifier|const
block|{
return|return
name|Value
operator|->
name|isNullValue
argument_list|()
return|;
block|}
name|bool
name|isAllOnesValue
argument_list|()
specifier|const
block|{
return|return
name|Value
operator|->
name|isAllOnesValue
argument_list|()
return|;
block|}
specifier|static
name|bool
name|classof
argument_list|(
argument|const ConstantSDNode *
argument_list|)
block|{
return|return
name|true
return|;
block|}
specifier|static
name|bool
name|classof
argument_list|(
argument|const SDNode *N
argument_list|)
block|{
return|return
name|N
operator|->
name|getOpcode
argument_list|()
operator|==
name|ISD
operator|::
name|Constant
operator|||
name|N
operator|->
name|getOpcode
argument_list|()
operator|==
name|ISD
operator|::
name|TargetConstant
return|;
block|}
expr|}
block|;
name|class
name|ConstantFPSDNode
operator|:
name|public
name|SDNode
block|{
specifier|const
name|ConstantFP
operator|*
name|Value
block|;
name|friend
name|class
name|SelectionDAG
block|;
name|ConstantFPSDNode
argument_list|(
argument|bool isTarget
argument_list|,
argument|const ConstantFP *val
argument_list|,
argument|EVT VT
argument_list|)
operator|:
name|SDNode
argument_list|(
name|isTarget
condition|?
name|ISD
operator|::
name|TargetConstantFP
else|:
name|ISD
operator|::
name|ConstantFP
argument_list|,
name|DebugLoc
operator|::
name|getUnknownLoc
argument_list|()
argument_list|,
name|getSDVTList
argument_list|(
name|VT
argument_list|)
argument_list|)
block|,
name|Value
argument_list|(
argument|val
argument_list|)
block|{   }
name|public
operator|:
specifier|const
name|APFloat
operator|&
name|getValueAPF
argument_list|()
specifier|const
block|{
return|return
name|Value
operator|->
name|getValueAPF
argument_list|()
return|;
block|}
specifier|const
name|ConstantFP
operator|*
name|getConstantFPValue
argument_list|()
specifier|const
block|{
return|return
name|Value
return|;
block|}
comment|/// isExactlyValue - We don't rely on operator== working on double values, as
comment|/// it returns true for things that are clearly not equal, like -0.0 and 0.0.
comment|/// As such, this method can be used to do an exact bit-for-bit comparison of
comment|/// two floating point values.
comment|/// We leave the version with the double argument here because it's just so
comment|/// convenient to write "2.0" and the like.  Without this function we'd
comment|/// have to duplicate its logic everywhere it's called.
name|bool
name|isExactlyValue
argument_list|(
argument|double V
argument_list|)
specifier|const
block|{
name|bool
name|ignored
block|;
comment|// convert is not supported on this type
if|if
condition|(
operator|&
name|Value
operator|->
name|getValueAPF
argument_list|()
operator|.
name|getSemantics
argument_list|()
operator|==
operator|&
name|APFloat
operator|::
name|PPCDoubleDouble
condition|)
return|return
name|false
return|;
name|APFloat
name|Tmp
argument_list|(
name|V
argument_list|)
block|;
name|Tmp
operator|.
name|convert
argument_list|(
name|Value
operator|->
name|getValueAPF
argument_list|()
operator|.
name|getSemantics
argument_list|()
argument_list|,
name|APFloat
operator|::
name|rmNearestTiesToEven
argument_list|,
operator|&
name|ignored
argument_list|)
block|;
return|return
name|isExactlyValue
argument_list|(
name|Tmp
argument_list|)
return|;
block|}
name|bool
name|isExactlyValue
argument_list|(
argument|const APFloat& V
argument_list|)
specifier|const
block|;
name|bool
name|isValueValidForType
argument_list|(
argument|EVT VT
argument_list|,
argument|const APFloat& Val
argument_list|)
block|;
specifier|static
name|bool
name|classof
argument_list|(
argument|const ConstantFPSDNode *
argument_list|)
block|{
return|return
name|true
return|;
block|}
specifier|static
name|bool
name|classof
argument_list|(
argument|const SDNode *N
argument_list|)
block|{
return|return
name|N
operator|->
name|getOpcode
argument_list|()
operator|==
name|ISD
operator|::
name|ConstantFP
operator|||
name|N
operator|->
name|getOpcode
argument_list|()
operator|==
name|ISD
operator|::
name|TargetConstantFP
return|;
block|}
expr|}
block|;
name|class
name|GlobalAddressSDNode
operator|:
name|public
name|SDNode
block|{
name|GlobalValue
operator|*
name|TheGlobal
block|;
name|int64_t
name|Offset
block|;
name|unsigned
name|char
name|TargetFlags
block|;
name|friend
name|class
name|SelectionDAG
block|;
name|GlobalAddressSDNode
argument_list|(
argument|unsigned Opc
argument_list|,
argument|const GlobalValue *GA
argument_list|,
argument|EVT VT
argument_list|,
argument|int64_t o
argument_list|,
argument|unsigned char TargetFlags
argument_list|)
block|;
name|public
operator|:
name|GlobalValue
operator|*
name|getGlobal
argument_list|()
specifier|const
block|{
return|return
name|TheGlobal
return|;
block|}
name|int64_t
name|getOffset
argument_list|()
specifier|const
block|{
return|return
name|Offset
return|;
block|}
name|unsigned
name|char
name|getTargetFlags
argument_list|()
specifier|const
block|{
return|return
name|TargetFlags
return|;
block|}
comment|// Return the address space this GlobalAddress belongs to.
name|unsigned
name|getAddressSpace
argument_list|()
specifier|const
block|;
specifier|static
name|bool
name|classof
argument_list|(
argument|const GlobalAddressSDNode *
argument_list|)
block|{
return|return
name|true
return|;
block|}
specifier|static
name|bool
name|classof
argument_list|(
argument|const SDNode *N
argument_list|)
block|{
return|return
name|N
operator|->
name|getOpcode
argument_list|()
operator|==
name|ISD
operator|::
name|GlobalAddress
operator|||
name|N
operator|->
name|getOpcode
argument_list|()
operator|==
name|ISD
operator|::
name|TargetGlobalAddress
operator|||
name|N
operator|->
name|getOpcode
argument_list|()
operator|==
name|ISD
operator|::
name|GlobalTLSAddress
operator|||
name|N
operator|->
name|getOpcode
argument_list|()
operator|==
name|ISD
operator|::
name|TargetGlobalTLSAddress
return|;
block|}
expr|}
block|;
name|class
name|FrameIndexSDNode
operator|:
name|public
name|SDNode
block|{
name|int
name|FI
block|;
name|friend
name|class
name|SelectionDAG
block|;
name|FrameIndexSDNode
argument_list|(
argument|int fi
argument_list|,
argument|EVT VT
argument_list|,
argument|bool isTarg
argument_list|)
operator|:
name|SDNode
argument_list|(
name|isTarg
condition|?
name|ISD
operator|::
name|TargetFrameIndex
else|:
name|ISD
operator|::
name|FrameIndex
argument_list|,
name|DebugLoc
operator|::
name|getUnknownLoc
argument_list|()
argument_list|,
name|getSDVTList
argument_list|(
name|VT
argument_list|)
argument_list|)
block|,
name|FI
argument_list|(
argument|fi
argument_list|)
block|{   }
name|public
operator|:
name|int
name|getIndex
argument_list|()
specifier|const
block|{
return|return
name|FI
return|;
block|}
specifier|static
name|bool
name|classof
argument_list|(
argument|const FrameIndexSDNode *
argument_list|)
block|{
return|return
name|true
return|;
block|}
specifier|static
name|bool
name|classof
argument_list|(
argument|const SDNode *N
argument_list|)
block|{
return|return
name|N
operator|->
name|getOpcode
argument_list|()
operator|==
name|ISD
operator|::
name|FrameIndex
operator|||
name|N
operator|->
name|getOpcode
argument_list|()
operator|==
name|ISD
operator|::
name|TargetFrameIndex
return|;
block|}
expr|}
block|;
name|class
name|JumpTableSDNode
operator|:
name|public
name|SDNode
block|{
name|int
name|JTI
block|;
name|unsigned
name|char
name|TargetFlags
block|;
name|friend
name|class
name|SelectionDAG
block|;
name|JumpTableSDNode
argument_list|(
argument|int jti
argument_list|,
argument|EVT VT
argument_list|,
argument|bool isTarg
argument_list|,
argument|unsigned char TF
argument_list|)
operator|:
name|SDNode
argument_list|(
name|isTarg
condition|?
name|ISD
operator|::
name|TargetJumpTable
else|:
name|ISD
operator|::
name|JumpTable
argument_list|,
name|DebugLoc
operator|::
name|getUnknownLoc
argument_list|()
argument_list|,
name|getSDVTList
argument_list|(
name|VT
argument_list|)
argument_list|)
block|,
name|JTI
argument_list|(
name|jti
argument_list|)
block|,
name|TargetFlags
argument_list|(
argument|TF
argument_list|)
block|{   }
name|public
operator|:
name|int
name|getIndex
argument_list|()
specifier|const
block|{
return|return
name|JTI
return|;
block|}
name|unsigned
name|char
name|getTargetFlags
argument_list|()
specifier|const
block|{
return|return
name|TargetFlags
return|;
block|}
specifier|static
name|bool
name|classof
argument_list|(
argument|const JumpTableSDNode *
argument_list|)
block|{
return|return
name|true
return|;
block|}
specifier|static
name|bool
name|classof
argument_list|(
argument|const SDNode *N
argument_list|)
block|{
return|return
name|N
operator|->
name|getOpcode
argument_list|()
operator|==
name|ISD
operator|::
name|JumpTable
operator|||
name|N
operator|->
name|getOpcode
argument_list|()
operator|==
name|ISD
operator|::
name|TargetJumpTable
return|;
block|}
expr|}
block|;
name|class
name|ConstantPoolSDNode
operator|:
name|public
name|SDNode
block|{
expr|union
block|{
name|Constant
operator|*
name|ConstVal
block|;
name|MachineConstantPoolValue
operator|*
name|MachineCPVal
block|;   }
name|Val
block|;
name|int
name|Offset
block|;
comment|// It's a MachineConstantPoolValue if top bit is set.
name|unsigned
name|Alignment
block|;
comment|// Minimum alignment requirement of CP (not log2 value).
name|unsigned
name|char
name|TargetFlags
block|;
name|friend
name|class
name|SelectionDAG
block|;
name|ConstantPoolSDNode
argument_list|(
argument|bool isTarget
argument_list|,
argument|Constant *c
argument_list|,
argument|EVT VT
argument_list|,
argument|int o
argument_list|,
argument|unsigned Align
argument_list|,
argument|unsigned char TF
argument_list|)
operator|:
name|SDNode
argument_list|(
name|isTarget
condition|?
name|ISD
operator|::
name|TargetConstantPool
else|:
name|ISD
operator|::
name|ConstantPool
argument_list|,
name|DebugLoc
operator|::
name|getUnknownLoc
argument_list|()
argument_list|,
name|getSDVTList
argument_list|(
name|VT
argument_list|)
argument_list|)
block|,
name|Offset
argument_list|(
name|o
argument_list|)
block|,
name|Alignment
argument_list|(
name|Align
argument_list|)
block|,
name|TargetFlags
argument_list|(
argument|TF
argument_list|)
block|{
name|assert
argument_list|(
operator|(
name|int
operator|)
name|Offset
operator|>=
literal|0
operator|&&
literal|"Offset is too large"
argument_list|)
block|;
name|Val
operator|.
name|ConstVal
operator|=
name|c
block|;   }
name|ConstantPoolSDNode
argument_list|(
argument|bool isTarget
argument_list|,
argument|MachineConstantPoolValue *v
argument_list|,
argument|EVT VT
argument_list|,
argument|int o
argument_list|,
argument|unsigned Align
argument_list|,
argument|unsigned char TF
argument_list|)
operator|:
name|SDNode
argument_list|(
name|isTarget
condition|?
name|ISD
operator|::
name|TargetConstantPool
else|:
name|ISD
operator|::
name|ConstantPool
argument_list|,
name|DebugLoc
operator|::
name|getUnknownLoc
argument_list|()
argument_list|,
name|getSDVTList
argument_list|(
name|VT
argument_list|)
argument_list|)
block|,
name|Offset
argument_list|(
name|o
argument_list|)
block|,
name|Alignment
argument_list|(
name|Align
argument_list|)
block|,
name|TargetFlags
argument_list|(
argument|TF
argument_list|)
block|{
name|assert
argument_list|(
operator|(
name|int
operator|)
name|Offset
operator|>=
literal|0
operator|&&
literal|"Offset is too large"
argument_list|)
block|;
name|Val
operator|.
name|MachineCPVal
operator|=
name|v
block|;
name|Offset
operator||=
literal|1
operator|<<
operator|(
sizeof|sizeof
argument_list|(
name|unsigned
argument_list|)
operator|*
name|CHAR_BIT
operator|-
literal|1
operator|)
block|;   }
name|public
operator|:
name|bool
name|isMachineConstantPoolEntry
argument_list|()
specifier|const
block|{
return|return
operator|(
name|int
operator|)
name|Offset
operator|<
literal|0
return|;
block|}
name|Constant
operator|*
name|getConstVal
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
operator|!
name|isMachineConstantPoolEntry
argument_list|()
operator|&&
literal|"Wrong constantpool type"
argument_list|)
block|;
return|return
name|Val
operator|.
name|ConstVal
return|;
block|}
name|MachineConstantPoolValue
operator|*
name|getMachineCPVal
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
name|isMachineConstantPoolEntry
argument_list|()
operator|&&
literal|"Wrong constantpool type"
argument_list|)
block|;
return|return
name|Val
operator|.
name|MachineCPVal
return|;
block|}
name|int
name|getOffset
argument_list|()
specifier|const
block|{
return|return
name|Offset
operator|&
operator|~
operator|(
literal|1
operator|<<
operator|(
sizeof|sizeof
argument_list|(
name|unsigned
argument_list|)
operator|*
name|CHAR_BIT
operator|-
literal|1
operator|)
operator|)
return|;
block|}
comment|// Return the alignment of this constant pool object, which is either 0 (for
comment|// default alignment) or the desired value.
name|unsigned
name|getAlignment
argument_list|()
specifier|const
block|{
return|return
name|Alignment
return|;
block|}
name|unsigned
name|char
name|getTargetFlags
argument_list|()
specifier|const
block|{
return|return
name|TargetFlags
return|;
block|}
specifier|const
name|Type
operator|*
name|getType
argument_list|()
specifier|const
block|;
specifier|static
name|bool
name|classof
argument_list|(
argument|const ConstantPoolSDNode *
argument_list|)
block|{
return|return
name|true
return|;
block|}
specifier|static
name|bool
name|classof
argument_list|(
argument|const SDNode *N
argument_list|)
block|{
return|return
name|N
operator|->
name|getOpcode
argument_list|()
operator|==
name|ISD
operator|::
name|ConstantPool
operator|||
name|N
operator|->
name|getOpcode
argument_list|()
operator|==
name|ISD
operator|::
name|TargetConstantPool
return|;
block|}
expr|}
block|;
name|class
name|BasicBlockSDNode
operator|:
name|public
name|SDNode
block|{
name|MachineBasicBlock
operator|*
name|MBB
block|;
name|friend
name|class
name|SelectionDAG
block|;
comment|/// Debug info is meaningful and potentially useful here, but we create
comment|/// blocks out of order when they're jumped to, which makes it a bit
comment|/// harder.  Let's see if we need it first.
name|explicit
name|BasicBlockSDNode
argument_list|(
name|MachineBasicBlock
operator|*
name|mbb
argument_list|)
operator|:
name|SDNode
argument_list|(
name|ISD
operator|::
name|BasicBlock
argument_list|,
name|DebugLoc
operator|::
name|getUnknownLoc
argument_list|()
argument_list|,
name|getSDVTList
argument_list|(
name|MVT
operator|::
name|Other
argument_list|)
argument_list|)
block|,
name|MBB
argument_list|(
argument|mbb
argument_list|)
block|{   }
name|public
operator|:
name|MachineBasicBlock
operator|*
name|getBasicBlock
argument_list|()
specifier|const
block|{
return|return
name|MBB
return|;
block|}
specifier|static
name|bool
name|classof
argument_list|(
argument|const BasicBlockSDNode *
argument_list|)
block|{
return|return
name|true
return|;
block|}
specifier|static
name|bool
name|classof
argument_list|(
argument|const SDNode *N
argument_list|)
block|{
return|return
name|N
operator|->
name|getOpcode
argument_list|()
operator|==
name|ISD
operator|::
name|BasicBlock
return|;
block|}
expr|}
block|;
comment|/// BuildVectorSDNode - A "pseudo-class" with methods for operating on
comment|/// BUILD_VECTORs.
name|class
name|BuildVectorSDNode
operator|:
name|public
name|SDNode
block|{
comment|// These are constructed as SDNodes and then cast to BuildVectorSDNodes.
name|explicit
name|BuildVectorSDNode
argument_list|()
block|;
comment|// Do not implement
name|public
operator|:
comment|/// isConstantSplat - Check if this is a constant splat, and if so, find the
comment|/// smallest element size that splats the vector.  If MinSplatBits is
comment|/// nonzero, the element size must be at least that large.  Note that the
comment|/// splat element may be the entire vector (i.e., a one element vector).
comment|/// Returns the splat element value in SplatValue.  Any undefined bits in
comment|/// that value are zero, and the corresponding bits in the SplatUndef mask
comment|/// are set.  The SplatBitSize value is set to the splat element size in
comment|/// bits.  HasAnyUndefs is set to true if any bits in the vector are
comment|/// undefined.
name|bool
name|isConstantSplat
argument_list|(
argument|APInt&SplatValue
argument_list|,
argument|APInt&SplatUndef
argument_list|,
argument|unsigned&SplatBitSize
argument_list|,
argument|bool&HasAnyUndefs
argument_list|,
argument|unsigned MinSplatBits =
literal|0
argument_list|)
block|;
specifier|static
specifier|inline
name|bool
name|classof
argument_list|(
argument|const BuildVectorSDNode *
argument_list|)
block|{
return|return
name|true
return|;
block|}
specifier|static
specifier|inline
name|bool
name|classof
argument_list|(
argument|const SDNode *N
argument_list|)
block|{
return|return
name|N
operator|->
name|getOpcode
argument_list|()
operator|==
name|ISD
operator|::
name|BUILD_VECTOR
return|;
block|}
expr|}
block|;
comment|/// SrcValueSDNode - An SDNode that holds an arbitrary LLVM IR Value. This is
comment|/// used when the SelectionDAG needs to make a simple reference to something
comment|/// in the LLVM IR representation.
comment|///
name|class
name|SrcValueSDNode
operator|:
name|public
name|SDNode
block|{
specifier|const
name|Value
operator|*
name|V
block|;
name|friend
name|class
name|SelectionDAG
block|;
comment|/// Create a SrcValue for a general value.
name|explicit
name|SrcValueSDNode
argument_list|(
specifier|const
name|Value
operator|*
name|v
argument_list|)
operator|:
name|SDNode
argument_list|(
name|ISD
operator|::
name|SRCVALUE
argument_list|,
name|DebugLoc
operator|::
name|getUnknownLoc
argument_list|()
argument_list|,
name|getSDVTList
argument_list|(
name|MVT
operator|::
name|Other
argument_list|)
argument_list|)
block|,
name|V
argument_list|(
argument|v
argument_list|)
block|{}
name|public
operator|:
comment|/// getValue - return the contained Value.
specifier|const
name|Value
operator|*
name|getValue
argument_list|()
specifier|const
block|{
return|return
name|V
return|;
block|}
specifier|static
name|bool
name|classof
argument_list|(
argument|const SrcValueSDNode *
argument_list|)
block|{
return|return
name|true
return|;
block|}
specifier|static
name|bool
name|classof
argument_list|(
argument|const SDNode *N
argument_list|)
block|{
return|return
name|N
operator|->
name|getOpcode
argument_list|()
operator|==
name|ISD
operator|::
name|SRCVALUE
return|;
block|}
expr|}
block|;
name|class
name|RegisterSDNode
operator|:
name|public
name|SDNode
block|{
name|unsigned
name|Reg
block|;
name|friend
name|class
name|SelectionDAG
block|;
name|RegisterSDNode
argument_list|(
argument|unsigned reg
argument_list|,
argument|EVT VT
argument_list|)
operator|:
name|SDNode
argument_list|(
name|ISD
operator|::
name|Register
argument_list|,
name|DebugLoc
operator|::
name|getUnknownLoc
argument_list|()
argument_list|,
name|getSDVTList
argument_list|(
name|VT
argument_list|)
argument_list|)
block|,
name|Reg
argument_list|(
argument|reg
argument_list|)
block|{   }
name|public
operator|:
name|unsigned
name|getReg
argument_list|()
specifier|const
block|{
return|return
name|Reg
return|;
block|}
specifier|static
name|bool
name|classof
argument_list|(
argument|const RegisterSDNode *
argument_list|)
block|{
return|return
name|true
return|;
block|}
specifier|static
name|bool
name|classof
argument_list|(
argument|const SDNode *N
argument_list|)
block|{
return|return
name|N
operator|->
name|getOpcode
argument_list|()
operator|==
name|ISD
operator|::
name|Register
return|;
block|}
expr|}
block|;
name|class
name|DbgStopPointSDNode
operator|:
name|public
name|SDNode
block|{
name|SDUse
name|Chain
block|;
name|unsigned
name|Line
block|;
name|unsigned
name|Column
block|;
name|MDNode
operator|*
name|CU
block|;
name|friend
name|class
name|SelectionDAG
block|;
name|DbgStopPointSDNode
argument_list|(
argument|SDValue ch
argument_list|,
argument|unsigned l
argument_list|,
argument|unsigned c
argument_list|,
argument|MDNode *cu
argument_list|)
operator|:
name|SDNode
argument_list|(
name|ISD
operator|::
name|DBG_STOPPOINT
argument_list|,
name|DebugLoc
operator|::
name|getUnknownLoc
argument_list|()
argument_list|,
name|getSDVTList
argument_list|(
name|MVT
operator|::
name|Other
argument_list|)
argument_list|)
block|,
name|Line
argument_list|(
name|l
argument_list|)
block|,
name|Column
argument_list|(
name|c
argument_list|)
block|,
name|CU
argument_list|(
argument|cu
argument_list|)
block|{
name|InitOperands
argument_list|(
operator|&
name|Chain
argument_list|,
name|ch
argument_list|)
block|;   }
name|public
operator|:
name|unsigned
name|getLine
argument_list|()
specifier|const
block|{
return|return
name|Line
return|;
block|}
name|unsigned
name|getColumn
argument_list|()
specifier|const
block|{
return|return
name|Column
return|;
block|}
name|MDNode
operator|*
name|getCompileUnit
argument_list|()
specifier|const
block|{
return|return
name|CU
return|;
block|}
specifier|static
name|bool
name|classof
argument_list|(
argument|const DbgStopPointSDNode *
argument_list|)
block|{
return|return
name|true
return|;
block|}
specifier|static
name|bool
name|classof
argument_list|(
argument|const SDNode *N
argument_list|)
block|{
return|return
name|N
operator|->
name|getOpcode
argument_list|()
operator|==
name|ISD
operator|::
name|DBG_STOPPOINT
return|;
block|}
expr|}
block|;
name|class
name|BlockAddressSDNode
operator|:
name|public
name|SDNode
block|{
name|BlockAddress
operator|*
name|BA
block|;
name|friend
name|class
name|SelectionDAG
block|;
name|BlockAddressSDNode
argument_list|(
argument|unsigned NodeTy
argument_list|,
argument|DebugLoc dl
argument_list|,
argument|EVT VT
argument_list|,
argument|BlockAddress *ba
argument_list|)
operator|:
name|SDNode
argument_list|(
name|NodeTy
argument_list|,
name|dl
argument_list|,
name|getSDVTList
argument_list|(
name|VT
argument_list|)
argument_list|)
block|,
name|BA
argument_list|(
argument|ba
argument_list|)
block|{   }
name|public
operator|:
name|BlockAddress
operator|*
name|getBlockAddress
argument_list|()
specifier|const
block|{
return|return
name|BA
return|;
block|}
specifier|static
name|bool
name|classof
argument_list|(
argument|const BlockAddressSDNode *
argument_list|)
block|{
return|return
name|true
return|;
block|}
specifier|static
name|bool
name|classof
argument_list|(
argument|const SDNode *N
argument_list|)
block|{
return|return
name|N
operator|->
name|getOpcode
argument_list|()
operator|==
name|ISD
operator|::
name|BlockAddress
operator|||
name|N
operator|->
name|getOpcode
argument_list|()
operator|==
name|ISD
operator|::
name|TargetBlockAddress
return|;
block|}
expr|}
block|;
name|class
name|LabelSDNode
operator|:
name|public
name|SDNode
block|{
name|SDUse
name|Chain
block|;
name|unsigned
name|LabelID
block|;
name|friend
name|class
name|SelectionDAG
block|;
name|LabelSDNode
argument_list|(
argument|unsigned NodeTy
argument_list|,
argument|DebugLoc dl
argument_list|,
argument|SDValue ch
argument_list|,
argument|unsigned id
argument_list|)
operator|:
name|SDNode
argument_list|(
name|NodeTy
argument_list|,
name|dl
argument_list|,
name|getSDVTList
argument_list|(
name|MVT
operator|::
name|Other
argument_list|)
argument_list|)
block|,
name|LabelID
argument_list|(
argument|id
argument_list|)
block|{
name|InitOperands
argument_list|(
operator|&
name|Chain
argument_list|,
name|ch
argument_list|)
block|;   }
name|public
operator|:
name|unsigned
name|getLabelID
argument_list|()
specifier|const
block|{
return|return
name|LabelID
return|;
block|}
specifier|static
name|bool
name|classof
argument_list|(
argument|const LabelSDNode *
argument_list|)
block|{
return|return
name|true
return|;
block|}
specifier|static
name|bool
name|classof
argument_list|(
argument|const SDNode *N
argument_list|)
block|{
return|return
name|N
operator|->
name|getOpcode
argument_list|()
operator|==
name|ISD
operator|::
name|DBG_LABEL
operator|||
name|N
operator|->
name|getOpcode
argument_list|()
operator|==
name|ISD
operator|::
name|EH_LABEL
return|;
block|}
expr|}
block|;
name|class
name|ExternalSymbolSDNode
operator|:
name|public
name|SDNode
block|{
specifier|const
name|char
operator|*
name|Symbol
block|;
name|unsigned
name|char
name|TargetFlags
block|;
name|friend
name|class
name|SelectionDAG
block|;
name|ExternalSymbolSDNode
argument_list|(
argument|bool isTarget
argument_list|,
argument|const char *Sym
argument_list|,
argument|unsigned char TF
argument_list|,
argument|EVT VT
argument_list|)
operator|:
name|SDNode
argument_list|(
name|isTarget
condition|?
name|ISD
operator|::
name|TargetExternalSymbol
else|:
name|ISD
operator|::
name|ExternalSymbol
argument_list|,
name|DebugLoc
operator|::
name|getUnknownLoc
argument_list|()
argument_list|,
name|getSDVTList
argument_list|(
name|VT
argument_list|)
argument_list|)
block|,
name|Symbol
argument_list|(
name|Sym
argument_list|)
block|,
name|TargetFlags
argument_list|(
argument|TF
argument_list|)
block|{   }
name|public
operator|:
specifier|const
name|char
operator|*
name|getSymbol
argument_list|()
specifier|const
block|{
return|return
name|Symbol
return|;
block|}
name|unsigned
name|char
name|getTargetFlags
argument_list|()
specifier|const
block|{
return|return
name|TargetFlags
return|;
block|}
specifier|static
name|bool
name|classof
argument_list|(
argument|const ExternalSymbolSDNode *
argument_list|)
block|{
return|return
name|true
return|;
block|}
specifier|static
name|bool
name|classof
argument_list|(
argument|const SDNode *N
argument_list|)
block|{
return|return
name|N
operator|->
name|getOpcode
argument_list|()
operator|==
name|ISD
operator|::
name|ExternalSymbol
operator|||
name|N
operator|->
name|getOpcode
argument_list|()
operator|==
name|ISD
operator|::
name|TargetExternalSymbol
return|;
block|}
expr|}
block|;
name|class
name|CondCodeSDNode
operator|:
name|public
name|SDNode
block|{
name|ISD
operator|::
name|CondCode
name|Condition
block|;
name|friend
name|class
name|SelectionDAG
block|;
name|explicit
name|CondCodeSDNode
argument_list|(
argument|ISD::CondCode Cond
argument_list|)
operator|:
name|SDNode
argument_list|(
name|ISD
operator|::
name|CONDCODE
argument_list|,
name|DebugLoc
operator|::
name|getUnknownLoc
argument_list|()
argument_list|,
name|getSDVTList
argument_list|(
name|MVT
operator|::
name|Other
argument_list|)
argument_list|)
block|,
name|Condition
argument_list|(
argument|Cond
argument_list|)
block|{   }
name|public
operator|:
name|ISD
operator|::
name|CondCode
name|get
argument_list|()
specifier|const
block|{
return|return
name|Condition
return|;
block|}
specifier|static
name|bool
name|classof
argument_list|(
argument|const CondCodeSDNode *
argument_list|)
block|{
return|return
name|true
return|;
block|}
specifier|static
name|bool
name|classof
argument_list|(
argument|const SDNode *N
argument_list|)
block|{
return|return
name|N
operator|->
name|getOpcode
argument_list|()
operator|==
name|ISD
operator|::
name|CONDCODE
return|;
block|}
expr|}
block|;
comment|/// CvtRndSatSDNode - NOTE: avoid using this node as this may disappear in the
comment|/// future and most targets don't support it.
name|class
name|CvtRndSatSDNode
operator|:
name|public
name|SDNode
block|{
name|ISD
operator|::
name|CvtCode
name|CvtCode
block|;
name|friend
name|class
name|SelectionDAG
block|;
name|explicit
name|CvtRndSatSDNode
argument_list|(
argument|EVT VT
argument_list|,
argument|DebugLoc dl
argument_list|,
argument|const SDValue *Ops
argument_list|,
argument|unsigned NumOps
argument_list|,
argument|ISD::CvtCode Code
argument_list|)
operator|:
name|SDNode
argument_list|(
name|ISD
operator|::
name|CONVERT_RNDSAT
argument_list|,
name|dl
argument_list|,
name|getSDVTList
argument_list|(
name|VT
argument_list|)
argument_list|,
name|Ops
argument_list|,
name|NumOps
argument_list|)
block|,
name|CvtCode
argument_list|(
argument|Code
argument_list|)
block|{
name|assert
argument_list|(
name|NumOps
operator|==
literal|5
operator|&&
literal|"wrong number of operations"
argument_list|)
block|;   }
name|public
operator|:
name|ISD
operator|::
name|CvtCode
name|getCvtCode
argument_list|()
specifier|const
block|{
return|return
name|CvtCode
return|;
block|}
specifier|static
name|bool
name|classof
argument_list|(
argument|const CvtRndSatSDNode *
argument_list|)
block|{
return|return
name|true
return|;
block|}
specifier|static
name|bool
name|classof
argument_list|(
argument|const SDNode *N
argument_list|)
block|{
return|return
name|N
operator|->
name|getOpcode
argument_list|()
operator|==
name|ISD
operator|::
name|CONVERT_RNDSAT
return|;
block|}
expr|}
block|;
name|namespace
name|ISD
block|{   struct
name|ArgFlagsTy
block|{
name|private
operator|:
specifier|static
specifier|const
name|uint64_t
name|NoFlagSet
operator|=
literal|0ULL
block|;
specifier|static
specifier|const
name|uint64_t
name|ZExt
operator|=
literal|1ULL
operator|<<
literal|0
block|;
comment|///< Zero extended
specifier|static
specifier|const
name|uint64_t
name|ZExtOffs
operator|=
literal|0
block|;
specifier|static
specifier|const
name|uint64_t
name|SExt
operator|=
literal|1ULL
operator|<<
literal|1
block|;
comment|///< Sign extended
specifier|static
specifier|const
name|uint64_t
name|SExtOffs
operator|=
literal|1
block|;
specifier|static
specifier|const
name|uint64_t
name|InReg
operator|=
literal|1ULL
operator|<<
literal|2
block|;
comment|///< Passed in register
specifier|static
specifier|const
name|uint64_t
name|InRegOffs
operator|=
literal|2
block|;
specifier|static
specifier|const
name|uint64_t
name|SRet
operator|=
literal|1ULL
operator|<<
literal|3
block|;
comment|///< Hidden struct-ret ptr
specifier|static
specifier|const
name|uint64_t
name|SRetOffs
operator|=
literal|3
block|;
specifier|static
specifier|const
name|uint64_t
name|ByVal
operator|=
literal|1ULL
operator|<<
literal|4
block|;
comment|///< Struct passed by value
specifier|static
specifier|const
name|uint64_t
name|ByValOffs
operator|=
literal|4
block|;
specifier|static
specifier|const
name|uint64_t
name|Nest
operator|=
literal|1ULL
operator|<<
literal|5
block|;
comment|///< Nested fn static chain
specifier|static
specifier|const
name|uint64_t
name|NestOffs
operator|=
literal|5
block|;
specifier|static
specifier|const
name|uint64_t
name|ByValAlign
operator|=
literal|0xFULL
operator|<<
literal|6
block|;
comment|//< Struct alignment
specifier|static
specifier|const
name|uint64_t
name|ByValAlignOffs
operator|=
literal|6
block|;
specifier|static
specifier|const
name|uint64_t
name|Split
operator|=
literal|1ULL
operator|<<
literal|10
block|;
specifier|static
specifier|const
name|uint64_t
name|SplitOffs
operator|=
literal|10
block|;
specifier|static
specifier|const
name|uint64_t
name|OrigAlign
operator|=
literal|0x1FULL
operator|<<
literal|27
block|;
specifier|static
specifier|const
name|uint64_t
name|OrigAlignOffs
operator|=
literal|27
block|;
specifier|static
specifier|const
name|uint64_t
name|ByValSize
operator|=
literal|0xffffffffULL
operator|<<
literal|32
block|;
comment|//< Struct size
specifier|static
specifier|const
name|uint64_t
name|ByValSizeOffs
operator|=
literal|32
block|;
specifier|static
specifier|const
name|uint64_t
name|One
operator|=
literal|1ULL
block|;
comment|//< 1 of this type, for shifts
name|uint64_t
name|Flags
block|;
name|public
operator|:
name|ArgFlagsTy
argument_list|()
operator|:
name|Flags
argument_list|(
literal|0
argument_list|)
block|{ }
name|bool
name|isZExt
argument_list|()
specifier|const
block|{
return|return
name|Flags
operator|&
name|ZExt
return|;
block|}
name|void
name|setZExt
argument_list|()
block|{
name|Flags
operator||=
name|One
operator|<<
name|ZExtOffs
block|; }
name|bool
name|isSExt
argument_list|()
specifier|const
block|{
return|return
name|Flags
operator|&
name|SExt
return|;
block|}
name|void
name|setSExt
argument_list|()
block|{
name|Flags
operator||=
name|One
operator|<<
name|SExtOffs
block|; }
name|bool
name|isInReg
argument_list|()
specifier|const
block|{
return|return
name|Flags
operator|&
name|InReg
return|;
block|}
name|void
name|setInReg
argument_list|()
block|{
name|Flags
operator||=
name|One
operator|<<
name|InRegOffs
block|; }
name|bool
name|isSRet
argument_list|()
specifier|const
block|{
return|return
name|Flags
operator|&
name|SRet
return|;
block|}
name|void
name|setSRet
argument_list|()
block|{
name|Flags
operator||=
name|One
operator|<<
name|SRetOffs
block|; }
name|bool
name|isByVal
argument_list|()
specifier|const
block|{
return|return
name|Flags
operator|&
name|ByVal
return|;
block|}
name|void
name|setByVal
argument_list|()
block|{
name|Flags
operator||=
name|One
operator|<<
name|ByValOffs
block|; }
name|bool
name|isNest
argument_list|()
specifier|const
block|{
return|return
name|Flags
operator|&
name|Nest
return|;
block|}
name|void
name|setNest
argument_list|()
block|{
name|Flags
operator||=
name|One
operator|<<
name|NestOffs
block|; }
name|unsigned
name|getByValAlign
argument_list|()
specifier|const
block|{
return|return
call|(
name|unsigned
call|)
argument_list|(
operator|(
name|One
operator|<<
operator|(
operator|(
name|Flags
operator|&
name|ByValAlign
operator|)
operator|>>
name|ByValAlignOffs
operator|)
operator|)
operator|/
literal|2
argument_list|)
return|;
block|}
name|void
name|setByValAlign
argument_list|(
argument|unsigned A
argument_list|)
block|{
name|Flags
operator|=
operator|(
name|Flags
operator|&
operator|~
name|ByValAlign
operator|)
operator||
operator|(
name|uint64_t
argument_list|(
name|Log2_32
argument_list|(
name|A
argument_list|)
operator|+
literal|1
argument_list|)
operator|<<
name|ByValAlignOffs
operator|)
block|;     }
name|bool
name|isSplit
argument_list|()
specifier|const
block|{
return|return
name|Flags
operator|&
name|Split
return|;
block|}
name|void
name|setSplit
argument_list|()
block|{
name|Flags
operator||=
name|One
operator|<<
name|SplitOffs
block|; }
name|unsigned
name|getOrigAlign
argument_list|()
specifier|const
block|{
return|return
call|(
name|unsigned
call|)
argument_list|(
operator|(
name|One
operator|<<
operator|(
operator|(
name|Flags
operator|&
name|OrigAlign
operator|)
operator|>>
name|OrigAlignOffs
operator|)
operator|)
operator|/
literal|2
argument_list|)
return|;
block|}
name|void
name|setOrigAlign
argument_list|(
argument|unsigned A
argument_list|)
block|{
name|Flags
operator|=
operator|(
name|Flags
operator|&
operator|~
name|OrigAlign
operator|)
operator||
operator|(
name|uint64_t
argument_list|(
name|Log2_32
argument_list|(
name|A
argument_list|)
operator|+
literal|1
argument_list|)
operator|<<
name|OrigAlignOffs
operator|)
block|;     }
name|unsigned
name|getByValSize
argument_list|()
specifier|const
block|{
return|return
call|(
name|unsigned
call|)
argument_list|(
operator|(
name|Flags
operator|&
name|ByValSize
operator|)
operator|>>
name|ByValSizeOffs
argument_list|)
return|;
block|}
name|void
name|setByValSize
argument_list|(
argument|unsigned S
argument_list|)
block|{
name|Flags
operator|=
operator|(
name|Flags
operator|&
operator|~
name|ByValSize
operator|)
operator||
operator|(
name|uint64_t
argument_list|(
name|S
argument_list|)
operator|<<
name|ByValSizeOffs
operator|)
block|;     }
comment|/// getArgFlagsString - Returns the flags as a string, eg: "zext align:4".
name|std
operator|::
name|string
name|getArgFlagsString
argument_list|()
block|;
comment|/// getRawBits - Represent the flags as a bunch of bits.
name|uint64_t
name|getRawBits
argument_list|()
specifier|const
block|{
return|return
name|Flags
return|;
block|}
expr|}
block|;
comment|/// InputArg - This struct carries flags and type information about a
comment|/// single incoming (formal) argument or incoming (from the perspective
comment|/// of the caller) return value virtual register.
comment|///
block|struct
name|InputArg
block|{
name|ArgFlagsTy
name|Flags
block|;
name|EVT
name|VT
block|;
name|bool
name|Used
block|;
name|InputArg
argument_list|()
operator|:
name|VT
argument_list|(
name|MVT
operator|::
name|Other
argument_list|)
block|,
name|Used
argument_list|(
argument|false
argument_list|)
block|{}
name|InputArg
argument_list|(
argument|ISD::ArgFlagsTy flags
argument_list|,
argument|EVT vt
argument_list|,
argument|bool used
argument_list|)
operator|:
name|Flags
argument_list|(
name|flags
argument_list|)
block|,
name|VT
argument_list|(
name|vt
argument_list|)
block|,
name|Used
argument_list|(
argument|used
argument_list|)
block|{
name|assert
argument_list|(
name|VT
operator|.
name|isSimple
argument_list|()
operator|&&
literal|"InputArg value type must be Simple!"
argument_list|)
block|;     }
block|}
block|;
comment|/// OutputArg - This struct carries flags and a value for a
comment|/// single outgoing (actual) argument or outgoing (from the perspective
comment|/// of the caller) return value virtual register.
comment|///
block|struct
name|OutputArg
block|{
name|ArgFlagsTy
name|Flags
block|;
name|SDValue
name|Val
block|;
name|bool
name|IsFixed
block|;
name|OutputArg
argument_list|()
operator|:
name|IsFixed
argument_list|(
argument|false
argument_list|)
block|{}
name|OutputArg
argument_list|(
argument|ISD::ArgFlagsTy flags
argument_list|,
argument|SDValue val
argument_list|,
argument|bool isfixed
argument_list|)
operator|:
name|Flags
argument_list|(
name|flags
argument_list|)
block|,
name|Val
argument_list|(
name|val
argument_list|)
block|,
name|IsFixed
argument_list|(
argument|isfixed
argument_list|)
block|{
name|assert
argument_list|(
name|Val
operator|.
name|getValueType
argument_list|()
operator|.
name|isSimple
argument_list|()
operator|&&
literal|"OutputArg value type must be Simple!"
argument_list|)
block|;     }
block|}
block|; }
comment|/// VTSDNode - This class is used to represent EVT's, which are used
comment|/// to parameterize some operations.
name|class
name|VTSDNode
operator|:
name|public
name|SDNode
block|{
name|EVT
name|ValueType
block|;
name|friend
name|class
name|SelectionDAG
block|;
name|explicit
name|VTSDNode
argument_list|(
argument|EVT VT
argument_list|)
operator|:
name|SDNode
argument_list|(
name|ISD
operator|::
name|VALUETYPE
argument_list|,
name|DebugLoc
operator|::
name|getUnknownLoc
argument_list|()
argument_list|,
name|getSDVTList
argument_list|(
name|MVT
operator|::
name|Other
argument_list|)
argument_list|)
block|,
name|ValueType
argument_list|(
argument|VT
argument_list|)
block|{   }
name|public
operator|:
name|EVT
name|getVT
argument_list|()
specifier|const
block|{
return|return
name|ValueType
return|;
block|}
specifier|static
name|bool
name|classof
argument_list|(
argument|const VTSDNode *
argument_list|)
block|{
return|return
name|true
return|;
block|}
specifier|static
name|bool
name|classof
argument_list|(
argument|const SDNode *N
argument_list|)
block|{
return|return
name|N
operator|->
name|getOpcode
argument_list|()
operator|==
name|ISD
operator|::
name|VALUETYPE
return|;
block|}
expr|}
block|;
comment|/// LSBaseSDNode - Base class for LoadSDNode and StoreSDNode
comment|///
name|class
name|LSBaseSDNode
operator|:
name|public
name|MemSDNode
block|{
comment|//! Operand array for load and store
comment|/*!     \note Moving this array to the base class captures more     common functionality shared between LoadSDNode and     StoreSDNode    */
name|SDUse
name|Ops
index|[
literal|4
index|]
block|;
name|public
operator|:
name|LSBaseSDNode
argument_list|(
argument|ISD::NodeType NodeTy
argument_list|,
argument|DebugLoc dl
argument_list|,
argument|SDValue *Operands
argument_list|,
argument|unsigned numOperands
argument_list|,
argument|SDVTList VTs
argument_list|,
argument|ISD::MemIndexedMode AM
argument_list|,
argument|EVT MemVT
argument_list|,
argument|MachineMemOperand *MMO
argument_list|)
operator|:
name|MemSDNode
argument_list|(
argument|NodeTy
argument_list|,
argument|dl
argument_list|,
argument|VTs
argument_list|,
argument|MemVT
argument_list|,
argument|MMO
argument_list|)
block|{
name|SubclassData
operator||=
name|AM
operator|<<
literal|2
block|;
name|assert
argument_list|(
name|getAddressingMode
argument_list|()
operator|==
name|AM
operator|&&
literal|"MemIndexedMode encoding error!"
argument_list|)
block|;
name|InitOperands
argument_list|(
name|Ops
argument_list|,
name|Operands
argument_list|,
name|numOperands
argument_list|)
block|;
name|assert
argument_list|(
operator|(
name|getOffset
argument_list|()
operator|.
name|getOpcode
argument_list|()
operator|==
name|ISD
operator|::
name|UNDEF
operator|||
name|isIndexed
argument_list|()
operator|)
operator|&&
literal|"Only indexed loads and stores have a non-undef offset operand"
argument_list|)
block|;   }
specifier|const
name|SDValue
operator|&
name|getOffset
argument_list|()
specifier|const
block|{
return|return
name|getOperand
argument_list|(
name|getOpcode
argument_list|()
operator|==
name|ISD
operator|::
name|LOAD
condition|?
literal|2
else|:
literal|3
argument_list|)
return|;
block|}
comment|/// getAddressingMode - Return the addressing mode for this load or store:
comment|/// unindexed, pre-inc, pre-dec, post-inc, or post-dec.
name|ISD
operator|::
name|MemIndexedMode
name|getAddressingMode
argument_list|()
specifier|const
block|{
return|return
name|ISD
operator|::
name|MemIndexedMode
argument_list|(
operator|(
name|SubclassData
operator|>>
literal|2
operator|)
operator|&
literal|7
argument_list|)
return|;
block|}
comment|/// isIndexed - Return true if this is a pre/post inc/dec load/store.
name|bool
name|isIndexed
argument_list|()
specifier|const
block|{
return|return
name|getAddressingMode
argument_list|()
operator|!=
name|ISD
operator|::
name|UNINDEXED
return|;
block|}
comment|/// isUnindexed - Return true if this is NOT a pre/post inc/dec load/store.
name|bool
name|isUnindexed
argument_list|()
specifier|const
block|{
return|return
name|getAddressingMode
argument_list|()
operator|==
name|ISD
operator|::
name|UNINDEXED
return|;
block|}
specifier|static
name|bool
name|classof
argument_list|(
argument|const LSBaseSDNode *
argument_list|)
block|{
return|return
name|true
return|;
block|}
specifier|static
name|bool
name|classof
argument_list|(
argument|const SDNode *N
argument_list|)
block|{
return|return
name|N
operator|->
name|getOpcode
argument_list|()
operator|==
name|ISD
operator|::
name|LOAD
operator|||
name|N
operator|->
name|getOpcode
argument_list|()
operator|==
name|ISD
operator|::
name|STORE
return|;
block|}
expr|}
block|;
comment|/// LoadSDNode - This class is used to represent ISD::LOAD nodes.
comment|///
name|class
name|LoadSDNode
operator|:
name|public
name|LSBaseSDNode
block|{
name|friend
name|class
name|SelectionDAG
block|;
name|LoadSDNode
argument_list|(
argument|SDValue *ChainPtrOff
argument_list|,
argument|DebugLoc dl
argument_list|,
argument|SDVTList VTs
argument_list|,
argument|ISD::MemIndexedMode AM
argument_list|,
argument|ISD::LoadExtType ETy
argument_list|,
argument|EVT MemVT
argument_list|,
argument|MachineMemOperand *MMO
argument_list|)
operator|:
name|LSBaseSDNode
argument_list|(
argument|ISD::LOAD
argument_list|,
argument|dl
argument_list|,
argument|ChainPtrOff
argument_list|,
literal|3
argument_list|,
argument|VTs
argument_list|,
argument|AM
argument_list|,
argument|MemVT
argument_list|,
argument|MMO
argument_list|)
block|{
name|SubclassData
operator||=
operator|(
name|unsigned
name|short
operator|)
name|ETy
block|;
name|assert
argument_list|(
name|getExtensionType
argument_list|()
operator|==
name|ETy
operator|&&
literal|"LoadExtType encoding error!"
argument_list|)
block|;
name|assert
argument_list|(
name|readMem
argument_list|()
operator|&&
literal|"Load MachineMemOperand is not a load!"
argument_list|)
block|;
name|assert
argument_list|(
operator|!
name|writeMem
argument_list|()
operator|&&
literal|"Load MachineMemOperand is a store!"
argument_list|)
block|;   }
name|public
operator|:
comment|/// getExtensionType - Return whether this is a plain node,
comment|/// or one of the varieties of value-extending loads.
name|ISD
operator|::
name|LoadExtType
name|getExtensionType
argument_list|()
specifier|const
block|{
return|return
name|ISD
operator|::
name|LoadExtType
argument_list|(
name|SubclassData
operator|&
literal|3
argument_list|)
return|;
block|}
specifier|const
name|SDValue
operator|&
name|getBasePtr
argument_list|()
specifier|const
block|{
return|return
name|getOperand
argument_list|(
literal|1
argument_list|)
return|;
block|}
specifier|const
name|SDValue
operator|&
name|getOffset
argument_list|()
specifier|const
block|{
return|return
name|getOperand
argument_list|(
literal|2
argument_list|)
return|;
block|}
specifier|static
name|bool
name|classof
argument_list|(
argument|const LoadSDNode *
argument_list|)
block|{
return|return
name|true
return|;
block|}
specifier|static
name|bool
name|classof
argument_list|(
argument|const SDNode *N
argument_list|)
block|{
return|return
name|N
operator|->
name|getOpcode
argument_list|()
operator|==
name|ISD
operator|::
name|LOAD
return|;
block|}
expr|}
block|;
comment|/// StoreSDNode - This class is used to represent ISD::STORE nodes.
comment|///
name|class
name|StoreSDNode
operator|:
name|public
name|LSBaseSDNode
block|{
name|friend
name|class
name|SelectionDAG
block|;
name|StoreSDNode
argument_list|(
argument|SDValue *ChainValuePtrOff
argument_list|,
argument|DebugLoc dl
argument_list|,
argument|SDVTList VTs
argument_list|,
argument|ISD::MemIndexedMode AM
argument_list|,
argument|bool isTrunc
argument_list|,
argument|EVT MemVT
argument_list|,
argument|MachineMemOperand *MMO
argument_list|)
operator|:
name|LSBaseSDNode
argument_list|(
argument|ISD::STORE
argument_list|,
argument|dl
argument_list|,
argument|ChainValuePtrOff
argument_list|,
literal|4
argument_list|,
argument|VTs
argument_list|,
argument|AM
argument_list|,
argument|MemVT
argument_list|,
argument|MMO
argument_list|)
block|{
name|SubclassData
operator||=
operator|(
name|unsigned
name|short
operator|)
name|isTrunc
block|;
name|assert
argument_list|(
name|isTruncatingStore
argument_list|()
operator|==
name|isTrunc
operator|&&
literal|"isTrunc encoding error!"
argument_list|)
block|;
name|assert
argument_list|(
operator|!
name|readMem
argument_list|()
operator|&&
literal|"Store MachineMemOperand is a load!"
argument_list|)
block|;
name|assert
argument_list|(
name|writeMem
argument_list|()
operator|&&
literal|"Store MachineMemOperand is not a store!"
argument_list|)
block|;   }
name|public
operator|:
comment|/// isTruncatingStore - Return true if the op does a truncation before store.
comment|/// For integers this is the same as doing a TRUNCATE and storing the result.
comment|/// For floats, it is the same as doing an FP_ROUND and storing the result.
name|bool
name|isTruncatingStore
argument_list|()
specifier|const
block|{
return|return
name|SubclassData
operator|&
literal|1
return|;
block|}
specifier|const
name|SDValue
operator|&
name|getValue
argument_list|()
specifier|const
block|{
return|return
name|getOperand
argument_list|(
literal|1
argument_list|)
return|;
block|}
specifier|const
name|SDValue
operator|&
name|getBasePtr
argument_list|()
specifier|const
block|{
return|return
name|getOperand
argument_list|(
literal|2
argument_list|)
return|;
block|}
specifier|const
name|SDValue
operator|&
name|getOffset
argument_list|()
specifier|const
block|{
return|return
name|getOperand
argument_list|(
literal|3
argument_list|)
return|;
block|}
specifier|static
name|bool
name|classof
argument_list|(
argument|const StoreSDNode *
argument_list|)
block|{
return|return
name|true
return|;
block|}
specifier|static
name|bool
name|classof
argument_list|(
argument|const SDNode *N
argument_list|)
block|{
return|return
name|N
operator|->
name|getOpcode
argument_list|()
operator|==
name|ISD
operator|::
name|STORE
return|;
block|}
expr|}
block|;
comment|/// MachineSDNode - An SDNode that represents everything that will be needed
comment|/// to construct a MachineInstr. These nodes are created during the
comment|/// instruction selection proper phase.
comment|///
name|class
name|MachineSDNode
operator|:
name|public
name|SDNode
block|{
name|public
operator|:
typedef|typedef
name|MachineMemOperand
modifier|*
modifier|*
name|mmo_iterator
typedef|;
name|private
operator|:
name|friend
name|class
name|SelectionDAG
block|;
name|MachineSDNode
argument_list|(
argument|unsigned Opc
argument_list|,
argument|const DebugLoc DL
argument_list|,
argument|SDVTList VTs
argument_list|)
operator|:
name|SDNode
argument_list|(
name|Opc
argument_list|,
name|DL
argument_list|,
name|VTs
argument_list|)
block|,
name|MemRefs
argument_list|(
literal|0
argument_list|)
block|,
name|MemRefsEnd
argument_list|(
literal|0
argument_list|)
block|{}
comment|/// LocalOperands - Operands for this instruction, if they fit here. If
comment|/// they don't, this field is unused.
name|SDUse
name|LocalOperands
index|[
literal|4
index|]
block|;
comment|/// MemRefs - Memory reference descriptions for this instruction.
name|mmo_iterator
name|MemRefs
block|;
name|mmo_iterator
name|MemRefsEnd
block|;
name|public
operator|:
name|mmo_iterator
name|memoperands_begin
argument_list|()
specifier|const
block|{
return|return
name|MemRefs
return|;
block|}
name|mmo_iterator
name|memoperands_end
argument_list|()
specifier|const
block|{
return|return
name|MemRefsEnd
return|;
block|}
name|bool
name|memoperands_empty
argument_list|()
specifier|const
block|{
return|return
name|MemRefsEnd
operator|==
name|MemRefs
return|;
block|}
comment|/// setMemRefs - Assign this MachineSDNodes's memory reference descriptor
comment|/// list. This does not transfer ownership.
name|void
name|setMemRefs
argument_list|(
argument|mmo_iterator NewMemRefs
argument_list|,
argument|mmo_iterator NewMemRefsEnd
argument_list|)
block|{
name|MemRefs
operator|=
name|NewMemRefs
block|;
name|MemRefsEnd
operator|=
name|NewMemRefsEnd
block|;   }
specifier|static
name|bool
name|classof
argument_list|(
argument|const MachineSDNode *
argument_list|)
block|{
return|return
name|true
return|;
block|}
specifier|static
name|bool
name|classof
argument_list|(
argument|const SDNode *N
argument_list|)
block|{
return|return
name|N
operator|->
name|isMachineOpcode
argument_list|()
return|;
block|}
expr|}
block|;
name|class
name|SDNodeIterator
operator|:
name|public
name|std
operator|::
name|iterator
operator|<
name|std
operator|::
name|forward_iterator_tag
block|,
name|SDNode
block|,
name|ptrdiff_t
operator|>
block|{
name|SDNode
operator|*
name|Node
block|;
name|unsigned
name|Operand
block|;
name|SDNodeIterator
argument_list|(
argument|SDNode *N
argument_list|,
argument|unsigned Op
argument_list|)
operator|:
name|Node
argument_list|(
name|N
argument_list|)
block|,
name|Operand
argument_list|(
argument|Op
argument_list|)
block|{}
name|public
operator|:
name|bool
name|operator
operator|==
operator|(
specifier|const
name|SDNodeIterator
operator|&
name|x
operator|)
specifier|const
block|{
return|return
name|Operand
operator|==
name|x
operator|.
name|Operand
return|;
block|}
name|bool
name|operator
operator|!=
operator|(
specifier|const
name|SDNodeIterator
operator|&
name|x
operator|)
specifier|const
block|{
return|return
operator|!
name|operator
operator|==
operator|(
name|x
operator|)
return|;
block|}
specifier|const
name|SDNodeIterator
operator|&
name|operator
operator|=
operator|(
specifier|const
name|SDNodeIterator
operator|&
name|I
operator|)
block|{
name|assert
argument_list|(
name|I
operator|.
name|Node
operator|==
name|Node
operator|&&
literal|"Cannot assign iterators to two different nodes!"
argument_list|)
block|;
name|Operand
operator|=
name|I
operator|.
name|Operand
block|;
return|return
operator|*
name|this
return|;
block|}
name|pointer
name|operator
operator|*
operator|(
operator|)
specifier|const
block|{
return|return
name|Node
operator|->
name|getOperand
argument_list|(
name|Operand
argument_list|)
operator|.
name|getNode
argument_list|()
return|;
block|}
name|pointer
name|operator
operator|->
expr|(
block|)
specifier|const
block|{
return|return
name|operator
operator|*
operator|(
operator|)
return|;
block|}
name|SDNodeIterator
operator|&
name|operator
operator|++
operator|(
operator|)
block|{
comment|// Preincrement
operator|++
name|Operand
block|;
return|return
operator|*
name|this
return|;
block|}
name|SDNodeIterator
name|operator
operator|++
operator|(
name|int
operator|)
block|{
comment|// Postincrement
name|SDNodeIterator
name|tmp
operator|=
operator|*
name|this
block|;
operator|++
operator|*
name|this
block|;
return|return
name|tmp
return|;
block|}
specifier|static
name|SDNodeIterator
name|begin
argument_list|(
argument|SDNode *N
argument_list|)
block|{
return|return
name|SDNodeIterator
argument_list|(
name|N
argument_list|,
literal|0
argument_list|)
return|;
block|}
specifier|static
name|SDNodeIterator
name|end
argument_list|(
argument|SDNode *N
argument_list|)
block|{
return|return
name|SDNodeIterator
argument_list|(
name|N
argument_list|,
name|N
operator|->
name|getNumOperands
argument_list|()
argument_list|)
return|;
block|}
name|unsigned
name|getOperand
argument_list|()
specifier|const
block|{
return|return
name|Operand
return|;
block|}
specifier|const
name|SDNode
operator|*
name|getNode
argument_list|()
specifier|const
block|{
return|return
name|Node
return|;
block|}
expr|}
block|;
name|template
operator|<
operator|>
expr|struct
name|GraphTraits
operator|<
name|SDNode
operator|*
operator|>
block|{
typedef|typedef
name|SDNode
name|NodeType
typedef|;
typedef|typedef
name|SDNodeIterator
name|ChildIteratorType
typedef|;
specifier|static
specifier|inline
name|NodeType
operator|*
name|getEntryNode
argument_list|(
argument|SDNode *N
argument_list|)
block|{
return|return
name|N
return|;
block|}
specifier|static
specifier|inline
name|ChildIteratorType
name|child_begin
argument_list|(
argument|NodeType *N
argument_list|)
block|{
return|return
name|SDNodeIterator
operator|::
name|begin
argument_list|(
name|N
argument_list|)
return|;
block|}
specifier|static
specifier|inline
name|ChildIteratorType
name|child_end
argument_list|(
argument|NodeType *N
argument_list|)
block|{
return|return
name|SDNodeIterator
operator|::
name|end
argument_list|(
name|N
argument_list|)
return|;
block|}
expr|}
block|;
comment|/// LargestSDNode - The largest SDNode class.
comment|///
typedef|typedef
name|LoadSDNode
name|LargestSDNode
typedef|;
comment|/// MostAlignedSDNode - The SDNode class with the greatest alignment
comment|/// requirement.
comment|///
typedef|typedef
name|GlobalAddressSDNode
name|MostAlignedSDNode
typedef|;
name|namespace
name|ISD
block|{
comment|/// isNormalLoad - Returns true if the specified node is a non-extending
comment|/// and unindexed load.
specifier|inline
name|bool
name|isNormalLoad
argument_list|(
argument|const SDNode *N
argument_list|)
block|{
specifier|const
name|LoadSDNode
operator|*
name|Ld
operator|=
name|dyn_cast
operator|<
name|LoadSDNode
operator|>
operator|(
name|N
operator|)
block|;
return|return
name|Ld
operator|&&
name|Ld
operator|->
name|getExtensionType
argument_list|()
operator|==
name|ISD
operator|::
name|NON_EXTLOAD
operator|&&
name|Ld
operator|->
name|getAddressingMode
argument_list|()
operator|==
name|ISD
operator|::
name|UNINDEXED
return|;
block|}
comment|/// isNON_EXTLoad - Returns true if the specified node is a non-extending
comment|/// load.
specifier|inline
name|bool
name|isNON_EXTLoad
argument_list|(
argument|const SDNode *N
argument_list|)
block|{
return|return
name|isa
operator|<
name|LoadSDNode
operator|>
operator|(
name|N
operator|)
operator|&&
name|cast
operator|<
name|LoadSDNode
operator|>
operator|(
name|N
operator|)
operator|->
name|getExtensionType
argument_list|()
operator|==
name|ISD
operator|::
name|NON_EXTLOAD
return|;
block|}
comment|/// isEXTLoad - Returns true if the specified node is a EXTLOAD.
comment|///
specifier|inline
name|bool
name|isEXTLoad
argument_list|(
argument|const SDNode *N
argument_list|)
block|{
return|return
name|isa
operator|<
name|LoadSDNode
operator|>
operator|(
name|N
operator|)
operator|&&
name|cast
operator|<
name|LoadSDNode
operator|>
operator|(
name|N
operator|)
operator|->
name|getExtensionType
argument_list|()
operator|==
name|ISD
operator|::
name|EXTLOAD
return|;
block|}
comment|/// isSEXTLoad - Returns true if the specified node is a SEXTLOAD.
comment|///
specifier|inline
name|bool
name|isSEXTLoad
argument_list|(
argument|const SDNode *N
argument_list|)
block|{
return|return
name|isa
operator|<
name|LoadSDNode
operator|>
operator|(
name|N
operator|)
operator|&&
name|cast
operator|<
name|LoadSDNode
operator|>
operator|(
name|N
operator|)
operator|->
name|getExtensionType
argument_list|()
operator|==
name|ISD
operator|::
name|SEXTLOAD
return|;
block|}
comment|/// isZEXTLoad - Returns true if the specified node is a ZEXTLOAD.
comment|///
specifier|inline
name|bool
name|isZEXTLoad
argument_list|(
argument|const SDNode *N
argument_list|)
block|{
return|return
name|isa
operator|<
name|LoadSDNode
operator|>
operator|(
name|N
operator|)
operator|&&
name|cast
operator|<
name|LoadSDNode
operator|>
operator|(
name|N
operator|)
operator|->
name|getExtensionType
argument_list|()
operator|==
name|ISD
operator|::
name|ZEXTLOAD
return|;
block|}
comment|/// isUNINDEXEDLoad - Returns true if the specified node is an unindexed load.
comment|///
specifier|inline
name|bool
name|isUNINDEXEDLoad
argument_list|(
argument|const SDNode *N
argument_list|)
block|{
return|return
name|isa
operator|<
name|LoadSDNode
operator|>
operator|(
name|N
operator|)
operator|&&
name|cast
operator|<
name|LoadSDNode
operator|>
operator|(
name|N
operator|)
operator|->
name|getAddressingMode
argument_list|()
operator|==
name|ISD
operator|::
name|UNINDEXED
return|;
block|}
comment|/// isNormalStore - Returns true if the specified node is a non-truncating
comment|/// and unindexed store.
specifier|inline
name|bool
name|isNormalStore
argument_list|(
argument|const SDNode *N
argument_list|)
block|{
specifier|const
name|StoreSDNode
operator|*
name|St
operator|=
name|dyn_cast
operator|<
name|StoreSDNode
operator|>
operator|(
name|N
operator|)
block|;
return|return
name|St
operator|&&
operator|!
name|St
operator|->
name|isTruncatingStore
argument_list|()
operator|&&
name|St
operator|->
name|getAddressingMode
argument_list|()
operator|==
name|ISD
operator|::
name|UNINDEXED
return|;
block|}
comment|/// isNON_TRUNCStore - Returns true if the specified node is a non-truncating
comment|/// store.
specifier|inline
name|bool
name|isNON_TRUNCStore
argument_list|(
argument|const SDNode *N
argument_list|)
block|{
return|return
name|isa
operator|<
name|StoreSDNode
operator|>
operator|(
name|N
operator|)
operator|&&
operator|!
name|cast
operator|<
name|StoreSDNode
operator|>
operator|(
name|N
operator|)
operator|->
name|isTruncatingStore
argument_list|()
return|;
block|}
comment|/// isTRUNCStore - Returns true if the specified node is a truncating
comment|/// store.
specifier|inline
name|bool
name|isTRUNCStore
argument_list|(
argument|const SDNode *N
argument_list|)
block|{
return|return
name|isa
operator|<
name|StoreSDNode
operator|>
operator|(
name|N
operator|)
operator|&&
name|cast
operator|<
name|StoreSDNode
operator|>
operator|(
name|N
operator|)
operator|->
name|isTruncatingStore
argument_list|()
return|;
block|}
comment|/// isUNINDEXEDStore - Returns true if the specified node is an
comment|/// unindexed store.
specifier|inline
name|bool
name|isUNINDEXEDStore
argument_list|(
argument|const SDNode *N
argument_list|)
block|{
return|return
name|isa
operator|<
name|StoreSDNode
operator|>
operator|(
name|N
operator|)
operator|&&
name|cast
operator|<
name|StoreSDNode
operator|>
operator|(
name|N
operator|)
operator|->
name|getAddressingMode
argument_list|()
operator|==
name|ISD
operator|::
name|UNINDEXED
return|;
block|}
expr|}   }
end_decl_stmt

begin_comment
comment|// end llvm namespace
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

