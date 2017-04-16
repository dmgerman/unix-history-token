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
file|<cassert>
end_include

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
enum|enum
name|TypeKind
enum|:
name|uint16_t
block|{
name|Invalid
block|,
name|Scalar
block|,
name|Pointer
block|,
name|Vector
block|,   }
enum|;
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
name|Scalar
block|,
literal|1
block|,
name|SizeInBits
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
return|return
name|LLT
block|{
name|Pointer
block|,
name|AddressSpace
block|,
name|SizeInBits
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
return|return
name|LLT
block|{
name|Vector
block|,
name|NumElements
block|,
name|ScalarSizeInBits
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
name|ScalarTy
operator|.
name|isScalar
argument_list|()
operator|&&
literal|"invalid vector element type"
argument_list|)
expr_stmt|;
return|return
name|LLT
block|{
name|Vector
block|,
name|NumElements
block|,
name|ScalarTy
operator|.
name|getSizeInBits
argument_list|()
block|}
return|;
block|}
name|explicit
name|LLT
argument_list|(
argument|TypeKind Kind
argument_list|,
argument|uint16_t NumElements
argument_list|,
argument|unsigned SizeInBits
argument_list|)
block|:
name|SizeInBits
argument_list|(
name|SizeInBits
argument_list|)
operator|,
name|ElementsOrAddrSpace
argument_list|(
name|NumElements
argument_list|)
operator|,
name|Kind
argument_list|(
argument|Kind
argument_list|)
block|{
name|assert
argument_list|(
operator|(
name|Kind
operator|!=
name|Vector
operator|||
name|ElementsOrAddrSpace
operator|>
literal|1
operator|)
operator|&&
literal|"invalid number of vector elements"
argument_list|)
block|;   }
name|explicit
name|LLT
argument_list|()
operator|:
name|SizeInBits
argument_list|(
literal|0
argument_list|)
operator|,
name|ElementsOrAddrSpace
argument_list|(
literal|0
argument_list|)
operator|,
name|Kind
argument_list|(
argument|Invalid
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
name|Kind
operator|!=
name|Invalid
return|;
block|}
name|bool
name|isScalar
argument_list|()
specifier|const
block|{
return|return
name|Kind
operator|==
name|Scalar
return|;
block|}
name|bool
name|isPointer
argument_list|()
specifier|const
block|{
return|return
name|Kind
operator|==
name|Pointer
return|;
block|}
name|bool
name|isVector
argument_list|()
specifier|const
block|{
return|return
name|Kind
operator|==
name|Vector
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
name|isVector
argument_list|()
operator|&&
literal|"cannot get number of elements on scalar/aggregate"
argument_list|)
block|;
return|return
name|ElementsOrAddrSpace
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
name|SizeInBits
return|;
return|return
name|SizeInBits
operator|*
name|ElementsOrAddrSpace
return|;
block|}
name|unsigned
name|getScalarSizeInBits
argument_list|()
specifier|const
block|{
return|return
name|SizeInBits
return|;
block|}
name|unsigned
name|getAddressSpace
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
name|isPointer
argument_list|()
operator|&&
literal|"cannot get address space of non-pointer type"
argument_list|)
block|;
return|return
name|ElementsOrAddrSpace
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
return|return
name|scalar
argument_list|(
name|SizeInBits
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
name|isPointer
argument_list|()
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
name|Kind
block|,
name|ElementsOrAddrSpace
block|,
name|SizeInBits
operator|/
literal|2
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
name|isPointer
argument_list|()
operator|&&
literal|"cannot change size of this type"
argument_list|)
block|;
return|return
name|LLT
block|{
name|Kind
block|,
name|ElementsOrAddrSpace
block|,
name|SizeInBits
operator|*
literal|2
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
name|ElementsOrAddrSpace
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
name|ElementsOrAddrSpace
operator|==
literal|2
condition|)
return|return
name|scalar
argument_list|(
name|SizeInBits
argument_list|)
return|;
return|return
name|LLT
block|{
name|Vector
block|,
name|static_cast
operator|<
name|uint16_t
operator|>
operator|(
name|ElementsOrAddrSpace
operator|/
literal|2
operator|)
block|,
name|SizeInBits
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
name|assert
argument_list|(
operator|!
name|isPointer
argument_list|()
operator|&&
literal|"cannot double elements in pointer"
argument_list|)
block|;
return|return
name|LLT
block|{
name|Vector
block|,
name|static_cast
operator|<
name|uint16_t
operator|>
operator|(
name|ElementsOrAddrSpace
operator|*
literal|2
operator|)
block|,
name|SizeInBits
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
name|Kind
operator|==
name|RHS
operator|.
name|Kind
operator|&&
name|SizeInBits
operator|==
name|RHS
operator|.
name|SizeInBits
operator|&&
name|ElementsOrAddrSpace
operator|==
name|RHS
operator|.
name|ElementsOrAddrSpace
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

begin_decl_stmt
name|unsigned
name|SizeInBits
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|uint16_t
name|ElementsOrAddrSpace
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|TypeKind
name|Kind
decl_stmt|;
end_decl_stmt

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
return|return
name|LLT
block|{
name|LLT
operator|::
name|Invalid
block|,
literal|0
block|,
operator|-
literal|1u
block|}
return|;
block|}
specifier|static
specifier|inline
name|LLT
name|getTombstoneKey
argument_list|()
block|{
return|return
name|LLT
block|{
name|LLT
operator|::
name|Invalid
block|,
literal|0
block|,
operator|-
literal|2u
block|}
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
name|SizeInBits
operator|<<
literal|32
operator|)
operator||
operator|(
operator|(
name|uint64_t
operator|)
name|Ty
operator|.
name|ElementsOrAddrSpace
operator|<<
literal|16
operator|)
operator||
operator|(
name|uint64_t
operator|)
name|Ty
operator|.
name|Kind
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

