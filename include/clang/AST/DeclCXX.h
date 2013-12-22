begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- DeclCXX.h - Classes for representing C++ declarations -*- C++ -*-=====//
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
comment|/// \brief Defines the C++ Decl subclasses, other than those for templates
end_comment

begin_comment
comment|/// (found in DeclTemplate.h) and friends (in DeclFriend.h).
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
name|LLVM_CLANG_AST_DECLCXX_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_AST_DECLCXX_H
end_define

begin_include
include|#
directive|include
file|"clang/AST/ASTUnresolvedSet.h"
end_include

begin_include
include|#
directive|include
file|"clang/AST/Decl.h"
end_include

begin_include
include|#
directive|include
file|"clang/AST/Expr.h"
end_include

begin_include
include|#
directive|include
file|"clang/AST/ExprCXX.h"
end_include

begin_include
include|#
directive|include
file|"clang/AST/TypeLoc.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/DenseMap.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/PointerIntPair.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/SmallPtrSet.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/Compiler.h"
end_include

begin_decl_stmt
name|namespace
name|clang
block|{
name|class
name|ClassTemplateDecl
decl_stmt|;
name|class
name|ClassTemplateSpecializationDecl
decl_stmt|;
name|class
name|CXXBasePath
decl_stmt|;
name|class
name|CXXBasePaths
decl_stmt|;
name|class
name|CXXConstructorDecl
decl_stmt|;
name|class
name|CXXConversionDecl
decl_stmt|;
name|class
name|CXXDestructorDecl
decl_stmt|;
name|class
name|CXXMethodDecl
decl_stmt|;
name|class
name|CXXRecordDecl
decl_stmt|;
name|class
name|CXXMemberLookupCriteria
decl_stmt|;
name|class
name|CXXFinalOverriderMap
decl_stmt|;
name|class
name|CXXIndirectPrimaryBaseSet
decl_stmt|;
name|class
name|FriendDecl
decl_stmt|;
name|class
name|LambdaExpr
decl_stmt|;
name|class
name|UsingDecl
decl_stmt|;
comment|/// \brief Represents any kind of function declaration, whether it is a
comment|/// concrete function or a function template.
name|class
name|AnyFunctionDecl
block|{
name|NamedDecl
modifier|*
name|Function
decl_stmt|;
name|AnyFunctionDecl
argument_list|(
name|NamedDecl
operator|*
name|ND
argument_list|)
operator|:
name|Function
argument_list|(
argument|ND
argument_list|)
block|{ }
name|public
operator|:
name|AnyFunctionDecl
argument_list|(
name|FunctionDecl
operator|*
name|FD
argument_list|)
operator|:
name|Function
argument_list|(
argument|FD
argument_list|)
block|{ }
name|AnyFunctionDecl
argument_list|(
name|FunctionTemplateDecl
operator|*
name|FTD
argument_list|)
expr_stmt|;
comment|/// \brief Implicily converts any function or function template into a
comment|/// named declaration.
name|operator
name|NamedDecl
operator|*
operator|(
operator|)
specifier|const
block|{
return|return
name|Function
return|;
block|}
comment|/// \brief Retrieve the underlying function or function template.
name|NamedDecl
operator|*
name|get
argument_list|()
specifier|const
block|{
return|return
name|Function
return|;
block|}
specifier|static
name|AnyFunctionDecl
name|getFromNamedDecl
parameter_list|(
name|NamedDecl
modifier|*
name|ND
parameter_list|)
block|{
return|return
name|AnyFunctionDecl
argument_list|(
name|ND
argument_list|)
return|;
block|}
block|}
empty_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// end namespace clang
end_comment

begin_decl_stmt
name|namespace
name|llvm
block|{
comment|// Provide PointerLikeTypeTraits for non-cvr pointers.
name|template
operator|<
operator|>
name|class
name|PointerLikeTypeTraits
operator|<
operator|::
name|clang
operator|::
name|AnyFunctionDecl
operator|>
block|{
name|public
operator|:
specifier|static
specifier|inline
name|void
operator|*
name|getAsVoidPointer
argument_list|(
argument|::clang::AnyFunctionDecl F
argument_list|)
block|{
return|return
name|F
operator|.
name|get
argument_list|()
return|;
block|}
specifier|static
specifier|inline
operator|::
name|clang
operator|::
name|AnyFunctionDecl
name|getFromVoidPointer
argument_list|(
argument|void *P
argument_list|)
block|{
return|return
operator|::
name|clang
operator|::
name|AnyFunctionDecl
operator|::
name|getFromNamedDecl
argument_list|(
name|static_cast
operator|<
operator|::
name|clang
operator|::
name|NamedDecl
operator|*
operator|>
operator|(
name|P
operator|)
argument_list|)
return|;
block|}
expr|enum
block|{
name|NumLowBitsAvailable
operator|=
literal|2
block|}
block|;   }
expr_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// end namespace llvm
end_comment

begin_decl_stmt
name|namespace
name|clang
block|{
comment|/// \brief Represents an access specifier followed by colon ':'.
comment|///
comment|/// An objects of this class represents sugar for the syntactic occurrence
comment|/// of an access specifier followed by a colon in the list of member
comment|/// specifiers of a C++ class definition.
comment|///
comment|/// Note that they do not represent other uses of access specifiers,
comment|/// such as those occurring in a list of base specifiers.
comment|/// Also note that this class has nothing to do with so-called
comment|/// "access declarations" (C++98 11.3 [class.access.dcl]).
name|class
name|AccessSpecDecl
range|:
name|public
name|Decl
block|{
name|virtual
name|void
name|anchor
argument_list|()
block|;
comment|/// \brief The location of the ':'.
name|SourceLocation
name|ColonLoc
block|;
name|AccessSpecDecl
argument_list|(
argument|AccessSpecifier AS
argument_list|,
argument|DeclContext *DC
argument_list|,
argument|SourceLocation ASLoc
argument_list|,
argument|SourceLocation ColonLoc
argument_list|)
operator|:
name|Decl
argument_list|(
name|AccessSpec
argument_list|,
name|DC
argument_list|,
name|ASLoc
argument_list|)
block|,
name|ColonLoc
argument_list|(
argument|ColonLoc
argument_list|)
block|{
name|setAccess
argument_list|(
name|AS
argument_list|)
block|;   }
name|AccessSpecDecl
argument_list|(
argument|EmptyShell Empty
argument_list|)
operator|:
name|Decl
argument_list|(
argument|AccessSpec
argument_list|,
argument|Empty
argument_list|)
block|{ }
name|public
operator|:
comment|/// \brief The location of the access specifier.
name|SourceLocation
name|getAccessSpecifierLoc
argument_list|()
specifier|const
block|{
return|return
name|getLocation
argument_list|()
return|;
block|}
comment|/// \brief Sets the location of the access specifier.
name|void
name|setAccessSpecifierLoc
argument_list|(
argument|SourceLocation ASLoc
argument_list|)
block|{
name|setLocation
argument_list|(
name|ASLoc
argument_list|)
block|; }
comment|/// \brief The location of the colon following the access specifier.
name|SourceLocation
name|getColonLoc
argument_list|()
specifier|const
block|{
return|return
name|ColonLoc
return|;
block|}
comment|/// \brief Sets the location of the colon.
name|void
name|setColonLoc
argument_list|(
argument|SourceLocation CLoc
argument_list|)
block|{
name|ColonLoc
operator|=
name|CLoc
block|; }
name|SourceRange
name|getSourceRange
argument_list|()
specifier|const
name|LLVM_READONLY
block|{
return|return
name|SourceRange
argument_list|(
name|getAccessSpecifierLoc
argument_list|()
argument_list|,
name|getColonLoc
argument_list|()
argument_list|)
return|;
block|}
specifier|static
name|AccessSpecDecl
operator|*
name|Create
argument_list|(
argument|ASTContext&C
argument_list|,
argument|AccessSpecifier AS
argument_list|,
argument|DeclContext *DC
argument_list|,
argument|SourceLocation ASLoc
argument_list|,
argument|SourceLocation ColonLoc
argument_list|)
block|{
return|return
name|new
argument_list|(
argument|C
argument_list|)
name|AccessSpecDecl
argument_list|(
name|AS
argument_list|,
name|DC
argument_list|,
name|ASLoc
argument_list|,
name|ColonLoc
argument_list|)
return|;
block|}
specifier|static
name|AccessSpecDecl
operator|*
name|CreateDeserialized
argument_list|(
argument|ASTContext&C
argument_list|,
argument|unsigned ID
argument_list|)
block|;
comment|// Implement isa/cast/dyncast/etc.
specifier|static
name|bool
name|classof
argument_list|(
argument|const Decl *D
argument_list|)
block|{
return|return
name|classofKind
argument_list|(
name|D
operator|->
name|getKind
argument_list|()
argument_list|)
return|;
block|}
specifier|static
name|bool
name|classofKind
argument_list|(
argument|Kind K
argument_list|)
block|{
return|return
name|K
operator|==
name|AccessSpec
return|;
block|}
expr|}
block|;
comment|/// \brief Represents a base class of a C++ class.
comment|///
comment|/// Each CXXBaseSpecifier represents a single, direct base class (or
comment|/// struct) of a C++ class (or struct). It specifies the type of that
comment|/// base class, whether it is a virtual or non-virtual base, and what
comment|/// level of access (public, protected, private) is used for the
comment|/// derivation. For example:
comment|///
comment|/// \code
comment|///   class A { };
comment|///   class B { };
comment|///   class C : public virtual A, protected B { };
comment|/// \endcode
comment|///
comment|/// In this code, C will have two CXXBaseSpecifiers, one for "public
comment|/// virtual A" and the other for "protected B".
name|class
name|CXXBaseSpecifier
block|{
comment|/// \brief The source code range that covers the full base
comment|/// specifier, including the "virtual" (if present) and access
comment|/// specifier (if present).
name|SourceRange
name|Range
block|;
comment|/// \brief The source location of the ellipsis, if this is a pack
comment|/// expansion.
name|SourceLocation
name|EllipsisLoc
block|;
comment|/// \brief Whether this is a virtual base class or not.
name|bool
name|Virtual
operator|:
literal|1
block|;
comment|/// \brief Whether this is the base of a class (true) or of a struct (false).
comment|///
comment|/// This determines the mapping from the access specifier as written in the
comment|/// source code to the access specifier used for semantic analysis.
name|bool
name|BaseOfClass
operator|:
literal|1
block|;
comment|/// \brief Access specifier as written in the source code (may be AS_none).
comment|///
comment|/// The actual type of data stored here is an AccessSpecifier, but we use
comment|/// "unsigned" here to work around a VC++ bug.
name|unsigned
name|Access
operator|:
literal|2
block|;
comment|/// \brief Whether the class contains a using declaration
comment|/// to inherit the named class's constructors.
name|bool
name|InheritConstructors
operator|:
literal|1
block|;
comment|/// \brief The type of the base class.
comment|///
comment|/// This will be a class or struct (or a typedef of such). The source code
comment|/// range does not include the \c virtual or the access specifier.
name|TypeSourceInfo
operator|*
name|BaseTypeInfo
block|;
name|public
operator|:
name|CXXBaseSpecifier
argument_list|()
block|{ }
name|CXXBaseSpecifier
argument_list|(
argument|SourceRange R
argument_list|,
argument|bool V
argument_list|,
argument|bool BC
argument_list|,
argument|AccessSpecifier A
argument_list|,
argument|TypeSourceInfo *TInfo
argument_list|,
argument|SourceLocation EllipsisLoc
argument_list|)
operator|:
name|Range
argument_list|(
name|R
argument_list|)
block|,
name|EllipsisLoc
argument_list|(
name|EllipsisLoc
argument_list|)
block|,
name|Virtual
argument_list|(
name|V
argument_list|)
block|,
name|BaseOfClass
argument_list|(
name|BC
argument_list|)
block|,
name|Access
argument_list|(
name|A
argument_list|)
block|,
name|InheritConstructors
argument_list|(
name|false
argument_list|)
block|,
name|BaseTypeInfo
argument_list|(
argument|TInfo
argument_list|)
block|{ }
comment|/// \brief Retrieves the source range that contains the entire base specifier.
name|SourceRange
name|getSourceRange
argument_list|()
specifier|const
name|LLVM_READONLY
block|{
return|return
name|Range
return|;
block|}
name|SourceLocation
name|getLocStart
argument_list|()
specifier|const
name|LLVM_READONLY
block|{
return|return
name|Range
operator|.
name|getBegin
argument_list|()
return|;
block|}
name|SourceLocation
name|getLocEnd
argument_list|()
specifier|const
name|LLVM_READONLY
block|{
return|return
name|Range
operator|.
name|getEnd
argument_list|()
return|;
block|}
comment|/// \brief Determines whether the base class is a virtual base class (or not).
name|bool
name|isVirtual
argument_list|()
specifier|const
block|{
return|return
name|Virtual
return|;
block|}
comment|/// \brief Determine whether this base class is a base of a class declared
comment|/// with the 'class' keyword (vs. one declared with the 'struct' keyword).
name|bool
name|isBaseOfClass
argument_list|()
specifier|const
block|{
return|return
name|BaseOfClass
return|;
block|}
comment|/// \brief Determine whether this base specifier is a pack expansion.
name|bool
name|isPackExpansion
argument_list|()
specifier|const
block|{
return|return
name|EllipsisLoc
operator|.
name|isValid
argument_list|()
return|;
block|}
comment|/// \brief Determine whether this base class's constructors get inherited.
name|bool
name|getInheritConstructors
argument_list|()
specifier|const
block|{
return|return
name|InheritConstructors
return|;
block|}
comment|/// \brief Set that this base class's constructors should be inherited.
name|void
name|setInheritConstructors
argument_list|(
argument|bool Inherit = true
argument_list|)
block|{
name|InheritConstructors
operator|=
name|Inherit
block|;   }
comment|/// \brief For a pack expansion, determine the location of the ellipsis.
name|SourceLocation
name|getEllipsisLoc
argument_list|()
specifier|const
block|{
return|return
name|EllipsisLoc
return|;
block|}
comment|/// \brief Returns the access specifier for this base specifier.
comment|///
comment|/// This is the actual base specifier as used for semantic analysis, so
comment|/// the result can never be AS_none. To retrieve the access specifier as
comment|/// written in the source code, use getAccessSpecifierAsWritten().
name|AccessSpecifier
name|getAccessSpecifier
argument_list|()
specifier|const
block|{
if|if
condition|(
operator|(
name|AccessSpecifier
operator|)
name|Access
operator|==
name|AS_none
condition|)
return|return
name|BaseOfClass
operator|?
name|AS_private
operator|:
name|AS_public
return|;
else|else
return|return
operator|(
name|AccessSpecifier
operator|)
name|Access
return|;
block|}
comment|/// \brief Retrieves the access specifier as written in the source code
comment|/// (which may mean that no access specifier was explicitly written).
comment|///
comment|/// Use getAccessSpecifier() to retrieve the access specifier for use in
comment|/// semantic analysis.
name|AccessSpecifier
name|getAccessSpecifierAsWritten
argument_list|()
specifier|const
block|{
return|return
operator|(
name|AccessSpecifier
operator|)
name|Access
return|;
block|}
comment|/// \brief Retrieves the type of the base class.
comment|///
comment|/// This type will always be an unqualified class type.
name|QualType
name|getType
argument_list|()
specifier|const
block|{
return|return
name|BaseTypeInfo
operator|->
name|getType
argument_list|()
operator|.
name|getUnqualifiedType
argument_list|()
return|;
block|}
comment|/// \brief Retrieves the type and source location of the base class.
name|TypeSourceInfo
operator|*
name|getTypeSourceInfo
argument_list|()
specifier|const
block|{
return|return
name|BaseTypeInfo
return|;
block|}
expr|}
block|;
comment|/// The inheritance model to use for member pointers of a given CXXRecordDecl.
block|enum
name|MSInheritanceModel
block|{
name|MSIM_Single
block|,
name|MSIM_SinglePolymorphic
block|,
name|MSIM_Multiple
block|,
name|MSIM_MultiplePolymorphic
block|,
name|MSIM_Virtual
block|,
name|MSIM_Unspecified
block|}
block|;
comment|/// \brief Represents a C++ struct/union/class.
comment|///
comment|/// FIXME: This class will disappear once we've properly taught RecordDecl
comment|/// to deal with C++-specific things.
name|class
name|CXXRecordDecl
operator|:
name|public
name|RecordDecl
block|{
name|friend
name|void
name|TagDecl
operator|::
name|startDefinition
argument_list|()
block|;
comment|/// Values used in DefinitionData fields to represent special members.
block|enum
name|SpecialMemberFlags
block|{
name|SMF_DefaultConstructor
operator|=
literal|0x1
block|,
name|SMF_CopyConstructor
operator|=
literal|0x2
block|,
name|SMF_MoveConstructor
operator|=
literal|0x4
block|,
name|SMF_CopyAssignment
operator|=
literal|0x8
block|,
name|SMF_MoveAssignment
operator|=
literal|0x10
block|,
name|SMF_Destructor
operator|=
literal|0x20
block|,
name|SMF_All
operator|=
literal|0x3f
block|}
block|;    struct
name|DefinitionData
block|{
name|DefinitionData
argument_list|(
name|CXXRecordDecl
operator|*
name|D
argument_list|)
block|;
comment|/// \brief True if this class has any user-declared constructors.
name|bool
name|UserDeclaredConstructor
operator|:
literal|1
block|;
comment|/// \brief The user-declared special members which this class has.
name|unsigned
name|UserDeclaredSpecialMembers
operator|:
literal|6
block|;
comment|/// \brief True when this class is an aggregate.
name|bool
name|Aggregate
operator|:
literal|1
block|;
comment|/// \brief True when this class is a POD-type.
name|bool
name|PlainOldData
operator|:
literal|1
block|;
comment|/// true when this class is empty for traits purposes,
comment|/// i.e. has no data members other than 0-width bit-fields, has no
comment|/// virtual function/base, and doesn't inherit from a non-empty
comment|/// class. Doesn't take union-ness into account.
name|bool
name|Empty
operator|:
literal|1
block|;
comment|/// \brief True when this class is polymorphic, i.e., has at
comment|/// least one virtual member or derives from a polymorphic class.
name|bool
name|Polymorphic
operator|:
literal|1
block|;
comment|/// \brief True when this class is abstract, i.e., has at least
comment|/// one pure virtual function, (that can come from a base class).
name|bool
name|Abstract
operator|:
literal|1
block|;
comment|/// \brief True when this class has standard layout.
comment|///
comment|/// C++11 [class]p7.  A standard-layout class is a class that:
comment|/// * has no non-static data members of type non-standard-layout class (or
comment|///   array of such types) or reference,
comment|/// * has no virtual functions (10.3) and no virtual base classes (10.1),
comment|/// * has the same access control (Clause 11) for all non-static data
comment|///   members
comment|/// * has no non-standard-layout base classes,
comment|/// * either has no non-static data members in the most derived class and at
comment|///   most one base class with non-static data members, or has no base
comment|///   classes with non-static data members, and
comment|/// * has no base classes of the same type as the first non-static data
comment|///   member.
name|bool
name|IsStandardLayout
operator|:
literal|1
block|;
comment|/// \brief True when there are no non-empty base classes.
comment|///
comment|/// This is a helper bit of state used to implement IsStandardLayout more
comment|/// efficiently.
name|bool
name|HasNoNonEmptyBases
operator|:
literal|1
block|;
comment|/// \brief True when there are private non-static data members.
name|bool
name|HasPrivateFields
operator|:
literal|1
block|;
comment|/// \brief True when there are protected non-static data members.
name|bool
name|HasProtectedFields
operator|:
literal|1
block|;
comment|/// \brief True when there are private non-static data members.
name|bool
name|HasPublicFields
operator|:
literal|1
block|;
comment|/// \brief True if this class (or any subobject) has mutable fields.
name|bool
name|HasMutableFields
operator|:
literal|1
block|;
comment|/// \brief True if there no non-field members declared by the user.
name|bool
name|HasOnlyCMembers
operator|:
literal|1
block|;
comment|/// \brief True if any field has an in-class initializer.
name|bool
name|HasInClassInitializer
operator|:
literal|1
block|;
comment|/// \brief True if any field is of reference type, and does not have an
comment|/// in-class initializer.
comment|///
comment|/// In this case, value-initialization of this class is illegal in C++98
comment|/// even if the class has a trivial default constructor.
name|bool
name|HasUninitializedReferenceMember
operator|:
literal|1
block|;
comment|/// \brief These flags are \c true if a defaulted corresponding special
comment|/// member can't be fully analyzed without performing overload resolution.
comment|/// @{
name|bool
name|NeedOverloadResolutionForMoveConstructor
operator|:
literal|1
block|;
name|bool
name|NeedOverloadResolutionForMoveAssignment
operator|:
literal|1
block|;
name|bool
name|NeedOverloadResolutionForDestructor
operator|:
literal|1
block|;
comment|/// @}
comment|/// \brief These flags are \c true if an implicit defaulted corresponding
comment|/// special member would be defined as deleted.
comment|/// @{
name|bool
name|DefaultedMoveConstructorIsDeleted
operator|:
literal|1
block|;
name|bool
name|DefaultedMoveAssignmentIsDeleted
operator|:
literal|1
block|;
name|bool
name|DefaultedDestructorIsDeleted
operator|:
literal|1
block|;
comment|/// @}
comment|/// \brief The trivial special members which this class has, per
comment|/// C++11 [class.ctor]p5, C++11 [class.copy]p12, C++11 [class.copy]p25,
comment|/// C++11 [class.dtor]p5, or would have if the member were not suppressed.
comment|///
comment|/// This excludes any user-declared but not user-provided special members
comment|/// which have been declared but not yet defined.
name|unsigned
name|HasTrivialSpecialMembers
operator|:
literal|6
block|;
comment|/// \brief The declared special members of this class which are known to be
comment|/// non-trivial.
comment|///
comment|/// This excludes any user-declared but not user-provided special members
comment|/// which have been declared but not yet defined, and any implicit special
comment|/// members which have not yet been declared.
name|unsigned
name|DeclaredNonTrivialSpecialMembers
operator|:
literal|6
block|;
comment|/// \brief True when this class has a destructor with no semantic effect.
name|bool
name|HasIrrelevantDestructor
operator|:
literal|1
block|;
comment|/// \brief True when this class has at least one user-declared constexpr
comment|/// constructor which is neither the copy nor move constructor.
name|bool
name|HasConstexprNonCopyMoveConstructor
operator|:
literal|1
block|;
comment|/// \brief True if a defaulted default constructor for this class would
comment|/// be constexpr.
name|bool
name|DefaultedDefaultConstructorIsConstexpr
operator|:
literal|1
block|;
comment|/// \brief True if this class has a constexpr default constructor.
comment|///
comment|/// This is true for either a user-declared constexpr default constructor
comment|/// or an implicitly declared constexpr default constructor..
name|bool
name|HasConstexprDefaultConstructor
operator|:
literal|1
block|;
comment|/// \brief True when this class contains at least one non-static data
comment|/// member or base class of non-literal or volatile type.
name|bool
name|HasNonLiteralTypeFieldsOrBases
operator|:
literal|1
block|;
comment|/// \brief True when visible conversion functions are already computed
comment|/// and are available.
name|bool
name|ComputedVisibleConversions
operator|:
literal|1
block|;
comment|/// \brief Whether we have a C++11 user-provided default constructor (not
comment|/// explicitly deleted or defaulted).
name|bool
name|UserProvidedDefaultConstructor
operator|:
literal|1
block|;
comment|/// \brief The special members which have been declared for this class,
comment|/// either by the user or implicitly.
name|unsigned
name|DeclaredSpecialMembers
operator|:
literal|6
block|;
comment|/// \brief Whether an implicit copy constructor would have a const-qualified
comment|/// parameter.
name|bool
name|ImplicitCopyConstructorHasConstParam
operator|:
literal|1
block|;
comment|/// \brief Whether an implicit copy assignment operator would have a
comment|/// const-qualified parameter.
name|bool
name|ImplicitCopyAssignmentHasConstParam
operator|:
literal|1
block|;
comment|/// \brief Whether any declared copy constructor has a const-qualified
comment|/// parameter.
name|bool
name|HasDeclaredCopyConstructorWithConstParam
operator|:
literal|1
block|;
comment|/// \brief Whether any declared copy assignment operator has either a
comment|/// const-qualified reference parameter or a non-reference parameter.
name|bool
name|HasDeclaredCopyAssignmentWithConstParam
operator|:
literal|1
block|;
comment|/// \brief Whether this class describes a C++ lambda.
name|bool
name|IsLambda
operator|:
literal|1
block|;
comment|/// \brief The number of base class specifiers in Bases.
name|unsigned
name|NumBases
block|;
comment|/// \brief The number of virtual base class specifiers in VBases.
name|unsigned
name|NumVBases
block|;
comment|/// \brief Base classes of this class.
comment|///
comment|/// FIXME: This is wasted space for a union.
name|LazyCXXBaseSpecifiersPtr
name|Bases
block|;
comment|/// \brief direct and indirect virtual base classes of this class.
name|LazyCXXBaseSpecifiersPtr
name|VBases
block|;
comment|/// \brief The conversion functions of this C++ class (but not its
comment|/// inherited conversion functions).
comment|///
comment|/// Each of the entries in this overload set is a CXXConversionDecl.
name|LazyASTUnresolvedSet
name|Conversions
block|;
comment|/// \brief The conversion functions of this C++ class and all those
comment|/// inherited conversion functions that are visible in this class.
comment|///
comment|/// Each of the entries in this overload set is a CXXConversionDecl or a
comment|/// FunctionTemplateDecl.
name|LazyASTUnresolvedSet
name|VisibleConversions
block|;
comment|/// \brief The declaration which defines this record.
name|CXXRecordDecl
operator|*
name|Definition
block|;
comment|/// \brief The first friend declaration in this class, or null if there
comment|/// aren't any.
comment|///
comment|/// This is actually currently stored in reverse order.
name|LazyDeclPtr
name|FirstFriend
block|;
comment|/// \brief Retrieve the set of direct base classes.
name|CXXBaseSpecifier
operator|*
name|getBases
argument_list|()
specifier|const
block|{
if|if
condition|(
operator|!
name|Bases
operator|.
name|isOffset
argument_list|()
condition|)
return|return
name|Bases
operator|.
name|get
argument_list|(
literal|0
argument_list|)
return|;
return|return
name|getBasesSlowCase
argument_list|()
return|;
block|}
comment|/// \brief Retrieve the set of virtual base classes.
name|CXXBaseSpecifier
operator|*
name|getVBases
argument_list|()
specifier|const
block|{
if|if
condition|(
operator|!
name|VBases
operator|.
name|isOffset
argument_list|()
condition|)
return|return
name|VBases
operator|.
name|get
argument_list|(
literal|0
argument_list|)
return|;
return|return
name|getVBasesSlowCase
argument_list|()
return|;
block|}
name|private
operator|:
name|CXXBaseSpecifier
operator|*
name|getBasesSlowCase
argument_list|()
specifier|const
block|;
name|CXXBaseSpecifier
operator|*
name|getVBasesSlowCase
argument_list|()
specifier|const
block|;   }
operator|*
name|DefinitionData
block|;
comment|/// \brief Describes a C++ closure type (generated by a lambda expression).
block|struct
name|LambdaDefinitionData
operator|:
name|public
name|DefinitionData
block|{
typedef|typedef
name|LambdaExpr
operator|::
name|Capture
name|Capture
expr_stmt|;
name|LambdaDefinitionData
argument_list|(
argument|CXXRecordDecl *D
argument_list|,
argument|TypeSourceInfo *Info
argument_list|,
argument|bool Dependent
argument_list|,
argument|bool IsGeneric
argument_list|,
argument|LambdaCaptureDefault CaptureDefault
argument_list|)
operator|:
name|DefinitionData
argument_list|(
name|D
argument_list|)
block|,
name|Dependent
argument_list|(
name|Dependent
argument_list|)
block|,
name|IsGenericLambda
argument_list|(
name|IsGeneric
argument_list|)
block|,
name|CaptureDefault
argument_list|(
name|CaptureDefault
argument_list|)
block|,
name|NumCaptures
argument_list|(
literal|0
argument_list|)
block|,
name|NumExplicitCaptures
argument_list|(
literal|0
argument_list|)
block|,
name|ManglingNumber
argument_list|(
literal|0
argument_list|)
block|,
name|ContextDecl
argument_list|(
literal|0
argument_list|)
block|,
name|Captures
argument_list|(
literal|0
argument_list|)
block|,
name|MethodTyInfo
argument_list|(
argument|Info
argument_list|)
block|{
name|IsLambda
operator|=
name|true
block|;     }
comment|/// \brief Whether this lambda is known to be dependent, even if its
comment|/// context isn't dependent.
comment|///
comment|/// A lambda with a non-dependent context can be dependent if it occurs
comment|/// within the default argument of a function template, because the
comment|/// lambda will have been created with the enclosing context as its
comment|/// declaration context, rather than function. This is an unfortunate
comment|/// artifact of having to parse the default arguments before.
name|unsigned
name|Dependent
operator|:
literal|1
block|;
comment|/// \brief Whether this lambda is a generic lambda.
name|unsigned
name|IsGenericLambda
operator|:
literal|1
block|;
comment|/// \brief The Default Capture.
name|unsigned
name|CaptureDefault
operator|:
literal|2
block|;
comment|/// \brief The number of captures in this lambda is limited 2^NumCaptures.
name|unsigned
name|NumCaptures
operator|:
literal|15
block|;
comment|/// \brief The number of explicit captures in this lambda.
name|unsigned
name|NumExplicitCaptures
operator|:
literal|13
block|;
comment|/// \brief The number used to indicate this lambda expression for name
comment|/// mangling in the Itanium C++ ABI.
name|unsigned
name|ManglingNumber
block|;
comment|/// \brief The declaration that provides context for this lambda, if the
comment|/// actual DeclContext does not suffice. This is used for lambdas that
comment|/// occur within default arguments of function parameters within the class
comment|/// or within a data member initializer.
name|Decl
operator|*
name|ContextDecl
block|;
comment|/// \brief The list of captures, both explicit and implicit, for this
comment|/// lambda.
name|Capture
operator|*
name|Captures
block|;
comment|/// \brief The type of the call method.
name|TypeSourceInfo
operator|*
name|MethodTyInfo
block|;           }
decl_stmt|;
name|struct
name|DefinitionData
modifier|&
name|data
function|()
block|{
name|assert
argument_list|(
name|DefinitionData
operator|&&
literal|"queried property of class with no definition"
argument_list|)
expr_stmt|;
return|return
operator|*
name|DefinitionData
return|;
block|}
specifier|const
expr|struct
name|DefinitionData
operator|&
name|data
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
name|DefinitionData
operator|&&
literal|"queried property of class with no definition"
argument_list|)
block|;
return|return
operator|*
name|DefinitionData
return|;
block|}
block|struct
name|LambdaDefinitionData
operator|&
name|getLambdaData
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
name|DefinitionData
operator|&&
literal|"queried property of lambda with no definition"
argument_list|)
block|;
name|assert
argument_list|(
name|DefinitionData
operator|->
name|IsLambda
operator|&&
literal|"queried lambda property of non-lambda class"
argument_list|)
block|;
return|return
name|static_cast
operator|<
name|LambdaDefinitionData
operator|&
operator|>
operator|(
operator|*
name|DefinitionData
operator|)
return|;
block|}
comment|/// \brief The template or declaration that this declaration
comment|/// describes or was instantiated from, respectively.
comment|///
comment|/// For non-templates, this value will be null. For record
comment|/// declarations that describe a class template, this will be a
comment|/// pointer to a ClassTemplateDecl. For member
comment|/// classes of class template specializations, this will be the
comment|/// MemberSpecializationInfo referring to the member class that was
comment|/// instantiated or specialized.
name|llvm
operator|::
name|PointerUnion
operator|<
name|ClassTemplateDecl
operator|*
operator|,
name|MemberSpecializationInfo
operator|*
operator|>
name|TemplateOrInstantiation
expr_stmt|;
name|friend
name|class
name|DeclContext
decl_stmt|;
name|friend
name|class
name|LambdaExpr
decl_stmt|;
comment|/// \brief Called from setBases and addedMember to notify the class that a
comment|/// direct or virtual base class or a member of class type has been added.
name|void
name|addedClassSubobject
parameter_list|(
name|CXXRecordDecl
modifier|*
name|Base
parameter_list|)
function_decl|;
comment|/// \brief Notify the class that member has been added.
comment|///
comment|/// This routine helps maintain information about the class based on which
comment|/// members have been added. It will be invoked by DeclContext::addDecl()
comment|/// whenever a member is added to this record.
name|void
name|addedMember
parameter_list|(
name|Decl
modifier|*
name|D
parameter_list|)
function_decl|;
name|void
name|markedVirtualFunctionPure
parameter_list|()
function_decl|;
name|friend
name|void
name|FunctionDecl
operator|::
name|setPure
argument_list|(
name|bool
argument_list|)
expr_stmt|;
name|friend
name|class
name|ASTNodeImporter
decl_stmt|;
comment|/// \brief Get the head of our list of friend declarations, possibly
comment|/// deserializing the friends from an external AST source.
name|FriendDecl
operator|*
name|getFirstFriend
argument_list|()
specifier|const
expr_stmt|;
name|protected
label|:
name|CXXRecordDecl
argument_list|(
argument|Kind K
argument_list|,
argument|TagKind TK
argument_list|,
argument|DeclContext *DC
argument_list|,
argument|SourceLocation StartLoc
argument_list|,
argument|SourceLocation IdLoc
argument_list|,
argument|IdentifierInfo *Id
argument_list|,
argument|CXXRecordDecl *PrevDecl
argument_list|)
empty_stmt|;
name|public
label|:
comment|/// \brief Iterator that traverses the base classes of a class.
typedef|typedef
name|CXXBaseSpecifier
modifier|*
name|base_class_iterator
typedef|;
comment|/// \brief Iterator that traverses the base classes of a class.
typedef|typedef
specifier|const
name|CXXBaseSpecifier
modifier|*
name|base_class_const_iterator
typedef|;
comment|/// \brief Iterator that traverses the base classes of a class in reverse
comment|/// order.
typedef|typedef
name|std
operator|::
name|reverse_iterator
operator|<
name|base_class_iterator
operator|>
name|reverse_base_class_iterator
expr_stmt|;
comment|/// \brief Iterator that traverses the base classes of a class in reverse
comment|/// order.
typedef|typedef
name|std
operator|::
name|reverse_iterator
operator|<
name|base_class_const_iterator
operator|>
name|reverse_base_class_const_iterator
expr_stmt|;
name|virtual
name|CXXRecordDecl
modifier|*
name|getCanonicalDecl
parameter_list|()
block|{
return|return
name|cast
operator|<
name|CXXRecordDecl
operator|>
operator|(
name|RecordDecl
operator|::
name|getCanonicalDecl
argument_list|()
operator|)
return|;
block|}
name|virtual
specifier|const
name|CXXRecordDecl
operator|*
name|getCanonicalDecl
argument_list|()
specifier|const
block|{
return|return
name|cast
operator|<
name|CXXRecordDecl
operator|>
operator|(
name|RecordDecl
operator|::
name|getCanonicalDecl
argument_list|()
operator|)
return|;
block|}
name|CXXRecordDecl
modifier|*
name|getPreviousDecl
parameter_list|()
block|{
return|return
name|cast_or_null
operator|<
name|CXXRecordDecl
operator|>
operator|(
name|static_cast
operator|<
name|RecordDecl
operator|*
operator|>
operator|(
name|this
operator|)
operator|->
name|getPreviousDecl
argument_list|()
operator|)
return|;
block|}
specifier|const
name|CXXRecordDecl
operator|*
name|getPreviousDecl
argument_list|()
specifier|const
block|{
return|return
name|const_cast
operator|<
name|CXXRecordDecl
operator|*
operator|>
operator|(
name|this
operator|)
operator|->
name|getPreviousDecl
argument_list|()
return|;
block|}
name|CXXRecordDecl
modifier|*
name|getMostRecentDecl
parameter_list|()
block|{
return|return
name|cast
operator|<
name|CXXRecordDecl
operator|>
operator|(
name|static_cast
operator|<
name|RecordDecl
operator|*
operator|>
operator|(
name|this
operator|)
operator|->
name|getMostRecentDecl
argument_list|()
operator|)
return|;
block|}
specifier|const
name|CXXRecordDecl
operator|*
name|getMostRecentDecl
argument_list|()
specifier|const
block|{
return|return
name|const_cast
operator|<
name|CXXRecordDecl
operator|*
operator|>
operator|(
name|this
operator|)
operator|->
name|getMostRecentDecl
argument_list|()
return|;
block|}
name|CXXRecordDecl
operator|*
name|getDefinition
argument_list|()
specifier|const
block|{
if|if
condition|(
operator|!
name|DefinitionData
condition|)
return|return
literal|0
return|;
return|return
name|data
argument_list|()
operator|.
name|Definition
return|;
block|}
end_decl_stmt

begin_expr_stmt
name|bool
name|hasDefinition
argument_list|()
specifier|const
block|{
return|return
name|DefinitionData
operator|!=
literal|0
return|;
block|}
end_expr_stmt

begin_function_decl
specifier|static
name|CXXRecordDecl
modifier|*
name|Create
parameter_list|(
specifier|const
name|ASTContext
modifier|&
name|C
parameter_list|,
name|TagKind
name|TK
parameter_list|,
name|DeclContext
modifier|*
name|DC
parameter_list|,
name|SourceLocation
name|StartLoc
parameter_list|,
name|SourceLocation
name|IdLoc
parameter_list|,
name|IdentifierInfo
modifier|*
name|Id
parameter_list|,
name|CXXRecordDecl
modifier|*
name|PrevDecl
init|=
literal|0
parameter_list|,
name|bool
name|DelayTypeCreation
init|=
name|false
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|CXXRecordDecl
modifier|*
name|CreateLambda
parameter_list|(
specifier|const
name|ASTContext
modifier|&
name|C
parameter_list|,
name|DeclContext
modifier|*
name|DC
parameter_list|,
name|TypeSourceInfo
modifier|*
name|Info
parameter_list|,
name|SourceLocation
name|Loc
parameter_list|,
name|bool
name|DependentLambda
parameter_list|,
name|bool
name|IsGeneric
parameter_list|,
name|LambdaCaptureDefault
name|CaptureDefault
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|CXXRecordDecl
modifier|*
name|CreateDeserialized
parameter_list|(
specifier|const
name|ASTContext
modifier|&
name|C
parameter_list|,
name|unsigned
name|ID
parameter_list|)
function_decl|;
end_function_decl

begin_expr_stmt
name|bool
name|isDynamicClass
argument_list|()
specifier|const
block|{
return|return
name|data
argument_list|()
operator|.
name|Polymorphic
operator|||
name|data
argument_list|()
operator|.
name|NumVBases
operator|!=
literal|0
return|;
block|}
end_expr_stmt

begin_comment
comment|/// \brief Sets the base classes of this struct or class.
end_comment

begin_function_decl
name|void
name|setBases
parameter_list|(
name|CXXBaseSpecifier
specifier|const
modifier|*
specifier|const
modifier|*
name|Bases
parameter_list|,
name|unsigned
name|NumBases
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// \brief Retrieves the number of base classes of this class.
end_comment

begin_expr_stmt
name|unsigned
name|getNumBases
argument_list|()
specifier|const
block|{
return|return
name|data
argument_list|()
operator|.
name|NumBases
return|;
block|}
end_expr_stmt

begin_function
name|base_class_iterator
name|bases_begin
parameter_list|()
block|{
return|return
name|data
argument_list|()
operator|.
name|getBases
argument_list|()
return|;
block|}
end_function

begin_expr_stmt
name|base_class_const_iterator
name|bases_begin
argument_list|()
specifier|const
block|{
return|return
name|data
argument_list|()
operator|.
name|getBases
argument_list|()
return|;
block|}
end_expr_stmt

begin_function
name|base_class_iterator
name|bases_end
parameter_list|()
block|{
return|return
name|bases_begin
argument_list|()
operator|+
name|data
argument_list|()
operator|.
name|NumBases
return|;
block|}
end_function

begin_expr_stmt
name|base_class_const_iterator
name|bases_end
argument_list|()
specifier|const
block|{
return|return
name|bases_begin
argument_list|()
operator|+
name|data
argument_list|()
operator|.
name|NumBases
return|;
block|}
end_expr_stmt

begin_function
name|reverse_base_class_iterator
name|bases_rbegin
parameter_list|()
block|{
return|return
name|reverse_base_class_iterator
argument_list|(
name|bases_end
argument_list|()
argument_list|)
return|;
block|}
end_function

begin_expr_stmt
name|reverse_base_class_const_iterator
name|bases_rbegin
argument_list|()
specifier|const
block|{
return|return
name|reverse_base_class_const_iterator
argument_list|(
name|bases_end
argument_list|()
argument_list|)
return|;
block|}
end_expr_stmt

begin_function
name|reverse_base_class_iterator
name|bases_rend
parameter_list|()
block|{
return|return
name|reverse_base_class_iterator
argument_list|(
name|bases_begin
argument_list|()
argument_list|)
return|;
block|}
end_function

begin_expr_stmt
name|reverse_base_class_const_iterator
name|bases_rend
argument_list|()
specifier|const
block|{
return|return
name|reverse_base_class_const_iterator
argument_list|(
name|bases_begin
argument_list|()
argument_list|)
return|;
block|}
end_expr_stmt

begin_comment
comment|/// \brief Retrieves the number of virtual base classes of this class.
end_comment

begin_expr_stmt
name|unsigned
name|getNumVBases
argument_list|()
specifier|const
block|{
return|return
name|data
argument_list|()
operator|.
name|NumVBases
return|;
block|}
end_expr_stmt

begin_function
name|base_class_iterator
name|vbases_begin
parameter_list|()
block|{
return|return
name|data
argument_list|()
operator|.
name|getVBases
argument_list|()
return|;
block|}
end_function

begin_expr_stmt
name|base_class_const_iterator
name|vbases_begin
argument_list|()
specifier|const
block|{
return|return
name|data
argument_list|()
operator|.
name|getVBases
argument_list|()
return|;
block|}
end_expr_stmt

begin_function
name|base_class_iterator
name|vbases_end
parameter_list|()
block|{
return|return
name|vbases_begin
argument_list|()
operator|+
name|data
argument_list|()
operator|.
name|NumVBases
return|;
block|}
end_function

begin_expr_stmt
name|base_class_const_iterator
name|vbases_end
argument_list|()
specifier|const
block|{
return|return
name|vbases_begin
argument_list|()
operator|+
name|data
argument_list|()
operator|.
name|NumVBases
return|;
block|}
end_expr_stmt

begin_function
name|reverse_base_class_iterator
name|vbases_rbegin
parameter_list|()
block|{
return|return
name|reverse_base_class_iterator
argument_list|(
name|vbases_end
argument_list|()
argument_list|)
return|;
block|}
end_function

begin_expr_stmt
name|reverse_base_class_const_iterator
name|vbases_rbegin
argument_list|()
specifier|const
block|{
return|return
name|reverse_base_class_const_iterator
argument_list|(
name|vbases_end
argument_list|()
argument_list|)
return|;
block|}
end_expr_stmt

begin_function
name|reverse_base_class_iterator
name|vbases_rend
parameter_list|()
block|{
return|return
name|reverse_base_class_iterator
argument_list|(
name|vbases_begin
argument_list|()
argument_list|)
return|;
block|}
end_function

begin_expr_stmt
name|reverse_base_class_const_iterator
name|vbases_rend
argument_list|()
specifier|const
block|{
return|return
name|reverse_base_class_const_iterator
argument_list|(
name|vbases_begin
argument_list|()
argument_list|)
return|;
block|}
end_expr_stmt

begin_comment
comment|/// \brief Determine whether this class has any dependent base classes which
end_comment

begin_comment
comment|/// are not the current instantiation.
end_comment

begin_expr_stmt
name|bool
name|hasAnyDependentBases
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// Iterator access to method members.  The method iterator visits
end_comment

begin_comment
comment|/// all method members of the class, including non-instance methods,
end_comment

begin_comment
comment|/// special methods, etc.
end_comment

begin_typedef
typedef|typedef
name|specific_decl_iterator
operator|<
name|CXXMethodDecl
operator|>
name|method_iterator
expr_stmt|;
end_typedef

begin_comment
comment|/// \brief Method begin iterator.  Iterates in the order the methods
end_comment

begin_comment
comment|/// were declared.
end_comment

begin_expr_stmt
name|method_iterator
name|method_begin
argument_list|()
specifier|const
block|{
return|return
name|method_iterator
argument_list|(
name|decls_begin
argument_list|()
argument_list|)
return|;
block|}
end_expr_stmt

begin_comment
comment|/// \brief Method past-the-end iterator.
end_comment

begin_expr_stmt
name|method_iterator
name|method_end
argument_list|()
specifier|const
block|{
return|return
name|method_iterator
argument_list|(
name|decls_end
argument_list|()
argument_list|)
return|;
block|}
end_expr_stmt

begin_comment
comment|/// Iterator access to constructor members.
end_comment

begin_typedef
typedef|typedef
name|specific_decl_iterator
operator|<
name|CXXConstructorDecl
operator|>
name|ctor_iterator
expr_stmt|;
end_typedef

begin_expr_stmt
name|ctor_iterator
name|ctor_begin
argument_list|()
specifier|const
block|{
return|return
name|ctor_iterator
argument_list|(
name|decls_begin
argument_list|()
argument_list|)
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|ctor_iterator
name|ctor_end
argument_list|()
specifier|const
block|{
return|return
name|ctor_iterator
argument_list|(
name|decls_end
argument_list|()
argument_list|)
return|;
block|}
end_expr_stmt

begin_comment
comment|/// An iterator over friend declarations.  All of these are defined
end_comment

begin_comment
comment|/// in DeclFriend.h.
end_comment

begin_decl_stmt
name|class
name|friend_iterator
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|friend_iterator
name|friend_begin
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|friend_iterator
name|friend_end
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt

begin_function_decl
name|void
name|pushFriendDecl
parameter_list|(
name|FriendDecl
modifier|*
name|FD
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// Determines whether this record has any friends.
end_comment

begin_expr_stmt
name|bool
name|hasFriends
argument_list|()
specifier|const
block|{
return|return
name|data
argument_list|()
operator|.
name|FirstFriend
operator|.
name|isValid
argument_list|()
return|;
block|}
end_expr_stmt

begin_comment
comment|/// \brief \c true if we know for sure that this class has a single,
end_comment

begin_comment
comment|/// accessible, unambiguous move constructor that is not deleted.
end_comment

begin_expr_stmt
name|bool
name|hasSimpleMoveConstructor
argument_list|()
specifier|const
block|{
return|return
operator|!
name|hasUserDeclaredMoveConstructor
argument_list|()
operator|&&
name|hasMoveConstructor
argument_list|()
operator|&&
operator|!
name|data
argument_list|()
operator|.
name|DefaultedMoveConstructorIsDeleted
return|;
block|}
end_expr_stmt

begin_comment
comment|/// \brief \c true if we know for sure that this class has a single,
end_comment

begin_comment
comment|/// accessible, unambiguous move assignment operator that is not deleted.
end_comment

begin_expr_stmt
name|bool
name|hasSimpleMoveAssignment
argument_list|()
specifier|const
block|{
return|return
operator|!
name|hasUserDeclaredMoveAssignment
argument_list|()
operator|&&
name|hasMoveAssignment
argument_list|()
operator|&&
operator|!
name|data
argument_list|()
operator|.
name|DefaultedMoveAssignmentIsDeleted
return|;
block|}
end_expr_stmt

begin_comment
comment|/// \brief \c true if we know for sure that this class has an accessible
end_comment

begin_comment
comment|/// destructor that is not deleted.
end_comment

begin_expr_stmt
name|bool
name|hasSimpleDestructor
argument_list|()
specifier|const
block|{
return|return
operator|!
name|hasUserDeclaredDestructor
argument_list|()
operator|&&
operator|!
name|data
argument_list|()
operator|.
name|DefaultedDestructorIsDeleted
return|;
block|}
end_expr_stmt

begin_comment
comment|/// \brief Determine whether this class has any default constructors.
end_comment

begin_expr_stmt
name|bool
name|hasDefaultConstructor
argument_list|()
specifier|const
block|{
return|return
operator|(
name|data
argument_list|()
operator|.
name|DeclaredSpecialMembers
operator|&
name|SMF_DefaultConstructor
operator|)
operator|||
name|needsImplicitDefaultConstructor
argument_list|()
return|;
block|}
end_expr_stmt

begin_comment
comment|/// \brief Determine if we need to declare a default constructor for
end_comment

begin_comment
comment|/// this class.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This value is used for lazy creation of default constructors.
end_comment

begin_expr_stmt
name|bool
name|needsImplicitDefaultConstructor
argument_list|()
specifier|const
block|{
return|return
operator|!
name|data
argument_list|()
operator|.
name|UserDeclaredConstructor
operator|&&
operator|!
operator|(
name|data
argument_list|()
operator|.
name|DeclaredSpecialMembers
operator|&
name|SMF_DefaultConstructor
operator|)
return|;
block|}
end_expr_stmt

begin_comment
comment|/// \brief Determine whether this class has any user-declared constructors.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// When true, a default constructor will not be implicitly declared.
end_comment

begin_expr_stmt
name|bool
name|hasUserDeclaredConstructor
argument_list|()
specifier|const
block|{
return|return
name|data
argument_list|()
operator|.
name|UserDeclaredConstructor
return|;
block|}
end_expr_stmt

begin_comment
comment|/// \brief Whether this class has a user-provided default constructor
end_comment

begin_comment
comment|/// per C++11.
end_comment

begin_expr_stmt
name|bool
name|hasUserProvidedDefaultConstructor
argument_list|()
specifier|const
block|{
return|return
name|data
argument_list|()
operator|.
name|UserProvidedDefaultConstructor
return|;
block|}
end_expr_stmt

begin_comment
comment|/// \brief Determine whether this class has a user-declared copy constructor.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// When false, a copy constructor will be implicitly declared.
end_comment

begin_expr_stmt
name|bool
name|hasUserDeclaredCopyConstructor
argument_list|()
specifier|const
block|{
return|return
name|data
argument_list|()
operator|.
name|UserDeclaredSpecialMembers
operator|&
name|SMF_CopyConstructor
return|;
block|}
end_expr_stmt

begin_comment
comment|/// \brief Determine whether this class needs an implicit copy
end_comment

begin_comment
comment|/// constructor to be lazily declared.
end_comment

begin_expr_stmt
name|bool
name|needsImplicitCopyConstructor
argument_list|()
specifier|const
block|{
return|return
operator|!
operator|(
name|data
argument_list|()
operator|.
name|DeclaredSpecialMembers
operator|&
name|SMF_CopyConstructor
operator|)
return|;
block|}
end_expr_stmt

begin_comment
comment|/// \brief Determine whether we need to eagerly declare a defaulted copy
end_comment

begin_comment
comment|/// constructor for this class.
end_comment

begin_expr_stmt
name|bool
name|needsOverloadResolutionForCopyConstructor
argument_list|()
specifier|const
block|{
return|return
name|data
argument_list|()
operator|.
name|HasMutableFields
return|;
block|}
end_expr_stmt

begin_comment
comment|/// \brief Determine whether an implicit copy constructor for this type
end_comment

begin_comment
comment|/// would have a parameter with a const-qualified reference type.
end_comment

begin_expr_stmt
name|bool
name|implicitCopyConstructorHasConstParam
argument_list|()
specifier|const
block|{
return|return
name|data
argument_list|()
operator|.
name|ImplicitCopyConstructorHasConstParam
return|;
block|}
end_expr_stmt

begin_comment
comment|/// \brief Determine whether this class has a copy constructor with
end_comment

begin_comment
comment|/// a parameter type which is a reference to a const-qualified type.
end_comment

begin_expr_stmt
name|bool
name|hasCopyConstructorWithConstParam
argument_list|()
specifier|const
block|{
return|return
name|data
argument_list|()
operator|.
name|HasDeclaredCopyConstructorWithConstParam
operator|||
operator|(
name|needsImplicitCopyConstructor
argument_list|()
operator|&&
name|implicitCopyConstructorHasConstParam
argument_list|()
operator|)
return|;
block|}
end_expr_stmt

begin_comment
comment|/// \brief Whether this class has a user-declared move constructor or
end_comment

begin_comment
comment|/// assignment operator.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// When false, a move constructor and assignment operator may be
end_comment

begin_comment
comment|/// implicitly declared.
end_comment

begin_expr_stmt
name|bool
name|hasUserDeclaredMoveOperation
argument_list|()
specifier|const
block|{
return|return
name|data
argument_list|()
operator|.
name|UserDeclaredSpecialMembers
operator|&
operator|(
name|SMF_MoveConstructor
operator||
name|SMF_MoveAssignment
operator|)
return|;
block|}
end_expr_stmt

begin_comment
comment|/// \brief Determine whether this class has had a move constructor
end_comment

begin_comment
comment|/// declared by the user.
end_comment

begin_expr_stmt
name|bool
name|hasUserDeclaredMoveConstructor
argument_list|()
specifier|const
block|{
return|return
name|data
argument_list|()
operator|.
name|UserDeclaredSpecialMembers
operator|&
name|SMF_MoveConstructor
return|;
block|}
end_expr_stmt

begin_comment
comment|/// \brief Determine whether this class has a move constructor.
end_comment

begin_expr_stmt
name|bool
name|hasMoveConstructor
argument_list|()
specifier|const
block|{
return|return
operator|(
name|data
argument_list|()
operator|.
name|DeclaredSpecialMembers
operator|&
name|SMF_MoveConstructor
operator|)
operator|||
name|needsImplicitMoveConstructor
argument_list|()
return|;
block|}
end_expr_stmt

begin_comment
comment|/// \brief Set that we attempted to declare an implicitly move
end_comment

begin_comment
comment|/// constructor, but overload resolution failed so we deleted it.
end_comment

begin_function
name|void
name|setImplicitMoveConstructorIsDeleted
parameter_list|()
block|{
name|assert
argument_list|(
operator|(
name|data
argument_list|()
operator|.
name|DefaultedMoveConstructorIsDeleted
operator|||
name|needsOverloadResolutionForMoveConstructor
argument_list|()
operator|)
operator|&&
literal|"move constructor should not be deleted"
argument_list|)
expr_stmt|;
name|data
argument_list|()
operator|.
name|DefaultedMoveConstructorIsDeleted
operator|=
name|true
expr_stmt|;
block|}
end_function

begin_comment
comment|/// \brief Determine whether this class should get an implicit move
end_comment

begin_comment
comment|/// constructor or if any existing special member function inhibits this.
end_comment

begin_expr_stmt
name|bool
name|needsImplicitMoveConstructor
argument_list|()
specifier|const
block|{
return|return
operator|!
operator|(
name|data
argument_list|()
operator|.
name|DeclaredSpecialMembers
operator|&
name|SMF_MoveConstructor
operator|)
operator|&&
operator|!
name|hasUserDeclaredCopyConstructor
argument_list|()
operator|&&
operator|!
name|hasUserDeclaredCopyAssignment
argument_list|()
operator|&&
operator|!
name|hasUserDeclaredMoveAssignment
argument_list|()
operator|&&
operator|!
name|hasUserDeclaredDestructor
argument_list|()
return|;
block|}
end_expr_stmt

begin_comment
comment|/// \brief Determine whether we need to eagerly declare a defaulted move
end_comment

begin_comment
comment|/// constructor for this class.
end_comment

begin_expr_stmt
name|bool
name|needsOverloadResolutionForMoveConstructor
argument_list|()
specifier|const
block|{
return|return
name|data
argument_list|()
operator|.
name|NeedOverloadResolutionForMoveConstructor
return|;
block|}
end_expr_stmt

begin_comment
comment|/// \brief Determine whether this class has a user-declared copy assignment
end_comment

begin_comment
comment|/// operator.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// When false, a copy assigment operator will be implicitly declared.
end_comment

begin_expr_stmt
name|bool
name|hasUserDeclaredCopyAssignment
argument_list|()
specifier|const
block|{
return|return
name|data
argument_list|()
operator|.
name|UserDeclaredSpecialMembers
operator|&
name|SMF_CopyAssignment
return|;
block|}
end_expr_stmt

begin_comment
comment|/// \brief Determine whether this class needs an implicit copy
end_comment

begin_comment
comment|/// assignment operator to be lazily declared.
end_comment

begin_expr_stmt
name|bool
name|needsImplicitCopyAssignment
argument_list|()
specifier|const
block|{
return|return
operator|!
operator|(
name|data
argument_list|()
operator|.
name|DeclaredSpecialMembers
operator|&
name|SMF_CopyAssignment
operator|)
return|;
block|}
end_expr_stmt

begin_comment
comment|/// \brief Determine whether we need to eagerly declare a defaulted copy
end_comment

begin_comment
comment|/// assignment operator for this class.
end_comment

begin_expr_stmt
name|bool
name|needsOverloadResolutionForCopyAssignment
argument_list|()
specifier|const
block|{
return|return
name|data
argument_list|()
operator|.
name|HasMutableFields
return|;
block|}
end_expr_stmt

begin_comment
comment|/// \brief Determine whether an implicit copy assignment operator for this
end_comment

begin_comment
comment|/// type would have a parameter with a const-qualified reference type.
end_comment

begin_expr_stmt
name|bool
name|implicitCopyAssignmentHasConstParam
argument_list|()
specifier|const
block|{
return|return
name|data
argument_list|()
operator|.
name|ImplicitCopyAssignmentHasConstParam
return|;
block|}
end_expr_stmt

begin_comment
comment|/// \brief Determine whether this class has a copy assignment operator with
end_comment

begin_comment
comment|/// a parameter type which is a reference to a const-qualified type or is not
end_comment

begin_comment
comment|/// a reference.
end_comment

begin_expr_stmt
name|bool
name|hasCopyAssignmentWithConstParam
argument_list|()
specifier|const
block|{
return|return
name|data
argument_list|()
operator|.
name|HasDeclaredCopyAssignmentWithConstParam
operator|||
operator|(
name|needsImplicitCopyAssignment
argument_list|()
operator|&&
name|implicitCopyAssignmentHasConstParam
argument_list|()
operator|)
return|;
block|}
end_expr_stmt

begin_comment
comment|/// \brief Determine whether this class has had a move assignment
end_comment

begin_comment
comment|/// declared by the user.
end_comment

begin_expr_stmt
name|bool
name|hasUserDeclaredMoveAssignment
argument_list|()
specifier|const
block|{
return|return
name|data
argument_list|()
operator|.
name|UserDeclaredSpecialMembers
operator|&
name|SMF_MoveAssignment
return|;
block|}
end_expr_stmt

begin_comment
comment|/// \brief Determine whether this class has a move assignment operator.
end_comment

begin_expr_stmt
name|bool
name|hasMoveAssignment
argument_list|()
specifier|const
block|{
return|return
operator|(
name|data
argument_list|()
operator|.
name|DeclaredSpecialMembers
operator|&
name|SMF_MoveAssignment
operator|)
operator|||
name|needsImplicitMoveAssignment
argument_list|()
return|;
block|}
end_expr_stmt

begin_comment
comment|/// \brief Set that we attempted to declare an implicit move assignment
end_comment

begin_comment
comment|/// operator, but overload resolution failed so we deleted it.
end_comment

begin_function
name|void
name|setImplicitMoveAssignmentIsDeleted
parameter_list|()
block|{
name|assert
argument_list|(
operator|(
name|data
argument_list|()
operator|.
name|DefaultedMoveAssignmentIsDeleted
operator|||
name|needsOverloadResolutionForMoveAssignment
argument_list|()
operator|)
operator|&&
literal|"move assignment should not be deleted"
argument_list|)
expr_stmt|;
name|data
argument_list|()
operator|.
name|DefaultedMoveAssignmentIsDeleted
operator|=
name|true
expr_stmt|;
block|}
end_function

begin_comment
comment|/// \brief Determine whether this class should get an implicit move
end_comment

begin_comment
comment|/// assignment operator or if any existing special member function inhibits
end_comment

begin_comment
comment|/// this.
end_comment

begin_expr_stmt
name|bool
name|needsImplicitMoveAssignment
argument_list|()
specifier|const
block|{
return|return
operator|!
operator|(
name|data
argument_list|()
operator|.
name|DeclaredSpecialMembers
operator|&
name|SMF_MoveAssignment
operator|)
operator|&&
operator|!
name|hasUserDeclaredCopyConstructor
argument_list|()
operator|&&
operator|!
name|hasUserDeclaredCopyAssignment
argument_list|()
operator|&&
operator|!
name|hasUserDeclaredMoveConstructor
argument_list|()
operator|&&
operator|!
name|hasUserDeclaredDestructor
argument_list|()
return|;
block|}
end_expr_stmt

begin_comment
comment|/// \brief Determine whether we need to eagerly declare a move assignment
end_comment

begin_comment
comment|/// operator for this class.
end_comment

begin_expr_stmt
name|bool
name|needsOverloadResolutionForMoveAssignment
argument_list|()
specifier|const
block|{
return|return
name|data
argument_list|()
operator|.
name|NeedOverloadResolutionForMoveAssignment
return|;
block|}
end_expr_stmt

begin_comment
comment|/// \brief Determine whether this class has a user-declared destructor.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// When false, a destructor will be implicitly declared.
end_comment

begin_expr_stmt
name|bool
name|hasUserDeclaredDestructor
argument_list|()
specifier|const
block|{
return|return
name|data
argument_list|()
operator|.
name|UserDeclaredSpecialMembers
operator|&
name|SMF_Destructor
return|;
block|}
end_expr_stmt

begin_comment
comment|/// \brief Determine whether this class needs an implicit destructor to
end_comment

begin_comment
comment|/// be lazily declared.
end_comment

begin_expr_stmt
name|bool
name|needsImplicitDestructor
argument_list|()
specifier|const
block|{
return|return
operator|!
operator|(
name|data
argument_list|()
operator|.
name|DeclaredSpecialMembers
operator|&
name|SMF_Destructor
operator|)
return|;
block|}
end_expr_stmt

begin_comment
comment|/// \brief Determine whether we need to eagerly declare a destructor for this
end_comment

begin_comment
comment|/// class.
end_comment

begin_expr_stmt
name|bool
name|needsOverloadResolutionForDestructor
argument_list|()
specifier|const
block|{
return|return
name|data
argument_list|()
operator|.
name|NeedOverloadResolutionForDestructor
return|;
block|}
end_expr_stmt

begin_comment
comment|/// \brief Determine whether this class describes a lambda function object.
end_comment

begin_expr_stmt
name|bool
name|isLambda
argument_list|()
specifier|const
block|{
return|return
name|hasDefinition
argument_list|()
operator|&&
name|data
argument_list|()
operator|.
name|IsLambda
return|;
block|}
end_expr_stmt

begin_comment
comment|/// \brief Determine whether this class describes a generic
end_comment

begin_comment
comment|/// lambda function object (i.e. function call operator is
end_comment

begin_comment
comment|/// a template).
end_comment

begin_expr_stmt
name|bool
name|isGenericLambda
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// \brief Retrieve the lambda call operator of the closure type
end_comment

begin_comment
comment|/// if this is a closure type.
end_comment

begin_expr_stmt
name|CXXMethodDecl
operator|*
name|getLambdaCallOperator
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// \brief Retrieve the lambda static invoker, the address of which
end_comment

begin_comment
comment|/// is returned by the conversion operator, and the body of which
end_comment

begin_comment
comment|/// is forwarded to the lambda call operator.
end_comment

begin_expr_stmt
name|CXXMethodDecl
operator|*
name|getLambdaStaticInvoker
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// \brief Retrieve the generic lambda's template parameter list.
end_comment

begin_comment
comment|/// Returns null if the class does not represent a lambda or a generic
end_comment

begin_comment
comment|/// lambda.
end_comment

begin_expr_stmt
name|TemplateParameterList
operator|*
name|getGenericLambdaTemplateParameterList
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|LambdaCaptureDefault
name|getLambdaCaptureDefault
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
name|isLambda
argument_list|()
argument_list|)
block|;
return|return
name|static_cast
operator|<
name|LambdaCaptureDefault
operator|>
operator|(
name|getLambdaData
argument_list|()
operator|.
name|CaptureDefault
operator|)
return|;
block|}
end_expr_stmt

begin_comment
comment|/// \brief For a closure type, retrieve the mapping from captured
end_comment

begin_comment
comment|/// variables and \c this to the non-static data members that store the
end_comment

begin_comment
comment|/// values or references of the captures.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param Captures Will be populated with the mapping from captured
end_comment

begin_comment
comment|/// variables to the corresponding fields.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param ThisCapture Will be set to the field declaration for the
end_comment

begin_comment
comment|/// \c this capture.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \note No entries will be added for init-captures, as they do not capture
end_comment

begin_comment
comment|/// variables.
end_comment

begin_decl_stmt
name|void
name|getCaptureFields
argument_list|(
name|llvm
operator|::
name|DenseMap
operator|<
specifier|const
name|VarDecl
operator|*
argument_list|,
name|FieldDecl
operator|*
operator|>
operator|&
name|Captures
argument_list|,
name|FieldDecl
operator|*
operator|&
name|ThisCapture
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_typedef
typedef|typedef
specifier|const
name|LambdaExpr
operator|::
name|Capture
operator|*
name|capture_const_iterator
expr_stmt|;
end_typedef

begin_expr_stmt
name|capture_const_iterator
name|captures_begin
argument_list|()
specifier|const
block|{
return|return
name|isLambda
argument_list|()
operator|?
name|getLambdaData
argument_list|()
operator|.
name|Captures
operator|:
name|NULL
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|capture_const_iterator
name|captures_end
argument_list|()
specifier|const
block|{
return|return
name|isLambda
argument_list|()
operator|?
name|captures_begin
argument_list|()
operator|+
name|getLambdaData
argument_list|()
operator|.
name|NumCaptures
operator|:
name|NULL
return|;
block|}
end_expr_stmt

begin_typedef
typedef|typedef
name|UnresolvedSetIterator
name|conversion_iterator
typedef|;
end_typedef

begin_expr_stmt
name|conversion_iterator
name|conversion_begin
argument_list|()
specifier|const
block|{
return|return
name|data
argument_list|()
operator|.
name|Conversions
operator|.
name|get
argument_list|(
name|getASTContext
argument_list|()
argument_list|)
operator|.
name|begin
argument_list|()
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|conversion_iterator
name|conversion_end
argument_list|()
specifier|const
block|{
return|return
name|data
argument_list|()
operator|.
name|Conversions
operator|.
name|get
argument_list|(
name|getASTContext
argument_list|()
argument_list|)
operator|.
name|end
argument_list|()
return|;
block|}
end_expr_stmt

begin_comment
comment|/// Removes a conversion function from this class.  The conversion
end_comment

begin_comment
comment|/// function must currently be a member of this class.  Furthermore,
end_comment

begin_comment
comment|/// this class must currently be in the process of being defined.
end_comment

begin_function_decl
name|void
name|removeConversion
parameter_list|(
specifier|const
name|NamedDecl
modifier|*
name|Old
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// \brief Get all conversion functions visible in current class,
end_comment

begin_comment
comment|/// including conversion function templates.
end_comment

begin_expr_stmt
name|std
operator|::
name|pair
operator|<
name|conversion_iterator
operator|,
name|conversion_iterator
operator|>
name|getVisibleConversionFunctions
argument_list|()
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// Determine whether this class is an aggregate (C++ [dcl.init.aggr]),
end_comment

begin_comment
comment|/// which is a class with no user-declared constructors, no private
end_comment

begin_comment
comment|/// or protected non-static data members, no base classes, and no virtual
end_comment

begin_comment
comment|/// functions (C++ [dcl.init.aggr]p1).
end_comment

begin_expr_stmt
name|bool
name|isAggregate
argument_list|()
specifier|const
block|{
return|return
name|data
argument_list|()
operator|.
name|Aggregate
return|;
block|}
end_expr_stmt

begin_comment
comment|/// \brief Whether this class has any in-class initializers
end_comment

begin_comment
comment|/// for non-static data members.
end_comment

begin_expr_stmt
name|bool
name|hasInClassInitializer
argument_list|()
specifier|const
block|{
return|return
name|data
argument_list|()
operator|.
name|HasInClassInitializer
return|;
block|}
end_expr_stmt

begin_comment
comment|/// \brief Whether this class or any of its subobjects has any members of
end_comment

begin_comment
comment|/// reference type which would make value-initialization ill-formed.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Per C++03 [dcl.init]p5:
end_comment

begin_comment
comment|///  - if T is a non-union class type without a user-declared constructor,
end_comment

begin_comment
comment|///    then every non-static data member and base-class component of T is
end_comment

begin_comment
comment|///    value-initialized [...] A program that calls for [...]
end_comment

begin_comment
comment|///    value-initialization of an entity of reference type is ill-formed.
end_comment

begin_expr_stmt
name|bool
name|hasUninitializedReferenceMember
argument_list|()
specifier|const
block|{
return|return
operator|!
name|isUnion
argument_list|()
operator|&&
operator|!
name|hasUserDeclaredConstructor
argument_list|()
operator|&&
name|data
argument_list|()
operator|.
name|HasUninitializedReferenceMember
return|;
block|}
end_expr_stmt

begin_comment
comment|/// \brief Whether this class is a POD-type (C++ [class]p4)
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// For purposes of this function a class is POD if it is an aggregate
end_comment

begin_comment
comment|/// that has no non-static non-POD data members, no reference data
end_comment

begin_comment
comment|/// members, no user-defined copy assignment operator and no
end_comment

begin_comment
comment|/// user-defined destructor.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Note that this is the C++ TR1 definition of POD.
end_comment

begin_expr_stmt
name|bool
name|isPOD
argument_list|()
specifier|const
block|{
return|return
name|data
argument_list|()
operator|.
name|PlainOldData
return|;
block|}
end_expr_stmt

begin_comment
comment|/// \brief True if this class is C-like, without C++-specific features, e.g.
end_comment

begin_comment
comment|/// it contains only public fields, no bases, tag kind is not 'class', etc.
end_comment

begin_expr_stmt
name|bool
name|isCLike
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// \brief Determine whether this is an empty class in the sense of
end_comment

begin_comment
comment|/// (C++11 [meta.unary.prop]).
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// A non-union class is empty iff it has a virtual function, virtual base,
end_comment

begin_comment
comment|/// data member (other than 0-width bit-field) or inherits from a non-empty
end_comment

begin_comment
comment|/// class.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \note This does NOT include a check for union-ness.
end_comment

begin_expr_stmt
name|bool
name|isEmpty
argument_list|()
specifier|const
block|{
return|return
name|data
argument_list|()
operator|.
name|Empty
return|;
block|}
end_expr_stmt

begin_comment
comment|/// Whether this class is polymorphic (C++ [class.virtual]),
end_comment

begin_comment
comment|/// which means that the class contains or inherits a virtual function.
end_comment

begin_expr_stmt
name|bool
name|isPolymorphic
argument_list|()
specifier|const
block|{
return|return
name|data
argument_list|()
operator|.
name|Polymorphic
return|;
block|}
end_expr_stmt

begin_comment
comment|/// \brief Determine whether this class has a pure virtual function.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// The class is is abstract per (C++ [class.abstract]p2) if it declares
end_comment

begin_comment
comment|/// a pure virtual function or inherits a pure virtual function that is
end_comment

begin_comment
comment|/// not overridden.
end_comment

begin_expr_stmt
name|bool
name|isAbstract
argument_list|()
specifier|const
block|{
return|return
name|data
argument_list|()
operator|.
name|Abstract
return|;
block|}
end_expr_stmt

begin_comment
comment|/// \brief Determine whether this class has standard layout per
end_comment

begin_comment
comment|/// (C++ [class]p7)
end_comment

begin_expr_stmt
name|bool
name|isStandardLayout
argument_list|()
specifier|const
block|{
return|return
name|data
argument_list|()
operator|.
name|IsStandardLayout
return|;
block|}
end_expr_stmt

begin_comment
comment|/// \brief Determine whether this class, or any of its class subobjects,
end_comment

begin_comment
comment|/// contains a mutable field.
end_comment

begin_expr_stmt
name|bool
name|hasMutableFields
argument_list|()
specifier|const
block|{
return|return
name|data
argument_list|()
operator|.
name|HasMutableFields
return|;
block|}
end_expr_stmt

begin_comment
comment|/// \brief Determine whether this class has a trivial default constructor
end_comment

begin_comment
comment|/// (C++11 [class.ctor]p5).
end_comment

begin_expr_stmt
name|bool
name|hasTrivialDefaultConstructor
argument_list|()
specifier|const
block|{
return|return
name|hasDefaultConstructor
argument_list|()
operator|&&
operator|(
name|data
argument_list|()
operator|.
name|HasTrivialSpecialMembers
operator|&
name|SMF_DefaultConstructor
operator|)
return|;
block|}
end_expr_stmt

begin_comment
comment|/// \brief Determine whether this class has a non-trivial default constructor
end_comment

begin_comment
comment|/// (C++11 [class.ctor]p5).
end_comment

begin_expr_stmt
name|bool
name|hasNonTrivialDefaultConstructor
argument_list|()
specifier|const
block|{
return|return
operator|(
name|data
argument_list|()
operator|.
name|DeclaredNonTrivialSpecialMembers
operator|&
name|SMF_DefaultConstructor
operator|)
operator|||
operator|(
name|needsImplicitDefaultConstructor
argument_list|()
operator|&&
operator|!
operator|(
name|data
argument_list|()
operator|.
name|HasTrivialSpecialMembers
operator|&
name|SMF_DefaultConstructor
operator|)
operator|)
return|;
block|}
end_expr_stmt

begin_comment
comment|/// \brief Determine whether this class has at least one constexpr constructor
end_comment

begin_comment
comment|/// other than the copy or move constructors.
end_comment

begin_expr_stmt
name|bool
name|hasConstexprNonCopyMoveConstructor
argument_list|()
specifier|const
block|{
return|return
name|data
argument_list|()
operator|.
name|HasConstexprNonCopyMoveConstructor
operator|||
operator|(
name|needsImplicitDefaultConstructor
argument_list|()
operator|&&
name|defaultedDefaultConstructorIsConstexpr
argument_list|()
operator|)
return|;
block|}
end_expr_stmt

begin_comment
comment|/// \brief Determine whether a defaulted default constructor for this class
end_comment

begin_comment
comment|/// would be constexpr.
end_comment

begin_expr_stmt
name|bool
name|defaultedDefaultConstructorIsConstexpr
argument_list|()
specifier|const
block|{
return|return
name|data
argument_list|()
operator|.
name|DefaultedDefaultConstructorIsConstexpr
operator|&&
operator|(
operator|!
name|isUnion
argument_list|()
operator|||
name|hasInClassInitializer
argument_list|()
operator|)
return|;
block|}
end_expr_stmt

begin_comment
comment|/// \brief Determine whether this class has a constexpr default constructor.
end_comment

begin_expr_stmt
name|bool
name|hasConstexprDefaultConstructor
argument_list|()
specifier|const
block|{
return|return
name|data
argument_list|()
operator|.
name|HasConstexprDefaultConstructor
operator|||
operator|(
name|needsImplicitDefaultConstructor
argument_list|()
operator|&&
name|defaultedDefaultConstructorIsConstexpr
argument_list|()
operator|)
return|;
block|}
end_expr_stmt

begin_comment
comment|/// \brief Determine whether this class has a trivial copy constructor
end_comment

begin_comment
comment|/// (C++ [class.copy]p6, C++11 [class.copy]p12)
end_comment

begin_expr_stmt
name|bool
name|hasTrivialCopyConstructor
argument_list|()
specifier|const
block|{
return|return
name|data
argument_list|()
operator|.
name|HasTrivialSpecialMembers
operator|&
name|SMF_CopyConstructor
return|;
block|}
end_expr_stmt

begin_comment
comment|/// \brief Determine whether this class has a non-trivial copy constructor
end_comment

begin_comment
comment|/// (C++ [class.copy]p6, C++11 [class.copy]p12)
end_comment

begin_expr_stmt
name|bool
name|hasNonTrivialCopyConstructor
argument_list|()
specifier|const
block|{
return|return
name|data
argument_list|()
operator|.
name|DeclaredNonTrivialSpecialMembers
operator|&
name|SMF_CopyConstructor
operator|||
operator|!
name|hasTrivialCopyConstructor
argument_list|()
return|;
block|}
end_expr_stmt

begin_comment
comment|/// \brief Determine whether this class has a trivial move constructor
end_comment

begin_comment
comment|/// (C++11 [class.copy]p12)
end_comment

begin_expr_stmt
name|bool
name|hasTrivialMoveConstructor
argument_list|()
specifier|const
block|{
return|return
name|hasMoveConstructor
argument_list|()
operator|&&
operator|(
name|data
argument_list|()
operator|.
name|HasTrivialSpecialMembers
operator|&
name|SMF_MoveConstructor
operator|)
return|;
block|}
end_expr_stmt

begin_comment
comment|/// \brief Determine whether this class has a non-trivial move constructor
end_comment

begin_comment
comment|/// (C++11 [class.copy]p12)
end_comment

begin_expr_stmt
name|bool
name|hasNonTrivialMoveConstructor
argument_list|()
specifier|const
block|{
return|return
operator|(
name|data
argument_list|()
operator|.
name|DeclaredNonTrivialSpecialMembers
operator|&
name|SMF_MoveConstructor
operator|)
operator|||
operator|(
name|needsImplicitMoveConstructor
argument_list|()
operator|&&
operator|!
operator|(
name|data
argument_list|()
operator|.
name|HasTrivialSpecialMembers
operator|&
name|SMF_MoveConstructor
operator|)
operator|)
return|;
block|}
end_expr_stmt

begin_comment
comment|/// \brief Determine whether this class has a trivial copy assignment operator
end_comment

begin_comment
comment|/// (C++ [class.copy]p11, C++11 [class.copy]p25)
end_comment

begin_expr_stmt
name|bool
name|hasTrivialCopyAssignment
argument_list|()
specifier|const
block|{
return|return
name|data
argument_list|()
operator|.
name|HasTrivialSpecialMembers
operator|&
name|SMF_CopyAssignment
return|;
block|}
end_expr_stmt

begin_comment
comment|/// \brief Determine whether this class has a non-trivial copy assignment
end_comment

begin_comment
comment|/// operator (C++ [class.copy]p11, C++11 [class.copy]p25)
end_comment

begin_expr_stmt
name|bool
name|hasNonTrivialCopyAssignment
argument_list|()
specifier|const
block|{
return|return
name|data
argument_list|()
operator|.
name|DeclaredNonTrivialSpecialMembers
operator|&
name|SMF_CopyAssignment
operator|||
operator|!
name|hasTrivialCopyAssignment
argument_list|()
return|;
block|}
end_expr_stmt

begin_comment
comment|/// \brief Determine whether this class has a trivial move assignment operator
end_comment

begin_comment
comment|/// (C++11 [class.copy]p25)
end_comment

begin_expr_stmt
name|bool
name|hasTrivialMoveAssignment
argument_list|()
specifier|const
block|{
return|return
name|hasMoveAssignment
argument_list|()
operator|&&
operator|(
name|data
argument_list|()
operator|.
name|HasTrivialSpecialMembers
operator|&
name|SMF_MoveAssignment
operator|)
return|;
block|}
end_expr_stmt

begin_comment
comment|/// \brief Determine whether this class has a non-trivial move assignment
end_comment

begin_comment
comment|/// operator (C++11 [class.copy]p25)
end_comment

begin_expr_stmt
name|bool
name|hasNonTrivialMoveAssignment
argument_list|()
specifier|const
block|{
return|return
operator|(
name|data
argument_list|()
operator|.
name|DeclaredNonTrivialSpecialMembers
operator|&
name|SMF_MoveAssignment
operator|)
operator|||
operator|(
name|needsImplicitMoveAssignment
argument_list|()
operator|&&
operator|!
operator|(
name|data
argument_list|()
operator|.
name|HasTrivialSpecialMembers
operator|&
name|SMF_MoveAssignment
operator|)
operator|)
return|;
block|}
end_expr_stmt

begin_comment
comment|/// \brief Determine whether this class has a trivial destructor
end_comment

begin_comment
comment|/// (C++ [class.dtor]p3)
end_comment

begin_expr_stmt
name|bool
name|hasTrivialDestructor
argument_list|()
specifier|const
block|{
return|return
name|data
argument_list|()
operator|.
name|HasTrivialSpecialMembers
operator|&
name|SMF_Destructor
return|;
block|}
end_expr_stmt

begin_comment
comment|/// \brief Determine whether this class has a non-trivial destructor
end_comment

begin_comment
comment|/// (C++ [class.dtor]p3)
end_comment

begin_expr_stmt
name|bool
name|hasNonTrivialDestructor
argument_list|()
specifier|const
block|{
return|return
operator|!
operator|(
name|data
argument_list|()
operator|.
name|HasTrivialSpecialMembers
operator|&
name|SMF_Destructor
operator|)
return|;
block|}
end_expr_stmt

begin_comment
comment|/// \brief Determine whether this class has a destructor which has no
end_comment

begin_comment
comment|/// semantic effect.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Any such destructor will be trivial, public, defaulted and not deleted,
end_comment

begin_comment
comment|/// and will call only irrelevant destructors.
end_comment

begin_expr_stmt
name|bool
name|hasIrrelevantDestructor
argument_list|()
specifier|const
block|{
return|return
name|data
argument_list|()
operator|.
name|HasIrrelevantDestructor
return|;
block|}
end_expr_stmt

begin_comment
comment|/// \brief Determine whether this class has a non-literal or/ volatile type
end_comment

begin_comment
comment|/// non-static data member or base class.
end_comment

begin_expr_stmt
name|bool
name|hasNonLiteralTypeFieldsOrBases
argument_list|()
specifier|const
block|{
return|return
name|data
argument_list|()
operator|.
name|HasNonLiteralTypeFieldsOrBases
return|;
block|}
end_expr_stmt

begin_comment
comment|/// \brief Determine whether this class is considered trivially copyable per
end_comment

begin_comment
comment|/// (C++11 [class]p6).
end_comment

begin_expr_stmt
name|bool
name|isTriviallyCopyable
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// \brief Determine whether this class is considered trivial.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// C++11 [class]p6:
end_comment

begin_comment
comment|///    "A trivial class is a class that has a trivial default constructor and
end_comment

begin_comment
comment|///    is trivially copiable."
end_comment

begin_expr_stmt
name|bool
name|isTrivial
argument_list|()
specifier|const
block|{
return|return
name|isTriviallyCopyable
argument_list|()
operator|&&
name|hasTrivialDefaultConstructor
argument_list|()
return|;
block|}
end_expr_stmt

begin_comment
comment|/// \brief Determine whether this class is a literal type.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// C++11 [basic.types]p10:
end_comment

begin_comment
comment|///   A class type that has all the following properties:
end_comment

begin_comment
comment|///     - it has a trivial destructor
end_comment

begin_comment
comment|///     - every constructor call and full-expression in the
end_comment

begin_comment
comment|///       brace-or-equal-intializers for non-static data members (if any) is
end_comment

begin_comment
comment|///       a constant expression.
end_comment

begin_comment
comment|///     - it is an aggregate type or has at least one constexpr constructor
end_comment

begin_comment
comment|///       or constructor template that is not a copy or move constructor, and
end_comment

begin_comment
comment|///     - all of its non-static data members and base classes are of literal
end_comment

begin_comment
comment|///       types
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// We resolve DR1361 by ignoring the second bullet. We resolve DR1452 by
end_comment

begin_comment
comment|/// treating types with trivial default constructors as literal types.
end_comment

begin_expr_stmt
name|bool
name|isLiteral
argument_list|()
specifier|const
block|{
return|return
name|hasTrivialDestructor
argument_list|()
operator|&&
operator|(
name|isAggregate
argument_list|()
operator|||
name|hasConstexprNonCopyMoveConstructor
argument_list|()
operator|||
name|hasTrivialDefaultConstructor
argument_list|()
operator|)
operator|&&
operator|!
name|hasNonLiteralTypeFieldsOrBases
argument_list|()
return|;
block|}
end_expr_stmt

begin_comment
comment|/// \brief If this record is an instantiation of a member class,
end_comment

begin_comment
comment|/// retrieves the member class from which it was instantiated.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This routine will return non-null for (non-templated) member
end_comment

begin_comment
comment|/// classes of class templates. For example, given:
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \code
end_comment

begin_comment
comment|/// template<typename T>
end_comment

begin_comment
comment|/// struct X {
end_comment

begin_comment
comment|///   struct A { };
end_comment

begin_comment
comment|/// };
end_comment

begin_comment
comment|/// \endcode
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// The declaration for X<int>::A is a (non-templated) CXXRecordDecl
end_comment

begin_comment
comment|/// whose parent is the class template specialization X<int>. For
end_comment

begin_comment
comment|/// this declaration, getInstantiatedFromMemberClass() will return
end_comment

begin_comment
comment|/// the CXXRecordDecl X<T>::A. When a complete definition of
end_comment

begin_comment
comment|/// X<int>::A is required, it will be instantiated from the
end_comment

begin_comment
comment|/// declaration returned by getInstantiatedFromMemberClass().
end_comment

begin_expr_stmt
name|CXXRecordDecl
operator|*
name|getInstantiatedFromMemberClass
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// \brief If this class is an instantiation of a member class of a
end_comment

begin_comment
comment|/// class template specialization, retrieves the member specialization
end_comment

begin_comment
comment|/// information.
end_comment

begin_expr_stmt
name|MemberSpecializationInfo
operator|*
name|getMemberSpecializationInfo
argument_list|()
specifier|const
block|{
return|return
name|TemplateOrInstantiation
operator|.
name|dyn_cast
operator|<
name|MemberSpecializationInfo
operator|*
operator|>
operator|(
operator|)
return|;
block|}
end_expr_stmt

begin_comment
comment|/// \brief Specify that this record is an instantiation of the
end_comment

begin_comment
comment|/// member class \p RD.
end_comment

begin_function_decl
name|void
name|setInstantiationOfMemberClass
parameter_list|(
name|CXXRecordDecl
modifier|*
name|RD
parameter_list|,
name|TemplateSpecializationKind
name|TSK
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// \brief Retrieves the class template that is described by this
end_comment

begin_comment
comment|/// class declaration.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Every class template is represented as a ClassTemplateDecl and a
end_comment

begin_comment
comment|/// CXXRecordDecl. The former contains template properties (such as
end_comment

begin_comment
comment|/// the template parameter lists) while the latter contains the
end_comment

begin_comment
comment|/// actual description of the template's
end_comment

begin_comment
comment|/// contents. ClassTemplateDecl::getTemplatedDecl() retrieves the
end_comment

begin_comment
comment|/// CXXRecordDecl that from a ClassTemplateDecl, while
end_comment

begin_comment
comment|/// getDescribedClassTemplate() retrieves the ClassTemplateDecl from
end_comment

begin_comment
comment|/// a CXXRecordDecl.
end_comment

begin_expr_stmt
name|ClassTemplateDecl
operator|*
name|getDescribedClassTemplate
argument_list|()
specifier|const
block|{
return|return
name|TemplateOrInstantiation
operator|.
name|dyn_cast
operator|<
name|ClassTemplateDecl
operator|*
operator|>
operator|(
operator|)
return|;
block|}
end_expr_stmt

begin_function
name|void
name|setDescribedClassTemplate
parameter_list|(
name|ClassTemplateDecl
modifier|*
name|Template
parameter_list|)
block|{
name|TemplateOrInstantiation
operator|=
name|Template
expr_stmt|;
block|}
end_function

begin_comment
comment|/// \brief Determine whether this particular class is a specialization or
end_comment

begin_comment
comment|/// instantiation of a class template or member class of a class template,
end_comment

begin_comment
comment|/// and how it was instantiated or specialized.
end_comment

begin_expr_stmt
name|TemplateSpecializationKind
name|getTemplateSpecializationKind
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// \brief Set the kind of specialization or template instantiation this is.
end_comment

begin_function_decl
name|void
name|setTemplateSpecializationKind
parameter_list|(
name|TemplateSpecializationKind
name|TSK
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// \brief Returns the destructor decl for this class.
end_comment

begin_expr_stmt
name|CXXDestructorDecl
operator|*
name|getDestructor
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// \brief If the class is a local class [class.local], returns
end_comment

begin_comment
comment|/// the enclosing function declaration.
end_comment

begin_expr_stmt
specifier|const
name|FunctionDecl
operator|*
name|isLocalClass
argument_list|()
specifier|const
block|{
if|if
condition|(
specifier|const
name|CXXRecordDecl
modifier|*
name|RD
init|=
name|dyn_cast
operator|<
name|CXXRecordDecl
operator|>
operator|(
name|getDeclContext
argument_list|()
operator|)
condition|)
return|return
name|RD
operator|->
name|isLocalClass
argument_list|()
return|;
end_expr_stmt

begin_return
return|return
name|dyn_cast
operator|<
name|FunctionDecl
operator|>
operator|(
name|getDeclContext
argument_list|()
operator|)
return|;
end_return

begin_expr_stmt
unit|}    FunctionDecl
operator|*
name|isLocalClass
argument_list|()
block|{
return|return
name|const_cast
operator|<
name|FunctionDecl
operator|*
operator|>
operator|(
name|const_cast
operator|<
specifier|const
name|CXXRecordDecl
operator|*
operator|>
operator|(
name|this
operator|)
operator|->
name|isLocalClass
argument_list|()
operator|)
return|;
block|}
end_expr_stmt

begin_comment
comment|/// \brief Determine whether this dependent class is a current instantiation,
end_comment

begin_comment
comment|/// when viewed from within the given context.
end_comment

begin_decl_stmt
name|bool
name|isCurrentInstantiation
argument_list|(
specifier|const
name|DeclContext
operator|*
name|CurContext
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// \brief Determine whether this class is derived from the class \p Base.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This routine only determines whether this class is derived from \p Base,
end_comment

begin_comment
comment|/// but does not account for factors that may make a Derived -> Base class
end_comment

begin_comment
comment|/// ill-formed, such as private/protected inheritance or multiple, ambiguous
end_comment

begin_comment
comment|/// base class subobjects.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param Base the base class we are searching for.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \returns true if this class is derived from Base, false otherwise.
end_comment

begin_decl_stmt
name|bool
name|isDerivedFrom
argument_list|(
specifier|const
name|CXXRecordDecl
operator|*
name|Base
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// \brief Determine whether this class is derived from the type \p Base.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This routine only determines whether this class is derived from \p Base,
end_comment

begin_comment
comment|/// but does not account for factors that may make a Derived -> Base class
end_comment

begin_comment
comment|/// ill-formed, such as private/protected inheritance or multiple, ambiguous
end_comment

begin_comment
comment|/// base class subobjects.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param Base the base class we are searching for.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param Paths will contain the paths taken from the current class to the
end_comment

begin_comment
comment|/// given \p Base class.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \returns true if this class is derived from \p Base, false otherwise.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \todo add a separate paramaeter to configure IsDerivedFrom, rather than
end_comment

begin_comment
comment|/// tangling input and output in \p Paths
end_comment

begin_decl_stmt
name|bool
name|isDerivedFrom
argument_list|(
specifier|const
name|CXXRecordDecl
operator|*
name|Base
argument_list|,
name|CXXBasePaths
operator|&
name|Paths
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// \brief Determine whether this class is virtually derived from
end_comment

begin_comment
comment|/// the class \p Base.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This routine only determines whether this class is virtually
end_comment

begin_comment
comment|/// derived from \p Base, but does not account for factors that may
end_comment

begin_comment
comment|/// make a Derived -> Base class ill-formed, such as
end_comment

begin_comment
comment|/// private/protected inheritance or multiple, ambiguous base class
end_comment

begin_comment
comment|/// subobjects.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param Base the base class we are searching for.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \returns true if this class is virtually derived from Base,
end_comment

begin_comment
comment|/// false otherwise.
end_comment

begin_decl_stmt
name|bool
name|isVirtuallyDerivedFrom
argument_list|(
specifier|const
name|CXXRecordDecl
operator|*
name|Base
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// \brief Determine whether this class is provably not derived from
end_comment

begin_comment
comment|/// the type \p Base.
end_comment

begin_decl_stmt
name|bool
name|isProvablyNotDerivedFrom
argument_list|(
specifier|const
name|CXXRecordDecl
operator|*
name|Base
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// \brief Function type used by forallBases() as a callback.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param BaseDefinition the definition of the base class
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \returns true if this base matched the search criteria
end_comment

begin_typedef
typedef|typedef
name|bool
name|ForallBasesCallback
parameter_list|(
specifier|const
name|CXXRecordDecl
modifier|*
name|BaseDefinition
parameter_list|,
name|void
modifier|*
name|UserData
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/// \brief Determines if the given callback holds for all the direct
end_comment

begin_comment
comment|/// or indirect base classes of this type.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// The class itself does not count as a base class.  This routine
end_comment

begin_comment
comment|/// returns false if the class has non-computable base classes.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param BaseMatches Callback invoked for each (direct or indirect) base
end_comment

begin_comment
comment|/// class of this type, or if \p AllowShortCircuit is true then until a call
end_comment

begin_comment
comment|/// returns false.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param UserData Passed as the second argument of every call to
end_comment

begin_comment
comment|/// \p BaseMatches.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param AllowShortCircuit if false, forces the callback to be called
end_comment

begin_comment
comment|/// for every base class, even if a dependent or non-matching base was
end_comment

begin_comment
comment|/// found.
end_comment

begin_decl_stmt
name|bool
name|forallBases
argument_list|(
name|ForallBasesCallback
operator|*
name|BaseMatches
argument_list|,
name|void
operator|*
name|UserData
argument_list|,
name|bool
name|AllowShortCircuit
operator|=
name|true
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// \brief Function type used by lookupInBases() to determine whether a
end_comment

begin_comment
comment|/// specific base class subobject matches the lookup criteria.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param Specifier the base-class specifier that describes the inheritance
end_comment

begin_comment
comment|/// from the base class we are trying to match.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param Path the current path, from the most-derived class down to the
end_comment

begin_comment
comment|/// base named by the \p Specifier.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param UserData a single pointer to user-specified data, provided to
end_comment

begin_comment
comment|/// lookupInBases().
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \returns true if this base matched the search criteria, false otherwise.
end_comment

begin_typedef
typedef|typedef
name|bool
name|BaseMatchesCallback
parameter_list|(
specifier|const
name|CXXBaseSpecifier
modifier|*
name|Specifier
parameter_list|,
name|CXXBasePath
modifier|&
name|Path
parameter_list|,
name|void
modifier|*
name|UserData
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/// \brief Look for entities within the base classes of this C++ class,
end_comment

begin_comment
comment|/// transitively searching all base class subobjects.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This routine uses the callback function \p BaseMatches to find base
end_comment

begin_comment
comment|/// classes meeting some search criteria, walking all base class subobjects
end_comment

begin_comment
comment|/// and populating the given \p Paths structure with the paths through the
end_comment

begin_comment
comment|/// inheritance hierarchy that resulted in a match. On a successful search,
end_comment

begin_comment
comment|/// the \p Paths structure can be queried to retrieve the matching paths and
end_comment

begin_comment
comment|/// to determine if there were any ambiguities.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param BaseMatches callback function used to determine whether a given
end_comment

begin_comment
comment|/// base matches the user-defined search criteria.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param UserData user data pointer that will be provided to \p BaseMatches.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param Paths used to record the paths from this class to its base class
end_comment

begin_comment
comment|/// subobjects that match the search criteria.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \returns true if there exists any path from this class to a base class
end_comment

begin_comment
comment|/// subobject that matches the search criteria.
end_comment

begin_decl_stmt
name|bool
name|lookupInBases
argument_list|(
name|BaseMatchesCallback
operator|*
name|BaseMatches
argument_list|,
name|void
operator|*
name|UserData
argument_list|,
name|CXXBasePaths
operator|&
name|Paths
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// \brief Base-class lookup callback that determines whether the given
end_comment

begin_comment
comment|/// base class specifier refers to a specific class declaration.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This callback can be used with \c lookupInBases() to determine whether
end_comment

begin_comment
comment|/// a given derived class has is a base class subobject of a particular type.
end_comment

begin_comment
comment|/// The user data pointer should refer to the canonical CXXRecordDecl of the
end_comment

begin_comment
comment|/// base class that we are searching for.
end_comment

begin_function_decl
specifier|static
name|bool
name|FindBaseClass
parameter_list|(
specifier|const
name|CXXBaseSpecifier
modifier|*
name|Specifier
parameter_list|,
name|CXXBasePath
modifier|&
name|Path
parameter_list|,
name|void
modifier|*
name|BaseRecord
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// \brief Base-class lookup callback that determines whether the
end_comment

begin_comment
comment|/// given base class specifier refers to a specific class
end_comment

begin_comment
comment|/// declaration and describes virtual derivation.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This callback can be used with \c lookupInBases() to determine
end_comment

begin_comment
comment|/// whether a given derived class has is a virtual base class
end_comment

begin_comment
comment|/// subobject of a particular type.  The user data pointer should
end_comment

begin_comment
comment|/// refer to the canonical CXXRecordDecl of the base class that we
end_comment

begin_comment
comment|/// are searching for.
end_comment

begin_function_decl
specifier|static
name|bool
name|FindVirtualBaseClass
parameter_list|(
specifier|const
name|CXXBaseSpecifier
modifier|*
name|Specifier
parameter_list|,
name|CXXBasePath
modifier|&
name|Path
parameter_list|,
name|void
modifier|*
name|BaseRecord
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// \brief Base-class lookup callback that determines whether there exists
end_comment

begin_comment
comment|/// a tag with the given name.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This callback can be used with \c lookupInBases() to find tag members
end_comment

begin_comment
comment|/// of the given name within a C++ class hierarchy. The user data pointer
end_comment

begin_comment
comment|/// is an opaque \c DeclarationName pointer.
end_comment

begin_function_decl
specifier|static
name|bool
name|FindTagMember
parameter_list|(
specifier|const
name|CXXBaseSpecifier
modifier|*
name|Specifier
parameter_list|,
name|CXXBasePath
modifier|&
name|Path
parameter_list|,
name|void
modifier|*
name|Name
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// \brief Base-class lookup callback that determines whether there exists
end_comment

begin_comment
comment|/// a member with the given name.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This callback can be used with \c lookupInBases() to find members
end_comment

begin_comment
comment|/// of the given name within a C++ class hierarchy. The user data pointer
end_comment

begin_comment
comment|/// is an opaque \c DeclarationName pointer.
end_comment

begin_function_decl
specifier|static
name|bool
name|FindOrdinaryMember
parameter_list|(
specifier|const
name|CXXBaseSpecifier
modifier|*
name|Specifier
parameter_list|,
name|CXXBasePath
modifier|&
name|Path
parameter_list|,
name|void
modifier|*
name|Name
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// \brief Base-class lookup callback that determines whether there exists
end_comment

begin_comment
comment|/// a member with the given name that can be used in a nested-name-specifier.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This callback can be used with \c lookupInBases() to find membes of
end_comment

begin_comment
comment|/// the given name within a C++ class hierarchy that can occur within
end_comment

begin_comment
comment|/// nested-name-specifiers.
end_comment

begin_function_decl
specifier|static
name|bool
name|FindNestedNameSpecifierMember
parameter_list|(
specifier|const
name|CXXBaseSpecifier
modifier|*
name|Specifier
parameter_list|,
name|CXXBasePath
modifier|&
name|Path
parameter_list|,
name|void
modifier|*
name|UserData
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// \brief Retrieve the final overriders for each virtual member
end_comment

begin_comment
comment|/// function in the class hierarchy where this class is the
end_comment

begin_comment
comment|/// most-derived class in the class hierarchy.
end_comment

begin_decl_stmt
name|void
name|getFinalOverriders
argument_list|(
name|CXXFinalOverriderMap
operator|&
name|FinaOverriders
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// \brief Get the indirect primary bases for this class.
end_comment

begin_decl_stmt
name|void
name|getIndirectPrimaryBases
argument_list|(
name|CXXIndirectPrimaryBaseSet
operator|&
name|Bases
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// Renders and displays an inheritance diagram
end_comment

begin_comment
comment|/// for this C++ class and all of its base classes (transitively) using
end_comment

begin_comment
comment|/// GraphViz.
end_comment

begin_decl_stmt
name|void
name|viewInheritance
argument_list|(
name|ASTContext
operator|&
name|Context
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// \brief Calculates the access of a decl that is reached
end_comment

begin_comment
comment|/// along a path.
end_comment

begin_function
specifier|static
name|AccessSpecifier
name|MergeAccess
parameter_list|(
name|AccessSpecifier
name|PathAccess
parameter_list|,
name|AccessSpecifier
name|DeclAccess
parameter_list|)
block|{
name|assert
argument_list|(
name|DeclAccess
operator|!=
name|AS_none
argument_list|)
expr_stmt|;
if|if
condition|(
name|DeclAccess
operator|==
name|AS_private
condition|)
return|return
name|AS_none
return|;
return|return
operator|(
name|PathAccess
operator|>
name|DeclAccess
condition|?
name|PathAccess
else|:
name|DeclAccess
operator|)
return|;
block|}
end_function

begin_comment
comment|/// \brief Indicates that the declaration of a defaulted or deleted special
end_comment

begin_comment
comment|/// member function is now complete.
end_comment

begin_function_decl
name|void
name|finishedDefaultedOrDeletedMember
parameter_list|(
name|CXXMethodDecl
modifier|*
name|MD
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// \brief Indicates that the definition of this class is now complete.
end_comment

begin_function_decl
name|virtual
name|void
name|completeDefinition
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/// \brief Indicates that the definition of this class is now complete,
end_comment

begin_comment
comment|/// and provides a final overrider map to help determine
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param FinalOverriders The final overrider map for this class, which can
end_comment

begin_comment
comment|/// be provided as an optimization for abstract-class checking. If NULL,
end_comment

begin_comment
comment|/// final overriders will be computed if they are needed to complete the
end_comment

begin_comment
comment|/// definition.
end_comment

begin_function_decl
name|void
name|completeDefinition
parameter_list|(
name|CXXFinalOverriderMap
modifier|*
name|FinalOverriders
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// \brief Determine whether this class may end up being abstract, even though
end_comment

begin_comment
comment|/// it is not yet known to be abstract.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \returns true if this class is not known to be abstract but has any
end_comment

begin_comment
comment|/// base classes that are abstract. In this case, \c completeDefinition()
end_comment

begin_comment
comment|/// will need to compute final overriders to determine whether the class is
end_comment

begin_comment
comment|/// actually abstract.
end_comment

begin_expr_stmt
name|bool
name|mayBeAbstract
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// \brief If this is the closure type of a lambda expression, retrieve the
end_comment

begin_comment
comment|/// number to be used for name mangling in the Itanium C++ ABI.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Zero indicates that this closure type has internal linkage, so the
end_comment

begin_comment
comment|/// mangling number does not matter, while a non-zero value indicates which
end_comment

begin_comment
comment|/// lambda expression this is in this particular context.
end_comment

begin_expr_stmt
name|unsigned
name|getLambdaManglingNumber
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
name|isLambda
argument_list|()
operator|&&
literal|"Not a lambda closure type!"
argument_list|)
block|;
return|return
name|getLambdaData
argument_list|()
operator|.
name|ManglingNumber
return|;
block|}
end_expr_stmt

begin_comment
comment|/// \brief Retrieve the declaration that provides additional context for a
end_comment

begin_comment
comment|/// lambda, when the normal declaration context is not specific enough.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Certain contexts (default arguments of in-class function parameters and
end_comment

begin_comment
comment|/// the initializers of data members) have separate name mangling rules for
end_comment

begin_comment
comment|/// lambdas within the Itanium C++ ABI. For these cases, this routine provides
end_comment

begin_comment
comment|/// the declaration in which the lambda occurs, e.g., the function parameter
end_comment

begin_comment
comment|/// or the non-static data member. Otherwise, it returns NULL to imply that
end_comment

begin_comment
comment|/// the declaration context suffices.
end_comment

begin_expr_stmt
name|Decl
operator|*
name|getLambdaContextDecl
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
name|isLambda
argument_list|()
operator|&&
literal|"Not a lambda closure type!"
argument_list|)
block|;
return|return
name|getLambdaData
argument_list|()
operator|.
name|ContextDecl
return|;
block|}
end_expr_stmt

begin_comment
comment|/// \brief Set the mangling number and context declaration for a lambda
end_comment

begin_comment
comment|/// class.
end_comment

begin_function
name|void
name|setLambdaMangling
parameter_list|(
name|unsigned
name|ManglingNumber
parameter_list|,
name|Decl
modifier|*
name|ContextDecl
parameter_list|)
block|{
name|getLambdaData
argument_list|()
operator|.
name|ManglingNumber
operator|=
name|ManglingNumber
expr_stmt|;
name|getLambdaData
argument_list|()
operator|.
name|ContextDecl
operator|=
name|ContextDecl
expr_stmt|;
block|}
end_function

begin_comment
comment|/// \brief Returns the inheritance model used for this record.
end_comment

begin_expr_stmt
name|MSInheritanceModel
name|getMSInheritanceModel
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// \brief Determine whether this lambda expression was known to be dependent
end_comment

begin_comment
comment|/// at the time it was created, even if its context does not appear to be
end_comment

begin_comment
comment|/// dependent.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This flag is a workaround for an issue with parsing, where default
end_comment

begin_comment
comment|/// arguments are parsed before their enclosing function declarations have
end_comment

begin_comment
comment|/// been created. This means that any lambda expressions within those
end_comment

begin_comment
comment|/// default arguments will have as their DeclContext the context enclosing
end_comment

begin_comment
comment|/// the function declaration, which may be non-dependent even when the
end_comment

begin_comment
comment|/// function declaration itself is dependent. This flag indicates when we
end_comment

begin_comment
comment|/// know that the lambda is dependent despite that.
end_comment

begin_expr_stmt
name|bool
name|isDependentLambda
argument_list|()
specifier|const
block|{
return|return
name|isLambda
argument_list|()
operator|&&
name|getLambdaData
argument_list|()
operator|.
name|Dependent
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|TypeSourceInfo
operator|*
name|getLambdaTypeInfo
argument_list|()
specifier|const
block|{
return|return
name|getLambdaData
argument_list|()
operator|.
name|MethodTyInfo
return|;
block|}
end_expr_stmt

begin_function
specifier|static
name|bool
name|classof
parameter_list|(
specifier|const
name|Decl
modifier|*
name|D
parameter_list|)
block|{
return|return
name|classofKind
argument_list|(
name|D
operator|->
name|getKind
argument_list|()
argument_list|)
return|;
block|}
end_function

begin_function
specifier|static
name|bool
name|classofKind
parameter_list|(
name|Kind
name|K
parameter_list|)
block|{
return|return
name|K
operator|>=
name|firstCXXRecord
operator|&&
name|K
operator|<=
name|lastCXXRecord
return|;
block|}
end_function

begin_decl_stmt
name|friend
name|class
name|ASTDeclReader
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|friend
name|class
name|ASTDeclWriter
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|friend
name|class
name|ASTReader
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|friend
name|class
name|ASTWriter
decl_stmt|;
end_decl_stmt

begin_comment
unit|};
comment|/// \brief Represents a static or instance method of a struct/union/class.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// In the terminology of the C++ Standard, these are the (static and
end_comment

begin_comment
comment|/// non-static) member functions, whether virtual or not.
end_comment

begin_decl_stmt
name|class
name|CXXMethodDecl
range|:
name|public
name|FunctionDecl
block|{
name|virtual
name|void
name|anchor
argument_list|()
block|;
name|protected
operator|:
name|CXXMethodDecl
argument_list|(
argument|Kind DK
argument_list|,
argument|CXXRecordDecl *RD
argument_list|,
argument|SourceLocation StartLoc
argument_list|,
argument|const DeclarationNameInfo&NameInfo
argument_list|,
argument|QualType T
argument_list|,
argument|TypeSourceInfo *TInfo
argument_list|,
argument|StorageClass SC
argument_list|,
argument|bool isInline
argument_list|,
argument|bool isConstexpr
argument_list|,
argument|SourceLocation EndLocation
argument_list|)
operator|:
name|FunctionDecl
argument_list|(
argument|DK
argument_list|,
argument|RD
argument_list|,
argument|StartLoc
argument_list|,
argument|NameInfo
argument_list|,
argument|T
argument_list|,
argument|TInfo
argument_list|,
argument|SC
argument_list|,
argument|isInline
argument_list|,
argument|isConstexpr
argument_list|)
block|{
if|if
condition|(
name|EndLocation
operator|.
name|isValid
argument_list|()
condition|)
name|setRangeEnd
argument_list|(
name|EndLocation
argument_list|)
expr_stmt|;
block|}
name|public
operator|:
specifier|static
name|CXXMethodDecl
operator|*
name|Create
argument_list|(
argument|ASTContext&C
argument_list|,
argument|CXXRecordDecl *RD
argument_list|,
argument|SourceLocation StartLoc
argument_list|,
argument|const DeclarationNameInfo&NameInfo
argument_list|,
argument|QualType T
argument_list|,
argument|TypeSourceInfo *TInfo
argument_list|,
argument|StorageClass SC
argument_list|,
argument|bool isInline
argument_list|,
argument|bool isConstexpr
argument_list|,
argument|SourceLocation EndLocation
argument_list|)
block|;
specifier|static
name|CXXMethodDecl
operator|*
name|CreateDeserialized
argument_list|(
argument|ASTContext&C
argument_list|,
argument|unsigned ID
argument_list|)
block|;
name|bool
name|isStatic
argument_list|()
specifier|const
block|;
name|bool
name|isInstance
argument_list|()
specifier|const
block|{
return|return
operator|!
name|isStatic
argument_list|()
return|;
block|}
comment|/// Returns true if the given operator is implicitly static in a record
comment|/// context.
specifier|static
name|bool
name|isStaticOverloadedOperator
argument_list|(
argument|OverloadedOperatorKind OOK
argument_list|)
block|{
comment|// [class.free]p1:
comment|// Any allocation function for a class T is a static member
comment|// (even if not explicitly declared static).
comment|// [class.free]p6 Any deallocation function for a class X is a static member
comment|// (even if not explicitly declared static).
return|return
name|OOK
operator|==
name|OO_New
operator|||
name|OOK
operator|==
name|OO_Array_New
operator|||
name|OOK
operator|==
name|OO_Delete
operator|||
name|OOK
operator|==
name|OO_Array_Delete
return|;
block|}
name|bool
name|isConst
argument_list|()
specifier|const
block|{
return|return
name|getType
argument_list|()
operator|->
name|castAs
operator|<
name|FunctionType
operator|>
operator|(
operator|)
operator|->
name|isConst
argument_list|()
return|;
block|}
name|bool
name|isVolatile
argument_list|()
specifier|const
block|{
return|return
name|getType
argument_list|()
operator|->
name|castAs
operator|<
name|FunctionType
operator|>
operator|(
operator|)
operator|->
name|isVolatile
argument_list|()
return|;
block|}
name|bool
name|isVirtual
argument_list|()
specifier|const
block|{
name|CXXMethodDecl
operator|*
name|CD
operator|=
name|cast
operator|<
name|CXXMethodDecl
operator|>
operator|(
name|const_cast
operator|<
name|CXXMethodDecl
operator|*
operator|>
operator|(
name|this
operator|)
operator|->
name|getCanonicalDecl
argument_list|()
operator|)
block|;
comment|// Methods declared in interfaces are automatically (pure) virtual.
if|if
condition|(
name|CD
operator|->
name|isVirtualAsWritten
argument_list|()
operator|||
operator|(
name|CD
operator|->
name|getParent
argument_list|()
operator|->
name|isInterface
argument_list|()
operator|&&
name|CD
operator|->
name|isUserProvided
argument_list|()
operator|)
condition|)
return|return
name|true
return|;
return|return
operator|(
name|CD
operator|->
name|begin_overridden_methods
argument_list|()
operator|!=
name|CD
operator|->
name|end_overridden_methods
argument_list|()
operator|)
return|;
block|}
end_decl_stmt

begin_comment
comment|/// \brief Determine whether this is a usual deallocation function
end_comment

begin_comment
comment|/// (C++ [basic.stc.dynamic.deallocation]p2), which is an overloaded
end_comment

begin_comment
comment|/// delete or delete[] operator with a particular signature.
end_comment

begin_expr_stmt
name|bool
name|isUsualDeallocationFunction
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// \brief Determine whether this is a copy-assignment operator, regardless
end_comment

begin_comment
comment|/// of whether it was declared implicitly or explicitly.
end_comment

begin_expr_stmt
name|bool
name|isCopyAssignmentOperator
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// \brief Determine whether this is a move assignment operator.
end_comment

begin_expr_stmt
name|bool
name|isMoveAssignmentOperator
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt

begin_function
name|CXXMethodDecl
modifier|*
name|getCanonicalDecl
parameter_list|()
block|{
return|return
name|cast
operator|<
name|CXXMethodDecl
operator|>
operator|(
name|FunctionDecl
operator|::
name|getCanonicalDecl
argument_list|()
operator|)
return|;
block|}
end_function

begin_expr_stmt
specifier|const
name|CXXMethodDecl
operator|*
name|getCanonicalDecl
argument_list|()
specifier|const
block|{
return|return
name|const_cast
operator|<
name|CXXMethodDecl
operator|*
operator|>
operator|(
name|this
operator|)
operator|->
name|getCanonicalDecl
argument_list|()
return|;
block|}
end_expr_stmt

begin_function
name|CXXMethodDecl
modifier|*
name|getMostRecentDecl
parameter_list|()
block|{
return|return
name|cast
operator|<
name|CXXMethodDecl
operator|>
operator|(
name|static_cast
operator|<
name|FunctionDecl
operator|*
operator|>
operator|(
name|this
operator|)
operator|->
name|getMostRecentDecl
argument_list|()
operator|)
return|;
block|}
end_function

begin_expr_stmt
specifier|const
name|CXXMethodDecl
operator|*
name|getMostRecentDecl
argument_list|()
specifier|const
block|{
return|return
name|const_cast
operator|<
name|CXXMethodDecl
operator|*
operator|>
operator|(
name|this
operator|)
operator|->
name|getMostRecentDecl
argument_list|()
return|;
block|}
end_expr_stmt

begin_comment
comment|/// True if this method is user-declared and was not
end_comment

begin_comment
comment|/// deleted or defaulted on its first declaration.
end_comment

begin_expr_stmt
name|bool
name|isUserProvided
argument_list|()
specifier|const
block|{
return|return
operator|!
operator|(
name|isDeleted
argument_list|()
operator|||
name|getCanonicalDecl
argument_list|()
operator|->
name|isDefaulted
argument_list|()
operator|)
return|;
block|}
end_expr_stmt

begin_comment
comment|///
end_comment

begin_function_decl
name|void
name|addOverriddenMethod
parameter_list|(
specifier|const
name|CXXMethodDecl
modifier|*
name|MD
parameter_list|)
function_decl|;
end_function_decl

begin_typedef
typedef|typedef
specifier|const
name|CXXMethodDecl
modifier|*
specifier|const
modifier|*
name|method_iterator
typedef|;
end_typedef

begin_expr_stmt
name|method_iterator
name|begin_overridden_methods
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|method_iterator
name|end_overridden_methods
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|unsigned
name|size_overridden_methods
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// Returns the parent of this method declaration, which
end_comment

begin_comment
comment|/// is the class in which this method is defined.
end_comment

begin_expr_stmt
specifier|const
name|CXXRecordDecl
operator|*
name|getParent
argument_list|()
specifier|const
block|{
return|return
name|cast
operator|<
name|CXXRecordDecl
operator|>
operator|(
name|FunctionDecl
operator|::
name|getParent
argument_list|()
operator|)
return|;
block|}
end_expr_stmt

begin_comment
comment|/// Returns the parent of this method declaration, which
end_comment

begin_comment
comment|/// is the class in which this method is defined.
end_comment

begin_function
name|CXXRecordDecl
modifier|*
name|getParent
parameter_list|()
block|{
return|return
name|const_cast
operator|<
name|CXXRecordDecl
operator|*
operator|>
operator|(
name|cast
operator|<
name|CXXRecordDecl
operator|>
operator|(
name|FunctionDecl
operator|::
name|getParent
argument_list|()
operator|)
operator|)
return|;
block|}
end_function

begin_comment
comment|/// \brief Returns the type of the \c this pointer.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Should only be called for instance (i.e., non-static) methods.
end_comment

begin_decl_stmt
name|QualType
name|getThisType
argument_list|(
name|ASTContext
operator|&
name|C
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|unsigned
name|getTypeQualifiers
argument_list|()
specifier|const
block|{
return|return
name|getType
argument_list|()
operator|->
name|getAs
operator|<
name|FunctionProtoType
operator|>
operator|(
operator|)
operator|->
name|getTypeQuals
argument_list|()
return|;
block|}
end_expr_stmt

begin_comment
comment|/// \brief Retrieve the ref-qualifier associated with this method.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// In the following example, \c f() has an lvalue ref-qualifier, \c g()
end_comment

begin_comment
comment|/// has an rvalue ref-qualifier, and \c h() has no ref-qualifier.
end_comment

begin_comment
comment|/// @code
end_comment

begin_comment
comment|/// struct X {
end_comment

begin_comment
comment|///   void f()&;
end_comment

begin_comment
comment|///   void g()&&;
end_comment

begin_comment
comment|///   void h();
end_comment

begin_comment
comment|/// };
end_comment

begin_comment
comment|/// @endcode
end_comment

begin_expr_stmt
name|RefQualifierKind
name|getRefQualifier
argument_list|()
specifier|const
block|{
return|return
name|getType
argument_list|()
operator|->
name|getAs
operator|<
name|FunctionProtoType
operator|>
operator|(
operator|)
operator|->
name|getRefQualifier
argument_list|()
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|bool
name|hasInlineBody
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// \brief Determine whether this is a lambda closure type's static member
end_comment

begin_comment
comment|/// function that is used for the result of the lambda's conversion to
end_comment

begin_comment
comment|/// function pointer (for a lambda with no captures).
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// The function itself, if used, will have a placeholder body that will be
end_comment

begin_comment
comment|/// supplied by IR generation to either forward to the function call operator
end_comment

begin_comment
comment|/// or clone the function call operator.
end_comment

begin_expr_stmt
name|bool
name|isLambdaStaticInvoker
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// \brief Find the method in \p RD that corresponds to this one.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Find if \p RD or one of the classes it inherits from override this method.
end_comment

begin_comment
comment|/// If so, return it. \p RD is assumed to be a subclass of the class defining
end_comment

begin_comment
comment|/// this method (or be the class itself), unless \p MayBeBase is set to true.
end_comment

begin_function_decl
name|CXXMethodDecl
modifier|*
name|getCorrespondingMethodInClass
parameter_list|(
specifier|const
name|CXXRecordDecl
modifier|*
name|RD
parameter_list|,
name|bool
name|MayBeBase
init|=
name|false
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
specifier|const
name|CXXMethodDecl
modifier|*
name|getCorrespondingMethodInClass
argument_list|(
specifier|const
name|CXXRecordDecl
operator|*
name|RD
argument_list|,
name|bool
name|MayBeBase
operator|=
name|false
argument_list|)
decl|const
block|{
return|return
name|const_cast
operator|<
name|CXXMethodDecl
operator|*
operator|>
operator|(
name|this
operator|)
operator|->
name|getCorrespondingMethodInClass
argument_list|(
name|RD
argument_list|,
name|MayBeBase
argument_list|)
return|;
block|}
end_decl_stmt

begin_comment
comment|// Implement isa/cast/dyncast/etc.
end_comment

begin_function
specifier|static
name|bool
name|classof
parameter_list|(
specifier|const
name|Decl
modifier|*
name|D
parameter_list|)
block|{
return|return
name|classofKind
argument_list|(
name|D
operator|->
name|getKind
argument_list|()
argument_list|)
return|;
block|}
end_function

begin_function
specifier|static
name|bool
name|classofKind
parameter_list|(
name|Kind
name|K
parameter_list|)
block|{
return|return
name|K
operator|>=
name|firstCXXMethod
operator|&&
name|K
operator|<=
name|lastCXXMethod
return|;
block|}
end_function

begin_comment
unit|};
comment|/// \brief Represents a C++ base or member initializer.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This is part of a constructor initializer that
end_comment

begin_comment
comment|/// initializes one non-static member variable or one base class. For
end_comment

begin_comment
comment|/// example, in the following, both 'A(a)' and 'f(3.14159)' are member
end_comment

begin_comment
comment|/// initializers:
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \code
end_comment

begin_comment
comment|/// class A { };
end_comment

begin_comment
comment|/// class B : public A {
end_comment

begin_comment
comment|///   float f;
end_comment

begin_comment
comment|/// public:
end_comment

begin_comment
comment|///   B(A& a) : A(a), f(3.14159) { }
end_comment

begin_comment
comment|/// };
end_comment

begin_comment
comment|/// \endcode
end_comment

begin_decl_stmt
name|class
name|CXXCtorInitializer
block|{
comment|/// \brief Either the base class name/delegating constructor type (stored as
comment|/// a TypeSourceInfo*), an normal field (FieldDecl), or an anonymous field
comment|/// (IndirectFieldDecl*) being initialized.
name|llvm
operator|::
name|PointerUnion3
operator|<
name|TypeSourceInfo
operator|*
operator|,
name|FieldDecl
operator|*
operator|,
name|IndirectFieldDecl
operator|*
operator|>
name|Initializee
expr_stmt|;
comment|/// \brief The source location for the field name or, for a base initializer
comment|/// pack expansion, the location of the ellipsis.
comment|///
comment|/// In the case of a delegating
comment|/// constructor, it will still include the type's source location as the
comment|/// Initializee points to the CXXConstructorDecl (to allow loop detection).
name|SourceLocation
name|MemberOrEllipsisLocation
decl_stmt|;
comment|/// \brief The argument used to initialize the base or member, which may
comment|/// end up constructing an object (when multiple arguments are involved).
name|Stmt
modifier|*
name|Init
decl_stmt|;
comment|/// \brief Location of the left paren of the ctor-initializer.
name|SourceLocation
name|LParenLoc
decl_stmt|;
comment|/// \brief Location of the right paren of the ctor-initializer.
name|SourceLocation
name|RParenLoc
decl_stmt|;
comment|/// \brief If the initializee is a type, whether that type makes this
comment|/// a delegating initialization.
name|bool
name|IsDelegating
range|:
literal|1
decl_stmt|;
comment|/// \brief If the initializer is a base initializer, this keeps track
comment|/// of whether the base is virtual or not.
name|bool
name|IsVirtual
range|:
literal|1
decl_stmt|;
comment|/// \brief Whether or not the initializer is explicitly written
comment|/// in the sources.
name|bool
name|IsWritten
range|:
literal|1
decl_stmt|;
comment|/// If IsWritten is true, then this number keeps track of the textual order
comment|/// of this initializer in the original sources, counting from 0; otherwise,
comment|/// it stores the number of array index variables stored after this object
comment|/// in memory.
name|unsigned
name|SourceOrderOrNumArrayIndices
range|:
literal|13
decl_stmt|;
name|CXXCtorInitializer
argument_list|(
argument|ASTContext&Context
argument_list|,
argument|FieldDecl *Member
argument_list|,
argument|SourceLocation MemberLoc
argument_list|,
argument|SourceLocation L
argument_list|,
argument|Expr *Init
argument_list|,
argument|SourceLocation R
argument_list|,
argument|VarDecl **Indices
argument_list|,
argument|unsigned NumIndices
argument_list|)
empty_stmt|;
name|public
label|:
comment|/// \brief Creates a new base-class initializer.
name|explicit
name|CXXCtorInitializer
parameter_list|(
name|ASTContext
modifier|&
name|Context
parameter_list|,
name|TypeSourceInfo
modifier|*
name|TInfo
parameter_list|,
name|bool
name|IsVirtual
parameter_list|,
name|SourceLocation
name|L
parameter_list|,
name|Expr
modifier|*
name|Init
parameter_list|,
name|SourceLocation
name|R
parameter_list|,
name|SourceLocation
name|EllipsisLoc
parameter_list|)
function_decl|;
comment|/// \brief Creates a new member initializer.
name|explicit
name|CXXCtorInitializer
parameter_list|(
name|ASTContext
modifier|&
name|Context
parameter_list|,
name|FieldDecl
modifier|*
name|Member
parameter_list|,
name|SourceLocation
name|MemberLoc
parameter_list|,
name|SourceLocation
name|L
parameter_list|,
name|Expr
modifier|*
name|Init
parameter_list|,
name|SourceLocation
name|R
parameter_list|)
function_decl|;
comment|/// \brief Creates a new anonymous field initializer.
name|explicit
name|CXXCtorInitializer
parameter_list|(
name|ASTContext
modifier|&
name|Context
parameter_list|,
name|IndirectFieldDecl
modifier|*
name|Member
parameter_list|,
name|SourceLocation
name|MemberLoc
parameter_list|,
name|SourceLocation
name|L
parameter_list|,
name|Expr
modifier|*
name|Init
parameter_list|,
name|SourceLocation
name|R
parameter_list|)
function_decl|;
comment|/// \brief Creates a new delegating initializer.
name|explicit
name|CXXCtorInitializer
parameter_list|(
name|ASTContext
modifier|&
name|Context
parameter_list|,
name|TypeSourceInfo
modifier|*
name|TInfo
parameter_list|,
name|SourceLocation
name|L
parameter_list|,
name|Expr
modifier|*
name|Init
parameter_list|,
name|SourceLocation
name|R
parameter_list|)
function_decl|;
comment|/// \brief Creates a new member initializer that optionally contains
comment|/// array indices used to describe an elementwise initialization.
specifier|static
name|CXXCtorInitializer
modifier|*
name|Create
parameter_list|(
name|ASTContext
modifier|&
name|Context
parameter_list|,
name|FieldDecl
modifier|*
name|Member
parameter_list|,
name|SourceLocation
name|MemberLoc
parameter_list|,
name|SourceLocation
name|L
parameter_list|,
name|Expr
modifier|*
name|Init
parameter_list|,
name|SourceLocation
name|R
parameter_list|,
name|VarDecl
modifier|*
modifier|*
name|Indices
parameter_list|,
name|unsigned
name|NumIndices
parameter_list|)
function_decl|;
comment|/// \brief Determine whether this initializer is initializing a base class.
name|bool
name|isBaseInitializer
argument_list|()
specifier|const
block|{
return|return
name|Initializee
operator|.
name|is
operator|<
name|TypeSourceInfo
operator|*
operator|>
operator|(
operator|)
operator|&&
operator|!
name|IsDelegating
return|;
block|}
comment|/// \brief Determine whether this initializer is initializing a non-static
comment|/// data member.
name|bool
name|isMemberInitializer
argument_list|()
specifier|const
block|{
return|return
name|Initializee
operator|.
name|is
operator|<
name|FieldDecl
operator|*
operator|>
operator|(
operator|)
return|;
block|}
name|bool
name|isAnyMemberInitializer
argument_list|()
specifier|const
block|{
return|return
name|isMemberInitializer
argument_list|()
operator|||
name|isIndirectMemberInitializer
argument_list|()
return|;
block|}
name|bool
name|isIndirectMemberInitializer
argument_list|()
specifier|const
block|{
return|return
name|Initializee
operator|.
name|is
operator|<
name|IndirectFieldDecl
operator|*
operator|>
operator|(
operator|)
return|;
block|}
comment|/// \brief Determine whether this initializer is an implicit initializer
comment|/// generated for a field with an initializer defined on the member
comment|/// declaration.
comment|///
comment|/// In-class member initializers (also known as "non-static data member
comment|/// initializations", NSDMIs) were introduced in C++11.
name|bool
name|isInClassMemberInitializer
argument_list|()
specifier|const
block|{
return|return
name|isa
operator|<
name|CXXDefaultInitExpr
operator|>
operator|(
name|Init
operator|)
return|;
block|}
comment|/// \brief Determine whether this initializer is creating a delegating
comment|/// constructor.
name|bool
name|isDelegatingInitializer
argument_list|()
specifier|const
block|{
return|return
name|Initializee
operator|.
name|is
operator|<
name|TypeSourceInfo
operator|*
operator|>
operator|(
operator|)
operator|&&
name|IsDelegating
return|;
block|}
comment|/// \brief Determine whether this initializer is a pack expansion.
name|bool
name|isPackExpansion
argument_list|()
specifier|const
block|{
return|return
name|isBaseInitializer
argument_list|()
operator|&&
name|MemberOrEllipsisLocation
operator|.
name|isValid
argument_list|()
return|;
block|}
comment|// \brief For a pack expansion, returns the location of the ellipsis.
name|SourceLocation
name|getEllipsisLoc
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
name|isPackExpansion
argument_list|()
operator|&&
literal|"Initializer is not a pack expansion"
argument_list|)
block|;
return|return
name|MemberOrEllipsisLocation
return|;
block|}
comment|/// If this is a base class initializer, returns the type of the
comment|/// base class with location information. Otherwise, returns an NULL
comment|/// type location.
name|TypeLoc
name|getBaseClassLoc
argument_list|()
specifier|const
expr_stmt|;
comment|/// If this is a base class initializer, returns the type of the base class.
comment|/// Otherwise, returns null.
specifier|const
name|Type
operator|*
name|getBaseClass
argument_list|()
specifier|const
expr_stmt|;
comment|/// Returns whether the base is virtual or not.
name|bool
name|isBaseVirtual
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
name|isBaseInitializer
argument_list|()
operator|&&
literal|"Must call this on base initializer!"
argument_list|)
block|;
return|return
name|IsVirtual
return|;
block|}
comment|/// \brief Returns the declarator information for a base class or delegating
comment|/// initializer.
name|TypeSourceInfo
operator|*
name|getTypeSourceInfo
argument_list|()
specifier|const
block|{
return|return
name|Initializee
operator|.
name|dyn_cast
operator|<
name|TypeSourceInfo
operator|*
operator|>
operator|(
operator|)
return|;
block|}
comment|/// \brief If this is a member initializer, returns the declaration of the
comment|/// non-static data member being initialized. Otherwise, returns null.
name|FieldDecl
operator|*
name|getMember
argument_list|()
specifier|const
block|{
if|if
condition|(
name|isMemberInitializer
argument_list|()
condition|)
return|return
name|Initializee
operator|.
name|get
operator|<
name|FieldDecl
operator|*
operator|>
operator|(
operator|)
return|;
return|return
literal|0
return|;
block|}
end_decl_stmt

begin_expr_stmt
name|FieldDecl
operator|*
name|getAnyMember
argument_list|()
specifier|const
block|{
if|if
condition|(
name|isMemberInitializer
argument_list|()
condition|)
return|return
name|Initializee
operator|.
name|get
operator|<
name|FieldDecl
operator|*
operator|>
operator|(
operator|)
return|;
end_expr_stmt

begin_if
if|if
condition|(
name|isIndirectMemberInitializer
argument_list|()
condition|)
return|return
name|Initializee
operator|.
name|get
operator|<
name|IndirectFieldDecl
operator|*
operator|>
operator|(
operator|)
operator|->
name|getAnonField
argument_list|()
return|;
end_if

begin_return
return|return
literal|0
return|;
end_return

begin_expr_stmt
unit|}    IndirectFieldDecl
operator|*
name|getIndirectMember
argument_list|()
specifier|const
block|{
if|if
condition|(
name|isIndirectMemberInitializer
argument_list|()
condition|)
return|return
name|Initializee
operator|.
name|get
operator|<
name|IndirectFieldDecl
operator|*
operator|>
operator|(
operator|)
return|;
end_expr_stmt

begin_return
return|return
literal|0
return|;
end_return

begin_macro
unit|}    SourceLocation
name|getMemberLocation
argument_list|()
end_macro

begin_expr_stmt
specifier|const
block|{
return|return
name|MemberOrEllipsisLocation
return|;
block|}
end_expr_stmt

begin_comment
comment|/// \brief Determine the source location of the initializer.
end_comment

begin_expr_stmt
name|SourceLocation
name|getSourceLocation
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// \brief Determine the source range covering the entire initializer.
end_comment

begin_expr_stmt
name|SourceRange
name|getSourceRange
argument_list|()
specifier|const
name|LLVM_READONLY
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// \brief Determine whether this initializer is explicitly written
end_comment

begin_comment
comment|/// in the source code.
end_comment

begin_expr_stmt
name|bool
name|isWritten
argument_list|()
specifier|const
block|{
return|return
name|IsWritten
return|;
block|}
end_expr_stmt

begin_comment
comment|/// \brief Return the source position of the initializer, counting from 0.
end_comment

begin_comment
comment|/// If the initializer was implicit, -1 is returned.
end_comment

begin_expr_stmt
name|int
name|getSourceOrder
argument_list|()
specifier|const
block|{
return|return
name|IsWritten
operator|?
name|static_cast
operator|<
name|int
operator|>
operator|(
name|SourceOrderOrNumArrayIndices
operator|)
operator|:
operator|-
literal|1
return|;
block|}
end_expr_stmt

begin_comment
comment|/// \brief Set the source order of this initializer.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This can only be called once for each initializer; it cannot be called
end_comment

begin_comment
comment|/// on an initializer having a positive number of (implicit) array indices.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This assumes that the initialzier was written in the source code, and
end_comment

begin_comment
comment|/// ensures that isWritten() returns true.
end_comment

begin_function
name|void
name|setSourceOrder
parameter_list|(
name|int
name|pos
parameter_list|)
block|{
name|assert
argument_list|(
operator|!
name|IsWritten
operator|&&
literal|"calling twice setSourceOrder() on the same initializer"
argument_list|)
expr_stmt|;
name|assert
argument_list|(
name|SourceOrderOrNumArrayIndices
operator|==
literal|0
operator|&&
literal|"setSourceOrder() used when there are implicit array indices"
argument_list|)
expr_stmt|;
name|assert
argument_list|(
name|pos
operator|>=
literal|0
operator|&&
literal|"setSourceOrder() used to make an initializer implicit"
argument_list|)
expr_stmt|;
name|IsWritten
operator|=
name|true
expr_stmt|;
name|SourceOrderOrNumArrayIndices
operator|=
name|static_cast
operator|<
name|unsigned
operator|>
operator|(
name|pos
operator|)
expr_stmt|;
block|}
end_function

begin_expr_stmt
name|SourceLocation
name|getLParenLoc
argument_list|()
specifier|const
block|{
return|return
name|LParenLoc
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|SourceLocation
name|getRParenLoc
argument_list|()
specifier|const
block|{
return|return
name|RParenLoc
return|;
block|}
end_expr_stmt

begin_comment
comment|/// \brief Determine the number of implicit array indices used while
end_comment

begin_comment
comment|/// described an array member initialization.
end_comment

begin_expr_stmt
name|unsigned
name|getNumArrayIndices
argument_list|()
specifier|const
block|{
return|return
name|IsWritten
operator|?
literal|0
operator|:
name|SourceOrderOrNumArrayIndices
return|;
block|}
end_expr_stmt

begin_comment
comment|/// \brief Retrieve a particular array index variable used to
end_comment

begin_comment
comment|/// describe an array member initialization.
end_comment

begin_function
name|VarDecl
modifier|*
name|getArrayIndex
parameter_list|(
name|unsigned
name|I
parameter_list|)
block|{
name|assert
argument_list|(
name|I
operator|<
name|getNumArrayIndices
argument_list|()
operator|&&
literal|"Out of bounds member array index"
argument_list|)
expr_stmt|;
return|return
name|reinterpret_cast
operator|<
name|VarDecl
operator|*
operator|*
operator|>
operator|(
name|this
operator|+
literal|1
operator|)
index|[
name|I
index|]
return|;
block|}
end_function

begin_decl_stmt
specifier|const
name|VarDecl
modifier|*
name|getArrayIndex
argument_list|(
name|unsigned
name|I
argument_list|)
decl|const
block|{
name|assert
argument_list|(
name|I
operator|<
name|getNumArrayIndices
argument_list|()
operator|&&
literal|"Out of bounds member array index"
argument_list|)
expr_stmt|;
return|return
name|reinterpret_cast
operator|<
specifier|const
name|VarDecl
operator|*
specifier|const
operator|*
operator|>
operator|(
name|this
operator|+
literal|1
operator|)
index|[
name|I
index|]
return|;
block|}
end_decl_stmt

begin_function
name|void
name|setArrayIndex
parameter_list|(
name|unsigned
name|I
parameter_list|,
name|VarDecl
modifier|*
name|Index
parameter_list|)
block|{
name|assert
argument_list|(
name|I
operator|<
name|getNumArrayIndices
argument_list|()
operator|&&
literal|"Out of bounds member array index"
argument_list|)
expr_stmt|;
name|reinterpret_cast
operator|<
name|VarDecl
operator|*
operator|*
operator|>
operator|(
name|this
operator|+
literal|1
operator|)
index|[
name|I
index|]
operator|=
name|Index
expr_stmt|;
block|}
end_function

begin_expr_stmt
name|ArrayRef
operator|<
name|VarDecl
operator|*
operator|>
name|getArrayIndexes
argument_list|()
block|{
name|assert
argument_list|(
name|getNumArrayIndices
argument_list|()
operator|!=
literal|0
operator|&&
literal|"Getting indexes for non-array init"
argument_list|)
block|;
return|return
name|ArrayRef
operator|<
name|VarDecl
operator|*
operator|>
operator|(
name|reinterpret_cast
operator|<
name|VarDecl
operator|*
operator|*
operator|>
operator|(
name|this
operator|+
literal|1
operator|)
operator|,
name|getNumArrayIndices
argument_list|()
operator|)
return|;
block|}
end_expr_stmt

begin_comment
comment|/// \brief Get the initializer.
end_comment

begin_expr_stmt
name|Expr
operator|*
name|getInit
argument_list|()
specifier|const
block|{
return|return
name|static_cast
operator|<
name|Expr
operator|*
operator|>
operator|(
name|Init
operator|)
return|;
block|}
end_expr_stmt

begin_comment
unit|};
comment|/// \brief Represents a C++ constructor within a class.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// For example:
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \code
end_comment

begin_comment
comment|/// class X {
end_comment

begin_comment
comment|/// public:
end_comment

begin_comment
comment|///   explicit X(int); // represented by a CXXConstructorDecl.
end_comment

begin_comment
comment|/// };
end_comment

begin_comment
comment|/// \endcode
end_comment

begin_decl_stmt
name|class
name|CXXConstructorDecl
range|:
name|public
name|CXXMethodDecl
block|{
name|virtual
name|void
name|anchor
argument_list|()
block|;
comment|/// \brief Whether this constructor declaration has the \c explicit keyword
comment|/// specified.
name|bool
name|IsExplicitSpecified
operator|:
literal|1
block|;
comment|/// \name Support for base and member initializers.
comment|/// \{
comment|/// \brief The arguments used to initialize the base or member.
name|CXXCtorInitializer
operator|*
operator|*
name|CtorInitializers
block|;
name|unsigned
name|NumCtorInitializers
block|;
comment|/// \}
name|CXXConstructorDecl
argument_list|(
argument|CXXRecordDecl *RD
argument_list|,
argument|SourceLocation StartLoc
argument_list|,
argument|const DeclarationNameInfo&NameInfo
argument_list|,
argument|QualType T
argument_list|,
argument|TypeSourceInfo *TInfo
argument_list|,
argument|bool isExplicitSpecified
argument_list|,
argument|bool isInline
argument_list|,
argument|bool isImplicitlyDeclared
argument_list|,
argument|bool isConstexpr
argument_list|)
operator|:
name|CXXMethodDecl
argument_list|(
name|CXXConstructor
argument_list|,
name|RD
argument_list|,
name|StartLoc
argument_list|,
name|NameInfo
argument_list|,
name|T
argument_list|,
name|TInfo
argument_list|,
name|SC_None
argument_list|,
name|isInline
argument_list|,
name|isConstexpr
argument_list|,
name|SourceLocation
argument_list|()
argument_list|)
block|,
name|IsExplicitSpecified
argument_list|(
name|isExplicitSpecified
argument_list|)
block|,
name|CtorInitializers
argument_list|(
literal|0
argument_list|)
block|,
name|NumCtorInitializers
argument_list|(
literal|0
argument_list|)
block|{
name|setImplicit
argument_list|(
name|isImplicitlyDeclared
argument_list|)
block|;   }
name|public
operator|:
specifier|static
name|CXXConstructorDecl
operator|*
name|CreateDeserialized
argument_list|(
argument|ASTContext&C
argument_list|,
argument|unsigned ID
argument_list|)
block|;
specifier|static
name|CXXConstructorDecl
operator|*
name|Create
argument_list|(
argument|ASTContext&C
argument_list|,
argument|CXXRecordDecl *RD
argument_list|,
argument|SourceLocation StartLoc
argument_list|,
argument|const DeclarationNameInfo&NameInfo
argument_list|,
argument|QualType T
argument_list|,
argument|TypeSourceInfo *TInfo
argument_list|,
argument|bool isExplicit
argument_list|,
argument|bool isInline
argument_list|,
argument|bool isImplicitlyDeclared
argument_list|,
argument|bool isConstexpr
argument_list|)
block|;
comment|/// \brief Determine whether this constructor declaration has the
comment|/// \c explicit keyword specified.
name|bool
name|isExplicitSpecified
argument_list|()
specifier|const
block|{
return|return
name|IsExplicitSpecified
return|;
block|}
comment|/// \brief Determine whether this constructor was marked "explicit" or not.
name|bool
name|isExplicit
argument_list|()
specifier|const
block|{
return|return
name|cast
operator|<
name|CXXConstructorDecl
operator|>
operator|(
name|getFirstDecl
argument_list|()
operator|)
operator|->
name|isExplicitSpecified
argument_list|()
return|;
block|}
comment|/// \brief Iterates through the member/base initializer list.
typedef|typedef
name|CXXCtorInitializer
modifier|*
modifier|*
name|init_iterator
typedef|;
end_decl_stmt

begin_comment
comment|/// \brief Iterates through the member/base initializer list.
end_comment

begin_typedef
typedef|typedef
name|CXXCtorInitializer
modifier|*
specifier|const
modifier|*
name|init_const_iterator
typedef|;
end_typedef

begin_comment
comment|/// \brief Retrieve an iterator to the first initializer.
end_comment

begin_function
name|init_iterator
name|init_begin
parameter_list|()
block|{
return|return
name|CtorInitializers
return|;
block|}
end_function

begin_comment
comment|/// \brief Retrieve an iterator to the first initializer.
end_comment

begin_expr_stmt
name|init_const_iterator
name|init_begin
argument_list|()
specifier|const
block|{
return|return
name|CtorInitializers
return|;
block|}
end_expr_stmt

begin_comment
comment|/// \brief Retrieve an iterator past the last initializer.
end_comment

begin_function
name|init_iterator
name|init_end
parameter_list|()
block|{
return|return
name|CtorInitializers
operator|+
name|NumCtorInitializers
return|;
block|}
end_function

begin_comment
comment|/// \brief Retrieve an iterator past the last initializer.
end_comment

begin_expr_stmt
name|init_const_iterator
name|init_end
argument_list|()
specifier|const
block|{
return|return
name|CtorInitializers
operator|+
name|NumCtorInitializers
return|;
block|}
end_expr_stmt

begin_typedef
typedef|typedef
name|std
operator|::
name|reverse_iterator
operator|<
name|init_iterator
operator|>
name|init_reverse_iterator
expr_stmt|;
end_typedef

begin_typedef
typedef|typedef
name|std
operator|::
name|reverse_iterator
operator|<
name|init_const_iterator
operator|>
name|init_const_reverse_iterator
expr_stmt|;
end_typedef

begin_function
name|init_reverse_iterator
name|init_rbegin
parameter_list|()
block|{
return|return
name|init_reverse_iterator
argument_list|(
name|init_end
argument_list|()
argument_list|)
return|;
block|}
end_function

begin_expr_stmt
name|init_const_reverse_iterator
name|init_rbegin
argument_list|()
specifier|const
block|{
return|return
name|init_const_reverse_iterator
argument_list|(
name|init_end
argument_list|()
argument_list|)
return|;
block|}
end_expr_stmt

begin_function
name|init_reverse_iterator
name|init_rend
parameter_list|()
block|{
return|return
name|init_reverse_iterator
argument_list|(
name|init_begin
argument_list|()
argument_list|)
return|;
block|}
end_function

begin_expr_stmt
name|init_const_reverse_iterator
name|init_rend
argument_list|()
specifier|const
block|{
return|return
name|init_const_reverse_iterator
argument_list|(
name|init_begin
argument_list|()
argument_list|)
return|;
block|}
end_expr_stmt

begin_comment
comment|/// \brief Determine the number of arguments used to initialize the member
end_comment

begin_comment
comment|/// or base.
end_comment

begin_expr_stmt
name|unsigned
name|getNumCtorInitializers
argument_list|()
specifier|const
block|{
return|return
name|NumCtorInitializers
return|;
block|}
end_expr_stmt

begin_function
name|void
name|setNumCtorInitializers
parameter_list|(
name|unsigned
name|numCtorInitializers
parameter_list|)
block|{
name|NumCtorInitializers
operator|=
name|numCtorInitializers
expr_stmt|;
block|}
end_function

begin_function
name|void
name|setCtorInitializers
parameter_list|(
name|CXXCtorInitializer
modifier|*
modifier|*
name|initializers
parameter_list|)
block|{
name|CtorInitializers
operator|=
name|initializers
expr_stmt|;
block|}
end_function

begin_comment
comment|/// \brief Determine whether this constructor is a delegating constructor.
end_comment

begin_expr_stmt
name|bool
name|isDelegatingConstructor
argument_list|()
specifier|const
block|{
return|return
operator|(
name|getNumCtorInitializers
argument_list|()
operator|==
literal|1
operator|)
operator|&&
name|CtorInitializers
index|[
literal|0
index|]
operator|->
name|isDelegatingInitializer
argument_list|()
return|;
block|}
end_expr_stmt

begin_comment
comment|/// \brief When this constructor delegates to another, retrieve the target.
end_comment

begin_expr_stmt
name|CXXConstructorDecl
operator|*
name|getTargetConstructor
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// Whether this constructor is a default
end_comment

begin_comment
comment|/// constructor (C++ [class.ctor]p5), which can be used to
end_comment

begin_comment
comment|/// default-initialize a class of this type.
end_comment

begin_expr_stmt
name|bool
name|isDefaultConstructor
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// \brief Whether this constructor is a copy constructor (C++ [class.copy]p2,
end_comment

begin_comment
comment|/// which can be used to copy the class.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \p TypeQuals will be set to the qualifiers on the
end_comment

begin_comment
comment|/// argument type. For example, \p TypeQuals would be set to \c
end_comment

begin_comment
comment|/// Qualifiers::Const for the following copy constructor:
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \code
end_comment

begin_comment
comment|/// class X {
end_comment

begin_comment
comment|/// public:
end_comment

begin_comment
comment|///   X(const X&);
end_comment

begin_comment
comment|/// };
end_comment

begin_comment
comment|/// \endcode
end_comment

begin_decl_stmt
name|bool
name|isCopyConstructor
argument_list|(
name|unsigned
operator|&
name|TypeQuals
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// Whether this constructor is a copy
end_comment

begin_comment
comment|/// constructor (C++ [class.copy]p2, which can be used to copy the
end_comment

begin_comment
comment|/// class.
end_comment

begin_expr_stmt
name|bool
name|isCopyConstructor
argument_list|()
specifier|const
block|{
name|unsigned
name|TypeQuals
operator|=
literal|0
block|;
return|return
name|isCopyConstructor
argument_list|(
name|TypeQuals
argument_list|)
return|;
block|}
end_expr_stmt

begin_comment
comment|/// \brief Determine whether this constructor is a move constructor
end_comment

begin_comment
comment|/// (C++0x [class.copy]p3), which can be used to move values of the class.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param TypeQuals If this constructor is a move constructor, will be set
end_comment

begin_comment
comment|/// to the type qualifiers on the referent of the first parameter's type.
end_comment

begin_decl_stmt
name|bool
name|isMoveConstructor
argument_list|(
name|unsigned
operator|&
name|TypeQuals
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// \brief Determine whether this constructor is a move constructor
end_comment

begin_comment
comment|/// (C++0x [class.copy]p3), which can be used to move values of the class.
end_comment

begin_expr_stmt
name|bool
name|isMoveConstructor
argument_list|()
specifier|const
block|{
name|unsigned
name|TypeQuals
operator|=
literal|0
block|;
return|return
name|isMoveConstructor
argument_list|(
name|TypeQuals
argument_list|)
return|;
block|}
end_expr_stmt

begin_comment
comment|/// \brief Determine whether this is a copy or move constructor.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param TypeQuals Will be set to the type qualifiers on the reference
end_comment

begin_comment
comment|/// parameter, if in fact this is a copy or move constructor.
end_comment

begin_decl_stmt
name|bool
name|isCopyOrMoveConstructor
argument_list|(
name|unsigned
operator|&
name|TypeQuals
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// \brief Determine whether this a copy or move constructor.
end_comment

begin_expr_stmt
name|bool
name|isCopyOrMoveConstructor
argument_list|()
specifier|const
block|{
name|unsigned
name|Quals
block|;
return|return
name|isCopyOrMoveConstructor
argument_list|(
name|Quals
argument_list|)
return|;
block|}
end_expr_stmt

begin_comment
comment|/// Whether this constructor is a
end_comment

begin_comment
comment|/// converting constructor (C++ [class.conv.ctor]), which can be
end_comment

begin_comment
comment|/// used for user-defined conversions.
end_comment

begin_decl_stmt
name|bool
name|isConvertingConstructor
argument_list|(
name|bool
name|AllowExplicit
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// \brief Determine whether this is a member template specialization that
end_comment

begin_comment
comment|/// would copy the object to itself. Such constructors are never used to copy
end_comment

begin_comment
comment|/// an object.
end_comment

begin_expr_stmt
name|bool
name|isSpecializationCopyingObject
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// \brief Get the constructor that this inheriting constructor is based on.
end_comment

begin_expr_stmt
specifier|const
name|CXXConstructorDecl
operator|*
name|getInheritedConstructor
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// \brief Set the constructor that this inheriting constructor is based on.
end_comment

begin_function_decl
name|void
name|setInheritedConstructor
parameter_list|(
specifier|const
name|CXXConstructorDecl
modifier|*
name|BaseCtor
parameter_list|)
function_decl|;
end_function_decl

begin_expr_stmt
specifier|const
name|CXXConstructorDecl
operator|*
name|getCanonicalDecl
argument_list|()
specifier|const
block|{
return|return
name|cast
operator|<
name|CXXConstructorDecl
operator|>
operator|(
name|FunctionDecl
operator|::
name|getCanonicalDecl
argument_list|()
operator|)
return|;
block|}
end_expr_stmt

begin_function
name|CXXConstructorDecl
modifier|*
name|getCanonicalDecl
parameter_list|()
block|{
return|return
name|cast
operator|<
name|CXXConstructorDecl
operator|>
operator|(
name|FunctionDecl
operator|::
name|getCanonicalDecl
argument_list|()
operator|)
return|;
block|}
end_function

begin_comment
comment|// Implement isa/cast/dyncast/etc.
end_comment

begin_function
specifier|static
name|bool
name|classof
parameter_list|(
specifier|const
name|Decl
modifier|*
name|D
parameter_list|)
block|{
return|return
name|classofKind
argument_list|(
name|D
operator|->
name|getKind
argument_list|()
argument_list|)
return|;
block|}
end_function

begin_function
specifier|static
name|bool
name|classofKind
parameter_list|(
name|Kind
name|K
parameter_list|)
block|{
return|return
name|K
operator|==
name|CXXConstructor
return|;
block|}
end_function

begin_decl_stmt
name|friend
name|class
name|ASTDeclReader
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|friend
name|class
name|ASTDeclWriter
decl_stmt|;
end_decl_stmt

begin_comment
unit|};
comment|/// \brief Represents a C++ destructor within a class.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// For example:
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \code
end_comment

begin_comment
comment|/// class X {
end_comment

begin_comment
comment|/// public:
end_comment

begin_comment
comment|///   ~X(); // represented by a CXXDestructorDecl.
end_comment

begin_comment
comment|/// };
end_comment

begin_comment
comment|/// \endcode
end_comment

begin_decl_stmt
name|class
name|CXXDestructorDecl
range|:
name|public
name|CXXMethodDecl
block|{
name|virtual
name|void
name|anchor
argument_list|()
block|;
name|FunctionDecl
operator|*
name|OperatorDelete
block|;
name|CXXDestructorDecl
argument_list|(
argument|CXXRecordDecl *RD
argument_list|,
argument|SourceLocation StartLoc
argument_list|,
argument|const DeclarationNameInfo&NameInfo
argument_list|,
argument|QualType T
argument_list|,
argument|TypeSourceInfo *TInfo
argument_list|,
argument|bool isInline
argument_list|,
argument|bool isImplicitlyDeclared
argument_list|)
operator|:
name|CXXMethodDecl
argument_list|(
name|CXXDestructor
argument_list|,
name|RD
argument_list|,
name|StartLoc
argument_list|,
name|NameInfo
argument_list|,
name|T
argument_list|,
name|TInfo
argument_list|,
name|SC_None
argument_list|,
name|isInline
argument_list|,
comment|/*isConstexpr=*/
name|false
argument_list|,
name|SourceLocation
argument_list|()
argument_list|)
block|,
name|OperatorDelete
argument_list|(
literal|0
argument_list|)
block|{
name|setImplicit
argument_list|(
name|isImplicitlyDeclared
argument_list|)
block|;   }
name|public
operator|:
specifier|static
name|CXXDestructorDecl
operator|*
name|Create
argument_list|(
argument|ASTContext&C
argument_list|,
argument|CXXRecordDecl *RD
argument_list|,
argument|SourceLocation StartLoc
argument_list|,
argument|const DeclarationNameInfo&NameInfo
argument_list|,
argument|QualType T
argument_list|,
argument|TypeSourceInfo* TInfo
argument_list|,
argument|bool isInline
argument_list|,
argument|bool isImplicitlyDeclared
argument_list|)
block|;
specifier|static
name|CXXDestructorDecl
operator|*
name|CreateDeserialized
argument_list|(
argument|ASTContext& C
argument_list|,
argument|unsigned ID
argument_list|)
block|;
name|void
name|setOperatorDelete
argument_list|(
argument|FunctionDecl *OD
argument_list|)
block|{
name|OperatorDelete
operator|=
name|OD
block|; }
specifier|const
name|FunctionDecl
operator|*
name|getOperatorDelete
argument_list|()
specifier|const
block|{
return|return
name|OperatorDelete
return|;
block|}
comment|// Implement isa/cast/dyncast/etc.
specifier|static
name|bool
name|classof
argument_list|(
argument|const Decl *D
argument_list|)
block|{
return|return
name|classofKind
argument_list|(
name|D
operator|->
name|getKind
argument_list|()
argument_list|)
return|;
block|}
specifier|static
name|bool
name|classofKind
argument_list|(
argument|Kind K
argument_list|)
block|{
return|return
name|K
operator|==
name|CXXDestructor
return|;
block|}
name|friend
name|class
name|ASTDeclReader
block|;
name|friend
name|class
name|ASTDeclWriter
block|; }
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// \brief Represents a C++ conversion function within a class.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// For example:
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \code
end_comment

begin_comment
comment|/// class X {
end_comment

begin_comment
comment|/// public:
end_comment

begin_comment
comment|///   operator bool();
end_comment

begin_comment
comment|/// };
end_comment

begin_comment
comment|/// \endcode
end_comment

begin_decl_stmt
name|class
name|CXXConversionDecl
range|:
name|public
name|CXXMethodDecl
block|{
name|virtual
name|void
name|anchor
argument_list|()
block|;
comment|/// Whether this conversion function declaration is marked
comment|/// "explicit", meaning that it can only be applied when the user
comment|/// explicitly wrote a cast. This is a C++0x feature.
name|bool
name|IsExplicitSpecified
operator|:
literal|1
block|;
name|CXXConversionDecl
argument_list|(
argument|CXXRecordDecl *RD
argument_list|,
argument|SourceLocation StartLoc
argument_list|,
argument|const DeclarationNameInfo&NameInfo
argument_list|,
argument|QualType T
argument_list|,
argument|TypeSourceInfo *TInfo
argument_list|,
argument|bool isInline
argument_list|,
argument|bool isExplicitSpecified
argument_list|,
argument|bool isConstexpr
argument_list|,
argument|SourceLocation EndLocation
argument_list|)
operator|:
name|CXXMethodDecl
argument_list|(
name|CXXConversion
argument_list|,
name|RD
argument_list|,
name|StartLoc
argument_list|,
name|NameInfo
argument_list|,
name|T
argument_list|,
name|TInfo
argument_list|,
name|SC_None
argument_list|,
name|isInline
argument_list|,
name|isConstexpr
argument_list|,
name|EndLocation
argument_list|)
block|,
name|IsExplicitSpecified
argument_list|(
argument|isExplicitSpecified
argument_list|)
block|{ }
name|public
operator|:
specifier|static
name|CXXConversionDecl
operator|*
name|Create
argument_list|(
argument|ASTContext&C
argument_list|,
argument|CXXRecordDecl *RD
argument_list|,
argument|SourceLocation StartLoc
argument_list|,
argument|const DeclarationNameInfo&NameInfo
argument_list|,
argument|QualType T
argument_list|,
argument|TypeSourceInfo *TInfo
argument_list|,
argument|bool isInline
argument_list|,
argument|bool isExplicit
argument_list|,
argument|bool isConstexpr
argument_list|,
argument|SourceLocation EndLocation
argument_list|)
block|;
specifier|static
name|CXXConversionDecl
operator|*
name|CreateDeserialized
argument_list|(
argument|ASTContext&C
argument_list|,
argument|unsigned ID
argument_list|)
block|;
comment|/// Whether this conversion function declaration is marked
comment|/// "explicit", meaning that it can only be used for direct initialization
comment|/// (including explitly written casts).  This is a C++11 feature.
name|bool
name|isExplicitSpecified
argument_list|()
specifier|const
block|{
return|return
name|IsExplicitSpecified
return|;
block|}
comment|/// \brief Whether this is an explicit conversion operator (C++11 and later).
comment|///
comment|/// Explicit conversion operators are only considered for direct
comment|/// initialization, e.g., when the user has explicitly written a cast.
name|bool
name|isExplicit
argument_list|()
specifier|const
block|{
return|return
name|cast
operator|<
name|CXXConversionDecl
operator|>
operator|(
name|getFirstDecl
argument_list|()
operator|)
operator|->
name|isExplicitSpecified
argument_list|()
return|;
block|}
comment|/// \brief Returns the type that this conversion function is converting to.
name|QualType
name|getConversionType
argument_list|()
specifier|const
block|{
return|return
name|getType
argument_list|()
operator|->
name|getAs
operator|<
name|FunctionType
operator|>
operator|(
operator|)
operator|->
name|getResultType
argument_list|()
return|;
block|}
comment|/// \brief Determine whether this conversion function is a conversion from
comment|/// a lambda closure type to a block pointer.
name|bool
name|isLambdaToBlockPointerConversion
argument_list|()
specifier|const
block|;
comment|// Implement isa/cast/dyncast/etc.
specifier|static
name|bool
name|classof
argument_list|(
argument|const Decl *D
argument_list|)
block|{
return|return
name|classofKind
argument_list|(
name|D
operator|->
name|getKind
argument_list|()
argument_list|)
return|;
block|}
specifier|static
name|bool
name|classofKind
argument_list|(
argument|Kind K
argument_list|)
block|{
return|return
name|K
operator|==
name|CXXConversion
return|;
block|}
name|friend
name|class
name|ASTDeclReader
block|;
name|friend
name|class
name|ASTDeclWriter
block|; }
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// \brief Represents a linkage specification.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// For example:
end_comment

begin_comment
comment|/// \code
end_comment

begin_comment
comment|///   extern "C" void foo();
end_comment

begin_comment
comment|/// \endcode
end_comment

begin_decl_stmt
name|class
name|LinkageSpecDecl
range|:
name|public
name|Decl
decl_stmt|,
name|public
name|DeclContext
block|{
name|virtual
name|void
name|anchor
parameter_list|()
function_decl|;
name|public
label|:
comment|/// \brief Represents the language in a linkage specification.
comment|///
comment|/// The values are part of the serialization ABI for
comment|/// ASTs and cannot be changed without altering that ABI.  To help
comment|/// ensure a stable ABI for this, we choose the DW_LANG_ encodings
comment|/// from the dwarf standard.
enum|enum
name|LanguageIDs
block|{
name|lang_c
init|=
comment|/* DW_LANG_C */
literal|0x0002
block|,
name|lang_cxx
init|=
comment|/* DW_LANG_C_plus_plus */
literal|0x0004
block|}
enum|;
name|private
label|:
comment|/// \brief The language for this linkage specification.
name|unsigned
name|Language
range|:
literal|3
decl_stmt|;
comment|/// \brief True if this linkage spec has braces.
comment|///
comment|/// This is needed so that hasBraces() returns the correct result while the
comment|/// linkage spec body is being parsed.  Once RBraceLoc has been set this is
comment|/// not used, so it doesn't need to be serialized.
name|unsigned
name|HasBraces
range|:
literal|1
decl_stmt|;
comment|/// \brief The source location for the extern keyword.
name|SourceLocation
name|ExternLoc
decl_stmt|;
comment|/// \brief The source location for the right brace (if valid).
name|SourceLocation
name|RBraceLoc
decl_stmt|;
name|LinkageSpecDecl
argument_list|(
argument|DeclContext *DC
argument_list|,
argument|SourceLocation ExternLoc
argument_list|,
argument|SourceLocation LangLoc
argument_list|,
argument|LanguageIDs lang
argument_list|,
argument|bool HasBraces
argument_list|)
block|:
name|Decl
argument_list|(
name|LinkageSpec
argument_list|,
name|DC
argument_list|,
name|LangLoc
argument_list|)
operator|,
name|DeclContext
argument_list|(
name|LinkageSpec
argument_list|)
operator|,
name|Language
argument_list|(
name|lang
argument_list|)
operator|,
name|HasBraces
argument_list|(
name|HasBraces
argument_list|)
operator|,
name|ExternLoc
argument_list|(
name|ExternLoc
argument_list|)
operator|,
name|RBraceLoc
argument_list|(
argument|SourceLocation()
argument_list|)
block|{ }
name|public
operator|:
specifier|static
name|LinkageSpecDecl
operator|*
name|Create
argument_list|(
argument|ASTContext&C
argument_list|,
argument|DeclContext *DC
argument_list|,
argument|SourceLocation ExternLoc
argument_list|,
argument|SourceLocation LangLoc
argument_list|,
argument|LanguageIDs Lang
argument_list|,
argument|bool HasBraces
argument_list|)
expr_stmt|;
specifier|static
name|LinkageSpecDecl
modifier|*
name|CreateDeserialized
parameter_list|(
name|ASTContext
modifier|&
name|C
parameter_list|,
name|unsigned
name|ID
parameter_list|)
function_decl|;
comment|/// \brief Return the language specified by this linkage specification.
name|LanguageIDs
name|getLanguage
argument_list|()
specifier|const
block|{
return|return
name|LanguageIDs
argument_list|(
name|Language
argument_list|)
return|;
block|}
comment|/// \brief Set the language specified by this linkage specification.
name|void
name|setLanguage
parameter_list|(
name|LanguageIDs
name|L
parameter_list|)
block|{
name|Language
operator|=
name|L
expr_stmt|;
block|}
comment|/// \brief Determines whether this linkage specification had braces in
comment|/// its syntactic form.
name|bool
name|hasBraces
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
operator|!
name|RBraceLoc
operator|.
name|isValid
argument_list|()
operator|||
name|HasBraces
argument_list|)
block|;
return|return
name|HasBraces
return|;
block|}
name|SourceLocation
name|getExternLoc
argument_list|()
specifier|const
block|{
return|return
name|ExternLoc
return|;
block|}
name|SourceLocation
name|getRBraceLoc
argument_list|()
specifier|const
block|{
return|return
name|RBraceLoc
return|;
block|}
name|void
name|setExternLoc
parameter_list|(
name|SourceLocation
name|L
parameter_list|)
block|{
name|ExternLoc
operator|=
name|L
expr_stmt|;
block|}
name|void
name|setRBraceLoc
parameter_list|(
name|SourceLocation
name|L
parameter_list|)
block|{
name|RBraceLoc
operator|=
name|L
expr_stmt|;
name|HasBraces
operator|=
name|RBraceLoc
operator|.
name|isValid
argument_list|()
expr_stmt|;
block|}
name|SourceLocation
name|getLocEnd
argument_list|()
specifier|const
name|LLVM_READONLY
block|{
if|if
condition|(
name|hasBraces
argument_list|()
condition|)
return|return
name|getRBraceLoc
argument_list|()
return|;
comment|// No braces: get the end location of the (only) declaration in context
comment|// (if present).
return|return
name|decls_empty
argument_list|()
condition|?
name|getLocation
argument_list|()
else|:
name|decls_begin
argument_list|()
operator|->
name|getLocEnd
argument_list|()
return|;
block|}
end_decl_stmt

begin_expr_stmt
name|SourceRange
name|getSourceRange
argument_list|()
specifier|const
name|LLVM_READONLY
block|{
return|return
name|SourceRange
argument_list|(
name|ExternLoc
argument_list|,
name|getLocEnd
argument_list|()
argument_list|)
return|;
block|}
end_expr_stmt

begin_function
specifier|static
name|bool
name|classof
parameter_list|(
specifier|const
name|Decl
modifier|*
name|D
parameter_list|)
block|{
return|return
name|classofKind
argument_list|(
name|D
operator|->
name|getKind
argument_list|()
argument_list|)
return|;
block|}
end_function

begin_function
specifier|static
name|bool
name|classofKind
parameter_list|(
name|Kind
name|K
parameter_list|)
block|{
return|return
name|K
operator|==
name|LinkageSpec
return|;
block|}
end_function

begin_function
specifier|static
name|DeclContext
modifier|*
name|castToDeclContext
parameter_list|(
specifier|const
name|LinkageSpecDecl
modifier|*
name|D
parameter_list|)
block|{
return|return
name|static_cast
operator|<
name|DeclContext
operator|*
operator|>
operator|(
name|const_cast
operator|<
name|LinkageSpecDecl
operator|*
operator|>
operator|(
name|D
operator|)
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|LinkageSpecDecl
modifier|*
name|castFromDeclContext
parameter_list|(
specifier|const
name|DeclContext
modifier|*
name|DC
parameter_list|)
block|{
return|return
name|static_cast
operator|<
name|LinkageSpecDecl
operator|*
operator|>
operator|(
name|const_cast
operator|<
name|DeclContext
operator|*
operator|>
operator|(
name|DC
operator|)
operator|)
return|;
block|}
end_function

begin_comment
unit|};
comment|/// \brief Represents C++ using-directive.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// For example:
end_comment

begin_comment
comment|/// \code
end_comment

begin_comment
comment|///    using namespace std;
end_comment

begin_comment
comment|/// \endcode
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \note UsingDirectiveDecl should be Decl not NamedDecl, but we provide
end_comment

begin_comment
comment|/// artificial names for all using-directives in order to store
end_comment

begin_comment
comment|/// them in DeclContext effectively.
end_comment

begin_decl_stmt
name|class
name|UsingDirectiveDecl
range|:
name|public
name|NamedDecl
block|{
name|virtual
name|void
name|anchor
argument_list|()
block|;
comment|/// \brief The location of the \c using keyword.
name|SourceLocation
name|UsingLoc
block|;
comment|/// \brief The location of the \c namespace keyword.
name|SourceLocation
name|NamespaceLoc
block|;
comment|/// \brief The nested-name-specifier that precedes the namespace.
name|NestedNameSpecifierLoc
name|QualifierLoc
block|;
comment|/// \brief The namespace nominated by this using-directive.
name|NamedDecl
operator|*
name|NominatedNamespace
block|;
comment|/// Enclosing context containing both using-directive and nominated
comment|/// namespace.
name|DeclContext
operator|*
name|CommonAncestor
block|;
comment|/// \brief Returns special DeclarationName used by using-directives.
comment|///
comment|/// This is only used by DeclContext for storing UsingDirectiveDecls in
comment|/// its lookup structure.
specifier|static
name|DeclarationName
name|getName
argument_list|()
block|{
return|return
name|DeclarationName
operator|::
name|getUsingDirectiveName
argument_list|()
return|;
block|}
name|UsingDirectiveDecl
argument_list|(
argument|DeclContext *DC
argument_list|,
argument|SourceLocation UsingLoc
argument_list|,
argument|SourceLocation NamespcLoc
argument_list|,
argument|NestedNameSpecifierLoc QualifierLoc
argument_list|,
argument|SourceLocation IdentLoc
argument_list|,
argument|NamedDecl *Nominated
argument_list|,
argument|DeclContext *CommonAncestor
argument_list|)
operator|:
name|NamedDecl
argument_list|(
name|UsingDirective
argument_list|,
name|DC
argument_list|,
name|IdentLoc
argument_list|,
name|getName
argument_list|()
argument_list|)
block|,
name|UsingLoc
argument_list|(
name|UsingLoc
argument_list|)
block|,
name|NamespaceLoc
argument_list|(
name|NamespcLoc
argument_list|)
block|,
name|QualifierLoc
argument_list|(
name|QualifierLoc
argument_list|)
block|,
name|NominatedNamespace
argument_list|(
name|Nominated
argument_list|)
block|,
name|CommonAncestor
argument_list|(
argument|CommonAncestor
argument_list|)
block|{ }
name|public
operator|:
comment|/// \brief Retrieve the nested-name-specifier that qualifies the
comment|/// name of the namespace, with source-location information.
name|NestedNameSpecifierLoc
name|getQualifierLoc
argument_list|()
specifier|const
block|{
return|return
name|QualifierLoc
return|;
block|}
comment|/// \brief Retrieve the nested-name-specifier that qualifies the
comment|/// name of the namespace.
name|NestedNameSpecifier
operator|*
name|getQualifier
argument_list|()
specifier|const
block|{
return|return
name|QualifierLoc
operator|.
name|getNestedNameSpecifier
argument_list|()
return|;
block|}
name|NamedDecl
operator|*
name|getNominatedNamespaceAsWritten
argument_list|()
block|{
return|return
name|NominatedNamespace
return|;
block|}
specifier|const
name|NamedDecl
operator|*
name|getNominatedNamespaceAsWritten
argument_list|()
specifier|const
block|{
return|return
name|NominatedNamespace
return|;
block|}
comment|/// \brief Returns the namespace nominated by this using-directive.
name|NamespaceDecl
operator|*
name|getNominatedNamespace
argument_list|()
block|;
specifier|const
name|NamespaceDecl
operator|*
name|getNominatedNamespace
argument_list|()
specifier|const
block|{
return|return
name|const_cast
operator|<
name|UsingDirectiveDecl
operator|*
operator|>
operator|(
name|this
operator|)
operator|->
name|getNominatedNamespace
argument_list|()
return|;
block|}
comment|/// \brief Returns the common ancestor context of this using-directive and
comment|/// its nominated namespace.
name|DeclContext
operator|*
name|getCommonAncestor
argument_list|()
block|{
return|return
name|CommonAncestor
return|;
block|}
specifier|const
name|DeclContext
operator|*
name|getCommonAncestor
argument_list|()
specifier|const
block|{
return|return
name|CommonAncestor
return|;
block|}
comment|/// \brief Return the location of the \c using keyword.
name|SourceLocation
name|getUsingLoc
argument_list|()
specifier|const
block|{
return|return
name|UsingLoc
return|;
block|}
comment|// FIXME: Could omit 'Key' in name.
comment|/// \brief Returns the location of the \c namespace keyword.
name|SourceLocation
name|getNamespaceKeyLocation
argument_list|()
specifier|const
block|{
return|return
name|NamespaceLoc
return|;
block|}
comment|/// \brief Returns the location of this using declaration's identifier.
name|SourceLocation
name|getIdentLocation
argument_list|()
specifier|const
block|{
return|return
name|getLocation
argument_list|()
return|;
block|}
specifier|static
name|UsingDirectiveDecl
operator|*
name|Create
argument_list|(
argument|ASTContext&C
argument_list|,
argument|DeclContext *DC
argument_list|,
argument|SourceLocation UsingLoc
argument_list|,
argument|SourceLocation NamespaceLoc
argument_list|,
argument|NestedNameSpecifierLoc QualifierLoc
argument_list|,
argument|SourceLocation IdentLoc
argument_list|,
argument|NamedDecl *Nominated
argument_list|,
argument|DeclContext *CommonAncestor
argument_list|)
block|;
specifier|static
name|UsingDirectiveDecl
operator|*
name|CreateDeserialized
argument_list|(
argument|ASTContext&C
argument_list|,
argument|unsigned ID
argument_list|)
block|;
name|SourceRange
name|getSourceRange
argument_list|()
specifier|const
name|LLVM_READONLY
block|{
return|return
name|SourceRange
argument_list|(
name|UsingLoc
argument_list|,
name|getLocation
argument_list|()
argument_list|)
return|;
block|}
specifier|static
name|bool
name|classof
argument_list|(
argument|const Decl *D
argument_list|)
block|{
return|return
name|classofKind
argument_list|(
name|D
operator|->
name|getKind
argument_list|()
argument_list|)
return|;
block|}
specifier|static
name|bool
name|classofKind
argument_list|(
argument|Kind K
argument_list|)
block|{
return|return
name|K
operator|==
name|UsingDirective
return|;
block|}
comment|// Friend for getUsingDirectiveName.
name|friend
name|class
name|DeclContext
block|;
name|friend
name|class
name|ASTDeclReader
block|; }
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// \brief Represents a C++ namespace alias.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// For example:
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \code
end_comment

begin_comment
comment|/// namespace Foo = Bar;
end_comment

begin_comment
comment|/// \endcode
end_comment

begin_decl_stmt
name|class
name|NamespaceAliasDecl
range|:
name|public
name|NamedDecl
block|{
name|virtual
name|void
name|anchor
argument_list|()
block|;
comment|/// \brief The location of the \c namespace keyword.
name|SourceLocation
name|NamespaceLoc
block|;
comment|/// \brief The location of the namespace's identifier.
comment|///
comment|/// This is accessed by TargetNameLoc.
name|SourceLocation
name|IdentLoc
block|;
comment|/// \brief The nested-name-specifier that precedes the namespace.
name|NestedNameSpecifierLoc
name|QualifierLoc
block|;
comment|/// \brief The Decl that this alias points to, either a NamespaceDecl or
comment|/// a NamespaceAliasDecl.
name|NamedDecl
operator|*
name|Namespace
block|;
name|NamespaceAliasDecl
argument_list|(
argument|DeclContext *DC
argument_list|,
argument|SourceLocation NamespaceLoc
argument_list|,
argument|SourceLocation AliasLoc
argument_list|,
argument|IdentifierInfo *Alias
argument_list|,
argument|NestedNameSpecifierLoc QualifierLoc
argument_list|,
argument|SourceLocation IdentLoc
argument_list|,
argument|NamedDecl *Namespace
argument_list|)
operator|:
name|NamedDecl
argument_list|(
name|NamespaceAlias
argument_list|,
name|DC
argument_list|,
name|AliasLoc
argument_list|,
name|Alias
argument_list|)
block|,
name|NamespaceLoc
argument_list|(
name|NamespaceLoc
argument_list|)
block|,
name|IdentLoc
argument_list|(
name|IdentLoc
argument_list|)
block|,
name|QualifierLoc
argument_list|(
name|QualifierLoc
argument_list|)
block|,
name|Namespace
argument_list|(
argument|Namespace
argument_list|)
block|{ }
name|friend
name|class
name|ASTDeclReader
block|;
name|public
operator|:
comment|/// \brief Retrieve the nested-name-specifier that qualifies the
comment|/// name of the namespace, with source-location information.
name|NestedNameSpecifierLoc
name|getQualifierLoc
argument_list|()
specifier|const
block|{
return|return
name|QualifierLoc
return|;
block|}
comment|/// \brief Retrieve the nested-name-specifier that qualifies the
comment|/// name of the namespace.
name|NestedNameSpecifier
operator|*
name|getQualifier
argument_list|()
specifier|const
block|{
return|return
name|QualifierLoc
operator|.
name|getNestedNameSpecifier
argument_list|()
return|;
block|}
comment|/// \brief Retrieve the namespace declaration aliased by this directive.
name|NamespaceDecl
operator|*
name|getNamespace
argument_list|()
block|{
if|if
condition|(
name|NamespaceAliasDecl
modifier|*
name|AD
init|=
name|dyn_cast
operator|<
name|NamespaceAliasDecl
operator|>
operator|(
name|Namespace
operator|)
condition|)
return|return
name|AD
operator|->
name|getNamespace
argument_list|()
return|;
return|return
name|cast
operator|<
name|NamespaceDecl
operator|>
operator|(
name|Namespace
operator|)
return|;
block|}
end_decl_stmt

begin_expr_stmt
specifier|const
name|NamespaceDecl
operator|*
name|getNamespace
argument_list|()
specifier|const
block|{
return|return
name|const_cast
operator|<
name|NamespaceAliasDecl
operator|*
operator|>
operator|(
name|this
operator|)
operator|->
name|getNamespace
argument_list|()
return|;
block|}
end_expr_stmt

begin_comment
comment|/// Returns the location of the alias name, i.e. 'foo' in
end_comment

begin_comment
comment|/// "namespace foo = ns::bar;".
end_comment

begin_expr_stmt
name|SourceLocation
name|getAliasLoc
argument_list|()
specifier|const
block|{
return|return
name|getLocation
argument_list|()
return|;
block|}
end_expr_stmt

begin_comment
comment|/// Returns the location of the \c namespace keyword.
end_comment

begin_expr_stmt
name|SourceLocation
name|getNamespaceLoc
argument_list|()
specifier|const
block|{
return|return
name|NamespaceLoc
return|;
block|}
end_expr_stmt

begin_comment
comment|/// Returns the location of the identifier in the named namespace.
end_comment

begin_expr_stmt
name|SourceLocation
name|getTargetNameLoc
argument_list|()
specifier|const
block|{
return|return
name|IdentLoc
return|;
block|}
end_expr_stmt

begin_comment
comment|/// \brief Retrieve the namespace that this alias refers to, which
end_comment

begin_comment
comment|/// may either be a NamespaceDecl or a NamespaceAliasDecl.
end_comment

begin_expr_stmt
name|NamedDecl
operator|*
name|getAliasedNamespace
argument_list|()
specifier|const
block|{
return|return
name|Namespace
return|;
block|}
end_expr_stmt

begin_function_decl
specifier|static
name|NamespaceAliasDecl
modifier|*
name|Create
parameter_list|(
name|ASTContext
modifier|&
name|C
parameter_list|,
name|DeclContext
modifier|*
name|DC
parameter_list|,
name|SourceLocation
name|NamespaceLoc
parameter_list|,
name|SourceLocation
name|AliasLoc
parameter_list|,
name|IdentifierInfo
modifier|*
name|Alias
parameter_list|,
name|NestedNameSpecifierLoc
name|QualifierLoc
parameter_list|,
name|SourceLocation
name|IdentLoc
parameter_list|,
name|NamedDecl
modifier|*
name|Namespace
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|NamespaceAliasDecl
modifier|*
name|CreateDeserialized
parameter_list|(
name|ASTContext
modifier|&
name|C
parameter_list|,
name|unsigned
name|ID
parameter_list|)
function_decl|;
end_function_decl

begin_expr_stmt
name|virtual
name|SourceRange
name|getSourceRange
argument_list|()
specifier|const
name|LLVM_READONLY
block|{
return|return
name|SourceRange
argument_list|(
name|NamespaceLoc
argument_list|,
name|IdentLoc
argument_list|)
return|;
block|}
end_expr_stmt

begin_function
specifier|static
name|bool
name|classof
parameter_list|(
specifier|const
name|Decl
modifier|*
name|D
parameter_list|)
block|{
return|return
name|classofKind
argument_list|(
name|D
operator|->
name|getKind
argument_list|()
argument_list|)
return|;
block|}
end_function

begin_function
specifier|static
name|bool
name|classofKind
parameter_list|(
name|Kind
name|K
parameter_list|)
block|{
return|return
name|K
operator|==
name|NamespaceAlias
return|;
block|}
end_function

begin_comment
unit|};
comment|/// \brief Represents a shadow declaration introduced into a scope by a
end_comment

begin_comment
comment|/// (resolved) using declaration.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// For example,
end_comment

begin_comment
comment|/// \code
end_comment

begin_comment
comment|/// namespace A {
end_comment

begin_comment
comment|///   void foo();
end_comment

begin_comment
comment|/// }
end_comment

begin_comment
comment|/// namespace B {
end_comment

begin_comment
comment|///   using A::foo; //<- a UsingDecl
end_comment

begin_comment
comment|///                 // Also creates a UsingShadowDecl for A::foo() in B
end_comment

begin_comment
comment|/// }
end_comment

begin_comment
comment|/// \endcode
end_comment

begin_decl_stmt
name|class
name|UsingShadowDecl
range|:
name|public
name|NamedDecl
decl_stmt|,
name|public
name|Redeclarable
decl|<
name|UsingShadowDecl
decl|>
block|{
name|virtual
name|void
name|anchor
parameter_list|()
function_decl|;
comment|/// The referenced declaration.
name|NamedDecl
modifier|*
name|Underlying
decl_stmt|;
comment|/// \brief The using declaration which introduced this decl or the next using
comment|/// shadow declaration contained in the aforementioned using declaration.
name|NamedDecl
modifier|*
name|UsingOrNextShadow
decl_stmt|;
name|friend
name|class
name|UsingDecl
decl_stmt|;
name|UsingShadowDecl
argument_list|(
argument|DeclContext *DC
argument_list|,
argument|SourceLocation Loc
argument_list|,
argument|UsingDecl *Using
argument_list|,
argument|NamedDecl *Target
argument_list|)
block|:
name|NamedDecl
argument_list|(
name|UsingShadow
argument_list|,
name|DC
argument_list|,
name|Loc
argument_list|,
name|DeclarationName
argument_list|()
argument_list|)
operator|,
name|Underlying
argument_list|(
name|Target
argument_list|)
operator|,
name|UsingOrNextShadow
argument_list|(
argument|reinterpret_cast<NamedDecl *>(Using)
argument_list|)
block|{
if|if
condition|(
name|Target
condition|)
block|{
name|setDeclName
argument_list|(
name|Target
operator|->
name|getDeclName
argument_list|()
argument_list|)
expr_stmt|;
name|IdentifierNamespace
operator|=
name|Target
operator|->
name|getIdentifierNamespace
argument_list|()
expr_stmt|;
block|}
name|setImplicit
argument_list|()
expr_stmt|;
block|}
typedef|typedef
name|Redeclarable
operator|<
name|UsingShadowDecl
operator|>
name|redeclarable_base
expr_stmt|;
name|virtual
name|UsingShadowDecl
modifier|*
name|getNextRedeclaration
parameter_list|()
block|{
return|return
name|RedeclLink
operator|.
name|getNext
argument_list|()
return|;
block|}
name|virtual
name|UsingShadowDecl
modifier|*
name|getPreviousDeclImpl
parameter_list|()
block|{
return|return
name|getPreviousDecl
argument_list|()
return|;
block|}
name|virtual
name|UsingShadowDecl
modifier|*
name|getMostRecentDeclImpl
parameter_list|()
block|{
return|return
name|getMostRecentDecl
argument_list|()
return|;
block|}
name|public
label|:
specifier|static
name|UsingShadowDecl
modifier|*
name|Create
parameter_list|(
name|ASTContext
modifier|&
name|C
parameter_list|,
name|DeclContext
modifier|*
name|DC
parameter_list|,
name|SourceLocation
name|Loc
parameter_list|,
name|UsingDecl
modifier|*
name|Using
parameter_list|,
name|NamedDecl
modifier|*
name|Target
parameter_list|)
block|{
return|return
name|new
argument_list|(
argument|C
argument_list|)
name|UsingShadowDecl
argument_list|(
name|DC
argument_list|,
name|Loc
argument_list|,
name|Using
argument_list|,
name|Target
argument_list|)
return|;
block|}
specifier|static
name|UsingShadowDecl
modifier|*
name|CreateDeserialized
parameter_list|(
name|ASTContext
modifier|&
name|C
parameter_list|,
name|unsigned
name|ID
parameter_list|)
function_decl|;
typedef|typedef
name|redeclarable_base
operator|::
name|redecl_iterator
name|redecl_iterator
expr_stmt|;
name|using
name|redeclarable_base
operator|::
name|redecls_begin
expr_stmt|;
name|using
name|redeclarable_base
operator|::
name|redecls_end
expr_stmt|;
name|using
name|redeclarable_base
operator|::
name|getPreviousDecl
expr_stmt|;
name|using
name|redeclarable_base
operator|::
name|getMostRecentDecl
expr_stmt|;
name|virtual
name|UsingShadowDecl
modifier|*
name|getCanonicalDecl
parameter_list|()
block|{
return|return
name|getFirstDecl
argument_list|()
return|;
block|}
name|virtual
specifier|const
name|UsingShadowDecl
operator|*
name|getCanonicalDecl
argument_list|()
specifier|const
block|{
return|return
name|getFirstDecl
argument_list|()
return|;
block|}
comment|/// \brief Gets the underlying declaration which has been brought into the
comment|/// local scope.
name|NamedDecl
operator|*
name|getTargetDecl
argument_list|()
specifier|const
block|{
return|return
name|Underlying
return|;
block|}
comment|/// \brief Sets the underlying declaration which has been brought into the
comment|/// local scope.
name|void
name|setTargetDecl
parameter_list|(
name|NamedDecl
modifier|*
name|ND
parameter_list|)
block|{
name|assert
argument_list|(
name|ND
operator|&&
literal|"Target decl is null!"
argument_list|)
expr_stmt|;
name|Underlying
operator|=
name|ND
expr_stmt|;
name|IdentifierNamespace
operator|=
name|ND
operator|->
name|getIdentifierNamespace
argument_list|()
expr_stmt|;
block|}
comment|/// \brief Gets the using declaration to which this declaration is tied.
name|UsingDecl
operator|*
name|getUsingDecl
argument_list|()
specifier|const
expr_stmt|;
comment|/// \brief The next using shadow declaration contained in the shadow decl
comment|/// chain of the using declaration which introduced this decl.
name|UsingShadowDecl
operator|*
name|getNextUsingShadowDecl
argument_list|()
specifier|const
block|{
return|return
name|dyn_cast_or_null
operator|<
name|UsingShadowDecl
operator|>
operator|(
name|UsingOrNextShadow
operator|)
return|;
block|}
specifier|static
name|bool
name|classof
parameter_list|(
specifier|const
name|Decl
modifier|*
name|D
parameter_list|)
block|{
return|return
name|classofKind
argument_list|(
name|D
operator|->
name|getKind
argument_list|()
argument_list|)
return|;
block|}
specifier|static
name|bool
name|classofKind
parameter_list|(
name|Kind
name|K
parameter_list|)
block|{
return|return
name|K
operator|==
name|Decl
operator|::
name|UsingShadow
return|;
block|}
name|friend
name|class
name|ASTDeclReader
decl_stmt|;
name|friend
name|class
name|ASTDeclWriter
decl_stmt|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|/// \brief Represents a C++ using-declaration.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// For example:
end_comment

begin_comment
comment|/// \code
end_comment

begin_comment
comment|///    using someNameSpace::someIdentifier;
end_comment

begin_comment
comment|/// \endcode
end_comment

begin_decl_stmt
name|class
name|UsingDecl
range|:
name|public
name|NamedDecl
block|{
name|virtual
name|void
name|anchor
argument_list|()
block|;
comment|/// \brief The source location of the 'using' keyword itself.
name|SourceLocation
name|UsingLocation
block|;
comment|/// \brief The nested-name-specifier that precedes the name.
name|NestedNameSpecifierLoc
name|QualifierLoc
block|;
comment|/// \brief Provides source/type location info for the declaration name
comment|/// embedded in the ValueDecl base class.
name|DeclarationNameLoc
name|DNLoc
block|;
comment|/// \brief The first shadow declaration of the shadow decl chain associated
comment|/// with this using declaration.
comment|///
comment|/// The bool member of the pair store whether this decl has the \c typename
comment|/// keyword.
name|llvm
operator|::
name|PointerIntPair
operator|<
name|UsingShadowDecl
operator|*
block|,
literal|1
block|,
name|bool
operator|>
name|FirstUsingShadow
block|;
name|UsingDecl
argument_list|(
argument|DeclContext *DC
argument_list|,
argument|SourceLocation UL
argument_list|,
argument|NestedNameSpecifierLoc QualifierLoc
argument_list|,
argument|const DeclarationNameInfo&NameInfo
argument_list|,
argument|bool HasTypenameKeyword
argument_list|)
operator|:
name|NamedDecl
argument_list|(
name|Using
argument_list|,
name|DC
argument_list|,
name|NameInfo
operator|.
name|getLoc
argument_list|()
argument_list|,
name|NameInfo
operator|.
name|getName
argument_list|()
argument_list|)
block|,
name|UsingLocation
argument_list|(
name|UL
argument_list|)
block|,
name|QualifierLoc
argument_list|(
name|QualifierLoc
argument_list|)
block|,
name|DNLoc
argument_list|(
name|NameInfo
operator|.
name|getInfo
argument_list|()
argument_list|)
block|,
name|FirstUsingShadow
argument_list|(
literal|0
argument_list|,
argument|HasTypenameKeyword
argument_list|)
block|{   }
name|public
operator|:
comment|/// \brief Return the source location of the 'using' keyword.
name|SourceLocation
name|getUsingLoc
argument_list|()
specifier|const
block|{
return|return
name|UsingLocation
return|;
block|}
comment|/// \brief Set the source location of the 'using' keyword.
name|void
name|setUsingLoc
argument_list|(
argument|SourceLocation L
argument_list|)
block|{
name|UsingLocation
operator|=
name|L
block|; }
comment|/// \brief Retrieve the nested-name-specifier that qualifies the name,
comment|/// with source-location information.
name|NestedNameSpecifierLoc
name|getQualifierLoc
argument_list|()
specifier|const
block|{
return|return
name|QualifierLoc
return|;
block|}
comment|/// \brief Retrieve the nested-name-specifier that qualifies the name.
name|NestedNameSpecifier
operator|*
name|getQualifier
argument_list|()
specifier|const
block|{
return|return
name|QualifierLoc
operator|.
name|getNestedNameSpecifier
argument_list|()
return|;
block|}
name|DeclarationNameInfo
name|getNameInfo
argument_list|()
specifier|const
block|{
return|return
name|DeclarationNameInfo
argument_list|(
name|getDeclName
argument_list|()
argument_list|,
name|getLocation
argument_list|()
argument_list|,
name|DNLoc
argument_list|)
return|;
block|}
comment|/// \brief Return true if it is a C++03 access declaration (no 'using').
name|bool
name|isAccessDeclaration
argument_list|()
specifier|const
block|{
return|return
name|UsingLocation
operator|.
name|isInvalid
argument_list|()
return|;
block|}
comment|/// \brief Return true if the using declaration has 'typename'.
name|bool
name|hasTypename
argument_list|()
specifier|const
block|{
return|return
name|FirstUsingShadow
operator|.
name|getInt
argument_list|()
return|;
block|}
comment|/// \brief Sets whether the using declaration has 'typename'.
name|void
name|setTypename
argument_list|(
argument|bool TN
argument_list|)
block|{
name|FirstUsingShadow
operator|.
name|setInt
argument_list|(
name|TN
argument_list|)
block|; }
comment|/// \brief Iterates through the using shadow declarations associated with
comment|/// this using declaration.
name|class
name|shadow_iterator
block|{
comment|/// \brief The current using shadow declaration.
name|UsingShadowDecl
operator|*
name|Current
block|;
name|public
operator|:
typedef|typedef
name|UsingShadowDecl
modifier|*
name|value_type
typedef|;
typedef|typedef
name|UsingShadowDecl
modifier|*
name|reference
typedef|;
end_decl_stmt

begin_typedef
typedef|typedef
name|UsingShadowDecl
modifier|*
name|pointer
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|std
operator|::
name|forward_iterator_tag
name|iterator_category
expr_stmt|;
end_typedef

begin_typedef
typedef|typedef
name|std
operator|::
name|ptrdiff_t
name|difference_type
expr_stmt|;
end_typedef

begin_expr_stmt
name|shadow_iterator
argument_list|()
operator|:
name|Current
argument_list|(
literal|0
argument_list|)
block|{ }
name|explicit
name|shadow_iterator
argument_list|(
name|UsingShadowDecl
operator|*
name|C
argument_list|)
operator|:
name|Current
argument_list|(
argument|C
argument_list|)
block|{ }
name|reference
name|operator
operator|*
operator|(
operator|)
specifier|const
block|{
return|return
name|Current
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|pointer
name|operator
operator|->
expr|(
end_expr_stmt

begin_expr_stmt
unit|)
specifier|const
block|{
return|return
name|Current
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|shadow_iterator
operator|&
name|operator
operator|++
operator|(
operator|)
block|{
name|Current
operator|=
name|Current
operator|->
name|getNextUsingShadowDecl
argument_list|()
block|;
return|return
operator|*
name|this
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|shadow_iterator
name|operator
operator|++
operator|(
name|int
operator|)
block|{
name|shadow_iterator
name|tmp
argument_list|(
operator|*
name|this
argument_list|)
block|;
operator|++
operator|(
operator|*
name|this
operator|)
block|;
return|return
name|tmp
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|friend
name|bool
name|operator
operator|==
operator|(
name|shadow_iterator
name|x
operator|,
name|shadow_iterator
name|y
operator|)
block|{
return|return
name|x
operator|.
name|Current
operator|==
name|y
operator|.
name|Current
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|friend
name|bool
name|operator
operator|!=
operator|(
name|shadow_iterator
name|x
operator|,
name|shadow_iterator
name|y
operator|)
block|{
return|return
name|x
operator|.
name|Current
operator|!=
name|y
operator|.
name|Current
return|;
block|}
end_expr_stmt

begin_expr_stmt
unit|};
name|shadow_iterator
name|shadow_begin
argument_list|()
specifier|const
block|{
return|return
name|shadow_iterator
argument_list|(
name|FirstUsingShadow
operator|.
name|getPointer
argument_list|()
argument_list|)
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|shadow_iterator
name|shadow_end
argument_list|()
specifier|const
block|{
return|return
name|shadow_iterator
argument_list|()
return|;
block|}
end_expr_stmt

begin_comment
comment|/// \brief Return the number of shadowed declarations associated with this
end_comment

begin_comment
comment|/// using declaration.
end_comment

begin_expr_stmt
name|unsigned
name|shadow_size
argument_list|()
specifier|const
block|{
return|return
name|std
operator|::
name|distance
argument_list|(
name|shadow_begin
argument_list|()
argument_list|,
name|shadow_end
argument_list|()
argument_list|)
return|;
block|}
end_expr_stmt

begin_function_decl
name|void
name|addShadowDecl
parameter_list|(
name|UsingShadowDecl
modifier|*
name|S
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|removeShadowDecl
parameter_list|(
name|UsingShadowDecl
modifier|*
name|S
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|UsingDecl
modifier|*
name|Create
parameter_list|(
name|ASTContext
modifier|&
name|C
parameter_list|,
name|DeclContext
modifier|*
name|DC
parameter_list|,
name|SourceLocation
name|UsingL
parameter_list|,
name|NestedNameSpecifierLoc
name|QualifierLoc
parameter_list|,
specifier|const
name|DeclarationNameInfo
modifier|&
name|NameInfo
parameter_list|,
name|bool
name|HasTypenameKeyword
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|UsingDecl
modifier|*
name|CreateDeserialized
parameter_list|(
name|ASTContext
modifier|&
name|C
parameter_list|,
name|unsigned
name|ID
parameter_list|)
function_decl|;
end_function_decl

begin_expr_stmt
name|SourceRange
name|getSourceRange
argument_list|()
specifier|const
name|LLVM_READONLY
expr_stmt|;
end_expr_stmt

begin_function
specifier|static
name|bool
name|classof
parameter_list|(
specifier|const
name|Decl
modifier|*
name|D
parameter_list|)
block|{
return|return
name|classofKind
argument_list|(
name|D
operator|->
name|getKind
argument_list|()
argument_list|)
return|;
block|}
end_function

begin_function
specifier|static
name|bool
name|classofKind
parameter_list|(
name|Kind
name|K
parameter_list|)
block|{
return|return
name|K
operator|==
name|Using
return|;
block|}
end_function

begin_decl_stmt
name|friend
name|class
name|ASTDeclReader
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|friend
name|class
name|ASTDeclWriter
decl_stmt|;
end_decl_stmt

begin_comment
unit|};
comment|/// \brief Represents a dependent using declaration which was not marked with
end_comment

begin_comment
comment|/// \c typename.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Unlike non-dependent using declarations, these *only* bring through
end_comment

begin_comment
comment|/// non-types; otherwise they would break two-phase lookup.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \code
end_comment

begin_comment
comment|/// template \<class T> class A : public Base<T> {
end_comment

begin_comment
comment|///   using Base<T>::foo;
end_comment

begin_comment
comment|/// };
end_comment

begin_comment
comment|/// \endcode
end_comment

begin_decl_stmt
name|class
name|UnresolvedUsingValueDecl
range|:
name|public
name|ValueDecl
block|{
name|virtual
name|void
name|anchor
argument_list|()
block|;
comment|/// \brief The source location of the 'using' keyword
name|SourceLocation
name|UsingLocation
block|;
comment|/// \brief The nested-name-specifier that precedes the name.
name|NestedNameSpecifierLoc
name|QualifierLoc
block|;
comment|/// \brief Provides source/type location info for the declaration name
comment|/// embedded in the ValueDecl base class.
name|DeclarationNameLoc
name|DNLoc
block|;
name|UnresolvedUsingValueDecl
argument_list|(
argument|DeclContext *DC
argument_list|,
argument|QualType Ty
argument_list|,
argument|SourceLocation UsingLoc
argument_list|,
argument|NestedNameSpecifierLoc QualifierLoc
argument_list|,
argument|const DeclarationNameInfo&NameInfo
argument_list|)
operator|:
name|ValueDecl
argument_list|(
name|UnresolvedUsingValue
argument_list|,
name|DC
argument_list|,
name|NameInfo
operator|.
name|getLoc
argument_list|()
argument_list|,
name|NameInfo
operator|.
name|getName
argument_list|()
argument_list|,
name|Ty
argument_list|)
block|,
name|UsingLocation
argument_list|(
name|UsingLoc
argument_list|)
block|,
name|QualifierLoc
argument_list|(
name|QualifierLoc
argument_list|)
block|,
name|DNLoc
argument_list|(
argument|NameInfo.getInfo()
argument_list|)
block|{ }
name|public
operator|:
comment|/// \brief Returns the source location of the 'using' keyword.
name|SourceLocation
name|getUsingLoc
argument_list|()
specifier|const
block|{
return|return
name|UsingLocation
return|;
block|}
comment|/// \brief Set the source location of the 'using' keyword.
name|void
name|setUsingLoc
argument_list|(
argument|SourceLocation L
argument_list|)
block|{
name|UsingLocation
operator|=
name|L
block|; }
comment|/// \brief Return true if it is a C++03 access declaration (no 'using').
name|bool
name|isAccessDeclaration
argument_list|()
specifier|const
block|{
return|return
name|UsingLocation
operator|.
name|isInvalid
argument_list|()
return|;
block|}
comment|/// \brief Retrieve the nested-name-specifier that qualifies the name,
comment|/// with source-location information.
name|NestedNameSpecifierLoc
name|getQualifierLoc
argument_list|()
specifier|const
block|{
return|return
name|QualifierLoc
return|;
block|}
comment|/// \brief Retrieve the nested-name-specifier that qualifies the name.
name|NestedNameSpecifier
operator|*
name|getQualifier
argument_list|()
specifier|const
block|{
return|return
name|QualifierLoc
operator|.
name|getNestedNameSpecifier
argument_list|()
return|;
block|}
name|DeclarationNameInfo
name|getNameInfo
argument_list|()
specifier|const
block|{
return|return
name|DeclarationNameInfo
argument_list|(
name|getDeclName
argument_list|()
argument_list|,
name|getLocation
argument_list|()
argument_list|,
name|DNLoc
argument_list|)
return|;
block|}
specifier|static
name|UnresolvedUsingValueDecl
operator|*
name|Create
argument_list|(
argument|ASTContext&C
argument_list|,
argument|DeclContext *DC
argument_list|,
argument|SourceLocation UsingLoc
argument_list|,
argument|NestedNameSpecifierLoc QualifierLoc
argument_list|,
argument|const DeclarationNameInfo&NameInfo
argument_list|)
block|;
specifier|static
name|UnresolvedUsingValueDecl
operator|*
name|CreateDeserialized
argument_list|(
argument|ASTContext&C
argument_list|,
argument|unsigned ID
argument_list|)
block|;
name|SourceRange
name|getSourceRange
argument_list|()
specifier|const
name|LLVM_READONLY
block|;
specifier|static
name|bool
name|classof
argument_list|(
argument|const Decl *D
argument_list|)
block|{
return|return
name|classofKind
argument_list|(
name|D
operator|->
name|getKind
argument_list|()
argument_list|)
return|;
block|}
specifier|static
name|bool
name|classofKind
argument_list|(
argument|Kind K
argument_list|)
block|{
return|return
name|K
operator|==
name|UnresolvedUsingValue
return|;
block|}
name|friend
name|class
name|ASTDeclReader
block|;
name|friend
name|class
name|ASTDeclWriter
block|; }
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// \brief Represents a dependent using declaration which was marked with
end_comment

begin_comment
comment|/// \c typename.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \code
end_comment

begin_comment
comment|/// template \<class T> class A : public Base<T> {
end_comment

begin_comment
comment|///   using typename Base<T>::foo;
end_comment

begin_comment
comment|/// };
end_comment

begin_comment
comment|/// \endcode
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// The type associated with an unresolved using typename decl is
end_comment

begin_comment
comment|/// currently always a typename type.
end_comment

begin_decl_stmt
name|class
name|UnresolvedUsingTypenameDecl
range|:
name|public
name|TypeDecl
block|{
name|virtual
name|void
name|anchor
argument_list|()
block|;
comment|/// \brief The source location of the 'typename' keyword
name|SourceLocation
name|TypenameLocation
block|;
comment|/// \brief The nested-name-specifier that precedes the name.
name|NestedNameSpecifierLoc
name|QualifierLoc
block|;
name|UnresolvedUsingTypenameDecl
argument_list|(
argument|DeclContext *DC
argument_list|,
argument|SourceLocation UsingLoc
argument_list|,
argument|SourceLocation TypenameLoc
argument_list|,
argument|NestedNameSpecifierLoc QualifierLoc
argument_list|,
argument|SourceLocation TargetNameLoc
argument_list|,
argument|IdentifierInfo *TargetName
argument_list|)
operator|:
name|TypeDecl
argument_list|(
name|UnresolvedUsingTypename
argument_list|,
name|DC
argument_list|,
name|TargetNameLoc
argument_list|,
name|TargetName
argument_list|,
name|UsingLoc
argument_list|)
block|,
name|TypenameLocation
argument_list|(
name|TypenameLoc
argument_list|)
block|,
name|QualifierLoc
argument_list|(
argument|QualifierLoc
argument_list|)
block|{ }
name|friend
name|class
name|ASTDeclReader
block|;
name|public
operator|:
comment|/// \brief Returns the source location of the 'using' keyword.
name|SourceLocation
name|getUsingLoc
argument_list|()
specifier|const
block|{
return|return
name|getLocStart
argument_list|()
return|;
block|}
comment|/// \brief Returns the source location of the 'typename' keyword.
name|SourceLocation
name|getTypenameLoc
argument_list|()
specifier|const
block|{
return|return
name|TypenameLocation
return|;
block|}
comment|/// \brief Retrieve the nested-name-specifier that qualifies the name,
comment|/// with source-location information.
name|NestedNameSpecifierLoc
name|getQualifierLoc
argument_list|()
specifier|const
block|{
return|return
name|QualifierLoc
return|;
block|}
comment|/// \brief Retrieve the nested-name-specifier that qualifies the name.
name|NestedNameSpecifier
operator|*
name|getQualifier
argument_list|()
specifier|const
block|{
return|return
name|QualifierLoc
operator|.
name|getNestedNameSpecifier
argument_list|()
return|;
block|}
specifier|static
name|UnresolvedUsingTypenameDecl
operator|*
name|Create
argument_list|(
argument|ASTContext&C
argument_list|,
argument|DeclContext *DC
argument_list|,
argument|SourceLocation UsingLoc
argument_list|,
argument|SourceLocation TypenameLoc
argument_list|,
argument|NestedNameSpecifierLoc QualifierLoc
argument_list|,
argument|SourceLocation TargetNameLoc
argument_list|,
argument|DeclarationName TargetName
argument_list|)
block|;
specifier|static
name|UnresolvedUsingTypenameDecl
operator|*
name|CreateDeserialized
argument_list|(
argument|ASTContext&C
argument_list|,
argument|unsigned ID
argument_list|)
block|;
specifier|static
name|bool
name|classof
argument_list|(
argument|const Decl *D
argument_list|)
block|{
return|return
name|classofKind
argument_list|(
name|D
operator|->
name|getKind
argument_list|()
argument_list|)
return|;
block|}
specifier|static
name|bool
name|classofKind
argument_list|(
argument|Kind K
argument_list|)
block|{
return|return
name|K
operator|==
name|UnresolvedUsingTypename
return|;
block|}
expr|}
block|;
comment|/// \brief Represents a C++11 static_assert declaration.
name|class
name|StaticAssertDecl
operator|:
name|public
name|Decl
block|{
name|virtual
name|void
name|anchor
argument_list|()
block|;
name|llvm
operator|::
name|PointerIntPair
operator|<
name|Expr
operator|*
block|,
literal|1
block|,
name|bool
operator|>
name|AssertExprAndFailed
block|;
name|StringLiteral
operator|*
name|Message
block|;
name|SourceLocation
name|RParenLoc
block|;
name|StaticAssertDecl
argument_list|(
argument|DeclContext *DC
argument_list|,
argument|SourceLocation StaticAssertLoc
argument_list|,
argument|Expr *AssertExpr
argument_list|,
argument|StringLiteral *Message
argument_list|,
argument|SourceLocation RParenLoc
argument_list|,
argument|bool Failed
argument_list|)
operator|:
name|Decl
argument_list|(
name|StaticAssert
argument_list|,
name|DC
argument_list|,
name|StaticAssertLoc
argument_list|)
block|,
name|AssertExprAndFailed
argument_list|(
name|AssertExpr
argument_list|,
name|Failed
argument_list|)
block|,
name|Message
argument_list|(
name|Message
argument_list|)
block|,
name|RParenLoc
argument_list|(
argument|RParenLoc
argument_list|)
block|{ }
name|public
operator|:
specifier|static
name|StaticAssertDecl
operator|*
name|Create
argument_list|(
argument|ASTContext&C
argument_list|,
argument|DeclContext *DC
argument_list|,
argument|SourceLocation StaticAssertLoc
argument_list|,
argument|Expr *AssertExpr
argument_list|,
argument|StringLiteral *Message
argument_list|,
argument|SourceLocation RParenLoc
argument_list|,
argument|bool Failed
argument_list|)
block|;
specifier|static
name|StaticAssertDecl
operator|*
name|CreateDeserialized
argument_list|(
argument|ASTContext&C
argument_list|,
argument|unsigned ID
argument_list|)
block|;
name|Expr
operator|*
name|getAssertExpr
argument_list|()
block|{
return|return
name|AssertExprAndFailed
operator|.
name|getPointer
argument_list|()
return|;
block|}
specifier|const
name|Expr
operator|*
name|getAssertExpr
argument_list|()
specifier|const
block|{
return|return
name|AssertExprAndFailed
operator|.
name|getPointer
argument_list|()
return|;
block|}
name|StringLiteral
operator|*
name|getMessage
argument_list|()
block|{
return|return
name|Message
return|;
block|}
specifier|const
name|StringLiteral
operator|*
name|getMessage
argument_list|()
specifier|const
block|{
return|return
name|Message
return|;
block|}
name|bool
name|isFailed
argument_list|()
specifier|const
block|{
return|return
name|AssertExprAndFailed
operator|.
name|getInt
argument_list|()
return|;
block|}
name|SourceLocation
name|getRParenLoc
argument_list|()
specifier|const
block|{
return|return
name|RParenLoc
return|;
block|}
name|SourceRange
name|getSourceRange
argument_list|()
specifier|const
name|LLVM_READONLY
block|{
return|return
name|SourceRange
argument_list|(
name|getLocation
argument_list|()
argument_list|,
name|getRParenLoc
argument_list|()
argument_list|)
return|;
block|}
specifier|static
name|bool
name|classof
argument_list|(
argument|const Decl *D
argument_list|)
block|{
return|return
name|classofKind
argument_list|(
name|D
operator|->
name|getKind
argument_list|()
argument_list|)
return|;
block|}
specifier|static
name|bool
name|classofKind
argument_list|(
argument|Kind K
argument_list|)
block|{
return|return
name|K
operator|==
name|StaticAssert
return|;
block|}
name|friend
name|class
name|ASTDeclReader
block|; }
block|;
comment|/// An instance of this class represents the declaration of a property
comment|/// member.  This is a Microsoft extension to C++, first introduced in
comment|/// Visual Studio .NET 2003 as a parallel to similar features in C#
comment|/// and Managed C++.
comment|///
comment|/// A property must always be a non-static class member.
comment|///
comment|/// A property member superficially resembles a non-static data
comment|/// member, except preceded by a property attribute:
comment|///   __declspec(property(get=GetX, put=PutX)) int x;
comment|/// Either (but not both) of the 'get' and 'put' names may be omitted.
comment|///
comment|/// A reference to a property is always an lvalue.  If the lvalue
comment|/// undergoes lvalue-to-rvalue conversion, then a getter name is
comment|/// required, and that member is called with no arguments.
comment|/// If the lvalue is assigned into, then a setter name is required,
comment|/// and that member is called with one argument, the value assigned.
comment|/// Both operations are potentially overloaded.  Compound assignments
comment|/// are permitted, as are the increment and decrement operators.
comment|///
comment|/// The getter and putter methods are permitted to be overloaded,
comment|/// although their return and parameter types are subject to certain
comment|/// restrictions according to the type of the property.
comment|///
comment|/// A property declared using an incomplete array type may
comment|/// additionally be subscripted, adding extra parameters to the getter
comment|/// and putter methods.
name|class
name|MSPropertyDecl
operator|:
name|public
name|DeclaratorDecl
block|{
name|IdentifierInfo
operator|*
name|GetterId
block|,
operator|*
name|SetterId
block|;
name|public
operator|:
name|MSPropertyDecl
argument_list|(
argument|DeclContext *DC
argument_list|,
argument|SourceLocation L
argument_list|,
argument|DeclarationName N
argument_list|,
argument|QualType T
argument_list|,
argument|TypeSourceInfo *TInfo
argument_list|,
argument|SourceLocation StartL
argument_list|,
argument|IdentifierInfo *Getter
argument_list|,
argument|IdentifierInfo *Setter
argument_list|)
operator|:
name|DeclaratorDecl
argument_list|(
name|MSProperty
argument_list|,
name|DC
argument_list|,
name|L
argument_list|,
name|N
argument_list|,
name|T
argument_list|,
name|TInfo
argument_list|,
name|StartL
argument_list|)
block|,
name|GetterId
argument_list|(
name|Getter
argument_list|)
block|,
name|SetterId
argument_list|(
argument|Setter
argument_list|)
block|{}
specifier|static
name|MSPropertyDecl
operator|*
name|CreateDeserialized
argument_list|(
argument|ASTContext&C
argument_list|,
argument|unsigned ID
argument_list|)
block|;
specifier|static
name|bool
name|classof
argument_list|(
argument|const Decl *D
argument_list|)
block|{
return|return
name|D
operator|->
name|getKind
argument_list|()
operator|==
name|MSProperty
return|;
block|}
name|bool
name|hasGetter
argument_list|()
specifier|const
block|{
return|return
name|GetterId
operator|!=
name|NULL
return|;
block|}
name|IdentifierInfo
operator|*
name|getGetterId
argument_list|()
specifier|const
block|{
return|return
name|GetterId
return|;
block|}
name|bool
name|hasSetter
argument_list|()
specifier|const
block|{
return|return
name|SetterId
operator|!=
name|NULL
return|;
block|}
name|IdentifierInfo
operator|*
name|getSetterId
argument_list|()
specifier|const
block|{
return|return
name|SetterId
return|;
block|}
name|friend
name|class
name|ASTDeclReader
block|; }
block|;
comment|/// Insertion operator for diagnostics.  This allows sending an AccessSpecifier
comment|/// into a diagnostic with<<.
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
expr|,
name|AccessSpecifier
name|AS
operator|)
block|;
specifier|const
name|PartialDiagnostic
operator|&
name|operator
operator|<<
operator|(
specifier|const
name|PartialDiagnostic
operator|&
name|DB
expr|,
name|AccessSpecifier
name|AS
operator|)
block|;  }
end_decl_stmt

begin_comment
comment|// end namespace clang
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

