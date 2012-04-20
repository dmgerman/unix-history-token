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
name|namespace
name|Attribute
block|{
comment|/// We use this proxy POD type to allow constructing Attributes constants
comment|/// using initializer lists. Do not use this class directly.
struct|struct
name|AttrConst
block|{
name|uint64_t
name|v
decl_stmt|;
name|AttrConst
name|operator
operator||
operator|(
specifier|const
name|AttrConst
name|Attrs
operator|)
specifier|const
block|{
name|AttrConst
name|Res
operator|=
block|{
name|v
operator||
name|Attrs
operator|.
name|v
block|}
block|;
return|return
name|Res
return|;
block|}
name|AttrConst
name|operator
operator|~
operator|(
operator|)
specifier|const
block|{
name|AttrConst
name|Res
operator|=
block|{
operator|~
name|v
block|}
block|;
return|return
name|Res
return|;
block|}
block|}
struct|;
block|}
comment|// namespace Attribute
comment|/// Attributes - A bitset of attributes.
name|class
name|Attributes
block|{
name|public
label|:
name|Attributes
argument_list|()
operator|:
name|Bits
argument_list|(
literal|0
argument_list|)
block|{ }
name|explicit
name|Attributes
argument_list|(
argument|uint64_t Val
argument_list|)
operator|:
name|Bits
argument_list|(
argument|Val
argument_list|)
block|{ }
comment|/*implicit*/
name|Attributes
argument_list|(
argument|Attribute::AttrConst Val
argument_list|)
operator|:
name|Bits
argument_list|(
argument|Val.v
argument_list|)
block|{ }
name|Attributes
argument_list|(
specifier|const
name|Attributes
operator|&
name|Attrs
argument_list|)
operator|:
name|Bits
argument_list|(
argument|Attrs.Bits
argument_list|)
block|{ }
comment|// This is a "safe bool() operator".
name|operator
specifier|const
name|void
operator|*
operator|(
operator|)
specifier|const
block|{
return|return
name|Bits
operator|?
name|this
operator|:
literal|0
return|;
block|}
name|bool
name|isEmptyOrSingleton
argument_list|()
specifier|const
block|{
return|return
operator|(
name|Bits
operator|&
operator|(
name|Bits
operator|-
literal|1
operator|)
operator|)
operator|==
literal|0
return|;
block|}
name|Attributes
modifier|&
name|operator
init|=
operator|(
specifier|const
name|Attributes
operator|&
name|Attrs
operator|)
block|{
name|Bits
operator|=
name|Attrs
operator|.
name|Bits
block|;
return|return
operator|*
name|this
return|;
block|}
name|bool
name|operator
operator|==
operator|(
specifier|const
name|Attributes
operator|&
name|Attrs
operator|)
specifier|const
block|{
return|return
name|Bits
operator|==
name|Attrs
operator|.
name|Bits
return|;
block|}
name|bool
name|operator
operator|!=
operator|(
specifier|const
name|Attributes
operator|&
name|Attrs
operator|)
specifier|const
block|{
return|return
name|Bits
operator|!=
name|Attrs
operator|.
name|Bits
return|;
block|}
name|Attributes
name|operator
operator||
operator|(
specifier|const
name|Attributes
operator|&
name|Attrs
operator|)
specifier|const
block|{
return|return
name|Attributes
argument_list|(
name|Bits
operator||
name|Attrs
operator|.
name|Bits
argument_list|)
return|;
block|}
name|Attributes
name|operator
modifier|&
argument_list|(
specifier|const
name|Attributes
operator|&
name|Attrs
argument_list|)
decl|const
block|{
return|return
name|Attributes
argument_list|(
name|Bits
operator|&
name|Attrs
operator|.
name|Bits
argument_list|)
return|;
block|}
name|Attributes
name|operator
modifier|^
argument_list|(
specifier|const
name|Attributes
operator|&
name|Attrs
argument_list|)
decl|const
block|{
return|return
name|Attributes
argument_list|(
name|Bits
operator|^
name|Attrs
operator|.
name|Bits
argument_list|)
return|;
block|}
name|Attributes
operator|&
name|operator
operator||=
operator|(
specifier|const
name|Attributes
operator|&
name|Attrs
operator|)
block|{
name|Bits
operator||=
name|Attrs
operator|.
name|Bits
block|;
return|return
operator|*
name|this
return|;
block|}
name|Attributes
operator|&
name|operator
operator|&=
operator|(
specifier|const
name|Attributes
operator|&
name|Attrs
operator|)
block|{
name|Bits
operator|&=
name|Attrs
operator|.
name|Bits
block|;
return|return
operator|*
name|this
return|;
block|}
name|Attributes
name|operator
operator|~
operator|(
operator|)
specifier|const
block|{
return|return
name|Attributes
argument_list|(
operator|~
name|Bits
argument_list|)
return|;
block|}
name|uint64_t
name|Raw
argument_list|()
specifier|const
block|{
return|return
name|Bits
return|;
block|}
name|private
label|:
comment|// Currently, we need less than 64 bits.
name|uint64_t
name|Bits
decl_stmt|;
block|}
empty_stmt|;
name|namespace
name|Attribute
block|{
comment|/// Function parameters and results can have attributes to indicate how they
comment|/// should be treated by optimizations and code generation. This enumeration
comment|/// lists the attributes that can be associated with parameters, function
comment|/// results or the function itself.
comment|/// @brief Function attributes.
comment|// We declare AttrConst objects that will be used throughout the code
comment|// and also raw uint64_t objects with _i suffix to be used below for other
comment|// constant declarations. This is done to avoid static CTORs and at the same
comment|// time to keep type-safety of Attributes.
define|#
directive|define
name|DECLARE_LLVM_ATTRIBUTE
parameter_list|(
name|name
parameter_list|,
name|value
parameter_list|)
define|\
value|const uint64_t name##_i = value; \   const AttrConst name = {value};
name|DECLARE_LLVM_ATTRIBUTE
argument_list|(
argument|None
argument_list|,
literal|0
argument_list|)
comment|///< No attributes have been set
name|DECLARE_LLVM_ATTRIBUTE
argument_list|(
argument|ZExt
argument_list|,
literal|1
argument|<<
literal|0
argument_list|)
comment|///< Zero extended before/after call
name|DECLARE_LLVM_ATTRIBUTE
argument_list|(
argument|SExt
argument_list|,
literal|1
argument|<<
literal|1
argument_list|)
comment|///< Sign extended before/after call
name|DECLARE_LLVM_ATTRIBUTE
argument_list|(
argument|NoReturn
argument_list|,
literal|1
argument|<<
literal|2
argument_list|)
comment|///< Mark the function as not returning
name|DECLARE_LLVM_ATTRIBUTE
argument_list|(
argument|InReg
argument_list|,
literal|1
argument|<<
literal|3
argument_list|)
comment|///< Force argument to be passed in register
name|DECLARE_LLVM_ATTRIBUTE
argument_list|(
argument|StructRet
argument_list|,
literal|1
argument|<<
literal|4
argument_list|)
comment|///< Hidden pointer to structure to return
name|DECLARE_LLVM_ATTRIBUTE
argument_list|(
argument|NoUnwind
argument_list|,
literal|1
argument|<<
literal|5
argument_list|)
comment|///< Function doesn't unwind stack
name|DECLARE_LLVM_ATTRIBUTE
argument_list|(
argument|NoAlias
argument_list|,
literal|1
argument|<<
literal|6
argument_list|)
comment|///< Considered to not alias after call
name|DECLARE_LLVM_ATTRIBUTE
argument_list|(
argument|ByVal
argument_list|,
literal|1
argument|<<
literal|7
argument_list|)
comment|///< Pass structure by value
name|DECLARE_LLVM_ATTRIBUTE
argument_list|(
argument|Nest
argument_list|,
literal|1
argument|<<
literal|8
argument_list|)
comment|///< Nested function static chain
name|DECLARE_LLVM_ATTRIBUTE
argument_list|(
argument|ReadNone
argument_list|,
literal|1
argument|<<
literal|9
argument_list|)
comment|///< Function does not access memory
name|DECLARE_LLVM_ATTRIBUTE
argument_list|(
argument|ReadOnly
argument_list|,
literal|1
argument|<<
literal|10
argument_list|)
comment|///< Function only reads from memory
name|DECLARE_LLVM_ATTRIBUTE
argument_list|(
argument|NoInline
argument_list|,
literal|1
argument|<<
literal|11
argument_list|)
comment|///< inline=never
name|DECLARE_LLVM_ATTRIBUTE
argument_list|(
argument|AlwaysInline
argument_list|,
literal|1
argument|<<
literal|12
argument_list|)
comment|///< inline=always
name|DECLARE_LLVM_ATTRIBUTE
argument_list|(
argument|OptimizeForSize
argument_list|,
literal|1
argument|<<
literal|13
argument_list|)
comment|///< opt_size
name|DECLARE_LLVM_ATTRIBUTE
argument_list|(
argument|StackProtect
argument_list|,
literal|1
argument|<<
literal|14
argument_list|)
comment|///< Stack protection.
name|DECLARE_LLVM_ATTRIBUTE
argument_list|(
argument|StackProtectReq
argument_list|,
literal|1
argument|<<
literal|15
argument_list|)
comment|///< Stack protection required.
name|DECLARE_LLVM_ATTRIBUTE
argument_list|(
argument|Alignment
argument_list|,
literal|31
argument|<<
literal|16
argument_list|)
comment|///< Alignment of parameter (5 bits)
comment|// stored as log2 of alignment with +1 bias
comment|// 0 means unaligned different from align 1
name|DECLARE_LLVM_ATTRIBUTE
argument_list|(
argument|NoCapture
argument_list|,
literal|1
argument|<<
literal|21
argument_list|)
comment|///< Function creates no aliases of pointer
name|DECLARE_LLVM_ATTRIBUTE
argument_list|(
argument|NoRedZone
argument_list|,
literal|1
argument|<<
literal|22
argument_list|)
comment|/// disable redzone
name|DECLARE_LLVM_ATTRIBUTE
argument_list|(
argument|NoImplicitFloat
argument_list|,
literal|1
argument|<<
literal|23
argument_list|)
comment|/// disable implicit floating point
comment|/// instructions.
name|DECLARE_LLVM_ATTRIBUTE
argument_list|(
argument|Naked
argument_list|,
literal|1
argument|<<
literal|24
argument_list|)
comment|///< Naked function
name|DECLARE_LLVM_ATTRIBUTE
argument_list|(
argument|InlineHint
argument_list|,
literal|1
argument|<<
literal|25
argument_list|)
comment|///< source said inlining was
comment|///desirable
name|DECLARE_LLVM_ATTRIBUTE
argument_list|(
argument|StackAlignment
argument_list|,
literal|7
argument|<<
literal|26
argument_list|)
comment|///< Alignment of stack for
comment|///function (3 bits) stored as log2
comment|///of alignment with +1 bias
comment|///0 means unaligned (different from
comment|///alignstack= {1))
name|DECLARE_LLVM_ATTRIBUTE
argument_list|(
argument|ReturnsTwice
argument_list|,
literal|1
argument|<<
literal|29
argument_list|)
comment|///< Function can return twice
name|DECLARE_LLVM_ATTRIBUTE
argument_list|(
argument|UWTable
argument_list|,
literal|1
argument|<<
literal|30
argument_list|)
comment|///< Function must be in a unwind
comment|///table
name|DECLARE_LLVM_ATTRIBUTE
argument_list|(
argument|NonLazyBind
argument_list|,
literal|1U
argument|<<
literal|31
argument_list|)
comment|///< Function is called early and/or
comment|/// often, so lazy binding isn't
comment|/// worthwhile.
name|DECLARE_LLVM_ATTRIBUTE
argument_list|(
argument|AddressSafety
argument_list|,
literal|1ULL
argument|<<
literal|32
argument_list|)
comment|///< Address safety checking is on.
undef|#
directive|undef
name|DECLARE_LLVM_ATTRIBUTE
comment|/// Note that uwtable is about the ABI or the user mandating an entry in the
comment|/// unwind table. The nounwind attribute is about an exception passing by the
comment|/// function.
comment|/// In a theoretical system that uses tables for profiling and sjlj for
comment|/// exceptions, they would be fully independent. In a normal system that
comment|/// uses tables for both, the semantics are:
comment|/// nil                = Needs an entry because an exception might pass by.
comment|/// nounwind           = No need for an entry
comment|/// uwtable            = Needs an entry because the ABI says so and because
comment|///                      an exception might pass by.
comment|/// uwtable + nounwind = Needs an entry because the ABI says so.
comment|/// @brief Attributes that only apply to function parameters.
specifier|const
name|AttrConst
name|ParameterOnly
init|=
block|{
name|ByVal_i
operator||
name|Nest_i
operator||
name|StructRet_i
operator||
name|NoCapture_i
block|}
decl_stmt|;
comment|/// @brief Attributes that may be applied to the function itself.  These cannot
comment|/// be used on return values or function parameters.
specifier|const
name|AttrConst
name|FunctionOnly
init|=
block|{
name|NoReturn_i
operator||
name|NoUnwind_i
operator||
name|ReadNone_i
operator||
name|ReadOnly_i
operator||
name|NoInline_i
operator||
name|AlwaysInline_i
operator||
name|OptimizeForSize_i
operator||
name|StackProtect_i
operator||
name|StackProtectReq_i
operator||
name|NoRedZone_i
operator||
name|NoImplicitFloat_i
operator||
name|Naked_i
operator||
name|InlineHint_i
operator||
name|StackAlignment_i
operator||
name|UWTable_i
operator||
name|NonLazyBind_i
operator||
name|ReturnsTwice_i
operator||
name|AddressSafety_i
block|}
decl_stmt|;
comment|/// @brief Parameter attributes that do not apply to vararg call arguments.
specifier|const
name|AttrConst
name|VarArgsIncompatible
init|=
block|{
name|StructRet_i
block|}
decl_stmt|;
comment|/// @brief Attributes that are mutually incompatible.
specifier|const
name|AttrConst
name|MutuallyIncompatible
index|[
literal|4
index|]
init|=
block|{
block|{
name|ByVal_i
operator||
name|InReg_i
operator||
name|Nest_i
operator||
name|StructRet_i
block|}
block|,
block|{
name|ZExt_i
operator||
name|SExt_i
block|}
block|,
block|{
name|ReadNone_i
operator||
name|ReadOnly_i
block|}
block|,
block|{
name|NoInline_i
operator||
name|AlwaysInline_i
block|}
block|}
decl_stmt|;
comment|/// @brief Which attributes cannot be applied to a type.
name|Attributes
name|typeIncompatible
parameter_list|(
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
name|None
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
name|Attributes
argument_list|(
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
argument_list|)
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
operator|!
name|Align
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
operator|.
name|Raw
argument_list|()
operator|>>
literal|16
operator|)
operator|-
literal|1
operator|)
return|;
block|}
comment|/// This turns an int stack alignment (which must be a power of 2) into
comment|/// the form used internally in Attributes.
specifier|inline
name|Attributes
name|constructStackAlignmentFromInt
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
name|None
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
literal|0x100
operator|&&
literal|"Alignment too large."
argument_list|)
expr_stmt|;
return|return
name|Attributes
argument_list|(
operator|(
name|Log2_32
argument_list|(
name|i
argument_list|)
operator|+
literal|1
operator|)
operator|<<
literal|26
argument_list|)
return|;
block|}
comment|/// This returns the stack alignment field of an attribute as a byte alignment
comment|/// value.
specifier|inline
name|unsigned
name|getStackAlignmentFromAttrs
parameter_list|(
name|Attributes
name|A
parameter_list|)
block|{
name|Attributes
name|StackAlign
init|=
name|A
operator|&
name|Attribute
operator|::
name|StackAlignment
decl_stmt|;
if|if
condition|(
operator|!
name|StackAlign
condition|)
return|return
literal|0
return|;
return|return
literal|1U
operator|<<
operator|(
operator|(
name|StackAlign
operator|.
name|Raw
argument_list|()
operator|>>
literal|26
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

