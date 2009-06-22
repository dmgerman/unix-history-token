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
name|DesignatedInitExpr
decl_stmt|;
name|class
name|CallExpr
decl_stmt|;
name|class
name|DeclRefExpr
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
name|BasePaths
decl_stmt|;
struct_decl|struct
name|MemberLookupCriteria
struct_decl|;
name|class
name|CXXTemporary
decl_stmt|;
comment|/// BlockSemaInfo - When a block is being parsed, this contains information
comment|/// about the block.  It is pointed to from Sema::CurBlock.
struct|struct
name|BlockSemaInfo
block|{
name|llvm
operator|::
name|SmallVector
operator|<
name|ParmVarDecl
operator|*
operator|,
literal|8
operator|>
name|Params
expr_stmt|;
name|bool
name|hasPrototype
decl_stmt|;
name|bool
name|isVariadic
decl_stmt|;
name|bool
name|hasBlockDeclRefExprs
decl_stmt|;
name|BlockDecl
modifier|*
name|TheDecl
decl_stmt|;
comment|/// TheScope - This is the scope for the block itself, which contains
comment|/// arguments etc.
name|Scope
modifier|*
name|TheScope
decl_stmt|;
comment|/// ReturnType - This will get set to block result type, by looking at
comment|/// return types, if any, in the block body.
name|QualType
name|ReturnType
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
comment|/// SavedFunctionNeedsScopeChecking - This is the value of
comment|/// CurFunctionNeedsScopeChecking at the point when the block started.
name|bool
name|SavedFunctionNeedsScopeChecking
decl_stmt|;
comment|/// PrevBlockInfo - If this is nested inside another block, this points
comment|/// to the outer block.
name|BlockSemaInfo
modifier|*
name|PrevBlockInfo
decl_stmt|;
block|}
struct|;
comment|/// Sema - This implements semantic analysis and AST building for C.
name|class
name|Sema
range|:
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
comment|/// CurContext - This is the current declaration context of parsing.
name|DeclContext
operator|*
name|CurContext
block|;
comment|/// PreDeclaratorDC - Keeps the declaration context before switching to the
comment|/// context of a declarator's nested-name-specifier.
name|DeclContext
operator|*
name|PreDeclaratorDC
block|;
comment|/// CurBlock - If inside of a block definition, this contains a pointer to
comment|/// the active block object that represents it.
name|BlockSemaInfo
operator|*
name|CurBlock
block|;
comment|/// PackContext - Manages the stack for #pragma pack. An alignment
comment|/// of 0 indicates default alignment.
name|void
operator|*
name|PackContext
block|;
comment|// Really a "PragmaPackStack*"
comment|/// FunctionLabelMap - This is a mapping from label identifiers to the
comment|/// LabelStmt for it (which acts like the label decl in some ways).  Forward
comment|/// referenced labels have a LabelStmt created for them with a null location&
comment|/// SubStmt.
comment|///
comment|/// Note that this should always be accessed through getLabelMap() in order
comment|/// to handle blocks properly.
name|llvm
operator|::
name|DenseMap
operator|<
name|IdentifierInfo
operator|*
block|,
name|LabelStmt
operator|*
operator|>
name|FunctionLabelMap
block|;
comment|/// FunctionSwitchStack - This is the current set of active switch statements
comment|/// in the top level function.  Clients should always use getSwitchStack() to
comment|/// handle the case when they are in a block.
name|llvm
operator|::
name|SmallVector
operator|<
name|SwitchStmt
operator|*
block|,
literal|8
operator|>
name|FunctionSwitchStack
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
comment|/// CurFunctionNeedsScopeChecking - This is set to true when a function or
comment|/// ObjC method body contains a VLA or an ObjC try block, which introduce
comment|/// scopes that need to be checked for goto conditions.  If a function does
comment|/// not contain this, then it need not have the jump checker run on it.
name|bool
name|CurFunctionNeedsScopeChecking
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
comment|/// ObjCCategoryImpls - Maintain a list of category implementations so
comment|/// we can check for duplicates and find local method declarations.
name|llvm
operator|::
name|SmallVector
operator|<
name|ObjCCategoryImplDecl
operator|*
block|,
literal|8
operator|>
name|ObjCCategoryImpls
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
decl_stmt|;
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
comment|/// \brief The set of tentative declarations seen so far in this
comment|/// translation unit for which no definition has been seen.
comment|///
comment|/// The tentative declarations are indexed by the name of the
comment|/// declaration, and only the most recent tentative declaration for
comment|/// a given variable will be recorded here.
name|llvm
operator|::
name|DenseMap
operator|<
name|DeclarationName
operator|,
name|VarDecl
operator|*
operator|>
name|TentativeDefinitions
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
comment|/// The C++ "std" namespace, where the standard library resides. Cached here
comment|/// by GetStdNamespace
name|NamespaceDecl
modifier|*
name|StdNamespace
decl_stmt|;
comment|/// A flag to remember whether the implicit forms of operator new and delete
comment|/// have been declared.
name|bool
name|GlobalNewDeleteDeclared
decl_stmt|;
comment|/// A flag that indicates when we are processing an unevaluated operand
comment|/// (C++0x [expr]). C99 has the same notion of declarations being
comment|/// "used" and C++03 has the notion of "potentially evaluated", but we
comment|/// adopt the C++0x terminology since it is most precise.
name|bool
name|InUnevaluatedOperand
decl_stmt|;
comment|/// \brief Whether the code handled by Sema should be considered a
comment|/// complete translation unit or not.
comment|///
comment|/// When true (which is generally the case), Sema will perform
comment|/// end-of-translation-unit semantic tasks (such as creating
comment|/// initializers for tentative definitions in C) once parsing has
comment|/// completed. This flag will be false when building PCH files,
comment|/// since a PCH file is by definition not a complete translation
comment|/// unit.
name|bool
name|CompleteTranslationUnit
decl_stmt|;
comment|/// \brief The number of SFINAE diagnostics that have been trapped.
name|unsigned
name|NumSFINAEErrors
decl_stmt|;
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
comment|/// Instance/Factory Method Pools - allows efficient lookup when typechecking
comment|/// messages to "id". We need to maintain a list, since selectors can have
comment|/// differing signatures across classes. In Cocoa, this happens to be
comment|/// extremely uncommon (only 1% of selectors are "overloaded").
name|MethodPool
name|InstanceMethodPool
decl_stmt|;
name|MethodPool
name|FactoryMethodPool
decl_stmt|;
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
comment|/// Private Helper predicate to check for 'self'.
name|bool
name|isSelfExpr
parameter_list|(
name|Expr
modifier|*
name|RExpr
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
argument|bool CompleteTranslationUnit = true
argument_list|)
empty_stmt|;
operator|~
name|Sema
argument_list|()
block|{
if|if
condition|(
name|PackContext
condition|)
name|FreePackedContext
argument_list|()
expr_stmt|;
block|}
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
if|if
condition|(
name|isSFINAEContext
argument_list|()
operator|&&
name|Diagnostic
operator|::
name|isBuiltinSFINAEDiag
argument_list|(
name|DiagID
argument_list|)
condition|)
block|{
comment|// If we encountered an error during template argument
comment|// deduction, and that error is one of the SFINAE errors,
comment|// suppress the diagnostic.
operator|++
name|NumSFINAEErrors
expr_stmt|;
return|return
name|SemaDiagnosticBuilder
argument_list|(
operator|*
name|this
argument_list|)
return|;
block|}
name|DiagnosticBuilder
name|DB
init|=
name|Diags
operator|.
name|Report
argument_list|(
name|FullSourceLoc
argument_list|(
name|Loc
argument_list|,
name|SourceMgr
argument_list|)
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
name|virtual
name|void
name|DeleteExpr
parameter_list|(
name|ExprTy
modifier|*
name|E
parameter_list|)
function_decl|;
name|virtual
name|void
name|DeleteStmt
parameter_list|(
name|StmtTy
modifier|*
name|S
parameter_list|)
function_decl|;
name|OwningExprResult
name|Owned
parameter_list|(
name|Expr
modifier|*
name|E
parameter_list|)
block|{
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
name|OwningStmtResult
name|Owned
parameter_list|(
name|Stmt
modifier|*
name|S
parameter_list|)
block|{
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
name|virtual
name|void
name|ActOnEndOfTranslationUnit
parameter_list|()
function_decl|;
comment|/// getLabelMap() - Return the current label map.  If we're in a block, we
comment|/// return it.
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
return|return
name|CurBlock
operator|?
name|CurBlock
operator|->
name|LabelMap
operator|:
name|FunctionLabelMap
return|;
block|}
comment|/// getSwitchStack - This is returns the switch stack for the current block or
comment|/// function.
name|llvm
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
return|return
name|CurBlock
operator|?
name|CurBlock
operator|->
name|SwitchStack
operator|:
name|FunctionSwitchStack
return|;
block|}
comment|//===--------------------------------------------------------------------===//
comment|// Type Analysis / Processing: SemaType.cpp.
comment|//
name|QualType
name|adjustParameterType
parameter_list|(
name|QualType
name|T
parameter_list|)
function_decl|;
name|QualType
name|ConvertDeclSpecToType
parameter_list|(
specifier|const
name|DeclSpec
modifier|&
name|DS
parameter_list|,
name|SourceLocation
name|DeclLoc
parameter_list|,
name|bool
modifier|&
name|IsInvalid
parameter_list|)
function_decl|;
name|void
name|ProcessTypeAttributeList
parameter_list|(
name|QualType
modifier|&
name|Result
parameter_list|,
specifier|const
name|AttributeList
modifier|*
name|AL
parameter_list|)
function_decl|;
name|QualType
name|BuildPointerType
parameter_list|(
name|QualType
name|T
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
name|QualType
name|BuildReferenceType
parameter_list|(
name|QualType
name|T
parameter_list|,
name|bool
name|LValueRef
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
name|SourceLocation
name|Loc
argument_list|,
name|DeclarationName
name|Entity
argument_list|)
decl_stmt|;
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
name|QualType
name|BuildMemberPointerType
parameter_list|(
name|QualType
name|T
parameter_list|,
name|QualType
name|Class
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
name|QualType
name|BuildBlockPointerType
parameter_list|(
name|QualType
name|T
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
name|QualType
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
name|unsigned
name|Skip
init|=
literal|0
parameter_list|,
name|TagDecl
modifier|*
modifier|*
name|OwnedDecl
init|=
literal|0
parameter_list|)
function_decl|;
name|DeclarationName
name|GetNameForDeclarator
parameter_list|(
name|Declarator
modifier|&
name|D
parameter_list|)
function_decl|;
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
name|bool
name|CheckDistantExceptionSpec
parameter_list|(
name|QualType
name|T
parameter_list|)
function_decl|;
name|QualType
name|ObjCGetTypeForMethodDefinition
parameter_list|(
name|DeclPtrTy
name|D
parameter_list|)
function_decl|;
name|bool
name|UnwrapSimilarPointerTypes
parameter_list|(
name|QualType
modifier|&
name|T1
parameter_list|,
name|QualType
modifier|&
name|T2
parameter_list|)
function_decl|;
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
name|diag
parameter_list|,
name|SourceRange
name|Range1
init|=
name|SourceRange
argument_list|()
parameter_list|,
name|SourceRange
name|Range2
init|=
name|SourceRange
argument_list|()
parameter_list|,
name|QualType
name|PrintType
init|=
name|QualType
argument_list|()
parameter_list|)
function_decl|;
name|QualType
name|getQualifiedNameType
parameter_list|(
specifier|const
name|CXXScopeSpec
modifier|&
name|SS
parameter_list|,
name|QualType
name|T
parameter_list|)
function_decl|;
comment|//===--------------------------------------------------------------------===//
comment|// Symbol table / Decl tracking callbacks: SemaDecl.cpp.
comment|//
comment|/// getDeclName - Return a pretty name for the specified decl if possible, or
comment|/// an empty string if not.  This is used for pretty crash reporting.
name|virtual
name|std
operator|::
name|string
name|getDeclName
argument_list|(
argument|DeclPtrTy D
argument_list|)
expr_stmt|;
name|DeclGroupPtrTy
name|ConvertDeclToDeclGroup
parameter_list|(
name|DeclPtrTy
name|Ptr
parameter_list|)
function_decl|;
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
specifier|const
name|CXXScopeSpec
modifier|*
name|SS
parameter_list|)
function_decl|;
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
name|ActOnDeclarator
argument_list|(
name|S
argument_list|,
name|D
argument_list|,
name|false
argument_list|)
return|;
block|}
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
parameter_list|,
name|bool
name|IsFunctionDefinition
parameter_list|)
function_decl|;
name|void
name|RegisterLocallyScopedExternCDecl
parameter_list|(
name|NamedDecl
modifier|*
name|ND
parameter_list|,
name|NamedDecl
modifier|*
name|PrevDecl
parameter_list|,
name|Scope
modifier|*
name|S
parameter_list|)
function_decl|;
name|void
name|DiagnoseFunctionSpecifiers
parameter_list|(
name|Declarator
modifier|&
name|D
parameter_list|)
function_decl|;
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
name|Decl
modifier|*
name|PrevDecl
parameter_list|,
name|bool
modifier|&
name|Redeclaration
parameter_list|)
function_decl|;
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
name|NamedDecl
modifier|*
name|PrevDecl
parameter_list|,
name|bool
modifier|&
name|Redeclaration
parameter_list|)
function_decl|;
name|void
name|CheckVariableDeclaration
parameter_list|(
name|VarDecl
modifier|*
name|NewVD
parameter_list|,
name|NamedDecl
modifier|*
name|PrevDecl
parameter_list|,
name|bool
modifier|&
name|Redeclaration
parameter_list|)
function_decl|;
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
name|NamedDecl
modifier|*
name|PrevDecl
parameter_list|,
name|bool
name|IsFunctionDefinition
parameter_list|,
name|bool
modifier|&
name|Redeclaration
parameter_list|)
function_decl|;
name|void
name|CheckFunctionDeclaration
parameter_list|(
name|FunctionDecl
modifier|*
name|NewFD
parameter_list|,
name|NamedDecl
modifier|*
modifier|&
name|PrevDecl
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
name|virtual
name|void
name|ActOnParamDefaultArgumentError
parameter_list|(
name|DeclPtrTy
name|param
parameter_list|)
function_decl|;
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
name|virtual
name|void
name|AddInitializerToDecl
parameter_list|(
name|DeclPtrTy
name|dcl
parameter_list|,
name|FullExprArg
name|init
parameter_list|)
function_decl|;
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
name|void
name|ActOnUninitializedDecl
parameter_list|(
name|DeclPtrTy
name|dcl
parameter_list|)
function_decl|;
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
comment|/// \brief Diagnose any unused parameters in the given sequence of
comment|/// ParmVarDecl pointers.
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
name|Context
operator|)
condition|)
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
name|void
name|DiagnoseInvalidJumps
argument_list|(
name|Stmt
operator|*
name|Body
argument_list|)
expr_stmt|;
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
comment|/// Scope actions.
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
comment|/// ParsedFreeStandingDeclSpec - This method is invoked when a declspec with
comment|/// no declarator (e.g. "struct foo;") is parsed.
name|virtual
name|DeclPtrTy
name|ParsedFreeStandingDeclSpec
parameter_list|(
name|Scope
modifier|*
name|S
parameter_list|,
name|DeclSpec
modifier|&
name|DS
parameter_list|)
function_decl|;
name|bool
name|InjectAnonymousStructOrUnionMembers
parameter_list|(
name|Scope
modifier|*
name|S
parameter_list|,
name|DeclContext
modifier|*
name|Owner
parameter_list|,
name|RecordDecl
modifier|*
name|AnonRecord
parameter_list|)
function_decl|;
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
name|RecordDecl
modifier|*
name|Record
parameter_list|)
function_decl|;
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
name|TagKind
name|TK
parameter_list|,
name|SourceLocation
name|KWLoc
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
name|NameLoc
parameter_list|,
name|AttributeList
modifier|*
name|Attr
parameter_list|,
name|AccessSpecifier
name|AS
parameter_list|,
name|bool
modifier|&
name|OwnedDecl
parameter_list|)
function_decl|;
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
comment|// This is used for both record definitions and ObjC interface declarations.
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
comment|/// ActOnTagStartDefinition - Invoked when we have entered the
comment|/// scope of a tag's definition (e.g., for an enumeration, class,
comment|/// struct, or union).
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
comment|/// ActOnTagFinishDefinition - Invoked once we have finished parsing
comment|/// the definition of a tag (enumeration, class, struct, or union).
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
parameter_list|)
function_decl|;
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
parameter_list|)
function_decl|;
name|DeclContext
modifier|*
name|getContainingDC
parameter_list|(
name|DeclContext
modifier|*
name|DC
parameter_list|)
function_decl|;
comment|/// Set the current declaration context until it gets popped.
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
name|void
name|PopDeclContext
parameter_list|()
function_decl|;
comment|/// EnterDeclaratorContext - Used when we must lookup names in the context
comment|/// of a declarator's nested name specifier.
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
name|void
name|ExitDeclaratorContext
parameter_list|(
name|Scope
modifier|*
name|S
parameter_list|)
function_decl|;
comment|/// getCurFunctionDecl - If inside of a function body, this returns a pointer
comment|/// to the function decl for the function being parsed.  If we're currently
comment|/// in a 'block', this returns the containing context.
name|FunctionDecl
modifier|*
name|getCurFunctionDecl
parameter_list|()
function_decl|;
comment|/// getCurMethodDecl - If inside of a method body, this returns a pointer to
comment|/// the method decl for the method being parsed.  If we're currently
comment|/// in a 'block', this returns the containing context.
name|ObjCMethodDecl
modifier|*
name|getCurMethodDecl
parameter_list|()
function_decl|;
comment|/// getCurFunctionOrMethodDecl - Return the Decl for the current ObjC method
comment|/// or C function we're in, otherwise return null.  If we're currently
comment|/// in a 'block', this returns the containing context.
name|NamedDecl
modifier|*
name|getCurFunctionOrMethodDecl
parameter_list|()
function_decl|;
comment|/// Add this decl to the scope shadowed decl chains.
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
parameter_list|)
function_decl|;
comment|/// isDeclInScope - If 'Ctx' is a function/method, isDeclInScope returns true
comment|/// if 'D' is in Scope 'S', otherwise 'S' is ignored and isDeclInScope returns
comment|/// true if 'D' belongs to the given declaration context.
name|bool
name|isDeclInScope
parameter_list|(
name|Decl
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
literal|0
parameter_list|)
block|{
return|return
name|IdResolver
operator|.
name|isDeclInScope
argument_list|(
name|D
argument_list|,
name|Ctx
argument_list|,
name|Context
argument_list|,
name|S
argument_list|)
return|;
block|}
comment|/// Subroutines of ActOnDeclarator().
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
parameter_list|)
function_decl|;
name|void
name|MergeTypeDefDecl
parameter_list|(
name|TypedefDecl
modifier|*
name|New
parameter_list|,
name|Decl
modifier|*
name|Old
parameter_list|)
function_decl|;
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
name|void
name|MergeVarDecl
parameter_list|(
name|VarDecl
modifier|*
name|New
parameter_list|,
name|Decl
modifier|*
name|Old
parameter_list|)
function_decl|;
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
comment|/// C++ Overloading.
name|bool
name|IsOverload
argument_list|(
name|FunctionDecl
operator|*
name|New
argument_list|,
name|Decl
operator|*
name|OldD
argument_list|,
name|OverloadedFunctionDecl
operator|::
name|function_iterator
operator|&
name|MatchedDecl
argument_list|)
decl_stmt|;
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
init|=
name|false
parameter_list|,
name|bool
name|AllowExplicit
init|=
name|false
parameter_list|,
name|bool
name|ForceRValue
init|=
name|false
parameter_list|)
function_decl|;
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
name|StandardConversionSequence
modifier|&
name|SCS
parameter_list|)
function_decl|;
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
name|QualType
modifier|&
name|ConvertedType
parameter_list|,
name|bool
modifier|&
name|IncompatibleObjC
parameter_list|)
function_decl|;
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
name|bool
name|CheckPointerConversion
parameter_list|(
name|Expr
modifier|*
name|From
parameter_list|,
name|QualType
name|ToType
parameter_list|)
function_decl|;
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
name|QualType
modifier|&
name|ConvertedType
parameter_list|)
function_decl|;
name|bool
name|CheckMemberPointerConversion
parameter_list|(
name|Expr
modifier|*
name|From
parameter_list|,
name|QualType
name|ToType
parameter_list|)
function_decl|;
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
name|bool
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
name|bool
name|AllowConversionFunctions
parameter_list|,
name|bool
name|AllowExplicit
parameter_list|,
name|bool
name|ForceRValue
parameter_list|)
function_decl|;
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
name|ImplicitConversionSequence
name|TryCopyInitialization
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
init|=
name|false
parameter_list|,
name|bool
name|ForceRValue
init|=
name|false
parameter_list|)
function_decl|;
name|bool
name|PerformCopyInitialization
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
name|char
modifier|*
name|Flavor
parameter_list|,
name|bool
name|Elidable
init|=
name|false
parameter_list|)
function_decl|;
name|ImplicitConversionSequence
name|TryObjectArgumentInitialization
parameter_list|(
name|Expr
modifier|*
name|From
parameter_list|,
name|CXXMethodDecl
modifier|*
name|Method
parameter_list|)
function_decl|;
name|bool
name|PerformObjectArgumentInitialization
parameter_list|(
name|Expr
modifier|*
modifier|&
name|From
parameter_list|,
name|CXXMethodDecl
modifier|*
name|Method
parameter_list|)
function_decl|;
name|ImplicitConversionSequence
name|TryContextuallyConvertToBool
parameter_list|(
name|Expr
modifier|*
name|From
parameter_list|)
function_decl|;
name|bool
name|PerformContextuallyConvertToBool
parameter_list|(
name|Expr
modifier|*
modifier|&
name|From
parameter_list|)
function_decl|;
comment|/// OverloadingResult - Capture the result of performing overload
comment|/// resolution.
enum|enum
name|OverloadingResult
block|{
name|OR_Success
block|,
comment|///< Overload resolution succeeded.
name|OR_No_Viable_Function
block|,
comment|///< No viable function found.
name|OR_Ambiguous
block|,
comment|///< Ambiguous candidates found.
name|OR_Deleted
comment|///< Overload resoltuion refers to a deleted function.
block|}
enum|;
typedef|typedef
name|llvm
operator|::
name|SmallPtrSet
operator|<
name|FunctionDecl
operator|*
operator|,
literal|16
operator|>
name|FunctionSet
expr_stmt|;
typedef|typedef
name|llvm
operator|::
name|SmallPtrSet
operator|<
name|NamespaceDecl
operator|*
operator|,
literal|16
operator|>
name|AssociatedNamespaceSet
expr_stmt|;
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
name|void
name|AddOverloadCandidate
parameter_list|(
name|FunctionDecl
modifier|*
name|Function
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
name|ForceRValue
init|=
name|false
parameter_list|)
function_decl|;
name|void
name|AddFunctionCandidates
parameter_list|(
specifier|const
name|FunctionSet
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
name|void
name|AddMethodCandidate
parameter_list|(
name|CXXMethodDecl
modifier|*
name|Method
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
parameter_list|,
name|bool
name|SuppressUserConversions
init|=
name|false
parameter_list|,
name|bool
name|ForceRValue
init|=
name|false
parameter_list|)
function_decl|;
name|void
name|AddConversionCandidate
parameter_list|(
name|CXXConversionDecl
modifier|*
name|Conversion
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
name|void
name|AddSurrogateCandidate
parameter_list|(
name|CXXConversionDecl
modifier|*
name|Conversion
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
name|void
name|AddOperatorCandidates
parameter_list|(
name|OverloadedOperatorKind
name|Op
parameter_list|,
name|Scope
modifier|*
name|S
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
name|void
name|AddBuiltinOperatorCandidates
parameter_list|(
name|OverloadedOperatorKind
name|Op
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
name|void
name|AddArgumentDependentLookupCandidates
parameter_list|(
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
name|OverloadCandidateSet
modifier|&
name|CandidateSet
parameter_list|)
function_decl|;
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
parameter_list|)
function_decl|;
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
name|void
name|PrintOverloadCandidates
parameter_list|(
name|OverloadCandidateSet
modifier|&
name|CandidateSet
parameter_list|,
name|bool
name|OnlyViable
parameter_list|)
function_decl|;
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
parameter_list|)
function_decl|;
name|void
name|FixOverloadedFunctionReference
parameter_list|(
name|Expr
modifier|*
name|E
parameter_list|,
name|FunctionDecl
modifier|*
name|Fn
parameter_list|)
function_decl|;
name|FunctionDecl
modifier|*
name|ResolveOverloadedCallFn
parameter_list|(
name|Expr
modifier|*
name|Fn
parameter_list|,
name|NamedDecl
modifier|*
name|Callee
parameter_list|,
name|DeclarationName
name|UnqualifiedName
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
parameter_list|,
name|bool
modifier|&
name|ArgumentDependentLookup
parameter_list|)
function_decl|;
name|OwningExprResult
name|CreateOverloadedUnaryOp
parameter_list|(
name|SourceLocation
name|OpLoc
parameter_list|,
name|unsigned
name|Opc
parameter_list|,
name|FunctionSet
modifier|&
name|Functions
parameter_list|,
name|ExprArg
name|input
parameter_list|)
function_decl|;
name|OwningExprResult
name|CreateOverloadedBinOp
parameter_list|(
name|SourceLocation
name|OpLoc
parameter_list|,
name|unsigned
name|Opc
parameter_list|,
name|FunctionSet
modifier|&
name|Functions
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
modifier|*
name|CommaLocs
parameter_list|,
name|SourceLocation
name|RParenLoc
parameter_list|)
function_decl|;
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
name|SourceLocation
name|MemberLoc
parameter_list|,
name|IdentifierInfo
modifier|&
name|Member
parameter_list|)
function_decl|;
comment|/// Helpers for dealing with function parameters.
name|bool
name|CheckParmsForFunctionDef
parameter_list|(
name|FunctionDecl
modifier|*
name|FD
parameter_list|)
function_decl|;
name|void
name|CheckCXXDefaultArguments
parameter_list|(
name|FunctionDecl
modifier|*
name|FD
parameter_list|)
function_decl|;
name|void
name|CheckExtraCXXDefaultArguments
parameter_list|(
name|Declarator
modifier|&
name|D
parameter_list|)
function_decl|;
name|Scope
modifier|*
name|getNonFieldDeclScope
parameter_list|(
name|Scope
modifier|*
name|S
parameter_list|)
function_decl|;
comment|/// \name Name lookup
comment|///
comment|/// These routines provide name lookup that is used during semantic
comment|/// analysis to resolve the various kinds of names (identifiers,
comment|/// overloaded operator names, constructor names, etc.) into zero or
comment|/// more declarations within a particular scope. The major entry
comment|/// points are LookupName, which performs unqualified name lookup,
comment|/// and LookupQualifiedName, which performs qualified name lookup.
comment|///
comment|/// All name lookup is performed based on some specific criteria,
comment|/// which specify what names will be visible to name lookup and how
comment|/// far name lookup should work. These criteria are important both
comment|/// for capturing language semantics (certain lookups will ignore
comment|/// certain names, for example) and for performance, since name
comment|/// lookup is often a bottleneck in the compilation of C++. Name
comment|/// lookup criteria is specified via the LookupCriteria enumeration.
comment|///
comment|/// The results of name lookup can vary based on the kind of name
comment|/// lookup performed, the current language, and the translation
comment|/// unit. In C, for example, name lookup will either return nothing
comment|/// (no entity found) or a single declaration. In C++, name lookup
comment|/// can additionally refer to a set of overloaded functions or
comment|/// result in an ambiguity. All of the possible results of name
comment|/// lookup are captured by the LookupResult class, which provides
comment|/// the ability to distinguish among them.
comment|//@{
comment|/// @brief Describes the kind of name lookup to perform.
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
comment|/// operator in C++. This lookup completely ignores operator,
comment|/// function, and enumerator names (C++ [basic.lookup.qual]p1).
name|LookupNestedNameSpecifierName
block|,
comment|/// Look up a namespace name within a C++ using directive or
comment|/// namespace alias definition, ignoring non-namespace names (C++
comment|/// [basic.lookup.udir]p1).
name|LookupNamespaceName
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
comment|/// Look up the name of an Objective-C implementation
name|LookupObjCImplementationName
block|,
comment|/// Look up the name of an Objective-C category implementation
name|LookupObjCCategoryImplName
block|}
enum|;
comment|/// @brief Represents the results of name lookup.
comment|///
comment|/// An instance of the LookupResult class captures the results of a
comment|/// single name lookup, which can return no result (nothing found),
comment|/// a single declaration, a set of overloaded functions, or an
comment|/// ambiguity. Use the getKind() method to determine which of these
comment|/// results occurred for a given lookup.
comment|///
comment|/// Any non-ambiguous lookup can be converted into a single
comment|/// (possibly NULL) @c NamedDecl* via a conversion function or the
comment|/// getAsDecl() method. This conversion permits the common-case
comment|/// usage in C and Objective-C where name lookup will always return
comment|/// a single declaration.
struct|struct
name|LookupResult
block|{
comment|/// The kind of entity that is actually stored within the
comment|/// LookupResult object.
enum|enum
block|{
comment|/// First is a single declaration (a NamedDecl*), which may be NULL.
name|SingleDecl
block|,
comment|/// First is a single declaration (an OverloadedFunctionDecl*).
name|OverloadedDeclSingleDecl
block|,
comment|/// [First, Last) is an iterator range represented as opaque
comment|/// pointers used to reconstruct IdentifierResolver::iterators.
name|OverloadedDeclFromIdResolver
block|,
comment|/// [First, Last) is an iterator range represented as opaque
comment|/// pointers used to reconstruct DeclContext::lookup_iterators.
name|OverloadedDeclFromDeclContext
block|,
comment|/// First is a pointer to a BasePaths structure, which is owned
comment|/// by the LookupResult. Last is non-zero to indicate that the
comment|/// ambiguity is caused by two names found in base class
comment|/// subobjects of different types.
name|AmbiguousLookupStoresBasePaths
block|,
comment|/// [First, Last) is an iterator range represented as opaque
comment|/// pointers used to reconstruct new'ed Decl*[] array containing
comment|/// found ambiguous decls. LookupResult is owner of this array.
name|AmbiguousLookupStoresDecls
block|}
name|StoredKind
enum|;
comment|/// The first lookup result, whose contents depend on the kind of
comment|/// lookup result. This may be a NamedDecl* (if StoredKind ==
comment|/// SingleDecl), OverloadedFunctionDecl* (if StoredKind ==
comment|/// OverloadedDeclSingleDecl), the opaque pointer from an
comment|/// IdentifierResolver::iterator (if StoredKind ==
comment|/// OverloadedDeclFromIdResolver), a DeclContext::lookup_iterator
comment|/// (if StoredKind == OverloadedDeclFromDeclContext), or a
comment|/// BasePaths pointer (if StoredKind == AmbiguousLookupStoresBasePaths).
name|mutable
name|uintptr_t
name|First
decl_stmt|;
comment|/// The last lookup result, whose contents depend on the kind of
comment|/// lookup result. This may be unused (if StoredKind ==
comment|/// SingleDecl), it may have the same type as First (for
comment|/// overloaded function declarations), or is may be used as a
comment|/// Boolean value (if StoredKind == AmbiguousLookupStoresBasePaths).
name|mutable
name|uintptr_t
name|Last
decl_stmt|;
comment|/// Context - The context in which we will build any
comment|/// OverloadedFunctionDecl nodes needed by the conversion to
comment|/// Decl*.
name|ASTContext
modifier|*
name|Context
decl_stmt|;
comment|/// @brief The kind of entity found by name lookup.
enum|enum
name|LookupKind
block|{
comment|/// @brief No entity found met the criteria.
name|NotFound
init|=
literal|0
block|,
comment|/// @brief Name lookup found a single declaration that met the
comment|/// criteria. getAsDecl will return this declaration.
name|Found
block|,
comment|/// @brief Name lookup found a set of overloaded functions that
comment|/// met the criteria. getAsDecl will turn this set of overloaded
comment|/// functions into an OverloadedFunctionDecl.
name|FoundOverloaded
block|,
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
block|}
enum|;
specifier|static
name|LookupResult
name|CreateLookupResult
parameter_list|(
name|ASTContext
modifier|&
name|Context
parameter_list|,
name|NamedDecl
modifier|*
name|D
parameter_list|)
function_decl|;
specifier|static
name|LookupResult
name|CreateLookupResult
argument_list|(
name|ASTContext
operator|&
name|Context
argument_list|,
name|IdentifierResolver
operator|::
name|iterator
name|F
argument_list|,
name|IdentifierResolver
operator|::
name|iterator
name|L
argument_list|)
decl_stmt|;
specifier|static
name|LookupResult
name|CreateLookupResult
argument_list|(
name|ASTContext
operator|&
name|Context
argument_list|,
name|DeclContext
operator|::
name|lookup_iterator
name|F
argument_list|,
name|DeclContext
operator|::
name|lookup_iterator
name|L
argument_list|)
decl_stmt|;
specifier|static
name|LookupResult
name|CreateLookupResult
parameter_list|(
name|ASTContext
modifier|&
name|Context
parameter_list|,
name|BasePaths
modifier|*
name|Paths
parameter_list|,
name|bool
name|DifferentSubobjectTypes
parameter_list|)
block|{
name|LookupResult
name|Result
decl_stmt|;
name|Result
operator|.
name|StoredKind
operator|=
name|AmbiguousLookupStoresBasePaths
expr_stmt|;
name|Result
operator|.
name|First
operator|=
name|reinterpret_cast
operator|<
name|uintptr_t
operator|>
operator|(
name|Paths
operator|)
expr_stmt|;
name|Result
operator|.
name|Last
operator|=
name|DifferentSubobjectTypes
condition|?
literal|1
else|:
literal|0
expr_stmt|;
name|Result
operator|.
name|Context
operator|=
operator|&
name|Context
expr_stmt|;
return|return
name|Result
return|;
block|}
name|template
operator|<
name|typename
name|Iterator
operator|>
specifier|static
name|LookupResult
name|CreateLookupResult
argument_list|(
argument|ASTContext&Context
argument_list|,
argument|Iterator B
argument_list|,
argument|std::size_t Len
argument_list|)
block|{
name|NamedDecl
operator|*
operator|*
name|Array
operator|=
name|new
name|NamedDecl
operator|*
index|[
name|Len
index|]
block|;
for|for
control|(
name|std
operator|::
name|size_t
name|Idx
operator|=
literal|0
init|;
name|Idx
operator|<
name|Len
condition|;
operator|++
name|Idx
operator|,
operator|++
name|B
control|)
name|Array
index|[
name|Idx
index|]
operator|=
operator|*
name|B
expr_stmt|;
name|LookupResult
name|Result
expr_stmt|;
name|Result
operator|.
name|StoredKind
operator|=
name|AmbiguousLookupStoresDecls
expr_stmt|;
name|Result
operator|.
name|First
operator|=
name|reinterpret_cast
operator|<
name|uintptr_t
operator|>
operator|(
name|Array
operator|)
expr_stmt|;
name|Result
operator|.
name|Last
operator|=
name|reinterpret_cast
operator|<
name|uintptr_t
operator|>
operator|(
name|Array
operator|+
name|Len
operator|)
expr_stmt|;
name|Result
operator|.
name|Context
operator|=
operator|&
name|Context
expr_stmt|;
return|return
name|Result
return|;
block|}
name|LookupKind
name|getKind
argument_list|()
decl|const
struct|;
comment|/// @brief Determine whether name look found something.
name|operator
name|bool
argument_list|()
specifier|const
block|{
return|return
name|getKind
argument_list|()
operator|!=
name|NotFound
return|;
block|}
comment|/// @brief Determines whether the lookup resulted in an ambiguity.
name|bool
name|isAmbiguous
argument_list|()
specifier|const
block|{
return|return
name|StoredKind
operator|==
name|AmbiguousLookupStoresBasePaths
operator|||
name|StoredKind
operator|==
name|AmbiguousLookupStoresDecls
return|;
block|}
comment|/// @brief Allows conversion of a lookup result into a
comment|/// declaration, with the same behavior as getAsDecl.
name|operator
name|NamedDecl
operator|*
operator|(
operator|)
specifier|const
block|{
return|return
name|getAsDecl
argument_list|()
return|;
block|}
name|NamedDecl
operator|*
name|getAsDecl
argument_list|()
specifier|const
expr_stmt|;
name|BasePaths
modifier|*
name|getBasePaths
parameter_list|()
function|const;
comment|/// \brief Iterate over the results of name lookup.
comment|///
comment|/// The @c iterator class provides iteration over the results of a
comment|/// non-ambiguous name lookup.
name|class
name|iterator
block|{
comment|/// The LookupResult structure we're iterating through.
name|LookupResult
modifier|*
name|Result
decl_stmt|;
comment|/// The current position of this iterator within the sequence of
comment|/// results. This value will have the same representation as the
comment|/// @c First field in the LookupResult structure.
name|mutable
name|uintptr_t
name|Current
decl_stmt|;
name|public
label|:
typedef|typedef
name|NamedDecl
modifier|*
name|value_type
typedef|;
typedef|typedef
name|NamedDecl
modifier|*
name|reference
typedef|;
typedef|typedef
name|NamedDecl
modifier|*
name|pointer
typedef|;
typedef|typedef
name|std
operator|::
name|ptrdiff_t
name|difference_type
expr_stmt|;
typedef|typedef
name|std
operator|::
name|forward_iterator_tag
name|iterator_category
expr_stmt|;
name|iterator
argument_list|()
operator|:
name|Result
argument_list|(
literal|0
argument_list|)
operator|,
name|Current
argument_list|(
literal|0
argument_list|)
block|{ }
name|iterator
argument_list|(
argument|LookupResult *Res
argument_list|,
argument|uintptr_t Cur
argument_list|)
operator|:
name|Result
argument_list|(
name|Res
argument_list|)
operator|,
name|Current
argument_list|(
argument|Cur
argument_list|)
block|{ }
name|reference
name|operator
operator|*
operator|(
operator|)
specifier|const
expr_stmt|;
name|pointer
name|operator
operator|->
expr|(
block|)
decl|const
block|{
return|return
operator|*
operator|*
name|this
return|;
block|}
name|iterator
operator|&
name|operator
operator|++
operator|(
operator|)
expr_stmt|;
name|iterator
name|operator
operator|++
operator|(
name|int
operator|)
block|{
name|iterator
name|tmp
argument_list|(
operator|*
name|this
argument_list|)
block|;
operator|++
operator|(
operator|*
name|this
operator|)
block|;
return|return
name|tmp
return|;
block|}
name|friend
specifier|inline
name|bool
name|operator
operator|==
operator|(
name|iterator
specifier|const
operator|&
name|x
operator|,
name|iterator
specifier|const
operator|&
name|y
operator|)
block|{
return|return
name|x
operator|.
name|Current
operator|==
name|y
operator|.
name|Current
return|;
block|}
name|friend
specifier|inline
name|bool
name|operator
operator|!=
operator|(
name|iterator
specifier|const
operator|&
name|x
operator|,
name|iterator
specifier|const
operator|&
name|y
operator|)
block|{
return|return
name|x
operator|.
name|Current
operator|!=
name|y
operator|.
name|Current
return|;
block|}
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_decl_stmt
name|friend
name|class
name|iterator
decl_stmt|;
end_decl_stmt

begin_function_decl
name|iterator
name|begin
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|iterator
name|end
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/// \brief Free the memory associated with this lookup.
end_comment

begin_function_decl
name|void
name|Destroy
parameter_list|()
function_decl|;
end_function_decl

begin_label
unit|};
name|private
label|:
end_label

begin_typedef
typedef|typedef
name|llvm
operator|::
name|SmallVector
operator|<
name|LookupResult
operator|,
literal|3
operator|>
name|LookupResultsVecTy
expr_stmt|;
end_typedef

begin_expr_stmt
name|std
operator|::
name|pair
operator|<
name|bool
operator|,
name|LookupResult
operator|>
name|CppLookupName
argument_list|(
argument|Scope *S
argument_list|,
argument|DeclarationName Name
argument_list|,
argument|LookupNameKind NameKind
argument_list|,
argument|bool RedeclarationOnly
argument_list|)
expr_stmt|;
end_expr_stmt

begin_function_decl
name|ObjCMethodDecl
modifier|*
name|FindMethodInNestedImplementations
parameter_list|(
specifier|const
name|ObjCInterfaceDecl
modifier|*
name|IFace
parameter_list|,
specifier|const
name|Selector
modifier|&
name|Sel
parameter_list|)
function_decl|;
end_function_decl

begin_label
name|public
label|:
end_label

begin_comment
comment|/// Determines whether D is a suitable lookup result according to the
end_comment

begin_comment
comment|/// lookup criteria.
end_comment

begin_function
specifier|static
name|bool
name|isAcceptableLookupResult
parameter_list|(
name|NamedDecl
modifier|*
name|D
parameter_list|,
name|LookupNameKind
name|NameKind
parameter_list|,
name|unsigned
name|IDNS
parameter_list|)
block|{
switch|switch
condition|(
name|NameKind
condition|)
block|{
case|case
name|Sema
operator|::
name|LookupOrdinaryName
case|:
case|case
name|Sema
operator|::
name|LookupTagName
case|:
case|case
name|Sema
operator|::
name|LookupMemberName
case|:
case|case
name|Sema
operator|::
name|LookupRedeclarationWithLinkage
case|:
comment|// FIXME: check linkage, scoping
case|case
name|Sema
operator|::
name|LookupObjCProtocolName
case|:
case|case
name|Sema
operator|::
name|LookupObjCImplementationName
case|:
case|case
name|Sema
operator|::
name|LookupObjCCategoryImplName
case|:
return|return
name|D
operator|->
name|isInIdentifierNamespace
argument_list|(
name|IDNS
argument_list|)
return|;
case|case
name|Sema
operator|::
name|LookupOperatorName
case|:
return|return
name|D
operator|->
name|isInIdentifierNamespace
argument_list|(
name|IDNS
argument_list|)
operator|&&
operator|!
name|D
operator|->
name|getDeclContext
argument_list|()
operator|->
name|isRecord
argument_list|()
return|;
case|case
name|Sema
operator|::
name|LookupNestedNameSpecifierName
case|:
return|return
name|isa
operator|<
name|TypedefDecl
operator|>
operator|(
name|D
operator|)
operator|||
name|D
operator|->
name|isInIdentifierNamespace
argument_list|(
name|Decl
operator|::
name|IDNS_Tag
argument_list|)
return|;
case|case
name|Sema
operator|::
name|LookupNamespaceName
case|:
return|return
name|isa
operator|<
name|NamespaceDecl
operator|>
operator|(
name|D
operator|)
operator|||
name|isa
operator|<
name|NamespaceAliasDecl
operator|>
operator|(
name|D
operator|)
return|;
block|}
name|assert
argument_list|(
name|false
operator|&&
literal|"isAcceptableLookupResult always returns before this point"
argument_list|)
expr_stmt|;
return|return
name|false
return|;
block|}
end_function

begin_function_decl
name|LookupResult
name|LookupName
parameter_list|(
name|Scope
modifier|*
name|S
parameter_list|,
name|DeclarationName
name|Name
parameter_list|,
name|LookupNameKind
name|NameKind
parameter_list|,
name|bool
name|RedeclarationOnly
init|=
name|false
parameter_list|,
name|bool
name|AllowBuiltinCreation
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

begin_function_decl
name|LookupResult
name|LookupQualifiedName
parameter_list|(
name|DeclContext
modifier|*
name|LookupCtx
parameter_list|,
name|DeclarationName
name|Name
parameter_list|,
name|LookupNameKind
name|NameKind
parameter_list|,
name|bool
name|RedeclarationOnly
init|=
name|false
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|LookupResult
name|LookupParsedName
parameter_list|(
name|Scope
modifier|*
name|S
parameter_list|,
specifier|const
name|CXXScopeSpec
modifier|*
name|SS
parameter_list|,
name|DeclarationName
name|Name
parameter_list|,
name|LookupNameKind
name|NameKind
parameter_list|,
name|bool
name|RedeclarationOnly
init|=
name|false
parameter_list|,
name|bool
name|AllowBuiltinCreation
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

begin_function_decl
name|ObjCProtocolDecl
modifier|*
name|LookupProtocol
parameter_list|(
name|IdentifierInfo
modifier|*
name|II
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ObjCImplementationDecl
modifier|*
name|LookupObjCImplementation
parameter_list|(
name|IdentifierInfo
modifier|*
name|II
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ObjCCategoryImplDecl
modifier|*
name|LookupObjCCategoryImpl
parameter_list|(
name|IdentifierInfo
modifier|*
name|II
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
name|FunctionSet
modifier|&
name|Functions
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
name|Expr
modifier|*
modifier|*
name|Args
parameter_list|,
name|unsigned
name|NumArgs
parameter_list|,
name|FunctionSet
modifier|&
name|Functions
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
parameter_list|,
name|DeclarationName
name|Name
parameter_list|,
name|SourceLocation
name|NameLoc
parameter_list|,
name|SourceRange
name|LookupRange
init|=
name|SourceRange
argument_list|()
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
name|Id
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
name|QualifiedIdConformsQualifiedId
parameter_list|(
name|QualType
name|LHS
parameter_list|,
name|QualType
name|RHS
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|NamespaceDecl
modifier|*
name|GetStdNamespace
parameter_list|()
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
name|ObjCInterfaceDecl
operator|*
name|IDecl
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
name|ExprArg
name|Cond
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
name|ExprArg
name|Second
parameter_list|,
name|ExprArg
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
name|FullExprArg
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

begin_decl_stmt
name|virtual
name|OwningStmtResult
name|ActOnAsmStmt
argument_list|(
name|SourceLocation
name|AsmLoc
argument_list|,
name|bool
name|IsSimple
argument_list|,
name|bool
name|IsVolatile
argument_list|,
name|unsigned
name|NumOutputs
argument_list|,
name|unsigned
name|NumInputs
argument_list|,
name|std
operator|::
name|string
operator|*
name|Names
argument_list|,
name|MultiExprArg
name|Constraints
argument_list|,
name|MultiExprArg
name|Exprs
argument_list|,
name|ExprArg
name|AsmString
argument_list|,
name|MultiExprArg
name|Clobbers
argument_list|,
name|SourceLocation
name|RParenLoc
argument_list|)
decl_stmt|;
end_decl_stmt

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
parameter_list|,
name|StmtArg
name|CatchList
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
name|StmtArg
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

begin_function
name|virtual
name|bool
name|setUnevaluatedOperand
parameter_list|(
name|bool
name|UnevaluatedOperand
parameter_list|)
block|{
name|bool
name|Result
init|=
name|InUnevaluatedOperand
decl_stmt|;
name|InUnevaluatedOperand
operator|=
name|UnevaluatedOperand
expr_stmt|;
return|return
name|Result
return|;
block|}
end_function

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
name|ActOnIdentifierExpr
parameter_list|(
name|Scope
modifier|*
name|S
parameter_list|,
name|SourceLocation
name|Loc
parameter_list|,
name|IdentifierInfo
modifier|&
name|II
parameter_list|,
name|bool
name|HasTrailingLParen
parameter_list|,
specifier|const
name|CXXScopeSpec
modifier|*
name|SS
init|=
literal|0
parameter_list|,
name|bool
name|isAddressOfOperand
init|=
name|false
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|virtual
name|OwningExprResult
name|ActOnCXXOperatorFunctionIdExpr
parameter_list|(
name|Scope
modifier|*
name|S
parameter_list|,
name|SourceLocation
name|OperatorLoc
parameter_list|,
name|OverloadedOperatorKind
name|Op
parameter_list|,
name|bool
name|HasTrailingLParen
parameter_list|,
specifier|const
name|CXXScopeSpec
modifier|&
name|SS
parameter_list|,
name|bool
name|isAddressOfOperand
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|virtual
name|OwningExprResult
name|ActOnCXXConversionFunctionExpr
parameter_list|(
name|Scope
modifier|*
name|S
parameter_list|,
name|SourceLocation
name|OperatorLoc
parameter_list|,
name|TypeTy
modifier|*
name|Ty
parameter_list|,
name|bool
name|HasTrailingLParen
parameter_list|,
specifier|const
name|CXXScopeSpec
modifier|&
name|SS
parameter_list|,
name|bool
name|isAddressOfOperand
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|DeclRefExpr
modifier|*
name|BuildDeclRefExpr
parameter_list|(
name|NamedDecl
modifier|*
name|D
parameter_list|,
name|QualType
name|Ty
parameter_list|,
name|SourceLocation
name|Loc
parameter_list|,
name|bool
name|TypeDependent
parameter_list|,
name|bool
name|ValueDependent
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
name|ActOnDeclarationNameExpr
parameter_list|(
name|Scope
modifier|*
name|S
parameter_list|,
name|SourceLocation
name|Loc
parameter_list|,
name|DeclarationName
name|Name
parameter_list|,
name|bool
name|HasTrailingLParen
parameter_list|,
specifier|const
name|CXXScopeSpec
modifier|*
name|SS
parameter_list|,
name|bool
name|isAddressOfOperand
init|=
name|false
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
name|QualType
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

begin_decl_stmt
name|virtual
name|OwningExprResult
name|ActOnMemberReferenceExpr
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
name|SourceLocation
name|MemberLoc
argument_list|,
name|IdentifierInfo
operator|&
name|Member
argument_list|,
name|DeclPtrTy
name|ImplDecl
argument_list|)
decl_stmt|;
end_decl_stmt

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
name|virtual
name|OwningExprResult
name|ActOnCastExpr
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
specifier|const
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
specifier|const
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
name|virtual
name|DeclPtrTy
name|ActOnUsingDeclaration
parameter_list|(
name|Scope
modifier|*
name|CurScope
parameter_list|,
name|SourceLocation
name|UsingLoc
parameter_list|,
specifier|const
name|CXXScopeSpec
modifier|&
name|SS
parameter_list|,
name|SourceLocation
name|IdentLoc
parameter_list|,
name|IdentifierInfo
modifier|*
name|TargetName
parameter_list|,
name|AttributeList
modifier|*
name|AttrList
parameter_list|,
name|bool
name|IsTypeName
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
name|void
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
name|QualType
name|DeclInitType
parameter_list|,
name|Expr
modifier|*
modifier|*
name|Exprs
parameter_list|,
name|unsigned
name|NumExprs
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// DefineImplicitDefaultConstructor - Checks for feasibilityt of
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

begin_comment
comment|/// RemoveOutermostTemporaryBinding - Remove and destroy the outermost
end_comment

begin_comment
comment|/// CXXBindToTemporaryExpr if necessary. This is used when we want to not
end_comment

begin_comment
comment|/// destroy a temporary when a full expression has been evaluated.
end_comment

begin_comment
comment|/// For example:
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// const T& t = T(10, T());
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Here the outermost T needs to be destroyed when t goes out of scope, but
end_comment

begin_comment
comment|/// the innermost T needs to be destroyed when the expr has been evaluated.
end_comment

begin_function_decl
name|Expr
modifier|*
name|RemoveOutermostTemporaryBinding
parameter_list|(
name|Expr
modifier|*
name|E
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// InitializationKind - Represents which kind of C++ initialization
end_comment

begin_comment
comment|/// [dcl.init] a routine is to perform.
end_comment

begin_enum
enum|enum
name|InitializationKind
block|{
name|IK_Direct
block|,
comment|///< Direct initialization
name|IK_Copy
block|,
comment|///< Copy initialization
name|IK_Default
comment|///< Default initialization
block|}
enum|;
end_enum

begin_function_decl
name|CXXConstructorDecl
modifier|*
name|PerformInitializationByConstructor
parameter_list|(
name|QualType
name|ClassType
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
name|Loc
parameter_list|,
name|SourceRange
name|Range
parameter_list|,
name|DeclarationName
name|InitEntity
parameter_list|,
name|InitializationKind
name|Kind
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
name|bool
name|ParenTypeId
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
name|bool
name|ParenTypeId
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

begin_comment
comment|/// ActOnCXXConditionDeclarationExpr - Parsed a condition declaration of a
end_comment

begin_comment
comment|/// C++ if/switch/while/for statement.
end_comment

begin_comment
comment|/// e.g: "if (int x = f()) {...}"
end_comment

begin_function_decl
name|virtual
name|OwningExprResult
name|ActOnCXXConditionDeclarationExpr
parameter_list|(
name|Scope
modifier|*
name|S
parameter_list|,
name|SourceLocation
name|StartLoc
parameter_list|,
name|Declarator
modifier|&
name|D
parameter_list|,
name|SourceLocation
name|EqualLoc
parameter_list|,
name|ExprArg
name|AssignExprVal
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
parameter_list|,
name|bool
name|ShouldDestroyTemporaries
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

begin_function_decl
name|bool
name|RequireCompleteDeclContext
parameter_list|(
specifier|const
name|CXXScopeSpec
modifier|&
name|SS
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

begin_comment
comment|/// ActOnCXXNestedNameSpecifier - Called during parsing of a
end_comment

begin_comment
comment|/// nested-name-specifier. e.g. for "foo::bar::" we parsed "foo::" and now
end_comment

begin_comment
comment|/// we want to resolve "bar::". 'SS' is empty or the previously parsed
end_comment

begin_comment
comment|/// nested-name part ("foo::"), 'IdLoc' is the source location of 'bar',
end_comment

begin_comment
comment|/// 'CCLoc' is the location of '::' and 'II' is the identifier for 'bar'.
end_comment

begin_comment
comment|/// Returns a CXXScopeTy* object representing the C++ scope.
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
name|SourceLocation
name|IdLoc
parameter_list|,
name|SourceLocation
name|CCLoc
parameter_list|,
name|IdentifierInfo
modifier|&
name|II
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
name|void
name|ActOnCXXEnterDeclaratorScope
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
name|QualType
name|EncodedType
parameter_list|,
name|SourceLocation
name|RParenLoc
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

begin_function_decl
name|virtual
name|DeclPtrTy
name|ActOnStartLinkageSpecification
parameter_list|(
name|Scope
modifier|*
name|S
parameter_list|,
name|SourceLocation
name|ExternLoc
parameter_list|,
name|SourceLocation
name|LangLoc
parameter_list|,
specifier|const
name|char
modifier|*
name|Lang
parameter_list|,
name|unsigned
name|StrSize
parameter_list|,
name|SourceLocation
name|LBraceLoc
parameter_list|)
function_decl|;
end_function_decl

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
name|ExprTy
modifier|*
name|BitfieldWidth
parameter_list|,
name|ExprTy
modifier|*
name|Init
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
name|IdentifierInfo
modifier|*
name|MemberOrBase
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
name|virtual
name|bool
name|ActOnFriendDecl
parameter_list|(
name|Scope
modifier|*
name|S
parameter_list|,
name|SourceLocation
name|FriendLoc
parameter_list|,
name|DeclPtrTy
name|Dcl
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
name|FunctionDecl
operator|::
name|StorageClass
operator|&
name|SC
argument_list|)
decl_stmt|;
end_decl_stmt

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
name|BasePaths
modifier|&
name|Paths
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|LookupInBases
parameter_list|(
name|CXXRecordDecl
modifier|*
name|Class
parameter_list|,
specifier|const
name|MemberLookupCriteria
modifier|&
name|Criteria
parameter_list|,
name|BasePaths
modifier|&
name|Paths
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
parameter_list|)
function_decl|;
end_function_decl

begin_expr_stmt
name|std
operator|::
name|string
name|getAmbiguousPathsDisplayString
argument_list|(
name|BasePaths
operator|&
name|Paths
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// CheckReturnTypeCovariance - Checks whether two types are covariant,
end_comment

begin_comment
comment|/// according to C++ [class.virtual]p5.
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
comment|//===--------------------------------------------------------------------===//
end_comment

begin_comment
comment|// C++ Access Control
end_comment

begin_comment
comment|//
end_comment

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
name|bool
name|CheckBaseClassAccess
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
name|BasePaths
modifier|&
name|Paths
parameter_list|,
name|SourceLocation
name|AccessLoc
parameter_list|,
name|DeclarationName
name|Name
parameter_list|)
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
name|virtual
name|TemplateNameKind
name|isTemplateName
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
name|TemplateTy
modifier|&
name|Template
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
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|virtual
name|void
name|ActOnTypeParameterDefault
parameter_list|(
name|DeclPtrTy
name|TypeParam
parameter_list|,
name|SourceLocation
name|EqualLoc
parameter_list|,
name|SourceLocation
name|DefaultLoc
parameter_list|,
name|TypeTy
modifier|*
name|Default
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
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|virtual
name|void
name|ActOnNonTypeTemplateParameterDefault
parameter_list|(
name|DeclPtrTy
name|TemplateParam
parameter_list|,
name|SourceLocation
name|EqualLoc
parameter_list|,
name|ExprArg
name|Default
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
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|virtual
name|void
name|ActOnTemplateTemplateParameterDefault
parameter_list|(
name|DeclPtrTy
name|TemplateParam
parameter_list|,
name|SourceLocation
name|EqualLoc
parameter_list|,
name|ExprArg
name|Default
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
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|virtual
name|DeclResult
name|ActOnClassTemplate
parameter_list|(
name|Scope
modifier|*
name|S
parameter_list|,
name|unsigned
name|TagSpec
parameter_list|,
name|TagKind
name|TK
parameter_list|,
name|SourceLocation
name|KWLoc
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
name|NameLoc
parameter_list|,
name|AttributeList
modifier|*
name|Attr
parameter_list|,
name|MultiTemplateParamsArg
name|TemplateParameterLists
parameter_list|,
name|AccessSpecifier
name|AS
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
name|SourceLocation
name|LAngleLoc
parameter_list|,
specifier|const
name|TemplateArgument
modifier|*
name|TemplateArgs
parameter_list|,
name|unsigned
name|NumTemplateArgs
parameter_list|,
name|SourceLocation
name|RAngleLoc
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
modifier|*
name|TemplateArgLocs
parameter_list|,
name|SourceLocation
name|RAngleLoc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|virtual
name|TemplateTy
name|ActOnDependentTemplateName
parameter_list|(
name|SourceLocation
name|TemplateKWLoc
parameter_list|,
specifier|const
name|IdentifierInfo
modifier|&
name|Name
parameter_list|,
name|SourceLocation
name|NameLoc
parameter_list|,
specifier|const
name|CXXScopeSpec
modifier|&
name|SS
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|CheckClassTemplateSpecializationScope
parameter_list|(
name|ClassTemplateDecl
modifier|*
name|ClassTemplate
parameter_list|,
name|ClassTemplateSpecializationDecl
modifier|*
name|PrevDecl
parameter_list|,
name|SourceLocation
name|TemplateNameLoc
parameter_list|,
name|SourceRange
name|ScopeSpecifierRange
parameter_list|,
name|bool
name|PartialSpecialization
parameter_list|,
name|bool
name|ExplicitInstantiation
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
name|TagKind
name|TK
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
modifier|*
name|TemplateArgLocs
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
name|DeclResult
name|ActOnExplicitInstantiation
parameter_list|(
name|Scope
modifier|*
name|S
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
modifier|*
name|TemplateArgLocs
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
name|SourceLocation
name|LAngleLoc
parameter_list|,
specifier|const
name|TemplateArgument
modifier|*
name|TemplateArgs
parameter_list|,
name|unsigned
name|NumTemplateArgs
parameter_list|,
name|SourceLocation
name|RAngleLoc
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
name|TemplateArgument
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
name|QualType
name|Arg
parameter_list|,
name|SourceLocation
name|ArgLoc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|CheckTemplateArgumentAddressOfObjectOrFunction
parameter_list|(
name|Expr
modifier|*
name|Arg
parameter_list|,
name|NamedDecl
modifier|*
modifier|&
name|Entity
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
name|NamedDecl
modifier|*
modifier|&
name|Member
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
name|DeclRefExpr
modifier|*
name|Arg
parameter_list|)
function_decl|;
end_function_decl

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
name|bool
name|IsTemplateTemplateParm
init|=
name|false
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
name|MultiTemplateParamsArg
modifier|&
name|TemplateParameterLists
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
name|NestedNameSpecifier
modifier|*
name|NNS
parameter_list|,
specifier|const
name|IdentifierInfo
modifier|&
name|II
parameter_list|,
name|SourceRange
name|Range
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
name|ASTContext
operator|&
name|Context
argument_list|)
operator|:
name|Context
argument_list|(
name|Context
argument_list|)
operator|,
name|Deduced
argument_list|(
literal|0
argument_list|)
block|{ }
operator|~
name|TemplateDeductionInfo
argument_list|()
block|{
comment|// FIXME: if (Deduced) Deduced->Destroy(Context);
block|}
comment|/// \brief Take ownership of the deduced template argument list.
name|TemplateArgumentList
operator|*
name|take
argument_list|()
block|{
name|TemplateArgumentList
operator|*
name|Result
operator|=
name|Deduced
block|;
name|Deduced
operator|=
literal|0
block|;
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
name|void
name|MarkDeducedTemplateParameters
argument_list|(
specifier|const
name|TemplateArgumentList
operator|&
name|TemplateArgs
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
specifier|const
name|TemplateArgumentList
modifier|&
name|getTemplateInstantiationArgs
parameter_list|(
name|NamedDecl
modifier|*
name|D
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
comment|/// We are performing template argument deduction for a class
comment|/// template partial specialization. The Entity is the class
comment|/// template partial specialization, and
comment|/// TemplateArgs/NumTemplateArgs provides the deduced template
comment|/// arguments.
comment|/// FIXME: Use a TemplateArgumentList
name|PartialSpecDeductionInstantiation
block|}
name|Kind
enum|;
comment|/// \brief The point of instantiation within the source code.
name|SourceLocation
name|PointOfInstantiation
decl_stmt|;
comment|/// \brief The entity that is being instantiated.
name|uintptr_t
name|Entity
decl_stmt|;
comment|// \brief If this the instantiation of a default template
comment|// argument, the list of template arguments.
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
name|DefaultTemplateArgumentInstantiation
case|:
case|case
name|PartialSpecDeductionInstantiation
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
comment|/// \brief The outer scope, in which contains local variable
comment|/// definitions from some other instantiation (that is not
comment|/// relevant to this particular scope).
name|LocalInstantiationScope
modifier|*
name|Outer
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
name|Outer
argument_list|(
argument|SemaRef.CurrentInstantiationScope
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
name|SemaRef
operator|.
name|CurrentInstantiationScope
operator|=
name|Outer
block|;     }
name|Decl
operator|*
name|getInstantiationOf
argument_list|(
argument|const Decl *D
argument_list|)
block|{
name|Decl
operator|*
name|Result
operator|=
name|LocalDecls
index|[
name|D
index|]
block|;
name|assert
argument_list|(
name|Result
operator|&&
literal|"declaration was not instantiated in this scope!"
argument_list|)
block|;
return|return
name|Result
return|;
block|}
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
block|{
name|Decl
modifier|*
modifier|&
name|Stored
init|=
name|LocalDecls
index|[
name|D
index|]
decl_stmt|;
name|assert
argument_list|(
operator|!
name|Stored
operator|&&
literal|"Already instantiated this local"
argument_list|)
expr_stmt|;
name|Stored
operator|=
name|Inst
expr_stmt|;
block|}
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

begin_function_decl
name|QualType
name|InstantiateType
parameter_list|(
name|QualType
name|T
parameter_list|,
specifier|const
name|TemplateArgumentList
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
name|OwningExprResult
name|InstantiateExpr
parameter_list|(
name|Expr
modifier|*
name|E
parameter_list|,
specifier|const
name|TemplateArgumentList
modifier|&
name|TemplateArgs
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|OwningStmtResult
name|InstantiateStmt
parameter_list|(
name|Stmt
modifier|*
name|S
parameter_list|,
specifier|const
name|TemplateArgumentList
modifier|&
name|TemplateArgs
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|OwningStmtResult
name|InstantiateCompoundStmt
parameter_list|(
name|CompoundStmt
modifier|*
name|S
parameter_list|,
specifier|const
name|TemplateArgumentList
modifier|&
name|TemplateArgs
parameter_list|,
name|bool
name|isStmtExpr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|Decl
modifier|*
name|InstantiateDecl
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
name|TemplateArgumentList
modifier|&
name|TemplateArgs
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|InstantiateBaseSpecifiers
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
name|TemplateArgumentList
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
name|TemplateArgumentList
modifier|&
name|TemplateArgs
parameter_list|,
name|bool
name|ExplicitInstantiation
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|InstantiateClassTemplateSpecialization
parameter_list|(
name|ClassTemplateSpecializationDecl
modifier|*
name|ClassTemplateSpec
parameter_list|,
name|bool
name|ExplicitInstantiation
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
name|TemplateArgumentList
modifier|&
name|TemplateArgs
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
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|NestedNameSpecifier
modifier|*
name|InstantiateNestedNameSpecifier
parameter_list|(
name|NestedNameSpecifier
modifier|*
name|NNS
parameter_list|,
name|SourceRange
name|Range
parameter_list|,
specifier|const
name|TemplateArgumentList
modifier|&
name|TemplateArgs
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|TemplateName
name|InstantiateTemplateName
parameter_list|(
name|TemplateName
name|Name
parameter_list|,
name|SourceLocation
name|Loc
parameter_list|,
specifier|const
name|TemplateArgumentList
modifier|&
name|TemplateArgs
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|TemplateArgument
name|Instantiate
parameter_list|(
name|TemplateArgument
name|Arg
parameter_list|,
specifier|const
name|TemplateArgumentList
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
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|InstantiateVariableDefinition
parameter_list|(
name|VarDecl
modifier|*
name|Var
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|NamedDecl
modifier|*
name|InstantiateCurrentDeclRef
parameter_list|(
name|NamedDecl
modifier|*
name|D
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|// Simple function for cloning expressions.
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|>
name|OwningExprResult
name|Clone
argument_list|(
argument|T *E
argument_list|)
block|{
name|assert
argument_list|(
operator|!
name|E
operator|->
name|isValueDependent
argument_list|()
operator|&&
operator|!
name|E
operator|->
name|isTypeDependent
argument_list|()
operator|&&
literal|"expression is value or type dependent!"
argument_list|)
block|;
return|return
name|Owned
argument_list|(
name|E
operator|->
name|Clone
argument_list|(
name|Context
argument_list|)
argument_list|)
return|;
block|}
end_expr_stmt

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
name|QualType
name|PropertyTy
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
name|MergeProtocolPropertiesIntoClass
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
name|MergeOneProtocolPropertiesIntoClass
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
name|SourceLocation
name|AtEndLoc
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
name|llvm
operator|::
name|SmallVectorImpl
operator|<
name|Declarator
operator|>
operator|&
name|Cdecls
argument_list|,
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
modifier|&
name|receiverNameLoc
parameter_list|,
name|SourceLocation
modifier|&
name|propertyNameLoc
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|// ActOnClassMessage - used for both unary and keyword messages.
end_comment

begin_comment
comment|// ArgExprs is optional - if it is present, the number of expressions
end_comment

begin_comment
comment|// is obtained from NumArgs.
end_comment

begin_function_decl
name|virtual
name|ExprResult
name|ActOnClassMessage
parameter_list|(
name|Scope
modifier|*
name|S
parameter_list|,
name|IdentifierInfo
modifier|*
name|receivingClassName
parameter_list|,
name|Selector
name|Sel
parameter_list|,
name|SourceLocation
name|lbrac
parameter_list|,
name|SourceLocation
name|receiverLoc
parameter_list|,
name|SourceLocation
name|selectorLoc
parameter_list|,
name|SourceLocation
name|rbrac
parameter_list|,
name|ExprTy
modifier|*
modifier|*
name|ArgExprs
parameter_list|,
name|unsigned
name|NumArgs
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|// ActOnInstanceMessage - used for both unary and keyword messages.
end_comment

begin_comment
comment|// ArgExprs is optional - if it is present, the number of expressions
end_comment

begin_comment
comment|// is obtained from NumArgs.
end_comment

begin_function_decl
name|virtual
name|ExprResult
name|ActOnInstanceMessage
parameter_list|(
name|ExprTy
modifier|*
name|receiver
parameter_list|,
name|Selector
name|Sel
parameter_list|,
name|SourceLocation
name|lbrac
parameter_list|,
name|SourceLocation
name|receiverLoc
parameter_list|,
name|SourceLocation
name|rbrac
parameter_list|,
name|ExprTy
modifier|*
modifier|*
name|ArgExprs
parameter_list|,
name|unsigned
name|NumArgs
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
name|ExprTy
modifier|*
modifier|*
name|Exprs
parameter_list|,
name|unsigned
name|NumExprs
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
comment|/// getPragmaPackAlignment() - Return the current alignment as specified by
end_comment

begin_comment
comment|/// the current #pragma pack directive, or 0 if none is currently active.
end_comment

begin_expr_stmt
name|unsigned
name|getPragmaPackAlignment
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt

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
comment|/// ImpCastExprToType - If Expr is not of type 'Type', insert an implicit
end_comment

begin_comment
comment|/// cast.  If there is already an implicit cast, merge into the existing one.
end_comment

begin_comment
comment|/// If isLvalue, the result of the cast is an lvalue.
end_comment

begin_function_decl
name|void
name|ImpCastExprToType
parameter_list|(
name|Expr
modifier|*
modifier|&
name|Expr
parameter_list|,
name|QualType
name|Type
parameter_list|,
name|bool
name|isLvalue
init|=
name|false
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
block|}
enum|;
end_enum

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
comment|/// UsualArithmeticConversionsType - handles the various conversions
end_comment

begin_comment
comment|/// that are common to binary operators (C99 6.3.1.8, C++ [expr]p9)
end_comment

begin_comment
comment|/// and returns the result type of that conversion.
end_comment

begin_function_decl
name|QualType
name|UsualArithmeticConversionsType
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
specifier|const
name|char
modifier|*
name|Flavor
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
name|char
modifier|*
name|Flavor
parameter_list|,
name|bool
name|AllowExplicit
init|=
name|false
parameter_list|,
name|bool
name|Elidable
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
name|ImplicitConversionSequence
modifier|&
name|ICS
parameter_list|,
specifier|const
name|char
modifier|*
name|Flavor
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
specifier|const
name|char
modifier|*
name|Flavor
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
init|=
name|false
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
name|Expr
modifier|*
modifier|&
name|E1
parameter_list|,
name|Expr
modifier|*
modifier|&
name|E2
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|// C++ 5.9
end_comment

begin_comment
comment|/// type checking for vector binary operators.
end_comment

begin_function_decl
specifier|inline
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
specifier|inline
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
name|IdentifierInfo
modifier|&
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
name|CheckInitializerTypes
parameter_list|(
name|Expr
modifier|*
modifier|&
name|simpleInit_or_initList
parameter_list|,
name|QualType
modifier|&
name|declType
parameter_list|,
name|SourceLocation
name|InitLoc
parameter_list|,
name|DeclarationName
name|InitEntity
parameter_list|,
name|bool
name|DirectInit
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|CheckInitList
parameter_list|(
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

begin_function_decl
name|bool
name|CheckValueInitialization
parameter_list|(
name|QualType
name|Type
parameter_list|,
name|SourceLocation
name|Loc
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

begin_function_decl
name|bool
name|CheckReferenceInit
parameter_list|(
name|Expr
modifier|*
modifier|&
name|simpleInit_or_initList
parameter_list|,
name|QualType
name|declType
parameter_list|,
name|ImplicitConversionSequence
modifier|*
name|ICS
init|=
literal|0
parameter_list|,
name|bool
name|SuppressUserConversions
init|=
name|false
parameter_list|,
name|bool
name|AllowExplicit
init|=
name|false
parameter_list|,
name|bool
name|ForceRValue
init|=
name|false
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// CheckCastTypes - Check type constraints for casting between types.
end_comment

begin_function_decl
name|bool
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
modifier|&
name|CastExpr
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

begin_function_decl
name|bool
name|ObjCQualifiedIdTypesAreCompatible
parameter_list|(
name|QualType
name|LHS
parameter_list|,
name|QualType
name|RHS
parameter_list|,
name|bool
name|ForCompare
parameter_list|)
function_decl|;
end_function_decl

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
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|//===--------------------------------------------------------------------===//
end_comment

begin_comment
comment|// Extra semantic analysis beyond the C type system
end_comment

begin_label
name|private
label|:
end_label

begin_expr_stmt
name|Action
operator|::
name|OwningExprResult
name|CheckFunctionCall
argument_list|(
name|FunctionDecl
operator|*
name|FDecl
argument_list|,
name|CallExpr
operator|*
name|TheCall
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|Action
operator|::
name|OwningExprResult
name|CheckBlockCall
argument_list|(
name|NamedDecl
operator|*
name|NDecl
argument_list|,
name|CallExpr
operator|*
name|TheCall
argument_list|)
expr_stmt|;
end_expr_stmt

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
name|SemaBuiltinStackAddress
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
name|bool
name|SemaBuiltinAtomicOverloaded
parameter_list|(
name|CallExpr
modifier|*
name|TheCall
parameter_list|)
function_decl|;
end_function_decl

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

