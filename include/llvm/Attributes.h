begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- llvm/Attributes.h - Container for Attributes ------------*- C++ -*-===//
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
comment|// This file contains the simple types necessary to represent the
end_comment

begin_comment
comment|// attributes associated with functions and their calls.
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
name|LLVM_ATTRIBUTES_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_ATTRIBUTES_H
end_define

begin_include
include|#
directive|include
file|"llvm/Support/MathExtras.h"
end_include

begin_include
include|#
directive|include
file|<cassert>
end_include

begin_include
include|#
directive|include
file|<string>
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|Type
decl_stmt|;
comment|/// Attributes - A bitset of attributes.
typedef|typedef
name|unsigned
name|Attributes
typedef|;
name|namespace
name|Attribute
block|{
comment|/// Function parameters and results can have attributes to indicate how they
comment|/// should be treated by optimizations and code generation. This enumeration
comment|/// lists the attributes that can be associated with parameters, function
comment|/// results or the function itself.
comment|/// @brief Function attributes.
specifier|const
name|Attributes
name|None
init|=
literal|0
decl_stmt|;
comment|///< No attributes have been set
specifier|const
name|Attributes
name|ZExt
init|=
literal|1
operator|<<
literal|0
decl_stmt|;
comment|///< Zero extended before/after call
specifier|const
name|Attributes
name|SExt
init|=
literal|1
operator|<<
literal|1
decl_stmt|;
comment|///< Sign extended before/after call
specifier|const
name|Attributes
name|NoReturn
init|=
literal|1
operator|<<
literal|2
decl_stmt|;
comment|///< Mark the function as not returning
specifier|const
name|Attributes
name|InReg
init|=
literal|1
operator|<<
literal|3
decl_stmt|;
comment|///< Force argument to be passed in register
specifier|const
name|Attributes
name|StructRet
init|=
literal|1
operator|<<
literal|4
decl_stmt|;
comment|///< Hidden pointer to structure to return
specifier|const
name|Attributes
name|NoUnwind
init|=
literal|1
operator|<<
literal|5
decl_stmt|;
comment|///< Function doesn't unwind stack
specifier|const
name|Attributes
name|NoAlias
init|=
literal|1
operator|<<
literal|6
decl_stmt|;
comment|///< Considered to not alias after call
specifier|const
name|Attributes
name|ByVal
init|=
literal|1
operator|<<
literal|7
decl_stmt|;
comment|///< Pass structure by value
specifier|const
name|Attributes
name|Nest
init|=
literal|1
operator|<<
literal|8
decl_stmt|;
comment|///< Nested function static chain
specifier|const
name|Attributes
name|ReadNone
init|=
literal|1
operator|<<
literal|9
decl_stmt|;
comment|///< Function does not access memory
specifier|const
name|Attributes
name|ReadOnly
init|=
literal|1
operator|<<
literal|10
decl_stmt|;
comment|///< Function only reads from memory
specifier|const
name|Attributes
name|NoInline
init|=
literal|1
operator|<<
literal|11
decl_stmt|;
comment|///< inline=never
specifier|const
name|Attributes
name|AlwaysInline
init|=
literal|1
operator|<<
literal|12
decl_stmt|;
comment|///< inline=always
specifier|const
name|Attributes
name|OptimizeForSize
init|=
literal|1
operator|<<
literal|13
decl_stmt|;
comment|///< opt_size
specifier|const
name|Attributes
name|StackProtect
init|=
literal|1
operator|<<
literal|14
decl_stmt|;
comment|///< Stack protection.
specifier|const
name|Attributes
name|StackProtectReq
init|=
literal|1
operator|<<
literal|15
decl_stmt|;
comment|///< Stack protection required.
specifier|const
name|Attributes
name|Alignment
init|=
literal|31
operator|<<
literal|16
decl_stmt|;
comment|///< Alignment of parameter (5 bits)
comment|// stored as log2 of alignment with +1 bias
comment|// 0 means unaligned different from align 1
specifier|const
name|Attributes
name|NoCapture
init|=
literal|1
operator|<<
literal|21
decl_stmt|;
comment|///< Function creates no aliases of pointer
specifier|const
name|Attributes
name|NoRedZone
init|=
literal|1
operator|<<
literal|22
decl_stmt|;
comment|/// disable redzone
specifier|const
name|Attributes
name|NoImplicitFloat
init|=
literal|1
operator|<<
literal|23
decl_stmt|;
comment|/// disable implicit floating point
comment|/// instructions.
specifier|const
name|Attributes
name|Naked
init|=
literal|1
operator|<<
literal|24
decl_stmt|;
comment|///< Naked function
comment|/// @brief Attributes that only apply to function parameters.
specifier|const
name|Attributes
name|ParameterOnly
init|=
name|ByVal
operator||
name|Nest
operator||
name|StructRet
operator||
name|NoCapture
decl_stmt|;
comment|/// @brief Attributes that may be applied to the function itself.  These cannot
comment|/// be used on return values or function parameters.
specifier|const
name|Attributes
name|FunctionOnly
init|=
name|NoReturn
operator||
name|NoUnwind
operator||
name|ReadNone
operator||
name|ReadOnly
operator||
name|NoInline
operator||
name|AlwaysInline
operator||
name|OptimizeForSize
operator||
name|StackProtect
operator||
name|StackProtectReq
operator||
name|NoRedZone
operator||
name|NoImplicitFloat
operator||
name|Naked
decl_stmt|;
comment|/// @brief Parameter attributes that do not apply to vararg call arguments.
specifier|const
name|Attributes
name|VarArgsIncompatible
init|=
name|StructRet
decl_stmt|;
comment|/// @brief Attributes that are mutually incompatible.
specifier|const
name|Attributes
name|MutuallyIncompatible
index|[
literal|4
index|]
init|=
block|{
name|ByVal
operator||
name|InReg
operator||
name|Nest
operator||
name|StructRet
block|,
name|ZExt
operator||
name|SExt
block|,
name|ReadNone
operator||
name|ReadOnly
block|,
name|NoInline
operator||
name|AlwaysInline
block|}
decl_stmt|;
comment|/// @brief Which attributes cannot be applied to a type.
name|Attributes
name|typeIncompatible
parameter_list|(
specifier|const
name|Type
modifier|*
name|Ty
parameter_list|)
function_decl|;
comment|/// This turns an int alignment (a power of 2, normally) into the
comment|/// form used internally in Attributes.
specifier|inline
name|Attributes
name|constructAlignmentFromInt
parameter_list|(
name|unsigned
name|i
parameter_list|)
block|{
comment|// Default alignment, allow the target to define how to align it.
if|if
condition|(
name|i
operator|==
literal|0
condition|)
return|return
literal|0
return|;
name|assert
argument_list|(
name|isPowerOf2_32
argument_list|(
name|i
argument_list|)
operator|&&
literal|"Alignment must be a power of two."
argument_list|)
expr_stmt|;
name|assert
argument_list|(
name|i
operator|<=
literal|0x40000000
operator|&&
literal|"Alignment too large."
argument_list|)
expr_stmt|;
return|return
operator|(
name|Log2_32
argument_list|(
name|i
argument_list|)
operator|+
literal|1
operator|)
operator|<<
literal|16
return|;
block|}
comment|/// This returns the alignment field of an attribute as a byte alignment value.
specifier|inline
name|unsigned
name|getAlignmentFromAttrs
parameter_list|(
name|Attributes
name|A
parameter_list|)
block|{
name|Attributes
name|Align
init|=
name|A
operator|&
name|Attribute
operator|::
name|Alignment
decl_stmt|;
if|if
condition|(
name|Align
operator|==
literal|0
condition|)
return|return
literal|0
return|;
return|return
literal|1U
operator|<<
operator|(
operator|(
name|Align
operator|>>
literal|16
operator|)
operator|-
literal|1
operator|)
return|;
block|}
comment|/// The set of Attributes set in Attributes is converted to a
comment|/// string of equivalent mnemonics. This is, presumably, for writing out
comment|/// the mnemonics for the assembly writer.
comment|/// @brief Convert attribute bits to text
name|std
operator|::
name|string
name|getAsString
argument_list|(
argument|Attributes Attrs
argument_list|)
expr_stmt|;
block|}
comment|// end namespace Attribute
comment|/// This is just a pair of values to associate a set of attributes
comment|/// with an index.
struct|struct
name|AttributeWithIndex
block|{
name|Attributes
name|Attrs
decl_stmt|;
comment|///< The attributes that are set, or'd together.
name|unsigned
name|Index
decl_stmt|;
comment|///< Index of the parameter for which the attributes apply.
comment|///< Index 0 is used for return value attributes.
comment|///< Index ~0U is used for function attributes.
specifier|static
name|AttributeWithIndex
name|get
parameter_list|(
name|unsigned
name|Idx
parameter_list|,
name|Attributes
name|Attrs
parameter_list|)
block|{
name|AttributeWithIndex
name|P
decl_stmt|;
name|P
operator|.
name|Index
operator|=
name|Idx
expr_stmt|;
name|P
operator|.
name|Attrs
operator|=
name|Attrs
expr_stmt|;
return|return
name|P
return|;
block|}
block|}
struct|;
comment|//===----------------------------------------------------------------------===//
comment|// AttrListPtr Smart Pointer
comment|//===----------------------------------------------------------------------===//
name|class
name|AttributeListImpl
decl_stmt|;
comment|/// AttrListPtr - This class manages the ref count for the opaque
comment|/// AttributeListImpl object and provides accessors for it.
name|class
name|AttrListPtr
block|{
comment|/// AttrList - The attributes that we are managing.  This can be null
comment|/// to represent the empty attributes list.
name|AttributeListImpl
modifier|*
name|AttrList
decl_stmt|;
name|public
label|:
name|AttrListPtr
argument_list|()
operator|:
name|AttrList
argument_list|(
literal|0
argument_list|)
block|{}
name|AttrListPtr
argument_list|(
specifier|const
name|AttrListPtr
operator|&
name|P
argument_list|)
expr_stmt|;
specifier|const
name|AttrListPtr
modifier|&
name|operator
init|=
operator|(
specifier|const
name|AttrListPtr
operator|&
name|RHS
operator|)
decl_stmt|;
operator|~
name|AttrListPtr
argument_list|()
expr_stmt|;
comment|//===--------------------------------------------------------------------===//
comment|// Attribute List Construction and Mutation
comment|//===--------------------------------------------------------------------===//
comment|/// get - Return a Attributes list with the specified parameter in it.
specifier|static
name|AttrListPtr
name|get
parameter_list|(
specifier|const
name|AttributeWithIndex
modifier|*
name|Attr
parameter_list|,
name|unsigned
name|NumAttrs
parameter_list|)
function_decl|;
comment|/// get - Return a Attribute list with the parameters specified by the
comment|/// consecutive random access iterator range.
name|template
operator|<
name|typename
name|Iter
operator|>
specifier|static
name|AttrListPtr
name|get
argument_list|(
argument|const Iter&I
argument_list|,
argument|const Iter&E
argument_list|)
block|{
if|if
condition|(
name|I
operator|==
name|E
condition|)
return|return
name|AttrListPtr
argument_list|()
return|;
comment|// Empty list.
return|return
name|get
argument_list|(
operator|&
operator|*
name|I
argument_list|,
name|static_cast
operator|<
name|unsigned
operator|>
operator|(
name|E
operator|-
name|I
operator|)
argument_list|)
return|;
block|}
comment|/// addAttr - Add the specified attribute at the specified index to this
comment|/// attribute list.  Since attribute lists are immutable, this
comment|/// returns the new list.
name|AttrListPtr
name|addAttr
argument_list|(
name|unsigned
name|Idx
argument_list|,
name|Attributes
name|Attrs
argument_list|)
decl|const
decl_stmt|;
comment|/// removeAttr - Remove the specified attribute at the specified index from
comment|/// this attribute list.  Since attribute lists are immutable, this
comment|/// returns the new list.
name|AttrListPtr
name|removeAttr
argument_list|(
name|unsigned
name|Idx
argument_list|,
name|Attributes
name|Attrs
argument_list|)
decl|const
decl_stmt|;
comment|//===--------------------------------------------------------------------===//
comment|// Attribute List Accessors
comment|//===--------------------------------------------------------------------===//
comment|/// getParamAttributes - The attributes for the specified index are
comment|/// returned.
name|Attributes
name|getParamAttributes
argument_list|(
name|unsigned
name|Idx
argument_list|)
decl|const
block|{
name|assert
argument_list|(
name|Idx
operator|&&
name|Idx
operator|!=
operator|~
literal|0U
operator|&&
literal|"Invalid parameter index!"
argument_list|)
expr_stmt|;
return|return
name|getAttributes
argument_list|(
name|Idx
argument_list|)
return|;
block|}
comment|/// getRetAttributes - The attributes for the ret value are
comment|/// returned.
name|Attributes
name|getRetAttributes
argument_list|()
specifier|const
block|{
return|return
name|getAttributes
argument_list|(
literal|0
argument_list|)
return|;
block|}
comment|/// getFnAttributes - The function attributes are returned.
name|Attributes
name|getFnAttributes
argument_list|()
specifier|const
block|{
return|return
name|getAttributes
argument_list|(
operator|~
literal|0U
argument_list|)
return|;
block|}
comment|/// paramHasAttr - Return true if the specified parameter index has the
comment|/// specified attribute set.
name|bool
name|paramHasAttr
argument_list|(
name|unsigned
name|Idx
argument_list|,
name|Attributes
name|Attr
argument_list|)
decl|const
block|{
return|return
name|getAttributes
argument_list|(
name|Idx
argument_list|)
operator|&
name|Attr
return|;
block|}
comment|/// getParamAlignment - Return the alignment for the specified function
comment|/// parameter.
name|unsigned
name|getParamAlignment
argument_list|(
name|unsigned
name|Idx
argument_list|)
decl|const
block|{
return|return
name|Attribute
operator|::
name|getAlignmentFromAttrs
argument_list|(
name|getAttributes
argument_list|(
name|Idx
argument_list|)
argument_list|)
return|;
block|}
comment|/// hasAttrSomewhere - Return true if the specified attribute is set for at
comment|/// least one parameter or for the return value.
name|bool
name|hasAttrSomewhere
argument_list|(
name|Attributes
name|Attr
argument_list|)
decl|const
decl_stmt|;
comment|/// operator==/!= - Provide equality predicates.
name|bool
name|operator
operator|==
operator|(
specifier|const
name|AttrListPtr
operator|&
name|RHS
operator|)
specifier|const
block|{
return|return
name|AttrList
operator|==
name|RHS
operator|.
name|AttrList
return|;
block|}
name|bool
name|operator
operator|!=
operator|(
specifier|const
name|AttrListPtr
operator|&
name|RHS
operator|)
specifier|const
block|{
return|return
name|AttrList
operator|!=
name|RHS
operator|.
name|AttrList
return|;
block|}
name|void
name|dump
argument_list|()
specifier|const
expr_stmt|;
comment|//===--------------------------------------------------------------------===//
comment|// Attribute List Introspection
comment|//===--------------------------------------------------------------------===//
comment|/// getRawPointer - Return a raw pointer that uniquely identifies this
comment|/// attribute list.
name|void
operator|*
name|getRawPointer
argument_list|()
specifier|const
block|{
return|return
name|AttrList
return|;
block|}
comment|// Attributes are stored as a dense set of slots, where there is one
comment|// slot for each argument that has an attribute.  This allows walking over the
comment|// dense set instead of walking the sparse list of attributes.
comment|/// isEmpty - Return true if there are no attributes.
comment|///
name|bool
name|isEmpty
argument_list|()
specifier|const
block|{
return|return
name|AttrList
operator|==
literal|0
return|;
block|}
comment|/// getNumSlots - Return the number of slots used in this attribute list.
comment|/// This is the number of arguments that have an attribute set on them
comment|/// (including the function itself).
name|unsigned
name|getNumSlots
argument_list|()
specifier|const
expr_stmt|;
comment|/// getSlot - Return the AttributeWithIndex at the specified slot.  This
comment|/// holds a index number plus a set of attributes.
specifier|const
name|AttributeWithIndex
modifier|&
name|getSlot
argument_list|(
name|unsigned
name|Slot
argument_list|)
decl|const
decl_stmt|;
name|private
label|:
name|explicit
name|AttrListPtr
parameter_list|(
name|AttributeListImpl
modifier|*
name|L
parameter_list|)
function_decl|;
comment|/// getAttributes - The attributes for the specified index are
comment|/// returned.  Attributes for the result are denoted with Idx = 0.
name|Attributes
name|getAttributes
argument_list|(
name|unsigned
name|Idx
argument_list|)
decl|const
decl_stmt|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
unit|}
comment|// End llvm namespace
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

