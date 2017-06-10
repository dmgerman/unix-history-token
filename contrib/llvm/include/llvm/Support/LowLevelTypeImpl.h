begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//== llvm/Support/LowLevelTypeImpl.h --------------------------- -*- C++ -*-==//
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
comment|/// Implement a low-level type suitable for MachineInstr level instruction
end_comment

begin_comment
comment|/// selection.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// For a type attached to a MachineInstr, we only care about 2 details: total
end_comment

begin_comment
comment|/// size and the number of vector lanes (if any). Accordingly, there are 4
end_comment

begin_comment
comment|/// possible valid type-kinds:
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|///    * `sN` for scalars and aggregates
end_comment

begin_comment
comment|///    * `<N x sM>` for vectors, which must have at least 2 elements.
end_comment

begin_comment
comment|///    * `pN` for pointers
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Other information required for correct selection is expected to be carried
end_comment

begin_comment
comment|/// by the opcode, or non-type flags. For example the distinction between G_ADD
end_comment

begin_comment
comment|/// and G_FADD for int/float or fast-math flags.
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
name|LLVM_SUPPORT_LOWLEVELTYPEIMPL_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_SUPPORT_LOWLEVELTYPEIMPL_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/DenseMapInfo.h"
end_include

begin_include
include|#
directive|include
file|"llvm/CodeGen/MachineValueType.h"
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
name|DataLayout
decl_stmt|;
name|class
name|Type
decl_stmt|;
name|class
name|raw_ostream
decl_stmt|;
name|class
name|LLT
block|{
name|public
label|:
comment|/// Get a low-level scalar or aggregate "bag of bits".
specifier|static
name|LLT
name|scalar
parameter_list|(
name|unsigned
name|SizeInBits
parameter_list|)
block|{
name|assert
argument_list|(
name|SizeInBits
operator|>
literal|0
operator|&&
literal|"invalid scalar size"
argument_list|)
expr_stmt|;
return|return
name|LLT
block|{
comment|/*isPointer=*/
name|false
block|,
comment|/*isVector=*/
name|false
block|,
comment|/*NumElements=*/
literal|0
block|,
name|SizeInBits
block|,
comment|/*AddressSpace=*/
literal|0
block|}
return|;
block|}
comment|/// Get a low-level pointer in the given address space (defaulting to 0).
specifier|static
name|LLT
name|pointer
parameter_list|(
name|uint16_t
name|AddressSpace
parameter_list|,
name|unsigned
name|SizeInBits
parameter_list|)
block|{
name|assert
argument_list|(
name|SizeInBits
operator|>
literal|0
operator|&&
literal|"invalid pointer size"
argument_list|)
expr_stmt|;
return|return
name|LLT
block|{
comment|/*isPointer=*/
name|true
block|,
comment|/*isVector=*/
name|false
block|,
comment|/*NumElements=*/
literal|0
block|,
name|SizeInBits
block|,
name|AddressSpace
block|}
return|;
block|}
comment|/// Get a low-level vector of some number of elements and element width.
comment|/// \p NumElements must be at least 2.
specifier|static
name|LLT
name|vector
parameter_list|(
name|uint16_t
name|NumElements
parameter_list|,
name|unsigned
name|ScalarSizeInBits
parameter_list|)
block|{
name|assert
argument_list|(
name|NumElements
operator|>
literal|1
operator|&&
literal|"invalid number of vector elements"
argument_list|)
expr_stmt|;
name|assert
argument_list|(
name|ScalarSizeInBits
operator|>
literal|0
operator|&&
literal|"invalid vector element size"
argument_list|)
expr_stmt|;
return|return
name|LLT
block|{
comment|/*isPointer=*/
name|false
block|,
comment|/*isVector=*/
name|true
block|,
name|NumElements
block|,
name|ScalarSizeInBits
block|,
comment|/*AddressSpace=*/
literal|0
block|}
return|;
block|}
comment|/// Get a low-level vector of some number of elements and element type.
specifier|static
name|LLT
name|vector
parameter_list|(
name|uint16_t
name|NumElements
parameter_list|,
name|LLT
name|ScalarTy
parameter_list|)
block|{
name|assert
argument_list|(
name|NumElements
operator|>
literal|1
operator|&&
literal|"invalid number of vector elements"
argument_list|)
expr_stmt|;
name|assert
argument_list|(
operator|!
name|ScalarTy
operator|.
name|isVector
argument_list|()
operator|&&
literal|"invalid vector element type"
argument_list|)
expr_stmt|;
return|return
name|LLT
block|{
name|ScalarTy
operator|.
name|isPointer
argument_list|()
block|,
comment|/*isVector=*/
name|true
block|,
name|NumElements
block|,
name|ScalarTy
operator|.
name|getSizeInBits
argument_list|()
block|,
name|ScalarTy
operator|.
name|isPointer
argument_list|()
operator|?
name|ScalarTy
operator|.
name|getAddressSpace
argument_list|()
operator|:
literal|0
block|}
return|;
block|}
name|explicit
name|LLT
parameter_list|(
name|bool
name|isPointer
parameter_list|,
name|bool
name|isVector
parameter_list|,
name|uint16_t
name|NumElements
parameter_list|,
name|unsigned
name|SizeInBits
parameter_list|,
name|unsigned
name|AddressSpace
parameter_list|)
block|{
name|init
argument_list|(
name|isPointer
argument_list|,
name|isVector
argument_list|,
name|NumElements
argument_list|,
name|SizeInBits
argument_list|,
name|AddressSpace
argument_list|)
expr_stmt|;
block|}
name|explicit
name|LLT
argument_list|()
operator|:
name|IsPointer
argument_list|(
name|false
argument_list|)
operator|,
name|IsVector
argument_list|(
name|false
argument_list|)
operator|,
name|RawData
argument_list|(
literal|0
argument_list|)
block|{}
name|explicit
name|LLT
argument_list|(
argument|MVT VT
argument_list|)
expr_stmt|;
name|bool
name|isValid
argument_list|()
specifier|const
block|{
return|return
name|RawData
operator|!=
literal|0
return|;
block|}
name|bool
name|isScalar
argument_list|()
specifier|const
block|{
return|return
name|isValid
argument_list|()
operator|&&
operator|!
name|IsPointer
operator|&&
operator|!
name|IsVector
return|;
block|}
name|bool
name|isPointer
argument_list|()
specifier|const
block|{
return|return
name|isValid
argument_list|()
operator|&&
name|IsPointer
operator|&&
operator|!
name|IsVector
return|;
block|}
name|bool
name|isVector
argument_list|()
specifier|const
block|{
return|return
name|isValid
argument_list|()
operator|&&
name|IsVector
return|;
block|}
comment|/// Returns the number of elements in a vector LLT. Must only be called on
comment|/// vector types.
name|uint16_t
name|getNumElements
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
name|IsVector
operator|&&
literal|"cannot get number of elements on scalar/aggregate"
argument_list|)
block|;
if|if
condition|(
operator|!
name|IsPointer
condition|)
return|return
name|getFieldValue
argument_list|(
name|VectorElementsFieldInfo
argument_list|)
return|;
else|else
return|return
name|getFieldValue
argument_list|(
name|PointerVectorElementsFieldInfo
argument_list|)
return|;
block|}
comment|/// Returns the total size of the type. Must only be called on sized types.
name|unsigned
name|getSizeInBits
argument_list|()
specifier|const
block|{
if|if
condition|(
name|isPointer
argument_list|()
operator|||
name|isScalar
argument_list|()
condition|)
return|return
name|getScalarSizeInBits
argument_list|()
return|;
return|return
name|getScalarSizeInBits
argument_list|()
operator|*
name|getNumElements
argument_list|()
return|;
block|}
name|unsigned
name|getScalarSizeInBits
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
name|RawData
operator|!=
literal|0
operator|&&
literal|"Invalid Type"
argument_list|)
block|;
if|if
condition|(
operator|!
name|IsVector
condition|)
block|{
if|if
condition|(
operator|!
name|IsPointer
condition|)
return|return
name|getFieldValue
argument_list|(
name|ScalarSizeFieldInfo
argument_list|)
return|;
else|else
return|return
name|getFieldValue
argument_list|(
name|PointerSizeFieldInfo
argument_list|)
return|;
block|}
else|else
block|{
if|if
condition|(
operator|!
name|IsPointer
condition|)
return|return
name|getFieldValue
argument_list|(
name|VectorSizeFieldInfo
argument_list|)
return|;
else|else
return|return
name|getFieldValue
argument_list|(
name|PointerVectorSizeFieldInfo
argument_list|)
return|;
block|}
block|}
name|unsigned
name|getAddressSpace
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
name|RawData
operator|!=
literal|0
operator|&&
literal|"Invalid Type"
argument_list|)
block|;
name|assert
argument_list|(
name|IsPointer
operator|&&
literal|"cannot get address space of non-pointer type"
argument_list|)
block|;
if|if
condition|(
operator|!
name|IsVector
condition|)
return|return
name|getFieldValue
argument_list|(
name|PointerAddressSpaceFieldInfo
argument_list|)
return|;
else|else
return|return
name|getFieldValue
argument_list|(
name|PointerVectorAddressSpaceFieldInfo
argument_list|)
return|;
block|}
comment|/// Returns the vector's element type. Only valid for vector types.
name|LLT
name|getElementType
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
name|isVector
argument_list|()
operator|&&
literal|"cannot get element type of scalar/aggregate"
argument_list|)
block|;
if|if
condition|(
name|IsPointer
condition|)
return|return
name|pointer
argument_list|(
name|getAddressSpace
argument_list|()
argument_list|,
name|getScalarSizeInBits
argument_list|()
argument_list|)
return|;
else|else
return|return
name|scalar
argument_list|(
name|getScalarSizeInBits
argument_list|()
argument_list|)
return|;
block|}
comment|/// Get a low-level type with half the size of the original, by halving the
comment|/// size of the scalar type involved. For example `s32` will become `s16`,
comment|/// `<2 x s32>` will become `<2 x s16>`.
name|LLT
name|halfScalarSize
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
operator|!
name|IsPointer
operator|&&
name|getScalarSizeInBits
argument_list|()
operator|>
literal|1
operator|&&
name|getScalarSizeInBits
argument_list|()
operator|%
literal|2
operator|==
literal|0
operator|&&
literal|"cannot half size of this type"
argument_list|)
block|;
return|return
name|LLT
block|{
comment|/*isPointer=*/
name|false
block|,
name|IsVector
operator|?
name|true
operator|:
name|false
block|,
name|IsVector
operator|?
name|getNumElements
argument_list|()
operator|:
operator|(
name|uint16_t
operator|)
literal|0
block|,
name|getScalarSizeInBits
argument_list|()
operator|/
literal|2
block|,
comment|/*AddressSpace=*/
literal|0
block|}
return|;
block|}
comment|/// Get a low-level type with twice the size of the original, by doubling the
comment|/// size of the scalar type involved. For example `s32` will become `s64`,
comment|/// `<2 x s32>` will become `<2 x s64>`.
name|LLT
name|doubleScalarSize
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
operator|!
name|IsPointer
operator|&&
literal|"cannot change size of this type"
argument_list|)
block|;
return|return
name|LLT
block|{
comment|/*isPointer=*/
name|false
block|,
name|IsVector
operator|?
name|true
operator|:
name|false
block|,
name|IsVector
operator|?
name|getNumElements
argument_list|()
operator|:
operator|(
name|uint16_t
operator|)
literal|0
block|,
name|getScalarSizeInBits
argument_list|()
operator|*
literal|2
block|,
comment|/*AddressSpace=*/
literal|0
block|}
return|;
block|}
comment|/// Get a low-level type with half the size of the original, by halving the
comment|/// number of vector elements of the scalar type involved. The source must be
comment|/// a vector type with an even number of elements. For example `<4 x s32>`
comment|/// will become `<2 x s32>`, `<2 x s32>` will become `s32`.
name|LLT
name|halfElements
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
name|isVector
argument_list|()
operator|&&
name|getNumElements
argument_list|()
operator|%
literal|2
operator|==
literal|0
operator|&&
literal|"cannot half odd vector"
argument_list|)
block|;
if|if
condition|(
name|getNumElements
argument_list|()
operator|==
literal|2
condition|)
return|return
name|scalar
argument_list|(
name|getScalarSizeInBits
argument_list|()
argument_list|)
return|;
return|return
name|LLT
block|{
comment|/*isPointer=*/
name|false
block|,
comment|/*isVector=*/
name|true
block|,
call|(
name|uint16_t
call|)
argument_list|(
name|getNumElements
argument_list|()
operator|/
literal|2
argument_list|)
block|,
name|getScalarSizeInBits
argument_list|()
block|,
comment|/*AddressSpace=*/
literal|0
block|}
return|;
block|}
end_decl_stmt

begin_comment
comment|/// Get a low-level type with twice the size of the original, by doubling the
end_comment

begin_comment
comment|/// number of vector elements of the scalar type involved. The source must be
end_comment

begin_comment
comment|/// a vector type. For example `<2 x s32>` will become `<4 x s32>`. Doubling
end_comment

begin_comment
comment|/// the number of elements in sN produces<2 x sN>.
end_comment

begin_expr_stmt
name|LLT
name|doubleElements
argument_list|()
specifier|const
block|{
return|return
name|LLT
block|{
name|IsPointer
operator|?
name|true
operator|:
name|false
block|,
comment|/*isVector=*/
name|true
block|,
call|(
name|uint16_t
call|)
argument_list|(
name|getNumElements
argument_list|()
operator|*
literal|2
argument_list|)
block|,
name|getScalarSizeInBits
argument_list|()
block|,
name|IsPointer
operator|?
name|getAddressSpace
argument_list|()
operator|:
literal|0
block|}
return|;
block|}
end_expr_stmt

begin_decl_stmt
name|void
name|print
argument_list|(
name|raw_ostream
operator|&
name|OS
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|bool
name|operator
operator|==
operator|(
specifier|const
name|LLT
operator|&
name|RHS
operator|)
specifier|const
block|{
return|return
name|IsPointer
operator|==
name|RHS
operator|.
name|IsPointer
operator|&&
name|IsVector
operator|==
name|RHS
operator|.
name|IsVector
operator|&&
name|RHS
operator|.
name|RawData
operator|==
name|RawData
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|bool
name|operator
operator|!=
operator|(
specifier|const
name|LLT
operator|&
name|RHS
operator|)
specifier|const
block|{
return|return
operator|!
operator|(
operator|*
name|this
operator|==
name|RHS
operator|)
return|;
block|}
end_expr_stmt

begin_macro
name|friend
end_macro

begin_expr_stmt
unit|struct
name|DenseMapInfo
operator|<
name|LLT
operator|>
expr_stmt|;
end_expr_stmt

begin_label
name|private
label|:
end_label

begin_comment
comment|/// LLT is packed into 64 bits as follows:
end_comment

begin_comment
comment|/// isPointer : 1
end_comment

begin_comment
comment|/// isVector  : 1
end_comment

begin_comment
comment|/// with 62 bits remaining for Kind-specific data, packed in bitfields
end_comment

begin_comment
comment|/// as described below. As there isn't a simple portable way to pack bits
end_comment

begin_comment
comment|/// into bitfields, here the different fields in the packed structure is
end_comment

begin_comment
comment|/// described in static const *Field variables. Each of these variables
end_comment

begin_comment
comment|/// is a 2-element array, with the first element describing the bitfield size
end_comment

begin_comment
comment|/// and the second element describing the bitfield offset.
end_comment

begin_typedef
typedef|typedef
name|int
name|BitFieldInfo
index|[
literal|2
index|]
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// This is how the bitfields are packed per Kind:
end_comment

begin_comment
comment|/// * Invalid:
end_comment

begin_comment
comment|///   gets encoded as RawData == 0, as that is an invalid encoding, since for
end_comment

begin_comment
comment|///   valid encodings, SizeInBits/SizeOfElement must be larger than 0.
end_comment

begin_comment
comment|/// * Non-pointer scalar (isPointer == 0&& isVector == 0):
end_comment

begin_comment
comment|///   SizeInBits: 32;
end_comment

begin_decl_stmt
specifier|static
specifier|const
name|constexpr
name|BitFieldInfo
name|ScalarSizeFieldInfo
block|{
literal|32
operator|,
literal|0
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|/// * Pointer (isPointer == 1&& isVector == 0):
end_comment

begin_comment
comment|///   SizeInBits: 16;
end_comment

begin_comment
comment|///   AddressSpace: 23;
end_comment

begin_decl_stmt
specifier|static
specifier|const
name|constexpr
name|BitFieldInfo
name|PointerSizeFieldInfo
block|{
literal|16
operator|,
literal|0
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_decl_stmt
specifier|static
specifier|const
name|constexpr
name|BitFieldInfo
name|PointerAddressSpaceFieldInfo
block|{
literal|23
operator|,
name|PointerSizeFieldInfo
index|[
literal|0
index|]
operator|+
name|PointerSizeFieldInfo
index|[
literal|1
index|]
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|/// * Vector-of-non-pointer (isPointer == 0&& isVector == 1):
end_comment

begin_comment
comment|///   NumElements: 16;
end_comment

begin_comment
comment|///   SizeOfElement: 32;
end_comment

begin_decl_stmt
specifier|static
specifier|const
name|constexpr
name|BitFieldInfo
name|VectorElementsFieldInfo
block|{
literal|16
operator|,
literal|0
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_decl_stmt
specifier|static
specifier|const
name|constexpr
name|BitFieldInfo
name|VectorSizeFieldInfo
block|{
literal|32
operator|,
name|VectorElementsFieldInfo
index|[
literal|0
index|]
operator|+
name|VectorElementsFieldInfo
index|[
literal|1
index|]
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|/// * Vector-of-pointer (isPointer == 1&& isVector == 1):
end_comment

begin_comment
comment|///   NumElements: 16;
end_comment

begin_comment
comment|///   SizeOfElement: 16;
end_comment

begin_comment
comment|///   AddressSpace: 23;
end_comment

begin_decl_stmt
specifier|static
specifier|const
name|constexpr
name|BitFieldInfo
name|PointerVectorElementsFieldInfo
block|{
literal|16
operator|,
literal|0
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_decl_stmt
specifier|static
specifier|const
name|constexpr
name|BitFieldInfo
name|PointerVectorSizeFieldInfo
block|{
literal|16
operator|,
name|PointerVectorElementsFieldInfo
index|[
literal|1
index|]
operator|+
name|PointerVectorElementsFieldInfo
index|[
literal|0
index|]
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_decl_stmt
specifier|static
specifier|const
name|constexpr
name|BitFieldInfo
name|PointerVectorAddressSpaceFieldInfo
block|{
literal|23
operator|,
name|PointerVectorSizeFieldInfo
index|[
literal|1
index|]
operator|+
name|PointerVectorSizeFieldInfo
index|[
literal|0
index|]
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_decl_stmt
name|uint64_t
name|IsPointer
range|:
literal|1
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|uint64_t
name|IsVector
range|:
literal|1
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|uint64_t
name|RawData
range|:
literal|62
decl_stmt|;
end_decl_stmt

begin_function
specifier|static
name|uint64_t
name|getMask
parameter_list|(
specifier|const
name|BitFieldInfo
name|FieldInfo
parameter_list|)
block|{
specifier|const
name|int
name|FieldSizeInBits
init|=
name|FieldInfo
index|[
literal|0
index|]
decl_stmt|;
return|return
operator|(
operator|(
operator|(
name|uint64_t
operator|)
literal|1
operator|)
operator|<<
name|FieldSizeInBits
operator|)
operator|-
literal|1
return|;
block|}
end_function

begin_function
specifier|static
name|uint64_t
name|maskAndShift
parameter_list|(
name|uint64_t
name|Val
parameter_list|,
name|uint64_t
name|Mask
parameter_list|,
name|uint8_t
name|Shift
parameter_list|)
block|{
name|assert
argument_list|(
name|Val
operator|<=
name|Mask
operator|&&
literal|"Value too large for field"
argument_list|)
expr_stmt|;
return|return
operator|(
name|Val
operator|&
name|Mask
operator|)
operator|<<
name|Shift
return|;
block|}
end_function

begin_function
specifier|static
name|uint64_t
name|maskAndShift
parameter_list|(
name|uint64_t
name|Val
parameter_list|,
specifier|const
name|BitFieldInfo
name|FieldInfo
parameter_list|)
block|{
return|return
name|maskAndShift
argument_list|(
name|Val
argument_list|,
name|getMask
argument_list|(
name|FieldInfo
argument_list|)
argument_list|,
name|FieldInfo
index|[
literal|1
index|]
argument_list|)
return|;
block|}
end_function

begin_decl_stmt
name|uint64_t
name|getFieldValue
argument_list|(
specifier|const
name|BitFieldInfo
name|FieldInfo
argument_list|)
decl|const
block|{
return|return
name|getMask
argument_list|(
name|FieldInfo
argument_list|)
operator|&
operator|(
name|RawData
operator|>>
name|FieldInfo
index|[
literal|1
index|]
operator|)
return|;
block|}
end_decl_stmt

begin_function
name|void
name|init
parameter_list|(
name|bool
name|IsPointer
parameter_list|,
name|bool
name|IsVector
parameter_list|,
name|uint16_t
name|NumElements
parameter_list|,
name|unsigned
name|SizeInBits
parameter_list|,
name|unsigned
name|AddressSpace
parameter_list|)
block|{
name|this
operator|->
name|IsPointer
operator|=
name|IsPointer
expr_stmt|;
name|this
operator|->
name|IsVector
operator|=
name|IsVector
expr_stmt|;
if|if
condition|(
operator|!
name|IsVector
condition|)
block|{
if|if
condition|(
operator|!
name|IsPointer
condition|)
name|RawData
operator|=
name|maskAndShift
argument_list|(
name|SizeInBits
argument_list|,
name|ScalarSizeFieldInfo
argument_list|)
expr_stmt|;
else|else
name|RawData
operator|=
name|maskAndShift
argument_list|(
name|SizeInBits
argument_list|,
name|PointerSizeFieldInfo
argument_list|)
operator||
name|maskAndShift
argument_list|(
name|AddressSpace
argument_list|,
name|PointerAddressSpaceFieldInfo
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|assert
argument_list|(
name|NumElements
operator|>
literal|1
operator|&&
literal|"invalid number of vector elements"
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|IsPointer
condition|)
name|RawData
operator|=
name|maskAndShift
argument_list|(
name|NumElements
argument_list|,
name|VectorElementsFieldInfo
argument_list|)
operator||
name|maskAndShift
argument_list|(
name|SizeInBits
argument_list|,
name|VectorSizeFieldInfo
argument_list|)
expr_stmt|;
else|else
name|RawData
operator|=
name|maskAndShift
argument_list|(
name|NumElements
argument_list|,
name|PointerVectorElementsFieldInfo
argument_list|)
operator||
name|maskAndShift
argument_list|(
name|SizeInBits
argument_list|,
name|PointerVectorSizeFieldInfo
argument_list|)
operator||
name|maskAndShift
argument_list|(
name|AddressSpace
argument_list|,
name|PointerVectorAddressSpaceFieldInfo
argument_list|)
expr_stmt|;
block|}
block|}
end_function

begin_expr_stmt
unit|};
specifier|inline
name|raw_ostream
operator|&
name|operator
operator|<<
operator|(
name|raw_ostream
operator|&
name|OS
operator|,
specifier|const
name|LLT
operator|&
name|Ty
operator|)
block|{
name|Ty
operator|.
name|print
argument_list|(
name|OS
argument_list|)
block|;
return|return
name|OS
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|template
operator|<
operator|>
expr|struct
name|DenseMapInfo
operator|<
name|LLT
operator|>
block|{
specifier|static
specifier|inline
name|LLT
name|getEmptyKey
argument_list|()
block|{
name|LLT
name|Invalid
block|;
name|Invalid
operator|.
name|IsPointer
operator|=
name|true
block|;
return|return
name|Invalid
return|;
block|}
specifier|static
specifier|inline
name|LLT
name|getTombstoneKey
argument_list|()
block|{
name|LLT
name|Invalid
block|;
name|Invalid
operator|.
name|IsVector
operator|=
name|true
block|;
return|return
name|Invalid
return|;
block|}
end_expr_stmt

begin_function
specifier|static
specifier|inline
name|unsigned
name|getHashValue
parameter_list|(
specifier|const
name|LLT
modifier|&
name|Ty
parameter_list|)
block|{
name|uint64_t
name|Val
init|=
operator|(
operator|(
name|uint64_t
operator|)
name|Ty
operator|.
name|RawData
operator|)
operator|<<
literal|2
operator||
operator|(
operator|(
name|uint64_t
operator|)
name|Ty
operator|.
name|IsPointer
operator|)
operator|<<
literal|1
operator||
operator|(
operator|(
name|uint64_t
operator|)
name|Ty
operator|.
name|IsVector
operator|)
decl_stmt|;
return|return
name|DenseMapInfo
operator|<
name|uint64_t
operator|>
operator|::
name|getHashValue
argument_list|(
name|Val
argument_list|)
return|;
block|}
end_function

begin_function
specifier|static
name|bool
name|isEqual
parameter_list|(
specifier|const
name|LLT
modifier|&
name|LHS
parameter_list|,
specifier|const
name|LLT
modifier|&
name|RHS
parameter_list|)
block|{
return|return
name|LHS
operator|==
name|RHS
return|;
block|}
end_function

begin_endif
unit|};  }
endif|#
directive|endif
end_endif

begin_comment
comment|// LLVM_SUPPORT_LOWLEVELTYPEIMPL_H
end_comment

end_unit

