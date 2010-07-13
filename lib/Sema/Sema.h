begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===--- Sema.h - Semantic Analysis& AST Building --------------*- C++ -*-===//
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
comment|// This file defines the Sema class, which performs semantic analysis and
end_comment

begin_comment
comment|// builds ASTs.
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
name|LLVM_CLANG_AST_SEMA_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_AST_SEMA_H
end_define

begin_include
include|#
directive|include
file|"IdentifierResolver.h"
end_include

begin_include
include|#
directive|include
file|"CXXFieldCollector.h"
end_include

begin_include
include|#
directive|include
file|"SemaOverload.h"
end_include

begin_include
include|#
directive|include
file|"SemaTemplate.h"
end_include

begin_include
include|#
directive|include
file|"AnalysisBasedWarnings.h"
end_include

begin_include
include|#
directive|include
file|"clang/AST/Attr.h"
end_include

begin_include
include|#
directive|include
file|"clang/AST/DeclBase.h"
end_include

begin_include
include|#
directive|include
file|"clang/AST/Decl.h"
end_include

begin_include
include|#
directive|include
file|"clang/AST/DeclObjC.h"
end_include

begin_include
include|#
directive|include
file|"clang/AST/DeclTemplate.h"
end_include

begin_include
include|#
directive|include
file|"clang/AST/ExprCXX.h"
end_include

begin_include
include|#
directive|include
file|"clang/AST/FullExpr.h"
end_include

begin_include
include|#
directive|include
file|"clang/Parse/Action.h"
end_include

begin_include
include|#
directive|include
file|"clang/Sema/SemaDiagnostic.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/SmallVector.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/DenseSet.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/SmallPtrSet.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/OwningPtr.h"
end_include

begin_include
include|#
directive|include
file|<deque>
end_include

begin_include
include|#
directive|include
file|<list>
end_include

begin_include
include|#
directive|include
file|<map>
end_include

begin_include
include|#
directive|include
file|<string>
end_include

begin_include
include|#
directive|include
file|<vector>
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|APSInt
decl_stmt|;
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
name|ASTConsumer
decl_stmt|;
name|class
name|CodeCompleteConsumer
decl_stmt|;
name|class
name|Preprocessor
decl_stmt|;
name|class
name|Decl
decl_stmt|;
name|class
name|DeclContext
decl_stmt|;
name|class
name|DeclSpec
decl_stmt|;
name|class
name|ExternalSemaSource
decl_stmt|;
name|class
name|NamedDecl
decl_stmt|;
name|class
name|Stmt
decl_stmt|;
name|class
name|Expr
decl_stmt|;
name|class
name|InitListExpr
decl_stmt|;
name|class
name|ParenListExpr
decl_stmt|;
name|class
name|DesignatedInitExpr
decl_stmt|;
name|class
name|CallExpr
decl_stmt|;
name|class
name|DeclRefExpr
decl_stmt|;
name|class
name|UnresolvedLookupExpr
decl_stmt|;
name|class
name|UnresolvedMemberExpr
decl_stmt|;
name|class
name|VarDecl
decl_stmt|;
name|class
name|ParmVarDecl
decl_stmt|;
name|class
name|TypedefDecl
decl_stmt|;
name|class
name|FunctionDecl
decl_stmt|;
name|class
name|QualType
decl_stmt|;
name|class
name|LangOptions
decl_stmt|;
name|class
name|Token
decl_stmt|;
name|class
name|IntegerLiteral
decl_stmt|;
name|class
name|StringLiteral
decl_stmt|;
name|class
name|ArrayType
decl_stmt|;
name|class
name|LabelStmt
decl_stmt|;
name|class
name|SwitchStmt
decl_stmt|;
name|class
name|CXXTryStmt
decl_stmt|;
name|class
name|ExtVectorType
decl_stmt|;
name|class
name|TypedefDecl
decl_stmt|;
name|class
name|TemplateDecl
decl_stmt|;
name|class
name|TemplateArgument
decl_stmt|;
name|class
name|TemplateArgumentLoc
decl_stmt|;
name|class
name|TemplateArgumentList
decl_stmt|;
name|class
name|TemplateParameterList
decl_stmt|;
name|class
name|TemplateTemplateParmDecl
decl_stmt|;
name|class
name|ClassTemplatePartialSpecializationDecl
decl_stmt|;
name|class
name|ClassTemplateDecl
decl_stmt|;
name|class
name|ObjCInterfaceDecl
decl_stmt|;
name|class
name|ObjCCompatibleAliasDecl
decl_stmt|;
name|class
name|ObjCProtocolDecl
decl_stmt|;
name|class
name|ObjCImplDecl
decl_stmt|;
name|class
name|ObjCImplementationDecl
decl_stmt|;
name|class
name|ObjCCategoryImplDecl
decl_stmt|;
name|class
name|ObjCCategoryDecl
decl_stmt|;
name|class
name|ObjCIvarDecl
decl_stmt|;
name|class
name|ObjCMethodDecl
decl_stmt|;
name|class
name|ObjCPropertyDecl
decl_stmt|;
name|class
name|ObjCContainerDecl
decl_stmt|;
name|class
name|PseudoDestructorTypeStorage
decl_stmt|;
name|class
name|FunctionProtoType
decl_stmt|;
name|class
name|CXXBasePath
decl_stmt|;
name|class
name|CXXBasePaths
decl_stmt|;
name|class
name|CXXTemporary
decl_stmt|;
name|class
name|LookupResult
decl_stmt|;
name|class
name|InitializedEntity
decl_stmt|;
name|class
name|InitializationKind
decl_stmt|;
name|class
name|InitializationSequence
decl_stmt|;
name|class
name|VisibleDeclConsumer
decl_stmt|;
name|class
name|TargetAttributesSema
decl_stmt|;
name|class
name|ADLResult
decl_stmt|;
comment|/// \brief Retains information about a function, method, or block that is
comment|/// currently being parsed.
struct|struct
name|FunctionScopeInfo
block|{
comment|/// \brief Whether this scope information structure defined information for
comment|/// a block.
name|bool
name|IsBlockInfo
decl_stmt|;
comment|/// \brief Set true when a function, method contains a VLA or ObjC try block,
comment|/// which introduce scopes that need to be checked for goto conditions.  If a
comment|/// function does not contain this, then it need not have the jump checker run on it.
name|bool
name|NeedsScopeChecking
decl_stmt|;
comment|/// \brief The number of errors that had occurred before starting this
comment|/// function or block.
name|unsigned
name|NumErrorsAtStartOfFunction
decl_stmt|;
comment|/// LabelMap - This is a mapping from label identifiers to the LabelStmt for
comment|/// it (which acts like the label decl in some ways).  Forward referenced
comment|/// labels have a LabelStmt created for them with a null location& SubStmt.
name|llvm
operator|::
name|DenseMap
operator|<
name|IdentifierInfo
operator|*
operator|,
name|LabelStmt
operator|*
operator|>
name|LabelMap
expr_stmt|;
comment|/// SwitchStack - This is the current set of active switch statements in the
comment|/// block.
name|llvm
operator|::
name|SmallVector
operator|<
name|SwitchStmt
operator|*
operator|,
literal|8
operator|>
name|SwitchStack
expr_stmt|;
comment|/// \brief The list of return statements that occur within the function or
comment|/// block, if there is any chance of applying the named return value
comment|/// optimization.
name|llvm
operator|::
name|SmallVector
operator|<
name|ReturnStmt
operator|*
operator|,
literal|4
operator|>
name|Returns
expr_stmt|;
name|FunctionScopeInfo
argument_list|(
argument|unsigned NumErrors
argument_list|)
block|:
name|IsBlockInfo
argument_list|(
name|false
argument_list|)
operator|,
name|NeedsScopeChecking
argument_list|(
name|false
argument_list|)
operator|,
name|NumErrorsAtStartOfFunction
argument_list|(
argument|NumErrors
argument_list|)
block|{ }
name|virtual
operator|~
name|FunctionScopeInfo
argument_list|()
expr_stmt|;
comment|/// \brief Clear out the information in this function scope, making it
comment|/// suitable for reuse.
name|void
name|Clear
parameter_list|(
name|unsigned
name|NumErrors
parameter_list|)
function_decl|;
specifier|static
name|bool
name|classof
parameter_list|(
specifier|const
name|FunctionScopeInfo
modifier|*
name|FSI
parameter_list|)
block|{
return|return
name|true
return|;
block|}
block|}
struct|;
comment|/// \brief Retains information about a block that is currently being parsed.
name|struct
name|BlockScopeInfo
range|:
name|FunctionScopeInfo
block|{
name|bool
name|hasBlockDeclRefExprs
block|;
name|BlockDecl
operator|*
name|TheDecl
block|;
comment|/// TheScope - This is the scope for the block itself, which contains
comment|/// arguments etc.
name|Scope
operator|*
name|TheScope
block|;
comment|/// ReturnType - The return type of the block, or null if the block
comment|/// signature didn't provide an explicit return type.
name|QualType
name|ReturnType
block|;
comment|/// BlockType - The function type of the block, if one was given.
comment|/// Its return type may be BuiltinType::Dependent.
name|QualType
name|FunctionType
block|;
name|BlockScopeInfo
argument_list|(
argument|unsigned NumErrors
argument_list|,
argument|Scope *BlockScope
argument_list|,
argument|BlockDecl *Block
argument_list|)
operator|:
name|FunctionScopeInfo
argument_list|(
name|NumErrors
argument_list|)
block|,
name|hasBlockDeclRefExprs
argument_list|(
name|false
argument_list|)
block|,
name|TheDecl
argument_list|(
name|Block
argument_list|)
block|,
name|TheScope
argument_list|(
argument|BlockScope
argument_list|)
block|{
name|IsBlockInfo
operator|=
name|true
block|;   }
name|virtual
operator|~
name|BlockScopeInfo
argument_list|()
block|;
specifier|static
name|bool
name|classof
argument_list|(
argument|const FunctionScopeInfo *FSI
argument_list|)
block|{
return|return
name|FSI
operator|->
name|IsBlockInfo
return|;
block|}
specifier|static
name|bool
name|classof
argument_list|(
argument|const BlockScopeInfo *BSI
argument_list|)
block|{
return|return
name|true
return|;
block|}
expr|}
block|;
comment|/// \brief Holds a QualType and a TypeSourceInfo* that came out of a declarator
comment|/// parsing.
comment|///
comment|/// LocInfoType is a "transient" type, only needed for passing to/from Parser
comment|/// and Sema, when we want to preserve type source info for a parsed type.
comment|/// It will not participate in the type system semantics in any way.
name|class
name|LocInfoType
operator|:
name|public
name|Type
block|{   enum
block|{
comment|// The last number that can fit in Type's TC.
comment|// Avoids conflict with an existing Type class.
name|LocInfo
operator|=
name|Type
operator|::
name|TypeLast
operator|+
literal|1
block|}
block|;
name|TypeSourceInfo
operator|*
name|DeclInfo
block|;
name|LocInfoType
argument_list|(
argument|QualType ty
argument_list|,
argument|TypeSourceInfo *TInfo
argument_list|)
operator|:
name|Type
argument_list|(
operator|(
name|TypeClass
operator|)
name|LocInfo
argument_list|,
name|ty
argument_list|,
name|ty
operator|->
name|isDependentType
argument_list|()
argument_list|)
block|,
name|DeclInfo
argument_list|(
argument|TInfo
argument_list|)
block|{
name|assert
argument_list|(
name|getTypeClass
argument_list|()
operator|==
operator|(
name|TypeClass
operator|)
name|LocInfo
operator|&&
literal|"LocInfo didn't fit in TC?"
argument_list|)
block|;   }
name|friend
name|class
name|Sema
block|;
name|public
operator|:
name|QualType
name|getType
argument_list|()
specifier|const
block|{
return|return
name|getCanonicalTypeInternal
argument_list|()
return|;
block|}
name|TypeSourceInfo
operator|*
name|getTypeSourceInfo
argument_list|()
specifier|const
block|{
return|return
name|DeclInfo
return|;
block|}
name|virtual
name|void
name|getAsStringInternal
argument_list|(
argument|std::string&Str
argument_list|,
argument|const PrintingPolicy&Policy
argument_list|)
specifier|const
block|;
specifier|static
name|bool
name|classof
argument_list|(
argument|const Type *T
argument_list|)
block|{
return|return
name|T
operator|->
name|getTypeClass
argument_list|()
operator|==
operator|(
name|TypeClass
operator|)
name|LocInfo
return|;
block|}
specifier|static
name|bool
name|classof
argument_list|(
argument|const LocInfoType *
argument_list|)
block|{
return|return
name|true
return|;
block|}
expr|}
block|;
comment|/// Sema - This implements semantic analysis and AST building for C.
name|class
name|Sema
operator|:
name|public
name|Action
block|{
name|Sema
argument_list|(
specifier|const
name|Sema
operator|&
argument_list|)
block|;
comment|// DO NOT IMPLEMENT
name|void
name|operator
operator|=
operator|(
specifier|const
name|Sema
operator|&
operator|)
block|;
comment|// DO NOT IMPLEMENT
name|mutable
specifier|const
name|TargetAttributesSema
operator|*
name|TheTargetAttributesSema
block|;
name|public
operator|:
specifier|const
name|LangOptions
operator|&
name|LangOpts
block|;
name|Preprocessor
operator|&
name|PP
block|;
name|ASTContext
operator|&
name|Context
block|;
name|ASTConsumer
operator|&
name|Consumer
block|;
name|Diagnostic
operator|&
name|Diags
block|;
name|SourceManager
operator|&
name|SourceMgr
block|;
comment|/// \brief Source of additional semantic information.
name|ExternalSemaSource
operator|*
name|ExternalSource
block|;
comment|/// \brief Code-completion consumer.
name|CodeCompleteConsumer
operator|*
name|CodeCompleter
block|;
comment|/// CurContext - This is the current declaration context of parsing.
name|DeclContext
operator|*
name|CurContext
block|;
comment|/// VAListTagName - The declaration name corresponding to __va_list_tag.
comment|/// This is used as part of a hack to omit that class from ADL results.
name|DeclarationName
name|VAListTagName
block|;
comment|/// A RAII object to temporarily push a declaration context.
name|class
name|ContextRAII
block|{
name|private
operator|:
name|Sema
operator|&
name|S
block|;
name|DeclContext
operator|*
name|SavedContext
block|;
name|public
operator|:
name|ContextRAII
argument_list|(
name|Sema
operator|&
name|S
argument_list|,
name|DeclContext
operator|*
name|ContextToPush
argument_list|)
operator|:
name|S
argument_list|(
name|S
argument_list|)
block|,
name|SavedContext
argument_list|(
argument|S.CurContext
argument_list|)
block|{
name|assert
argument_list|(
name|ContextToPush
operator|&&
literal|"pushing null context"
argument_list|)
block|;
name|S
operator|.
name|CurContext
operator|=
name|ContextToPush
block|;     }
name|void
name|pop
argument_list|()
block|{
if|if
condition|(
operator|!
name|SavedContext
condition|)
return|return;
name|S
operator|.
name|CurContext
operator|=
name|SavedContext
block|;
name|SavedContext
operator|=
literal|0
block|;     }
operator|~
name|ContextRAII
argument_list|()
block|{
name|pop
argument_list|()
block|;     }
block|}
block|;
comment|/// PackContext - Manages the stack for #pragma pack. An alignment
comment|/// of 0 indicates default alignment.
name|void
operator|*
name|PackContext
block|;
comment|// Really a "PragmaPackStack*"
comment|/// \brief Stack containing information about each of the nested function,
comment|/// block, and method scopes that are currently active.
name|llvm
operator|::
name|SmallVector
operator|<
name|FunctionScopeInfo
operator|*
block|,
literal|4
operator|>
name|FunctionScopes
block|;
comment|/// \brief Cached function scope object used for the top function scope
comment|/// and when there is no function scope (in error cases).
comment|///
comment|/// This should never be accessed directly; rather, it's address will be
comment|/// pushed into \c FunctionScopes when we want to re-use it.
name|FunctionScopeInfo
name|TopFunctionScope
block|;
comment|/// ExprTemporaries - This is the stack of temporaries that are created by
comment|/// the current full expression.
name|llvm
operator|::
name|SmallVector
operator|<
name|CXXTemporary
operator|*
block|,
literal|8
operator|>
name|ExprTemporaries
block|;
comment|/// ExtVectorDecls - This is a list all the extended vector types. This allows
comment|/// us to associate a raw vector type with one of the ext_vector type names.
comment|/// This is only necessary for issuing pretty diagnostics.
name|llvm
operator|::
name|SmallVector
operator|<
name|TypedefDecl
operator|*
block|,
literal|24
operator|>
name|ExtVectorDecls
block|;
comment|/// FieldCollector - Collects CXXFieldDecls during parsing of C++ classes.
name|llvm
operator|::
name|OwningPtr
operator|<
name|CXXFieldCollector
operator|>
name|FieldCollector
block|;
typedef|typedef
name|llvm
operator|::
name|SmallPtrSet
operator|<
specifier|const
name|CXXRecordDecl
operator|*
operator|,
literal|8
operator|>
name|RecordDeclSetTy
expr_stmt|;
comment|/// PureVirtualClassDiagSet - a set of class declarations which we have
comment|/// emitted a list of pure virtual functions. Used to prevent emitting the
comment|/// same list more than once.
name|llvm
operator|::
name|OwningPtr
operator|<
name|RecordDeclSetTy
operator|>
name|PureVirtualClassDiagSet
block|;
comment|/// \brief A mapping from external names to the most recent
comment|/// locally-scoped external declaration with that name.
comment|///
comment|/// This map contains external declarations introduced in local
comment|/// scoped, e.g.,
comment|///
comment|/// \code
comment|/// void f() {
comment|///   void foo(int, int);
comment|/// }
comment|/// \endcode
comment|///
comment|/// Here, the name "foo" will be associated with the declaration on
comment|/// "foo" within f. This name is not visible outside of
comment|/// "f". However, we still find it in two cases:
comment|///
comment|///   - If we are declaring another external with the name "foo", we
comment|///     can find "foo" as a previous declaration, so that the types
comment|///     of this external declaration can be checked for
comment|///     compatibility.
comment|///
comment|///   - If we would implicitly declare "foo" (e.g., due to a call to
comment|///     "foo" in C when no prototype or definition is visible), then
comment|///     we find this declaration of "foo" and complain that it is
comment|///     not visible.
name|llvm
operator|::
name|DenseMap
operator|<
name|DeclarationName
block|,
name|NamedDecl
operator|*
operator|>
name|LocallyScopedExternalDecls
block|;
comment|/// \brief All the tentative definitions encountered in the TU.
name|std
operator|::
name|vector
operator|<
name|VarDecl
operator|*
operator|>
name|TentativeDefinitions
block|;
comment|/// \brief The set of static functions seen so far that have not been used.
name|std
operator|::
name|vector
operator|<
name|FunctionDecl
operator|*
operator|>
name|UnusedStaticFuncs
block|;
name|class
name|AccessedEntity
block|{
name|public
operator|:
comment|/// A member declaration found through lookup.  The target is the
comment|/// member.
expr|enum
name|MemberNonce
block|{
name|Member
block|}
block|;
comment|/// A hierarchy (base-to-derived or derived-to-base) conversion.
comment|/// The target is the base class.
block|enum
name|BaseNonce
block|{
name|Base
block|}
block|;
name|bool
name|isMemberAccess
argument_list|()
specifier|const
block|{
return|return
name|IsMember
return|;
block|}
name|AccessedEntity
argument_list|(
argument|ASTContext&Context
argument_list|,
argument|MemberNonce _
argument_list|,
argument|CXXRecordDecl *NamingClass
argument_list|,
argument|DeclAccessPair FoundDecl
argument_list|,
argument|QualType BaseObjectType
argument_list|)
operator|:
name|Access
argument_list|(
name|FoundDecl
operator|.
name|getAccess
argument_list|()
argument_list|)
block|,
name|IsMember
argument_list|(
name|true
argument_list|)
block|,
name|Target
argument_list|(
name|FoundDecl
operator|.
name|getDecl
argument_list|()
argument_list|)
block|,
name|NamingClass
argument_list|(
name|NamingClass
argument_list|)
block|,
name|BaseObjectType
argument_list|(
name|BaseObjectType
argument_list|)
block|,
name|Diag
argument_list|(
literal|0
argument_list|,
argument|Context.getDiagAllocator()
argument_list|)
block|{     }
name|AccessedEntity
argument_list|(
argument|ASTContext&Context
argument_list|,
argument|BaseNonce _
argument_list|,
argument|CXXRecordDecl *BaseClass
argument_list|,
argument|CXXRecordDecl *DerivedClass
argument_list|,
argument|AccessSpecifier Access
argument_list|)
operator|:
name|Access
argument_list|(
name|Access
argument_list|)
block|,
name|IsMember
argument_list|(
name|false
argument_list|)
block|,
name|Target
argument_list|(
name|BaseClass
argument_list|)
block|,
name|NamingClass
argument_list|(
name|DerivedClass
argument_list|)
block|,
name|Diag
argument_list|(
literal|0
argument_list|,
argument|Context.getDiagAllocator()
argument_list|)
block|{     }
name|bool
name|isQuiet
argument_list|()
specifier|const
block|{
return|return
name|Diag
operator|.
name|getDiagID
argument_list|()
operator|==
literal|0
return|;
block|}
name|AccessSpecifier
name|getAccess
argument_list|()
specifier|const
block|{
return|return
name|AccessSpecifier
argument_list|(
name|Access
argument_list|)
return|;
block|}
comment|// These apply to member decls...
name|NamedDecl
operator|*
name|getTargetDecl
argument_list|()
specifier|const
block|{
return|return
name|Target
return|;
block|}
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
comment|// ...and these apply to hierarchy conversions.
name|CXXRecordDecl
operator|*
name|getBaseClass
argument_list|()
specifier|const
block|{
return|return
name|cast
operator|<
name|CXXRecordDecl
operator|>
operator|(
name|Target
operator|)
return|;
block|}
name|CXXRecordDecl
operator|*
name|getDerivedClass
argument_list|()
specifier|const
block|{
return|return
name|NamingClass
return|;
block|}
comment|/// Retrieves the base object type, important when accessing
comment|/// an instance member.
name|QualType
name|getBaseObjectType
argument_list|()
specifier|const
block|{
return|return
name|BaseObjectType
return|;
block|}
comment|/// Sets a diagnostic to be performed.  The diagnostic is given
comment|/// four (additional) arguments:
comment|///   %0 - 0 if the entity was private, 1 if protected
comment|///   %1 - the DeclarationName of the entity
comment|///   %2 - the TypeDecl type of the naming class
comment|///   %3 - the TypeDecl type of the declaring class
name|void
name|setDiag
argument_list|(
argument|const PartialDiagnostic&PDiag
argument_list|)
block|{
name|assert
argument_list|(
name|isQuiet
argument_list|()
operator|&&
literal|"partial diagnostic already defined"
argument_list|)
block|;
name|Diag
operator|=
name|PDiag
block|;     }
name|PartialDiagnostic
operator|&
name|setDiag
argument_list|(
argument|unsigned DiagID
argument_list|)
block|{
name|assert
argument_list|(
name|isQuiet
argument_list|()
operator|&&
literal|"partial diagnostic already defined"
argument_list|)
block|;
name|assert
argument_list|(
name|DiagID
operator|&&
literal|"creating null diagnostic"
argument_list|)
block|;
name|Diag
operator|.
name|Reset
argument_list|(
name|DiagID
argument_list|)
block|;
return|return
name|Diag
return|;
block|}
specifier|const
name|PartialDiagnostic
operator|&
name|getDiag
argument_list|()
specifier|const
block|{
return|return
name|Diag
return|;
block|}
name|private
operator|:
name|unsigned
name|Access
operator|:
literal|2
block|;
name|bool
name|IsMember
block|;
name|NamedDecl
operator|*
name|Target
block|;
name|CXXRecordDecl
operator|*
name|NamingClass
block|;
name|QualType
name|BaseObjectType
block|;
name|PartialDiagnostic
name|Diag
block|;   }
block|;    struct
name|DelayedDiagnostic
block|{     enum
name|DDKind
block|{
name|Deprecation
block|,
name|Access
block|}
block|;
name|unsigned
name|char
name|Kind
block|;
comment|// actually a DDKind
name|bool
name|Triggered
block|;
name|SourceLocation
name|Loc
block|;
expr|union
block|{
comment|/// Deprecation.
block|struct
block|{
name|NamedDecl
operator|*
name|Decl
block|; }
name|DeprecationData
block|;
comment|/// Access control.
name|char
name|AccessData
index|[
sizeof|sizeof
argument_list|(
name|AccessedEntity
argument_list|)
index|]
block|;     }
block|;
name|void
name|destroy
argument_list|()
block|{
switch|switch
condition|(
name|Kind
condition|)
block|{
case|case
name|Access
case|:
name|getAccessData
argument_list|()
operator|.
operator|~
name|AccessedEntity
argument_list|()
expr_stmt|;
break|break;
case|case
name|Deprecation
case|:
break|break;
block|}
block|}
specifier|static
name|DelayedDiagnostic
name|makeDeprecation
argument_list|(
argument|SourceLocation Loc
argument_list|,
argument|NamedDecl *D
argument_list|)
block|{
name|DelayedDiagnostic
name|DD
block|;
name|DD
operator|.
name|Kind
operator|=
name|Deprecation
block|;
name|DD
operator|.
name|Triggered
operator|=
name|false
block|;
name|DD
operator|.
name|Loc
operator|=
name|Loc
block|;
name|DD
operator|.
name|DeprecationData
operator|.
name|Decl
operator|=
name|D
block|;
return|return
name|DD
return|;
block|}
specifier|static
name|DelayedDiagnostic
name|makeAccess
argument_list|(
argument|SourceLocation Loc
argument_list|,
argument|const AccessedEntity&Entity
argument_list|)
block|{
name|DelayedDiagnostic
name|DD
block|;
name|DD
operator|.
name|Kind
operator|=
name|Access
block|;
name|DD
operator|.
name|Triggered
operator|=
name|false
block|;
name|DD
operator|.
name|Loc
operator|=
name|Loc
block|;
name|new
argument_list|(
argument|&DD.getAccessData()
argument_list|)
name|AccessedEntity
argument_list|(
name|Entity
argument_list|)
block|;
return|return
name|DD
return|;
block|}
name|AccessedEntity
operator|&
name|getAccessData
argument_list|()
block|{
return|return
operator|*
name|reinterpret_cast
operator|<
name|AccessedEntity
operator|*
operator|>
operator|(
name|AccessData
operator|)
return|;
block|}
specifier|const
name|AccessedEntity
operator|&
name|getAccessData
argument_list|()
specifier|const
block|{
return|return
operator|*
name|reinterpret_cast
operator|<
specifier|const
name|AccessedEntity
operator|*
operator|>
operator|(
name|AccessData
operator|)
return|;
block|}
expr|}
block|;
comment|/// \brief The stack of diagnostics that were delayed due to being
comment|/// produced during the parsing of a declaration.
name|llvm
operator|::
name|SmallVector
operator|<
name|DelayedDiagnostic
block|,
literal|8
operator|>
name|DelayedDiagnostics
block|;
comment|/// \brief The depth of the current ParsingDeclaration stack.
comment|/// If nonzero, we are currently parsing a declaration (and
comment|/// hence should delay deprecation warnings).
name|unsigned
name|ParsingDeclDepth
block|;
comment|/// WeakUndeclaredIdentifiers - Identifiers contained in
comment|/// #pragma weak before declared. rare. may alias another
comment|/// identifier, declared or undeclared
name|class
name|WeakInfo
block|{
name|IdentifierInfo
operator|*
name|alias
block|;
comment|// alias (optional)
name|SourceLocation
name|loc
block|;
comment|// for diagnostics
name|bool
name|used
block|;
comment|// identifier later declared?
name|public
operator|:
name|WeakInfo
argument_list|()
operator|:
name|alias
argument_list|(
literal|0
argument_list|)
block|,
name|loc
argument_list|(
name|SourceLocation
argument_list|()
argument_list|)
block|,
name|used
argument_list|(
argument|false
argument_list|)
block|{}
name|WeakInfo
argument_list|(
argument|IdentifierInfo *Alias
argument_list|,
argument|SourceLocation Loc
argument_list|)
operator|:
name|alias
argument_list|(
name|Alias
argument_list|)
block|,
name|loc
argument_list|(
name|Loc
argument_list|)
block|,
name|used
argument_list|(
argument|false
argument_list|)
block|{}
specifier|inline
name|IdentifierInfo
operator|*
name|getAlias
argument_list|()
specifier|const
block|{
return|return
name|alias
return|;
block|}
specifier|inline
name|SourceLocation
name|getLocation
argument_list|()
specifier|const
block|{
return|return
name|loc
return|;
block|}
name|void
name|setUsed
argument_list|(
argument|bool Used=true
argument_list|)
block|{
name|used
operator|=
name|Used
block|; }
specifier|inline
name|bool
name|getUsed
argument_list|()
block|{
return|return
name|used
return|;
block|}
name|bool
name|operator
operator|==
operator|(
name|WeakInfo
name|RHS
operator|)
specifier|const
block|{
return|return
name|alias
operator|==
name|RHS
operator|.
name|getAlias
argument_list|()
operator|&&
name|loc
operator|==
name|RHS
operator|.
name|getLocation
argument_list|()
return|;
block|}
name|bool
name|operator
operator|!=
operator|(
name|WeakInfo
name|RHS
operator|)
specifier|const
block|{
return|return
operator|!
operator|(
operator|*
name|this
operator|==
name|RHS
operator|)
return|;
block|}
expr|}
block|;
name|llvm
operator|::
name|DenseMap
operator|<
name|IdentifierInfo
operator|*
block|,
name|WeakInfo
operator|>
name|WeakUndeclaredIdentifiers
block|;
comment|/// WeakTopLevelDecl - Translation-unit scoped declarations generated by
comment|/// #pragma weak during processing of other Decls.
comment|/// I couldn't figure out a clean way to generate these in-line, so
comment|/// we store them here and handle separately -- which is a hack.
comment|/// It would be best to refactor this.
name|llvm
operator|::
name|SmallVector
operator|<
name|Decl
operator|*
block|,
literal|2
operator|>
name|WeakTopLevelDecl
block|;
name|IdentifierResolver
name|IdResolver
block|;
comment|/// Translation Unit Scope - useful to Objective-C actions that need
comment|/// to lookup file scope declarations in the "ordinary" C decl namespace.
comment|/// For example, user-defined classes, built-in "id" type, etc.
name|Scope
operator|*
name|TUScope
block|;
comment|/// \brief The C++ "std" namespace, where the standard library resides.
name|NamespaceDecl
operator|*
name|StdNamespace
block|;
comment|/// \brief The C++ "std::bad_alloc" class, which is defined by the C++
comment|/// standard library.
name|CXXRecordDecl
operator|*
name|StdBadAlloc
block|;
comment|/// A flag to remember whether the implicit forms of operator new and delete
comment|/// have been declared.
name|bool
name|GlobalNewDeleteDeclared
block|;
comment|/// \brief The set of declarations that have been referenced within
comment|/// a potentially evaluated expression.
typedef|typedef
name|std
operator|::
name|vector
operator|<
name|std
operator|::
name|pair
operator|<
name|SourceLocation
operator|,
name|Decl
operator|*
operator|>
expr|>
name|PotentiallyReferencedDecls
expr_stmt|;
comment|/// \brief A set of diagnostics that may be emitted.
typedef|typedef
name|std
operator|::
name|vector
operator|<
name|std
operator|::
name|pair
operator|<
name|SourceLocation
operator|,
name|PartialDiagnostic
operator|>
expr|>
name|PotentiallyEmittedDiagnostics
expr_stmt|;
comment|/// \brief Data structure used to record current or nested
comment|/// expression evaluation contexts.
block|struct
name|ExpressionEvaluationContextRecord
block|{
comment|/// \brief The expression evaluation context.
name|ExpressionEvaluationContext
name|Context
block|;
comment|/// \brief The number of temporaries that were active when we
comment|/// entered this expression evaluation context.
name|unsigned
name|NumTemporaries
block|;
comment|/// \brief The set of declarations referenced within a
comment|/// potentially potentially-evaluated context.
comment|///
comment|/// When leaving a potentially potentially-evaluated context, each
comment|/// of these elements will be as referenced if the corresponding
comment|/// potentially potentially evaluated expression is potentially
comment|/// evaluated.
name|PotentiallyReferencedDecls
operator|*
name|PotentiallyReferenced
block|;
comment|/// \brief The set of diagnostics to emit should this potentially
comment|/// potentially-evaluated context become evaluated.
name|PotentiallyEmittedDiagnostics
operator|*
name|PotentiallyDiagnosed
block|;
name|ExpressionEvaluationContextRecord
argument_list|(
argument|ExpressionEvaluationContext Context
argument_list|,
argument|unsigned NumTemporaries
argument_list|)
operator|:
name|Context
argument_list|(
name|Context
argument_list|)
block|,
name|NumTemporaries
argument_list|(
name|NumTemporaries
argument_list|)
block|,
name|PotentiallyReferenced
argument_list|(
literal|0
argument_list|)
block|,
name|PotentiallyDiagnosed
argument_list|(
literal|0
argument_list|)
block|{ }
name|void
name|addReferencedDecl
argument_list|(
argument|SourceLocation Loc
argument_list|,
argument|Decl *Decl
argument_list|)
block|{
if|if
condition|(
operator|!
name|PotentiallyReferenced
condition|)
name|PotentiallyReferenced
operator|=
name|new
name|PotentiallyReferencedDecls
expr_stmt|;
name|PotentiallyReferenced
operator|->
name|push_back
argument_list|(
name|std
operator|::
name|make_pair
argument_list|(
name|Loc
argument_list|,
name|Decl
argument_list|)
argument_list|)
block|;     }
name|void
name|addDiagnostic
argument_list|(
argument|SourceLocation Loc
argument_list|,
argument|const PartialDiagnostic&PD
argument_list|)
block|{
if|if
condition|(
operator|!
name|PotentiallyDiagnosed
condition|)
name|PotentiallyDiagnosed
operator|=
name|new
name|PotentiallyEmittedDiagnostics
expr_stmt|;
name|PotentiallyDiagnosed
operator|->
name|push_back
argument_list|(
name|std
operator|::
name|make_pair
argument_list|(
name|Loc
argument_list|,
name|PD
argument_list|)
argument_list|)
block|;     }
name|void
name|Destroy
argument_list|()
block|{
name|delete
name|PotentiallyReferenced
block|;
name|delete
name|PotentiallyDiagnosed
block|;
name|PotentiallyReferenced
operator|=
literal|0
block|;
name|PotentiallyDiagnosed
operator|=
literal|0
block|;     }
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|/// A stack of expression evaluation contexts.
end_comment

begin_expr_stmt
name|llvm
operator|::
name|SmallVector
operator|<
name|ExpressionEvaluationContextRecord
operator|,
literal|8
operator|>
name|ExprEvalContexts
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// \brief Whether the code handled by Sema should be considered a
end_comment

begin_comment
comment|/// complete translation unit or not.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// When true (which is generally the case), Sema will perform
end_comment

begin_comment
comment|/// end-of-translation-unit semantic tasks (such as creating
end_comment

begin_comment
comment|/// initializers for tentative definitions in C) once parsing has
end_comment

begin_comment
comment|/// completed. This flag will be false when building PCH files,
end_comment

begin_comment
comment|/// since a PCH file is by definition not a complete translation
end_comment

begin_comment
comment|/// unit.
end_comment

begin_decl_stmt
name|bool
name|CompleteTranslationUnit
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|llvm
operator|::
name|BumpPtrAllocator
name|BumpAlloc
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// \brief The number of SFINAE diagnostics that have been trapped.
end_comment

begin_decl_stmt
name|unsigned
name|NumSFINAEErrors
decl_stmt|;
end_decl_stmt

begin_typedef
typedef|typedef
name|llvm
operator|::
name|DenseMap
operator|<
name|Selector
operator|,
name|ObjCMethodList
operator|>
name|MethodPool
expr_stmt|;
end_typedef

begin_comment
comment|/// Instance/Factory Method Pools - allows efficient lookup when typechecking
end_comment

begin_comment
comment|/// messages to "id". We need to maintain a list, since selectors can have
end_comment

begin_comment
comment|/// differing signatures across classes. In Cocoa, this happens to be
end_comment

begin_comment
comment|/// extremely uncommon (only 1% of selectors are "overloaded").
end_comment

begin_decl_stmt
name|MethodPool
name|InstanceMethodPool
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|MethodPool
name|FactoryMethodPool
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|MethodPool
operator|::
name|iterator
name|ReadMethodPool
argument_list|(
argument|Selector Sel
argument_list|,
argument|bool isInstance
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// Private Helper predicate to check for 'self'.
end_comment

begin_function_decl
name|bool
name|isSelfExpr
parameter_list|(
name|Expr
modifier|*
name|RExpr
parameter_list|)
function_decl|;
end_function_decl

begin_label
name|public
label|:
end_label

begin_macro
name|Sema
argument_list|(
argument|Preprocessor&pp
argument_list|,
argument|ASTContext&ctxt
argument_list|,
argument|ASTConsumer&consumer
argument_list|,
argument|bool CompleteTranslationUnit = true
argument_list|,
argument|CodeCompleteConsumer *CompletionConsumer =
literal|0
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_expr_stmt
operator|~
name|Sema
argument_list|()
expr_stmt|;
end_expr_stmt

begin_expr_stmt
specifier|const
name|LangOptions
operator|&
name|getLangOptions
argument_list|()
specifier|const
block|{
return|return
name|LangOpts
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|Diagnostic
operator|&
name|getDiagnostics
argument_list|()
specifier|const
block|{
return|return
name|Diags
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|SourceManager
operator|&
name|getSourceManager
argument_list|()
specifier|const
block|{
return|return
name|SourceMgr
return|;
block|}
end_expr_stmt

begin_expr_stmt
specifier|const
name|TargetAttributesSema
operator|&
name|getTargetAttributesSema
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// \brief Helper class that creates diagnostics with optional
end_comment

begin_comment
comment|/// template instantiation stacks.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This class provides a wrapper around the basic DiagnosticBuilder
end_comment

begin_comment
comment|/// class that emits diagnostics. SemaDiagnosticBuilder is
end_comment

begin_comment
comment|/// responsible for emitting the diagnostic (as DiagnosticBuilder
end_comment

begin_comment
comment|/// does) and, if the diagnostic comes from inside a template
end_comment

begin_comment
comment|/// instantiation, printing the template instantiation stack as
end_comment

begin_comment
comment|/// well.
end_comment

begin_decl_stmt
name|class
name|SemaDiagnosticBuilder
range|:
name|public
name|DiagnosticBuilder
block|{
name|Sema
operator|&
name|SemaRef
block|;
name|unsigned
name|DiagID
block|;
name|public
operator|:
name|SemaDiagnosticBuilder
argument_list|(
argument|DiagnosticBuilder&DB
argument_list|,
argument|Sema&SemaRef
argument_list|,
argument|unsigned DiagID
argument_list|)
operator|:
name|DiagnosticBuilder
argument_list|(
name|DB
argument_list|)
block|,
name|SemaRef
argument_list|(
name|SemaRef
argument_list|)
block|,
name|DiagID
argument_list|(
argument|DiagID
argument_list|)
block|{ }
name|explicit
name|SemaDiagnosticBuilder
argument_list|(
name|Sema
operator|&
name|SemaRef
argument_list|)
operator|:
name|DiagnosticBuilder
argument_list|(
name|DiagnosticBuilder
operator|::
name|Suppress
argument_list|)
block|,
name|SemaRef
argument_list|(
argument|SemaRef
argument_list|)
block|{ }
operator|~
name|SemaDiagnosticBuilder
argument_list|()
block|;   }
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// \brief Emit a diagnostic.
end_comment

begin_function_decl
name|SemaDiagnosticBuilder
name|Diag
parameter_list|(
name|SourceLocation
name|Loc
parameter_list|,
name|unsigned
name|DiagID
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// \brief Emit a partial diagnostic.
end_comment

begin_function_decl
name|SemaDiagnosticBuilder
name|Diag
parameter_list|(
name|SourceLocation
name|Loc
parameter_list|,
specifier|const
name|PartialDiagnostic
modifier|&
name|PD
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// \brief Build a partial diagnostic.
end_comment

begin_function
name|PartialDiagnostic
name|PDiag
parameter_list|(
name|unsigned
name|DiagID
init|=
literal|0
parameter_list|)
block|{
return|return
name|PartialDiagnostic
argument_list|(
name|DiagID
argument_list|,
name|Context
operator|.
name|getDiagAllocator
argument_list|()
argument_list|)
return|;
block|}
end_function

begin_function_decl
name|virtual
name|void
name|DeleteExpr
parameter_list|(
name|ExprTy
modifier|*
name|E
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|virtual
name|void
name|DeleteStmt
parameter_list|(
name|StmtTy
modifier|*
name|S
parameter_list|)
function_decl|;
end_function_decl

begin_function
name|OwningExprResult
name|Owned
parameter_list|(
name|Expr
modifier|*
name|E
parameter_list|)
block|{
name|assert
argument_list|(
operator|!
name|E
operator|||
name|E
operator|->
name|isRetained
argument_list|()
argument_list|)
expr_stmt|;
return|return
name|OwningExprResult
argument_list|(
operator|*
name|this
argument_list|,
name|E
argument_list|)
return|;
block|}
end_function

begin_function
name|OwningExprResult
name|Owned
parameter_list|(
name|ExprResult
name|R
parameter_list|)
block|{
if|if
condition|(
name|R
operator|.
name|isInvalid
argument_list|()
condition|)
return|return
name|ExprError
argument_list|()
return|;
name|assert
argument_list|(
operator|!
name|R
operator|.
name|get
argument_list|()
operator|||
operator|(
operator|(
name|Expr
operator|*
operator|)
name|R
operator|.
name|get
argument_list|()
operator|)
operator|->
name|isRetained
argument_list|()
argument_list|)
expr_stmt|;
return|return
name|OwningExprResult
argument_list|(
operator|*
name|this
argument_list|,
name|R
operator|.
name|get
argument_list|()
argument_list|)
return|;
block|}
end_function

begin_function
name|OwningStmtResult
name|Owned
parameter_list|(
name|Stmt
modifier|*
name|S
parameter_list|)
block|{
name|assert
argument_list|(
operator|!
name|S
operator|||
name|S
operator|->
name|isRetained
argument_list|()
argument_list|)
expr_stmt|;
return|return
name|OwningStmtResult
argument_list|(
operator|*
name|this
argument_list|,
name|S
argument_list|)
return|;
block|}
end_function

begin_function_decl
name|virtual
name|void
name|ActOnEndOfTranslationUnit
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|Scope
modifier|*
name|getScopeForContext
parameter_list|(
name|DeclContext
modifier|*
name|Ctx
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|PushFunctionScope
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|PushBlockScope
parameter_list|(
name|Scope
modifier|*
name|BlockScope
parameter_list|,
name|BlockDecl
modifier|*
name|Block
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|PopFunctionOrBlockScope
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/// getLabelMap() - Return the current label map.  If we're in a block, we
end_comment

begin_comment
comment|/// return it.
end_comment

begin_expr_stmt
name|llvm
operator|::
name|DenseMap
operator|<
name|IdentifierInfo
operator|*
operator|,
name|LabelStmt
operator|*
operator|>
operator|&
name|getLabelMap
argument_list|()
block|{
if|if
condition|(
name|FunctionScopes
operator|.
name|empty
argument_list|()
condition|)
return|return
name|TopFunctionScope
operator|.
name|LabelMap
return|;
end_expr_stmt

begin_return
return|return
name|FunctionScopes
operator|.
name|back
argument_list|()
operator|->
name|LabelMap
return|;
end_return

begin_comment
unit|}
comment|/// getSwitchStack - This is returns the switch stack for the current block or
end_comment

begin_comment
comment|/// function.
end_comment

begin_expr_stmt
unit|llvm
operator|::
name|SmallVector
operator|<
name|SwitchStmt
operator|*
operator|,
literal|8
operator|>
operator|&
name|getSwitchStack
argument_list|()
block|{
if|if
condition|(
name|FunctionScopes
operator|.
name|empty
argument_list|()
condition|)
return|return
name|TopFunctionScope
operator|.
name|SwitchStack
return|;
end_expr_stmt

begin_return
return|return
name|FunctionScopes
operator|.
name|back
argument_list|()
operator|->
name|SwitchStack
return|;
end_return

begin_comment
unit|}
comment|/// \brief Determine whether the current function or block needs scope
end_comment

begin_comment
comment|/// checking.
end_comment

begin_expr_stmt
unit|bool
operator|&
name|FunctionNeedsScopeChecking
argument_list|()
block|{
if|if
condition|(
name|FunctionScopes
operator|.
name|empty
argument_list|()
condition|)
return|return
name|TopFunctionScope
operator|.
name|NeedsScopeChecking
return|;
end_expr_stmt

begin_return
return|return
name|FunctionScopes
operator|.
name|back
argument_list|()
operator|->
name|NeedsScopeChecking
return|;
end_return

begin_macro
unit|}    bool
name|hasAnyErrorsInThisFunction
argument_list|()
end_macro

begin_decl_stmt
specifier|const
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// \brief Retrieve the current block, if any.
end_comment

begin_function_decl
name|BlockScopeInfo
modifier|*
name|getCurBlock
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/// WeakTopLevelDeclDecls - access to #pragma weak-generated Decls
end_comment

begin_expr_stmt
name|llvm
operator|::
name|SmallVector
operator|<
name|Decl
operator|*
operator|,
literal|2
operator|>
operator|&
name|WeakTopLevelDecls
argument_list|()
block|{
return|return
name|WeakTopLevelDecl
return|;
block|}
end_expr_stmt

begin_comment
comment|//===--------------------------------------------------------------------===//
end_comment

begin_comment
comment|// Type Analysis / Processing: SemaType.cpp.
end_comment

begin_comment
comment|//
end_comment

begin_function_decl
name|QualType
name|adjustParameterType
parameter_list|(
name|QualType
name|T
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|QualType
name|BuildQualifiedType
parameter_list|(
name|QualType
name|T
parameter_list|,
name|SourceLocation
name|Loc
parameter_list|,
name|Qualifiers
name|Qs
parameter_list|)
function_decl|;
end_function_decl

begin_function
name|QualType
name|BuildQualifiedType
parameter_list|(
name|QualType
name|T
parameter_list|,
name|SourceLocation
name|Loc
parameter_list|,
name|unsigned
name|CVR
parameter_list|)
block|{
return|return
name|BuildQualifiedType
argument_list|(
name|T
argument_list|,
name|Loc
argument_list|,
name|Qualifiers
operator|::
name|fromCVRMask
argument_list|(
name|CVR
argument_list|)
argument_list|)
return|;
block|}
end_function

begin_function_decl
name|QualType
name|BuildPointerType
parameter_list|(
name|QualType
name|T
parameter_list|,
name|SourceLocation
name|Loc
parameter_list|,
name|DeclarationName
name|Entity
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|QualType
name|BuildReferenceType
parameter_list|(
name|QualType
name|T
parameter_list|,
name|bool
name|LValueRef
parameter_list|,
name|SourceLocation
name|Loc
parameter_list|,
name|DeclarationName
name|Entity
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
name|QualType
name|BuildArrayType
argument_list|(
name|QualType
name|T
argument_list|,
name|ArrayType
operator|::
name|ArraySizeModifier
name|ASM
argument_list|,
name|Expr
operator|*
name|ArraySize
argument_list|,
name|unsigned
name|Quals
argument_list|,
name|SourceRange
name|Brackets
argument_list|,
name|DeclarationName
name|Entity
argument_list|)
decl_stmt|;
end_decl_stmt

begin_function_decl
name|QualType
name|BuildExtVectorType
parameter_list|(
name|QualType
name|T
parameter_list|,
name|ExprArg
name|ArraySize
parameter_list|,
name|SourceLocation
name|AttrLoc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|QualType
name|BuildFunctionType
parameter_list|(
name|QualType
name|T
parameter_list|,
name|QualType
modifier|*
name|ParamTypes
parameter_list|,
name|unsigned
name|NumParamTypes
parameter_list|,
name|bool
name|Variadic
parameter_list|,
name|unsigned
name|Quals
parameter_list|,
name|SourceLocation
name|Loc
parameter_list|,
name|DeclarationName
name|Entity
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|QualType
name|BuildMemberPointerType
parameter_list|(
name|QualType
name|T
parameter_list|,
name|QualType
name|Class
parameter_list|,
name|SourceLocation
name|Loc
parameter_list|,
name|DeclarationName
name|Entity
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|QualType
name|BuildBlockPointerType
parameter_list|(
name|QualType
name|T
parameter_list|,
name|SourceLocation
name|Loc
parameter_list|,
name|DeclarationName
name|Entity
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|TypeSourceInfo
modifier|*
name|GetTypeForDeclarator
parameter_list|(
name|Declarator
modifier|&
name|D
parameter_list|,
name|Scope
modifier|*
name|S
parameter_list|,
name|TagDecl
modifier|*
modifier|*
name|OwnedDecl
init|=
literal|0
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|TypeSourceInfo
modifier|*
name|GetTypeSourceInfoForDeclarator
parameter_list|(
name|Declarator
modifier|&
name|D
parameter_list|,
name|QualType
name|T
parameter_list|,
name|TypeSourceInfo
modifier|*
name|ReturnTypeInfo
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// \brief Create a LocInfoType to hold the given QualType and TypeSourceInfo.
end_comment

begin_function_decl
name|QualType
name|CreateLocInfoType
parameter_list|(
name|QualType
name|T
parameter_list|,
name|TypeSourceInfo
modifier|*
name|TInfo
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|DeclarationName
name|GetNameForDeclarator
parameter_list|(
name|Declarator
modifier|&
name|D
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|DeclarationName
name|GetNameFromUnqualifiedId
parameter_list|(
specifier|const
name|UnqualifiedId
modifier|&
name|Name
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|QualType
name|GetTypeFromParser
parameter_list|(
name|TypeTy
modifier|*
name|Ty
parameter_list|,
name|TypeSourceInfo
modifier|*
modifier|*
name|TInfo
init|=
literal|0
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|CheckSpecifiedExceptionType
parameter_list|(
name|QualType
name|T
parameter_list|,
specifier|const
name|SourceRange
modifier|&
name|Range
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|CheckDistantExceptionSpec
parameter_list|(
name|QualType
name|T
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|CheckEquivalentExceptionSpec
parameter_list|(
name|FunctionDecl
modifier|*
name|Old
parameter_list|,
name|FunctionDecl
modifier|*
name|New
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|CheckEquivalentExceptionSpec
parameter_list|(
specifier|const
name|FunctionProtoType
modifier|*
name|Old
parameter_list|,
name|SourceLocation
name|OldLoc
parameter_list|,
specifier|const
name|FunctionProtoType
modifier|*
name|New
parameter_list|,
name|SourceLocation
name|NewLoc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|CheckEquivalentExceptionSpec
parameter_list|(
specifier|const
name|PartialDiagnostic
modifier|&
name|DiagID
parameter_list|,
specifier|const
name|PartialDiagnostic
modifier|&
name|NoteID
parameter_list|,
specifier|const
name|FunctionProtoType
modifier|*
name|Old
parameter_list|,
name|SourceLocation
name|OldLoc
parameter_list|,
specifier|const
name|FunctionProtoType
modifier|*
name|New
parameter_list|,
name|SourceLocation
name|NewLoc
parameter_list|,
name|bool
modifier|*
name|MissingExceptionSpecification
init|=
literal|0
parameter_list|,
name|bool
modifier|*
name|MissingEmptyExceptionSpecification
init|=
literal|0
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|CheckExceptionSpecSubset
parameter_list|(
specifier|const
name|PartialDiagnostic
modifier|&
name|DiagID
parameter_list|,
specifier|const
name|PartialDiagnostic
modifier|&
name|NoteID
parameter_list|,
specifier|const
name|FunctionProtoType
modifier|*
name|Superset
parameter_list|,
name|SourceLocation
name|SuperLoc
parameter_list|,
specifier|const
name|FunctionProtoType
modifier|*
name|Subset
parameter_list|,
name|SourceLocation
name|SubLoc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|CheckParamExceptionSpec
parameter_list|(
specifier|const
name|PartialDiagnostic
modifier|&
name|NoteID
parameter_list|,
specifier|const
name|FunctionProtoType
modifier|*
name|Target
parameter_list|,
name|SourceLocation
name|TargetLoc
parameter_list|,
specifier|const
name|FunctionProtoType
modifier|*
name|Source
parameter_list|,
name|SourceLocation
name|SourceLoc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|virtual
name|TypeResult
name|ActOnTypeName
parameter_list|(
name|Scope
modifier|*
name|S
parameter_list|,
name|Declarator
modifier|&
name|D
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
name|bool
name|RequireCompleteType
argument_list|(
name|SourceLocation
name|Loc
argument_list|,
name|QualType
name|T
argument_list|,
specifier|const
name|PartialDiagnostic
operator|&
name|PD
argument_list|,
name|std
operator|::
name|pair
operator|<
name|SourceLocation
argument_list|,
name|PartialDiagnostic
operator|>
name|Note
argument_list|)
decl_stmt|;
end_decl_stmt

begin_function_decl
name|bool
name|RequireCompleteType
parameter_list|(
name|SourceLocation
name|Loc
parameter_list|,
name|QualType
name|T
parameter_list|,
specifier|const
name|PartialDiagnostic
modifier|&
name|PD
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|RequireCompleteType
parameter_list|(
name|SourceLocation
name|Loc
parameter_list|,
name|QualType
name|T
parameter_list|,
name|unsigned
name|DiagID
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|QualType
name|getElaboratedType
parameter_list|(
name|ElaboratedTypeKeyword
name|Keyword
parameter_list|,
specifier|const
name|CXXScopeSpec
modifier|&
name|SS
parameter_list|,
name|QualType
name|T
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|QualType
name|BuildTypeofExprType
parameter_list|(
name|Expr
modifier|*
name|E
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|QualType
name|BuildDecltypeType
parameter_list|(
name|Expr
modifier|*
name|E
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|//===--------------------------------------------------------------------===//
end_comment

begin_comment
comment|// Symbol table / Decl tracking callbacks: SemaDecl.cpp.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|/// getDeclName - Return a pretty name for the specified decl if possible, or
end_comment

begin_comment
comment|/// an empty string if not.  This is used for pretty crash reporting.
end_comment

begin_expr_stmt
name|virtual
name|std
operator|::
name|string
name|getDeclName
argument_list|(
argument|DeclPtrTy D
argument_list|)
expr_stmt|;
end_expr_stmt

begin_function_decl
name|DeclGroupPtrTy
name|ConvertDeclToDeclGroup
parameter_list|(
name|DeclPtrTy
name|Ptr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|virtual
name|TypeTy
modifier|*
name|getTypeName
parameter_list|(
name|IdentifierInfo
modifier|&
name|II
parameter_list|,
name|SourceLocation
name|NameLoc
parameter_list|,
name|Scope
modifier|*
name|S
parameter_list|,
name|CXXScopeSpec
modifier|*
name|SS
parameter_list|,
name|bool
name|isClassName
init|=
name|false
parameter_list|,
name|TypeTy
modifier|*
name|ObjectType
init|=
literal|0
parameter_list|)
function_decl|;
end_function_decl

begin_expr_stmt
name|virtual
name|DeclSpec
operator|::
name|TST
name|isTagName
argument_list|(
name|IdentifierInfo
operator|&
name|II
argument_list|,
name|Scope
operator|*
name|S
argument_list|)
expr_stmt|;
end_expr_stmt

begin_function_decl
name|virtual
name|bool
name|DiagnoseUnknownTypeName
parameter_list|(
specifier|const
name|IdentifierInfo
modifier|&
name|II
parameter_list|,
name|SourceLocation
name|IILoc
parameter_list|,
name|Scope
modifier|*
name|S
parameter_list|,
name|CXXScopeSpec
modifier|*
name|SS
parameter_list|,
name|TypeTy
modifier|*
modifier|&
name|SuggestedType
parameter_list|)
function_decl|;
end_function_decl

begin_function
name|virtual
name|DeclPtrTy
name|ActOnDeclarator
parameter_list|(
name|Scope
modifier|*
name|S
parameter_list|,
name|Declarator
modifier|&
name|D
parameter_list|)
block|{
return|return
name|HandleDeclarator
argument_list|(
name|S
argument_list|,
name|D
argument_list|,
name|MultiTemplateParamsArg
argument_list|(
operator|*
name|this
argument_list|)
argument_list|,
name|false
argument_list|)
return|;
block|}
end_function

begin_function_decl
name|DeclPtrTy
name|HandleDeclarator
parameter_list|(
name|Scope
modifier|*
name|S
parameter_list|,
name|Declarator
modifier|&
name|D
parameter_list|,
name|MultiTemplateParamsArg
name|TemplateParameterLists
parameter_list|,
name|bool
name|IsFunctionDefinition
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|RegisterLocallyScopedExternCDecl
parameter_list|(
name|NamedDecl
modifier|*
name|ND
parameter_list|,
specifier|const
name|LookupResult
modifier|&
name|Previous
parameter_list|,
name|Scope
modifier|*
name|S
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|DiagnoseFunctionSpecifiers
parameter_list|(
name|Declarator
modifier|&
name|D
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|CheckShadow
parameter_list|(
name|Scope
modifier|*
name|S
parameter_list|,
name|VarDecl
modifier|*
name|D
parameter_list|,
specifier|const
name|LookupResult
modifier|&
name|R
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|CheckShadow
parameter_list|(
name|Scope
modifier|*
name|S
parameter_list|,
name|VarDecl
modifier|*
name|D
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|NamedDecl
modifier|*
name|ActOnTypedefDeclarator
parameter_list|(
name|Scope
modifier|*
name|S
parameter_list|,
name|Declarator
modifier|&
name|D
parameter_list|,
name|DeclContext
modifier|*
name|DC
parameter_list|,
name|QualType
name|R
parameter_list|,
name|TypeSourceInfo
modifier|*
name|TInfo
parameter_list|,
name|LookupResult
modifier|&
name|Previous
parameter_list|,
name|bool
modifier|&
name|Redeclaration
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|NamedDecl
modifier|*
name|ActOnVariableDeclarator
parameter_list|(
name|Scope
modifier|*
name|S
parameter_list|,
name|Declarator
modifier|&
name|D
parameter_list|,
name|DeclContext
modifier|*
name|DC
parameter_list|,
name|QualType
name|R
parameter_list|,
name|TypeSourceInfo
modifier|*
name|TInfo
parameter_list|,
name|LookupResult
modifier|&
name|Previous
parameter_list|,
name|MultiTemplateParamsArg
name|TemplateParamLists
parameter_list|,
name|bool
modifier|&
name|Redeclaration
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|CheckVariableDeclaration
parameter_list|(
name|VarDecl
modifier|*
name|NewVD
parameter_list|,
name|LookupResult
modifier|&
name|Previous
parameter_list|,
name|bool
modifier|&
name|Redeclaration
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|NamedDecl
modifier|*
name|ActOnFunctionDeclarator
parameter_list|(
name|Scope
modifier|*
name|S
parameter_list|,
name|Declarator
modifier|&
name|D
parameter_list|,
name|DeclContext
modifier|*
name|DC
parameter_list|,
name|QualType
name|R
parameter_list|,
name|TypeSourceInfo
modifier|*
name|TInfo
parameter_list|,
name|LookupResult
modifier|&
name|Previous
parameter_list|,
name|MultiTemplateParamsArg
name|TemplateParamLists
parameter_list|,
name|bool
name|IsFunctionDefinition
parameter_list|,
name|bool
modifier|&
name|Redeclaration
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|AddOverriddenMethods
parameter_list|(
name|CXXRecordDecl
modifier|*
name|DC
parameter_list|,
name|CXXMethodDecl
modifier|*
name|MD
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|CheckFunctionDeclaration
parameter_list|(
name|Scope
modifier|*
name|S
parameter_list|,
name|FunctionDecl
modifier|*
name|NewFD
parameter_list|,
name|LookupResult
modifier|&
name|Previous
parameter_list|,
name|bool
name|IsExplicitSpecialization
parameter_list|,
name|bool
modifier|&
name|Redeclaration
parameter_list|,
name|bool
modifier|&
name|OverloadableAttrRequired
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|CheckMain
parameter_list|(
name|FunctionDecl
modifier|*
name|FD
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|virtual
name|DeclPtrTy
name|ActOnParamDeclarator
parameter_list|(
name|Scope
modifier|*
name|S
parameter_list|,
name|Declarator
modifier|&
name|D
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ParmVarDecl
modifier|*
name|BuildParmVarDeclForTypedef
parameter_list|(
name|DeclContext
modifier|*
name|DC
parameter_list|,
name|SourceLocation
name|Loc
parameter_list|,
name|QualType
name|T
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
name|ParmVarDecl
modifier|*
name|CheckParameter
argument_list|(
name|DeclContext
operator|*
name|DC
argument_list|,
name|TypeSourceInfo
operator|*
name|TSInfo
argument_list|,
name|QualType
name|T
argument_list|,
name|IdentifierInfo
operator|*
name|Name
argument_list|,
name|SourceLocation
name|NameLoc
argument_list|,
name|VarDecl
operator|::
name|StorageClass
name|StorageClass
argument_list|,
name|VarDecl
operator|::
name|StorageClass
name|StorageClassAsWritten
argument_list|)
decl_stmt|;
end_decl_stmt

begin_function_decl
name|virtual
name|void
name|ActOnParamDefaultArgument
parameter_list|(
name|DeclPtrTy
name|param
parameter_list|,
name|SourceLocation
name|EqualLoc
parameter_list|,
name|ExprArg
name|defarg
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|virtual
name|void
name|ActOnParamUnparsedDefaultArgument
parameter_list|(
name|DeclPtrTy
name|param
parameter_list|,
name|SourceLocation
name|EqualLoc
parameter_list|,
name|SourceLocation
name|ArgLoc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|virtual
name|void
name|ActOnParamDefaultArgumentError
parameter_list|(
name|DeclPtrTy
name|param
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|SetParamDefaultArgument
parameter_list|(
name|ParmVarDecl
modifier|*
name|Param
parameter_list|,
name|ExprArg
name|DefaultArg
parameter_list|,
name|SourceLocation
name|EqualLoc
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|// Contains the locations of the beginning of unparsed default
end_comment

begin_comment
comment|// argument locations.
end_comment

begin_expr_stmt
name|llvm
operator|::
name|DenseMap
operator|<
name|ParmVarDecl
operator|*
operator|,
name|SourceLocation
operator|>
name|UnparsedDefaultArgLocs
expr_stmt|;
end_expr_stmt

begin_function_decl
name|virtual
name|void
name|AddInitializerToDecl
parameter_list|(
name|DeclPtrTy
name|dcl
parameter_list|,
name|ExprArg
name|init
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|AddInitializerToDecl
parameter_list|(
name|DeclPtrTy
name|dcl
parameter_list|,
name|ExprArg
name|init
parameter_list|,
name|bool
name|DirectInit
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ActOnUninitializedDecl
parameter_list|(
name|DeclPtrTy
name|dcl
parameter_list|,
name|bool
name|TypeContainsUndeducedAuto
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|virtual
name|void
name|ActOnInitializerError
parameter_list|(
name|DeclPtrTy
name|Dcl
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|virtual
name|void
name|SetDeclDeleted
parameter_list|(
name|DeclPtrTy
name|dcl
parameter_list|,
name|SourceLocation
name|DelLoc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|virtual
name|DeclGroupPtrTy
name|FinalizeDeclaratorGroup
parameter_list|(
name|Scope
modifier|*
name|S
parameter_list|,
specifier|const
name|DeclSpec
modifier|&
name|DS
parameter_list|,
name|DeclPtrTy
modifier|*
name|Group
parameter_list|,
name|unsigned
name|NumDecls
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|virtual
name|void
name|ActOnFinishKNRParamDeclarations
parameter_list|(
name|Scope
modifier|*
name|S
parameter_list|,
name|Declarator
modifier|&
name|D
parameter_list|,
name|SourceLocation
name|LocAfterDecls
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|virtual
name|DeclPtrTy
name|ActOnStartOfFunctionDef
parameter_list|(
name|Scope
modifier|*
name|S
parameter_list|,
name|Declarator
modifier|&
name|D
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|virtual
name|DeclPtrTy
name|ActOnStartOfFunctionDef
parameter_list|(
name|Scope
modifier|*
name|S
parameter_list|,
name|DeclPtrTy
name|D
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|virtual
name|void
name|ActOnStartOfObjCMethodDef
parameter_list|(
name|Scope
modifier|*
name|S
parameter_list|,
name|DeclPtrTy
name|D
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|virtual
name|DeclPtrTy
name|ActOnFinishFunctionBody
parameter_list|(
name|DeclPtrTy
name|Decl
parameter_list|,
name|StmtArg
name|Body
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|DeclPtrTy
name|ActOnFinishFunctionBody
parameter_list|(
name|DeclPtrTy
name|Decl
parameter_list|,
name|StmtArg
name|Body
parameter_list|,
name|bool
name|IsInstantiation
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// \brief Diagnose any unused parameters in the given sequence of
end_comment

begin_comment
comment|/// ParmVarDecl pointers.
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|InputIterator
operator|>
name|void
name|DiagnoseUnusedParameters
argument_list|(
argument|InputIterator Param
argument_list|,
argument|InputIterator ParamEnd
argument_list|)
block|{
if|if
condition|(
name|Diags
operator|.
name|getDiagnosticLevel
argument_list|(
name|diag
operator|::
name|warn_unused_parameter
argument_list|)
operator|==
name|Diagnostic
operator|::
name|Ignored
condition|)
return|return;
end_expr_stmt

begin_comment
comment|// Don't diagnose unused-parameter errors in template instantiations; we
end_comment

begin_comment
comment|// will already have done so in the template itself.
end_comment

begin_if
if|if
condition|(
operator|!
name|ActiveTemplateInstantiations
operator|.
name|empty
argument_list|()
condition|)
return|return;
end_if

begin_for
for|for
control|(
init|;
name|Param
operator|!=
name|ParamEnd
condition|;
operator|++
name|Param
control|)
block|{
if|if
condition|(
operator|!
operator|(
operator|*
name|Param
operator|)
operator|->
name|isUsed
argument_list|()
operator|&&
operator|(
operator|*
name|Param
operator|)
operator|->
name|getDeclName
argument_list|()
operator|&&
operator|!
operator|(
operator|*
name|Param
operator|)
operator|->
name|template
name|hasAttr
operator|<
name|UnusedAttr
operator|>
operator|(
operator|)
condition|)
block|{
name|Diag
argument_list|(
operator|(
operator|*
name|Param
operator|)
operator|->
name|getLocation
argument_list|()
argument_list|,
name|diag
operator|::
name|warn_unused_parameter
argument_list|)
operator|<<
operator|(
operator|*
name|Param
operator|)
operator|->
name|getDeclName
argument_list|()
expr_stmt|;
block|}
block|}
end_for

begin_expr_stmt
unit|}    void
name|DiagnoseInvalidJumps
argument_list|(
name|Stmt
operator|*
name|Body
argument_list|)
expr_stmt|;
end_expr_stmt

begin_function_decl
name|virtual
name|DeclPtrTy
name|ActOnFileScopeAsmDecl
parameter_list|(
name|SourceLocation
name|Loc
parameter_list|,
name|ExprArg
name|expr
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// Scope actions.
end_comment

begin_function_decl
name|virtual
name|void
name|ActOnPopScope
parameter_list|(
name|SourceLocation
name|Loc
parameter_list|,
name|Scope
modifier|*
name|S
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|virtual
name|void
name|ActOnTranslationUnitScope
parameter_list|(
name|SourceLocation
name|Loc
parameter_list|,
name|Scope
modifier|*
name|S
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// ParsedFreeStandingDeclSpec - This method is invoked when a declspec with
end_comment

begin_comment
comment|/// no declarator (e.g. "struct foo;") is parsed.
end_comment

begin_function_decl
name|virtual
name|DeclPtrTy
name|ParsedFreeStandingDeclSpec
parameter_list|(
name|Scope
modifier|*
name|S
parameter_list|,
name|AccessSpecifier
name|AS
parameter_list|,
name|DeclSpec
modifier|&
name|DS
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|virtual
name|DeclPtrTy
name|BuildAnonymousStructOrUnion
parameter_list|(
name|Scope
modifier|*
name|S
parameter_list|,
name|DeclSpec
modifier|&
name|DS
parameter_list|,
name|AccessSpecifier
name|AS
parameter_list|,
name|RecordDecl
modifier|*
name|Record
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
name|bool
name|isAcceptableTagRedeclaration
argument_list|(
specifier|const
name|TagDecl
operator|*
name|Previous
argument_list|,
name|TagDecl
operator|::
name|TagKind
name|NewTag
argument_list|,
name|SourceLocation
name|NewTagLoc
argument_list|,
specifier|const
name|IdentifierInfo
operator|&
name|Name
argument_list|)
decl_stmt|;
end_decl_stmt

begin_function_decl
name|virtual
name|DeclPtrTy
name|ActOnTag
parameter_list|(
name|Scope
modifier|*
name|S
parameter_list|,
name|unsigned
name|TagSpec
parameter_list|,
name|TagUseKind
name|TUK
parameter_list|,
name|SourceLocation
name|KWLoc
parameter_list|,
name|CXXScopeSpec
modifier|&
name|SS
parameter_list|,
name|IdentifierInfo
modifier|*
name|Name
parameter_list|,
name|SourceLocation
name|NameLoc
parameter_list|,
name|AttributeList
modifier|*
name|Attr
parameter_list|,
name|AccessSpecifier
name|AS
parameter_list|,
name|MultiTemplateParamsArg
name|TemplateParameterLists
parameter_list|,
name|bool
modifier|&
name|OwnedDecl
parameter_list|,
name|bool
modifier|&
name|IsDependent
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|virtual
name|TypeResult
name|ActOnDependentTag
parameter_list|(
name|Scope
modifier|*
name|S
parameter_list|,
name|unsigned
name|TagSpec
parameter_list|,
name|TagUseKind
name|TUK
parameter_list|,
specifier|const
name|CXXScopeSpec
modifier|&
name|SS
parameter_list|,
name|IdentifierInfo
modifier|*
name|Name
parameter_list|,
name|SourceLocation
name|TagLoc
parameter_list|,
name|SourceLocation
name|NameLoc
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
name|virtual
name|void
name|ActOnDefs
argument_list|(
name|Scope
operator|*
name|S
argument_list|,
name|DeclPtrTy
name|TagD
argument_list|,
name|SourceLocation
name|DeclStart
argument_list|,
name|IdentifierInfo
operator|*
name|ClassName
argument_list|,
name|llvm
operator|::
name|SmallVectorImpl
operator|<
name|DeclPtrTy
operator|>
operator|&
name|Decls
argument_list|)
decl_stmt|;
end_decl_stmt

begin_function_decl
name|virtual
name|DeclPtrTy
name|ActOnField
parameter_list|(
name|Scope
modifier|*
name|S
parameter_list|,
name|DeclPtrTy
name|TagD
parameter_list|,
name|SourceLocation
name|DeclStart
parameter_list|,
name|Declarator
modifier|&
name|D
parameter_list|,
name|ExprTy
modifier|*
name|BitfieldWidth
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|FieldDecl
modifier|*
name|HandleField
parameter_list|(
name|Scope
modifier|*
name|S
parameter_list|,
name|RecordDecl
modifier|*
name|TagD
parameter_list|,
name|SourceLocation
name|DeclStart
parameter_list|,
name|Declarator
modifier|&
name|D
parameter_list|,
name|Expr
modifier|*
name|BitfieldWidth
parameter_list|,
name|AccessSpecifier
name|AS
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|FieldDecl
modifier|*
name|CheckFieldDecl
parameter_list|(
name|DeclarationName
name|Name
parameter_list|,
name|QualType
name|T
parameter_list|,
name|TypeSourceInfo
modifier|*
name|TInfo
parameter_list|,
name|RecordDecl
modifier|*
name|Record
parameter_list|,
name|SourceLocation
name|Loc
parameter_list|,
name|bool
name|Mutable
parameter_list|,
name|Expr
modifier|*
name|BitfieldWidth
parameter_list|,
name|SourceLocation
name|TSSL
parameter_list|,
name|AccessSpecifier
name|AS
parameter_list|,
name|NamedDecl
modifier|*
name|PrevDecl
parameter_list|,
name|Declarator
modifier|*
name|D
init|=
literal|0
parameter_list|)
function_decl|;
end_function_decl

begin_enum
enum|enum
name|CXXSpecialMember
block|{
name|CXXInvalid
init|=
operator|-
literal|1
block|,
name|CXXConstructor
init|=
literal|0
block|,
name|CXXCopyConstructor
init|=
literal|1
block|,
name|CXXCopyAssignment
init|=
literal|2
block|,
name|CXXDestructor
init|=
literal|3
block|}
enum|;
end_enum

begin_function_decl
name|void
name|DiagnoseNontrivial
parameter_list|(
specifier|const
name|RecordType
modifier|*
name|Record
parameter_list|,
name|CXXSpecialMember
name|mem
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|CXXSpecialMember
name|getSpecialMember
parameter_list|(
specifier|const
name|CXXMethodDecl
modifier|*
name|MD
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
name|virtual
name|DeclPtrTy
name|ActOnIvar
argument_list|(
name|Scope
operator|*
name|S
argument_list|,
name|SourceLocation
name|DeclStart
argument_list|,
name|DeclPtrTy
name|IntfDecl
argument_list|,
name|Declarator
operator|&
name|D
argument_list|,
name|ExprTy
operator|*
name|BitfieldWidth
argument_list|,
name|tok
operator|::
name|ObjCKeywordKind
name|visibility
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|// This is used for both record definitions and ObjC interface declarations.
end_comment

begin_function_decl
name|virtual
name|void
name|ActOnFields
parameter_list|(
name|Scope
modifier|*
name|S
parameter_list|,
name|SourceLocation
name|RecLoc
parameter_list|,
name|DeclPtrTy
name|TagDecl
parameter_list|,
name|DeclPtrTy
modifier|*
name|Fields
parameter_list|,
name|unsigned
name|NumFields
parameter_list|,
name|SourceLocation
name|LBrac
parameter_list|,
name|SourceLocation
name|RBrac
parameter_list|,
name|AttributeList
modifier|*
name|AttrList
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// ActOnTagStartDefinition - Invoked when we have entered the
end_comment

begin_comment
comment|/// scope of a tag's definition (e.g., for an enumeration, class,
end_comment

begin_comment
comment|/// struct, or union).
end_comment

begin_function_decl
name|virtual
name|void
name|ActOnTagStartDefinition
parameter_list|(
name|Scope
modifier|*
name|S
parameter_list|,
name|DeclPtrTy
name|TagDecl
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// ActOnStartCXXMemberDeclarations - Invoked when we have parsed a
end_comment

begin_comment
comment|/// C++ record definition's base-specifiers clause and are starting its
end_comment

begin_comment
comment|/// member declarations.
end_comment

begin_function_decl
name|virtual
name|void
name|ActOnStartCXXMemberDeclarations
parameter_list|(
name|Scope
modifier|*
name|S
parameter_list|,
name|DeclPtrTy
name|TagDecl
parameter_list|,
name|SourceLocation
name|LBraceLoc
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// ActOnTagFinishDefinition - Invoked once we have finished parsing
end_comment

begin_comment
comment|/// the definition of a tag (enumeration, class, struct, or union).
end_comment

begin_function_decl
name|virtual
name|void
name|ActOnTagFinishDefinition
parameter_list|(
name|Scope
modifier|*
name|S
parameter_list|,
name|DeclPtrTy
name|TagDecl
parameter_list|,
name|SourceLocation
name|RBraceLoc
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// ActOnTagDefinitionError - Invoked when there was an unrecoverable
end_comment

begin_comment
comment|/// error parsing the definition of a tag.
end_comment

begin_function_decl
name|virtual
name|void
name|ActOnTagDefinitionError
parameter_list|(
name|Scope
modifier|*
name|S
parameter_list|,
name|DeclPtrTy
name|TagDecl
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|EnumConstantDecl
modifier|*
name|CheckEnumConstant
parameter_list|(
name|EnumDecl
modifier|*
name|Enum
parameter_list|,
name|EnumConstantDecl
modifier|*
name|LastEnumConst
parameter_list|,
name|SourceLocation
name|IdLoc
parameter_list|,
name|IdentifierInfo
modifier|*
name|Id
parameter_list|,
name|ExprArg
name|val
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|virtual
name|DeclPtrTy
name|ActOnEnumConstant
parameter_list|(
name|Scope
modifier|*
name|S
parameter_list|,
name|DeclPtrTy
name|EnumDecl
parameter_list|,
name|DeclPtrTy
name|LastEnumConstant
parameter_list|,
name|SourceLocation
name|IdLoc
parameter_list|,
name|IdentifierInfo
modifier|*
name|Id
parameter_list|,
name|SourceLocation
name|EqualLoc
parameter_list|,
name|ExprTy
modifier|*
name|Val
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|virtual
name|void
name|ActOnEnumBody
parameter_list|(
name|SourceLocation
name|EnumLoc
parameter_list|,
name|SourceLocation
name|LBraceLoc
parameter_list|,
name|SourceLocation
name|RBraceLoc
parameter_list|,
name|DeclPtrTy
name|EnumDecl
parameter_list|,
name|DeclPtrTy
modifier|*
name|Elements
parameter_list|,
name|unsigned
name|NumElements
parameter_list|,
name|Scope
modifier|*
name|S
parameter_list|,
name|AttributeList
modifier|*
name|Attr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|DeclContext
modifier|*
name|getContainingDC
parameter_list|(
name|DeclContext
modifier|*
name|DC
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// Set the current declaration context until it gets popped.
end_comment

begin_function_decl
name|void
name|PushDeclContext
parameter_list|(
name|Scope
modifier|*
name|S
parameter_list|,
name|DeclContext
modifier|*
name|DC
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|PopDeclContext
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/// EnterDeclaratorContext - Used when we must lookup names in the context
end_comment

begin_comment
comment|/// of a declarator's nested name specifier.
end_comment

begin_function_decl
name|void
name|EnterDeclaratorContext
parameter_list|(
name|Scope
modifier|*
name|S
parameter_list|,
name|DeclContext
modifier|*
name|DC
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ExitDeclaratorContext
parameter_list|(
name|Scope
modifier|*
name|S
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|DeclContext
modifier|*
name|getFunctionLevelDeclContext
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/// getCurFunctionDecl - If inside of a function body, this returns a pointer
end_comment

begin_comment
comment|/// to the function decl for the function being parsed.  If we're currently
end_comment

begin_comment
comment|/// in a 'block', this returns the containing context.
end_comment

begin_function_decl
name|FunctionDecl
modifier|*
name|getCurFunctionDecl
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/// getCurMethodDecl - If inside of a method body, this returns a pointer to
end_comment

begin_comment
comment|/// the method decl for the method being parsed.  If we're currently
end_comment

begin_comment
comment|/// in a 'block', this returns the containing context.
end_comment

begin_function_decl
name|ObjCMethodDecl
modifier|*
name|getCurMethodDecl
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/// getCurFunctionOrMethodDecl - Return the Decl for the current ObjC method
end_comment

begin_comment
comment|/// or C function we're in, otherwise return null.  If we're currently
end_comment

begin_comment
comment|/// in a 'block', this returns the containing context.
end_comment

begin_function_decl
name|NamedDecl
modifier|*
name|getCurFunctionOrMethodDecl
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/// Add this decl to the scope shadowed decl chains.
end_comment

begin_function_decl
name|void
name|PushOnScopeChains
parameter_list|(
name|NamedDecl
modifier|*
name|D
parameter_list|,
name|Scope
modifier|*
name|S
parameter_list|,
name|bool
name|AddToContext
init|=
name|true
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// isDeclInScope - If 'Ctx' is a function/method, isDeclInScope returns true
end_comment

begin_comment
comment|/// if 'D' is in Scope 'S', otherwise 'S' is ignored and isDeclInScope returns
end_comment

begin_comment
comment|/// true if 'D' belongs to the given declaration context.
end_comment

begin_function_decl
name|bool
name|isDeclInScope
parameter_list|(
name|NamedDecl
modifier|*
modifier|&
name|D
parameter_list|,
name|DeclContext
modifier|*
name|Ctx
parameter_list|,
name|Scope
modifier|*
name|S
init|=
literal|0
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// Finds the scope corresponding to the given decl context, if it
end_comment

begin_comment
comment|/// happens to be an enclosing scope.  Otherwise return NULL.
end_comment

begin_function
name|Scope
modifier|*
name|getScopeForDeclContext
parameter_list|(
name|Scope
modifier|*
name|S
parameter_list|,
name|DeclContext
modifier|*
name|DC
parameter_list|)
block|{
name|DeclContext
modifier|*
name|TargetDC
init|=
name|DC
operator|->
name|getPrimaryContext
argument_list|()
decl_stmt|;
do|do
block|{
if|if
condition|(
name|DeclContext
modifier|*
name|ScopeDC
init|=
operator|(
name|DeclContext
operator|*
operator|)
name|S
operator|->
name|getEntity
argument_list|()
condition|)
if|if
condition|(
name|ScopeDC
operator|->
name|getPrimaryContext
argument_list|()
operator|==
name|TargetDC
condition|)
return|return
name|S
return|;
block|}
do|while
condition|(
operator|(
name|S
operator|=
name|S
operator|->
name|getParent
argument_list|()
operator|)
condition|)
do|;
return|return
name|NULL
return|;
block|}
end_function

begin_comment
comment|/// Subroutines of ActOnDeclarator().
end_comment

begin_function_decl
name|TypedefDecl
modifier|*
name|ParseTypedefDecl
parameter_list|(
name|Scope
modifier|*
name|S
parameter_list|,
name|Declarator
modifier|&
name|D
parameter_list|,
name|QualType
name|T
parameter_list|,
name|TypeSourceInfo
modifier|*
name|TInfo
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|MergeTypeDefDecl
parameter_list|(
name|TypedefDecl
modifier|*
name|New
parameter_list|,
name|LookupResult
modifier|&
name|OldDecls
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|MergeFunctionDecl
parameter_list|(
name|FunctionDecl
modifier|*
name|New
parameter_list|,
name|Decl
modifier|*
name|Old
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|MergeCompatibleFunctionDecls
parameter_list|(
name|FunctionDecl
modifier|*
name|New
parameter_list|,
name|FunctionDecl
modifier|*
name|Old
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|MergeVarDecl
parameter_list|(
name|VarDecl
modifier|*
name|New
parameter_list|,
name|LookupResult
modifier|&
name|OldDecls
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|MergeCXXFunctionDecl
parameter_list|(
name|FunctionDecl
modifier|*
name|New
parameter_list|,
name|FunctionDecl
modifier|*
name|Old
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|// AssignmentAction - This is used by all the assignment diagnostic functions
end_comment

begin_comment
comment|// to represent what is actually causing the operation
end_comment

begin_enum
enum|enum
name|AssignmentAction
block|{
name|AA_Assigning
block|,
name|AA_Passing
block|,
name|AA_Returning
block|,
name|AA_Converting
block|,
name|AA_Initializing
block|,
name|AA_Sending
block|,
name|AA_Casting
block|}
enum|;
end_enum

begin_comment
comment|/// C++ Overloading.
end_comment

begin_enum
enum|enum
name|OverloadKind
block|{
comment|/// This is a legitimate overload: the existing declarations are
comment|/// functions or function templates with different signatures.
name|Ovl_Overload
block|,
comment|/// This is not an overload because the signature exactly matches
comment|/// an existing declaration.
name|Ovl_Match
block|,
comment|/// This is not an overload because the lookup results contain a
comment|/// non-function.
name|Ovl_NonFunction
block|}
enum|;
end_enum

begin_function_decl
name|OverloadKind
name|CheckOverload
parameter_list|(
name|Scope
modifier|*
name|S
parameter_list|,
name|FunctionDecl
modifier|*
name|New
parameter_list|,
specifier|const
name|LookupResult
modifier|&
name|OldDecls
parameter_list|,
name|NamedDecl
modifier|*
modifier|&
name|OldDecl
parameter_list|,
name|bool
name|IsForUsingDecl
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|IsOverload
parameter_list|(
name|FunctionDecl
modifier|*
name|New
parameter_list|,
name|FunctionDecl
modifier|*
name|Old
parameter_list|,
name|bool
name|IsForUsingDecl
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|TryImplicitConversion
parameter_list|(
name|InitializationSequence
modifier|&
name|Sequence
parameter_list|,
specifier|const
name|InitializedEntity
modifier|&
name|Entity
parameter_list|,
name|Expr
modifier|*
name|From
parameter_list|,
name|bool
name|SuppressUserConversions
parameter_list|,
name|bool
name|AllowExplicit
parameter_list|,
name|bool
name|InOverloadResolution
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ImplicitConversionSequence
name|TryImplicitConversion
parameter_list|(
name|Expr
modifier|*
name|From
parameter_list|,
name|QualType
name|ToType
parameter_list|,
name|bool
name|SuppressUserConversions
parameter_list|,
name|bool
name|AllowExplicit
parameter_list|,
name|bool
name|InOverloadResolution
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|IsStandardConversion
parameter_list|(
name|Expr
modifier|*
name|From
parameter_list|,
name|QualType
name|ToType
parameter_list|,
name|bool
name|InOverloadResolution
parameter_list|,
name|StandardConversionSequence
modifier|&
name|SCS
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|IsIntegralPromotion
parameter_list|(
name|Expr
modifier|*
name|From
parameter_list|,
name|QualType
name|FromType
parameter_list|,
name|QualType
name|ToType
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|IsFloatingPointPromotion
parameter_list|(
name|QualType
name|FromType
parameter_list|,
name|QualType
name|ToType
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|IsComplexPromotion
parameter_list|(
name|QualType
name|FromType
parameter_list|,
name|QualType
name|ToType
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|IsPointerConversion
parameter_list|(
name|Expr
modifier|*
name|From
parameter_list|,
name|QualType
name|FromType
parameter_list|,
name|QualType
name|ToType
parameter_list|,
name|bool
name|InOverloadResolution
parameter_list|,
name|QualType
modifier|&
name|ConvertedType
parameter_list|,
name|bool
modifier|&
name|IncompatibleObjC
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|isObjCPointerConversion
parameter_list|(
name|QualType
name|FromType
parameter_list|,
name|QualType
name|ToType
parameter_list|,
name|QualType
modifier|&
name|ConvertedType
parameter_list|,
name|bool
modifier|&
name|IncompatibleObjC
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|FunctionArgTypesAreEqual
parameter_list|(
name|FunctionProtoType
modifier|*
name|OldType
parameter_list|,
name|FunctionProtoType
modifier|*
name|NewType
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
name|bool
name|CheckPointerConversion
argument_list|(
name|Expr
operator|*
name|From
argument_list|,
name|QualType
name|ToType
argument_list|,
name|CastExpr
operator|::
name|CastKind
operator|&
name|Kind
argument_list|,
name|CXXBaseSpecifierArray
operator|&
name|BasePath
argument_list|,
name|bool
name|IgnoreBaseAccess
argument_list|)
decl_stmt|;
end_decl_stmt

begin_function_decl
name|bool
name|IsMemberPointerConversion
parameter_list|(
name|Expr
modifier|*
name|From
parameter_list|,
name|QualType
name|FromType
parameter_list|,
name|QualType
name|ToType
parameter_list|,
name|bool
name|InOverloadResolution
parameter_list|,
name|QualType
modifier|&
name|ConvertedType
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
name|bool
name|CheckMemberPointerConversion
argument_list|(
name|Expr
operator|*
name|From
argument_list|,
name|QualType
name|ToType
argument_list|,
name|CastExpr
operator|::
name|CastKind
operator|&
name|Kind
argument_list|,
name|CXXBaseSpecifierArray
operator|&
name|BasePath
argument_list|,
name|bool
name|IgnoreBaseAccess
argument_list|)
decl_stmt|;
end_decl_stmt

begin_function_decl
name|bool
name|IsQualificationConversion
parameter_list|(
name|QualType
name|FromType
parameter_list|,
name|QualType
name|ToType
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|OverloadingResult
name|IsUserDefinedConversion
parameter_list|(
name|Expr
modifier|*
name|From
parameter_list|,
name|QualType
name|ToType
parameter_list|,
name|UserDefinedConversionSequence
modifier|&
name|User
parameter_list|,
name|OverloadCandidateSet
modifier|&
name|Conversions
parameter_list|,
name|bool
name|AllowExplicit
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|DiagnoseMultipleUserDefinedConversion
parameter_list|(
name|Expr
modifier|*
name|From
parameter_list|,
name|QualType
name|ToType
parameter_list|)
function_decl|;
end_function_decl

begin_expr_stmt
name|ImplicitConversionSequence
operator|::
name|CompareKind
name|CompareImplicitConversionSequences
argument_list|(
specifier|const
name|ImplicitConversionSequence
operator|&
name|ICS1
argument_list|,
specifier|const
name|ImplicitConversionSequence
operator|&
name|ICS2
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|ImplicitConversionSequence
operator|::
name|CompareKind
name|CompareStandardConversionSequences
argument_list|(
specifier|const
name|StandardConversionSequence
operator|&
name|SCS1
argument_list|,
specifier|const
name|StandardConversionSequence
operator|&
name|SCS2
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|ImplicitConversionSequence
operator|::
name|CompareKind
name|CompareQualificationConversions
argument_list|(
specifier|const
name|StandardConversionSequence
operator|&
name|SCS1
argument_list|,
specifier|const
name|StandardConversionSequence
operator|&
name|SCS2
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|ImplicitConversionSequence
operator|::
name|CompareKind
name|CompareDerivedToBaseConversions
argument_list|(
specifier|const
name|StandardConversionSequence
operator|&
name|SCS1
argument_list|,
specifier|const
name|StandardConversionSequence
operator|&
name|SCS2
argument_list|)
expr_stmt|;
end_expr_stmt

begin_function_decl
name|OwningExprResult
name|PerformCopyInitialization
parameter_list|(
specifier|const
name|InitializedEntity
modifier|&
name|Entity
parameter_list|,
name|SourceLocation
name|EqualLoc
parameter_list|,
name|OwningExprResult
name|Init
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ImplicitConversionSequence
name|TryObjectArgumentInitialization
parameter_list|(
name|QualType
name|FromType
parameter_list|,
name|CXXMethodDecl
modifier|*
name|Method
parameter_list|,
name|CXXRecordDecl
modifier|*
name|ActingContext
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|PerformObjectArgumentInitialization
parameter_list|(
name|Expr
modifier|*
modifier|&
name|From
parameter_list|,
name|NestedNameSpecifier
modifier|*
name|Qualifier
parameter_list|,
name|NamedDecl
modifier|*
name|FoundDecl
parameter_list|,
name|CXXMethodDecl
modifier|*
name|Method
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ImplicitConversionSequence
name|TryContextuallyConvertToBool
parameter_list|(
name|Expr
modifier|*
name|From
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|PerformContextuallyConvertToBool
parameter_list|(
name|Expr
modifier|*
modifier|&
name|From
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ImplicitConversionSequence
name|TryContextuallyConvertToObjCId
parameter_list|(
name|Expr
modifier|*
name|From
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|PerformContextuallyConvertToObjCId
parameter_list|(
name|Expr
modifier|*
modifier|&
name|From
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|OwningExprResult
name|ConvertToIntegralOrEnumerationType
parameter_list|(
name|SourceLocation
name|Loc
parameter_list|,
name|ExprArg
name|FromE
parameter_list|,
specifier|const
name|PartialDiagnostic
modifier|&
name|NotIntDiag
parameter_list|,
specifier|const
name|PartialDiagnostic
modifier|&
name|IncompleteDiag
parameter_list|,
specifier|const
name|PartialDiagnostic
modifier|&
name|ExplicitConvDiag
parameter_list|,
specifier|const
name|PartialDiagnostic
modifier|&
name|ExplicitConvNote
parameter_list|,
specifier|const
name|PartialDiagnostic
modifier|&
name|AmbigDiag
parameter_list|,
specifier|const
name|PartialDiagnostic
modifier|&
name|AmbigNote
parameter_list|,
specifier|const
name|PartialDiagnostic
modifier|&
name|ConvDiag
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|PerformObjectMemberConversion
parameter_list|(
name|Expr
modifier|*
modifier|&
name|From
parameter_list|,
name|NestedNameSpecifier
modifier|*
name|Qualifier
parameter_list|,
name|NamedDecl
modifier|*
name|FoundDecl
parameter_list|,
name|NamedDecl
modifier|*
name|Member
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|// Members have to be NamespaceDecl* or TranslationUnitDecl*.
end_comment

begin_comment
comment|// TODO: make this is a typesafe union.
end_comment

begin_typedef
typedef|typedef
name|llvm
operator|::
name|SmallPtrSet
operator|<
name|DeclContext
operator|*
operator|,
literal|16
operator|>
name|AssociatedNamespaceSet
expr_stmt|;
end_typedef

begin_typedef
typedef|typedef
name|llvm
operator|::
name|SmallPtrSet
operator|<
name|CXXRecordDecl
operator|*
operator|,
literal|16
operator|>
name|AssociatedClassSet
expr_stmt|;
end_typedef

begin_function_decl
name|void
name|AddOverloadCandidate
parameter_list|(
name|NamedDecl
modifier|*
name|Function
parameter_list|,
name|DeclAccessPair
name|FoundDecl
parameter_list|,
name|Expr
modifier|*
modifier|*
name|Args
parameter_list|,
name|unsigned
name|NumArgs
parameter_list|,
name|OverloadCandidateSet
modifier|&
name|CandidateSet
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|AddOverloadCandidate
parameter_list|(
name|FunctionDecl
modifier|*
name|Function
parameter_list|,
name|DeclAccessPair
name|FoundDecl
parameter_list|,
name|Expr
modifier|*
modifier|*
name|Args
parameter_list|,
name|unsigned
name|NumArgs
parameter_list|,
name|OverloadCandidateSet
modifier|&
name|CandidateSet
parameter_list|,
name|bool
name|SuppressUserConversions
init|=
name|false
parameter_list|,
name|bool
name|PartialOverloading
init|=
name|false
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|AddFunctionCandidates
parameter_list|(
specifier|const
name|UnresolvedSetImpl
modifier|&
name|Functions
parameter_list|,
name|Expr
modifier|*
modifier|*
name|Args
parameter_list|,
name|unsigned
name|NumArgs
parameter_list|,
name|OverloadCandidateSet
modifier|&
name|CandidateSet
parameter_list|,
name|bool
name|SuppressUserConversions
init|=
name|false
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|AddMethodCandidate
parameter_list|(
name|DeclAccessPair
name|FoundDecl
parameter_list|,
name|QualType
name|ObjectType
parameter_list|,
name|Expr
modifier|*
modifier|*
name|Args
parameter_list|,
name|unsigned
name|NumArgs
parameter_list|,
name|OverloadCandidateSet
modifier|&
name|CandidateSet
parameter_list|,
name|bool
name|SuppressUserConversion
init|=
name|false
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|AddMethodCandidate
parameter_list|(
name|CXXMethodDecl
modifier|*
name|Method
parameter_list|,
name|DeclAccessPair
name|FoundDecl
parameter_list|,
name|CXXRecordDecl
modifier|*
name|ActingContext
parameter_list|,
name|QualType
name|ObjectType
parameter_list|,
name|Expr
modifier|*
modifier|*
name|Args
parameter_list|,
name|unsigned
name|NumArgs
parameter_list|,
name|OverloadCandidateSet
modifier|&
name|CandidateSet
parameter_list|,
name|bool
name|SuppressUserConversions
init|=
name|false
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|AddMethodTemplateCandidate
parameter_list|(
name|FunctionTemplateDecl
modifier|*
name|MethodTmpl
parameter_list|,
name|DeclAccessPair
name|FoundDecl
parameter_list|,
name|CXXRecordDecl
modifier|*
name|ActingContext
parameter_list|,
specifier|const
name|TemplateArgumentListInfo
modifier|*
name|ExplicitTemplateArgs
parameter_list|,
name|QualType
name|ObjectType
parameter_list|,
name|Expr
modifier|*
modifier|*
name|Args
parameter_list|,
name|unsigned
name|NumArgs
parameter_list|,
name|OverloadCandidateSet
modifier|&
name|CandidateSet
parameter_list|,
name|bool
name|SuppressUserConversions
init|=
name|false
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|AddTemplateOverloadCandidate
parameter_list|(
name|FunctionTemplateDecl
modifier|*
name|FunctionTemplate
parameter_list|,
name|DeclAccessPair
name|FoundDecl
parameter_list|,
specifier|const
name|TemplateArgumentListInfo
modifier|*
name|ExplicitTemplateArgs
parameter_list|,
name|Expr
modifier|*
modifier|*
name|Args
parameter_list|,
name|unsigned
name|NumArgs
parameter_list|,
name|OverloadCandidateSet
modifier|&
name|CandidateSet
parameter_list|,
name|bool
name|SuppressUserConversions
init|=
name|false
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|AddConversionCandidate
parameter_list|(
name|CXXConversionDecl
modifier|*
name|Conversion
parameter_list|,
name|DeclAccessPair
name|FoundDecl
parameter_list|,
name|CXXRecordDecl
modifier|*
name|ActingContext
parameter_list|,
name|Expr
modifier|*
name|From
parameter_list|,
name|QualType
name|ToType
parameter_list|,
name|OverloadCandidateSet
modifier|&
name|CandidateSet
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|AddTemplateConversionCandidate
parameter_list|(
name|FunctionTemplateDecl
modifier|*
name|FunctionTemplate
parameter_list|,
name|DeclAccessPair
name|FoundDecl
parameter_list|,
name|CXXRecordDecl
modifier|*
name|ActingContext
parameter_list|,
name|Expr
modifier|*
name|From
parameter_list|,
name|QualType
name|ToType
parameter_list|,
name|OverloadCandidateSet
modifier|&
name|CandidateSet
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|AddSurrogateCandidate
parameter_list|(
name|CXXConversionDecl
modifier|*
name|Conversion
parameter_list|,
name|DeclAccessPair
name|FoundDecl
parameter_list|,
name|CXXRecordDecl
modifier|*
name|ActingContext
parameter_list|,
specifier|const
name|FunctionProtoType
modifier|*
name|Proto
parameter_list|,
name|QualType
name|ObjectTy
parameter_list|,
name|Expr
modifier|*
modifier|*
name|Args
parameter_list|,
name|unsigned
name|NumArgs
parameter_list|,
name|OverloadCandidateSet
modifier|&
name|CandidateSet
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|AddMemberOperatorCandidates
parameter_list|(
name|OverloadedOperatorKind
name|Op
parameter_list|,
name|SourceLocation
name|OpLoc
parameter_list|,
name|Expr
modifier|*
modifier|*
name|Args
parameter_list|,
name|unsigned
name|NumArgs
parameter_list|,
name|OverloadCandidateSet
modifier|&
name|CandidateSet
parameter_list|,
name|SourceRange
name|OpRange
init|=
name|SourceRange
argument_list|()
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|AddBuiltinCandidate
parameter_list|(
name|QualType
name|ResultTy
parameter_list|,
name|QualType
modifier|*
name|ParamTys
parameter_list|,
name|Expr
modifier|*
modifier|*
name|Args
parameter_list|,
name|unsigned
name|NumArgs
parameter_list|,
name|OverloadCandidateSet
modifier|&
name|CandidateSet
parameter_list|,
name|bool
name|IsAssignmentOperator
init|=
name|false
parameter_list|,
name|unsigned
name|NumContextualBoolArguments
init|=
literal|0
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|AddBuiltinOperatorCandidates
parameter_list|(
name|OverloadedOperatorKind
name|Op
parameter_list|,
name|SourceLocation
name|OpLoc
parameter_list|,
name|Expr
modifier|*
modifier|*
name|Args
parameter_list|,
name|unsigned
name|NumArgs
parameter_list|,
name|OverloadCandidateSet
modifier|&
name|CandidateSet
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|AddArgumentDependentLookupCandidates
parameter_list|(
name|DeclarationName
name|Name
parameter_list|,
name|bool
name|Operator
parameter_list|,
name|Expr
modifier|*
modifier|*
name|Args
parameter_list|,
name|unsigned
name|NumArgs
parameter_list|,
specifier|const
name|TemplateArgumentListInfo
modifier|*
name|ExplicitTemplateArgs
parameter_list|,
name|OverloadCandidateSet
modifier|&
name|CandidateSet
parameter_list|,
name|bool
name|PartialOverloading
init|=
name|false
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|isBetterOverloadCandidate
parameter_list|(
specifier|const
name|OverloadCandidate
modifier|&
name|Cand1
parameter_list|,
specifier|const
name|OverloadCandidate
modifier|&
name|Cand2
parameter_list|,
name|SourceLocation
name|Loc
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
name|OverloadingResult
name|BestViableFunction
argument_list|(
name|OverloadCandidateSet
operator|&
name|CandidateSet
argument_list|,
name|SourceLocation
name|Loc
argument_list|,
name|OverloadCandidateSet
operator|::
name|iterator
operator|&
name|Best
argument_list|)
decl_stmt|;
end_decl_stmt

begin_enum
enum|enum
name|OverloadCandidateDisplayKind
block|{
comment|/// Requests that all candidates be shown.  Viable candidates will
comment|/// be printed first.
name|OCD_AllCandidates
block|,
comment|/// Requests that only viable candidates be shown.
name|OCD_ViableCandidates
block|}
enum|;
end_enum

begin_function_decl
name|void
name|PrintOverloadCandidates
parameter_list|(
name|OverloadCandidateSet
modifier|&
name|CandidateSet
parameter_list|,
name|OverloadCandidateDisplayKind
name|OCD
parameter_list|,
name|Expr
modifier|*
modifier|*
name|Args
parameter_list|,
name|unsigned
name|NumArgs
parameter_list|,
specifier|const
name|char
modifier|*
name|Opc
init|=
literal|0
parameter_list|,
name|SourceLocation
name|Loc
init|=
name|SourceLocation
argument_list|()
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|NoteOverloadCandidate
parameter_list|(
name|FunctionDecl
modifier|*
name|Fn
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|DiagnoseAmbiguousConversion
parameter_list|(
specifier|const
name|ImplicitConversionSequence
modifier|&
name|ICS
parameter_list|,
name|SourceLocation
name|CaretLoc
parameter_list|,
specifier|const
name|PartialDiagnostic
modifier|&
name|PDiag
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|FunctionDecl
modifier|*
name|ResolveAddressOfOverloadedFunction
parameter_list|(
name|Expr
modifier|*
name|From
parameter_list|,
name|QualType
name|ToType
parameter_list|,
name|bool
name|Complain
parameter_list|,
name|DeclAccessPair
modifier|&
name|Found
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|FunctionDecl
modifier|*
name|ResolveSingleFunctionTemplateSpecialization
parameter_list|(
name|Expr
modifier|*
name|From
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|Expr
modifier|*
name|FixOverloadedFunctionReference
parameter_list|(
name|Expr
modifier|*
name|E
parameter_list|,
name|DeclAccessPair
name|FoundDecl
parameter_list|,
name|FunctionDecl
modifier|*
name|Fn
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|OwningExprResult
name|FixOverloadedFunctionReference
parameter_list|(
name|OwningExprResult
parameter_list|,
name|DeclAccessPair
name|FoundDecl
parameter_list|,
name|FunctionDecl
modifier|*
name|Fn
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|AddOverloadedCallCandidates
parameter_list|(
name|UnresolvedLookupExpr
modifier|*
name|ULE
parameter_list|,
name|Expr
modifier|*
modifier|*
name|Args
parameter_list|,
name|unsigned
name|NumArgs
parameter_list|,
name|OverloadCandidateSet
modifier|&
name|CandidateSet
parameter_list|,
name|bool
name|PartialOverloading
init|=
name|false
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|OwningExprResult
name|BuildOverloadedCallExpr
parameter_list|(
name|Scope
modifier|*
name|S
parameter_list|,
name|Expr
modifier|*
name|Fn
parameter_list|,
name|UnresolvedLookupExpr
modifier|*
name|ULE
parameter_list|,
name|SourceLocation
name|LParenLoc
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
modifier|*
name|CommaLocs
parameter_list|,
name|SourceLocation
name|RParenLoc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|OwningExprResult
name|CreateOverloadedUnaryOp
parameter_list|(
name|SourceLocation
name|OpLoc
parameter_list|,
name|unsigned
name|Opc
parameter_list|,
specifier|const
name|UnresolvedSetImpl
modifier|&
name|Fns
parameter_list|,
name|ExprArg
name|input
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|OwningExprResult
name|CreateOverloadedBinOp
parameter_list|(
name|SourceLocation
name|OpLoc
parameter_list|,
name|unsigned
name|Opc
parameter_list|,
specifier|const
name|UnresolvedSetImpl
modifier|&
name|Fns
parameter_list|,
name|Expr
modifier|*
name|LHS
parameter_list|,
name|Expr
modifier|*
name|RHS
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|OwningExprResult
name|CreateOverloadedArraySubscriptExpr
parameter_list|(
name|SourceLocation
name|LLoc
parameter_list|,
name|SourceLocation
name|RLoc
parameter_list|,
name|ExprArg
name|Base
parameter_list|,
name|ExprArg
name|Idx
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|OwningExprResult
name|BuildCallToMemberFunction
parameter_list|(
name|Scope
modifier|*
name|S
parameter_list|,
name|Expr
modifier|*
name|MemExpr
parameter_list|,
name|SourceLocation
name|LParenLoc
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
modifier|*
name|CommaLocs
parameter_list|,
name|SourceLocation
name|RParenLoc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ExprResult
name|BuildCallToObjectOfClassType
parameter_list|(
name|Scope
modifier|*
name|S
parameter_list|,
name|Expr
modifier|*
name|Object
parameter_list|,
name|SourceLocation
name|LParenLoc
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
modifier|*
name|CommaLocs
parameter_list|,
name|SourceLocation
name|RParenLoc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|OwningExprResult
name|BuildOverloadedArrowExpr
parameter_list|(
name|Scope
modifier|*
name|S
parameter_list|,
name|ExprArg
name|Base
parameter_list|,
name|SourceLocation
name|OpLoc
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// CheckCallReturnType - Checks that a call expression's return type is
end_comment

begin_comment
comment|/// complete. Returns true on failure. The location passed in is the location
end_comment

begin_comment
comment|/// that best represents the call.
end_comment

begin_function_decl
name|bool
name|CheckCallReturnType
parameter_list|(
name|QualType
name|ReturnType
parameter_list|,
name|SourceLocation
name|Loc
parameter_list|,
name|CallExpr
modifier|*
name|CE
parameter_list|,
name|FunctionDecl
modifier|*
name|FD
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// Helpers for dealing with blocks and functions.
end_comment

begin_function_decl
name|bool
name|CheckParmsForFunctionDef
parameter_list|(
name|FunctionDecl
modifier|*
name|FD
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|CheckCXXDefaultArguments
parameter_list|(
name|FunctionDecl
modifier|*
name|FD
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|CheckExtraCXXDefaultArguments
parameter_list|(
name|Declarator
modifier|&
name|D
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|Scope
modifier|*
name|getNonFieldDeclScope
parameter_list|(
name|Scope
modifier|*
name|S
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// \name Name lookup
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// These routines provide name lookup that is used during semantic
end_comment

begin_comment
comment|/// analysis to resolve the various kinds of names (identifiers,
end_comment

begin_comment
comment|/// overloaded operator names, constructor names, etc.) into zero or
end_comment

begin_comment
comment|/// more declarations within a particular scope. The major entry
end_comment

begin_comment
comment|/// points are LookupName, which performs unqualified name lookup,
end_comment

begin_comment
comment|/// and LookupQualifiedName, which performs qualified name lookup.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// All name lookup is performed based on some specific criteria,
end_comment

begin_comment
comment|/// which specify what names will be visible to name lookup and how
end_comment

begin_comment
comment|/// far name lookup should work. These criteria are important both
end_comment

begin_comment
comment|/// for capturing language semantics (certain lookups will ignore
end_comment

begin_comment
comment|/// certain names, for example) and for performance, since name
end_comment

begin_comment
comment|/// lookup is often a bottleneck in the compilation of C++. Name
end_comment

begin_comment
comment|/// lookup criteria is specified via the LookupCriteria enumeration.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// The results of name lookup can vary based on the kind of name
end_comment

begin_comment
comment|/// lookup performed, the current language, and the translation
end_comment

begin_comment
comment|/// unit. In C, for example, name lookup will either return nothing
end_comment

begin_comment
comment|/// (no entity found) or a single declaration. In C++, name lookup
end_comment

begin_comment
comment|/// can additionally refer to a set of overloaded functions or
end_comment

begin_comment
comment|/// result in an ambiguity. All of the possible results of name
end_comment

begin_comment
comment|/// lookup are captured by the LookupResult class, which provides
end_comment

begin_comment
comment|/// the ability to distinguish among them.
end_comment

begin_comment
comment|//@{
end_comment

begin_comment
comment|/// @brief Describes the kind of name lookup to perform.
end_comment

begin_enum
enum|enum
name|LookupNameKind
block|{
comment|/// Ordinary name lookup, which finds ordinary names (functions,
comment|/// variables, typedefs, etc.) in C and most kinds of names
comment|/// (functions, variables, members, types, etc.) in C++.
name|LookupOrdinaryName
init|=
literal|0
block|,
comment|/// Tag name lookup, which finds the names of enums, classes,
comment|/// structs, and unions.
name|LookupTagName
block|,
comment|/// Member name lookup, which finds the names of
comment|/// class/struct/union members.
name|LookupMemberName
block|,
comment|// Look up of an operator name (e.g., operator+) for use with
comment|// operator overloading. This lookup is similar to ordinary name
comment|// lookup, but will ignore any declarations that are class
comment|// members.
name|LookupOperatorName
block|,
comment|/// Look up of a name that precedes the '::' scope resolution
comment|/// operator in C++. This lookup completely ignores operator, object,
comment|/// function, and enumerator names (C++ [basic.lookup.qual]p1).
name|LookupNestedNameSpecifierName
block|,
comment|/// Look up a namespace name within a C++ using directive or
comment|/// namespace alias definition, ignoring non-namespace names (C++
comment|/// [basic.lookup.udir]p1).
name|LookupNamespaceName
block|,
comment|/// Look up all declarations in a scope with the given name,
comment|/// including resolved using declarations.  This is appropriate
comment|/// for checking redeclarations for a using declaration.
name|LookupUsingDeclName
block|,
comment|/// Look up an ordinary name that is going to be redeclared as a
comment|/// name with linkage. This lookup ignores any declarations that
comment|/// are outside of the current scope unless they have linkage. See
comment|/// C99 6.2.2p4-5 and C++ [basic.link]p6.
name|LookupRedeclarationWithLinkage
block|,
comment|/// Look up the name of an Objective-C protocol.
name|LookupObjCProtocolName
block|}
enum|;
end_enum

begin_comment
comment|/// \brief Specifies whether (or how) name lookup is being performed for a
end_comment

begin_comment
comment|/// redeclaration (vs. a reference).
end_comment

begin_enum
enum|enum
name|RedeclarationKind
block|{
comment|/// \brief The lookup is a reference to this name that is not for the
comment|/// purpose of redeclaring the name.
name|NotForRedeclaration
init|=
literal|0
block|,
comment|/// \brief The lookup results will be used for redeclaration of a name,
comment|/// if an entity by that name already exists.
name|ForRedeclaration
block|}
enum|;
end_enum

begin_label
name|private
label|:
end_label

begin_function_decl
name|bool
name|CppLookupName
parameter_list|(
name|LookupResult
modifier|&
name|R
parameter_list|,
name|Scope
modifier|*
name|S
parameter_list|)
function_decl|;
end_function_decl

begin_label
name|public
label|:
end_label

begin_comment
comment|/// \brief Look up a name, looking for a single declaration.  Return
end_comment

begin_comment
comment|/// null if the results were absent, ambiguous, or overloaded.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// It is preferable to use the elaborated form and explicitly handle
end_comment

begin_comment
comment|/// ambiguity and overloaded.
end_comment

begin_function_decl
name|NamedDecl
modifier|*
name|LookupSingleName
parameter_list|(
name|Scope
modifier|*
name|S
parameter_list|,
name|DeclarationName
name|Name
parameter_list|,
name|SourceLocation
name|Loc
parameter_list|,
name|LookupNameKind
name|NameKind
parameter_list|,
name|RedeclarationKind
name|Redecl
init|=
name|NotForRedeclaration
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|LookupName
parameter_list|(
name|LookupResult
modifier|&
name|R
parameter_list|,
name|Scope
modifier|*
name|S
parameter_list|,
name|bool
name|AllowBuiltinCreation
init|=
name|false
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|LookupQualifiedName
parameter_list|(
name|LookupResult
modifier|&
name|R
parameter_list|,
name|DeclContext
modifier|*
name|LookupCtx
parameter_list|,
name|bool
name|InUnqualifiedLookup
init|=
name|false
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|LookupParsedName
parameter_list|(
name|LookupResult
modifier|&
name|R
parameter_list|,
name|Scope
modifier|*
name|S
parameter_list|,
name|CXXScopeSpec
modifier|*
name|SS
parameter_list|,
name|bool
name|AllowBuiltinCreation
init|=
name|false
parameter_list|,
name|bool
name|EnteringContext
init|=
name|false
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ObjCProtocolDecl
modifier|*
name|LookupProtocol
parameter_list|(
name|IdentifierInfo
modifier|*
name|II
parameter_list|,
name|SourceLocation
name|IdLoc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|LookupOverloadedOperatorName
parameter_list|(
name|OverloadedOperatorKind
name|Op
parameter_list|,
name|Scope
modifier|*
name|S
parameter_list|,
name|QualType
name|T1
parameter_list|,
name|QualType
name|T2
parameter_list|,
name|UnresolvedSetImpl
modifier|&
name|Functions
parameter_list|)
function_decl|;
end_function_decl

begin_expr_stmt
name|DeclContext
operator|::
name|lookup_result
name|LookupConstructors
argument_list|(
name|CXXRecordDecl
operator|*
name|Class
argument_list|)
expr_stmt|;
end_expr_stmt

begin_function_decl
name|CXXDestructorDecl
modifier|*
name|LookupDestructor
parameter_list|(
name|CXXRecordDecl
modifier|*
name|Class
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ArgumentDependentLookup
parameter_list|(
name|DeclarationName
name|Name
parameter_list|,
name|bool
name|Operator
parameter_list|,
name|Expr
modifier|*
modifier|*
name|Args
parameter_list|,
name|unsigned
name|NumArgs
parameter_list|,
name|ADLResult
modifier|&
name|Functions
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|LookupVisibleDecls
parameter_list|(
name|Scope
modifier|*
name|S
parameter_list|,
name|LookupNameKind
name|Kind
parameter_list|,
name|VisibleDeclConsumer
modifier|&
name|Consumer
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|LookupVisibleDecls
parameter_list|(
name|DeclContext
modifier|*
name|Ctx
parameter_list|,
name|LookupNameKind
name|Kind
parameter_list|,
name|VisibleDeclConsumer
modifier|&
name|Consumer
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// \brief The context in which typo-correction occurs.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// The typo-correction context affects which keywords (if any) are
end_comment

begin_comment
comment|/// considered when trying to correct for typos.
end_comment

begin_enum
enum|enum
name|CorrectTypoContext
block|{
comment|/// \brief An unknown context, where any keyword might be valid.
name|CTC_Unknown
block|,
comment|/// \brief A context where no keywords are used (e.g. we expect an actual
comment|/// name).
name|CTC_NoKeywords
block|,
comment|/// \brief A context where we're correcting a type name.
name|CTC_Type
block|,
comment|/// \brief An expression context.
name|CTC_Expression
block|,
comment|/// \brief A type cast, or anything else that can be followed by a '<'.
name|CTC_CXXCasts
block|,
comment|/// \brief A member lookup context.
name|CTC_MemberLookup
block|,
comment|/// \brief The receiver of an Objective-C message send within an
comment|/// Objective-C method where 'super' is a valid keyword.
name|CTC_ObjCMessageReceiver
block|}
enum|;
end_enum

begin_function_decl
name|DeclarationName
name|CorrectTypo
parameter_list|(
name|LookupResult
modifier|&
name|R
parameter_list|,
name|Scope
modifier|*
name|S
parameter_list|,
name|CXXScopeSpec
modifier|*
name|SS
parameter_list|,
name|DeclContext
modifier|*
name|MemberContext
init|=
literal|0
parameter_list|,
name|bool
name|EnteringContext
init|=
name|false
parameter_list|,
name|CorrectTypoContext
name|CTC
init|=
name|CTC_Unknown
parameter_list|,
specifier|const
name|ObjCObjectPointerType
modifier|*
name|OPT
init|=
literal|0
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|FindAssociatedClassesAndNamespaces
parameter_list|(
name|Expr
modifier|*
modifier|*
name|Args
parameter_list|,
name|unsigned
name|NumArgs
parameter_list|,
name|AssociatedNamespaceSet
modifier|&
name|AssociatedNamespaces
parameter_list|,
name|AssociatedClassSet
modifier|&
name|AssociatedClasses
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|DiagnoseAmbiguousLookup
parameter_list|(
name|LookupResult
modifier|&
name|Result
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|//@}
end_comment

begin_function_decl
name|ObjCInterfaceDecl
modifier|*
name|getObjCInterfaceDecl
parameter_list|(
name|IdentifierInfo
modifier|*
modifier|&
name|Id
parameter_list|,
name|SourceLocation
name|IdLoc
parameter_list|,
name|bool
name|TypoCorrection
init|=
name|false
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|NamedDecl
modifier|*
name|LazilyCreateBuiltin
parameter_list|(
name|IdentifierInfo
modifier|*
name|II
parameter_list|,
name|unsigned
name|ID
parameter_list|,
name|Scope
modifier|*
name|S
parameter_list|,
name|bool
name|ForRedeclaration
parameter_list|,
name|SourceLocation
name|Loc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|NamedDecl
modifier|*
name|ImplicitlyDefineFunction
parameter_list|(
name|SourceLocation
name|Loc
parameter_list|,
name|IdentifierInfo
modifier|&
name|II
parameter_list|,
name|Scope
modifier|*
name|S
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|AddKnownFunctionAttributes
parameter_list|(
name|FunctionDecl
modifier|*
name|FD
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|// More parsing and symbol table subroutines.
end_comment

begin_comment
comment|// Decl attributes - this routine is the top level dispatcher.
end_comment

begin_function_decl
name|void
name|ProcessDeclAttributes
parameter_list|(
name|Scope
modifier|*
name|S
parameter_list|,
name|Decl
modifier|*
name|D
parameter_list|,
specifier|const
name|Declarator
modifier|&
name|PD
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ProcessDeclAttributeList
parameter_list|(
name|Scope
modifier|*
name|S
parameter_list|,
name|Decl
modifier|*
name|D
parameter_list|,
specifier|const
name|AttributeList
modifier|*
name|AttrList
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|WarnUndefinedMethod
parameter_list|(
name|SourceLocation
name|ImpLoc
parameter_list|,
name|ObjCMethodDecl
modifier|*
name|method
parameter_list|,
name|bool
modifier|&
name|IncompleteImpl
parameter_list|,
name|unsigned
name|DiagID
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|WarnConflictingTypedMethods
parameter_list|(
name|ObjCMethodDecl
modifier|*
name|ImpMethod
parameter_list|,
name|ObjCMethodDecl
modifier|*
name|IntfMethod
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|isPropertyReadonly
parameter_list|(
name|ObjCPropertyDecl
modifier|*
name|PropertyDecl
parameter_list|,
name|ObjCInterfaceDecl
modifier|*
name|IDecl
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// CheckProtocolMethodDefs - This routine checks unimplemented
end_comment

begin_comment
comment|/// methods declared in protocol, and those referenced by it.
end_comment

begin_comment
comment|/// \param IDecl - Used for checking for methods which may have been
end_comment

begin_comment
comment|/// inherited.
end_comment

begin_decl_stmt
name|void
name|CheckProtocolMethodDefs
argument_list|(
name|SourceLocation
name|ImpLoc
argument_list|,
name|ObjCProtocolDecl
operator|*
name|PDecl
argument_list|,
name|bool
operator|&
name|IncompleteImpl
argument_list|,
specifier|const
name|llvm
operator|::
name|DenseSet
operator|<
name|Selector
operator|>
operator|&
name|InsMap
argument_list|,
specifier|const
name|llvm
operator|::
name|DenseSet
operator|<
name|Selector
operator|>
operator|&
name|ClsMap
argument_list|,
name|ObjCContainerDecl
operator|*
name|CDecl
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// CheckImplementationIvars - This routine checks if the instance variables
end_comment

begin_comment
comment|/// listed in the implelementation match those listed in the interface.
end_comment

begin_function_decl
name|void
name|CheckImplementationIvars
parameter_list|(
name|ObjCImplementationDecl
modifier|*
name|ImpDecl
parameter_list|,
name|ObjCIvarDecl
modifier|*
modifier|*
name|Fields
parameter_list|,
name|unsigned
name|nIvars
parameter_list|,
name|SourceLocation
name|Loc
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// ImplMethodsVsClassMethods - This is main routine to warn if any method
end_comment

begin_comment
comment|/// remains unimplemented in the class or category @implementation.
end_comment

begin_function_decl
name|void
name|ImplMethodsVsClassMethods
parameter_list|(
name|Scope
modifier|*
name|S
parameter_list|,
name|ObjCImplDecl
modifier|*
name|IMPDecl
parameter_list|,
name|ObjCContainerDecl
modifier|*
name|IDecl
parameter_list|,
name|bool
name|IncompleteImpl
init|=
name|false
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// DiagnoseUnimplementedProperties - This routine warns on those properties
end_comment

begin_comment
comment|/// which must be implemented by this implementation.
end_comment

begin_decl_stmt
name|void
name|DiagnoseUnimplementedProperties
argument_list|(
name|Scope
operator|*
name|S
argument_list|,
name|ObjCImplDecl
operator|*
name|IMPDecl
argument_list|,
name|ObjCContainerDecl
operator|*
name|CDecl
argument_list|,
specifier|const
name|llvm
operator|::
name|DenseSet
operator|<
name|Selector
operator|>
operator|&
name|InsMap
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// DefaultSynthesizeProperties - This routine default synthesizes all
end_comment

begin_comment
comment|/// properties which must be synthesized in class's @implementation.
end_comment

begin_function_decl
name|void
name|DefaultSynthesizeProperties
parameter_list|(
name|Scope
modifier|*
name|S
parameter_list|,
name|ObjCImplDecl
modifier|*
name|IMPDecl
parameter_list|,
name|ObjCInterfaceDecl
modifier|*
name|IDecl
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// CollectImmediateProperties - This routine collects all properties in
end_comment

begin_comment
comment|/// the class and its conforming protocols; but not those it its super class.
end_comment

begin_decl_stmt
name|void
name|CollectImmediateProperties
argument_list|(
name|ObjCContainerDecl
operator|*
name|CDecl
argument_list|,
name|llvm
operator|::
name|DenseMap
operator|<
name|IdentifierInfo
operator|*
argument_list|,
name|ObjCPropertyDecl
operator|*
operator|>
operator|&
name|PropMap
argument_list|,
name|llvm
operator|::
name|DenseMap
operator|<
name|IdentifierInfo
operator|*
argument_list|,
name|ObjCPropertyDecl
operator|*
operator|>
operator|&
name|SuperPropMap
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// LookupPropertyDecl - Looks up a property in the current class and all
end_comment

begin_comment
comment|/// its protocols.
end_comment

begin_function_decl
name|ObjCPropertyDecl
modifier|*
name|LookupPropertyDecl
parameter_list|(
specifier|const
name|ObjCContainerDecl
modifier|*
name|CDecl
parameter_list|,
name|IdentifierInfo
modifier|*
name|II
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// Called by ActOnProperty to handle @property declarations in
end_comment

begin_comment
comment|////  class extensions.
end_comment

begin_decl_stmt
name|DeclPtrTy
name|HandlePropertyInClassExtension
argument_list|(
name|Scope
operator|*
name|S
argument_list|,
name|ObjCCategoryDecl
operator|*
name|CDecl
argument_list|,
name|SourceLocation
name|AtLoc
argument_list|,
name|FieldDeclarator
operator|&
name|FD
argument_list|,
name|Selector
name|GetterSel
argument_list|,
name|Selector
name|SetterSel
argument_list|,
specifier|const
name|bool
name|isAssign
argument_list|,
specifier|const
name|bool
name|isReadWrite
argument_list|,
specifier|const
name|unsigned
name|Attributes
argument_list|,
name|bool
operator|*
name|isOverridingProperty
argument_list|,
name|TypeSourceInfo
operator|*
name|T
argument_list|,
name|tok
operator|::
name|ObjCKeywordKind
name|MethodImplKind
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// Called by ActOnProperty and HandlePropertyInClassExtension to
end_comment

begin_comment
comment|///  handle creating the ObjcPropertyDecl for a category or @interface.
end_comment

begin_decl_stmt
name|ObjCPropertyDecl
modifier|*
name|CreatePropertyDecl
argument_list|(
name|Scope
operator|*
name|S
argument_list|,
name|ObjCContainerDecl
operator|*
name|CDecl
argument_list|,
name|SourceLocation
name|AtLoc
argument_list|,
name|FieldDeclarator
operator|&
name|FD
argument_list|,
name|Selector
name|GetterSel
argument_list|,
name|Selector
name|SetterSel
argument_list|,
specifier|const
name|bool
name|isAssign
argument_list|,
specifier|const
name|bool
name|isReadWrite
argument_list|,
specifier|const
name|unsigned
name|Attributes
argument_list|,
name|TypeSourceInfo
operator|*
name|T
argument_list|,
name|tok
operator|::
name|ObjCKeywordKind
name|MethodImplKind
argument_list|,
name|DeclContext
operator|*
name|lexicalDC
operator|=
literal|0
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// AtomicPropertySetterGetterRules - This routine enforces the rule (via
end_comment

begin_comment
comment|/// warning) when atomic property has one but not the other user-declared
end_comment

begin_comment
comment|/// setter or getter.
end_comment

begin_function_decl
name|void
name|AtomicPropertySetterGetterRules
parameter_list|(
name|ObjCImplDecl
modifier|*
name|IMPDecl
parameter_list|,
name|ObjCContainerDecl
modifier|*
name|IDecl
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|DiagnoseDuplicateIvars
parameter_list|(
name|ObjCInterfaceDecl
modifier|*
name|ID
parameter_list|,
name|ObjCInterfaceDecl
modifier|*
name|SID
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// MatchTwoMethodDeclarations - Checks if two methods' type match and returns
end_comment

begin_comment
comment|/// true, or false, accordingly.
end_comment

begin_function_decl
name|bool
name|MatchTwoMethodDeclarations
parameter_list|(
specifier|const
name|ObjCMethodDecl
modifier|*
name|Method
parameter_list|,
specifier|const
name|ObjCMethodDecl
modifier|*
name|PrevMethod
parameter_list|,
name|bool
name|matchBasedOnSizeAndAlignment
init|=
name|false
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// MatchAllMethodDeclarations - Check methods declaraed in interface or
end_comment

begin_comment
comment|/// or protocol against those declared in their implementations.
end_comment

begin_decl_stmt
name|void
name|MatchAllMethodDeclarations
argument_list|(
specifier|const
name|llvm
operator|::
name|DenseSet
operator|<
name|Selector
operator|>
operator|&
name|InsMap
argument_list|,
specifier|const
name|llvm
operator|::
name|DenseSet
operator|<
name|Selector
operator|>
operator|&
name|ClsMap
argument_list|,
name|llvm
operator|::
name|DenseSet
operator|<
name|Selector
operator|>
operator|&
name|InsMapSeen
argument_list|,
name|llvm
operator|::
name|DenseSet
operator|<
name|Selector
operator|>
operator|&
name|ClsMapSeen
argument_list|,
name|ObjCImplDecl
operator|*
name|IMPDecl
argument_list|,
name|ObjCContainerDecl
operator|*
name|IDecl
argument_list|,
name|bool
operator|&
name|IncompleteImpl
argument_list|,
name|bool
name|ImmediateClass
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// AddInstanceMethodToGlobalPool - All instance methods in a translation
end_comment

begin_comment
comment|/// unit are added to a global pool. This allows us to efficiently associate
end_comment

begin_comment
comment|/// a selector with a method declaraation for purposes of typechecking
end_comment

begin_comment
comment|/// messages sent to "id" (where the class of the object is unknown).
end_comment

begin_function_decl
name|void
name|AddInstanceMethodToGlobalPool
parameter_list|(
name|ObjCMethodDecl
modifier|*
name|Method
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// LookupInstanceMethodInGlobalPool - Returns the method and warns if
end_comment

begin_comment
comment|/// there are multiple signatures.
end_comment

begin_function_decl
name|ObjCMethodDecl
modifier|*
name|LookupInstanceMethodInGlobalPool
parameter_list|(
name|Selector
name|Sel
parameter_list|,
name|SourceRange
name|R
parameter_list|,
name|bool
name|warn
init|=
name|true
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// LookupFactoryMethodInGlobalPool - Returns the method and warns if
end_comment

begin_comment
comment|/// there are multiple signatures.
end_comment

begin_function_decl
name|ObjCMethodDecl
modifier|*
name|LookupFactoryMethodInGlobalPool
parameter_list|(
name|Selector
name|Sel
parameter_list|,
name|SourceRange
name|R
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// AddFactoryMethodToGlobalPool - Same as above, but for factory methods.
end_comment

begin_function_decl
name|void
name|AddFactoryMethodToGlobalPool
parameter_list|(
name|ObjCMethodDecl
modifier|*
name|Method
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// CollectIvarsToConstructOrDestruct - Collect those ivars which require
end_comment

begin_comment
comment|/// initialization.
end_comment

begin_decl_stmt
name|void
name|CollectIvarsToConstructOrDestruct
argument_list|(
specifier|const
name|ObjCInterfaceDecl
operator|*
name|OI
argument_list|,
name|llvm
operator|::
name|SmallVectorImpl
operator|<
name|ObjCIvarDecl
operator|*
operator|>
operator|&
name|Ivars
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|//===--------------------------------------------------------------------===//
end_comment

begin_comment
comment|// Statement Parsing Callbacks: SemaStmt.cpp.
end_comment

begin_label
name|public
label|:
end_label

begin_function_decl
name|virtual
name|OwningStmtResult
name|ActOnExprStmt
parameter_list|(
name|FullExprArg
name|Expr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|virtual
name|OwningStmtResult
name|ActOnNullStmt
parameter_list|(
name|SourceLocation
name|SemiLoc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|virtual
name|OwningStmtResult
name|ActOnCompoundStmt
parameter_list|(
name|SourceLocation
name|L
parameter_list|,
name|SourceLocation
name|R
parameter_list|,
name|MultiStmtArg
name|Elts
parameter_list|,
name|bool
name|isStmtExpr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|virtual
name|OwningStmtResult
name|ActOnDeclStmt
parameter_list|(
name|DeclGroupPtrTy
name|Decl
parameter_list|,
name|SourceLocation
name|StartLoc
parameter_list|,
name|SourceLocation
name|EndLoc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|virtual
name|void
name|ActOnForEachDeclStmt
parameter_list|(
name|DeclGroupPtrTy
name|Decl
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|virtual
name|OwningStmtResult
name|ActOnCaseStmt
parameter_list|(
name|SourceLocation
name|CaseLoc
parameter_list|,
name|ExprArg
name|LHSVal
parameter_list|,
name|SourceLocation
name|DotDotDotLoc
parameter_list|,
name|ExprArg
name|RHSVal
parameter_list|,
name|SourceLocation
name|ColonLoc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|virtual
name|void
name|ActOnCaseStmtBody
parameter_list|(
name|StmtTy
modifier|*
name|CaseStmt
parameter_list|,
name|StmtArg
name|SubStmt
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|virtual
name|OwningStmtResult
name|ActOnDefaultStmt
parameter_list|(
name|SourceLocation
name|DefaultLoc
parameter_list|,
name|SourceLocation
name|ColonLoc
parameter_list|,
name|StmtArg
name|SubStmt
parameter_list|,
name|Scope
modifier|*
name|CurScope
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|virtual
name|OwningStmtResult
name|ActOnLabelStmt
parameter_list|(
name|SourceLocation
name|IdentLoc
parameter_list|,
name|IdentifierInfo
modifier|*
name|II
parameter_list|,
name|SourceLocation
name|ColonLoc
parameter_list|,
name|StmtArg
name|SubStmt
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|virtual
name|OwningStmtResult
name|ActOnIfStmt
parameter_list|(
name|SourceLocation
name|IfLoc
parameter_list|,
name|FullExprArg
name|CondVal
parameter_list|,
name|DeclPtrTy
name|CondVar
parameter_list|,
name|StmtArg
name|ThenVal
parameter_list|,
name|SourceLocation
name|ElseLoc
parameter_list|,
name|StmtArg
name|ElseVal
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|virtual
name|OwningStmtResult
name|ActOnStartOfSwitchStmt
parameter_list|(
name|SourceLocation
name|SwitchLoc
parameter_list|,
name|ExprArg
name|Cond
parameter_list|,
name|DeclPtrTy
name|CondVar
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|virtual
name|OwningStmtResult
name|ActOnFinishSwitchStmt
parameter_list|(
name|SourceLocation
name|SwitchLoc
parameter_list|,
name|StmtArg
name|Switch
parameter_list|,
name|StmtArg
name|Body
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|virtual
name|OwningStmtResult
name|ActOnWhileStmt
parameter_list|(
name|SourceLocation
name|WhileLoc
parameter_list|,
name|FullExprArg
name|Cond
parameter_list|,
name|DeclPtrTy
name|CondVar
parameter_list|,
name|StmtArg
name|Body
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|virtual
name|OwningStmtResult
name|ActOnDoStmt
parameter_list|(
name|SourceLocation
name|DoLoc
parameter_list|,
name|StmtArg
name|Body
parameter_list|,
name|SourceLocation
name|WhileLoc
parameter_list|,
name|SourceLocation
name|CondLParen
parameter_list|,
name|ExprArg
name|Cond
parameter_list|,
name|SourceLocation
name|CondRParen
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|virtual
name|OwningStmtResult
name|ActOnForStmt
parameter_list|(
name|SourceLocation
name|ForLoc
parameter_list|,
name|SourceLocation
name|LParenLoc
parameter_list|,
name|StmtArg
name|First
parameter_list|,
name|FullExprArg
name|Second
parameter_list|,
name|DeclPtrTy
name|SecondVar
parameter_list|,
name|FullExprArg
name|Third
parameter_list|,
name|SourceLocation
name|RParenLoc
parameter_list|,
name|StmtArg
name|Body
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|virtual
name|OwningStmtResult
name|ActOnObjCForCollectionStmt
parameter_list|(
name|SourceLocation
name|ForColLoc
parameter_list|,
name|SourceLocation
name|LParenLoc
parameter_list|,
name|StmtArg
name|First
parameter_list|,
name|ExprArg
name|Second
parameter_list|,
name|SourceLocation
name|RParenLoc
parameter_list|,
name|StmtArg
name|Body
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|virtual
name|OwningStmtResult
name|ActOnGotoStmt
parameter_list|(
name|SourceLocation
name|GotoLoc
parameter_list|,
name|SourceLocation
name|LabelLoc
parameter_list|,
name|IdentifierInfo
modifier|*
name|LabelII
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|virtual
name|OwningStmtResult
name|ActOnIndirectGotoStmt
parameter_list|(
name|SourceLocation
name|GotoLoc
parameter_list|,
name|SourceLocation
name|StarLoc
parameter_list|,
name|ExprArg
name|DestExp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|virtual
name|OwningStmtResult
name|ActOnContinueStmt
parameter_list|(
name|SourceLocation
name|ContinueLoc
parameter_list|,
name|Scope
modifier|*
name|CurScope
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|virtual
name|OwningStmtResult
name|ActOnBreakStmt
parameter_list|(
name|SourceLocation
name|GotoLoc
parameter_list|,
name|Scope
modifier|*
name|CurScope
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|virtual
name|OwningStmtResult
name|ActOnReturnStmt
parameter_list|(
name|SourceLocation
name|ReturnLoc
parameter_list|,
name|ExprArg
name|RetValExp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|OwningStmtResult
name|ActOnBlockReturnStmt
parameter_list|(
name|SourceLocation
name|ReturnLoc
parameter_list|,
name|Expr
modifier|*
name|RetValExp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|virtual
name|OwningStmtResult
name|ActOnAsmStmt
parameter_list|(
name|SourceLocation
name|AsmLoc
parameter_list|,
name|bool
name|IsSimple
parameter_list|,
name|bool
name|IsVolatile
parameter_list|,
name|unsigned
name|NumOutputs
parameter_list|,
name|unsigned
name|NumInputs
parameter_list|,
name|IdentifierInfo
modifier|*
modifier|*
name|Names
parameter_list|,
name|MultiExprArg
name|Constraints
parameter_list|,
name|MultiExprArg
name|Exprs
parameter_list|,
name|ExprArg
name|AsmString
parameter_list|,
name|MultiExprArg
name|Clobbers
parameter_list|,
name|SourceLocation
name|RParenLoc
parameter_list|,
name|bool
name|MSAsm
init|=
name|false
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|VarDecl
modifier|*
name|BuildObjCExceptionDecl
parameter_list|(
name|TypeSourceInfo
modifier|*
name|TInfo
parameter_list|,
name|QualType
name|ExceptionType
parameter_list|,
name|IdentifierInfo
modifier|*
name|Name
parameter_list|,
name|SourceLocation
name|NameLoc
parameter_list|,
name|bool
name|Invalid
init|=
name|false
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|virtual
name|DeclPtrTy
name|ActOnObjCExceptionDecl
parameter_list|(
name|Scope
modifier|*
name|S
parameter_list|,
name|Declarator
modifier|&
name|D
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|virtual
name|OwningStmtResult
name|ActOnObjCAtCatchStmt
parameter_list|(
name|SourceLocation
name|AtLoc
parameter_list|,
name|SourceLocation
name|RParen
parameter_list|,
name|DeclPtrTy
name|Parm
parameter_list|,
name|StmtArg
name|Body
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|virtual
name|OwningStmtResult
name|ActOnObjCAtFinallyStmt
parameter_list|(
name|SourceLocation
name|AtLoc
parameter_list|,
name|StmtArg
name|Body
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|virtual
name|OwningStmtResult
name|ActOnObjCAtTryStmt
parameter_list|(
name|SourceLocation
name|AtLoc
parameter_list|,
name|StmtArg
name|Try
parameter_list|,
name|MultiStmtArg
name|Catch
parameter_list|,
name|StmtArg
name|Finally
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|virtual
name|OwningStmtResult
name|BuildObjCAtThrowStmt
parameter_list|(
name|SourceLocation
name|AtLoc
parameter_list|,
name|ExprArg
name|Throw
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|virtual
name|OwningStmtResult
name|ActOnObjCAtThrowStmt
parameter_list|(
name|SourceLocation
name|AtLoc
parameter_list|,
name|ExprArg
name|Throw
parameter_list|,
name|Scope
modifier|*
name|CurScope
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|virtual
name|OwningStmtResult
name|ActOnObjCAtSynchronizedStmt
parameter_list|(
name|SourceLocation
name|AtLoc
parameter_list|,
name|ExprArg
name|SynchExpr
parameter_list|,
name|StmtArg
name|SynchBody
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|VarDecl
modifier|*
name|BuildExceptionDeclaration
parameter_list|(
name|Scope
modifier|*
name|S
parameter_list|,
name|QualType
name|ExDeclType
parameter_list|,
name|TypeSourceInfo
modifier|*
name|TInfo
parameter_list|,
name|IdentifierInfo
modifier|*
name|Name
parameter_list|,
name|SourceLocation
name|Loc
parameter_list|,
name|SourceRange
name|Range
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|virtual
name|DeclPtrTy
name|ActOnExceptionDeclarator
parameter_list|(
name|Scope
modifier|*
name|S
parameter_list|,
name|Declarator
modifier|&
name|D
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|virtual
name|OwningStmtResult
name|ActOnCXXCatchBlock
parameter_list|(
name|SourceLocation
name|CatchLoc
parameter_list|,
name|DeclPtrTy
name|ExDecl
parameter_list|,
name|StmtArg
name|HandlerBlock
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|virtual
name|OwningStmtResult
name|ActOnCXXTryBlock
parameter_list|(
name|SourceLocation
name|TryLoc
parameter_list|,
name|StmtArg
name|TryBlock
parameter_list|,
name|MultiStmtArg
name|Handlers
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|DiagnoseReturnInConstructorExceptionHandler
parameter_list|(
name|CXXTryStmt
modifier|*
name|TryBlock
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// DiagnoseUnusedExprResult - If the statement passed in is an expression
end_comment

begin_comment
comment|/// whose result is unused, warn.
end_comment

begin_function_decl
name|void
name|DiagnoseUnusedExprResult
parameter_list|(
specifier|const
name|Stmt
modifier|*
name|S
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|DiagnoseUnusedDecl
parameter_list|(
specifier|const
name|NamedDecl
modifier|*
name|ND
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ParsingDeclStackState
name|PushParsingDeclaration
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|PopParsingDeclaration
parameter_list|(
name|ParsingDeclStackState
name|S
parameter_list|,
name|DeclPtrTy
name|D
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|EmitDeprecationWarning
parameter_list|(
name|NamedDecl
modifier|*
name|D
parameter_list|,
name|SourceLocation
name|Loc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|HandleDelayedDeprecationCheck
parameter_list|(
name|DelayedDiagnostic
modifier|&
name|DD
parameter_list|,
name|Decl
modifier|*
name|Ctx
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|//===--------------------------------------------------------------------===//
end_comment

begin_comment
comment|// Expression Parsing Callbacks: SemaExpr.cpp.
end_comment

begin_function_decl
name|bool
name|DiagnoseUseOfDecl
parameter_list|(
name|NamedDecl
modifier|*
name|D
parameter_list|,
name|SourceLocation
name|Loc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|DiagnosePropertyAccessorMismatch
parameter_list|(
name|ObjCPropertyDecl
modifier|*
name|PD
parameter_list|,
name|ObjCMethodDecl
modifier|*
name|Getter
parameter_list|,
name|SourceLocation
name|Loc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|DiagnoseSentinelCalls
parameter_list|(
name|NamedDecl
modifier|*
name|D
parameter_list|,
name|SourceLocation
name|Loc
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
end_function_decl

begin_function_decl
name|virtual
name|void
name|PushExpressionEvaluationContext
parameter_list|(
name|ExpressionEvaluationContext
name|NewContext
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|virtual
name|void
name|PopExpressionEvaluationContext
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|MarkDeclarationReferenced
parameter_list|(
name|SourceLocation
name|Loc
parameter_list|,
name|Decl
modifier|*
name|D
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|MarkDeclarationsReferencedInType
parameter_list|(
name|SourceLocation
name|Loc
parameter_list|,
name|QualType
name|T
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|DiagRuntimeBehavior
parameter_list|(
name|SourceLocation
name|Loc
parameter_list|,
specifier|const
name|PartialDiagnostic
modifier|&
name|PD
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|// Primary Expressions.
end_comment

begin_decl_stmt
name|virtual
name|SourceRange
name|getExprRange
argument_list|(
name|ExprTy
operator|*
name|E
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_function_decl
name|virtual
name|OwningExprResult
name|ActOnIdExpression
parameter_list|(
name|Scope
modifier|*
name|S
parameter_list|,
name|CXXScopeSpec
modifier|&
name|SS
parameter_list|,
name|UnqualifiedId
modifier|&
name|Name
parameter_list|,
name|bool
name|HasTrailingLParen
parameter_list|,
name|bool
name|IsAddressOfOperand
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|DiagnoseEmptyLookup
parameter_list|(
name|Scope
modifier|*
name|S
parameter_list|,
name|CXXScopeSpec
modifier|&
name|SS
parameter_list|,
name|LookupResult
modifier|&
name|R
parameter_list|,
name|CorrectTypoContext
name|CTC
init|=
name|CTC_Unknown
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|OwningExprResult
name|LookupInObjCMethod
parameter_list|(
name|LookupResult
modifier|&
name|R
parameter_list|,
name|Scope
modifier|*
name|S
parameter_list|,
name|IdentifierInfo
modifier|*
name|II
parameter_list|,
name|bool
name|AllowBuiltinCreation
init|=
name|false
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|OwningExprResult
name|ActOnDependentIdExpression
parameter_list|(
specifier|const
name|CXXScopeSpec
modifier|&
name|SS
parameter_list|,
name|DeclarationName
name|Name
parameter_list|,
name|SourceLocation
name|NameLoc
parameter_list|,
name|bool
name|isAddressOfOperand
parameter_list|,
specifier|const
name|TemplateArgumentListInfo
modifier|*
name|TemplateArgs
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|OwningExprResult
name|BuildDeclRefExpr
parameter_list|(
name|ValueDecl
modifier|*
name|D
parameter_list|,
name|QualType
name|Ty
parameter_list|,
name|SourceLocation
name|Loc
parameter_list|,
specifier|const
name|CXXScopeSpec
modifier|*
name|SS
init|=
literal|0
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
name|VarDecl
modifier|*
name|BuildAnonymousStructUnionMemberPath
argument_list|(
name|FieldDecl
operator|*
name|Field
argument_list|,
name|llvm
operator|::
name|SmallVectorImpl
operator|<
name|FieldDecl
operator|*
operator|>
operator|&
name|Path
argument_list|)
decl_stmt|;
end_decl_stmt

begin_function_decl
name|OwningExprResult
name|BuildAnonymousStructUnionMemberReference
parameter_list|(
name|SourceLocation
name|Loc
parameter_list|,
name|FieldDecl
modifier|*
name|Field
parameter_list|,
name|Expr
modifier|*
name|BaseObjectExpr
init|=
literal|0
parameter_list|,
name|SourceLocation
name|OpLoc
init|=
name|SourceLocation
argument_list|()
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|OwningExprResult
name|BuildPossibleImplicitMemberExpr
parameter_list|(
specifier|const
name|CXXScopeSpec
modifier|&
name|SS
parameter_list|,
name|LookupResult
modifier|&
name|R
parameter_list|,
specifier|const
name|TemplateArgumentListInfo
modifier|*
name|TemplateArgs
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|OwningExprResult
name|BuildImplicitMemberExpr
parameter_list|(
specifier|const
name|CXXScopeSpec
modifier|&
name|SS
parameter_list|,
name|LookupResult
modifier|&
name|R
parameter_list|,
specifier|const
name|TemplateArgumentListInfo
modifier|*
name|TemplateArgs
parameter_list|,
name|bool
name|IsDefiniteInstance
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|UseArgumentDependentLookup
parameter_list|(
specifier|const
name|CXXScopeSpec
modifier|&
name|SS
parameter_list|,
specifier|const
name|LookupResult
modifier|&
name|R
parameter_list|,
name|bool
name|HasTrailingLParen
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|OwningExprResult
name|BuildQualifiedDeclarationNameExpr
parameter_list|(
name|CXXScopeSpec
modifier|&
name|SS
parameter_list|,
name|DeclarationName
name|Name
parameter_list|,
name|SourceLocation
name|NameLoc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|OwningExprResult
name|BuildDependentDeclRefExpr
parameter_list|(
specifier|const
name|CXXScopeSpec
modifier|&
name|SS
parameter_list|,
name|DeclarationName
name|Name
parameter_list|,
name|SourceLocation
name|NameLoc
parameter_list|,
specifier|const
name|TemplateArgumentListInfo
modifier|*
name|TemplateArgs
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|OwningExprResult
name|BuildDeclarationNameExpr
parameter_list|(
specifier|const
name|CXXScopeSpec
modifier|&
name|SS
parameter_list|,
name|LookupResult
modifier|&
name|R
parameter_list|,
name|bool
name|ADL
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|OwningExprResult
name|BuildDeclarationNameExpr
parameter_list|(
specifier|const
name|CXXScopeSpec
modifier|&
name|SS
parameter_list|,
name|SourceLocation
name|Loc
parameter_list|,
name|NamedDecl
modifier|*
name|D
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
name|virtual
name|OwningExprResult
name|ActOnPredefinedExpr
argument_list|(
name|SourceLocation
name|Loc
argument_list|,
name|tok
operator|::
name|TokenKind
name|Kind
argument_list|)
decl_stmt|;
end_decl_stmt

begin_function_decl
name|virtual
name|OwningExprResult
name|ActOnNumericConstant
parameter_list|(
specifier|const
name|Token
modifier|&
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|virtual
name|OwningExprResult
name|ActOnCharacterConstant
parameter_list|(
specifier|const
name|Token
modifier|&
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|virtual
name|OwningExprResult
name|ActOnParenExpr
parameter_list|(
name|SourceLocation
name|L
parameter_list|,
name|SourceLocation
name|R
parameter_list|,
name|ExprArg
name|Val
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|virtual
name|OwningExprResult
name|ActOnParenOrParenListExpr
parameter_list|(
name|SourceLocation
name|L
parameter_list|,
name|SourceLocation
name|R
parameter_list|,
name|MultiExprArg
name|Val
parameter_list|,
name|TypeTy
modifier|*
name|TypeOfCast
init|=
literal|0
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// ActOnStringLiteral - The specified tokens were lexed as pasted string
end_comment

begin_comment
comment|/// fragments (e.g. "foo" "bar" L"baz").
end_comment

begin_function_decl
name|virtual
name|OwningExprResult
name|ActOnStringLiteral
parameter_list|(
specifier|const
name|Token
modifier|*
name|Toks
parameter_list|,
name|unsigned
name|NumToks
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|// Binary/Unary Operators.  'Tok' is the token for the operator.
end_comment

begin_function_decl
name|OwningExprResult
name|CreateBuiltinUnaryOp
parameter_list|(
name|SourceLocation
name|OpLoc
parameter_list|,
name|unsigned
name|OpcIn
parameter_list|,
name|ExprArg
name|InputArg
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
name|OwningExprResult
name|BuildUnaryOp
argument_list|(
name|Scope
operator|*
name|S
argument_list|,
name|SourceLocation
name|OpLoc
argument_list|,
name|UnaryOperator
operator|::
name|Opcode
name|Opc
argument_list|,
name|ExprArg
name|input
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|virtual
name|OwningExprResult
name|ActOnUnaryOp
argument_list|(
name|Scope
operator|*
name|S
argument_list|,
name|SourceLocation
name|OpLoc
argument_list|,
name|tok
operator|::
name|TokenKind
name|Op
argument_list|,
name|ExprArg
name|Input
argument_list|)
decl_stmt|;
end_decl_stmt

begin_function_decl
name|OwningExprResult
name|CreateSizeOfAlignOfExpr
parameter_list|(
name|TypeSourceInfo
modifier|*
name|T
parameter_list|,
name|SourceLocation
name|OpLoc
parameter_list|,
name|bool
name|isSizeOf
parameter_list|,
name|SourceRange
name|R
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|OwningExprResult
name|CreateSizeOfAlignOfExpr
parameter_list|(
name|Expr
modifier|*
name|E
parameter_list|,
name|SourceLocation
name|OpLoc
parameter_list|,
name|bool
name|isSizeOf
parameter_list|,
name|SourceRange
name|R
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|virtual
name|OwningExprResult
name|ActOnSizeOfAlignOfExpr
parameter_list|(
name|SourceLocation
name|OpLoc
parameter_list|,
name|bool
name|isSizeof
parameter_list|,
name|bool
name|isType
parameter_list|,
name|void
modifier|*
name|TyOrEx
parameter_list|,
specifier|const
name|SourceRange
modifier|&
name|ArgRange
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|CheckAlignOfExpr
parameter_list|(
name|Expr
modifier|*
name|E
parameter_list|,
name|SourceLocation
name|OpLoc
parameter_list|,
specifier|const
name|SourceRange
modifier|&
name|R
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|CheckSizeOfAlignOfOperand
parameter_list|(
name|QualType
name|type
parameter_list|,
name|SourceLocation
name|OpLoc
parameter_list|,
specifier|const
name|SourceRange
modifier|&
name|R
parameter_list|,
name|bool
name|isSizeof
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
name|virtual
name|OwningExprResult
name|ActOnPostfixUnaryOp
argument_list|(
name|Scope
operator|*
name|S
argument_list|,
name|SourceLocation
name|OpLoc
argument_list|,
name|tok
operator|::
name|TokenKind
name|Kind
argument_list|,
name|ExprArg
name|Input
argument_list|)
decl_stmt|;
end_decl_stmt

begin_function_decl
name|virtual
name|OwningExprResult
name|ActOnArraySubscriptExpr
parameter_list|(
name|Scope
modifier|*
name|S
parameter_list|,
name|ExprArg
name|Base
parameter_list|,
name|SourceLocation
name|LLoc
parameter_list|,
name|ExprArg
name|Idx
parameter_list|,
name|SourceLocation
name|RLoc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|OwningExprResult
name|CreateBuiltinArraySubscriptExpr
parameter_list|(
name|ExprArg
name|Base
parameter_list|,
name|SourceLocation
name|LLoc
parameter_list|,
name|ExprArg
name|Idx
parameter_list|,
name|SourceLocation
name|RLoc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|OwningExprResult
name|BuildMemberReferenceExpr
parameter_list|(
name|ExprArg
name|Base
parameter_list|,
name|QualType
name|BaseType
parameter_list|,
name|SourceLocation
name|OpLoc
parameter_list|,
name|bool
name|IsArrow
parameter_list|,
name|CXXScopeSpec
modifier|&
name|SS
parameter_list|,
name|NamedDecl
modifier|*
name|FirstQualifierInScope
parameter_list|,
name|DeclarationName
name|Name
parameter_list|,
name|SourceLocation
name|NameLoc
parameter_list|,
specifier|const
name|TemplateArgumentListInfo
modifier|*
name|TemplateArgs
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|OwningExprResult
name|BuildMemberReferenceExpr
parameter_list|(
name|ExprArg
name|Base
parameter_list|,
name|QualType
name|BaseType
parameter_list|,
name|SourceLocation
name|OpLoc
parameter_list|,
name|bool
name|IsArrow
parameter_list|,
specifier|const
name|CXXScopeSpec
modifier|&
name|SS
parameter_list|,
name|NamedDecl
modifier|*
name|FirstQualifierInScope
parameter_list|,
name|LookupResult
modifier|&
name|R
parameter_list|,
specifier|const
name|TemplateArgumentListInfo
modifier|*
name|TemplateArgs
parameter_list|,
name|bool
name|SuppressQualifierCheck
init|=
name|false
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|OwningExprResult
name|LookupMemberExpr
parameter_list|(
name|LookupResult
modifier|&
name|R
parameter_list|,
name|Expr
modifier|*
modifier|&
name|Base
parameter_list|,
name|bool
modifier|&
name|IsArrow
parameter_list|,
name|SourceLocation
name|OpLoc
parameter_list|,
name|CXXScopeSpec
modifier|&
name|SS
parameter_list|,
name|DeclPtrTy
name|ObjCImpDecl
parameter_list|,
name|bool
name|HasTemplateArgs
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|CheckQualifiedMemberReference
parameter_list|(
name|Expr
modifier|*
name|BaseExpr
parameter_list|,
name|QualType
name|BaseType
parameter_list|,
specifier|const
name|CXXScopeSpec
modifier|&
name|SS
parameter_list|,
specifier|const
name|LookupResult
modifier|&
name|R
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|OwningExprResult
name|ActOnDependentMemberExpr
parameter_list|(
name|ExprArg
name|Base
parameter_list|,
name|QualType
name|BaseType
parameter_list|,
name|bool
name|IsArrow
parameter_list|,
name|SourceLocation
name|OpLoc
parameter_list|,
specifier|const
name|CXXScopeSpec
modifier|&
name|SS
parameter_list|,
name|NamedDecl
modifier|*
name|FirstQualifierInScope
parameter_list|,
name|DeclarationName
name|Name
parameter_list|,
name|SourceLocation
name|NameLoc
parameter_list|,
specifier|const
name|TemplateArgumentListInfo
modifier|*
name|TemplateArgs
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
name|virtual
name|OwningExprResult
name|ActOnMemberAccessExpr
argument_list|(
name|Scope
operator|*
name|S
argument_list|,
name|ExprArg
name|Base
argument_list|,
name|SourceLocation
name|OpLoc
argument_list|,
name|tok
operator|::
name|TokenKind
name|OpKind
argument_list|,
name|CXXScopeSpec
operator|&
name|SS
argument_list|,
name|UnqualifiedId
operator|&
name|Member
argument_list|,
name|DeclPtrTy
name|ObjCImpDecl
argument_list|,
name|bool
name|HasTrailingLParen
argument_list|)
decl_stmt|;
end_decl_stmt

begin_function_decl
name|virtual
name|void
name|ActOnDefaultCtorInitializers
parameter_list|(
name|DeclPtrTy
name|CDtorDecl
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|ConvertArgumentsForCall
parameter_list|(
name|CallExpr
modifier|*
name|Call
parameter_list|,
name|Expr
modifier|*
name|Fn
parameter_list|,
name|FunctionDecl
modifier|*
name|FDecl
parameter_list|,
specifier|const
name|FunctionProtoType
modifier|*
name|Proto
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
name|RParenLoc
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// ActOnCallExpr - Handle a call to Fn with the specified array of arguments.
end_comment

begin_comment
comment|/// This provides the location of the left/right parens and a list of comma
end_comment

begin_comment
comment|/// locations.
end_comment

begin_function_decl
name|virtual
name|OwningExprResult
name|ActOnCallExpr
parameter_list|(
name|Scope
modifier|*
name|S
parameter_list|,
name|ExprArg
name|Fn
parameter_list|,
name|SourceLocation
name|LParenLoc
parameter_list|,
name|MultiExprArg
name|Args
parameter_list|,
name|SourceLocation
modifier|*
name|CommaLocs
parameter_list|,
name|SourceLocation
name|RParenLoc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|OwningExprResult
name|BuildResolvedCallExpr
parameter_list|(
name|Expr
modifier|*
name|Fn
parameter_list|,
name|NamedDecl
modifier|*
name|NDecl
parameter_list|,
name|SourceLocation
name|LParenLoc
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
name|RParenLoc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|virtual
name|OwningExprResult
name|ActOnCastExpr
parameter_list|(
name|Scope
modifier|*
name|S
parameter_list|,
name|SourceLocation
name|LParenLoc
parameter_list|,
name|TypeTy
modifier|*
name|Ty
parameter_list|,
name|SourceLocation
name|RParenLoc
parameter_list|,
name|ExprArg
name|Op
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|OwningExprResult
name|BuildCStyleCastExpr
parameter_list|(
name|SourceLocation
name|LParenLoc
parameter_list|,
name|TypeSourceInfo
modifier|*
name|Ty
parameter_list|,
name|SourceLocation
name|RParenLoc
parameter_list|,
name|ExprArg
name|Op
parameter_list|)
function_decl|;
end_function_decl

begin_function
name|virtual
name|bool
name|TypeIsVectorType
parameter_list|(
name|TypeTy
modifier|*
name|Ty
parameter_list|)
block|{
return|return
name|GetTypeFromParser
argument_list|(
name|Ty
argument_list|)
operator|->
name|isVectorType
argument_list|()
return|;
block|}
end_function

begin_function_decl
name|OwningExprResult
name|MaybeConvertParenListExprToParenExpr
parameter_list|(
name|Scope
modifier|*
name|S
parameter_list|,
name|ExprArg
name|ME
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|OwningExprResult
name|ActOnCastOfParenListExpr
parameter_list|(
name|Scope
modifier|*
name|S
parameter_list|,
name|SourceLocation
name|LParenLoc
parameter_list|,
name|SourceLocation
name|RParenLoc
parameter_list|,
name|ExprArg
name|E
parameter_list|,
name|TypeSourceInfo
modifier|*
name|TInfo
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|virtual
name|OwningExprResult
name|ActOnCompoundLiteral
parameter_list|(
name|SourceLocation
name|LParenLoc
parameter_list|,
name|TypeTy
modifier|*
name|Ty
parameter_list|,
name|SourceLocation
name|RParenLoc
parameter_list|,
name|ExprArg
name|Op
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|OwningExprResult
name|BuildCompoundLiteralExpr
parameter_list|(
name|SourceLocation
name|LParenLoc
parameter_list|,
name|TypeSourceInfo
modifier|*
name|TInfo
parameter_list|,
name|SourceLocation
name|RParenLoc
parameter_list|,
name|ExprArg
name|InitExpr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|virtual
name|OwningExprResult
name|ActOnInitList
parameter_list|(
name|SourceLocation
name|LParenLoc
parameter_list|,
name|MultiExprArg
name|InitList
parameter_list|,
name|SourceLocation
name|RParenLoc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|virtual
name|OwningExprResult
name|ActOnDesignatedInitializer
parameter_list|(
name|Designation
modifier|&
name|Desig
parameter_list|,
name|SourceLocation
name|Loc
parameter_list|,
name|bool
name|GNUSyntax
parameter_list|,
name|OwningExprResult
name|Init
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
name|virtual
name|OwningExprResult
name|ActOnBinOp
argument_list|(
name|Scope
operator|*
name|S
argument_list|,
name|SourceLocation
name|TokLoc
argument_list|,
name|tok
operator|::
name|TokenKind
name|Kind
argument_list|,
name|ExprArg
name|LHS
argument_list|,
name|ExprArg
name|RHS
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|OwningExprResult
name|BuildBinOp
argument_list|(
name|Scope
operator|*
name|S
argument_list|,
name|SourceLocation
name|OpLoc
argument_list|,
name|BinaryOperator
operator|::
name|Opcode
name|Opc
argument_list|,
name|Expr
operator|*
name|lhs
argument_list|,
name|Expr
operator|*
name|rhs
argument_list|)
decl_stmt|;
end_decl_stmt

begin_function_decl
name|OwningExprResult
name|CreateBuiltinBinOp
parameter_list|(
name|SourceLocation
name|TokLoc
parameter_list|,
name|unsigned
name|Opc
parameter_list|,
name|Expr
modifier|*
name|lhs
parameter_list|,
name|Expr
modifier|*
name|rhs
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// ActOnConditionalOp - Parse a ?: operation.  Note that 'LHS' may be null
end_comment

begin_comment
comment|/// in the case of a the GNU conditional expr extension.
end_comment

begin_function_decl
name|virtual
name|OwningExprResult
name|ActOnConditionalOp
parameter_list|(
name|SourceLocation
name|QuestionLoc
parameter_list|,
name|SourceLocation
name|ColonLoc
parameter_list|,
name|ExprArg
name|Cond
parameter_list|,
name|ExprArg
name|LHS
parameter_list|,
name|ExprArg
name|RHS
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// ActOnAddrLabel - Parse the GNU address of label extension: "&&foo".
end_comment

begin_function_decl
name|virtual
name|OwningExprResult
name|ActOnAddrLabel
parameter_list|(
name|SourceLocation
name|OpLoc
parameter_list|,
name|SourceLocation
name|LabLoc
parameter_list|,
name|IdentifierInfo
modifier|*
name|LabelII
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|virtual
name|OwningExprResult
name|ActOnStmtExpr
parameter_list|(
name|SourceLocation
name|LPLoc
parameter_list|,
name|StmtArg
name|SubStmt
parameter_list|,
name|SourceLocation
name|RPLoc
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|// "({..})"
end_comment

begin_comment
comment|/// __builtin_offsetof(type, a.b[123][456].c)
end_comment

begin_function_decl
name|OwningExprResult
name|BuildBuiltinOffsetOf
parameter_list|(
name|SourceLocation
name|BuiltinLoc
parameter_list|,
name|TypeSourceInfo
modifier|*
name|TInfo
parameter_list|,
name|OffsetOfComponent
modifier|*
name|CompPtr
parameter_list|,
name|unsigned
name|NumComponents
parameter_list|,
name|SourceLocation
name|RParenLoc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|virtual
name|OwningExprResult
name|ActOnBuiltinOffsetOf
parameter_list|(
name|Scope
modifier|*
name|S
parameter_list|,
name|SourceLocation
name|BuiltinLoc
parameter_list|,
name|SourceLocation
name|TypeLoc
parameter_list|,
name|TypeTy
modifier|*
name|Arg1
parameter_list|,
name|OffsetOfComponent
modifier|*
name|CompPtr
parameter_list|,
name|unsigned
name|NumComponents
parameter_list|,
name|SourceLocation
name|RParenLoc
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|// __builtin_types_compatible_p(type1, type2)
end_comment

begin_function_decl
name|virtual
name|OwningExprResult
name|ActOnTypesCompatibleExpr
parameter_list|(
name|SourceLocation
name|BuiltinLoc
parameter_list|,
name|TypeTy
modifier|*
name|arg1
parameter_list|,
name|TypeTy
modifier|*
name|arg2
parameter_list|,
name|SourceLocation
name|RPLoc
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|// __builtin_choose_expr(constExpr, expr1, expr2)
end_comment

begin_function_decl
name|virtual
name|OwningExprResult
name|ActOnChooseExpr
parameter_list|(
name|SourceLocation
name|BuiltinLoc
parameter_list|,
name|ExprArg
name|cond
parameter_list|,
name|ExprArg
name|expr1
parameter_list|,
name|ExprArg
name|expr2
parameter_list|,
name|SourceLocation
name|RPLoc
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|// __builtin_va_arg(expr, type)
end_comment

begin_function_decl
name|virtual
name|OwningExprResult
name|ActOnVAArg
parameter_list|(
name|SourceLocation
name|BuiltinLoc
parameter_list|,
name|ExprArg
name|expr
parameter_list|,
name|TypeTy
modifier|*
name|type
parameter_list|,
name|SourceLocation
name|RPLoc
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|// __null
end_comment

begin_function_decl
name|virtual
name|OwningExprResult
name|ActOnGNUNullExpr
parameter_list|(
name|SourceLocation
name|TokenLoc
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|//===------------------------- "Block" Extension ------------------------===//
end_comment

begin_comment
comment|/// ActOnBlockStart - This callback is invoked when a block literal is
end_comment

begin_comment
comment|/// started.
end_comment

begin_function_decl
name|virtual
name|void
name|ActOnBlockStart
parameter_list|(
name|SourceLocation
name|CaretLoc
parameter_list|,
name|Scope
modifier|*
name|CurScope
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// ActOnBlockArguments - This callback allows processing of block arguments.
end_comment

begin_comment
comment|/// If there are no arguments, this is still invoked.
end_comment

begin_function_decl
name|virtual
name|void
name|ActOnBlockArguments
parameter_list|(
name|Declarator
modifier|&
name|ParamInfo
parameter_list|,
name|Scope
modifier|*
name|CurScope
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// ActOnBlockError - If there is an error parsing a block, this callback
end_comment

begin_comment
comment|/// is invoked to pop the information about the block from the action impl.
end_comment

begin_function_decl
name|virtual
name|void
name|ActOnBlockError
parameter_list|(
name|SourceLocation
name|CaretLoc
parameter_list|,
name|Scope
modifier|*
name|CurScope
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// ActOnBlockStmtExpr - This is called when the body of a block statement
end_comment

begin_comment
comment|/// literal was successfully completed.  ^(int x){...}
end_comment

begin_function_decl
name|virtual
name|OwningExprResult
name|ActOnBlockStmtExpr
parameter_list|(
name|SourceLocation
name|CaretLoc
parameter_list|,
name|StmtArg
name|Body
parameter_list|,
name|Scope
modifier|*
name|CurScope
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|//===---------------------------- C++ Features --------------------------===//
end_comment

begin_comment
comment|// Act on C++ namespaces
end_comment

begin_function_decl
name|virtual
name|DeclPtrTy
name|ActOnStartNamespaceDef
parameter_list|(
name|Scope
modifier|*
name|S
parameter_list|,
name|SourceLocation
name|IdentLoc
parameter_list|,
name|IdentifierInfo
modifier|*
name|Ident
parameter_list|,
name|SourceLocation
name|LBrace
parameter_list|,
name|AttributeList
modifier|*
name|AttrList
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|virtual
name|void
name|ActOnFinishNamespaceDef
parameter_list|(
name|DeclPtrTy
name|Dcl
parameter_list|,
name|SourceLocation
name|RBrace
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|NamespaceDecl
modifier|*
name|getStdNamespace
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|virtual
name|DeclPtrTy
name|ActOnUsingDirective
parameter_list|(
name|Scope
modifier|*
name|CurScope
parameter_list|,
name|SourceLocation
name|UsingLoc
parameter_list|,
name|SourceLocation
name|NamespcLoc
parameter_list|,
name|CXXScopeSpec
modifier|&
name|SS
parameter_list|,
name|SourceLocation
name|IdentLoc
parameter_list|,
name|IdentifierInfo
modifier|*
name|NamespcName
parameter_list|,
name|AttributeList
modifier|*
name|AttrList
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|PushUsingDirective
parameter_list|(
name|Scope
modifier|*
name|S
parameter_list|,
name|UsingDirectiveDecl
modifier|*
name|UDir
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|virtual
name|DeclPtrTy
name|ActOnNamespaceAliasDef
parameter_list|(
name|Scope
modifier|*
name|CurScope
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
name|CXXScopeSpec
modifier|&
name|SS
parameter_list|,
name|SourceLocation
name|IdentLoc
parameter_list|,
name|IdentifierInfo
modifier|*
name|Ident
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|HideUsingShadowDecl
parameter_list|(
name|Scope
modifier|*
name|S
parameter_list|,
name|UsingShadowDecl
modifier|*
name|Shadow
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|CheckUsingShadowDecl
parameter_list|(
name|UsingDecl
modifier|*
name|UD
parameter_list|,
name|NamedDecl
modifier|*
name|Target
parameter_list|,
specifier|const
name|LookupResult
modifier|&
name|PreviousDecls
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|UsingShadowDecl
modifier|*
name|BuildUsingShadowDecl
parameter_list|(
name|Scope
modifier|*
name|S
parameter_list|,
name|UsingDecl
modifier|*
name|UD
parameter_list|,
name|NamedDecl
modifier|*
name|Target
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|CheckUsingDeclRedeclaration
parameter_list|(
name|SourceLocation
name|UsingLoc
parameter_list|,
name|bool
name|isTypeName
parameter_list|,
specifier|const
name|CXXScopeSpec
modifier|&
name|SS
parameter_list|,
name|SourceLocation
name|NameLoc
parameter_list|,
specifier|const
name|LookupResult
modifier|&
name|Previous
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|CheckUsingDeclQualifier
parameter_list|(
name|SourceLocation
name|UsingLoc
parameter_list|,
specifier|const
name|CXXScopeSpec
modifier|&
name|SS
parameter_list|,
name|SourceLocation
name|NameLoc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|NamedDecl
modifier|*
name|BuildUsingDeclaration
parameter_list|(
name|Scope
modifier|*
name|S
parameter_list|,
name|AccessSpecifier
name|AS
parameter_list|,
name|SourceLocation
name|UsingLoc
parameter_list|,
name|CXXScopeSpec
modifier|&
name|SS
parameter_list|,
name|SourceLocation
name|IdentLoc
parameter_list|,
name|DeclarationName
name|Name
parameter_list|,
name|AttributeList
modifier|*
name|AttrList
parameter_list|,
name|bool
name|IsInstantiation
parameter_list|,
name|bool
name|IsTypeName
parameter_list|,
name|SourceLocation
name|TypenameLoc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|virtual
name|DeclPtrTy
name|ActOnUsingDeclaration
parameter_list|(
name|Scope
modifier|*
name|CurScope
parameter_list|,
name|AccessSpecifier
name|AS
parameter_list|,
name|bool
name|HasUsingKeyword
parameter_list|,
name|SourceLocation
name|UsingLoc
parameter_list|,
name|CXXScopeSpec
modifier|&
name|SS
parameter_list|,
name|UnqualifiedId
modifier|&
name|Name
parameter_list|,
name|AttributeList
modifier|*
name|AttrList
parameter_list|,
name|bool
name|IsTypeName
parameter_list|,
name|SourceLocation
name|TypenameLoc
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// AddCXXDirectInitializerToDecl - This action is called immediately after
end_comment

begin_comment
comment|/// ActOnDeclarator, when a C++ direct initializer is present.
end_comment

begin_comment
comment|/// e.g: "int x(1);"
end_comment

begin_function_decl
name|virtual
name|void
name|AddCXXDirectInitializerToDecl
parameter_list|(
name|DeclPtrTy
name|Dcl
parameter_list|,
name|SourceLocation
name|LParenLoc
parameter_list|,
name|MultiExprArg
name|Exprs
parameter_list|,
name|SourceLocation
modifier|*
name|CommaLocs
parameter_list|,
name|SourceLocation
name|RParenLoc
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// InitializeVarWithConstructor - Creates an CXXConstructExpr
end_comment

begin_comment
comment|/// and sets it as the initializer for the the passed in VarDecl.
end_comment

begin_function_decl
name|bool
name|InitializeVarWithConstructor
parameter_list|(
name|VarDecl
modifier|*
name|VD
parameter_list|,
name|CXXConstructorDecl
modifier|*
name|Constructor
parameter_list|,
name|MultiExprArg
name|Exprs
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// BuildCXXConstructExpr - Creates a complete call to a constructor,
end_comment

begin_comment
comment|/// including handling of its default argument expressions.
end_comment

begin_decl_stmt
name|OwningExprResult
name|BuildCXXConstructExpr
argument_list|(
name|SourceLocation
name|ConstructLoc
argument_list|,
name|QualType
name|DeclInitType
argument_list|,
name|CXXConstructorDecl
operator|*
name|Constructor
argument_list|,
name|MultiExprArg
name|Exprs
argument_list|,
name|bool
name|RequiresZeroInit
operator|=
name|false
argument_list|,
name|CXXConstructExpr
operator|::
name|ConstructionKind
name|ConstructKind
operator|=
name|CXXConstructExpr
operator|::
name|CK_Complete
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|// FIXME: Can re remove this and have the above BuildCXXConstructExpr check if
end_comment

begin_comment
comment|// the constructor can be elidable?
end_comment

begin_decl_stmt
name|OwningExprResult
name|BuildCXXConstructExpr
argument_list|(
name|SourceLocation
name|ConstructLoc
argument_list|,
name|QualType
name|DeclInitType
argument_list|,
name|CXXConstructorDecl
operator|*
name|Constructor
argument_list|,
name|bool
name|Elidable
argument_list|,
name|MultiExprArg
name|Exprs
argument_list|,
name|bool
name|RequiresZeroInit
operator|=
name|false
argument_list|,
name|CXXConstructExpr
operator|::
name|ConstructionKind
name|ConstructKind
operator|=
name|CXXConstructExpr
operator|::
name|CK_Complete
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// BuildCXXDefaultArgExpr - Creates a CXXDefaultArgExpr, instantiating
end_comment

begin_comment
comment|/// the default expr if needed.
end_comment

begin_function_decl
name|OwningExprResult
name|BuildCXXDefaultArgExpr
parameter_list|(
name|SourceLocation
name|CallLoc
parameter_list|,
name|FunctionDecl
modifier|*
name|FD
parameter_list|,
name|ParmVarDecl
modifier|*
name|Param
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// FinalizeVarWithDestructor - Prepare for calling destructor on the
end_comment

begin_comment
comment|/// constructed variable.
end_comment

begin_function_decl
name|void
name|FinalizeVarWithDestructor
parameter_list|(
name|VarDecl
modifier|*
name|VD
parameter_list|,
specifier|const
name|RecordType
modifier|*
name|DeclInitType
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// \brief Declare the implicit default constructor for the given class.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param ClassDecl The class declaration into which the implicit
end_comment

begin_comment
comment|/// default constructor will be added.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \returns The implicitly-declared default constructor.
end_comment

begin_function_decl
name|CXXConstructorDecl
modifier|*
name|DeclareImplicitDefaultConstructor
parameter_list|(
name|CXXRecordDecl
modifier|*
name|ClassDecl
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// DefineImplicitDefaultConstructor - Checks for feasibility of
end_comment

begin_comment
comment|/// defining this constructor as the default constructor.
end_comment

begin_function_decl
name|void
name|DefineImplicitDefaultConstructor
parameter_list|(
name|SourceLocation
name|CurrentLocation
parameter_list|,
name|CXXConstructorDecl
modifier|*
name|Constructor
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// \brief Declare the implicit destructor for the given class.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param ClassDecl The class declaration into which the implicit
end_comment

begin_comment
comment|/// destructor will be added.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \returns The implicitly-declared destructor.
end_comment

begin_function_decl
name|CXXDestructorDecl
modifier|*
name|DeclareImplicitDestructor
parameter_list|(
name|CXXRecordDecl
modifier|*
name|ClassDecl
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// DefineImplicitDestructor - Checks for feasibility of
end_comment

begin_comment
comment|/// defining this destructor as the default destructor.
end_comment

begin_function_decl
name|void
name|DefineImplicitDestructor
parameter_list|(
name|SourceLocation
name|CurrentLocation
parameter_list|,
name|CXXDestructorDecl
modifier|*
name|Destructor
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// \brief Declare the implicit copy constructor for the given class.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param S The scope of the class, which may be NULL if this is a
end_comment

begin_comment
comment|/// template instantiation.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param ClassDecl The class declaration into which the implicit
end_comment

begin_comment
comment|/// copy constructor will be added.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \returns The implicitly-declared copy constructor.
end_comment

begin_function_decl
name|CXXConstructorDecl
modifier|*
name|DeclareImplicitCopyConstructor
parameter_list|(
name|CXXRecordDecl
modifier|*
name|ClassDecl
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// DefineImplicitCopyConstructor - Checks for feasibility of
end_comment

begin_comment
comment|/// defining this constructor as the copy constructor.
end_comment

begin_function_decl
name|void
name|DefineImplicitCopyConstructor
parameter_list|(
name|SourceLocation
name|CurrentLocation
parameter_list|,
name|CXXConstructorDecl
modifier|*
name|Constructor
parameter_list|,
name|unsigned
name|TypeQuals
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// \brief Declare the implicit copy assignment operator for the given class.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param S The scope of the class, which may be NULL if this is a
end_comment

begin_comment
comment|/// template instantiation.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param ClassDecl The class declaration into which the implicit
end_comment

begin_comment
comment|/// copy-assignment operator will be added.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \returns The implicitly-declared copy assignment operator.
end_comment

begin_function_decl
name|CXXMethodDecl
modifier|*
name|DeclareImplicitCopyAssignment
parameter_list|(
name|CXXRecordDecl
modifier|*
name|ClassDecl
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// \brief Defined an implicitly-declared copy assignment operator.
end_comment

begin_function_decl
name|void
name|DefineImplicitCopyAssignment
parameter_list|(
name|SourceLocation
name|CurrentLocation
parameter_list|,
name|CXXMethodDecl
modifier|*
name|MethodDecl
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// \brief Force the declaration of any implicitly-declared members of this
end_comment

begin_comment
comment|/// class.
end_comment

begin_function_decl
name|void
name|ForceDeclarationOfImplicitMembers
parameter_list|(
name|CXXRecordDecl
modifier|*
name|Class
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// MaybeBindToTemporary - If the passed in expression has a record type with
end_comment

begin_comment
comment|/// a non-trivial destructor, this will return CXXBindTemporaryExpr. Otherwise
end_comment

begin_comment
comment|/// it simply returns the passed in expression.
end_comment

begin_function_decl
name|OwningExprResult
name|MaybeBindToTemporary
parameter_list|(
name|Expr
modifier|*
name|E
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
name|bool
name|CompleteConstructorCall
argument_list|(
name|CXXConstructorDecl
operator|*
name|Constructor
argument_list|,
name|MultiExprArg
name|ArgsPtr
argument_list|,
name|SourceLocation
name|Loc
argument_list|,
name|ASTOwningVector
operator|<
operator|&
name|ActionBase
operator|::
name|DeleteExpr
operator|>
operator|&
name|ConvertedArgs
argument_list|)
decl_stmt|;
end_decl_stmt

begin_function_decl
name|virtual
name|TypeTy
modifier|*
name|getDestructorName
parameter_list|(
name|SourceLocation
name|TildeLoc
parameter_list|,
name|IdentifierInfo
modifier|&
name|II
parameter_list|,
name|SourceLocation
name|NameLoc
parameter_list|,
name|Scope
modifier|*
name|S
parameter_list|,
name|CXXScopeSpec
modifier|&
name|SS
parameter_list|,
name|TypeTy
modifier|*
name|ObjectType
parameter_list|,
name|bool
name|EnteringContext
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// ActOnCXXNamedCast - Parse {dynamic,static,reinterpret,const}_cast's.
end_comment

begin_decl_stmt
name|virtual
name|OwningExprResult
name|ActOnCXXNamedCast
argument_list|(
name|SourceLocation
name|OpLoc
argument_list|,
name|tok
operator|::
name|TokenKind
name|Kind
argument_list|,
name|SourceLocation
name|LAngleBracketLoc
argument_list|,
name|TypeTy
operator|*
name|Ty
argument_list|,
name|SourceLocation
name|RAngleBracketLoc
argument_list|,
name|SourceLocation
name|LParenLoc
argument_list|,
name|ExprArg
name|E
argument_list|,
name|SourceLocation
name|RParenLoc
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|OwningExprResult
name|BuildCXXNamedCast
argument_list|(
name|SourceLocation
name|OpLoc
argument_list|,
name|tok
operator|::
name|TokenKind
name|Kind
argument_list|,
name|TypeSourceInfo
operator|*
name|Ty
argument_list|,
name|ExprArg
name|E
argument_list|,
name|SourceRange
name|AngleBrackets
argument_list|,
name|SourceRange
name|Parens
argument_list|)
decl_stmt|;
end_decl_stmt

begin_function_decl
name|OwningExprResult
name|BuildCXXTypeId
parameter_list|(
name|QualType
name|TypeInfoType
parameter_list|,
name|SourceLocation
name|TypeidLoc
parameter_list|,
name|TypeSourceInfo
modifier|*
name|Operand
parameter_list|,
name|SourceLocation
name|RParenLoc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|OwningExprResult
name|BuildCXXTypeId
parameter_list|(
name|QualType
name|TypeInfoType
parameter_list|,
name|SourceLocation
name|TypeidLoc
parameter_list|,
name|ExprArg
name|Operand
parameter_list|,
name|SourceLocation
name|RParenLoc
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// ActOnCXXTypeid - Parse typeid( something ).
end_comment

begin_function_decl
name|virtual
name|OwningExprResult
name|ActOnCXXTypeid
parameter_list|(
name|SourceLocation
name|OpLoc
parameter_list|,
name|SourceLocation
name|LParenLoc
parameter_list|,
name|bool
name|isType
parameter_list|,
name|void
modifier|*
name|TyOrExpr
parameter_list|,
name|SourceLocation
name|RParenLoc
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|//// ActOnCXXThis -  Parse 'this' pointer.
end_comment

begin_function_decl
name|virtual
name|OwningExprResult
name|ActOnCXXThis
parameter_list|(
name|SourceLocation
name|ThisLoc
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// ActOnCXXBoolLiteral - Parse {true,false} literals.
end_comment

begin_decl_stmt
name|virtual
name|OwningExprResult
name|ActOnCXXBoolLiteral
argument_list|(
name|SourceLocation
name|OpLoc
argument_list|,
name|tok
operator|::
name|TokenKind
name|Kind
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// ActOnCXXNullPtrLiteral - Parse 'nullptr'.
end_comment

begin_function_decl
name|virtual
name|OwningExprResult
name|ActOnCXXNullPtrLiteral
parameter_list|(
name|SourceLocation
name|Loc
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|//// ActOnCXXThrow -  Parse throw expressions.
end_comment

begin_function_decl
name|virtual
name|OwningExprResult
name|ActOnCXXThrow
parameter_list|(
name|SourceLocation
name|OpLoc
parameter_list|,
name|ExprArg
name|expr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|CheckCXXThrowOperand
parameter_list|(
name|SourceLocation
name|ThrowLoc
parameter_list|,
name|Expr
modifier|*
modifier|&
name|E
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// ActOnCXXTypeConstructExpr - Parse construction of a specified type.
end_comment

begin_comment
comment|/// Can be interpreted either as function-style casting ("int(x)")
end_comment

begin_comment
comment|/// or class type construction ("ClassType(x,y,z)")
end_comment

begin_comment
comment|/// or creation of a value-initialized type ("int()").
end_comment

begin_function_decl
name|virtual
name|OwningExprResult
name|ActOnCXXTypeConstructExpr
parameter_list|(
name|SourceRange
name|TypeRange
parameter_list|,
name|TypeTy
modifier|*
name|TypeRep
parameter_list|,
name|SourceLocation
name|LParenLoc
parameter_list|,
name|MultiExprArg
name|Exprs
parameter_list|,
name|SourceLocation
modifier|*
name|CommaLocs
parameter_list|,
name|SourceLocation
name|RParenLoc
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// ActOnCXXNew - Parsed a C++ 'new' expression.
end_comment

begin_function_decl
name|virtual
name|OwningExprResult
name|ActOnCXXNew
parameter_list|(
name|SourceLocation
name|StartLoc
parameter_list|,
name|bool
name|UseGlobal
parameter_list|,
name|SourceLocation
name|PlacementLParen
parameter_list|,
name|MultiExprArg
name|PlacementArgs
parameter_list|,
name|SourceLocation
name|PlacementRParen
parameter_list|,
name|SourceRange
name|TypeIdParens
parameter_list|,
name|Declarator
modifier|&
name|D
parameter_list|,
name|SourceLocation
name|ConstructorLParen
parameter_list|,
name|MultiExprArg
name|ConstructorArgs
parameter_list|,
name|SourceLocation
name|ConstructorRParen
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|OwningExprResult
name|BuildCXXNew
parameter_list|(
name|SourceLocation
name|StartLoc
parameter_list|,
name|bool
name|UseGlobal
parameter_list|,
name|SourceLocation
name|PlacementLParen
parameter_list|,
name|MultiExprArg
name|PlacementArgs
parameter_list|,
name|SourceLocation
name|PlacementRParen
parameter_list|,
name|SourceRange
name|TypeIdParens
parameter_list|,
name|QualType
name|AllocType
parameter_list|,
name|SourceLocation
name|TypeLoc
parameter_list|,
name|SourceRange
name|TypeRange
parameter_list|,
name|ExprArg
name|ArraySize
parameter_list|,
name|SourceLocation
name|ConstructorLParen
parameter_list|,
name|MultiExprArg
name|ConstructorArgs
parameter_list|,
name|SourceLocation
name|ConstructorRParen
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|CheckAllocatedType
parameter_list|(
name|QualType
name|AllocType
parameter_list|,
name|SourceLocation
name|Loc
parameter_list|,
name|SourceRange
name|R
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|FindAllocationFunctions
parameter_list|(
name|SourceLocation
name|StartLoc
parameter_list|,
name|SourceRange
name|Range
parameter_list|,
name|bool
name|UseGlobal
parameter_list|,
name|QualType
name|AllocType
parameter_list|,
name|bool
name|IsArray
parameter_list|,
name|Expr
modifier|*
modifier|*
name|PlaceArgs
parameter_list|,
name|unsigned
name|NumPlaceArgs
parameter_list|,
name|FunctionDecl
modifier|*
modifier|&
name|OperatorNew
parameter_list|,
name|FunctionDecl
modifier|*
modifier|&
name|OperatorDelete
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|FindAllocationOverload
parameter_list|(
name|SourceLocation
name|StartLoc
parameter_list|,
name|SourceRange
name|Range
parameter_list|,
name|DeclarationName
name|Name
parameter_list|,
name|Expr
modifier|*
modifier|*
name|Args
parameter_list|,
name|unsigned
name|NumArgs
parameter_list|,
name|DeclContext
modifier|*
name|Ctx
parameter_list|,
name|bool
name|AllowMissing
parameter_list|,
name|FunctionDecl
modifier|*
modifier|&
name|Operator
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|DeclareGlobalNewDelete
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|DeclareGlobalAllocationFunction
parameter_list|(
name|DeclarationName
name|Name
parameter_list|,
name|QualType
name|Return
parameter_list|,
name|QualType
name|Argument
parameter_list|,
name|bool
name|addMallocAttr
init|=
name|false
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|FindDeallocationFunction
parameter_list|(
name|SourceLocation
name|StartLoc
parameter_list|,
name|CXXRecordDecl
modifier|*
name|RD
parameter_list|,
name|DeclarationName
name|Name
parameter_list|,
name|FunctionDecl
modifier|*
modifier|&
name|Operator
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// ActOnCXXDelete - Parsed a C++ 'delete' expression
end_comment

begin_function_decl
name|virtual
name|OwningExprResult
name|ActOnCXXDelete
parameter_list|(
name|SourceLocation
name|StartLoc
parameter_list|,
name|bool
name|UseGlobal
parameter_list|,
name|bool
name|ArrayForm
parameter_list|,
name|ExprArg
name|Operand
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|virtual
name|DeclResult
name|ActOnCXXConditionDeclaration
parameter_list|(
name|Scope
modifier|*
name|S
parameter_list|,
name|Declarator
modifier|&
name|D
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|OwningExprResult
name|CheckConditionVariable
parameter_list|(
name|VarDecl
modifier|*
name|ConditionVar
parameter_list|,
name|SourceLocation
name|StmtLoc
parameter_list|,
name|bool
name|ConvertToBoolean
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// ActOnUnaryTypeTrait - Parsed one of the unary type trait support
end_comment

begin_comment
comment|/// pseudo-functions.
end_comment

begin_function_decl
name|virtual
name|OwningExprResult
name|ActOnUnaryTypeTrait
parameter_list|(
name|UnaryTypeTrait
name|OTT
parameter_list|,
name|SourceLocation
name|KWLoc
parameter_list|,
name|SourceLocation
name|LParen
parameter_list|,
name|TypeTy
modifier|*
name|Ty
parameter_list|,
name|SourceLocation
name|RParen
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
name|virtual
name|OwningExprResult
name|ActOnStartCXXMemberReference
argument_list|(
name|Scope
operator|*
name|S
argument_list|,
name|ExprArg
name|Base
argument_list|,
name|SourceLocation
name|OpLoc
argument_list|,
name|tok
operator|::
name|TokenKind
name|OpKind
argument_list|,
name|TypeTy
operator|*
operator|&
name|ObjectType
argument_list|,
name|bool
operator|&
name|MayBePseudoDestructor
argument_list|)
decl_stmt|;
end_decl_stmt

begin_function_decl
name|OwningExprResult
name|DiagnoseDtorReference
parameter_list|(
name|SourceLocation
name|NameLoc
parameter_list|,
name|ExprArg
name|MemExpr
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
name|OwningExprResult
name|BuildPseudoDestructorExpr
argument_list|(
name|ExprArg
name|Base
argument_list|,
name|SourceLocation
name|OpLoc
argument_list|,
name|tok
operator|::
name|TokenKind
name|OpKind
argument_list|,
specifier|const
name|CXXScopeSpec
operator|&
name|SS
argument_list|,
name|TypeSourceInfo
operator|*
name|ScopeType
argument_list|,
name|SourceLocation
name|CCLoc
argument_list|,
name|SourceLocation
name|TildeLoc
argument_list|,
name|PseudoDestructorTypeStorage
name|DestroyedType
argument_list|,
name|bool
name|HasTrailingLParen
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|virtual
name|OwningExprResult
name|ActOnPseudoDestructorExpr
argument_list|(
name|Scope
operator|*
name|S
argument_list|,
name|ExprArg
name|Base
argument_list|,
name|SourceLocation
name|OpLoc
argument_list|,
name|tok
operator|::
name|TokenKind
name|OpKind
argument_list|,
name|CXXScopeSpec
operator|&
name|SS
argument_list|,
name|UnqualifiedId
operator|&
name|FirstTypeName
argument_list|,
name|SourceLocation
name|CCLoc
argument_list|,
name|SourceLocation
name|TildeLoc
argument_list|,
name|UnqualifiedId
operator|&
name|SecondTypeName
argument_list|,
name|bool
name|HasTrailingLParen
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// MaybeCreateCXXExprWithTemporaries - If the list of temporaries is
end_comment

begin_comment
comment|/// non-empty, will create a new CXXExprWithTemporaries expression.
end_comment

begin_comment
comment|/// Otherwise, just returs the passed in expression.
end_comment

begin_function_decl
name|Expr
modifier|*
name|MaybeCreateCXXExprWithTemporaries
parameter_list|(
name|Expr
modifier|*
name|SubExpr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|OwningExprResult
name|MaybeCreateCXXExprWithTemporaries
parameter_list|(
name|OwningExprResult
name|SubExpr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|FullExpr
name|CreateFullExpr
parameter_list|(
name|Expr
modifier|*
name|SubExpr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|virtual
name|OwningExprResult
name|ActOnFinishFullExpr
parameter_list|(
name|ExprArg
name|Expr
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|// Marks SS invalid if it represents an incomplete type.
end_comment

begin_function_decl
name|bool
name|RequireCompleteDeclContext
parameter_list|(
name|CXXScopeSpec
modifier|&
name|SS
parameter_list|,
name|DeclContext
modifier|*
name|DC
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|DeclContext
modifier|*
name|computeDeclContext
parameter_list|(
name|QualType
name|T
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|DeclContext
modifier|*
name|computeDeclContext
parameter_list|(
specifier|const
name|CXXScopeSpec
modifier|&
name|SS
parameter_list|,
name|bool
name|EnteringContext
init|=
name|false
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|isDependentScopeSpecifier
parameter_list|(
specifier|const
name|CXXScopeSpec
modifier|&
name|SS
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|CXXRecordDecl
modifier|*
name|getCurrentInstantiationOf
parameter_list|(
name|NestedNameSpecifier
modifier|*
name|NNS
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|isUnknownSpecialization
parameter_list|(
specifier|const
name|CXXScopeSpec
modifier|&
name|SS
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// ActOnCXXGlobalScopeSpecifier - Return the object that represents the
end_comment

begin_comment
comment|/// global scope ('::').
end_comment

begin_function_decl
name|virtual
name|CXXScopeTy
modifier|*
name|ActOnCXXGlobalScopeSpecifier
parameter_list|(
name|Scope
modifier|*
name|S
parameter_list|,
name|SourceLocation
name|CCLoc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|isAcceptableNestedNameSpecifier
parameter_list|(
name|NamedDecl
modifier|*
name|SD
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|NamedDecl
modifier|*
name|FindFirstQualifierInScope
parameter_list|(
name|Scope
modifier|*
name|S
parameter_list|,
name|NestedNameSpecifier
modifier|*
name|NNS
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|virtual
name|bool
name|isNonTypeNestedNameSpecifier
parameter_list|(
name|Scope
modifier|*
name|S
parameter_list|,
name|CXXScopeSpec
modifier|&
name|SS
parameter_list|,
name|SourceLocation
name|IdLoc
parameter_list|,
name|IdentifierInfo
modifier|&
name|II
parameter_list|,
name|TypeTy
modifier|*
name|ObjectType
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|CXXScopeTy
modifier|*
name|BuildCXXNestedNameSpecifier
parameter_list|(
name|Scope
modifier|*
name|S
parameter_list|,
name|CXXScopeSpec
modifier|&
name|SS
parameter_list|,
name|SourceLocation
name|IdLoc
parameter_list|,
name|SourceLocation
name|CCLoc
parameter_list|,
name|IdentifierInfo
modifier|&
name|II
parameter_list|,
name|QualType
name|ObjectType
parameter_list|,
name|NamedDecl
modifier|*
name|ScopeLookupResult
parameter_list|,
name|bool
name|EnteringContext
parameter_list|,
name|bool
name|ErrorRecoveryLookup
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|virtual
name|CXXScopeTy
modifier|*
name|ActOnCXXNestedNameSpecifier
parameter_list|(
name|Scope
modifier|*
name|S
parameter_list|,
name|CXXScopeSpec
modifier|&
name|SS
parameter_list|,
name|SourceLocation
name|IdLoc
parameter_list|,
name|SourceLocation
name|CCLoc
parameter_list|,
name|IdentifierInfo
modifier|&
name|II
parameter_list|,
name|TypeTy
modifier|*
name|ObjectType
parameter_list|,
name|bool
name|EnteringContext
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|virtual
name|bool
name|IsInvalidUnlessNestedName
parameter_list|(
name|Scope
modifier|*
name|S
parameter_list|,
name|CXXScopeSpec
modifier|&
name|SS
parameter_list|,
name|IdentifierInfo
modifier|&
name|II
parameter_list|,
name|TypeTy
modifier|*
name|ObjectType
parameter_list|,
name|bool
name|EnteringContext
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// ActOnCXXNestedNameSpecifier - Called during parsing of a
end_comment

begin_comment
comment|/// nested-name-specifier that involves a template-id, e.g.,
end_comment

begin_comment
comment|/// "foo::bar<int, float>::", and now we need to build a scope
end_comment

begin_comment
comment|/// specifier. \p SS is empty or the previously parsed nested-name
end_comment

begin_comment
comment|/// part ("foo::"), \p Type is the already-parsed class template
end_comment

begin_comment
comment|/// specialization (or other template-id that names a type), \p
end_comment

begin_comment
comment|/// TypeRange is the source range where the type is located, and \p
end_comment

begin_comment
comment|/// CCLoc is the location of the trailing '::'.
end_comment

begin_function_decl
name|virtual
name|CXXScopeTy
modifier|*
name|ActOnCXXNestedNameSpecifier
parameter_list|(
name|Scope
modifier|*
name|S
parameter_list|,
specifier|const
name|CXXScopeSpec
modifier|&
name|SS
parameter_list|,
name|TypeTy
modifier|*
name|Type
parameter_list|,
name|SourceRange
name|TypeRange
parameter_list|,
name|SourceLocation
name|CCLoc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|virtual
name|bool
name|ShouldEnterDeclaratorScope
parameter_list|(
name|Scope
modifier|*
name|S
parameter_list|,
specifier|const
name|CXXScopeSpec
modifier|&
name|SS
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// ActOnCXXEnterDeclaratorScope - Called when a C++ scope specifier (global
end_comment

begin_comment
comment|/// scope or nested-name-specifier) is parsed, part of a declarator-id.
end_comment

begin_comment
comment|/// After this method is called, according to [C++ 3.4.3p3], names should be
end_comment

begin_comment
comment|/// looked up in the declarator-id's scope, until the declarator is parsed and
end_comment

begin_comment
comment|/// ActOnCXXExitDeclaratorScope is called.
end_comment

begin_comment
comment|/// The 'SS' should be a non-empty valid CXXScopeSpec.
end_comment

begin_function_decl
name|virtual
name|bool
name|ActOnCXXEnterDeclaratorScope
parameter_list|(
name|Scope
modifier|*
name|S
parameter_list|,
name|CXXScopeSpec
modifier|&
name|SS
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// ActOnCXXExitDeclaratorScope - Called when a declarator that previously
end_comment

begin_comment
comment|/// invoked ActOnCXXEnterDeclaratorScope(), is finished. 'SS' is the same
end_comment

begin_comment
comment|/// CXXScopeSpec that was passed to ActOnCXXEnterDeclaratorScope as well.
end_comment

begin_comment
comment|/// Used to indicate that names should revert to being looked up in the
end_comment

begin_comment
comment|/// defining scope.
end_comment

begin_function_decl
name|virtual
name|void
name|ActOnCXXExitDeclaratorScope
parameter_list|(
name|Scope
modifier|*
name|S
parameter_list|,
specifier|const
name|CXXScopeSpec
modifier|&
name|SS
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// ActOnCXXEnterDeclInitializer - Invoked when we are about to parse an
end_comment

begin_comment
comment|/// initializer for the declaration 'Dcl'.
end_comment

begin_comment
comment|/// After this method is called, according to [C++ 3.4.1p13], if 'Dcl' is a
end_comment

begin_comment
comment|/// static data member of class X, names should be looked up in the scope of
end_comment

begin_comment
comment|/// class X.
end_comment

begin_function_decl
name|virtual
name|void
name|ActOnCXXEnterDeclInitializer
parameter_list|(
name|Scope
modifier|*
name|S
parameter_list|,
name|DeclPtrTy
name|Dcl
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// ActOnCXXExitDeclInitializer - Invoked after we are finished parsing an
end_comment

begin_comment
comment|/// initializer for the declaration 'Dcl'.
end_comment

begin_function_decl
name|virtual
name|void
name|ActOnCXXExitDeclInitializer
parameter_list|(
name|Scope
modifier|*
name|S
parameter_list|,
name|DeclPtrTy
name|Dcl
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|// ParseObjCStringLiteral - Parse Objective-C string literals.
end_comment

begin_function_decl
name|virtual
name|ExprResult
name|ParseObjCStringLiteral
parameter_list|(
name|SourceLocation
modifier|*
name|AtLocs
parameter_list|,
name|ExprTy
modifier|*
modifier|*
name|Strings
parameter_list|,
name|unsigned
name|NumStrings
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|Expr
modifier|*
name|BuildObjCEncodeExpression
parameter_list|(
name|SourceLocation
name|AtLoc
parameter_list|,
name|TypeSourceInfo
modifier|*
name|EncodedTypeInfo
parameter_list|,
name|SourceLocation
name|RParenLoc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|CXXMemberCallExpr
modifier|*
name|BuildCXXMemberCallExpr
parameter_list|(
name|Expr
modifier|*
name|Exp
parameter_list|,
name|NamedDecl
modifier|*
name|FoundDecl
parameter_list|,
name|CXXMethodDecl
modifier|*
name|Method
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|virtual
name|ExprResult
name|ParseObjCEncodeExpression
parameter_list|(
name|SourceLocation
name|AtLoc
parameter_list|,
name|SourceLocation
name|EncodeLoc
parameter_list|,
name|SourceLocation
name|LParenLoc
parameter_list|,
name|TypeTy
modifier|*
name|Ty
parameter_list|,
name|SourceLocation
name|RParenLoc
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|// ParseObjCSelectorExpression - Build selector expression for @selector
end_comment

begin_function_decl
name|virtual
name|ExprResult
name|ParseObjCSelectorExpression
parameter_list|(
name|Selector
name|Sel
parameter_list|,
name|SourceLocation
name|AtLoc
parameter_list|,
name|SourceLocation
name|SelLoc
parameter_list|,
name|SourceLocation
name|LParenLoc
parameter_list|,
name|SourceLocation
name|RParenLoc
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|// ParseObjCProtocolExpression - Build protocol expression for @protocol
end_comment

begin_function_decl
name|virtual
name|ExprResult
name|ParseObjCProtocolExpression
parameter_list|(
name|IdentifierInfo
modifier|*
name|ProtocolName
parameter_list|,
name|SourceLocation
name|AtLoc
parameter_list|,
name|SourceLocation
name|ProtoLoc
parameter_list|,
name|SourceLocation
name|LParenLoc
parameter_list|,
name|SourceLocation
name|RParenLoc
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|//===--------------------------------------------------------------------===//
end_comment

begin_comment
comment|// C++ Declarations
end_comment

begin_comment
comment|//
end_comment

begin_decl_stmt
name|virtual
name|DeclPtrTy
name|ActOnStartLinkageSpecification
argument_list|(
name|Scope
operator|*
name|S
argument_list|,
name|SourceLocation
name|ExternLoc
argument_list|,
name|SourceLocation
name|LangLoc
argument_list|,
name|llvm
operator|::
name|StringRef
name|Lang
argument_list|,
name|SourceLocation
name|LBraceLoc
argument_list|)
decl_stmt|;
end_decl_stmt

begin_function_decl
name|virtual
name|DeclPtrTy
name|ActOnFinishLinkageSpecification
parameter_list|(
name|Scope
modifier|*
name|S
parameter_list|,
name|DeclPtrTy
name|LinkageSpec
parameter_list|,
name|SourceLocation
name|RBraceLoc
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|//===--------------------------------------------------------------------===//
end_comment

begin_comment
comment|// C++ Classes
end_comment

begin_comment
comment|//
end_comment

begin_function_decl
name|virtual
name|bool
name|isCurrentClassName
parameter_list|(
specifier|const
name|IdentifierInfo
modifier|&
name|II
parameter_list|,
name|Scope
modifier|*
name|S
parameter_list|,
specifier|const
name|CXXScopeSpec
modifier|*
name|SS
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|virtual
name|DeclPtrTy
name|ActOnAccessSpecifier
parameter_list|(
name|AccessSpecifier
name|Access
parameter_list|,
name|SourceLocation
name|ASLoc
parameter_list|,
name|SourceLocation
name|ColonLoc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|virtual
name|DeclPtrTy
name|ActOnCXXMemberDeclarator
parameter_list|(
name|Scope
modifier|*
name|S
parameter_list|,
name|AccessSpecifier
name|AS
parameter_list|,
name|Declarator
modifier|&
name|D
parameter_list|,
name|MultiTemplateParamsArg
name|TemplateParameterLists
parameter_list|,
name|ExprTy
modifier|*
name|BitfieldWidth
parameter_list|,
name|ExprTy
modifier|*
name|Init
parameter_list|,
name|bool
name|IsDefinition
parameter_list|,
name|bool
name|Deleted
init|=
name|false
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|virtual
name|MemInitResult
name|ActOnMemInitializer
parameter_list|(
name|DeclPtrTy
name|ConstructorD
parameter_list|,
name|Scope
modifier|*
name|S
parameter_list|,
name|CXXScopeSpec
modifier|&
name|SS
parameter_list|,
name|IdentifierInfo
modifier|*
name|MemberOrBase
parameter_list|,
name|TypeTy
modifier|*
name|TemplateTypeTy
parameter_list|,
name|SourceLocation
name|IdLoc
parameter_list|,
name|SourceLocation
name|LParenLoc
parameter_list|,
name|ExprTy
modifier|*
modifier|*
name|Args
parameter_list|,
name|unsigned
name|NumArgs
parameter_list|,
name|SourceLocation
modifier|*
name|CommaLocs
parameter_list|,
name|SourceLocation
name|RParenLoc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|MemInitResult
name|BuildMemberInitializer
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
parameter_list|,
name|SourceLocation
name|IdLoc
parameter_list|,
name|SourceLocation
name|LParenLoc
parameter_list|,
name|SourceLocation
name|RParenLoc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|MemInitResult
name|BuildBaseInitializer
parameter_list|(
name|QualType
name|BaseType
parameter_list|,
name|TypeSourceInfo
modifier|*
name|BaseTInfo
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
name|LParenLoc
parameter_list|,
name|SourceLocation
name|RParenLoc
parameter_list|,
name|CXXRecordDecl
modifier|*
name|ClassDecl
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|SetBaseOrMemberInitializers
parameter_list|(
name|CXXConstructorDecl
modifier|*
name|Constructor
parameter_list|,
name|CXXBaseOrMemberInitializer
modifier|*
modifier|*
name|Initializers
parameter_list|,
name|unsigned
name|NumInitializers
parameter_list|,
name|bool
name|AnyErrors
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|SetIvarInitializers
parameter_list|(
name|ObjCImplementationDecl
modifier|*
name|ObjCImplementation
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// MarkBaseAndMemberDestructorsReferenced - Given a record decl,
end_comment

begin_comment
comment|/// mark all the non-trivial destructors of its members and bases as
end_comment

begin_comment
comment|/// referenced.
end_comment

begin_function_decl
name|void
name|MarkBaseAndMemberDestructorsReferenced
parameter_list|(
name|SourceLocation
name|Loc
parameter_list|,
name|CXXRecordDecl
modifier|*
name|Record
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// \brief The list of classes whose vtables have been used within
end_comment

begin_comment
comment|/// this translation unit, and the source locations at which the
end_comment

begin_comment
comment|/// first use occurred.
end_comment

begin_expr_stmt
name|llvm
operator|::
name|SmallVector
operator|<
name|std
operator|::
name|pair
operator|<
name|CXXRecordDecl
operator|*
operator|,
name|SourceLocation
operator|>
operator|,
literal|16
operator|>
name|VTableUses
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// \brief The set of classes whose vtables have been used within
end_comment

begin_comment
comment|/// this translation unit, and a bit that will be true if the vtable is
end_comment

begin_comment
comment|/// required to be emitted (otherwise, it should be emitted only if needed
end_comment

begin_comment
comment|/// by code generation).
end_comment

begin_expr_stmt
name|llvm
operator|::
name|DenseMap
operator|<
name|CXXRecordDecl
operator|*
operator|,
name|bool
operator|>
name|VTablesUsed
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// \brief A list of all of the dynamic classes in this translation
end_comment

begin_comment
comment|/// unit.
end_comment

begin_expr_stmt
name|llvm
operator|::
name|SmallVector
operator|<
name|CXXRecordDecl
operator|*
operator|,
literal|16
operator|>
name|DynamicClasses
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// \brief Note that the vtable for the given class was used at the
end_comment

begin_comment
comment|/// given location.
end_comment

begin_function_decl
name|void
name|MarkVTableUsed
parameter_list|(
name|SourceLocation
name|Loc
parameter_list|,
name|CXXRecordDecl
modifier|*
name|Class
parameter_list|,
name|bool
name|DefinitionRequired
init|=
name|false
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// MarkVirtualMembersReferenced - Will mark all virtual members of the given
end_comment

begin_comment
comment|/// CXXRecordDecl referenced.
end_comment

begin_function_decl
name|void
name|MarkVirtualMembersReferenced
parameter_list|(
name|SourceLocation
name|Loc
parameter_list|,
specifier|const
name|CXXRecordDecl
modifier|*
name|RD
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// \brief Define all of the vtables that have been used in this
end_comment

begin_comment
comment|/// translation unit and reference any virtual members used by those
end_comment

begin_comment
comment|/// vtables.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \returns true if any work was done, false otherwise.
end_comment

begin_function_decl
name|bool
name|DefineUsedVTables
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|AddImplicitlyDeclaredMembersToClass
parameter_list|(
name|CXXRecordDecl
modifier|*
name|ClassDecl
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|virtual
name|void
name|ActOnMemInitializers
parameter_list|(
name|DeclPtrTy
name|ConstructorDecl
parameter_list|,
name|SourceLocation
name|ColonLoc
parameter_list|,
name|MemInitTy
modifier|*
modifier|*
name|MemInits
parameter_list|,
name|unsigned
name|NumMemInits
parameter_list|,
name|bool
name|AnyErrors
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|CheckCompletedCXXClass
parameter_list|(
name|CXXRecordDecl
modifier|*
name|Record
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|virtual
name|void
name|ActOnFinishCXXMemberSpecification
parameter_list|(
name|Scope
modifier|*
name|S
parameter_list|,
name|SourceLocation
name|RLoc
parameter_list|,
name|DeclPtrTy
name|TagDecl
parameter_list|,
name|SourceLocation
name|LBrac
parameter_list|,
name|SourceLocation
name|RBrac
parameter_list|,
name|AttributeList
modifier|*
name|AttrList
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|virtual
name|void
name|ActOnReenterTemplateScope
parameter_list|(
name|Scope
modifier|*
name|S
parameter_list|,
name|DeclPtrTy
name|Template
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|virtual
name|void
name|ActOnStartDelayedMemberDeclarations
parameter_list|(
name|Scope
modifier|*
name|S
parameter_list|,
name|DeclPtrTy
name|Record
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|virtual
name|void
name|ActOnStartDelayedCXXMethodDeclaration
parameter_list|(
name|Scope
modifier|*
name|S
parameter_list|,
name|DeclPtrTy
name|Method
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|virtual
name|void
name|ActOnDelayedCXXMethodParameter
parameter_list|(
name|Scope
modifier|*
name|S
parameter_list|,
name|DeclPtrTy
name|Param
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|virtual
name|void
name|ActOnFinishDelayedCXXMethodDeclaration
parameter_list|(
name|Scope
modifier|*
name|S
parameter_list|,
name|DeclPtrTy
name|Method
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|virtual
name|void
name|ActOnFinishDelayedMemberDeclarations
parameter_list|(
name|Scope
modifier|*
name|S
parameter_list|,
name|DeclPtrTy
name|Record
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|virtual
name|DeclPtrTy
name|ActOnStaticAssertDeclaration
parameter_list|(
name|SourceLocation
name|AssertLoc
parameter_list|,
name|ExprArg
name|AssertExpr
parameter_list|,
name|ExprArg
name|AssertMessageExpr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|FriendDecl
modifier|*
name|CheckFriendTypeDecl
parameter_list|(
name|SourceLocation
name|FriendLoc
parameter_list|,
name|TypeSourceInfo
modifier|*
name|TSInfo
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|DeclPtrTy
name|ActOnFriendTypeDecl
parameter_list|(
name|Scope
modifier|*
name|S
parameter_list|,
specifier|const
name|DeclSpec
modifier|&
name|DS
parameter_list|,
name|MultiTemplateParamsArg
name|TemplateParams
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|DeclPtrTy
name|ActOnFriendFunctionDecl
parameter_list|(
name|Scope
modifier|*
name|S
parameter_list|,
name|Declarator
modifier|&
name|D
parameter_list|,
name|bool
name|IsDefinition
parameter_list|,
name|MultiTemplateParamsArg
name|TemplateParams
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
name|QualType
name|CheckConstructorDeclarator
argument_list|(
name|Declarator
operator|&
name|D
argument_list|,
name|QualType
name|R
argument_list|,
name|FunctionDecl
operator|::
name|StorageClass
operator|&
name|SC
argument_list|)
decl_stmt|;
end_decl_stmt

begin_function_decl
name|void
name|CheckConstructor
parameter_list|(
name|CXXConstructorDecl
modifier|*
name|Constructor
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
name|QualType
name|CheckDestructorDeclarator
argument_list|(
name|Declarator
operator|&
name|D
argument_list|,
name|QualType
name|R
argument_list|,
name|FunctionDecl
operator|::
name|StorageClass
operator|&
name|SC
argument_list|)
decl_stmt|;
end_decl_stmt

begin_function_decl
name|bool
name|CheckDestructor
parameter_list|(
name|CXXDestructorDecl
modifier|*
name|Destructor
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
name|void
name|CheckConversionDeclarator
argument_list|(
name|Declarator
operator|&
name|D
argument_list|,
name|QualType
operator|&
name|R
argument_list|,
name|FunctionDecl
operator|::
name|StorageClass
operator|&
name|SC
argument_list|)
decl_stmt|;
end_decl_stmt

begin_function_decl
name|DeclPtrTy
name|ActOnConversionDeclarator
parameter_list|(
name|CXXConversionDecl
modifier|*
name|Conversion
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|//===--------------------------------------------------------------------===//
end_comment

begin_comment
comment|// C++ Derived Classes
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|/// ActOnBaseSpecifier - Parsed a base specifier
end_comment

begin_function_decl
name|CXXBaseSpecifier
modifier|*
name|CheckBaseSpecifier
parameter_list|(
name|CXXRecordDecl
modifier|*
name|Class
parameter_list|,
name|SourceRange
name|SpecifierRange
parameter_list|,
name|bool
name|Virtual
parameter_list|,
name|AccessSpecifier
name|Access
parameter_list|,
name|QualType
name|BaseType
parameter_list|,
name|SourceLocation
name|BaseLoc
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// SetClassDeclAttributesFromBase - Copies class decl traits
end_comment

begin_comment
comment|/// (such as whether the class has a trivial constructor,
end_comment

begin_comment
comment|/// trivial destructor etc) from the given base class.
end_comment

begin_function_decl
name|void
name|SetClassDeclAttributesFromBase
parameter_list|(
name|CXXRecordDecl
modifier|*
name|Class
parameter_list|,
specifier|const
name|CXXRecordDecl
modifier|*
name|BaseClass
parameter_list|,
name|bool
name|BaseIsVirtual
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|virtual
name|BaseResult
name|ActOnBaseSpecifier
parameter_list|(
name|DeclPtrTy
name|classdecl
parameter_list|,
name|SourceRange
name|SpecifierRange
parameter_list|,
name|bool
name|Virtual
parameter_list|,
name|AccessSpecifier
name|Access
parameter_list|,
name|TypeTy
modifier|*
name|basetype
parameter_list|,
name|SourceLocation
name|BaseLoc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|AttachBaseSpecifiers
parameter_list|(
name|CXXRecordDecl
modifier|*
name|Class
parameter_list|,
name|CXXBaseSpecifier
modifier|*
modifier|*
name|Bases
parameter_list|,
name|unsigned
name|NumBases
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|virtual
name|void
name|ActOnBaseSpecifiers
parameter_list|(
name|DeclPtrTy
name|ClassDecl
parameter_list|,
name|BaseTy
modifier|*
modifier|*
name|Bases
parameter_list|,
name|unsigned
name|NumBases
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|IsDerivedFrom
parameter_list|(
name|QualType
name|Derived
parameter_list|,
name|QualType
name|Base
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|IsDerivedFrom
parameter_list|(
name|QualType
name|Derived
parameter_list|,
name|QualType
name|Base
parameter_list|,
name|CXXBasePaths
modifier|&
name|Paths
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|// FIXME: I don't like this name.
end_comment

begin_function_decl
name|void
name|BuildBasePathArray
parameter_list|(
specifier|const
name|CXXBasePaths
modifier|&
name|Paths
parameter_list|,
name|CXXBaseSpecifierArray
modifier|&
name|BasePath
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|BasePathInvolvesVirtualBase
parameter_list|(
specifier|const
name|CXXBaseSpecifierArray
modifier|&
name|BasePath
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|CheckDerivedToBaseConversion
parameter_list|(
name|QualType
name|Derived
parameter_list|,
name|QualType
name|Base
parameter_list|,
name|SourceLocation
name|Loc
parameter_list|,
name|SourceRange
name|Range
parameter_list|,
name|CXXBaseSpecifierArray
modifier|*
name|BasePath
init|=
literal|0
parameter_list|,
name|bool
name|IgnoreAccess
init|=
name|false
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|CheckDerivedToBaseConversion
parameter_list|(
name|QualType
name|Derived
parameter_list|,
name|QualType
name|Base
parameter_list|,
name|unsigned
name|InaccessibleBaseID
parameter_list|,
name|unsigned
name|AmbigiousBaseConvID
parameter_list|,
name|SourceLocation
name|Loc
parameter_list|,
name|SourceRange
name|Range
parameter_list|,
name|DeclarationName
name|Name
parameter_list|,
name|CXXBaseSpecifierArray
modifier|*
name|BasePath
parameter_list|)
function_decl|;
end_function_decl

begin_expr_stmt
name|std
operator|::
name|string
name|getAmbiguousPathsDisplayString
argument_list|(
name|CXXBasePaths
operator|&
name|Paths
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// CheckOverridingFunctionReturnType - Checks whether the return types are
end_comment

begin_comment
comment|/// covariant, according to C++ [class.virtual]p5.
end_comment

begin_function_decl
name|bool
name|CheckOverridingFunctionReturnType
parameter_list|(
specifier|const
name|CXXMethodDecl
modifier|*
name|New
parameter_list|,
specifier|const
name|CXXMethodDecl
modifier|*
name|Old
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// CheckOverridingFunctionExceptionSpec - Checks whether the exception
end_comment

begin_comment
comment|/// spec is a subset of base spec.
end_comment

begin_function_decl
name|bool
name|CheckOverridingFunctionExceptionSpec
parameter_list|(
specifier|const
name|CXXMethodDecl
modifier|*
name|New
parameter_list|,
specifier|const
name|CXXMethodDecl
modifier|*
name|Old
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// CheckOverridingFunctionAttributes - Checks whether attributes are
end_comment

begin_comment
comment|/// incompatible or prevent overriding.
end_comment

begin_function_decl
name|bool
name|CheckOverridingFunctionAttributes
parameter_list|(
specifier|const
name|CXXMethodDecl
modifier|*
name|New
parameter_list|,
specifier|const
name|CXXMethodDecl
modifier|*
name|Old
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|CheckPureMethod
parameter_list|(
name|CXXMethodDecl
modifier|*
name|Method
parameter_list|,
name|SourceRange
name|InitRange
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|//===--------------------------------------------------------------------===//
end_comment

begin_comment
comment|// C++ Access Control
end_comment

begin_comment
comment|//
end_comment

begin_enum
enum|enum
name|AccessResult
block|{
name|AR_accessible
block|,
name|AR_inaccessible
block|,
name|AR_dependent
block|,
name|AR_delayed
block|}
enum|;
end_enum

begin_function_decl
name|bool
name|SetMemberAccessSpecifier
parameter_list|(
name|NamedDecl
modifier|*
name|MemberDecl
parameter_list|,
name|NamedDecl
modifier|*
name|PrevMemberDecl
parameter_list|,
name|AccessSpecifier
name|LexicalAS
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|AccessResult
name|CheckUnresolvedMemberAccess
parameter_list|(
name|UnresolvedMemberExpr
modifier|*
name|E
parameter_list|,
name|DeclAccessPair
name|FoundDecl
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|AccessResult
name|CheckUnresolvedLookupAccess
parameter_list|(
name|UnresolvedLookupExpr
modifier|*
name|E
parameter_list|,
name|DeclAccessPair
name|FoundDecl
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|AccessResult
name|CheckAllocationAccess
parameter_list|(
name|SourceLocation
name|OperatorLoc
parameter_list|,
name|SourceRange
name|PlacementRange
parameter_list|,
name|CXXRecordDecl
modifier|*
name|NamingClass
parameter_list|,
name|DeclAccessPair
name|FoundDecl
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|AccessResult
name|CheckConstructorAccess
parameter_list|(
name|SourceLocation
name|Loc
parameter_list|,
name|CXXConstructorDecl
modifier|*
name|D
parameter_list|,
specifier|const
name|InitializedEntity
modifier|&
name|Entity
parameter_list|,
name|AccessSpecifier
name|Access
parameter_list|,
name|bool
name|IsCopyBindingRefToTemp
init|=
name|false
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|AccessResult
name|CheckDestructorAccess
parameter_list|(
name|SourceLocation
name|Loc
parameter_list|,
name|CXXDestructorDecl
modifier|*
name|Dtor
parameter_list|,
specifier|const
name|PartialDiagnostic
modifier|&
name|PDiag
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|AccessResult
name|CheckDirectMemberAccess
parameter_list|(
name|SourceLocation
name|Loc
parameter_list|,
name|NamedDecl
modifier|*
name|D
parameter_list|,
specifier|const
name|PartialDiagnostic
modifier|&
name|PDiag
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|AccessResult
name|CheckMemberOperatorAccess
parameter_list|(
name|SourceLocation
name|Loc
parameter_list|,
name|Expr
modifier|*
name|ObjectExpr
parameter_list|,
name|Expr
modifier|*
name|ArgExpr
parameter_list|,
name|DeclAccessPair
name|FoundDecl
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|AccessResult
name|CheckAddressOfMemberAccess
parameter_list|(
name|Expr
modifier|*
name|OvlExpr
parameter_list|,
name|DeclAccessPair
name|FoundDecl
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|AccessResult
name|CheckBaseClassAccess
parameter_list|(
name|SourceLocation
name|AccessLoc
parameter_list|,
name|QualType
name|Base
parameter_list|,
name|QualType
name|Derived
parameter_list|,
specifier|const
name|CXXBasePath
modifier|&
name|Path
parameter_list|,
name|unsigned
name|DiagID
parameter_list|,
name|bool
name|ForceCheck
init|=
name|false
parameter_list|,
name|bool
name|ForceUnprivileged
init|=
name|false
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|CheckLookupAccess
parameter_list|(
specifier|const
name|LookupResult
modifier|&
name|R
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|HandleDependentAccessCheck
parameter_list|(
specifier|const
name|DependentDiagnostic
modifier|&
name|DD
parameter_list|,
specifier|const
name|MultiLevelTemplateArgumentList
modifier|&
name|TemplateArgs
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|PerformDependentDiagnostics
parameter_list|(
specifier|const
name|DeclContext
modifier|*
name|Pattern
parameter_list|,
specifier|const
name|MultiLevelTemplateArgumentList
modifier|&
name|TemplateArgs
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|HandleDelayedAccessCheck
parameter_list|(
name|DelayedDiagnostic
modifier|&
name|DD
parameter_list|,
name|Decl
modifier|*
name|Ctx
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// A flag to suppress access checking.
end_comment

begin_decl_stmt
name|bool
name|SuppressAccessChecking
decl_stmt|;
end_decl_stmt

begin_function_decl
name|void
name|ActOnStartSuppressingAccessChecks
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ActOnStopSuppressingAccessChecks
parameter_list|()
function_decl|;
end_function_decl

begin_enum
enum|enum
name|AbstractDiagSelID
block|{
name|AbstractNone
init|=
operator|-
literal|1
block|,
name|AbstractReturnType
block|,
name|AbstractParamType
block|,
name|AbstractVariableType
block|,
name|AbstractFieldType
block|}
enum|;
end_enum

begin_function_decl
name|bool
name|RequireNonAbstractType
parameter_list|(
name|SourceLocation
name|Loc
parameter_list|,
name|QualType
name|T
parameter_list|,
specifier|const
name|PartialDiagnostic
modifier|&
name|PD
parameter_list|,
specifier|const
name|CXXRecordDecl
modifier|*
name|CurrentRD
init|=
literal|0
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|RequireNonAbstractType
parameter_list|(
name|SourceLocation
name|Loc
parameter_list|,
name|QualType
name|T
parameter_list|,
name|unsigned
name|DiagID
parameter_list|,
name|AbstractDiagSelID
name|SelID
init|=
name|AbstractNone
parameter_list|,
specifier|const
name|CXXRecordDecl
modifier|*
name|CurrentRD
init|=
literal|0
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|//===--------------------------------------------------------------------===//
end_comment

begin_comment
comment|// C++ Overloaded Operators [C++ 13.5]
end_comment

begin_comment
comment|//
end_comment

begin_function_decl
name|bool
name|CheckOverloadedOperatorDeclaration
parameter_list|(
name|FunctionDecl
modifier|*
name|FnDecl
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|CheckLiteralOperatorDeclaration
parameter_list|(
name|FunctionDecl
modifier|*
name|FnDecl
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|//===--------------------------------------------------------------------===//
end_comment

begin_comment
comment|// C++ Templates [C++ 14]
end_comment

begin_comment
comment|//
end_comment

begin_function_decl
name|void
name|LookupTemplateName
parameter_list|(
name|LookupResult
modifier|&
name|R
parameter_list|,
name|Scope
modifier|*
name|S
parameter_list|,
name|CXXScopeSpec
modifier|&
name|SS
parameter_list|,
name|QualType
name|ObjectType
parameter_list|,
name|bool
name|EnteringContext
parameter_list|,
name|bool
modifier|&
name|MemberOfUnknownSpecialization
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|virtual
name|TemplateNameKind
name|isTemplateName
parameter_list|(
name|Scope
modifier|*
name|S
parameter_list|,
name|CXXScopeSpec
modifier|&
name|SS
parameter_list|,
name|UnqualifiedId
modifier|&
name|Name
parameter_list|,
name|TypeTy
modifier|*
name|ObjectType
parameter_list|,
name|bool
name|EnteringContext
parameter_list|,
name|TemplateTy
modifier|&
name|Template
parameter_list|,
name|bool
modifier|&
name|MemberOfUnknownSpecialization
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|virtual
name|bool
name|DiagnoseUnknownTemplateName
parameter_list|(
specifier|const
name|IdentifierInfo
modifier|&
name|II
parameter_list|,
name|SourceLocation
name|IILoc
parameter_list|,
name|Scope
modifier|*
name|S
parameter_list|,
specifier|const
name|CXXScopeSpec
modifier|*
name|SS
parameter_list|,
name|TemplateTy
modifier|&
name|SuggestedTemplate
parameter_list|,
name|TemplateNameKind
modifier|&
name|SuggestedKind
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|DiagnoseTemplateParameterShadow
parameter_list|(
name|SourceLocation
name|Loc
parameter_list|,
name|Decl
modifier|*
name|PrevDecl
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|TemplateDecl
modifier|*
name|AdjustDeclIfTemplate
parameter_list|(
name|DeclPtrTy
modifier|&
name|Decl
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|virtual
name|DeclPtrTy
name|ActOnTypeParameter
parameter_list|(
name|Scope
modifier|*
name|S
parameter_list|,
name|bool
name|Typename
parameter_list|,
name|bool
name|Ellipsis
parameter_list|,
name|SourceLocation
name|EllipsisLoc
parameter_list|,
name|SourceLocation
name|KeyLoc
parameter_list|,
name|IdentifierInfo
modifier|*
name|ParamName
parameter_list|,
name|SourceLocation
name|ParamNameLoc
parameter_list|,
name|unsigned
name|Depth
parameter_list|,
name|unsigned
name|Position
parameter_list|,
name|SourceLocation
name|EqualLoc
parameter_list|,
name|TypeTy
modifier|*
name|DefaultArg
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|QualType
name|CheckNonTypeTemplateParameterType
parameter_list|(
name|QualType
name|T
parameter_list|,
name|SourceLocation
name|Loc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|virtual
name|DeclPtrTy
name|ActOnNonTypeTemplateParameter
parameter_list|(
name|Scope
modifier|*
name|S
parameter_list|,
name|Declarator
modifier|&
name|D
parameter_list|,
name|unsigned
name|Depth
parameter_list|,
name|unsigned
name|Position
parameter_list|,
name|SourceLocation
name|EqualLoc
parameter_list|,
name|ExprArg
name|DefaultArg
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|virtual
name|DeclPtrTy
name|ActOnTemplateTemplateParameter
parameter_list|(
name|Scope
modifier|*
name|S
parameter_list|,
name|SourceLocation
name|TmpLoc
parameter_list|,
name|TemplateParamsTy
modifier|*
name|Params
parameter_list|,
name|IdentifierInfo
modifier|*
name|ParamName
parameter_list|,
name|SourceLocation
name|ParamNameLoc
parameter_list|,
name|unsigned
name|Depth
parameter_list|,
name|unsigned
name|Position
parameter_list|,
name|SourceLocation
name|EqualLoc
parameter_list|,
specifier|const
name|ParsedTemplateArgument
modifier|&
name|DefaultArg
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|virtual
name|TemplateParamsTy
modifier|*
name|ActOnTemplateParameterList
parameter_list|(
name|unsigned
name|Depth
parameter_list|,
name|SourceLocation
name|ExportLoc
parameter_list|,
name|SourceLocation
name|TemplateLoc
parameter_list|,
name|SourceLocation
name|LAngleLoc
parameter_list|,
name|DeclPtrTy
modifier|*
name|Params
parameter_list|,
name|unsigned
name|NumParams
parameter_list|,
name|SourceLocation
name|RAngleLoc
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// \brief The context in which we are checking a template parameter
end_comment

begin_comment
comment|/// list.
end_comment

begin_enum
enum|enum
name|TemplateParamListContext
block|{
name|TPC_ClassTemplate
block|,
name|TPC_FunctionTemplate
block|,
name|TPC_ClassTemplateMember
block|,
name|TPC_FriendFunctionTemplate
block|}
enum|;
end_enum

begin_function_decl
name|bool
name|CheckTemplateParameterList
parameter_list|(
name|TemplateParameterList
modifier|*
name|NewParams
parameter_list|,
name|TemplateParameterList
modifier|*
name|OldParams
parameter_list|,
name|TemplateParamListContext
name|TPC
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|TemplateParameterList
modifier|*
name|MatchTemplateParametersToScopeSpecifier
parameter_list|(
name|SourceLocation
name|DeclStartLoc
parameter_list|,
specifier|const
name|CXXScopeSpec
modifier|&
name|SS
parameter_list|,
name|TemplateParameterList
modifier|*
modifier|*
name|ParamLists
parameter_list|,
name|unsigned
name|NumParamLists
parameter_list|,
name|bool
name|IsFriend
parameter_list|,
name|bool
modifier|&
name|IsExplicitSpecialization
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|DeclResult
name|CheckClassTemplate
parameter_list|(
name|Scope
modifier|*
name|S
parameter_list|,
name|unsigned
name|TagSpec
parameter_list|,
name|TagUseKind
name|TUK
parameter_list|,
name|SourceLocation
name|KWLoc
parameter_list|,
name|CXXScopeSpec
modifier|&
name|SS
parameter_list|,
name|IdentifierInfo
modifier|*
name|Name
parameter_list|,
name|SourceLocation
name|NameLoc
parameter_list|,
name|AttributeList
modifier|*
name|Attr
parameter_list|,
name|TemplateParameterList
modifier|*
name|TemplateParams
parameter_list|,
name|AccessSpecifier
name|AS
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|translateTemplateArguments
parameter_list|(
specifier|const
name|ASTTemplateArgsPtr
modifier|&
name|In
parameter_list|,
name|TemplateArgumentListInfo
modifier|&
name|Out
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|QualType
name|CheckTemplateIdType
parameter_list|(
name|TemplateName
name|Template
parameter_list|,
name|SourceLocation
name|TemplateLoc
parameter_list|,
specifier|const
name|TemplateArgumentListInfo
modifier|&
name|TemplateArgs
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|virtual
name|TypeResult
name|ActOnTemplateIdType
parameter_list|(
name|TemplateTy
name|Template
parameter_list|,
name|SourceLocation
name|TemplateLoc
parameter_list|,
name|SourceLocation
name|LAngleLoc
parameter_list|,
name|ASTTemplateArgsPtr
name|TemplateArgs
parameter_list|,
name|SourceLocation
name|RAngleLoc
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
name|virtual
name|TypeResult
name|ActOnTagTemplateIdType
argument_list|(
name|TypeResult
name|Type
argument_list|,
name|TagUseKind
name|TUK
argument_list|,
name|DeclSpec
operator|::
name|TST
name|TagSpec
argument_list|,
name|SourceLocation
name|TagLoc
argument_list|)
decl_stmt|;
end_decl_stmt

begin_function_decl
name|OwningExprResult
name|BuildTemplateIdExpr
parameter_list|(
specifier|const
name|CXXScopeSpec
modifier|&
name|SS
parameter_list|,
name|LookupResult
modifier|&
name|R
parameter_list|,
name|bool
name|RequiresADL
parameter_list|,
specifier|const
name|TemplateArgumentListInfo
modifier|&
name|TemplateArgs
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|OwningExprResult
name|BuildQualifiedTemplateIdExpr
parameter_list|(
name|CXXScopeSpec
modifier|&
name|SS
parameter_list|,
name|DeclarationName
name|Name
parameter_list|,
name|SourceLocation
name|NameLoc
parameter_list|,
specifier|const
name|TemplateArgumentListInfo
modifier|&
name|TemplateArgs
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|virtual
name|TemplateNameKind
name|ActOnDependentTemplateName
parameter_list|(
name|Scope
modifier|*
name|S
parameter_list|,
name|SourceLocation
name|TemplateKWLoc
parameter_list|,
name|CXXScopeSpec
modifier|&
name|SS
parameter_list|,
name|UnqualifiedId
modifier|&
name|Name
parameter_list|,
name|TypeTy
modifier|*
name|ObjectType
parameter_list|,
name|bool
name|EnteringContext
parameter_list|,
name|TemplateTy
modifier|&
name|Template
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|CheckClassTemplatePartialSpecializationArgs
parameter_list|(
name|TemplateParameterList
modifier|*
name|TemplateParams
parameter_list|,
specifier|const
name|TemplateArgumentListBuilder
modifier|&
name|TemplateArgs
parameter_list|,
name|bool
modifier|&
name|MirrorsPrimaryTemplate
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|virtual
name|DeclResult
name|ActOnClassTemplateSpecialization
parameter_list|(
name|Scope
modifier|*
name|S
parameter_list|,
name|unsigned
name|TagSpec
parameter_list|,
name|TagUseKind
name|TUK
parameter_list|,
name|SourceLocation
name|KWLoc
parameter_list|,
name|CXXScopeSpec
modifier|&
name|SS
parameter_list|,
name|TemplateTy
name|Template
parameter_list|,
name|SourceLocation
name|TemplateNameLoc
parameter_list|,
name|SourceLocation
name|LAngleLoc
parameter_list|,
name|ASTTemplateArgsPtr
name|TemplateArgs
parameter_list|,
name|SourceLocation
name|RAngleLoc
parameter_list|,
name|AttributeList
modifier|*
name|Attr
parameter_list|,
name|MultiTemplateParamsArg
name|TemplateParameterLists
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|virtual
name|DeclPtrTy
name|ActOnTemplateDeclarator
parameter_list|(
name|Scope
modifier|*
name|S
parameter_list|,
name|MultiTemplateParamsArg
name|TemplateParameterLists
parameter_list|,
name|Declarator
modifier|&
name|D
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|virtual
name|DeclPtrTy
name|ActOnStartOfFunctionTemplateDef
parameter_list|(
name|Scope
modifier|*
name|FnBodyScope
parameter_list|,
name|MultiTemplateParamsArg
name|TemplateParameterLists
parameter_list|,
name|Declarator
modifier|&
name|D
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|CheckSpecializationInstantiationRedecl
parameter_list|(
name|SourceLocation
name|NewLoc
parameter_list|,
name|TemplateSpecializationKind
name|NewTSK
parameter_list|,
name|NamedDecl
modifier|*
name|PrevDecl
parameter_list|,
name|TemplateSpecializationKind
name|PrevTSK
parameter_list|,
name|SourceLocation
name|PrevPointOfInstantiation
parameter_list|,
name|bool
modifier|&
name|SuppressNew
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|CheckDependentFunctionTemplateSpecialization
parameter_list|(
name|FunctionDecl
modifier|*
name|FD
parameter_list|,
specifier|const
name|TemplateArgumentListInfo
modifier|&
name|ExplicitTemplateArgs
parameter_list|,
name|LookupResult
modifier|&
name|Previous
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|CheckFunctionTemplateSpecialization
parameter_list|(
name|FunctionDecl
modifier|*
name|FD
parameter_list|,
specifier|const
name|TemplateArgumentListInfo
modifier|*
name|ExplicitTemplateArgs
parameter_list|,
name|LookupResult
modifier|&
name|Previous
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|CheckMemberSpecialization
parameter_list|(
name|NamedDecl
modifier|*
name|Member
parameter_list|,
name|LookupResult
modifier|&
name|Previous
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|virtual
name|DeclResult
name|ActOnExplicitInstantiation
parameter_list|(
name|Scope
modifier|*
name|S
parameter_list|,
name|SourceLocation
name|ExternLoc
parameter_list|,
name|SourceLocation
name|TemplateLoc
parameter_list|,
name|unsigned
name|TagSpec
parameter_list|,
name|SourceLocation
name|KWLoc
parameter_list|,
specifier|const
name|CXXScopeSpec
modifier|&
name|SS
parameter_list|,
name|TemplateTy
name|Template
parameter_list|,
name|SourceLocation
name|TemplateNameLoc
parameter_list|,
name|SourceLocation
name|LAngleLoc
parameter_list|,
name|ASTTemplateArgsPtr
name|TemplateArgs
parameter_list|,
name|SourceLocation
name|RAngleLoc
parameter_list|,
name|AttributeList
modifier|*
name|Attr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|virtual
name|DeclResult
name|ActOnExplicitInstantiation
parameter_list|(
name|Scope
modifier|*
name|S
parameter_list|,
name|SourceLocation
name|ExternLoc
parameter_list|,
name|SourceLocation
name|TemplateLoc
parameter_list|,
name|unsigned
name|TagSpec
parameter_list|,
name|SourceLocation
name|KWLoc
parameter_list|,
name|CXXScopeSpec
modifier|&
name|SS
parameter_list|,
name|IdentifierInfo
modifier|*
name|Name
parameter_list|,
name|SourceLocation
name|NameLoc
parameter_list|,
name|AttributeList
modifier|*
name|Attr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|virtual
name|DeclResult
name|ActOnExplicitInstantiation
parameter_list|(
name|Scope
modifier|*
name|S
parameter_list|,
name|SourceLocation
name|ExternLoc
parameter_list|,
name|SourceLocation
name|TemplateLoc
parameter_list|,
name|Declarator
modifier|&
name|D
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|TemplateArgumentLoc
name|SubstDefaultTemplateArgumentIfAvailable
parameter_list|(
name|TemplateDecl
modifier|*
name|Template
parameter_list|,
name|SourceLocation
name|TemplateLoc
parameter_list|,
name|SourceLocation
name|RAngleLoc
parameter_list|,
name|Decl
modifier|*
name|Param
parameter_list|,
name|TemplateArgumentListBuilder
modifier|&
name|Converted
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// \brief Specifies the context in which a particular template
end_comment

begin_comment
comment|/// argument is being checked.
end_comment

begin_enum
enum|enum
name|CheckTemplateArgumentKind
block|{
comment|/// \brief The template argument was specified in the code or was
comment|/// instantiated with some deduced template arguments.
name|CTAK_Specified
block|,
comment|/// \brief The template argument was deduced via template argument
comment|/// deduction.
name|CTAK_Deduced
block|,
comment|/// \brief The template argument was deduced from an array bound
comment|/// via template argument deduction.
name|CTAK_DeducedFromArrayBound
block|}
enum|;
end_enum

begin_function_decl
name|bool
name|CheckTemplateArgument
parameter_list|(
name|NamedDecl
modifier|*
name|Param
parameter_list|,
specifier|const
name|TemplateArgumentLoc
modifier|&
name|Arg
parameter_list|,
name|TemplateDecl
modifier|*
name|Template
parameter_list|,
name|SourceLocation
name|TemplateLoc
parameter_list|,
name|SourceLocation
name|RAngleLoc
parameter_list|,
name|TemplateArgumentListBuilder
modifier|&
name|Converted
parameter_list|,
name|CheckTemplateArgumentKind
name|CTAK
init|=
name|CTAK_Specified
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|CheckTemplateArgumentList
parameter_list|(
name|TemplateDecl
modifier|*
name|Template
parameter_list|,
name|SourceLocation
name|TemplateLoc
parameter_list|,
specifier|const
name|TemplateArgumentListInfo
modifier|&
name|TemplateArgs
parameter_list|,
name|bool
name|PartialTemplateArgs
parameter_list|,
name|TemplateArgumentListBuilder
modifier|&
name|Converted
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|CheckTemplateTypeArgument
parameter_list|(
name|TemplateTypeParmDecl
modifier|*
name|Param
parameter_list|,
specifier|const
name|TemplateArgumentLoc
modifier|&
name|Arg
parameter_list|,
name|TemplateArgumentListBuilder
modifier|&
name|Converted
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|CheckTemplateArgument
parameter_list|(
name|TemplateTypeParmDecl
modifier|*
name|Param
parameter_list|,
name|TypeSourceInfo
modifier|*
name|Arg
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|CheckTemplateArgumentPointerToMember
parameter_list|(
name|Expr
modifier|*
name|Arg
parameter_list|,
name|TemplateArgument
modifier|&
name|Converted
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|CheckTemplateArgument
parameter_list|(
name|NonTypeTemplateParmDecl
modifier|*
name|Param
parameter_list|,
name|QualType
name|InstantiatedParamType
parameter_list|,
name|Expr
modifier|*
modifier|&
name|Arg
parameter_list|,
name|TemplateArgument
modifier|&
name|Converted
parameter_list|,
name|CheckTemplateArgumentKind
name|CTAK
init|=
name|CTAK_Specified
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|CheckTemplateArgument
parameter_list|(
name|TemplateTemplateParmDecl
modifier|*
name|Param
parameter_list|,
specifier|const
name|TemplateArgumentLoc
modifier|&
name|Arg
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|OwningExprResult
name|BuildExpressionFromDeclTemplateArgument
parameter_list|(
specifier|const
name|TemplateArgument
modifier|&
name|Arg
parameter_list|,
name|QualType
name|ParamType
parameter_list|,
name|SourceLocation
name|Loc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|OwningExprResult
name|BuildExpressionFromIntegralTemplateArgument
parameter_list|(
specifier|const
name|TemplateArgument
modifier|&
name|Arg
parameter_list|,
name|SourceLocation
name|Loc
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// \brief Enumeration describing how template parameter lists are compared
end_comment

begin_comment
comment|/// for equality.
end_comment

begin_enum
enum|enum
name|TemplateParameterListEqualKind
block|{
comment|/// \brief We are matching the template parameter lists of two templates
comment|/// that might be redeclarations.
comment|///
comment|/// \code
comment|/// template<typename T> struct X;
comment|/// template<typename T> struct X;
comment|/// \endcode
name|TPL_TemplateMatch
block|,
comment|/// \brief We are matching the template parameter lists of two template
comment|/// template parameters as part of matching the template parameter lists
comment|/// of two templates that might be redeclarations.
comment|///
comment|/// \code
comment|/// template<template<int I> class TT> struct X;
comment|/// template<template<int Value> class Other> struct X;
comment|/// \endcode
name|TPL_TemplateTemplateParmMatch
block|,
comment|/// \brief We are matching the template parameter lists of a template
comment|/// template argument against the template parameter lists of a template
comment|/// template parameter.
comment|///
comment|/// \code
comment|/// template<template<int Value> class Metafun> struct X;
comment|/// template<int Value> struct integer_c;
comment|/// X<integer_c> xic;
comment|/// \endcode
name|TPL_TemplateTemplateArgumentMatch
block|}
enum|;
end_enum

begin_function_decl
name|bool
name|TemplateParameterListsAreEqual
parameter_list|(
name|TemplateParameterList
modifier|*
name|New
parameter_list|,
name|TemplateParameterList
modifier|*
name|Old
parameter_list|,
name|bool
name|Complain
parameter_list|,
name|TemplateParameterListEqualKind
name|Kind
parameter_list|,
name|SourceLocation
name|TemplateArgLoc
init|=
name|SourceLocation
argument_list|()
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|CheckTemplateDeclScope
parameter_list|(
name|Scope
modifier|*
name|S
parameter_list|,
name|TemplateParameterList
modifier|*
name|TemplateParams
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// \brief Called when the parser has parsed a C++ typename
end_comment

begin_comment
comment|/// specifier, e.g., "typename T::type".
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param S The scope in which this typename type occurs.
end_comment

begin_comment
comment|/// \param TypenameLoc the location of the 'typename' keyword
end_comment

begin_comment
comment|/// \param SS the nested-name-specifier following the typename (e.g., 'T::').
end_comment

begin_comment
comment|/// \param II the identifier we're retrieving (e.g., 'type' in the example).
end_comment

begin_comment
comment|/// \param IdLoc the location of the identifier.
end_comment

begin_function_decl
name|virtual
name|TypeResult
name|ActOnTypenameType
parameter_list|(
name|Scope
modifier|*
name|S
parameter_list|,
name|SourceLocation
name|TypenameLoc
parameter_list|,
specifier|const
name|CXXScopeSpec
modifier|&
name|SS
parameter_list|,
specifier|const
name|IdentifierInfo
modifier|&
name|II
parameter_list|,
name|SourceLocation
name|IdLoc
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// \brief Called when the parser has parsed a C++ typename
end_comment

begin_comment
comment|/// specifier that ends in a template-id, e.g.,
end_comment

begin_comment
comment|/// "typename MetaFun::template apply<T1, T2>".
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param S The scope in which this typename type occurs.
end_comment

begin_comment
comment|/// \param TypenameLoc the location of the 'typename' keyword
end_comment

begin_comment
comment|/// \param SS the nested-name-specifier following the typename (e.g., 'T::').
end_comment

begin_comment
comment|/// \param TemplateLoc the location of the 'template' keyword, if any.
end_comment

begin_comment
comment|/// \param Ty the type that the typename specifier refers to.
end_comment

begin_function_decl
name|virtual
name|TypeResult
name|ActOnTypenameType
parameter_list|(
name|Scope
modifier|*
name|S
parameter_list|,
name|SourceLocation
name|TypenameLoc
parameter_list|,
specifier|const
name|CXXScopeSpec
modifier|&
name|SS
parameter_list|,
name|SourceLocation
name|TemplateLoc
parameter_list|,
name|TypeTy
modifier|*
name|Ty
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|QualType
name|CheckTypenameType
parameter_list|(
name|ElaboratedTypeKeyword
name|Keyword
parameter_list|,
name|NestedNameSpecifier
modifier|*
name|NNS
parameter_list|,
specifier|const
name|IdentifierInfo
modifier|&
name|II
parameter_list|,
name|SourceLocation
name|KeywordLoc
parameter_list|,
name|SourceRange
name|NNSRange
parameter_list|,
name|SourceLocation
name|IILoc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|TypeSourceInfo
modifier|*
name|RebuildTypeInCurrentInstantiation
parameter_list|(
name|TypeSourceInfo
modifier|*
name|T
parameter_list|,
name|SourceLocation
name|Loc
parameter_list|,
name|DeclarationName
name|Name
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|RebuildNestedNameSpecifierInCurrentInstantiation
parameter_list|(
name|CXXScopeSpec
modifier|&
name|SS
parameter_list|)
function_decl|;
end_function_decl

begin_expr_stmt
name|std
operator|::
name|string
name|getTemplateArgumentBindingsText
argument_list|(
specifier|const
name|TemplateParameterList
operator|*
name|Params
argument_list|,
specifier|const
name|TemplateArgumentList
operator|&
name|Args
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|std
operator|::
name|string
name|getTemplateArgumentBindingsText
argument_list|(
argument|const TemplateParameterList *Params
argument_list|,
argument|const TemplateArgument *Args
argument_list|,
argument|unsigned NumArgs
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// \brief Describes the result of template argument deduction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// The TemplateDeductionResult enumeration describes the result of
end_comment

begin_comment
comment|/// template argument deduction, as returned from
end_comment

begin_comment
comment|/// DeduceTemplateArguments(). The separate TemplateDeductionInfo
end_comment

begin_comment
comment|/// structure provides additional information about the results of
end_comment

begin_comment
comment|/// template argument deduction, e.g., the deduced template argument
end_comment

begin_comment
comment|/// list (if successful) or the specific template parameters or
end_comment

begin_comment
comment|/// deduced arguments that were involved in the failure.
end_comment

begin_enum
enum|enum
name|TemplateDeductionResult
block|{
comment|/// \brief Template argument deduction was successful.
name|TDK_Success
init|=
literal|0
block|,
comment|/// \brief Template argument deduction exceeded the maximum template
comment|/// instantiation depth (which has already been diagnosed).
name|TDK_InstantiationDepth
block|,
comment|/// \brief Template argument deduction did not deduce a value
comment|/// for every template parameter.
name|TDK_Incomplete
block|,
comment|/// \brief Template argument deduction produced inconsistent
comment|/// deduced values for the given template parameter.
name|TDK_Inconsistent
block|,
comment|/// \brief Template argument deduction failed due to inconsistent
comment|/// cv-qualifiers on a template parameter type that would
comment|/// otherwise be deduced, e.g., we tried to deduce T in "const T"
comment|/// but were given a non-const "X".
name|TDK_InconsistentQuals
block|,
comment|/// \brief Substitution of the deduced template argument values
comment|/// resulted in an error.
name|TDK_SubstitutionFailure
block|,
comment|/// \brief Substitution of the deduced template argument values
comment|/// into a non-deduced context produced a type or value that
comment|/// produces a type that does not match the original template
comment|/// arguments provided.
name|TDK_NonDeducedMismatch
block|,
comment|/// \brief When performing template argument deduction for a function
comment|/// template, there were too many call arguments.
name|TDK_TooManyArguments
block|,
comment|/// \brief When performing template argument deduction for a function
comment|/// template, there were too few call arguments.
name|TDK_TooFewArguments
block|,
comment|/// \brief The explicitly-specified template arguments were not valid
comment|/// template arguments for the given template.
name|TDK_InvalidExplicitArguments
block|,
comment|/// \brief The arguments included an overloaded function name that could
comment|/// not be resolved to a suitable function.
name|TDK_FailedOverloadResolution
block|}
enum|;
end_enum

begin_comment
comment|/// \brief Provides information about an attempted template argument
end_comment

begin_comment
comment|/// deduction, whose success or failure was described by a
end_comment

begin_comment
comment|/// TemplateDeductionResult value.
end_comment

begin_decl_stmt
name|class
name|TemplateDeductionInfo
block|{
comment|/// \brief The context in which the template arguments are stored.
name|ASTContext
modifier|&
name|Context
decl_stmt|;
comment|/// \brief The deduced template argument list.
comment|///
name|TemplateArgumentList
modifier|*
name|Deduced
decl_stmt|;
comment|/// \brief The source location at which template argument
comment|/// deduction is occurring.
name|SourceLocation
name|Loc
decl_stmt|;
comment|// do not implement these
name|TemplateDeductionInfo
argument_list|(
specifier|const
name|TemplateDeductionInfo
operator|&
argument_list|)
expr_stmt|;
name|TemplateDeductionInfo
modifier|&
name|operator
init|=
operator|(
specifier|const
name|TemplateDeductionInfo
operator|&
operator|)
decl_stmt|;
name|public
label|:
name|TemplateDeductionInfo
argument_list|(
argument|ASTContext&Context
argument_list|,
argument|SourceLocation Loc
argument_list|)
block|:
name|Context
argument_list|(
name|Context
argument_list|)
operator|,
name|Deduced
argument_list|(
literal|0
argument_list|)
operator|,
name|Loc
argument_list|(
argument|Loc
argument_list|)
block|{ }
operator|~
name|TemplateDeductionInfo
argument_list|()
block|{
comment|// FIXME: if (Deduced) Deduced->Destroy(Context);
block|}
comment|/// \brief Returns the location at which template argument is
comment|/// occuring.
name|SourceLocation
name|getLocation
argument_list|()
specifier|const
block|{
return|return
name|Loc
return|;
block|}
comment|/// \brief Take ownership of the deduced template argument list.
name|TemplateArgumentList
modifier|*
name|take
parameter_list|()
block|{
name|TemplateArgumentList
modifier|*
name|Result
init|=
name|Deduced
decl_stmt|;
name|Deduced
operator|=
literal|0
expr_stmt|;
return|return
name|Result
return|;
block|}
comment|/// \brief Provide a new template argument list that contains the
comment|/// results of template argument deduction.
name|void
name|reset
parameter_list|(
name|TemplateArgumentList
modifier|*
name|NewDeduced
parameter_list|)
block|{
comment|// FIXME: if (Deduced) Deduced->Destroy(Context);
name|Deduced
operator|=
name|NewDeduced
expr_stmt|;
block|}
comment|/// \brief The template parameter to which a template argument
comment|/// deduction failure refers.
comment|///
comment|/// Depending on the result of template argument deduction, this
comment|/// template parameter may have different meanings:
comment|///
comment|///   TDK_Incomplete: this is the first template parameter whose
comment|///   corresponding template argument was not deduced.
comment|///
comment|///   TDK_Inconsistent: this is the template parameter for which
comment|///   two different template argument values were deduced.
name|TemplateParameter
name|Param
decl_stmt|;
comment|/// \brief The first template argument to which the template
comment|/// argument deduction failure refers.
comment|///
comment|/// Depending on the result of the template argument deduction,
comment|/// this template argument may have different meanings:
comment|///
comment|///   TDK_Inconsistent: this argument is the first value deduced
comment|///   for the corresponding template parameter.
comment|///
comment|///   TDK_SubstitutionFailure: this argument is the template
comment|///   argument we were instantiating when we encountered an error.
comment|///
comment|///   TDK_NonDeducedMismatch: this is the template argument
comment|///   provided in the source code.
name|TemplateArgument
name|FirstArg
decl_stmt|;
comment|/// \brief The second template argument to which the template
comment|/// argument deduction failure refers.
comment|///
comment|/// FIXME: Finish documenting this.
name|TemplateArgument
name|SecondArg
decl_stmt|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_function_decl
name|TemplateDeductionResult
name|DeduceTemplateArguments
parameter_list|(
name|ClassTemplatePartialSpecializationDecl
modifier|*
name|Partial
parameter_list|,
specifier|const
name|TemplateArgumentList
modifier|&
name|TemplateArgs
parameter_list|,
name|TemplateDeductionInfo
modifier|&
name|Info
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
name|TemplateDeductionResult
name|SubstituteExplicitTemplateArguments
argument_list|(
name|FunctionTemplateDecl
operator|*
name|FunctionTemplate
argument_list|,
specifier|const
name|TemplateArgumentListInfo
operator|&
name|ExplicitTemplateArgs
argument_list|,
name|llvm
operator|::
name|SmallVectorImpl
operator|<
name|DeducedTemplateArgument
operator|>
operator|&
name|Deduced
argument_list|,
name|llvm
operator|::
name|SmallVectorImpl
operator|<
name|QualType
operator|>
operator|&
name|ParamTypes
argument_list|,
name|QualType
operator|*
name|FunctionType
argument_list|,
name|TemplateDeductionInfo
operator|&
name|Info
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|TemplateDeductionResult
name|FinishTemplateArgumentDeduction
argument_list|(
name|FunctionTemplateDecl
operator|*
name|FunctionTemplate
argument_list|,
name|llvm
operator|::
name|SmallVectorImpl
operator|<
name|DeducedTemplateArgument
operator|>
operator|&
name|Deduced
argument_list|,
name|unsigned
name|NumExplicitlySpecified
argument_list|,
name|FunctionDecl
operator|*
operator|&
name|Specialization
argument_list|,
name|TemplateDeductionInfo
operator|&
name|Info
argument_list|)
decl_stmt|;
end_decl_stmt

begin_function_decl
name|TemplateDeductionResult
name|DeduceTemplateArguments
parameter_list|(
name|FunctionTemplateDecl
modifier|*
name|FunctionTemplate
parameter_list|,
specifier|const
name|TemplateArgumentListInfo
modifier|*
name|ExplicitTemplateArgs
parameter_list|,
name|Expr
modifier|*
modifier|*
name|Args
parameter_list|,
name|unsigned
name|NumArgs
parameter_list|,
name|FunctionDecl
modifier|*
modifier|&
name|Specialization
parameter_list|,
name|TemplateDeductionInfo
modifier|&
name|Info
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|TemplateDeductionResult
name|DeduceTemplateArguments
parameter_list|(
name|FunctionTemplateDecl
modifier|*
name|FunctionTemplate
parameter_list|,
specifier|const
name|TemplateArgumentListInfo
modifier|*
name|ExplicitTemplateArgs
parameter_list|,
name|QualType
name|ArgFunctionType
parameter_list|,
name|FunctionDecl
modifier|*
modifier|&
name|Specialization
parameter_list|,
name|TemplateDeductionInfo
modifier|&
name|Info
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|TemplateDeductionResult
name|DeduceTemplateArguments
parameter_list|(
name|FunctionTemplateDecl
modifier|*
name|FunctionTemplate
parameter_list|,
name|QualType
name|ToType
parameter_list|,
name|CXXConversionDecl
modifier|*
modifier|&
name|Specialization
parameter_list|,
name|TemplateDeductionInfo
modifier|&
name|Info
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|TemplateDeductionResult
name|DeduceTemplateArguments
parameter_list|(
name|FunctionTemplateDecl
modifier|*
name|FunctionTemplate
parameter_list|,
specifier|const
name|TemplateArgumentListInfo
modifier|*
name|ExplicitTemplateArgs
parameter_list|,
name|FunctionDecl
modifier|*
modifier|&
name|Specialization
parameter_list|,
name|TemplateDeductionInfo
modifier|&
name|Info
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|FunctionTemplateDecl
modifier|*
name|getMoreSpecializedTemplate
parameter_list|(
name|FunctionTemplateDecl
modifier|*
name|FT1
parameter_list|,
name|FunctionTemplateDecl
modifier|*
name|FT2
parameter_list|,
name|SourceLocation
name|Loc
parameter_list|,
name|TemplatePartialOrderingContext
name|TPOC
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|UnresolvedSetIterator
name|getMostSpecialized
parameter_list|(
name|UnresolvedSetIterator
name|SBegin
parameter_list|,
name|UnresolvedSetIterator
name|SEnd
parameter_list|,
name|TemplatePartialOrderingContext
name|TPOC
parameter_list|,
name|SourceLocation
name|Loc
parameter_list|,
specifier|const
name|PartialDiagnostic
modifier|&
name|NoneDiag
parameter_list|,
specifier|const
name|PartialDiagnostic
modifier|&
name|AmbigDiag
parameter_list|,
specifier|const
name|PartialDiagnostic
modifier|&
name|CandidateDiag
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ClassTemplatePartialSpecializationDecl
modifier|*
name|getMoreSpecializedPartialSpecialization
parameter_list|(
name|ClassTemplatePartialSpecializationDecl
modifier|*
name|PS1
parameter_list|,
name|ClassTemplatePartialSpecializationDecl
modifier|*
name|PS2
parameter_list|,
name|SourceLocation
name|Loc
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
name|void
name|MarkUsedTemplateParameters
argument_list|(
specifier|const
name|TemplateArgumentList
operator|&
name|TemplateArgs
argument_list|,
name|bool
name|OnlyDeduced
argument_list|,
name|unsigned
name|Depth
argument_list|,
name|llvm
operator|::
name|SmallVectorImpl
operator|<
name|bool
operator|>
operator|&
name|Used
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|MarkDeducedTemplateParameters
argument_list|(
name|FunctionTemplateDecl
operator|*
name|FunctionTemplate
argument_list|,
name|llvm
operator|::
name|SmallVectorImpl
operator|<
name|bool
operator|>
operator|&
name|Deduced
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|//===--------------------------------------------------------------------===//
end_comment

begin_comment
comment|// C++ Template Instantiation
end_comment

begin_comment
comment|//
end_comment

begin_function_decl
name|MultiLevelTemplateArgumentList
name|getTemplateInstantiationArgs
parameter_list|(
name|NamedDecl
modifier|*
name|D
parameter_list|,
specifier|const
name|TemplateArgumentList
modifier|*
name|Innermost
init|=
literal|0
parameter_list|,
name|bool
name|RelativeToPrimary
init|=
name|false
parameter_list|,
specifier|const
name|FunctionDecl
modifier|*
name|Pattern
init|=
literal|0
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// \brief A template instantiation that is currently in progress.
end_comment

begin_struct
struct|struct
name|ActiveTemplateInstantiation
block|{
comment|/// \brief The kind of template instantiation we are performing
enum|enum
name|InstantiationKind
block|{
comment|/// We are instantiating a template declaration. The entity is
comment|/// the declaration we're instantiating (e.g., a CXXRecordDecl).
name|TemplateInstantiation
block|,
comment|/// We are instantiating a default argument for a template
comment|/// parameter. The Entity is the template, and
comment|/// TemplateArgs/NumTemplateArguments provides the template
comment|/// arguments as specified.
comment|/// FIXME: Use a TemplateArgumentList
name|DefaultTemplateArgumentInstantiation
block|,
comment|/// We are instantiating a default argument for a function.
comment|/// The Entity is the ParmVarDecl, and TemplateArgs/NumTemplateArgs
comment|/// provides the template arguments as specified.
name|DefaultFunctionArgumentInstantiation
block|,
comment|/// We are substituting explicit template arguments provided for
comment|/// a function template. The entity is a FunctionTemplateDecl.
name|ExplicitTemplateArgumentSubstitution
block|,
comment|/// We are substituting template argument determined as part of
comment|/// template argument deduction for either a class template
comment|/// partial specialization or a function template. The
comment|/// Entity is either a ClassTemplatePartialSpecializationDecl or
comment|/// a FunctionTemplateDecl.
name|DeducedTemplateArgumentSubstitution
block|,
comment|/// We are substituting prior template arguments into a new
comment|/// template parameter. The template parameter itself is either a
comment|/// NonTypeTemplateParmDecl or a TemplateTemplateParmDecl.
name|PriorTemplateArgumentSubstitution
block|,
comment|/// We are checking the validity of a default template argument that
comment|/// has been used when naming a template-id.
name|DefaultTemplateArgumentChecking
block|}
name|Kind
enum|;
comment|/// \brief The point of instantiation within the source code.
name|SourceLocation
name|PointOfInstantiation
decl_stmt|;
comment|/// \brief The template in which we are performing the instantiation,
comment|/// for substitutions of prior template arguments.
name|TemplateDecl
modifier|*
name|Template
decl_stmt|;
comment|/// \brief The entity that is being instantiated.
name|uintptr_t
name|Entity
decl_stmt|;
comment|/// \brief The list of template arguments we are substituting, if they
comment|/// are not part of the entity.
specifier|const
name|TemplateArgument
modifier|*
name|TemplateArgs
decl_stmt|;
comment|/// \brief The number of template arguments in TemplateArgs.
name|unsigned
name|NumTemplateArgs
decl_stmt|;
comment|/// \brief The source range that covers the construct that cause
comment|/// the instantiation, e.g., the template-id that causes a class
comment|/// template instantiation.
name|SourceRange
name|InstantiationRange
decl_stmt|;
name|ActiveTemplateInstantiation
argument_list|()
operator|:
name|Kind
argument_list|(
name|TemplateInstantiation
argument_list|)
operator|,
name|Template
argument_list|(
literal|0
argument_list|)
operator|,
name|Entity
argument_list|(
literal|0
argument_list|)
operator|,
name|TemplateArgs
argument_list|(
literal|0
argument_list|)
operator|,
name|NumTemplateArgs
argument_list|(
literal|0
argument_list|)
block|{}
comment|/// \brief Determines whether this template is an actual instantiation
comment|/// that should be counted toward the maximum instantiation depth.
name|bool
name|isInstantiationRecord
argument_list|()
specifier|const
expr_stmt|;
name|friend
name|bool
name|operator
operator|==
operator|(
specifier|const
name|ActiveTemplateInstantiation
operator|&
name|X
operator|,
specifier|const
name|ActiveTemplateInstantiation
operator|&
name|Y
operator|)
block|{
if|if
condition|(
name|X
operator|.
name|Kind
operator|!=
name|Y
operator|.
name|Kind
condition|)
return|return
name|false
return|;
if|if
condition|(
name|X
operator|.
name|Entity
operator|!=
name|Y
operator|.
name|Entity
condition|)
return|return
name|false
return|;
switch|switch
condition|(
name|X
operator|.
name|Kind
condition|)
block|{
case|case
name|TemplateInstantiation
case|:
return|return
name|true
return|;
case|case
name|PriorTemplateArgumentSubstitution
case|:
case|case
name|DefaultTemplateArgumentChecking
case|:
if|if
condition|(
name|X
operator|.
name|Template
operator|!=
name|Y
operator|.
name|Template
condition|)
return|return
name|false
return|;
comment|// Fall through
case|case
name|DefaultTemplateArgumentInstantiation
case|:
case|case
name|ExplicitTemplateArgumentSubstitution
case|:
case|case
name|DeducedTemplateArgumentSubstitution
case|:
case|case
name|DefaultFunctionArgumentInstantiation
case|:
return|return
name|X
operator|.
name|TemplateArgs
operator|==
name|Y
operator|.
name|TemplateArgs
return|;
block|}
return|return
name|true
return|;
block|}
name|friend
name|bool
name|operator
decl|!=
argument_list|(
specifier|const
name|ActiveTemplateInstantiation
operator|&
name|X
argument_list|,
specifier|const
name|ActiveTemplateInstantiation
operator|&
name|Y
argument_list|)
block|{
return|return
operator|!
operator|(
name|X
operator|==
name|Y
operator|)
return|;
block|}
end_struct

begin_comment
unit|};
comment|/// \brief List of active template instantiations.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This vector is treated as a stack. As one template instantiation
end_comment

begin_comment
comment|/// requires another template instantiation, additional
end_comment

begin_comment
comment|/// instantiations are pushed onto the stack up to a
end_comment

begin_comment
comment|/// user-configurable limit LangOptions::InstantiationDepth.
end_comment

begin_expr_stmt
name|llvm
operator|::
name|SmallVector
operator|<
name|ActiveTemplateInstantiation
operator|,
literal|16
operator|>
name|ActiveTemplateInstantiations
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// \brief The number of ActiveTemplateInstantiation entries in
end_comment

begin_comment
comment|/// \c ActiveTemplateInstantiations that are not actual instantiations and,
end_comment

begin_comment
comment|/// therefore, should not be counted as part of the instantiation depth.
end_comment

begin_decl_stmt
name|unsigned
name|NonInstantiationEntries
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// \brief The last template from which a template instantiation
end_comment

begin_comment
comment|/// error or warning was produced.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This value is used to suppress printing of redundant template
end_comment

begin_comment
comment|/// instantiation backtraces when there are multiple errors in the
end_comment

begin_comment
comment|/// same instantiation. FIXME: Does this belong in Sema? It's tough
end_comment

begin_comment
comment|/// to implement it anywhere else.
end_comment

begin_decl_stmt
name|ActiveTemplateInstantiation
name|LastTemplateInstantiationErrorContext
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// \brief The stack of calls expression undergoing template instantiation.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// The top of this stack is used by a fixit instantiating unresolved
end_comment

begin_comment
comment|/// function calls to fix the AST to match the textual change it prints.
end_comment

begin_expr_stmt
name|llvm
operator|::
name|SmallVector
operator|<
name|CallExpr
operator|*
operator|,
literal|8
operator|>
name|CallsUndergoingInstantiation
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// \brief A stack object to be created when performing template
end_comment

begin_comment
comment|/// instantiation.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Construction of an object of type \c InstantiatingTemplate
end_comment

begin_comment
comment|/// pushes the current instantiation onto the stack of active
end_comment

begin_comment
comment|/// instantiations. If the size of this stack exceeds the maximum
end_comment

begin_comment
comment|/// number of recursive template instantiations, construction
end_comment

begin_comment
comment|/// produces an error and evaluates true.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Destruction of this object will pop the named instantiation off
end_comment

begin_comment
comment|/// the stack.
end_comment

begin_struct
struct|struct
name|InstantiatingTemplate
block|{
comment|/// \brief Note that we are instantiating a class template,
comment|/// function template, or a member thereof.
name|InstantiatingTemplate
argument_list|(
argument|Sema&SemaRef
argument_list|,
argument|SourceLocation PointOfInstantiation
argument_list|,
argument|Decl *Entity
argument_list|,
argument|SourceRange InstantiationRange = SourceRange()
argument_list|)
empty_stmt|;
comment|/// \brief Note that we are instantiating a default argument in a
comment|/// template-id.
name|InstantiatingTemplate
argument_list|(
argument|Sema&SemaRef
argument_list|,
argument|SourceLocation PointOfInstantiation
argument_list|,
argument|TemplateDecl *Template
argument_list|,
argument|const TemplateArgument *TemplateArgs
argument_list|,
argument|unsigned NumTemplateArgs
argument_list|,
argument|SourceRange InstantiationRange = SourceRange()
argument_list|)
empty_stmt|;
comment|/// \brief Note that we are instantiating a default argument in a
comment|/// template-id.
name|InstantiatingTemplate
argument_list|(
argument|Sema&SemaRef
argument_list|,
argument|SourceLocation PointOfInstantiation
argument_list|,
argument|FunctionTemplateDecl *FunctionTemplate
argument_list|,
argument|const TemplateArgument *TemplateArgs
argument_list|,
argument|unsigned NumTemplateArgs
argument_list|,
argument|ActiveTemplateInstantiation::InstantiationKind Kind
argument_list|,
argument|SourceRange InstantiationRange = SourceRange()
argument_list|)
empty_stmt|;
comment|/// \brief Note that we are instantiating as part of template
comment|/// argument deduction for a class template partial
comment|/// specialization.
name|InstantiatingTemplate
argument_list|(
argument|Sema&SemaRef
argument_list|,
argument|SourceLocation PointOfInstantiation
argument_list|,
argument|ClassTemplatePartialSpecializationDecl *PartialSpec
argument_list|,
argument|const TemplateArgument *TemplateArgs
argument_list|,
argument|unsigned NumTemplateArgs
argument_list|,
argument|SourceRange InstantiationRange = SourceRange()
argument_list|)
empty_stmt|;
name|InstantiatingTemplate
argument_list|(
argument|Sema&SemaRef
argument_list|,
argument|SourceLocation PointOfInstantiation
argument_list|,
argument|ParmVarDecl *Param
argument_list|,
argument|const TemplateArgument *TemplateArgs
argument_list|,
argument|unsigned NumTemplateArgs
argument_list|,
argument|SourceRange InstantiationRange = SourceRange()
argument_list|)
empty_stmt|;
comment|/// \brief Note that we are substituting prior template arguments into a
comment|/// non-type or template template parameter.
name|InstantiatingTemplate
argument_list|(
argument|Sema&SemaRef
argument_list|,
argument|SourceLocation PointOfInstantiation
argument_list|,
argument|TemplateDecl *Template
argument_list|,
argument|NonTypeTemplateParmDecl *Param
argument_list|,
argument|const TemplateArgument *TemplateArgs
argument_list|,
argument|unsigned NumTemplateArgs
argument_list|,
argument|SourceRange InstantiationRange
argument_list|)
empty_stmt|;
name|InstantiatingTemplate
argument_list|(
argument|Sema&SemaRef
argument_list|,
argument|SourceLocation PointOfInstantiation
argument_list|,
argument|TemplateDecl *Template
argument_list|,
argument|TemplateTemplateParmDecl *Param
argument_list|,
argument|const TemplateArgument *TemplateArgs
argument_list|,
argument|unsigned NumTemplateArgs
argument_list|,
argument|SourceRange InstantiationRange
argument_list|)
empty_stmt|;
comment|/// \brief Note that we are checking the default template argument
comment|/// against the template parameter for a given template-id.
name|InstantiatingTemplate
argument_list|(
argument|Sema&SemaRef
argument_list|,
argument|SourceLocation PointOfInstantiation
argument_list|,
argument|TemplateDecl *Template
argument_list|,
argument|NamedDecl *Param
argument_list|,
argument|const TemplateArgument *TemplateArgs
argument_list|,
argument|unsigned NumTemplateArgs
argument_list|,
argument|SourceRange InstantiationRange
argument_list|)
empty_stmt|;
comment|/// \brief Note that we have finished instantiating this template.
name|void
name|Clear
parameter_list|()
function_decl|;
operator|~
name|InstantiatingTemplate
argument_list|()
block|{
name|Clear
argument_list|()
block|; }
comment|/// \brief Determines whether we have exceeded the maximum
comment|/// recursive template instantiations.
name|operator
name|bool
argument_list|()
specifier|const
block|{
return|return
name|Invalid
return|;
block|}
name|private
label|:
name|Sema
modifier|&
name|SemaRef
decl_stmt|;
name|bool
name|Invalid
decl_stmt|;
name|bool
name|CheckInstantiationDepth
parameter_list|(
name|SourceLocation
name|PointOfInstantiation
parameter_list|,
name|SourceRange
name|InstantiationRange
parameter_list|)
function_decl|;
name|InstantiatingTemplate
argument_list|(
specifier|const
name|InstantiatingTemplate
operator|&
argument_list|)
expr_stmt|;
comment|// not implemented
name|InstantiatingTemplate
modifier|&
name|operator
init|=
operator|(
specifier|const
name|InstantiatingTemplate
operator|&
operator|)
decl_stmt|;
comment|// not implemented
block|}
struct|;
end_struct

begin_function_decl
name|void
name|PrintInstantiationStack
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/// \brief Determines whether we are currently in a context where
end_comment

begin_comment
comment|/// template argument substitution failures are not considered
end_comment

begin_comment
comment|/// errors.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// When this routine returns true, the emission of most diagnostics
end_comment

begin_comment
comment|/// will be suppressed and there will be no local error recovery.
end_comment

begin_function
name|bool
name|isSFINAEContext
parameter_list|()
function|const;
end_function

begin_comment
comment|/// \brief RAII class used to determine whether SFINAE has
end_comment

begin_comment
comment|/// trapped any errors that occur during template argument
end_comment

begin_comment
comment|/// deduction.
end_comment

begin_decl_stmt
name|class
name|SFINAETrap
block|{
name|Sema
modifier|&
name|SemaRef
decl_stmt|;
name|unsigned
name|PrevSFINAEErrors
decl_stmt|;
name|public
label|:
name|explicit
name|SFINAETrap
argument_list|(
name|Sema
operator|&
name|SemaRef
argument_list|)
operator|:
name|SemaRef
argument_list|(
name|SemaRef
argument_list|)
operator|,
name|PrevSFINAEErrors
argument_list|(
argument|SemaRef.NumSFINAEErrors
argument_list|)
block|{ }
operator|~
name|SFINAETrap
argument_list|()
block|{
name|SemaRef
operator|.
name|NumSFINAEErrors
operator|=
name|PrevSFINAEErrors
block|; }
comment|/// \brief Determine whether any SFINAE errors have been trapped.
name|bool
name|hasErrorOccurred
argument_list|()
specifier|const
block|{
return|return
name|SemaRef
operator|.
name|NumSFINAEErrors
operator|>
name|PrevSFINAEErrors
return|;
block|}
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|/// \brief RAII class that determines when any errors have occurred
end_comment

begin_comment
comment|/// between the time the instance was created and the time it was
end_comment

begin_comment
comment|/// queried.
end_comment

begin_decl_stmt
name|class
name|ErrorTrap
block|{
name|Sema
modifier|&
name|SemaRef
decl_stmt|;
name|unsigned
name|PrevErrors
decl_stmt|;
name|public
label|:
name|explicit
name|ErrorTrap
argument_list|(
name|Sema
operator|&
name|SemaRef
argument_list|)
operator|:
name|SemaRef
argument_list|(
name|SemaRef
argument_list|)
operator|,
name|PrevErrors
argument_list|(
argument|SemaRef.getDiagnostics().getNumErrors()
argument_list|)
block|{}
comment|/// \brief Determine whether any errors have occurred since this
comment|/// object instance was created.
name|bool
name|hasErrorOccurred
argument_list|()
specifier|const
block|{
return|return
name|SemaRef
operator|.
name|getDiagnostics
argument_list|()
operator|.
name|getNumErrors
argument_list|()
operator|>
name|PrevErrors
return|;
block|}
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|/// \brief A stack-allocated class that identifies which local
end_comment

begin_comment
comment|/// variable declaration instantiations are present in this scope.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// A new instance of this class type will be created whenever we
end_comment

begin_comment
comment|/// instantiate a new function declaration, which will have its own
end_comment

begin_comment
comment|/// set of parameter declarations.
end_comment

begin_decl_stmt
name|class
name|LocalInstantiationScope
block|{
comment|/// \brief Reference to the semantic analysis that is performing
comment|/// this template instantiation.
name|Sema
modifier|&
name|SemaRef
decl_stmt|;
comment|/// \brief A mapping from local declarations that occur
comment|/// within a template to their instantiations.
comment|///
comment|/// This mapping is used during instantiation to keep track of,
comment|/// e.g., function parameter and variable declarations. For example,
comment|/// given:
comment|///
comment|/// \code
comment|///   template<typename T> T add(T x, T y) { return x + y; }
comment|/// \endcode
comment|///
comment|/// when we instantiate add<int>, we will introduce a mapping from
comment|/// the ParmVarDecl for 'x' that occurs in the template to the
comment|/// instantiated ParmVarDecl for 'x'.
name|llvm
operator|::
name|DenseMap
operator|<
specifier|const
name|Decl
operator|*
operator|,
name|Decl
operator|*
operator|>
name|LocalDecls
expr_stmt|;
comment|/// \brief The outer scope, which contains local variable
comment|/// definitions from some other instantiation (that may not be
comment|/// relevant to this particular scope).
name|LocalInstantiationScope
modifier|*
name|Outer
decl_stmt|;
comment|/// \brief Whether we have already exited this scope.
name|bool
name|Exited
decl_stmt|;
comment|/// \brief Whether to combine this scope with the outer scope, such that
comment|/// lookup will search our outer scope.
name|bool
name|CombineWithOuterScope
decl_stmt|;
comment|// This class is non-copyable
name|LocalInstantiationScope
argument_list|(
specifier|const
name|LocalInstantiationScope
operator|&
argument_list|)
expr_stmt|;
name|LocalInstantiationScope
modifier|&
name|operator
init|=
operator|(
specifier|const
name|LocalInstantiationScope
operator|&
operator|)
decl_stmt|;
name|public
label|:
name|LocalInstantiationScope
argument_list|(
argument|Sema&SemaRef
argument_list|,
argument|bool CombineWithOuterScope = false
argument_list|)
block|:
name|SemaRef
argument_list|(
name|SemaRef
argument_list|)
operator|,
name|Outer
argument_list|(
name|SemaRef
operator|.
name|CurrentInstantiationScope
argument_list|)
operator|,
name|Exited
argument_list|(
name|false
argument_list|)
operator|,
name|CombineWithOuterScope
argument_list|(
argument|CombineWithOuterScope
argument_list|)
block|{
name|SemaRef
operator|.
name|CurrentInstantiationScope
operator|=
name|this
block|;     }
operator|~
name|LocalInstantiationScope
argument_list|()
block|{
name|Exit
argument_list|()
block|;     }
comment|/// \brief Exit this local instantiation scope early.
name|void
name|Exit
argument_list|()
block|{
if|if
condition|(
name|Exited
condition|)
return|return;
name|SemaRef
operator|.
name|CurrentInstantiationScope
operator|=
name|Outer
expr_stmt|;
name|Exited
operator|=
name|true
expr_stmt|;
block|}
end_decl_stmt

begin_function_decl
name|Decl
modifier|*
name|getInstantiationOf
parameter_list|(
specifier|const
name|Decl
modifier|*
name|D
parameter_list|)
function_decl|;
end_function_decl

begin_function
name|VarDecl
modifier|*
name|getInstantiationOf
parameter_list|(
specifier|const
name|VarDecl
modifier|*
name|Var
parameter_list|)
block|{
return|return
name|cast
operator|<
name|VarDecl
operator|>
operator|(
name|getInstantiationOf
argument_list|(
name|cast
operator|<
name|Decl
operator|>
operator|(
name|Var
operator|)
argument_list|)
operator|)
return|;
block|}
end_function

begin_function
name|ParmVarDecl
modifier|*
name|getInstantiationOf
parameter_list|(
specifier|const
name|ParmVarDecl
modifier|*
name|Var
parameter_list|)
block|{
return|return
name|cast
operator|<
name|ParmVarDecl
operator|>
operator|(
name|getInstantiationOf
argument_list|(
name|cast
operator|<
name|Decl
operator|>
operator|(
name|Var
operator|)
argument_list|)
operator|)
return|;
block|}
end_function

begin_function
name|NonTypeTemplateParmDecl
modifier|*
name|getInstantiationOf
parameter_list|(
specifier|const
name|NonTypeTemplateParmDecl
modifier|*
name|Var
parameter_list|)
block|{
return|return
name|cast
operator|<
name|NonTypeTemplateParmDecl
operator|>
operator|(
name|getInstantiationOf
argument_list|(
name|cast
operator|<
name|Decl
operator|>
operator|(
name|Var
operator|)
argument_list|)
operator|)
return|;
block|}
end_function

begin_function_decl
name|void
name|InstantiatedLocal
parameter_list|(
specifier|const
name|Decl
modifier|*
name|D
parameter_list|,
name|Decl
modifier|*
name|Inst
parameter_list|)
function_decl|;
end_function_decl

begin_comment
unit|};
comment|/// \brief The current instantiation scope used to store local
end_comment

begin_comment
comment|/// variables.
end_comment

begin_decl_stmt
name|LocalInstantiationScope
modifier|*
name|CurrentInstantiationScope
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// \brief The number of typos corrected by CorrectTypo.
end_comment

begin_decl_stmt
name|unsigned
name|TyposCorrected
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// \brief Worker object for performing CFG-based warnings.
end_comment

begin_expr_stmt
name|sema
operator|::
name|AnalysisBasedWarnings
name|AnalysisWarnings
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// \brief An entity for which implicit template instantiation is required.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// The source location associated with the declaration is the first place in
end_comment

begin_comment
comment|/// the source code where the declaration was "used". It is not necessarily
end_comment

begin_comment
comment|/// the point of instantiation (which will be either before or after the
end_comment

begin_comment
comment|/// namespace-scope declaration that triggered this implicit instantiation),
end_comment

begin_comment
comment|/// However, it is the location that diagnostics should generally refer to,
end_comment

begin_comment
comment|/// because users will need to know what code triggered the instantiation.
end_comment

begin_typedef
typedef|typedef
name|std
operator|::
name|pair
operator|<
name|ValueDecl
operator|*
operator|,
name|SourceLocation
operator|>
name|PendingImplicitInstantiation
expr_stmt|;
end_typedef

begin_comment
comment|/// \brief The queue of implicit template instantiations that are required
end_comment

begin_comment
comment|/// but have not yet been performed.
end_comment

begin_expr_stmt
name|std
operator|::
name|deque
operator|<
name|PendingImplicitInstantiation
operator|>
name|PendingImplicitInstantiations
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// \brief The queue of implicit template instantiations that are required
end_comment

begin_comment
comment|/// and must be performed within the current local scope.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This queue is only used for member functions of local classes in
end_comment

begin_comment
comment|/// templates, which must be instantiated in the same scope as their
end_comment

begin_comment
comment|/// enclosing function, so that they can reference function-local
end_comment

begin_comment
comment|/// types, static variables, enumerators, etc.
end_comment

begin_expr_stmt
name|std
operator|::
name|deque
operator|<
name|PendingImplicitInstantiation
operator|>
name|PendingLocalImplicitInstantiations
expr_stmt|;
end_expr_stmt

begin_function_decl
name|void
name|PerformPendingImplicitInstantiations
parameter_list|(
name|bool
name|LocalOnly
init|=
name|false
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|TypeSourceInfo
modifier|*
name|SubstType
parameter_list|(
name|TypeSourceInfo
modifier|*
name|T
parameter_list|,
specifier|const
name|MultiLevelTemplateArgumentList
modifier|&
name|TemplateArgs
parameter_list|,
name|SourceLocation
name|Loc
parameter_list|,
name|DeclarationName
name|Entity
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|QualType
name|SubstType
parameter_list|(
name|QualType
name|T
parameter_list|,
specifier|const
name|MultiLevelTemplateArgumentList
modifier|&
name|TemplateArgs
parameter_list|,
name|SourceLocation
name|Loc
parameter_list|,
name|DeclarationName
name|Entity
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|TypeSourceInfo
modifier|*
name|SubstFunctionDeclType
parameter_list|(
name|TypeSourceInfo
modifier|*
name|T
parameter_list|,
specifier|const
name|MultiLevelTemplateArgumentList
modifier|&
name|TemplateArgs
parameter_list|,
name|SourceLocation
name|Loc
parameter_list|,
name|DeclarationName
name|Entity
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ParmVarDecl
modifier|*
name|SubstParmVarDecl
parameter_list|(
name|ParmVarDecl
modifier|*
name|D
parameter_list|,
specifier|const
name|MultiLevelTemplateArgumentList
modifier|&
name|TemplateArgs
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|OwningExprResult
name|SubstExpr
parameter_list|(
name|Expr
modifier|*
name|E
parameter_list|,
specifier|const
name|MultiLevelTemplateArgumentList
modifier|&
name|TemplateArgs
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|OwningStmtResult
name|SubstStmt
parameter_list|(
name|Stmt
modifier|*
name|S
parameter_list|,
specifier|const
name|MultiLevelTemplateArgumentList
modifier|&
name|TemplateArgs
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|Decl
modifier|*
name|SubstDecl
parameter_list|(
name|Decl
modifier|*
name|D
parameter_list|,
name|DeclContext
modifier|*
name|Owner
parameter_list|,
specifier|const
name|MultiLevelTemplateArgumentList
modifier|&
name|TemplateArgs
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|SubstBaseSpecifiers
parameter_list|(
name|CXXRecordDecl
modifier|*
name|Instantiation
parameter_list|,
name|CXXRecordDecl
modifier|*
name|Pattern
parameter_list|,
specifier|const
name|MultiLevelTemplateArgumentList
modifier|&
name|TemplateArgs
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|InstantiateClass
parameter_list|(
name|SourceLocation
name|PointOfInstantiation
parameter_list|,
name|CXXRecordDecl
modifier|*
name|Instantiation
parameter_list|,
name|CXXRecordDecl
modifier|*
name|Pattern
parameter_list|,
specifier|const
name|MultiLevelTemplateArgumentList
modifier|&
name|TemplateArgs
parameter_list|,
name|TemplateSpecializationKind
name|TSK
parameter_list|,
name|bool
name|Complain
init|=
name|true
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|InstantiateClassTemplateSpecialization
parameter_list|(
name|SourceLocation
name|PointOfInstantiation
parameter_list|,
name|ClassTemplateSpecializationDecl
modifier|*
name|ClassTemplateSpec
parameter_list|,
name|TemplateSpecializationKind
name|TSK
parameter_list|,
name|bool
name|Complain
init|=
name|true
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|InstantiateClassMembers
parameter_list|(
name|SourceLocation
name|PointOfInstantiation
parameter_list|,
name|CXXRecordDecl
modifier|*
name|Instantiation
parameter_list|,
specifier|const
name|MultiLevelTemplateArgumentList
modifier|&
name|TemplateArgs
parameter_list|,
name|TemplateSpecializationKind
name|TSK
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|InstantiateClassTemplateSpecializationMembers
parameter_list|(
name|SourceLocation
name|PointOfInstantiation
parameter_list|,
name|ClassTemplateSpecializationDecl
modifier|*
name|ClassTemplateSpec
parameter_list|,
name|TemplateSpecializationKind
name|TSK
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|NestedNameSpecifier
modifier|*
name|SubstNestedNameSpecifier
parameter_list|(
name|NestedNameSpecifier
modifier|*
name|NNS
parameter_list|,
name|SourceRange
name|Range
parameter_list|,
specifier|const
name|MultiLevelTemplateArgumentList
modifier|&
name|TemplateArgs
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|TemplateName
name|SubstTemplateName
parameter_list|(
name|TemplateName
name|Name
parameter_list|,
name|SourceLocation
name|Loc
parameter_list|,
specifier|const
name|MultiLevelTemplateArgumentList
modifier|&
name|TemplateArgs
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|Subst
parameter_list|(
specifier|const
name|TemplateArgumentLoc
modifier|&
name|Arg
parameter_list|,
name|TemplateArgumentLoc
modifier|&
name|Result
parameter_list|,
specifier|const
name|MultiLevelTemplateArgumentList
modifier|&
name|TemplateArgs
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|InstantiateFunctionDefinition
parameter_list|(
name|SourceLocation
name|PointOfInstantiation
parameter_list|,
name|FunctionDecl
modifier|*
name|Function
parameter_list|,
name|bool
name|Recursive
init|=
name|false
parameter_list|,
name|bool
name|DefinitionRequired
init|=
name|false
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|InstantiateStaticDataMemberDefinition
parameter_list|(
name|SourceLocation
name|PointOfInstantiation
parameter_list|,
name|VarDecl
modifier|*
name|Var
parameter_list|,
name|bool
name|Recursive
init|=
name|false
parameter_list|,
name|bool
name|DefinitionRequired
init|=
name|false
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|InstantiateMemInitializers
parameter_list|(
name|CXXConstructorDecl
modifier|*
name|New
parameter_list|,
specifier|const
name|CXXConstructorDecl
modifier|*
name|Tmpl
parameter_list|,
specifier|const
name|MultiLevelTemplateArgumentList
modifier|&
name|TemplateArgs
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|NamedDecl
modifier|*
name|FindInstantiatedDecl
parameter_list|(
name|SourceLocation
name|Loc
parameter_list|,
name|NamedDecl
modifier|*
name|D
parameter_list|,
specifier|const
name|MultiLevelTemplateArgumentList
modifier|&
name|TemplateArgs
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|DeclContext
modifier|*
name|FindInstantiatedContext
parameter_list|(
name|SourceLocation
name|Loc
parameter_list|,
name|DeclContext
modifier|*
name|DC
parameter_list|,
specifier|const
name|MultiLevelTemplateArgumentList
modifier|&
name|TemplateArgs
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|// Objective-C declarations.
end_comment

begin_function_decl
name|virtual
name|DeclPtrTy
name|ActOnStartClassInterface
parameter_list|(
name|SourceLocation
name|AtInterfaceLoc
parameter_list|,
name|IdentifierInfo
modifier|*
name|ClassName
parameter_list|,
name|SourceLocation
name|ClassLoc
parameter_list|,
name|IdentifierInfo
modifier|*
name|SuperName
parameter_list|,
name|SourceLocation
name|SuperLoc
parameter_list|,
specifier|const
name|DeclPtrTy
modifier|*
name|ProtoRefs
parameter_list|,
name|unsigned
name|NumProtoRefs
parameter_list|,
specifier|const
name|SourceLocation
modifier|*
name|ProtoLocs
parameter_list|,
name|SourceLocation
name|EndProtoLoc
parameter_list|,
name|AttributeList
modifier|*
name|AttrList
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|virtual
name|DeclPtrTy
name|ActOnCompatiblityAlias
parameter_list|(
name|SourceLocation
name|AtCompatibilityAliasLoc
parameter_list|,
name|IdentifierInfo
modifier|*
name|AliasName
parameter_list|,
name|SourceLocation
name|AliasLocation
parameter_list|,
name|IdentifierInfo
modifier|*
name|ClassName
parameter_list|,
name|SourceLocation
name|ClassLocation
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
name|void
name|CheckForwardProtocolDeclarationForCircularDependency
argument_list|(
name|IdentifierInfo
operator|*
name|PName
argument_list|,
name|SourceLocation
operator|&
name|PLoc
argument_list|,
name|SourceLocation
name|PrevLoc
argument_list|,
specifier|const
name|ObjCList
operator|<
name|ObjCProtocolDecl
operator|>
operator|&
name|PList
argument_list|)
decl_stmt|;
end_decl_stmt

begin_function_decl
name|virtual
name|DeclPtrTy
name|ActOnStartProtocolInterface
parameter_list|(
name|SourceLocation
name|AtProtoInterfaceLoc
parameter_list|,
name|IdentifierInfo
modifier|*
name|ProtocolName
parameter_list|,
name|SourceLocation
name|ProtocolLoc
parameter_list|,
specifier|const
name|DeclPtrTy
modifier|*
name|ProtoRefNames
parameter_list|,
name|unsigned
name|NumProtoRefs
parameter_list|,
specifier|const
name|SourceLocation
modifier|*
name|ProtoLocs
parameter_list|,
name|SourceLocation
name|EndProtoLoc
parameter_list|,
name|AttributeList
modifier|*
name|AttrList
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|virtual
name|DeclPtrTy
name|ActOnStartCategoryInterface
parameter_list|(
name|SourceLocation
name|AtInterfaceLoc
parameter_list|,
name|IdentifierInfo
modifier|*
name|ClassName
parameter_list|,
name|SourceLocation
name|ClassLoc
parameter_list|,
name|IdentifierInfo
modifier|*
name|CategoryName
parameter_list|,
name|SourceLocation
name|CategoryLoc
parameter_list|,
specifier|const
name|DeclPtrTy
modifier|*
name|ProtoRefs
parameter_list|,
name|unsigned
name|NumProtoRefs
parameter_list|,
specifier|const
name|SourceLocation
modifier|*
name|ProtoLocs
parameter_list|,
name|SourceLocation
name|EndProtoLoc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|virtual
name|DeclPtrTy
name|ActOnStartClassImplementation
parameter_list|(
name|SourceLocation
name|AtClassImplLoc
parameter_list|,
name|IdentifierInfo
modifier|*
name|ClassName
parameter_list|,
name|SourceLocation
name|ClassLoc
parameter_list|,
name|IdentifierInfo
modifier|*
name|SuperClassname
parameter_list|,
name|SourceLocation
name|SuperClassLoc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|virtual
name|DeclPtrTy
name|ActOnStartCategoryImplementation
parameter_list|(
name|SourceLocation
name|AtCatImplLoc
parameter_list|,
name|IdentifierInfo
modifier|*
name|ClassName
parameter_list|,
name|SourceLocation
name|ClassLoc
parameter_list|,
name|IdentifierInfo
modifier|*
name|CatName
parameter_list|,
name|SourceLocation
name|CatLoc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|virtual
name|DeclPtrTy
name|ActOnForwardClassDeclaration
parameter_list|(
name|SourceLocation
name|Loc
parameter_list|,
name|IdentifierInfo
modifier|*
modifier|*
name|IdentList
parameter_list|,
name|SourceLocation
modifier|*
name|IdentLocs
parameter_list|,
name|unsigned
name|NumElts
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|virtual
name|DeclPtrTy
name|ActOnForwardProtocolDeclaration
parameter_list|(
name|SourceLocation
name|AtProtocolLoc
parameter_list|,
specifier|const
name|IdentifierLocPair
modifier|*
name|IdentList
parameter_list|,
name|unsigned
name|NumElts
parameter_list|,
name|AttributeList
modifier|*
name|attrList
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
name|virtual
name|void
name|FindProtocolDeclaration
argument_list|(
name|bool
name|WarnOnDeclarations
argument_list|,
specifier|const
name|IdentifierLocPair
operator|*
name|ProtocolId
argument_list|,
name|unsigned
name|NumProtocols
argument_list|,
name|llvm
operator|::
name|SmallVectorImpl
operator|<
name|DeclPtrTy
operator|>
operator|&
name|Protocols
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// Ensure attributes are consistent with type.
end_comment

begin_comment
comment|/// \param [in, out] Attributes The attributes to check; they will
end_comment

begin_comment
comment|/// be modified to be consistent with \arg PropertyTy.
end_comment

begin_function_decl
name|void
name|CheckObjCPropertyAttributes
parameter_list|(
name|DeclPtrTy
name|PropertyPtrTy
parameter_list|,
name|SourceLocation
name|Loc
parameter_list|,
name|unsigned
modifier|&
name|Attributes
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ProcessPropertyDecl
parameter_list|(
name|ObjCPropertyDecl
modifier|*
name|property
parameter_list|,
name|ObjCContainerDecl
modifier|*
name|DC
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|DiagnosePropertyMismatch
parameter_list|(
name|ObjCPropertyDecl
modifier|*
name|Property
parameter_list|,
name|ObjCPropertyDecl
modifier|*
name|SuperProperty
parameter_list|,
specifier|const
name|IdentifierInfo
modifier|*
name|Name
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ComparePropertiesInBaseAndSuper
parameter_list|(
name|ObjCInterfaceDecl
modifier|*
name|IDecl
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|CompareMethodParamsInBaseAndSuper
parameter_list|(
name|Decl
modifier|*
name|IDecl
parameter_list|,
name|ObjCMethodDecl
modifier|*
name|MethodDecl
parameter_list|,
name|bool
name|IsInstance
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|CompareProperties
parameter_list|(
name|Decl
modifier|*
name|CDecl
parameter_list|,
name|DeclPtrTy
name|MergeProtocols
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|DiagnoseClassExtensionDupMethods
parameter_list|(
name|ObjCCategoryDecl
modifier|*
name|CAT
parameter_list|,
name|ObjCInterfaceDecl
modifier|*
name|ID
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|MatchOneProtocolPropertiesInClass
parameter_list|(
name|Decl
modifier|*
name|CDecl
parameter_list|,
name|ObjCProtocolDecl
modifier|*
name|PDecl
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|virtual
name|void
name|ActOnAtEnd
parameter_list|(
name|Scope
modifier|*
name|S
parameter_list|,
name|SourceRange
name|AtEnd
parameter_list|,
name|DeclPtrTy
name|classDecl
parameter_list|,
name|DeclPtrTy
modifier|*
name|allMethods
init|=
literal|0
parameter_list|,
name|unsigned
name|allNum
init|=
literal|0
parameter_list|,
name|DeclPtrTy
modifier|*
name|allProperties
init|=
literal|0
parameter_list|,
name|unsigned
name|pNum
init|=
literal|0
parameter_list|,
name|DeclGroupPtrTy
modifier|*
name|allTUVars
init|=
literal|0
parameter_list|,
name|unsigned
name|tuvNum
init|=
literal|0
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
name|virtual
name|DeclPtrTy
name|ActOnProperty
argument_list|(
name|Scope
operator|*
name|S
argument_list|,
name|SourceLocation
name|AtLoc
argument_list|,
name|FieldDeclarator
operator|&
name|FD
argument_list|,
name|ObjCDeclSpec
operator|&
name|ODS
argument_list|,
name|Selector
name|GetterSel
argument_list|,
name|Selector
name|SetterSel
argument_list|,
name|DeclPtrTy
name|ClassCategory
argument_list|,
name|bool
operator|*
name|OverridingProperty
argument_list|,
name|tok
operator|::
name|ObjCKeywordKind
name|MethodImplKind
argument_list|)
decl_stmt|;
end_decl_stmt

begin_function_decl
name|virtual
name|DeclPtrTy
name|ActOnPropertyImplDecl
parameter_list|(
name|Scope
modifier|*
name|S
parameter_list|,
name|SourceLocation
name|AtLoc
parameter_list|,
name|SourceLocation
name|PropertyLoc
parameter_list|,
name|bool
name|ImplKind
parameter_list|,
name|DeclPtrTy
name|ClassImplDecl
parameter_list|,
name|IdentifierInfo
modifier|*
name|PropertyId
parameter_list|,
name|IdentifierInfo
modifier|*
name|PropertyIvar
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
name|virtual
name|DeclPtrTy
name|ActOnMethodDeclaration
argument_list|(
name|SourceLocation
name|BeginLoc
argument_list|,
comment|// location of the + or -.
name|SourceLocation
name|EndLoc
argument_list|,
comment|// location of the ; or {.
name|tok
operator|::
name|TokenKind
name|MethodType
argument_list|,
name|DeclPtrTy
name|ClassDecl
argument_list|,
name|ObjCDeclSpec
operator|&
name|ReturnQT
argument_list|,
name|TypeTy
operator|*
name|ReturnType
argument_list|,
name|Selector
name|Sel
argument_list|,
comment|// optional arguments. The number of types/arguments is obtained
comment|// from the Sel.getNumArgs().
name|ObjCArgInfo
operator|*
name|ArgInfo
argument_list|,
name|DeclaratorChunk
operator|::
name|ParamInfo
operator|*
name|CParamInfo
argument_list|,
name|unsigned
name|CNumArgs
argument_list|,
comment|// c-style args
name|AttributeList
operator|*
name|AttrList
argument_list|,
name|tok
operator|::
name|ObjCKeywordKind
name|MethodImplKind
argument_list|,
name|bool
name|isVariadic
operator|=
name|false
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|// Helper method for ActOnClassMethod/ActOnInstanceMethod.
end_comment

begin_comment
comment|// Will search "local" class/category implementations for a method decl.
end_comment

begin_comment
comment|// Will also search in class's root looking for instance method.
end_comment

begin_comment
comment|// Returns 0 if no method is found.
end_comment

begin_function_decl
name|ObjCMethodDecl
modifier|*
name|LookupPrivateClassMethod
parameter_list|(
name|Selector
name|Sel
parameter_list|,
name|ObjCInterfaceDecl
modifier|*
name|CDecl
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ObjCMethodDecl
modifier|*
name|LookupPrivateInstanceMethod
parameter_list|(
name|Selector
name|Sel
parameter_list|,
name|ObjCInterfaceDecl
modifier|*
name|ClassDecl
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|OwningExprResult
name|HandleExprPropertyRefExpr
parameter_list|(
specifier|const
name|ObjCObjectPointerType
modifier|*
name|OPT
parameter_list|,
name|Expr
modifier|*
name|BaseExpr
parameter_list|,
name|DeclarationName
name|MemberName
parameter_list|,
name|SourceLocation
name|MemberLoc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|virtual
name|OwningExprResult
name|ActOnClassPropertyRefExpr
parameter_list|(
name|IdentifierInfo
modifier|&
name|receiverName
parameter_list|,
name|IdentifierInfo
modifier|&
name|propertyName
parameter_list|,
name|SourceLocation
name|receiverNameLoc
parameter_list|,
name|SourceLocation
name|propertyNameLoc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|virtual
name|ObjCMessageKind
name|getObjCMessageKind
parameter_list|(
name|Scope
modifier|*
name|S
parameter_list|,
name|IdentifierInfo
modifier|*
name|Name
parameter_list|,
name|SourceLocation
name|NameLoc
parameter_list|,
name|bool
name|IsSuper
parameter_list|,
name|bool
name|HasTrailingDot
parameter_list|,
name|TypeTy
modifier|*
modifier|&
name|ReceiverType
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|virtual
name|OwningExprResult
name|ActOnSuperMessage
parameter_list|(
name|Scope
modifier|*
name|S
parameter_list|,
name|SourceLocation
name|SuperLoc
parameter_list|,
name|Selector
name|Sel
parameter_list|,
name|SourceLocation
name|LBracLoc
parameter_list|,
name|SourceLocation
name|SelectorLoc
parameter_list|,
name|SourceLocation
name|RBracLoc
parameter_list|,
name|MultiExprArg
name|Args
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|OwningExprResult
name|BuildClassMessage
parameter_list|(
name|TypeSourceInfo
modifier|*
name|ReceiverTypeInfo
parameter_list|,
name|QualType
name|ReceiverType
parameter_list|,
name|SourceLocation
name|SuperLoc
parameter_list|,
name|Selector
name|Sel
parameter_list|,
name|ObjCMethodDecl
modifier|*
name|Method
parameter_list|,
name|SourceLocation
name|LBracLoc
parameter_list|,
name|SourceLocation
name|RBracLoc
parameter_list|,
name|MultiExprArg
name|Args
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|virtual
name|OwningExprResult
name|ActOnClassMessage
parameter_list|(
name|Scope
modifier|*
name|S
parameter_list|,
name|TypeTy
modifier|*
name|Receiver
parameter_list|,
name|Selector
name|Sel
parameter_list|,
name|SourceLocation
name|LBracLoc
parameter_list|,
name|SourceLocation
name|SelectorLoc
parameter_list|,
name|SourceLocation
name|RBracLoc
parameter_list|,
name|MultiExprArg
name|Args
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|OwningExprResult
name|BuildInstanceMessage
parameter_list|(
name|ExprArg
name|Receiver
parameter_list|,
name|QualType
name|ReceiverType
parameter_list|,
name|SourceLocation
name|SuperLoc
parameter_list|,
name|Selector
name|Sel
parameter_list|,
name|ObjCMethodDecl
modifier|*
name|Method
parameter_list|,
name|SourceLocation
name|LBracLoc
parameter_list|,
name|SourceLocation
name|RBracLoc
parameter_list|,
name|MultiExprArg
name|Args
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|virtual
name|OwningExprResult
name|ActOnInstanceMessage
parameter_list|(
name|Scope
modifier|*
name|S
parameter_list|,
name|ExprArg
name|Receiver
parameter_list|,
name|Selector
name|Sel
parameter_list|,
name|SourceLocation
name|LBracLoc
parameter_list|,
name|SourceLocation
name|SelectorLoc
parameter_list|,
name|SourceLocation
name|RBracLoc
parameter_list|,
name|MultiExprArg
name|Args
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// ActOnPragmaOptionsAlign - Called on well formed #pragma options align.
end_comment

begin_function_decl
name|virtual
name|void
name|ActOnPragmaOptionsAlign
parameter_list|(
name|PragmaOptionsAlignKind
name|Kind
parameter_list|,
name|SourceLocation
name|PragmaLoc
parameter_list|,
name|SourceLocation
name|KindLoc
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// ActOnPragmaPack - Called on well formed #pragma pack(...).
end_comment

begin_function_decl
name|virtual
name|void
name|ActOnPragmaPack
parameter_list|(
name|PragmaPackKind
name|Kind
parameter_list|,
name|IdentifierInfo
modifier|*
name|Name
parameter_list|,
name|ExprTy
modifier|*
name|Alignment
parameter_list|,
name|SourceLocation
name|PragmaLoc
parameter_list|,
name|SourceLocation
name|LParenLoc
parameter_list|,
name|SourceLocation
name|RParenLoc
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// ActOnPragmaUnused - Called on well-formed '#pragma unused'.
end_comment

begin_function_decl
name|virtual
name|void
name|ActOnPragmaUnused
parameter_list|(
specifier|const
name|Token
modifier|*
name|Identifiers
parameter_list|,
name|unsigned
name|NumIdentifiers
parameter_list|,
name|Scope
modifier|*
name|curScope
parameter_list|,
name|SourceLocation
name|PragmaLoc
parameter_list|,
name|SourceLocation
name|LParenLoc
parameter_list|,
name|SourceLocation
name|RParenLoc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|NamedDecl
modifier|*
name|DeclClonePragmaWeak
parameter_list|(
name|NamedDecl
modifier|*
name|ND
parameter_list|,
name|IdentifierInfo
modifier|*
name|II
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|DeclApplyPragmaWeak
parameter_list|(
name|Scope
modifier|*
name|S
parameter_list|,
name|NamedDecl
modifier|*
name|ND
parameter_list|,
name|WeakInfo
modifier|&
name|W
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// ActOnPragmaWeakID - Called on well formed #pragma weak ident.
end_comment

begin_function_decl
name|virtual
name|void
name|ActOnPragmaWeakID
parameter_list|(
name|IdentifierInfo
modifier|*
name|WeakName
parameter_list|,
name|SourceLocation
name|PragmaLoc
parameter_list|,
name|SourceLocation
name|WeakNameLoc
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// ActOnPragmaWeakAlias - Called on well formed #pragma weak ident = ident.
end_comment

begin_function_decl
name|virtual
name|void
name|ActOnPragmaWeakAlias
parameter_list|(
name|IdentifierInfo
modifier|*
name|WeakName
parameter_list|,
name|IdentifierInfo
modifier|*
name|AliasName
parameter_list|,
name|SourceLocation
name|PragmaLoc
parameter_list|,
name|SourceLocation
name|WeakNameLoc
parameter_list|,
name|SourceLocation
name|AliasNameLoc
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// AddAlignmentAttributesForRecord - Adds any needed alignment attributes to
end_comment

begin_comment
comment|/// a the record decl, to handle '#pragma pack' and '#pragma options align'.
end_comment

begin_function_decl
name|void
name|AddAlignmentAttributesForRecord
parameter_list|(
name|RecordDecl
modifier|*
name|RD
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// FreePackedContext - Deallocate and null out PackContext.
end_comment

begin_function_decl
name|void
name|FreePackedContext
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/// AddAlignedAttr - Adds an aligned attribute to a particular declaration.
end_comment

begin_function_decl
name|void
name|AddAlignedAttr
parameter_list|(
name|SourceLocation
name|AttrLoc
parameter_list|,
name|Decl
modifier|*
name|D
parameter_list|,
name|Expr
modifier|*
name|E
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// ImpCastExprToType - If Expr is not of type 'Type', insert an implicit
end_comment

begin_comment
comment|/// cast.  If there is already an implicit cast, merge into the existing one.
end_comment

begin_comment
comment|/// If isLvalue, the result of the cast is an lvalue.
end_comment

begin_decl_stmt
name|void
name|ImpCastExprToType
argument_list|(
name|Expr
operator|*
operator|&
name|Expr
argument_list|,
name|QualType
name|Type
argument_list|,
name|CastExpr
operator|::
name|CastKind
name|Kind
argument_list|,
name|bool
name|isLvalue
operator|=
name|false
argument_list|,
name|CXXBaseSpecifierArray
name|BasePath
operator|=
name|CXXBaseSpecifierArray
argument_list|()
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|// UsualUnaryConversions - promotes integers (C99 6.3.1.1p2) and converts
end_comment

begin_comment
comment|// functions and arrays to their respective pointers (C99 6.3.2.1).
end_comment

begin_function_decl
name|Expr
modifier|*
name|UsualUnaryConversions
parameter_list|(
name|Expr
modifier|*
modifier|&
name|expr
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|// DefaultFunctionArrayConversion - converts functions and arrays
end_comment

begin_comment
comment|// to their respective pointers (C99 6.3.2.1).
end_comment

begin_function_decl
name|void
name|DefaultFunctionArrayConversion
parameter_list|(
name|Expr
modifier|*
modifier|&
name|expr
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|// DefaultFunctionArrayLvalueConversion - converts functions and
end_comment

begin_comment
comment|// arrays to their respective pointers and performs the
end_comment

begin_comment
comment|// lvalue-to-rvalue conversion.
end_comment

begin_function_decl
name|void
name|DefaultFunctionArrayLvalueConversion
parameter_list|(
name|Expr
modifier|*
modifier|&
name|expr
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|// DefaultArgumentPromotion (C99 6.5.2.2p6). Used for function calls that
end_comment

begin_comment
comment|// do not have a prototype. Integer promotions are performed on each
end_comment

begin_comment
comment|// argument, and arguments that have type float are promoted to double.
end_comment

begin_function_decl
name|void
name|DefaultArgumentPromotion
parameter_list|(
name|Expr
modifier|*
modifier|&
name|Expr
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|// Used for emitting the right warning by DefaultVariadicArgumentPromotion
end_comment

begin_enum
enum|enum
name|VariadicCallType
block|{
name|VariadicFunction
block|,
name|VariadicBlock
block|,
name|VariadicMethod
block|,
name|VariadicConstructor
block|,
name|VariadicDoesNotApply
block|}
enum|;
end_enum

begin_comment
comment|/// GatherArgumentsForCall - Collector argument expressions for various
end_comment

begin_comment
comment|/// form of call prototypes.
end_comment

begin_decl_stmt
name|bool
name|GatherArgumentsForCall
argument_list|(
name|SourceLocation
name|CallLoc
argument_list|,
name|FunctionDecl
operator|*
name|FDecl
argument_list|,
specifier|const
name|FunctionProtoType
operator|*
name|Proto
argument_list|,
name|unsigned
name|FirstProtoArg
argument_list|,
name|Expr
operator|*
operator|*
name|Args
argument_list|,
name|unsigned
name|NumArgs
argument_list|,
name|llvm
operator|::
name|SmallVector
operator|<
name|Expr
operator|*
argument_list|,
literal|8
operator|>
operator|&
name|AllArgs
argument_list|,
name|VariadicCallType
name|CallType
operator|=
name|VariadicDoesNotApply
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|// DefaultVariadicArgumentPromotion - Like DefaultArgumentPromotion, but
end_comment

begin_comment
comment|// will warn if the resulting type is not a POD type.
end_comment

begin_function_decl
name|bool
name|DefaultVariadicArgumentPromotion
parameter_list|(
name|Expr
modifier|*
modifier|&
name|Expr
parameter_list|,
name|VariadicCallType
name|CT
parameter_list|,
name|FunctionDecl
modifier|*
name|FDecl
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|// UsualArithmeticConversions - performs the UsualUnaryConversions on it's
end_comment

begin_comment
comment|// operands and then handles various conversions that are common to binary
end_comment

begin_comment
comment|// operators (C99 6.3.1.8). If both operands aren't arithmetic, this
end_comment

begin_comment
comment|// routine returns the first non-arithmetic type found. The client is
end_comment

begin_comment
comment|// responsible for emitting appropriate error diagnostics.
end_comment

begin_function_decl
name|QualType
name|UsualArithmeticConversions
parameter_list|(
name|Expr
modifier|*
modifier|&
name|lExpr
parameter_list|,
name|Expr
modifier|*
modifier|&
name|rExpr
parameter_list|,
name|bool
name|isCompAssign
init|=
name|false
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// AssignConvertType - All of the 'assignment' semantic checks return this
end_comment

begin_comment
comment|/// enum to indicate whether the assignment was allowed.  These checks are
end_comment

begin_comment
comment|/// done for simple assignments, as well as initialization, return from
end_comment

begin_comment
comment|/// function, argument passing, etc.  The query is phrased in terms of a
end_comment

begin_comment
comment|/// source and destination type.
end_comment

begin_enum
enum|enum
name|AssignConvertType
block|{
comment|/// Compatible - the types are compatible according to the standard.
name|Compatible
block|,
comment|/// PointerToInt - The assignment converts a pointer to an int, which we
comment|/// accept as an extension.
name|PointerToInt
block|,
comment|/// IntToPointer - The assignment converts an int to a pointer, which we
comment|/// accept as an extension.
name|IntToPointer
block|,
comment|/// FunctionVoidPointer - The assignment is between a function pointer and
comment|/// void*, which the standard doesn't allow, but we accept as an extension.
name|FunctionVoidPointer
block|,
comment|/// IncompatiblePointer - The assignment is between two pointers types that
comment|/// are not compatible, but we accept them as an extension.
name|IncompatiblePointer
block|,
comment|/// IncompatiblePointer - The assignment is between two pointers types which
comment|/// point to integers which have a different sign, but are otherwise identical.
comment|/// This is a subset of the above, but broken out because it's by far the most
comment|/// common case of incompatible pointers.
name|IncompatiblePointerSign
block|,
comment|/// CompatiblePointerDiscardsQualifiers - The assignment discards
comment|/// c/v/r qualifiers, which we accept as an extension.
name|CompatiblePointerDiscardsQualifiers
block|,
comment|/// IncompatibleNestedPointerQualifiers - The assignment is between two
comment|/// nested pointer types, and the qualifiers other than the first two
comment|/// levels differ e.g. char ** -> const char **, but we accept them as an
comment|/// extension.
name|IncompatibleNestedPointerQualifiers
block|,
comment|/// IncompatibleVectors - The assignment is between two vector types that
comment|/// have the same size, which we accept as an extension.
name|IncompatibleVectors
block|,
comment|/// IntToBlockPointer - The assignment converts an int to a block
comment|/// pointer. We disallow this.
name|IntToBlockPointer
block|,
comment|/// IncompatibleBlockPointer - The assignment is between two block
comment|/// pointers types that are not compatible.
name|IncompatibleBlockPointer
block|,
comment|/// IncompatibleObjCQualifiedId - The assignment is between a qualified
comment|/// id type and something else (that is incompatible with it). For example,
comment|/// "id<XXX>" = "Foo *", where "Foo *" doesn't implement the XXX protocol.
name|IncompatibleObjCQualifiedId
block|,
comment|/// Incompatible - We reject this conversion outright, it is invalid to
comment|/// represent it in the AST.
name|Incompatible
block|}
enum|;
end_enum

begin_comment
comment|/// DiagnoseAssignmentResult - Emit a diagnostic, if required, for the
end_comment

begin_comment
comment|/// assignment conversion type specified by ConvTy.  This returns true if the
end_comment

begin_comment
comment|/// conversion was invalid or false if the conversion was accepted.
end_comment

begin_function_decl
name|bool
name|DiagnoseAssignmentResult
parameter_list|(
name|AssignConvertType
name|ConvTy
parameter_list|,
name|SourceLocation
name|Loc
parameter_list|,
name|QualType
name|DstType
parameter_list|,
name|QualType
name|SrcType
parameter_list|,
name|Expr
modifier|*
name|SrcExpr
parameter_list|,
name|AssignmentAction
name|Action
parameter_list|,
name|bool
modifier|*
name|Complained
init|=
literal|0
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// CheckAssignmentConstraints - Perform type checking for assignment,
end_comment

begin_comment
comment|/// argument passing, variable initialization, and function return values.
end_comment

begin_comment
comment|/// This routine is only used by the following two methods. C99 6.5.16.
end_comment

begin_function_decl
name|AssignConvertType
name|CheckAssignmentConstraints
parameter_list|(
name|QualType
name|lhs
parameter_list|,
name|QualType
name|rhs
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|// CheckSingleAssignmentConstraints - Currently used by
end_comment

begin_comment
comment|// CheckAssignmentOperands, and ActOnReturnStmt. Prior to type checking,
end_comment

begin_comment
comment|// this routine performs the default function/array converions.
end_comment

begin_function_decl
name|AssignConvertType
name|CheckSingleAssignmentConstraints
parameter_list|(
name|QualType
name|lhs
parameter_list|,
name|Expr
modifier|*
modifier|&
name|rExpr
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|// \brief If the lhs type is a transparent union, check whether we
end_comment

begin_comment
comment|// can initialize the transparent union with the given expression.
end_comment

begin_function_decl
name|AssignConvertType
name|CheckTransparentUnionArgumentConstraints
parameter_list|(
name|QualType
name|lhs
parameter_list|,
name|Expr
modifier|*
modifier|&
name|rExpr
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|// Helper function for CheckAssignmentConstraints (C99 6.5.16.1p1)
end_comment

begin_function_decl
name|AssignConvertType
name|CheckPointerTypesForAssignment
parameter_list|(
name|QualType
name|lhsType
parameter_list|,
name|QualType
name|rhsType
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|AssignConvertType
name|CheckObjCPointerTypesForAssignment
parameter_list|(
name|QualType
name|lhsType
parameter_list|,
name|QualType
name|rhsType
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|// Helper function for CheckAssignmentConstraints involving two
end_comment

begin_comment
comment|// block pointer types.
end_comment

begin_function_decl
name|AssignConvertType
name|CheckBlockPointerTypesForAssignment
parameter_list|(
name|QualType
name|lhsType
parameter_list|,
name|QualType
name|rhsType
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|IsStringLiteralToNonConstPointerConversion
parameter_list|(
name|Expr
modifier|*
name|From
parameter_list|,
name|QualType
name|ToType
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|CheckExceptionSpecCompatibility
parameter_list|(
name|Expr
modifier|*
name|From
parameter_list|,
name|QualType
name|ToType
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|PerformImplicitConversion
parameter_list|(
name|Expr
modifier|*
modifier|&
name|From
parameter_list|,
name|QualType
name|ToType
parameter_list|,
name|AssignmentAction
name|Action
parameter_list|,
name|bool
name|AllowExplicit
init|=
name|false
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|PerformImplicitConversion
parameter_list|(
name|Expr
modifier|*
modifier|&
name|From
parameter_list|,
name|QualType
name|ToType
parameter_list|,
name|AssignmentAction
name|Action
parameter_list|,
name|bool
name|AllowExplicit
parameter_list|,
name|ImplicitConversionSequence
modifier|&
name|ICS
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|PerformImplicitConversion
parameter_list|(
name|Expr
modifier|*
modifier|&
name|From
parameter_list|,
name|QualType
name|ToType
parameter_list|,
specifier|const
name|ImplicitConversionSequence
modifier|&
name|ICS
parameter_list|,
name|AssignmentAction
name|Action
parameter_list|,
name|bool
name|IgnoreBaseAccess
init|=
name|false
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|PerformImplicitConversion
parameter_list|(
name|Expr
modifier|*
modifier|&
name|From
parameter_list|,
name|QualType
name|ToType
parameter_list|,
specifier|const
name|StandardConversionSequence
modifier|&
name|SCS
parameter_list|,
name|AssignmentAction
name|Action
parameter_list|,
name|bool
name|IgnoreBaseAccess
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// the following "Check" methods will return a valid/converted QualType
end_comment

begin_comment
comment|/// or a null QualType (indicating an error diagnostic was issued).
end_comment

begin_comment
comment|/// type checking binary operators (subroutines of CreateBuiltinBinOp).
end_comment

begin_function_decl
name|QualType
name|InvalidOperands
parameter_list|(
name|SourceLocation
name|l
parameter_list|,
name|Expr
modifier|*
modifier|&
name|lex
parameter_list|,
name|Expr
modifier|*
modifier|&
name|rex
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|QualType
name|CheckPointerToMemberOperands
parameter_list|(
comment|// C++ 5.5
name|Expr
modifier|*
modifier|&
name|lex
parameter_list|,
name|Expr
modifier|*
modifier|&
name|rex
parameter_list|,
name|SourceLocation
name|OpLoc
parameter_list|,
name|bool
name|isIndirect
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|QualType
name|CheckMultiplyDivideOperands
parameter_list|(
comment|// C99 6.5.5
name|Expr
modifier|*
modifier|&
name|lex
parameter_list|,
name|Expr
modifier|*
modifier|&
name|rex
parameter_list|,
name|SourceLocation
name|OpLoc
parameter_list|,
name|bool
name|isCompAssign
parameter_list|,
name|bool
name|isDivide
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|QualType
name|CheckRemainderOperands
parameter_list|(
comment|// C99 6.5.5
name|Expr
modifier|*
modifier|&
name|lex
parameter_list|,
name|Expr
modifier|*
modifier|&
name|rex
parameter_list|,
name|SourceLocation
name|OpLoc
parameter_list|,
name|bool
name|isCompAssign
init|=
name|false
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|QualType
name|CheckAdditionOperands
parameter_list|(
comment|// C99 6.5.6
name|Expr
modifier|*
modifier|&
name|lex
parameter_list|,
name|Expr
modifier|*
modifier|&
name|rex
parameter_list|,
name|SourceLocation
name|OpLoc
parameter_list|,
name|QualType
modifier|*
name|CompLHSTy
init|=
literal|0
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|QualType
name|CheckSubtractionOperands
parameter_list|(
comment|// C99 6.5.6
name|Expr
modifier|*
modifier|&
name|lex
parameter_list|,
name|Expr
modifier|*
modifier|&
name|rex
parameter_list|,
name|SourceLocation
name|OpLoc
parameter_list|,
name|QualType
modifier|*
name|CompLHSTy
init|=
literal|0
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|QualType
name|CheckShiftOperands
parameter_list|(
comment|// C99 6.5.7
name|Expr
modifier|*
modifier|&
name|lex
parameter_list|,
name|Expr
modifier|*
modifier|&
name|rex
parameter_list|,
name|SourceLocation
name|OpLoc
parameter_list|,
name|bool
name|isCompAssign
init|=
name|false
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|QualType
name|CheckCompareOperands
parameter_list|(
comment|// C99 6.5.8/9
name|Expr
modifier|*
modifier|&
name|lex
parameter_list|,
name|Expr
modifier|*
modifier|&
name|rex
parameter_list|,
name|SourceLocation
name|OpLoc
parameter_list|,
name|unsigned
name|Opc
parameter_list|,
name|bool
name|isRelational
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|QualType
name|CheckBitwiseOperands
parameter_list|(
comment|// C99 6.5.[10...12]
name|Expr
modifier|*
modifier|&
name|lex
parameter_list|,
name|Expr
modifier|*
modifier|&
name|rex
parameter_list|,
name|SourceLocation
name|OpLoc
parameter_list|,
name|bool
name|isCompAssign
init|=
name|false
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|QualType
name|CheckLogicalOperands
parameter_list|(
comment|// C99 6.5.[13,14]
name|Expr
modifier|*
modifier|&
name|lex
parameter_list|,
name|Expr
modifier|*
modifier|&
name|rex
parameter_list|,
name|SourceLocation
name|OpLoc
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|// CheckAssignmentOperands is used for both simple and compound assignment.
end_comment

begin_comment
comment|// For simple assignment, pass both expressions and a null converted type.
end_comment

begin_comment
comment|// For compound assignment, pass both expressions and the converted type.
end_comment

begin_function_decl
name|QualType
name|CheckAssignmentOperands
parameter_list|(
comment|// C99 6.5.16.[1,2]
name|Expr
modifier|*
name|lex
parameter_list|,
name|Expr
modifier|*
modifier|&
name|rex
parameter_list|,
name|SourceLocation
name|OpLoc
parameter_list|,
name|QualType
name|convertedType
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|QualType
name|CheckCommaOperands
parameter_list|(
comment|// C99 6.5.17
name|Expr
modifier|*
name|lex
parameter_list|,
name|Expr
modifier|*
modifier|&
name|rex
parameter_list|,
name|SourceLocation
name|OpLoc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|QualType
name|CheckConditionalOperands
parameter_list|(
comment|// C99 6.5.15
name|Expr
modifier|*
modifier|&
name|cond
parameter_list|,
name|Expr
modifier|*
modifier|&
name|lhs
parameter_list|,
name|Expr
modifier|*
modifier|&
name|rhs
parameter_list|,
name|SourceLocation
name|questionLoc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|QualType
name|CXXCheckConditionalOperands
parameter_list|(
comment|// C++ 5.16
name|Expr
modifier|*
modifier|&
name|cond
parameter_list|,
name|Expr
modifier|*
modifier|&
name|lhs
parameter_list|,
name|Expr
modifier|*
modifier|&
name|rhs
parameter_list|,
name|SourceLocation
name|questionLoc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|QualType
name|FindCompositePointerType
parameter_list|(
name|SourceLocation
name|Loc
parameter_list|,
name|Expr
modifier|*
modifier|&
name|E1
parameter_list|,
name|Expr
modifier|*
modifier|&
name|E2
parameter_list|,
name|bool
modifier|*
name|NonStandardCompositeType
init|=
literal|0
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|QualType
name|FindCompositeObjCPointerType
parameter_list|(
name|Expr
modifier|*
modifier|&
name|LHS
parameter_list|,
name|Expr
modifier|*
modifier|&
name|RHS
parameter_list|,
name|SourceLocation
name|questionLoc
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// type checking for vector binary operators.
end_comment

begin_function_decl
name|QualType
name|CheckVectorOperands
parameter_list|(
name|SourceLocation
name|l
parameter_list|,
name|Expr
modifier|*
modifier|&
name|lex
parameter_list|,
name|Expr
modifier|*
modifier|&
name|rex
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|QualType
name|CheckVectorCompareOperands
parameter_list|(
name|Expr
modifier|*
modifier|&
name|lex
parameter_list|,
name|Expr
modifier|*
modifier|&
name|rx
parameter_list|,
name|SourceLocation
name|l
parameter_list|,
name|bool
name|isRel
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// type checking unary operators (subroutines of ActOnUnaryOp).
end_comment

begin_comment
comment|/// C99 6.5.3.1, 6.5.3.2, 6.5.3.4
end_comment

begin_function_decl
name|QualType
name|CheckIncrementDecrementOperand
parameter_list|(
name|Expr
modifier|*
name|op
parameter_list|,
name|SourceLocation
name|OpLoc
parameter_list|,
name|bool
name|isInc
parameter_list|,
name|bool
name|isPrefix
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|QualType
name|CheckAddressOfOperand
parameter_list|(
name|Expr
modifier|*
name|op
parameter_list|,
name|SourceLocation
name|OpLoc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|QualType
name|CheckIndirectionOperand
parameter_list|(
name|Expr
modifier|*
name|op
parameter_list|,
name|SourceLocation
name|OpLoc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|QualType
name|CheckRealImagOperand
parameter_list|(
name|Expr
modifier|*
modifier|&
name|Op
parameter_list|,
name|SourceLocation
name|OpLoc
parameter_list|,
name|bool
name|isReal
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// type checking primary expressions.
end_comment

begin_function_decl
name|QualType
name|CheckExtVectorComponent
parameter_list|(
name|QualType
name|baseType
parameter_list|,
name|SourceLocation
name|OpLoc
parameter_list|,
specifier|const
name|IdentifierInfo
modifier|*
name|Comp
parameter_list|,
name|SourceLocation
name|CmpLoc
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// type checking declaration initializers (C99 6.7.8)
end_comment

begin_function_decl
name|bool
name|CheckInitList
parameter_list|(
specifier|const
name|InitializedEntity
modifier|&
name|Entity
parameter_list|,
name|InitListExpr
modifier|*
modifier|&
name|InitList
parameter_list|,
name|QualType
modifier|&
name|DeclType
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|CheckForConstantInitializer
parameter_list|(
name|Expr
modifier|*
name|e
parameter_list|,
name|QualType
name|t
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|// type checking C++ declaration initializers (C++ [dcl.init]).
end_comment

begin_comment
comment|/// ReferenceCompareResult - Expresses the result of comparing two
end_comment

begin_comment
comment|/// types (cv1 T1 and cv2 T2) to determine their compatibility for the
end_comment

begin_comment
comment|/// purposes of initialization by reference (C++ [dcl.init.ref]p4).
end_comment

begin_enum
enum|enum
name|ReferenceCompareResult
block|{
comment|/// Ref_Incompatible - The two types are incompatible, so direct
comment|/// reference binding is not possible.
name|Ref_Incompatible
init|=
literal|0
block|,
comment|/// Ref_Related - The two types are reference-related, which means
comment|/// that their unqualified forms (T1 and T2) are either the same
comment|/// or T1 is a base class of T2.
name|Ref_Related
block|,
comment|/// Ref_Compatible_With_Added_Qualification - The two types are
comment|/// reference-compatible with added qualification, meaning that
comment|/// they are reference-compatible and the qualifiers on T1 (cv1)
comment|/// are greater than the qualifiers on T2 (cv2).
name|Ref_Compatible_With_Added_Qualification
block|,
comment|/// Ref_Compatible - The two types are reference-compatible and
comment|/// have equivalent qualifiers (cv1 == cv2).
name|Ref_Compatible
block|}
enum|;
end_enum

begin_function_decl
name|ReferenceCompareResult
name|CompareReferenceRelationship
parameter_list|(
name|SourceLocation
name|Loc
parameter_list|,
name|QualType
name|T1
parameter_list|,
name|QualType
name|T2
parameter_list|,
name|bool
modifier|&
name|DerivedToBase
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// CheckCastTypes - Check type constraints for casting between types under
end_comment

begin_comment
comment|/// C semantics, or forward to CXXCheckCStyleCast in C++.
end_comment

begin_decl_stmt
name|bool
name|CheckCastTypes
argument_list|(
name|SourceRange
name|TyRange
argument_list|,
name|QualType
name|CastTy
argument_list|,
name|Expr
operator|*
operator|&
name|CastExpr
argument_list|,
name|CastExpr
operator|::
name|CastKind
operator|&
name|Kind
argument_list|,
name|CXXBaseSpecifierArray
operator|&
name|BasePath
argument_list|,
name|bool
name|FunctionalStyle
operator|=
name|false
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|// CheckVectorCast - check type constraints for vectors.
end_comment

begin_comment
comment|// Since vectors are an extension, there are no C standard reference for this.
end_comment

begin_comment
comment|// We allow casting between vectors and integer datatypes of the same size.
end_comment

begin_comment
comment|// returns true if the cast is invalid
end_comment

begin_decl_stmt
name|bool
name|CheckVectorCast
argument_list|(
name|SourceRange
name|R
argument_list|,
name|QualType
name|VectorTy
argument_list|,
name|QualType
name|Ty
argument_list|,
name|CastExpr
operator|::
name|CastKind
operator|&
name|Kind
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|// CheckExtVectorCast - check type constraints for extended vectors.
end_comment

begin_comment
comment|// Since vectors are an extension, there are no C standard reference for this.
end_comment

begin_comment
comment|// We allow casting between vectors and integer datatypes of the same size,
end_comment

begin_comment
comment|// or vectors and the element type of that vector.
end_comment

begin_comment
comment|// returns true if the cast is invalid
end_comment

begin_decl_stmt
name|bool
name|CheckExtVectorCast
argument_list|(
name|SourceRange
name|R
argument_list|,
name|QualType
name|VectorTy
argument_list|,
name|Expr
operator|*
operator|&
name|CastExpr
argument_list|,
name|CastExpr
operator|::
name|CastKind
operator|&
name|Kind
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// CXXCheckCStyleCast - Check constraints of a C-style or function-style
end_comment

begin_comment
comment|/// cast under C++ semantics.
end_comment

begin_decl_stmt
name|bool
name|CXXCheckCStyleCast
argument_list|(
name|SourceRange
name|R
argument_list|,
name|QualType
name|CastTy
argument_list|,
name|Expr
operator|*
operator|&
name|CastExpr
argument_list|,
name|CastExpr
operator|::
name|CastKind
operator|&
name|Kind
argument_list|,
name|CXXBaseSpecifierArray
operator|&
name|BasePath
argument_list|,
name|bool
name|FunctionalStyle
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// CheckMessageArgumentTypes - Check types in an Obj-C message send.
end_comment

begin_comment
comment|/// \param Method - May be null.
end_comment

begin_comment
comment|/// \param [out] ReturnType - The return type of the send.
end_comment

begin_comment
comment|/// \return true iff there were any incompatible types.
end_comment

begin_function_decl
name|bool
name|CheckMessageArgumentTypes
parameter_list|(
name|Expr
modifier|*
modifier|*
name|Args
parameter_list|,
name|unsigned
name|NumArgs
parameter_list|,
name|Selector
name|Sel
parameter_list|,
name|ObjCMethodDecl
modifier|*
name|Method
parameter_list|,
name|bool
name|isClassMessage
parameter_list|,
name|SourceLocation
name|lbrac
parameter_list|,
name|SourceLocation
name|rbrac
parameter_list|,
name|QualType
modifier|&
name|ReturnType
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// CheckBooleanCondition - Diagnose problems involving the use of
end_comment

begin_comment
comment|/// the given expression as a boolean condition (e.g. in an if
end_comment

begin_comment
comment|/// statement).  Also performs the standard function and array
end_comment

begin_comment
comment|/// decays, possibly changing the input variable.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param Loc - A location associated with the condition, e.g. the
end_comment

begin_comment
comment|/// 'if' keyword.
end_comment

begin_comment
comment|/// \return true iff there were any errors
end_comment

begin_function_decl
name|bool
name|CheckBooleanCondition
parameter_list|(
name|Expr
modifier|*
modifier|&
name|CondExpr
parameter_list|,
name|SourceLocation
name|Loc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|virtual
name|OwningExprResult
name|ActOnBooleanCondition
parameter_list|(
name|Scope
modifier|*
name|S
parameter_list|,
name|SourceLocation
name|Loc
parameter_list|,
name|ExprArg
name|SubExpr
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// DiagnoseAssignmentAsCondition - Given that an expression is
end_comment

begin_comment
comment|/// being used as a boolean condition, warn if it's an assignment.
end_comment

begin_function_decl
name|void
name|DiagnoseAssignmentAsCondition
parameter_list|(
name|Expr
modifier|*
name|E
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// CheckCXXBooleanCondition - Returns true if conversion to bool is invalid.
end_comment

begin_function_decl
name|bool
name|CheckCXXBooleanCondition
parameter_list|(
name|Expr
modifier|*
modifier|&
name|CondExpr
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// ConvertIntegerToTypeWarnOnOverflow - Convert the specified APInt to have
end_comment

begin_comment
comment|/// the specified width and sign.  If an overflow occurs, detect it and emit
end_comment

begin_comment
comment|/// the specified diagnostic.
end_comment

begin_decl_stmt
name|void
name|ConvertIntegerToTypeWarnOnOverflow
argument_list|(
name|llvm
operator|::
name|APSInt
operator|&
name|OldVal
argument_list|,
name|unsigned
name|NewWidth
argument_list|,
name|bool
name|NewSign
argument_list|,
name|SourceLocation
name|Loc
argument_list|,
name|unsigned
name|DiagID
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// Checks that the Objective-C declaration is declared in the global scope.
end_comment

begin_comment
comment|/// Emits an error and marks the declaration as invalid if it's not declared
end_comment

begin_comment
comment|/// in the global scope.
end_comment

begin_function_decl
name|bool
name|CheckObjCDeclScope
parameter_list|(
name|Decl
modifier|*
name|D
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|InitBuiltinVaListType
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/// VerifyIntegerConstantExpression - verifies that an expression is an ICE,
end_comment

begin_comment
comment|/// and reports the appropriate diagnostics. Returns false on success.
end_comment

begin_comment
comment|/// Can optionally return the value of the expression.
end_comment

begin_decl_stmt
name|bool
name|VerifyIntegerConstantExpression
argument_list|(
specifier|const
name|Expr
operator|*
name|E
argument_list|,
name|llvm
operator|::
name|APSInt
operator|*
name|Result
operator|=
literal|0
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// VerifyBitField - verifies that a bit field expression is an ICE and has
end_comment

begin_comment
comment|/// the correct width, and that the field type is valid.
end_comment

begin_comment
comment|/// Returns false on success.
end_comment

begin_comment
comment|/// Can optionally return whether the bit-field is of width 0
end_comment

begin_function_decl
name|bool
name|VerifyBitField
parameter_list|(
name|SourceLocation
name|FieldLoc
parameter_list|,
name|IdentifierInfo
modifier|*
name|FieldName
parameter_list|,
name|QualType
name|FieldTy
parameter_list|,
specifier|const
name|Expr
modifier|*
name|BitWidth
parameter_list|,
name|bool
modifier|*
name|ZeroWidth
init|=
literal|0
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// \name Code completion
end_comment

begin_comment
comment|//@{
end_comment

begin_function_decl
name|virtual
name|void
name|CodeCompleteOrdinaryName
parameter_list|(
name|Scope
modifier|*
name|S
parameter_list|,
name|CodeCompletionContext
name|CompletionContext
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|virtual
name|void
name|CodeCompleteExpression
parameter_list|(
name|Scope
modifier|*
name|S
parameter_list|,
name|QualType
name|T
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|virtual
name|void
name|CodeCompleteMemberReferenceExpr
parameter_list|(
name|Scope
modifier|*
name|S
parameter_list|,
name|ExprTy
modifier|*
name|Base
parameter_list|,
name|SourceLocation
name|OpLoc
parameter_list|,
name|bool
name|IsArrow
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|virtual
name|void
name|CodeCompleteTag
parameter_list|(
name|Scope
modifier|*
name|S
parameter_list|,
name|unsigned
name|TagSpec
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|virtual
name|void
name|CodeCompleteCase
parameter_list|(
name|Scope
modifier|*
name|S
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|virtual
name|void
name|CodeCompleteCall
parameter_list|(
name|Scope
modifier|*
name|S
parameter_list|,
name|ExprTy
modifier|*
name|Fn
parameter_list|,
name|ExprTy
modifier|*
modifier|*
name|Args
parameter_list|,
name|unsigned
name|NumArgs
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|virtual
name|void
name|CodeCompleteInitializer
parameter_list|(
name|Scope
modifier|*
name|S
parameter_list|,
name|DeclPtrTy
name|D
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|virtual
name|void
name|CodeCompleteReturn
parameter_list|(
name|Scope
modifier|*
name|S
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|virtual
name|void
name|CodeCompleteAssignmentRHS
parameter_list|(
name|Scope
modifier|*
name|S
parameter_list|,
name|ExprTy
modifier|*
name|LHS
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|virtual
name|void
name|CodeCompleteQualifiedId
parameter_list|(
name|Scope
modifier|*
name|S
parameter_list|,
name|CXXScopeSpec
modifier|&
name|SS
parameter_list|,
name|bool
name|EnteringContext
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|virtual
name|void
name|CodeCompleteUsing
parameter_list|(
name|Scope
modifier|*
name|S
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|virtual
name|void
name|CodeCompleteUsingDirective
parameter_list|(
name|Scope
modifier|*
name|S
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|virtual
name|void
name|CodeCompleteNamespaceDecl
parameter_list|(
name|Scope
modifier|*
name|S
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|virtual
name|void
name|CodeCompleteNamespaceAliasDecl
parameter_list|(
name|Scope
modifier|*
name|S
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|virtual
name|void
name|CodeCompleteOperatorName
parameter_list|(
name|Scope
modifier|*
name|S
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|virtual
name|void
name|CodeCompleteObjCAtDirective
parameter_list|(
name|Scope
modifier|*
name|S
parameter_list|,
name|DeclPtrTy
name|ObjCImpDecl
parameter_list|,
name|bool
name|InInterface
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|virtual
name|void
name|CodeCompleteObjCAtVisibility
parameter_list|(
name|Scope
modifier|*
name|S
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|virtual
name|void
name|CodeCompleteObjCAtStatement
parameter_list|(
name|Scope
modifier|*
name|S
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|virtual
name|void
name|CodeCompleteObjCAtExpression
parameter_list|(
name|Scope
modifier|*
name|S
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|virtual
name|void
name|CodeCompleteObjCPropertyFlags
parameter_list|(
name|Scope
modifier|*
name|S
parameter_list|,
name|ObjCDeclSpec
modifier|&
name|ODS
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|virtual
name|void
name|CodeCompleteObjCPropertyGetter
parameter_list|(
name|Scope
modifier|*
name|S
parameter_list|,
name|DeclPtrTy
name|ClassDecl
parameter_list|,
name|DeclPtrTy
modifier|*
name|Methods
parameter_list|,
name|unsigned
name|NumMethods
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|virtual
name|void
name|CodeCompleteObjCPropertySetter
parameter_list|(
name|Scope
modifier|*
name|S
parameter_list|,
name|DeclPtrTy
name|ClassDecl
parameter_list|,
name|DeclPtrTy
modifier|*
name|Methods
parameter_list|,
name|unsigned
name|NumMethods
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|virtual
name|void
name|CodeCompleteObjCMessageReceiver
parameter_list|(
name|Scope
modifier|*
name|S
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|virtual
name|void
name|CodeCompleteObjCSuperMessage
parameter_list|(
name|Scope
modifier|*
name|S
parameter_list|,
name|SourceLocation
name|SuperLoc
parameter_list|,
name|IdentifierInfo
modifier|*
modifier|*
name|SelIdents
parameter_list|,
name|unsigned
name|NumSelIdents
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|virtual
name|void
name|CodeCompleteObjCClassMessage
parameter_list|(
name|Scope
modifier|*
name|S
parameter_list|,
name|TypeTy
modifier|*
name|Receiver
parameter_list|,
name|IdentifierInfo
modifier|*
modifier|*
name|SelIdents
parameter_list|,
name|unsigned
name|NumSelIdents
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|virtual
name|void
name|CodeCompleteObjCInstanceMessage
parameter_list|(
name|Scope
modifier|*
name|S
parameter_list|,
name|ExprTy
modifier|*
name|Receiver
parameter_list|,
name|IdentifierInfo
modifier|*
modifier|*
name|SelIdents
parameter_list|,
name|unsigned
name|NumSelIdents
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|virtual
name|void
name|CodeCompleteObjCProtocolReferences
parameter_list|(
name|IdentifierLocPair
modifier|*
name|Protocols
parameter_list|,
name|unsigned
name|NumProtocols
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|virtual
name|void
name|CodeCompleteObjCProtocolDecl
parameter_list|(
name|Scope
modifier|*
name|S
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|virtual
name|void
name|CodeCompleteObjCInterfaceDecl
parameter_list|(
name|Scope
modifier|*
name|S
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|virtual
name|void
name|CodeCompleteObjCSuperclass
parameter_list|(
name|Scope
modifier|*
name|S
parameter_list|,
name|IdentifierInfo
modifier|*
name|ClassName
parameter_list|,
name|SourceLocation
name|ClassNameLoc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|virtual
name|void
name|CodeCompleteObjCImplementationDecl
parameter_list|(
name|Scope
modifier|*
name|S
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|virtual
name|void
name|CodeCompleteObjCInterfaceCategory
parameter_list|(
name|Scope
modifier|*
name|S
parameter_list|,
name|IdentifierInfo
modifier|*
name|ClassName
parameter_list|,
name|SourceLocation
name|ClassNameLoc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|virtual
name|void
name|CodeCompleteObjCImplementationCategory
parameter_list|(
name|Scope
modifier|*
name|S
parameter_list|,
name|IdentifierInfo
modifier|*
name|ClassName
parameter_list|,
name|SourceLocation
name|ClassNameLoc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|virtual
name|void
name|CodeCompleteObjCPropertyDefinition
parameter_list|(
name|Scope
modifier|*
name|S
parameter_list|,
name|DeclPtrTy
name|ObjCImpDecl
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|virtual
name|void
name|CodeCompleteObjCPropertySynthesizeIvar
parameter_list|(
name|Scope
modifier|*
name|S
parameter_list|,
name|IdentifierInfo
modifier|*
name|PropertyName
parameter_list|,
name|DeclPtrTy
name|ObjCImpDecl
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|virtual
name|void
name|CodeCompleteObjCMethodDecl
parameter_list|(
name|Scope
modifier|*
name|S
parameter_list|,
name|bool
name|IsInstanceMethod
parameter_list|,
name|TypeTy
modifier|*
name|ReturnType
parameter_list|,
name|DeclPtrTy
name|IDecl
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|virtual
name|void
name|CodeCompleteObjCMethodDeclSelector
parameter_list|(
name|Scope
modifier|*
name|S
parameter_list|,
name|bool
name|IsInstanceMethod
parameter_list|,
name|bool
name|AtParameterName
parameter_list|,
name|TypeTy
modifier|*
name|ReturnType
parameter_list|,
name|IdentifierInfo
modifier|*
modifier|*
name|SelIdents
parameter_list|,
name|unsigned
name|NumSelIdents
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|//@}
end_comment

begin_comment
comment|//===--------------------------------------------------------------------===//
end_comment

begin_comment
comment|// Extra semantic analysis beyond the C type system
end_comment

begin_label
name|public
label|:
end_label

begin_decl_stmt
name|SourceLocation
name|getLocationOfStringLiteralByte
argument_list|(
specifier|const
name|StringLiteral
operator|*
name|SL
argument_list|,
name|unsigned
name|ByteNo
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_label
name|private
label|:
end_label

begin_function_decl
name|bool
name|CheckFunctionCall
parameter_list|(
name|FunctionDecl
modifier|*
name|FDecl
parameter_list|,
name|CallExpr
modifier|*
name|TheCall
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|CheckBlockCall
parameter_list|(
name|NamedDecl
modifier|*
name|NDecl
parameter_list|,
name|CallExpr
modifier|*
name|TheCall
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|CheckablePrintfAttr
parameter_list|(
specifier|const
name|FormatAttr
modifier|*
name|Format
parameter_list|,
name|CallExpr
modifier|*
name|TheCall
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|CheckObjCString
parameter_list|(
name|Expr
modifier|*
name|Arg
parameter_list|)
function_decl|;
end_function_decl

begin_expr_stmt
name|Action
operator|::
name|OwningExprResult
name|CheckBuiltinFunctionCall
argument_list|(
argument|unsigned BuiltinID
argument_list|,
argument|CallExpr *TheCall
argument_list|)
expr_stmt|;
end_expr_stmt

begin_function_decl
name|bool
name|CheckARMBuiltinFunctionCall
parameter_list|(
name|unsigned
name|BuiltinID
parameter_list|,
name|CallExpr
modifier|*
name|TheCall
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|CheckX86BuiltinFunctionCall
parameter_list|(
name|unsigned
name|BuiltinID
parameter_list|,
name|CallExpr
modifier|*
name|TheCall
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|SemaBuiltinVAStart
parameter_list|(
name|CallExpr
modifier|*
name|TheCall
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|SemaBuiltinUnorderedCompare
parameter_list|(
name|CallExpr
modifier|*
name|TheCall
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|SemaBuiltinFPClassification
parameter_list|(
name|CallExpr
modifier|*
name|TheCall
parameter_list|,
name|unsigned
name|NumArgs
parameter_list|)
function_decl|;
end_function_decl

begin_label
name|public
label|:
end_label

begin_comment
comment|// Used by C++ template instantiation.
end_comment

begin_expr_stmt
name|Action
operator|::
name|OwningExprResult
name|SemaBuiltinShuffleVector
argument_list|(
name|CallExpr
operator|*
name|TheCall
argument_list|)
expr_stmt|;
end_expr_stmt

begin_label
name|private
label|:
end_label

begin_function_decl
name|bool
name|SemaBuiltinPrefetch
parameter_list|(
name|CallExpr
modifier|*
name|TheCall
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|SemaBuiltinObjectSize
parameter_list|(
name|CallExpr
modifier|*
name|TheCall
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|SemaBuiltinLongjmp
parameter_list|(
name|CallExpr
modifier|*
name|TheCall
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|OwningExprResult
name|SemaBuiltinAtomicOverloaded
parameter_list|(
name|OwningExprResult
name|TheCallResult
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
name|bool
name|SemaBuiltinConstantArg
argument_list|(
name|CallExpr
operator|*
name|TheCall
argument_list|,
name|int
name|ArgNum
argument_list|,
name|llvm
operator|::
name|APSInt
operator|&
name|Result
argument_list|)
decl_stmt|;
end_decl_stmt

begin_function_decl
name|bool
name|SemaCheckStringLiteral
parameter_list|(
specifier|const
name|Expr
modifier|*
name|E
parameter_list|,
specifier|const
name|CallExpr
modifier|*
name|TheCall
parameter_list|,
name|bool
name|HasVAListArg
parameter_list|,
name|unsigned
name|format_idx
parameter_list|,
name|unsigned
name|firstDataArg
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|CheckPrintfString
parameter_list|(
specifier|const
name|StringLiteral
modifier|*
name|FExpr
parameter_list|,
specifier|const
name|Expr
modifier|*
name|OrigFormatExpr
parameter_list|,
specifier|const
name|CallExpr
modifier|*
name|TheCall
parameter_list|,
name|bool
name|HasVAListArg
parameter_list|,
name|unsigned
name|format_idx
parameter_list|,
name|unsigned
name|firstDataArg
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|CheckNonNullArguments
parameter_list|(
specifier|const
name|NonNullAttr
modifier|*
name|NonNull
parameter_list|,
specifier|const
name|CallExpr
modifier|*
name|TheCall
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|CheckPrintfArguments
parameter_list|(
specifier|const
name|CallExpr
modifier|*
name|TheCall
parameter_list|,
name|bool
name|HasVAListArg
parameter_list|,
name|unsigned
name|format_idx
parameter_list|,
name|unsigned
name|firstDataArg
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|CheckReturnStackAddr
parameter_list|(
name|Expr
modifier|*
name|RetValExp
parameter_list|,
name|QualType
name|lhsType
parameter_list|,
name|SourceLocation
name|ReturnLoc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|CheckFloatComparison
parameter_list|(
name|SourceLocation
name|loc
parameter_list|,
name|Expr
modifier|*
name|lex
parameter_list|,
name|Expr
modifier|*
name|rex
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|CheckImplicitConversions
parameter_list|(
name|Expr
modifier|*
name|E
parameter_list|)
function_decl|;
end_function_decl

begin_comment
unit|};
comment|//===--------------------------------------------------------------------===//
end_comment

begin_comment
comment|// Typed version of Parser::ExprArg (smart pointer for wrapping Expr pointers).
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|>
name|class
name|ExprOwningPtr
operator|:
name|public
name|Action
operator|::
name|ExprArg
block|{
name|public
operator|:
name|ExprOwningPtr
argument_list|(
name|Sema
operator|*
name|S
argument_list|,
name|T
operator|*
name|expr
argument_list|)
operator|:
name|Action
operator|::
name|ExprArg
argument_list|(
argument|*S
argument_list|,
argument|expr
argument_list|)
block|{}
name|void
name|reset
argument_list|(
argument|T* p
argument_list|)
block|{
name|Action
operator|::
name|ExprArg
operator|::
name|operator
operator|=
operator|(
name|p
operator|)
block|; }
name|T
operator|*
name|get
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
name|Action
operator|::
name|ExprArg
operator|::
name|get
argument_list|()
operator|)
return|;
block|}
name|T
operator|*
name|take
argument_list|()
block|{
return|return
name|static_cast
operator|<
name|T
operator|*
operator|>
operator|(
name|Action
operator|::
name|ExprArg
operator|::
name|take
argument_list|()
operator|)
return|;
block|}
end_expr_stmt

begin_function
name|T
modifier|*
name|release
parameter_list|()
block|{
return|return
name|take
argument_list|()
return|;
block|}
end_function

begin_expr_stmt
name|T
operator|&
name|operator
operator|*
operator|(
operator|)
specifier|const
block|{
return|return
operator|*
name|get
argument_list|()
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|T
operator|*
name|operator
operator|->
expr|(
end_expr_stmt

begin_expr_stmt
unit|)
specifier|const
block|{
return|return
name|get
argument_list|()
return|;
block|}
end_expr_stmt

begin_comment
unit|};  }
comment|// end namespace clang
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

