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
comment|/// getNameAsCString - Get the name of identifier for this declaration as a
comment|/// C string (const char*).  This requires that the declaration have a name
comment|/// and that it be a simple identifier.
comment|//
comment|// FIXME: Deprecated, move clients to getName().
specifier|const
name|char
operator|*
name|getNameAsCString
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
name|getNameStart
argument_list|()
else|:
literal|""
return|;
block|}
comment|/// getNameAsString - Get a human-readable name for the declaration, even if
comment|/// it is one of the special kinds of names (C++ constructor, Objective-C
comment|/// selector, etc).  Creating this name requires expensive string
comment|/// manipulation, so it should be called only when performance doesn't matter.
comment|/// For simple declarations, getNameAsCString() should suffice.
comment|//
comment|// FIXME: This function should be renamed to indicate that it is not just an
comment|// alternate form of getName(), and clients should move as appropriate.
comment|//
comment|// FIXME: Deprecated, move clients to getName().
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
comment|/// getDeclName - Get the actual, stored name of the declaration,
comment|/// which may be a special name.
name|DeclarationName
name|getDeclName
argument_list|()
specifier|const
block|{
return|return
name|Name
return|;
block|}
comment|/// \brief Set the name of this declaration.
name|void
name|setDeclName
argument_list|(
argument|DeclarationName N
argument_list|)
block|{
name|Name
operator|=
name|N
block|; }
comment|/// getQualifiedNameAsString - Returns human-readable qualified name for
comment|/// declaration, like A::B::i, for i being member of namespace A::B.
comment|/// If declaration is not member of context which can be named (record,
comment|/// namespace), it will return same result as getNameAsString().
comment|/// Creating this name is expensive, so it should be called only when
comment|/// performance doesn't matter.
name|std
operator|::
name|string
name|getQualifiedNameAsString
argument_list|()
specifier|const
block|;
name|std
operator|::
name|string
name|getQualifiedNameAsString
argument_list|(
argument|const PrintingPolicy&Policy
argument_list|)
specifier|const
block|;
comment|/// getNameForDiagnostic - Appends a human-readable name for this
comment|/// declaration into the given string.
comment|///
comment|/// This is the method invoked by Sema when displaying a NamedDecl
comment|/// in a diagnostic.  It does not necessarily produce the same
comment|/// result as getNameAsString(); for example, class template
comment|/// specializations are printed with their template arguments.
comment|///
comment|/// TODO: use an API that doesn't require so many temporary strings
name|virtual
name|void
name|getNameForDiagnostic
argument_list|(
argument|std::string&S
argument_list|,
argument|const PrintingPolicy&Policy
argument_list|,
argument|bool Qualified
argument_list|)
specifier|const
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
comment|/// declarationReplaces - Determine whether this declaration, if
comment|/// known to be well-formed within its context, will replace the
comment|/// declaration OldD if introduced into scope. A declaration will
comment|/// replace another declaration if, for example, it is a
comment|/// redeclaration of the same variable or function, but not if it is
comment|/// a declaration of a different kind (function vs. class) or an
comment|/// overloaded function.
name|bool
name|declarationReplaces
argument_list|(
argument|NamedDecl *OldD
argument_list|)
specifier|const
block|;
comment|/// \brief Determine whether this declaration has linkage.
name|bool
name|hasLinkage
argument_list|()
specifier|const
block|;
comment|/// \brief Determine whether this declaration is a C++ class member.
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
return|return
name|DC
operator|->
name|isRecord
argument_list|()
return|;
block|}
comment|/// \brief Given that this declaration is a C++ class member,
comment|/// determine whether it's an instance member of its class.
name|bool
name|isCXXInstanceMember
argument_list|()
specifier|const
expr_stmt|;
comment|/// \brief Determine what kind of linkage this entity has.
name|Linkage
name|getLinkage
argument_list|()
specifier|const
expr_stmt|;
comment|/// \brief Looks through UsingDecls and ObjCCompatibleAliasDecls for
comment|/// the underlying named decl.
name|NamedDecl
modifier|*
name|getUnderlyingDecl
parameter_list|()
function_decl|;
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
name|NamedDecl
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
name|NamedFirst
operator|&&
name|K
operator|<=
name|NamedLast
return|;
block|}
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_expr_stmt
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
comment|/// NamespaceDecl - Represent a C++ namespace.
end_comment

begin_decl_stmt
name|class
name|NamespaceDecl
range|:
name|public
name|NamedDecl
decl_stmt|,
name|public
name|DeclContext
block|{
name|SourceLocation
name|LBracLoc
decl_stmt|,
name|RBracLoc
decl_stmt|;
comment|// For extended namespace definitions:
comment|//
comment|// namespace A { int x; }
comment|// namespace A { int y; }
comment|//
comment|// there will be one NamespaceDecl for each declaration.
comment|// NextNamespace points to the next extended declaration.
comment|// OrigNamespace points to the original namespace declaration.
comment|// OrigNamespace of the first namespace decl points to itself.
name|NamespaceDecl
modifier|*
name|NextNamespace
decl_stmt|;
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
operator|,
literal|1
operator|,
name|bool
operator|>
name|OrigOrAnonNamespace
expr_stmt|;
name|NamespaceDecl
argument_list|(
argument|DeclContext *DC
argument_list|,
argument|SourceLocation L
argument_list|,
argument|IdentifierInfo *Id
argument_list|)
block|:
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
operator|,
name|DeclContext
argument_list|(
name|Namespace
argument_list|)
operator|,
name|NextNamespace
argument_list|(
literal|0
argument_list|)
operator|,
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
expr_stmt|;
name|virtual
name|void
name|Destroy
parameter_list|(
name|ASTContext
modifier|&
name|C
parameter_list|)
function_decl|;
comment|// \brief Returns true if this is an anonymous namespace declaration.
comment|//
comment|// For example:
comment|//   namespace {
comment|//     ...
comment|//   };
comment|// q.v. C++ [namespace.unnamed]
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
name|NamespaceDecl
modifier|*
name|getNextNamespace
parameter_list|()
block|{
return|return
name|NextNamespace
return|;
block|}
specifier|const
name|NamespaceDecl
operator|*
name|getNextNamespace
argument_list|()
specifier|const
block|{
return|return
name|NextNamespace
return|;
block|}
name|void
name|setNextNamespace
parameter_list|(
name|NamespaceDecl
modifier|*
name|ND
parameter_list|)
block|{
name|NextNamespace
operator|=
name|ND
expr_stmt|;
block|}
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
end_decl_stmt

begin_function
name|void
name|setOriginalNamespace
parameter_list|(
name|NamespaceDecl
modifier|*
name|ND
parameter_list|)
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
end_function

begin_expr_stmt
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
end_expr_stmt

begin_function
name|void
name|setAnonymousNamespace
parameter_list|(
name|NamespaceDecl
modifier|*
name|D
parameter_list|)
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
expr_stmt|;
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
expr_stmt|;
name|getOriginalNamespace
argument_list|()
operator|->
name|OrigOrAnonNamespace
operator|.
name|setPointer
argument_list|(
name|D
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
name|virtual
name|NamespaceDecl
modifier|*
name|getCanonicalDecl
parameter_list|()
block|{
return|return
name|getOriginalNamespace
argument_list|()
return|;
block|}
end_function

begin_expr_stmt
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
end_expr_stmt

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
name|getLocation
argument_list|()
argument_list|,
name|RBracLoc
argument_list|)
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|SourceLocation
name|getLBracLoc
argument_list|()
specifier|const
block|{
return|return
name|LBracLoc
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|SourceLocation
name|getRBracLoc
argument_list|()
specifier|const
block|{
return|return
name|RBracLoc
return|;
block|}
end_expr_stmt

begin_function
name|void
name|setLBracLoc
parameter_list|(
name|SourceLocation
name|LBrace
parameter_list|)
block|{
name|LBracLoc
operator|=
name|LBrace
expr_stmt|;
block|}
end_function

begin_function
name|void
name|setRBracLoc
parameter_list|(
name|SourceLocation
name|RBrace
parameter_list|)
block|{
name|RBracLoc
operator|=
name|RBrace
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
name|NamespaceDecl
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
name|Namespace
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
name|NamespaceDecl
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
name|NamespaceDecl
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
name|NamespaceDecl
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
end_function

begin_comment
unit|};
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
name|ValueFirst
operator|&&
name|K
operator|<=
name|ValueLast
return|;
block|}
expr|}
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
block|{
name|TypeSourceInfo
operator|*
name|TInfo
block|;
name|NestedNameSpecifier
operator|*
name|NNS
block|;
name|SourceRange
name|NNSRange
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
name|virtual
operator|~
name|DeclaratorDecl
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
name|DeclInfo
operator|.
name|get
operator|<
name|ExtInfo
operator|*
operator|>
operator|(
operator|)
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
name|DeclInfo
operator|.
name|get
operator|<
name|ExtInfo
operator|*
operator|>
operator|(
operator|)
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
name|DeclInfo
operator|.
name|get
operator|<
name|ExtInfo
operator|*
operator|>
operator|(
operator|)
operator|->
name|NNS
operator|:
literal|0
return|;
block|}
name|SourceRange
name|getQualifierRange
argument_list|()
specifier|const
block|{
return|return
name|hasExtInfo
argument_list|()
condition|?
name|DeclInfo
operator|.
name|get
operator|<
name|ExtInfo
operator|*
operator|>
operator|(
operator|)
operator|->
name|NNSRange
else|:
name|SourceRange
argument_list|()
return|;
block|}
name|void
name|setQualifierInfo
argument_list|(
argument|NestedNameSpecifier *Qualifier
argument_list|,
argument|SourceRange QualifierRange
argument_list|)
block|;
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
name|DeclaratorFirst
operator|&&
name|K
operator|<=
name|DeclaratorLast
return|;
block|}
expr|}
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
comment|// \brief Describes the kind of template specialization that a
comment|// particular template specialization declaration represents.
block|enum
name|TemplateSpecializationKind
block|{
comment|/// This template specialization was formed from a template-id but
comment|/// has not yet been declared, defined, or instantiated.
name|TSK_Undeclared
operator|=
literal|0
block|,
comment|/// This template specialization was implicitly instantiated from a
comment|/// template. (C++ [temp.inst]).
name|TSK_ImplicitInstantiation
block|,
comment|/// This template specialization was declared or defined by an
comment|/// explicit specialization (C++ [temp.expl.spec]) or partial
comment|/// specialization (C++ [temp.class.spec]).
name|TSK_ExplicitSpecialization
block|,
comment|/// This template specialization was instantiated from a template
comment|/// due to an explicit instantiation declaration request
comment|/// (C++0x [temp.explicit]).
name|TSK_ExplicitInstantiationDeclaration
block|,
comment|/// This template specialization was instantiated from a template
comment|/// due to an explicit instantiation definition request
comment|/// (C++ [temp.explicit]).
name|TSK_ExplicitInstantiationDefinition
block|}
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
expr|enum
name|StorageClass
block|{
name|None
block|,
name|Auto
block|,
name|Register
block|,
name|Extern
block|,
name|Static
block|,
name|PrivateExtern
block|}
block|;
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
block|;
name|private
operator|:
comment|// FIXME: This can be packed into the bitfields in Decl.
name|unsigned
name|SClass
operator|:
literal|3
block|;
name|unsigned
name|SClassAsWritten
operator|:
literal|3
block|;
name|bool
name|ThreadSpecified
operator|:
literal|1
block|;
name|bool
name|HasCXXDirectInit
operator|:
literal|1
block|;
comment|/// DeclaredInCondition - Whether this variable was declared in a
comment|/// condition, e.g., if (int x = foo()) { ... }.
name|bool
name|DeclaredInCondition
operator|:
literal|1
block|;
comment|/// \brief Whether this variable is the exception variable in a C++ catch
comment|/// or an Objective-C @catch statement.
name|bool
name|ExceptionVar
operator|:
literal|1
block|;
name|friend
name|class
name|StmtIteratorBase
block|;
name|protected
operator|:
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
name|Init
argument_list|()
block|,
name|ThreadSpecified
argument_list|(
name|false
argument_list|)
block|,
name|HasCXXDirectInit
argument_list|(
name|false
argument_list|)
block|,
name|DeclaredInCondition
argument_list|(
name|false
argument_list|)
block|,
name|ExceptionVar
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
typedef|typedef
name|Redeclarable
operator|<
name|VarDecl
operator|>
name|redeclarable_base
expr_stmt|;
name|virtual
name|VarDecl
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
name|VarDecl
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
argument_list|)
decl_stmt|;
end_decl_stmt

begin_function_decl
name|virtual
name|void
name|Destroy
parameter_list|(
name|ASTContext
modifier|&
name|C
parameter_list|)
function_decl|;
end_function_decl

begin_expr_stmt
name|virtual
operator|~
name|VarDecl
argument_list|()
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

begin_function
name|void
name|setStorageClass
parameter_list|(
name|StorageClass
name|SC
parameter_list|)
block|{
name|SClass
operator|=
name|SC
expr_stmt|;
block|}
end_function

begin_function
name|void
name|setStorageClassAsWritten
parameter_list|(
name|StorageClass
name|SC
parameter_list|)
block|{
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
name|None
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
operator|<=
name|Register
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
name|Static
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
name|Extern
operator|||
name|getStorageClass
argument_list|()
operator|==
name|PrivateExtern
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
comment|/// isBlockVarDecl - Returns true for local variable declarations.  Note that
end_comment

begin_comment
comment|/// this includes static variables inside of functions. It also includes
end_comment

begin_comment
comment|/// variables inside blocks.
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
name|isBlockVarDecl
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
name|getLookupContext
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
comment|/// isFunctionOrMethodVarDecl - Similar to isBlockVarDecl, but excludes
end_comment

begin_comment
comment|/// variables declared in blocks.
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
name|getLookupContext
argument_list|()
operator|->
name|isFunctionOrMethod
argument_list|()
operator|&&
name|DC
operator|->
name|getLookupContext
argument_list|()
operator|->
name|getDeclKind
argument_list|()
operator|!=
name|Decl
operator|::
name|Block
return|;
end_if

begin_return
return|return
name|false
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
specifier|const
name|DeclContext
modifier|*
name|Ctx
init|=
name|getDeclContext
argument_list|()
condition|)
block|{
name|Ctx
operator|=
name|Ctx
operator|->
name|getLookupContext
argument_list|()
expr_stmt|;
if|if
condition|(
name|isa
operator|<
name|TranslationUnitDecl
operator|>
operator|(
name|Ctx
operator|)
operator|||
name|isa
operator|<
name|NamespaceDecl
operator|>
operator|(
name|Ctx
operator|)
condition|)
return|return
name|true
return|;
block|}
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
comment|/// isDeclaredInCondition - Whether this variable was declared as
end_comment

begin_comment
comment|/// part of a condition in an if/switch/while statement, e.g.,
end_comment

begin_comment
comment|/// @code
end_comment

begin_comment
comment|/// if (int x = foo()) { ... }
end_comment

begin_comment
comment|/// @endcode
end_comment

begin_expr_stmt
name|bool
name|isDeclaredInCondition
argument_list|()
specifier|const
block|{
return|return
name|DeclaredInCondition
return|;
block|}
end_expr_stmt

begin_function
name|void
name|setDeclaredInCondition
parameter_list|(
name|bool
name|InCondition
parameter_list|)
block|{
name|DeclaredInCondition
operator|=
name|InCondition
expr_stmt|;
block|}
end_function

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
name|VarFirst
operator|&&
name|K
operator|<=
name|VarLast
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
name|protected
operator|:
name|ImplicitParamDecl
argument_list|(
argument|Kind DK
argument_list|,
argument|DeclContext *DC
argument_list|,
argument|SourceLocation L
argument_list|,
argument|IdentifierInfo *Id
argument_list|,
argument|QualType Tw
argument_list|)
operator|:
name|VarDecl
argument_list|(
argument|DK
argument_list|,
argument|DC
argument_list|,
argument|L
argument_list|,
argument|Id
argument_list|,
argument|Tw
argument_list|,
comment|/*TInfo=*/
literal|0
argument_list|,
argument|VarDecl::None
argument_list|,
argument|VarDecl::None
argument_list|)
block|{}
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
expr|enum
name|StorageClass
block|{
name|None
block|,
name|Extern
block|,
name|Static
block|,
name|PrivateExtern
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
name|IsCopyAssignment
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
name|protected
operator|:
name|FunctionDecl
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
argument_list|,
argument|StorageClass S
argument_list|,
argument|StorageClass SCAsWritten
argument_list|,
argument|bool isInline
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
name|N
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
name|isInline
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
name|IsCopyAssignment
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
name|L
argument_list|)
block|,
name|TemplateOrSpecialization
argument_list|()
block|{}
name|virtual
operator|~
name|FunctionDecl
argument_list|()
block|{}
name|virtual
name|void
name|Destroy
argument_list|(
name|ASTContext
operator|&
name|C
argument_list|)
block|;
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
name|FunctionDecl
operator|*
name|Create
argument_list|(
argument|ASTContext&C
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
argument_list|,
argument|StorageClass S = None
argument_list|,
argument|StorageClass SCAsWritten = None
argument_list|,
argument|bool isInline = false
argument_list|,
argument|bool hasWrittenPrototype = true
argument_list|)
decl_stmt|;
end_decl_stmt

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
name|getLocation
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

begin_function
name|void
name|setPure
parameter_list|(
name|bool
name|P
init|=
name|true
parameter_list|)
block|{
name|IsPure
operator|=
name|P
expr_stmt|;
block|}
end_function

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

begin_expr_stmt
name|bool
name|isCopyAssignment
argument_list|()
specifier|const
block|{
return|return
name|IsCopyAssignment
return|;
block|}
end_expr_stmt

begin_function
name|void
name|setCopyAssignment
parameter_list|(
name|bool
name|CA
parameter_list|)
block|{
name|IsCopyAssignment
operator|=
name|CA
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

begin_function
name|void
name|setHasWrittenPrototype
parameter_list|(
name|bool
name|P
parameter_list|)
block|{
name|HasWrittenPrototype
operator|=
name|P
expr_stmt|;
block|}
end_function

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

begin_function_decl
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
function_decl|;
end_function_decl

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

begin_function
name|void
name|setStorageClass
parameter_list|(
name|StorageClass
name|SC
parameter_list|)
block|{
name|SClass
operator|=
name|SC
expr_stmt|;
block|}
end_function

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

begin_function
name|void
name|setStorageClassAsWritten
parameter_list|(
name|StorageClass
name|SC
parameter_list|)
block|{
name|SClassAsWritten
operator|=
name|SC
expr_stmt|;
block|}
end_function

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
name|IsInline
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
name|IsInline
operator|=
name|I
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

begin_function_decl
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
function_decl|;
end_function_decl

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
comment|/// \brief Specify that this function declaration is actually a function
end_comment

begin_comment
comment|/// template specialization.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param Context the AST context in which this function resides.
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

begin_function_decl
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
parameter_list|)
function_decl|;
end_function_decl

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
name|FunctionFirst
operator|&&
name|K
operator|<=
name|FunctionLast
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
argument|Expr *BW
argument_list|,
argument|bool Mutable
argument_list|)
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
name|FieldFirst
operator|&&
name|K
operator|<=
name|FieldLast
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
name|virtual
operator|~
name|EnumConstantDecl
argument_list|()
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
name|virtual
name|void
name|Destroy
argument_list|(
name|ASTContext
operator|&
name|C
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
comment|/// TypeDecl - Represents a declaration of a type.
comment|///
name|class
name|TypeDecl
operator|:
name|public
name|NamedDecl
block|{
comment|/// TypeForDecl - This indicates the Type object that represents
comment|/// this TypeDecl.  It is a cache maintained by
comment|/// ASTContext::getTypedefType, ASTContext::getTagDeclType, and
comment|/// ASTContext::getTemplateTypeParmType, and TemplateTypeParmDecl.
name|mutable
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
argument|Type *TD
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
name|TypeFirst
operator|&&
name|K
operator|<=
name|TypeLast
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
name|virtual
operator|~
name|TypedefDecl
argument_list|()
block|;
name|public
operator|:
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
block|;
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
comment|/// Retrieves the canonical declaration of this typedef.
name|TypedefDecl
operator|*
name|getCanonicalDecl
argument_list|()
block|{
return|return
name|getFirstDeclaration
argument_list|()
return|;
block|}
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
name|void
name|setTypeSourceInfo
argument_list|(
argument|TypeSourceInfo *newType
argument_list|)
block|{
name|TInfo
operator|=
name|newType
block|;   }
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
argument|const TypedefDecl *D
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
name|Typedef
return|;
block|}
expr|}
block|;
name|class
name|TypedefDecl
block|;
comment|/// TagDecl - Represents the declaration of a struct/union/class/enum.
name|class
name|TagDecl
operator|:
name|public
name|TypeDecl
block|,
name|public
name|DeclContext
block|,
name|public
name|Redeclarable
operator|<
name|TagDecl
operator|>
block|{
name|public
operator|:
comment|// This is really ugly.
typedef|typedef
name|ElaboratedType
operator|::
name|TagKind
name|TagKind
expr_stmt|;
specifier|static
specifier|const
name|TagKind
name|TK_struct
operator|=
name|ElaboratedType
operator|::
name|TK_struct
block|;
specifier|static
specifier|const
name|TagKind
name|TK_union
operator|=
name|ElaboratedType
operator|::
name|TK_union
block|;
specifier|static
specifier|const
name|TagKind
name|TK_class
operator|=
name|ElaboratedType
operator|::
name|TK_class
block|;
specifier|static
specifier|const
name|TagKind
name|TK_enum
operator|=
name|ElaboratedType
operator|::
name|TK_enum
block|;
name|private
operator|:
comment|// FIXME: This can be packed into the bitfields in Decl.
comment|/// TagDeclKind - The TagKind enum.
name|unsigned
name|TagDeclKind
operator|:
literal|2
block|;
comment|/// IsDefinition - True if this is a definition ("struct foo {};"), false if
comment|/// it is a declaration ("struct foo;").
name|bool
name|IsDefinition
operator|:
literal|1
block|;
comment|/// IsEmbeddedInDeclarator - True if this tag declaration is
comment|/// "embedded" (i.e., defined or declared for the very first time)
comment|/// in the syntax of a declarator.
name|bool
name|IsEmbeddedInDeclarator
operator|:
literal|1
block|;
name|SourceLocation
name|TagKeywordLoc
block|;
name|SourceLocation
name|RBraceLoc
block|;
comment|// A struct representing syntactic qualifier info,
comment|// to be used for the (uncommon) case of out-of-line declarations.
block|struct
name|ExtInfo
block|{
name|NestedNameSpecifier
operator|*
name|NNS
block|;
name|SourceRange
name|NNSRange
block|;   }
block|;
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
block|,
name|ExtInfo
operator|*
operator|>
name|TypedefDeclOrQualifier
block|;
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
operator|*
name|getExtInfo
argument_list|()
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
operator|:
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
operator|:
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
block|,
name|DeclContext
argument_list|(
name|DK
argument_list|)
block|,
name|TagKeywordLoc
argument_list|(
name|TKL
argument_list|)
block|,
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
name|TK_enum
operator|)
operator|&&
literal|"EnumDecl not matched with TK_enum"
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
name|void
name|Destroy
argument_list|(
name|ASTContext
operator|&
name|C
argument_list|)
block|;
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
argument_list|(
argument|SourceLocation L
argument_list|)
block|{
name|RBraceLoc
operator|=
name|L
block|; }
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
argument_list|(
argument|SourceLocation TKL
argument_list|)
block|{
name|TagKeywordLoc
operator|=
name|TKL
block|; }
name|virtual
name|SourceRange
name|getSourceRange
argument_list|()
specifier|const
block|;
name|virtual
name|TagDecl
operator|*
name|getCanonicalDecl
argument_list|()
block|;
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
argument_list|(
argument|bool isInDeclarator
argument_list|)
block|{
name|IsEmbeddedInDeclarator
operator|=
name|isInDeclarator
block|;   }
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
argument_list|()
block|;
comment|/// @brief Completes the definition of this tag declaration.
name|void
name|completeDefinition
argument_list|()
block|;
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
block|;
name|void
name|setDefinition
argument_list|(
argument|bool V
argument_list|)
block|{
name|IsDefinition
operator|=
name|V
block|; }
specifier|const
name|char
operator|*
name|getKindName
argument_list|()
specifier|const
block|{
return|return
name|ElaboratedType
operator|::
name|getNameForTagKind
argument_list|(
name|getTagKind
argument_list|()
argument_list|)
return|;
block|}
comment|/// getTagKindForTypeSpec - Converts a type specifier (DeclSpec::TST)
comment|/// into a tag kind.  It is an error to provide a type specifier
comment|/// which *isn't* a tag kind here.
specifier|static
name|TagKind
name|getTagKindForTypeSpec
argument_list|(
argument|unsigned TypeSpec
argument_list|)
block|;
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
argument_list|(
argument|TagKind TK
argument_list|)
block|{
name|TagDeclKind
operator|=
name|TK
block|; }
name|bool
name|isStruct
argument_list|()
specifier|const
block|{
return|return
name|getTagKind
argument_list|()
operator|==
name|TK_struct
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
name|TK_class
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
name|TK_union
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
name|TK_enum
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
argument_list|(
argument|TypedefDecl *TDD
argument_list|)
block|{
name|TypedefDeclOrQualifier
operator|=
name|TDD
block|; }
name|NestedNameSpecifier
operator|*
name|getQualifier
argument_list|()
specifier|const
block|{
return|return
name|hasExtInfo
argument_list|()
condition|?
name|TypedefDeclOrQualifier
operator|.
name|get
operator|<
name|ExtInfo
operator|*
operator|>
operator|(
operator|)
operator|->
name|NNS
else|:
literal|0
return|;
block|}
name|SourceRange
name|getQualifierRange
argument_list|()
specifier|const
block|{
return|return
name|hasExtInfo
argument_list|()
condition|?
name|TypedefDeclOrQualifier
operator|.
name|get
operator|<
name|ExtInfo
operator|*
operator|>
operator|(
operator|)
operator|->
name|NNSRange
else|:
name|SourceRange
argument_list|()
return|;
block|}
name|void
name|setQualifierInfo
argument_list|(
argument|NestedNameSpecifier *Qualifier
argument_list|,
argument|SourceRange QualifierRange
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
name|classof
argument_list|(
argument|const TagDecl *D
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
name|TagFirst
operator|&&
name|K
operator|<=
name|TagLast
return|;
block|}
specifier|static
name|DeclContext
operator|*
name|castToDeclContext
argument_list|(
argument|const TagDecl *D
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
operator|*
name|castFromDeclContext
argument_list|(
argument|const DeclContext *DC
argument_list|)
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
expr|}
block|;
comment|/// EnumDecl - Represents an enum.  As an extension, we allow forward-declared
comment|/// enums.
name|class
name|EnumDecl
operator|:
name|public
name|TagDecl
block|{
comment|/// IntegerType - This represent the integer type that the enum corresponds
comment|/// to for code generation purposes.  Note that the enumerator constants may
comment|/// have a different type than this does.
name|QualType
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
argument_list|)
operator|:
name|TagDecl
argument_list|(
name|Enum
argument_list|,
name|TK_enum
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
name|IntegerType
operator|=
name|QualType
argument_list|()
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
argument_list|)
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
return|return
name|enumerator_iterator
argument_list|(
name|this
operator|->
name|decls_begin
argument_list|()
argument_list|)
return|;
block|}
name|enumerator_iterator
name|enumerator_end
argument_list|()
specifier|const
block|{
return|return
name|enumerator_iterator
argument_list|(
name|this
operator|->
name|decls_end
argument_list|()
argument_list|)
return|;
block|}
comment|/// getPromotionType - Return the integer type that enumerators
comment|/// should promote to.
name|QualType
name|getPromotionType
argument_list|()
specifier|const
block|{
return|return
name|PromotionType
return|;
block|}
comment|/// \brief Set the promotion type.
name|void
name|setPromotionType
argument_list|(
argument|QualType T
argument_list|)
block|{
name|PromotionType
operator|=
name|T
block|; }
comment|/// getIntegerType - Return the integer type this enum decl corresponds to.
comment|/// This returns a null qualtype for an enum forward definition.
name|QualType
name|getIntegerType
argument_list|()
specifier|const
block|{
return|return
name|IntegerType
return|;
block|}
comment|/// \brief Set the underlying integer type.
name|void
name|setIntegerType
argument_list|(
argument|QualType T
argument_list|)
block|{
name|IntegerType
operator|=
name|T
block|; }
comment|/// \brief Returns the enumeration (declared within the template)
comment|/// from which this enumeration type was instantiated, or NULL if
comment|/// this enumeration was not instantiated from any template.
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
name|void
name|setInstantiationOfMemberEnum
argument_list|(
argument|EnumDecl *IF
argument_list|)
block|{
name|InstantiatedFrom
operator|=
name|IF
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
argument|const EnumDecl *D
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
name|Enum
return|;
block|}
expr|}
block|;
comment|/// RecordDecl - Represents a struct/union/class.  For example:
comment|///   struct X;                  // Forward declaration, no "body".
comment|///   union Y { int A, B; };     // Has body with members A and B (FieldDecls).
comment|/// This decl will be marked invalid if *any* members are invalid.
comment|///
name|class
name|RecordDecl
operator|:
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
name|virtual
operator|~
name|RecordDecl
argument_list|()
block|;
name|public
operator|:
specifier|static
name|RecordDecl
operator|*
name|Create
argument_list|(
argument|ASTContext&C
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
name|virtual
name|void
name|Destroy
argument_list|(
name|ASTContext
operator|&
name|C
argument_list|)
block|;
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
block|{
return|return
name|field_iterator
argument_list|(
name|decls_begin
argument_list|()
argument_list|)
return|;
block|}
name|field_iterator
name|field_end
argument_list|()
specifier|const
block|{
return|return
name|field_iterator
argument_list|(
name|decls_end
argument_list|()
argument_list|)
return|;
block|}
comment|// field_empty - Whether there are any fields (non-static data
comment|// members) in this record.
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
comment|/// completeDefinition - Notes that the definition of this type is
comment|/// now complete.
name|void
name|completeDefinition
argument_list|()
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
name|classof
argument_list|(
argument|const RecordDecl *D
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
name|RecordFirst
operator|&&
name|K
operator|<=
name|RecordLast
return|;
block|}
expr|}
block|;
name|class
name|FileScopeAsmDecl
operator|:
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
comment|// FIXME: This can be packed into the bitfields in Decl.
name|bool
name|IsVariadic
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
block|{}
name|virtual
operator|~
name|BlockDecl
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
block|;
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
argument|const BlockDecl *D
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
name|Block
return|;
block|}
specifier|static
name|DeclContext
operator|*
name|castToDeclContext
argument_list|(
argument|const BlockDecl *D
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
name|BlockDecl
operator|*
operator|>
operator|(
name|D
operator|)
operator|)
return|;
block|}
specifier|static
name|BlockDecl
operator|*
name|castFromDeclContext
argument_list|(
argument|const DeclContext *DC
argument_list|)
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
expr|}
block|;
comment|/// Insertion operator for diagnostics.  This allows sending NamedDecl's
comment|/// into a diagnostic with<<.
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
expr|,
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
expr|}
end_decl_stmt

begin_comment
comment|// end namespace clang
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

