begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===--- Lookup.h - Classes for name lookup ---------------------*- C++ -*-===//
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
comment|// This file defines the LookupResult class, which is integral to
end_comment

begin_comment
comment|// Sema's name-lookup subsystem.
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
name|LLVM_CLANG_SEMA_LOOKUP_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_SEMA_LOOKUP_H
end_define

begin_include
include|#
directive|include
file|"Sema.h"
end_include

begin_decl_stmt
name|namespace
name|clang
block|{
comment|/// @brief Represents the results of name lookup.
comment|///
comment|/// An instance of the LookupResult class captures the results of a
comment|/// single name lookup, which can return no result (nothing found),
comment|/// a single declaration, a set of overloaded functions, or an
comment|/// ambiguity. Use the getKind() method to determine which of these
comment|/// results occurred for a given lookup.
name|class
name|LookupResult
block|{
name|public
label|:
enum|enum
name|LookupResultKind
block|{
comment|/// @brief No entity found met the criteria.
name|NotFound
init|=
literal|0
block|,
comment|/// @brief No entity found met the criteria within the current
comment|/// instantiation,, but there were dependent base classes of the
comment|/// current instantiation that could not be searched.
name|NotFoundInCurrentInstantiation
block|,
comment|/// @brief Name lookup found a single declaration that met the
comment|/// criteria.  getFoundDecl() will return this declaration.
name|Found
block|,
comment|/// @brief Name lookup found a set of overloaded functions that
comment|/// met the criteria.
name|FoundOverloaded
block|,
comment|/// @brief Name lookup found an unresolvable value declaration
comment|/// and cannot yet complete.  This only happens in C++ dependent
comment|/// contexts with dependent using declarations.
name|FoundUnresolvedValue
block|,
comment|/// @brief Name lookup results in an ambiguity; use
comment|/// getAmbiguityKind to figure out what kind of ambiguity
comment|/// we have.
name|Ambiguous
block|}
enum|;
enum|enum
name|AmbiguityKind
block|{
comment|/// Name lookup results in an ambiguity because multiple
comment|/// entities that meet the lookup criteria were found in
comment|/// subobjects of different types. For example:
comment|/// @code
comment|/// struct A { void f(int); }
comment|/// struct B { void f(double); }
comment|/// struct C : A, B { };
comment|/// void test(C c) {
comment|///   c.f(0); // error: A::f and B::f come from subobjects of different
comment|///           // types. overload resolution is not performed.
comment|/// }
comment|/// @endcode
name|AmbiguousBaseSubobjectTypes
block|,
comment|/// Name lookup results in an ambiguity because multiple
comment|/// nonstatic entities that meet the lookup criteria were found
comment|/// in different subobjects of the same type. For example:
comment|/// @code
comment|/// struct A { int x; };
comment|/// struct B : A { };
comment|/// struct C : A { };
comment|/// struct D : B, C { };
comment|/// int test(D d) {
comment|///   return d.x; // error: 'x' is found in two A subobjects (of B and C)
comment|/// }
comment|/// @endcode
name|AmbiguousBaseSubobjects
block|,
comment|/// Name lookup results in an ambiguity because multiple definitions
comment|/// of entity that meet the lookup criteria were found in different
comment|/// declaration contexts.
comment|/// @code
comment|/// namespace A {
comment|///   int i;
comment|///   namespace B { int i; }
comment|///   int test() {
comment|///     using namespace B;
comment|///     return i; // error 'i' is found in namespace A and A::B
comment|///    }
comment|/// }
comment|/// @endcode
name|AmbiguousReference
block|,
comment|/// Name lookup results in an ambiguity because an entity with a
comment|/// tag name was hidden by an entity with an ordinary name from
comment|/// a different context.
comment|/// @code
comment|/// namespace A { struct Foo {}; }
comment|/// namespace B { void Foo(); }
comment|/// namespace C {
comment|///   using namespace A;
comment|///   using namespace B;
comment|/// }
comment|/// void test() {
comment|///   C::Foo(); // error: tag 'A::Foo' is hidden by an object in a
comment|///             // different namespace
comment|/// }
comment|/// @endcode
name|AmbiguousTagHiding
block|}
enum|;
comment|/// A little identifier for flagging temporary lookup results.
enum|enum
name|TemporaryToken
block|{
name|Temporary
block|}
enum|;
typedef|typedef
name|UnresolvedSetImpl
operator|::
name|iterator
name|iterator
expr_stmt|;
typedef|typedef
name|bool
function_decl|(
modifier|*
name|ResultFilter
function_decl|)
parameter_list|(
name|NamedDecl
modifier|*
parameter_list|,
name|unsigned
name|IDNS
parameter_list|)
function_decl|;
name|LookupResult
argument_list|(
argument|Sema&SemaRef
argument_list|,
argument|DeclarationName Name
argument_list|,
argument|SourceLocation NameLoc
argument_list|,
argument|Sema::LookupNameKind LookupKind
argument_list|,
argument|Sema::RedeclarationKind Redecl = Sema::NotForRedeclaration
argument_list|)
block|:
name|ResultKind
argument_list|(
name|NotFound
argument_list|)
operator|,
name|Paths
argument_list|(
literal|0
argument_list|)
operator|,
name|NamingClass
argument_list|(
literal|0
argument_list|)
operator|,
name|SemaRef
argument_list|(
name|SemaRef
argument_list|)
operator|,
name|Name
argument_list|(
name|Name
argument_list|)
operator|,
name|NameLoc
argument_list|(
name|NameLoc
argument_list|)
operator|,
name|LookupKind
argument_list|(
name|LookupKind
argument_list|)
operator|,
name|IsAcceptableFn
argument_list|(
literal|0
argument_list|)
operator|,
name|IDNS
argument_list|(
literal|0
argument_list|)
operator|,
name|Redecl
argument_list|(
name|Redecl
operator|!=
name|Sema
operator|::
name|NotForRedeclaration
argument_list|)
operator|,
name|HideTags
argument_list|(
name|true
argument_list|)
operator|,
name|Diagnose
argument_list|(
argument|Redecl == Sema::NotForRedeclaration
argument_list|)
block|{
name|configure
argument_list|()
block|;   }
comment|/// Creates a temporary lookup result, initializing its core data
comment|/// using the information from another result.  Diagnostics are always
comment|/// disabled.
name|LookupResult
argument_list|(
argument|TemporaryToken _
argument_list|,
argument|const LookupResult&Other
argument_list|)
operator|:
name|ResultKind
argument_list|(
name|NotFound
argument_list|)
operator|,
name|Paths
argument_list|(
literal|0
argument_list|)
operator|,
name|NamingClass
argument_list|(
literal|0
argument_list|)
operator|,
name|SemaRef
argument_list|(
name|Other
operator|.
name|SemaRef
argument_list|)
operator|,
name|Name
argument_list|(
name|Other
operator|.
name|Name
argument_list|)
operator|,
name|NameLoc
argument_list|(
name|Other
operator|.
name|NameLoc
argument_list|)
operator|,
name|LookupKind
argument_list|(
name|Other
operator|.
name|LookupKind
argument_list|)
operator|,
name|IsAcceptableFn
argument_list|(
name|Other
operator|.
name|IsAcceptableFn
argument_list|)
operator|,
name|IDNS
argument_list|(
name|Other
operator|.
name|IDNS
argument_list|)
operator|,
name|Redecl
argument_list|(
name|Other
operator|.
name|Redecl
argument_list|)
operator|,
name|HideTags
argument_list|(
name|Other
operator|.
name|HideTags
argument_list|)
operator|,
name|Diagnose
argument_list|(
argument|false
argument_list|)
block|{}
operator|~
name|LookupResult
argument_list|()
block|{
if|if
condition|(
name|Diagnose
condition|)
name|diagnose
argument_list|()
expr_stmt|;
if|if
condition|(
name|Paths
condition|)
name|deletePaths
argument_list|(
name|Paths
argument_list|)
expr_stmt|;
block|}
comment|/// Gets the name to look up.
name|DeclarationName
name|getLookupName
argument_list|()
specifier|const
block|{
return|return
name|Name
return|;
block|}
comment|/// \brief Sets the name to look up.
name|void
name|setLookupName
parameter_list|(
name|DeclarationName
name|Name
parameter_list|)
block|{
name|this
operator|->
name|Name
operator|=
name|Name
expr_stmt|;
block|}
comment|/// Gets the kind of lookup to perform.
name|Sema
operator|::
name|LookupNameKind
name|getLookupKind
argument_list|()
specifier|const
block|{
return|return
name|LookupKind
return|;
block|}
comment|/// True if this lookup is just looking for an existing declaration.
name|bool
name|isForRedeclaration
argument_list|()
specifier|const
block|{
return|return
name|Redecl
return|;
block|}
comment|/// Sets whether tag declarations should be hidden by non-tag
comment|/// declarations during resolution.  The default is true.
name|void
name|setHideTags
parameter_list|(
name|bool
name|Hide
parameter_list|)
block|{
name|HideTags
operator|=
name|Hide
expr_stmt|;
block|}
name|bool
name|isAmbiguous
argument_list|()
specifier|const
block|{
return|return
name|getResultKind
argument_list|()
operator|==
name|Ambiguous
return|;
block|}
comment|/// Determines if this names a single result which is not an
comment|/// unresolved value using decl.  If so, it is safe to call
comment|/// getFoundDecl().
name|bool
name|isSingleResult
argument_list|()
specifier|const
block|{
return|return
name|getResultKind
argument_list|()
operator|==
name|Found
return|;
block|}
comment|/// Determines if the results are overloaded.
name|bool
name|isOverloadedResult
argument_list|()
specifier|const
block|{
return|return
name|getResultKind
argument_list|()
operator|==
name|FoundOverloaded
return|;
block|}
name|bool
name|isUnresolvableResult
argument_list|()
specifier|const
block|{
return|return
name|getResultKind
argument_list|()
operator|==
name|FoundUnresolvedValue
return|;
block|}
name|LookupResultKind
name|getResultKind
argument_list|()
specifier|const
block|{
name|sanity
argument_list|()
block|;
return|return
name|ResultKind
return|;
block|}
name|AmbiguityKind
name|getAmbiguityKind
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
name|isAmbiguous
argument_list|()
argument_list|)
block|;
return|return
name|Ambiguity
return|;
block|}
name|iterator
name|begin
argument_list|()
specifier|const
block|{
return|return
name|iterator
argument_list|(
name|Decls
operator|.
name|begin
argument_list|()
argument_list|)
return|;
block|}
name|iterator
name|end
argument_list|()
specifier|const
block|{
return|return
name|iterator
argument_list|(
name|Decls
operator|.
name|end
argument_list|()
argument_list|)
return|;
block|}
comment|/// \brief Return true if no decls were found
name|bool
name|empty
argument_list|()
specifier|const
block|{
return|return
name|Decls
operator|.
name|empty
argument_list|()
return|;
block|}
comment|/// \brief Return the base paths structure that's associated with
comment|/// these results, or null if none is.
name|CXXBasePaths
operator|*
name|getBasePaths
argument_list|()
specifier|const
block|{
return|return
name|Paths
return|;
block|}
comment|/// \brief Tests whether the given declaration is acceptable.
name|bool
name|isAcceptableDecl
argument_list|(
name|NamedDecl
operator|*
name|D
argument_list|)
decl|const
block|{
name|assert
argument_list|(
name|IsAcceptableFn
argument_list|)
expr_stmt|;
return|return
name|IsAcceptableFn
argument_list|(
name|D
argument_list|,
name|IDNS
argument_list|)
return|;
block|}
comment|/// \brief Returns the identifier namespace mask for this lookup.
name|unsigned
name|getIdentifierNamespace
argument_list|()
specifier|const
block|{
return|return
name|IDNS
return|;
block|}
comment|/// \brief Returns whether these results arose from performing a
comment|/// lookup into a class.
name|bool
name|isClassLookup
argument_list|()
specifier|const
block|{
return|return
name|NamingClass
operator|!=
literal|0
return|;
block|}
comment|/// \brief Returns the 'naming class' for this lookup, i.e. the
comment|/// class which was looked into to find these results.
comment|///
comment|/// C++0x [class.access.base]p5:
comment|///   The access to a member is affected by the class in which the
comment|///   member is named. This naming class is the class in which the
comment|///   member name was looked up and found. [Note: this class can be
comment|///   explicit, e.g., when a qualified-id is used, or implicit,
comment|///   e.g., when a class member access operator (5.2.5) is used
comment|///   (including cases where an implicit "this->" is added). If both
comment|///   a class member access operator and a qualified-id are used to
comment|///   name the member (as in p->T::m), the class naming the member
comment|///   is the class named by the nested-name-specifier of the
comment|///   qualified-id (that is, T). -- end note ]
comment|///
comment|/// This is set by the lookup routines when they find results in a class.
name|CXXRecordDecl
operator|*
name|getNamingClass
argument_list|()
specifier|const
block|{
return|return
name|NamingClass
return|;
block|}
comment|/// \brief Sets the 'naming class' for this lookup.
name|void
name|setNamingClass
parameter_list|(
name|CXXRecordDecl
modifier|*
name|Record
parameter_list|)
block|{
name|NamingClass
operator|=
name|Record
expr_stmt|;
block|}
comment|/// \brief Add a declaration to these results with its natural access.
comment|/// Does not test the acceptance criteria.
name|void
name|addDecl
parameter_list|(
name|NamedDecl
modifier|*
name|D
parameter_list|)
block|{
name|addDecl
argument_list|(
name|D
argument_list|,
name|D
operator|->
name|getAccess
argument_list|()
argument_list|)
expr_stmt|;
block|}
comment|/// \brief Add a declaration to these results with the given access.
comment|/// Does not test the acceptance criteria.
name|void
name|addDecl
parameter_list|(
name|NamedDecl
modifier|*
name|D
parameter_list|,
name|AccessSpecifier
name|AS
parameter_list|)
block|{
name|Decls
operator|.
name|addDecl
argument_list|(
name|D
argument_list|,
name|AS
argument_list|)
expr_stmt|;
name|ResultKind
operator|=
name|Found
expr_stmt|;
block|}
comment|/// \brief Add all the declarations from another set of lookup
comment|/// results.
name|void
name|addAllDecls
parameter_list|(
specifier|const
name|LookupResult
modifier|&
name|Other
parameter_list|)
block|{
name|Decls
operator|.
name|append
argument_list|(
name|Other
operator|.
name|Decls
operator|.
name|begin
argument_list|()
argument_list|,
name|Other
operator|.
name|Decls
operator|.
name|end
argument_list|()
argument_list|)
expr_stmt|;
name|ResultKind
operator|=
name|Found
expr_stmt|;
block|}
comment|/// \brief Determine whether no result was found because we could not
comment|/// search into dependent base classes of the current instantiation.
name|bool
name|wasNotFoundInCurrentInstantiation
argument_list|()
specifier|const
block|{
return|return
name|ResultKind
operator|==
name|NotFoundInCurrentInstantiation
return|;
block|}
comment|/// \brief Note that while no result was found in the current instantiation,
comment|/// there were dependent base classes that could not be searched.
name|void
name|setNotFoundInCurrentInstantiation
parameter_list|()
block|{
name|assert
argument_list|(
name|ResultKind
operator|==
name|NotFound
operator|&&
name|Decls
operator|.
name|empty
argument_list|()
argument_list|)
expr_stmt|;
name|ResultKind
operator|=
name|NotFoundInCurrentInstantiation
expr_stmt|;
block|}
comment|/// \brief Resolves the result kind of the lookup, possibly hiding
comment|/// decls.
comment|///
comment|/// This should be called in any environment where lookup might
comment|/// generate multiple lookup results.
name|void
name|resolveKind
parameter_list|()
function_decl|;
comment|/// \brief Re-resolves the result kind of the lookup after a set of
comment|/// removals has been performed.
name|void
name|resolveKindAfterFilter
parameter_list|()
block|{
if|if
condition|(
name|Decls
operator|.
name|empty
argument_list|()
condition|)
block|{
if|if
condition|(
name|ResultKind
operator|!=
name|NotFoundInCurrentInstantiation
condition|)
name|ResultKind
operator|=
name|NotFound
expr_stmt|;
block|}
else|else
block|{
name|ResultKind
operator|=
name|Found
expr_stmt|;
name|resolveKind
argument_list|()
expr_stmt|;
block|}
block|}
name|template
operator|<
name|class
name|DeclClass
operator|>
name|DeclClass
operator|*
name|getAsSingle
argument_list|()
specifier|const
block|{
if|if
condition|(
name|getResultKind
argument_list|()
operator|!=
name|Found
condition|)
return|return
literal|0
return|;
return|return
name|dyn_cast
operator|<
name|DeclClass
operator|>
operator|(
name|getFoundDecl
argument_list|()
operator|)
return|;
block|}
end_decl_stmt

begin_comment
comment|/// \brief Fetch the unique decl found by this lookup.  Asserts
end_comment

begin_comment
comment|/// that one was found.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This is intended for users who have examined the result kind
end_comment

begin_comment
comment|/// and are certain that there is only one result.
end_comment

begin_expr_stmt
name|NamedDecl
operator|*
name|getFoundDecl
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
name|getResultKind
argument_list|()
operator|==
name|Found
operator|&&
literal|"getFoundDecl called on non-unique result"
argument_list|)
block|;
return|return
operator|(
operator|*
name|begin
argument_list|()
operator|)
operator|->
name|getUnderlyingDecl
argument_list|()
return|;
block|}
end_expr_stmt

begin_comment
comment|/// Fetches a representative decl.  Useful for lazy diagnostics.
end_comment

begin_expr_stmt
name|NamedDecl
operator|*
name|getRepresentativeDecl
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
operator|!
name|Decls
operator|.
name|empty
argument_list|()
operator|&&
literal|"cannot get representative of empty set"
argument_list|)
block|;
return|return
operator|*
name|begin
argument_list|()
return|;
block|}
end_expr_stmt

begin_comment
comment|/// \brief Asks if the result is a single tag decl.
end_comment

begin_expr_stmt
name|bool
name|isSingleTagDecl
argument_list|()
specifier|const
block|{
return|return
name|getResultKind
argument_list|()
operator|==
name|Found
operator|&&
name|isa
operator|<
name|TagDecl
operator|>
operator|(
name|getFoundDecl
argument_list|()
operator|)
return|;
block|}
end_expr_stmt

begin_comment
comment|/// \brief Make these results show that the name was found in
end_comment

begin_comment
comment|/// base classes of different types.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// The given paths object is copied and invalidated.
end_comment

begin_function_decl
name|void
name|setAmbiguousBaseSubobjectTypes
parameter_list|(
name|CXXBasePaths
modifier|&
name|P
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// \brief Make these results show that the name was found in
end_comment

begin_comment
comment|/// distinct base classes of the same type.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// The given paths object is copied and invalidated.
end_comment

begin_function_decl
name|void
name|setAmbiguousBaseSubobjects
parameter_list|(
name|CXXBasePaths
modifier|&
name|P
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// \brief Make these results show that the name was found in
end_comment

begin_comment
comment|/// different contexts and a tag decl was hidden by an ordinary
end_comment

begin_comment
comment|/// decl in a different context.
end_comment

begin_function
name|void
name|setAmbiguousQualifiedTagHiding
parameter_list|()
block|{
name|setAmbiguous
argument_list|(
name|AmbiguousTagHiding
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/// \brief Clears out any current state.
end_comment

begin_function
name|void
name|clear
parameter_list|()
block|{
name|ResultKind
operator|=
name|NotFound
expr_stmt|;
name|Decls
operator|.
name|clear
argument_list|()
expr_stmt|;
if|if
condition|(
name|Paths
condition|)
name|deletePaths
argument_list|(
name|Paths
argument_list|)
expr_stmt|;
name|Paths
operator|=
name|NULL
expr_stmt|;
block|}
end_function

begin_comment
comment|/// \brief Clears out any current state and re-initializes for a
end_comment

begin_comment
comment|/// different kind of lookup.
end_comment

begin_decl_stmt
name|void
name|clear
argument_list|(
name|Sema
operator|::
name|LookupNameKind
name|Kind
argument_list|)
block|{
name|clear
argument_list|()
expr_stmt|;
name|LookupKind
operator|=
name|Kind
expr_stmt|;
name|configure
argument_list|()
expr_stmt|;
block|}
end_decl_stmt

begin_decl_stmt
name|void
name|print
argument_list|(
name|llvm
operator|::
name|raw_ostream
operator|&
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// Suppress the diagnostics that would normally fire because of this
end_comment

begin_comment
comment|/// lookup.  This happens during (e.g.) redeclaration lookups.
end_comment

begin_function
name|void
name|suppressDiagnostics
parameter_list|()
block|{
name|Diagnose
operator|=
name|false
expr_stmt|;
block|}
end_function

begin_comment
comment|/// Sets a 'context' source range.
end_comment

begin_function
name|void
name|setContextRange
parameter_list|(
name|SourceRange
name|SR
parameter_list|)
block|{
name|NameContextRange
operator|=
name|SR
expr_stmt|;
block|}
end_function

begin_comment
comment|/// Gets the source range of the context of this name; for C++
end_comment

begin_comment
comment|/// qualified lookups, this is the source range of the scope
end_comment

begin_comment
comment|/// specifier.
end_comment

begin_expr_stmt
name|SourceRange
name|getContextRange
argument_list|()
specifier|const
block|{
return|return
name|NameContextRange
return|;
block|}
end_expr_stmt

begin_comment
comment|/// Gets the location of the identifier.  This isn't always defined:
end_comment

begin_comment
comment|/// sometimes we're doing lookups on synthesized names.
end_comment

begin_expr_stmt
name|SourceLocation
name|getNameLoc
argument_list|()
specifier|const
block|{
return|return
name|NameLoc
return|;
block|}
end_expr_stmt

begin_comment
comment|/// \brief Get the Sema object that this lookup result is searching
end_comment

begin_comment
comment|/// with.
end_comment

begin_expr_stmt
name|Sema
operator|&
name|getSema
argument_list|()
specifier|const
block|{
return|return
name|SemaRef
return|;
block|}
end_expr_stmt

begin_comment
comment|/// A class for iterating through a result set and possibly
end_comment

begin_comment
comment|/// filtering out results.  The results returned are possibly
end_comment

begin_comment
comment|/// sugared.
end_comment

begin_decl_stmt
name|class
name|Filter
block|{
name|LookupResult
modifier|&
name|Results
decl_stmt|;
name|LookupResult
operator|::
name|iterator
name|I
expr_stmt|;
name|bool
name|Changed
decl_stmt|;
ifndef|#
directive|ifndef
name|NDEBUG
name|bool
name|CalledDone
decl_stmt|;
endif|#
directive|endif
name|friend
name|class
name|LookupResult
decl_stmt|;
name|Filter
argument_list|(
name|LookupResult
operator|&
name|Results
argument_list|)
operator|:
name|Results
argument_list|(
name|Results
argument_list|)
operator|,
name|I
argument_list|(
name|Results
operator|.
name|begin
argument_list|()
argument_list|)
operator|,
name|Changed
argument_list|(
name|false
argument_list|)
ifndef|#
directive|ifndef
name|NDEBUG
operator|,
name|CalledDone
argument_list|(
argument|false
argument_list|)
endif|#
directive|endif
block|{}
name|public
operator|:
ifndef|#
directive|ifndef
name|NDEBUG
operator|~
name|Filter
argument_list|()
block|{
name|assert
argument_list|(
name|CalledDone
operator|&&
literal|"LookupResult::Filter destroyed without done() call"
argument_list|)
block|;     }
endif|#
directive|endif
name|bool
name|hasNext
argument_list|()
specifier|const
block|{
return|return
name|I
operator|!=
name|Results
operator|.
name|end
argument_list|()
return|;
block|}
name|NamedDecl
modifier|*
name|next
parameter_list|()
block|{
name|assert
argument_list|(
name|I
operator|!=
name|Results
operator|.
name|end
argument_list|()
operator|&&
literal|"next() called on empty filter"
argument_list|)
expr_stmt|;
return|return
operator|*
name|I
operator|++
return|;
block|}
comment|/// Erase the last element returned from this iterator.
name|void
name|erase
parameter_list|()
block|{
name|Results
operator|.
name|Decls
operator|.
name|erase
argument_list|(
operator|--
name|I
argument_list|)
expr_stmt|;
name|Changed
operator|=
name|true
expr_stmt|;
block|}
comment|/// Replaces the current entry with the given one, preserving the
comment|/// access bits.
name|void
name|replace
parameter_list|(
name|NamedDecl
modifier|*
name|D
parameter_list|)
block|{
name|Results
operator|.
name|Decls
operator|.
name|replace
argument_list|(
name|I
operator|-
literal|1
argument_list|,
name|D
argument_list|)
expr_stmt|;
name|Changed
operator|=
name|true
expr_stmt|;
block|}
comment|/// Replaces the current entry with the given one.
name|void
name|replace
parameter_list|(
name|NamedDecl
modifier|*
name|D
parameter_list|,
name|AccessSpecifier
name|AS
parameter_list|)
block|{
name|Results
operator|.
name|Decls
operator|.
name|replace
argument_list|(
name|I
operator|-
literal|1
argument_list|,
name|D
argument_list|,
name|AS
argument_list|)
expr_stmt|;
name|Changed
operator|=
name|true
expr_stmt|;
block|}
name|void
name|done
parameter_list|()
block|{
ifndef|#
directive|ifndef
name|NDEBUG
name|assert
argument_list|(
operator|!
name|CalledDone
operator|&&
literal|"done() called twice"
argument_list|)
expr_stmt|;
name|CalledDone
operator|=
name|true
expr_stmt|;
endif|#
directive|endif
if|if
condition|(
name|Changed
condition|)
name|Results
operator|.
name|resolveKindAfterFilter
argument_list|()
expr_stmt|;
block|}
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|/// Create a filter for this result set.
end_comment

begin_function
name|Filter
name|makeFilter
parameter_list|()
block|{
return|return
name|Filter
argument_list|(
operator|*
name|this
argument_list|)
return|;
block|}
end_function

begin_label
name|private
label|:
end_label

begin_function
name|void
name|diagnose
parameter_list|()
block|{
if|if
condition|(
name|isAmbiguous
argument_list|()
condition|)
name|SemaRef
operator|.
name|DiagnoseAmbiguousLookup
argument_list|(
operator|*
name|this
argument_list|)
expr_stmt|;
elseif|else
if|if
condition|(
name|isClassLookup
argument_list|()
operator|&&
name|SemaRef
operator|.
name|getLangOptions
argument_list|()
operator|.
name|AccessControl
condition|)
name|SemaRef
operator|.
name|CheckAccess
argument_list|(
operator|*
name|this
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
name|void
name|setAmbiguous
parameter_list|(
name|AmbiguityKind
name|AK
parameter_list|)
block|{
name|ResultKind
operator|=
name|Ambiguous
expr_stmt|;
name|Ambiguity
operator|=
name|AK
expr_stmt|;
block|}
end_function

begin_function_decl
name|void
name|addDeclsFromBasePaths
parameter_list|(
specifier|const
name|CXXBasePaths
modifier|&
name|P
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|configure
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|// Sanity checks.
end_comment

begin_expr_stmt
name|void
name|sanity
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
name|ResultKind
operator|!=
name|NotFound
operator|||
name|Decls
operator|.
name|size
argument_list|()
operator|==
literal|0
argument_list|)
block|;
name|assert
argument_list|(
name|ResultKind
operator|!=
name|Found
operator|||
name|Decls
operator|.
name|size
argument_list|()
operator|==
literal|1
argument_list|)
block|;
name|assert
argument_list|(
name|ResultKind
operator|!=
name|FoundOverloaded
operator|||
name|Decls
operator|.
name|size
argument_list|()
operator|>
literal|1
operator|||
operator|(
name|Decls
operator|.
name|size
argument_list|()
operator|==
literal|1
operator|&&
name|isa
operator|<
name|FunctionTemplateDecl
operator|>
operator|(
operator|(
operator|*
name|begin
argument_list|()
operator|)
operator|->
name|getUnderlyingDecl
argument_list|()
operator|)
operator|)
argument_list|)
block|;
name|assert
argument_list|(
name|ResultKind
operator|!=
name|FoundUnresolvedValue
operator|||
name|sanityCheckUnresolved
argument_list|()
argument_list|)
block|;
name|assert
argument_list|(
name|ResultKind
operator|!=
name|Ambiguous
operator|||
name|Decls
operator|.
name|size
argument_list|()
operator|>
literal|1
operator|||
operator|(
name|Decls
operator|.
name|size
argument_list|()
operator|==
literal|1
operator|&&
name|Ambiguity
operator|==
name|AmbiguousBaseSubobjects
operator|)
argument_list|)
block|;
name|assert
argument_list|(
operator|(
name|Paths
operator|!=
name|NULL
operator|)
operator|==
operator|(
name|ResultKind
operator|==
name|Ambiguous
operator|&&
operator|(
name|Ambiguity
operator|==
name|AmbiguousBaseSubobjectTypes
operator|||
name|Ambiguity
operator|==
name|AmbiguousBaseSubobjects
operator|)
operator|)
argument_list|)
block|;   }
name|bool
name|sanityCheckUnresolved
argument_list|()
specifier|const
block|{
for|for
control|(
name|iterator
name|I
init|=
name|begin
argument_list|()
init|,
name|E
init|=
name|end
argument_list|()
init|;
name|I
operator|!=
name|E
condition|;
operator|++
name|I
control|)
if|if
condition|(
name|isa
operator|<
name|UnresolvedUsingValueDecl
operator|>
operator|(
operator|*
name|I
operator|)
condition|)
return|return
name|true
return|;
end_expr_stmt

begin_return
return|return
name|false
return|;
end_return

begin_function_decl
unit|}    static
name|void
name|deletePaths
parameter_list|(
name|CXXBasePaths
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|// Results.
end_comment

begin_decl_stmt
name|LookupResultKind
name|ResultKind
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|AmbiguityKind
name|Ambiguity
decl_stmt|;
end_decl_stmt

begin_comment
comment|// ill-defined unless ambiguous
end_comment

begin_expr_stmt
name|UnresolvedSet
operator|<
literal|8
operator|>
name|Decls
expr_stmt|;
end_expr_stmt

begin_decl_stmt
name|CXXBasePaths
modifier|*
name|Paths
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|CXXRecordDecl
modifier|*
name|NamingClass
decl_stmt|;
end_decl_stmt

begin_comment
comment|// Parameters.
end_comment

begin_decl_stmt
name|Sema
modifier|&
name|SemaRef
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|DeclarationName
name|Name
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|SourceLocation
name|NameLoc
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|SourceRange
name|NameContextRange
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|Sema
operator|::
name|LookupNameKind
name|LookupKind
expr_stmt|;
end_expr_stmt

begin_decl_stmt
name|ResultFilter
name|IsAcceptableFn
decl_stmt|;
end_decl_stmt

begin_comment
comment|// set by configure()
end_comment

begin_decl_stmt
name|unsigned
name|IDNS
decl_stmt|;
end_decl_stmt

begin_comment
comment|// set by configure()
end_comment

begin_decl_stmt
name|bool
name|Redecl
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// \brief True if tag declarations should be hidden if non-tags
end_comment

begin_comment
comment|///   are present
end_comment

begin_decl_stmt
name|bool
name|HideTags
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|bool
name|Diagnose
decl_stmt|;
end_decl_stmt

begin_comment
unit|};
comment|/// \brief Consumes visible declarations found when searching for
end_comment

begin_comment
comment|/// all visible names within a given scope or context.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This abstract class is meant to be subclassed by clients of \c
end_comment

begin_comment
comment|/// Sema::LookupVisibleDecls(), each of which should override the \c
end_comment

begin_comment
comment|/// FoundDecl() function to process declarations as they are found.
end_comment

begin_decl_stmt
name|class
name|VisibleDeclConsumer
block|{
name|public
label|:
comment|/// \brief Destroys the visible declaration consumer.
name|virtual
operator|~
name|VisibleDeclConsumer
argument_list|()
expr_stmt|;
comment|/// \brief Invoked each time \p Sema::LookupVisibleDecls() finds a
comment|/// declaration visible from the current scope or context.
comment|///
comment|/// \param ND the declaration found.
comment|///
comment|/// \param Hiding a declaration that hides the declaration \p ND,
comment|/// or NULL if no such declaration exists.
comment|///
comment|/// \param InBaseClass whether this declaration was found in base
comment|/// class of the context we searched.
name|virtual
name|void
name|FoundDecl
parameter_list|(
name|NamedDecl
modifier|*
name|ND
parameter_list|,
name|NamedDecl
modifier|*
name|Hiding
parameter_list|,
name|bool
name|InBaseClass
parameter_list|)
init|=
literal|0
function_decl|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_endif
unit|}
endif|#
directive|endif
end_endif

end_unit

