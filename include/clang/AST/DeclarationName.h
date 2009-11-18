begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- DeclarationName.h - Representation of declaration names -*- C++ -*-===//
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
comment|// This file declares the DeclarationName and DeclarationNameTable classes.
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
name|LLVM_CLANG_AST_DECLARATIONNAME_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_AST_DECLARATIONNAME_H
end_define

begin_include
include|#
directive|include
file|"clang/Basic/IdentifierTable.h"
end_include

begin_include
include|#
directive|include
file|"clang/AST/Type.h"
end_include

begin_include
include|#
directive|include
file|"clang/AST/CanonicalType.h"
end_include

begin_include
include|#
directive|include
file|"clang/Basic/PartialDiagnostic.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|template
operator|<
name|typename
name|T
operator|>
expr|struct
name|DenseMapInfo
expr_stmt|;
block|}
end_decl_stmt

begin_decl_stmt
name|namespace
name|clang
block|{
name|class
name|CXXSpecialName
decl_stmt|;
name|class
name|CXXOperatorIdName
decl_stmt|;
name|class
name|DeclarationNameExtra
decl_stmt|;
name|class
name|IdentifierInfo
decl_stmt|;
name|class
name|MultiKeywordSelector
decl_stmt|;
name|class
name|UsingDirectiveDecl
decl_stmt|;
comment|/// DeclarationName - The name of a declaration. In the common case,
comment|/// this just stores an IdentifierInfo pointer to a normal
comment|/// name. However, it also provides encodings for Objective-C
comment|/// selectors (optimizing zero- and one-argument selectors, which make
comment|/// up 78% percent of all selectors in Cocoa.h) and special C++ names
comment|/// for constructors, destructors, and conversion functions.
name|class
name|DeclarationName
block|{
name|public
label|:
comment|/// NameKind - The kind of name this object contains.
enum|enum
name|NameKind
block|{
name|Identifier
block|,
name|ObjCZeroArgSelector
block|,
name|ObjCOneArgSelector
block|,
name|ObjCMultiArgSelector
block|,
name|CXXConstructorName
block|,
name|CXXDestructorName
block|,
name|CXXConversionFunctionName
block|,
name|CXXOperatorName
block|,
name|CXXUsingDirective
block|}
enum|;
name|private
label|:
comment|/// StoredNameKind - The kind of name that is actually stored in the
comment|/// upper bits of the Ptr field. This is only used internally.
enum|enum
name|StoredNameKind
block|{
name|StoredIdentifier
init|=
literal|0
block|,
name|StoredObjCZeroArgSelector
block|,
name|StoredObjCOneArgSelector
block|,
name|StoredDeclarationNameExtra
block|,
name|PtrMask
init|=
literal|0x03
block|}
enum|;
comment|/// Ptr - The lowest two bits are used to express what kind of name
comment|/// we're actually storing, using the values of NameKind. Depending
comment|/// on the kind of name this is, the upper bits of Ptr may have one
comment|/// of several different meanings:
comment|///
comment|///   StoredIdentifier - The name is a normal identifier, and Ptr is
comment|///   a normal IdentifierInfo pointer.
comment|///
comment|///   StoredObjCZeroArgSelector - The name is an Objective-C
comment|///   selector with zero arguments, and Ptr is an IdentifierInfo
comment|///   pointer pointing to the selector name.
comment|///
comment|///   StoredObjCOneArgSelector - The name is an Objective-C selector
comment|///   with one argument, and Ptr is an IdentifierInfo pointer
comment|///   pointing to the selector name.
comment|///
comment|///   StoredDeclarationNameExtra - Ptr is actually a pointer to a
comment|///   DeclarationNameExtra structure, whose first value will tell us
comment|///   whether this is an Objective-C selector, C++ operator-id name,
comment|///   or special C++ name.
name|uintptr_t
name|Ptr
decl_stmt|;
comment|/// getStoredNameKind - Return the kind of object that is stored in
comment|/// Ptr.
name|StoredNameKind
name|getStoredNameKind
argument_list|()
specifier|const
block|{
return|return
name|static_cast
operator|<
name|StoredNameKind
operator|>
operator|(
name|Ptr
operator|&
name|PtrMask
operator|)
return|;
block|}
comment|/// getExtra - Get the "extra" information associated with this
comment|/// multi-argument selector or C++ special name.
name|DeclarationNameExtra
operator|*
name|getExtra
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
name|getStoredNameKind
argument_list|()
operator|==
name|StoredDeclarationNameExtra
operator|&&
literal|"Declaration name does not store an Extra structure"
argument_list|)
block|;
return|return
name|reinterpret_cast
operator|<
name|DeclarationNameExtra
operator|*
operator|>
operator|(
name|Ptr
operator|&
operator|~
name|PtrMask
operator|)
return|;
block|}
comment|/// getAsCXXSpecialName - If the stored pointer is actually a
comment|/// CXXSpecialName, returns a pointer to it. Otherwise, returns
comment|/// a NULL pointer.
name|CXXSpecialName
operator|*
name|getAsCXXSpecialName
argument_list|()
specifier|const
block|{
if|if
condition|(
name|getNameKind
argument_list|()
operator|>=
name|CXXConstructorName
operator|&&
name|getNameKind
argument_list|()
operator|<=
name|CXXConversionFunctionName
condition|)
return|return
name|reinterpret_cast
operator|<
name|CXXSpecialName
operator|*
operator|>
operator|(
name|Ptr
operator|&
operator|~
name|PtrMask
operator|)
return|;
return|return
literal|0
return|;
block|}
comment|/// getAsCXXOperatorIdName
name|CXXOperatorIdName
operator|*
name|getAsCXXOperatorIdName
argument_list|()
specifier|const
block|{
if|if
condition|(
name|getNameKind
argument_list|()
operator|==
name|CXXOperatorName
condition|)
return|return
name|reinterpret_cast
operator|<
name|CXXOperatorIdName
operator|*
operator|>
operator|(
name|Ptr
operator|&
operator|~
name|PtrMask
operator|)
return|;
return|return
literal|0
return|;
block|}
end_decl_stmt

begin_comment
comment|// Construct a declaration name from the name of a C++ constructor,
end_comment

begin_comment
comment|// destructor, or conversion function.
end_comment

begin_expr_stmt
name|DeclarationName
argument_list|(
name|CXXSpecialName
operator|*
name|Name
argument_list|)
operator|:
name|Ptr
argument_list|(
argument|reinterpret_cast<uintptr_t>(Name)
argument_list|)
block|{
name|assert
argument_list|(
operator|(
name|Ptr
operator|&
name|PtrMask
operator|)
operator|==
literal|0
operator|&&
literal|"Improperly aligned CXXSpecialName"
argument_list|)
block|;
name|Ptr
operator||=
name|StoredDeclarationNameExtra
block|;   }
comment|// Construct a declaration name from the name of a C++ overloaded
comment|// operator.
name|DeclarationName
argument_list|(
name|CXXOperatorIdName
operator|*
name|Name
argument_list|)
operator|:
name|Ptr
argument_list|(
argument|reinterpret_cast<uintptr_t>(Name)
argument_list|)
block|{
name|assert
argument_list|(
operator|(
name|Ptr
operator|&
name|PtrMask
operator|)
operator|==
literal|0
operator|&&
literal|"Improperly aligned CXXOperatorId"
argument_list|)
block|;
name|Ptr
operator||=
name|StoredDeclarationNameExtra
block|;   }
comment|/// Construct a declaration name from a raw pointer.
name|DeclarationName
argument_list|(
argument|uintptr_t Ptr
argument_list|)
operator|:
name|Ptr
argument_list|(
argument|Ptr
argument_list|)
block|{ }
name|friend
name|class
name|DeclarationNameTable
expr_stmt|;
end_expr_stmt

begin_decl_stmt
name|friend
name|class
name|NamedDecl
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// getFETokenInfoAsVoid - Retrieves the front end-specified pointer
end_comment

begin_comment
comment|/// for this name as a void pointer.
end_comment

begin_expr_stmt
name|void
operator|*
name|getFETokenInfoAsVoid
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt

begin_label
name|public
label|:
end_label

begin_comment
comment|/// DeclarationName - Used to create an empty selector.
end_comment

begin_expr_stmt
name|DeclarationName
argument_list|()
operator|:
name|Ptr
argument_list|(
literal|0
argument_list|)
block|{ }
comment|// Construct a declaration name from an IdentifierInfo *.
name|DeclarationName
argument_list|(
specifier|const
name|IdentifierInfo
operator|*
name|II
argument_list|)
operator|:
name|Ptr
argument_list|(
argument|reinterpret_cast<uintptr_t>(II)
argument_list|)
block|{
name|assert
argument_list|(
operator|(
name|Ptr
operator|&
name|PtrMask
operator|)
operator|==
literal|0
operator|&&
literal|"Improperly aligned IdentifierInfo"
argument_list|)
block|;   }
comment|// Construct a declaration name from an Objective-C selector.
name|DeclarationName
argument_list|(
argument|Selector Sel
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// getUsingDirectiveName - Return name for all using-directives.
end_comment

begin_function_decl
specifier|static
name|DeclarationName
name|getUsingDirectiveName
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|// operator bool() - Evaluates true when this declaration name is
end_comment

begin_comment
comment|// non-empty.
end_comment

begin_expr_stmt
name|operator
name|bool
argument_list|()
specifier|const
block|{
return|return
operator|(
operator|(
name|Ptr
operator|&
name|PtrMask
operator|)
operator|!=
literal|0
operator|)
operator|||
operator|(
name|reinterpret_cast
operator|<
name|IdentifierInfo
operator|*
operator|>
operator|(
name|Ptr
operator|&
operator|~
name|PtrMask
operator|)
operator|)
return|;
block|}
end_expr_stmt

begin_comment
comment|/// Predicate functions for querying what type of name this is.
end_comment

begin_expr_stmt
name|bool
name|isIdentifier
argument_list|()
specifier|const
block|{
return|return
name|getStoredNameKind
argument_list|()
operator|==
name|StoredIdentifier
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|bool
name|isObjCZeroArgSelector
argument_list|()
specifier|const
block|{
return|return
name|getStoredNameKind
argument_list|()
operator|==
name|StoredObjCZeroArgSelector
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|bool
name|isObjCOneArgSelector
argument_list|()
specifier|const
block|{
return|return
name|getStoredNameKind
argument_list|()
operator|==
name|StoredObjCOneArgSelector
return|;
block|}
end_expr_stmt

begin_comment
comment|/// getNameKind - Determine what kind of name this is.
end_comment

begin_expr_stmt
name|NameKind
name|getNameKind
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// getName - Retrieve the human-readable string for this name.
end_comment

begin_expr_stmt
name|std
operator|::
name|string
name|getAsString
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// getAsIdentifierInfo - Retrieve the IdentifierInfo * stored in
end_comment

begin_comment
comment|/// this declaration name, or NULL if this declaration name isn't a
end_comment

begin_comment
comment|/// simple identifier.
end_comment

begin_expr_stmt
name|IdentifierInfo
operator|*
name|getAsIdentifierInfo
argument_list|()
specifier|const
block|{
if|if
condition|(
name|isIdentifier
argument_list|()
condition|)
return|return
name|reinterpret_cast
operator|<
name|IdentifierInfo
operator|*
operator|>
operator|(
name|Ptr
operator|)
return|;
end_expr_stmt

begin_return
return|return
literal|0
return|;
end_return

begin_comment
unit|}
comment|/// getAsOpaqueInteger - Get the representation of this declaration
end_comment

begin_comment
comment|/// name as an opaque integer.
end_comment

begin_macro
unit|uintptr_t
name|getAsOpaqueInteger
argument_list|()
end_macro

begin_expr_stmt
specifier|const
block|{
return|return
name|Ptr
return|;
block|}
end_expr_stmt

begin_comment
comment|/// getAsOpaquePtr - Get the representation of this declaration name as
end_comment

begin_comment
comment|/// an opaque pointer.
end_comment

begin_expr_stmt
name|void
operator|*
name|getAsOpaquePtr
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
name|Ptr
operator|)
return|;
block|}
end_expr_stmt

begin_function
specifier|static
name|DeclarationName
name|getFromOpaquePtr
parameter_list|(
name|void
modifier|*
name|P
parameter_list|)
block|{
name|DeclarationName
name|N
decl_stmt|;
name|N
operator|.
name|Ptr
operator|=
name|reinterpret_cast
operator|<
name|uintptr_t
operator|>
operator|(
name|P
operator|)
expr_stmt|;
return|return
name|N
return|;
block|}
end_function

begin_function
specifier|static
name|DeclarationName
name|getFromOpaqueInteger
parameter_list|(
name|uintptr_t
name|P
parameter_list|)
block|{
name|DeclarationName
name|N
decl_stmt|;
name|N
operator|.
name|Ptr
operator|=
name|P
expr_stmt|;
return|return
name|N
return|;
block|}
end_function

begin_comment
comment|/// getCXXNameType - If this name is one of the C++ names (of a
end_comment

begin_comment
comment|/// constructor, destructor, or conversion function), return the
end_comment

begin_comment
comment|/// type associated with that name.
end_comment

begin_expr_stmt
name|QualType
name|getCXXNameType
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// getCXXOverloadedOperator - If this name is the name of an
end_comment

begin_comment
comment|/// overloadable operator in C++ (e.g., @c operator+), retrieve the
end_comment

begin_comment
comment|/// kind of overloaded operator.
end_comment

begin_expr_stmt
name|OverloadedOperatorKind
name|getCXXOverloadedOperator
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// getObjCSelector - Get the Objective-C selector stored in this
end_comment

begin_comment
comment|/// declaration name.
end_comment

begin_expr_stmt
name|Selector
name|getObjCSelector
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// getFETokenInfo/setFETokenInfo - The language front-end is
end_comment

begin_comment
comment|/// allowed to associate arbitrary metadata with some kinds of
end_comment

begin_comment
comment|/// declaration names, including normal identifiers and C++
end_comment

begin_comment
comment|/// constructors, destructors, and conversion functions.
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|>
name|T
operator|*
name|getFETokenInfo
argument_list|()
specifier|const
block|{
return|return
name|static_cast
operator|<
name|T
operator|*
operator|>
operator|(
name|getFETokenInfoAsVoid
argument_list|()
operator|)
return|;
block|}
end_expr_stmt

begin_function_decl
name|void
name|setFETokenInfo
parameter_list|(
name|void
modifier|*
name|T
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// operator== - Determine whether the specified names are identical..
end_comment

begin_expr_stmt
name|friend
name|bool
name|operator
operator|==
operator|(
name|DeclarationName
name|LHS
operator|,
name|DeclarationName
name|RHS
operator|)
block|{
return|return
name|LHS
operator|.
name|Ptr
operator|==
name|RHS
operator|.
name|Ptr
return|;
block|}
end_expr_stmt

begin_comment
comment|/// operator!= - Determine whether the specified names are different.
end_comment

begin_expr_stmt
name|friend
name|bool
name|operator
operator|!=
operator|(
name|DeclarationName
name|LHS
operator|,
name|DeclarationName
name|RHS
operator|)
block|{
return|return
name|LHS
operator|.
name|Ptr
operator|!=
name|RHS
operator|.
name|Ptr
return|;
block|}
end_expr_stmt

begin_function
specifier|static
name|DeclarationName
name|getEmptyMarker
parameter_list|()
block|{
return|return
name|DeclarationName
argument_list|(
name|uintptr_t
argument_list|(
operator|-
literal|1
argument_list|)
argument_list|)
return|;
block|}
end_function

begin_function
specifier|static
name|DeclarationName
name|getTombstoneMarker
parameter_list|()
block|{
return|return
name|DeclarationName
argument_list|(
name|uintptr_t
argument_list|(
operator|-
literal|2
argument_list|)
argument_list|)
return|;
block|}
end_function

begin_expr_stmt
name|void
name|dump
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt

begin_comment
unit|};
comment|/// Ordering on two declaration names. If both names are identifiers,
end_comment

begin_comment
comment|/// this provides a lexicographical ordering.
end_comment

begin_expr_stmt
name|bool
name|operator
operator|<
operator|(
name|DeclarationName
name|LHS
operator|,
name|DeclarationName
name|RHS
operator|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// Ordering on two declaration names. If both names are identifiers,
end_comment

begin_comment
comment|/// this provides a lexicographical ordering.
end_comment

begin_expr_stmt
specifier|inline
name|bool
name|operator
operator|>
operator|(
name|DeclarationName
name|LHS
operator|,
name|DeclarationName
name|RHS
operator|)
block|{
return|return
name|RHS
operator|<
name|LHS
return|;
block|}
end_expr_stmt

begin_comment
comment|/// Ordering on two declaration names. If both names are identifiers,
end_comment

begin_comment
comment|/// this provides a lexicographical ordering.
end_comment

begin_expr_stmt
specifier|inline
name|bool
name|operator
operator|<=
operator|(
name|DeclarationName
name|LHS
operator|,
name|DeclarationName
name|RHS
operator|)
block|{
return|return
operator|!
operator|(
name|RHS
operator|<
name|LHS
operator|)
return|;
block|}
end_expr_stmt

begin_comment
comment|/// Ordering on two declaration names. If both names are identifiers,
end_comment

begin_comment
comment|/// this provides a lexicographical ordering.
end_comment

begin_expr_stmt
specifier|inline
name|bool
name|operator
operator|>=
operator|(
name|DeclarationName
name|LHS
operator|,
name|DeclarationName
name|RHS
operator|)
block|{
return|return
operator|!
operator|(
name|LHS
operator|<
name|RHS
operator|)
return|;
block|}
end_expr_stmt

begin_comment
comment|/// DeclarationNameTable - Used to store and retrieve DeclarationName
end_comment

begin_comment
comment|/// instances for the various kinds of declaration names, e.g., normal
end_comment

begin_comment
comment|/// identifiers, C++ constructor names, etc. This class contains
end_comment

begin_comment
comment|/// uniqued versions of each of the C++ special names, which can be
end_comment

begin_comment
comment|/// retrieved using its member functions (e.g.,
end_comment

begin_comment
comment|/// getCXXConstructorName).
end_comment

begin_decl_stmt
name|class
name|DeclarationNameTable
block|{
name|void
modifier|*
name|CXXSpecialNamesImpl
decl_stmt|;
comment|// Actually a FoldingSet<CXXSpecialName> *
name|CXXOperatorIdName
modifier|*
name|CXXOperatorNames
decl_stmt|;
comment|// Operator names
name|DeclarationNameTable
argument_list|(
specifier|const
name|DeclarationNameTable
operator|&
argument_list|)
expr_stmt|;
comment|// NONCOPYABLE
name|DeclarationNameTable
modifier|&
name|operator
init|=
operator|(
specifier|const
name|DeclarationNameTable
operator|&
operator|)
decl_stmt|;
comment|// NONCOPYABLE
name|public
label|:
name|DeclarationNameTable
argument_list|()
expr_stmt|;
operator|~
name|DeclarationNameTable
argument_list|()
expr_stmt|;
comment|/// getIdentifier - Create a declaration name that is a simple
comment|/// identifier.
name|DeclarationName
name|getIdentifier
parameter_list|(
name|IdentifierInfo
modifier|*
name|ID
parameter_list|)
block|{
return|return
name|DeclarationName
argument_list|(
name|ID
argument_list|)
return|;
block|}
comment|/// getCXXConstructorName - Returns the name of a C++ constructor
comment|/// for the given Type.
name|DeclarationName
name|getCXXConstructorName
parameter_list|(
name|CanQualType
name|Ty
parameter_list|)
block|{
return|return
name|getCXXSpecialName
argument_list|(
name|DeclarationName
operator|::
name|CXXConstructorName
argument_list|,
name|Ty
argument_list|)
return|;
block|}
comment|/// getCXXDestructorName - Returns the name of a C++ destructor
comment|/// for the given Type.
name|DeclarationName
name|getCXXDestructorName
parameter_list|(
name|CanQualType
name|Ty
parameter_list|)
block|{
return|return
name|getCXXSpecialName
argument_list|(
name|DeclarationName
operator|::
name|CXXDestructorName
argument_list|,
name|Ty
argument_list|)
return|;
block|}
comment|/// getCXXConversionFunctionName - Returns the name of a C++
comment|/// conversion function for the given Type.
name|DeclarationName
name|getCXXConversionFunctionName
parameter_list|(
name|CanQualType
name|Ty
parameter_list|)
block|{
return|return
name|getCXXSpecialName
argument_list|(
name|DeclarationName
operator|::
name|CXXConversionFunctionName
argument_list|,
name|Ty
argument_list|)
return|;
block|}
comment|/// getCXXSpecialName - Returns a declaration name for special kind
comment|/// of C++ name, e.g., for a constructor, destructor, or conversion
comment|/// function.
name|DeclarationName
name|getCXXSpecialName
argument_list|(
name|DeclarationName
operator|::
name|NameKind
name|Kind
argument_list|,
name|CanQualType
name|Ty
argument_list|)
decl_stmt|;
comment|/// getCXXOperatorName - Get the name of the overloadable C++
comment|/// operator corresponding to Op.
name|DeclarationName
name|getCXXOperatorName
parameter_list|(
name|OverloadedOperatorKind
name|Op
parameter_list|)
function_decl|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|/// Insertion operator for diagnostics.  This allows sending DeclarationName's
end_comment

begin_comment
comment|/// into a diagnostic with<<.
end_comment

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
name|DeclarationName
name|N
operator|)
block|{
name|DB
operator|.
name|AddTaggedVal
argument_list|(
name|N
operator|.
name|getAsOpaqueInteger
argument_list|()
argument_list|,
name|Diagnostic
operator|::
name|ak_declarationname
argument_list|)
block|;
return|return
name|DB
return|;
block|}
end_expr_stmt

begin_comment
comment|/// Insertion operator for partial diagnostics.  This allows binding
end_comment

begin_comment
comment|/// DeclarationName's into a partial diagnostic with<<.
end_comment

begin_expr_stmt
specifier|inline
specifier|const
name|PartialDiagnostic
operator|&
name|operator
operator|<<
operator|(
specifier|const
name|PartialDiagnostic
operator|&
name|PD
operator|,
name|DeclarationName
name|N
operator|)
block|{
name|PD
operator|.
name|AddTaggedVal
argument_list|(
name|N
operator|.
name|getAsOpaqueInteger
argument_list|()
argument_list|,
name|Diagnostic
operator|::
name|ak_declarationname
argument_list|)
block|;
return|return
name|PD
return|;
block|}
end_expr_stmt

begin_comment
unit|}
comment|// end namespace clang
end_comment

begin_macro
unit|namespace
name|llvm
end_macro

begin_block
block|{
comment|/// Define DenseMapInfo so that DeclarationNames can be used as keys
comment|/// in DenseMap and DenseSets.
name|template
operator|<
operator|>
expr|struct
name|DenseMapInfo
operator|<
name|clang
operator|::
name|DeclarationName
operator|>
block|{
specifier|static
specifier|inline
name|clang
operator|::
name|DeclarationName
name|getEmptyKey
argument_list|()
block|{
return|return
name|clang
operator|::
name|DeclarationName
operator|::
name|getEmptyMarker
argument_list|()
return|;
block|}
specifier|static
specifier|inline
name|clang
operator|::
name|DeclarationName
name|getTombstoneKey
argument_list|()
block|{
return|return
name|clang
operator|::
name|DeclarationName
operator|::
name|getTombstoneMarker
argument_list|()
return|;
block|}
specifier|static
name|unsigned
name|getHashValue
argument_list|(
name|clang
operator|::
name|DeclarationName
argument_list|)
decl_stmt|;
specifier|static
specifier|inline
name|bool
name|isEqual
argument_list|(
name|clang
operator|::
name|DeclarationName
name|LHS
argument_list|,
name|clang
operator|::
name|DeclarationName
name|RHS
argument_list|)
block|{
return|return
name|LHS
operator|==
name|RHS
return|;
block|}
specifier|static
specifier|inline
name|bool
name|isPod
parameter_list|()
block|{
return|return
name|true
return|;
block|}
block|}
end_block

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
unit|}
comment|// end namespace llvm
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

