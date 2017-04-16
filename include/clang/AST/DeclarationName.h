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
file|"clang/Basic/PartialDiagnostic.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/Compiler.h"
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
name|ASTContext
decl_stmt|;
name|class
name|CXXDeductionGuideNameExtra
decl_stmt|;
name|class
name|CXXLiteralOperatorIdName
decl_stmt|;
name|class
name|CXXOperatorIdName
decl_stmt|;
name|class
name|CXXSpecialName
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
enum_decl|enum
name|OverloadedOperatorKind
enum_decl|:
name|int
enum_decl|;
struct_decl|struct
name|PrintingPolicy
struct_decl|;
name|class
name|QualType
decl_stmt|;
name|class
name|TemplateDecl
decl_stmt|;
name|class
name|Type
decl_stmt|;
name|class
name|TypeSourceInfo
decl_stmt|;
name|class
name|UsingDirectiveDecl
decl_stmt|;
name|template
operator|<
name|typename
operator|>
name|class
name|CanQual
expr_stmt|;
typedef|typedef
name|CanQual
operator|<
name|Type
operator|>
name|CanQualType
expr_stmt|;
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
name|CXXDeductionGuideName
block|,
name|CXXOperatorName
block|,
name|CXXLiteralOperatorName
block|,
name|CXXUsingDirective
block|}
enum|;
specifier|static
specifier|const
name|unsigned
name|NumNameKinds
init|=
name|CXXUsingDirective
operator|+
literal|1
decl_stmt|;
name|private
label|:
comment|/// StoredNameKind - The kind of name that is actually stored in the
comment|/// upper bits of the Ptr field. This is only used internally.
comment|///
comment|/// Note: The entries here are synchronized with the entries in Selector,
comment|/// for efficient translation between the two.
enum|enum
name|StoredNameKind
block|{
name|StoredIdentifier
init|=
literal|0
block|,
name|StoredObjCZeroArgSelector
init|=
literal|0x01
block|,
name|StoredObjCOneArgSelector
init|=
literal|0x02
block|,
name|StoredDeclarationNameExtra
init|=
literal|0x03
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
name|NameKind
name|Kind
operator|=
name|getNameKind
argument_list|()
block|;
if|if
condition|(
name|Kind
operator|>=
name|CXXConstructorName
operator|&&
name|Kind
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
name|getExtra
argument_list|()
operator|)
return|;
return|return
name|nullptr
return|;
block|}
comment|/// If the stored pointer is actually a CXXDeductionGuideNameExtra, returns a
comment|/// pointer to it. Otherwise, returns a NULL pointer.
name|CXXDeductionGuideNameExtra
operator|*
name|getAsCXXDeductionGuideNameExtra
argument_list|()
specifier|const
block|{
if|if
condition|(
name|getNameKind
argument_list|()
operator|==
name|CXXDeductionGuideName
condition|)
return|return
name|reinterpret_cast
operator|<
name|CXXDeductionGuideNameExtra
operator|*
operator|>
operator|(
name|getExtra
argument_list|()
operator|)
return|;
return|return
name|nullptr
return|;
block|}
end_decl_stmt

begin_comment
comment|/// getAsCXXOperatorIdName
end_comment

begin_expr_stmt
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
name|getExtra
argument_list|()
operator|)
return|;
end_expr_stmt

begin_return
return|return
name|nullptr
return|;
end_return

begin_expr_stmt
unit|}    CXXLiteralOperatorIdName
operator|*
name|getAsCXXLiteralOperatorIdName
argument_list|()
specifier|const
block|{
if|if
condition|(
name|getNameKind
argument_list|()
operator|==
name|CXXLiteralOperatorName
condition|)
return|return
name|reinterpret_cast
operator|<
name|CXXLiteralOperatorIdName
operator|*
operator|>
operator|(
name|getExtra
argument_list|()
operator|)
return|;
end_expr_stmt

begin_return
return|return
name|nullptr
return|;
end_return

begin_comment
unit|}
comment|// Construct a declaration name from the name of a C++ constructor,
end_comment

begin_comment
comment|// destructor, or conversion function.
end_comment

begin_expr_stmt
unit|DeclarationName
operator|(
name|DeclarationNameExtra
operator|*
name|Name
operator|)
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
literal|"Improperly aligned DeclarationNameExtra"
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
comment|/// getFETokenInfoAsVoidSlow - Retrieves the front end-specified pointer
end_comment

begin_comment
comment|/// for this name as a void pointer if it's not an identifier.
end_comment

begin_expr_stmt
name|void
operator|*
name|getFETokenInfoAsVoidSlow
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
operator|:
name|Ptr
argument_list|(
argument|Sel.InfoPtr
argument_list|)
block|{ }
comment|/// getUsingDirectiveName - Return name for all using-directives.
specifier|static
name|DeclarationName
name|getUsingDirectiveName
argument_list|()
expr_stmt|;
end_expr_stmt

begin_comment
comment|// operator bool() - Evaluates true when this declaration name is
end_comment

begin_comment
comment|// non-empty.
end_comment

begin_expr_stmt
name|explicit
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
comment|/// \brief Evaluates true when this declaration name is empty.
end_comment

begin_expr_stmt
name|bool
name|isEmpty
argument_list|()
specifier|const
block|{
return|return
operator|!
operator|*
name|this
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
comment|/// \brief Determines whether the name itself is dependent, e.g., because it
end_comment

begin_comment
comment|/// involves a C++ type that is itself dependent.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Note that this does not capture all of the notions of "dependent name",
end_comment

begin_comment
comment|/// because an identifier can be a dependent name if it is used as the
end_comment

begin_comment
comment|/// callee in a call expression with dependent arguments.
end_comment

begin_expr_stmt
name|bool
name|isDependentName
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// getNameAsString - Retrieve the human-readable string for this name.
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
name|nullptr
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
comment|/// If this name is the name of a C++ deduction guide, return the
end_comment

begin_comment
comment|/// template associated with that name.
end_comment

begin_expr_stmt
name|TemplateDecl
operator|*
name|getCXXDeductionGuideTemplate
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
comment|/// getCXXLiteralIdentifier - If this name is the name of a literal
end_comment

begin_comment
comment|/// operator, retrieve the identifier associated with it.
end_comment

begin_expr_stmt
name|IdentifierInfo
operator|*
name|getCXXLiteralIdentifier
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
block|{
name|assert
argument_list|(
operator|(
name|getNameKind
argument_list|()
operator|==
name|ObjCZeroArgSelector
operator|||
name|getNameKind
argument_list|()
operator|==
name|ObjCOneArgSelector
operator|||
name|getNameKind
argument_list|()
operator|==
name|ObjCMultiArgSelector
operator|||
name|Ptr
operator|==
literal|0
operator|)
operator|&&
literal|"Not a selector!"
argument_list|)
block|;
return|return
name|Selector
argument_list|(
name|Ptr
argument_list|)
return|;
block|}
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
if|if
condition|(
specifier|const
name|IdentifierInfo
modifier|*
name|Info
init|=
name|getAsIdentifierInfo
argument_list|()
condition|)
return|return
name|Info
operator|->
name|getFETokenInfo
operator|<
name|T
operator|>
operator|(
operator|)
return|;
end_expr_stmt

begin_return
return|return
name|static_cast
operator|<
name|T
operator|*
operator|>
operator|(
name|getFETokenInfoAsVoidSlow
argument_list|()
operator|)
return|;
end_return

begin_expr_stmt
unit|}    void
name|setFETokenInfo
argument_list|(
name|void
operator|*
name|T
argument_list|)
expr_stmt|;
end_expr_stmt

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

begin_function_decl
specifier|static
name|int
name|compare
parameter_list|(
name|DeclarationName
name|LHS
parameter_list|,
name|DeclarationName
name|RHS
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|print
parameter_list|(
name|raw_ostream
modifier|&
name|OS
parameter_list|,
specifier|const
name|PrintingPolicy
modifier|&
name|Policy
parameter_list|)
function_decl|;
end_function_decl

begin_expr_stmt
name|void
name|dump
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt

begin_expr_stmt
unit|};
name|raw_ostream
operator|&
name|operator
operator|<<
operator|(
name|raw_ostream
operator|&
name|OS
operator|,
name|DeclarationName
name|N
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
operator|<
operator|(
name|DeclarationName
name|LHS
operator|,
name|DeclarationName
name|RHS
operator|)
block|{
return|return
name|DeclarationName
operator|::
name|compare
argument_list|(
name|LHS
argument_list|,
name|RHS
argument_list|)
operator|<
literal|0
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
name|DeclarationName
operator|::
name|compare
argument_list|(
name|LHS
argument_list|,
name|RHS
argument_list|)
operator|>
literal|0
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
name|DeclarationName
operator|::
name|compare
argument_list|(
name|LHS
argument_list|,
name|RHS
argument_list|)
operator|<=
literal|0
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
name|DeclarationName
operator|::
name|compare
argument_list|(
name|LHS
argument_list|,
name|RHS
argument_list|)
operator|>=
literal|0
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
specifier|const
name|ASTContext
modifier|&
name|Ctx
decl_stmt|;
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
name|void
modifier|*
name|CXXLiteralOperatorNames
decl_stmt|;
comment|// Actually a CXXOperatorIdName*
name|void
modifier|*
name|CXXDeductionGuideNames
decl_stmt|;
comment|// FoldingSet<CXXDeductionGuideNameExtra> *
name|DeclarationNameTable
argument_list|(
specifier|const
name|DeclarationNameTable
operator|&
argument_list|)
operator|=
name|delete
expr_stmt|;
name|void
name|operator
init|=
operator|(
specifier|const
name|DeclarationNameTable
operator|&
operator|)
operator|=
name|delete
decl_stmt|;
name|public
label|:
name|DeclarationNameTable
argument_list|(
specifier|const
name|ASTContext
operator|&
name|C
argument_list|)
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
specifier|const
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
function_decl|;
comment|/// getCXXDestructorName - Returns the name of a C++ destructor
comment|/// for the given Type.
name|DeclarationName
name|getCXXDestructorName
parameter_list|(
name|CanQualType
name|Ty
parameter_list|)
function_decl|;
comment|/// Returns the name of a C++ deduction guide for the given template.
name|DeclarationName
name|getCXXDeductionGuideName
parameter_list|(
name|TemplateDecl
modifier|*
name|TD
parameter_list|)
function_decl|;
comment|/// getCXXConversionFunctionName - Returns the name of a C++
comment|/// conversion function for the given Type.
name|DeclarationName
name|getCXXConversionFunctionName
parameter_list|(
name|CanQualType
name|Ty
parameter_list|)
function_decl|;
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
comment|/// getCXXLiteralOperatorName - Get the name of the literal operator function
comment|/// with II as the identifier.
name|DeclarationName
name|getCXXLiteralOperatorName
parameter_list|(
name|IdentifierInfo
modifier|*
name|II
parameter_list|)
function_decl|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|/// DeclarationNameLoc - Additional source/type location info
end_comment

begin_comment
comment|/// for a declaration name. Needs a DeclarationName in order
end_comment

begin_comment
comment|/// to be interpreted correctly.
end_comment

begin_struct
struct|struct
name|DeclarationNameLoc
block|{
comment|// The source location for identifier stored elsewhere.
comment|// struct {} Identifier;
comment|// Type info for constructors, destructors and conversion functions.
comment|// Locations (if any) for the tilde (destructor) or operator keyword
comment|// (conversion) are stored elsewhere.
struct|struct
name|NT
block|{
name|TypeSourceInfo
modifier|*
name|TInfo
decl_stmt|;
block|}
struct|;
comment|// The location (if any) of the operator keyword is stored elsewhere.
struct|struct
name|CXXOpName
block|{
name|unsigned
name|BeginOpNameLoc
decl_stmt|;
name|unsigned
name|EndOpNameLoc
decl_stmt|;
block|}
struct|;
comment|// The location (if any) of the operator keyword is stored elsewhere.
struct|struct
name|CXXLitOpName
block|{
name|unsigned
name|OpNameLoc
decl_stmt|;
block|}
struct|;
comment|// struct {} CXXUsingDirective;
comment|// struct {} ObjCZeroArgSelector;
comment|// struct {} ObjCOneArgSelector;
comment|// struct {} ObjCMultiArgSelector;
union|union
block|{
name|struct
name|NT
name|NamedType
decl_stmt|;
name|struct
name|CXXOpName
name|CXXOperatorName
decl_stmt|;
name|struct
name|CXXLitOpName
name|CXXLiteralOperatorName
decl_stmt|;
block|}
union|;
name|DeclarationNameLoc
argument_list|(
argument|DeclarationName Name
argument_list|)
empty_stmt|;
comment|// FIXME: this should go away once all DNLocs are properly initialized.
name|DeclarationNameLoc
argument_list|()
block|{
name|memset
argument_list|(
operator|(
name|void
operator|*
operator|)
name|this
argument_list|,
literal|0
argument_list|,
sizeof|sizeof
argument_list|(
operator|*
name|this
argument_list|)
argument_list|)
expr_stmt|;
block|}
block|}
struct|;
end_struct

begin_comment
comment|// struct DeclarationNameLoc
end_comment

begin_comment
comment|/// DeclarationNameInfo - A collector data type for bundling together
end_comment

begin_comment
comment|/// a DeclarationName and the correspnding source/type location info.
end_comment

begin_struct
struct|struct
name|DeclarationNameInfo
block|{
name|private
label|:
comment|/// Name - The declaration name, also encoding name kind.
name|DeclarationName
name|Name
decl_stmt|;
comment|/// Loc - The main source location for the declaration name.
name|SourceLocation
name|NameLoc
decl_stmt|;
comment|/// Info - Further source/type location info for special kinds of names.
name|DeclarationNameLoc
name|LocInfo
decl_stmt|;
name|public
label|:
comment|// FIXME: remove it.
name|DeclarationNameInfo
argument_list|()
block|{}
name|DeclarationNameInfo
argument_list|(
argument|DeclarationName Name
argument_list|,
argument|SourceLocation NameLoc
argument_list|)
block|:
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
name|LocInfo
argument_list|(
argument|Name
argument_list|)
block|{}
name|DeclarationNameInfo
argument_list|(
argument|DeclarationName Name
argument_list|,
argument|SourceLocation NameLoc
argument_list|,
argument|DeclarationNameLoc LocInfo
argument_list|)
operator|:
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
name|LocInfo
argument_list|(
argument|LocInfo
argument_list|)
block|{}
comment|/// getName - Returns the embedded declaration name.
name|DeclarationName
name|getName
argument_list|()
specifier|const
block|{
return|return
name|Name
return|;
block|}
comment|/// setName - Sets the embedded declaration name.
name|void
name|setName
parameter_list|(
name|DeclarationName
name|N
parameter_list|)
block|{
name|Name
operator|=
name|N
expr_stmt|;
block|}
comment|/// getLoc - Returns the main location of the declaration name.
name|SourceLocation
name|getLoc
argument_list|()
specifier|const
block|{
return|return
name|NameLoc
return|;
block|}
comment|/// setLoc - Sets the main location of the declaration name.
name|void
name|setLoc
parameter_list|(
name|SourceLocation
name|L
parameter_list|)
block|{
name|NameLoc
operator|=
name|L
expr_stmt|;
block|}
specifier|const
name|DeclarationNameLoc
operator|&
name|getInfo
argument_list|()
specifier|const
block|{
return|return
name|LocInfo
return|;
block|}
name|DeclarationNameLoc
modifier|&
name|getInfo
parameter_list|()
block|{
return|return
name|LocInfo
return|;
block|}
name|void
name|setInfo
parameter_list|(
specifier|const
name|DeclarationNameLoc
modifier|&
name|Info
parameter_list|)
block|{
name|LocInfo
operator|=
name|Info
expr_stmt|;
block|}
comment|/// getNamedTypeInfo - Returns the source type info associated to
comment|/// the name. Assumes it is a constructor, destructor or conversion.
name|TypeSourceInfo
operator|*
name|getNamedTypeInfo
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
name|Name
operator|.
name|getNameKind
argument_list|()
operator|==
name|DeclarationName
operator|::
name|CXXConstructorName
operator|||
name|Name
operator|.
name|getNameKind
argument_list|()
operator|==
name|DeclarationName
operator|::
name|CXXDestructorName
operator|||
name|Name
operator|.
name|getNameKind
argument_list|()
operator|==
name|DeclarationName
operator|::
name|CXXConversionFunctionName
argument_list|)
block|;
return|return
name|LocInfo
operator|.
name|NamedType
operator|.
name|TInfo
return|;
block|}
comment|/// setNamedTypeInfo - Sets the source type info associated to
comment|/// the name. Assumes it is a constructor, destructor or conversion.
name|void
name|setNamedTypeInfo
parameter_list|(
name|TypeSourceInfo
modifier|*
name|TInfo
parameter_list|)
block|{
name|assert
argument_list|(
name|Name
operator|.
name|getNameKind
argument_list|()
operator|==
name|DeclarationName
operator|::
name|CXXConstructorName
operator|||
name|Name
operator|.
name|getNameKind
argument_list|()
operator|==
name|DeclarationName
operator|::
name|CXXDestructorName
operator|||
name|Name
operator|.
name|getNameKind
argument_list|()
operator|==
name|DeclarationName
operator|::
name|CXXConversionFunctionName
argument_list|)
expr_stmt|;
name|LocInfo
operator|.
name|NamedType
operator|.
name|TInfo
operator|=
name|TInfo
expr_stmt|;
block|}
comment|/// getCXXOperatorNameRange - Gets the range of the operator name
comment|/// (without the operator keyword). Assumes it is a (non-literal) operator.
name|SourceRange
name|getCXXOperatorNameRange
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
name|Name
operator|.
name|getNameKind
argument_list|()
operator|==
name|DeclarationName
operator|::
name|CXXOperatorName
argument_list|)
block|;
return|return
name|SourceRange
argument_list|(
name|SourceLocation
operator|::
name|getFromRawEncoding
argument_list|(
name|LocInfo
operator|.
name|CXXOperatorName
operator|.
name|BeginOpNameLoc
argument_list|)
argument_list|,
name|SourceLocation
operator|::
name|getFromRawEncoding
argument_list|(
name|LocInfo
operator|.
name|CXXOperatorName
operator|.
name|EndOpNameLoc
argument_list|)
argument_list|)
return|;
block|}
comment|/// setCXXOperatorNameRange - Sets the range of the operator name
comment|/// (without the operator keyword). Assumes it is a C++ operator.
name|void
name|setCXXOperatorNameRange
parameter_list|(
name|SourceRange
name|R
parameter_list|)
block|{
name|assert
argument_list|(
name|Name
operator|.
name|getNameKind
argument_list|()
operator|==
name|DeclarationName
operator|::
name|CXXOperatorName
argument_list|)
expr_stmt|;
name|LocInfo
operator|.
name|CXXOperatorName
operator|.
name|BeginOpNameLoc
operator|=
name|R
operator|.
name|getBegin
argument_list|()
operator|.
name|getRawEncoding
argument_list|()
expr_stmt|;
name|LocInfo
operator|.
name|CXXOperatorName
operator|.
name|EndOpNameLoc
operator|=
name|R
operator|.
name|getEnd
argument_list|()
operator|.
name|getRawEncoding
argument_list|()
expr_stmt|;
block|}
comment|/// getCXXLiteralOperatorNameLoc - Returns the location of the literal
comment|/// operator name (not the operator keyword).
comment|/// Assumes it is a literal operator.
name|SourceLocation
name|getCXXLiteralOperatorNameLoc
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
name|Name
operator|.
name|getNameKind
argument_list|()
operator|==
name|DeclarationName
operator|::
name|CXXLiteralOperatorName
argument_list|)
block|;
return|return
name|SourceLocation
operator|::
name|getFromRawEncoding
argument_list|(
name|LocInfo
operator|.
name|CXXLiteralOperatorName
operator|.
name|OpNameLoc
argument_list|)
return|;
block|}
comment|/// setCXXLiteralOperatorNameLoc - Sets the location of the literal
comment|/// operator name (not the operator keyword).
comment|/// Assumes it is a literal operator.
name|void
name|setCXXLiteralOperatorNameLoc
parameter_list|(
name|SourceLocation
name|Loc
parameter_list|)
block|{
name|assert
argument_list|(
name|Name
operator|.
name|getNameKind
argument_list|()
operator|==
name|DeclarationName
operator|::
name|CXXLiteralOperatorName
argument_list|)
expr_stmt|;
name|LocInfo
operator|.
name|CXXLiteralOperatorName
operator|.
name|OpNameLoc
operator|=
name|Loc
operator|.
name|getRawEncoding
argument_list|()
expr_stmt|;
block|}
comment|/// \brief Determine whether this name involves a template parameter.
name|bool
name|isInstantiationDependent
argument_list|()
specifier|const
expr_stmt|;
comment|/// \brief Determine whether this name contains an unexpanded
comment|/// parameter pack.
name|bool
name|containsUnexpandedParameterPack
argument_list|()
specifier|const
expr_stmt|;
comment|/// getAsString - Retrieve the human-readable string for this name.
name|std
operator|::
name|string
name|getAsString
argument_list|()
specifier|const
expr_stmt|;
comment|/// printName - Print the human-readable name to a stream.
name|void
name|printName
argument_list|(
name|raw_ostream
operator|&
name|OS
argument_list|)
decl|const
decl_stmt|;
comment|/// getBeginLoc - Retrieve the location of the first token.
name|SourceLocation
name|getBeginLoc
argument_list|()
specifier|const
block|{
return|return
name|NameLoc
return|;
block|}
comment|/// getEndLoc - Retrieve the location of the last token.
name|SourceLocation
name|getEndLoc
argument_list|()
specifier|const
expr_stmt|;
comment|/// getSourceRange - The range of the declaration name.
name|SourceRange
name|getSourceRange
argument_list|()
specifier|const
name|LLVM_READONLY
block|{
return|return
name|SourceRange
argument_list|(
name|getLocStart
argument_list|()
argument_list|,
name|getLocEnd
argument_list|()
argument_list|)
return|;
block|}
name|SourceLocation
name|getLocStart
argument_list|()
specifier|const
name|LLVM_READONLY
block|{
return|return
name|getBeginLoc
argument_list|()
return|;
block|}
name|SourceLocation
name|getLocEnd
argument_list|()
specifier|const
name|LLVM_READONLY
block|{
name|SourceLocation
name|EndLoc
operator|=
name|getEndLoc
argument_list|()
block|;
return|return
name|EndLoc
operator|.
name|isValid
argument_list|()
condition|?
name|EndLoc
else|:
name|getLocStart
argument_list|()
return|;
block|}
block|}
struct|;
end_struct

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
name|DiagnosticsEngine
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
name|DiagnosticsEngine
operator|::
name|ak_declarationname
argument_list|)
block|;
return|return
name|PD
return|;
block|}
end_expr_stmt

begin_expr_stmt
specifier|inline
name|raw_ostream
operator|&
name|operator
operator|<<
operator|(
name|raw_ostream
operator|&
name|OS
operator|,
name|DeclarationNameInfo
name|DNInfo
operator|)
block|{
name|DNInfo
operator|.
name|printName
argument_list|(
name|OS
argument_list|)
block|;
return|return
name|OS
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
name|Name
argument_list|)
block|{
return|return
name|DenseMapInfo
operator|<
name|void
operator|*
operator|>
operator|::
name|getHashValue
argument_list|(
name|Name
operator|.
name|getAsOpaquePtr
argument_list|()
argument_list|)
return|;
block|}
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
block|}
end_block

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_expr_stmt
name|template
operator|<
operator|>
expr|struct
name|isPodLike
operator|<
name|clang
operator|::
name|DeclarationName
operator|>
block|{
specifier|static
specifier|const
name|bool
name|value
operator|=
name|true
block|; }
expr_stmt|;
end_expr_stmt

begin_comment
unit|}
comment|// end namespace llvm
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

