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
name|LLVM_CLANG_SEMA_SEMA_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_SEMA_SEMA_H
end_define

begin_include
include|#
directive|include
file|"clang/Sema/Ownership.h"
end_include

begin_include
include|#
directive|include
file|"clang/Sema/AnalysisBasedWarnings.h"
end_include

begin_include
include|#
directive|include
file|"clang/Sema/IdentifierResolver.h"
end_include

begin_include
include|#
directive|include
file|"clang/Sema/ObjCMethodList.h"
end_include

begin_include
include|#
directive|include
file|"clang/Sema/DeclSpec.h"
end_include

begin_include
include|#
directive|include
file|"clang/AST/Expr.h"
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
file|"clang/AST/TypeLoc.h"
end_include

begin_include
include|#
directive|include
file|"clang/Basic/Specifiers.h"
end_include

begin_include
include|#
directive|include
file|"clang/Basic/TemplateKinds.h"
end_include

begin_include
include|#
directive|include
file|"clang/Basic/TypeTraits.h"
end_include

begin_include
include|#
directive|include
file|"clang/Basic/ExpressionTraits.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/OwningPtr.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/SmallPtrSet.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/SmallVector.h"
end_include

begin_include
include|#
directive|include
file|<deque>
end_include

begin_include
include|#
directive|include
file|<string>
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|APSInt
decl_stmt|;
name|template
operator|<
name|typename
name|ValueT
operator|>
expr|struct
name|DenseMapInfo
expr_stmt|;
name|template
operator|<
name|typename
name|ValueT
operator|,
name|typename
name|ValueInfoT
operator|>
name|class
name|DenseSet
expr_stmt|;
block|}
end_decl_stmt

begin_decl_stmt
name|namespace
name|clang
block|{
name|class
name|ADLResult
decl_stmt|;
name|class
name|ASTConsumer
decl_stmt|;
name|class
name|ASTContext
decl_stmt|;
name|class
name|ASTMutationListener
decl_stmt|;
name|class
name|ArrayType
decl_stmt|;
name|class
name|AttributeList
decl_stmt|;
name|class
name|BlockDecl
decl_stmt|;
name|class
name|CXXBasePath
decl_stmt|;
name|class
name|CXXBasePaths
decl_stmt|;
typedef|typedef
name|llvm
operator|::
name|SmallVector
operator|<
name|CXXBaseSpecifier
operator|*
operator|,
literal|4
operator|>
name|CXXCastPath
expr_stmt|;
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
name|CXXFieldCollector
decl_stmt|;
name|class
name|CXXMemberCallExpr
decl_stmt|;
name|class
name|CXXMethodDecl
decl_stmt|;
name|class
name|CXXScopeSpec
decl_stmt|;
name|class
name|CXXTemporary
decl_stmt|;
name|class
name|CXXTryStmt
decl_stmt|;
name|class
name|CallExpr
decl_stmt|;
name|class
name|ClassTemplateDecl
decl_stmt|;
name|class
name|ClassTemplatePartialSpecializationDecl
decl_stmt|;
name|class
name|ClassTemplateSpecializationDecl
decl_stmt|;
name|class
name|CodeCompleteConsumer
decl_stmt|;
name|class
name|CodeCompletionAllocator
decl_stmt|;
name|class
name|CodeCompletionResult
decl_stmt|;
name|class
name|Decl
decl_stmt|;
name|class
name|DeclAccessPair
decl_stmt|;
name|class
name|DeclContext
decl_stmt|;
name|class
name|DeclRefExpr
decl_stmt|;
name|class
name|DeclaratorDecl
decl_stmt|;
name|class
name|DeducedTemplateArgument
decl_stmt|;
name|class
name|DependentDiagnostic
decl_stmt|;
name|class
name|DesignatedInitExpr
decl_stmt|;
name|class
name|Designation
decl_stmt|;
name|class
name|EnumConstantDecl
decl_stmt|;
name|class
name|Expr
decl_stmt|;
name|class
name|ExtVectorType
decl_stmt|;
name|class
name|ExternalSemaSource
decl_stmt|;
name|class
name|FormatAttr
decl_stmt|;
name|class
name|FriendDecl
decl_stmt|;
name|class
name|FunctionDecl
decl_stmt|;
name|class
name|FunctionProtoType
decl_stmt|;
name|class
name|FunctionTemplateDecl
decl_stmt|;
name|class
name|ImplicitConversionSequence
decl_stmt|;
name|class
name|InitListExpr
decl_stmt|;
name|class
name|InitializationKind
decl_stmt|;
name|class
name|InitializationSequence
decl_stmt|;
name|class
name|InitializedEntity
decl_stmt|;
name|class
name|IntegerLiteral
decl_stmt|;
name|class
name|LabelStmt
decl_stmt|;
name|class
name|LangOptions
decl_stmt|;
name|class
name|LocalInstantiationScope
decl_stmt|;
name|class
name|LookupResult
decl_stmt|;
name|class
name|MacroInfo
decl_stmt|;
name|class
name|MultiLevelTemplateArgumentList
decl_stmt|;
name|class
name|NamedDecl
decl_stmt|;
name|class
name|NonNullAttr
decl_stmt|;
name|class
name|ObjCCategoryDecl
decl_stmt|;
name|class
name|ObjCCategoryImplDecl
decl_stmt|;
name|class
name|ObjCCompatibleAliasDecl
decl_stmt|;
name|class
name|ObjCContainerDecl
decl_stmt|;
name|class
name|ObjCImplDecl
decl_stmt|;
name|class
name|ObjCImplementationDecl
decl_stmt|;
name|class
name|ObjCInterfaceDecl
decl_stmt|;
name|class
name|ObjCIvarDecl
decl_stmt|;
name|template
operator|<
name|class
name|T
operator|>
name|class
name|ObjCList
expr_stmt|;
name|class
name|ObjCMethodDecl
decl_stmt|;
name|class
name|ObjCPropertyDecl
decl_stmt|;
name|class
name|ObjCProtocolDecl
decl_stmt|;
name|class
name|OverloadCandidateSet
decl_stmt|;
name|class
name|OverloadExpr
decl_stmt|;
name|class
name|ParenListExpr
decl_stmt|;
name|class
name|ParmVarDecl
decl_stmt|;
name|class
name|Preprocessor
decl_stmt|;
name|class
name|PseudoDestructorTypeStorage
decl_stmt|;
name|class
name|QualType
decl_stmt|;
name|class
name|StandardConversionSequence
decl_stmt|;
name|class
name|Stmt
decl_stmt|;
name|class
name|StringLiteral
decl_stmt|;
name|class
name|SwitchStmt
decl_stmt|;
name|class
name|TargetAttributesSema
decl_stmt|;
name|class
name|TemplateArgument
decl_stmt|;
name|class
name|TemplateArgumentList
decl_stmt|;
name|class
name|TemplateArgumentLoc
decl_stmt|;
name|class
name|TemplateDecl
decl_stmt|;
name|class
name|TemplateParameterList
decl_stmt|;
name|class
name|TemplatePartialOrderingContext
decl_stmt|;
name|class
name|TemplateTemplateParmDecl
decl_stmt|;
name|class
name|Token
decl_stmt|;
name|class
name|TypeAliasDecl
decl_stmt|;
name|class
name|TypedefDecl
decl_stmt|;
name|class
name|TypedefNameDecl
decl_stmt|;
name|class
name|TypeLoc
decl_stmt|;
name|class
name|UnqualifiedId
decl_stmt|;
name|class
name|UnresolvedLookupExpr
decl_stmt|;
name|class
name|UnresolvedMemberExpr
decl_stmt|;
name|class
name|UnresolvedSetImpl
decl_stmt|;
name|class
name|UnresolvedSetIterator
decl_stmt|;
name|class
name|UsingDecl
decl_stmt|;
name|class
name|UsingShadowDecl
decl_stmt|;
name|class
name|ValueDecl
decl_stmt|;
name|class
name|VarDecl
decl_stmt|;
name|class
name|VisibilityAttr
decl_stmt|;
name|class
name|VisibleDeclConsumer
decl_stmt|;
name|class
name|IndirectFieldDecl
decl_stmt|;
name|namespace
name|sema
block|{
name|class
name|AccessedEntity
decl_stmt|;
name|class
name|BlockScopeInfo
decl_stmt|;
name|class
name|DelayedDiagnostic
decl_stmt|;
name|class
name|FunctionScopeInfo
decl_stmt|;
name|class
name|TemplateDeductionInfo
decl_stmt|;
block|}
comment|/// \brief Holds a QualType and a TypeSourceInfo* that came out of a declarator
comment|/// parsing.
comment|///
comment|/// LocInfoType is a "transient" type, only needed for passing to/from Parser
comment|/// and Sema, when we want to preserve type source info for a parsed type.
comment|/// It will not participate in the type system semantics in any way.
name|class
name|LocInfoType
range|:
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
argument_list|,
name|ty
operator|->
name|isVariablyModifiedType
argument_list|()
argument_list|,
name|ty
operator|->
name|containsUnexpandedParameterPack
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
comment|// FIXME: No way to easily map from TemplateTypeParmTypes to
comment|// TemplateTypeParmDecls, so we have this horrible PointerUnion.
typedef|typedef
name|std
operator|::
name|pair
operator|<
name|llvm
operator|::
name|PointerUnion
operator|<
specifier|const
name|TemplateTypeParmType
operator|*
operator|,
name|NamedDecl
operator|*
operator|>
operator|,
name|SourceLocation
operator|>
name|UnexpandedParameterPack
expr_stmt|;
comment|/// Sema - This implements semantic analysis and AST building for C.
name|class
name|Sema
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
typedef|typedef
name|OpaquePtr
operator|<
name|DeclGroupRef
operator|>
name|DeclGroupPtrTy
expr_stmt|;
typedef|typedef
name|OpaquePtr
operator|<
name|TemplateName
operator|>
name|TemplateTy
expr_stmt|;
typedef|typedef
name|OpaquePtr
operator|<
name|QualType
operator|>
name|TypeTy
expr_stmt|;
typedef|typedef
name|Attr
name|AttrTy
typedef|;
typedef|typedef
name|CXXBaseSpecifier
name|BaseTy
typedef|;
typedef|typedef
name|CXXCtorInitializer
name|MemInitTy
typedef|;
typedef|typedef
name|Expr
name|ExprTy
typedef|;
typedef|typedef
name|Stmt
name|StmtTy
typedef|;
typedef|typedef
name|TemplateParameterList
name|TemplateParamsTy
typedef|;
typedef|typedef
name|NestedNameSpecifier
name|CXXScopeTy
typedef|;
name|OpenCLOptions
name|OpenCLFeatures
decl_stmt|;
name|FPOptions
name|FPFeatures
decl_stmt|;
specifier|const
name|LangOptions
modifier|&
name|LangOpts
decl_stmt|;
name|Preprocessor
modifier|&
name|PP
decl_stmt|;
name|ASTContext
modifier|&
name|Context
decl_stmt|;
name|ASTConsumer
modifier|&
name|Consumer
decl_stmt|;
name|Diagnostic
modifier|&
name|Diags
decl_stmt|;
name|SourceManager
modifier|&
name|SourceMgr
decl_stmt|;
comment|/// \brief Source of additional semantic information.
name|ExternalSemaSource
modifier|*
name|ExternalSource
decl_stmt|;
comment|/// \brief Code-completion consumer.
name|CodeCompleteConsumer
modifier|*
name|CodeCompleter
decl_stmt|;
comment|/// CurContext - This is the current declaration context of parsing.
name|DeclContext
modifier|*
name|CurContext
decl_stmt|;
comment|/// VAListTagName - The declaration name corresponding to __va_list_tag.
comment|/// This is used as part of a hack to omit that class from ADL results.
name|DeclarationName
name|VAListTagName
decl_stmt|;
comment|/// PackContext - Manages the stack for #pragma pack. An alignment
comment|/// of 0 indicates default alignment.
name|void
modifier|*
name|PackContext
decl_stmt|;
comment|// Really a "PragmaPackStack*"
name|bool
name|MSStructPragmaOn
decl_stmt|;
comment|// True when #pragma ms_struct on
comment|/// VisContext - Manages the stack for #pragma GCC visibility.
name|void
modifier|*
name|VisContext
decl_stmt|;
comment|// Really a "PragmaVisStack*"
comment|/// \brief Stack containing information about each of the nested
comment|/// function, block, and method scopes that are currently active.
comment|///
comment|/// This array is never empty.  Clients should ignore the first
comment|/// element, which is used to cache a single FunctionScopeInfo
comment|/// that's used to parse every top-level function.
name|llvm
operator|::
name|SmallVector
operator|<
name|sema
operator|::
name|FunctionScopeInfo
operator|*
operator|,
literal|4
operator|>
name|FunctionScopes
expr_stmt|;
comment|/// ExprTemporaries - This is the stack of temporaries that are created by
comment|/// the current full expression.
name|llvm
operator|::
name|SmallVector
operator|<
name|CXXTemporary
operator|*
operator|,
literal|8
operator|>
name|ExprTemporaries
expr_stmt|;
comment|/// ExtVectorDecls - This is a list all the extended vector types. This allows
comment|/// us to associate a raw vector type with one of the ext_vector type names.
comment|/// This is only necessary for issuing pretty diagnostics.
name|llvm
operator|::
name|SmallVector
operator|<
name|TypedefNameDecl
operator|*
operator|,
literal|24
operator|>
name|ExtVectorDecls
expr_stmt|;
comment|/// FieldCollector - Collects CXXFieldDecls during parsing of C++ classes.
name|llvm
operator|::
name|OwningPtr
operator|<
name|CXXFieldCollector
operator|>
name|FieldCollector
expr_stmt|;
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
expr_stmt|;
comment|/// ParsingInitForAutoVars - a set of declarations with auto types for which
comment|/// we are currently parsing the initializer.
name|llvm
operator|::
name|SmallPtrSet
operator|<
specifier|const
name|Decl
operator|*
operator|,
literal|4
operator|>
name|ParsingInitForAutoVars
expr_stmt|;
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
operator|,
name|NamedDecl
operator|*
operator|>
name|LocallyScopedExternalDecls
expr_stmt|;
comment|/// \brief All the tentative definitions encountered in the TU.
name|llvm
operator|::
name|SmallVector
operator|<
name|VarDecl
operator|*
operator|,
literal|2
operator|>
name|TentativeDefinitions
expr_stmt|;
comment|/// \brief The set of file scoped decls seen so far that have not been used
comment|/// and must warn if not used. Only contains the first declaration.
name|llvm
operator|::
name|SmallVector
operator|<
specifier|const
name|DeclaratorDecl
operator|*
operator|,
literal|4
operator|>
name|UnusedFileScopedDecls
expr_stmt|;
comment|/// \brief Callback to the parser to parse templated functions when needed.
typedef|typedef
name|void
name|LateTemplateParserCB
parameter_list|(
name|void
modifier|*
name|P
parameter_list|,
specifier|const
name|FunctionDecl
modifier|*
name|FD
parameter_list|)
function_decl|;
name|LateTemplateParserCB
modifier|*
name|LateTemplateParser
decl_stmt|;
name|void
modifier|*
name|OpaqueParser
decl_stmt|;
name|void
name|SetLateTemplateParser
parameter_list|(
name|LateTemplateParserCB
modifier|*
name|LTP
parameter_list|,
name|void
modifier|*
name|P
parameter_list|)
block|{
name|LateTemplateParser
operator|=
name|LTP
expr_stmt|;
name|OpaqueParser
operator|=
name|P
expr_stmt|;
block|}
name|class
name|DelayedDiagnostics
decl_stmt|;
name|class
name|ParsingDeclState
block|{
name|unsigned
name|SavedStackSize
decl_stmt|;
name|friend
name|class
name|Sema
operator|::
name|DelayedDiagnostics
expr_stmt|;
block|}
empty_stmt|;
name|class
name|ProcessingContextState
block|{
name|unsigned
name|SavedParsingDepth
decl_stmt|;
name|unsigned
name|SavedActiveStackBase
decl_stmt|;
name|friend
name|class
name|Sema
operator|::
name|DelayedDiagnostics
expr_stmt|;
block|}
empty_stmt|;
comment|/// A class which encapsulates the logic for delaying diagnostics
comment|/// during parsing and other processing.
name|class
name|DelayedDiagnostics
block|{
comment|/// \brief The stack of diagnostics that were delayed due to being
comment|/// produced during the parsing of a declaration.
name|sema
operator|::
name|DelayedDiagnostic
operator|*
name|Stack
expr_stmt|;
comment|/// \brief The number of objects on the delayed-diagnostics stack.
name|unsigned
name|StackSize
decl_stmt|;
comment|/// \brief The current capacity of the delayed-diagnostics stack.
name|unsigned
name|StackCapacity
decl_stmt|;
comment|/// \brief The index of the first "active" delayed diagnostic in
comment|/// the stack.  When parsing class definitions, we ignore active
comment|/// delayed diagnostics from the surrounding context.
name|unsigned
name|ActiveStackBase
decl_stmt|;
comment|/// \brief The depth of the declarations we're currently parsing.
comment|/// This gets saved and reset whenever we enter a class definition.
name|unsigned
name|ParsingDepth
decl_stmt|;
name|public
label|:
name|DelayedDiagnostics
argument_list|()
operator|:
name|Stack
argument_list|(
literal|0
argument_list|)
operator|,
name|StackSize
argument_list|(
literal|0
argument_list|)
operator|,
name|StackCapacity
argument_list|(
literal|0
argument_list|)
operator|,
name|ActiveStackBase
argument_list|(
literal|0
argument_list|)
operator|,
name|ParsingDepth
argument_list|(
literal|0
argument_list|)
block|{}
operator|~
name|DelayedDiagnostics
argument_list|()
block|{
name|delete
index|[]
name|reinterpret_cast
operator|<
name|char
operator|*
operator|>
operator|(
name|Stack
operator|)
block|;     }
comment|/// Adds a delayed diagnostic.
name|void
name|add
argument_list|(
specifier|const
name|sema
operator|::
name|DelayedDiagnostic
operator|&
name|diag
argument_list|)
expr_stmt|;
comment|/// Determines whether diagnostics should be delayed.
name|bool
name|shouldDelayDiagnostics
parameter_list|()
block|{
return|return
name|ParsingDepth
operator|>
literal|0
return|;
block|}
comment|/// Observe that we've started parsing a declaration.  Access and
comment|/// deprecation diagnostics will be delayed; when the declaration
comment|/// is completed, all active delayed diagnostics will be evaluated
comment|/// in its context, and then active diagnostics stack will be
comment|/// popped down to the saved depth.
name|ParsingDeclState
name|pushParsingDecl
parameter_list|()
block|{
name|ParsingDepth
operator|++
expr_stmt|;
name|ParsingDeclState
name|state
decl_stmt|;
name|state
operator|.
name|SavedStackSize
operator|=
name|StackSize
expr_stmt|;
return|return
name|state
return|;
block|}
comment|/// Observe that we're completed parsing a declaration.
specifier|static
name|void
name|popParsingDecl
parameter_list|(
name|Sema
modifier|&
name|S
parameter_list|,
name|ParsingDeclState
name|state
parameter_list|,
name|Decl
modifier|*
name|decl
parameter_list|)
function_decl|;
comment|/// Observe that we've started processing a different context, the
comment|/// contents of which are semantically separate from the
comment|/// declarations it may lexically appear in.  This sets aside the
comment|/// current stack of active diagnostics and starts afresh.
name|ProcessingContextState
name|pushContext
parameter_list|()
block|{
name|assert
argument_list|(
name|StackSize
operator|>=
name|ActiveStackBase
argument_list|)
expr_stmt|;
name|ProcessingContextState
name|state
decl_stmt|;
name|state
operator|.
name|SavedParsingDepth
operator|=
name|ParsingDepth
expr_stmt|;
name|state
operator|.
name|SavedActiveStackBase
operator|=
name|ActiveStackBase
expr_stmt|;
name|ActiveStackBase
operator|=
name|StackSize
expr_stmt|;
name|ParsingDepth
operator|=
literal|0
expr_stmt|;
return|return
name|state
return|;
block|}
comment|/// Observe that we've stopped processing a context.  This
comment|/// restores the previous stack of active diagnostics.
name|void
name|popContext
parameter_list|(
name|ProcessingContextState
name|state
parameter_list|)
block|{
name|assert
argument_list|(
name|ActiveStackBase
operator|==
name|StackSize
argument_list|)
expr_stmt|;
name|assert
argument_list|(
name|ParsingDepth
operator|==
literal|0
argument_list|)
expr_stmt|;
name|ActiveStackBase
operator|=
name|state
operator|.
name|SavedActiveStackBase
expr_stmt|;
name|ParsingDepth
operator|=
name|state
operator|.
name|SavedParsingDepth
expr_stmt|;
block|}
block|}
name|DelayedDiagnostics
expr_stmt|;
comment|/// A RAII object to temporarily push a declaration context.
name|class
name|ContextRAII
block|{
name|private
label|:
name|Sema
modifier|&
name|S
decl_stmt|;
name|DeclContext
modifier|*
name|SavedContext
decl_stmt|;
name|ProcessingContextState
name|SavedContextState
decl_stmt|;
name|public
label|:
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
operator|,
name|SavedContext
argument_list|(
name|S
operator|.
name|CurContext
argument_list|)
operator|,
name|SavedContextState
argument_list|(
argument|S.DelayedDiagnostics.pushContext()
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
expr_stmt|;
name|S
operator|.
name|DelayedDiagnostics
operator|.
name|popContext
argument_list|(
name|SavedContextState
argument_list|)
expr_stmt|;
name|SavedContext
operator|=
literal|0
expr_stmt|;
block|}
operator|~
name|ContextRAII
argument_list|()
block|{
name|pop
argument_list|()
block|;     }
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|/// WeakUndeclaredIdentifiers - Identifiers contained in
end_comment

begin_comment
comment|/// #pragma weak before declared. rare. may alias another
end_comment

begin_comment
comment|/// identifier, declared or undeclared
end_comment

begin_decl_stmt
name|class
name|WeakInfo
block|{
name|IdentifierInfo
modifier|*
name|alias
decl_stmt|;
comment|// alias (optional)
name|SourceLocation
name|loc
decl_stmt|;
comment|// for diagnostics
name|bool
name|used
decl_stmt|;
comment|// identifier later declared?
name|public
label|:
name|WeakInfo
argument_list|()
operator|:
name|alias
argument_list|(
literal|0
argument_list|)
operator|,
name|loc
argument_list|(
name|SourceLocation
argument_list|()
argument_list|)
operator|,
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
operator|,
name|loc
argument_list|(
name|Loc
argument_list|)
operator|,
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
parameter_list|(
name|bool
name|Used
init|=
name|true
parameter_list|)
block|{
name|used
operator|=
name|Used
expr_stmt|;
block|}
specifier|inline
name|bool
name|getUsed
parameter_list|()
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
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_expr_stmt
name|llvm
operator|::
name|DenseMap
operator|<
name|IdentifierInfo
operator|*
operator|,
name|WeakInfo
operator|>
name|WeakUndeclaredIdentifiers
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// WeakTopLevelDecl - Translation-unit scoped declarations generated by
end_comment

begin_comment
comment|/// #pragma weak during processing of other Decls.
end_comment

begin_comment
comment|/// I couldn't figure out a clean way to generate these in-line, so
end_comment

begin_comment
comment|/// we store them here and handle separately -- which is a hack.
end_comment

begin_comment
comment|/// It would be best to refactor this.
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
name|WeakTopLevelDecl
expr_stmt|;
end_expr_stmt

begin_decl_stmt
name|IdentifierResolver
name|IdResolver
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// Translation Unit Scope - useful to Objective-C actions that need
end_comment

begin_comment
comment|/// to lookup file scope declarations in the "ordinary" C decl namespace.
end_comment

begin_comment
comment|/// For example, user-defined classes, built-in "id" type, etc.
end_comment

begin_decl_stmt
name|Scope
modifier|*
name|TUScope
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// \brief The C++ "std" namespace, where the standard library resides.
end_comment

begin_decl_stmt
name|LazyDeclPtr
name|StdNamespace
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// \brief The C++ "std::bad_alloc" class, which is defined by the C++
end_comment

begin_comment
comment|/// standard library.
end_comment

begin_decl_stmt
name|LazyDeclPtr
name|StdBadAlloc
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// \brief The C++ "type_info" declaration, which is defined in<typeinfo>.
end_comment

begin_decl_stmt
name|RecordDecl
modifier|*
name|CXXTypeInfoDecl
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// \brief The MSVC "_GUID" struct, which is defined in MSVC header files.
end_comment

begin_decl_stmt
name|RecordDecl
modifier|*
name|MSVCGuidDecl
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// A flag to remember whether the implicit forms of operator new and delete
end_comment

begin_comment
comment|/// have been declared.
end_comment

begin_decl_stmt
name|bool
name|GlobalNewDeleteDeclared
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// \brief The set of declarations that have been referenced within
end_comment

begin_comment
comment|/// a potentially evaluated expression.
end_comment

begin_typedef
typedef|typedef
name|llvm
operator|::
name|SmallVector
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
operator|,
literal|10
operator|>
name|PotentiallyReferencedDecls
expr_stmt|;
end_typedef

begin_comment
comment|/// \brief A set of diagnostics that may be emitted.
end_comment

begin_typedef
typedef|typedef
name|llvm
operator|::
name|SmallVector
operator|<
name|std
operator|::
name|pair
operator|<
name|SourceLocation
operator|,
name|PartialDiagnostic
operator|>
operator|,
literal|10
operator|>
name|PotentiallyEmittedDiagnostics
expr_stmt|;
end_typedef

begin_comment
comment|/// \brief Describes how the expressions currently being parsed are
end_comment

begin_comment
comment|/// evaluated at run-time, if at all.
end_comment

begin_enum
enum|enum
name|ExpressionEvaluationContext
block|{
comment|/// \brief The current expression and its subexpressions occur within an
comment|/// unevaluated operand (C++0x [expr]p8), such as a constant expression
comment|/// or the subexpression of \c sizeof, where the type or the value of the
comment|/// expression may be significant but no code will be generated to evaluate
comment|/// the value of the expression at run time.
name|Unevaluated
block|,
comment|/// \brief The current expression is potentially evaluated at run time,
comment|/// which means that code may be generated to evaluate the value of the
comment|/// expression at run time.
name|PotentiallyEvaluated
block|,
comment|/// \brief The current expression may be potentially evaluated or it may
comment|/// be unevaluated, but it is impossible to tell from the lexical context.
comment|/// This evaluation context is used primary for the operand of the C++
comment|/// \c typeid expression, whose argument is potentially evaluated only when
comment|/// it is an lvalue of polymorphic class type (C++ [basic.def.odr]p2).
name|PotentiallyPotentiallyEvaluated
block|,
comment|/// \brief The current expression is potentially evaluated, but any
comment|/// declarations referenced inside that expression are only used if
comment|/// in fact the current expression is used.
comment|///
comment|/// This value is used when parsing default function arguments, for which
comment|/// we would like to provide diagnostics (e.g., passing non-POD arguments
comment|/// through varargs) but do not want to mark declarations as "referenced"
comment|/// until the default argument is used.
name|PotentiallyEvaluatedIfUsed
block|}
enum|;
end_enum

begin_comment
comment|/// \brief Data structure used to record current or nested
end_comment

begin_comment
comment|/// expression evaluation contexts.
end_comment

begin_struct
struct|struct
name|ExpressionEvaluationContextRecord
block|{
comment|/// \brief The expression evaluation context.
name|ExpressionEvaluationContext
name|Context
decl_stmt|;
comment|/// \brief The number of temporaries that were active when we
comment|/// entered this expression evaluation context.
name|unsigned
name|NumTemporaries
decl_stmt|;
comment|/// \brief The set of declarations referenced within a
comment|/// potentially potentially-evaluated context.
comment|///
comment|/// When leaving a potentially potentially-evaluated context, each
comment|/// of these elements will be as referenced if the corresponding
comment|/// potentially potentially evaluated expression is potentially
comment|/// evaluated.
name|PotentiallyReferencedDecls
modifier|*
name|PotentiallyReferenced
decl_stmt|;
comment|/// \brief The set of diagnostics to emit should this potentially
comment|/// potentially-evaluated context become evaluated.
name|PotentiallyEmittedDiagnostics
modifier|*
name|PotentiallyDiagnosed
decl_stmt|;
name|ExpressionEvaluationContextRecord
argument_list|(
argument|ExpressionEvaluationContext Context
argument_list|,
argument|unsigned NumTemporaries
argument_list|)
block|:
name|Context
argument_list|(
name|Context
argument_list|)
operator|,
name|NumTemporaries
argument_list|(
name|NumTemporaries
argument_list|)
operator|,
name|PotentiallyReferenced
argument_list|(
literal|0
argument_list|)
operator|,
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
expr_stmt|;
block|}
name|void
name|addDiagnostic
argument_list|(
name|SourceLocation
name|Loc
argument_list|,
specifier|const
name|PartialDiagnostic
operator|&
name|PD
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
expr_stmt|;
block|}
name|void
name|Destroy
argument_list|()
block|{
name|delete
name|PotentiallyReferenced
decl_stmt|;
name|delete
name|PotentiallyDiagnosed
decl_stmt|;
name|PotentiallyReferenced
operator|=
literal|0
expr_stmt|;
name|PotentiallyDiagnosed
operator|=
literal|0
expr_stmt|;
block|}
end_struct

begin_comment
unit|};
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
name|ParmVarDecl
operator|*
operator|,
name|llvm
operator|::
name|SmallVector
operator|<
name|ParmVarDecl
operator|*
operator|,
literal|1
operator|>
expr|>
name|UnparsedDefaultArgInstantiationsMap
expr_stmt|;
end_typedef

begin_comment
comment|/// \brief A mapping from parameters with unparsed default arguments to the
end_comment

begin_comment
comment|/// set of instantiations of each parameter.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This mapping is a temporary data structure used when parsing
end_comment

begin_comment
comment|/// nested class templates or nested classes of class templates,
end_comment

begin_comment
comment|/// where we might end up instantiating an inner class before the
end_comment

begin_comment
comment|/// default arguments of its methods have been parsed.
end_comment

begin_decl_stmt
name|UnparsedDefaultArgInstantiationsMap
name|UnparsedDefaultArgInstantiations
decl_stmt|;
end_decl_stmt

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

begin_comment
comment|/// UndefinedInternals - all the used, undefined objects with
end_comment

begin_comment
comment|/// internal linkage in this translation unit.
end_comment

begin_expr_stmt
name|llvm
operator|::
name|DenseMap
operator|<
name|NamedDecl
operator|*
operator|,
name|SourceLocation
operator|>
name|UndefinedInternals
expr_stmt|;
end_expr_stmt

begin_typedef
typedef|typedef
name|std
operator|::
name|pair
operator|<
name|ObjCMethodList
operator|,
name|ObjCMethodList
operator|>
name|GlobalMethods
expr_stmt|;
end_typedef

begin_typedef
typedef|typedef
name|llvm
operator|::
name|DenseMap
operator|<
name|Selector
operator|,
name|GlobalMethods
operator|>
name|GlobalMethodPool
expr_stmt|;
end_typedef

begin_comment
comment|/// Method Pool - allows efficient lookup when typechecking messages to "id".
end_comment

begin_comment
comment|/// We need to maintain a list, since selectors can have differing signatures
end_comment

begin_comment
comment|/// across classes. In Cocoa, this happens to be extremely uncommon (only 1%
end_comment

begin_comment
comment|/// of selectors are "overloaded").
end_comment

begin_decl_stmt
name|GlobalMethodPool
name|MethodPool
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// Method selectors used in a @selector expression. Used for implementation
end_comment

begin_comment
comment|/// of -Wselector.
end_comment

begin_expr_stmt
name|llvm
operator|::
name|DenseMap
operator|<
name|Selector
operator|,
name|SourceLocation
operator|>
name|ReferencedSelectors
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|GlobalMethodPool
operator|::
name|iterator
name|ReadMethodPool
argument_list|(
argument|Selector Sel
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

begin_comment
comment|/// \brief Perform initialization that occurs after the parser has been
end_comment

begin_comment
comment|/// initialized but before it parses anything.
end_comment

begin_function_decl
name|void
name|Initialize
parameter_list|()
function_decl|;
end_function_decl

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

begin_function
name|OpenCLOptions
modifier|&
name|getOpenCLOptions
parameter_list|()
block|{
return|return
name|OpenCLFeatures
return|;
block|}
end_function

begin_function
name|FPOptions
modifier|&
name|getFPOptions
parameter_list|()
block|{
return|return
name|FPFeatures
return|;
block|}
end_function

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

begin_expr_stmt
name|Preprocessor
operator|&
name|getPreprocessor
argument_list|()
specifier|const
block|{
return|return
name|PP
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|ASTContext
operator|&
name|getASTContext
argument_list|()
specifier|const
block|{
return|return
name|Context
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|ASTConsumer
operator|&
name|getASTConsumer
argument_list|()
specifier|const
block|{
return|return
name|Consumer
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|ASTMutationListener
operator|*
name|getASTMutationListener
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

begin_function_decl
name|PartialDiagnostic
name|PDiag
parameter_list|(
name|unsigned
name|DiagID
init|=
literal|0
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|// in SemaInternal.h
end_comment

begin_decl_stmt
name|bool
name|findMacroSpelling
argument_list|(
name|SourceLocation
operator|&
name|loc
argument_list|,
name|llvm
operator|::
name|StringRef
name|name
argument_list|)
decl_stmt|;
end_decl_stmt

begin_function
name|ExprResult
name|Owned
parameter_list|(
name|Expr
modifier|*
name|E
parameter_list|)
block|{
return|return
name|E
return|;
block|}
end_function

begin_function
name|ExprResult
name|Owned
parameter_list|(
name|ExprResult
name|R
parameter_list|)
block|{
return|return
name|R
return|;
block|}
end_function

begin_function
name|StmtResult
name|Owned
parameter_list|(
name|Stmt
modifier|*
name|S
parameter_list|)
block|{
return|return
name|S
return|;
block|}
end_function

begin_function_decl
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

begin_decl_stmt
name|void
name|PopFunctionOrBlockScope
argument_list|(
specifier|const
name|sema
operator|::
name|AnalysisBasedWarnings
operator|::
name|Policy
operator|*
name|WP
operator|=
literal|0
argument_list|,
specifier|const
name|Decl
operator|*
name|D
operator|=
literal|0
argument_list|,
specifier|const
name|BlockExpr
operator|*
name|blkExpr
operator|=
literal|0
argument_list|)
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|sema
operator|::
name|FunctionScopeInfo
operator|*
name|getCurFunction
argument_list|()
specifier|const
block|{
return|return
name|FunctionScopes
operator|.
name|back
argument_list|()
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|bool
name|hasAnyErrorsInThisFunction
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// \brief Retrieve the current block, if any.
end_comment

begin_expr_stmt
name|sema
operator|::
name|BlockScopeInfo
operator|*
name|getCurBlock
argument_list|()
expr_stmt|;
end_expr_stmt

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
name|Expr
modifier|*
name|ArraySize
parameter_list|,
name|SourceLocation
name|AttrLoc
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
name|QualType
name|BuildFunctionType
argument_list|(
name|QualType
name|T
argument_list|,
name|QualType
operator|*
name|ParamTypes
argument_list|,
name|unsigned
name|NumParamTypes
argument_list|,
name|bool
name|Variadic
argument_list|,
name|unsigned
name|Quals
argument_list|,
name|RefQualifierKind
name|RefQualifier
argument_list|,
name|SourceLocation
name|Loc
argument_list|,
name|DeclarationName
name|Entity
argument_list|,
name|FunctionType
operator|::
name|ExtInfo
name|Info
argument_list|)
decl_stmt|;
end_decl_stmt

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
name|QualType
name|BuildParenType
parameter_list|(
name|QualType
name|T
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
parameter_list|,
name|bool
name|AllowAutoInTypeName
init|=
name|false
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
comment|/// \brief Package the given type and TSI into a ParsedType.
end_comment

begin_function_decl
name|ParsedType
name|CreateParsedType
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
name|DeclarationNameInfo
name|GetNameForDeclarator
parameter_list|(
name|Declarator
modifier|&
name|D
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|DeclarationNameInfo
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
name|ParsedType
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
parameter_list|,
name|bool
name|AllowNoexceptAllMatchWithNoSpec
init|=
name|false
parameter_list|,
name|bool
name|IsOperatorNew
init|=
name|false
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
parameter_list|,
name|SourceLocation
name|Loc
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
parameter_list|,
name|SourceLocation
name|Loc
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

begin_function_decl
name|DeclGroupPtrTy
name|ConvertDeclToDeclGroup
parameter_list|(
name|Decl
modifier|*
name|Ptr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|DiagnoseUseOfUnimplementedSelectors
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|ParsedType
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
init|=
literal|0
parameter_list|,
name|bool
name|isClassName
init|=
name|false
parameter_list|,
name|bool
name|HasTrailingDot
init|=
name|false
parameter_list|,
name|ParsedType
name|ObjectType
init|=
name|ParsedType
argument_list|()
parameter_list|,
name|bool
name|WantNontrivialTypeSourceInfo
init|=
name|false
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|TypeSpecifierType
name|isTagName
parameter_list|(
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
name|bool
name|isMicrosoftMissingTypename
parameter_list|(
specifier|const
name|CXXScopeSpec
modifier|*
name|SS
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
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
name|ParsedType
modifier|&
name|SuggestedType
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// \brief Describes the result of the name lookup and resolution performed
end_comment

begin_comment
comment|/// by \c ClassifyName().
end_comment

begin_enum
enum|enum
name|NameClassificationKind
block|{
name|NC_Unknown
block|,
name|NC_Error
block|,
name|NC_Keyword
block|,
name|NC_Type
block|,
name|NC_Expression
block|,
name|NC_NestedNameSpecifier
block|,
name|NC_TypeTemplate
block|,
name|NC_FunctionTemplate
block|}
enum|;
end_enum

begin_decl_stmt
name|class
name|NameClassification
block|{
name|NameClassificationKind
name|Kind
decl_stmt|;
name|ExprResult
name|Expr
decl_stmt|;
name|TemplateName
name|Template
decl_stmt|;
name|ParsedType
name|Type
decl_stmt|;
specifier|const
name|IdentifierInfo
modifier|*
name|Keyword
decl_stmt|;
name|explicit
name|NameClassification
argument_list|(
argument|NameClassificationKind Kind
argument_list|)
block|:
name|Kind
argument_list|(
argument|Kind
argument_list|)
block|{}
name|public
label|:
name|NameClassification
argument_list|(
argument|ExprResult Expr
argument_list|)
block|:
name|Kind
argument_list|(
name|NC_Expression
argument_list|)
operator|,
name|Expr
argument_list|(
argument|Expr
argument_list|)
block|{}
name|NameClassification
argument_list|(
argument|ParsedType Type
argument_list|)
operator|:
name|Kind
argument_list|(
name|NC_Type
argument_list|)
operator|,
name|Type
argument_list|(
argument|Type
argument_list|)
block|{}
name|NameClassification
argument_list|(
specifier|const
name|IdentifierInfo
operator|*
name|Keyword
argument_list|)
operator|:
name|Kind
argument_list|(
name|NC_Keyword
argument_list|)
operator|,
name|Keyword
argument_list|(
argument|Keyword
argument_list|)
block|{ }
specifier|static
name|NameClassification
name|Error
argument_list|()
block|{
return|return
name|NameClassification
argument_list|(
name|NC_Error
argument_list|)
return|;
block|}
specifier|static
name|NameClassification
name|Unknown
parameter_list|()
block|{
return|return
name|NameClassification
argument_list|(
name|NC_Unknown
argument_list|)
return|;
block|}
specifier|static
name|NameClassification
name|NestedNameSpecifier
parameter_list|()
block|{
return|return
name|NameClassification
argument_list|(
name|NC_NestedNameSpecifier
argument_list|)
return|;
block|}
specifier|static
name|NameClassification
name|TypeTemplate
parameter_list|(
name|TemplateName
name|Name
parameter_list|)
block|{
name|NameClassification
name|Result
argument_list|(
name|NC_TypeTemplate
argument_list|)
decl_stmt|;
name|Result
operator|.
name|Template
operator|=
name|Name
expr_stmt|;
return|return
name|Result
return|;
block|}
specifier|static
name|NameClassification
name|FunctionTemplate
parameter_list|(
name|TemplateName
name|Name
parameter_list|)
block|{
name|NameClassification
name|Result
argument_list|(
name|NC_FunctionTemplate
argument_list|)
decl_stmt|;
name|Result
operator|.
name|Template
operator|=
name|Name
expr_stmt|;
return|return
name|Result
return|;
block|}
name|NameClassificationKind
name|getKind
argument_list|()
specifier|const
block|{
return|return
name|Kind
return|;
block|}
name|ParsedType
name|getType
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
name|Kind
operator|==
name|NC_Type
argument_list|)
block|;
return|return
name|Type
return|;
block|}
name|ExprResult
name|getExpression
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
name|Kind
operator|==
name|NC_Expression
argument_list|)
block|;
return|return
name|Expr
return|;
block|}
name|TemplateName
name|getTemplateName
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
name|Kind
operator|==
name|NC_TypeTemplate
operator|||
name|Kind
operator|==
name|NC_FunctionTemplate
argument_list|)
block|;
return|return
name|Template
return|;
block|}
name|TemplateNameKind
name|getTemplateNameKind
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
name|Kind
operator|==
name|NC_TypeTemplate
operator|||
name|Kind
operator|==
name|NC_FunctionTemplate
argument_list|)
block|;
return|return
name|Kind
operator|==
name|NC_TypeTemplate
condition|?
name|TNK_Type_template
else|:
name|TNK_Function_template
return|;
block|}
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|/// \brief Perform name lookup on the given name, classifying it based on
end_comment

begin_comment
comment|/// the results of name lookup and the following token.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This routine is used by the parser to resolve identifiers and help direct
end_comment

begin_comment
comment|/// parsing. When the identifier cannot be found, this routine will attempt
end_comment

begin_comment
comment|/// to correct the typo and classify based on the resulting name.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param S The scope in which we're performing name lookup.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param SS The nested-name-specifier that precedes the name.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param Name The identifier. If typo correction finds an alternative name,
end_comment

begin_comment
comment|/// this pointer parameter will be updated accordingly.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param NameLoc The location of the identifier.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param NextToken The token following the identifier. Used to help
end_comment

begin_comment
comment|/// disambiguate the name.
end_comment

begin_function_decl
name|NameClassification
name|ClassifyName
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
modifier|*
modifier|&
name|Name
parameter_list|,
name|SourceLocation
name|NameLoc
parameter_list|,
specifier|const
name|Token
modifier|&
name|NextToken
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|Decl
modifier|*
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
function_decl|;
end_function_decl

begin_function_decl
name|Decl
modifier|*
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
name|bool
name|DiagnoseClassNameShadow
parameter_list|(
name|DeclContext
modifier|*
name|DC
parameter_list|,
name|DeclarationNameInfo
name|Info
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
name|void
name|CheckCastAlign
parameter_list|(
name|Expr
modifier|*
name|Op
parameter_list|,
name|QualType
name|T
parameter_list|,
name|SourceRange
name|TRange
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
name|ActOnTypedefNameDecl
parameter_list|(
name|Scope
modifier|*
name|S
parameter_list|,
name|DeclContext
modifier|*
name|DC
parameter_list|,
name|TypedefNameDecl
modifier|*
name|D
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
name|void
name|CheckCompleteVariableDeclaration
parameter_list|(
name|VarDecl
modifier|*
name|var
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
name|bool
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
name|DiagnoseHiddenVirtualMethods
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
name|Decl
modifier|*
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

begin_function_decl
name|ParmVarDecl
modifier|*
name|CheckParameter
parameter_list|(
name|DeclContext
modifier|*
name|DC
parameter_list|,
name|SourceLocation
name|StartLoc
parameter_list|,
name|SourceLocation
name|NameLoc
parameter_list|,
name|IdentifierInfo
modifier|*
name|Name
parameter_list|,
name|QualType
name|T
parameter_list|,
name|TypeSourceInfo
modifier|*
name|TSInfo
parameter_list|,
name|StorageClass
name|SC
parameter_list|,
name|StorageClass
name|SCAsWritten
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ActOnParamDefaultArgument
parameter_list|(
name|Decl
modifier|*
name|param
parameter_list|,
name|SourceLocation
name|EqualLoc
parameter_list|,
name|Expr
modifier|*
name|defarg
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ActOnParamUnparsedDefaultArgument
parameter_list|(
name|Decl
modifier|*
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
name|void
name|ActOnParamDefaultArgumentError
parameter_list|(
name|Decl
modifier|*
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
name|Expr
modifier|*
name|DefaultArg
parameter_list|,
name|SourceLocation
name|EqualLoc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|AddInitializerToDecl
parameter_list|(
name|Decl
modifier|*
name|dcl
parameter_list|,
name|Expr
modifier|*
name|init
parameter_list|,
name|bool
name|DirectInit
parameter_list|,
name|bool
name|TypeMayContainAuto
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ActOnUninitializedDecl
parameter_list|(
name|Decl
modifier|*
name|dcl
parameter_list|,
name|bool
name|TypeMayContainAuto
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ActOnInitializerError
parameter_list|(
name|Decl
modifier|*
name|Dcl
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ActOnCXXForRangeDecl
parameter_list|(
name|Decl
modifier|*
name|D
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|SetDeclDeleted
parameter_list|(
name|Decl
modifier|*
name|dcl
parameter_list|,
name|SourceLocation
name|DelLoc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|FinalizeDeclaration
parameter_list|(
name|Decl
modifier|*
name|D
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
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
name|Decl
modifier|*
modifier|*
name|Group
parameter_list|,
name|unsigned
name|NumDecls
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|DeclGroupPtrTy
name|BuildDeclaratorGroup
parameter_list|(
name|Decl
modifier|*
modifier|*
name|Group
parameter_list|,
name|unsigned
name|NumDecls
parameter_list|,
name|bool
name|TypeMayContainAuto
init|=
name|true
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
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
name|void
name|CheckForFunctionRedefinition
parameter_list|(
name|FunctionDecl
modifier|*
name|FD
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|Decl
modifier|*
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
name|Decl
modifier|*
name|ActOnStartOfFunctionDef
parameter_list|(
name|Scope
modifier|*
name|S
parameter_list|,
name|Decl
modifier|*
name|D
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ActOnStartOfObjCMethodDef
parameter_list|(
name|Scope
modifier|*
name|S
parameter_list|,
name|Decl
modifier|*
name|D
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|Decl
modifier|*
name|ActOnFinishFunctionBody
parameter_list|(
name|Decl
modifier|*
name|Decl
parameter_list|,
name|Stmt
modifier|*
name|Body
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|Decl
modifier|*
name|ActOnFinishFunctionBody
parameter_list|(
name|Decl
modifier|*
name|Decl
parameter_list|,
name|Stmt
modifier|*
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

begin_function_decl
name|void
name|DiagnoseUnusedParameters
parameter_list|(
name|ParmVarDecl
modifier|*
specifier|const
modifier|*
name|Begin
parameter_list|,
name|ParmVarDecl
modifier|*
specifier|const
modifier|*
name|End
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// \brief Diagnose whether the size of parameters or return value of a
end_comment

begin_comment
comment|/// function or obj-c method definition is pass-by-value and larger than a
end_comment

begin_comment
comment|/// specified threshold.
end_comment

begin_function_decl
name|void
name|DiagnoseSizeOfParametersAndReturnValue
parameter_list|(
name|ParmVarDecl
modifier|*
specifier|const
modifier|*
name|Begin
parameter_list|,
name|ParmVarDecl
modifier|*
specifier|const
modifier|*
name|End
parameter_list|,
name|QualType
name|ReturnTy
parameter_list|,
name|NamedDecl
modifier|*
name|D
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|DiagnoseInvalidJumps
parameter_list|(
name|Stmt
modifier|*
name|Body
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|Decl
modifier|*
name|ActOnFileScopeAsmDecl
parameter_list|(
name|Expr
modifier|*
name|expr
parameter_list|,
name|SourceLocation
name|AsmLoc
parameter_list|,
name|SourceLocation
name|RParenLoc
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// Scope actions.
end_comment

begin_function_decl
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
name|void
name|ActOnTranslationUnitScope
parameter_list|(
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
name|Decl
modifier|*
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
name|StmtResult
name|ActOnVlaStmt
parameter_list|(
specifier|const
name|DeclSpec
modifier|&
name|DS
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|Decl
modifier|*
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

begin_function_decl
name|Decl
modifier|*
name|BuildMicrosoftCAnonymousStruct
parameter_list|(
name|Scope
modifier|*
name|S
parameter_list|,
name|DeclSpec
modifier|&
name|DS
parameter_list|,
name|RecordDecl
modifier|*
name|Record
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|isAcceptableTagRedeclaration
parameter_list|(
specifier|const
name|TagDecl
modifier|*
name|Previous
parameter_list|,
name|TagTypeKind
name|NewTag
parameter_list|,
name|SourceLocation
name|NewTagLoc
parameter_list|,
specifier|const
name|IdentifierInfo
modifier|&
name|Name
parameter_list|)
function_decl|;
end_function_decl

begin_enum
enum|enum
name|TagUseKind
block|{
name|TUK_Reference
block|,
comment|// Reference to a tag:  'struct foo *X;'
name|TUK_Declaration
block|,
comment|// Fwd decl of a tag:   'struct foo;'
name|TUK_Definition
block|,
comment|// Definition of a tag: 'struct foo { int X; } Y;'
name|TUK_Friend
comment|// Friend declaration:  'friend struct foo;'
block|}
enum|;
end_enum

begin_function_decl
name|Decl
modifier|*
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
parameter_list|,
name|bool
name|ScopedEnum
parameter_list|,
name|bool
name|ScopedEnumUsesClassTag
parameter_list|,
name|TypeResult
name|UnderlyingType
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|Decl
modifier|*
name|ActOnTemplatedFriendTag
parameter_list|(
name|Scope
modifier|*
name|S
parameter_list|,
name|SourceLocation
name|FriendLoc
parameter_list|,
name|unsigned
name|TagSpec
parameter_list|,
name|SourceLocation
name|TagLoc
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
name|MultiTemplateParamsArg
name|TempParamLists
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
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
name|void
name|ActOnDefs
argument_list|(
name|Scope
operator|*
name|S
argument_list|,
name|Decl
operator|*
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
name|Decl
operator|*
operator|>
operator|&
name|Decls
argument_list|)
decl_stmt|;
end_decl_stmt

begin_function_decl
name|Decl
modifier|*
name|ActOnField
parameter_list|(
name|Scope
modifier|*
name|S
parameter_list|,
name|Decl
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
name|bool
name|CheckNontrivialField
parameter_list|(
name|FieldDecl
modifier|*
name|FD
parameter_list|)
function_decl|;
end_function_decl

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
name|void
name|ActOnLastBitfield
argument_list|(
name|SourceLocation
name|DeclStart
argument_list|,
name|Decl
operator|*
name|IntfDecl
argument_list|,
name|llvm
operator|::
name|SmallVectorImpl
operator|<
name|Decl
operator|*
operator|>
operator|&
name|AllIvarDecls
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|Decl
modifier|*
name|ActOnIvar
argument_list|(
name|Scope
operator|*
name|S
argument_list|,
name|SourceLocation
name|DeclStart
argument_list|,
name|Decl
operator|*
name|IntfDecl
argument_list|,
name|Declarator
operator|&
name|D
argument_list|,
name|Expr
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
name|Decl
modifier|*
name|TagDecl
parameter_list|,
name|Decl
modifier|*
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
name|void
name|ActOnTagStartDefinition
parameter_list|(
name|Scope
modifier|*
name|S
parameter_list|,
name|Decl
modifier|*
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
name|void
name|ActOnStartCXXMemberDeclarations
parameter_list|(
name|Scope
modifier|*
name|S
parameter_list|,
name|Decl
modifier|*
name|TagDecl
parameter_list|,
name|SourceLocation
name|FinalLoc
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
name|void
name|ActOnTagFinishDefinition
parameter_list|(
name|Scope
modifier|*
name|S
parameter_list|,
name|Decl
modifier|*
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
name|void
name|ActOnTagDefinitionError
parameter_list|(
name|Scope
modifier|*
name|S
parameter_list|,
name|Decl
modifier|*
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
name|Expr
modifier|*
name|val
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|Decl
modifier|*
name|ActOnEnumConstant
parameter_list|(
name|Scope
modifier|*
name|S
parameter_list|,
name|Decl
modifier|*
name|EnumDecl
parameter_list|,
name|Decl
modifier|*
name|LastEnumConstant
parameter_list|,
name|SourceLocation
name|IdLoc
parameter_list|,
name|IdentifierInfo
modifier|*
name|Id
parameter_list|,
name|AttributeList
modifier|*
name|Attrs
parameter_list|,
name|SourceLocation
name|EqualLoc
parameter_list|,
name|Expr
modifier|*
name|Val
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
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
name|Decl
modifier|*
name|EnumDecl
parameter_list|,
name|Decl
modifier|*
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

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param ExplicitInstantiationOrSpecialization When true, we are checking
end_comment

begin_comment
comment|/// whether the declaration is in scope for the purposes of explicit template
end_comment

begin_comment
comment|/// instantiation or specialization. The default is false.
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
parameter_list|,
name|bool
name|ExplicitInstantiationOrSpecialization
init|=
name|false
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// Finds the scope corresponding to the given decl context, if it
end_comment

begin_comment
comment|/// happens to be an enclosing scope.  Otherwise return NULL.
end_comment

begin_function_decl
specifier|static
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
function_decl|;
end_function_decl

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
name|MergeTypedefNameDecl
parameter_list|(
name|TypedefNameDecl
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
name|mergeObjCMethodDecls
parameter_list|(
name|ObjCMethodDecl
modifier|*
name|New
parameter_list|,
specifier|const
name|ObjCMethodDecl
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
name|void
name|MergeVarDeclTypes
parameter_list|(
name|VarDecl
modifier|*
name|New
parameter_list|,
name|VarDecl
modifier|*
name|Old
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|MergeVarDeclExceptionSpecs
parameter_list|(
name|VarDecl
modifier|*
name|New
parameter_list|,
name|VarDecl
modifier|*
name|Old
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
parameter_list|,
name|bool
name|CStyle
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
name|IsBlockPointerConversion
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
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|FunctionArgTypesAreEqual
parameter_list|(
specifier|const
name|FunctionProtoType
modifier|*
name|OldType
parameter_list|,
specifier|const
name|FunctionProtoType
modifier|*
name|NewType
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|CheckPointerConversion
parameter_list|(
name|Expr
modifier|*
name|From
parameter_list|,
name|QualType
name|ToType
parameter_list|,
name|CastKind
modifier|&
name|Kind
parameter_list|,
name|CXXCastPath
modifier|&
name|BasePath
parameter_list|,
name|bool
name|IgnoreBaseAccess
parameter_list|)
function_decl|;
end_function_decl

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

begin_function_decl
name|bool
name|CheckMemberPointerConversion
parameter_list|(
name|Expr
modifier|*
name|From
parameter_list|,
name|QualType
name|ToType
parameter_list|,
name|CastKind
modifier|&
name|Kind
parameter_list|,
name|CXXCastPath
modifier|&
name|BasePath
parameter_list|,
name|bool
name|IgnoreBaseAccess
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|IsQualificationConversion
parameter_list|(
name|QualType
name|FromType
parameter_list|,
name|QualType
name|ToType
parameter_list|,
name|bool
name|CStyle
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

begin_function_decl
name|ExprResult
name|PerformMoveOrCopyInitialization
parameter_list|(
specifier|const
name|InitializedEntity
modifier|&
name|Entity
parameter_list|,
specifier|const
name|VarDecl
modifier|*
name|NRVOCandidate
parameter_list|,
name|QualType
name|ResultType
parameter_list|,
name|Expr
modifier|*
name|Value
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ExprResult
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
name|ExprResult
name|Init
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ExprResult
name|PerformObjectArgumentInitialization
parameter_list|(
name|Expr
modifier|*
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
name|ExprResult
name|PerformContextuallyConvertToBool
parameter_list|(
name|Expr
modifier|*
name|From
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ExprResult
name|PerformContextuallyConvertToObjCId
parameter_list|(
name|Expr
modifier|*
name|From
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ExprResult
name|ConvertToIntegralOrEnumerationType
parameter_list|(
name|SourceLocation
name|Loc
parameter_list|,
name|Expr
modifier|*
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
name|ExprResult
name|PerformObjectMemberConversion
parameter_list|(
name|Expr
modifier|*
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

begin_decl_stmt
name|void
name|AddMethodCandidate
argument_list|(
name|DeclAccessPair
name|FoundDecl
argument_list|,
name|QualType
name|ObjectType
argument_list|,
name|Expr
operator|::
name|Classification
name|ObjectClassification
argument_list|,
name|Expr
operator|*
operator|*
name|Args
argument_list|,
name|unsigned
name|NumArgs
argument_list|,
name|OverloadCandidateSet
operator|&
name|CandidateSet
argument_list|,
name|bool
name|SuppressUserConversion
operator|=
name|false
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|AddMethodCandidate
argument_list|(
name|CXXMethodDecl
operator|*
name|Method
argument_list|,
name|DeclAccessPair
name|FoundDecl
argument_list|,
name|CXXRecordDecl
operator|*
name|ActingContext
argument_list|,
name|QualType
name|ObjectType
argument_list|,
name|Expr
operator|::
name|Classification
name|ObjectClassification
argument_list|,
name|Expr
operator|*
operator|*
name|Args
argument_list|,
name|unsigned
name|NumArgs
argument_list|,
name|OverloadCandidateSet
operator|&
name|CandidateSet
argument_list|,
name|bool
name|SuppressUserConversions
operator|=
name|false
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|AddMethodTemplateCandidate
argument_list|(
name|FunctionTemplateDecl
operator|*
name|MethodTmpl
argument_list|,
name|DeclAccessPair
name|FoundDecl
argument_list|,
name|CXXRecordDecl
operator|*
name|ActingContext
argument_list|,
name|TemplateArgumentListInfo
operator|*
name|ExplicitTemplateArgs
argument_list|,
name|QualType
name|ObjectType
argument_list|,
name|Expr
operator|::
name|Classification
name|ObjectClassification
argument_list|,
name|Expr
operator|*
operator|*
name|Args
argument_list|,
name|unsigned
name|NumArgs
argument_list|,
name|OverloadCandidateSet
operator|&
name|CandidateSet
argument_list|,
name|bool
name|SuppressUserConversions
operator|=
name|false
argument_list|)
decl_stmt|;
end_decl_stmt

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
name|Expr
modifier|*
name|Object
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
parameter_list|,
name|bool
name|StdNamespaceIsAssociated
init|=
name|false
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|// Emit as a 'note' the specific overload candidate
end_comment

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

begin_comment
comment|// Emit as a series of 'note's all template and non-templates
end_comment

begin_comment
comment|// identified by the expression Expr
end_comment

begin_function_decl
name|void
name|NoteAllOverloadCandidates
parameter_list|(
name|Expr
modifier|*
name|E
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|// [PossiblyAFunctionType]  -->   [Return]
end_comment

begin_comment
comment|// NonFunctionType --> NonFunctionType
end_comment

begin_comment
comment|// R (A) --> R(A)
end_comment

begin_comment
comment|// R (*)(A) --> R (A)
end_comment

begin_comment
comment|// R (&)(A) --> R (A)
end_comment

begin_comment
comment|// R (S::*)(A) --> R (A)
end_comment

begin_function_decl
name|QualType
name|ExtractUnqualifiedFunctionType
parameter_list|(
name|QualType
name|PossiblyAFunctionType
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
name|AddressOfExpr
parameter_list|,
name|QualType
name|TargetType
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
name|OverloadExpr
modifier|*
name|ovl
parameter_list|,
name|bool
name|Complain
init|=
name|false
parameter_list|,
name|DeclAccessPair
modifier|*
name|Found
init|=
literal|0
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ExprResult
name|ResolveAndFixSingleFunctionTemplateSpecialization
parameter_list|(
name|Expr
modifier|*
name|SrcExpr
parameter_list|,
name|bool
name|DoFunctionPointerConverion
init|=
name|false
parameter_list|,
name|bool
name|Complain
init|=
name|false
parameter_list|,
specifier|const
name|SourceRange
modifier|&
name|OpRangeForComplaining
init|=
name|SourceRange
argument_list|()
parameter_list|,
name|QualType
name|DestTypeForComplaining
init|=
name|QualType
argument_list|()
parameter_list|,
name|unsigned
name|DiagIDForComplaining
init|=
literal|0
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
name|ExprResult
name|FixOverloadedFunctionReference
parameter_list|(
name|ExprResult
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
name|ExprResult
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
name|RParenLoc
parameter_list|,
name|Expr
modifier|*
name|ExecConfig
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ExprResult
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
name|Expr
modifier|*
name|input
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ExprResult
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
name|ExprResult
name|CreateOverloadedArraySubscriptExpr
parameter_list|(
name|SourceLocation
name|LLoc
parameter_list|,
name|SourceLocation
name|RLoc
parameter_list|,
name|Expr
modifier|*
name|Base
parameter_list|,
name|Expr
modifier|*
name|Idx
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ExprResult
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
name|RParenLoc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ExprResult
name|BuildOverloadedArrowExpr
parameter_list|(
name|Scope
modifier|*
name|S
parameter_list|,
name|Expr
modifier|*
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
name|ParmVarDecl
modifier|*
modifier|*
name|Param
parameter_list|,
name|ParmVarDecl
modifier|*
modifier|*
name|ParamEnd
parameter_list|,
name|bool
name|CheckParameterNames
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
comment|/// Label name lookup.
name|LookupLabel
block|,
comment|/// Member name lookup, which finds the names of
comment|/// class/struct/union members.
name|LookupMemberName
block|,
comment|/// Look up of an operator name (e.g., operator+) for use with
comment|/// operator overloading. This lookup is similar to ordinary name
comment|/// lookup, but will ignore any declarations that are class members.
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
block|,
comment|/// \brief Look up any declaration with any name.
name|LookupAnyName
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

begin_function_decl
name|LabelDecl
modifier|*
name|LookupOrCreateLabel
parameter_list|(
name|IdentifierInfo
modifier|*
name|II
parameter_list|,
name|SourceLocation
name|IdentLoc
parameter_list|,
name|SourceLocation
name|GnuLabelLoc
init|=
name|SourceLocation
argument_list|()
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|DeclContextLookupResult
name|LookupConstructors
parameter_list|(
name|CXXRecordDecl
modifier|*
name|Class
parameter_list|)
function_decl|;
end_function_decl

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
parameter_list|,
name|bool
name|StdNamespaceIsAssociated
init|=
name|false
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
parameter_list|,
name|bool
name|IncludeGlobalScope
init|=
name|true
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
parameter_list|,
name|bool
name|IncludeGlobalScope
init|=
name|true
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
comment|/// \brief An Objective-C ivar lookup context (e.g., self->ivar).
name|CTC_ObjCIvarLookup
block|,
comment|/// \brief An Objective-C property lookup context (e.g., self.prop).
name|CTC_ObjCPropertyLookup
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
parameter_list|,
name|bool
name|NonInheritable
init|=
name|true
parameter_list|,
name|bool
name|Inheritable
init|=
name|true
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
name|AL
parameter_list|,
name|bool
name|NonInheritable
init|=
name|true
parameter_list|,
name|bool
name|Inheritable
init|=
name|true
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|CheckRegparmAttr
parameter_list|(
specifier|const
name|AttributeList
modifier|&
name|attr
parameter_list|,
name|unsigned
modifier|&
name|value
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|CheckCallingConvAttr
parameter_list|(
specifier|const
name|AttributeList
modifier|&
name|attr
parameter_list|,
name|CallingConv
modifier|&
name|CC
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|CheckNoReturnAttr
parameter_list|(
specifier|const
name|AttributeList
modifier|&
name|attr
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
name|MethodDecl
parameter_list|,
name|bool
name|IsProtocolMethodDecl
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

begin_typedef
typedef|typedef
name|llvm
operator|::
name|DenseSet
operator|<
name|Selector
operator|,
name|llvm
operator|::
name|DenseMapInfo
operator|<
name|Selector
operator|>
expr|>
name|SelectorSet
expr_stmt|;
end_typedef

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

begin_function_decl
name|void
name|CheckProtocolMethodDefs
parameter_list|(
name|SourceLocation
name|ImpLoc
parameter_list|,
name|ObjCProtocolDecl
modifier|*
name|PDecl
parameter_list|,
name|bool
modifier|&
name|IncompleteImpl
parameter_list|,
specifier|const
name|SelectorSet
modifier|&
name|InsMap
parameter_list|,
specifier|const
name|SelectorSet
modifier|&
name|ClsMap
parameter_list|,
name|ObjCContainerDecl
modifier|*
name|CDecl
parameter_list|)
function_decl|;
end_function_decl

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
comment|/// \brief Determine whether we can synthesize a provisional ivar for the
end_comment

begin_comment
comment|/// given name.
end_comment

begin_function_decl
name|ObjCPropertyDecl
modifier|*
name|canSynthesizeProvisionalIvar
parameter_list|(
name|IdentifierInfo
modifier|*
name|II
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// \brief Determine whether we can synthesize a provisional ivar for the
end_comment

begin_comment
comment|/// given property.
end_comment

begin_function_decl
name|bool
name|canSynthesizeProvisionalIvar
parameter_list|(
name|ObjCPropertyDecl
modifier|*
name|Property
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

begin_function_decl
name|void
name|DiagnoseUnimplementedProperties
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
name|CDecl
parameter_list|,
specifier|const
name|SelectorSet
modifier|&
name|InsMap
parameter_list|)
function_decl|;
end_function_decl

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
name|Decl
modifier|*
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
parameter_list|,
name|bool
name|matchBasedOnStrictEqulity
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

begin_function_decl
name|void
name|MatchAllMethodDeclarations
parameter_list|(
specifier|const
name|SelectorSet
modifier|&
name|InsMap
parameter_list|,
specifier|const
name|SelectorSet
modifier|&
name|ClsMap
parameter_list|,
name|SelectorSet
modifier|&
name|InsMapSeen
parameter_list|,
name|SelectorSet
modifier|&
name|ClsMapSeen
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
modifier|&
name|IncompleteImpl
parameter_list|,
name|bool
name|ImmediateClass
parameter_list|)
function_decl|;
end_function_decl

begin_label
name|private
label|:
end_label

begin_comment
comment|/// AddMethodToGlobalPool - Add an instance or factory method to the global
end_comment

begin_comment
comment|/// pool. See descriptoin of AddInstanceMethodToGlobalPool.
end_comment

begin_function_decl
name|void
name|AddMethodToGlobalPool
parameter_list|(
name|ObjCMethodDecl
modifier|*
name|Method
parameter_list|,
name|bool
name|impl
parameter_list|,
name|bool
name|instance
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// LookupMethodInGlobalPool - Returns the instance or factory method and
end_comment

begin_comment
comment|/// optionally warns if there are multiple signatures.
end_comment

begin_function_decl
name|ObjCMethodDecl
modifier|*
name|LookupMethodInGlobalPool
parameter_list|(
name|Selector
name|Sel
parameter_list|,
name|SourceRange
name|R
parameter_list|,
name|bool
name|receiverIdOrClass
parameter_list|,
name|bool
name|warn
parameter_list|,
name|bool
name|instance
parameter_list|)
function_decl|;
end_function_decl

begin_label
name|public
label|:
end_label

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

begin_function
name|void
name|AddInstanceMethodToGlobalPool
parameter_list|(
name|ObjCMethodDecl
modifier|*
name|Method
parameter_list|,
name|bool
name|impl
init|=
name|false
parameter_list|)
block|{
name|AddMethodToGlobalPool
argument_list|(
name|Method
argument_list|,
name|impl
argument_list|,
comment|/*instance*/
name|true
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/// AddFactoryMethodToGlobalPool - Same as above, but for factory methods.
end_comment

begin_function
name|void
name|AddFactoryMethodToGlobalPool
parameter_list|(
name|ObjCMethodDecl
modifier|*
name|Method
parameter_list|,
name|bool
name|impl
init|=
name|false
parameter_list|)
block|{
name|AddMethodToGlobalPool
argument_list|(
name|Method
argument_list|,
name|impl
argument_list|,
comment|/*instance*/
name|false
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/// LookupInstanceMethodInGlobalPool - Returns the method and warns if
end_comment

begin_comment
comment|/// there are multiple signatures.
end_comment

begin_function
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
name|receiverIdOrClass
init|=
name|false
parameter_list|,
name|bool
name|warn
init|=
name|true
parameter_list|)
block|{
return|return
name|LookupMethodInGlobalPool
argument_list|(
name|Sel
argument_list|,
name|R
argument_list|,
name|receiverIdOrClass
argument_list|,
name|warn
argument_list|,
comment|/*instance*/
name|true
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/// LookupFactoryMethodInGlobalPool - Returns the method and warns if
end_comment

begin_comment
comment|/// there are multiple signatures.
end_comment

begin_function
name|ObjCMethodDecl
modifier|*
name|LookupFactoryMethodInGlobalPool
parameter_list|(
name|Selector
name|Sel
parameter_list|,
name|SourceRange
name|R
parameter_list|,
name|bool
name|receiverIdOrClass
init|=
name|false
parameter_list|,
name|bool
name|warn
init|=
name|true
parameter_list|)
block|{
return|return
name|LookupMethodInGlobalPool
argument_list|(
name|Sel
argument_list|,
name|R
argument_list|,
name|receiverIdOrClass
argument_list|,
name|warn
argument_list|,
comment|/*instance*/
name|false
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/// LookupImplementedMethodInGlobalPool - Returns the method which has an
end_comment

begin_comment
comment|/// implementation.
end_comment

begin_function_decl
name|ObjCMethodDecl
modifier|*
name|LookupImplementedMethodInGlobalPool
parameter_list|(
name|Selector
name|Sel
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

begin_decl_stmt
name|class
name|FullExprArg
block|{
name|public
label|:
name|FullExprArg
argument_list|(
name|Sema
operator|&
name|actions
argument_list|)
operator|:
name|E
argument_list|(
literal|0
argument_list|)
block|{ }
comment|// FIXME: The const_cast here is ugly. RValue references would make this
comment|// much nicer (or we could duplicate a bunch of the move semantics
comment|// emulation code from Ownership.h).
name|FullExprArg
argument_list|(
specifier|const
name|FullExprArg
operator|&
name|Other
argument_list|)
operator|:
name|E
argument_list|(
argument|Other.E
argument_list|)
block|{}
name|ExprResult
name|release
argument_list|()
block|{
return|return
name|move
argument_list|(
name|E
argument_list|)
return|;
block|}
name|Expr
operator|*
name|get
argument_list|()
specifier|const
block|{
return|return
name|E
return|;
block|}
name|Expr
operator|*
name|operator
operator|->
expr|(
block|)
block|{
return|return
name|E
return|;
block|}
end_decl_stmt

begin_label
name|private
label|:
end_label

begin_comment
comment|// FIXME: No need to make the entire Sema class a friend when it's just
end_comment

begin_comment
comment|// Sema::MakeFullExpr that needs access to the constructor below.
end_comment

begin_decl_stmt
name|friend
name|class
name|Sema
decl_stmt|;
end_decl_stmt

begin_macro
name|explicit
end_macro

begin_expr_stmt
name|FullExprArg
argument_list|(
name|Expr
operator|*
name|expr
argument_list|)
operator|:
name|E
argument_list|(
argument|expr
argument_list|)
block|{}
name|Expr
operator|*
name|E
expr_stmt|;
end_expr_stmt

begin_function
unit|};
name|FullExprArg
name|MakeFullExpr
parameter_list|(
name|Expr
modifier|*
name|Arg
parameter_list|)
block|{
return|return
name|FullExprArg
argument_list|(
name|ActOnFinishFullExpr
argument_list|(
name|Arg
argument_list|)
operator|.
name|release
argument_list|()
argument_list|)
return|;
block|}
end_function

begin_function_decl
name|StmtResult
name|ActOnExprStmt
parameter_list|(
name|FullExprArg
name|Expr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|StmtResult
name|ActOnNullStmt
parameter_list|(
name|SourceLocation
name|SemiLoc
parameter_list|,
name|SourceLocation
name|LeadingEmptyMacroLoc
init|=
name|SourceLocation
argument_list|()
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|StmtResult
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
name|StmtResult
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
name|void
name|ActOnForEachDeclStmt
parameter_list|(
name|DeclGroupPtrTy
name|Decl
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|StmtResult
name|ActOnForEachLValueExpr
parameter_list|(
name|Expr
modifier|*
name|E
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|StmtResult
name|ActOnCaseStmt
parameter_list|(
name|SourceLocation
name|CaseLoc
parameter_list|,
name|Expr
modifier|*
name|LHSVal
parameter_list|,
name|SourceLocation
name|DotDotDotLoc
parameter_list|,
name|Expr
modifier|*
name|RHSVal
parameter_list|,
name|SourceLocation
name|ColonLoc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ActOnCaseStmtBody
parameter_list|(
name|Stmt
modifier|*
name|CaseStmt
parameter_list|,
name|Stmt
modifier|*
name|SubStmt
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|StmtResult
name|ActOnDefaultStmt
parameter_list|(
name|SourceLocation
name|DefaultLoc
parameter_list|,
name|SourceLocation
name|ColonLoc
parameter_list|,
name|Stmt
modifier|*
name|SubStmt
parameter_list|,
name|Scope
modifier|*
name|CurScope
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|StmtResult
name|ActOnLabelStmt
parameter_list|(
name|SourceLocation
name|IdentLoc
parameter_list|,
name|LabelDecl
modifier|*
name|TheDecl
parameter_list|,
name|SourceLocation
name|ColonLoc
parameter_list|,
name|Stmt
modifier|*
name|SubStmt
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|StmtResult
name|ActOnIfStmt
parameter_list|(
name|SourceLocation
name|IfLoc
parameter_list|,
name|FullExprArg
name|CondVal
parameter_list|,
name|Decl
modifier|*
name|CondVar
parameter_list|,
name|Stmt
modifier|*
name|ThenVal
parameter_list|,
name|SourceLocation
name|ElseLoc
parameter_list|,
name|Stmt
modifier|*
name|ElseVal
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|StmtResult
name|ActOnStartOfSwitchStmt
parameter_list|(
name|SourceLocation
name|SwitchLoc
parameter_list|,
name|Expr
modifier|*
name|Cond
parameter_list|,
name|Decl
modifier|*
name|CondVar
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|StmtResult
name|ActOnFinishSwitchStmt
parameter_list|(
name|SourceLocation
name|SwitchLoc
parameter_list|,
name|Stmt
modifier|*
name|Switch
parameter_list|,
name|Stmt
modifier|*
name|Body
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|StmtResult
name|ActOnWhileStmt
parameter_list|(
name|SourceLocation
name|WhileLoc
parameter_list|,
name|FullExprArg
name|Cond
parameter_list|,
name|Decl
modifier|*
name|CondVar
parameter_list|,
name|Stmt
modifier|*
name|Body
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|StmtResult
name|ActOnDoStmt
parameter_list|(
name|SourceLocation
name|DoLoc
parameter_list|,
name|Stmt
modifier|*
name|Body
parameter_list|,
name|SourceLocation
name|WhileLoc
parameter_list|,
name|SourceLocation
name|CondLParen
parameter_list|,
name|Expr
modifier|*
name|Cond
parameter_list|,
name|SourceLocation
name|CondRParen
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|StmtResult
name|ActOnForStmt
parameter_list|(
name|SourceLocation
name|ForLoc
parameter_list|,
name|SourceLocation
name|LParenLoc
parameter_list|,
name|Stmt
modifier|*
name|First
parameter_list|,
name|FullExprArg
name|Second
parameter_list|,
name|Decl
modifier|*
name|SecondVar
parameter_list|,
name|FullExprArg
name|Third
parameter_list|,
name|SourceLocation
name|RParenLoc
parameter_list|,
name|Stmt
modifier|*
name|Body
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|StmtResult
name|ActOnObjCForCollectionStmt
parameter_list|(
name|SourceLocation
name|ForColLoc
parameter_list|,
name|SourceLocation
name|LParenLoc
parameter_list|,
name|Stmt
modifier|*
name|First
parameter_list|,
name|Expr
modifier|*
name|Second
parameter_list|,
name|SourceLocation
name|RParenLoc
parameter_list|,
name|Stmt
modifier|*
name|Body
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|StmtResult
name|ActOnCXXForRangeStmt
parameter_list|(
name|SourceLocation
name|ForLoc
parameter_list|,
name|SourceLocation
name|LParenLoc
parameter_list|,
name|Stmt
modifier|*
name|LoopVar
parameter_list|,
name|SourceLocation
name|ColonLoc
parameter_list|,
name|Expr
modifier|*
name|Collection
parameter_list|,
name|SourceLocation
name|RParenLoc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|StmtResult
name|BuildCXXForRangeStmt
parameter_list|(
name|SourceLocation
name|ForLoc
parameter_list|,
name|SourceLocation
name|ColonLoc
parameter_list|,
name|Stmt
modifier|*
name|RangeDecl
parameter_list|,
name|Stmt
modifier|*
name|BeginEndDecl
parameter_list|,
name|Expr
modifier|*
name|Cond
parameter_list|,
name|Expr
modifier|*
name|Inc
parameter_list|,
name|Stmt
modifier|*
name|LoopVarDecl
parameter_list|,
name|SourceLocation
name|RParenLoc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|StmtResult
name|FinishCXXForRangeStmt
parameter_list|(
name|Stmt
modifier|*
name|ForRange
parameter_list|,
name|Stmt
modifier|*
name|Body
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|StmtResult
name|ActOnGotoStmt
parameter_list|(
name|SourceLocation
name|GotoLoc
parameter_list|,
name|SourceLocation
name|LabelLoc
parameter_list|,
name|LabelDecl
modifier|*
name|TheDecl
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|StmtResult
name|ActOnIndirectGotoStmt
parameter_list|(
name|SourceLocation
name|GotoLoc
parameter_list|,
name|SourceLocation
name|StarLoc
parameter_list|,
name|Expr
modifier|*
name|DestExp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|StmtResult
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
name|StmtResult
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
specifier|const
name|VarDecl
modifier|*
name|getCopyElisionCandidate
parameter_list|(
name|QualType
name|ReturnType
parameter_list|,
name|Expr
modifier|*
name|E
parameter_list|,
name|bool
name|AllowFunctionParameters
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|StmtResult
name|ActOnReturnStmt
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
name|StmtResult
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
name|StmtResult
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
name|Expr
modifier|*
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
name|bool
name|Invalid
init|=
name|false
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|Decl
modifier|*
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
name|StmtResult
name|ActOnObjCAtCatchStmt
parameter_list|(
name|SourceLocation
name|AtLoc
parameter_list|,
name|SourceLocation
name|RParen
parameter_list|,
name|Decl
modifier|*
name|Parm
parameter_list|,
name|Stmt
modifier|*
name|Body
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|StmtResult
name|ActOnObjCAtFinallyStmt
parameter_list|(
name|SourceLocation
name|AtLoc
parameter_list|,
name|Stmt
modifier|*
name|Body
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|StmtResult
name|ActOnObjCAtTryStmt
parameter_list|(
name|SourceLocation
name|AtLoc
parameter_list|,
name|Stmt
modifier|*
name|Try
parameter_list|,
name|MultiStmtArg
name|Catch
parameter_list|,
name|Stmt
modifier|*
name|Finally
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|StmtResult
name|BuildObjCAtThrowStmt
parameter_list|(
name|SourceLocation
name|AtLoc
parameter_list|,
name|Expr
modifier|*
name|Throw
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|StmtResult
name|ActOnObjCAtThrowStmt
parameter_list|(
name|SourceLocation
name|AtLoc
parameter_list|,
name|Expr
modifier|*
name|Throw
parameter_list|,
name|Scope
modifier|*
name|CurScope
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|StmtResult
name|ActOnObjCAtSynchronizedStmt
parameter_list|(
name|SourceLocation
name|AtLoc
parameter_list|,
name|Expr
modifier|*
name|SynchExpr
parameter_list|,
name|Stmt
modifier|*
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
name|TypeSourceInfo
modifier|*
name|TInfo
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
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|Decl
modifier|*
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
name|StmtResult
name|ActOnCXXCatchBlock
parameter_list|(
name|SourceLocation
name|CatchLoc
parameter_list|,
name|Decl
modifier|*
name|ExDecl
parameter_list|,
name|Stmt
modifier|*
name|HandlerBlock
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|StmtResult
name|ActOnCXXTryBlock
parameter_list|(
name|SourceLocation
name|TryLoc
parameter_list|,
name|Stmt
modifier|*
name|TryBlock
parameter_list|,
name|MultiStmtArg
name|Handlers
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|StmtResult
name|ActOnSEHTryBlock
parameter_list|(
name|bool
name|IsCXXTry
parameter_list|,
comment|// try (true) or __try (false) ?
name|SourceLocation
name|TryLoc
parameter_list|,
name|Stmt
modifier|*
name|TryBlock
parameter_list|,
name|Stmt
modifier|*
name|Handler
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|StmtResult
name|ActOnSEHExceptBlock
parameter_list|(
name|SourceLocation
name|Loc
parameter_list|,
name|Expr
modifier|*
name|FilterExpr
parameter_list|,
name|Stmt
modifier|*
name|Block
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|StmtResult
name|ActOnSEHFinallyBlock
parameter_list|(
name|SourceLocation
name|Loc
parameter_list|,
name|Stmt
modifier|*
name|Block
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

begin_decl_stmt
name|bool
name|ShouldWarnIfUnusedFileScopedDecl
argument_list|(
specifier|const
name|DeclaratorDecl
operator|*
name|D
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// \brief If it's a file scoped decl that must warn if not used, keep track
end_comment

begin_comment
comment|/// of it.
end_comment

begin_function_decl
name|void
name|MarkUnusedFileScopedDecl
parameter_list|(
specifier|const
name|DeclaratorDecl
modifier|*
name|D
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

begin_function
name|ParsingDeclState
name|PushParsingDeclaration
parameter_list|()
block|{
return|return
name|DelayedDiagnostics
operator|.
name|pushParsingDecl
argument_list|()
return|;
block|}
end_function

begin_function
name|void
name|PopParsingDeclaration
parameter_list|(
name|ParsingDeclState
name|state
parameter_list|,
name|Decl
modifier|*
name|decl
parameter_list|)
block|{
name|DelayedDiagnostics
operator|::
name|popParsingDecl
argument_list|(
operator|*
name|this
argument_list|,
name|state
argument_list|,
name|decl
argument_list|)
expr_stmt|;
block|}
end_function

begin_typedef
typedef|typedef
name|ProcessingContextState
name|ParsingClassState
typedef|;
end_typedef

begin_function
name|ParsingClassState
name|PushParsingClass
parameter_list|()
block|{
return|return
name|DelayedDiagnostics
operator|.
name|pushContext
argument_list|()
return|;
block|}
end_function

begin_function
name|void
name|PopParsingClass
parameter_list|(
name|ParsingClassState
name|state
parameter_list|)
block|{
name|DelayedDiagnostics
operator|.
name|popContext
argument_list|(
name|state
argument_list|)
expr_stmt|;
block|}
end_function

begin_decl_stmt
name|void
name|EmitDeprecationWarning
argument_list|(
name|NamedDecl
operator|*
name|D
argument_list|,
name|llvm
operator|::
name|StringRef
name|Message
argument_list|,
name|SourceLocation
name|Loc
argument_list|,
specifier|const
name|ObjCInterfaceDecl
operator|*
name|UnknownObjCClass
operator|=
literal|0
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|HandleDelayedDeprecationCheck
argument_list|(
name|sema
operator|::
name|DelayedDiagnostic
operator|&
name|DD
argument_list|,
name|Decl
operator|*
name|Ctx
argument_list|)
decl_stmt|;
end_decl_stmt

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
parameter_list|,
specifier|const
name|ObjCInterfaceDecl
modifier|*
name|UnknownObjCClass
init|=
literal|0
parameter_list|)
function_decl|;
end_function_decl

begin_expr_stmt
name|std
operator|::
name|string
name|getDeletedOrUnavailableSuffix
argument_list|(
specifier|const
name|FunctionDecl
operator|*
name|FD
argument_list|)
expr_stmt|;
end_expr_stmt

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
name|void
name|PushExpressionEvaluationContext
parameter_list|(
name|ExpressionEvaluationContext
name|NewContext
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
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
name|void
name|MarkDeclarationsReferencedInExpr
parameter_list|(
name|Expr
modifier|*
name|E
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// \brief Conditionally issue a diagnostic based on the current
end_comment

begin_comment
comment|/// evaluation context.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param stmt - If stmt is non-null, delay reporting the diagnostic until
end_comment

begin_comment
comment|///  the function body is parsed, and then do a basic reachability analysis to
end_comment

begin_comment
comment|///  determine if the statement is reachable.  If it is unreachable, the
end_comment

begin_comment
comment|///  diagnostic will not be emitted.
end_comment

begin_function_decl
name|bool
name|DiagRuntimeBehavior
parameter_list|(
name|SourceLocation
name|Loc
parameter_list|,
specifier|const
name|Stmt
modifier|*
name|stmt
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
name|SourceRange
name|getExprRange
argument_list|(
name|Expr
operator|*
name|E
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_function_decl
name|ObjCIvarDecl
modifier|*
name|SynthesizeProvisionalIvar
parameter_list|(
name|LookupResult
modifier|&
name|Lookup
parameter_list|,
name|IdentifierInfo
modifier|*
name|II
parameter_list|,
name|SourceLocation
name|NameLoc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ExprResult
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
name|ExprResult
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
name|ExprResult
name|ActOnDependentIdExpression
parameter_list|(
specifier|const
name|CXXScopeSpec
modifier|&
name|SS
parameter_list|,
specifier|const
name|DeclarationNameInfo
modifier|&
name|NameInfo
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
name|ExprResult
name|BuildDeclRefExpr
parameter_list|(
name|ValueDecl
modifier|*
name|D
parameter_list|,
name|QualType
name|Ty
parameter_list|,
name|ExprValueKind
name|VK
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

begin_function_decl
name|ExprResult
name|BuildDeclRefExpr
parameter_list|(
name|ValueDecl
modifier|*
name|D
parameter_list|,
name|QualType
name|Ty
parameter_list|,
name|ExprValueKind
name|VK
parameter_list|,
specifier|const
name|DeclarationNameInfo
modifier|&
name|NameInfo
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

begin_function_decl
name|ExprResult
name|BuildAnonymousStructUnionMemberReference
parameter_list|(
specifier|const
name|CXXScopeSpec
modifier|&
name|SS
parameter_list|,
name|SourceLocation
name|nameLoc
parameter_list|,
name|IndirectFieldDecl
modifier|*
name|indirectField
parameter_list|,
name|Expr
modifier|*
name|baseObjectExpr
init|=
literal|0
parameter_list|,
name|SourceLocation
name|opLoc
init|=
name|SourceLocation
argument_list|()
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ExprResult
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
name|ExprResult
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
name|ExprResult
name|BuildQualifiedDeclarationNameExpr
parameter_list|(
name|CXXScopeSpec
modifier|&
name|SS
parameter_list|,
specifier|const
name|DeclarationNameInfo
modifier|&
name|NameInfo
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ExprResult
name|BuildDependentDeclRefExpr
parameter_list|(
specifier|const
name|CXXScopeSpec
modifier|&
name|SS
parameter_list|,
specifier|const
name|DeclarationNameInfo
modifier|&
name|NameInfo
parameter_list|,
specifier|const
name|TemplateArgumentListInfo
modifier|*
name|TemplateArgs
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ExprResult
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
name|ExprResult
name|BuildDeclarationNameExpr
parameter_list|(
specifier|const
name|CXXScopeSpec
modifier|&
name|SS
parameter_list|,
specifier|const
name|DeclarationNameInfo
modifier|&
name|NameInfo
parameter_list|,
name|NamedDecl
modifier|*
name|D
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
name|ExprResult
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
name|ExprResult
name|ActOnNumericConstant
parameter_list|(
specifier|const
name|Token
modifier|&
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ExprResult
name|ActOnCharacterConstant
parameter_list|(
specifier|const
name|Token
modifier|&
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ExprResult
name|ActOnParenExpr
parameter_list|(
name|SourceLocation
name|L
parameter_list|,
name|SourceLocation
name|R
parameter_list|,
name|Expr
modifier|*
name|Val
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ExprResult
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
name|ParsedType
name|TypeOfCast
init|=
name|ParsedType
argument_list|()
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
name|ExprResult
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

begin_function_decl
name|ExprResult
name|ActOnGenericSelectionExpr
parameter_list|(
name|SourceLocation
name|KeyLoc
parameter_list|,
name|SourceLocation
name|DefaultLoc
parameter_list|,
name|SourceLocation
name|RParenLoc
parameter_list|,
name|Expr
modifier|*
name|ControllingExpr
parameter_list|,
name|MultiTypeArg
name|Types
parameter_list|,
name|MultiExprArg
name|Exprs
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ExprResult
name|CreateGenericSelectionExpr
parameter_list|(
name|SourceLocation
name|KeyLoc
parameter_list|,
name|SourceLocation
name|DefaultLoc
parameter_list|,
name|SourceLocation
name|RParenLoc
parameter_list|,
name|Expr
modifier|*
name|ControllingExpr
parameter_list|,
name|TypeSourceInfo
modifier|*
modifier|*
name|Types
parameter_list|,
name|Expr
modifier|*
modifier|*
name|Exprs
parameter_list|,
name|unsigned
name|NumAssocs
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|// Binary/Unary Operators.  'Tok' is the token for the operator.
end_comment

begin_function_decl
name|ExprResult
name|CreateBuiltinUnaryOp
parameter_list|(
name|SourceLocation
name|OpLoc
parameter_list|,
name|UnaryOperatorKind
name|Opc
parameter_list|,
name|Expr
modifier|*
name|InputArg
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ExprResult
name|BuildUnaryOp
parameter_list|(
name|Scope
modifier|*
name|S
parameter_list|,
name|SourceLocation
name|OpLoc
parameter_list|,
name|UnaryOperatorKind
name|Opc
parameter_list|,
name|Expr
modifier|*
name|input
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
name|ExprResult
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
name|Expr
operator|*
name|Input
argument_list|)
decl_stmt|;
end_decl_stmt

begin_function_decl
name|ExprResult
name|CreateUnaryExprOrTypeTraitExpr
parameter_list|(
name|TypeSourceInfo
modifier|*
name|T
parameter_list|,
name|SourceLocation
name|OpLoc
parameter_list|,
name|UnaryExprOrTypeTrait
name|ExprKind
parameter_list|,
name|SourceRange
name|R
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ExprResult
name|CreateUnaryExprOrTypeTraitExpr
parameter_list|(
name|Expr
modifier|*
name|E
parameter_list|,
name|SourceLocation
name|OpLoc
parameter_list|,
name|UnaryExprOrTypeTrait
name|ExprKind
parameter_list|,
name|SourceRange
name|R
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ExprResult
name|ActOnUnaryExprOrTypeTraitExpr
parameter_list|(
name|SourceLocation
name|OpLoc
parameter_list|,
name|UnaryExprOrTypeTrait
name|ExprKind
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
name|ExprResult
name|CheckPlaceholderExpr
parameter_list|(
name|Expr
modifier|*
name|E
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|CheckVecStepExpr
parameter_list|(
name|Expr
modifier|*
name|E
parameter_list|,
name|SourceLocation
name|OpLoc
parameter_list|,
name|SourceRange
name|R
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|CheckUnaryExprOrTypeTraitOperand
parameter_list|(
name|QualType
name|type
parameter_list|,
name|SourceLocation
name|OpLoc
parameter_list|,
name|SourceRange
name|R
parameter_list|,
name|UnaryExprOrTypeTrait
name|ExprKind
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ExprResult
name|ActOnSizeofParameterPackExpr
parameter_list|(
name|Scope
modifier|*
name|S
parameter_list|,
name|SourceLocation
name|OpLoc
parameter_list|,
name|IdentifierInfo
modifier|&
name|Name
parameter_list|,
name|SourceLocation
name|NameLoc
parameter_list|,
name|SourceLocation
name|RParenLoc
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
name|ExprResult
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
name|Expr
operator|*
name|Input
argument_list|)
decl_stmt|;
end_decl_stmt

begin_function_decl
name|ExprResult
name|ActOnArraySubscriptExpr
parameter_list|(
name|Scope
modifier|*
name|S
parameter_list|,
name|Expr
modifier|*
name|Base
parameter_list|,
name|SourceLocation
name|LLoc
parameter_list|,
name|Expr
modifier|*
name|Idx
parameter_list|,
name|SourceLocation
name|RLoc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ExprResult
name|CreateBuiltinArraySubscriptExpr
parameter_list|(
name|Expr
modifier|*
name|Base
parameter_list|,
name|SourceLocation
name|LLoc
parameter_list|,
name|Expr
modifier|*
name|Idx
parameter_list|,
name|SourceLocation
name|RLoc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ExprResult
name|BuildMemberReferenceExpr
parameter_list|(
name|Expr
modifier|*
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
specifier|const
name|DeclarationNameInfo
modifier|&
name|NameInfo
parameter_list|,
specifier|const
name|TemplateArgumentListInfo
modifier|*
name|TemplateArgs
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ExprResult
name|BuildMemberReferenceExpr
parameter_list|(
name|Expr
modifier|*
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
name|ExprResult
name|LookupMemberExpr
parameter_list|(
name|LookupResult
modifier|&
name|R
parameter_list|,
name|ExprResult
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
name|Decl
modifier|*
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
name|ExprResult
name|ActOnDependentMemberExpr
parameter_list|(
name|Expr
modifier|*
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
specifier|const
name|DeclarationNameInfo
modifier|&
name|NameInfo
parameter_list|,
specifier|const
name|TemplateArgumentListInfo
modifier|*
name|TemplateArgs
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
name|ExprResult
name|ActOnMemberAccessExpr
argument_list|(
name|Scope
operator|*
name|S
argument_list|,
name|Expr
operator|*
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
name|Decl
operator|*
name|ObjCImpDecl
argument_list|,
name|bool
name|HasTrailingLParen
argument_list|)
decl_stmt|;
end_decl_stmt

begin_function_decl
name|void
name|ActOnDefaultCtorInitializers
parameter_list|(
name|Decl
modifier|*
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
name|ExprResult
name|ActOnCallExpr
parameter_list|(
name|Scope
modifier|*
name|S
parameter_list|,
name|Expr
modifier|*
name|Fn
parameter_list|,
name|SourceLocation
name|LParenLoc
parameter_list|,
name|MultiExprArg
name|Args
parameter_list|,
name|SourceLocation
name|RParenLoc
parameter_list|,
name|Expr
modifier|*
name|ExecConfig
init|=
literal|0
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ExprResult
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
parameter_list|,
name|Expr
modifier|*
name|ExecConfig
init|=
literal|0
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ExprResult
name|ActOnCUDAExecConfigExpr
parameter_list|(
name|Scope
modifier|*
name|S
parameter_list|,
name|SourceLocation
name|LLLLoc
parameter_list|,
name|MultiExprArg
name|ExecConfig
parameter_list|,
name|SourceLocation
name|GGGLoc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ExprResult
name|ActOnCastExpr
parameter_list|(
name|Scope
modifier|*
name|S
parameter_list|,
name|SourceLocation
name|LParenLoc
parameter_list|,
name|ParsedType
name|Ty
parameter_list|,
name|SourceLocation
name|RParenLoc
parameter_list|,
name|Expr
modifier|*
name|Op
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ExprResult
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
name|Expr
modifier|*
name|Op
parameter_list|)
function_decl|;
end_function_decl

begin_function
name|bool
name|TypeIsVectorType
parameter_list|(
name|ParsedType
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
name|ExprResult
name|MaybeConvertParenListExprToParenExpr
parameter_list|(
name|Scope
modifier|*
name|S
parameter_list|,
name|Expr
modifier|*
name|ME
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ExprResult
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
name|Expr
modifier|*
name|E
parameter_list|,
name|TypeSourceInfo
modifier|*
name|TInfo
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ExprResult
name|ActOnCompoundLiteral
parameter_list|(
name|SourceLocation
name|LParenLoc
parameter_list|,
name|ParsedType
name|Ty
parameter_list|,
name|SourceLocation
name|RParenLoc
parameter_list|,
name|Expr
modifier|*
name|Op
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ExprResult
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
name|Expr
modifier|*
name|InitExpr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ExprResult
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
name|ExprResult
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
name|ExprResult
name|Init
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
name|ExprResult
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
name|Expr
operator|*
name|LHS
argument_list|,
name|Expr
operator|*
name|RHS
argument_list|)
decl_stmt|;
end_decl_stmt

begin_function_decl
name|ExprResult
name|BuildBinOp
parameter_list|(
name|Scope
modifier|*
name|S
parameter_list|,
name|SourceLocation
name|OpLoc
parameter_list|,
name|BinaryOperatorKind
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

begin_function_decl
name|ExprResult
name|CreateBuiltinBinOp
parameter_list|(
name|SourceLocation
name|TokLoc
parameter_list|,
name|BinaryOperatorKind
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
name|ExprResult
name|ActOnConditionalOp
parameter_list|(
name|SourceLocation
name|QuestionLoc
parameter_list|,
name|SourceLocation
name|ColonLoc
parameter_list|,
name|Expr
modifier|*
name|Cond
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

begin_comment
comment|/// ActOnAddrLabel - Parse the GNU address of label extension: "&&foo".
end_comment

begin_function_decl
name|ExprResult
name|ActOnAddrLabel
parameter_list|(
name|SourceLocation
name|OpLoc
parameter_list|,
name|SourceLocation
name|LabLoc
parameter_list|,
name|LabelDecl
modifier|*
name|LD
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ExprResult
name|ActOnStmtExpr
parameter_list|(
name|SourceLocation
name|LPLoc
parameter_list|,
name|Stmt
modifier|*
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
comment|// __builtin_offsetof(type, identifier(.identifier|[expr])*)
end_comment

begin_struct
struct|struct
name|OffsetOfComponent
block|{
name|SourceLocation
name|LocStart
decl_stmt|,
name|LocEnd
decl_stmt|;
name|bool
name|isBrackets
decl_stmt|;
comment|// true if [expr], false if .ident
union|union
block|{
name|IdentifierInfo
modifier|*
name|IdentInfo
decl_stmt|;
name|ExprTy
modifier|*
name|E
decl_stmt|;
block|}
name|U
union|;
block|}
struct|;
end_struct

begin_comment
comment|/// __builtin_offsetof(type, a.b[123][456].c)
end_comment

begin_function_decl
name|ExprResult
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
name|ExprResult
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
name|ParsedType
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
comment|// __builtin_choose_expr(constExpr, expr1, expr2)
end_comment

begin_function_decl
name|ExprResult
name|ActOnChooseExpr
parameter_list|(
name|SourceLocation
name|BuiltinLoc
parameter_list|,
name|Expr
modifier|*
name|cond
parameter_list|,
name|Expr
modifier|*
name|expr1
parameter_list|,
name|Expr
modifier|*
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
name|ExprResult
name|ActOnVAArg
parameter_list|(
name|SourceLocation
name|BuiltinLoc
parameter_list|,
name|Expr
modifier|*
name|expr
parameter_list|,
name|ParsedType
name|type
parameter_list|,
name|SourceLocation
name|RPLoc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ExprResult
name|BuildVAArgExpr
parameter_list|(
name|SourceLocation
name|BuiltinLoc
parameter_list|,
name|Expr
modifier|*
name|expr
parameter_list|,
name|TypeSourceInfo
modifier|*
name|TInfo
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
name|ExprResult
name|ActOnGNUNullExpr
parameter_list|(
name|SourceLocation
name|TokenLoc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|CheckCaseExpression
parameter_list|(
name|Expr
modifier|*
name|expr
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
name|ExprResult
name|ActOnBlockStmtExpr
parameter_list|(
name|SourceLocation
name|CaretLoc
parameter_list|,
name|Stmt
modifier|*
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
name|Decl
modifier|*
name|ActOnStartNamespaceDef
parameter_list|(
name|Scope
modifier|*
name|S
parameter_list|,
name|SourceLocation
name|InlineLoc
parameter_list|,
name|SourceLocation
name|NamespaceLoc
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
name|void
name|ActOnFinishNamespaceDef
parameter_list|(
name|Decl
modifier|*
name|Dcl
parameter_list|,
name|SourceLocation
name|RBrace
parameter_list|)
function_decl|;
end_function_decl

begin_expr_stmt
name|NamespaceDecl
operator|*
name|getStdNamespace
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt

begin_function_decl
name|NamespaceDecl
modifier|*
name|getOrCreateStdNamespace
parameter_list|()
function_decl|;
end_function_decl

begin_expr_stmt
name|CXXRecordDecl
operator|*
name|getStdBadAlloc
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt

begin_function_decl
name|Decl
modifier|*
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
name|Decl
modifier|*
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
specifier|const
name|DeclarationNameInfo
modifier|&
name|NameInfo
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
name|bool
name|CheckInheritedConstructorUsingDecl
parameter_list|(
name|UsingDecl
modifier|*
name|UD
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|Decl
modifier|*
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

begin_function_decl
name|Decl
modifier|*
name|ActOnAliasDeclaration
parameter_list|(
name|Scope
modifier|*
name|CurScope
parameter_list|,
name|AccessSpecifier
name|AS
parameter_list|,
name|SourceLocation
name|UsingLoc
parameter_list|,
name|UnqualifiedId
modifier|&
name|Name
parameter_list|,
name|TypeResult
name|Type
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
name|void
name|AddCXXDirectInitializerToDecl
parameter_list|(
name|Decl
modifier|*
name|Dcl
parameter_list|,
name|SourceLocation
name|LParenLoc
parameter_list|,
name|MultiExprArg
name|Exprs
parameter_list|,
name|SourceLocation
name|RParenLoc
parameter_list|,
name|bool
name|TypeMayContainAuto
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

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param ConstructKind - a CXXConstructExpr::ConstructionKind
end_comment

begin_function_decl
name|ExprResult
name|BuildCXXConstructExpr
parameter_list|(
name|SourceLocation
name|ConstructLoc
parameter_list|,
name|QualType
name|DeclInitType
parameter_list|,
name|CXXConstructorDecl
modifier|*
name|Constructor
parameter_list|,
name|MultiExprArg
name|Exprs
parameter_list|,
name|bool
name|RequiresZeroInit
parameter_list|,
name|unsigned
name|ConstructKind
parameter_list|,
name|SourceRange
name|ParenRange
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|// FIXME: Can re remove this and have the above BuildCXXConstructExpr check if
end_comment

begin_comment
comment|// the constructor can be elidable?
end_comment

begin_function_decl
name|ExprResult
name|BuildCXXConstructExpr
parameter_list|(
name|SourceLocation
name|ConstructLoc
parameter_list|,
name|QualType
name|DeclInitType
parameter_list|,
name|CXXConstructorDecl
modifier|*
name|Constructor
parameter_list|,
name|bool
name|Elidable
parameter_list|,
name|MultiExprArg
name|Exprs
parameter_list|,
name|bool
name|RequiresZeroInit
parameter_list|,
name|unsigned
name|ConstructKind
parameter_list|,
name|SourceRange
name|ParenRange
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// BuildCXXDefaultArgExpr - Creates a CXXDefaultArgExpr, instantiating
end_comment

begin_comment
comment|/// the default expr if needed.
end_comment

begin_function_decl
name|ExprResult
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
comment|/// \brief Declare all inherited constructors for the given class.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param ClassDecl The class declaration into which the inherited
end_comment

begin_comment
comment|/// constructors will be added.
end_comment

begin_function_decl
name|void
name|DeclareInheritedConstructors
parameter_list|(
name|CXXRecordDecl
modifier|*
name|ClassDecl
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
name|ExprResult
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
name|Expr
operator|*
operator|>
operator|&
name|ConvertedArgs
argument_list|)
decl_stmt|;
end_decl_stmt

begin_function_decl
name|ParsedType
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
name|ParsedType
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
name|ExprResult
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
name|ParsedType
name|Ty
argument_list|,
name|SourceLocation
name|RAngleBracketLoc
argument_list|,
name|SourceLocation
name|LParenLoc
argument_list|,
name|Expr
operator|*
name|E
argument_list|,
name|SourceLocation
name|RParenLoc
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|ExprResult
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
name|Expr
operator|*
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
name|ExprResult
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
name|ExprResult
name|BuildCXXTypeId
parameter_list|(
name|QualType
name|TypeInfoType
parameter_list|,
name|SourceLocation
name|TypeidLoc
parameter_list|,
name|Expr
modifier|*
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
name|ExprResult
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

begin_function_decl
name|ExprResult
name|BuildCXXUuidof
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
name|ExprResult
name|BuildCXXUuidof
parameter_list|(
name|QualType
name|TypeInfoType
parameter_list|,
name|SourceLocation
name|TypeidLoc
parameter_list|,
name|Expr
modifier|*
name|Operand
parameter_list|,
name|SourceLocation
name|RParenLoc
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// ActOnCXXUuidof - Parse __uuidof( something ).
end_comment

begin_function_decl
name|ExprResult
name|ActOnCXXUuidof
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
name|ExprResult
name|ActOnCXXThis
parameter_list|(
name|SourceLocation
name|loc
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// tryCaptureCXXThis - Try to capture a 'this' pointer.  Returns a
end_comment

begin_comment
comment|/// pointer to an instance method whose 'this' pointer is
end_comment

begin_comment
comment|/// capturable, or null if this is not possible.
end_comment

begin_function_decl
name|CXXMethodDecl
modifier|*
name|tryCaptureCXXThis
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/// ActOnCXXBoolLiteral - Parse {true,false} literals.
end_comment

begin_decl_stmt
name|ExprResult
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
name|ExprResult
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
name|ExprResult
name|ActOnCXXThrow
parameter_list|(
name|SourceLocation
name|OpLoc
parameter_list|,
name|Expr
modifier|*
name|expr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ExprResult
name|CheckCXXThrowOperand
parameter_list|(
name|SourceLocation
name|ThrowLoc
parameter_list|,
name|Expr
modifier|*
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
name|ExprResult
name|ActOnCXXTypeConstructExpr
parameter_list|(
name|ParsedType
name|TypeRep
parameter_list|,
name|SourceLocation
name|LParenLoc
parameter_list|,
name|MultiExprArg
name|Exprs
parameter_list|,
name|SourceLocation
name|RParenLoc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ExprResult
name|BuildCXXTypeConstructExpr
parameter_list|(
name|TypeSourceInfo
modifier|*
name|Type
parameter_list|,
name|SourceLocation
name|LParenLoc
parameter_list|,
name|MultiExprArg
name|Exprs
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
name|ExprResult
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
name|ExprResult
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
name|TypeSourceInfo
modifier|*
name|AllocTypeInfo
parameter_list|,
name|Expr
modifier|*
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
parameter_list|,
name|bool
name|TypeMayContainAuto
init|=
name|true
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
name|ExprResult
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
name|Expr
modifier|*
name|Operand
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
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
name|ExprResult
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

begin_function_decl
name|ExprResult
name|ActOnNoexceptExpr
parameter_list|(
name|SourceLocation
name|KeyLoc
parameter_list|,
name|SourceLocation
name|LParen
parameter_list|,
name|Expr
modifier|*
name|Operand
parameter_list|,
name|SourceLocation
name|RParen
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ExprResult
name|BuildCXXNoexceptExpr
parameter_list|(
name|SourceLocation
name|KeyLoc
parameter_list|,
name|Expr
modifier|*
name|Operand
parameter_list|,
name|SourceLocation
name|RParen
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
name|ExprResult
name|ActOnUnaryTypeTrait
parameter_list|(
name|UnaryTypeTrait
name|OTT
parameter_list|,
name|SourceLocation
name|KWLoc
parameter_list|,
name|ParsedType
name|Ty
parameter_list|,
name|SourceLocation
name|RParen
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ExprResult
name|BuildUnaryTypeTrait
parameter_list|(
name|UnaryTypeTrait
name|OTT
parameter_list|,
name|SourceLocation
name|KWLoc
parameter_list|,
name|TypeSourceInfo
modifier|*
name|T
parameter_list|,
name|SourceLocation
name|RParen
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// ActOnBinaryTypeTrait - Parsed one of the bianry type trait support
end_comment

begin_comment
comment|/// pseudo-functions.
end_comment

begin_function_decl
name|ExprResult
name|ActOnBinaryTypeTrait
parameter_list|(
name|BinaryTypeTrait
name|OTT
parameter_list|,
name|SourceLocation
name|KWLoc
parameter_list|,
name|ParsedType
name|LhsTy
parameter_list|,
name|ParsedType
name|RhsTy
parameter_list|,
name|SourceLocation
name|RParen
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ExprResult
name|BuildBinaryTypeTrait
parameter_list|(
name|BinaryTypeTrait
name|BTT
parameter_list|,
name|SourceLocation
name|KWLoc
parameter_list|,
name|TypeSourceInfo
modifier|*
name|LhsT
parameter_list|,
name|TypeSourceInfo
modifier|*
name|RhsT
parameter_list|,
name|SourceLocation
name|RParen
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// ActOnArrayTypeTrait - Parsed one of the bianry type trait support
end_comment

begin_comment
comment|/// pseudo-functions.
end_comment

begin_function_decl
name|ExprResult
name|ActOnArrayTypeTrait
parameter_list|(
name|ArrayTypeTrait
name|ATT
parameter_list|,
name|SourceLocation
name|KWLoc
parameter_list|,
name|ParsedType
name|LhsTy
parameter_list|,
name|Expr
modifier|*
name|DimExpr
parameter_list|,
name|SourceLocation
name|RParen
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ExprResult
name|BuildArrayTypeTrait
parameter_list|(
name|ArrayTypeTrait
name|ATT
parameter_list|,
name|SourceLocation
name|KWLoc
parameter_list|,
name|TypeSourceInfo
modifier|*
name|TSInfo
parameter_list|,
name|Expr
modifier|*
name|DimExpr
parameter_list|,
name|SourceLocation
name|RParen
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// ActOnExpressionTrait - Parsed one of the unary type trait support
end_comment

begin_comment
comment|/// pseudo-functions.
end_comment

begin_function_decl
name|ExprResult
name|ActOnExpressionTrait
parameter_list|(
name|ExpressionTrait
name|OET
parameter_list|,
name|SourceLocation
name|KWLoc
parameter_list|,
name|Expr
modifier|*
name|Queried
parameter_list|,
name|SourceLocation
name|RParen
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ExprResult
name|BuildExpressionTrait
parameter_list|(
name|ExpressionTrait
name|OET
parameter_list|,
name|SourceLocation
name|KWLoc
parameter_list|,
name|Expr
modifier|*
name|Queried
parameter_list|,
name|SourceLocation
name|RParen
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
name|ExprResult
name|ActOnStartCXXMemberReference
argument_list|(
name|Scope
operator|*
name|S
argument_list|,
name|Expr
operator|*
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
name|ParsedType
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
name|ExprResult
name|DiagnoseDtorReference
parameter_list|(
name|SourceLocation
name|NameLoc
parameter_list|,
name|Expr
modifier|*
name|MemExpr
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
name|ExprResult
name|BuildPseudoDestructorExpr
argument_list|(
name|Expr
operator|*
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
name|ExprResult
name|ActOnPseudoDestructorExpr
argument_list|(
name|Scope
operator|*
name|S
argument_list|,
name|Expr
operator|*
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
comment|/// MaybeCreateExprWithCleanups - If the current full-expression
end_comment

begin_comment
comment|/// requires any cleanups, surround it with a ExprWithCleanups node.
end_comment

begin_comment
comment|/// Otherwise, just returns the passed-in expression.
end_comment

begin_function_decl
name|Expr
modifier|*
name|MaybeCreateExprWithCleanups
parameter_list|(
name|Expr
modifier|*
name|SubExpr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|Stmt
modifier|*
name|MaybeCreateStmtWithCleanups
parameter_list|(
name|Stmt
modifier|*
name|SubStmt
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ExprResult
name|MaybeCreateExprWithCleanups
parameter_list|(
name|ExprResult
name|SubExpr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ExprResult
name|ActOnFinishFullExpr
parameter_list|(
name|Expr
modifier|*
name|Expr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|StmtResult
name|ActOnFinishFullStmt
parameter_list|(
name|Stmt
modifier|*
name|Stmt
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
comment|/// \brief The parser has parsed a global nested-name-specifier '::'.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param S The scope in which this nested-name-specifier occurs.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param CCLoc The location of the '::'.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param SS The nested-name-specifier, which will be updated in-place
end_comment

begin_comment
comment|/// to reflect the parsed nested-name-specifier.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \returns true if an error occurred, false otherwise.
end_comment

begin_function_decl
name|bool
name|ActOnCXXGlobalScopeSpecifier
parameter_list|(
name|Scope
modifier|*
name|S
parameter_list|,
name|SourceLocation
name|CCLoc
parameter_list|,
name|CXXScopeSpec
modifier|&
name|SS
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
name|ParsedType
name|ObjectType
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|BuildCXXNestedNameSpecifier
parameter_list|(
name|Scope
modifier|*
name|S
parameter_list|,
name|IdentifierInfo
modifier|&
name|Identifier
parameter_list|,
name|SourceLocation
name|IdentifierLoc
parameter_list|,
name|SourceLocation
name|CCLoc
parameter_list|,
name|QualType
name|ObjectType
parameter_list|,
name|bool
name|EnteringContext
parameter_list|,
name|CXXScopeSpec
modifier|&
name|SS
parameter_list|,
name|NamedDecl
modifier|*
name|ScopeLookupResult
parameter_list|,
name|bool
name|ErrorRecoveryLookup
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// \brief The parser has parsed a nested-name-specifier 'identifier::'.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param S The scope in which this nested-name-specifier occurs.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param Identifier The identifier preceding the '::'.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param IdentifierLoc The location of the identifier.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param CCLoc The location of the '::'.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param ObjectType The type of the object, if we're parsing
end_comment

begin_comment
comment|/// nested-name-specifier in a member access expression.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param EnteringContext Whether we're entering the context nominated by
end_comment

begin_comment
comment|/// this nested-name-specifier.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param SS The nested-name-specifier, which is both an input
end_comment

begin_comment
comment|/// parameter (the nested-name-specifier before this type) and an
end_comment

begin_comment
comment|/// output parameter (containing the full nested-name-specifier,
end_comment

begin_comment
comment|/// including this new type).
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \returns true if an error occurred, false otherwise.
end_comment

begin_function_decl
name|bool
name|ActOnCXXNestedNameSpecifier
parameter_list|(
name|Scope
modifier|*
name|S
parameter_list|,
name|IdentifierInfo
modifier|&
name|Identifier
parameter_list|,
name|SourceLocation
name|IdentifierLoc
parameter_list|,
name|SourceLocation
name|CCLoc
parameter_list|,
name|ParsedType
name|ObjectType
parameter_list|,
name|bool
name|EnteringContext
parameter_list|,
name|CXXScopeSpec
modifier|&
name|SS
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
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
name|Identifier
parameter_list|,
name|SourceLocation
name|IdentifierLoc
parameter_list|,
name|SourceLocation
name|ColonLoc
parameter_list|,
name|ParsedType
name|ObjectType
parameter_list|,
name|bool
name|EnteringContext
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// \brief The parser has parsed a nested-name-specifier
end_comment

begin_comment
comment|/// 'template[opt] template-name< template-args>::'.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param S The scope in which this nested-name-specifier occurs.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param TemplateLoc The location of the 'template' keyword, if any.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param SS The nested-name-specifier, which is both an input
end_comment

begin_comment
comment|/// parameter (the nested-name-specifier before this type) and an
end_comment

begin_comment
comment|/// output parameter (containing the full nested-name-specifier,
end_comment

begin_comment
comment|/// including this new type).
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param TemplateLoc the location of the 'template' keyword, if any.
end_comment

begin_comment
comment|/// \param TemplateName The template name.
end_comment

begin_comment
comment|/// \param TemplateNameLoc The location of the template name.
end_comment

begin_comment
comment|/// \param LAngleLoc The location of the opening angle bracket  ('<').
end_comment

begin_comment
comment|/// \param TemplateArgs The template arguments.
end_comment

begin_comment
comment|/// \param RAngleLoc The location of the closing angle bracket  ('>').
end_comment

begin_comment
comment|/// \param CCLoc The location of the '::'.
end_comment

begin_comment
comment|/// \param EnteringContext Whether we're entering the context of the
end_comment

begin_comment
comment|/// nested-name-specifier.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \returns true if an error occurred, false otherwise.
end_comment

begin_function_decl
name|bool
name|ActOnCXXNestedNameSpecifier
parameter_list|(
name|Scope
modifier|*
name|S
parameter_list|,
name|SourceLocation
name|TemplateLoc
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
name|SourceLocation
name|CCLoc
parameter_list|,
name|bool
name|EnteringContext
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// \brief Given a C++ nested-name-specifier, produce an annotation value
end_comment

begin_comment
comment|/// that the parser can use later to reconstruct the given
end_comment

begin_comment
comment|/// nested-name-specifier.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param SS A nested-name-specifier.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \returns A pointer containing all of the information in the
end_comment

begin_comment
comment|/// nested-name-specifier \p SS.
end_comment

begin_function_decl
name|void
modifier|*
name|SaveNestedNameSpecifierAnnotation
parameter_list|(
name|CXXScopeSpec
modifier|&
name|SS
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// \brief Given an annotation pointer for a nested-name-specifier, restore
end_comment

begin_comment
comment|/// the nested-name-specifier structure.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param Annotation The annotation pointer, produced by
end_comment

begin_comment
comment|/// \c SaveNestedNameSpecifierAnnotation().
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param AnnotationRange The source range corresponding to the annotation.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param SS The nested-name-specifier that will be updated with the contents
end_comment

begin_comment
comment|/// of the annotation pointer.
end_comment

begin_function_decl
name|void
name|RestoreNestedNameSpecifierAnnotation
parameter_list|(
name|void
modifier|*
name|Annotation
parameter_list|,
name|SourceRange
name|AnnotationRange
parameter_list|,
name|CXXScopeSpec
modifier|&
name|SS
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
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
name|void
name|ActOnCXXEnterDeclInitializer
parameter_list|(
name|Scope
modifier|*
name|S
parameter_list|,
name|Decl
modifier|*
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
name|void
name|ActOnCXXExitDeclInitializer
parameter_list|(
name|Scope
modifier|*
name|S
parameter_list|,
name|Decl
modifier|*
name|Dcl
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|// ParseObjCStringLiteral - Parse Objective-C string literals.
end_comment

begin_function_decl
name|ExprResult
name|ParseObjCStringLiteral
parameter_list|(
name|SourceLocation
modifier|*
name|AtLocs
parameter_list|,
name|Expr
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
name|ExprResult
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
name|ParsedType
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
name|Decl
modifier|*
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
name|Decl
modifier|*
name|ActOnFinishLinkageSpecification
parameter_list|(
name|Scope
modifier|*
name|S
parameter_list|,
name|Decl
modifier|*
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
init|=
literal|0
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|Decl
modifier|*
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
name|Decl
modifier|*
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
name|Expr
modifier|*
name|BitfieldWidth
parameter_list|,
specifier|const
name|VirtSpecifiers
modifier|&
name|VS
parameter_list|,
name|Expr
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
name|MemInitResult
name|ActOnMemInitializer
parameter_list|(
name|Decl
modifier|*
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
name|ParsedType
name|TemplateTypeTy
parameter_list|,
name|SourceLocation
name|IdLoc
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
parameter_list|,
name|SourceLocation
name|EllipsisLoc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|MemInitResult
name|BuildMemberInitializer
parameter_list|(
name|ValueDecl
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
parameter_list|,
name|SourceLocation
name|EllipsisLoc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|MemInitResult
name|BuildDelegatingInitializer
parameter_list|(
name|TypeSourceInfo
modifier|*
name|TInfo
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
name|BaseLoc
parameter_list|,
name|SourceLocation
name|RParenLoc
parameter_list|,
name|SourceLocation
name|LParenLoc
parameter_list|,
name|CXXRecordDecl
modifier|*
name|ClassDecl
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|SetDelegatingInitializer
parameter_list|(
name|CXXConstructorDecl
modifier|*
name|Constructor
parameter_list|,
name|CXXCtorInitializer
modifier|*
name|Initializer
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|SetCtorInitializers
parameter_list|(
name|CXXConstructorDecl
modifier|*
name|Constructor
parameter_list|,
name|CXXCtorInitializer
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

begin_typedef
typedef|typedef
name|std
operator|::
name|pair
operator|<
name|CXXRecordDecl
operator|*
operator|,
name|SourceLocation
operator|>
name|VTableUse
expr_stmt|;
end_typedef

begin_comment
comment|/// \brief The list of vtables that are required but have not yet been
end_comment

begin_comment
comment|/// materialized.
end_comment

begin_expr_stmt
name|llvm
operator|::
name|SmallVector
operator|<
name|VTableUse
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
comment|/// MarkVirtualMembersReferenced - Will mark all members of the given
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
name|void
name|ActOnMemInitializers
parameter_list|(
name|Decl
modifier|*
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
name|Decl
modifier|*
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
name|void
name|ActOnReenterTemplateScope
parameter_list|(
name|Scope
modifier|*
name|S
parameter_list|,
name|Decl
modifier|*
name|Template
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ActOnReenterDeclaratorTemplateScope
parameter_list|(
name|Scope
modifier|*
name|S
parameter_list|,
name|DeclaratorDecl
modifier|*
name|D
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ActOnStartDelayedMemberDeclarations
parameter_list|(
name|Scope
modifier|*
name|S
parameter_list|,
name|Decl
modifier|*
name|Record
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ActOnStartDelayedCXXMethodDeclaration
parameter_list|(
name|Scope
modifier|*
name|S
parameter_list|,
name|Decl
modifier|*
name|Method
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ActOnDelayedCXXMethodParameter
parameter_list|(
name|Scope
modifier|*
name|S
parameter_list|,
name|Decl
modifier|*
name|Param
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ActOnFinishDelayedCXXMethodDeclaration
parameter_list|(
name|Scope
modifier|*
name|S
parameter_list|,
name|Decl
modifier|*
name|Method
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ActOnFinishDelayedMemberDeclarations
parameter_list|(
name|Scope
modifier|*
name|S
parameter_list|,
name|Decl
modifier|*
name|Record
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|MarkAsLateParsedTemplate
parameter_list|(
name|FunctionDecl
modifier|*
name|FD
parameter_list|,
name|bool
name|Flag
init|=
name|true
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|IsInsideALocalClassWithinATemplateFunction
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|Decl
modifier|*
name|ActOnStaticAssertDeclaration
parameter_list|(
name|SourceLocation
name|StaticAssertLoc
parameter_list|,
name|Expr
modifier|*
name|AssertExpr
parameter_list|,
name|Expr
modifier|*
name|AssertMessageExpr
parameter_list|,
name|SourceLocation
name|RParenLoc
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
name|Decl
modifier|*
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
name|Decl
modifier|*
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

begin_function_decl
name|QualType
name|CheckConstructorDeclarator
parameter_list|(
name|Declarator
modifier|&
name|D
parameter_list|,
name|QualType
name|R
parameter_list|,
name|StorageClass
modifier|&
name|SC
parameter_list|)
function_decl|;
end_function_decl

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

begin_function_decl
name|QualType
name|CheckDestructorDeclarator
parameter_list|(
name|Declarator
modifier|&
name|D
parameter_list|,
name|QualType
name|R
parameter_list|,
name|StorageClass
modifier|&
name|SC
parameter_list|)
function_decl|;
end_function_decl

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

begin_function_decl
name|void
name|CheckConversionDeclarator
parameter_list|(
name|Declarator
modifier|&
name|D
parameter_list|,
name|QualType
modifier|&
name|R
parameter_list|,
name|StorageClass
modifier|&
name|SC
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|Decl
modifier|*
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
name|TypeSourceInfo
modifier|*
name|TInfo
parameter_list|,
name|SourceLocation
name|EllipsisLoc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|BaseResult
name|ActOnBaseSpecifier
parameter_list|(
name|Decl
modifier|*
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
name|ParsedType
name|basetype
parameter_list|,
name|SourceLocation
name|BaseLoc
parameter_list|,
name|SourceLocation
name|EllipsisLoc
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
name|void
name|ActOnBaseSpecifiers
parameter_list|(
name|Decl
modifier|*
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
name|CXXCastPath
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
name|CXXCastPath
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
name|CXXCastPath
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
name|CXXCastPath
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
comment|/// CheckOverrideControl - Check C++0x override control semantics.
end_comment

begin_function_decl
name|void
name|CheckOverrideControl
parameter_list|(
specifier|const
name|Decl
modifier|*
name|D
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// CheckForFunctionMarkedFinal - Checks whether a virtual member function
end_comment

begin_comment
comment|/// overrides a virtual member function marked 'final', according to
end_comment

begin_comment
comment|/// C++0x [class.virtual]p3.
end_comment

begin_function_decl
name|bool
name|CheckIfOverriddenFunctionIsMarkedFinal
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

begin_decl_stmt
name|void
name|HandleDelayedAccessCheck
argument_list|(
name|sema
operator|::
name|DelayedDiagnostic
operator|&
name|DD
argument_list|,
name|Decl
operator|*
name|Ctx
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// A flag to suppress access checking.
end_comment

begin_decl_stmt
name|bool
name|SuppressAccessChecking
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// \brief When true, access checking violations are treated as SFINAE
end_comment

begin_comment
comment|/// failures rather than hard errors.
end_comment

begin_decl_stmt
name|bool
name|AccessCheckingSFINAE
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
block|,
name|AbstractArrayType
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
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|DiagnoseAbstractType
parameter_list|(
specifier|const
name|CXXRecordDecl
modifier|*
name|RD
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
name|FilterAcceptableTemplateNames
parameter_list|(
name|LookupResult
modifier|&
name|R
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|hasAnyAcceptableTemplateNames
parameter_list|(
name|LookupResult
modifier|&
name|R
parameter_list|)
function_decl|;
end_function_decl

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
name|bool
name|hasTemplateKeyword
parameter_list|,
name|UnqualifiedId
modifier|&
name|Name
parameter_list|,
name|ParsedType
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
name|Decl
modifier|*
modifier|&
name|Decl
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|Decl
modifier|*
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
name|ParsedType
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
name|Decl
modifier|*
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
name|Expr
modifier|*
name|DefaultArg
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|Decl
modifier|*
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
name|SourceLocation
name|EllipsisLoc
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
name|ParsedTemplateArgument
name|DefaultArg
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
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
name|Decl
modifier|*
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
block|,
name|TPC_FriendFunctionTemplateDefinition
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
parameter_list|,
name|bool
modifier|&
name|Invalid
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
parameter_list|,
name|unsigned
name|NumOuterTemplateParamLists
parameter_list|,
name|TemplateParameterList
modifier|*
modifier|*
name|OuterTemplateParamLists
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
name|void
name|NoteAllFoundTemplates
parameter_list|(
name|TemplateName
name|Name
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
name|TemplateArgumentListInfo
modifier|&
name|TemplateArgs
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|TypeResult
name|ActOnTemplateIdType
parameter_list|(
name|CXXScopeSpec
modifier|&
name|SS
parameter_list|,
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

begin_comment
comment|/// \brief Parsed an elaborated-type-specifier that refers to a template-id,
end_comment

begin_comment
comment|/// such as \c class T::template apply<U>.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param TUK
end_comment

begin_function_decl
name|TypeResult
name|ActOnTagTemplateIdType
parameter_list|(
name|TagUseKind
name|TUK
parameter_list|,
name|TypeSpecifierType
name|TagSpec
parameter_list|,
name|SourceLocation
name|TagLoc
parameter_list|,
name|CXXScopeSpec
modifier|&
name|SS
parameter_list|,
name|TemplateTy
name|TemplateD
parameter_list|,
name|SourceLocation
name|TemplateLoc
parameter_list|,
name|SourceLocation
name|LAngleLoc
parameter_list|,
name|ASTTemplateArgsPtr
name|TemplateArgsIn
parameter_list|,
name|SourceLocation
name|RAngleLoc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ExprResult
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
name|ExprResult
name|BuildQualifiedTemplateIdExpr
parameter_list|(
name|CXXScopeSpec
modifier|&
name|SS
parameter_list|,
specifier|const
name|DeclarationNameInfo
modifier|&
name|NameInfo
parameter_list|,
specifier|const
name|TemplateArgumentListInfo
modifier|&
name|TemplateArgs
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
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
name|ParsedType
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
name|Decl
modifier|*
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
name|Decl
modifier|*
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
name|PrevPtOfInstantiation
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

begin_decl_stmt
name|TemplateArgumentLoc
name|SubstDefaultTemplateArgumentIfAvailable
argument_list|(
name|TemplateDecl
operator|*
name|Template
argument_list|,
name|SourceLocation
name|TemplateLoc
argument_list|,
name|SourceLocation
name|RAngleLoc
argument_list|,
name|Decl
operator|*
name|Param
argument_list|,
name|llvm
operator|::
name|SmallVectorImpl
operator|<
name|TemplateArgument
operator|>
operator|&
name|Converted
argument_list|)
decl_stmt|;
end_decl_stmt

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

begin_decl_stmt
name|bool
name|CheckTemplateArgument
argument_list|(
name|NamedDecl
operator|*
name|Param
argument_list|,
specifier|const
name|TemplateArgumentLoc
operator|&
name|Arg
argument_list|,
name|NamedDecl
operator|*
name|Template
argument_list|,
name|SourceLocation
name|TemplateLoc
argument_list|,
name|SourceLocation
name|RAngleLoc
argument_list|,
name|unsigned
name|ArgumentPackIndex
argument_list|,
name|llvm
operator|::
name|SmallVectorImpl
operator|<
name|TemplateArgument
operator|>
operator|&
name|Converted
argument_list|,
name|CheckTemplateArgumentKind
name|CTAK
operator|=
name|CTAK_Specified
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// \brief Check that the given template arguments can be be provided to
end_comment

begin_comment
comment|/// the given template, converting the arguments along the way.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param Template The template to which the template arguments are being
end_comment

begin_comment
comment|/// provided.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param TemplateLoc The location of the template name in the source.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param TemplateArgs The list of template arguments. If the template is
end_comment

begin_comment
comment|/// a template template parameter, this function may extend the set of
end_comment

begin_comment
comment|/// template arguments to also include substituted, defaulted template
end_comment

begin_comment
comment|/// arguments.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param PartialTemplateArgs True if the list of template arguments is
end_comment

begin_comment
comment|/// intentionally partial, e.g., because we're checking just the initial
end_comment

begin_comment
comment|/// set of template arguments.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param Converted Will receive the converted, canonicalized template
end_comment

begin_comment
comment|/// arguments.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \returns True if an error occurred, false otherwise.
end_comment

begin_decl_stmt
name|bool
name|CheckTemplateArgumentList
argument_list|(
name|TemplateDecl
operator|*
name|Template
argument_list|,
name|SourceLocation
name|TemplateLoc
argument_list|,
name|TemplateArgumentListInfo
operator|&
name|TemplateArgs
argument_list|,
name|bool
name|PartialTemplateArgs
argument_list|,
name|llvm
operator|::
name|SmallVectorImpl
operator|<
name|TemplateArgument
operator|>
operator|&
name|Converted
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|bool
name|CheckTemplateTypeArgument
argument_list|(
name|TemplateTypeParmDecl
operator|*
name|Param
argument_list|,
specifier|const
name|TemplateArgumentLoc
operator|&
name|Arg
argument_list|,
name|llvm
operator|::
name|SmallVectorImpl
operator|<
name|TemplateArgument
operator|>
operator|&
name|Converted
argument_list|)
decl_stmt|;
end_decl_stmt

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
name|ExprResult
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
name|ExprResult
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
name|ExprResult
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
comment|/// \param TemplateName The template name.
end_comment

begin_comment
comment|/// \param TemplateNameLoc The location of the template name.
end_comment

begin_comment
comment|/// \param LAngleLoc The location of the opening angle bracket  ('<').
end_comment

begin_comment
comment|/// \param TemplateArgs The template arguments.
end_comment

begin_comment
comment|/// \param RAngleLoc The location of the closing angle bracket  ('>').
end_comment

begin_function_decl
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
name|SourceLocation
name|KeywordLoc
parameter_list|,
name|NestedNameSpecifierLoc
name|QualifierLoc
parameter_list|,
specifier|const
name|IdentifierInfo
modifier|&
name|II
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

begin_function_decl
name|ExprResult
name|RebuildExprInCurrentInstantiation
parameter_list|(
name|Expr
modifier|*
name|E
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
comment|//===--------------------------------------------------------------------===//
end_comment

begin_comment
comment|// C++ Variadic Templates (C++0x [temp.variadic])
end_comment

begin_comment
comment|//===--------------------------------------------------------------------===//
end_comment

begin_comment
comment|/// \brief The context in which an unexpanded parameter pack is
end_comment

begin_comment
comment|/// being diagnosed.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Note that the values of this enumeration line up with the first
end_comment

begin_comment
comment|/// argument to the \c err_unexpanded_parameter_pack diagnostic.
end_comment

begin_enum
enum|enum
name|UnexpandedParameterPackContext
block|{
comment|/// \brief An arbitrary expression.
name|UPPC_Expression
init|=
literal|0
block|,
comment|/// \brief The base type of a class type.
name|UPPC_BaseType
block|,
comment|/// \brief The type of an arbitrary declaration.
name|UPPC_DeclarationType
block|,
comment|/// \brief The type of a data member.
name|UPPC_DataMemberType
block|,
comment|/// \brief The size of a bit-field.
name|UPPC_BitFieldWidth
block|,
comment|/// \brief The expression in a static assertion.
name|UPPC_StaticAssertExpression
block|,
comment|/// \brief The fixed underlying type of an enumeration.
name|UPPC_FixedUnderlyingType
block|,
comment|/// \brief The enumerator value.
name|UPPC_EnumeratorValue
block|,
comment|/// \brief A using declaration.
name|UPPC_UsingDeclaration
block|,
comment|/// \brief A friend declaration.
name|UPPC_FriendDeclaration
block|,
comment|/// \brief A declaration qualifier.
name|UPPC_DeclarationQualifier
block|,
comment|/// \brief An initializer.
name|UPPC_Initializer
block|,
comment|/// \brief A default argument.
name|UPPC_DefaultArgument
block|,
comment|/// \brief The type of a non-type template parameter.
name|UPPC_NonTypeTemplateParameterType
block|,
comment|/// \brief The type of an exception.
name|UPPC_ExceptionType
block|,
comment|/// \brief Partial specialization.
name|UPPC_PartialSpecialization
block|}
enum|;
end_enum

begin_comment
comment|/// \brief If the given type contains an unexpanded parameter pack,
end_comment

begin_comment
comment|/// diagnose the error.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param Loc The source location where a diagnostc should be emitted.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param T The type that is being checked for unexpanded parameter
end_comment

begin_comment
comment|/// packs.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \returns true if an error occurred, false otherwise.
end_comment

begin_function_decl
name|bool
name|DiagnoseUnexpandedParameterPack
parameter_list|(
name|SourceLocation
name|Loc
parameter_list|,
name|TypeSourceInfo
modifier|*
name|T
parameter_list|,
name|UnexpandedParameterPackContext
name|UPPC
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// \brief If the given expression contains an unexpanded parameter
end_comment

begin_comment
comment|/// pack, diagnose the error.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param E The expression that is being checked for unexpanded
end_comment

begin_comment
comment|/// parameter packs.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \returns true if an error occurred, false otherwise.
end_comment

begin_function_decl
name|bool
name|DiagnoseUnexpandedParameterPack
parameter_list|(
name|Expr
modifier|*
name|E
parameter_list|,
name|UnexpandedParameterPackContext
name|UPPC
init|=
name|UPPC_Expression
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// \brief If the given nested-name-specifier contains an unexpanded
end_comment

begin_comment
comment|/// parameter pack, diagnose the error.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param SS The nested-name-specifier that is being checked for
end_comment

begin_comment
comment|/// unexpanded parameter packs.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \returns true if an error occurred, false otherwise.
end_comment

begin_function_decl
name|bool
name|DiagnoseUnexpandedParameterPack
parameter_list|(
specifier|const
name|CXXScopeSpec
modifier|&
name|SS
parameter_list|,
name|UnexpandedParameterPackContext
name|UPPC
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// \brief If the given name contains an unexpanded parameter pack,
end_comment

begin_comment
comment|/// diagnose the error.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param NameInfo The name (with source location information) that
end_comment

begin_comment
comment|/// is being checked for unexpanded parameter packs.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \returns true if an error occurred, false otherwise.
end_comment

begin_function_decl
name|bool
name|DiagnoseUnexpandedParameterPack
parameter_list|(
specifier|const
name|DeclarationNameInfo
modifier|&
name|NameInfo
parameter_list|,
name|UnexpandedParameterPackContext
name|UPPC
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// \brief If the given template name contains an unexpanded parameter pack,
end_comment

begin_comment
comment|/// diagnose the error.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param Loc The location of the template name.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param Template The template name that is being checked for unexpanded
end_comment

begin_comment
comment|/// parameter packs.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \returns true if an error occurred, false otherwise.
end_comment

begin_function_decl
name|bool
name|DiagnoseUnexpandedParameterPack
parameter_list|(
name|SourceLocation
name|Loc
parameter_list|,
name|TemplateName
name|Template
parameter_list|,
name|UnexpandedParameterPackContext
name|UPPC
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// \brief If the given template argument contains an unexpanded parameter
end_comment

begin_comment
comment|/// pack, diagnose the error.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param Arg The template argument that is being checked for unexpanded
end_comment

begin_comment
comment|/// parameter packs.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \returns true if an error occurred, false otherwise.
end_comment

begin_function_decl
name|bool
name|DiagnoseUnexpandedParameterPack
parameter_list|(
name|TemplateArgumentLoc
name|Arg
parameter_list|,
name|UnexpandedParameterPackContext
name|UPPC
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// \brief Collect the set of unexpanded parameter packs within the given
end_comment

begin_comment
comment|/// template argument.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param Arg The template argument that will be traversed to find
end_comment

begin_comment
comment|/// unexpanded parameter packs.
end_comment

begin_decl_stmt
name|void
name|collectUnexpandedParameterPacks
argument_list|(
name|TemplateArgument
name|Arg
argument_list|,
name|llvm
operator|::
name|SmallVectorImpl
operator|<
name|UnexpandedParameterPack
operator|>
operator|&
name|Unexpanded
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// \brief Collect the set of unexpanded parameter packs within the given
end_comment

begin_comment
comment|/// template argument.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param Arg The template argument that will be traversed to find
end_comment

begin_comment
comment|/// unexpanded parameter packs.
end_comment

begin_decl_stmt
name|void
name|collectUnexpandedParameterPacks
argument_list|(
name|TemplateArgumentLoc
name|Arg
argument_list|,
name|llvm
operator|::
name|SmallVectorImpl
operator|<
name|UnexpandedParameterPack
operator|>
operator|&
name|Unexpanded
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// \brief Collect the set of unexpanded parameter packs within the given
end_comment

begin_comment
comment|/// type.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param T The type that will be traversed to find
end_comment

begin_comment
comment|/// unexpanded parameter packs.
end_comment

begin_decl_stmt
name|void
name|collectUnexpandedParameterPacks
argument_list|(
name|QualType
name|T
argument_list|,
name|llvm
operator|::
name|SmallVectorImpl
operator|<
name|UnexpandedParameterPack
operator|>
operator|&
name|Unexpanded
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// \brief Collect the set of unexpanded parameter packs within the given
end_comment

begin_comment
comment|/// type.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param TL The type that will be traversed to find
end_comment

begin_comment
comment|/// unexpanded parameter packs.
end_comment

begin_decl_stmt
name|void
name|collectUnexpandedParameterPacks
argument_list|(
name|TypeLoc
name|TL
argument_list|,
name|llvm
operator|::
name|SmallVectorImpl
operator|<
name|UnexpandedParameterPack
operator|>
operator|&
name|Unexpanded
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// \brief Invoked when parsing a template argument followed by an
end_comment

begin_comment
comment|/// ellipsis, which creates a pack expansion.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param Arg The template argument preceding the ellipsis, which
end_comment

begin_comment
comment|/// may already be invalid.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param EllipsisLoc The location of the ellipsis.
end_comment

begin_function_decl
name|ParsedTemplateArgument
name|ActOnPackExpansion
parameter_list|(
specifier|const
name|ParsedTemplateArgument
modifier|&
name|Arg
parameter_list|,
name|SourceLocation
name|EllipsisLoc
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// \brief Invoked when parsing a type followed by an ellipsis, which
end_comment

begin_comment
comment|/// creates a pack expansion.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param Type The type preceding the ellipsis, which will become
end_comment

begin_comment
comment|/// the pattern of the pack expansion.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param EllipsisLoc The location of the ellipsis.
end_comment

begin_function_decl
name|TypeResult
name|ActOnPackExpansion
parameter_list|(
name|ParsedType
name|Type
parameter_list|,
name|SourceLocation
name|EllipsisLoc
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// \brief Construct a pack expansion type from the pattern of the pack
end_comment

begin_comment
comment|/// expansion.
end_comment

begin_decl_stmt
name|TypeSourceInfo
modifier|*
name|CheckPackExpansion
argument_list|(
name|TypeSourceInfo
operator|*
name|Pattern
argument_list|,
name|SourceLocation
name|EllipsisLoc
argument_list|,
name|llvm
operator|::
name|Optional
operator|<
name|unsigned
operator|>
name|NumExpansions
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// \brief Construct a pack expansion type from the pattern of the pack
end_comment

begin_comment
comment|/// expansion.
end_comment

begin_decl_stmt
name|QualType
name|CheckPackExpansion
argument_list|(
name|QualType
name|Pattern
argument_list|,
name|SourceRange
name|PatternRange
argument_list|,
name|SourceLocation
name|EllipsisLoc
argument_list|,
name|llvm
operator|::
name|Optional
operator|<
name|unsigned
operator|>
name|NumExpansions
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// \brief Invoked when parsing an expression followed by an ellipsis, which
end_comment

begin_comment
comment|/// creates a pack expansion.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param Pattern The expression preceding the ellipsis, which will become
end_comment

begin_comment
comment|/// the pattern of the pack expansion.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param EllipsisLoc The location of the ellipsis.
end_comment

begin_function_decl
name|ExprResult
name|ActOnPackExpansion
parameter_list|(
name|Expr
modifier|*
name|Pattern
parameter_list|,
name|SourceLocation
name|EllipsisLoc
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// \brief Invoked when parsing an expression followed by an ellipsis, which
end_comment

begin_comment
comment|/// creates a pack expansion.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param Pattern The expression preceding the ellipsis, which will become
end_comment

begin_comment
comment|/// the pattern of the pack expansion.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param EllipsisLoc The location of the ellipsis.
end_comment

begin_decl_stmt
name|ExprResult
name|CheckPackExpansion
argument_list|(
name|Expr
operator|*
name|Pattern
argument_list|,
name|SourceLocation
name|EllipsisLoc
argument_list|,
name|llvm
operator|::
name|Optional
operator|<
name|unsigned
operator|>
name|NumExpansions
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// \brief Determine whether we could expand a pack expansion with the
end_comment

begin_comment
comment|/// given set of parameter packs into separate arguments by repeatedly
end_comment

begin_comment
comment|/// transforming the pattern.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param EllipsisLoc The location of the ellipsis that identifies the
end_comment

begin_comment
comment|/// pack expansion.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param PatternRange The source range that covers the entire pattern of
end_comment

begin_comment
comment|/// the pack expansion.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param Unexpanded The set of unexpanded parameter packs within the
end_comment

begin_comment
comment|/// pattern.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param NumUnexpanded The number of unexpanded parameter packs in
end_comment

begin_comment
comment|/// \p Unexpanded.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param ShouldExpand Will be set to \c true if the transformer should
end_comment

begin_comment
comment|/// expand the corresponding pack expansions into separate arguments. When
end_comment

begin_comment
comment|/// set, \c NumExpansions must also be set.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param RetainExpansion Whether the caller should add an unexpanded
end_comment

begin_comment
comment|/// pack expansion after all of the expanded arguments. This is used
end_comment

begin_comment
comment|/// when extending explicitly-specified template argument packs per
end_comment

begin_comment
comment|/// C++0x [temp.arg.explicit]p9.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param NumExpansions The number of separate arguments that will be in
end_comment

begin_comment
comment|/// the expanded form of the corresponding pack expansion. This is both an
end_comment

begin_comment
comment|/// input and an output parameter, which can be set by the caller if the
end_comment

begin_comment
comment|/// number of expansions is known a priori (e.g., due to a prior substitution)
end_comment

begin_comment
comment|/// and will be set by the callee when the number of expansions is known.
end_comment

begin_comment
comment|/// The callee must set this value when \c ShouldExpand is \c true; it may
end_comment

begin_comment
comment|/// set this value in other cases.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \returns true if an error occurred (e.g., because the parameter packs
end_comment

begin_comment
comment|/// are to be instantiated with arguments of different lengths), false
end_comment

begin_comment
comment|/// otherwise. If false, \c ShouldExpand (and possibly \c NumExpansions)
end_comment

begin_comment
comment|/// must be set.
end_comment

begin_decl_stmt
name|bool
name|CheckParameterPacksForExpansion
argument_list|(
name|SourceLocation
name|EllipsisLoc
argument_list|,
name|SourceRange
name|PatternRange
argument_list|,
specifier|const
name|UnexpandedParameterPack
operator|*
name|Unexpanded
argument_list|,
name|unsigned
name|NumUnexpanded
argument_list|,
specifier|const
name|MultiLevelTemplateArgumentList
operator|&
name|TemplateArgs
argument_list|,
name|bool
operator|&
name|ShouldExpand
argument_list|,
name|bool
operator|&
name|RetainExpansion
argument_list|,
name|llvm
operator|::
name|Optional
operator|<
name|unsigned
operator|>
operator|&
name|NumExpansions
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// \brief Determine the number of arguments in the given pack expansion
end_comment

begin_comment
comment|/// type.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This routine already assumes that the pack expansion type can be
end_comment

begin_comment
comment|/// expanded and that the number of arguments in the expansion is
end_comment

begin_comment
comment|/// consistent across all of the unexpanded parameter packs in its pattern.
end_comment

begin_function_decl
name|unsigned
name|getNumArgumentsInExpansion
parameter_list|(
name|QualType
name|T
parameter_list|,
specifier|const
name|MultiLevelTemplateArgumentList
modifier|&
name|TemplateArgs
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// \brief Determine whether the given declarator contains any unexpanded
end_comment

begin_comment
comment|/// parameter packs.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This routine is used by the parser to disambiguate function declarators
end_comment

begin_comment
comment|/// with an ellipsis prior to the ')', e.g.,
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \code
end_comment

begin_comment
comment|///   void f(T...);
end_comment

begin_comment
comment|/// \endcode
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// To determine whether we have an (unnamed) function parameter pack or
end_comment

begin_comment
comment|/// a variadic function.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \returns true if the declarator contains any unexpanded parameter packs,
end_comment

begin_comment
comment|/// false otherwise.
end_comment

begin_function_decl
name|bool
name|containsUnexpandedParameterPacks
parameter_list|(
name|Declarator
modifier|&
name|D
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|//===--------------------------------------------------------------------===//
end_comment

begin_comment
comment|// C++ Template Argument Deduction (C++ [temp.deduct])
end_comment

begin_comment
comment|//===--------------------------------------------------------------------===//
end_comment

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
name|TDK_Underqualified
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

begin_decl_stmt
name|TemplateDeductionResult
name|DeduceTemplateArguments
argument_list|(
name|ClassTemplatePartialSpecializationDecl
operator|*
name|Partial
argument_list|,
specifier|const
name|TemplateArgumentList
operator|&
name|TemplateArgs
argument_list|,
name|sema
operator|::
name|TemplateDeductionInfo
operator|&
name|Info
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|TemplateDeductionResult
name|SubstituteExplicitTemplateArguments
argument_list|(
name|FunctionTemplateDecl
operator|*
name|FunctionTemplate
argument_list|,
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
name|sema
operator|::
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
name|sema
operator|::
name|TemplateDeductionInfo
operator|&
name|Info
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|TemplateDeductionResult
name|DeduceTemplateArguments
argument_list|(
name|FunctionTemplateDecl
operator|*
name|FunctionTemplate
argument_list|,
name|TemplateArgumentListInfo
operator|*
name|ExplicitTemplateArgs
argument_list|,
name|Expr
operator|*
operator|*
name|Args
argument_list|,
name|unsigned
name|NumArgs
argument_list|,
name|FunctionDecl
operator|*
operator|&
name|Specialization
argument_list|,
name|sema
operator|::
name|TemplateDeductionInfo
operator|&
name|Info
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|TemplateDeductionResult
name|DeduceTemplateArguments
argument_list|(
name|FunctionTemplateDecl
operator|*
name|FunctionTemplate
argument_list|,
name|TemplateArgumentListInfo
operator|*
name|ExplicitTemplateArgs
argument_list|,
name|QualType
name|ArgFunctionType
argument_list|,
name|FunctionDecl
operator|*
operator|&
name|Specialization
argument_list|,
name|sema
operator|::
name|TemplateDeductionInfo
operator|&
name|Info
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|TemplateDeductionResult
name|DeduceTemplateArguments
argument_list|(
name|FunctionTemplateDecl
operator|*
name|FunctionTemplate
argument_list|,
name|QualType
name|ToType
argument_list|,
name|CXXConversionDecl
operator|*
operator|&
name|Specialization
argument_list|,
name|sema
operator|::
name|TemplateDeductionInfo
operator|&
name|Info
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|TemplateDeductionResult
name|DeduceTemplateArguments
argument_list|(
name|FunctionTemplateDecl
operator|*
name|FunctionTemplate
argument_list|,
name|TemplateArgumentListInfo
operator|*
name|ExplicitTemplateArgs
argument_list|,
name|FunctionDecl
operator|*
operator|&
name|Specialization
argument_list|,
name|sema
operator|::
name|TemplateDeductionInfo
operator|&
name|Info
argument_list|)
decl_stmt|;
end_decl_stmt

begin_function_decl
name|bool
name|DeduceAutoType
parameter_list|(
name|TypeSourceInfo
modifier|*
name|AutoType
parameter_list|,
name|Expr
modifier|*
name|Initializer
parameter_list|,
name|TypeSourceInfo
modifier|*
modifier|&
name|Result
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
parameter_list|,
name|unsigned
name|NumCallArguments
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
name|unsigned
name|NumCallArguments
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
parameter_list|,
name|bool
name|Complain
init|=
name|true
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
comment|/// \brief The template (or partial specialization) in which we are
comment|/// performing the instantiation, for substitutions of prior template
comment|/// arguments.
name|NamedDecl
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
comment|/// \brief The template deduction info object associated with the
comment|/// substitution or checking of explicit or deduced template arguments.
name|sema
operator|::
name|TemplateDeductionInfo
operator|*
name|DeductionInfo
expr_stmt|;
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
operator|,
name|DeductionInfo
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
comment|/// \brief Whether we are in a SFINAE context that is not associated with
end_comment

begin_comment
comment|/// template instantiation.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This is used when setting up a SFINAE trap (\c see SFINAETrap) outside
end_comment

begin_comment
comment|/// of a template instantiation or template argument deduction.
end_comment

begin_decl_stmt
name|bool
name|InNonInstantiationSFINAEContext
decl_stmt|;
end_decl_stmt

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
comment|/// \brief The current index into pack expansion arguments that will be
end_comment

begin_comment
comment|/// used for substitution of parameter packs.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// The pack expansion index will be -1 to indicate that parameter packs
end_comment

begin_comment
comment|/// should be instantiated as themselves. Otherwise, the index specifies
end_comment

begin_comment
comment|/// which argument within the parameter pack will be used for substitution.
end_comment

begin_decl_stmt
name|int
name|ArgumentPackSubstitutionIndex
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// \brief RAII object used to change the argument pack substitution index
end_comment

begin_comment
comment|/// within a \c Sema object.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// See \c ArgumentPackSubstitutionIndex for more information.
end_comment

begin_decl_stmt
name|class
name|ArgumentPackSubstitutionIndexRAII
block|{
name|Sema
modifier|&
name|Self
decl_stmt|;
name|int
name|OldSubstitutionIndex
decl_stmt|;
name|public
label|:
name|ArgumentPackSubstitutionIndexRAII
argument_list|(
argument|Sema&Self
argument_list|,
argument|int NewSubstitutionIndex
argument_list|)
block|:
name|Self
argument_list|(
name|Self
argument_list|)
operator|,
name|OldSubstitutionIndex
argument_list|(
argument|Self.ArgumentPackSubstitutionIndex
argument_list|)
block|{
name|Self
operator|.
name|ArgumentPackSubstitutionIndex
operator|=
name|NewSubstitutionIndex
block|;     }
operator|~
name|ArgumentPackSubstitutionIndexRAII
argument_list|()
block|{
name|Self
operator|.
name|ArgumentPackSubstitutionIndex
operator|=
name|OldSubstitutionIndex
block|;     }
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_decl_stmt
name|friend
name|class
name|ArgumentPackSubstitutionRAII
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
comment|/// \brief For each declaration that involved template argument deduction, the
end_comment

begin_comment
comment|/// set of diagnostics that were suppressed during that template argument
end_comment

begin_comment
comment|/// deduction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// FIXME: Serialize this structure to the AST file.
end_comment

begin_expr_stmt
name|llvm
operator|::
name|DenseMap
operator|<
name|Decl
operator|*
operator|,
name|llvm
operator|::
name|SmallVector
operator|<
name|PartialDiagnosticAt
operator|,
literal|1
operator|>
expr|>
name|SuppressedDiagnostics
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
argument|sema::TemplateDeductionInfo&DeductionInfo
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
argument|sema::TemplateDeductionInfo&DeductionInfo
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
argument|NamedDecl *Template
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
argument|NamedDecl *Template
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
name|SavedInNonInstantiationSFINAEContext
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
comment|/// \returns An empty \c llvm::Optional if we're not in a SFINAE context.
end_comment

begin_comment
comment|/// Otherwise, contains a pointer that, if non-NULL, contains the nearest
end_comment

begin_comment
comment|/// template-deduction context object, which can be used to capture
end_comment

begin_comment
comment|/// diagnostics that will be suppressed.
end_comment

begin_expr_stmt
name|llvm
operator|::
name|Optional
operator|<
name|sema
operator|::
name|TemplateDeductionInfo
operator|*
operator|>
name|isSFINAEContext
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// \brief RAII class used to determine whether SFINAE has
end_comment

begin_comment
comment|/// trapped any errors that occur during template argument
end_comment

begin_comment
comment|/// deduction.`
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
name|bool
name|PrevInNonInstantiationSFINAEContext
decl_stmt|;
name|bool
name|PrevAccessCheckingSFINAE
decl_stmt|;
name|public
label|:
name|explicit
name|SFINAETrap
argument_list|(
argument|Sema&SemaRef
argument_list|,
argument|bool AccessCheckingSFINAE = false
argument_list|)
block|:
name|SemaRef
argument_list|(
name|SemaRef
argument_list|)
operator|,
name|PrevSFINAEErrors
argument_list|(
name|SemaRef
operator|.
name|NumSFINAEErrors
argument_list|)
operator|,
name|PrevInNonInstantiationSFINAEContext
argument_list|(
name|SemaRef
operator|.
name|InNonInstantiationSFINAEContext
argument_list|)
operator|,
name|PrevAccessCheckingSFINAE
argument_list|(
argument|SemaRef.AccessCheckingSFINAE
argument_list|)
block|{
if|if
condition|(
operator|!
name|SemaRef
operator|.
name|isSFINAEContext
argument_list|()
condition|)
name|SemaRef
operator|.
name|InNonInstantiationSFINAEContext
operator|=
name|true
expr_stmt|;
name|SemaRef
operator|.
name|AccessCheckingSFINAE
operator|=
name|AccessCheckingSFINAE
expr_stmt|;
block|}
end_decl_stmt

begin_expr_stmt
operator|~
name|SFINAETrap
argument_list|()
block|{
name|SemaRef
operator|.
name|NumSFINAEErrors
operator|=
name|PrevSFINAEErrors
block|;
name|SemaRef
operator|.
name|InNonInstantiationSFINAEContext
operator|=
name|PrevInNonInstantiationSFINAEContext
block|;
name|SemaRef
operator|.
name|AccessCheckingSFINAE
operator|=
name|PrevAccessCheckingSFINAE
block|;     }
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
end_expr_stmt

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

begin_typedef
typedef|typedef
name|llvm
operator|::
name|DenseMap
operator|<
name|IdentifierInfo
operator|*
operator|,
name|std
operator|::
name|pair
operator|<
name|llvm
operator|::
name|StringRef
operator|,
name|bool
operator|>
expr|>
name|UnqualifiedTyposCorrectedMap
expr_stmt|;
end_typedef

begin_comment
comment|/// \brief A cache containing the results of typo correction for unqualified
end_comment

begin_comment
comment|/// name lookup.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// The string is the string that we corrected to (which may be empty, if
end_comment

begin_comment
comment|/// there was no correction), while the boolean will be true when the
end_comment

begin_comment
comment|/// string represents a keyword.
end_comment

begin_decl_stmt
name|UnqualifiedTyposCorrectedMap
name|UnqualifiedTyposCorrected
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
name|PendingInstantiations
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
name|bool
name|PerformPendingInstantiations
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
name|SubstType
parameter_list|(
name|TypeLoc
name|TL
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

begin_decl_stmt
name|ParmVarDecl
modifier|*
name|SubstParmVarDecl
argument_list|(
name|ParmVarDecl
operator|*
name|D
argument_list|,
specifier|const
name|MultiLevelTemplateArgumentList
operator|&
name|TemplateArgs
argument_list|,
name|int
name|indexAdjustment
argument_list|,
name|llvm
operator|::
name|Optional
operator|<
name|unsigned
operator|>
name|NumExpansions
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|bool
name|SubstParmTypes
argument_list|(
name|SourceLocation
name|Loc
argument_list|,
name|ParmVarDecl
operator|*
operator|*
name|Params
argument_list|,
name|unsigned
name|NumParams
argument_list|,
specifier|const
name|MultiLevelTemplateArgumentList
operator|&
name|TemplateArgs
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
name|llvm
operator|::
name|SmallVectorImpl
operator|<
name|ParmVarDecl
operator|*
operator|>
operator|*
name|OutParams
operator|=
literal|0
argument_list|)
decl_stmt|;
end_decl_stmt

begin_function_decl
name|ExprResult
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

begin_comment
comment|/// \brief Substitute the given template arguments into a list of
end_comment

begin_comment
comment|/// expressions, expanding pack expansions if required.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param Exprs The list of expressions to substitute into.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param NumExprs The number of expressions in \p Exprs.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param IsCall Whether this is some form of call, in which case
end_comment

begin_comment
comment|/// default arguments will be dropped.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param TemplateArgs The set of template arguments to substitute.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param Outputs Will receive all of the substituted arguments.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \returns true if an error occurred, false otherwise.
end_comment

begin_decl_stmt
name|bool
name|SubstExprs
argument_list|(
name|Expr
operator|*
operator|*
name|Exprs
argument_list|,
name|unsigned
name|NumExprs
argument_list|,
name|bool
name|IsCall
argument_list|,
specifier|const
name|MultiLevelTemplateArgumentList
operator|&
name|TemplateArgs
argument_list|,
name|llvm
operator|::
name|SmallVectorImpl
operator|<
name|Expr
operator|*
operator|>
operator|&
name|Outputs
argument_list|)
decl_stmt|;
end_decl_stmt

begin_function_decl
name|StmtResult
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
name|void
name|InstantiateAttrs
parameter_list|(
specifier|const
name|MultiLevelTemplateArgumentList
modifier|&
name|TemplateArgs
parameter_list|,
name|Decl
modifier|*
name|Pattern
parameter_list|,
name|Decl
modifier|*
name|Inst
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
name|NestedNameSpecifierLoc
name|SubstNestedNameSpecifierLoc
parameter_list|(
name|NestedNameSpecifierLoc
name|NNS
parameter_list|,
specifier|const
name|MultiLevelTemplateArgumentList
modifier|&
name|TemplateArgs
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|DeclarationNameInfo
name|SubstDeclarationNameInfo
parameter_list|(
specifier|const
name|DeclarationNameInfo
modifier|&
name|NameInfo
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
name|NestedNameSpecifierLoc
name|QualifierLoc
parameter_list|,
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
modifier|*
name|Args
parameter_list|,
name|unsigned
name|NumArgs
parameter_list|,
name|TemplateArgumentListInfo
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
name|Decl
modifier|*
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
name|Decl
modifier|*
specifier|const
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
name|Decl
modifier|*
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
name|Decl
modifier|*
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
name|Decl
modifier|*
specifier|const
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
name|Decl
modifier|*
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
name|Decl
modifier|*
specifier|const
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
name|Decl
modifier|*
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
name|Decl
modifier|*
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
name|Decl
modifier|*
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
name|Decl
modifier|*
name|ActOnForwardProtocolDeclaration
parameter_list|(
name|SourceLocation
name|AtProtoclLoc
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
name|Decl
operator|*
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
name|Decl
modifier|*
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

begin_comment
comment|/// Process the specified property declaration and create decls for the
end_comment

begin_comment
comment|/// setters and getters as needed.
end_comment

begin_comment
comment|/// \param property The property declaration being processed
end_comment

begin_comment
comment|/// \param DC The semantic container for the property
end_comment

begin_comment
comment|/// \param redeclaredProperty Declaration for property if redeclared
end_comment

begin_comment
comment|///        in class extension.
end_comment

begin_comment
comment|/// \param lexicalDC Container for redeclaredProperty.
end_comment

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
parameter_list|,
name|ObjCPropertyDecl
modifier|*
name|redeclaredProperty
init|=
literal|0
parameter_list|,
name|ObjCContainerDecl
modifier|*
name|lexicalDC
init|=
literal|0
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
name|Decl
modifier|*
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
name|Decl
modifier|*
name|classDecl
parameter_list|,
name|Decl
modifier|*
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
name|Decl
modifier|*
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
name|Decl
modifier|*
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
name|Decl
operator|*
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
argument_list|,
name|DeclContext
operator|*
name|lexicalDC
operator|=
literal|0
argument_list|)
decl_stmt|;
end_decl_stmt

begin_function_decl
name|Decl
modifier|*
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
name|Decl
modifier|*
name|ClassImplDecl
parameter_list|,
name|IdentifierInfo
modifier|*
name|PropertyId
parameter_list|,
name|IdentifierInfo
modifier|*
name|PropertyIvar
parameter_list|,
name|SourceLocation
name|PropertyIvarLoc
parameter_list|)
function_decl|;
end_function_decl

begin_struct
struct|struct
name|ObjCArgInfo
block|{
name|IdentifierInfo
modifier|*
name|Name
decl_stmt|;
name|SourceLocation
name|NameLoc
decl_stmt|;
comment|// The Type is null if no type was specified, and the DeclSpec is invalid
comment|// in this case.
name|ParsedType
name|Type
decl_stmt|;
name|ObjCDeclSpec
name|DeclSpec
decl_stmt|;
comment|/// ArgAttrs - Attribute list for this argument.
name|AttributeList
modifier|*
name|ArgAttrs
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
name|Decl
modifier|*
name|ActOnMethodDeclaration
argument_list|(
name|Scope
operator|*
name|S
argument_list|,
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
name|Decl
operator|*
name|ClassDecl
argument_list|,
name|ObjCDeclSpec
operator|&
name|ReturnQT
argument_list|,
name|ParsedType
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
argument_list|,
name|bool
name|MethodDefinition
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
name|ObjCMethodDecl
modifier|*
name|LookupMethodInQualifiedType
parameter_list|(
name|Selector
name|Sel
parameter_list|,
specifier|const
name|ObjCObjectPointerType
modifier|*
name|OPT
parameter_list|,
name|bool
name|IsInstance
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ExprResult
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
parameter_list|,
name|SourceLocation
name|SuperLoc
parameter_list|,
name|QualType
name|SuperType
parameter_list|,
name|bool
name|Super
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ExprResult
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
name|ObjCMethodDecl
modifier|*
name|tryCaptureObjCSelf
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/// \brief Describes the kind of message expression indicated by a message
end_comment

begin_comment
comment|/// send that starts with an identifier.
end_comment

begin_enum
enum|enum
name|ObjCMessageKind
block|{
comment|/// \brief The message is sent to 'super'.
name|ObjCSuperMessage
block|,
comment|/// \brief The message is an instance message.
name|ObjCInstanceMessage
block|,
comment|/// \brief The message is a class message, and the identifier is a type
comment|/// name.
name|ObjCClassMessage
block|}
enum|;
end_enum

begin_function_decl
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
name|ParsedType
modifier|&
name|ReceiverType
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ExprResult
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
name|ExprResult
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
name|ExprResult
name|ActOnClassMessage
parameter_list|(
name|Scope
modifier|*
name|S
parameter_list|,
name|ParsedType
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
name|ExprResult
name|BuildInstanceMessage
parameter_list|(
name|Expr
modifier|*
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
name|ExprResult
name|ActOnInstanceMessage
parameter_list|(
name|Scope
modifier|*
name|S
parameter_list|,
name|Expr
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

begin_enum
enum|enum
name|PragmaOptionsAlignKind
block|{
name|POAK_Native
block|,
comment|// #pragma options align=native
name|POAK_Natural
block|,
comment|// #pragma options align=natural
name|POAK_Packed
block|,
comment|// #pragma options align=packed
name|POAK_Power
block|,
comment|// #pragma options align=power
name|POAK_Mac68k
block|,
comment|// #pragma options align=mac68k
name|POAK_Reset
comment|// #pragma options align=reset
block|}
enum|;
end_enum

begin_comment
comment|/// ActOnPragmaOptionsAlign - Called on well formed #pragma options align.
end_comment

begin_function_decl
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

begin_enum
enum|enum
name|PragmaPackKind
block|{
name|PPK_Default
block|,
comment|// #pragma pack([n])
name|PPK_Show
block|,
comment|// #pragma pack(show), only supported by MSVC.
name|PPK_Push
block|,
comment|// #pragma pack(push, [identifier], [n])
name|PPK_Pop
comment|// #pragma pack(pop, [identifier], [n])
block|}
enum|;
end_enum

begin_enum
enum|enum
name|PragmaMSStructKind
block|{
name|PMSST_OFF
block|,
comment|// #pragms ms_struct off
name|PMSST_ON
comment|// #pragms ms_struct on
block|}
enum|;
end_enum

begin_comment
comment|/// ActOnPragmaPack - Called on well formed #pragma pack(...).
end_comment

begin_function_decl
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
name|Expr
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
comment|/// ActOnPragmaMSStruct - Called on well formed #pragms ms_struct [on|off].
end_comment

begin_function_decl
name|void
name|ActOnPragmaMSStruct
parameter_list|(
name|PragmaMSStructKind
name|Kind
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// ActOnPragmaUnused - Called on well-formed '#pragma unused'.
end_comment

begin_function_decl
name|void
name|ActOnPragmaUnused
parameter_list|(
specifier|const
name|Token
modifier|&
name|Identifier
parameter_list|,
name|Scope
modifier|*
name|curScope
parameter_list|,
name|SourceLocation
name|PragmaLoc
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// ActOnPragmaVisibility - Called on well formed #pragma GCC visibility... .
end_comment

begin_function_decl
name|void
name|ActOnPragmaVisibility
parameter_list|(
name|bool
name|IsPush
parameter_list|,
specifier|const
name|IdentifierInfo
modifier|*
name|VisType
parameter_list|,
name|SourceLocation
name|PragmaLoc
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
comment|/// ActOnPragmaFPContract - Called on well formed
end_comment

begin_comment
comment|/// #pragma {STDC,OPENCL} FP_CONTRACT
end_comment

begin_decl_stmt
name|void
name|ActOnPragmaFPContract
argument_list|(
name|tok
operator|::
name|OnOffSwitch
name|OOS
argument_list|)
decl_stmt|;
end_decl_stmt

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
comment|/// AddMsStructLayoutForRecord - Adds ms_struct layout attribute to record.
end_comment

begin_function_decl
name|void
name|AddMsStructLayoutForRecord
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
comment|/// PushNamespaceVisibilityAttr - Note that we've entered a
end_comment

begin_comment
comment|/// namespace with a visibility attribute.
end_comment

begin_function_decl
name|void
name|PushNamespaceVisibilityAttr
parameter_list|(
specifier|const
name|VisibilityAttr
modifier|*
name|Attr
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// AddPushedVisibilityAttribute - If '#pragma GCC visibility' was used,
end_comment

begin_comment
comment|/// add an appropriate visibility attribute.
end_comment

begin_function_decl
name|void
name|AddPushedVisibilityAttribute
parameter_list|(
name|Decl
modifier|*
name|RD
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// PopPragmaVisibility - Pop the top element of the visibility stack; used
end_comment

begin_comment
comment|/// for '#pragma GCC visibility' and visibility attributes on namespaces.
end_comment

begin_function_decl
name|void
name|PopPragmaVisibility
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/// FreeVisContext - Deallocate and null out VisContext.
end_comment

begin_function_decl
name|void
name|FreeVisContext
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
name|TypeSourceInfo
modifier|*
name|T
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// CastCategory - Get the correct forwarded implicit cast result category
end_comment

begin_comment
comment|/// from the inner expression.
end_comment

begin_function_decl
name|ExprValueKind
name|CastCategory
parameter_list|(
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

begin_function_decl
name|ExprResult
name|ImpCastExprToType
parameter_list|(
name|Expr
modifier|*
name|E
parameter_list|,
name|QualType
name|Type
parameter_list|,
name|CastKind
name|CK
parameter_list|,
name|ExprValueKind
name|VK
init|=
name|VK_RValue
parameter_list|,
specifier|const
name|CXXCastPath
modifier|*
name|BasePath
init|=
literal|0
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// ScalarTypeToBooleanCastKind - Returns the cast kind corresponding
end_comment

begin_comment
comment|/// to the conversion from scalar type ScalarTy to the Boolean type.
end_comment

begin_function_decl
specifier|static
name|CastKind
name|ScalarTypeToBooleanCastKind
parameter_list|(
name|QualType
name|ScalarTy
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// IgnoredValueConversions - Given that an expression's result is
end_comment

begin_comment
comment|/// syntactically ignored, perform any conversions that are
end_comment

begin_comment
comment|/// required.
end_comment

begin_function_decl
name|ExprResult
name|IgnoredValueConversions
parameter_list|(
name|Expr
modifier|*
name|E
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|// UsualUnaryConversions - promotes integers (C99 6.3.1.1p2) and converts
end_comment

begin_comment
comment|// functions and arrays to their respective pointers (C99 6.3.2.1).
end_comment

begin_function_decl
name|ExprResult
name|UsualUnaryConversions
parameter_list|(
name|Expr
modifier|*
name|E
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
name|ExprResult
name|DefaultFunctionArrayConversion
parameter_list|(
name|Expr
modifier|*
name|E
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
name|ExprResult
name|DefaultFunctionArrayLvalueConversion
parameter_list|(
name|Expr
modifier|*
name|E
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|// DefaultLvalueConversion - performs lvalue-to-rvalue conversion on
end_comment

begin_comment
comment|// the operand.  This is DefaultFunctionArrayLvalueConversion,
end_comment

begin_comment
comment|// except that it assumes the operand isn't of function or array
end_comment

begin_comment
comment|// type.
end_comment

begin_function_decl
name|ExprResult
name|DefaultLvalueConversion
parameter_list|(
name|Expr
modifier|*
name|E
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
name|ExprResult
name|DefaultArgumentPromotion
parameter_list|(
name|Expr
modifier|*
name|E
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
name|ExprResult
name|DefaultVariadicArgumentPromotion
parameter_list|(
name|Expr
modifier|*
name|E
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
name|ExprResult
modifier|&
name|lExpr
parameter_list|,
name|ExprResult
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
comment|/// IncompatiblePointerDiscardsQualifiers - The assignment
comment|/// discards qualifiers that we don't permit to be discarded,
comment|/// like address spaces.
name|IncompatiblePointerDiscardsQualifiers
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
comment|/// C99 6.5.16.
end_comment

begin_function_decl
name|AssignConvertType
name|CheckAssignmentConstraints
parameter_list|(
name|SourceLocation
name|Loc
parameter_list|,
name|QualType
name|lhs
parameter_list|,
name|QualType
name|rhs
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// Check assignment constraints and prepare for a conversion of the
end_comment

begin_comment
comment|/// RHS to the LHS type.
end_comment

begin_function_decl
name|AssignConvertType
name|CheckAssignmentConstraints
parameter_list|(
name|QualType
name|lhs
parameter_list|,
name|ExprResult
modifier|&
name|rhs
parameter_list|,
name|CastKind
modifier|&
name|Kind
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
name|ExprResult
modifier|&
name|rExprRes
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
name|ExprResult
modifier|&
name|rExpr
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
name|ExprResult
name|PerformImplicitConversion
parameter_list|(
name|Expr
modifier|*
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
name|ExprResult
name|PerformImplicitConversion
parameter_list|(
name|Expr
modifier|*
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
name|ExprResult
name|PerformImplicitConversion
parameter_list|(
name|Expr
modifier|*
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
name|CStyle
init|=
name|false
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ExprResult
name|PerformImplicitConversion
parameter_list|(
name|Expr
modifier|*
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
name|CStyle
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
name|ExprResult
modifier|&
name|lex
parameter_list|,
name|ExprResult
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
name|ExprResult
modifier|&
name|lex
parameter_list|,
name|ExprResult
modifier|&
name|rex
parameter_list|,
name|ExprValueKind
modifier|&
name|VK
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
name|ExprResult
modifier|&
name|lex
parameter_list|,
name|ExprResult
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
name|ExprResult
modifier|&
name|lex
parameter_list|,
name|ExprResult
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
name|ExprResult
modifier|&
name|lex
parameter_list|,
name|ExprResult
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
name|ExprResult
modifier|&
name|lex
parameter_list|,
name|ExprResult
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
name|ExprResult
modifier|&
name|lex
parameter_list|,
name|ExprResult
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
name|ExprResult
modifier|&
name|lex
parameter_list|,
name|ExprResult
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
name|ExprResult
modifier|&
name|lex
parameter_list|,
name|ExprResult
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
name|ExprResult
modifier|&
name|lex
parameter_list|,
name|ExprResult
modifier|&
name|rex
parameter_list|,
name|SourceLocation
name|OpLoc
parameter_list|,
name|unsigned
name|Opc
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
name|ExprResult
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
name|void
name|ConvertPropertyForLValue
parameter_list|(
name|ExprResult
modifier|&
name|LHS
parameter_list|,
name|ExprResult
modifier|&
name|RHS
parameter_list|,
name|QualType
modifier|&
name|LHSTy
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ExprResult
name|ConvertPropertyForRValue
parameter_list|(
name|Expr
modifier|*
name|E
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|QualType
name|CheckConditionalOperands
parameter_list|(
comment|// C99 6.5.15
name|ExprResult
modifier|&
name|cond
parameter_list|,
name|ExprResult
modifier|&
name|lhs
parameter_list|,
name|ExprResult
modifier|&
name|rhs
parameter_list|,
name|ExprValueKind
modifier|&
name|VK
parameter_list|,
name|ExprObjectKind
modifier|&
name|OK
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
name|ExprResult
modifier|&
name|cond
parameter_list|,
name|ExprResult
modifier|&
name|lhs
parameter_list|,
name|ExprResult
modifier|&
name|rhs
parameter_list|,
name|ExprValueKind
modifier|&
name|VK
parameter_list|,
name|ExprObjectKind
modifier|&
name|OK
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

begin_function
name|QualType
name|FindCompositePointerType
parameter_list|(
name|SourceLocation
name|Loc
parameter_list|,
name|ExprResult
modifier|&
name|E1
parameter_list|,
name|ExprResult
modifier|&
name|E2
parameter_list|,
name|bool
modifier|*
name|NonStandardCompositeType
init|=
literal|0
parameter_list|)
block|{
name|Expr
modifier|*
name|E1Tmp
init|=
name|E1
operator|.
name|take
argument_list|()
decl_stmt|,
modifier|*
name|E2Tmp
init|=
name|E2
operator|.
name|take
argument_list|()
decl_stmt|;
name|QualType
name|Composite
init|=
name|FindCompositePointerType
argument_list|(
name|Loc
argument_list|,
name|E1Tmp
argument_list|,
name|E2Tmp
argument_list|,
name|NonStandardCompositeType
argument_list|)
decl_stmt|;
name|E1
operator|=
name|Owned
argument_list|(
name|E1Tmp
argument_list|)
expr_stmt|;
name|E2
operator|=
name|Owned
argument_list|(
name|E2Tmp
argument_list|)
expr_stmt|;
return|return
name|Composite
return|;
block|}
end_function

begin_function_decl
name|QualType
name|FindCompositeObjCPointerType
parameter_list|(
name|ExprResult
modifier|&
name|LHS
parameter_list|,
name|ExprResult
modifier|&
name|RHS
parameter_list|,
name|SourceLocation
name|questionLoc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|DiagnoseConditionalForNull
parameter_list|(
name|Expr
modifier|*
name|LHS
parameter_list|,
name|Expr
modifier|*
name|RHS
parameter_list|,
name|SourceLocation
name|QuestionLoc
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
name|ExprResult
modifier|&
name|lex
parameter_list|,
name|ExprResult
modifier|&
name|rex
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|QualType
name|CheckVectorCompareOperands
parameter_list|(
name|ExprResult
modifier|&
name|lex
parameter_list|,
name|ExprResult
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
parameter_list|,
name|bool
modifier|&
name|ObjCConversion
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// CheckCastTypes - Check type constraints for casting between types under
end_comment

begin_comment
comment|/// C semantics, or forward to CXXCheckCStyleCast in C++.
end_comment

begin_function_decl
name|ExprResult
name|CheckCastTypes
parameter_list|(
name|SourceRange
name|TyRange
parameter_list|,
name|QualType
name|CastTy
parameter_list|,
name|Expr
modifier|*
name|CastExpr
parameter_list|,
name|CastKind
modifier|&
name|Kind
parameter_list|,
name|ExprValueKind
modifier|&
name|VK
parameter_list|,
name|CXXCastPath
modifier|&
name|BasePath
parameter_list|,
name|bool
name|FunctionalStyle
init|=
name|false
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ExprResult
name|checkUnknownAnyCast
parameter_list|(
name|SourceRange
name|TyRange
parameter_list|,
name|QualType
name|castType
parameter_list|,
name|Expr
modifier|*
name|castExpr
parameter_list|,
name|CastKind
modifier|&
name|castKind
parameter_list|,
name|ExprValueKind
modifier|&
name|valueKind
parameter_list|,
name|CXXCastPath
modifier|&
name|BasePath
parameter_list|)
function_decl|;
end_function_decl

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

begin_function_decl
name|bool
name|CheckVectorCast
parameter_list|(
name|SourceRange
name|R
parameter_list|,
name|QualType
name|VectorTy
parameter_list|,
name|QualType
name|Ty
parameter_list|,
name|CastKind
modifier|&
name|Kind
parameter_list|)
function_decl|;
end_function_decl

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
comment|// returns the cast expr
end_comment

begin_function_decl
name|ExprResult
name|CheckExtVectorCast
parameter_list|(
name|SourceRange
name|R
parameter_list|,
name|QualType
name|VectorTy
parameter_list|,
name|Expr
modifier|*
name|CastExpr
parameter_list|,
name|CastKind
modifier|&
name|Kind
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// CXXCheckCStyleCast - Check constraints of a C-style or function-style
end_comment

begin_comment
comment|/// cast under C++ semantics.
end_comment

begin_function_decl
name|ExprResult
name|CXXCheckCStyleCast
parameter_list|(
name|SourceRange
name|R
parameter_list|,
name|QualType
name|CastTy
parameter_list|,
name|ExprValueKind
modifier|&
name|VK
parameter_list|,
name|Expr
modifier|*
name|CastExpr
parameter_list|,
name|CastKind
modifier|&
name|Kind
parameter_list|,
name|CXXCastPath
modifier|&
name|BasePath
parameter_list|,
name|bool
name|FunctionalStyle
parameter_list|)
function_decl|;
end_function_decl

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
parameter_list|,
name|ExprValueKind
modifier|&
name|VK
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
name|ExprResult
name|CheckBooleanCondition
parameter_list|(
name|Expr
modifier|*
name|CondExpr
parameter_list|,
name|SourceLocation
name|Loc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ExprResult
name|ActOnBooleanCondition
parameter_list|(
name|Scope
modifier|*
name|S
parameter_list|,
name|SourceLocation
name|Loc
parameter_list|,
name|Expr
modifier|*
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
comment|/// \brief Redundant parentheses over an equality comparison can indicate
end_comment

begin_comment
comment|/// that the user intended an assignment used as condition.
end_comment

begin_function_decl
name|void
name|DiagnoseEqualityWithExtraParens
parameter_list|(
name|ParenExpr
modifier|*
name|parenE
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// CheckCXXBooleanCondition - Returns true if conversion to bool is invalid.
end_comment

begin_function_decl
name|ExprResult
name|CheckCXXBooleanCondition
parameter_list|(
name|Expr
modifier|*
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

begin_comment
comment|/// \brief Describes the context in which code completion occurs.
end_comment

begin_enum
enum|enum
name|ParserCompletionContext
block|{
comment|/// \brief Code completion occurs at top-level or namespace context.
name|PCC_Namespace
block|,
comment|/// \brief Code completion occurs within a class, struct, or union.
name|PCC_Class
block|,
comment|/// \brief Code completion occurs within an Objective-C interface, protocol,
comment|/// or category.
name|PCC_ObjCInterface
block|,
comment|/// \brief Code completion occurs within an Objective-C implementation or
comment|/// category implementation
name|PCC_ObjCImplementation
block|,
comment|/// \brief Code completion occurs within the list of instance variables
comment|/// in an Objective-C interface, protocol, category, or implementation.
name|PCC_ObjCInstanceVariableList
block|,
comment|/// \brief Code completion occurs following one or more template
comment|/// headers.
name|PCC_Template
block|,
comment|/// \brief Code completion occurs following one or more template
comment|/// headers within a class.
name|PCC_MemberTemplate
block|,
comment|/// \brief Code completion occurs within an expression.
name|PCC_Expression
block|,
comment|/// \brief Code completion occurs within a statement, which may
comment|/// also be an expression or a declaration.
name|PCC_Statement
block|,
comment|/// \brief Code completion occurs at the beginning of the
comment|/// initialization statement (or expression) in a for loop.
name|PCC_ForInit
block|,
comment|/// \brief Code completion occurs within the condition of an if,
comment|/// while, switch, or for statement.
name|PCC_Condition
block|,
comment|/// \brief Code completion occurs within the body of a function on a
comment|/// recovery path, where we do not have a specific handle on our position
comment|/// in the grammar.
name|PCC_RecoveryInFunction
block|,
comment|/// \brief Code completion occurs where only a type is permitted.
name|PCC_Type
block|,
comment|/// \brief Code completion occurs in a parenthesized expression, which
comment|/// might also be a type cast.
name|PCC_ParenthesizedExpression
block|,
comment|/// \brief Code completion occurs within a sequence of declaration
comment|/// specifiers within a function, method, or block.
name|PCC_LocalDeclarationSpecifiers
block|}
enum|;
end_enum

begin_function_decl
name|void
name|CodeCompleteOrdinaryName
parameter_list|(
name|Scope
modifier|*
name|S
parameter_list|,
name|ParserCompletionContext
name|CompletionContext
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|CodeCompleteDeclSpec
parameter_list|(
name|Scope
modifier|*
name|S
parameter_list|,
name|DeclSpec
modifier|&
name|DS
parameter_list|,
name|bool
name|AllowNonIdentifiers
parameter_list|,
name|bool
name|AllowNestedNameSpecifiers
parameter_list|)
function_decl|;
end_function_decl

begin_struct_decl
struct_decl|struct
name|CodeCompleteExpressionData
struct_decl|;
end_struct_decl

begin_function_decl
name|void
name|CodeCompleteExpression
parameter_list|(
name|Scope
modifier|*
name|S
parameter_list|,
specifier|const
name|CodeCompleteExpressionData
modifier|&
name|Data
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|CodeCompleteMemberReferenceExpr
parameter_list|(
name|Scope
modifier|*
name|S
parameter_list|,
name|Expr
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
name|void
name|CodeCompletePostfixExpression
parameter_list|(
name|Scope
modifier|*
name|S
parameter_list|,
name|ExprResult
name|LHS
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
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
name|void
name|CodeCompleteTypeQualifiers
parameter_list|(
name|DeclSpec
modifier|&
name|DS
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
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
name|void
name|CodeCompleteCall
parameter_list|(
name|Scope
modifier|*
name|S
parameter_list|,
name|Expr
modifier|*
name|Fn
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
name|void
name|CodeCompleteInitializer
parameter_list|(
name|Scope
modifier|*
name|S
parameter_list|,
name|Decl
modifier|*
name|D
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
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
name|void
name|CodeCompleteAssignmentRHS
parameter_list|(
name|Scope
modifier|*
name|S
parameter_list|,
name|Expr
modifier|*
name|LHS
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
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
name|void
name|CodeCompleteConstructorInitializer
parameter_list|(
name|Decl
modifier|*
name|Constructor
parameter_list|,
name|CXXCtorInitializer
modifier|*
modifier|*
name|Initializers
parameter_list|,
name|unsigned
name|NumInitializers
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|CodeCompleteObjCAtDirective
parameter_list|(
name|Scope
modifier|*
name|S
parameter_list|,
name|Decl
modifier|*
name|ObjCImpDecl
parameter_list|,
name|bool
name|InInterface
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
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
name|void
name|CodeCompleteObjCPropertyGetter
parameter_list|(
name|Scope
modifier|*
name|S
parameter_list|,
name|Decl
modifier|*
name|ClassDecl
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|CodeCompleteObjCPropertySetter
parameter_list|(
name|Scope
modifier|*
name|S
parameter_list|,
name|Decl
modifier|*
name|ClassDecl
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|CodeCompleteObjCPassingType
parameter_list|(
name|Scope
modifier|*
name|S
parameter_list|,
name|ObjCDeclSpec
modifier|&
name|DS
parameter_list|,
name|bool
name|IsParameter
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
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
parameter_list|,
name|bool
name|AtArgumentExpression
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|CodeCompleteObjCClassMessage
parameter_list|(
name|Scope
modifier|*
name|S
parameter_list|,
name|ParsedType
name|Receiver
parameter_list|,
name|IdentifierInfo
modifier|*
modifier|*
name|SelIdents
parameter_list|,
name|unsigned
name|NumSelIdents
parameter_list|,
name|bool
name|AtArgumentExpression
parameter_list|,
name|bool
name|IsSuper
init|=
name|false
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
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
parameter_list|,
name|bool
name|AtArgumentExpression
parameter_list|,
name|ObjCInterfaceDecl
modifier|*
name|Super
init|=
literal|0
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|CodeCompleteObjCForCollection
parameter_list|(
name|Scope
modifier|*
name|S
parameter_list|,
name|DeclGroupPtrTy
name|IterationVar
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|CodeCompleteObjCSelector
parameter_list|(
name|Scope
modifier|*
name|S
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
name|void
name|CodeCompleteObjCPropertyDefinition
parameter_list|(
name|Scope
modifier|*
name|S
parameter_list|,
name|Decl
modifier|*
name|ObjCImpDecl
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
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
name|Decl
modifier|*
name|ObjCImpDecl
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
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
name|ParsedType
name|ReturnType
parameter_list|,
name|Decl
modifier|*
name|IDecl
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
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
name|ParsedType
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

begin_function_decl
name|void
name|CodeCompletePreprocessorDirective
parameter_list|(
name|bool
name|InConditional
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|CodeCompleteInPreprocessorConditionalExclusion
parameter_list|(
name|Scope
modifier|*
name|S
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|CodeCompletePreprocessorMacroName
parameter_list|(
name|bool
name|IsDefinition
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|CodeCompletePreprocessorExpression
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|CodeCompletePreprocessorMacroArgument
parameter_list|(
name|Scope
modifier|*
name|S
parameter_list|,
name|IdentifierInfo
modifier|*
name|Macro
parameter_list|,
name|MacroInfo
modifier|*
name|MacroInfo
parameter_list|,
name|unsigned
name|Argument
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|CodeCompleteNaturalLanguage
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
name|void
name|GatherGlobalCodeCompletions
argument_list|(
name|CodeCompletionAllocator
operator|&
name|Allocator
argument_list|,
name|llvm
operator|::
name|SmallVectorImpl
operator|<
name|CodeCompletionResult
operator|>
operator|&
name|Results
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|//@}
end_comment

begin_expr_stmt
name|void
name|PrintStats
argument_list|()
specifier|const
block|{}
comment|//===--------------------------------------------------------------------===//
comment|// Extra semantic analysis beyond the C type system
name|public
operator|:
name|SourceLocation
name|getLocationOfStringLiteralByte
argument_list|(
argument|const StringLiteral *SL
argument_list|,
argument|unsigned ByteNo
argument_list|)
specifier|const
expr_stmt|;
end_expr_stmt

begin_label
name|private
label|:
end_label

begin_function_decl
name|void
name|CheckArrayAccess
parameter_list|(
specifier|const
name|Expr
modifier|*
name|E
parameter_list|)
function_decl|;
end_function_decl

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

begin_function_decl
name|ExprResult
name|CheckBuiltinFunctionCall
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

begin_function_decl
name|ExprResult
name|SemaBuiltinShuffleVector
parameter_list|(
name|CallExpr
modifier|*
name|TheCall
parameter_list|)
function_decl|;
end_function_decl

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
name|ExprResult
name|SemaBuiltinAtomicOverloaded
parameter_list|(
name|ExprResult
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
parameter_list|,
name|bool
name|isPrintf
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|CheckFormatString
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
parameter_list|,
name|bool
name|isPrintf
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
name|Expr
modifier|*
specifier|const
modifier|*
name|ExprArgs
parameter_list|,
name|SourceLocation
name|CallSiteLoc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|CheckPrintfScanfArguments
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
parameter_list|,
name|bool
name|isPrintf
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|CheckMemsetArguments
parameter_list|(
specifier|const
name|CallExpr
modifier|*
name|Call
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
parameter_list|,
name|SourceLocation
name|CC
init|=
name|SourceLocation
argument_list|()
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|CheckBitFieldInitialization
parameter_list|(
name|SourceLocation
name|InitLoc
parameter_list|,
name|FieldDecl
modifier|*
name|Field
parameter_list|,
name|Expr
modifier|*
name|Init
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// \brief The parser's current scope.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// The parser maintains this state here.
end_comment

begin_decl_stmt
name|Scope
modifier|*
name|CurScope
decl_stmt|;
end_decl_stmt

begin_label
name|protected
label|:
end_label

begin_decl_stmt
name|friend
name|class
name|Parser
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|friend
name|class
name|InitializationSequence
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// \brief Retrieve the parser's current scope.
end_comment

begin_expr_stmt
name|Scope
operator|*
name|getCurScope
argument_list|()
specifier|const
block|{
return|return
name|CurScope
return|;
block|}
end_expr_stmt

begin_comment
unit|};
comment|/// \brief RAII object that enters a new expression evaluation context.
end_comment

begin_decl_stmt
name|class
name|EnterExpressionEvaluationContext
block|{
name|Sema
modifier|&
name|Actions
decl_stmt|;
name|public
label|:
name|EnterExpressionEvaluationContext
argument_list|(
argument|Sema&Actions
argument_list|,
argument|Sema::ExpressionEvaluationContext NewContext
argument_list|)
block|:
name|Actions
argument_list|(
argument|Actions
argument_list|)
block|{
name|Actions
operator|.
name|PushExpressionEvaluationContext
argument_list|(
name|NewContext
argument_list|)
expr_stmt|;
block|}
operator|~
name|EnterExpressionEvaluationContext
argument_list|()
block|{
name|Actions
operator|.
name|PopExpressionEvaluationContext
argument_list|()
block|;   }
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
unit|}
comment|// end namespace clang
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

