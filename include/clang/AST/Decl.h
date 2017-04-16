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
file|"clang/AST/Redeclarable.h"
end_include

begin_include
include|#
directive|include
file|"clang/AST/Type.h"
end_include

begin_include
include|#
directive|include
file|"clang/Basic/Linkage.h"
end_include

begin_include
include|#
directive|include
file|"clang/Basic/Module.h"
end_include

begin_include
include|#
directive|include
file|"clang/Basic/OperatorKinds.h"
end_include

begin_include
include|#
directive|include
file|"clang/Basic/PragmaKinds.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/ArrayRef.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/Optional.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/Compiler.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/raw_ostream.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/TrailingObjects.h"
end_include

begin_decl_stmt
name|namespace
name|clang
block|{
struct_decl|struct
name|ASTTemplateArgumentListInfo
struct_decl|;
name|class
name|CXXTemporary
decl_stmt|;
name|class
name|CompoundStmt
decl_stmt|;
name|class
name|DependentFunctionTemplateSpecializationInfo
decl_stmt|;
name|class
name|Expr
decl_stmt|;
name|class
name|FunctionTemplateDecl
decl_stmt|;
name|class
name|FunctionTemplateSpecializationInfo
decl_stmt|;
name|class
name|LabelStmt
decl_stmt|;
name|class
name|MemberSpecializationInfo
decl_stmt|;
name|class
name|NestedNameSpecifier
decl_stmt|;
name|class
name|ParmVarDecl
decl_stmt|;
name|class
name|Stmt
decl_stmt|;
name|class
name|StringLiteral
decl_stmt|;
name|class
name|TemplateArgumentList
decl_stmt|;
name|class
name|TemplateParameterList
decl_stmt|;
name|class
name|TypeAliasTemplateDecl
decl_stmt|;
name|class
name|TypeLoc
decl_stmt|;
name|class
name|UnresolvedSetImpl
decl_stmt|;
name|class
name|VarTemplateDecl
decl_stmt|;
comment|/// \brief A container of type source information.
comment|///
comment|/// A client can read the relevant info using TypeLoc wrappers, e.g:
comment|/// @code
comment|/// TypeLoc TL = TypeSourceInfo->getTypeLoc();
comment|/// TL.getStartLoc().print(OS, SrcMgr);
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
comment|/// \brief Override the type stored in this TypeSourceInfo. Use with caution!
name|void
name|overrideType
parameter_list|(
name|QualType
name|T
parameter_list|)
block|{
name|Ty
operator|=
name|T
expr_stmt|;
block|}
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
name|virtual
name|void
name|anchor
parameter_list|()
function_decl|;
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
parameter_list|(
name|ASTContext
modifier|&
name|ctx
parameter_list|)
function_decl|;
name|public
label|:
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
comment|/// \brief Represents a `#pragma comment` line. Always a child of
comment|/// TranslationUnitDecl.
name|class
name|PragmaCommentDecl
name|final
range|:
name|public
name|Decl
decl_stmt|,
name|private
name|llvm
decl|::
name|TrailingObjects
decl|<
name|PragmaCommentDecl
decl_stmt|,
name|char
decl|>
block|{
name|virtual
name|void
name|anchor
parameter_list|()
function_decl|;
name|PragmaMSCommentKind
name|CommentKind
decl_stmt|;
name|friend
name|TrailingObjects
decl_stmt|;
name|friend
name|class
name|ASTDeclReader
decl_stmt|;
name|friend
name|class
name|ASTDeclWriter
decl_stmt|;
name|PragmaCommentDecl
argument_list|(
argument|TranslationUnitDecl *TU
argument_list|,
argument|SourceLocation CommentLoc
argument_list|,
argument|PragmaMSCommentKind CommentKind
argument_list|)
block|:
name|Decl
argument_list|(
name|PragmaComment
argument_list|,
name|TU
argument_list|,
name|CommentLoc
argument_list|)
operator|,
name|CommentKind
argument_list|(
argument|CommentKind
argument_list|)
block|{}
name|public
operator|:
specifier|static
name|PragmaCommentDecl
operator|*
name|Create
argument_list|(
argument|const ASTContext&C
argument_list|,
argument|TranslationUnitDecl *DC
argument_list|,
argument|SourceLocation CommentLoc
argument_list|,
argument|PragmaMSCommentKind CommentKind
argument_list|,
argument|StringRef Arg
argument_list|)
expr_stmt|;
specifier|static
name|PragmaCommentDecl
modifier|*
name|CreateDeserialized
parameter_list|(
name|ASTContext
modifier|&
name|C
parameter_list|,
name|unsigned
name|ID
parameter_list|,
name|unsigned
name|ArgSize
parameter_list|)
function_decl|;
name|PragmaMSCommentKind
name|getCommentKind
argument_list|()
specifier|const
block|{
return|return
name|CommentKind
return|;
block|}
name|StringRef
name|getArg
argument_list|()
specifier|const
block|{
return|return
name|getTrailingObjects
operator|<
name|char
operator|>
operator|(
operator|)
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
name|PragmaComment
return|;
block|}
block|}
empty_stmt|;
comment|/// \brief Represents a `#pragma detect_mismatch` line. Always a child of
comment|/// TranslationUnitDecl.
name|class
name|PragmaDetectMismatchDecl
name|final
range|:
name|public
name|Decl
decl_stmt|,
name|private
name|llvm
decl|::
name|TrailingObjects
decl|<
name|PragmaDetectMismatchDecl
decl_stmt|,
name|char
decl|>
block|{
name|virtual
name|void
name|anchor
parameter_list|()
function_decl|;
name|size_t
name|ValueStart
decl_stmt|;
name|friend
name|TrailingObjects
decl_stmt|;
name|friend
name|class
name|ASTDeclReader
decl_stmt|;
name|friend
name|class
name|ASTDeclWriter
decl_stmt|;
name|PragmaDetectMismatchDecl
argument_list|(
argument|TranslationUnitDecl *TU
argument_list|,
argument|SourceLocation Loc
argument_list|,
argument|size_t ValueStart
argument_list|)
block|:
name|Decl
argument_list|(
name|PragmaDetectMismatch
argument_list|,
name|TU
argument_list|,
name|Loc
argument_list|)
operator|,
name|ValueStart
argument_list|(
argument|ValueStart
argument_list|)
block|{}
name|public
operator|:
specifier|static
name|PragmaDetectMismatchDecl
operator|*
name|Create
argument_list|(
argument|const ASTContext&C
argument_list|,
argument|TranslationUnitDecl *DC
argument_list|,
argument|SourceLocation Loc
argument_list|,
argument|StringRef Name
argument_list|,
argument|StringRef Value
argument_list|)
expr_stmt|;
specifier|static
name|PragmaDetectMismatchDecl
modifier|*
name|CreateDeserialized
parameter_list|(
name|ASTContext
modifier|&
name|C
parameter_list|,
name|unsigned
name|ID
parameter_list|,
name|unsigned
name|NameValueSize
parameter_list|)
function_decl|;
name|StringRef
name|getName
argument_list|()
specifier|const
block|{
return|return
name|getTrailingObjects
operator|<
name|char
operator|>
operator|(
operator|)
return|;
block|}
name|StringRef
name|getValue
argument_list|()
specifier|const
block|{
return|return
name|getTrailingObjects
operator|<
name|char
operator|>
operator|(
operator|)
operator|+
name|ValueStart
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
name|PragmaDetectMismatch
return|;
block|}
block|}
empty_stmt|;
comment|/// \brief Declaration context for names declared as extern "C" in C++. This
comment|/// is neither the semantic nor lexical context for such declarations, but is
comment|/// used to check for conflicts with other extern "C" declarations. Example:
comment|///
comment|/// \code
comment|///   namespace N { extern "C" void f(); } // #1
comment|///   void N::f() {}                       // #2
comment|///   namespace M { extern "C" void f(); } // #3
comment|/// \endcode
comment|///
comment|/// The semantic context of #1 is namespace N and its lexical context is the
comment|/// LinkageSpecDecl; the semantic context of #2 is namespace N and its lexical
comment|/// context is the TU. However, both declarations are also visible in the
comment|/// extern "C" context.
comment|///
comment|/// The declaration at #3 finds it is a redeclaration of \c N::f through
comment|/// lookup in the extern "C" context.
name|class
name|ExternCContextDecl
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
name|explicit
name|ExternCContextDecl
argument_list|(
name|TranslationUnitDecl
operator|*
name|TU
argument_list|)
operator|:
name|Decl
argument_list|(
name|ExternCContext
argument_list|,
name|TU
argument_list|,
name|SourceLocation
argument_list|()
argument_list|)
operator|,
name|DeclContext
argument_list|(
argument|ExternCContext
argument_list|)
block|{}
name|public
operator|:
specifier|static
name|ExternCContextDecl
operator|*
name|Create
argument_list|(
specifier|const
name|ASTContext
operator|&
name|C
argument_list|,
name|TranslationUnitDecl
operator|*
name|TU
argument_list|)
expr_stmt|;
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
name|classofKind
parameter_list|(
name|Kind
name|K
parameter_list|)
block|{
return|return
name|K
operator|==
name|ExternCContext
return|;
block|}
specifier|static
name|DeclContext
modifier|*
name|castToDeclContext
parameter_list|(
specifier|const
name|ExternCContextDecl
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
name|ExternCContextDecl
operator|*
operator|>
operator|(
name|D
operator|)
operator|)
return|;
block|}
specifier|static
name|ExternCContextDecl
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
name|ExternCContextDecl
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
comment|/// as ObjCMethodDecl, but not \@class, etc.
name|class
name|NamedDecl
range|:
name|public
name|Decl
block|{
name|virtual
name|void
name|anchor
argument_list|()
block|;
comment|/// Name - The name of this declaration, which is typically a normal
comment|/// identifier but may also be a special kind of name (C++
comment|/// constructor, Objective-C selector, etc.)
name|DeclarationName
name|Name
block|;
name|private
operator|:
name|NamedDecl
operator|*
name|getUnderlyingDeclImpl
argument_list|()
name|LLVM_READONLY
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
name|virtual
name|void
name|printName
argument_list|(
argument|raw_ostream&os
argument_list|)
specifier|const
block|;
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
comment|/// printQualifiedName - Returns human-readable qualified name for
comment|/// declaration, like A::B::i, for i being member of namespace A::B.
comment|/// If declaration is not member of context which can be named (record,
comment|/// namespace), it will return same result as printName().
comment|/// Creating this name is expensive, so it should be called only when
comment|/// performance doesn't matter.
name|void
name|printQualifiedName
argument_list|(
argument|raw_ostream&OS
argument_list|)
specifier|const
block|;
name|void
name|printQualifiedName
argument_list|(
argument|raw_ostream&OS
argument_list|,
argument|const PrintingPolicy&Policy
argument_list|)
specifier|const
block|;
comment|// FIXME: Remove string version.
name|std
operator|::
name|string
name|getQualifiedNameAsString
argument_list|()
specifier|const
block|;
comment|/// getNameForDiagnostic - Appends a human-readable name for this
comment|/// declaration into the given stream.
comment|///
comment|/// This is the method invoked by Sema when displaying a NamedDecl
comment|/// in a diagnostic.  It does not necessarily produce the same
comment|/// result as printName(); for example, class template
comment|/// specializations are printed with their template arguments.
name|virtual
name|void
name|getNameForDiagnostic
argument_list|(
argument|raw_ostream&OS
argument_list|,
argument|const PrintingPolicy&Policy
argument_list|,
argument|bool Qualified
argument_list|)
specifier|const
block|;
comment|/// \brief Determine whether this declaration, if
comment|/// known to be well-formed within its context, will replace the
comment|/// declaration OldD if introduced into scope. A declaration will
comment|/// replace another declaration if, for example, it is a
comment|/// redeclaration of the same variable or function, but not if it is
comment|/// a declaration of a different kind (function vs. class) or an
comment|/// overloaded function.
comment|///
comment|/// \param IsKnownNewer \c true if this declaration is known to be newer
comment|/// than \p OldD (for instance, if this declaration is newly-created).
name|bool
name|declarationReplaces
argument_list|(
argument|NamedDecl *OldD
argument_list|,
argument|bool IsKnownNewer = true
argument_list|)
specifier|const
block|;
comment|/// \brief Determine whether this declaration has linkage.
name|bool
name|hasLinkage
argument_list|()
specifier|const
block|;
name|using
name|Decl
operator|::
name|isModulePrivate
block|;
name|using
name|Decl
operator|::
name|setModulePrivate
block|;
comment|/// \brief Determine whether this declaration is hidden from name lookup.
name|bool
name|isHidden
argument_list|()
specifier|const
block|{
return|return
name|Hidden
return|;
block|}
comment|/// \brief Set whether this declaration is hidden from name lookup.
name|void
name|setHidden
argument_list|(
argument|bool Hide
argument_list|)
block|{
name|assert
argument_list|(
operator|(
operator|!
name|Hide
operator|||
name|isFromASTFile
argument_list|()
operator|||
name|hasLocalOwningModuleStorage
argument_list|()
operator|)
operator|&&
literal|"declaration with no owning module can't be hidden"
argument_list|)
block|;
name|Hidden
operator|=
name|Hide
block|;   }
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
name|getRedeclContext
argument_list|()
expr_stmt|;
return|return
name|DC
operator|->
name|isRecord
argument_list|()
return|;
block|}
comment|/// \brief Determine whether the given declaration is an instance member of
comment|/// a C++ class.
name|bool
name|isCXXInstanceMember
argument_list|()
specifier|const
expr_stmt|;
comment|/// \brief Determine what kind of linkage this entity has.
comment|/// This is not the linkage as defined by the standard or the codegen notion
comment|/// of linkage. It is just an implementation detail that is used to compute
comment|/// those.
name|Linkage
name|getLinkageInternal
argument_list|()
specifier|const
expr_stmt|;
comment|/// \brief Get the linkage from a semantic point of view. Entities in
comment|/// anonymous namespaces are external (in c++98).
name|Linkage
name|getFormalLinkage
argument_list|()
specifier|const
block|{
return|return
name|clang
operator|::
name|getFormalLinkage
argument_list|(
name|getLinkageInternal
argument_list|()
argument_list|)
return|;
block|}
comment|/// \brief True if this decl has external linkage.
name|bool
name|hasExternalFormalLinkage
argument_list|()
specifier|const
block|{
return|return
name|isExternalFormalLinkage
argument_list|(
name|getLinkageInternal
argument_list|()
argument_list|)
return|;
block|}
name|bool
name|isExternallyVisible
argument_list|()
specifier|const
block|{
return|return
name|clang
operator|::
name|isExternallyVisible
argument_list|(
name|getLinkageInternal
argument_list|()
argument_list|)
return|;
block|}
comment|/// \brief Determines the visibility of this entity.
name|Visibility
name|getVisibility
argument_list|()
specifier|const
block|{
return|return
name|getLinkageAndVisibility
argument_list|()
operator|.
name|getVisibility
argument_list|()
return|;
block|}
comment|/// \brief Determines the linkage and visibility of this entity.
name|LinkageInfo
name|getLinkageAndVisibility
argument_list|()
specifier|const
expr_stmt|;
comment|/// Kinds of explicit visibility.
enum|enum
name|ExplicitVisibilityKind
block|{
name|VisibilityForType
block|,
name|VisibilityForValue
block|}
enum|;
comment|/// \brief If visibility was explicitly specified for this
comment|/// declaration, return that visibility.
name|Optional
operator|<
name|Visibility
operator|>
name|getExplicitVisibility
argument_list|(
argument|ExplicitVisibilityKind kind
argument_list|)
specifier|const
expr_stmt|;
comment|/// \brief True if the computed linkage is valid. Used for consistency
comment|/// checking. Should always return true.
name|bool
name|isLinkageValid
argument_list|()
specifier|const
expr_stmt|;
comment|/// \brief True if something has required us to compute the linkage
comment|/// of this declaration.
comment|///
comment|/// Language features which can retroactively change linkage (like a
comment|/// typedef name for linkage purposes) may need to consider this,
comment|/// but hopefully only in transitory ways during parsing.
name|bool
name|hasLinkageBeenComputed
argument_list|()
specifier|const
block|{
return|return
name|hasCachedLinkage
argument_list|()
return|;
block|}
comment|/// \brief Looks through UsingDecls and ObjCCompatibleAliasDecls for
comment|/// the underlying named decl.
name|NamedDecl
modifier|*
name|getUnderlyingDecl
parameter_list|()
block|{
comment|// Fast-path the common case.
if|if
condition|(
name|this
operator|->
name|getKind
argument_list|()
operator|!=
name|UsingShadow
operator|&&
name|this
operator|->
name|getKind
argument_list|()
operator|!=
name|ConstructorUsingShadow
operator|&&
name|this
operator|->
name|getKind
argument_list|()
operator|!=
name|ObjCCompatibleAlias
operator|&&
name|this
operator|->
name|getKind
argument_list|()
operator|!=
name|NamespaceAlias
condition|)
return|return
name|this
return|;
return|return
name|getUnderlyingDeclImpl
argument_list|()
return|;
block|}
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
name|NamedDecl
modifier|*
name|getMostRecentDecl
parameter_list|()
block|{
return|return
name|cast
operator|<
name|NamedDecl
operator|>
operator|(
name|static_cast
operator|<
name|Decl
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
name|NamedDecl
operator|*
name|getMostRecentDecl
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
name|getMostRecentDecl
argument_list|()
return|;
block|}
name|ObjCStringFormatFamily
name|getObjCFStringFormattingFamily
argument_list|()
specifier|const
expr_stmt|;
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
operator|>=
name|firstNamed
operator|&&
name|K
operator|<=
name|lastNamed
return|;
block|}
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

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
specifier|const
name|NamedDecl
operator|&
name|ND
operator|)
block|{
name|ND
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
name|void
name|anchor
argument_list|()
name|override
block|;
name|LabelStmt
operator|*
name|TheStmt
block|;
name|StringRef
name|MSAsmName
block|;
name|bool
name|MSAsmNameResolved
block|;
comment|/// LocStart - For normal labels, this is the same as the main declaration
comment|/// label, i.e., the location of the identifier; for GNU local labels,
comment|/// this is the location of the __label__ keyword.
name|SourceLocation
name|LocStart
block|;
name|LabelDecl
argument_list|(
argument|DeclContext *DC
argument_list|,
argument|SourceLocation IdentL
argument_list|,
argument|IdentifierInfo *II
argument_list|,
argument|LabelStmt *S
argument_list|,
argument|SourceLocation StartL
argument_list|)
operator|:
name|NamedDecl
argument_list|(
name|Label
argument_list|,
name|DC
argument_list|,
name|IdentL
argument_list|,
name|II
argument_list|)
block|,
name|TheStmt
argument_list|(
name|S
argument_list|)
block|,
name|MSAsmNameResolved
argument_list|(
name|false
argument_list|)
block|,
name|LocStart
argument_list|(
argument|StartL
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
argument|SourceLocation IdentL
argument_list|,
argument|IdentifierInfo *II
argument_list|)
block|;
specifier|static
name|LabelDecl
operator|*
name|Create
argument_list|(
argument|ASTContext&C
argument_list|,
argument|DeclContext *DC
argument_list|,
argument|SourceLocation IdentL
argument_list|,
argument|IdentifierInfo *II
argument_list|,
argument|SourceLocation GnuLabelL
argument_list|)
block|;
specifier|static
name|LabelDecl
operator|*
name|CreateDeserialized
argument_list|(
argument|ASTContext&C
argument_list|,
argument|unsigned ID
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
name|bool
name|isGnuLocal
argument_list|()
specifier|const
block|{
return|return
name|LocStart
operator|!=
name|getLocation
argument_list|()
return|;
block|}
name|void
name|setLocStart
argument_list|(
argument|SourceLocation L
argument_list|)
block|{
name|LocStart
operator|=
name|L
block|; }
name|SourceRange
name|getSourceRange
argument_list|()
specifier|const
name|override
name|LLVM_READONLY
block|{
return|return
name|SourceRange
argument_list|(
name|LocStart
argument_list|,
name|getLocation
argument_list|()
argument_list|)
return|;
block|}
name|bool
name|isMSAsmLabel
argument_list|()
specifier|const
block|{
return|return
name|MSAsmName
operator|.
name|size
argument_list|()
operator|!=
literal|0
return|;
block|}
name|bool
name|isResolvedMSAsmLabel
argument_list|()
specifier|const
block|{
return|return
name|isMSAsmLabel
argument_list|()
operator|&&
name|MSAsmNameResolved
return|;
block|}
name|void
name|setMSAsmLabel
argument_list|(
argument|StringRef Name
argument_list|)
block|;
name|StringRef
name|getMSAsmLabel
argument_list|()
specifier|const
block|{
return|return
name|MSAsmName
return|;
block|}
name|void
name|setMSAsmLabelResolved
argument_list|()
block|{
name|MSAsmNameResolved
operator|=
name|true
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
block|,
name|public
name|Redeclarable
operator|<
name|NamespaceDecl
operator|>
block|{
comment|/// LocStart - The starting location of the source range, pointing
comment|/// to either the namespace or the inline keyword.
name|SourceLocation
name|LocStart
block|;
comment|/// RBraceLoc - The ending location of the source range.
name|SourceLocation
name|RBraceLoc
block|;
comment|/// \brief A pointer to either the anonymous namespace that lives just inside
comment|/// this namespace or to the first namespace in the chain (the latter case
comment|/// only when this is not the first in the chain), along with a
comment|/// boolean value indicating whether this is an inline namespace.
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
name|AnonOrFirstNamespaceAndInline
block|;
name|NamespaceDecl
argument_list|(
argument|ASTContext&C
argument_list|,
argument|DeclContext *DC
argument_list|,
argument|bool Inline
argument_list|,
argument|SourceLocation StartLoc
argument_list|,
argument|SourceLocation IdLoc
argument_list|,
argument|IdentifierInfo *Id
argument_list|,
argument|NamespaceDecl *PrevDecl
argument_list|)
block|;
typedef|typedef
name|Redeclarable
operator|<
name|NamespaceDecl
operator|>
name|redeclarable_base
expr_stmt|;
name|NamespaceDecl
operator|*
name|getNextRedeclarationImpl
argument_list|()
name|override
block|;
name|NamespaceDecl
operator|*
name|getPreviousDeclImpl
argument_list|()
name|override
block|;
name|NamespaceDecl
operator|*
name|getMostRecentDeclImpl
argument_list|()
name|override
block|;
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
argument|bool Inline
argument_list|,
argument|SourceLocation StartLoc
argument_list|,
argument|SourceLocation IdLoc
argument_list|,
argument|IdentifierInfo *Id
argument_list|,
argument|NamespaceDecl *PrevDecl
argument_list|)
block|;
specifier|static
name|NamespaceDecl
operator|*
name|CreateDeserialized
argument_list|(
argument|ASTContext&C
argument_list|,
argument|unsigned ID
argument_list|)
block|;
typedef|typedef
name|redeclarable_base
operator|::
name|redecl_range
name|redecl_range
expr_stmt|;
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
name|using
name|redeclarable_base
operator|::
name|redecls_begin
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|redeclarable_base
operator|::
name|redecls_end
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|redeclarable_base
operator|::
name|redecls
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|redeclarable_base
operator|::
name|getPreviousDecl
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|redeclarable_base
operator|::
name|getMostRecentDecl
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|redeclarable_base
operator|::
name|isFirstDecl
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// \brief Returns true if this is an anonymous namespace declaration.
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
comment|///   namespace {
end_comment

begin_comment
comment|///     ...
end_comment

begin_comment
comment|///   };
end_comment

begin_comment
comment|/// \endcode
end_comment

begin_comment
comment|/// q.v. C++ [namespace.unnamed]
end_comment

begin_expr_stmt
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
end_expr_stmt

begin_comment
comment|/// \brief Returns true if this is an inline namespace declaration.
end_comment

begin_expr_stmt
name|bool
name|isInline
argument_list|()
specifier|const
block|{
return|return
name|AnonOrFirstNamespaceAndInline
operator|.
name|getInt
argument_list|()
return|;
block|}
end_expr_stmt

begin_comment
comment|/// \brief Set whether this is an inline namespace declaration.
end_comment

begin_function
name|void
name|setInline
parameter_list|(
name|bool
name|Inline
parameter_list|)
block|{
name|AnonOrFirstNamespaceAndInline
operator|.
name|setInt
argument_list|(
name|Inline
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/// \brief Get the original (first) namespace declaration.
end_comment

begin_function_decl
name|NamespaceDecl
modifier|*
name|getOriginalNamespace
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/// \brief Get the original (first) namespace declaration.
end_comment

begin_expr_stmt
specifier|const
name|NamespaceDecl
operator|*
name|getOriginalNamespace
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// \brief Return true if this declaration is an original (first) declaration
end_comment

begin_comment
comment|/// of the namespace. This is false for non-original (subsequent) namespace
end_comment

begin_comment
comment|/// declarations and anonymous namespaces.
end_comment

begin_expr_stmt
name|bool
name|isOriginalNamespace
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// \brief Retrieve the anonymous namespace nested inside this namespace,
end_comment

begin_comment
comment|/// if any.
end_comment

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
name|AnonOrFirstNamespaceAndInline
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
name|getOriginalNamespace
argument_list|()
operator|->
name|AnonOrFirstNamespaceAndInline
operator|.
name|setPointer
argument_list|(
name|D
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/// Retrieves the canonical declaration of this namespace.
end_comment

begin_function
name|NamespaceDecl
modifier|*
name|getCanonicalDecl
parameter_list|()
function|override
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
name|SourceRange
name|getSourceRange
argument_list|()
specifier|const
name|override
name|LLVM_READONLY
block|{
return|return
name|SourceRange
argument_list|(
name|LocStart
argument_list|,
name|RBraceLoc
argument_list|)
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|SourceLocation
name|getLocStart
argument_list|()
specifier|const
name|LLVM_READONLY
block|{
return|return
name|LocStart
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|SourceLocation
name|getRBraceLoc
argument_list|()
specifier|const
block|{
return|return
name|RBraceLoc
return|;
block|}
end_expr_stmt

begin_function
name|void
name|setLocStart
parameter_list|(
name|SourceLocation
name|L
parameter_list|)
block|{
name|LocStart
operator|=
name|L
expr_stmt|;
block|}
end_function

begin_function
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
name|void
name|anchor
argument_list|()
name|override
block|;
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
comment|/// \brief Determine whether this symbol is weakly-imported,
comment|///        or declared with the weak or weak-ref attr.
name|bool
name|isWeak
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
comment|/// NumTemplParamLists - The number of "outer" template parameter lists.
comment|/// The count includes all of the template parameter lists that were matched
comment|/// against the template-ids occurring into the NNS and possibly (in the
comment|/// case of an explicit specialization) a final "template<>".
name|unsigned
name|NumTemplParamLists
block|;
comment|/// TemplParamLists - A new-allocated array of size NumTemplParamLists,
comment|/// containing pointers to the "outer" template parameter lists.
comment|/// It includes all of the template parameter lists that were matched
comment|/// against the template-ids occurring into the NNS and possibly (in the
comment|/// case of an explicit specialization) a final "template<>".
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
argument|nullptr
argument_list|)
block|{}
comment|/// setTemplateParameterListsInfo - Sets info about "outer" template
comment|/// parameter lists.
name|void
name|setTemplateParameterListsInfo
argument_list|(
name|ASTContext
operator|&
name|Context
argument_list|,
name|ArrayRef
operator|<
name|TemplateParameterList
operator|*
operator|>
name|TPLists
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
operator|=
name|delete
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
operator|=
name|delete
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
comment|/// InnerLocStart - The start of the source range for this declaration,
comment|/// ignoring outer template declarations.
name|SourceLocation
name|InnerLocStart
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
argument_list|,
argument|SourceLocation StartL
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
name|TInfo
argument_list|)
block|,
name|InnerLocStart
argument_list|(
argument|StartL
argument_list|)
block|{   }
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
name|SourceLocation
name|getInnerLocStart
argument_list|()
specifier|const
block|{
return|return
name|InnerLocStart
return|;
block|}
name|void
name|setInnerLocStart
argument_list|(
argument|SourceLocation L
argument_list|)
block|{
name|InnerLocStart
operator|=
name|L
block|; }
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
name|override
name|LLVM_READONLY
block|;
name|SourceLocation
name|getLocStart
argument_list|()
specifier|const
name|LLVM_READONLY
block|{
return|return
name|getOuterLocStart
argument_list|()
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
name|nullptr
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
name|ASTContext
operator|&
name|Context
argument_list|,
name|ArrayRef
operator|<
name|TemplateParameterList
operator|*
operator|>
name|TPLists
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
comment|/// \brief Whether this statement is an integral constant expression,
comment|/// or in C++11, whether the statement is a constant expression. Only
comment|/// valid if CheckedICE is true.
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
comment|/// getStorageClassSpecifierString - Return the string used to
comment|/// specify the storage class \p SC.
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
comment|/// \brief Initialization styles.
block|enum
name|InitializationStyle
block|{
name|CInit
block|,
comment|///< C-style initialization with assignment
name|CallInit
block|,
comment|///< Call-style initialization (C++98)
name|ListInit
comment|///< Direct list-initialization (C++11)
block|}
block|;
comment|/// \brief Kinds of thread-local storage.
block|enum
name|TLSKind
block|{
name|TLS_None
block|,
comment|///< Not a TLS variable.
name|TLS_Static
block|,
comment|///< TLS with a known-constant initializer.
name|TLS_Dynamic
comment|///< TLS with a dynamic initializer.
block|}
block|;
name|protected
operator|:
comment|// A pointer union of Stmt * and EvaluatedStmt *. When an EvaluatedStmt, we
comment|// have allocated the auxiliary struct of information there.
comment|//
comment|// TODO: It is a bit unfortunate to use a PointerUnion inside the VarDecl for
comment|// this as *many* VarDecls are ParmVarDecls that don't have default
comment|// arguments. We could save some space by moving this pointer union to be
comment|// allocated in trailing space when necessary.
typedef|typedef
name|llvm
operator|::
name|PointerUnion
operator|<
name|Stmt
operator|*
operator|,
name|EvaluatedStmt
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
name|class
name|VarDeclBitfields
block|{
name|friend
name|class
name|VarDecl
block|;
name|friend
name|class
name|ASTDeclReader
block|;
name|unsigned
name|SClass
operator|:
literal|3
block|;
name|unsigned
name|TSCSpec
operator|:
literal|2
block|;
name|unsigned
name|InitStyle
operator|:
literal|2
block|;   }
block|;   enum
block|{
name|NumVarDeclBits
operator|=
literal|7
block|}
block|;
name|friend
name|class
name|ASTDeclReader
block|;
name|friend
name|class
name|StmtIteratorBase
block|;
name|friend
name|class
name|ASTNodeImporter
block|;
name|protected
operator|:
expr|enum
block|{
name|NumParameterIndexBits
operator|=
literal|8
block|}
block|;    enum
name|DefaultArgKind
block|{
name|DAK_None
block|,
name|DAK_Unparsed
block|,
name|DAK_Uninstantiated
block|,
name|DAK_Normal
block|}
block|;
name|class
name|ParmVarDeclBitfields
block|{
name|friend
name|class
name|ParmVarDecl
block|;
name|friend
name|class
name|ASTDeclReader
block|;
name|unsigned
operator|:
name|NumVarDeclBits
block|;
comment|/// Whether this parameter inherits a default argument from a
comment|/// prior declaration.
name|unsigned
name|HasInheritedDefaultArg
operator|:
literal|1
block|;
comment|/// Describes the kind of default argument for this parameter. By default
comment|/// this is none. If this is normal, then the default argument is stored in
comment|/// the \c VarDecl initializer expression unless we were unable to parse
comment|/// (even an invalid) expression for the default argument.
name|unsigned
name|DefaultArgKind
operator|:
literal|2
block|;
comment|/// Whether this parameter undergoes K&R argument promotion.
name|unsigned
name|IsKNRPromoted
operator|:
literal|1
block|;
comment|/// Whether this parameter is an ObjC method parameter or not.
name|unsigned
name|IsObjCMethodParam
operator|:
literal|1
block|;
comment|/// If IsObjCMethodParam, a Decl::ObjCDeclQualifier.
comment|/// Otherwise, the number of function parameter scopes enclosing
comment|/// the function parameter scope in which this parameter was
comment|/// declared.
name|unsigned
name|ScopeDepthOrObjCQuals
operator|:
literal|7
block|;
comment|/// The number of parameters preceding this parameter in the
comment|/// function parameter scope in which it was declared.
name|unsigned
name|ParameterIndex
operator|:
name|NumParameterIndexBits
block|;   }
block|;
name|class
name|NonParmVarDeclBitfields
block|{
name|friend
name|class
name|VarDecl
block|;
name|friend
name|class
name|ASTDeclReader
block|;
name|unsigned
operator|:
name|NumVarDeclBits
block|;
comment|// FIXME: We need something similar to CXXRecordDecl::DefinitionData.
comment|/// \brief Whether this variable is a definition which was demoted due to
comment|/// module merge.
name|unsigned
name|IsThisDeclarationADemotedDefinition
operator|:
literal|1
block|;
comment|/// \brief Whether this variable is the exception variable in a C++ catch
comment|/// or an Objective-C @catch statement.
name|unsigned
name|ExceptionVar
operator|:
literal|1
block|;
comment|/// \brief Whether this local variable could be allocated in the return
comment|/// slot of its function, enabling the named return value optimization
comment|/// (NRVO).
name|unsigned
name|NRVOVariable
operator|:
literal|1
block|;
comment|/// \brief Whether this variable is the for-range-declaration in a C++0x
comment|/// for-range statement.
name|unsigned
name|CXXForRangeDecl
operator|:
literal|1
block|;
comment|/// \brief Whether this variable is an ARC pseudo-__strong
comment|/// variable;  see isARCPseudoStrong() for details.
name|unsigned
name|ARCPseudoStrong
operator|:
literal|1
block|;
comment|/// \brief Whether this variable is (C++1z) inline.
name|unsigned
name|IsInline
operator|:
literal|1
block|;
comment|/// \brief Whether this variable has (C++1z) inline explicitly specified.
name|unsigned
name|IsInlineSpecified
operator|:
literal|1
block|;
comment|/// \brief Whether this variable is (C++0x) constexpr.
name|unsigned
name|IsConstexpr
operator|:
literal|1
block|;
comment|/// \brief Whether this variable is the implicit variable for a lambda
comment|/// init-capture.
name|unsigned
name|IsInitCapture
operator|:
literal|1
block|;
comment|/// \brief Whether this local extern variable's previous declaration was
comment|/// declared in the same block scope. This controls whether we should merge
comment|/// the type of this declaration with its previous declaration.
name|unsigned
name|PreviousDeclInSameBlockScope
operator|:
literal|1
block|;   }
block|;
expr|union
block|{
name|unsigned
name|AllBits
block|;
name|VarDeclBitfields
name|VarDeclBits
block|;
name|ParmVarDeclBitfields
name|ParmVarDeclBits
block|;
name|NonParmVarDeclBitfields
name|NonParmVarDeclBits
block|;   }
block|;
name|VarDecl
argument_list|(
argument|Kind DK
argument_list|,
argument|ASTContext&C
argument_list|,
argument|DeclContext *DC
argument_list|,
argument|SourceLocation StartLoc
argument_list|,
argument|SourceLocation IdLoc
argument_list|,
argument|IdentifierInfo *Id
argument_list|,
argument|QualType T
argument_list|,
argument|TypeSourceInfo *TInfo
argument_list|,
argument|StorageClass SC
argument_list|)
block|;
typedef|typedef
name|Redeclarable
operator|<
name|VarDecl
operator|>
name|redeclarable_base
expr_stmt|;
name|VarDecl
operator|*
name|getNextRedeclarationImpl
argument_list|()
name|override
block|{
return|return
name|getNextRedeclaration
argument_list|()
return|;
block|}
name|VarDecl
operator|*
name|getPreviousDeclImpl
argument_list|()
name|override
block|{
return|return
name|getPreviousDecl
argument_list|()
return|;
block|}
name|VarDecl
operator|*
name|getMostRecentDeclImpl
argument_list|()
name|override
block|{
return|return
name|getMostRecentDecl
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
name|redecl_range
name|redecl_range
expr_stmt|;
end_typedef

begin_typedef
typedef|typedef
name|redeclarable_base
operator|::
name|redecl_iterator
name|redecl_iterator
expr_stmt|;
end_typedef

begin_expr_stmt
name|using
name|redeclarable_base
operator|::
name|redecls_begin
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|redeclarable_base
operator|::
name|redecls_end
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|redeclarable_base
operator|::
name|redecls
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|redeclarable_base
operator|::
name|getPreviousDecl
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|redeclarable_base
operator|::
name|getMostRecentDecl
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|redeclarable_base
operator|::
name|isFirstDecl
expr_stmt|;
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
name|StartLoc
parameter_list|,
name|SourceLocation
name|IdLoc
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
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|VarDecl
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
name|override
name|LLVM_READONLY
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// \brief Returns the storage class as written in the source. For the
end_comment

begin_comment
comment|/// computed linkage of symbol, see getLinkage.
end_comment

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
name|VarDeclBits
operator|.
name|SClass
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
name|setTSCSpec
parameter_list|(
name|ThreadStorageClassSpecifier
name|TSC
parameter_list|)
block|{
name|VarDeclBits
operator|.
name|TSCSpec
operator|=
name|TSC
expr_stmt|;
name|assert
argument_list|(
name|VarDeclBits
operator|.
name|TSCSpec
operator|==
name|TSC
operator|&&
literal|"truncation"
argument_list|)
expr_stmt|;
block|}
end_function

begin_expr_stmt
name|ThreadStorageClassSpecifier
name|getTSCSpec
argument_list|()
specifier|const
block|{
return|return
name|static_cast
operator|<
name|ThreadStorageClassSpecifier
operator|>
operator|(
name|VarDeclBits
operator|.
name|TSCSpec
operator|)
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|TLSKind
name|getTLSKind
argument_list|()
specifier|const
expr_stmt|;
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
comment|// Second check is for C++11 [dcl.stc]p4.
return|return
operator|!
name|isFileVarDecl
argument_list|()
operator|&&
name|getTSCSpec
argument_list|()
operator|==
name|TSCS_unspecified
return|;
end_expr_stmt

begin_comment
comment|// Global Named Register (GNU extension)
end_comment

begin_if
if|if
condition|(
name|getStorageClass
argument_list|()
operator|==
name|SC_Register
operator|&&
operator|!
name|isLocalVarDeclOrParm
argument_list|()
condition|)
return|return
name|false
return|;
end_if

begin_comment
comment|// Return true for:  Auto, Register.
end_comment

begin_comment
comment|// Return false for: Extern, Static, PrivateExtern, OpenCLWorkGroupLocal.
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
operator|(
name|getStorageClass
argument_list|()
operator|==
name|SC_Static
operator|||
comment|// C++11 [dcl.stc]p4
operator|(
name|getStorageClass
argument_list|()
operator|==
name|SC_None
operator|&&
name|getTSCSpec
argument_list|()
operator|==
name|TSCS_thread_local
operator|)
operator|)
operator|&&
operator|!
name|isFileVarDecl
argument_list|()
return|;
block|}
end_expr_stmt

begin_comment
comment|/// \brief Returns true if a variable has extern or __private_extern__
end_comment

begin_comment
comment|/// storage.
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
comment|/// \brief Returns true for all variables that do not have local storage.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This includes all global variables as well as static variables declared
end_comment

begin_comment
comment|/// within a function.
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
comment|/// \brief Get the storage duration of this variable, per C++ [basic.stc].
end_comment

begin_expr_stmt
name|StorageDuration
name|getStorageDuration
argument_list|()
specifier|const
block|{
return|return
name|hasLocalStorage
argument_list|()
operator|?
name|SD_Automatic
operator|:
name|getTSCSpec
argument_list|()
operator|?
name|SD_Thread
operator|:
name|SD_Static
return|;
block|}
end_expr_stmt

begin_comment
comment|/// \brief Compute the language linkage.
end_comment

begin_expr_stmt
name|LanguageLinkage
name|getLanguageLinkage
argument_list|()
specifier|const
expr_stmt|;
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
comment|/// \brief Determines whether this variable's context is, or is nested within,
end_comment

begin_comment
comment|/// a C++ extern "C" linkage spec.
end_comment

begin_expr_stmt
name|bool
name|isInExternCContext
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// \brief Determines whether this variable's context is, or is nested within,
end_comment

begin_comment
comment|/// a C++ extern "C++" linkage spec.
end_comment

begin_expr_stmt
name|bool
name|isInExternCXXContext
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
operator|&&
name|getKind
argument_list|()
operator|!=
name|Decl
operator|::
name|Decomposition
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
name|getLexicalDeclContext
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
comment|/// \brief Similar to isLocalVarDecl but also includes parameters.
end_comment

begin_macro
unit|bool
name|isLocalVarDeclOrParm
argument_list|()
end_macro

begin_expr_stmt
specifier|const
block|{
return|return
name|isLocalVarDecl
argument_list|()
operator|||
name|getKind
argument_list|()
operator|==
name|Decl
operator|::
name|ParmVar
return|;
block|}
end_expr_stmt

begin_comment
comment|/// isFunctionOrMethodVarDecl - Similar to isLocalVarDecl, but
end_comment

begin_comment
comment|/// excludes variables declared in blocks.
end_comment

begin_expr_stmt
name|bool
name|isFunctionOrMethodVarDecl
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
operator|&&
name|getKind
argument_list|()
operator|!=
name|Decl
operator|::
name|Decomposition
condition|)
return|return
name|false
return|;
specifier|const
name|DeclContext
operator|*
name|DC
operator|=
name|getLexicalDeclContext
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

begin_expr_stmt
name|VarDecl
operator|*
name|getCanonicalDecl
argument_list|()
name|override
expr_stmt|;
end_expr_stmt

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

begin_decl_stmt
name|DefinitionKind
name|isThisDeclarationADefinition
argument_list|(
name|ASTContext
operator|&
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|DefinitionKind
name|isThisDeclarationADefinition
argument_list|()
specifier|const
block|{
return|return
name|isThisDeclarationADefinition
argument_list|(
name|getASTContext
argument_list|()
argument_list|)
return|;
block|}
end_expr_stmt

begin_comment
comment|/// \brief Check whether this variable is defined in this
end_comment

begin_comment
comment|/// translation unit.
end_comment

begin_decl_stmt
name|DefinitionKind
name|hasDefinition
argument_list|(
name|ASTContext
operator|&
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|DefinitionKind
name|hasDefinition
argument_list|()
specifier|const
block|{
return|return
name|hasDefinition
argument_list|(
name|getASTContext
argument_list|()
argument_list|)
return|;
block|}
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
comment|/// \brief Get the real (not just tentative) definition for this declaration.
end_comment

begin_function_decl
name|VarDecl
modifier|*
name|getDefinition
parameter_list|(
name|ASTContext
modifier|&
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
specifier|const
name|VarDecl
modifier|*
name|getDefinition
argument_list|(
name|ASTContext
operator|&
name|C
argument_list|)
decl|const
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
argument_list|(
name|C
argument_list|)
return|;
block|}
end_decl_stmt

begin_function
name|VarDecl
modifier|*
name|getDefinition
parameter_list|()
block|{
return|return
name|getDefinition
argument_list|(
name|getASTContext
argument_list|()
argument_list|)
return|;
block|}
end_function

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
name|bool
name|isOutOfLine
argument_list|()
specifier|const
name|override
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// isFileVarDecl - Returns true for file scoped variable declaration.
end_comment

begin_expr_stmt
name|bool
name|isFileVarDecl
argument_list|()
specifier|const
block|{
name|Kind
name|K
operator|=
name|getKind
argument_list|()
block|;
if|if
condition|(
name|K
operator|==
name|ParmVar
operator|||
name|K
operator|==
name|ImplicitParam
condition|)
return|return
name|false
return|;
end_expr_stmt

begin_if
if|if
condition|(
name|getLexicalDeclContext
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
expr_stmt|;
end_expr_stmt

begin_expr_stmt
specifier|const
name|Expr
operator|*
name|getInit
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
name|getInit
argument_list|()
return|;
block|}
end_expr_stmt

begin_function_decl
name|Expr
modifier|*
name|getInit
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/// \brief Retrieve the address of the initializer expression.
end_comment

begin_function_decl
name|Stmt
modifier|*
modifier|*
name|getInitAddress
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|setInit
parameter_list|(
name|Expr
modifier|*
name|I
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// \brief Determine whether this variable's value can be used in a
end_comment

begin_comment
comment|/// constant expression, according to the relevant language standard.
end_comment

begin_comment
comment|/// This only checks properties of the declaration, and does not check
end_comment

begin_comment
comment|/// whether the initializer is in fact a constant expression.
end_comment

begin_decl_stmt
name|bool
name|isUsableInConstantExpressions
argument_list|(
name|ASTContext
operator|&
name|C
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|EvaluatedStmt
operator|*
name|ensureEvaluatedStmt
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// \brief Attempt to evaluate the value of the initializer attached to this
end_comment

begin_comment
comment|/// declaration, and produce notes explaining why it cannot be evaluated or is
end_comment

begin_comment
comment|/// not a constant expression. Returns a pointer to the value if evaluation
end_comment

begin_comment
comment|/// succeeded, 0 otherwise.
end_comment

begin_expr_stmt
name|APValue
operator|*
name|evaluateValue
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt

begin_decl_stmt
name|APValue
modifier|*
name|evaluateValue
argument_list|(
name|SmallVectorImpl
operator|<
name|PartialDiagnosticAt
operator|>
operator|&
name|Notes
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// \brief Return the already-evaluated value of this variable's
end_comment

begin_comment
comment|/// initializer, or NULL if the value is not yet known. Returns pointer
end_comment

begin_comment
comment|/// to untyped APValue if the value could not be evaluated.
end_comment

begin_expr_stmt
name|APValue
operator|*
name|getEvaluatedValue
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// \brief Determines whether it is already known whether the
end_comment

begin_comment
comment|/// initializer is an integral constant expression or not.
end_comment

begin_expr_stmt
name|bool
name|isInitKnownICE
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// \brief Determines whether the initializer is an integral constant
end_comment

begin_comment
comment|/// expression, or in C++11, whether the initializer is a constant
end_comment

begin_comment
comment|/// expression.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \pre isInitKnownICE()
end_comment

begin_expr_stmt
name|bool
name|isInitICE
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// \brief Determine whether the value of the initializer attached to this
end_comment

begin_comment
comment|/// declaration is an integral constant expression.
end_comment

begin_expr_stmt
name|bool
name|checkInitIsICE
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt

begin_function
name|void
name|setInitStyle
parameter_list|(
name|InitializationStyle
name|Style
parameter_list|)
block|{
name|VarDeclBits
operator|.
name|InitStyle
operator|=
name|Style
expr_stmt|;
block|}
end_function

begin_comment
comment|/// \brief The style of initialization for this declaration.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// C-style initialization is "int x = 1;". Call-style initialization is
end_comment

begin_comment
comment|/// a C++98 direct-initializer, e.g. "int x(1);". The Init expression will be
end_comment

begin_comment
comment|/// the expression inside the parens or a "ClassType(a,b,c)" class constructor
end_comment

begin_comment
comment|/// expression for class types. List-style initialization is C++11 syntax,
end_comment

begin_comment
comment|/// e.g. "int x{1};". Clients can distinguish between different forms of
end_comment

begin_comment
comment|/// initialization by checking this value. In particular, "int x = {1};" is
end_comment

begin_comment
comment|/// C-style, "int x({1})" is call-style, and "int x{1};" is list-style; the
end_comment

begin_comment
comment|/// Init expression in all three cases is an InitListExpr.
end_comment

begin_expr_stmt
name|InitializationStyle
name|getInitStyle
argument_list|()
specifier|const
block|{
return|return
name|static_cast
operator|<
name|InitializationStyle
operator|>
operator|(
name|VarDeclBits
operator|.
name|InitStyle
operator|)
return|;
block|}
end_expr_stmt

begin_comment
comment|/// \brief Whether the initializer is a direct-initializer (list or call).
end_comment

begin_expr_stmt
name|bool
name|isDirectInit
argument_list|()
specifier|const
block|{
return|return
name|getInitStyle
argument_list|()
operator|!=
name|CInit
return|;
block|}
end_expr_stmt

begin_comment
comment|/// \brief If this definition should pretend to be a declaration.
end_comment

begin_expr_stmt
name|bool
name|isThisDeclarationADemotedDefinition
argument_list|()
specifier|const
block|{
return|return
name|isa
operator|<
name|ParmVarDecl
operator|>
operator|(
name|this
operator|)
operator|?
name|false
operator|:
name|NonParmVarDeclBits
operator|.
name|IsThisDeclarationADemotedDefinition
return|;
block|}
end_expr_stmt

begin_comment
comment|/// \brief This is a definition which should be demoted to a declaration.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// In some cases (mostly module merging) we can end up with two visible
end_comment

begin_comment
comment|/// definitions one of which needs to be demoted to a declaration to keep
end_comment

begin_comment
comment|/// the AST invariants.
end_comment

begin_function
name|void
name|demoteThisDefinitionToDeclaration
parameter_list|()
block|{
name|assert
argument_list|(
name|isThisDeclarationADefinition
argument_list|()
operator|&&
literal|"Not a definition!"
argument_list|)
expr_stmt|;
name|assert
argument_list|(
operator|!
name|isa
operator|<
name|ParmVarDecl
operator|>
operator|(
name|this
operator|)
operator|&&
literal|"Cannot demote ParmVarDecls!"
argument_list|)
expr_stmt|;
name|NonParmVarDeclBits
operator|.
name|IsThisDeclarationADemotedDefinition
operator|=
literal|1
expr_stmt|;
block|}
end_function

begin_comment
comment|/// \brief Determine whether this variable is the exception variable in a
end_comment

begin_comment
comment|/// C++ catch statememt or an Objective-C \@catch statement.
end_comment

begin_expr_stmt
name|bool
name|isExceptionVariable
argument_list|()
specifier|const
block|{
return|return
name|isa
operator|<
name|ParmVarDecl
operator|>
operator|(
name|this
operator|)
operator|?
name|false
operator|:
name|NonParmVarDeclBits
operator|.
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
name|assert
argument_list|(
operator|!
name|isa
operator|<
name|ParmVarDecl
operator|>
operator|(
name|this
operator|)
argument_list|)
expr_stmt|;
name|NonParmVarDeclBits
operator|.
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
name|isa
operator|<
name|ParmVarDecl
operator|>
operator|(
name|this
operator|)
operator|?
name|false
operator|:
name|NonParmVarDeclBits
operator|.
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
name|assert
argument_list|(
operator|!
name|isa
operator|<
name|ParmVarDecl
operator|>
operator|(
name|this
operator|)
argument_list|)
expr_stmt|;
name|NonParmVarDeclBits
operator|.
name|NRVOVariable
operator|=
name|NRVO
expr_stmt|;
block|}
end_function

begin_comment
comment|/// \brief Determine whether this variable is the for-range-declaration in
end_comment

begin_comment
comment|/// a C++0x for-range statement.
end_comment

begin_expr_stmt
name|bool
name|isCXXForRangeDecl
argument_list|()
specifier|const
block|{
return|return
name|isa
operator|<
name|ParmVarDecl
operator|>
operator|(
name|this
operator|)
operator|?
name|false
operator|:
name|NonParmVarDeclBits
operator|.
name|CXXForRangeDecl
return|;
block|}
end_expr_stmt

begin_function
name|void
name|setCXXForRangeDecl
parameter_list|(
name|bool
name|FRD
parameter_list|)
block|{
name|assert
argument_list|(
operator|!
name|isa
operator|<
name|ParmVarDecl
operator|>
operator|(
name|this
operator|)
argument_list|)
expr_stmt|;
name|NonParmVarDeclBits
operator|.
name|CXXForRangeDecl
operator|=
name|FRD
expr_stmt|;
block|}
end_function

begin_comment
comment|/// \brief Determine whether this variable is an ARC pseudo-__strong
end_comment

begin_comment
comment|/// variable.  A pseudo-__strong variable has a __strong-qualified
end_comment

begin_comment
comment|/// type but does not actually retain the object written into it.
end_comment

begin_comment
comment|/// Generally such variables are also 'const' for safety.
end_comment

begin_expr_stmt
name|bool
name|isARCPseudoStrong
argument_list|()
specifier|const
block|{
return|return
name|isa
operator|<
name|ParmVarDecl
operator|>
operator|(
name|this
operator|)
operator|?
name|false
operator|:
name|NonParmVarDeclBits
operator|.
name|ARCPseudoStrong
return|;
block|}
end_expr_stmt

begin_function
name|void
name|setARCPseudoStrong
parameter_list|(
name|bool
name|ps
parameter_list|)
block|{
name|assert
argument_list|(
operator|!
name|isa
operator|<
name|ParmVarDecl
operator|>
operator|(
name|this
operator|)
argument_list|)
expr_stmt|;
name|NonParmVarDeclBits
operator|.
name|ARCPseudoStrong
operator|=
name|ps
expr_stmt|;
block|}
end_function

begin_comment
comment|/// Whether this variable is (C++1z) inline.
end_comment

begin_expr_stmt
name|bool
name|isInline
argument_list|()
specifier|const
block|{
return|return
name|isa
operator|<
name|ParmVarDecl
operator|>
operator|(
name|this
operator|)
operator|?
name|false
operator|:
name|NonParmVarDeclBits
operator|.
name|IsInline
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|bool
name|isInlineSpecified
argument_list|()
specifier|const
block|{
return|return
name|isa
operator|<
name|ParmVarDecl
operator|>
operator|(
name|this
operator|)
operator|?
name|false
operator|:
name|NonParmVarDeclBits
operator|.
name|IsInlineSpecified
return|;
block|}
end_expr_stmt

begin_function
name|void
name|setInlineSpecified
parameter_list|()
block|{
name|assert
argument_list|(
operator|!
name|isa
operator|<
name|ParmVarDecl
operator|>
operator|(
name|this
operator|)
argument_list|)
expr_stmt|;
name|NonParmVarDeclBits
operator|.
name|IsInline
operator|=
name|true
expr_stmt|;
name|NonParmVarDeclBits
operator|.
name|IsInlineSpecified
operator|=
name|true
expr_stmt|;
block|}
end_function

begin_function
name|void
name|setImplicitlyInline
parameter_list|()
block|{
name|assert
argument_list|(
operator|!
name|isa
operator|<
name|ParmVarDecl
operator|>
operator|(
name|this
operator|)
argument_list|)
expr_stmt|;
name|NonParmVarDeclBits
operator|.
name|IsInline
operator|=
name|true
expr_stmt|;
block|}
end_function

begin_comment
comment|/// Whether this variable is (C++11) constexpr.
end_comment

begin_expr_stmt
name|bool
name|isConstexpr
argument_list|()
specifier|const
block|{
return|return
name|isa
operator|<
name|ParmVarDecl
operator|>
operator|(
name|this
operator|)
operator|?
name|false
operator|:
name|NonParmVarDeclBits
operator|.
name|IsConstexpr
return|;
block|}
end_expr_stmt

begin_function
name|void
name|setConstexpr
parameter_list|(
name|bool
name|IC
parameter_list|)
block|{
name|assert
argument_list|(
operator|!
name|isa
operator|<
name|ParmVarDecl
operator|>
operator|(
name|this
operator|)
argument_list|)
expr_stmt|;
name|NonParmVarDeclBits
operator|.
name|IsConstexpr
operator|=
name|IC
expr_stmt|;
block|}
end_function

begin_comment
comment|/// Whether this variable is the implicit variable for a lambda init-capture.
end_comment

begin_expr_stmt
name|bool
name|isInitCapture
argument_list|()
specifier|const
block|{
return|return
name|isa
operator|<
name|ParmVarDecl
operator|>
operator|(
name|this
operator|)
operator|?
name|false
operator|:
name|NonParmVarDeclBits
operator|.
name|IsInitCapture
return|;
block|}
end_expr_stmt

begin_function
name|void
name|setInitCapture
parameter_list|(
name|bool
name|IC
parameter_list|)
block|{
name|assert
argument_list|(
operator|!
name|isa
operator|<
name|ParmVarDecl
operator|>
operator|(
name|this
operator|)
argument_list|)
expr_stmt|;
name|NonParmVarDeclBits
operator|.
name|IsInitCapture
operator|=
name|IC
expr_stmt|;
block|}
end_function

begin_comment
comment|/// Whether this local extern variable declaration's previous declaration
end_comment

begin_comment
comment|/// was declared in the same block scope. Only correct in C++.
end_comment

begin_expr_stmt
name|bool
name|isPreviousDeclInSameBlockScope
argument_list|()
specifier|const
block|{
return|return
name|isa
operator|<
name|ParmVarDecl
operator|>
operator|(
name|this
operator|)
operator|?
name|false
operator|:
name|NonParmVarDeclBits
operator|.
name|PreviousDeclInSameBlockScope
return|;
block|}
end_expr_stmt

begin_function
name|void
name|setPreviousDeclInSameBlockScope
parameter_list|(
name|bool
name|Same
parameter_list|)
block|{
name|assert
argument_list|(
operator|!
name|isa
operator|<
name|ParmVarDecl
operator|>
operator|(
name|this
operator|)
argument_list|)
expr_stmt|;
name|NonParmVarDeclBits
operator|.
name|PreviousDeclInSameBlockScope
operator|=
name|Same
expr_stmt|;
block|}
end_function

begin_comment
comment|/// \brief Retrieve the variable declaration from which this variable could
end_comment

begin_comment
comment|/// be instantiated, if it is an instantiation (rather than a non-template).
end_comment

begin_expr_stmt
name|VarDecl
operator|*
name|getTemplateInstantiationPattern
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt

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
comment|/// \brief If this variable is an instantiation of a variable template or a
end_comment

begin_comment
comment|/// static data member of a class template, determine what kind of
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
comment|/// \brief If this variable is an instantiation of a variable template or a
end_comment

begin_comment
comment|/// static data member of a class template, determine its point of
end_comment

begin_comment
comment|/// instantiation.
end_comment

begin_expr_stmt
name|SourceLocation
name|getPointOfInstantiation
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
comment|/// \brief Specify that this variable is an instantiation of the
end_comment

begin_comment
comment|/// static data member VD.
end_comment

begin_function_decl
name|void
name|setInstantiationOfStaticDataMember
parameter_list|(
name|VarDecl
modifier|*
name|VD
parameter_list|,
name|TemplateSpecializationKind
name|TSK
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// \brief Retrieves the variable template that is described by this
end_comment

begin_comment
comment|/// variable declaration.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Every variable template is represented as a VarTemplateDecl and a
end_comment

begin_comment
comment|/// VarDecl. The former contains template properties (such as
end_comment

begin_comment
comment|/// the template parameter lists) while the latter contains the
end_comment

begin_comment
comment|/// actual description of the template's
end_comment

begin_comment
comment|/// contents. VarTemplateDecl::getTemplatedDecl() retrieves the
end_comment

begin_comment
comment|/// VarDecl that from a VarTemplateDecl, while
end_comment

begin_comment
comment|/// getDescribedVarTemplate() retrieves the VarTemplateDecl from
end_comment

begin_comment
comment|/// a VarDecl.
end_comment

begin_expr_stmt
name|VarTemplateDecl
operator|*
name|getDescribedVarTemplate
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt

begin_function_decl
name|void
name|setDescribedVarTemplate
parameter_list|(
name|VarTemplateDecl
modifier|*
name|Template
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
name|void
name|anchor
argument_list|()
name|override
block|;
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
argument|SourceLocation IdLoc
argument_list|,
argument|IdentifierInfo *Id
argument_list|,
argument|QualType T
argument_list|)
block|;
specifier|static
name|ImplicitParamDecl
operator|*
name|CreateDeserialized
argument_list|(
argument|ASTContext&C
argument_list|,
argument|unsigned ID
argument_list|)
block|;
name|ImplicitParamDecl
argument_list|(
argument|ASTContext&C
argument_list|,
argument|DeclContext *DC
argument_list|,
argument|SourceLocation IdLoc
argument_list|,
argument|IdentifierInfo *Id
argument_list|,
argument|QualType Type
argument_list|)
operator|:
name|VarDecl
argument_list|(
argument|ImplicitParam
argument_list|,
argument|C
argument_list|,
argument|DC
argument_list|,
argument|IdLoc
argument_list|,
argument|IdLoc
argument_list|,
argument|Id
argument_list|,
argument|Type
argument_list|,
comment|/*tinfo*/
argument|nullptr
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
comment|/// ParmVarDecl - Represents a parameter to a function.
name|class
name|ParmVarDecl
operator|:
name|public
name|VarDecl
block|{
name|public
operator|:
expr|enum
block|{
name|MaxFunctionScopeDepth
operator|=
literal|255
block|}
block|;   enum
block|{
name|MaxFunctionScopeIndex
operator|=
literal|255
block|}
block|;
name|protected
operator|:
name|ParmVarDecl
argument_list|(
argument|Kind DK
argument_list|,
argument|ASTContext&C
argument_list|,
argument|DeclContext *DC
argument_list|,
argument|SourceLocation StartLoc
argument_list|,
argument|SourceLocation IdLoc
argument_list|,
argument|IdentifierInfo *Id
argument_list|,
argument|QualType T
argument_list|,
argument|TypeSourceInfo *TInfo
argument_list|,
argument|StorageClass S
argument_list|,
argument|Expr *DefArg
argument_list|)
operator|:
name|VarDecl
argument_list|(
argument|DK
argument_list|,
argument|C
argument_list|,
argument|DC
argument_list|,
argument|StartLoc
argument_list|,
argument|IdLoc
argument_list|,
argument|Id
argument_list|,
argument|T
argument_list|,
argument|TInfo
argument_list|,
argument|S
argument_list|)
block|{
name|assert
argument_list|(
name|ParmVarDeclBits
operator|.
name|HasInheritedDefaultArg
operator|==
name|false
argument_list|)
block|;
name|assert
argument_list|(
name|ParmVarDeclBits
operator|.
name|DefaultArgKind
operator|==
name|DAK_None
argument_list|)
block|;
name|assert
argument_list|(
name|ParmVarDeclBits
operator|.
name|IsKNRPromoted
operator|==
name|false
argument_list|)
block|;
name|assert
argument_list|(
name|ParmVarDeclBits
operator|.
name|IsObjCMethodParam
operator|==
name|false
argument_list|)
block|;
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
argument|SourceLocation StartLoc
argument_list|,
argument|SourceLocation IdLoc
argument_list|,
argument|IdentifierInfo *Id
argument_list|,
argument|QualType T
argument_list|,
argument|TypeSourceInfo *TInfo
argument_list|,
argument|StorageClass S
argument_list|,
argument|Expr *DefArg
argument_list|)
block|;
specifier|static
name|ParmVarDecl
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
name|override
name|LLVM_READONLY
block|;
name|void
name|setObjCMethodScopeInfo
argument_list|(
argument|unsigned parameterIndex
argument_list|)
block|{
name|ParmVarDeclBits
operator|.
name|IsObjCMethodParam
operator|=
name|true
block|;
name|setParameterIndex
argument_list|(
name|parameterIndex
argument_list|)
block|;   }
name|void
name|setScopeInfo
argument_list|(
argument|unsigned scopeDepth
argument_list|,
argument|unsigned parameterIndex
argument_list|)
block|{
name|assert
argument_list|(
operator|!
name|ParmVarDeclBits
operator|.
name|IsObjCMethodParam
argument_list|)
block|;
name|ParmVarDeclBits
operator|.
name|ScopeDepthOrObjCQuals
operator|=
name|scopeDepth
block|;
name|assert
argument_list|(
name|ParmVarDeclBits
operator|.
name|ScopeDepthOrObjCQuals
operator|==
name|scopeDepth
operator|&&
literal|"truncation!"
argument_list|)
block|;
name|setParameterIndex
argument_list|(
name|parameterIndex
argument_list|)
block|;   }
name|bool
name|isObjCMethodParameter
argument_list|()
specifier|const
block|{
return|return
name|ParmVarDeclBits
operator|.
name|IsObjCMethodParam
return|;
block|}
name|unsigned
name|getFunctionScopeDepth
argument_list|()
specifier|const
block|{
if|if
condition|(
name|ParmVarDeclBits
operator|.
name|IsObjCMethodParam
condition|)
return|return
literal|0
return|;
return|return
name|ParmVarDeclBits
operator|.
name|ScopeDepthOrObjCQuals
return|;
block|}
comment|/// Returns the index of this parameter in its prototype or method scope.
name|unsigned
name|getFunctionScopeIndex
argument_list|()
specifier|const
block|{
return|return
name|getParameterIndex
argument_list|()
return|;
block|}
name|ObjCDeclQualifier
name|getObjCDeclQualifier
argument_list|()
specifier|const
block|{
if|if
condition|(
operator|!
name|ParmVarDeclBits
operator|.
name|IsObjCMethodParam
condition|)
return|return
name|OBJC_TQ_None
return|;
return|return
name|ObjCDeclQualifier
argument_list|(
name|ParmVarDeclBits
operator|.
name|ScopeDepthOrObjCQuals
argument_list|)
return|;
block|}
end_decl_stmt

begin_function
name|void
name|setObjCDeclQualifier
parameter_list|(
name|ObjCDeclQualifier
name|QTVal
parameter_list|)
block|{
name|assert
argument_list|(
name|ParmVarDeclBits
operator|.
name|IsObjCMethodParam
argument_list|)
expr_stmt|;
name|ParmVarDeclBits
operator|.
name|ScopeDepthOrObjCQuals
operator|=
name|QTVal
expr_stmt|;
block|}
end_function

begin_comment
comment|/// True if the value passed to this parameter must undergo
end_comment

begin_comment
comment|/// K&R-style default argument promotion:
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// C99 6.5.2.2.
end_comment

begin_comment
comment|///   If the expression that denotes the called function has a type
end_comment

begin_comment
comment|///   that does not include a prototype, the integer promotions are
end_comment

begin_comment
comment|///   performed on each argument, and arguments that have type float
end_comment

begin_comment
comment|///   are promoted to double.
end_comment

begin_expr_stmt
name|bool
name|isKNRPromoted
argument_list|()
specifier|const
block|{
return|return
name|ParmVarDeclBits
operator|.
name|IsKNRPromoted
return|;
block|}
end_expr_stmt

begin_function
name|void
name|setKNRPromoted
parameter_list|(
name|bool
name|promoted
parameter_list|)
block|{
name|ParmVarDeclBits
operator|.
name|IsKNRPromoted
operator|=
name|promoted
expr_stmt|;
block|}
end_function

begin_function_decl
name|Expr
modifier|*
name|getDefaultArg
parameter_list|()
function_decl|;
end_function_decl

begin_expr_stmt
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
end_expr_stmt

begin_function_decl
name|void
name|setDefaultArg
parameter_list|(
name|Expr
modifier|*
name|defarg
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// \brief Retrieve the source range that covers the entire default
end_comment

begin_comment
comment|/// argument.
end_comment

begin_expr_stmt
name|SourceRange
name|getDefaultArgRange
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt

begin_function_decl
name|void
name|setUninstantiatedDefaultArg
parameter_list|(
name|Expr
modifier|*
name|arg
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|Expr
modifier|*
name|getUninstantiatedDefaultArg
parameter_list|()
function_decl|;
end_function_decl

begin_expr_stmt
specifier|const
name|Expr
operator|*
name|getUninstantiatedDefaultArg
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
name|getUninstantiatedDefaultArg
argument_list|()
return|;
block|}
end_expr_stmt

begin_comment
comment|/// hasDefaultArg - Determines whether this parameter has a default argument,
end_comment

begin_comment
comment|/// either parsed or not.
end_comment

begin_expr_stmt
name|bool
name|hasDefaultArg
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// hasUnparsedDefaultArg - Determines whether this parameter has a
end_comment

begin_comment
comment|/// default argument that has not yet been parsed. This will occur
end_comment

begin_comment
comment|/// during the processing of a C++ class whose member functions have
end_comment

begin_comment
comment|/// default arguments, e.g.,
end_comment

begin_comment
comment|/// @code
end_comment

begin_comment
comment|///   class X {
end_comment

begin_comment
comment|///   public:
end_comment

begin_comment
comment|///     void f(int x = 17); // x has an unparsed default argument now
end_comment

begin_comment
comment|///   }; // x has a regular default argument now
end_comment

begin_comment
comment|/// @endcode
end_comment

begin_expr_stmt
name|bool
name|hasUnparsedDefaultArg
argument_list|()
specifier|const
block|{
return|return
name|ParmVarDeclBits
operator|.
name|DefaultArgKind
operator|==
name|DAK_Unparsed
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|bool
name|hasUninstantiatedDefaultArg
argument_list|()
specifier|const
block|{
return|return
name|ParmVarDeclBits
operator|.
name|DefaultArgKind
operator|==
name|DAK_Uninstantiated
return|;
block|}
end_expr_stmt

begin_comment
comment|/// setUnparsedDefaultArg - Specify that this parameter has an
end_comment

begin_comment
comment|/// unparsed default argument. The argument will be replaced with a
end_comment

begin_comment
comment|/// real default argument via setDefaultArg when the class
end_comment

begin_comment
comment|/// definition enclosing the function declaration that owns this
end_comment

begin_comment
comment|/// default argument is completed.
end_comment

begin_function
name|void
name|setUnparsedDefaultArg
parameter_list|()
block|{
name|ParmVarDeclBits
operator|.
name|DefaultArgKind
operator|=
name|DAK_Unparsed
expr_stmt|;
block|}
end_function

begin_expr_stmt
name|bool
name|hasInheritedDefaultArg
argument_list|()
specifier|const
block|{
return|return
name|ParmVarDeclBits
operator|.
name|HasInheritedDefaultArg
return|;
block|}
end_expr_stmt

begin_function
name|void
name|setHasInheritedDefaultArg
parameter_list|(
name|bool
name|I
init|=
name|true
parameter_list|)
block|{
name|ParmVarDeclBits
operator|.
name|HasInheritedDefaultArg
operator|=
name|I
expr_stmt|;
block|}
end_function

begin_expr_stmt
name|QualType
name|getOriginalType
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// \brief Determine whether this parameter is actually a function
end_comment

begin_comment
comment|/// parameter pack.
end_comment

begin_expr_stmt
name|bool
name|isParameterPack
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// setOwningFunction - Sets the function declaration that owns this
end_comment

begin_comment
comment|/// ParmVarDecl. Since ParmVarDecls are often created before the
end_comment

begin_comment
comment|/// FunctionDecls that own them, this routine is required to update
end_comment

begin_comment
comment|/// the DeclContext appropriately.
end_comment

begin_function
name|void
name|setOwningFunction
parameter_list|(
name|DeclContext
modifier|*
name|FD
parameter_list|)
block|{
name|setDeclContext
argument_list|(
name|FD
argument_list|)
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
name|classofKind
parameter_list|(
name|Kind
name|K
parameter_list|)
block|{
return|return
name|K
operator|==
name|ParmVar
return|;
block|}
end_function

begin_label
name|private
label|:
end_label

begin_enum
enum|enum
block|{
name|ParameterIndexSentinel
init|=
operator|(
literal|1
operator|<<
name|NumParameterIndexBits
operator|)
operator|-
literal|1
block|}
enum|;
end_enum

begin_function
name|void
name|setParameterIndex
parameter_list|(
name|unsigned
name|parameterIndex
parameter_list|)
block|{
if|if
condition|(
name|parameterIndex
operator|>=
name|ParameterIndexSentinel
condition|)
block|{
name|setParameterIndexLarge
argument_list|(
name|parameterIndex
argument_list|)
expr_stmt|;
return|return;
block|}
name|ParmVarDeclBits
operator|.
name|ParameterIndex
operator|=
name|parameterIndex
expr_stmt|;
name|assert
argument_list|(
name|ParmVarDeclBits
operator|.
name|ParameterIndex
operator|==
name|parameterIndex
operator|&&
literal|"truncation!"
argument_list|)
expr_stmt|;
block|}
end_function

begin_expr_stmt
name|unsigned
name|getParameterIndex
argument_list|()
specifier|const
block|{
name|unsigned
name|d
operator|=
name|ParmVarDeclBits
operator|.
name|ParameterIndex
block|;
return|return
name|d
operator|==
name|ParameterIndexSentinel
condition|?
name|getParameterIndexLarge
argument_list|()
else|:
name|d
return|;
block|}
end_expr_stmt

begin_function_decl
name|void
name|setParameterIndexLarge
parameter_list|(
name|unsigned
name|parameterIndex
parameter_list|)
function_decl|;
end_function_decl

begin_expr_stmt
name|unsigned
name|getParameterIndexLarge
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt

begin_comment
unit|};
comment|/// FunctionDecl - An instance of this class is created to represent a
end_comment

begin_comment
comment|/// function declaration or definition.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Since a given function can be declared several times in a program,
end_comment

begin_comment
comment|/// there may be several FunctionDecls that correspond to that
end_comment

begin_comment
comment|/// function. Only one of those FunctionDecls will be found when
end_comment

begin_comment
comment|/// traversing the list of declarations in the context of the
end_comment

begin_comment
comment|/// FunctionDecl (e.g., the translation unit); this FunctionDecl
end_comment

begin_comment
comment|/// contains all of the information known about the function. Other,
end_comment

begin_comment
comment|/// previous declarations of the function are available via the
end_comment

begin_comment
comment|/// getPreviousDecl() chain.
end_comment

begin_decl_stmt
name|class
name|FunctionDecl
range|:
name|public
name|DeclaratorDecl
decl_stmt|,
name|public
name|DeclContext
decl_stmt|,
name|public
name|Redeclarable
decl|<
name|FunctionDecl
decl|>
block|{
name|public
label|:
comment|/// \brief The kind of templated function a FunctionDecl can be.
enum|enum
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
enum|;
name|private
label|:
comment|/// ParamInfo - new[]'d array of pointers to VarDecls for the formal
comment|/// parameters of this function.  This is null if a prototype or if there are
comment|/// no formals.
name|ParmVarDecl
modifier|*
modifier|*
name|ParamInfo
decl_stmt|;
name|LazyDeclStmtPtr
name|Body
decl_stmt|;
comment|// FIXME: This can be packed into the bitfields in DeclContext.
comment|// NOTE: VC++ packs bitfields poorly if the types differ.
name|unsigned
name|SClass
range|:
literal|3
decl_stmt|;
name|unsigned
name|IsInline
range|:
literal|1
decl_stmt|;
name|unsigned
name|IsInlineSpecified
range|:
literal|1
decl_stmt|;
name|protected
label|:
comment|// This is shared by CXXConstructorDecl, CXXConversionDecl, and
comment|// CXXDeductionGuideDecl.
name|unsigned
name|IsExplicitSpecified
range|:
literal|1
decl_stmt|;
name|private
label|:
name|unsigned
name|IsVirtualAsWritten
range|:
literal|1
decl_stmt|;
name|unsigned
name|IsPure
range|:
literal|1
decl_stmt|;
name|unsigned
name|HasInheritedPrototype
range|:
literal|1
decl_stmt|;
name|unsigned
name|HasWrittenPrototype
range|:
literal|1
decl_stmt|;
name|unsigned
name|IsDeleted
range|:
literal|1
decl_stmt|;
name|unsigned
name|IsTrivial
range|:
literal|1
decl_stmt|;
comment|// sunk from CXXMethodDecl
name|unsigned
name|IsDefaulted
range|:
literal|1
decl_stmt|;
comment|// sunk from CXXMethoDecl
name|unsigned
name|IsExplicitlyDefaulted
range|:
literal|1
decl_stmt|;
comment|//sunk from CXXMethodDecl
name|unsigned
name|HasImplicitReturnZero
range|:
literal|1
decl_stmt|;
name|unsigned
name|IsLateTemplateParsed
range|:
literal|1
decl_stmt|;
name|unsigned
name|IsConstexpr
range|:
literal|1
decl_stmt|;
comment|/// \brief Indicates if the function uses __try.
name|unsigned
name|UsesSEHTry
range|:
literal|1
decl_stmt|;
comment|/// \brief Indicates if the function was a definition but its body was
comment|/// skipped.
name|unsigned
name|HasSkippedBody
range|:
literal|1
decl_stmt|;
comment|/// Indicates if the function declaration will have a body, once we're done
comment|/// parsing it.  (We don't set it to false when we're done parsing, in the
comment|/// hopes this is simpler.)
name|unsigned
name|WillHaveBody
range|:
literal|1
decl_stmt|;
comment|/// \brief End part of this FunctionDecl's source range.
comment|///
comment|/// We could compute the full range in getSourceRange(). However, when we're
comment|/// dealing with a function definition deserialized from a PCH/AST file,
comment|/// we can only compute the full range once the function body has been
comment|/// de-serialized, so it's far better to have the (sometimes-redundant)
comment|/// EndRangeLoc.
name|SourceLocation
name|EndRangeLoc
decl_stmt|;
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
operator|,
name|MemberSpecializationInfo
operator|*
operator|,
name|FunctionTemplateSpecializationInfo
operator|*
operator|,
name|DependentFunctionTemplateSpecializationInfo
operator|*
operator|>
name|TemplateOrSpecialization
expr_stmt|;
comment|/// DNLoc - Provides source/type location info for the
comment|/// declaration name embedded in the DeclaratorDecl base class.
name|DeclarationNameLoc
name|DNLoc
decl_stmt|;
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
parameter_list|(
name|ASTContext
modifier|&
name|C
parameter_list|,
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
parameter_list|,
specifier|const
name|TemplateArgumentListInfo
modifier|*
name|TemplateArgsAsWritten
parameter_list|,
name|SourceLocation
name|PointOfInstantiation
parameter_list|)
function_decl|;
comment|/// \brief Specify that this record is an instantiation of the
comment|/// member function FD.
name|void
name|setInstantiationOfMemberFunction
parameter_list|(
name|ASTContext
modifier|&
name|C
parameter_list|,
name|FunctionDecl
modifier|*
name|FD
parameter_list|,
name|TemplateSpecializationKind
name|TSK
parameter_list|)
function_decl|;
name|void
name|setParams
argument_list|(
name|ASTContext
operator|&
name|C
argument_list|,
name|ArrayRef
operator|<
name|ParmVarDecl
operator|*
operator|>
name|NewParamInfo
argument_list|)
decl_stmt|;
name|protected
label|:
name|FunctionDecl
argument_list|(
argument|Kind DK
argument_list|,
argument|ASTContext&C
argument_list|,
argument|DeclContext *DC
argument_list|,
argument|SourceLocation StartLoc
argument_list|,
argument|const DeclarationNameInfo&NameInfo
argument_list|,
argument|QualType T
argument_list|,
argument|TypeSourceInfo *TInfo
argument_list|,
argument|StorageClass S
argument_list|,
argument|bool isInlineSpecified
argument_list|,
argument|bool isConstexprSpecified
argument_list|)
block|:
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
argument_list|,
name|StartLoc
argument_list|)
operator|,
name|DeclContext
argument_list|(
name|DK
argument_list|)
operator|,
name|redeclarable_base
argument_list|(
name|C
argument_list|)
operator|,
name|ParamInfo
argument_list|(
name|nullptr
argument_list|)
operator|,
name|Body
argument_list|()
operator|,
name|SClass
argument_list|(
name|S
argument_list|)
operator|,
name|IsInline
argument_list|(
name|isInlineSpecified
argument_list|)
operator|,
name|IsInlineSpecified
argument_list|(
name|isInlineSpecified
argument_list|)
operator|,
name|IsExplicitSpecified
argument_list|(
name|false
argument_list|)
operator|,
name|IsVirtualAsWritten
argument_list|(
name|false
argument_list|)
operator|,
name|IsPure
argument_list|(
name|false
argument_list|)
operator|,
name|HasInheritedPrototype
argument_list|(
name|false
argument_list|)
operator|,
name|HasWrittenPrototype
argument_list|(
name|true
argument_list|)
operator|,
name|IsDeleted
argument_list|(
name|false
argument_list|)
operator|,
name|IsTrivial
argument_list|(
name|false
argument_list|)
operator|,
name|IsDefaulted
argument_list|(
name|false
argument_list|)
operator|,
name|IsExplicitlyDefaulted
argument_list|(
name|false
argument_list|)
operator|,
name|HasImplicitReturnZero
argument_list|(
name|false
argument_list|)
operator|,
name|IsLateTemplateParsed
argument_list|(
name|false
argument_list|)
operator|,
name|IsConstexpr
argument_list|(
name|isConstexprSpecified
argument_list|)
operator|,
name|UsesSEHTry
argument_list|(
name|false
argument_list|)
operator|,
name|HasSkippedBody
argument_list|(
name|false
argument_list|)
operator|,
name|WillHaveBody
argument_list|(
name|false
argument_list|)
operator|,
name|EndRangeLoc
argument_list|(
name|NameInfo
operator|.
name|getEndLoc
argument_list|()
argument_list|)
operator|,
name|TemplateOrSpecialization
argument_list|()
operator|,
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
name|FunctionDecl
modifier|*
name|getNextRedeclarationImpl
parameter_list|()
function|override
block|{
return|return
name|getNextRedeclaration
argument_list|()
return|;
block|}
name|FunctionDecl
modifier|*
name|getPreviousDeclImpl
parameter_list|()
function|override
block|{
return|return
name|getPreviousDecl
argument_list|()
return|;
block|}
name|FunctionDecl
modifier|*
name|getMostRecentDeclImpl
parameter_list|()
function|override
block|{
return|return
name|getMostRecentDecl
argument_list|()
return|;
block|}
name|public
label|:
typedef|typedef
name|redeclarable_base
operator|::
name|redecl_range
name|redecl_range
expr_stmt|;
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
name|redecls
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
name|using
name|redeclarable_base
operator|::
name|isFirstDecl
expr_stmt|;
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
name|StartLoc
parameter_list|,
name|SourceLocation
name|NLoc
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
name|SC
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
parameter_list|,
name|bool
name|isConstexprSpecified
init|=
name|false
parameter_list|)
block|{
name|DeclarationNameInfo
name|NameInfo
argument_list|(
name|N
argument_list|,
name|NLoc
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
name|StartLoc
argument_list|,
name|NameInfo
argument_list|,
name|T
argument_list|,
name|TInfo
argument_list|,
name|SC
argument_list|,
name|isInlineSpecified
argument_list|,
name|hasWrittenPrototype
argument_list|,
name|isConstexprSpecified
argument_list|)
return|;
block|}
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
name|StartLoc
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
name|SC
parameter_list|,
name|bool
name|isInlineSpecified
parameter_list|,
name|bool
name|hasWrittenPrototype
parameter_list|,
name|bool
name|isConstexprSpecified
init|=
name|false
parameter_list|)
function_decl|;
specifier|static
name|FunctionDecl
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
name|void
name|getNameForDiagnostic
argument_list|(
name|raw_ostream
operator|&
name|OS
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
name|override
decl_stmt|;
name|void
name|setRangeEnd
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
name|SourceRange
name|getSourceRange
argument_list|()
specifier|const
name|override
name|LLVM_READONLY
expr_stmt|;
comment|/// \brief Returns true if the function has a body (definition). The
comment|/// function body might be in any of the (re-)declarations of this
comment|/// function. The variant that accepts a FunctionDecl pointer will
comment|/// set that function declaration to the actual declaration
comment|/// containing the body (if there is one).
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
name|bool
name|hasBody
argument_list|()
specifier|const
name|override
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
comment|/// hasTrivialBody - Returns whether the function has a trivial body that does
comment|/// not require any specific codegen.
name|bool
name|hasTrivialBody
argument_list|()
specifier|const
expr_stmt|;
comment|/// isDefined - Returns true if the function is defined at all, including
comment|/// a deleted definition. Except for the behavior when the function is
comment|/// deleted, behaves like hasBody.
name|bool
name|isDefined
argument_list|(
specifier|const
name|FunctionDecl
operator|*
operator|&
name|Definition
argument_list|)
decl|const
decl_stmt|;
name|virtual
name|bool
name|isDefined
argument_list|()
specifier|const
block|{
specifier|const
name|FunctionDecl
operator|*
name|Definition
block|;
return|return
name|isDefined
argument_list|(
name|Definition
argument_list|)
return|;
block|}
comment|/// \brief Get the definition for this declaration.
name|FunctionDecl
modifier|*
name|getDefinition
parameter_list|()
block|{
specifier|const
name|FunctionDecl
modifier|*
name|Definition
decl_stmt|;
if|if
condition|(
name|isDefined
argument_list|(
name|Definition
argument_list|)
condition|)
return|return
name|const_cast
operator|<
name|FunctionDecl
operator|*
operator|>
operator|(
name|Definition
operator|)
return|;
return|return
name|nullptr
return|;
block|}
specifier|const
name|FunctionDecl
operator|*
name|getDefinition
argument_list|()
specifier|const
block|{
return|return
name|const_cast
operator|<
name|FunctionDecl
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
comment|/// getBody - Retrieve the body (definition) of the function. The
comment|/// function body might be in any of the (re-)declarations of this
comment|/// function. The variant that accepts a FunctionDecl pointer will
comment|/// set that function declaration to the actual declaration
comment|/// containing the body (if there is one).
comment|/// NOTE: For checking if there is a body, use hasBody() instead, to avoid
comment|/// unnecessary AST de-serialization of the body.
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
name|Stmt
operator|*
name|getBody
argument_list|()
specifier|const
name|override
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
comment|/// isThisDeclarationADefinition - Returns whether this specific
comment|/// declaration of the function is also a definition. This does not
comment|/// determine whether the function has been defined (e.g., in a
comment|/// previous definition); for that information, use isDefined. Note
comment|/// that this returns false for a defaulted function unless that function
comment|/// has been implicitly defined (possibly as deleted).
name|bool
name|isThisDeclarationADefinition
argument_list|()
specifier|const
block|{
return|return
name|IsDeleted
operator|||
name|Body
operator|||
name|IsLateTemplateParsed
return|;
block|}
comment|/// doesThisDeclarationHaveABody - Returns whether this specific
comment|/// declaration of the function has a body - that is, if it is a non-
comment|/// deleted definition.
name|bool
name|doesThisDeclarationHaveABody
argument_list|()
specifier|const
block|{
return|return
name|Body
operator|||
name|IsLateTemplateParsed
return|;
block|}
name|void
name|setBody
parameter_list|(
name|Stmt
modifier|*
name|B
parameter_list|)
function_decl|;
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
comment|/// Whether this function is variadic.
name|bool
name|isVariadic
argument_list|()
specifier|const
expr_stmt|;
comment|/// Whether this function is marked as virtual explicitly.
name|bool
name|isVirtualAsWritten
argument_list|()
specifier|const
block|{
return|return
name|IsVirtualAsWritten
return|;
block|}
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
comment|/// Whether this virtual function is pure, i.e. makes the containing class
comment|/// abstract.
name|bool
name|isPure
argument_list|()
specifier|const
block|{
return|return
name|IsPure
return|;
block|}
name|void
name|setPure
parameter_list|(
name|bool
name|P
init|=
name|true
parameter_list|)
function_decl|;
comment|/// Whether this templated function will be late parsed.
name|bool
name|isLateTemplateParsed
argument_list|()
specifier|const
block|{
return|return
name|IsLateTemplateParsed
return|;
block|}
name|void
name|setLateTemplateParsed
parameter_list|(
name|bool
name|ILT
init|=
name|true
parameter_list|)
block|{
name|IsLateTemplateParsed
operator|=
name|ILT
expr_stmt|;
block|}
comment|/// Whether this function is "trivial" in some specialized C++ senses.
comment|/// Can only be true for default constructors, copy constructors,
comment|/// copy assignment operators, and destructors.  Not meaningful until
comment|/// the class has been fully built by Sema.
name|bool
name|isTrivial
argument_list|()
specifier|const
block|{
return|return
name|IsTrivial
return|;
block|}
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
comment|/// Whether this function is defaulted per C++0x. Only valid for
comment|/// special member functions.
name|bool
name|isDefaulted
argument_list|()
specifier|const
block|{
return|return
name|IsDefaulted
return|;
block|}
name|void
name|setDefaulted
parameter_list|(
name|bool
name|D
init|=
name|true
parameter_list|)
block|{
name|IsDefaulted
operator|=
name|D
expr_stmt|;
block|}
comment|/// Whether this function is explicitly defaulted per C++0x. Only valid
comment|/// for special member functions.
name|bool
name|isExplicitlyDefaulted
argument_list|()
specifier|const
block|{
return|return
name|IsExplicitlyDefaulted
return|;
block|}
name|void
name|setExplicitlyDefaulted
parameter_list|(
name|bool
name|ED
init|=
name|true
parameter_list|)
block|{
name|IsExplicitlyDefaulted
operator|=
name|ED
expr_stmt|;
block|}
comment|/// Whether falling off this function implicitly returns null/zero.
comment|/// If a more specific implicit return value is required, front-ends
comment|/// should synthesize the appropriate return statements.
name|bool
name|hasImplicitReturnZero
argument_list|()
specifier|const
block|{
return|return
name|HasImplicitReturnZero
return|;
block|}
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
comment|/// \brief Whether this function has a prototype, either because one
comment|/// was explicitly written or because it was "inherited" by merging
comment|/// a declaration without a prototype with a declaration that has a
comment|/// prototype.
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
name|bool
name|hasWrittenPrototype
argument_list|()
specifier|const
block|{
return|return
name|HasWrittenPrototype
return|;
block|}
comment|/// \brief Whether this function inherited its prototype from a
comment|/// previous declaration.
name|bool
name|hasInheritedPrototype
argument_list|()
specifier|const
block|{
return|return
name|HasInheritedPrototype
return|;
block|}
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
comment|/// Whether this is a (C++11) constexpr function or constexpr constructor.
name|bool
name|isConstexpr
argument_list|()
specifier|const
block|{
return|return
name|IsConstexpr
return|;
block|}
name|void
name|setConstexpr
parameter_list|(
name|bool
name|IC
parameter_list|)
block|{
name|IsConstexpr
operator|=
name|IC
expr_stmt|;
block|}
comment|/// \brief Indicates the function uses __try.
name|bool
name|usesSEHTry
argument_list|()
specifier|const
block|{
return|return
name|UsesSEHTry
return|;
block|}
name|void
name|setUsesSEHTry
parameter_list|(
name|bool
name|UST
parameter_list|)
block|{
name|UsesSEHTry
operator|=
name|UST
expr_stmt|;
block|}
comment|/// \brief Whether this function has been deleted.
comment|///
comment|/// A function that is "deleted" (via the C++0x "= delete" syntax)
comment|/// acts like a normal function, except that it cannot actually be
comment|/// called or have its address taken. Deleted functions are
comment|/// typically used in C++ overload resolution to attract arguments
comment|/// whose type or lvalue/rvalue-ness would permit the use of a
comment|/// different overload that would behave incorrectly. For example,
comment|/// one might use deleted functions to ban implicit conversion from
comment|/// a floating-point number to an Integer type:
comment|///
comment|/// @code
comment|/// struct Integer {
comment|///   Integer(long); // construct from a long
comment|///   Integer(double) = delete; // no construction from float or double
comment|///   Integer(long double) = delete; // no construction from long double
comment|/// };
comment|/// @endcode
comment|// If a function is deleted, its first declaration must be.
name|bool
name|isDeleted
argument_list|()
specifier|const
block|{
return|return
name|getCanonicalDecl
argument_list|()
operator|->
name|IsDeleted
return|;
block|}
name|bool
name|isDeletedAsWritten
argument_list|()
specifier|const
block|{
return|return
name|IsDeleted
operator|&&
operator|!
name|IsDefaulted
return|;
block|}
name|void
name|setDeletedAsWritten
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
comment|/// \brief Determines whether this function is "main", which is the
comment|/// entry point into an executable program.
name|bool
name|isMain
argument_list|()
specifier|const
expr_stmt|;
comment|/// \brief Determines whether this function is a MSVCRT user defined entry
comment|/// point.
name|bool
name|isMSVCRTEntryPoint
argument_list|()
specifier|const
expr_stmt|;
comment|/// \brief Determines whether this operator new or delete is one
comment|/// of the reserved global placement operators:
comment|///    void *operator new(size_t, void *);
comment|///    void *operator new[](size_t, void *);
comment|///    void operator delete(void *, void *);
comment|///    void operator delete[](void *, void *);
comment|/// These functions have special behavior under [new.delete.placement]:
comment|///    These functions are reserved, a C++ program may not define
comment|///    functions that displace the versions in the Standard C++ library.
comment|///    The provisions of [basic.stc.dynamic] do not apply to these
comment|///    reserved placement forms of operator new and operator delete.
comment|///
comment|/// This function must be an allocation or deallocation function.
name|bool
name|isReservedGlobalPlacementOperator
argument_list|()
specifier|const
expr_stmt|;
comment|/// \brief Determines whether this function is one of the replaceable
comment|/// global allocation functions:
comment|///    void *operator new(size_t);
comment|///    void *operator new(size_t, const std::nothrow_t&) noexcept;
comment|///    void *operator new[](size_t);
comment|///    void *operator new[](size_t, const std::nothrow_t&) noexcept;
comment|///    void operator delete(void *) noexcept;
comment|///    void operator delete(void *, std::size_t) noexcept;      [C++1y]
comment|///    void operator delete(void *, const std::nothrow_t&) noexcept;
comment|///    void operator delete[](void *) noexcept;
comment|///    void operator delete[](void *, std::size_t) noexcept;    [C++1y]
comment|///    void operator delete[](void *, const std::nothrow_t&) noexcept;
comment|/// These functions have special behavior under C++1y [expr.new]:
comment|///    An implementation is allowed to omit a call to a replaceable global
comment|///    allocation function. [...]
name|bool
name|isReplaceableGlobalAllocationFunction
argument_list|()
specifier|const
expr_stmt|;
comment|/// Compute the language linkage.
name|LanguageLinkage
name|getLanguageLinkage
argument_list|()
specifier|const
expr_stmt|;
comment|/// \brief Determines whether this function is a function with
comment|/// external, C linkage.
name|bool
name|isExternC
argument_list|()
specifier|const
expr_stmt|;
comment|/// \brief Determines whether this function's context is, or is nested within,
comment|/// a C++ extern "C" linkage spec.
name|bool
name|isInExternCContext
argument_list|()
specifier|const
expr_stmt|;
comment|/// \brief Determines whether this function's context is, or is nested within,
comment|/// a C++ extern "C++" linkage spec.
name|bool
name|isInExternCXXContext
argument_list|()
specifier|const
expr_stmt|;
comment|/// \brief Determines whether this is a global function.
name|bool
name|isGlobal
argument_list|()
specifier|const
expr_stmt|;
comment|/// \brief Determines whether this function is known to be 'noreturn', through
comment|/// an attribute on its declaration or its type.
name|bool
name|isNoReturn
argument_list|()
specifier|const
expr_stmt|;
comment|/// \brief True if the function was a definition but its body was skipped.
name|bool
name|hasSkippedBody
argument_list|()
specifier|const
block|{
return|return
name|HasSkippedBody
return|;
block|}
name|void
name|setHasSkippedBody
parameter_list|(
name|bool
name|Skipped
init|=
name|true
parameter_list|)
block|{
name|HasSkippedBody
operator|=
name|Skipped
expr_stmt|;
block|}
comment|/// True if this function will eventually have a body, once it's fully parsed.
name|bool
name|willHaveBody
argument_list|()
specifier|const
block|{
return|return
name|WillHaveBody
return|;
block|}
name|void
name|setWillHaveBody
parameter_list|(
name|bool
name|V
init|=
name|true
parameter_list|)
block|{
name|WillHaveBody
operator|=
name|V
expr_stmt|;
block|}
name|void
name|setPreviousDeclaration
parameter_list|(
name|FunctionDecl
modifier|*
name|PrevDecl
parameter_list|)
function_decl|;
name|FunctionDecl
operator|*
name|getCanonicalDecl
argument_list|()
name|override
expr_stmt|;
specifier|const
name|FunctionDecl
operator|*
name|getCanonicalDecl
argument_list|()
specifier|const
block|{
return|return
name|const_cast
operator|<
name|FunctionDecl
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
name|unsigned
name|getBuiltinID
argument_list|()
specifier|const
expr_stmt|;
comment|// ArrayRef interface to parameters.
name|ArrayRef
operator|<
name|ParmVarDecl
operator|*
operator|>
name|parameters
argument_list|()
specifier|const
block|{
return|return
block|{
name|ParamInfo
block|,
name|getNumParams
argument_list|()
block|}
return|;
block|}
name|MutableArrayRef
operator|<
name|ParmVarDecl
operator|*
operator|>
name|parameters
argument_list|()
block|{
return|return
block|{
name|ParamInfo
block|,
name|getNumParams
argument_list|()
block|}
return|;
block|}
comment|// Iterator access to formal parameters.
typedef|typedef
name|MutableArrayRef
operator|<
name|ParmVarDecl
operator|*
operator|>
operator|::
name|iterator
name|param_iterator
expr_stmt|;
typedef|typedef
name|ArrayRef
operator|<
name|ParmVarDecl
operator|*
operator|>
operator|::
name|const_iterator
name|param_const_iterator
expr_stmt|;
name|bool
name|param_empty
argument_list|()
specifier|const
block|{
return|return
name|parameters
argument_list|()
operator|.
name|empty
argument_list|()
return|;
block|}
name|param_iterator
name|param_begin
parameter_list|()
block|{
return|return
name|parameters
argument_list|()
operator|.
name|begin
argument_list|()
return|;
block|}
name|param_iterator
name|param_end
parameter_list|()
block|{
return|return
name|parameters
argument_list|()
operator|.
name|end
argument_list|()
return|;
block|}
name|param_const_iterator
name|param_begin
argument_list|()
specifier|const
block|{
return|return
name|parameters
argument_list|()
operator|.
name|begin
argument_list|()
return|;
block|}
name|param_const_iterator
name|param_end
argument_list|()
specifier|const
block|{
return|return
name|parameters
argument_list|()
operator|.
name|end
argument_list|()
return|;
block|}
name|size_t
name|param_size
argument_list|()
specifier|const
block|{
return|return
name|parameters
argument_list|()
operator|.
name|size
argument_list|()
return|;
block|}
comment|/// getNumParams - Return the number of parameters this function must have
comment|/// based on its FunctionType.  This is the length of the ParamInfo array
comment|/// after it has been created.
name|unsigned
name|getNumParams
argument_list|()
specifier|const
expr_stmt|;
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
name|void
name|setParams
argument_list|(
name|ArrayRef
operator|<
name|ParmVarDecl
operator|*
operator|>
name|NewParamInfo
argument_list|)
block|{
name|setParams
argument_list|(
name|getASTContext
argument_list|()
argument_list|,
name|NewParamInfo
argument_list|)
expr_stmt|;
block|}
comment|/// getMinRequiredArguments - Returns the minimum number of arguments
comment|/// needed to call this function. This may be fewer than the number of
comment|/// function parameters, if some of the parameters have default
comment|/// arguments (in C++).
name|unsigned
name|getMinRequiredArguments
argument_list|()
specifier|const
expr_stmt|;
name|QualType
name|getReturnType
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
name|getType
argument_list|()
operator|->
name|getAs
operator|<
name|FunctionType
operator|>
operator|(
operator|)
operator|&&
literal|"Expected a FunctionType!"
argument_list|)
block|;
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
name|getReturnType
argument_list|()
return|;
block|}
comment|/// \brief Attempt to compute an informative source range covering the
comment|/// function return type. This may omit qualifiers and other information with
comment|/// limited representation in the AST.
name|SourceRange
name|getReturnTypeSourceRange
argument_list|()
specifier|const
expr_stmt|;
comment|/// \brief Attempt to compute an informative source range covering the
comment|/// function exception specification, if any.
name|SourceRange
name|getExceptionSpecSourceRange
argument_list|()
specifier|const
expr_stmt|;
comment|/// \brief Determine the type of an expression that calls this function.
name|QualType
name|getCallResultType
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
name|getType
argument_list|()
operator|->
name|getAs
operator|<
name|FunctionType
operator|>
operator|(
operator|)
operator|&&
literal|"Expected a FunctionType!"
argument_list|)
block|;
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
comment|/// \brief Returns the WarnUnusedResultAttr that is either declared on this
comment|/// function, or its return type declaration.
specifier|const
name|Attr
operator|*
name|getUnusedResultAttr
argument_list|()
specifier|const
expr_stmt|;
comment|/// \brief Returns true if this function or its return type has the
comment|/// warn_unused_result attribute. If the return type has the attribute and
comment|/// this function is a method of the return type's class, then false will be
comment|/// returned to avoid spurious warnings on member methods such as assignment
comment|/// operators.
name|bool
name|hasUnusedResultAttr
argument_list|()
specifier|const
block|{
return|return
name|getUnusedResultAttr
argument_list|()
operator|!=
name|nullptr
return|;
block|}
comment|/// \brief Returns the storage class as written in the source. For the
comment|/// computed linkage of symbol, see getLinkage.
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
comment|/// \brief Determine whether the "inline" keyword was specified for this
comment|/// function.
name|bool
name|isInlineSpecified
argument_list|()
specifier|const
block|{
return|return
name|IsInlineSpecified
return|;
block|}
comment|/// Set whether the "inline" keyword was specified for this function.
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
comment|/// Flag that this function is implicitly inline.
name|void
name|setImplicitlyInline
parameter_list|()
block|{
name|IsInline
operator|=
name|true
expr_stmt|;
block|}
comment|/// \brief Determine whether this function should be inlined, because it is
comment|/// either marked "inline" or "constexpr" or is a member function of a class
comment|/// that was defined in the class body.
name|bool
name|isInlined
argument_list|()
specifier|const
block|{
return|return
name|IsInline
return|;
block|}
name|bool
name|isInlineDefinitionExternallyVisible
argument_list|()
specifier|const
expr_stmt|;
name|bool
name|isMSExternInline
argument_list|()
specifier|const
expr_stmt|;
name|bool
name|doesDeclarationForceExternallyVisibleDefinition
argument_list|()
specifier|const
expr_stmt|;
comment|/// isOverloadedOperator - Whether this function declaration
comment|/// represents an C++ overloaded operator, e.g., "operator+".
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
name|OverloadedOperatorKind
name|getOverloadedOperator
argument_list|()
specifier|const
expr_stmt|;
specifier|const
name|IdentifierInfo
operator|*
name|getLiteralIdentifier
argument_list|()
specifier|const
expr_stmt|;
comment|/// \brief If this function is an instantiation of a member function
comment|/// of a class template specialization, retrieves the function from
comment|/// which it was instantiated.
comment|///
comment|/// This routine will return non-NULL for (non-templated) member
comment|/// functions of class templates and for instantiations of function
comment|/// templates. For example, given:
comment|///
comment|/// \code
comment|/// template<typename T>
comment|/// struct X {
comment|///   void f(T);
comment|/// };
comment|/// \endcode
comment|///
comment|/// The declaration for X<int>::f is a (non-templated) FunctionDecl
comment|/// whose parent is the class template specialization X<int>. For
comment|/// this declaration, getInstantiatedFromFunction() will return
comment|/// the FunctionDecl X<T>::A. When a complete definition of
comment|/// X<int>::A is required, it will be instantiated from the
comment|/// declaration returned by getInstantiatedFromMemberFunction().
name|FunctionDecl
operator|*
name|getInstantiatedFromMemberFunction
argument_list|()
specifier|const
expr_stmt|;
comment|/// \brief What kind of templated function this is.
name|TemplatedKind
name|getTemplatedKind
argument_list|()
specifier|const
expr_stmt|;
comment|/// \brief If this function is an instantiation of a member function of a
comment|/// class template specialization, retrieves the member specialization
comment|/// information.
name|MemberSpecializationInfo
operator|*
name|getMemberSpecializationInfo
argument_list|()
specifier|const
expr_stmt|;
comment|/// \brief Specify that this record is an instantiation of the
comment|/// member function FD.
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
comment|/// \brief Retrieves the function template that is described by this
comment|/// function declaration.
comment|///
comment|/// Every function template is represented as a FunctionTemplateDecl
comment|/// and a FunctionDecl (or something derived from FunctionDecl). The
comment|/// former contains template properties (such as the template
comment|/// parameter lists) while the latter contains the actual
comment|/// description of the template's
comment|/// contents. FunctionTemplateDecl::getTemplatedDecl() retrieves the
comment|/// FunctionDecl that describes the function template,
comment|/// getDescribedFunctionTemplate() retrieves the
comment|/// FunctionTemplateDecl from a FunctionDecl.
name|FunctionTemplateDecl
operator|*
name|getDescribedFunctionTemplate
argument_list|()
specifier|const
expr_stmt|;
name|void
name|setDescribedFunctionTemplate
parameter_list|(
name|FunctionTemplateDecl
modifier|*
name|Template
parameter_list|)
function_decl|;
comment|/// \brief Determine whether this function is a function template
comment|/// specialization.
name|bool
name|isFunctionTemplateSpecialization
argument_list|()
specifier|const
block|{
return|return
name|getPrimaryTemplate
argument_list|()
operator|!=
name|nullptr
return|;
block|}
comment|/// \brief Retrieve the class scope template pattern that this function
comment|///  template specialization is instantiated from.
name|FunctionDecl
operator|*
name|getClassScopeSpecializationPattern
argument_list|()
specifier|const
expr_stmt|;
comment|/// \brief If this function is actually a function template specialization,
comment|/// retrieve information about this function template specialization.
comment|/// Otherwise, returns NULL.
name|FunctionTemplateSpecializationInfo
operator|*
name|getTemplateSpecializationInfo
argument_list|()
specifier|const
expr_stmt|;
comment|/// \brief Determines whether this function is a function template
comment|/// specialization or a member of a class template specialization that can
comment|/// be implicitly instantiated.
name|bool
name|isImplicitlyInstantiable
argument_list|()
specifier|const
expr_stmt|;
comment|/// \brief Determines if the given function was instantiated from a
comment|/// function template.
name|bool
name|isTemplateInstantiation
argument_list|()
specifier|const
expr_stmt|;
comment|/// \brief Retrieve the function declaration from which this function could
comment|/// be instantiated, if it is an instantiation (rather than a non-template
comment|/// or a specialization, for example).
name|FunctionDecl
operator|*
name|getTemplateInstantiationPattern
argument_list|()
specifier|const
expr_stmt|;
comment|/// \brief Retrieve the primary template that this function template
comment|/// specialization either specializes or was instantiated from.
comment|///
comment|/// If this function declaration is not a function template specialization,
comment|/// returns NULL.
name|FunctionTemplateDecl
operator|*
name|getPrimaryTemplate
argument_list|()
specifier|const
expr_stmt|;
comment|/// \brief Retrieve the template arguments used to produce this function
comment|/// template specialization from the primary template.
comment|///
comment|/// If this function declaration is not a function template specialization,
comment|/// returns NULL.
specifier|const
name|TemplateArgumentList
operator|*
name|getTemplateSpecializationArgs
argument_list|()
specifier|const
expr_stmt|;
comment|/// \brief Retrieve the template argument list as written in the sources,
comment|/// if any.
comment|///
comment|/// If this function declaration is not a function template specialization
comment|/// or if it had no explicit template argument list, returns NULL.
comment|/// Note that it an explicit template argument list may be written empty,
comment|/// e.g., template<> void foo<>(char* s);
specifier|const
name|ASTTemplateArgumentListInfo
operator|*
name|getTemplateSpecializationArgsAsWritten
argument_list|()
specifier|const
expr_stmt|;
comment|/// \brief Specify that this function declaration is actually a function
comment|/// template specialization.
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
name|nullptr
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
comment|/// \brief Specifies that this function declaration is actually a
comment|/// dependent function template specialization.
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
name|DependentFunctionTemplateSpecializationInfo
operator|*
name|getDependentSpecializationInfo
argument_list|()
specifier|const
expr_stmt|;
comment|/// \brief Determine what kind of template instantiation this function
comment|/// represents.
name|TemplateSpecializationKind
name|getTemplateSpecializationKind
argument_list|()
specifier|const
expr_stmt|;
comment|/// \brief Determine what kind of template instantiation this function
comment|/// represents.
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
comment|/// \brief Retrieve the (first) point of instantiation of a function template
comment|/// specialization or a member of a class template specialization.
comment|///
comment|/// \returns the first point of instantiation, if this function was
comment|/// instantiated from a template; otherwise, returns an invalid source
comment|/// location.
name|SourceLocation
name|getPointOfInstantiation
argument_list|()
specifier|const
expr_stmt|;
comment|/// \brief Determine whether this is or was instantiated from an out-of-line
comment|/// definition of a member function.
name|bool
name|isOutOfLine
argument_list|()
specifier|const
name|override
expr_stmt|;
comment|/// \brief Identify a memory copying or setting function.
comment|/// If the given function is a memory copy or setting function, returns
comment|/// the corresponding Builtin ID. If the function is not a memory function,
comment|/// returns 0.
name|unsigned
name|getMemoryFunctionKind
argument_list|()
specifier|const
expr_stmt|;
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
decl_stmt|,
name|public
name|Mergeable
decl|<
name|FieldDecl
decl|>
block|{
comment|// FIXME: This can be packed into the bitfields in Decl.
name|unsigned
name|Mutable
range|:
literal|1
decl_stmt|;
name|mutable
name|unsigned
name|CachedFieldIndex
range|:
literal|31
decl_stmt|;
comment|/// The kinds of value we can store in InitializerOrBitWidth.
comment|///
comment|/// Note that this is compatible with InClassInitStyle except for
comment|/// ISK_CapturedVLAType.
enum|enum
name|InitStorageKind
block|{
comment|/// If the pointer is null, there's nothing special.  Otherwise,
comment|/// this is a bitfield and the pointer is the Expr* storing the
comment|/// bit-width.
name|ISK_BitWidthOrNothing
init|=
operator|(
name|unsigned
operator|)
name|ICIS_NoInit
block|,
comment|/// The pointer is an (optional due to delayed parsing) Expr*
comment|/// holding the copy-initializer.
name|ISK_InClassCopyInit
init|=
operator|(
name|unsigned
operator|)
name|ICIS_CopyInit
block|,
comment|/// The pointer is an (optional due to delayed parsing) Expr*
comment|/// holding the list-initializer.
name|ISK_InClassListInit
init|=
operator|(
name|unsigned
operator|)
name|ICIS_ListInit
block|,
comment|/// The pointer is a VariableArrayType* that's been captured;
comment|/// the enclosing context is a lambda or captured statement.
name|ISK_CapturedVLAType
block|,   }
enum|;
comment|/// \brief Storage for either the bit-width, the in-class
comment|/// initializer, or the captured variable length array bound.
comment|///
comment|/// We can safely combine these because in-class initializers are
comment|/// not permitted for bit-fields, and both are exclusive with VLA
comment|/// captures.
comment|///
comment|/// If the storage kind is ISK_InClassCopyInit or
comment|/// ISK_InClassListInit, but the initializer is null, then this
comment|/// field has an in-class initializer which has not yet been parsed
comment|/// and attached.
name|llvm
operator|::
name|PointerIntPair
operator|<
name|void
operator|*
operator|,
literal|2
operator|,
name|InitStorageKind
operator|>
name|InitStorage
expr_stmt|;
name|protected
label|:
name|FieldDecl
argument_list|(
argument|Kind DK
argument_list|,
argument|DeclContext *DC
argument_list|,
argument|SourceLocation StartLoc
argument_list|,
argument|SourceLocation IdLoc
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
argument_list|,
argument|InClassInitStyle InitStyle
argument_list|)
block|:
name|DeclaratorDecl
argument_list|(
name|DK
argument_list|,
name|DC
argument_list|,
name|IdLoc
argument_list|,
name|Id
argument_list|,
name|T
argument_list|,
name|TInfo
argument_list|,
name|StartLoc
argument_list|)
operator|,
name|Mutable
argument_list|(
name|Mutable
argument_list|)
operator|,
name|CachedFieldIndex
argument_list|(
literal|0
argument_list|)
operator|,
name|InitStorage
argument_list|(
argument|BW
argument_list|,
argument|(InitStorageKind) InitStyle
argument_list|)
block|{
name|assert
argument_list|(
operator|(
operator|!
name|BW
operator|||
name|InitStyle
operator|==
name|ICIS_NoInit
operator|)
operator|&&
literal|"got initializer for bitfield"
argument_list|)
block|;   }
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
argument|SourceLocation StartLoc
argument_list|,
argument|SourceLocation IdLoc
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
argument_list|,
argument|InClassInitStyle InitStyle
argument_list|)
expr_stmt|;
specifier|static
name|FieldDecl
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
comment|/// getFieldIndex - Returns the index of this field within its record,
comment|/// as appropriate for passing to ASTRecordLayout::getFieldOffset.
name|unsigned
name|getFieldIndex
argument_list|()
specifier|const
expr_stmt|;
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
comment|/// \brief Determines whether this field is a bitfield.
name|bool
name|isBitField
argument_list|()
specifier|const
block|{
return|return
name|InitStorage
operator|.
name|getInt
argument_list|()
operator|==
name|ISK_BitWidthOrNothing
operator|&&
name|InitStorage
operator|.
name|getPointer
argument_list|()
operator|!=
name|nullptr
return|;
block|}
comment|/// @brief Determines whether this is an unnamed bitfield.
name|bool
name|isUnnamedBitfield
argument_list|()
specifier|const
block|{
return|return
name|isBitField
argument_list|()
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
expr_stmt|;
name|Expr
operator|*
name|getBitWidth
argument_list|()
specifier|const
block|{
return|return
name|isBitField
argument_list|()
operator|?
name|static_cast
operator|<
name|Expr
operator|*
operator|>
operator|(
name|InitStorage
operator|.
name|getPointer
argument_list|()
operator|)
operator|:
name|nullptr
return|;
block|}
name|unsigned
name|getBitWidthValue
argument_list|(
specifier|const
name|ASTContext
operator|&
name|Ctx
argument_list|)
decl|const
decl_stmt|;
comment|/// setBitWidth - Set the bit-field width for this member.
comment|// Note: used by some clients (i.e., do not remove it).
name|void
name|setBitWidth
parameter_list|(
name|Expr
modifier|*
name|Width
parameter_list|)
block|{
name|assert
argument_list|(
name|InitStorage
operator|.
name|getInt
argument_list|()
operator|==
name|ISK_BitWidthOrNothing
operator|&&
name|InitStorage
operator|.
name|getPointer
argument_list|()
operator|==
name|nullptr
operator|&&
literal|"bit width, initializer or captured type already set"
argument_list|)
expr_stmt|;
name|InitStorage
operator|.
name|setPointerAndInt
argument_list|(
name|Width
argument_list|,
name|ISK_BitWidthOrNothing
argument_list|)
expr_stmt|;
block|}
comment|/// removeBitWidth - Remove the bit-field width from this member.
comment|// Note: used by some clients (i.e., do not remove it).
name|void
name|removeBitWidth
parameter_list|()
block|{
name|assert
argument_list|(
name|isBitField
argument_list|()
operator|&&
literal|"no bitfield width to remove"
argument_list|)
expr_stmt|;
name|InitStorage
operator|.
name|setPointerAndInt
argument_list|(
name|nullptr
argument_list|,
name|ISK_BitWidthOrNothing
argument_list|)
expr_stmt|;
block|}
comment|/// getInClassInitStyle - Get the kind of (C++11) in-class initializer which
comment|/// this field has.
name|InClassInitStyle
name|getInClassInitStyle
argument_list|()
specifier|const
block|{
name|InitStorageKind
name|storageKind
operator|=
name|InitStorage
operator|.
name|getInt
argument_list|()
block|;
return|return
operator|(
name|storageKind
operator|==
name|ISK_CapturedVLAType
condition|?
name|ICIS_NoInit
else|:
operator|(
name|InClassInitStyle
operator|)
name|storageKind
operator|)
return|;
block|}
comment|/// hasInClassInitializer - Determine whether this member has a C++11 in-class
comment|/// initializer.
name|bool
name|hasInClassInitializer
argument_list|()
specifier|const
block|{
return|return
name|getInClassInitStyle
argument_list|()
operator|!=
name|ICIS_NoInit
return|;
block|}
comment|/// getInClassInitializer - Get the C++11 in-class initializer for this
comment|/// member, or null if one has not been set. If a valid declaration has an
comment|/// in-class initializer, but this returns null, then we have not parsed and
comment|/// attached it yet.
name|Expr
operator|*
name|getInClassInitializer
argument_list|()
specifier|const
block|{
return|return
name|hasInClassInitializer
argument_list|()
operator|?
name|static_cast
operator|<
name|Expr
operator|*
operator|>
operator|(
name|InitStorage
operator|.
name|getPointer
argument_list|()
operator|)
operator|:
name|nullptr
return|;
block|}
comment|/// setInClassInitializer - Set the C++11 in-class initializer for this
comment|/// member.
name|void
name|setInClassInitializer
parameter_list|(
name|Expr
modifier|*
name|Init
parameter_list|)
block|{
name|assert
argument_list|(
name|hasInClassInitializer
argument_list|()
operator|&&
name|InitStorage
operator|.
name|getPointer
argument_list|()
operator|==
name|nullptr
operator|&&
literal|"bit width, initializer or captured type already set"
argument_list|)
expr_stmt|;
name|InitStorage
operator|.
name|setPointer
argument_list|(
name|Init
argument_list|)
expr_stmt|;
block|}
comment|/// removeInClassInitializer - Remove the C++11 in-class initializer from this
comment|/// member.
name|void
name|removeInClassInitializer
parameter_list|()
block|{
name|assert
argument_list|(
name|hasInClassInitializer
argument_list|()
operator|&&
literal|"no initializer to remove"
argument_list|)
expr_stmt|;
name|InitStorage
operator|.
name|setPointerAndInt
argument_list|(
name|nullptr
argument_list|,
name|ISK_BitWidthOrNothing
argument_list|)
expr_stmt|;
block|}
comment|/// \brief Determine whether this member captures the variable length array
comment|/// type.
name|bool
name|hasCapturedVLAType
argument_list|()
specifier|const
block|{
return|return
name|InitStorage
operator|.
name|getInt
argument_list|()
operator|==
name|ISK_CapturedVLAType
return|;
block|}
comment|/// \brief Get the captured variable length array type.
specifier|const
name|VariableArrayType
operator|*
name|getCapturedVLAType
argument_list|()
specifier|const
block|{
return|return
name|hasCapturedVLAType
argument_list|()
operator|?
name|static_cast
operator|<
specifier|const
name|VariableArrayType
operator|*
operator|>
operator|(
name|InitStorage
operator|.
name|getPointer
argument_list|()
operator|)
operator|:
name|nullptr
return|;
block|}
comment|/// \brief Set the captured variable length array type for this field.
name|void
name|setCapturedVLAType
parameter_list|(
specifier|const
name|VariableArrayType
modifier|*
name|VLAType
parameter_list|)
function_decl|;
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
modifier|*
name|getParent
parameter_list|()
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
name|SourceRange
name|getSourceRange
argument_list|()
specifier|const
name|override
name|LLVM_READONLY
expr_stmt|;
comment|/// Retrieves the canonical declaration of this field.
name|FieldDecl
modifier|*
name|getCanonicalDecl
parameter_list|()
function|override
block|{
return|return
name|getFirstDecl
argument_list|()
return|;
block|}
specifier|const
name|FieldDecl
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
name|classofKind
parameter_list|(
name|Kind
name|K
parameter_list|)
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
comment|/// EnumConstantDecl - An instance of this object exists for each enum constant
end_comment

begin_comment
comment|/// that is defined.  For example, in "enum X {a,b}", each of a/b are
end_comment

begin_comment
comment|/// EnumConstantDecl's, X is an instance of EnumDecl, and the type of a/b is a
end_comment

begin_comment
comment|/// TagType for the X EnumDecl.
end_comment

begin_decl_stmt
name|class
name|EnumConstantDecl
range|:
name|public
name|ValueDecl
decl_stmt|,
name|public
name|Mergeable
decl|<
name|EnumConstantDecl
decl|>
block|{
name|Stmt
modifier|*
name|Init
decl_stmt|;
comment|// an integer constant expression
name|llvm
operator|::
name|APSInt
name|Val
expr_stmt|;
comment|// The value.
name|protected
label|:
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
block|:
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
operator|,
name|Init
argument_list|(
operator|(
name|Stmt
operator|*
operator|)
name|E
argument_list|)
operator|,
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
expr_stmt|;
specifier|static
name|EnumConstantDecl
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
modifier|*
name|getInitExpr
parameter_list|()
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
parameter_list|(
name|Expr
modifier|*
name|E
parameter_list|)
block|{
name|Init
operator|=
operator|(
name|Stmt
operator|*
operator|)
name|E
expr_stmt|;
block|}
name|void
name|setInitVal
argument_list|(
specifier|const
name|llvm
operator|::
name|APSInt
operator|&
name|V
argument_list|)
block|{
name|Val
operator|=
name|V
expr_stmt|;
block|}
name|SourceRange
name|getSourceRange
argument_list|()
specifier|const
name|override
name|LLVM_READONLY
expr_stmt|;
comment|/// Retrieves the canonical declaration of this enumerator.
name|EnumConstantDecl
modifier|*
name|getCanonicalDecl
parameter_list|()
function|override
block|{
return|return
name|getFirstDecl
argument_list|()
return|;
block|}
specifier|const
name|EnumConstantDecl
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
name|classofKind
parameter_list|(
name|Kind
name|K
parameter_list|)
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
decl_stmt|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|/// IndirectFieldDecl - An instance of this class is created to represent a
end_comment

begin_comment
comment|/// field injected from an anonymous union/struct into the parent scope.
end_comment

begin_comment
comment|/// IndirectFieldDecl are always implicit.
end_comment

begin_decl_stmt
name|class
name|IndirectFieldDecl
range|:
name|public
name|ValueDecl
decl_stmt|,
name|public
name|Mergeable
decl|<
name|IndirectFieldDecl
decl|>
block|{
name|void
name|anchor
argument_list|()
name|override
expr_stmt|;
name|NamedDecl
modifier|*
modifier|*
name|Chaining
decl_stmt|;
name|unsigned
name|ChainingSize
decl_stmt|;
name|IndirectFieldDecl
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
argument|MutableArrayRef<NamedDecl *> CH
argument_list|)
empty_stmt|;
name|public
label|:
specifier|static
name|IndirectFieldDecl
modifier|*
name|Create
argument_list|(
name|ASTContext
operator|&
name|C
argument_list|,
name|DeclContext
operator|*
name|DC
argument_list|,
name|SourceLocation
name|L
argument_list|,
name|IdentifierInfo
operator|*
name|Id
argument_list|,
name|QualType
name|T
argument_list|,
name|llvm
operator|::
name|MutableArrayRef
operator|<
name|NamedDecl
operator|*
operator|>
name|CH
argument_list|)
decl_stmt|;
specifier|static
name|IndirectFieldDecl
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
name|ArrayRef
operator|<
name|NamedDecl
operator|*
operator|>
operator|::
name|const_iterator
name|chain_iterator
expr_stmt|;
name|ArrayRef
operator|<
name|NamedDecl
operator|*
operator|>
name|chain
argument_list|()
specifier|const
block|{
return|return
name|llvm
operator|::
name|makeArrayRef
argument_list|(
name|Chaining
argument_list|,
name|ChainingSize
argument_list|)
return|;
block|}
name|chain_iterator
name|chain_begin
argument_list|()
specifier|const
block|{
return|return
name|chain
argument_list|()
operator|.
name|begin
argument_list|()
return|;
block|}
name|chain_iterator
name|chain_end
argument_list|()
specifier|const
block|{
return|return
name|chain
argument_list|()
operator|.
name|end
argument_list|()
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
name|chain
argument_list|()
operator|.
name|size
argument_list|()
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
name|chain
argument_list|()
operator|.
name|back
argument_list|()
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
name|chain
argument_list|()
operator|.
name|size
argument_list|()
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
name|chain
argument_list|()
operator|.
name|front
argument_list|()
operator|)
return|;
block|}
name|IndirectFieldDecl
modifier|*
name|getCanonicalDecl
parameter_list|()
function|override
block|{
return|return
name|getFirstDecl
argument_list|()
return|;
block|}
specifier|const
name|IndirectFieldDecl
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
name|classofKind
parameter_list|(
name|Kind
name|K
parameter_list|)
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
decl_stmt|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

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
name|void
name|anchor
argument_list|()
name|override
block|;
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
comment|/// LocStart - The start of the source range for this declaration.
name|SourceLocation
name|LocStart
block|;
name|friend
name|class
name|ASTContext
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
argument_list|,
argument|SourceLocation StartL = SourceLocation()
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
name|nullptr
argument_list|)
block|,
name|LocStart
argument_list|(
argument|StartL
argument_list|)
block|{}
name|public
operator|:
comment|// Low-level accessor. If you just want the type defined by this node,
comment|// check out ASTContext::getTypeDeclType or one of
comment|// ASTContext::getTypedefType, ASTContext::getRecordType, etc. if you
comment|// already know the specific kind of node this is.
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
name|SourceLocation
name|getLocStart
argument_list|()
specifier|const
name|LLVM_READONLY
block|{
return|return
name|LocStart
return|;
block|}
name|void
name|setLocStart
argument_list|(
argument|SourceLocation L
argument_list|)
block|{
name|LocStart
operator|=
name|L
block|; }
name|SourceRange
name|getSourceRange
argument_list|()
specifier|const
name|override
name|LLVM_READONLY
block|{
if|if
condition|(
name|LocStart
operator|.
name|isValid
argument_list|()
condition|)
return|return
name|SourceRange
argument_list|(
name|LocStart
argument_list|,
name|getLocation
argument_list|()
argument_list|)
return|;
else|else
return|return
name|SourceRange
argument_list|(
name|getLocation
argument_list|()
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
comment|/// Base class for declarations which introduce a typedef-name.
name|class
name|TypedefNameDecl
operator|:
name|public
name|TypeDecl
block|,
name|public
name|Redeclarable
operator|<
name|TypedefNameDecl
operator|>
block|{
name|void
name|anchor
argument_list|()
name|override
block|;
typedef|typedef
name|std
operator|::
name|pair
operator|<
name|TypeSourceInfo
operator|*
operator|,
name|QualType
operator|>
name|ModedTInfo
expr_stmt|;
name|llvm
operator|::
name|PointerUnion
operator|<
name|TypeSourceInfo
operator|*
block|,
name|ModedTInfo
operator|*
operator|>
name|MaybeModedTInfo
block|;
comment|// FIXME: This can be packed into the bitfields in Decl.
comment|/// If 0, we have not computed IsTransparentTag.
comment|/// Otherwise, IsTransparentTag is (CacheIsTransparentTag>> 1).
name|mutable
name|unsigned
name|CacheIsTransparentTag
operator|:
literal|2
block|;
name|protected
operator|:
name|TypedefNameDecl
argument_list|(
argument|Kind DK
argument_list|,
argument|ASTContext&C
argument_list|,
argument|DeclContext *DC
argument_list|,
argument|SourceLocation StartLoc
argument_list|,
argument|SourceLocation IdLoc
argument_list|,
argument|IdentifierInfo *Id
argument_list|,
argument|TypeSourceInfo *TInfo
argument_list|)
operator|:
name|TypeDecl
argument_list|(
name|DK
argument_list|,
name|DC
argument_list|,
name|IdLoc
argument_list|,
name|Id
argument_list|,
name|StartLoc
argument_list|)
block|,
name|redeclarable_base
argument_list|(
name|C
argument_list|)
block|,
name|MaybeModedTInfo
argument_list|(
name|TInfo
argument_list|)
block|,
name|CacheIsTransparentTag
argument_list|(
literal|0
argument_list|)
block|{}
typedef|typedef
name|Redeclarable
operator|<
name|TypedefNameDecl
operator|>
name|redeclarable_base
expr_stmt|;
name|TypedefNameDecl
operator|*
name|getNextRedeclarationImpl
argument_list|()
name|override
block|{
return|return
name|getNextRedeclaration
argument_list|()
return|;
block|}
name|TypedefNameDecl
operator|*
name|getPreviousDeclImpl
argument_list|()
name|override
block|{
return|return
name|getPreviousDecl
argument_list|()
return|;
block|}
name|TypedefNameDecl
operator|*
name|getMostRecentDeclImpl
argument_list|()
name|override
block|{
return|return
name|getMostRecentDecl
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
name|redecl_range
name|redecl_range
expr_stmt|;
end_typedef

begin_typedef
typedef|typedef
name|redeclarable_base
operator|::
name|redecl_iterator
name|redecl_iterator
expr_stmt|;
end_typedef

begin_expr_stmt
name|using
name|redeclarable_base
operator|::
name|redecls_begin
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|redeclarable_base
operator|::
name|redecls_end
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|redeclarable_base
operator|::
name|redecls
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|redeclarable_base
operator|::
name|getPreviousDecl
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|redeclarable_base
operator|::
name|getMostRecentDecl
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|redeclarable_base
operator|::
name|isFirstDecl
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|bool
name|isModed
argument_list|()
specifier|const
block|{
return|return
name|MaybeModedTInfo
operator|.
name|is
operator|<
name|ModedTInfo
operator|*
operator|>
operator|(
operator|)
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|TypeSourceInfo
operator|*
name|getTypeSourceInfo
argument_list|()
specifier|const
block|{
return|return
name|isModed
argument_list|()
operator|?
name|MaybeModedTInfo
operator|.
name|get
operator|<
name|ModedTInfo
operator|*
operator|>
operator|(
operator|)
operator|->
name|first
operator|:
name|MaybeModedTInfo
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
end_expr_stmt

begin_expr_stmt
name|QualType
name|getUnderlyingType
argument_list|()
specifier|const
block|{
return|return
name|isModed
argument_list|()
operator|?
name|MaybeModedTInfo
operator|.
name|get
operator|<
name|ModedTInfo
operator|*
operator|>
operator|(
operator|)
operator|->
name|second
operator|:
name|MaybeModedTInfo
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
name|MaybeModedTInfo
operator|=
name|newType
expr_stmt|;
block|}
end_function

begin_function
name|void
name|setModedTypeSourceInfo
parameter_list|(
name|TypeSourceInfo
modifier|*
name|unmodedTSI
parameter_list|,
name|QualType
name|modedTy
parameter_list|)
block|{
name|MaybeModedTInfo
operator|=
name|new
argument_list|(
argument|getASTContext()
argument_list|)
name|ModedTInfo
argument_list|(
name|unmodedTSI
argument_list|,
name|modedTy
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/// Retrieves the canonical declaration of this typedef-name.
end_comment

begin_function
name|TypedefNameDecl
modifier|*
name|getCanonicalDecl
parameter_list|()
function|override
block|{
return|return
name|getFirstDecl
argument_list|()
return|;
block|}
end_function

begin_expr_stmt
specifier|const
name|TypedefNameDecl
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
end_expr_stmt

begin_comment
comment|/// Retrieves the tag declaration for which this is the typedef name for
end_comment

begin_comment
comment|/// linkage purposes, if any.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param AnyRedecl Look for the tag declaration in any redeclaration of
end_comment

begin_comment
comment|/// this typedef declaration.
end_comment

begin_decl_stmt
name|TagDecl
modifier|*
name|getAnonDeclWithTypedefName
argument_list|(
name|bool
name|AnyRedecl
operator|=
name|false
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// Determines if this typedef shares a name and spelling location with its
end_comment

begin_comment
comment|/// underlying tag type, as is the case with the NS_ENUM macro.
end_comment

begin_expr_stmt
name|bool
name|isTransparentTag
argument_list|()
specifier|const
block|{
if|if
condition|(
name|CacheIsTransparentTag
condition|)
return|return
name|CacheIsTransparentTag
operator|&
literal|0x2
return|;
end_expr_stmt

begin_return
return|return
name|isTransparentTagSlow
argument_list|()
return|;
end_return

begin_comment
unit|}
comment|// Implement isa/cast/dyncast/etc.
end_comment

begin_function
unit|static
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
name|firstTypedefName
operator|&&
name|K
operator|<=
name|lastTypedefName
return|;
block|}
end_function

begin_label
name|private
label|:
end_label

begin_expr_stmt
name|bool
name|isTransparentTagSlow
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt

begin_comment
unit|};
comment|/// TypedefDecl - Represents the declaration of a typedef-name via the 'typedef'
end_comment

begin_comment
comment|/// type specifier.
end_comment

begin_decl_stmt
name|class
name|TypedefDecl
range|:
name|public
name|TypedefNameDecl
block|{
name|TypedefDecl
argument_list|(
argument|ASTContext&C
argument_list|,
argument|DeclContext *DC
argument_list|,
argument|SourceLocation StartLoc
argument_list|,
argument|SourceLocation IdLoc
argument_list|,
argument|IdentifierInfo *Id
argument_list|,
argument|TypeSourceInfo *TInfo
argument_list|)
operator|:
name|TypedefNameDecl
argument_list|(
argument|Typedef
argument_list|,
argument|C
argument_list|,
argument|DC
argument_list|,
argument|StartLoc
argument_list|,
argument|IdLoc
argument_list|,
argument|Id
argument_list|,
argument|TInfo
argument_list|)
block|{}
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
argument|SourceLocation StartLoc
argument_list|,
argument|SourceLocation IdLoc
argument_list|,
argument|IdentifierInfo *Id
argument_list|,
argument|TypeSourceInfo *TInfo
argument_list|)
block|;
specifier|static
name|TypedefDecl
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
name|override
name|LLVM_READONLY
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
name|Typedef
return|;
block|}
expr|}
block|;
comment|/// TypeAliasDecl - Represents the declaration of a typedef-name via a C++0x
comment|/// alias-declaration.
name|class
name|TypeAliasDecl
operator|:
name|public
name|TypedefNameDecl
block|{
comment|/// The template for which this is the pattern, if any.
name|TypeAliasTemplateDecl
operator|*
name|Template
block|;
name|TypeAliasDecl
argument_list|(
argument|ASTContext&C
argument_list|,
argument|DeclContext *DC
argument_list|,
argument|SourceLocation StartLoc
argument_list|,
argument|SourceLocation IdLoc
argument_list|,
argument|IdentifierInfo *Id
argument_list|,
argument|TypeSourceInfo *TInfo
argument_list|)
operator|:
name|TypedefNameDecl
argument_list|(
name|TypeAlias
argument_list|,
name|C
argument_list|,
name|DC
argument_list|,
name|StartLoc
argument_list|,
name|IdLoc
argument_list|,
name|Id
argument_list|,
name|TInfo
argument_list|)
block|,
name|Template
argument_list|(
argument|nullptr
argument_list|)
block|{}
name|public
operator|:
specifier|static
name|TypeAliasDecl
operator|*
name|Create
argument_list|(
argument|ASTContext&C
argument_list|,
argument|DeclContext *DC
argument_list|,
argument|SourceLocation StartLoc
argument_list|,
argument|SourceLocation IdLoc
argument_list|,
argument|IdentifierInfo *Id
argument_list|,
argument|TypeSourceInfo *TInfo
argument_list|)
block|;
specifier|static
name|TypeAliasDecl
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
name|override
name|LLVM_READONLY
block|;
name|TypeAliasTemplateDecl
operator|*
name|getDescribedAliasTemplate
argument_list|()
specifier|const
block|{
return|return
name|Template
return|;
block|}
name|void
name|setDescribedAliasTemplate
argument_list|(
argument|TypeAliasTemplateDecl *TAT
argument_list|)
block|{
name|Template
operator|=
name|TAT
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
name|classofKind
argument_list|(
argument|Kind K
argument_list|)
block|{
return|return
name|K
operator|==
name|TypeAlias
return|;
block|}
expr|}
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
name|TagTypeKind
name|TagKind
typedef|;
name|private
operator|:
comment|// FIXME: This can be packed into the bitfields in Decl.
comment|/// TagDeclKind - The TagKind enum.
name|unsigned
name|TagDeclKind
operator|:
literal|3
block|;
comment|/// IsCompleteDefinition - True if this is a definition ("struct foo
comment|/// {};"), false if it is a declaration ("struct foo;").  It is not
comment|/// a definition until the definition has been fully processed.
name|unsigned
name|IsCompleteDefinition
operator|:
literal|1
block|;
name|protected
operator|:
comment|/// IsBeingDefined - True if this is currently being defined.
name|unsigned
name|IsBeingDefined
operator|:
literal|1
block|;
name|private
operator|:
comment|/// IsEmbeddedInDeclarator - True if this tag declaration is
comment|/// "embedded" (i.e., defined or declared for the very first time)
comment|/// in the syntax of a declarator.
name|unsigned
name|IsEmbeddedInDeclarator
operator|:
literal|1
block|;
comment|/// \brief True if this tag is free standing, e.g. "struct foo;".
name|unsigned
name|IsFreeStanding
operator|:
literal|1
block|;
name|protected
operator|:
comment|// These are used by (and only defined for) EnumDecl.
name|unsigned
name|NumPositiveBits
operator|:
literal|8
block|;
name|unsigned
name|NumNegativeBits
operator|:
literal|8
block|;
comment|/// IsScoped - True if this tag declaration is a scoped enumeration. Only
comment|/// possible in C++11 mode.
name|unsigned
name|IsScoped
operator|:
literal|1
block|;
comment|/// IsScopedUsingClassTag - If this tag declaration is a scoped enum,
comment|/// then this is true if the scoped enum was declared using the class
comment|/// tag, false if it was declared with the struct tag. No meaning is
comment|/// associated if this tag declaration is not a scoped enum.
name|unsigned
name|IsScopedUsingClassTag
operator|:
literal|1
block|;
comment|/// IsFixed - True if this is an enumeration with fixed underlying type. Only
comment|/// possible in C++11, Microsoft extensions, or Objective C mode.
name|unsigned
name|IsFixed
operator|:
literal|1
block|;
comment|/// \brief Indicates whether it is possible for declarations of this kind
comment|/// to have an out-of-date definition.
comment|///
comment|/// This option is only enabled when modules are enabled.
name|unsigned
name|MayHaveOutOfDateDef
operator|:
literal|1
block|;
comment|/// Has the full definition of this type been required by a use somewhere in
comment|/// the TU.
name|unsigned
name|IsCompleteDefinitionRequired
operator|:
literal|1
block|;
name|private
operator|:
name|SourceRange
name|BraceRange
block|;
comment|// A struct representing syntactic qualifier info,
comment|// to be used for the (uncommon) case of out-of-line declarations.
typedef|typedef
name|QualifierInfo
name|ExtInfo
typedef|;
comment|/// \brief If the (out-of-line) tag declaration name
comment|/// is qualified, it points to the qualifier info (nns and range);
comment|/// otherwise, if the tag declaration is anonymous and it is part of
comment|/// a typedef or alias, it points to the TypedefNameDecl (used for mangling);
comment|/// otherwise, if the tag declaration is anonymous and it is used as a
comment|/// declaration specifier for variables, it points to the first VarDecl (used
comment|/// for mangling);
comment|/// otherwise, it is a null (TypedefNameDecl) pointer.
name|llvm
operator|::
name|PointerUnion
operator|<
name|TypedefNameDecl
operator|*
block|,
name|ExtInfo
operator|*
operator|>
name|TypedefNameDeclOrQualifier
block|;
name|bool
name|hasExtInfo
argument_list|()
specifier|const
block|{
return|return
name|TypedefNameDeclOrQualifier
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
name|TypedefNameDeclOrQualifier
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
name|TypedefNameDeclOrQualifier
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
argument|const ASTContext&C
argument_list|,
argument|DeclContext *DC
argument_list|,
argument|SourceLocation L
argument_list|,
argument|IdentifierInfo *Id
argument_list|,
argument|TagDecl *PrevDecl
argument_list|,
argument|SourceLocation StartL
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
argument_list|,
name|StartL
argument_list|)
block|,
name|DeclContext
argument_list|(
name|DK
argument_list|)
block|,
name|redeclarable_base
argument_list|(
name|C
argument_list|)
block|,
name|TagDeclKind
argument_list|(
name|TK
argument_list|)
block|,
name|IsCompleteDefinition
argument_list|(
name|false
argument_list|)
block|,
name|IsBeingDefined
argument_list|(
name|false
argument_list|)
block|,
name|IsEmbeddedInDeclarator
argument_list|(
name|false
argument_list|)
block|,
name|IsFreeStanding
argument_list|(
name|false
argument_list|)
block|,
name|IsCompleteDefinitionRequired
argument_list|(
name|false
argument_list|)
block|,
name|TypedefNameDeclOrQualifier
argument_list|(
argument|(TypedefNameDecl *)nullptr
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
name|setPreviousDecl
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
name|TagDecl
operator|*
name|getNextRedeclarationImpl
argument_list|()
name|override
block|{
return|return
name|getNextRedeclaration
argument_list|()
return|;
block|}
name|TagDecl
operator|*
name|getPreviousDeclImpl
argument_list|()
name|override
block|{
return|return
name|getPreviousDecl
argument_list|()
return|;
block|}
name|TagDecl
operator|*
name|getMostRecentDeclImpl
argument_list|()
name|override
block|{
return|return
name|getMostRecentDecl
argument_list|()
return|;
block|}
comment|/// @brief Completes the definition of this tag declaration.
comment|///
comment|/// This is a helper function for derived classes.
name|void
name|completeDefinition
argument_list|()
decl_stmt|;
end_decl_stmt

begin_label
name|public
label|:
end_label

begin_typedef
typedef|typedef
name|redeclarable_base
operator|::
name|redecl_range
name|redecl_range
expr_stmt|;
end_typedef

begin_typedef
typedef|typedef
name|redeclarable_base
operator|::
name|redecl_iterator
name|redecl_iterator
expr_stmt|;
end_typedef

begin_expr_stmt
name|using
name|redeclarable_base
operator|::
name|redecls_begin
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|redeclarable_base
operator|::
name|redecls_end
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|redeclarable_base
operator|::
name|redecls
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|redeclarable_base
operator|::
name|getPreviousDecl
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|redeclarable_base
operator|::
name|getMostRecentDecl
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|redeclarable_base
operator|::
name|isFirstDecl
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|SourceRange
name|getBraceRange
argument_list|()
specifier|const
block|{
return|return
name|BraceRange
return|;
block|}
end_expr_stmt

begin_function
name|void
name|setBraceRange
parameter_list|(
name|SourceRange
name|R
parameter_list|)
block|{
name|BraceRange
operator|=
name|R
expr_stmt|;
block|}
end_function

begin_comment
comment|/// getInnerLocStart - Return SourceLocation representing start of source
end_comment

begin_comment
comment|/// range ignoring outer template declarations.
end_comment

begin_expr_stmt
name|SourceLocation
name|getInnerLocStart
argument_list|()
specifier|const
block|{
return|return
name|getLocStart
argument_list|()
return|;
block|}
end_expr_stmt

begin_comment
comment|/// getOuterLocStart - Return SourceLocation representing start of source
end_comment

begin_comment
comment|/// range taking into account any outer template declarations.
end_comment

begin_expr_stmt
name|SourceLocation
name|getOuterLocStart
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|SourceRange
name|getSourceRange
argument_list|()
specifier|const
name|override
name|LLVM_READONLY
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|TagDecl
operator|*
name|getCanonicalDecl
argument_list|()
name|override
expr_stmt|;
end_expr_stmt

begin_expr_stmt
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
end_expr_stmt

begin_comment
comment|/// isThisDeclarationADefinition() - Return true if this declaration
end_comment

begin_comment
comment|/// is a completion definition of the type.  Provided for consistency.
end_comment

begin_expr_stmt
name|bool
name|isThisDeclarationADefinition
argument_list|()
specifier|const
block|{
return|return
name|isCompleteDefinition
argument_list|()
return|;
block|}
end_expr_stmt

begin_comment
comment|/// isCompleteDefinition - Return true if this decl has its body
end_comment

begin_comment
comment|/// fully specified.
end_comment

begin_expr_stmt
name|bool
name|isCompleteDefinition
argument_list|()
specifier|const
block|{
return|return
name|IsCompleteDefinition
return|;
block|}
end_expr_stmt

begin_comment
comment|/// \brief Return true if this complete decl is
end_comment

begin_comment
comment|/// required to be complete for some existing use.
end_comment

begin_expr_stmt
name|bool
name|isCompleteDefinitionRequired
argument_list|()
specifier|const
block|{
return|return
name|IsCompleteDefinitionRequired
return|;
block|}
end_expr_stmt

begin_comment
comment|/// isBeingDefined - Return true if this decl is currently being defined.
end_comment

begin_expr_stmt
name|bool
name|isBeingDefined
argument_list|()
specifier|const
block|{
return|return
name|IsBeingDefined
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|bool
name|isEmbeddedInDeclarator
argument_list|()
specifier|const
block|{
return|return
name|IsEmbeddedInDeclarator
return|;
block|}
end_expr_stmt

begin_function
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
end_function

begin_expr_stmt
name|bool
name|isFreeStanding
argument_list|()
specifier|const
block|{
return|return
name|IsFreeStanding
return|;
block|}
end_expr_stmt

begin_function
name|void
name|setFreeStanding
parameter_list|(
name|bool
name|isFreeStanding
init|=
name|true
parameter_list|)
block|{
name|IsFreeStanding
operator|=
name|isFreeStanding
expr_stmt|;
block|}
end_function

begin_comment
comment|/// \brief Whether this declaration declares a type that is
end_comment

begin_comment
comment|/// dependent, i.e., a type that somehow depends on template
end_comment

begin_comment
comment|/// parameters.
end_comment

begin_expr_stmt
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
end_expr_stmt

begin_comment
comment|/// @brief Starts the definition of this tag declaration.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This method should be invoked at the beginning of the definition
end_comment

begin_comment
comment|/// of this tag declaration. It will set the tag type into a state
end_comment

begin_comment
comment|/// where it is in the process of being defined.
end_comment

begin_function_decl
name|void
name|startDefinition
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/// getDefinition - Returns the TagDecl that actually defines this
end_comment

begin_comment
comment|///  struct/union/class/enum.  When determining whether or not a
end_comment

begin_comment
comment|///  struct/union/class/enum has a definition, one should use this
end_comment

begin_comment
comment|///  method as opposed to 'isDefinition'.  'isDefinition' indicates
end_comment

begin_comment
comment|///  whether or not a specific TagDecl is defining declaration, not
end_comment

begin_comment
comment|///  whether or not the struct/union/class/enum type is defined.
end_comment

begin_comment
comment|///  This method returns NULL if there is no TagDecl that defines
end_comment

begin_comment
comment|///  the struct/union/class/enum.
end_comment

begin_expr_stmt
name|TagDecl
operator|*
name|getDefinition
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt

begin_function
name|void
name|setCompleteDefinition
parameter_list|(
name|bool
name|V
parameter_list|)
block|{
name|IsCompleteDefinition
operator|=
name|V
expr_stmt|;
block|}
end_function

begin_function
name|void
name|setCompleteDefinitionRequired
parameter_list|(
name|bool
name|V
init|=
name|true
parameter_list|)
block|{
name|IsCompleteDefinitionRequired
operator|=
name|V
expr_stmt|;
block|}
end_function

begin_expr_stmt
name|StringRef
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
end_expr_stmt

begin_expr_stmt
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
end_expr_stmt

begin_function
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
end_function

begin_expr_stmt
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
end_expr_stmt

begin_expr_stmt
name|bool
name|isInterface
argument_list|()
specifier|const
block|{
return|return
name|getTagKind
argument_list|()
operator|==
name|TTK_Interface
return|;
block|}
end_expr_stmt

begin_expr_stmt
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
end_expr_stmt

begin_expr_stmt
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
end_expr_stmt

begin_expr_stmt
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
end_expr_stmt

begin_comment
comment|/// Is this tag type named, either directly or via being defined in
end_comment

begin_comment
comment|/// a typedef of this type?
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// C++11 [basic.link]p8:
end_comment

begin_comment
comment|///   A type is said to have linkage if and only if:
end_comment

begin_comment
comment|///     - it is a class or enumeration type that is named (or has a
end_comment

begin_comment
comment|///       name for linkage purposes) and the name has linkage; ...
end_comment

begin_comment
comment|/// C++11 [dcl.typedef]p9:
end_comment

begin_comment
comment|///   If the typedef declaration defines an unnamed class (or enum),
end_comment

begin_comment
comment|///   the first typedef-name declared by the declaration to be that
end_comment

begin_comment
comment|///   class type (or enum type) is used to denote the class type (or
end_comment

begin_comment
comment|///   enum type) for linkage purposes only.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// C does not have an analogous rule, but the same concept is
end_comment

begin_comment
comment|/// nonetheless useful in some places.
end_comment

begin_expr_stmt
name|bool
name|hasNameForLinkage
argument_list|()
specifier|const
block|{
return|return
operator|(
name|getDeclName
argument_list|()
operator|||
name|getTypedefNameForAnonDecl
argument_list|()
operator|)
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|TypedefNameDecl
operator|*
name|getTypedefNameForAnonDecl
argument_list|()
specifier|const
block|{
return|return
name|hasExtInfo
argument_list|()
operator|?
name|nullptr
operator|:
name|TypedefNameDeclOrQualifier
operator|.
name|get
operator|<
name|TypedefNameDecl
operator|*
operator|>
operator|(
operator|)
return|;
block|}
end_expr_stmt

begin_function_decl
name|void
name|setTypedefNameForAnonDecl
parameter_list|(
name|TypedefNameDecl
modifier|*
name|TDD
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// \brief Retrieve the nested-name-specifier that qualifies the name of this
end_comment

begin_comment
comment|/// declaration, if it was present in the source.
end_comment

begin_expr_stmt
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
name|nullptr
return|;
block|}
end_expr_stmt

begin_comment
comment|/// \brief Retrieve the nested-name-specifier (with source-location
end_comment

begin_comment
comment|/// information) that qualifies the name of this declaration, if it was
end_comment

begin_comment
comment|/// present in the source.
end_comment

begin_expr_stmt
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
end_expr_stmt

begin_function_decl
name|void
name|setQualifierInfo
parameter_list|(
name|NestedNameSpecifierLoc
name|QualifierLoc
parameter_list|)
function_decl|;
end_function_decl

begin_expr_stmt
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
end_expr_stmt

begin_decl_stmt
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
end_decl_stmt

begin_decl_stmt
name|void
name|setTemplateParameterListsInfo
argument_list|(
name|ASTContext
operator|&
name|Context
argument_list|,
name|ArrayRef
operator|<
name|TemplateParameterList
operator|*
operator|>
name|TPLists
argument_list|)
decl_stmt|;
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
name|firstTag
operator|&&
name|K
operator|<=
name|lastTag
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
end_function

begin_function
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
comment|/// EnumDecl - Represents an enum.  In C++11, enums can be forward-declared
end_comment

begin_comment
comment|/// with a fixed underlying type, and in C we allow them to be forward-declared
end_comment

begin_comment
comment|/// with no underlying type as an extension.
end_comment

begin_decl_stmt
name|class
name|EnumDecl
range|:
name|public
name|TagDecl
block|{
name|void
name|anchor
argument_list|()
name|override
block|;
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
comment|/// \brief If this enumeration is an instantiation of a member enumeration
comment|/// of a class template specialization, this is the member specialization
comment|/// information.
name|MemberSpecializationInfo
operator|*
name|SpecializationInfo
block|;
name|EnumDecl
argument_list|(
argument|ASTContext&C
argument_list|,
argument|DeclContext *DC
argument_list|,
argument|SourceLocation StartLoc
argument_list|,
argument|SourceLocation IdLoc
argument_list|,
argument|IdentifierInfo *Id
argument_list|,
argument|EnumDecl *PrevDecl
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
name|C
argument_list|,
name|DC
argument_list|,
name|IdLoc
argument_list|,
name|Id
argument_list|,
name|PrevDecl
argument_list|,
name|StartLoc
argument_list|)
block|,
name|SpecializationInfo
argument_list|(
argument|nullptr
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
name|nullptr
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
block|;   }
name|void
name|setInstantiationOfMemberEnum
argument_list|(
argument|ASTContext&C
argument_list|,
argument|EnumDecl *ED
argument_list|,
argument|TemplateSpecializationKind TSK
argument_list|)
block|;
name|public
operator|:
name|EnumDecl
operator|*
name|getCanonicalDecl
argument_list|()
name|override
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
name|const_cast
operator|<
name|EnumDecl
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
name|EnumDecl
operator|*
name|getPreviousDecl
argument_list|()
block|{
return|return
name|cast_or_null
operator|<
name|EnumDecl
operator|>
operator|(
name|static_cast
operator|<
name|TagDecl
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
name|EnumDecl
operator|*
name|getPreviousDecl
argument_list|()
specifier|const
block|{
return|return
name|const_cast
operator|<
name|EnumDecl
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
name|EnumDecl
operator|*
name|getMostRecentDecl
argument_list|()
block|{
return|return
name|cast
operator|<
name|EnumDecl
operator|>
operator|(
name|static_cast
operator|<
name|TagDecl
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
name|EnumDecl
operator|*
name|getMostRecentDecl
argument_list|()
specifier|const
block|{
return|return
name|const_cast
operator|<
name|EnumDecl
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
name|EnumDecl
operator|*
name|getDefinition
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
name|getDefinition
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
argument|SourceLocation StartLoc
argument_list|,
argument|SourceLocation IdLoc
argument_list|,
argument|IdentifierInfo *Id
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
name|CreateDeserialized
argument_list|(
argument|ASTContext&C
argument_list|,
argument|unsigned ID
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
end_decl_stmt

begin_typedef
typedef|typedef
name|llvm
operator|::
name|iterator_range
operator|<
name|specific_decl_iterator
operator|<
name|EnumConstantDecl
operator|>>
name|enumerator_range
expr_stmt|;
end_typedef

begin_expr_stmt
name|enumerator_range
name|enumerators
argument_list|()
specifier|const
block|{
return|return
name|enumerator_range
argument_list|(
name|enumerator_begin
argument_list|()
argument_list|,
name|enumerator_end
argument_list|()
argument_list|)
return|;
block|}
end_expr_stmt

begin_expr_stmt
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
name|getDefinition
argument_list|()
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
name|getDefinition
argument_list|()
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
comment|/// This returns a null QualType for an enum forward definition with no fixed
end_comment

begin_comment
comment|/// underlying type.
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
operator|.
name|getUnqualifiedType
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
comment|/// \brief Retrieve the source range that covers the underlying type if
end_comment

begin_comment
comment|/// specified.
end_comment

begin_expr_stmt
name|SourceRange
name|getIntegerTypeRange
argument_list|()
specifier|const
name|LLVM_READONLY
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// \brief Returns the width in bits required to store all the
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
comment|/// \brief Returns the width in bits required to store all the
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
comment|/// \brief Returns true if this is a C++11 scoped enumeration.
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
comment|/// \brief Returns true if this is a C++11 scoped enumeration.
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
comment|/// \brief Returns true if this is an Objective-C, C++11, or
end_comment

begin_comment
comment|/// Microsoft-style enumeration with a fixed underlying type.
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
name|isCompleteDefinition
argument_list|()
operator|||
name|isFixed
argument_list|()
return|;
block|}
end_expr_stmt

begin_comment
comment|/// Returns true if this enum is either annotated with
end_comment

begin_comment
comment|/// enum_extensibility(closed) or isn't annotated with enum_extensibility.
end_comment

begin_expr_stmt
name|bool
name|isClosed
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// Returns true if this enum is annotated with flag_enum and isn't annotated
end_comment

begin_comment
comment|/// with enum_extensibility(open).
end_comment

begin_expr_stmt
name|bool
name|isClosedFlag
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// Returns true if this enum is annotated with neither flag_enum nor
end_comment

begin_comment
comment|/// enum_extensibility(open).
end_comment

begin_expr_stmt
name|bool
name|isClosedNonFlag
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// \brief Retrieve the enum definition from which this enumeration could
end_comment

begin_comment
comment|/// be instantiated, if it is an instantiation (rather than a non-template).
end_comment

begin_expr_stmt
name|EnumDecl
operator|*
name|getTemplateInstantiationPattern
argument_list|()
specifier|const
expr_stmt|;
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
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// \brief If this enumeration is a member of a specialization of a
end_comment

begin_comment
comment|/// templated class, determine what kind of template specialization
end_comment

begin_comment
comment|/// or instantiation this is.
end_comment

begin_expr_stmt
name|TemplateSpecializationKind
name|getTemplateSpecializationKind
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// \brief For an enumeration member that was instantiated from a member
end_comment

begin_comment
comment|/// enumeration of a templated class, set the template specialiation kind.
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
comment|/// \brief If this enumeration is an instantiation of a member enumeration of
end_comment

begin_comment
comment|/// a class template specialization, retrieves the member specialization
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
name|SpecializationInfo
return|;
block|}
end_expr_stmt

begin_comment
comment|/// \brief Specify that this enumeration is an instantiation of the
end_comment

begin_comment
comment|/// member enumeration ED.
end_comment

begin_function
name|void
name|setInstantiationOfMemberEnum
parameter_list|(
name|EnumDecl
modifier|*
name|ED
parameter_list|,
name|TemplateSpecializationKind
name|TSK
parameter_list|)
block|{
name|setInstantiationOfMemberEnum
argument_list|(
name|getASTContext
argument_list|()
argument_list|,
name|ED
argument_list|,
name|TSK
argument_list|)
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
comment|/// containing an Objective-C object pointer type.
name|bool
name|HasObjectMember
operator|:
literal|1
block|;
comment|/// HasVolatileMember - This is true if struct has at least one member of
comment|/// 'volatile' type.
name|bool
name|HasVolatileMember
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
argument|const ASTContext&C
argument_list|,
argument|DeclContext *DC
argument_list|,
argument|SourceLocation StartLoc
argument_list|,
argument|SourceLocation IdLoc
argument_list|,
argument|IdentifierInfo *Id
argument_list|,
argument|RecordDecl *PrevDecl
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
argument|SourceLocation StartLoc
argument_list|,
argument|SourceLocation IdLoc
argument_list|,
argument|IdentifierInfo *Id
argument_list|,
argument|RecordDecl* PrevDecl = nullptr
argument_list|)
block|;
specifier|static
name|RecordDecl
operator|*
name|CreateDeserialized
argument_list|(
argument|const ASTContext&C
argument_list|,
argument|unsigned ID
argument_list|)
block|;
name|RecordDecl
operator|*
name|getPreviousDecl
argument_list|()
block|{
return|return
name|cast_or_null
operator|<
name|RecordDecl
operator|>
operator|(
name|static_cast
operator|<
name|TagDecl
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
name|RecordDecl
operator|*
name|getPreviousDecl
argument_list|()
specifier|const
block|{
return|return
name|const_cast
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
return|;
block|}
name|RecordDecl
operator|*
name|getMostRecentDecl
argument_list|()
block|{
return|return
name|cast
operator|<
name|RecordDecl
operator|>
operator|(
name|static_cast
operator|<
name|TagDecl
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
name|RecordDecl
operator|*
name|getMostRecentDecl
argument_list|()
specifier|const
block|{
return|return
name|const_cast
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
name|bool
name|hasVolatileMember
argument_list|()
specifier|const
block|{
return|return
name|HasVolatileMember
return|;
block|}
name|void
name|setHasVolatileMember
argument_list|(
argument|bool val
argument_list|)
block|{
name|HasVolatileMember
operator|=
name|val
block|; }
name|bool
name|hasLoadedFieldsFromExternalStorage
argument_list|()
specifier|const
block|{
return|return
name|LoadedFieldsFromExternalStorage
return|;
block|}
name|void
name|setHasLoadedFieldsFromExternalStorage
argument_list|(
argument|bool val
argument_list|)
block|{
name|LoadedFieldsFromExternalStorage
operator|=
name|val
block|;   }
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
comment|/// \brief Determine whether this record is a class describing a lambda
comment|/// function object.
name|bool
name|isLambda
argument_list|()
specifier|const
block|;
comment|/// \brief Determine whether this record is a record for captured variables in
comment|/// CapturedStmt construct.
name|bool
name|isCapturedRecord
argument_list|()
specifier|const
block|;
comment|/// \brief Mark the record as a record for captured variables in CapturedStmt
comment|/// construct.
name|void
name|setCapturedRecord
argument_list|()
block|;
comment|/// getDefinition - Returns the RecordDecl that actually defines
comment|///  this struct/union/class.  When determining whether or not a
comment|///  struct/union/class is completely defined, one should use this
comment|///  method as opposed to 'isCompleteDefinition'.
comment|///  'isCompleteDefinition' indicates whether or not a specific
comment|///  RecordDecl is a completed definition, not whether or not the
comment|///  record type is defined.  This method returns NULL if there is
comment|///  no RecordDecl that defines the struct/union/tag.
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
end_decl_stmt

begin_typedef
typedef|typedef
name|llvm
operator|::
name|iterator_range
operator|<
name|specific_decl_iterator
operator|<
name|FieldDecl
operator|>>
name|field_range
expr_stmt|;
end_typedef

begin_expr_stmt
name|field_range
name|fields
argument_list|()
specifier|const
block|{
return|return
name|field_range
argument_list|(
name|field_begin
argument_list|()
argument_list|,
name|field_end
argument_list|()
argument_list|)
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|field_iterator
name|field_begin
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt

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

begin_comment
comment|/// isMsStrust - Get whether or not this is an ms_struct which can
end_comment

begin_comment
comment|/// be turned on with an attribute, pragma, or -mms-bitfields
end_comment

begin_comment
comment|/// commandline option.
end_comment

begin_decl_stmt
name|bool
name|isMsStruct
argument_list|(
specifier|const
name|ASTContext
operator|&
name|C
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// \brief Whether we are allowed to insert extra padding between fields.
end_comment

begin_comment
comment|/// These padding are added to help AddressSanitizer detect
end_comment

begin_comment
comment|/// intra-object-overflow bugs.
end_comment

begin_decl_stmt
name|bool
name|mayInsertExtraPadding
argument_list|(
name|bool
name|EmitRemark
operator|=
name|false
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// Finds the first data member which has a name.
end_comment

begin_comment
comment|/// nullptr is returned if no named data member exists.
end_comment

begin_expr_stmt
specifier|const
name|FieldDecl
operator|*
name|findFirstNamedDataMember
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt

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
name|virtual
name|void
name|anchor
argument_list|()
block|;
name|StringLiteral
operator|*
name|AsmString
block|;
name|SourceLocation
name|RParenLoc
block|;
name|FileScopeAsmDecl
argument_list|(
argument|DeclContext *DC
argument_list|,
argument|StringLiteral *asmstring
argument_list|,
argument|SourceLocation StartL
argument_list|,
argument|SourceLocation EndL
argument_list|)
operator|:
name|Decl
argument_list|(
name|FileScopeAsm
argument_list|,
name|DC
argument_list|,
name|StartL
argument_list|)
block|,
name|AsmString
argument_list|(
name|asmstring
argument_list|)
block|,
name|RParenLoc
argument_list|(
argument|EndL
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
argument|StringLiteral *Str
argument_list|,
argument|SourceLocation AsmLoc
argument_list|,
argument|SourceLocation RParenLoc
argument_list|)
block|;
specifier|static
name|FileScopeAsmDecl
operator|*
name|CreateDeserialized
argument_list|(
argument|ASTContext&C
argument_list|,
argument|unsigned ID
argument_list|)
block|;
name|SourceLocation
name|getAsmLoc
argument_list|()
specifier|const
block|{
return|return
name|getLocation
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
name|void
name|setRParenLoc
argument_list|(
argument|SourceLocation L
argument_list|)
block|{
name|RParenLoc
operator|=
name|L
block|; }
name|SourceRange
name|getSourceRange
argument_list|()
specifier|const
name|override
name|LLVM_READONLY
block|{
return|return
name|SourceRange
argument_list|(
name|getAsmLoc
argument_list|()
argument_list|,
name|getRParenLoc
argument_list|()
argument_list|)
return|;
block|}
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
name|nullptr
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
name|bool
name|BlockMissingReturnType
operator|:
literal|1
block|;
name|bool
name|IsConversionFromLambda
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
specifier|const
name|Capture
operator|*
name|Captures
block|;
name|unsigned
name|NumCaptures
block|;
name|unsigned
name|ManglingNumber
block|;
name|Decl
operator|*
name|ManglingContextDecl
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
name|BlockMissingReturnType
argument_list|(
name|true
argument_list|)
block|,
name|IsConversionFromLambda
argument_list|(
name|false
argument_list|)
block|,
name|ParamInfo
argument_list|(
name|nullptr
argument_list|)
block|,
name|NumParams
argument_list|(
literal|0
argument_list|)
block|,
name|Body
argument_list|(
name|nullptr
argument_list|)
block|,
name|SignatureAsWritten
argument_list|(
name|nullptr
argument_list|)
block|,
name|Captures
argument_list|(
name|nullptr
argument_list|)
block|,
name|NumCaptures
argument_list|(
literal|0
argument_list|)
block|,
name|ManglingNumber
argument_list|(
literal|0
argument_list|)
block|,
name|ManglingContextDecl
argument_list|(
argument|nullptr
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
specifier|static
name|BlockDecl
operator|*
name|CreateDeserialized
argument_list|(
argument|ASTContext&C
argument_list|,
argument|unsigned ID
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
name|override
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
comment|// ArrayRef access to formal parameters.
name|ArrayRef
operator|<
name|ParmVarDecl
operator|*
operator|>
name|parameters
argument_list|()
specifier|const
block|{
return|return
block|{
name|ParamInfo
block|,
name|getNumParams
argument_list|()
block|}
return|;
block|}
name|MutableArrayRef
operator|<
name|ParmVarDecl
operator|*
operator|>
name|parameters
argument_list|()
block|{
return|return
block|{
name|ParamInfo
block|,
name|getNumParams
argument_list|()
block|}
return|;
block|}
comment|// Iterator access to formal parameters.
typedef|typedef
name|MutableArrayRef
operator|<
name|ParmVarDecl
operator|*
operator|>
operator|::
name|iterator
name|param_iterator
expr_stmt|;
typedef|typedef
name|ArrayRef
operator|<
name|ParmVarDecl
operator|*
operator|>
operator|::
name|const_iterator
name|param_const_iterator
expr_stmt|;
name|bool
name|param_empty
argument_list|()
specifier|const
block|{
return|return
name|parameters
argument_list|()
operator|.
name|empty
argument_list|()
return|;
block|}
name|param_iterator
name|param_begin
argument_list|()
block|{
return|return
name|parameters
argument_list|()
operator|.
name|begin
argument_list|()
return|;
block|}
name|param_iterator
name|param_end
argument_list|()
block|{
return|return
name|parameters
argument_list|()
operator|.
name|end
argument_list|()
return|;
block|}
name|param_const_iterator
name|param_begin
argument_list|()
specifier|const
block|{
return|return
name|parameters
argument_list|()
operator|.
name|begin
argument_list|()
return|;
block|}
name|param_const_iterator
name|param_end
argument_list|()
specifier|const
block|{
return|return
name|parameters
argument_list|()
operator|.
name|end
argument_list|()
return|;
block|}
name|size_t
name|param_size
argument_list|()
specifier|const
block|{
return|return
name|parameters
argument_list|()
operator|.
name|size
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
name|ArrayRef
operator|<
name|ParmVarDecl
operator|*
operator|>
name|NewParamInfo
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
name|ArrayRef
operator|<
name|Capture
operator|>
operator|::
name|const_iterator
name|capture_const_iterator
expr_stmt|;
name|ArrayRef
operator|<
name|Capture
operator|>
name|captures
argument_list|()
specifier|const
block|{
return|return
block|{
name|Captures
block|,
name|NumCaptures
block|}
return|;
block|}
name|capture_const_iterator
name|capture_begin
argument_list|()
specifier|const
block|{
return|return
name|captures
argument_list|()
operator|.
name|begin
argument_list|()
return|;
block|}
name|capture_const_iterator
name|capture_end
argument_list|()
specifier|const
block|{
return|return
name|captures
argument_list|()
operator|.
name|end
argument_list|()
return|;
block|}
name|bool
name|capturesCXXThis
argument_list|()
specifier|const
block|{
return|return
name|CapturesCXXThis
return|;
block|}
name|bool
name|blockMissingReturnType
argument_list|()
specifier|const
block|{
return|return
name|BlockMissingReturnType
return|;
block|}
name|void
name|setBlockMissingReturnType
argument_list|(
argument|bool val
argument_list|)
block|{
name|BlockMissingReturnType
operator|=
name|val
block|; }
name|bool
name|isConversionFromLambda
argument_list|()
specifier|const
block|{
return|return
name|IsConversionFromLambda
return|;
block|}
end_decl_stmt

begin_function
name|void
name|setIsConversionFromLambda
parameter_list|(
name|bool
name|val
parameter_list|)
block|{
name|IsConversionFromLambda
operator|=
name|val
expr_stmt|;
block|}
end_function

begin_decl_stmt
name|bool
name|capturesVariable
argument_list|(
specifier|const
name|VarDecl
operator|*
name|var
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|setCaptures
argument_list|(
name|ASTContext
operator|&
name|Context
argument_list|,
name|ArrayRef
operator|<
name|Capture
operator|>
name|Captures
argument_list|,
name|bool
name|CapturesCXXThis
argument_list|)
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|unsigned
name|getBlockManglingNumber
argument_list|()
specifier|const
block|{
return|return
name|ManglingNumber
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|Decl
operator|*
name|getBlockManglingContextDecl
argument_list|()
specifier|const
block|{
return|return
name|ManglingContextDecl
return|;
block|}
end_expr_stmt

begin_function
name|void
name|setBlockMangling
parameter_list|(
name|unsigned
name|Number
parameter_list|,
name|Decl
modifier|*
name|Ctx
parameter_list|)
block|{
name|ManglingNumber
operator|=
name|Number
expr_stmt|;
name|ManglingContextDecl
operator|=
name|Ctx
expr_stmt|;
block|}
end_function

begin_expr_stmt
name|SourceRange
name|getSourceRange
argument_list|()
specifier|const
name|override
name|LLVM_READONLY
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
comment|/// \brief This represents the body of a CapturedStmt, and serves as its
end_comment

begin_comment
comment|/// DeclContext.
end_comment

begin_decl_stmt
name|class
name|CapturedDecl
name|final
range|:
name|public
name|Decl
decl_stmt|,
name|public
name|DeclContext
decl_stmt|,
name|private
name|llvm
decl|::
name|TrailingObjects
decl|<
name|CapturedDecl
decl_stmt|,
name|ImplicitParamDecl
modifier|*
decl|>
block|{
name|protected
label|:
name|size_t
name|numTrailingObjects
argument_list|(
name|OverloadToken
operator|<
name|ImplicitParamDecl
operator|>
argument_list|)
block|{
return|return
name|NumParams
return|;
block|}
name|private
label|:
comment|/// \brief The number of parameters to the outlined function.
name|unsigned
name|NumParams
decl_stmt|;
comment|/// \brief The position of context parameter in list of parameters.
name|unsigned
name|ContextParam
decl_stmt|;
comment|/// \brief The body of the outlined function.
name|llvm
operator|::
name|PointerIntPair
operator|<
name|Stmt
operator|*
operator|,
literal|1
operator|,
name|bool
operator|>
name|BodyAndNothrow
expr_stmt|;
name|explicit
name|CapturedDecl
parameter_list|(
name|DeclContext
modifier|*
name|DC
parameter_list|,
name|unsigned
name|NumParams
parameter_list|)
function_decl|;
name|ImplicitParamDecl
operator|*
specifier|const
operator|*
name|getParams
argument_list|()
specifier|const
block|{
return|return
name|getTrailingObjects
operator|<
name|ImplicitParamDecl
operator|*
operator|>
operator|(
operator|)
return|;
block|}
name|ImplicitParamDecl
modifier|*
modifier|*
name|getParams
parameter_list|()
block|{
return|return
name|getTrailingObjects
operator|<
name|ImplicitParamDecl
operator|*
operator|>
operator|(
operator|)
return|;
block|}
name|public
label|:
specifier|static
name|CapturedDecl
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
name|unsigned
name|NumParams
parameter_list|)
function_decl|;
specifier|static
name|CapturedDecl
modifier|*
name|CreateDeserialized
parameter_list|(
name|ASTContext
modifier|&
name|C
parameter_list|,
name|unsigned
name|ID
parameter_list|,
name|unsigned
name|NumParams
parameter_list|)
function_decl|;
name|Stmt
operator|*
name|getBody
argument_list|()
specifier|const
name|override
expr_stmt|;
name|void
name|setBody
parameter_list|(
name|Stmt
modifier|*
name|B
parameter_list|)
function_decl|;
name|bool
name|isNothrow
argument_list|()
specifier|const
expr_stmt|;
name|void
name|setNothrow
parameter_list|(
name|bool
name|Nothrow
init|=
name|true
parameter_list|)
function_decl|;
name|unsigned
name|getNumParams
argument_list|()
specifier|const
block|{
return|return
name|NumParams
return|;
block|}
name|ImplicitParamDecl
modifier|*
name|getParam
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
name|NumParams
argument_list|)
expr_stmt|;
return|return
name|getParams
argument_list|()
index|[
name|i
index|]
return|;
block|}
name|void
name|setParam
parameter_list|(
name|unsigned
name|i
parameter_list|,
name|ImplicitParamDecl
modifier|*
name|P
parameter_list|)
block|{
name|assert
argument_list|(
name|i
operator|<
name|NumParams
argument_list|)
expr_stmt|;
name|getParams
argument_list|()
index|[
name|i
index|]
operator|=
name|P
expr_stmt|;
block|}
comment|// ArrayRef interface to parameters.
name|ArrayRef
operator|<
name|ImplicitParamDecl
operator|*
operator|>
name|parameters
argument_list|()
specifier|const
block|{
return|return
block|{
name|getParams
argument_list|()
block|,
name|getNumParams
argument_list|()
block|}
return|;
block|}
name|MutableArrayRef
operator|<
name|ImplicitParamDecl
operator|*
operator|>
name|parameters
argument_list|()
block|{
return|return
block|{
name|getParams
argument_list|()
block|,
name|getNumParams
argument_list|()
block|}
return|;
block|}
comment|/// \brief Retrieve the parameter containing captured variables.
name|ImplicitParamDecl
operator|*
name|getContextParam
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
name|ContextParam
operator|<
name|NumParams
argument_list|)
block|;
return|return
name|getParam
argument_list|(
name|ContextParam
argument_list|)
return|;
block|}
name|void
name|setContextParam
parameter_list|(
name|unsigned
name|i
parameter_list|,
name|ImplicitParamDecl
modifier|*
name|P
parameter_list|)
block|{
name|assert
argument_list|(
name|i
operator|<
name|NumParams
argument_list|)
expr_stmt|;
name|ContextParam
operator|=
name|i
expr_stmt|;
name|setParam
argument_list|(
name|i
argument_list|,
name|P
argument_list|)
expr_stmt|;
block|}
name|unsigned
name|getContextParamPosition
argument_list|()
specifier|const
block|{
return|return
name|ContextParam
return|;
block|}
typedef|typedef
name|ImplicitParamDecl
modifier|*
specifier|const
modifier|*
name|param_iterator
typedef|;
typedef|typedef
name|llvm
operator|::
name|iterator_range
operator|<
name|param_iterator
operator|>
name|param_range
expr_stmt|;
comment|/// \brief Retrieve an iterator pointing to the first parameter decl.
name|param_iterator
name|param_begin
argument_list|()
specifier|const
block|{
return|return
name|getParams
argument_list|()
return|;
block|}
comment|/// \brief Retrieve an iterator one past the last parameter decl.
name|param_iterator
name|param_end
argument_list|()
specifier|const
block|{
return|return
name|getParams
argument_list|()
operator|+
name|NumParams
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
name|Captured
return|;
block|}
specifier|static
name|DeclContext
modifier|*
name|castToDeclContext
parameter_list|(
specifier|const
name|CapturedDecl
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
name|CapturedDecl
operator|*
operator|>
operator|(
name|D
operator|)
operator|)
return|;
block|}
specifier|static
name|CapturedDecl
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
name|CapturedDecl
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
name|friend
name|TrailingObjects
decl_stmt|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|/// \brief Describes a module import declaration, which makes the contents
end_comment

begin_comment
comment|/// of the named module visible in the current translation unit.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// An import declaration imports the named module (or submodule). For example:
end_comment

begin_comment
comment|/// \code
end_comment

begin_comment
comment|///   @import std.vector;
end_comment

begin_comment
comment|/// \endcode
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Import declarations can also be implicitly generated from
end_comment

begin_comment
comment|/// \#include/\#import directives.
end_comment

begin_decl_stmt
name|class
name|ImportDecl
name|final
range|:
name|public
name|Decl
decl_stmt|,
name|llvm
decl|::
name|TrailingObjects
decl|<
name|ImportDecl
decl_stmt|,
name|SourceLocation
decl|>
block|{
comment|/// \brief The imported module, along with a bit that indicates whether
comment|/// we have source-location information for each identifier in the module
comment|/// name.
comment|///
comment|/// When the bit is false, we only have a single source location for the
comment|/// end of the import declaration.
name|llvm
operator|::
name|PointerIntPair
operator|<
name|Module
operator|*
operator|,
literal|1
operator|,
name|bool
operator|>
name|ImportedAndComplete
expr_stmt|;
comment|/// \brief The next import in the list of imports local to the translation
comment|/// unit being parsed (not loaded from an AST file).
name|ImportDecl
modifier|*
name|NextLocalImport
decl_stmt|;
name|friend
name|class
name|ASTReader
decl_stmt|;
name|friend
name|class
name|ASTDeclReader
decl_stmt|;
name|friend
name|class
name|ASTContext
decl_stmt|;
name|friend
name|TrailingObjects
decl_stmt|;
name|ImportDecl
argument_list|(
argument|DeclContext *DC
argument_list|,
argument|SourceLocation StartLoc
argument_list|,
argument|Module *Imported
argument_list|,
argument|ArrayRef<SourceLocation> IdentifierLocs
argument_list|)
empty_stmt|;
name|ImportDecl
argument_list|(
argument|DeclContext *DC
argument_list|,
argument|SourceLocation StartLoc
argument_list|,
argument|Module *Imported
argument_list|,
argument|SourceLocation EndLoc
argument_list|)
empty_stmt|;
name|ImportDecl
argument_list|(
argument|EmptyShell Empty
argument_list|)
block|:
name|Decl
argument_list|(
name|Import
argument_list|,
name|Empty
argument_list|)
operator|,
name|NextLocalImport
argument_list|()
block|{ }
name|public
operator|:
comment|/// \brief Create a new module import declaration.
specifier|static
name|ImportDecl
operator|*
name|Create
argument_list|(
argument|ASTContext&C
argument_list|,
argument|DeclContext *DC
argument_list|,
argument|SourceLocation StartLoc
argument_list|,
argument|Module *Imported
argument_list|,
argument|ArrayRef<SourceLocation> IdentifierLocs
argument_list|)
expr_stmt|;
comment|/// \brief Create a new module import declaration for an implicitly-generated
comment|/// import.
specifier|static
name|ImportDecl
modifier|*
name|CreateImplicit
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
name|StartLoc
parameter_list|,
name|Module
modifier|*
name|Imported
parameter_list|,
name|SourceLocation
name|EndLoc
parameter_list|)
function_decl|;
comment|/// \brief Create a new, deserialized module import declaration.
specifier|static
name|ImportDecl
modifier|*
name|CreateDeserialized
parameter_list|(
name|ASTContext
modifier|&
name|C
parameter_list|,
name|unsigned
name|ID
parameter_list|,
name|unsigned
name|NumLocations
parameter_list|)
function_decl|;
comment|/// \brief Retrieve the module that was imported by the import declaration.
name|Module
operator|*
name|getImportedModule
argument_list|()
specifier|const
block|{
return|return
name|ImportedAndComplete
operator|.
name|getPointer
argument_list|()
return|;
block|}
comment|/// \brief Retrieves the locations of each of the identifiers that make up
comment|/// the complete module name in the import declaration.
comment|///
comment|/// This will return an empty array if the locations of the individual
comment|/// identifiers aren't available.
name|ArrayRef
operator|<
name|SourceLocation
operator|>
name|getIdentifierLocs
argument_list|()
specifier|const
expr_stmt|;
name|SourceRange
name|getSourceRange
argument_list|()
specifier|const
name|override
name|LLVM_READONLY
expr_stmt|;
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
name|Import
return|;
block|}
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|/// \brief Represents a C++ Modules TS module export declaration.
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
comment|///   export void foo();
end_comment

begin_comment
comment|/// \endcode
end_comment

begin_decl_stmt
name|class
name|ExportDecl
name|final
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
name|private
label|:
comment|/// \brief The source location for the right brace (if valid).
name|SourceLocation
name|RBraceLoc
decl_stmt|;
name|ExportDecl
argument_list|(
argument|DeclContext *DC
argument_list|,
argument|SourceLocation ExportLoc
argument_list|)
block|:
name|Decl
argument_list|(
name|Export
argument_list|,
name|DC
argument_list|,
name|ExportLoc
argument_list|)
operator|,
name|DeclContext
argument_list|(
name|Export
argument_list|)
operator|,
name|RBraceLoc
argument_list|(
argument|SourceLocation()
argument_list|)
block|{ }
name|friend
name|class
name|ASTDeclReader
expr_stmt|;
name|public
label|:
specifier|static
name|ExportDecl
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
name|ExportLoc
parameter_list|)
function_decl|;
specifier|static
name|ExportDecl
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
name|SourceLocation
name|getExportLoc
argument_list|()
specifier|const
block|{
return|return
name|getLocation
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
name|getLocEnd
argument_list|()
specifier|const
name|LLVM_READONLY
block|{
if|if
condition|(
name|RBraceLoc
operator|.
name|isValid
argument_list|()
condition|)
return|return
name|RBraceLoc
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
name|override
name|LLVM_READONLY
block|{
return|return
name|SourceRange
argument_list|(
name|getLocation
argument_list|()
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
name|Export
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
name|ExportDecl
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
name|ExportDecl
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
name|ExportDecl
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
name|ExportDecl
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
comment|/// \brief Represents an empty-declaration.
end_comment

begin_decl_stmt
name|class
name|EmptyDecl
range|:
name|public
name|Decl
block|{
name|virtual
name|void
name|anchor
argument_list|()
block|;
name|EmptyDecl
argument_list|(
argument|DeclContext *DC
argument_list|,
argument|SourceLocation L
argument_list|)
operator|:
name|Decl
argument_list|(
argument|Empty
argument_list|,
argument|DC
argument_list|,
argument|L
argument_list|)
block|{ }
name|public
operator|:
specifier|static
name|EmptyDecl
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
specifier|static
name|EmptyDecl
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
name|Empty
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
specifier|const
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
name|DiagnosticsEngine
operator|::
name|ak_nameddecl
argument_list|)
block|;
return|return
name|DB
return|;
block|}
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
expr|,
specifier|const
name|NamedDecl
operator|*
name|ND
operator|)
block|{
name|PD
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
name|DiagnosticsEngine
operator|::
name|ak_nameddecl
argument_list|)
block|;
return|return
name|PD
return|;
block|}
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
name|setPreviousDecl
argument_list|(
argument|decl_type *PrevDecl
argument_list|)
block|{
comment|// Note: This routine is implemented here because we need both NamedDecl
comment|// and Redeclarable to be defined.
name|assert
argument_list|(
name|RedeclLink
operator|.
name|NextIsLatest
argument_list|()
operator|&&
literal|"setPreviousDecl on a decl already in a redeclaration chain"
argument_list|)
block|;
if|if
condition|(
name|PrevDecl
condition|)
block|{
comment|// Point to previous. Make sure that this is actually the most recent
comment|// redeclaration, or we can build invalid chains. If the most recent
comment|// redeclaration is invalid, it won't be PrevDecl, but we want it anyway.
name|First
operator|=
name|PrevDecl
operator|->
name|getFirstDecl
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
name|decl_type
modifier|*
name|MostRecent
init|=
name|First
operator|->
name|getNextRedeclaration
argument_list|()
decl_stmt|;
name|RedeclLink
operator|=
name|PreviousDeclLink
argument_list|(
name|cast
operator|<
name|decl_type
operator|>
operator|(
name|MostRecent
operator|)
argument_list|)
expr_stmt|;
comment|// If the declaration was previously visible, a redeclaration of it remains
comment|// visible even if it wouldn't be visible by itself.
name|static_cast
operator|<
name|decl_type
operator|*
operator|>
operator|(
name|this
operator|)
operator|->
name|IdentifierNamespace
operator||=
name|MostRecent
operator|->
name|getIdentifierNamespace
argument_list|()
operator|&
operator|(
name|Decl
operator|::
name|IDNS_Ordinary
operator||
name|Decl
operator|::
name|IDNS_Tag
operator||
name|Decl
operator|::
name|IDNS_Type
operator|)
expr_stmt|;
block|}
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
comment|// First one will point to this one as latest.
name|First
operator|->
name|RedeclLink
operator|.
name|setLatest
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
name|assert
argument_list|(
operator|!
name|isa
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
operator|||
name|cast
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
operator|->
name|isLinkageValid
argument_list|()
argument_list|)
block|; }
comment|// Inline function definitions.
comment|/// \brief Check if the given decl is complete.
comment|///
comment|/// We use this function to break a cycle between the inline definitions in
comment|/// Type.h and Decl.h.
specifier|inline
name|bool
name|IsEnumDeclComplete
argument_list|(
argument|EnumDecl *ED
argument_list|)
block|{
return|return
name|ED
operator|->
name|isComplete
argument_list|()
return|;
block|}
end_decl_stmt

begin_comment
comment|/// \brief Check if the given decl is scoped.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// We use this function to break a cycle between the inline definitions in
end_comment

begin_comment
comment|/// Type.h and Decl.h.
end_comment

begin_function
specifier|inline
name|bool
name|IsEnumDeclScoped
parameter_list|(
name|EnumDecl
modifier|*
name|ED
parameter_list|)
block|{
return|return
name|ED
operator|->
name|isScoped
argument_list|()
return|;
block|}
end_function

begin_comment
unit|}
comment|// end namespace clang
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

