begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- llvm/Attributes.h - Container for Attributes -------------*- C++ -*-===//
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
comment|///
end_comment

begin_comment
comment|/// \file
end_comment

begin_comment
comment|/// \brief This file contains the simple types necessary to represent the
end_comment

begin_comment
comment|/// attributes associated with functions and their calls.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|LLVM_IR_ATTRIBUTES_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_IR_ATTRIBUTES_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/ArrayRef.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/FoldingSet.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/iterator_range.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/Optional.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/StringRef.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/PointerLikeTypeTraits.h"
end_include

begin_include
include|#
directive|include
file|"llvm-c/Types.h"
end_include

begin_include
include|#
directive|include
file|<bitset>
end_include

begin_include
include|#
directive|include
file|<cassert>
end_include

begin_include
include|#
directive|include
file|<cstdint>
end_include

begin_include
include|#
directive|include
file|<map>
end_include

begin_include
include|#
directive|include
file|<string>
end_include

begin_include
include|#
directive|include
file|<utility>
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|AttrBuilder
decl_stmt|;
name|class
name|AttributeImpl
decl_stmt|;
name|class
name|AttributeListImpl
decl_stmt|;
name|class
name|AttributeSetNode
decl_stmt|;
name|template
operator|<
name|typename
name|T
operator|>
expr|struct
name|DenseMapInfo
expr_stmt|;
name|class
name|Function
decl_stmt|;
name|class
name|LLVMContext
decl_stmt|;
name|class
name|Type
decl_stmt|;
comment|//===----------------------------------------------------------------------===//
comment|/// \class
comment|/// \brief Functions, function parameters, and return types can have attributes
comment|/// to indicate how they should be treated by optimizations and code
comment|/// generation. This class represents one of those attributes. It's light-weight
comment|/// and should be passed around by-value.
name|class
name|Attribute
block|{
name|public
label|:
comment|/// This enumeration lists the attributes that can be associated with
comment|/// parameters, function results, or the function itself.
comment|///
comment|/// Note: The `uwtable' attribute is about the ABI or the user mandating an
comment|/// entry in the unwind table. The `nounwind' attribute is about an exception
comment|/// passing by the function.
comment|///
comment|/// In a theoretical system that uses tables for profiling and SjLj for
comment|/// exceptions, they would be fully independent. In a normal system that uses
comment|/// tables for both, the semantics are:
comment|///
comment|/// nil                = Needs an entry because an exception might pass by.
comment|/// nounwind           = No need for an entry
comment|/// uwtable            = Needs an entry because the ABI says so and because
comment|///                      an exception might pass by.
comment|/// uwtable + nounwind = Needs an entry because the ABI says so.
enum|enum
name|AttrKind
block|{
comment|// IR-Level Attributes
name|None
block|,
comment|///< No attributes have been set
define|#
directive|define
name|GET_ATTR_ENUM
include|#
directive|include
file|"llvm/IR/Attributes.gen"
name|EndAttrKinds
comment|///< Sentinal value useful for loops
block|}
enum|;
name|private
label|:
name|AttributeImpl
modifier|*
name|pImpl
init|=
name|nullptr
decl_stmt|;
name|Attribute
argument_list|(
name|AttributeImpl
operator|*
name|A
argument_list|)
operator|:
name|pImpl
argument_list|(
argument|A
argument_list|)
block|{}
name|public
operator|:
name|Attribute
argument_list|()
operator|=
expr|default
expr_stmt|;
comment|//===--------------------------------------------------------------------===//
comment|// Attribute Construction
comment|//===--------------------------------------------------------------------===//
comment|/// \brief Return a uniquified Attribute object.
specifier|static
name|Attribute
name|get
parameter_list|(
name|LLVMContext
modifier|&
name|Context
parameter_list|,
name|AttrKind
name|Kind
parameter_list|,
name|uint64_t
name|Val
init|=
literal|0
parameter_list|)
function_decl|;
specifier|static
name|Attribute
name|get
parameter_list|(
name|LLVMContext
modifier|&
name|Context
parameter_list|,
name|StringRef
name|Kind
parameter_list|,
name|StringRef
name|Val
init|=
name|StringRef
argument_list|()
parameter_list|)
function_decl|;
comment|/// \brief Return a uniquified Attribute object that has the specific
comment|/// alignment set.
specifier|static
name|Attribute
name|getWithAlignment
parameter_list|(
name|LLVMContext
modifier|&
name|Context
parameter_list|,
name|uint64_t
name|Align
parameter_list|)
function_decl|;
specifier|static
name|Attribute
name|getWithStackAlignment
parameter_list|(
name|LLVMContext
modifier|&
name|Context
parameter_list|,
name|uint64_t
name|Align
parameter_list|)
function_decl|;
specifier|static
name|Attribute
name|getWithDereferenceableBytes
parameter_list|(
name|LLVMContext
modifier|&
name|Context
parameter_list|,
name|uint64_t
name|Bytes
parameter_list|)
function_decl|;
specifier|static
name|Attribute
name|getWithDereferenceableOrNullBytes
parameter_list|(
name|LLVMContext
modifier|&
name|Context
parameter_list|,
name|uint64_t
name|Bytes
parameter_list|)
function_decl|;
specifier|static
name|Attribute
name|getWithAllocSizeArgs
argument_list|(
name|LLVMContext
operator|&
name|Context
argument_list|,
name|unsigned
name|ElemSizeArg
argument_list|,
specifier|const
name|Optional
operator|<
name|unsigned
operator|>
operator|&
name|NumElemsArg
argument_list|)
decl_stmt|;
comment|//===--------------------------------------------------------------------===//
comment|// Attribute Accessors
comment|//===--------------------------------------------------------------------===//
comment|/// \brief Return true if the attribute is an Attribute::AttrKind type.
name|bool
name|isEnumAttribute
argument_list|()
specifier|const
expr_stmt|;
comment|/// \brief Return true if the attribute is an integer attribute.
name|bool
name|isIntAttribute
argument_list|()
specifier|const
expr_stmt|;
comment|/// \brief Return true if the attribute is a string (target-dependent)
comment|/// attribute.
name|bool
name|isStringAttribute
argument_list|()
specifier|const
expr_stmt|;
comment|/// \brief Return true if the attribute is present.
name|bool
name|hasAttribute
argument_list|(
name|AttrKind
name|Val
argument_list|)
decl|const
decl_stmt|;
comment|/// \brief Return true if the target-dependent attribute is present.
name|bool
name|hasAttribute
argument_list|(
name|StringRef
name|Val
argument_list|)
decl|const
decl_stmt|;
comment|/// \brief Return the attribute's kind as an enum (Attribute::AttrKind). This
comment|/// requires the attribute to be an enum or integer attribute.
name|Attribute
operator|::
name|AttrKind
name|getKindAsEnum
argument_list|()
specifier|const
expr_stmt|;
comment|/// \brief Return the attribute's value as an integer. This requires that the
comment|/// attribute be an integer attribute.
name|uint64_t
name|getValueAsInt
argument_list|()
specifier|const
expr_stmt|;
comment|/// \brief Return the attribute's kind as a string. This requires the
comment|/// attribute to be a string attribute.
name|StringRef
name|getKindAsString
argument_list|()
specifier|const
expr_stmt|;
comment|/// \brief Return the attribute's value as a string. This requires the
comment|/// attribute to be a string attribute.
name|StringRef
name|getValueAsString
argument_list|()
specifier|const
expr_stmt|;
comment|/// \brief Returns the alignment field of an attribute as a byte alignment
comment|/// value.
name|unsigned
name|getAlignment
argument_list|()
specifier|const
expr_stmt|;
comment|/// \brief Returns the stack alignment field of an attribute as a byte
comment|/// alignment value.
name|unsigned
name|getStackAlignment
argument_list|()
specifier|const
expr_stmt|;
comment|/// \brief Returns the number of dereferenceable bytes from the
comment|/// dereferenceable attribute.
name|uint64_t
name|getDereferenceableBytes
argument_list|()
specifier|const
expr_stmt|;
comment|/// \brief Returns the number of dereferenceable_or_null bytes from the
comment|/// dereferenceable_or_null attribute.
name|uint64_t
name|getDereferenceableOrNullBytes
argument_list|()
specifier|const
expr_stmt|;
comment|/// Returns the argument numbers for the allocsize attribute (or pair(0, 0)
comment|/// if not known).
name|std
operator|::
name|pair
operator|<
name|unsigned
operator|,
name|Optional
operator|<
name|unsigned
operator|>>
name|getAllocSizeArgs
argument_list|()
specifier|const
expr_stmt|;
comment|/// \brief The Attribute is converted to a string of equivalent mnemonic. This
comment|/// is, presumably, for writing out the mnemonics for the assembly writer.
name|std
operator|::
name|string
name|getAsString
argument_list|(
argument|bool InAttrGrp = false
argument_list|)
specifier|const
expr_stmt|;
comment|/// \brief Equality and non-equality operators.
name|bool
name|operator
operator|==
operator|(
name|Attribute
name|A
operator|)
specifier|const
block|{
return|return
name|pImpl
operator|==
name|A
operator|.
name|pImpl
return|;
block|}
name|bool
name|operator
operator|!=
operator|(
name|Attribute
name|A
operator|)
specifier|const
block|{
return|return
name|pImpl
operator|!=
name|A
operator|.
name|pImpl
return|;
block|}
comment|/// \brief Less-than operator. Useful for sorting the attributes list.
name|bool
name|operator
operator|<
operator|(
name|Attribute
name|A
operator|)
specifier|const
expr_stmt|;
name|void
name|Profile
argument_list|(
name|FoldingSetNodeID
operator|&
name|ID
argument_list|)
decl|const
block|{
name|ID
operator|.
name|AddPointer
argument_list|(
name|pImpl
argument_list|)
expr_stmt|;
block|}
comment|/// \brief Return a raw pointer that uniquely identifies this attribute.
name|void
operator|*
name|getRawPointer
argument_list|()
specifier|const
block|{
return|return
name|pImpl
return|;
block|}
comment|/// \brief Get an attribute from a raw pointer created by getRawPointer.
specifier|static
name|Attribute
name|fromRawPointer
parameter_list|(
name|void
modifier|*
name|RawPtr
parameter_list|)
block|{
return|return
name|Attribute
argument_list|(
name|reinterpret_cast
operator|<
name|AttributeImpl
operator|*
operator|>
operator|(
name|RawPtr
operator|)
argument_list|)
return|;
block|}
block|}
empty_stmt|;
comment|// Specialized opaque value conversions.
specifier|inline
name|LLVMAttributeRef
name|wrap
parameter_list|(
name|Attribute
name|Attr
parameter_list|)
block|{
return|return
name|reinterpret_cast
operator|<
name|LLVMAttributeRef
operator|>
operator|(
name|Attr
operator|.
name|getRawPointer
argument_list|()
operator|)
return|;
block|}
comment|// Specialized opaque value conversions.
specifier|inline
name|Attribute
name|unwrap
parameter_list|(
name|LLVMAttributeRef
name|Attr
parameter_list|)
block|{
return|return
name|Attribute
operator|::
name|fromRawPointer
argument_list|(
name|Attr
argument_list|)
return|;
block|}
comment|//===----------------------------------------------------------------------===//
comment|/// \class
comment|/// This class holds the attributes for a particular argument, parameter,
comment|/// function, or return value. It is an immutable value type that is cheap to
comment|/// copy. Adding and removing enum attributes is intended to be fast, but adding
comment|/// and removing string or integer attributes involves a FoldingSet lookup.
name|class
name|AttributeSet
block|{
comment|// TODO: Extract AvailableAttrs from AttributeSetNode and store them here.
comment|// This will allow an efficient implementation of addAttribute and
comment|// removeAttribute for enum attrs.
comment|/// Private implementation pointer.
name|AttributeSetNode
modifier|*
name|SetNode
init|=
name|nullptr
decl_stmt|;
name|friend
name|AttributeListImpl
decl_stmt|;
name|template
operator|<
name|typename
name|Ty
operator|>
name|friend
expr|struct
name|DenseMapInfo
expr_stmt|;
name|private
label|:
name|explicit
name|AttributeSet
argument_list|(
name|AttributeSetNode
operator|*
name|ASN
argument_list|)
operator|:
name|SetNode
argument_list|(
argument|ASN
argument_list|)
block|{}
name|public
operator|:
comment|/// AttributeSet is a trivially copyable value type.
name|AttributeSet
argument_list|()
operator|=
expr|default
expr_stmt|;
name|AttributeSet
argument_list|(
specifier|const
name|AttributeSet
operator|&
argument_list|)
operator|=
expr|default
expr_stmt|;
operator|~
name|AttributeSet
argument_list|()
operator|=
expr|default
expr_stmt|;
specifier|static
name|AttributeSet
name|get
parameter_list|(
name|LLVMContext
modifier|&
name|C
parameter_list|,
specifier|const
name|AttrBuilder
modifier|&
name|B
parameter_list|)
function_decl|;
specifier|static
name|AttributeSet
name|get
argument_list|(
name|LLVMContext
operator|&
name|C
argument_list|,
name|ArrayRef
operator|<
name|Attribute
operator|>
name|Attrs
argument_list|)
decl_stmt|;
name|bool
name|operator
operator|==
operator|(
specifier|const
name|AttributeSet
operator|&
name|O
operator|)
block|{
return|return
name|SetNode
operator|==
name|O
operator|.
name|SetNode
return|;
block|}
name|bool
name|operator
operator|!=
operator|(
specifier|const
name|AttributeSet
operator|&
name|O
operator|)
block|{
return|return
operator|!
operator|(
operator|*
name|this
operator|==
name|O
operator|)
return|;
block|}
name|unsigned
name|getNumAttributes
argument_list|()
specifier|const
expr_stmt|;
name|bool
name|hasAttributes
argument_list|()
specifier|const
block|{
return|return
name|SetNode
operator|!=
name|nullptr
return|;
block|}
name|bool
name|hasAttribute
argument_list|(
name|Attribute
operator|::
name|AttrKind
name|Kind
argument_list|)
decl|const
decl_stmt|;
name|bool
name|hasAttribute
argument_list|(
name|StringRef
name|Kind
argument_list|)
decl|const
decl_stmt|;
name|Attribute
name|getAttribute
argument_list|(
name|Attribute
operator|::
name|AttrKind
name|Kind
argument_list|)
decl|const
decl_stmt|;
name|Attribute
name|getAttribute
argument_list|(
name|StringRef
name|Kind
argument_list|)
decl|const
decl_stmt|;
name|unsigned
name|getAlignment
argument_list|()
specifier|const
expr_stmt|;
name|unsigned
name|getStackAlignment
argument_list|()
specifier|const
expr_stmt|;
name|uint64_t
name|getDereferenceableBytes
argument_list|()
specifier|const
expr_stmt|;
name|uint64_t
name|getDereferenceableOrNullBytes
argument_list|()
specifier|const
expr_stmt|;
name|std
operator|::
name|pair
operator|<
name|unsigned
operator|,
name|Optional
operator|<
name|unsigned
operator|>>
name|getAllocSizeArgs
argument_list|()
specifier|const
expr_stmt|;
name|std
operator|::
name|string
name|getAsString
argument_list|(
argument|bool InAttrGrp = false
argument_list|)
specifier|const
expr_stmt|;
typedef|typedef
specifier|const
name|Attribute
modifier|*
name|iterator
typedef|;
name|iterator
name|begin
argument_list|()
specifier|const
expr_stmt|;
name|iterator
name|end
argument_list|()
specifier|const
expr_stmt|;
block|}
empty_stmt|;
comment|//===----------------------------------------------------------------------===//
comment|/// \class
comment|/// \brief Provide DenseMapInfo for AttributeSet.
name|template
operator|<
operator|>
expr|struct
name|DenseMapInfo
operator|<
name|AttributeSet
operator|>
block|{
specifier|static
specifier|inline
name|AttributeSet
name|getEmptyKey
argument_list|()
block|{
name|uintptr_t
name|Val
operator|=
name|static_cast
operator|<
name|uintptr_t
operator|>
operator|(
operator|-
literal|1
operator|)
block|;
name|Val
operator|<<=
name|PointerLikeTypeTraits
operator|<
name|void
operator|*
operator|>
operator|::
name|NumLowBitsAvailable
block|;
return|return
name|AttributeSet
argument_list|(
name|reinterpret_cast
operator|<
name|AttributeSetNode
operator|*
operator|>
operator|(
name|Val
operator|)
argument_list|)
return|;
block|}
specifier|static
specifier|inline
name|AttributeSet
name|getTombstoneKey
argument_list|()
block|{
name|uintptr_t
name|Val
operator|=
name|static_cast
operator|<
name|uintptr_t
operator|>
operator|(
operator|-
literal|2
operator|)
block|;
name|Val
operator|<<=
name|PointerLikeTypeTraits
operator|<
name|void
operator|*
operator|>
operator|::
name|NumLowBitsAvailable
block|;
return|return
name|AttributeSet
argument_list|(
name|reinterpret_cast
operator|<
name|AttributeSetNode
operator|*
operator|>
operator|(
name|Val
operator|)
argument_list|)
return|;
block|}
specifier|static
name|unsigned
name|getHashValue
argument_list|(
argument|AttributeSet AS
argument_list|)
block|{
return|return
operator|(
name|unsigned
argument_list|(
operator|(
name|uintptr_t
operator|)
name|AS
operator|.
name|SetNode
argument_list|)
operator|>>
literal|4
operator|)
operator|^
operator|(
name|unsigned
argument_list|(
operator|(
name|uintptr_t
operator|)
name|AS
operator|.
name|SetNode
argument_list|)
operator|>>
literal|9
operator|)
return|;
block|}
specifier|static
name|bool
name|isEqual
argument_list|(
argument|AttributeSet LHS
argument_list|,
argument|AttributeSet RHS
argument_list|)
block|{
return|return
name|LHS
operator|==
name|RHS
return|;
block|}
expr|}
block|;
comment|//===----------------------------------------------------------------------===//
comment|/// \class
comment|/// \brief This class holds the attributes for a function, its return value, and
comment|/// its parameters. You access the attributes for each of them via an index into
comment|/// the AttributeList object. The function attributes are at index
comment|/// `AttributeList::FunctionIndex', the return value is at index
comment|/// `AttributeList::ReturnIndex', and the attributes for the parameters start at
comment|/// index `1'.
name|class
name|AttributeList
block|{
name|public
operator|:
expr|enum
name|AttrIndex
operator|:
name|unsigned
block|{
name|ReturnIndex
operator|=
literal|0U
block|,
name|FunctionIndex
operator|=
operator|~
literal|0U
block|}
block|;
name|private
operator|:
name|friend
name|class
name|AttrBuilder
block|;
name|friend
name|class
name|AttributeListImpl
block|;
name|friend
name|class
name|AttributeSet
block|;
name|friend
name|class
name|AttributeSetNode
block|;
name|template
operator|<
name|typename
name|Ty
operator|>
name|friend
expr|struct
name|DenseMapInfo
block|;
comment|/// \brief The attributes that we are managing. This can be null to represent
comment|/// the empty attributes list.
name|AttributeListImpl
operator|*
name|pImpl
operator|=
name|nullptr
block|;
name|public
operator|:
comment|/// \brief Create an AttributeList with the specified parameters in it.
specifier|static
name|AttributeList
name|get
argument_list|(
name|LLVMContext
operator|&
name|C
argument_list|,
name|ArrayRef
operator|<
name|std
operator|::
name|pair
operator|<
name|unsigned
argument_list|,
name|Attribute
operator|>>
name|Attrs
argument_list|)
block|;
specifier|static
name|AttributeList
name|get
argument_list|(
name|LLVMContext
operator|&
name|C
argument_list|,
name|ArrayRef
operator|<
name|std
operator|::
name|pair
operator|<
name|unsigned
argument_list|,
name|AttributeSet
operator|>>
name|Attrs
argument_list|)
block|;
comment|/// \brief Create an AttributeList from attribute sets for a function, its
comment|/// return value, and all of its arguments.
specifier|static
name|AttributeList
name|get
argument_list|(
argument|LLVMContext&C
argument_list|,
argument|AttributeSet FnAttrs
argument_list|,
argument|AttributeSet RetAttrs
argument_list|,
argument|ArrayRef<AttributeSet> ArgAttrs
argument_list|)
block|;
specifier|static
name|AttributeList
name|getImpl
argument_list|(
name|LLVMContext
operator|&
name|C
argument_list|,
name|ArrayRef
operator|<
name|std
operator|::
name|pair
operator|<
name|unsigned
argument_list|,
name|AttributeSet
operator|>>
name|Attrs
argument_list|)
block|;
name|private
operator|:
name|explicit
name|AttributeList
argument_list|(
name|AttributeListImpl
operator|*
name|LI
argument_list|)
operator|:
name|pImpl
argument_list|(
argument|LI
argument_list|)
block|{}
name|public
operator|:
name|AttributeList
argument_list|()
operator|=
expr|default
block|;
comment|//===--------------------------------------------------------------------===//
comment|// AttributeList Construction and Mutation
comment|//===--------------------------------------------------------------------===//
comment|/// \brief Return an AttributeList with the specified parameters in it.
specifier|static
name|AttributeList
name|get
argument_list|(
name|LLVMContext
operator|&
name|C
argument_list|,
name|ArrayRef
operator|<
name|AttributeList
operator|>
name|Attrs
argument_list|)
block|;
specifier|static
name|AttributeList
name|get
argument_list|(
argument|LLVMContext&C
argument_list|,
argument|unsigned Index
argument_list|,
argument|ArrayRef<Attribute::AttrKind> Kinds
argument_list|)
block|;
specifier|static
name|AttributeList
name|get
argument_list|(
argument|LLVMContext&C
argument_list|,
argument|unsigned Index
argument_list|,
argument|ArrayRef<StringRef> Kind
argument_list|)
block|;
specifier|static
name|AttributeList
name|get
argument_list|(
argument|LLVMContext&C
argument_list|,
argument|unsigned Index
argument_list|,
argument|const AttrBuilder&B
argument_list|)
block|;
comment|/// \brief Add an attribute to the attribute set at the given index. Because
comment|/// attribute sets are immutable, this returns a new set.
name|AttributeList
name|addAttribute
argument_list|(
argument|LLVMContext&C
argument_list|,
argument|unsigned Index
argument_list|,
argument|Attribute::AttrKind Kind
argument_list|)
specifier|const
block|;
comment|/// \brief Add an attribute to the attribute set at the given index. Because
comment|/// attribute sets are immutable, this returns a new set.
name|AttributeList
name|addAttribute
argument_list|(
argument|LLVMContext&C
argument_list|,
argument|unsigned Index
argument_list|,
argument|StringRef Kind
argument_list|,
argument|StringRef Value = StringRef()
argument_list|)
specifier|const
block|;
comment|/// Add an attribute to the attribute set at the given indices. Because
comment|/// attribute sets are immutable, this returns a new set.
name|AttributeList
name|addAttribute
argument_list|(
argument|LLVMContext&C
argument_list|,
argument|ArrayRef<unsigned> Indices
argument_list|,
argument|Attribute A
argument_list|)
specifier|const
block|;
comment|/// \brief Add attributes to the attribute set at the given index. Because
comment|/// attribute sets are immutable, this returns a new set.
name|AttributeList
name|addAttributes
argument_list|(
argument|LLVMContext&C
argument_list|,
argument|unsigned Index
argument_list|,
argument|AttributeList Attrs
argument_list|)
specifier|const
block|;
name|AttributeList
name|addAttributes
argument_list|(
argument|LLVMContext&C
argument_list|,
argument|unsigned Index
argument_list|,
argument|const AttrBuilder&B
argument_list|)
specifier|const
block|;
comment|/// \brief Remove the specified attribute at the specified index from this
comment|/// attribute list. Because attribute lists are immutable, this returns the
comment|/// new list.
name|AttributeList
name|removeAttribute
argument_list|(
argument|LLVMContext&C
argument_list|,
argument|unsigned Index
argument_list|,
argument|Attribute::AttrKind Kind
argument_list|)
specifier|const
block|;
comment|/// \brief Remove the specified attribute at the specified index from this
comment|/// attribute list. Because attribute lists are immutable, this returns the
comment|/// new list.
name|AttributeList
name|removeAttribute
argument_list|(
argument|LLVMContext&C
argument_list|,
argument|unsigned Index
argument_list|,
argument|StringRef Kind
argument_list|)
specifier|const
block|;
comment|/// \brief Remove the specified attributes at the specified index from this
comment|/// attribute list. Because attribute lists are immutable, this returns the
comment|/// new list.
name|AttributeList
name|removeAttributes
argument_list|(
argument|LLVMContext&C
argument_list|,
argument|unsigned Index
argument_list|,
argument|AttributeList Attrs
argument_list|)
specifier|const
block|;
comment|/// \brief Remove the specified attributes at the specified index from this
comment|/// attribute list. Because attribute lists are immutable, this returns the
comment|/// new list.
name|AttributeList
name|removeAttributes
argument_list|(
argument|LLVMContext&C
argument_list|,
argument|unsigned Index
argument_list|,
argument|const AttrBuilder&Attrs
argument_list|)
specifier|const
block|;
comment|/// \brief Remove all attributes at the specified index from this
comment|/// attribute list. Because attribute lists are immutable, this returns the
comment|/// new list.
name|AttributeList
name|removeAttributes
argument_list|(
argument|LLVMContext&C
argument_list|,
argument|unsigned Index
argument_list|)
specifier|const
block|;
comment|/// \brief Add the dereferenceable attribute to the attribute set at the given
comment|/// index. Because attribute sets are immutable, this returns a new set.
name|AttributeList
name|addDereferenceableAttr
argument_list|(
argument|LLVMContext&C
argument_list|,
argument|unsigned Index
argument_list|,
argument|uint64_t Bytes
argument_list|)
specifier|const
block|;
comment|/// \brief Add the dereferenceable_or_null attribute to the attribute set at
comment|/// the given index. Because attribute sets are immutable, this returns a new
comment|/// set.
name|AttributeList
name|addDereferenceableOrNullAttr
argument_list|(
argument|LLVMContext&C
argument_list|,
argument|unsigned Index
argument_list|,
argument|uint64_t Bytes
argument_list|)
specifier|const
block|;
comment|/// Add the allocsize attribute to the attribute set at the given index.
comment|/// Because attribute sets are immutable, this returns a new set.
name|AttributeList
name|addAllocSizeAttr
argument_list|(
argument|LLVMContext&C
argument_list|,
argument|unsigned Index
argument_list|,
argument|unsigned ElemSizeArg
argument_list|,
argument|const Optional<unsigned>&NumElemsArg
argument_list|)
block|;
comment|//===--------------------------------------------------------------------===//
comment|// AttributeList Accessors
comment|//===--------------------------------------------------------------------===//
comment|/// \brief Retrieve the LLVM context.
name|LLVMContext
operator|&
name|getContext
argument_list|()
specifier|const
block|;
comment|/// \brief The attributes for the specified index are returned.
name|AttributeSet
name|getAttributes
argument_list|(
argument|unsigned Index
argument_list|)
specifier|const
block|;
comment|/// \brief The attributes for the argument or parameter at the given index are
comment|/// returned.
name|AttributeSet
name|getParamAttributes
argument_list|(
argument|unsigned ArgNo
argument_list|)
specifier|const
block|;
comment|/// \brief The attributes for the ret value are returned.
name|AttributeSet
name|getRetAttributes
argument_list|()
specifier|const
block|;
comment|/// \brief The function attributes are returned.
name|AttributeSet
name|getFnAttributes
argument_list|()
specifier|const
block|;
comment|/// \brief Return true if the attribute exists at the given index.
name|bool
name|hasAttribute
argument_list|(
argument|unsigned Index
argument_list|,
argument|Attribute::AttrKind Kind
argument_list|)
specifier|const
block|;
comment|/// \brief Return true if the attribute exists at the given index.
name|bool
name|hasAttribute
argument_list|(
argument|unsigned Index
argument_list|,
argument|StringRef Kind
argument_list|)
specifier|const
block|;
comment|/// \brief Return true if attribute exists at the given index.
name|bool
name|hasAttributes
argument_list|(
argument|unsigned Index
argument_list|)
specifier|const
block|;
comment|/// \brief Equivalent to hasAttribute(AttributeList::FunctionIndex, Kind) but
comment|/// may be faster.
name|bool
name|hasFnAttribute
argument_list|(
argument|Attribute::AttrKind Kind
argument_list|)
specifier|const
block|;
comment|/// \brief Equivalent to hasAttribute(AttributeList::FunctionIndex, Kind) but
comment|/// may be faster.
name|bool
name|hasFnAttribute
argument_list|(
argument|StringRef Kind
argument_list|)
specifier|const
block|;
comment|/// \brief Equivalent to hasAttribute(ArgNo + 1, Kind).
name|bool
name|hasParamAttribute
argument_list|(
argument|unsigned ArgNo
argument_list|,
argument|Attribute::AttrKind Kind
argument_list|)
specifier|const
block|;
comment|/// \brief Return true if the specified attribute is set for at least one
comment|/// parameter or for the return value. If Index is not nullptr, the index
comment|/// of a parameter with the specified attribute is provided.
name|bool
name|hasAttrSomewhere
argument_list|(
argument|Attribute::AttrKind Kind
argument_list|,
argument|unsigned *Index = nullptr
argument_list|)
specifier|const
block|;
comment|/// \brief Return the attribute object that exists at the given index.
name|Attribute
name|getAttribute
argument_list|(
argument|unsigned Index
argument_list|,
argument|Attribute::AttrKind Kind
argument_list|)
specifier|const
block|;
comment|/// \brief Return the attribute object that exists at the given index.
name|Attribute
name|getAttribute
argument_list|(
argument|unsigned Index
argument_list|,
argument|StringRef Kind
argument_list|)
specifier|const
block|;
comment|/// \brief Return the alignment for the specified function parameter.
name|unsigned
name|getParamAlignment
argument_list|(
argument|unsigned Index
argument_list|)
specifier|const
block|;
comment|/// \brief Get the stack alignment.
name|unsigned
name|getStackAlignment
argument_list|(
argument|unsigned Index
argument_list|)
specifier|const
block|;
comment|/// \brief Get the number of dereferenceable bytes (or zero if unknown).
name|uint64_t
name|getDereferenceableBytes
argument_list|(
argument|unsigned Index
argument_list|)
specifier|const
block|;
comment|/// \brief Get the number of dereferenceable_or_null bytes (or zero if
comment|/// unknown).
name|uint64_t
name|getDereferenceableOrNullBytes
argument_list|(
argument|unsigned Index
argument_list|)
specifier|const
block|;
comment|/// Get the allocsize argument numbers (or pair(0, 0) if unknown).
name|std
operator|::
name|pair
operator|<
name|unsigned
block|,
name|Optional
operator|<
name|unsigned
operator|>>
name|getAllocSizeArgs
argument_list|(
argument|unsigned Index
argument_list|)
specifier|const
block|;
comment|/// \brief Return the attributes at the index as a string.
name|std
operator|::
name|string
name|getAsString
argument_list|(
argument|unsigned Index
argument_list|,
argument|bool InAttrGrp = false
argument_list|)
specifier|const
block|;
typedef|typedef
name|ArrayRef
operator|<
name|Attribute
operator|>
operator|::
name|iterator
name|iterator
expr_stmt|;
name|iterator
name|begin
argument_list|(
argument|unsigned Slot
argument_list|)
specifier|const
block|;
name|iterator
name|end
argument_list|(
argument|unsigned Slot
argument_list|)
specifier|const
block|;
comment|/// operator==/!= - Provide equality predicates.
name|bool
name|operator
operator|==
operator|(
specifier|const
name|AttributeList
operator|&
name|RHS
operator|)
specifier|const
block|{
return|return
name|pImpl
operator|==
name|RHS
operator|.
name|pImpl
return|;
block|}
name|bool
name|operator
operator|!=
operator|(
specifier|const
name|AttributeList
operator|&
name|RHS
operator|)
specifier|const
block|{
return|return
name|pImpl
operator|!=
name|RHS
operator|.
name|pImpl
return|;
block|}
comment|//===--------------------------------------------------------------------===//
comment|// AttributeList Introspection
comment|//===--------------------------------------------------------------------===//
comment|/// \brief Return a raw pointer that uniquely identifies this attribute list.
name|void
operator|*
name|getRawPointer
argument_list|()
specifier|const
block|{
return|return
name|pImpl
return|;
block|}
comment|/// \brief Return true if there are no attributes.
name|bool
name|isEmpty
argument_list|()
specifier|const
block|{
return|return
name|getNumSlots
argument_list|()
operator|==
literal|0
return|;
block|}
comment|/// \brief Return the number of slots used in this attribute list.  This is
comment|/// the number of arguments that have an attribute set on them (including the
comment|/// function itself).
name|unsigned
name|getNumSlots
argument_list|()
specifier|const
block|;
comment|/// \brief Return the index for the given slot.
name|unsigned
name|getSlotIndex
argument_list|(
argument|unsigned Slot
argument_list|)
specifier|const
block|;
comment|/// \brief Return the attributes at the given slot.
name|AttributeSet
name|getSlotAttributes
argument_list|(
argument|unsigned Slot
argument_list|)
specifier|const
block|;
name|void
name|dump
argument_list|()
specifier|const
block|; }
expr_stmt|;
comment|//===----------------------------------------------------------------------===//
comment|/// \class
comment|/// \brief Provide DenseMapInfo for AttributeList.
name|template
operator|<
operator|>
expr|struct
name|DenseMapInfo
operator|<
name|AttributeList
operator|>
block|{
specifier|static
specifier|inline
name|AttributeList
name|getEmptyKey
argument_list|()
block|{
name|uintptr_t
name|Val
operator|=
name|static_cast
operator|<
name|uintptr_t
operator|>
operator|(
operator|-
literal|1
operator|)
block|;
name|Val
operator|<<=
name|PointerLikeTypeTraits
operator|<
name|void
operator|*
operator|>
operator|::
name|NumLowBitsAvailable
block|;
return|return
name|AttributeList
argument_list|(
name|reinterpret_cast
operator|<
name|AttributeListImpl
operator|*
operator|>
operator|(
name|Val
operator|)
argument_list|)
return|;
block|}
specifier|static
specifier|inline
name|AttributeList
name|getTombstoneKey
argument_list|()
block|{
name|uintptr_t
name|Val
operator|=
name|static_cast
operator|<
name|uintptr_t
operator|>
operator|(
operator|-
literal|2
operator|)
block|;
name|Val
operator|<<=
name|PointerLikeTypeTraits
operator|<
name|void
operator|*
operator|>
operator|::
name|NumLowBitsAvailable
block|;
return|return
name|AttributeList
argument_list|(
name|reinterpret_cast
operator|<
name|AttributeListImpl
operator|*
operator|>
operator|(
name|Val
operator|)
argument_list|)
return|;
block|}
specifier|static
name|unsigned
name|getHashValue
argument_list|(
argument|AttributeList AS
argument_list|)
block|{
return|return
operator|(
name|unsigned
argument_list|(
operator|(
name|uintptr_t
operator|)
name|AS
operator|.
name|pImpl
argument_list|)
operator|>>
literal|4
operator|)
operator|^
operator|(
name|unsigned
argument_list|(
operator|(
name|uintptr_t
operator|)
name|AS
operator|.
name|pImpl
argument_list|)
operator|>>
literal|9
operator|)
return|;
block|}
specifier|static
name|bool
name|isEqual
argument_list|(
argument|AttributeList LHS
argument_list|,
argument|AttributeList RHS
argument_list|)
block|{
return|return
name|LHS
operator|==
name|RHS
return|;
block|}
expr|}
block|;
comment|//===----------------------------------------------------------------------===//
comment|/// \class
comment|/// \brief This class is used in conjunction with the Attribute::get method to
comment|/// create an Attribute object. The object itself is uniquified. The Builder's
comment|/// value, however, is not. So this can be used as a quick way to test for
comment|/// equality, presence of attributes, etc.
name|class
name|AttrBuilder
block|{
name|std
operator|::
name|bitset
operator|<
name|Attribute
operator|::
name|EndAttrKinds
operator|>
name|Attrs
block|;
name|std
operator|::
name|map
operator|<
name|std
operator|::
name|string
block|,
name|std
operator|::
name|string
operator|>
name|TargetDepAttrs
block|;
name|uint64_t
name|Alignment
operator|=
literal|0
block|;
name|uint64_t
name|StackAlignment
operator|=
literal|0
block|;
name|uint64_t
name|DerefBytes
operator|=
literal|0
block|;
name|uint64_t
name|DerefOrNullBytes
operator|=
literal|0
block|;
name|uint64_t
name|AllocSizeArgs
operator|=
literal|0
block|;
name|public
operator|:
name|AttrBuilder
argument_list|()
operator|=
expr|default
block|;
name|AttrBuilder
argument_list|(
argument|const Attribute&A
argument_list|)
block|{
name|addAttribute
argument_list|(
name|A
argument_list|)
block|;   }
name|AttrBuilder
argument_list|(
argument|AttributeList AS
argument_list|,
argument|unsigned Idx
argument_list|)
block|;
name|AttrBuilder
argument_list|(
argument|AttributeSet AS
argument_list|)
block|;
name|void
name|clear
argument_list|()
block|;
comment|/// \brief Add an attribute to the builder.
name|AttrBuilder
operator|&
name|addAttribute
argument_list|(
argument|Attribute::AttrKind Val
argument_list|)
block|;
comment|/// \brief Add the Attribute object to the builder.
name|AttrBuilder
operator|&
name|addAttribute
argument_list|(
argument|Attribute A
argument_list|)
block|;
comment|/// \brief Add the target-dependent attribute to the builder.
name|AttrBuilder
operator|&
name|addAttribute
argument_list|(
argument|StringRef A
argument_list|,
argument|StringRef V = StringRef()
argument_list|)
block|;
comment|/// \brief Remove an attribute from the builder.
name|AttrBuilder
operator|&
name|removeAttribute
argument_list|(
argument|Attribute::AttrKind Val
argument_list|)
block|;
comment|/// \brief Remove the attributes from the builder.
name|AttrBuilder
operator|&
name|removeAttributes
argument_list|(
argument|AttributeList A
argument_list|,
argument|uint64_t WithoutIndex
argument_list|)
block|;
comment|/// \brief Remove the target-dependent attribute to the builder.
name|AttrBuilder
operator|&
name|removeAttribute
argument_list|(
argument|StringRef A
argument_list|)
block|;
comment|/// \brief Add the attributes from the builder.
name|AttrBuilder
operator|&
name|merge
argument_list|(
specifier|const
name|AttrBuilder
operator|&
name|B
argument_list|)
block|;
comment|/// \brief Remove the attributes from the builder.
name|AttrBuilder
operator|&
name|remove
argument_list|(
specifier|const
name|AttrBuilder
operator|&
name|B
argument_list|)
block|;
comment|/// \brief Return true if the builder has any attribute that's in the
comment|/// specified builder.
name|bool
name|overlaps
argument_list|(
argument|const AttrBuilder&B
argument_list|)
specifier|const
block|;
comment|/// \brief Return true if the builder has the specified attribute.
name|bool
name|contains
argument_list|(
argument|Attribute::AttrKind A
argument_list|)
specifier|const
block|{
name|assert
argument_list|(
operator|(
name|unsigned
operator|)
name|A
operator|<
name|Attribute
operator|::
name|EndAttrKinds
operator|&&
literal|"Attribute out of range!"
argument_list|)
block|;
return|return
name|Attrs
index|[
name|A
index|]
return|;
block|}
comment|/// \brief Return true if the builder has the specified target-dependent
comment|/// attribute.
name|bool
name|contains
argument_list|(
argument|StringRef A
argument_list|)
specifier|const
block|;
comment|/// \brief Return true if the builder has IR-level attributes.
name|bool
name|hasAttributes
argument_list|()
specifier|const
block|;
comment|/// \brief Return true if the builder has any attribute that's in the
comment|/// specified attribute.
name|bool
name|hasAttributes
argument_list|(
argument|AttributeList A
argument_list|,
argument|uint64_t Index
argument_list|)
specifier|const
block|;
comment|/// \brief Return true if the builder has an alignment attribute.
name|bool
name|hasAlignmentAttr
argument_list|()
specifier|const
block|;
comment|/// \brief Retrieve the alignment attribute, if it exists.
name|uint64_t
name|getAlignment
argument_list|()
specifier|const
block|{
return|return
name|Alignment
return|;
block|}
comment|/// \brief Retrieve the stack alignment attribute, if it exists.
name|uint64_t
name|getStackAlignment
argument_list|()
specifier|const
block|{
return|return
name|StackAlignment
return|;
block|}
comment|/// \brief Retrieve the number of dereferenceable bytes, if the
comment|/// dereferenceable attribute exists (zero is returned otherwise).
name|uint64_t
name|getDereferenceableBytes
argument_list|()
specifier|const
block|{
return|return
name|DerefBytes
return|;
block|}
comment|/// \brief Retrieve the number of dereferenceable_or_null bytes, if the
comment|/// dereferenceable_or_null attribute exists (zero is returned otherwise).
name|uint64_t
name|getDereferenceableOrNullBytes
argument_list|()
specifier|const
block|{
return|return
name|DerefOrNullBytes
return|;
block|}
comment|/// Retrieve the allocsize args, if the allocsize attribute exists.  If it
comment|/// doesn't exist, pair(0, 0) is returned.
name|std
operator|::
name|pair
operator|<
name|unsigned
block|,
name|Optional
operator|<
name|unsigned
operator|>>
name|getAllocSizeArgs
argument_list|()
specifier|const
block|;
comment|/// \brief This turns an int alignment (which must be a power of 2) into the
comment|/// form used internally in Attribute.
name|AttrBuilder
operator|&
name|addAlignmentAttr
argument_list|(
argument|unsigned Align
argument_list|)
block|;
comment|/// \brief This turns an int stack alignment (which must be a power of 2) into
comment|/// the form used internally in Attribute.
name|AttrBuilder
operator|&
name|addStackAlignmentAttr
argument_list|(
argument|unsigned Align
argument_list|)
block|;
comment|/// \brief This turns the number of dereferenceable bytes into the form used
comment|/// internally in Attribute.
name|AttrBuilder
operator|&
name|addDereferenceableAttr
argument_list|(
argument|uint64_t Bytes
argument_list|)
block|;
comment|/// \brief This turns the number of dereferenceable_or_null bytes into the
comment|/// form used internally in Attribute.
name|AttrBuilder
operator|&
name|addDereferenceableOrNullAttr
argument_list|(
argument|uint64_t Bytes
argument_list|)
block|;
comment|/// This turns one (or two) ints into the form used internally in Attribute.
name|AttrBuilder
operator|&
name|addAllocSizeAttr
argument_list|(
argument|unsigned ElemSizeArg
argument_list|,
argument|const Optional<unsigned>&NumElemsArg
argument_list|)
block|;
comment|/// Add an allocsize attribute, using the representation returned by
comment|/// Attribute.getIntValue().
name|AttrBuilder
operator|&
name|addAllocSizeAttrFromRawRepr
argument_list|(
argument|uint64_t RawAllocSizeRepr
argument_list|)
block|;
comment|/// \brief Return true if the builder contains no target-independent
comment|/// attributes.
name|bool
name|empty
argument_list|()
specifier|const
block|{
return|return
name|Attrs
operator|.
name|none
argument_list|()
return|;
block|}
comment|// Iterators for target-dependent attributes.
typedef|typedef
name|std
operator|::
name|pair
operator|<
name|std
operator|::
name|string
operator|,
name|std
operator|::
name|string
operator|>
name|td_type
expr_stmt|;
typedef|typedef
name|std
operator|::
name|map
operator|<
name|std
operator|::
name|string
operator|,
name|std
operator|::
name|string
operator|>
operator|::
name|iterator
name|td_iterator
expr_stmt|;
typedef|typedef
name|std
operator|::
name|map
operator|<
name|std
operator|::
name|string
operator|,
name|std
operator|::
name|string
operator|>
operator|::
name|const_iterator
name|td_const_iterator
expr_stmt|;
typedef|typedef
name|iterator_range
operator|<
name|td_iterator
operator|>
name|td_range
expr_stmt|;
typedef|typedef
name|iterator_range
operator|<
name|td_const_iterator
operator|>
name|td_const_range
expr_stmt|;
name|td_iterator
name|td_begin
parameter_list|()
block|{
return|return
name|TargetDepAttrs
operator|.
name|begin
argument_list|()
return|;
block|}
name|td_iterator
name|td_end
parameter_list|()
block|{
return|return
name|TargetDepAttrs
operator|.
name|end
argument_list|()
return|;
block|}
name|td_const_iterator
name|td_begin
argument_list|()
specifier|const
block|{
return|return
name|TargetDepAttrs
operator|.
name|begin
argument_list|()
return|;
block|}
name|td_const_iterator
name|td_end
argument_list|()
specifier|const
block|{
return|return
name|TargetDepAttrs
operator|.
name|end
argument_list|()
return|;
block|}
name|td_range
name|td_attrs
parameter_list|()
block|{
return|return
name|td_range
argument_list|(
name|td_begin
argument_list|()
argument_list|,
name|td_end
argument_list|()
argument_list|)
return|;
block|}
name|td_const_range
name|td_attrs
argument_list|()
specifier|const
block|{
return|return
name|td_const_range
argument_list|(
name|td_begin
argument_list|()
argument_list|,
name|td_end
argument_list|()
argument_list|)
return|;
block|}
name|bool
name|td_empty
argument_list|()
specifier|const
block|{
return|return
name|TargetDepAttrs
operator|.
name|empty
argument_list|()
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
expr_stmt|;
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
operator|!
operator|(
operator|*
name|this
operator|==
name|B
operator|)
return|;
block|}
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_decl_stmt
name|namespace
name|AttributeFuncs
block|{
comment|/// \brief Which attributes cannot be applied to a type.
name|AttrBuilder
name|typeIncompatible
parameter_list|(
name|Type
modifier|*
name|Ty
parameter_list|)
function_decl|;
comment|/// \returns Return true if the two functions have compatible target-independent
comment|/// attributes for inlining purposes.
name|bool
name|areInlineCompatible
parameter_list|(
specifier|const
name|Function
modifier|&
name|Caller
parameter_list|,
specifier|const
name|Function
modifier|&
name|Callee
parameter_list|)
function_decl|;
comment|/// \brief Merge caller's and callee's attributes.
name|void
name|mergeAttributesForInlining
parameter_list|(
name|Function
modifier|&
name|Caller
parameter_list|,
specifier|const
name|Function
modifier|&
name|Callee
parameter_list|)
function_decl|;
block|}
end_decl_stmt

begin_comment
comment|// end AttributeFuncs namespace
end_comment

begin_comment
unit|}
comment|// end llvm namespace
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// LLVM_IR_ATTRIBUTES_H
end_comment

end_unit

