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
name|LLVM_CONSTANTS_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CONSTANTS_H
end_define

begin_include
include|#
directive|include
file|"llvm/Constant.h"
end_include

begin_include
include|#
directive|include
file|"llvm/OperandTraits.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/APInt.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/APFloat.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/SmallVector.h"
end_include

begin_include
include|#
directive|include
file|<vector>
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
name|void
operator|*
name|operator
name|new
argument_list|(
name|size_t
argument_list|,
name|unsigned
argument_list|)
block|;
comment|// DO NOT IMPLEMENT
name|ConstantInt
argument_list|(
specifier|const
name|ConstantInt
operator|&
argument_list|)
block|;
comment|// DO NOT IMPLEMENT
name|ConstantInt
argument_list|(
specifier|const
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
comment|/// If Ty is a vector type, return a Constant with a splat of the given
comment|/// value. Otherwise return a ConstantInt for the given value.
specifier|static
name|Constant
operator|*
name|get
argument_list|(
argument|const Type *Ty
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
argument|const IntegerType *Ty
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
argument|const IntegerType *Ty
argument_list|,
argument|int64_t V
argument_list|)
block|;
specifier|static
name|Constant
operator|*
name|getSigned
argument_list|(
argument|const Type *Ty
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
argument|const IntegerType *Ty
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
specifier|const
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
comment|/// @deprecated
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
comment|/// @deprecated
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
specifier|const
name|IntegerType
operator|*
name|getType
argument_list|()
specifier|const
block|{
return|return
name|reinterpret_cast
operator|<
specifier|const
name|IntegerType
operator|*
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
argument|const Type *Ty
argument_list|,
argument|uint64_t V
argument_list|)
block|;
specifier|static
name|bool
name|isValueValidForType
argument_list|(
argument|const Type *Ty
argument_list|,
argument|int64_t V
argument_list|)
block|;
comment|/// This function will return true iff this constant represents the "null"
comment|/// value that would be returned by the getNullValue method.
comment|/// @returns true if this is the null integer value.
comment|/// @brief Determine if the value is null.
name|virtual
name|bool
name|isNullValue
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
name|isAllOnesValue
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
specifier|inline
name|bool
name|classof
argument_list|(
argument|const ConstantInt *
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
name|void
operator|*
name|operator
name|new
argument_list|(
name|size_t
argument_list|,
name|unsigned
argument_list|)
block|;
comment|// DO NOT IMPLEMENT
name|ConstantFP
argument_list|(
specifier|const
name|ConstantFP
operator|&
argument_list|)
block|;
comment|// DO NOT IMPLEMENT
name|friend
name|class
name|LLVMContextImpl
block|;
name|protected
operator|:
name|ConstantFP
argument_list|(
specifier|const
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
specifier|const
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
argument|const Type* Ty
argument_list|,
argument|double V
argument_list|)
block|;
specifier|static
name|Constant
operator|*
name|get
argument_list|(
argument|const Type* Ty
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
specifier|const
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
argument|const Type *Ty
argument_list|,
argument|bool Negative = false
argument_list|)
block|;
comment|/// isValueValidForType - return true if Ty is big enough to represent V.
specifier|static
name|bool
name|isValueValidForType
argument_list|(
specifier|const
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
comment|/// isNullValue - Return true if this is the value that would be returned by
comment|/// getNullValue.  Don't depend on == for doubles to tell us it's zero, it
comment|/// considers -0.0 to be null as well as 0.0.  :(
name|virtual
name|bool
name|isNullValue
argument_list|()
specifier|const
block|;
comment|/// isNegativeZeroValue - Return true if the value is what would be returned
comment|/// by getZeroValueForNegation.
name|virtual
name|bool
name|isNegativeZeroValue
argument_list|()
specifier|const
block|{
return|return
name|Val
operator|.
name|isZero
argument_list|()
operator|&&
name|Val
operator|.
name|isNegative
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
comment|// convert is not supported on this type
if|if
condition|(
operator|&
name|Val
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
specifier|inline
name|bool
name|classof
argument_list|(
argument|const ConstantFP *
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
name|friend
expr|struct
name|ConstantCreator
operator|<
name|ConstantAggregateZero
block|,
name|Type
block|,
name|char
operator|>
block|;
name|void
operator|*
name|operator
name|new
argument_list|(
name|size_t
argument_list|,
name|unsigned
argument_list|)
block|;
comment|// DO NOT IMPLEMENT
name|ConstantAggregateZero
argument_list|(
specifier|const
name|ConstantAggregateZero
operator|&
argument_list|)
block|;
comment|// DO NOT IMPLEMENT
name|protected
operator|:
name|explicit
name|ConstantAggregateZero
argument_list|(
specifier|const
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
specifier|const
name|Type
operator|*
name|Ty
argument_list|)
block|;
comment|/// isNullValue - Return true if this is the value that would be returned by
comment|/// getNullValue.
name|virtual
name|bool
name|isNullValue
argument_list|()
specifier|const
block|{
return|return
name|true
return|;
block|}
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
argument|const ConstantAggregateZero *
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
name|ConstantCreator
operator|<
name|ConstantArray
block|,
name|ArrayType
block|,
name|std
operator|::
name|vector
operator|<
name|Constant
operator|*
operator|>
expr|>
block|;
name|ConstantArray
argument_list|(
specifier|const
name|ConstantArray
operator|&
argument_list|)
block|;
comment|// DO NOT IMPLEMENT
name|protected
operator|:
name|ConstantArray
argument_list|(
specifier|const
name|ArrayType
operator|*
name|T
argument_list|,
specifier|const
name|std
operator|::
name|vector
operator|<
name|Constant
operator|*
operator|>
operator|&
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
specifier|const
name|ArrayType
operator|*
name|T
argument_list|,
specifier|const
name|std
operator|::
name|vector
operator|<
name|Constant
operator|*
operator|>
operator|&
name|V
argument_list|)
block|;
specifier|static
name|Constant
operator|*
name|get
argument_list|(
argument|const ArrayType *T
argument_list|,
argument|Constant *const *Vals
argument_list|,
argument|unsigned NumVals
argument_list|)
block|;
comment|/// This method constructs a ConstantArray and initializes it with a text
comment|/// string. The default behavior (AddNull==true) causes a null terminator to
comment|/// be placed at the end of the array. This effectively increases the length
comment|/// of the array by one (you've been warned).  However, in some situations
comment|/// this is not desired so if AddNull==false then the string is copied without
comment|/// null termination.
specifier|static
name|Constant
operator|*
name|get
argument_list|(
argument|LLVMContext&Context
argument_list|,
argument|StringRef Initializer
argument_list|,
argument|bool AddNull = true
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
specifier|const
name|ArrayType
operator|*
name|getType
argument_list|()
specifier|const
block|{
return|return
name|reinterpret_cast
operator|<
specifier|const
name|ArrayType
operator|*
operator|>
operator|(
name|Value
operator|::
name|getType
argument_list|()
operator|)
return|;
block|}
comment|/// isString - This method returns true if the array is an array of i8 and
comment|/// the elements of the array are all ConstantInt's.
name|bool
name|isString
argument_list|()
specifier|const
block|;
comment|/// isCString - This method returns true if the array is a string (see
comment|/// @verbatim
comment|/// isString) and it ends in a null byte \0 and does not contains any other
comment|/// @endverbatim
comment|/// null bytes except its terminator.
name|bool
name|isCString
argument_list|()
specifier|const
block|;
comment|/// getAsString - If this array is isString(), then this method converts the
comment|/// array to an std::string and returns it.  Otherwise, it asserts out.
comment|///
name|std
operator|::
name|string
name|getAsString
argument_list|()
specifier|const
block|;
comment|/// isNullValue - Return true if this is the value that would be returned by
comment|/// getNullValue.  This always returns false because zero arrays are always
comment|/// created as ConstantAggregateZero objects.
name|virtual
name|bool
name|isNullValue
argument_list|()
specifier|const
block|{
return|return
name|false
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
argument|const ConstantArray *
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
operator|>
block|{ }
block|;
name|DEFINE_TRANSPARENT_CASTED_OPERAND_ACCESSORS
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
name|ConstantCreator
operator|<
name|ConstantStruct
block|,
name|StructType
block|,
name|std
operator|::
name|vector
operator|<
name|Constant
operator|*
operator|>
expr|>
block|;
name|ConstantStruct
argument_list|(
specifier|const
name|ConstantStruct
operator|&
argument_list|)
block|;
comment|// DO NOT IMPLEMENT
name|protected
operator|:
name|ConstantStruct
argument_list|(
specifier|const
name|StructType
operator|*
name|T
argument_list|,
specifier|const
name|std
operator|::
name|vector
operator|<
name|Constant
operator|*
operator|>
operator|&
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
specifier|const
name|StructType
operator|*
name|T
argument_list|,
specifier|const
name|std
operator|::
name|vector
operator|<
name|Constant
operator|*
operator|>
operator|&
name|V
argument_list|)
block|;
specifier|static
name|Constant
operator|*
name|get
argument_list|(
argument|LLVMContext&Context
argument_list|,
argument|const std::vector<Constant*>&V
argument_list|,
argument|bool Packed
argument_list|)
block|;
specifier|static
name|Constant
operator|*
name|get
argument_list|(
argument|LLVMContext&Context
argument_list|,
argument|Constant *const *Vals
argument_list|,
argument|unsigned NumVals
argument_list|,
argument|bool Packed
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
specifier|const
name|StructType
operator|*
name|getType
argument_list|()
specifier|const
block|{
return|return
name|reinterpret_cast
operator|<
specifier|const
name|StructType
operator|*
operator|>
operator|(
name|Value
operator|::
name|getType
argument_list|()
operator|)
return|;
block|}
comment|/// isNullValue - Return true if this is the value that would be returned by
comment|/// getNullValue.  This always returns false because zero structs are always
comment|/// created as ConstantAggregateZero objects.
name|virtual
name|bool
name|isNullValue
argument_list|()
specifier|const
block|{
return|return
name|false
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
argument|const ConstantStruct *
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
operator|>
block|{ }
block|;
name|DEFINE_TRANSPARENT_CASTED_OPERAND_ACCESSORS
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
name|ConstantCreator
operator|<
name|ConstantVector
block|,
name|VectorType
block|,
name|std
operator|::
name|vector
operator|<
name|Constant
operator|*
operator|>
expr|>
block|;
name|ConstantVector
argument_list|(
specifier|const
name|ConstantVector
operator|&
argument_list|)
block|;
comment|// DO NOT IMPLEMENT
name|protected
operator|:
name|ConstantVector
argument_list|(
specifier|const
name|VectorType
operator|*
name|T
argument_list|,
specifier|const
name|std
operator|::
name|vector
operator|<
name|Constant
operator|*
operator|>
operator|&
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
specifier|const
name|VectorType
operator|*
name|T
argument_list|,
specifier|const
name|std
operator|::
name|vector
operator|<
name|Constant
operator|*
operator|>
operator|&
name|V
argument_list|)
block|;
specifier|static
name|Constant
operator|*
name|get
argument_list|(
specifier|const
name|std
operator|::
name|vector
operator|<
name|Constant
operator|*
operator|>
operator|&
name|V
argument_list|)
block|;
specifier|static
name|Constant
operator|*
name|get
argument_list|(
argument|Constant *const *Vals
argument_list|,
argument|unsigned NumVals
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
specifier|const
name|VectorType
operator|*
name|getType
argument_list|()
specifier|const
block|{
return|return
name|reinterpret_cast
operator|<
specifier|const
name|VectorType
operator|*
operator|>
operator|(
name|Value
operator|::
name|getType
argument_list|()
operator|)
return|;
block|}
comment|/// isNullValue - Return true if this is the value that would be returned by
comment|/// getNullValue.  This always returns false because zero vectors are always
comment|/// created as ConstantAggregateZero objects.
name|virtual
name|bool
name|isNullValue
argument_list|()
specifier|const
block|{
return|return
name|false
return|;
block|}
comment|/// This function will return true iff every element in this vector constant
comment|/// is set to all ones.
comment|/// @returns true iff this constant's emements are all set to all ones.
comment|/// @brief Determine if the value is all ones.
name|bool
name|isAllOnesValue
argument_list|()
specifier|const
block|;
comment|/// getSplatValue - If this is a splat constant, meaning that all of the
comment|/// elements have the same value, return that value. Otherwise return NULL.
name|Constant
operator|*
name|getSplatValue
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
argument|const ConstantVector *
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
operator|>
block|{ }
block|;
name|DEFINE_TRANSPARENT_CASTED_OPERAND_ACCESSORS
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
name|friend
expr|struct
name|ConstantCreator
operator|<
name|ConstantPointerNull
block|,
name|PointerType
block|,
name|char
operator|>
block|;
name|void
operator|*
name|operator
name|new
argument_list|(
name|size_t
argument_list|,
name|unsigned
argument_list|)
block|;
comment|// DO NOT IMPLEMENT
name|ConstantPointerNull
argument_list|(
specifier|const
name|ConstantPointerNull
operator|&
argument_list|)
block|;
comment|// DO NOT IMPLEMENT
name|protected
operator|:
name|explicit
name|ConstantPointerNull
argument_list|(
specifier|const
name|PointerType
operator|*
name|T
argument_list|)
operator|:
name|Constant
argument_list|(
argument|reinterpret_cast<const Type*>(T)
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
specifier|const
name|PointerType
operator|*
name|T
argument_list|)
block|;
comment|/// isNullValue - Return true if this is the value that would be returned by
comment|/// getNullValue.
name|virtual
name|bool
name|isNullValue
argument_list|()
specifier|const
block|{
return|return
name|true
return|;
block|}
name|virtual
name|void
name|destroyConstant
argument_list|()
block|;
comment|/// getType - Specialize the getType() method to always return an PointerType,
comment|/// which reduces the amount of casting needed in parts of the compiler.
comment|///
specifier|inline
specifier|const
name|PointerType
operator|*
name|getType
argument_list|()
specifier|const
block|{
return|return
name|reinterpret_cast
operator|<
specifier|const
name|PointerType
operator|*
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
specifier|inline
name|bool
name|classof
argument_list|(
argument|const ConstantPointerNull *
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
name|size_t
argument_list|,
name|unsigned
argument_list|)
block|;
comment|// DO NOT IMPLEMENT
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
comment|/// isNullValue - Return true if this is the value that would be returned by
comment|/// getNullValue.
name|virtual
name|bool
name|isNullValue
argument_list|()
specifier|const
block|{
return|return
name|false
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
argument|const BlockAddress *
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
literal|2
operator|>
block|{ }
block|;
name|DEFINE_TRANSPARENT_CASTED_OPERAND_ACCESSORS
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
argument|const Type *ty
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
comment|// These private methods are used by the type resolution code to create
comment|// ConstantExprs in intermediate forms.
specifier|static
name|Constant
operator|*
name|getTy
argument_list|(
argument|const Type *Ty
argument_list|,
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
specifier|static
name|Constant
operator|*
name|getCompareTy
argument_list|(
argument|unsigned short pred
argument_list|,
argument|Constant *C1
argument_list|,
argument|Constant *C2
argument_list|)
block|;
specifier|static
name|Constant
operator|*
name|getSelectTy
argument_list|(
specifier|const
name|Type
operator|*
name|Ty
argument_list|,
name|Constant
operator|*
name|C1
argument_list|,
name|Constant
operator|*
name|C2
argument_list|,
name|Constant
operator|*
name|C3
argument_list|)
block|;
specifier|static
name|Constant
operator|*
name|getGetElementPtrTy
argument_list|(
argument|const Type *Ty
argument_list|,
argument|Constant *C
argument_list|,
argument|Value* const *Idxs
argument_list|,
argument|unsigned NumIdxs
argument_list|)
block|;
specifier|static
name|Constant
operator|*
name|getInBoundsGetElementPtrTy
argument_list|(
argument|const Type *Ty
argument_list|,
argument|Constant *C
argument_list|,
argument|Value* const *Idxs
argument_list|,
argument|unsigned NumIdxs
argument_list|)
block|;
specifier|static
name|Constant
operator|*
name|getExtractElementTy
argument_list|(
specifier|const
name|Type
operator|*
name|Ty
argument_list|,
name|Constant
operator|*
name|Val
argument_list|,
name|Constant
operator|*
name|Idx
argument_list|)
block|;
specifier|static
name|Constant
operator|*
name|getInsertElementTy
argument_list|(
specifier|const
name|Type
operator|*
name|Ty
argument_list|,
name|Constant
operator|*
name|Val
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
name|getShuffleVectorTy
argument_list|(
specifier|const
name|Type
operator|*
name|Ty
argument_list|,
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
name|getExtractValueTy
argument_list|(
argument|const Type *Ty
argument_list|,
argument|Constant *Agg
argument_list|,
argument|const unsigned *Idxs
argument_list|,
argument|unsigned NumIdxs
argument_list|)
block|;
specifier|static
name|Constant
operator|*
name|getInsertValueTy
argument_list|(
argument|const Type *Ty
argument_list|,
argument|Constant *Agg
argument_list|,
argument|Constant *Val
argument_list|,
argument|const unsigned *Idxs
argument_list|,
argument|unsigned NumIdxs
argument_list|)
block|;
name|public
operator|:
comment|// Static methods to construct a ConstantExpr of different kinds.  Note that
comment|// these methods may return a object that is not an instance of the
comment|// ConstantExpr class, because they will attempt to fold the constant
comment|// expression into something simpler if possible.
comment|/// Cast constant expr
comment|///
comment|/// getAlignOf constant expr - computes the alignment of a type in a target
comment|/// independent way (Note: the return type is an i32; Note: assumes that i8
comment|/// is byte aligned).
specifier|static
name|Constant
operator|*
name|getAlignOf
argument_list|(
specifier|const
name|Type
operator|*
name|Ty
argument_list|)
block|;
comment|/// getSizeOf constant expr - computes the size of a type in a target
comment|/// independent way (Note: the return type is an i64).
comment|///
specifier|static
name|Constant
operator|*
name|getSizeOf
argument_list|(
specifier|const
name|Type
operator|*
name|Ty
argument_list|)
block|;
comment|/// getOffsetOf constant expr - computes the offset of a field in a target
comment|/// independent way (Note: the return type is an i64).
comment|///
specifier|static
name|Constant
operator|*
name|getOffsetOf
argument_list|(
argument|const StructType* Ty
argument_list|,
argument|unsigned FieldNo
argument_list|)
block|;
specifier|static
name|Constant
operator|*
name|getNeg
argument_list|(
name|Constant
operator|*
name|C
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
name|getSDiv
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
name|getLShr
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
name|getAShr
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
name|getTrunc
argument_list|(
name|Constant
operator|*
name|C
argument_list|,
specifier|const
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
specifier|const
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
specifier|const
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
specifier|const
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
specifier|const
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
specifier|const
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
specifier|const
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
specifier|const
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
specifier|const
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
specifier|const
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
specifier|const
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
specifier|const
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
name|Constant
operator|*
name|C
argument_list|)
block|;
specifier|static
name|Constant
operator|*
name|getNSWAdd
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
name|getNSWSub
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
name|getNSWMul
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
name|getExactSDiv
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
argument|const Type *Ty
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
specifier|const
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
specifier|const
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
specifier|const
name|Type
operator|*
name|Ty
comment|///< The type to trunc or bitcast C to
argument_list|)
block|;
comment|/// @brief Create a BitCast or a PtrToInt cast constant expression
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
specifier|const
name|Type
operator|*
name|Ty
comment|///< The type to which cast should be made
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
argument|const Type *Ty
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
specifier|const
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
argument|Constant *C
argument_list|,
argument|Constant *V1
argument_list|,
argument|Constant *V2
argument_list|)
block|{
return|return
name|getSelectTy
argument_list|(
name|V1
operator|->
name|getType
argument_list|()
argument_list|,
name|C
argument_list|,
name|V1
argument_list|,
name|V2
argument_list|)
return|;
block|}
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
comment|/// Getelementptr form.  std::vector<Value*> is only accepted for convenience:
comment|/// all elements must be Constant's.
comment|///
specifier|static
name|Constant
operator|*
name|getGetElementPtr
argument_list|(
argument|Constant *C
argument_list|,
argument|Constant *const *IdxList
argument_list|,
argument|unsigned NumIdx
argument_list|)
block|;
specifier|static
name|Constant
operator|*
name|getGetElementPtr
argument_list|(
argument|Constant *C
argument_list|,
argument|Value* const *IdxList
argument_list|,
argument|unsigned NumIdx
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
argument|Constant *const *IdxList
argument_list|,
argument|unsigned NumIdx
argument_list|)
block|;
specifier|static
name|Constant
operator|*
name|getInBoundsGetElementPtr
argument_list|(
argument|Constant *C
argument_list|,
argument|Value* const *IdxList
argument_list|,
argument|unsigned NumIdx
argument_list|)
block|;
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
argument|Constant *Agg
argument_list|,
argument|const unsigned *IdxList
argument_list|,
argument|unsigned NumIdx
argument_list|)
block|;
specifier|static
name|Constant
operator|*
name|getInsertValue
argument_list|(
argument|Constant *Agg
argument_list|,
argument|Constant *Val
argument_list|,
argument|const unsigned *IdxList
argument_list|,
argument|unsigned NumIdx
argument_list|)
block|;
comment|/// isNullValue - Return true if this is the value that would be returned by
comment|/// getNullValue.
name|virtual
name|bool
name|isNullValue
argument_list|()
specifier|const
block|{
return|return
name|false
return|;
block|}
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
specifier|const
name|SmallVector
operator|<
name|unsigned
block|,
literal|4
operator|>
operator|&
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
comment|/// operands replaced with the specified values.  The specified operands must
comment|/// match count and type with the existing ones.
name|Constant
operator|*
name|getWithOperands
argument_list|(
argument|const std::vector<Constant*>&Ops
argument_list|)
specifier|const
block|{
return|return
name|getWithOperands
argument_list|(
operator|&
name|Ops
index|[
literal|0
index|]
argument_list|,
operator|(
name|unsigned
operator|)
name|Ops
operator|.
name|size
argument_list|()
argument_list|)
return|;
block|}
name|Constant
operator|*
name|getWithOperands
argument_list|(
argument|Constant *const *Ops
argument_list|,
argument|unsigned NumOps
argument_list|)
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
specifier|inline
name|bool
name|classof
argument_list|(
argument|const ConstantExpr *
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
literal|1
operator|>
block|{ }
block|;
name|DEFINE_TRANSPARENT_CASTED_OPERAND_ACCESSORS
argument_list|(
argument|ConstantExpr
argument_list|,
argument|Constant
argument_list|)
comment|//===----------------------------------------------------------------------===//
comment|/// UndefValue - 'undef' values are things that do not have specified contents.
comment|/// These are used for a variety of purposes, including global variable
comment|/// initializers and operands to instructions.  'undef' values can occur with
comment|/// any type.
comment|///
name|class
name|UndefValue
operator|:
name|public
name|Constant
block|{
name|friend
expr|struct
name|ConstantCreator
operator|<
name|UndefValue
block|,
name|Type
block|,
name|char
operator|>
block|;
name|void
operator|*
name|operator
name|new
argument_list|(
name|size_t
argument_list|,
name|unsigned
argument_list|)
block|;
comment|// DO NOT IMPLEMENT
name|UndefValue
argument_list|(
specifier|const
name|UndefValue
operator|&
argument_list|)
block|;
comment|// DO NOT IMPLEMENT
name|protected
operator|:
name|explicit
name|UndefValue
argument_list|(
specifier|const
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
specifier|const
name|Type
operator|*
name|T
argument_list|)
block|;
comment|/// isNullValue - Return true if this is the value that would be returned by
comment|/// getNullValue.
name|virtual
name|bool
name|isNullValue
argument_list|()
specifier|const
block|{
return|return
name|false
return|;
block|}
name|virtual
name|void
name|destroyConstant
argument_list|()
block|;
comment|/// Methods for support type inquiry through isa, cast, and dyn_cast:
specifier|static
specifier|inline
name|bool
name|classof
argument_list|(
argument|const UndefValue *
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
block|; }
end_decl_stmt

begin_comment
comment|// End llvm namespace
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

