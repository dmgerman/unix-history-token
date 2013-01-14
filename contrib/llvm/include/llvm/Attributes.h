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
file|"llvm/ADT/ArrayRef.h"
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
name|AttrBuilder
decl_stmt|;
name|class
name|AttributesImpl
decl_stmt|;
name|class
name|LLVMContext
decl_stmt|;
name|class
name|Type
decl_stmt|;
comment|/// Attributes - A bitset of attributes.
name|class
name|Attributes
block|{
name|public
label|:
comment|/// Function parameters and results can have attributes to indicate how they
comment|/// should be treated by optimizations and code generation. This enumeration
comment|/// lists the attributes that can be associated with parameters, function
comment|/// results or the function itself.
comment|///
comment|/// Note that uwtable is about the ABI or the user mandating an entry in the
comment|/// unwind table. The nounwind attribute is about an exception passing by the
comment|/// function.
comment|///
comment|/// In a theoretical system that uses tables for profiling and sjlj for
comment|/// exceptions, they would be fully independent. In a normal system that uses
comment|/// tables for both, the semantics are:
comment|///
comment|/// nil                = Needs an entry because an exception might pass by.
comment|/// nounwind           = No need for an entry
comment|/// uwtable            = Needs an entry because the ABI says so and because
comment|///                      an exception might pass by.
comment|/// uwtable + nounwind = Needs an entry because the ABI says so.
enum|enum
name|AttrVal
block|{
comment|// IR-Level Attributes
name|None
block|,
comment|///< No attributes have been set
name|AddressSafety
block|,
comment|///< Address safety checking is on.
name|Alignment
block|,
comment|///< Alignment of parameter (5 bits)
comment|///< stored as log2 of alignment with +1 bias
comment|///< 0 means unaligned different from align 1
name|AlwaysInline
block|,
comment|///< inline=always
name|ByVal
block|,
comment|///< Pass structure by value
name|InlineHint
block|,
comment|///< Source said inlining was desirable
name|InReg
block|,
comment|///< Force argument to be passed in register
name|MinSize
block|,
comment|///< Function must be optimized for size first
name|Naked
block|,
comment|///< Naked function
name|Nest
block|,
comment|///< Nested function static chain
name|NoAlias
block|,
comment|///< Considered to not alias after call
name|NoCapture
block|,
comment|///< Function creates no aliases of pointer
name|NoImplicitFloat
block|,
comment|///< Disable implicit floating point insts
name|NoInline
block|,
comment|///< inline=never
name|NonLazyBind
block|,
comment|///< Function is called early and/or
comment|///< often, so lazy binding isn't worthwhile
name|NoRedZone
block|,
comment|///< Disable redzone
name|NoReturn
block|,
comment|///< Mark the function as not returning
name|NoUnwind
block|,
comment|///< Function doesn't unwind stack
name|OptimizeForSize
block|,
comment|///< opt_size
name|ReadNone
block|,
comment|///< Function does not access memory
name|ReadOnly
block|,
comment|///< Function only reads from memory
name|ReturnsTwice
block|,
comment|///< Function can return twice
name|SExt
block|,
comment|///< Sign extended before/after call
name|StackAlignment
block|,
comment|///< Alignment of stack for function (3 bits)
comment|///< stored as log2 of alignment with +1 bias 0
comment|///< means unaligned (different from
comment|///< alignstack={1))
name|StackProtect
block|,
comment|///< Stack protection.
name|StackProtectReq
block|,
comment|///< Stack protection required.
name|StructRet
block|,
comment|///< Hidden pointer to structure to return
name|UWTable
block|,
comment|///< Function must be in a unwind table
name|ZExt
comment|///< Zero extended before/after call
block|}
enum|;
name|private
label|:
name|AttributesImpl
modifier|*
name|Attrs
decl_stmt|;
name|Attributes
argument_list|(
name|AttributesImpl
operator|*
name|A
argument_list|)
operator|:
name|Attrs
argument_list|(
argument|A
argument_list|)
block|{}
name|public
operator|:
name|Attributes
argument_list|()
operator|:
name|Attrs
argument_list|(
literal|0
argument_list|)
block|{}
name|Attributes
argument_list|(
specifier|const
name|Attributes
operator|&
name|A
argument_list|)
operator|:
name|Attrs
argument_list|(
argument|A.Attrs
argument_list|)
block|{}
name|Attributes
operator|&
name|operator
operator|=
operator|(
specifier|const
name|Attributes
operator|&
name|A
operator|)
block|{
name|Attrs
operator|=
name|A
operator|.
name|Attrs
block|;
return|return
operator|*
name|this
return|;
block|}
comment|/// get - Return a uniquified Attributes object. This takes the uniquified
comment|/// value from the Builder and wraps it in the Attributes class.
specifier|static
name|Attributes
name|get
argument_list|(
name|LLVMContext
operator|&
name|Context
argument_list|,
name|ArrayRef
operator|<
name|AttrVal
operator|>
name|Vals
argument_list|)
decl_stmt|;
specifier|static
name|Attributes
name|get
parameter_list|(
name|LLVMContext
modifier|&
name|Context
parameter_list|,
name|AttrBuilder
modifier|&
name|B
parameter_list|)
function_decl|;
comment|/// @brief Return true if the attribute is present.
name|bool
name|hasAttribute
argument_list|(
name|AttrVal
name|Val
argument_list|)
decl|const
decl_stmt|;
comment|/// @brief Return true if attributes exist
name|bool
name|hasAttributes
argument_list|()
specifier|const
expr_stmt|;
comment|/// @brief Return true if the attributes are a non-null intersection.
name|bool
name|hasAttributes
argument_list|(
specifier|const
name|Attributes
operator|&
name|A
argument_list|)
decl|const
decl_stmt|;
comment|/// @brief Returns the alignment field of an attribute as a byte alignment
comment|/// value.
name|unsigned
name|getAlignment
argument_list|()
specifier|const
expr_stmt|;
comment|/// @brief Returns the stack alignment field of an attribute as a byte
comment|/// alignment value.
name|unsigned
name|getStackAlignment
argument_list|()
specifier|const
expr_stmt|;
comment|/// @brief Parameter attributes that do not apply to vararg call arguments.
name|bool
name|hasIncompatibleWithVarArgsAttrs
argument_list|()
specifier|const
block|{
return|return
name|hasAttribute
argument_list|(
name|Attributes
operator|::
name|StructRet
argument_list|)
return|;
block|}
comment|/// @brief Attributes that only apply to function parameters.
name|bool
name|hasParameterOnlyAttrs
argument_list|()
specifier|const
block|{
return|return
name|hasAttribute
argument_list|(
name|Attributes
operator|::
name|ByVal
argument_list|)
operator|||
name|hasAttribute
argument_list|(
name|Attributes
operator|::
name|Nest
argument_list|)
operator|||
name|hasAttribute
argument_list|(
name|Attributes
operator|::
name|StructRet
argument_list|)
operator|||
name|hasAttribute
argument_list|(
name|Attributes
operator|::
name|NoCapture
argument_list|)
return|;
block|}
comment|/// @brief Attributes that may be applied to the function itself.  These cannot
comment|/// be used on return values or function parameters.
name|bool
name|hasFunctionOnlyAttrs
argument_list|()
specifier|const
block|{
return|return
name|hasAttribute
argument_list|(
name|Attributes
operator|::
name|NoReturn
argument_list|)
operator|||
name|hasAttribute
argument_list|(
name|Attributes
operator|::
name|NoUnwind
argument_list|)
operator|||
name|hasAttribute
argument_list|(
name|Attributes
operator|::
name|ReadNone
argument_list|)
operator|||
name|hasAttribute
argument_list|(
name|Attributes
operator|::
name|ReadOnly
argument_list|)
operator|||
name|hasAttribute
argument_list|(
name|Attributes
operator|::
name|NoInline
argument_list|)
operator|||
name|hasAttribute
argument_list|(
name|Attributes
operator|::
name|AlwaysInline
argument_list|)
operator|||
name|hasAttribute
argument_list|(
name|Attributes
operator|::
name|OptimizeForSize
argument_list|)
operator|||
name|hasAttribute
argument_list|(
name|Attributes
operator|::
name|StackProtect
argument_list|)
operator|||
name|hasAttribute
argument_list|(
name|Attributes
operator|::
name|StackProtectReq
argument_list|)
operator|||
name|hasAttribute
argument_list|(
name|Attributes
operator|::
name|NoRedZone
argument_list|)
operator|||
name|hasAttribute
argument_list|(
name|Attributes
operator|::
name|NoImplicitFloat
argument_list|)
operator|||
name|hasAttribute
argument_list|(
name|Attributes
operator|::
name|Naked
argument_list|)
operator|||
name|hasAttribute
argument_list|(
name|Attributes
operator|::
name|InlineHint
argument_list|)
operator|||
name|hasAttribute
argument_list|(
name|Attributes
operator|::
name|StackAlignment
argument_list|)
operator|||
name|hasAttribute
argument_list|(
name|Attributes
operator|::
name|UWTable
argument_list|)
operator|||
name|hasAttribute
argument_list|(
name|Attributes
operator|::
name|NonLazyBind
argument_list|)
operator|||
name|hasAttribute
argument_list|(
name|Attributes
operator|::
name|ReturnsTwice
argument_list|)
operator|||
name|hasAttribute
argument_list|(
name|Attributes
operator|::
name|AddressSafety
argument_list|)
operator|||
name|hasAttribute
argument_list|(
name|Attributes
operator|::
name|MinSize
argument_list|)
return|;
block|}
name|bool
name|operator
operator|==
operator|(
specifier|const
name|Attributes
operator|&
name|A
operator|)
specifier|const
block|{
return|return
name|Attrs
operator|==
name|A
operator|.
name|Attrs
return|;
block|}
name|bool
name|operator
operator|!=
operator|(
specifier|const
name|Attributes
operator|&
name|A
operator|)
specifier|const
block|{
return|return
name|Attrs
operator|!=
name|A
operator|.
name|Attrs
return|;
block|}
name|uint64_t
name|Raw
argument_list|()
specifier|const
expr_stmt|;
comment|/// @brief Which attributes cannot be applied to a type.
specifier|static
name|Attributes
name|typeIncompatible
parameter_list|(
name|Type
modifier|*
name|Ty
parameter_list|)
function_decl|;
comment|/// encodeLLVMAttributesForBitcode - This returns an integer containing an
comment|/// encoding of all the LLVM attributes found in the given attribute bitset.
comment|/// Any change to this encoding is a breaking change to bitcode compatibility.
specifier|static
name|uint64_t
name|encodeLLVMAttributesForBitcode
parameter_list|(
name|Attributes
name|Attrs
parameter_list|)
function_decl|;
comment|/// decodeLLVMAttributesForBitcode - This returns an attribute bitset
comment|/// containing the LLVM attributes that have been decoded from the given
comment|/// integer.  This function must stay in sync with
comment|/// 'encodeLLVMAttributesForBitcode'.
specifier|static
name|Attributes
name|decodeLLVMAttributesForBitcode
parameter_list|(
name|LLVMContext
modifier|&
name|C
parameter_list|,
name|uint64_t
name|EncodedAttrs
parameter_list|)
function_decl|;
comment|/// getAsString - The set of Attributes set in Attributes is converted to a
comment|/// string of equivalent mnemonics. This is, presumably, for writing out the
comment|/// mnemonics for the assembly writer.
comment|/// @brief Convert attribute bits to text
name|std
operator|::
name|string
name|getAsString
argument_list|()
specifier|const
expr_stmt|;
block|}
empty_stmt|;
comment|//===----------------------------------------------------------------------===//
comment|/// AttrBuilder - This class is used in conjunction with the Attributes::get
comment|/// method to create an Attributes object. The object itself is uniquified. The
comment|/// Builder's value, however, is not. So this can be used as a quick way to test
comment|/// for equality, presence of attributes, etc.
name|class
name|AttrBuilder
block|{
name|uint64_t
name|Bits
decl_stmt|;
name|public
label|:
name|AttrBuilder
argument_list|()
operator|:
name|Bits
argument_list|(
literal|0
argument_list|)
block|{}
name|explicit
name|AttrBuilder
argument_list|(
argument|uint64_t B
argument_list|)
operator|:
name|Bits
argument_list|(
argument|B
argument_list|)
block|{}
name|AttrBuilder
argument_list|(
specifier|const
name|Attributes
operator|&
name|A
argument_list|)
operator|:
name|Bits
argument_list|(
argument|A.Raw()
argument_list|)
block|{}
name|AttrBuilder
argument_list|(
specifier|const
name|AttrBuilder
operator|&
name|B
argument_list|)
operator|:
name|Bits
argument_list|(
argument|B.Bits
argument_list|)
block|{}
name|void
name|clear
argument_list|()
block|{
name|Bits
operator|=
literal|0
block|; }
comment|/// addAttribute - Add an attribute to the builder.
name|AttrBuilder
operator|&
name|addAttribute
argument_list|(
argument|Attributes::AttrVal Val
argument_list|)
expr_stmt|;
comment|/// removeAttribute - Remove an attribute from the builder.
name|AttrBuilder
modifier|&
name|removeAttribute
argument_list|(
name|Attributes
operator|::
name|AttrVal
name|Val
argument_list|)
decl_stmt|;
comment|/// addAttribute - Add the attributes from A to the builder.
name|AttrBuilder
modifier|&
name|addAttributes
parameter_list|(
specifier|const
name|Attributes
modifier|&
name|A
parameter_list|)
function_decl|;
comment|/// removeAttribute - Remove the attributes from A from the builder.
name|AttrBuilder
modifier|&
name|removeAttributes
parameter_list|(
specifier|const
name|Attributes
modifier|&
name|A
parameter_list|)
function_decl|;
comment|/// hasAttribute - Return true if the builder has the specified attribute.
name|bool
name|hasAttribute
argument_list|(
name|Attributes
operator|::
name|AttrVal
name|A
argument_list|)
decl|const
decl_stmt|;
comment|/// hasAttributes - Return true if the builder has IR-level attributes.
name|bool
name|hasAttributes
argument_list|()
specifier|const
expr_stmt|;
comment|/// hasAttributes - Return true if the builder has any attribute that's in the
comment|/// specified attribute.
name|bool
name|hasAttributes
argument_list|(
specifier|const
name|Attributes
operator|&
name|A
argument_list|)
decl|const
decl_stmt|;
comment|/// hasAlignmentAttr - Return true if the builder has an alignment attribute.
name|bool
name|hasAlignmentAttr
argument_list|()
specifier|const
expr_stmt|;
comment|/// getAlignment - Retrieve the alignment attribute, if it exists.
name|uint64_t
name|getAlignment
argument_list|()
specifier|const
expr_stmt|;
comment|/// getStackAlignment - Retrieve the stack alignment attribute, if it exists.
name|uint64_t
name|getStackAlignment
argument_list|()
specifier|const
expr_stmt|;
comment|/// addAlignmentAttr - This turns an int alignment (which must be a power of
comment|/// 2) into the form used internally in Attributes.
name|AttrBuilder
modifier|&
name|addAlignmentAttr
parameter_list|(
name|unsigned
name|Align
parameter_list|)
function_decl|;
comment|/// addStackAlignmentAttr - This turns an int stack alignment (which must be a
comment|/// power of 2) into the form used internally in Attributes.
name|AttrBuilder
modifier|&
name|addStackAlignmentAttr
parameter_list|(
name|unsigned
name|Align
parameter_list|)
function_decl|;
comment|/// addRawValue - Add the raw value to the internal representation.
comment|/// N.B. This should be used ONLY for decoding LLVM bitcode!
name|AttrBuilder
modifier|&
name|addRawValue
parameter_list|(
name|uint64_t
name|Val
parameter_list|)
function_decl|;
comment|/// @brief Remove attributes that are used on functions only.
name|void
name|removeFunctionOnlyAttrs
parameter_list|()
block|{
name|removeAttribute
argument_list|(
name|Attributes
operator|::
name|NoReturn
argument_list|)
operator|.
name|removeAttribute
argument_list|(
name|Attributes
operator|::
name|NoUnwind
argument_list|)
operator|.
name|removeAttribute
argument_list|(
name|Attributes
operator|::
name|ReadNone
argument_list|)
operator|.
name|removeAttribute
argument_list|(
name|Attributes
operator|::
name|ReadOnly
argument_list|)
operator|.
name|removeAttribute
argument_list|(
name|Attributes
operator|::
name|NoInline
argument_list|)
operator|.
name|removeAttribute
argument_list|(
name|Attributes
operator|::
name|AlwaysInline
argument_list|)
operator|.
name|removeAttribute
argument_list|(
name|Attributes
operator|::
name|OptimizeForSize
argument_list|)
operator|.
name|removeAttribute
argument_list|(
name|Attributes
operator|::
name|StackProtect
argument_list|)
operator|.
name|removeAttribute
argument_list|(
name|Attributes
operator|::
name|StackProtectReq
argument_list|)
operator|.
name|removeAttribute
argument_list|(
name|Attributes
operator|::
name|NoRedZone
argument_list|)
operator|.
name|removeAttribute
argument_list|(
name|Attributes
operator|::
name|NoImplicitFloat
argument_list|)
operator|.
name|removeAttribute
argument_list|(
name|Attributes
operator|::
name|Naked
argument_list|)
operator|.
name|removeAttribute
argument_list|(
name|Attributes
operator|::
name|InlineHint
argument_list|)
operator|.
name|removeAttribute
argument_list|(
name|Attributes
operator|::
name|StackAlignment
argument_list|)
operator|.
name|removeAttribute
argument_list|(
name|Attributes
operator|::
name|UWTable
argument_list|)
operator|.
name|removeAttribute
argument_list|(
name|Attributes
operator|::
name|NonLazyBind
argument_list|)
operator|.
name|removeAttribute
argument_list|(
name|Attributes
operator|::
name|ReturnsTwice
argument_list|)
operator|.
name|removeAttribute
argument_list|(
name|Attributes
operator|::
name|AddressSafety
argument_list|)
operator|.
name|removeAttribute
argument_list|(
name|Attributes
operator|::
name|MinSize
argument_list|)
expr_stmt|;
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
name|bool
name|operator
operator|==
operator|(
specifier|const
name|AttrBuilder
operator|&
name|B
operator|)
block|{
return|return
name|Bits
operator|==
name|B
operator|.
name|Bits
return|;
block|}
name|bool
name|operator
operator|!=
operator|(
specifier|const
name|AttrBuilder
operator|&
name|B
operator|)
block|{
return|return
name|Bits
operator|!=
name|B
operator|.
name|Bits
return|;
block|}
block|}
empty_stmt|;
comment|//===----------------------------------------------------------------------===//
comment|// AttributeWithIndex
comment|//===----------------------------------------------------------------------===//
comment|/// AttributeWithIndex - This is just a pair of values to associate a set of
comment|/// attributes with an index.
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
argument_list|(
name|LLVMContext
operator|&
name|C
argument_list|,
name|unsigned
name|Idx
argument_list|,
name|ArrayRef
operator|<
name|Attributes
operator|::
name|AttrVal
operator|>
name|Attrs
argument_list|)
block|{
return|return
name|get
argument_list|(
name|Idx
argument_list|,
name|Attributes
operator|::
name|get
argument_list|(
name|C
argument_list|,
name|Attrs
argument_list|)
argument_list|)
return|;
block|}
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
name|public
label|:
enum|enum
name|AttrIndex
block|{
name|ReturnIndex
init|=
literal|0U
block|,
name|FunctionIndex
init|=
operator|~
literal|0U
block|}
enum|;
name|private
label|:
comment|/// @brief The attributes that we are managing.  This can be null to represent
comment|/// the empty attributes list.
name|AttributeListImpl
modifier|*
name|AttrList
decl_stmt|;
comment|/// @brief The attributes for the specified index are returned.  Attributes
comment|/// for the result are denoted with Idx = 0.
name|Attributes
name|getAttributes
argument_list|(
name|unsigned
name|Idx
argument_list|)
decl|const
decl_stmt|;
name|explicit
name|AttrListPtr
argument_list|(
name|AttributeListImpl
operator|*
name|LI
argument_list|)
operator|:
name|AttrList
argument_list|(
argument|LI
argument_list|)
block|{}
name|public
operator|:
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
operator|:
name|AttrList
argument_list|(
argument|P.AttrList
argument_list|)
block|{}
specifier|const
name|AttrListPtr
operator|&
name|operator
operator|=
operator|(
specifier|const
name|AttrListPtr
operator|&
name|RHS
operator|)
expr_stmt|;
comment|//===--------------------------------------------------------------------===//
comment|// Attribute List Construction and Mutation
comment|//===--------------------------------------------------------------------===//
comment|/// get - Return a Attributes list with the specified parameters in it.
specifier|static
name|AttrListPtr
name|get
argument_list|(
name|LLVMContext
operator|&
name|C
argument_list|,
name|ArrayRef
operator|<
name|AttributeWithIndex
operator|>
name|Attrs
argument_list|)
decl_stmt|;
comment|/// addAttr - Add the specified attribute at the specified index to this
comment|/// attribute list.  Since attribute lists are immutable, this
comment|/// returns the new list.
name|AttrListPtr
name|addAttr
argument_list|(
name|LLVMContext
operator|&
name|C
argument_list|,
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
name|LLVMContext
operator|&
name|C
argument_list|,
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
name|ReturnIndex
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
name|FunctionIndex
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
operator|.
name|hasAttributes
argument_list|(
name|Attr
argument_list|)
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
name|getAttributes
argument_list|(
name|Idx
argument_list|)
operator|.
name|getAlignment
argument_list|()
return|;
block|}
comment|/// hasAttrSomewhere - Return true if the specified attribute is set for at
comment|/// least one parameter or for the return value.
name|bool
name|hasAttrSomewhere
argument_list|(
name|Attributes
operator|::
name|AttrVal
name|Attr
argument_list|)
decl|const
decl_stmt|;
name|unsigned
name|getNumAttrs
argument_list|()
specifier|const
expr_stmt|;
name|Attributes
modifier|&
name|getAttributesAtIndex
argument_list|(
name|unsigned
name|i
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
name|void
name|dump
argument_list|()
specifier|const
expr_stmt|;
block|}
empty_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// End llvm namespace
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

