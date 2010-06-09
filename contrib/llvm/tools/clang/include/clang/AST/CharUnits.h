begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===--- CharUnits.h - Character units for sizes and offsets ----*- C++ -*-===//
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
comment|//  This file defines the CharUnits class
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
name|LLVM_CLANG_AST_CHARUNITS_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_AST_CHARUNITS_H
end_define

begin_include
include|#
directive|include
file|"llvm/System/DataTypes.h"
end_include

begin_decl_stmt
name|namespace
name|clang
block|{
comment|/// CharUnits - This is an opaque type for sizes expressed in character units.
comment|/// Instances of this type represent a quantity as a multiple of the size
comment|/// of the standard C type, char, on the target architecture. As an opaque
comment|/// type, CharUnits protects you from accidentally combining operations on
comment|/// quantities in bit units and character units.
comment|///
comment|/// It should be noted that characters and bytes are distinct concepts. Bytes
comment|/// refer to addressable units of data storage on the target machine, and
comment|/// characters are members of a set of elements used for the organization,
comment|/// control, or representation of data. According to C99, bytes are allowed
comment|/// to exceed characters in size, although currently, clang only supports
comment|/// architectures where the two are the same size.
comment|///
comment|/// For portability, never assume that a target character is 8 bits wide. Use
comment|/// CharUnit values whereever you calculate sizes, offsets, or alignments
comment|/// in character units.
name|class
name|CharUnits
block|{
name|public
label|:
typedef|typedef
name|int64_t
name|QuantityType
typedef|;
name|private
label|:
name|QuantityType
name|Quantity
decl_stmt|;
name|explicit
name|CharUnits
argument_list|(
argument|QuantityType C
argument_list|)
block|:
name|Quantity
argument_list|(
argument|C
argument_list|)
block|{}
name|public
label|:
comment|/// CharUnits - A default constructor.
name|CharUnits
argument_list|()
operator|:
name|Quantity
argument_list|(
literal|0
argument_list|)
block|{}
comment|/// Zero - Construct a CharUnits quantity of zero.
specifier|static
name|CharUnits
name|Zero
argument_list|()
block|{
return|return
name|CharUnits
argument_list|(
literal|0
argument_list|)
return|;
block|}
comment|/// One - Construct a CharUnits quantity of one.
specifier|static
name|CharUnits
name|One
parameter_list|()
block|{
return|return
name|CharUnits
argument_list|(
literal|1
argument_list|)
return|;
block|}
comment|/// fromQuantity - Construct a CharUnits quantity from a raw integer type.
specifier|static
name|CharUnits
name|fromQuantity
parameter_list|(
name|QuantityType
name|Quantity
parameter_list|)
block|{
return|return
name|CharUnits
argument_list|(
name|Quantity
argument_list|)
return|;
block|}
comment|// Compound assignment.
name|CharUnits
operator|&
name|operator
operator|+=
operator|(
specifier|const
name|CharUnits
operator|&
name|Other
operator|)
block|{
name|Quantity
operator|+=
name|Other
operator|.
name|Quantity
block|;
return|return
operator|*
name|this
return|;
block|}
name|CharUnits
operator|&
name|operator
operator|-=
operator|(
specifier|const
name|CharUnits
operator|&
name|Other
operator|)
block|{
name|Quantity
operator|-=
name|Other
operator|.
name|Quantity
block|;
return|return
operator|*
name|this
return|;
block|}
comment|// Comparison operators.
name|bool
name|operator
operator|==
operator|(
specifier|const
name|CharUnits
operator|&
name|Other
operator|)
specifier|const
block|{
return|return
name|Quantity
operator|==
name|Other
operator|.
name|Quantity
return|;
block|}
name|bool
name|operator
operator|!=
operator|(
specifier|const
name|CharUnits
operator|&
name|Other
operator|)
specifier|const
block|{
return|return
name|Quantity
operator|!=
name|Other
operator|.
name|Quantity
return|;
block|}
comment|// Relational operators.
name|bool
name|operator
operator|<
operator|(
specifier|const
name|CharUnits
operator|&
name|Other
operator|)
specifier|const
block|{
return|return
name|Quantity
operator|<
name|Other
operator|.
name|Quantity
return|;
block|}
name|bool
name|operator
operator|<=
operator|(
specifier|const
name|CharUnits
operator|&
name|Other
operator|)
specifier|const
block|{
return|return
name|Quantity
operator|<=
name|Other
operator|.
name|Quantity
return|;
block|}
name|bool
name|operator
operator|>
operator|(
specifier|const
name|CharUnits
operator|&
name|Other
operator|)
specifier|const
block|{
return|return
name|Quantity
operator|>
name|Other
operator|.
name|Quantity
return|;
block|}
name|bool
name|operator
operator|>=
operator|(
specifier|const
name|CharUnits
operator|&
name|Other
operator|)
specifier|const
block|{
return|return
name|Quantity
operator|>=
name|Other
operator|.
name|Quantity
return|;
block|}
comment|// Other predicates.
comment|/// isZero - Test whether the quantity equals zero.
name|bool
name|isZero
argument_list|()
specifier|const
block|{
return|return
name|Quantity
operator|==
literal|0
return|;
block|}
comment|/// isOne - Test whether the quantity equals one.
name|bool
name|isOne
argument_list|()
specifier|const
block|{
return|return
name|Quantity
operator|==
literal|1
return|;
block|}
comment|/// isPositive - Test whether the quantity is greater than zero.
name|bool
name|isPositive
argument_list|()
specifier|const
block|{
return|return
name|Quantity
operator|>
literal|0
return|;
block|}
comment|/// isNegative - Test whether the quantity is less than zero.
name|bool
name|isNegative
argument_list|()
specifier|const
block|{
return|return
name|Quantity
operator|<
literal|0
return|;
block|}
comment|// Arithmetic operators.
name|CharUnits
name|operator
modifier|*
argument_list|(
name|QuantityType
name|N
argument_list|)
decl|const
block|{
return|return
name|CharUnits
argument_list|(
name|Quantity
operator|*
name|N
argument_list|)
return|;
block|}
name|CharUnits
name|operator
operator|/
operator|(
name|QuantityType
name|N
operator|)
specifier|const
block|{
return|return
name|CharUnits
argument_list|(
name|Quantity
operator|/
name|N
argument_list|)
return|;
block|}
name|QuantityType
name|operator
operator|/
operator|(
specifier|const
name|CharUnits
operator|&
name|Other
operator|)
specifier|const
block|{
return|return
name|Quantity
operator|/
name|Other
operator|.
name|Quantity
return|;
block|}
name|CharUnits
name|operator
operator|%
operator|(
name|QuantityType
name|N
operator|)
specifier|const
block|{
return|return
name|CharUnits
argument_list|(
name|Quantity
operator|%
name|N
argument_list|)
return|;
block|}
name|QuantityType
name|operator
operator|%
operator|(
specifier|const
name|CharUnits
operator|&
name|Other
operator|)
specifier|const
block|{
return|return
name|Quantity
operator|%
name|Other
operator|.
name|Quantity
return|;
block|}
name|CharUnits
name|operator
operator|+
operator|(
specifier|const
name|CharUnits
operator|&
name|Other
operator|)
specifier|const
block|{
return|return
name|CharUnits
argument_list|(
name|Quantity
operator|+
name|Other
operator|.
name|Quantity
argument_list|)
return|;
block|}
name|CharUnits
name|operator
operator|-
operator|(
specifier|const
name|CharUnits
operator|&
name|Other
operator|)
specifier|const
block|{
return|return
name|CharUnits
argument_list|(
name|Quantity
operator|-
name|Other
operator|.
name|Quantity
argument_list|)
return|;
block|}
comment|// Conversions.
comment|/// getQuantity - Get the raw integer representation of this quantity.
name|QuantityType
name|getQuantity
argument_list|()
specifier|const
block|{
return|return
name|Quantity
return|;
block|}
block|}
empty_stmt|;
comment|// class CharUnit
block|}
end_decl_stmt

begin_comment
comment|// namespace clang
end_comment

begin_expr_stmt
specifier|inline
name|clang
operator|::
name|CharUnits
name|operator
operator|*
operator|(
name|clang
operator|::
name|CharUnits
operator|::
name|QuantityType
name|Scale
operator|,
specifier|const
name|clang
operator|::
name|CharUnits
operator|&
name|CU
operator|)
block|{
return|return
name|CU
operator|*
name|Scale
return|;
block|}
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// LLVM_CLANG_AST_CHARUNITS_H
end_comment

end_unit

