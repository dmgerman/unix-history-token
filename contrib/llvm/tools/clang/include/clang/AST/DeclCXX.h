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
comment|//
end_comment

begin_comment
comment|//  This file defines the C++ Decl subclasses, other than those for
end_comment

begin_comment
comment|//  templates (in DeclTemplate.h) and friends (in DeclFriend.h).
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
file|"clang/AST/Expr.h"
end_include

begin_include
include|#
directive|include
file|"clang/AST/Decl.h"
end_include

begin_include
include|#
directive|include
file|"clang/AST/TypeLoc.h"
end_include

begin_include
include|#
directive|include
file|"clang/AST/UnresolvedSet.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/SmallVector.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/SmallPtrSet.h"
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
comment|/// Implement simplify_type for AnyFunctionDecl, so that we can dyn_cast from
comment|/// AnyFunctionDecl to any function or function template declaration.
name|template
operator|<
operator|>
expr|struct
name|simplify_type
operator|<
specifier|const
operator|::
name|clang
operator|::
name|AnyFunctionDecl
operator|>
block|{
typedef|typedef
operator|::
name|clang
operator|::
name|NamedDecl
operator|*
name|SimpleType
expr_stmt|;
specifier|static
name|SimpleType
name|getSimplifiedValue
argument_list|(
argument|const ::clang::AnyFunctionDecl&Val
argument_list|)
block|{
return|return
name|Val
return|;
block|}
block|}
empty_stmt|;
name|template
operator|<
operator|>
expr|struct
name|simplify_type
operator|<
operator|::
name|clang
operator|::
name|AnyFunctionDecl
operator|>
operator|:
name|public
name|simplify_type
operator|<
specifier|const
operator|::
name|clang
operator|::
name|AnyFunctionDecl
operator|>
block|{}
expr_stmt|;
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
comment|/// AccessSpecDecl - An access specifier followed by colon ':'.
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
comment|/// ColonLoc - The location of the ':'.
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
comment|/// getAccessSpecifierLoc - The location of the access specifier.
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
comment|/// setAccessSpecifierLoc - Sets the location of the access specifier.
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
comment|/// getColonLoc - The location of the colon following the access specifier.
name|SourceLocation
name|getColonLoc
argument_list|()
specifier|const
block|{
return|return
name|ColonLoc
return|;
block|}
comment|/// setColonLoc - Sets the location of the colon.
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
name|Create
argument_list|(
argument|ASTContext&C
argument_list|,
argument|EmptyShell Empty
argument_list|)
block|{
return|return
name|new
argument_list|(
argument|C
argument_list|)
name|AccessSpecDecl
argument_list|(
name|Empty
argument_list|)
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
name|classof
argument_list|(
argument|const AccessSpecDecl *D
argument_list|)
block|{
return|return
name|true
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
comment|/// CXXBaseSpecifier - A base class of a C++ class.
comment|///
comment|/// Each CXXBaseSpecifier represents a single, direct base class (or
comment|/// struct) of a C++ class (or struct). It specifies the type of that
comment|/// base class, whether it is a virtual or non-virtual base, and what
comment|/// level of access (public, protected, private) is used for the
comment|/// derivation. For example:
comment|///
comment|/// @code
comment|///   class A { };
comment|///   class B { };
comment|///   class C : public virtual A, protected B { };
comment|/// @endcode
comment|///
comment|/// In this code, C will have two CXXBaseSpecifiers, one for "public
comment|/// virtual A" and the other for "protected B".
name|class
name|CXXBaseSpecifier
block|{
comment|/// Range - The source code range that covers the full base
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
comment|/// Virtual - Whether this is a virtual base class or not.
name|bool
name|Virtual
operator|:
literal|1
block|;
comment|/// BaseOfClass - Whether this is the base of a class (true) or of a
comment|/// struct (false). This determines the mapping from the access
comment|/// specifier as written in the source code to the access specifier
comment|/// used for semantic analysis.
name|bool
name|BaseOfClass
operator|:
literal|1
block|;
comment|/// Access - Access specifier as written in the source code (which
comment|/// may be AS_none). The actual type of data stored here is an
comment|/// AccessSpecifier, but we use "unsigned" here to work around a
comment|/// VC++ bug.
name|unsigned
name|Access
operator|:
literal|2
block|;
comment|/// InheritConstructors - Whether the class contains a using declaration
comment|/// to inherit the named class's constructors.
name|bool
name|InheritConstructors
operator|:
literal|1
block|;
comment|/// BaseTypeInfo - The type of the base class. This will be a class or struct
comment|/// (or a typedef of such). The source code range does not include the
comment|/// "virtual" or access specifier.
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
comment|/// getSourceRange - Retrieves the source range that contains the
comment|/// entire base specifier.
name|SourceRange
name|getSourceRange
argument_list|()
specifier|const
block|{
return|return
name|Range
return|;
block|}
comment|/// isVirtual - Determines whether the base class is a virtual base
comment|/// class (or not).
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
comment|/// getAccessSpecifier - Returns the access specifier for this base
comment|/// specifier. This is the actual base specifier as used for
comment|/// semantic analysis, so the result can never be AS_none. To
comment|/// retrieve the access specifier as written in the source code, use
comment|/// getAccessSpecifierAsWritten().
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
comment|/// getAccessSpecifierAsWritten - Retrieves the access specifier as
comment|/// written in the source code (which may mean that no access
comment|/// specifier was explicitly written). Use getAccessSpecifier() to
comment|/// retrieve the access specifier for use in semantic analysis.
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
comment|/// getType - Retrieves the type of the base class. This type will
comment|/// always be an unqualified class type.
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
return|;
block|}
comment|/// getTypeLoc - Retrieves the type and source location of the base class.
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
comment|/// CXXRecordDecl - Represents a C++ struct/union/class.
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
comment|/// UserDeclaredConstructor - True when this class has a
comment|/// user-declared constructor.
name|bool
name|UserDeclaredConstructor
operator|:
literal|1
block|;
comment|/// UserDeclaredCopyConstructor - True when this class has a
comment|/// user-declared copy constructor.
name|bool
name|UserDeclaredCopyConstructor
operator|:
literal|1
block|;
comment|/// UserDeclaredCopyAssignment - True when this class has a
comment|/// user-declared copy assignment operator.
name|bool
name|UserDeclaredCopyAssignment
operator|:
literal|1
block|;
comment|/// UserDeclaredDestructor - True when this class has a
comment|/// user-declared destructor.
name|bool
name|UserDeclaredDestructor
operator|:
literal|1
block|;
comment|/// Aggregate - True when this class is an aggregate.
name|bool
name|Aggregate
operator|:
literal|1
block|;
comment|/// PlainOldData - True when this class is a POD-type.
name|bool
name|PlainOldData
operator|:
literal|1
block|;
comment|/// Empty - true when this class is empty for traits purposes,
comment|/// i.e. has no data members other than 0-width bit-fields, has no
comment|/// virtual function/base, and doesn't inherit from a non-empty
comment|/// class. Doesn't take union-ness into account.
name|bool
name|Empty
operator|:
literal|1
block|;
comment|/// Polymorphic - True when this class is polymorphic, i.e. has at
comment|/// least one virtual member or derives from a polymorphic class.
name|bool
name|Polymorphic
operator|:
literal|1
block|;
comment|/// Abstract - True when this class is abstract, i.e. has at least
comment|/// one pure virtual function, (that can come from a base class).
name|bool
name|Abstract
operator|:
literal|1
block|;
comment|/// HasTrivialConstructor - True when this class has a trivial constructor.
comment|///
comment|/// C++ [class.ctor]p5.  A constructor is trivial if it is an
comment|/// implicitly-declared default constructor and if:
comment|/// * its class has no virtual functions and no virtual base classes, and
comment|/// * all the direct base classes of its class have trivial constructors, and
comment|/// * for all the nonstatic data members of its class that are of class type
comment|///   (or array thereof), each such class has a trivial constructor.
name|bool
name|HasTrivialConstructor
operator|:
literal|1
block|;
comment|/// HasTrivialCopyConstructor - True when this class has a trivial copy
comment|/// constructor.
comment|///
comment|/// C++ [class.copy]p6.  A copy constructor for class X is trivial
comment|/// if it is implicitly declared and if
comment|/// * class X has no virtual functions and no virtual base classes, and
comment|/// * each direct base class of X has a trivial copy constructor, and
comment|/// * for all the nonstatic data members of X that are of class type (or
comment|///   array thereof), each such class type has a trivial copy constructor;
comment|/// otherwise the copy constructor is non-trivial.
name|bool
name|HasTrivialCopyConstructor
operator|:
literal|1
block|;
comment|/// HasTrivialCopyAssignment - True when this class has a trivial copy
comment|/// assignment operator.
comment|///
comment|/// C++ [class.copy]p11.  A copy assignment operator for class X is
comment|/// trivial if it is implicitly declared and if
comment|/// * class X has no virtual functions and no virtual base classes, and
comment|/// * each direct base class of X has a trivial copy assignment operator, and
comment|/// * for all the nonstatic data members of X that are of class type (or
comment|///   array thereof), each such class type has a trivial copy assignment
comment|///   operator;
comment|/// otherwise the copy assignment operator is non-trivial.
name|bool
name|HasTrivialCopyAssignment
operator|:
literal|1
block|;
comment|/// HasTrivialDestructor - True when this class has a trivial destructor.
comment|///
comment|/// C++ [class.dtor]p3.  A destructor is trivial if it is an
comment|/// implicitly-declared destructor and if:
comment|/// * all of the direct base classes of its class have trivial destructors
comment|///   and
comment|/// * for all of the non-static data members of its class that are of class
comment|///   type (or array thereof), each such class has a trivial destructor.
name|bool
name|HasTrivialDestructor
operator|:
literal|1
block|;
comment|/// ComputedVisibleConversions - True when visible conversion functions are
comment|/// already computed and are available.
name|bool
name|ComputedVisibleConversions
operator|:
literal|1
block|;
comment|/// \brief Whether we have already declared the default constructor or
comment|/// do not need to have one declared.
name|bool
name|DeclaredDefaultConstructor
operator|:
literal|1
block|;
comment|/// \brief Whether we have already declared the copy constructor.
name|bool
name|DeclaredCopyConstructor
operator|:
literal|1
block|;
comment|/// \brief Whether we have already declared the copy-assignment operator.
name|bool
name|DeclaredCopyAssignment
operator|:
literal|1
block|;
comment|/// \brief Whether we have already declared a destructor within the class.
name|bool
name|DeclaredDestructor
operator|:
literal|1
block|;
comment|/// NumBases - The number of base class specifiers in Bases.
name|unsigned
name|NumBases
block|;
comment|/// NumVBases - The number of virtual base class specifiers in VBases.
name|unsigned
name|NumVBases
block|;
comment|/// Bases - Base classes of this class.
comment|/// FIXME: This is wasted space for a union.
name|LazyCXXBaseSpecifiersPtr
name|Bases
block|;
comment|/// VBases - direct and indirect virtual base classes of this class.
name|LazyCXXBaseSpecifiersPtr
name|VBases
block|;
comment|/// Conversions - Overload set containing the conversion functions
comment|/// of this C++ class (but not its inherited conversion
comment|/// functions). Each of the entries in this overload set is a
comment|/// CXXConversionDecl.
name|UnresolvedSet
operator|<
literal|4
operator|>
name|Conversions
block|;
comment|/// VisibleConversions - Overload set containing the conversion
comment|/// functions of this C++ class and all those inherited conversion
comment|/// functions that are visible in this class. Each of the entries
comment|/// in this overload set is a CXXConversionDecl or a
comment|/// FunctionTemplateDecl.
name|UnresolvedSet
operator|<
literal|4
operator|>
name|VisibleConversions
block|;
comment|/// Definition - The declaration which defines this record.
name|CXXRecordDecl
operator|*
name|Definition
block|;
comment|/// FirstFriend - The first friend declaration in this class, or
comment|/// null if there aren't any.  This is actually currently stored
comment|/// in reverse order.
name|FriendDecl
operator|*
name|FirstFriend
block|;
comment|/// \brief Retrieve the set of direct base classes.
name|CXXBaseSpecifier
operator|*
name|getBases
argument_list|()
specifier|const
block|{
return|return
name|Bases
operator|.
name|get
argument_list|(
name|Definition
operator|->
name|getASTContext
argument_list|()
operator|.
name|getExternalSource
argument_list|()
argument_list|)
return|;
block|}
comment|/// \brief Retrieve the set of virtual base classes.
name|CXXBaseSpecifier
operator|*
name|getVBases
argument_list|()
specifier|const
block|{
return|return
name|VBases
operator|.
name|get
argument_list|(
name|Definition
operator|->
name|getASTContext
argument_list|()
operator|.
name|getExternalSource
argument_list|()
argument_list|)
return|;
block|}
expr|}
operator|*
name|DefinitionData
block|;    struct
name|DefinitionData
operator|&
name|data
argument_list|()
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
comment|/// \brief The template or declaration that this declaration
comment|/// describes or was instantiated from, respectively.
comment|///
comment|/// For non-templates, this value will be NULL. For record
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
block|,
name|MemberSpecializationInfo
operator|*
operator|>
name|TemplateOrInstantiation
block|;
name|friend
name|class
name|DeclContext
block|;
comment|/// \brief Notify the class that member has been added.
comment|///
comment|/// This routine helps maintain information about the class based on which
comment|/// members have been added. It will be invoked by DeclContext::addDecl()
comment|/// whenever a member is added to this record.
name|void
name|addedMember
argument_list|(
name|Decl
operator|*
name|D
argument_list|)
block|;
name|void
name|markedVirtualFunctionPure
argument_list|()
block|;
name|friend
name|void
name|FunctionDecl
operator|::
name|setPure
argument_list|(
name|bool
argument_list|)
block|;
name|protected
operator|:
name|CXXRecordDecl
argument_list|(
argument|Kind K
argument_list|,
argument|TagKind TK
argument_list|,
argument|DeclContext *DC
argument_list|,
argument|SourceLocation L
argument_list|,
argument|IdentifierInfo *Id
argument_list|,
argument|CXXRecordDecl *PrevDecl
argument_list|,
argument|SourceLocation TKL = SourceLocation()
argument_list|)
block|;
name|public
operator|:
comment|/// base_class_iterator - Iterator that traverses the base classes
comment|/// of a class.
typedef|typedef
name|CXXBaseSpecifier
modifier|*
name|base_class_iterator
typedef|;
comment|/// base_class_const_iterator - Iterator that traverses the base
comment|/// classes of a class.
typedef|typedef
specifier|const
name|CXXBaseSpecifier
modifier|*
name|base_class_const_iterator
typedef|;
comment|/// reverse_base_class_iterator = Iterator that traverses the base classes
comment|/// of a class in reverse order.
typedef|typedef
name|std
operator|::
name|reverse_iterator
operator|<
name|base_class_iterator
operator|>
name|reverse_base_class_iterator
expr_stmt|;
comment|/// reverse_base_class_iterator = Iterator that traverses the base classes
comment|/// of a class in reverse order.
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
operator|*
name|getCanonicalDecl
argument_list|()
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
specifier|const
name|CXXRecordDecl
operator|*
name|getPreviousDeclaration
argument_list|()
specifier|const
block|{
return|return
name|cast_or_null
operator|<
name|CXXRecordDecl
operator|>
operator|(
name|RecordDecl
operator|::
name|getPreviousDeclaration
argument_list|()
operator|)
return|;
block|}
name|CXXRecordDecl
operator|*
name|getPreviousDeclaration
argument_list|()
block|{
return|return
name|cast_or_null
operator|<
name|CXXRecordDecl
operator|>
operator|(
name|RecordDecl
operator|::
name|getPreviousDeclaration
argument_list|()
operator|)
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
name|L
parameter_list|,
name|IdentifierInfo
modifier|*
name|Id
parameter_list|,
name|SourceLocation
name|TKL
init|=
name|SourceLocation
argument_list|()
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
name|Create
parameter_list|(
specifier|const
name|ASTContext
modifier|&
name|C
parameter_list|,
name|EmptyShell
name|Empty
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
comment|/// setBases - Sets the base classes of this struct or class.
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
comment|/// getNumBases - Retrieves the number of base classes of this
end_comment

begin_comment
comment|/// class.
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
comment|/// getNumVBases - Retrieves the number of virtual base classes of this
end_comment

begin_comment
comment|/// class.
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
comment|/// \brief Determine whether this class has any dependent base classes.
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
comment|/// method_begin - Method begin iterator.  Iterates in the order the methods
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
comment|/// method_end - Method end iterator.
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
operator|!=
literal|0
return|;
block|}
end_expr_stmt

begin_comment
comment|/// \brief Determine whether this class has had its default constructor
end_comment

begin_comment
comment|/// declared implicitly or does not need one declared implicitly.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This value is used for lazy creation of default constructors.
end_comment

begin_expr_stmt
name|bool
name|hasDeclaredDefaultConstructor
argument_list|()
specifier|const
block|{
return|return
name|data
argument_list|()
operator|.
name|DeclaredDefaultConstructor
return|;
block|}
end_expr_stmt

begin_comment
comment|/// hasConstCopyConstructor - Determines whether this class has a
end_comment

begin_comment
comment|/// copy constructor that accepts a const-qualified argument.
end_comment

begin_decl_stmt
name|bool
name|hasConstCopyConstructor
argument_list|(
specifier|const
name|ASTContext
operator|&
name|Context
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// getCopyConstructor - Returns the copy constructor for this class
end_comment

begin_decl_stmt
name|CXXConstructorDecl
modifier|*
name|getCopyConstructor
argument_list|(
specifier|const
name|ASTContext
operator|&
name|Context
argument_list|,
name|unsigned
name|TypeQuals
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// \brief Retrieve the copy-assignment operator for this class, if available.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This routine attempts to find the copy-assignment operator for this
end_comment

begin_comment
comment|/// class, using a simplistic form of overload resolution.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param ArgIsConst Whether the argument to the copy-assignment operator
end_comment

begin_comment
comment|/// is const-qualified.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \returns The copy-assignment operator that can be invoked, or NULL if
end_comment

begin_comment
comment|/// a unique copy-assignment operator could not be found.
end_comment

begin_decl_stmt
name|CXXMethodDecl
modifier|*
name|getCopyAssignmentOperator
argument_list|(
name|bool
name|ArgIsConst
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// hasUserDeclaredConstructor - Whether this class has any
end_comment

begin_comment
comment|/// user-declared constructors. When true, a default constructor
end_comment

begin_comment
comment|/// will not be implicitly declared.
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
comment|/// hasUserDeclaredCopyConstructor - Whether this class has a
end_comment

begin_comment
comment|/// user-declared copy constructor. When false, a copy constructor
end_comment

begin_comment
comment|/// will be implicitly declared.
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
name|UserDeclaredCopyConstructor
return|;
block|}
end_expr_stmt

begin_comment
comment|/// \brief Determine whether this class has had its copy constructor
end_comment

begin_comment
comment|/// declared, either via the user or via an implicit declaration.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This value is used for lazy creation of copy constructors.
end_comment

begin_expr_stmt
name|bool
name|hasDeclaredCopyConstructor
argument_list|()
specifier|const
block|{
return|return
name|data
argument_list|()
operator|.
name|DeclaredCopyConstructor
return|;
block|}
end_expr_stmt

begin_comment
comment|/// hasUserDeclaredCopyAssignment - Whether this class has a
end_comment

begin_comment
comment|/// user-declared copy assignment operator. When false, a copy
end_comment

begin_comment
comment|/// assigment operator will be implicitly declared.
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
name|UserDeclaredCopyAssignment
return|;
block|}
end_expr_stmt

begin_comment
comment|/// \brief Determine whether this class has had its copy assignment operator
end_comment

begin_comment
comment|/// declared, either via the user or via an implicit declaration.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This value is used for lazy creation of copy assignment operators.
end_comment

begin_expr_stmt
name|bool
name|hasDeclaredCopyAssignment
argument_list|()
specifier|const
block|{
return|return
name|data
argument_list|()
operator|.
name|DeclaredCopyAssignment
return|;
block|}
end_expr_stmt

begin_comment
comment|/// hasUserDeclaredDestructor - Whether this class has a
end_comment

begin_comment
comment|/// user-declared destructor. When false, a destructor will be
end_comment

begin_comment
comment|/// implicitly declared.
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
name|UserDeclaredDestructor
return|;
block|}
end_expr_stmt

begin_comment
comment|/// \brief Determine whether this class has had its destructor declared,
end_comment

begin_comment
comment|/// either via the user or via an implicit declaration.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This value is used for lazy creation of destructors.
end_comment

begin_expr_stmt
name|bool
name|hasDeclaredDestructor
argument_list|()
specifier|const
block|{
return|return
name|data
argument_list|()
operator|.
name|DeclaredDestructor
return|;
block|}
end_expr_stmt

begin_comment
comment|/// getConversions - Retrieve the overload set containing all of the
end_comment

begin_comment
comment|/// conversion functions in this class.
end_comment

begin_function
name|UnresolvedSetImpl
modifier|*
name|getConversionFunctions
parameter_list|()
block|{
return|return
operator|&
name|data
argument_list|()
operator|.
name|Conversions
return|;
block|}
end_function

begin_expr_stmt
specifier|const
name|UnresolvedSetImpl
operator|*
name|getConversionFunctions
argument_list|()
specifier|const
block|{
return|return
operator|&
name|data
argument_list|()
operator|.
name|Conversions
return|;
block|}
end_expr_stmt

begin_typedef
typedef|typedef
name|UnresolvedSetImpl
operator|::
name|iterator
name|conversion_iterator
expr_stmt|;
end_typedef

begin_expr_stmt
name|conversion_iterator
name|conversion_begin
argument_list|()
specifier|const
block|{
return|return
name|getConversionFunctions
argument_list|()
operator|->
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
name|getConversionFunctions
argument_list|()
operator|->
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
comment|/// getVisibleConversionFunctions - get all conversion functions visible
end_comment

begin_comment
comment|/// in current class; including conversion function templates.
end_comment

begin_function_decl
specifier|const
name|UnresolvedSetImpl
modifier|*
name|getVisibleConversionFunctions
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/// isAggregate - Whether this class is an aggregate (C++
end_comment

begin_comment
comment|/// [dcl.init.aggr]), which is a class with no user-declared
end_comment

begin_comment
comment|/// constructors, no private or protected non-static data members,
end_comment

begin_comment
comment|/// no base classes, and no virtual functions (C++ [dcl.init.aggr]p1).
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
comment|/// isPOD - Whether this class is a POD-type (C++ [class]p4), which is a class
end_comment

begin_comment
comment|/// that is an aggregate that has no non-static non-POD data members, no
end_comment

begin_comment
comment|/// reference data members, no user-defined copy assignment operator and no
end_comment

begin_comment
comment|/// user-defined destructor.
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
comment|/// isEmpty - Whether this class is empty (C++0x [meta.unary.prop]), which
end_comment

begin_comment
comment|/// means it has a virtual function, virtual base, data member (other than
end_comment

begin_comment
comment|/// 0-width bit-field) or inherits from a non-empty class. Does NOT include
end_comment

begin_comment
comment|/// a check for union-ness.
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
comment|/// isPolymorphic - Whether this class is polymorphic (C++ [class.virtual]),
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
comment|/// isAbstract - Whether this class is abstract (C++ [class.abstract]),
end_comment

begin_comment
comment|/// which means that the class contains or inherits a pure virtual function.
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
comment|// hasTrivialConstructor - Whether this class has a trivial constructor
end_comment

begin_comment
comment|// (C++ [class.ctor]p5)
end_comment

begin_expr_stmt
name|bool
name|hasTrivialConstructor
argument_list|()
specifier|const
block|{
return|return
name|data
argument_list|()
operator|.
name|HasTrivialConstructor
return|;
block|}
end_expr_stmt

begin_comment
comment|// hasTrivialCopyConstructor - Whether this class has a trivial copy
end_comment

begin_comment
comment|// constructor (C++ [class.copy]p6)
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
name|HasTrivialCopyConstructor
return|;
block|}
end_expr_stmt

begin_comment
comment|// hasTrivialCopyAssignment - Whether this class has a trivial copy
end_comment

begin_comment
comment|// assignment operator (C++ [class.copy]p11)
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
name|HasTrivialCopyAssignment
return|;
block|}
end_expr_stmt

begin_comment
comment|// hasTrivialDestructor - Whether this class has a trivial destructor
end_comment

begin_comment
comment|// (C++ [class.dtor]p3)
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
name|HasTrivialDestructor
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
comment|/// This routine will return non-NULL for (non-templated) member
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
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// \brief Specify that this record is an instantiation of the
end_comment

begin_comment
comment|/// member class RD.
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
comment|/// getDestructor - Returns the destructor decl for this class.
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
comment|/// isLocalClass - If the class is a local class [class.local], returns
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

begin_comment
unit|}
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

begin_macro
unit|bool
name|isDerivedFrom
argument_list|(
argument|const CXXRecordDecl *Base
argument_list|)
end_macro

begin_decl_stmt
specifier|const
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
comment|/// \returns true if this class is derived from Base, false otherwise.
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
comment|/// \param Base the definition of the base class
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
comment|/// viewInheritance - Renders and displays an inheritance diagram
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
comment|/// MergeAccess - Calculates the access of a decl that is reached
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

begin_function
specifier|static
name|bool
name|classof
parameter_list|(
specifier|const
name|CXXRecordDecl
modifier|*
name|D
parameter_list|)
block|{
return|return
name|true
return|;
block|}
end_function

begin_function
specifier|static
name|bool
name|classof
parameter_list|(
specifier|const
name|ClassTemplateSpecializationDecl
modifier|*
name|D
parameter_list|)
block|{
return|return
name|true
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
comment|/// CXXMethodDecl - Represents a static or instance method of a
end_comment

begin_comment
comment|/// struct/union/class.
end_comment

begin_decl_stmt
name|class
name|CXXMethodDecl
range|:
name|public
name|FunctionDecl
block|{
name|protected
operator|:
name|CXXMethodDecl
argument_list|(
argument|Kind DK
argument_list|,
argument|CXXRecordDecl *RD
argument_list|,
argument|const DeclarationNameInfo&NameInfo
argument_list|,
argument|QualType T
argument_list|,
argument|TypeSourceInfo *TInfo
argument_list|,
argument|bool isStatic
argument_list|,
argument|StorageClass SCAsWritten
argument_list|,
argument|bool isInline
argument_list|)
operator|:
name|FunctionDecl
argument_list|(
argument|DK
argument_list|,
argument|RD
argument_list|,
argument|NameInfo
argument_list|,
argument|T
argument_list|,
argument|TInfo
argument_list|,
argument|(isStatic ? SC_Static : SC_None)
argument_list|,
argument|SCAsWritten
argument_list|,
argument|isInline
argument_list|)
block|{}
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
argument|const DeclarationNameInfo&NameInfo
argument_list|,
argument|QualType T
argument_list|,
argument|TypeSourceInfo *TInfo
argument_list|,
argument|bool isStatic = false
argument_list|,
argument|StorageClass SCAsWritten = SC_None
argument_list|,
argument|bool isInline = false
argument_list|)
block|;
name|bool
name|isStatic
argument_list|()
specifier|const
block|{
return|return
name|getStorageClass
argument_list|()
operator|==
name|SC_Static
return|;
block|}
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
if|if
condition|(
name|CD
operator|->
name|isVirtualAsWritten
argument_list|()
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

begin_expr_stmt
specifier|const
name|CXXMethodDecl
operator|*
name|getCanonicalDecl
argument_list|()
specifier|const
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
comment|/// getParent - Returns the parent of this method declaration, which
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
comment|/// getParent - Returns the parent of this method declaration, which
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
comment|/// getThisType - Returns the type of 'this' pointer.
end_comment

begin_comment
comment|/// Should only be called for instance methods.
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
comment|/// \code
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
name|classof
parameter_list|(
specifier|const
name|CXXMethodDecl
modifier|*
name|D
parameter_list|)
block|{
return|return
name|true
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
comment|/// CXXCtorInitializer - Represents a C++ base or member
end_comment

begin_comment
comment|/// initializer, which is part of a constructor initializer that
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
comment|/// @code
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
comment|/// @endcode
end_comment

begin_decl_stmt
name|class
name|CXXCtorInitializer
block|{
comment|/// \brief Either the base class name (stored as a TypeSourceInfo*), an normal
comment|/// field (FieldDecl) or an anonymous field (IndirectFieldDecl*) being
comment|/// initialized.
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
name|SourceLocation
name|MemberOrEllipsisLocation
decl_stmt|;
comment|/// \brief The argument used to initialize the base or member, which may
comment|/// end up constructing an object (when multiple arguments are involved).
name|Stmt
modifier|*
name|Init
decl_stmt|;
comment|/// LParenLoc - Location of the left paren of the ctor-initializer.
name|SourceLocation
name|LParenLoc
decl_stmt|;
comment|/// RParenLoc - Location of the right paren of the ctor-initializer.
name|SourceLocation
name|RParenLoc
decl_stmt|;
comment|/// IsVirtual - If the initializer is a base initializer, this keeps track
comment|/// of whether the base is virtual or not.
name|bool
name|IsVirtual
range|:
literal|1
decl_stmt|;
comment|/// IsWritten - Whether or not the initializer is explicitly written
comment|/// in the sources.
name|bool
name|IsWritten
range|:
literal|1
decl_stmt|;
comment|/// SourceOrderOrNumArrayIndices - If IsWritten is true, then this
comment|/// number keeps track of the textual order of this initializer in the
comment|/// original sources, counting from 0; otherwise, if IsWritten is false,
comment|/// it stores the number of array index variables stored after this
comment|/// object in memory.
name|unsigned
name|SourceOrderOrNumArrayIndices
range|:
literal|14
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
comment|/// CXXCtorInitializer - Creates a new base-class initializer.
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
comment|/// CXXCtorInitializer - Creates a new member initializer.
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
comment|/// isBaseInitializer - Returns true when this initializer is
comment|/// initializing a base class.
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
return|;
block|}
comment|/// isMemberInitializer - Returns true when this initializer is
comment|/// initializing a non-static data member.
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
comment|/// Otherwise, returns NULL.
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
comment|/// \brief Returns the declarator information for a base class initializer.
name|TypeSourceInfo
operator|*
name|getBaseClassInfo
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
comment|/// getMember - If this is a member initializer, returns the
comment|/// declaration of the non-static data member being
comment|/// initialized. Otherwise, returns NULL.
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
else|else
return|return
literal|0
return|;
block|}
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
elseif|else
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
else|else
return|return
literal|0
return|;
block|}
name|IndirectFieldDecl
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
else|else
return|return
literal|0
return|;
block|}
name|SourceLocation
name|getMemberLocation
argument_list|()
specifier|const
block|{
return|return
name|MemberOrEllipsisLocation
return|;
block|}
comment|/// \brief Determine the source location of the initializer.
name|SourceLocation
name|getSourceLocation
argument_list|()
specifier|const
expr_stmt|;
comment|/// \brief Determine the source range covering the entire initializer.
name|SourceRange
name|getSourceRange
argument_list|()
specifier|const
expr_stmt|;
comment|/// isWritten - Returns true if this initializer is explicitly written
comment|/// in the source code.
name|bool
name|isWritten
argument_list|()
specifier|const
block|{
return|return
name|IsWritten
return|;
block|}
comment|/// \brief Return the source position of the initializer, counting from 0.
comment|/// If the initializer was implicit, -1 is returned.
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
comment|/// \brief Set the source order of this initializer. This method can only
comment|/// be called once for each initializer; it cannot be called on an
comment|/// initializer having a positive number of (implicit) array indices.
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
name|SourceLocation
name|getLParenLoc
argument_list|()
specifier|const
block|{
return|return
name|LParenLoc
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
comment|/// \brief Determine the number of implicit array indices used while
comment|/// described an array member initialization.
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
comment|/// \brief Retrieve a particular array index variable used to
comment|/// describe an array member initialization.
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
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|/// CXXConstructorDecl - Represents a C++ constructor within a
end_comment

begin_comment
comment|/// class. For example:
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// @code
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
comment|/// @endcode
end_comment

begin_decl_stmt
name|class
name|CXXConstructorDecl
range|:
name|public
name|CXXMethodDecl
block|{
comment|/// IsExplicitSpecified - Whether this constructor declaration has the
comment|/// 'explicit' keyword specified.
name|bool
name|IsExplicitSpecified
operator|:
literal|1
block|;
comment|/// ImplicitlyDefined - Whether this constructor was implicitly
comment|/// defined by the compiler. When false, the constructor was defined
comment|/// by the user. In C++03, this flag will have the same value as
comment|/// Implicit. In C++0x, however, a constructor that is
comment|/// explicitly defaulted (i.e., defined with " = default") will have
comment|/// @c !Implicit&& ImplicitlyDefined.
name|bool
name|ImplicitlyDefined
operator|:
literal|1
block|;
comment|/// Support for base and member initializers.
comment|/// CtorInitializers - The arguments used to initialize the base
comment|/// or member.
name|CXXCtorInitializer
operator|*
operator|*
name|CtorInitializers
block|;
name|unsigned
name|NumCtorInitializers
block|;
name|CXXConstructorDecl
argument_list|(
argument|CXXRecordDecl *RD
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
argument_list|)
operator|:
name|CXXMethodDecl
argument_list|(
name|CXXConstructor
argument_list|,
name|RD
argument_list|,
name|NameInfo
argument_list|,
name|T
argument_list|,
name|TInfo
argument_list|,
name|false
argument_list|,
name|SC_None
argument_list|,
name|isInline
argument_list|)
block|,
name|IsExplicitSpecified
argument_list|(
name|isExplicitSpecified
argument_list|)
block|,
name|ImplicitlyDefined
argument_list|(
name|false
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
name|Create
argument_list|(
argument|ASTContext&C
argument_list|,
argument|EmptyShell Empty
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
argument_list|)
block|;
comment|/// isExplicitSpecified - Whether this constructor declaration has the
comment|/// 'explicit' keyword specified.
name|bool
name|isExplicitSpecified
argument_list|()
specifier|const
block|{
return|return
name|IsExplicitSpecified
return|;
block|}
comment|/// isExplicit - Whether this constructor was marked "explicit" or not.
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
name|getFirstDeclaration
argument_list|()
operator|)
operator|->
name|isExplicitSpecified
argument_list|()
return|;
block|}
comment|/// isImplicitlyDefined - Whether this constructor was implicitly
comment|/// defined. If false, then this constructor was defined by the
comment|/// user. This operation can only be invoked if the constructor has
comment|/// already been defined.
name|bool
name|isImplicitlyDefined
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
name|isThisDeclarationADefinition
argument_list|()
operator|&&
literal|"Can only get the implicit-definition flag once the "
literal|"constructor has been defined"
argument_list|)
block|;
return|return
name|ImplicitlyDefined
return|;
block|}
comment|/// setImplicitlyDefined - Set whether this constructor was
comment|/// implicitly defined or not.
name|void
name|setImplicitlyDefined
argument_list|(
argument|bool ID
argument_list|)
block|{
name|assert
argument_list|(
name|isThisDeclarationADefinition
argument_list|()
operator|&&
literal|"Can only set the implicit-definition flag once the constructor "
literal|"has been defined"
argument_list|)
block|;
name|ImplicitlyDefined
operator|=
name|ID
block|;   }
comment|/// init_iterator - Iterates through the member/base initializer list.
typedef|typedef
name|CXXCtorInitializer
modifier|*
modifier|*
name|init_iterator
typedef|;
end_decl_stmt

begin_comment
comment|/// init_const_iterator - Iterates through the memberbase initializer list.
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
comment|/// init_begin() - Retrieve an iterator to the first initializer.
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
comment|/// begin() - Retrieve an iterator to the first initializer.
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
comment|/// init_end() - Retrieve an iterator past the last initializer.
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
comment|/// end() - Retrieve an iterator past the last initializer.
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
comment|/// getNumArgs - Determine the number of arguments used to
end_comment

begin_comment
comment|/// initialize the member or base.
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
comment|/// isDefaultConstructor - Whether this constructor is a default
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
comment|/// isCopyConstructor - Whether this constructor is a copy
end_comment

begin_comment
comment|/// constructor (C++ [class.copy]p2, which can be used to copy the
end_comment

begin_comment
comment|/// class. @p TypeQuals will be set to the qualifiers on the
end_comment

begin_comment
comment|/// argument type. For example, @p TypeQuals would be set to @c
end_comment

begin_comment
comment|/// QualType::Const for the following copy constructor:
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// @code
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
comment|/// @endcode
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
comment|/// isCopyConstructor - Whether this constructor is a copy
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
expr_stmt|;
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
comment|/// isConvertingConstructor - Whether this constructor is a
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
name|classof
parameter_list|(
specifier|const
name|CXXConstructorDecl
modifier|*
name|D
parameter_list|)
block|{
return|return
name|true
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
comment|/// CXXDestructorDecl - Represents a C++ destructor within a
end_comment

begin_comment
comment|/// class. For example:
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// @code
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
comment|/// @endcode
end_comment

begin_decl_stmt
name|class
name|CXXDestructorDecl
range|:
name|public
name|CXXMethodDecl
block|{
comment|/// ImplicitlyDefined - Whether this destructor was implicitly
comment|/// defined by the compiler. When false, the destructor was defined
comment|/// by the user. In C++03, this flag will have the same value as
comment|/// Implicit. In C++0x, however, a destructor that is
comment|/// explicitly defaulted (i.e., defined with " = default") will have
comment|/// @c !Implicit&& ImplicitlyDefined.
name|bool
name|ImplicitlyDefined
operator|:
literal|1
block|;
name|FunctionDecl
operator|*
name|OperatorDelete
block|;
name|CXXDestructorDecl
argument_list|(
argument|CXXRecordDecl *RD
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
name|NameInfo
argument_list|,
name|T
argument_list|,
name|TInfo
argument_list|,
name|false
argument_list|,
name|SC_None
argument_list|,
name|isInline
argument_list|)
block|,
name|ImplicitlyDefined
argument_list|(
name|false
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
argument|ASTContext& C
argument_list|,
argument|EmptyShell Empty
argument_list|)
block|;
specifier|static
name|CXXDestructorDecl
operator|*
name|Create
argument_list|(
argument|ASTContext&C
argument_list|,
argument|CXXRecordDecl *RD
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
comment|/// isImplicitlyDefined - Whether this destructor was implicitly
comment|/// defined. If false, then this destructor was defined by the
comment|/// user. This operation can only be invoked if the destructor has
comment|/// already been defined.
name|bool
name|isImplicitlyDefined
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
name|isThisDeclarationADefinition
argument_list|()
operator|&&
literal|"Can only get the implicit-definition flag once the destructor has been defined"
argument_list|)
block|;
return|return
name|ImplicitlyDefined
return|;
block|}
comment|/// setImplicitlyDefined - Set whether this destructor was
comment|/// implicitly defined or not.
name|void
name|setImplicitlyDefined
argument_list|(
argument|bool ID
argument_list|)
block|{
name|assert
argument_list|(
name|isThisDeclarationADefinition
argument_list|()
operator|&&
literal|"Can only set the implicit-definition flag once the destructor has been defined"
argument_list|)
block|;
name|ImplicitlyDefined
operator|=
name|ID
block|;   }
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
name|classof
argument_list|(
argument|const CXXDestructorDecl *D
argument_list|)
block|{
return|return
name|true
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
comment|/// CXXConversionDecl - Represents a C++ conversion function within a
end_comment

begin_comment
comment|/// class. For example:
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// @code
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
comment|/// @endcode
end_comment

begin_decl_stmt
name|class
name|CXXConversionDecl
range|:
name|public
name|CXXMethodDecl
block|{
comment|/// IsExplicitSpecified - Whether this conversion function declaration is
comment|/// marked "explicit", meaning that it can only be applied when the user
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
argument|const DeclarationNameInfo&NameInfo
argument_list|,
argument|QualType T
argument_list|,
argument|TypeSourceInfo *TInfo
argument_list|,
argument|bool isInline
argument_list|,
argument|bool isExplicitSpecified
argument_list|)
operator|:
name|CXXMethodDecl
argument_list|(
name|CXXConversion
argument_list|,
name|RD
argument_list|,
name|NameInfo
argument_list|,
name|T
argument_list|,
name|TInfo
argument_list|,
name|false
argument_list|,
name|SC_None
argument_list|,
name|isInline
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
argument|EmptyShell Empty
argument_list|)
block|;
specifier|static
name|CXXConversionDecl
operator|*
name|Create
argument_list|(
argument|ASTContext&C
argument_list|,
argument|CXXRecordDecl *RD
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
argument_list|)
block|;
comment|/// IsExplicitSpecified - Whether this conversion function declaration is
comment|/// marked "explicit", meaning that it can only be applied when the user
comment|/// explicitly wrote a cast. This is a C++0x feature.
name|bool
name|isExplicitSpecified
argument_list|()
specifier|const
block|{
return|return
name|IsExplicitSpecified
return|;
block|}
comment|/// isExplicit - Whether this is an explicit conversion operator
comment|/// (C++0x only). Explicit conversion operators are only considered
comment|/// when the user has explicitly written a cast.
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
name|getFirstDeclaration
argument_list|()
operator|)
operator|->
name|isExplicitSpecified
argument_list|()
return|;
block|}
comment|/// getConversionType - Returns the type that this conversion
comment|/// function is converting to.
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
name|classof
argument_list|(
argument|const CXXConversionDecl *D
argument_list|)
block|{
return|return
name|true
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
comment|/// LinkageSpecDecl - This represents a linkage specification.  For example:
end_comment

begin_comment
comment|///   extern "C" void foo();
end_comment

begin_comment
comment|///
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
name|public
label|:
comment|/// LanguageIDs - Used to represent the language in a linkage
comment|/// specification.  The values are part of the serialization abi for
comment|/// ASTs and cannot be changed without altering that abi.  To help
comment|/// ensure a stable abi for this, we choose the DW_LANG_ encodings
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
comment|/// Language - The language for this linkage specification.
name|LanguageIDs
name|Language
decl_stmt|;
comment|/// HadBraces - Whether this linkage specification had curly braces or not.
name|bool
name|HadBraces
range|:
literal|1
decl_stmt|;
name|LinkageSpecDecl
argument_list|(
argument|DeclContext *DC
argument_list|,
argument|SourceLocation L
argument_list|,
argument|LanguageIDs lang
argument_list|,
argument|bool Braces
argument_list|)
block|:
name|Decl
argument_list|(
name|LinkageSpec
argument_list|,
name|DC
argument_list|,
name|L
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
name|HadBraces
argument_list|(
argument|Braces
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
argument|SourceLocation L
argument_list|,
argument|LanguageIDs Lang
argument_list|,
argument|bool Braces
argument_list|)
expr_stmt|;
comment|/// \brief Return the language specified by this linkage specification.
name|LanguageIDs
name|getLanguage
argument_list|()
specifier|const
block|{
return|return
name|Language
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
return|return
name|HadBraces
return|;
block|}
comment|/// \brief Set whether this linkage specification has braces in its
comment|/// syntactic form.
name|void
name|setHasBraces
parameter_list|(
name|bool
name|B
parameter_list|)
block|{
name|HadBraces
operator|=
name|B
expr_stmt|;
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
name|classof
parameter_list|(
specifier|const
name|LinkageSpecDecl
modifier|*
name|D
parameter_list|)
block|{
return|return
name|true
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
name|LinkageSpec
return|;
block|}
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
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|/// UsingDirectiveDecl - Represents C++ using-directive. For example:
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|///    using namespace std;
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|// NB: UsingDirectiveDecl should be Decl not NamedDecl, but we provide
end_comment

begin_comment
comment|// artificial name, for all using-directives in order to store
end_comment

begin_comment
comment|// them in DeclContext effectively.
end_comment

begin_decl_stmt
name|class
name|UsingDirectiveDecl
range|:
name|public
name|NamedDecl
block|{
comment|/// \brief The location of the "using" keyword.
name|SourceLocation
name|UsingLoc
block|;
comment|/// SourceLocation - Location of 'namespace' token.
name|SourceLocation
name|NamespaceLoc
block|;
comment|/// \brief The source range that covers the nested-name-specifier
comment|/// preceding the namespace name.
name|SourceRange
name|QualifierRange
block|;
comment|/// \brief The nested-name-specifier that precedes the namespace
comment|/// name, if any.
name|NestedNameSpecifier
operator|*
name|Qualifier
block|;
comment|/// NominatedNamespace - Namespace nominated by using-directive.
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
comment|/// getUsingDirectiveName - Returns special DeclarationName used by
comment|/// using-directives. This is only used by DeclContext for storing
comment|/// UsingDirectiveDecls in its lookup structure.
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
argument|SourceRange QualifierRange
argument_list|,
argument|NestedNameSpecifier *Qualifier
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
name|QualifierRange
argument_list|(
name|QualifierRange
argument_list|)
block|,
name|Qualifier
argument_list|(
name|Qualifier
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
block|{   }
name|public
operator|:
comment|/// \brief Retrieve the source range of the nested-name-specifier
comment|/// that qualifies the namespace name.
name|SourceRange
name|getQualifierRange
argument_list|()
specifier|const
block|{
return|return
name|QualifierRange
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
name|Qualifier
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
comment|/// getNominatedNamespace - Returns namespace nominated by using-directive.
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
comment|/// \brief Return the location of the "using" keyword.
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
comment|/// getNamespaceKeyLocation - Returns location of namespace keyword.
name|SourceLocation
name|getNamespaceKeyLocation
argument_list|()
specifier|const
block|{
return|return
name|NamespaceLoc
return|;
block|}
comment|/// getIdentLocation - Returns location of identifier.
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
argument|SourceRange QualifierRange
argument_list|,
argument|NestedNameSpecifier *Qualifier
argument_list|,
argument|SourceLocation IdentLoc
argument_list|,
argument|NamedDecl *Nominated
argument_list|,
argument|DeclContext *CommonAncestor
argument_list|)
block|;
name|SourceRange
name|getSourceRange
argument_list|()
specifier|const
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
name|classof
argument_list|(
argument|const UsingDirectiveDecl *D
argument_list|)
block|{
return|return
name|true
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
comment|/// NamespaceAliasDecl - Represents a C++ namespace alias. For example:
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// @code
end_comment

begin_comment
comment|/// namespace Foo = Bar;
end_comment

begin_comment
comment|/// @endcode
end_comment

begin_decl_stmt
name|class
name|NamespaceAliasDecl
range|:
name|public
name|NamedDecl
block|{
comment|/// \brief The location of the "namespace" keyword.
name|SourceLocation
name|NamespaceLoc
block|;
comment|/// \brief The source range that covers the nested-name-specifier
comment|/// preceding the namespace name.
name|SourceRange
name|QualifierRange
block|;
comment|/// \brief The nested-name-specifier that precedes the namespace
comment|/// name, if any.
name|NestedNameSpecifier
operator|*
name|Qualifier
block|;
comment|/// IdentLoc - Location of namespace identifier. Accessed by TargetNameLoc.
name|SourceLocation
name|IdentLoc
block|;
comment|/// Namespace - The Decl that this alias points to. Can either be a
comment|/// NamespaceDecl or a NamespaceAliasDecl.
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
argument|SourceRange QualifierRange
argument_list|,
argument|NestedNameSpecifier *Qualifier
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
name|QualifierRange
argument_list|(
name|QualifierRange
argument_list|)
block|,
name|Qualifier
argument_list|(
name|Qualifier
argument_list|)
block|,
name|IdentLoc
argument_list|(
name|IdentLoc
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
comment|/// \brief Retrieve the source range of the nested-name-specifier
comment|/// that qualifiers the namespace name.
name|SourceRange
name|getQualifierRange
argument_list|()
specifier|const
block|{
return|return
name|QualifierRange
return|;
block|}
comment|/// \brief Set the source range of the nested-name-specifier that qualifies
comment|/// the namespace name.
name|void
name|setQualifierRange
argument_list|(
argument|SourceRange R
argument_list|)
block|{
name|QualifierRange
operator|=
name|R
block|; }
comment|/// \brief Retrieve the nested-name-specifier that qualifies the
comment|/// name of the namespace.
name|NestedNameSpecifier
operator|*
name|getQualifier
argument_list|()
specifier|const
block|{
return|return
name|Qualifier
return|;
block|}
comment|/// \brief Set the nested-name-specifier that qualifies the name of the
comment|/// namespace.
name|void
name|setQualifier
argument_list|(
argument|NestedNameSpecifier *NNS
argument_list|)
block|{
name|Qualifier
operator|=
name|NNS
block|; }
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
comment|/// Returns the location of the 'namespace' keyword.
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
name|SourceRange
name|QualifierRange
parameter_list|,
name|NestedNameSpecifier
modifier|*
name|Qualifier
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

begin_expr_stmt
name|virtual
name|SourceRange
name|getSourceRange
argument_list|()
specifier|const
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
name|classof
parameter_list|(
specifier|const
name|NamespaceAliasDecl
modifier|*
name|D
parameter_list|)
block|{
return|return
name|true
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
comment|/// UsingShadowDecl - Represents a shadow declaration introduced into
end_comment

begin_comment
comment|/// a scope by a (resolved) using declaration.  For example,
end_comment

begin_comment
comment|///
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
comment|///   using A::foo(); //<- a UsingDecl
end_comment

begin_comment
comment|///                   // Also creates a UsingShadowDecl for A::foo in B
end_comment

begin_comment
comment|/// }
end_comment

begin_comment
comment|///
end_comment

begin_decl_stmt
name|class
name|UsingShadowDecl
range|:
name|public
name|NamedDecl
block|{
comment|/// The referenced declaration.
name|NamedDecl
operator|*
name|Underlying
block|;
comment|/// \brief The using declaration which introduced this decl or the next using
comment|/// shadow declaration contained in the aforementioned using declaration.
name|NamedDecl
operator|*
name|UsingOrNextShadow
block|;
name|friend
name|class
name|UsingDecl
block|;
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
operator|:
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
block|,
name|Underlying
argument_list|(
name|Target
argument_list|)
block|,
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
name|public
operator|:
specifier|static
name|UsingShadowDecl
operator|*
name|Create
argument_list|(
argument|ASTContext&C
argument_list|,
argument|DeclContext *DC
argument_list|,
argument|SourceLocation Loc
argument_list|,
argument|UsingDecl *Using
argument_list|,
argument|NamedDecl *Target
argument_list|)
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
argument_list|(
argument|NamedDecl* ND
argument_list|)
block|{
name|assert
argument_list|(
name|ND
operator|&&
literal|"Target decl is null!"
argument_list|)
block|;
name|Underlying
operator|=
name|ND
block|;
name|IdentifierNamespace
operator|=
name|ND
operator|->
name|getIdentifierNamespace
argument_list|()
block|;   }
comment|/// \brief Gets the using declaration to which this declaration is tied.
name|UsingDecl
operator|*
name|getUsingDecl
argument_list|()
specifier|const
block|;
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
name|classof
argument_list|(
argument|const UsingShadowDecl *D
argument_list|)
block|{
return|return
name|true
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
name|Decl
operator|::
name|UsingShadow
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
comment|/// UsingDecl - Represents a C++ using-declaration. For example:
end_comment

begin_comment
comment|///    using someNameSpace::someIdentifier;
end_comment

begin_decl_stmt
name|class
name|UsingDecl
range|:
name|public
name|NamedDecl
block|{
comment|/// \brief The source range that covers the nested-name-specifier
comment|/// preceding the declaration name.
name|SourceRange
name|NestedNameRange
block|;
comment|/// \brief The source location of the "using" location itself.
name|SourceLocation
name|UsingLocation
block|;
comment|/// \brief Target nested name specifier.
name|NestedNameSpecifier
operator|*
name|TargetNestedName
block|;
comment|/// DNLoc - Provides source/type location info for the
comment|/// declaration name embedded in the ValueDecl base class.
name|DeclarationNameLoc
name|DNLoc
block|;
comment|/// \brief The first shadow declaration of the shadow decl chain associated
comment|/// with this using declaration.
name|UsingShadowDecl
operator|*
name|FirstUsingShadow
block|;
comment|// \brief Has 'typename' keyword.
name|bool
name|IsTypeName
block|;
name|UsingDecl
argument_list|(
argument|DeclContext *DC
argument_list|,
argument|SourceRange NNR
argument_list|,
argument|SourceLocation UL
argument_list|,
argument|NestedNameSpecifier* TargetNNS
argument_list|,
argument|const DeclarationNameInfo&NameInfo
argument_list|,
argument|bool IsTypeNameArg
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
name|NestedNameRange
argument_list|(
name|NNR
argument_list|)
block|,
name|UsingLocation
argument_list|(
name|UL
argument_list|)
block|,
name|TargetNestedName
argument_list|(
name|TargetNNS
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
argument_list|)
block|,
name|IsTypeName
argument_list|(
argument|IsTypeNameArg
argument_list|)
block|{   }
name|public
operator|:
comment|/// \brief Returns the source range that covers the nested-name-specifier
comment|/// preceding the namespace name.
name|SourceRange
name|getNestedNameRange
argument_list|()
specifier|const
block|{
return|return
name|NestedNameRange
return|;
block|}
comment|/// \brief Set the source range of the nested-name-specifier.
name|void
name|setNestedNameRange
argument_list|(
argument|SourceRange R
argument_list|)
block|{
name|NestedNameRange
operator|=
name|R
block|; }
comment|// FIXME: Naming is inconsistent with other get*Loc functions.
comment|/// \brief Returns the source location of the "using" keyword.
name|SourceLocation
name|getUsingLocation
argument_list|()
specifier|const
block|{
return|return
name|UsingLocation
return|;
block|}
comment|/// \brief Set the source location of the 'using' keyword.
name|void
name|setUsingLocation
argument_list|(
argument|SourceLocation L
argument_list|)
block|{
name|UsingLocation
operator|=
name|L
block|; }
comment|/// \brief Get the target nested name declaration.
name|NestedNameSpecifier
operator|*
name|getTargetNestedNameDecl
argument_list|()
specifier|const
block|{
return|return
name|TargetNestedName
return|;
block|}
comment|/// \brief Set the target nested name declaration.
name|void
name|setTargetNestedNameDecl
argument_list|(
argument|NestedNameSpecifier *NNS
argument_list|)
block|{
name|TargetNestedName
operator|=
name|NNS
block|;   }
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
comment|/// \brief Return true if the using declaration has 'typename'.
name|bool
name|isTypeName
argument_list|()
specifier|const
block|{
return|return
name|IsTypeName
return|;
block|}
comment|/// \brief Sets whether the using declaration has 'typename'.
name|void
name|setTypeName
argument_list|(
argument|bool TN
argument_list|)
block|{
name|IsTypeName
operator|=
name|TN
block|; }
comment|/// \brief Iterates through the using shadow declarations assosiated with
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
name|SourceRange
name|NNR
parameter_list|,
name|SourceLocation
name|UsingL
parameter_list|,
name|NestedNameSpecifier
modifier|*
name|TargetNNS
parameter_list|,
specifier|const
name|DeclarationNameInfo
modifier|&
name|NameInfo
parameter_list|,
name|bool
name|IsTypeNameArg
parameter_list|)
function_decl|;
end_function_decl

begin_expr_stmt
name|SourceRange
name|getSourceRange
argument_list|()
specifier|const
block|{
return|return
name|SourceRange
argument_list|(
name|UsingLocation
argument_list|,
name|getNameInfo
argument_list|()
operator|.
name|getEndLoc
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
name|classof
parameter_list|(
specifier|const
name|UsingDecl
modifier|*
name|D
parameter_list|)
block|{
return|return
name|true
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
comment|/// UnresolvedUsingValueDecl - Represents a dependent using
end_comment

begin_comment
comment|/// declaration which was not marked with 'typename'.  Unlike
end_comment

begin_comment
comment|/// non-dependent using declarations, these *only* bring through
end_comment

begin_comment
comment|/// non-types; otherwise they would break two-phase lookup.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// template<class T> class A : public Base<T> {
end_comment

begin_comment
comment|///   using Base<T>::foo;
end_comment

begin_comment
comment|/// };
end_comment

begin_decl_stmt
name|class
name|UnresolvedUsingValueDecl
range|:
name|public
name|ValueDecl
block|{
comment|/// \brief The source range that covers the nested-name-specifier
comment|/// preceding the declaration name.
name|SourceRange
name|TargetNestedNameRange
block|;
comment|/// \brief The source location of the 'using' keyword
name|SourceLocation
name|UsingLocation
block|;
name|NestedNameSpecifier
operator|*
name|TargetNestedNameSpecifier
block|;
comment|/// DNLoc - Provides source/type location info for the
comment|/// declaration name embedded in the ValueDecl base class.
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
argument|SourceRange TargetNNR
argument_list|,
argument|NestedNameSpecifier *TargetNNS
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
name|TargetNestedNameRange
argument_list|(
name|TargetNNR
argument_list|)
block|,
name|UsingLocation
argument_list|(
name|UsingLoc
argument_list|)
block|,
name|TargetNestedNameSpecifier
argument_list|(
name|TargetNNS
argument_list|)
block|,
name|DNLoc
argument_list|(
argument|NameInfo.getInfo()
argument_list|)
block|{ }
name|public
operator|:
comment|/// \brief Returns the source range that covers the nested-name-specifier
comment|/// preceding the namespace name.
name|SourceRange
name|getTargetNestedNameRange
argument_list|()
specifier|const
block|{
return|return
name|TargetNestedNameRange
return|;
block|}
comment|/// \brief Set the source range coverting the nested-name-specifier preceding
comment|/// the namespace name.
name|void
name|setTargetNestedNameRange
argument_list|(
argument|SourceRange R
argument_list|)
block|{
name|TargetNestedNameRange
operator|=
name|R
block|; }
comment|/// \brief Get target nested name declaration.
name|NestedNameSpecifier
operator|*
name|getTargetNestedNameSpecifier
argument_list|()
specifier|const
block|{
return|return
name|TargetNestedNameSpecifier
return|;
block|}
comment|/// \brief Set the nested name declaration.
name|void
name|setTargetNestedNameSpecifier
argument_list|(
argument|NestedNameSpecifier* NNS
argument_list|)
block|{
name|TargetNestedNameSpecifier
operator|=
name|NNS
block|;   }
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
argument|SourceRange TargetNNR
argument_list|,
argument|NestedNameSpecifier *TargetNNS
argument_list|,
argument|const DeclarationNameInfo&NameInfo
argument_list|)
block|;
name|SourceRange
name|getSourceRange
argument_list|()
specifier|const
block|{
return|return
name|SourceRange
argument_list|(
name|UsingLocation
argument_list|,
name|getNameInfo
argument_list|()
operator|.
name|getEndLoc
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
name|classof
argument_list|(
argument|const UnresolvedUsingValueDecl *D
argument_list|)
block|{
return|return
name|true
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
comment|/// UnresolvedUsingTypenameDecl - Represents a dependent using
end_comment

begin_comment
comment|/// declaration which was marked with 'typename'.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// template<class T> class A : public Base<T> {
end_comment

begin_comment
comment|///   using typename Base<T>::foo;
end_comment

begin_comment
comment|/// };
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// The type associated with a unresolved using typename decl is
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
comment|/// \brief The source range that covers the nested-name-specifier
comment|/// preceding the declaration name.
name|SourceRange
name|TargetNestedNameRange
block|;
comment|/// \brief The source location of the 'using' keyword
name|SourceLocation
name|UsingLocation
block|;
comment|/// \brief The source location of the 'typename' keyword
name|SourceLocation
name|TypenameLocation
block|;
name|NestedNameSpecifier
operator|*
name|TargetNestedNameSpecifier
block|;
name|UnresolvedUsingTypenameDecl
argument_list|(
argument|DeclContext *DC
argument_list|,
argument|SourceLocation UsingLoc
argument_list|,
argument|SourceLocation TypenameLoc
argument_list|,
argument|SourceRange TargetNNR
argument_list|,
argument|NestedNameSpecifier *TargetNNS
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
argument_list|)
block|,
name|TargetNestedNameRange
argument_list|(
name|TargetNNR
argument_list|)
block|,
name|UsingLocation
argument_list|(
name|UsingLoc
argument_list|)
block|,
name|TypenameLocation
argument_list|(
name|TypenameLoc
argument_list|)
block|,
name|TargetNestedNameSpecifier
argument_list|(
argument|TargetNNS
argument_list|)
block|{ }
name|friend
name|class
name|ASTDeclReader
block|;
name|public
operator|:
comment|/// \brief Returns the source range that covers the nested-name-specifier
comment|/// preceding the namespace name.
name|SourceRange
name|getTargetNestedNameRange
argument_list|()
specifier|const
block|{
return|return
name|TargetNestedNameRange
return|;
block|}
comment|/// \brief Get target nested name declaration.
name|NestedNameSpecifier
operator|*
name|getTargetNestedNameSpecifier
argument_list|()
block|{
return|return
name|TargetNestedNameSpecifier
return|;
block|}
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
argument|SourceRange TargetNNR
argument_list|,
argument|NestedNameSpecifier *TargetNNS
argument_list|,
argument|SourceLocation TargetNameLoc
argument_list|,
argument|DeclarationName TargetName
argument_list|)
block|;
name|SourceRange
name|getSourceRange
argument_list|()
specifier|const
block|{
return|return
name|SourceRange
argument_list|(
name|UsingLocation
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
name|classof
argument_list|(
argument|const UnresolvedUsingTypenameDecl *D
argument_list|)
block|{
return|return
name|true
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
comment|/// StaticAssertDecl - Represents a C++0x static_assert declaration.
name|class
name|StaticAssertDecl
operator|:
name|public
name|Decl
block|{
name|Expr
operator|*
name|AssertExpr
block|;
name|StringLiteral
operator|*
name|Message
block|;
name|StaticAssertDecl
argument_list|(
argument|DeclContext *DC
argument_list|,
argument|SourceLocation L
argument_list|,
argument|Expr *assertexpr
argument_list|,
argument|StringLiteral *message
argument_list|)
operator|:
name|Decl
argument_list|(
name|StaticAssert
argument_list|,
name|DC
argument_list|,
name|L
argument_list|)
block|,
name|AssertExpr
argument_list|(
name|assertexpr
argument_list|)
block|,
name|Message
argument_list|(
argument|message
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
argument|SourceLocation L
argument_list|,
argument|Expr *AssertExpr
argument_list|,
argument|StringLiteral *Message
argument_list|)
block|;
name|Expr
operator|*
name|getAssertExpr
argument_list|()
block|{
return|return
name|AssertExpr
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
name|AssertExpr
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
name|classof
argument_list|(
argument|StaticAssertDecl *D
argument_list|)
block|{
return|return
name|true
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
comment|/// Insertion operator for diagnostics.  This allows sending AccessSpecifier's
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

