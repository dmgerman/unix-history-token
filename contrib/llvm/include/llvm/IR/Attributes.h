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
file|"llvm/Support/Compiler.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/PointerLikeTypeTraits.h"
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
file|<map>
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
name|AttributeImpl
decl_stmt|;
name|class
name|AttributeSetImpl
decl_stmt|;
name|class
name|AttributeSetNode
decl_stmt|;
name|class
name|Constant
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
name|Alignment
block|,
comment|///< Alignment of parameter (5 bits)
comment|///< stored as log2 of alignment with +1 bias
comment|///< 0 means unaligned (different from align(1))
name|AlwaysInline
block|,
comment|///< inline=always
name|Builtin
block|,
comment|///< Callee is recognized as a builtin, despite
comment|///< nobuiltin attribute on its declaration.
name|ByVal
block|,
comment|///< Pass structure by value
name|Cold
block|,
comment|///< Marks function as being in a cold path.
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
name|NoBuiltin
block|,
comment|///< Callee isn't recognized as a builtin
name|NoCapture
block|,
comment|///< Function creates no aliases of pointer
name|NoDuplicate
block|,
comment|///< Call cannot be duplicated
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
name|OptimizeNone
block|,
comment|///< Function must not be optimized.
name|ReadNone
block|,
comment|///< Function does not access memory
name|ReadOnly
block|,
comment|///< Function only reads from memory
name|Returned
block|,
comment|///< Return value is always equal to this argument
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
comment|///< alignstack=(1))
name|StackProtect
block|,
comment|///< Stack protection.
name|StackProtectReq
block|,
comment|///< Stack protection required.
name|StackProtectStrong
block|,
comment|///< Strong Stack protection.
name|StructRet
block|,
comment|///< Hidden pointer to structure to return
name|SanitizeAddress
block|,
comment|///< AddressSanitizer is on.
name|SanitizeThread
block|,
comment|///< ThreadSanitizer is on.
name|SanitizeMemory
block|,
comment|///< MemorySanitizer is on.
name|UWTable
block|,
comment|///< Function must be in a unwind table
name|ZExt
block|,
comment|///< Zero extended before/after call
name|EndAttrKinds
comment|///< Sentinal value useful for loops
block|}
enum|;
name|private
label|:
name|AttributeImpl
modifier|*
name|pImpl
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
operator|:
name|pImpl
argument_list|(
literal|0
argument_list|)
block|{}
comment|//===--------------------------------------------------------------------===//
comment|// Attribute Construction
comment|//===--------------------------------------------------------------------===//
comment|/// \brief Return a uniquified Attribute object.
specifier|static
name|Attribute
name|get
argument_list|(
argument|LLVMContext&Context
argument_list|,
argument|AttrKind Kind
argument_list|,
argument|uint64_t Val =
literal|0
argument_list|)
expr_stmt|;
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
comment|//===--------------------------------------------------------------------===//
comment|// Attribute Accessors
comment|//===--------------------------------------------------------------------===//
comment|/// \brief Return true if the attribute is an Attribute::AttrKind type.
name|bool
name|isEnumAttribute
argument_list|()
specifier|const
expr_stmt|;
comment|/// \brief Return true if the attribute is an alignment attribute.
name|bool
name|isAlignAttribute
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
comment|/// requires the attribute to be an enum or alignment attribute.
name|Attribute
operator|::
name|AttrKind
name|getKindAsEnum
argument_list|()
specifier|const
expr_stmt|;
comment|/// \brief Return the attribute's value as an integer. This requires that the
comment|/// attribute be an alignment attribute.
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
block|}
empty_stmt|;
comment|//===----------------------------------------------------------------------===//
comment|/// \class
comment|/// \brief This class holds the attributes for a function, its return value, and
comment|/// its parameters. You access the attributes for each of them via an index into
comment|/// the AttributeSet object. The function attributes are at index
comment|/// `AttributeSet::FunctionIndex', the return value is at index
comment|/// `AttributeSet::ReturnIndex', and the attributes for the parameters start at
comment|/// index `1'.
name|class
name|AttributeSet
block|{
name|public
label|:
name|enum
name|AttrIndex
name|LLVM_ENUM_INT_TYPE
parameter_list|(
name|unsigned
parameter_list|)
block|{
name|ReturnIndex
operator|=
literal|0U
operator|,
name|FunctionIndex
operator|=
operator|~
literal|0U
block|}
empty_stmt|;
name|private
label|:
name|friend
name|class
name|AttrBuilder
decl_stmt|;
name|friend
name|class
name|AttributeSetImpl
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
comment|/// \brief The attributes that we are managing. This can be null to represent
comment|/// the empty attributes list.
name|AttributeSetImpl
modifier|*
name|pImpl
decl_stmt|;
comment|/// \brief The attributes for the specified index are returned.
name|AttributeSetNode
modifier|*
name|getAttributes
argument_list|(
name|unsigned
name|Index
argument_list|)
decl|const
decl_stmt|;
comment|/// \brief Create an AttributeSet with the specified parameters in it.
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
name|std
operator|::
name|pair
operator|<
name|unsigned
argument_list|,
name|Attribute
operator|>
expr|>
name|Attrs
argument_list|)
decl_stmt|;
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
name|std
operator|::
name|pair
operator|<
name|unsigned
argument_list|,
name|AttributeSetNode
operator|*
operator|>
expr|>
name|Attrs
argument_list|)
decl_stmt|;
specifier|static
name|AttributeSet
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
name|AttributeSetNode
operator|*
operator|>
expr|>
name|Attrs
argument_list|)
decl_stmt|;
name|explicit
name|AttributeSet
argument_list|(
name|AttributeSetImpl
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
name|AttributeSet
argument_list|()
operator|:
name|pImpl
argument_list|(
literal|0
argument_list|)
block|{}
comment|//===--------------------------------------------------------------------===//
comment|// AttributeSet Construction and Mutation
comment|//===--------------------------------------------------------------------===//
comment|/// \brief Return an AttributeSet with the specified parameters in it.
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
name|AttributeSet
operator|>
name|Attrs
argument_list|)
expr_stmt|;
specifier|static
name|AttributeSet
name|get
argument_list|(
name|LLVMContext
operator|&
name|C
argument_list|,
name|unsigned
name|Index
argument_list|,
name|ArrayRef
operator|<
name|Attribute
operator|::
name|AttrKind
operator|>
name|Kind
argument_list|)
decl_stmt|;
specifier|static
name|AttributeSet
name|get
parameter_list|(
name|LLVMContext
modifier|&
name|C
parameter_list|,
name|unsigned
name|Index
parameter_list|,
name|AttrBuilder
modifier|&
name|B
parameter_list|)
function_decl|;
comment|/// \brief Add an attribute to the attribute set at the given index. Since
comment|/// attribute sets are immutable, this returns a new set.
name|AttributeSet
name|addAttribute
argument_list|(
name|LLVMContext
operator|&
name|C
argument_list|,
name|unsigned
name|Index
argument_list|,
name|Attribute
operator|::
name|AttrKind
name|Attr
argument_list|)
decl|const
decl_stmt|;
comment|/// \brief Add an attribute to the attribute set at the given index. Since
comment|/// attribute sets are immutable, this returns a new set.
name|AttributeSet
name|addAttribute
argument_list|(
name|LLVMContext
operator|&
name|C
argument_list|,
name|unsigned
name|Index
argument_list|,
name|StringRef
name|Kind
argument_list|)
decl|const
decl_stmt|;
name|AttributeSet
name|addAttribute
argument_list|(
name|LLVMContext
operator|&
name|C
argument_list|,
name|unsigned
name|Index
argument_list|,
name|StringRef
name|Kind
argument_list|,
name|StringRef
name|Value
argument_list|)
decl|const
decl_stmt|;
comment|/// \brief Add attributes to the attribute set at the given index. Since
comment|/// attribute sets are immutable, this returns a new set.
name|AttributeSet
name|addAttributes
argument_list|(
name|LLVMContext
operator|&
name|C
argument_list|,
name|unsigned
name|Index
argument_list|,
name|AttributeSet
name|Attrs
argument_list|)
decl|const
decl_stmt|;
comment|/// \brief Remove the specified attribute at the specified index from this
comment|/// attribute list. Since attribute lists are immutable, this returns the new
comment|/// list.
name|AttributeSet
name|removeAttribute
argument_list|(
name|LLVMContext
operator|&
name|C
argument_list|,
name|unsigned
name|Index
argument_list|,
name|Attribute
operator|::
name|AttrKind
name|Attr
argument_list|)
decl|const
decl_stmt|;
comment|/// \brief Remove the specified attributes at the specified index from this
comment|/// attribute list. Since attribute lists are immutable, this returns the new
comment|/// list.
name|AttributeSet
name|removeAttributes
argument_list|(
name|LLVMContext
operator|&
name|C
argument_list|,
name|unsigned
name|Index
argument_list|,
name|AttributeSet
name|Attrs
argument_list|)
decl|const
decl_stmt|;
comment|//===--------------------------------------------------------------------===//
comment|// AttributeSet Accessors
comment|//===--------------------------------------------------------------------===//
comment|/// \brief Retrieve the LLVM context.
name|LLVMContext
operator|&
name|getContext
argument_list|()
specifier|const
expr_stmt|;
comment|/// \brief The attributes for the specified index are returned.
name|AttributeSet
name|getParamAttributes
argument_list|(
name|unsigned
name|Index
argument_list|)
decl|const
decl_stmt|;
comment|/// \brief The attributes for the ret value are returned.
name|AttributeSet
name|getRetAttributes
argument_list|()
specifier|const
expr_stmt|;
comment|/// \brief The function attributes are returned.
name|AttributeSet
name|getFnAttributes
argument_list|()
specifier|const
expr_stmt|;
comment|/// \brief Return true if the attribute exists at the given index.
name|bool
name|hasAttribute
argument_list|(
name|unsigned
name|Index
argument_list|,
name|Attribute
operator|::
name|AttrKind
name|Kind
argument_list|)
decl|const
decl_stmt|;
comment|/// \brief Return true if the attribute exists at the given index.
name|bool
name|hasAttribute
argument_list|(
name|unsigned
name|Index
argument_list|,
name|StringRef
name|Kind
argument_list|)
decl|const
decl_stmt|;
comment|/// \brief Return true if attribute exists at the given index.
name|bool
name|hasAttributes
argument_list|(
name|unsigned
name|Index
argument_list|)
decl|const
decl_stmt|;
comment|/// \brief Return true if the specified attribute is set for at least one
comment|/// parameter or for the return value.
name|bool
name|hasAttrSomewhere
argument_list|(
name|Attribute
operator|::
name|AttrKind
name|Attr
argument_list|)
decl|const
decl_stmt|;
comment|/// \brief Return the attribute object that exists at the given index.
name|Attribute
name|getAttribute
argument_list|(
name|unsigned
name|Index
argument_list|,
name|Attribute
operator|::
name|AttrKind
name|Kind
argument_list|)
decl|const
decl_stmt|;
comment|/// \brief Return the attribute object that exists at the given index.
name|Attribute
name|getAttribute
argument_list|(
name|unsigned
name|Index
argument_list|,
name|StringRef
name|Kind
argument_list|)
decl|const
decl_stmt|;
comment|/// \brief Return the alignment for the specified function parameter.
name|unsigned
name|getParamAlignment
argument_list|(
name|unsigned
name|Index
argument_list|)
decl|const
decl_stmt|;
comment|/// \brief Get the stack alignment.
name|unsigned
name|getStackAlignment
argument_list|(
name|unsigned
name|Index
argument_list|)
decl|const
decl_stmt|;
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
expr_stmt|;
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
name|unsigned
name|Slot
argument_list|)
decl|const
decl_stmt|;
name|iterator
name|end
argument_list|(
name|unsigned
name|Slot
argument_list|)
decl|const
decl_stmt|;
comment|/// operator==/!= - Provide equality predicates.
name|bool
name|operator
operator|==
operator|(
specifier|const
name|AttributeSet
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
name|AttributeSet
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
comment|// AttributeSet Introspection
comment|//===--------------------------------------------------------------------===//
comment|// FIXME: Remove this.
name|uint64_t
name|Raw
argument_list|(
name|unsigned
name|Index
argument_list|)
decl|const
decl_stmt|;
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
expr_stmt|;
comment|/// \brief Return the index for the given slot.
name|unsigned
name|getSlotIndex
argument_list|(
name|unsigned
name|Slot
argument_list|)
decl|const
decl_stmt|;
comment|/// \brief Return the attributes at the given slot.
name|AttributeSet
name|getSlotAttributes
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
name|AttributeSetImpl
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
name|AttributeSetImpl
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
block|;
name|uint64_t
name|StackAlignment
block|;
name|public
operator|:
name|AttrBuilder
argument_list|()
operator|:
name|Attrs
argument_list|(
literal|0
argument_list|)
block|,
name|Alignment
argument_list|(
literal|0
argument_list|)
block|,
name|StackAlignment
argument_list|(
literal|0
argument_list|)
block|{}
name|explicit
name|AttrBuilder
argument_list|(
argument|uint64_t Val
argument_list|)
operator|:
name|Attrs
argument_list|(
literal|0
argument_list|)
block|,
name|Alignment
argument_list|(
literal|0
argument_list|)
block|,
name|StackAlignment
argument_list|(
literal|0
argument_list|)
block|{
name|addRawValue
argument_list|(
name|Val
argument_list|)
block|;   }
name|AttrBuilder
argument_list|(
specifier|const
name|Attribute
operator|&
name|A
argument_list|)
operator|:
name|Attrs
argument_list|(
literal|0
argument_list|)
block|,
name|Alignment
argument_list|(
literal|0
argument_list|)
block|,
name|StackAlignment
argument_list|(
literal|0
argument_list|)
block|{
name|addAttribute
argument_list|(
name|A
argument_list|)
block|;   }
name|AttrBuilder
argument_list|(
argument|AttributeSet AS
argument_list|,
argument|unsigned Idx
argument_list|)
block|;
name|AttrBuilder
argument_list|(
specifier|const
name|AttrBuilder
operator|&
name|B
argument_list|)
operator|:
name|Attrs
argument_list|(
name|B
operator|.
name|Attrs
argument_list|)
block|,
name|TargetDepAttrs
argument_list|(
name|B
operator|.
name|TargetDepAttrs
operator|.
name|begin
argument_list|()
argument_list|,
name|B
operator|.
name|TargetDepAttrs
operator|.
name|end
argument_list|()
argument_list|)
block|,
name|Alignment
argument_list|(
name|B
operator|.
name|Alignment
argument_list|)
block|,
name|StackAlignment
argument_list|(
argument|B.StackAlignment
argument_list|)
block|{}
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
argument|AttributeSet A
argument_list|,
argument|uint64_t Index
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
argument|AttributeSet A
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
comment|// FIXME: Remove this in 4.0.
comment|/// \brief Add the raw value to the internal representation.
name|AttrBuilder
modifier|&
name|addRawValue
parameter_list|(
name|uint64_t
name|Val
parameter_list|)
function_decl|;
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
name|AttributeSet
name|typeIncompatible
parameter_list|(
name|Type
modifier|*
name|Ty
parameter_list|,
name|uint64_t
name|Index
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

end_unit

