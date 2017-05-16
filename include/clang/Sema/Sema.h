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
file|"clang/AST/Attr.h"
end_include

begin_include
include|#
directive|include
file|"clang/AST/Availability.h"
end_include

begin_include
include|#
directive|include
file|"clang/AST/DeclarationName.h"
end_include

begin_include
include|#
directive|include
file|"clang/AST/DeclTemplate.h"
end_include

begin_include
include|#
directive|include
file|"clang/AST/Expr.h"
end_include

begin_include
include|#
directive|include
file|"clang/AST/ExprObjC.h"
end_include

begin_include
include|#
directive|include
file|"clang/AST/ExternalASTSource.h"
end_include

begin_include
include|#
directive|include
file|"clang/AST/LocInfoType.h"
end_include

begin_include
include|#
directive|include
file|"clang/AST/MangleNumberingContext.h"
end_include

begin_include
include|#
directive|include
file|"clang/AST/NSAPI.h"
end_include

begin_include
include|#
directive|include
file|"clang/AST/PrettyPrinter.h"
end_include

begin_include
include|#
directive|include
file|"clang/AST/StmtCXX.h"
end_include

begin_include
include|#
directive|include
file|"clang/AST/TypeLoc.h"
end_include

begin_include
include|#
directive|include
file|"clang/AST/TypeOrdering.h"
end_include

begin_include
include|#
directive|include
file|"clang/Basic/ExpressionTraits.h"
end_include

begin_include
include|#
directive|include
file|"clang/Basic/LangOptions.h"
end_include

begin_include
include|#
directive|include
file|"clang/Basic/Module.h"
end_include

begin_include
include|#
directive|include
file|"clang/Basic/OpenMPKinds.h"
end_include

begin_include
include|#
directive|include
file|"clang/Basic/PragmaKinds.h"
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
file|"clang/Sema/AnalysisBasedWarnings.h"
end_include

begin_include
include|#
directive|include
file|"clang/Sema/CleanupInfo.h"
end_include

begin_include
include|#
directive|include
file|"clang/Sema/DeclSpec.h"
end_include

begin_include
include|#
directive|include
file|"clang/Sema/ExternalSemaSource.h"
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
file|"clang/Sema/Ownership.h"
end_include

begin_include
include|#
directive|include
file|"clang/Sema/Scope.h"
end_include

begin_include
include|#
directive|include
file|"clang/Sema/ScopeInfo.h"
end_include

begin_include
include|#
directive|include
file|"clang/Sema/TypoCorrection.h"
end_include

begin_include
include|#
directive|include
file|"clang/Sema/Weak.h"
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
file|"llvm/ADT/SetVector.h"
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
file|"llvm/ADT/TinyPtrVector.h"
end_include

begin_include
include|#
directive|include
file|<deque>
end_include

begin_include
include|#
directive|include
file|<memory>
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
name|class
name|SmallBitVector
decl_stmt|;
name|class
name|InlineAsmIdentifierInfo
decl_stmt|;
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
name|ASTReader
decl_stmt|;
name|class
name|ASTWriter
decl_stmt|;
name|class
name|ArrayType
decl_stmt|;
name|class
name|AttributeList
decl_stmt|;
name|class
name|BindingDecl
decl_stmt|;
name|class
name|BlockDecl
decl_stmt|;
name|class
name|CapturedDecl
decl_stmt|;
name|class
name|CXXBasePath
decl_stmt|;
name|class
name|CXXBasePaths
decl_stmt|;
name|class
name|CXXBindTemporaryExpr
decl_stmt|;
typedef|typedef
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
name|CXXDeleteExpr
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
name|VarTemplatePartialSpecializationDecl
decl_stmt|;
name|class
name|CodeCompleteConsumer
decl_stmt|;
name|class
name|CodeCompletionAllocator
decl_stmt|;
name|class
name|CodeCompletionTUInfo
decl_stmt|;
name|class
name|CodeCompletionResult
decl_stmt|;
name|class
name|CoroutineBodyStmt
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
name|EnableIfAttr
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
typedef|typedef
name|MutableArrayRef
operator|<
name|ImplicitConversionSequence
operator|>
name|ConversionSequenceList
expr_stmt|;
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
name|LambdaExpr
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
typedef|typedef
name|ArrayRef
operator|<
name|std
operator|::
name|pair
operator|<
name|IdentifierInfo
operator|*
operator|,
name|SourceLocation
operator|>>
name|ModuleIdPath
expr_stmt|;
name|class
name|ModuleLoader
decl_stmt|;
name|class
name|MultiLevelTemplateArgumentList
decl_stmt|;
name|class
name|NamedDecl
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
name|ObjCMessageExpr
decl_stmt|;
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
name|OMPThreadPrivateDecl
decl_stmt|;
name|class
name|OMPDeclareReductionDecl
decl_stmt|;
name|class
name|OMPDeclareSimdDecl
decl_stmt|;
name|class
name|OMPClause
decl_stmt|;
struct_decl|struct
name|OverloadCandidate
struct_decl|;
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
name|PseudoObjectExpr
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
name|TypoCorrectionConsumer
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
name|VarTemplateSpecializationDecl
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
struct_decl|struct
name|DeductionFailureInfo
struct_decl|;
name|class
name|TemplateSpecCandidateSet
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
name|CapturedRegionScopeInfo
decl_stmt|;
name|class
name|CapturingScopeInfo
decl_stmt|;
name|class
name|CompoundScopeInfo
decl_stmt|;
name|class
name|DelayedDiagnostic
decl_stmt|;
name|class
name|DelayedDiagnosticPool
decl_stmt|;
name|class
name|FunctionScopeInfo
decl_stmt|;
name|class
name|LambdaScopeInfo
decl_stmt|;
name|class
name|PossiblyUnreachableDiag
decl_stmt|;
name|class
name|TemplateDeductionInfo
decl_stmt|;
block|}
name|namespace
name|threadSafety
block|{
name|class
name|BeforeSet
decl_stmt|;
name|void
name|threadSafetyCleanup
parameter_list|(
name|BeforeSet
modifier|*
name|Cache
parameter_list|)
function_decl|;
block|}
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
comment|/// Describes whether we've seen any nullability information for the given
comment|/// file.
struct|struct
name|FileNullability
block|{
comment|/// The first pointer declarator (of any pointer kind) in the file that does
comment|/// not have a corresponding nullability annotation.
name|SourceLocation
name|PointerLoc
decl_stmt|;
comment|/// Which kind of pointer declarator we saw.
name|uint8_t
name|PointerKind
decl_stmt|;
comment|/// Whether we saw any type nullability annotations in the given file.
name|bool
name|SawTypeNullability
init|=
name|false
decl_stmt|;
block|}
struct|;
comment|/// A mapping from file IDs to a record of whether we've seen nullability
comment|/// information in that file.
name|class
name|FileNullabilityMap
block|{
comment|/// A mapping from file IDs to the nullability information for each file ID.
name|llvm
operator|::
name|DenseMap
operator|<
name|FileID
operator|,
name|FileNullability
operator|>
name|Map
expr_stmt|;
comment|/// A single-element cache based on the file ID.
struct|struct
block|{
name|FileID
name|File
decl_stmt|;
name|FileNullability
name|Nullability
decl_stmt|;
block|}
name|Cache
struct|;
name|public
label|:
name|FileNullability
modifier|&
name|operator
function|[]
parameter_list|(
name|FileID
name|file
parameter_list|)
block|{
comment|// Check the single-element cache.
if|if
condition|(
name|file
operator|==
name|Cache
operator|.
name|File
condition|)
return|return
name|Cache
operator|.
name|Nullability
return|;
comment|// It's not in the single-element cache; flush the cache if we have one.
if|if
condition|(
operator|!
name|Cache
operator|.
name|File
operator|.
name|isInvalid
argument_list|()
condition|)
block|{
name|Map
index|[
name|Cache
operator|.
name|File
index|]
operator|=
name|Cache
operator|.
name|Nullability
expr_stmt|;
block|}
comment|// Pull this entry into the cache.
name|Cache
operator|.
name|File
operator|=
name|file
expr_stmt|;
name|Cache
operator|.
name|Nullability
operator|=
name|Map
index|[
name|file
index|]
expr_stmt|;
return|return
name|Cache
operator|.
name|Nullability
return|;
block|}
block|}
empty_stmt|;
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
operator|=
name|delete
expr_stmt|;
name|void
name|operator
init|=
operator|(
specifier|const
name|Sema
operator|&
operator|)
operator|=
name|delete
decl_stmt|;
comment|///\brief Source of additional semantic information.
name|ExternalSemaSource
modifier|*
name|ExternalSource
decl_stmt|;
comment|///\brief Whether Sema has generated a multiplexer and has to delete it.
name|bool
name|isMultiplexExternalSource
decl_stmt|;
specifier|static
name|bool
name|mightHaveNonExternalLinkage
parameter_list|(
specifier|const
name|DeclaratorDecl
modifier|*
name|FD
parameter_list|)
function_decl|;
name|bool
name|isVisibleSlow
parameter_list|(
specifier|const
name|NamedDecl
modifier|*
name|D
parameter_list|)
function_decl|;
name|bool
name|shouldLinkPossiblyHiddenDecl
parameter_list|(
specifier|const
name|NamedDecl
modifier|*
name|Old
parameter_list|,
specifier|const
name|NamedDecl
modifier|*
name|New
parameter_list|)
block|{
comment|// We are about to link these. It is now safe to compute the linkage of
comment|// the new decl. If the new decl has external linkage, we will
comment|// link it with the hidden decl (which also has external linkage) and
comment|// it will keep having external linkage. If it has internal linkage, we
comment|// will not link it. Since it has no previous decls, it will remain
comment|// with internal linkage.
return|return
name|isVisible
argument_list|(
name|Old
argument_list|)
operator|||
name|New
operator|->
name|isExternallyVisible
argument_list|()
return|;
block|}
name|bool
name|shouldLinkPossiblyHiddenDecl
parameter_list|(
name|LookupResult
modifier|&
name|Old
parameter_list|,
specifier|const
name|NamedDecl
modifier|*
name|New
parameter_list|)
function_decl|;
name|public
label|:
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
name|DiagnosticsEngine
modifier|&
name|Diags
decl_stmt|;
name|SourceManager
modifier|&
name|SourceMgr
decl_stmt|;
comment|/// \brief Flag indicating whether or not to collect detailed statistics.
name|bool
name|CollectStats
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
comment|/// \brief Generally null except when we temporarily switch decl contexts,
comment|/// like in \see ActOnObjCTemporaryExitContainerContext.
name|DeclContext
modifier|*
name|OriginalLexicalContext
decl_stmt|;
comment|/// VAListTagName - The declaration name corresponding to __va_list_tag.
comment|/// This is used as part of a hack to omit that class from ADL results.
name|DeclarationName
name|VAListTagName
decl_stmt|;
name|bool
name|MSStructPragmaOn
decl_stmt|;
comment|// True when \#pragma ms_struct on
comment|/// \brief Controls member pointer representation format under the MS ABI.
name|LangOptions
operator|::
name|PragmaMSPointersToMembersKind
name|MSPointerToMemberRepresentationMethod
expr_stmt|;
comment|/// Stack of active SEH __finally scopes.  Can be empty.
name|SmallVector
operator|<
name|Scope
operator|*
operator|,
literal|2
operator|>
name|CurrentSEHFinally
expr_stmt|;
comment|/// \brief Source location for newly created implicit MSInheritanceAttrs
name|SourceLocation
name|ImplicitMSInheritanceAttrLoc
decl_stmt|;
enum|enum
name|PragmaMsStackAction
block|{
name|PSK_Reset
init|=
literal|0x0
block|,
comment|// #pragma ()
name|PSK_Set
init|=
literal|0x1
block|,
comment|// #pragma (value)
name|PSK_Push
init|=
literal|0x2
block|,
comment|// #pragma (push[, id])
name|PSK_Pop
init|=
literal|0x4
block|,
comment|// #pragma (pop[, id])
name|PSK_Show
init|=
literal|0x8
block|,
comment|// #pragma (show) -- only for "pack"!
name|PSK_Push_Set
init|=
name|PSK_Push
operator||
name|PSK_Set
block|,
comment|// #pragma (push[, id], value)
name|PSK_Pop_Set
init|=
name|PSK_Pop
operator||
name|PSK_Set
block|,
comment|// #pragma (pop[, id], value)
block|}
enum|;
name|template
operator|<
name|typename
name|ValueType
operator|>
expr|struct
name|PragmaStack
block|{     struct
name|Slot
block|{
name|llvm
operator|::
name|StringRef
name|StackSlotLabel
block|;
name|ValueType
name|Value
block|;
name|SourceLocation
name|PragmaLocation
block|;
name|Slot
argument_list|(
argument|llvm::StringRef StackSlotLabel
argument_list|,
argument|ValueType Value
argument_list|,
argument|SourceLocation PragmaLocation
argument_list|)
operator|:
name|StackSlotLabel
argument_list|(
name|StackSlotLabel
argument_list|)
block|,
name|Value
argument_list|(
name|Value
argument_list|)
block|,
name|PragmaLocation
argument_list|(
argument|PragmaLocation
argument_list|)
block|{}
block|}
block|;
name|void
name|Act
argument_list|(
argument|SourceLocation PragmaLocation
argument_list|,
argument|PragmaMsStackAction Action
argument_list|,
argument|llvm::StringRef StackSlotLabel
argument_list|,
argument|ValueType Value
argument_list|)
block|;
comment|// MSVC seems to add artificial slots to #pragma stacks on entering a C++
comment|// method body to restore the stacks on exit, so it works like this:
comment|//
comment|//   struct S {
comment|//     #pragma<name>(push, InternalPragmaSlot,<current_pragma_value>)
comment|//     void Method {}
comment|//     #pragma<name>(pop, InternalPragmaSlot)
comment|//   };
comment|//
comment|// It works even with #pragma vtordisp, although MSVC doesn't support
comment|//   #pragma vtordisp(push [, id], n)
comment|// syntax.
comment|//
comment|// Push / pop a named sentinel slot.
name|void
name|SentinelAction
argument_list|(
argument|PragmaMsStackAction Action
argument_list|,
argument|StringRef Label
argument_list|)
block|{
name|assert
argument_list|(
operator|(
name|Action
operator|==
name|PSK_Push
operator|||
name|Action
operator|==
name|PSK_Pop
operator|)
operator|&&
literal|"Can only push / pop #pragma stack sentinels!"
argument_list|)
block|;
name|Act
argument_list|(
name|CurrentPragmaLocation
argument_list|,
name|Action
argument_list|,
name|Label
argument_list|,
name|CurrentValue
argument_list|)
block|;     }
comment|// Constructors.
name|explicit
name|PragmaStack
argument_list|(
specifier|const
name|ValueType
operator|&
name|Default
argument_list|)
operator|:
name|DefaultValue
argument_list|(
name|Default
argument_list|)
block|,
name|CurrentValue
argument_list|(
argument|Default
argument_list|)
block|{}
name|SmallVector
operator|<
name|Slot
block|,
literal|2
operator|>
name|Stack
block|;
name|ValueType
name|DefaultValue
block|;
comment|// Value used for PSK_Reset action.
name|ValueType
name|CurrentValue
block|;
name|SourceLocation
name|CurrentPragmaLocation
block|;   }
expr_stmt|;
comment|// FIXME: We should serialize / deserialize these if they occur in a PCH (but
comment|// we shouldn't do so if they're in a module).
comment|/// \brief Whether to insert vtordisps prior to virtual bases in the Microsoft
comment|/// C++ ABI.  Possible values are 0, 1, and 2, which mean:
comment|///
comment|/// 0: Suppress all vtordisps
comment|/// 1: Insert vtordisps in the presence of vbase overrides and non-trivial
comment|///    structors
comment|/// 2: Always insert vtordisps to support RTTI on partially constructed
comment|///    objects
name|PragmaStack
operator|<
name|MSVtorDispAttr
operator|::
name|Mode
operator|>
name|VtorDispStack
expr_stmt|;
comment|// #pragma pack.
comment|// Sentinel to represent when the stack is set to mac68k alignment.
specifier|static
specifier|const
name|unsigned
name|kMac68kAlignmentSentinel
init|=
operator|~
literal|0U
decl_stmt|;
name|PragmaStack
operator|<
name|unsigned
operator|>
name|PackStack
expr_stmt|;
comment|// Segment #pragmas.
name|PragmaStack
operator|<
name|StringLiteral
operator|*
operator|>
name|DataSegStack
expr_stmt|;
name|PragmaStack
operator|<
name|StringLiteral
operator|*
operator|>
name|BSSSegStack
expr_stmt|;
name|PragmaStack
operator|<
name|StringLiteral
operator|*
operator|>
name|ConstSegStack
expr_stmt|;
name|PragmaStack
operator|<
name|StringLiteral
operator|*
operator|>
name|CodeSegStack
expr_stmt|;
comment|// RAII object to push / pop sentinel slots for all MS #pragma stacks.
comment|// Actions should be performed only if we enter / exit a C++ method body.
name|class
name|PragmaStackSentinelRAII
block|{
name|public
label|:
name|PragmaStackSentinelRAII
argument_list|(
argument|Sema&S
argument_list|,
argument|StringRef SlotLabel
argument_list|,
argument|bool ShouldAct
argument_list|)
empty_stmt|;
operator|~
name|PragmaStackSentinelRAII
argument_list|()
expr_stmt|;
name|private
label|:
name|Sema
modifier|&
name|S
decl_stmt|;
name|StringRef
name|SlotLabel
decl_stmt|;
name|bool
name|ShouldAct
decl_stmt|;
block|}
empty_stmt|;
comment|/// A mapping that describes the nullability we've seen in each header file.
name|FileNullabilityMap
name|NullabilityMap
decl_stmt|;
comment|/// Last section used with #pragma init_seg.
name|StringLiteral
modifier|*
name|CurInitSeg
decl_stmt|;
name|SourceLocation
name|CurInitSegLoc
decl_stmt|;
comment|/// VisContext - Manages the stack for \#pragma GCC visibility.
name|void
modifier|*
name|VisContext
decl_stmt|;
comment|// Really a "PragmaVisStack*"
comment|/// \brief This represents the stack of attributes that were pushed by
comment|/// \#pragma clang attribute.
struct|struct
name|PragmaAttributeEntry
block|{
name|SourceLocation
name|Loc
decl_stmt|;
name|AttributeList
modifier|*
name|Attribute
decl_stmt|;
name|SmallVector
operator|<
name|attr
operator|::
name|SubjectMatchRule
operator|,
literal|4
operator|>
name|MatchRules
expr_stmt|;
name|bool
name|IsUsed
decl_stmt|;
block|}
struct|;
name|SmallVector
operator|<
name|PragmaAttributeEntry
operator|,
literal|2
operator|>
name|PragmaAttributeStack
expr_stmt|;
comment|/// \brief The declaration that is currently receiving an attribute from the
comment|/// #pragma attribute stack.
specifier|const
name|Decl
modifier|*
name|PragmaAttributeCurrentTargetDecl
decl_stmt|;
comment|/// \brief This represents the last location of a "#pragma clang optimize off"
comment|/// directive if such a directive has not been closed by an "on" yet. If
comment|/// optimizations are currently "on", this is set to an invalid location.
name|SourceLocation
name|OptimizeOffPragmaLocation
decl_stmt|;
comment|/// \brief Flag indicating if Sema is building a recovery call expression.
comment|///
comment|/// This flag is used to avoid building recovery call expressions
comment|/// if Sema is already doing so, which would cause infinite recursions.
name|bool
name|IsBuildingRecoveryCallExpr
decl_stmt|;
comment|/// Used to control the generation of ExprWithCleanups.
name|CleanupInfo
name|Cleanup
decl_stmt|;
comment|/// ExprCleanupObjects - This is the stack of objects requiring
comment|/// cleanup that are created by the current full expression.  The
comment|/// element type here is ExprWithCleanups::Object.
name|SmallVector
operator|<
name|BlockDecl
operator|*
operator|,
literal|8
operator|>
name|ExprCleanupObjects
expr_stmt|;
comment|/// \brief Store a list of either DeclRefExprs or MemberExprs
comment|///  that contain a reference to a variable (constant) that may or may not
comment|///  be odr-used in this Expr, and we won't know until all lvalue-to-rvalue
comment|///  and discarded value conversions have been applied to all subexpressions
comment|///  of the enclosing full expression.  This is cleared at the end of each
comment|///  full expression.
name|llvm
operator|::
name|SmallPtrSet
operator|<
name|Expr
operator|*
operator|,
literal|2
operator|>
name|MaybeODRUseExprs
expr_stmt|;
comment|/// \brief Stack containing information about each of the nested
comment|/// function, block, and method scopes that are currently active.
comment|///
comment|/// This array is never empty.  Clients should ignore the first
comment|/// element, which is used to cache a single FunctionScopeInfo
comment|/// that's used to parse every top-level function.
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
typedef|typedef
name|LazyVector
operator|<
name|TypedefNameDecl
operator|*
operator|,
name|ExternalSemaSource
operator|,
operator|&
name|ExternalSemaSource
operator|::
name|ReadExtVectorDecls
operator|,
literal|2
operator|,
literal|2
operator|>
name|ExtVectorDeclsType
expr_stmt|;
comment|/// ExtVectorDecls - This is a list all the extended vector types. This allows
comment|/// us to associate a raw vector type with one of the ext_vector type names.
comment|/// This is only necessary for issuing pretty diagnostics.
name|ExtVectorDeclsType
name|ExtVectorDecls
decl_stmt|;
comment|/// FieldCollector - Collects CXXFieldDecls during parsing of C++ classes.
name|std
operator|::
name|unique_ptr
operator|<
name|CXXFieldCollector
operator|>
name|FieldCollector
expr_stmt|;
typedef|typedef
name|llvm
operator|::
name|SmallSetVector
operator|<
specifier|const
name|NamedDecl
operator|*
operator|,
literal|16
operator|>
name|NamedDeclSetType
expr_stmt|;
comment|/// \brief Set containing all declared private fields that are not used.
name|NamedDeclSetType
name|UnusedPrivateFields
decl_stmt|;
comment|/// \brief Set containing all typedefs that are likely unused.
name|llvm
operator|::
name|SmallSetVector
operator|<
specifier|const
name|TypedefNameDecl
operator|*
operator|,
literal|4
operator|>
name|UnusedLocalTypedefNameCandidates
expr_stmt|;
comment|/// \brief Delete-expressions to be analyzed at the end of translation unit
comment|///
comment|/// This list contains class members, and locations of delete-expressions
comment|/// that could not be proven as to whether they mismatch with new-expression
comment|/// used in initializer of the field.
typedef|typedef
name|std
operator|::
name|pair
operator|<
name|SourceLocation
operator|,
name|bool
operator|>
name|DeleteExprLoc
expr_stmt|;
typedef|typedef
name|llvm
operator|::
name|SmallVector
operator|<
name|DeleteExprLoc
operator|,
literal|4
operator|>
name|DeleteLocs
expr_stmt|;
name|llvm
operator|::
name|MapVector
operator|<
name|FieldDecl
operator|*
operator|,
name|DeleteLocs
operator|>
name|DeleteExprs
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
name|std
operator|::
name|unique_ptr
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
comment|/// \brief Look for a locally scoped extern "C" declaration by the given name.
name|NamedDecl
modifier|*
name|findLocallyScopedExternCDecl
parameter_list|(
name|DeclarationName
name|Name
parameter_list|)
function_decl|;
typedef|typedef
name|LazyVector
operator|<
name|VarDecl
operator|*
operator|,
name|ExternalSemaSource
operator|,
operator|&
name|ExternalSemaSource
operator|::
name|ReadTentativeDefinitions
operator|,
literal|2
operator|,
literal|2
operator|>
name|TentativeDefinitionsType
expr_stmt|;
comment|/// \brief All the tentative definitions encountered in the TU.
name|TentativeDefinitionsType
name|TentativeDefinitions
decl_stmt|;
typedef|typedef
name|LazyVector
operator|<
specifier|const
name|DeclaratorDecl
operator|*
operator|,
name|ExternalSemaSource
operator|,
operator|&
name|ExternalSemaSource
operator|::
name|ReadUnusedFileScopedDecls
operator|,
literal|2
operator|,
literal|2
operator|>
name|UnusedFileScopedDeclsType
expr_stmt|;
comment|/// \brief The set of file scoped decls seen so far that have not been used
comment|/// and must warn if not used. Only contains the first declaration.
name|UnusedFileScopedDeclsType
name|UnusedFileScopedDecls
decl_stmt|;
typedef|typedef
name|LazyVector
operator|<
name|CXXConstructorDecl
operator|*
operator|,
name|ExternalSemaSource
operator|,
operator|&
name|ExternalSemaSource
operator|::
name|ReadDelegatingConstructors
operator|,
literal|2
operator|,
literal|2
operator|>
name|DelegatingCtorDeclsType
expr_stmt|;
comment|/// \brief All the delegating constructors seen so far in the file, used for
comment|/// cycle detection at the end of the TU.
name|DelegatingCtorDeclsType
name|DelegatingCtorDecls
decl_stmt|;
comment|/// \brief All the overriding functions seen during a class definition
comment|/// that had their exception spec checks delayed, plus the overridden
comment|/// function.
name|SmallVector
operator|<
name|std
operator|::
name|pair
operator|<
specifier|const
name|CXXMethodDecl
operator|*
operator|,
specifier|const
name|CXXMethodDecl
operator|*
operator|>
operator|,
literal|2
operator|>
name|DelayedExceptionSpecChecks
expr_stmt|;
comment|/// \brief All the members seen during a class definition which were both
comment|/// explicitly defaulted and had explicitly-specified exception
comment|/// specifications, along with the function type containing their
comment|/// user-specified exception specification. Those exception specifications
comment|/// were overridden with the default specifications, but we still need to
comment|/// check whether they are compatible with the default specification, and
comment|/// we can't do that until the nesting set of class definitions is complete.
name|SmallVector
operator|<
name|std
operator|::
name|pair
operator|<
name|CXXMethodDecl
operator|*
operator|,
specifier|const
name|FunctionProtoType
operator|*
operator|>
operator|,
literal|2
operator|>
name|DelayedDefaultedMemberExceptionSpecs
expr_stmt|;
typedef|typedef
name|llvm
operator|::
name|MapVector
operator|<
specifier|const
name|FunctionDecl
operator|*
operator|,
name|std
operator|::
name|unique_ptr
operator|<
name|LateParsedTemplate
operator|>>
name|LateParsedTemplateMapT
expr_stmt|;
name|LateParsedTemplateMapT
name|LateParsedTemplateMap
decl_stmt|;
comment|/// \brief Callback to the parser to parse templated functions when needed.
typedef|typedef
name|void
name|LateTemplateParserCB
parameter_list|(
name|void
modifier|*
name|P
parameter_list|,
name|LateParsedTemplate
modifier|&
name|LPT
parameter_list|)
function_decl|;
typedef|typedef
name|void
name|LateTemplateParserCleanupCB
parameter_list|(
name|void
modifier|*
name|P
parameter_list|)
function_decl|;
name|LateTemplateParserCB
modifier|*
name|LateTemplateParser
decl_stmt|;
name|LateTemplateParserCleanupCB
modifier|*
name|LateTemplateParserCleanup
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
name|LateTemplateParserCleanupCB
modifier|*
name|LTPCleanup
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
name|LateTemplateParserCleanup
operator|=
name|LTPCleanup
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
name|DelayedDiagnosticsState
block|{
name|sema
operator|::
name|DelayedDiagnosticPool
operator|*
name|SavedPool
expr_stmt|;
name|friend
name|class
name|Sema
operator|::
name|DelayedDiagnostics
expr_stmt|;
block|}
empty_stmt|;
typedef|typedef
name|DelayedDiagnosticsState
name|ParsingDeclState
typedef|;
typedef|typedef
name|DelayedDiagnosticsState
name|ProcessingContextState
typedef|;
comment|/// A class which encapsulates the logic for delaying diagnostics
comment|/// during parsing and other processing.
name|class
name|DelayedDiagnostics
block|{
comment|/// \brief The current pool of diagnostics into which delayed
comment|/// diagnostics should go.
name|sema
operator|::
name|DelayedDiagnosticPool
operator|*
name|CurPool
expr_stmt|;
name|public
label|:
name|DelayedDiagnostics
argument_list|()
operator|:
name|CurPool
argument_list|(
argument|nullptr
argument_list|)
block|{}
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
comment|// in DelayedDiagnostic.h
comment|/// Determines whether diagnostics should be delayed.
name|bool
name|shouldDelayDiagnostics
parameter_list|()
block|{
return|return
name|CurPool
operator|!=
name|nullptr
return|;
block|}
comment|/// Returns the current delayed-diagnostics pool.
name|sema
operator|::
name|DelayedDiagnosticPool
operator|*
name|getCurrentPool
argument_list|()
specifier|const
block|{
return|return
name|CurPool
return|;
block|}
comment|/// Enter a new scope.  Access and deprecation diagnostics will be
comment|/// collected in this pool.
name|DelayedDiagnosticsState
name|push
argument_list|(
name|sema
operator|::
name|DelayedDiagnosticPool
operator|&
name|pool
argument_list|)
block|{
name|DelayedDiagnosticsState
name|state
decl_stmt|;
name|state
operator|.
name|SavedPool
operator|=
name|CurPool
expr_stmt|;
name|CurPool
operator|=
operator|&
name|pool
expr_stmt|;
return|return
name|state
return|;
block|}
comment|/// Leave a delayed-diagnostic state that was previously pushed.
comment|/// Do not emit any of the diagnostics.  This is performed as part
comment|/// of the bookkeeping of popping a pool "properly".
name|void
name|popWithoutEmitting
parameter_list|(
name|DelayedDiagnosticsState
name|state
parameter_list|)
block|{
name|CurPool
operator|=
name|state
operator|.
name|SavedPool
expr_stmt|;
block|}
comment|/// Enter a new scope where access and deprecation diagnostics are
comment|/// not delayed.
name|DelayedDiagnosticsState
name|pushUndelayed
parameter_list|()
block|{
name|DelayedDiagnosticsState
name|state
decl_stmt|;
name|state
operator|.
name|SavedPool
operator|=
name|CurPool
expr_stmt|;
name|CurPool
operator|=
name|nullptr
expr_stmt|;
return|return
name|state
return|;
block|}
comment|/// Undo a previous pushUndelayed().
name|void
name|popUndelayed
parameter_list|(
name|DelayedDiagnosticsState
name|state
parameter_list|)
block|{
name|assert
argument_list|(
name|CurPool
operator|==
name|nullptr
argument_list|)
expr_stmt|;
name|CurPool
operator|=
name|state
operator|.
name|SavedPool
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
name|QualType
name|SavedCXXThisTypeOverride
decl_stmt|;
name|public
label|:
name|ContextRAII
argument_list|(
argument|Sema&S
argument_list|,
argument|DeclContext *ContextToPush
argument_list|,
argument|bool NewThisContext = true
argument_list|)
block|:
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
name|S
operator|.
name|DelayedDiagnostics
operator|.
name|pushUndelayed
argument_list|()
argument_list|)
operator|,
name|SavedCXXThisTypeOverride
argument_list|(
argument|S.CXXThisTypeOverride
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
block|;
if|if
condition|(
name|NewThisContext
condition|)
name|S
operator|.
name|CXXThisTypeOverride
operator|=
name|QualType
argument_list|()
expr_stmt|;
block|}
name|void
name|pop
parameter_list|()
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
name|popUndelayed
argument_list|(
name|SavedContextState
argument_list|)
expr_stmt|;
name|S
operator|.
name|CXXThisTypeOverride
operator|=
name|SavedCXXThisTypeOverride
expr_stmt|;
name|SavedContext
operator|=
name|nullptr
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
empty_stmt|;
comment|/// \brief RAII object to handle the state changes required to synthesize
comment|/// a function body.
name|class
name|SynthesizedFunctionScope
block|{
name|Sema
modifier|&
name|S
decl_stmt|;
name|Sema
operator|::
name|ContextRAII
name|SavedContext
expr_stmt|;
name|public
label|:
name|SynthesizedFunctionScope
argument_list|(
name|Sema
operator|&
name|S
argument_list|,
name|DeclContext
operator|*
name|DC
argument_list|)
operator|:
name|S
argument_list|(
name|S
argument_list|)
operator|,
name|SavedContext
argument_list|(
argument|S
argument_list|,
argument|DC
argument_list|)
block|{
name|S
operator|.
name|PushFunctionScope
argument_list|()
block|;
name|S
operator|.
name|PushExpressionEvaluationContext
argument_list|(
name|Sema
operator|::
name|ExpressionEvaluationContext
operator|::
name|PotentiallyEvaluated
argument_list|)
block|;     }
operator|~
name|SynthesizedFunctionScope
argument_list|()
block|{
name|S
operator|.
name|PopExpressionEvaluationContext
argument_list|()
block|;
name|S
operator|.
name|PopFunctionScopeInfo
argument_list|()
block|;     }
block|}
empty_stmt|;
comment|/// WeakUndeclaredIdentifiers - Identifiers contained in
comment|/// \#pragma weak before declared. rare. may alias another
comment|/// identifier, declared or undeclared
name|llvm
operator|::
name|MapVector
operator|<
name|IdentifierInfo
operator|*
operator|,
name|WeakInfo
operator|>
name|WeakUndeclaredIdentifiers
expr_stmt|;
comment|/// ExtnameUndeclaredIdentifiers - Identifiers contained in
comment|/// \#pragma redefine_extname before declared.  Used in Solaris system headers
comment|/// to define functions that occur in multiple standards to call the version
comment|/// in the currently selected standard.
name|llvm
operator|::
name|DenseMap
operator|<
name|IdentifierInfo
operator|*
operator|,
name|AsmLabelAttr
operator|*
operator|>
name|ExtnameUndeclaredIdentifiers
expr_stmt|;
comment|/// \brief Load weak undeclared identifiers from the external source.
name|void
name|LoadExternalWeakUndeclaredIdentifiers
parameter_list|()
function_decl|;
comment|/// WeakTopLevelDecl - Translation-unit scoped declarations generated by
comment|/// \#pragma weak during processing of other Decls.
comment|/// I couldn't figure out a clean way to generate these in-line, so
comment|/// we store them here and handle separately -- which is a hack.
comment|/// It would be best to refactor this.
name|SmallVector
operator|<
name|Decl
operator|*
operator|,
literal|2
operator|>
name|WeakTopLevelDecl
expr_stmt|;
name|IdentifierResolver
name|IdResolver
decl_stmt|;
comment|/// Translation Unit Scope - useful to Objective-C actions that need
comment|/// to lookup file scope declarations in the "ordinary" C decl namespace.
comment|/// For example, user-defined classes, built-in "id" type, etc.
name|Scope
modifier|*
name|TUScope
decl_stmt|;
comment|/// \brief The C++ "std" namespace, where the standard library resides.
name|LazyDeclPtr
name|StdNamespace
decl_stmt|;
comment|/// \brief The C++ "std::bad_alloc" class, which is defined by the C++
comment|/// standard library.
name|LazyDeclPtr
name|StdBadAlloc
decl_stmt|;
comment|/// \brief The C++ "std::align_val_t" enum class, which is defined by the C++
comment|/// standard library.
name|LazyDeclPtr
name|StdAlignValT
decl_stmt|;
comment|/// \brief The C++ "std::experimental" namespace, where the experimental parts
comment|/// of the standard library resides.
name|NamespaceDecl
modifier|*
name|StdExperimentalNamespaceCache
decl_stmt|;
comment|/// \brief The C++ "std::initializer_list" template, which is defined in
comment|/// \<initializer_list>.
name|ClassTemplateDecl
modifier|*
name|StdInitializerList
decl_stmt|;
comment|/// \brief The C++ "type_info" declaration, which is defined in \<typeinfo>.
name|RecordDecl
modifier|*
name|CXXTypeInfoDecl
decl_stmt|;
comment|/// \brief The MSVC "_GUID" struct, which is defined in MSVC header files.
name|RecordDecl
modifier|*
name|MSVCGuidDecl
decl_stmt|;
comment|/// \brief Caches identifiers/selectors for NSFoundation APIs.
name|std
operator|::
name|unique_ptr
operator|<
name|NSAPI
operator|>
name|NSAPIObj
expr_stmt|;
comment|/// \brief The declaration of the Objective-C NSNumber class.
name|ObjCInterfaceDecl
modifier|*
name|NSNumberDecl
decl_stmt|;
comment|/// \brief The declaration of the Objective-C NSValue class.
name|ObjCInterfaceDecl
modifier|*
name|NSValueDecl
decl_stmt|;
comment|/// \brief Pointer to NSNumber type (NSNumber *).
name|QualType
name|NSNumberPointer
decl_stmt|;
comment|/// \brief Pointer to NSValue type (NSValue *).
name|QualType
name|NSValuePointer
decl_stmt|;
comment|/// \brief The Objective-C NSNumber methods used to create NSNumber literals.
name|ObjCMethodDecl
modifier|*
name|NSNumberLiteralMethods
index|[
name|NSAPI
operator|::
name|NumNSNumberLiteralMethods
index|]
decl_stmt|;
comment|/// \brief The declaration of the Objective-C NSString class.
name|ObjCInterfaceDecl
modifier|*
name|NSStringDecl
decl_stmt|;
comment|/// \brief Pointer to NSString type (NSString *).
name|QualType
name|NSStringPointer
decl_stmt|;
comment|/// \brief The declaration of the stringWithUTF8String: method.
name|ObjCMethodDecl
modifier|*
name|StringWithUTF8StringMethod
decl_stmt|;
comment|/// \brief The declaration of the valueWithBytes:objCType: method.
name|ObjCMethodDecl
modifier|*
name|ValueWithBytesObjCTypeMethod
decl_stmt|;
comment|/// \brief The declaration of the Objective-C NSArray class.
name|ObjCInterfaceDecl
modifier|*
name|NSArrayDecl
decl_stmt|;
comment|/// \brief The declaration of the arrayWithObjects:count: method.
name|ObjCMethodDecl
modifier|*
name|ArrayWithObjectsMethod
decl_stmt|;
comment|/// \brief The declaration of the Objective-C NSDictionary class.
name|ObjCInterfaceDecl
modifier|*
name|NSDictionaryDecl
decl_stmt|;
comment|/// \brief The declaration of the dictionaryWithObjects:forKeys:count: method.
name|ObjCMethodDecl
modifier|*
name|DictionaryWithObjectsMethod
decl_stmt|;
comment|/// \brief id<NSCopying> type.
name|QualType
name|QIDNSCopying
decl_stmt|;
comment|/// \brief will hold 'respondsToSelector:'
name|Selector
name|RespondsToSelectorSel
decl_stmt|;
comment|/// A flag to remember whether the implicit forms of operator new and delete
comment|/// have been declared.
name|bool
name|GlobalNewDeleteDeclared
decl_stmt|;
comment|/// A flag to indicate that we're in a context that permits abstract
comment|/// references to fields.  This is really a
name|bool
name|AllowAbstractFieldReference
decl_stmt|;
comment|/// \brief Describes how the expressions currently being parsed are
comment|/// evaluated at run-time, if at all.
name|enum
name|class
name|ExpressionEvaluationContext
block|{
comment|/// \brief The current expression and its subexpressions occur within an
comment|/// unevaluated operand (C++11 [expr]p7), such as the subexpression of
comment|/// \c sizeof, where the type of the expression may be significant but
comment|/// no code will be generated to evaluate the value of the expression at
comment|/// run time.
name|Unevaluated
operator|,
comment|/// \brief The current expression occurs within a braced-init-list within
comment|/// an unevaluated operand. This is mostly like a regular unevaluated
comment|/// context, except that we still instantiate constexpr functions that are
comment|/// referenced here so that we can perform narrowing checks correctly.
name|UnevaluatedList
operator|,
comment|/// \brief The current expression occurs within a discarded statement.
comment|/// This behaves largely similarly to an unevaluated operand in preventing
comment|/// definitions from being required, but not in other ways.
name|DiscardedStatement
operator|,
comment|/// \brief The current expression occurs within an unevaluated
comment|/// operand that unconditionally permits abstract references to
comment|/// fields, such as a SIZE operator in MS-style inline assembly.
name|UnevaluatedAbstract
operator|,
comment|/// \brief The current context is "potentially evaluated" in C++11 terms,
comment|/// but the expression is evaluated at compile-time (like the values of
comment|/// cases in a switch statement).
name|ConstantEvaluated
operator|,
comment|/// \brief The current expression is potentially evaluated at run time,
comment|/// which means that code may be generated to evaluate the value of the
comment|/// expression at run time.
name|PotentiallyEvaluated
operator|,
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
empty_stmt|;
comment|/// \brief Data structure used to record current or nested
comment|/// expression evaluation contexts.
struct|struct
name|ExpressionEvaluationContextRecord
block|{
comment|/// \brief The expression evaluation context.
name|ExpressionEvaluationContext
name|Context
decl_stmt|;
comment|/// \brief Whether the enclosing context needed a cleanup.
name|CleanupInfo
name|ParentCleanup
decl_stmt|;
comment|/// \brief Whether we are in a decltype expression.
name|bool
name|IsDecltype
decl_stmt|;
comment|/// \brief The number of active cleanup objects when we entered
comment|/// this expression evaluation context.
name|unsigned
name|NumCleanupObjects
decl_stmt|;
comment|/// \brief The number of typos encountered during this expression evaluation
comment|/// context (i.e. the number of TypoExprs created).
name|unsigned
name|NumTypos
decl_stmt|;
name|llvm
operator|::
name|SmallPtrSet
operator|<
name|Expr
operator|*
operator|,
literal|2
operator|>
name|SavedMaybeODRUseExprs
expr_stmt|;
comment|/// \brief The lambdas that are present within this context, if it
comment|/// is indeed an unevaluated context.
name|SmallVector
operator|<
name|LambdaExpr
operator|*
operator|,
literal|2
operator|>
name|Lambdas
expr_stmt|;
comment|/// \brief The declaration that provides context for lambda expressions
comment|/// and block literals if the normal declaration context does not
comment|/// suffice, e.g., in a default function argument.
name|Decl
modifier|*
name|ManglingContextDecl
decl_stmt|;
comment|/// \brief The context information used to mangle lambda expressions
comment|/// and block literals within this context.
comment|///
comment|/// This mangling information is allocated lazily, since most contexts
comment|/// do not have lambda expressions or block literals.
name|std
operator|::
name|unique_ptr
operator|<
name|MangleNumberingContext
operator|>
name|MangleNumbering
expr_stmt|;
comment|/// \brief If we are processing a decltype type, a set of call expressions
comment|/// for which we have deferred checking the completeness of the return type.
name|SmallVector
operator|<
name|CallExpr
operator|*
operator|,
literal|8
operator|>
name|DelayedDecltypeCalls
expr_stmt|;
comment|/// \brief If we are processing a decltype type, a set of temporary binding
comment|/// expressions for which we have deferred checking the destructor.
name|SmallVector
operator|<
name|CXXBindTemporaryExpr
operator|*
operator|,
literal|8
operator|>
name|DelayedDecltypeBinds
expr_stmt|;
name|ExpressionEvaluationContextRecord
argument_list|(
argument|ExpressionEvaluationContext Context
argument_list|,
argument|unsigned NumCleanupObjects
argument_list|,
argument|CleanupInfo ParentCleanup
argument_list|,
argument|Decl *ManglingContextDecl
argument_list|,
argument|bool IsDecltype
argument_list|)
block|:
name|Context
argument_list|(
name|Context
argument_list|)
operator|,
name|ParentCleanup
argument_list|(
name|ParentCleanup
argument_list|)
operator|,
name|IsDecltype
argument_list|(
name|IsDecltype
argument_list|)
operator|,
name|NumCleanupObjects
argument_list|(
name|NumCleanupObjects
argument_list|)
operator|,
name|NumTypos
argument_list|(
literal|0
argument_list|)
operator|,
name|ManglingContextDecl
argument_list|(
name|ManglingContextDecl
argument_list|)
operator|,
name|MangleNumbering
argument_list|()
block|{ }
comment|/// \brief Retrieve the mangling numbering context, used to consistently
comment|/// number constructs like lambdas for mangling.
name|MangleNumberingContext
operator|&
name|getMangleNumberingContext
argument_list|(
name|ASTContext
operator|&
name|Ctx
argument_list|)
expr_stmt|;
name|bool
name|isUnevaluated
argument_list|()
specifier|const
block|{
return|return
name|Context
operator|==
name|ExpressionEvaluationContext
operator|::
name|Unevaluated
operator|||
name|Context
operator|==
name|ExpressionEvaluationContext
operator|::
name|UnevaluatedAbstract
operator|||
name|Context
operator|==
name|ExpressionEvaluationContext
operator|::
name|UnevaluatedList
return|;
block|}
name|bool
name|isConstantEvaluated
argument_list|()
specifier|const
block|{
return|return
name|Context
operator|==
name|ExpressionEvaluationContext
operator|::
name|ConstantEvaluated
return|;
block|}
block|}
struct|;
comment|/// A stack of expression evaluation contexts.
name|SmallVector
operator|<
name|ExpressionEvaluationContextRecord
operator|,
literal|8
operator|>
name|ExprEvalContexts
expr_stmt|;
comment|/// \brief Compute the mangling number context for a lambda expression or
comment|/// block literal.
comment|///
comment|/// \param DC - The DeclContext containing the lambda expression or
comment|/// block literal.
comment|/// \param[out] ManglingContextDecl - Returns the ManglingContextDecl
comment|/// associated with the context, if relevant.
name|MangleNumberingContext
modifier|*
name|getCurrentMangleNumberContext
parameter_list|(
specifier|const
name|DeclContext
modifier|*
name|DC
parameter_list|,
name|Decl
modifier|*
modifier|&
name|ManglingContextDecl
parameter_list|)
function_decl|;
comment|/// SpecialMemberOverloadResult - The overloading result for a special member
comment|/// function.
comment|///
comment|/// This is basically a wrapper around PointerIntPair. The lowest bits of the
comment|/// integer are used to determine whether overload resolution succeeded.
name|class
name|SpecialMemberOverloadResult
block|{
name|public
label|:
enum|enum
name|Kind
block|{
name|NoMemberOrDeleted
block|,
name|Ambiguous
block|,
name|Success
block|}
enum|;
name|private
label|:
name|llvm
operator|::
name|PointerIntPair
operator|<
name|CXXMethodDecl
operator|*
operator|,
literal|2
operator|>
name|Pair
expr_stmt|;
name|public
label|:
name|SpecialMemberOverloadResult
argument_list|()
operator|:
name|Pair
argument_list|()
block|{}
name|SpecialMemberOverloadResult
argument_list|(
name|CXXMethodDecl
operator|*
name|MD
argument_list|)
operator|:
name|Pair
argument_list|(
argument|MD
argument_list|,
argument|MD->isDeleted() ? NoMemberOrDeleted : Success
argument_list|)
block|{}
name|CXXMethodDecl
operator|*
name|getMethod
argument_list|()
specifier|const
block|{
return|return
name|Pair
operator|.
name|getPointer
argument_list|()
return|;
block|}
name|void
name|setMethod
parameter_list|(
name|CXXMethodDecl
modifier|*
name|MD
parameter_list|)
block|{
name|Pair
operator|.
name|setPointer
argument_list|(
name|MD
argument_list|)
expr_stmt|;
block|}
name|Kind
name|getKind
argument_list|()
specifier|const
block|{
return|return
name|static_cast
operator|<
name|Kind
operator|>
operator|(
name|Pair
operator|.
name|getInt
argument_list|()
operator|)
return|;
block|}
name|void
name|setKind
parameter_list|(
name|Kind
name|K
parameter_list|)
block|{
name|Pair
operator|.
name|setInt
argument_list|(
name|K
argument_list|)
expr_stmt|;
block|}
block|}
empty_stmt|;
name|class
name|SpecialMemberOverloadResultEntry
range|:
name|public
name|llvm
operator|::
name|FastFoldingSetNode
decl_stmt|,
name|public
name|SpecialMemberOverloadResult
block|{
name|public
label|:
name|SpecialMemberOverloadResultEntry
argument_list|(
specifier|const
name|llvm
operator|::
name|FoldingSetNodeID
operator|&
name|ID
argument_list|)
operator|:
name|FastFoldingSetNode
argument_list|(
argument|ID
argument_list|)
block|{}
block|}
empty_stmt|;
comment|/// \brief A cache of special member function overload resolution results
comment|/// for C++ records.
name|llvm
operator|::
name|FoldingSet
operator|<
name|SpecialMemberOverloadResultEntry
operator|>
name|SpecialMemberCache
expr_stmt|;
comment|/// \brief A cache of the flags available in enumerations with the flag_bits
comment|/// attribute.
name|mutable
name|llvm
operator|::
name|DenseMap
operator|<
specifier|const
name|EnumDecl
operator|*
operator|,
name|llvm
operator|::
name|APInt
operator|>
name|FlagBitsCache
expr_stmt|;
comment|/// \brief The kind of translation unit we are processing.
comment|///
comment|/// When we're processing a complete translation unit, Sema will perform
comment|/// end-of-translation-unit semantic tasks (such as creating
comment|/// initializers for tentative definitions in C) once parsing has
comment|/// completed. Modules and precompiled headers perform different kinds of
comment|/// checks.
name|TranslationUnitKind
name|TUKind
decl_stmt|;
name|llvm
operator|::
name|BumpPtrAllocator
name|BumpAlloc
expr_stmt|;
comment|/// \brief The number of SFINAE diagnostics that have been trapped.
name|unsigned
name|NumSFINAEErrors
decl_stmt|;
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
name|TinyPtrVector
operator|<
name|ParmVarDecl
operator|*
operator|>>
name|UnparsedDefaultArgInstantiationsMap
expr_stmt|;
comment|/// \brief A mapping from parameters with unparsed default arguments to the
comment|/// set of instantiations of each parameter.
comment|///
comment|/// This mapping is a temporary data structure used when parsing
comment|/// nested class templates or nested classes of class templates,
comment|/// where we might end up instantiating an inner class before the
comment|/// default arguments of its methods have been parsed.
name|UnparsedDefaultArgInstantiationsMap
name|UnparsedDefaultArgInstantiations
decl_stmt|;
comment|// Contains the locations of the beginning of unparsed default
comment|// argument locations.
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
comment|/// UndefinedInternals - all the used, undefined objects which require a
comment|/// definition in this translation unit.
name|llvm
operator|::
name|MapVector
operator|<
name|NamedDecl
operator|*
operator|,
name|SourceLocation
operator|>
name|UndefinedButUsed
expr_stmt|;
comment|/// Obtain a sorted list of functions that are undefined but ODR-used.
name|void
name|getUndefinedButUsed
argument_list|(
name|SmallVectorImpl
operator|<
name|std
operator|::
name|pair
operator|<
name|NamedDecl
operator|*
argument_list|,
name|SourceLocation
operator|>
expr|>
operator|&
name|Undefined
argument_list|)
decl_stmt|;
comment|/// Retrieves list of suspicious delete-expressions that will be checked at
comment|/// the end of translation unit.
specifier|const
name|llvm
operator|::
name|MapVector
operator|<
name|FieldDecl
operator|*
operator|,
name|DeleteLocs
operator|>
operator|&
name|getMismatchingDeleteExpressions
argument_list|()
specifier|const
expr_stmt|;
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
comment|/// Method Pool - allows efficient lookup when typechecking messages to "id".
comment|/// We need to maintain a list, since selectors can have differing signatures
comment|/// across classes. In Cocoa, this happens to be extremely uncommon (only 1%
comment|/// of selectors are "overloaded").
comment|/// At the head of the list it is recorded whether there were 0, 1, or>= 2
comment|/// methods inside categories with a particular selector.
name|GlobalMethodPool
name|MethodPool
decl_stmt|;
comment|/// Method selectors used in a \@selector expression. Used for implementation
comment|/// of -Wselector.
name|llvm
operator|::
name|MapVector
operator|<
name|Selector
operator|,
name|SourceLocation
operator|>
name|ReferencedSelectors
expr_stmt|;
comment|/// Kinds of C++ special members.
enum|enum
name|CXXSpecialMember
block|{
name|CXXDefaultConstructor
block|,
name|CXXCopyConstructor
block|,
name|CXXMoveConstructor
block|,
name|CXXCopyAssignment
block|,
name|CXXMoveAssignment
block|,
name|CXXDestructor
block|,
name|CXXInvalid
block|}
enum|;
typedef|typedef
name|std
operator|::
name|pair
operator|<
name|CXXRecordDecl
operator|*
operator|,
name|CXXSpecialMember
operator|>
name|SpecialMemberDecl
expr_stmt|;
comment|/// The C++ special members which we are currently in the process of
comment|/// declaring. If this process recursively triggers the declaration of the
comment|/// same special member, we should act as if it is not yet declared.
name|llvm
operator|::
name|SmallSet
operator|<
name|SpecialMemberDecl
operator|,
literal|4
operator|>
name|SpecialMembersBeingDeclared
expr_stmt|;
comment|/// The function definitions which were renamed as part of typo-correction
comment|/// to match their respective declarations. We want to keep track of them
comment|/// to ensure that we don't emit a "redefinition" error if we encounter a
comment|/// correctly named definition after the renamed definition.
name|llvm
operator|::
name|SmallPtrSet
operator|<
specifier|const
name|NamedDecl
operator|*
operator|,
literal|4
operator|>
name|TypoCorrectedFunctionDefinitions
expr_stmt|;
comment|/// Stack of types that correspond to the parameter entities that are
comment|/// currently being copy-initialized. Can be empty.
name|llvm
operator|::
name|SmallVector
operator|<
name|QualType
operator|,
literal|4
operator|>
name|CurrentParameterCopyTypes
expr_stmt|;
name|void
name|ReadMethodPool
parameter_list|(
name|Selector
name|Sel
parameter_list|)
function_decl|;
name|void
name|updateOutOfDateSelector
parameter_list|(
name|Selector
name|Sel
parameter_list|)
function_decl|;
comment|/// Private Helper predicate to check for 'self'.
name|bool
name|isSelfExpr
parameter_list|(
name|Expr
modifier|*
name|RExpr
parameter_list|)
function_decl|;
name|bool
name|isSelfExpr
parameter_list|(
name|Expr
modifier|*
name|RExpr
parameter_list|,
specifier|const
name|ObjCMethodDecl
modifier|*
name|Method
parameter_list|)
function_decl|;
comment|/// \brief Cause the active diagnostic on the DiagosticsEngine to be
comment|/// emitted. This is closely coupled to the SemaDiagnosticBuilder class and
comment|/// should not be used elsewhere.
name|void
name|EmitCurrentDiagnostic
parameter_list|(
name|unsigned
name|DiagID
parameter_list|)
function_decl|;
comment|/// Records and restores the FP_CONTRACT state on entry/exit of compound
comment|/// statements.
name|class
name|FPContractStateRAII
block|{
name|public
label|:
name|FPContractStateRAII
argument_list|(
name|Sema
operator|&
name|S
argument_list|)
operator|:
name|S
argument_list|(
name|S
argument_list|)
operator|,
name|OldFPFeaturesState
argument_list|(
argument|S.FPFeatures
argument_list|)
block|{}
operator|~
name|FPContractStateRAII
argument_list|()
block|{
name|S
operator|.
name|FPFeatures
operator|=
name|OldFPFeaturesState
block|; }
name|private
operator|:
name|Sema
operator|&
name|S
expr_stmt|;
name|FPOptions
name|OldFPFeaturesState
decl_stmt|;
block|}
empty_stmt|;
name|void
name|addImplicitTypedef
parameter_list|(
name|StringRef
name|Name
parameter_list|,
name|QualType
name|T
parameter_list|)
function_decl|;
name|public
label|:
name|Sema
argument_list|(
argument|Preprocessor&pp
argument_list|,
argument|ASTContext&ctxt
argument_list|,
argument|ASTConsumer&consumer
argument_list|,
argument|TranslationUnitKind TUKind = TU_Complete
argument_list|,
argument|CodeCompleteConsumer *CompletionConsumer = nullptr
argument_list|)
empty_stmt|;
operator|~
name|Sema
argument_list|()
expr_stmt|;
comment|/// \brief Perform initialization that occurs after the parser has been
comment|/// initialized but before it parses anything.
name|void
name|Initialize
parameter_list|()
function_decl|;
specifier|const
name|LangOptions
operator|&
name|getLangOpts
argument_list|()
specifier|const
block|{
return|return
name|LangOpts
return|;
block|}
name|OpenCLOptions
modifier|&
name|getOpenCLOptions
parameter_list|()
block|{
return|return
name|OpenCLFeatures
return|;
block|}
name|FPOptions
modifier|&
name|getFPOptions
parameter_list|()
block|{
return|return
name|FPFeatures
return|;
block|}
name|DiagnosticsEngine
operator|&
name|getDiagnostics
argument_list|()
specifier|const
block|{
return|return
name|Diags
return|;
block|}
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
name|ASTMutationListener
operator|*
name|getASTMutationListener
argument_list|()
specifier|const
expr_stmt|;
name|ExternalSemaSource
operator|*
name|getExternalSource
argument_list|()
specifier|const
block|{
return|return
name|ExternalSource
return|;
block|}
comment|///\brief Registers an external source. If an external source already exists,
comment|/// creates a multiplex external source and appends to it.
comment|///
comment|///\param[in] E - A non-null external sema source.
comment|///
name|void
name|addExternalSource
parameter_list|(
name|ExternalSemaSource
modifier|*
name|E
parameter_list|)
function_decl|;
name|void
name|PrintStats
argument_list|()
specifier|const
expr_stmt|;
comment|/// \brief Helper class that creates diagnostics with optional
comment|/// template instantiation stacks.
comment|///
comment|/// This class provides a wrapper around the basic DiagnosticBuilder
comment|/// class that emits diagnostics. SemaDiagnosticBuilder is
comment|/// responsible for emitting the diagnostic (as DiagnosticBuilder
comment|/// does) and, if the diagnostic comes from inside a template
comment|/// instantiation, printing the template instantiation stack as
comment|/// well.
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
comment|// This is a cunning lie. DiagnosticBuilder actually performs move
comment|// construction in its copy constructor (but due to varied uses, it's not
comment|// possible to conveniently express this as actual move construction). So
comment|// the default copy ctor here is fine, because the base class disables the
comment|// source anyway, so the user-defined ~SemaDiagnosticBuilder is a safe no-op
comment|// in that case anwyay.
name|SemaDiagnosticBuilder
argument_list|(
specifier|const
name|SemaDiagnosticBuilder
operator|&
argument_list|)
operator|=
expr|default
block|;
operator|~
name|SemaDiagnosticBuilder
argument_list|()
block|{
comment|// If we aren't active, there is nothing to do.
if|if
condition|(
operator|!
name|isActive
argument_list|()
condition|)
return|return;
comment|// Otherwise, we need to emit the diagnostic. First flush the underlying
comment|// DiagnosticBuilder data, and clear the diagnostic builder itself so it
comment|// won't emit the diagnostic in its own destructor.
comment|//
comment|// This seems wasteful, in that as written the DiagnosticBuilder dtor will
comment|// do its own needless checks to see if the diagnostic needs to be
comment|// emitted. However, because we take care to ensure that the builder
comment|// objects never escape, a sufficiently smart compiler will be able to
comment|// eliminate that code.
name|FlushCounts
argument_list|()
block|;
name|Clear
argument_list|()
block|;
comment|// Dispatch to Sema to emit the diagnostic.
name|SemaRef
operator|.
name|EmitCurrentDiagnostic
argument_list|(
name|DiagID
argument_list|)
block|;     }
comment|/// Teach operator<< to produce an object of the correct type.
name|template
operator|<
name|typename
name|T
operator|>
name|friend
specifier|const
name|SemaDiagnosticBuilder
operator|&
name|operator
operator|<<
operator|(
specifier|const
name|SemaDiagnosticBuilder
operator|&
name|Diag
expr|,
specifier|const
name|T
operator|&
name|Value
operator|)
block|{
specifier|const
name|DiagnosticBuilder
operator|&
name|BaseDiag
operator|=
name|Diag
block|;
name|BaseDiag
operator|<<
name|Value
block|;
return|return
name|Diag
return|;
block|}
block|}
empty_stmt|;
comment|/// \brief Emit a diagnostic.
name|SemaDiagnosticBuilder
name|Diag
parameter_list|(
name|SourceLocation
name|Loc
parameter_list|,
name|unsigned
name|DiagID
parameter_list|)
block|{
name|DiagnosticBuilder
name|DB
init|=
name|Diags
operator|.
name|Report
argument_list|(
name|Loc
argument_list|,
name|DiagID
argument_list|)
decl_stmt|;
return|return
name|SemaDiagnosticBuilder
argument_list|(
name|DB
argument_list|,
operator|*
name|this
argument_list|,
name|DiagID
argument_list|)
return|;
block|}
comment|/// \brief Emit a partial diagnostic.
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
comment|/// \brief Build a partial diagnostic.
name|PartialDiagnostic
name|PDiag
parameter_list|(
name|unsigned
name|DiagID
init|=
literal|0
parameter_list|)
function_decl|;
comment|// in SemaInternal.h
name|bool
name|findMacroSpelling
parameter_list|(
name|SourceLocation
modifier|&
name|loc
parameter_list|,
name|StringRef
name|name
parameter_list|)
function_decl|;
comment|/// \brief Get a string to suggest for zero-initialization of a type.
name|std
operator|::
name|string
name|getFixItZeroInitializerForType
argument_list|(
argument|QualType T
argument_list|,
argument|SourceLocation Loc
argument_list|)
specifier|const
expr_stmt|;
name|std
operator|::
name|string
name|getFixItZeroLiteralForType
argument_list|(
argument|QualType T
argument_list|,
argument|SourceLocation Loc
argument_list|)
specifier|const
expr_stmt|;
comment|/// \brief Calls \c Lexer::getLocForEndOfToken()
name|SourceLocation
name|getLocForEndOfToken
parameter_list|(
name|SourceLocation
name|Loc
parameter_list|,
name|unsigned
name|Offset
init|=
literal|0
parameter_list|)
function_decl|;
comment|/// \brief Retrieve the module loader associated with the preprocessor.
name|ModuleLoader
operator|&
name|getModuleLoader
argument_list|()
specifier|const
expr_stmt|;
name|void
name|emitAndClearUnusedLocalTypedefWarnings
parameter_list|()
function_decl|;
name|void
name|ActOnEndOfTranslationUnit
parameter_list|()
function_decl|;
name|void
name|CheckDelegatingCtorCycles
parameter_list|()
function_decl|;
name|Scope
modifier|*
name|getScopeForContext
parameter_list|(
name|DeclContext
modifier|*
name|Ctx
parameter_list|)
function_decl|;
name|void
name|PushFunctionScope
parameter_list|()
function_decl|;
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
name|sema
operator|::
name|LambdaScopeInfo
operator|*
name|PushLambdaScope
argument_list|()
expr_stmt|;
comment|/// \brief This is used to inform Sema what the current TemplateParameterDepth
comment|/// is during Parsing.  Currently it is used to pass on the depth
comment|/// when parsing generic lambda 'auto' parameters.
name|void
name|RecordParsingTemplateParameterDepth
parameter_list|(
name|unsigned
name|Depth
parameter_list|)
function_decl|;
name|void
name|PushCapturedRegionScope
parameter_list|(
name|Scope
modifier|*
name|RegionScope
parameter_list|,
name|CapturedDecl
modifier|*
name|CD
parameter_list|,
name|RecordDecl
modifier|*
name|RD
parameter_list|,
name|CapturedRegionKind
name|K
parameter_list|)
function_decl|;
name|void
name|PopFunctionScopeInfo
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
name|nullptr
argument_list|,
specifier|const
name|Decl
operator|*
name|D
operator|=
name|nullptr
argument_list|,
specifier|const
name|BlockExpr
operator|*
name|blkExpr
operator|=
name|nullptr
argument_list|)
decl_stmt|;
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
name|sema
operator|::
name|FunctionScopeInfo
operator|*
name|getEnclosingFunction
argument_list|()
specifier|const
block|{
if|if
condition|(
name|FunctionScopes
operator|.
name|empty
argument_list|()
condition|)
return|return
name|nullptr
return|;
for|for
control|(
name|int
name|e
init|=
name|FunctionScopes
operator|.
name|size
argument_list|()
operator|-
literal|1
init|;
name|e
operator|>=
literal|0
condition|;
operator|--
name|e
control|)
block|{
if|if
condition|(
name|isa
operator|<
name|sema
operator|::
name|BlockScopeInfo
operator|>
operator|(
name|FunctionScopes
index|[
name|e
index|]
operator|)
condition|)
continue|continue;
return|return
name|FunctionScopes
index|[
name|e
index|]
return|;
block|}
return|return
name|nullptr
return|;
block|}
end_decl_stmt

begin_expr_stmt
name|template
operator|<
name|typename
name|ExprT
operator|>
name|void
name|recordUseOfEvaluatedWeak
argument_list|(
argument|const ExprT *E
argument_list|,
argument|bool IsRead=true
argument_list|)
block|{
if|if
condition|(
operator|!
name|isUnevaluatedContext
argument_list|()
condition|)
name|getCurFunction
argument_list|()
operator|->
name|recordUseOfWeak
argument_list|(
name|E
argument_list|,
name|IsRead
argument_list|)
expr_stmt|;
block|}
end_expr_stmt

begin_function_decl
name|void
name|PushCompoundScope
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|PopCompoundScope
parameter_list|()
function_decl|;
end_function_decl

begin_expr_stmt
name|sema
operator|::
name|CompoundScopeInfo
operator|&
name|getCurCompoundScope
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|bool
name|hasAnyUnrecoverableErrorsInThisFunction
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
comment|/// Retrieve the current lambda scope info, if any.
end_comment

begin_comment
comment|/// \param IgnoreNonLambdaCapturingScope true if should find the top-most
end_comment

begin_comment
comment|/// lambda scope info ignoring all inner capturing scopes that are not
end_comment

begin_comment
comment|/// lambda scopes.
end_comment

begin_expr_stmt
name|sema
operator|::
name|LambdaScopeInfo
operator|*
name|getCurLambda
argument_list|(
argument|bool IgnoreNonLambdaCapturingScope = false
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// \brief Retrieve the current generic lambda info, if any.
end_comment

begin_expr_stmt
name|sema
operator|::
name|LambdaScopeInfo
operator|*
name|getCurGenericLambda
argument_list|()
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// \brief Retrieve the current captured region, if any.
end_comment

begin_expr_stmt
name|sema
operator|::
name|CapturedRegionScopeInfo
operator|*
name|getCurCapturedRegion
argument_list|()
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// WeakTopLevelDeclDecls - access to \#pragma weak-generated Decls
end_comment

begin_expr_stmt
name|SmallVectorImpl
operator|<
name|Decl
operator|*
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

begin_function_decl
name|void
name|ActOnComment
parameter_list|(
name|SourceRange
name|Comment
parameter_list|)
function_decl|;
end_function_decl

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
parameter_list|,
specifier|const
name|DeclSpec
modifier|*
name|DS
init|=
name|nullptr
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
name|unsigned
name|CVRA
parameter_list|,
specifier|const
name|DeclSpec
modifier|*
name|DS
init|=
name|nullptr
parameter_list|)
function_decl|;
end_function_decl

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

begin_function_decl
name|bool
name|CheckFunctionReturnType
parameter_list|(
name|QualType
name|T
parameter_list|,
name|SourceLocation
name|Loc
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// \brief Build a function type.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This routine checks the function type according to C++ rules and
end_comment

begin_comment
comment|/// under the assumption that the result type and parameter types have
end_comment

begin_comment
comment|/// just been instantiated from a template. It therefore duplicates
end_comment

begin_comment
comment|/// some of the behavior of GetTypeForDeclarator, but in a much
end_comment

begin_comment
comment|/// simpler form that is only suitable for this narrow use case.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param T The return type of the function.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param ParamTypes The parameter types of the function. This array
end_comment

begin_comment
comment|/// will be modified to account for adjustments to the types of the
end_comment

begin_comment
comment|/// function parameters.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param Loc The location of the entity whose type involves this
end_comment

begin_comment
comment|/// function type or, if there is no such entity, the location of the
end_comment

begin_comment
comment|/// type that will have function type.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param Entity The name of the entity that involves the function
end_comment

begin_comment
comment|/// type, if known.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param EPI Extra information about the function type. Usually this will
end_comment

begin_comment
comment|/// be taken from an existing function with the same prototype.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \returns A suitable function type, if there are no errors. The
end_comment

begin_comment
comment|/// unqualified type will always be a FunctionProtoType.
end_comment

begin_comment
comment|/// Otherwise, returns a NULL type.
end_comment

begin_decl_stmt
name|QualType
name|BuildFunctionType
argument_list|(
name|QualType
name|T
argument_list|,
name|MutableArrayRef
operator|<
name|QualType
operator|>
name|ParamTypes
argument_list|,
name|SourceLocation
name|Loc
argument_list|,
name|DeclarationName
name|Entity
argument_list|,
specifier|const
name|FunctionProtoType
operator|::
name|ExtProtoInfo
operator|&
name|EPI
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
name|QualType
name|BuildAtomicType
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
name|QualType
name|BuildReadPipeType
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
name|QualType
name|BuildWritePipeType
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
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|TypeSourceInfo
modifier|*
name|GetTypeForDeclaratorCast
parameter_list|(
name|Declarator
modifier|&
name|D
parameter_list|,
name|QualType
name|FromTy
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
name|nullptr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|CanThrowResult
name|canThrow
parameter_list|(
specifier|const
name|Expr
modifier|*
name|E
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|const
name|FunctionProtoType
modifier|*
name|ResolveExceptionSpec
parameter_list|(
name|SourceLocation
name|Loc
parameter_list|,
specifier|const
name|FunctionProtoType
modifier|*
name|FPT
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
name|void
name|UpdateExceptionSpec
argument_list|(
name|FunctionDecl
operator|*
name|FD
argument_list|,
specifier|const
name|FunctionProtoType
operator|::
name|ExceptionSpecInfo
operator|&
name|ESI
argument_list|)
decl_stmt|;
end_decl_stmt

begin_function_decl
name|bool
name|CheckSpecifiedExceptionType
parameter_list|(
name|QualType
modifier|&
name|T
parameter_list|,
name|SourceRange
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
name|NestedDiagID
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
name|NestedDiagID
parameter_list|,
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

begin_comment
comment|/// \brief The parser has parsed the context-sensitive type 'instancetype'
end_comment

begin_comment
comment|/// in an Objective-C message declaration. Return the appropriate type.
end_comment

begin_function_decl
name|ParsedType
name|ActOnObjCInstanceType
parameter_list|(
name|SourceLocation
name|Loc
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// \brief Abstract class used to diagnose incomplete types.
end_comment

begin_struct
struct|struct
name|TypeDiagnoser
block|{
name|TypeDiagnoser
argument_list|()
block|{}
name|virtual
name|void
name|diagnose
parameter_list|(
name|Sema
modifier|&
name|S
parameter_list|,
name|SourceLocation
name|Loc
parameter_list|,
name|QualType
name|T
parameter_list|)
init|=
literal|0
function_decl|;
name|virtual
operator|~
name|TypeDiagnoser
argument_list|()
block|{}
block|}
struct|;
end_struct

begin_function
specifier|static
name|int
name|getPrintable
parameter_list|(
name|int
name|I
parameter_list|)
block|{
return|return
name|I
return|;
block|}
end_function

begin_function
specifier|static
name|unsigned
name|getPrintable
parameter_list|(
name|unsigned
name|I
parameter_list|)
block|{
return|return
name|I
return|;
block|}
end_function

begin_function
specifier|static
name|bool
name|getPrintable
parameter_list|(
name|bool
name|B
parameter_list|)
block|{
return|return
name|B
return|;
block|}
end_function

begin_function
specifier|static
specifier|const
name|char
modifier|*
name|getPrintable
parameter_list|(
specifier|const
name|char
modifier|*
name|S
parameter_list|)
block|{
return|return
name|S
return|;
block|}
end_function

begin_function
specifier|static
name|StringRef
name|getPrintable
parameter_list|(
name|StringRef
name|S
parameter_list|)
block|{
return|return
name|S
return|;
block|}
end_function

begin_expr_stmt
specifier|static
specifier|const
name|std
operator|::
name|string
operator|&
name|getPrintable
argument_list|(
argument|const std::string&S
argument_list|)
block|{
return|return
name|S
return|;
block|}
end_expr_stmt

begin_function
specifier|static
specifier|const
name|IdentifierInfo
modifier|*
name|getPrintable
parameter_list|(
specifier|const
name|IdentifierInfo
modifier|*
name|II
parameter_list|)
block|{
return|return
name|II
return|;
block|}
end_function

begin_function
specifier|static
name|DeclarationName
name|getPrintable
parameter_list|(
name|DeclarationName
name|N
parameter_list|)
block|{
return|return
name|N
return|;
block|}
end_function

begin_function
specifier|static
name|QualType
name|getPrintable
parameter_list|(
name|QualType
name|T
parameter_list|)
block|{
return|return
name|T
return|;
block|}
end_function

begin_function
specifier|static
name|SourceRange
name|getPrintable
parameter_list|(
name|SourceRange
name|R
parameter_list|)
block|{
return|return
name|R
return|;
block|}
end_function

begin_function
specifier|static
name|SourceRange
name|getPrintable
parameter_list|(
name|SourceLocation
name|L
parameter_list|)
block|{
return|return
name|L
return|;
block|}
end_function

begin_function
specifier|static
name|SourceRange
name|getPrintable
parameter_list|(
specifier|const
name|Expr
modifier|*
name|E
parameter_list|)
block|{
return|return
name|E
operator|->
name|getSourceRange
argument_list|()
return|;
block|}
end_function

begin_function
specifier|static
name|SourceRange
name|getPrintable
parameter_list|(
name|TypeLoc
name|TL
parameter_list|)
block|{
return|return
name|TL
operator|.
name|getSourceRange
argument_list|()
return|;
block|}
end_function

begin_expr_stmt
name|template
operator|<
name|typename
operator|...
name|Ts
operator|>
name|class
name|BoundTypeDiagnoser
operator|:
name|public
name|TypeDiagnoser
block|{
name|unsigned
name|DiagID
block|;
name|std
operator|::
name|tuple
operator|<
specifier|const
name|Ts
operator|&
operator|...
operator|>
name|Args
block|;
name|template
operator|<
name|std
operator|::
name|size_t
operator|...
name|Is
operator|>
name|void
name|emit
argument_list|(
argument|const SemaDiagnosticBuilder&DB
argument_list|,
argument|llvm::index_sequence<Is...>
argument_list|)
specifier|const
block|{
comment|// Apply all tuple elements to the builder in order.
name|bool
name|Dummy
index|[]
operator|=
block|{
name|false
block|,
operator|(
name|DB
operator|<<
name|getPrintable
argument_list|(
name|std
operator|::
name|get
operator|<
name|Is
operator|>
operator|(
name|Args
operator|)
argument_list|)
operator|)
operator|...
block|}
block|;
operator|(
name|void
operator|)
name|Dummy
block|;     }
name|public
operator|:
name|BoundTypeDiagnoser
argument_list|(
argument|unsigned DiagID
argument_list|,
argument|const Ts&...Args
argument_list|)
operator|:
name|TypeDiagnoser
argument_list|()
block|,
name|DiagID
argument_list|(
name|DiagID
argument_list|)
block|,
name|Args
argument_list|(
argument|Args...
argument_list|)
block|{
name|assert
argument_list|(
name|DiagID
operator|!=
literal|0
operator|&&
literal|"no diagnostic for type diagnoser"
argument_list|)
block|;     }
name|void
name|diagnose
argument_list|(
argument|Sema&S
argument_list|,
argument|SourceLocation Loc
argument_list|,
argument|QualType T
argument_list|)
name|override
block|{
specifier|const
name|SemaDiagnosticBuilder
operator|&
name|DB
operator|=
name|S
operator|.
name|Diag
argument_list|(
name|Loc
argument_list|,
name|DiagID
argument_list|)
block|;
name|emit
argument_list|(
name|DB
argument_list|,
name|llvm
operator|::
name|index_sequence_for
operator|<
name|Ts
operator|...
operator|>
operator|(
operator|)
argument_list|)
block|;
name|DB
operator|<<
name|T
block|;     }
block|}
expr_stmt|;
end_expr_stmt

begin_label
name|private
label|:
end_label

begin_function_decl
name|bool
name|RequireCompleteTypeImpl
parameter_list|(
name|SourceLocation
name|Loc
parameter_list|,
name|QualType
name|T
parameter_list|,
name|TypeDiagnoser
modifier|*
name|Diagnoser
parameter_list|)
function_decl|;
end_function_decl

begin_struct
struct|struct
name|ModuleScope
block|{
name|clang
operator|::
name|Module
operator|*
name|Module
expr_stmt|;
name|VisibleModuleSet
name|OuterVisibleModules
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/// The modules we're currently parsing.
end_comment

begin_expr_stmt
name|llvm
operator|::
name|SmallVector
operator|<
name|ModuleScope
operator|,
literal|16
operator|>
name|ModuleScopes
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// Get the module whose scope we are currently within.
end_comment

begin_expr_stmt
name|Module
operator|*
name|getCurrentModule
argument_list|()
specifier|const
block|{
return|return
name|ModuleScopes
operator|.
name|empty
argument_list|()
operator|?
name|nullptr
operator|:
name|ModuleScopes
operator|.
name|back
argument_list|()
operator|.
name|Module
return|;
block|}
end_expr_stmt

begin_decl_stmt
name|VisibleModuleSet
name|VisibleModules
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|Module
modifier|*
name|CachedFakeTopLevelModule
decl_stmt|;
end_decl_stmt

begin_label
name|public
label|:
end_label

begin_comment
comment|/// \brief Get the module owning an entity.
end_comment

begin_function_decl
name|Module
modifier|*
name|getOwningModule
parameter_list|(
name|Decl
modifier|*
name|Entity
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// \brief Make a merged definition of an existing hidden definition \p ND
end_comment

begin_comment
comment|/// visible at the specified location.
end_comment

begin_function_decl
name|void
name|makeMergedDefinitionVisible
parameter_list|(
name|NamedDecl
modifier|*
name|ND
parameter_list|)
function_decl|;
end_function_decl

begin_function
name|bool
name|isModuleVisible
parameter_list|(
name|Module
modifier|*
name|M
parameter_list|)
block|{
return|return
name|VisibleModules
operator|.
name|isVisible
argument_list|(
name|M
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/// Determine whether a declaration is visible to name lookup.
end_comment

begin_function
name|bool
name|isVisible
parameter_list|(
specifier|const
name|NamedDecl
modifier|*
name|D
parameter_list|)
block|{
return|return
operator|!
name|D
operator|->
name|isHidden
argument_list|()
operator|||
name|isVisibleSlow
argument_list|(
name|D
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/// Determine whether any declaration of an entity is visible.
end_comment

begin_decl_stmt
name|bool
name|hasVisibleDeclaration
argument_list|(
specifier|const
name|NamedDecl
operator|*
name|D
argument_list|,
name|llvm
operator|::
name|SmallVectorImpl
operator|<
name|Module
operator|*
operator|>
operator|*
name|Modules
operator|=
name|nullptr
argument_list|)
block|{
return|return
name|isVisible
argument_list|(
name|D
argument_list|)
operator|||
name|hasVisibleDeclarationSlow
argument_list|(
name|D
argument_list|,
name|Modules
argument_list|)
return|;
block|}
end_decl_stmt

begin_decl_stmt
name|bool
name|hasVisibleDeclarationSlow
argument_list|(
specifier|const
name|NamedDecl
operator|*
name|D
argument_list|,
name|llvm
operator|::
name|SmallVectorImpl
operator|<
name|Module
operator|*
operator|>
operator|*
name|Modules
argument_list|)
decl_stmt|;
end_decl_stmt

begin_function_decl
name|bool
name|hasVisibleMergedDefinition
parameter_list|(
name|NamedDecl
modifier|*
name|Def
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// Determine if \p D has a visible definition. If not, suggest a declaration
end_comment

begin_comment
comment|/// that should be made visible to expose the definition.
end_comment

begin_function_decl
name|bool
name|hasVisibleDefinition
parameter_list|(
name|NamedDecl
modifier|*
name|D
parameter_list|,
name|NamedDecl
modifier|*
modifier|*
name|Suggested
parameter_list|,
name|bool
name|OnlyNeedComplete
init|=
name|false
parameter_list|)
function_decl|;
end_function_decl

begin_function
name|bool
name|hasVisibleDefinition
parameter_list|(
specifier|const
name|NamedDecl
modifier|*
name|D
parameter_list|)
block|{
name|NamedDecl
modifier|*
name|Hidden
decl_stmt|;
return|return
name|hasVisibleDefinition
argument_list|(
name|const_cast
operator|<
name|NamedDecl
operator|*
operator|>
operator|(
name|D
operator|)
argument_list|,
operator|&
name|Hidden
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/// Determine if the template parameter \p D has a visible default argument.
end_comment

begin_decl_stmt
name|bool
name|hasVisibleDefaultArgument
argument_list|(
specifier|const
name|NamedDecl
operator|*
name|D
argument_list|,
name|llvm
operator|::
name|SmallVectorImpl
operator|<
name|Module
operator|*
operator|>
operator|*
name|Modules
operator|=
name|nullptr
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// Determine if there is a visible declaration of \p D that is a member
end_comment

begin_comment
comment|/// specialization declaration (as opposed to an instantiated declaration).
end_comment

begin_decl_stmt
name|bool
name|hasVisibleMemberSpecialization
argument_list|(
specifier|const
name|NamedDecl
operator|*
name|D
argument_list|,
name|llvm
operator|::
name|SmallVectorImpl
operator|<
name|Module
operator|*
operator|>
operator|*
name|Modules
operator|=
name|nullptr
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// Determine if \p A and \p B are equivalent internal linkage declarations
end_comment

begin_comment
comment|/// from different modules, and thus an ambiguity error can be downgraded to
end_comment

begin_comment
comment|/// an extension warning.
end_comment

begin_function_decl
name|bool
name|isEquivalentInternalLinkageDeclaration
parameter_list|(
specifier|const
name|NamedDecl
modifier|*
name|A
parameter_list|,
specifier|const
name|NamedDecl
modifier|*
name|B
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
name|void
name|diagnoseEquivalentInternalLinkageDeclarations
argument_list|(
name|SourceLocation
name|Loc
argument_list|,
specifier|const
name|NamedDecl
operator|*
name|D
argument_list|,
name|ArrayRef
operator|<
specifier|const
name|NamedDecl
operator|*
operator|>
name|Equiv
argument_list|)
decl_stmt|;
end_decl_stmt

begin_function
name|bool
name|isCompleteType
parameter_list|(
name|SourceLocation
name|Loc
parameter_list|,
name|QualType
name|T
parameter_list|)
block|{
return|return
operator|!
name|RequireCompleteTypeImpl
argument_list|(
name|Loc
argument_list|,
name|T
argument_list|,
name|nullptr
argument_list|)
return|;
block|}
end_function

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
name|TypeDiagnoser
modifier|&
name|Diagnoser
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

begin_expr_stmt
name|template
operator|<
name|typename
operator|...
name|Ts
operator|>
name|bool
name|RequireCompleteType
argument_list|(
argument|SourceLocation Loc
argument_list|,
argument|QualType T
argument_list|,
argument|unsigned DiagID
argument_list|,
argument|const Ts&...Args
argument_list|)
block|{
name|BoundTypeDiagnoser
operator|<
name|Ts
operator|...
operator|>
name|Diagnoser
argument_list|(
name|DiagID
argument_list|,
name|Args
operator|...
argument_list|)
block|;
return|return
name|RequireCompleteType
argument_list|(
name|Loc
argument_list|,
name|T
argument_list|,
name|Diagnoser
argument_list|)
return|;
block|}
end_expr_stmt

begin_function_decl
name|void
name|completeExprArrayBound
parameter_list|(
name|Expr
modifier|*
name|E
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|RequireCompleteExprType
parameter_list|(
name|Expr
modifier|*
name|E
parameter_list|,
name|TypeDiagnoser
modifier|&
name|Diagnoser
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|RequireCompleteExprType
parameter_list|(
name|Expr
modifier|*
name|E
parameter_list|,
name|unsigned
name|DiagID
parameter_list|)
function_decl|;
end_function_decl

begin_expr_stmt
name|template
operator|<
name|typename
operator|...
name|Ts
operator|>
name|bool
name|RequireCompleteExprType
argument_list|(
argument|Expr *E
argument_list|,
argument|unsigned DiagID
argument_list|,
argument|const Ts&...Args
argument_list|)
block|{
name|BoundTypeDiagnoser
operator|<
name|Ts
operator|...
operator|>
name|Diagnoser
argument_list|(
name|DiagID
argument_list|,
name|Args
operator|...
argument_list|)
block|;
return|return
name|RequireCompleteExprType
argument_list|(
name|E
argument_list|,
name|Diagnoser
argument_list|)
return|;
block|}
end_expr_stmt

begin_function_decl
name|bool
name|RequireLiteralType
parameter_list|(
name|SourceLocation
name|Loc
parameter_list|,
name|QualType
name|T
parameter_list|,
name|TypeDiagnoser
modifier|&
name|Diagnoser
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|RequireLiteralType
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

begin_expr_stmt
name|template
operator|<
name|typename
operator|...
name|Ts
operator|>
name|bool
name|RequireLiteralType
argument_list|(
argument|SourceLocation Loc
argument_list|,
argument|QualType T
argument_list|,
argument|unsigned DiagID
argument_list|,
argument|const Ts&...Args
argument_list|)
block|{
name|BoundTypeDiagnoser
operator|<
name|Ts
operator|...
operator|>
name|Diagnoser
argument_list|(
name|DiagID
argument_list|,
name|Args
operator|...
argument_list|)
block|;
return|return
name|RequireLiteralType
argument_list|(
name|Loc
argument_list|,
name|T
argument_list|,
name|Diagnoser
argument_list|)
return|;
block|}
end_expr_stmt

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

begin_comment
comment|/// If AsUnevaluated is false, E is treated as though it were an evaluated
end_comment

begin_comment
comment|/// context, such as when building a type for decltype(auto).
end_comment

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
parameter_list|,
name|bool
name|AsUnevaluated
init|=
name|true
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
name|QualType
name|BuildUnaryTransformType
argument_list|(
name|QualType
name|BaseType
argument_list|,
name|UnaryTransformType
operator|::
name|UTTKind
name|UKind
argument_list|,
name|SourceLocation
name|Loc
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|//===--------------------------------------------------------------------===//
end_comment

begin_comment
comment|// Symbol table / Decl tracking callbacks: SemaDecl.cpp.
end_comment

begin_comment
comment|//
end_comment

begin_struct
struct|struct
name|SkipBodyInfo
block|{
name|SkipBodyInfo
argument_list|()
operator|:
name|ShouldSkip
argument_list|(
name|false
argument_list|)
operator|,
name|Previous
argument_list|(
argument|nullptr
argument_list|)
block|{}
name|bool
name|ShouldSkip
expr_stmt|;
name|NamedDecl
modifier|*
name|Previous
decl_stmt|;
block|}
struct|;
end_struct

begin_function_decl
name|DeclGroupPtrTy
name|ConvertDeclToDeclGroup
parameter_list|(
name|Decl
modifier|*
name|Ptr
parameter_list|,
name|Decl
modifier|*
name|OwnedType
init|=
name|nullptr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|DiagnoseUseOfUnimplementedSelectors
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
name|bool
name|isSimpleTypeSpecifier
argument_list|(
name|tok
operator|::
name|TokenKind
name|Kind
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_function_decl
name|ParsedType
name|getTypeName
parameter_list|(
specifier|const
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
name|nullptr
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
name|nullptr
parameter_list|,
name|bool
name|IsCtorOrDtorName
init|=
name|false
parameter_list|,
name|bool
name|WantNontrivialTypeSourceInfo
init|=
name|false
parameter_list|,
name|bool
name|IsClassTemplateDeductionContext
init|=
name|true
parameter_list|,
name|IdentifierInfo
modifier|*
modifier|*
name|CorrectedII
init|=
name|nullptr
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
parameter_list|,
name|Scope
modifier|*
name|S
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|DiagnoseUnknownTypeName
parameter_list|(
name|IdentifierInfo
modifier|*
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
parameter_list|,
name|bool
name|IsTemplateName
init|=
name|false
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// Attempt to behave like MSVC in situations where lookup of an unqualified
end_comment

begin_comment
comment|/// type name has failed in a dependent context. In these situations, we
end_comment

begin_comment
comment|/// automatically form a DependentTypeName that will retry lookup in a related
end_comment

begin_comment
comment|/// scope during instantiation.
end_comment

begin_function_decl
name|ParsedType
name|ActOnMSVCUnknownTypeName
parameter_list|(
specifier|const
name|IdentifierInfo
modifier|&
name|II
parameter_list|,
name|SourceLocation
name|NameLoc
parameter_list|,
name|bool
name|IsTemplateTypeArg
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
name|NC_VarTemplate
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
name|VarTemplate
parameter_list|(
name|TemplateName
name|Name
parameter_list|)
block|{
name|NameClassification
name|Result
argument_list|(
name|NC_VarTemplate
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
operator|||
name|Kind
operator|==
name|NC_VarTemplate
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
switch|switch
condition|(
name|Kind
condition|)
block|{
case|case
name|NC_TypeTemplate
case|:
return|return
name|TNK_Type_template
return|;
case|case
name|NC_FunctionTemplate
case|:
return|return
name|TNK_Function_template
return|;
case|case
name|NC_VarTemplate
case|:
return|return
name|TNK_Var_template
return|;
default|default:
name|llvm_unreachable
argument_list|(
literal|"unsupported name classification."
argument_list|)
expr_stmt|;
block|}
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

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param IsAddressOfOperand True if this name is the operand of a unary
end_comment

begin_comment
comment|///        address of ('&') expression, assuming it is classified as an
end_comment

begin_comment
comment|///        expression.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param CCC The correction callback, if typo correction is desired.
end_comment

begin_decl_stmt
name|NameClassification
name|ClassifyName
argument_list|(
name|Scope
operator|*
name|S
argument_list|,
name|CXXScopeSpec
operator|&
name|SS
argument_list|,
name|IdentifierInfo
operator|*
operator|&
name|Name
argument_list|,
name|SourceLocation
name|NameLoc
argument_list|,
specifier|const
name|Token
operator|&
name|NextToken
argument_list|,
name|bool
name|IsAddressOfOperand
argument_list|,
name|std
operator|::
name|unique_ptr
operator|<
name|CorrectionCandidateCallback
operator|>
name|CCC
operator|=
name|nullptr
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// Describes the detailed kind of a template name. Used in diagnostics.
end_comment

begin_decl_stmt
name|enum
name|class
name|TemplateNameKindForDiagnostics
block|{
name|ClassTemplate
operator|,
name|FunctionTemplate
operator|,
name|VarTemplate
operator|,
name|AliasTemplate
operator|,
name|TemplateTemplateParam
operator|,
name|DependentTemplate
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_function_decl
name|TemplateNameKindForDiagnostics
name|getTemplateNameKindForDiagnostics
parameter_list|(
name|TemplateName
name|Name
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// Determine whether it's plausible that E was intended to be a
end_comment

begin_comment
comment|/// template-name.
end_comment

begin_function
name|bool
name|mightBeIntendedToBeTemplateName
parameter_list|(
name|ExprResult
name|E
parameter_list|)
block|{
if|if
condition|(
operator|!
name|getLangOpts
argument_list|()
operator|.
name|CPlusPlus
operator|||
name|E
operator|.
name|isInvalid
argument_list|()
condition|)
return|return
name|false
return|;
if|if
condition|(
name|auto
operator|*
name|DRE
operator|=
name|dyn_cast
operator|<
name|DeclRefExpr
operator|>
operator|(
name|E
operator|.
name|get
argument_list|()
operator|)
condition|)
return|return
operator|!
name|DRE
operator|->
name|hasExplicitTemplateArgs
argument_list|()
return|;
if|if
condition|(
name|auto
operator|*
name|ME
operator|=
name|dyn_cast
operator|<
name|MemberExpr
operator|>
operator|(
name|E
operator|.
name|get
argument_list|()
operator|)
condition|)
return|return
operator|!
name|ME
operator|->
name|hasExplicitTemplateArgs
argument_list|()
return|;
comment|// Any additional cases recognized here should also be handled by
comment|// diagnoseExprIntendedAsTemplateName.
return|return
name|false
return|;
block|}
end_function

begin_function_decl
name|void
name|diagnoseExprIntendedAsTemplateName
parameter_list|(
name|Scope
modifier|*
name|S
parameter_list|,
name|ExprResult
name|TemplateName
parameter_list|,
name|SourceLocation
name|Less
parameter_list|,
name|SourceLocation
name|Greater
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
name|NamedDecl
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
name|bool
name|diagnoseQualifiedDeclaration
parameter_list|(
name|CXXScopeSpec
modifier|&
name|SS
parameter_list|,
name|DeclContext
modifier|*
name|DC
parameter_list|,
name|DeclarationName
name|Name
parameter_list|,
name|SourceLocation
name|Loc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|diagnoseIgnoredQualifiers
parameter_list|(
name|unsigned
name|DiagID
parameter_list|,
name|unsigned
name|Quals
parameter_list|,
name|SourceLocation
name|FallbackLoc
parameter_list|,
name|SourceLocation
name|ConstQualLoc
init|=
name|SourceLocation
argument_list|()
parameter_list|,
name|SourceLocation
name|VolatileQualLoc
init|=
name|SourceLocation
argument_list|()
parameter_list|,
name|SourceLocation
name|RestrictQualLoc
init|=
name|SourceLocation
argument_list|()
parameter_list|,
name|SourceLocation
name|AtomicQualLoc
init|=
name|SourceLocation
argument_list|()
parameter_list|,
name|SourceLocation
name|UnalignedQualLoc
init|=
name|SourceLocation
argument_list|()
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|bool
name|adjustContextForLocalExternDecl
parameter_list|(
name|DeclContext
modifier|*
modifier|&
name|DC
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|DiagnoseFunctionSpecifiers
parameter_list|(
specifier|const
name|DeclSpec
modifier|&
name|DS
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|NamedDecl
modifier|*
name|getShadowedDeclaration
parameter_list|(
specifier|const
name|TypedefNameDecl
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
name|NamedDecl
modifier|*
name|getShadowedDeclaration
parameter_list|(
specifier|const
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
name|NamedDecl
modifier|*
name|D
parameter_list|,
name|NamedDecl
modifier|*
name|ShadowedDecl
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

begin_comment
comment|/// Warn if 'E', which is an expression that is about to be modified, refers
end_comment

begin_comment
comment|/// to a shadowing declaration.
end_comment

begin_function_decl
name|void
name|CheckShadowingDeclModification
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

begin_decl_stmt
name|void
name|DiagnoseShadowingLambdaDecls
argument_list|(
specifier|const
name|sema
operator|::
name|LambdaScopeInfo
operator|*
name|LSI
argument_list|)
decl_stmt|;
end_decl_stmt

begin_label
name|private
label|:
end_label

begin_comment
comment|/// Map of current shadowing declarations to shadowed declarations. Warn if
end_comment

begin_comment
comment|/// it looks like the user is trying to modify the shadowing declaration.
end_comment

begin_expr_stmt
name|llvm
operator|::
name|DenseMap
operator|<
specifier|const
name|NamedDecl
operator|*
operator|,
specifier|const
name|NamedDecl
operator|*
operator|>
name|ShadowingDecls
expr_stmt|;
end_expr_stmt

begin_label
name|public
label|:
end_label

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
name|void
name|handleTagNumbering
parameter_list|(
specifier|const
name|TagDecl
modifier|*
name|Tag
parameter_list|,
name|Scope
modifier|*
name|TagScope
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|setTagNameForLinkagePurposes
parameter_list|(
name|TagDecl
modifier|*
name|TagFromDeclSpec
parameter_list|,
name|TypedefNameDecl
modifier|*
name|NewTD
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|CheckTypedefForVariablyModifiedType
parameter_list|(
name|Scope
modifier|*
name|S
parameter_list|,
name|TypedefNameDecl
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
name|TypeSourceInfo
modifier|*
name|TInfo
parameter_list|,
name|LookupResult
modifier|&
name|Previous
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

begin_decl_stmt
name|NamedDecl
modifier|*
name|ActOnVariableDeclarator
argument_list|(
name|Scope
operator|*
name|S
argument_list|,
name|Declarator
operator|&
name|D
argument_list|,
name|DeclContext
operator|*
name|DC
argument_list|,
name|TypeSourceInfo
operator|*
name|TInfo
argument_list|,
name|LookupResult
operator|&
name|Previous
argument_list|,
name|MultiTemplateParamsArg
name|TemplateParamLists
argument_list|,
name|bool
operator|&
name|AddToScope
argument_list|,
name|ArrayRef
operator|<
name|BindingDecl
operator|*
operator|>
name|Bindings
operator|=
name|None
argument_list|)
decl_stmt|;
end_decl_stmt

begin_function_decl
name|NamedDecl
modifier|*
name|ActOnDecompositionDeclarator
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
name|TemplateParamLists
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|// Returns true if the variable declaration is a redeclaration
end_comment

begin_function_decl
name|bool
name|CheckVariableDeclaration
parameter_list|(
name|VarDecl
modifier|*
name|NewVD
parameter_list|,
name|LookupResult
modifier|&
name|Previous
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|CheckVariableDeclarationType
parameter_list|(
name|VarDecl
modifier|*
name|NewVD
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|DeduceVariableDeclarationType
parameter_list|(
name|VarDecl
modifier|*
name|VDecl
parameter_list|,
name|bool
name|DirectInit
parameter_list|,
name|Expr
modifier|*
name|Init
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|CheckCompleteVariableDeclaration
parameter_list|(
name|VarDecl
modifier|*
name|VD
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|CheckCompleteDecompositionDeclaration
parameter_list|(
name|DecompositionDecl
modifier|*
name|DD
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|MaybeSuggestAddingStaticToDecl
parameter_list|(
specifier|const
name|FunctionDecl
modifier|*
name|D
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
name|AddToScope
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
name|bool
name|CheckConstexprFunctionDecl
parameter_list|(
specifier|const
name|FunctionDecl
modifier|*
name|FD
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|CheckConstexprFunctionBody
parameter_list|(
specifier|const
name|FunctionDecl
modifier|*
name|FD
parameter_list|,
name|Stmt
modifier|*
name|Body
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|DiagnoseHiddenVirtualMethods
parameter_list|(
name|CXXMethodDecl
modifier|*
name|MD
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
name|void
name|FindHiddenVirtualMethods
argument_list|(
name|CXXMethodDecl
operator|*
name|MD
argument_list|,
name|SmallVectorImpl
operator|<
name|CXXMethodDecl
operator|*
operator|>
operator|&
name|OverloadedMethods
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|NoteHiddenVirtualMethods
argument_list|(
name|CXXMethodDecl
operator|*
name|MD
argument_list|,
name|SmallVectorImpl
operator|<
name|CXXMethodDecl
operator|*
operator|>
operator|&
name|OverloadedMethods
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|// Returns true if the function declaration is a redeclaration
end_comment

begin_function_decl
name|bool
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
name|IsMemberSpecialization
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|shouldLinkDependentDeclWithPrevious
parameter_list|(
name|Decl
modifier|*
name|D
parameter_list|,
name|Decl
modifier|*
name|OldDecl
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
parameter_list|,
specifier|const
name|DeclSpec
modifier|&
name|D
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|CheckMSVCRTEntryPoint
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
parameter_list|,
name|SourceLocation
name|EqualLoc
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
name|ActOnPureSpecifier
parameter_list|(
name|Decl
modifier|*
name|D
parameter_list|,
name|SourceLocation
name|PureSpecLoc
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
name|StmtResult
name|ActOnCXXForRangeIdentifier
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
name|ParsedAttributes
modifier|&
name|Attrs
parameter_list|,
name|SourceLocation
name|AttrEnd
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
name|SetDeclDefaulted
parameter_list|(
name|Decl
modifier|*
name|dcl
parameter_list|,
name|SourceLocation
name|DefaultLoc
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

begin_decl_stmt
name|DeclGroupPtrTy
name|FinalizeDeclaratorGroup
argument_list|(
name|Scope
operator|*
name|S
argument_list|,
specifier|const
name|DeclSpec
operator|&
name|DS
argument_list|,
name|ArrayRef
operator|<
name|Decl
operator|*
operator|>
name|Group
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|DeclGroupPtrTy
name|BuildDeclaratorGroup
argument_list|(
name|MutableArrayRef
operator|<
name|Decl
operator|*
operator|>
name|Group
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// Should be called on all declarations that might have attached
end_comment

begin_comment
comment|/// documentation comments.
end_comment

begin_function_decl
name|void
name|ActOnDocumentableDecl
parameter_list|(
name|Decl
modifier|*
name|D
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
name|void
name|ActOnDocumentableDecls
argument_list|(
name|ArrayRef
operator|<
name|Decl
operator|*
operator|>
name|Group
argument_list|)
decl_stmt|;
end_decl_stmt

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
parameter_list|,
specifier|const
name|FunctionDecl
modifier|*
name|EffectiveDefinition
init|=
name|nullptr
parameter_list|,
name|SkipBodyInfo
modifier|*
name|SkipBody
init|=
name|nullptr
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
parameter_list|,
name|MultiTemplateParamsArg
name|TemplateParamLists
parameter_list|,
name|SkipBodyInfo
modifier|*
name|SkipBody
init|=
name|nullptr
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
parameter_list|,
name|SkipBodyInfo
modifier|*
name|SkipBody
init|=
name|nullptr
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

begin_function
name|bool
name|isObjCMethodDecl
parameter_list|(
name|Decl
modifier|*
name|D
parameter_list|)
block|{
return|return
name|D
operator|&&
name|isa
operator|<
name|ObjCMethodDecl
operator|>
operator|(
name|D
operator|)
return|;
block|}
end_function

begin_comment
comment|/// \brief Determine whether we can delay parsing the body of a function or
end_comment

begin_comment
comment|/// function template until it is used, assuming we don't care about emitting
end_comment

begin_comment
comment|/// code for that function.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This will be \c false if we may need the body of the function in the
end_comment

begin_comment
comment|/// middle of parsing an expression (where it's impractical to switch to
end_comment

begin_comment
comment|/// parsing a different function), for instance, if it's constexpr in C++11
end_comment

begin_comment
comment|/// or has an 'auto' return type in C++14. These cases are essentially bugs.
end_comment

begin_function_decl
name|bool
name|canDelayFunctionBody
parameter_list|(
specifier|const
name|Declarator
modifier|&
name|D
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// \brief Determine whether we can skip parsing the body of a function
end_comment

begin_comment
comment|/// definition, assuming we don't care about analyzing its body or emitting
end_comment

begin_comment
comment|/// code for that function.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This will be \c false only if we may need the body of the function in
end_comment

begin_comment
comment|/// order to parse the rest of the program (for instance, if it is
end_comment

begin_comment
comment|/// \c constexpr in C++11 or has an 'auto' return type in C++14).
end_comment

begin_function_decl
name|bool
name|canSkipFunctionBody
parameter_list|(
name|Decl
modifier|*
name|D
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
name|void
name|computeNRVO
argument_list|(
name|Stmt
operator|*
name|Body
argument_list|,
name|sema
operator|::
name|FunctionScopeInfo
operator|*
name|Scope
argument_list|)
decl_stmt|;
end_decl_stmt

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

begin_function_decl
name|Decl
modifier|*
name|ActOnSkippedFunctionBody
parameter_list|(
name|Decl
modifier|*
name|Decl
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ActOnFinishInlineFunctionDef
parameter_list|(
name|FunctionDecl
modifier|*
name|D
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// ActOnFinishDelayedAttribute - Invoked when we have finished parsing an
end_comment

begin_comment
comment|/// attribute for which parsing is delayed.
end_comment

begin_function_decl
name|void
name|ActOnFinishDelayedAttribute
parameter_list|(
name|Scope
modifier|*
name|S
parameter_list|,
name|Decl
modifier|*
name|D
parameter_list|,
name|ParsedAttributes
modifier|&
name|Attrs
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// \brief Diagnose any unused parameters in the given sequence of
end_comment

begin_comment
comment|/// ParmVarDecl pointers.
end_comment

begin_decl_stmt
name|void
name|DiagnoseUnusedParameters
argument_list|(
name|ArrayRef
operator|<
name|ParmVarDecl
operator|*
operator|>
name|Parameters
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// \brief Diagnose whether the size of parameters or return value of a
end_comment

begin_comment
comment|/// function or obj-c method definition is pass-by-value and larger than a
end_comment

begin_comment
comment|/// specified threshold.
end_comment

begin_decl_stmt
name|void
name|DiagnoseSizeOfParametersAndReturnValue
argument_list|(
name|ArrayRef
operator|<
name|ParmVarDecl
operator|*
operator|>
name|Parameters
argument_list|,
name|QualType
name|ReturnTy
argument_list|,
name|NamedDecl
operator|*
name|D
argument_list|)
decl_stmt|;
end_decl_stmt

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
comment|/// \brief Handle a C++11 empty-declaration and attribute-declaration.
end_comment

begin_function_decl
name|Decl
modifier|*
name|ActOnEmptyDeclaration
parameter_list|(
name|Scope
modifier|*
name|S
parameter_list|,
name|AttributeList
modifier|*
name|AttrList
parameter_list|,
name|SourceLocation
name|SemiLoc
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
name|enum
name|class
name|ModuleDeclKind
block|{
name|Module
operator|,
comment|///< 'module X;'
name|Partition
operator|,
comment|///< 'module partition X;'
name|Implementation
operator|,
comment|///< 'module implementation X;'
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|/// The parser has processed a module-declaration that begins the definition
end_comment

begin_comment
comment|/// of a module interface or implementation.
end_comment

begin_function_decl
name|DeclGroupPtrTy
name|ActOnModuleDecl
parameter_list|(
name|SourceLocation
name|StartLoc
parameter_list|,
name|SourceLocation
name|ModuleLoc
parameter_list|,
name|ModuleDeclKind
name|MDK
parameter_list|,
name|ModuleIdPath
name|Path
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// \brief The parser has processed a module import declaration.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param AtLoc The location of the '@' symbol, if any.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param ImportLoc The location of the 'import' keyword.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param Path The module access path.
end_comment

begin_function_decl
name|DeclResult
name|ActOnModuleImport
parameter_list|(
name|SourceLocation
name|AtLoc
parameter_list|,
name|SourceLocation
name|ImportLoc
parameter_list|,
name|ModuleIdPath
name|Path
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// \brief The parser has processed a module import translated from a
end_comment

begin_comment
comment|/// #include or similar preprocessing directive.
end_comment

begin_function_decl
name|void
name|ActOnModuleInclude
parameter_list|(
name|SourceLocation
name|DirectiveLoc
parameter_list|,
name|Module
modifier|*
name|Mod
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|BuildModuleInclude
parameter_list|(
name|SourceLocation
name|DirectiveLoc
parameter_list|,
name|Module
modifier|*
name|Mod
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// \brief The parsed has entered a submodule.
end_comment

begin_function_decl
name|void
name|ActOnModuleBegin
parameter_list|(
name|SourceLocation
name|DirectiveLoc
parameter_list|,
name|Module
modifier|*
name|Mod
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// \brief The parser has left a submodule.
end_comment

begin_function_decl
name|void
name|ActOnModuleEnd
parameter_list|(
name|SourceLocation
name|DirectiveLoc
parameter_list|,
name|Module
modifier|*
name|Mod
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// \brief Create an implicit import of the given module at the given
end_comment

begin_comment
comment|/// source location, for error recovery, if possible.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This routine is typically used when an entity found by name lookup
end_comment

begin_comment
comment|/// is actually hidden within a module that we know about but the user
end_comment

begin_comment
comment|/// has forgotten to import.
end_comment

begin_function_decl
name|void
name|createImplicitModuleImportForErrorRecovery
parameter_list|(
name|SourceLocation
name|Loc
parameter_list|,
name|Module
modifier|*
name|Mod
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// Kinds of missing import. Note, the values of these enumerators correspond
end_comment

begin_comment
comment|/// to %select values in diagnostics.
end_comment

begin_decl_stmt
name|enum
name|class
name|MissingImportKind
block|{
name|Declaration
operator|,
name|Definition
operator|,
name|DefaultArgument
operator|,
name|ExplicitSpecialization
operator|,
name|PartialSpecialization
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|/// \brief Diagnose that the specified declaration needs to be visible but
end_comment

begin_comment
comment|/// isn't, and suggest a module import that would resolve the problem.
end_comment

begin_function_decl
name|void
name|diagnoseMissingImport
parameter_list|(
name|SourceLocation
name|Loc
parameter_list|,
name|NamedDecl
modifier|*
name|Decl
parameter_list|,
name|MissingImportKind
name|MIK
parameter_list|,
name|bool
name|Recover
init|=
name|true
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
name|void
name|diagnoseMissingImport
argument_list|(
name|SourceLocation
name|Loc
argument_list|,
name|NamedDecl
operator|*
name|Decl
argument_list|,
name|SourceLocation
name|DeclLoc
argument_list|,
name|ArrayRef
operator|<
name|Module
operator|*
operator|>
name|Modules
argument_list|,
name|MissingImportKind
name|MIK
argument_list|,
name|bool
name|Recover
argument_list|)
decl_stmt|;
end_decl_stmt

begin_function_decl
name|Decl
modifier|*
name|ActOnStartExportDecl
parameter_list|(
name|Scope
modifier|*
name|S
parameter_list|,
name|SourceLocation
name|ExportLoc
parameter_list|,
name|SourceLocation
name|LBraceLoc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|Decl
modifier|*
name|ActOnFinishExportDecl
parameter_list|(
name|Scope
modifier|*
name|S
parameter_list|,
name|Decl
modifier|*
name|ExportDecl
parameter_list|,
name|SourceLocation
name|RBraceLoc
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// \brief We've found a use of a templated declaration that would trigger an
end_comment

begin_comment
comment|/// implicit instantiation. Check that any relevant explicit specializations
end_comment

begin_comment
comment|/// and partial specializations are visible, and diagnose if not.
end_comment

begin_function_decl
name|void
name|checkSpecializationVisibility
parameter_list|(
name|SourceLocation
name|Loc
parameter_list|,
name|NamedDecl
modifier|*
name|Spec
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// \brief We've found a use of a template specialization that would select a
end_comment

begin_comment
comment|/// partial specialization. Check that the partial specialization is visible,
end_comment

begin_comment
comment|/// and diagnose if not.
end_comment

begin_function_decl
name|void
name|checkPartialSpecializationVisibility
parameter_list|(
name|SourceLocation
name|Loc
parameter_list|,
name|NamedDecl
modifier|*
name|Spec
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// \brief Retrieve a suitable printing policy.
end_comment

begin_expr_stmt
name|PrintingPolicy
name|getPrintingPolicy
argument_list|()
specifier|const
block|{
return|return
name|getPrintingPolicy
argument_list|(
name|Context
argument_list|,
name|PP
argument_list|)
return|;
block|}
end_expr_stmt

begin_comment
comment|/// \brief Retrieve a suitable printing policy.
end_comment

begin_function_decl
specifier|static
name|PrintingPolicy
name|getPrintingPolicy
parameter_list|(
specifier|const
name|ASTContext
modifier|&
name|Ctx
parameter_list|,
specifier|const
name|Preprocessor
modifier|&
name|PP
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
parameter_list|,
name|RecordDecl
modifier|*
modifier|&
name|AnonRecord
parameter_list|)
function_decl|;
end_function_decl

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
parameter_list|,
name|MultiTemplateParamsArg
name|TemplateParams
parameter_list|,
name|bool
name|IsExplicitInstantiation
parameter_list|,
name|RecordDecl
modifier|*
modifier|&
name|AnonRecord
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
parameter_list|,
specifier|const
name|PrintingPolicy
modifier|&
name|Policy
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

begin_comment
comment|/// Common ways to introduce type names without a tag for use in diagnostics.
end_comment

begin_comment
comment|/// Keep in sync with err_tag_reference_non_tag.
end_comment

begin_enum
enum|enum
name|NonTagKind
block|{
name|NTK_NonStruct
block|,
name|NTK_NonClass
block|,
name|NTK_NonUnion
block|,
name|NTK_NonEnum
block|,
name|NTK_Typedef
block|,
name|NTK_TypeAlias
block|,
name|NTK_Template
block|,
name|NTK_TypeAliasTemplate
block|,
name|NTK_TemplateTemplateArgument
block|,   }
enum|;
end_enum

begin_comment
comment|/// Given a non-tag type declaration, returns an enum useful for indicating
end_comment

begin_comment
comment|/// what kind of non-tag type this is.
end_comment

begin_function_decl
name|NonTagKind
name|getNonTagTypeDeclKind
parameter_list|(
specifier|const
name|Decl
modifier|*
name|D
parameter_list|,
name|TagTypeKind
name|TTK
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
name|bool
name|isDefinition
parameter_list|,
name|SourceLocation
name|NewTagLoc
parameter_list|,
specifier|const
name|IdentifierInfo
modifier|*
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
name|SourceLocation
name|ModulePrivateLoc
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
name|SourceLocation
name|ScopedEnumKWLoc
parameter_list|,
name|bool
name|ScopedEnumUsesClassTag
parameter_list|,
name|TypeResult
name|UnderlyingType
parameter_list|,
name|bool
name|IsTypeSpecifier
parameter_list|,
name|SkipBodyInfo
modifier|*
name|SkipBody
init|=
name|nullptr
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
name|InClassInitStyle
name|InitStyle
parameter_list|,
name|AccessSpecifier
name|AS
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|MSPropertyDecl
modifier|*
name|HandleMSProperty
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
name|InClassInitStyle
name|InitStyle
parameter_list|,
name|AccessSpecifier
name|AS
parameter_list|,
name|AttributeList
modifier|*
name|MSPropertyAttr
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
name|InClassInitStyle
name|InitStyle
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
name|nullptr
parameter_list|)
function_decl|;
end_function_decl

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
name|CXXRecordDecl
modifier|*
name|Record
parameter_list|,
name|CXXSpecialMember
name|CSM
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|SpecialMemberIsTrivial
parameter_list|(
name|CXXMethodDecl
modifier|*
name|MD
parameter_list|,
name|CXXSpecialMember
name|CSM
parameter_list|,
name|bool
name|Diagnose
init|=
name|false
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

begin_decl_stmt
name|void
name|ActOnFields
argument_list|(
name|Scope
operator|*
name|S
argument_list|,
name|SourceLocation
name|RecLoc
argument_list|,
name|Decl
operator|*
name|TagDecl
argument_list|,
name|ArrayRef
operator|<
name|Decl
operator|*
operator|>
name|Fields
argument_list|,
name|SourceLocation
name|LBrac
argument_list|,
name|SourceLocation
name|RBrac
argument_list|,
name|AttributeList
operator|*
name|AttrList
argument_list|)
decl_stmt|;
end_decl_stmt

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

begin_typedef
typedef|typedef
name|void
modifier|*
name|SkippedDefinitionContext
typedef|;
end_typedef

begin_comment
comment|/// \brief Invoked when we enter a tag definition that we're skipping.
end_comment

begin_function_decl
name|SkippedDefinitionContext
name|ActOnTagStartSkippedDefinition
parameter_list|(
name|Scope
modifier|*
name|S
parameter_list|,
name|Decl
modifier|*
name|TD
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|Decl
modifier|*
name|ActOnObjCContainerStartDefinition
parameter_list|(
name|Decl
modifier|*
name|IDecl
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
name|bool
name|IsFinalSpelledSealed
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
name|SourceRange
name|BraceRange
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ActOnTagFinishSkippedDefinition
parameter_list|(
name|SkippedDefinitionContext
name|Context
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ActOnObjCContainerFinishDefinition
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/// \brief Invoked when we must temporarily exit the objective-c container
end_comment

begin_comment
comment|/// scope for parsing/looking-up C constructs.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Must be followed by a call to \see ActOnObjCReenterContainerContext
end_comment

begin_function_decl
name|void
name|ActOnObjCTemporaryExitContainerContext
parameter_list|(
name|DeclContext
modifier|*
name|DC
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ActOnObjCReenterContainerContext
parameter_list|(
name|DeclContext
modifier|*
name|DC
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
name|bool
name|CheckEnumUnderlyingType
parameter_list|(
name|TypeSourceInfo
modifier|*
name|TI
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|CheckEnumRedeclaration
parameter_list|(
name|SourceLocation
name|EnumLoc
parameter_list|,
name|bool
name|IsScoped
parameter_list|,
name|QualType
name|EnumUnderlyingTy
parameter_list|,
name|bool
name|EnumUnderlyingIsImplicit
parameter_list|,
specifier|const
name|EnumDecl
modifier|*
name|Prev
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// Determine whether the body of an anonymous enumeration should be skipped.
end_comment

begin_comment
comment|/// \param II The name of the first enumerator.
end_comment

begin_function_decl
name|SkipBodyInfo
name|shouldSkipAnonEnumBody
parameter_list|(
name|Scope
modifier|*
name|S
parameter_list|,
name|IdentifierInfo
modifier|*
name|II
parameter_list|,
name|SourceLocation
name|IILoc
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

begin_decl_stmt
name|void
name|ActOnEnumBody
argument_list|(
name|SourceLocation
name|EnumLoc
argument_list|,
name|SourceRange
name|BraceRange
argument_list|,
name|Decl
operator|*
name|EnumDecl
argument_list|,
name|ArrayRef
operator|<
name|Decl
operator|*
operator|>
name|Elements
argument_list|,
name|Scope
operator|*
name|S
argument_list|,
name|AttributeList
operator|*
name|Attr
argument_list|)
decl_stmt|;
end_decl_stmt

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

begin_comment
comment|/// Push the parameters of D, which must be a function, into scope.
end_comment

begin_function_decl
name|void
name|ActOnReenterFunctionContext
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
name|ActOnExitFunctionContext
parameter_list|()
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
comment|/// \brief Make the given externally-produced declaration visible at the
end_comment

begin_comment
comment|/// top level scope.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param D The externally-produced declaration to push.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param Name The name of the externally-produced declaration.
end_comment

begin_function_decl
name|void
name|pushExternalDeclIntoScope
parameter_list|(
name|NamedDecl
modifier|*
name|D
parameter_list|,
name|DeclarationName
name|Name
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
comment|/// \param AllowInlineNamespace If \c true, allow the declaration to be in the
end_comment

begin_comment
comment|///        enclosing namespace set of the context, rather than contained
end_comment

begin_comment
comment|///        directly within it.
end_comment

begin_function_decl
name|bool
name|isDeclInScope
parameter_list|(
name|NamedDecl
modifier|*
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
name|nullptr
parameter_list|,
name|bool
name|AllowInlineNamespace
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
name|bool
name|isIncompatibleTypedef
parameter_list|(
name|TypeDecl
modifier|*
name|Old
parameter_list|,
name|TypedefNameDecl
modifier|*
name|New
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// \brief Describes the kind of merge to perform for availability
end_comment

begin_comment
comment|/// attributes (including "deprecated", "unavailable", and "availability").
end_comment

begin_enum
enum|enum
name|AvailabilityMergeKind
block|{
comment|/// \brief Don't merge availability attributes at all.
name|AMK_None
block|,
comment|/// \brief Merge availability attributes for a redeclaration, which requires
comment|/// an exact match.
name|AMK_Redeclaration
block|,
comment|/// \brief Merge availability attributes for an override, which requires
comment|/// an exact match or a weakening of constraints.
name|AMK_Override
block|,
comment|/// \brief Merge availability attributes for an implementation of
comment|/// a protocol requirement.
name|AMK_ProtocolImplementation
block|,   }
enum|;
end_enum

begin_comment
comment|/// Attribute merging methods. Return true if a new attribute was added.
end_comment

begin_function_decl
name|AvailabilityAttr
modifier|*
name|mergeAvailabilityAttr
parameter_list|(
name|NamedDecl
modifier|*
name|D
parameter_list|,
name|SourceRange
name|Range
parameter_list|,
name|IdentifierInfo
modifier|*
name|Platform
parameter_list|,
name|bool
name|Implicit
parameter_list|,
name|VersionTuple
name|Introduced
parameter_list|,
name|VersionTuple
name|Deprecated
parameter_list|,
name|VersionTuple
name|Obsoleted
parameter_list|,
name|bool
name|IsUnavailable
parameter_list|,
name|StringRef
name|Message
parameter_list|,
name|bool
name|IsStrict
parameter_list|,
name|StringRef
name|Replacement
parameter_list|,
name|AvailabilityMergeKind
name|AMK
parameter_list|,
name|unsigned
name|AttrSpellingListIndex
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
name|TypeVisibilityAttr
modifier|*
name|mergeTypeVisibilityAttr
argument_list|(
name|Decl
operator|*
name|D
argument_list|,
name|SourceRange
name|Range
argument_list|,
name|TypeVisibilityAttr
operator|::
name|VisibilityType
name|Vis
argument_list|,
name|unsigned
name|AttrSpellingListIndex
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|VisibilityAttr
modifier|*
name|mergeVisibilityAttr
argument_list|(
name|Decl
operator|*
name|D
argument_list|,
name|SourceRange
name|Range
argument_list|,
name|VisibilityAttr
operator|::
name|VisibilityType
name|Vis
argument_list|,
name|unsigned
name|AttrSpellingListIndex
argument_list|)
decl_stmt|;
end_decl_stmt

begin_function_decl
name|UuidAttr
modifier|*
name|mergeUuidAttr
parameter_list|(
name|Decl
modifier|*
name|D
parameter_list|,
name|SourceRange
name|Range
parameter_list|,
name|unsigned
name|AttrSpellingListIndex
parameter_list|,
name|StringRef
name|Uuid
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|DLLImportAttr
modifier|*
name|mergeDLLImportAttr
parameter_list|(
name|Decl
modifier|*
name|D
parameter_list|,
name|SourceRange
name|Range
parameter_list|,
name|unsigned
name|AttrSpellingListIndex
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|DLLExportAttr
modifier|*
name|mergeDLLExportAttr
parameter_list|(
name|Decl
modifier|*
name|D
parameter_list|,
name|SourceRange
name|Range
parameter_list|,
name|unsigned
name|AttrSpellingListIndex
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
name|MSInheritanceAttr
modifier|*
name|mergeMSInheritanceAttr
argument_list|(
name|Decl
operator|*
name|D
argument_list|,
name|SourceRange
name|Range
argument_list|,
name|bool
name|BestCase
argument_list|,
name|unsigned
name|AttrSpellingListIndex
argument_list|,
name|MSInheritanceAttr
operator|::
name|Spelling
name|SemanticSpelling
argument_list|)
decl_stmt|;
end_decl_stmt

begin_function_decl
name|FormatAttr
modifier|*
name|mergeFormatAttr
parameter_list|(
name|Decl
modifier|*
name|D
parameter_list|,
name|SourceRange
name|Range
parameter_list|,
name|IdentifierInfo
modifier|*
name|Format
parameter_list|,
name|int
name|FormatIdx
parameter_list|,
name|int
name|FirstArg
parameter_list|,
name|unsigned
name|AttrSpellingListIndex
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|SectionAttr
modifier|*
name|mergeSectionAttr
parameter_list|(
name|Decl
modifier|*
name|D
parameter_list|,
name|SourceRange
name|Range
parameter_list|,
name|StringRef
name|Name
parameter_list|,
name|unsigned
name|AttrSpellingListIndex
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|AlwaysInlineAttr
modifier|*
name|mergeAlwaysInlineAttr
parameter_list|(
name|Decl
modifier|*
name|D
parameter_list|,
name|SourceRange
name|Range
parameter_list|,
name|IdentifierInfo
modifier|*
name|Ident
parameter_list|,
name|unsigned
name|AttrSpellingListIndex
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|MinSizeAttr
modifier|*
name|mergeMinSizeAttr
parameter_list|(
name|Decl
modifier|*
name|D
parameter_list|,
name|SourceRange
name|Range
parameter_list|,
name|unsigned
name|AttrSpellingListIndex
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|OptimizeNoneAttr
modifier|*
name|mergeOptimizeNoneAttr
parameter_list|(
name|Decl
modifier|*
name|D
parameter_list|,
name|SourceRange
name|Range
parameter_list|,
name|unsigned
name|AttrSpellingListIndex
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|InternalLinkageAttr
modifier|*
name|mergeInternalLinkageAttr
parameter_list|(
name|Decl
modifier|*
name|D
parameter_list|,
name|SourceRange
name|Range
parameter_list|,
name|IdentifierInfo
modifier|*
name|Ident
parameter_list|,
name|unsigned
name|AttrSpellingListIndex
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|CommonAttr
modifier|*
name|mergeCommonAttr
parameter_list|(
name|Decl
modifier|*
name|D
parameter_list|,
name|SourceRange
name|Range
parameter_list|,
name|IdentifierInfo
modifier|*
name|Ident
parameter_list|,
name|unsigned
name|AttrSpellingListIndex
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|mergeDeclAttributes
parameter_list|(
name|NamedDecl
modifier|*
name|New
parameter_list|,
name|Decl
modifier|*
name|Old
parameter_list|,
name|AvailabilityMergeKind
name|AMK
init|=
name|AMK_Redeclaration
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|MergeTypedefNameDecl
parameter_list|(
name|Scope
modifier|*
name|S
parameter_list|,
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
name|NamedDecl
modifier|*
modifier|&
name|Old
parameter_list|,
name|Scope
modifier|*
name|S
parameter_list|,
name|bool
name|MergeTypeWithOld
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
parameter_list|,
name|Scope
modifier|*
name|S
parameter_list|,
name|bool
name|MergeTypeWithOld
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
name|Previous
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
parameter_list|,
name|bool
name|MergeTypeWithOld
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
name|checkVarDeclRedefinition
parameter_list|(
name|VarDecl
modifier|*
name|OldDefn
parameter_list|,
name|VarDecl
modifier|*
name|NewDefn
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|notePreviousDefinition
parameter_list|(
name|SourceLocation
name|Old
parameter_list|,
name|SourceLocation
name|New
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
parameter_list|,
name|Scope
modifier|*
name|S
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
block|,
name|AA_Passing_CFAudited
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
parameter_list|,
name|bool
name|ConsiderCudaAttrs
init|=
name|true
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// \brief Checks availability of the function depending on the current
end_comment

begin_comment
comment|/// function context.Inside an unavailable function,unavailability is ignored.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \returns true if \p FD is unavailable and current context is inside
end_comment

begin_comment
comment|/// an available function, false otherwise.
end_comment

begin_function_decl
name|bool
name|isFunctionConsideredUnavailable
parameter_list|(
name|FunctionDecl
modifier|*
name|FD
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
parameter_list|,
name|bool
name|CStyle
parameter_list|,
name|bool
name|AllowObjCWritebackConversion
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
name|isObjCWritebackConversion
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
name|FunctionParamTypesAreEqual
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
parameter_list|,
name|unsigned
modifier|*
name|ArgPos
init|=
name|nullptr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|HandleFunctionTypeMismatch
parameter_list|(
name|PartialDiagnostic
modifier|&
name|PDiag
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
name|void
name|maybeExtendBlockObject
parameter_list|(
name|ExprResult
modifier|&
name|E
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|CastKind
name|PrepareCastToObjCObjectPointer
parameter_list|(
name|ExprResult
modifier|&
name|E
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
parameter_list|,
name|bool
name|Diagnose
init|=
name|true
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
parameter_list|,
name|bool
modifier|&
name|ObjCLifetimeConversion
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|IsFunctionConversion
parameter_list|(
name|QualType
name|FromType
parameter_list|,
name|QualType
name|ToType
parameter_list|,
name|QualType
modifier|&
name|ResultTy
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
name|bool
name|isSameOrCompatibleFunctionType
parameter_list|(
name|CanQualType
name|Param
parameter_list|,
name|CanQualType
name|Arg
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
parameter_list|,
name|bool
name|AllowNRVO
init|=
name|true
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|CanPerformCopyInitialization
parameter_list|(
specifier|const
name|InitializedEntity
modifier|&
name|Entity
parameter_list|,
name|ExprResult
name|Init
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
parameter_list|,
name|bool
name|TopLevelOfInitList
init|=
name|false
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
name|PerformContextuallyConvertToObjCPointer
parameter_list|(
name|Expr
modifier|*
name|From
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// Contexts in which a converted constant expression is required.
end_comment

begin_enum
enum|enum
name|CCEKind
block|{
name|CCEK_CaseValue
block|,
comment|///< Expression in a case label.
name|CCEK_Enumerator
block|,
comment|///< Enumerator value with fixed underlying type.
name|CCEK_TemplateArg
block|,
comment|///< Value of a non-type template parameter.
name|CCEK_NewExpr
block|,
comment|///< Constant expression in a noptr-new-declarator.
name|CCEK_ConstexprIf
comment|///< Condition in a constexpr if statement.
block|}
enum|;
end_enum

begin_decl_stmt
name|ExprResult
name|CheckConvertedConstantExpression
argument_list|(
name|Expr
operator|*
name|From
argument_list|,
name|QualType
name|T
argument_list|,
name|llvm
operator|::
name|APSInt
operator|&
name|Value
argument_list|,
name|CCEKind
name|CCE
argument_list|)
decl_stmt|;
end_decl_stmt

begin_function_decl
name|ExprResult
name|CheckConvertedConstantExpression
parameter_list|(
name|Expr
modifier|*
name|From
parameter_list|,
name|QualType
name|T
parameter_list|,
name|APValue
modifier|&
name|Value
parameter_list|,
name|CCEKind
name|CCE
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// \brief Abstract base class used to perform a contextual implicit
end_comment

begin_comment
comment|/// conversion from an expression to any type passing a filter.
end_comment

begin_decl_stmt
name|class
name|ContextualImplicitConverter
block|{
name|public
label|:
name|bool
name|Suppress
decl_stmt|;
name|bool
name|SuppressConversion
decl_stmt|;
name|ContextualImplicitConverter
argument_list|(
argument|bool Suppress = false
argument_list|,
argument|bool SuppressConversion = false
argument_list|)
block|:
name|Suppress
argument_list|(
name|Suppress
argument_list|)
operator|,
name|SuppressConversion
argument_list|(
argument|SuppressConversion
argument_list|)
block|{}
comment|/// \brief Determine whether the specified type is a valid destination type
comment|/// for this conversion.
name|virtual
name|bool
name|match
argument_list|(
argument|QualType T
argument_list|)
operator|=
literal|0
expr_stmt|;
comment|/// \brief Emits a diagnostic complaining that the expression does not have
comment|/// integral or enumeration type.
name|virtual
name|SemaDiagnosticBuilder
name|diagnoseNoMatch
parameter_list|(
name|Sema
modifier|&
name|S
parameter_list|,
name|SourceLocation
name|Loc
parameter_list|,
name|QualType
name|T
parameter_list|)
init|=
literal|0
function_decl|;
comment|/// \brief Emits a diagnostic when the expression has incomplete class type.
name|virtual
name|SemaDiagnosticBuilder
name|diagnoseIncomplete
parameter_list|(
name|Sema
modifier|&
name|S
parameter_list|,
name|SourceLocation
name|Loc
parameter_list|,
name|QualType
name|T
parameter_list|)
init|=
literal|0
function_decl|;
comment|/// \brief Emits a diagnostic when the only matching conversion function
comment|/// is explicit.
name|virtual
name|SemaDiagnosticBuilder
name|diagnoseExplicitConv
parameter_list|(
name|Sema
modifier|&
name|S
parameter_list|,
name|SourceLocation
name|Loc
parameter_list|,
name|QualType
name|T
parameter_list|,
name|QualType
name|ConvTy
parameter_list|)
init|=
literal|0
function_decl|;
comment|/// \brief Emits a note for the explicit conversion function.
name|virtual
name|SemaDiagnosticBuilder
name|noteExplicitConv
parameter_list|(
name|Sema
modifier|&
name|S
parameter_list|,
name|CXXConversionDecl
modifier|*
name|Conv
parameter_list|,
name|QualType
name|ConvTy
parameter_list|)
init|=
literal|0
function_decl|;
comment|/// \brief Emits a diagnostic when there are multiple possible conversion
comment|/// functions.
name|virtual
name|SemaDiagnosticBuilder
name|diagnoseAmbiguous
parameter_list|(
name|Sema
modifier|&
name|S
parameter_list|,
name|SourceLocation
name|Loc
parameter_list|,
name|QualType
name|T
parameter_list|)
init|=
literal|0
function_decl|;
comment|/// \brief Emits a note for one of the candidate conversions.
name|virtual
name|SemaDiagnosticBuilder
name|noteAmbiguous
parameter_list|(
name|Sema
modifier|&
name|S
parameter_list|,
name|CXXConversionDecl
modifier|*
name|Conv
parameter_list|,
name|QualType
name|ConvTy
parameter_list|)
init|=
literal|0
function_decl|;
comment|/// \brief Emits a diagnostic when we picked a conversion function
comment|/// (for cases when we are not allowed to pick a conversion function).
name|virtual
name|SemaDiagnosticBuilder
name|diagnoseConversion
parameter_list|(
name|Sema
modifier|&
name|S
parameter_list|,
name|SourceLocation
name|Loc
parameter_list|,
name|QualType
name|T
parameter_list|,
name|QualType
name|ConvTy
parameter_list|)
init|=
literal|0
function_decl|;
name|virtual
operator|~
name|ContextualImplicitConverter
argument_list|()
block|{}
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_decl_stmt
name|class
name|ICEConvertDiagnoser
range|:
name|public
name|ContextualImplicitConverter
block|{
name|bool
name|AllowScopedEnumerations
block|;
name|public
operator|:
name|ICEConvertDiagnoser
argument_list|(
argument|bool AllowScopedEnumerations
argument_list|,
argument|bool Suppress
argument_list|,
argument|bool SuppressConversion
argument_list|)
operator|:
name|ContextualImplicitConverter
argument_list|(
name|Suppress
argument_list|,
name|SuppressConversion
argument_list|)
block|,
name|AllowScopedEnumerations
argument_list|(
argument|AllowScopedEnumerations
argument_list|)
block|{}
comment|/// Match an integral or (possibly scoped) enumeration type.
name|bool
name|match
argument_list|(
argument|QualType T
argument_list|)
name|override
block|;
name|SemaDiagnosticBuilder
name|diagnoseNoMatch
argument_list|(
argument|Sema&S
argument_list|,
argument|SourceLocation Loc
argument_list|,
argument|QualType T
argument_list|)
name|override
block|{
return|return
name|diagnoseNotInt
argument_list|(
name|S
argument_list|,
name|Loc
argument_list|,
name|T
argument_list|)
return|;
block|}
comment|/// \brief Emits a diagnostic complaining that the expression does not have
comment|/// integral or enumeration type.
name|virtual
name|SemaDiagnosticBuilder
name|diagnoseNotInt
argument_list|(
argument|Sema&S
argument_list|,
argument|SourceLocation Loc
argument_list|,
argument|QualType T
argument_list|)
operator|=
literal|0
block|;   }
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// Perform a contextual implicit conversion.
end_comment

begin_function_decl
name|ExprResult
name|PerformContextualImplicitConversion
parameter_list|(
name|SourceLocation
name|Loc
parameter_list|,
name|Expr
modifier|*
name|FromE
parameter_list|,
name|ContextualImplicitConverter
modifier|&
name|Converter
parameter_list|)
function_decl|;
end_function_decl

begin_enum
enum|enum
name|ObjCSubscriptKind
block|{
name|OS_Array
block|,
name|OS_Dictionary
block|,
name|OS_Error
block|}
enum|;
end_enum

begin_function_decl
name|ObjCSubscriptKind
name|CheckSubscriptingKind
parameter_list|(
name|Expr
modifier|*
name|FromE
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|// Note that LK_String is intentionally after the other literals, as
end_comment

begin_comment
comment|// this is used for diagnostics logic.
end_comment

begin_enum
enum|enum
name|ObjCLiteralKind
block|{
name|LK_Array
block|,
name|LK_Dictionary
block|,
name|LK_Numeric
block|,
name|LK_Boxed
block|,
name|LK_String
block|,
name|LK_Block
block|,
name|LK_None
block|}
enum|;
end_enum

begin_function_decl
name|ObjCLiteralKind
name|CheckLiteralKind
parameter_list|(
name|Expr
modifier|*
name|FromE
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
name|SmallSetVector
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
name|SmallSetVector
operator|<
name|CXXRecordDecl
operator|*
operator|,
literal|16
operator|>
name|AssociatedClassSet
expr_stmt|;
end_typedef

begin_decl_stmt
name|void
name|AddOverloadCandidate
argument_list|(
name|FunctionDecl
operator|*
name|Function
argument_list|,
name|DeclAccessPair
name|FoundDecl
argument_list|,
name|ArrayRef
operator|<
name|Expr
operator|*
operator|>
name|Args
argument_list|,
name|OverloadCandidateSet
operator|&
name|CandidateSet
argument_list|,
name|bool
name|SuppressUserConversions
operator|=
name|false
argument_list|,
name|bool
name|PartialOverloading
operator|=
name|false
argument_list|,
name|bool
name|AllowExplicit
operator|=
name|false
argument_list|,
name|ConversionSequenceList
name|EarlyConversions
operator|=
name|None
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|AddFunctionCandidates
argument_list|(
specifier|const
name|UnresolvedSetImpl
operator|&
name|Functions
argument_list|,
name|ArrayRef
operator|<
name|Expr
operator|*
operator|>
name|Args
argument_list|,
name|OverloadCandidateSet
operator|&
name|CandidateSet
argument_list|,
name|TemplateArgumentListInfo
operator|*
name|ExplicitTemplateArgs
operator|=
name|nullptr
argument_list|,
name|bool
name|SuppressUserConversions
operator|=
name|false
argument_list|,
name|bool
name|PartialOverloading
operator|=
name|false
argument_list|)
decl_stmt|;
end_decl_stmt

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
name|ArrayRef
operator|<
name|Expr
operator|*
operator|>
name|Args
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
name|ArrayRef
operator|<
name|Expr
operator|*
operator|>
name|Args
argument_list|,
name|OverloadCandidateSet
operator|&
name|CandidateSet
argument_list|,
name|bool
name|SuppressUserConversions
operator|=
name|false
argument_list|,
name|bool
name|PartialOverloading
operator|=
name|false
argument_list|,
name|ConversionSequenceList
name|EarlyConversions
operator|=
name|None
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
name|ArrayRef
operator|<
name|Expr
operator|*
operator|>
name|Args
argument_list|,
name|OverloadCandidateSet
operator|&
name|CandidateSet
argument_list|,
name|bool
name|SuppressUserConversions
operator|=
name|false
argument_list|,
name|bool
name|PartialOverloading
operator|=
name|false
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|AddTemplateOverloadCandidate
argument_list|(
name|FunctionTemplateDecl
operator|*
name|FunctionTemplate
argument_list|,
name|DeclAccessPair
name|FoundDecl
argument_list|,
name|TemplateArgumentListInfo
operator|*
name|ExplicitTemplateArgs
argument_list|,
name|ArrayRef
operator|<
name|Expr
operator|*
operator|>
name|Args
argument_list|,
name|OverloadCandidateSet
operator|&
name|CandidateSet
argument_list|,
name|bool
name|SuppressUserConversions
operator|=
name|false
argument_list|,
name|bool
name|PartialOverloading
operator|=
name|false
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|bool
name|CheckNonDependentConversions
argument_list|(
name|FunctionTemplateDecl
operator|*
name|FunctionTemplate
argument_list|,
name|ArrayRef
operator|<
name|QualType
operator|>
name|ParamTypes
argument_list|,
name|ArrayRef
operator|<
name|Expr
operator|*
operator|>
name|Args
argument_list|,
name|OverloadCandidateSet
operator|&
name|CandidateSet
argument_list|,
name|ConversionSequenceList
operator|&
name|Conversions
argument_list|,
name|bool
name|SuppressUserConversions
argument_list|,
name|CXXRecordDecl
operator|*
name|ActingContext
operator|=
name|nullptr
argument_list|,
name|QualType
name|ObjectType
operator|=
name|QualType
argument_list|()
argument_list|,
name|Expr
operator|::
name|Classification
name|ObjectClassification
operator|=
block|{}
argument_list|)
decl_stmt|;
end_decl_stmt

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
parameter_list|,
name|bool
name|AllowObjCConversionOnExplicit
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
parameter_list|,
name|bool
name|AllowObjCConversionOnExplicit
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
name|void
name|AddSurrogateCandidate
argument_list|(
name|CXXConversionDecl
operator|*
name|Conversion
argument_list|,
name|DeclAccessPair
name|FoundDecl
argument_list|,
name|CXXRecordDecl
operator|*
name|ActingContext
argument_list|,
specifier|const
name|FunctionProtoType
operator|*
name|Proto
argument_list|,
name|Expr
operator|*
name|Object
argument_list|,
name|ArrayRef
operator|<
name|Expr
operator|*
operator|>
name|Args
argument_list|,
name|OverloadCandidateSet
operator|&
name|CandidateSet
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|AddMemberOperatorCandidates
argument_list|(
name|OverloadedOperatorKind
name|Op
argument_list|,
name|SourceLocation
name|OpLoc
argument_list|,
name|ArrayRef
operator|<
name|Expr
operator|*
operator|>
name|Args
argument_list|,
name|OverloadCandidateSet
operator|&
name|CandidateSet
argument_list|,
name|SourceRange
name|OpRange
operator|=
name|SourceRange
argument_list|()
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|AddBuiltinCandidate
argument_list|(
name|QualType
name|ResultTy
argument_list|,
name|QualType
operator|*
name|ParamTys
argument_list|,
name|ArrayRef
operator|<
name|Expr
operator|*
operator|>
name|Args
argument_list|,
name|OverloadCandidateSet
operator|&
name|CandidateSet
argument_list|,
name|bool
name|IsAssignmentOperator
operator|=
name|false
argument_list|,
name|unsigned
name|NumContextualBoolArguments
operator|=
literal|0
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|AddBuiltinOperatorCandidates
argument_list|(
name|OverloadedOperatorKind
name|Op
argument_list|,
name|SourceLocation
name|OpLoc
argument_list|,
name|ArrayRef
operator|<
name|Expr
operator|*
operator|>
name|Args
argument_list|,
name|OverloadCandidateSet
operator|&
name|CandidateSet
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|AddArgumentDependentLookupCandidates
argument_list|(
name|DeclarationName
name|Name
argument_list|,
name|SourceLocation
name|Loc
argument_list|,
name|ArrayRef
operator|<
name|Expr
operator|*
operator|>
name|Args
argument_list|,
name|TemplateArgumentListInfo
operator|*
name|ExplicitTemplateArgs
argument_list|,
name|OverloadCandidateSet
operator|&
name|CandidateSet
argument_list|,
name|bool
name|PartialOverloading
operator|=
name|false
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|// Emit as a 'note' the specific overload candidate
end_comment

begin_function_decl
name|void
name|NoteOverloadCandidate
parameter_list|(
name|NamedDecl
modifier|*
name|Found
parameter_list|,
name|FunctionDecl
modifier|*
name|Fn
parameter_list|,
name|QualType
name|DestType
init|=
name|QualType
argument_list|()
parameter_list|,
name|bool
name|TakingAddress
init|=
name|false
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|// Emit as a series of 'note's all template and non-templates identified by
end_comment

begin_comment
comment|// the expression Expr
end_comment

begin_function_decl
name|void
name|NoteAllOverloadCandidates
parameter_list|(
name|Expr
modifier|*
name|E
parameter_list|,
name|QualType
name|DestType
init|=
name|QualType
argument_list|()
parameter_list|,
name|bool
name|TakingAddress
init|=
name|false
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// Check the enable_if expressions on the given function. Returns the first
end_comment

begin_comment
comment|/// failing attribute, or NULL if they were all successful.
end_comment

begin_decl_stmt
name|EnableIfAttr
modifier|*
name|CheckEnableIf
argument_list|(
name|FunctionDecl
operator|*
name|Function
argument_list|,
name|ArrayRef
operator|<
name|Expr
operator|*
operator|>
name|Args
argument_list|,
name|bool
name|MissingImplicitThis
operator|=
name|false
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// Emit diagnostics for the diagnose_if attributes on Function, ignoring any
end_comment

begin_comment
comment|/// non-ArgDependent DiagnoseIfAttrs.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Argument-dependent diagnose_if attributes should be checked each time a
end_comment

begin_comment
comment|/// function is used as a direct callee of a function call.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Returns true if any errors were emitted.
end_comment

begin_decl_stmt
name|bool
name|diagnoseArgDependentDiagnoseIfAttrs
argument_list|(
specifier|const
name|FunctionDecl
operator|*
name|Function
argument_list|,
specifier|const
name|Expr
operator|*
name|ThisArg
argument_list|,
name|ArrayRef
operator|<
specifier|const
name|Expr
operator|*
operator|>
name|Args
argument_list|,
name|SourceLocation
name|Loc
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// Emit diagnostics for the diagnose_if attributes on Function, ignoring any
end_comment

begin_comment
comment|/// ArgDependent DiagnoseIfAttrs.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Argument-independent diagnose_if attributes should be checked on every use
end_comment

begin_comment
comment|/// of a function.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Returns true if any errors were emitted.
end_comment

begin_function_decl
name|bool
name|diagnoseArgIndependentDiagnoseIfAttrs
parameter_list|(
specifier|const
name|FunctionDecl
modifier|*
name|Function
parameter_list|,
name|SourceLocation
name|Loc
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// Returns whether the given function's address can be taken or not,
end_comment

begin_comment
comment|/// optionally emitting a diagnostic if the address can't be taken.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Returns false if taking the address of the function is illegal.
end_comment

begin_function_decl
name|bool
name|checkAddressOfFunctionIsAvailable
parameter_list|(
specifier|const
name|FunctionDecl
modifier|*
name|Function
parameter_list|,
name|bool
name|Complain
init|=
name|false
parameter_list|,
name|SourceLocation
name|Loc
init|=
name|SourceLocation
argument_list|()
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
parameter_list|,
name|bool
modifier|*
name|pHadMultipleCandidates
init|=
name|nullptr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|FunctionDecl
modifier|*
name|resolveAddressOfOnlyViableOverloadCandidate
parameter_list|(
name|Expr
modifier|*
name|E
parameter_list|,
name|DeclAccessPair
modifier|&
name|FoundResult
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|resolveAndFixAddressOfOnlyViableOverloadCandidate
parameter_list|(
name|ExprResult
modifier|&
name|SrcExpr
parameter_list|,
name|bool
name|DoFunctionPointerConversion
init|=
name|false
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
name|nullptr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|ResolveAndFixSingleFunctionTemplateSpecialization
parameter_list|(
name|ExprResult
modifier|&
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
name|SourceRange
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

begin_decl_stmt
name|void
name|AddOverloadedCallCandidates
argument_list|(
name|UnresolvedLookupExpr
operator|*
name|ULE
argument_list|,
name|ArrayRef
operator|<
name|Expr
operator|*
operator|>
name|Args
argument_list|,
name|OverloadCandidateSet
operator|&
name|CandidateSet
argument_list|,
name|bool
name|PartialOverloading
operator|=
name|false
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|// An enum used to represent the different possible results of building a
end_comment

begin_comment
comment|// range-based for loop.
end_comment

begin_enum
enum|enum
name|ForRangeStatus
block|{
name|FRS_Success
block|,
name|FRS_NoViableFunction
block|,
name|FRS_DiagnosticIssued
block|}
enum|;
end_enum

begin_function_decl
name|ForRangeStatus
name|BuildForRangeBeginEndCall
parameter_list|(
name|SourceLocation
name|Loc
parameter_list|,
name|SourceLocation
name|RangeLoc
parameter_list|,
specifier|const
name|DeclarationNameInfo
modifier|&
name|NameInfo
parameter_list|,
name|LookupResult
modifier|&
name|MemberLookup
parameter_list|,
name|OverloadCandidateSet
modifier|*
name|CandidateSet
parameter_list|,
name|Expr
modifier|*
name|Range
parameter_list|,
name|ExprResult
modifier|*
name|CallExpr
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
name|MultiExprArg
name|Args
parameter_list|,
name|SourceLocation
name|RParenLoc
parameter_list|,
name|Expr
modifier|*
name|ExecConfig
parameter_list|,
name|bool
name|AllowTypoCorrection
init|=
name|true
parameter_list|,
name|bool
name|CalleesAddressIsTaken
init|=
name|false
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|buildOverloadedCallSet
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
name|MultiExprArg
name|Args
parameter_list|,
name|SourceLocation
name|RParenLoc
parameter_list|,
name|OverloadCandidateSet
modifier|*
name|CandidateSet
parameter_list|,
name|ExprResult
modifier|*
name|Result
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
name|UnaryOperatorKind
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
name|BinaryOperatorKind
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
name|MultiExprArg
name|Args
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
name|MultiExprArg
name|Args
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
parameter_list|,
name|bool
modifier|*
name|NoArrowOperatorFound
init|=
name|nullptr
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

begin_decl_stmt
name|bool
name|CheckParmsForFunctionDef
argument_list|(
name|ArrayRef
operator|<
name|ParmVarDecl
operator|*
operator|>
name|Parameters
argument_list|,
name|bool
name|CheckParameterNames
argument_list|)
decl_stmt|;
end_decl_stmt

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
comment|/// Look up a friend of a local class. This lookup does not look
comment|/// outside the innermost non-class scope. See C++11 [class.friend]p11.
name|LookupLocalFriendName
block|,
comment|/// Look up the name of an Objective-C protocol.
name|LookupObjCProtocolName
block|,
comment|/// Look up implicit 'self' parameter of an objective-c method.
name|LookupObjCImplicitSelfParam
block|,
comment|/// \brief Look up the name of an OpenMP user-defined reduction operation.
name|LookupOMPReductionName
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

begin_comment
comment|/// \brief The possible outcomes of name lookup for a literal operator.
end_comment

begin_enum
enum|enum
name|LiteralOperatorLookupResult
block|{
comment|/// \brief The lookup resulted in an error.
name|LOLR_Error
block|,
comment|/// \brief The lookup found a single 'cooked' literal operator, which
comment|/// expects a normal literal to be built and passed to it.
name|LOLR_Cooked
block|,
comment|/// \brief The lookup found a single 'raw' literal operator, which expects
comment|/// a string literal containing the spelling of the literal token.
name|LOLR_Raw
block|,
comment|/// \brief The lookup found an overload set of literal operator templates,
comment|/// which expect the characters of the spelling of the literal token to be
comment|/// passed as a non-type template argument pack.
name|LOLR_Template
block|,
comment|/// \brief The lookup found an overload set of literal operator templates,
comment|/// which expect the character type and characters of the spelling of the
comment|/// string literal token to be passed as template arguments.
name|LOLR_StringTemplate
block|}
enum|;
end_enum

begin_function_decl
name|SpecialMemberOverloadResult
name|LookupSpecialMember
parameter_list|(
name|CXXRecordDecl
modifier|*
name|D
parameter_list|,
name|CXXSpecialMember
name|SM
parameter_list|,
name|bool
name|ConstArg
parameter_list|,
name|bool
name|VolatileArg
parameter_list|,
name|bool
name|RValueThis
parameter_list|,
name|bool
name|ConstThis
parameter_list|,
name|bool
name|VolatileThis
parameter_list|)
function_decl|;
end_function_decl

begin_typedef
typedef|typedef
name|std
operator|::
name|function
operator|<
name|void
argument_list|(
specifier|const
name|TypoCorrection
operator|&
argument_list|)
operator|>
name|TypoDiagnosticGenerator
expr_stmt|;
end_typedef

begin_typedef
typedef|typedef
name|std
operator|::
name|function
operator|<
name|ExprResult
argument_list|(
name|Sema
operator|&
argument_list|,
name|TypoExpr
operator|*
argument_list|,
name|TypoCorrection
argument_list|)
operator|>
name|TypoRecoveryCallback
expr_stmt|;
end_typedef

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

begin_struct
struct|struct
name|TypoExprState
block|{
name|std
operator|::
name|unique_ptr
operator|<
name|TypoCorrectionConsumer
operator|>
name|Consumer
expr_stmt|;
name|TypoDiagnosticGenerator
name|DiagHandler
decl_stmt|;
name|TypoRecoveryCallback
name|RecoveryHandler
decl_stmt|;
name|TypoExprState
argument_list|()
expr_stmt|;
name|TypoExprState
argument_list|(
argument|TypoExprState&&other
argument_list|)
name|noexcept
expr_stmt|;
name|TypoExprState
modifier|&
name|operator
init|=
operator|(
name|TypoExprState
operator|&&
name|other
operator|)
name|noexcept
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/// \brief The set of unhandled TypoExprs and their associated state.
end_comment

begin_expr_stmt
name|llvm
operator|::
name|MapVector
operator|<
name|TypoExpr
operator|*
operator|,
name|TypoExprState
operator|>
name|DelayedTypos
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// \brief Creates a new TypoExpr AST node.
end_comment

begin_decl_stmt
name|TypoExpr
modifier|*
name|createDelayedTypo
argument_list|(
name|std
operator|::
name|unique_ptr
operator|<
name|TypoCorrectionConsumer
operator|>
name|TCC
argument_list|,
name|TypoDiagnosticGenerator
name|TDG
argument_list|,
name|TypoRecoveryCallback
name|TRC
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|// \brief The set of known/encountered (unique, canonicalized) NamespaceDecls.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// The boolean value will be true to indicate that the namespace was loaded
end_comment

begin_comment
comment|// from an AST/PCH file, or false otherwise.
end_comment

begin_expr_stmt
name|llvm
operator|::
name|MapVector
operator|<
name|NamespaceDecl
operator|*
operator|,
name|bool
operator|>
name|KnownNamespaces
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// \brief Whether we have already loaded known namespaces from an extenal
end_comment

begin_comment
comment|/// source.
end_comment

begin_decl_stmt
name|bool
name|LoadedExternalKnownNamespaces
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// \brief Helper for CorrectTypo and CorrectTypoDelayed used to create and
end_comment

begin_comment
comment|/// populate a new TypoCorrectionConsumer. Returns nullptr if typo correction
end_comment

begin_comment
comment|/// should be skipped entirely.
end_comment

begin_expr_stmt
name|std
operator|::
name|unique_ptr
operator|<
name|TypoCorrectionConsumer
operator|>
name|makeTypoCorrectionConsumer
argument_list|(
argument|const DeclarationNameInfo&Typo
argument_list|,
argument|Sema::LookupNameKind LookupKind
argument_list|,
argument|Scope *S
argument_list|,
argument|CXXScopeSpec *SS
argument_list|,
argument|std::unique_ptr<CorrectionCandidateCallback> CCC
argument_list|,
argument|DeclContext *MemberContext
argument_list|,
argument|bool EnteringContext
argument_list|,
argument|const ObjCObjectPointerType *OPT
argument_list|,
argument|bool ErrorRecovery
argument_list|)
expr_stmt|;
end_expr_stmt

begin_label
name|public
label|:
end_label

begin_decl_stmt
specifier|const
name|TypoExprState
modifier|&
name|getTypoExprState
argument_list|(
name|TypoExpr
operator|*
name|TE
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// \brief Clears the state of the given TypoExpr.
end_comment

begin_function_decl
name|void
name|clearDelayedTypo
parameter_list|(
name|TypoExpr
modifier|*
name|TE
parameter_list|)
function_decl|;
end_function_decl

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
name|CXXScopeSpec
modifier|&
name|SS
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
name|LookupInSuper
parameter_list|(
name|LookupResult
modifier|&
name|R
parameter_list|,
name|CXXRecordDecl
modifier|*
name|Class
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
name|CXXConstructorDecl
modifier|*
name|LookupDefaultConstructor
parameter_list|(
name|CXXRecordDecl
modifier|*
name|Class
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|CXXConstructorDecl
modifier|*
name|LookupCopyingConstructor
parameter_list|(
name|CXXRecordDecl
modifier|*
name|Class
parameter_list|,
name|unsigned
name|Quals
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|CXXMethodDecl
modifier|*
name|LookupCopyingAssignment
parameter_list|(
name|CXXRecordDecl
modifier|*
name|Class
parameter_list|,
name|unsigned
name|Quals
parameter_list|,
name|bool
name|RValueThis
parameter_list|,
name|unsigned
name|ThisQuals
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|CXXConstructorDecl
modifier|*
name|LookupMovingConstructor
parameter_list|(
name|CXXRecordDecl
modifier|*
name|Class
parameter_list|,
name|unsigned
name|Quals
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|CXXMethodDecl
modifier|*
name|LookupMovingAssignment
parameter_list|(
name|CXXRecordDecl
modifier|*
name|Class
parameter_list|,
name|unsigned
name|Quals
parameter_list|,
name|bool
name|RValueThis
parameter_list|,
name|unsigned
name|ThisQuals
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
name|bool
name|checkLiteralOperatorId
parameter_list|(
specifier|const
name|CXXScopeSpec
modifier|&
name|SS
parameter_list|,
specifier|const
name|UnqualifiedId
modifier|&
name|Id
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
name|LiteralOperatorLookupResult
name|LookupLiteralOperator
argument_list|(
name|Scope
operator|*
name|S
argument_list|,
name|LookupResult
operator|&
name|R
argument_list|,
name|ArrayRef
operator|<
name|QualType
operator|>
name|ArgTys
argument_list|,
name|bool
name|AllowRaw
argument_list|,
name|bool
name|AllowTemplate
argument_list|,
name|bool
name|AllowStringTemplate
argument_list|)
decl_stmt|;
end_decl_stmt

begin_function_decl
name|bool
name|isKnownName
parameter_list|(
name|StringRef
name|name
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
name|void
name|ArgumentDependentLookup
argument_list|(
name|DeclarationName
name|Name
argument_list|,
name|SourceLocation
name|Loc
argument_list|,
name|ArrayRef
operator|<
name|Expr
operator|*
operator|>
name|Args
argument_list|,
name|ADLResult
operator|&
name|Functions
argument_list|)
decl_stmt|;
end_decl_stmt

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
parameter_list|,
name|bool
name|IncludeDependentBases
init|=
name|false
parameter_list|)
function_decl|;
end_function_decl

begin_enum
enum|enum
name|CorrectTypoKind
block|{
name|CTK_NonError
block|,
comment|// CorrectTypo used in a non error recovery situation.
name|CTK_ErrorRecovery
comment|// CorrectTypo used in normal error recovery.
block|}
enum|;
end_enum

begin_decl_stmt
name|TypoCorrection
name|CorrectTypo
argument_list|(
specifier|const
name|DeclarationNameInfo
operator|&
name|Typo
argument_list|,
name|Sema
operator|::
name|LookupNameKind
name|LookupKind
argument_list|,
name|Scope
operator|*
name|S
argument_list|,
name|CXXScopeSpec
operator|*
name|SS
argument_list|,
name|std
operator|::
name|unique_ptr
operator|<
name|CorrectionCandidateCallback
operator|>
name|CCC
argument_list|,
name|CorrectTypoKind
name|Mode
argument_list|,
name|DeclContext
operator|*
name|MemberContext
operator|=
name|nullptr
argument_list|,
name|bool
name|EnteringContext
operator|=
name|false
argument_list|,
specifier|const
name|ObjCObjectPointerType
operator|*
name|OPT
operator|=
name|nullptr
argument_list|,
name|bool
name|RecordFailure
operator|=
name|true
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|TypoExpr
modifier|*
name|CorrectTypoDelayed
argument_list|(
specifier|const
name|DeclarationNameInfo
operator|&
name|Typo
argument_list|,
name|Sema
operator|::
name|LookupNameKind
name|LookupKind
argument_list|,
name|Scope
operator|*
name|S
argument_list|,
name|CXXScopeSpec
operator|*
name|SS
argument_list|,
name|std
operator|::
name|unique_ptr
operator|<
name|CorrectionCandidateCallback
operator|>
name|CCC
argument_list|,
name|TypoDiagnosticGenerator
name|TDG
argument_list|,
name|TypoRecoveryCallback
name|TRC
argument_list|,
name|CorrectTypoKind
name|Mode
argument_list|,
name|DeclContext
operator|*
name|MemberContext
operator|=
name|nullptr
argument_list|,
name|bool
name|EnteringContext
operator|=
name|false
argument_list|,
specifier|const
name|ObjCObjectPointerType
operator|*
name|OPT
operator|=
name|nullptr
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// \brief Process any TypoExprs in the given Expr and its children,
end_comment

begin_comment
comment|/// generating diagnostics as appropriate and returning a new Expr if there
end_comment

begin_comment
comment|/// were typos that were all successfully corrected and ExprError if one or
end_comment

begin_comment
comment|/// more typos could not be corrected.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param E The Expr to check for TypoExprs.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param InitDecl A VarDecl to avoid because the Expr being corrected is its
end_comment

begin_comment
comment|/// initializer.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param Filter A function applied to a newly rebuilt Expr to determine if
end_comment

begin_comment
comment|/// it is an acceptable/usable result from a single combination of typo
end_comment

begin_comment
comment|/// corrections. As long as the filter returns ExprError, different
end_comment

begin_comment
comment|/// combinations of corrections will be tried until all are exhausted.
end_comment

begin_decl_stmt
name|ExprResult
name|CorrectDelayedTyposInExpr
argument_list|(
name|Expr
operator|*
name|E
argument_list|,
name|VarDecl
operator|*
name|InitDecl
operator|=
name|nullptr
argument_list|,
name|llvm
operator|::
name|function_ref
operator|<
name|ExprResult
argument_list|(
name|Expr
operator|*
argument_list|)
operator|>
name|Filter
operator|=
index|[]
operator|(
name|Expr
operator|*
name|E
operator|)
operator|->
name|ExprResult
block|{
return|return
name|E
return|;
block|}
end_decl_stmt

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_decl_stmt
name|ExprResult
name|CorrectDelayedTyposInExpr
argument_list|(
name|Expr
operator|*
name|E
argument_list|,
name|llvm
operator|::
name|function_ref
operator|<
name|ExprResult
argument_list|(
name|Expr
operator|*
argument_list|)
operator|>
name|Filter
argument_list|)
block|{
return|return
name|CorrectDelayedTyposInExpr
argument_list|(
name|E
argument_list|,
name|nullptr
argument_list|,
name|Filter
argument_list|)
return|;
block|}
end_decl_stmt

begin_decl_stmt
name|ExprResult
name|CorrectDelayedTyposInExpr
argument_list|(
name|ExprResult
name|ER
argument_list|,
name|VarDecl
operator|*
name|InitDecl
operator|=
name|nullptr
argument_list|,
name|llvm
operator|::
name|function_ref
operator|<
name|ExprResult
argument_list|(
name|Expr
operator|*
argument_list|)
operator|>
name|Filter
operator|=
index|[]
operator|(
name|Expr
operator|*
name|E
operator|)
operator|->
name|ExprResult
block|{
return|return
name|E
return|;
block|}
end_decl_stmt

begin_block
unit|)
block|{
return|return
name|ER
operator|.
name|isInvalid
argument_list|()
condition|?
name|ER
else|:
name|CorrectDelayedTyposInExpr
argument_list|(
name|ER
operator|.
name|get
argument_list|()
argument_list|,
name|Filter
argument_list|)
return|;
block|}
end_block

begin_decl_stmt
name|ExprResult
name|CorrectDelayedTyposInExpr
argument_list|(
name|ExprResult
name|ER
argument_list|,
name|llvm
operator|::
name|function_ref
operator|<
name|ExprResult
argument_list|(
name|Expr
operator|*
argument_list|)
operator|>
name|Filter
argument_list|)
block|{
return|return
name|CorrectDelayedTyposInExpr
argument_list|(
name|ER
argument_list|,
name|nullptr
argument_list|,
name|Filter
argument_list|)
return|;
block|}
end_decl_stmt

begin_function_decl
name|void
name|diagnoseTypo
parameter_list|(
specifier|const
name|TypoCorrection
modifier|&
name|Correction
parameter_list|,
specifier|const
name|PartialDiagnostic
modifier|&
name|TypoDiag
parameter_list|,
name|bool
name|ErrorRecovery
init|=
name|true
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|diagnoseTypo
parameter_list|(
specifier|const
name|TypoCorrection
modifier|&
name|Correction
parameter_list|,
specifier|const
name|PartialDiagnostic
modifier|&
name|TypoDiag
parameter_list|,
specifier|const
name|PartialDiagnostic
modifier|&
name|PrevNote
parameter_list|,
name|bool
name|ErrorRecovery
init|=
name|true
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|MarkTypoCorrectedFunctionDefinition
parameter_list|(
specifier|const
name|NamedDecl
modifier|*
name|F
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
name|void
name|FindAssociatedClassesAndNamespaces
argument_list|(
name|SourceLocation
name|InstantiationLoc
argument_list|,
name|ArrayRef
operator|<
name|Expr
operator|*
operator|>
name|Args
argument_list|,
name|AssociatedNamespaceSet
operator|&
name|AssociatedNamespaces
argument_list|,
name|AssociatedClassSet
operator|&
name|AssociatedClasses
argument_list|)
decl_stmt|;
end_decl_stmt

begin_function_decl
name|void
name|FilterLookupForScope
parameter_list|(
name|LookupResult
modifier|&
name|R
parameter_list|,
name|DeclContext
modifier|*
name|Ctx
parameter_list|,
name|Scope
modifier|*
name|S
parameter_list|,
name|bool
name|ConsiderLinkage
parameter_list|,
name|bool
name|AllowInlineNamespace
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
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

begin_function_decl
name|void
name|ProcessPragmaWeak
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

begin_comment
comment|// Helper for delayed proccessing of attributes.
end_comment

begin_function_decl
name|void
name|ProcessDeclAttributeDelayed
parameter_list|(
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
name|IncludeCXX11Attributes
init|=
name|true
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|ProcessAccessDeclAttributeList
parameter_list|(
name|AccessSpecDecl
modifier|*
name|ASDecl
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
name|checkUnusedDeclAttributes
parameter_list|(
name|Declarator
modifier|&
name|D
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// Determine if type T is a valid subject for a nonnull and similar
end_comment

begin_comment
comment|/// attributes. By default, we look through references (the behavior used by
end_comment

begin_comment
comment|/// nonnull), but if the second parameter is true, then we treat a reference
end_comment

begin_comment
comment|/// type as valid.
end_comment

begin_function_decl
name|bool
name|isValidPointerAttrType
parameter_list|(
name|QualType
name|T
parameter_list|,
name|bool
name|RefOkay
init|=
name|false
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
parameter_list|,
specifier|const
name|FunctionDecl
modifier|*
name|FD
init|=
name|nullptr
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
name|bool
name|CheckNoCallerSavedRegsAttr
parameter_list|(
specifier|const
name|AttributeList
modifier|&
name|attr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|checkStringLiteralArgumentAttr
parameter_list|(
specifier|const
name|AttributeList
modifier|&
name|Attr
parameter_list|,
name|unsigned
name|ArgNum
parameter_list|,
name|StringRef
modifier|&
name|Str
parameter_list|,
name|SourceLocation
modifier|*
name|ArgLocation
init|=
name|nullptr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|checkSectionName
parameter_list|(
name|SourceLocation
name|LiteralLoc
parameter_list|,
name|StringRef
name|Str
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|checkTargetAttr
parameter_list|(
name|SourceLocation
name|LiteralLoc
parameter_list|,
name|StringRef
name|Str
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
name|bool
name|checkMSInheritanceAttrOnDefinition
argument_list|(
name|CXXRecordDecl
operator|*
name|RD
argument_list|,
name|SourceRange
name|Range
argument_list|,
name|bool
name|BestCase
argument_list|,
name|MSInheritanceAttr
operator|::
name|Spelling
name|SemanticSpelling
argument_list|)
decl_stmt|;
end_decl_stmt

begin_function_decl
name|void
name|CheckAlignasUnderalignment
parameter_list|(
name|Decl
modifier|*
name|D
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// Adjust the calling convention of a method to be the ABI default if it
end_comment

begin_comment
comment|/// wasn't specified explicitly.  This handles method types formed from
end_comment

begin_comment
comment|/// function type typedefs and typename template arguments.
end_comment

begin_function_decl
name|void
name|adjustMemberFunctionCC
parameter_list|(
name|QualType
modifier|&
name|T
parameter_list|,
name|bool
name|IsStatic
parameter_list|,
name|bool
name|IsCtorOrDtor
parameter_list|,
name|SourceLocation
name|Loc
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|// Check if there is an explicit attribute, but only look through parens.
end_comment

begin_comment
comment|// The intent is to look for an attribute on the current declarator, but not
end_comment

begin_comment
comment|// one that came from a typedef.
end_comment

begin_function_decl
name|bool
name|hasExplicitCallingConv
parameter_list|(
name|QualType
modifier|&
name|T
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// Get the outermost AttributedType node that sets a calling convention.
end_comment

begin_comment
comment|/// Valid types should not have multiple attributes with different CCs.
end_comment

begin_decl_stmt
specifier|const
name|AttributedType
modifier|*
name|getCallingConvAttributedType
argument_list|(
name|QualType
name|T
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// Check whether a nullability type specifier can be added to the given
end_comment

begin_comment
comment|/// type.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param type The type to which the nullability specifier will be
end_comment

begin_comment
comment|/// added. On success, this type will be updated appropriately.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param nullability The nullability specifier to add.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param nullabilityLoc The location of the nullability specifier.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param isContextSensitive Whether this nullability specifier was
end_comment

begin_comment
comment|/// written as a context-sensitive keyword (in an Objective-C
end_comment

begin_comment
comment|/// method) or an Objective-C property attribute, rather than as an
end_comment

begin_comment
comment|/// underscored type specifier.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param allowArrayTypes Whether to accept nullability specifiers on an
end_comment

begin_comment
comment|/// array type (e.g., because it will decay to a pointer).
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \returns true if nullability cannot be applied, false otherwise.
end_comment

begin_function_decl
name|bool
name|checkNullabilityTypeSpecifier
parameter_list|(
name|QualType
modifier|&
name|type
parameter_list|,
name|NullabilityKind
name|nullability
parameter_list|,
name|SourceLocation
name|nullabilityLoc
parameter_list|,
name|bool
name|isContextSensitive
parameter_list|,
name|bool
name|allowArrayTypes
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// \brief Stmt attributes - this routine is the top level dispatcher.
end_comment

begin_function_decl
name|StmtResult
name|ProcessStmtAttributes
parameter_list|(
name|Stmt
modifier|*
name|Stmt
parameter_list|,
name|AttributeList
modifier|*
name|Attrs
parameter_list|,
name|SourceRange
name|Range
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|WarnConflictingTypedMethods
parameter_list|(
name|ObjCMethodDecl
modifier|*
name|Method
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
name|void
name|CheckConflictingOverridingMethod
parameter_list|(
name|ObjCMethodDecl
modifier|*
name|Method
parameter_list|,
name|ObjCMethodDecl
modifier|*
name|Overridden
parameter_list|,
name|bool
name|IsProtocolMethodDecl
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// WarnExactTypedMethods - This routine issues a warning if method
end_comment

begin_comment
comment|/// implementation declaration matches exactly that of its declaration.
end_comment

begin_function_decl
name|void
name|WarnExactTypedMethods
parameter_list|(
name|ObjCMethodDecl
modifier|*
name|Method
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

begin_typedef
typedef|typedef
name|llvm
operator|::
name|SmallPtrSet
operator|<
name|Selector
operator|,
literal|8
operator|>
name|SelectorSet
expr_stmt|;
end_typedef

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
comment|/// remains unimplemented in the class or category \@implementation.
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
name|bool
name|SynthesizeProperties
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// Diagnose any null-resettable synthesized setters.
end_comment

begin_function_decl
name|void
name|diagnoseNullResettableSynthesizedSetters
parameter_list|(
specifier|const
name|ObjCImplDecl
modifier|*
name|impDecl
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// DefaultSynthesizeProperties - This routine default synthesizes all
end_comment

begin_comment
comment|/// properties which must be synthesized in the class's \@implementation.
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

begin_function_decl
name|void
name|DefaultSynthesizeProperties
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

begin_comment
comment|/// IvarBacksCurrentMethodAccessor - This routine returns 'true' if 'IV' is
end_comment

begin_comment
comment|/// an ivar synthesized for 'Method' and 'Method' is a property accessor
end_comment

begin_comment
comment|/// declared in class 'IFace'.
end_comment

begin_function_decl
name|bool
name|IvarBacksCurrentMethodAccessor
parameter_list|(
name|ObjCInterfaceDecl
modifier|*
name|IFace
parameter_list|,
name|ObjCMethodDecl
modifier|*
name|Method
parameter_list|,
name|ObjCIvarDecl
modifier|*
name|IV
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// DiagnoseUnusedBackingIvarInAccessor - Issue an 'unused' warning if ivar which
end_comment

begin_comment
comment|/// backs the property is not used in the property's accessor.
end_comment

begin_function_decl
name|void
name|DiagnoseUnusedBackingIvarInAccessor
parameter_list|(
name|Scope
modifier|*
name|S
parameter_list|,
specifier|const
name|ObjCImplementationDecl
modifier|*
name|ImplD
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// GetIvarBackingPropertyAccessor - If method is a property setter/getter and
end_comment

begin_comment
comment|/// it property has a backing ivar, returns this ivar; otherwise, returns NULL.
end_comment

begin_comment
comment|/// It also returns ivar's property on success.
end_comment

begin_decl_stmt
name|ObjCIvarDecl
modifier|*
name|GetIvarBackingPropertyAccessor
argument_list|(
specifier|const
name|ObjCMethodDecl
operator|*
name|Method
argument_list|,
specifier|const
name|ObjCPropertyDecl
operator|*
operator|&
name|PDecl
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// Called by ActOnProperty to handle \@property declarations in
end_comment

begin_comment
comment|/// class extensions.
end_comment

begin_decl_stmt
name|ObjCPropertyDecl
modifier|*
name|HandlePropertyInClassExtension
argument_list|(
name|Scope
operator|*
name|S
argument_list|,
name|SourceLocation
name|AtLoc
argument_list|,
name|SourceLocation
name|LParenLoc
argument_list|,
name|FieldDeclarator
operator|&
name|FD
argument_list|,
name|Selector
name|GetterSel
argument_list|,
name|SourceLocation
name|GetterNameLoc
argument_list|,
name|Selector
name|SetterSel
argument_list|,
name|SourceLocation
name|SetterNameLoc
argument_list|,
specifier|const
name|bool
name|isReadWrite
argument_list|,
name|unsigned
operator|&
name|Attributes
argument_list|,
specifier|const
name|unsigned
name|AttributesAsWritten
argument_list|,
name|QualType
name|T
argument_list|,
name|TypeSourceInfo
operator|*
name|TSI
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
comment|/// handle creating the ObjcPropertyDecl for a category or \@interface.
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
name|SourceLocation
name|LParenLoc
argument_list|,
name|FieldDeclarator
operator|&
name|FD
argument_list|,
name|Selector
name|GetterSel
argument_list|,
name|SourceLocation
name|GetterNameLoc
argument_list|,
name|Selector
name|SetterSel
argument_list|,
name|SourceLocation
name|SetterNameLoc
argument_list|,
specifier|const
name|bool
name|isReadWrite
argument_list|,
specifier|const
name|unsigned
name|Attributes
argument_list|,
specifier|const
name|unsigned
name|AttributesAsWritten
argument_list|,
name|QualType
name|T
argument_list|,
name|TypeSourceInfo
operator|*
name|TSI
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
name|nullptr
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
name|ObjCInterfaceDecl
modifier|*
name|IDecl
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|DiagnoseOwningPropertyGetterSynthesis
parameter_list|(
specifier|const
name|ObjCImplementationDecl
modifier|*
name|D
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|DiagnoseMissingDesignatedInitOverrides
parameter_list|(
specifier|const
name|ObjCImplementationDecl
modifier|*
name|ImplD
parameter_list|,
specifier|const
name|ObjCInterfaceDecl
modifier|*
name|IFD
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

begin_enum
enum|enum
name|MethodMatchStrategy
block|{
name|MMS_loose
block|,
name|MMS_strict
block|}
enum|;
end_enum

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
name|MethodMatchStrategy
name|strategy
init|=
name|MMS_strict
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
parameter_list|,
name|bool
name|WarnCategoryMethodImpl
init|=
name|false
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// CheckCategoryVsClassMethodMatches - Checks that methods implemented in
end_comment

begin_comment
comment|/// category matches with those implemented in its primary class and
end_comment

begin_comment
comment|/// warns each time an exact match is found.
end_comment

begin_function_decl
name|void
name|CheckCategoryVsClassMethodMatches
parameter_list|(
name|ObjCCategoryImplDecl
modifier|*
name|CatIMP
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// \brief Add the given method to the list of globally-known methods.
end_comment

begin_function_decl
name|void
name|addMethodToGlobalList
parameter_list|(
name|ObjCMethodList
modifier|*
name|List
parameter_list|,
name|ObjCMethodDecl
modifier|*
name|Method
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
name|instance
parameter_list|)
function_decl|;
end_function_decl

begin_label
name|public
label|:
end_label

begin_comment
comment|/// \brief - Returns instance or factory methods in global method pool for
end_comment

begin_comment
comment|/// given selector. It checks the desired kind first, if none is found, and
end_comment

begin_comment
comment|/// parameter checkTheOther is set, it then checks the other kind. If no such
end_comment

begin_comment
comment|/// method or only one method is found, function returns false; otherwise, it
end_comment

begin_comment
comment|/// returns true.
end_comment

begin_decl_stmt
name|bool
name|CollectMultipleMethodsInGlobalPool
argument_list|(
name|Selector
name|Sel
argument_list|,
name|SmallVectorImpl
operator|<
name|ObjCMethodDecl
operator|*
operator|>
operator|&
name|Methods
argument_list|,
name|bool
name|InstanceFirst
argument_list|,
name|bool
name|CheckTheOther
argument_list|,
specifier|const
name|ObjCObjectType
operator|*
name|TypeBound
operator|=
name|nullptr
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|bool
name|AreMultipleMethodsInGlobalPool
argument_list|(
name|Selector
name|Sel
argument_list|,
name|ObjCMethodDecl
operator|*
name|BestMethod
argument_list|,
name|SourceRange
name|R
argument_list|,
name|bool
name|receiverIdOrClass
argument_list|,
name|SmallVectorImpl
operator|<
name|ObjCMethodDecl
operator|*
operator|>
operator|&
name|Methods
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|DiagnoseMultipleMethodInGlobalPool
argument_list|(
name|SmallVectorImpl
operator|<
name|ObjCMethodDecl
operator|*
operator|>
operator|&
name|Methods
argument_list|,
name|Selector
name|Sel
argument_list|,
name|SourceRange
name|R
argument_list|,
name|bool
name|receiverIdOrClass
argument_list|)
decl_stmt|;
end_decl_stmt

begin_label
name|private
label|:
end_label

begin_comment
comment|/// \brief - Returns a selector which best matches given argument list or
end_comment

begin_comment
comment|/// nullptr if none could be found
end_comment

begin_decl_stmt
name|ObjCMethodDecl
modifier|*
name|SelectBestMethod
argument_list|(
name|Selector
name|Sel
argument_list|,
name|MultiExprArg
name|Args
argument_list|,
name|bool
name|IsInstance
argument_list|,
name|SmallVectorImpl
operator|<
name|ObjCMethodDecl
operator|*
operator|>
operator|&
name|Methods
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// \brief Record the typo correction failure and return an empty correction.
end_comment

begin_function
name|TypoCorrection
name|FailedCorrection
parameter_list|(
name|IdentifierInfo
modifier|*
name|Typo
parameter_list|,
name|SourceLocation
name|TypoLoc
parameter_list|,
name|bool
name|RecordFailure
init|=
name|true
parameter_list|)
block|{
if|if
condition|(
name|RecordFailure
condition|)
name|TypoCorrectionFailures
index|[
name|Typo
index|]
operator|.
name|insert
argument_list|(
name|TypoLoc
argument_list|)
expr_stmt|;
return|return
name|TypoCorrection
argument_list|()
return|;
block|}
end_function

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
comment|/// AddAnyMethodToGlobalPool - Add any method, instance or factory to global
end_comment

begin_comment
comment|/// pool.
end_comment

begin_function_decl
name|void
name|AddAnyMethodToGlobalPool
parameter_list|(
name|Decl
modifier|*
name|D
parameter_list|)
function_decl|;
end_function_decl

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
comment|/*instance*/
name|false
argument_list|)
return|;
block|}
end_function

begin_function_decl
specifier|const
name|ObjCMethodDecl
modifier|*
name|SelectorsForTypoCorrection
parameter_list|(
name|Selector
name|Sel
parameter_list|,
name|QualType
name|ObjectType
init|=
name|QualType
argument_list|()
parameter_list|)
function_decl|;
end_function_decl

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
argument_list|()
operator|:
name|E
argument_list|(
argument|nullptr
argument_list|)
block|{ }
name|FullExprArg
argument_list|(
name|Sema
operator|&
name|actions
argument_list|)
operator|:
name|E
argument_list|(
argument|nullptr
argument_list|)
block|{ }
name|ExprResult
name|release
argument_list|()
block|{
return|return
name|E
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
name|MakeFullExpr
argument_list|(
name|Arg
argument_list|,
name|Arg
condition|?
name|Arg
operator|->
name|getExprLoc
argument_list|()
else|:
name|SourceLocation
argument_list|()
argument_list|)
return|;
block|}
end_function

begin_function
name|FullExprArg
name|MakeFullExpr
parameter_list|(
name|Expr
modifier|*
name|Arg
parameter_list|,
name|SourceLocation
name|CC
parameter_list|)
block|{
return|return
name|FullExprArg
argument_list|(
name|ActOnFinishFullExpr
argument_list|(
name|Arg
argument_list|,
name|CC
argument_list|)
operator|.
name|get
argument_list|()
argument_list|)
return|;
block|}
end_function

begin_function
name|FullExprArg
name|MakeFullDiscardedValueExpr
parameter_list|(
name|Expr
modifier|*
name|Arg
parameter_list|)
block|{
name|ExprResult
name|FE
init|=
name|ActOnFinishFullExpr
argument_list|(
name|Arg
argument_list|,
name|Arg
condition|?
name|Arg
operator|->
name|getExprLoc
argument_list|()
else|:
name|SourceLocation
argument_list|()
argument_list|,
comment|/*DiscardedValue*/
name|true
argument_list|)
decl_stmt|;
return|return
name|FullExprArg
argument_list|(
name|FE
operator|.
name|get
argument_list|()
argument_list|)
return|;
block|}
end_function

begin_function_decl
name|StmtResult
name|ActOnExprStmt
parameter_list|(
name|ExprResult
name|Arg
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|StmtResult
name|ActOnExprStmtError
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|StmtResult
name|ActOnNullStmt
parameter_list|(
name|SourceLocation
name|SemiLoc
parameter_list|,
name|bool
name|HasLeadingEmptyMacro
init|=
name|false
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ActOnStartOfCompoundStmt
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ActOnFinishOfCompoundStmt
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
name|StmtResult
name|ActOnCompoundStmt
argument_list|(
name|SourceLocation
name|L
argument_list|,
name|SourceLocation
name|R
argument_list|,
name|ArrayRef
operator|<
name|Stmt
operator|*
operator|>
name|Elts
argument_list|,
name|bool
name|isStmtExpr
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// \brief A RAII object to enter scope of a compound statement.
end_comment

begin_decl_stmt
name|class
name|CompoundScopeRAII
block|{
name|public
label|:
name|CompoundScopeRAII
argument_list|(
name|Sema
operator|&
name|S
argument_list|)
operator|:
name|S
argument_list|(
argument|S
argument_list|)
block|{
name|S
operator|.
name|ActOnStartOfCompoundStmt
argument_list|()
block|;     }
operator|~
name|CompoundScopeRAII
argument_list|()
block|{
name|S
operator|.
name|ActOnFinishOfCompoundStmt
argument_list|()
block|;     }
name|private
operator|:
name|Sema
operator|&
name|S
expr_stmt|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|/// An RAII helper that pops function a function scope on exit.
end_comment

begin_struct
struct|struct
name|FunctionScopeRAII
block|{
name|Sema
modifier|&
name|S
decl_stmt|;
name|bool
name|Active
decl_stmt|;
name|FunctionScopeRAII
argument_list|(
name|Sema
operator|&
name|S
argument_list|)
operator|:
name|S
argument_list|(
name|S
argument_list|)
operator|,
name|Active
argument_list|(
argument|true
argument_list|)
block|{}
operator|~
name|FunctionScopeRAII
argument_list|()
block|{
if|if
condition|(
name|Active
condition|)
name|S
operator|.
name|PopFunctionScopeInfo
argument_list|()
expr_stmt|;
block|}
name|void
name|disable
parameter_list|()
block|{
name|Active
operator|=
name|false
expr_stmt|;
block|}
block|}
struct|;
end_struct

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

begin_decl_stmt
name|StmtResult
name|ActOnAttributedStmt
argument_list|(
name|SourceLocation
name|AttrLoc
argument_list|,
name|ArrayRef
operator|<
specifier|const
name|Attr
operator|*
operator|>
name|Attrs
argument_list|,
name|Stmt
operator|*
name|SubStmt
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|class
name|ConditionResult
decl_stmt|;
end_decl_stmt

begin_function_decl
name|StmtResult
name|ActOnIfStmt
parameter_list|(
name|SourceLocation
name|IfLoc
parameter_list|,
name|bool
name|IsConstexpr
parameter_list|,
name|Stmt
modifier|*
name|InitStmt
parameter_list|,
name|ConditionResult
name|Cond
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
name|BuildIfStmt
parameter_list|(
name|SourceLocation
name|IfLoc
parameter_list|,
name|bool
name|IsConstexpr
parameter_list|,
name|Stmt
modifier|*
name|InitStmt
parameter_list|,
name|ConditionResult
name|Cond
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
name|Stmt
modifier|*
name|InitStmt
parameter_list|,
name|ConditionResult
name|Cond
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
name|ConditionResult
name|Cond
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
name|ConditionResult
name|Second
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
name|ExprResult
name|CheckObjCForCollectionOperand
parameter_list|(
name|SourceLocation
name|forLoc
parameter_list|,
name|Expr
modifier|*
name|collection
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
name|Stmt
modifier|*
name|First
parameter_list|,
name|Expr
modifier|*
name|collection
parameter_list|,
name|SourceLocation
name|RParenLoc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|StmtResult
name|FinishObjCForCollectionStmt
parameter_list|(
name|Stmt
modifier|*
name|ForCollection
parameter_list|,
name|Stmt
modifier|*
name|Body
parameter_list|)
function_decl|;
end_function_decl

begin_enum
enum|enum
name|BuildForRangeKind
block|{
comment|/// Initial building of a for-range statement.
name|BFRK_Build
block|,
comment|/// Instantiation or recovery rebuild of a for-range statement. Don't
comment|/// attempt any typo-correction.
name|BFRK_Rebuild
block|,
comment|/// Determining whether a for-range statement could be built. Avoid any
comment|/// unnecessary or irreversible actions.
name|BFRK_Check
block|}
enum|;
end_enum

begin_function_decl
name|StmtResult
name|ActOnCXXForRangeStmt
parameter_list|(
name|Scope
modifier|*
name|S
parameter_list|,
name|SourceLocation
name|ForLoc
parameter_list|,
name|SourceLocation
name|CoawaitLoc
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
parameter_list|,
name|BuildForRangeKind
name|Kind
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
name|CoawaitLoc
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
name|Begin
parameter_list|,
name|Stmt
modifier|*
name|End
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
parameter_list|,
name|BuildForRangeKind
name|Kind
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
name|BreakLoc
parameter_list|,
name|Scope
modifier|*
name|CurScope
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ActOnCapturedRegionStart
parameter_list|(
name|SourceLocation
name|Loc
parameter_list|,
name|Scope
modifier|*
name|CurScope
parameter_list|,
name|CapturedRegionKind
name|Kind
parameter_list|,
name|unsigned
name|NumParams
parameter_list|)
function_decl|;
end_function_decl

begin_typedef
typedef|typedef
name|std
operator|::
name|pair
operator|<
name|StringRef
operator|,
name|QualType
operator|>
name|CapturedParamNameType
expr_stmt|;
end_typedef

begin_decl_stmt
name|void
name|ActOnCapturedRegionStart
argument_list|(
name|SourceLocation
name|Loc
argument_list|,
name|Scope
operator|*
name|CurScope
argument_list|,
name|CapturedRegionKind
name|Kind
argument_list|,
name|ArrayRef
operator|<
name|CapturedParamNameType
operator|>
name|Params
argument_list|)
decl_stmt|;
end_decl_stmt

begin_function_decl
name|StmtResult
name|ActOnCapturedRegionEnd
parameter_list|(
name|Stmt
modifier|*
name|S
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ActOnCapturedRegionError
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|RecordDecl
modifier|*
name|CreateCapturedStmtRecordDecl
parameter_list|(
name|CapturedDecl
modifier|*
modifier|&
name|CD
parameter_list|,
name|SourceLocation
name|Loc
parameter_list|,
name|unsigned
name|NumParams
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
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
name|AllowParamOrMoveConstructible
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|isCopyElisionCandidate
parameter_list|(
name|QualType
name|ReturnType
parameter_list|,
specifier|const
name|VarDecl
modifier|*
name|VD
parameter_list|,
name|bool
name|AllowParamOrMoveConstructible
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
parameter_list|,
name|Scope
modifier|*
name|CurScope
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|StmtResult
name|BuildReturnStmt
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
name|ActOnCapScopeReturnStmt
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
name|ActOnGCCAsmStmt
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
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
name|ExprResult
name|LookupInlineAsmIdentifier
argument_list|(
name|CXXScopeSpec
operator|&
name|SS
argument_list|,
name|SourceLocation
name|TemplateKWLoc
argument_list|,
name|UnqualifiedId
operator|&
name|Id
argument_list|,
name|llvm
operator|::
name|InlineAsmIdentifierInfo
operator|&
name|Info
argument_list|,
name|bool
name|IsUnevaluatedContext
argument_list|)
decl_stmt|;
end_decl_stmt

begin_function_decl
name|bool
name|LookupInlineAsmField
parameter_list|(
name|StringRef
name|Base
parameter_list|,
name|StringRef
name|Member
parameter_list|,
name|unsigned
modifier|&
name|Offset
parameter_list|,
name|SourceLocation
name|AsmLoc
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
name|ExprResult
name|LookupInlineAsmVarDeclField
argument_list|(
name|Expr
operator|*
name|RefExpr
argument_list|,
name|StringRef
name|Member
argument_list|,
name|llvm
operator|::
name|InlineAsmIdentifierInfo
operator|&
name|Info
argument_list|,
name|SourceLocation
name|AsmLoc
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|StmtResult
name|ActOnMSAsmStmt
argument_list|(
name|SourceLocation
name|AsmLoc
argument_list|,
name|SourceLocation
name|LBraceLoc
argument_list|,
name|ArrayRef
operator|<
name|Token
operator|>
name|AsmToks
argument_list|,
name|StringRef
name|AsmString
argument_list|,
name|unsigned
name|NumOutputs
argument_list|,
name|unsigned
name|NumInputs
argument_list|,
name|ArrayRef
operator|<
name|StringRef
operator|>
name|Constraints
argument_list|,
name|ArrayRef
operator|<
name|StringRef
operator|>
name|Clobbers
argument_list|,
name|ArrayRef
operator|<
name|Expr
operator|*
operator|>
name|Exprs
argument_list|,
name|SourceLocation
name|EndLoc
argument_list|)
decl_stmt|;
end_decl_stmt

begin_function_decl
name|LabelDecl
modifier|*
name|GetOrCreateMSAsmLabel
parameter_list|(
name|StringRef
name|ExternalLabelName
parameter_list|,
name|SourceLocation
name|Location
parameter_list|,
name|bool
name|AlwaysCreate
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
name|ExprResult
name|ActOnObjCAtSynchronizedOperand
parameter_list|(
name|SourceLocation
name|atLoc
parameter_list|,
name|Expr
modifier|*
name|operand
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
name|StmtResult
name|ActOnObjCAutoreleasePoolStmt
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

begin_decl_stmt
name|StmtResult
name|ActOnCXXTryBlock
argument_list|(
name|SourceLocation
name|TryLoc
argument_list|,
name|Stmt
operator|*
name|TryBlock
argument_list|,
name|ArrayRef
operator|<
name|Stmt
operator|*
operator|>
name|Handlers
argument_list|)
decl_stmt|;
end_decl_stmt

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
name|void
name|ActOnStartSEHFinallyBlock
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ActOnAbortSEHFinallyBlock
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|StmtResult
name|ActOnFinishSEHFinallyBlock
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
name|StmtResult
name|ActOnSEHLeaveStmt
parameter_list|(
name|SourceLocation
name|Loc
parameter_list|,
name|Scope
modifier|*
name|CurScope
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
name|DiagnoseUnusedNestedTypedefs
parameter_list|(
specifier|const
name|RecordDecl
modifier|*
name|D
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

begin_comment
comment|/// Emit \p DiagID if statement located on \p StmtLoc has a suspicious null
end_comment

begin_comment
comment|/// statement as a \p Body, and it is located on the same line.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This helps prevent bugs due to typos, such as:
end_comment

begin_comment
comment|///     if (condition);
end_comment

begin_comment
comment|///       do_stuff();
end_comment

begin_function_decl
name|void
name|DiagnoseEmptyStmtBody
parameter_list|(
name|SourceLocation
name|StmtLoc
parameter_list|,
specifier|const
name|Stmt
modifier|*
name|Body
parameter_list|,
name|unsigned
name|DiagID
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// Warn if a for/while loop statement \p S, which is followed by
end_comment

begin_comment
comment|/// \p PossibleBody, has a suspicious null statement as a body.
end_comment

begin_function_decl
name|void
name|DiagnoseEmptyLoopBody
parameter_list|(
specifier|const
name|Stmt
modifier|*
name|S
parameter_list|,
specifier|const
name|Stmt
modifier|*
name|PossibleBody
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// Warn if a value is moved to itself.
end_comment

begin_function_decl
name|void
name|DiagnoseSelfMove
parameter_list|(
specifier|const
name|Expr
modifier|*
name|LHSExpr
parameter_list|,
specifier|const
name|Expr
modifier|*
name|RHSExpr
parameter_list|,
name|SourceLocation
name|OpLoc
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// \brief Warn if we're implicitly casting from a _Nullable pointer type to a
end_comment

begin_comment
comment|/// _Nonnull one.
end_comment

begin_function_decl
name|void
name|diagnoseNullableToNonnullConversion
parameter_list|(
name|QualType
name|DstType
parameter_list|,
name|QualType
name|SrcType
parameter_list|,
name|SourceLocation
name|Loc
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// Warn when implicitly casting 0 to nullptr.
end_comment

begin_function_decl
name|void
name|diagnoseZeroToNullptrConversion
parameter_list|(
name|CastKind
name|Kind
parameter_list|,
specifier|const
name|Expr
modifier|*
name|E
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
name|ParsingDeclState
name|PushParsingDeclaration
argument_list|(
name|sema
operator|::
name|DelayedDiagnosticPool
operator|&
name|pool
argument_list|)
block|{
return|return
name|DelayedDiagnostics
operator|.
name|push
argument_list|(
name|pool
argument_list|)
return|;
block|}
end_decl_stmt

begin_function_decl
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
function_decl|;
end_function_decl

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
name|pushUndelayed
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
name|popUndelayed
argument_list|(
name|state
argument_list|)
expr_stmt|;
block|}
end_function

begin_decl_stmt
name|void
name|redelayDiagnostics
argument_list|(
name|sema
operator|::
name|DelayedDiagnosticPool
operator|&
name|pool
argument_list|)
decl_stmt|;
end_decl_stmt

begin_function_decl
name|void
name|EmitAvailabilityWarning
parameter_list|(
name|AvailabilityResult
name|AR
parameter_list|,
name|NamedDecl
modifier|*
name|D
parameter_list|,
name|StringRef
name|Message
parameter_list|,
name|SourceLocation
name|Loc
parameter_list|,
specifier|const
name|ObjCInterfaceDecl
modifier|*
name|UnknownObjCClass
parameter_list|,
specifier|const
name|ObjCPropertyDecl
modifier|*
name|ObjCProperty
parameter_list|,
name|bool
name|ObjCPropertyAccess
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
name|bool
name|makeUnavailableInSystemHeader
argument_list|(
name|SourceLocation
name|loc
argument_list|,
name|UnavailableAttr
operator|::
name|ImplicitReason
name|reason
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// \brief Issue any -Wunguarded-availability warnings in \c FD
end_comment

begin_function_decl
name|void
name|DiagnoseUnguardedAvailabilityViolations
parameter_list|(
name|Decl
modifier|*
name|FD
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
name|CanUseDecl
parameter_list|(
name|NamedDecl
modifier|*
name|D
parameter_list|,
name|bool
name|TreatUnavailableAsInvalid
parameter_list|)
function_decl|;
end_function_decl

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
name|nullptr
parameter_list|,
name|bool
name|ObjCPropertyAccess
init|=
name|false
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|NoteDeletedFunction
parameter_list|(
name|FunctionDecl
modifier|*
name|FD
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|NoteDeletedInheritingConstructor
parameter_list|(
name|CXXConstructorDecl
modifier|*
name|CD
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

begin_decl_stmt
name|void
name|DiagnoseSentinelCalls
argument_list|(
name|NamedDecl
operator|*
name|D
argument_list|,
name|SourceLocation
name|Loc
argument_list|,
name|ArrayRef
operator|<
name|Expr
operator|*
operator|>
name|Args
argument_list|)
decl_stmt|;
end_decl_stmt

begin_function_decl
name|void
name|PushExpressionEvaluationContext
parameter_list|(
name|ExpressionEvaluationContext
name|NewContext
parameter_list|,
name|Decl
modifier|*
name|LambdaContextDecl
init|=
name|nullptr
parameter_list|,
name|bool
name|IsDecltype
init|=
name|false
parameter_list|)
function_decl|;
end_function_decl

begin_enum
enum|enum
name|ReuseLambdaContextDecl_t
block|{
name|ReuseLambdaContextDecl
block|}
enum|;
end_enum

begin_function_decl
name|void
name|PushExpressionEvaluationContext
parameter_list|(
name|ExpressionEvaluationContext
name|NewContext
parameter_list|,
name|ReuseLambdaContextDecl_t
parameter_list|,
name|bool
name|IsDecltype
init|=
name|false
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
name|DiscardCleanupsInEvaluationContext
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|ExprResult
name|TransformToPotentiallyEvaluated
parameter_list|(
name|Expr
modifier|*
name|E
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ExprResult
name|HandleExprEvaluationContextForTypeof
parameter_list|(
name|Expr
modifier|*
name|E
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ExprResult
name|ActOnConstantExpression
parameter_list|(
name|ExprResult
name|Res
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|// Functions for marking a declaration referenced.  These functions also
end_comment

begin_comment
comment|// contain the relevant logic for marking if a reference to a function or
end_comment

begin_comment
comment|// variable is an odr-use (in the C++11 sense).  There are separate variants
end_comment

begin_comment
comment|// for expressions referring to a decl; these exist because odr-use marking
end_comment

begin_comment
comment|// needs to be delayed for some constant variables when we build one of the
end_comment

begin_comment
comment|// named expressions.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// MightBeOdrUse indicates whether the use could possibly be an odr-use, and
end_comment

begin_comment
comment|// should usually be true. This only needs to be set to false if the lack of
end_comment

begin_comment
comment|// odr-use cannot be determined from the current context (for instance,
end_comment

begin_comment
comment|// because the name denotes a virtual function and was written without an
end_comment

begin_comment
comment|// explicit nested-name-specifier).
end_comment

begin_function_decl
name|void
name|MarkAnyDeclReferenced
parameter_list|(
name|SourceLocation
name|Loc
parameter_list|,
name|Decl
modifier|*
name|D
parameter_list|,
name|bool
name|MightBeOdrUse
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|MarkFunctionReferenced
parameter_list|(
name|SourceLocation
name|Loc
parameter_list|,
name|FunctionDecl
modifier|*
name|Func
parameter_list|,
name|bool
name|MightBeOdrUse
init|=
name|true
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|MarkVariableReferenced
parameter_list|(
name|SourceLocation
name|Loc
parameter_list|,
name|VarDecl
modifier|*
name|Var
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|MarkDeclRefReferenced
parameter_list|(
name|DeclRefExpr
modifier|*
name|E
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|MarkMemberReferenced
parameter_list|(
name|MemberExpr
modifier|*
name|E
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|UpdateMarkingForLValueToRValue
parameter_list|(
name|Expr
modifier|*
name|E
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|CleanupVarDeclMarking
parameter_list|()
function_decl|;
end_function_decl

begin_enum
enum|enum
name|TryCaptureKind
block|{
name|TryCapture_Implicit
block|,
name|TryCapture_ExplicitByVal
block|,
name|TryCapture_ExplicitByRef
block|}
enum|;
end_enum

begin_comment
comment|/// \brief Try to capture the given variable.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param Var The variable to capture.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param Loc The location at which the capture occurs.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param Kind The kind of capture, which may be implicit (for either a
end_comment

begin_comment
comment|/// block or a lambda), or explicit by-value or by-reference (for a lambda).
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param EllipsisLoc The location of the ellipsis, if one is provided in
end_comment

begin_comment
comment|/// an explicit lambda capture.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param BuildAndDiagnose Whether we are actually supposed to add the
end_comment

begin_comment
comment|/// captures or diagnose errors. If false, this routine merely check whether
end_comment

begin_comment
comment|/// the capture can occur without performing the capture itself or complaining
end_comment

begin_comment
comment|/// if the variable cannot be captured.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param CaptureType Will be set to the type of the field used to capture
end_comment

begin_comment
comment|/// this variable in the innermost block or lambda. Only valid when the
end_comment

begin_comment
comment|/// variable can be captured.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param DeclRefType Will be set to the type of a reference to the capture
end_comment

begin_comment
comment|/// from within the current scope. Only valid when the variable can be
end_comment

begin_comment
comment|/// captured.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param FunctionScopeIndexToStopAt If non-null, it points to the index
end_comment

begin_comment
comment|/// of the FunctionScopeInfo stack beyond which we do not attempt to capture.
end_comment

begin_comment
comment|/// This is useful when enclosing lambdas must speculatively capture
end_comment

begin_comment
comment|/// variables that may or may not be used in certain specializations of
end_comment

begin_comment
comment|/// a nested generic lambda.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \returns true if an error occurred (i.e., the variable cannot be
end_comment

begin_comment
comment|/// captured) and false if the capture succeeded.
end_comment

begin_function_decl
name|bool
name|tryCaptureVariable
parameter_list|(
name|VarDecl
modifier|*
name|Var
parameter_list|,
name|SourceLocation
name|Loc
parameter_list|,
name|TryCaptureKind
name|Kind
parameter_list|,
name|SourceLocation
name|EllipsisLoc
parameter_list|,
name|bool
name|BuildAndDiagnose
parameter_list|,
name|QualType
modifier|&
name|CaptureType
parameter_list|,
name|QualType
modifier|&
name|DeclRefType
parameter_list|,
specifier|const
name|unsigned
modifier|*
specifier|const
name|FunctionScopeIndexToStopAt
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// \brief Try to capture the given variable.
end_comment

begin_function_decl
name|bool
name|tryCaptureVariable
parameter_list|(
name|VarDecl
modifier|*
name|Var
parameter_list|,
name|SourceLocation
name|Loc
parameter_list|,
name|TryCaptureKind
name|Kind
init|=
name|TryCapture_Implicit
parameter_list|,
name|SourceLocation
name|EllipsisLoc
init|=
name|SourceLocation
argument_list|()
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// \brief Checks if the variable must be captured.
end_comment

begin_function_decl
name|bool
name|NeedToCaptureVariable
parameter_list|(
name|VarDecl
modifier|*
name|Var
parameter_list|,
name|SourceLocation
name|Loc
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// \brief Given a variable, determine the type that a reference to that
end_comment

begin_comment
comment|/// variable will have in the given scope.
end_comment

begin_function_decl
name|QualType
name|getCapturedDeclRefType
parameter_list|(
name|VarDecl
modifier|*
name|Var
parameter_list|,
name|SourceLocation
name|Loc
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// Mark all of the declarations referenced within a particular AST node as
end_comment

begin_comment
comment|/// referenced. Used when template instantiation instantiates a non-dependent
end_comment

begin_comment
comment|/// type -- entities referenced by the type are now referenced.
end_comment

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
parameter_list|,
name|bool
name|SkipLocalVariables
init|=
name|false
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// \brief Try to recover by turning the given expression into a
end_comment

begin_comment
comment|/// call.  Returns true if recovery was attempted or an error was
end_comment

begin_comment
comment|/// emitted; this may also leave the ExprResult invalid.
end_comment

begin_function_decl
name|bool
name|tryToRecoverWithCall
parameter_list|(
name|ExprResult
modifier|&
name|E
parameter_list|,
specifier|const
name|PartialDiagnostic
modifier|&
name|PD
parameter_list|,
name|bool
name|ForceComplain
init|=
name|false
parameter_list|,
name|bool
function_decl|(
modifier|*
name|IsPlausibleResult
function_decl|)
parameter_list|(
name|QualType
parameter_list|)
init|=
name|nullptr
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// \brief Figure out if an expression could be turned into a call.
end_comment

begin_function_decl
name|bool
name|tryExprAsCall
parameter_list|(
name|Expr
modifier|&
name|E
parameter_list|,
name|QualType
modifier|&
name|ZeroArgCallReturnTy
parameter_list|,
name|UnresolvedSetImpl
modifier|&
name|NonTemplateOverloads
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
comment|/// \param Statement If Statement is non-null, delay reporting the
end_comment

begin_comment
comment|/// diagnostic until the function body is parsed, and then do a basic
end_comment

begin_comment
comment|/// reachability analysis to determine if the statement is reachable.
end_comment

begin_comment
comment|/// If it is unreachable, the diagnostic will not be emitted.
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
name|Statement
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

begin_decl_stmt
name|ExprResult
name|ActOnIdExpression
argument_list|(
name|Scope
operator|*
name|S
argument_list|,
name|CXXScopeSpec
operator|&
name|SS
argument_list|,
name|SourceLocation
name|TemplateKWLoc
argument_list|,
name|UnqualifiedId
operator|&
name|Id
argument_list|,
name|bool
name|HasTrailingLParen
argument_list|,
name|bool
name|IsAddressOfOperand
argument_list|,
name|std
operator|::
name|unique_ptr
operator|<
name|CorrectionCandidateCallback
operator|>
name|CCC
operator|=
name|nullptr
argument_list|,
name|bool
name|IsInlineAsmIdentifier
operator|=
name|false
argument_list|,
name|Token
operator|*
name|KeywordReplacement
operator|=
name|nullptr
argument_list|)
decl_stmt|;
end_decl_stmt

begin_function_decl
name|void
name|DecomposeUnqualifiedId
parameter_list|(
specifier|const
name|UnqualifiedId
modifier|&
name|Id
parameter_list|,
name|TemplateArgumentListInfo
modifier|&
name|Buffer
parameter_list|,
name|DeclarationNameInfo
modifier|&
name|NameInfo
parameter_list|,
specifier|const
name|TemplateArgumentListInfo
modifier|*
modifier|&
name|TemplateArgs
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
name|bool
name|DiagnoseEmptyLookup
argument_list|(
name|Scope
operator|*
name|S
argument_list|,
name|CXXScopeSpec
operator|&
name|SS
argument_list|,
name|LookupResult
operator|&
name|R
argument_list|,
name|std
operator|::
name|unique_ptr
operator|<
name|CorrectionCandidateCallback
operator|>
name|CCC
argument_list|,
name|TemplateArgumentListInfo
operator|*
name|ExplicitTemplateArgs
operator|=
name|nullptr
argument_list|,
name|ArrayRef
operator|<
name|Expr
operator|*
operator|>
name|Args
operator|=
name|None
argument_list|,
name|TypoExpr
operator|*
operator|*
name|Out
operator|=
name|nullptr
argument_list|)
decl_stmt|;
end_decl_stmt

begin_function_decl
name|ExprResult
name|LookupInObjCMethod
parameter_list|(
name|LookupResult
modifier|&
name|LookUp
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
name|SourceLocation
name|TemplateKWLoc
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
name|nullptr
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
name|nullptr
parameter_list|,
name|NamedDecl
modifier|*
name|FoundD
init|=
name|nullptr
parameter_list|,
specifier|const
name|TemplateArgumentListInfo
modifier|*
name|TemplateArgs
init|=
name|nullptr
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
name|DeclAccessPair
name|FoundDecl
init|=
name|DeclAccessPair
operator|::
name|make
argument_list|(
name|nullptr
argument_list|,
name|AS_none
argument_list|)
parameter_list|,
name|Expr
modifier|*
name|baseObjectExpr
init|=
name|nullptr
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
name|SourceLocation
name|TemplateKWLoc
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
specifier|const
name|Scope
modifier|*
name|S
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
name|SourceLocation
name|TemplateKWLoc
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
parameter_list|,
specifier|const
name|Scope
modifier|*
name|S
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
parameter_list|,
name|bool
name|IsAddressOfOperand
parameter_list|,
specifier|const
name|Scope
modifier|*
name|S
parameter_list|,
name|TypeSourceInfo
modifier|*
modifier|*
name|RecoveryTSI
init|=
name|nullptr
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
name|SourceLocation
name|TemplateKWLoc
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
name|NeedsADL
parameter_list|,
name|bool
name|AcceptInvalidDecl
init|=
name|false
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
parameter_list|,
name|NamedDecl
modifier|*
name|FoundD
init|=
name|nullptr
parameter_list|,
specifier|const
name|TemplateArgumentListInfo
modifier|*
name|TemplateArgs
init|=
name|nullptr
parameter_list|,
name|bool
name|AcceptInvalidDecl
init|=
name|false
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
name|ExprResult
name|BuildLiteralOperatorCall
argument_list|(
name|LookupResult
operator|&
name|R
argument_list|,
name|DeclarationNameInfo
operator|&
name|SuffixInfo
argument_list|,
name|ArrayRef
operator|<
name|Expr
operator|*
operator|>
name|Args
argument_list|,
name|SourceLocation
name|LitEndLoc
argument_list|,
name|TemplateArgumentListInfo
operator|*
name|ExplicitTemplateArgs
operator|=
name|nullptr
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|ExprResult
name|BuildPredefinedExpr
argument_list|(
name|SourceLocation
name|Loc
argument_list|,
name|PredefinedExpr
operator|::
name|IdentType
name|IT
argument_list|)
decl_stmt|;
end_decl_stmt

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
name|ActOnIntegerConstant
parameter_list|(
name|SourceLocation
name|Loc
parameter_list|,
name|uint64_t
name|Val
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|CheckLoopHintExpr
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
name|ExprResult
name|ActOnNumericConstant
parameter_list|(
specifier|const
name|Token
modifier|&
name|Tok
parameter_list|,
name|Scope
modifier|*
name|UDLScope
init|=
name|nullptr
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
name|Tok
parameter_list|,
name|Scope
modifier|*
name|UDLScope
init|=
name|nullptr
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
name|E
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ExprResult
name|ActOnParenListExpr
parameter_list|(
name|SourceLocation
name|L
parameter_list|,
name|SourceLocation
name|R
parameter_list|,
name|MultiExprArg
name|Val
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// ActOnStringLiteral - The specified tokens were lexed as pasted string
end_comment

begin_comment
comment|/// fragments (e.g. "foo" "bar" L"baz").
end_comment

begin_decl_stmt
name|ExprResult
name|ActOnStringLiteral
argument_list|(
name|ArrayRef
operator|<
name|Token
operator|>
name|StringToks
argument_list|,
name|Scope
operator|*
name|UDLScope
operator|=
name|nullptr
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|ExprResult
name|ActOnGenericSelectionExpr
argument_list|(
name|SourceLocation
name|KeyLoc
argument_list|,
name|SourceLocation
name|DefaultLoc
argument_list|,
name|SourceLocation
name|RParenLoc
argument_list|,
name|Expr
operator|*
name|ControllingExpr
argument_list|,
name|ArrayRef
operator|<
name|ParsedType
operator|>
name|ArgTypes
argument_list|,
name|ArrayRef
operator|<
name|Expr
operator|*
operator|>
name|ArgExprs
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|ExprResult
name|CreateGenericSelectionExpr
argument_list|(
name|SourceLocation
name|KeyLoc
argument_list|,
name|SourceLocation
name|DefaultLoc
argument_list|,
name|SourceLocation
name|RParenLoc
argument_list|,
name|Expr
operator|*
name|ControllingExpr
argument_list|,
name|ArrayRef
operator|<
name|TypeSourceInfo
operator|*
operator|>
name|Types
argument_list|,
name|ArrayRef
operator|<
name|Expr
operator|*
operator|>
name|Exprs
argument_list|)
decl_stmt|;
end_decl_stmt

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
name|InputExpr
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
name|Input
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
name|QualType
name|CheckAddressOfOperand
parameter_list|(
name|ExprResult
modifier|&
name|Operand
parameter_list|,
name|SourceLocation
name|OpLoc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ExprResult
name|CreateUnaryExprOrTypeTraitExpr
parameter_list|(
name|TypeSourceInfo
modifier|*
name|TInfo
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
name|IsType
parameter_list|,
name|void
modifier|*
name|TyOrEx
parameter_list|,
name|SourceRange
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
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|CheckUnaryExprOrTypeTraitOperand
parameter_list|(
name|Expr
modifier|*
name|E
parameter_list|,
name|UnaryExprOrTypeTrait
name|ExprKind
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|CheckUnaryExprOrTypeTraitOperand
parameter_list|(
name|QualType
name|ExprType
parameter_list|,
name|SourceLocation
name|OpLoc
parameter_list|,
name|SourceRange
name|ExprRange
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
name|ActOnOMPArraySectionExpr
parameter_list|(
name|Expr
modifier|*
name|Base
parameter_list|,
name|SourceLocation
name|LBLoc
parameter_list|,
name|Expr
modifier|*
name|LowerBound
parameter_list|,
name|SourceLocation
name|ColonLoc
parameter_list|,
name|Expr
modifier|*
name|Length
parameter_list|,
name|SourceLocation
name|RBLoc
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|// This struct is for use by ActOnMemberAccess to allow
end_comment

begin_comment
comment|// BuildMemberReferenceExpr to be able to reinvoke ActOnMemberAccess after
end_comment

begin_comment
comment|// changing the access operator from a '.' to a '->' (to see if that is the
end_comment

begin_comment
comment|// change needed to fix an error about an unknown member, e.g. when the class
end_comment

begin_comment
comment|// defines a custom operator->).
end_comment

begin_struct
struct|struct
name|ActOnMemberAccessExtraArgs
block|{
name|Scope
modifier|*
name|S
decl_stmt|;
name|UnqualifiedId
modifier|&
name|Id
decl_stmt|;
name|Decl
modifier|*
name|ObjCImpDecl
decl_stmt|;
block|}
struct|;
end_struct

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
name|SourceLocation
name|TemplateKWLoc
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
parameter_list|,
specifier|const
name|Scope
modifier|*
name|S
parameter_list|,
name|ActOnMemberAccessExtraArgs
modifier|*
name|ExtraArgs
init|=
name|nullptr
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
name|SourceLocation
name|TemplateKWLoc
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
specifier|const
name|Scope
modifier|*
name|S
parameter_list|,
name|bool
name|SuppressQualifierCheck
init|=
name|false
parameter_list|,
name|ActOnMemberAccessExtraArgs
modifier|*
name|ExtraArgs
init|=
name|nullptr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ExprResult
name|BuildFieldReferenceExpr
parameter_list|(
name|Expr
modifier|*
name|BaseExpr
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
name|FieldDecl
modifier|*
name|Field
parameter_list|,
name|DeclAccessPair
name|FoundDecl
parameter_list|,
specifier|const
name|DeclarationNameInfo
modifier|&
name|MemberNameInfo
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ExprResult
name|PerformMemberExprBaseConversion
parameter_list|(
name|Expr
modifier|*
name|Base
parameter_list|,
name|bool
name|IsArrow
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
name|SourceLocation
name|TemplateKWLoc
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
name|SourceLocation
name|TemplateKWLoc
argument_list|,
name|UnqualifiedId
operator|&
name|Member
argument_list|,
name|Decl
operator|*
name|ObjCImpDecl
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

begin_decl_stmt
name|bool
name|ConvertArgumentsForCall
argument_list|(
name|CallExpr
operator|*
name|Call
argument_list|,
name|Expr
operator|*
name|Fn
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
name|ArrayRef
operator|<
name|Expr
operator|*
operator|>
name|Args
argument_list|,
name|SourceLocation
name|RParenLoc
argument_list|,
name|bool
name|ExecConfig
operator|=
name|false
argument_list|)
decl_stmt|;
end_decl_stmt

begin_function_decl
name|void
name|CheckStaticArrayArgument
parameter_list|(
name|SourceLocation
name|CallLoc
parameter_list|,
name|ParmVarDecl
modifier|*
name|Param
parameter_list|,
specifier|const
name|Expr
modifier|*
name|ArgExpr
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
name|ArgExprs
parameter_list|,
name|SourceLocation
name|RParenLoc
parameter_list|,
name|Expr
modifier|*
name|ExecConfig
init|=
name|nullptr
parameter_list|,
name|bool
name|IsExecConfig
init|=
name|false
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
name|ExprResult
name|BuildResolvedCallExpr
argument_list|(
name|Expr
operator|*
name|Fn
argument_list|,
name|NamedDecl
operator|*
name|NDecl
argument_list|,
name|SourceLocation
name|LParenLoc
argument_list|,
name|ArrayRef
operator|<
name|Expr
operator|*
operator|>
name|Arg
argument_list|,
name|SourceLocation
name|RParenLoc
argument_list|,
name|Expr
operator|*
name|Config
operator|=
name|nullptr
argument_list|,
name|bool
name|IsExecConfig
operator|=
name|false
argument_list|)
decl_stmt|;
end_decl_stmt

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
name|Declarator
modifier|&
name|D
parameter_list|,
name|ParsedType
modifier|&
name|Ty
parameter_list|,
name|SourceLocation
name|RParenLoc
parameter_list|,
name|Expr
modifier|*
name|CastExpr
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

begin_function_decl
name|CastKind
name|PrepareScalarCast
parameter_list|(
name|ExprResult
modifier|&
name|src
parameter_list|,
name|QualType
name|destType
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// \brief Build an altivec or OpenCL literal.
end_comment

begin_function_decl
name|ExprResult
name|BuildVectorLiteral
parameter_list|(
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
name|InitExpr
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
name|LiteralExpr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ExprResult
name|ActOnInitList
parameter_list|(
name|SourceLocation
name|LBraceLoc
parameter_list|,
name|MultiExprArg
name|InitArgList
parameter_list|,
name|SourceLocation
name|RBraceLoc
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

begin_label
name|private
label|:
end_label

begin_decl_stmt
specifier|static
name|BinaryOperatorKind
name|ConvertTokenKindToBinaryOpcode
argument_list|(
name|tok
operator|::
name|TokenKind
name|Kind
argument_list|)
decl_stmt|;
end_decl_stmt

begin_label
name|public
label|:
end_label

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
name|LHSExpr
argument_list|,
name|Expr
operator|*
name|RHSExpr
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
name|LHSExpr
parameter_list|,
name|Expr
modifier|*
name|RHSExpr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ExprResult
name|CreateBuiltinBinOp
parameter_list|(
name|SourceLocation
name|OpLoc
parameter_list|,
name|BinaryOperatorKind
name|Opc
parameter_list|,
name|Expr
modifier|*
name|LHSExpr
parameter_list|,
name|Expr
modifier|*
name|RHSExpr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|DiagnoseCommaOperator
parameter_list|(
specifier|const
name|Expr
modifier|*
name|LHS
parameter_list|,
name|SourceLocation
name|Loc
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
name|CondExpr
parameter_list|,
name|Expr
modifier|*
name|LHSExpr
parameter_list|,
name|Expr
modifier|*
name|RHSExpr
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
name|TheDecl
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ActOnStartStmtExpr
parameter_list|()
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

begin_function_decl
name|void
name|ActOnStmtExprError
parameter_list|()
function_decl|;
end_function_decl

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
name|Expr
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

begin_decl_stmt
name|ExprResult
name|BuildBuiltinOffsetOf
argument_list|(
name|SourceLocation
name|BuiltinLoc
argument_list|,
name|TypeSourceInfo
operator|*
name|TInfo
argument_list|,
name|ArrayRef
operator|<
name|OffsetOfComponent
operator|>
name|Components
argument_list|,
name|SourceLocation
name|RParenLoc
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|ExprResult
name|ActOnBuiltinOffsetOf
argument_list|(
name|Scope
operator|*
name|S
argument_list|,
name|SourceLocation
name|BuiltinLoc
argument_list|,
name|SourceLocation
name|TypeLoc
argument_list|,
name|ParsedType
name|ParsedArgTy
argument_list|,
name|ArrayRef
operator|<
name|OffsetOfComponent
operator|>
name|Components
argument_list|,
name|SourceLocation
name|RParenLoc
argument_list|)
decl_stmt|;
end_decl_stmt

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
name|CondExpr
parameter_list|,
name|Expr
modifier|*
name|LHSExpr
parameter_list|,
name|Expr
modifier|*
name|RHSExpr
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
name|E
parameter_list|,
name|ParsedType
name|Ty
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
name|E
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
name|E
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// \brief Describes the result of an "if-exists" condition check.
end_comment

begin_enum
enum|enum
name|IfExistsResult
block|{
comment|/// \brief The symbol exists.
name|IER_Exists
block|,
comment|/// \brief The symbol does not exist.
name|IER_DoesNotExist
block|,
comment|/// \brief The name is a dependent name, so the results will differ
comment|/// from one instantiation to the next.
name|IER_Dependent
block|,
comment|/// \brief An error occurred.
name|IER_Error
block|}
enum|;
end_enum

begin_function_decl
name|IfExistsResult
name|CheckMicrosoftIfExistsSymbol
parameter_list|(
name|Scope
modifier|*
name|S
parameter_list|,
name|CXXScopeSpec
modifier|&
name|SS
parameter_list|,
specifier|const
name|DeclarationNameInfo
modifier|&
name|TargetNameInfo
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|IfExistsResult
name|CheckMicrosoftIfExistsSymbol
parameter_list|(
name|Scope
modifier|*
name|S
parameter_list|,
name|SourceLocation
name|KeywordLoc
parameter_list|,
name|bool
name|IsIfExists
parameter_list|,
name|CXXScopeSpec
modifier|&
name|SS
parameter_list|,
name|UnqualifiedId
modifier|&
name|Name
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|StmtResult
name|BuildMSDependentExistsStmt
parameter_list|(
name|SourceLocation
name|KeywordLoc
parameter_list|,
name|bool
name|IsIfExists
parameter_list|,
name|NestedNameSpecifierLoc
name|QualifierLoc
parameter_list|,
name|DeclarationNameInfo
name|NameInfo
parameter_list|,
name|Stmt
modifier|*
name|Nested
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|StmtResult
name|ActOnMSDependentExistsStmt
parameter_list|(
name|SourceLocation
name|KeywordLoc
parameter_list|,
name|bool
name|IsIfExists
parameter_list|,
name|CXXScopeSpec
modifier|&
name|SS
parameter_list|,
name|UnqualifiedId
modifier|&
name|Name
parameter_list|,
name|Stmt
modifier|*
name|Nested
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
name|SourceLocation
name|CaretLoc
parameter_list|,
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
comment|//===---------------------------- Clang Extensions ----------------------===//
end_comment

begin_comment
comment|/// __builtin_convertvector(...)
end_comment

begin_function_decl
name|ExprResult
name|ActOnConvertVectorExpr
parameter_list|(
name|Expr
modifier|*
name|E
parameter_list|,
name|ParsedType
name|ParsedDestTy
parameter_list|,
name|SourceLocation
name|BuiltinLoc
parameter_list|,
name|SourceLocation
name|RParenLoc
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|//===---------------------------- OpenCL Features -----------------------===//
end_comment

begin_comment
comment|/// __builtin_astype(...)
end_comment

begin_function_decl
name|ExprResult
name|ActOnAsTypeExpr
parameter_list|(
name|Expr
modifier|*
name|E
parameter_list|,
name|ParsedType
name|ParsedDestTy
parameter_list|,
name|SourceLocation
name|BuiltinLoc
parameter_list|,
name|SourceLocation
name|RParenLoc
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
parameter_list|,
name|UsingDirectiveDecl
modifier|*
modifier|&
name|UsingDecl
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

begin_function_decl
name|NamespaceDecl
modifier|*
name|lookupStdExperimentalNamespace
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

begin_expr_stmt
name|EnumDecl
operator|*
name|getStdAlignValT
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// \brief Tests whether Ty is an instance of std::initializer_list and, if
end_comment

begin_comment
comment|/// it is and Element is not NULL, assigns the element type to Element.
end_comment

begin_function_decl
name|bool
name|isStdInitializerList
parameter_list|(
name|QualType
name|Ty
parameter_list|,
name|QualType
modifier|*
name|Element
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// \brief Looks for the std::initializer_list template and instantiates it
end_comment

begin_comment
comment|/// with Element, or emits an error if it's not found.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \returns The instantiated template, or null on error.
end_comment

begin_function_decl
name|QualType
name|BuildStdInitializerList
parameter_list|(
name|QualType
name|Element
parameter_list|,
name|SourceLocation
name|Loc
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// \brief Determine whether Ctor is an initializer-list constructor, as
end_comment

begin_comment
comment|/// defined in [dcl.init.list]p2.
end_comment

begin_function_decl
name|bool
name|isInitListConstructor
parameter_list|(
specifier|const
name|FunctionDecl
modifier|*
name|Ctor
parameter_list|)
function_decl|;
end_function_decl

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
parameter_list|,
name|UsingShadowDecl
modifier|*
modifier|&
name|PrevShadow
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
parameter_list|,
name|UsingShadowDecl
modifier|*
name|PrevDecl
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
name|HasTypenameKeyword
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
name|bool
name|HasTypename
parameter_list|,
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
name|bool
name|HasTypenameKeyword
parameter_list|,
name|SourceLocation
name|TypenameLoc
parameter_list|,
name|CXXScopeSpec
modifier|&
name|SS
parameter_list|,
name|DeclarationNameInfo
name|NameInfo
parameter_list|,
name|SourceLocation
name|EllipsisLoc
parameter_list|,
name|AttributeList
modifier|*
name|AttrList
parameter_list|,
name|bool
name|IsInstantiation
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
name|NamedDecl
modifier|*
name|BuildUsingPackDecl
argument_list|(
name|NamedDecl
operator|*
name|InstantiatedFrom
argument_list|,
name|ArrayRef
operator|<
name|NamedDecl
operator|*
operator|>
name|Expansions
argument_list|)
decl_stmt|;
end_decl_stmt

begin_function_decl
name|bool
name|CheckInheritingConstructorUsingDecl
parameter_list|(
name|UsingDecl
modifier|*
name|UD
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// Given a derived-class using shadow declaration for a constructor and the
end_comment

begin_comment
comment|/// correspnding base class constructor, find or create the implicit
end_comment

begin_comment
comment|/// synthesized derived class constructor to use for this initialization.
end_comment

begin_function_decl
name|CXXConstructorDecl
modifier|*
name|findInheritingConstructor
parameter_list|(
name|SourceLocation
name|Loc
parameter_list|,
name|CXXConstructorDecl
modifier|*
name|BaseCtor
parameter_list|,
name|ConstructorUsingShadowDecl
modifier|*
name|DerivedShadow
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
name|SourceLocation
name|UsingLoc
parameter_list|,
name|SourceLocation
name|TypenameLoc
parameter_list|,
name|CXXScopeSpec
modifier|&
name|SS
parameter_list|,
name|UnqualifiedId
modifier|&
name|Name
parameter_list|,
name|SourceLocation
name|EllipsisLoc
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
name|ActOnAliasDeclaration
parameter_list|(
name|Scope
modifier|*
name|CurScope
parameter_list|,
name|AccessSpecifier
name|AS
parameter_list|,
name|MultiTemplateParamsArg
name|TemplateParams
parameter_list|,
name|SourceLocation
name|UsingLoc
parameter_list|,
name|UnqualifiedId
modifier|&
name|Name
parameter_list|,
name|AttributeList
modifier|*
name|AttrList
parameter_list|,
name|TypeResult
name|Type
parameter_list|,
name|Decl
modifier|*
name|DeclFromDeclSpec
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
name|NamedDecl
modifier|*
name|FoundDecl
parameter_list|,
name|CXXConstructorDecl
modifier|*
name|Constructor
parameter_list|,
name|MultiExprArg
name|Exprs
parameter_list|,
name|bool
name|HadMultipleCandidates
parameter_list|,
name|bool
name|IsListInitialization
parameter_list|,
name|bool
name|IsStdInitListInitialization
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
comment|/// Build a CXXConstructExpr whose constructor has already been resolved if
end_comment

begin_comment
comment|/// it denotes an inherited constructor.
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
name|HadMultipleCandidates
parameter_list|,
name|bool
name|IsListInitialization
parameter_list|,
name|bool
name|IsStdInitListInitialization
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
comment|// FIXME: Can we remove this and have the above BuildCXXConstructExpr check if
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
name|NamedDecl
modifier|*
name|FoundDecl
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
name|HadMultipleCandidates
parameter_list|,
name|bool
name|IsListInitialization
parameter_list|,
name|bool
name|IsStdInitListInitialization
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

begin_function_decl
name|ExprResult
name|BuildCXXDefaultInitExpr
parameter_list|(
name|SourceLocation
name|Loc
parameter_list|,
name|FieldDecl
modifier|*
name|Field
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// Instantiate or parse a C++ default argument expression as necessary.
end_comment

begin_comment
comment|/// Return true on error.
end_comment

begin_function_decl
name|bool
name|CheckCXXDefaultArgExpr
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
comment|/// \brief Helper class that collects exception specifications for
end_comment

begin_comment
comment|/// implicitly-declared special member functions.
end_comment

begin_decl_stmt
name|class
name|ImplicitExceptionSpecification
block|{
comment|// Pointer to allow copying
name|Sema
modifier|*
name|Self
decl_stmt|;
comment|// We order exception specifications thus:
comment|// noexcept is the most restrictive, but is only used in C++11.
comment|// throw() comes next.
comment|// Then a throw(collected exceptions)
comment|// Finally no specification, which is expressed as noexcept(false).
comment|// throw(...) is used instead if any called function uses it.
name|ExceptionSpecificationType
name|ComputedEST
decl_stmt|;
name|llvm
operator|::
name|SmallPtrSet
operator|<
name|CanQualType
operator|,
literal|4
operator|>
name|ExceptionsSeen
expr_stmt|;
name|SmallVector
operator|<
name|QualType
operator|,
literal|4
operator|>
name|Exceptions
expr_stmt|;
name|void
name|ClearExceptions
parameter_list|()
block|{
name|ExceptionsSeen
operator|.
name|clear
argument_list|()
expr_stmt|;
name|Exceptions
operator|.
name|clear
argument_list|()
expr_stmt|;
block|}
name|public
label|:
name|explicit
name|ImplicitExceptionSpecification
argument_list|(
name|Sema
operator|&
name|Self
argument_list|)
operator|:
name|Self
argument_list|(
operator|&
name|Self
argument_list|)
operator|,
name|ComputedEST
argument_list|(
argument|EST_BasicNoexcept
argument_list|)
block|{
if|if
condition|(
operator|!
name|Self
operator|.
name|getLangOpts
argument_list|()
operator|.
name|CPlusPlus11
condition|)
name|ComputedEST
operator|=
name|EST_DynamicNone
expr_stmt|;
block|}
comment|/// \brief Get the computed exception specification type.
name|ExceptionSpecificationType
name|getExceptionSpecType
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
name|ComputedEST
operator|!=
name|EST_ComputedNoexcept
operator|&&
literal|"noexcept(expr) should not be a possible result"
argument_list|)
block|;
return|return
name|ComputedEST
return|;
block|}
comment|/// \brief The number of exceptions in the exception specification.
name|unsigned
name|size
argument_list|()
specifier|const
block|{
return|return
name|Exceptions
operator|.
name|size
argument_list|()
return|;
block|}
comment|/// \brief The set of exceptions in the exception specification.
specifier|const
name|QualType
operator|*
name|data
argument_list|()
specifier|const
block|{
return|return
name|Exceptions
operator|.
name|data
argument_list|()
return|;
block|}
comment|/// \brief Integrate another called method into the collected data.
name|void
name|CalledDecl
parameter_list|(
name|SourceLocation
name|CallLoc
parameter_list|,
specifier|const
name|CXXMethodDecl
modifier|*
name|Method
parameter_list|)
function_decl|;
comment|/// \brief Integrate an invoked expression into the collected data.
name|void
name|CalledExpr
parameter_list|(
name|Expr
modifier|*
name|E
parameter_list|)
function_decl|;
comment|/// \brief Overwrite an EPI's exception specification with this
comment|/// computed exception specification.
name|FunctionProtoType
operator|::
name|ExceptionSpecInfo
name|getExceptionSpec
argument_list|()
specifier|const
block|{
name|FunctionProtoType
operator|::
name|ExceptionSpecInfo
name|ESI
block|;
name|ESI
operator|.
name|Type
operator|=
name|getExceptionSpecType
argument_list|()
block|;
if|if
condition|(
name|ESI
operator|.
name|Type
operator|==
name|EST_Dynamic
condition|)
block|{
name|ESI
operator|.
name|Exceptions
operator|=
name|Exceptions
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|ESI
operator|.
name|Type
operator|==
name|EST_None
condition|)
block|{
comment|/// C++11 [except.spec]p14:
comment|///   The exception-specification is noexcept(false) if the set of
comment|///   potential exceptions of the special member function contains "any"
name|ESI
operator|.
name|Type
operator|=
name|EST_ComputedNoexcept
expr_stmt|;
name|ESI
operator|.
name|NoexceptExpr
operator|=
name|Self
operator|->
name|ActOnCXXBoolLiteral
argument_list|(
name|SourceLocation
argument_list|()
argument_list|,
name|tok
operator|::
name|kw_false
argument_list|)
operator|.
name|get
argument_list|()
expr_stmt|;
block|}
return|return
name|ESI
return|;
block|}
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|/// \brief Determine what sort of exception specification a defaulted
end_comment

begin_comment
comment|/// copy constructor of a class will have.
end_comment

begin_function_decl
name|ImplicitExceptionSpecification
name|ComputeDefaultedDefaultCtorExceptionSpec
parameter_list|(
name|SourceLocation
name|Loc
parameter_list|,
name|CXXMethodDecl
modifier|*
name|MD
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// \brief Determine what sort of exception specification a defaulted
end_comment

begin_comment
comment|/// default constructor of a class will have, and whether the parameter
end_comment

begin_comment
comment|/// will be const.
end_comment

begin_function_decl
name|ImplicitExceptionSpecification
name|ComputeDefaultedCopyCtorExceptionSpec
parameter_list|(
name|CXXMethodDecl
modifier|*
name|MD
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// \brief Determine what sort of exception specification a defautled
end_comment

begin_comment
comment|/// copy assignment operator of a class will have, and whether the
end_comment

begin_comment
comment|/// parameter will be const.
end_comment

begin_function_decl
name|ImplicitExceptionSpecification
name|ComputeDefaultedCopyAssignmentExceptionSpec
parameter_list|(
name|CXXMethodDecl
modifier|*
name|MD
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// \brief Determine what sort of exception specification a defaulted move
end_comment

begin_comment
comment|/// constructor of a class will have.
end_comment

begin_function_decl
name|ImplicitExceptionSpecification
name|ComputeDefaultedMoveCtorExceptionSpec
parameter_list|(
name|CXXMethodDecl
modifier|*
name|MD
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// \brief Determine what sort of exception specification a defaulted move
end_comment

begin_comment
comment|/// assignment operator of a class will have.
end_comment

begin_function_decl
name|ImplicitExceptionSpecification
name|ComputeDefaultedMoveAssignmentExceptionSpec
parameter_list|(
name|CXXMethodDecl
modifier|*
name|MD
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// \brief Determine what sort of exception specification a defaulted
end_comment

begin_comment
comment|/// destructor of a class will have.
end_comment

begin_function_decl
name|ImplicitExceptionSpecification
name|ComputeDefaultedDtorExceptionSpec
parameter_list|(
name|CXXMethodDecl
modifier|*
name|MD
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// \brief Determine what sort of exception specification an inheriting
end_comment

begin_comment
comment|/// constructor of a class will have.
end_comment

begin_function_decl
name|ImplicitExceptionSpecification
name|ComputeInheritingCtorExceptionSpec
parameter_list|(
name|SourceLocation
name|Loc
parameter_list|,
name|CXXConstructorDecl
modifier|*
name|CD
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// \brief Evaluate the implicit exception specification for a defaulted
end_comment

begin_comment
comment|/// special member function.
end_comment

begin_function_decl
name|void
name|EvaluateImplicitExceptionSpec
parameter_list|(
name|SourceLocation
name|Loc
parameter_list|,
name|CXXMethodDecl
modifier|*
name|MD
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// \brief Check the given exception-specification and update the
end_comment

begin_comment
comment|/// exception specification information with the results.
end_comment

begin_decl_stmt
name|void
name|checkExceptionSpecification
argument_list|(
name|bool
name|IsTopLevel
argument_list|,
name|ExceptionSpecificationType
name|EST
argument_list|,
name|ArrayRef
operator|<
name|ParsedType
operator|>
name|DynamicExceptions
argument_list|,
name|ArrayRef
operator|<
name|SourceRange
operator|>
name|DynamicExceptionRanges
argument_list|,
name|Expr
operator|*
name|NoexceptExpr
argument_list|,
name|SmallVectorImpl
operator|<
name|QualType
operator|>
operator|&
name|Exceptions
argument_list|,
name|FunctionProtoType
operator|::
name|ExceptionSpecInfo
operator|&
name|ESI
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// \brief Determine if we're in a case where we need to (incorrectly) eagerly
end_comment

begin_comment
comment|/// parse an exception specification to work around a libstdc++ bug.
end_comment

begin_function_decl
name|bool
name|isLibstdcxxEagerExceptionSpecHack
parameter_list|(
specifier|const
name|Declarator
modifier|&
name|D
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// \brief Add an exception-specification to the given member function
end_comment

begin_comment
comment|/// (or member function template). The exception-specification was parsed
end_comment

begin_comment
comment|/// after the method itself was declared.
end_comment

begin_decl_stmt
name|void
name|actOnDelayedExceptionSpecification
argument_list|(
name|Decl
operator|*
name|Method
argument_list|,
name|ExceptionSpecificationType
name|EST
argument_list|,
name|SourceRange
name|SpecificationRange
argument_list|,
name|ArrayRef
operator|<
name|ParsedType
operator|>
name|DynamicExceptions
argument_list|,
name|ArrayRef
operator|<
name|SourceRange
operator|>
name|DynamicExceptionRanges
argument_list|,
name|Expr
operator|*
name|NoexceptExpr
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|class
name|InheritedConstructorInfo
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// \brief Determine if a special member function should have a deleted
end_comment

begin_comment
comment|/// definition when it is defaulted.
end_comment

begin_function_decl
name|bool
name|ShouldDeleteSpecialMember
parameter_list|(
name|CXXMethodDecl
modifier|*
name|MD
parameter_list|,
name|CXXSpecialMember
name|CSM
parameter_list|,
name|InheritedConstructorInfo
modifier|*
name|ICI
init|=
name|nullptr
parameter_list|,
name|bool
name|Diagnose
init|=
name|false
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
comment|/// \brief Build an exception spec for destructors that don't have one.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// C++11 says that user-defined destructors with no exception spec get one
end_comment

begin_comment
comment|/// that looks as if the destructor was implicitly declared.
end_comment

begin_function_decl
name|void
name|AdjustDestructorExceptionSpec
parameter_list|(
name|CXXRecordDecl
modifier|*
name|ClassDecl
parameter_list|,
name|CXXDestructorDecl
modifier|*
name|Destructor
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// \brief Define the specified inheriting constructor.
end_comment

begin_function_decl
name|void
name|DefineInheritingConstructor
parameter_list|(
name|SourceLocation
name|UseLoc
parameter_list|,
name|CXXConstructorDecl
modifier|*
name|Constructor
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
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// \brief Declare the implicit move constructor for the given class.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param ClassDecl The Class declaration into which the implicit
end_comment

begin_comment
comment|/// move constructor will be added.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \returns The implicitly-declared move constructor, or NULL if it wasn't
end_comment

begin_comment
comment|/// declared.
end_comment

begin_function_decl
name|CXXConstructorDecl
modifier|*
name|DeclareImplicitMoveConstructor
parameter_list|(
name|CXXRecordDecl
modifier|*
name|ClassDecl
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// DefineImplicitMoveConstructor - Checks for feasibility of
end_comment

begin_comment
comment|/// defining this constructor as the move constructor.
end_comment

begin_function_decl
name|void
name|DefineImplicitMoveConstructor
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
comment|/// \brief Declare the implicit copy assignment operator for the given class.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param ClassDecl The class declaration into which the implicit
end_comment

begin_comment
comment|/// copy assignment operator will be added.
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
comment|/// \brief Defines an implicitly-declared copy assignment operator.
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
comment|/// \brief Declare the implicit move assignment operator for the given class.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param ClassDecl The Class declaration into which the implicit
end_comment

begin_comment
comment|/// move assignment operator will be added.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \returns The implicitly-declared move assignment operator, or NULL if it
end_comment

begin_comment
comment|/// wasn't declared.
end_comment

begin_function_decl
name|CXXMethodDecl
modifier|*
name|DeclareImplicitMoveAssignment
parameter_list|(
name|CXXRecordDecl
modifier|*
name|ClassDecl
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// \brief Defines an implicitly-declared move assignment operator.
end_comment

begin_function_decl
name|void
name|DefineImplicitMoveAssignment
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
comment|/// \brief Check a completed declaration of an implicit special member.
end_comment

begin_function_decl
name|void
name|CheckImplicitSpecialMemberDeclaration
parameter_list|(
name|Scope
modifier|*
name|S
parameter_list|,
name|FunctionDecl
modifier|*
name|FD
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// \brief Determine whether the given function is an implicitly-deleted
end_comment

begin_comment
comment|/// special member function.
end_comment

begin_function_decl
name|bool
name|isImplicitlyDeleted
parameter_list|(
name|FunctionDecl
modifier|*
name|FD
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// \brief Check whether 'this' shows up in the type of a static member
end_comment

begin_comment
comment|/// function after the (naturally empty) cv-qualifier-seq would be.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \returns true if an error occurred.
end_comment

begin_function_decl
name|bool
name|checkThisInStaticMemberFunctionType
parameter_list|(
name|CXXMethodDecl
modifier|*
name|Method
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// \brief Whether this' shows up in the exception specification of a static
end_comment

begin_comment
comment|/// member function.
end_comment

begin_function_decl
name|bool
name|checkThisInStaticMemberFunctionExceptionSpec
parameter_list|(
name|CXXMethodDecl
modifier|*
name|Method
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// \brief Check whether 'this' shows up in the attributes of the given
end_comment

begin_comment
comment|/// static member function.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \returns true if an error occurred.
end_comment

begin_function_decl
name|bool
name|checkThisInStaticMemberFunctionAttributes
parameter_list|(
name|CXXMethodDecl
modifier|*
name|Method
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
name|SmallVectorImpl
operator|<
name|Expr
operator|*
operator|>
operator|&
name|ConvertedArgs
argument_list|,
name|bool
name|AllowExplicit
operator|=
name|false
argument_list|,
name|bool
name|IsListInitialization
operator|=
name|false
argument_list|)
decl_stmt|;
end_decl_stmt

begin_function_decl
name|ParsedType
name|getInheritingConstructorName
parameter_list|(
name|CXXScopeSpec
modifier|&
name|SS
parameter_list|,
name|SourceLocation
name|NameLoc
parameter_list|,
name|IdentifierInfo
modifier|&
name|Name
parameter_list|)
function_decl|;
end_function_decl

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

begin_function_decl
name|ParsedType
name|getDestructorTypeForDecltype
parameter_list|(
specifier|const
name|DeclSpec
modifier|&
name|DS
parameter_list|,
name|ParsedType
name|ObjectType
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|// Checks that reinterpret casts don't have undefined behavior.
end_comment

begin_function_decl
name|void
name|CheckCompatibleReinterpretCast
parameter_list|(
name|QualType
name|SrcType
parameter_list|,
name|QualType
name|DestType
parameter_list|,
name|bool
name|IsDereference
parameter_list|,
name|SourceRange
name|Range
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
name|Declarator
operator|&
name|D
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
comment|/// \brief Handle a C++1z fold-expression: ( expr op ... op expr ).
end_comment

begin_decl_stmt
name|ExprResult
name|ActOnCXXFoldExpr
argument_list|(
name|SourceLocation
name|LParenLoc
argument_list|,
name|Expr
operator|*
name|LHS
argument_list|,
name|tok
operator|::
name|TokenKind
name|Operator
argument_list|,
name|SourceLocation
name|EllipsisLoc
argument_list|,
name|Expr
operator|*
name|RHS
argument_list|,
name|SourceLocation
name|RParenLoc
argument_list|)
decl_stmt|;
end_decl_stmt

begin_function_decl
name|ExprResult
name|BuildCXXFoldExpr
parameter_list|(
name|SourceLocation
name|LParenLoc
parameter_list|,
name|Expr
modifier|*
name|LHS
parameter_list|,
name|BinaryOperatorKind
name|Operator
parameter_list|,
name|SourceLocation
name|EllipsisLoc
parameter_list|,
name|Expr
modifier|*
name|RHS
parameter_list|,
name|SourceLocation
name|RParenLoc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ExprResult
name|BuildEmptyCXXFoldExpr
parameter_list|(
name|SourceLocation
name|EllipsisLoc
parameter_list|,
name|BinaryOperatorKind
name|Operator
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
comment|/// \brief Try to retrieve the type of the 'this' pointer.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \returns The type of 'this', if possible. Otherwise, returns a NULL type.
end_comment

begin_function_decl
name|QualType
name|getCurrentThisType
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/// \brief When non-NULL, the C++ 'this' expression is allowed despite the
end_comment

begin_comment
comment|/// current context not being a non-static member function. In such cases,
end_comment

begin_comment
comment|/// this provides the type used for 'this'.
end_comment

begin_decl_stmt
name|QualType
name|CXXThisTypeOverride
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// \brief RAII object used to temporarily allow the C++ 'this' expression
end_comment

begin_comment
comment|/// to be used, with the given qualifiers on the current class type.
end_comment

begin_decl_stmt
name|class
name|CXXThisScopeRAII
block|{
name|Sema
modifier|&
name|S
decl_stmt|;
name|QualType
name|OldCXXThisTypeOverride
decl_stmt|;
name|bool
name|Enabled
decl_stmt|;
name|public
label|:
comment|/// \brief Introduce a new scope where 'this' may be allowed (when enabled),
comment|/// using the given declaration (which is either a class template or a
comment|/// class) along with the given qualifiers.
comment|/// along with the qualifiers placed on '*this'.
name|CXXThisScopeRAII
argument_list|(
argument|Sema&S
argument_list|,
argument|Decl *ContextDecl
argument_list|,
argument|unsigned CXXThisTypeQuals
argument_list|,
argument|bool Enabled = true
argument_list|)
empty_stmt|;
operator|~
name|CXXThisScopeRAII
argument_list|()
expr_stmt|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|/// \brief Make sure the value of 'this' is actually available in the current
end_comment

begin_comment
comment|/// context, if it is a potentially evaluated context.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param Loc The location at which the capture of 'this' occurs.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param Explicit Whether 'this' is explicitly captured in a lambda
end_comment

begin_comment
comment|/// capture list.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param FunctionScopeIndexToStopAt If non-null, it points to the index
end_comment

begin_comment
comment|/// of the FunctionScopeInfo stack beyond which we do not attempt to capture.
end_comment

begin_comment
comment|/// This is useful when enclosing lambdas must speculatively capture
end_comment

begin_comment
comment|/// 'this' that may or may not be used in certain specializations of
end_comment

begin_comment
comment|/// a nested generic lambda (depending on whether the name resolves to
end_comment

begin_comment
comment|/// a non-static member function or a static function).
end_comment

begin_comment
comment|/// \return returns 'true' if failed, 'false' if success.
end_comment

begin_function_decl
name|bool
name|CheckCXXThisCapture
parameter_list|(
name|SourceLocation
name|Loc
parameter_list|,
name|bool
name|Explicit
init|=
name|false
parameter_list|,
name|bool
name|BuildAndDiagnose
init|=
name|true
parameter_list|,
specifier|const
name|unsigned
modifier|*
specifier|const
name|FunctionScopeIndexToStopAt
init|=
name|nullptr
parameter_list|,
name|bool
name|ByCopy
init|=
name|false
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// \brief Determine whether the given type is the type of *this that is used
end_comment

begin_comment
comment|/// outside of the body of a member function for a type that is currently
end_comment

begin_comment
comment|/// being defined.
end_comment

begin_function_decl
name|bool
name|isThisOutsideMemberFunctionBody
parameter_list|(
name|QualType
name|BaseType
parameter_list|)
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
comment|/// ActOnObjCBoolLiteral - Parse {__objc_yes,__objc_no} literals.
end_comment

begin_decl_stmt
name|ExprResult
name|ActOnObjCBoolLiteral
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

begin_decl_stmt
name|ExprResult
name|ActOnObjCAvailabilityCheckExpr
argument_list|(
name|llvm
operator|::
name|ArrayRef
operator|<
name|AvailabilitySpec
operator|>
name|AvailSpecs
argument_list|,
name|SourceLocation
name|AtLoc
argument_list|,
name|SourceLocation
name|RParen
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
name|Scope
modifier|*
name|S
parameter_list|,
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
name|BuildCXXThrow
parameter_list|(
name|SourceLocation
name|OpLoc
parameter_list|,
name|Expr
modifier|*
name|Ex
parameter_list|,
name|bool
name|IsThrownVarInScope
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
name|QualType
name|ThrowTy
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
name|Expr
modifier|*
name|Initializer
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ExprResult
name|BuildCXXNew
parameter_list|(
name|SourceRange
name|Range
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
name|SourceRange
name|DirectInitRange
parameter_list|,
name|Expr
modifier|*
name|Initializer
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
name|bool
modifier|&
name|PassAlignment
parameter_list|,
name|MultiExprArg
name|PlaceArgs
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
name|void
name|DeclareGlobalNewDelete
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
name|void
name|DeclareGlobalAllocationFunction
argument_list|(
name|DeclarationName
name|Name
argument_list|,
name|QualType
name|Return
argument_list|,
name|ArrayRef
operator|<
name|QualType
operator|>
name|Params
argument_list|)
decl_stmt|;
end_decl_stmt

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
parameter_list|,
name|bool
name|Diagnose
init|=
name|true
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|FunctionDecl
modifier|*
name|FindUsualDeallocationFunction
parameter_list|(
name|SourceLocation
name|StartLoc
parameter_list|,
name|bool
name|CanProvideSize
parameter_list|,
name|bool
name|Overaligned
parameter_list|,
name|DeclarationName
name|Name
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|FunctionDecl
modifier|*
name|FindDeallocationFunctionForDestructor
parameter_list|(
name|SourceLocation
name|StartLoc
parameter_list|,
name|CXXRecordDecl
modifier|*
name|RD
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
name|void
name|CheckVirtualDtorCall
parameter_list|(
name|CXXDestructorDecl
modifier|*
name|dtor
parameter_list|,
name|SourceLocation
name|Loc
parameter_list|,
name|bool
name|IsDelete
parameter_list|,
name|bool
name|CallCanBeVirtual
parameter_list|,
name|bool
name|WarnOnNonAbstractTypes
parameter_list|,
name|SourceLocation
name|DtorLoc
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
comment|/// \brief Parsed one of the type trait support pseudo-functions.
end_comment

begin_decl_stmt
name|ExprResult
name|ActOnTypeTrait
argument_list|(
name|TypeTrait
name|Kind
argument_list|,
name|SourceLocation
name|KWLoc
argument_list|,
name|ArrayRef
operator|<
name|ParsedType
operator|>
name|Args
argument_list|,
name|SourceLocation
name|RParenLoc
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|ExprResult
name|BuildTypeTrait
argument_list|(
name|TypeTrait
name|Kind
argument_list|,
name|SourceLocation
name|KWLoc
argument_list|,
name|ArrayRef
operator|<
name|TypeSourceInfo
operator|*
operator|>
name|Args
argument_list|,
name|SourceLocation
name|RParenLoc
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// ActOnArrayTypeTrait - Parsed one of the binary type trait support
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
name|SourceLocation
name|TildeLoc
argument_list|,
specifier|const
name|DeclSpec
operator|&
name|DS
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
name|MaterializeTemporaryExpr
modifier|*
name|CreateMaterializeTemporaryExpr
parameter_list|(
name|QualType
name|T
parameter_list|,
name|Expr
modifier|*
name|Temporary
parameter_list|,
name|bool
name|BoundToLvalueReference
parameter_list|)
function_decl|;
end_function_decl

begin_function
name|ExprResult
name|ActOnFinishFullExpr
parameter_list|(
name|Expr
modifier|*
name|Expr
parameter_list|)
block|{
return|return
name|ActOnFinishFullExpr
argument_list|(
name|Expr
argument_list|,
name|Expr
condition|?
name|Expr
operator|->
name|getExprLoc
argument_list|()
else|:
name|SourceLocation
argument_list|()
argument_list|)
return|;
block|}
end_function

begin_function_decl
name|ExprResult
name|ActOnFinishFullExpr
parameter_list|(
name|Expr
modifier|*
name|Expr
parameter_list|,
name|SourceLocation
name|CC
parameter_list|,
name|bool
name|DiscardedValue
init|=
name|false
parameter_list|,
name|bool
name|IsConstexpr
init|=
name|false
parameter_list|,
name|bool
name|IsLambdaInitCaptureInitializer
init|=
name|false
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

begin_comment
comment|/// \brief The parser has parsed a global nested-name-specifier '::'.
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
name|SourceLocation
name|CCLoc
parameter_list|,
name|CXXScopeSpec
modifier|&
name|SS
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// \brief The parser has parsed a '__super' nested-name-specifier.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param SuperLoc The location of the '__super' keyword.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param ColonColonLoc The location of the '::'.
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
name|ActOnSuperScopeSpecifier
parameter_list|(
name|SourceLocation
name|SuperLoc
parameter_list|,
name|SourceLocation
name|ColonColonLoc
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
specifier|const
name|NamedDecl
modifier|*
name|SD
parameter_list|,
name|bool
modifier|*
name|CanCorrect
init|=
name|nullptr
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

begin_comment
comment|/// \brief Keeps information about an identifier in a nested-name-spec.
end_comment

begin_comment
comment|///
end_comment

begin_struct
struct|struct
name|NestedNameSpecInfo
block|{
comment|/// \brief The type of the object, if we're parsing nested-name-specifier in
comment|/// a member access expression.
name|ParsedType
name|ObjectType
decl_stmt|;
comment|/// \brief The identifier preceding the '::'.
name|IdentifierInfo
modifier|*
name|Identifier
decl_stmt|;
comment|/// \brief The location of the identifier.
name|SourceLocation
name|IdentifierLoc
decl_stmt|;
comment|/// \brief The location of the '::'.
name|SourceLocation
name|CCLoc
decl_stmt|;
comment|/// \brief Creates info object for the most typical case.
name|NestedNameSpecInfo
argument_list|(
argument|IdentifierInfo *II
argument_list|,
argument|SourceLocation IdLoc
argument_list|,
argument|SourceLocation ColonColonLoc
argument_list|,
argument|ParsedType ObjectType = ParsedType()
argument_list|)
block|:
name|ObjectType
argument_list|(
name|ObjectType
argument_list|)
operator|,
name|Identifier
argument_list|(
name|II
argument_list|)
operator|,
name|IdentifierLoc
argument_list|(
name|IdLoc
argument_list|)
operator|,
name|CCLoc
argument_list|(
argument|ColonColonLoc
argument_list|)
block|{     }
name|NestedNameSpecInfo
argument_list|(
argument|IdentifierInfo *II
argument_list|,
argument|SourceLocation IdLoc
argument_list|,
argument|SourceLocation ColonColonLoc
argument_list|,
argument|QualType ObjectType
argument_list|)
operator|:
name|ObjectType
argument_list|(
name|ParsedType
operator|::
name|make
argument_list|(
name|ObjectType
argument_list|)
argument_list|)
operator|,
name|Identifier
argument_list|(
name|II
argument_list|)
operator|,
name|IdentifierLoc
argument_list|(
name|IdLoc
argument_list|)
operator|,
name|CCLoc
argument_list|(
argument|ColonColonLoc
argument_list|)
block|{     }
block|}
struct|;
end_struct

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
name|NestedNameSpecInfo
modifier|&
name|IdInfo
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
name|NestedNameSpecInfo
modifier|&
name|IdInfo
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
parameter_list|,
name|bool
modifier|*
name|IsCorrectedToColon
init|=
name|nullptr
parameter_list|,
name|bool
name|OnlyNamespace
init|=
name|false
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
comment|/// \param IdInfo Parser information about an identifier in the
end_comment

begin_comment
comment|/// nested-name-spec.
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
comment|/// \param ErrorRecoveryLookup If true, then this method is called to improve
end_comment

begin_comment
comment|/// error recovery. In this case do not emit error message.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param IsCorrectedToColon If not null, suggestions to replace '::' -> ':'
end_comment

begin_comment
comment|/// are allowed.  The bool value pointed by this parameter is set to 'true'
end_comment

begin_comment
comment|/// if the identifier is treated as if it was followed by ':', not '::'.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param OnlyNamespace If true, only considers namespaces in lookup.
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
name|NestedNameSpecInfo
modifier|&
name|IdInfo
parameter_list|,
name|bool
name|EnteringContext
parameter_list|,
name|CXXScopeSpec
modifier|&
name|SS
parameter_list|,
name|bool
name|ErrorRecoveryLookup
init|=
name|false
parameter_list|,
name|bool
modifier|*
name|IsCorrectedToColon
init|=
name|nullptr
parameter_list|,
name|bool
name|OnlyNamespace
init|=
name|false
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ExprResult
name|ActOnDecltypeExpression
parameter_list|(
name|Expr
modifier|*
name|E
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|ActOnCXXNestedNameSpecifierDecltype
parameter_list|(
name|CXXScopeSpec
modifier|&
name|SS
parameter_list|,
specifier|const
name|DeclSpec
modifier|&
name|DS
parameter_list|,
name|SourceLocation
name|ColonColonLoc
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
name|NestedNameSpecInfo
modifier|&
name|IdInfo
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
comment|/// \param TemplateKWLoc the location of the 'template' keyword, if any.
end_comment

begin_comment
comment|/// \param TemplateName the template name.
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
comment|///
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
name|CXXScopeSpec
modifier|&
name|SS
parameter_list|,
name|SourceLocation
name|TemplateKWLoc
parameter_list|,
name|TemplateTy
name|TemplateName
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
comment|/// \brief Create a new lambda closure type.
end_comment

begin_function_decl
name|CXXRecordDecl
modifier|*
name|createLambdaClosureType
parameter_list|(
name|SourceRange
name|IntroducerRange
parameter_list|,
name|TypeSourceInfo
modifier|*
name|Info
parameter_list|,
name|bool
name|KnownDependent
parameter_list|,
name|LambdaCaptureDefault
name|CaptureDefault
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// \brief Start the definition of a lambda expression.
end_comment

begin_decl_stmt
name|CXXMethodDecl
modifier|*
name|startLambdaDefinition
argument_list|(
name|CXXRecordDecl
operator|*
name|Class
argument_list|,
name|SourceRange
name|IntroducerRange
argument_list|,
name|TypeSourceInfo
operator|*
name|MethodType
argument_list|,
name|SourceLocation
name|EndLoc
argument_list|,
name|ArrayRef
operator|<
name|ParmVarDecl
operator|*
operator|>
name|Params
argument_list|,
name|bool
name|IsConstexprSpecified
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// \brief Endow the lambda scope info with the relevant properties.
end_comment

begin_decl_stmt
name|void
name|buildLambdaScope
argument_list|(
name|sema
operator|::
name|LambdaScopeInfo
operator|*
name|LSI
argument_list|,
name|CXXMethodDecl
operator|*
name|CallOperator
argument_list|,
name|SourceRange
name|IntroducerRange
argument_list|,
name|LambdaCaptureDefault
name|CaptureDefault
argument_list|,
name|SourceLocation
name|CaptureDefaultLoc
argument_list|,
name|bool
name|ExplicitParams
argument_list|,
name|bool
name|ExplicitResultType
argument_list|,
name|bool
name|Mutable
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// \brief Perform initialization analysis of the init-capture and perform
end_comment

begin_comment
comment|/// any implicit conversions such as an lvalue-to-rvalue conversion if
end_comment

begin_comment
comment|/// not being used to initialize a reference.
end_comment

begin_function
name|ParsedType
name|actOnLambdaInitCaptureInitialization
parameter_list|(
name|SourceLocation
name|Loc
parameter_list|,
name|bool
name|ByRef
parameter_list|,
name|IdentifierInfo
modifier|*
name|Id
parameter_list|,
name|LambdaCaptureInitKind
name|InitKind
parameter_list|,
name|Expr
modifier|*
modifier|&
name|Init
parameter_list|)
block|{
return|return
name|ParsedType
operator|::
name|make
argument_list|(
name|buildLambdaInitCaptureInitialization
argument_list|(
name|Loc
argument_list|,
name|ByRef
argument_list|,
name|Id
argument_list|,
name|InitKind
operator|!=
name|LambdaCaptureInitKind
operator|::
name|CopyInit
argument_list|,
name|Init
argument_list|)
argument_list|)
return|;
block|}
end_function

begin_function_decl
name|QualType
name|buildLambdaInitCaptureInitialization
parameter_list|(
name|SourceLocation
name|Loc
parameter_list|,
name|bool
name|ByRef
parameter_list|,
name|IdentifierInfo
modifier|*
name|Id
parameter_list|,
name|bool
name|DirectInit
parameter_list|,
name|Expr
modifier|*
modifier|&
name|Init
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// \brief Create a dummy variable within the declcontext of the lambda's
end_comment

begin_comment
comment|///  call operator, for name lookup purposes for a lambda init capture.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|///  CodeGen handles emission of lambda captures, ignoring these dummy
end_comment

begin_comment
comment|///  variables appropriately.
end_comment

begin_function_decl
name|VarDecl
modifier|*
name|createLambdaInitCaptureVarDecl
parameter_list|(
name|SourceLocation
name|Loc
parameter_list|,
name|QualType
name|InitCaptureType
parameter_list|,
name|IdentifierInfo
modifier|*
name|Id
parameter_list|,
name|unsigned
name|InitStyle
parameter_list|,
name|Expr
modifier|*
name|Init
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// \brief Build the implicit field for an init-capture.
end_comment

begin_decl_stmt
name|FieldDecl
modifier|*
name|buildInitCaptureField
argument_list|(
name|sema
operator|::
name|LambdaScopeInfo
operator|*
name|LSI
argument_list|,
name|VarDecl
operator|*
name|Var
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// \brief Note that we have finished the explicit captures for the
end_comment

begin_comment
comment|/// given lambda.
end_comment

begin_decl_stmt
name|void
name|finishLambdaExplicitCaptures
argument_list|(
name|sema
operator|::
name|LambdaScopeInfo
operator|*
name|LSI
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// \brief Introduce the lambda parameters into scope.
end_comment

begin_function_decl
name|void
name|addLambdaParameters
parameter_list|(
name|CXXMethodDecl
modifier|*
name|CallOperator
parameter_list|,
name|Scope
modifier|*
name|CurScope
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// \brief Deduce a block or lambda's return type based on the return
end_comment

begin_comment
comment|/// statements present in the body.
end_comment

begin_decl_stmt
name|void
name|deduceClosureReturnType
argument_list|(
name|sema
operator|::
name|CapturingScopeInfo
operator|&
name|CSI
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// ActOnStartOfLambdaDefinition - This is called just before we start
end_comment

begin_comment
comment|/// parsing the body of a lambda; it analyzes the explicit captures and
end_comment

begin_comment
comment|/// arguments, and sets up various data-structures for the body of the
end_comment

begin_comment
comment|/// lambda.
end_comment

begin_function_decl
name|void
name|ActOnStartOfLambdaDefinition
parameter_list|(
name|LambdaIntroducer
modifier|&
name|Intro
parameter_list|,
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
comment|/// ActOnLambdaError - If there is an error parsing a lambda, this callback
end_comment

begin_comment
comment|/// is invoked to pop the information about the lambda.
end_comment

begin_function_decl
name|void
name|ActOnLambdaError
parameter_list|(
name|SourceLocation
name|StartLoc
parameter_list|,
name|Scope
modifier|*
name|CurScope
parameter_list|,
name|bool
name|IsInstantiation
init|=
name|false
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// ActOnLambdaExpr - This is called when the body of a lambda expression
end_comment

begin_comment
comment|/// was successfully completed.
end_comment

begin_function_decl
name|ExprResult
name|ActOnLambdaExpr
parameter_list|(
name|SourceLocation
name|StartLoc
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
comment|/// \brief Does copying/destroying the captured variable have side effects?
end_comment

begin_decl_stmt
name|bool
name|CaptureHasSideEffects
argument_list|(
specifier|const
name|sema
operator|::
name|LambdaScopeInfo
operator|::
name|Capture
operator|&
name|From
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// \brief Diagnose if an explicit lambda capture is unused.
end_comment

begin_decl_stmt
name|void
name|DiagnoseUnusedLambdaCapture
argument_list|(
specifier|const
name|sema
operator|::
name|LambdaScopeInfo
operator|::
name|Capture
operator|&
name|From
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// \brief Complete a lambda-expression having processed and attached the
end_comment

begin_comment
comment|/// lambda body.
end_comment

begin_decl_stmt
name|ExprResult
name|BuildLambdaExpr
argument_list|(
name|SourceLocation
name|StartLoc
argument_list|,
name|SourceLocation
name|EndLoc
argument_list|,
name|sema
operator|::
name|LambdaScopeInfo
operator|*
name|LSI
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// \brief Define the "body" of the conversion from a lambda object to a
end_comment

begin_comment
comment|/// function pointer.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This routine doesn't actually define a sensible body; rather, it fills
end_comment

begin_comment
comment|/// in the initialization expression needed to copy the lambda object into
end_comment

begin_comment
comment|/// the block, and IR generation actually generates the real body of the
end_comment

begin_comment
comment|/// block pointer conversion.
end_comment

begin_function_decl
name|void
name|DefineImplicitLambdaToFunctionPointerConversion
parameter_list|(
name|SourceLocation
name|CurrentLoc
parameter_list|,
name|CXXConversionDecl
modifier|*
name|Conv
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// \brief Define the "body" of the conversion from a lambda object to a
end_comment

begin_comment
comment|/// block pointer.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This routine doesn't actually define a sensible body; rather, it fills
end_comment

begin_comment
comment|/// in the initialization expression needed to copy the lambda object into
end_comment

begin_comment
comment|/// the block, and IR generation actually generates the real body of the
end_comment

begin_comment
comment|/// block pointer conversion.
end_comment

begin_function_decl
name|void
name|DefineImplicitLambdaToBlockPointerConversion
parameter_list|(
name|SourceLocation
name|CurrentLoc
parameter_list|,
name|CXXConversionDecl
modifier|*
name|Conv
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ExprResult
name|BuildBlockForLambdaConversion
parameter_list|(
name|SourceLocation
name|CurrentLocation
parameter_list|,
name|SourceLocation
name|ConvLocation
parameter_list|,
name|CXXConversionDecl
modifier|*
name|Conv
parameter_list|,
name|Expr
modifier|*
name|Src
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|// ParseObjCStringLiteral - Parse Objective-C string literals.
end_comment

begin_decl_stmt
name|ExprResult
name|ParseObjCStringLiteral
argument_list|(
name|SourceLocation
operator|*
name|AtLocs
argument_list|,
name|ArrayRef
operator|<
name|Expr
operator|*
operator|>
name|Strings
argument_list|)
decl_stmt|;
end_decl_stmt

begin_function_decl
name|ExprResult
name|BuildObjCStringLiteral
parameter_list|(
name|SourceLocation
name|AtLoc
parameter_list|,
name|StringLiteral
modifier|*
name|S
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// BuildObjCNumericLiteral - builds an ObjCBoxedExpr AST node for the
end_comment

begin_comment
comment|/// numeric literal expression. Type of the expression will be "NSNumber *"
end_comment

begin_comment
comment|/// or "id" if NSNumber is unavailable.
end_comment

begin_function_decl
name|ExprResult
name|BuildObjCNumericLiteral
parameter_list|(
name|SourceLocation
name|AtLoc
parameter_list|,
name|Expr
modifier|*
name|Number
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ExprResult
name|ActOnObjCBoolLiteral
parameter_list|(
name|SourceLocation
name|AtLoc
parameter_list|,
name|SourceLocation
name|ValueLoc
parameter_list|,
name|bool
name|Value
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ExprResult
name|BuildObjCArrayLiteral
parameter_list|(
name|SourceRange
name|SR
parameter_list|,
name|MultiExprArg
name|Elements
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// BuildObjCBoxedExpr - builds an ObjCBoxedExpr AST node for the
end_comment

begin_comment
comment|/// '@' prefixed parenthesized expression. The type of the expression will
end_comment

begin_comment
comment|/// either be "NSNumber *", "NSString *" or "NSValue *" depending on the type
end_comment

begin_comment
comment|/// of ValueType, which is allowed to be a built-in numeric type, "char *",
end_comment

begin_comment
comment|/// "const char *" or C structure with attribute 'objc_boxable'.
end_comment

begin_function_decl
name|ExprResult
name|BuildObjCBoxedExpr
parameter_list|(
name|SourceRange
name|SR
parameter_list|,
name|Expr
modifier|*
name|ValueExpr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ExprResult
name|BuildObjCSubscriptExpression
parameter_list|(
name|SourceLocation
name|RB
parameter_list|,
name|Expr
modifier|*
name|BaseExpr
parameter_list|,
name|Expr
modifier|*
name|IndexExpr
parameter_list|,
name|ObjCMethodDecl
modifier|*
name|getterMethod
parameter_list|,
name|ObjCMethodDecl
modifier|*
name|setterMethod
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
name|ExprResult
name|BuildObjCDictionaryLiteral
argument_list|(
name|SourceRange
name|SR
argument_list|,
name|MutableArrayRef
operator|<
name|ObjCDictionaryElement
operator|>
name|Elements
argument_list|)
decl_stmt|;
end_decl_stmt

begin_function_decl
name|ExprResult
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
name|CXXConversionDecl
modifier|*
name|Method
parameter_list|,
name|bool
name|HadMultipleCandidates
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
comment|/// ParseObjCSelectorExpression - Build selector expression for \@selector
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
parameter_list|,
name|bool
name|WarnMultipleSelectors
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// ParseObjCProtocolExpression - Build protocol expression for \@protocol
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
name|ProtoIdLoc
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

begin_function_decl
name|Decl
modifier|*
name|ActOnStartLinkageSpecification
parameter_list|(
name|Scope
modifier|*
name|S
parameter_list|,
name|SourceLocation
name|ExternLoc
parameter_list|,
name|Expr
modifier|*
name|LangStr
parameter_list|,
name|SourceLocation
name|LBraceLoc
parameter_list|)
function_decl|;
end_function_decl

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
name|nullptr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|isCurrentClassNameTypo
parameter_list|(
name|IdentifierInfo
modifier|*
modifier|&
name|II
parameter_list|,
specifier|const
name|CXXScopeSpec
modifier|*
name|SS
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool
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
parameter_list|,
name|AttributeList
modifier|*
name|Attrs
init|=
name|nullptr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|NamedDecl
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
name|InClassInitStyle
name|InitStyle
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ActOnStartCXXInClassMemberInitializer
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ActOnFinishCXXInClassMemberInitializer
parameter_list|(
name|Decl
modifier|*
name|VarDecl
parameter_list|,
name|SourceLocation
name|EqualLoc
parameter_list|,
name|Expr
modifier|*
name|Init
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
name|MemInitResult
name|ActOnMemInitializer
argument_list|(
name|Decl
operator|*
name|ConstructorD
argument_list|,
name|Scope
operator|*
name|S
argument_list|,
name|CXXScopeSpec
operator|&
name|SS
argument_list|,
name|IdentifierInfo
operator|*
name|MemberOrBase
argument_list|,
name|ParsedType
name|TemplateTypeTy
argument_list|,
specifier|const
name|DeclSpec
operator|&
name|DS
argument_list|,
name|SourceLocation
name|IdLoc
argument_list|,
name|SourceLocation
name|LParenLoc
argument_list|,
name|ArrayRef
operator|<
name|Expr
operator|*
operator|>
name|Args
argument_list|,
name|SourceLocation
name|RParenLoc
argument_list|,
name|SourceLocation
name|EllipsisLoc
argument_list|)
decl_stmt|;
end_decl_stmt

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
specifier|const
name|DeclSpec
modifier|&
name|DS
parameter_list|,
name|SourceLocation
name|IdLoc
parameter_list|,
name|Expr
modifier|*
name|InitList
parameter_list|,
name|SourceLocation
name|EllipsisLoc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|MemInitResult
name|BuildMemInitializer
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
specifier|const
name|DeclSpec
modifier|&
name|DS
parameter_list|,
name|SourceLocation
name|IdLoc
parameter_list|,
name|Expr
modifier|*
name|Init
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
name|Init
parameter_list|,
name|SourceLocation
name|IdLoc
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
name|Init
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
name|Init
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

begin_decl_stmt
name|bool
name|SetCtorInitializers
argument_list|(
name|CXXConstructorDecl
operator|*
name|Constructor
argument_list|,
name|bool
name|AnyErrors
argument_list|,
name|ArrayRef
operator|<
name|CXXCtorInitializer
operator|*
operator|>
name|Initializers
operator|=
name|None
argument_list|)
decl_stmt|;
end_decl_stmt

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
comment|/// \brief Load any externally-stored vtable uses.
end_comment

begin_function_decl
name|void
name|LoadExternalVTableUses
parameter_list|()
function_decl|;
end_function_decl

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
comment|/// \brief Mark the exception specifications of all virtual member functions
end_comment

begin_comment
comment|/// in the given class as needed.
end_comment

begin_function_decl
name|void
name|MarkVirtualMemberExceptionSpecsNeeded
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

begin_decl_stmt
name|void
name|ActOnMemInitializers
argument_list|(
name|Decl
operator|*
name|ConstructorDecl
argument_list|,
name|SourceLocation
name|ColonLoc
argument_list|,
name|ArrayRef
operator|<
name|CXXCtorInitializer
operator|*
operator|>
name|MemInits
argument_list|,
name|bool
name|AnyErrors
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// \brief Check class-level dllimport/dllexport attribute. The caller must
end_comment

begin_comment
comment|/// ensure that referenceDLLExportedClassMethods is called some point later
end_comment

begin_comment
comment|/// when all outer classes of Class are complete.
end_comment

begin_function_decl
name|void
name|checkClassLevelDLLAttribute
parameter_list|(
name|CXXRecordDecl
modifier|*
name|Class
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|referenceDLLExportedClassMethods
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|propagateDLLAttrToBaseClassTemplate
parameter_list|(
name|CXXRecordDecl
modifier|*
name|Class
parameter_list|,
name|Attr
modifier|*
name|ClassAttr
parameter_list|,
name|ClassTemplateSpecializationDecl
modifier|*
name|BaseTemplateSpec
parameter_list|,
name|SourceLocation
name|BaseLoc
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
name|ActOnFinishCXXMemberDecls
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ActOnFinishCXXNonNestedClass
parameter_list|(
name|Decl
modifier|*
name|D
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ActOnReenterCXXMethodParameter
parameter_list|(
name|Scope
modifier|*
name|S
parameter_list|,
name|ParmVarDecl
modifier|*
name|Param
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|unsigned
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
name|ActOnFinishDelayedMemberInitializers
parameter_list|(
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
name|Decl
modifier|*
name|FnD
parameter_list|,
name|CachedTokens
modifier|&
name|Toks
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|UnmarkAsLateParsedTemplate
parameter_list|(
name|FunctionDecl
modifier|*
name|FD
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
name|Decl
modifier|*
name|BuildStaticAssertDeclaration
parameter_list|(
name|SourceLocation
name|StaticAssertLoc
parameter_list|,
name|Expr
modifier|*
name|AssertExpr
parameter_list|,
name|StringLiteral
modifier|*
name|AssertMessageExpr
parameter_list|,
name|SourceLocation
name|RParenLoc
parameter_list|,
name|bool
name|Failed
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|FriendDecl
modifier|*
name|CheckFriendTypeDecl
parameter_list|(
name|SourceLocation
name|LocStart
parameter_list|,
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
name|NamedDecl
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

begin_function_decl
name|void
name|CheckDeductionGuideDeclarator
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
name|void
name|CheckDeductionGuideTemplate
parameter_list|(
name|FunctionTemplateDecl
modifier|*
name|TD
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|CheckExplicitlyDefaultedSpecialMember
parameter_list|(
name|CXXMethodDecl
modifier|*
name|MD
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|CheckExplicitlyDefaultedMemberExceptionSpec
parameter_list|(
name|CXXMethodDecl
modifier|*
name|MD
parameter_list|,
specifier|const
name|FunctionProtoType
modifier|*
name|T
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|CheckDelayedMemberExceptionSpecs
parameter_list|()
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
name|ParsedAttributes
modifier|&
name|Attrs
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

begin_decl_stmt
name|bool
name|AttachBaseSpecifiers
argument_list|(
name|CXXRecordDecl
operator|*
name|Class
argument_list|,
name|MutableArrayRef
operator|<
name|CXXBaseSpecifier
operator|*
operator|>
name|Bases
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|ActOnBaseSpecifiers
argument_list|(
name|Decl
operator|*
name|ClassDecl
argument_list|,
name|MutableArrayRef
operator|<
name|CXXBaseSpecifier
operator|*
operator|>
name|Bases
argument_list|)
decl_stmt|;
end_decl_stmt

begin_function_decl
name|bool
name|IsDerivedFrom
parameter_list|(
name|SourceLocation
name|Loc
parameter_list|,
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
name|SourceLocation
name|Loc
parameter_list|,
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
name|nullptr
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
parameter_list|,
name|bool
name|IgnoreAccess
init|=
name|false
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
comment|/// CheckOverrideControl - Check C++11 override control semantics.
end_comment

begin_function_decl
name|void
name|CheckOverrideControl
parameter_list|(
name|NamedDecl
modifier|*
name|D
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// DiagnoseAbsenceOfOverrideControl - Diagnose if 'override' keyword was
end_comment

begin_comment
comment|/// not used in the declaration of an overriding method.
end_comment

begin_function_decl
name|void
name|DiagnoseAbsenceOfOverrideControl
parameter_list|(
name|NamedDecl
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
comment|/// C++11 [class.virtual]p4.
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
parameter_list|,
name|bool
name|Diagnose
init|=
name|true
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
name|DeclAccessPair
name|FoundDecl
parameter_list|,
specifier|const
name|InitializedEntity
modifier|&
name|Entity
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
name|CheckConstructorAccess
parameter_list|(
name|SourceLocation
name|Loc
parameter_list|,
name|CXXConstructorDecl
modifier|*
name|D
parameter_list|,
name|DeclAccessPair
name|FoundDecl
parameter_list|,
specifier|const
name|InitializedEntity
modifier|&
name|Entity
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
parameter_list|,
name|QualType
name|objectType
init|=
name|QualType
argument_list|()
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|AccessResult
name|CheckFriendAccess
parameter_list|(
name|NamedDecl
modifier|*
name|D
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|AccessResult
name|CheckMemberAccess
parameter_list|(
name|SourceLocation
name|UseLoc
parameter_list|,
name|CXXRecordDecl
modifier|*
name|NamingClass
parameter_list|,
name|DeclAccessPair
name|Found
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
name|bool
name|IsSimplyAccessible
parameter_list|(
name|NamedDecl
modifier|*
name|decl
parameter_list|,
name|DeclContext
modifier|*
name|Ctx
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|isSpecialMemberAccessibleForDeletion
parameter_list|(
name|CXXMethodDecl
modifier|*
name|decl
parameter_list|,
name|AccessSpecifier
name|access
parameter_list|,
name|QualType
name|objectType
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
name|AbstractIvarType
block|,
name|AbstractSynthesizedIvarType
block|,
name|AbstractArrayType
block|}
enum|;
end_enum

begin_function_decl
name|bool
name|isAbstractType
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
name|RequireNonAbstractType
parameter_list|(
name|SourceLocation
name|Loc
parameter_list|,
name|QualType
name|T
parameter_list|,
name|TypeDiagnoser
modifier|&
name|Diagnoser
parameter_list|)
function_decl|;
end_function_decl

begin_expr_stmt
name|template
operator|<
name|typename
operator|...
name|Ts
operator|>
name|bool
name|RequireNonAbstractType
argument_list|(
argument|SourceLocation Loc
argument_list|,
argument|QualType T
argument_list|,
argument|unsigned DiagID
argument_list|,
argument|const Ts&...Args
argument_list|)
block|{
name|BoundTypeDiagnoser
operator|<
name|Ts
operator|...
operator|>
name|Diagnoser
argument_list|(
name|DiagID
argument_list|,
name|Args
operator|...
argument_list|)
block|;
return|return
name|RequireNonAbstractType
argument_list|(
name|Loc
argument_list|,
name|T
argument_list|,
name|Diagnoser
argument_list|)
return|;
block|}
end_expr_stmt

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
parameter_list|,
name|bool
name|AllowFunctionTemplates
init|=
name|true
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
parameter_list|,
name|bool
name|AllowFunctionTemplates
init|=
name|true
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

begin_comment
comment|/// Determine whether a particular identifier might be the name in a C++1z
end_comment

begin_comment
comment|/// deduction-guide declaration.
end_comment

begin_function_decl
name|bool
name|isDeductionGuideName
parameter_list|(
name|Scope
modifier|*
name|S
parameter_list|,
specifier|const
name|IdentifierInfo
modifier|&
name|Name
parameter_list|,
name|SourceLocation
name|NameLoc
parameter_list|,
name|ParsedTemplateTy
modifier|*
name|Template
init|=
name|nullptr
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
name|DiagnoseUninstantiableTemplate
parameter_list|(
name|SourceLocation
name|PointOfInstantiation
parameter_list|,
name|NamedDecl
modifier|*
name|Instantiation
parameter_list|,
name|bool
name|InstantiatedFromMember
parameter_list|,
specifier|const
name|NamedDecl
modifier|*
name|Pattern
parameter_list|,
specifier|const
name|NamedDecl
modifier|*
name|PatternDef
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
name|TypeSourceInfo
modifier|*
modifier|&
name|TSI
parameter_list|,
name|SourceLocation
name|Loc
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
name|TemplateParameterList
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

begin_decl_stmt
name|TemplateParameterList
modifier|*
name|ActOnTemplateParameterList
argument_list|(
name|unsigned
name|Depth
argument_list|,
name|SourceLocation
name|ExportLoc
argument_list|,
name|SourceLocation
name|TemplateLoc
argument_list|,
name|SourceLocation
name|LAngleLoc
argument_list|,
name|ArrayRef
operator|<
name|Decl
operator|*
operator|>
name|Params
argument_list|,
name|SourceLocation
name|RAngleLoc
argument_list|,
name|Expr
operator|*
name|RequiresClause
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// \brief The context in which we are checking a template parameter list.
end_comment

begin_enum
enum|enum
name|TemplateParamListContext
block|{
name|TPC_ClassTemplate
block|,
name|TPC_VarTemplate
block|,
name|TPC_FunctionTemplate
block|,
name|TPC_ClassTemplateMember
block|,
name|TPC_FriendClassTemplate
block|,
name|TPC_FriendFunctionTemplate
block|,
name|TPC_FriendFunctionTemplateDefinition
block|,
name|TPC_TypeAliasTemplate
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

begin_decl_stmt
name|TemplateParameterList
modifier|*
name|MatchTemplateParametersToScopeSpecifier
argument_list|(
name|SourceLocation
name|DeclStartLoc
argument_list|,
name|SourceLocation
name|DeclLoc
argument_list|,
specifier|const
name|CXXScopeSpec
operator|&
name|SS
argument_list|,
name|TemplateIdAnnotation
operator|*
name|TemplateId
argument_list|,
name|ArrayRef
operator|<
name|TemplateParameterList
operator|*
operator|>
name|ParamLists
argument_list|,
name|bool
name|IsFriend
argument_list|,
name|bool
operator|&
name|IsMemberSpecialization
argument_list|,
name|bool
operator|&
name|Invalid
argument_list|)
decl_stmt|;
end_decl_stmt

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
name|SourceLocation
name|ModulePrivateLoc
parameter_list|,
name|SourceLocation
name|FriendLoc
parameter_list|,
name|unsigned
name|NumOuterTemplateParamLists
parameter_list|,
name|TemplateParameterList
modifier|*
modifier|*
name|OuterTemplateParamLists
parameter_list|,
name|SkipBodyInfo
modifier|*
name|SkipBody
init|=
name|nullptr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|TemplateArgumentLoc
name|getTrivialTemplateArgumentLoc
parameter_list|(
specifier|const
name|TemplateArgument
modifier|&
name|Arg
parameter_list|,
name|QualType
name|NTTPType
parameter_list|,
name|SourceLocation
name|Loc
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
name|SourceLocation
name|TemplateKWLoc
parameter_list|,
name|TemplateTy
name|Template
parameter_list|,
name|IdentifierInfo
modifier|*
name|TemplateII
parameter_list|,
name|SourceLocation
name|TemplateIILoc
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
name|bool
name|IsCtorOrDtorName
init|=
name|false
parameter_list|,
name|bool
name|IsClassName
init|=
name|false
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// \brief Parsed an elaborated-type-specifier that refers to a template-id,
end_comment

begin_comment
comment|/// such as \c class T::template apply<U>.
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
name|SourceLocation
name|TemplateKWLoc
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
name|DeclResult
name|ActOnVarTemplateSpecialization
parameter_list|(
name|Scope
modifier|*
name|S
parameter_list|,
name|Declarator
modifier|&
name|D
parameter_list|,
name|TypeSourceInfo
modifier|*
name|DI
parameter_list|,
name|SourceLocation
name|TemplateKWLoc
parameter_list|,
name|TemplateParameterList
modifier|*
name|TemplateParams
parameter_list|,
name|StorageClass
name|SC
parameter_list|,
name|bool
name|IsPartialSpecialization
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|DeclResult
name|CheckVarTemplateId
parameter_list|(
name|VarTemplateDecl
modifier|*
name|Template
parameter_list|,
name|SourceLocation
name|TemplateLoc
parameter_list|,
name|SourceLocation
name|TemplateNameLoc
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
name|CheckVarTemplateId
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
name|VarTemplateDecl
modifier|*
name|Template
parameter_list|,
name|SourceLocation
name|TemplateLoc
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
name|BuildTemplateIdExpr
parameter_list|(
specifier|const
name|CXXScopeSpec
modifier|&
name|SS
parameter_list|,
name|SourceLocation
name|TemplateKWLoc
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
modifier|*
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
name|SourceLocation
name|TemplateKWLoc
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
name|TemplateNameKind
name|ActOnDependentTemplateName
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
name|TemplateKWLoc
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
name|AllowInjectedClassName
init|=
name|false
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
name|SourceLocation
name|ModulePrivateLoc
parameter_list|,
name|TemplateIdAnnotation
modifier|&
name|TemplateId
parameter_list|,
name|AttributeList
modifier|*
name|Attr
parameter_list|,
name|MultiTemplateParamsArg
name|TemplateParameterLists
parameter_list|,
name|SkipBodyInfo
modifier|*
name|SkipBody
init|=
name|nullptr
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
name|bool
name|CheckTemplatePartialSpecializationArgs
argument_list|(
name|SourceLocation
name|Loc
argument_list|,
name|TemplateDecl
operator|*
name|PrimaryTemplate
argument_list|,
name|unsigned
name|NumExplicitArgs
argument_list|,
name|ArrayRef
operator|<
name|TemplateArgument
operator|>
name|Args
argument_list|)
decl_stmt|;
end_decl_stmt

begin_function_decl
name|void
name|CheckTemplatePartialSpecialization
parameter_list|(
name|ClassTemplatePartialSpecializationDecl
modifier|*
name|Partial
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|CheckTemplatePartialSpecialization
parameter_list|(
name|VarTemplatePartialSpecializationDecl
modifier|*
name|Partial
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
name|void
name|CompleteMemberSpecialization
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
name|SmallVectorImpl
operator|<
name|TemplateArgument
operator|>
operator|&
name|Converted
argument_list|,
name|bool
operator|&
name|HasDefaultArg
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
comment|/// \param UpdateArgsWithConversions If \c true, update \p TemplateArgs to
end_comment

begin_comment
comment|/// contain the converted forms of the template arguments as written.
end_comment

begin_comment
comment|/// Otherwise, \p TemplateArgs will not be modified.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \returns true if an error occurred, false otherwise.
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
name|SmallVectorImpl
operator|<
name|TemplateArgument
operator|>
operator|&
name|Converted
argument_list|,
name|bool
name|UpdateArgsWithConversions
operator|=
name|true
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
name|TemplateArgumentLoc
operator|&
name|Arg
argument_list|,
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
name|TemplateArgumentLoc
modifier|&
name|Arg
parameter_list|,
name|unsigned
name|ArgumentPackIndex
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
comment|/// \param TemplateII The identifier used to name the template.
end_comment

begin_comment
comment|/// \param TemplateIILoc The location of the template name.
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
name|TemplateName
parameter_list|,
name|IdentifierInfo
modifier|*
name|TemplateII
parameter_list|,
name|SourceLocation
name|TemplateIILoc
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

begin_function_decl
name|bool
name|RebuildTemplateParamsInCurrentInstantiation
parameter_list|(
name|TemplateParameterList
modifier|*
name|Params
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
comment|/// Determine whether an unexpanded parameter pack might be permitted in this
end_comment

begin_comment
comment|/// location. Useful for error recovery.
end_comment

begin_function_decl
name|bool
name|isUnexpandedParameterPackPermitted
parameter_list|()
function_decl|;
end_function_decl

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
block|,
comment|/// \brief Microsoft __if_exists.
name|UPPC_IfExists
block|,
comment|/// \brief Microsoft __if_not_exists.
name|UPPC_IfNotExists
block|,
comment|/// \brief Lambda expression.
name|UPPC_Lambda
block|,
comment|/// \brief Block expression,
name|UPPC_Block
block|}
enum|;
end_enum

begin_comment
comment|/// \brief Diagnose unexpanded parameter packs.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param Loc The location at which we should emit the diagnostic.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param UPPC The context in which we are diagnosing unexpanded
end_comment

begin_comment
comment|/// parameter packs.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param Unexpanded the set of unexpanded parameter packs.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \returns true if an error occurred, false otherwise.
end_comment

begin_decl_stmt
name|bool
name|DiagnoseUnexpandedParameterPacks
argument_list|(
name|SourceLocation
name|Loc
argument_list|,
name|UnexpandedParameterPackContext
name|UPPC
argument_list|,
name|ArrayRef
operator|<
name|UnexpandedParameterPack
operator|>
name|Unexpanded
argument_list|)
decl_stmt|;
end_decl_stmt

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
comment|/// nested-name-specifier.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param NNS The nested-name-specifier that will be traversed to find
end_comment

begin_comment
comment|/// unexpanded parameter packs.
end_comment

begin_decl_stmt
name|void
name|collectUnexpandedParameterPacks
argument_list|(
name|NestedNameSpecifierLoc
name|NNS
argument_list|,
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
comment|/// name.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param NameInfo The name that will be traversed to find
end_comment

begin_comment
comment|/// unexpanded parameter packs.
end_comment

begin_decl_stmt
name|void
name|collectUnexpandedParameterPacks
argument_list|(
specifier|const
name|DeclarationNameInfo
operator|&
name|NameInfo
argument_list|,
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
name|ArrayRef
operator|<
name|UnexpandedParameterPack
operator|>
name|Unexpanded
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
comment|/// This routine assumes that the number of arguments in the expansion is
end_comment

begin_comment
comment|/// consistent across all of the unexpanded parameter packs in its pattern.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Returns an empty Optional if the type can't be expanded.
end_comment

begin_expr_stmt
name|Optional
operator|<
name|unsigned
operator|>
name|getNumArgumentsInExpansion
argument_list|(
argument|QualType T
argument_list|,
argument|const MultiLevelTemplateArgumentList&TemplateArgs
argument_list|)
expr_stmt|;
end_expr_stmt

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
comment|/// \brief Returns the pattern of the pack expansion for a template argument.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param OrigLoc The template argument to expand.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param Ellipsis Will be set to the location of the ellipsis.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param NumExpansions Will be set to the number of expansions that will
end_comment

begin_comment
comment|/// be generated from this pack expansion, if known a priori.
end_comment

begin_decl_stmt
name|TemplateArgumentLoc
name|getTemplateArgumentPackExpansionPattern
argument_list|(
name|TemplateArgumentLoc
name|OrigLoc
argument_list|,
name|SourceLocation
operator|&
name|Ellipsis
argument_list|,
name|Optional
operator|<
name|unsigned
operator|>
operator|&
name|NumExpansions
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// Given a template argument that contains an unexpanded parameter pack, but
end_comment

begin_comment
comment|/// which has already been substituted, attempt to determine the number of
end_comment

begin_comment
comment|/// elements that will be produced once this argument is fully-expanded.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This is intended for use when transforming 'sizeof...(Arg)' in order to
end_comment

begin_comment
comment|/// avoid actually expanding the pack where possible.
end_comment

begin_expr_stmt
name|Optional
operator|<
name|unsigned
operator|>
name|getFullyPackExpandedSize
argument_list|(
argument|TemplateArgument Arg
argument_list|)
expr_stmt|;
end_expr_stmt

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
comment|/// Adjust the type \p ArgFunctionType to match the calling convention,
end_comment

begin_comment
comment|/// noreturn, and optionally the exception specification of \p FunctionType.
end_comment

begin_comment
comment|/// Deduction often wants to ignore these properties when matching function
end_comment

begin_comment
comment|/// types.
end_comment

begin_function_decl
name|QualType
name|adjustCCAndNoReturn
parameter_list|(
name|QualType
name|ArgFunctionType
parameter_list|,
name|QualType
name|FunctionType
parameter_list|,
name|bool
name|AdjustExceptionSpec
init|=
name|false
parameter_list|)
function_decl|;
end_function_decl

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
comment|/// \brief The declaration was invalid; do nothing.
name|TDK_Invalid
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
comment|/// \brief After substituting deduced template arguments, a dependent
comment|/// parameter type did not match the corresponding argument.
name|TDK_DeducedMismatch
block|,
comment|/// \brief After substituting deduced template arguments, an element of
comment|/// a dependent parameter type did not match the corresponding element
comment|/// of the corresponding argument (when deducing from an initializer list).
name|TDK_DeducedMismatchNested
block|,
comment|/// \brief A non-depnedent component of the parameter did not match the
comment|/// corresponding component of the argument.
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
comment|/// \brief Checking non-dependent argument conversions failed.
name|TDK_NonDependentConversionFailure
block|,
comment|/// \brief Deduction failed; that's all we know.
name|TDK_MiscellaneousDeductionFailure
block|,
comment|/// \brief CUDA Target attributes do not match.
name|TDK_CUDATargetMismatch
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
name|DeduceTemplateArguments
argument_list|(
name|VarTemplatePartialSpecializationDecl
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
name|SmallVectorImpl
operator|<
name|DeducedTemplateArgument
operator|>
operator|&
name|Deduced
argument_list|,
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

begin_comment
comment|/// brief A function argument from which we performed template argument
end_comment

begin_comment
comment|// deduction for a call.
end_comment

begin_struct
struct|struct
name|OriginalCallArg
block|{
name|OriginalCallArg
argument_list|(
argument|QualType OriginalParamType
argument_list|,
argument|bool DecomposedParam
argument_list|,
argument|unsigned ArgIdx
argument_list|,
argument|QualType OriginalArgType
argument_list|)
block|:
name|OriginalParamType
argument_list|(
name|OriginalParamType
argument_list|)
operator|,
name|DecomposedParam
argument_list|(
name|DecomposedParam
argument_list|)
operator|,
name|ArgIdx
argument_list|(
name|ArgIdx
argument_list|)
operator|,
name|OriginalArgType
argument_list|(
argument|OriginalArgType
argument_list|)
block|{}
name|QualType
name|OriginalParamType
expr_stmt|;
name|bool
name|DecomposedParam
decl_stmt|;
name|unsigned
name|ArgIdx
decl_stmt|;
name|QualType
name|OriginalArgType
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
name|TemplateDeductionResult
name|FinishTemplateArgumentDeduction
argument_list|(
name|FunctionTemplateDecl
operator|*
name|FunctionTemplate
argument_list|,
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
argument_list|,
name|SmallVectorImpl
operator|<
name|OriginalCallArg
operator|>
specifier|const
operator|*
name|OriginalCallArgs
operator|=
name|nullptr
argument_list|,
name|bool
name|PartialOverloading
operator|=
name|false
argument_list|,
name|llvm
operator|::
name|function_ref
operator|<
name|bool
argument_list|()
operator|>
name|CheckNonDependent
operator|=
index|[]
block|{
return|return
name|false
return|;
block|}
end_decl_stmt

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

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
name|ArrayRef
operator|<
name|Expr
operator|*
operator|>
name|Args
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
argument_list|,
name|bool
name|PartialOverloading
argument_list|,
name|llvm
operator|::
name|function_ref
operator|<
name|bool
argument_list|(
name|ArrayRef
operator|<
name|QualType
operator|>
argument_list|)
operator|>
name|CheckNonDependent
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
argument_list|,
name|bool
name|IsAddressOfFunction
operator|=
name|false
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
argument_list|,
name|bool
name|IsAddressOfFunction
operator|=
name|false
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// \brief Substitute Replacement for \p auto in \p TypeWithAuto
end_comment

begin_function_decl
name|QualType
name|SubstAutoType
parameter_list|(
name|QualType
name|TypeWithAuto
parameter_list|,
name|QualType
name|Replacement
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// \brief Substitute Replacement for auto in TypeWithAuto
end_comment

begin_function_decl
name|TypeSourceInfo
modifier|*
name|SubstAutoTypeSourceInfo
parameter_list|(
name|TypeSourceInfo
modifier|*
name|TypeWithAuto
parameter_list|,
name|QualType
name|Replacement
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// \brief Completely replace the \c auto in \p TypeWithAuto by
end_comment

begin_comment
comment|/// \p Replacement. This does not retain any \c auto type sugar.
end_comment

begin_function_decl
name|QualType
name|ReplaceAutoType
parameter_list|(
name|QualType
name|TypeWithAuto
parameter_list|,
name|QualType
name|Replacement
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// \brief Result type of DeduceAutoType.
end_comment

begin_enum
enum|enum
name|DeduceAutoResult
block|{
name|DAR_Succeeded
block|,
name|DAR_Failed
block|,
name|DAR_FailedAlreadyDiagnosed
block|}
enum|;
end_enum

begin_decl_stmt
name|DeduceAutoResult
name|DeduceAutoType
argument_list|(
name|TypeSourceInfo
operator|*
name|AutoType
argument_list|,
name|Expr
operator|*
operator|&
name|Initializer
argument_list|,
name|QualType
operator|&
name|Result
argument_list|,
name|Optional
operator|<
name|unsigned
operator|>
name|DependentDeductionDepth
operator|=
name|None
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|DeduceAutoResult
name|DeduceAutoType
argument_list|(
name|TypeLoc
name|AutoTypeLoc
argument_list|,
name|Expr
operator|*
operator|&
name|Initializer
argument_list|,
name|QualType
operator|&
name|Result
argument_list|,
name|Optional
operator|<
name|unsigned
operator|>
name|DependentDeductionDepth
operator|=
name|None
argument_list|)
decl_stmt|;
end_decl_stmt

begin_function_decl
name|void
name|DiagnoseAutoDeductionFailure
parameter_list|(
name|VarDecl
modifier|*
name|VDecl
parameter_list|,
name|Expr
modifier|*
name|Init
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|DeduceReturnType
parameter_list|(
name|FunctionDecl
modifier|*
name|FD
parameter_list|,
name|SourceLocation
name|Loc
parameter_list|,
name|bool
name|Diagnose
init|=
name|true
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// \brief Declare implicit deduction guides for a class template if we've
end_comment

begin_comment
comment|/// not already done so.
end_comment

begin_function_decl
name|void
name|DeclareImplicitDeductionGuides
parameter_list|(
name|TemplateDecl
modifier|*
name|Template
parameter_list|,
name|SourceLocation
name|Loc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|QualType
name|DeduceTemplateSpecializationFromInitializer
parameter_list|(
name|TypeSourceInfo
modifier|*
name|TInfo
parameter_list|,
specifier|const
name|InitializedEntity
modifier|&
name|Entity
parameter_list|,
specifier|const
name|InitializationKind
modifier|&
name|Kind
parameter_list|,
name|MultiExprArg
name|Init
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|QualType
name|deduceVarTypeFromInitializer
parameter_list|(
name|VarDecl
modifier|*
name|VDecl
parameter_list|,
name|DeclarationName
name|Name
parameter_list|,
name|QualType
name|Type
parameter_list|,
name|TypeSourceInfo
modifier|*
name|TSI
parameter_list|,
name|SourceRange
name|Range
parameter_list|,
name|bool
name|DirectInit
parameter_list|,
name|Expr
modifier|*
name|Init
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
name|TypeLoc
name|getReturnTypeLoc
argument_list|(
name|FunctionDecl
operator|*
name|FD
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_function_decl
name|bool
name|DeduceFunctionTypeFromReturnExpr
parameter_list|(
name|FunctionDecl
modifier|*
name|FD
parameter_list|,
name|SourceLocation
name|ReturnLoc
parameter_list|,
name|Expr
modifier|*
modifier|&
name|RetExpr
parameter_list|,
name|AutoType
modifier|*
name|AT
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
name|NumCallArguments1
parameter_list|,
name|unsigned
name|NumCallArguments2
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
name|TemplateSpecCandidateSet
modifier|&
name|FailedCandidates
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
parameter_list|,
name|QualType
name|TargetType
init|=
name|QualType
argument_list|()
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
name|bool
name|isMoreSpecializedThanPrimary
argument_list|(
name|ClassTemplatePartialSpecializationDecl
operator|*
name|T
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
name|VarTemplatePartialSpecializationDecl
modifier|*
name|getMoreSpecializedPartialSpecialization
parameter_list|(
name|VarTemplatePartialSpecializationDecl
modifier|*
name|PS1
parameter_list|,
name|VarTemplatePartialSpecializationDecl
modifier|*
name|PS2
parameter_list|,
name|SourceLocation
name|Loc
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
name|bool
name|isMoreSpecializedThanPrimary
argument_list|(
name|VarTemplatePartialSpecializationDecl
operator|*
name|T
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
name|isTemplateTemplateParameterAtLeastAsSpecializedAs
parameter_list|(
name|TemplateParameterList
modifier|*
name|P
parameter_list|,
name|TemplateDecl
modifier|*
name|AArg
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
name|SmallBitVector
operator|&
name|Used
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|MarkDeducedTemplateParameters
argument_list|(
specifier|const
name|FunctionTemplateDecl
operator|*
name|FunctionTemplate
argument_list|,
name|llvm
operator|::
name|SmallBitVector
operator|&
name|Deduced
argument_list|)
block|{
return|return
name|MarkDeducedTemplateParameters
argument_list|(
name|Context
argument_list|,
name|FunctionTemplate
argument_list|,
name|Deduced
argument_list|)
return|;
block|}
end_decl_stmt

begin_decl_stmt
specifier|static
name|void
name|MarkDeducedTemplateParameters
argument_list|(
name|ASTContext
operator|&
name|Ctx
argument_list|,
specifier|const
name|FunctionTemplateDecl
operator|*
name|FunctionTemplate
argument_list|,
name|llvm
operator|::
name|SmallBitVector
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
name|nullptr
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
name|nullptr
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// A context in which code is being synthesized (where a source location
end_comment

begin_comment
comment|/// alone is not sufficient to identify the context). This covers template
end_comment

begin_comment
comment|/// instantiation and various forms of implicitly-generated functions.
end_comment

begin_struct
struct|struct
name|CodeSynthesisContext
block|{
comment|/// \brief The kind of template instantiation we are performing
enum|enum
name|SynthesisKind
block|{
comment|/// We are instantiating a template declaration. The entity is
comment|/// the declaration we're instantiating (e.g., a CXXRecordDecl).
name|TemplateInstantiation
block|,
comment|/// We are instantiating a default argument for a template
comment|/// parameter. The Entity is the template parameter whose argument is
comment|/// being instantiated, the Template is the template, and the
comment|/// TemplateArgs/NumTemplateArguments provide the template arguments as
comment|/// specified.
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
comment|/// Entity is either a {Class|Var}TemplatePartialSpecializationDecl or
comment|/// a TemplateDecl.
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
block|,
comment|/// We are instantiating the exception specification for a function
comment|/// template which was deferred until it was needed.
name|ExceptionSpecInstantiation
block|,
comment|/// We are declaring an implicit special member function.
name|DeclaringSpecialMember
block|,     }
name|Kind
enum|;
comment|/// \brief Was the enclosing context a non-instantiation SFINAE context?
name|bool
name|SavedInNonInstantiationSFINAEContext
decl_stmt|;
comment|/// \brief The point of instantiation or synthesis within the source code.
name|SourceLocation
name|PointOfInstantiation
decl_stmt|;
comment|/// \brief The entity that is being synthesized.
name|Decl
modifier|*
name|Entity
decl_stmt|;
comment|/// \brief The template (or partial specialization) in which we are
comment|/// performing the instantiation, for substitutions of prior template
comment|/// arguments.
name|NamedDecl
modifier|*
name|Template
decl_stmt|;
comment|/// \brief The list of template arguments we are substituting, if they
comment|/// are not part of the entity.
specifier|const
name|TemplateArgument
modifier|*
name|TemplateArgs
decl_stmt|;
comment|// FIXME: Wrap this union around more members, or perhaps store the
comment|// kind-specific members in the RAII object owning the context.
union|union
block|{
comment|/// \brief The number of template arguments in TemplateArgs.
name|unsigned
name|NumTemplateArgs
decl_stmt|;
comment|/// \brief The special member being declared or defined.
name|CXXSpecialMember
name|SpecialMember
decl_stmt|;
block|}
union|;
name|ArrayRef
operator|<
name|TemplateArgument
operator|>
name|template_arguments
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
name|Kind
operator|!=
name|DeclaringSpecialMember
argument_list|)
block|;
return|return
block|{
name|TemplateArgs
block|,
name|NumTemplateArgs
block|}
return|;
block|}
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
name|CodeSynthesisContext
argument_list|()
operator|:
name|Kind
argument_list|(
name|TemplateInstantiation
argument_list|)
operator|,
name|Entity
argument_list|(
name|nullptr
argument_list|)
operator|,
name|Template
argument_list|(
name|nullptr
argument_list|)
operator|,
name|TemplateArgs
argument_list|(
name|nullptr
argument_list|)
operator|,
name|NumTemplateArgs
argument_list|(
literal|0
argument_list|)
operator|,
name|DeductionInfo
argument_list|(
argument|nullptr
argument_list|)
block|{}
comment|/// \brief Determines whether this template is an actual instantiation
comment|/// that should be counted toward the maximum instantiation depth.
name|bool
name|isInstantiationRecord
argument_list|()
specifier|const
expr_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/// \brief List of active code synthesis contexts.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This vector is treated as a stack. As synthesis of one entity requires
end_comment

begin_comment
comment|/// synthesis of another, additional contexts are pushed onto the stack.
end_comment

begin_expr_stmt
name|SmallVector
operator|<
name|CodeSynthesisContext
operator|,
literal|16
operator|>
name|CodeSynthesisContexts
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// Specializations whose definitions are currently being instantiated.
end_comment

begin_expr_stmt
name|llvm
operator|::
name|DenseSet
operator|<
name|std
operator|::
name|pair
operator|<
name|Decl
operator|*
operator|,
name|unsigned
operator|>>
name|InstantiatingSpecializations
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// Non-dependent types used in templates that have already been instantiated
end_comment

begin_comment
comment|/// by some template instantiation.
end_comment

begin_expr_stmt
name|llvm
operator|::
name|DenseSet
operator|<
name|QualType
operator|>
name|InstantiatedNonDependentTypes
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// \brief Extra modules inspected when performing a lookup during a template
end_comment

begin_comment
comment|/// instantiation. Computed lazily.
end_comment

begin_expr_stmt
name|SmallVector
operator|<
name|Module
operator|*
operator|,
literal|16
operator|>
name|CodeSynthesisContextLookupModules
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// \brief Cache of additional modules that should be used for name lookup
end_comment

begin_comment
comment|/// within the current template instantiation. Computed lazily; use
end_comment

begin_comment
comment|/// getLookupModules() to get a complete set.
end_comment

begin_expr_stmt
name|llvm
operator|::
name|DenseSet
operator|<
name|Module
operator|*
operator|>
name|LookupModulesCache
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// \brief Get the set of additional modules that should be checked during
end_comment

begin_comment
comment|/// name lookup. A module and its imports become visible when instanting a
end_comment

begin_comment
comment|/// template defined within it.
end_comment

begin_expr_stmt
name|llvm
operator|::
name|DenseSet
operator|<
name|Module
operator|*
operator|>
operator|&
name|getLookupModules
argument_list|()
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// \brief Map from the most recent declaration of a namespace to the most
end_comment

begin_comment
comment|/// recent visible declaration of that namespace.
end_comment

begin_expr_stmt
name|llvm
operator|::
name|DenseMap
operator|<
name|NamedDecl
operator|*
operator|,
name|NamedDecl
operator|*
operator|>
name|VisibleNamespaceCache
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
comment|/// \brief The number of \p CodeSynthesisContexts that are not template
end_comment

begin_comment
comment|/// instantiations and, therefore, should not be counted as part of the
end_comment

begin_comment
comment|/// instantiation depth.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// When the instantiation depth reaches the user-configurable limit
end_comment

begin_comment
comment|/// \p LangOptions::InstantiationDepth we will abort instantiation.
end_comment

begin_comment
comment|// FIXME: Should we have a similar limit for other forms of synthesis?
end_comment

begin_decl_stmt
name|unsigned
name|NonInstantiationEntries
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// \brief The depth of the context stack at the point when the most recent
end_comment

begin_comment
comment|/// error or warning was produced.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This value is used to suppress printing of redundant context stacks
end_comment

begin_comment
comment|/// when there are multiple errors or warnings in the same instantiation.
end_comment

begin_comment
comment|// FIXME: Does this belong in Sema? It's tough to implement it anywhere else.
end_comment

begin_decl_stmt
name|unsigned
name|LastEmittedCodeSynthesisContextDepth
init|=
literal|0
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

begin_typedef
typedef|typedef
name|llvm
operator|::
name|DenseMap
operator|<
name|Decl
operator|*
operator|,
name|SmallVector
operator|<
name|PartialDiagnosticAt
operator|,
literal|1
operator|>
expr|>
name|SuppressedDiagnosticsMap
expr_stmt|;
end_typedef

begin_decl_stmt
name|SuppressedDiagnosticsMap
name|SuppressedDiagnostics
decl_stmt|;
end_decl_stmt

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
comment|/// function template, variable template, alias template,
comment|/// or a member thereof.
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
struct|struct
name|ExceptionSpecification
block|{}
struct|;
comment|/// \brief Note that we are instantiating an exception specification
comment|/// of a function template.
name|InstantiatingTemplate
argument_list|(
argument|Sema&SemaRef
argument_list|,
argument|SourceLocation PointOfInstantiation
argument_list|,
argument|FunctionDecl *Entity
argument_list|,
argument|ExceptionSpecification
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
argument|TemplateParameter Param
argument_list|,
argument|TemplateDecl *Template
argument_list|,
argument|ArrayRef<TemplateArgument> TemplateArgs
argument_list|,
argument|SourceRange InstantiationRange = SourceRange()
argument_list|)
empty_stmt|;
comment|/// \brief Note that we are substituting either explicitly-specified or
comment|/// deduced template arguments during function template argument deduction.
name|InstantiatingTemplate
argument_list|(
argument|Sema&SemaRef
argument_list|,
argument|SourceLocation PointOfInstantiation
argument_list|,
argument|FunctionTemplateDecl *FunctionTemplate
argument_list|,
argument|ArrayRef<TemplateArgument> TemplateArgs
argument_list|,
argument|CodeSynthesisContext::SynthesisKind Kind
argument_list|,
argument|sema::TemplateDeductionInfo&DeductionInfo
argument_list|,
argument|SourceRange InstantiationRange = SourceRange()
argument_list|)
empty_stmt|;
comment|/// \brief Note that we are instantiating as part of template
comment|/// argument deduction for a class template declaration.
name|InstantiatingTemplate
argument_list|(
argument|Sema&SemaRef
argument_list|,
argument|SourceLocation PointOfInstantiation
argument_list|,
argument|TemplateDecl *Template
argument_list|,
argument|ArrayRef<TemplateArgument> TemplateArgs
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
argument|ArrayRef<TemplateArgument> TemplateArgs
argument_list|,
argument|sema::TemplateDeductionInfo&DeductionInfo
argument_list|,
argument|SourceRange InstantiationRange = SourceRange()
argument_list|)
empty_stmt|;
comment|/// \brief Note that we are instantiating as part of template
comment|/// argument deduction for a variable template partial
comment|/// specialization.
name|InstantiatingTemplate
argument_list|(
argument|Sema&SemaRef
argument_list|,
argument|SourceLocation PointOfInstantiation
argument_list|,
argument|VarTemplatePartialSpecializationDecl *PartialSpec
argument_list|,
argument|ArrayRef<TemplateArgument> TemplateArgs
argument_list|,
argument|sema::TemplateDeductionInfo&DeductionInfo
argument_list|,
argument|SourceRange InstantiationRange = SourceRange()
argument_list|)
empty_stmt|;
comment|/// \brief Note that we are instantiating a default argument for a function
comment|/// parameter.
name|InstantiatingTemplate
argument_list|(
argument|Sema&SemaRef
argument_list|,
argument|SourceLocation PointOfInstantiation
argument_list|,
argument|ParmVarDecl *Param
argument_list|,
argument|ArrayRef<TemplateArgument> TemplateArgs
argument_list|,
argument|SourceRange InstantiationRange = SourceRange()
argument_list|)
empty_stmt|;
comment|/// \brief Note that we are substituting prior template arguments into a
comment|/// non-type parameter.
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
argument|ArrayRef<TemplateArgument> TemplateArgs
argument_list|,
argument|SourceRange InstantiationRange
argument_list|)
empty_stmt|;
comment|/// \brief Note that we are substituting prior template arguments into a
comment|/// template template parameter.
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
argument|ArrayRef<TemplateArgument> TemplateArgs
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
argument|ArrayRef<TemplateArgument> TemplateArgs
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
name|bool
name|isInvalid
argument_list|()
specifier|const
block|{
return|return
name|Invalid
return|;
block|}
comment|/// \brief Determine whether we are already instantiating this
comment|/// specialization in some surrounding active instantiation.
name|bool
name|isAlreadyInstantiating
argument_list|()
specifier|const
block|{
return|return
name|AlreadyInstantiating
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
name|AlreadyInstantiating
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
argument|Sema&SemaRef
argument_list|,
argument|CodeSynthesisContext::SynthesisKind Kind
argument_list|,
argument|SourceLocation PointOfInstantiation
argument_list|,
argument|SourceRange InstantiationRange
argument_list|,
argument|Decl *Entity
argument_list|,
argument|NamedDecl *Template = nullptr
argument_list|,
argument|ArrayRef<TemplateArgument> TemplateArgs = None
argument_list|,
argument|sema::TemplateDeductionInfo *DeductionInfo = nullptr
argument_list|)
empty_stmt|;
name|InstantiatingTemplate
argument_list|(
specifier|const
name|InstantiatingTemplate
operator|&
argument_list|)
operator|=
name|delete
expr_stmt|;
name|InstantiatingTemplate
modifier|&
name|operator
init|=
operator|(
specifier|const
name|InstantiatingTemplate
operator|&
operator|)
operator|=
name|delete
decl_stmt|;
block|}
struct|;
end_struct

begin_function_decl
name|void
name|pushCodeSynthesisContext
parameter_list|(
name|CodeSynthesisContext
name|Ctx
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|popCodeSynthesisContext
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/// Determine whether we are currently performing template instantiation.
end_comment

begin_expr_stmt
name|bool
name|inTemplateInstantiation
argument_list|()
specifier|const
block|{
return|return
name|CodeSynthesisContexts
operator|.
name|size
argument_list|()
operator|>
name|NonInstantiationEntries
return|;
block|}
end_expr_stmt

begin_function
name|void
name|PrintContextStack
parameter_list|()
block|{
if|if
condition|(
operator|!
name|CodeSynthesisContexts
operator|.
name|empty
argument_list|()
operator|&&
name|CodeSynthesisContexts
operator|.
name|size
argument_list|()
operator|!=
name|LastEmittedCodeSynthesisContextDepth
condition|)
block|{
name|PrintInstantiationStack
argument_list|()
expr_stmt|;
name|LastEmittedCodeSynthesisContextDepth
operator|=
name|CodeSynthesisContexts
operator|.
name|size
argument_list|()
expr_stmt|;
block|}
if|if
condition|(
name|PragmaAttributeCurrentTargetDecl
condition|)
name|PrintPragmaAttributeInstantiationPoint
argument_list|()
expr_stmt|;
block|}
end_function

begin_function_decl
name|void
name|PrintInstantiationStack
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|PrintPragmaAttributeInstantiationPoint
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
comment|/// \returns An empty \c Optional if we're not in a SFINAE context.
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
comment|/// \brief Determines whether we are currently in a context that
end_comment

begin_comment
comment|/// is not evaluated as per C++ [expr] p5.
end_comment

begin_expr_stmt
name|bool
name|isUnevaluatedContext
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
operator|!
name|ExprEvalContexts
operator|.
name|empty
argument_list|()
operator|&&
literal|"Must be in an expression evaluation context"
argument_list|)
block|;
return|return
name|ExprEvalContexts
operator|.
name|back
argument_list|()
operator|.
name|isUnevaluated
argument_list|()
return|;
block|}
end_expr_stmt

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
comment|/// \brief RAII class used to indicate that we are performing provisional
end_comment

begin_comment
comment|/// semantic analysis to determine the validity of a construct, so
end_comment

begin_comment
comment|/// typo-correction and diagnostics in the immediate context (not within
end_comment

begin_comment
comment|/// implicitly-instantiated templates) should be suppressed.
end_comment

begin_decl_stmt
name|class
name|TentativeAnalysisScope
block|{
name|Sema
modifier|&
name|SemaRef
decl_stmt|;
comment|// FIXME: Using a SFINAETrap for this is a hack.
name|SFINAETrap
name|Trap
decl_stmt|;
name|bool
name|PrevDisableTypoCorrection
decl_stmt|;
name|public
label|:
name|explicit
name|TentativeAnalysisScope
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
name|Trap
argument_list|(
name|SemaRef
argument_list|,
name|true
argument_list|)
operator|,
name|PrevDisableTypoCorrection
argument_list|(
argument|SemaRef.DisableTypoCorrection
argument_list|)
block|{
name|SemaRef
operator|.
name|DisableTypoCorrection
operator|=
name|true
block|;     }
operator|~
name|TentativeAnalysisScope
argument_list|()
block|{
name|SemaRef
operator|.
name|DisableTypoCorrection
operator|=
name|PrevDisableTypoCorrection
block|;     }
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
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
comment|/// \brief Tracks whether we are in a context where typo correction is
end_comment

begin_comment
comment|/// disabled.
end_comment

begin_decl_stmt
name|bool
name|DisableTypoCorrection
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
name|SmallSet
operator|<
name|SourceLocation
operator|,
literal|2
operator|>
name|SrcLocSet
expr_stmt|;
end_typedef

begin_typedef
typedef|typedef
name|llvm
operator|::
name|DenseMap
operator|<
name|IdentifierInfo
operator|*
operator|,
name|SrcLocSet
operator|>
name|IdentifierSourceLocations
expr_stmt|;
end_typedef

begin_comment
comment|/// \brief A cache containing identifiers for which typo correction failed and
end_comment

begin_comment
comment|/// their locations, so that repeated attempts to correct an identifier in a
end_comment

begin_comment
comment|/// given location are ignored if typo correction already failed for it.
end_comment

begin_decl_stmt
name|IdentifierSourceLocations
name|TypoCorrectionFailures
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

begin_expr_stmt
name|threadSafety
operator|::
name|BeforeSet
operator|*
name|ThreadSafetyDeclCache
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

begin_decl_stmt
name|class
name|SavePendingInstantiationsAndVTableUsesRAII
block|{
name|public
label|:
name|SavePendingInstantiationsAndVTableUsesRAII
argument_list|(
argument|Sema&S
argument_list|,
argument|bool Enabled
argument_list|)
block|:
name|S
argument_list|(
name|S
argument_list|)
operator|,
name|Enabled
argument_list|(
argument|Enabled
argument_list|)
block|{
if|if
condition|(
operator|!
name|Enabled
condition|)
return|return;
name|SavedPendingInstantiations
operator|.
name|swap
argument_list|(
name|S
operator|.
name|PendingInstantiations
argument_list|)
expr_stmt|;
name|SavedVTableUses
operator|.
name|swap
argument_list|(
name|S
operator|.
name|VTableUses
argument_list|)
expr_stmt|;
block|}
end_decl_stmt

begin_expr_stmt
operator|~
name|SavePendingInstantiationsAndVTableUsesRAII
argument_list|()
block|{
if|if
condition|(
operator|!
name|Enabled
condition|)
return|return;
comment|// Restore the set of pending vtables.
name|assert
argument_list|(
name|S
operator|.
name|VTableUses
operator|.
name|empty
argument_list|()
operator|&&
literal|"VTableUses should be empty before it is discarded."
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|S
operator|.
name|VTableUses
operator|.
name|swap
argument_list|(
name|SavedVTableUses
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|// Restore the set of pending implicit instantiations.
end_comment

begin_expr_stmt
name|assert
argument_list|(
name|S
operator|.
name|PendingInstantiations
operator|.
name|empty
argument_list|()
operator|&&
literal|"PendingInstantiations should be empty before it is discarded."
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|S
operator|.
name|PendingInstantiations
operator|.
name|swap
argument_list|(
name|SavedPendingInstantiations
argument_list|)
expr_stmt|;
end_expr_stmt

begin_decl_stmt
unit|}    private:
name|Sema
modifier|&
name|S
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|SmallVector
operator|<
name|VTableUse
operator|,
literal|16
operator|>
name|SavedVTableUses
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|std
operator|::
name|deque
operator|<
name|PendingImplicitInstantiation
operator|>
name|SavedPendingInstantiations
expr_stmt|;
end_expr_stmt

begin_decl_stmt
name|bool
name|Enabled
decl_stmt|;
end_decl_stmt

begin_comment
unit|};
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

begin_decl_stmt
name|class
name|SavePendingLocalImplicitInstantiationsRAII
block|{
name|public
label|:
name|SavePendingLocalImplicitInstantiationsRAII
argument_list|(
name|Sema
operator|&
name|S
argument_list|)
operator|:
name|S
argument_list|(
argument|S
argument_list|)
block|{
name|SavedPendingLocalImplicitInstantiations
operator|.
name|swap
argument_list|(
name|S
operator|.
name|PendingLocalImplicitInstantiations
argument_list|)
block|;     }
operator|~
name|SavePendingLocalImplicitInstantiationsRAII
argument_list|()
block|{
name|assert
argument_list|(
name|S
operator|.
name|PendingLocalImplicitInstantiations
operator|.
name|empty
argument_list|()
operator|&&
literal|"there shouldn't be any pending local implicit instantiations"
argument_list|)
block|;
name|SavedPendingLocalImplicitInstantiations
operator|.
name|swap
argument_list|(
name|S
operator|.
name|PendingLocalImplicitInstantiations
argument_list|)
block|;     }
name|private
operator|:
name|Sema
operator|&
name|S
expr_stmt|;
name|std
operator|::
name|deque
operator|<
name|PendingImplicitInstantiation
operator|>
name|SavedPendingLocalImplicitInstantiations
expr_stmt|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|/// A helper class for building up ExtParameterInfos.
end_comment

begin_decl_stmt
name|class
name|ExtParameterInfoBuilder
block|{
name|SmallVector
operator|<
name|FunctionProtoType
operator|::
name|ExtParameterInfo
operator|,
literal|16
operator|>
name|Infos
expr_stmt|;
name|bool
name|HasInteresting
init|=
name|false
decl_stmt|;
name|public
label|:
comment|/// Set the ExtParameterInfo for the parameter at the given index,
comment|///
name|void
name|set
argument_list|(
name|unsigned
name|index
argument_list|,
name|FunctionProtoType
operator|::
name|ExtParameterInfo
name|info
argument_list|)
block|{
name|assert
argument_list|(
name|Infos
operator|.
name|size
argument_list|()
operator|<=
name|index
argument_list|)
expr_stmt|;
name|Infos
operator|.
name|resize
argument_list|(
name|index
argument_list|)
expr_stmt|;
name|Infos
operator|.
name|push_back
argument_list|(
name|info
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|HasInteresting
condition|)
name|HasInteresting
operator|=
operator|(
name|info
operator|!=
name|FunctionProtoType
operator|::
name|ExtParameterInfo
argument_list|()
operator|)
expr_stmt|;
block|}
comment|/// Return a pointer (suitable for setting in an ExtProtoInfo) to the
comment|/// ExtParameterInfo array we've built up.
specifier|const
name|FunctionProtoType
operator|::
name|ExtParameterInfo
operator|*
name|getPointerOrNull
argument_list|(
argument|unsigned numParams
argument_list|)
block|{
if|if
condition|(
operator|!
name|HasInteresting
condition|)
return|return
name|nullptr
return|;
name|Infos
operator|.
name|resize
argument_list|(
name|numParams
argument_list|)
expr_stmt|;
return|return
name|Infos
operator|.
name|data
argument_list|()
return|;
block|}
end_decl_stmt

begin_function_decl
unit|};
name|void
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
parameter_list|,
name|bool
name|AllowDeducedTST
init|=
name|false
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
parameter_list|,
name|CXXRecordDecl
modifier|*
name|ThisContext
parameter_list|,
name|unsigned
name|ThisTypeQuals
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|SubstExceptionSpec
parameter_list|(
name|FunctionDecl
modifier|*
name|New
parameter_list|,
specifier|const
name|FunctionProtoType
modifier|*
name|Proto
parameter_list|,
specifier|const
name|MultiLevelTemplateArgumentList
modifier|&
name|Args
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
name|Optional
operator|<
name|unsigned
operator|>
name|NumExpansions
argument_list|,
name|bool
name|ExpectParameterPack
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
name|ArrayRef
operator|<
name|ParmVarDecl
operator|*
operator|>
name|Params
argument_list|,
specifier|const
name|FunctionProtoType
operator|::
name|ExtParameterInfo
operator|*
name|ExtParamInfos
argument_list|,
specifier|const
name|MultiLevelTemplateArgumentList
operator|&
name|TemplateArgs
argument_list|,
name|SmallVectorImpl
operator|<
name|QualType
operator|>
operator|&
name|ParamTypes
argument_list|,
name|SmallVectorImpl
operator|<
name|ParmVarDecl
operator|*
operator|>
operator|*
name|OutParams
argument_list|,
name|ExtParameterInfoBuilder
operator|&
name|ParamInfos
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
name|ArrayRef
operator|<
name|Expr
operator|*
operator|>
name|Exprs
argument_list|,
name|bool
name|IsCall
argument_list|,
specifier|const
name|MultiLevelTemplateArgumentList
operator|&
name|TemplateArgs
argument_list|,
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
name|ExprResult
name|SubstInitializer
parameter_list|(
name|Expr
modifier|*
name|E
parameter_list|,
specifier|const
name|MultiLevelTemplateArgumentList
modifier|&
name|TemplateArgs
parameter_list|,
name|bool
name|CXXDirectInit
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
name|InstantiateEnum
parameter_list|(
name|SourceLocation
name|PointOfInstantiation
parameter_list|,
name|EnumDecl
modifier|*
name|Instantiation
parameter_list|,
name|EnumDecl
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
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|InstantiateInClassInitializer
parameter_list|(
name|SourceLocation
name|PointOfInstantiation
parameter_list|,
name|FieldDecl
modifier|*
name|Instantiation
parameter_list|,
name|FieldDecl
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

begin_struct
struct|struct
name|LateInstantiatedAttribute
block|{
specifier|const
name|Attr
modifier|*
name|TmplAttr
decl_stmt|;
name|LocalInstantiationScope
modifier|*
name|Scope
decl_stmt|;
name|Decl
modifier|*
name|NewDecl
decl_stmt|;
name|LateInstantiatedAttribute
argument_list|(
specifier|const
name|Attr
operator|*
name|A
argument_list|,
name|LocalInstantiationScope
operator|*
name|S
argument_list|,
name|Decl
operator|*
name|D
argument_list|)
operator|:
name|TmplAttr
argument_list|(
name|A
argument_list|)
operator|,
name|Scope
argument_list|(
name|S
argument_list|)
operator|,
name|NewDecl
argument_list|(
argument|D
argument_list|)
block|{ }
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|SmallVector
operator|<
name|LateInstantiatedAttribute
operator|,
literal|16
operator|>
name|LateInstantiatedAttrVec
expr_stmt|;
end_typedef

begin_function_decl
name|void
name|InstantiateAttrs
parameter_list|(
specifier|const
name|MultiLevelTemplateArgumentList
modifier|&
name|TemplateArgs
parameter_list|,
specifier|const
name|Decl
modifier|*
name|Pattern
parameter_list|,
name|Decl
modifier|*
name|Inst
parameter_list|,
name|LateInstantiatedAttrVec
modifier|*
name|LateAttrs
init|=
name|nullptr
parameter_list|,
name|LocalInstantiationScope
modifier|*
name|OuterMostScope
init|=
name|nullptr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|InstantiateAttrsForDecl
parameter_list|(
specifier|const
name|MultiLevelTemplateArgumentList
modifier|&
name|TemplateArgs
parameter_list|,
specifier|const
name|Decl
modifier|*
name|Pattern
parameter_list|,
name|Decl
modifier|*
name|Inst
parameter_list|,
name|LateInstantiatedAttrVec
modifier|*
name|LateAttrs
init|=
name|nullptr
parameter_list|,
name|LocalInstantiationScope
modifier|*
name|OuterMostScope
init|=
name|nullptr
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
name|InstantiateExceptionSpec
parameter_list|(
name|SourceLocation
name|PointOfInstantiation
parameter_list|,
name|FunctionDecl
modifier|*
name|Function
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
parameter_list|,
name|bool
name|AtEndOfTU
init|=
name|false
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
name|VarTemplateSpecializationDecl
modifier|*
name|BuildVarTemplateInstantiation
argument_list|(
name|VarTemplateDecl
operator|*
name|VarTemplate
argument_list|,
name|VarDecl
operator|*
name|FromVar
argument_list|,
specifier|const
name|TemplateArgumentList
operator|&
name|TemplateArgList
argument_list|,
specifier|const
name|TemplateArgumentListInfo
operator|&
name|TemplateArgsInfo
argument_list|,
name|SmallVectorImpl
operator|<
name|TemplateArgument
operator|>
operator|&
name|Converted
argument_list|,
name|SourceLocation
name|PointOfInstantiation
argument_list|,
name|void
operator|*
name|InsertPos
argument_list|,
name|LateInstantiatedAttrVec
operator|*
name|LateAttrs
operator|=
name|nullptr
argument_list|,
name|LocalInstantiationScope
operator|*
name|StartingScope
operator|=
name|nullptr
argument_list|)
decl_stmt|;
end_decl_stmt

begin_function_decl
name|VarTemplateSpecializationDecl
modifier|*
name|CompleteVarTemplateSpecializationDecl
parameter_list|(
name|VarTemplateSpecializationDecl
modifier|*
name|VarSpec
parameter_list|,
name|VarDecl
modifier|*
name|PatternDecl
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
name|BuildVariableInstantiation
parameter_list|(
name|VarDecl
modifier|*
name|NewVar
parameter_list|,
name|VarDecl
modifier|*
name|OldVar
parameter_list|,
specifier|const
name|MultiLevelTemplateArgumentList
modifier|&
name|TemplateArgs
parameter_list|,
name|LateInstantiatedAttrVec
modifier|*
name|LateAttrs
parameter_list|,
name|DeclContext
modifier|*
name|Owner
parameter_list|,
name|LocalInstantiationScope
modifier|*
name|StartingScope
parameter_list|,
name|bool
name|InstantiatingVarTemplate
init|=
name|false
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|InstantiateVariableInitializer
parameter_list|(
name|VarDecl
modifier|*
name|Var
parameter_list|,
name|VarDecl
modifier|*
name|OldVar
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
name|InstantiateVariableDefinition
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
parameter_list|,
name|bool
name|AtEndOfTU
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

begin_enum
enum|enum
name|ObjCContainerKind
block|{
name|OCK_None
init|=
operator|-
literal|1
block|,
name|OCK_Interface
init|=
literal|0
block|,
name|OCK_Protocol
block|,
name|OCK_Category
block|,
name|OCK_ClassExtension
block|,
name|OCK_Implementation
block|,
name|OCK_CategoryImplementation
block|}
enum|;
end_enum

begin_expr_stmt
name|ObjCContainerKind
name|getObjCContainerKind
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt

begin_function_decl
name|DeclResult
name|actOnObjCTypeParam
parameter_list|(
name|Scope
modifier|*
name|S
parameter_list|,
name|ObjCTypeParamVariance
name|variance
parameter_list|,
name|SourceLocation
name|varianceLoc
parameter_list|,
name|unsigned
name|index
parameter_list|,
name|IdentifierInfo
modifier|*
name|paramName
parameter_list|,
name|SourceLocation
name|paramLoc
parameter_list|,
name|SourceLocation
name|colonLoc
parameter_list|,
name|ParsedType
name|typeBound
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
name|ObjCTypeParamList
modifier|*
name|actOnObjCTypeParamList
argument_list|(
name|Scope
operator|*
name|S
argument_list|,
name|SourceLocation
name|lAngleLoc
argument_list|,
name|ArrayRef
operator|<
name|Decl
operator|*
operator|>
name|typeParams
argument_list|,
name|SourceLocation
name|rAngleLoc
argument_list|)
decl_stmt|;
end_decl_stmt

begin_function_decl
name|void
name|popObjCTypeParamList
parameter_list|(
name|Scope
modifier|*
name|S
parameter_list|,
name|ObjCTypeParamList
modifier|*
name|typeParamList
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
name|Decl
modifier|*
name|ActOnStartClassInterface
argument_list|(
name|Scope
operator|*
name|S
argument_list|,
name|SourceLocation
name|AtInterfaceLoc
argument_list|,
name|IdentifierInfo
operator|*
name|ClassName
argument_list|,
name|SourceLocation
name|ClassLoc
argument_list|,
name|ObjCTypeParamList
operator|*
name|typeParamList
argument_list|,
name|IdentifierInfo
operator|*
name|SuperName
argument_list|,
name|SourceLocation
name|SuperLoc
argument_list|,
name|ArrayRef
operator|<
name|ParsedType
operator|>
name|SuperTypeArgs
argument_list|,
name|SourceRange
name|SuperTypeArgsRange
argument_list|,
name|Decl
operator|*
specifier|const
operator|*
name|ProtoRefs
argument_list|,
name|unsigned
name|NumProtoRefs
argument_list|,
specifier|const
name|SourceLocation
operator|*
name|ProtoLocs
argument_list|,
name|SourceLocation
name|EndProtoLoc
argument_list|,
name|AttributeList
operator|*
name|AttrList
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|ActOnSuperClassOfClassInterface
argument_list|(
name|Scope
operator|*
name|S
argument_list|,
name|SourceLocation
name|AtInterfaceLoc
argument_list|,
name|ObjCInterfaceDecl
operator|*
name|IDecl
argument_list|,
name|IdentifierInfo
operator|*
name|ClassName
argument_list|,
name|SourceLocation
name|ClassLoc
argument_list|,
name|IdentifierInfo
operator|*
name|SuperName
argument_list|,
name|SourceLocation
name|SuperLoc
argument_list|,
name|ArrayRef
operator|<
name|ParsedType
operator|>
name|SuperTypeArgs
argument_list|,
name|SourceRange
name|SuperTypeArgsRange
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|ActOnTypedefedProtocols
argument_list|(
name|SmallVectorImpl
operator|<
name|Decl
operator|*
operator|>
operator|&
name|ProtocolRefs
argument_list|,
name|SmallVectorImpl
operator|<
name|SourceLocation
operator|>
operator|&
name|ProtocolLocs
argument_list|,
name|IdentifierInfo
operator|*
name|SuperName
argument_list|,
name|SourceLocation
name|SuperLoc
argument_list|)
decl_stmt|;
end_decl_stmt

begin_function_decl
name|Decl
modifier|*
name|ActOnCompatibilityAlias
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
name|bool
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
name|ObjCTypeParamList
modifier|*
name|typeParamList
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

begin_decl_stmt
name|DeclGroupPtrTy
name|ActOnFinishObjCImplementation
argument_list|(
name|Decl
operator|*
name|ObjCImpDecl
argument_list|,
name|ArrayRef
operator|<
name|Decl
operator|*
operator|>
name|Decls
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|DeclGroupPtrTy
name|ActOnForwardClassDeclaration
argument_list|(
name|SourceLocation
name|Loc
argument_list|,
name|IdentifierInfo
operator|*
operator|*
name|IdentList
argument_list|,
name|SourceLocation
operator|*
name|IdentLocs
argument_list|,
name|ArrayRef
operator|<
name|ObjCTypeParamList
operator|*
operator|>
name|TypeParamLists
argument_list|,
name|unsigned
name|NumElts
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|DeclGroupPtrTy
name|ActOnForwardProtocolDeclaration
argument_list|(
name|SourceLocation
name|AtProtoclLoc
argument_list|,
name|ArrayRef
operator|<
name|IdentifierLocPair
operator|>
name|IdentList
argument_list|,
name|AttributeList
operator|*
name|attrList
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|FindProtocolDeclaration
argument_list|(
name|bool
name|WarnOnDeclarations
argument_list|,
name|bool
name|ForObjCContainer
argument_list|,
name|ArrayRef
operator|<
name|IdentifierLocPair
operator|>
name|ProtocolId
argument_list|,
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

begin_function_decl
name|void
name|DiagnoseTypeArgsAndProtocols
parameter_list|(
name|IdentifierInfo
modifier|*
name|ProtocolId
parameter_list|,
name|SourceLocation
name|ProtocolLoc
parameter_list|,
name|IdentifierInfo
modifier|*
name|TypeArgId
parameter_list|,
name|SourceLocation
name|TypeArgLoc
parameter_list|,
name|bool
name|SelectProtocolFirst
init|=
name|false
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// Given a list of identifiers (and their locations), resolve the
end_comment

begin_comment
comment|/// names to either Objective-C protocol qualifiers or type
end_comment

begin_comment
comment|/// arguments, as appropriate.
end_comment

begin_decl_stmt
name|void
name|actOnObjCTypeArgsOrProtocolQualifiers
argument_list|(
name|Scope
operator|*
name|S
argument_list|,
name|ParsedType
name|baseType
argument_list|,
name|SourceLocation
name|lAngleLoc
argument_list|,
name|ArrayRef
operator|<
name|IdentifierInfo
operator|*
operator|>
name|identifiers
argument_list|,
name|ArrayRef
operator|<
name|SourceLocation
operator|>
name|identifierLocs
argument_list|,
name|SourceLocation
name|rAngleLoc
argument_list|,
name|SourceLocation
operator|&
name|typeArgsLAngleLoc
argument_list|,
name|SmallVectorImpl
operator|<
name|ParsedType
operator|>
operator|&
name|typeArgs
argument_list|,
name|SourceLocation
operator|&
name|typeArgsRAngleLoc
argument_list|,
name|SourceLocation
operator|&
name|protocolLAngleLoc
argument_list|,
name|SmallVectorImpl
operator|<
name|Decl
operator|*
operator|>
operator|&
name|protocols
argument_list|,
name|SourceLocation
operator|&
name|protocolRAngleLoc
argument_list|,
name|bool
name|warnOnIncompleteProtocols
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// Build a an Objective-C protocol-qualified 'id' type where no
end_comment

begin_comment
comment|/// base type was specified.
end_comment

begin_decl_stmt
name|TypeResult
name|actOnObjCProtocolQualifierType
argument_list|(
name|SourceLocation
name|lAngleLoc
argument_list|,
name|ArrayRef
operator|<
name|Decl
operator|*
operator|>
name|protocols
argument_list|,
name|ArrayRef
operator|<
name|SourceLocation
operator|>
name|protocolLocs
argument_list|,
name|SourceLocation
name|rAngleLoc
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// Build a specialized and/or protocol-qualified Objective-C type.
end_comment

begin_decl_stmt
name|TypeResult
name|actOnObjCTypeArgsAndProtocolQualifiers
argument_list|(
name|Scope
operator|*
name|S
argument_list|,
name|SourceLocation
name|Loc
argument_list|,
name|ParsedType
name|BaseType
argument_list|,
name|SourceLocation
name|TypeArgsLAngleLoc
argument_list|,
name|ArrayRef
operator|<
name|ParsedType
operator|>
name|TypeArgs
argument_list|,
name|SourceLocation
name|TypeArgsRAngleLoc
argument_list|,
name|SourceLocation
name|ProtocolLAngleLoc
argument_list|,
name|ArrayRef
operator|<
name|Decl
operator|*
operator|>
name|Protocols
argument_list|,
name|ArrayRef
operator|<
name|SourceLocation
operator|>
name|ProtocolLocs
argument_list|,
name|SourceLocation
name|ProtocolRAngleLoc
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// Build an Objective-C type parameter type.
end_comment

begin_decl_stmt
name|QualType
name|BuildObjCTypeParamType
argument_list|(
specifier|const
name|ObjCTypeParamDecl
operator|*
name|Decl
argument_list|,
name|SourceLocation
name|ProtocolLAngleLoc
argument_list|,
name|ArrayRef
operator|<
name|ObjCProtocolDecl
operator|*
operator|>
name|Protocols
argument_list|,
name|ArrayRef
operator|<
name|SourceLocation
operator|>
name|ProtocolLocs
argument_list|,
name|SourceLocation
name|ProtocolRAngleLoc
argument_list|,
name|bool
name|FailOnError
operator|=
name|false
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// Build an Objective-C object pointer type.
end_comment

begin_decl_stmt
name|QualType
name|BuildObjCObjectType
argument_list|(
name|QualType
name|BaseType
argument_list|,
name|SourceLocation
name|Loc
argument_list|,
name|SourceLocation
name|TypeArgsLAngleLoc
argument_list|,
name|ArrayRef
operator|<
name|TypeSourceInfo
operator|*
operator|>
name|TypeArgs
argument_list|,
name|SourceLocation
name|TypeArgsRAngleLoc
argument_list|,
name|SourceLocation
name|ProtocolLAngleLoc
argument_list|,
name|ArrayRef
operator|<
name|ObjCProtocolDecl
operator|*
operator|>
name|Protocols
argument_list|,
name|ArrayRef
operator|<
name|SourceLocation
operator|>
name|ProtocolLocs
argument_list|,
name|SourceLocation
name|ProtocolRAngleLoc
argument_list|,
name|bool
name|FailOnError
operator|=
name|false
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// Check the application of the Objective-C '__kindof' qualifier to
end_comment

begin_comment
comment|/// the given type.
end_comment

begin_function_decl
name|bool
name|checkObjCKindOfType
parameter_list|(
name|QualType
modifier|&
name|type
parameter_list|,
name|SourceLocation
name|loc
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// Ensure attributes are consistent with type.
end_comment

begin_comment
comment|/// \param [in, out] Attributes The attributes to check; they will
end_comment

begin_comment
comment|/// be modified to be consistent with \p PropertyTy.
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
parameter_list|,
name|bool
name|propertyInPrimaryClass
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

begin_function_decl
name|void
name|ProcessPropertyDecl
parameter_list|(
name|ObjCPropertyDecl
modifier|*
name|property
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
parameter_list|,
name|bool
name|OverridingProtocolProperty
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

begin_decl_stmt
name|Decl
modifier|*
name|ActOnAtEnd
argument_list|(
name|Scope
operator|*
name|S
argument_list|,
name|SourceRange
name|AtEnd
argument_list|,
name|ArrayRef
operator|<
name|Decl
operator|*
operator|>
name|allMethods
operator|=
name|None
argument_list|,
name|ArrayRef
operator|<
name|DeclGroupPtrTy
operator|>
name|allTUVars
operator|=
name|None
argument_list|)
decl_stmt|;
end_decl_stmt

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
name|SourceLocation
name|LParenLoc
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
name|tok
operator|::
name|ObjCKeywordKind
name|MethodImplKind
argument_list|,
name|DeclContext
operator|*
name|lexicalDC
operator|=
name|nullptr
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
parameter_list|,
name|ObjCPropertyQueryKind
name|QueryKind
parameter_list|)
function_decl|;
end_function_decl

begin_enum
enum|enum
name|ObjCSpecialMethodKind
block|{
name|OSMK_None
block|,
name|OSMK_Alloc
block|,
name|OSMK_New
block|,
name|OSMK_Copy
block|,
name|OSMK_RetainingInit
block|,
name|OSMK_NonRetainingInit
block|}
enum|;
end_enum

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
name|ObjCDeclSpec
operator|&
name|ReturnQT
argument_list|,
name|ParsedType
name|ReturnType
argument_list|,
name|ArrayRef
operator|<
name|SourceLocation
operator|>
name|SelectorLocs
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
name|ObjCMethodDecl
modifier|*
name|LookupMethodInObjectType
parameter_list|(
name|Selector
name|Sel
parameter_list|,
name|QualType
name|Ty
parameter_list|,
name|bool
name|IsInstance
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|CheckARCMethodDecl
parameter_list|(
name|ObjCMethodDecl
modifier|*
name|method
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|inferObjCARCLifetime
parameter_list|(
name|ValueDecl
modifier|*
name|decl
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
name|SourceLocation
name|OpLoc
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
parameter_list|(
name|SourceLocation
name|Loc
parameter_list|)
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

begin_decl_stmt
name|ExprResult
name|ActOnSuperMessage
argument_list|(
name|Scope
operator|*
name|S
argument_list|,
name|SourceLocation
name|SuperLoc
argument_list|,
name|Selector
name|Sel
argument_list|,
name|SourceLocation
name|LBracLoc
argument_list|,
name|ArrayRef
operator|<
name|SourceLocation
operator|>
name|SelectorLocs
argument_list|,
name|SourceLocation
name|RBracLoc
argument_list|,
name|MultiExprArg
name|Args
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|ExprResult
name|BuildClassMessage
argument_list|(
name|TypeSourceInfo
operator|*
name|ReceiverTypeInfo
argument_list|,
name|QualType
name|ReceiverType
argument_list|,
name|SourceLocation
name|SuperLoc
argument_list|,
name|Selector
name|Sel
argument_list|,
name|ObjCMethodDecl
operator|*
name|Method
argument_list|,
name|SourceLocation
name|LBracLoc
argument_list|,
name|ArrayRef
operator|<
name|SourceLocation
operator|>
name|SelectorLocs
argument_list|,
name|SourceLocation
name|RBracLoc
argument_list|,
name|MultiExprArg
name|Args
argument_list|,
name|bool
name|isImplicit
operator|=
name|false
argument_list|)
decl_stmt|;
end_decl_stmt

begin_function_decl
name|ExprResult
name|BuildClassMessageImplicit
parameter_list|(
name|QualType
name|ReceiverType
parameter_list|,
name|bool
name|isSuperReceiver
parameter_list|,
name|SourceLocation
name|Loc
parameter_list|,
name|Selector
name|Sel
parameter_list|,
name|ObjCMethodDecl
modifier|*
name|Method
parameter_list|,
name|MultiExprArg
name|Args
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
name|ExprResult
name|ActOnClassMessage
argument_list|(
name|Scope
operator|*
name|S
argument_list|,
name|ParsedType
name|Receiver
argument_list|,
name|Selector
name|Sel
argument_list|,
name|SourceLocation
name|LBracLoc
argument_list|,
name|ArrayRef
operator|<
name|SourceLocation
operator|>
name|SelectorLocs
argument_list|,
name|SourceLocation
name|RBracLoc
argument_list|,
name|MultiExprArg
name|Args
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|ExprResult
name|BuildInstanceMessage
argument_list|(
name|Expr
operator|*
name|Receiver
argument_list|,
name|QualType
name|ReceiverType
argument_list|,
name|SourceLocation
name|SuperLoc
argument_list|,
name|Selector
name|Sel
argument_list|,
name|ObjCMethodDecl
operator|*
name|Method
argument_list|,
name|SourceLocation
name|LBracLoc
argument_list|,
name|ArrayRef
operator|<
name|SourceLocation
operator|>
name|SelectorLocs
argument_list|,
name|SourceLocation
name|RBracLoc
argument_list|,
name|MultiExprArg
name|Args
argument_list|,
name|bool
name|isImplicit
operator|=
name|false
argument_list|)
decl_stmt|;
end_decl_stmt

begin_function_decl
name|ExprResult
name|BuildInstanceMessageImplicit
parameter_list|(
name|Expr
modifier|*
name|Receiver
parameter_list|,
name|QualType
name|ReceiverType
parameter_list|,
name|SourceLocation
name|Loc
parameter_list|,
name|Selector
name|Sel
parameter_list|,
name|ObjCMethodDecl
modifier|*
name|Method
parameter_list|,
name|MultiExprArg
name|Args
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
name|ExprResult
name|ActOnInstanceMessage
argument_list|(
name|Scope
operator|*
name|S
argument_list|,
name|Expr
operator|*
name|Receiver
argument_list|,
name|Selector
name|Sel
argument_list|,
name|SourceLocation
name|LBracLoc
argument_list|,
name|ArrayRef
operator|<
name|SourceLocation
operator|>
name|SelectorLocs
argument_list|,
name|SourceLocation
name|RBracLoc
argument_list|,
name|MultiExprArg
name|Args
argument_list|)
decl_stmt|;
end_decl_stmt

begin_function_decl
name|ExprResult
name|BuildObjCBridgedCast
parameter_list|(
name|SourceLocation
name|LParenLoc
parameter_list|,
name|ObjCBridgeCastKind
name|Kind
parameter_list|,
name|SourceLocation
name|BridgeKeywordLoc
parameter_list|,
name|TypeSourceInfo
modifier|*
name|TSInfo
parameter_list|,
name|Expr
modifier|*
name|SubExpr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ExprResult
name|ActOnObjCBridgedCast
parameter_list|(
name|Scope
modifier|*
name|S
parameter_list|,
name|SourceLocation
name|LParenLoc
parameter_list|,
name|ObjCBridgeCastKind
name|Kind
parameter_list|,
name|SourceLocation
name|BridgeKeywordLoc
parameter_list|,
name|ParsedType
name|Type
parameter_list|,
name|SourceLocation
name|RParenLoc
parameter_list|,
name|Expr
modifier|*
name|SubExpr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|CheckTollFreeBridgeCast
parameter_list|(
name|QualType
name|castType
parameter_list|,
name|Expr
modifier|*
name|castExpr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|CheckObjCBridgeRelatedCast
parameter_list|(
name|QualType
name|castType
parameter_list|,
name|Expr
modifier|*
name|castExpr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|CheckTollFreeBridgeStaticCast
parameter_list|(
name|QualType
name|castType
parameter_list|,
name|Expr
modifier|*
name|castExpr
parameter_list|,
name|CastKind
modifier|&
name|Kind
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|checkObjCBridgeRelatedComponents
parameter_list|(
name|SourceLocation
name|Loc
parameter_list|,
name|QualType
name|DestType
parameter_list|,
name|QualType
name|SrcType
parameter_list|,
name|ObjCInterfaceDecl
modifier|*
modifier|&
name|RelatedClass
parameter_list|,
name|ObjCMethodDecl
modifier|*
modifier|&
name|ClassMethod
parameter_list|,
name|ObjCMethodDecl
modifier|*
modifier|&
name|InstanceMethod
parameter_list|,
name|TypedefNameDecl
modifier|*
modifier|&
name|TDNDecl
parameter_list|,
name|bool
name|CfToNs
parameter_list|,
name|bool
name|Diagnose
init|=
name|true
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|CheckObjCBridgeRelatedConversions
parameter_list|(
name|SourceLocation
name|Loc
parameter_list|,
name|QualType
name|DestType
parameter_list|,
name|QualType
name|SrcType
parameter_list|,
name|Expr
modifier|*
modifier|&
name|SrcExpr
parameter_list|,
name|bool
name|Diagnose
init|=
name|true
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|ConversionToObjCStringLiteralCheck
parameter_list|(
name|QualType
name|DstType
parameter_list|,
name|Expr
modifier|*
modifier|&
name|SrcExpr
parameter_list|,
name|bool
name|Diagnose
init|=
name|true
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|checkInitMethod
parameter_list|(
name|ObjCMethodDecl
modifier|*
name|method
parameter_list|,
name|QualType
name|receiverTypeIfCall
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// \brief Check whether the given new method is a valid override of the
end_comment

begin_comment
comment|/// given overridden method, and set any properties that should be inherited.
end_comment

begin_function_decl
name|void
name|CheckObjCMethodOverride
parameter_list|(
name|ObjCMethodDecl
modifier|*
name|NewMethod
parameter_list|,
specifier|const
name|ObjCMethodDecl
modifier|*
name|Overridden
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// \brief Describes the compatibility of a result type with its method.
end_comment

begin_enum
enum|enum
name|ResultTypeCompatibilityKind
block|{
name|RTC_Compatible
block|,
name|RTC_Incompatible
block|,
name|RTC_Unknown
block|}
enum|;
end_enum

begin_function_decl
name|void
name|CheckObjCMethodOverrides
parameter_list|(
name|ObjCMethodDecl
modifier|*
name|ObjCMethod
parameter_list|,
name|ObjCInterfaceDecl
modifier|*
name|CurrentClass
parameter_list|,
name|ResultTypeCompatibilityKind
name|RTC
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
comment|/// ActOnPragmaOptionsAlign - Called on well formed \#pragma options align.
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
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// ActOnPragmaPack - Called on well formed \#pragma pack(...).
end_comment

begin_function_decl
name|void
name|ActOnPragmaPack
parameter_list|(
name|SourceLocation
name|PragmaLoc
parameter_list|,
name|PragmaMsStackAction
name|Action
parameter_list|,
name|StringRef
name|SlotLabel
parameter_list|,
name|Expr
modifier|*
name|Alignment
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// ActOnPragmaMSStruct - Called on well formed \#pragma ms_struct [on|off].
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
comment|/// ActOnPragmaMSComment - Called on well formed
end_comment

begin_comment
comment|/// \#pragma comment(kind, "arg").
end_comment

begin_function_decl
name|void
name|ActOnPragmaMSComment
parameter_list|(
name|SourceLocation
name|CommentLoc
parameter_list|,
name|PragmaMSCommentKind
name|Kind
parameter_list|,
name|StringRef
name|Arg
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// ActOnPragmaMSPointersToMembers - called on well formed \#pragma
end_comment

begin_comment
comment|/// pointers_to_members(representation method[, general purpose
end_comment

begin_comment
comment|/// representation]).
end_comment

begin_decl_stmt
name|void
name|ActOnPragmaMSPointersToMembers
argument_list|(
name|LangOptions
operator|::
name|PragmaMSPointersToMembersKind
name|Kind
argument_list|,
name|SourceLocation
name|PragmaLoc
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// \brief Called on well formed \#pragma vtordisp().
end_comment

begin_decl_stmt
name|void
name|ActOnPragmaMSVtorDisp
argument_list|(
name|PragmaMsStackAction
name|Action
argument_list|,
name|SourceLocation
name|PragmaLoc
argument_list|,
name|MSVtorDispAttr
operator|::
name|Mode
name|Value
argument_list|)
decl_stmt|;
end_decl_stmt

begin_enum
enum|enum
name|PragmaSectionKind
block|{
name|PSK_DataSeg
block|,
name|PSK_BSSSeg
block|,
name|PSK_ConstSeg
block|,
name|PSK_CodeSeg
block|,   }
enum|;
end_enum

begin_function_decl
name|bool
name|UnifySection
parameter_list|(
name|StringRef
name|SectionName
parameter_list|,
name|int
name|SectionFlags
parameter_list|,
name|DeclaratorDecl
modifier|*
name|TheDecl
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|UnifySection
parameter_list|(
name|StringRef
name|SectionName
parameter_list|,
name|int
name|SectionFlags
parameter_list|,
name|SourceLocation
name|PragmaSectionLocation
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// \brief Called on well formed \#pragma bss_seg/data_seg/const_seg/code_seg.
end_comment

begin_decl_stmt
name|void
name|ActOnPragmaMSSeg
argument_list|(
name|SourceLocation
name|PragmaLocation
argument_list|,
name|PragmaMsStackAction
name|Action
argument_list|,
name|llvm
operator|::
name|StringRef
name|StackSlotLabel
argument_list|,
name|StringLiteral
operator|*
name|SegmentName
argument_list|,
name|llvm
operator|::
name|StringRef
name|PragmaName
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// \brief Called on well formed \#pragma section().
end_comment

begin_function_decl
name|void
name|ActOnPragmaMSSection
parameter_list|(
name|SourceLocation
name|PragmaLocation
parameter_list|,
name|int
name|SectionFlags
parameter_list|,
name|StringLiteral
modifier|*
name|SegmentName
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// \brief Called on well-formed \#pragma init_seg().
end_comment

begin_function_decl
name|void
name|ActOnPragmaMSInitSeg
parameter_list|(
name|SourceLocation
name|PragmaLocation
parameter_list|,
name|StringLiteral
modifier|*
name|SegmentName
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// \brief Called on #pragma clang __debug dump II
end_comment

begin_function_decl
name|void
name|ActOnPragmaDump
parameter_list|(
name|Scope
modifier|*
name|S
parameter_list|,
name|SourceLocation
name|Loc
parameter_list|,
name|IdentifierInfo
modifier|*
name|II
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// ActOnPragmaDetectMismatch - Call on well-formed \#pragma detect_mismatch
end_comment

begin_function_decl
name|void
name|ActOnPragmaDetectMismatch
parameter_list|(
name|SourceLocation
name|Loc
parameter_list|,
name|StringRef
name|Name
parameter_list|,
name|StringRef
name|Value
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// ActOnPragmaUnused - Called on well-formed '\#pragma unused'.
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
comment|/// ActOnPragmaVisibility - Called on well formed \#pragma GCC visibility... .
end_comment

begin_function_decl
name|void
name|ActOnPragmaVisibility
parameter_list|(
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
parameter_list|,
name|SourceLocation
name|Loc
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
comment|/// ActOnPragmaWeakID - Called on well formed \#pragma weak ident.
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
comment|/// ActOnPragmaRedefineExtname - Called on well formed
end_comment

begin_comment
comment|/// \#pragma redefine_extname oldname newname.
end_comment

begin_function_decl
name|void
name|ActOnPragmaRedefineExtname
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
comment|/// ActOnPragmaWeakAlias - Called on well formed \#pragma weak ident = ident.
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
comment|/// \#pragma {STDC,OPENCL} FP_CONTRACT and
end_comment

begin_comment
comment|/// \#pragma clang fp contract
end_comment

begin_decl_stmt
name|void
name|ActOnPragmaFPContract
argument_list|(
name|LangOptions
operator|::
name|FPContractModeKind
name|FPC
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// AddAlignmentAttributesForRecord - Adds any needed alignment attributes to
end_comment

begin_comment
comment|/// a the record decl, to handle '\#pragma pack' and '\#pragma options align'.
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
parameter_list|,
name|SourceLocation
name|Loc
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// AddPushedVisibilityAttribute - If '\#pragma GCC visibility' was used,
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
comment|/// for '\#pragma GCC visibility' and visibility attributes on namespaces.
end_comment

begin_function_decl
name|void
name|PopPragmaVisibility
parameter_list|(
name|bool
name|IsNamespaceEnd
parameter_list|,
name|SourceLocation
name|EndLoc
parameter_list|)
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
comment|/// AddCFAuditedAttribute - Check whether we're currently within
end_comment

begin_comment
comment|/// '\#pragma clang arc_cf_code_audited' and, if so, consider adding
end_comment

begin_comment
comment|/// the appropriate attribute.
end_comment

begin_function_decl
name|void
name|AddCFAuditedAttribute
parameter_list|(
name|Decl
modifier|*
name|D
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// \brief Called on well-formed '\#pragma clang attribute push'.
end_comment

begin_decl_stmt
name|void
name|ActOnPragmaAttributePush
argument_list|(
name|AttributeList
operator|&
name|Attribute
argument_list|,
name|SourceLocation
name|PragmaLoc
argument_list|,
name|attr
operator|::
name|ParsedSubjectMatchRuleSet
name|Rules
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// \brief Called on well-formed '\#pragma clang attribute pop'.
end_comment

begin_function_decl
name|void
name|ActOnPragmaAttributePop
parameter_list|(
name|SourceLocation
name|PragmaLoc
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// \brief Adds the attributes that have been specified using the
end_comment

begin_comment
comment|/// '\#pragma clang attribute push' directives to the given declaration.
end_comment

begin_function_decl
name|void
name|AddPragmaAttributes
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
name|DiagnoseUnterminatedPragmaAttribute
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/// \brief Called on well formed \#pragma clang optimize.
end_comment

begin_function_decl
name|void
name|ActOnPragmaOptimize
parameter_list|(
name|bool
name|On
parameter_list|,
name|SourceLocation
name|PragmaLoc
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// \brief Get the location for the currently active "\#pragma clang optimize
end_comment

begin_comment
comment|/// off". If this location is invalid, then the state of the pragma is "on".
end_comment

begin_expr_stmt
name|SourceLocation
name|getOptimizeOffPragmaLocation
argument_list|()
specifier|const
block|{
return|return
name|OptimizeOffPragmaLocation
return|;
block|}
end_expr_stmt

begin_comment
comment|/// \brief Only called on function definitions; if there is a pragma in scope
end_comment

begin_comment
comment|/// with the effect of a range-based optnone, consider marking the function
end_comment

begin_comment
comment|/// with attribute optnone.
end_comment

begin_function_decl
name|void
name|AddRangeBasedOptnone
parameter_list|(
name|FunctionDecl
modifier|*
name|FD
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// \brief Adds the 'optnone' attribute to the function declaration if there
end_comment

begin_comment
comment|/// are no conflicts; Loc represents the location causing the 'optnone'
end_comment

begin_comment
comment|/// attribute to be added (usually because of a pragma).
end_comment

begin_function_decl
name|void
name|AddOptnoneAttributeIfNoConflicts
parameter_list|(
name|FunctionDecl
modifier|*
name|FD
parameter_list|,
name|SourceLocation
name|Loc
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// AddAlignedAttr - Adds an aligned attribute to a particular declaration.
end_comment

begin_function_decl
name|void
name|AddAlignedAttr
parameter_list|(
name|SourceRange
name|AttrRange
parameter_list|,
name|Decl
modifier|*
name|D
parameter_list|,
name|Expr
modifier|*
name|E
parameter_list|,
name|unsigned
name|SpellingListIndex
parameter_list|,
name|bool
name|IsPackExpansion
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|AddAlignedAttr
parameter_list|(
name|SourceRange
name|AttrRange
parameter_list|,
name|Decl
modifier|*
name|D
parameter_list|,
name|TypeSourceInfo
modifier|*
name|T
parameter_list|,
name|unsigned
name|SpellingListIndex
parameter_list|,
name|bool
name|IsPackExpansion
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// AddAssumeAlignedAttr - Adds an assume_aligned attribute to a particular
end_comment

begin_comment
comment|/// declaration.
end_comment

begin_function_decl
name|void
name|AddAssumeAlignedAttr
parameter_list|(
name|SourceRange
name|AttrRange
parameter_list|,
name|Decl
modifier|*
name|D
parameter_list|,
name|Expr
modifier|*
name|E
parameter_list|,
name|Expr
modifier|*
name|OE
parameter_list|,
name|unsigned
name|SpellingListIndex
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// AddAllocAlignAttr - Adds an alloc_align attribute to a particular
end_comment

begin_comment
comment|/// declaration.
end_comment

begin_function_decl
name|void
name|AddAllocAlignAttr
parameter_list|(
name|SourceRange
name|AttrRange
parameter_list|,
name|Decl
modifier|*
name|D
parameter_list|,
name|Expr
modifier|*
name|ParamExpr
parameter_list|,
name|unsigned
name|SpellingListIndex
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// AddAlignValueAttr - Adds an align_value attribute to a particular
end_comment

begin_comment
comment|/// declaration.
end_comment

begin_function_decl
name|void
name|AddAlignValueAttr
parameter_list|(
name|SourceRange
name|AttrRange
parameter_list|,
name|Decl
modifier|*
name|D
parameter_list|,
name|Expr
modifier|*
name|E
parameter_list|,
name|unsigned
name|SpellingListIndex
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// AddLaunchBoundsAttr - Adds a launch_bounds attribute to a particular
end_comment

begin_comment
comment|/// declaration.
end_comment

begin_function_decl
name|void
name|AddLaunchBoundsAttr
parameter_list|(
name|SourceRange
name|AttrRange
parameter_list|,
name|Decl
modifier|*
name|D
parameter_list|,
name|Expr
modifier|*
name|MaxThreads
parameter_list|,
name|Expr
modifier|*
name|MinBlocks
parameter_list|,
name|unsigned
name|SpellingListIndex
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// AddModeAttr - Adds a mode attribute to a particular declaration.
end_comment

begin_function_decl
name|void
name|AddModeAttr
parameter_list|(
name|SourceRange
name|AttrRange
parameter_list|,
name|Decl
modifier|*
name|D
parameter_list|,
name|IdentifierInfo
modifier|*
name|Name
parameter_list|,
name|unsigned
name|SpellingListIndex
parameter_list|,
name|bool
name|InInstantiation
init|=
name|false
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|AddParameterABIAttr
parameter_list|(
name|SourceRange
name|AttrRange
parameter_list|,
name|Decl
modifier|*
name|D
parameter_list|,
name|ParameterABI
name|ABI
parameter_list|,
name|unsigned
name|SpellingListIndex
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|AddNSConsumedAttr
parameter_list|(
name|SourceRange
name|AttrRange
parameter_list|,
name|Decl
modifier|*
name|D
parameter_list|,
name|unsigned
name|SpellingListIndex
parameter_list|,
name|bool
name|isNSConsumed
parameter_list|,
name|bool
name|isTemplateInstantiation
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|//===--------------------------------------------------------------------===//
end_comment

begin_comment
comment|// C++ Coroutines TS
end_comment

begin_comment
comment|//
end_comment

begin_function_decl
name|ExprResult
name|ActOnCoawaitExpr
parameter_list|(
name|Scope
modifier|*
name|S
parameter_list|,
name|SourceLocation
name|KwLoc
parameter_list|,
name|Expr
modifier|*
name|E
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ExprResult
name|ActOnCoyieldExpr
parameter_list|(
name|Scope
modifier|*
name|S
parameter_list|,
name|SourceLocation
name|KwLoc
parameter_list|,
name|Expr
modifier|*
name|E
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|StmtResult
name|ActOnCoreturnStmt
parameter_list|(
name|Scope
modifier|*
name|S
parameter_list|,
name|SourceLocation
name|KwLoc
parameter_list|,
name|Expr
modifier|*
name|E
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ExprResult
name|BuildResolvedCoawaitExpr
parameter_list|(
name|SourceLocation
name|KwLoc
parameter_list|,
name|Expr
modifier|*
name|E
parameter_list|,
name|bool
name|IsImplicit
init|=
name|false
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ExprResult
name|BuildUnresolvedCoawaitExpr
parameter_list|(
name|SourceLocation
name|KwLoc
parameter_list|,
name|Expr
modifier|*
name|E
parameter_list|,
name|UnresolvedLookupExpr
modifier|*
name|Lookup
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ExprResult
name|BuildCoyieldExpr
parameter_list|(
name|SourceLocation
name|KwLoc
parameter_list|,
name|Expr
modifier|*
name|E
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|StmtResult
name|BuildCoreturnStmt
parameter_list|(
name|SourceLocation
name|KwLoc
parameter_list|,
name|Expr
modifier|*
name|E
parameter_list|,
name|bool
name|IsImplicit
init|=
name|false
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
name|StmtResult
name|BuildCoroutineBodyStmt
argument_list|(
name|CoroutineBodyStmt
operator|::
name|CtorArgs
argument_list|)
decl_stmt|;
end_decl_stmt

begin_function_decl
name|VarDecl
modifier|*
name|buildCoroutinePromise
parameter_list|(
name|SourceLocation
name|Loc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|CheckCompletedCoroutineBody
parameter_list|(
name|FunctionDecl
modifier|*
name|FD
parameter_list|,
name|Stmt
modifier|*
modifier|&
name|Body
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|//===--------------------------------------------------------------------===//
end_comment

begin_comment
comment|// OpenCL extensions.
end_comment

begin_comment
comment|//
end_comment

begin_label
name|private
label|:
end_label

begin_expr_stmt
name|std
operator|::
name|string
name|CurrOpenCLExtension
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// Extensions required by an OpenCL type.
end_comment

begin_expr_stmt
name|llvm
operator|::
name|DenseMap
operator|<
specifier|const
name|Type
operator|*
operator|,
name|std
operator|::
name|set
operator|<
name|std
operator|::
name|string
operator|>>
name|OpenCLTypeExtMap
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// Extensions required by an OpenCL declaration.
end_comment

begin_expr_stmt
name|llvm
operator|::
name|DenseMap
operator|<
specifier|const
name|Decl
operator|*
operator|,
name|std
operator|::
name|set
operator|<
name|std
operator|::
name|string
operator|>>
name|OpenCLDeclExtMap
expr_stmt|;
end_expr_stmt

begin_label
name|public
label|:
end_label

begin_expr_stmt
name|llvm
operator|::
name|StringRef
name|getCurrentOpenCLExtension
argument_list|()
specifier|const
block|{
return|return
name|CurrOpenCLExtension
return|;
block|}
end_expr_stmt

begin_decl_stmt
name|void
name|setCurrentOpenCLExtension
argument_list|(
name|llvm
operator|::
name|StringRef
name|Ext
argument_list|)
block|{
name|CurrOpenCLExtension
operator|=
name|Ext
expr_stmt|;
block|}
end_decl_stmt

begin_comment
comment|/// \brief Set OpenCL extensions for a type which can only be used when these
end_comment

begin_comment
comment|/// OpenCL extensions are enabled. If \p Exts is empty, do nothing.
end_comment

begin_comment
comment|/// \param Exts A space separated list of OpenCL extensions.
end_comment

begin_decl_stmt
name|void
name|setOpenCLExtensionForType
argument_list|(
name|QualType
name|T
argument_list|,
name|llvm
operator|::
name|StringRef
name|Exts
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// \brief Set OpenCL extensions for a declaration which can only be
end_comment

begin_comment
comment|/// used when these OpenCL extensions are enabled. If \p Exts is empty, do
end_comment

begin_comment
comment|/// nothing.
end_comment

begin_comment
comment|/// \param Exts A space separated list of OpenCL extensions.
end_comment

begin_decl_stmt
name|void
name|setOpenCLExtensionForDecl
argument_list|(
name|Decl
operator|*
name|FD
argument_list|,
name|llvm
operator|::
name|StringRef
name|Exts
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// \brief Set current OpenCL extensions for a type which can only be used
end_comment

begin_comment
comment|/// when these OpenCL extensions are enabled. If current OpenCL extension is
end_comment

begin_comment
comment|/// empty, do nothing.
end_comment

begin_function_decl
name|void
name|setCurrentOpenCLExtensionForType
parameter_list|(
name|QualType
name|T
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// \brief Set current OpenCL extensions for a declaration which
end_comment

begin_comment
comment|/// can only be used when these OpenCL extensions are enabled. If current
end_comment

begin_comment
comment|/// OpenCL extension is empty, do nothing.
end_comment

begin_function_decl
name|void
name|setCurrentOpenCLExtensionForDecl
parameter_list|(
name|Decl
modifier|*
name|FD
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|isOpenCLDisabledDecl
parameter_list|(
name|Decl
modifier|*
name|FD
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// \brief Check if type \p T corresponding to declaration specifier \p DS
end_comment

begin_comment
comment|/// is disabled due to required OpenCL extensions being disabled. If so,
end_comment

begin_comment
comment|/// emit diagnostics.
end_comment

begin_comment
comment|/// \return true if type is disabled.
end_comment

begin_function_decl
name|bool
name|checkOpenCLDisabledTypeDeclSpec
parameter_list|(
specifier|const
name|DeclSpec
modifier|&
name|DS
parameter_list|,
name|QualType
name|T
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// \brief Check if declaration \p D used by expression \p E
end_comment

begin_comment
comment|/// is disabled due to required OpenCL extensions being disabled. If so,
end_comment

begin_comment
comment|/// emit diagnostics.
end_comment

begin_comment
comment|/// \return true if type is disabled.
end_comment

begin_function_decl
name|bool
name|checkOpenCLDisabledDecl
parameter_list|(
specifier|const
name|Decl
modifier|&
name|D
parameter_list|,
specifier|const
name|Expr
modifier|&
name|E
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|//===--------------------------------------------------------------------===//
end_comment

begin_comment
comment|// OpenMP directives and clauses.
end_comment

begin_comment
comment|//
end_comment

begin_label
name|private
label|:
end_label

begin_decl_stmt
name|void
modifier|*
name|VarDataSharingAttributesStack
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// Set to true inside '#pragma omp declare target' region.
end_comment

begin_decl_stmt
name|bool
name|IsInOpenMPDeclareTargetContext
init|=
name|false
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// \brief Initialization of data-sharing attributes stack.
end_comment

begin_function_decl
name|void
name|InitDataSharingAttributesStack
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|DestroyDataSharingAttributesStack
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|ExprResult
name|VerifyPositiveIntegerConstantInClause
parameter_list|(
name|Expr
modifier|*
name|Op
parameter_list|,
name|OpenMPClauseKind
name|CKind
parameter_list|,
name|bool
name|StrictlyPositive
init|=
name|true
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// Returns OpenMP nesting level for current directive.
end_comment

begin_expr_stmt
name|unsigned
name|getOpenMPNestingLevel
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// Push new OpenMP function region for non-capturing function.
end_comment

begin_function_decl
name|void
name|pushOpenMPFunctionRegion
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/// Pop OpenMP function region for non-capturing function.
end_comment

begin_decl_stmt
name|void
name|popOpenMPFunctionRegion
argument_list|(
specifier|const
name|sema
operator|::
name|FunctionScopeInfo
operator|*
name|OldFSI
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// Checks if a type or a declaration is disabled due to the owning extension
end_comment

begin_comment
comment|/// being disabled, and emits diagnostic messages if it is disabled.
end_comment

begin_comment
comment|/// \param D type or declaration to be checked.
end_comment

begin_comment
comment|/// \param DiagLoc source location for the diagnostic message.
end_comment

begin_comment
comment|/// \param DiagInfo information to be emitted for the diagnostic message.
end_comment

begin_comment
comment|/// \param SrcRange source range of the declaration.
end_comment

begin_comment
comment|/// \param Map maps type or declaration to the extensions.
end_comment

begin_comment
comment|/// \param Selector selects diagnostic message: 0 for type and 1 for
end_comment

begin_comment
comment|///        declaration.
end_comment

begin_comment
comment|/// \return true if the type or declaration is disabled.
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|,
name|typename
name|DiagLocT
operator|,
name|typename
name|DiagInfoT
operator|,
name|typename
name|MapT
operator|>
name|bool
name|checkOpenCLDisabledTypeOrDecl
argument_list|(
argument|T D
argument_list|,
argument|DiagLocT DiagLoc
argument_list|,
argument|DiagInfoT DiagInfo
argument_list|,
argument|MapT&Map
argument_list|,
argument|unsigned Selector =
literal|0
argument_list|,
argument|SourceRange SrcRange = SourceRange()
argument_list|)
expr_stmt|;
end_expr_stmt

begin_label
name|public
label|:
end_label

begin_comment
comment|/// \brief Return true if the provided declaration \a VD should be captured by
end_comment

begin_comment
comment|/// reference.
end_comment

begin_comment
comment|/// \param Level Relative level of nested OpenMP construct for that the check
end_comment

begin_comment
comment|/// is performed.
end_comment

begin_function_decl
name|bool
name|IsOpenMPCapturedByRef
parameter_list|(
name|ValueDecl
modifier|*
name|D
parameter_list|,
name|unsigned
name|Level
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// \brief Check if the specified variable is used in one of the private
end_comment

begin_comment
comment|/// clauses (private, firstprivate, lastprivate, reduction etc.) in OpenMP
end_comment

begin_comment
comment|/// constructs.
end_comment

begin_function_decl
name|VarDecl
modifier|*
name|IsOpenMPCapturedDecl
parameter_list|(
name|ValueDecl
modifier|*
name|D
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ExprResult
name|getOpenMPCapturedExpr
parameter_list|(
name|VarDecl
modifier|*
name|Capture
parameter_list|,
name|ExprValueKind
name|VK
parameter_list|,
name|ExprObjectKind
name|OK
parameter_list|,
name|SourceLocation
name|Loc
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// \brief Check if the specified variable is used in 'private' clause.
end_comment

begin_comment
comment|/// \param Level Relative level of nested OpenMP construct for that the check
end_comment

begin_comment
comment|/// is performed.
end_comment

begin_function_decl
name|bool
name|isOpenMPPrivateDecl
parameter_list|(
name|ValueDecl
modifier|*
name|D
parameter_list|,
name|unsigned
name|Level
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// \brief Check if the specified variable is captured  by 'target' directive.
end_comment

begin_comment
comment|/// \param Level Relative level of nested OpenMP construct for that the check
end_comment

begin_comment
comment|/// is performed.
end_comment

begin_function_decl
name|bool
name|isOpenMPTargetCapturedDecl
parameter_list|(
name|ValueDecl
modifier|*
name|D
parameter_list|,
name|unsigned
name|Level
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ExprResult
name|PerformOpenMPImplicitIntegerConversion
parameter_list|(
name|SourceLocation
name|OpLoc
parameter_list|,
name|Expr
modifier|*
name|Op
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// \brief Called on start of new data sharing attribute block.
end_comment

begin_function_decl
name|void
name|StartOpenMPDSABlock
parameter_list|(
name|OpenMPDirectiveKind
name|K
parameter_list|,
specifier|const
name|DeclarationNameInfo
modifier|&
name|DirName
parameter_list|,
name|Scope
modifier|*
name|CurScope
parameter_list|,
name|SourceLocation
name|Loc
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// \brief Start analysis of clauses.
end_comment

begin_function_decl
name|void
name|StartOpenMPClause
parameter_list|(
name|OpenMPClauseKind
name|K
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// \brief End analysis of clauses.
end_comment

begin_function_decl
name|void
name|EndOpenMPClause
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/// \brief Called on end of data sharing attribute block.
end_comment

begin_function_decl
name|void
name|EndOpenMPDSABlock
parameter_list|(
name|Stmt
modifier|*
name|CurDirective
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// \brief Check if the current region is an OpenMP loop region and if it is,
end_comment

begin_comment
comment|/// mark loop control variable, used in \p Init for loop initialization, as
end_comment

begin_comment
comment|/// private by default.
end_comment

begin_comment
comment|/// \param Init First part of the for loop.
end_comment

begin_function_decl
name|void
name|ActOnOpenMPLoopInitialization
parameter_list|(
name|SourceLocation
name|ForLoc
parameter_list|,
name|Stmt
modifier|*
name|Init
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|// OpenMP directives and clauses.
end_comment

begin_comment
comment|/// \brief Called on correct id-expression from the '#pragma omp
end_comment

begin_comment
comment|/// threadprivate'.
end_comment

begin_function_decl
name|ExprResult
name|ActOnOpenMPIdExpression
parameter_list|(
name|Scope
modifier|*
name|CurScope
parameter_list|,
name|CXXScopeSpec
modifier|&
name|ScopeSpec
parameter_list|,
specifier|const
name|DeclarationNameInfo
modifier|&
name|Id
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// \brief Called on well-formed '#pragma omp threadprivate'.
end_comment

begin_decl_stmt
name|DeclGroupPtrTy
name|ActOnOpenMPThreadprivateDirective
argument_list|(
name|SourceLocation
name|Loc
argument_list|,
name|ArrayRef
operator|<
name|Expr
operator|*
operator|>
name|VarList
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// \brief Builds a new OpenMPThreadPrivateDecl and checks its correctness.
end_comment

begin_decl_stmt
name|OMPThreadPrivateDecl
modifier|*
name|CheckOMPThreadPrivateDecl
argument_list|(
name|SourceLocation
name|Loc
argument_list|,
name|ArrayRef
operator|<
name|Expr
operator|*
operator|>
name|VarList
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// \brief Check if the specified type is allowed to be used in 'omp declare
end_comment

begin_comment
comment|/// reduction' construct.
end_comment

begin_function_decl
name|QualType
name|ActOnOpenMPDeclareReductionType
parameter_list|(
name|SourceLocation
name|TyLoc
parameter_list|,
name|TypeResult
name|ParsedType
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// \brief Called on start of '#pragma omp declare reduction'.
end_comment

begin_decl_stmt
name|DeclGroupPtrTy
name|ActOnOpenMPDeclareReductionDirectiveStart
argument_list|(
name|Scope
operator|*
name|S
argument_list|,
name|DeclContext
operator|*
name|DC
argument_list|,
name|DeclarationName
name|Name
argument_list|,
name|ArrayRef
operator|<
name|std
operator|::
name|pair
operator|<
name|QualType
argument_list|,
name|SourceLocation
operator|>>
name|ReductionTypes
argument_list|,
name|AccessSpecifier
name|AS
argument_list|,
name|Decl
operator|*
name|PrevDeclInScope
operator|=
name|nullptr
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// \brief Initialize declare reduction construct initializer.
end_comment

begin_function_decl
name|void
name|ActOnOpenMPDeclareReductionCombinerStart
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

begin_comment
comment|/// \brief Finish current declare reduction construct initializer.
end_comment

begin_function_decl
name|void
name|ActOnOpenMPDeclareReductionCombinerEnd
parameter_list|(
name|Decl
modifier|*
name|D
parameter_list|,
name|Expr
modifier|*
name|Combiner
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// \brief Initialize declare reduction construct initializer.
end_comment

begin_function_decl
name|void
name|ActOnOpenMPDeclareReductionInitializerStart
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

begin_comment
comment|/// \brief Finish current declare reduction construct initializer.
end_comment

begin_function_decl
name|void
name|ActOnOpenMPDeclareReductionInitializerEnd
parameter_list|(
name|Decl
modifier|*
name|D
parameter_list|,
name|Expr
modifier|*
name|Initializer
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// \brief Called at the end of '#pragma omp declare reduction'.
end_comment

begin_function_decl
name|DeclGroupPtrTy
name|ActOnOpenMPDeclareReductionDirectiveEnd
parameter_list|(
name|Scope
modifier|*
name|S
parameter_list|,
name|DeclGroupPtrTy
name|DeclReductions
parameter_list|,
name|bool
name|IsValid
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// Called on the start of target region i.e. '#pragma omp declare target'.
end_comment

begin_function_decl
name|bool
name|ActOnStartOpenMPDeclareTargetDirective
parameter_list|(
name|SourceLocation
name|Loc
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// Called at the end of target region i.e. '#pragme omp end declare target'.
end_comment

begin_function_decl
name|void
name|ActOnFinishOpenMPDeclareTargetDirective
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/// Called on correct id-expression from the '#pragma omp declare target'.
end_comment

begin_decl_stmt
name|void
name|ActOnOpenMPDeclareTargetName
argument_list|(
name|Scope
operator|*
name|CurScope
argument_list|,
name|CXXScopeSpec
operator|&
name|ScopeSpec
argument_list|,
specifier|const
name|DeclarationNameInfo
operator|&
name|Id
argument_list|,
name|OMPDeclareTargetDeclAttr
operator|::
name|MapTypeTy
name|MT
argument_list|,
name|NamedDeclSetType
operator|&
name|SameDirectiveDecls
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// Check declaration inside target region.
end_comment

begin_function_decl
name|void
name|checkDeclIsAllowedInOpenMPTarget
parameter_list|(
name|Expr
modifier|*
name|E
parameter_list|,
name|Decl
modifier|*
name|D
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// Return true inside OpenMP target region.
end_comment

begin_expr_stmt
name|bool
name|isInOpenMPDeclareTargetContext
argument_list|()
specifier|const
block|{
return|return
name|IsInOpenMPDeclareTargetContext
return|;
block|}
end_expr_stmt

begin_comment
comment|/// Return the number of captured regions created for an OpenMP directive.
end_comment

begin_function_decl
specifier|static
name|int
name|getOpenMPCaptureLevels
parameter_list|(
name|OpenMPDirectiveKind
name|Kind
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// \brief Initialization of captured region for OpenMP region.
end_comment

begin_function_decl
name|void
name|ActOnOpenMPRegionStart
parameter_list|(
name|OpenMPDirectiveKind
name|DKind
parameter_list|,
name|Scope
modifier|*
name|CurScope
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// \brief End of OpenMP region.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param S Statement associated with the current OpenMP region.
end_comment

begin_comment
comment|/// \param Clauses List of clauses for the current OpenMP region.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \returns Statement for finished OpenMP region.
end_comment

begin_decl_stmt
name|StmtResult
name|ActOnOpenMPRegionEnd
argument_list|(
name|StmtResult
name|S
argument_list|,
name|ArrayRef
operator|<
name|OMPClause
operator|*
operator|>
name|Clauses
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|StmtResult
name|ActOnOpenMPExecutableDirective
argument_list|(
name|OpenMPDirectiveKind
name|Kind
argument_list|,
specifier|const
name|DeclarationNameInfo
operator|&
name|DirName
argument_list|,
name|OpenMPDirectiveKind
name|CancelRegion
argument_list|,
name|ArrayRef
operator|<
name|OMPClause
operator|*
operator|>
name|Clauses
argument_list|,
name|Stmt
operator|*
name|AStmt
argument_list|,
name|SourceLocation
name|StartLoc
argument_list|,
name|SourceLocation
name|EndLoc
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// \brief Called on well-formed '\#pragma omp parallel' after parsing
end_comment

begin_comment
comment|/// of the  associated statement.
end_comment

begin_decl_stmt
name|StmtResult
name|ActOnOpenMPParallelDirective
argument_list|(
name|ArrayRef
operator|<
name|OMPClause
operator|*
operator|>
name|Clauses
argument_list|,
name|Stmt
operator|*
name|AStmt
argument_list|,
name|SourceLocation
name|StartLoc
argument_list|,
name|SourceLocation
name|EndLoc
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// \brief Called on well-formed '\#pragma omp simd' after parsing
end_comment

begin_comment
comment|/// of the associated statement.
end_comment

begin_decl_stmt
name|StmtResult
name|ActOnOpenMPSimdDirective
argument_list|(
name|ArrayRef
operator|<
name|OMPClause
operator|*
operator|>
name|Clauses
argument_list|,
name|Stmt
operator|*
name|AStmt
argument_list|,
name|SourceLocation
name|StartLoc
argument_list|,
name|SourceLocation
name|EndLoc
argument_list|,
name|llvm
operator|::
name|DenseMap
operator|<
name|ValueDecl
operator|*
argument_list|,
name|Expr
operator|*
operator|>
operator|&
name|VarsWithImplicitDSA
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// \brief Called on well-formed '\#pragma omp for' after parsing
end_comment

begin_comment
comment|/// of the associated statement.
end_comment

begin_decl_stmt
name|StmtResult
name|ActOnOpenMPForDirective
argument_list|(
name|ArrayRef
operator|<
name|OMPClause
operator|*
operator|>
name|Clauses
argument_list|,
name|Stmt
operator|*
name|AStmt
argument_list|,
name|SourceLocation
name|StartLoc
argument_list|,
name|SourceLocation
name|EndLoc
argument_list|,
name|llvm
operator|::
name|DenseMap
operator|<
name|ValueDecl
operator|*
argument_list|,
name|Expr
operator|*
operator|>
operator|&
name|VarsWithImplicitDSA
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// \brief Called on well-formed '\#pragma omp for simd' after parsing
end_comment

begin_comment
comment|/// of the associated statement.
end_comment

begin_decl_stmt
name|StmtResult
name|ActOnOpenMPForSimdDirective
argument_list|(
name|ArrayRef
operator|<
name|OMPClause
operator|*
operator|>
name|Clauses
argument_list|,
name|Stmt
operator|*
name|AStmt
argument_list|,
name|SourceLocation
name|StartLoc
argument_list|,
name|SourceLocation
name|EndLoc
argument_list|,
name|llvm
operator|::
name|DenseMap
operator|<
name|ValueDecl
operator|*
argument_list|,
name|Expr
operator|*
operator|>
operator|&
name|VarsWithImplicitDSA
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// \brief Called on well-formed '\#pragma omp sections' after parsing
end_comment

begin_comment
comment|/// of the associated statement.
end_comment

begin_decl_stmt
name|StmtResult
name|ActOnOpenMPSectionsDirective
argument_list|(
name|ArrayRef
operator|<
name|OMPClause
operator|*
operator|>
name|Clauses
argument_list|,
name|Stmt
operator|*
name|AStmt
argument_list|,
name|SourceLocation
name|StartLoc
argument_list|,
name|SourceLocation
name|EndLoc
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// \brief Called on well-formed '\#pragma omp section' after parsing of the
end_comment

begin_comment
comment|/// associated statement.
end_comment

begin_function_decl
name|StmtResult
name|ActOnOpenMPSectionDirective
parameter_list|(
name|Stmt
modifier|*
name|AStmt
parameter_list|,
name|SourceLocation
name|StartLoc
parameter_list|,
name|SourceLocation
name|EndLoc
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// \brief Called on well-formed '\#pragma omp single' after parsing of the
end_comment

begin_comment
comment|/// associated statement.
end_comment

begin_decl_stmt
name|StmtResult
name|ActOnOpenMPSingleDirective
argument_list|(
name|ArrayRef
operator|<
name|OMPClause
operator|*
operator|>
name|Clauses
argument_list|,
name|Stmt
operator|*
name|AStmt
argument_list|,
name|SourceLocation
name|StartLoc
argument_list|,
name|SourceLocation
name|EndLoc
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// \brief Called on well-formed '\#pragma omp master' after parsing of the
end_comment

begin_comment
comment|/// associated statement.
end_comment

begin_function_decl
name|StmtResult
name|ActOnOpenMPMasterDirective
parameter_list|(
name|Stmt
modifier|*
name|AStmt
parameter_list|,
name|SourceLocation
name|StartLoc
parameter_list|,
name|SourceLocation
name|EndLoc
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// \brief Called on well-formed '\#pragma omp critical' after parsing of the
end_comment

begin_comment
comment|/// associated statement.
end_comment

begin_decl_stmt
name|StmtResult
name|ActOnOpenMPCriticalDirective
argument_list|(
specifier|const
name|DeclarationNameInfo
operator|&
name|DirName
argument_list|,
name|ArrayRef
operator|<
name|OMPClause
operator|*
operator|>
name|Clauses
argument_list|,
name|Stmt
operator|*
name|AStmt
argument_list|,
name|SourceLocation
name|StartLoc
argument_list|,
name|SourceLocation
name|EndLoc
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// \brief Called on well-formed '\#pragma omp parallel for' after parsing
end_comment

begin_comment
comment|/// of the  associated statement.
end_comment

begin_decl_stmt
name|StmtResult
name|ActOnOpenMPParallelForDirective
argument_list|(
name|ArrayRef
operator|<
name|OMPClause
operator|*
operator|>
name|Clauses
argument_list|,
name|Stmt
operator|*
name|AStmt
argument_list|,
name|SourceLocation
name|StartLoc
argument_list|,
name|SourceLocation
name|EndLoc
argument_list|,
name|llvm
operator|::
name|DenseMap
operator|<
name|ValueDecl
operator|*
argument_list|,
name|Expr
operator|*
operator|>
operator|&
name|VarsWithImplicitDSA
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// \brief Called on well-formed '\#pragma omp parallel for simd' after
end_comment

begin_comment
comment|/// parsing of the  associated statement.
end_comment

begin_decl_stmt
name|StmtResult
name|ActOnOpenMPParallelForSimdDirective
argument_list|(
name|ArrayRef
operator|<
name|OMPClause
operator|*
operator|>
name|Clauses
argument_list|,
name|Stmt
operator|*
name|AStmt
argument_list|,
name|SourceLocation
name|StartLoc
argument_list|,
name|SourceLocation
name|EndLoc
argument_list|,
name|llvm
operator|::
name|DenseMap
operator|<
name|ValueDecl
operator|*
argument_list|,
name|Expr
operator|*
operator|>
operator|&
name|VarsWithImplicitDSA
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// \brief Called on well-formed '\#pragma omp parallel sections' after
end_comment

begin_comment
comment|/// parsing of the  associated statement.
end_comment

begin_decl_stmt
name|StmtResult
name|ActOnOpenMPParallelSectionsDirective
argument_list|(
name|ArrayRef
operator|<
name|OMPClause
operator|*
operator|>
name|Clauses
argument_list|,
name|Stmt
operator|*
name|AStmt
argument_list|,
name|SourceLocation
name|StartLoc
argument_list|,
name|SourceLocation
name|EndLoc
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// \brief Called on well-formed '\#pragma omp task' after parsing of the
end_comment

begin_comment
comment|/// associated statement.
end_comment

begin_decl_stmt
name|StmtResult
name|ActOnOpenMPTaskDirective
argument_list|(
name|ArrayRef
operator|<
name|OMPClause
operator|*
operator|>
name|Clauses
argument_list|,
name|Stmt
operator|*
name|AStmt
argument_list|,
name|SourceLocation
name|StartLoc
argument_list|,
name|SourceLocation
name|EndLoc
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// \brief Called on well-formed '\#pragma omp taskyield'.
end_comment

begin_function_decl
name|StmtResult
name|ActOnOpenMPTaskyieldDirective
parameter_list|(
name|SourceLocation
name|StartLoc
parameter_list|,
name|SourceLocation
name|EndLoc
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// \brief Called on well-formed '\#pragma omp barrier'.
end_comment

begin_function_decl
name|StmtResult
name|ActOnOpenMPBarrierDirective
parameter_list|(
name|SourceLocation
name|StartLoc
parameter_list|,
name|SourceLocation
name|EndLoc
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// \brief Called on well-formed '\#pragma omp taskwait'.
end_comment

begin_function_decl
name|StmtResult
name|ActOnOpenMPTaskwaitDirective
parameter_list|(
name|SourceLocation
name|StartLoc
parameter_list|,
name|SourceLocation
name|EndLoc
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// \brief Called on well-formed '\#pragma omp taskgroup'.
end_comment

begin_function_decl
name|StmtResult
name|ActOnOpenMPTaskgroupDirective
parameter_list|(
name|Stmt
modifier|*
name|AStmt
parameter_list|,
name|SourceLocation
name|StartLoc
parameter_list|,
name|SourceLocation
name|EndLoc
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// \brief Called on well-formed '\#pragma omp flush'.
end_comment

begin_decl_stmt
name|StmtResult
name|ActOnOpenMPFlushDirective
argument_list|(
name|ArrayRef
operator|<
name|OMPClause
operator|*
operator|>
name|Clauses
argument_list|,
name|SourceLocation
name|StartLoc
argument_list|,
name|SourceLocation
name|EndLoc
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// \brief Called on well-formed '\#pragma omp ordered' after parsing of the
end_comment

begin_comment
comment|/// associated statement.
end_comment

begin_decl_stmt
name|StmtResult
name|ActOnOpenMPOrderedDirective
argument_list|(
name|ArrayRef
operator|<
name|OMPClause
operator|*
operator|>
name|Clauses
argument_list|,
name|Stmt
operator|*
name|AStmt
argument_list|,
name|SourceLocation
name|StartLoc
argument_list|,
name|SourceLocation
name|EndLoc
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// \brief Called on well-formed '\#pragma omp atomic' after parsing of the
end_comment

begin_comment
comment|/// associated statement.
end_comment

begin_decl_stmt
name|StmtResult
name|ActOnOpenMPAtomicDirective
argument_list|(
name|ArrayRef
operator|<
name|OMPClause
operator|*
operator|>
name|Clauses
argument_list|,
name|Stmt
operator|*
name|AStmt
argument_list|,
name|SourceLocation
name|StartLoc
argument_list|,
name|SourceLocation
name|EndLoc
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// \brief Called on well-formed '\#pragma omp target' after parsing of the
end_comment

begin_comment
comment|/// associated statement.
end_comment

begin_decl_stmt
name|StmtResult
name|ActOnOpenMPTargetDirective
argument_list|(
name|ArrayRef
operator|<
name|OMPClause
operator|*
operator|>
name|Clauses
argument_list|,
name|Stmt
operator|*
name|AStmt
argument_list|,
name|SourceLocation
name|StartLoc
argument_list|,
name|SourceLocation
name|EndLoc
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// \brief Called on well-formed '\#pragma omp target data' after parsing of
end_comment

begin_comment
comment|/// the associated statement.
end_comment

begin_decl_stmt
name|StmtResult
name|ActOnOpenMPTargetDataDirective
argument_list|(
name|ArrayRef
operator|<
name|OMPClause
operator|*
operator|>
name|Clauses
argument_list|,
name|Stmt
operator|*
name|AStmt
argument_list|,
name|SourceLocation
name|StartLoc
argument_list|,
name|SourceLocation
name|EndLoc
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// \brief Called on well-formed '\#pragma omp target enter data' after
end_comment

begin_comment
comment|/// parsing of the associated statement.
end_comment

begin_decl_stmt
name|StmtResult
name|ActOnOpenMPTargetEnterDataDirective
argument_list|(
name|ArrayRef
operator|<
name|OMPClause
operator|*
operator|>
name|Clauses
argument_list|,
name|SourceLocation
name|StartLoc
argument_list|,
name|SourceLocation
name|EndLoc
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// \brief Called on well-formed '\#pragma omp target exit data' after
end_comment

begin_comment
comment|/// parsing of the associated statement.
end_comment

begin_decl_stmt
name|StmtResult
name|ActOnOpenMPTargetExitDataDirective
argument_list|(
name|ArrayRef
operator|<
name|OMPClause
operator|*
operator|>
name|Clauses
argument_list|,
name|SourceLocation
name|StartLoc
argument_list|,
name|SourceLocation
name|EndLoc
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// \brief Called on well-formed '\#pragma omp target parallel' after
end_comment

begin_comment
comment|/// parsing of the associated statement.
end_comment

begin_decl_stmt
name|StmtResult
name|ActOnOpenMPTargetParallelDirective
argument_list|(
name|ArrayRef
operator|<
name|OMPClause
operator|*
operator|>
name|Clauses
argument_list|,
name|Stmt
operator|*
name|AStmt
argument_list|,
name|SourceLocation
name|StartLoc
argument_list|,
name|SourceLocation
name|EndLoc
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// \brief Called on well-formed '\#pragma omp target parallel for' after
end_comment

begin_comment
comment|/// parsing of the  associated statement.
end_comment

begin_decl_stmt
name|StmtResult
name|ActOnOpenMPTargetParallelForDirective
argument_list|(
name|ArrayRef
operator|<
name|OMPClause
operator|*
operator|>
name|Clauses
argument_list|,
name|Stmt
operator|*
name|AStmt
argument_list|,
name|SourceLocation
name|StartLoc
argument_list|,
name|SourceLocation
name|EndLoc
argument_list|,
name|llvm
operator|::
name|DenseMap
operator|<
name|ValueDecl
operator|*
argument_list|,
name|Expr
operator|*
operator|>
operator|&
name|VarsWithImplicitDSA
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// \brief Called on well-formed '\#pragma omp teams' after parsing of the
end_comment

begin_comment
comment|/// associated statement.
end_comment

begin_decl_stmt
name|StmtResult
name|ActOnOpenMPTeamsDirective
argument_list|(
name|ArrayRef
operator|<
name|OMPClause
operator|*
operator|>
name|Clauses
argument_list|,
name|Stmt
operator|*
name|AStmt
argument_list|,
name|SourceLocation
name|StartLoc
argument_list|,
name|SourceLocation
name|EndLoc
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// \brief Called on well-formed '\#pragma omp cancellation point'.
end_comment

begin_function_decl
name|StmtResult
name|ActOnOpenMPCancellationPointDirective
parameter_list|(
name|SourceLocation
name|StartLoc
parameter_list|,
name|SourceLocation
name|EndLoc
parameter_list|,
name|OpenMPDirectiveKind
name|CancelRegion
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// \brief Called on well-formed '\#pragma omp cancel'.
end_comment

begin_decl_stmt
name|StmtResult
name|ActOnOpenMPCancelDirective
argument_list|(
name|ArrayRef
operator|<
name|OMPClause
operator|*
operator|>
name|Clauses
argument_list|,
name|SourceLocation
name|StartLoc
argument_list|,
name|SourceLocation
name|EndLoc
argument_list|,
name|OpenMPDirectiveKind
name|CancelRegion
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// \brief Called on well-formed '\#pragma omp taskloop' after parsing of the
end_comment

begin_comment
comment|/// associated statement.
end_comment

begin_decl_stmt
name|StmtResult
name|ActOnOpenMPTaskLoopDirective
argument_list|(
name|ArrayRef
operator|<
name|OMPClause
operator|*
operator|>
name|Clauses
argument_list|,
name|Stmt
operator|*
name|AStmt
argument_list|,
name|SourceLocation
name|StartLoc
argument_list|,
name|SourceLocation
name|EndLoc
argument_list|,
name|llvm
operator|::
name|DenseMap
operator|<
name|ValueDecl
operator|*
argument_list|,
name|Expr
operator|*
operator|>
operator|&
name|VarsWithImplicitDSA
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// \brief Called on well-formed '\#pragma omp taskloop simd' after parsing of
end_comment

begin_comment
comment|/// the associated statement.
end_comment

begin_decl_stmt
name|StmtResult
name|ActOnOpenMPTaskLoopSimdDirective
argument_list|(
name|ArrayRef
operator|<
name|OMPClause
operator|*
operator|>
name|Clauses
argument_list|,
name|Stmt
operator|*
name|AStmt
argument_list|,
name|SourceLocation
name|StartLoc
argument_list|,
name|SourceLocation
name|EndLoc
argument_list|,
name|llvm
operator|::
name|DenseMap
operator|<
name|ValueDecl
operator|*
argument_list|,
name|Expr
operator|*
operator|>
operator|&
name|VarsWithImplicitDSA
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// \brief Called on well-formed '\#pragma omp distribute' after parsing
end_comment

begin_comment
comment|/// of the associated statement.
end_comment

begin_decl_stmt
name|StmtResult
name|ActOnOpenMPDistributeDirective
argument_list|(
name|ArrayRef
operator|<
name|OMPClause
operator|*
operator|>
name|Clauses
argument_list|,
name|Stmt
operator|*
name|AStmt
argument_list|,
name|SourceLocation
name|StartLoc
argument_list|,
name|SourceLocation
name|EndLoc
argument_list|,
name|llvm
operator|::
name|DenseMap
operator|<
name|ValueDecl
operator|*
argument_list|,
name|Expr
operator|*
operator|>
operator|&
name|VarsWithImplicitDSA
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// \brief Called on well-formed '\#pragma omp target update'.
end_comment

begin_decl_stmt
name|StmtResult
name|ActOnOpenMPTargetUpdateDirective
argument_list|(
name|ArrayRef
operator|<
name|OMPClause
operator|*
operator|>
name|Clauses
argument_list|,
name|SourceLocation
name|StartLoc
argument_list|,
name|SourceLocation
name|EndLoc
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// \brief Called on well-formed '\#pragma omp distribute parallel for' after
end_comment

begin_comment
comment|/// parsing of the associated statement.
end_comment

begin_decl_stmt
name|StmtResult
name|ActOnOpenMPDistributeParallelForDirective
argument_list|(
name|ArrayRef
operator|<
name|OMPClause
operator|*
operator|>
name|Clauses
argument_list|,
name|Stmt
operator|*
name|AStmt
argument_list|,
name|SourceLocation
name|StartLoc
argument_list|,
name|SourceLocation
name|EndLoc
argument_list|,
name|llvm
operator|::
name|DenseMap
operator|<
name|ValueDecl
operator|*
argument_list|,
name|Expr
operator|*
operator|>
operator|&
name|VarsWithImplicitDSA
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// \brief Called on well-formed '\#pragma omp distribute parallel for simd'
end_comment

begin_comment
comment|/// after parsing of the associated statement.
end_comment

begin_decl_stmt
name|StmtResult
name|ActOnOpenMPDistributeParallelForSimdDirective
argument_list|(
name|ArrayRef
operator|<
name|OMPClause
operator|*
operator|>
name|Clauses
argument_list|,
name|Stmt
operator|*
name|AStmt
argument_list|,
name|SourceLocation
name|StartLoc
argument_list|,
name|SourceLocation
name|EndLoc
argument_list|,
name|llvm
operator|::
name|DenseMap
operator|<
name|ValueDecl
operator|*
argument_list|,
name|Expr
operator|*
operator|>
operator|&
name|VarsWithImplicitDSA
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// \brief Called on well-formed '\#pragma omp distribute simd' after
end_comment

begin_comment
comment|/// parsing of the associated statement.
end_comment

begin_decl_stmt
name|StmtResult
name|ActOnOpenMPDistributeSimdDirective
argument_list|(
name|ArrayRef
operator|<
name|OMPClause
operator|*
operator|>
name|Clauses
argument_list|,
name|Stmt
operator|*
name|AStmt
argument_list|,
name|SourceLocation
name|StartLoc
argument_list|,
name|SourceLocation
name|EndLoc
argument_list|,
name|llvm
operator|::
name|DenseMap
operator|<
name|ValueDecl
operator|*
argument_list|,
name|Expr
operator|*
operator|>
operator|&
name|VarsWithImplicitDSA
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// \brief Called on well-formed '\#pragma omp target parallel for simd' after
end_comment

begin_comment
comment|/// parsing of the associated statement.
end_comment

begin_decl_stmt
name|StmtResult
name|ActOnOpenMPTargetParallelForSimdDirective
argument_list|(
name|ArrayRef
operator|<
name|OMPClause
operator|*
operator|>
name|Clauses
argument_list|,
name|Stmt
operator|*
name|AStmt
argument_list|,
name|SourceLocation
name|StartLoc
argument_list|,
name|SourceLocation
name|EndLoc
argument_list|,
name|llvm
operator|::
name|DenseMap
operator|<
name|ValueDecl
operator|*
argument_list|,
name|Expr
operator|*
operator|>
operator|&
name|VarsWithImplicitDSA
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// \brief Called on well-formed '\#pragma omp target simd' after parsing of
end_comment

begin_comment
comment|/// the associated statement.
end_comment

begin_decl_stmt
name|StmtResult
name|ActOnOpenMPTargetSimdDirective
argument_list|(
name|ArrayRef
operator|<
name|OMPClause
operator|*
operator|>
name|Clauses
argument_list|,
name|Stmt
operator|*
name|AStmt
argument_list|,
name|SourceLocation
name|StartLoc
argument_list|,
name|SourceLocation
name|EndLoc
argument_list|,
name|llvm
operator|::
name|DenseMap
operator|<
name|ValueDecl
operator|*
argument_list|,
name|Expr
operator|*
operator|>
operator|&
name|VarsWithImplicitDSA
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// Called on well-formed '\#pragma omp teams distribute' after parsing of
end_comment

begin_comment
comment|/// the associated statement.
end_comment

begin_decl_stmt
name|StmtResult
name|ActOnOpenMPTeamsDistributeDirective
argument_list|(
name|ArrayRef
operator|<
name|OMPClause
operator|*
operator|>
name|Clauses
argument_list|,
name|Stmt
operator|*
name|AStmt
argument_list|,
name|SourceLocation
name|StartLoc
argument_list|,
name|SourceLocation
name|EndLoc
argument_list|,
name|llvm
operator|::
name|DenseMap
operator|<
name|ValueDecl
operator|*
argument_list|,
name|Expr
operator|*
operator|>
operator|&
name|VarsWithImplicitDSA
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// Called on well-formed '\#pragma omp teams distribute simd' after parsing
end_comment

begin_comment
comment|/// of the associated statement.
end_comment

begin_decl_stmt
name|StmtResult
name|ActOnOpenMPTeamsDistributeSimdDirective
argument_list|(
name|ArrayRef
operator|<
name|OMPClause
operator|*
operator|>
name|Clauses
argument_list|,
name|Stmt
operator|*
name|AStmt
argument_list|,
name|SourceLocation
name|StartLoc
argument_list|,
name|SourceLocation
name|EndLoc
argument_list|,
name|llvm
operator|::
name|DenseMap
operator|<
name|ValueDecl
operator|*
argument_list|,
name|Expr
operator|*
operator|>
operator|&
name|VarsWithImplicitDSA
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// Called on well-formed '\#pragma omp teams distribute parallel for simd'
end_comment

begin_comment
comment|/// after parsing of the associated statement.
end_comment

begin_decl_stmt
name|StmtResult
name|ActOnOpenMPTeamsDistributeParallelForSimdDirective
argument_list|(
name|ArrayRef
operator|<
name|OMPClause
operator|*
operator|>
name|Clauses
argument_list|,
name|Stmt
operator|*
name|AStmt
argument_list|,
name|SourceLocation
name|StartLoc
argument_list|,
name|SourceLocation
name|EndLoc
argument_list|,
name|llvm
operator|::
name|DenseMap
operator|<
name|ValueDecl
operator|*
argument_list|,
name|Expr
operator|*
operator|>
operator|&
name|VarsWithImplicitDSA
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// Called on well-formed '\#pragma omp teams distribute parallel for'
end_comment

begin_comment
comment|/// after parsing of the associated statement.
end_comment

begin_decl_stmt
name|StmtResult
name|ActOnOpenMPTeamsDistributeParallelForDirective
argument_list|(
name|ArrayRef
operator|<
name|OMPClause
operator|*
operator|>
name|Clauses
argument_list|,
name|Stmt
operator|*
name|AStmt
argument_list|,
name|SourceLocation
name|StartLoc
argument_list|,
name|SourceLocation
name|EndLoc
argument_list|,
name|llvm
operator|::
name|DenseMap
operator|<
name|ValueDecl
operator|*
argument_list|,
name|Expr
operator|*
operator|>
operator|&
name|VarsWithImplicitDSA
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// Called on well-formed '\#pragma omp target teams' after parsing of the
end_comment

begin_comment
comment|/// associated statement.
end_comment

begin_decl_stmt
name|StmtResult
name|ActOnOpenMPTargetTeamsDirective
argument_list|(
name|ArrayRef
operator|<
name|OMPClause
operator|*
operator|>
name|Clauses
argument_list|,
name|Stmt
operator|*
name|AStmt
argument_list|,
name|SourceLocation
name|StartLoc
argument_list|,
name|SourceLocation
name|EndLoc
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// Called on well-formed '\#pragma omp target teams distribute' after parsing
end_comment

begin_comment
comment|/// of the associated statement.
end_comment

begin_decl_stmt
name|StmtResult
name|ActOnOpenMPTargetTeamsDistributeDirective
argument_list|(
name|ArrayRef
operator|<
name|OMPClause
operator|*
operator|>
name|Clauses
argument_list|,
name|Stmt
operator|*
name|AStmt
argument_list|,
name|SourceLocation
name|StartLoc
argument_list|,
name|SourceLocation
name|EndLoc
argument_list|,
name|llvm
operator|::
name|DenseMap
operator|<
name|ValueDecl
operator|*
argument_list|,
name|Expr
operator|*
operator|>
operator|&
name|VarsWithImplicitDSA
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// Called on well-formed '\#pragma omp target teams distribute parallel for'
end_comment

begin_comment
comment|/// after parsing of the associated statement.
end_comment

begin_decl_stmt
name|StmtResult
name|ActOnOpenMPTargetTeamsDistributeParallelForDirective
argument_list|(
name|ArrayRef
operator|<
name|OMPClause
operator|*
operator|>
name|Clauses
argument_list|,
name|Stmt
operator|*
name|AStmt
argument_list|,
name|SourceLocation
name|StartLoc
argument_list|,
name|SourceLocation
name|EndLoc
argument_list|,
name|llvm
operator|::
name|DenseMap
operator|<
name|ValueDecl
operator|*
argument_list|,
name|Expr
operator|*
operator|>
operator|&
name|VarsWithImplicitDSA
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// Called on well-formed '\#pragma omp target teams distribute parallel for
end_comment

begin_comment
comment|/// simd' after parsing of the associated statement.
end_comment

begin_decl_stmt
name|StmtResult
name|ActOnOpenMPTargetTeamsDistributeParallelForSimdDirective
argument_list|(
name|ArrayRef
operator|<
name|OMPClause
operator|*
operator|>
name|Clauses
argument_list|,
name|Stmt
operator|*
name|AStmt
argument_list|,
name|SourceLocation
name|StartLoc
argument_list|,
name|SourceLocation
name|EndLoc
argument_list|,
name|llvm
operator|::
name|DenseMap
operator|<
name|ValueDecl
operator|*
argument_list|,
name|Expr
operator|*
operator|>
operator|&
name|VarsWithImplicitDSA
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// Called on well-formed '\#pragma omp target teams distribute simd' after
end_comment

begin_comment
comment|/// parsing of the associated statement.
end_comment

begin_decl_stmt
name|StmtResult
name|ActOnOpenMPTargetTeamsDistributeSimdDirective
argument_list|(
name|ArrayRef
operator|<
name|OMPClause
operator|*
operator|>
name|Clauses
argument_list|,
name|Stmt
operator|*
name|AStmt
argument_list|,
name|SourceLocation
name|StartLoc
argument_list|,
name|SourceLocation
name|EndLoc
argument_list|,
name|llvm
operator|::
name|DenseMap
operator|<
name|ValueDecl
operator|*
argument_list|,
name|Expr
operator|*
operator|>
operator|&
name|VarsWithImplicitDSA
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// Checks correctness of linear modifiers.
end_comment

begin_function_decl
name|bool
name|CheckOpenMPLinearModifier
parameter_list|(
name|OpenMPLinearClauseKind
name|LinKind
parameter_list|,
name|SourceLocation
name|LinLoc
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// Checks that the specified declaration matches requirements for the linear
end_comment

begin_comment
comment|/// decls.
end_comment

begin_function_decl
name|bool
name|CheckOpenMPLinearDecl
parameter_list|(
name|ValueDecl
modifier|*
name|D
parameter_list|,
name|SourceLocation
name|ELoc
parameter_list|,
name|OpenMPLinearClauseKind
name|LinKind
parameter_list|,
name|QualType
name|Type
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// \brief Called on well-formed '\#pragma omp declare simd' after parsing of
end_comment

begin_comment
comment|/// the associated method/function.
end_comment

begin_decl_stmt
name|DeclGroupPtrTy
name|ActOnOpenMPDeclareSimdDirective
argument_list|(
name|DeclGroupPtrTy
name|DG
argument_list|,
name|OMPDeclareSimdDeclAttr
operator|::
name|BranchStateTy
name|BS
argument_list|,
name|Expr
operator|*
name|Simdlen
argument_list|,
name|ArrayRef
operator|<
name|Expr
operator|*
operator|>
name|Uniforms
argument_list|,
name|ArrayRef
operator|<
name|Expr
operator|*
operator|>
name|Aligneds
argument_list|,
name|ArrayRef
operator|<
name|Expr
operator|*
operator|>
name|Alignments
argument_list|,
name|ArrayRef
operator|<
name|Expr
operator|*
operator|>
name|Linears
argument_list|,
name|ArrayRef
operator|<
name|unsigned
operator|>
name|LinModifiers
argument_list|,
name|ArrayRef
operator|<
name|Expr
operator|*
operator|>
name|Steps
argument_list|,
name|SourceRange
name|SR
argument_list|)
decl_stmt|;
end_decl_stmt

begin_function_decl
name|OMPClause
modifier|*
name|ActOnOpenMPSingleExprClause
parameter_list|(
name|OpenMPClauseKind
name|Kind
parameter_list|,
name|Expr
modifier|*
name|Expr
parameter_list|,
name|SourceLocation
name|StartLoc
parameter_list|,
name|SourceLocation
name|LParenLoc
parameter_list|,
name|SourceLocation
name|EndLoc
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// \brief Called on well-formed 'if' clause.
end_comment

begin_function_decl
name|OMPClause
modifier|*
name|ActOnOpenMPIfClause
parameter_list|(
name|OpenMPDirectiveKind
name|NameModifier
parameter_list|,
name|Expr
modifier|*
name|Condition
parameter_list|,
name|SourceLocation
name|StartLoc
parameter_list|,
name|SourceLocation
name|LParenLoc
parameter_list|,
name|SourceLocation
name|NameModifierLoc
parameter_list|,
name|SourceLocation
name|ColonLoc
parameter_list|,
name|SourceLocation
name|EndLoc
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// \brief Called on well-formed 'final' clause.
end_comment

begin_function_decl
name|OMPClause
modifier|*
name|ActOnOpenMPFinalClause
parameter_list|(
name|Expr
modifier|*
name|Condition
parameter_list|,
name|SourceLocation
name|StartLoc
parameter_list|,
name|SourceLocation
name|LParenLoc
parameter_list|,
name|SourceLocation
name|EndLoc
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// \brief Called on well-formed 'num_threads' clause.
end_comment

begin_function_decl
name|OMPClause
modifier|*
name|ActOnOpenMPNumThreadsClause
parameter_list|(
name|Expr
modifier|*
name|NumThreads
parameter_list|,
name|SourceLocation
name|StartLoc
parameter_list|,
name|SourceLocation
name|LParenLoc
parameter_list|,
name|SourceLocation
name|EndLoc
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// \brief Called on well-formed 'safelen' clause.
end_comment

begin_function_decl
name|OMPClause
modifier|*
name|ActOnOpenMPSafelenClause
parameter_list|(
name|Expr
modifier|*
name|Length
parameter_list|,
name|SourceLocation
name|StartLoc
parameter_list|,
name|SourceLocation
name|LParenLoc
parameter_list|,
name|SourceLocation
name|EndLoc
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// \brief Called on well-formed 'simdlen' clause.
end_comment

begin_function_decl
name|OMPClause
modifier|*
name|ActOnOpenMPSimdlenClause
parameter_list|(
name|Expr
modifier|*
name|Length
parameter_list|,
name|SourceLocation
name|StartLoc
parameter_list|,
name|SourceLocation
name|LParenLoc
parameter_list|,
name|SourceLocation
name|EndLoc
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// \brief Called on well-formed 'collapse' clause.
end_comment

begin_function_decl
name|OMPClause
modifier|*
name|ActOnOpenMPCollapseClause
parameter_list|(
name|Expr
modifier|*
name|NumForLoops
parameter_list|,
name|SourceLocation
name|StartLoc
parameter_list|,
name|SourceLocation
name|LParenLoc
parameter_list|,
name|SourceLocation
name|EndLoc
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// \brief Called on well-formed 'ordered' clause.
end_comment

begin_function_decl
name|OMPClause
modifier|*
name|ActOnOpenMPOrderedClause
parameter_list|(
name|SourceLocation
name|StartLoc
parameter_list|,
name|SourceLocation
name|EndLoc
parameter_list|,
name|SourceLocation
name|LParenLoc
init|=
name|SourceLocation
argument_list|()
parameter_list|,
name|Expr
modifier|*
name|NumForLoops
init|=
name|nullptr
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// \brief Called on well-formed 'grainsize' clause.
end_comment

begin_function_decl
name|OMPClause
modifier|*
name|ActOnOpenMPGrainsizeClause
parameter_list|(
name|Expr
modifier|*
name|Size
parameter_list|,
name|SourceLocation
name|StartLoc
parameter_list|,
name|SourceLocation
name|LParenLoc
parameter_list|,
name|SourceLocation
name|EndLoc
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// \brief Called on well-formed 'num_tasks' clause.
end_comment

begin_function_decl
name|OMPClause
modifier|*
name|ActOnOpenMPNumTasksClause
parameter_list|(
name|Expr
modifier|*
name|NumTasks
parameter_list|,
name|SourceLocation
name|StartLoc
parameter_list|,
name|SourceLocation
name|LParenLoc
parameter_list|,
name|SourceLocation
name|EndLoc
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// \brief Called on well-formed 'hint' clause.
end_comment

begin_function_decl
name|OMPClause
modifier|*
name|ActOnOpenMPHintClause
parameter_list|(
name|Expr
modifier|*
name|Hint
parameter_list|,
name|SourceLocation
name|StartLoc
parameter_list|,
name|SourceLocation
name|LParenLoc
parameter_list|,
name|SourceLocation
name|EndLoc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|OMPClause
modifier|*
name|ActOnOpenMPSimpleClause
parameter_list|(
name|OpenMPClauseKind
name|Kind
parameter_list|,
name|unsigned
name|Argument
parameter_list|,
name|SourceLocation
name|ArgumentLoc
parameter_list|,
name|SourceLocation
name|StartLoc
parameter_list|,
name|SourceLocation
name|LParenLoc
parameter_list|,
name|SourceLocation
name|EndLoc
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// \brief Called on well-formed 'default' clause.
end_comment

begin_function_decl
name|OMPClause
modifier|*
name|ActOnOpenMPDefaultClause
parameter_list|(
name|OpenMPDefaultClauseKind
name|Kind
parameter_list|,
name|SourceLocation
name|KindLoc
parameter_list|,
name|SourceLocation
name|StartLoc
parameter_list|,
name|SourceLocation
name|LParenLoc
parameter_list|,
name|SourceLocation
name|EndLoc
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// \brief Called on well-formed 'proc_bind' clause.
end_comment

begin_function_decl
name|OMPClause
modifier|*
name|ActOnOpenMPProcBindClause
parameter_list|(
name|OpenMPProcBindClauseKind
name|Kind
parameter_list|,
name|SourceLocation
name|KindLoc
parameter_list|,
name|SourceLocation
name|StartLoc
parameter_list|,
name|SourceLocation
name|LParenLoc
parameter_list|,
name|SourceLocation
name|EndLoc
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
name|OMPClause
modifier|*
name|ActOnOpenMPSingleExprWithArgClause
argument_list|(
name|OpenMPClauseKind
name|Kind
argument_list|,
name|ArrayRef
operator|<
name|unsigned
operator|>
name|Arguments
argument_list|,
name|Expr
operator|*
name|Expr
argument_list|,
name|SourceLocation
name|StartLoc
argument_list|,
name|SourceLocation
name|LParenLoc
argument_list|,
name|ArrayRef
operator|<
name|SourceLocation
operator|>
name|ArgumentsLoc
argument_list|,
name|SourceLocation
name|DelimLoc
argument_list|,
name|SourceLocation
name|EndLoc
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// \brief Called on well-formed 'schedule' clause.
end_comment

begin_function_decl
name|OMPClause
modifier|*
name|ActOnOpenMPScheduleClause
parameter_list|(
name|OpenMPScheduleClauseModifier
name|M1
parameter_list|,
name|OpenMPScheduleClauseModifier
name|M2
parameter_list|,
name|OpenMPScheduleClauseKind
name|Kind
parameter_list|,
name|Expr
modifier|*
name|ChunkSize
parameter_list|,
name|SourceLocation
name|StartLoc
parameter_list|,
name|SourceLocation
name|LParenLoc
parameter_list|,
name|SourceLocation
name|M1Loc
parameter_list|,
name|SourceLocation
name|M2Loc
parameter_list|,
name|SourceLocation
name|KindLoc
parameter_list|,
name|SourceLocation
name|CommaLoc
parameter_list|,
name|SourceLocation
name|EndLoc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|OMPClause
modifier|*
name|ActOnOpenMPClause
parameter_list|(
name|OpenMPClauseKind
name|Kind
parameter_list|,
name|SourceLocation
name|StartLoc
parameter_list|,
name|SourceLocation
name|EndLoc
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// \brief Called on well-formed 'nowait' clause.
end_comment

begin_function_decl
name|OMPClause
modifier|*
name|ActOnOpenMPNowaitClause
parameter_list|(
name|SourceLocation
name|StartLoc
parameter_list|,
name|SourceLocation
name|EndLoc
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// \brief Called on well-formed 'untied' clause.
end_comment

begin_function_decl
name|OMPClause
modifier|*
name|ActOnOpenMPUntiedClause
parameter_list|(
name|SourceLocation
name|StartLoc
parameter_list|,
name|SourceLocation
name|EndLoc
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// \brief Called on well-formed 'mergeable' clause.
end_comment

begin_function_decl
name|OMPClause
modifier|*
name|ActOnOpenMPMergeableClause
parameter_list|(
name|SourceLocation
name|StartLoc
parameter_list|,
name|SourceLocation
name|EndLoc
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// \brief Called on well-formed 'read' clause.
end_comment

begin_function_decl
name|OMPClause
modifier|*
name|ActOnOpenMPReadClause
parameter_list|(
name|SourceLocation
name|StartLoc
parameter_list|,
name|SourceLocation
name|EndLoc
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// \brief Called on well-formed 'write' clause.
end_comment

begin_function_decl
name|OMPClause
modifier|*
name|ActOnOpenMPWriteClause
parameter_list|(
name|SourceLocation
name|StartLoc
parameter_list|,
name|SourceLocation
name|EndLoc
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// \brief Called on well-formed 'update' clause.
end_comment

begin_function_decl
name|OMPClause
modifier|*
name|ActOnOpenMPUpdateClause
parameter_list|(
name|SourceLocation
name|StartLoc
parameter_list|,
name|SourceLocation
name|EndLoc
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// \brief Called on well-formed 'capture' clause.
end_comment

begin_function_decl
name|OMPClause
modifier|*
name|ActOnOpenMPCaptureClause
parameter_list|(
name|SourceLocation
name|StartLoc
parameter_list|,
name|SourceLocation
name|EndLoc
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// \brief Called on well-formed 'seq_cst' clause.
end_comment

begin_function_decl
name|OMPClause
modifier|*
name|ActOnOpenMPSeqCstClause
parameter_list|(
name|SourceLocation
name|StartLoc
parameter_list|,
name|SourceLocation
name|EndLoc
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// \brief Called on well-formed 'threads' clause.
end_comment

begin_function_decl
name|OMPClause
modifier|*
name|ActOnOpenMPThreadsClause
parameter_list|(
name|SourceLocation
name|StartLoc
parameter_list|,
name|SourceLocation
name|EndLoc
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// \brief Called on well-formed 'simd' clause.
end_comment

begin_function_decl
name|OMPClause
modifier|*
name|ActOnOpenMPSIMDClause
parameter_list|(
name|SourceLocation
name|StartLoc
parameter_list|,
name|SourceLocation
name|EndLoc
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// \brief Called on well-formed 'nogroup' clause.
end_comment

begin_function_decl
name|OMPClause
modifier|*
name|ActOnOpenMPNogroupClause
parameter_list|(
name|SourceLocation
name|StartLoc
parameter_list|,
name|SourceLocation
name|EndLoc
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
name|OMPClause
modifier|*
name|ActOnOpenMPVarListClause
argument_list|(
name|OpenMPClauseKind
name|Kind
argument_list|,
name|ArrayRef
operator|<
name|Expr
operator|*
operator|>
name|Vars
argument_list|,
name|Expr
operator|*
name|TailExpr
argument_list|,
name|SourceLocation
name|StartLoc
argument_list|,
name|SourceLocation
name|LParenLoc
argument_list|,
name|SourceLocation
name|ColonLoc
argument_list|,
name|SourceLocation
name|EndLoc
argument_list|,
name|CXXScopeSpec
operator|&
name|ReductionIdScopeSpec
argument_list|,
specifier|const
name|DeclarationNameInfo
operator|&
name|ReductionId
argument_list|,
name|OpenMPDependClauseKind
name|DepKind
argument_list|,
name|OpenMPLinearClauseKind
name|LinKind
argument_list|,
name|OpenMPMapClauseKind
name|MapTypeModifier
argument_list|,
name|OpenMPMapClauseKind
name|MapType
argument_list|,
name|bool
name|IsMapTypeImplicit
argument_list|,
name|SourceLocation
name|DepLinMapLoc
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// \brief Called on well-formed 'private' clause.
end_comment

begin_decl_stmt
name|OMPClause
modifier|*
name|ActOnOpenMPPrivateClause
argument_list|(
name|ArrayRef
operator|<
name|Expr
operator|*
operator|>
name|VarList
argument_list|,
name|SourceLocation
name|StartLoc
argument_list|,
name|SourceLocation
name|LParenLoc
argument_list|,
name|SourceLocation
name|EndLoc
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// \brief Called on well-formed 'firstprivate' clause.
end_comment

begin_decl_stmt
name|OMPClause
modifier|*
name|ActOnOpenMPFirstprivateClause
argument_list|(
name|ArrayRef
operator|<
name|Expr
operator|*
operator|>
name|VarList
argument_list|,
name|SourceLocation
name|StartLoc
argument_list|,
name|SourceLocation
name|LParenLoc
argument_list|,
name|SourceLocation
name|EndLoc
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// \brief Called on well-formed 'lastprivate' clause.
end_comment

begin_decl_stmt
name|OMPClause
modifier|*
name|ActOnOpenMPLastprivateClause
argument_list|(
name|ArrayRef
operator|<
name|Expr
operator|*
operator|>
name|VarList
argument_list|,
name|SourceLocation
name|StartLoc
argument_list|,
name|SourceLocation
name|LParenLoc
argument_list|,
name|SourceLocation
name|EndLoc
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// \brief Called on well-formed 'shared' clause.
end_comment

begin_decl_stmt
name|OMPClause
modifier|*
name|ActOnOpenMPSharedClause
argument_list|(
name|ArrayRef
operator|<
name|Expr
operator|*
operator|>
name|VarList
argument_list|,
name|SourceLocation
name|StartLoc
argument_list|,
name|SourceLocation
name|LParenLoc
argument_list|,
name|SourceLocation
name|EndLoc
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// \brief Called on well-formed 'reduction' clause.
end_comment

begin_decl_stmt
name|OMPClause
modifier|*
name|ActOnOpenMPReductionClause
argument_list|(
name|ArrayRef
operator|<
name|Expr
operator|*
operator|>
name|VarList
argument_list|,
name|SourceLocation
name|StartLoc
argument_list|,
name|SourceLocation
name|LParenLoc
argument_list|,
name|SourceLocation
name|ColonLoc
argument_list|,
name|SourceLocation
name|EndLoc
argument_list|,
name|CXXScopeSpec
operator|&
name|ReductionIdScopeSpec
argument_list|,
specifier|const
name|DeclarationNameInfo
operator|&
name|ReductionId
argument_list|,
name|ArrayRef
operator|<
name|Expr
operator|*
operator|>
name|UnresolvedReductions
operator|=
name|llvm
operator|::
name|None
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// \brief Called on well-formed 'linear' clause.
end_comment

begin_decl_stmt
name|OMPClause
modifier|*
name|ActOnOpenMPLinearClause
argument_list|(
name|ArrayRef
operator|<
name|Expr
operator|*
operator|>
name|VarList
argument_list|,
name|Expr
operator|*
name|Step
argument_list|,
name|SourceLocation
name|StartLoc
argument_list|,
name|SourceLocation
name|LParenLoc
argument_list|,
name|OpenMPLinearClauseKind
name|LinKind
argument_list|,
name|SourceLocation
name|LinLoc
argument_list|,
name|SourceLocation
name|ColonLoc
argument_list|,
name|SourceLocation
name|EndLoc
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// \brief Called on well-formed 'aligned' clause.
end_comment

begin_decl_stmt
name|OMPClause
modifier|*
name|ActOnOpenMPAlignedClause
argument_list|(
name|ArrayRef
operator|<
name|Expr
operator|*
operator|>
name|VarList
argument_list|,
name|Expr
operator|*
name|Alignment
argument_list|,
name|SourceLocation
name|StartLoc
argument_list|,
name|SourceLocation
name|LParenLoc
argument_list|,
name|SourceLocation
name|ColonLoc
argument_list|,
name|SourceLocation
name|EndLoc
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// \brief Called on well-formed 'copyin' clause.
end_comment

begin_decl_stmt
name|OMPClause
modifier|*
name|ActOnOpenMPCopyinClause
argument_list|(
name|ArrayRef
operator|<
name|Expr
operator|*
operator|>
name|VarList
argument_list|,
name|SourceLocation
name|StartLoc
argument_list|,
name|SourceLocation
name|LParenLoc
argument_list|,
name|SourceLocation
name|EndLoc
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// \brief Called on well-formed 'copyprivate' clause.
end_comment

begin_decl_stmt
name|OMPClause
modifier|*
name|ActOnOpenMPCopyprivateClause
argument_list|(
name|ArrayRef
operator|<
name|Expr
operator|*
operator|>
name|VarList
argument_list|,
name|SourceLocation
name|StartLoc
argument_list|,
name|SourceLocation
name|LParenLoc
argument_list|,
name|SourceLocation
name|EndLoc
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// \brief Called on well-formed 'flush' pseudo clause.
end_comment

begin_decl_stmt
name|OMPClause
modifier|*
name|ActOnOpenMPFlushClause
argument_list|(
name|ArrayRef
operator|<
name|Expr
operator|*
operator|>
name|VarList
argument_list|,
name|SourceLocation
name|StartLoc
argument_list|,
name|SourceLocation
name|LParenLoc
argument_list|,
name|SourceLocation
name|EndLoc
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// \brief Called on well-formed 'depend' clause.
end_comment

begin_decl_stmt
name|OMPClause
modifier|*
name|ActOnOpenMPDependClause
argument_list|(
name|OpenMPDependClauseKind
name|DepKind
argument_list|,
name|SourceLocation
name|DepLoc
argument_list|,
name|SourceLocation
name|ColonLoc
argument_list|,
name|ArrayRef
operator|<
name|Expr
operator|*
operator|>
name|VarList
argument_list|,
name|SourceLocation
name|StartLoc
argument_list|,
name|SourceLocation
name|LParenLoc
argument_list|,
name|SourceLocation
name|EndLoc
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// \brief Called on well-formed 'device' clause.
end_comment

begin_function_decl
name|OMPClause
modifier|*
name|ActOnOpenMPDeviceClause
parameter_list|(
name|Expr
modifier|*
name|Device
parameter_list|,
name|SourceLocation
name|StartLoc
parameter_list|,
name|SourceLocation
name|LParenLoc
parameter_list|,
name|SourceLocation
name|EndLoc
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// \brief Called on well-formed 'map' clause.
end_comment

begin_decl_stmt
name|OMPClause
modifier|*
name|ActOnOpenMPMapClause
argument_list|(
name|OpenMPMapClauseKind
name|MapTypeModifier
argument_list|,
name|OpenMPMapClauseKind
name|MapType
argument_list|,
name|bool
name|IsMapTypeImplicit
argument_list|,
name|SourceLocation
name|MapLoc
argument_list|,
name|SourceLocation
name|ColonLoc
argument_list|,
name|ArrayRef
operator|<
name|Expr
operator|*
operator|>
name|VarList
argument_list|,
name|SourceLocation
name|StartLoc
argument_list|,
name|SourceLocation
name|LParenLoc
argument_list|,
name|SourceLocation
name|EndLoc
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// \brief Called on well-formed 'num_teams' clause.
end_comment

begin_function_decl
name|OMPClause
modifier|*
name|ActOnOpenMPNumTeamsClause
parameter_list|(
name|Expr
modifier|*
name|NumTeams
parameter_list|,
name|SourceLocation
name|StartLoc
parameter_list|,
name|SourceLocation
name|LParenLoc
parameter_list|,
name|SourceLocation
name|EndLoc
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// \brief Called on well-formed 'thread_limit' clause.
end_comment

begin_function_decl
name|OMPClause
modifier|*
name|ActOnOpenMPThreadLimitClause
parameter_list|(
name|Expr
modifier|*
name|ThreadLimit
parameter_list|,
name|SourceLocation
name|StartLoc
parameter_list|,
name|SourceLocation
name|LParenLoc
parameter_list|,
name|SourceLocation
name|EndLoc
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// \brief Called on well-formed 'priority' clause.
end_comment

begin_function_decl
name|OMPClause
modifier|*
name|ActOnOpenMPPriorityClause
parameter_list|(
name|Expr
modifier|*
name|Priority
parameter_list|,
name|SourceLocation
name|StartLoc
parameter_list|,
name|SourceLocation
name|LParenLoc
parameter_list|,
name|SourceLocation
name|EndLoc
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// \brief Called on well-formed 'dist_schedule' clause.
end_comment

begin_function_decl
name|OMPClause
modifier|*
name|ActOnOpenMPDistScheduleClause
parameter_list|(
name|OpenMPDistScheduleClauseKind
name|Kind
parameter_list|,
name|Expr
modifier|*
name|ChunkSize
parameter_list|,
name|SourceLocation
name|StartLoc
parameter_list|,
name|SourceLocation
name|LParenLoc
parameter_list|,
name|SourceLocation
name|KindLoc
parameter_list|,
name|SourceLocation
name|CommaLoc
parameter_list|,
name|SourceLocation
name|EndLoc
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// \brief Called on well-formed 'defaultmap' clause.
end_comment

begin_function_decl
name|OMPClause
modifier|*
name|ActOnOpenMPDefaultmapClause
parameter_list|(
name|OpenMPDefaultmapClauseModifier
name|M
parameter_list|,
name|OpenMPDefaultmapClauseKind
name|Kind
parameter_list|,
name|SourceLocation
name|StartLoc
parameter_list|,
name|SourceLocation
name|LParenLoc
parameter_list|,
name|SourceLocation
name|MLoc
parameter_list|,
name|SourceLocation
name|KindLoc
parameter_list|,
name|SourceLocation
name|EndLoc
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// \brief Called on well-formed 'to' clause.
end_comment

begin_decl_stmt
name|OMPClause
modifier|*
name|ActOnOpenMPToClause
argument_list|(
name|ArrayRef
operator|<
name|Expr
operator|*
operator|>
name|VarList
argument_list|,
name|SourceLocation
name|StartLoc
argument_list|,
name|SourceLocation
name|LParenLoc
argument_list|,
name|SourceLocation
name|EndLoc
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// \brief Called on well-formed 'from' clause.
end_comment

begin_decl_stmt
name|OMPClause
modifier|*
name|ActOnOpenMPFromClause
argument_list|(
name|ArrayRef
operator|<
name|Expr
operator|*
operator|>
name|VarList
argument_list|,
name|SourceLocation
name|StartLoc
argument_list|,
name|SourceLocation
name|LParenLoc
argument_list|,
name|SourceLocation
name|EndLoc
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// Called on well-formed 'use_device_ptr' clause.
end_comment

begin_decl_stmt
name|OMPClause
modifier|*
name|ActOnOpenMPUseDevicePtrClause
argument_list|(
name|ArrayRef
operator|<
name|Expr
operator|*
operator|>
name|VarList
argument_list|,
name|SourceLocation
name|StartLoc
argument_list|,
name|SourceLocation
name|LParenLoc
argument_list|,
name|SourceLocation
name|EndLoc
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// Called on well-formed 'is_device_ptr' clause.
end_comment

begin_decl_stmt
name|OMPClause
modifier|*
name|ActOnOpenMPIsDevicePtrClause
argument_list|(
name|ArrayRef
operator|<
name|Expr
operator|*
operator|>
name|VarList
argument_list|,
name|SourceLocation
name|StartLoc
argument_list|,
name|SourceLocation
name|LParenLoc
argument_list|,
name|SourceLocation
name|EndLoc
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// \brief The kind of conversion being performed.
end_comment

begin_enum
enum|enum
name|CheckedConversionKind
block|{
comment|/// \brief An implicit conversion.
name|CCK_ImplicitConversion
block|,
comment|/// \brief A C-style cast.
name|CCK_CStyleCast
block|,
comment|/// \brief A functional-style cast.
name|CCK_FunctionalCast
block|,
comment|/// \brief A cast other than a C-style cast.
name|CCK_OtherCast
block|}
enum|;
end_enum

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
name|nullptr
parameter_list|,
name|CheckedConversionKind
name|CCK
init|=
name|CCK_ImplicitConversion
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
comment|/// CallExprUnaryConversions - a special case of an unary conversion
end_comment

begin_comment
comment|/// performed on a function designator of a call expression.
end_comment

begin_function_decl
name|ExprResult
name|CallExprUnaryConversions
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
parameter_list|,
name|bool
name|Diagnose
init|=
name|true
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
parameter_list|,
name|bool
name|Diagnose
init|=
name|true
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
comment|/// If \p E is a prvalue denoting an unmaterialized temporary, materialize
end_comment

begin_comment
comment|/// it as an xvalue. In C++98, the result will still be a prvalue, because
end_comment

begin_comment
comment|/// we don't have xvalues there.
end_comment

begin_function_decl
name|ExprResult
name|TemporaryMaterializationConversion
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

begin_function_decl
name|VariadicCallType
name|getVariadicCallType
parameter_list|(
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
name|Fn
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|// Used for determining in which context a type is allowed to be passed to a
end_comment

begin_comment
comment|// vararg function.
end_comment

begin_enum
enum|enum
name|VarArgKind
block|{
name|VAK_Valid
block|,
name|VAK_ValidInCXX11
block|,
name|VAK_Undefined
block|,
name|VAK_MSVCUndefined
block|,
name|VAK_Invalid
block|}
enum|;
end_enum

begin_comment
comment|// Determines which VarArgKind fits an expression.
end_comment

begin_function_decl
name|VarArgKind
name|isValidVarArgType
parameter_list|(
specifier|const
name|QualType
modifier|&
name|Ty
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// Check to see if the given expression is a valid argument to a variadic
end_comment

begin_comment
comment|/// function, issuing a diagnostic if not.
end_comment

begin_function_decl
name|void
name|checkVariadicArgument
parameter_list|(
specifier|const
name|Expr
modifier|*
name|E
parameter_list|,
name|VariadicCallType
name|CT
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// Check to see if a given expression could have '.c_str()' called on it.
end_comment

begin_function_decl
name|bool
name|hasCStrMethod
parameter_list|(
specifier|const
name|Expr
modifier|*
name|E
parameter_list|)
function_decl|;
end_function_decl

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
name|FirstParam
argument_list|,
name|ArrayRef
operator|<
name|Expr
operator|*
operator|>
name|Args
argument_list|,
name|SmallVectorImpl
operator|<
name|Expr
operator|*
operator|>
operator|&
name|AllArgs
argument_list|,
name|VariadicCallType
name|CallType
operator|=
name|VariadicDoesNotApply
argument_list|,
name|bool
name|AllowExplicit
operator|=
name|false
argument_list|,
name|bool
name|IsListInitialization
operator|=
name|false
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|// DefaultVariadicArgumentPromotion - Like DefaultArgumentPromotion, but
end_comment

begin_comment
comment|// will create a runtime trap if the resulting type is not a POD type.
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
name|LHS
parameter_list|,
name|ExprResult
modifier|&
name|RHS
parameter_list|,
name|bool
name|IsCompAssign
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
comment|/// IncompatiblePointerSign - The assignment is between two pointers types
comment|/// which point to integers which have a different sign, but are otherwise
comment|/// identical. This is a subset of the above, but broken out because it's by
comment|/// far the most common case of incompatible pointers.
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
comment|/// IncompatibleObjCWeakRef - Assigning a weak-unavailable object to an
comment|/// object with __weak qualifier.
name|IncompatibleObjCWeakRef
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
name|nullptr
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// IsValueInFlagEnum - Determine if a value is allowed as part of a flag
end_comment

begin_comment
comment|/// enum. If AllowMask is true, then we also allow the complement of a valid
end_comment

begin_comment
comment|/// value, to be used as a mask.
end_comment

begin_decl_stmt
name|bool
name|IsValueInFlagEnum
argument_list|(
specifier|const
name|EnumDecl
operator|*
name|ED
argument_list|,
specifier|const
name|llvm
operator|::
name|APInt
operator|&
name|Val
argument_list|,
name|bool
name|AllowMask
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// DiagnoseAssignmentEnum - Warn if assignment to enum is a constant
end_comment

begin_comment
comment|/// integer not in the range of enum values.
end_comment

begin_function_decl
name|void
name|DiagnoseAssignmentEnum
parameter_list|(
name|QualType
name|DstType
parameter_list|,
name|QualType
name|SrcType
parameter_list|,
name|Expr
modifier|*
name|SrcExpr
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
name|LHSType
parameter_list|,
name|QualType
name|RHSType
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// Check assignment constraints and optionally prepare for a conversion of
end_comment

begin_comment
comment|/// the RHS to the LHS type. The conversion is prepared for if ConvertRHS
end_comment

begin_comment
comment|/// is true.
end_comment

begin_function_decl
name|AssignConvertType
name|CheckAssignmentConstraints
parameter_list|(
name|QualType
name|LHSType
parameter_list|,
name|ExprResult
modifier|&
name|RHS
parameter_list|,
name|CastKind
modifier|&
name|Kind
parameter_list|,
name|bool
name|ConvertRHS
init|=
name|true
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// Check assignment constraints for an assignment of RHS to LHSType.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param LHSType The destination type for the assignment.
end_comment

begin_comment
comment|/// \param RHS The source expression for the assignment.
end_comment

begin_comment
comment|/// \param Diagnose If \c true, diagnostics may be produced when checking
end_comment

begin_comment
comment|///        for assignability. If a diagnostic is produced, \p RHS will be
end_comment

begin_comment
comment|///        set to ExprError(). Note that this function may still return
end_comment

begin_comment
comment|///        without producing a diagnostic, even for an invalid assignment.
end_comment

begin_comment
comment|/// \param DiagnoseCFAudited If \c true, the target is a function parameter
end_comment

begin_comment
comment|///        in an audited Core Foundation API and does not need to be checked
end_comment

begin_comment
comment|///        for ARC retain issues.
end_comment

begin_comment
comment|/// \param ConvertRHS If \c true, \p RHS will be updated to model the
end_comment

begin_comment
comment|///        conversions necessary to perform the assignment. If \c false,
end_comment

begin_comment
comment|///        \p Diagnose must also be \c false.
end_comment

begin_function_decl
name|AssignConvertType
name|CheckSingleAssignmentConstraints
parameter_list|(
name|QualType
name|LHSType
parameter_list|,
name|ExprResult
modifier|&
name|RHS
parameter_list|,
name|bool
name|Diagnose
init|=
name|true
parameter_list|,
name|bool
name|DiagnoseCFAudited
init|=
name|false
parameter_list|,
name|bool
name|ConvertRHS
init|=
name|true
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
name|ArgType
parameter_list|,
name|ExprResult
modifier|&
name|RHS
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
name|CheckedConversionKind
name|CCK
init|=
name|CCK_ImplicitConversion
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
name|CheckedConversionKind
name|CCK
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
name|Loc
parameter_list|,
name|ExprResult
modifier|&
name|LHS
parameter_list|,
name|ExprResult
modifier|&
name|RHS
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|QualType
name|InvalidLogicalVectorOperands
parameter_list|(
name|SourceLocation
name|Loc
parameter_list|,
name|ExprResult
modifier|&
name|LHS
parameter_list|,
name|ExprResult
modifier|&
name|RHS
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
name|LHS
parameter_list|,
name|ExprResult
modifier|&
name|RHS
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
name|LHS
parameter_list|,
name|ExprResult
modifier|&
name|RHS
parameter_list|,
name|SourceLocation
name|Loc
parameter_list|,
name|bool
name|IsCompAssign
parameter_list|,
name|bool
name|IsDivide
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
name|LHS
parameter_list|,
name|ExprResult
modifier|&
name|RHS
parameter_list|,
name|SourceLocation
name|Loc
parameter_list|,
name|bool
name|IsCompAssign
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
name|LHS
parameter_list|,
name|ExprResult
modifier|&
name|RHS
parameter_list|,
name|SourceLocation
name|Loc
parameter_list|,
name|BinaryOperatorKind
name|Opc
parameter_list|,
name|QualType
modifier|*
name|CompLHSTy
init|=
name|nullptr
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
name|LHS
parameter_list|,
name|ExprResult
modifier|&
name|RHS
parameter_list|,
name|SourceLocation
name|Loc
parameter_list|,
name|QualType
modifier|*
name|CompLHSTy
init|=
name|nullptr
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
name|LHS
parameter_list|,
name|ExprResult
modifier|&
name|RHS
parameter_list|,
name|SourceLocation
name|Loc
parameter_list|,
name|BinaryOperatorKind
name|Opc
parameter_list|,
name|bool
name|IsCompAssign
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
name|LHS
parameter_list|,
name|ExprResult
modifier|&
name|RHS
parameter_list|,
name|SourceLocation
name|Loc
parameter_list|,
name|BinaryOperatorKind
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
name|LHS
parameter_list|,
name|ExprResult
modifier|&
name|RHS
parameter_list|,
name|SourceLocation
name|Loc
parameter_list|,
name|BinaryOperatorKind
name|Opc
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
name|LHS
parameter_list|,
name|ExprResult
modifier|&
name|RHS
parameter_list|,
name|SourceLocation
name|Loc
parameter_list|,
name|BinaryOperatorKind
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
name|LHSExpr
parameter_list|,
name|ExprResult
modifier|&
name|RHS
parameter_list|,
name|SourceLocation
name|Loc
parameter_list|,
name|QualType
name|CompoundType
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ExprResult
name|checkPseudoObjectIncDec
parameter_list|(
name|Scope
modifier|*
name|S
parameter_list|,
name|SourceLocation
name|OpLoc
parameter_list|,
name|UnaryOperatorKind
name|Opcode
parameter_list|,
name|Expr
modifier|*
name|Op
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ExprResult
name|checkPseudoObjectAssignment
parameter_list|(
name|Scope
modifier|*
name|S
parameter_list|,
name|SourceLocation
name|OpLoc
parameter_list|,
name|BinaryOperatorKind
name|Opcode
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
name|checkPseudoObjectRValue
parameter_list|(
name|Expr
modifier|*
name|E
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|Expr
modifier|*
name|recreateSyntacticForm
parameter_list|(
name|PseudoObjectExpr
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
name|Cond
parameter_list|,
name|ExprResult
modifier|&
name|LHS
parameter_list|,
name|ExprResult
modifier|&
name|RHS
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
name|QuestionLoc
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
name|ConvertArgs
init|=
name|true
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
name|ConvertArgs
init|=
name|true
parameter_list|)
block|{
name|Expr
modifier|*
name|E1Tmp
init|=
name|E1
operator|.
name|get
argument_list|()
decl_stmt|,
modifier|*
name|E2Tmp
init|=
name|E2
operator|.
name|get
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
name|ConvertArgs
argument_list|)
decl_stmt|;
name|E1
operator|=
name|E1Tmp
expr_stmt|;
name|E2
operator|=
name|E2Tmp
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
name|QuestionLoc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|DiagnoseConditionalForNull
parameter_list|(
name|Expr
modifier|*
name|LHSExpr
parameter_list|,
name|Expr
modifier|*
name|RHSExpr
parameter_list|,
name|SourceLocation
name|QuestionLoc
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
name|void
name|DiagnoseAlwaysNonNullPointer
argument_list|(
name|Expr
operator|*
name|E
argument_list|,
name|Expr
operator|::
name|NullPointerConstantKind
name|NullType
argument_list|,
name|bool
name|IsEqual
argument_list|,
name|SourceRange
name|Range
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// type checking for vector binary operators.
end_comment

begin_function_decl
name|QualType
name|CheckVectorOperands
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
name|Loc
parameter_list|,
name|bool
name|IsCompAssign
parameter_list|,
name|bool
name|AllowBothBool
parameter_list|,
name|bool
name|AllowBoolConversion
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|QualType
name|GetSignedVectorType
parameter_list|(
name|QualType
name|V
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|QualType
name|CheckVectorCompareOperands
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
name|Loc
parameter_list|,
name|bool
name|isRelational
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|QualType
name|CheckVectorLogicalOperands
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
name|Loc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|areLaxCompatibleVectorTypes
parameter_list|(
name|QualType
name|srcType
parameter_list|,
name|QualType
name|destType
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|isLaxVectorConversion
parameter_list|(
name|QualType
name|srcType
parameter_list|,
name|QualType
name|destType
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// type checking declaration initializers (C99 6.7.8)
end_comment

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
comment|/// Ref_Compatible - The two types are reference-compatible.
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
parameter_list|,
name|bool
modifier|&
name|ObjCLifetimeConversion
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ExprResult
name|checkUnknownAnyCast
parameter_list|(
name|SourceRange
name|TypeRange
parameter_list|,
name|QualType
name|CastType
parameter_list|,
name|Expr
modifier|*
name|CastExpr
parameter_list|,
name|CastKind
modifier|&
name|CastKind
parameter_list|,
name|ExprValueKind
modifier|&
name|VK
parameter_list|,
name|CXXCastPath
modifier|&
name|Path
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// \brief Force an expression with unknown-type to an expression of the
end_comment

begin_comment
comment|/// given type.
end_comment

begin_function_decl
name|ExprResult
name|forceUnknownAnyToType
parameter_list|(
name|Expr
modifier|*
name|E
parameter_list|,
name|QualType
name|ToType
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// \brief Type-check an expression that's being passed to an
end_comment

begin_comment
comment|/// __unknown_anytype parameter.
end_comment

begin_function_decl
name|ExprResult
name|checkUnknownAnyArg
parameter_list|(
name|SourceLocation
name|callLoc
parameter_list|,
name|Expr
modifier|*
name|result
parameter_list|,
name|QualType
modifier|&
name|paramType
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
comment|/// \brief Prepare `SplattedExpr` for a vector splat operation, adding
end_comment

begin_comment
comment|/// implicit casts if necessary.
end_comment

begin_function_decl
name|ExprResult
name|prepareVectorSplat
parameter_list|(
name|QualType
name|VectorTy
parameter_list|,
name|Expr
modifier|*
name|SplattedExpr
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
name|DestTy
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

begin_function_decl
name|ExprResult
name|BuildCXXFunctionalCastExpr
parameter_list|(
name|TypeSourceInfo
modifier|*
name|TInfo
parameter_list|,
name|QualType
name|Type
parameter_list|,
name|SourceLocation
name|LParenLoc
parameter_list|,
name|Expr
modifier|*
name|CastExpr
parameter_list|,
name|SourceLocation
name|RParenLoc
parameter_list|)
function_decl|;
end_function_decl

begin_enum
enum|enum
name|ARCConversionResult
block|{
name|ACR_okay
block|,
name|ACR_unbridged
block|,
name|ACR_error
block|}
enum|;
end_enum

begin_comment
comment|/// \brief Checks for invalid conversions and casts between
end_comment

begin_comment
comment|/// retainable pointers and other pointer kinds for ARC and Weak.
end_comment

begin_function_decl
name|ARCConversionResult
name|CheckObjCConversion
parameter_list|(
name|SourceRange
name|castRange
parameter_list|,
name|QualType
name|castType
parameter_list|,
name|Expr
modifier|*
modifier|&
name|op
parameter_list|,
name|CheckedConversionKind
name|CCK
parameter_list|,
name|bool
name|Diagnose
init|=
name|true
parameter_list|,
name|bool
name|DiagnoseCFAudited
init|=
name|false
parameter_list|,
name|BinaryOperatorKind
name|Opc
init|=
name|BO_PtrMemD
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|Expr
modifier|*
name|stripARCUnbridgedCast
parameter_list|(
name|Expr
modifier|*
name|e
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|diagnoseARCUnbridgedCast
parameter_list|(
name|Expr
modifier|*
name|e
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|CheckObjCARCUnavailableWeakConversion
parameter_list|(
name|QualType
name|castType
parameter_list|,
name|QualType
name|ExprType
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// checkRetainCycles - Check whether an Objective-C message send
end_comment

begin_comment
comment|/// might create an obvious retain cycle.
end_comment

begin_function_decl
name|void
name|checkRetainCycles
parameter_list|(
name|ObjCMessageExpr
modifier|*
name|msg
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|checkRetainCycles
parameter_list|(
name|Expr
modifier|*
name|receiver
parameter_list|,
name|Expr
modifier|*
name|argument
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|checkRetainCycles
parameter_list|(
name|VarDecl
modifier|*
name|Var
parameter_list|,
name|Expr
modifier|*
name|Init
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// checkUnsafeAssigns - Check whether +1 expr is being assigned
end_comment

begin_comment
comment|/// to weak/__unsafe_unretained type.
end_comment

begin_function_decl
name|bool
name|checkUnsafeAssigns
parameter_list|(
name|SourceLocation
name|Loc
parameter_list|,
name|QualType
name|LHS
parameter_list|,
name|Expr
modifier|*
name|RHS
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// checkUnsafeExprAssigns - Check whether +1 expr is being assigned
end_comment

begin_comment
comment|/// to weak/__unsafe_unretained expression.
end_comment

begin_function_decl
name|void
name|checkUnsafeExprAssigns
parameter_list|(
name|SourceLocation
name|Loc
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

begin_decl_stmt
name|bool
name|CheckMessageArgumentTypes
argument_list|(
name|QualType
name|ReceiverType
argument_list|,
name|MultiExprArg
name|Args
argument_list|,
name|Selector
name|Sel
argument_list|,
name|ArrayRef
operator|<
name|SourceLocation
operator|>
name|SelectorLocs
argument_list|,
name|ObjCMethodDecl
operator|*
name|Method
argument_list|,
name|bool
name|isClassMessage
argument_list|,
name|bool
name|isSuperMessage
argument_list|,
name|SourceLocation
name|lbrac
argument_list|,
name|SourceLocation
name|rbrac
argument_list|,
name|SourceRange
name|RecRange
argument_list|,
name|QualType
operator|&
name|ReturnType
argument_list|,
name|ExprValueKind
operator|&
name|VK
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// \brief Determine the result of a message send expression based on
end_comment

begin_comment
comment|/// the type of the receiver, the method expected to receive the message,
end_comment

begin_comment
comment|/// and the form of the message send.
end_comment

begin_function_decl
name|QualType
name|getMessageSendResultType
parameter_list|(
name|QualType
name|ReceiverType
parameter_list|,
name|ObjCMethodDecl
modifier|*
name|Method
parameter_list|,
name|bool
name|isClassMessage
parameter_list|,
name|bool
name|isSuperMessage
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// \brief If the given expression involves a message send to a method
end_comment

begin_comment
comment|/// with a related result type, emit a note describing what happened.
end_comment

begin_function_decl
name|void
name|EmitRelatedResultTypeNote
parameter_list|(
specifier|const
name|Expr
modifier|*
name|E
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// \brief Given that we had incompatible pointer types in a return
end_comment

begin_comment
comment|/// statement, check whether we're in a method with a related result
end_comment

begin_comment
comment|/// type, and if so, emit a note describing what happened.
end_comment

begin_function_decl
name|void
name|EmitRelatedResultTypeNoteForReturn
parameter_list|(
name|QualType
name|destType
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
name|class
name|ConditionResult
block|{
name|Decl
modifier|*
name|ConditionVar
decl_stmt|;
name|FullExprArg
name|Condition
decl_stmt|;
name|bool
name|Invalid
decl_stmt|;
name|bool
name|HasKnownValue
decl_stmt|;
name|bool
name|KnownValue
decl_stmt|;
name|friend
name|class
name|Sema
decl_stmt|;
name|ConditionResult
argument_list|(
argument|Sema&S
argument_list|,
argument|Decl *ConditionVar
argument_list|,
argument|FullExprArg Condition
argument_list|,
argument|bool IsConstexpr
argument_list|)
block|:
name|ConditionVar
argument_list|(
name|ConditionVar
argument_list|)
operator|,
name|Condition
argument_list|(
name|Condition
argument_list|)
operator|,
name|Invalid
argument_list|(
name|false
argument_list|)
operator|,
name|HasKnownValue
argument_list|(
name|IsConstexpr
operator|&&
name|Condition
operator|.
name|get
argument_list|()
operator|&&
operator|!
name|Condition
operator|.
name|get
argument_list|()
operator|->
name|isValueDependent
argument_list|()
argument_list|)
operator|,
name|KnownValue
argument_list|(
argument|HasKnownValue&&                      !!Condition.get()->EvaluateKnownConstInt(S.Context)
argument_list|)
block|{}
name|explicit
name|ConditionResult
argument_list|(
argument|bool Invalid
argument_list|)
operator|:
name|ConditionVar
argument_list|(
name|nullptr
argument_list|)
operator|,
name|Condition
argument_list|(
name|nullptr
argument_list|)
operator|,
name|Invalid
argument_list|(
name|Invalid
argument_list|)
operator|,
name|HasKnownValue
argument_list|(
name|false
argument_list|)
operator|,
name|KnownValue
argument_list|(
argument|false
argument_list|)
block|{}
name|public
operator|:
name|ConditionResult
argument_list|()
operator|:
name|ConditionResult
argument_list|(
argument|false
argument_list|)
block|{}
name|bool
name|isInvalid
argument_list|()
specifier|const
block|{
return|return
name|Invalid
return|;
block|}
name|std
operator|::
name|pair
operator|<
name|VarDecl
operator|*
operator|,
name|Expr
operator|*
operator|>
name|get
argument_list|()
specifier|const
block|{
return|return
name|std
operator|::
name|make_pair
argument_list|(
name|cast_or_null
operator|<
name|VarDecl
operator|>
operator|(
name|ConditionVar
operator|)
argument_list|,
name|Condition
operator|.
name|get
argument_list|()
argument_list|)
return|;
block|}
name|llvm
operator|::
name|Optional
operator|<
name|bool
operator|>
name|getKnownValue
argument_list|()
specifier|const
block|{
if|if
condition|(
operator|!
name|HasKnownValue
condition|)
return|return
name|None
return|;
return|return
name|KnownValue
return|;
block|}
end_decl_stmt

begin_function
unit|};
specifier|static
name|ConditionResult
name|ConditionError
parameter_list|()
block|{
return|return
name|ConditionResult
argument_list|(
name|true
argument_list|)
return|;
block|}
end_function

begin_decl_stmt
name|enum
name|class
name|ConditionKind
block|{
name|Boolean
operator|,
comment|///< A boolean condition, from 'if', 'while', 'for', or 'do'.
name|ConstexprIf
operator|,
comment|///< A constant boolean condition from 'if constexpr'.
name|Switch
comment|///< An integral condition for a 'switch' statement.
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_function_decl
name|ConditionResult
name|ActOnCondition
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
parameter_list|,
name|ConditionKind
name|CK
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ConditionResult
name|ActOnConditionVariable
parameter_list|(
name|Decl
modifier|*
name|ConditionVar
parameter_list|,
name|SourceLocation
name|StmtLoc
parameter_list|,
name|ConditionKind
name|CK
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
name|ConditionKind
name|CK
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ExprResult
name|CheckSwitchCondition
parameter_list|(
name|SourceLocation
name|SwitchLoc
parameter_list|,
name|Expr
modifier|*
name|Cond
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
name|SourceLocation
name|Loc
parameter_list|,
name|Expr
modifier|*
name|E
parameter_list|,
name|bool
name|IsConstexpr
init|=
name|false
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
name|ParenE
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
parameter_list|,
name|bool
name|IsConstexpr
init|=
name|false
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
comment|/// \brief Abstract base class used for diagnosing integer constant
end_comment

begin_comment
comment|/// expression violations.
end_comment

begin_decl_stmt
name|class
name|VerifyICEDiagnoser
block|{
name|public
label|:
name|bool
name|Suppress
decl_stmt|;
name|VerifyICEDiagnoser
argument_list|(
argument|bool Suppress = false
argument_list|)
block|:
name|Suppress
argument_list|(
argument|Suppress
argument_list|)
block|{ }
name|virtual
name|void
name|diagnoseNotICE
parameter_list|(
name|Sema
modifier|&
name|S
parameter_list|,
name|SourceLocation
name|Loc
parameter_list|,
name|SourceRange
name|SR
parameter_list|)
init|=
literal|0
function_decl|;
name|virtual
name|void
name|diagnoseFold
parameter_list|(
name|Sema
modifier|&
name|S
parameter_list|,
name|SourceLocation
name|Loc
parameter_list|,
name|SourceRange
name|SR
parameter_list|)
function_decl|;
name|virtual
operator|~
name|VerifyICEDiagnoser
argument_list|()
block|{ }
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|/// VerifyIntegerConstantExpression - Verifies that an expression is an ICE,
end_comment

begin_comment
comment|/// and reports the appropriate diagnostics. Returns false on success.
end_comment

begin_comment
comment|/// Can optionally return the value of the expression.
end_comment

begin_decl_stmt
name|ExprResult
name|VerifyIntegerConstantExpression
argument_list|(
name|Expr
operator|*
name|E
argument_list|,
name|llvm
operator|::
name|APSInt
operator|*
name|Result
argument_list|,
name|VerifyICEDiagnoser
operator|&
name|Diagnoser
argument_list|,
name|bool
name|AllowFold
operator|=
name|true
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|ExprResult
name|VerifyIntegerConstantExpression
argument_list|(
name|Expr
operator|*
name|E
argument_list|,
name|llvm
operator|::
name|APSInt
operator|*
name|Result
argument_list|,
name|unsigned
name|DiagID
argument_list|,
name|bool
name|AllowFold
operator|=
name|true
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|ExprResult
name|VerifyIntegerConstantExpression
argument_list|(
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
name|nullptr
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
name|ExprResult
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
name|bool
name|IsMsStruct
parameter_list|,
name|Expr
modifier|*
name|BitWidth
parameter_list|,
name|bool
modifier|*
name|ZeroWidth
init|=
name|nullptr
parameter_list|)
function_decl|;
end_function_decl

begin_label
name|private
label|:
end_label

begin_decl_stmt
name|unsigned
name|ForceCUDAHostDeviceDepth
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_label
name|public
label|:
end_label

begin_comment
comment|/// Increments our count of the number of times we've seen a pragma forcing
end_comment

begin_comment
comment|/// functions to be __host__ __device__.  So long as this count is greater
end_comment

begin_comment
comment|/// than zero, all functions encountered will be __host__ __device__.
end_comment

begin_function_decl
name|void
name|PushForceCUDAHostDevice
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/// Decrements our count of the number of times we've seen a pragma forcing
end_comment

begin_comment
comment|/// functions to be __host__ __device__.  Returns false if the count is 0
end_comment

begin_comment
comment|/// before incrementing, so you can emit an error.
end_comment

begin_function_decl
name|bool
name|PopForceCUDAHostDevice
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/// Diagnostics that are emitted only if we discover that the given function
end_comment

begin_comment
comment|/// must be codegen'ed.  Because handling these correctly adds overhead to
end_comment

begin_comment
comment|/// compilation, this is currently only enabled for CUDA compilations.
end_comment

begin_expr_stmt
name|llvm
operator|::
name|DenseMap
operator|<
name|CanonicalDeclPtr
operator|<
name|FunctionDecl
operator|>
operator|,
name|std
operator|::
name|vector
operator|<
name|PartialDiagnosticAt
operator|>>
name|CUDADeferredDiags
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// A pair of a canonical FunctionDecl and a SourceLocation.  When used as the
end_comment

begin_comment
comment|/// key in a hashtable, both the FD and location are hashed.
end_comment

begin_struct
struct|struct
name|FunctionDeclAndLoc
block|{
name|CanonicalDeclPtr
operator|<
name|FunctionDecl
operator|>
name|FD
expr_stmt|;
name|SourceLocation
name|Loc
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/// FunctionDecls and SourceLocations for which CheckCUDACall has emitted a
end_comment

begin_comment
comment|/// (maybe deferred) "bad call" diagnostic.  We use this to avoid emitting the
end_comment

begin_comment
comment|/// same deferred diag twice.
end_comment

begin_expr_stmt
name|llvm
operator|::
name|DenseSet
operator|<
name|FunctionDeclAndLoc
operator|>
name|LocsWithCUDACallDiags
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// An inverse call graph, mapping known-emitted functions to one of their
end_comment

begin_comment
comment|/// known-emitted callers (plus the location of the call).
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Functions that we can tell a priori must be emitted aren't added to this
end_comment

begin_comment
comment|/// map.
end_comment

begin_expr_stmt
name|llvm
operator|::
name|DenseMap
operator|<
comment|/* Callee = */
name|CanonicalDeclPtr
operator|<
name|FunctionDecl
operator|>
operator|,
comment|/* Caller = */
name|FunctionDeclAndLoc
operator|>
name|CUDAKnownEmittedFns
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// A partial call graph maintained during CUDA compilation to support
end_comment

begin_comment
comment|/// deferred diagnostics.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Functions are only added here if, at the time they're considered, they are
end_comment

begin_comment
comment|/// not known-emitted.  As soon as we discover that a function is
end_comment

begin_comment
comment|/// known-emitted, we remove it and everything it transitively calls from this
end_comment

begin_comment
comment|/// set and add those functions to CUDAKnownEmittedFns.
end_comment

begin_expr_stmt
name|llvm
operator|::
name|DenseMap
operator|<
comment|/* Caller = */
name|CanonicalDeclPtr
operator|<
name|FunctionDecl
operator|>
operator|,
comment|/* Callees = */
name|llvm
operator|::
name|MapVector
operator|<
name|CanonicalDeclPtr
operator|<
name|FunctionDecl
operator|>
operator|,
name|SourceLocation
operator|>>
name|CUDACallGraph
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// Diagnostic builder for CUDA errors which may or may not be deferred.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// In CUDA, there exist constructs (e.g. variable-length arrays, try/catch)
end_comment

begin_comment
comment|/// which are not allowed to appear inside __device__ functions and are
end_comment

begin_comment
comment|/// allowed to appear in __host__ __device__ functions only if the host+device
end_comment

begin_comment
comment|/// function is never codegen'ed.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// To handle this, we use the notion of "deferred diagnostics", where we
end_comment

begin_comment
comment|/// attach a diagnostic to a FunctionDecl that's emitted iff it's codegen'ed.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This class lets you emit either a regular diagnostic, a deferred
end_comment

begin_comment
comment|/// diagnostic, or no diagnostic at all, according to an argument you pass to
end_comment

begin_comment
comment|/// its constructor, thus simplifying the process of creating these "maybe
end_comment

begin_comment
comment|/// deferred" diagnostics.
end_comment

begin_decl_stmt
name|class
name|CUDADiagBuilder
block|{
name|public
label|:
enum|enum
name|Kind
block|{
comment|/// Emit no diagnostics.
name|K_Nop
block|,
comment|/// Emit the diagnostic immediately (i.e., behave like Sema::Diag()).
name|K_Immediate
block|,
comment|/// Emit the diagnostic immediately, and, if it's a warning or error, also
comment|/// emit a call stack showing how this function can be reached by an a
comment|/// priori known-emitted function.
name|K_ImmediateWithCallStack
block|,
comment|/// Create a deferred diagnostic, which is emitted only if the function
comment|/// it's attached to is codegen'ed.  Also emit a call stack as with
comment|/// K_ImmediateWithCallStack.
name|K_Deferred
block|}
enum|;
name|CUDADiagBuilder
argument_list|(
argument|Kind K
argument_list|,
argument|SourceLocation Loc
argument_list|,
argument|unsigned DiagID
argument_list|,
argument|FunctionDecl *Fn
argument_list|,
argument|Sema&S
argument_list|)
empty_stmt|;
operator|~
name|CUDADiagBuilder
argument_list|()
expr_stmt|;
comment|/// Convertible to bool: True if we immediately emitted an error, false if
comment|/// we didn't emit an error or we created a deferred error.
comment|///
comment|/// Example usage:
comment|///
comment|///   if (CUDADiagBuilder(...)<< foo<< bar)
comment|///     return ExprError();
comment|///
comment|/// But see CUDADiagIfDeviceCode() and CUDADiagIfHostCode() -- you probably
comment|/// want to use these instead of creating a CUDADiagBuilder yourself.
name|operator
name|bool
argument_list|()
specifier|const
block|{
return|return
name|ImmediateDiag
operator|.
name|hasValue
argument_list|()
return|;
block|}
name|template
operator|<
name|typename
name|T
operator|>
name|friend
specifier|const
name|CUDADiagBuilder
operator|&
name|operator
operator|<<
operator|(
specifier|const
name|CUDADiagBuilder
operator|&
name|Diag
operator|,
specifier|const
name|T
operator|&
name|Value
operator|)
block|{
if|if
condition|(
name|Diag
operator|.
name|ImmediateDiag
operator|.
name|hasValue
argument_list|()
condition|)
operator|*
name|Diag
operator|.
name|ImmediateDiag
operator|<<
name|Value
expr_stmt|;
elseif|else
if|if
condition|(
name|Diag
operator|.
name|PartialDiag
operator|.
name|hasValue
argument_list|()
condition|)
operator|*
name|Diag
operator|.
name|PartialDiag
operator|<<
name|Value
expr_stmt|;
return|return
name|Diag
return|;
block|}
end_decl_stmt

begin_label
name|private
label|:
end_label

begin_decl_stmt
name|Sema
modifier|&
name|S
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|SourceLocation
name|Loc
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|unsigned
name|DiagID
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|FunctionDecl
modifier|*
name|Fn
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|bool
name|ShowCallStack
decl_stmt|;
end_decl_stmt

begin_comment
comment|// Invariant: At most one of these Optionals has a value.
end_comment

begin_comment
comment|// FIXME: Switch these to a Variant once that exists.
end_comment

begin_expr_stmt
name|llvm
operator|::
name|Optional
operator|<
name|SemaDiagnosticBuilder
operator|>
name|ImmediateDiag
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|llvm
operator|::
name|Optional
operator|<
name|PartialDiagnostic
operator|>
name|PartialDiag
expr_stmt|;
end_expr_stmt

begin_comment
unit|};
comment|/// Creates a CUDADiagBuilder that emits the diagnostic if the current context
end_comment

begin_comment
comment|/// is "used as device code".
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// - If CurContext is a __host__ function, does not emit any diagnostics.
end_comment

begin_comment
comment|/// - If CurContext is a __device__ or __global__ function, emits the
end_comment

begin_comment
comment|///   diagnostics immediately.
end_comment

begin_comment
comment|/// - If CurContext is a __host__ __device__ function and we are compiling for
end_comment

begin_comment
comment|///   the device, creates a diagnostic which is emitted if and when we realize
end_comment

begin_comment
comment|///   that the function will be codegen'ed.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Example usage:
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|///  // Variable-length arrays are not allowed in CUDA device code.
end_comment

begin_comment
comment|///  if (CUDADiagIfDeviceCode(Loc, diag::err_cuda_vla)<< CurrentCUDATarget())
end_comment

begin_comment
comment|///    return ExprError();
end_comment

begin_comment
comment|///  // Otherwise, continue parsing as normal.
end_comment

begin_function_decl
name|CUDADiagBuilder
name|CUDADiagIfDeviceCode
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
comment|/// Creates a CUDADiagBuilder that emits the diagnostic if the current context
end_comment

begin_comment
comment|/// is "used as host code".
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Same as CUDADiagIfDeviceCode, with "host" and "device" switched.
end_comment

begin_function_decl
name|CUDADiagBuilder
name|CUDADiagIfHostCode
parameter_list|(
name|SourceLocation
name|Loc
parameter_list|,
name|unsigned
name|DiagID
parameter_list|)
function_decl|;
end_function_decl

begin_enum
enum|enum
name|CUDAFunctionTarget
block|{
name|CFT_Device
block|,
name|CFT_Global
block|,
name|CFT_Host
block|,
name|CFT_HostDevice
block|,
name|CFT_InvalidTarget
block|}
enum|;
end_enum

begin_comment
comment|/// Determines whether the given function is a CUDA device/host/kernel/etc.
end_comment

begin_comment
comment|/// function.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Use this rather than examining the function's attributes yourself -- you
end_comment

begin_comment
comment|/// will get it wrong.  Returns CFT_Host if D is null.
end_comment

begin_function_decl
name|CUDAFunctionTarget
name|IdentifyCUDATarget
parameter_list|(
specifier|const
name|FunctionDecl
modifier|*
name|D
parameter_list|,
name|bool
name|IgnoreImplicitHDAttr
init|=
name|false
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|CUDAFunctionTarget
name|IdentifyCUDATarget
parameter_list|(
specifier|const
name|AttributeList
modifier|*
name|Attr
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// Gets the CUDA target for the current context.
end_comment

begin_function
name|CUDAFunctionTarget
name|CurrentCUDATarget
parameter_list|()
block|{
return|return
name|IdentifyCUDATarget
argument_list|(
name|dyn_cast
operator|<
name|FunctionDecl
operator|>
operator|(
name|CurContext
operator|)
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CUDA function call preference. Must be ordered numerically from
end_comment

begin_comment
comment|// worst to best.
end_comment

begin_enum
enum|enum
name|CUDAFunctionPreference
block|{
name|CFP_Never
block|,
comment|// Invalid caller/callee combination.
name|CFP_WrongSide
block|,
comment|// Calls from host-device to host or device
comment|// function that do not match current compilation
comment|// mode.
name|CFP_HostDevice
block|,
comment|// Any calls to host/device functions.
name|CFP_SameSide
block|,
comment|// Calls from host-device to host or device
comment|// function matching current compilation mode.
name|CFP_Native
block|,
comment|// host-to-host or device-to-device calls.
block|}
enum|;
end_enum

begin_comment
comment|/// Identifies relative preference of a given Caller/Callee
end_comment

begin_comment
comment|/// combination, based on their host/device attributes.
end_comment

begin_comment
comment|/// \param Caller function which needs address of \p Callee.
end_comment

begin_comment
comment|///               nullptr in case of global context.
end_comment

begin_comment
comment|/// \param Callee target function
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \returns preference value for particular Caller/Callee combination.
end_comment

begin_function_decl
name|CUDAFunctionPreference
name|IdentifyCUDAPreference
parameter_list|(
specifier|const
name|FunctionDecl
modifier|*
name|Caller
parameter_list|,
specifier|const
name|FunctionDecl
modifier|*
name|Callee
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// Determines whether Caller may invoke Callee, based on their CUDA
end_comment

begin_comment
comment|/// host/device attributes.  Returns false if the call is not allowed.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Note: Will return true for CFP_WrongSide calls.  These may appear in
end_comment

begin_comment
comment|/// semantically correct CUDA programs, but only if they're never codegen'ed.
end_comment

begin_function
name|bool
name|IsAllowedCUDACall
parameter_list|(
specifier|const
name|FunctionDecl
modifier|*
name|Caller
parameter_list|,
specifier|const
name|FunctionDecl
modifier|*
name|Callee
parameter_list|)
block|{
return|return
name|IdentifyCUDAPreference
argument_list|(
name|Caller
argument_list|,
name|Callee
argument_list|)
operator|!=
name|CFP_Never
return|;
block|}
end_function

begin_comment
comment|/// May add implicit CUDAHostAttr and CUDADeviceAttr attributes to FD,
end_comment

begin_comment
comment|/// depending on FD and the current compilation settings.
end_comment

begin_function_decl
name|void
name|maybeAddCUDAHostDeviceAttrs
parameter_list|(
name|FunctionDecl
modifier|*
name|FD
parameter_list|,
specifier|const
name|LookupResult
modifier|&
name|Previous
parameter_list|)
function_decl|;
end_function_decl

begin_label
name|public
label|:
end_label

begin_comment
comment|/// Check whether we're allowed to call Callee from the current context.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// - If the call is never allowed in a semantically-correct program
end_comment

begin_comment
comment|///   (CFP_Never), emits an error and returns false.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// - If the call is allowed in semantically-correct programs, but only if
end_comment

begin_comment
comment|///   it's never codegen'ed (CFP_WrongSide), creates a deferred diagnostic to
end_comment

begin_comment
comment|///   be emitted if and when the caller is codegen'ed, and returns true.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|///   Will only create deferred diagnostics for a given SourceLocation once,
end_comment

begin_comment
comment|///   so you can safely call this multiple times without generating duplicate
end_comment

begin_comment
comment|///   deferred errors.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// - Otherwise, returns true without emitting any diagnostics.
end_comment

begin_function_decl
name|bool
name|CheckCUDACall
parameter_list|(
name|SourceLocation
name|Loc
parameter_list|,
name|FunctionDecl
modifier|*
name|Callee
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// Set __device__ or __host__ __device__ attributes on the given lambda
end_comment

begin_comment
comment|/// operator() method.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// CUDA lambdas declared inside __device__ or __global__ functions inherit
end_comment

begin_comment
comment|/// the __device__ attribute.  Similarly, lambdas inside __host__ __device__
end_comment

begin_comment
comment|/// functions become __host__ __device__ themselves.
end_comment

begin_function_decl
name|void
name|CUDASetLambdaAttrs
parameter_list|(
name|CXXMethodDecl
modifier|*
name|Method
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// Finds a function in \p Matches with highest calling priority
end_comment

begin_comment
comment|/// from \p Caller context and erases all functions with lower
end_comment

begin_comment
comment|/// calling priority.
end_comment

begin_decl_stmt
name|void
name|EraseUnwantedCUDAMatches
argument_list|(
specifier|const
name|FunctionDecl
operator|*
name|Caller
argument_list|,
name|SmallVectorImpl
operator|<
name|std
operator|::
name|pair
operator|<
name|DeclAccessPair
argument_list|,
name|FunctionDecl
operator|*
operator|>>
operator|&
name|Matches
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// Given a implicit special member, infer its CUDA target from the
end_comment

begin_comment
comment|/// calls it needs to make to underlying base/field special members.
end_comment

begin_comment
comment|/// \param ClassDecl the class for which the member is being created.
end_comment

begin_comment
comment|/// \param CSM the kind of special member.
end_comment

begin_comment
comment|/// \param MemberDecl the special member itself.
end_comment

begin_comment
comment|/// \param ConstRHS true if this is a copy operation with a const object on
end_comment

begin_comment
comment|///        its RHS.
end_comment

begin_comment
comment|/// \param Diagnose true if this call should emit diagnostics.
end_comment

begin_comment
comment|/// \return true if there was an error inferring.
end_comment

begin_comment
comment|/// The result of this call is implicit CUDA target attribute(s) attached to
end_comment

begin_comment
comment|/// the member declaration.
end_comment

begin_function_decl
name|bool
name|inferCUDATargetForImplicitSpecialMember
parameter_list|(
name|CXXRecordDecl
modifier|*
name|ClassDecl
parameter_list|,
name|CXXSpecialMember
name|CSM
parameter_list|,
name|CXXMethodDecl
modifier|*
name|MemberDecl
parameter_list|,
name|bool
name|ConstRHS
parameter_list|,
name|bool
name|Diagnose
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// \return true if \p CD can be considered empty according to CUDA
end_comment

begin_comment
comment|/// (E.2.3.1 in CUDA 7.5 Programming guide).
end_comment

begin_function_decl
name|bool
name|isEmptyCudaConstructor
parameter_list|(
name|SourceLocation
name|Loc
parameter_list|,
name|CXXConstructorDecl
modifier|*
name|CD
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|isEmptyCudaDestructor
parameter_list|(
name|SourceLocation
name|Loc
parameter_list|,
name|CXXDestructorDecl
modifier|*
name|CD
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// Check whether NewFD is a valid overload for CUDA. Emits
end_comment

begin_comment
comment|/// diagnostics and invalidates NewFD if not.
end_comment

begin_function_decl
name|void
name|checkCUDATargetOverload
parameter_list|(
name|FunctionDecl
modifier|*
name|NewFD
parameter_list|,
specifier|const
name|LookupResult
modifier|&
name|Previous
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// Copies target attributes from the template TD to the function FD.
end_comment

begin_function_decl
name|void
name|inheritCUDATargetAttrs
parameter_list|(
name|FunctionDecl
modifier|*
name|FD
parameter_list|,
specifier|const
name|FunctionTemplateDecl
modifier|&
name|TD
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
name|CodeCompleteModuleImport
parameter_list|(
name|SourceLocation
name|ImportLoc
parameter_list|,
name|ModuleIdPath
name|Path
parameter_list|)
function_decl|;
end_function_decl

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
parameter_list|,
name|bool
name|IsBaseExprStatement
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
name|CodeCompleteFunctionQualifiers
parameter_list|(
name|DeclSpec
modifier|&
name|DS
parameter_list|,
name|Declarator
modifier|&
name|D
parameter_list|,
specifier|const
name|VirtSpecifiers
modifier|*
name|VS
init|=
name|nullptr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|CodeCompleteBracketDeclarator
parameter_list|(
name|Scope
modifier|*
name|S
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

begin_decl_stmt
name|void
name|CodeCompleteCall
argument_list|(
name|Scope
operator|*
name|S
argument_list|,
name|Expr
operator|*
name|Fn
argument_list|,
name|ArrayRef
operator|<
name|Expr
operator|*
operator|>
name|Args
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|CodeCompleteConstructor
argument_list|(
name|Scope
operator|*
name|S
argument_list|,
name|QualType
name|Type
argument_list|,
name|SourceLocation
name|Loc
argument_list|,
name|ArrayRef
operator|<
name|Expr
operator|*
operator|>
name|Args
argument_list|)
decl_stmt|;
end_decl_stmt

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
name|CodeCompleteAfterIf
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

begin_decl_stmt
name|void
name|CodeCompleteConstructorInitializer
argument_list|(
name|Decl
operator|*
name|Constructor
argument_list|,
name|ArrayRef
operator|<
name|CXXCtorInitializer
operator|*
operator|>
name|Initializers
argument_list|)
decl_stmt|;
end_decl_stmt

begin_function_decl
name|void
name|CodeCompleteLambdaIntroducer
parameter_list|(
name|Scope
modifier|*
name|S
parameter_list|,
name|LambdaIntroducer
modifier|&
name|Intro
parameter_list|,
name|bool
name|AfterAmpersand
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

begin_decl_stmt
name|void
name|CodeCompleteObjCSuperMessage
argument_list|(
name|Scope
operator|*
name|S
argument_list|,
name|SourceLocation
name|SuperLoc
argument_list|,
name|ArrayRef
operator|<
name|IdentifierInfo
operator|*
operator|>
name|SelIdents
argument_list|,
name|bool
name|AtArgumentExpression
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|CodeCompleteObjCClassMessage
argument_list|(
name|Scope
operator|*
name|S
argument_list|,
name|ParsedType
name|Receiver
argument_list|,
name|ArrayRef
operator|<
name|IdentifierInfo
operator|*
operator|>
name|SelIdents
argument_list|,
name|bool
name|AtArgumentExpression
argument_list|,
name|bool
name|IsSuper
operator|=
name|false
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|CodeCompleteObjCInstanceMessage
argument_list|(
name|Scope
operator|*
name|S
argument_list|,
name|Expr
operator|*
name|Receiver
argument_list|,
name|ArrayRef
operator|<
name|IdentifierInfo
operator|*
operator|>
name|SelIdents
argument_list|,
name|bool
name|AtArgumentExpression
argument_list|,
name|ObjCInterfaceDecl
operator|*
name|Super
operator|=
name|nullptr
argument_list|)
decl_stmt|;
end_decl_stmt

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

begin_decl_stmt
name|void
name|CodeCompleteObjCSelector
argument_list|(
name|Scope
operator|*
name|S
argument_list|,
name|ArrayRef
operator|<
name|IdentifierInfo
operator|*
operator|>
name|SelIdents
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|CodeCompleteObjCProtocolReferences
argument_list|(
name|ArrayRef
operator|<
name|IdentifierLocPair
operator|>
name|Protocols
argument_list|)
decl_stmt|;
end_decl_stmt

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
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
name|void
name|CodeCompleteObjCMethodDeclSelector
argument_list|(
name|Scope
operator|*
name|S
argument_list|,
name|bool
name|IsInstanceMethod
argument_list|,
name|bool
name|AtParameterName
argument_list|,
name|ParsedType
name|ReturnType
argument_list|,
name|ArrayRef
operator|<
name|IdentifierInfo
operator|*
operator|>
name|SelIdents
argument_list|)
decl_stmt|;
end_decl_stmt

begin_function_decl
name|void
name|CodeCompleteObjCClassPropertyRefExpr
parameter_list|(
name|Scope
modifier|*
name|S
parameter_list|,
name|IdentifierInfo
modifier|&
name|ClassName
parameter_list|,
name|SourceLocation
name|ClassNameLoc
parameter_list|,
name|bool
name|IsBaseExprStatement
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

begin_function_decl
name|void
name|CodeCompleteAvailabilityPlatformName
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
name|CodeCompletionTUInfo
operator|&
name|CCTUInfo
argument_list|,
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
name|void
name|CheckArrayAccess
parameter_list|(
specifier|const
name|Expr
modifier|*
name|BaseExpr
parameter_list|,
specifier|const
name|Expr
modifier|*
name|IndexExpr
parameter_list|,
specifier|const
name|ArraySubscriptExpr
modifier|*
name|ASE
init|=
name|nullptr
parameter_list|,
name|bool
name|AllowOnePastEnd
init|=
name|true
parameter_list|,
name|bool
name|IndexNegated
init|=
name|false
parameter_list|)
function_decl|;
end_function_decl

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

begin_comment
comment|// Used to grab the relevant information from a FormatAttr and a
end_comment

begin_comment
comment|// FunctionDeclaration.
end_comment

begin_struct
struct|struct
name|FormatStringInfo
block|{
name|unsigned
name|FormatIdx
decl_stmt|;
name|unsigned
name|FirstDataArg
decl_stmt|;
name|bool
name|HasVAListArg
decl_stmt|;
block|}
struct|;
end_struct

begin_function_decl
specifier|static
name|bool
name|getFormatStringInfo
parameter_list|(
specifier|const
name|FormatAttr
modifier|*
name|Format
parameter_list|,
name|bool
name|IsCXXMember
parameter_list|,
name|FormatStringInfo
modifier|*
name|FSI
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
parameter_list|,
specifier|const
name|FunctionProtoType
modifier|*
name|Proto
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
name|bool
name|CheckObjCMethodCall
argument_list|(
name|ObjCMethodDecl
operator|*
name|Method
argument_list|,
name|SourceLocation
name|loc
argument_list|,
name|ArrayRef
operator|<
specifier|const
name|Expr
operator|*
operator|>
name|Args
argument_list|)
decl_stmt|;
end_decl_stmt

begin_function_decl
name|bool
name|CheckPointerCall
parameter_list|(
name|NamedDecl
modifier|*
name|NDecl
parameter_list|,
name|CallExpr
modifier|*
name|TheCall
parameter_list|,
specifier|const
name|FunctionProtoType
modifier|*
name|Proto
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|CheckOtherCall
parameter_list|(
name|CallExpr
modifier|*
name|TheCall
parameter_list|,
specifier|const
name|FunctionProtoType
modifier|*
name|Proto
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
name|void
name|CheckConstructorCall
argument_list|(
name|FunctionDecl
operator|*
name|FDecl
argument_list|,
name|ArrayRef
operator|<
specifier|const
name|Expr
operator|*
operator|>
name|Args
argument_list|,
specifier|const
name|FunctionProtoType
operator|*
name|Proto
argument_list|,
name|SourceLocation
name|Loc
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|checkCall
argument_list|(
name|NamedDecl
operator|*
name|FDecl
argument_list|,
specifier|const
name|FunctionProtoType
operator|*
name|Proto
argument_list|,
specifier|const
name|Expr
operator|*
name|ThisArg
argument_list|,
name|ArrayRef
operator|<
specifier|const
name|Expr
operator|*
operator|>
name|Args
argument_list|,
name|bool
name|IsMemberFunction
argument_list|,
name|SourceLocation
name|Loc
argument_list|,
name|SourceRange
name|Range
argument_list|,
name|VariadicCallType
name|CallType
argument_list|)
decl_stmt|;
end_decl_stmt

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
name|CheckOSLogFormatStringArg
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
name|FunctionDecl
modifier|*
name|FDecl
parameter_list|,
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
name|CheckARMBuiltinExclusiveCall
parameter_list|(
name|unsigned
name|BuiltinID
parameter_list|,
name|CallExpr
modifier|*
name|TheCall
parameter_list|,
name|unsigned
name|MaxWidth
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|CheckNeonBuiltinFunctionCall
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
name|CheckAArch64BuiltinFunctionCall
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
name|CheckMipsBuiltinFunctionCall
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
name|CheckSystemZBuiltinFunctionCall
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
name|CheckX86BuiltinRoundingOrSAE
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
name|CheckX86BuiltinGatherScatterScale
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
name|CheckPPCBuiltinFunctionCall
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
name|SemaBuiltinVAStartARM
parameter_list|(
name|CallExpr
modifier|*
name|Call
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

begin_function_decl
name|bool
name|SemaBuiltinOSLogFormat
parameter_list|(
name|CallExpr
modifier|*
name|TheCall
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

begin_function_decl
name|ExprResult
name|SemaConvertVectorExpr
parameter_list|(
name|Expr
modifier|*
name|E
parameter_list|,
name|TypeSourceInfo
modifier|*
name|TInfo
parameter_list|,
name|SourceLocation
name|BuiltinLoc
parameter_list|,
name|SourceLocation
name|RParenLoc
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
name|SemaBuiltinAllocaWithAlign
parameter_list|(
name|CallExpr
modifier|*
name|TheCall
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|SemaBuiltinAssume
parameter_list|(
name|CallExpr
modifier|*
name|TheCall
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|SemaBuiltinAssumeAligned
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
name|bool
name|SemaBuiltinSetjmp
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

begin_function_decl
name|ExprResult
name|SemaBuiltinNontemporalOverloaded
parameter_list|(
name|ExprResult
name|TheCallResult
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
name|ExprResult
name|SemaAtomicOpsOverloaded
argument_list|(
name|ExprResult
name|TheCallResult
argument_list|,
name|AtomicExpr
operator|::
name|AtomicOp
name|Op
argument_list|)
decl_stmt|;
end_decl_stmt

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
name|SemaBuiltinConstantArgRange
parameter_list|(
name|CallExpr
modifier|*
name|TheCall
parameter_list|,
name|int
name|ArgNum
parameter_list|,
name|int
name|Low
parameter_list|,
name|int
name|High
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|SemaBuiltinConstantArgMultiple
parameter_list|(
name|CallExpr
modifier|*
name|TheCall
parameter_list|,
name|int
name|ArgNum
parameter_list|,
name|unsigned
name|Multiple
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|SemaBuiltinARMSpecialReg
parameter_list|(
name|unsigned
name|BuiltinID
parameter_list|,
name|CallExpr
modifier|*
name|TheCall
parameter_list|,
name|int
name|ArgNum
parameter_list|,
name|unsigned
name|ExpectedFieldNum
parameter_list|,
name|bool
name|AllowName
parameter_list|)
function_decl|;
end_function_decl

begin_label
name|public
label|:
end_label

begin_enum
enum|enum
name|FormatStringType
block|{
name|FST_Scanf
block|,
name|FST_Printf
block|,
name|FST_NSString
block|,
name|FST_Strftime
block|,
name|FST_Strfmon
block|,
name|FST_Kprintf
block|,
name|FST_FreeBSDKPrintf
block|,
name|FST_OSTrace
block|,
name|FST_OSLog
block|,
name|FST_Unknown
block|}
enum|;
end_enum

begin_function_decl
specifier|static
name|FormatStringType
name|GetFormatStringType
parameter_list|(
specifier|const
name|FormatAttr
modifier|*
name|Format
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|FormatStringHasSArg
parameter_list|(
specifier|const
name|StringLiteral
modifier|*
name|FExpr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|bool
name|GetFormatNSStringIdx
parameter_list|(
specifier|const
name|FormatAttr
modifier|*
name|Format
parameter_list|,
name|unsigned
modifier|&
name|Idx
parameter_list|)
function_decl|;
end_function_decl

begin_label
name|private
label|:
end_label

begin_decl_stmt
name|bool
name|CheckFormatArguments
argument_list|(
specifier|const
name|FormatAttr
operator|*
name|Format
argument_list|,
name|ArrayRef
operator|<
specifier|const
name|Expr
operator|*
operator|>
name|Args
argument_list|,
name|bool
name|IsCXXMember
argument_list|,
name|VariadicCallType
name|CallType
argument_list|,
name|SourceLocation
name|Loc
argument_list|,
name|SourceRange
name|Range
argument_list|,
name|llvm
operator|::
name|SmallBitVector
operator|&
name|CheckedVarArgs
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|bool
name|CheckFormatArguments
argument_list|(
name|ArrayRef
operator|<
specifier|const
name|Expr
operator|*
operator|>
name|Args
argument_list|,
name|bool
name|HasVAListArg
argument_list|,
name|unsigned
name|format_idx
argument_list|,
name|unsigned
name|firstDataArg
argument_list|,
name|FormatStringType
name|Type
argument_list|,
name|VariadicCallType
name|CallType
argument_list|,
name|SourceLocation
name|Loc
argument_list|,
name|SourceRange
name|range
argument_list|,
name|llvm
operator|::
name|SmallBitVector
operator|&
name|CheckedVarArgs
argument_list|)
decl_stmt|;
end_decl_stmt

begin_function_decl
name|void
name|CheckAbsoluteValueFunction
parameter_list|(
specifier|const
name|CallExpr
modifier|*
name|Call
parameter_list|,
specifier|const
name|FunctionDecl
modifier|*
name|FDecl
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|CheckMaxUnsignedZero
parameter_list|(
specifier|const
name|CallExpr
modifier|*
name|Call
parameter_list|,
specifier|const
name|FunctionDecl
modifier|*
name|FDecl
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|CheckMemaccessArguments
parameter_list|(
specifier|const
name|CallExpr
modifier|*
name|Call
parameter_list|,
name|unsigned
name|BId
parameter_list|,
name|IdentifierInfo
modifier|*
name|FnName
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|CheckStrlcpycatArguments
parameter_list|(
specifier|const
name|CallExpr
modifier|*
name|Call
parameter_list|,
name|IdentifierInfo
modifier|*
name|FnName
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|CheckStrncatArguments
parameter_list|(
specifier|const
name|CallExpr
modifier|*
name|Call
parameter_list|,
name|IdentifierInfo
modifier|*
name|FnName
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|CheckReturnValExpr
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
parameter_list|,
name|bool
name|isObjCMethod
init|=
name|false
parameter_list|,
specifier|const
name|AttrVec
modifier|*
name|Attrs
init|=
name|nullptr
parameter_list|,
specifier|const
name|FunctionDecl
modifier|*
name|FD
init|=
name|nullptr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|CheckFloatComparison
parameter_list|(
name|SourceLocation
name|Loc
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
name|CheckBoolLikeConversion
parameter_list|(
name|Expr
modifier|*
name|E
parameter_list|,
name|SourceLocation
name|CC
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|CheckUnsequencedOperations
parameter_list|(
name|Expr
modifier|*
name|E
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// \brief Perform semantic checks on a completed expression. This will either
end_comment

begin_comment
comment|/// be a full-expression or a default argument expression.
end_comment

begin_function_decl
name|void
name|CheckCompletedExpr
parameter_list|(
name|Expr
modifier|*
name|E
parameter_list|,
name|SourceLocation
name|CheckLoc
init|=
name|SourceLocation
argument_list|()
parameter_list|,
name|bool
name|IsConstexpr
init|=
name|false
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
comment|/// Check if there is a field shadowing.
end_comment

begin_function_decl
name|void
name|CheckShadowInheritedFields
parameter_list|(
specifier|const
name|SourceLocation
modifier|&
name|Loc
parameter_list|,
name|DeclarationName
name|FieldName
parameter_list|,
specifier|const
name|CXXRecordDecl
modifier|*
name|RD
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// \brief Check if the given expression contains 'break' or 'continue'
end_comment

begin_comment
comment|/// statement that produces control flow different from GCC.
end_comment

begin_function_decl
name|void
name|CheckBreakContinueBinding
parameter_list|(
name|Expr
modifier|*
name|E
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// \brief Check whether receiver is mutable ObjC container which
end_comment

begin_comment
comment|/// attempts to add itself into the container
end_comment

begin_function_decl
name|void
name|CheckObjCCircularContainer
parameter_list|(
name|ObjCMessageExpr
modifier|*
name|Message
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|AnalyzeDeleteExprMismatch
parameter_list|(
specifier|const
name|CXXDeleteExpr
modifier|*
name|DE
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|AnalyzeDeleteExprMismatch
parameter_list|(
name|FieldDecl
modifier|*
name|Field
parameter_list|,
name|SourceLocation
name|DeleteLoc
parameter_list|,
name|bool
name|DeleteWasArrayForm
parameter_list|)
function_decl|;
end_function_decl

begin_label
name|public
label|:
end_label

begin_comment
comment|/// \brief Register a magic integral constant to be used as a type tag.
end_comment

begin_function_decl
name|void
name|RegisterTypeTagForDatatype
parameter_list|(
specifier|const
name|IdentifierInfo
modifier|*
name|ArgumentKind
parameter_list|,
name|uint64_t
name|MagicValue
parameter_list|,
name|QualType
name|Type
parameter_list|,
name|bool
name|LayoutCompatible
parameter_list|,
name|bool
name|MustBeNull
parameter_list|)
function_decl|;
end_function_decl

begin_struct
struct|struct
name|TypeTagData
block|{
name|TypeTagData
argument_list|()
block|{}
name|TypeTagData
argument_list|(
argument|QualType Type
argument_list|,
argument|bool LayoutCompatible
argument_list|,
argument|bool MustBeNull
argument_list|)
block|:
name|Type
argument_list|(
name|Type
argument_list|)
operator|,
name|LayoutCompatible
argument_list|(
name|LayoutCompatible
argument_list|)
operator|,
name|MustBeNull
argument_list|(
argument|MustBeNull
argument_list|)
block|{}
name|QualType
name|Type
expr_stmt|;
comment|/// If true, \c Type should be compared with other expression's types for
comment|/// layout-compatibility.
name|unsigned
name|LayoutCompatible
range|:
literal|1
decl_stmt|;
name|unsigned
name|MustBeNull
range|:
literal|1
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/// A pair of ArgumentKind identifier and magic value.  This uniquely
end_comment

begin_comment
comment|/// identifies the magic value.
end_comment

begin_typedef
typedef|typedef
name|std
operator|::
name|pair
operator|<
specifier|const
name|IdentifierInfo
operator|*
operator|,
name|uint64_t
operator|>
name|TypeTagMagicValue
expr_stmt|;
end_typedef

begin_label
name|private
label|:
end_label

begin_comment
comment|/// \brief A map from magic value to type information.
end_comment

begin_expr_stmt
name|std
operator|::
name|unique_ptr
operator|<
name|llvm
operator|::
name|DenseMap
operator|<
name|TypeTagMagicValue
operator|,
name|TypeTagData
operator|>>
name|TypeTagForDatatypeMagicValues
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// \brief Peform checks on a call of a function with argument_with_type_tag
end_comment

begin_comment
comment|/// or pointer_with_type_tag attributes.
end_comment

begin_function_decl
name|void
name|CheckArgumentWithTypeTag
parameter_list|(
specifier|const
name|ArgumentWithTypeTagAttr
modifier|*
name|Attr
parameter_list|,
specifier|const
name|Expr
modifier|*
specifier|const
modifier|*
name|ExprArgs
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// \brief Check if we are taking the address of a packed field
end_comment

begin_comment
comment|/// as this may be a problem if the pointer value is dereferenced.
end_comment

begin_function_decl
name|void
name|CheckAddressOfPackedMember
parameter_list|(
name|Expr
modifier|*
name|rhs
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

begin_decl_stmt
name|mutable
name|IdentifierInfo
modifier|*
name|Ident_super
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|mutable
name|IdentifierInfo
modifier|*
name|Ident___float128
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// Nullability type specifiers.
end_comment

begin_decl_stmt
name|IdentifierInfo
modifier|*
name|Ident__Nonnull
init|=
name|nullptr
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|IdentifierInfo
modifier|*
name|Ident__Nullable
init|=
name|nullptr
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|IdentifierInfo
modifier|*
name|Ident__Null_unspecified
init|=
name|nullptr
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|IdentifierInfo
modifier|*
name|Ident_NSError
init|=
name|nullptr
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

begin_decl_stmt
name|friend
name|class
name|ASTReader
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|friend
name|class
name|ASTDeclReader
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|friend
name|class
name|ASTWriter
decl_stmt|;
end_decl_stmt

begin_label
name|public
label|:
end_label

begin_comment
comment|/// Retrieve the keyword associated
end_comment

begin_function_decl
name|IdentifierInfo
modifier|*
name|getNullabilityKeyword
parameter_list|(
name|NullabilityKind
name|nullability
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// The struct behind the CFErrorRef pointer.
end_comment

begin_decl_stmt
name|RecordDecl
modifier|*
name|CFError
init|=
name|nullptr
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// Retrieve the identifier "NSError".
end_comment

begin_function_decl
name|IdentifierInfo
modifier|*
name|getNSErrorIdent
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/// \brief Retrieve the parser's current scope.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This routine must only be used when it is certain that semantic analysis
end_comment

begin_comment
comment|/// and the parser are in precisely the same context, which is not the case
end_comment

begin_comment
comment|/// when, e.g., we are performing any kind of template instantiation.
end_comment

begin_comment
comment|/// Therefore, the only safe places to use this scope are in the parser
end_comment

begin_comment
comment|/// itself and in routines directly invoked from the parser and *never* from
end_comment

begin_comment
comment|/// template substitution or instantiation.
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

begin_expr_stmt
name|void
name|incrementMSManglingNumber
argument_list|()
specifier|const
block|{
return|return
name|CurScope
operator|->
name|incrementMSManglingNumber
argument_list|()
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|IdentifierInfo
operator|*
name|getSuperIdentifier
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|IdentifierInfo
operator|*
name|getFloat128Identifier
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|Decl
operator|*
name|getObjCDeclContext
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|DeclContext
operator|*
name|getCurLexicalContext
argument_list|()
specifier|const
block|{
return|return
name|OriginalLexicalContext
operator|?
name|OriginalLexicalContext
operator|:
name|CurContext
return|;
block|}
end_expr_stmt

begin_comment
comment|/// \brief The diagnostic we should emit for \c D, or \c AR_Available.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param D The declaration to check. Note that this may be altered to point
end_comment

begin_comment
comment|/// to another declaration that \c D gets it's availability from. i.e., we
end_comment

begin_comment
comment|/// walk the list of typedefs to find an availability attribute.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param Message If non-null, this will be populated with the message from
end_comment

begin_comment
comment|/// the availability attribute that is selected.
end_comment

begin_decl_stmt
name|AvailabilityResult
name|ShouldDiagnoseAvailabilityOfDecl
argument_list|(
name|NamedDecl
operator|*
operator|&
name|D
argument_list|,
name|std
operator|::
name|string
operator|*
name|Message
argument_list|)
decl_stmt|;
end_decl_stmt

begin_expr_stmt
specifier|const
name|DeclContext
operator|*
name|getCurObjCLexicalContext
argument_list|()
specifier|const
block|{
specifier|const
name|DeclContext
operator|*
name|DC
operator|=
name|getCurLexicalContext
argument_list|()
block|;
comment|// A category implicitly has the attribute of the interface.
if|if
condition|(
specifier|const
name|ObjCCategoryDecl
modifier|*
name|CatD
init|=
name|dyn_cast
operator|<
name|ObjCCategoryDecl
operator|>
operator|(
name|DC
operator|)
condition|)
name|DC
operator|=
name|CatD
operator|->
name|getClassInterface
argument_list|()
expr_stmt|;
end_expr_stmt

begin_return
return|return
name|DC
return|;
end_return

begin_comment
unit|}
comment|/// \brief To be used for checking whether the arguments being passed to
end_comment

begin_comment
comment|/// function exceeds the number of parameters expected for it.
end_comment

begin_function
unit|static
name|bool
name|TooManyArguments
parameter_list|(
name|size_t
name|NumParams
parameter_list|,
name|size_t
name|NumArgs
parameter_list|,
name|bool
name|PartialOverloading
init|=
name|false
parameter_list|)
block|{
comment|// We check whether we're just after a comma in code-completion.
if|if
condition|(
name|NumArgs
operator|>
literal|0
operator|&&
name|PartialOverloading
condition|)
return|return
name|NumArgs
operator|+
literal|1
operator|>
name|NumParams
return|;
comment|// If so, we view as an extra argument.
return|return
name|NumArgs
operator|>
name|NumParams
return|;
block|}
end_function

begin_comment
comment|// Emitting members of dllexported classes is delayed until the class
end_comment

begin_comment
comment|// (including field initializers) is fully parsed.
end_comment

begin_expr_stmt
name|SmallVector
operator|<
name|CXXRecordDecl
operator|*
operator|,
literal|4
operator|>
name|DelayedDllExportClasses
expr_stmt|;
end_expr_stmt

begin_label
name|private
label|:
end_label

begin_comment
comment|/// \brief Helper class that collects misaligned member designations and
end_comment

begin_comment
comment|/// their location info for delayed diagnostics.
end_comment

begin_struct
struct|struct
name|MisalignedMember
block|{
name|Expr
modifier|*
name|E
decl_stmt|;
name|RecordDecl
modifier|*
name|RD
decl_stmt|;
name|ValueDecl
modifier|*
name|MD
decl_stmt|;
name|CharUnits
name|Alignment
decl_stmt|;
name|MisalignedMember
argument_list|()
operator|:
name|E
argument_list|()
operator|,
name|RD
argument_list|()
operator|,
name|MD
argument_list|()
operator|,
name|Alignment
argument_list|()
block|{}
name|MisalignedMember
argument_list|(
argument|Expr *E
argument_list|,
argument|RecordDecl *RD
argument_list|,
argument|ValueDecl *MD
argument_list|,
argument|CharUnits Alignment
argument_list|)
operator|:
name|E
argument_list|(
name|E
argument_list|)
operator|,
name|RD
argument_list|(
name|RD
argument_list|)
operator|,
name|MD
argument_list|(
name|MD
argument_list|)
operator|,
name|Alignment
argument_list|(
argument|Alignment
argument_list|)
block|{}
name|explicit
name|MisalignedMember
argument_list|(
name|Expr
operator|*
name|E
argument_list|)
operator|:
name|MisalignedMember
argument_list|(
argument|E
argument_list|,
argument|nullptr
argument_list|,
argument|nullptr
argument_list|,
argument|CharUnits()
argument_list|)
block|{}
name|bool
name|operator
operator|==
operator|(
specifier|const
name|MisalignedMember
operator|&
name|m
operator|)
block|{
return|return
name|this
operator|->
name|E
operator|==
name|m
operator|.
name|E
return|;
block|}
block|}
struct|;
end_struct

begin_comment
comment|/// \brief Small set of gathered accesses to potentially misaligned members
end_comment

begin_comment
comment|/// due to the packed attribute.
end_comment

begin_expr_stmt
name|SmallVector
operator|<
name|MisalignedMember
operator|,
literal|4
operator|>
name|MisalignedMembers
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// \brief Adds an expression to the set of gathered misaligned members.
end_comment

begin_function_decl
name|void
name|AddPotentialMisalignedMembers
parameter_list|(
name|Expr
modifier|*
name|E
parameter_list|,
name|RecordDecl
modifier|*
name|RD
parameter_list|,
name|ValueDecl
modifier|*
name|MD
parameter_list|,
name|CharUnits
name|Alignment
parameter_list|)
function_decl|;
end_function_decl

begin_label
name|public
label|:
end_label

begin_comment
comment|/// \brief Diagnoses the current set of gathered accesses. This typically
end_comment

begin_comment
comment|/// happens at full expression level. The set is cleared after emitting the
end_comment

begin_comment
comment|/// diagnostics.
end_comment

begin_function_decl
name|void
name|DiagnoseMisalignedMembers
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/// \brief This function checks if the expression is in the sef of potentially
end_comment

begin_comment
comment|/// misaligned members and it is converted to some pointer type T with lower
end_comment

begin_comment
comment|/// or equal alignment requirements. If so it removes it. This is used when
end_comment

begin_comment
comment|/// we do not want to diagnose such misaligned access (e.g. in conversions to
end_comment

begin_comment
comment|/// void*).
end_comment

begin_function_decl
name|void
name|DiscardMisalignedMemberAddress
parameter_list|(
specifier|const
name|Type
modifier|*
name|T
parameter_list|,
name|Expr
modifier|*
name|E
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// \brief This function calls Action when it determines that E designates a
end_comment

begin_comment
comment|/// misaligned member due to the packed attribute. This is used to emit
end_comment

begin_comment
comment|/// local diagnostics like in reference binding.
end_comment

begin_decl_stmt
name|void
name|RefersToMemberWithReducedAlignment
argument_list|(
name|Expr
operator|*
name|E
argument_list|,
name|llvm
operator|::
name|function_ref
operator|<
name|void
argument_list|(
name|Expr
operator|*
argument_list|,
name|RecordDecl
operator|*
argument_list|,
name|FieldDecl
operator|*
argument_list|,
name|CharUnits
argument_list|)
operator|>
name|Action
argument_list|)
decl_stmt|;
end_decl_stmt

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
name|bool
name|Entered
init|=
name|true
decl_stmt|;
name|public
label|:
name|EnterExpressionEvaluationContext
argument_list|(
argument|Sema&Actions
argument_list|,
argument|Sema::ExpressionEvaluationContext NewContext
argument_list|,
argument|Decl *LambdaContextDecl = nullptr
argument_list|,
argument|bool IsDecltype = false
argument_list|,
argument|bool ShouldEnter = true
argument_list|)
block|:
name|Actions
argument_list|(
name|Actions
argument_list|)
operator|,
name|Entered
argument_list|(
argument|ShouldEnter
argument_list|)
block|{
if|if
condition|(
name|Entered
condition|)
name|Actions
operator|.
name|PushExpressionEvaluationContext
argument_list|(
name|NewContext
argument_list|,
name|LambdaContextDecl
argument_list|,
name|IsDecltype
argument_list|)
expr_stmt|;
block|}
name|EnterExpressionEvaluationContext
argument_list|(
argument|Sema&Actions
argument_list|,
argument|Sema::ExpressionEvaluationContext NewContext
argument_list|,
argument|Sema::ReuseLambdaContextDecl_t
argument_list|,
argument|bool IsDecltype = false
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
argument_list|,
name|Sema
operator|::
name|ReuseLambdaContextDecl
argument_list|,
name|IsDecltype
argument_list|)
expr_stmt|;
block|}
enum|enum
name|InitListTag
block|{
name|InitList
block|}
enum|;
name|EnterExpressionEvaluationContext
argument_list|(
argument|Sema&Actions
argument_list|,
argument|InitListTag
argument_list|,
argument|bool ShouldEnter = true
argument_list|)
block|:
name|Actions
argument_list|(
name|Actions
argument_list|)
operator|,
name|Entered
argument_list|(
argument|false
argument_list|)
block|{
comment|// In C++11 onwards, narrowing checks are performed on the contents of
comment|// braced-init-lists, even when they occur within unevaluated operands.
comment|// Therefore we still need to instantiate constexpr functions used in such
comment|// a context.
if|if
condition|(
name|ShouldEnter
operator|&&
name|Actions
operator|.
name|isUnevaluatedContext
argument_list|()
operator|&&
name|Actions
operator|.
name|getLangOpts
argument_list|()
operator|.
name|CPlusPlus11
condition|)
block|{
name|Actions
operator|.
name|PushExpressionEvaluationContext
argument_list|(
name|Sema
operator|::
name|ExpressionEvaluationContext
operator|::
name|UnevaluatedList
argument_list|,
name|nullptr
argument_list|,
name|false
argument_list|)
expr_stmt|;
name|Entered
operator|=
name|true
expr_stmt|;
block|}
block|}
operator|~
name|EnterExpressionEvaluationContext
argument_list|()
block|{
if|if
condition|(
name|Entered
condition|)
name|Actions
operator|.
name|PopExpressionEvaluationContext
argument_list|()
expr_stmt|;
block|}
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_decl_stmt
name|DeductionFailureInfo
name|MakeDeductionFailureInfo
argument_list|(
name|ASTContext
operator|&
name|Context
argument_list|,
name|Sema
operator|::
name|TemplateDeductionResult
name|TDK
argument_list|,
name|sema
operator|::
name|TemplateDeductionInfo
operator|&
name|Info
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// \brief Contains a late templated function.
end_comment

begin_comment
comment|/// Will be parsed at the end of the translation unit, used by Sema& Parser.
end_comment

begin_struct
struct|struct
name|LateParsedTemplate
block|{
name|CachedTokens
name|Toks
decl_stmt|;
comment|/// \brief The template function declaration to be late parsed.
name|Decl
modifier|*
name|D
decl_stmt|;
block|}
struct|;
end_struct

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
comment|// Hash a FunctionDeclAndLoc by looking at both its FunctionDecl and its
comment|// SourceLocation.
name|template
operator|<
operator|>
expr|struct
name|DenseMapInfo
operator|<
name|clang
operator|::
name|Sema
operator|::
name|FunctionDeclAndLoc
operator|>
block|{
name|using
name|FunctionDeclAndLoc
operator|=
name|clang
operator|::
name|Sema
operator|::
name|FunctionDeclAndLoc
block|;
name|using
name|FDBaseInfo
operator|=
name|DenseMapInfo
operator|<
name|clang
operator|::
name|CanonicalDeclPtr
operator|<
name|clang
operator|::
name|FunctionDecl
operator|>>
block|;
specifier|static
name|FunctionDeclAndLoc
name|getEmptyKey
argument_list|()
block|{
return|return
block|{
name|FDBaseInfo
operator|::
name|getEmptyKey
argument_list|()
block|,
name|clang
operator|::
name|SourceLocation
argument_list|()
block|}
return|;
block|}
specifier|static
name|FunctionDeclAndLoc
name|getTombstoneKey
argument_list|()
block|{
return|return
block|{
name|FDBaseInfo
operator|::
name|getTombstoneKey
argument_list|()
block|,
name|clang
operator|::
name|SourceLocation
argument_list|()
block|}
return|;
block|}
specifier|static
name|unsigned
name|getHashValue
parameter_list|(
specifier|const
name|FunctionDeclAndLoc
modifier|&
name|FDL
parameter_list|)
block|{
return|return
name|hash_combine
argument_list|(
name|FDBaseInfo
operator|::
name|getHashValue
argument_list|(
name|FDL
operator|.
name|FD
argument_list|)
argument_list|,
name|FDL
operator|.
name|Loc
operator|.
name|getRawEncoding
argument_list|()
argument_list|)
return|;
block|}
specifier|static
name|bool
name|isEqual
parameter_list|(
specifier|const
name|FunctionDeclAndLoc
modifier|&
name|LHS
parameter_list|,
specifier|const
name|FunctionDeclAndLoc
modifier|&
name|RHS
parameter_list|)
block|{
return|return
name|LHS
operator|.
name|FD
operator|==
name|RHS
operator|.
name|FD
operator|&&
name|LHS
operator|.
name|Loc
operator|==
name|RHS
operator|.
name|Loc
return|;
block|}
block|}
end_block

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
unit|}
comment|// namespace llvm
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

