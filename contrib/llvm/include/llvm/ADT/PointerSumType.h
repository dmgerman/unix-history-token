begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- llvm/ADT/PointerSumType.h --------------------------------*- C++ -*-===//
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

begin_ifndef
ifndef|#
directive|ifndef
name|LLVM_ADT_POINTERSUMTYPE_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_ADT_POINTERSUMTYPE_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/DenseMapInfo.h"
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

begin_decl_stmt
name|namespace
name|llvm
block|{
comment|/// A compile time pair of an integer tag and the pointer-like type which it
comment|/// indexes within a sum type. Also allows the user to specify a particular
comment|/// traits class for pointer types with custom behavior such as over-aligned
comment|/// allocation.
name|template
operator|<
name|uintptr_t
name|N
operator|,
name|typename
name|PointerArgT
operator|,
name|typename
name|TraitsArgT
operator|=
name|PointerLikeTypeTraits
operator|<
name|PointerArgT
operator|>>
expr|struct
name|PointerSumTypeMember
block|{   enum
block|{
name|Tag
operator|=
name|N
block|}
block|;
typedef|typedef
name|PointerArgT
name|PointerT
typedef|;
typedef|typedef
name|TraitsArgT
name|TraitsT
typedef|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_decl_stmt
name|namespace
name|detail
block|{
name|template
operator|<
name|typename
name|TagT
operator|,
name|typename
operator|...
name|MemberTs
operator|>
expr|struct
name|PointerSumTypeHelper
expr_stmt|;
block|}
end_decl_stmt

begin_comment
comment|/// A sum type over pointer-like types.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This is a normal tagged union across pointer-like types that uses the low
end_comment

begin_comment
comment|/// bits of the pointers to store the tag.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Each member of the sum type is specified by passing a \c
end_comment

begin_comment
comment|/// PointerSumTypeMember specialization in the variadic member argument list.
end_comment

begin_comment
comment|/// This allows the user to control the particular tag value associated with
end_comment

begin_comment
comment|/// a particular type, use the same type for multiple different tags, and
end_comment

begin_comment
comment|/// customize the pointer-like traits used for a particular member. Note that
end_comment

begin_comment
comment|/// these *must* be specializations of \c PointerSumTypeMember, no other type
end_comment

begin_comment
comment|/// will suffice, even if it provides a compatible interface.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This type implements all of the comparison operators and even hash table
end_comment

begin_comment
comment|/// support by comparing the underlying storage of the pointer values. It
end_comment

begin_comment
comment|/// doesn't support delegating to particular members for comparisons.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// It also default constructs to a zero tag with a null pointer, whatever that
end_comment

begin_comment
comment|/// would be. This means that the zero value for the tag type is significant
end_comment

begin_comment
comment|/// and may be desireable to set to a state that is particularly desirable to
end_comment

begin_comment
comment|/// default construct.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// There is no support for constructing or accessing with a dynamic tag as
end_comment

begin_comment
comment|/// that would fundamentally violate the type safety provided by the sum type.
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|TagT
operator|,
name|typename
operator|...
name|MemberTs
operator|>
name|class
name|PointerSumType
block|{
name|uintptr_t
name|Value
block|;
typedef|typedef
name|detail
operator|::
name|PointerSumTypeHelper
operator|<
name|TagT
operator|,
name|MemberTs
operator|...
operator|>
name|HelperT
expr_stmt|;
name|public
operator|:
name|PointerSumType
argument_list|()
operator|:
name|Value
argument_list|(
literal|0
argument_list|)
block|{}
comment|/// A typed constructor for a specific tagged member of the sum type.
name|template
operator|<
name|TagT
name|N
operator|>
specifier|static
name|PointerSumType
name|create
argument_list|(
argument|typename HelperT::template Lookup<N>::PointerT Pointer
argument_list|)
block|{
name|PointerSumType
name|Result
block|;
name|void
operator|*
name|V
operator|=
name|HelperT
operator|::
name|template
name|Lookup
operator|<
name|N
operator|>
operator|::
name|TraitsT
operator|::
name|getAsVoidPointer
argument_list|(
name|Pointer
argument_list|)
block|;
name|assert
argument_list|(
operator|(
name|reinterpret_cast
operator|<
name|uintptr_t
operator|>
operator|(
name|V
operator|)
operator|&
name|HelperT
operator|::
name|TagMask
operator|)
operator|==
literal|0
operator|&&
literal|"Pointer is insufficiently aligned to store the discriminant!"
argument_list|)
block|;
name|Result
operator|.
name|Value
operator|=
name|reinterpret_cast
operator|<
name|uintptr_t
operator|>
operator|(
name|V
operator|)
operator||
name|N
block|;
return|return
name|Result
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|TagT
name|getTag
argument_list|()
specifier|const
block|{
return|return
name|static_cast
operator|<
name|TagT
operator|>
operator|(
name|Value
operator|&
name|HelperT
operator|::
name|TagMask
operator|)
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|template
operator|<
name|TagT
name|N
operator|>
name|bool
name|is
argument_list|()
specifier|const
block|{
return|return
name|N
operator|==
name|getTag
argument_list|()
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|template
operator|<
name|TagT
name|N
operator|>
name|typename
name|HelperT
operator|::
name|template
name|Lookup
operator|<
name|N
operator|>
operator|::
name|PointerT
name|get
argument_list|()
specifier|const
block|{
name|void
operator|*
name|P
operator|=
name|is
operator|<
name|N
operator|>
operator|(
operator|)
operator|?
name|getImpl
argument_list|()
operator|:
name|nullptr
block|;
return|return
name|HelperT
operator|::
name|template
name|Lookup
operator|<
name|N
operator|>
operator|::
name|TraitsT
operator|::
name|getFromVoidPointer
argument_list|(
name|P
argument_list|)
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|template
operator|<
name|TagT
name|N
operator|>
name|typename
name|HelperT
operator|::
name|template
name|Lookup
operator|<
name|N
operator|>
operator|::
name|PointerT
name|cast
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
name|is
operator|<
name|N
operator|>
operator|(
operator|)
operator|&&
literal|"This instance has a different active member."
argument_list|)
block|;
return|return
name|HelperT
operator|::
name|template
name|Lookup
operator|<
name|N
operator|>
operator|::
name|TraitsT
operator|::
name|getFromVoidPointer
argument_list|(
name|getImpl
argument_list|()
argument_list|)
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|operator
name|bool
argument_list|()
specifier|const
block|{
return|return
name|Value
operator|&
name|HelperT
operator|::
name|PointerMask
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|bool
name|operator
operator|==
operator|(
specifier|const
name|PointerSumType
operator|&
name|R
operator|)
specifier|const
block|{
return|return
name|Value
operator|==
name|R
operator|.
name|Value
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|bool
name|operator
operator|!=
operator|(
specifier|const
name|PointerSumType
operator|&
name|R
operator|)
specifier|const
block|{
return|return
name|Value
operator|!=
name|R
operator|.
name|Value
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|bool
name|operator
operator|<
operator|(
specifier|const
name|PointerSumType
operator|&
name|R
operator|)
specifier|const
block|{
return|return
name|Value
operator|<
name|R
operator|.
name|Value
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|bool
name|operator
operator|>
operator|(
specifier|const
name|PointerSumType
operator|&
name|R
operator|)
specifier|const
block|{
return|return
name|Value
operator|>
name|R
operator|.
name|Value
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|bool
name|operator
operator|<=
operator|(
specifier|const
name|PointerSumType
operator|&
name|R
operator|)
specifier|const
block|{
return|return
name|Value
operator|<=
name|R
operator|.
name|Value
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|bool
name|operator
operator|>=
operator|(
specifier|const
name|PointerSumType
operator|&
name|R
operator|)
specifier|const
block|{
return|return
name|Value
operator|>=
name|R
operator|.
name|Value
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|uintptr_t
name|getOpaqueValue
argument_list|()
specifier|const
block|{
return|return
name|Value
return|;
block|}
end_expr_stmt

begin_label
name|protected
label|:
end_label

begin_expr_stmt
name|void
operator|*
name|getImpl
argument_list|()
specifier|const
block|{
return|return
name|reinterpret_cast
operator|<
name|void
operator|*
operator|>
operator|(
name|Value
operator|&
name|HelperT
operator|::
name|PointerMask
operator|)
return|;
block|}
end_expr_stmt

begin_decl_stmt
unit|};
name|namespace
name|detail
block|{
comment|/// A helper template for implementing \c PointerSumType. It provides fast
comment|/// compile-time lookup of the member from a particular tag value, along with
comment|/// useful constants and compile time checking infrastructure..
name|template
operator|<
name|typename
name|TagT
operator|,
name|typename
operator|...
name|MemberTs
operator|>
expr|struct
name|PointerSumTypeHelper
operator|:
name|MemberTs
operator|...
block|{
comment|// First we use a trick to allow quickly looking up information about
comment|// a particular member of the sum type. This works because we arranged to
comment|// have this type derive from all of the member type templates. We can select
comment|// the matching member for a tag using type deduction during overload
comment|// resolution.
name|template
operator|<
name|TagT
name|N
block|,
name|typename
name|PointerT
block|,
name|typename
name|TraitsT
operator|>
specifier|static
name|PointerSumTypeMember
operator|<
name|N
block|,
name|PointerT
block|,
name|TraitsT
operator|>
name|LookupOverload
argument_list|(
name|PointerSumTypeMember
operator|<
name|N
argument_list|,
name|PointerT
argument_list|,
name|TraitsT
operator|>
operator|*
argument_list|)
block|;
name|template
operator|<
name|TagT
name|N
operator|>
specifier|static
name|void
name|LookupOverload
argument_list|(
operator|...
argument_list|)
block|;
name|template
operator|<
name|TagT
name|N
operator|>
expr|struct
name|Lookup
block|{
comment|// Compute a particular member type by resolving the lookup helper ovorload.
typedef|typedef
name|decltype
argument_list|(
argument|LookupOverload<N>(         static_cast<PointerSumTypeHelper *>(nullptr))
argument_list|)
name|MemberT
expr_stmt|;
comment|/// The Nth member's pointer type.
typedef|typedef
name|typename
name|MemberT
operator|::
name|PointerT
name|PointerT
expr_stmt|;
comment|/// The Nth member's traits type.
typedef|typedef
name|typename
name|MemberT
operator|::
name|TraitsT
name|TraitsT
expr_stmt|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|// Next we need to compute the number of bits available for the discriminant
end_comment

begin_comment
comment|// by taking the min of the bits available for each member. Much of this
end_comment

begin_comment
comment|// would be amazingly easier with good constexpr support.
end_comment

begin_expr_stmt
name|template
operator|<
name|uintptr_t
name|V
operator|,
name|uintptr_t
operator|...
name|Vs
operator|>
expr|struct
name|Min
operator|:
name|std
operator|::
name|integral_constant
operator|<
name|uintptr_t
operator|,
operator|(
name|V
operator|<
name|Min
operator|<
name|Vs
operator|...
operator|>
operator|::
name|value
condition|?
name|V
else|:
name|Min
operator|<
name|Vs
operator|...
operator|>
operator|::
name|value
operator|)
operator|>
block|{   }
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|template
operator|<
name|uintptr_t
name|V
operator|>
expr|struct
name|Min
operator|<
name|V
operator|>
operator|:
name|std
operator|::
name|integral_constant
operator|<
name|uintptr_t
operator|,
name|V
operator|>
block|{}
expr_stmt|;
end_expr_stmt

begin_enum
enum|enum
block|{
name|NumTagBits
init|=
name|Min
operator|<
name|MemberTs
operator|::
name|TraitsT
operator|::
name|NumLowBitsAvailable
operator|...
operator|>
operator|::
name|value
block|}
enum|;
end_enum

begin_comment
comment|// Also compute the smallest discriminant and various masks for convenience.
end_comment

begin_enum_decl
enum_decl|enum :
name|uint64_t
block|{
name|MinTag
init|=
name|Min
operator|<
name|MemberTs
operator|::
name|Tag
operator|...
operator|>
operator|::
name|value
block|,
name|PointerMask
init|=
name|static_cast
operator|<
name|uint64_t
operator|>
operator|(
operator|-
literal|1
operator|)
operator|<<
name|NumTagBits
block|,
name|TagMask
init|=
operator|~
name|PointerMask
block|}
enum_decl|;
end_enum_decl

begin_comment
comment|// Finally we need a recursive template to do static checks of each
end_comment

begin_comment
comment|// member.
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|MemberT
operator|,
name|typename
operator|...
name|InnerMemberTs
operator|>
expr|struct
name|Checker
operator|:
name|Checker
operator|<
name|InnerMemberTs
operator|...
operator|>
block|{
name|static_assert
argument_list|(
name|MemberT
operator|::
name|Tag
operator|<
operator|(
literal|1
operator|<<
name|NumTagBits
operator|)
argument_list|,
literal|"This discriminant value requires too many bits!"
argument_list|)
block|;   }
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|template
operator|<
name|typename
name|MemberT
operator|>
expr|struct
name|Checker
operator|<
name|MemberT
operator|>
operator|:
name|std
operator|::
name|true_type
block|{
name|static_assert
argument_list|(
name|MemberT
operator|::
name|Tag
operator|<
operator|(
literal|1
operator|<<
name|NumTagBits
operator|)
argument_list|,
literal|"This discriminant value requires too many bits!"
argument_list|)
block|;   }
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|static_assert
argument_list|(
name|Checker
operator|<
name|MemberTs
operator|...
operator|>
operator|::
name|value
argument_list|,
literal|"Each member must pass the checker."
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
unit|};  }
comment|// Teach DenseMap how to use PointerSumTypes as keys.
end_comment

begin_expr_stmt
unit|template
operator|<
name|typename
name|TagT
operator|,
name|typename
operator|...
name|MemberTs
operator|>
expr|struct
name|DenseMapInfo
operator|<
name|PointerSumType
operator|<
name|TagT
operator|,
name|MemberTs
operator|...
operator|>>
block|{
typedef|typedef
name|PointerSumType
operator|<
name|TagT
operator|,
name|MemberTs
operator|...
operator|>
name|SumType
expr_stmt|;
end_expr_stmt

begin_typedef
typedef|typedef
name|detail
operator|::
name|PointerSumTypeHelper
operator|<
name|TagT
operator|,
name|MemberTs
operator|...
operator|>
name|HelperT
expr_stmt|;
end_typedef

begin_enum
enum|enum
block|{
name|SomeTag
init|=
name|HelperT
operator|::
name|MinTag
block|}
enum|;
end_enum

begin_typedef
typedef|typedef
name|typename
name|HelperT
operator|::
name|template
name|Lookup
operator|<
name|HelperT
operator|::
name|MinTag
operator|>
operator|::
name|PointerT
name|SomePointerT
expr_stmt|;
end_typedef

begin_typedef
typedef|typedef
name|DenseMapInfo
operator|<
name|SomePointerT
operator|>
name|SomePointerInfo
expr_stmt|;
end_typedef

begin_function
specifier|static
specifier|inline
name|SumType
name|getEmptyKey
parameter_list|()
block|{
return|return
name|SumType
operator|::
name|create
operator|<
name|SomeTag
operator|>
operator|(
name|SomePointerInfo
operator|::
name|getEmptyKey
argument_list|()
operator|)
return|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|SumType
name|getTombstoneKey
parameter_list|()
block|{
return|return
name|SumType
operator|::
name|create
operator|<
name|SomeTag
operator|>
operator|(
name|SomePointerInfo
operator|::
name|getTombstoneKey
argument_list|()
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|unsigned
name|getHashValue
parameter_list|(
specifier|const
name|SumType
modifier|&
name|Arg
parameter_list|)
block|{
name|uintptr_t
name|OpaqueValue
init|=
name|Arg
operator|.
name|getOpaqueValue
argument_list|()
decl_stmt|;
return|return
name|DenseMapInfo
operator|<
name|uintptr_t
operator|>
operator|::
name|getHashValue
argument_list|(
name|OpaqueValue
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
name|SumType
modifier|&
name|LHS
parameter_list|,
specifier|const
name|SumType
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

end_unit

