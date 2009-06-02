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
file|"clang/AST/Decl.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/SmallVector.h"
end_include

begin_decl_stmt
name|namespace
name|clang
block|{
name|class
name|ClassTemplateDecl
decl_stmt|;
name|class
name|CXXRecordDecl
decl_stmt|;
name|class
name|CXXConstructorDecl
decl_stmt|;
name|class
name|CXXDestructorDecl
decl_stmt|;
name|class
name|CXXConversionDecl
decl_stmt|;
name|class
name|CXXMethodDecl
decl_stmt|;
name|class
name|ClassTemplateSpecializationDecl
decl_stmt|;
comment|/// OverloadedFunctionDecl - An instance of this class represents a
comment|/// set of overloaded functions. All of the functions have the same
comment|/// name and occur within the same scope.
comment|///
comment|/// An OverloadedFunctionDecl has no ownership over the FunctionDecl
comment|/// nodes it contains. Rather, the FunctionDecls are owned by the
comment|/// enclosing scope (which also owns the OverloadedFunctionDecl
comment|/// node). OverloadedFunctionDecl is used primarily to store a set of
comment|/// overloaded functions for name lookup.
name|class
name|OverloadedFunctionDecl
range|:
name|public
name|NamedDecl
block|{
name|protected
operator|:
name|OverloadedFunctionDecl
argument_list|(
argument|DeclContext *DC
argument_list|,
argument|DeclarationName N
argument_list|)
operator|:
name|NamedDecl
argument_list|(
argument|OverloadedFunction
argument_list|,
argument|DC
argument_list|,
argument|SourceLocation()
argument_list|,
argument|N
argument_list|)
block|{ }
comment|/// Functions - the set of overloaded functions contained in this
comment|/// overload set.
name|llvm
operator|::
name|SmallVector
operator|<
name|FunctionDecl
operator|*
block|,
literal|4
operator|>
name|Functions
block|;
comment|// FIXME: This should go away when we stop using
comment|// OverloadedFunctionDecl to store conversions in CXXRecordDecl.
name|friend
name|class
name|CXXRecordDecl
block|;
name|public
operator|:
typedef|typedef
name|llvm
operator|::
name|SmallVector
operator|<
name|FunctionDecl
operator|*
operator|,
literal|4
operator|>
operator|::
name|iterator
name|function_iterator
expr_stmt|;
typedef|typedef
name|llvm
operator|::
name|SmallVector
operator|<
name|FunctionDecl
operator|*
operator|,
literal|4
operator|>
operator|::
name|const_iterator
name|function_const_iterator
expr_stmt|;
specifier|static
name|OverloadedFunctionDecl
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
name|DeclarationName
name|N
parameter_list|)
function_decl|;
comment|/// addOverload - Add an overloaded function FD to this set of
comment|/// overloaded functions.
name|void
name|addOverload
parameter_list|(
name|FunctionDecl
modifier|*
name|FD
parameter_list|)
block|{
name|assert
argument_list|(
operator|(
name|FD
operator|->
name|getDeclName
argument_list|()
operator|==
name|getDeclName
argument_list|()
operator|||
name|isa
operator|<
name|CXXConversionDecl
operator|>
operator|(
name|FD
operator|)
operator|||
name|isa
operator|<
name|CXXConstructorDecl
operator|>
operator|(
name|FD
operator|)
operator|)
operator|&&
literal|"Overloaded functions must have the same name"
argument_list|)
expr_stmt|;
name|Functions
operator|.
name|push_back
argument_list|(
name|FD
argument_list|)
expr_stmt|;
comment|// An overloaded function declaration always has the location of
comment|// the most-recently-added function declaration.
if|if
condition|(
name|FD
operator|->
name|getLocation
argument_list|()
operator|.
name|isValid
argument_list|()
condition|)
name|this
operator|->
name|setLocation
argument_list|(
name|FD
operator|->
name|getLocation
argument_list|()
argument_list|)
expr_stmt|;
block|}
name|function_iterator
name|function_begin
parameter_list|()
block|{
return|return
name|Functions
operator|.
name|begin
argument_list|()
return|;
block|}
name|function_iterator
name|function_end
parameter_list|()
block|{
return|return
name|Functions
operator|.
name|end
argument_list|()
return|;
block|}
name|function_const_iterator
name|function_begin
argument_list|()
specifier|const
block|{
return|return
name|Functions
operator|.
name|begin
argument_list|()
return|;
block|}
name|function_const_iterator
name|function_end
argument_list|()
specifier|const
block|{
return|return
name|Functions
operator|.
name|end
argument_list|()
return|;
block|}
comment|/// getNumFunctions - the number of overloaded functions stored in
comment|/// this set.
name|unsigned
name|getNumFunctions
argument_list|()
specifier|const
block|{
return|return
name|Functions
operator|.
name|size
argument_list|()
return|;
block|}
comment|/// getFunction - retrieve the ith function in the overload set.
specifier|const
name|FunctionDecl
modifier|*
name|getFunction
argument_list|(
name|unsigned
name|i
argument_list|)
decl|const
block|{
name|assert
argument_list|(
name|i
operator|<
name|getNumFunctions
argument_list|()
operator|&&
literal|"Illegal function #"
argument_list|)
expr_stmt|;
return|return
name|Functions
index|[
name|i
index|]
return|;
block|}
name|FunctionDecl
modifier|*
name|getFunction
parameter_list|(
name|unsigned
name|i
parameter_list|)
block|{
name|assert
argument_list|(
name|i
operator|<
name|getNumFunctions
argument_list|()
operator|&&
literal|"Illegal function #"
argument_list|)
expr_stmt|;
return|return
name|Functions
index|[
name|i
index|]
return|;
block|}
comment|// getDeclContext - Get the context of these overloaded functions.
name|DeclContext
modifier|*
name|getDeclContext
parameter_list|()
block|{
name|assert
argument_list|(
name|getNumFunctions
argument_list|()
operator|>
literal|0
operator|&&
literal|"Context of an empty overload set"
argument_list|)
expr_stmt|;
return|return
name|getFunction
argument_list|(
literal|0
argument_list|)
operator|->
name|getDeclContext
argument_list|()
return|;
block|}
comment|// Implement isa/cast/dyncast/etc.
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
name|OverloadedFunction
return|;
block|}
specifier|static
name|bool
name|classof
parameter_list|(
specifier|const
name|OverloadedFunctionDecl
modifier|*
name|D
parameter_list|)
block|{
return|return
name|true
return|;
block|}
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|/// CXXBaseSpecifier - A base class of a C++ class.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Each CXXBaseSpecifier represents a single, direct base class (or
end_comment

begin_comment
comment|/// struct) of a C++ class (or struct). It specifies the type of that
end_comment

begin_comment
comment|/// base class, whether it is a virtual or non-virtual base, and what
end_comment

begin_comment
comment|/// level of access (public, protected, private) is used for the
end_comment

begin_comment
comment|/// derivation. For example:
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// @code
end_comment

begin_comment
comment|///   class A { };
end_comment

begin_comment
comment|///   class B { };
end_comment

begin_comment
comment|///   class C : public virtual A, protected B { };
end_comment

begin_comment
comment|/// @endcode
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// In this code, C will have two CXXBaseSpecifiers, one for "public
end_comment

begin_comment
comment|/// virtual A" and the other for "protected B".
end_comment

begin_decl_stmt
name|class
name|CXXBaseSpecifier
block|{
comment|/// Range - The source code range that covers the full base
comment|/// specifier, including the "virtual" (if present) and access
comment|/// specifier (if present).
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
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|/// CXXRecordDecl - Represents a C++ struct/union/class.
end_comment

begin_comment
comment|/// FIXME: This class will disappear once we've properly taught RecordDecl
end_comment

begin_comment
comment|/// to deal with C++-specific things.
end_comment

begin_decl_stmt
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
comment|/// HasTrivialConstructor - True when this class has a trivial constructor
name|bool
name|HasTrivialConstructor
operator|:
literal|1
block|;
comment|/// HasTrivialDestructor - True when this class has a trivial destructor
name|bool
name|HasTrivialDestructor
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
comment|/// Conversions - Overload set containing the conversion functions
comment|/// of this C++ class (but not its inherited conversion
comment|/// functions). Each of the entries in this overload set is a
comment|/// CXXConversionDecl.
name|OverloadedFunctionDecl
name|Conversions
block|;
comment|/// \brief The template or declaration that this declaration
comment|/// describes or was instantiated from, respectively.
comment|///
comment|/// For non-templates, this value will be NULL. For record
comment|/// declarations that describe a class template, this will be a
comment|/// pointer to a ClassTemplateDecl. For member
comment|/// classes of class template specializations, this will be the
comment|/// RecordDecl from which the member class was instantiated.
name|llvm
operator|::
name|PointerUnion
operator|<
name|ClassTemplateDecl
operator|*
block|,
name|CXXRecordDecl
operator|*
operator|>
name|TemplateOrInstantiation
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
argument_list|)
block|;
operator|~
name|CXXRecordDecl
argument_list|()
block|;
name|public
operator|:
comment|/// base_class_iterator - Iterator that traverses the base classes
comment|/// of a clas.
typedef|typedef
name|CXXBaseSpecifier
modifier|*
name|base_class_iterator
typedef|;
end_decl_stmt

begin_comment
comment|/// base_class_const_iterator - Iterator that traverses the base
end_comment

begin_comment
comment|/// classes of a clas.
end_comment

begin_typedef
typedef|typedef
specifier|const
name|CXXBaseSpecifier
modifier|*
name|base_class_const_iterator
typedef|;
end_typedef

begin_function_decl
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
name|Bases
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
name|Bases
return|;
block|}
end_expr_stmt

begin_function
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
end_function

begin_expr_stmt
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
name|ASTContext
operator|&
name|Context
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// hasConstCopyAssignment - Determines whether this class has a
end_comment

begin_comment
comment|/// copy assignment operator that accepts a const-qualified argument.
end_comment

begin_decl_stmt
name|bool
name|hasConstCopyAssignment
argument_list|(
name|ASTContext
operator|&
name|Context
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// addedConstructor - Notify the class that another constructor has
end_comment

begin_comment
comment|/// been added. This routine helps maintain information about the
end_comment

begin_comment
comment|/// class based on which constructors have been added.
end_comment

begin_function_decl
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
end_function_decl

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
name|UserDeclaredCopyConstructor
return|;
block|}
end_expr_stmt

begin_comment
comment|/// addedAssignmentOperator - Notify the class that another assignment
end_comment

begin_comment
comment|/// operator has been added. This routine helps maintain information about the
end_comment

begin_comment
comment|/// class based on which operators have been added.
end_comment

begin_function_decl
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
end_function_decl

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
name|UserDeclaredCopyAssignment
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
name|UserDeclaredDestructor
return|;
block|}
end_expr_stmt

begin_comment
comment|/// setUserDeclaredDestructor - Set whether this class has a
end_comment

begin_comment
comment|/// user-declared destructor. If not set by the time the class is
end_comment

begin_comment
comment|/// fully defined, a destructor will be implicitly declared.
end_comment

begin_function
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
end_function

begin_comment
comment|/// getConversions - Retrieve the overload set containing all of the
end_comment

begin_comment
comment|/// conversion functions in this class.
end_comment

begin_function
name|OverloadedFunctionDecl
modifier|*
name|getConversionFunctions
parameter_list|()
block|{
return|return
operator|&
name|Conversions
return|;
block|}
end_function

begin_expr_stmt
specifier|const
name|OverloadedFunctionDecl
operator|*
name|getConversionFunctions
argument_list|()
specifier|const
block|{
return|return
operator|&
name|Conversions
return|;
block|}
end_expr_stmt

begin_comment
comment|/// addConversionFunction - Add a new conversion function to the
end_comment

begin_comment
comment|/// list of conversion functions.
end_comment

begin_function_decl
name|void
name|addConversionFunction
parameter_list|(
name|ASTContext
modifier|&
name|Context
parameter_list|,
name|CXXConversionDecl
modifier|*
name|ConvDecl
parameter_list|)
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
name|Aggregate
return|;
block|}
end_expr_stmt

begin_comment
comment|/// setAggregate - Set whether this class is an aggregate (C++
end_comment

begin_comment
comment|/// [dcl.init.aggr]).
end_comment

begin_function
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
end_function

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
name|PlainOldData
return|;
block|}
end_expr_stmt

begin_comment
comment|/// setPOD - Set whether this class is a POD-type (C++ [class]p4).
end_comment

begin_function
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
end_function

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
name|Polymorphic
return|;
block|}
end_expr_stmt

begin_comment
comment|/// setPolymorphic - Set whether this class is polymorphic (C++
end_comment

begin_comment
comment|/// [class.virtual]).
end_comment

begin_function
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
end_function

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
name|Abstract
return|;
block|}
end_expr_stmt

begin_comment
comment|/// setAbstract - Set whether this class is abstract (C++ [class.abstract])
end_comment

begin_function
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
end_function

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
name|HasTrivialConstructor
return|;
block|}
end_expr_stmt

begin_comment
comment|// setHasTrivialConstructor - Set whether this class has a trivial constructor
end_comment

begin_comment
comment|// (C++ [class.ctor]p5)
end_comment

begin_function
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
end_function

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
name|HasTrivialDestructor
return|;
block|}
end_expr_stmt

begin_comment
comment|// setHasTrivialDestructor - Set whether this class has a trivial destructor
end_comment

begin_comment
comment|// (C++ [class.dtor]p3)
end_comment

begin_function
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
end_function

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
block|{
return|return
name|TemplateOrInstantiation
operator|.
name|dyn_cast
operator|<
name|CXXRecordDecl
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
comment|/// member class RD.
end_comment

begin_function
name|void
name|setInstantiationOfMemberClass
parameter_list|(
name|CXXRecordDecl
modifier|*
name|RD
parameter_list|)
block|{
name|TemplateOrInstantiation
operator|=
name|RD
expr_stmt|;
block|}
end_function

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
comment|/// getDestructor - Returns the destructor decl for this class.
end_comment

begin_function_decl
specifier|const
name|CXXDestructorDecl
modifier|*
name|getDestructor
parameter_list|(
name|ASTContext
modifier|&
name|Context
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
name|isOutOfLineDefinition
argument_list|()
specifier|const
block|{
return|return
name|getLexicalDeclContext
argument_list|()
operator|!=
name|getDeclContext
argument_list|()
return|;
block|}
name|bool
name|isVirtual
argument_list|()
specifier|const
block|{
return|return
name|isVirtualAsWritten
argument_list|()
operator|||
operator|(
name|begin_overridden_methods
argument_list|()
operator|!=
name|end_overridden_methods
argument_list|()
operator|)
return|;
block|}
comment|///
name|void
name|addOverriddenMethod
argument_list|(
specifier|const
name|CXXMethodDecl
operator|*
name|MD
argument_list|)
block|;
typedef|typedef
specifier|const
name|CXXMethodDecl
modifier|*
modifier|*
name|method_iterator
typedef|;
name|method_iterator
name|begin_overridden_methods
argument_list|()
specifier|const
decl_stmt|;
end_decl_stmt

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
name|getAsFunctionProtoType
argument_list|()
operator|->
name|getTypeQuals
argument_list|()
return|;
block|}
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

begin_decl_stmt
name|class
name|CXXBaseOrMemberInitializer
block|{
comment|/// BaseOrMember - This points to the entity being initialized,
comment|/// which is either a base class (a Type) or a non-static data
comment|/// member. When the low bit is 1, it's a base
comment|/// class; when the low bit is 0, it's a member.
name|uintptr_t
name|BaseOrMember
decl_stmt|;
comment|/// Args - The arguments used to initialize the base or member.
name|Expr
modifier|*
modifier|*
name|Args
decl_stmt|;
name|unsigned
name|NumArgs
decl_stmt|;
name|public
label|:
comment|/// CXXBaseOrMemberInitializer - Creates a new base-class initializer.
name|explicit
name|CXXBaseOrMemberInitializer
parameter_list|(
name|QualType
name|BaseType
parameter_list|,
name|Expr
modifier|*
modifier|*
name|Args
parameter_list|,
name|unsigned
name|NumArgs
parameter_list|)
function_decl|;
comment|/// CXXBaseOrMemberInitializer - Creates a new member initializer.
name|explicit
name|CXXBaseOrMemberInitializer
parameter_list|(
name|FieldDecl
modifier|*
name|Member
parameter_list|,
name|Expr
modifier|*
modifier|*
name|Args
parameter_list|,
name|unsigned
name|NumArgs
parameter_list|)
function_decl|;
comment|/// ~CXXBaseOrMemberInitializer - Destroy the base or member initializer.
operator|~
name|CXXBaseOrMemberInitializer
argument_list|()
expr_stmt|;
comment|/// arg_iterator - Iterates through the member initialization
comment|/// arguments.
typedef|typedef
name|Expr
modifier|*
modifier|*
name|arg_iterator
typedef|;
comment|/// arg_const_iterator - Iterates through the member initialization
comment|/// arguments.
typedef|typedef
name|Expr
modifier|*
specifier|const
modifier|*
name|arg_const_iterator
typedef|;
comment|/// isBaseInitializer - Returns true when this initializer is
comment|/// initializing a base class.
name|bool
name|isBaseInitializer
argument_list|()
specifier|const
block|{
return|return
operator|(
name|BaseOrMember
operator|&
literal|0x1
operator|)
operator|!=
literal|0
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
operator|(
name|BaseOrMember
operator|&
literal|0x1
operator|)
operator|==
literal|0
return|;
block|}
comment|/// getBaseClass - If this is a base class initializer, returns the
comment|/// type used to specify the initializer. The resulting type will be
comment|/// a class type or a typedef of a class type. If this is not a base
comment|/// class initializer, returns NULL.
name|Type
modifier|*
name|getBaseClass
parameter_list|()
block|{
if|if
condition|(
name|isBaseInitializer
argument_list|()
condition|)
return|return
name|reinterpret_cast
operator|<
name|Type
operator|*
operator|>
operator|(
name|BaseOrMember
operator|&
operator|~
literal|0x01
operator|)
return|;
else|else
return|return
literal|0
return|;
block|}
comment|/// getBaseClass - If this is a base class initializer, returns the
comment|/// type used to specify the initializer. The resulting type will be
comment|/// a class type or a typedef of a class type. If this is not a base
comment|/// class initializer, returns NULL.
specifier|const
name|Type
operator|*
name|getBaseClass
argument_list|()
specifier|const
block|{
if|if
condition|(
name|isBaseInitializer
argument_list|()
condition|)
return|return
name|reinterpret_cast
operator|<
specifier|const
name|Type
operator|*
operator|>
operator|(
name|BaseOrMember
operator|&
operator|~
literal|0x01
operator|)
return|;
else|else
return|return
literal|0
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
name|reinterpret_cast
operator|<
name|FieldDecl
operator|*
operator|>
operator|(
name|BaseOrMember
operator|)
return|;
else|else
return|return
literal|0
return|;
block|}
comment|/// begin() - Retrieve an iterator to the first initializer argument.
name|arg_iterator
name|begin
parameter_list|()
block|{
return|return
name|Args
return|;
block|}
comment|/// begin() - Retrieve an iterator to the first initializer argument.
name|arg_const_iterator
name|begin
argument_list|()
specifier|const
block|{
return|return
name|Args
return|;
block|}
comment|/// end() - Retrieve an iterator past the last initializer argument.
name|arg_iterator
name|end
parameter_list|()
block|{
return|return
name|Args
operator|+
name|NumArgs
return|;
block|}
comment|/// end() - Retrieve an iterator past the last initializer argument.
name|arg_const_iterator
name|end
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
comment|/// FIXME: Add support for base and member initializers.
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
argument|false
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
argument|CXXRecordDecl *RD
argument_list|,
argument|SourceLocation L
argument_list|,
argument|DeclarationName N
argument_list|,
argument|QualType T
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
literal|"Can only get the implicit-definition flag once the constructor has been defined"
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
literal|"Can only set the implicit-definition flag once the constructor has been defined"
argument_list|)
block|;
name|ImplicitlyDefined
operator|=
name|ID
block|;    }
comment|/// isDefaultConstructor - Whether this constructor is a default
comment|/// constructor (C++ [class.ctor]p5), which can be used to
comment|/// default-initialize a class of this type.
name|bool
name|isDefaultConstructor
argument_list|()
specifier|const
block|;
comment|/// isCopyConstructor - Whether this constructor is a copy
comment|/// constructor (C++ [class.copy]p2, which can be used to copy the
comment|/// class. @p TypeQuals will be set to the qualifiers on the
comment|/// argument type. For example, @p TypeQuals would be set to @c
comment|/// QualType::Const for the following copy constructor:
comment|///
comment|/// @code
comment|/// class X {
comment|/// public:
comment|///   X(const X&);
comment|/// };
comment|/// @endcode
name|bool
name|isCopyConstructor
argument_list|(
argument|ASTContext&Context
argument_list|,
argument|unsigned&TypeQuals
argument_list|)
specifier|const
block|;
comment|/// isCopyConstructor - Whether this constructor is a copy
comment|/// constructor (C++ [class.copy]p2, which can be used to copy the
comment|/// class.
name|bool
name|isCopyConstructor
argument_list|(
argument|ASTContext&Context
argument_list|)
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
name|Context
argument_list|,
name|TypeQuals
argument_list|)
return|;
block|}
comment|/// isConvertingConstructor - Whether this constructor is a
comment|/// converting constructor (C++ [class.conv.ctor]), which can be
comment|/// used for user-defined conversions.
name|bool
name|isConvertingConstructor
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
name|D
operator|->
name|getKind
argument_list|()
operator|==
name|CXXConstructor
return|;
block|}
specifier|static
name|bool
name|classof
argument_list|(
argument|const CXXConstructorDecl *D
argument_list|)
block|{
return|return
name|true
return|;
block|}
expr|}
block|;
comment|/// CXXDestructorDecl - Represents a C++ destructor within a
comment|/// class. For example:
comment|///
comment|/// @code
comment|/// class X {
comment|/// public:
comment|///   ~X(); // represented by a CXXDestructorDecl.
comment|/// };
comment|/// @endcode
name|class
name|CXXDestructorDecl
operator|:
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
name|false
argument_list|,
name|isInline
argument_list|)
block|,
name|ImplicitlyDefined
argument_list|(
argument|false
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
block|;    }
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
name|getAsFunctionType
argument_list|()
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
name|NamespaceDecl
operator|*
name|NominatedNamespace
block|;
comment|/// Enclosing context containing both using-directive and nomintated
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
argument|NamespaceDecl *Nominated
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
condition|?
name|Nominated
operator|->
name|getOriginalNamespace
argument_list|()
else|:
literal|0
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
comment|/// getNominatedNamespace - Returns namespace nominated by using-directive.
name|NamespaceDecl
operator|*
name|getNominatedNamespace
argument_list|()
block|{
return|return
name|NominatedNamespace
return|;
block|}
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
argument|NamespaceDecl *Nominated
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
block|;    }
end_decl_stmt

begin_comment
comment|// end namespace clang
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

