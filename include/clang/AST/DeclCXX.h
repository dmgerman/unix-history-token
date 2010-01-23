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
comment|//  This file defines the C++ Decl subclasses.
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
comment|// FIXME: Move over to a TypeLoc!
name|SourceRange
name|Range
decl_stmt|;
comment|/// Virtual - Whether this is a virtual base class or not.
name|bool
name|Virtual
range|:
literal|1
decl_stmt|;
comment|/// BaseOfClass - Whether this is the base of a class (true) or of a
comment|/// struct (false). This determines the mapping from the access
comment|/// specifier as written in the source code to the access specifier
comment|/// used for semantic analysis.
name|bool
name|BaseOfClass
range|:
literal|1
decl_stmt|;
comment|/// Access - Access specifier as written in the source code (which
comment|/// may be AS_none). The actual type of data stored here is an
comment|/// AccessSpecifier, but we use "unsigned" here to work around a
comment|/// VC++ bug.
name|unsigned
name|Access
range|:
literal|2
decl_stmt|;
comment|/// BaseType - The type of the base class. This will be a class or
comment|/// struct (or a typedef of such).
name|QualType
name|BaseType
decl_stmt|;
name|public
label|:
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
argument|QualType T
argument_list|)
block|:
name|Range
argument_list|(
name|R
argument_list|)
operator|,
name|Virtual
argument_list|(
name|V
argument_list|)
operator|,
name|BaseOfClass
argument_list|(
name|BC
argument_list|)
operator|,
name|Access
argument_list|(
name|A
argument_list|)
operator|,
name|BaseType
argument_list|(
argument|T
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
name|BaseType
return|;
block|}
block|}
empty_stmt|;
comment|/// CXXRecordDecl - Represents a C++ struct/union/class.
comment|/// FIXME: This class will disappear once we've properly taught RecordDecl
comment|/// to deal with C++-specific things.
name|class
name|CXXRecordDecl
range|:
name|public
name|RecordDecl
block|{
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
comment|/// Empty - true when this class is empty for traits purposes, i.e. has no
comment|/// data members other than 0-width bit-fields, has no virtual function/base,
comment|/// and doesn't inherit from a non-empty class. Doesn't take union-ness into
comment|/// account.
name|bool
name|Empty
operator|:
literal|1
block|;
comment|/// Polymorphic - True when this class is polymorphic, i.e. has at least one
comment|/// virtual member or derives from a polymorphic class.
name|bool
name|Polymorphic
operator|:
literal|1
block|;
comment|/// Abstract - True when this class is abstract, i.e. has at least one
comment|/// pure virtual function, (that can come from a base class).
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
comment|/// Bases - Base classes of this class.
comment|/// FIXME: This is wasted space for a union.
name|CXXBaseSpecifier
operator|*
name|Bases
block|;
comment|/// NumBases - The number of base class specifiers in Bases.
name|unsigned
name|NumBases
block|;
comment|/// VBases - direct and indirect virtual base classes of this class.
name|CXXBaseSpecifier
operator|*
name|VBases
block|;
comment|/// NumVBases - The number of virtual base class specifiers in VBases.
name|unsigned
name|NumVBases
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
comment|/// VisibleConversions - Overload set containing the conversion functions
comment|/// of this C++ class and all those inherited conversion functions that
comment|/// are visible in this class. Each of the entries in this overload set is
comment|/// a CXXConversionDecl or a FunctionTemplateDecl.
name|UnresolvedSet
operator|<
literal|4
operator|>
name|VisibleConversions
block|;
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
name|void
name|getNestedVisibleConversionFunctions
argument_list|(
name|CXXRecordDecl
operator|*
name|RD
argument_list|,
specifier|const
name|llvm
operator|::
name|SmallPtrSet
operator|<
name|CanQualType
argument_list|,
literal|8
operator|>
operator|&
name|TopConversionsTypeSet
argument_list|,
specifier|const
name|llvm
operator|::
name|SmallPtrSet
operator|<
name|CanQualType
argument_list|,
literal|8
operator|>
operator|&
name|HiddenConversionTypes
argument_list|)
block|;
name|void
name|collectConversionFunctions
argument_list|(
argument|llvm::SmallPtrSet<CanQualType
argument_list|,
literal|8
argument|>& ConversionsTypeSet
argument_list|)
specifier|const
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
operator|~
name|CXXRecordDecl
argument_list|()
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
specifier|static
name|CXXRecordDecl
modifier|*
name|Create
parameter_list|(
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
name|virtual
name|void
name|Destroy
parameter_list|(
name|ASTContext
modifier|&
name|C
parameter_list|)
function_decl|;
name|bool
name|isDynamicClass
argument_list|()
specifier|const
block|{
return|return
name|Polymorphic
operator|||
name|NumVBases
operator|!=
literal|0
return|;
block|}
comment|/// setBases - Sets the base classes of this struct or class.
name|void
name|setBases
parameter_list|(
name|ASTContext
modifier|&
name|C
parameter_list|,
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
comment|/// getNumBases - Retrieves the number of base classes of this
comment|/// class.
name|unsigned
name|getNumBases
argument_list|()
specifier|const
block|{
return|return
name|NumBases
return|;
block|}
name|base_class_iterator
name|bases_begin
parameter_list|()
block|{
return|return
name|Bases
return|;
block|}
name|base_class_const_iterator
name|bases_begin
argument_list|()
specifier|const
block|{
return|return
name|Bases
return|;
block|}
name|base_class_iterator
name|bases_end
parameter_list|()
block|{
return|return
name|Bases
operator|+
name|NumBases
return|;
block|}
name|base_class_const_iterator
name|bases_end
argument_list|()
specifier|const
block|{
return|return
name|Bases
operator|+
name|NumBases
return|;
block|}
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
comment|/// getNumVBases - Retrieves the number of virtual base classes of this
comment|/// class.
name|unsigned
name|getNumVBases
argument_list|()
specifier|const
block|{
return|return
name|NumVBases
return|;
block|}
name|base_class_iterator
name|vbases_begin
parameter_list|()
block|{
return|return
name|VBases
return|;
block|}
name|base_class_const_iterator
name|vbases_begin
argument_list|()
specifier|const
block|{
return|return
name|VBases
return|;
block|}
name|base_class_iterator
name|vbases_end
parameter_list|()
block|{
return|return
name|VBases
operator|+
name|NumVBases
return|;
block|}
name|base_class_const_iterator
name|vbases_end
argument_list|()
specifier|const
block|{
return|return
name|VBases
operator|+
name|NumVBases
return|;
block|}
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
comment|/// \brief Determine whether this class has any dependent base classes.
name|bool
name|hasAnyDependentBases
argument_list|()
specifier|const
expr_stmt|;
comment|/// Iterator access to method members.  The method iterator visits
comment|/// all method members of the class, including non-instance methods,
comment|/// special methods, etc.
typedef|typedef
name|specific_decl_iterator
operator|<
name|CXXMethodDecl
operator|>
name|method_iterator
expr_stmt|;
comment|/// method_begin - Method begin iterator.  Iterates in the order the methods
comment|/// were declared.
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
comment|/// method_end - Method end iterator.
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
comment|/// Iterator access to constructor members.
typedef|typedef
name|specific_decl_iterator
operator|<
name|CXXConstructorDecl
operator|>
name|ctor_iterator
expr_stmt|;
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
comment|/// hasConstCopyConstructor - Determines whether this class has a
comment|/// copy constructor that accepts a const-qualified argument.
name|bool
name|hasConstCopyConstructor
argument_list|(
name|ASTContext
operator|&
name|Context
argument_list|)
decl|const
decl_stmt|;
comment|/// getCopyConstructor - Returns the copy constructor for this class
name|CXXConstructorDecl
modifier|*
name|getCopyConstructor
argument_list|(
name|ASTContext
operator|&
name|Context
argument_list|,
name|unsigned
name|TypeQuals
argument_list|)
decl|const
decl_stmt|;
comment|/// hasConstCopyAssignment - Determines whether this class has a
comment|/// copy assignment operator that accepts a const-qualified argument.
comment|/// It returns its decl in MD if found.
name|bool
name|hasConstCopyAssignment
argument_list|(
name|ASTContext
operator|&
name|Context
argument_list|,
specifier|const
name|CXXMethodDecl
operator|*
operator|&
name|MD
argument_list|)
decl|const
decl_stmt|;
comment|/// addedConstructor - Notify the class that another constructor has
comment|/// been added. This routine helps maintain information about the
comment|/// class based on which constructors have been added.
name|void
name|addedConstructor
parameter_list|(
name|ASTContext
modifier|&
name|Context
parameter_list|,
name|CXXConstructorDecl
modifier|*
name|ConDecl
parameter_list|)
function_decl|;
comment|/// hasUserDeclaredConstructor - Whether this class has any
comment|/// user-declared constructors. When true, a default constructor
comment|/// will not be implicitly declared.
name|bool
name|hasUserDeclaredConstructor
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
operator|(
name|isDefinition
argument_list|()
operator|||
name|cast
operator|<
name|RecordType
operator|>
operator|(
name|getTypeForDecl
argument_list|()
operator|)
operator|->
name|isBeingDefined
argument_list|()
operator|)
operator|&&
literal|"Incomplete record decl!"
argument_list|)
block|;
return|return
name|UserDeclaredConstructor
return|;
block|}
comment|/// hasUserDeclaredCopyConstructor - Whether this class has a
comment|/// user-declared copy constructor. When false, a copy constructor
comment|/// will be implicitly declared.
name|bool
name|hasUserDeclaredCopyConstructor
argument_list|()
specifier|const
block|{
return|return
name|UserDeclaredCopyConstructor
return|;
block|}
comment|/// addedAssignmentOperator - Notify the class that another assignment
comment|/// operator has been added. This routine helps maintain information about the
comment|/// class based on which operators have been added.
name|void
name|addedAssignmentOperator
parameter_list|(
name|ASTContext
modifier|&
name|Context
parameter_list|,
name|CXXMethodDecl
modifier|*
name|OpDecl
parameter_list|)
function_decl|;
comment|/// hasUserDeclaredCopyAssignment - Whether this class has a
comment|/// user-declared copy assignment operator. When false, a copy
comment|/// assigment operator will be implicitly declared.
name|bool
name|hasUserDeclaredCopyAssignment
argument_list|()
specifier|const
block|{
return|return
name|UserDeclaredCopyAssignment
return|;
block|}
comment|/// hasUserDeclaredDestructor - Whether this class has a
comment|/// user-declared destructor. When false, a destructor will be
comment|/// implicitly declared.
name|bool
name|hasUserDeclaredDestructor
argument_list|()
specifier|const
block|{
return|return
name|UserDeclaredDestructor
return|;
block|}
comment|/// setUserDeclaredDestructor - Set whether this class has a
comment|/// user-declared destructor. If not set by the time the class is
comment|/// fully defined, a destructor will be implicitly declared.
name|void
name|setUserDeclaredDestructor
parameter_list|(
name|bool
name|UCD
parameter_list|)
block|{
name|UserDeclaredDestructor
operator|=
name|UCD
expr_stmt|;
block|}
comment|/// getConversions - Retrieve the overload set containing all of the
comment|/// conversion functions in this class.
name|UnresolvedSetImpl
modifier|*
name|getConversionFunctions
parameter_list|()
block|{
name|assert
argument_list|(
operator|(
name|this
operator|->
name|isDefinition
argument_list|()
operator|||
name|cast
operator|<
name|RecordType
operator|>
operator|(
name|getTypeForDecl
argument_list|()
operator|)
operator|->
name|isBeingDefined
argument_list|()
operator|)
operator|&&
literal|"getConversionFunctions() called on incomplete type"
argument_list|)
expr_stmt|;
return|return
operator|&
name|Conversions
return|;
block|}
specifier|const
name|UnresolvedSetImpl
operator|*
name|getConversionFunctions
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
operator|(
name|this
operator|->
name|isDefinition
argument_list|()
operator|||
name|cast
operator|<
name|RecordType
operator|>
operator|(
name|getTypeForDecl
argument_list|()
operator|)
operator|->
name|isBeingDefined
argument_list|()
operator|)
operator|&&
literal|"getConversionFunctions() called on incomplete type"
argument_list|)
block|;
return|return
operator|&
name|Conversions
return|;
block|}
typedef|typedef
name|UnresolvedSetImpl
operator|::
name|iterator
name|conversion_iterator
expr_stmt|;
name|conversion_iterator
name|conversion_begin
argument_list|()
specifier|const
block|{
return|return
name|Conversions
operator|.
name|begin
argument_list|()
return|;
block|}
name|conversion_iterator
name|conversion_end
argument_list|()
specifier|const
block|{
return|return
name|Conversions
operator|.
name|end
argument_list|()
return|;
block|}
comment|/// Replaces a conversion function with a new declaration.
comment|///
comment|/// Returns true if the old conversion was found.
name|bool
name|replaceConversion
parameter_list|(
specifier|const
name|NamedDecl
modifier|*
name|Old
parameter_list|,
name|NamedDecl
modifier|*
name|New
parameter_list|)
block|{
return|return
name|Conversions
operator|.
name|replace
argument_list|(
name|Old
argument_list|,
name|New
argument_list|)
return|;
block|}
comment|/// getVisibleConversionFunctions - get all conversion functions visible
comment|/// in current class; including conversion function templates.
specifier|const
name|UnresolvedSetImpl
modifier|*
name|getVisibleConversionFunctions
parameter_list|()
function_decl|;
comment|/// addVisibleConversionFunction - Add a new conversion function to the
comment|/// list of visible conversion functions.
name|void
name|addVisibleConversionFunction
parameter_list|(
name|CXXConversionDecl
modifier|*
name|ConvDecl
parameter_list|)
function_decl|;
comment|/// \brief Add a new conversion function template to the list of visible
comment|/// conversion functions.
name|void
name|addVisibleConversionFunction
parameter_list|(
name|FunctionTemplateDecl
modifier|*
name|ConvDecl
parameter_list|)
function_decl|;
comment|/// addConversionFunction - Add a new conversion function to the
comment|/// list of conversion functions.
name|void
name|addConversionFunction
parameter_list|(
name|CXXConversionDecl
modifier|*
name|ConvDecl
parameter_list|)
function_decl|;
comment|/// \brief Add a new conversion function template to the list of conversion
comment|/// functions.
name|void
name|addConversionFunction
parameter_list|(
name|FunctionTemplateDecl
modifier|*
name|ConvDecl
parameter_list|)
function_decl|;
comment|/// isAggregate - Whether this class is an aggregate (C++
comment|/// [dcl.init.aggr]), which is a class with no user-declared
comment|/// constructors, no private or protected non-static data members,
comment|/// no base classes, and no virtual functions (C++ [dcl.init.aggr]p1).
name|bool
name|isAggregate
argument_list|()
specifier|const
block|{
return|return
name|Aggregate
return|;
block|}
comment|/// setAggregate - Set whether this class is an aggregate (C++
comment|/// [dcl.init.aggr]).
name|void
name|setAggregate
parameter_list|(
name|bool
name|Agg
parameter_list|)
block|{
name|Aggregate
operator|=
name|Agg
expr_stmt|;
block|}
comment|/// setMethodAsVirtual - Make input method virtual and set the necesssary
comment|/// special function bits and other bits accordingly.
name|void
name|setMethodAsVirtual
parameter_list|(
name|FunctionDecl
modifier|*
name|Method
parameter_list|)
function_decl|;
comment|/// isPOD - Whether this class is a POD-type (C++ [class]p4), which is a class
comment|/// that is an aggregate that has no non-static non-POD data members, no
comment|/// reference data members, no user-defined copy assignment operator and no
comment|/// user-defined destructor.
name|bool
name|isPOD
argument_list|()
specifier|const
block|{
return|return
name|PlainOldData
return|;
block|}
comment|/// setPOD - Set whether this class is a POD-type (C++ [class]p4).
name|void
name|setPOD
parameter_list|(
name|bool
name|POD
parameter_list|)
block|{
name|PlainOldData
operator|=
name|POD
expr_stmt|;
block|}
comment|/// isEmpty - Whether this class is empty (C++0x [meta.unary.prop]), which
comment|/// means it has a virtual function, virtual base, data member (other than
comment|/// 0-width bit-field) or inherits from a non-empty class. Does NOT include
comment|/// a check for union-ness.
name|bool
name|isEmpty
argument_list|()
specifier|const
block|{
return|return
name|Empty
return|;
block|}
comment|/// Set whether this class is empty (C++0x [meta.unary.prop])
name|void
name|setEmpty
parameter_list|(
name|bool
name|Emp
parameter_list|)
block|{
name|Empty
operator|=
name|Emp
expr_stmt|;
block|}
comment|/// isPolymorphic - Whether this class is polymorphic (C++ [class.virtual]),
comment|/// which means that the class contains or inherits a virtual function.
name|bool
name|isPolymorphic
argument_list|()
specifier|const
block|{
return|return
name|Polymorphic
return|;
block|}
comment|/// setPolymorphic - Set whether this class is polymorphic (C++
comment|/// [class.virtual]).
name|void
name|setPolymorphic
parameter_list|(
name|bool
name|Poly
parameter_list|)
block|{
name|Polymorphic
operator|=
name|Poly
expr_stmt|;
block|}
comment|/// isAbstract - Whether this class is abstract (C++ [class.abstract]),
comment|/// which means that the class contains or inherits a pure virtual function.
name|bool
name|isAbstract
argument_list|()
specifier|const
block|{
return|return
name|Abstract
return|;
block|}
comment|/// setAbstract - Set whether this class is abstract (C++ [class.abstract])
name|void
name|setAbstract
parameter_list|(
name|bool
name|Abs
parameter_list|)
block|{
name|Abstract
operator|=
name|Abs
expr_stmt|;
block|}
comment|// hasTrivialConstructor - Whether this class has a trivial constructor
comment|// (C++ [class.ctor]p5)
name|bool
name|hasTrivialConstructor
argument_list|()
specifier|const
block|{
return|return
name|HasTrivialConstructor
return|;
block|}
comment|// setHasTrivialConstructor - Set whether this class has a trivial constructor
comment|// (C++ [class.ctor]p5)
name|void
name|setHasTrivialConstructor
parameter_list|(
name|bool
name|TC
parameter_list|)
block|{
name|HasTrivialConstructor
operator|=
name|TC
expr_stmt|;
block|}
comment|// hasTrivialCopyConstructor - Whether this class has a trivial copy
comment|// constructor (C++ [class.copy]p6)
name|bool
name|hasTrivialCopyConstructor
argument_list|()
specifier|const
block|{
return|return
name|HasTrivialCopyConstructor
return|;
block|}
comment|// setHasTrivialCopyConstructor - Set whether this class has a trivial
comment|// copy constructor (C++ [class.copy]p6)
name|void
name|setHasTrivialCopyConstructor
parameter_list|(
name|bool
name|TC
parameter_list|)
block|{
name|HasTrivialCopyConstructor
operator|=
name|TC
expr_stmt|;
block|}
comment|// hasTrivialCopyAssignment - Whether this class has a trivial copy
comment|// assignment operator (C++ [class.copy]p11)
name|bool
name|hasTrivialCopyAssignment
argument_list|()
specifier|const
block|{
return|return
name|HasTrivialCopyAssignment
return|;
block|}
comment|// setHasTrivialCopyAssignment - Set whether this class has a
comment|// trivial copy assignment operator (C++ [class.copy]p11)
name|void
name|setHasTrivialCopyAssignment
parameter_list|(
name|bool
name|TC
parameter_list|)
block|{
name|HasTrivialCopyAssignment
operator|=
name|TC
expr_stmt|;
block|}
comment|// hasTrivialDestructor - Whether this class has a trivial destructor
comment|// (C++ [class.dtor]p3)
name|bool
name|hasTrivialDestructor
argument_list|()
specifier|const
block|{
return|return
name|HasTrivialDestructor
return|;
block|}
comment|// setHasTrivialDestructor - Set whether this class has a trivial destructor
comment|// (C++ [class.dtor]p3)
name|void
name|setHasTrivialDestructor
parameter_list|(
name|bool
name|TC
parameter_list|)
block|{
name|HasTrivialDestructor
operator|=
name|TC
expr_stmt|;
block|}
comment|/// \brief If this record is an instantiation of a member class,
comment|/// retrieves the member class from which it was instantiated.
comment|///
comment|/// This routine will return non-NULL for (non-templated) member
comment|/// classes of class templates. For example, given:
comment|///
comment|/// \code
comment|/// template<typename T>
comment|/// struct X {
comment|///   struct A { };
comment|/// };
comment|/// \endcode
comment|///
comment|/// The declaration for X<int>::A is a (non-templated) CXXRecordDecl
comment|/// whose parent is the class template specialization X<int>. For
comment|/// this declaration, getInstantiatedFromMemberClass() will return
comment|/// the CXXRecordDecl X<T>::A. When a complete definition of
comment|/// X<int>::A is required, it will be instantiated from the
comment|/// declaration returned by getInstantiatedFromMemberClass().
name|CXXRecordDecl
operator|*
name|getInstantiatedFromMemberClass
argument_list|()
specifier|const
expr_stmt|;
comment|/// \brief If this class is an instantiation of a member class of a
comment|/// class template specialization, retrieves the member specialization
comment|/// information.
name|MemberSpecializationInfo
operator|*
name|getMemberSpecializationInfo
argument_list|()
specifier|const
expr_stmt|;
comment|/// \brief Specify that this record is an instantiation of the
comment|/// member class RD.
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
comment|/// \brief Retrieves the class template that is described by this
comment|/// class declaration.
comment|///
comment|/// Every class template is represented as a ClassTemplateDecl and a
comment|/// CXXRecordDecl. The former contains template properties (such as
comment|/// the template parameter lists) while the latter contains the
comment|/// actual description of the template's
comment|/// contents. ClassTemplateDecl::getTemplatedDecl() retrieves the
comment|/// CXXRecordDecl that from a ClassTemplateDecl, while
comment|/// getDescribedClassTemplate() retrieves the ClassTemplateDecl from
comment|/// a CXXRecordDecl.
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
comment|/// \brief Determine whether this particular class is a specialization or
comment|/// instantiation of a class template or member class of a class template,
comment|/// and how it was instantiated or specialized.
name|TemplateSpecializationKind
name|getTemplateSpecializationKind
argument_list|()
specifier|const
expr_stmt|;
comment|/// \brief Set the kind of specialization or template instantiation this is.
name|void
name|setTemplateSpecializationKind
parameter_list|(
name|TemplateSpecializationKind
name|TSK
parameter_list|)
function_decl|;
comment|/// getDefaultConstructor - Returns the default constructor for this class
name|CXXConstructorDecl
modifier|*
name|getDefaultConstructor
parameter_list|(
name|ASTContext
modifier|&
name|Context
parameter_list|)
function_decl|;
comment|/// getDestructor - Returns the destructor decl for this class.
name|CXXDestructorDecl
modifier|*
name|getDestructor
parameter_list|(
name|ASTContext
modifier|&
name|Context
parameter_list|)
function_decl|;
comment|/// isLocalClass - If the class is a local class [class.local], returns
comment|/// the enclosing function declaration.
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
block|}
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
name|D
operator|->
name|getKind
argument_list|()
operator|==
name|CXXRecord
operator|||
name|D
operator|->
name|getKind
argument_list|()
operator|==
name|ClassTemplateSpecialization
operator|||
name|D
operator|->
name|getKind
argument_list|()
operator|==
name|ClassTemplatePartialSpecialization
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
argument|SourceLocation L
argument_list|,
argument|DeclarationName N
argument_list|,
argument|QualType T
argument_list|,
argument|TypeSourceInfo *TInfo
argument_list|,
argument|bool isStatic
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
argument|L
argument_list|,
argument|N
argument_list|,
argument|T
argument_list|,
argument|TInfo
argument_list|,
argument|(isStatic ? Static : None)
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
argument|SourceLocation L
argument_list|,
argument|DeclarationName N
argument_list|,
argument|QualType T
argument_list|,
argument|TypeSourceInfo *TInfo
argument_list|,
argument|bool isStatic = false
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
name|Static
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
name|D
operator|->
name|getKind
argument_list|()
operator|>=
name|CXXMethod
operator|&&
name|D
operator|->
name|getKind
argument_list|()
operator|<=
name|CXXConversion
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

begin_comment
unit|};
comment|/// CXXBaseOrMemberInitializer - Represents a C++ base or member
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
name|CXXBaseOrMemberInitializer
block|{
comment|/// \brief Either the base class name (stored as a TypeSourceInfo*) or the
comment|/// field being initialized.
name|llvm
operator|::
name|PointerUnion
operator|<
name|TypeSourceInfo
operator|*
operator|,
name|FieldDecl
operator|*
operator|>
name|BaseOrMember
expr_stmt|;
comment|/// \brief The source location for the field name.
name|SourceLocation
name|MemberLocation
decl_stmt|;
comment|/// Args - The arguments used to initialize the base or member.
name|Stmt
modifier|*
modifier|*
name|Args
decl_stmt|;
name|unsigned
name|NumArgs
decl_stmt|;
comment|/// \brief Stores either the constructor to call to initialize this base or
comment|/// member (a CXXConstructorDecl pointer), or stores the anonymous union of
comment|/// which the initialized value is a member.
comment|///
comment|/// When the value is a FieldDecl pointer, 'BaseOrMember' is class's
comment|/// anonymous union data member, this field holds the FieldDecl for the
comment|/// member of the anonymous union being initialized.
comment|/// @code
comment|/// struct X {
comment|///   X() : au_i1(123) {}
comment|///   union {
comment|///     int au_i1;
comment|///     float au_f1;
comment|///   };
comment|/// };
comment|/// @endcode
comment|/// In above example, BaseOrMember holds the field decl. for anonymous union
comment|/// and AnonUnionMember holds field decl for au_i1.
name|llvm
operator|::
name|PointerUnion
operator|<
name|CXXConstructorDecl
operator|*
operator|,
name|FieldDecl
operator|*
operator|>
name|CtorOrAnonUnion
expr_stmt|;
comment|/// LParenLoc - Location of the left paren of the ctor-initializer.
name|SourceLocation
name|LParenLoc
decl_stmt|;
comment|/// RParenLoc - Location of the right paren of the ctor-initializer.
name|SourceLocation
name|RParenLoc
decl_stmt|;
name|public
label|:
comment|/// CXXBaseOrMemberInitializer - Creates a new base-class initializer.
name|explicit
name|CXXBaseOrMemberInitializer
parameter_list|(
name|ASTContext
modifier|&
name|Context
parameter_list|,
name|TypeSourceInfo
modifier|*
name|TInfo
parameter_list|,
name|CXXConstructorDecl
modifier|*
name|C
parameter_list|,
name|SourceLocation
name|L
parameter_list|,
name|Expr
modifier|*
modifier|*
name|Args
parameter_list|,
name|unsigned
name|NumArgs
parameter_list|,
name|SourceLocation
name|R
parameter_list|)
function_decl|;
comment|/// CXXBaseOrMemberInitializer - Creates a new member initializer.
name|explicit
name|CXXBaseOrMemberInitializer
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
name|CXXConstructorDecl
modifier|*
name|C
parameter_list|,
name|SourceLocation
name|L
parameter_list|,
name|Expr
modifier|*
modifier|*
name|Args
parameter_list|,
name|unsigned
name|NumArgs
parameter_list|,
name|SourceLocation
name|R
parameter_list|)
function_decl|;
comment|/// \brief Destroy the base or member initializer.
name|void
name|Destroy
parameter_list|(
name|ASTContext
modifier|&
name|Context
parameter_list|)
function_decl|;
comment|/// arg_iterator - Iterates through the member initialization
comment|/// arguments.
typedef|typedef
name|ExprIterator
name|arg_iterator
typedef|;
comment|/// arg_const_iterator - Iterates through the member initialization
comment|/// arguments.
typedef|typedef
name|ConstExprIterator
name|const_arg_iterator
typedef|;
comment|/// isBaseInitializer - Returns true when this initializer is
comment|/// initializing a base class.
name|bool
name|isBaseInitializer
argument_list|()
specifier|const
block|{
return|return
name|BaseOrMember
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
name|BaseOrMember
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
name|Type
modifier|*
name|getBaseClass
parameter_list|()
function_decl|;
comment|/// \brief Returns the declarator information for a base class initializer.
name|TypeSourceInfo
operator|*
name|getBaseClassInfo
argument_list|()
specifier|const
block|{
return|return
name|BaseOrMember
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
modifier|*
name|getMember
parameter_list|()
block|{
if|if
condition|(
name|isMemberInitializer
argument_list|()
condition|)
return|return
name|BaseOrMember
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
name|SourceLocation
name|getMemberLocation
argument_list|()
specifier|const
block|{
return|return
name|MemberLocation
return|;
block|}
name|void
name|setMember
parameter_list|(
name|FieldDecl
modifier|*
name|Member
parameter_list|)
block|{
name|assert
argument_list|(
name|isMemberInitializer
argument_list|()
argument_list|)
expr_stmt|;
name|BaseOrMember
operator|=
name|Member
expr_stmt|;
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
name|FieldDecl
operator|*
name|getAnonUnionMember
argument_list|()
specifier|const
block|{
return|return
name|CtorOrAnonUnion
operator|.
name|dyn_cast
operator|<
name|FieldDecl
operator|*
operator|>
operator|(
operator|)
return|;
block|}
name|void
name|setAnonUnionMember
parameter_list|(
name|FieldDecl
modifier|*
name|anonMember
parameter_list|)
block|{
name|CtorOrAnonUnion
operator|=
name|anonMember
expr_stmt|;
block|}
specifier|const
name|CXXConstructorDecl
operator|*
name|getConstructor
argument_list|()
specifier|const
block|{
return|return
name|CtorOrAnonUnion
operator|.
name|dyn_cast
operator|<
name|CXXConstructorDecl
operator|*
operator|>
operator|(
operator|)
return|;
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
comment|/// arg_begin() - Retrieve an iterator to the first initializer argument.
name|arg_iterator
name|arg_begin
parameter_list|()
block|{
return|return
name|Args
return|;
block|}
comment|/// arg_begin() - Retrieve an iterator to the first initializer argument.
name|const_arg_iterator
name|const_arg_begin
argument_list|()
specifier|const
block|{
return|return
name|Args
return|;
block|}
comment|/// arg_end() - Retrieve an iterator past the last initializer argument.
name|arg_iterator
name|arg_end
parameter_list|()
block|{
return|return
name|Args
operator|+
name|NumArgs
return|;
block|}
comment|/// arg_end() - Retrieve an iterator past the last initializer argument.
name|const_arg_iterator
name|const_arg_end
argument_list|()
specifier|const
block|{
return|return
name|Args
operator|+
name|NumArgs
return|;
block|}
comment|/// getNumArgs - Determine the number of arguments used to
comment|/// initialize the member or base.
name|unsigned
name|getNumArgs
argument_list|()
specifier|const
block|{
return|return
name|NumArgs
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
comment|/// Explicit - Whether this constructor is explicit.
name|bool
name|Explicit
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
comment|/// BaseOrMemberInitializers - The arguments used to initialize the base
comment|/// or member.
name|CXXBaseOrMemberInitializer
operator|*
operator|*
name|BaseOrMemberInitializers
block|;
name|unsigned
name|NumBaseOrMemberInitializers
block|;
name|CXXConstructorDecl
argument_list|(
argument|CXXRecordDecl *RD
argument_list|,
argument|SourceLocation L
argument_list|,
argument|DeclarationName N
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
operator|:
name|CXXMethodDecl
argument_list|(
name|CXXConstructor
argument_list|,
name|RD
argument_list|,
name|L
argument_list|,
name|N
argument_list|,
name|T
argument_list|,
name|TInfo
argument_list|,
name|false
argument_list|,
name|isInline
argument_list|)
block|,
name|Explicit
argument_list|(
name|isExplicit
argument_list|)
block|,
name|ImplicitlyDefined
argument_list|(
name|false
argument_list|)
block|,
name|BaseOrMemberInitializers
argument_list|(
literal|0
argument_list|)
block|,
name|NumBaseOrMemberInitializers
argument_list|(
literal|0
argument_list|)
block|{
name|setImplicit
argument_list|(
name|isImplicitlyDeclared
argument_list|)
block|;   }
name|virtual
name|void
name|Destroy
argument_list|(
name|ASTContext
operator|&
name|C
argument_list|)
block|;
name|public
operator|:
specifier|static
name|CXXConstructorDecl
operator|*
name|Create
argument_list|(
argument|ASTContext&C
argument_list|,
argument|CXXRecordDecl *RD
argument_list|,
argument|SourceLocation L
argument_list|,
argument|DeclarationName N
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
comment|/// isExplicit - Whether this constructor was marked "explicit" or not.
name|bool
name|isExplicit
argument_list|()
specifier|const
block|{
return|return
name|Explicit
return|;
block|}
comment|/// isImplicitlyDefined - Whether this constructor was implicitly
comment|/// defined. If false, then this constructor was defined by the
comment|/// user. This operation can only be invoked if the constructor has
comment|/// already been defined.
name|bool
name|isImplicitlyDefined
argument_list|(
argument|ASTContext&C
argument_list|)
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
name|CXXBaseOrMemberInitializer
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
name|CXXBaseOrMemberInitializer
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
name|BaseOrMemberInitializers
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
name|BaseOrMemberInitializers
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
name|BaseOrMemberInitializers
operator|+
name|NumBaseOrMemberInitializers
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
name|BaseOrMemberInitializers
operator|+
name|NumBaseOrMemberInitializers
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
name|getNumBaseOrMemberInitializers
argument_list|()
specifier|const
block|{
return|return
name|NumBaseOrMemberInitializers
return|;
block|}
end_expr_stmt

begin_function
name|void
name|setNumBaseOrMemberInitializers
parameter_list|(
name|unsigned
name|numBaseOrMemberInitializers
parameter_list|)
block|{
name|NumBaseOrMemberInitializers
operator|=
name|numBaseOrMemberInitializers
expr_stmt|;
block|}
end_function

begin_function
name|void
name|setBaseOrMemberInitializers
parameter_list|(
name|CXXBaseOrMemberInitializer
modifier|*
modifier|*
name|initializers
parameter_list|)
block|{
name|BaseOrMemberInitializers
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
comment|/// looks like a copy constructor. Such constructors are never used to copy
end_comment

begin_comment
comment|/// an object.
end_comment

begin_expr_stmt
name|bool
name|isCopyConstructorLikeSpecialization
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
name|D
operator|->
name|getKind
argument_list|()
operator|==
name|CXXConstructor
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
argument|SourceLocation L
argument_list|,
argument|DeclarationName N
argument_list|,
argument|QualType T
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
name|L
argument_list|,
name|N
argument_list|,
name|T
argument_list|,
comment|/*TInfo=*/
literal|0
argument_list|,
name|false
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
argument|ASTContext&C
argument_list|,
argument|CXXRecordDecl *RD
argument_list|,
argument|SourceLocation L
argument_list|,
argument|DeclarationName N
argument_list|,
argument|QualType T
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
name|D
operator|->
name|getKind
argument_list|()
operator|==
name|CXXDestructor
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
expr|}
block|;
comment|/// CXXConversionDecl - Represents a C++ conversion function within a
comment|/// class. For example:
comment|///
comment|/// @code
comment|/// class X {
comment|/// public:
comment|///   operator bool();
comment|/// };
comment|/// @endcode
name|class
name|CXXConversionDecl
operator|:
name|public
name|CXXMethodDecl
block|{
comment|/// Explicit - Whether this conversion function is marked
comment|/// "explicit", meaning that it can only be applied when the user
comment|/// explicitly wrote a cast. This is a C++0x feature.
name|bool
name|Explicit
operator|:
literal|1
block|;
name|CXXConversionDecl
argument_list|(
argument|CXXRecordDecl *RD
argument_list|,
argument|SourceLocation L
argument_list|,
argument|DeclarationName N
argument_list|,
argument|QualType T
argument_list|,
argument|TypeSourceInfo *TInfo
argument_list|,
argument|bool isInline
argument_list|,
argument|bool isExplicit
argument_list|)
operator|:
name|CXXMethodDecl
argument_list|(
name|CXXConversion
argument_list|,
name|RD
argument_list|,
name|L
argument_list|,
name|N
argument_list|,
name|T
argument_list|,
name|TInfo
argument_list|,
name|false
argument_list|,
name|isInline
argument_list|)
block|,
name|Explicit
argument_list|(
argument|isExplicit
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
argument|SourceLocation L
argument_list|,
argument|DeclarationName N
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
comment|/// isExplicit - Whether this is an explicit conversion operator
comment|/// (C++0x only). Explicit conversion operators are only considered
comment|/// when the user has explicitly written a cast.
name|bool
name|isExplicit
argument_list|()
specifier|const
block|{
return|return
name|Explicit
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
name|D
operator|->
name|getKind
argument_list|()
operator|==
name|CXXConversion
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
expr|}
block|;
comment|/// FriendDecl - Represents the declaration of a friend entity,
comment|/// which can be a function, a type, or a templated function or type.
comment|//  For example:
comment|///
comment|/// @code
comment|/// template<typename T> class A {
comment|///   friend int foo(T);
comment|///   friend class B;
comment|///   friend T; // only in C++0x
comment|///   template<typename U> friend class C;
comment|///   template<typename U> friend A& operator+=(A&, const U&) { ... }
comment|/// };
comment|/// @endcode
comment|///
comment|/// The semantic context of a friend decl is its declaring class.
name|class
name|FriendDecl
operator|:
name|public
name|Decl
block|{
name|public
operator|:
typedef|typedef
name|llvm
operator|::
name|PointerUnion
operator|<
name|NamedDecl
operator|*
operator|,
name|Type
operator|*
operator|>
name|FriendUnion
expr_stmt|;
name|private
operator|:
comment|// The declaration that's a friend of this class.
name|FriendUnion
name|Friend
block|;
comment|// Location of the 'friend' specifier.
name|SourceLocation
name|FriendLoc
block|;
comment|// FIXME: Hack to keep track of whether this was a friend function
comment|// template specialization.
name|bool
name|WasSpecialization
block|;
name|FriendDecl
argument_list|(
argument|DeclContext *DC
argument_list|,
argument|SourceLocation L
argument_list|,
argument|FriendUnion Friend
argument_list|,
argument|SourceLocation FriendL
argument_list|)
operator|:
name|Decl
argument_list|(
name|Decl
operator|::
name|Friend
argument_list|,
name|DC
argument_list|,
name|L
argument_list|)
block|,
name|Friend
argument_list|(
name|Friend
argument_list|)
block|,
name|FriendLoc
argument_list|(
name|FriendL
argument_list|)
block|,
name|WasSpecialization
argument_list|(
argument|false
argument_list|)
block|{   }
name|public
operator|:
specifier|static
name|FriendDecl
operator|*
name|Create
argument_list|(
argument|ASTContext&C
argument_list|,
argument|DeclContext *DC
argument_list|,
argument|SourceLocation L
argument_list|,
argument|FriendUnion Friend_
argument_list|,
argument|SourceLocation FriendL
argument_list|)
block|;
comment|/// If this friend declaration names an (untemplated but
comment|/// possibly dependent) type, return the type;  otherwise
comment|/// return null.  This is used only for C++0x's unelaborated
comment|/// friend type declarations.
name|Type
operator|*
name|getFriendType
argument_list|()
specifier|const
block|{
return|return
name|Friend
operator|.
name|dyn_cast
operator|<
name|Type
operator|*
operator|>
operator|(
operator|)
return|;
block|}
comment|/// If this friend declaration doesn't name an unelaborated
comment|/// type, return the inner declaration.
name|NamedDecl
operator|*
name|getFriendDecl
argument_list|()
specifier|const
block|{
return|return
name|Friend
operator|.
name|dyn_cast
operator|<
name|NamedDecl
operator|*
operator|>
operator|(
operator|)
return|;
block|}
comment|/// Retrieves the location of the 'friend' keyword.
name|SourceLocation
name|getFriendLoc
argument_list|()
specifier|const
block|{
return|return
name|FriendLoc
return|;
block|}
name|bool
name|wasSpecialization
argument_list|()
specifier|const
block|{
return|return
name|WasSpecialization
return|;
block|}
name|void
name|setSpecialization
argument_list|(
argument|bool WS
argument_list|)
block|{
name|WasSpecialization
operator|=
name|WS
block|; }
comment|// Implement isa/cast/dyncast/etc.
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
name|Decl
operator|::
name|Friend
return|;
block|}
specifier|static
name|bool
name|classof
argument_list|(
argument|const FriendDecl *D
argument_list|)
block|{
return|return
name|true
return|;
block|}
expr|}
block|;
comment|/// LinkageSpecDecl - This represents a linkage specification.  For example:
comment|///   extern "C" void foo();
comment|///
name|class
name|LinkageSpecDecl
operator|:
name|public
name|Decl
block|,
name|public
name|DeclContext
block|{
name|public
operator|:
comment|/// LanguageIDs - Used to represent the language in a linkage
comment|/// specification.  The values are part of the serialization abi for
comment|/// ASTs and cannot be changed without altering that abi.  To help
comment|/// ensure a stable abi for this, we choose the DW_LANG_ encodings
comment|/// from the dwarf standard.
expr|enum
name|LanguageIDs
block|{
name|lang_c
operator|=
comment|/* DW_LANG_C */
literal|0x0002
block|,
name|lang_cxx
operator|=
comment|/* DW_LANG_C_plus_plus */
literal|0x0004
block|}
block|;
name|private
operator|:
comment|/// Language - The language for this linkage specification.
name|LanguageIDs
name|Language
block|;
comment|/// HadBraces - Whether this linkage specification had curly braces or not.
name|bool
name|HadBraces
operator|:
literal|1
block|;
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
operator|:
name|Decl
argument_list|(
name|LinkageSpec
argument_list|,
name|DC
argument_list|,
name|L
argument_list|)
block|,
name|DeclContext
argument_list|(
name|LinkageSpec
argument_list|)
block|,
name|Language
argument_list|(
name|lang
argument_list|)
block|,
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
block|;
name|LanguageIDs
name|getLanguage
argument_list|()
specifier|const
block|{
return|return
name|Language
return|;
block|}
comment|/// hasBraces - Determines whether this linkage specification had
comment|/// braces in its syntactic form.
name|bool
name|hasBraces
argument_list|()
specifier|const
block|{
return|return
name|HadBraces
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
name|D
operator|->
name|getKind
argument_list|()
operator|==
name|LinkageSpec
return|;
block|}
specifier|static
name|bool
name|classof
argument_list|(
argument|const LinkageSpecDecl *D
argument_list|)
block|{
return|return
name|true
return|;
block|}
specifier|static
name|DeclContext
operator|*
name|castToDeclContext
argument_list|(
argument|const LinkageSpecDecl *D
argument_list|)
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
operator|*
name|castFromDeclContext
argument_list|(
argument|const DeclContext *DC
argument_list|)
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
expr|}
block|;
comment|/// UsingDirectiveDecl - Represents C++ using-directive. For example:
comment|///
comment|///    using namespace std;
comment|///
comment|// NB: UsingDirectiveDecl should be Decl not NamedDecl, but we provide
comment|// artificial name, for all using-directives in order to store
comment|// them in DeclContext effectively.
name|class
name|UsingDirectiveDecl
operator|:
name|public
name|NamedDecl
block|{
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
comment|/// IdentLoc - Location of nominated namespace-name identifier.
comment|// FIXME: We don't store location of scope specifier.
name|SourceLocation
name|IdentLoc
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
argument|SourceLocation L
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
name|Decl
operator|::
name|UsingDirective
argument_list|,
name|DC
argument_list|,
name|L
argument_list|,
name|getName
argument_list|()
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
name|IdentLoc
argument_list|(
name|IdentLoc
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
comment|/// getCommonAncestor - returns common ancestor context of using-directive,
comment|/// and nominated by it namespace.
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
name|IdentLoc
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
argument|SourceLocation L
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
name|Decl
operator|::
name|UsingDirective
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
comment|// Friend for getUsingDirectiveName.
name|friend
name|class
name|DeclContext
block|; }
block|;
comment|/// NamespaceAliasDecl - Represents a C++ namespace alias. For example:
comment|///
comment|/// @code
comment|/// namespace Foo = Bar;
comment|/// @endcode
name|class
name|NamespaceAliasDecl
operator|:
name|public
name|NamedDecl
block|{
name|SourceLocation
name|AliasLoc
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
comment|/// IdentLoc - Location of namespace identifier.
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
argument|SourceLocation L
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
name|Decl
operator|::
name|NamespaceAlias
argument_list|,
name|DC
argument_list|,
name|L
argument_list|,
name|Alias
argument_list|)
block|,
name|AliasLoc
argument_list|(
name|AliasLoc
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
comment|/// \brief Retrieve the namespace that this alias refers to, which
comment|/// may either be a NamespaceDecl or a NamespaceAliasDecl.
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
specifier|static
name|NamespaceAliasDecl
operator|*
name|Create
argument_list|(
argument|ASTContext&C
argument_list|,
argument|DeclContext *DC
argument_list|,
argument|SourceLocation L
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
name|Decl
operator|::
name|NamespaceAlias
return|;
block|}
specifier|static
name|bool
name|classof
argument_list|(
argument|const NamespaceAliasDecl *D
argument_list|)
block|{
return|return
name|true
return|;
block|}
expr|}
block|;
comment|/// UsingShadowDecl - Represents a shadow declaration introduced into
comment|/// a scope by a (resolved) using declaration.  For example,
comment|///
comment|/// namespace A {
comment|///   void foo();
comment|/// }
comment|/// namespace B {
comment|///   using A::foo(); //<- a UsingDecl
comment|///                   // Also creates a UsingShadowDecl for A::foo in B
comment|/// }
comment|///
name|class
name|UsingShadowDecl
operator|:
name|public
name|NamedDecl
block|{
comment|/// The referenced declaration.
name|NamedDecl
operator|*
name|Underlying
block|;
comment|/// The using declaration which introduced this decl.
name|UsingDecl
operator|*
name|Using
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
name|Target
operator|->
name|getDeclName
argument_list|()
argument_list|)
block|,
name|Underlying
argument_list|(
name|Target
argument_list|)
block|,
name|Using
argument_list|(
argument|Using
argument_list|)
block|{
name|IdentifierNamespace
operator|=
name|Target
operator|->
name|getIdentifierNamespace
argument_list|()
block|;
name|setImplicit
argument_list|()
block|;   }
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
comment|/// Gets the underlying declaration which has been brought into the
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
comment|/// Gets the using declaration to which this declaration is tied.
name|UsingDecl
operator|*
name|getUsingDecl
argument_list|()
specifier|const
block|{
return|return
name|Using
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
name|D
operator|->
name|getKind
argument_list|()
operator|==
name|Decl
operator|::
name|UsingShadow
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
expr|}
block|;
comment|/// UsingDecl - Represents a C++ using-declaration. For example:
comment|///    using someNameSpace::someIdentifier;
name|class
name|UsingDecl
operator|:
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
comment|/// \brief The collection of shadow declarations associated with
comment|/// this using declaration.  This set can change as a class is
comment|/// processed.
name|llvm
operator|::
name|SmallPtrSet
operator|<
name|UsingShadowDecl
operator|*
block|,
literal|8
operator|>
name|Shadows
block|;
comment|// \brief Has 'typename' keyword.
name|bool
name|IsTypeName
block|;
name|UsingDecl
argument_list|(
argument|DeclContext *DC
argument_list|,
argument|SourceLocation L
argument_list|,
argument|SourceRange NNR
argument_list|,
argument|SourceLocation UL
argument_list|,
argument|NestedNameSpecifier* TargetNNS
argument_list|,
argument|DeclarationName Name
argument_list|,
argument|bool IsTypeNameArg
argument_list|)
operator|:
name|NamedDecl
argument_list|(
name|Decl
operator|::
name|Using
argument_list|,
name|DC
argument_list|,
name|L
argument_list|,
name|Name
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
block|{
return|return
name|NestedNameRange
return|;
block|}
comment|/// \brief Returns the source location of the "using" location itself.
name|SourceLocation
name|getUsingLocation
argument_list|()
block|{
return|return
name|UsingLocation
return|;
block|}
comment|/// \brief Get target nested name declaration.
name|NestedNameSpecifier
operator|*
name|getTargetNestedNameDecl
argument_list|()
block|{
return|return
name|TargetNestedName
return|;
block|}
comment|/// isTypeName - Return true if using decl has 'typename'.
name|bool
name|isTypeName
argument_list|()
specifier|const
block|{
return|return
name|IsTypeName
return|;
block|}
typedef|typedef
name|llvm
operator|::
name|SmallPtrSet
operator|<
name|UsingShadowDecl
operator|*
operator|,
literal|8
operator|>
operator|::
name|const_iterator
name|shadow_iterator
expr_stmt|;
name|shadow_iterator
name|shadow_begin
argument_list|()
specifier|const
block|{
return|return
name|Shadows
operator|.
name|begin
argument_list|()
return|;
block|}
name|shadow_iterator
name|shadow_end
argument_list|()
specifier|const
block|{
return|return
name|Shadows
operator|.
name|end
argument_list|()
return|;
block|}
name|void
name|addShadowDecl
argument_list|(
argument|UsingShadowDecl *S
argument_list|)
block|{
name|assert
argument_list|(
name|S
operator|->
name|getUsingDecl
argument_list|()
operator|==
name|this
argument_list|)
block|;
if|if
condition|(
operator|!
name|Shadows
operator|.
name|insert
argument_list|(
name|S
argument_list|)
condition|)
block|{
name|assert
argument_list|(
name|false
operator|&&
literal|"declaration already in set"
argument_list|)
expr_stmt|;
block|}
block|}
name|void
name|removeShadowDecl
argument_list|(
argument|UsingShadowDecl *S
argument_list|)
block|{
name|assert
argument_list|(
name|S
operator|->
name|getUsingDecl
argument_list|()
operator|==
name|this
argument_list|)
block|;
if|if
condition|(
operator|!
name|Shadows
operator|.
name|erase
argument_list|(
name|S
argument_list|)
condition|)
block|{
name|assert
argument_list|(
name|false
operator|&&
literal|"declaration not in set"
argument_list|)
expr_stmt|;
block|}
block|}
specifier|static
name|UsingDecl
operator|*
name|Create
argument_list|(
argument|ASTContext&C
argument_list|,
argument|DeclContext *DC
argument_list|,
argument|SourceLocation IdentL
argument_list|,
argument|SourceRange NNR
argument_list|,
argument|SourceLocation UsingL
argument_list|,
argument|NestedNameSpecifier* TargetNNS
argument_list|,
argument|DeclarationName Name
argument_list|,
argument|bool IsTypeNameArg
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
name|Decl
operator|::
name|Using
return|;
block|}
specifier|static
name|bool
name|classof
argument_list|(
argument|const UsingDecl *D
argument_list|)
block|{
return|return
name|true
return|;
block|}
expr|}
block|;
comment|/// UnresolvedUsingValueDecl - Represents a dependent using
comment|/// declaration which was not marked with 'typename'.  Unlike
comment|/// non-dependent using declarations, these *only* bring through
comment|/// non-types; otherwise they would break two-phase lookup.
comment|///
comment|/// template<class T> class A : public Base<T> {
comment|///   using Base<T>::foo;
comment|/// };
name|class
name|UnresolvedUsingValueDecl
operator|:
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
argument|SourceLocation TargetNameLoc
argument_list|,
argument|DeclarationName TargetName
argument_list|)
operator|:
name|ValueDecl
argument_list|(
name|Decl
operator|::
name|UnresolvedUsingValue
argument_list|,
name|DC
argument_list|,
name|TargetNameLoc
argument_list|,
name|TargetName
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
argument|TargetNNS
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
argument|SourceLocation TargetNameLoc
argument_list|,
argument|DeclarationName TargetName
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
name|Decl
operator|::
name|UnresolvedUsingValue
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
expr|}
block|;
comment|/// UnresolvedUsingTypenameDecl - Represents a dependent using
comment|/// declaration which was marked with 'typename'.
comment|///
comment|/// template<class T> class A : public Base<T> {
comment|///   using typename Base<T>::foo;
comment|/// };
comment|///
comment|/// The type associated with a unresolved using typename decl is
comment|/// currently always a typename type.
name|class
name|UnresolvedUsingTypenameDecl
operator|:
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
name|Decl
operator|::
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
name|Decl
operator|::
name|UnresolvedUsingTypename
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
name|virtual
operator|~
name|StaticAssertDecl
argument_list|()
block|;
name|virtual
name|void
name|Destroy
argument_list|(
name|ASTContext
operator|&
name|C
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
name|Decl
operator|::
name|StaticAssert
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
expr|}
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

