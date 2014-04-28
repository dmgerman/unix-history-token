begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- llvm/Constants.h - Constant class subclass definitions --*- C++ -*-===//
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
comment|/// @file
end_comment

begin_comment
comment|/// This file contains the declarations for the subclasses of Constant,
end_comment

begin_comment
comment|/// which represent the different flavors of constant values that live in LLVM.
end_comment

begin_comment
comment|/// Note that Constants are immutable (once created they never change) and are
end_comment

begin_comment
comment|/// fully shared by structural equivalence.  This means that two structurally
end_comment

begin_comment
comment|/// equivalent constants will always have the same address.  Constant's are
end_comment

begin_comment
comment|/// created on demand as needed and never deleted: thus clients don't have to
end_comment

begin_comment
comment|/// worry about the lifetime of the objects.
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
name|LLVM_IR_CONSTANTS_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_IR_CONSTANTS_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/APFloat.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/APInt.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/ArrayRef.h"
end_include

begin_include
include|#
directive|include
file|"llvm/IR/Constant.h"
end_include

begin_include
include|#
directive|include
file|"llvm/IR/OperandTraits.h"
end_include

begin_include
include|#
directive|include
file|"llvm/IR/DerivedTypes.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|ArrayType
decl_stmt|;
name|class
name|IntegerType
decl_stmt|;
name|class
name|StructType
decl_stmt|;
name|class
name|PointerType
decl_stmt|;
name|class
name|VectorType
decl_stmt|;
name|class
name|SequentialType
decl_stmt|;
name|template
operator|<
name|class
name|ConstantClass
operator|,
name|class
name|TypeClass
operator|,
name|class
name|ValType
operator|>
expr|struct
name|ConstantCreator
expr_stmt|;
name|template
operator|<
name|class
name|ConstantClass
operator|,
name|class
name|TypeClass
operator|>
expr|struct
name|ConstantArrayCreator
expr_stmt|;
name|template
operator|<
name|class
name|ConstantClass
operator|,
name|class
name|TypeClass
operator|>
expr|struct
name|ConvertConstantType
expr_stmt|;
comment|//===----------------------------------------------------------------------===//
comment|/// This is the shared class of boolean and integer constants. This class
comment|/// represents both boolean and integral constants.
comment|/// @brief Class for constant integers.
name|class
name|ConstantInt
range|:
name|public
name|Constant
block|{
name|virtual
name|void
name|anchor
argument_list|()
block|;
name|void
operator|*
name|operator
name|new
argument_list|(
argument|size_t
argument_list|,
argument|unsigned
argument_list|)
name|LLVM_DELETED_FUNCTION
block|;
name|ConstantInt
argument_list|(
argument|const ConstantInt&
argument_list|)
name|LLVM_DELETED_FUNCTION
block|;
name|ConstantInt
argument_list|(
name|IntegerType
operator|*
name|Ty
argument_list|,
specifier|const
name|APInt
operator|&
name|V
argument_list|)
block|;
name|APInt
name|Val
block|;
name|protected
operator|:
comment|// allocate space for exactly zero operands
name|void
operator|*
name|operator
name|new
argument_list|(
argument|size_t s
argument_list|)
block|{
return|return
name|User
operator|::
name|operator
name|new
argument_list|(
name|s
argument_list|,
literal|0
argument_list|)
return|;
block|}
name|public
operator|:
specifier|static
name|ConstantInt
operator|*
name|getTrue
argument_list|(
name|LLVMContext
operator|&
name|Context
argument_list|)
block|;
specifier|static
name|ConstantInt
operator|*
name|getFalse
argument_list|(
name|LLVMContext
operator|&
name|Context
argument_list|)
block|;
specifier|static
name|Constant
operator|*
name|getTrue
argument_list|(
name|Type
operator|*
name|Ty
argument_list|)
block|;
specifier|static
name|Constant
operator|*
name|getFalse
argument_list|(
name|Type
operator|*
name|Ty
argument_list|)
block|;
comment|/// If Ty is a vector type, return a Constant with a splat of the given
comment|/// value. Otherwise return a ConstantInt for the given value.
specifier|static
name|Constant
operator|*
name|get
argument_list|(
argument|Type *Ty
argument_list|,
argument|uint64_t V
argument_list|,
argument|bool isSigned = false
argument_list|)
block|;
comment|/// Return a ConstantInt with the specified integer value for the specified
comment|/// type. If the type is wider than 64 bits, the value will be zero-extended
comment|/// to fit the type, unless isSigned is true, in which case the value will
comment|/// be interpreted as a 64-bit signed integer and sign-extended to fit
comment|/// the type.
comment|/// @brief Get a ConstantInt for a specific value.
specifier|static
name|ConstantInt
operator|*
name|get
argument_list|(
argument|IntegerType *Ty
argument_list|,
argument|uint64_t V
argument_list|,
argument|bool isSigned = false
argument_list|)
block|;
comment|/// Return a ConstantInt with the specified value for the specified type. The
comment|/// value V will be canonicalized to a an unsigned APInt. Accessing it with
comment|/// either getSExtValue() or getZExtValue() will yield a correctly sized and
comment|/// signed value for the type Ty.
comment|/// @brief Get a ConstantInt for a specific signed value.
specifier|static
name|ConstantInt
operator|*
name|getSigned
argument_list|(
argument|IntegerType *Ty
argument_list|,
argument|int64_t V
argument_list|)
block|;
specifier|static
name|Constant
operator|*
name|getSigned
argument_list|(
argument|Type *Ty
argument_list|,
argument|int64_t V
argument_list|)
block|;
comment|/// Return a ConstantInt with the specified value and an implied Type. The
comment|/// type is the integer type that corresponds to the bit width of the value.
specifier|static
name|ConstantInt
operator|*
name|get
argument_list|(
name|LLVMContext
operator|&
name|Context
argument_list|,
specifier|const
name|APInt
operator|&
name|V
argument_list|)
block|;
comment|/// Return a ConstantInt constructed from the string strStart with the given
comment|/// radix.
specifier|static
name|ConstantInt
operator|*
name|get
argument_list|(
argument|IntegerType *Ty
argument_list|,
argument|StringRef Str
argument_list|,
argument|uint8_t radix
argument_list|)
block|;
comment|/// If Ty is a vector type, return a Constant with a splat of the given
comment|/// value. Otherwise return a ConstantInt for the given value.
specifier|static
name|Constant
operator|*
name|get
argument_list|(
name|Type
operator|*
name|Ty
argument_list|,
specifier|const
name|APInt
operator|&
name|V
argument_list|)
block|;
comment|/// Return the constant as an APInt value reference. This allows clients to
comment|/// obtain a copy of the value, with all its precision in tact.
comment|/// @brief Return the constant's value.
specifier|inline
specifier|const
name|APInt
operator|&
name|getValue
argument_list|()
specifier|const
block|{
return|return
name|Val
return|;
block|}
comment|/// getBitWidth - Return the bitwidth of this constant.
name|unsigned
name|getBitWidth
argument_list|()
specifier|const
block|{
return|return
name|Val
operator|.
name|getBitWidth
argument_list|()
return|;
block|}
comment|/// Return the constant as a 64-bit unsigned integer value after it
comment|/// has been zero extended as appropriate for the type of this constant. Note
comment|/// that this method can assert if the value does not fit in 64 bits.
comment|/// @brief Return the zero extended value.
specifier|inline
name|uint64_t
name|getZExtValue
argument_list|()
specifier|const
block|{
return|return
name|Val
operator|.
name|getZExtValue
argument_list|()
return|;
block|}
comment|/// Return the constant as a 64-bit integer value after it has been sign
comment|/// extended as appropriate for the type of this constant. Note that
comment|/// this method can assert if the value does not fit in 64 bits.
comment|/// @brief Return the sign extended value.
specifier|inline
name|int64_t
name|getSExtValue
argument_list|()
specifier|const
block|{
return|return
name|Val
operator|.
name|getSExtValue
argument_list|()
return|;
block|}
comment|/// A helper method that can be used to determine if the constant contained
comment|/// within is equal to a constant.  This only works for very small values,
comment|/// because this is all that can be represented with all types.
comment|/// @brief Determine if this constant's value is same as an unsigned char.
name|bool
name|equalsInt
argument_list|(
argument|uint64_t V
argument_list|)
specifier|const
block|{
return|return
name|Val
operator|==
name|V
return|;
block|}
comment|/// getType - Specialize the getType() method to always return an IntegerType,
comment|/// which reduces the amount of casting needed in parts of the compiler.
comment|///
specifier|inline
name|IntegerType
operator|*
name|getType
argument_list|()
specifier|const
block|{
return|return
name|cast
operator|<
name|IntegerType
operator|>
operator|(
name|Value
operator|::
name|getType
argument_list|()
operator|)
return|;
block|}
comment|/// This static method returns true if the type Ty is big enough to
comment|/// represent the value V. This can be used to avoid having the get method
comment|/// assert when V is larger than Ty can represent. Note that there are two
comment|/// versions of this method, one for unsigned and one for signed integers.
comment|/// Although ConstantInt canonicalizes everything to an unsigned integer,
comment|/// the signed version avoids callers having to convert a signed quantity
comment|/// to the appropriate unsigned type before calling the method.
comment|/// @returns true if V is a valid value for type Ty
comment|/// @brief Determine if the value is in range for the given type.
specifier|static
name|bool
name|isValueValidForType
argument_list|(
argument|Type *Ty
argument_list|,
argument|uint64_t V
argument_list|)
block|;
specifier|static
name|bool
name|isValueValidForType
argument_list|(
argument|Type *Ty
argument_list|,
argument|int64_t V
argument_list|)
block|;
name|bool
name|isNegative
argument_list|()
specifier|const
block|{
return|return
name|Val
operator|.
name|isNegative
argument_list|()
return|;
block|}
comment|/// This is just a convenience method to make client code smaller for a
comment|/// common code. It also correctly performs the comparison without the
comment|/// potential for an assertion from getZExtValue().
name|bool
name|isZero
argument_list|()
specifier|const
block|{
return|return
name|Val
operator|==
literal|0
return|;
block|}
comment|/// This is just a convenience method to make client code smaller for a
comment|/// common case. It also correctly performs the comparison without the
comment|/// potential for an assertion from getZExtValue().
comment|/// @brief Determine if the value is one.
name|bool
name|isOne
argument_list|()
specifier|const
block|{
return|return
name|Val
operator|==
literal|1
return|;
block|}
comment|/// This function will return true iff every bit in this constant is set
comment|/// to true.
comment|/// @returns true iff this constant's bits are all set to true.
comment|/// @brief Determine if the value is all ones.
name|bool
name|isMinusOne
argument_list|()
specifier|const
block|{
return|return
name|Val
operator|.
name|isAllOnesValue
argument_list|()
return|;
block|}
comment|/// This function will return true iff this constant represents the largest
comment|/// value that may be represented by the constant's type.
comment|/// @returns true iff this is the largest value that may be represented
comment|/// by this type.
comment|/// @brief Determine if the value is maximal.
name|bool
name|isMaxValue
argument_list|(
argument|bool isSigned
argument_list|)
specifier|const
block|{
if|if
condition|(
name|isSigned
condition|)
return|return
name|Val
operator|.
name|isMaxSignedValue
argument_list|()
return|;
else|else
return|return
name|Val
operator|.
name|isMaxValue
argument_list|()
return|;
block|}
comment|/// This function will return true iff this constant represents the smallest
comment|/// value that may be represented by this constant's type.
comment|/// @returns true if this is the smallest value that may be represented by
comment|/// this type.
comment|/// @brief Determine if the value is minimal.
name|bool
name|isMinValue
argument_list|(
argument|bool isSigned
argument_list|)
specifier|const
block|{
if|if
condition|(
name|isSigned
condition|)
return|return
name|Val
operator|.
name|isMinSignedValue
argument_list|()
return|;
else|else
return|return
name|Val
operator|.
name|isMinValue
argument_list|()
return|;
block|}
comment|/// This function will return true iff this constant represents a value with
comment|/// active bits bigger than 64 bits or a value greater than the given uint64_t
comment|/// value.
comment|/// @returns true iff this constant is greater or equal to the given number.
comment|/// @brief Determine if the value is greater or equal to the given number.
name|bool
name|uge
argument_list|(
argument|uint64_t Num
argument_list|)
specifier|const
block|{
return|return
name|Val
operator|.
name|getActiveBits
argument_list|()
operator|>
literal|64
operator|||
name|Val
operator|.
name|getZExtValue
argument_list|()
operator|>=
name|Num
return|;
block|}
comment|/// getLimitedValue - If the value is smaller than the specified limit,
comment|/// return it, otherwise return the limit value.  This causes the value
comment|/// to saturate to the limit.
comment|/// @returns the min of the value of the constant and the specified value
comment|/// @brief Get the constant's value with a saturation limit
name|uint64_t
name|getLimitedValue
argument_list|(
argument|uint64_t Limit = ~
literal|0ULL
argument_list|)
specifier|const
block|{
return|return
name|Val
operator|.
name|getLimitedValue
argument_list|(
name|Limit
argument_list|)
return|;
block|}
comment|/// @brief Methods to support type inquiry through isa, cast, and dyn_cast.
specifier|static
name|bool
name|classof
argument_list|(
argument|const Value *V
argument_list|)
block|{
return|return
name|V
operator|->
name|getValueID
argument_list|()
operator|==
name|ConstantIntVal
return|;
block|}
expr|}
block|;
comment|//===----------------------------------------------------------------------===//
comment|/// ConstantFP - Floating Point Values [float, double]
comment|///
name|class
name|ConstantFP
operator|:
name|public
name|Constant
block|{
name|APFloat
name|Val
block|;
name|virtual
name|void
name|anchor
argument_list|()
block|;
name|void
operator|*
name|operator
name|new
argument_list|(
argument|size_t
argument_list|,
argument|unsigned
argument_list|)
name|LLVM_DELETED_FUNCTION
block|;
name|ConstantFP
argument_list|(
argument|const ConstantFP&
argument_list|)
name|LLVM_DELETED_FUNCTION
block|;
name|friend
name|class
name|LLVMContextImpl
block|;
name|protected
operator|:
name|ConstantFP
argument_list|(
name|Type
operator|*
name|Ty
argument_list|,
specifier|const
name|APFloat
operator|&
name|V
argument_list|)
block|;
name|protected
operator|:
comment|// allocate space for exactly zero operands
name|void
operator|*
name|operator
name|new
argument_list|(
argument|size_t s
argument_list|)
block|{
return|return
name|User
operator|::
name|operator
name|new
argument_list|(
name|s
argument_list|,
literal|0
argument_list|)
return|;
block|}
name|public
operator|:
comment|/// Floating point negation must be implemented with f(x) = -0.0 - x. This
comment|/// method returns the negative zero constant for floating point or vector
comment|/// floating point types; for all other types, it returns the null value.
specifier|static
name|Constant
operator|*
name|getZeroValueForNegation
argument_list|(
name|Type
operator|*
name|Ty
argument_list|)
block|;
comment|/// get() - This returns a ConstantFP, or a vector containing a splat of a
comment|/// ConstantFP, for the specified value in the specified type.  This should
comment|/// only be used for simple constant values like 2.0/1.0 etc, that are
comment|/// known-valid both as host double and as the target format.
specifier|static
name|Constant
operator|*
name|get
argument_list|(
argument|Type* Ty
argument_list|,
argument|double V
argument_list|)
block|;
specifier|static
name|Constant
operator|*
name|get
argument_list|(
argument|Type* Ty
argument_list|,
argument|StringRef Str
argument_list|)
block|;
specifier|static
name|ConstantFP
operator|*
name|get
argument_list|(
name|LLVMContext
operator|&
name|Context
argument_list|,
specifier|const
name|APFloat
operator|&
name|V
argument_list|)
block|;
specifier|static
name|ConstantFP
operator|*
name|getNegativeZero
argument_list|(
name|Type
operator|*
name|Ty
argument_list|)
block|;
specifier|static
name|ConstantFP
operator|*
name|getInfinity
argument_list|(
argument|Type *Ty
argument_list|,
argument|bool Negative = false
argument_list|)
block|;
comment|/// isValueValidForType - return true if Ty is big enough to represent V.
specifier|static
name|bool
name|isValueValidForType
argument_list|(
name|Type
operator|*
name|Ty
argument_list|,
specifier|const
name|APFloat
operator|&
name|V
argument_list|)
block|;
specifier|inline
specifier|const
name|APFloat
operator|&
name|getValueAPF
argument_list|()
specifier|const
block|{
return|return
name|Val
return|;
block|}
comment|/// isZero - Return true if the value is positive or negative zero.
name|bool
name|isZero
argument_list|()
specifier|const
block|{
return|return
name|Val
operator|.
name|isZero
argument_list|()
return|;
block|}
comment|/// isNegative - Return true if the sign bit is set.
name|bool
name|isNegative
argument_list|()
specifier|const
block|{
return|return
name|Val
operator|.
name|isNegative
argument_list|()
return|;
block|}
comment|/// isNaN - Return true if the value is a NaN.
name|bool
name|isNaN
argument_list|()
specifier|const
block|{
return|return
name|Val
operator|.
name|isNaN
argument_list|()
return|;
block|}
comment|/// isExactlyValue - We don't rely on operator== working on double values, as
comment|/// it returns true for things that are clearly not equal, like -0.0 and 0.0.
comment|/// As such, this method can be used to do an exact bit-for-bit comparison of
comment|/// two floating point values.  The version with a double operand is retained
comment|/// because it's so convenient to write isExactlyValue(2.0), but please use
comment|/// it only for simple constants.
name|bool
name|isExactlyValue
argument_list|(
argument|const APFloat&V
argument_list|)
specifier|const
block|;
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
name|APFloat
name|FV
argument_list|(
name|V
argument_list|)
block|;
name|FV
operator|.
name|convert
argument_list|(
name|Val
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
name|FV
argument_list|)
return|;
block|}
comment|/// Methods for support type inquiry through isa, cast, and dyn_cast:
specifier|static
name|bool
name|classof
argument_list|(
argument|const Value *V
argument_list|)
block|{
return|return
name|V
operator|->
name|getValueID
argument_list|()
operator|==
name|ConstantFPVal
return|;
block|}
expr|}
block|;
comment|//===----------------------------------------------------------------------===//
comment|/// ConstantAggregateZero - All zero aggregate value
comment|///
name|class
name|ConstantAggregateZero
operator|:
name|public
name|Constant
block|{
name|void
operator|*
name|operator
name|new
argument_list|(
argument|size_t
argument_list|,
argument|unsigned
argument_list|)
name|LLVM_DELETED_FUNCTION
block|;
name|ConstantAggregateZero
argument_list|(
argument|const ConstantAggregateZero&
argument_list|)
name|LLVM_DELETED_FUNCTION
block|;
name|protected
operator|:
name|explicit
name|ConstantAggregateZero
argument_list|(
name|Type
operator|*
name|ty
argument_list|)
operator|:
name|Constant
argument_list|(
argument|ty
argument_list|,
argument|ConstantAggregateZeroVal
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
block|{}
name|protected
operator|:
comment|// allocate space for exactly zero operands
name|void
operator|*
name|operator
name|new
argument_list|(
argument|size_t s
argument_list|)
block|{
return|return
name|User
operator|::
name|operator
name|new
argument_list|(
name|s
argument_list|,
literal|0
argument_list|)
return|;
block|}
name|public
operator|:
specifier|static
name|ConstantAggregateZero
operator|*
name|get
argument_list|(
name|Type
operator|*
name|Ty
argument_list|)
block|;
name|virtual
name|void
name|destroyConstant
argument_list|()
block|;
comment|/// getSequentialElement - If this CAZ has array or vector type, return a zero
comment|/// with the right element type.
name|Constant
operator|*
name|getSequentialElement
argument_list|()
specifier|const
block|;
comment|/// getStructElement - If this CAZ has struct type, return a zero with the
comment|/// right element type for the specified element.
name|Constant
operator|*
name|getStructElement
argument_list|(
argument|unsigned Elt
argument_list|)
specifier|const
block|;
comment|/// getElementValue - Return a zero of the right value for the specified GEP
comment|/// index.
name|Constant
operator|*
name|getElementValue
argument_list|(
argument|Constant *C
argument_list|)
specifier|const
block|;
comment|/// getElementValue - Return a zero of the right value for the specified GEP
comment|/// index.
name|Constant
operator|*
name|getElementValue
argument_list|(
argument|unsigned Idx
argument_list|)
specifier|const
block|;
comment|/// Methods for support type inquiry through isa, cast, and dyn_cast:
comment|///
specifier|static
name|bool
name|classof
argument_list|(
argument|const Value *V
argument_list|)
block|{
return|return
name|V
operator|->
name|getValueID
argument_list|()
operator|==
name|ConstantAggregateZeroVal
return|;
block|}
expr|}
block|;
comment|//===----------------------------------------------------------------------===//
comment|/// ConstantArray - Constant Array Declarations
comment|///
name|class
name|ConstantArray
operator|:
name|public
name|Constant
block|{
name|friend
expr|struct
name|ConstantArrayCreator
operator|<
name|ConstantArray
block|,
name|ArrayType
operator|>
block|;
name|ConstantArray
argument_list|(
argument|const ConstantArray&
argument_list|)
name|LLVM_DELETED_FUNCTION
block|;
name|protected
operator|:
name|ConstantArray
argument_list|(
name|ArrayType
operator|*
name|T
argument_list|,
name|ArrayRef
operator|<
name|Constant
operator|*
operator|>
name|Val
argument_list|)
block|;
name|public
operator|:
comment|// ConstantArray accessors
specifier|static
name|Constant
operator|*
name|get
argument_list|(
name|ArrayType
operator|*
name|T
argument_list|,
name|ArrayRef
operator|<
name|Constant
operator|*
operator|>
name|V
argument_list|)
block|;
comment|/// Transparently provide more efficient getOperand methods.
name|DECLARE_TRANSPARENT_OPERAND_ACCESSORS
argument_list|(
name|Constant
argument_list|)
block|;
comment|/// getType - Specialize the getType() method to always return an ArrayType,
comment|/// which reduces the amount of casting needed in parts of the compiler.
comment|///
specifier|inline
name|ArrayType
operator|*
name|getType
argument_list|()
specifier|const
block|{
return|return
name|cast
operator|<
name|ArrayType
operator|>
operator|(
name|Value
operator|::
name|getType
argument_list|()
operator|)
return|;
block|}
name|virtual
name|void
name|destroyConstant
argument_list|()
block|;
name|virtual
name|void
name|replaceUsesOfWithOnConstant
argument_list|(
name|Value
operator|*
name|From
argument_list|,
name|Value
operator|*
name|To
argument_list|,
name|Use
operator|*
name|U
argument_list|)
block|;
comment|/// Methods for support type inquiry through isa, cast, and dyn_cast:
specifier|static
name|bool
name|classof
argument_list|(
argument|const Value *V
argument_list|)
block|{
return|return
name|V
operator|->
name|getValueID
argument_list|()
operator|==
name|ConstantArrayVal
return|;
block|}
expr|}
block|;
name|template
operator|<
operator|>
expr|struct
name|OperandTraits
operator|<
name|ConstantArray
operator|>
operator|:
name|public
name|VariadicOperandTraits
operator|<
name|ConstantArray
operator|>
block|{ }
block|;
name|DEFINE_TRANSPARENT_OPERAND_ACCESSORS
argument_list|(
argument|ConstantArray
argument_list|,
argument|Constant
argument_list|)
comment|//===----------------------------------------------------------------------===//
comment|// ConstantStruct - Constant Struct Declarations
comment|//
name|class
name|ConstantStruct
operator|:
name|public
name|Constant
block|{
name|friend
expr|struct
name|ConstantArrayCreator
operator|<
name|ConstantStruct
block|,
name|StructType
operator|>
block|;
name|ConstantStruct
argument_list|(
argument|const ConstantStruct&
argument_list|)
name|LLVM_DELETED_FUNCTION
block|;
name|protected
operator|:
name|ConstantStruct
argument_list|(
name|StructType
operator|*
name|T
argument_list|,
name|ArrayRef
operator|<
name|Constant
operator|*
operator|>
name|Val
argument_list|)
block|;
name|public
operator|:
comment|// ConstantStruct accessors
specifier|static
name|Constant
operator|*
name|get
argument_list|(
name|StructType
operator|*
name|T
argument_list|,
name|ArrayRef
operator|<
name|Constant
operator|*
operator|>
name|V
argument_list|)
block|;
specifier|static
name|Constant
operator|*
name|get
argument_list|(
argument|StructType *T
argument_list|,
argument|...
argument_list|)
name|END_WITH_NULL
block|;
comment|/// getAnon - Return an anonymous struct that has the specified
comment|/// elements.  If the struct is possibly empty, then you must specify a
comment|/// context.
specifier|static
name|Constant
operator|*
name|getAnon
argument_list|(
argument|ArrayRef<Constant*> V
argument_list|,
argument|bool Packed = false
argument_list|)
block|{
return|return
name|get
argument_list|(
name|getTypeForElements
argument_list|(
name|V
argument_list|,
name|Packed
argument_list|)
argument_list|,
name|V
argument_list|)
return|;
block|}
specifier|static
name|Constant
operator|*
name|getAnon
argument_list|(
argument|LLVMContext&Ctx
argument_list|,
argument|ArrayRef<Constant*> V
argument_list|,
argument|bool Packed = false
argument_list|)
block|{
return|return
name|get
argument_list|(
name|getTypeForElements
argument_list|(
name|Ctx
argument_list|,
name|V
argument_list|,
name|Packed
argument_list|)
argument_list|,
name|V
argument_list|)
return|;
block|}
comment|/// getTypeForElements - Return an anonymous struct type to use for a constant
comment|/// with the specified set of elements.  The list must not be empty.
specifier|static
name|StructType
operator|*
name|getTypeForElements
argument_list|(
argument|ArrayRef<Constant*> V
argument_list|,
argument|bool Packed = false
argument_list|)
block|;
comment|/// getTypeForElements - This version of the method allows an empty list.
specifier|static
name|StructType
operator|*
name|getTypeForElements
argument_list|(
argument|LLVMContext&Ctx
argument_list|,
argument|ArrayRef<Constant*> V
argument_list|,
argument|bool Packed = false
argument_list|)
block|;
comment|/// Transparently provide more efficient getOperand methods.
name|DECLARE_TRANSPARENT_OPERAND_ACCESSORS
argument_list|(
name|Constant
argument_list|)
block|;
comment|/// getType() specialization - Reduce amount of casting...
comment|///
specifier|inline
name|StructType
operator|*
name|getType
argument_list|()
specifier|const
block|{
return|return
name|cast
operator|<
name|StructType
operator|>
operator|(
name|Value
operator|::
name|getType
argument_list|()
operator|)
return|;
block|}
name|virtual
name|void
name|destroyConstant
argument_list|()
block|;
name|virtual
name|void
name|replaceUsesOfWithOnConstant
argument_list|(
name|Value
operator|*
name|From
argument_list|,
name|Value
operator|*
name|To
argument_list|,
name|Use
operator|*
name|U
argument_list|)
block|;
comment|/// Methods for support type inquiry through isa, cast, and dyn_cast:
specifier|static
name|bool
name|classof
argument_list|(
argument|const Value *V
argument_list|)
block|{
return|return
name|V
operator|->
name|getValueID
argument_list|()
operator|==
name|ConstantStructVal
return|;
block|}
expr|}
block|;
name|template
operator|<
operator|>
expr|struct
name|OperandTraits
operator|<
name|ConstantStruct
operator|>
operator|:
name|public
name|VariadicOperandTraits
operator|<
name|ConstantStruct
operator|>
block|{ }
block|;
name|DEFINE_TRANSPARENT_OPERAND_ACCESSORS
argument_list|(
argument|ConstantStruct
argument_list|,
argument|Constant
argument_list|)
comment|//===----------------------------------------------------------------------===//
comment|/// ConstantVector - Constant Vector Declarations
comment|///
name|class
name|ConstantVector
operator|:
name|public
name|Constant
block|{
name|friend
expr|struct
name|ConstantArrayCreator
operator|<
name|ConstantVector
block|,
name|VectorType
operator|>
block|;
name|ConstantVector
argument_list|(
argument|const ConstantVector&
argument_list|)
name|LLVM_DELETED_FUNCTION
block|;
name|protected
operator|:
name|ConstantVector
argument_list|(
name|VectorType
operator|*
name|T
argument_list|,
name|ArrayRef
operator|<
name|Constant
operator|*
operator|>
name|Val
argument_list|)
block|;
name|public
operator|:
comment|// ConstantVector accessors
specifier|static
name|Constant
operator|*
name|get
argument_list|(
name|ArrayRef
operator|<
name|Constant
operator|*
operator|>
name|V
argument_list|)
block|;
comment|/// getSplat - Return a ConstantVector with the specified constant in each
comment|/// element.
specifier|static
name|Constant
operator|*
name|getSplat
argument_list|(
argument|unsigned NumElts
argument_list|,
argument|Constant *Elt
argument_list|)
block|;
comment|/// Transparently provide more efficient getOperand methods.
name|DECLARE_TRANSPARENT_OPERAND_ACCESSORS
argument_list|(
name|Constant
argument_list|)
block|;
comment|/// getType - Specialize the getType() method to always return a VectorType,
comment|/// which reduces the amount of casting needed in parts of the compiler.
comment|///
specifier|inline
name|VectorType
operator|*
name|getType
argument_list|()
specifier|const
block|{
return|return
name|cast
operator|<
name|VectorType
operator|>
operator|(
name|Value
operator|::
name|getType
argument_list|()
operator|)
return|;
block|}
comment|/// getSplatValue - If this is a splat constant, meaning that all of the
comment|/// elements have the same value, return that value. Otherwise return NULL.
name|Constant
operator|*
name|getSplatValue
argument_list|()
specifier|const
block|;
name|virtual
name|void
name|destroyConstant
argument_list|()
block|;
name|virtual
name|void
name|replaceUsesOfWithOnConstant
argument_list|(
name|Value
operator|*
name|From
argument_list|,
name|Value
operator|*
name|To
argument_list|,
name|Use
operator|*
name|U
argument_list|)
block|;
comment|/// Methods for support type inquiry through isa, cast, and dyn_cast:
specifier|static
name|bool
name|classof
argument_list|(
argument|const Value *V
argument_list|)
block|{
return|return
name|V
operator|->
name|getValueID
argument_list|()
operator|==
name|ConstantVectorVal
return|;
block|}
expr|}
block|;
name|template
operator|<
operator|>
expr|struct
name|OperandTraits
operator|<
name|ConstantVector
operator|>
operator|:
name|public
name|VariadicOperandTraits
operator|<
name|ConstantVector
operator|>
block|{ }
block|;
name|DEFINE_TRANSPARENT_OPERAND_ACCESSORS
argument_list|(
argument|ConstantVector
argument_list|,
argument|Constant
argument_list|)
comment|//===----------------------------------------------------------------------===//
comment|/// ConstantPointerNull - a constant pointer value that points to null
comment|///
name|class
name|ConstantPointerNull
operator|:
name|public
name|Constant
block|{
name|void
operator|*
name|operator
name|new
argument_list|(
argument|size_t
argument_list|,
argument|unsigned
argument_list|)
name|LLVM_DELETED_FUNCTION
block|;
name|ConstantPointerNull
argument_list|(
argument|const ConstantPointerNull&
argument_list|)
name|LLVM_DELETED_FUNCTION
block|;
name|protected
operator|:
name|explicit
name|ConstantPointerNull
argument_list|(
name|PointerType
operator|*
name|T
argument_list|)
operator|:
name|Constant
argument_list|(
argument|T
argument_list|,
argument|Value::ConstantPointerNullVal
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
block|{}
name|protected
operator|:
comment|// allocate space for exactly zero operands
name|void
operator|*
name|operator
name|new
argument_list|(
argument|size_t s
argument_list|)
block|{
return|return
name|User
operator|::
name|operator
name|new
argument_list|(
name|s
argument_list|,
literal|0
argument_list|)
return|;
block|}
name|public
operator|:
comment|/// get() - Static factory methods - Return objects of the specified value
specifier|static
name|ConstantPointerNull
operator|*
name|get
argument_list|(
name|PointerType
operator|*
name|T
argument_list|)
block|;
name|virtual
name|void
name|destroyConstant
argument_list|()
block|;
comment|/// getType - Specialize the getType() method to always return an PointerType,
comment|/// which reduces the amount of casting needed in parts of the compiler.
comment|///
specifier|inline
name|PointerType
operator|*
name|getType
argument_list|()
specifier|const
block|{
return|return
name|cast
operator|<
name|PointerType
operator|>
operator|(
name|Value
operator|::
name|getType
argument_list|()
operator|)
return|;
block|}
comment|/// Methods for support type inquiry through isa, cast, and dyn_cast:
specifier|static
name|bool
name|classof
argument_list|(
argument|const Value *V
argument_list|)
block|{
return|return
name|V
operator|->
name|getValueID
argument_list|()
operator|==
name|ConstantPointerNullVal
return|;
block|}
expr|}
block|;
comment|//===----------------------------------------------------------------------===//
comment|/// ConstantDataSequential - A vector or array constant whose element type is a
comment|/// simple 1/2/4/8-byte integer or float/double, and whose elements are just
comment|/// simple data values (i.e. ConstantInt/ConstantFP).  This Constant node has no
comment|/// operands because it stores all of the elements of the constant as densely
comment|/// packed data, instead of as Value*'s.
comment|///
comment|/// This is the common base class of ConstantDataArray and ConstantDataVector.
comment|///
name|class
name|ConstantDataSequential
operator|:
name|public
name|Constant
block|{
name|friend
name|class
name|LLVMContextImpl
block|;
comment|/// DataElements - A pointer to the bytes underlying this constant (which is
comment|/// owned by the uniquing StringMap).
specifier|const
name|char
operator|*
name|DataElements
block|;
comment|/// Next - This forms a link list of ConstantDataSequential nodes that have
comment|/// the same value but different type.  For example, 0,0,0,1 could be a 4
comment|/// element array of i8, or a 1-element array of i32.  They'll both end up in
comment|/// the same StringMap bucket, linked up.
name|ConstantDataSequential
operator|*
name|Next
block|;
name|void
operator|*
name|operator
name|new
argument_list|(
argument|size_t
argument_list|,
argument|unsigned
argument_list|)
name|LLVM_DELETED_FUNCTION
block|;
name|ConstantDataSequential
argument_list|(
argument|const ConstantDataSequential&
argument_list|)
name|LLVM_DELETED_FUNCTION
block|;
name|protected
operator|:
name|explicit
name|ConstantDataSequential
argument_list|(
argument|Type *ty
argument_list|,
argument|ValueTy VT
argument_list|,
argument|const char *Data
argument_list|)
operator|:
name|Constant
argument_list|(
name|ty
argument_list|,
name|VT
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
block|,
name|DataElements
argument_list|(
name|Data
argument_list|)
block|,
name|Next
argument_list|(
literal|0
argument_list|)
block|{}
operator|~
name|ConstantDataSequential
argument_list|()
block|{
name|delete
name|Next
block|; }
specifier|static
name|Constant
operator|*
name|getImpl
argument_list|(
argument|StringRef Bytes
argument_list|,
argument|Type *Ty
argument_list|)
block|;
name|protected
operator|:
comment|// allocate space for exactly zero operands.
name|void
operator|*
name|operator
name|new
argument_list|(
argument|size_t s
argument_list|)
block|{
return|return
name|User
operator|::
name|operator
name|new
argument_list|(
name|s
argument_list|,
literal|0
argument_list|)
return|;
block|}
name|public
operator|:
comment|/// isElementTypeCompatible - Return true if a ConstantDataSequential can be
comment|/// formed with a vector or array of the specified element type.
comment|/// ConstantDataArray only works with normal float and int types that are
comment|/// stored densely in memory, not with things like i42 or x86_f80.
specifier|static
name|bool
name|isElementTypeCompatible
argument_list|(
specifier|const
name|Type
operator|*
name|Ty
argument_list|)
block|;
comment|/// getElementAsInteger - If this is a sequential container of integers (of
comment|/// any size), return the specified element in the low bits of a uint64_t.
name|uint64_t
name|getElementAsInteger
argument_list|(
argument|unsigned i
argument_list|)
specifier|const
block|;
comment|/// getElementAsAPFloat - If this is a sequential container of floating point
comment|/// type, return the specified element as an APFloat.
name|APFloat
name|getElementAsAPFloat
argument_list|(
argument|unsigned i
argument_list|)
specifier|const
block|;
comment|/// getElementAsFloat - If this is an sequential container of floats, return
comment|/// the specified element as a float.
name|float
name|getElementAsFloat
argument_list|(
argument|unsigned i
argument_list|)
specifier|const
block|;
comment|/// getElementAsDouble - If this is an sequential container of doubles, return
comment|/// the specified element as a double.
name|double
name|getElementAsDouble
argument_list|(
argument|unsigned i
argument_list|)
specifier|const
block|;
comment|/// getElementAsConstant - Return a Constant for a specified index's element.
comment|/// Note that this has to compute a new constant to return, so it isn't as
comment|/// efficient as getElementAsInteger/Float/Double.
name|Constant
operator|*
name|getElementAsConstant
argument_list|(
argument|unsigned i
argument_list|)
specifier|const
block|;
comment|/// getType - Specialize the getType() method to always return a
comment|/// SequentialType, which reduces the amount of casting needed in parts of the
comment|/// compiler.
specifier|inline
name|SequentialType
operator|*
name|getType
argument_list|()
specifier|const
block|{
return|return
name|cast
operator|<
name|SequentialType
operator|>
operator|(
name|Value
operator|::
name|getType
argument_list|()
operator|)
return|;
block|}
comment|/// getElementType - Return the element type of the array/vector.
name|Type
operator|*
name|getElementType
argument_list|()
specifier|const
block|;
comment|/// getNumElements - Return the number of elements in the array or vector.
name|unsigned
name|getNumElements
argument_list|()
specifier|const
block|;
comment|/// getElementByteSize - Return the size (in bytes) of each element in the
comment|/// array/vector.  The size of the elements is known to be a multiple of one
comment|/// byte.
name|uint64_t
name|getElementByteSize
argument_list|()
specifier|const
block|;
comment|/// isString - This method returns true if this is an array of i8.
name|bool
name|isString
argument_list|()
specifier|const
block|;
comment|/// isCString - This method returns true if the array "isString", ends with a
comment|/// nul byte, and does not contains any other nul bytes.
name|bool
name|isCString
argument_list|()
specifier|const
block|;
comment|/// getAsString - If this array is isString(), then this method returns the
comment|/// array as a StringRef.  Otherwise, it asserts out.
comment|///
name|StringRef
name|getAsString
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
name|isString
argument_list|()
operator|&&
literal|"Not a string"
argument_list|)
block|;
return|return
name|getRawDataValues
argument_list|()
return|;
block|}
comment|/// getAsCString - If this array is isCString(), then this method returns the
comment|/// array (without the trailing null byte) as a StringRef. Otherwise, it
comment|/// asserts out.
comment|///
name|StringRef
name|getAsCString
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
name|isCString
argument_list|()
operator|&&
literal|"Isn't a C string"
argument_list|)
block|;
name|StringRef
name|Str
operator|=
name|getAsString
argument_list|()
block|;
return|return
name|Str
operator|.
name|substr
argument_list|(
literal|0
argument_list|,
name|Str
operator|.
name|size
argument_list|()
operator|-
literal|1
argument_list|)
return|;
block|}
comment|/// getRawDataValues - Return the raw, underlying, bytes of this data.  Note
comment|/// that this is an extremely tricky thing to work with, as it exposes the
comment|/// host endianness of the data elements.
name|StringRef
name|getRawDataValues
argument_list|()
specifier|const
block|;
name|virtual
name|void
name|destroyConstant
argument_list|()
block|;
comment|/// Methods for support type inquiry through isa, cast, and dyn_cast:
comment|///
specifier|static
name|bool
name|classof
argument_list|(
argument|const Value *V
argument_list|)
block|{
return|return
name|V
operator|->
name|getValueID
argument_list|()
operator|==
name|ConstantDataArrayVal
operator|||
name|V
operator|->
name|getValueID
argument_list|()
operator|==
name|ConstantDataVectorVal
return|;
block|}
name|private
operator|:
specifier|const
name|char
operator|*
name|getElementPointer
argument_list|(
argument|unsigned Elt
argument_list|)
specifier|const
block|; }
block|;
comment|//===----------------------------------------------------------------------===//
comment|/// ConstantDataArray - An array constant whose element type is a simple
comment|/// 1/2/4/8-byte integer or float/double, and whose elements are just simple
comment|/// data values (i.e. ConstantInt/ConstantFP).  This Constant node has no
comment|/// operands because it stores all of the elements of the constant as densely
comment|/// packed data, instead of as Value*'s.
name|class
name|ConstantDataArray
operator|:
name|public
name|ConstantDataSequential
block|{
name|void
operator|*
name|operator
name|new
argument_list|(
argument|size_t
argument_list|,
argument|unsigned
argument_list|)
name|LLVM_DELETED_FUNCTION
block|;
name|ConstantDataArray
argument_list|(
argument|const ConstantDataArray&
argument_list|)
name|LLVM_DELETED_FUNCTION
block|;
name|virtual
name|void
name|anchor
argument_list|()
block|;
name|friend
name|class
name|ConstantDataSequential
block|;
name|explicit
name|ConstantDataArray
argument_list|(
name|Type
operator|*
name|ty
argument_list|,
specifier|const
name|char
operator|*
name|Data
argument_list|)
operator|:
name|ConstantDataSequential
argument_list|(
argument|ty
argument_list|,
argument|ConstantDataArrayVal
argument_list|,
argument|Data
argument_list|)
block|{}
name|protected
operator|:
comment|// allocate space for exactly zero operands.
name|void
operator|*
name|operator
name|new
argument_list|(
argument|size_t s
argument_list|)
block|{
return|return
name|User
operator|::
name|operator
name|new
argument_list|(
name|s
argument_list|,
literal|0
argument_list|)
return|;
block|}
name|public
operator|:
comment|/// get() constructors - Return a constant with array type with an element
comment|/// count and element type matching the ArrayRef passed in.  Note that this
comment|/// can return a ConstantAggregateZero object.
specifier|static
name|Constant
operator|*
name|get
argument_list|(
name|LLVMContext
operator|&
name|Context
argument_list|,
name|ArrayRef
operator|<
name|uint8_t
operator|>
name|Elts
argument_list|)
block|;
specifier|static
name|Constant
operator|*
name|get
argument_list|(
name|LLVMContext
operator|&
name|Context
argument_list|,
name|ArrayRef
operator|<
name|uint16_t
operator|>
name|Elts
argument_list|)
block|;
specifier|static
name|Constant
operator|*
name|get
argument_list|(
name|LLVMContext
operator|&
name|Context
argument_list|,
name|ArrayRef
operator|<
name|uint32_t
operator|>
name|Elts
argument_list|)
block|;
specifier|static
name|Constant
operator|*
name|get
argument_list|(
name|LLVMContext
operator|&
name|Context
argument_list|,
name|ArrayRef
operator|<
name|uint64_t
operator|>
name|Elts
argument_list|)
block|;
specifier|static
name|Constant
operator|*
name|get
argument_list|(
name|LLVMContext
operator|&
name|Context
argument_list|,
name|ArrayRef
operator|<
name|float
operator|>
name|Elts
argument_list|)
block|;
specifier|static
name|Constant
operator|*
name|get
argument_list|(
name|LLVMContext
operator|&
name|Context
argument_list|,
name|ArrayRef
operator|<
name|double
operator|>
name|Elts
argument_list|)
block|;
comment|/// getString - This method constructs a CDS and initializes it with a text
comment|/// string. The default behavior (AddNull==true) causes a null terminator to
comment|/// be placed at the end of the array (increasing the length of the string by
comment|/// one more than the StringRef would normally indicate.  Pass AddNull=false
comment|/// to disable this behavior.
specifier|static
name|Constant
operator|*
name|getString
argument_list|(
argument|LLVMContext&Context
argument_list|,
argument|StringRef Initializer
argument_list|,
argument|bool AddNull = true
argument_list|)
block|;
comment|/// getType - Specialize the getType() method to always return an ArrayType,
comment|/// which reduces the amount of casting needed in parts of the compiler.
comment|///
specifier|inline
name|ArrayType
operator|*
name|getType
argument_list|()
specifier|const
block|{
return|return
name|cast
operator|<
name|ArrayType
operator|>
operator|(
name|Value
operator|::
name|getType
argument_list|()
operator|)
return|;
block|}
comment|/// Methods for support type inquiry through isa, cast, and dyn_cast:
comment|///
specifier|static
name|bool
name|classof
argument_list|(
argument|const Value *V
argument_list|)
block|{
return|return
name|V
operator|->
name|getValueID
argument_list|()
operator|==
name|ConstantDataArrayVal
return|;
block|}
expr|}
block|;
comment|//===----------------------------------------------------------------------===//
comment|/// ConstantDataVector - A vector constant whose element type is a simple
comment|/// 1/2/4/8-byte integer or float/double, and whose elements are just simple
comment|/// data values (i.e. ConstantInt/ConstantFP).  This Constant node has no
comment|/// operands because it stores all of the elements of the constant as densely
comment|/// packed data, instead of as Value*'s.
name|class
name|ConstantDataVector
operator|:
name|public
name|ConstantDataSequential
block|{
name|void
operator|*
name|operator
name|new
argument_list|(
argument|size_t
argument_list|,
argument|unsigned
argument_list|)
name|LLVM_DELETED_FUNCTION
block|;
name|ConstantDataVector
argument_list|(
argument|const ConstantDataVector&
argument_list|)
name|LLVM_DELETED_FUNCTION
block|;
name|virtual
name|void
name|anchor
argument_list|()
block|;
name|friend
name|class
name|ConstantDataSequential
block|;
name|explicit
name|ConstantDataVector
argument_list|(
name|Type
operator|*
name|ty
argument_list|,
specifier|const
name|char
operator|*
name|Data
argument_list|)
operator|:
name|ConstantDataSequential
argument_list|(
argument|ty
argument_list|,
argument|ConstantDataVectorVal
argument_list|,
argument|Data
argument_list|)
block|{}
name|protected
operator|:
comment|// allocate space for exactly zero operands.
name|void
operator|*
name|operator
name|new
argument_list|(
argument|size_t s
argument_list|)
block|{
return|return
name|User
operator|::
name|operator
name|new
argument_list|(
name|s
argument_list|,
literal|0
argument_list|)
return|;
block|}
name|public
operator|:
comment|/// get() constructors - Return a constant with vector type with an element
comment|/// count and element type matching the ArrayRef passed in.  Note that this
comment|/// can return a ConstantAggregateZero object.
specifier|static
name|Constant
operator|*
name|get
argument_list|(
name|LLVMContext
operator|&
name|Context
argument_list|,
name|ArrayRef
operator|<
name|uint8_t
operator|>
name|Elts
argument_list|)
block|;
specifier|static
name|Constant
operator|*
name|get
argument_list|(
name|LLVMContext
operator|&
name|Context
argument_list|,
name|ArrayRef
operator|<
name|uint16_t
operator|>
name|Elts
argument_list|)
block|;
specifier|static
name|Constant
operator|*
name|get
argument_list|(
name|LLVMContext
operator|&
name|Context
argument_list|,
name|ArrayRef
operator|<
name|uint32_t
operator|>
name|Elts
argument_list|)
block|;
specifier|static
name|Constant
operator|*
name|get
argument_list|(
name|LLVMContext
operator|&
name|Context
argument_list|,
name|ArrayRef
operator|<
name|uint64_t
operator|>
name|Elts
argument_list|)
block|;
specifier|static
name|Constant
operator|*
name|get
argument_list|(
name|LLVMContext
operator|&
name|Context
argument_list|,
name|ArrayRef
operator|<
name|float
operator|>
name|Elts
argument_list|)
block|;
specifier|static
name|Constant
operator|*
name|get
argument_list|(
name|LLVMContext
operator|&
name|Context
argument_list|,
name|ArrayRef
operator|<
name|double
operator|>
name|Elts
argument_list|)
block|;
comment|/// getSplat - Return a ConstantVector with the specified constant in each
comment|/// element.  The specified constant has to be a of a compatible type (i8/i16/
comment|/// i32/i64/float/double) and must be a ConstantFP or ConstantInt.
specifier|static
name|Constant
operator|*
name|getSplat
argument_list|(
argument|unsigned NumElts
argument_list|,
argument|Constant *Elt
argument_list|)
block|;
comment|/// getSplatValue - If this is a splat constant, meaning that all of the
comment|/// elements have the same value, return that value. Otherwise return NULL.
name|Constant
operator|*
name|getSplatValue
argument_list|()
specifier|const
block|;
comment|/// getType - Specialize the getType() method to always return a VectorType,
comment|/// which reduces the amount of casting needed in parts of the compiler.
comment|///
specifier|inline
name|VectorType
operator|*
name|getType
argument_list|()
specifier|const
block|{
return|return
name|cast
operator|<
name|VectorType
operator|>
operator|(
name|Value
operator|::
name|getType
argument_list|()
operator|)
return|;
block|}
comment|/// Methods for support type inquiry through isa, cast, and dyn_cast:
comment|///
specifier|static
name|bool
name|classof
argument_list|(
argument|const Value *V
argument_list|)
block|{
return|return
name|V
operator|->
name|getValueID
argument_list|()
operator|==
name|ConstantDataVectorVal
return|;
block|}
expr|}
block|;
comment|/// BlockAddress - The address of a basic block.
comment|///
name|class
name|BlockAddress
operator|:
name|public
name|Constant
block|{
name|void
operator|*
name|operator
name|new
argument_list|(
argument|size_t
argument_list|,
argument|unsigned
argument_list|)
name|LLVM_DELETED_FUNCTION
block|;
name|void
operator|*
name|operator
name|new
argument_list|(
argument|size_t s
argument_list|)
block|{
return|return
name|User
operator|::
name|operator
name|new
argument_list|(
name|s
argument_list|,
literal|2
argument_list|)
return|;
block|}
name|BlockAddress
argument_list|(
name|Function
operator|*
name|F
argument_list|,
name|BasicBlock
operator|*
name|BB
argument_list|)
block|;
name|public
operator|:
comment|/// get - Return a BlockAddress for the specified function and basic block.
specifier|static
name|BlockAddress
operator|*
name|get
argument_list|(
name|Function
operator|*
name|F
argument_list|,
name|BasicBlock
operator|*
name|BB
argument_list|)
block|;
comment|/// get - Return a BlockAddress for the specified basic block.  The basic
comment|/// block must be embedded into a function.
specifier|static
name|BlockAddress
operator|*
name|get
argument_list|(
name|BasicBlock
operator|*
name|BB
argument_list|)
block|;
comment|/// Transparently provide more efficient getOperand methods.
name|DECLARE_TRANSPARENT_OPERAND_ACCESSORS
argument_list|(
name|Value
argument_list|)
block|;
name|Function
operator|*
name|getFunction
argument_list|()
specifier|const
block|{
return|return
operator|(
name|Function
operator|*
operator|)
name|Op
operator|<
literal|0
operator|>
operator|(
operator|)
operator|.
name|get
argument_list|()
return|;
block|}
name|BasicBlock
operator|*
name|getBasicBlock
argument_list|()
specifier|const
block|{
return|return
operator|(
name|BasicBlock
operator|*
operator|)
name|Op
operator|<
literal|1
operator|>
operator|(
operator|)
operator|.
name|get
argument_list|()
return|;
block|}
name|virtual
name|void
name|destroyConstant
argument_list|()
block|;
name|virtual
name|void
name|replaceUsesOfWithOnConstant
argument_list|(
name|Value
operator|*
name|From
argument_list|,
name|Value
operator|*
name|To
argument_list|,
name|Use
operator|*
name|U
argument_list|)
block|;
comment|/// Methods for support type inquiry through isa, cast, and dyn_cast:
specifier|static
specifier|inline
name|bool
name|classof
argument_list|(
argument|const Value *V
argument_list|)
block|{
return|return
name|V
operator|->
name|getValueID
argument_list|()
operator|==
name|BlockAddressVal
return|;
block|}
expr|}
block|;
name|template
operator|<
operator|>
expr|struct
name|OperandTraits
operator|<
name|BlockAddress
operator|>
operator|:
name|public
name|FixedNumOperandTraits
operator|<
name|BlockAddress
block|,
literal|2
operator|>
block|{ }
block|;
name|DEFINE_TRANSPARENT_OPERAND_ACCESSORS
argument_list|(
argument|BlockAddress
argument_list|,
argument|Value
argument_list|)
comment|//===----------------------------------------------------------------------===//
comment|/// ConstantExpr - a constant value that is initialized with an expression using
comment|/// other constant values.
comment|///
comment|/// This class uses the standard Instruction opcodes to define the various
comment|/// constant expressions.  The Opcode field for the ConstantExpr class is
comment|/// maintained in the Value::SubclassData field.
name|class
name|ConstantExpr
operator|:
name|public
name|Constant
block|{
name|friend
expr|struct
name|ConstantCreator
operator|<
name|ConstantExpr
block|,
name|Type
block|,
name|std
operator|::
name|pair
operator|<
name|unsigned
block|,
name|std
operator|::
name|vector
operator|<
name|Constant
operator|*
operator|>
expr|>
operator|>
block|;
name|friend
expr|struct
name|ConvertConstantType
operator|<
name|ConstantExpr
block|,
name|Type
operator|>
block|;
name|protected
operator|:
name|ConstantExpr
argument_list|(
argument|Type *ty
argument_list|,
argument|unsigned Opcode
argument_list|,
argument|Use *Ops
argument_list|,
argument|unsigned NumOps
argument_list|)
operator|:
name|Constant
argument_list|(
argument|ty
argument_list|,
argument|ConstantExprVal
argument_list|,
argument|Ops
argument_list|,
argument|NumOps
argument_list|)
block|{
comment|// Operation type (an Instruction opcode) is stored as the SubclassData.
name|setValueSubclassData
argument_list|(
name|Opcode
argument_list|)
block|;   }
name|public
operator|:
comment|// Static methods to construct a ConstantExpr of different kinds.  Note that
comment|// these methods may return a object that is not an instance of the
comment|// ConstantExpr class, because they will attempt to fold the constant
comment|// expression into something simpler if possible.
comment|/// getAlignOf constant expr - computes the alignment of a type in a target
comment|/// independent way (Note: the return type is an i64).
specifier|static
name|Constant
operator|*
name|getAlignOf
argument_list|(
name|Type
operator|*
name|Ty
argument_list|)
block|;
comment|/// getSizeOf constant expr - computes the (alloc) size of a type (in
comment|/// address-units, not bits) in a target independent way (Note: the return
comment|/// type is an i64).
comment|///
specifier|static
name|Constant
operator|*
name|getSizeOf
argument_list|(
name|Type
operator|*
name|Ty
argument_list|)
block|;
comment|/// getOffsetOf constant expr - computes the offset of a struct field in a
comment|/// target independent way (Note: the return type is an i64).
comment|///
specifier|static
name|Constant
operator|*
name|getOffsetOf
argument_list|(
argument|StructType *STy
argument_list|,
argument|unsigned FieldNo
argument_list|)
block|;
comment|/// getOffsetOf constant expr - This is a generalized form of getOffsetOf,
comment|/// which supports any aggregate type, and any Constant index.
comment|///
specifier|static
name|Constant
operator|*
name|getOffsetOf
argument_list|(
name|Type
operator|*
name|Ty
argument_list|,
name|Constant
operator|*
name|FieldNo
argument_list|)
block|;
specifier|static
name|Constant
operator|*
name|getNeg
argument_list|(
argument|Constant *C
argument_list|,
argument|bool HasNUW = false
argument_list|,
argument|bool HasNSW =false
argument_list|)
block|;
specifier|static
name|Constant
operator|*
name|getFNeg
argument_list|(
name|Constant
operator|*
name|C
argument_list|)
block|;
specifier|static
name|Constant
operator|*
name|getNot
argument_list|(
name|Constant
operator|*
name|C
argument_list|)
block|;
specifier|static
name|Constant
operator|*
name|getAdd
argument_list|(
argument|Constant *C1
argument_list|,
argument|Constant *C2
argument_list|,
argument|bool HasNUW = false
argument_list|,
argument|bool HasNSW = false
argument_list|)
block|;
specifier|static
name|Constant
operator|*
name|getFAdd
argument_list|(
name|Constant
operator|*
name|C1
argument_list|,
name|Constant
operator|*
name|C2
argument_list|)
block|;
specifier|static
name|Constant
operator|*
name|getSub
argument_list|(
argument|Constant *C1
argument_list|,
argument|Constant *C2
argument_list|,
argument|bool HasNUW = false
argument_list|,
argument|bool HasNSW = false
argument_list|)
block|;
specifier|static
name|Constant
operator|*
name|getFSub
argument_list|(
name|Constant
operator|*
name|C1
argument_list|,
name|Constant
operator|*
name|C2
argument_list|)
block|;
specifier|static
name|Constant
operator|*
name|getMul
argument_list|(
argument|Constant *C1
argument_list|,
argument|Constant *C2
argument_list|,
argument|bool HasNUW = false
argument_list|,
argument|bool HasNSW = false
argument_list|)
block|;
specifier|static
name|Constant
operator|*
name|getFMul
argument_list|(
name|Constant
operator|*
name|C1
argument_list|,
name|Constant
operator|*
name|C2
argument_list|)
block|;
specifier|static
name|Constant
operator|*
name|getUDiv
argument_list|(
argument|Constant *C1
argument_list|,
argument|Constant *C2
argument_list|,
argument|bool isExact = false
argument_list|)
block|;
specifier|static
name|Constant
operator|*
name|getSDiv
argument_list|(
argument|Constant *C1
argument_list|,
argument|Constant *C2
argument_list|,
argument|bool isExact = false
argument_list|)
block|;
specifier|static
name|Constant
operator|*
name|getFDiv
argument_list|(
name|Constant
operator|*
name|C1
argument_list|,
name|Constant
operator|*
name|C2
argument_list|)
block|;
specifier|static
name|Constant
operator|*
name|getURem
argument_list|(
name|Constant
operator|*
name|C1
argument_list|,
name|Constant
operator|*
name|C2
argument_list|)
block|;
specifier|static
name|Constant
operator|*
name|getSRem
argument_list|(
name|Constant
operator|*
name|C1
argument_list|,
name|Constant
operator|*
name|C2
argument_list|)
block|;
specifier|static
name|Constant
operator|*
name|getFRem
argument_list|(
name|Constant
operator|*
name|C1
argument_list|,
name|Constant
operator|*
name|C2
argument_list|)
block|;
specifier|static
name|Constant
operator|*
name|getAnd
argument_list|(
name|Constant
operator|*
name|C1
argument_list|,
name|Constant
operator|*
name|C2
argument_list|)
block|;
specifier|static
name|Constant
operator|*
name|getOr
argument_list|(
name|Constant
operator|*
name|C1
argument_list|,
name|Constant
operator|*
name|C2
argument_list|)
block|;
specifier|static
name|Constant
operator|*
name|getXor
argument_list|(
name|Constant
operator|*
name|C1
argument_list|,
name|Constant
operator|*
name|C2
argument_list|)
block|;
specifier|static
name|Constant
operator|*
name|getShl
argument_list|(
argument|Constant *C1
argument_list|,
argument|Constant *C2
argument_list|,
argument|bool HasNUW = false
argument_list|,
argument|bool HasNSW = false
argument_list|)
block|;
specifier|static
name|Constant
operator|*
name|getLShr
argument_list|(
argument|Constant *C1
argument_list|,
argument|Constant *C2
argument_list|,
argument|bool isExact = false
argument_list|)
block|;
specifier|static
name|Constant
operator|*
name|getAShr
argument_list|(
argument|Constant *C1
argument_list|,
argument|Constant *C2
argument_list|,
argument|bool isExact = false
argument_list|)
block|;
specifier|static
name|Constant
operator|*
name|getTrunc
argument_list|(
name|Constant
operator|*
name|C
argument_list|,
name|Type
operator|*
name|Ty
argument_list|)
block|;
specifier|static
name|Constant
operator|*
name|getSExt
argument_list|(
name|Constant
operator|*
name|C
argument_list|,
name|Type
operator|*
name|Ty
argument_list|)
block|;
specifier|static
name|Constant
operator|*
name|getZExt
argument_list|(
name|Constant
operator|*
name|C
argument_list|,
name|Type
operator|*
name|Ty
argument_list|)
block|;
specifier|static
name|Constant
operator|*
name|getFPTrunc
argument_list|(
name|Constant
operator|*
name|C
argument_list|,
name|Type
operator|*
name|Ty
argument_list|)
block|;
specifier|static
name|Constant
operator|*
name|getFPExtend
argument_list|(
name|Constant
operator|*
name|C
argument_list|,
name|Type
operator|*
name|Ty
argument_list|)
block|;
specifier|static
name|Constant
operator|*
name|getUIToFP
argument_list|(
name|Constant
operator|*
name|C
argument_list|,
name|Type
operator|*
name|Ty
argument_list|)
block|;
specifier|static
name|Constant
operator|*
name|getSIToFP
argument_list|(
name|Constant
operator|*
name|C
argument_list|,
name|Type
operator|*
name|Ty
argument_list|)
block|;
specifier|static
name|Constant
operator|*
name|getFPToUI
argument_list|(
name|Constant
operator|*
name|C
argument_list|,
name|Type
operator|*
name|Ty
argument_list|)
block|;
specifier|static
name|Constant
operator|*
name|getFPToSI
argument_list|(
name|Constant
operator|*
name|C
argument_list|,
name|Type
operator|*
name|Ty
argument_list|)
block|;
specifier|static
name|Constant
operator|*
name|getPtrToInt
argument_list|(
name|Constant
operator|*
name|C
argument_list|,
name|Type
operator|*
name|Ty
argument_list|)
block|;
specifier|static
name|Constant
operator|*
name|getIntToPtr
argument_list|(
name|Constant
operator|*
name|C
argument_list|,
name|Type
operator|*
name|Ty
argument_list|)
block|;
specifier|static
name|Constant
operator|*
name|getBitCast
argument_list|(
name|Constant
operator|*
name|C
argument_list|,
name|Type
operator|*
name|Ty
argument_list|)
block|;
specifier|static
name|Constant
operator|*
name|getAddrSpaceCast
argument_list|(
name|Constant
operator|*
name|C
argument_list|,
name|Type
operator|*
name|Ty
argument_list|)
block|;
specifier|static
name|Constant
operator|*
name|getNSWNeg
argument_list|(
argument|Constant *C
argument_list|)
block|{
return|return
name|getNeg
argument_list|(
name|C
argument_list|,
name|false
argument_list|,
name|true
argument_list|)
return|;
block|}
specifier|static
name|Constant
operator|*
name|getNUWNeg
argument_list|(
argument|Constant *C
argument_list|)
block|{
return|return
name|getNeg
argument_list|(
name|C
argument_list|,
name|true
argument_list|,
name|false
argument_list|)
return|;
block|}
specifier|static
name|Constant
operator|*
name|getNSWAdd
argument_list|(
argument|Constant *C1
argument_list|,
argument|Constant *C2
argument_list|)
block|{
return|return
name|getAdd
argument_list|(
name|C1
argument_list|,
name|C2
argument_list|,
name|false
argument_list|,
name|true
argument_list|)
return|;
block|}
specifier|static
name|Constant
operator|*
name|getNUWAdd
argument_list|(
argument|Constant *C1
argument_list|,
argument|Constant *C2
argument_list|)
block|{
return|return
name|getAdd
argument_list|(
name|C1
argument_list|,
name|C2
argument_list|,
name|true
argument_list|,
name|false
argument_list|)
return|;
block|}
specifier|static
name|Constant
operator|*
name|getNSWSub
argument_list|(
argument|Constant *C1
argument_list|,
argument|Constant *C2
argument_list|)
block|{
return|return
name|getSub
argument_list|(
name|C1
argument_list|,
name|C2
argument_list|,
name|false
argument_list|,
name|true
argument_list|)
return|;
block|}
specifier|static
name|Constant
operator|*
name|getNUWSub
argument_list|(
argument|Constant *C1
argument_list|,
argument|Constant *C2
argument_list|)
block|{
return|return
name|getSub
argument_list|(
name|C1
argument_list|,
name|C2
argument_list|,
name|true
argument_list|,
name|false
argument_list|)
return|;
block|}
specifier|static
name|Constant
operator|*
name|getNSWMul
argument_list|(
argument|Constant *C1
argument_list|,
argument|Constant *C2
argument_list|)
block|{
return|return
name|getMul
argument_list|(
name|C1
argument_list|,
name|C2
argument_list|,
name|false
argument_list|,
name|true
argument_list|)
return|;
block|}
specifier|static
name|Constant
operator|*
name|getNUWMul
argument_list|(
argument|Constant *C1
argument_list|,
argument|Constant *C2
argument_list|)
block|{
return|return
name|getMul
argument_list|(
name|C1
argument_list|,
name|C2
argument_list|,
name|true
argument_list|,
name|false
argument_list|)
return|;
block|}
specifier|static
name|Constant
operator|*
name|getNSWShl
argument_list|(
argument|Constant *C1
argument_list|,
argument|Constant *C2
argument_list|)
block|{
return|return
name|getShl
argument_list|(
name|C1
argument_list|,
name|C2
argument_list|,
name|false
argument_list|,
name|true
argument_list|)
return|;
block|}
specifier|static
name|Constant
operator|*
name|getNUWShl
argument_list|(
argument|Constant *C1
argument_list|,
argument|Constant *C2
argument_list|)
block|{
return|return
name|getShl
argument_list|(
name|C1
argument_list|,
name|C2
argument_list|,
name|true
argument_list|,
name|false
argument_list|)
return|;
block|}
specifier|static
name|Constant
operator|*
name|getExactSDiv
argument_list|(
argument|Constant *C1
argument_list|,
argument|Constant *C2
argument_list|)
block|{
return|return
name|getSDiv
argument_list|(
name|C1
argument_list|,
name|C2
argument_list|,
name|true
argument_list|)
return|;
block|}
specifier|static
name|Constant
operator|*
name|getExactUDiv
argument_list|(
argument|Constant *C1
argument_list|,
argument|Constant *C2
argument_list|)
block|{
return|return
name|getUDiv
argument_list|(
name|C1
argument_list|,
name|C2
argument_list|,
name|true
argument_list|)
return|;
block|}
specifier|static
name|Constant
operator|*
name|getExactAShr
argument_list|(
argument|Constant *C1
argument_list|,
argument|Constant *C2
argument_list|)
block|{
return|return
name|getAShr
argument_list|(
name|C1
argument_list|,
name|C2
argument_list|,
name|true
argument_list|)
return|;
block|}
specifier|static
name|Constant
operator|*
name|getExactLShr
argument_list|(
argument|Constant *C1
argument_list|,
argument|Constant *C2
argument_list|)
block|{
return|return
name|getLShr
argument_list|(
name|C1
argument_list|,
name|C2
argument_list|,
name|true
argument_list|)
return|;
block|}
comment|/// getBinOpIdentity - Return the identity for the given binary operation,
comment|/// i.e. a constant C such that X op C = X and C op X = X for every X.  It
comment|/// returns null if the operator doesn't have an identity.
specifier|static
name|Constant
operator|*
name|getBinOpIdentity
argument_list|(
argument|unsigned Opcode
argument_list|,
argument|Type *Ty
argument_list|)
block|;
comment|/// getBinOpAbsorber - Return the absorbing element for the given binary
comment|/// operation, i.e. a constant C such that X op C = C and C op X = C for
comment|/// every X.  For example, this returns zero for integer multiplication.
comment|/// It returns null if the operator doesn't have an absorbing element.
specifier|static
name|Constant
operator|*
name|getBinOpAbsorber
argument_list|(
argument|unsigned Opcode
argument_list|,
argument|Type *Ty
argument_list|)
block|;
comment|/// Transparently provide more efficient getOperand methods.
name|DECLARE_TRANSPARENT_OPERAND_ACCESSORS
argument_list|(
name|Constant
argument_list|)
block|;
comment|// @brief Convenience function for getting one of the casting operations
comment|// using a CastOps opcode.
specifier|static
name|Constant
operator|*
name|getCast
argument_list|(
argument|unsigned ops
argument_list|,
comment|///< The opcode for the conversion
argument|Constant *C
argument_list|,
comment|///< The constant to be converted
argument|Type *Ty
comment|///< The type to which the constant is converted
argument_list|)
block|;
comment|// @brief Create a ZExt or BitCast cast constant expression
specifier|static
name|Constant
operator|*
name|getZExtOrBitCast
argument_list|(
name|Constant
operator|*
name|C
argument_list|,
comment|///< The constant to zext or bitcast
name|Type
operator|*
name|Ty
comment|///< The type to zext or bitcast C to
argument_list|)
block|;
comment|// @brief Create a SExt or BitCast cast constant expression
specifier|static
name|Constant
operator|*
name|getSExtOrBitCast
argument_list|(
name|Constant
operator|*
name|C
argument_list|,
comment|///< The constant to sext or bitcast
name|Type
operator|*
name|Ty
comment|///< The type to sext or bitcast C to
argument_list|)
block|;
comment|// @brief Create a Trunc or BitCast cast constant expression
specifier|static
name|Constant
operator|*
name|getTruncOrBitCast
argument_list|(
name|Constant
operator|*
name|C
argument_list|,
comment|///< The constant to trunc or bitcast
name|Type
operator|*
name|Ty
comment|///< The type to trunc or bitcast C to
argument_list|)
block|;
comment|/// @brief Create a BitCast, AddrSpaceCast, or a PtrToInt cast constant
comment|/// expression.
specifier|static
name|Constant
operator|*
name|getPointerCast
argument_list|(
name|Constant
operator|*
name|C
argument_list|,
comment|///< The pointer value to be casted (operand 0)
name|Type
operator|*
name|Ty
comment|///< The type to which cast should be made
argument_list|)
block|;
comment|/// @brief Create a BitCast or AddrSpaceCast for a pointer type depending on
comment|/// the address space.
specifier|static
name|Constant
operator|*
name|getPointerBitCastOrAddrSpaceCast
argument_list|(
name|Constant
operator|*
name|C
argument_list|,
comment|///< The constant to addrspacecast or bitcast
name|Type
operator|*
name|Ty
comment|///< The type to bitcast or addrspacecast C to
argument_list|)
block|;
comment|/// @brief Create a ZExt, Bitcast or Trunc for integer -> integer casts
specifier|static
name|Constant
operator|*
name|getIntegerCast
argument_list|(
argument|Constant *C
argument_list|,
comment|///< The integer constant to be casted
argument|Type *Ty
argument_list|,
comment|///< The integer type to cast to
argument|bool isSigned
comment|///< Whether C should be treated as signed or not
argument_list|)
block|;
comment|/// @brief Create a FPExt, Bitcast or FPTrunc for fp -> fp casts
specifier|static
name|Constant
operator|*
name|getFPCast
argument_list|(
name|Constant
operator|*
name|C
argument_list|,
comment|///< The integer constant to be casted
name|Type
operator|*
name|Ty
comment|///< The integer type to cast to
argument_list|)
block|;
comment|/// @brief Return true if this is a convert constant expression
name|bool
name|isCast
argument_list|()
specifier|const
block|;
comment|/// @brief Return true if this is a compare constant expression
name|bool
name|isCompare
argument_list|()
specifier|const
block|;
comment|/// @brief Return true if this is an insertvalue or extractvalue expression,
comment|/// and the getIndices() method may be used.
name|bool
name|hasIndices
argument_list|()
specifier|const
block|;
comment|/// @brief Return true if this is a getelementptr expression and all
comment|/// the index operands are compile-time known integers within the
comment|/// corresponding notional static array extents. Note that this is
comment|/// not equivalant to, a subset of, or a superset of the "inbounds"
comment|/// property.
name|bool
name|isGEPWithNoNotionalOverIndexing
argument_list|()
specifier|const
block|;
comment|/// Select constant expr
comment|///
specifier|static
name|Constant
operator|*
name|getSelect
argument_list|(
name|Constant
operator|*
name|C
argument_list|,
name|Constant
operator|*
name|V1
argument_list|,
name|Constant
operator|*
name|V2
argument_list|)
block|;
comment|/// get - Return a binary or shift operator constant expression,
comment|/// folding if possible.
comment|///
specifier|static
name|Constant
operator|*
name|get
argument_list|(
argument|unsigned Opcode
argument_list|,
argument|Constant *C1
argument_list|,
argument|Constant *C2
argument_list|,
argument|unsigned Flags =
literal|0
argument_list|)
block|;
comment|/// @brief Return an ICmp or FCmp comparison operator constant expression.
specifier|static
name|Constant
operator|*
name|getCompare
argument_list|(
argument|unsigned short pred
argument_list|,
argument|Constant *C1
argument_list|,
argument|Constant *C2
argument_list|)
block|;
comment|/// get* - Return some common constants without having to
comment|/// specify the full Instruction::OPCODE identifier.
comment|///
specifier|static
name|Constant
operator|*
name|getICmp
argument_list|(
argument|unsigned short pred
argument_list|,
argument|Constant *LHS
argument_list|,
argument|Constant *RHS
argument_list|)
block|;
specifier|static
name|Constant
operator|*
name|getFCmp
argument_list|(
argument|unsigned short pred
argument_list|,
argument|Constant *LHS
argument_list|,
argument|Constant *RHS
argument_list|)
block|;
comment|/// Getelementptr form.  Value* is only accepted for convenience;
comment|/// all elements must be Constant's.
comment|///
specifier|static
name|Constant
operator|*
name|getGetElementPtr
argument_list|(
argument|Constant *C
argument_list|,
argument|ArrayRef<Constant *> IdxList
argument_list|,
argument|bool InBounds = false
argument_list|)
block|{
return|return
name|getGetElementPtr
argument_list|(
name|C
argument_list|,
name|makeArrayRef
argument_list|(
operator|(
name|Value
operator|*
specifier|const
operator|*
operator|)
name|IdxList
operator|.
name|data
argument_list|()
argument_list|,
name|IdxList
operator|.
name|size
argument_list|()
argument_list|)
argument_list|,
name|InBounds
argument_list|)
return|;
block|}
specifier|static
name|Constant
operator|*
name|getGetElementPtr
argument_list|(
argument|Constant *C
argument_list|,
argument|Constant *Idx
argument_list|,
argument|bool InBounds = false
argument_list|)
block|{
comment|// This form of the function only exists to avoid ambiguous overload
comment|// warnings about whether to convert Idx to ArrayRef<Constant *> or
comment|// ArrayRef<Value *>.
return|return
name|getGetElementPtr
argument_list|(
name|C
argument_list|,
name|cast
operator|<
name|Value
operator|>
operator|(
name|Idx
operator|)
argument_list|,
name|InBounds
argument_list|)
return|;
block|}
specifier|static
name|Constant
operator|*
name|getGetElementPtr
argument_list|(
argument|Constant *C
argument_list|,
argument|ArrayRef<Value *> IdxList
argument_list|,
argument|bool InBounds = false
argument_list|)
block|;
comment|/// Create an "inbounds" getelementptr. See the documentation for the
comment|/// "inbounds" flag in LangRef.html for details.
specifier|static
name|Constant
operator|*
name|getInBoundsGetElementPtr
argument_list|(
argument|Constant *C
argument_list|,
argument|ArrayRef<Constant *> IdxList
argument_list|)
block|{
return|return
name|getGetElementPtr
argument_list|(
name|C
argument_list|,
name|IdxList
argument_list|,
name|true
argument_list|)
return|;
block|}
specifier|static
name|Constant
operator|*
name|getInBoundsGetElementPtr
argument_list|(
argument|Constant *C
argument_list|,
argument|Constant *Idx
argument_list|)
block|{
comment|// This form of the function only exists to avoid ambiguous overload
comment|// warnings about whether to convert Idx to ArrayRef<Constant *> or
comment|// ArrayRef<Value *>.
return|return
name|getGetElementPtr
argument_list|(
name|C
argument_list|,
name|Idx
argument_list|,
name|true
argument_list|)
return|;
block|}
specifier|static
name|Constant
operator|*
name|getInBoundsGetElementPtr
argument_list|(
argument|Constant *C
argument_list|,
argument|ArrayRef<Value *> IdxList
argument_list|)
block|{
return|return
name|getGetElementPtr
argument_list|(
name|C
argument_list|,
name|IdxList
argument_list|,
name|true
argument_list|)
return|;
block|}
specifier|static
name|Constant
operator|*
name|getExtractElement
argument_list|(
name|Constant
operator|*
name|Vec
argument_list|,
name|Constant
operator|*
name|Idx
argument_list|)
block|;
specifier|static
name|Constant
operator|*
name|getInsertElement
argument_list|(
name|Constant
operator|*
name|Vec
argument_list|,
name|Constant
operator|*
name|Elt
argument_list|,
name|Constant
operator|*
name|Idx
argument_list|)
block|;
specifier|static
name|Constant
operator|*
name|getShuffleVector
argument_list|(
name|Constant
operator|*
name|V1
argument_list|,
name|Constant
operator|*
name|V2
argument_list|,
name|Constant
operator|*
name|Mask
argument_list|)
block|;
specifier|static
name|Constant
operator|*
name|getExtractValue
argument_list|(
name|Constant
operator|*
name|Agg
argument_list|,
name|ArrayRef
operator|<
name|unsigned
operator|>
name|Idxs
argument_list|)
block|;
specifier|static
name|Constant
operator|*
name|getInsertValue
argument_list|(
name|Constant
operator|*
name|Agg
argument_list|,
name|Constant
operator|*
name|Val
argument_list|,
name|ArrayRef
operator|<
name|unsigned
operator|>
name|Idxs
argument_list|)
block|;
comment|/// getOpcode - Return the opcode at the root of this constant expression
name|unsigned
name|getOpcode
argument_list|()
specifier|const
block|{
return|return
name|getSubclassDataFromValue
argument_list|()
return|;
block|}
comment|/// getPredicate - Return the ICMP or FCMP predicate value. Assert if this is
comment|/// not an ICMP or FCMP constant expression.
name|unsigned
name|getPredicate
argument_list|()
specifier|const
block|;
comment|/// getIndices - Assert that this is an insertvalue or exactvalue
comment|/// expression and return the list of indices.
name|ArrayRef
operator|<
name|unsigned
operator|>
name|getIndices
argument_list|()
specifier|const
block|;
comment|/// getOpcodeName - Return a string representation for an opcode.
specifier|const
name|char
operator|*
name|getOpcodeName
argument_list|()
specifier|const
block|;
comment|/// getWithOperandReplaced - Return a constant expression identical to this
comment|/// one, but with the specified operand set to the specified value.
name|Constant
operator|*
name|getWithOperandReplaced
argument_list|(
argument|unsigned OpNo
argument_list|,
argument|Constant *Op
argument_list|)
specifier|const
block|;
comment|/// getWithOperands - This returns the current constant expression with the
comment|/// operands replaced with the specified values.  The specified array must
comment|/// have the same number of operands as our current one.
name|Constant
operator|*
name|getWithOperands
argument_list|(
argument|ArrayRef<Constant*> Ops
argument_list|)
specifier|const
block|{
return|return
name|getWithOperands
argument_list|(
name|Ops
argument_list|,
name|getType
argument_list|()
argument_list|)
return|;
block|}
comment|/// getWithOperands - This returns the current constant expression with the
comment|/// operands replaced with the specified values and with the specified result
comment|/// type.  The specified array must have the same number of operands as our
comment|/// current one.
name|Constant
operator|*
name|getWithOperands
argument_list|(
argument|ArrayRef<Constant*> Ops
argument_list|,
argument|Type *Ty
argument_list|)
specifier|const
block|;
comment|/// getAsInstruction - Returns an Instruction which implements the same operation
comment|/// as this ConstantExpr. The instruction is not linked to any basic block.
comment|///
comment|/// A better approach to this could be to have a constructor for Instruction
comment|/// which would take a ConstantExpr parameter, but that would have spread
comment|/// implementation details of ConstantExpr outside of Constants.cpp, which
comment|/// would make it harder to remove ConstantExprs altogether.
name|Instruction
operator|*
name|getAsInstruction
argument_list|()
block|;
name|virtual
name|void
name|destroyConstant
argument_list|()
block|;
name|virtual
name|void
name|replaceUsesOfWithOnConstant
argument_list|(
name|Value
operator|*
name|From
argument_list|,
name|Value
operator|*
name|To
argument_list|,
name|Use
operator|*
name|U
argument_list|)
block|;
comment|/// Methods for support type inquiry through isa, cast, and dyn_cast:
specifier|static
specifier|inline
name|bool
name|classof
argument_list|(
argument|const Value *V
argument_list|)
block|{
return|return
name|V
operator|->
name|getValueID
argument_list|()
operator|==
name|ConstantExprVal
return|;
block|}
name|private
operator|:
comment|// Shadow Value::setValueSubclassData with a private forwarding method so that
comment|// subclasses cannot accidentally use it.
name|void
name|setValueSubclassData
argument_list|(
argument|unsigned short D
argument_list|)
block|{
name|Value
operator|::
name|setValueSubclassData
argument_list|(
name|D
argument_list|)
block|;   }
expr|}
block|;
name|template
operator|<
operator|>
expr|struct
name|OperandTraits
operator|<
name|ConstantExpr
operator|>
operator|:
name|public
name|VariadicOperandTraits
operator|<
name|ConstantExpr
block|,
literal|1
operator|>
block|{ }
block|;
name|DEFINE_TRANSPARENT_OPERAND_ACCESSORS
argument_list|(
argument|ConstantExpr
argument_list|,
argument|Constant
argument_list|)
comment|//===----------------------------------------------------------------------===//
comment|/// UndefValue - 'undef' values are things that do not have specified contents.
comment|/// These are used for a variety of purposes, including global variable
comment|/// initializers and operands to instructions.  'undef' values can occur with
comment|/// any first-class type.
comment|///
comment|/// Undef values aren't exactly constants; if they have multiple uses, they
comment|/// can appear to have different bit patterns at each use. See
comment|/// LangRef.html#undefvalues for details.
comment|///
name|class
name|UndefValue
operator|:
name|public
name|Constant
block|{
name|void
operator|*
name|operator
name|new
argument_list|(
argument|size_t
argument_list|,
argument|unsigned
argument_list|)
name|LLVM_DELETED_FUNCTION
block|;
name|UndefValue
argument_list|(
argument|const UndefValue&
argument_list|)
name|LLVM_DELETED_FUNCTION
block|;
name|protected
operator|:
name|explicit
name|UndefValue
argument_list|(
name|Type
operator|*
name|T
argument_list|)
operator|:
name|Constant
argument_list|(
argument|T
argument_list|,
argument|UndefValueVal
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
block|{}
name|protected
operator|:
comment|// allocate space for exactly zero operands
name|void
operator|*
name|operator
name|new
argument_list|(
argument|size_t s
argument_list|)
block|{
return|return
name|User
operator|::
name|operator
name|new
argument_list|(
name|s
argument_list|,
literal|0
argument_list|)
return|;
block|}
name|public
operator|:
comment|/// get() - Static factory methods - Return an 'undef' object of the specified
comment|/// type.
comment|///
specifier|static
name|UndefValue
operator|*
name|get
argument_list|(
name|Type
operator|*
name|T
argument_list|)
block|;
comment|/// getSequentialElement - If this Undef has array or vector type, return a
comment|/// undef with the right element type.
name|UndefValue
operator|*
name|getSequentialElement
argument_list|()
specifier|const
block|;
comment|/// getStructElement - If this undef has struct type, return a undef with the
comment|/// right element type for the specified element.
name|UndefValue
operator|*
name|getStructElement
argument_list|(
argument|unsigned Elt
argument_list|)
specifier|const
block|;
comment|/// getElementValue - Return an undef of the right value for the specified GEP
comment|/// index.
name|UndefValue
operator|*
name|getElementValue
argument_list|(
argument|Constant *C
argument_list|)
specifier|const
block|;
comment|/// getElementValue - Return an undef of the right value for the specified GEP
comment|/// index.
name|UndefValue
operator|*
name|getElementValue
argument_list|(
argument|unsigned Idx
argument_list|)
specifier|const
block|;
name|virtual
name|void
name|destroyConstant
argument_list|()
block|;
comment|/// Methods for support type inquiry through isa, cast, and dyn_cast:
specifier|static
name|bool
name|classof
argument_list|(
argument|const Value *V
argument_list|)
block|{
return|return
name|V
operator|->
name|getValueID
argument_list|()
operator|==
name|UndefValueVal
return|;
block|}
expr|}
block|;  }
end_decl_stmt

begin_comment
comment|// End llvm namespace
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

