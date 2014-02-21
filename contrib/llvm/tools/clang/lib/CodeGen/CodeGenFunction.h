begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- CodeGenFunction.h - Per-Function state for LLVM CodeGen -*- C++ -*-===//
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
comment|// This is the internal per-function state used for llvm translation.
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
name|CLANG_CODEGEN_CODEGENFUNCTION_H
end_ifndef

begin_define
define|#
directive|define
name|CLANG_CODEGEN_CODEGENFUNCTION_H
end_define

begin_include
include|#
directive|include
file|"CGBuilder.h"
end_include

begin_include
include|#
directive|include
file|"CGDebugInfo.h"
end_include

begin_include
include|#
directive|include
file|"CGValue.h"
end_include

begin_include
include|#
directive|include
file|"EHScopeStack.h"
end_include

begin_include
include|#
directive|include
file|"CodeGenModule.h"
end_include

begin_include
include|#
directive|include
file|"clang/AST/CharUnits.h"
end_include

begin_include
include|#
directive|include
file|"clang/AST/ExprCXX.h"
end_include

begin_include
include|#
directive|include
file|"clang/AST/ExprObjC.h"
end_include

begin_include
include|#
directive|include
file|"clang/AST/Type.h"
end_include

begin_include
include|#
directive|include
file|"clang/Basic/ABI.h"
end_include

begin_include
include|#
directive|include
file|"clang/Basic/CapturedStmt.h"
end_include

begin_include
include|#
directive|include
file|"clang/Basic/TargetInfo.h"
end_include

begin_include
include|#
directive|include
file|"clang/Frontend/CodeGenOptions.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/ArrayRef.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/DenseMap.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/SmallVector.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/Debug.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/ValueHandle.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|BasicBlock
decl_stmt|;
name|class
name|LLVMContext
decl_stmt|;
name|class
name|MDNode
decl_stmt|;
name|class
name|Module
decl_stmt|;
name|class
name|SwitchInst
decl_stmt|;
name|class
name|Twine
decl_stmt|;
name|class
name|Value
decl_stmt|;
name|class
name|CallSite
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
name|BlockDecl
decl_stmt|;
name|class
name|CXXDestructorDecl
decl_stmt|;
name|class
name|CXXForRangeStmt
decl_stmt|;
name|class
name|CXXTryStmt
decl_stmt|;
name|class
name|Decl
decl_stmt|;
name|class
name|LabelDecl
decl_stmt|;
name|class
name|EnumConstantDecl
decl_stmt|;
name|class
name|FunctionDecl
decl_stmt|;
name|class
name|FunctionProtoType
decl_stmt|;
name|class
name|LabelStmt
decl_stmt|;
name|class
name|ObjCContainerDecl
decl_stmt|;
name|class
name|ObjCInterfaceDecl
decl_stmt|;
name|class
name|ObjCIvarDecl
decl_stmt|;
name|class
name|ObjCMethodDecl
decl_stmt|;
name|class
name|ObjCImplementationDecl
decl_stmt|;
name|class
name|ObjCPropertyImplDecl
decl_stmt|;
name|class
name|TargetInfo
decl_stmt|;
name|class
name|TargetCodeGenInfo
decl_stmt|;
name|class
name|VarDecl
decl_stmt|;
name|class
name|ObjCForCollectionStmt
decl_stmt|;
name|class
name|ObjCAtTryStmt
decl_stmt|;
name|class
name|ObjCAtThrowStmt
decl_stmt|;
name|class
name|ObjCAtSynchronizedStmt
decl_stmt|;
name|class
name|ObjCAutoreleasePoolStmt
decl_stmt|;
name|namespace
name|CodeGen
block|{
name|class
name|CodeGenTypes
decl_stmt|;
name|class
name|CGFunctionInfo
decl_stmt|;
name|class
name|CGRecordLayout
decl_stmt|;
name|class
name|CGBlockInfo
decl_stmt|;
name|class
name|CGCXXABI
decl_stmt|;
name|class
name|BlockFlags
decl_stmt|;
name|class
name|BlockFieldFlags
decl_stmt|;
comment|/// The kind of evaluation to perform on values of a particular
comment|/// type.  Basically, is the code in CGExprScalar, CGExprComplex, or
comment|/// CGExprAgg?
comment|///
comment|/// TODO: should vectors maybe be split out into their own thing?
enum|enum
name|TypeEvaluationKind
block|{
name|TEK_Scalar
block|,
name|TEK_Complex
block|,
name|TEK_Aggregate
block|}
enum|;
comment|/// CodeGenFunction - This class organizes the per-function state that is used
comment|/// while generating LLVM code.
name|class
name|CodeGenFunction
range|:
name|public
name|CodeGenTypeCache
block|{
name|CodeGenFunction
argument_list|(
argument|const CodeGenFunction&
argument_list|)
name|LLVM_DELETED_FUNCTION
block|;
name|void
name|operator
operator|=
operator|(
specifier|const
name|CodeGenFunction
operator|&
operator|)
name|LLVM_DELETED_FUNCTION
block|;
name|friend
name|class
name|CGCXXABI
block|;
name|public
operator|:
comment|/// A jump destination is an abstract label, branching to which may
comment|/// require a jump out through normal cleanups.
expr|struct
name|JumpDest
block|{
name|JumpDest
argument_list|()
operator|:
name|Block
argument_list|(
literal|0
argument_list|)
block|,
name|ScopeDepth
argument_list|()
block|,
name|Index
argument_list|(
literal|0
argument_list|)
block|{}
name|JumpDest
argument_list|(
argument|llvm::BasicBlock *Block
argument_list|,
argument|EHScopeStack::stable_iterator Depth
argument_list|,
argument|unsigned Index
argument_list|)
operator|:
name|Block
argument_list|(
name|Block
argument_list|)
block|,
name|ScopeDepth
argument_list|(
name|Depth
argument_list|)
block|,
name|Index
argument_list|(
argument|Index
argument_list|)
block|{}
name|bool
name|isValid
argument_list|()
specifier|const
block|{
return|return
name|Block
operator|!=
literal|0
return|;
block|}
name|llvm
operator|::
name|BasicBlock
operator|*
name|getBlock
argument_list|()
specifier|const
block|{
return|return
name|Block
return|;
block|}
name|EHScopeStack
operator|::
name|stable_iterator
name|getScopeDepth
argument_list|()
specifier|const
block|{
return|return
name|ScopeDepth
return|;
block|}
name|unsigned
name|getDestIndex
argument_list|()
specifier|const
block|{
return|return
name|Index
return|;
block|}
comment|// This should be used cautiously.
name|void
name|setScopeDepth
argument_list|(
argument|EHScopeStack::stable_iterator depth
argument_list|)
block|{
name|ScopeDepth
operator|=
name|depth
block|;     }
name|private
operator|:
name|llvm
operator|::
name|BasicBlock
operator|*
name|Block
block|;
name|EHScopeStack
operator|::
name|stable_iterator
name|ScopeDepth
block|;
name|unsigned
name|Index
block|;   }
block|;
name|CodeGenModule
operator|&
name|CGM
block|;
comment|// Per-module state.
specifier|const
name|TargetInfo
operator|&
name|Target
block|;
typedef|typedef
name|std
operator|::
name|pair
operator|<
name|llvm
operator|::
name|Value
operator|*
operator|,
name|llvm
operator|::
name|Value
operator|*
operator|>
name|ComplexPairTy
expr_stmt|;
name|CGBuilderTy
name|Builder
decl_stmt|;
comment|/// CurFuncDecl - Holds the Decl for the current outermost
comment|/// non-closure context.
specifier|const
name|Decl
modifier|*
name|CurFuncDecl
decl_stmt|;
comment|/// CurCodeDecl - This is the inner-most code context, which includes blocks.
specifier|const
name|Decl
modifier|*
name|CurCodeDecl
decl_stmt|;
specifier|const
name|CGFunctionInfo
modifier|*
name|CurFnInfo
decl_stmt|;
name|QualType
name|FnRetTy
decl_stmt|;
name|llvm
operator|::
name|Function
operator|*
name|CurFn
expr_stmt|;
comment|/// CurGD - The GlobalDecl for the current function being compiled.
name|GlobalDecl
name|CurGD
decl_stmt|;
comment|/// PrologueCleanupDepth - The cleanup depth enclosing all the
comment|/// cleanups associated with the parameters.
name|EHScopeStack
operator|::
name|stable_iterator
name|PrologueCleanupDepth
expr_stmt|;
comment|/// ReturnBlock - Unified return block.
name|JumpDest
name|ReturnBlock
decl_stmt|;
comment|/// ReturnValue - The temporary alloca to hold the return value. This is null
comment|/// iff the function has no return value.
name|llvm
operator|::
name|Value
operator|*
name|ReturnValue
expr_stmt|;
comment|/// AllocaInsertPoint - This is an instruction in the entry block before which
comment|/// we prefer to insert allocas.
name|llvm
operator|::
name|AssertingVH
operator|<
name|llvm
operator|::
name|Instruction
operator|>
name|AllocaInsertPt
expr_stmt|;
comment|/// \brief API for captured statement code generation.
name|class
name|CGCapturedStmtInfo
block|{
name|public
label|:
name|explicit
name|CGCapturedStmtInfo
argument_list|(
argument|const CapturedStmt&S
argument_list|,
argument|CapturedRegionKind K = CR_Default
argument_list|)
block|:
name|Kind
argument_list|(
name|K
argument_list|)
operator|,
name|ThisValue
argument_list|(
literal|0
argument_list|)
operator|,
name|CXXThisFieldDecl
argument_list|(
literal|0
argument_list|)
block|{
name|RecordDecl
operator|::
name|field_iterator
name|Field
operator|=
name|S
operator|.
name|getCapturedRecordDecl
argument_list|()
operator|->
name|field_begin
argument_list|()
block|;
for|for
control|(
name|CapturedStmt
operator|::
name|const_capture_iterator
name|I
operator|=
name|S
operator|.
name|capture_begin
argument_list|()
operator|,
name|E
operator|=
name|S
operator|.
name|capture_end
argument_list|()
init|;
name|I
operator|!=
name|E
condition|;
operator|++
name|I
operator|,
operator|++
name|Field
control|)
block|{
if|if
condition|(
name|I
operator|->
name|capturesThis
argument_list|()
condition|)
name|CXXThisFieldDecl
operator|=
operator|*
name|Field
expr_stmt|;
else|else
name|CaptureFields
index|[
name|I
operator|->
name|getCapturedVar
argument_list|()
index|]
operator|=
operator|*
name|Field
expr_stmt|;
block|}
block|}
name|virtual
operator|~
name|CGCapturedStmtInfo
argument_list|()
expr_stmt|;
name|CapturedRegionKind
name|getKind
argument_list|()
specifier|const
block|{
return|return
name|Kind
return|;
block|}
name|void
name|setContextValue
argument_list|(
name|llvm
operator|::
name|Value
operator|*
name|V
argument_list|)
block|{
name|ThisValue
operator|=
name|V
expr_stmt|;
block|}
comment|// \brief Retrieve the value of the context parameter.
name|llvm
operator|::
name|Value
operator|*
name|getContextValue
argument_list|()
specifier|const
block|{
return|return
name|ThisValue
return|;
block|}
comment|/// \brief Lookup the captured field decl for a variable.
specifier|const
name|FieldDecl
modifier|*
name|lookup
argument_list|(
specifier|const
name|VarDecl
operator|*
name|VD
argument_list|)
decl|const
block|{
return|return
name|CaptureFields
operator|.
name|lookup
argument_list|(
name|VD
argument_list|)
return|;
block|}
name|bool
name|isCXXThisExprCaptured
argument_list|()
specifier|const
block|{
return|return
name|CXXThisFieldDecl
operator|!=
literal|0
return|;
block|}
name|FieldDecl
operator|*
name|getThisFieldDecl
argument_list|()
specifier|const
block|{
return|return
name|CXXThisFieldDecl
return|;
block|}
comment|/// \brief Emit the captured statement body.
name|virtual
name|void
name|EmitBody
parameter_list|(
name|CodeGenFunction
modifier|&
name|CGF
parameter_list|,
name|Stmt
modifier|*
name|S
parameter_list|)
block|{
name|CGF
operator|.
name|EmitStmt
argument_list|(
name|S
argument_list|)
expr_stmt|;
block|}
comment|/// \brief Get the name of the capture helper.
name|virtual
name|StringRef
name|getHelperName
argument_list|()
specifier|const
block|{
return|return
literal|"__captured_stmt"
return|;
block|}
name|private
label|:
comment|/// \brief The kind of captured statement being generated.
name|CapturedRegionKind
name|Kind
decl_stmt|;
comment|/// \brief Keep the map between VarDecl and FieldDecl.
name|llvm
operator|::
name|SmallDenseMap
operator|<
specifier|const
name|VarDecl
operator|*
operator|,
name|FieldDecl
operator|*
operator|>
name|CaptureFields
expr_stmt|;
comment|/// \brief The base address of the captured record, passed in as the first
comment|/// argument of the parallel region function.
name|llvm
operator|::
name|Value
operator|*
name|ThisValue
expr_stmt|;
comment|/// \brief Captured 'this' type.
name|FieldDecl
modifier|*
name|CXXThisFieldDecl
decl_stmt|;
block|}
empty_stmt|;
name|CGCapturedStmtInfo
modifier|*
name|CapturedStmtInfo
decl_stmt|;
comment|/// BoundsChecking - Emit run-time bounds checks. Higher values mean
comment|/// potentially higher performance penalties.
name|unsigned
name|char
name|BoundsChecking
decl_stmt|;
comment|/// \brief Whether any type-checking sanitizers are enabled. If \c false,
comment|/// calls to EmitTypeCheck can be skipped.
name|bool
name|SanitizePerformTypeCheck
decl_stmt|;
comment|/// \brief Sanitizer options to use for this function.
specifier|const
name|SanitizerOptions
modifier|*
name|SanOpts
decl_stmt|;
comment|/// In ARC, whether we should autorelease the return value.
name|bool
name|AutoreleaseResult
decl_stmt|;
specifier|const
name|CodeGen
operator|::
name|CGBlockInfo
operator|*
name|BlockInfo
expr_stmt|;
name|llvm
operator|::
name|Value
operator|*
name|BlockPointer
expr_stmt|;
name|llvm
operator|::
name|DenseMap
operator|<
specifier|const
name|VarDecl
operator|*
operator|,
name|FieldDecl
operator|*
operator|>
name|LambdaCaptureFields
expr_stmt|;
name|FieldDecl
modifier|*
name|LambdaThisCaptureField
decl_stmt|;
comment|/// \brief A mapping from NRVO variables to the flags used to indicate
comment|/// when the NRVO has been applied to this variable.
name|llvm
operator|::
name|DenseMap
operator|<
specifier|const
name|VarDecl
operator|*
operator|,
name|llvm
operator|::
name|Value
operator|*
operator|>
name|NRVOFlags
expr_stmt|;
name|EHScopeStack
name|EHStack
decl_stmt|;
name|llvm
operator|::
name|SmallVector
operator|<
name|char
operator|,
literal|256
operator|>
name|LifetimeExtendedCleanupStack
expr_stmt|;
comment|/// Header for data within LifetimeExtendedCleanupStack.
struct|struct
name|LifetimeExtendedCleanupHeader
block|{
comment|/// The size of the following cleanup object.
name|size_t
name|Size
range|:
literal|29
decl_stmt|;
comment|/// The kind of cleanup to push: a value from the CleanupKind enumeration.
name|unsigned
name|Kind
range|:
literal|3
decl_stmt|;
name|size_t
name|getSize
argument_list|()
specifier|const
block|{
return|return
name|Size
return|;
block|}
name|CleanupKind
name|getKind
argument_list|()
specifier|const
block|{
return|return
name|static_cast
operator|<
name|CleanupKind
operator|>
operator|(
name|Kind
operator|)
return|;
block|}
block|}
struct|;
comment|/// i32s containing the indexes of the cleanup destinations.
name|llvm
operator|::
name|AllocaInst
operator|*
name|NormalCleanupDest
expr_stmt|;
name|unsigned
name|NextCleanupDestIndex
decl_stmt|;
comment|/// FirstBlockInfo - The head of a singly-linked-list of block layouts.
name|CGBlockInfo
modifier|*
name|FirstBlockInfo
decl_stmt|;
comment|/// EHResumeBlock - Unified block containing a call to llvm.eh.resume.
name|llvm
operator|::
name|BasicBlock
operator|*
name|EHResumeBlock
expr_stmt|;
comment|/// The exception slot.  All landing pads write the current exception pointer
comment|/// into this alloca.
name|llvm
operator|::
name|Value
operator|*
name|ExceptionSlot
expr_stmt|;
comment|/// The selector slot.  Under the MandatoryCleanup model, all landing pads
comment|/// write the current selector value into this alloca.
name|llvm
operator|::
name|AllocaInst
operator|*
name|EHSelectorSlot
expr_stmt|;
comment|/// Emits a landing pad for the current EH stack.
name|llvm
operator|::
name|BasicBlock
operator|*
name|EmitLandingPad
argument_list|()
expr_stmt|;
name|llvm
operator|::
name|BasicBlock
operator|*
name|getInvokeDestImpl
argument_list|()
expr_stmt|;
name|template
operator|<
name|class
name|T
operator|>
name|typename
name|DominatingValue
operator|<
name|T
operator|>
operator|::
name|saved_type
name|saveValueInCond
argument_list|(
argument|T value
argument_list|)
block|{
return|return
name|DominatingValue
operator|<
name|T
operator|>
operator|::
name|save
argument_list|(
operator|*
name|this
argument_list|,
name|value
argument_list|)
return|;
block|}
name|public
label|:
comment|/// ObjCEHValueStack - Stack of Objective-C exception values, used for
comment|/// rethrows.
name|SmallVector
operator|<
name|llvm
operator|::
name|Value
operator|*
operator|,
literal|8
operator|>
name|ObjCEHValueStack
expr_stmt|;
comment|/// A class controlling the emission of a finally block.
name|class
name|FinallyInfo
block|{
comment|/// Where the catchall's edge through the cleanup should go.
name|JumpDest
name|RethrowDest
decl_stmt|;
comment|/// A function to call to enter the catch.
name|llvm
operator|::
name|Constant
operator|*
name|BeginCatchFn
expr_stmt|;
comment|/// An i1 variable indicating whether or not the @finally is
comment|/// running for an exception.
name|llvm
operator|::
name|AllocaInst
operator|*
name|ForEHVar
expr_stmt|;
comment|/// An i8* variable into which the exception pointer to rethrow
comment|/// has been saved.
name|llvm
operator|::
name|AllocaInst
operator|*
name|SavedExnVar
expr_stmt|;
name|public
label|:
name|void
name|enter
argument_list|(
name|CodeGenFunction
operator|&
name|CGF
argument_list|,
specifier|const
name|Stmt
operator|*
name|Finally
argument_list|,
name|llvm
operator|::
name|Constant
operator|*
name|beginCatchFn
argument_list|,
name|llvm
operator|::
name|Constant
operator|*
name|endCatchFn
argument_list|,
name|llvm
operator|::
name|Constant
operator|*
name|rethrowFn
argument_list|)
decl_stmt|;
name|void
name|exit
parameter_list|(
name|CodeGenFunction
modifier|&
name|CGF
parameter_list|)
function_decl|;
block|}
empty_stmt|;
comment|/// pushFullExprCleanup - Push a cleanup to be run at the end of the
comment|/// current full-expression.  Safe against the possibility that
comment|/// we're currently inside a conditionally-evaluated expression.
name|template
operator|<
name|class
name|T
operator|,
name|class
name|A0
operator|>
name|void
name|pushFullExprCleanup
argument_list|(
argument|CleanupKind kind
argument_list|,
argument|A0 a0
argument_list|)
block|{
comment|// If we're not in a conditional branch, or if none of the
comment|// arguments requires saving, then use the unconditional cleanup.
if|if
condition|(
operator|!
name|isInConditionalBranch
argument_list|()
condition|)
return|return
name|EHStack
operator|.
name|pushCleanup
operator|<
name|T
operator|>
operator|(
name|kind
operator|,
name|a0
operator|)
return|;
name|typename
name|DominatingValue
operator|<
name|A0
operator|>
operator|::
name|saved_type
name|a0_saved
operator|=
name|saveValueInCond
argument_list|(
name|a0
argument_list|)
expr_stmt|;
typedef|typedef
name|EHScopeStack
operator|::
name|ConditionalCleanup1
operator|<
name|T
operator|,
name|A0
operator|>
name|CleanupType
expr_stmt|;
name|EHStack
operator|.
name|pushCleanup
operator|<
name|CleanupType
operator|>
operator|(
name|kind
operator|,
name|a0_saved
operator|)
expr_stmt|;
name|initFullExprCleanup
argument_list|()
expr_stmt|;
block|}
comment|/// pushFullExprCleanup - Push a cleanup to be run at the end of the
comment|/// current full-expression.  Safe against the possibility that
comment|/// we're currently inside a conditionally-evaluated expression.
name|template
operator|<
name|class
name|T
operator|,
name|class
name|A0
operator|,
name|class
name|A1
operator|>
name|void
name|pushFullExprCleanup
argument_list|(
argument|CleanupKind kind
argument_list|,
argument|A0 a0
argument_list|,
argument|A1 a1
argument_list|)
block|{
comment|// If we're not in a conditional branch, or if none of the
comment|// arguments requires saving, then use the unconditional cleanup.
if|if
condition|(
operator|!
name|isInConditionalBranch
argument_list|()
condition|)
return|return
name|EHStack
operator|.
name|pushCleanup
operator|<
name|T
operator|>
operator|(
name|kind
operator|,
name|a0
operator|,
name|a1
operator|)
return|;
name|typename
name|DominatingValue
operator|<
name|A0
operator|>
operator|::
name|saved_type
name|a0_saved
operator|=
name|saveValueInCond
argument_list|(
name|a0
argument_list|)
expr_stmt|;
name|typename
name|DominatingValue
operator|<
name|A1
operator|>
operator|::
name|saved_type
name|a1_saved
operator|=
name|saveValueInCond
argument_list|(
name|a1
argument_list|)
expr_stmt|;
typedef|typedef
name|EHScopeStack
operator|::
name|ConditionalCleanup2
operator|<
name|T
operator|,
name|A0
operator|,
name|A1
operator|>
name|CleanupType
expr_stmt|;
name|EHStack
operator|.
name|pushCleanup
operator|<
name|CleanupType
operator|>
operator|(
name|kind
operator|,
name|a0_saved
operator|,
name|a1_saved
operator|)
expr_stmt|;
name|initFullExprCleanup
argument_list|()
expr_stmt|;
block|}
end_decl_stmt

begin_comment
comment|/// pushFullExprCleanup - Push a cleanup to be run at the end of the
end_comment

begin_comment
comment|/// current full-expression.  Safe against the possibility that
end_comment

begin_comment
comment|/// we're currently inside a conditionally-evaluated expression.
end_comment

begin_expr_stmt
name|template
operator|<
name|class
name|T
operator|,
name|class
name|A0
operator|,
name|class
name|A1
operator|,
name|class
name|A2
operator|>
name|void
name|pushFullExprCleanup
argument_list|(
argument|CleanupKind kind
argument_list|,
argument|A0 a0
argument_list|,
argument|A1 a1
argument_list|,
argument|A2 a2
argument_list|)
block|{
comment|// If we're not in a conditional branch, or if none of the
comment|// arguments requires saving, then use the unconditional cleanup.
if|if
condition|(
operator|!
name|isInConditionalBranch
argument_list|()
condition|)
block|{
return|return
name|EHStack
operator|.
name|pushCleanup
operator|<
name|T
operator|>
operator|(
name|kind
operator|,
name|a0
operator|,
name|a1
operator|,
name|a2
operator|)
return|;
block|}
name|typename
name|DominatingValue
operator|<
name|A0
operator|>
operator|::
name|saved_type
name|a0_saved
operator|=
name|saveValueInCond
argument_list|(
name|a0
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|typename
name|DominatingValue
operator|<
name|A1
operator|>
operator|::
name|saved_type
name|a1_saved
operator|=
name|saveValueInCond
argument_list|(
name|a1
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|typename
name|DominatingValue
operator|<
name|A2
operator|>
operator|::
name|saved_type
name|a2_saved
operator|=
name|saveValueInCond
argument_list|(
name|a2
argument_list|)
expr_stmt|;
end_expr_stmt

begin_typedef
typedef|typedef
name|EHScopeStack
operator|::
name|ConditionalCleanup3
operator|<
name|T
operator|,
name|A0
operator|,
name|A1
operator|,
name|A2
operator|>
name|CleanupType
expr_stmt|;
end_typedef

begin_expr_stmt
name|EHStack
operator|.
name|pushCleanup
operator|<
name|CleanupType
operator|>
operator|(
name|kind
operator|,
name|a0_saved
operator|,
name|a1_saved
operator|,
name|a2_saved
operator|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|initFullExprCleanup
argument_list|()
expr_stmt|;
end_expr_stmt

begin_comment
unit|}
comment|/// pushFullExprCleanup - Push a cleanup to be run at the end of the
end_comment

begin_comment
comment|/// current full-expression.  Safe against the possibility that
end_comment

begin_comment
comment|/// we're currently inside a conditionally-evaluated expression.
end_comment

begin_expr_stmt
unit|template
operator|<
name|class
name|T
operator|,
name|class
name|A0
operator|,
name|class
name|A1
operator|,
name|class
name|A2
operator|,
name|class
name|A3
operator|>
name|void
name|pushFullExprCleanup
argument_list|(
argument|CleanupKind kind
argument_list|,
argument|A0 a0
argument_list|,
argument|A1 a1
argument_list|,
argument|A2 a2
argument_list|,
argument|A3 a3
argument_list|)
block|{
comment|// If we're not in a conditional branch, or if none of the
comment|// arguments requires saving, then use the unconditional cleanup.
if|if
condition|(
operator|!
name|isInConditionalBranch
argument_list|()
condition|)
block|{
return|return
name|EHStack
operator|.
name|pushCleanup
operator|<
name|T
operator|>
operator|(
name|kind
operator|,
name|a0
operator|,
name|a1
operator|,
name|a2
operator|,
name|a3
operator|)
return|;
block|}
name|typename
name|DominatingValue
operator|<
name|A0
operator|>
operator|::
name|saved_type
name|a0_saved
operator|=
name|saveValueInCond
argument_list|(
name|a0
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|typename
name|DominatingValue
operator|<
name|A1
operator|>
operator|::
name|saved_type
name|a1_saved
operator|=
name|saveValueInCond
argument_list|(
name|a1
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|typename
name|DominatingValue
operator|<
name|A2
operator|>
operator|::
name|saved_type
name|a2_saved
operator|=
name|saveValueInCond
argument_list|(
name|a2
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|typename
name|DominatingValue
operator|<
name|A3
operator|>
operator|::
name|saved_type
name|a3_saved
operator|=
name|saveValueInCond
argument_list|(
name|a3
argument_list|)
expr_stmt|;
end_expr_stmt

begin_typedef
typedef|typedef
name|EHScopeStack
operator|::
name|ConditionalCleanup4
operator|<
name|T
operator|,
name|A0
operator|,
name|A1
operator|,
name|A2
operator|,
name|A3
operator|>
name|CleanupType
expr_stmt|;
end_typedef

begin_expr_stmt
name|EHStack
operator|.
name|pushCleanup
operator|<
name|CleanupType
operator|>
operator|(
name|kind
operator|,
name|a0_saved
operator|,
name|a1_saved
operator|,
name|a2_saved
operator|,
name|a3_saved
operator|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|initFullExprCleanup
argument_list|()
expr_stmt|;
end_expr_stmt

begin_comment
unit|}
comment|/// \brief Queue a cleanup to be pushed after finishing the current
end_comment

begin_comment
comment|/// full-expression.
end_comment

begin_expr_stmt
unit|template
operator|<
name|class
name|T
operator|,
name|class
name|A0
operator|,
name|class
name|A1
operator|,
name|class
name|A2
operator|,
name|class
name|A3
operator|>
name|void
name|pushCleanupAfterFullExpr
argument_list|(
argument|CleanupKind Kind
argument_list|,
argument|A0 a0
argument_list|,
argument|A1 a1
argument_list|,
argument|A2 a2
argument_list|,
argument|A3 a3
argument_list|)
block|{
name|assert
argument_list|(
operator|!
name|isInConditionalBranch
argument_list|()
operator|&&
literal|"can't defer conditional cleanup"
argument_list|)
block|;
name|LifetimeExtendedCleanupHeader
name|Header
operator|=
block|{
sizeof|sizeof
argument_list|(
name|T
argument_list|)
block|,
name|Kind
block|}
block|;
name|size_t
name|OldSize
operator|=
name|LifetimeExtendedCleanupStack
operator|.
name|size
argument_list|()
block|;
name|LifetimeExtendedCleanupStack
operator|.
name|resize
argument_list|(
name|LifetimeExtendedCleanupStack
operator|.
name|size
argument_list|()
operator|+
sizeof|sizeof
argument_list|(
name|Header
argument_list|)
operator|+
name|Header
operator|.
name|Size
argument_list|)
block|;
name|char
operator|*
name|Buffer
operator|=
operator|&
name|LifetimeExtendedCleanupStack
index|[
name|OldSize
index|]
block|;
name|new
argument_list|(
argument|Buffer
argument_list|)
name|LifetimeExtendedCleanupHeader
argument_list|(
name|Header
argument_list|)
block|;
name|new
argument_list|(
argument|Buffer + sizeof(Header)
argument_list|)
name|T
argument_list|(
name|a0
argument_list|,
name|a1
argument_list|,
name|a2
argument_list|,
name|a3
argument_list|)
block|;   }
comment|/// Set up the last cleaup that was pushed as a conditional
comment|/// full-expression cleanup.
name|void
name|initFullExprCleanup
argument_list|()
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// PushDestructorCleanup - Push a cleanup to call the
end_comment

begin_comment
comment|/// complete-object destructor of an object of the given type at the
end_comment

begin_comment
comment|/// given address.  Does nothing if T is not a C++ class type with a
end_comment

begin_comment
comment|/// non-trivial destructor.
end_comment

begin_decl_stmt
name|void
name|PushDestructorCleanup
argument_list|(
name|QualType
name|T
argument_list|,
name|llvm
operator|::
name|Value
operator|*
name|Addr
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// PushDestructorCleanup - Push a cleanup to call the
end_comment

begin_comment
comment|/// complete-object variant of the given destructor on the object at
end_comment

begin_comment
comment|/// the given address.
end_comment

begin_decl_stmt
name|void
name|PushDestructorCleanup
argument_list|(
specifier|const
name|CXXDestructorDecl
operator|*
name|Dtor
argument_list|,
name|llvm
operator|::
name|Value
operator|*
name|Addr
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// PopCleanupBlock - Will pop the cleanup entry on the stack and
end_comment

begin_comment
comment|/// process all branch fixups.
end_comment

begin_function_decl
name|void
name|PopCleanupBlock
parameter_list|(
name|bool
name|FallThroughIsBranchThrough
init|=
name|false
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// DeactivateCleanupBlock - Deactivates the given cleanup block.
end_comment

begin_comment
comment|/// The block cannot be reactivated.  Pops it if it's the top of the
end_comment

begin_comment
comment|/// stack.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param DominatingIP - An instruction which is known to
end_comment

begin_comment
comment|///   dominate the current IP (if set) and which lies along
end_comment

begin_comment
comment|///   all paths of execution between the current IP and the
end_comment

begin_comment
comment|///   the point at which the cleanup comes into scope.
end_comment

begin_decl_stmt
name|void
name|DeactivateCleanupBlock
argument_list|(
name|EHScopeStack
operator|::
name|stable_iterator
name|Cleanup
argument_list|,
name|llvm
operator|::
name|Instruction
operator|*
name|DominatingIP
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// ActivateCleanupBlock - Activates an initially-inactive cleanup.
end_comment

begin_comment
comment|/// Cannot be used to resurrect a deactivated cleanup.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param DominatingIP - An instruction which is known to
end_comment

begin_comment
comment|///   dominate the current IP (if set) and which lies along
end_comment

begin_comment
comment|///   all paths of execution between the current IP and the
end_comment

begin_comment
comment|///   the point at which the cleanup comes into scope.
end_comment

begin_decl_stmt
name|void
name|ActivateCleanupBlock
argument_list|(
name|EHScopeStack
operator|::
name|stable_iterator
name|Cleanup
argument_list|,
name|llvm
operator|::
name|Instruction
operator|*
name|DominatingIP
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// \brief Enters a new scope for capturing cleanups, all of which
end_comment

begin_comment
comment|/// will be executed once the scope is exited.
end_comment

begin_decl_stmt
name|class
name|RunCleanupsScope
block|{
name|EHScopeStack
operator|::
name|stable_iterator
name|CleanupStackDepth
expr_stmt|;
name|size_t
name|LifetimeExtendedCleanupStackSize
decl_stmt|;
name|bool
name|OldDidCallStackSave
decl_stmt|;
name|protected
label|:
name|bool
name|PerformCleanup
decl_stmt|;
name|private
label|:
name|RunCleanupsScope
argument_list|(
argument|const RunCleanupsScope&
argument_list|)
name|LLVM_DELETED_FUNCTION
expr_stmt|;
name|void
name|operator
init|=
operator|(
specifier|const
name|RunCleanupsScope
operator|&
operator|)
name|LLVM_DELETED_FUNCTION
decl_stmt|;
name|protected
label|:
name|CodeGenFunction
modifier|&
name|CGF
decl_stmt|;
name|public
label|:
comment|/// \brief Enter a new cleanup scope.
name|explicit
name|RunCleanupsScope
argument_list|(
name|CodeGenFunction
operator|&
name|CGF
argument_list|)
operator|:
name|PerformCleanup
argument_list|(
name|true
argument_list|)
operator|,
name|CGF
argument_list|(
argument|CGF
argument_list|)
block|{
name|CleanupStackDepth
operator|=
name|CGF
operator|.
name|EHStack
operator|.
name|stable_begin
argument_list|()
block|;
name|LifetimeExtendedCleanupStackSize
operator|=
name|CGF
operator|.
name|LifetimeExtendedCleanupStack
operator|.
name|size
argument_list|()
block|;
name|OldDidCallStackSave
operator|=
name|CGF
operator|.
name|DidCallStackSave
block|;
name|CGF
operator|.
name|DidCallStackSave
operator|=
name|false
block|;     }
comment|/// \brief Exit this cleanup scope, emitting any accumulated
comment|/// cleanups.
operator|~
name|RunCleanupsScope
argument_list|()
block|{
if|if
condition|(
name|PerformCleanup
condition|)
block|{
name|CGF
operator|.
name|DidCallStackSave
operator|=
name|OldDidCallStackSave
expr_stmt|;
name|CGF
operator|.
name|PopCleanupBlocks
argument_list|(
name|CleanupStackDepth
argument_list|,
name|LifetimeExtendedCleanupStackSize
argument_list|)
expr_stmt|;
block|}
block|}
comment|/// \brief Determine whether this scope requires any cleanups.
name|bool
name|requiresCleanups
argument_list|()
specifier|const
block|{
return|return
name|CGF
operator|.
name|EHStack
operator|.
name|stable_begin
argument_list|()
operator|!=
name|CleanupStackDepth
return|;
block|}
comment|/// \brief Force the emission of cleanups now, instead of waiting
comment|/// until this object is destroyed.
name|void
name|ForceCleanup
parameter_list|()
block|{
name|assert
argument_list|(
name|PerformCleanup
operator|&&
literal|"Already forced cleanup"
argument_list|)
expr_stmt|;
name|CGF
operator|.
name|DidCallStackSave
operator|=
name|OldDidCallStackSave
expr_stmt|;
name|CGF
operator|.
name|PopCleanupBlocks
argument_list|(
name|CleanupStackDepth
argument_list|,
name|LifetimeExtendedCleanupStackSize
argument_list|)
expr_stmt|;
name|PerformCleanup
operator|=
name|false
expr_stmt|;
block|}
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_decl_stmt
name|class
name|LexicalScope
range|:
name|protected
name|RunCleanupsScope
block|{
name|SourceRange
name|Range
block|;
name|SmallVector
operator|<
specifier|const
name|LabelDecl
operator|*
block|,
literal|4
operator|>
name|Labels
block|;
name|LexicalScope
operator|*
name|ParentScope
block|;
name|LexicalScope
argument_list|(
argument|const LexicalScope&
argument_list|)
name|LLVM_DELETED_FUNCTION
block|;
name|void
name|operator
operator|=
operator|(
specifier|const
name|LexicalScope
operator|&
operator|)
name|LLVM_DELETED_FUNCTION
block|;
name|public
operator|:
comment|/// \brief Enter a new cleanup scope.
name|explicit
name|LexicalScope
argument_list|(
argument|CodeGenFunction&CGF
argument_list|,
argument|SourceRange Range
argument_list|)
operator|:
name|RunCleanupsScope
argument_list|(
name|CGF
argument_list|)
block|,
name|Range
argument_list|(
name|Range
argument_list|)
block|,
name|ParentScope
argument_list|(
argument|CGF.CurLexicalScope
argument_list|)
block|{
name|CGF
operator|.
name|CurLexicalScope
operator|=
name|this
block|;
if|if
condition|(
name|CGDebugInfo
modifier|*
name|DI
init|=
name|CGF
operator|.
name|getDebugInfo
argument_list|()
condition|)
name|DI
operator|->
name|EmitLexicalBlockStart
argument_list|(
name|CGF
operator|.
name|Builder
argument_list|,
name|Range
operator|.
name|getBegin
argument_list|()
argument_list|)
expr_stmt|;
block|}
name|void
name|addLabel
argument_list|(
argument|const LabelDecl *label
argument_list|)
block|{
name|assert
argument_list|(
name|PerformCleanup
operator|&&
literal|"adding label to dead scope?"
argument_list|)
block|;
name|Labels
operator|.
name|push_back
argument_list|(
name|label
argument_list|)
block|;     }
comment|/// \brief Exit this cleanup scope, emitting any accumulated
comment|/// cleanups.
operator|~
name|LexicalScope
argument_list|()
block|{
if|if
condition|(
name|CGDebugInfo
modifier|*
name|DI
init|=
name|CGF
operator|.
name|getDebugInfo
argument_list|()
condition|)
name|DI
operator|->
name|EmitLexicalBlockEnd
argument_list|(
name|CGF
operator|.
name|Builder
argument_list|,
name|Range
operator|.
name|getEnd
argument_list|()
argument_list|)
expr_stmt|;
comment|// If we should perform a cleanup, force them now.  Note that
comment|// this ends the cleanup scope before rescoping any labels.
if|if
condition|(
name|PerformCleanup
condition|)
name|ForceCleanup
argument_list|()
expr_stmt|;
block|}
end_decl_stmt

begin_comment
comment|/// \brief Force the emission of cleanups now, instead of waiting
end_comment

begin_comment
comment|/// until this object is destroyed.
end_comment

begin_function
name|void
name|ForceCleanup
parameter_list|()
block|{
name|CGF
operator|.
name|CurLexicalScope
operator|=
name|ParentScope
expr_stmt|;
name|RunCleanupsScope
operator|::
name|ForceCleanup
argument_list|()
expr_stmt|;
if|if
condition|(
operator|!
name|Labels
operator|.
name|empty
argument_list|()
condition|)
name|rescopeLabels
argument_list|()
expr_stmt|;
block|}
end_function

begin_function_decl
name|void
name|rescopeLabels
parameter_list|()
function_decl|;
end_function_decl

begin_comment
unit|};
comment|/// \brief Takes the old cleanup stack size and emits the cleanup blocks
end_comment

begin_comment
comment|/// that have been added.
end_comment

begin_decl_stmt
name|void
name|PopCleanupBlocks
argument_list|(
name|EHScopeStack
operator|::
name|stable_iterator
name|OldCleanupStackSize
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// \brief Takes the old cleanup stack size and emits the cleanup blocks
end_comment

begin_comment
comment|/// that have been added, then adds all lifetime-extended cleanups from
end_comment

begin_comment
comment|/// the given position to the stack.
end_comment

begin_decl_stmt
name|void
name|PopCleanupBlocks
argument_list|(
name|EHScopeStack
operator|::
name|stable_iterator
name|OldCleanupStackSize
argument_list|,
name|size_t
name|OldLifetimeExtendedStackSize
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|ResolveBranchFixups
argument_list|(
name|llvm
operator|::
name|BasicBlock
operator|*
name|Target
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// The given basic block lies in the current EH scope, but may be a
end_comment

begin_comment
comment|/// target of a potentially scope-crossing jump; get a stable handle
end_comment

begin_comment
comment|/// to which we can perform this jump later.
end_comment

begin_decl_stmt
name|JumpDest
name|getJumpDestInCurrentScope
argument_list|(
name|llvm
operator|::
name|BasicBlock
operator|*
name|Target
argument_list|)
block|{
return|return
name|JumpDest
argument_list|(
name|Target
argument_list|,
name|EHStack
operator|.
name|getInnermostNormalCleanup
argument_list|()
argument_list|,
name|NextCleanupDestIndex
operator|++
argument_list|)
return|;
block|}
end_decl_stmt

begin_comment
comment|/// The given basic block lies in the current EH scope, but may be a
end_comment

begin_comment
comment|/// target of a potentially scope-crossing jump; get a stable handle
end_comment

begin_comment
comment|/// to which we can perform this jump later.
end_comment

begin_function
name|JumpDest
name|getJumpDestInCurrentScope
parameter_list|(
name|StringRef
name|Name
init|=
name|StringRef
argument_list|()
parameter_list|)
block|{
return|return
name|getJumpDestInCurrentScope
argument_list|(
name|createBasicBlock
argument_list|(
name|Name
argument_list|)
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/// EmitBranchThroughCleanup - Emit a branch from the current insert
end_comment

begin_comment
comment|/// block through the normal cleanup handling code (if any) and then
end_comment

begin_comment
comment|/// on to \arg Dest.
end_comment

begin_function_decl
name|void
name|EmitBranchThroughCleanup
parameter_list|(
name|JumpDest
name|Dest
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// isObviouslyBranchWithoutCleanups - Return true if a branch to the
end_comment

begin_comment
comment|/// specified destination obviously has no cleanups to run.  'false' is always
end_comment

begin_comment
comment|/// a conservatively correct answer for this method.
end_comment

begin_decl_stmt
name|bool
name|isObviouslyBranchWithoutCleanups
argument_list|(
name|JumpDest
name|Dest
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// popCatchScope - Pops the catch scope at the top of the EHScope
end_comment

begin_comment
comment|/// stack, emitting any required code (other than the catch handlers
end_comment

begin_comment
comment|/// themselves).
end_comment

begin_function_decl
name|void
name|popCatchScope
parameter_list|()
function_decl|;
end_function_decl

begin_expr_stmt
name|llvm
operator|::
name|BasicBlock
operator|*
name|getEHResumeBlock
argument_list|(
argument|bool isCleanup
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|llvm
operator|::
name|BasicBlock
operator|*
name|getEHDispatchBlock
argument_list|(
argument|EHScopeStack::stable_iterator scope
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// An object to manage conditionally-evaluated expressions.
end_comment

begin_decl_stmt
name|class
name|ConditionalEvaluation
block|{
name|llvm
operator|::
name|BasicBlock
operator|*
name|StartBB
expr_stmt|;
name|public
label|:
name|ConditionalEvaluation
argument_list|(
name|CodeGenFunction
operator|&
name|CGF
argument_list|)
operator|:
name|StartBB
argument_list|(
argument|CGF.Builder.GetInsertBlock()
argument_list|)
block|{}
name|void
name|begin
argument_list|(
argument|CodeGenFunction&CGF
argument_list|)
block|{
name|assert
argument_list|(
name|CGF
operator|.
name|OutermostConditional
operator|!=
name|this
argument_list|)
block|;
if|if
condition|(
operator|!
name|CGF
operator|.
name|OutermostConditional
condition|)
name|CGF
operator|.
name|OutermostConditional
operator|=
name|this
expr_stmt|;
block|}
name|void
name|end
parameter_list|(
name|CodeGenFunction
modifier|&
name|CGF
parameter_list|)
block|{
name|assert
argument_list|(
name|CGF
operator|.
name|OutermostConditional
operator|!=
literal|0
argument_list|)
expr_stmt|;
if|if
condition|(
name|CGF
operator|.
name|OutermostConditional
operator|==
name|this
condition|)
name|CGF
operator|.
name|OutermostConditional
operator|=
literal|0
expr_stmt|;
block|}
comment|/// Returns a block which will be executed prior to each
comment|/// evaluation of the conditional code.
name|llvm
operator|::
name|BasicBlock
operator|*
name|getStartingBlock
argument_list|()
specifier|const
block|{
return|return
name|StartBB
return|;
block|}
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|/// isInConditionalBranch - Return true if we're currently emitting
end_comment

begin_comment
comment|/// one branch or the other of a conditional expression.
end_comment

begin_expr_stmt
name|bool
name|isInConditionalBranch
argument_list|()
specifier|const
block|{
return|return
name|OutermostConditional
operator|!=
literal|0
return|;
block|}
end_expr_stmt

begin_decl_stmt
name|void
name|setBeforeOutermostConditional
argument_list|(
name|llvm
operator|::
name|Value
operator|*
name|value
argument_list|,
name|llvm
operator|::
name|Value
operator|*
name|addr
argument_list|)
block|{
name|assert
argument_list|(
name|isInConditionalBranch
argument_list|()
argument_list|)
expr_stmt|;
name|llvm
operator|::
name|BasicBlock
operator|*
name|block
operator|=
name|OutermostConditional
operator|->
name|getStartingBlock
argument_list|()
expr_stmt|;
name|new
name|llvm
operator|::
name|StoreInst
argument_list|(
name|value
argument_list|,
name|addr
argument_list|,
operator|&
name|block
operator|->
name|back
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_decl_stmt

begin_comment
comment|/// An RAII object to record that we're evaluating a statement
end_comment

begin_comment
comment|/// expression.
end_comment

begin_decl_stmt
name|class
name|StmtExprEvaluation
block|{
name|CodeGenFunction
modifier|&
name|CGF
decl_stmt|;
comment|/// We have to save the outermost conditional: cleanups in a
comment|/// statement expression aren't conditional just because the
comment|/// StmtExpr is.
name|ConditionalEvaluation
modifier|*
name|SavedOutermostConditional
decl_stmt|;
name|public
label|:
name|StmtExprEvaluation
argument_list|(
name|CodeGenFunction
operator|&
name|CGF
argument_list|)
operator|:
name|CGF
argument_list|(
name|CGF
argument_list|)
operator|,
name|SavedOutermostConditional
argument_list|(
argument|CGF.OutermostConditional
argument_list|)
block|{
name|CGF
operator|.
name|OutermostConditional
operator|=
literal|0
block|;     }
operator|~
name|StmtExprEvaluation
argument_list|()
block|{
name|CGF
operator|.
name|OutermostConditional
operator|=
name|SavedOutermostConditional
block|;
name|CGF
operator|.
name|EnsureInsertPoint
argument_list|()
block|;     }
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|/// An object which temporarily prevents a value from being
end_comment

begin_comment
comment|/// destroyed by aggressive peephole optimizations that assume that
end_comment

begin_comment
comment|/// all uses of a value have been realized in the IR.
end_comment

begin_decl_stmt
name|class
name|PeepholeProtection
block|{
name|llvm
operator|::
name|Instruction
operator|*
name|Inst
expr_stmt|;
name|friend
name|class
name|CodeGenFunction
decl_stmt|;
name|public
label|:
name|PeepholeProtection
argument_list|()
operator|:
name|Inst
argument_list|(
literal|0
argument_list|)
block|{}
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|/// A non-RAII class containing all the information about a bound
end_comment

begin_comment
comment|/// opaque value.  OpaqueValueMapping, below, is a RAII wrapper for
end_comment

begin_comment
comment|/// this which makes individual mappings very simple; using this
end_comment

begin_comment
comment|/// class directly is useful when you have a variable number of
end_comment

begin_comment
comment|/// opaque values or don't want the RAII functionality for some
end_comment

begin_comment
comment|/// reason.
end_comment

begin_decl_stmt
name|class
name|OpaqueValueMappingData
block|{
specifier|const
name|OpaqueValueExpr
modifier|*
name|OpaqueValue
decl_stmt|;
name|bool
name|BoundLValue
decl_stmt|;
name|CodeGenFunction
operator|::
name|PeepholeProtection
name|Protection
expr_stmt|;
name|OpaqueValueMappingData
argument_list|(
argument|const OpaqueValueExpr *ov
argument_list|,
argument|bool boundLValue
argument_list|)
block|:
name|OpaqueValue
argument_list|(
name|ov
argument_list|)
operator|,
name|BoundLValue
argument_list|(
argument|boundLValue
argument_list|)
block|{}
name|public
operator|:
name|OpaqueValueMappingData
argument_list|()
operator|:
name|OpaqueValue
argument_list|(
literal|0
argument_list|)
block|{}
specifier|static
name|bool
name|shouldBindAsLValue
argument_list|(
argument|const Expr *expr
argument_list|)
block|{
comment|// gl-values should be bound as l-values for obvious reasons.
comment|// Records should be bound as l-values because IR generation
comment|// always keeps them in memory.  Expressions of function type
comment|// act exactly like l-values but are formally required to be
comment|// r-values in C.
return|return
name|expr
operator|->
name|isGLValue
argument_list|()
operator|||
name|expr
operator|->
name|getType
argument_list|()
operator|->
name|isRecordType
argument_list|()
operator|||
name|expr
operator|->
name|getType
argument_list|()
operator|->
name|isFunctionType
argument_list|()
return|;
block|}
specifier|static
name|OpaqueValueMappingData
name|bind
parameter_list|(
name|CodeGenFunction
modifier|&
name|CGF
parameter_list|,
specifier|const
name|OpaqueValueExpr
modifier|*
name|ov
parameter_list|,
specifier|const
name|Expr
modifier|*
name|e
parameter_list|)
block|{
if|if
condition|(
name|shouldBindAsLValue
argument_list|(
name|ov
argument_list|)
condition|)
return|return
name|bind
argument_list|(
name|CGF
argument_list|,
name|ov
argument_list|,
name|CGF
operator|.
name|EmitLValue
argument_list|(
name|e
argument_list|)
argument_list|)
return|;
return|return
name|bind
argument_list|(
name|CGF
argument_list|,
name|ov
argument_list|,
name|CGF
operator|.
name|EmitAnyExpr
argument_list|(
name|e
argument_list|)
argument_list|)
return|;
block|}
specifier|static
name|OpaqueValueMappingData
name|bind
parameter_list|(
name|CodeGenFunction
modifier|&
name|CGF
parameter_list|,
specifier|const
name|OpaqueValueExpr
modifier|*
name|ov
parameter_list|,
specifier|const
name|LValue
modifier|&
name|lv
parameter_list|)
block|{
name|assert
argument_list|(
name|shouldBindAsLValue
argument_list|(
name|ov
argument_list|)
argument_list|)
expr_stmt|;
name|CGF
operator|.
name|OpaqueLValues
operator|.
name|insert
argument_list|(
name|std
operator|::
name|make_pair
argument_list|(
name|ov
argument_list|,
name|lv
argument_list|)
argument_list|)
expr_stmt|;
return|return
name|OpaqueValueMappingData
argument_list|(
name|ov
argument_list|,
name|true
argument_list|)
return|;
block|}
specifier|static
name|OpaqueValueMappingData
name|bind
parameter_list|(
name|CodeGenFunction
modifier|&
name|CGF
parameter_list|,
specifier|const
name|OpaqueValueExpr
modifier|*
name|ov
parameter_list|,
specifier|const
name|RValue
modifier|&
name|rv
parameter_list|)
block|{
name|assert
argument_list|(
operator|!
name|shouldBindAsLValue
argument_list|(
name|ov
argument_list|)
argument_list|)
expr_stmt|;
name|CGF
operator|.
name|OpaqueRValues
operator|.
name|insert
argument_list|(
name|std
operator|::
name|make_pair
argument_list|(
name|ov
argument_list|,
name|rv
argument_list|)
argument_list|)
expr_stmt|;
name|OpaqueValueMappingData
name|data
argument_list|(
name|ov
argument_list|,
name|false
argument_list|)
decl_stmt|;
comment|// Work around an extremely aggressive peephole optimization in
comment|// EmitScalarConversion which assumes that all other uses of a
comment|// value are extant.
name|data
operator|.
name|Protection
operator|=
name|CGF
operator|.
name|protectFromPeepholes
argument_list|(
name|rv
argument_list|)
expr_stmt|;
return|return
name|data
return|;
block|}
name|bool
name|isValid
argument_list|()
specifier|const
block|{
return|return
name|OpaqueValue
operator|!=
literal|0
return|;
block|}
name|void
name|clear
parameter_list|()
block|{
name|OpaqueValue
operator|=
literal|0
expr_stmt|;
block|}
name|void
name|unbind
parameter_list|(
name|CodeGenFunction
modifier|&
name|CGF
parameter_list|)
block|{
name|assert
argument_list|(
name|OpaqueValue
operator|&&
literal|"no data to unbind!"
argument_list|)
expr_stmt|;
if|if
condition|(
name|BoundLValue
condition|)
block|{
name|CGF
operator|.
name|OpaqueLValues
operator|.
name|erase
argument_list|(
name|OpaqueValue
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|CGF
operator|.
name|OpaqueRValues
operator|.
name|erase
argument_list|(
name|OpaqueValue
argument_list|)
expr_stmt|;
name|CGF
operator|.
name|unprotectFromPeepholes
argument_list|(
name|Protection
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
comment|/// An RAII object to set (and then clear) a mapping for an OpaqueValueExpr.
end_comment

begin_decl_stmt
name|class
name|OpaqueValueMapping
block|{
name|CodeGenFunction
modifier|&
name|CGF
decl_stmt|;
name|OpaqueValueMappingData
name|Data
decl_stmt|;
name|public
label|:
specifier|static
name|bool
name|shouldBindAsLValue
parameter_list|(
specifier|const
name|Expr
modifier|*
name|expr
parameter_list|)
block|{
return|return
name|OpaqueValueMappingData
operator|::
name|shouldBindAsLValue
argument_list|(
name|expr
argument_list|)
return|;
block|}
comment|/// Build the opaque value mapping for the given conditional
comment|/// operator if it's the GNU ?: extension.  This is a common
comment|/// enough pattern that the convenience operator is really
comment|/// helpful.
comment|///
name|OpaqueValueMapping
argument_list|(
name|CodeGenFunction
operator|&
name|CGF
argument_list|,
specifier|const
name|AbstractConditionalOperator
operator|*
name|op
argument_list|)
operator|:
name|CGF
argument_list|(
argument|CGF
argument_list|)
block|{
if|if
condition|(
name|isa
operator|<
name|ConditionalOperator
operator|>
operator|(
name|op
operator|)
condition|)
comment|// Leave Data empty.
return|return;
specifier|const
name|BinaryConditionalOperator
operator|*
name|e
operator|=
name|cast
operator|<
name|BinaryConditionalOperator
operator|>
operator|(
name|op
operator|)
expr_stmt|;
name|Data
operator|=
name|OpaqueValueMappingData
operator|::
name|bind
argument_list|(
name|CGF
argument_list|,
name|e
operator|->
name|getOpaqueValue
argument_list|()
argument_list|,
name|e
operator|->
name|getCommon
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_decl_stmt

begin_macro
name|OpaqueValueMapping
argument_list|(
argument|CodeGenFunction&CGF
argument_list|,
argument|const OpaqueValueExpr *opaqueValue
argument_list|,
argument|LValue lvalue
argument_list|)
end_macro

begin_expr_stmt
unit|:
name|CGF
argument_list|(
name|CGF
argument_list|)
operator|,
name|Data
argument_list|(
argument|OpaqueValueMappingData::bind(CGF, opaqueValue, lvalue)
argument_list|)
block|{     }
name|OpaqueValueMapping
argument_list|(
argument|CodeGenFunction&CGF
argument_list|,
argument|const OpaqueValueExpr *opaqueValue
argument_list|,
argument|RValue rvalue
argument_list|)
operator|:
name|CGF
argument_list|(
name|CGF
argument_list|)
operator|,
name|Data
argument_list|(
argument|OpaqueValueMappingData::bind(CGF, opaqueValue, rvalue)
argument_list|)
block|{     }
name|void
name|pop
argument_list|()
block|{
name|Data
operator|.
name|unbind
argument_list|(
name|CGF
argument_list|)
block|;
name|Data
operator|.
name|clear
argument_list|()
block|;     }
operator|~
name|OpaqueValueMapping
argument_list|()
block|{
if|if
condition|(
name|Data
operator|.
name|isValid
argument_list|()
condition|)
name|Data
operator|.
name|unbind
argument_list|(
name|CGF
argument_list|)
expr_stmt|;
block|}
end_expr_stmt

begin_comment
unit|};
comment|/// getByrefValueFieldNumber - Given a declaration, returns the LLVM field
end_comment

begin_comment
comment|/// number that holds the value.
end_comment

begin_decl_stmt
name|unsigned
name|getByRefValueLLVMField
argument_list|(
specifier|const
name|ValueDecl
operator|*
name|VD
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// BuildBlockByrefAddress - Computes address location of the
end_comment

begin_comment
comment|/// variable which is declared as __block.
end_comment

begin_expr_stmt
name|llvm
operator|::
name|Value
operator|*
name|BuildBlockByrefAddress
argument_list|(
name|llvm
operator|::
name|Value
operator|*
name|BaseAddr
argument_list|,
specifier|const
name|VarDecl
operator|*
name|V
argument_list|)
expr_stmt|;
end_expr_stmt

begin_label
name|private
label|:
end_label

begin_decl_stmt
name|CGDebugInfo
modifier|*
name|DebugInfo
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|bool
name|DisableDebugInfo
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// DidCallStackSave - Whether llvm.stacksave has been called. Used to avoid
end_comment

begin_comment
comment|/// calling llvm.stacksave for multiple VLAs in the same scope.
end_comment

begin_decl_stmt
name|bool
name|DidCallStackSave
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// IndirectBranch - The first time an indirect goto is seen we create a block
end_comment

begin_comment
comment|/// with an indirect branch.  Every time we see the address of a label taken,
end_comment

begin_comment
comment|/// we add the label to the indirect goto.  Every subsequent indirect goto is
end_comment

begin_comment
comment|/// codegen'd as a jump to the IndirectBranch's basic block.
end_comment

begin_expr_stmt
name|llvm
operator|::
name|IndirectBrInst
operator|*
name|IndirectBranch
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// LocalDeclMap - This keeps track of the LLVM allocas or globals for local C
end_comment

begin_comment
comment|/// decls.
end_comment

begin_typedef
typedef|typedef
name|llvm
operator|::
name|DenseMap
operator|<
specifier|const
name|Decl
operator|*
operator|,
name|llvm
operator|::
name|Value
operator|*
operator|>
name|DeclMapTy
expr_stmt|;
end_typedef

begin_decl_stmt
name|DeclMapTy
name|LocalDeclMap
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// LabelMap - This keeps track of the LLVM basic block for each C label.
end_comment

begin_expr_stmt
name|llvm
operator|::
name|DenseMap
operator|<
specifier|const
name|LabelDecl
operator|*
operator|,
name|JumpDest
operator|>
name|LabelMap
expr_stmt|;
end_expr_stmt

begin_comment
comment|// BreakContinueStack - This keeps track of where break and continue
end_comment

begin_comment
comment|// statements should jump to.
end_comment

begin_struct
struct|struct
name|BreakContinue
block|{
name|BreakContinue
argument_list|(
argument|JumpDest Break
argument_list|,
argument|JumpDest Continue
argument_list|)
block|:
name|BreakBlock
argument_list|(
name|Break
argument_list|)
operator|,
name|ContinueBlock
argument_list|(
argument|Continue
argument_list|)
block|{}
name|JumpDest
name|BreakBlock
expr_stmt|;
name|JumpDest
name|ContinueBlock
decl_stmt|;
block|}
struct|;
end_struct

begin_expr_stmt
name|SmallVector
operator|<
name|BreakContinue
operator|,
literal|8
operator|>
name|BreakContinueStack
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// SwitchInsn - This is nearest current switch instruction. It is null if
end_comment

begin_comment
comment|/// current context is not in a switch.
end_comment

begin_expr_stmt
name|llvm
operator|::
name|SwitchInst
operator|*
name|SwitchInsn
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// CaseRangeBlock - This block holds if condition check for last case
end_comment

begin_comment
comment|/// statement range in current switch instruction.
end_comment

begin_expr_stmt
name|llvm
operator|::
name|BasicBlock
operator|*
name|CaseRangeBlock
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// OpaqueLValues - Keeps track of the current set of opaque value
end_comment

begin_comment
comment|/// expressions.
end_comment

begin_expr_stmt
name|llvm
operator|::
name|DenseMap
operator|<
specifier|const
name|OpaqueValueExpr
operator|*
operator|,
name|LValue
operator|>
name|OpaqueLValues
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|llvm
operator|::
name|DenseMap
operator|<
specifier|const
name|OpaqueValueExpr
operator|*
operator|,
name|RValue
operator|>
name|OpaqueRValues
expr_stmt|;
end_expr_stmt

begin_comment
comment|// VLASizeMap - This keeps track of the associated size for each VLA type.
end_comment

begin_comment
comment|// We track this by the size expression rather than the type itself because
end_comment

begin_comment
comment|// in certain situations, like a const qualifier applied to an VLA typedef,
end_comment

begin_comment
comment|// multiple VLA types can share the same size expression.
end_comment

begin_comment
comment|// FIXME: Maybe this could be a stack of maps that is pushed/popped as we
end_comment

begin_comment
comment|// enter/leave scopes.
end_comment

begin_expr_stmt
name|llvm
operator|::
name|DenseMap
operator|<
specifier|const
name|Expr
operator|*
operator|,
name|llvm
operator|::
name|Value
operator|*
operator|>
name|VLASizeMap
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// A block containing a single 'unreachable' instruction.  Created
end_comment

begin_comment
comment|/// lazily by getUnreachableBlock().
end_comment

begin_expr_stmt
name|llvm
operator|::
name|BasicBlock
operator|*
name|UnreachableBlock
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// Counts of the number return expressions in the function.
end_comment

begin_decl_stmt
name|unsigned
name|NumReturnExprs
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// Count the number of simple (constant) return expressions in the function.
end_comment

begin_decl_stmt
name|unsigned
name|NumSimpleReturnExprs
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// The last regular (non-return) debug location (breakpoint) in the function.
end_comment

begin_decl_stmt
name|SourceLocation
name|LastStopPoint
decl_stmt|;
end_decl_stmt

begin_label
name|public
label|:
end_label

begin_comment
comment|/// A scope within which we are constructing the fields of an object which
end_comment

begin_comment
comment|/// might use a CXXDefaultInitExpr. This stashes away a 'this' value to use
end_comment

begin_comment
comment|/// if we need to evaluate a CXXDefaultInitExpr within the evaluation.
end_comment

begin_decl_stmt
name|class
name|FieldConstructionScope
block|{
name|public
label|:
name|FieldConstructionScope
argument_list|(
name|CodeGenFunction
operator|&
name|CGF
argument_list|,
name|llvm
operator|::
name|Value
operator|*
name|This
argument_list|)
operator|:
name|CGF
argument_list|(
name|CGF
argument_list|)
operator|,
name|OldCXXDefaultInitExprThis
argument_list|(
argument|CGF.CXXDefaultInitExprThis
argument_list|)
block|{
name|CGF
operator|.
name|CXXDefaultInitExprThis
operator|=
name|This
block|;     }
operator|~
name|FieldConstructionScope
argument_list|()
block|{
name|CGF
operator|.
name|CXXDefaultInitExprThis
operator|=
name|OldCXXDefaultInitExprThis
block|;     }
name|private
operator|:
name|CodeGenFunction
operator|&
name|CGF
expr_stmt|;
name|llvm
operator|::
name|Value
operator|*
name|OldCXXDefaultInitExprThis
expr_stmt|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|/// The scope of a CXXDefaultInitExpr. Within this scope, the value of 'this'
end_comment

begin_comment
comment|/// is overridden to be the object under construction.
end_comment

begin_decl_stmt
name|class
name|CXXDefaultInitExprScope
block|{
name|public
label|:
name|CXXDefaultInitExprScope
argument_list|(
name|CodeGenFunction
operator|&
name|CGF
argument_list|)
operator|:
name|CGF
argument_list|(
name|CGF
argument_list|)
operator|,
name|OldCXXThisValue
argument_list|(
argument|CGF.CXXThisValue
argument_list|)
block|{
name|CGF
operator|.
name|CXXThisValue
operator|=
name|CGF
operator|.
name|CXXDefaultInitExprThis
block|;     }
operator|~
name|CXXDefaultInitExprScope
argument_list|()
block|{
name|CGF
operator|.
name|CXXThisValue
operator|=
name|OldCXXThisValue
block|;     }
name|public
operator|:
name|CodeGenFunction
operator|&
name|CGF
expr_stmt|;
name|llvm
operator|::
name|Value
operator|*
name|OldCXXThisValue
expr_stmt|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_label
name|private
label|:
end_label

begin_comment
comment|/// CXXThisDecl - When generating code for a C++ member function,
end_comment

begin_comment
comment|/// this will hold the implicit 'this' declaration.
end_comment

begin_decl_stmt
name|ImplicitParamDecl
modifier|*
name|CXXABIThisDecl
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|llvm
operator|::
name|Value
operator|*
name|CXXABIThisValue
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|llvm
operator|::
name|Value
operator|*
name|CXXThisValue
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// The value of 'this' to use when evaluating CXXDefaultInitExprs within
end_comment

begin_comment
comment|/// this expression.
end_comment

begin_expr_stmt
name|llvm
operator|::
name|Value
operator|*
name|CXXDefaultInitExprThis
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// CXXStructorImplicitParamDecl - When generating code for a constructor or
end_comment

begin_comment
comment|/// destructor, this will hold the implicit argument (e.g. VTT).
end_comment

begin_decl_stmt
name|ImplicitParamDecl
modifier|*
name|CXXStructorImplicitParamDecl
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|llvm
operator|::
name|Value
operator|*
name|CXXStructorImplicitParamValue
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// OutermostConditional - Points to the outermost active
end_comment

begin_comment
comment|/// conditional control.  This is used so that we know if a
end_comment

begin_comment
comment|/// temporary should be destroyed conditionally.
end_comment

begin_decl_stmt
name|ConditionalEvaluation
modifier|*
name|OutermostConditional
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// The current lexical scope.
end_comment

begin_decl_stmt
name|LexicalScope
modifier|*
name|CurLexicalScope
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// The current source location that should be used for exception
end_comment

begin_comment
comment|/// handling code.
end_comment

begin_decl_stmt
name|SourceLocation
name|CurEHLocation
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// ByrefValueInfoMap - For each __block variable, contains a pair of the LLVM
end_comment

begin_comment
comment|/// type as well as the field number that contains the actual data.
end_comment

begin_expr_stmt
name|llvm
operator|::
name|DenseMap
operator|<
specifier|const
name|ValueDecl
operator|*
operator|,
name|std
operator|::
name|pair
operator|<
name|llvm
operator|::
name|Type
operator|*
operator|,
name|unsigned
operator|>
expr|>
name|ByRefValueInfo
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|llvm
operator|::
name|BasicBlock
operator|*
name|TerminateLandingPad
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|llvm
operator|::
name|BasicBlock
operator|*
name|TerminateHandler
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|llvm
operator|::
name|BasicBlock
operator|*
name|TrapBB
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// Add a kernel metadata node to the named metadata node 'opencl.kernels'.
end_comment

begin_comment
comment|/// In the kernel metadata node, reference the kernel function and metadata
end_comment

begin_comment
comment|/// nodes for its optional attribute qualifiers (OpenCL 1.1 6.7.2):
end_comment

begin_comment
comment|/// - A node for the vec_type_hint(<type>) qualifier contains string
end_comment

begin_comment
comment|///   "vec_type_hint", an undefined value of the<type> data type,
end_comment

begin_comment
comment|///   and a Boolean that is true if the<type> is integer and signed.
end_comment

begin_comment
comment|/// - A node for the work_group_size_hint(X,Y,Z) qualifier contains string
end_comment

begin_comment
comment|///   "work_group_size_hint", and three 32-bit integers X, Y and Z.
end_comment

begin_comment
comment|/// - A node for the reqd_work_group_size(X,Y,Z) qualifier contains string
end_comment

begin_comment
comment|///   "reqd_work_group_size", and three 32-bit integers X, Y and Z.
end_comment

begin_decl_stmt
name|void
name|EmitOpenCLKernelMetadata
argument_list|(
specifier|const
name|FunctionDecl
operator|*
name|FD
argument_list|,
name|llvm
operator|::
name|Function
operator|*
name|Fn
argument_list|)
decl_stmt|;
end_decl_stmt

begin_label
name|public
label|:
end_label

begin_macro
name|CodeGenFunction
argument_list|(
argument|CodeGenModule&cgm
argument_list|,
argument|bool suppressNewContext=false
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_expr_stmt
operator|~
name|CodeGenFunction
argument_list|()
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|CodeGenTypes
operator|&
name|getTypes
argument_list|()
specifier|const
block|{
return|return
name|CGM
operator|.
name|getTypes
argument_list|()
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|ASTContext
operator|&
name|getContext
argument_list|()
specifier|const
block|{
return|return
name|CGM
operator|.
name|getContext
argument_list|()
return|;
block|}
end_expr_stmt

begin_function
name|CGDebugInfo
modifier|*
name|getDebugInfo
parameter_list|()
block|{
if|if
condition|(
name|DisableDebugInfo
condition|)
return|return
name|NULL
return|;
return|return
name|DebugInfo
return|;
block|}
end_function

begin_function
name|void
name|disableDebugInfo
parameter_list|()
block|{
name|DisableDebugInfo
operator|=
name|true
expr_stmt|;
block|}
end_function

begin_function
name|void
name|enableDebugInfo
parameter_list|()
block|{
name|DisableDebugInfo
operator|=
name|false
expr_stmt|;
block|}
end_function

begin_function
name|bool
name|shouldUseFusedARCCalls
parameter_list|()
block|{
return|return
name|CGM
operator|.
name|getCodeGenOpts
argument_list|()
operator|.
name|OptimizationLevel
operator|==
literal|0
return|;
block|}
end_function

begin_expr_stmt
specifier|const
name|LangOptions
operator|&
name|getLangOpts
argument_list|()
specifier|const
block|{
return|return
name|CGM
operator|.
name|getLangOpts
argument_list|()
return|;
block|}
end_expr_stmt

begin_comment
comment|/// Returns a pointer to the function's exception object and selector slot,
end_comment

begin_comment
comment|/// which is assigned in every landing pad.
end_comment

begin_expr_stmt
name|llvm
operator|::
name|Value
operator|*
name|getExceptionSlot
argument_list|()
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|llvm
operator|::
name|Value
operator|*
name|getEHSelectorSlot
argument_list|()
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// Returns the contents of the function's exception object and selector
end_comment

begin_comment
comment|/// slots.
end_comment

begin_expr_stmt
name|llvm
operator|::
name|Value
operator|*
name|getExceptionFromSlot
argument_list|()
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|llvm
operator|::
name|Value
operator|*
name|getSelectorFromSlot
argument_list|()
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|llvm
operator|::
name|Value
operator|*
name|getNormalCleanupDestSlot
argument_list|()
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|llvm
operator|::
name|BasicBlock
operator|*
name|getUnreachableBlock
argument_list|()
block|{
if|if
condition|(
operator|!
name|UnreachableBlock
condition|)
block|{
name|UnreachableBlock
operator|=
name|createBasicBlock
argument_list|(
literal|"unreachable"
argument_list|)
expr_stmt|;
name|new
name|llvm
operator|::
name|UnreachableInst
argument_list|(
name|getLLVMContext
argument_list|()
argument_list|,
name|UnreachableBlock
argument_list|)
expr_stmt|;
block|}
end_expr_stmt

begin_return
return|return
name|UnreachableBlock
return|;
end_return

begin_expr_stmt
unit|}    llvm
operator|::
name|BasicBlock
operator|*
name|getInvokeDest
argument_list|()
block|{
if|if
condition|(
operator|!
name|EHStack
operator|.
name|requiresLandingPad
argument_list|()
condition|)
return|return
literal|0
return|;
end_expr_stmt

begin_return
return|return
name|getInvokeDestImpl
argument_list|()
return|;
end_return

begin_expr_stmt
unit|}    const
name|TargetInfo
operator|&
name|getTarget
argument_list|()
specifier|const
block|{
return|return
name|Target
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|llvm
operator|::
name|LLVMContext
operator|&
name|getLLVMContext
argument_list|()
block|{
return|return
name|CGM
operator|.
name|getLLVMContext
argument_list|()
return|;
block|}
end_expr_stmt

begin_comment
comment|//===--------------------------------------------------------------------===//
end_comment

begin_comment
comment|//                                  Cleanups
end_comment

begin_comment
comment|//===--------------------------------------------------------------------===//
end_comment

begin_typedef
typedef|typedef
name|void
name|Destroyer
argument_list|(
name|CodeGenFunction
operator|&
name|CGF
argument_list|,
name|llvm
operator|::
name|Value
operator|*
name|addr
argument_list|,
name|QualType
name|ty
argument_list|)
typedef|;
end_typedef

begin_decl_stmt
name|void
name|pushIrregularPartialArrayCleanup
argument_list|(
name|llvm
operator|::
name|Value
operator|*
name|arrayBegin
argument_list|,
name|llvm
operator|::
name|Value
operator|*
name|arrayEndPointer
argument_list|,
name|QualType
name|elementType
argument_list|,
name|Destroyer
operator|*
name|destroyer
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|pushRegularPartialArrayCleanup
argument_list|(
name|llvm
operator|::
name|Value
operator|*
name|arrayBegin
argument_list|,
name|llvm
operator|::
name|Value
operator|*
name|arrayEnd
argument_list|,
name|QualType
name|elementType
argument_list|,
name|Destroyer
operator|*
name|destroyer
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|pushDestroy
argument_list|(
name|QualType
operator|::
name|DestructionKind
name|dtorKind
argument_list|,
name|llvm
operator|::
name|Value
operator|*
name|addr
argument_list|,
name|QualType
name|type
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|pushEHDestroy
argument_list|(
name|QualType
operator|::
name|DestructionKind
name|dtorKind
argument_list|,
name|llvm
operator|::
name|Value
operator|*
name|addr
argument_list|,
name|QualType
name|type
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|pushDestroy
argument_list|(
name|CleanupKind
name|kind
argument_list|,
name|llvm
operator|::
name|Value
operator|*
name|addr
argument_list|,
name|QualType
name|type
argument_list|,
name|Destroyer
operator|*
name|destroyer
argument_list|,
name|bool
name|useEHCleanupForArray
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|pushLifetimeExtendedDestroy
argument_list|(
name|CleanupKind
name|kind
argument_list|,
name|llvm
operator|::
name|Value
operator|*
name|addr
argument_list|,
name|QualType
name|type
argument_list|,
name|Destroyer
operator|*
name|destroyer
argument_list|,
name|bool
name|useEHCleanupForArray
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|emitDestroy
argument_list|(
name|llvm
operator|::
name|Value
operator|*
name|addr
argument_list|,
name|QualType
name|type
argument_list|,
name|Destroyer
operator|*
name|destroyer
argument_list|,
name|bool
name|useEHCleanupForArray
argument_list|)
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|llvm
operator|::
name|Function
operator|*
name|generateDestroyHelper
argument_list|(
argument|llvm::Constant *addr
argument_list|,
argument|QualType type
argument_list|,
argument|Destroyer *destroyer
argument_list|,
argument|bool useEHCleanupForArray
argument_list|,
argument|const VarDecl *VD
argument_list|)
expr_stmt|;
end_expr_stmt

begin_decl_stmt
name|void
name|emitArrayDestroy
argument_list|(
name|llvm
operator|::
name|Value
operator|*
name|begin
argument_list|,
name|llvm
operator|::
name|Value
operator|*
name|end
argument_list|,
name|QualType
name|type
argument_list|,
name|Destroyer
operator|*
name|destroyer
argument_list|,
name|bool
name|checkZeroLength
argument_list|,
name|bool
name|useEHCleanup
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|Destroyer
modifier|*
name|getDestroyer
argument_list|(
name|QualType
operator|::
name|DestructionKind
name|destructionKind
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// Determines whether an EH cleanup is required to destroy a type
end_comment

begin_comment
comment|/// with the given destruction kind.
end_comment

begin_decl_stmt
name|bool
name|needsEHCleanup
argument_list|(
name|QualType
operator|::
name|DestructionKind
name|kind
argument_list|)
block|{
switch|switch
condition|(
name|kind
condition|)
block|{
case|case
name|QualType
operator|::
name|DK_none
case|:
return|return
name|false
return|;
case|case
name|QualType
operator|::
name|DK_cxx_destructor
case|:
case|case
name|QualType
operator|::
name|DK_objc_weak_lifetime
case|:
return|return
name|getLangOpts
argument_list|()
operator|.
name|Exceptions
return|;
case|case
name|QualType
operator|::
name|DK_objc_strong_lifetime
case|:
return|return
name|getLangOpts
argument_list|()
operator|.
name|Exceptions
operator|&&
name|CGM
operator|.
name|getCodeGenOpts
argument_list|()
operator|.
name|ObjCAutoRefCountExceptions
return|;
block|}
name|llvm_unreachable
argument_list|(
literal|"bad destruction kind"
argument_list|)
expr_stmt|;
block|}
end_decl_stmt

begin_decl_stmt
name|CleanupKind
name|getCleanupKind
argument_list|(
name|QualType
operator|::
name|DestructionKind
name|kind
argument_list|)
block|{
return|return
operator|(
name|needsEHCleanup
argument_list|(
name|kind
argument_list|)
condition|?
name|NormalAndEHCleanup
else|:
name|NormalCleanup
operator|)
return|;
block|}
end_decl_stmt

begin_comment
comment|//===--------------------------------------------------------------------===//
end_comment

begin_comment
comment|//                                  Objective-C
end_comment

begin_comment
comment|//===--------------------------------------------------------------------===//
end_comment

begin_function_decl
name|void
name|GenerateObjCMethod
parameter_list|(
specifier|const
name|ObjCMethodDecl
modifier|*
name|OMD
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|StartObjCMethod
parameter_list|(
specifier|const
name|ObjCMethodDecl
modifier|*
name|MD
parameter_list|,
specifier|const
name|ObjCContainerDecl
modifier|*
name|CD
parameter_list|,
name|SourceLocation
name|StartLoc
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// GenerateObjCGetter - Synthesize an Objective-C property getter function.
end_comment

begin_function_decl
name|void
name|GenerateObjCGetter
parameter_list|(
name|ObjCImplementationDecl
modifier|*
name|IMP
parameter_list|,
specifier|const
name|ObjCPropertyImplDecl
modifier|*
name|PID
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
name|void
name|generateObjCGetterBody
argument_list|(
specifier|const
name|ObjCImplementationDecl
operator|*
name|classImpl
argument_list|,
specifier|const
name|ObjCPropertyImplDecl
operator|*
name|propImpl
argument_list|,
specifier|const
name|ObjCMethodDecl
operator|*
name|GetterMothodDecl
argument_list|,
name|llvm
operator|::
name|Constant
operator|*
name|AtomicHelperFn
argument_list|)
decl_stmt|;
end_decl_stmt

begin_function_decl
name|void
name|GenerateObjCCtorDtorMethod
parameter_list|(
name|ObjCImplementationDecl
modifier|*
name|IMP
parameter_list|,
name|ObjCMethodDecl
modifier|*
name|MD
parameter_list|,
name|bool
name|ctor
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// GenerateObjCSetter - Synthesize an Objective-C property setter function
end_comment

begin_comment
comment|/// for the given property.
end_comment

begin_function_decl
name|void
name|GenerateObjCSetter
parameter_list|(
name|ObjCImplementationDecl
modifier|*
name|IMP
parameter_list|,
specifier|const
name|ObjCPropertyImplDecl
modifier|*
name|PID
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
name|void
name|generateObjCSetterBody
argument_list|(
specifier|const
name|ObjCImplementationDecl
operator|*
name|classImpl
argument_list|,
specifier|const
name|ObjCPropertyImplDecl
operator|*
name|propImpl
argument_list|,
name|llvm
operator|::
name|Constant
operator|*
name|AtomicHelperFn
argument_list|)
decl_stmt|;
end_decl_stmt

begin_function_decl
name|bool
name|IndirectObjCSetterArg
parameter_list|(
specifier|const
name|CGFunctionInfo
modifier|&
name|FI
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|IvarTypeWithAggrGCObjects
parameter_list|(
name|QualType
name|Ty
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|//===--------------------------------------------------------------------===//
end_comment

begin_comment
comment|//                                  Block Bits
end_comment

begin_comment
comment|//===--------------------------------------------------------------------===//
end_comment

begin_expr_stmt
name|llvm
operator|::
name|Value
operator|*
name|EmitBlockLiteral
argument_list|(
specifier|const
name|BlockExpr
operator|*
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|llvm
operator|::
name|Value
operator|*
name|EmitBlockLiteral
argument_list|(
specifier|const
name|CGBlockInfo
operator|&
name|Info
argument_list|)
expr_stmt|;
end_expr_stmt

begin_function_decl
specifier|static
name|void
name|destroyBlockInfos
parameter_list|(
name|CGBlockInfo
modifier|*
name|info
parameter_list|)
function_decl|;
end_function_decl

begin_expr_stmt
name|llvm
operator|::
name|Constant
operator|*
name|BuildDescriptorBlockDecl
argument_list|(
specifier|const
name|BlockExpr
operator|*
argument_list|,
specifier|const
name|CGBlockInfo
operator|&
name|Info
argument_list|,
name|llvm
operator|::
name|StructType
operator|*
argument_list|,
name|llvm
operator|::
name|Constant
operator|*
name|BlockVarLayout
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|llvm
operator|::
name|Function
operator|*
name|GenerateBlockFunction
argument_list|(
argument|GlobalDecl GD
argument_list|,
argument|const CGBlockInfo&Info
argument_list|,
argument|const DeclMapTy&ldm
argument_list|,
argument|bool IsLambdaConversionToBlock
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|llvm
operator|::
name|Constant
operator|*
name|GenerateCopyHelperFunction
argument_list|(
specifier|const
name|CGBlockInfo
operator|&
name|blockInfo
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|llvm
operator|::
name|Constant
operator|*
name|GenerateDestroyHelperFunction
argument_list|(
specifier|const
name|CGBlockInfo
operator|&
name|blockInfo
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|llvm
operator|::
name|Constant
operator|*
name|GenerateObjCAtomicSetterCopyHelperFunction
argument_list|(
specifier|const
name|ObjCPropertyImplDecl
operator|*
name|PID
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|llvm
operator|::
name|Constant
operator|*
name|GenerateObjCAtomicGetterCopyHelperFunction
argument_list|(
specifier|const
name|ObjCPropertyImplDecl
operator|*
name|PID
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|llvm
operator|::
name|Value
operator|*
name|EmitBlockCopyAndAutorelease
argument_list|(
argument|llvm::Value *Block
argument_list|,
argument|QualType Ty
argument_list|)
expr_stmt|;
end_expr_stmt

begin_decl_stmt
name|void
name|BuildBlockRelease
argument_list|(
name|llvm
operator|::
name|Value
operator|*
name|DeclPtr
argument_list|,
name|BlockFieldFlags
name|flags
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|class
name|AutoVarEmission
decl_stmt|;
end_decl_stmt

begin_function_decl
name|void
name|emitByrefStructureInit
parameter_list|(
specifier|const
name|AutoVarEmission
modifier|&
name|emission
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|enterByrefCleanup
parameter_list|(
specifier|const
name|AutoVarEmission
modifier|&
name|emission
parameter_list|)
function_decl|;
end_function_decl

begin_expr_stmt
name|llvm
operator|::
name|Value
operator|*
name|LoadBlockStruct
argument_list|()
block|{
name|assert
argument_list|(
name|BlockPointer
operator|&&
literal|"no block pointer set!"
argument_list|)
block|;
return|return
name|BlockPointer
return|;
block|}
end_expr_stmt

begin_function_decl
name|void
name|AllocateBlockCXXThisPointer
parameter_list|(
specifier|const
name|CXXThisExpr
modifier|*
name|E
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|AllocateBlockDecl
parameter_list|(
specifier|const
name|DeclRefExpr
modifier|*
name|E
parameter_list|)
function_decl|;
end_function_decl

begin_expr_stmt
name|llvm
operator|::
name|Value
operator|*
name|GetAddrOfBlockDecl
argument_list|(
argument|const VarDecl *var
argument_list|,
argument|bool ByRef
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|llvm
operator|::
name|Type
operator|*
name|BuildByRefType
argument_list|(
specifier|const
name|VarDecl
operator|*
name|var
argument_list|)
expr_stmt|;
end_expr_stmt

begin_decl_stmt
name|void
name|GenerateCode
argument_list|(
name|GlobalDecl
name|GD
argument_list|,
name|llvm
operator|::
name|Function
operator|*
name|Fn
argument_list|,
specifier|const
name|CGFunctionInfo
operator|&
name|FnInfo
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|StartFunction
argument_list|(
name|GlobalDecl
name|GD
argument_list|,
name|QualType
name|RetTy
argument_list|,
name|llvm
operator|::
name|Function
operator|*
name|Fn
argument_list|,
specifier|const
name|CGFunctionInfo
operator|&
name|FnInfo
argument_list|,
specifier|const
name|FunctionArgList
operator|&
name|Args
argument_list|,
name|SourceLocation
name|StartLoc
argument_list|)
decl_stmt|;
end_decl_stmt

begin_function_decl
name|void
name|EmitConstructorBody
parameter_list|(
name|FunctionArgList
modifier|&
name|Args
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|EmitDestructorBody
parameter_list|(
name|FunctionArgList
modifier|&
name|Args
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|emitImplicitAssignmentOperatorBody
parameter_list|(
name|FunctionArgList
modifier|&
name|Args
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|EmitFunctionBody
parameter_list|(
name|FunctionArgList
modifier|&
name|Args
parameter_list|,
specifier|const
name|Stmt
modifier|*
name|Body
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|EmitForwardingCallToLambda
parameter_list|(
specifier|const
name|CXXMethodDecl
modifier|*
name|LambdaCallOperator
parameter_list|,
name|CallArgList
modifier|&
name|CallArgs
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|EmitLambdaToBlockPointerBody
parameter_list|(
name|FunctionArgList
modifier|&
name|Args
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|EmitLambdaBlockInvokeBody
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|EmitLambdaDelegatingInvokeBody
parameter_list|(
specifier|const
name|CXXMethodDecl
modifier|*
name|MD
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|EmitLambdaStaticInvokeFunction
parameter_list|(
specifier|const
name|CXXMethodDecl
modifier|*
name|MD
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// EmitReturnBlock - Emit the unified return block, trying to avoid its
end_comment

begin_comment
comment|/// emission when possible.
end_comment

begin_function_decl
name|void
name|EmitReturnBlock
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/// FinishFunction - Complete IR generation of the current function. It is
end_comment

begin_comment
comment|/// legal to call this function even if there is no current insertion point.
end_comment

begin_function_decl
name|void
name|FinishFunction
parameter_list|(
name|SourceLocation
name|EndLoc
init|=
name|SourceLocation
argument_list|()
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
name|void
name|StartThunk
argument_list|(
name|llvm
operator|::
name|Function
operator|*
name|Fn
argument_list|,
name|GlobalDecl
name|GD
argument_list|,
specifier|const
name|CGFunctionInfo
operator|&
name|FnInfo
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|EmitCallAndReturnForThunk
argument_list|(
name|GlobalDecl
name|GD
argument_list|,
name|llvm
operator|::
name|Value
operator|*
name|Callee
argument_list|,
specifier|const
name|ThunkInfo
operator|*
name|Thunk
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// GenerateThunk - Generate a thunk for the given method.
end_comment

begin_decl_stmt
name|void
name|GenerateThunk
argument_list|(
name|llvm
operator|::
name|Function
operator|*
name|Fn
argument_list|,
specifier|const
name|CGFunctionInfo
operator|&
name|FnInfo
argument_list|,
name|GlobalDecl
name|GD
argument_list|,
specifier|const
name|ThunkInfo
operator|&
name|Thunk
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|GenerateVarArgsThunk
argument_list|(
name|llvm
operator|::
name|Function
operator|*
name|Fn
argument_list|,
specifier|const
name|CGFunctionInfo
operator|&
name|FnInfo
argument_list|,
name|GlobalDecl
name|GD
argument_list|,
specifier|const
name|ThunkInfo
operator|&
name|Thunk
argument_list|)
decl_stmt|;
end_decl_stmt

begin_function_decl
name|void
name|EmitCtorPrologue
parameter_list|(
specifier|const
name|CXXConstructorDecl
modifier|*
name|CD
parameter_list|,
name|CXXCtorType
name|Type
parameter_list|,
name|FunctionArgList
modifier|&
name|Args
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
name|void
name|EmitInitializerForField
argument_list|(
name|FieldDecl
operator|*
name|Field
argument_list|,
name|LValue
name|LHS
argument_list|,
name|Expr
operator|*
name|Init
argument_list|,
name|ArrayRef
operator|<
name|VarDecl
operator|*
operator|>
name|ArrayIndexes
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// InitializeVTablePointer - Initialize the vtable pointer of the given
end_comment

begin_comment
comment|/// subobject.
end_comment

begin_comment
comment|///
end_comment

begin_function_decl
name|void
name|InitializeVTablePointer
parameter_list|(
name|BaseSubobject
name|Base
parameter_list|,
specifier|const
name|CXXRecordDecl
modifier|*
name|NearestVBase
parameter_list|,
name|CharUnits
name|OffsetFromNearestVBase
parameter_list|,
specifier|const
name|CXXRecordDecl
modifier|*
name|VTableClass
parameter_list|)
function_decl|;
end_function_decl

begin_typedef
typedef|typedef
name|llvm
operator|::
name|SmallPtrSet
operator|<
specifier|const
name|CXXRecordDecl
operator|*
operator|,
literal|4
operator|>
name|VisitedVirtualBasesSetTy
expr_stmt|;
end_typedef

begin_function_decl
name|void
name|InitializeVTablePointers
parameter_list|(
name|BaseSubobject
name|Base
parameter_list|,
specifier|const
name|CXXRecordDecl
modifier|*
name|NearestVBase
parameter_list|,
name|CharUnits
name|OffsetFromNearestVBase
parameter_list|,
name|bool
name|BaseIsNonVirtualPrimaryBase
parameter_list|,
specifier|const
name|CXXRecordDecl
modifier|*
name|VTableClass
parameter_list|,
name|VisitedVirtualBasesSetTy
modifier|&
name|VBases
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|InitializeVTablePointers
parameter_list|(
specifier|const
name|CXXRecordDecl
modifier|*
name|ClassDecl
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// GetVTablePtr - Return the Value of the vtable pointer member pointed
end_comment

begin_comment
comment|/// to by This.
end_comment

begin_expr_stmt
name|llvm
operator|::
name|Value
operator|*
name|GetVTablePtr
argument_list|(
name|llvm
operator|::
name|Value
operator|*
name|This
argument_list|,
name|llvm
operator|::
name|Type
operator|*
name|Ty
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// CanDevirtualizeMemberFunctionCalls - Checks whether virtual calls on given
end_comment

begin_comment
comment|/// expr can be devirtualized.
end_comment

begin_function_decl
name|bool
name|CanDevirtualizeMemberFunctionCall
parameter_list|(
specifier|const
name|Expr
modifier|*
name|Base
parameter_list|,
specifier|const
name|CXXMethodDecl
modifier|*
name|MD
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// EnterDtorCleanups - Enter the cleanups necessary to complete the
end_comment

begin_comment
comment|/// given phase of destruction for a destructor.  The end result
end_comment

begin_comment
comment|/// should call destructors on members and base classes in reverse
end_comment

begin_comment
comment|/// order of their construction.
end_comment

begin_function_decl
name|void
name|EnterDtorCleanups
parameter_list|(
specifier|const
name|CXXDestructorDecl
modifier|*
name|Dtor
parameter_list|,
name|CXXDtorType
name|Type
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// ShouldInstrumentFunction - Return true if the current function should be
end_comment

begin_comment
comment|/// instrumented with __cyg_profile_func_* calls
end_comment

begin_function_decl
name|bool
name|ShouldInstrumentFunction
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/// EmitFunctionInstrumentation - Emit LLVM code to call the specified
end_comment

begin_comment
comment|/// instrumentation function with the current function and the call site, if
end_comment

begin_comment
comment|/// function instrumentation is enabled.
end_comment

begin_function_decl
name|void
name|EmitFunctionInstrumentation
parameter_list|(
specifier|const
name|char
modifier|*
name|Fn
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// EmitMCountInstrumentation - Emit call to .mcount.
end_comment

begin_function_decl
name|void
name|EmitMCountInstrumentation
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/// EmitFunctionProlog - Emit the target specific LLVM code to load the
end_comment

begin_comment
comment|/// arguments for the given function. This is also responsible for naming the
end_comment

begin_comment
comment|/// LLVM function arguments.
end_comment

begin_decl_stmt
name|void
name|EmitFunctionProlog
argument_list|(
specifier|const
name|CGFunctionInfo
operator|&
name|FI
argument_list|,
name|llvm
operator|::
name|Function
operator|*
name|Fn
argument_list|,
specifier|const
name|FunctionArgList
operator|&
name|Args
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// EmitFunctionEpilog - Emit the target specific LLVM code to return the
end_comment

begin_comment
comment|/// given temporary.
end_comment

begin_function_decl
name|void
name|EmitFunctionEpilog
parameter_list|(
specifier|const
name|CGFunctionInfo
modifier|&
name|FI
parameter_list|,
name|bool
name|EmitRetDbgLoc
parameter_list|,
name|SourceLocation
name|EndLoc
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// EmitStartEHSpec - Emit the start of the exception spec.
end_comment

begin_function_decl
name|void
name|EmitStartEHSpec
parameter_list|(
specifier|const
name|Decl
modifier|*
name|D
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// EmitEndEHSpec - Emit the end of the exception spec.
end_comment

begin_function_decl
name|void
name|EmitEndEHSpec
parameter_list|(
specifier|const
name|Decl
modifier|*
name|D
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// getTerminateLandingPad - Return a landing pad that just calls terminate.
end_comment

begin_expr_stmt
name|llvm
operator|::
name|BasicBlock
operator|*
name|getTerminateLandingPad
argument_list|()
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// getTerminateHandler - Return a handler (not a landing pad, just
end_comment

begin_comment
comment|/// a catch handler) that just calls terminate.  This is used when
end_comment

begin_comment
comment|/// a terminate scope encloses a try.
end_comment

begin_expr_stmt
name|llvm
operator|::
name|BasicBlock
operator|*
name|getTerminateHandler
argument_list|()
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|llvm
operator|::
name|Type
operator|*
name|ConvertTypeForMem
argument_list|(
argument|QualType T
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|llvm
operator|::
name|Type
operator|*
name|ConvertType
argument_list|(
argument|QualType T
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|llvm
operator|::
name|Type
operator|*
name|ConvertType
argument_list|(
argument|const TypeDecl *T
argument_list|)
block|{
return|return
name|ConvertType
argument_list|(
name|getContext
argument_list|()
operator|.
name|getTypeDeclType
argument_list|(
name|T
argument_list|)
argument_list|)
return|;
block|}
end_expr_stmt

begin_comment
comment|/// LoadObjCSelf - Load the value of self. This function is only valid while
end_comment

begin_comment
comment|/// generating code for an Objective-C method.
end_comment

begin_expr_stmt
name|llvm
operator|::
name|Value
operator|*
name|LoadObjCSelf
argument_list|()
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// TypeOfSelfObject - Return type of object that this self represents.
end_comment

begin_function_decl
name|QualType
name|TypeOfSelfObject
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/// hasAggregateLLVMType - Return true if the specified AST type will map into
end_comment

begin_comment
comment|/// an aggregate LLVM type or is void.
end_comment

begin_function_decl
specifier|static
name|TypeEvaluationKind
name|getEvaluationKind
parameter_list|(
name|QualType
name|T
parameter_list|)
function_decl|;
end_function_decl

begin_function
specifier|static
name|bool
name|hasScalarEvaluationKind
parameter_list|(
name|QualType
name|T
parameter_list|)
block|{
return|return
name|getEvaluationKind
argument_list|(
name|T
argument_list|)
operator|==
name|TEK_Scalar
return|;
block|}
end_function

begin_function
specifier|static
name|bool
name|hasAggregateEvaluationKind
parameter_list|(
name|QualType
name|T
parameter_list|)
block|{
return|return
name|getEvaluationKind
argument_list|(
name|T
argument_list|)
operator|==
name|TEK_Aggregate
return|;
block|}
end_function

begin_comment
comment|/// createBasicBlock - Create an LLVM basic block.
end_comment

begin_expr_stmt
name|llvm
operator|::
name|BasicBlock
operator|*
name|createBasicBlock
argument_list|(
argument|const Twine&name =
literal|""
argument_list|,
argument|llvm::Function *parent =
literal|0
argument_list|,
argument|llvm::BasicBlock *before =
literal|0
argument_list|)
block|{
ifdef|#
directive|ifdef
name|NDEBUG
return|return
name|llvm
operator|::
name|BasicBlock
operator|::
name|Create
argument_list|(
name|getLLVMContext
argument_list|()
argument_list|,
literal|""
argument_list|,
name|parent
argument_list|,
name|before
argument_list|)
return|;
end_expr_stmt

begin_else
else|#
directive|else
end_else

begin_return
return|return
name|llvm
operator|::
name|BasicBlock
operator|::
name|Create
argument_list|(
name|getLLVMContext
argument_list|()
argument_list|,
name|name
argument_list|,
name|parent
argument_list|,
name|before
argument_list|)
return|;
end_return

begin_endif
endif|#
directive|endif
end_endif

begin_comment
unit|}
comment|/// getBasicBlockForLabel - Return the LLVM basicblock that the specified
end_comment

begin_comment
comment|/// label maps to.
end_comment

begin_expr_stmt
unit|JumpDest
name|getJumpDestForLabel
argument_list|(
specifier|const
name|LabelDecl
operator|*
name|S
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// SimplifyForwardingBlocks - If the given basic block is only a branch to
end_comment

begin_comment
comment|/// another basic block, simplify it. This assumes that no other code could
end_comment

begin_comment
comment|/// potentially reference the basic block.
end_comment

begin_decl_stmt
name|void
name|SimplifyForwardingBlocks
argument_list|(
name|llvm
operator|::
name|BasicBlock
operator|*
name|BB
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// EmitBlock - Emit the given block \arg BB and set it as the insert point,
end_comment

begin_comment
comment|/// adding a fall-through branch from the current insert block if
end_comment

begin_comment
comment|/// necessary. It is legal to call this function even if there is no current
end_comment

begin_comment
comment|/// insertion point.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// IsFinished - If true, indicates that the caller has finished emitting
end_comment

begin_comment
comment|/// branches to the given block and does not expect to emit code into it. This
end_comment

begin_comment
comment|/// means the block can be ignored if it is unreachable.
end_comment

begin_decl_stmt
name|void
name|EmitBlock
argument_list|(
name|llvm
operator|::
name|BasicBlock
operator|*
name|BB
argument_list|,
name|bool
name|IsFinished
operator|=
name|false
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// EmitBlockAfterUses - Emit the given block somewhere hopefully
end_comment

begin_comment
comment|/// near its uses, and leave the insertion point in it.
end_comment

begin_decl_stmt
name|void
name|EmitBlockAfterUses
argument_list|(
name|llvm
operator|::
name|BasicBlock
operator|*
name|BB
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// EmitBranch - Emit a branch to the specified basic block from the current
end_comment

begin_comment
comment|/// insert block, taking care to avoid creation of branches from dummy
end_comment

begin_comment
comment|/// blocks. It is legal to call this function even if there is no current
end_comment

begin_comment
comment|/// insertion point.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This function clears the current insertion point. The caller should follow
end_comment

begin_comment
comment|/// calls to this function with calls to Emit*Block prior to generation new
end_comment

begin_comment
comment|/// code.
end_comment

begin_decl_stmt
name|void
name|EmitBranch
argument_list|(
name|llvm
operator|::
name|BasicBlock
operator|*
name|Block
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// HaveInsertPoint - True if an insertion point is defined. If not, this
end_comment

begin_comment
comment|/// indicates that the current code being emitted is unreachable.
end_comment

begin_expr_stmt
name|bool
name|HaveInsertPoint
argument_list|()
specifier|const
block|{
return|return
name|Builder
operator|.
name|GetInsertBlock
argument_list|()
operator|!=
literal|0
return|;
block|}
end_expr_stmt

begin_comment
comment|/// EnsureInsertPoint - Ensure that an insertion point is defined so that
end_comment

begin_comment
comment|/// emitted IR has a place to go. Note that by definition, if this function
end_comment

begin_comment
comment|/// creates a block then that block is unreachable; callers may do better to
end_comment

begin_comment
comment|/// detect when no insertion point is defined and simply skip IR generation.
end_comment

begin_function
name|void
name|EnsureInsertPoint
parameter_list|()
block|{
if|if
condition|(
operator|!
name|HaveInsertPoint
argument_list|()
condition|)
name|EmitBlock
argument_list|(
name|createBasicBlock
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/// ErrorUnsupported - Print out an error that codegen doesn't support the
end_comment

begin_comment
comment|/// specified stmt yet.
end_comment

begin_function_decl
name|void
name|ErrorUnsupported
parameter_list|(
specifier|const
name|Stmt
modifier|*
name|S
parameter_list|,
specifier|const
name|char
modifier|*
name|Type
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|//===--------------------------------------------------------------------===//
end_comment

begin_comment
comment|//                                  Helpers
end_comment

begin_comment
comment|//===--------------------------------------------------------------------===//
end_comment

begin_decl_stmt
name|LValue
name|MakeAddrLValue
argument_list|(
name|llvm
operator|::
name|Value
operator|*
name|V
argument_list|,
name|QualType
name|T
argument_list|,
name|CharUnits
name|Alignment
operator|=
name|CharUnits
argument_list|()
argument_list|)
block|{
return|return
name|LValue
operator|::
name|MakeAddr
argument_list|(
name|V
argument_list|,
name|T
argument_list|,
name|Alignment
argument_list|,
name|getContext
argument_list|()
argument_list|,
name|CGM
operator|.
name|getTBAAInfo
argument_list|(
name|T
argument_list|)
argument_list|)
return|;
block|}
end_decl_stmt

begin_decl_stmt
name|LValue
name|MakeNaturalAlignAddrLValue
argument_list|(
name|llvm
operator|::
name|Value
operator|*
name|V
argument_list|,
name|QualType
name|T
argument_list|)
block|{
name|CharUnits
name|Alignment
decl_stmt|;
if|if
condition|(
operator|!
name|T
operator|->
name|isIncompleteType
argument_list|()
condition|)
name|Alignment
operator|=
name|getContext
argument_list|()
operator|.
name|getTypeAlignInChars
argument_list|(
name|T
argument_list|)
expr_stmt|;
return|return
name|LValue
operator|::
name|MakeAddr
argument_list|(
name|V
argument_list|,
name|T
argument_list|,
name|Alignment
argument_list|,
name|getContext
argument_list|()
argument_list|,
name|CGM
operator|.
name|getTBAAInfo
argument_list|(
name|T
argument_list|)
argument_list|)
return|;
block|}
end_decl_stmt

begin_comment
comment|/// CreateTempAlloca - This creates a alloca and inserts it into the entry
end_comment

begin_comment
comment|/// block. The caller is responsible for setting an appropriate alignment on
end_comment

begin_comment
comment|/// the alloca.
end_comment

begin_expr_stmt
name|llvm
operator|::
name|AllocaInst
operator|*
name|CreateTempAlloca
argument_list|(
name|llvm
operator|::
name|Type
operator|*
name|Ty
argument_list|,
specifier|const
name|Twine
operator|&
name|Name
operator|=
literal|"tmp"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// InitTempAlloca - Provide an initial value for the given alloca.
end_comment

begin_decl_stmt
name|void
name|InitTempAlloca
argument_list|(
name|llvm
operator|::
name|AllocaInst
operator|*
name|Alloca
argument_list|,
name|llvm
operator|::
name|Value
operator|*
name|Value
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// CreateIRTemp - Create a temporary IR object of the given type, with
end_comment

begin_comment
comment|/// appropriate alignment. This routine should only be used when an temporary
end_comment

begin_comment
comment|/// value needs to be stored into an alloca (for example, to avoid explicit
end_comment

begin_comment
comment|/// PHI construction), but the type is the IR type, not the type appropriate
end_comment

begin_comment
comment|/// for storing in memory.
end_comment

begin_expr_stmt
name|llvm
operator|::
name|AllocaInst
operator|*
name|CreateIRTemp
argument_list|(
argument|QualType T
argument_list|,
argument|const Twine&Name =
literal|"tmp"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// CreateMemTemp - Create a temporary memory object of the given type, with
end_comment

begin_comment
comment|/// appropriate alignment.
end_comment

begin_expr_stmt
name|llvm
operator|::
name|AllocaInst
operator|*
name|CreateMemTemp
argument_list|(
argument|QualType T
argument_list|,
argument|const Twine&Name =
literal|"tmp"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// CreateAggTemp - Create a temporary memory object for the given
end_comment

begin_comment
comment|/// aggregate type.
end_comment

begin_function
name|AggValueSlot
name|CreateAggTemp
parameter_list|(
name|QualType
name|T
parameter_list|,
specifier|const
name|Twine
modifier|&
name|Name
init|=
literal|"tmp"
parameter_list|)
block|{
name|CharUnits
name|Alignment
init|=
name|getContext
argument_list|()
operator|.
name|getTypeAlignInChars
argument_list|(
name|T
argument_list|)
decl_stmt|;
return|return
name|AggValueSlot
operator|::
name|forAddr
argument_list|(
name|CreateMemTemp
argument_list|(
name|T
argument_list|,
name|Name
argument_list|)
argument_list|,
name|Alignment
argument_list|,
name|T
operator|.
name|getQualifiers
argument_list|()
argument_list|,
name|AggValueSlot
operator|::
name|IsNotDestructed
argument_list|,
name|AggValueSlot
operator|::
name|DoesNotNeedGCBarriers
argument_list|,
name|AggValueSlot
operator|::
name|IsNotAliased
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/// Emit a cast to void* in the appropriate address space.
end_comment

begin_expr_stmt
name|llvm
operator|::
name|Value
operator|*
name|EmitCastToVoidPtr
argument_list|(
name|llvm
operator|::
name|Value
operator|*
name|value
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// EvaluateExprAsBool - Perform the usual unary conversions on the specified
end_comment

begin_comment
comment|/// expression and compare the result against zero, returning an Int1Ty value.
end_comment

begin_expr_stmt
name|llvm
operator|::
name|Value
operator|*
name|EvaluateExprAsBool
argument_list|(
specifier|const
name|Expr
operator|*
name|E
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// EmitIgnoredExpr - Emit an expression in a context which ignores the result.
end_comment

begin_function_decl
name|void
name|EmitIgnoredExpr
parameter_list|(
specifier|const
name|Expr
modifier|*
name|E
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// EmitAnyExpr - Emit code to compute the specified expression which can have
end_comment

begin_comment
comment|/// any type.  The result is returned as an RValue struct.  If this is an
end_comment

begin_comment
comment|/// aggregate expression, the aggloc/agglocvolatile arguments indicate where
end_comment

begin_comment
comment|/// the result should be returned.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param ignoreResult True if the resulting value isn't used.
end_comment

begin_function_decl
name|RValue
name|EmitAnyExpr
parameter_list|(
specifier|const
name|Expr
modifier|*
name|E
parameter_list|,
name|AggValueSlot
name|aggSlot
init|=
name|AggValueSlot
operator|::
name|ignored
argument_list|()
parameter_list|,
name|bool
name|ignoreResult
init|=
name|false
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|// EmitVAListRef - Emit a "reference" to a va_list; this is either the address
end_comment

begin_comment
comment|// or the value of the expression, depending on how va_list is defined.
end_comment

begin_expr_stmt
name|llvm
operator|::
name|Value
operator|*
name|EmitVAListRef
argument_list|(
specifier|const
name|Expr
operator|*
name|E
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// EmitAnyExprToTemp - Similary to EmitAnyExpr(), however, the result will
end_comment

begin_comment
comment|/// always be accessible even if no aggregate location is provided.
end_comment

begin_function_decl
name|RValue
name|EmitAnyExprToTemp
parameter_list|(
specifier|const
name|Expr
modifier|*
name|E
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// EmitAnyExprToMem - Emits the code necessary to evaluate an
end_comment

begin_comment
comment|/// arbitrary expression into the given memory location.
end_comment

begin_decl_stmt
name|void
name|EmitAnyExprToMem
argument_list|(
specifier|const
name|Expr
operator|*
name|E
argument_list|,
name|llvm
operator|::
name|Value
operator|*
name|Location
argument_list|,
name|Qualifiers
name|Quals
argument_list|,
name|bool
name|IsInitializer
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// EmitExprAsInit - Emits the code necessary to initialize a
end_comment

begin_comment
comment|/// location in memory with the given initializer.
end_comment

begin_function_decl
name|void
name|EmitExprAsInit
parameter_list|(
specifier|const
name|Expr
modifier|*
name|init
parameter_list|,
specifier|const
name|ValueDecl
modifier|*
name|D
parameter_list|,
name|LValue
name|lvalue
parameter_list|,
name|bool
name|capturedByInit
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// hasVolatileMember - returns true if aggregate type has a volatile
end_comment

begin_comment
comment|/// member.
end_comment

begin_function
name|bool
name|hasVolatileMember
parameter_list|(
name|QualType
name|T
parameter_list|)
block|{
if|if
condition|(
specifier|const
name|RecordType
modifier|*
name|RT
init|=
name|T
operator|->
name|getAs
operator|<
name|RecordType
operator|>
operator|(
operator|)
condition|)
block|{
specifier|const
name|RecordDecl
modifier|*
name|RD
init|=
name|cast
operator|<
name|RecordDecl
operator|>
operator|(
name|RT
operator|->
name|getDecl
argument_list|()
operator|)
decl_stmt|;
return|return
name|RD
operator|->
name|hasVolatileMember
argument_list|()
return|;
block|}
return|return
name|false
return|;
block|}
end_function

begin_comment
comment|/// EmitAggregateCopy - Emit an aggregate assignment.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// The difference to EmitAggregateCopy is that tail padding is not copied.
end_comment

begin_comment
comment|/// This is required for correctness when assigning non-POD structures in C++.
end_comment

begin_decl_stmt
name|void
name|EmitAggregateAssign
argument_list|(
name|llvm
operator|::
name|Value
operator|*
name|DestPtr
argument_list|,
name|llvm
operator|::
name|Value
operator|*
name|SrcPtr
argument_list|,
name|QualType
name|EltTy
argument_list|)
block|{
name|bool
name|IsVolatile
init|=
name|hasVolatileMember
argument_list|(
name|EltTy
argument_list|)
decl_stmt|;
name|EmitAggregateCopy
argument_list|(
name|DestPtr
argument_list|,
name|SrcPtr
argument_list|,
name|EltTy
argument_list|,
name|IsVolatile
argument_list|,
name|CharUnits
operator|::
name|Zero
argument_list|()
argument_list|,
name|true
argument_list|)
expr_stmt|;
block|}
end_decl_stmt

begin_comment
comment|/// EmitAggregateCopy - Emit an aggregate copy.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param isVolatile - True iff either the source or the destination is
end_comment

begin_comment
comment|/// volatile.
end_comment

begin_comment
comment|/// \param isAssignment - If false, allow padding to be copied.  This often
end_comment

begin_comment
comment|/// yields more efficient.
end_comment

begin_decl_stmt
name|void
name|EmitAggregateCopy
argument_list|(
name|llvm
operator|::
name|Value
operator|*
name|DestPtr
argument_list|,
name|llvm
operator|::
name|Value
operator|*
name|SrcPtr
argument_list|,
name|QualType
name|EltTy
argument_list|,
name|bool
name|isVolatile
operator|=
name|false
argument_list|,
name|CharUnits
name|Alignment
operator|=
name|CharUnits
operator|::
name|Zero
argument_list|()
argument_list|,
name|bool
name|isAssignment
operator|=
name|false
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// StartBlock - Start new block named N. If insert block is a dummy block
end_comment

begin_comment
comment|/// then reuse it.
end_comment

begin_function_decl
name|void
name|StartBlock
parameter_list|(
specifier|const
name|char
modifier|*
name|N
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// GetAddrOfLocalVar - Return the address of a local variable.
end_comment

begin_expr_stmt
name|llvm
operator|::
name|Value
operator|*
name|GetAddrOfLocalVar
argument_list|(
argument|const VarDecl *VD
argument_list|)
block|{
name|llvm
operator|::
name|Value
operator|*
name|Res
operator|=
name|LocalDeclMap
index|[
name|VD
index|]
block|;
name|assert
argument_list|(
name|Res
operator|&&
literal|"Invalid argument to GetAddrOfLocalVar(), no decl!"
argument_list|)
block|;
return|return
name|Res
return|;
block|}
end_expr_stmt

begin_comment
comment|/// getOpaqueLValueMapping - Given an opaque value expression (which
end_comment

begin_comment
comment|/// must be mapped to an l-value), return its mapping.
end_comment

begin_function
specifier|const
name|LValue
modifier|&
name|getOpaqueLValueMapping
parameter_list|(
specifier|const
name|OpaqueValueExpr
modifier|*
name|e
parameter_list|)
block|{
name|assert
argument_list|(
name|OpaqueValueMapping
operator|::
name|shouldBindAsLValue
argument_list|(
name|e
argument_list|)
argument_list|)
expr_stmt|;
name|llvm
operator|::
name|DenseMap
operator|<
specifier|const
name|OpaqueValueExpr
operator|*
operator|,
name|LValue
operator|>
operator|::
name|iterator
name|it
operator|=
name|OpaqueLValues
operator|.
name|find
argument_list|(
name|e
argument_list|)
expr_stmt|;
name|assert
argument_list|(
name|it
operator|!=
name|OpaqueLValues
operator|.
name|end
argument_list|()
operator|&&
literal|"no mapping for opaque value!"
argument_list|)
expr_stmt|;
return|return
name|it
operator|->
name|second
return|;
block|}
end_function

begin_comment
comment|/// getOpaqueRValueMapping - Given an opaque value expression (which
end_comment

begin_comment
comment|/// must be mapped to an r-value), return its mapping.
end_comment

begin_function
specifier|const
name|RValue
modifier|&
name|getOpaqueRValueMapping
parameter_list|(
specifier|const
name|OpaqueValueExpr
modifier|*
name|e
parameter_list|)
block|{
name|assert
argument_list|(
operator|!
name|OpaqueValueMapping
operator|::
name|shouldBindAsLValue
argument_list|(
name|e
argument_list|)
argument_list|)
expr_stmt|;
name|llvm
operator|::
name|DenseMap
operator|<
specifier|const
name|OpaqueValueExpr
operator|*
operator|,
name|RValue
operator|>
operator|::
name|iterator
name|it
operator|=
name|OpaqueRValues
operator|.
name|find
argument_list|(
name|e
argument_list|)
expr_stmt|;
name|assert
argument_list|(
name|it
operator|!=
name|OpaqueRValues
operator|.
name|end
argument_list|()
operator|&&
literal|"no mapping for opaque value!"
argument_list|)
expr_stmt|;
return|return
name|it
operator|->
name|second
return|;
block|}
end_function

begin_comment
comment|/// getAccessedFieldNo - Given an encoded value and a result number, return
end_comment

begin_comment
comment|/// the input field number being accessed.
end_comment

begin_decl_stmt
specifier|static
name|unsigned
name|getAccessedFieldNo
argument_list|(
name|unsigned
name|Idx
argument_list|,
specifier|const
name|llvm
operator|::
name|Constant
operator|*
name|Elts
argument_list|)
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|llvm
operator|::
name|BlockAddress
operator|*
name|GetAddrOfLabel
argument_list|(
specifier|const
name|LabelDecl
operator|*
name|L
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|llvm
operator|::
name|BasicBlock
operator|*
name|GetIndirectGotoBlock
argument_list|()
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// EmitNullInitialization - Generate code to set a value of the given type to
end_comment

begin_comment
comment|/// null, If the type contains data member pointers, they will be initialized
end_comment

begin_comment
comment|/// to -1 in accordance with the Itanium C++ ABI.
end_comment

begin_decl_stmt
name|void
name|EmitNullInitialization
argument_list|(
name|llvm
operator|::
name|Value
operator|*
name|DestPtr
argument_list|,
name|QualType
name|Ty
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|// EmitVAArg - Generate code to get an argument from the passed in pointer
end_comment

begin_comment
comment|// and update it accordingly. The return value is a pointer to the argument.
end_comment

begin_comment
comment|// FIXME: We should be able to get rid of this method and use the va_arg
end_comment

begin_comment
comment|// instruction in LLVM instead once it works well enough.
end_comment

begin_expr_stmt
name|llvm
operator|::
name|Value
operator|*
name|EmitVAArg
argument_list|(
argument|llvm::Value *VAListAddr
argument_list|,
argument|QualType Ty
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// emitArrayLength - Compute the length of an array, even if it's a
end_comment

begin_comment
comment|/// VLA, and drill down to the base element type.
end_comment

begin_expr_stmt
name|llvm
operator|::
name|Value
operator|*
name|emitArrayLength
argument_list|(
specifier|const
name|ArrayType
operator|*
name|arrayType
argument_list|,
name|QualType
operator|&
name|baseType
argument_list|,
name|llvm
operator|::
name|Value
operator|*
operator|&
name|addr
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// EmitVLASize - Capture all the sizes for the VLA expressions in
end_comment

begin_comment
comment|/// the given variably-modified type and store them in the VLASizeMap.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This function can be called with a null (unreachable) insert point.
end_comment

begin_function_decl
name|void
name|EmitVariablyModifiedType
parameter_list|(
name|QualType
name|Ty
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// getVLASize - Returns an LLVM value that corresponds to the size,
end_comment

begin_comment
comment|/// in non-variably-sized elements, of a variable length array type,
end_comment

begin_comment
comment|/// plus that largest non-variably-sized element type.  Assumes that
end_comment

begin_comment
comment|/// the type has already been emitted with EmitVariablyModifiedType.
end_comment

begin_expr_stmt
name|std
operator|::
name|pair
operator|<
name|llvm
operator|::
name|Value
operator|*
operator|,
name|QualType
operator|>
name|getVLASize
argument_list|(
specifier|const
name|VariableArrayType
operator|*
name|vla
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|std
operator|::
name|pair
operator|<
name|llvm
operator|::
name|Value
operator|*
operator|,
name|QualType
operator|>
name|getVLASize
argument_list|(
argument|QualType vla
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// LoadCXXThis - Load the value of 'this'. This function is only valid while
end_comment

begin_comment
comment|/// generating code for an C++ member function.
end_comment

begin_expr_stmt
name|llvm
operator|::
name|Value
operator|*
name|LoadCXXThis
argument_list|()
block|{
name|assert
argument_list|(
name|CXXThisValue
operator|&&
literal|"no 'this' value for this function"
argument_list|)
block|;
return|return
name|CXXThisValue
return|;
block|}
end_expr_stmt

begin_comment
comment|/// LoadCXXVTT - Load the VTT parameter to base constructors/destructors have
end_comment

begin_comment
comment|/// virtual bases.
end_comment

begin_comment
comment|// FIXME: Every place that calls LoadCXXVTT is something
end_comment

begin_comment
comment|// that needs to be abstracted properly.
end_comment

begin_expr_stmt
name|llvm
operator|::
name|Value
operator|*
name|LoadCXXVTT
argument_list|()
block|{
name|assert
argument_list|(
name|CXXStructorImplicitParamValue
operator|&&
literal|"no VTT value for this function"
argument_list|)
block|;
return|return
name|CXXStructorImplicitParamValue
return|;
block|}
end_expr_stmt

begin_comment
comment|/// LoadCXXStructorImplicitParam - Load the implicit parameter
end_comment

begin_comment
comment|/// for a constructor/destructor.
end_comment

begin_expr_stmt
name|llvm
operator|::
name|Value
operator|*
name|LoadCXXStructorImplicitParam
argument_list|()
block|{
name|assert
argument_list|(
name|CXXStructorImplicitParamValue
operator|&&
literal|"no implicit argument value for this function"
argument_list|)
block|;
return|return
name|CXXStructorImplicitParamValue
return|;
block|}
end_expr_stmt

begin_comment
comment|/// GetAddressOfBaseOfCompleteClass - Convert the given pointer to a
end_comment

begin_comment
comment|/// complete class to the given direct base.
end_comment

begin_expr_stmt
name|llvm
operator|::
name|Value
operator|*
name|GetAddressOfDirectBaseInCompleteClass
argument_list|(
argument|llvm::Value *Value
argument_list|,
argument|const CXXRecordDecl *Derived
argument_list|,
argument|const CXXRecordDecl *Base
argument_list|,
argument|bool BaseIsVirtual
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// GetAddressOfBaseClass - This function will add the necessary delta to the
end_comment

begin_comment
comment|/// load of 'this' and returns address of the base class.
end_comment

begin_expr_stmt
name|llvm
operator|::
name|Value
operator|*
name|GetAddressOfBaseClass
argument_list|(
argument|llvm::Value *Value
argument_list|,
argument|const CXXRecordDecl *Derived
argument_list|,
argument|CastExpr::path_const_iterator PathBegin
argument_list|,
argument|CastExpr::path_const_iterator PathEnd
argument_list|,
argument|bool NullCheckValue
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|llvm
operator|::
name|Value
operator|*
name|GetAddressOfDerivedClass
argument_list|(
argument|llvm::Value *Value
argument_list|,
argument|const CXXRecordDecl *Derived
argument_list|,
argument|CastExpr::path_const_iterator PathBegin
argument_list|,
argument|CastExpr::path_const_iterator PathEnd
argument_list|,
argument|bool NullCheckValue
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// GetVTTParameter - Return the VTT parameter that should be passed to a
end_comment

begin_comment
comment|/// base constructor/destructor with virtual bases.
end_comment

begin_comment
comment|/// FIXME: VTTs are Itanium ABI-specific, so the definition should move
end_comment

begin_comment
comment|/// to ItaniumCXXABI.cpp together with all the references to VTT.
end_comment

begin_expr_stmt
name|llvm
operator|::
name|Value
operator|*
name|GetVTTParameter
argument_list|(
argument|GlobalDecl GD
argument_list|,
argument|bool ForVirtualBase
argument_list|,
argument|bool Delegating
argument_list|)
expr_stmt|;
end_expr_stmt

begin_function_decl
name|void
name|EmitDelegateCXXConstructorCall
parameter_list|(
specifier|const
name|CXXConstructorDecl
modifier|*
name|Ctor
parameter_list|,
name|CXXCtorType
name|CtorType
parameter_list|,
specifier|const
name|FunctionArgList
modifier|&
name|Args
parameter_list|,
name|SourceLocation
name|Loc
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|// It's important not to confuse this and the previous function. Delegating
end_comment

begin_comment
comment|// constructors are the C++0x feature. The constructor delegate optimization
end_comment

begin_comment
comment|// is used to reduce duplication in the base and complete consturctors where
end_comment

begin_comment
comment|// they are substantially the same.
end_comment

begin_function_decl
name|void
name|EmitDelegatingCXXConstructorCall
parameter_list|(
specifier|const
name|CXXConstructorDecl
modifier|*
name|Ctor
parameter_list|,
specifier|const
name|FunctionArgList
modifier|&
name|Args
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
name|void
name|EmitCXXConstructorCall
argument_list|(
specifier|const
name|CXXConstructorDecl
operator|*
name|D
argument_list|,
name|CXXCtorType
name|Type
argument_list|,
name|bool
name|ForVirtualBase
argument_list|,
name|bool
name|Delegating
argument_list|,
name|llvm
operator|::
name|Value
operator|*
name|This
argument_list|,
name|CallExpr
operator|::
name|const_arg_iterator
name|ArgBeg
argument_list|,
name|CallExpr
operator|::
name|const_arg_iterator
name|ArgEnd
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|EmitSynthesizedCXXCopyCtorCall
argument_list|(
specifier|const
name|CXXConstructorDecl
operator|*
name|D
argument_list|,
name|llvm
operator|::
name|Value
operator|*
name|This
argument_list|,
name|llvm
operator|::
name|Value
operator|*
name|Src
argument_list|,
name|CallExpr
operator|::
name|const_arg_iterator
name|ArgBeg
argument_list|,
name|CallExpr
operator|::
name|const_arg_iterator
name|ArgEnd
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|EmitCXXAggrConstructorCall
argument_list|(
specifier|const
name|CXXConstructorDecl
operator|*
name|D
argument_list|,
specifier|const
name|ConstantArrayType
operator|*
name|ArrayTy
argument_list|,
name|llvm
operator|::
name|Value
operator|*
name|ArrayPtr
argument_list|,
name|CallExpr
operator|::
name|const_arg_iterator
name|ArgBeg
argument_list|,
name|CallExpr
operator|::
name|const_arg_iterator
name|ArgEnd
argument_list|,
name|bool
name|ZeroInitialization
operator|=
name|false
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|EmitCXXAggrConstructorCall
argument_list|(
specifier|const
name|CXXConstructorDecl
operator|*
name|D
argument_list|,
name|llvm
operator|::
name|Value
operator|*
name|NumElements
argument_list|,
name|llvm
operator|::
name|Value
operator|*
name|ArrayPtr
argument_list|,
name|CallExpr
operator|::
name|const_arg_iterator
name|ArgBeg
argument_list|,
name|CallExpr
operator|::
name|const_arg_iterator
name|ArgEnd
argument_list|,
name|bool
name|ZeroInitialization
operator|=
name|false
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|Destroyer
name|destroyCXXObject
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|EmitCXXDestructorCall
argument_list|(
specifier|const
name|CXXDestructorDecl
operator|*
name|D
argument_list|,
name|CXXDtorType
name|Type
argument_list|,
name|bool
name|ForVirtualBase
argument_list|,
name|bool
name|Delegating
argument_list|,
name|llvm
operator|::
name|Value
operator|*
name|This
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|EmitNewArrayInitializer
argument_list|(
specifier|const
name|CXXNewExpr
operator|*
name|E
argument_list|,
name|QualType
name|elementType
argument_list|,
name|llvm
operator|::
name|Value
operator|*
name|NewPtr
argument_list|,
name|llvm
operator|::
name|Value
operator|*
name|NumElements
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|EmitCXXTemporary
argument_list|(
specifier|const
name|CXXTemporary
operator|*
name|Temporary
argument_list|,
name|QualType
name|TempType
argument_list|,
name|llvm
operator|::
name|Value
operator|*
name|Ptr
argument_list|)
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|llvm
operator|::
name|Value
operator|*
name|EmitCXXNewExpr
argument_list|(
specifier|const
name|CXXNewExpr
operator|*
name|E
argument_list|)
expr_stmt|;
end_expr_stmt

begin_function_decl
name|void
name|EmitCXXDeleteExpr
parameter_list|(
specifier|const
name|CXXDeleteExpr
modifier|*
name|E
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
name|void
name|EmitDeleteCall
argument_list|(
specifier|const
name|FunctionDecl
operator|*
name|DeleteFD
argument_list|,
name|llvm
operator|::
name|Value
operator|*
name|Ptr
argument_list|,
name|QualType
name|DeleteTy
argument_list|)
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|llvm
operator|::
name|Value
operator|*
name|EmitCXXTypeidExpr
argument_list|(
specifier|const
name|CXXTypeidExpr
operator|*
name|E
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|llvm
operator|::
name|Value
operator|*
name|EmitDynamicCast
argument_list|(
name|llvm
operator|::
name|Value
operator|*
name|V
argument_list|,
specifier|const
name|CXXDynamicCastExpr
operator|*
name|DCE
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|llvm
operator|::
name|Value
operator|*
name|EmitCXXUuidofExpr
argument_list|(
specifier|const
name|CXXUuidofExpr
operator|*
name|E
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// \brief Situations in which we might emit a check for the suitability of a
end_comment

begin_comment
comment|///        pointer or glvalue.
end_comment

begin_enum
enum|enum
name|TypeCheckKind
block|{
comment|/// Checking the operand of a load. Must be suitably sized and aligned.
name|TCK_Load
block|,
comment|/// Checking the destination of a store. Must be suitably sized and aligned.
name|TCK_Store
block|,
comment|/// Checking the bound value in a reference binding. Must be suitably sized
comment|/// and aligned, but is not required to refer to an object (until the
comment|/// reference is used), per core issue 453.
name|TCK_ReferenceBinding
block|,
comment|/// Checking the object expression in a non-static data member access. Must
comment|/// be an object within its lifetime.
name|TCK_MemberAccess
block|,
comment|/// Checking the 'this' pointer for a call to a non-static member function.
comment|/// Must be an object within its lifetime.
name|TCK_MemberCall
block|,
comment|/// Checking the 'this' pointer for a constructor call.
name|TCK_ConstructorCall
block|,
comment|/// Checking the operand of a static_cast to a derived pointer type. Must be
comment|/// null or an object within its lifetime.
name|TCK_DowncastPointer
block|,
comment|/// Checking the operand of a static_cast to a derived reference type. Must
comment|/// be an object within its lifetime.
name|TCK_DowncastReference
block|}
enum|;
end_enum

begin_comment
comment|/// \brief Emit a check that \p V is the address of storage of the
end_comment

begin_comment
comment|/// appropriate size and alignment for an object of type \p Type.
end_comment

begin_decl_stmt
name|void
name|EmitTypeCheck
argument_list|(
name|TypeCheckKind
name|TCK
argument_list|,
name|SourceLocation
name|Loc
argument_list|,
name|llvm
operator|::
name|Value
operator|*
name|V
argument_list|,
name|QualType
name|Type
argument_list|,
name|CharUnits
name|Alignment
operator|=
name|CharUnits
operator|::
name|Zero
argument_list|()
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// \brief Emit a check that \p Base points into an array object, which
end_comment

begin_comment
comment|/// we can access at index \p Index. \p Accessed should be \c false if we
end_comment

begin_comment
comment|/// this expression is used as an lvalue, for instance in "&Arr[Idx]".
end_comment

begin_decl_stmt
name|void
name|EmitBoundsCheck
argument_list|(
specifier|const
name|Expr
operator|*
name|E
argument_list|,
specifier|const
name|Expr
operator|*
name|Base
argument_list|,
name|llvm
operator|::
name|Value
operator|*
name|Index
argument_list|,
name|QualType
name|IndexType
argument_list|,
name|bool
name|Accessed
argument_list|)
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|llvm
operator|::
name|Value
operator|*
name|EmitScalarPrePostIncDec
argument_list|(
argument|const UnaryOperator *E
argument_list|,
argument|LValue LV
argument_list|,
argument|bool isInc
argument_list|,
argument|bool isPre
argument_list|)
expr_stmt|;
end_expr_stmt

begin_function_decl
name|ComplexPairTy
name|EmitComplexPrePostIncDec
parameter_list|(
specifier|const
name|UnaryOperator
modifier|*
name|E
parameter_list|,
name|LValue
name|LV
parameter_list|,
name|bool
name|isInc
parameter_list|,
name|bool
name|isPre
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|//===--------------------------------------------------------------------===//
end_comment

begin_comment
comment|//                            Declaration Emission
end_comment

begin_comment
comment|//===--------------------------------------------------------------------===//
end_comment

begin_comment
comment|/// EmitDecl - Emit a declaration.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This function can be called with a null (unreachable) insert point.
end_comment

begin_function_decl
name|void
name|EmitDecl
parameter_list|(
specifier|const
name|Decl
modifier|&
name|D
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// EmitVarDecl - Emit a local variable declaration.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This function can be called with a null (unreachable) insert point.
end_comment

begin_function_decl
name|void
name|EmitVarDecl
parameter_list|(
specifier|const
name|VarDecl
modifier|&
name|D
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|EmitScalarInit
parameter_list|(
specifier|const
name|Expr
modifier|*
name|init
parameter_list|,
specifier|const
name|ValueDecl
modifier|*
name|D
parameter_list|,
name|LValue
name|lvalue
parameter_list|,
name|bool
name|capturedByInit
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
name|void
name|EmitScalarInit
argument_list|(
name|llvm
operator|::
name|Value
operator|*
name|init
argument_list|,
name|LValue
name|lvalue
argument_list|)
decl_stmt|;
end_decl_stmt

begin_typedef
typedef|typedef
name|void
name|SpecialInitFn
argument_list|(
name|CodeGenFunction
operator|&
name|Init
argument_list|,
specifier|const
name|VarDecl
operator|&
name|D
argument_list|,
name|llvm
operator|::
name|Value
operator|*
name|Address
argument_list|)
typedef|;
end_typedef

begin_comment
comment|/// EmitAutoVarDecl - Emit an auto variable declaration.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This function can be called with a null (unreachable) insert point.
end_comment

begin_function_decl
name|void
name|EmitAutoVarDecl
parameter_list|(
specifier|const
name|VarDecl
modifier|&
name|D
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
name|class
name|AutoVarEmission
block|{
name|friend
name|class
name|CodeGenFunction
decl_stmt|;
specifier|const
name|VarDecl
modifier|*
name|Variable
decl_stmt|;
comment|/// The alignment of the variable.
name|CharUnits
name|Alignment
decl_stmt|;
comment|/// The address of the alloca.  Null if the variable was emitted
comment|/// as a global constant.
name|llvm
operator|::
name|Value
operator|*
name|Address
expr_stmt|;
name|llvm
operator|::
name|Value
operator|*
name|NRVOFlag
expr_stmt|;
comment|/// True if the variable is a __block variable.
name|bool
name|IsByRef
decl_stmt|;
comment|/// True if the variable is of aggregate type and has a constant
comment|/// initializer.
name|bool
name|IsConstantAggregate
decl_stmt|;
comment|/// Non-null if we should use lifetime annotations.
name|llvm
operator|::
name|Value
operator|*
name|SizeForLifetimeMarkers
expr_stmt|;
struct|struct
name|Invalid
block|{}
struct|;
name|AutoVarEmission
argument_list|(
name|Invalid
argument_list|)
operator|:
name|Variable
argument_list|(
literal|0
argument_list|)
block|{}
name|AutoVarEmission
argument_list|(
specifier|const
name|VarDecl
operator|&
name|variable
argument_list|)
operator|:
name|Variable
argument_list|(
operator|&
name|variable
argument_list|)
operator|,
name|Address
argument_list|(
literal|0
argument_list|)
operator|,
name|NRVOFlag
argument_list|(
literal|0
argument_list|)
operator|,
name|IsByRef
argument_list|(
name|false
argument_list|)
operator|,
name|IsConstantAggregate
argument_list|(
name|false
argument_list|)
operator|,
name|SizeForLifetimeMarkers
argument_list|(
literal|0
argument_list|)
block|{}
name|bool
name|wasEmittedAsGlobal
argument_list|()
specifier|const
block|{
return|return
name|Address
operator|==
literal|0
return|;
block|}
name|public
label|:
specifier|static
name|AutoVarEmission
name|invalid
parameter_list|()
block|{
return|return
name|AutoVarEmission
argument_list|(
name|Invalid
argument_list|()
argument_list|)
return|;
block|}
name|bool
name|useLifetimeMarkers
argument_list|()
specifier|const
block|{
return|return
name|SizeForLifetimeMarkers
operator|!=
literal|0
return|;
block|}
name|llvm
operator|::
name|Value
operator|*
name|getSizeForLifetimeMarkers
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
name|useLifetimeMarkers
argument_list|()
argument_list|)
block|;
return|return
name|SizeForLifetimeMarkers
return|;
block|}
comment|/// Returns the raw, allocated address, which is not necessarily
comment|/// the address of the object itself.
name|llvm
operator|::
name|Value
operator|*
name|getAllocatedAddress
argument_list|()
specifier|const
block|{
return|return
name|Address
return|;
block|}
comment|/// Returns the address of the object within this declaration.
comment|/// Note that this does not chase the forwarding pointer for
comment|/// __block decls.
name|llvm
operator|::
name|Value
operator|*
name|getObjectAddress
argument_list|(
argument|CodeGenFunction&CGF
argument_list|)
specifier|const
block|{
if|if
condition|(
operator|!
name|IsByRef
condition|)
return|return
name|Address
return|;
return|return
name|CGF
operator|.
name|Builder
operator|.
name|CreateStructGEP
argument_list|(
name|Address
argument_list|,
name|CGF
operator|.
name|getByRefValueLLVMField
argument_list|(
name|Variable
argument_list|)
argument_list|,
name|Variable
operator|->
name|getNameAsString
argument_list|()
argument_list|)
return|;
block|}
end_decl_stmt

begin_function_decl
unit|};
name|AutoVarEmission
name|EmitAutoVarAlloca
parameter_list|(
specifier|const
name|VarDecl
modifier|&
name|var
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|EmitAutoVarInit
parameter_list|(
specifier|const
name|AutoVarEmission
modifier|&
name|emission
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|EmitAutoVarCleanups
parameter_list|(
specifier|const
name|AutoVarEmission
modifier|&
name|emission
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
name|void
name|emitAutoVarTypeCleanup
argument_list|(
specifier|const
name|AutoVarEmission
operator|&
name|emission
argument_list|,
name|QualType
operator|::
name|DestructionKind
name|dtorKind
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|EmitStaticVarDecl
argument_list|(
specifier|const
name|VarDecl
operator|&
name|D
argument_list|,
name|llvm
operator|::
name|GlobalValue
operator|::
name|LinkageTypes
name|Linkage
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// EmitParmDecl - Emit a ParmVarDecl or an ImplicitParamDecl.
end_comment

begin_decl_stmt
name|void
name|EmitParmDecl
argument_list|(
specifier|const
name|VarDecl
operator|&
name|D
argument_list|,
name|llvm
operator|::
name|Value
operator|*
name|Arg
argument_list|,
name|unsigned
name|ArgNo
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// protectFromPeepholes - Protect a value that we're intending to
end_comment

begin_comment
comment|/// store to the side, but which will probably be used later, from
end_comment

begin_comment
comment|/// aggressive peepholing optimizations that might delete it.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Pass the result to unprotectFromPeepholes to declare that
end_comment

begin_comment
comment|/// protection is no longer required.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// There's no particular reason why this shouldn't apply to
end_comment

begin_comment
comment|/// l-values, it's just that no existing peepholes work on pointers.
end_comment

begin_function_decl
name|PeepholeProtection
name|protectFromPeepholes
parameter_list|(
name|RValue
name|rvalue
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|unprotectFromPeepholes
parameter_list|(
name|PeepholeProtection
name|protection
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|//===--------------------------------------------------------------------===//
end_comment

begin_comment
comment|//                             Statement Emission
end_comment

begin_comment
comment|//===--------------------------------------------------------------------===//
end_comment

begin_comment
comment|/// EmitStopPoint - Emit a debug stoppoint if we are emitting debug info.
end_comment

begin_function_decl
name|void
name|EmitStopPoint
parameter_list|(
specifier|const
name|Stmt
modifier|*
name|S
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// EmitStmt - Emit the code for the statement \arg S. It is legal to call
end_comment

begin_comment
comment|/// this function even if there is no current insertion point.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This function may clear the current insertion point; callers should use
end_comment

begin_comment
comment|/// EnsureInsertPoint if they wish to subsequently generate code without first
end_comment

begin_comment
comment|/// calling EmitBlock, EmitBranch, or EmitStmt.
end_comment

begin_function_decl
name|void
name|EmitStmt
parameter_list|(
specifier|const
name|Stmt
modifier|*
name|S
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// EmitSimpleStmt - Try to emit a "simple" statement which does not
end_comment

begin_comment
comment|/// necessarily require an insertion point or debug information; typically
end_comment

begin_comment
comment|/// because the statement amounts to a jump or a container of other
end_comment

begin_comment
comment|/// statements.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \return True if the statement was handled.
end_comment

begin_function_decl
name|bool
name|EmitSimpleStmt
parameter_list|(
specifier|const
name|Stmt
modifier|*
name|S
parameter_list|)
function_decl|;
end_function_decl

begin_expr_stmt
name|llvm
operator|::
name|Value
operator|*
name|EmitCompoundStmt
argument_list|(
argument|const CompoundStmt&S
argument_list|,
argument|bool GetLast = false
argument_list|,
argument|AggValueSlot AVS = AggValueSlot::ignored()
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|llvm
operator|::
name|Value
operator|*
name|EmitCompoundStmtWithoutScope
argument_list|(
argument|const CompoundStmt&S
argument_list|,
argument|bool GetLast = false
argument_list|,
argument|AggValueSlot AVS =                                                 AggValueSlot::ignored()
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// EmitLabel - Emit the block for the given label. It is legal to call this
end_comment

begin_comment
comment|/// function even if there is no current insertion point.
end_comment

begin_function_decl
name|void
name|EmitLabel
parameter_list|(
specifier|const
name|LabelDecl
modifier|*
name|D
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|// helper for EmitLabelStmt.
end_comment

begin_function_decl
name|void
name|EmitLabelStmt
parameter_list|(
specifier|const
name|LabelStmt
modifier|&
name|S
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|EmitAttributedStmt
parameter_list|(
specifier|const
name|AttributedStmt
modifier|&
name|S
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|EmitGotoStmt
parameter_list|(
specifier|const
name|GotoStmt
modifier|&
name|S
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|EmitIndirectGotoStmt
parameter_list|(
specifier|const
name|IndirectGotoStmt
modifier|&
name|S
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|EmitIfStmt
parameter_list|(
specifier|const
name|IfStmt
modifier|&
name|S
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|EmitWhileStmt
parameter_list|(
specifier|const
name|WhileStmt
modifier|&
name|S
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|EmitDoStmt
parameter_list|(
specifier|const
name|DoStmt
modifier|&
name|S
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|EmitForStmt
parameter_list|(
specifier|const
name|ForStmt
modifier|&
name|S
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|EmitReturnStmt
parameter_list|(
specifier|const
name|ReturnStmt
modifier|&
name|S
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|EmitDeclStmt
parameter_list|(
specifier|const
name|DeclStmt
modifier|&
name|S
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|EmitBreakStmt
parameter_list|(
specifier|const
name|BreakStmt
modifier|&
name|S
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|EmitContinueStmt
parameter_list|(
specifier|const
name|ContinueStmt
modifier|&
name|S
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|EmitSwitchStmt
parameter_list|(
specifier|const
name|SwitchStmt
modifier|&
name|S
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|EmitDefaultStmt
parameter_list|(
specifier|const
name|DefaultStmt
modifier|&
name|S
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|EmitCaseStmt
parameter_list|(
specifier|const
name|CaseStmt
modifier|&
name|S
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|EmitCaseStmtRange
parameter_list|(
specifier|const
name|CaseStmt
modifier|&
name|S
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|EmitAsmStmt
parameter_list|(
specifier|const
name|AsmStmt
modifier|&
name|S
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|EmitObjCForCollectionStmt
parameter_list|(
specifier|const
name|ObjCForCollectionStmt
modifier|&
name|S
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|EmitObjCAtTryStmt
parameter_list|(
specifier|const
name|ObjCAtTryStmt
modifier|&
name|S
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|EmitObjCAtThrowStmt
parameter_list|(
specifier|const
name|ObjCAtThrowStmt
modifier|&
name|S
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|EmitObjCAtSynchronizedStmt
parameter_list|(
specifier|const
name|ObjCAtSynchronizedStmt
modifier|&
name|S
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|EmitObjCAutoreleasePoolStmt
parameter_list|(
specifier|const
name|ObjCAutoreleasePoolStmt
modifier|&
name|S
parameter_list|)
function_decl|;
end_function_decl

begin_expr_stmt
name|llvm
operator|::
name|Constant
operator|*
name|getUnwindResumeFn
argument_list|()
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|llvm
operator|::
name|Constant
operator|*
name|getUnwindResumeOrRethrowFn
argument_list|()
expr_stmt|;
end_expr_stmt

begin_function_decl
name|void
name|EnterCXXTryStmt
parameter_list|(
specifier|const
name|CXXTryStmt
modifier|&
name|S
parameter_list|,
name|bool
name|IsFnTryBlock
init|=
name|false
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ExitCXXTryStmt
parameter_list|(
specifier|const
name|CXXTryStmt
modifier|&
name|S
parameter_list|,
name|bool
name|IsFnTryBlock
init|=
name|false
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|EmitCXXTryStmt
parameter_list|(
specifier|const
name|CXXTryStmt
modifier|&
name|S
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|EmitSEHTryStmt
parameter_list|(
specifier|const
name|SEHTryStmt
modifier|&
name|S
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|EmitCXXForRangeStmt
parameter_list|(
specifier|const
name|CXXForRangeStmt
modifier|&
name|S
parameter_list|)
function_decl|;
end_function_decl

begin_expr_stmt
name|llvm
operator|::
name|Function
operator|*
name|EmitCapturedStmt
argument_list|(
argument|const CapturedStmt&S
argument_list|,
argument|CapturedRegionKind K
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|llvm
operator|::
name|Function
operator|*
name|GenerateCapturedStmtFunction
argument_list|(
argument|const CapturedDecl *CD
argument_list|,
argument|const RecordDecl *RD
argument_list|,
argument|SourceLocation Loc
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|//===--------------------------------------------------------------------===//
end_comment

begin_comment
comment|//                         LValue Expression Emission
end_comment

begin_comment
comment|//===--------------------------------------------------------------------===//
end_comment

begin_comment
comment|/// GetUndefRValue - Get an appropriate 'undef' rvalue for the given type.
end_comment

begin_function_decl
name|RValue
name|GetUndefRValue
parameter_list|(
name|QualType
name|Ty
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// EmitUnsupportedRValue - Emit a dummy r-value using the type of E
end_comment

begin_comment
comment|/// and issue an ErrorUnsupported style diagnostic (using the
end_comment

begin_comment
comment|/// provided Name).
end_comment

begin_function_decl
name|RValue
name|EmitUnsupportedRValue
parameter_list|(
specifier|const
name|Expr
modifier|*
name|E
parameter_list|,
specifier|const
name|char
modifier|*
name|Name
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// EmitUnsupportedLValue - Emit a dummy l-value using the type of E and issue
end_comment

begin_comment
comment|/// an ErrorUnsupported style diagnostic (using the provided Name).
end_comment

begin_function_decl
name|LValue
name|EmitUnsupportedLValue
parameter_list|(
specifier|const
name|Expr
modifier|*
name|E
parameter_list|,
specifier|const
name|char
modifier|*
name|Name
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// EmitLValue - Emit code to compute a designator that specifies the location
end_comment

begin_comment
comment|/// of the expression.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This can return one of two things: a simple address or a bitfield
end_comment

begin_comment
comment|/// reference.  In either case, the LLVM Value* in the LValue structure is
end_comment

begin_comment
comment|/// guaranteed to be an LLVM pointer type.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// If this returns a bitfield reference, nothing about the pointee type of
end_comment

begin_comment
comment|/// the LLVM value is known: For example, it may not be a pointer to an
end_comment

begin_comment
comment|/// integer.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// If this returns a normal address, and if the lvalue's C type is fixed
end_comment

begin_comment
comment|/// size, this method guarantees that the returned pointer type will point to
end_comment

begin_comment
comment|/// an LLVM type of the same size of the lvalue's type.  If the lvalue has a
end_comment

begin_comment
comment|/// variable length type, this is not possible.
end_comment

begin_comment
comment|///
end_comment

begin_function_decl
name|LValue
name|EmitLValue
parameter_list|(
specifier|const
name|Expr
modifier|*
name|E
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// \brief Same as EmitLValue but additionally we generate checking code to
end_comment

begin_comment
comment|/// guard against undefined behavior.  This is only suitable when we know
end_comment

begin_comment
comment|/// that the address will be used to access the object.
end_comment

begin_function_decl
name|LValue
name|EmitCheckedLValue
parameter_list|(
specifier|const
name|Expr
modifier|*
name|E
parameter_list|,
name|TypeCheckKind
name|TCK
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
name|RValue
name|convertTempToRValue
argument_list|(
name|llvm
operator|::
name|Value
operator|*
name|addr
argument_list|,
name|QualType
name|type
argument_list|,
name|SourceLocation
name|Loc
argument_list|)
decl_stmt|;
end_decl_stmt

begin_function_decl
name|void
name|EmitAtomicInit
parameter_list|(
name|Expr
modifier|*
name|E
parameter_list|,
name|LValue
name|lvalue
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|RValue
name|EmitAtomicLoad
parameter_list|(
name|LValue
name|lvalue
parameter_list|,
name|SourceLocation
name|loc
parameter_list|,
name|AggValueSlot
name|slot
init|=
name|AggValueSlot
operator|::
name|ignored
argument_list|()
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|EmitAtomicStore
parameter_list|(
name|RValue
name|rvalue
parameter_list|,
name|LValue
name|lvalue
parameter_list|,
name|bool
name|isInit
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// EmitToMemory - Change a scalar value from its value
end_comment

begin_comment
comment|/// representation to its in-memory representation.
end_comment

begin_expr_stmt
name|llvm
operator|::
name|Value
operator|*
name|EmitToMemory
argument_list|(
argument|llvm::Value *Value
argument_list|,
argument|QualType Ty
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// EmitFromMemory - Change a scalar value from its memory
end_comment

begin_comment
comment|/// representation to its value representation.
end_comment

begin_expr_stmt
name|llvm
operator|::
name|Value
operator|*
name|EmitFromMemory
argument_list|(
argument|llvm::Value *Value
argument_list|,
argument|QualType Ty
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// EmitLoadOfScalar - Load a scalar value from an address, taking
end_comment

begin_comment
comment|/// care to appropriately convert from the memory representation to
end_comment

begin_comment
comment|/// the LLVM value representation.
end_comment

begin_expr_stmt
name|llvm
operator|::
name|Value
operator|*
name|EmitLoadOfScalar
argument_list|(
argument|llvm::Value *Addr
argument_list|,
argument|bool Volatile
argument_list|,
argument|unsigned Alignment
argument_list|,
argument|QualType Ty
argument_list|,
argument|SourceLocation Loc
argument_list|,
argument|llvm::MDNode *TBAAInfo =
literal|0
argument_list|,
argument|QualType TBAABaseTy = QualType()
argument_list|,
argument|uint64_t TBAAOffset =
literal|0
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// EmitLoadOfScalar - Load a scalar value from an address, taking
end_comment

begin_comment
comment|/// care to appropriately convert from the memory representation to
end_comment

begin_comment
comment|/// the LLVM value representation.  The l-value must be a simple
end_comment

begin_comment
comment|/// l-value.
end_comment

begin_expr_stmt
name|llvm
operator|::
name|Value
operator|*
name|EmitLoadOfScalar
argument_list|(
argument|LValue lvalue
argument_list|,
argument|SourceLocation Loc
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// EmitStoreOfScalar - Store a scalar value to an address, taking
end_comment

begin_comment
comment|/// care to appropriately convert from the memory representation to
end_comment

begin_comment
comment|/// the LLVM value representation.
end_comment

begin_decl_stmt
name|void
name|EmitStoreOfScalar
argument_list|(
name|llvm
operator|::
name|Value
operator|*
name|Value
argument_list|,
name|llvm
operator|::
name|Value
operator|*
name|Addr
argument_list|,
name|bool
name|Volatile
argument_list|,
name|unsigned
name|Alignment
argument_list|,
name|QualType
name|Ty
argument_list|,
name|llvm
operator|::
name|MDNode
operator|*
name|TBAAInfo
operator|=
literal|0
argument_list|,
name|bool
name|isInit
operator|=
name|false
argument_list|,
name|QualType
name|TBAABaseTy
operator|=
name|QualType
argument_list|()
argument_list|,
name|uint64_t
name|TBAAOffset
operator|=
literal|0
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// EmitStoreOfScalar - Store a scalar value to an address, taking
end_comment

begin_comment
comment|/// care to appropriately convert from the memory representation to
end_comment

begin_comment
comment|/// the LLVM value representation.  The l-value must be a simple
end_comment

begin_comment
comment|/// l-value.  The isInit flag indicates whether this is an initialization.
end_comment

begin_comment
comment|/// If so, atomic qualifiers are ignored and the store is always non-atomic.
end_comment

begin_decl_stmt
name|void
name|EmitStoreOfScalar
argument_list|(
name|llvm
operator|::
name|Value
operator|*
name|value
argument_list|,
name|LValue
name|lvalue
argument_list|,
name|bool
name|isInit
operator|=
name|false
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// EmitLoadOfLValue - Given an expression that represents a value lvalue,
end_comment

begin_comment
comment|/// this method emits the address of the lvalue, then loads the result as an
end_comment

begin_comment
comment|/// rvalue, returning the rvalue.
end_comment

begin_function_decl
name|RValue
name|EmitLoadOfLValue
parameter_list|(
name|LValue
name|V
parameter_list|,
name|SourceLocation
name|Loc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|RValue
name|EmitLoadOfExtVectorElementLValue
parameter_list|(
name|LValue
name|V
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|RValue
name|EmitLoadOfBitfieldLValue
parameter_list|(
name|LValue
name|LV
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// EmitStoreThroughLValue - Store the specified rvalue into the specified
end_comment

begin_comment
comment|/// lvalue, where both are guaranteed to the have the same type, and that type
end_comment

begin_comment
comment|/// is 'Ty'.
end_comment

begin_function_decl
name|void
name|EmitStoreThroughLValue
parameter_list|(
name|RValue
name|Src
parameter_list|,
name|LValue
name|Dst
parameter_list|,
name|bool
name|isInit
init|=
name|false
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|EmitStoreThroughExtVectorComponentLValue
parameter_list|(
name|RValue
name|Src
parameter_list|,
name|LValue
name|Dst
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// EmitStoreThroughBitfieldLValue - Store Src into Dst with same constraints
end_comment

begin_comment
comment|/// as EmitStoreThroughLValue.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param Result [out] - If non-null, this will be set to a Value* for the
end_comment

begin_comment
comment|/// bit-field contents after the store, appropriate for use as the result of
end_comment

begin_comment
comment|/// an assignment to the bit-field.
end_comment

begin_decl_stmt
name|void
name|EmitStoreThroughBitfieldLValue
argument_list|(
name|RValue
name|Src
argument_list|,
name|LValue
name|Dst
argument_list|,
name|llvm
operator|::
name|Value
operator|*
operator|*
name|Result
operator|=
literal|0
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// Emit an l-value for an assignment (simple or compound) of complex type.
end_comment

begin_function_decl
name|LValue
name|EmitComplexAssignmentLValue
parameter_list|(
specifier|const
name|BinaryOperator
modifier|*
name|E
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|LValue
name|EmitComplexCompoundAssignmentLValue
parameter_list|(
specifier|const
name|CompoundAssignOperator
modifier|*
name|E
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
name|LValue
name|EmitScalarCompooundAssignWithComplex
argument_list|(
specifier|const
name|CompoundAssignOperator
operator|*
name|E
argument_list|,
name|llvm
operator|::
name|Value
operator|*
operator|&
name|Result
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|// Note: only available for agg return types
end_comment

begin_function_decl
name|LValue
name|EmitBinaryOperatorLValue
parameter_list|(
specifier|const
name|BinaryOperator
modifier|*
name|E
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|LValue
name|EmitCompoundAssignmentLValue
parameter_list|(
specifier|const
name|CompoundAssignOperator
modifier|*
name|E
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|// Note: only available for agg return types
end_comment

begin_function_decl
name|LValue
name|EmitCallExprLValue
parameter_list|(
specifier|const
name|CallExpr
modifier|*
name|E
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|// Note: only available for agg return types
end_comment

begin_function_decl
name|LValue
name|EmitVAArgExprLValue
parameter_list|(
specifier|const
name|VAArgExpr
modifier|*
name|E
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|LValue
name|EmitDeclRefLValue
parameter_list|(
specifier|const
name|DeclRefExpr
modifier|*
name|E
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|LValue
name|EmitStringLiteralLValue
parameter_list|(
specifier|const
name|StringLiteral
modifier|*
name|E
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|LValue
name|EmitObjCEncodeExprLValue
parameter_list|(
specifier|const
name|ObjCEncodeExpr
modifier|*
name|E
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|LValue
name|EmitPredefinedLValue
parameter_list|(
specifier|const
name|PredefinedExpr
modifier|*
name|E
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|LValue
name|EmitUnaryOpLValue
parameter_list|(
specifier|const
name|UnaryOperator
modifier|*
name|E
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|LValue
name|EmitArraySubscriptExpr
parameter_list|(
specifier|const
name|ArraySubscriptExpr
modifier|*
name|E
parameter_list|,
name|bool
name|Accessed
init|=
name|false
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|LValue
name|EmitExtVectorElementExpr
parameter_list|(
specifier|const
name|ExtVectorElementExpr
modifier|*
name|E
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|LValue
name|EmitMemberExpr
parameter_list|(
specifier|const
name|MemberExpr
modifier|*
name|E
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|LValue
name|EmitObjCIsaExpr
parameter_list|(
specifier|const
name|ObjCIsaExpr
modifier|*
name|E
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|LValue
name|EmitCompoundLiteralLValue
parameter_list|(
specifier|const
name|CompoundLiteralExpr
modifier|*
name|E
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|LValue
name|EmitInitListLValue
parameter_list|(
specifier|const
name|InitListExpr
modifier|*
name|E
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|LValue
name|EmitConditionalOperatorLValue
parameter_list|(
specifier|const
name|AbstractConditionalOperator
modifier|*
name|E
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|LValue
name|EmitCastLValue
parameter_list|(
specifier|const
name|CastExpr
modifier|*
name|E
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|LValue
name|EmitMaterializeTemporaryExpr
parameter_list|(
specifier|const
name|MaterializeTemporaryExpr
modifier|*
name|E
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|LValue
name|EmitOpaqueValueLValue
parameter_list|(
specifier|const
name|OpaqueValueExpr
modifier|*
name|e
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|RValue
name|EmitRValueForField
parameter_list|(
name|LValue
name|LV
parameter_list|,
specifier|const
name|FieldDecl
modifier|*
name|FD
parameter_list|,
name|SourceLocation
name|Loc
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
name|class
name|ConstantEmission
block|{
name|llvm
operator|::
name|PointerIntPair
operator|<
name|llvm
operator|::
name|Constant
operator|*
operator|,
literal|1
operator|,
name|bool
operator|>
name|ValueAndIsReference
expr_stmt|;
name|ConstantEmission
argument_list|(
argument|llvm::Constant *C
argument_list|,
argument|bool isReference
argument_list|)
block|:
name|ValueAndIsReference
argument_list|(
argument|C
argument_list|,
argument|isReference
argument_list|)
block|{}
name|public
label|:
name|ConstantEmission
argument_list|()
block|{}
specifier|static
name|ConstantEmission
name|forReference
argument_list|(
name|llvm
operator|::
name|Constant
operator|*
name|C
argument_list|)
block|{
return|return
name|ConstantEmission
argument_list|(
name|C
argument_list|,
name|true
argument_list|)
return|;
block|}
specifier|static
name|ConstantEmission
name|forValue
argument_list|(
name|llvm
operator|::
name|Constant
operator|*
name|C
argument_list|)
block|{
return|return
name|ConstantEmission
argument_list|(
name|C
argument_list|,
name|false
argument_list|)
return|;
block|}
name|LLVM_EXPLICIT
name|operator
name|bool
argument_list|()
specifier|const
block|{
return|return
name|ValueAndIsReference
operator|.
name|getOpaqueValue
argument_list|()
operator|!=
literal|0
return|;
block|}
name|bool
name|isReference
argument_list|()
specifier|const
block|{
return|return
name|ValueAndIsReference
operator|.
name|getInt
argument_list|()
return|;
block|}
name|LValue
name|getReferenceLValue
argument_list|(
name|CodeGenFunction
operator|&
name|CGF
argument_list|,
name|Expr
operator|*
name|refExpr
argument_list|)
decl|const
block|{
name|assert
argument_list|(
name|isReference
argument_list|()
argument_list|)
expr_stmt|;
return|return
name|CGF
operator|.
name|MakeNaturalAlignAddrLValue
argument_list|(
name|ValueAndIsReference
operator|.
name|getPointer
argument_list|()
argument_list|,
name|refExpr
operator|->
name|getType
argument_list|()
argument_list|)
return|;
block|}
name|llvm
operator|::
name|Constant
operator|*
name|getValue
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
operator|!
name|isReference
argument_list|()
argument_list|)
block|;
return|return
name|ValueAndIsReference
operator|.
name|getPointer
argument_list|()
return|;
block|}
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_function_decl
name|ConstantEmission
name|tryEmitAsConstant
parameter_list|(
name|DeclRefExpr
modifier|*
name|refExpr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|RValue
name|EmitPseudoObjectRValue
parameter_list|(
specifier|const
name|PseudoObjectExpr
modifier|*
name|e
parameter_list|,
name|AggValueSlot
name|slot
init|=
name|AggValueSlot
operator|::
name|ignored
argument_list|()
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|LValue
name|EmitPseudoObjectLValue
parameter_list|(
specifier|const
name|PseudoObjectExpr
modifier|*
name|e
parameter_list|)
function_decl|;
end_function_decl

begin_expr_stmt
name|llvm
operator|::
name|Value
operator|*
name|EmitIvarOffset
argument_list|(
specifier|const
name|ObjCInterfaceDecl
operator|*
name|Interface
argument_list|,
specifier|const
name|ObjCIvarDecl
operator|*
name|Ivar
argument_list|)
expr_stmt|;
end_expr_stmt

begin_function_decl
name|LValue
name|EmitLValueForField
parameter_list|(
name|LValue
name|Base
parameter_list|,
specifier|const
name|FieldDecl
modifier|*
name|Field
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|LValue
name|EmitLValueForLambdaField
parameter_list|(
specifier|const
name|FieldDecl
modifier|*
name|Field
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// EmitLValueForFieldInitialization - Like EmitLValueForField, except that
end_comment

begin_comment
comment|/// if the Field is a reference, this will return the address of the reference
end_comment

begin_comment
comment|/// and not the address of the value stored in the reference.
end_comment

begin_function_decl
name|LValue
name|EmitLValueForFieldInitialization
parameter_list|(
name|LValue
name|Base
parameter_list|,
specifier|const
name|FieldDecl
modifier|*
name|Field
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
name|LValue
name|EmitLValueForIvar
argument_list|(
name|QualType
name|ObjectTy
argument_list|,
name|llvm
operator|::
name|Value
operator|*
name|Base
argument_list|,
specifier|const
name|ObjCIvarDecl
operator|*
name|Ivar
argument_list|,
name|unsigned
name|CVRQualifiers
argument_list|)
decl_stmt|;
end_decl_stmt

begin_function_decl
name|LValue
name|EmitCXXConstructLValue
parameter_list|(
specifier|const
name|CXXConstructExpr
modifier|*
name|E
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|LValue
name|EmitCXXBindTemporaryLValue
parameter_list|(
specifier|const
name|CXXBindTemporaryExpr
modifier|*
name|E
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|LValue
name|EmitLambdaLValue
parameter_list|(
specifier|const
name|LambdaExpr
modifier|*
name|E
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|LValue
name|EmitCXXTypeidLValue
parameter_list|(
specifier|const
name|CXXTypeidExpr
modifier|*
name|E
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|LValue
name|EmitCXXUuidofLValue
parameter_list|(
specifier|const
name|CXXUuidofExpr
modifier|*
name|E
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|LValue
name|EmitObjCMessageExprLValue
parameter_list|(
specifier|const
name|ObjCMessageExpr
modifier|*
name|E
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|LValue
name|EmitObjCIvarRefLValue
parameter_list|(
specifier|const
name|ObjCIvarRefExpr
modifier|*
name|E
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|LValue
name|EmitStmtExprLValue
parameter_list|(
specifier|const
name|StmtExpr
modifier|*
name|E
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|LValue
name|EmitPointerToDataMemberBinaryExpr
parameter_list|(
specifier|const
name|BinaryOperator
modifier|*
name|E
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|LValue
name|EmitObjCSelectorLValue
parameter_list|(
specifier|const
name|ObjCSelectorExpr
modifier|*
name|E
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
name|void
name|EmitDeclRefExprDbgValue
argument_list|(
specifier|const
name|DeclRefExpr
operator|*
name|E
argument_list|,
name|llvm
operator|::
name|Constant
operator|*
name|Init
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|//===--------------------------------------------------------------------===//
end_comment

begin_comment
comment|//                         Scalar Expression Emission
end_comment

begin_comment
comment|//===--------------------------------------------------------------------===//
end_comment

begin_comment
comment|/// EmitCall - Generate a call of the given function, expecting the given
end_comment

begin_comment
comment|/// result type, and using the given argument list which specifies both the
end_comment

begin_comment
comment|/// LLVM arguments and the types they were derived from.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param TargetDecl - If given, the decl of the function in a direct call;
end_comment

begin_comment
comment|/// used to set attributes on the call (noreturn, etc.).
end_comment

begin_decl_stmt
name|RValue
name|EmitCall
argument_list|(
specifier|const
name|CGFunctionInfo
operator|&
name|FnInfo
argument_list|,
name|llvm
operator|::
name|Value
operator|*
name|Callee
argument_list|,
name|ReturnValueSlot
name|ReturnValue
argument_list|,
specifier|const
name|CallArgList
operator|&
name|Args
argument_list|,
specifier|const
name|Decl
operator|*
name|TargetDecl
operator|=
literal|0
argument_list|,
name|llvm
operator|::
name|Instruction
operator|*
operator|*
name|callOrInvoke
operator|=
literal|0
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|RValue
name|EmitCall
argument_list|(
name|QualType
name|FnType
argument_list|,
name|llvm
operator|::
name|Value
operator|*
name|Callee
argument_list|,
name|SourceLocation
name|CallLoc
argument_list|,
name|ReturnValueSlot
name|ReturnValue
argument_list|,
name|CallExpr
operator|::
name|const_arg_iterator
name|ArgBeg
argument_list|,
name|CallExpr
operator|::
name|const_arg_iterator
name|ArgEnd
argument_list|,
specifier|const
name|Decl
operator|*
name|TargetDecl
operator|=
literal|0
argument_list|)
decl_stmt|;
end_decl_stmt

begin_function_decl
name|RValue
name|EmitCallExpr
parameter_list|(
specifier|const
name|CallExpr
modifier|*
name|E
parameter_list|,
name|ReturnValueSlot
name|ReturnValue
init|=
name|ReturnValueSlot
argument_list|()
parameter_list|)
function_decl|;
end_function_decl

begin_expr_stmt
name|llvm
operator|::
name|CallInst
operator|*
name|EmitRuntimeCall
argument_list|(
name|llvm
operator|::
name|Value
operator|*
name|callee
argument_list|,
specifier|const
name|Twine
operator|&
name|name
operator|=
literal|""
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|llvm
operator|::
name|CallInst
operator|*
name|EmitRuntimeCall
argument_list|(
name|llvm
operator|::
name|Value
operator|*
name|callee
argument_list|,
name|ArrayRef
operator|<
name|llvm
operator|::
name|Value
operator|*
operator|>
name|args
argument_list|,
specifier|const
name|Twine
operator|&
name|name
operator|=
literal|""
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|llvm
operator|::
name|CallInst
operator|*
name|EmitNounwindRuntimeCall
argument_list|(
name|llvm
operator|::
name|Value
operator|*
name|callee
argument_list|,
specifier|const
name|Twine
operator|&
name|name
operator|=
literal|""
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|llvm
operator|::
name|CallInst
operator|*
name|EmitNounwindRuntimeCall
argument_list|(
name|llvm
operator|::
name|Value
operator|*
name|callee
argument_list|,
name|ArrayRef
operator|<
name|llvm
operator|::
name|Value
operator|*
operator|>
name|args
argument_list|,
specifier|const
name|Twine
operator|&
name|name
operator|=
literal|""
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|llvm
operator|::
name|CallSite
name|EmitCallOrInvoke
argument_list|(
name|llvm
operator|::
name|Value
operator|*
name|Callee
argument_list|,
name|ArrayRef
operator|<
name|llvm
operator|::
name|Value
operator|*
operator|>
name|Args
argument_list|,
specifier|const
name|Twine
operator|&
name|Name
operator|=
literal|""
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|llvm
operator|::
name|CallSite
name|EmitCallOrInvoke
argument_list|(
name|llvm
operator|::
name|Value
operator|*
name|Callee
argument_list|,
specifier|const
name|Twine
operator|&
name|Name
operator|=
literal|""
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|llvm
operator|::
name|CallSite
name|EmitRuntimeCallOrInvoke
argument_list|(
name|llvm
operator|::
name|Value
operator|*
name|callee
argument_list|,
name|ArrayRef
operator|<
name|llvm
operator|::
name|Value
operator|*
operator|>
name|args
argument_list|,
specifier|const
name|Twine
operator|&
name|name
operator|=
literal|""
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|llvm
operator|::
name|CallSite
name|EmitRuntimeCallOrInvoke
argument_list|(
name|llvm
operator|::
name|Value
operator|*
name|callee
argument_list|,
specifier|const
name|Twine
operator|&
name|name
operator|=
literal|""
argument_list|)
expr_stmt|;
end_expr_stmt

begin_decl_stmt
name|void
name|EmitNoreturnRuntimeCallOrInvoke
argument_list|(
name|llvm
operator|::
name|Value
operator|*
name|callee
argument_list|,
name|ArrayRef
operator|<
name|llvm
operator|::
name|Value
operator|*
operator|>
name|args
argument_list|)
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|llvm
operator|::
name|Value
operator|*
name|BuildAppleKextVirtualCall
argument_list|(
specifier|const
name|CXXMethodDecl
operator|*
name|MD
argument_list|,
name|NestedNameSpecifier
operator|*
name|Qual
argument_list|,
name|llvm
operator|::
name|Type
operator|*
name|Ty
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|llvm
operator|::
name|Value
operator|*
name|BuildAppleKextVirtualDestructorCall
argument_list|(
argument|const CXXDestructorDecl *DD
argument_list|,
argument|CXXDtorType Type
argument_list|,
argument|const CXXRecordDecl *RD
argument_list|)
expr_stmt|;
end_expr_stmt

begin_decl_stmt
name|RValue
name|EmitCXXMemberCall
argument_list|(
specifier|const
name|CXXMethodDecl
operator|*
name|MD
argument_list|,
name|SourceLocation
name|CallLoc
argument_list|,
name|llvm
operator|::
name|Value
operator|*
name|Callee
argument_list|,
name|ReturnValueSlot
name|ReturnValue
argument_list|,
name|llvm
operator|::
name|Value
operator|*
name|This
argument_list|,
name|llvm
operator|::
name|Value
operator|*
name|ImplicitParam
argument_list|,
name|QualType
name|ImplicitParamTy
argument_list|,
name|CallExpr
operator|::
name|const_arg_iterator
name|ArgBeg
argument_list|,
name|CallExpr
operator|::
name|const_arg_iterator
name|ArgEnd
argument_list|)
decl_stmt|;
end_decl_stmt

begin_function_decl
name|RValue
name|EmitCXXMemberCallExpr
parameter_list|(
specifier|const
name|CXXMemberCallExpr
modifier|*
name|E
parameter_list|,
name|ReturnValueSlot
name|ReturnValue
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|RValue
name|EmitCXXMemberPointerCallExpr
parameter_list|(
specifier|const
name|CXXMemberCallExpr
modifier|*
name|E
parameter_list|,
name|ReturnValueSlot
name|ReturnValue
parameter_list|)
function_decl|;
end_function_decl

begin_expr_stmt
name|llvm
operator|::
name|Value
operator|*
name|EmitCXXOperatorMemberCallee
argument_list|(
specifier|const
name|CXXOperatorCallExpr
operator|*
name|E
argument_list|,
specifier|const
name|CXXMethodDecl
operator|*
name|MD
argument_list|,
name|llvm
operator|::
name|Value
operator|*
name|This
argument_list|)
expr_stmt|;
end_expr_stmt

begin_function_decl
name|RValue
name|EmitCXXOperatorMemberCallExpr
parameter_list|(
specifier|const
name|CXXOperatorCallExpr
modifier|*
name|E
parameter_list|,
specifier|const
name|CXXMethodDecl
modifier|*
name|MD
parameter_list|,
name|ReturnValueSlot
name|ReturnValue
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|RValue
name|EmitCUDAKernelCallExpr
parameter_list|(
specifier|const
name|CUDAKernelCallExpr
modifier|*
name|E
parameter_list|,
name|ReturnValueSlot
name|ReturnValue
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|RValue
name|EmitBuiltinExpr
parameter_list|(
specifier|const
name|FunctionDecl
modifier|*
name|FD
parameter_list|,
name|unsigned
name|BuiltinID
parameter_list|,
specifier|const
name|CallExpr
modifier|*
name|E
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|RValue
name|EmitBlockCallExpr
parameter_list|(
specifier|const
name|CallExpr
modifier|*
name|E
parameter_list|,
name|ReturnValueSlot
name|ReturnValue
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// EmitTargetBuiltinExpr - Emit the given builtin call. Returns 0 if the call
end_comment

begin_comment
comment|/// is unhandled by the current target.
end_comment

begin_expr_stmt
name|llvm
operator|::
name|Value
operator|*
name|EmitTargetBuiltinExpr
argument_list|(
argument|unsigned BuiltinID
argument_list|,
argument|const CallExpr *E
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|llvm
operator|::
name|Value
operator|*
name|EmitAArch64CompareBuiltinExpr
argument_list|(
argument|llvm::Value *Op
argument_list|,
argument|llvm::Type *Ty
argument_list|,
argument|const llvm::CmpInst::Predicate Fp
argument_list|,
argument|const llvm::CmpInst::Predicate Ip
argument_list|,
argument|const llvm::Twine&Name =
literal|""
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|llvm
operator|::
name|Value
operator|*
name|EmitAArch64CompareBuiltinExpr
argument_list|(
name|llvm
operator|::
name|Value
operator|*
name|Op
argument_list|,
name|llvm
operator|::
name|Type
operator|*
name|Ty
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|llvm
operator|::
name|Value
operator|*
name|EmitAArch64BuiltinExpr
argument_list|(
argument|unsigned BuiltinID
argument_list|,
argument|const CallExpr *E
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|llvm
operator|::
name|Value
operator|*
name|EmitARMBuiltinExpr
argument_list|(
argument|unsigned BuiltinID
argument_list|,
argument|const CallExpr *E
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|llvm
operator|::
name|Value
operator|*
name|EmitNeonCall
argument_list|(
argument|llvm::Function *F
argument_list|,
argument|SmallVectorImpl<llvm::Value*>&O
argument_list|,
argument|const char *name
argument_list|,
argument|unsigned shift =
literal|0
argument_list|,
argument|bool rightshift = false
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|llvm
operator|::
name|Value
operator|*
name|EmitNeonSplat
argument_list|(
name|llvm
operator|::
name|Value
operator|*
name|V
argument_list|,
name|llvm
operator|::
name|Constant
operator|*
name|Idx
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|llvm
operator|::
name|Value
operator|*
name|EmitNeonShiftVector
argument_list|(
argument|llvm::Value *V
argument_list|,
argument|llvm::Type *Ty
argument_list|,
argument|bool negateForRightShift
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|llvm
operator|::
name|Value
operator|*
name|EmitNeonRShiftImm
argument_list|(
argument|llvm::Value *Vec
argument_list|,
argument|llvm::Value *Amt
argument_list|,
argument|llvm::Type *Ty
argument_list|,
argument|bool usgn
argument_list|,
argument|const char *name
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|llvm
operator|::
name|Value
operator|*
name|BuildVector
argument_list|(
name|ArrayRef
operator|<
name|llvm
operator|::
name|Value
operator|*
operator|>
name|Ops
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|llvm
operator|::
name|Value
operator|*
name|EmitX86BuiltinExpr
argument_list|(
argument|unsigned BuiltinID
argument_list|,
argument|const CallExpr *E
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|llvm
operator|::
name|Value
operator|*
name|EmitPPCBuiltinExpr
argument_list|(
argument|unsigned BuiltinID
argument_list|,
argument|const CallExpr *E
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|llvm
operator|::
name|Value
operator|*
name|EmitObjCProtocolExpr
argument_list|(
specifier|const
name|ObjCProtocolExpr
operator|*
name|E
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|llvm
operator|::
name|Value
operator|*
name|EmitObjCStringLiteral
argument_list|(
specifier|const
name|ObjCStringLiteral
operator|*
name|E
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|llvm
operator|::
name|Value
operator|*
name|EmitObjCBoxedExpr
argument_list|(
specifier|const
name|ObjCBoxedExpr
operator|*
name|E
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|llvm
operator|::
name|Value
operator|*
name|EmitObjCArrayLiteral
argument_list|(
specifier|const
name|ObjCArrayLiteral
operator|*
name|E
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|llvm
operator|::
name|Value
operator|*
name|EmitObjCDictionaryLiteral
argument_list|(
specifier|const
name|ObjCDictionaryLiteral
operator|*
name|E
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|llvm
operator|::
name|Value
operator|*
name|EmitObjCCollectionLiteral
argument_list|(
specifier|const
name|Expr
operator|*
name|E
argument_list|,
specifier|const
name|ObjCMethodDecl
operator|*
name|MethodWithObjects
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|llvm
operator|::
name|Value
operator|*
name|EmitObjCSelectorExpr
argument_list|(
specifier|const
name|ObjCSelectorExpr
operator|*
name|E
argument_list|)
expr_stmt|;
end_expr_stmt

begin_function_decl
name|RValue
name|EmitObjCMessageExpr
parameter_list|(
specifier|const
name|ObjCMessageExpr
modifier|*
name|E
parameter_list|,
name|ReturnValueSlot
name|Return
init|=
name|ReturnValueSlot
argument_list|()
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// Retrieves the default cleanup kind for an ARC cleanup.
end_comment

begin_comment
comment|/// Except under -fobjc-arc-eh, ARC cleanups are normal-only.
end_comment

begin_function
name|CleanupKind
name|getARCCleanupKind
parameter_list|()
block|{
return|return
name|CGM
operator|.
name|getCodeGenOpts
argument_list|()
operator|.
name|ObjCAutoRefCountExceptions
condition|?
name|NormalAndEHCleanup
else|:
name|NormalCleanup
return|;
block|}
end_function

begin_comment
comment|// ARC primitives.
end_comment

begin_decl_stmt
name|void
name|EmitARCInitWeak
argument_list|(
name|llvm
operator|::
name|Value
operator|*
name|value
argument_list|,
name|llvm
operator|::
name|Value
operator|*
name|addr
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|EmitARCDestroyWeak
argument_list|(
name|llvm
operator|::
name|Value
operator|*
name|addr
argument_list|)
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|llvm
operator|::
name|Value
operator|*
name|EmitARCLoadWeak
argument_list|(
name|llvm
operator|::
name|Value
operator|*
name|addr
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|llvm
operator|::
name|Value
operator|*
name|EmitARCLoadWeakRetained
argument_list|(
name|llvm
operator|::
name|Value
operator|*
name|addr
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|llvm
operator|::
name|Value
operator|*
name|EmitARCStoreWeak
argument_list|(
argument|llvm::Value *value
argument_list|,
argument|llvm::Value *addr
argument_list|,
argument|bool ignored
argument_list|)
expr_stmt|;
end_expr_stmt

begin_decl_stmt
name|void
name|EmitARCCopyWeak
argument_list|(
name|llvm
operator|::
name|Value
operator|*
name|dst
argument_list|,
name|llvm
operator|::
name|Value
operator|*
name|src
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|EmitARCMoveWeak
argument_list|(
name|llvm
operator|::
name|Value
operator|*
name|dst
argument_list|,
name|llvm
operator|::
name|Value
operator|*
name|src
argument_list|)
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|llvm
operator|::
name|Value
operator|*
name|EmitARCRetainAutorelease
argument_list|(
argument|QualType type
argument_list|,
argument|llvm::Value *value
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|llvm
operator|::
name|Value
operator|*
name|EmitARCRetainAutoreleaseNonBlock
argument_list|(
name|llvm
operator|::
name|Value
operator|*
name|value
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|llvm
operator|::
name|Value
operator|*
name|EmitARCStoreStrong
argument_list|(
argument|LValue lvalue
argument_list|,
argument|llvm::Value *value
argument_list|,
argument|bool resultIgnored
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|llvm
operator|::
name|Value
operator|*
name|EmitARCStoreStrongCall
argument_list|(
argument|llvm::Value *addr
argument_list|,
argument|llvm::Value *value
argument_list|,
argument|bool resultIgnored
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|llvm
operator|::
name|Value
operator|*
name|EmitARCRetain
argument_list|(
argument|QualType type
argument_list|,
argument|llvm::Value *value
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|llvm
operator|::
name|Value
operator|*
name|EmitARCRetainNonBlock
argument_list|(
name|llvm
operator|::
name|Value
operator|*
name|value
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|llvm
operator|::
name|Value
operator|*
name|EmitARCRetainBlock
argument_list|(
argument|llvm::Value *value
argument_list|,
argument|bool mandatory
argument_list|)
expr_stmt|;
end_expr_stmt

begin_decl_stmt
name|void
name|EmitARCDestroyStrong
argument_list|(
name|llvm
operator|::
name|Value
operator|*
name|addr
argument_list|,
name|ARCPreciseLifetime_t
name|precise
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|EmitARCRelease
argument_list|(
name|llvm
operator|::
name|Value
operator|*
name|value
argument_list|,
name|ARCPreciseLifetime_t
name|precise
argument_list|)
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|llvm
operator|::
name|Value
operator|*
name|EmitARCAutorelease
argument_list|(
name|llvm
operator|::
name|Value
operator|*
name|value
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|llvm
operator|::
name|Value
operator|*
name|EmitARCAutoreleaseReturnValue
argument_list|(
name|llvm
operator|::
name|Value
operator|*
name|value
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|llvm
operator|::
name|Value
operator|*
name|EmitARCRetainAutoreleaseReturnValue
argument_list|(
name|llvm
operator|::
name|Value
operator|*
name|value
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|llvm
operator|::
name|Value
operator|*
name|EmitARCRetainAutoreleasedReturnValue
argument_list|(
name|llvm
operator|::
name|Value
operator|*
name|value
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|std
operator|::
name|pair
operator|<
name|LValue
operator|,
name|llvm
operator|::
name|Value
operator|*
operator|>
name|EmitARCStoreAutoreleasing
argument_list|(
specifier|const
name|BinaryOperator
operator|*
name|e
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|std
operator|::
name|pair
operator|<
name|LValue
operator|,
name|llvm
operator|::
name|Value
operator|*
operator|>
name|EmitARCStoreStrong
argument_list|(
argument|const BinaryOperator *e
argument_list|,
argument|bool ignored
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|llvm
operator|::
name|Value
operator|*
name|EmitObjCThrowOperand
argument_list|(
specifier|const
name|Expr
operator|*
name|expr
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|llvm
operator|::
name|Value
operator|*
name|EmitObjCProduceObject
argument_list|(
argument|QualType T
argument_list|,
argument|llvm::Value *Ptr
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|llvm
operator|::
name|Value
operator|*
name|EmitObjCConsumeObject
argument_list|(
argument|QualType T
argument_list|,
argument|llvm::Value *Ptr
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|llvm
operator|::
name|Value
operator|*
name|EmitObjCExtendObjectLifetime
argument_list|(
argument|QualType T
argument_list|,
argument|llvm::Value *Ptr
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|llvm
operator|::
name|Value
operator|*
name|EmitARCExtendBlockObject
argument_list|(
specifier|const
name|Expr
operator|*
name|expr
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|llvm
operator|::
name|Value
operator|*
name|EmitARCRetainScalarExpr
argument_list|(
specifier|const
name|Expr
operator|*
name|expr
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|llvm
operator|::
name|Value
operator|*
name|EmitARCRetainAutoreleaseScalarExpr
argument_list|(
specifier|const
name|Expr
operator|*
name|expr
argument_list|)
expr_stmt|;
end_expr_stmt

begin_decl_stmt
name|void
name|EmitARCIntrinsicUse
argument_list|(
name|llvm
operator|::
name|ArrayRef
operator|<
name|llvm
operator|::
name|Value
operator|*
operator|>
name|values
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|Destroyer
name|destroyARCStrongImprecise
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|Destroyer
name|destroyARCStrongPrecise
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|Destroyer
name|destroyARCWeak
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|EmitObjCAutoreleasePoolPop
argument_list|(
name|llvm
operator|::
name|Value
operator|*
name|Ptr
argument_list|)
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|llvm
operator|::
name|Value
operator|*
name|EmitObjCAutoreleasePoolPush
argument_list|()
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|llvm
operator|::
name|Value
operator|*
name|EmitObjCMRRAutoreleasePoolPush
argument_list|()
expr_stmt|;
end_expr_stmt

begin_decl_stmt
name|void
name|EmitObjCAutoreleasePoolCleanup
argument_list|(
name|llvm
operator|::
name|Value
operator|*
name|Ptr
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|EmitObjCMRRAutoreleasePoolPop
argument_list|(
name|llvm
operator|::
name|Value
operator|*
name|Ptr
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// \brief Emits a reference binding to the passed in expression.
end_comment

begin_function_decl
name|RValue
name|EmitReferenceBindingToExpr
parameter_list|(
specifier|const
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
comment|//                           Expression Emission
end_comment

begin_comment
comment|//===--------------------------------------------------------------------===//
end_comment

begin_comment
comment|// Expressions are broken into three classes: scalar, complex, aggregate.
end_comment

begin_comment
comment|/// EmitScalarExpr - Emit the computation of the specified expression of LLVM
end_comment

begin_comment
comment|/// scalar type, returning the result.
end_comment

begin_expr_stmt
name|llvm
operator|::
name|Value
operator|*
name|EmitScalarExpr
argument_list|(
argument|const Expr *E
argument_list|,
argument|bool IgnoreResultAssign = false
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// EmitScalarConversion - Emit a conversion from the specified type to the
end_comment

begin_comment
comment|/// specified destination type, both of which are LLVM scalar types.
end_comment

begin_expr_stmt
name|llvm
operator|::
name|Value
operator|*
name|EmitScalarConversion
argument_list|(
argument|llvm::Value *Src
argument_list|,
argument|QualType SrcTy
argument_list|,
argument|QualType DstTy
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// EmitComplexToScalarConversion - Emit a conversion from the specified
end_comment

begin_comment
comment|/// complex type to the specified destination type, where the destination type
end_comment

begin_comment
comment|/// is an LLVM scalar type.
end_comment

begin_expr_stmt
name|llvm
operator|::
name|Value
operator|*
name|EmitComplexToScalarConversion
argument_list|(
argument|ComplexPairTy Src
argument_list|,
argument|QualType SrcTy
argument_list|,
argument|QualType DstTy
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// EmitAggExpr - Emit the computation of the specified expression
end_comment

begin_comment
comment|/// of aggregate type.  The result is computed into the given slot,
end_comment

begin_comment
comment|/// which may be null to indicate that the value is not needed.
end_comment

begin_function_decl
name|void
name|EmitAggExpr
parameter_list|(
specifier|const
name|Expr
modifier|*
name|E
parameter_list|,
name|AggValueSlot
name|AS
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// EmitAggExprToLValue - Emit the computation of the specified expression of
end_comment

begin_comment
comment|/// aggregate type into a temporary LValue.
end_comment

begin_function_decl
name|LValue
name|EmitAggExprToLValue
parameter_list|(
specifier|const
name|Expr
modifier|*
name|E
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// EmitGCMemmoveCollectable - Emit special API for structs with object
end_comment

begin_comment
comment|/// pointers.
end_comment

begin_decl_stmt
name|void
name|EmitGCMemmoveCollectable
argument_list|(
name|llvm
operator|::
name|Value
operator|*
name|DestPtr
argument_list|,
name|llvm
operator|::
name|Value
operator|*
name|SrcPtr
argument_list|,
name|QualType
name|Ty
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// EmitExtendGCLifetime - Given a pointer to an Objective-C object,
end_comment

begin_comment
comment|/// make sure it survives garbage collection until this point.
end_comment

begin_decl_stmt
name|void
name|EmitExtendGCLifetime
argument_list|(
name|llvm
operator|::
name|Value
operator|*
name|object
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// EmitComplexExpr - Emit the computation of the specified expression of
end_comment

begin_comment
comment|/// complex type, returning the result.
end_comment

begin_function_decl
name|ComplexPairTy
name|EmitComplexExpr
parameter_list|(
specifier|const
name|Expr
modifier|*
name|E
parameter_list|,
name|bool
name|IgnoreReal
init|=
name|false
parameter_list|,
name|bool
name|IgnoreImag
init|=
name|false
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// EmitComplexExprIntoLValue - Emit the given expression of complex
end_comment

begin_comment
comment|/// type and place its result into the specified l-value.
end_comment

begin_function_decl
name|void
name|EmitComplexExprIntoLValue
parameter_list|(
specifier|const
name|Expr
modifier|*
name|E
parameter_list|,
name|LValue
name|dest
parameter_list|,
name|bool
name|isInit
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// EmitStoreOfComplex - Store a complex number into the specified l-value.
end_comment

begin_function_decl
name|void
name|EmitStoreOfComplex
parameter_list|(
name|ComplexPairTy
name|V
parameter_list|,
name|LValue
name|dest
parameter_list|,
name|bool
name|isInit
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// EmitLoadOfComplex - Load a complex number from the specified l-value.
end_comment

begin_function_decl
name|ComplexPairTy
name|EmitLoadOfComplex
parameter_list|(
name|LValue
name|src
parameter_list|,
name|SourceLocation
name|loc
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// CreateStaticVarDecl - Create a zero-initialized LLVM global for
end_comment

begin_comment
comment|/// a static local variable.
end_comment

begin_expr_stmt
name|llvm
operator|::
name|GlobalVariable
operator|*
name|CreateStaticVarDecl
argument_list|(
argument|const VarDecl&D
argument_list|,
argument|const char *Separator
argument_list|,
argument|llvm::GlobalValue::LinkageTypes Linkage
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// AddInitializerToStaticVarDecl - Add the initializer for 'D' to the
end_comment

begin_comment
comment|/// global variable that has already been created for it.  If the initializer
end_comment

begin_comment
comment|/// has a different type than GV does, this may free GV and return a different
end_comment

begin_comment
comment|/// one.  Otherwise it just returns GV.
end_comment

begin_expr_stmt
name|llvm
operator|::
name|GlobalVariable
operator|*
name|AddInitializerToStaticVarDecl
argument_list|(
specifier|const
name|VarDecl
operator|&
name|D
argument_list|,
name|llvm
operator|::
name|GlobalVariable
operator|*
name|GV
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// EmitCXXGlobalVarDeclInit - Create the initializer for a C++
end_comment

begin_comment
comment|/// variable with global storage.
end_comment

begin_decl_stmt
name|void
name|EmitCXXGlobalVarDeclInit
argument_list|(
specifier|const
name|VarDecl
operator|&
name|D
argument_list|,
name|llvm
operator|::
name|Constant
operator|*
name|DeclPtr
argument_list|,
name|bool
name|PerformInit
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// Call atexit() with a function that passes the given argument to
end_comment

begin_comment
comment|/// the given function.
end_comment

begin_decl_stmt
name|void
name|registerGlobalDtorWithAtExit
argument_list|(
specifier|const
name|VarDecl
operator|&
name|D
argument_list|,
name|llvm
operator|::
name|Constant
operator|*
name|fn
argument_list|,
name|llvm
operator|::
name|Constant
operator|*
name|addr
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// Emit code in this function to perform a guarded variable
end_comment

begin_comment
comment|/// initialization.  Guarded initializations are used when it's not
end_comment

begin_comment
comment|/// possible to prove that an initialization will be done exactly
end_comment

begin_comment
comment|/// once, e.g. with a static local variable or a static data member
end_comment

begin_comment
comment|/// of a class template.
end_comment

begin_decl_stmt
name|void
name|EmitCXXGuardedInit
argument_list|(
specifier|const
name|VarDecl
operator|&
name|D
argument_list|,
name|llvm
operator|::
name|GlobalVariable
operator|*
name|DeclPtr
argument_list|,
name|bool
name|PerformInit
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// GenerateCXXGlobalInitFunc - Generates code for initializing global
end_comment

begin_comment
comment|/// variables.
end_comment

begin_decl_stmt
name|void
name|GenerateCXXGlobalInitFunc
argument_list|(
name|llvm
operator|::
name|Function
operator|*
name|Fn
argument_list|,
name|ArrayRef
operator|<
name|llvm
operator|::
name|Constant
operator|*
operator|>
name|Decls
argument_list|,
name|llvm
operator|::
name|GlobalVariable
operator|*
name|Guard
operator|=
literal|0
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// GenerateCXXGlobalDtorsFunc - Generates code for destroying global
end_comment

begin_comment
comment|/// variables.
end_comment

begin_decl_stmt
name|void
name|GenerateCXXGlobalDtorsFunc
argument_list|(
name|llvm
operator|::
name|Function
operator|*
name|Fn
argument_list|,
specifier|const
name|std
operator|::
name|vector
operator|<
name|std
operator|::
name|pair
operator|<
name|llvm
operator|::
name|WeakVH
argument_list|,
name|llvm
operator|::
name|Constant
operator|*
operator|>
expr|>
operator|&
name|DtorsAndObjects
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|GenerateCXXGlobalVarDeclInitFunc
argument_list|(
name|llvm
operator|::
name|Function
operator|*
name|Fn
argument_list|,
specifier|const
name|VarDecl
operator|*
name|D
argument_list|,
name|llvm
operator|::
name|GlobalVariable
operator|*
name|Addr
argument_list|,
name|bool
name|PerformInit
argument_list|)
decl_stmt|;
end_decl_stmt

begin_function_decl
name|void
name|EmitCXXConstructExpr
parameter_list|(
specifier|const
name|CXXConstructExpr
modifier|*
name|E
parameter_list|,
name|AggValueSlot
name|Dest
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
name|void
name|EmitSynthesizedCXXCopyCtor
argument_list|(
name|llvm
operator|::
name|Value
operator|*
name|Dest
argument_list|,
name|llvm
operator|::
name|Value
operator|*
name|Src
argument_list|,
specifier|const
name|Expr
operator|*
name|Exp
argument_list|)
decl_stmt|;
end_decl_stmt

begin_function
name|void
name|enterFullExpression
parameter_list|(
specifier|const
name|ExprWithCleanups
modifier|*
name|E
parameter_list|)
block|{
if|if
condition|(
name|E
operator|->
name|getNumObjects
argument_list|()
operator|==
literal|0
condition|)
return|return;
name|enterNonTrivialFullExpression
argument_list|(
name|E
argument_list|)
expr_stmt|;
block|}
end_function

begin_function_decl
name|void
name|enterNonTrivialFullExpression
parameter_list|(
specifier|const
name|ExprWithCleanups
modifier|*
name|E
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|EmitCXXThrowExpr
parameter_list|(
specifier|const
name|CXXThrowExpr
modifier|*
name|E
parameter_list|,
name|bool
name|KeepInsertionPoint
init|=
name|true
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|EmitLambdaExpr
parameter_list|(
specifier|const
name|LambdaExpr
modifier|*
name|E
parameter_list|,
name|AggValueSlot
name|Dest
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
name|RValue
name|EmitAtomicExpr
argument_list|(
name|AtomicExpr
operator|*
name|E
argument_list|,
name|llvm
operator|::
name|Value
operator|*
name|Dest
operator|=
literal|0
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|//===--------------------------------------------------------------------===//
end_comment

begin_comment
comment|//                         Annotations Emission
end_comment

begin_comment
comment|//===--------------------------------------------------------------------===//
end_comment

begin_comment
comment|/// Emit an annotation call (intrinsic or builtin).
end_comment

begin_expr_stmt
name|llvm
operator|::
name|Value
operator|*
name|EmitAnnotationCall
argument_list|(
argument|llvm::Value *AnnotationFn
argument_list|,
argument|llvm::Value *AnnotatedVal
argument_list|,
argument|StringRef AnnotationStr
argument_list|,
argument|SourceLocation Location
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// Emit local annotations for the local variable V, declared by D.
end_comment

begin_decl_stmt
name|void
name|EmitVarAnnotations
argument_list|(
specifier|const
name|VarDecl
operator|*
name|D
argument_list|,
name|llvm
operator|::
name|Value
operator|*
name|V
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// Emit field annotations for the given field& value. Returns the
end_comment

begin_comment
comment|/// annotation result.
end_comment

begin_expr_stmt
name|llvm
operator|::
name|Value
operator|*
name|EmitFieldAnnotations
argument_list|(
specifier|const
name|FieldDecl
operator|*
name|D
argument_list|,
name|llvm
operator|::
name|Value
operator|*
name|V
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|//===--------------------------------------------------------------------===//
end_comment

begin_comment
comment|//                             Internal Helpers
end_comment

begin_comment
comment|//===--------------------------------------------------------------------===//
end_comment

begin_comment
comment|/// ContainsLabel - Return true if the statement contains a label in it.  If
end_comment

begin_comment
comment|/// this statement is not executed normally, it not containing a label means
end_comment

begin_comment
comment|/// that we can just remove the code.
end_comment

begin_function_decl
specifier|static
name|bool
name|ContainsLabel
parameter_list|(
specifier|const
name|Stmt
modifier|*
name|S
parameter_list|,
name|bool
name|IgnoreCaseStmts
init|=
name|false
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// containsBreak - Return true if the statement contains a break out of it.
end_comment

begin_comment
comment|/// If the statement (recursively) contains a switch or loop with a break
end_comment

begin_comment
comment|/// inside of it, this is fine.
end_comment

begin_function_decl
specifier|static
name|bool
name|containsBreak
parameter_list|(
specifier|const
name|Stmt
modifier|*
name|S
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// ConstantFoldsToSimpleInteger - If the specified expression does not fold
end_comment

begin_comment
comment|/// to a constant, or if it does but contains a label, return false.  If it
end_comment

begin_comment
comment|/// constant folds return true and set the boolean result in Result.
end_comment

begin_function_decl
name|bool
name|ConstantFoldsToSimpleInteger
parameter_list|(
specifier|const
name|Expr
modifier|*
name|Cond
parameter_list|,
name|bool
modifier|&
name|Result
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// ConstantFoldsToSimpleInteger - If the specified expression does not fold
end_comment

begin_comment
comment|/// to a constant, or if it does but contains a label, return false.  If it
end_comment

begin_comment
comment|/// constant folds return true and set the folded value.
end_comment

begin_decl_stmt
name|bool
name|ConstantFoldsToSimpleInteger
argument_list|(
specifier|const
name|Expr
operator|*
name|Cond
argument_list|,
name|llvm
operator|::
name|APSInt
operator|&
name|Result
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// EmitBranchOnBoolExpr - Emit a branch on a boolean condition (e.g. for an
end_comment

begin_comment
comment|/// if statement) to the specified blocks.  Based on the condition, this might
end_comment

begin_comment
comment|/// try to simplify the codegen of the conditional based on the branch.
end_comment

begin_decl_stmt
name|void
name|EmitBranchOnBoolExpr
argument_list|(
specifier|const
name|Expr
operator|*
name|Cond
argument_list|,
name|llvm
operator|::
name|BasicBlock
operator|*
name|TrueBlock
argument_list|,
name|llvm
operator|::
name|BasicBlock
operator|*
name|FalseBlock
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// \brief Emit a description of a type in a format suitable for passing to
end_comment

begin_comment
comment|/// a runtime sanitizer handler.
end_comment

begin_expr_stmt
name|llvm
operator|::
name|Constant
operator|*
name|EmitCheckTypeDescriptor
argument_list|(
argument|QualType T
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// \brief Convert a value into a format suitable for passing to a runtime
end_comment

begin_comment
comment|/// sanitizer handler.
end_comment

begin_expr_stmt
name|llvm
operator|::
name|Value
operator|*
name|EmitCheckValue
argument_list|(
name|llvm
operator|::
name|Value
operator|*
name|V
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// \brief Emit a description of a source location in a format suitable for
end_comment

begin_comment
comment|/// passing to a runtime sanitizer handler.
end_comment

begin_expr_stmt
name|llvm
operator|::
name|Constant
operator|*
name|EmitCheckSourceLocation
argument_list|(
argument|SourceLocation Loc
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// \brief Specify under what conditions this check can be recovered
end_comment

begin_enum
enum|enum
name|CheckRecoverableKind
block|{
comment|/// Always terminate program execution if this check fails
name|CRK_Unrecoverable
block|,
comment|/// Check supports recovering, allows user to specify which
name|CRK_Recoverable
block|,
comment|/// Runtime conditionally aborts, always need to support recovery.
name|CRK_AlwaysRecoverable
block|}
enum|;
end_enum

begin_comment
comment|/// \brief Create a basic block that will call a handler function in a
end_comment

begin_comment
comment|/// sanitizer runtime with the provided arguments, and create a conditional
end_comment

begin_comment
comment|/// branch to it.
end_comment

begin_decl_stmt
name|void
name|EmitCheck
argument_list|(
name|llvm
operator|::
name|Value
operator|*
name|Checked
argument_list|,
name|StringRef
name|CheckName
argument_list|,
name|ArrayRef
operator|<
name|llvm
operator|::
name|Constant
operator|*
operator|>
name|StaticArgs
argument_list|,
name|ArrayRef
operator|<
name|llvm
operator|::
name|Value
operator|*
operator|>
name|DynamicArgs
argument_list|,
name|CheckRecoverableKind
name|Recoverable
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// \brief Create a basic block that will call the trap intrinsic, and emit a
end_comment

begin_comment
comment|/// conditional branch to it, for the -ftrapv checks.
end_comment

begin_decl_stmt
name|void
name|EmitTrapCheck
argument_list|(
name|llvm
operator|::
name|Value
operator|*
name|Checked
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// EmitCallArg - Emit a single call argument.
end_comment

begin_function_decl
name|void
name|EmitCallArg
parameter_list|(
name|CallArgList
modifier|&
name|args
parameter_list|,
specifier|const
name|Expr
modifier|*
name|E
parameter_list|,
name|QualType
name|ArgType
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// EmitDelegateCallArg - We are performing a delegate call; that
end_comment

begin_comment
comment|/// is, the current function is delegating to another one.  Produce
end_comment

begin_comment
comment|/// a r-value suitable for passing the given parameter.
end_comment

begin_function_decl
name|void
name|EmitDelegateCallArg
parameter_list|(
name|CallArgList
modifier|&
name|args
parameter_list|,
specifier|const
name|VarDecl
modifier|*
name|param
parameter_list|,
name|SourceLocation
name|loc
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// SetFPAccuracy - Set the minimum required accuracy of the given floating
end_comment

begin_comment
comment|/// point operation, expressed as the maximum relative error in ulp.
end_comment

begin_decl_stmt
name|void
name|SetFPAccuracy
argument_list|(
name|llvm
operator|::
name|Value
operator|*
name|Val
argument_list|,
name|float
name|Accuracy
argument_list|)
decl_stmt|;
end_decl_stmt

begin_label
name|private
label|:
end_label

begin_expr_stmt
name|llvm
operator|::
name|MDNode
operator|*
name|getRangeForLoadFromType
argument_list|(
argument|QualType Ty
argument_list|)
expr_stmt|;
end_expr_stmt

begin_function_decl
name|void
name|EmitReturnOfRValue
parameter_list|(
name|RValue
name|RV
parameter_list|,
name|QualType
name|Ty
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// ExpandTypeFromArgs - Reconstruct a structure of type \arg Ty
end_comment

begin_comment
comment|/// from function arguments into \arg Dst. See ABIArgInfo::Expand.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param AI - The first function argument of the expansion.
end_comment

begin_comment
comment|/// \return The argument following the last expanded function
end_comment

begin_comment
comment|/// argument.
end_comment

begin_expr_stmt
name|llvm
operator|::
name|Function
operator|::
name|arg_iterator
name|ExpandTypeFromArgs
argument_list|(
argument|QualType Ty
argument_list|,
argument|LValue Dst
argument_list|,
argument|llvm::Function::arg_iterator AI
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// ExpandTypeToArgs - Expand an RValue \arg Src, with the LLVM type for \arg
end_comment

begin_comment
comment|/// Ty, into individual arguments on the provided vector \arg Args. See
end_comment

begin_comment
comment|/// ABIArgInfo::Expand.
end_comment

begin_decl_stmt
name|void
name|ExpandTypeToArgs
argument_list|(
name|QualType
name|Ty
argument_list|,
name|RValue
name|Src
argument_list|,
name|SmallVectorImpl
operator|<
name|llvm
operator|::
name|Value
operator|*
operator|>
operator|&
name|Args
argument_list|,
name|llvm
operator|::
name|FunctionType
operator|*
name|IRFuncTy
argument_list|)
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|llvm
operator|::
name|Value
operator|*
name|EmitAsmInput
argument_list|(
specifier|const
name|TargetInfo
operator|::
name|ConstraintInfo
operator|&
name|Info
argument_list|,
specifier|const
name|Expr
operator|*
name|InputExpr
argument_list|,
name|std
operator|::
name|string
operator|&
name|ConstraintStr
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|llvm
operator|::
name|Value
operator|*
name|EmitAsmInputLValue
argument_list|(
argument|const TargetInfo::ConstraintInfo&Info
argument_list|,
argument|LValue InputValue
argument_list|,
argument|QualType InputType
argument_list|,
argument|std::string&ConstraintStr
argument_list|,
argument|SourceLocation Loc
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// EmitCallArgs - Emit call arguments for a function.
end_comment

begin_comment
comment|/// The CallArgTypeInfo parameter is used for iterating over the known
end_comment

begin_comment
comment|/// argument types of the function being called.
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|>
name|void
name|EmitCallArgs
argument_list|(
argument|CallArgList& Args
argument_list|,
argument|const T* CallArgTypeInfo
argument_list|,
argument|CallExpr::const_arg_iterator ArgBeg
argument_list|,
argument|CallExpr::const_arg_iterator ArgEnd
argument_list|,
argument|bool ForceColumnInfo = false
argument_list|)
block|{
name|CGDebugInfo
operator|*
name|DI
operator|=
name|getDebugInfo
argument_list|()
block|;
name|SourceLocation
name|CallLoc
block|;
if|if
condition|(
name|DI
condition|)
name|CallLoc
operator|=
name|DI
operator|->
name|getLocation
argument_list|()
expr_stmt|;
name|CallExpr
operator|::
name|const_arg_iterator
name|Arg
operator|=
name|ArgBeg
expr_stmt|;
end_expr_stmt

begin_comment
comment|// First, use the argument types that the type info knows about
end_comment

begin_if
if|if
condition|(
name|CallArgTypeInfo
condition|)
block|{
for|for
control|(
name|typename
name|T
operator|::
name|arg_type_iterator
name|I
operator|=
name|CallArgTypeInfo
operator|->
name|arg_type_begin
argument_list|()
operator|,
name|E
operator|=
name|CallArgTypeInfo
operator|->
name|arg_type_end
argument_list|()
init|;
name|I
operator|!=
name|E
condition|;
operator|++
name|I
operator|,
operator|++
name|Arg
control|)
block|{
name|assert
argument_list|(
name|Arg
operator|!=
name|ArgEnd
operator|&&
literal|"Running over edge of argument list!"
argument_list|)
expr_stmt|;
name|QualType
name|ArgType
init|=
operator|*
name|I
decl_stmt|;
ifndef|#
directive|ifndef
name|NDEBUG
name|QualType
name|ActualArgType
init|=
name|Arg
operator|->
name|getType
argument_list|()
decl_stmt|;
if|if
condition|(
name|ArgType
operator|->
name|isPointerType
argument_list|()
operator|&&
name|ActualArgType
operator|->
name|isPointerType
argument_list|()
condition|)
block|{
name|QualType
name|ActualBaseType
init|=
name|ActualArgType
operator|->
name|getAs
operator|<
name|PointerType
operator|>
operator|(
operator|)
operator|->
name|getPointeeType
argument_list|()
decl_stmt|;
name|QualType
name|ArgBaseType
init|=
name|ArgType
operator|->
name|getAs
operator|<
name|PointerType
operator|>
operator|(
operator|)
operator|->
name|getPointeeType
argument_list|()
decl_stmt|;
if|if
condition|(
name|ArgBaseType
operator|->
name|isVariableArrayType
argument_list|()
condition|)
block|{
if|if
condition|(
specifier|const
name|VariableArrayType
modifier|*
name|VAT
init|=
name|getContext
argument_list|()
operator|.
name|getAsVariableArrayType
argument_list|(
name|ActualBaseType
argument_list|)
condition|)
block|{
if|if
condition|(
operator|!
name|VAT
operator|->
name|getSizeExpr
argument_list|()
condition|)
name|ActualArgType
operator|=
name|ArgType
expr_stmt|;
block|}
block|}
block|}
name|assert
argument_list|(
name|getContext
argument_list|()
operator|.
name|getCanonicalType
argument_list|(
name|ArgType
operator|.
name|getNonReferenceType
argument_list|()
argument_list|)
operator|.
name|getTypePtr
argument_list|()
operator|==
name|getContext
argument_list|()
operator|.
name|getCanonicalType
argument_list|(
name|ActualArgType
argument_list|)
operator|.
name|getTypePtr
argument_list|()
operator|&&
literal|"type mismatch in call argument!"
argument_list|)
expr_stmt|;
endif|#
directive|endif
name|EmitCallArg
argument_list|(
name|Args
argument_list|,
operator|*
name|Arg
argument_list|,
name|ArgType
argument_list|)
expr_stmt|;
comment|// Each argument expression could modify the debug
comment|// location. Restore it.
if|if
condition|(
name|DI
condition|)
name|DI
operator|->
name|EmitLocation
argument_list|(
name|Builder
argument_list|,
name|CallLoc
argument_list|,
name|ForceColumnInfo
argument_list|)
expr_stmt|;
block|}
comment|// Either we've emitted all the call args, or we have a call to a
comment|// variadic function.
name|assert
argument_list|(
operator|(
name|Arg
operator|==
name|ArgEnd
operator|||
name|CallArgTypeInfo
operator|->
name|isVariadic
argument_list|()
operator|)
operator|&&
literal|"Extra arguments in non-variadic function!"
argument_list|)
expr_stmt|;
block|}
end_if

begin_comment
comment|// If we still have any arguments, emit them using the type of the argument.
end_comment

begin_for
for|for
control|(
init|;
name|Arg
operator|!=
name|ArgEnd
condition|;
operator|++
name|Arg
control|)
block|{
name|EmitCallArg
argument_list|(
name|Args
argument_list|,
operator|*
name|Arg
argument_list|,
name|Arg
operator|->
name|getType
argument_list|()
argument_list|)
expr_stmt|;
comment|// Restore the debug location.
if|if
condition|(
name|DI
condition|)
name|DI
operator|->
name|EmitLocation
argument_list|(
name|Builder
argument_list|,
name|CallLoc
argument_list|,
name|ForceColumnInfo
argument_list|)
expr_stmt|;
block|}
end_for

begin_expr_stmt
unit|}    const
name|TargetCodeGenInfo
operator|&
name|getTargetHooks
argument_list|()
specifier|const
block|{
return|return
name|CGM
operator|.
name|getTargetCodeGenInfo
argument_list|()
return|;
block|}
end_expr_stmt

begin_function_decl
name|void
name|EmitDeclMetadata
parameter_list|()
function_decl|;
end_function_decl

begin_expr_stmt
name|CodeGenModule
operator|::
name|ByrefHelpers
operator|*
name|buildByrefHelpers
argument_list|(
name|llvm
operator|::
name|StructType
operator|&
name|byrefType
argument_list|,
specifier|const
name|AutoVarEmission
operator|&
name|emission
argument_list|)
expr_stmt|;
end_expr_stmt

begin_decl_stmt
name|void
name|AddObjCARCExceptionMetadata
argument_list|(
name|llvm
operator|::
name|Instruction
operator|*
name|Inst
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// GetPointeeAlignment - Given an expression with a pointer type, emit the
end_comment

begin_comment
comment|/// value and compute our best estimate of the alignment of the pointee.
end_comment

begin_expr_stmt
name|std
operator|::
name|pair
operator|<
name|llvm
operator|::
name|Value
operator|*
operator|,
name|unsigned
operator|>
name|EmitPointerWithAlignment
argument_list|(
specifier|const
name|Expr
operator|*
name|Addr
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
unit|};
comment|/// Helper class with most of the code for saving a value for a
end_comment

begin_comment
comment|/// conditional expression cleanup.
end_comment

begin_struct
struct|struct
name|DominatingLLVMValue
block|{
typedef|typedef
name|llvm
operator|::
name|PointerIntPair
operator|<
name|llvm
operator|::
name|Value
operator|*
operator|,
literal|1
operator|,
name|bool
operator|>
name|saved_type
expr_stmt|;
comment|/// Answer whether the given value needs extra work to be saved.
specifier|static
name|bool
name|needsSaving
argument_list|(
name|llvm
operator|::
name|Value
operator|*
name|value
argument_list|)
block|{
comment|// If it's not an instruction, we don't need to save.
if|if
condition|(
operator|!
name|isa
operator|<
name|llvm
operator|::
name|Instruction
operator|>
operator|(
name|value
operator|)
condition|)
return|return
name|false
return|;
comment|// If it's an instruction in the entry block, we don't need to save.
name|llvm
operator|::
name|BasicBlock
operator|*
name|block
operator|=
name|cast
operator|<
name|llvm
operator|::
name|Instruction
operator|>
operator|(
name|value
operator|)
operator|->
name|getParent
argument_list|()
expr_stmt|;
return|return
operator|(
name|block
operator|!=
operator|&
name|block
operator|->
name|getParent
argument_list|()
operator|->
name|getEntryBlock
argument_list|()
operator|)
return|;
block|}
comment|/// Try to save the given value.
specifier|static
name|saved_type
name|save
argument_list|(
name|CodeGenFunction
operator|&
name|CGF
argument_list|,
name|llvm
operator|::
name|Value
operator|*
name|value
argument_list|)
block|{
if|if
condition|(
operator|!
name|needsSaving
argument_list|(
name|value
argument_list|)
condition|)
return|return
name|saved_type
argument_list|(
name|value
argument_list|,
name|false
argument_list|)
return|;
comment|// Otherwise we need an alloca.
name|llvm
operator|::
name|Value
operator|*
name|alloca
operator|=
name|CGF
operator|.
name|CreateTempAlloca
argument_list|(
name|value
operator|->
name|getType
argument_list|()
argument_list|,
literal|"cond-cleanup.save"
argument_list|)
expr_stmt|;
name|CGF
operator|.
name|Builder
operator|.
name|CreateStore
argument_list|(
name|value
argument_list|,
name|alloca
argument_list|)
expr_stmt|;
return|return
name|saved_type
argument_list|(
name|alloca
argument_list|,
name|true
argument_list|)
return|;
block|}
specifier|static
name|llvm
operator|::
name|Value
operator|*
name|restore
argument_list|(
argument|CodeGenFunction&CGF
argument_list|,
argument|saved_type value
argument_list|)
block|{
if|if
condition|(
operator|!
name|value
operator|.
name|getInt
argument_list|()
condition|)
return|return
name|value
operator|.
name|getPointer
argument_list|()
return|;
return|return
name|CGF
operator|.
name|Builder
operator|.
name|CreateLoad
argument_list|(
name|value
operator|.
name|getPointer
argument_list|()
argument_list|)
return|;
block|}
end_struct

begin_comment
unit|};
comment|/// A partial specialization of DominatingValue for llvm::Values that
end_comment

begin_comment
comment|/// might be llvm::Instructions.
end_comment

begin_expr_stmt
name|template
operator|<
name|class
name|T
operator|>
expr|struct
name|DominatingPointer
operator|<
name|T
operator|,
name|true
operator|>
operator|:
name|DominatingLLVMValue
block|{
typedef|typedef
name|T
modifier|*
name|type
typedef|;
specifier|static
name|type
name|restore
argument_list|(
argument|CodeGenFunction&CGF
argument_list|,
argument|saved_type value
argument_list|)
block|{
return|return
name|static_cast
operator|<
name|T
operator|*
operator|>
operator|(
name|DominatingLLVMValue
operator|::
name|restore
argument_list|(
name|CGF
argument_list|,
name|value
argument_list|)
operator|)
return|;
block|}
block|}
end_expr_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|/// A specialization of DominatingValue for RValue.
end_comment

begin_expr_stmt
name|template
operator|<
operator|>
expr|struct
name|DominatingValue
operator|<
name|RValue
operator|>
block|{
typedef|typedef
name|RValue
name|type
typedef|;
name|class
name|saved_type
block|{     enum
name|Kind
block|{
name|ScalarLiteral
block|,
name|ScalarAddress
block|,
name|AggregateLiteral
block|,
name|AggregateAddress
block|,
name|ComplexAddress
block|}
block|;
name|llvm
operator|::
name|Value
operator|*
name|Value
block|;
name|Kind
name|K
block|;
name|saved_type
argument_list|(
argument|llvm::Value *v
argument_list|,
argument|Kind k
argument_list|)
operator|:
name|Value
argument_list|(
name|v
argument_list|)
block|,
name|K
argument_list|(
argument|k
argument_list|)
block|{}
name|public
operator|:
specifier|static
name|bool
name|needsSaving
argument_list|(
argument|RValue value
argument_list|)
block|;
specifier|static
name|saved_type
name|save
argument_list|(
argument|CodeGenFunction&CGF
argument_list|,
argument|RValue value
argument_list|)
block|;
name|RValue
name|restore
argument_list|(
name|CodeGenFunction
operator|&
name|CGF
argument_list|)
block|;
comment|// implementations in CGExprCXX.cpp
block|}
expr_stmt|;
end_expr_stmt

begin_function
specifier|static
name|bool
name|needsSaving
parameter_list|(
name|type
name|value
parameter_list|)
block|{
return|return
name|saved_type
operator|::
name|needsSaving
argument_list|(
name|value
argument_list|)
return|;
block|}
end_function

begin_function
specifier|static
name|saved_type
name|save
parameter_list|(
name|CodeGenFunction
modifier|&
name|CGF
parameter_list|,
name|type
name|value
parameter_list|)
block|{
return|return
name|saved_type
operator|::
name|save
argument_list|(
name|CGF
argument_list|,
name|value
argument_list|)
return|;
block|}
end_function

begin_function
specifier|static
name|type
name|restore
parameter_list|(
name|CodeGenFunction
modifier|&
name|CGF
parameter_list|,
name|saved_type
name|value
parameter_list|)
block|{
return|return
name|value
operator|.
name|restore
argument_list|(
name|CGF
argument_list|)
return|;
block|}
end_function

begin_comment
unit|};  }
comment|// end namespace CodeGen
end_comment

begin_comment
unit|}
comment|// end namespace clang
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

