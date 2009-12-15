begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- CanonicalType.h - C Language Family Type Representation -*- C++ -*-===//
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
comment|//  This file defines the CanQual class template, which provides access to
end_comment

begin_comment
comment|//  canonical types.
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
name|LLVM_CLANG_AST_CANONICAL_TYPE_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_AST_CANONICAL_TYPE_H
end_define

begin_include
include|#
directive|include
file|"clang/AST/Type.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/Casting.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/type_traits.h"
end_include

begin_include
include|#
directive|include
file|<iterator>
end_include

begin_decl_stmt
name|namespace
name|clang
block|{
name|template
operator|<
name|typename
name|T
operator|>
name|class
name|CanProxy
expr_stmt|;
name|template
operator|<
name|typename
name|T
operator|>
expr|struct
name|CanProxyAdaptor
expr_stmt|;
comment|//----------------------------------------------------------------------------//
comment|// Canonical, qualified type template
comment|//----------------------------------------------------------------------------//
comment|/// \brief Represents a canonical, potentially-qualified type.
comment|///
comment|/// The CanQual template is a lightweight smart pointer that provides access
comment|/// to the canonical representation of a type, where all typedefs and other
comment|/// syntactic sugar has been eliminated. A CanQualType may also have various
comment|/// qualifiers (const, volatile, restrict) attached to it.
comment|///
comment|/// The template type parameter @p T is one of the Type classes (PointerType,
comment|/// BuiltinType, etc.). The type stored within @c CanQual<T> will be of that
comment|/// type (or some subclass of that type). The typedef @c CanQualType is just
comment|/// a shorthand for @c CanQual<Type>.
comment|///
comment|/// An instance of @c CanQual<T> can be implicitly converted to a
comment|/// @c CanQual<U> when T is derived from U, which essentially provides an
comment|/// implicit upcast. For example, @c CanQual<LValueReferenceType> can be
comment|/// converted to @c CanQual<ReferenceType>. Note that any @c CanQual type can
comment|/// be implicitly converted to a QualType, but the reverse operation requires
comment|/// a call to ASTContext::getCanonicalType().
comment|///
comment|///
name|template
operator|<
name|typename
name|T
operator|=
name|Type
operator|>
name|class
name|CanQual
block|{
comment|/// \brief The actual, canonical type.
name|QualType
name|Stored
block|;
name|public
operator|:
comment|/// \brief Constructs a NULL canonical type.
name|CanQual
argument_list|()
operator|:
name|Stored
argument_list|()
block|{ }
comment|/// \brief Converting constructor that permits implicit upcasting of
comment|/// canonical type pointers.
name|template
operator|<
name|typename
name|U
operator|>
name|CanQual
argument_list|(
argument|const CanQual<U>& Other
argument_list|,
argument|typename llvm::enable_if<llvm::is_base_of<T
argument_list|,
argument|U>
argument_list|,
argument|int>::type =
literal|0
argument_list|)
block|;
comment|/// \brief Retrieve the underlying type pointer, which refers to a
comment|/// canonical type.
name|T
operator|*
name|getTypePtr
argument_list|()
specifier|const
block|{
return|return
name|cast_or_null
operator|<
name|T
operator|>
operator|(
name|Stored
operator|.
name|getTypePtr
argument_list|()
operator|)
return|;
block|}
comment|/// \brief Implicit conversion to a qualified type.
name|operator
name|QualType
argument_list|()
specifier|const
block|{
return|return
name|Stored
return|;
block|}
comment|/// \brief Implicit conversion to bool.
name|operator
name|bool
argument_list|()
specifier|const
block|{
return|return
operator|!
name|isNull
argument_list|()
return|;
block|}
name|bool
name|isNull
argument_list|()
specifier|const
block|{
return|return
name|Stored
operator|.
name|isNull
argument_list|()
return|;
block|}
comment|/// \brief Retrieve a canonical type pointer with a different static type,
comment|/// upcasting or downcasting as needed.
comment|///
comment|/// The getAs() function is typically used to try to downcast to a
comment|/// more specific (canonical) type in the type system. For example:
comment|///
comment|/// @code
comment|/// void f(CanQual<Type> T) {
comment|///   if (CanQual<PointerType> Ptr = T->getAs<PointerType>()) {
comment|///     // look at Ptr's pointee type
comment|///   }
comment|/// }
comment|/// @endcode
comment|///
comment|/// \returns A proxy pointer to the same type, but with the specified
comment|/// static type (@p U). If the dynamic type is not the specified static type
comment|/// or a derived class thereof, a NULL canonical type.
name|template
operator|<
name|typename
name|U
operator|>
name|CanProxy
operator|<
name|U
operator|>
name|getAs
argument_list|()
specifier|const
block|;
comment|/// \brief Overloaded arrow operator that produces a canonical type
comment|/// proxy.
name|CanProxy
operator|<
name|T
operator|>
name|operator
operator|->
expr|(
block|)
specifier|const
expr_stmt|;
comment|/// \brief Retrieve all qualifiers.
name|Qualifiers
name|getQualifiers
argument_list|()
specifier|const
block|{
return|return
name|Stored
operator|.
name|getLocalQualifiers
argument_list|()
return|;
block|}
comment|/// \brief Retrieve the const/volatile/restrict qualifiers.
name|unsigned
name|getCVRQualifiers
argument_list|()
specifier|const
block|{
return|return
name|Stored
operator|.
name|getLocalCVRQualifiers
argument_list|()
return|;
block|}
comment|/// \brief Determines whether this type has any qualifiers
name|bool
name|hasQualifiers
argument_list|()
specifier|const
block|{
return|return
name|Stored
operator|.
name|hasLocalQualifiers
argument_list|()
return|;
block|}
name|bool
name|isConstQualified
argument_list|()
specifier|const
block|{
return|return
name|Stored
operator|.
name|isLocalConstQualified
argument_list|()
return|;
block|}
name|bool
name|isVolatileQualified
argument_list|()
specifier|const
block|{
return|return
name|Stored
operator|.
name|isLocalVolatileQualified
argument_list|()
return|;
block|}
name|bool
name|isRestrictQualified
argument_list|()
specifier|const
block|{
return|return
name|Stored
operator|.
name|isLocalRestrictQualified
argument_list|()
return|;
block|}
comment|/// \brief Retrieve the unqualified form of this type.
name|CanQual
operator|<
name|T
operator|>
name|getUnqualifiedType
argument_list|()
specifier|const
expr_stmt|;
comment|/// \brief Retrieves a version of this type with const applied.
comment|/// Note that this does not always yield a canonical type.
name|QualType
name|withConst
argument_list|()
specifier|const
block|{
return|return
name|Stored
operator|.
name|withConst
argument_list|()
return|;
block|}
comment|/// \brief Determines whether this canonical type is more qualified than
comment|/// the @p Other canonical type.
name|bool
name|isMoreQualifiedThan
argument_list|(
name|CanQual
operator|<
name|T
operator|>
name|Other
argument_list|)
decl|const
block|{
return|return
name|Stored
operator|.
name|isMoreQualifiedThan
argument_list|(
name|Other
operator|.
name|Stored
argument_list|)
return|;
block|}
comment|/// \brief Determines whether this canonical type is at least as qualified as
comment|/// the @p Other canonical type.
name|bool
name|isAtLeastAsQualifiedAs
argument_list|(
name|CanQual
operator|<
name|T
operator|>
name|Other
argument_list|)
decl|const
block|{
return|return
name|Stored
operator|.
name|isAtLeastAsQualifiedAs
argument_list|(
name|Other
operator|.
name|Stored
argument_list|)
return|;
block|}
comment|/// \brief If the canonical type is a reference type, returns the type that
comment|/// it refers to; otherwise, returns the type itself.
name|CanQual
operator|<
name|Type
operator|>
name|getNonReferenceType
argument_list|()
specifier|const
expr_stmt|;
comment|/// \brief Retrieve the internal representation of this canonical type.
name|void
operator|*
name|getAsOpaquePtr
argument_list|()
specifier|const
block|{
return|return
name|Stored
operator|.
name|getAsOpaquePtr
argument_list|()
return|;
block|}
comment|/// \brief Construct a canonical type from its internal representation.
specifier|static
name|CanQual
operator|<
name|T
operator|>
name|getFromOpaquePtr
argument_list|(
name|void
operator|*
name|Ptr
argument_list|)
expr_stmt|;
comment|/// \brief Builds a canonical type from a QualType.
comment|///
comment|/// This routine is inherently unsafe, because it requires the user to
comment|/// ensure that the given type is a canonical type with the correct
comment|// (dynamic) type.
specifier|static
name|CanQual
operator|<
name|T
operator|>
name|CreateUnsafe
argument_list|(
argument|QualType Other
argument_list|)
expr_stmt|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|,
name|typename
name|U
operator|>
specifier|inline
name|bool
name|operator
operator|==
operator|(
name|CanQual
operator|<
name|T
operator|>
name|x
operator|,
name|CanQual
operator|<
name|U
operator|>
name|y
operator|)
block|{
return|return
name|x
operator|.
name|getAsOpaquePtr
argument_list|()
operator|==
name|y
operator|.
name|getAsOpaquePtr
argument_list|()
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|,
name|typename
name|U
operator|>
specifier|inline
name|bool
name|operator
operator|!=
operator|(
name|CanQual
operator|<
name|T
operator|>
name|x
operator|,
name|CanQual
operator|<
name|U
operator|>
name|y
operator|)
block|{
return|return
name|x
operator|.
name|getAsOpaquePtr
argument_list|()
operator|!=
name|y
operator|.
name|getAsOpaquePtr
argument_list|()
return|;
block|}
end_expr_stmt

begin_comment
comment|/// \brief Represents a canonical, potentially-qualified type.
end_comment

begin_typedef
typedef|typedef
name|CanQual
operator|<
name|Type
operator|>
name|CanQualType
expr_stmt|;
end_typedef

begin_expr_stmt
specifier|inline
specifier|const
name|DiagnosticBuilder
operator|&
name|operator
operator|<<
operator|(
specifier|const
name|DiagnosticBuilder
operator|&
name|DB
operator|,
name|CanQualType
name|T
operator|)
block|{
name|DB
operator|<<
name|static_cast
operator|<
name|QualType
operator|>
operator|(
name|T
operator|)
block|;
return|return
name|DB
return|;
block|}
end_expr_stmt

begin_comment
comment|//----------------------------------------------------------------------------//
end_comment

begin_comment
comment|// Internal proxy classes used by canonical types
end_comment

begin_comment
comment|//----------------------------------------------------------------------------//
end_comment

begin_define
define|#
directive|define
name|LLVM_CLANG_CANPROXY_TYPE_ACCESSOR
parameter_list|(
name|Accessor
parameter_list|)
define|\
value|CanQualType Accessor() const {                                           \ return CanQualType::CreateUnsafe(this->getTypePtr()->Accessor());      \ }
end_define

begin_define
define|#
directive|define
name|LLVM_CLANG_CANPROXY_SIMPLE_ACCESSOR
parameter_list|(
name|Type
parameter_list|,
name|Accessor
parameter_list|)
define|\
value|Type Accessor() const { return this->getTypePtr()->Accessor(); }
end_define

begin_comment
comment|/// \brief Base class of all canonical proxy types, which is responsible for
end_comment

begin_comment
comment|/// storing the underlying canonical type and providing basic conversions.
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|>
name|class
name|CanProxyBase
block|{
name|protected
operator|:
name|CanQual
operator|<
name|T
operator|>
name|Stored
block|;
name|public
operator|:
comment|/// \brief Retrieve the pointer to the underlying Type
name|T
operator|*
name|getTypePtr
argument_list|()
specifier|const
block|{
return|return
name|Stored
operator|.
name|getTypePtr
argument_list|()
return|;
block|}
comment|/// \brief Implicit conversion to the underlying pointer.
comment|///
comment|/// Also provides the ability to use canonical type proxies in a Boolean
comment|// context,e.g.,
comment|/// @code
comment|///   if (CanQual<PointerType> Ptr = T->getAs<PointerType>()) { ... }
comment|/// @endcode
name|operator
specifier|const
name|T
operator|*
operator|(
operator|)
specifier|const
block|{
return|return
name|this
operator|->
name|Stored
operator|.
name|getTypePtr
argument_list|()
return|;
block|}
end_expr_stmt

begin_comment
comment|/// \brief Try to convert the given canonical type to a specific structural
end_comment

begin_comment
comment|/// type.
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|U
operator|>
name|CanProxy
operator|<
name|U
operator|>
name|getAs
argument_list|()
specifier|const
block|{
return|return
name|this
operator|->
name|Stored
operator|.
name|template
name|getAs
operator|<
name|U
operator|>
operator|(
operator|)
return|;
block|}
end_expr_stmt

begin_macro
name|LLVM_CLANG_CANPROXY_SIMPLE_ACCESSOR
argument_list|(
argument|Type::TypeClass
argument_list|,
argument|getTypeClass
argument_list|)
end_macro

begin_comment
comment|// Type predicates
end_comment

begin_macro
name|LLVM_CLANG_CANPROXY_SIMPLE_ACCESSOR
argument_list|(
argument|bool
argument_list|,
argument|isObjectType
argument_list|)
end_macro

begin_macro
name|LLVM_CLANG_CANPROXY_SIMPLE_ACCESSOR
argument_list|(
argument|bool
argument_list|,
argument|isIncompleteType
argument_list|)
end_macro

begin_macro
name|LLVM_CLANG_CANPROXY_SIMPLE_ACCESSOR
argument_list|(
argument|bool
argument_list|,
argument|isIncompleteOrObjectType
argument_list|)
end_macro

begin_macro
name|LLVM_CLANG_CANPROXY_SIMPLE_ACCESSOR
argument_list|(
argument|bool
argument_list|,
argument|isPODType
argument_list|)
end_macro

begin_macro
name|LLVM_CLANG_CANPROXY_SIMPLE_ACCESSOR
argument_list|(
argument|bool
argument_list|,
argument|isVariablyModifiedType
argument_list|)
end_macro

begin_macro
name|LLVM_CLANG_CANPROXY_SIMPLE_ACCESSOR
argument_list|(
argument|bool
argument_list|,
argument|isIntegerType
argument_list|)
end_macro

begin_macro
name|LLVM_CLANG_CANPROXY_SIMPLE_ACCESSOR
argument_list|(
argument|bool
argument_list|,
argument|isEnumeralType
argument_list|)
end_macro

begin_macro
name|LLVM_CLANG_CANPROXY_SIMPLE_ACCESSOR
argument_list|(
argument|bool
argument_list|,
argument|isBooleanType
argument_list|)
end_macro

begin_macro
name|LLVM_CLANG_CANPROXY_SIMPLE_ACCESSOR
argument_list|(
argument|bool
argument_list|,
argument|isCharType
argument_list|)
end_macro

begin_macro
name|LLVM_CLANG_CANPROXY_SIMPLE_ACCESSOR
argument_list|(
argument|bool
argument_list|,
argument|isWideCharType
argument_list|)
end_macro

begin_macro
name|LLVM_CLANG_CANPROXY_SIMPLE_ACCESSOR
argument_list|(
argument|bool
argument_list|,
argument|isIntegralType
argument_list|)
end_macro

begin_macro
name|LLVM_CLANG_CANPROXY_SIMPLE_ACCESSOR
argument_list|(
argument|bool
argument_list|,
argument|isRealFloatingType
argument_list|)
end_macro

begin_macro
name|LLVM_CLANG_CANPROXY_SIMPLE_ACCESSOR
argument_list|(
argument|bool
argument_list|,
argument|isComplexType
argument_list|)
end_macro

begin_macro
name|LLVM_CLANG_CANPROXY_SIMPLE_ACCESSOR
argument_list|(
argument|bool
argument_list|,
argument|isAnyComplexType
argument_list|)
end_macro

begin_macro
name|LLVM_CLANG_CANPROXY_SIMPLE_ACCESSOR
argument_list|(
argument|bool
argument_list|,
argument|isFloatingType
argument_list|)
end_macro

begin_macro
name|LLVM_CLANG_CANPROXY_SIMPLE_ACCESSOR
argument_list|(
argument|bool
argument_list|,
argument|isRealType
argument_list|)
end_macro

begin_macro
name|LLVM_CLANG_CANPROXY_SIMPLE_ACCESSOR
argument_list|(
argument|bool
argument_list|,
argument|isArithmeticType
argument_list|)
end_macro

begin_macro
name|LLVM_CLANG_CANPROXY_SIMPLE_ACCESSOR
argument_list|(
argument|bool
argument_list|,
argument|isVoidType
argument_list|)
end_macro

begin_macro
name|LLVM_CLANG_CANPROXY_SIMPLE_ACCESSOR
argument_list|(
argument|bool
argument_list|,
argument|isDerivedType
argument_list|)
end_macro

begin_macro
name|LLVM_CLANG_CANPROXY_SIMPLE_ACCESSOR
argument_list|(
argument|bool
argument_list|,
argument|isScalarType
argument_list|)
end_macro

begin_macro
name|LLVM_CLANG_CANPROXY_SIMPLE_ACCESSOR
argument_list|(
argument|bool
argument_list|,
argument|isAggregateType
argument_list|)
end_macro

begin_macro
name|LLVM_CLANG_CANPROXY_SIMPLE_ACCESSOR
argument_list|(
argument|bool
argument_list|,
argument|isAnyPointerType
argument_list|)
end_macro

begin_macro
name|LLVM_CLANG_CANPROXY_SIMPLE_ACCESSOR
argument_list|(
argument|bool
argument_list|,
argument|isVoidPointerType
argument_list|)
end_macro

begin_macro
name|LLVM_CLANG_CANPROXY_SIMPLE_ACCESSOR
argument_list|(
argument|bool
argument_list|,
argument|isFunctionPointerType
argument_list|)
end_macro

begin_macro
name|LLVM_CLANG_CANPROXY_SIMPLE_ACCESSOR
argument_list|(
argument|bool
argument_list|,
argument|isMemberFunctionPointerType
argument_list|)
end_macro

begin_macro
name|LLVM_CLANG_CANPROXY_SIMPLE_ACCESSOR
argument_list|(
argument|bool
argument_list|,
argument|isClassType
argument_list|)
end_macro

begin_macro
name|LLVM_CLANG_CANPROXY_SIMPLE_ACCESSOR
argument_list|(
argument|bool
argument_list|,
argument|isStructureType
argument_list|)
end_macro

begin_macro
name|LLVM_CLANG_CANPROXY_SIMPLE_ACCESSOR
argument_list|(
argument|bool
argument_list|,
argument|isUnionType
argument_list|)
end_macro

begin_macro
name|LLVM_CLANG_CANPROXY_SIMPLE_ACCESSOR
argument_list|(
argument|bool
argument_list|,
argument|isComplexIntegerType
argument_list|)
end_macro

begin_macro
name|LLVM_CLANG_CANPROXY_SIMPLE_ACCESSOR
argument_list|(
argument|bool
argument_list|,
argument|isNullPtrType
argument_list|)
end_macro

begin_macro
name|LLVM_CLANG_CANPROXY_SIMPLE_ACCESSOR
argument_list|(
argument|bool
argument_list|,
argument|isDependentType
argument_list|)
end_macro

begin_macro
name|LLVM_CLANG_CANPROXY_SIMPLE_ACCESSOR
argument_list|(
argument|bool
argument_list|,
argument|isOverloadableType
argument_list|)
end_macro

begin_macro
name|LLVM_CLANG_CANPROXY_SIMPLE_ACCESSOR
argument_list|(
argument|bool
argument_list|,
argument|hasPointerRepresentation
argument_list|)
end_macro

begin_macro
name|LLVM_CLANG_CANPROXY_SIMPLE_ACCESSOR
argument_list|(
argument|bool
argument_list|,
argument|hasObjCPointerRepresentation
argument_list|)
end_macro

begin_macro
name|LLVM_CLANG_CANPROXY_SIMPLE_ACCESSOR
argument_list|(
argument|bool
argument_list|,
argument|isPromotableIntegerType
argument_list|)
end_macro

begin_macro
name|LLVM_CLANG_CANPROXY_SIMPLE_ACCESSOR
argument_list|(
argument|bool
argument_list|,
argument|isSignedIntegerType
argument_list|)
end_macro

begin_macro
name|LLVM_CLANG_CANPROXY_SIMPLE_ACCESSOR
argument_list|(
argument|bool
argument_list|,
argument|isUnsignedIntegerType
argument_list|)
end_macro

begin_macro
name|LLVM_CLANG_CANPROXY_SIMPLE_ACCESSOR
argument_list|(
argument|bool
argument_list|,
argument|isConstantSizeType
argument_list|)
end_macro

begin_macro
name|LLVM_CLANG_CANPROXY_SIMPLE_ACCESSOR
argument_list|(
argument|bool
argument_list|,
argument|isSpecifierType
argument_list|)
end_macro

begin_comment
comment|/// \brief Retrieve the proxy-adaptor type.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This arrow operator is used when CanProxyAdaptor has been specialized
end_comment

begin_comment
comment|/// for the given type T. In that case, we reference members of the
end_comment

begin_comment
comment|/// CanProxyAdaptor specialization. Otherwise, this operator will be hidden
end_comment

begin_comment
comment|/// by the arrow operator in the primary CanProxyAdaptor template.
end_comment

begin_expr_stmt
specifier|const
name|CanProxyAdaptor
operator|<
name|T
operator|>
operator|*
name|operator
operator|->
expr|(
end_expr_stmt

begin_expr_stmt
unit|)
specifier|const
block|{
return|return
name|static_cast
operator|<
specifier|const
name|CanProxyAdaptor
operator|<
name|T
operator|>
operator|*
operator|>
operator|(
name|this
operator|)
return|;
block|}
end_expr_stmt

begin_comment
unit|};
comment|/// \brief Replacable canonical proxy adaptor class that provides the link
end_comment

begin_comment
comment|/// between a canonical type and the accessors of the type.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// The CanProxyAdaptor is a replaceable class template that is instantiated
end_comment

begin_comment
comment|/// as part of each canonical proxy type. The primary template merely provides
end_comment

begin_comment
comment|/// redirection to the underlying type (T), e.g., @c PointerType. One can
end_comment

begin_comment
comment|/// provide specializations of this class template for each underlying type
end_comment

begin_comment
comment|/// that provide accessors returning canonical types (@c CanQualType) rather
end_comment

begin_comment
comment|/// than the more typical @c QualType, to propagate the notion of "canonical"
end_comment

begin_comment
comment|/// through the system.
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|>
expr|struct
name|CanProxyAdaptor
operator|:
name|CanProxyBase
operator|<
name|T
operator|>
block|{ }
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// \brief Canonical proxy type returned when retrieving the members of a
end_comment

begin_comment
comment|/// canonical type or as the result of the @c CanQual<T>::getAs member
end_comment

begin_comment
comment|/// function.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// The CanProxy type mainly exists as a proxy through which operator-> will
end_comment

begin_comment
comment|/// look to either map down to a raw T* (e.g., PointerType*) or to a proxy
end_comment

begin_comment
comment|/// type that provides canonical-type access to the fields of the type.
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|>
name|class
name|CanProxy
operator|:
name|public
name|CanProxyAdaptor
operator|<
name|T
operator|>
block|{
name|public
operator|:
comment|/// \brief Build a NULL proxy.
name|CanProxy
argument_list|()
block|{ }
comment|/// \brief Build a proxy to the given canonical type.
name|CanProxy
argument_list|(
argument|CanQual<T> Stored
argument_list|)
block|{
name|this
operator|->
name|Stored
operator|=
name|Stored
block|; }
comment|/// \brief Implicit conversion to the stored canonical type.
name|operator
name|CanQual
operator|<
name|T
operator|>
operator|(
operator|)
specifier|const
block|{
return|return
name|this
operator|->
name|Stored
return|;
block|}
end_expr_stmt

begin_comment
unit|};  }
comment|// end namespace clang
end_comment

begin_macro
unit|namespace
name|llvm
end_macro

begin_block
block|{
comment|/// Implement simplify_type for CanQual<T>, so that we can dyn_cast from
comment|/// CanQual<T> to a specific Type class. We're prefer isa/dyn_cast/cast/etc.
comment|/// to return smart pointer (proxies?).
name|template
operator|<
name|typename
name|T
operator|>
expr|struct
name|simplify_type
operator|<
specifier|const
operator|::
name|clang
operator|::
name|CanQual
operator|<
name|T
operator|>
expr|>
block|{
typedef|typedef
name|T
modifier|*
name|SimpleType
typedef|;
specifier|static
name|SimpleType
name|getSimplifiedValue
argument_list|(
argument|const ::clang::CanQual<T>&Val
argument_list|)
block|{
return|return
name|Val
operator|.
name|getTypePtr
argument_list|()
return|;
block|}
block|}
empty_stmt|;
name|template
operator|<
name|typename
name|T
operator|>
expr|struct
name|simplify_type
operator|<
operator|::
name|clang
operator|::
name|CanQual
operator|<
name|T
operator|>
expr|>
operator|:
name|public
name|simplify_type
operator|<
specifier|const
operator|::
name|clang
operator|::
name|CanQual
operator|<
name|T
operator|>
expr|>
block|{}
expr_stmt|;
comment|// Teach SmallPtrSet that CanQual<T> is "basically a pointer".
name|template
operator|<
name|typename
name|T
operator|>
name|class
name|PointerLikeTypeTraits
operator|<
name|clang
operator|::
name|CanQual
operator|<
name|T
operator|>
expr|>
block|{
name|public
operator|:
specifier|static
specifier|inline
name|void
operator|*
name|getAsVoidPointer
argument_list|(
argument|clang::CanQual<T> P
argument_list|)
block|{
return|return
name|P
operator|.
name|getAsOpaquePtr
argument_list|()
return|;
block|}
specifier|static
specifier|inline
name|clang
operator|::
name|CanQual
operator|<
name|T
operator|>
name|getFromVoidPointer
argument_list|(
argument|void *P
argument_list|)
block|{
return|return
name|clang
operator|::
name|CanQual
operator|<
name|T
operator|>
operator|::
name|getFromOpaquePtr
argument_list|(
name|P
argument_list|)
return|;
block|}
comment|// qualifier information is encoded in the low bits.
enum|enum
block|{
name|NumLowBitsAvailable
init|=
literal|0
block|}
enum|;
block|}
end_block

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
unit|}
comment|// end namespace llvm
end_comment

begin_macro
unit|namespace
name|clang
end_macro

begin_block
block|{
comment|//----------------------------------------------------------------------------//
comment|// Canonical proxy adaptors for canonical type nodes.
comment|//----------------------------------------------------------------------------//
comment|/// \brief Iterator adaptor that turns an iterator over canonical QualTypes
comment|/// into an iterator over CanQualTypes.
name|template
operator|<
name|typename
name|InputIterator
operator|>
name|class
name|CanTypeIterator
block|{
name|InputIterator
name|Iter
block|;
name|public
operator|:
typedef|typedef
name|CanQualType
name|value_type
typedef|;
typedef|typedef
name|value_type
name|reference
typedef|;
typedef|typedef
name|CanProxy
operator|<
name|Type
operator|>
name|pointer
expr_stmt|;
typedef|typedef
name|typename
name|std
operator|::
name|iterator_traits
operator|<
name|InputIterator
operator|>
operator|::
name|difference_type
name|difference_type
expr_stmt|;
typedef|typedef
name|typename
name|std
operator|::
name|iterator_traits
operator|<
name|InputIterator
operator|>
operator|::
name|iterator_category
name|iterator_category
expr_stmt|;
name|CanTypeIterator
argument_list|()
operator|:
name|Iter
argument_list|()
block|{ }
name|explicit
name|CanTypeIterator
argument_list|(
argument|InputIterator Iter
argument_list|)
operator|:
name|Iter
argument_list|(
argument|Iter
argument_list|)
block|{ }
comment|// Input iterator
name|reference
name|operator
operator|*
operator|(
operator|)
specifier|const
block|{
return|return
name|CanQualType
operator|::
name|CreateUnsafe
argument_list|(
operator|*
name|Iter
argument_list|)
return|;
block|}
name|pointer
name|operator
operator|->
expr|(
block|)
end_block

begin_decl_stmt
specifier|const
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|CanTypeIterator
operator|&
name|operator
operator|++
operator|(
operator|)
block|{
operator|++
name|Iter
block|;
return|return
operator|*
name|this
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|CanTypeIterator
name|operator
operator|++
operator|(
name|int
operator|)
block|{
name|CanTypeIterator
name|Tmp
argument_list|(
operator|*
name|this
argument_list|)
block|;
operator|++
name|Iter
block|;
return|return
name|Tmp
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|friend
name|bool
name|operator
operator|==
operator|(
specifier|const
name|CanTypeIterator
operator|&
name|X
operator|,
specifier|const
name|CanTypeIterator
operator|&
name|Y
operator|)
block|{
return|return
name|X
operator|.
name|Iter
operator|==
name|Y
operator|.
name|Iter
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|friend
name|bool
name|operator
operator|!=
operator|(
specifier|const
name|CanTypeIterator
operator|&
name|X
operator|,
specifier|const
name|CanTypeIterator
operator|&
name|Y
operator|)
block|{
return|return
name|X
operator|.
name|Iter
operator|!=
name|Y
operator|.
name|Iter
return|;
block|}
end_expr_stmt

begin_comment
comment|// Bidirectional iterator
end_comment

begin_expr_stmt
name|CanTypeIterator
operator|&
name|operator
operator|--
operator|(
operator|)
block|{
operator|--
name|Iter
block|;
return|return
operator|*
name|this
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|CanTypeIterator
name|operator
operator|--
operator|(
name|int
operator|)
block|{
name|CanTypeIterator
name|Tmp
argument_list|(
operator|*
name|this
argument_list|)
block|;
operator|--
name|Iter
block|;
return|return
name|Tmp
return|;
block|}
end_expr_stmt

begin_comment
comment|// Random access iterator
end_comment

begin_decl_stmt
name|reference
name|operator
index|[]
argument_list|(
name|difference_type
name|n
argument_list|)
decl|const
block|{
return|return
name|CanQualType
operator|::
name|CreateUnsafe
argument_list|(
name|Iter
index|[
name|n
index|]
argument_list|)
return|;
block|}
end_decl_stmt

begin_expr_stmt
name|CanTypeIterator
operator|&
name|operator
operator|+=
operator|(
name|difference_type
name|n
operator|)
block|{
name|Iter
operator|+=
name|n
block|;
return|return
operator|*
name|this
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|CanTypeIterator
operator|&
name|operator
operator|-=
operator|(
name|difference_type
name|n
operator|)
block|{
name|Iter
operator|-=
name|n
block|;
return|return
operator|*
name|this
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|friend
name|CanTypeIterator
name|operator
operator|+
operator|(
name|CanTypeIterator
name|X
operator|,
name|difference_type
name|n
operator|)
block|{
name|X
operator|+=
name|n
block|;
return|return
name|X
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|friend
name|CanTypeIterator
name|operator
operator|+
operator|(
name|difference_type
name|n
operator|,
name|CanTypeIterator
name|X
operator|)
block|{
name|X
operator|+=
name|n
block|;
return|return
name|X
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|friend
name|CanTypeIterator
name|operator
operator|-
operator|(
name|CanTypeIterator
name|X
operator|,
name|difference_type
name|n
operator|)
block|{
name|X
operator|-=
name|n
block|;
return|return
name|X
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|friend
name|difference_type
name|operator
operator|-
operator|(
specifier|const
name|CanTypeIterator
operator|&
name|X
operator|,
specifier|const
name|CanTypeIterator
operator|&
name|Y
operator|)
block|{
return|return
name|X
operator|-
name|Y
return|;
block|}
end_expr_stmt

begin_expr_stmt
unit|};
name|template
operator|<
operator|>
expr|struct
name|CanProxyAdaptor
operator|<
name|ComplexType
operator|>
operator|:
name|public
name|CanProxyBase
operator|<
name|ComplexType
operator|>
block|{
name|LLVM_CLANG_CANPROXY_TYPE_ACCESSOR
argument_list|(
argument|getElementType
argument_list|)
block|}
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|template
operator|<
operator|>
expr|struct
name|CanProxyAdaptor
operator|<
name|PointerType
operator|>
operator|:
name|public
name|CanProxyBase
operator|<
name|PointerType
operator|>
block|{
name|LLVM_CLANG_CANPROXY_TYPE_ACCESSOR
argument_list|(
argument|getPointeeType
argument_list|)
block|}
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|template
operator|<
operator|>
expr|struct
name|CanProxyAdaptor
operator|<
name|BlockPointerType
operator|>
operator|:
name|public
name|CanProxyBase
operator|<
name|BlockPointerType
operator|>
block|{
name|LLVM_CLANG_CANPROXY_TYPE_ACCESSOR
argument_list|(
argument|getPointeeType
argument_list|)
block|}
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|template
operator|<
operator|>
expr|struct
name|CanProxyAdaptor
operator|<
name|ReferenceType
operator|>
operator|:
name|public
name|CanProxyBase
operator|<
name|ReferenceType
operator|>
block|{
name|LLVM_CLANG_CANPROXY_TYPE_ACCESSOR
argument_list|(
argument|getPointeeType
argument_list|)
block|}
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|template
operator|<
operator|>
expr|struct
name|CanProxyAdaptor
operator|<
name|LValueReferenceType
operator|>
operator|:
name|public
name|CanProxyBase
operator|<
name|LValueReferenceType
operator|>
block|{
name|LLVM_CLANG_CANPROXY_TYPE_ACCESSOR
argument_list|(
argument|getPointeeType
argument_list|)
block|}
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|template
operator|<
operator|>
expr|struct
name|CanProxyAdaptor
operator|<
name|RValueReferenceType
operator|>
operator|:
name|public
name|CanProxyBase
operator|<
name|RValueReferenceType
operator|>
block|{
name|LLVM_CLANG_CANPROXY_TYPE_ACCESSOR
argument_list|(
argument|getPointeeType
argument_list|)
block|}
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|template
operator|<
operator|>
expr|struct
name|CanProxyAdaptor
operator|<
name|MemberPointerType
operator|>
operator|:
name|public
name|CanProxyBase
operator|<
name|MemberPointerType
operator|>
block|{
name|LLVM_CLANG_CANPROXY_TYPE_ACCESSOR
argument_list|(
argument|getPointeeType
argument_list|)
name|LLVM_CLANG_CANPROXY_SIMPLE_ACCESSOR
argument_list|(
argument|const Type *
argument_list|,
argument|getClass
argument_list|)
block|}
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|template
operator|<
operator|>
expr|struct
name|CanProxyAdaptor
operator|<
name|ArrayType
operator|>
operator|:
name|public
name|CanProxyBase
operator|<
name|ArrayType
operator|>
block|{
name|LLVM_CLANG_CANPROXY_TYPE_ACCESSOR
argument_list|(
argument|getElementType
argument_list|)
name|LLVM_CLANG_CANPROXY_SIMPLE_ACCESSOR
argument_list|(
argument|ArrayType::ArraySizeModifier
argument_list|,
argument|getSizeModifier
argument_list|)
name|LLVM_CLANG_CANPROXY_SIMPLE_ACCESSOR
argument_list|(
argument|Qualifiers
argument_list|,
argument|getIndexTypeQualifiers
argument_list|)
block|}
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|template
operator|<
operator|>
expr|struct
name|CanProxyAdaptor
operator|<
name|ConstantArrayType
operator|>
operator|:
name|public
name|CanProxyBase
operator|<
name|ConstantArrayType
operator|>
block|{
name|LLVM_CLANG_CANPROXY_TYPE_ACCESSOR
argument_list|(
argument|getElementType
argument_list|)
name|LLVM_CLANG_CANPROXY_SIMPLE_ACCESSOR
argument_list|(
argument|ArrayType::ArraySizeModifier
argument_list|,
argument|getSizeModifier
argument_list|)
name|LLVM_CLANG_CANPROXY_SIMPLE_ACCESSOR
argument_list|(
argument|Qualifiers
argument_list|,
argument|getIndexTypeQualifiers
argument_list|)
name|LLVM_CLANG_CANPROXY_SIMPLE_ACCESSOR
argument_list|(
argument|const llvm::APInt&
argument_list|,
argument|getSize
argument_list|)
block|}
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|template
operator|<
operator|>
expr|struct
name|CanProxyAdaptor
operator|<
name|IncompleteArrayType
operator|>
operator|:
name|public
name|CanProxyBase
operator|<
name|IncompleteArrayType
operator|>
block|{
name|LLVM_CLANG_CANPROXY_TYPE_ACCESSOR
argument_list|(
argument|getElementType
argument_list|)
name|LLVM_CLANG_CANPROXY_SIMPLE_ACCESSOR
argument_list|(
argument|ArrayType::ArraySizeModifier
argument_list|,
argument|getSizeModifier
argument_list|)
name|LLVM_CLANG_CANPROXY_SIMPLE_ACCESSOR
argument_list|(
argument|Qualifiers
argument_list|,
argument|getIndexTypeQualifiers
argument_list|)
block|}
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|template
operator|<
operator|>
expr|struct
name|CanProxyAdaptor
operator|<
name|VariableArrayType
operator|>
operator|:
name|public
name|CanProxyBase
operator|<
name|VariableArrayType
operator|>
block|{
name|LLVM_CLANG_CANPROXY_TYPE_ACCESSOR
argument_list|(
argument|getElementType
argument_list|)
name|LLVM_CLANG_CANPROXY_SIMPLE_ACCESSOR
argument_list|(
argument|ArrayType::ArraySizeModifier
argument_list|,
argument|getSizeModifier
argument_list|)
name|LLVM_CLANG_CANPROXY_SIMPLE_ACCESSOR
argument_list|(
argument|Qualifiers
argument_list|,
argument|getIndexTypeQualifiers
argument_list|)
name|LLVM_CLANG_CANPROXY_SIMPLE_ACCESSOR
argument_list|(
argument|Expr *
argument_list|,
argument|getSizeExpr
argument_list|)
name|LLVM_CLANG_CANPROXY_SIMPLE_ACCESSOR
argument_list|(
argument|SourceRange
argument_list|,
argument|getBracketsRange
argument_list|)
name|LLVM_CLANG_CANPROXY_SIMPLE_ACCESSOR
argument_list|(
argument|SourceLocation
argument_list|,
argument|getLBracketLoc
argument_list|)
name|LLVM_CLANG_CANPROXY_SIMPLE_ACCESSOR
argument_list|(
argument|SourceLocation
argument_list|,
argument|getRBracketLoc
argument_list|)
block|}
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|template
operator|<
operator|>
expr|struct
name|CanProxyAdaptor
operator|<
name|DependentSizedArrayType
operator|>
operator|:
name|public
name|CanProxyBase
operator|<
name|DependentSizedArrayType
operator|>
block|{
name|LLVM_CLANG_CANPROXY_TYPE_ACCESSOR
argument_list|(
argument|getElementType
argument_list|)
name|LLVM_CLANG_CANPROXY_SIMPLE_ACCESSOR
argument_list|(
argument|Expr *
argument_list|,
argument|getSizeExpr
argument_list|)
name|LLVM_CLANG_CANPROXY_SIMPLE_ACCESSOR
argument_list|(
argument|SourceRange
argument_list|,
argument|getBracketsRange
argument_list|)
name|LLVM_CLANG_CANPROXY_SIMPLE_ACCESSOR
argument_list|(
argument|SourceLocation
argument_list|,
argument|getLBracketLoc
argument_list|)
name|LLVM_CLANG_CANPROXY_SIMPLE_ACCESSOR
argument_list|(
argument|SourceLocation
argument_list|,
argument|getRBracketLoc
argument_list|)
block|}
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|template
operator|<
operator|>
expr|struct
name|CanProxyAdaptor
operator|<
name|DependentSizedExtVectorType
operator|>
operator|:
name|public
name|CanProxyBase
operator|<
name|DependentSizedExtVectorType
operator|>
block|{
name|LLVM_CLANG_CANPROXY_TYPE_ACCESSOR
argument_list|(
argument|getElementType
argument_list|)
name|LLVM_CLANG_CANPROXY_SIMPLE_ACCESSOR
argument_list|(
argument|const Expr *
argument_list|,
argument|getSizeExpr
argument_list|)
name|LLVM_CLANG_CANPROXY_SIMPLE_ACCESSOR
argument_list|(
argument|SourceLocation
argument_list|,
argument|getAttributeLoc
argument_list|)
block|}
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|template
operator|<
operator|>
expr|struct
name|CanProxyAdaptor
operator|<
name|VectorType
operator|>
operator|:
name|public
name|CanProxyBase
operator|<
name|VectorType
operator|>
block|{
name|LLVM_CLANG_CANPROXY_TYPE_ACCESSOR
argument_list|(
argument|getElementType
argument_list|)
name|LLVM_CLANG_CANPROXY_SIMPLE_ACCESSOR
argument_list|(
argument|unsigned
argument_list|,
argument|getNumElements
argument_list|)
block|}
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|template
operator|<
operator|>
expr|struct
name|CanProxyAdaptor
operator|<
name|ExtVectorType
operator|>
operator|:
name|public
name|CanProxyBase
operator|<
name|ExtVectorType
operator|>
block|{
name|LLVM_CLANG_CANPROXY_TYPE_ACCESSOR
argument_list|(
argument|getElementType
argument_list|)
name|LLVM_CLANG_CANPROXY_SIMPLE_ACCESSOR
argument_list|(
argument|unsigned
argument_list|,
argument|getNumElements
argument_list|)
block|}
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|template
operator|<
operator|>
expr|struct
name|CanProxyAdaptor
operator|<
name|FunctionType
operator|>
operator|:
name|public
name|CanProxyBase
operator|<
name|FunctionType
operator|>
block|{
name|LLVM_CLANG_CANPROXY_TYPE_ACCESSOR
argument_list|(
argument|getResultType
argument_list|)
block|}
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|template
operator|<
operator|>
expr|struct
name|CanProxyAdaptor
operator|<
name|FunctionNoProtoType
operator|>
operator|:
name|public
name|CanProxyBase
operator|<
name|FunctionNoProtoType
operator|>
block|{
name|LLVM_CLANG_CANPROXY_TYPE_ACCESSOR
argument_list|(
argument|getResultType
argument_list|)
block|}
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|template
operator|<
operator|>
expr|struct
name|CanProxyAdaptor
operator|<
name|FunctionProtoType
operator|>
operator|:
name|public
name|CanProxyBase
operator|<
name|FunctionProtoType
operator|>
block|{
name|LLVM_CLANG_CANPROXY_TYPE_ACCESSOR
argument_list|(
argument|getResultType
argument_list|)
name|LLVM_CLANG_CANPROXY_SIMPLE_ACCESSOR
argument_list|(
name|unsigned
argument_list|,
name|getNumArgs
argument_list|)
block|;
name|CanQualType
name|getArgType
argument_list|(
argument|unsigned i
argument_list|)
specifier|const
block|{
return|return
name|CanQualType
operator|::
name|CreateUnsafe
argument_list|(
name|this
operator|->
name|getTypePtr
argument_list|()
operator|->
name|getArgType
argument_list|(
name|i
argument_list|)
argument_list|)
return|;
block|}
name|LLVM_CLANG_CANPROXY_SIMPLE_ACCESSOR
argument_list|(
argument|bool
argument_list|,
argument|isVariadic
argument_list|)
name|LLVM_CLANG_CANPROXY_SIMPLE_ACCESSOR
argument_list|(
argument|unsigned
argument_list|,
argument|getTypeQuals
argument_list|)
end_expr_stmt

begin_typedef
typedef|typedef
name|CanTypeIterator
operator|<
name|FunctionProtoType
operator|::
name|arg_type_iterator
operator|>
name|arg_type_iterator
expr_stmt|;
end_typedef

begin_expr_stmt
name|arg_type_iterator
name|arg_type_begin
argument_list|()
specifier|const
block|{
return|return
name|arg_type_iterator
argument_list|(
name|this
operator|->
name|getTypePtr
argument_list|()
operator|->
name|arg_type_begin
argument_list|()
argument_list|)
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|arg_type_iterator
name|arg_type_end
argument_list|()
specifier|const
block|{
return|return
name|arg_type_iterator
argument_list|(
name|this
operator|->
name|getTypePtr
argument_list|()
operator|->
name|arg_type_end
argument_list|()
argument_list|)
return|;
block|}
end_expr_stmt

begin_comment
comment|// Note: canonical function types never have exception specifications
end_comment

begin_expr_stmt
unit|};
name|template
operator|<
operator|>
expr|struct
name|CanProxyAdaptor
operator|<
name|TypeOfType
operator|>
operator|:
name|public
name|CanProxyBase
operator|<
name|TypeOfType
operator|>
block|{
name|LLVM_CLANG_CANPROXY_TYPE_ACCESSOR
argument_list|(
argument|getUnderlyingType
argument_list|)
block|}
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|template
operator|<
operator|>
expr|struct
name|CanProxyAdaptor
operator|<
name|DecltypeType
operator|>
operator|:
name|public
name|CanProxyBase
operator|<
name|DecltypeType
operator|>
block|{
name|LLVM_CLANG_CANPROXY_SIMPLE_ACCESSOR
argument_list|(
argument|Expr *
argument_list|,
argument|getUnderlyingExpr
argument_list|)
name|LLVM_CLANG_CANPROXY_TYPE_ACCESSOR
argument_list|(
argument|getUnderlyingType
argument_list|)
block|}
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|template
operator|<
operator|>
expr|struct
name|CanProxyAdaptor
operator|<
name|TagType
operator|>
operator|:
name|public
name|CanProxyBase
operator|<
name|TagType
operator|>
block|{
name|LLVM_CLANG_CANPROXY_SIMPLE_ACCESSOR
argument_list|(
argument|TagDecl *
argument_list|,
argument|getDecl
argument_list|)
name|LLVM_CLANG_CANPROXY_SIMPLE_ACCESSOR
argument_list|(
argument|bool
argument_list|,
argument|isBeingDefined
argument_list|)
block|}
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|template
operator|<
operator|>
expr|struct
name|CanProxyAdaptor
operator|<
name|RecordType
operator|>
operator|:
name|public
name|CanProxyBase
operator|<
name|RecordType
operator|>
block|{
name|LLVM_CLANG_CANPROXY_SIMPLE_ACCESSOR
argument_list|(
argument|RecordDecl *
argument_list|,
argument|getDecl
argument_list|)
name|LLVM_CLANG_CANPROXY_SIMPLE_ACCESSOR
argument_list|(
argument|bool
argument_list|,
argument|isBeingDefined
argument_list|)
name|LLVM_CLANG_CANPROXY_SIMPLE_ACCESSOR
argument_list|(
argument|bool
argument_list|,
argument|hasConstFields
argument_list|)
name|LLVM_CLANG_CANPROXY_SIMPLE_ACCESSOR
argument_list|(
argument|unsigned
argument_list|,
argument|getAddressSpace
argument_list|)
block|}
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|template
operator|<
operator|>
expr|struct
name|CanProxyAdaptor
operator|<
name|EnumType
operator|>
operator|:
name|public
name|CanProxyBase
operator|<
name|EnumType
operator|>
block|{
name|LLVM_CLANG_CANPROXY_SIMPLE_ACCESSOR
argument_list|(
argument|EnumDecl *
argument_list|,
argument|getDecl
argument_list|)
name|LLVM_CLANG_CANPROXY_SIMPLE_ACCESSOR
argument_list|(
argument|bool
argument_list|,
argument|isBeingDefined
argument_list|)
block|}
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|template
operator|<
operator|>
expr|struct
name|CanProxyAdaptor
operator|<
name|TemplateTypeParmType
operator|>
operator|:
name|public
name|CanProxyBase
operator|<
name|TemplateTypeParmType
operator|>
block|{
name|LLVM_CLANG_CANPROXY_SIMPLE_ACCESSOR
argument_list|(
argument|unsigned
argument_list|,
argument|getDepth
argument_list|)
name|LLVM_CLANG_CANPROXY_SIMPLE_ACCESSOR
argument_list|(
argument|unsigned
argument_list|,
argument|getIndex
argument_list|)
name|LLVM_CLANG_CANPROXY_SIMPLE_ACCESSOR
argument_list|(
argument|bool
argument_list|,
argument|isParameterPack
argument_list|)
name|LLVM_CLANG_CANPROXY_SIMPLE_ACCESSOR
argument_list|(
argument|IdentifierInfo *
argument_list|,
argument|getName
argument_list|)
block|}
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|template
operator|<
operator|>
expr|struct
name|CanProxyAdaptor
operator|<
name|ObjCObjectPointerType
operator|>
operator|:
name|public
name|CanProxyBase
operator|<
name|ObjCObjectPointerType
operator|>
block|{
name|LLVM_CLANG_CANPROXY_TYPE_ACCESSOR
argument_list|(
argument|getPointeeType
argument_list|)
name|LLVM_CLANG_CANPROXY_SIMPLE_ACCESSOR
argument_list|(
argument|const ObjCInterfaceType *
argument_list|,
argument|getInterfaceType
argument_list|)
name|LLVM_CLANG_CANPROXY_SIMPLE_ACCESSOR
argument_list|(
argument|bool
argument_list|,
argument|isObjCIdType
argument_list|)
name|LLVM_CLANG_CANPROXY_SIMPLE_ACCESSOR
argument_list|(
argument|bool
argument_list|,
argument|isObjCClassType
argument_list|)
name|LLVM_CLANG_CANPROXY_SIMPLE_ACCESSOR
argument_list|(
argument|bool
argument_list|,
argument|isObjCQualifiedIdType
argument_list|)
name|LLVM_CLANG_CANPROXY_SIMPLE_ACCESSOR
argument_list|(
argument|bool
argument_list|,
argument|isObjCQualifiedClassType
argument_list|)
typedef|typedef
name|ObjCObjectPointerType
operator|::
name|qual_iterator
name|qual_iterator
expr_stmt|;
name|LLVM_CLANG_CANPROXY_SIMPLE_ACCESSOR
argument_list|(
argument|qual_iterator
argument_list|,
argument|qual_begin
argument_list|)
name|LLVM_CLANG_CANPROXY_SIMPLE_ACCESSOR
argument_list|(
argument|qual_iterator
argument_list|,
argument|qual_end
argument_list|)
name|LLVM_CLANG_CANPROXY_SIMPLE_ACCESSOR
argument_list|(
argument|bool
argument_list|,
argument|qual_empty
argument_list|)
name|LLVM_CLANG_CANPROXY_SIMPLE_ACCESSOR
argument_list|(
argument|unsigned
argument_list|,
argument|getNumProtocols
argument_list|)
block|}
end_expr_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|//----------------------------------------------------------------------------//
end_comment

begin_comment
comment|// Method and function definitions
end_comment

begin_comment
comment|//----------------------------------------------------------------------------//
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|>
specifier|inline
name|CanQual
operator|<
name|T
operator|>
name|CanQual
operator|<
name|T
operator|>
operator|::
name|getUnqualifiedType
argument_list|()
specifier|const
block|{
return|return
name|CanQual
operator|<
name|T
operator|>
operator|::
name|CreateUnsafe
argument_list|(
name|Stored
operator|.
name|getLocalUnqualifiedType
argument_list|()
argument_list|)
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|>
specifier|inline
name|CanQual
operator|<
name|Type
operator|>
name|CanQual
operator|<
name|T
operator|>
operator|::
name|getNonReferenceType
argument_list|()
specifier|const
block|{
if|if
condition|(
name|CanQual
operator|<
name|ReferenceType
operator|>
name|RefType
operator|=
name|getAs
operator|<
name|ReferenceType
operator|>
operator|(
operator|)
condition|)
return|return
name|RefType
operator|->
name|getPointeeType
argument_list|()
return|;
else|else
return|return
operator|*
name|this
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|>
name|CanQual
operator|<
name|T
operator|>
name|CanQual
operator|<
name|T
operator|>
operator|::
name|getFromOpaquePtr
argument_list|(
argument|void *Ptr
argument_list|)
block|{
name|CanQual
operator|<
name|T
operator|>
name|Result
block|;
name|Result
operator|.
name|Stored
operator|.
name|setFromOpaqueValue
argument_list|(
name|Ptr
argument_list|)
block|;
name|assert
argument_list|(
operator|(
operator|!
name|Result
operator|||
name|Result
operator|.
name|Stored
operator|.
name|isCanonical
argument_list|()
operator|)
operator|&&
literal|"Type is not canonical!"
argument_list|)
block|;
return|return
name|Result
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|>
name|CanQual
operator|<
name|T
operator|>
name|CanQual
operator|<
name|T
operator|>
operator|::
name|CreateUnsafe
argument_list|(
argument|QualType Other
argument_list|)
block|{
name|assert
argument_list|(
operator|(
name|Other
operator|.
name|isNull
argument_list|()
operator|||
name|Other
operator|.
name|isCanonical
argument_list|()
operator|)
operator|&&
literal|"Type is not canonical!"
argument_list|)
block|;
name|assert
argument_list|(
operator|(
name|Other
operator|.
name|isNull
argument_list|()
operator|||
name|isa
operator|<
name|T
operator|>
operator|(
name|Other
operator|.
name|getTypePtr
argument_list|()
operator|)
operator|)
operator|&&
literal|"Dynamic type does not meet the static type's requires"
argument_list|)
block|;
name|CanQual
operator|<
name|T
operator|>
name|Result
block|;
name|Result
operator|.
name|Stored
operator|=
name|Other
block|;
return|return
name|Result
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|>
name|template
operator|<
name|typename
name|U
operator|>
name|CanProxy
operator|<
name|U
operator|>
name|CanQual
operator|<
name|T
operator|>
operator|::
name|getAs
argument_list|()
specifier|const
block|{
if|if
condition|(
name|Stored
operator|.
name|isNull
argument_list|()
condition|)
return|return
name|CanProxy
operator|<
name|U
operator|>
operator|(
operator|)
return|;
end_expr_stmt

begin_if
if|if
condition|(
name|isa
operator|<
name|U
operator|>
operator|(
name|Stored
operator|.
name|getTypePtr
argument_list|()
operator|)
condition|)
return|return
name|CanQual
operator|<
name|U
operator|>
operator|::
name|CreateUnsafe
argument_list|(
name|Stored
argument_list|)
return|;
end_if

begin_return
return|return
name|CanProxy
operator|<
name|U
operator|>
operator|(
operator|)
return|;
end_return

begin_expr_stmt
unit|}  template
operator|<
name|typename
name|T
operator|>
name|CanProxy
operator|<
name|T
operator|>
name|CanQual
operator|<
name|T
operator|>
operator|::
name|operator
operator|->
expr|(
end_expr_stmt

begin_expr_stmt
unit|)
specifier|const
block|{
return|return
name|CanProxy
operator|<
name|T
operator|>
operator|(
operator|*
name|this
operator|)
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|template
operator|<
name|typename
name|InputIterator
operator|>
name|typename
name|CanTypeIterator
operator|<
name|InputIterator
operator|>
operator|::
name|pointer
name|CanTypeIterator
operator|<
name|InputIterator
operator|>
operator|::
name|operator
operator|->
expr|(
end_expr_stmt

begin_expr_stmt
unit|)
specifier|const
block|{
return|return
name|CanProxy
operator|<
name|Type
operator|>
operator|(
operator|*
name|this
operator|)
return|;
block|}
end_expr_stmt

begin_endif
unit|}
endif|#
directive|endif
end_endif

begin_comment
comment|// LLVM_CLANG_AST_CANONICAL_TYPE_H
end_comment

end_unit

