begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===--- Decl.h - Classes for representing declarations ---------*- C++ -*-===//
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
comment|//  This file defines the Decl subclasses.
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
name|LLVM_CLANG_AST_DECL_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_AST_DECL_H
end_define

begin_include
include|#
directive|include
file|"clang/AST/APValue.h"
end_include

begin_include
include|#
directive|include
file|"clang/AST/DeclBase.h"
end_include

begin_include
include|#
directive|include
file|"clang/AST/Redeclarable.h"
end_include

begin_include
include|#
directive|include
file|"clang/AST/DeclarationName.h"
end_include

begin_include
include|#
directive|include
file|"clang/AST/ExternalASTSource.h"
end_include

begin_include
include|#
directive|include
file|"clang/Basic/Linkage.h"
end_include

begin_decl_stmt
name|namespace
name|clang
block|{
name|class
name|CXXTemporary
decl_stmt|;
name|class
name|Expr
decl_stmt|;
name|class
name|FunctionTemplateDecl
decl_stmt|;
name|class
name|Stmt
decl_stmt|;
name|class
name|CompoundStmt
decl_stmt|;
name|class
name|StringLiteral
decl_stmt|;
name|class
name|NestedNameSpecifier
decl_stmt|;
name|class
name|TemplateParameterList
decl_stmt|;
name|class
name|TemplateArgumentList
decl_stmt|;
name|class
name|MemberSpecializationInfo
decl_stmt|;
name|class
name|FunctionTemplateSpecializationInfo
decl_stmt|;
name|class
name|DependentFunctionTemplateSpecializationInfo
decl_stmt|;
name|class
name|TypeLoc
decl_stmt|;
name|class
name|UnresolvedSetImpl
decl_stmt|;
name|class
name|LabelStmt
decl_stmt|;
comment|/// \brief A container of type source information.
comment|///
comment|/// A client can read the relevant info using TypeLoc wrappers, e.g:
comment|/// @code
comment|/// TypeLoc TL = TypeSourceInfo->getTypeLoc();
comment|/// if (PointerLoc *PL = dyn_cast<PointerLoc>(&TL))
comment|///   PL->getStarLoc().print(OS, SrcMgr);
comment|/// @endcode
comment|///
name|class
name|TypeSourceInfo
block|{
name|QualType
name|Ty
decl_stmt|;
comment|// Contains a memory block after the class, used for type source information,
comment|// allocated by ASTContext.
name|friend
name|class
name|ASTContext
decl_stmt|;
name|TypeSourceInfo
argument_list|(
argument|QualType ty
argument_list|)
block|:
name|Ty
argument_list|(
argument|ty
argument_list|)
block|{ }
name|public
label|:
comment|/// \brief Return the type wrapped by this type source info.
name|QualType
name|getType
argument_list|()
specifier|const
block|{
return|return
name|Ty
return|;
block|}
comment|/// \brief Return the TypeLoc wrapper for the type source info.
name|TypeLoc
name|getTypeLoc
argument_list|()
specifier|const
expr_stmt|;
comment|// implemented in TypeLoc.h
block|}
empty_stmt|;
comment|/// TranslationUnitDecl - The top declaration context.
name|class
name|TranslationUnitDecl
range|:
name|public
name|Decl
decl_stmt|,
name|public
name|DeclContext
block|{
name|ASTContext
modifier|&
name|Ctx
decl_stmt|;
comment|/// The (most recently entered) anonymous namespace for this
comment|/// translation unit, if one has been created.
name|NamespaceDecl
modifier|*
name|AnonymousNamespace
decl_stmt|;
name|explicit
name|TranslationUnitDecl
argument_list|(
name|ASTContext
operator|&
name|ctx
argument_list|)
operator|:
name|Decl
argument_list|(
name|TranslationUnit
argument_list|,
literal|0
argument_list|,
name|SourceLocation
argument_list|()
argument_list|)
operator|,
name|DeclContext
argument_list|(
name|TranslationUnit
argument_list|)
operator|,
name|Ctx
argument_list|(
name|ctx
argument_list|)
operator|,
name|AnonymousNamespace
argument_list|(
literal|0
argument_list|)
block|{}
name|public
operator|:
name|ASTContext
operator|&
name|getASTContext
argument_list|()
specifier|const
block|{
return|return
name|Ctx
return|;
block|}
name|NamespaceDecl
operator|*
name|getAnonymousNamespace
argument_list|()
specifier|const
block|{
return|return
name|AnonymousNamespace
return|;
block|}
name|void
name|setAnonymousNamespace
parameter_list|(
name|NamespaceDecl
modifier|*
name|D
parameter_list|)
block|{
name|AnonymousNamespace
operator|=
name|D
expr_stmt|;
block|}
specifier|static
name|TranslationUnitDecl
modifier|*
name|Create
parameter_list|(
name|ASTContext
modifier|&
name|C
parameter_list|)
function_decl|;
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
name|TranslationUnitDecl
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
name|TranslationUnit
return|;
block|}
specifier|static
name|DeclContext
modifier|*
name|castToDeclContext
parameter_list|(
specifier|const
name|TranslationUnitDecl
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
name|TranslationUnitDecl
operator|*
operator|>
operator|(
name|D
operator|)
operator|)
return|;
block|}
specifier|static
name|TranslationUnitDecl
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
name|TranslationUnitDecl
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
empty_stmt|;
comment|/// NamedDecl - This represents a decl with a name.  Many decls have names such
comment|/// as ObjCMethodDecl, but not @class, etc.
name|class
name|NamedDecl
range|:
name|public
name|Decl
block|{
comment|/// Name - The name of this declaration, which is typically a normal
comment|/// identifier but may also be a special kind of name (C++
comment|/// constructor, Objective-C selector, etc.)
name|DeclarationName
name|Name
block|;
name|protected
operator|:
name|NamedDecl
argument_list|(
argument|Kind DK
argument_list|,
argument|DeclContext *DC
argument_list|,
argument|SourceLocation L
argument_list|,
argument|DeclarationName N
argument_list|)
operator|:
name|Decl
argument_list|(
name|DK
argument_list|,
name|DC
argument_list|,
name|L
argument_list|)
block|,
name|Name
argument_list|(
argument|N
argument_list|)
block|{ }
name|public
operator|:
comment|/// getIdentifier - Get the identifier that names this declaration,
comment|/// if there is one. This will return NULL if this declaration has
comment|/// no name (e.g., for an unnamed class) or if the name is a special
comment|/// name (C++ constructor, Objective-C selector, etc.).
name|IdentifierInfo
operator|*
name|getIdentifier
argument_list|()
specifier|const
block|{
return|return
name|Name
operator|.
name|getAsIdentifierInfo
argument_list|()
return|;
block|}
comment|/// getName - Get the name of identifier for this declaration as a StringRef.
comment|/// This requires that the declaration have a name and that it be a simple
comment|/// identifier.
name|llvm
operator|::
name|StringRef
name|getName
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
name|Name
operator|.
name|isIdentifier
argument_list|()
operator|&&
literal|"Name is not a simple identifier"
argument_list|)
block|;
return|return
name|getIdentifier
argument_list|()
condition|?
name|getIdentifier
argument_list|()
operator|->
name|getName
argument_list|()
else|:
literal|""
return|;
block|}
name|llvm
operator|::
name|StringRef
name|getMessageUnavailableAttr
argument_list|(
argument|bool unavailable
argument_list|)
specifier|const
block|{
if|if
condition|(
operator|!
name|unavailable
condition|)
return|return
literal|""
return|;
if|if
condition|(
specifier|const
name|UnavailableAttr
modifier|*
name|UA
init|=
name|getAttr
operator|<
name|UnavailableAttr
operator|>
operator|(
operator|)
condition|)
return|return
name|UA
operator|->
name|getMessage
argument_list|()
return|;
return|return
literal|""
return|;
block|}
end_decl_stmt

begin_comment
comment|/// getNameAsString - Get a human-readable name for the declaration, even if
end_comment

begin_comment
comment|/// it is one of the special kinds of names (C++ constructor, Objective-C
end_comment

begin_comment
comment|/// selector, etc).  Creating this name requires expensive string
end_comment

begin_comment
comment|/// manipulation, so it should be called only when performance doesn't matter.
end_comment

begin_comment
comment|/// For simple declarations, getNameAsCString() should suffice.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// FIXME: This function should be renamed to indicate that it is not just an
end_comment

begin_comment
comment|// alternate form of getName(), and clients should move as appropriate.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// FIXME: Deprecated, move clients to getName().
end_comment

begin_expr_stmt
name|std
operator|::
name|string
name|getNameAsString
argument_list|()
specifier|const
block|{
return|return
name|Name
operator|.
name|getAsString
argument_list|()
return|;
block|}
end_expr_stmt

begin_decl_stmt
name|void
name|printName
argument_list|(
name|llvm
operator|::
name|raw_ostream
operator|&
name|os
argument_list|)
decl|const
block|{
return|return
name|Name
operator|.
name|printName
argument_list|(
name|os
argument_list|)
return|;
block|}
end_decl_stmt

begin_comment
comment|/// getDeclName - Get the actual, stored name of the declaration,
end_comment

begin_comment
comment|/// which may be a special name.
end_comment

begin_expr_stmt
name|DeclarationName
name|getDeclName
argument_list|()
specifier|const
block|{
return|return
name|Name
return|;
block|}
end_expr_stmt

begin_comment
comment|/// \brief Set the name of this declaration.
end_comment

begin_function
name|void
name|setDeclName
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
end_function

begin_comment
comment|/// getQualifiedNameAsString - Returns human-readable qualified name for
end_comment

begin_comment
comment|/// declaration, like A::B::i, for i being member of namespace A::B.
end_comment

begin_comment
comment|/// If declaration is not member of context which can be named (record,
end_comment

begin_comment
comment|/// namespace), it will return same result as getNameAsString().
end_comment

begin_comment
comment|/// Creating this name is expensive, so it should be called only when
end_comment

begin_comment
comment|/// performance doesn't matter.
end_comment

begin_expr_stmt
name|std
operator|::
name|string
name|getQualifiedNameAsString
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|std
operator|::
name|string
name|getQualifiedNameAsString
argument_list|(
argument|const PrintingPolicy&Policy
argument_list|)
specifier|const
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// getNameForDiagnostic - Appends a human-readable name for this
end_comment

begin_comment
comment|/// declaration into the given string.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This is the method invoked by Sema when displaying a NamedDecl
end_comment

begin_comment
comment|/// in a diagnostic.  It does not necessarily produce the same
end_comment

begin_comment
comment|/// result as getNameAsString(); for example, class template
end_comment

begin_comment
comment|/// specializations are printed with their template arguments.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// TODO: use an API that doesn't require so many temporary strings
end_comment

begin_decl_stmt
name|virtual
name|void
name|getNameForDiagnostic
argument_list|(
name|std
operator|::
name|string
operator|&
name|S
argument_list|,
specifier|const
name|PrintingPolicy
operator|&
name|Policy
argument_list|,
name|bool
name|Qualified
argument_list|)
decl|const
block|{
if|if
condition|(
name|Qualified
condition|)
name|S
operator|+=
name|getQualifiedNameAsString
argument_list|(
name|Policy
argument_list|)
expr_stmt|;
else|else
name|S
operator|+=
name|getNameAsString
argument_list|()
expr_stmt|;
block|}
end_decl_stmt

begin_comment
comment|/// declarationReplaces - Determine whether this declaration, if
end_comment

begin_comment
comment|/// known to be well-formed within its context, will replace the
end_comment

begin_comment
comment|/// declaration OldD if introduced into scope. A declaration will
end_comment

begin_comment
comment|/// replace another declaration if, for example, it is a
end_comment

begin_comment
comment|/// redeclaration of the same variable or function, but not if it is
end_comment

begin_comment
comment|/// a declaration of a different kind (function vs. class) or an
end_comment

begin_comment
comment|/// overloaded function.
end_comment

begin_decl_stmt
name|bool
name|declarationReplaces
argument_list|(
name|NamedDecl
operator|*
name|OldD
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// \brief Determine whether this declaration has linkage.
end_comment

begin_expr_stmt
name|bool
name|hasLinkage
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// \brief Determine whether this declaration is a C++ class member.
end_comment

begin_expr_stmt
name|bool
name|isCXXClassMember
argument_list|()
specifier|const
block|{
specifier|const
name|DeclContext
operator|*
name|DC
operator|=
name|getDeclContext
argument_list|()
block|;
comment|// C++0x [class.mem]p1:
comment|//   The enumerators of an unscoped enumeration defined in
comment|//   the class are members of the class.
comment|// FIXME: support C++0x scoped enumerations.
if|if
condition|(
name|isa
operator|<
name|EnumDecl
operator|>
operator|(
name|DC
operator|)
condition|)
name|DC
operator|=
name|DC
operator|->
name|getParent
argument_list|()
expr_stmt|;
end_expr_stmt

begin_return
return|return
name|DC
operator|->
name|isRecord
argument_list|()
return|;
end_return

begin_comment
unit|}
comment|/// \brief Given that this declaration is a C++ class member,
end_comment

begin_comment
comment|/// determine whether it's an instance member of its class.
end_comment

begin_macro
unit|bool
name|isCXXInstanceMember
argument_list|()
end_macro

begin_decl_stmt
specifier|const
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|class
name|LinkageInfo
block|{
name|Linkage
name|linkage_
decl_stmt|;
name|Visibility
name|visibility_
decl_stmt|;
name|bool
name|explicit_
decl_stmt|;
name|public
label|:
name|LinkageInfo
argument_list|()
operator|:
name|linkage_
argument_list|(
name|ExternalLinkage
argument_list|)
operator|,
name|visibility_
argument_list|(
name|DefaultVisibility
argument_list|)
operator|,
name|explicit_
argument_list|(
argument|false
argument_list|)
block|{}
name|LinkageInfo
argument_list|(
argument|Linkage L
argument_list|,
argument|Visibility V
argument_list|,
argument|bool E
argument_list|)
operator|:
name|linkage_
argument_list|(
name|L
argument_list|)
operator|,
name|visibility_
argument_list|(
name|V
argument_list|)
operator|,
name|explicit_
argument_list|(
argument|E
argument_list|)
block|{}
specifier|static
name|LinkageInfo
name|external
argument_list|()
block|{
return|return
name|LinkageInfo
argument_list|()
return|;
block|}
specifier|static
name|LinkageInfo
name|internal
parameter_list|()
block|{
return|return
name|LinkageInfo
argument_list|(
name|InternalLinkage
argument_list|,
name|DefaultVisibility
argument_list|,
name|false
argument_list|)
return|;
block|}
specifier|static
name|LinkageInfo
name|uniqueExternal
parameter_list|()
block|{
return|return
name|LinkageInfo
argument_list|(
name|UniqueExternalLinkage
argument_list|,
name|DefaultVisibility
argument_list|,
name|false
argument_list|)
return|;
block|}
specifier|static
name|LinkageInfo
name|none
parameter_list|()
block|{
return|return
name|LinkageInfo
argument_list|(
name|NoLinkage
argument_list|,
name|DefaultVisibility
argument_list|,
name|false
argument_list|)
return|;
block|}
name|Linkage
name|linkage
argument_list|()
specifier|const
block|{
return|return
name|linkage_
return|;
block|}
name|Visibility
name|visibility
argument_list|()
specifier|const
block|{
return|return
name|visibility_
return|;
block|}
name|bool
name|visibilityExplicit
argument_list|()
specifier|const
block|{
return|return
name|explicit_
return|;
block|}
name|void
name|setLinkage
parameter_list|(
name|Linkage
name|L
parameter_list|)
block|{
name|linkage_
operator|=
name|L
expr_stmt|;
block|}
name|void
name|setVisibility
parameter_list|(
name|Visibility
name|V
parameter_list|)
block|{
name|visibility_
operator|=
name|V
expr_stmt|;
block|}
name|void
name|setVisibility
parameter_list|(
name|Visibility
name|V
parameter_list|,
name|bool
name|E
parameter_list|)
block|{
name|visibility_
operator|=
name|V
expr_stmt|;
name|explicit_
operator|=
name|E
expr_stmt|;
block|}
name|void
name|setVisibility
parameter_list|(
name|LinkageInfo
name|Other
parameter_list|)
block|{
name|setVisibility
argument_list|(
name|Other
operator|.
name|visibility
argument_list|()
argument_list|,
name|Other
operator|.
name|visibilityExplicit
argument_list|()
argument_list|)
expr_stmt|;
block|}
name|void
name|mergeLinkage
parameter_list|(
name|Linkage
name|L
parameter_list|)
block|{
name|setLinkage
argument_list|(
name|minLinkage
argument_list|(
name|linkage
argument_list|()
argument_list|,
name|L
argument_list|)
argument_list|)
expr_stmt|;
block|}
name|void
name|mergeLinkage
parameter_list|(
name|LinkageInfo
name|Other
parameter_list|)
block|{
name|setLinkage
argument_list|(
name|minLinkage
argument_list|(
name|linkage
argument_list|()
argument_list|,
name|Other
operator|.
name|linkage
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
block|}
name|void
name|mergeVisibility
parameter_list|(
name|Visibility
name|V
parameter_list|)
block|{
name|setVisibility
argument_list|(
name|minVisibility
argument_list|(
name|visibility
argument_list|()
argument_list|,
name|V
argument_list|)
argument_list|)
expr_stmt|;
block|}
name|void
name|mergeVisibility
parameter_list|(
name|Visibility
name|V
parameter_list|,
name|bool
name|E
parameter_list|)
block|{
name|setVisibility
argument_list|(
name|minVisibility
argument_list|(
name|visibility
argument_list|()
argument_list|,
name|V
argument_list|)
argument_list|,
name|visibilityExplicit
argument_list|()
operator|||
name|E
argument_list|)
expr_stmt|;
block|}
name|void
name|mergeVisibility
parameter_list|(
name|LinkageInfo
name|Other
parameter_list|)
block|{
name|mergeVisibility
argument_list|(
name|Other
operator|.
name|visibility
argument_list|()
argument_list|,
name|Other
operator|.
name|visibilityExplicit
argument_list|()
argument_list|)
expr_stmt|;
block|}
name|void
name|merge
parameter_list|(
name|LinkageInfo
name|Other
parameter_list|)
block|{
name|mergeLinkage
argument_list|(
name|Other
argument_list|)
expr_stmt|;
name|mergeVisibility
argument_list|(
name|Other
argument_list|)
expr_stmt|;
block|}
name|void
name|merge
argument_list|(
name|std
operator|::
name|pair
operator|<
name|Linkage
argument_list|,
name|Visibility
operator|>
name|LV
argument_list|)
block|{
name|mergeLinkage
argument_list|(
name|LV
operator|.
name|first
argument_list|)
expr_stmt|;
name|mergeVisibility
argument_list|(
name|LV
operator|.
name|second
argument_list|)
expr_stmt|;
block|}
name|friend
name|LinkageInfo
name|merge
parameter_list|(
name|LinkageInfo
name|L
parameter_list|,
name|LinkageInfo
name|R
parameter_list|)
block|{
name|L
operator|.
name|merge
argument_list|(
name|R
argument_list|)
expr_stmt|;
return|return
name|L
return|;
block|}
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|/// \brief Determine what kind of linkage this entity has.
end_comment

begin_expr_stmt
name|Linkage
name|getLinkage
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// \brief Determines the visibility of this entity.
end_comment

begin_expr_stmt
name|Visibility
name|getVisibility
argument_list|()
specifier|const
block|{
return|return
name|getLinkageAndVisibility
argument_list|()
operator|.
name|visibility
argument_list|()
return|;
block|}
end_expr_stmt

begin_comment
comment|/// \brief Determines the linkage and visibility of this entity.
end_comment

begin_expr_stmt
name|LinkageInfo
name|getLinkageAndVisibility
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// \brief Clear the linkage cache in response to a change
end_comment

begin_comment
comment|/// to the declaration.
end_comment

begin_function_decl
name|void
name|ClearLinkageCache
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/// \brief Looks through UsingDecls and ObjCCompatibleAliasDecls for
end_comment

begin_comment
comment|/// the underlying named decl.
end_comment

begin_function_decl
name|NamedDecl
modifier|*
name|getUnderlyingDecl
parameter_list|()
function_decl|;
end_function_decl

begin_expr_stmt
specifier|const
name|NamedDecl
operator|*
name|getUnderlyingDecl
argument_list|()
specifier|const
block|{
return|return
name|const_cast
operator|<
name|NamedDecl
operator|*
operator|>
operator|(
name|this
operator|)
operator|->
name|getUnderlyingDecl
argument_list|()
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
name|NamedDecl
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
name|firstNamed
operator|&&
name|K
operator|<=
name|lastNamed
return|;
block|}
end_function

begin_expr_stmt
unit|};
specifier|inline
name|llvm
operator|::
name|raw_ostream
operator|&
name|operator
operator|<<
operator|(
name|llvm
operator|::
name|raw_ostream
operator|&
name|OS
operator|,
specifier|const
name|NamedDecl
operator|*
name|ND
operator|)
block|{
name|ND
operator|->
name|getDeclName
argument_list|()
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
comment|/// LabelDecl - Represents the declaration of a label.  Labels also have a
end_comment

begin_comment
comment|/// corresponding LabelStmt, which indicates the position that the label was
end_comment

begin_comment
comment|/// defined at.  For normal labels, the location of the decl is the same as the
end_comment

begin_comment
comment|/// location of the statement.  For GNU local labels (__label__), the decl
end_comment

begin_comment
comment|/// location is where the __label__ is.
end_comment

begin_decl_stmt
name|class
name|LabelDecl
range|:
name|public
name|NamedDecl
block|{
name|LabelStmt
operator|*
name|TheStmt
block|;
name|LabelDecl
argument_list|(
argument|DeclContext *DC
argument_list|,
argument|SourceLocation L
argument_list|,
argument|IdentifierInfo *II
argument_list|,
argument|LabelStmt *S
argument_list|)
operator|:
name|NamedDecl
argument_list|(
name|Label
argument_list|,
name|DC
argument_list|,
name|L
argument_list|,
name|II
argument_list|)
block|,
name|TheStmt
argument_list|(
argument|S
argument_list|)
block|{}
name|public
operator|:
specifier|static
name|LabelDecl
operator|*
name|Create
argument_list|(
argument|ASTContext&C
argument_list|,
argument|DeclContext *DC
argument_list|,
argument|SourceLocation L
argument_list|,
argument|IdentifierInfo *II
argument_list|)
block|;
name|LabelStmt
operator|*
name|getStmt
argument_list|()
specifier|const
block|{
return|return
name|TheStmt
return|;
block|}
name|void
name|setStmt
argument_list|(
argument|LabelStmt *T
argument_list|)
block|{
name|TheStmt
operator|=
name|T
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
argument|const LabelDecl *D
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
name|Label
return|;
block|}
expr|}
block|;
comment|/// NamespaceDecl - Represent a C++ namespace.
name|class
name|NamespaceDecl
operator|:
name|public
name|NamedDecl
block|,
name|public
name|DeclContext
block|{
name|bool
name|IsInline
operator|:
literal|1
block|;
name|SourceLocation
name|LBracLoc
block|,
name|RBracLoc
block|;
comment|// For extended namespace definitions:
comment|//
comment|// namespace A { int x; }
comment|// namespace A { int y; }
comment|//
comment|// there will be one NamespaceDecl for each declaration.
comment|// NextNamespace points to the next extended declaration.
comment|// OrigNamespace points to the original namespace declaration.
comment|// OrigNamespace of the first namespace decl points to its anonymous namespace
name|LazyDeclPtr
name|NextNamespace
block|;
comment|/// \brief A pointer to either the original namespace definition for
comment|/// this namespace (if the boolean value is false) or the anonymous
comment|/// namespace that lives just inside this namespace (if the boolean
comment|/// value is true).
comment|///
comment|/// We can combine these two notions because the anonymous namespace
comment|/// must only be stored in one of the namespace declarations (so all
comment|/// of the namespace declarations can find it). We therefore choose
comment|/// the original namespace declaration, since all of the namespace
comment|/// declarations have a link directly to it; the original namespace
comment|/// declaration itself only needs to know that it is the original
comment|/// namespace declaration (which the boolean indicates).
name|llvm
operator|::
name|PointerIntPair
operator|<
name|NamespaceDecl
operator|*
block|,
literal|1
block|,
name|bool
operator|>
name|OrigOrAnonNamespace
block|;
name|NamespaceDecl
argument_list|(
argument|DeclContext *DC
argument_list|,
argument|SourceLocation L
argument_list|,
argument|IdentifierInfo *Id
argument_list|)
operator|:
name|NamedDecl
argument_list|(
name|Namespace
argument_list|,
name|DC
argument_list|,
name|L
argument_list|,
name|Id
argument_list|)
block|,
name|DeclContext
argument_list|(
name|Namespace
argument_list|)
block|,
name|IsInline
argument_list|(
name|false
argument_list|)
block|,
name|NextNamespace
argument_list|()
block|,
name|OrigOrAnonNamespace
argument_list|(
literal|0
argument_list|,
argument|true
argument_list|)
block|{ }
name|public
operator|:
specifier|static
name|NamespaceDecl
operator|*
name|Create
argument_list|(
argument|ASTContext&C
argument_list|,
argument|DeclContext *DC
argument_list|,
argument|SourceLocation L
argument_list|,
argument|IdentifierInfo *Id
argument_list|)
block|;
comment|/// \brief Returns true if this is an anonymous namespace declaration.
comment|///
comment|/// For example:
comment|/// \code
comment|///   namespace {
comment|///     ...
comment|///   };
comment|/// \endcode
comment|/// q.v. C++ [namespace.unnamed]
name|bool
name|isAnonymousNamespace
argument_list|()
specifier|const
block|{
return|return
operator|!
name|getIdentifier
argument_list|()
return|;
block|}
comment|/// \brief Returns true if this is an inline namespace declaration.
name|bool
name|isInline
argument_list|()
specifier|const
block|{
return|return
name|IsInline
return|;
block|}
comment|/// \brief Set whether this is an inline namespace declaration.
name|void
name|setInline
argument_list|(
argument|bool Inline
argument_list|)
block|{
name|IsInline
operator|=
name|Inline
block|;   }
comment|/// \brief Return the next extended namespace declaration or null if there
comment|/// is none.
name|NamespaceDecl
operator|*
name|getNextNamespace
argument_list|()
block|;
specifier|const
name|NamespaceDecl
operator|*
name|getNextNamespace
argument_list|()
specifier|const
block|{
return|return
name|const_cast
operator|<
name|NamespaceDecl
operator|*
operator|>
operator|(
name|this
operator|)
operator|->
name|getNextNamespace
argument_list|()
return|;
block|}
comment|/// \brief Set the next extended namespace declaration.
name|void
name|setNextNamespace
argument_list|(
argument|NamespaceDecl *ND
argument_list|)
block|{
name|NextNamespace
operator|=
name|ND
block|; }
comment|/// \brief Get the original (first) namespace declaration.
name|NamespaceDecl
operator|*
name|getOriginalNamespace
argument_list|()
specifier|const
block|{
if|if
condition|(
name|OrigOrAnonNamespace
operator|.
name|getInt
argument_list|()
condition|)
return|return
name|const_cast
operator|<
name|NamespaceDecl
operator|*
operator|>
operator|(
name|this
operator|)
return|;
return|return
name|OrigOrAnonNamespace
operator|.
name|getPointer
argument_list|()
return|;
block|}
comment|/// \brief Return true if this declaration is an original (first) declaration
comment|/// of the namespace. This is false for non-original (subsequent) namespace
comment|/// declarations and anonymous namespaces.
name|bool
name|isOriginalNamespace
argument_list|()
specifier|const
block|{
return|return
name|getOriginalNamespace
argument_list|()
operator|==
name|this
return|;
block|}
comment|/// \brief Set the original (first) namespace declaration.
name|void
name|setOriginalNamespace
argument_list|(
argument|NamespaceDecl *ND
argument_list|)
block|{
if|if
condition|(
name|ND
operator|!=
name|this
condition|)
block|{
name|OrigOrAnonNamespace
operator|.
name|setPointer
argument_list|(
name|ND
argument_list|)
expr_stmt|;
name|OrigOrAnonNamespace
operator|.
name|setInt
argument_list|(
name|false
argument_list|)
expr_stmt|;
block|}
block|}
name|NamespaceDecl
operator|*
name|getAnonymousNamespace
argument_list|()
specifier|const
block|{
return|return
name|getOriginalNamespace
argument_list|()
operator|->
name|OrigOrAnonNamespace
operator|.
name|getPointer
argument_list|()
return|;
block|}
name|void
name|setAnonymousNamespace
argument_list|(
argument|NamespaceDecl *D
argument_list|)
block|{
name|assert
argument_list|(
operator|!
name|D
operator|||
name|D
operator|->
name|isAnonymousNamespace
argument_list|()
argument_list|)
block|;
name|assert
argument_list|(
operator|!
name|D
operator|||
name|D
operator|->
name|getParent
argument_list|()
operator|==
name|this
argument_list|)
block|;
name|getOriginalNamespace
argument_list|()
operator|->
name|OrigOrAnonNamespace
operator|.
name|setPointer
argument_list|(
name|D
argument_list|)
block|;   }
name|virtual
name|NamespaceDecl
operator|*
name|getCanonicalDecl
argument_list|()
block|{
return|return
name|getOriginalNamespace
argument_list|()
return|;
block|}
specifier|const
name|NamespaceDecl
operator|*
name|getCanonicalDecl
argument_list|()
specifier|const
block|{
return|return
name|getOriginalNamespace
argument_list|()
return|;
block|}
name|virtual
name|SourceRange
name|getSourceRange
argument_list|()
specifier|const
block|{
return|return
name|SourceRange
argument_list|(
name|getLocation
argument_list|()
argument_list|,
name|RBracLoc
argument_list|)
return|;
block|}
name|SourceLocation
name|getLBracLoc
argument_list|()
specifier|const
block|{
return|return
name|LBracLoc
return|;
block|}
name|SourceLocation
name|getRBracLoc
argument_list|()
specifier|const
block|{
return|return
name|RBracLoc
return|;
block|}
name|void
name|setLBracLoc
argument_list|(
argument|SourceLocation L
argument_list|)
block|{
name|LBracLoc
operator|=
name|L
block|; }
name|void
name|setRBracLoc
argument_list|(
argument|SourceLocation R
argument_list|)
block|{
name|RBracLoc
operator|=
name|R
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
argument|const NamespaceDecl *D
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
name|Namespace
return|;
block|}
specifier|static
name|DeclContext
operator|*
name|castToDeclContext
argument_list|(
argument|const NamespaceDecl *D
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
name|NamespaceDecl
operator|*
operator|>
operator|(
name|D
operator|)
operator|)
return|;
block|}
specifier|static
name|NamespaceDecl
operator|*
name|castFromDeclContext
argument_list|(
argument|const DeclContext *DC
argument_list|)
block|{
return|return
name|static_cast
operator|<
name|NamespaceDecl
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
comment|/// ValueDecl - Represent the declaration of a variable (in which case it is
end_comment

begin_comment
comment|/// an lvalue) a function (in which case it is a function designator) or
end_comment

begin_comment
comment|/// an enum constant.
end_comment

begin_decl_stmt
name|class
name|ValueDecl
range|:
name|public
name|NamedDecl
block|{
name|QualType
name|DeclType
block|;
name|protected
operator|:
name|ValueDecl
argument_list|(
argument|Kind DK
argument_list|,
argument|DeclContext *DC
argument_list|,
argument|SourceLocation L
argument_list|,
argument|DeclarationName N
argument_list|,
argument|QualType T
argument_list|)
operator|:
name|NamedDecl
argument_list|(
name|DK
argument_list|,
name|DC
argument_list|,
name|L
argument_list|,
name|N
argument_list|)
block|,
name|DeclType
argument_list|(
argument|T
argument_list|)
block|{}
name|public
operator|:
name|QualType
name|getType
argument_list|()
specifier|const
block|{
return|return
name|DeclType
return|;
block|}
name|void
name|setType
argument_list|(
argument|QualType newType
argument_list|)
block|{
name|DeclType
operator|=
name|newType
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
argument|const ValueDecl *D
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
operator|>=
name|firstValue
operator|&&
name|K
operator|<=
name|lastValue
return|;
block|}
expr|}
block|;
comment|/// QualifierInfo - A struct with extended info about a syntactic
comment|/// name qualifier, to be used for the case of out-of-line declarations.
block|struct
name|QualifierInfo
block|{
name|NestedNameSpecifierLoc
name|QualifierLoc
block|;
comment|/// NumTemplParamLists - The number of template parameter lists
comment|/// that were matched against the template-ids occurring into the NNS.
name|unsigned
name|NumTemplParamLists
block|;
comment|/// TemplParamLists - A new-allocated array of size NumTemplParamLists,
comment|/// containing pointers to the matched template parameter lists.
name|TemplateParameterList
operator|*
operator|*
name|TemplParamLists
block|;
comment|/// Default constructor.
name|QualifierInfo
argument_list|()
operator|:
name|QualifierLoc
argument_list|()
block|,
name|NumTemplParamLists
argument_list|(
literal|0
argument_list|)
block|,
name|TemplParamLists
argument_list|(
literal|0
argument_list|)
block|{}
comment|/// setTemplateParameterListsInfo - Sets info about matched template
comment|/// parameter lists.
name|void
name|setTemplateParameterListsInfo
argument_list|(
argument|ASTContext&Context
argument_list|,
argument|unsigned NumTPLists
argument_list|,
argument|TemplateParameterList **TPLists
argument_list|)
block|;
name|private
operator|:
comment|// Copy constructor and copy assignment are disabled.
name|QualifierInfo
argument_list|(
specifier|const
name|QualifierInfo
operator|&
argument_list|)
block|;
name|QualifierInfo
operator|&
name|operator
operator|=
operator|(
specifier|const
name|QualifierInfo
operator|&
operator|)
block|; }
block|;
comment|/// \brief Represents a ValueDecl that came out of a declarator.
comment|/// Contains type source information through TypeSourceInfo.
name|class
name|DeclaratorDecl
operator|:
name|public
name|ValueDecl
block|{
comment|// A struct representing both a TInfo and a syntactic qualifier,
comment|// to be used for the (uncommon) case of out-of-line declarations.
block|struct
name|ExtInfo
operator|:
name|public
name|QualifierInfo
block|{
name|TypeSourceInfo
operator|*
name|TInfo
block|;   }
block|;
name|llvm
operator|::
name|PointerUnion
operator|<
name|TypeSourceInfo
operator|*
block|,
name|ExtInfo
operator|*
operator|>
name|DeclInfo
block|;
name|bool
name|hasExtInfo
argument_list|()
specifier|const
block|{
return|return
name|DeclInfo
operator|.
name|is
operator|<
name|ExtInfo
operator|*
operator|>
operator|(
operator|)
return|;
block|}
name|ExtInfo
operator|*
name|getExtInfo
argument_list|()
block|{
return|return
name|DeclInfo
operator|.
name|get
operator|<
name|ExtInfo
operator|*
operator|>
operator|(
operator|)
return|;
block|}
specifier|const
name|ExtInfo
operator|*
name|getExtInfo
argument_list|()
specifier|const
block|{
return|return
name|DeclInfo
operator|.
name|get
operator|<
name|ExtInfo
operator|*
operator|>
operator|(
operator|)
return|;
block|}
name|protected
operator|:
name|DeclaratorDecl
argument_list|(
argument|Kind DK
argument_list|,
argument|DeclContext *DC
argument_list|,
argument|SourceLocation L
argument_list|,
argument|DeclarationName N
argument_list|,
argument|QualType T
argument_list|,
argument|TypeSourceInfo *TInfo
argument_list|)
operator|:
name|ValueDecl
argument_list|(
name|DK
argument_list|,
name|DC
argument_list|,
name|L
argument_list|,
name|N
argument_list|,
name|T
argument_list|)
block|,
name|DeclInfo
argument_list|(
argument|TInfo
argument_list|)
block|{}
name|public
operator|:
name|TypeSourceInfo
operator|*
name|getTypeSourceInfo
argument_list|()
specifier|const
block|{
return|return
name|hasExtInfo
argument_list|()
operator|?
name|getExtInfo
argument_list|()
operator|->
name|TInfo
operator|:
name|DeclInfo
operator|.
name|get
operator|<
name|TypeSourceInfo
operator|*
operator|>
operator|(
operator|)
return|;
block|}
name|void
name|setTypeSourceInfo
argument_list|(
argument|TypeSourceInfo *TI
argument_list|)
block|{
if|if
condition|(
name|hasExtInfo
argument_list|()
condition|)
name|getExtInfo
argument_list|()
operator|->
name|TInfo
operator|=
name|TI
expr_stmt|;
else|else
name|DeclInfo
operator|=
name|TI
expr_stmt|;
block|}
comment|/// getInnerLocStart - Return SourceLocation representing start of source
comment|/// range ignoring outer template declarations.
name|virtual
name|SourceLocation
name|getInnerLocStart
argument_list|()
specifier|const
block|{
return|return
name|getLocation
argument_list|()
return|;
block|}
comment|/// getOuterLocStart - Return SourceLocation representing start of source
comment|/// range taking into account any outer template declarations.
name|SourceLocation
name|getOuterLocStart
argument_list|()
specifier|const
block|;
name|SourceRange
name|getSourceRange
argument_list|()
specifier|const
block|{
return|return
name|SourceRange
argument_list|(
name|getOuterLocStart
argument_list|()
argument_list|,
name|getLocation
argument_list|()
argument_list|)
return|;
block|}
comment|/// \brief Retrieve the nested-name-specifier that qualifies the name of this
comment|/// declaration, if it was present in the source.
name|NestedNameSpecifier
operator|*
name|getQualifier
argument_list|()
specifier|const
block|{
return|return
name|hasExtInfo
argument_list|()
operator|?
name|getExtInfo
argument_list|()
operator|->
name|QualifierLoc
operator|.
name|getNestedNameSpecifier
argument_list|()
operator|:
literal|0
return|;
block|}
comment|/// \brief Retrieve the nested-name-specifier (with source-location
comment|/// information) that qualifies the name of this declaration, if it was
comment|/// present in the source.
name|NestedNameSpecifierLoc
name|getQualifierLoc
argument_list|()
specifier|const
block|{
return|return
name|hasExtInfo
argument_list|()
condition|?
name|getExtInfo
argument_list|()
operator|->
name|QualifierLoc
else|:
name|NestedNameSpecifierLoc
argument_list|()
return|;
block|}
name|void
name|setQualifierInfo
argument_list|(
argument|NestedNameSpecifierLoc QualifierLoc
argument_list|)
block|;
name|unsigned
name|getNumTemplateParameterLists
argument_list|()
specifier|const
block|{
return|return
name|hasExtInfo
argument_list|()
condition|?
name|getExtInfo
argument_list|()
operator|->
name|NumTemplParamLists
else|:
literal|0
return|;
block|}
name|TemplateParameterList
operator|*
name|getTemplateParameterList
argument_list|(
argument|unsigned index
argument_list|)
specifier|const
block|{
name|assert
argument_list|(
name|index
operator|<
name|getNumTemplateParameterLists
argument_list|()
argument_list|)
block|;
return|return
name|getExtInfo
argument_list|()
operator|->
name|TemplParamLists
index|[
name|index
index|]
return|;
block|}
name|void
name|setTemplateParameterListsInfo
argument_list|(
argument|ASTContext&Context
argument_list|,
argument|unsigned NumTPLists
argument_list|,
argument|TemplateParameterList **TPLists
argument_list|)
block|{
name|getExtInfo
argument_list|()
operator|->
name|setTemplateParameterListsInfo
argument_list|(
name|Context
argument_list|,
name|NumTPLists
argument_list|,
name|TPLists
argument_list|)
block|;   }
name|SourceLocation
name|getTypeSpecStartLoc
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
name|classof
argument_list|(
argument|const DeclaratorDecl *D
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
operator|>=
name|firstDeclarator
operator|&&
name|K
operator|<=
name|lastDeclarator
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
block|;
comment|/// \brief Structure used to store a statement, the constant value to
comment|/// which it was evaluated (if any), and whether or not the statement
comment|/// is an integral constant expression (if known).
block|struct
name|EvaluatedStmt
block|{
name|EvaluatedStmt
argument_list|()
operator|:
name|WasEvaluated
argument_list|(
name|false
argument_list|)
block|,
name|IsEvaluating
argument_list|(
name|false
argument_list|)
block|,
name|CheckedICE
argument_list|(
name|false
argument_list|)
block|,
name|CheckingICE
argument_list|(
name|false
argument_list|)
block|,
name|IsICE
argument_list|(
argument|false
argument_list|)
block|{ }
comment|/// \brief Whether this statement was already evaluated.
name|bool
name|WasEvaluated
operator|:
literal|1
block|;
comment|/// \brief Whether this statement is being evaluated.
name|bool
name|IsEvaluating
operator|:
literal|1
block|;
comment|/// \brief Whether we already checked whether this statement was an
comment|/// integral constant expression.
name|bool
name|CheckedICE
operator|:
literal|1
block|;
comment|/// \brief Whether we are checking whether this statement is an
comment|/// integral constant expression.
name|bool
name|CheckingICE
operator|:
literal|1
block|;
comment|/// \brief Whether this statement is an integral constant
comment|/// expression. Only valid if CheckedICE is true.
name|bool
name|IsICE
operator|:
literal|1
block|;
name|Stmt
operator|*
name|Value
block|;
name|APValue
name|Evaluated
block|; }
block|;
comment|/// VarDecl - An instance of this class is created to represent a variable
comment|/// declaration or definition.
name|class
name|VarDecl
operator|:
name|public
name|DeclaratorDecl
block|,
name|public
name|Redeclarable
operator|<
name|VarDecl
operator|>
block|{
name|public
operator|:
typedef|typedef
name|clang
operator|::
name|StorageClass
name|StorageClass
expr_stmt|;
comment|/// getStorageClassSpecifierString - Return the string used to
comment|/// specify the storage class \arg SC.
comment|///
comment|/// It is illegal to call this function with SC == None.
specifier|static
specifier|const
name|char
operator|*
name|getStorageClassSpecifierString
argument_list|(
argument|StorageClass SC
argument_list|)
block|;
name|protected
operator|:
comment|/// \brief Placeholder type used in Init to denote an unparsed C++ default
comment|/// argument.
expr|struct
name|UnparsedDefaultArgument
block|;
comment|/// \brief Placeholder type used in Init to denote an uninstantiated C++
comment|/// default argument.
block|struct
name|UninstantiatedDefaultArgument
block|;
typedef|typedef
name|llvm
operator|::
name|PointerUnion4
operator|<
name|Stmt
operator|*
operator|,
name|EvaluatedStmt
operator|*
operator|,
name|UnparsedDefaultArgument
operator|*
operator|,
name|UninstantiatedDefaultArgument
operator|*
operator|>
name|InitType
expr_stmt|;
comment|/// \brief The initializer for this variable or, for a ParmVarDecl, the
comment|/// C++ default argument.
name|mutable
name|InitType
name|Init
decl_stmt|;
end_decl_stmt

begin_label
name|private
label|:
end_label

begin_comment
comment|// FIXME: This can be packed into the bitfields in Decl.
end_comment

begin_decl_stmt
name|unsigned
name|SClass
range|:
literal|3
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|unsigned
name|SClassAsWritten
range|:
literal|3
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|bool
name|ThreadSpecified
range|:
literal|1
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|bool
name|HasCXXDirectInit
range|:
literal|1
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// \brief Whether this variable is the exception variable in a C++ catch
end_comment

begin_comment
comment|/// or an Objective-C @catch statement.
end_comment

begin_decl_stmt
name|bool
name|ExceptionVar
range|:
literal|1
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// \brief Whether this local variable could be allocated in the return
end_comment

begin_comment
comment|/// slot of its function, enabling the named return value optimization (NRVO).
end_comment

begin_decl_stmt
name|bool
name|NRVOVariable
range|:
literal|1
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|friend
name|class
name|StmtIteratorBase
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|friend
name|class
name|ASTDeclReader
decl_stmt|;
end_decl_stmt

begin_label
name|protected
label|:
end_label

begin_macro
name|VarDecl
argument_list|(
argument|Kind DK
argument_list|,
argument|DeclContext *DC
argument_list|,
argument|SourceLocation L
argument_list|,
argument|IdentifierInfo *Id
argument_list|,
argument|QualType T
argument_list|,
argument|TypeSourceInfo *TInfo
argument_list|,
argument|StorageClass SC
argument_list|,
argument|StorageClass SCAsWritten
argument_list|)
end_macro

begin_expr_stmt
unit|:
name|DeclaratorDecl
argument_list|(
name|DK
argument_list|,
name|DC
argument_list|,
name|L
argument_list|,
name|Id
argument_list|,
name|T
argument_list|,
name|TInfo
argument_list|)
operator|,
name|Init
argument_list|()
operator|,
name|ThreadSpecified
argument_list|(
name|false
argument_list|)
operator|,
name|HasCXXDirectInit
argument_list|(
name|false
argument_list|)
operator|,
name|ExceptionVar
argument_list|(
name|false
argument_list|)
operator|,
name|NRVOVariable
argument_list|(
argument|false
argument_list|)
block|{
name|SClass
operator|=
name|SC
block|;
name|SClassAsWritten
operator|=
name|SCAsWritten
block|;   }
end_expr_stmt

begin_typedef
typedef|typedef
name|Redeclarable
operator|<
name|VarDecl
operator|>
name|redeclarable_base
expr_stmt|;
end_typedef

begin_function
name|virtual
name|VarDecl
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
end_function

begin_label
name|public
label|:
end_label

begin_typedef
typedef|typedef
name|redeclarable_base
operator|::
name|redecl_iterator
name|redecl_iterator
expr_stmt|;
end_typedef

begin_expr_stmt
name|redecl_iterator
name|redecls_begin
argument_list|()
specifier|const
block|{
return|return
name|redeclarable_base
operator|::
name|redecls_begin
argument_list|()
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|redecl_iterator
name|redecls_end
argument_list|()
specifier|const
block|{
return|return
name|redeclarable_base
operator|::
name|redecls_end
argument_list|()
return|;
block|}
end_expr_stmt

begin_function_decl
specifier|static
name|VarDecl
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
name|L
parameter_list|,
name|IdentifierInfo
modifier|*
name|Id
parameter_list|,
name|QualType
name|T
parameter_list|,
name|TypeSourceInfo
modifier|*
name|TInfo
parameter_list|,
name|StorageClass
name|S
parameter_list|,
name|StorageClass
name|SCAsWritten
parameter_list|)
function_decl|;
end_function_decl

begin_expr_stmt
name|virtual
name|SourceLocation
name|getInnerLocStart
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|virtual
name|SourceRange
name|getSourceRange
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|StorageClass
name|getStorageClass
argument_list|()
specifier|const
block|{
return|return
operator|(
name|StorageClass
operator|)
name|SClass
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|StorageClass
name|getStorageClassAsWritten
argument_list|()
specifier|const
block|{
return|return
operator|(
name|StorageClass
operator|)
name|SClassAsWritten
return|;
block|}
end_expr_stmt

begin_function_decl
name|void
name|setStorageClass
parameter_list|(
name|StorageClass
name|SC
parameter_list|)
function_decl|;
end_function_decl

begin_function
name|void
name|setStorageClassAsWritten
parameter_list|(
name|StorageClass
name|SC
parameter_list|)
block|{
name|assert
argument_list|(
name|isLegalForVariable
argument_list|(
name|SC
argument_list|)
argument_list|)
expr_stmt|;
name|SClassAsWritten
operator|=
name|SC
expr_stmt|;
block|}
end_function

begin_function
name|void
name|setThreadSpecified
parameter_list|(
name|bool
name|T
parameter_list|)
block|{
name|ThreadSpecified
operator|=
name|T
expr_stmt|;
block|}
end_function

begin_expr_stmt
name|bool
name|isThreadSpecified
argument_list|()
specifier|const
block|{
return|return
name|ThreadSpecified
return|;
block|}
end_expr_stmt

begin_comment
comment|/// hasLocalStorage - Returns true if a variable with function scope
end_comment

begin_comment
comment|///  is a non-static local variable.
end_comment

begin_expr_stmt
name|bool
name|hasLocalStorage
argument_list|()
specifier|const
block|{
if|if
condition|(
name|getStorageClass
argument_list|()
operator|==
name|SC_None
condition|)
return|return
operator|!
name|isFileVarDecl
argument_list|()
return|;
end_expr_stmt

begin_comment
comment|// Return true for:  Auto, Register.
end_comment

begin_comment
comment|// Return false for: Extern, Static, PrivateExtern.
end_comment

begin_return
return|return
name|getStorageClass
argument_list|()
operator|>=
name|SC_Auto
return|;
end_return

begin_comment
unit|}
comment|/// isStaticLocal - Returns true if a variable with function scope is a
end_comment

begin_comment
comment|/// static local variable.
end_comment

begin_macro
unit|bool
name|isStaticLocal
argument_list|()
end_macro

begin_expr_stmt
specifier|const
block|{
return|return
name|getStorageClass
argument_list|()
operator|==
name|SC_Static
operator|&&
operator|!
name|isFileVarDecl
argument_list|()
return|;
block|}
end_expr_stmt

begin_comment
comment|/// hasExternStorage - Returns true if a variable has extern or
end_comment

begin_comment
comment|/// __private_extern__ storage.
end_comment

begin_expr_stmt
name|bool
name|hasExternalStorage
argument_list|()
specifier|const
block|{
return|return
name|getStorageClass
argument_list|()
operator|==
name|SC_Extern
operator|||
name|getStorageClass
argument_list|()
operator|==
name|SC_PrivateExtern
return|;
block|}
end_expr_stmt

begin_comment
comment|/// hasGlobalStorage - Returns true for all variables that do not
end_comment

begin_comment
comment|///  have local storage.  This includs all global variables as well
end_comment

begin_comment
comment|///  as static variables declared within a function.
end_comment

begin_expr_stmt
name|bool
name|hasGlobalStorage
argument_list|()
specifier|const
block|{
return|return
operator|!
name|hasLocalStorage
argument_list|()
return|;
block|}
end_expr_stmt

begin_comment
comment|/// \brief Determines whether this variable is a variable with
end_comment

begin_comment
comment|/// external, C linkage.
end_comment

begin_expr_stmt
name|bool
name|isExternC
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// isLocalVarDecl - Returns true for local variable declarations
end_comment

begin_comment
comment|/// other than parameters.  Note that this includes static variables
end_comment

begin_comment
comment|/// inside of functions. It also includes variables inside blocks.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|///   void foo() { int x; static int y; extern int z; }
end_comment

begin_comment
comment|///
end_comment

begin_expr_stmt
name|bool
name|isLocalVarDecl
argument_list|()
specifier|const
block|{
if|if
condition|(
name|getKind
argument_list|()
operator|!=
name|Decl
operator|::
name|Var
condition|)
return|return
name|false
return|;
end_expr_stmt

begin_if
if|if
condition|(
specifier|const
name|DeclContext
modifier|*
name|DC
init|=
name|getDeclContext
argument_list|()
condition|)
return|return
name|DC
operator|->
name|getRedeclContext
argument_list|()
operator|->
name|isFunctionOrMethod
argument_list|()
return|;
end_if

begin_return
return|return
name|false
return|;
end_return

begin_comment
unit|}
comment|/// isFunctionOrMethodVarDecl - Similar to isLocalVarDecl, but
end_comment

begin_comment
comment|/// excludes variables declared in blocks.
end_comment

begin_macro
unit|bool
name|isFunctionOrMethodVarDecl
argument_list|()
end_macro

begin_expr_stmt
specifier|const
block|{
if|if
condition|(
name|getKind
argument_list|()
operator|!=
name|Decl
operator|::
name|Var
condition|)
return|return
name|false
return|;
specifier|const
name|DeclContext
operator|*
name|DC
operator|=
name|getDeclContext
argument_list|()
operator|->
name|getRedeclContext
argument_list|()
expr_stmt|;
end_expr_stmt

begin_return
return|return
name|DC
operator|->
name|isFunctionOrMethod
argument_list|()
operator|&&
name|DC
operator|->
name|getDeclKind
argument_list|()
operator|!=
name|Decl
operator|::
name|Block
return|;
end_return

begin_comment
unit|}
comment|/// \brief Determines whether this is a static data member.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This will only be true in C++, and applies to, e.g., the
end_comment

begin_comment
comment|/// variable 'x' in:
end_comment

begin_comment
comment|/// \code
end_comment

begin_comment
comment|/// struct S {
end_comment

begin_comment
comment|///   static int x;
end_comment

begin_comment
comment|/// };
end_comment

begin_comment
comment|/// \endcode
end_comment

begin_macro
unit|bool
name|isStaticDataMember
argument_list|()
end_macro

begin_expr_stmt
specifier|const
block|{
comment|// If it wasn't static, it would be a FieldDecl.
return|return
name|getKind
argument_list|()
operator|!=
name|Decl
operator|::
name|ParmVar
operator|&&
name|getDeclContext
argument_list|()
operator|->
name|isRecord
argument_list|()
return|;
block|}
end_expr_stmt

begin_function_decl
name|virtual
name|VarDecl
modifier|*
name|getCanonicalDecl
parameter_list|()
function_decl|;
end_function_decl

begin_expr_stmt
specifier|const
name|VarDecl
operator|*
name|getCanonicalDecl
argument_list|()
specifier|const
block|{
return|return
name|const_cast
operator|<
name|VarDecl
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

begin_enum
enum|enum
name|DefinitionKind
block|{
name|DeclarationOnly
block|,
comment|///< This declaration is only a declaration.
name|TentativeDefinition
block|,
comment|///< This declaration is a tentative definition.
name|Definition
comment|///< This declaration is definitely a definition.
block|}
enum|;
end_enum

begin_comment
comment|/// \brief Check whether this declaration is a definition. If this could be
end_comment

begin_comment
comment|/// a tentative definition (in C), don't check whether there's an overriding
end_comment

begin_comment
comment|/// definition.
end_comment

begin_expr_stmt
name|DefinitionKind
name|isThisDeclarationADefinition
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// \brief Check whether this variable is defined in this
end_comment

begin_comment
comment|/// translation unit.
end_comment

begin_expr_stmt
name|DefinitionKind
name|hasDefinition
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// \brief Get the tentative definition that acts as the real definition in
end_comment

begin_comment
comment|/// a TU. Returns null if there is a proper definition available.
end_comment

begin_function_decl
name|VarDecl
modifier|*
name|getActingDefinition
parameter_list|()
function_decl|;
end_function_decl

begin_expr_stmt
specifier|const
name|VarDecl
operator|*
name|getActingDefinition
argument_list|()
specifier|const
block|{
return|return
name|const_cast
operator|<
name|VarDecl
operator|*
operator|>
operator|(
name|this
operator|)
operator|->
name|getActingDefinition
argument_list|()
return|;
block|}
end_expr_stmt

begin_comment
comment|/// \brief Determine whether this is a tentative definition of a
end_comment

begin_comment
comment|/// variable in C.
end_comment

begin_expr_stmt
name|bool
name|isTentativeDefinitionNow
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// \brief Get the real (not just tentative) definition for this declaration.
end_comment

begin_function_decl
name|VarDecl
modifier|*
name|getDefinition
parameter_list|()
function_decl|;
end_function_decl

begin_expr_stmt
specifier|const
name|VarDecl
operator|*
name|getDefinition
argument_list|()
specifier|const
block|{
return|return
name|const_cast
operator|<
name|VarDecl
operator|*
operator|>
operator|(
name|this
operator|)
operator|->
name|getDefinition
argument_list|()
return|;
block|}
end_expr_stmt

begin_comment
comment|/// \brief Determine whether this is or was instantiated from an out-of-line
end_comment

begin_comment
comment|/// definition of a static data member.
end_comment

begin_expr_stmt
name|virtual
name|bool
name|isOutOfLine
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// \brief If this is a static data member, find its out-of-line definition.
end_comment

begin_function_decl
name|VarDecl
modifier|*
name|getOutOfLineDefinition
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/// isFileVarDecl - Returns true for file scoped variable declaration.
end_comment

begin_expr_stmt
name|bool
name|isFileVarDecl
argument_list|()
specifier|const
block|{
if|if
condition|(
name|getKind
argument_list|()
operator|!=
name|Decl
operator|::
name|Var
condition|)
return|return
name|false
return|;
end_expr_stmt

begin_if
if|if
condition|(
name|getDeclContext
argument_list|()
operator|->
name|getRedeclContext
argument_list|()
operator|->
name|isFileContext
argument_list|()
condition|)
return|return
name|true
return|;
end_if

begin_if
if|if
condition|(
name|isStaticDataMember
argument_list|()
condition|)
return|return
name|true
return|;
end_if

begin_return
return|return
name|false
return|;
end_return

begin_comment
unit|}
comment|/// getAnyInitializer - Get the initializer for this variable, no matter which
end_comment

begin_comment
comment|/// declaration it is attached to.
end_comment

begin_expr_stmt
unit|const
name|Expr
operator|*
name|getAnyInitializer
argument_list|()
specifier|const
block|{
specifier|const
name|VarDecl
operator|*
name|D
block|;
return|return
name|getAnyInitializer
argument_list|(
name|D
argument_list|)
return|;
block|}
end_expr_stmt

begin_comment
comment|/// getAnyInitializer - Get the initializer for this variable, no matter which
end_comment

begin_comment
comment|/// declaration it is attached to. Also get that declaration.
end_comment

begin_decl_stmt
specifier|const
name|Expr
modifier|*
name|getAnyInitializer
argument_list|(
specifier|const
name|VarDecl
operator|*
operator|&
name|D
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|bool
name|hasInit
argument_list|()
specifier|const
block|{
return|return
operator|!
name|Init
operator|.
name|isNull
argument_list|()
operator|&&
operator|(
name|Init
operator|.
name|is
operator|<
name|Stmt
operator|*
operator|>
operator|(
operator|)
operator|||
name|Init
operator|.
name|is
operator|<
name|EvaluatedStmt
operator|*
operator|>
operator|(
operator|)
operator|)
return|;
block|}
end_expr_stmt

begin_expr_stmt
specifier|const
name|Expr
operator|*
name|getInit
argument_list|()
specifier|const
block|{
if|if
condition|(
name|Init
operator|.
name|isNull
argument_list|()
condition|)
return|return
literal|0
return|;
specifier|const
name|Stmt
operator|*
name|S
operator|=
name|Init
operator|.
name|dyn_cast
operator|<
name|Stmt
operator|*
operator|>
operator|(
operator|)
expr_stmt|;
end_expr_stmt

begin_if
if|if
condition|(
operator|!
name|S
condition|)
block|{
if|if
condition|(
name|EvaluatedStmt
modifier|*
name|ES
init|=
name|Init
operator|.
name|dyn_cast
operator|<
name|EvaluatedStmt
operator|*
operator|>
operator|(
operator|)
condition|)
name|S
operator|=
name|ES
operator|->
name|Value
expr_stmt|;
block|}
end_if

begin_return
return|return
operator|(
specifier|const
name|Expr
operator|*
operator|)
name|S
return|;
end_return

begin_expr_stmt
unit|}   Expr
operator|*
name|getInit
argument_list|()
block|{
if|if
condition|(
name|Init
operator|.
name|isNull
argument_list|()
condition|)
return|return
literal|0
return|;
name|Stmt
operator|*
name|S
operator|=
name|Init
operator|.
name|dyn_cast
operator|<
name|Stmt
operator|*
operator|>
operator|(
operator|)
expr_stmt|;
end_expr_stmt

begin_if
if|if
condition|(
operator|!
name|S
condition|)
block|{
if|if
condition|(
name|EvaluatedStmt
modifier|*
name|ES
init|=
name|Init
operator|.
name|dyn_cast
operator|<
name|EvaluatedStmt
operator|*
operator|>
operator|(
operator|)
condition|)
name|S
operator|=
name|ES
operator|->
name|Value
expr_stmt|;
block|}
end_if

begin_return
return|return
operator|(
name|Expr
operator|*
operator|)
name|S
return|;
end_return

begin_comment
unit|}
comment|/// \brief Retrieve the address of the initializer expression.
end_comment

begin_expr_stmt
unit|Stmt
operator|*
operator|*
name|getInitAddress
argument_list|()
block|{
if|if
condition|(
name|EvaluatedStmt
modifier|*
name|ES
init|=
name|Init
operator|.
name|dyn_cast
operator|<
name|EvaluatedStmt
operator|*
operator|>
operator|(
operator|)
condition|)
return|return
operator|&
name|ES
operator|->
name|Value
return|;
comment|// This union hack tip-toes around strict-aliasing rules.
block|union
block|{
name|InitType
operator|*
name|InitPtr
block|;
name|Stmt
operator|*
operator|*
name|StmtPtr
block|;     }
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|InitPtr
operator|=
operator|&
name|Init
expr_stmt|;
end_expr_stmt

begin_return
return|return
name|StmtPtr
return|;
end_return

begin_expr_stmt
unit|}    void
name|setInit
argument_list|(
name|Expr
operator|*
name|I
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|EvaluatedStmt
operator|*
name|EnsureEvaluatedStmt
argument_list|()
specifier|const
block|{
name|EvaluatedStmt
operator|*
name|Eval
operator|=
name|Init
operator|.
name|dyn_cast
operator|<
name|EvaluatedStmt
operator|*
operator|>
operator|(
operator|)
block|;
if|if
condition|(
operator|!
name|Eval
condition|)
block|{
name|Stmt
modifier|*
name|S
init|=
name|Init
operator|.
name|get
operator|<
name|Stmt
operator|*
operator|>
operator|(
operator|)
decl_stmt|;
name|Eval
operator|=
name|new
argument_list|(
argument|getASTContext()
argument_list|)
name|EvaluatedStmt
expr_stmt|;
name|Eval
operator|->
name|Value
operator|=
name|S
expr_stmt|;
name|Init
operator|=
name|Eval
expr_stmt|;
block|}
end_expr_stmt

begin_return
return|return
name|Eval
return|;
end_return

begin_comment
unit|}
comment|/// \brief Check whether we are in the process of checking whether the
end_comment

begin_comment
comment|/// initializer can be evaluated.
end_comment

begin_macro
unit|bool
name|isEvaluatingValue
argument_list|()
end_macro

begin_expr_stmt
specifier|const
block|{
if|if
condition|(
name|EvaluatedStmt
modifier|*
name|Eval
init|=
name|Init
operator|.
name|dyn_cast
operator|<
name|EvaluatedStmt
operator|*
operator|>
operator|(
operator|)
condition|)
return|return
name|Eval
operator|->
name|IsEvaluating
return|;
end_expr_stmt

begin_return
return|return
name|false
return|;
end_return

begin_comment
unit|}
comment|/// \brief Note that we now are checking whether the initializer can be
end_comment

begin_comment
comment|/// evaluated.
end_comment

begin_macro
unit|void
name|setEvaluatingValue
argument_list|()
end_macro

begin_expr_stmt
specifier|const
block|{
name|EvaluatedStmt
operator|*
name|Eval
operator|=
name|EnsureEvaluatedStmt
argument_list|()
block|;
name|Eval
operator|->
name|IsEvaluating
operator|=
name|true
block|;   }
comment|/// \brief Note that constant evaluation has computed the given
comment|/// value for this variable's initializer.
name|void
name|setEvaluatedValue
argument_list|(
argument|const APValue&Value
argument_list|)
specifier|const
block|{
name|EvaluatedStmt
operator|*
name|Eval
operator|=
name|EnsureEvaluatedStmt
argument_list|()
block|;
name|Eval
operator|->
name|IsEvaluating
operator|=
name|false
block|;
name|Eval
operator|->
name|WasEvaluated
operator|=
name|true
block|;
name|Eval
operator|->
name|Evaluated
operator|=
name|Value
block|;   }
comment|/// \brief Return the already-evaluated value of this variable's
comment|/// initializer, or NULL if the value is not yet known. Returns pointer
comment|/// to untyped APValue if the value could not be evaluated.
name|APValue
operator|*
name|getEvaluatedValue
argument_list|()
specifier|const
block|{
if|if
condition|(
name|EvaluatedStmt
modifier|*
name|Eval
init|=
name|Init
operator|.
name|dyn_cast
operator|<
name|EvaluatedStmt
operator|*
operator|>
operator|(
operator|)
condition|)
if|if
condition|(
name|Eval
operator|->
name|WasEvaluated
condition|)
return|return
operator|&
name|Eval
operator|->
name|Evaluated
return|;
end_expr_stmt

begin_return
return|return
literal|0
return|;
end_return

begin_comment
unit|}
comment|/// \brief Determines whether it is already known whether the
end_comment

begin_comment
comment|/// initializer is an integral constant expression or not.
end_comment

begin_macro
unit|bool
name|isInitKnownICE
argument_list|()
end_macro

begin_expr_stmt
specifier|const
block|{
if|if
condition|(
name|EvaluatedStmt
modifier|*
name|Eval
init|=
name|Init
operator|.
name|dyn_cast
operator|<
name|EvaluatedStmt
operator|*
operator|>
operator|(
operator|)
condition|)
return|return
name|Eval
operator|->
name|CheckedICE
return|;
end_expr_stmt

begin_return
return|return
name|false
return|;
end_return

begin_comment
unit|}
comment|/// \brief Determines whether the initializer is an integral
end_comment

begin_comment
comment|/// constant expression.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \pre isInitKnownICE()
end_comment

begin_macro
unit|bool
name|isInitICE
argument_list|()
end_macro

begin_expr_stmt
specifier|const
block|{
name|assert
argument_list|(
name|isInitKnownICE
argument_list|()
operator|&&
literal|"Check whether we already know that the initializer is an ICE"
argument_list|)
block|;
return|return
name|Init
operator|.
name|get
operator|<
name|EvaluatedStmt
operator|*
operator|>
operator|(
operator|)
operator|->
name|IsICE
return|;
block|}
end_expr_stmt

begin_comment
comment|/// \brief Check whether we are in the process of checking the initializer
end_comment

begin_comment
comment|/// is an integral constant expression.
end_comment

begin_expr_stmt
name|bool
name|isCheckingICE
argument_list|()
specifier|const
block|{
if|if
condition|(
name|EvaluatedStmt
modifier|*
name|Eval
init|=
name|Init
operator|.
name|dyn_cast
operator|<
name|EvaluatedStmt
operator|*
operator|>
operator|(
operator|)
condition|)
return|return
name|Eval
operator|->
name|CheckingICE
return|;
end_expr_stmt

begin_return
return|return
name|false
return|;
end_return

begin_comment
unit|}
comment|/// \brief Note that we now are checking whether the initializer is an
end_comment

begin_comment
comment|/// integral constant expression.
end_comment

begin_macro
unit|void
name|setCheckingICE
argument_list|()
end_macro

begin_expr_stmt
specifier|const
block|{
name|EvaluatedStmt
operator|*
name|Eval
operator|=
name|EnsureEvaluatedStmt
argument_list|()
block|;
name|Eval
operator|->
name|CheckingICE
operator|=
name|true
block|;   }
comment|/// \brief Note that we now know whether the initializer is an
comment|/// integral constant expression.
name|void
name|setInitKnownICE
argument_list|(
argument|bool IsICE
argument_list|)
specifier|const
block|{
name|EvaluatedStmt
operator|*
name|Eval
operator|=
name|EnsureEvaluatedStmt
argument_list|()
block|;
name|Eval
operator|->
name|CheckingICE
operator|=
name|false
block|;
name|Eval
operator|->
name|CheckedICE
operator|=
name|true
block|;
name|Eval
operator|->
name|IsICE
operator|=
name|IsICE
block|;   }
name|void
name|setCXXDirectInitializer
argument_list|(
argument|bool T
argument_list|)
block|{
name|HasCXXDirectInit
operator|=
name|T
block|; }
comment|/// hasCXXDirectInitializer - If true, the initializer was a direct
comment|/// initializer, e.g: "int x(1);". The Init expression will be the expression
comment|/// inside the parens or a "ClassType(a,b,c)" class constructor expression for
comment|/// class types. Clients can distinguish between "int x(1);" and "int x=1;"
comment|/// by checking hasCXXDirectInitializer.
comment|///
name|bool
name|hasCXXDirectInitializer
argument_list|()
specifier|const
block|{
return|return
name|HasCXXDirectInit
return|;
block|}
end_expr_stmt

begin_comment
comment|/// \brief Determine whether this variable is the exception variable in a
end_comment

begin_comment
comment|/// C++ catch statememt or an Objective-C @catch statement.
end_comment

begin_expr_stmt
name|bool
name|isExceptionVariable
argument_list|()
specifier|const
block|{
return|return
name|ExceptionVar
return|;
block|}
end_expr_stmt

begin_function
name|void
name|setExceptionVariable
parameter_list|(
name|bool
name|EV
parameter_list|)
block|{
name|ExceptionVar
operator|=
name|EV
expr_stmt|;
block|}
end_function

begin_comment
comment|/// \brief Determine whether this local variable can be used with the named
end_comment

begin_comment
comment|/// return value optimization (NRVO).
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// The named return value optimization (NRVO) works by marking certain
end_comment

begin_comment
comment|/// non-volatile local variables of class type as NRVO objects. These
end_comment

begin_comment
comment|/// locals can be allocated within the return slot of their containing
end_comment

begin_comment
comment|/// function, in which case there is no need to copy the object to the
end_comment

begin_comment
comment|/// return slot when returning from the function. Within the function body,
end_comment

begin_comment
comment|/// each return that returns the NRVO object will have this variable as its
end_comment

begin_comment
comment|/// NRVO candidate.
end_comment

begin_expr_stmt
name|bool
name|isNRVOVariable
argument_list|()
specifier|const
block|{
return|return
name|NRVOVariable
return|;
block|}
end_expr_stmt

begin_function
name|void
name|setNRVOVariable
parameter_list|(
name|bool
name|NRVO
parameter_list|)
block|{
name|NRVOVariable
operator|=
name|NRVO
expr_stmt|;
block|}
end_function

begin_comment
comment|/// \brief If this variable is an instantiated static data member of a
end_comment

begin_comment
comment|/// class template specialization, returns the templated static data member
end_comment

begin_comment
comment|/// from which it was instantiated.
end_comment

begin_expr_stmt
name|VarDecl
operator|*
name|getInstantiatedFromStaticDataMember
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// \brief If this variable is a static data member, determine what kind of
end_comment

begin_comment
comment|/// template specialization or instantiation this is.
end_comment

begin_expr_stmt
name|TemplateSpecializationKind
name|getTemplateSpecializationKind
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// \brief If this variable is an instantiation of a static data member of a
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
comment|/// \brief For a static data member that was instantiated from a static
end_comment

begin_comment
comment|/// data member of a class template, set the template specialiation kind.
end_comment

begin_function_decl
name|void
name|setTemplateSpecializationKind
parameter_list|(
name|TemplateSpecializationKind
name|TSK
parameter_list|,
name|SourceLocation
name|PointOfInstantiation
init|=
name|SourceLocation
argument_list|()
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
name|VarDecl
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
name|firstVar
operator|&&
name|K
operator|<=
name|lastVar
return|;
block|}
end_function

begin_decl_stmt
unit|};
name|class
name|ImplicitParamDecl
range|:
name|public
name|VarDecl
block|{
name|public
operator|:
specifier|static
name|ImplicitParamDecl
operator|*
name|Create
argument_list|(
argument|ASTContext&C
argument_list|,
argument|DeclContext *DC
argument_list|,
argument|SourceLocation L
argument_list|,
argument|IdentifierInfo *Id
argument_list|,
argument|QualType T
argument_list|)
block|;
name|ImplicitParamDecl
argument_list|(
argument|DeclContext *DC
argument_list|,
argument|SourceLocation loc
argument_list|,
argument|IdentifierInfo *name
argument_list|,
argument|QualType type
argument_list|)
operator|:
name|VarDecl
argument_list|(
argument|ImplicitParam
argument_list|,
argument|DC
argument_list|,
argument|loc
argument_list|,
argument|name
argument_list|,
argument|type
argument_list|,
comment|/*tinfo*/
literal|0
argument_list|,
argument|SC_None
argument_list|,
argument|SC_None
argument_list|)
block|{
name|setImplicit
argument_list|()
block|;   }
comment|// Implement isa/cast/dyncast/etc.
specifier|static
name|bool
name|classof
argument_list|(
argument|const ImplicitParamDecl *D
argument_list|)
block|{
return|return
name|true
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
name|ImplicitParam
return|;
block|}
expr|}
block|;
comment|/// ParmVarDecl - Represent a parameter to a function.
name|class
name|ParmVarDecl
operator|:
name|public
name|VarDecl
block|{
comment|// NOTE: VC++ treats enums as signed, avoid using the ObjCDeclQualifier enum
comment|/// FIXME: Also can be paced into the bitfields in Decl.
comment|/// in, inout, etc.
name|unsigned
name|objcDeclQualifier
operator|:
literal|6
block|;
name|bool
name|HasInheritedDefaultArg
operator|:
literal|1
block|;
name|protected
operator|:
name|ParmVarDecl
argument_list|(
argument|Kind DK
argument_list|,
argument|DeclContext *DC
argument_list|,
argument|SourceLocation L
argument_list|,
argument|IdentifierInfo *Id
argument_list|,
argument|QualType T
argument_list|,
argument|TypeSourceInfo *TInfo
argument_list|,
argument|StorageClass S
argument_list|,
argument|StorageClass SCAsWritten
argument_list|,
argument|Expr *DefArg
argument_list|)
operator|:
name|VarDecl
argument_list|(
name|DK
argument_list|,
name|DC
argument_list|,
name|L
argument_list|,
name|Id
argument_list|,
name|T
argument_list|,
name|TInfo
argument_list|,
name|S
argument_list|,
name|SCAsWritten
argument_list|)
block|,
name|objcDeclQualifier
argument_list|(
name|OBJC_TQ_None
argument_list|)
block|,
name|HasInheritedDefaultArg
argument_list|(
argument|false
argument_list|)
block|{
name|setDefaultArg
argument_list|(
name|DefArg
argument_list|)
block|;   }
name|public
operator|:
specifier|static
name|ParmVarDecl
operator|*
name|Create
argument_list|(
argument|ASTContext&C
argument_list|,
argument|DeclContext *DC
argument_list|,
argument|SourceLocation L
argument_list|,
argument|IdentifierInfo *Id
argument_list|,
argument|QualType T
argument_list|,
argument|TypeSourceInfo *TInfo
argument_list|,
argument|StorageClass S
argument_list|,
argument|StorageClass SCAsWritten
argument_list|,
argument|Expr *DefArg
argument_list|)
block|;
name|ObjCDeclQualifier
name|getObjCDeclQualifier
argument_list|()
specifier|const
block|{
return|return
name|ObjCDeclQualifier
argument_list|(
name|objcDeclQualifier
argument_list|)
return|;
block|}
name|void
name|setObjCDeclQualifier
argument_list|(
argument|ObjCDeclQualifier QTVal
argument_list|)
block|{
name|objcDeclQualifier
operator|=
name|QTVal
block|;   }
name|Expr
operator|*
name|getDefaultArg
argument_list|()
block|;
specifier|const
name|Expr
operator|*
name|getDefaultArg
argument_list|()
specifier|const
block|{
return|return
name|const_cast
operator|<
name|ParmVarDecl
operator|*
operator|>
operator|(
name|this
operator|)
operator|->
name|getDefaultArg
argument_list|()
return|;
block|}
name|void
name|setDefaultArg
argument_list|(
argument|Expr *defarg
argument_list|)
block|{
name|Init
operator|=
name|reinterpret_cast
operator|<
name|Stmt
operator|*
operator|>
operator|(
name|defarg
operator|)
block|;   }
name|unsigned
name|getNumDefaultArgTemporaries
argument_list|()
specifier|const
block|;
name|CXXTemporary
operator|*
name|getDefaultArgTemporary
argument_list|(
argument|unsigned i
argument_list|)
block|;
specifier|const
name|CXXTemporary
operator|*
name|getDefaultArgTemporary
argument_list|(
argument|unsigned i
argument_list|)
specifier|const
block|{
return|return
name|const_cast
operator|<
name|ParmVarDecl
operator|*
operator|>
operator|(
name|this
operator|)
operator|->
name|getDefaultArgTemporary
argument_list|(
name|i
argument_list|)
return|;
block|}
comment|/// \brief Retrieve the source range that covers the entire default
comment|/// argument.
name|SourceRange
name|getDefaultArgRange
argument_list|()
specifier|const
block|;
name|void
name|setUninstantiatedDefaultArg
argument_list|(
argument|Expr *arg
argument_list|)
block|{
name|Init
operator|=
name|reinterpret_cast
operator|<
name|UninstantiatedDefaultArgument
operator|*
operator|>
operator|(
name|arg
operator|)
block|;   }
name|Expr
operator|*
name|getUninstantiatedDefaultArg
argument_list|()
block|{
return|return
operator|(
name|Expr
operator|*
operator|)
name|Init
operator|.
name|get
operator|<
name|UninstantiatedDefaultArgument
operator|*
operator|>
operator|(
operator|)
return|;
block|}
specifier|const
name|Expr
operator|*
name|getUninstantiatedDefaultArg
argument_list|()
specifier|const
block|{
return|return
operator|(
specifier|const
name|Expr
operator|*
operator|)
name|Init
operator|.
name|get
operator|<
name|UninstantiatedDefaultArgument
operator|*
operator|>
operator|(
operator|)
return|;
block|}
comment|/// hasDefaultArg - Determines whether this parameter has a default argument,
comment|/// either parsed or not.
name|bool
name|hasDefaultArg
argument_list|()
specifier|const
block|{
return|return
name|getInit
argument_list|()
operator|||
name|hasUnparsedDefaultArg
argument_list|()
operator|||
name|hasUninstantiatedDefaultArg
argument_list|()
return|;
block|}
comment|/// hasUnparsedDefaultArg - Determines whether this parameter has a
comment|/// default argument that has not yet been parsed. This will occur
comment|/// during the processing of a C++ class whose member functions have
comment|/// default arguments, e.g.,
comment|/// @code
comment|///   class X {
comment|///   public:
comment|///     void f(int x = 17); // x has an unparsed default argument now
comment|///   }; // x has a regular default argument now
comment|/// @endcode
name|bool
name|hasUnparsedDefaultArg
argument_list|()
specifier|const
block|{
return|return
name|Init
operator|.
name|is
operator|<
name|UnparsedDefaultArgument
operator|*
operator|>
operator|(
operator|)
return|;
block|}
name|bool
name|hasUninstantiatedDefaultArg
argument_list|()
specifier|const
block|{
return|return
name|Init
operator|.
name|is
operator|<
name|UninstantiatedDefaultArgument
operator|*
operator|>
operator|(
operator|)
return|;
block|}
comment|/// setUnparsedDefaultArg - Specify that this parameter has an
comment|/// unparsed default argument. The argument will be replaced with a
comment|/// real default argument via setDefaultArg when the class
comment|/// definition enclosing the function declaration that owns this
comment|/// default argument is completed.
name|void
name|setUnparsedDefaultArg
argument_list|()
block|{
name|Init
operator|=
operator|(
name|UnparsedDefaultArgument
operator|*
operator|)
literal|0
block|;   }
name|bool
name|hasInheritedDefaultArg
argument_list|()
specifier|const
block|{
return|return
name|HasInheritedDefaultArg
return|;
block|}
name|void
name|setHasInheritedDefaultArg
argument_list|(
argument|bool I = true
argument_list|)
block|{
name|HasInheritedDefaultArg
operator|=
name|I
block|;   }
name|QualType
name|getOriginalType
argument_list|()
specifier|const
block|{
if|if
condition|(
name|getTypeSourceInfo
argument_list|()
condition|)
return|return
name|getTypeSourceInfo
argument_list|()
operator|->
name|getType
argument_list|()
return|;
return|return
name|getType
argument_list|()
return|;
block|}
comment|/// \brief Determine whether this parameter is actually a function
comment|/// parameter pack.
name|bool
name|isParameterPack
argument_list|()
specifier|const
block|;
comment|/// setOwningFunction - Sets the function declaration that owns this
comment|/// ParmVarDecl. Since ParmVarDecls are often created before the
comment|/// FunctionDecls that own them, this routine is required to update
comment|/// the DeclContext appropriately.
name|void
name|setOwningFunction
argument_list|(
argument|DeclContext *FD
argument_list|)
block|{
name|setDeclContext
argument_list|(
name|FD
argument_list|)
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
argument|const ParmVarDecl *D
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
name|ParmVar
return|;
block|}
expr|}
block|;
comment|/// FunctionDecl - An instance of this class is created to represent a
comment|/// function declaration or definition.
comment|///
comment|/// Since a given function can be declared several times in a program,
comment|/// there may be several FunctionDecls that correspond to that
comment|/// function. Only one of those FunctionDecls will be found when
comment|/// traversing the list of declarations in the context of the
comment|/// FunctionDecl (e.g., the translation unit); this FunctionDecl
comment|/// contains all of the information known about the function. Other,
comment|/// previous declarations of the function are available via the
comment|/// getPreviousDeclaration() chain.
name|class
name|FunctionDecl
operator|:
name|public
name|DeclaratorDecl
block|,
name|public
name|DeclContext
block|,
name|public
name|Redeclarable
operator|<
name|FunctionDecl
operator|>
block|{
name|public
operator|:
typedef|typedef
name|clang
operator|::
name|StorageClass
name|StorageClass
expr_stmt|;
comment|/// \brief The kind of templated function a FunctionDecl can be.
block|enum
name|TemplatedKind
block|{
name|TK_NonTemplate
block|,
name|TK_FunctionTemplate
block|,
name|TK_MemberSpecialization
block|,
name|TK_FunctionTemplateSpecialization
block|,
name|TK_DependentFunctionTemplateSpecialization
block|}
block|;
name|private
operator|:
comment|/// ParamInfo - new[]'d array of pointers to VarDecls for the formal
comment|/// parameters of this function.  This is null if a prototype or if there are
comment|/// no formals.
name|ParmVarDecl
operator|*
operator|*
name|ParamInfo
block|;
name|LazyDeclStmtPtr
name|Body
block|;
comment|// FIXME: This can be packed into the bitfields in Decl.
comment|// NOTE: VC++ treats enums as signed, avoid using the StorageClass enum
name|unsigned
name|SClass
operator|:
literal|2
block|;
name|unsigned
name|SClassAsWritten
operator|:
literal|2
block|;
name|bool
name|IsInline
operator|:
literal|1
block|;
name|bool
name|IsInlineSpecified
operator|:
literal|1
block|;
name|bool
name|IsVirtualAsWritten
operator|:
literal|1
block|;
name|bool
name|IsPure
operator|:
literal|1
block|;
name|bool
name|HasInheritedPrototype
operator|:
literal|1
block|;
name|bool
name|HasWrittenPrototype
operator|:
literal|1
block|;
name|bool
name|IsDeleted
operator|:
literal|1
block|;
name|bool
name|IsTrivial
operator|:
literal|1
block|;
comment|// sunk from CXXMethodDecl
name|bool
name|HasImplicitReturnZero
operator|:
literal|1
block|;
comment|/// \brief End part of this FunctionDecl's source range.
comment|///
comment|/// We could compute the full range in getSourceRange(). However, when we're
comment|/// dealing with a function definition deserialized from a PCH/AST file,
comment|/// we can only compute the full range once the function body has been
comment|/// de-serialized, so it's far better to have the (sometimes-redundant)
comment|/// EndRangeLoc.
name|SourceLocation
name|EndRangeLoc
block|;
comment|/// \brief The template or declaration that this declaration
comment|/// describes or was instantiated from, respectively.
comment|///
comment|/// For non-templates, this value will be NULL. For function
comment|/// declarations that describe a function template, this will be a
comment|/// pointer to a FunctionTemplateDecl. For member functions
comment|/// of class template specializations, this will be a MemberSpecializationInfo
comment|/// pointer containing information about the specialization.
comment|/// For function template specializations, this will be a
comment|/// FunctionTemplateSpecializationInfo, which contains information about
comment|/// the template being specialized and the template arguments involved in
comment|/// that specialization.
name|llvm
operator|::
name|PointerUnion4
operator|<
name|FunctionTemplateDecl
operator|*
block|,
name|MemberSpecializationInfo
operator|*
block|,
name|FunctionTemplateSpecializationInfo
operator|*
block|,
name|DependentFunctionTemplateSpecializationInfo
operator|*
operator|>
name|TemplateOrSpecialization
block|;
comment|/// DNLoc - Provides source/type location info for the
comment|/// declaration name embedded in the DeclaratorDecl base class.
name|DeclarationNameLoc
name|DNLoc
block|;
comment|/// \brief Specify that this function declaration is actually a function
comment|/// template specialization.
comment|///
comment|/// \param C the ASTContext.
comment|///
comment|/// \param Template the function template that this function template
comment|/// specialization specializes.
comment|///
comment|/// \param TemplateArgs the template arguments that produced this
comment|/// function template specialization from the template.
comment|///
comment|/// \param InsertPos If non-NULL, the position in the function template
comment|/// specialization set where the function template specialization data will
comment|/// be inserted.
comment|///
comment|/// \param TSK the kind of template specialization this is.
comment|///
comment|/// \param TemplateArgsAsWritten location info of template arguments.
comment|///
comment|/// \param PointOfInstantiation point at which the function template
comment|/// specialization was first instantiated.
name|void
name|setFunctionTemplateSpecialization
argument_list|(
argument|ASTContext&C
argument_list|,
argument|FunctionTemplateDecl *Template
argument_list|,
argument|const TemplateArgumentList *TemplateArgs
argument_list|,
argument|void *InsertPos
argument_list|,
argument|TemplateSpecializationKind TSK
argument_list|,
argument|const TemplateArgumentListInfo *TemplateArgsAsWritten
argument_list|,
argument|SourceLocation PointOfInstantiation
argument_list|)
block|;
comment|/// \brief Specify that this record is an instantiation of the
comment|/// member function FD.
name|void
name|setInstantiationOfMemberFunction
argument_list|(
argument|ASTContext&C
argument_list|,
argument|FunctionDecl *FD
argument_list|,
argument|TemplateSpecializationKind TSK
argument_list|)
block|;
name|void
name|setParams
argument_list|(
argument|ASTContext&C
argument_list|,
argument|ParmVarDecl **NewParamInfo
argument_list|,
argument|unsigned NumParams
argument_list|)
block|;
name|protected
operator|:
name|FunctionDecl
argument_list|(
argument|Kind DK
argument_list|,
argument|DeclContext *DC
argument_list|,
argument|const DeclarationNameInfo&NameInfo
argument_list|,
argument|QualType T
argument_list|,
argument|TypeSourceInfo *TInfo
argument_list|,
argument|StorageClass S
argument_list|,
argument|StorageClass SCAsWritten
argument_list|,
argument|bool isInlineSpecified
argument_list|)
operator|:
name|DeclaratorDecl
argument_list|(
name|DK
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
name|T
argument_list|,
name|TInfo
argument_list|)
block|,
name|DeclContext
argument_list|(
name|DK
argument_list|)
block|,
name|ParamInfo
argument_list|(
literal|0
argument_list|)
block|,
name|Body
argument_list|()
block|,
name|SClass
argument_list|(
name|S
argument_list|)
block|,
name|SClassAsWritten
argument_list|(
name|SCAsWritten
argument_list|)
block|,
name|IsInline
argument_list|(
name|isInlineSpecified
argument_list|)
block|,
name|IsInlineSpecified
argument_list|(
name|isInlineSpecified
argument_list|)
block|,
name|IsVirtualAsWritten
argument_list|(
name|false
argument_list|)
block|,
name|IsPure
argument_list|(
name|false
argument_list|)
block|,
name|HasInheritedPrototype
argument_list|(
name|false
argument_list|)
block|,
name|HasWrittenPrototype
argument_list|(
name|true
argument_list|)
block|,
name|IsDeleted
argument_list|(
name|false
argument_list|)
block|,
name|IsTrivial
argument_list|(
name|false
argument_list|)
block|,
name|HasImplicitReturnZero
argument_list|(
name|false
argument_list|)
block|,
name|EndRangeLoc
argument_list|(
name|NameInfo
operator|.
name|getEndLoc
argument_list|()
argument_list|)
block|,
name|TemplateOrSpecialization
argument_list|()
block|,
name|DNLoc
argument_list|(
argument|NameInfo.getInfo()
argument_list|)
block|{}
typedef|typedef
name|Redeclarable
operator|<
name|FunctionDecl
operator|>
name|redeclarable_base
expr_stmt|;
name|virtual
name|FunctionDecl
operator|*
name|getNextRedeclaration
argument_list|()
block|{
return|return
name|RedeclLink
operator|.
name|getNext
argument_list|()
return|;
block|}
name|public
operator|:
end_decl_stmt

begin_typedef
typedef|typedef
name|redeclarable_base
operator|::
name|redecl_iterator
name|redecl_iterator
expr_stmt|;
end_typedef

begin_expr_stmt
name|redecl_iterator
name|redecls_begin
argument_list|()
specifier|const
block|{
return|return
name|redeclarable_base
operator|::
name|redecls_begin
argument_list|()
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|redecl_iterator
name|redecls_end
argument_list|()
specifier|const
block|{
return|return
name|redeclarable_base
operator|::
name|redecls_end
argument_list|()
return|;
block|}
end_expr_stmt

begin_function
specifier|static
name|FunctionDecl
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
name|L
parameter_list|,
name|DeclarationName
name|N
parameter_list|,
name|QualType
name|T
parameter_list|,
name|TypeSourceInfo
modifier|*
name|TInfo
parameter_list|,
name|StorageClass
name|S
init|=
name|SC_None
parameter_list|,
name|StorageClass
name|SCAsWritten
init|=
name|SC_None
parameter_list|,
name|bool
name|isInlineSpecified
init|=
name|false
parameter_list|,
name|bool
name|hasWrittenPrototype
init|=
name|true
parameter_list|)
block|{
name|DeclarationNameInfo
name|NameInfo
argument_list|(
name|N
argument_list|,
name|L
argument_list|)
decl_stmt|;
return|return
name|FunctionDecl
operator|::
name|Create
argument_list|(
name|C
argument_list|,
name|DC
argument_list|,
name|NameInfo
argument_list|,
name|T
argument_list|,
name|TInfo
argument_list|,
name|S
argument_list|,
name|SCAsWritten
argument_list|,
name|isInlineSpecified
argument_list|,
name|hasWrittenPrototype
argument_list|)
return|;
block|}
end_function

begin_function_decl
specifier|static
name|FunctionDecl
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
specifier|const
name|DeclarationNameInfo
modifier|&
name|NameInfo
parameter_list|,
name|QualType
name|T
parameter_list|,
name|TypeSourceInfo
modifier|*
name|TInfo
parameter_list|,
name|StorageClass
name|S
init|=
name|SC_None
parameter_list|,
name|StorageClass
name|SCAsWritten
init|=
name|SC_None
parameter_list|,
name|bool
name|isInlineSpecified
init|=
name|false
parameter_list|,
name|bool
name|hasWrittenPrototype
init|=
name|true
parameter_list|)
function_decl|;
end_function_decl

begin_expr_stmt
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
end_expr_stmt

begin_decl_stmt
name|virtual
name|void
name|getNameForDiagnostic
argument_list|(
name|std
operator|::
name|string
operator|&
name|S
argument_list|,
specifier|const
name|PrintingPolicy
operator|&
name|Policy
argument_list|,
name|bool
name|Qualified
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

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
name|getOuterLocStart
argument_list|()
argument_list|,
name|EndRangeLoc
argument_list|)
return|;
block|}
end_expr_stmt

begin_function
name|void
name|setLocEnd
parameter_list|(
name|SourceLocation
name|E
parameter_list|)
block|{
name|EndRangeLoc
operator|=
name|E
expr_stmt|;
block|}
end_function

begin_comment
comment|/// \brief Returns true if the function has a body (definition). The
end_comment

begin_comment
comment|/// function body might be in any of the (re-)declarations of this
end_comment

begin_comment
comment|/// function. The variant that accepts a FunctionDecl pointer will
end_comment

begin_comment
comment|/// set that function declaration to the actual declaration
end_comment

begin_comment
comment|/// containing the body (if there is one).
end_comment

begin_decl_stmt
name|bool
name|hasBody
argument_list|(
specifier|const
name|FunctionDecl
operator|*
operator|&
name|Definition
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|virtual
name|bool
name|hasBody
argument_list|()
specifier|const
block|{
specifier|const
name|FunctionDecl
operator|*
name|Definition
block|;
return|return
name|hasBody
argument_list|(
name|Definition
argument_list|)
return|;
block|}
end_expr_stmt

begin_comment
comment|/// getBody - Retrieve the body (definition) of the function. The
end_comment

begin_comment
comment|/// function body might be in any of the (re-)declarations of this
end_comment

begin_comment
comment|/// function. The variant that accepts a FunctionDecl pointer will
end_comment

begin_comment
comment|/// set that function declaration to the actual declaration
end_comment

begin_comment
comment|/// containing the body (if there is one).
end_comment

begin_comment
comment|/// NOTE: For checking if there is a body, use hasBody() instead, to avoid
end_comment

begin_comment
comment|/// unnecessary AST de-serialization of the body.
end_comment

begin_decl_stmt
name|Stmt
modifier|*
name|getBody
argument_list|(
specifier|const
name|FunctionDecl
operator|*
operator|&
name|Definition
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|virtual
name|Stmt
operator|*
name|getBody
argument_list|()
specifier|const
block|{
specifier|const
name|FunctionDecl
operator|*
name|Definition
block|;
return|return
name|getBody
argument_list|(
name|Definition
argument_list|)
return|;
block|}
end_expr_stmt

begin_comment
comment|/// isThisDeclarationADefinition - Returns whether this specific
end_comment

begin_comment
comment|/// declaration of the function is also a definition. This does not
end_comment

begin_comment
comment|/// determine whether the function has been defined (e.g., in a
end_comment

begin_comment
comment|/// previous definition); for that information, use getBody.
end_comment

begin_comment
comment|/// FIXME: Should return true if function is deleted or defaulted. However,
end_comment

begin_comment
comment|/// CodeGenModule.cpp uses it, and I don't know if this would break it.
end_comment

begin_expr_stmt
name|bool
name|isThisDeclarationADefinition
argument_list|()
specifier|const
block|{
return|return
name|Body
return|;
block|}
end_expr_stmt

begin_function_decl
name|void
name|setBody
parameter_list|(
name|Stmt
modifier|*
name|B
parameter_list|)
function_decl|;
end_function_decl

begin_function
name|void
name|setLazyBody
parameter_list|(
name|uint64_t
name|Offset
parameter_list|)
block|{
name|Body
operator|=
name|Offset
expr_stmt|;
block|}
end_function

begin_comment
comment|/// Whether this function is variadic.
end_comment

begin_expr_stmt
name|bool
name|isVariadic
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// Whether this function is marked as virtual explicitly.
end_comment

begin_expr_stmt
name|bool
name|isVirtualAsWritten
argument_list|()
specifier|const
block|{
return|return
name|IsVirtualAsWritten
return|;
block|}
end_expr_stmt

begin_function
name|void
name|setVirtualAsWritten
parameter_list|(
name|bool
name|V
parameter_list|)
block|{
name|IsVirtualAsWritten
operator|=
name|V
expr_stmt|;
block|}
end_function

begin_comment
comment|/// Whether this virtual function is pure, i.e. makes the containing class
end_comment

begin_comment
comment|/// abstract.
end_comment

begin_expr_stmt
name|bool
name|isPure
argument_list|()
specifier|const
block|{
return|return
name|IsPure
return|;
block|}
end_expr_stmt

begin_function_decl
name|void
name|setPure
parameter_list|(
name|bool
name|P
init|=
name|true
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// Whether this function is "trivial" in some specialized C++ senses.
end_comment

begin_comment
comment|/// Can only be true for default constructors, copy constructors,
end_comment

begin_comment
comment|/// copy assignment operators, and destructors.  Not meaningful until
end_comment

begin_comment
comment|/// the class has been fully built by Sema.
end_comment

begin_expr_stmt
name|bool
name|isTrivial
argument_list|()
specifier|const
block|{
return|return
name|IsTrivial
return|;
block|}
end_expr_stmt

begin_function
name|void
name|setTrivial
parameter_list|(
name|bool
name|IT
parameter_list|)
block|{
name|IsTrivial
operator|=
name|IT
expr_stmt|;
block|}
end_function

begin_comment
comment|/// Whether falling off this function implicitly returns null/zero.
end_comment

begin_comment
comment|/// If a more specific implicit return value is required, front-ends
end_comment

begin_comment
comment|/// should synthesize the appropriate return statements.
end_comment

begin_expr_stmt
name|bool
name|hasImplicitReturnZero
argument_list|()
specifier|const
block|{
return|return
name|HasImplicitReturnZero
return|;
block|}
end_expr_stmt

begin_function
name|void
name|setHasImplicitReturnZero
parameter_list|(
name|bool
name|IRZ
parameter_list|)
block|{
name|HasImplicitReturnZero
operator|=
name|IRZ
expr_stmt|;
block|}
end_function

begin_comment
comment|/// \brief Whether this function has a prototype, either because one
end_comment

begin_comment
comment|/// was explicitly written or because it was "inherited" by merging
end_comment

begin_comment
comment|/// a declaration without a prototype with a declaration that has a
end_comment

begin_comment
comment|/// prototype.
end_comment

begin_expr_stmt
name|bool
name|hasPrototype
argument_list|()
specifier|const
block|{
return|return
name|HasWrittenPrototype
operator|||
name|HasInheritedPrototype
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|bool
name|hasWrittenPrototype
argument_list|()
specifier|const
block|{
return|return
name|HasWrittenPrototype
return|;
block|}
end_expr_stmt

begin_comment
comment|/// \brief Whether this function inherited its prototype from a
end_comment

begin_comment
comment|/// previous declaration.
end_comment

begin_expr_stmt
name|bool
name|hasInheritedPrototype
argument_list|()
specifier|const
block|{
return|return
name|HasInheritedPrototype
return|;
block|}
end_expr_stmt

begin_function
name|void
name|setHasInheritedPrototype
parameter_list|(
name|bool
name|P
init|=
name|true
parameter_list|)
block|{
name|HasInheritedPrototype
operator|=
name|P
expr_stmt|;
block|}
end_function

begin_comment
comment|/// \brief Whether this function has been deleted.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// A function that is "deleted" (via the C++0x "= delete" syntax)
end_comment

begin_comment
comment|/// acts like a normal function, except that it cannot actually be
end_comment

begin_comment
comment|/// called or have its address taken. Deleted functions are
end_comment

begin_comment
comment|/// typically used in C++ overload resolution to attract arguments
end_comment

begin_comment
comment|/// whose type or lvalue/rvalue-ness would permit the use of a
end_comment

begin_comment
comment|/// different overload that would behave incorrectly. For example,
end_comment

begin_comment
comment|/// one might use deleted functions to ban implicit conversion from
end_comment

begin_comment
comment|/// a floating-point number to an Integer type:
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// @code
end_comment

begin_comment
comment|/// struct Integer {
end_comment

begin_comment
comment|///   Integer(long); // construct from a long
end_comment

begin_comment
comment|///   Integer(double) = delete; // no construction from float or double
end_comment

begin_comment
comment|///   Integer(long double) = delete; // no construction from long double
end_comment

begin_comment
comment|/// };
end_comment

begin_comment
comment|/// @endcode
end_comment

begin_expr_stmt
name|bool
name|isDeleted
argument_list|()
specifier|const
block|{
return|return
name|IsDeleted
return|;
block|}
end_expr_stmt

begin_function
name|void
name|setDeleted
parameter_list|(
name|bool
name|D
init|=
name|true
parameter_list|)
block|{
name|IsDeleted
operator|=
name|D
expr_stmt|;
block|}
end_function

begin_comment
comment|/// \brief Determines whether this is a function "main", which is
end_comment

begin_comment
comment|/// the entry point into an executable program.
end_comment

begin_expr_stmt
name|bool
name|isMain
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// \brief Determines whether this function is a function with
end_comment

begin_comment
comment|/// external, C linkage.
end_comment

begin_expr_stmt
name|bool
name|isExternC
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// \brief Determines whether this is a global function.
end_comment

begin_expr_stmt
name|bool
name|isGlobal
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt

begin_function_decl
name|void
name|setPreviousDeclaration
parameter_list|(
name|FunctionDecl
modifier|*
name|PrevDecl
parameter_list|)
function_decl|;
end_function_decl

begin_expr_stmt
name|virtual
specifier|const
name|FunctionDecl
operator|*
name|getCanonicalDecl
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt

begin_function_decl
name|virtual
name|FunctionDecl
modifier|*
name|getCanonicalDecl
parameter_list|()
function_decl|;
end_function_decl

begin_expr_stmt
name|unsigned
name|getBuiltinID
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt

begin_comment
comment|// Iterator access to formal parameters.
end_comment

begin_expr_stmt
name|unsigned
name|param_size
argument_list|()
specifier|const
block|{
return|return
name|getNumParams
argument_list|()
return|;
block|}
end_expr_stmt

begin_typedef
typedef|typedef
name|ParmVarDecl
modifier|*
modifier|*
name|param_iterator
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|ParmVarDecl
modifier|*
specifier|const
modifier|*
name|param_const_iterator
typedef|;
end_typedef

begin_function
name|param_iterator
name|param_begin
parameter_list|()
block|{
return|return
name|ParamInfo
return|;
block|}
end_function

begin_function
name|param_iterator
name|param_end
parameter_list|()
block|{
return|return
name|ParamInfo
operator|+
name|param_size
argument_list|()
return|;
block|}
end_function

begin_expr_stmt
name|param_const_iterator
name|param_begin
argument_list|()
specifier|const
block|{
return|return
name|ParamInfo
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|param_const_iterator
name|param_end
argument_list|()
specifier|const
block|{
return|return
name|ParamInfo
operator|+
name|param_size
argument_list|()
return|;
block|}
end_expr_stmt

begin_comment
comment|/// getNumParams - Return the number of parameters this function must have
end_comment

begin_comment
comment|/// based on its FunctionType.  This is the length of the ParamInfo array
end_comment

begin_comment
comment|/// after it has been created.
end_comment

begin_expr_stmt
name|unsigned
name|getNumParams
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt

begin_decl_stmt
specifier|const
name|ParmVarDecl
modifier|*
name|getParamDecl
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
name|getNumParams
argument_list|()
operator|&&
literal|"Illegal param #"
argument_list|)
expr_stmt|;
return|return
name|ParamInfo
index|[
name|i
index|]
return|;
block|}
end_decl_stmt

begin_function
name|ParmVarDecl
modifier|*
name|getParamDecl
parameter_list|(
name|unsigned
name|i
parameter_list|)
block|{
name|assert
argument_list|(
name|i
operator|<
name|getNumParams
argument_list|()
operator|&&
literal|"Illegal param #"
argument_list|)
expr_stmt|;
return|return
name|ParamInfo
index|[
name|i
index|]
return|;
block|}
end_function

begin_function
name|void
name|setParams
parameter_list|(
name|ParmVarDecl
modifier|*
modifier|*
name|NewParamInfo
parameter_list|,
name|unsigned
name|NumParams
parameter_list|)
block|{
name|setParams
argument_list|(
name|getASTContext
argument_list|()
argument_list|,
name|NewParamInfo
argument_list|,
name|NumParams
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/// getMinRequiredArguments - Returns the minimum number of arguments
end_comment

begin_comment
comment|/// needed to call this function. This may be fewer than the number of
end_comment

begin_comment
comment|/// function parameters, if some of the parameters have default
end_comment

begin_comment
comment|/// arguments (in C++).
end_comment

begin_expr_stmt
name|unsigned
name|getMinRequiredArguments
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|QualType
name|getResultType
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
end_expr_stmt

begin_comment
comment|/// \brief Determine the type of an expression that calls this function.
end_comment

begin_expr_stmt
name|QualType
name|getCallResultType
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
name|getCallResultType
argument_list|(
name|getASTContext
argument_list|()
argument_list|)
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|StorageClass
name|getStorageClass
argument_list|()
specifier|const
block|{
return|return
name|StorageClass
argument_list|(
name|SClass
argument_list|)
return|;
block|}
end_expr_stmt

begin_function_decl
name|void
name|setStorageClass
parameter_list|(
name|StorageClass
name|SC
parameter_list|)
function_decl|;
end_function_decl

begin_expr_stmt
name|StorageClass
name|getStorageClassAsWritten
argument_list|()
specifier|const
block|{
return|return
name|StorageClass
argument_list|(
name|SClassAsWritten
argument_list|)
return|;
block|}
end_expr_stmt

begin_comment
comment|/// \brief Determine whether the "inline" keyword was specified for this
end_comment

begin_comment
comment|/// function.
end_comment

begin_expr_stmt
name|bool
name|isInlineSpecified
argument_list|()
specifier|const
block|{
return|return
name|IsInlineSpecified
return|;
block|}
end_expr_stmt

begin_comment
comment|/// Set whether the "inline" keyword was specified for this function.
end_comment

begin_function
name|void
name|setInlineSpecified
parameter_list|(
name|bool
name|I
parameter_list|)
block|{
name|IsInlineSpecified
operator|=
name|I
expr_stmt|;
name|IsInline
operator|=
name|I
expr_stmt|;
block|}
end_function

begin_comment
comment|/// Flag that this function is implicitly inline.
end_comment

begin_function
name|void
name|setImplicitlyInline
parameter_list|()
block|{
name|IsInline
operator|=
name|true
expr_stmt|;
block|}
end_function

begin_comment
comment|/// \brief Determine whether this function should be inlined, because it is
end_comment

begin_comment
comment|/// either marked "inline" or is a member function of a C++ class that
end_comment

begin_comment
comment|/// was defined in the class body.
end_comment

begin_expr_stmt
name|bool
name|isInlined
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|bool
name|isInlineDefinitionExternallyVisible
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// isOverloadedOperator - Whether this function declaration
end_comment

begin_comment
comment|/// represents an C++ overloaded operator, e.g., "operator+".
end_comment

begin_expr_stmt
name|bool
name|isOverloadedOperator
argument_list|()
specifier|const
block|{
return|return
name|getOverloadedOperator
argument_list|()
operator|!=
name|OO_None
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|OverloadedOperatorKind
name|getOverloadedOperator
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt

begin_expr_stmt
specifier|const
name|IdentifierInfo
operator|*
name|getLiteralIdentifier
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// \brief If this function is an instantiation of a member function
end_comment

begin_comment
comment|/// of a class template specialization, retrieves the function from
end_comment

begin_comment
comment|/// which it was instantiated.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This routine will return non-NULL for (non-templated) member
end_comment

begin_comment
comment|/// functions of class templates and for instantiations of function
end_comment

begin_comment
comment|/// templates. For example, given:
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
comment|///   void f(T);
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
comment|/// The declaration for X<int>::f is a (non-templated) FunctionDecl
end_comment

begin_comment
comment|/// whose parent is the class template specialization X<int>. For
end_comment

begin_comment
comment|/// this declaration, getInstantiatedFromFunction() will return
end_comment

begin_comment
comment|/// the FunctionDecl X<T>::A. When a complete definition of
end_comment

begin_comment
comment|/// X<int>::A is required, it will be instantiated from the
end_comment

begin_comment
comment|/// declaration returned by getInstantiatedFromMemberFunction().
end_comment

begin_expr_stmt
name|FunctionDecl
operator|*
name|getInstantiatedFromMemberFunction
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// \brief What kind of templated function this is.
end_comment

begin_expr_stmt
name|TemplatedKind
name|getTemplatedKind
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// \brief If this function is an instantiation of a member function of a
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
comment|/// member function FD.
end_comment

begin_function
name|void
name|setInstantiationOfMemberFunction
parameter_list|(
name|FunctionDecl
modifier|*
name|FD
parameter_list|,
name|TemplateSpecializationKind
name|TSK
parameter_list|)
block|{
name|setInstantiationOfMemberFunction
argument_list|(
name|getASTContext
argument_list|()
argument_list|,
name|FD
argument_list|,
name|TSK
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/// \brief Retrieves the function template that is described by this
end_comment

begin_comment
comment|/// function declaration.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Every function template is represented as a FunctionTemplateDecl
end_comment

begin_comment
comment|/// and a FunctionDecl (or something derived from FunctionDecl). The
end_comment

begin_comment
comment|/// former contains template properties (such as the template
end_comment

begin_comment
comment|/// parameter lists) while the latter contains the actual
end_comment

begin_comment
comment|/// description of the template's
end_comment

begin_comment
comment|/// contents. FunctionTemplateDecl::getTemplatedDecl() retrieves the
end_comment

begin_comment
comment|/// FunctionDecl that describes the function template,
end_comment

begin_comment
comment|/// getDescribedFunctionTemplate() retrieves the
end_comment

begin_comment
comment|/// FunctionTemplateDecl from a FunctionDecl.
end_comment

begin_expr_stmt
name|FunctionTemplateDecl
operator|*
name|getDescribedFunctionTemplate
argument_list|()
specifier|const
block|{
return|return
name|TemplateOrSpecialization
operator|.
name|dyn_cast
operator|<
name|FunctionTemplateDecl
operator|*
operator|>
operator|(
operator|)
return|;
block|}
end_expr_stmt

begin_function
name|void
name|setDescribedFunctionTemplate
parameter_list|(
name|FunctionTemplateDecl
modifier|*
name|Template
parameter_list|)
block|{
name|TemplateOrSpecialization
operator|=
name|Template
expr_stmt|;
block|}
end_function

begin_comment
comment|/// \brief Determine whether this function is a function template
end_comment

begin_comment
comment|/// specialization.
end_comment

begin_expr_stmt
name|bool
name|isFunctionTemplateSpecialization
argument_list|()
specifier|const
block|{
return|return
name|getPrimaryTemplate
argument_list|()
operator|!=
literal|0
return|;
block|}
end_expr_stmt

begin_comment
comment|/// \brief If this function is actually a function template specialization,
end_comment

begin_comment
comment|/// retrieve information about this function template specialization.
end_comment

begin_comment
comment|/// Otherwise, returns NULL.
end_comment

begin_expr_stmt
name|FunctionTemplateSpecializationInfo
operator|*
name|getTemplateSpecializationInfo
argument_list|()
specifier|const
block|{
return|return
name|TemplateOrSpecialization
operator|.
name|dyn_cast
operator|<
name|FunctionTemplateSpecializationInfo
operator|*
operator|>
operator|(
operator|)
return|;
block|}
end_expr_stmt

begin_comment
comment|/// \brief Determines whether this function is a function template
end_comment

begin_comment
comment|/// specialization or a member of a class template specialization that can
end_comment

begin_comment
comment|/// be implicitly instantiated.
end_comment

begin_expr_stmt
name|bool
name|isImplicitlyInstantiable
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// \brief Retrieve the function declaration from which this function could
end_comment

begin_comment
comment|/// be instantiated, if it is an instantiation (rather than a non-template
end_comment

begin_comment
comment|/// or a specialization, for example).
end_comment

begin_expr_stmt
name|FunctionDecl
operator|*
name|getTemplateInstantiationPattern
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// \brief Retrieve the primary template that this function template
end_comment

begin_comment
comment|/// specialization either specializes or was instantiated from.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// If this function declaration is not a function template specialization,
end_comment

begin_comment
comment|/// returns NULL.
end_comment

begin_expr_stmt
name|FunctionTemplateDecl
operator|*
name|getPrimaryTemplate
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// \brief Retrieve the template arguments used to produce this function
end_comment

begin_comment
comment|/// template specialization from the primary template.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// If this function declaration is not a function template specialization,
end_comment

begin_comment
comment|/// returns NULL.
end_comment

begin_expr_stmt
specifier|const
name|TemplateArgumentList
operator|*
name|getTemplateSpecializationArgs
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// \brief Retrieve the template argument list as written in the sources,
end_comment

begin_comment
comment|/// if any.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// If this function declaration is not a function template specialization
end_comment

begin_comment
comment|/// or if it had no explicit template argument list, returns NULL.
end_comment

begin_comment
comment|/// Note that it an explicit template argument list may be written empty,
end_comment

begin_comment
comment|/// e.g., template<> void foo<>(char* s);
end_comment

begin_expr_stmt
specifier|const
name|TemplateArgumentListInfo
operator|*
name|getTemplateSpecializationArgsAsWritten
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// \brief Specify that this function declaration is actually a function
end_comment

begin_comment
comment|/// template specialization.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param Template the function template that this function template
end_comment

begin_comment
comment|/// specialization specializes.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param TemplateArgs the template arguments that produced this
end_comment

begin_comment
comment|/// function template specialization from the template.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param InsertPos If non-NULL, the position in the function template
end_comment

begin_comment
comment|/// specialization set where the function template specialization data will
end_comment

begin_comment
comment|/// be inserted.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param TSK the kind of template specialization this is.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param TemplateArgsAsWritten location info of template arguments.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param PointOfInstantiation point at which the function template
end_comment

begin_comment
comment|/// specialization was first instantiated.
end_comment

begin_function
name|void
name|setFunctionTemplateSpecialization
parameter_list|(
name|FunctionTemplateDecl
modifier|*
name|Template
parameter_list|,
specifier|const
name|TemplateArgumentList
modifier|*
name|TemplateArgs
parameter_list|,
name|void
modifier|*
name|InsertPos
parameter_list|,
name|TemplateSpecializationKind
name|TSK
init|=
name|TSK_ImplicitInstantiation
parameter_list|,
specifier|const
name|TemplateArgumentListInfo
modifier|*
name|TemplateArgsAsWritten
init|=
literal|0
parameter_list|,
name|SourceLocation
name|PointOfInstantiation
init|=
name|SourceLocation
argument_list|()
parameter_list|)
block|{
name|setFunctionTemplateSpecialization
argument_list|(
name|getASTContext
argument_list|()
argument_list|,
name|Template
argument_list|,
name|TemplateArgs
argument_list|,
name|InsertPos
argument_list|,
name|TSK
argument_list|,
name|TemplateArgsAsWritten
argument_list|,
name|PointOfInstantiation
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/// \brief Specifies that this function declaration is actually a
end_comment

begin_comment
comment|/// dependent function template specialization.
end_comment

begin_function_decl
name|void
name|setDependentTemplateSpecialization
parameter_list|(
name|ASTContext
modifier|&
name|Context
parameter_list|,
specifier|const
name|UnresolvedSetImpl
modifier|&
name|Templates
parameter_list|,
specifier|const
name|TemplateArgumentListInfo
modifier|&
name|TemplateArgs
parameter_list|)
function_decl|;
end_function_decl

begin_expr_stmt
name|DependentFunctionTemplateSpecializationInfo
operator|*
name|getDependentSpecializationInfo
argument_list|()
specifier|const
block|{
return|return
name|TemplateOrSpecialization
operator|.
name|dyn_cast
operator|<
name|DependentFunctionTemplateSpecializationInfo
operator|*
operator|>
operator|(
operator|)
return|;
block|}
end_expr_stmt

begin_comment
comment|/// \brief Determine what kind of template instantiation this function
end_comment

begin_comment
comment|/// represents.
end_comment

begin_expr_stmt
name|TemplateSpecializationKind
name|getTemplateSpecializationKind
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// \brief Determine what kind of template instantiation this function
end_comment

begin_comment
comment|/// represents.
end_comment

begin_function_decl
name|void
name|setTemplateSpecializationKind
parameter_list|(
name|TemplateSpecializationKind
name|TSK
parameter_list|,
name|SourceLocation
name|PointOfInstantiation
init|=
name|SourceLocation
argument_list|()
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// \brief Retrieve the (first) point of instantiation of a function template
end_comment

begin_comment
comment|/// specialization or a member of a class template specialization.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \returns the first point of instantiation, if this function was
end_comment

begin_comment
comment|/// instantiated from a template; otherwie, returns an invalid source
end_comment

begin_comment
comment|/// location.
end_comment

begin_expr_stmt
name|SourceLocation
name|getPointOfInstantiation
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// \brief Determine whether this is or was instantiated from an out-of-line
end_comment

begin_comment
comment|/// definition of a member function.
end_comment

begin_expr_stmt
name|virtual
name|bool
name|isOutOfLine
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
name|FunctionDecl
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
name|firstFunction
operator|&&
name|K
operator|<=
name|lastFunction
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
name|FunctionDecl
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
name|FunctionDecl
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
name|FunctionDecl
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
name|FunctionDecl
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
comment|/// FieldDecl - An instance of this class is created by Sema::ActOnField to
end_comment

begin_comment
comment|/// represent a member of a struct/union/class.
end_comment

begin_decl_stmt
name|class
name|FieldDecl
range|:
name|public
name|DeclaratorDecl
block|{
comment|// FIXME: This can be packed into the bitfields in Decl.
name|bool
name|Mutable
operator|:
literal|1
block|;
name|mutable
name|unsigned
name|CachedFieldIndex
operator|:
literal|31
block|;
name|Expr
operator|*
name|BitWidth
block|;
name|protected
operator|:
name|FieldDecl
argument_list|(
argument|Kind DK
argument_list|,
argument|DeclContext *DC
argument_list|,
argument|SourceLocation L
argument_list|,
argument|IdentifierInfo *Id
argument_list|,
argument|QualType T
argument_list|,
argument|TypeSourceInfo *TInfo
argument_list|,
argument|Expr *BW
argument_list|,
argument|bool Mutable
argument_list|)
operator|:
name|DeclaratorDecl
argument_list|(
name|DK
argument_list|,
name|DC
argument_list|,
name|L
argument_list|,
name|Id
argument_list|,
name|T
argument_list|,
name|TInfo
argument_list|)
block|,
name|Mutable
argument_list|(
name|Mutable
argument_list|)
block|,
name|CachedFieldIndex
argument_list|(
literal|0
argument_list|)
block|,
name|BitWidth
argument_list|(
argument|BW
argument_list|)
block|{   }
name|public
operator|:
specifier|static
name|FieldDecl
operator|*
name|Create
argument_list|(
argument|const ASTContext&C
argument_list|,
argument|DeclContext *DC
argument_list|,
argument|SourceLocation L
argument_list|,
argument|IdentifierInfo *Id
argument_list|,
argument|QualType T
argument_list|,
argument|TypeSourceInfo *TInfo
argument_list|,
argument|Expr *BW
argument_list|,
argument|bool Mutable
argument_list|)
block|;
comment|/// getFieldIndex - Returns the index of this field within its record,
comment|/// as appropriate for passing to ASTRecordLayout::getFieldOffset.
name|unsigned
name|getFieldIndex
argument_list|()
specifier|const
block|;
comment|/// isMutable - Determines whether this field is mutable (C++ only).
name|bool
name|isMutable
argument_list|()
specifier|const
block|{
return|return
name|Mutable
return|;
block|}
comment|/// \brief Set whether this field is mutable (C++ only).
name|void
name|setMutable
argument_list|(
argument|bool M
argument_list|)
block|{
name|Mutable
operator|=
name|M
block|; }
comment|/// isBitfield - Determines whether this field is a bitfield.
name|bool
name|isBitField
argument_list|()
specifier|const
block|{
return|return
name|BitWidth
operator|!=
name|NULL
return|;
block|}
comment|/// @brief Determines whether this is an unnamed bitfield.
name|bool
name|isUnnamedBitfield
argument_list|()
specifier|const
block|{
return|return
name|BitWidth
operator|!=
name|NULL
operator|&&
operator|!
name|getDeclName
argument_list|()
return|;
block|}
comment|/// isAnonymousStructOrUnion - Determines whether this field is a
comment|/// representative for an anonymous struct or union. Such fields are
comment|/// unnamed and are implicitly generated by the implementation to
comment|/// store the data for the anonymous union or struct.
name|bool
name|isAnonymousStructOrUnion
argument_list|()
specifier|const
block|;
name|Expr
operator|*
name|getBitWidth
argument_list|()
specifier|const
block|{
return|return
name|BitWidth
return|;
block|}
name|void
name|setBitWidth
argument_list|(
argument|Expr *BW
argument_list|)
block|{
name|BitWidth
operator|=
name|BW
block|; }
comment|/// getParent - Returns the parent of this field declaration, which
comment|/// is the struct in which this method is defined.
specifier|const
name|RecordDecl
operator|*
name|getParent
argument_list|()
specifier|const
block|{
return|return
name|cast
operator|<
name|RecordDecl
operator|>
operator|(
name|getDeclContext
argument_list|()
operator|)
return|;
block|}
name|RecordDecl
operator|*
name|getParent
argument_list|()
block|{
return|return
name|cast
operator|<
name|RecordDecl
operator|>
operator|(
name|getDeclContext
argument_list|()
operator|)
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
argument|const FieldDecl *D
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
operator|>=
name|firstField
operator|&&
name|K
operator|<=
name|lastField
return|;
block|}
expr|}
block|;
comment|/// EnumConstantDecl - An instance of this object exists for each enum constant
comment|/// that is defined.  For example, in "enum X {a,b}", each of a/b are
comment|/// EnumConstantDecl's, X is an instance of EnumDecl, and the type of a/b is a
comment|/// TagType for the X EnumDecl.
name|class
name|EnumConstantDecl
operator|:
name|public
name|ValueDecl
block|{
name|Stmt
operator|*
name|Init
block|;
comment|// an integer constant expression
name|llvm
operator|::
name|APSInt
name|Val
block|;
comment|// The value.
name|protected
operator|:
name|EnumConstantDecl
argument_list|(
argument|DeclContext *DC
argument_list|,
argument|SourceLocation L
argument_list|,
argument|IdentifierInfo *Id
argument_list|,
argument|QualType T
argument_list|,
argument|Expr *E
argument_list|,
argument|const llvm::APSInt&V
argument_list|)
operator|:
name|ValueDecl
argument_list|(
name|EnumConstant
argument_list|,
name|DC
argument_list|,
name|L
argument_list|,
name|Id
argument_list|,
name|T
argument_list|)
block|,
name|Init
argument_list|(
operator|(
name|Stmt
operator|*
operator|)
name|E
argument_list|)
block|,
name|Val
argument_list|(
argument|V
argument_list|)
block|{}
name|public
operator|:
specifier|static
name|EnumConstantDecl
operator|*
name|Create
argument_list|(
argument|ASTContext&C
argument_list|,
argument|EnumDecl *DC
argument_list|,
argument|SourceLocation L
argument_list|,
argument|IdentifierInfo *Id
argument_list|,
argument|QualType T
argument_list|,
argument|Expr *E
argument_list|,
argument|const llvm::APSInt&V
argument_list|)
block|;
specifier|const
name|Expr
operator|*
name|getInitExpr
argument_list|()
specifier|const
block|{
return|return
operator|(
specifier|const
name|Expr
operator|*
operator|)
name|Init
return|;
block|}
name|Expr
operator|*
name|getInitExpr
argument_list|()
block|{
return|return
operator|(
name|Expr
operator|*
operator|)
name|Init
return|;
block|}
specifier|const
name|llvm
operator|::
name|APSInt
operator|&
name|getInitVal
argument_list|()
specifier|const
block|{
return|return
name|Val
return|;
block|}
name|void
name|setInitExpr
argument_list|(
argument|Expr *E
argument_list|)
block|{
name|Init
operator|=
operator|(
name|Stmt
operator|*
operator|)
name|E
block|; }
name|void
name|setInitVal
argument_list|(
argument|const llvm::APSInt&V
argument_list|)
block|{
name|Val
operator|=
name|V
block|; }
name|SourceRange
name|getSourceRange
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
name|classof
argument_list|(
argument|const EnumConstantDecl *D
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
name|EnumConstant
return|;
block|}
name|friend
name|class
name|StmtIteratorBase
block|; }
block|;
comment|/// IndirectFieldDecl - An instance of this class is created to represent a
comment|/// field injected from an anonymous union/struct into the parent scope.
comment|/// IndirectFieldDecl are always implicit.
name|class
name|IndirectFieldDecl
operator|:
name|public
name|ValueDecl
block|{
name|NamedDecl
operator|*
operator|*
name|Chaining
block|;
name|unsigned
name|ChainingSize
block|;
name|IndirectFieldDecl
argument_list|(
argument|DeclContext *DC
argument_list|,
argument|SourceLocation L
argument_list|,
argument|DeclarationName N
argument_list|,
argument|QualType T
argument_list|,
argument|NamedDecl **CH
argument_list|,
argument|unsigned CHS
argument_list|)
operator|:
name|ValueDecl
argument_list|(
name|IndirectField
argument_list|,
name|DC
argument_list|,
name|L
argument_list|,
name|N
argument_list|,
name|T
argument_list|)
block|,
name|Chaining
argument_list|(
name|CH
argument_list|)
block|,
name|ChainingSize
argument_list|(
argument|CHS
argument_list|)
block|{}
name|public
operator|:
specifier|static
name|IndirectFieldDecl
operator|*
name|Create
argument_list|(
argument|ASTContext&C
argument_list|,
argument|DeclContext *DC
argument_list|,
argument|SourceLocation L
argument_list|,
argument|IdentifierInfo *Id
argument_list|,
argument|QualType T
argument_list|,
argument|NamedDecl **CH
argument_list|,
argument|unsigned CHS
argument_list|)
block|;
typedef|typedef
name|NamedDecl
modifier|*
specifier|const
modifier|*
name|chain_iterator
typedef|;
name|chain_iterator
name|chain_begin
argument_list|()
specifier|const
block|{
return|return
name|Chaining
return|;
block|}
name|chain_iterator
name|chain_end
argument_list|()
specifier|const
block|{
return|return
name|Chaining
operator|+
name|ChainingSize
return|;
block|}
name|unsigned
name|getChainingSize
argument_list|()
specifier|const
block|{
return|return
name|ChainingSize
return|;
block|}
name|FieldDecl
operator|*
name|getAnonField
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
name|ChainingSize
operator|>=
literal|2
argument_list|)
block|;
return|return
name|cast
operator|<
name|FieldDecl
operator|>
operator|(
name|Chaining
index|[
name|ChainingSize
operator|-
literal|1
index|]
operator|)
return|;
block|}
name|VarDecl
operator|*
name|getVarDecl
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
name|ChainingSize
operator|>=
literal|2
argument_list|)
block|;
return|return
name|dyn_cast
operator|<
name|VarDecl
operator|>
operator|(
operator|*
name|chain_begin
argument_list|()
operator|)
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
argument|const IndirectFieldDecl *D
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
name|IndirectField
return|;
block|}
name|friend
name|class
name|ASTDeclReader
block|; }
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// TypeDecl - Represents a declaration of a type.
end_comment

begin_comment
comment|///
end_comment

begin_decl_stmt
name|class
name|TypeDecl
range|:
name|public
name|NamedDecl
block|{
comment|/// TypeForDecl - This indicates the Type object that represents
comment|/// this TypeDecl.  It is a cache maintained by
comment|/// ASTContext::getTypedefType, ASTContext::getTagDeclType, and
comment|/// ASTContext::getTemplateTypeParmType, and TemplateTypeParmDecl.
name|mutable
specifier|const
name|Type
operator|*
name|TypeForDecl
block|;
name|friend
name|class
name|ASTContext
block|;
name|friend
name|class
name|DeclContext
block|;
name|friend
name|class
name|TagDecl
block|;
name|friend
name|class
name|TemplateTypeParmDecl
block|;
name|friend
name|class
name|TagType
block|;
name|protected
operator|:
name|TypeDecl
argument_list|(
argument|Kind DK
argument_list|,
argument|DeclContext *DC
argument_list|,
argument|SourceLocation L
argument_list|,
argument|IdentifierInfo *Id
argument_list|)
operator|:
name|NamedDecl
argument_list|(
name|DK
argument_list|,
name|DC
argument_list|,
name|L
argument_list|,
name|Id
argument_list|)
block|,
name|TypeForDecl
argument_list|(
literal|0
argument_list|)
block|{}
name|public
operator|:
comment|// Low-level accessor
specifier|const
name|Type
operator|*
name|getTypeForDecl
argument_list|()
specifier|const
block|{
return|return
name|TypeForDecl
return|;
block|}
name|void
name|setTypeForDecl
argument_list|(
argument|const Type *TD
argument_list|)
block|{
name|TypeForDecl
operator|=
name|TD
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
argument|const TypeDecl *D
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
operator|>=
name|firstType
operator|&&
name|K
operator|<=
name|lastType
return|;
block|}
expr|}
block|;
name|class
name|TypedefDecl
operator|:
name|public
name|TypeDecl
block|,
name|public
name|Redeclarable
operator|<
name|TypedefDecl
operator|>
block|{
comment|/// UnderlyingType - This is the type the typedef is set to.
name|TypeSourceInfo
operator|*
name|TInfo
block|;
name|TypedefDecl
argument_list|(
argument|DeclContext *DC
argument_list|,
argument|SourceLocation L
argument_list|,
argument|IdentifierInfo *Id
argument_list|,
argument|TypeSourceInfo *TInfo
argument_list|)
operator|:
name|TypeDecl
argument_list|(
name|Typedef
argument_list|,
name|DC
argument_list|,
name|L
argument_list|,
name|Id
argument_list|)
block|,
name|TInfo
argument_list|(
argument|TInfo
argument_list|)
block|{}
name|protected
operator|:
typedef|typedef
name|Redeclarable
operator|<
name|TypedefDecl
operator|>
name|redeclarable_base
expr_stmt|;
name|virtual
name|TypedefDecl
operator|*
name|getNextRedeclaration
argument_list|()
block|{
return|return
name|RedeclLink
operator|.
name|getNext
argument_list|()
return|;
block|}
name|public
operator|:
typedef|typedef
name|redeclarable_base
operator|::
name|redecl_iterator
name|redecl_iterator
expr_stmt|;
name|redecl_iterator
name|redecls_begin
argument_list|()
specifier|const
block|{
return|return
name|redeclarable_base
operator|::
name|redecls_begin
argument_list|()
return|;
block|}
name|redecl_iterator
name|redecls_end
argument_list|()
specifier|const
block|{
return|return
name|redeclarable_base
operator|::
name|redecls_end
argument_list|()
return|;
block|}
specifier|static
name|TypedefDecl
operator|*
name|Create
argument_list|(
argument|ASTContext&C
argument_list|,
argument|DeclContext *DC
argument_list|,
argument|SourceLocation L
argument_list|,
argument|IdentifierInfo *Id
argument_list|,
argument|TypeSourceInfo *TInfo
argument_list|)
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|TypeSourceInfo
operator|*
name|getTypeSourceInfo
argument_list|()
specifier|const
block|{
return|return
name|TInfo
return|;
block|}
end_expr_stmt

begin_comment
comment|/// Retrieves the canonical declaration of this typedef.
end_comment

begin_function
name|TypedefDecl
modifier|*
name|getCanonicalDecl
parameter_list|()
block|{
return|return
name|getFirstDeclaration
argument_list|()
return|;
block|}
end_function

begin_expr_stmt
specifier|const
name|TypedefDecl
operator|*
name|getCanonicalDecl
argument_list|()
specifier|const
block|{
return|return
name|getFirstDeclaration
argument_list|()
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|QualType
name|getUnderlyingType
argument_list|()
specifier|const
block|{
return|return
name|TInfo
operator|->
name|getType
argument_list|()
return|;
block|}
end_expr_stmt

begin_function
name|void
name|setTypeSourceInfo
parameter_list|(
name|TypeSourceInfo
modifier|*
name|newType
parameter_list|)
block|{
name|TInfo
operator|=
name|newType
expr_stmt|;
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
name|classof
parameter_list|(
specifier|const
name|TypedefDecl
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
name|Typedef
return|;
block|}
end_function

begin_decl_stmt
unit|};
name|class
name|TypedefDecl
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// TagDecl - Represents the declaration of a struct/union/class/enum.
end_comment

begin_decl_stmt
name|class
name|TagDecl
range|:
name|public
name|TypeDecl
decl_stmt|,
name|public
name|DeclContext
decl_stmt|,
name|public
name|Redeclarable
decl|<
name|TagDecl
decl|>
block|{
name|public
label|:
comment|// This is really ugly.
typedef|typedef
name|TagTypeKind
name|TagKind
typedef|;
name|private
label|:
comment|// FIXME: This can be packed into the bitfields in Decl.
comment|/// TagDeclKind - The TagKind enum.
name|unsigned
name|TagDeclKind
range|:
literal|2
decl_stmt|;
comment|/// IsDefinition - True if this is a definition ("struct foo {};"), false if
comment|/// it is a declaration ("struct foo;").
name|bool
name|IsDefinition
range|:
literal|1
decl_stmt|;
comment|/// IsBeingDefined - True if this is currently being defined.
name|bool
name|IsBeingDefined
range|:
literal|1
decl_stmt|;
comment|/// IsEmbeddedInDeclarator - True if this tag declaration is
comment|/// "embedded" (i.e., defined or declared for the very first time)
comment|/// in the syntax of a declarator.
name|bool
name|IsEmbeddedInDeclarator
range|:
literal|1
decl_stmt|;
name|protected
label|:
comment|// These are used by (and only defined for) EnumDecl.
name|unsigned
name|NumPositiveBits
range|:
literal|8
decl_stmt|;
name|unsigned
name|NumNegativeBits
range|:
literal|8
decl_stmt|;
comment|/// IsScoped - True if this tag declaration is a scoped enumeration. Only
comment|/// possible in C++0x mode.
name|bool
name|IsScoped
range|:
literal|1
decl_stmt|;
comment|/// IsScopedUsingClassTag - If this tag declaration is a scoped enum,
comment|/// then this is true if the scoped enum was declared using the class
comment|/// tag, false if it was declared with the struct tag. No meaning is
comment|/// associated if this tag declaration is not a scoped enum.
name|bool
name|IsScopedUsingClassTag
range|:
literal|1
decl_stmt|;
comment|/// IsFixed - True if this is an enumeration with fixed underlying type. Only
comment|/// possible in C++0x mode.
name|bool
name|IsFixed
range|:
literal|1
decl_stmt|;
name|private
label|:
name|SourceLocation
name|TagKeywordLoc
decl_stmt|;
name|SourceLocation
name|RBraceLoc
decl_stmt|;
comment|// A struct representing syntactic qualifier info,
comment|// to be used for the (uncommon) case of out-of-line declarations.
typedef|typedef
name|QualifierInfo
name|ExtInfo
typedef|;
comment|/// TypedefDeclOrQualifier - If the (out-of-line) tag declaration name
comment|/// is qualified, it points to the qualifier info (nns and range);
comment|/// otherwise, if the tag declaration is anonymous and it is part of
comment|/// a typedef, it points to the TypedefDecl (used for mangling);
comment|/// otherwise, it is a null (TypedefDecl) pointer.
name|llvm
operator|::
name|PointerUnion
operator|<
name|TypedefDecl
operator|*
operator|,
name|ExtInfo
operator|*
operator|>
name|TypedefDeclOrQualifier
expr_stmt|;
name|bool
name|hasExtInfo
argument_list|()
specifier|const
block|{
return|return
name|TypedefDeclOrQualifier
operator|.
name|is
operator|<
name|ExtInfo
operator|*
operator|>
operator|(
operator|)
return|;
block|}
name|ExtInfo
modifier|*
name|getExtInfo
parameter_list|()
block|{
return|return
name|TypedefDeclOrQualifier
operator|.
name|get
operator|<
name|ExtInfo
operator|*
operator|>
operator|(
operator|)
return|;
block|}
specifier|const
name|ExtInfo
operator|*
name|getExtInfo
argument_list|()
specifier|const
block|{
return|return
name|TypedefDeclOrQualifier
operator|.
name|get
operator|<
name|ExtInfo
operator|*
operator|>
operator|(
operator|)
return|;
block|}
name|protected
label|:
name|TagDecl
argument_list|(
argument|Kind DK
argument_list|,
argument|TagKind TK
argument_list|,
argument|DeclContext *DC
argument_list|,
argument|SourceLocation L
argument_list|,
argument|IdentifierInfo *Id
argument_list|,
argument|TagDecl *PrevDecl
argument_list|,
argument|SourceLocation TKL = SourceLocation()
argument_list|)
block|:
name|TypeDecl
argument_list|(
name|DK
argument_list|,
name|DC
argument_list|,
name|L
argument_list|,
name|Id
argument_list|)
operator|,
name|DeclContext
argument_list|(
name|DK
argument_list|)
operator|,
name|TagKeywordLoc
argument_list|(
name|TKL
argument_list|)
operator|,
name|TypedefDeclOrQualifier
argument_list|(
argument|(TypedefDecl*)
literal|0
argument_list|)
block|{
name|assert
argument_list|(
operator|(
name|DK
operator|!=
name|Enum
operator|||
name|TK
operator|==
name|TTK_Enum
operator|)
operator|&&
literal|"EnumDecl not matched with TTK_Enum"
argument_list|)
block|;
name|TagDeclKind
operator|=
name|TK
block|;
name|IsDefinition
operator|=
name|false
block|;
name|IsBeingDefined
operator|=
name|false
block|;
name|IsEmbeddedInDeclarator
operator|=
name|false
block|;
name|setPreviousDeclaration
argument_list|(
name|PrevDecl
argument_list|)
block|;   }
typedef|typedef
name|Redeclarable
operator|<
name|TagDecl
operator|>
name|redeclarable_base
expr_stmt|;
name|virtual
name|TagDecl
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
comment|/// @brief Completes the definition of this tag declaration.
comment|///
comment|/// This is a helper function for derived classes.
name|void
name|completeDefinition
parameter_list|()
function_decl|;
name|public
label|:
typedef|typedef
name|redeclarable_base
operator|::
name|redecl_iterator
name|redecl_iterator
expr_stmt|;
name|redecl_iterator
name|redecls_begin
argument_list|()
specifier|const
block|{
return|return
name|redeclarable_base
operator|::
name|redecls_begin
argument_list|()
return|;
block|}
name|redecl_iterator
name|redecls_end
argument_list|()
specifier|const
block|{
return|return
name|redeclarable_base
operator|::
name|redecls_end
argument_list|()
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
block|}
name|SourceLocation
name|getTagKeywordLoc
argument_list|()
specifier|const
block|{
return|return
name|TagKeywordLoc
return|;
block|}
name|void
name|setTagKeywordLoc
parameter_list|(
name|SourceLocation
name|TKL
parameter_list|)
block|{
name|TagKeywordLoc
operator|=
name|TKL
expr_stmt|;
block|}
comment|/// getInnerLocStart - Return SourceLocation representing start of source
comment|/// range ignoring outer template declarations.
name|virtual
name|SourceLocation
name|getInnerLocStart
argument_list|()
specifier|const
block|{
return|return
name|TagKeywordLoc
return|;
block|}
comment|/// getOuterLocStart - Return SourceLocation representing start of source
comment|/// range taking into account any outer template declarations.
name|SourceLocation
name|getOuterLocStart
argument_list|()
specifier|const
expr_stmt|;
name|virtual
name|SourceRange
name|getSourceRange
argument_list|()
specifier|const
expr_stmt|;
name|virtual
name|TagDecl
modifier|*
name|getCanonicalDecl
parameter_list|()
function_decl|;
specifier|const
name|TagDecl
operator|*
name|getCanonicalDecl
argument_list|()
specifier|const
block|{
return|return
name|const_cast
operator|<
name|TagDecl
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
comment|/// isThisDeclarationADefinition() - Return true if this declaration
comment|/// defines the type.  Provided for consistency.
name|bool
name|isThisDeclarationADefinition
argument_list|()
specifier|const
block|{
return|return
name|isDefinition
argument_list|()
return|;
block|}
comment|/// isDefinition - Return true if this decl has its body specified.
name|bool
name|isDefinition
argument_list|()
specifier|const
block|{
return|return
name|IsDefinition
return|;
block|}
comment|/// isBeingDefined - Return true if this decl is currently being defined.
name|bool
name|isBeingDefined
argument_list|()
specifier|const
block|{
return|return
name|IsBeingDefined
return|;
block|}
name|bool
name|isEmbeddedInDeclarator
argument_list|()
specifier|const
block|{
return|return
name|IsEmbeddedInDeclarator
return|;
block|}
name|void
name|setEmbeddedInDeclarator
parameter_list|(
name|bool
name|isInDeclarator
parameter_list|)
block|{
name|IsEmbeddedInDeclarator
operator|=
name|isInDeclarator
expr_stmt|;
block|}
comment|/// \brief Whether this declaration declares a type that is
comment|/// dependent, i.e., a type that somehow depends on template
comment|/// parameters.
name|bool
name|isDependentType
argument_list|()
specifier|const
block|{
return|return
name|isDependentContext
argument_list|()
return|;
block|}
comment|/// @brief Starts the definition of this tag declaration.
comment|///
comment|/// This method should be invoked at the beginning of the definition
comment|/// of this tag declaration. It will set the tag type into a state
comment|/// where it is in the process of being defined.
name|void
name|startDefinition
parameter_list|()
function_decl|;
comment|/// getDefinition - Returns the TagDecl that actually defines this
comment|///  struct/union/class/enum.  When determining whether or not a
comment|///  struct/union/class/enum is completely defined, one should use this method
comment|///  as opposed to 'isDefinition'.  'isDefinition' indicates whether or not a
comment|///  specific TagDecl is defining declaration, not whether or not the
comment|///  struct/union/class/enum type is defined.  This method returns NULL if
comment|///  there is no TagDecl that defines the struct/union/class/enum.
name|TagDecl
operator|*
name|getDefinition
argument_list|()
specifier|const
expr_stmt|;
name|void
name|setDefinition
parameter_list|(
name|bool
name|V
parameter_list|)
block|{
name|IsDefinition
operator|=
name|V
expr_stmt|;
block|}
specifier|const
name|char
operator|*
name|getKindName
argument_list|()
specifier|const
block|{
return|return
name|TypeWithKeyword
operator|::
name|getTagTypeKindName
argument_list|(
name|getTagKind
argument_list|()
argument_list|)
return|;
block|}
name|TagKind
name|getTagKind
argument_list|()
specifier|const
block|{
return|return
name|TagKind
argument_list|(
name|TagDeclKind
argument_list|)
return|;
block|}
name|void
name|setTagKind
parameter_list|(
name|TagKind
name|TK
parameter_list|)
block|{
name|TagDeclKind
operator|=
name|TK
expr_stmt|;
block|}
name|bool
name|isStruct
argument_list|()
specifier|const
block|{
return|return
name|getTagKind
argument_list|()
operator|==
name|TTK_Struct
return|;
block|}
name|bool
name|isClass
argument_list|()
specifier|const
block|{
return|return
name|getTagKind
argument_list|()
operator|==
name|TTK_Class
return|;
block|}
name|bool
name|isUnion
argument_list|()
specifier|const
block|{
return|return
name|getTagKind
argument_list|()
operator|==
name|TTK_Union
return|;
block|}
name|bool
name|isEnum
argument_list|()
specifier|const
block|{
return|return
name|getTagKind
argument_list|()
operator|==
name|TTK_Enum
return|;
block|}
name|TypedefDecl
operator|*
name|getTypedefForAnonDecl
argument_list|()
specifier|const
block|{
return|return
name|hasExtInfo
argument_list|()
operator|?
literal|0
operator|:
name|TypedefDeclOrQualifier
operator|.
name|get
operator|<
name|TypedefDecl
operator|*
operator|>
operator|(
operator|)
return|;
block|}
name|void
name|setTypedefForAnonDecl
parameter_list|(
name|TypedefDecl
modifier|*
name|TDD
parameter_list|)
function_decl|;
comment|/// \brief Retrieve the nested-name-specifier that qualifies the name of this
comment|/// declaration, if it was present in the source.
name|NestedNameSpecifier
operator|*
name|getQualifier
argument_list|()
specifier|const
block|{
return|return
name|hasExtInfo
argument_list|()
operator|?
name|getExtInfo
argument_list|()
operator|->
name|QualifierLoc
operator|.
name|getNestedNameSpecifier
argument_list|()
operator|:
literal|0
return|;
block|}
comment|/// \brief Retrieve the nested-name-specifier (with source-location
comment|/// information) that qualifies the name of this declaration, if it was
comment|/// present in the source.
name|NestedNameSpecifierLoc
name|getQualifierLoc
argument_list|()
specifier|const
block|{
return|return
name|hasExtInfo
argument_list|()
operator|?
name|getExtInfo
argument_list|()
operator|->
name|QualifierLoc
operator|:
name|NestedNameSpecifierLoc
argument_list|()
return|;
block|}
name|void
name|setQualifierInfo
parameter_list|(
name|NestedNameSpecifierLoc
name|QualifierLoc
parameter_list|)
function_decl|;
name|unsigned
name|getNumTemplateParameterLists
argument_list|()
specifier|const
block|{
return|return
name|hasExtInfo
argument_list|()
operator|?
name|getExtInfo
argument_list|()
operator|->
name|NumTemplParamLists
operator|:
literal|0
return|;
block|}
name|TemplateParameterList
modifier|*
name|getTemplateParameterList
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
name|getNumTemplateParameterLists
argument_list|()
argument_list|)
expr_stmt|;
return|return
name|getExtInfo
argument_list|()
operator|->
name|TemplParamLists
index|[
name|i
index|]
return|;
block|}
name|void
name|setTemplateParameterListsInfo
parameter_list|(
name|ASTContext
modifier|&
name|Context
parameter_list|,
name|unsigned
name|NumTPLists
parameter_list|,
name|TemplateParameterList
modifier|*
modifier|*
name|TPLists
parameter_list|)
block|{
name|getExtInfo
argument_list|()
operator|->
name|setTemplateParameterListsInfo
argument_list|(
name|Context
argument_list|,
name|NumTPLists
argument_list|,
name|TPLists
argument_list|)
expr_stmt|;
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
name|TagDecl
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
operator|>=
name|firstTag
operator|&&
name|K
operator|<=
name|lastTag
return|;
block|}
specifier|static
name|DeclContext
modifier|*
name|castToDeclContext
parameter_list|(
specifier|const
name|TagDecl
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
name|TagDecl
operator|*
operator|>
operator|(
name|D
operator|)
operator|)
return|;
block|}
specifier|static
name|TagDecl
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
name|TagDecl
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
comment|/// EnumDecl - Represents an enum.  As an extension, we allow forward-declared
end_comment

begin_comment
comment|/// enums.
end_comment

begin_decl_stmt
name|class
name|EnumDecl
range|:
name|public
name|TagDecl
block|{
comment|/// IntegerType - This represent the integer type that the enum corresponds
comment|/// to for code generation purposes.  Note that the enumerator constants may
comment|/// have a different type than this does.
comment|///
comment|/// If the underlying integer type was explicitly stated in the source
comment|/// code, this is a TypeSourceInfo* for that type. Otherwise this type
comment|/// was automatically deduced somehow, and this is a Type*.
comment|///
comment|/// Normally if IsFixed(), this would contain a TypeSourceInfo*, but in
comment|/// some cases it won't.
comment|///
comment|/// The underlying type of an enumeration never has any qualifiers, so
comment|/// we can get away with just storing a raw Type*, and thus save an
comment|/// extra pointer when TypeSourceInfo is needed.
name|llvm
operator|::
name|PointerUnion
operator|<
specifier|const
name|Type
operator|*
block|,
name|TypeSourceInfo
operator|*
operator|>
name|IntegerType
block|;
comment|/// PromotionType - The integer type that values of this type should
comment|/// promote to.  In C, enumerators are generally of an integer type
comment|/// directly, but gcc-style large enumerators (and all enumerators
comment|/// in C++) are of the enum type instead.
name|QualType
name|PromotionType
block|;
comment|/// \brief If the enumeration was instantiated from an enumeration
comment|/// within a class or function template, this pointer refers to the
comment|/// enumeration declared within the template.
name|EnumDecl
operator|*
name|InstantiatedFrom
block|;
comment|// The number of positive and negative bits required by the
comment|// enumerators are stored in the SubclassBits field.
block|enum
block|{
name|NumBitsWidth
operator|=
literal|8
block|,
name|NumBitsMask
operator|=
operator|(
literal|1
operator|<<
name|NumBitsWidth
operator|)
operator|-
literal|1
block|}
block|;
name|EnumDecl
argument_list|(
argument|DeclContext *DC
argument_list|,
argument|SourceLocation L
argument_list|,
argument|IdentifierInfo *Id
argument_list|,
argument|EnumDecl *PrevDecl
argument_list|,
argument|SourceLocation TKL
argument_list|,
argument|bool Scoped
argument_list|,
argument|bool ScopedUsingClassTag
argument_list|,
argument|bool Fixed
argument_list|)
operator|:
name|TagDecl
argument_list|(
name|Enum
argument_list|,
name|TTK_Enum
argument_list|,
name|DC
argument_list|,
name|L
argument_list|,
name|Id
argument_list|,
name|PrevDecl
argument_list|,
name|TKL
argument_list|)
block|,
name|InstantiatedFrom
argument_list|(
literal|0
argument_list|)
block|{
name|assert
argument_list|(
name|Scoped
operator|||
operator|!
name|ScopedUsingClassTag
argument_list|)
block|;
name|IntegerType
operator|=
operator|(
specifier|const
name|Type
operator|*
operator|)
literal|0
block|;
name|NumNegativeBits
operator|=
literal|0
block|;
name|NumPositiveBits
operator|=
literal|0
block|;
name|IsScoped
operator|=
name|Scoped
block|;
name|IsScopedUsingClassTag
operator|=
name|ScopedUsingClassTag
block|;
name|IsFixed
operator|=
name|Fixed
block|;     }
name|public
operator|:
name|EnumDecl
operator|*
name|getCanonicalDecl
argument_list|()
block|{
return|return
name|cast
operator|<
name|EnumDecl
operator|>
operator|(
name|TagDecl
operator|::
name|getCanonicalDecl
argument_list|()
operator|)
return|;
block|}
specifier|const
name|EnumDecl
operator|*
name|getCanonicalDecl
argument_list|()
specifier|const
block|{
return|return
name|cast
operator|<
name|EnumDecl
operator|>
operator|(
name|TagDecl
operator|::
name|getCanonicalDecl
argument_list|()
operator|)
return|;
block|}
specifier|const
name|EnumDecl
operator|*
name|getPreviousDeclaration
argument_list|()
specifier|const
block|{
return|return
name|cast_or_null
operator|<
name|EnumDecl
operator|>
operator|(
name|TagDecl
operator|::
name|getPreviousDeclaration
argument_list|()
operator|)
return|;
block|}
name|EnumDecl
operator|*
name|getPreviousDeclaration
argument_list|()
block|{
return|return
name|cast_or_null
operator|<
name|EnumDecl
operator|>
operator|(
name|TagDecl
operator|::
name|getPreviousDeclaration
argument_list|()
operator|)
return|;
block|}
specifier|static
name|EnumDecl
operator|*
name|Create
argument_list|(
argument|ASTContext&C
argument_list|,
argument|DeclContext *DC
argument_list|,
argument|SourceLocation L
argument_list|,
argument|IdentifierInfo *Id
argument_list|,
argument|SourceLocation TKL
argument_list|,
argument|EnumDecl *PrevDecl
argument_list|,
argument|bool IsScoped
argument_list|,
argument|bool IsScopedUsingClassTag
argument_list|,
argument|bool IsFixed
argument_list|)
block|;
specifier|static
name|EnumDecl
operator|*
name|Create
argument_list|(
argument|ASTContext&C
argument_list|,
argument|EmptyShell Empty
argument_list|)
block|;
comment|/// completeDefinition - When created, the EnumDecl corresponds to a
comment|/// forward-declared enum. This method is used to mark the
comment|/// declaration as being defined; it's enumerators have already been
comment|/// added (via DeclContext::addDecl). NewType is the new underlying
comment|/// type of the enumeration type.
name|void
name|completeDefinition
argument_list|(
argument|QualType NewType
argument_list|,
argument|QualType PromotionType
argument_list|,
argument|unsigned NumPositiveBits
argument_list|,
argument|unsigned NumNegativeBits
argument_list|)
block|;
comment|// enumerator_iterator - Iterates through the enumerators of this
comment|// enumeration.
typedef|typedef
name|specific_decl_iterator
operator|<
name|EnumConstantDecl
operator|>
name|enumerator_iterator
expr_stmt|;
name|enumerator_iterator
name|enumerator_begin
argument_list|()
specifier|const
block|{
specifier|const
name|EnumDecl
operator|*
name|E
operator|=
name|cast_or_null
operator|<
name|EnumDecl
operator|>
operator|(
name|getDefinition
argument_list|()
operator|)
block|;
if|if
condition|(
operator|!
name|E
condition|)
name|E
operator|=
name|this
expr_stmt|;
end_decl_stmt

begin_return
return|return
name|enumerator_iterator
argument_list|(
name|E
operator|->
name|decls_begin
argument_list|()
argument_list|)
return|;
end_return

begin_macro
unit|}    enumerator_iterator
name|enumerator_end
argument_list|()
end_macro

begin_expr_stmt
specifier|const
block|{
specifier|const
name|EnumDecl
operator|*
name|E
operator|=
name|cast_or_null
operator|<
name|EnumDecl
operator|>
operator|(
name|getDefinition
argument_list|()
operator|)
block|;
if|if
condition|(
operator|!
name|E
condition|)
name|E
operator|=
name|this
expr_stmt|;
end_expr_stmt

begin_return
return|return
name|enumerator_iterator
argument_list|(
name|E
operator|->
name|decls_end
argument_list|()
argument_list|)
return|;
end_return

begin_comment
unit|}
comment|/// getPromotionType - Return the integer type that enumerators
end_comment

begin_comment
comment|/// should promote to.
end_comment

begin_macro
unit|QualType
name|getPromotionType
argument_list|()
end_macro

begin_expr_stmt
specifier|const
block|{
return|return
name|PromotionType
return|;
block|}
end_expr_stmt

begin_comment
comment|/// \brief Set the promotion type.
end_comment

begin_function
name|void
name|setPromotionType
parameter_list|(
name|QualType
name|T
parameter_list|)
block|{
name|PromotionType
operator|=
name|T
expr_stmt|;
block|}
end_function

begin_comment
comment|/// getIntegerType - Return the integer type this enum decl corresponds to.
end_comment

begin_comment
comment|/// This returns a null qualtype for an enum forward definition.
end_comment

begin_expr_stmt
name|QualType
name|getIntegerType
argument_list|()
specifier|const
block|{
if|if
condition|(
operator|!
name|IntegerType
condition|)
return|return
name|QualType
argument_list|()
return|;
end_expr_stmt

begin_if
if|if
condition|(
specifier|const
name|Type
modifier|*
name|T
init|=
name|IntegerType
operator|.
name|dyn_cast
operator|<
specifier|const
name|Type
operator|*
operator|>
operator|(
operator|)
condition|)
return|return
name|QualType
argument_list|(
name|T
argument_list|,
literal|0
argument_list|)
return|;
end_if

begin_return
return|return
name|IntegerType
operator|.
name|get
operator|<
name|TypeSourceInfo
operator|*
operator|>
operator|(
operator|)
operator|->
name|getType
argument_list|()
return|;
end_return

begin_comment
unit|}
comment|/// \brief Set the underlying integer type.
end_comment

begin_macro
unit|void
name|setIntegerType
argument_list|(
argument|QualType T
argument_list|)
end_macro

begin_block
block|{
name|IntegerType
operator|=
name|T
operator|.
name|getTypePtrOrNull
argument_list|()
expr_stmt|;
block|}
end_block

begin_comment
comment|/// \brief Set the underlying integer type source info.
end_comment

begin_function
name|void
name|setIntegerTypeSourceInfo
parameter_list|(
name|TypeSourceInfo
modifier|*
name|TInfo
parameter_list|)
block|{
name|IntegerType
operator|=
name|TInfo
expr_stmt|;
block|}
end_function

begin_comment
comment|/// \brief Return the type source info for the underlying integer type,
end_comment

begin_comment
comment|/// if no type source info exists, return 0.
end_comment

begin_expr_stmt
name|TypeSourceInfo
operator|*
name|getIntegerTypeSourceInfo
argument_list|()
specifier|const
block|{
return|return
name|IntegerType
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
end_expr_stmt

begin_comment
comment|/// \brief Returns the width in bits requred to store all the
end_comment

begin_comment
comment|/// non-negative enumerators of this enum.
end_comment

begin_expr_stmt
name|unsigned
name|getNumPositiveBits
argument_list|()
specifier|const
block|{
return|return
name|NumPositiveBits
return|;
block|}
end_expr_stmt

begin_function
name|void
name|setNumPositiveBits
parameter_list|(
name|unsigned
name|Num
parameter_list|)
block|{
name|NumPositiveBits
operator|=
name|Num
expr_stmt|;
name|assert
argument_list|(
name|NumPositiveBits
operator|==
name|Num
operator|&&
literal|"can't store this bitcount"
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/// \brief Returns the width in bits requred to store all the
end_comment

begin_comment
comment|/// negative enumerators of this enum.  These widths include
end_comment

begin_comment
comment|/// the rightmost leading 1;  that is:
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// MOST NEGATIVE ENUMERATOR     PATTERN     NUM NEGATIVE BITS
end_comment

begin_comment
comment|/// ------------------------     -------     -----------------
end_comment

begin_comment
comment|///                       -1     1111111                     1
end_comment

begin_comment
comment|///                      -10     1110110                     5
end_comment

begin_comment
comment|///                     -101     1001011                     8
end_comment

begin_expr_stmt
name|unsigned
name|getNumNegativeBits
argument_list|()
specifier|const
block|{
return|return
name|NumNegativeBits
return|;
block|}
end_expr_stmt

begin_function
name|void
name|setNumNegativeBits
parameter_list|(
name|unsigned
name|Num
parameter_list|)
block|{
name|NumNegativeBits
operator|=
name|Num
expr_stmt|;
block|}
end_function

begin_comment
comment|/// \brief Returns true if this is a C++0x scoped enumeration.
end_comment

begin_expr_stmt
name|bool
name|isScoped
argument_list|()
specifier|const
block|{
return|return
name|IsScoped
return|;
block|}
end_expr_stmt

begin_comment
comment|/// \brief Returns true if this is a C++0x scoped enumeration.
end_comment

begin_expr_stmt
name|bool
name|isScopedUsingClassTag
argument_list|()
specifier|const
block|{
return|return
name|IsScopedUsingClassTag
return|;
block|}
end_expr_stmt

begin_comment
comment|/// \brief Returns true if this is a C++0x enumeration with fixed underlying
end_comment

begin_comment
comment|/// type.
end_comment

begin_expr_stmt
name|bool
name|isFixed
argument_list|()
specifier|const
block|{
return|return
name|IsFixed
return|;
block|}
end_expr_stmt

begin_comment
comment|/// \brief Returns true if this can be considered a complete type.
end_comment

begin_expr_stmt
name|bool
name|isComplete
argument_list|()
specifier|const
block|{
return|return
name|isDefinition
argument_list|()
operator|||
name|isFixed
argument_list|()
return|;
block|}
end_expr_stmt

begin_comment
comment|/// \brief Returns the enumeration (declared within the template)
end_comment

begin_comment
comment|/// from which this enumeration type was instantiated, or NULL if
end_comment

begin_comment
comment|/// this enumeration was not instantiated from any template.
end_comment

begin_expr_stmt
name|EnumDecl
operator|*
name|getInstantiatedFromMemberEnum
argument_list|()
specifier|const
block|{
return|return
name|InstantiatedFrom
return|;
block|}
end_expr_stmt

begin_function
name|void
name|setInstantiationOfMemberEnum
parameter_list|(
name|EnumDecl
modifier|*
name|IF
parameter_list|)
block|{
name|InstantiatedFrom
operator|=
name|IF
expr_stmt|;
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
name|EnumDecl
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
name|Enum
return|;
block|}
end_function

begin_decl_stmt
name|friend
name|class
name|ASTDeclReader
decl_stmt|;
end_decl_stmt

begin_comment
unit|};
comment|/// RecordDecl - Represents a struct/union/class.  For example:
end_comment

begin_comment
comment|///   struct X;                  // Forward declaration, no "body".
end_comment

begin_comment
comment|///   union Y { int A, B; };     // Has body with members A and B (FieldDecls).
end_comment

begin_comment
comment|/// This decl will be marked invalid if *any* members are invalid.
end_comment

begin_comment
comment|///
end_comment

begin_decl_stmt
name|class
name|RecordDecl
range|:
name|public
name|TagDecl
block|{
comment|// FIXME: This can be packed into the bitfields in Decl.
comment|/// HasFlexibleArrayMember - This is true if this struct ends with a flexible
comment|/// array member (e.g. int X[]) or if this union contains a struct that does.
comment|/// If so, this cannot be contained in arrays or other structs as a member.
name|bool
name|HasFlexibleArrayMember
operator|:
literal|1
block|;
comment|/// AnonymousStructOrUnion - Whether this is the type of an anonymous struct
comment|/// or union.
name|bool
name|AnonymousStructOrUnion
operator|:
literal|1
block|;
comment|/// HasObjectMember - This is true if this struct has at least one member
comment|/// containing an object.
name|bool
name|HasObjectMember
operator|:
literal|1
block|;
comment|/// \brief Whether the field declarations of this record have been loaded
comment|/// from external storage. To avoid unnecessary deserialization of
comment|/// methods/nested types we allow deserialization of just the fields
comment|/// when needed.
name|mutable
name|bool
name|LoadedFieldsFromExternalStorage
operator|:
literal|1
block|;
name|friend
name|class
name|DeclContext
block|;
name|protected
operator|:
name|RecordDecl
argument_list|(
argument|Kind DK
argument_list|,
argument|TagKind TK
argument_list|,
argument|DeclContext *DC
argument_list|,
argument|SourceLocation L
argument_list|,
argument|IdentifierInfo *Id
argument_list|,
argument|RecordDecl *PrevDecl
argument_list|,
argument|SourceLocation TKL
argument_list|)
block|;
name|public
operator|:
specifier|static
name|RecordDecl
operator|*
name|Create
argument_list|(
argument|const ASTContext&C
argument_list|,
argument|TagKind TK
argument_list|,
argument|DeclContext *DC
argument_list|,
argument|SourceLocation L
argument_list|,
argument|IdentifierInfo *Id
argument_list|,
argument|SourceLocation TKL = SourceLocation()
argument_list|,
argument|RecordDecl* PrevDecl =
literal|0
argument_list|)
block|;
specifier|static
name|RecordDecl
operator|*
name|Create
argument_list|(
argument|const ASTContext&C
argument_list|,
argument|EmptyShell Empty
argument_list|)
block|;
specifier|const
name|RecordDecl
operator|*
name|getPreviousDeclaration
argument_list|()
specifier|const
block|{
return|return
name|cast_or_null
operator|<
name|RecordDecl
operator|>
operator|(
name|TagDecl
operator|::
name|getPreviousDeclaration
argument_list|()
operator|)
return|;
block|}
name|RecordDecl
operator|*
name|getPreviousDeclaration
argument_list|()
block|{
return|return
name|cast_or_null
operator|<
name|RecordDecl
operator|>
operator|(
name|TagDecl
operator|::
name|getPreviousDeclaration
argument_list|()
operator|)
return|;
block|}
name|bool
name|hasFlexibleArrayMember
argument_list|()
specifier|const
block|{
return|return
name|HasFlexibleArrayMember
return|;
block|}
name|void
name|setHasFlexibleArrayMember
argument_list|(
argument|bool V
argument_list|)
block|{
name|HasFlexibleArrayMember
operator|=
name|V
block|; }
comment|/// isAnonymousStructOrUnion - Whether this is an anonymous struct
comment|/// or union. To be an anonymous struct or union, it must have been
comment|/// declared without a name and there must be no objects of this
comment|/// type declared, e.g.,
comment|/// @code
comment|///   union { int i; float f; };
comment|/// @endcode
comment|/// is an anonymous union but neither of the following are:
comment|/// @code
comment|///  union X { int i; float f; };
comment|///  union { int i; float f; } obj;
comment|/// @endcode
name|bool
name|isAnonymousStructOrUnion
argument_list|()
specifier|const
block|{
return|return
name|AnonymousStructOrUnion
return|;
block|}
name|void
name|setAnonymousStructOrUnion
argument_list|(
argument|bool Anon
argument_list|)
block|{
name|AnonymousStructOrUnion
operator|=
name|Anon
block|;   }
name|bool
name|hasObjectMember
argument_list|()
specifier|const
block|{
return|return
name|HasObjectMember
return|;
block|}
name|void
name|setHasObjectMember
argument_list|(
argument|bool val
argument_list|)
block|{
name|HasObjectMember
operator|=
name|val
block|; }
comment|/// \brief Determines whether this declaration represents the
comment|/// injected class name.
comment|///
comment|/// The injected class name in C++ is the name of the class that
comment|/// appears inside the class itself. For example:
comment|///
comment|/// \code
comment|/// struct C {
comment|///   // C is implicitly declared here as a synonym for the class name.
comment|/// };
comment|///
comment|/// C::C c; // same as "C c;"
comment|/// \endcode
name|bool
name|isInjectedClassName
argument_list|()
specifier|const
block|;
comment|/// getDefinition - Returns the RecordDecl that actually defines this
comment|///  struct/union/class.  When determining whether or not a struct/union/class
comment|///  is completely defined, one should use this method as opposed to
comment|///  'isDefinition'.  'isDefinition' indicates whether or not a specific
comment|///  RecordDecl is defining declaration, not whether or not the record
comment|///  type is defined.  This method returns NULL if there is no RecordDecl
comment|///  that defines the struct/union/tag.
name|RecordDecl
operator|*
name|getDefinition
argument_list|()
specifier|const
block|{
return|return
name|cast_or_null
operator|<
name|RecordDecl
operator|>
operator|(
name|TagDecl
operator|::
name|getDefinition
argument_list|()
operator|)
return|;
block|}
comment|// Iterator access to field members. The field iterator only visits
comment|// the non-static data members of this class, ignoring any static
comment|// data members, functions, constructors, destructors, etc.
typedef|typedef
name|specific_decl_iterator
operator|<
name|FieldDecl
operator|>
name|field_iterator
expr_stmt|;
name|field_iterator
name|field_begin
argument_list|()
specifier|const
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|field_iterator
name|field_end
argument_list|()
specifier|const
block|{
return|return
name|field_iterator
argument_list|(
name|decl_iterator
argument_list|()
argument_list|)
return|;
block|}
end_expr_stmt

begin_comment
comment|// field_empty - Whether there are any fields (non-static data
end_comment

begin_comment
comment|// members) in this record.
end_comment

begin_expr_stmt
name|bool
name|field_empty
argument_list|()
specifier|const
block|{
return|return
name|field_begin
argument_list|()
operator|==
name|field_end
argument_list|()
return|;
block|}
end_expr_stmt

begin_comment
comment|/// completeDefinition - Notes that the definition of this type is
end_comment

begin_comment
comment|/// now complete.
end_comment

begin_function_decl
name|virtual
name|void
name|completeDefinition
parameter_list|()
function_decl|;
end_function_decl

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
name|RecordDecl
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
name|firstRecord
operator|&&
name|K
operator|<=
name|lastRecord
return|;
block|}
end_function

begin_label
name|private
label|:
end_label

begin_comment
comment|/// \brief Deserialize just the fields.
end_comment

begin_expr_stmt
name|void
name|LoadFieldsFromExternalStorage
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt

begin_decl_stmt
unit|};
name|class
name|FileScopeAsmDecl
range|:
name|public
name|Decl
block|{
name|StringLiteral
operator|*
name|AsmString
block|;
name|FileScopeAsmDecl
argument_list|(
argument|DeclContext *DC
argument_list|,
argument|SourceLocation L
argument_list|,
argument|StringLiteral *asmstring
argument_list|)
operator|:
name|Decl
argument_list|(
name|FileScopeAsm
argument_list|,
name|DC
argument_list|,
name|L
argument_list|)
block|,
name|AsmString
argument_list|(
argument|asmstring
argument_list|)
block|{}
name|public
operator|:
specifier|static
name|FileScopeAsmDecl
operator|*
name|Create
argument_list|(
argument|ASTContext&C
argument_list|,
argument|DeclContext *DC
argument_list|,
argument|SourceLocation L
argument_list|,
argument|StringLiteral *Str
argument_list|)
block|;
specifier|const
name|StringLiteral
operator|*
name|getAsmString
argument_list|()
specifier|const
block|{
return|return
name|AsmString
return|;
block|}
name|StringLiteral
operator|*
name|getAsmString
argument_list|()
block|{
return|return
name|AsmString
return|;
block|}
name|void
name|setAsmString
argument_list|(
argument|StringLiteral *Asm
argument_list|)
block|{
name|AsmString
operator|=
name|Asm
block|; }
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
argument|const FileScopeAsmDecl *D
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
name|FileScopeAsm
return|;
block|}
expr|}
block|;
comment|/// BlockDecl - This represents a block literal declaration, which is like an
comment|/// unnamed FunctionDecl.  For example:
comment|/// ^{ statement-body }   or   ^(int arg1, float arg2){ statement-body }
comment|///
name|class
name|BlockDecl
operator|:
name|public
name|Decl
block|,
name|public
name|DeclContext
block|{
name|public
operator|:
comment|/// A class which contains all the information about a particular
comment|/// captured value.
name|class
name|Capture
block|{     enum
block|{
name|flag_isByRef
operator|=
literal|0x1
block|,
name|flag_isNested
operator|=
literal|0x2
block|}
block|;
comment|/// The variable being captured.
name|llvm
operator|::
name|PointerIntPair
operator|<
name|VarDecl
operator|*
block|,
literal|2
operator|>
name|VariableAndFlags
block|;
comment|/// The copy expression, expressed in terms of a DeclRef (or
comment|/// BlockDeclRef) to the captured variable.  Only required if the
comment|/// variable has a C++ class type.
name|Expr
operator|*
name|CopyExpr
block|;
name|public
operator|:
name|Capture
argument_list|(
argument|VarDecl *variable
argument_list|,
argument|bool byRef
argument_list|,
argument|bool nested
argument_list|,
argument|Expr *copy
argument_list|)
operator|:
name|VariableAndFlags
argument_list|(
name|variable
argument_list|,
operator|(
name|byRef
condition|?
name|flag_isByRef
else|:
literal|0
operator|)
operator||
operator|(
name|nested
condition|?
name|flag_isNested
else|:
literal|0
operator|)
argument_list|)
block|,
name|CopyExpr
argument_list|(
argument|copy
argument_list|)
block|{}
comment|/// The variable being captured.
name|VarDecl
operator|*
name|getVariable
argument_list|()
specifier|const
block|{
return|return
name|VariableAndFlags
operator|.
name|getPointer
argument_list|()
return|;
block|}
comment|/// Whether this is a "by ref" capture, i.e. a capture of a __block
comment|/// variable.
name|bool
name|isByRef
argument_list|()
specifier|const
block|{
return|return
name|VariableAndFlags
operator|.
name|getInt
argument_list|()
operator|&
name|flag_isByRef
return|;
block|}
comment|/// Whether this is a nested capture, i.e. the variable captured
comment|/// is not from outside the immediately enclosing function/block.
name|bool
name|isNested
argument_list|()
specifier|const
block|{
return|return
name|VariableAndFlags
operator|.
name|getInt
argument_list|()
operator|&
name|flag_isNested
return|;
block|}
name|bool
name|hasCopyExpr
argument_list|()
specifier|const
block|{
return|return
name|CopyExpr
operator|!=
literal|0
return|;
block|}
name|Expr
operator|*
name|getCopyExpr
argument_list|()
specifier|const
block|{
return|return
name|CopyExpr
return|;
block|}
name|void
name|setCopyExpr
argument_list|(
argument|Expr *e
argument_list|)
block|{
name|CopyExpr
operator|=
name|e
block|; }
expr|}
block|;
name|private
operator|:
comment|// FIXME: This can be packed into the bitfields in Decl.
name|bool
name|IsVariadic
operator|:
literal|1
block|;
name|bool
name|CapturesCXXThis
operator|:
literal|1
block|;
comment|/// ParamInfo - new[]'d array of pointers to ParmVarDecls for the formal
comment|/// parameters of this function.  This is null if a prototype or if there are
comment|/// no formals.
name|ParmVarDecl
operator|*
operator|*
name|ParamInfo
block|;
name|unsigned
name|NumParams
block|;
name|Stmt
operator|*
name|Body
block|;
name|TypeSourceInfo
operator|*
name|SignatureAsWritten
block|;
name|Capture
operator|*
name|Captures
block|;
name|unsigned
name|NumCaptures
block|;
name|protected
operator|:
name|BlockDecl
argument_list|(
argument|DeclContext *DC
argument_list|,
argument|SourceLocation CaretLoc
argument_list|)
operator|:
name|Decl
argument_list|(
name|Block
argument_list|,
name|DC
argument_list|,
name|CaretLoc
argument_list|)
block|,
name|DeclContext
argument_list|(
name|Block
argument_list|)
block|,
name|IsVariadic
argument_list|(
name|false
argument_list|)
block|,
name|CapturesCXXThis
argument_list|(
name|false
argument_list|)
block|,
name|ParamInfo
argument_list|(
literal|0
argument_list|)
block|,
name|NumParams
argument_list|(
literal|0
argument_list|)
block|,
name|Body
argument_list|(
literal|0
argument_list|)
block|,
name|SignatureAsWritten
argument_list|(
literal|0
argument_list|)
block|,
name|Captures
argument_list|(
literal|0
argument_list|)
block|,
name|NumCaptures
argument_list|(
literal|0
argument_list|)
block|{}
name|public
operator|:
specifier|static
name|BlockDecl
operator|*
name|Create
argument_list|(
argument|ASTContext&C
argument_list|,
argument|DeclContext *DC
argument_list|,
argument|SourceLocation L
argument_list|)
block|;
name|SourceLocation
name|getCaretLocation
argument_list|()
specifier|const
block|{
return|return
name|getLocation
argument_list|()
return|;
block|}
name|bool
name|isVariadic
argument_list|()
specifier|const
block|{
return|return
name|IsVariadic
return|;
block|}
name|void
name|setIsVariadic
argument_list|(
argument|bool value
argument_list|)
block|{
name|IsVariadic
operator|=
name|value
block|; }
name|CompoundStmt
operator|*
name|getCompoundBody
argument_list|()
specifier|const
block|{
return|return
operator|(
name|CompoundStmt
operator|*
operator|)
name|Body
return|;
block|}
name|Stmt
operator|*
name|getBody
argument_list|()
specifier|const
block|{
return|return
operator|(
name|Stmt
operator|*
operator|)
name|Body
return|;
block|}
name|void
name|setBody
argument_list|(
argument|CompoundStmt *B
argument_list|)
block|{
name|Body
operator|=
operator|(
name|Stmt
operator|*
operator|)
name|B
block|; }
name|void
name|setSignatureAsWritten
argument_list|(
argument|TypeSourceInfo *Sig
argument_list|)
block|{
name|SignatureAsWritten
operator|=
name|Sig
block|; }
name|TypeSourceInfo
operator|*
name|getSignatureAsWritten
argument_list|()
specifier|const
block|{
return|return
name|SignatureAsWritten
return|;
block|}
comment|// Iterator access to formal parameters.
name|unsigned
name|param_size
argument_list|()
specifier|const
block|{
return|return
name|getNumParams
argument_list|()
return|;
block|}
typedef|typedef
name|ParmVarDecl
modifier|*
modifier|*
name|param_iterator
typedef|;
typedef|typedef
name|ParmVarDecl
modifier|*
specifier|const
modifier|*
name|param_const_iterator
typedef|;
name|bool
name|param_empty
argument_list|()
specifier|const
block|{
return|return
name|NumParams
operator|==
literal|0
return|;
block|}
name|param_iterator
name|param_begin
argument_list|()
block|{
return|return
name|ParamInfo
return|;
block|}
name|param_iterator
name|param_end
argument_list|()
block|{
return|return
name|ParamInfo
operator|+
name|param_size
argument_list|()
return|;
block|}
name|param_const_iterator
name|param_begin
argument_list|()
specifier|const
block|{
return|return
name|ParamInfo
return|;
block|}
name|param_const_iterator
name|param_end
argument_list|()
specifier|const
block|{
return|return
name|ParamInfo
operator|+
name|param_size
argument_list|()
return|;
block|}
name|unsigned
name|getNumParams
argument_list|()
specifier|const
block|{
return|return
name|NumParams
return|;
block|}
specifier|const
name|ParmVarDecl
operator|*
name|getParamDecl
argument_list|(
argument|unsigned i
argument_list|)
specifier|const
block|{
name|assert
argument_list|(
name|i
operator|<
name|getNumParams
argument_list|()
operator|&&
literal|"Illegal param #"
argument_list|)
block|;
return|return
name|ParamInfo
index|[
name|i
index|]
return|;
block|}
name|ParmVarDecl
operator|*
name|getParamDecl
argument_list|(
argument|unsigned i
argument_list|)
block|{
name|assert
argument_list|(
name|i
operator|<
name|getNumParams
argument_list|()
operator|&&
literal|"Illegal param #"
argument_list|)
block|;
return|return
name|ParamInfo
index|[
name|i
index|]
return|;
block|}
name|void
name|setParams
argument_list|(
argument|ParmVarDecl **NewParamInfo
argument_list|,
argument|unsigned NumParams
argument_list|)
block|;
comment|/// hasCaptures - True if this block (or its nested blocks) captures
comment|/// anything of local storage from its enclosing scopes.
name|bool
name|hasCaptures
argument_list|()
specifier|const
block|{
return|return
name|NumCaptures
operator|!=
literal|0
operator|||
name|CapturesCXXThis
return|;
block|}
comment|/// getNumCaptures - Returns the number of captured variables.
comment|/// Does not include an entry for 'this'.
name|unsigned
name|getNumCaptures
argument_list|()
specifier|const
block|{
return|return
name|NumCaptures
return|;
block|}
typedef|typedef
specifier|const
name|Capture
modifier|*
name|capture_iterator
typedef|;
end_decl_stmt

begin_typedef
typedef|typedef
specifier|const
name|Capture
modifier|*
name|capture_const_iterator
typedef|;
end_typedef

begin_function
name|capture_iterator
name|capture_begin
parameter_list|()
block|{
return|return
name|Captures
return|;
block|}
end_function

begin_function
name|capture_iterator
name|capture_end
parameter_list|()
block|{
return|return
name|Captures
operator|+
name|NumCaptures
return|;
block|}
end_function

begin_expr_stmt
name|capture_const_iterator
name|capture_begin
argument_list|()
specifier|const
block|{
return|return
name|Captures
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|capture_const_iterator
name|capture_end
argument_list|()
specifier|const
block|{
return|return
name|Captures
operator|+
name|NumCaptures
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|bool
name|capturesCXXThis
argument_list|()
specifier|const
block|{
return|return
name|CapturesCXXThis
return|;
block|}
end_expr_stmt

begin_function_decl
name|void
name|setCaptures
parameter_list|(
name|ASTContext
modifier|&
name|Context
parameter_list|,
specifier|const
name|Capture
modifier|*
name|begin
parameter_list|,
specifier|const
name|Capture
modifier|*
name|end
parameter_list|,
name|bool
name|capturesCXXThis
parameter_list|)
function_decl|;
end_function_decl

begin_expr_stmt
name|virtual
name|SourceRange
name|getSourceRange
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
name|BlockDecl
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
name|Block
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
name|BlockDecl
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
name|BlockDecl
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
name|BlockDecl
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
name|BlockDecl
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
comment|/// Insertion operator for diagnostics.  This allows sending NamedDecl's
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
name|NamedDecl
operator|*
name|ND
operator|)
block|{
name|DB
operator|.
name|AddTaggedVal
argument_list|(
name|reinterpret_cast
operator|<
name|intptr_t
operator|>
operator|(
name|ND
operator|)
argument_list|,
name|Diagnostic
operator|::
name|ak_nameddecl
argument_list|)
block|;
return|return
name|DB
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|template
operator|<
name|typename
name|decl_type
operator|>
name|void
name|Redeclarable
operator|<
name|decl_type
operator|>
operator|::
name|setPreviousDeclaration
argument_list|(
argument|decl_type *PrevDecl
argument_list|)
block|{
comment|// Note: This routine is implemented here because we need both NamedDecl
comment|// and Redeclarable to be defined.
name|decl_type
operator|*
name|First
block|;
if|if
condition|(
name|PrevDecl
condition|)
block|{
comment|// Point to previous. Make sure that this is actually the most recent
comment|// redeclaration, or we can build invalid chains. If the most recent
comment|// redeclaration is invalid, it won't be PrevDecl, but we want it anyway.
name|RedeclLink
operator|=
name|PreviousDeclLink
argument_list|(
name|llvm
operator|::
name|cast
operator|<
name|decl_type
operator|>
operator|(
name|PrevDecl
operator|->
name|getMostRecentDeclaration
argument_list|()
operator|)
argument_list|)
expr_stmt|;
name|First
operator|=
name|PrevDecl
operator|->
name|getFirstDeclaration
argument_list|()
expr_stmt|;
name|assert
argument_list|(
name|First
operator|->
name|RedeclLink
operator|.
name|NextIsLatest
argument_list|()
operator|&&
literal|"Expected first"
argument_list|)
expr_stmt|;
block|}
end_expr_stmt

begin_else
else|else
block|{
comment|// Make this first.
name|First
operator|=
name|static_cast
operator|<
name|decl_type
operator|*
operator|>
operator|(
name|this
operator|)
expr_stmt|;
block|}
end_else

begin_comment
comment|// First one will point to this one as latest.
end_comment

begin_expr_stmt
name|First
operator|->
name|RedeclLink
operator|=
name|LatestDeclLink
argument_list|(
name|static_cast
operator|<
name|decl_type
operator|*
operator|>
operator|(
name|this
operator|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_if
if|if
condition|(
name|NamedDecl
modifier|*
name|ND
init|=
name|dyn_cast
operator|<
name|NamedDecl
operator|>
operator|(
name|static_cast
operator|<
name|decl_type
operator|*
operator|>
operator|(
name|this
operator|)
operator|)
condition|)
name|ND
operator|->
name|ClearLinkageCache
argument_list|()
expr_stmt|;
end_if

begin_comment
unit|}  }
comment|// end namespace clang
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

