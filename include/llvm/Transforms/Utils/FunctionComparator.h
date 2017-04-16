begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- FunctionComparator.h - Function Comparator ---------------*- C++ -*-===//
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
comment|// This file defines the FunctionComparator and GlobalNumberState classes which
end_comment

begin_comment
comment|// are used by the MergeFunctions pass for comparing functions.
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
name|LLVM_TRANSFORMS_UTILS_FUNCTIONCOMPARATOR_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_TRANSFORMS_UTILS_FUNCTIONCOMPARATOR_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/APFloat.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/DenseMap.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/StringRef.h"
end_include

begin_include
include|#
directive|include
file|"llvm/IR/Function.h"
end_include

begin_include
include|#
directive|include
file|"llvm/IR/ValueMap.h"
end_include

begin_include
include|#
directive|include
file|"llvm/IR/Operator.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/AtomicOrdering.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/Casting.h"
end_include

begin_include
include|#
directive|include
file|<cstdint>
end_include

begin_include
include|#
directive|include
file|<tuple>
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|GetElementPtrInst
decl_stmt|;
comment|/// GlobalNumberState assigns an integer to each global value in the program,
comment|/// which is used by the comparison routine to order references to globals. This
comment|/// state must be preserved throughout the pass, because Functions and other
comment|/// globals need to maintain their relative order. Globals are assigned a number
comment|/// when they are first visited. This order is deterministic, and so the
comment|/// assigned numbers are as well. When two functions are merged, neither number
comment|/// is updated. If the symbols are weak, this would be incorrect. If they are
comment|/// strong, then one will be replaced at all references to the other, and so
comment|/// direct callsites will now see one or the other symbol, and no update is
comment|/// necessary. Note that if we were guaranteed unique names, we could just
comment|/// compare those, but this would not work for stripped bitcodes or for those
comment|/// few symbols without a name.
name|class
name|GlobalNumberState
block|{
name|struct
name|Config
range|:
name|ValueMapConfig
operator|<
name|GlobalValue
operator|*
operator|>
block|{     enum
block|{
name|FollowRAUW
operator|=
name|false
block|}
block|;   }
decl_stmt|;
comment|// Each GlobalValue is mapped to an identifier. The Config ensures when RAUW
comment|// occurs, the mapping does not change. Tracking changes is unnecessary, and
comment|// also problematic for weak symbols (which may be overwritten).
typedef|typedef
name|ValueMap
operator|<
name|GlobalValue
operator|*
operator|,
name|uint64_t
operator|,
name|Config
operator|>
name|ValueNumberMap
expr_stmt|;
name|ValueNumberMap
name|GlobalNumbers
decl_stmt|;
comment|// The next unused serial number to assign to a global.
name|uint64_t
name|NextNumber
init|=
literal|0
decl_stmt|;
name|public
label|:
name|GlobalNumberState
argument_list|()
operator|=
expr|default
expr_stmt|;
name|uint64_t
name|getNumber
parameter_list|(
name|GlobalValue
modifier|*
name|Global
parameter_list|)
block|{
name|ValueNumberMap
operator|::
name|iterator
name|MapIter
expr_stmt|;
name|bool
name|Inserted
decl_stmt|;
name|std
operator|::
name|tie
argument_list|(
name|MapIter
argument_list|,
name|Inserted
argument_list|)
operator|=
name|GlobalNumbers
operator|.
name|insert
argument_list|(
block|{
name|Global
block|,
name|NextNumber
block|}
argument_list|)
expr_stmt|;
if|if
condition|(
name|Inserted
condition|)
name|NextNumber
operator|++
expr_stmt|;
return|return
name|MapIter
operator|->
name|second
return|;
block|}
name|void
name|clear
parameter_list|()
block|{
name|GlobalNumbers
operator|.
name|clear
argument_list|()
expr_stmt|;
block|}
block|}
empty_stmt|;
comment|/// FunctionComparator - Compares two functions to determine whether or not
comment|/// they will generate machine code with the same behaviour. DataLayout is
comment|/// used if available. The comparator always fails conservatively (erring on the
comment|/// side of claiming that two functions are different).
name|class
name|FunctionComparator
block|{
name|public
label|:
name|FunctionComparator
argument_list|(
specifier|const
name|Function
operator|*
name|F1
argument_list|,
specifier|const
name|Function
operator|*
name|F2
argument_list|,
name|GlobalNumberState
operator|*
name|GN
argument_list|)
operator|:
name|FnL
argument_list|(
name|F1
argument_list|)
operator|,
name|FnR
argument_list|(
name|F2
argument_list|)
operator|,
name|GlobalNumbers
argument_list|(
argument|GN
argument_list|)
block|{}
comment|/// Test whether the two functions have equivalent behaviour.
name|int
name|compare
argument_list|()
expr_stmt|;
comment|/// Hash a function. Equivalent functions will have the same hash, and unequal
comment|/// functions will have different hashes with high probability.
typedef|typedef
name|uint64_t
name|FunctionHash
typedef|;
specifier|static
name|FunctionHash
name|functionHash
parameter_list|(
name|Function
modifier|&
parameter_list|)
function_decl|;
name|protected
label|:
comment|/// Start the comparison.
name|void
name|beginCompare
parameter_list|()
block|{
name|sn_mapL
operator|.
name|clear
argument_list|()
expr_stmt|;
name|sn_mapR
operator|.
name|clear
argument_list|()
expr_stmt|;
block|}
comment|/// Compares the signature and other general attributes of the two functions.
name|int
name|compareSignature
argument_list|()
specifier|const
expr_stmt|;
comment|/// Test whether two basic blocks have equivalent behaviour.
name|int
name|cmpBasicBlocks
argument_list|(
specifier|const
name|BasicBlock
operator|*
name|BBL
argument_list|,
specifier|const
name|BasicBlock
operator|*
name|BBR
argument_list|)
decl|const
decl_stmt|;
comment|/// Constants comparison.
comment|/// Its analog to lexicographical comparison between hypothetical numbers
comment|/// of next format:
comment|///<bitcastability-trait><raw-bit-contents>
comment|///
comment|/// 1. Bitcastability.
comment|/// Check whether L's type could be losslessly bitcasted to R's type.
comment|/// On this stage method, in case when lossless bitcast is not possible
comment|/// method returns -1 or 1, thus also defining which type is greater in
comment|/// context of bitcastability.
comment|/// Stage 0: If types are equal in terms of cmpTypes, then we can go straight
comment|///          to the contents comparison.
comment|///          If types differ, remember types comparison result and check
comment|///          whether we still can bitcast types.
comment|/// Stage 1: Types that satisfies isFirstClassType conditions are always
comment|///          greater then others.
comment|/// Stage 2: Vector is greater then non-vector.
comment|///          If both types are vectors, then vector with greater bitwidth is
comment|///          greater.
comment|///          If both types are vectors with the same bitwidth, then types
comment|///          are bitcastable, and we can skip other stages, and go to contents
comment|///          comparison.
comment|/// Stage 3: Pointer types are greater than non-pointers. If both types are
comment|///          pointers of the same address space - go to contents comparison.
comment|///          Different address spaces: pointer with greater address space is
comment|///          greater.
comment|/// Stage 4: Types are neither vectors, nor pointers. And they differ.
comment|///          We don't know how to bitcast them. So, we better don't do it,
comment|///          and return types comparison result (so it determines the
comment|///          relationship among constants we don't know how to bitcast).
comment|///
comment|/// Just for clearance, let's see how the set of constants could look
comment|/// on single dimension axis:
comment|///
comment|/// [NFCT], [FCT, "others"], [FCT, pointers], [FCT, vectors]
comment|/// Where: NFCT - Not a FirstClassType
comment|///        FCT - FirstClassTyp:
comment|///
comment|/// 2. Compare raw contents.
comment|/// It ignores types on this stage and only compares bits from L and R.
comment|/// Returns 0, if L and R has equivalent contents.
comment|/// -1 or 1 if values are different.
comment|/// Pretty trivial:
comment|/// 2.1. If contents are numbers, compare numbers.
comment|///    Ints with greater bitwidth are greater. Ints with same bitwidths
comment|///    compared by their contents.
comment|/// 2.2. "And so on". Just to avoid discrepancies with comments
comment|/// perhaps it would be better to read the implementation itself.
comment|/// 3. And again about overall picture. Let's look back at how the ordered set
comment|/// of constants will look like:
comment|/// [NFCT], [FCT, "others"], [FCT, pointers], [FCT, vectors]
comment|///
comment|/// Now look, what could be inside [FCT, "others"], for example:
comment|/// [FCT, "others"] =
comment|/// [
comment|///   [double 0.1], [double 1.23],
comment|///   [i32 1], [i32 2],
comment|///   { double 1.0 },       ; StructTyID, NumElements = 1
comment|///   { i32 1 },            ; StructTyID, NumElements = 1
comment|///   { double 1, i32 1 },  ; StructTyID, NumElements = 2
comment|///   { i32 1, double 1 }   ; StructTyID, NumElements = 2
comment|/// ]
comment|///
comment|/// Let's explain the order. Float numbers will be less than integers, just
comment|/// because of cmpType terms: FloatTyID< IntegerTyID.
comment|/// Floats (with same fltSemantics) are sorted according to their value.
comment|/// Then you can see integers, and they are, like a floats,
comment|/// could be easy sorted among each others.
comment|/// The structures. Structures are grouped at the tail, again because of their
comment|/// TypeID: StructTyID> IntegerTyID> FloatTyID.
comment|/// Structures with greater number of elements are greater. Structures with
comment|/// greater elements going first are greater.
comment|/// The same logic with vectors, arrays and other possible complex types.
comment|///
comment|/// Bitcastable constants.
comment|/// Let's assume, that some constant, belongs to some group of
comment|/// "so-called-equal" values with different types, and at the same time
comment|/// belongs to another group of constants with equal types
comment|/// and "really" equal values.
comment|///
comment|/// Now, prove that this is impossible:
comment|///
comment|/// If constant A with type TyA is bitcastable to B with type TyB, then:
comment|/// 1. All constants with equal types to TyA, are bitcastable to B. Since
comment|///    those should be vectors (if TyA is vector), pointers
comment|///    (if TyA is pointer), or else (if TyA equal to TyB), those types should
comment|///    be equal to TyB.
comment|/// 2. All constants with non-equal, but bitcastable types to TyA, are
comment|///    bitcastable to B.
comment|///    Once again, just because we allow it to vectors and pointers only.
comment|///    This statement could be expanded as below:
comment|/// 2.1. All vectors with equal bitwidth to vector A, has equal bitwidth to
comment|///      vector B, and thus bitcastable to B as well.
comment|/// 2.2. All pointers of the same address space, no matter what they point to,
comment|///      bitcastable. So if C is pointer, it could be bitcasted to A and to B.
comment|/// So any constant equal or bitcastable to A is equal or bitcastable to B.
comment|/// QED.
comment|///
comment|/// In another words, for pointers and vectors, we ignore top-level type and
comment|/// look at their particular properties (bit-width for vectors, and
comment|/// address space for pointers).
comment|/// If these properties are equal - compare their contents.
name|int
name|cmpConstants
argument_list|(
specifier|const
name|Constant
operator|*
name|L
argument_list|,
specifier|const
name|Constant
operator|*
name|R
argument_list|)
decl|const
decl_stmt|;
comment|/// Compares two global values by number. Uses the GlobalNumbersState to
comment|/// identify the same gobals across function calls.
name|int
name|cmpGlobalValues
argument_list|(
name|GlobalValue
operator|*
name|L
argument_list|,
name|GlobalValue
operator|*
name|R
argument_list|)
decl|const
decl_stmt|;
comment|/// Assign or look up previously assigned numbers for the two values, and
comment|/// return whether the numbers are equal. Numbers are assigned in the order
comment|/// visited.
comment|/// Comparison order:
comment|/// Stage 0: Value that is function itself is always greater then others.
comment|///          If left and right values are references to their functions, then
comment|///          they are equal.
comment|/// Stage 1: Constants are greater than non-constants.
comment|///          If both left and right are constants, then the result of
comment|///          cmpConstants is used as cmpValues result.
comment|/// Stage 2: InlineAsm instances are greater than others. If both left and
comment|///          right are InlineAsm instances, InlineAsm* pointers casted to
comment|///          integers and compared as numbers.
comment|/// Stage 3: For all other cases we compare order we meet these values in
comment|///          their functions. If right value was met first during scanning,
comment|///          then left value is greater.
comment|///          In another words, we compare serial numbers, for more details
comment|///          see comments for sn_mapL and sn_mapR.
name|int
name|cmpValues
argument_list|(
specifier|const
name|Value
operator|*
name|L
argument_list|,
specifier|const
name|Value
operator|*
name|R
argument_list|)
decl|const
decl_stmt|;
comment|/// Compare two Instructions for equivalence, similar to
comment|/// Instruction::isSameOperationAs.
comment|///
comment|/// Stages are listed in "most significant stage first" order:
comment|/// On each stage below, we do comparison between some left and right
comment|/// operation parts. If parts are non-equal, we assign parts comparison
comment|/// result to the operation comparison result and exit from method.
comment|/// Otherwise we proceed to the next stage.
comment|/// Stages:
comment|/// 1. Operations opcodes. Compared as numbers.
comment|/// 2. Number of operands.
comment|/// 3. Operation types. Compared with cmpType method.
comment|/// 4. Compare operation subclass optional data as stream of bytes:
comment|/// just convert it to integers and call cmpNumbers.
comment|/// 5. Compare in operation operand types with cmpType in
comment|/// most significant operand first order.
comment|/// 6. Last stage. Check operations for some specific attributes.
comment|/// For example, for Load it would be:
comment|/// 6.1.Load: volatile (as boolean flag)
comment|/// 6.2.Load: alignment (as integer numbers)
comment|/// 6.3.Load: ordering (as underlying enum class value)
comment|/// 6.4.Load: synch-scope (as integer numbers)
comment|/// 6.5.Load: range metadata (as integer ranges)
comment|/// On this stage its better to see the code, since its not more than 10-15
comment|/// strings for particular instruction, and could change sometimes.
comment|///
comment|/// Sets \p needToCmpOperands to true if the operands of the instructions
comment|/// still must be compared afterwards. In this case it's already guaranteed
comment|/// that both instructions have the same number of operands.
name|int
name|cmpOperations
argument_list|(
specifier|const
name|Instruction
operator|*
name|L
argument_list|,
specifier|const
name|Instruction
operator|*
name|R
argument_list|,
name|bool
operator|&
name|needToCmpOperands
argument_list|)
decl|const
decl_stmt|;
comment|/// cmpType - compares two types,
comment|/// defines total ordering among the types set.
comment|///
comment|/// Return values:
comment|/// 0 if types are equal,
comment|/// -1 if Left is less than Right,
comment|/// +1 if Left is greater than Right.
comment|///
comment|/// Description:
comment|/// Comparison is broken onto stages. Like in lexicographical comparison
comment|/// stage coming first has higher priority.
comment|/// On each explanation stage keep in mind total ordering properties.
comment|///
comment|/// 0. Before comparison we coerce pointer types of 0 address space to
comment|/// integer.
comment|/// We also don't bother with same type at left and right, so
comment|/// just return 0 in this case.
comment|///
comment|/// 1. If types are of different kind (different type IDs).
comment|///    Return result of type IDs comparison, treating them as numbers.
comment|/// 2. If types are integers, check that they have the same width. If they
comment|/// are vectors, check that they have the same count and subtype.
comment|/// 3. Types have the same ID, so check whether they are one of:
comment|/// * Void
comment|/// * Float
comment|/// * Double
comment|/// * X86_FP80
comment|/// * FP128
comment|/// * PPC_FP128
comment|/// * Label
comment|/// * Metadata
comment|/// We can treat these types as equal whenever their IDs are same.
comment|/// 4. If Left and Right are pointers, return result of address space
comment|/// comparison (numbers comparison). We can treat pointer types of same
comment|/// address space as equal.
comment|/// 5. If types are complex.
comment|/// Then both Left and Right are to be expanded and their element types will
comment|/// be checked with the same way. If we get Res != 0 on some stage, return it.
comment|/// Otherwise return 0.
comment|/// 6. For all other cases put llvm_unreachable.
name|int
name|cmpTypes
argument_list|(
name|Type
operator|*
name|TyL
argument_list|,
name|Type
operator|*
name|TyR
argument_list|)
decl|const
decl_stmt|;
name|int
name|cmpNumbers
argument_list|(
name|uint64_t
name|L
argument_list|,
name|uint64_t
name|R
argument_list|)
decl|const
decl_stmt|;
name|int
name|cmpAPInts
argument_list|(
specifier|const
name|APInt
operator|&
name|L
argument_list|,
specifier|const
name|APInt
operator|&
name|R
argument_list|)
decl|const
decl_stmt|;
name|int
name|cmpAPFloats
argument_list|(
specifier|const
name|APFloat
operator|&
name|L
argument_list|,
specifier|const
name|APFloat
operator|&
name|R
argument_list|)
decl|const
decl_stmt|;
name|int
name|cmpMem
argument_list|(
name|StringRef
name|L
argument_list|,
name|StringRef
name|R
argument_list|)
decl|const
decl_stmt|;
comment|// The two functions undergoing comparison.
specifier|const
name|Function
modifier|*
name|FnL
decl_stmt|,
modifier|*
name|FnR
decl_stmt|;
name|private
label|:
name|int
name|cmpOrderings
argument_list|(
name|AtomicOrdering
name|L
argument_list|,
name|AtomicOrdering
name|R
argument_list|)
decl|const
decl_stmt|;
name|int
name|cmpInlineAsm
argument_list|(
specifier|const
name|InlineAsm
operator|*
name|L
argument_list|,
specifier|const
name|InlineAsm
operator|*
name|R
argument_list|)
decl|const
decl_stmt|;
name|int
name|cmpAttrs
argument_list|(
specifier|const
name|AttributeList
name|L
argument_list|,
specifier|const
name|AttributeList
name|R
argument_list|)
decl|const
decl_stmt|;
name|int
name|cmpRangeMetadata
argument_list|(
specifier|const
name|MDNode
operator|*
name|L
argument_list|,
specifier|const
name|MDNode
operator|*
name|R
argument_list|)
decl|const
decl_stmt|;
name|int
name|cmpOperandBundlesSchema
argument_list|(
specifier|const
name|Instruction
operator|*
name|L
argument_list|,
specifier|const
name|Instruction
operator|*
name|R
argument_list|)
decl|const
decl_stmt|;
comment|/// Compare two GEPs for equivalent pointer arithmetic.
comment|/// Parts to be compared for each comparison stage,
comment|/// most significant stage first:
comment|/// 1. Address space. As numbers.
comment|/// 2. Constant offset, (using GEPOperator::accumulateConstantOffset method).
comment|/// 3. Pointer operand type (using cmpType method).
comment|/// 4. Number of operands.
comment|/// 5. Compare operands, using cmpValues method.
name|int
name|cmpGEPs
argument_list|(
specifier|const
name|GEPOperator
operator|*
name|GEPL
argument_list|,
specifier|const
name|GEPOperator
operator|*
name|GEPR
argument_list|)
decl|const
decl_stmt|;
name|int
name|cmpGEPs
argument_list|(
specifier|const
name|GetElementPtrInst
operator|*
name|GEPL
argument_list|,
specifier|const
name|GetElementPtrInst
operator|*
name|GEPR
argument_list|)
decl|const
block|{
return|return
name|cmpGEPs
argument_list|(
name|cast
operator|<
name|GEPOperator
operator|>
operator|(
name|GEPL
operator|)
argument_list|,
name|cast
operator|<
name|GEPOperator
operator|>
operator|(
name|GEPR
operator|)
argument_list|)
return|;
block|}
comment|/// Assign serial numbers to values from left function, and values from
comment|/// right function.
comment|/// Explanation:
comment|/// Being comparing functions we need to compare values we meet at left and
comment|/// right sides.
comment|/// Its easy to sort things out for external values. It just should be
comment|/// the same value at left and right.
comment|/// But for local values (those were introduced inside function body)
comment|/// we have to ensure they were introduced at exactly the same place,
comment|/// and plays the same role.
comment|/// Let's assign serial number to each value when we meet it first time.
comment|/// Values that were met at same place will be with same serial numbers.
comment|/// In this case it would be good to explain few points about values assigned
comment|/// to BBs and other ways of implementation (see below).
comment|///
comment|/// 1. Safety of BB reordering.
comment|/// It's safe to change the order of BasicBlocks in function.
comment|/// Relationship with other functions and serial numbering will not be
comment|/// changed in this case.
comment|/// As follows from FunctionComparator::compare(), we do CFG walk: we start
comment|/// from the entry, and then take each terminator. So it doesn't matter how in
comment|/// fact BBs are ordered in function. And since cmpValues are called during
comment|/// this walk, the numbering depends only on how BBs located inside the CFG.
comment|/// So the answer is - yes. We will get the same numbering.
comment|///
comment|/// 2. Impossibility to use dominance properties of values.
comment|/// If we compare two instruction operands: first is usage of local
comment|/// variable AL from function FL, and second is usage of local variable AR
comment|/// from FR, we could compare their origins and check whether they are
comment|/// defined at the same place.
comment|/// But, we are still not able to compare operands of PHI nodes, since those
comment|/// could be operands from further BBs we didn't scan yet.
comment|/// So it's impossible to use dominance properties in general.
name|mutable
name|DenseMap
operator|<
specifier|const
name|Value
operator|*
operator|,
name|int
operator|>
name|sn_mapL
operator|,
name|sn_mapR
expr_stmt|;
comment|// The global state we will use
name|GlobalNumberState
modifier|*
name|GlobalNumbers
decl_stmt|;
block|}
empty_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// end namespace llvm
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// LLVM_TRANSFORMS_UTILS_FUNCTIONCOMPARATOR_H
end_comment

end_unit

