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
name|LLVM_CLANG_LIB_CODEGEN_CODEGENFUNCTION_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_LIB_CODEGEN_CODEGENFUNCTION_H
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
file|"CGLoopInfo.h"
end_include

begin_include
include|#
directive|include
file|"CGValue.h"
end_include

begin_include
include|#
directive|include
file|"CodeGenModule.h"
end_include

begin_include
include|#
directive|include
file|"CodeGenPGO.h"
end_include

begin_include
include|#
directive|include
file|"EHScopeStack.h"
end_include

begin_include
include|#
directive|include
file|"VarBypassDetector.h"
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
file|"clang/AST/ExprOpenMP.h"
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
file|"clang/Basic/OpenMPKinds.h"
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
file|"llvm/IR/ValueHandle.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/Debug.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Transforms/Utils/SanitizerStats.h"
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
name|CGCallee
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
name|BlockByrefHelpers
decl_stmt|;
name|class
name|BlockByrefInfo
decl_stmt|;
name|class
name|BlockFlags
decl_stmt|;
name|class
name|BlockFieldFlags
decl_stmt|;
name|class
name|RegionCodeGenTy
decl_stmt|;
name|class
name|TargetCodeGenInfo
decl_stmt|;
struct_decl|struct
name|OMPTaskDataTy
struct_decl|;
struct_decl|struct
name|CGCoroData
struct_decl|;
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
define|#
directive|define
name|LIST_SANITIZER_CHECKS
define|\
value|SANITIZER_CHECK(AddOverflow, add_overflow, 0)                                \   SANITIZER_CHECK(BuiltinUnreachable, builtin_unreachable, 0)                  \   SANITIZER_CHECK(CFICheckFail, cfi_check_fail, 0)                             \   SANITIZER_CHECK(DivremOverflow, divrem_overflow, 0)                          \   SANITIZER_CHECK(DynamicTypeCacheMiss, dynamic_type_cache_miss, 0)            \   SANITIZER_CHECK(FloatCastOverflow, float_cast_overflow, 0)                   \   SANITIZER_CHECK(FunctionTypeMismatch, function_type_mismatch, 0)             \   SANITIZER_CHECK(LoadInvalidValue, load_invalid_value, 0)                     \   SANITIZER_CHECK(MissingReturn, missing_return, 0)                            \   SANITIZER_CHECK(MulOverflow, mul_overflow, 0)                                \   SANITIZER_CHECK(NegateOverflow, negate_overflow, 0)                          \   SANITIZER_CHECK(NullabilityArg, nullability_arg, 0)                          \   SANITIZER_CHECK(NullabilityReturn, nullability_return, 0)                    \   SANITIZER_CHECK(NonnullArg, nonnull_arg, 0)                                  \   SANITIZER_CHECK(NonnullReturn, nonnull_return, 0)                            \   SANITIZER_CHECK(OutOfBounds, out_of_bounds, 0)                               \   SANITIZER_CHECK(PointerOverflow, pointer_overflow, 0)                        \   SANITIZER_CHECK(ShiftOutOfBounds, shift_out_of_bounds, 0)                    \   SANITIZER_CHECK(SubOverflow, sub_overflow, 0)                                \   SANITIZER_CHECK(TypeMismatch, type_mismatch, 1)                              \   SANITIZER_CHECK(VLABoundNotPositive, vla_bound_not_positive, 0)
enum|enum
name|SanitizerHandler
block|{
define|#
directive|define
name|SANITIZER_CHECK
parameter_list|(
name|Enum
parameter_list|,
name|Name
parameter_list|,
name|Version
parameter_list|)
value|Enum,
name|LIST_SANITIZER_CHECKS
undef|#
directive|undef
name|SANITIZER_CHECK
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
specifier|const
name|CodeGenFunction
operator|&
argument_list|)
operator|=
name|delete
block|;
name|void
name|operator
operator|=
operator|(
specifier|const
name|CodeGenFunction
operator|&
operator|)
operator|=
name|delete
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
name|nullptr
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
name|nullptr
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
name|LoopInfoStack
name|LoopStack
decl_stmt|;
name|CGBuilderTy
name|Builder
decl_stmt|;
comment|// Stores variables for which we can't generate correct lifetime markers
comment|// because of jumps.
name|VarBypassDetector
name|Bypasses
decl_stmt|;
comment|// CodeGen lambda for loops and support for ordered clause
typedef|typedef
name|llvm
operator|::
name|function_ref
operator|<
name|void
argument_list|(
name|CodeGenFunction
operator|&
argument_list|,
specifier|const
name|OMPLoopDirective
operator|&
argument_list|,
name|JumpDest
argument_list|)
operator|>
name|CodeGenLoopTy
expr_stmt|;
typedef|typedef
name|llvm
operator|::
name|function_ref
operator|<
name|void
argument_list|(
name|CodeGenFunction
operator|&
argument_list|,
name|SourceLocation
argument_list|,
specifier|const
name|unsigned
argument_list|,
specifier|const
name|bool
argument_list|)
operator|>
name|CodeGenOrderedTy
expr_stmt|;
comment|// Codegen lambda for loop bounds in worksharing loop constructs
typedef|typedef
name|llvm
operator|::
name|function_ref
operator|<
name|std
operator|::
name|pair
operator|<
name|LValue
operator|,
name|LValue
operator|>
operator|(
name|CodeGenFunction
operator|&
operator|,
specifier|const
name|OMPExecutableDirective
operator|&
name|S
operator|)
operator|>
name|CodeGenLoopBoundsTy
expr_stmt|;
comment|// Codegen lambda for loop bounds in dispatch-based loop implementation
typedef|typedef
name|llvm
operator|::
name|function_ref
operator|<
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
operator|(
name|CodeGenFunction
operator|&
operator|,
specifier|const
name|OMPExecutableDirective
operator|&
name|S
operator|,
name|Address
name|LB
operator|,
name|Address
name|UB
operator|)
operator|>
name|CodeGenDispatchBoundsTy
expr_stmt|;
comment|/// \brief CGBuilder insert helper. This function is called after an
comment|/// instruction is created using Builder.
name|void
name|InsertHelper
argument_list|(
name|llvm
operator|::
name|Instruction
operator|*
name|I
argument_list|,
specifier|const
name|llvm
operator|::
name|Twine
operator|&
name|Name
argument_list|,
name|llvm
operator|::
name|BasicBlock
operator|*
name|BB
argument_list|,
name|llvm
operator|::
name|BasicBlock
operator|::
name|iterator
name|InsertPt
argument_list|)
decl|const
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
comment|// Holds coroutine data if the current function is a coroutine. We use a
comment|// wrapper to manage its lifetime, so that we don't have to define CGCoroData
comment|// in this header.
struct|struct
name|CGCoroInfo
block|{
name|std
operator|::
name|unique_ptr
operator|<
name|CGCoroData
operator|>
name|Data
expr_stmt|;
name|CGCoroInfo
argument_list|()
expr_stmt|;
operator|~
name|CGCoroInfo
argument_list|()
expr_stmt|;
block|}
struct|;
name|CGCoroInfo
name|CurCoro
decl_stmt|;
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
comment|/// ReturnValue - The temporary alloca to hold the return
comment|/// value. This is invalid iff the function has no return value.
name|Address
name|ReturnValue
decl_stmt|;
comment|/// Return true if a label was seen in the current scope.
name|bool
name|hasLabelBeenSeenInCurrentScope
argument_list|()
specifier|const
block|{
if|if
condition|(
name|CurLexicalScope
condition|)
return|return
name|CurLexicalScope
operator|->
name|hasLabels
argument_list|()
return|;
return|return
operator|!
name|LabelMap
operator|.
name|empty
argument_list|()
return|;
block|}
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
name|nullptr
argument_list|)
operator|,
name|CXXThisFieldDecl
argument_list|(
argument|nullptr
argument_list|)
block|{}
name|explicit
name|CGCapturedStmtInfo
argument_list|(
argument|const CapturedStmt&S
argument_list|,
argument|CapturedRegionKind K = CR_Default
argument_list|)
operator|:
name|Kind
argument_list|(
name|K
argument_list|)
operator|,
name|ThisValue
argument_list|(
name|nullptr
argument_list|)
operator|,
name|CXXThisFieldDecl
argument_list|(
argument|nullptr
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
elseif|else
if|if
condition|(
name|I
operator|->
name|capturesVariable
argument_list|()
condition|)
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
elseif|else
if|if
condition|(
name|I
operator|->
name|capturesVariableByCopy
argument_list|()
condition|)
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
name|virtual
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
name|virtual
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
name|virtual
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
name|getThisFieldDecl
argument_list|()
operator|!=
name|nullptr
return|;
block|}
name|virtual
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
specifier|static
name|bool
name|classof
parameter_list|(
specifier|const
name|CGCapturedStmtInfo
modifier|*
parameter_list|)
block|{
return|return
name|true
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
specifier|const
name|Stmt
modifier|*
name|S
parameter_list|)
block|{
name|CGF
operator|.
name|incrementProfileCounter
argument_list|(
name|S
argument_list|)
expr_stmt|;
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
comment|/// \brief RAII for correct setting/restoring of CapturedStmtInfo.
name|class
name|CGCapturedStmtRAII
block|{
name|private
label|:
name|CodeGenFunction
modifier|&
name|CGF
decl_stmt|;
name|CGCapturedStmtInfo
modifier|*
name|PrevCapturedStmtInfo
decl_stmt|;
name|public
label|:
name|CGCapturedStmtRAII
argument_list|(
name|CodeGenFunction
operator|&
name|CGF
argument_list|,
name|CGCapturedStmtInfo
operator|*
name|NewCapturedStmtInfo
argument_list|)
operator|:
name|CGF
argument_list|(
name|CGF
argument_list|)
operator|,
name|PrevCapturedStmtInfo
argument_list|(
argument|CGF.CapturedStmtInfo
argument_list|)
block|{
name|CGF
operator|.
name|CapturedStmtInfo
operator|=
name|NewCapturedStmtInfo
block|;     }
operator|~
name|CGCapturedStmtRAII
argument_list|()
block|{
name|CGF
operator|.
name|CapturedStmtInfo
operator|=
name|PrevCapturedStmtInfo
block|; }
block|}
empty_stmt|;
comment|/// An abstract representation of regular/ObjC call/message targets.
name|class
name|AbstractCallee
block|{
comment|/// The function declaration of the callee.
specifier|const
name|Decl
modifier|*
name|CalleeDecl
decl_stmt|;
name|public
label|:
name|AbstractCallee
argument_list|()
operator|:
name|CalleeDecl
argument_list|(
argument|nullptr
argument_list|)
block|{}
name|AbstractCallee
argument_list|(
specifier|const
name|FunctionDecl
operator|*
name|FD
argument_list|)
operator|:
name|CalleeDecl
argument_list|(
argument|FD
argument_list|)
block|{}
name|AbstractCallee
argument_list|(
specifier|const
name|ObjCMethodDecl
operator|*
name|OMD
argument_list|)
operator|:
name|CalleeDecl
argument_list|(
argument|OMD
argument_list|)
block|{}
name|bool
name|hasFunctionDecl
argument_list|()
specifier|const
block|{
return|return
name|dyn_cast_or_null
operator|<
name|FunctionDecl
operator|>
operator|(
name|CalleeDecl
operator|)
return|;
block|}
specifier|const
name|Decl
operator|*
name|getDecl
argument_list|()
specifier|const
block|{
return|return
name|CalleeDecl
return|;
block|}
name|unsigned
name|getNumParams
argument_list|()
specifier|const
block|{
if|if
condition|(
specifier|const
specifier|auto
modifier|*
name|FD
init|=
name|dyn_cast
operator|<
name|FunctionDecl
operator|>
operator|(
name|CalleeDecl
operator|)
condition|)
return|return
name|FD
operator|->
name|getNumParams
argument_list|()
return|;
return|return
name|cast
operator|<
name|ObjCMethodDecl
operator|>
operator|(
name|CalleeDecl
operator|)
operator|->
name|param_size
argument_list|()
return|;
block|}
specifier|const
name|ParmVarDecl
modifier|*
name|getParamDecl
argument_list|(
name|unsigned
name|I
argument_list|)
decl|const
block|{
if|if
condition|(
specifier|const
specifier|auto
modifier|*
name|FD
init|=
name|dyn_cast
operator|<
name|FunctionDecl
operator|>
operator|(
name|CalleeDecl
operator|)
condition|)
return|return
name|FD
operator|->
name|getParamDecl
argument_list|(
name|I
argument_list|)
return|;
return|return
operator|*
operator|(
name|cast
operator|<
name|ObjCMethodDecl
operator|>
operator|(
name|CalleeDecl
operator|)
operator|->
name|param_begin
argument_list|()
operator|+
name|I
operator|)
return|;
block|}
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|/// \brief Sanitizers enabled for this function.
end_comment

begin_decl_stmt
name|SanitizerSet
name|SanOpts
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// \brief True if CodeGen currently emits code implementing sanitizer checks.
end_comment

begin_decl_stmt
name|bool
name|IsSanitizerScope
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// \brief RAII object to set/unset CodeGenFunction::IsSanitizerScope.
end_comment

begin_decl_stmt
name|class
name|SanitizerScope
block|{
name|CodeGenFunction
modifier|*
name|CGF
decl_stmt|;
name|public
label|:
name|SanitizerScope
argument_list|(
name|CodeGenFunction
operator|*
name|CGF
argument_list|)
expr_stmt|;
operator|~
name|SanitizerScope
argument_list|()
expr_stmt|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|/// In C++, whether we are code generating a thunk.  This controls whether we
end_comment

begin_comment
comment|/// should emit cleanups.
end_comment

begin_decl_stmt
name|bool
name|CurFuncIsThunk
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// In ARC, whether we should autorelease the return value.
end_comment

begin_decl_stmt
name|bool
name|AutoreleaseResult
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// Whether we processed a Microsoft-style asm block during CodeGen. These can
end_comment

begin_comment
comment|/// potentially set the return value.
end_comment

begin_decl_stmt
name|bool
name|SawAsmBlock
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|FunctionDecl
modifier|*
name|CurSEHParent
init|=
name|nullptr
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// True if the current function is an outlined SEH helper. This can be a
end_comment

begin_comment
comment|/// finally block or filter expression.
end_comment

begin_decl_stmt
name|bool
name|IsOutlinedSEHHelper
decl_stmt|;
end_decl_stmt

begin_expr_stmt
specifier|const
name|CodeGen
operator|::
name|CGBlockInfo
operator|*
name|BlockInfo
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|llvm
operator|::
name|Value
operator|*
name|BlockPointer
expr_stmt|;
end_expr_stmt

begin_expr_stmt
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
end_expr_stmt

begin_decl_stmt
name|FieldDecl
modifier|*
name|LambdaThisCaptureField
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// \brief A mapping from NRVO variables to the flags used to indicate
end_comment

begin_comment
comment|/// when the NRVO has been applied to this variable.
end_comment

begin_expr_stmt
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
end_expr_stmt

begin_decl_stmt
name|EHScopeStack
name|EHStack
decl_stmt|;
end_decl_stmt

begin_expr_stmt
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
end_expr_stmt

begin_expr_stmt
name|llvm
operator|::
name|SmallVector
operator|<
specifier|const
name|JumpDest
operator|*
operator|,
literal|2
operator|>
name|SEHTryEpilogueStack
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|llvm
operator|::
name|Instruction
operator|*
name|CurrentFuncletPad
operator|=
name|nullptr
expr_stmt|;
end_expr_stmt

begin_decl_stmt
name|class
name|CallLifetimeEnd
name|final
range|:
name|public
name|EHScopeStack
operator|::
name|Cleanup
block|{
name|llvm
operator|::
name|Value
operator|*
name|Addr
block|;
name|llvm
operator|::
name|Value
operator|*
name|Size
block|;
name|public
operator|:
name|CallLifetimeEnd
argument_list|(
argument|Address addr
argument_list|,
argument|llvm::Value *size
argument_list|)
operator|:
name|Addr
argument_list|(
name|addr
operator|.
name|getPointer
argument_list|()
argument_list|)
block|,
name|Size
argument_list|(
argument|size
argument_list|)
block|{}
name|void
name|Emit
argument_list|(
argument|CodeGenFunction&CGF
argument_list|,
argument|Flags flags
argument_list|)
name|override
block|{
name|CGF
operator|.
name|EmitLifetimeEnd
argument_list|(
name|Size
argument_list|,
name|Addr
argument_list|)
block|;     }
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// Header for data within LifetimeExtendedCleanupStack.
end_comment

begin_struct
struct|struct
name|LifetimeExtendedCleanupHeader
block|{
comment|/// The size of the following cleanup object.
name|unsigned
name|Size
decl_stmt|;
comment|/// The kind of cleanup to push: a value from the CleanupKind enumeration.
name|CleanupKind
name|Kind
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
name|Kind
return|;
block|}
block|}
struct|;
end_struct

begin_comment
comment|/// i32s containing the indexes of the cleanup destinations.
end_comment

begin_expr_stmt
name|llvm
operator|::
name|AllocaInst
operator|*
name|NormalCleanupDest
expr_stmt|;
end_expr_stmt

begin_decl_stmt
name|unsigned
name|NextCleanupDestIndex
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// FirstBlockInfo - The head of a singly-linked-list of block layouts.
end_comment

begin_decl_stmt
name|CGBlockInfo
modifier|*
name|FirstBlockInfo
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// EHResumeBlock - Unified block containing a call to llvm.eh.resume.
end_comment

begin_expr_stmt
name|llvm
operator|::
name|BasicBlock
operator|*
name|EHResumeBlock
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// The exception slot.  All landing pads write the current exception pointer
end_comment

begin_comment
comment|/// into this alloca.
end_comment

begin_expr_stmt
name|llvm
operator|::
name|Value
operator|*
name|ExceptionSlot
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// The selector slot.  Under the MandatoryCleanup model, all landing pads
end_comment

begin_comment
comment|/// write the current selector value into this alloca.
end_comment

begin_expr_stmt
name|llvm
operator|::
name|AllocaInst
operator|*
name|EHSelectorSlot
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// A stack of exception code slots. Entering an __except block pushes a slot
end_comment

begin_comment
comment|/// on the stack and leaving pops one. The __exception_code() intrinsic loads
end_comment

begin_comment
comment|/// a value from the top of the stack.
end_comment

begin_expr_stmt
name|SmallVector
operator|<
name|Address
operator|,
literal|1
operator|>
name|SEHCodeSlotStack
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// Value returned by __exception_info intrinsic.
end_comment

begin_expr_stmt
name|llvm
operator|::
name|Value
operator|*
name|SEHInfo
operator|=
name|nullptr
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// Emits a landing pad for the current EH stack.
end_comment

begin_expr_stmt
name|llvm
operator|::
name|BasicBlock
operator|*
name|EmitLandingPad
argument_list|()
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|llvm
operator|::
name|BasicBlock
operator|*
name|getInvokeDestImpl
argument_list|()
expr_stmt|;
end_expr_stmt

begin_expr_stmt
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
end_expr_stmt

begin_label
name|public
label|:
end_label

begin_comment
comment|/// ObjCEHValueStack - Stack of Objective-C exception values, used for
end_comment

begin_comment
comment|/// rethrows.
end_comment

begin_expr_stmt
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
end_expr_stmt

begin_comment
comment|/// A class controlling the emission of a finally block.
end_comment

begin_decl_stmt
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
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|/// Returns true inside SEH __try blocks.
end_comment

begin_expr_stmt
name|bool
name|isSEHTryScope
argument_list|()
specifier|const
block|{
return|return
operator|!
name|SEHTryEpilogueStack
operator|.
name|empty
argument_list|()
return|;
block|}
end_expr_stmt

begin_comment
comment|/// Returns true while emitting a cleanuppad.
end_comment

begin_expr_stmt
name|bool
name|isCleanupPadScope
argument_list|()
specifier|const
block|{
return|return
name|CurrentFuncletPad
operator|&&
name|isa
operator|<
name|llvm
operator|::
name|CleanupPadInst
operator|>
operator|(
name|CurrentFuncletPad
operator|)
return|;
block|}
end_expr_stmt

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
operator|...
name|As
operator|>
name|void
name|pushFullExprCleanup
argument_list|(
argument|CleanupKind kind
argument_list|,
argument|As... A
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
name|A
operator|...
operator|)
return|;
end_expr_stmt

begin_comment
comment|// Stash values in a tuple so we can guarantee the order of saves.
end_comment

begin_typedef
typedef|typedef
name|std
operator|::
name|tuple
operator|<
name|typename
name|DominatingValue
operator|<
name|As
operator|>
operator|::
name|saved_type
operator|...
operator|>
name|SavedTuple
expr_stmt|;
end_typedef

begin_decl_stmt
name|SavedTuple
name|Saved
block|{
name|saveValueInCond
argument_list|(
name|A
argument_list|)
operator|...
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_typedef
typedef|typedef
name|EHScopeStack
operator|::
name|ConditionalCleanup
operator|<
name|T
operator|,
name|As
operator|...
operator|>
name|CleanupType
expr_stmt|;
end_typedef

begin_expr_stmt
name|EHStack
operator|.
name|pushCleanupTuple
operator|<
name|CleanupType
operator|>
operator|(
name|kind
operator|,
name|Saved
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
operator|...
name|As
operator|>
name|void
name|pushCleanupAfterFullExpr
argument_list|(
argument|CleanupKind Kind
argument_list|,
argument|As... A
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
name|static_assert
argument_list|(
sizeof|sizeof
argument_list|(
name|Header
argument_list|)
operator|%
name|alignof
argument_list|(
name|T
argument_list|)
operator|==
literal|0
argument_list|,
literal|"Cleanup will be allocated on misaligned address"
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
name|A
operator|...
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

begin_function_decl
name|void
name|PushDestructorCleanup
parameter_list|(
name|QualType
name|T
parameter_list|,
name|Address
name|Addr
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// PushDestructorCleanup - Push a cleanup to call the
end_comment

begin_comment
comment|/// complete-object variant of the given destructor on the object at
end_comment

begin_comment
comment|/// the given address.
end_comment

begin_function_decl
name|void
name|PushDestructorCleanup
parameter_list|(
specifier|const
name|CXXDestructorDecl
modifier|*
name|Dtor
parameter_list|,
name|Address
name|Addr
parameter_list|)
function_decl|;
end_function_decl

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
specifier|const
name|RunCleanupsScope
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
name|RunCleanupsScope
operator|&
operator|)
operator|=
name|delete
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
comment|/// \brief Exit this cleanup scope, emitting any accumulated cleanups.
operator|~
name|RunCleanupsScope
argument_list|()
block|{
if|if
condition|(
name|PerformCleanup
condition|)
name|ForceCleanup
argument_list|()
expr_stmt|;
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
comment|/// \param ValuesToReload - A list of values that need to be available at
comment|/// the insertion point after cleanup emission. If cleanup emission created
comment|/// a shared cleanup block, these value pointers will be rewritten.
comment|/// Otherwise, they not will be modified.
name|void
name|ForceCleanup
argument_list|(
name|std
operator|::
name|initializer_list
operator|<
name|llvm
operator|::
name|Value
operator|*
operator|*
operator|>
name|ValuesToReload
operator|=
block|{}
argument_list|)
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
argument_list|,
name|ValuesToReload
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
name|public
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
specifier|const
name|LexicalScope
operator|&
argument_list|)
operator|=
name|delete
block|;
name|void
name|operator
operator|=
operator|(
specifier|const
name|LexicalScope
operator|&
operator|)
operator|=
name|delete
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
block|{
name|ApplyDebugLocation
name|DL
argument_list|(
name|CGF
argument_list|,
name|Range
operator|.
name|getEnd
argument_list|()
argument_list|)
decl_stmt|;
name|ForceCleanup
argument_list|()
expr_stmt|;
block|}
block|}
comment|/// \brief Force the emission of cleanups now, instead of waiting
comment|/// until this object is destroyed.
name|void
name|ForceCleanup
argument_list|()
block|{
name|CGF
operator|.
name|CurLexicalScope
operator|=
name|ParentScope
block|;
name|RunCleanupsScope
operator|::
name|ForceCleanup
argument_list|()
block|;
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
end_decl_stmt

begin_expr_stmt
name|bool
name|hasLabels
argument_list|()
specifier|const
block|{
return|return
operator|!
name|Labels
operator|.
name|empty
argument_list|()
return|;
block|}
end_expr_stmt

begin_function_decl
name|void
name|rescopeLabels
parameter_list|()
function_decl|;
end_function_decl

begin_typedef
unit|};
typedef|typedef
name|llvm
operator|::
name|DenseMap
operator|<
specifier|const
name|Decl
operator|*
operator|,
name|Address
operator|>
name|DeclMapTy
expr_stmt|;
end_typedef

begin_comment
comment|/// \brief The scope used to remap some variables as private in the OpenMP
end_comment

begin_comment
comment|/// loop body (or other captured region emitted without outlining), and to
end_comment

begin_comment
comment|/// restore old vars back on exit.
end_comment

begin_decl_stmt
name|class
name|OMPPrivateScope
range|:
name|public
name|RunCleanupsScope
block|{
name|DeclMapTy
name|SavedLocals
block|;
name|DeclMapTy
name|SavedPrivates
block|;
name|private
operator|:
name|OMPPrivateScope
argument_list|(
specifier|const
name|OMPPrivateScope
operator|&
argument_list|)
operator|=
name|delete
block|;
name|void
name|operator
operator|=
operator|(
specifier|const
name|OMPPrivateScope
operator|&
operator|)
operator|=
name|delete
block|;
name|public
operator|:
comment|/// \brief Enter a new OpenMP private scope.
name|explicit
name|OMPPrivateScope
argument_list|(
name|CodeGenFunction
operator|&
name|CGF
argument_list|)
operator|:
name|RunCleanupsScope
argument_list|(
argument|CGF
argument_list|)
block|{}
comment|/// \brief Registers \a LocalVD variable as a private and apply \a
comment|/// PrivateGen function for it to generate corresponding private variable.
comment|/// \a PrivateGen returns an address of the generated private variable.
comment|/// \return true if the variable is registered as private, false if it has
comment|/// been privatized already.
name|bool
name|addPrivate
argument_list|(
argument|const VarDecl *LocalVD
argument_list|,
argument|llvm::function_ref<Address()> PrivateGen
argument_list|)
block|{
name|assert
argument_list|(
name|PerformCleanup
operator|&&
literal|"adding private to dead scope"
argument_list|)
block|;
comment|// Only save it once.
if|if
condition|(
name|SavedLocals
operator|.
name|count
argument_list|(
name|LocalVD
argument_list|)
condition|)
return|return
name|false
return|;
comment|// Copy the existing local entry to SavedLocals.
name|auto
name|it
operator|=
name|CGF
operator|.
name|LocalDeclMap
operator|.
name|find
argument_list|(
name|LocalVD
argument_list|)
block|;
if|if
condition|(
name|it
operator|!=
name|CGF
operator|.
name|LocalDeclMap
operator|.
name|end
argument_list|()
condition|)
block|{
name|SavedLocals
operator|.
name|insert
argument_list|(
block|{
name|LocalVD
block|,
name|it
operator|->
name|second
block|}
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|SavedLocals
operator|.
name|insert
argument_list|(
block|{
name|LocalVD
block|,
name|Address
operator|::
name|invalid
argument_list|()
block|}
argument_list|)
expr_stmt|;
block|}
comment|// Generate the private entry.
name|Address
name|Addr
init|=
name|PrivateGen
argument_list|()
decl_stmt|;
name|QualType
name|VarTy
operator|=
name|LocalVD
operator|->
name|getType
argument_list|()
decl_stmt|;
end_decl_stmt

begin_if
if|if
condition|(
name|VarTy
operator|->
name|isReferenceType
argument_list|()
condition|)
block|{
name|Address
name|Temp
init|=
name|CGF
operator|.
name|CreateMemTemp
argument_list|(
name|VarTy
argument_list|)
decl_stmt|;
name|CGF
operator|.
name|Builder
operator|.
name|CreateStore
argument_list|(
name|Addr
operator|.
name|getPointer
argument_list|()
argument_list|,
name|Temp
argument_list|)
expr_stmt|;
name|Addr
operator|=
name|Temp
expr_stmt|;
block|}
end_if

begin_expr_stmt
name|SavedPrivates
operator|.
name|insert
argument_list|(
block|{
name|LocalVD
block|,
name|Addr
block|}
argument_list|)
expr_stmt|;
end_expr_stmt

begin_return
return|return
name|true
return|;
end_return

begin_comment
unit|}
comment|/// \brief Privatizes local variables previously registered as private.
end_comment

begin_comment
comment|/// Registration is separate from the actual privatization to allow
end_comment

begin_comment
comment|/// initializers use values of the original variables, not the private one.
end_comment

begin_comment
comment|/// This is important, for example, if the private variable is a class
end_comment

begin_comment
comment|/// variable initialized by a constructor that references other private
end_comment

begin_comment
comment|/// variables. But at initialization original variables must be used, not
end_comment

begin_comment
comment|/// private copies.
end_comment

begin_comment
comment|/// \return true if at least one variable was privatized, false otherwise.
end_comment

begin_macro
unit|bool
name|Privatize
argument_list|()
end_macro

begin_block
block|{
name|copyInto
argument_list|(
name|SavedPrivates
argument_list|,
name|CGF
operator|.
name|LocalDeclMap
argument_list|)
expr_stmt|;
name|SavedPrivates
operator|.
name|clear
argument_list|()
expr_stmt|;
return|return
operator|!
name|SavedLocals
operator|.
name|empty
argument_list|()
return|;
block|}
end_block

begin_function
name|void
name|ForceCleanup
parameter_list|()
block|{
name|RunCleanupsScope
operator|::
name|ForceCleanup
argument_list|()
expr_stmt|;
name|copyInto
argument_list|(
name|SavedLocals
argument_list|,
name|CGF
operator|.
name|LocalDeclMap
argument_list|)
expr_stmt|;
name|SavedLocals
operator|.
name|clear
argument_list|()
expr_stmt|;
block|}
end_function

begin_comment
comment|/// \brief Exit scope - all the mapped variables are restored.
end_comment

begin_expr_stmt
operator|~
name|OMPPrivateScope
argument_list|()
block|{
if|if
condition|(
name|PerformCleanup
condition|)
name|ForceCleanup
argument_list|()
expr_stmt|;
block|}
end_expr_stmt

begin_comment
comment|/// Checks if the global variable is captured in current function.
end_comment

begin_decl_stmt
name|bool
name|isGlobalVarCaptured
argument_list|(
specifier|const
name|VarDecl
operator|*
name|VD
argument_list|)
decl|const
block|{
return|return
operator|!
name|VD
operator|->
name|isLocalVarDeclOrParm
argument_list|()
operator|&&
name|CGF
operator|.
name|LocalDeclMap
operator|.
name|count
argument_list|(
name|VD
argument_list|)
operator|>
literal|0
return|;
block|}
end_decl_stmt

begin_label
name|private
label|:
end_label

begin_comment
comment|/// Copy all the entries in the source map over the corresponding
end_comment

begin_comment
comment|/// entries in the destination, which must exist.
end_comment

begin_function
specifier|static
name|void
name|copyInto
parameter_list|(
specifier|const
name|DeclMapTy
modifier|&
name|src
parameter_list|,
name|DeclMapTy
modifier|&
name|dest
parameter_list|)
block|{
for|for
control|(
name|auto
operator|&
name|pair
operator|:
name|src
control|)
block|{
if|if
condition|(
operator|!
name|pair
operator|.
name|second
operator|.
name|isValid
argument_list|()
condition|)
block|{
name|dest
operator|.
name|erase
argument_list|(
name|pair
operator|.
name|first
argument_list|)
expr_stmt|;
continue|continue;
block|}
name|auto
name|it
init|=
name|dest
operator|.
name|find
argument_list|(
name|pair
operator|.
name|first
argument_list|)
decl_stmt|;
if|if
condition|(
name|it
operator|!=
name|dest
operator|.
name|end
argument_list|()
condition|)
block|{
name|it
operator|->
name|second
operator|=
name|pair
operator|.
name|second
expr_stmt|;
block|}
else|else
block|{
name|dest
operator|.
name|insert
argument_list|(
name|pair
argument_list|)
expr_stmt|;
block|}
block|}
block|}
end_function

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
argument_list|,
name|std
operator|::
name|initializer_list
operator|<
name|llvm
operator|::
name|Value
operator|*
operator|*
operator|>
name|ValuesToReload
operator|=
block|{}
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
argument_list|,
name|std
operator|::
name|initializer_list
operator|<
name|llvm
operator|::
name|Value
operator|*
operator|*
operator|>
name|ValuesToReload
operator|=
block|{}
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

begin_expr_stmt
name|llvm
operator|::
name|BasicBlock
operator|*
name|getMSVCDispatchBlock
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
name|nullptr
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
name|nullptr
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
name|nullptr
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
name|Address
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
name|auto
name|store
init|=
name|new
name|llvm
operator|::
name|StoreInst
argument_list|(
name|value
argument_list|,
name|addr
operator|.
name|getPointer
argument_list|()
argument_list|,
operator|&
name|block
operator|->
name|back
argument_list|()
argument_list|)
decl_stmt|;
name|store
operator|->
name|setAlignment
argument_list|(
name|addr
operator|.
name|getAlignment
argument_list|()
operator|.
name|getQuantity
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
name|nullptr
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
argument|nullptr
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
argument|nullptr
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
name|isFunctionType
argument_list|()
operator|||
name|hasAggregateEvaluationKind
argument_list|(
name|expr
operator|->
name|getType
argument_list|()
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
name|nullptr
return|;
block|}
name|void
name|clear
parameter_list|()
block|{
name|OpaqueValue
operator|=
name|nullptr
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

begin_comment
comment|/// Build the opaque value mapping for an OpaqueValueExpr whose source
end_comment

begin_comment
comment|/// expression is set to the expression the OVE represents.
end_comment

begin_expr_stmt
name|OpaqueValueMapping
argument_list|(
name|CodeGenFunction
operator|&
name|CGF
argument_list|,
specifier|const
name|OpaqueValueExpr
operator|*
name|OV
argument_list|)
operator|:
name|CGF
argument_list|(
argument|CGF
argument_list|)
block|{
if|if
condition|(
name|OV
condition|)
block|{
name|assert
argument_list|(
name|OV
operator|->
name|getSourceExpr
argument_list|()
operator|&&
literal|"wrong form of OpaqueValueMapping used "
literal|"for OVE with no source expression"
argument_list|)
expr_stmt|;
name|Data
operator|=
name|OpaqueValueMappingData
operator|::
name|bind
argument_list|(
name|CGF
argument_list|,
name|OV
argument_list|,
name|OV
operator|->
name|getSourceExpr
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_expr_stmt

begin_expr_stmt
unit|}      OpaqueValueMapping
operator|(
name|CodeGenFunction
operator|&
name|CGF
operator|,
specifier|const
name|OpaqueValueExpr
operator|*
name|opaqueValue
operator|,
name|LValue
name|lvalue
operator|)
operator|:
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

begin_label
unit|};
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

begin_decl_stmt
name|DeclMapTy
name|LocalDeclMap
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// SizeArguments - If a ParmVarDecl had the pass_object_size attribute, this
end_comment

begin_comment
comment|/// will contain a mapping from said ParmVarDecl to its implicit "object_size"
end_comment

begin_comment
comment|/// parameter.
end_comment

begin_expr_stmt
name|llvm
operator|::
name|SmallDenseMap
operator|<
specifier|const
name|ParmVarDecl
operator|*
operator|,
specifier|const
name|ImplicitParamDecl
operator|*
operator|,
literal|2
operator|>
name|SizeArguments
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// Track escaped local variables with auto storage. Used during SEH
end_comment

begin_comment
comment|/// outlining to produce a call to llvm.localescape.
end_comment

begin_expr_stmt
name|llvm
operator|::
name|DenseMap
operator|<
name|llvm
operator|::
name|AllocaInst
operator|*
operator|,
name|int
operator|>
name|EscapedLocals
expr_stmt|;
end_expr_stmt

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
comment|/// Handles cancellation exit points in OpenMP-related constructs.
end_comment

begin_decl_stmt
name|class
name|OpenMPCancelExitStack
block|{
comment|/// Tracks cancellation exit point and join point for cancel-related exit
comment|/// and normal exit.
struct|struct
name|CancelExit
block|{
name|CancelExit
argument_list|()
operator|=
expr|default
expr_stmt|;
name|CancelExit
argument_list|(
argument|OpenMPDirectiveKind Kind
argument_list|,
argument|JumpDest ExitBlock
argument_list|,
argument|JumpDest ContBlock
argument_list|)
block|:
name|Kind
argument_list|(
name|Kind
argument_list|)
operator|,
name|ExitBlock
argument_list|(
name|ExitBlock
argument_list|)
operator|,
name|ContBlock
argument_list|(
argument|ContBlock
argument_list|)
block|{}
name|OpenMPDirectiveKind
name|Kind
operator|=
name|OMPD_unknown
expr_stmt|;
comment|/// true if the exit block has been emitted already by the special
comment|/// emitExit() call, false if the default codegen is used.
name|bool
name|HasBeenEmitted
init|=
name|false
decl_stmt|;
name|JumpDest
name|ExitBlock
decl_stmt|;
name|JumpDest
name|ContBlock
decl_stmt|;
block|}
struct|;
name|SmallVector
operator|<
name|CancelExit
operator|,
literal|8
operator|>
name|Stack
expr_stmt|;
name|public
label|:
name|OpenMPCancelExitStack
argument_list|()
operator|:
name|Stack
argument_list|(
literal|1
argument_list|)
block|{}
operator|~
name|OpenMPCancelExitStack
argument_list|()
operator|=
expr|default
expr_stmt|;
comment|/// Fetches the exit block for the current OpenMP construct.
name|JumpDest
name|getExitBlock
argument_list|()
specifier|const
block|{
return|return
name|Stack
operator|.
name|back
argument_list|()
operator|.
name|ExitBlock
return|;
block|}
comment|/// Emits exit block with special codegen procedure specific for the related
comment|/// OpenMP construct + emits code for normal construct cleanup.
name|void
name|emitExit
argument_list|(
name|CodeGenFunction
operator|&
name|CGF
argument_list|,
name|OpenMPDirectiveKind
name|Kind
argument_list|,
specifier|const
name|llvm
operator|::
name|function_ref
operator|<
name|void
argument_list|(
name|CodeGenFunction
operator|&
argument_list|)
operator|>
operator|&
name|CodeGen
argument_list|)
block|{
if|if
condition|(
name|Stack
operator|.
name|back
argument_list|()
operator|.
name|Kind
operator|==
name|Kind
operator|&&
name|getExitBlock
argument_list|()
operator|.
name|isValid
argument_list|()
condition|)
block|{
name|assert
argument_list|(
name|CGF
operator|.
name|getOMPCancelDestination
argument_list|(
name|Kind
argument_list|)
operator|.
name|isValid
argument_list|()
argument_list|)
expr_stmt|;
name|assert
argument_list|(
name|CGF
operator|.
name|HaveInsertPoint
argument_list|()
argument_list|)
expr_stmt|;
name|assert
argument_list|(
operator|!
name|Stack
operator|.
name|back
argument_list|()
operator|.
name|HasBeenEmitted
argument_list|)
expr_stmt|;
name|auto
name|IP
init|=
name|CGF
operator|.
name|Builder
operator|.
name|saveAndClearIP
argument_list|()
decl_stmt|;
name|CGF
operator|.
name|EmitBlock
argument_list|(
name|Stack
operator|.
name|back
argument_list|()
operator|.
name|ExitBlock
operator|.
name|getBlock
argument_list|()
argument_list|)
expr_stmt|;
name|CodeGen
argument_list|(
name|CGF
argument_list|)
expr_stmt|;
name|CGF
operator|.
name|EmitBranchThroughCleanup
argument_list|(
name|Stack
operator|.
name|back
argument_list|()
operator|.
name|ContBlock
argument_list|)
expr_stmt|;
name|CGF
operator|.
name|Builder
operator|.
name|restoreIP
argument_list|(
name|IP
argument_list|)
expr_stmt|;
name|Stack
operator|.
name|back
argument_list|()
operator|.
name|HasBeenEmitted
operator|=
name|true
expr_stmt|;
block|}
name|CodeGen
argument_list|(
name|CGF
argument_list|)
expr_stmt|;
block|}
comment|/// Enter the cancel supporting \a Kind construct.
comment|/// \param Kind OpenMP directive that supports cancel constructs.
comment|/// \param HasCancel true, if the construct has inner cancel directive,
comment|/// false otherwise.
name|void
name|enter
parameter_list|(
name|CodeGenFunction
modifier|&
name|CGF
parameter_list|,
name|OpenMPDirectiveKind
name|Kind
parameter_list|,
name|bool
name|HasCancel
parameter_list|)
block|{
name|Stack
operator|.
name|push_back
argument_list|(
block|{
name|Kind
block|,
name|HasCancel
condition|?
name|CGF
operator|.
name|getJumpDestInCurrentScope
argument_list|(
literal|"cancel.exit"
argument_list|)
else|:
name|JumpDest
argument_list|()
block|,
name|HasCancel
condition|?
name|CGF
operator|.
name|getJumpDestInCurrentScope
argument_list|(
literal|"cancel.cont"
argument_list|)
else|:
name|JumpDest
argument_list|()
block|}
argument_list|)
expr_stmt|;
block|}
comment|/// Emits default exit point for the cancel construct (if the special one
comment|/// has not be used) + join point for cancel/normal exits.
name|void
name|exit
parameter_list|(
name|CodeGenFunction
modifier|&
name|CGF
parameter_list|)
block|{
if|if
condition|(
name|getExitBlock
argument_list|()
operator|.
name|isValid
argument_list|()
condition|)
block|{
name|assert
argument_list|(
name|CGF
operator|.
name|getOMPCancelDestination
argument_list|(
name|Stack
operator|.
name|back
argument_list|()
operator|.
name|Kind
argument_list|)
operator|.
name|isValid
argument_list|()
argument_list|)
expr_stmt|;
name|bool
name|HaveIP
init|=
name|CGF
operator|.
name|HaveInsertPoint
argument_list|()
decl_stmt|;
if|if
condition|(
operator|!
name|Stack
operator|.
name|back
argument_list|()
operator|.
name|HasBeenEmitted
condition|)
block|{
if|if
condition|(
name|HaveIP
condition|)
name|CGF
operator|.
name|EmitBranchThroughCleanup
argument_list|(
name|Stack
operator|.
name|back
argument_list|()
operator|.
name|ContBlock
argument_list|)
expr_stmt|;
name|CGF
operator|.
name|EmitBlock
argument_list|(
name|Stack
operator|.
name|back
argument_list|()
operator|.
name|ExitBlock
operator|.
name|getBlock
argument_list|()
argument_list|)
expr_stmt|;
name|CGF
operator|.
name|EmitBranchThroughCleanup
argument_list|(
name|Stack
operator|.
name|back
argument_list|()
operator|.
name|ContBlock
argument_list|)
expr_stmt|;
block|}
name|CGF
operator|.
name|EmitBlock
argument_list|(
name|Stack
operator|.
name|back
argument_list|()
operator|.
name|ContBlock
operator|.
name|getBlock
argument_list|()
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|HaveIP
condition|)
block|{
name|CGF
operator|.
name|Builder
operator|.
name|CreateUnreachable
argument_list|()
expr_stmt|;
name|CGF
operator|.
name|Builder
operator|.
name|ClearInsertionPoint
argument_list|()
expr_stmt|;
block|}
block|}
name|Stack
operator|.
name|pop_back
argument_list|()
expr_stmt|;
block|}
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_decl_stmt
name|OpenMPCancelExitStack
name|OMPCancelStack
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// Controls insertion of cancellation exit blocks in worksharing constructs.
end_comment

begin_decl_stmt
name|class
name|OMPCancelStackRAII
block|{
name|CodeGenFunction
modifier|&
name|CGF
decl_stmt|;
name|public
label|:
name|OMPCancelStackRAII
argument_list|(
argument|CodeGenFunction&CGF
argument_list|,
argument|OpenMPDirectiveKind Kind
argument_list|,
argument|bool HasCancel
argument_list|)
block|:
name|CGF
argument_list|(
argument|CGF
argument_list|)
block|{
name|CGF
operator|.
name|OMPCancelStack
operator|.
name|enter
argument_list|(
name|CGF
argument_list|,
name|Kind
argument_list|,
name|HasCancel
argument_list|)
expr_stmt|;
block|}
operator|~
name|OMPCancelStackRAII
argument_list|()
block|{
name|CGF
operator|.
name|OMPCancelStack
operator|.
name|exit
argument_list|(
name|CGF
argument_list|)
block|; }
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_decl_stmt
name|CodeGenPGO
name|PGO
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// Calculate branch weights appropriate for PGO data
end_comment

begin_expr_stmt
name|llvm
operator|::
name|MDNode
operator|*
name|createProfileWeights
argument_list|(
argument|uint64_t TrueCount
argument_list|,
argument|uint64_t FalseCount
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|llvm
operator|::
name|MDNode
operator|*
name|createProfileWeights
argument_list|(
name|ArrayRef
operator|<
name|uint64_t
operator|>
name|Weights
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|llvm
operator|::
name|MDNode
operator|*
name|createProfileWeightsForLoop
argument_list|(
argument|const Stmt *Cond
argument_list|,
argument|uint64_t LoopCount
argument_list|)
expr_stmt|;
end_expr_stmt

begin_label
name|public
label|:
end_label

begin_comment
comment|/// Increment the profiler's counter for the given statement by \p StepV.
end_comment

begin_comment
comment|/// If \p StepV is null, the default increment is 1.
end_comment

begin_decl_stmt
name|void
name|incrementProfileCounter
argument_list|(
specifier|const
name|Stmt
operator|*
name|S
argument_list|,
name|llvm
operator|::
name|Value
operator|*
name|StepV
operator|=
name|nullptr
argument_list|)
block|{
if|if
condition|(
name|CGM
operator|.
name|getCodeGenOpts
argument_list|()
operator|.
name|hasProfileClangInstr
argument_list|()
condition|)
name|PGO
operator|.
name|emitCounterIncrement
argument_list|(
name|Builder
argument_list|,
name|S
argument_list|,
name|StepV
argument_list|)
expr_stmt|;
name|PGO
operator|.
name|setCurrentStmt
argument_list|(
name|S
argument_list|)
expr_stmt|;
block|}
end_decl_stmt

begin_comment
comment|/// Get the profiler's count for the given statement.
end_comment

begin_function
name|uint64_t
name|getProfileCount
parameter_list|(
specifier|const
name|Stmt
modifier|*
name|S
parameter_list|)
block|{
name|Optional
operator|<
name|uint64_t
operator|>
name|Count
operator|=
name|PGO
operator|.
name|getStmtCount
argument_list|(
name|S
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|Count
operator|.
name|hasValue
argument_list|()
condition|)
return|return
literal|0
return|;
return|return
operator|*
name|Count
return|;
block|}
end_function

begin_comment
comment|/// Set the profiler's current count.
end_comment

begin_function
name|void
name|setCurrentProfileCount
parameter_list|(
name|uint64_t
name|Count
parameter_list|)
block|{
name|PGO
operator|.
name|setCurrentRegionCount
argument_list|(
name|Count
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/// Get the profiler's current count. This is generally the count for the most
end_comment

begin_comment
comment|/// recently incremented counter.
end_comment

begin_function
name|uint64_t
name|getCurrentProfileCount
parameter_list|()
block|{
return|return
name|PGO
operator|.
name|getCurrentRegionCount
argument_list|()
return|;
block|}
end_function

begin_label
name|private
label|:
end_label

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
comment|/// The branch weights of SwitchInsn when doing instrumentation based PGO.
end_comment

begin_expr_stmt
name|SmallVector
operator|<
name|uint64_t
operator|,
literal|16
operator|>
operator|*
name|SwitchWeights
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
argument|CodeGenFunction&CGF
argument_list|,
argument|Address This
argument_list|)
block|:
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
name|Address
name|OldCXXDefaultInitExprThis
decl_stmt|;
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
name|CGF
operator|.
name|CXXThisValue
argument_list|)
operator|,
name|OldCXXThisAlignment
argument_list|(
argument|CGF.CXXThisAlignment
argument_list|)
block|{
name|CGF
operator|.
name|CXXThisValue
operator|=
name|CGF
operator|.
name|CXXDefaultInitExprThis
operator|.
name|getPointer
argument_list|()
block|;
name|CGF
operator|.
name|CXXThisAlignment
operator|=
name|CGF
operator|.
name|CXXDefaultInitExprThis
operator|.
name|getAlignment
argument_list|()
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
block|;
name|CGF
operator|.
name|CXXThisAlignment
operator|=
name|OldCXXThisAlignment
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
name|CharUnits
name|OldCXXThisAlignment
decl_stmt|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|/// The scope of an ArrayInitLoopExpr. Within this scope, the value of the
end_comment

begin_comment
comment|/// current loop index is overridden.
end_comment

begin_decl_stmt
name|class
name|ArrayInitLoopExprScope
block|{
name|public
label|:
name|ArrayInitLoopExprScope
argument_list|(
name|CodeGenFunction
operator|&
name|CGF
argument_list|,
name|llvm
operator|::
name|Value
operator|*
name|Index
argument_list|)
operator|:
name|CGF
argument_list|(
name|CGF
argument_list|)
operator|,
name|OldArrayInitIndex
argument_list|(
argument|CGF.ArrayInitIndex
argument_list|)
block|{
name|CGF
operator|.
name|ArrayInitIndex
operator|=
name|Index
block|;     }
operator|~
name|ArrayInitLoopExprScope
argument_list|()
block|{
name|CGF
operator|.
name|ArrayInitIndex
operator|=
name|OldArrayInitIndex
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
name|OldArrayInitIndex
expr_stmt|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_decl_stmt
name|class
name|InlinedInheritingConstructorScope
block|{
name|public
label|:
name|InlinedInheritingConstructorScope
argument_list|(
argument|CodeGenFunction&CGF
argument_list|,
argument|GlobalDecl GD
argument_list|)
block|:
name|CGF
argument_list|(
name|CGF
argument_list|)
operator|,
name|OldCurGD
argument_list|(
name|CGF
operator|.
name|CurGD
argument_list|)
operator|,
name|OldCurFuncDecl
argument_list|(
name|CGF
operator|.
name|CurFuncDecl
argument_list|)
operator|,
name|OldCurCodeDecl
argument_list|(
name|CGF
operator|.
name|CurCodeDecl
argument_list|)
operator|,
name|OldCXXABIThisDecl
argument_list|(
name|CGF
operator|.
name|CXXABIThisDecl
argument_list|)
operator|,
name|OldCXXABIThisValue
argument_list|(
name|CGF
operator|.
name|CXXABIThisValue
argument_list|)
operator|,
name|OldCXXThisValue
argument_list|(
name|CGF
operator|.
name|CXXThisValue
argument_list|)
operator|,
name|OldCXXABIThisAlignment
argument_list|(
name|CGF
operator|.
name|CXXABIThisAlignment
argument_list|)
operator|,
name|OldCXXThisAlignment
argument_list|(
name|CGF
operator|.
name|CXXThisAlignment
argument_list|)
operator|,
name|OldReturnValue
argument_list|(
name|CGF
operator|.
name|ReturnValue
argument_list|)
operator|,
name|OldFnRetTy
argument_list|(
name|CGF
operator|.
name|FnRetTy
argument_list|)
operator|,
name|OldCXXInheritedCtorInitExprArgs
argument_list|(
argument|std::move(CGF.CXXInheritedCtorInitExprArgs)
argument_list|)
block|{
name|CGF
operator|.
name|CurGD
operator|=
name|GD
block|;
name|CGF
operator|.
name|CurFuncDecl
operator|=
name|CGF
operator|.
name|CurCodeDecl
operator|=
name|cast
operator|<
name|CXXConstructorDecl
operator|>
operator|(
name|GD
operator|.
name|getDecl
argument_list|()
operator|)
block|;
name|CGF
operator|.
name|CXXABIThisDecl
operator|=
name|nullptr
block|;
name|CGF
operator|.
name|CXXABIThisValue
operator|=
name|nullptr
block|;
name|CGF
operator|.
name|CXXThisValue
operator|=
name|nullptr
block|;
name|CGF
operator|.
name|CXXABIThisAlignment
operator|=
name|CharUnits
argument_list|()
block|;
name|CGF
operator|.
name|CXXThisAlignment
operator|=
name|CharUnits
argument_list|()
block|;
name|CGF
operator|.
name|ReturnValue
operator|=
name|Address
operator|::
name|invalid
argument_list|()
block|;
name|CGF
operator|.
name|FnRetTy
operator|=
name|QualType
argument_list|()
block|;
name|CGF
operator|.
name|CXXInheritedCtorInitExprArgs
operator|.
name|clear
argument_list|()
block|;     }
operator|~
name|InlinedInheritingConstructorScope
argument_list|()
block|{
name|CGF
operator|.
name|CurGD
operator|=
name|OldCurGD
block|;
name|CGF
operator|.
name|CurFuncDecl
operator|=
name|OldCurFuncDecl
block|;
name|CGF
operator|.
name|CurCodeDecl
operator|=
name|OldCurCodeDecl
block|;
name|CGF
operator|.
name|CXXABIThisDecl
operator|=
name|OldCXXABIThisDecl
block|;
name|CGF
operator|.
name|CXXABIThisValue
operator|=
name|OldCXXABIThisValue
block|;
name|CGF
operator|.
name|CXXThisValue
operator|=
name|OldCXXThisValue
block|;
name|CGF
operator|.
name|CXXABIThisAlignment
operator|=
name|OldCXXABIThisAlignment
block|;
name|CGF
operator|.
name|CXXThisAlignment
operator|=
name|OldCXXThisAlignment
block|;
name|CGF
operator|.
name|ReturnValue
operator|=
name|OldReturnValue
block|;
name|CGF
operator|.
name|FnRetTy
operator|=
name|OldFnRetTy
block|;
name|CGF
operator|.
name|CXXInheritedCtorInitExprArgs
operator|=
name|std
operator|::
name|move
argument_list|(
name|OldCXXInheritedCtorInitExprArgs
argument_list|)
block|;     }
name|private
operator|:
name|CodeGenFunction
operator|&
name|CGF
expr_stmt|;
name|GlobalDecl
name|OldCurGD
decl_stmt|;
specifier|const
name|Decl
modifier|*
name|OldCurFuncDecl
decl_stmt|;
specifier|const
name|Decl
modifier|*
name|OldCurCodeDecl
decl_stmt|;
name|ImplicitParamDecl
modifier|*
name|OldCXXABIThisDecl
decl_stmt|;
name|llvm
operator|::
name|Value
operator|*
name|OldCXXABIThisValue
expr_stmt|;
name|llvm
operator|::
name|Value
operator|*
name|OldCXXThisValue
expr_stmt|;
name|CharUnits
name|OldCXXABIThisAlignment
decl_stmt|;
name|CharUnits
name|OldCXXThisAlignment
decl_stmt|;
name|Address
name|OldReturnValue
decl_stmt|;
name|QualType
name|OldFnRetTy
decl_stmt|;
name|CallArgList
name|OldCXXInheritedCtorInitExprArgs
decl_stmt|;
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

begin_decl_stmt
name|CharUnits
name|CXXABIThisAlignment
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|CharUnits
name|CXXThisAlignment
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// The value of 'this' to use when evaluating CXXDefaultInitExprs within
end_comment

begin_comment
comment|/// this expression.
end_comment

begin_decl_stmt
name|Address
name|CXXDefaultInitExprThis
init|=
name|Address
operator|::
name|invalid
argument_list|()
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// The current array initialization index when evaluating an
end_comment

begin_comment
comment|/// ArrayInitIndexExpr within an ArrayInitLoopExpr.
end_comment

begin_expr_stmt
name|llvm
operator|::
name|Value
operator|*
name|ArrayInitIndex
operator|=
name|nullptr
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// The values of function arguments to use when evaluating
end_comment

begin_comment
comment|/// CXXInheritedCtorInitExprs within this context.
end_comment

begin_decl_stmt
name|CallArgList
name|CXXInheritedCtorInitExprArgs
decl_stmt|;
end_decl_stmt

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
comment|/// BlockByrefInfos - For each __block variable, contains
end_comment

begin_comment
comment|/// information about the layout of the variable.
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
name|BlockByrefInfo
operator|>
name|BlockByrefInfos
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// Used by -fsanitize=nullability-return to determine whether the return
end_comment

begin_comment
comment|/// value can be checked.
end_comment

begin_expr_stmt
name|llvm
operator|::
name|Value
operator|*
name|RetValNullabilityPrecondition
operator|=
name|nullptr
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// Check if -fsanitize=nullability-return instrumentation is required for
end_comment

begin_comment
comment|/// this function.
end_comment

begin_expr_stmt
name|bool
name|requiresReturnValueNullabilityCheck
argument_list|()
specifier|const
block|{
return|return
name|RetValNullabilityPrecondition
return|;
block|}
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
comment|/// True if we need emit the life-time markers.
end_comment

begin_decl_stmt
specifier|const
name|bool
name|ShouldEmitLifetimeMarkers
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// Add OpenCL kernel arg metadata and the kernel attribute meatadata to
end_comment

begin_comment
comment|/// the function metadata.
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
name|nullptr
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

begin_function_decl
name|Address
name|getExceptionSlot
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|Address
name|getEHSelectorSlot
parameter_list|()
function_decl|;
end_function_decl

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

begin_function_decl
name|Address
name|getNormalCleanupDestSlot
parameter_list|()
function_decl|;
end_function_decl

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
name|nullptr
return|;
end_expr_stmt

begin_return
return|return
name|getInvokeDestImpl
argument_list|()
return|;
end_return

begin_macro
unit|}    bool
name|currentFunctionUsesSEHTry
argument_list|()
end_macro

begin_expr_stmt
specifier|const
block|{
return|return
name|CurSEHParent
operator|!=
name|nullptr
return|;
block|}
end_expr_stmt

begin_expr_stmt
specifier|const
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
parameter_list|(
name|CodeGenFunction
modifier|&
name|CGF
parameter_list|,
name|Address
name|addr
parameter_list|,
name|QualType
name|ty
parameter_list|)
function_decl|;
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
name|Address
name|arrayEndPointer
argument_list|,
name|QualType
name|elementType
argument_list|,
name|CharUnits
name|elementAlignment
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
name|CharUnits
name|elementAlignment
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
name|Address
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
name|Address
name|addr
argument_list|,
name|QualType
name|type
argument_list|)
decl_stmt|;
end_decl_stmt

begin_function_decl
name|void
name|pushDestroy
parameter_list|(
name|CleanupKind
name|kind
parameter_list|,
name|Address
name|addr
parameter_list|,
name|QualType
name|type
parameter_list|,
name|Destroyer
modifier|*
name|destroyer
parameter_list|,
name|bool
name|useEHCleanupForArray
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|pushLifetimeExtendedDestroy
parameter_list|(
name|CleanupKind
name|kind
parameter_list|,
name|Address
name|addr
parameter_list|,
name|QualType
name|type
parameter_list|,
name|Destroyer
modifier|*
name|destroyer
parameter_list|,
name|bool
name|useEHCleanupForArray
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
name|void
name|pushCallObjectDeleteCleanup
argument_list|(
specifier|const
name|FunctionDecl
operator|*
name|OperatorDelete
argument_list|,
name|llvm
operator|::
name|Value
operator|*
name|CompletePtr
argument_list|,
name|QualType
name|ElementType
argument_list|)
decl_stmt|;
end_decl_stmt

begin_function_decl
name|void
name|pushStackRestore
parameter_list|(
name|CleanupKind
name|kind
parameter_list|,
name|Address
name|SPMem
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|emitDestroy
parameter_list|(
name|Address
name|addr
parameter_list|,
name|QualType
name|type
parameter_list|,
name|Destroyer
modifier|*
name|destroyer
parameter_list|,
name|bool
name|useEHCleanupForArray
parameter_list|)
function_decl|;
end_function_decl

begin_expr_stmt
name|llvm
operator|::
name|Function
operator|*
name|generateDestroyHelper
argument_list|(
argument|Address addr
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
name|elementType
argument_list|,
name|CharUnits
name|elementAlign
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

begin_decl_stmt
name|void
name|setBlockContextParameter
argument_list|(
specifier|const
name|ImplicitParamDecl
operator|*
name|D
argument_list|,
name|unsigned
name|argNum
argument_list|,
name|llvm
operator|::
name|Value
operator|*
name|ptr
argument_list|)
decl_stmt|;
end_decl_stmt

begin_function_decl
name|Address
name|LoadBlockStruct
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|Address
name|GetAddrOfBlockDecl
parameter_list|(
specifier|const
name|VarDecl
modifier|*
name|var
parameter_list|,
name|bool
name|ByRef
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// BuildBlockByrefAddress - Computes the location of the
end_comment

begin_comment
comment|/// data in a variable which is declared as __block.
end_comment

begin_function_decl
name|Address
name|emitBlockByrefAddress
parameter_list|(
name|Address
name|baseAddr
parameter_list|,
specifier|const
name|VarDecl
modifier|*
name|V
parameter_list|,
name|bool
name|followForward
init|=
name|true
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
name|Address
name|emitBlockByrefAddress
argument_list|(
name|Address
name|baseAddr
argument_list|,
specifier|const
name|BlockByrefInfo
operator|&
name|info
argument_list|,
name|bool
name|followForward
argument_list|,
specifier|const
name|llvm
operator|::
name|Twine
operator|&
name|name
argument_list|)
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|const
name|BlockByrefInfo
modifier|&
name|getBlockByrefInfo
parameter_list|(
specifier|const
name|VarDecl
modifier|*
name|var
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|QualType
name|BuildFunctionArgList
parameter_list|(
name|GlobalDecl
name|GD
parameter_list|,
name|FunctionArgList
modifier|&
name|Args
parameter_list|)
function_decl|;
end_function_decl

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

begin_comment
comment|/// \brief Emit code for the start of a function.
end_comment

begin_comment
comment|/// \param Loc       The location to be associated with the function.
end_comment

begin_comment
comment|/// \param StartLoc  The location of the function body.
end_comment

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
name|Loc
operator|=
name|SourceLocation
argument_list|()
argument_list|,
name|SourceLocation
name|StartLoc
operator|=
name|SourceLocation
argument_list|()
argument_list|)
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|static
name|bool
name|IsConstructorDelegationValid
parameter_list|(
specifier|const
name|CXXConstructorDecl
modifier|*
name|Ctor
parameter_list|)
function_decl|;
end_function_decl

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

begin_decl_stmt
name|void
name|EmitBlockWithFallThrough
argument_list|(
name|llvm
operator|::
name|BasicBlock
operator|*
name|BB
argument_list|,
specifier|const
name|Stmt
operator|*
name|S
argument_list|)
decl_stmt|;
end_decl_stmt

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

begin_function_decl
name|void
name|EmitAsanPrologueOrEpilogue
parameter_list|(
name|bool
name|Prologue
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// \brief Emit the unified return block, trying to avoid its emission when
end_comment

begin_comment
comment|/// possible.
end_comment

begin_comment
comment|/// \return The debug location of the user written return statement if the
end_comment

begin_comment
comment|/// return block is is avoided.
end_comment

begin_expr_stmt
name|llvm
operator|::
name|DebugLoc
name|EmitReturnBlock
argument_list|()
expr_stmt|;
end_expr_stmt

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
name|llvm
operator|::
name|Constant
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

begin_function_decl
name|void
name|FinishThunk
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/// Emit a musttail call for a thunk with a potentially adjusted this pointer.
end_comment

begin_decl_stmt
name|void
name|EmitMustTailThunk
argument_list|(
specifier|const
name|CXXMethodDecl
operator|*
name|MD
argument_list|,
name|llvm
operator|::
name|Value
operator|*
name|AdjustedThisPtr
argument_list|,
name|llvm
operator|::
name|Value
operator|*
name|Callee
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// Generate a thunk for the given method.
end_comment

begin_decl_stmt
name|void
name|generateThunk
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

begin_expr_stmt
name|llvm
operator|::
name|Function
operator|*
name|GenerateVarArgsThunk
argument_list|(
argument|llvm::Function *Fn
argument_list|,
argument|const CGFunctionInfo&FnInfo
argument_list|,
argument|GlobalDecl GD
argument_list|,
argument|const ThunkInfo&Thunk
argument_list|)
expr_stmt|;
end_expr_stmt

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

begin_function_decl
name|void
name|EmitInitializerForField
parameter_list|(
name|FieldDecl
modifier|*
name|Field
parameter_list|,
name|LValue
name|LHS
parameter_list|,
name|Expr
modifier|*
name|Init
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// Struct with all informations about dynamic [sub]class needed to set vptr.
end_comment

begin_struct
struct|struct
name|VPtr
block|{
name|BaseSubobject
name|Base
decl_stmt|;
specifier|const
name|CXXRecordDecl
modifier|*
name|NearestVBase
decl_stmt|;
name|CharUnits
name|OffsetFromNearestVBase
decl_stmt|;
specifier|const
name|CXXRecordDecl
modifier|*
name|VTableClass
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/// Initialize the vtable pointer of the given subobject.
end_comment

begin_function_decl
name|void
name|InitializeVTablePointer
parameter_list|(
specifier|const
name|VPtr
modifier|&
name|vptr
parameter_list|)
function_decl|;
end_function_decl

begin_typedef
typedef|typedef
name|llvm
operator|::
name|SmallVector
operator|<
name|VPtr
operator|,
literal|4
operator|>
name|VPtrsVector
expr_stmt|;
end_typedef

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
name|VPtrsVector
name|getVTablePointers
parameter_list|(
specifier|const
name|CXXRecordDecl
modifier|*
name|VTableClass
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|getVTablePointers
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
parameter_list|,
name|VPtrsVector
modifier|&
name|vptrs
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
argument|Address This
argument_list|,
argument|llvm::Type *VTableTy
argument_list|,
argument|const CXXRecordDecl *VTableClass
argument_list|)
expr_stmt|;
end_expr_stmt

begin_enum
enum|enum
name|CFITypeCheckKind
block|{
name|CFITCK_VCall
block|,
name|CFITCK_NVCall
block|,
name|CFITCK_DerivedCast
block|,
name|CFITCK_UnrelatedCast
block|,
name|CFITCK_ICall
block|,   }
enum|;
end_enum

begin_comment
comment|/// \brief Derived is the presumed address of an object of type T after a
end_comment

begin_comment
comment|/// cast. If T is a polymorphic class type, emit a check that the virtual
end_comment

begin_comment
comment|/// table for Derived belongs to a class derived from T.
end_comment

begin_decl_stmt
name|void
name|EmitVTablePtrCheckForCast
argument_list|(
name|QualType
name|T
argument_list|,
name|llvm
operator|::
name|Value
operator|*
name|Derived
argument_list|,
name|bool
name|MayBeNull
argument_list|,
name|CFITypeCheckKind
name|TCK
argument_list|,
name|SourceLocation
name|Loc
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// EmitVTablePtrCheckForCall - Virtual method MD is being called via VTable.
end_comment

begin_comment
comment|/// If vptr CFI is enabled, emit a check that VTable is valid.
end_comment

begin_decl_stmt
name|void
name|EmitVTablePtrCheckForCall
argument_list|(
specifier|const
name|CXXRecordDecl
operator|*
name|RD
argument_list|,
name|llvm
operator|::
name|Value
operator|*
name|VTable
argument_list|,
name|CFITypeCheckKind
name|TCK
argument_list|,
name|SourceLocation
name|Loc
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// EmitVTablePtrCheck - Emit a check that VTable is a valid virtual table for
end_comment

begin_comment
comment|/// RD using llvm.type.test.
end_comment

begin_decl_stmt
name|void
name|EmitVTablePtrCheck
argument_list|(
specifier|const
name|CXXRecordDecl
operator|*
name|RD
argument_list|,
name|llvm
operator|::
name|Value
operator|*
name|VTable
argument_list|,
name|CFITypeCheckKind
name|TCK
argument_list|,
name|SourceLocation
name|Loc
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// If whole-program virtual table optimization is enabled, emit an assumption
end_comment

begin_comment
comment|/// that VTable is a member of RD's type identifier. Or, if vptr CFI is
end_comment

begin_comment
comment|/// enabled, emit a check that VTable is a member of RD's type identifier.
end_comment

begin_decl_stmt
name|void
name|EmitTypeMetadataCodeForVCall
argument_list|(
specifier|const
name|CXXRecordDecl
operator|*
name|RD
argument_list|,
name|llvm
operator|::
name|Value
operator|*
name|VTable
argument_list|,
name|SourceLocation
name|Loc
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// Returns whether we should perform a type checked load when loading a
end_comment

begin_comment
comment|/// virtual function for virtual calls to members of RD. This is generally
end_comment

begin_comment
comment|/// true when both vcall CFI and whole-program-vtables are enabled.
end_comment

begin_function_decl
name|bool
name|ShouldEmitVTableTypeCheckedLoad
parameter_list|(
specifier|const
name|CXXRecordDecl
modifier|*
name|RD
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// Emit a type checked load from the given vtable.
end_comment

begin_expr_stmt
name|llvm
operator|::
name|Value
operator|*
name|EmitVTableTypeCheckedLoad
argument_list|(
argument|const CXXRecordDecl *RD
argument_list|,
argument|llvm::Value *VTable
argument_list|,
argument|uint64_t VTableByteOffset
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
comment|/// ShouldXRayInstrument - Return true if the current function should be
end_comment

begin_comment
comment|/// instrumented with XRay nop sleds.
end_comment

begin_expr_stmt
name|bool
name|ShouldXRayInstrumentFunction
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt

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
comment|/// Emit a test that checks if the return value \p RV is nonnull.
end_comment

begin_decl_stmt
name|void
name|EmitReturnValueCheck
argument_list|(
name|llvm
operator|::
name|Value
operator|*
name|RV
argument_list|,
name|SourceLocation
name|EndLoc
argument_list|)
decl_stmt|;
end_decl_stmt

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
argument|llvm::Function *parent = nullptr
argument_list|,
argument|llvm::BasicBlock *before = nullptr
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
name|nullptr
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

begin_function
name|LValue
name|MakeAddrLValue
parameter_list|(
name|Address
name|Addr
parameter_list|,
name|QualType
name|T
parameter_list|,
name|LValueBaseInfo
name|BaseInfo
init|=
name|LValueBaseInfo
argument_list|(
name|AlignmentSource
operator|::
name|Type
argument_list|)
parameter_list|)
block|{
return|return
name|LValue
operator|::
name|MakeAddr
argument_list|(
name|Addr
argument_list|,
name|T
argument_list|,
name|getContext
argument_list|()
argument_list|,
name|BaseInfo
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
end_function

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
argument_list|,
name|LValueBaseInfo
name|BaseInfo
operator|=
name|LValueBaseInfo
argument_list|(
name|AlignmentSource
operator|::
name|Type
argument_list|)
argument_list|)
block|{
return|return
name|LValue
operator|::
name|MakeAddr
argument_list|(
name|Address
argument_list|(
name|V
argument_list|,
name|Alignment
argument_list|)
argument_list|,
name|T
argument_list|,
name|getContext
argument_list|()
argument_list|,
name|BaseInfo
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
name|MakeNaturalAlignPointeeAddrLValue
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
decl_stmt|;
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
decl_stmt|;
end_decl_stmt

begin_function_decl
name|CharUnits
name|getNaturalTypeAlignment
parameter_list|(
name|QualType
name|T
parameter_list|,
name|LValueBaseInfo
modifier|*
name|BaseInfo
init|=
name|nullptr
parameter_list|,
name|bool
name|forPointeeType
init|=
name|false
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|CharUnits
name|getNaturalPointeeTypeAlignment
parameter_list|(
name|QualType
name|T
parameter_list|,
name|LValueBaseInfo
modifier|*
name|BaseInfo
init|=
name|nullptr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|Address
name|EmitLoadOfReference
parameter_list|(
name|Address
name|Ref
parameter_list|,
specifier|const
name|ReferenceType
modifier|*
name|RefTy
parameter_list|,
name|LValueBaseInfo
modifier|*
name|BaseInfo
init|=
name|nullptr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|LValue
name|EmitLoadOfReferenceLValue
parameter_list|(
name|Address
name|Ref
parameter_list|,
specifier|const
name|ReferenceType
modifier|*
name|RefTy
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|Address
name|EmitLoadOfPointer
parameter_list|(
name|Address
name|Ptr
parameter_list|,
specifier|const
name|PointerType
modifier|*
name|PtrTy
parameter_list|,
name|LValueBaseInfo
modifier|*
name|BaseInfo
init|=
name|nullptr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|LValue
name|EmitLoadOfPointerLValue
parameter_list|(
name|Address
name|Ptr
parameter_list|,
specifier|const
name|PointerType
modifier|*
name|PtrTy
parameter_list|)
function_decl|;
end_function_decl

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

begin_decl_stmt
name|Address
name|CreateTempAlloca
argument_list|(
name|llvm
operator|::
name|Type
operator|*
name|Ty
argument_list|,
name|CharUnits
name|align
argument_list|,
specifier|const
name|Twine
operator|&
name|Name
operator|=
literal|"tmp"
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// CreateDefaultAlignedTempAlloca - This creates an alloca with the
end_comment

begin_comment
comment|/// default ABI alignment of the given LLVM type.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// IMPORTANT NOTE: This is *not* generally the right alignment for
end_comment

begin_comment
comment|/// any given AST type that happens to have been lowered to the
end_comment

begin_comment
comment|/// given IR type.  This should only ever be used for function-local,
end_comment

begin_comment
comment|/// IR-driven manipulations like saving and restoring a value.  Do
end_comment

begin_comment
comment|/// not hand this address off to arbitrary IRGen routines, and especially
end_comment

begin_comment
comment|/// do not pass it as an argument to a function that might expect a
end_comment

begin_comment
comment|/// properly ABI-aligned value.
end_comment

begin_decl_stmt
name|Address
name|CreateDefaultAlignTempAlloca
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
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// InitTempAlloca - Provide an initial value for the given alloca which
end_comment

begin_comment
comment|/// will be observable at all locations in the function.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// The address should be something that was returned from one of
end_comment

begin_comment
comment|/// the CreateTempAlloca or CreateMemTemp routines, and the
end_comment

begin_comment
comment|/// initializer must be valid in the entry block (i.e. it must
end_comment

begin_comment
comment|/// either be a constant or an argument value).
end_comment

begin_decl_stmt
name|void
name|InitTempAlloca
argument_list|(
name|Address
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

begin_comment
comment|///
end_comment

begin_comment
comment|/// That is, this is exactly equivalent to CreateMemTemp, but calling
end_comment

begin_comment
comment|/// ConvertType instead of ConvertTypeForMem.
end_comment

begin_function_decl
name|Address
name|CreateIRTemp
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
function_decl|;
end_function_decl

begin_comment
comment|/// CreateMemTemp - Create a temporary memory object of the given type, with
end_comment

begin_comment
comment|/// appropriate alignment.
end_comment

begin_function_decl
name|Address
name|CreateMemTemp
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
function_decl|;
end_function_decl

begin_function_decl
name|Address
name|CreateMemTemp
parameter_list|(
name|QualType
name|T
parameter_list|,
name|CharUnits
name|Align
parameter_list|,
specifier|const
name|Twine
modifier|&
name|Name
init|=
literal|"tmp"
parameter_list|)
function_decl|;
end_function_decl

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

begin_function_decl
name|Address
name|EmitVAListRef
parameter_list|(
specifier|const
name|Expr
modifier|*
name|E
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// Emit a "reference" to a __builtin_ms_va_list; this is
end_comment

begin_comment
comment|/// always the value of the expression, because a __builtin_ms_va_list is a
end_comment

begin_comment
comment|/// pointer to a char.
end_comment

begin_function_decl
name|Address
name|EmitMSVAListRef
parameter_list|(
specifier|const
name|Expr
modifier|*
name|E
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// EmitAnyExprToTemp - Similarly to EmitAnyExpr(), however, the result will
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

begin_function_decl
name|void
name|EmitAnyExprToMem
parameter_list|(
specifier|const
name|Expr
modifier|*
name|E
parameter_list|,
name|Address
name|Location
parameter_list|,
name|Qualifiers
name|Quals
parameter_list|,
name|bool
name|IsInitializer
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|EmitAnyExprToExn
parameter_list|(
specifier|const
name|Expr
modifier|*
name|E
parameter_list|,
name|Address
name|Addr
parameter_list|)
function_decl|;
end_function_decl

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

begin_function
name|void
name|EmitAggregateAssign
parameter_list|(
name|Address
name|DestPtr
parameter_list|,
name|Address
name|SrcPtr
parameter_list|,
name|QualType
name|EltTy
parameter_list|)
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
name|true
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
name|void
name|EmitAggregateCopyCtor
parameter_list|(
name|Address
name|DestPtr
parameter_list|,
name|Address
name|SrcPtr
parameter_list|,
name|QualType
name|DestTy
parameter_list|,
name|QualType
name|SrcTy
parameter_list|)
block|{
name|EmitAggregateCopy
argument_list|(
name|DestPtr
argument_list|,
name|SrcPtr
argument_list|,
name|SrcTy
argument_list|,
comment|/*IsVolatile=*/
name|false
argument_list|,
comment|/*IsAssignment=*/
name|false
argument_list|)
expr_stmt|;
block|}
end_function

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

begin_function_decl
name|void
name|EmitAggregateCopy
parameter_list|(
name|Address
name|DestPtr
parameter_list|,
name|Address
name|SrcPtr
parameter_list|,
name|QualType
name|EltTy
parameter_list|,
name|bool
name|isVolatile
init|=
name|false
parameter_list|,
name|bool
name|isAssignment
init|=
name|false
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// GetAddrOfLocalVar - Return the address of a local variable.
end_comment

begin_function
name|Address
name|GetAddrOfLocalVar
parameter_list|(
specifier|const
name|VarDecl
modifier|*
name|VD
parameter_list|)
block|{
name|auto
name|it
init|=
name|LocalDeclMap
operator|.
name|find
argument_list|(
name|VD
argument_list|)
decl_stmt|;
name|assert
argument_list|(
name|it
operator|!=
name|LocalDeclMap
operator|.
name|end
argument_list|()
operator|&&
literal|"Invalid argument to GetAddrOfLocalVar(), no decl!"
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
comment|/// Get the index of the current ArrayInitLoopExpr, if any.
end_comment

begin_expr_stmt
name|llvm
operator|::
name|Value
operator|*
name|getArrayInitIndex
argument_list|()
block|{
return|return
name|ArrayInitIndex
return|;
block|}
end_expr_stmt

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
comment|/// Check if \p E is a C++ "this" pointer wrapped in value-preserving casts.
end_comment

begin_function_decl
specifier|static
name|bool
name|IsWrappedCXXThis
parameter_list|(
specifier|const
name|Expr
modifier|*
name|E
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// EmitNullInitialization - Generate code to set a value of the given type to
end_comment

begin_comment
comment|/// null, If the type contains data member pointers, they will be initialized
end_comment

begin_comment
comment|/// to -1 in accordance with the Itanium C++ ABI.
end_comment

begin_function_decl
name|void
name|EmitNullInitialization
parameter_list|(
name|Address
name|DestPtr
parameter_list|,
name|QualType
name|Ty
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// Emits a call to an LLVM variable-argument intrinsic, either
end_comment

begin_comment
comment|/// \c llvm.va_start or \c llvm.va_end.
end_comment

begin_comment
comment|/// \param ArgValue A reference to the \c va_list as emitted by either
end_comment

begin_comment
comment|/// \c EmitVAListRef or \c EmitMSVAListRef.
end_comment

begin_comment
comment|/// \param IsStart If \c true, emits a call to \c llvm.va_start; otherwise,
end_comment

begin_comment
comment|/// calls \c llvm.va_end.
end_comment

begin_expr_stmt
name|llvm
operator|::
name|Value
operator|*
name|EmitVAStartEnd
argument_list|(
argument|llvm::Value *ArgValue
argument_list|,
argument|bool IsStart
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// Generate code to get an argument from the passed in pointer
end_comment

begin_comment
comment|/// and update it accordingly.
end_comment

begin_comment
comment|/// \param VE The \c VAArgExpr for which to generate code.
end_comment

begin_comment
comment|/// \param VAListAddr Receives a reference to the \c va_list as emitted by
end_comment

begin_comment
comment|/// either \c EmitVAListRef or \c EmitMSVAListRef.
end_comment

begin_comment
comment|/// \returns A pointer to the argument.
end_comment

begin_comment
comment|// FIXME: We should be able to get rid of this method and use the va_arg
end_comment

begin_comment
comment|// instruction in LLVM instead once it works well enough.
end_comment

begin_function_decl
name|Address
name|EmitVAArg
parameter_list|(
name|VAArgExpr
modifier|*
name|VE
parameter_list|,
name|Address
modifier|&
name|VAListAddr
parameter_list|)
function_decl|;
end_function_decl

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
name|Address
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

begin_function_decl
name|Address
name|LoadCXXThisAddress
parameter_list|()
function_decl|;
end_function_decl

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
comment|/// GetAddressOfBaseOfCompleteClass - Convert the given pointer to a
end_comment

begin_comment
comment|/// complete class to the given direct base.
end_comment

begin_function_decl
name|Address
name|GetAddressOfDirectBaseInCompleteClass
parameter_list|(
name|Address
name|Value
parameter_list|,
specifier|const
name|CXXRecordDecl
modifier|*
name|Derived
parameter_list|,
specifier|const
name|CXXRecordDecl
modifier|*
name|Base
parameter_list|,
name|bool
name|BaseIsVirtual
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|bool
name|ShouldNullCheckClassCastValue
parameter_list|(
specifier|const
name|CastExpr
modifier|*
name|Cast
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// GetAddressOfBaseClass - This function will add the necessary delta to the
end_comment

begin_comment
comment|/// load of 'this' and returns address of the base class.
end_comment

begin_decl_stmt
name|Address
name|GetAddressOfBaseClass
argument_list|(
name|Address
name|Value
argument_list|,
specifier|const
name|CXXRecordDecl
operator|*
name|Derived
argument_list|,
name|CastExpr
operator|::
name|path_const_iterator
name|PathBegin
argument_list|,
name|CastExpr
operator|::
name|path_const_iterator
name|PathEnd
argument_list|,
name|bool
name|NullCheckValue
argument_list|,
name|SourceLocation
name|Loc
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|Address
name|GetAddressOfDerivedClass
argument_list|(
name|Address
name|Value
argument_list|,
specifier|const
name|CXXRecordDecl
operator|*
name|Derived
argument_list|,
name|CastExpr
operator|::
name|path_const_iterator
name|PathBegin
argument_list|,
name|CastExpr
operator|::
name|path_const_iterator
name|PathEnd
argument_list|,
name|bool
name|NullCheckValue
argument_list|)
decl_stmt|;
end_decl_stmt

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

begin_comment
comment|/// Emit a call to an inheriting constructor (that is, one that invokes a
end_comment

begin_comment
comment|/// constructor inherited from a base class) by inlining its definition. This
end_comment

begin_comment
comment|/// is necessary if the ABI does not support forwarding the arguments to the
end_comment

begin_comment
comment|/// base class constructor (because they're variadic or similar).
end_comment

begin_function_decl
name|void
name|EmitInlinedInheritingCXXConstructorCall
parameter_list|(
specifier|const
name|CXXConstructorDecl
modifier|*
name|Ctor
parameter_list|,
name|CXXCtorType
name|CtorType
parameter_list|,
name|bool
name|ForVirtualBase
parameter_list|,
name|bool
name|Delegating
parameter_list|,
name|CallArgList
modifier|&
name|Args
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// Emit a call to a constructor inherited from a base class, passing the
end_comment

begin_comment
comment|/// current constructor's arguments along unmodified (without even making
end_comment

begin_comment
comment|/// a copy).
end_comment

begin_function_decl
name|void
name|EmitInheritedCXXConstructorCall
parameter_list|(
specifier|const
name|CXXConstructorDecl
modifier|*
name|D
parameter_list|,
name|bool
name|ForVirtualBase
parameter_list|,
name|Address
name|This
parameter_list|,
name|bool
name|InheritedFromVBase
parameter_list|,
specifier|const
name|CXXInheritedCtorInitExpr
modifier|*
name|E
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|EmitCXXConstructorCall
parameter_list|(
specifier|const
name|CXXConstructorDecl
modifier|*
name|D
parameter_list|,
name|CXXCtorType
name|Type
parameter_list|,
name|bool
name|ForVirtualBase
parameter_list|,
name|bool
name|Delegating
parameter_list|,
name|Address
name|This
parameter_list|,
specifier|const
name|CXXConstructExpr
modifier|*
name|E
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|EmitCXXConstructorCall
parameter_list|(
specifier|const
name|CXXConstructorDecl
modifier|*
name|D
parameter_list|,
name|CXXCtorType
name|Type
parameter_list|,
name|bool
name|ForVirtualBase
parameter_list|,
name|bool
name|Delegating
parameter_list|,
name|Address
name|This
parameter_list|,
name|CallArgList
modifier|&
name|Args
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// Emit assumption load for all bases. Requires to be be called only on
end_comment

begin_comment
comment|/// most-derived class and not under construction of the object.
end_comment

begin_function_decl
name|void
name|EmitVTableAssumptionLoads
parameter_list|(
specifier|const
name|CXXRecordDecl
modifier|*
name|ClassDecl
parameter_list|,
name|Address
name|This
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// Emit assumption that vptr load == global vtable.
end_comment

begin_function_decl
name|void
name|EmitVTableAssumptionLoad
parameter_list|(
specifier|const
name|VPtr
modifier|&
name|vptr
parameter_list|,
name|Address
name|This
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|EmitSynthesizedCXXCopyCtorCall
parameter_list|(
specifier|const
name|CXXConstructorDecl
modifier|*
name|D
parameter_list|,
name|Address
name|This
parameter_list|,
name|Address
name|Src
parameter_list|,
specifier|const
name|CXXConstructExpr
modifier|*
name|E
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|EmitCXXAggrConstructorCall
parameter_list|(
specifier|const
name|CXXConstructorDecl
modifier|*
name|D
parameter_list|,
specifier|const
name|ArrayType
modifier|*
name|ArrayTy
parameter_list|,
name|Address
name|ArrayPtr
parameter_list|,
specifier|const
name|CXXConstructExpr
modifier|*
name|E
parameter_list|,
name|bool
name|ZeroInitialization
init|=
name|false
parameter_list|)
function_decl|;
end_function_decl

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
name|Address
name|ArrayPtr
argument_list|,
specifier|const
name|CXXConstructExpr
operator|*
name|E
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

begin_function_decl
name|void
name|EmitCXXDestructorCall
parameter_list|(
specifier|const
name|CXXDestructorDecl
modifier|*
name|D
parameter_list|,
name|CXXDtorType
name|Type
parameter_list|,
name|bool
name|ForVirtualBase
parameter_list|,
name|bool
name|Delegating
parameter_list|,
name|Address
name|This
parameter_list|)
function_decl|;
end_function_decl

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
name|Type
operator|*
name|ElementTy
argument_list|,
name|Address
name|NewPtr
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
name|AllocSizeWithoutCookie
argument_list|)
decl_stmt|;
end_decl_stmt

begin_function_decl
name|void
name|EmitCXXTemporary
parameter_list|(
specifier|const
name|CXXTemporary
modifier|*
name|Temporary
parameter_list|,
name|QualType
name|TempType
parameter_list|,
name|Address
name|Ptr
parameter_list|)
function_decl|;
end_function_decl

begin_expr_stmt
name|llvm
operator|::
name|Value
operator|*
name|EmitLifetimeStart
argument_list|(
argument|uint64_t Size
argument_list|,
argument|llvm::Value *Addr
argument_list|)
expr_stmt|;
end_expr_stmt

begin_decl_stmt
name|void
name|EmitLifetimeEnd
argument_list|(
name|llvm
operator|::
name|Value
operator|*
name|Size
argument_list|,
name|llvm
operator|::
name|Value
operator|*
name|Addr
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
argument_list|,
name|llvm
operator|::
name|Value
operator|*
name|NumElements
operator|=
name|nullptr
argument_list|,
name|CharUnits
name|CookieSize
operator|=
name|CharUnits
argument_list|()
argument_list|)
decl_stmt|;
end_decl_stmt

begin_function_decl
name|RValue
name|EmitBuiltinNewDeleteCall
parameter_list|(
specifier|const
name|FunctionProtoType
modifier|*
name|Type
parameter_list|,
specifier|const
name|Expr
modifier|*
name|Arg
parameter_list|,
name|bool
name|IsDelete
parameter_list|)
function_decl|;
end_function_decl

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
argument|Address V
argument_list|,
argument|const CXXDynamicCastExpr *DCE
argument_list|)
expr_stmt|;
end_expr_stmt

begin_function_decl
name|Address
name|EmitCXXUuidofExpr
parameter_list|(
specifier|const
name|CXXUuidofExpr
modifier|*
name|E
parameter_list|)
function_decl|;
end_function_decl

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
block|,
comment|/// Checking the operand of a cast to a base object. Must be suitably sized
comment|/// and aligned.
name|TCK_Upcast
block|,
comment|/// Checking the operand of a cast to a virtual base object. Must be an
comment|/// object within its lifetime.
name|TCK_UpcastToVirtualBase
block|,
comment|/// Checking the value assigned to a _Nonnull pointer. Must not be null.
name|TCK_NonnullAssign
block|}
enum|;
end_enum

begin_comment
comment|/// \brief Whether any type-checking sanitizers are enabled. If \c false,
end_comment

begin_comment
comment|/// calls to EmitTypeCheck can be skipped.
end_comment

begin_expr_stmt
name|bool
name|sanitizePerformTypeCheck
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt

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
argument_list|,
name|SanitizerSet
name|SkippedChecks
operator|=
name|SanitizerSet
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

begin_decl_stmt
name|void
name|EmitAlignmentAssumption
argument_list|(
name|llvm
operator|::
name|Value
operator|*
name|PtrValue
argument_list|,
name|unsigned
name|Alignment
argument_list|,
name|llvm
operator|::
name|Value
operator|*
name|OffsetValue
operator|=
name|nullptr
argument_list|)
block|{
name|Builder
operator|.
name|CreateAlignmentAssumption
argument_list|(
name|CGM
operator|.
name|getDataLayout
argument_list|()
argument_list|,
name|PtrValue
argument_list|,
name|Alignment
argument_list|,
name|OffsetValue
argument_list|)
expr_stmt|;
block|}
end_decl_stmt

begin_comment
comment|/// Converts Location to a DebugLoc, if debug information is enabled.
end_comment

begin_expr_stmt
name|llvm
operator|::
name|DebugLoc
name|SourceLocToDebugLoc
argument_list|(
argument|SourceLocation Location
argument_list|)
expr_stmt|;
end_expr_stmt

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
comment|/// \brief Determine whether the given initializer is trivial in the sense
end_comment

begin_comment
comment|/// that it requires no code to be generated.
end_comment

begin_function_decl
name|bool
name|isTrivialInitializer
parameter_list|(
specifier|const
name|Expr
modifier|*
name|Init
parameter_list|)
function_decl|;
end_function_decl

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
comment|/// The address of the alloca.  Invalid if the variable was emitted
comment|/// as a global constant.
name|Address
name|Addr
decl_stmt|;
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
name|nullptr
argument_list|)
operator|,
name|Addr
argument_list|(
argument|Address::invalid()
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
name|Addr
argument_list|(
name|Address
operator|::
name|invalid
argument_list|()
argument_list|)
operator|,
name|NRVOFlag
argument_list|(
name|nullptr
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
argument|nullptr
argument_list|)
block|{}
name|bool
name|wasEmittedAsGlobal
argument_list|()
specifier|const
block|{
return|return
operator|!
name|Addr
operator|.
name|isValid
argument_list|()
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
name|nullptr
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
name|Address
name|getAllocatedAddress
argument_list|()
specifier|const
block|{
return|return
name|Addr
return|;
block|}
comment|/// Returns the address of the object within this declaration.
comment|/// Note that this does not chase the forwarding pointer for
comment|/// __block decls.
name|Address
name|getObjectAddress
argument_list|(
name|CodeGenFunction
operator|&
name|CGF
argument_list|)
decl|const
block|{
if|if
condition|(
operator|!
name|IsByRef
condition|)
return|return
name|Addr
return|;
return|return
name|CGF
operator|.
name|emitBlockByrefAddress
argument_list|(
name|Addr
argument_list|,
name|Variable
argument_list|,
comment|/*forward*/
name|false
argument_list|)
return|;
block|}
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_function_decl
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

begin_decl_stmt
name|class
name|ParamValue
block|{
name|llvm
operator|::
name|Value
operator|*
name|Value
expr_stmt|;
name|unsigned
name|Alignment
decl_stmt|;
name|ParamValue
argument_list|(
argument|llvm::Value *V
argument_list|,
argument|unsigned A
argument_list|)
block|:
name|Value
argument_list|(
name|V
argument_list|)
operator|,
name|Alignment
argument_list|(
argument|A
argument_list|)
block|{}
name|public
operator|:
specifier|static
name|ParamValue
name|forDirect
argument_list|(
argument|llvm::Value *value
argument_list|)
block|{
return|return
name|ParamValue
argument_list|(
name|value
argument_list|,
literal|0
argument_list|)
return|;
block|}
specifier|static
name|ParamValue
name|forIndirect
parameter_list|(
name|Address
name|addr
parameter_list|)
block|{
name|assert
argument_list|(
operator|!
name|addr
operator|.
name|getAlignment
argument_list|()
operator|.
name|isZero
argument_list|()
argument_list|)
expr_stmt|;
return|return
name|ParamValue
argument_list|(
name|addr
operator|.
name|getPointer
argument_list|()
argument_list|,
name|addr
operator|.
name|getAlignment
argument_list|()
operator|.
name|getQuantity
argument_list|()
argument_list|)
return|;
block|}
name|bool
name|isIndirect
argument_list|()
specifier|const
block|{
return|return
name|Alignment
operator|!=
literal|0
return|;
block|}
name|llvm
operator|::
name|Value
operator|*
name|getAnyValue
argument_list|()
specifier|const
block|{
return|return
name|Value
return|;
block|}
name|llvm
operator|::
name|Value
operator|*
name|getDirectValue
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
operator|!
name|isIndirect
argument_list|()
argument_list|)
block|;
return|return
name|Value
return|;
block|}
name|Address
name|getIndirectAddress
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
name|isIndirect
argument_list|()
argument_list|)
block|;
return|return
name|Address
argument_list|(
name|Value
argument_list|,
name|CharUnits
operator|::
name|fromQuantity
argument_list|(
name|Alignment
argument_list|)
argument_list|)
return|;
block|}
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|/// EmitParmDecl - Emit a ParmVarDecl or an ImplicitParamDecl.
end_comment

begin_function_decl
name|void
name|EmitParmDecl
parameter_list|(
specifier|const
name|VarDecl
modifier|&
name|D
parameter_list|,
name|ParamValue
name|Arg
parameter_list|,
name|unsigned
name|ArgNo
parameter_list|)
function_decl|;
end_function_decl

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

begin_decl_stmt
name|void
name|EmitAlignmentAssumption
argument_list|(
name|llvm
operator|::
name|Value
operator|*
name|PtrValue
argument_list|,
name|llvm
operator|::
name|Value
operator|*
name|Alignment
argument_list|,
name|llvm
operator|::
name|Value
operator|*
name|OffsetValue
operator|=
name|nullptr
argument_list|)
block|{
name|Builder
operator|.
name|CreateAlignmentAssumption
argument_list|(
name|CGM
operator|.
name|getDataLayout
argument_list|()
argument_list|,
name|PtrValue
argument_list|,
name|Alignment
argument_list|,
name|OffsetValue
argument_list|)
expr_stmt|;
block|}
end_decl_stmt

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

begin_function_decl
name|Address
name|EmitCompoundStmt
parameter_list|(
specifier|const
name|CompoundStmt
modifier|&
name|S
parameter_list|,
name|bool
name|GetLast
init|=
name|false
parameter_list|,
name|AggValueSlot
name|AVS
init|=
name|AggValueSlot
operator|::
name|ignored
argument_list|()
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|Address
name|EmitCompoundStmtWithoutScope
parameter_list|(
specifier|const
name|CompoundStmt
modifier|&
name|S
parameter_list|,
name|bool
name|GetLast
init|=
name|false
parameter_list|,
name|AggValueSlot
name|AVS
init|=
name|AggValueSlot
operator|::
name|ignored
argument_list|()
parameter_list|)
function_decl|;
end_function_decl

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

begin_decl_stmt
name|void
name|EmitWhileStmt
argument_list|(
specifier|const
name|WhileStmt
operator|&
name|S
argument_list|,
name|ArrayRef
operator|<
specifier|const
name|Attr
operator|*
operator|>
name|Attrs
operator|=
name|None
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|EmitDoStmt
argument_list|(
specifier|const
name|DoStmt
operator|&
name|S
argument_list|,
name|ArrayRef
operator|<
specifier|const
name|Attr
operator|*
operator|>
name|Attrs
operator|=
name|None
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|EmitForStmt
argument_list|(
specifier|const
name|ForStmt
operator|&
name|S
argument_list|,
name|ArrayRef
operator|<
specifier|const
name|Attr
operator|*
operator|>
name|Attrs
operator|=
name|None
argument_list|)
decl_stmt|;
end_decl_stmt

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

begin_function_decl
name|void
name|EmitCoroutineBody
parameter_list|(
specifier|const
name|CoroutineBodyStmt
modifier|&
name|S
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|EmitCoreturnStmt
parameter_list|(
specifier|const
name|CoreturnStmt
modifier|&
name|S
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|RValue
name|EmitCoawaitExpr
parameter_list|(
specifier|const
name|CoawaitExpr
modifier|&
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

begin_function_decl
name|RValue
name|EmitCoyieldExpr
parameter_list|(
specifier|const
name|CoyieldExpr
modifier|&
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

begin_function_decl
name|RValue
name|EmitCoroutineIntrinsic
parameter_list|(
specifier|const
name|CallExpr
modifier|*
name|E
parameter_list|,
name|unsigned
name|int
name|IID
parameter_list|)
function_decl|;
end_function_decl

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
name|EmitSEHLeaveStmt
parameter_list|(
specifier|const
name|SEHLeaveStmt
modifier|&
name|S
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|EnterSEHTryStmt
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
name|ExitSEHTryStmt
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
name|startOutlinedSEHHelper
parameter_list|(
name|CodeGenFunction
modifier|&
name|ParentCGF
parameter_list|,
name|bool
name|IsFilter
parameter_list|,
specifier|const
name|Stmt
modifier|*
name|OutlinedStmt
parameter_list|)
function_decl|;
end_function_decl

begin_expr_stmt
name|llvm
operator|::
name|Function
operator|*
name|GenerateSEHFilterFunction
argument_list|(
name|CodeGenFunction
operator|&
name|ParentCGF
argument_list|,
specifier|const
name|SEHExceptStmt
operator|&
name|Except
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|llvm
operator|::
name|Function
operator|*
name|GenerateSEHFinallyFunction
argument_list|(
name|CodeGenFunction
operator|&
name|ParentCGF
argument_list|,
specifier|const
name|SEHFinallyStmt
operator|&
name|Finally
argument_list|)
expr_stmt|;
end_expr_stmt

begin_decl_stmt
name|void
name|EmitSEHExceptionCodeSave
argument_list|(
name|CodeGenFunction
operator|&
name|ParentCGF
argument_list|,
name|llvm
operator|::
name|Value
operator|*
name|ParentFP
argument_list|,
name|llvm
operator|::
name|Value
operator|*
name|EntryEBP
argument_list|)
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|llvm
operator|::
name|Value
operator|*
name|EmitSEHExceptionCode
argument_list|()
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|llvm
operator|::
name|Value
operator|*
name|EmitSEHExceptionInfo
argument_list|()
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|llvm
operator|::
name|Value
operator|*
name|EmitSEHAbnormalTermination
argument_list|()
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// Scan the outlined statement for captures from the parent function. For
end_comment

begin_comment
comment|/// each capture, mark the capture as escaped and emit a call to
end_comment

begin_comment
comment|/// llvm.localrecover. Insert the localrecover result into the LocalDeclMap.
end_comment

begin_function_decl
name|void
name|EmitCapturedLocals
parameter_list|(
name|CodeGenFunction
modifier|&
name|ParentCGF
parameter_list|,
specifier|const
name|Stmt
modifier|*
name|OutlinedStmt
parameter_list|,
name|bool
name|IsFilter
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// Recovers the address of a local in a parent function. ParentVar is the
end_comment

begin_comment
comment|/// address of the variable used in the immediate parent function. It can
end_comment

begin_comment
comment|/// either be an alloca or a call to llvm.localrecover if there are nested
end_comment

begin_comment
comment|/// outlined functions. ParentFP is the frame pointer of the outermost parent
end_comment

begin_comment
comment|/// frame.
end_comment

begin_decl_stmt
name|Address
name|recoverAddrOfEscapedLocal
argument_list|(
name|CodeGenFunction
operator|&
name|ParentCGF
argument_list|,
name|Address
name|ParentVar
argument_list|,
name|llvm
operator|::
name|Value
operator|*
name|ParentFP
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|EmitCXXForRangeStmt
argument_list|(
specifier|const
name|CXXForRangeStmt
operator|&
name|S
argument_list|,
name|ArrayRef
operator|<
specifier|const
name|Attr
operator|*
operator|>
name|Attrs
operator|=
name|None
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// Returns calculated size of the specified type.
end_comment

begin_expr_stmt
name|llvm
operator|::
name|Value
operator|*
name|getTypeSize
argument_list|(
argument|QualType Ty
argument_list|)
expr_stmt|;
end_expr_stmt

begin_function_decl
name|LValue
name|InitCapturedStruct
parameter_list|(
specifier|const
name|CapturedStmt
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
specifier|const
name|CapturedStmt
operator|&
name|S
argument_list|)
expr_stmt|;
end_expr_stmt

begin_function_decl
name|Address
name|GenerateCapturedStmtArgument
parameter_list|(
specifier|const
name|CapturedStmt
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
name|GenerateOpenMPCapturedStmtFunction
argument_list|(
specifier|const
name|CapturedStmt
operator|&
name|S
argument_list|)
expr_stmt|;
end_expr_stmt

begin_decl_stmt
name|void
name|GenerateOpenMPCapturedVars
argument_list|(
specifier|const
name|CapturedStmt
operator|&
name|S
argument_list|,
name|SmallVectorImpl
operator|<
name|llvm
operator|::
name|Value
operator|*
operator|>
operator|&
name|CapturedVars
argument_list|)
decl_stmt|;
end_decl_stmt

begin_function_decl
name|void
name|emitOMPSimpleStore
parameter_list|(
name|LValue
name|LVal
parameter_list|,
name|RValue
name|RVal
parameter_list|,
name|QualType
name|RValTy
parameter_list|,
name|SourceLocation
name|Loc
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// \brief Perform element by element copying of arrays with type \a
end_comment

begin_comment
comment|/// OriginalType from \a SrcAddr to \a DestAddr using copying procedure
end_comment

begin_comment
comment|/// generated by \a CopyGen.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param DestAddr Address of the destination array.
end_comment

begin_comment
comment|/// \param SrcAddr Address of the source array.
end_comment

begin_comment
comment|/// \param OriginalType Type of destination and source arrays.
end_comment

begin_comment
comment|/// \param CopyGen Copying procedure that copies value of single array element
end_comment

begin_comment
comment|/// to another single array element.
end_comment

begin_decl_stmt
name|void
name|EmitOMPAggregateAssign
argument_list|(
name|Address
name|DestAddr
argument_list|,
name|Address
name|SrcAddr
argument_list|,
name|QualType
name|OriginalType
argument_list|,
specifier|const
name|llvm
operator|::
name|function_ref
operator|<
name|void
argument_list|(
name|Address
argument_list|,
name|Address
argument_list|)
operator|>
operator|&
name|CopyGen
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// \brief Emit proper copying of data from one variable to another.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param OriginalType Original type of the copied variables.
end_comment

begin_comment
comment|/// \param DestAddr Destination address.
end_comment

begin_comment
comment|/// \param SrcAddr Source address.
end_comment

begin_comment
comment|/// \param DestVD Destination variable used in \a CopyExpr (for arrays, has
end_comment

begin_comment
comment|/// type of the base array element).
end_comment

begin_comment
comment|/// \param SrcVD Source variable used in \a CopyExpr (for arrays, has type of
end_comment

begin_comment
comment|/// the base array element).
end_comment

begin_comment
comment|/// \param Copy Actual copygin expression for copying data from \a SrcVD to \a
end_comment

begin_comment
comment|/// DestVD.
end_comment

begin_function_decl
name|void
name|EmitOMPCopy
parameter_list|(
name|QualType
name|OriginalType
parameter_list|,
name|Address
name|DestAddr
parameter_list|,
name|Address
name|SrcAddr
parameter_list|,
specifier|const
name|VarDecl
modifier|*
name|DestVD
parameter_list|,
specifier|const
name|VarDecl
modifier|*
name|SrcVD
parameter_list|,
specifier|const
name|Expr
modifier|*
name|Copy
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// \brief Emit atomic update code for constructs: \a X = \a X \a BO \a E or
end_comment

begin_comment
comment|/// \a X = \a E \a BO \a E.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param X Value to be updated.
end_comment

begin_comment
comment|/// \param E Update value.
end_comment

begin_comment
comment|/// \param BO Binary operation for update operation.
end_comment

begin_comment
comment|/// \param IsXLHSInRHSPart true if \a X is LHS in RHS part of the update
end_comment

begin_comment
comment|/// expression, false otherwise.
end_comment

begin_comment
comment|/// \param AO Atomic ordering of the generated atomic instructions.
end_comment

begin_comment
comment|/// \param CommonGen Code generator for complex expressions that cannot be
end_comment

begin_comment
comment|/// expressed through atomicrmw instruction.
end_comment

begin_comment
comment|/// \returns<true, OldAtomicValue> if simple 'atomicrmw' instruction was
end_comment

begin_comment
comment|/// generated,<false, RValue::get(nullptr)> otherwise.
end_comment

begin_expr_stmt
name|std
operator|::
name|pair
operator|<
name|bool
operator|,
name|RValue
operator|>
name|EmitOMPAtomicSimpleUpdateExpr
argument_list|(
argument|LValue X
argument_list|,
argument|RValue E
argument_list|,
argument|BinaryOperatorKind BO
argument_list|,
argument|bool IsXLHSInRHSPart
argument_list|,
argument|llvm::AtomicOrdering AO
argument_list|,
argument|SourceLocation Loc
argument_list|,
argument|const llvm::function_ref<RValue(RValue)>&CommonGen
argument_list|)
expr_stmt|;
end_expr_stmt

begin_function_decl
name|bool
name|EmitOMPFirstprivateClause
parameter_list|(
specifier|const
name|OMPExecutableDirective
modifier|&
name|D
parameter_list|,
name|OMPPrivateScope
modifier|&
name|PrivateScope
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|EmitOMPPrivateClause
parameter_list|(
specifier|const
name|OMPExecutableDirective
modifier|&
name|D
parameter_list|,
name|OMPPrivateScope
modifier|&
name|PrivateScope
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
name|void
name|EmitOMPUseDevicePtrClause
argument_list|(
specifier|const
name|OMPClause
operator|&
name|C
argument_list|,
name|OMPPrivateScope
operator|&
name|PrivateScope
argument_list|,
specifier|const
name|llvm
operator|::
name|DenseMap
operator|<
specifier|const
name|ValueDecl
operator|*
argument_list|,
name|Address
operator|>
operator|&
name|CaptureDeviceAddrMap
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// \brief Emit code for copyin clause in \a D directive. The next code is
end_comment

begin_comment
comment|/// generated at the start of outlined functions for directives:
end_comment

begin_comment
comment|/// \code
end_comment

begin_comment
comment|/// threadprivate_var1 = master_threadprivate_var1;
end_comment

begin_comment
comment|/// operator=(threadprivate_var2, master_threadprivate_var2);
end_comment

begin_comment
comment|/// ...
end_comment

begin_comment
comment|/// __kmpc_barrier(&loc, global_tid);
end_comment

begin_comment
comment|/// \endcode
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param D OpenMP directive possibly with 'copyin' clause(s).
end_comment

begin_comment
comment|/// \returns true if at least one copyin variable is found, false otherwise.
end_comment

begin_function_decl
name|bool
name|EmitOMPCopyinClause
parameter_list|(
specifier|const
name|OMPExecutableDirective
modifier|&
name|D
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// \brief Emit initial code for lastprivate variables. If some variable is
end_comment

begin_comment
comment|/// not also firstprivate, then the default initialization is used. Otherwise
end_comment

begin_comment
comment|/// initialization of this variable is performed by EmitOMPFirstprivateClause
end_comment

begin_comment
comment|/// method.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param D Directive that may have 'lastprivate' directives.
end_comment

begin_comment
comment|/// \param PrivateScope Private scope for capturing lastprivate variables for
end_comment

begin_comment
comment|/// proper codegen in internal captured statement.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \returns true if there is at least one lastprivate variable, false
end_comment

begin_comment
comment|/// otherwise.
end_comment

begin_function_decl
name|bool
name|EmitOMPLastprivateClauseInit
parameter_list|(
specifier|const
name|OMPExecutableDirective
modifier|&
name|D
parameter_list|,
name|OMPPrivateScope
modifier|&
name|PrivateScope
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// \brief Emit final copying of lastprivate values to original variables at
end_comment

begin_comment
comment|/// the end of the worksharing or simd directive.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param D Directive that has at least one 'lastprivate' directives.
end_comment

begin_comment
comment|/// \param IsLastIterCond Boolean condition that must be set to 'i1 true' if
end_comment

begin_comment
comment|/// it is the last iteration of the loop code in associated directive, or to
end_comment

begin_comment
comment|/// 'i1 false' otherwise. If this item is nullptr, no final check is required.
end_comment

begin_decl_stmt
name|void
name|EmitOMPLastprivateClauseFinal
argument_list|(
specifier|const
name|OMPExecutableDirective
operator|&
name|D
argument_list|,
name|bool
name|NoFinals
argument_list|,
name|llvm
operator|::
name|Value
operator|*
name|IsLastIterCond
operator|=
name|nullptr
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// Emit initial code for linear clauses.
end_comment

begin_decl_stmt
name|void
name|EmitOMPLinearClause
argument_list|(
specifier|const
name|OMPLoopDirective
operator|&
name|D
argument_list|,
name|CodeGenFunction
operator|::
name|OMPPrivateScope
operator|&
name|PrivateScope
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// Emit final code for linear clauses.
end_comment

begin_comment
comment|/// \param CondGen Optional conditional code for final part of codegen for
end_comment

begin_comment
comment|/// linear clause.
end_comment

begin_decl_stmt
name|void
name|EmitOMPLinearClauseFinal
argument_list|(
specifier|const
name|OMPLoopDirective
operator|&
name|D
argument_list|,
specifier|const
name|llvm
operator|::
name|function_ref
operator|<
name|llvm
operator|::
name|Value
operator|*
operator|(
name|CodeGenFunction
operator|&
operator|)
operator|>
operator|&
name|CondGen
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// \brief Emit initial code for reduction variables. Creates reduction copies
end_comment

begin_comment
comment|/// and initializes them with the values according to OpenMP standard.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param D Directive (possibly) with the 'reduction' clause.
end_comment

begin_comment
comment|/// \param PrivateScope Private scope for capturing reduction variables for
end_comment

begin_comment
comment|/// proper codegen in internal captured statement.
end_comment

begin_comment
comment|///
end_comment

begin_function_decl
name|void
name|EmitOMPReductionClauseInit
parameter_list|(
specifier|const
name|OMPExecutableDirective
modifier|&
name|D
parameter_list|,
name|OMPPrivateScope
modifier|&
name|PrivateScope
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// \brief Emit final update of reduction values to original variables at
end_comment

begin_comment
comment|/// the end of the directive.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param D Directive that has at least one 'reduction' directives.
end_comment

begin_comment
comment|/// \param ReductionKind The kind of reduction to perform.
end_comment

begin_function_decl
name|void
name|EmitOMPReductionClauseFinal
parameter_list|(
specifier|const
name|OMPExecutableDirective
modifier|&
name|D
parameter_list|,
specifier|const
name|OpenMPDirectiveKind
name|ReductionKind
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// \brief Emit initial code for linear variables. Creates private copies
end_comment

begin_comment
comment|/// and initializes them with the values according to OpenMP standard.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param D Directive (possibly) with the 'linear' clause.
end_comment

begin_function_decl
name|void
name|EmitOMPLinearClauseInit
parameter_list|(
specifier|const
name|OMPLoopDirective
modifier|&
name|D
parameter_list|)
function_decl|;
end_function_decl

begin_typedef
typedef|typedef
specifier|const
name|llvm
operator|::
name|function_ref
operator|<
name|void
argument_list|(
name|CodeGenFunction
operator|&
comment|/*CGF*/
argument_list|,
name|llvm
operator|::
name|Value
operator|*
comment|/*OutlinedFn*/
argument_list|,
specifier|const
name|OMPTaskDataTy
operator|&
comment|/*Data*/
argument_list|)
operator|>
name|TaskGenTy
expr_stmt|;
end_typedef

begin_function_decl
name|void
name|EmitOMPTaskBasedDirective
parameter_list|(
specifier|const
name|OMPExecutableDirective
modifier|&
name|S
parameter_list|,
specifier|const
name|RegionCodeGenTy
modifier|&
name|BodyGen
parameter_list|,
specifier|const
name|TaskGenTy
modifier|&
name|TaskGen
parameter_list|,
name|OMPTaskDataTy
modifier|&
name|Data
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|EmitOMPParallelDirective
parameter_list|(
specifier|const
name|OMPParallelDirective
modifier|&
name|S
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|EmitOMPSimdDirective
parameter_list|(
specifier|const
name|OMPSimdDirective
modifier|&
name|S
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|EmitOMPForDirective
parameter_list|(
specifier|const
name|OMPForDirective
modifier|&
name|S
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|EmitOMPForSimdDirective
parameter_list|(
specifier|const
name|OMPForSimdDirective
modifier|&
name|S
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|EmitOMPSectionsDirective
parameter_list|(
specifier|const
name|OMPSectionsDirective
modifier|&
name|S
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|EmitOMPSectionDirective
parameter_list|(
specifier|const
name|OMPSectionDirective
modifier|&
name|S
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|EmitOMPSingleDirective
parameter_list|(
specifier|const
name|OMPSingleDirective
modifier|&
name|S
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|EmitOMPMasterDirective
parameter_list|(
specifier|const
name|OMPMasterDirective
modifier|&
name|S
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|EmitOMPCriticalDirective
parameter_list|(
specifier|const
name|OMPCriticalDirective
modifier|&
name|S
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|EmitOMPParallelForDirective
parameter_list|(
specifier|const
name|OMPParallelForDirective
modifier|&
name|S
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|EmitOMPParallelForSimdDirective
parameter_list|(
specifier|const
name|OMPParallelForSimdDirective
modifier|&
name|S
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|EmitOMPParallelSectionsDirective
parameter_list|(
specifier|const
name|OMPParallelSectionsDirective
modifier|&
name|S
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|EmitOMPTaskDirective
parameter_list|(
specifier|const
name|OMPTaskDirective
modifier|&
name|S
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|EmitOMPTaskyieldDirective
parameter_list|(
specifier|const
name|OMPTaskyieldDirective
modifier|&
name|S
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|EmitOMPBarrierDirective
parameter_list|(
specifier|const
name|OMPBarrierDirective
modifier|&
name|S
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|EmitOMPTaskwaitDirective
parameter_list|(
specifier|const
name|OMPTaskwaitDirective
modifier|&
name|S
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|EmitOMPTaskgroupDirective
parameter_list|(
specifier|const
name|OMPTaskgroupDirective
modifier|&
name|S
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|EmitOMPFlushDirective
parameter_list|(
specifier|const
name|OMPFlushDirective
modifier|&
name|S
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|EmitOMPOrderedDirective
parameter_list|(
specifier|const
name|OMPOrderedDirective
modifier|&
name|S
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|EmitOMPAtomicDirective
parameter_list|(
specifier|const
name|OMPAtomicDirective
modifier|&
name|S
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|EmitOMPTargetDirective
parameter_list|(
specifier|const
name|OMPTargetDirective
modifier|&
name|S
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|EmitOMPTargetDataDirective
parameter_list|(
specifier|const
name|OMPTargetDataDirective
modifier|&
name|S
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|EmitOMPTargetEnterDataDirective
parameter_list|(
specifier|const
name|OMPTargetEnterDataDirective
modifier|&
name|S
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|EmitOMPTargetExitDataDirective
parameter_list|(
specifier|const
name|OMPTargetExitDataDirective
modifier|&
name|S
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|EmitOMPTargetUpdateDirective
parameter_list|(
specifier|const
name|OMPTargetUpdateDirective
modifier|&
name|S
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|EmitOMPTargetParallelDirective
parameter_list|(
specifier|const
name|OMPTargetParallelDirective
modifier|&
name|S
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|EmitOMPTargetParallelForDirective
parameter_list|(
specifier|const
name|OMPTargetParallelForDirective
modifier|&
name|S
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|EmitOMPTeamsDirective
parameter_list|(
specifier|const
name|OMPTeamsDirective
modifier|&
name|S
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|EmitOMPCancellationPointDirective
parameter_list|(
specifier|const
name|OMPCancellationPointDirective
modifier|&
name|S
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|EmitOMPCancelDirective
parameter_list|(
specifier|const
name|OMPCancelDirective
modifier|&
name|S
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|EmitOMPTaskLoopBasedDirective
parameter_list|(
specifier|const
name|OMPLoopDirective
modifier|&
name|S
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|EmitOMPTaskLoopDirective
parameter_list|(
specifier|const
name|OMPTaskLoopDirective
modifier|&
name|S
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|EmitOMPTaskLoopSimdDirective
parameter_list|(
specifier|const
name|OMPTaskLoopSimdDirective
modifier|&
name|S
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|EmitOMPDistributeDirective
parameter_list|(
specifier|const
name|OMPDistributeDirective
modifier|&
name|S
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|EmitOMPDistributeParallelForDirective
parameter_list|(
specifier|const
name|OMPDistributeParallelForDirective
modifier|&
name|S
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|EmitOMPDistributeParallelForSimdDirective
parameter_list|(
specifier|const
name|OMPDistributeParallelForSimdDirective
modifier|&
name|S
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|EmitOMPDistributeSimdDirective
parameter_list|(
specifier|const
name|OMPDistributeSimdDirective
modifier|&
name|S
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|EmitOMPTargetParallelForSimdDirective
parameter_list|(
specifier|const
name|OMPTargetParallelForSimdDirective
modifier|&
name|S
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|EmitOMPTargetSimdDirective
parameter_list|(
specifier|const
name|OMPTargetSimdDirective
modifier|&
name|S
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|EmitOMPTeamsDistributeDirective
parameter_list|(
specifier|const
name|OMPTeamsDistributeDirective
modifier|&
name|S
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|EmitOMPTeamsDistributeSimdDirective
parameter_list|(
specifier|const
name|OMPTeamsDistributeSimdDirective
modifier|&
name|S
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|EmitOMPTeamsDistributeParallelForSimdDirective
parameter_list|(
specifier|const
name|OMPTeamsDistributeParallelForSimdDirective
modifier|&
name|S
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|EmitOMPTeamsDistributeParallelForDirective
parameter_list|(
specifier|const
name|OMPTeamsDistributeParallelForDirective
modifier|&
name|S
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|EmitOMPTargetTeamsDirective
parameter_list|(
specifier|const
name|OMPTargetTeamsDirective
modifier|&
name|S
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|EmitOMPTargetTeamsDistributeDirective
parameter_list|(
specifier|const
name|OMPTargetTeamsDistributeDirective
modifier|&
name|S
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|EmitOMPTargetTeamsDistributeParallelForDirective
parameter_list|(
specifier|const
name|OMPTargetTeamsDistributeParallelForDirective
modifier|&
name|S
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|EmitOMPTargetTeamsDistributeParallelForSimdDirective
parameter_list|(
specifier|const
name|OMPTargetTeamsDistributeParallelForSimdDirective
modifier|&
name|S
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|EmitOMPTargetTeamsDistributeSimdDirective
parameter_list|(
specifier|const
name|OMPTargetTeamsDistributeSimdDirective
modifier|&
name|S
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// Emit device code for the target directive.
end_comment

begin_function_decl
specifier|static
name|void
name|EmitOMPTargetDeviceFunction
parameter_list|(
name|CodeGenModule
modifier|&
name|CGM
parameter_list|,
name|StringRef
name|ParentName
parameter_list|,
specifier|const
name|OMPTargetDirective
modifier|&
name|S
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|void
name|EmitOMPTargetParallelDeviceFunction
parameter_list|(
name|CodeGenModule
modifier|&
name|CGM
parameter_list|,
name|StringRef
name|ParentName
parameter_list|,
specifier|const
name|OMPTargetParallelDirective
modifier|&
name|S
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|void
name|EmitOMPTargetTeamsDeviceFunction
parameter_list|(
name|CodeGenModule
modifier|&
name|CGM
parameter_list|,
name|StringRef
name|ParentName
parameter_list|,
specifier|const
name|OMPTargetTeamsDirective
modifier|&
name|S
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// \brief Emit inner loop of the worksharing/simd construct.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param S Directive, for which the inner loop must be emitted.
end_comment

begin_comment
comment|/// \param RequiresCleanup true, if directive has some associated private
end_comment

begin_comment
comment|/// variables.
end_comment

begin_comment
comment|/// \param LoopCond Bollean condition for loop continuation.
end_comment

begin_comment
comment|/// \param IncExpr Increment expression for loop control variable.
end_comment

begin_comment
comment|/// \param BodyGen Generator for the inner body of the inner loop.
end_comment

begin_comment
comment|/// \param PostIncGen Genrator for post-increment code (required for ordered
end_comment

begin_comment
comment|/// loop directvies).
end_comment

begin_decl_stmt
name|void
name|EmitOMPInnerLoop
argument_list|(
specifier|const
name|Stmt
operator|&
name|S
argument_list|,
name|bool
name|RequiresCleanup
argument_list|,
specifier|const
name|Expr
operator|*
name|LoopCond
argument_list|,
specifier|const
name|Expr
operator|*
name|IncExpr
argument_list|,
specifier|const
name|llvm
operator|::
name|function_ref
operator|<
name|void
argument_list|(
name|CodeGenFunction
operator|&
argument_list|)
operator|>
operator|&
name|BodyGen
argument_list|,
specifier|const
name|llvm
operator|::
name|function_ref
operator|<
name|void
argument_list|(
name|CodeGenFunction
operator|&
argument_list|)
operator|>
operator|&
name|PostIncGen
argument_list|)
decl_stmt|;
end_decl_stmt

begin_function_decl
name|JumpDest
name|getOMPCancelDestination
parameter_list|(
name|OpenMPDirectiveKind
name|Kind
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// Emit initial code for loop counters of loop-based directives.
end_comment

begin_function_decl
name|void
name|EmitOMPPrivateLoopCounters
parameter_list|(
specifier|const
name|OMPLoopDirective
modifier|&
name|S
parameter_list|,
name|OMPPrivateScope
modifier|&
name|LoopScope
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// Helper for the OpenMP loop directives.
end_comment

begin_function_decl
name|void
name|EmitOMPLoopBody
parameter_list|(
specifier|const
name|OMPLoopDirective
modifier|&
name|D
parameter_list|,
name|JumpDest
name|LoopExit
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// \brief Emit code for the worksharing loop-based directive.
end_comment

begin_comment
comment|/// \return true, if this construct has any lastprivate clause, false -
end_comment

begin_comment
comment|/// otherwise.
end_comment

begin_function_decl
name|bool
name|EmitOMPWorksharingLoop
parameter_list|(
specifier|const
name|OMPLoopDirective
modifier|&
name|S
parameter_list|,
name|Expr
modifier|*
name|EUB
parameter_list|,
specifier|const
name|CodeGenLoopBoundsTy
modifier|&
name|CodeGenLoopBounds
parameter_list|,
specifier|const
name|CodeGenDispatchBoundsTy
modifier|&
name|CGDispatchBounds
parameter_list|)
function_decl|;
end_function_decl

begin_label
name|private
label|:
end_label

begin_comment
comment|/// Helpers for blocks
end_comment

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

begin_comment
comment|/// Helpers for the OpenMP loop directives.
end_comment

begin_function_decl
name|void
name|EmitOMPSimdInit
parameter_list|(
specifier|const
name|OMPLoopDirective
modifier|&
name|D
parameter_list|,
name|bool
name|IsMonotonic
init|=
name|false
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
name|void
name|EmitOMPSimdFinal
argument_list|(
specifier|const
name|OMPLoopDirective
operator|&
name|D
argument_list|,
specifier|const
name|llvm
operator|::
name|function_ref
operator|<
name|llvm
operator|::
name|Value
operator|*
operator|(
name|CodeGenFunction
operator|&
operator|)
operator|>
operator|&
name|CondGen
argument_list|)
decl_stmt|;
end_decl_stmt

begin_function_decl
name|void
name|EmitOMPDistributeLoop
parameter_list|(
specifier|const
name|OMPLoopDirective
modifier|&
name|S
parameter_list|,
specifier|const
name|CodeGenLoopTy
modifier|&
name|CodeGenLoop
parameter_list|,
name|Expr
modifier|*
name|IncExpr
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// struct with the values to be passed to the OpenMP loop-related functions
end_comment

begin_struct
struct|struct
name|OMPLoopArguments
block|{
comment|/// loop lower bound
name|Address
name|LB
init|=
name|Address
operator|::
name|invalid
argument_list|()
decl_stmt|;
comment|/// loop upper bound
name|Address
name|UB
init|=
name|Address
operator|::
name|invalid
argument_list|()
decl_stmt|;
comment|/// loop stride
name|Address
name|ST
init|=
name|Address
operator|::
name|invalid
argument_list|()
decl_stmt|;
comment|/// isLastIteration argument for runtime functions
name|Address
name|IL
init|=
name|Address
operator|::
name|invalid
argument_list|()
decl_stmt|;
comment|/// Chunk value generated by sema
name|llvm
operator|::
name|Value
operator|*
name|Chunk
operator|=
name|nullptr
expr_stmt|;
comment|/// EnsureUpperBound
name|Expr
modifier|*
name|EUB
init|=
name|nullptr
decl_stmt|;
comment|/// IncrementExpression
name|Expr
modifier|*
name|IncExpr
init|=
name|nullptr
decl_stmt|;
comment|/// Loop initialization
name|Expr
modifier|*
name|Init
init|=
name|nullptr
decl_stmt|;
comment|/// Loop exit condition
name|Expr
modifier|*
name|Cond
init|=
name|nullptr
decl_stmt|;
comment|/// Update of LB after a whole chunk has been executed
name|Expr
modifier|*
name|NextLB
init|=
name|nullptr
decl_stmt|;
comment|/// Update of UB after a whole chunk has been executed
name|Expr
modifier|*
name|NextUB
init|=
name|nullptr
decl_stmt|;
name|OMPLoopArguments
argument_list|()
operator|=
expr|default
expr_stmt|;
name|OMPLoopArguments
argument_list|(
argument|Address LB
argument_list|,
argument|Address UB
argument_list|,
argument|Address ST
argument_list|,
argument|Address IL
argument_list|,
argument|llvm::Value *Chunk = nullptr
argument_list|,
argument|Expr *EUB = nullptr
argument_list|,
argument|Expr *IncExpr = nullptr
argument_list|,
argument|Expr *Init = nullptr
argument_list|,
argument|Expr *Cond = nullptr
argument_list|,
argument|Expr *NextLB = nullptr
argument_list|,
argument|Expr *NextUB = nullptr
argument_list|)
block|:
name|LB
argument_list|(
name|LB
argument_list|)
operator|,
name|UB
argument_list|(
name|UB
argument_list|)
operator|,
name|ST
argument_list|(
name|ST
argument_list|)
operator|,
name|IL
argument_list|(
name|IL
argument_list|)
operator|,
name|Chunk
argument_list|(
name|Chunk
argument_list|)
operator|,
name|EUB
argument_list|(
name|EUB
argument_list|)
operator|,
name|IncExpr
argument_list|(
name|IncExpr
argument_list|)
operator|,
name|Init
argument_list|(
name|Init
argument_list|)
operator|,
name|Cond
argument_list|(
name|Cond
argument_list|)
operator|,
name|NextLB
argument_list|(
name|NextLB
argument_list|)
operator|,
name|NextUB
argument_list|(
argument|NextUB
argument_list|)
block|{}
block|}
struct|;
end_struct

begin_function_decl
name|void
name|EmitOMPOuterLoop
parameter_list|(
name|bool
name|DynamicOrOrdered
parameter_list|,
name|bool
name|IsMonotonic
parameter_list|,
specifier|const
name|OMPLoopDirective
modifier|&
name|S
parameter_list|,
name|OMPPrivateScope
modifier|&
name|LoopScope
parameter_list|,
specifier|const
name|OMPLoopArguments
modifier|&
name|LoopArgs
parameter_list|,
specifier|const
name|CodeGenLoopTy
modifier|&
name|CodeGenLoop
parameter_list|,
specifier|const
name|CodeGenOrderedTy
modifier|&
name|CodeGenOrdered
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|EmitOMPForOuterLoop
parameter_list|(
specifier|const
name|OpenMPScheduleTy
modifier|&
name|ScheduleKind
parameter_list|,
name|bool
name|IsMonotonic
parameter_list|,
specifier|const
name|OMPLoopDirective
modifier|&
name|S
parameter_list|,
name|OMPPrivateScope
modifier|&
name|LoopScope
parameter_list|,
name|bool
name|Ordered
parameter_list|,
specifier|const
name|OMPLoopArguments
modifier|&
name|LoopArgs
parameter_list|,
specifier|const
name|CodeGenDispatchBoundsTy
modifier|&
name|CGDispatchBounds
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|EmitOMPDistributeOuterLoop
parameter_list|(
name|OpenMPDistScheduleClauseKind
name|ScheduleKind
parameter_list|,
specifier|const
name|OMPLoopDirective
modifier|&
name|S
parameter_list|,
name|OMPPrivateScope
modifier|&
name|LoopScope
parameter_list|,
specifier|const
name|OMPLoopArguments
modifier|&
name|LoopArgs
parameter_list|,
specifier|const
name|CodeGenLoopTy
modifier|&
name|CodeGenLoopContent
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// \brief Emit code for sections directive.
end_comment

begin_function_decl
name|void
name|EmitSections
parameter_list|(
specifier|const
name|OMPExecutableDirective
modifier|&
name|S
parameter_list|)
function_decl|;
end_function_decl

begin_label
name|public
label|:
end_label

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

begin_function_decl
name|RValue
name|convertTempToRValue
parameter_list|(
name|Address
name|addr
parameter_list|,
name|QualType
name|type
parameter_list|,
name|SourceLocation
name|Loc
parameter_list|)
function_decl|;
end_function_decl

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
name|bool
name|LValueIsSuitableForInlineAtomic
parameter_list|(
name|LValue
name|Src
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|RValue
name|EmitAtomicLoad
parameter_list|(
name|LValue
name|LV
parameter_list|,
name|SourceLocation
name|SL
parameter_list|,
name|AggValueSlot
name|Slot
init|=
name|AggValueSlot
operator|::
name|ignored
argument_list|()
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
name|RValue
name|EmitAtomicLoad
argument_list|(
name|LValue
name|lvalue
argument_list|,
name|SourceLocation
name|loc
argument_list|,
name|llvm
operator|::
name|AtomicOrdering
name|AO
argument_list|,
name|bool
name|IsVolatile
operator|=
name|false
argument_list|,
name|AggValueSlot
name|slot
operator|=
name|AggValueSlot
operator|::
name|ignored
argument_list|()
argument_list|)
decl_stmt|;
end_decl_stmt

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

begin_decl_stmt
name|void
name|EmitAtomicStore
argument_list|(
name|RValue
name|rvalue
argument_list|,
name|LValue
name|lvalue
argument_list|,
name|llvm
operator|::
name|AtomicOrdering
name|AO
argument_list|,
name|bool
name|IsVolatile
argument_list|,
name|bool
name|isInit
argument_list|)
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|std
operator|::
name|pair
operator|<
name|RValue
operator|,
name|llvm
operator|::
name|Value
operator|*
operator|>
name|EmitAtomicCompareExchange
argument_list|(
argument|LValue Obj
argument_list|,
argument|RValue Expected
argument_list|,
argument|RValue Desired
argument_list|,
argument|SourceLocation Loc
argument_list|,
argument|llvm::AtomicOrdering Success =           llvm::AtomicOrdering::SequentiallyConsistent
argument_list|,
argument|llvm::AtomicOrdering Failure =           llvm::AtomicOrdering::SequentiallyConsistent
argument_list|,
argument|bool IsWeak = false
argument_list|,
argument|AggValueSlot Slot = AggValueSlot::ignored()
argument_list|)
expr_stmt|;
end_expr_stmt

begin_decl_stmt
name|void
name|EmitAtomicUpdate
argument_list|(
name|LValue
name|LVal
argument_list|,
name|llvm
operator|::
name|AtomicOrdering
name|AO
argument_list|,
specifier|const
name|llvm
operator|::
name|function_ref
operator|<
name|RValue
argument_list|(
name|RValue
argument_list|)
operator|>
operator|&
name|UpdateOp
argument_list|,
name|bool
name|IsVolatile
argument_list|)
decl_stmt|;
end_decl_stmt

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
comment|/// Check if the scalar \p Value is within the valid range for the given
end_comment

begin_comment
comment|/// type \p Ty.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Returns true if a check is needed (even if the range is unknown).
end_comment

begin_decl_stmt
name|bool
name|EmitScalarRangeCheck
argument_list|(
name|llvm
operator|::
name|Value
operator|*
name|Value
argument_list|,
name|QualType
name|Ty
argument_list|,
name|SourceLocation
name|Loc
argument_list|)
decl_stmt|;
end_decl_stmt

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
argument|Address Addr
argument_list|,
argument|bool Volatile
argument_list|,
argument|QualType Ty
argument_list|,
argument|SourceLocation Loc
argument_list|,
argument|LValueBaseInfo BaseInfo =                                     LValueBaseInfo(AlignmentSource::Type)
argument_list|,
argument|llvm::MDNode *TBAAInfo = nullptr
argument_list|,
argument|QualType TBAABaseTy = QualType()
argument_list|,
argument|uint64_t TBAAOffset =
literal|0
argument_list|,
argument|bool isNontemporal = false
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
name|Address
name|Addr
argument_list|,
name|bool
name|Volatile
argument_list|,
name|QualType
name|Ty
argument_list|,
name|LValueBaseInfo
name|BaseInfo
operator|=
name|LValueBaseInfo
argument_list|(
name|AlignmentSource
operator|::
name|Type
argument_list|)
argument_list|,
name|llvm
operator|::
name|MDNode
operator|*
name|TBAAInfo
operator|=
name|nullptr
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
argument_list|,
name|bool
name|isNontemporal
operator|=
name|false
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
parameter_list|,
name|SourceLocation
name|Loc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|RValue
name|EmitLoadOfGlobalRegLValue
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

begin_function_decl
name|void
name|EmitStoreThroughGlobalRegLValue
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
name|nullptr
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
name|EmitScalarCompoundAssignWithComplex
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
name|EmitOMPArraySectionExpr
parameter_list|(
specifier|const
name|OMPArraySectionExpr
modifier|*
name|E
parameter_list|,
name|bool
name|IsLowerBound
init|=
name|true
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
name|Address
name|EmitExtVectorElementLValue
parameter_list|(
name|LValue
name|V
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

begin_function_decl
name|Address
name|EmitArrayToPointerDecay
parameter_list|(
specifier|const
name|Expr
modifier|*
name|Array
parameter_list|,
name|LValueBaseInfo
modifier|*
name|BaseInfo
init|=
name|nullptr
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
name|explicit
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
name|nullptr
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

begin_function_decl
name|void
name|EmitDeclRefExprDbgValue
parameter_list|(
specifier|const
name|DeclRefExpr
modifier|*
name|E
parameter_list|,
specifier|const
name|APValue
modifier|&
name|Init
parameter_list|)
function_decl|;
end_function_decl

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

begin_decl_stmt
name|RValue
name|EmitCall
argument_list|(
specifier|const
name|CGFunctionInfo
operator|&
name|CallInfo
argument_list|,
specifier|const
name|CGCallee
operator|&
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
name|llvm
operator|::
name|Instruction
operator|*
operator|*
name|callOrInvoke
operator|=
name|nullptr
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
specifier|const
name|CGCallee
operator|&
name|Callee
argument_list|,
specifier|const
name|CallExpr
operator|*
name|E
argument_list|,
name|ReturnValueSlot
name|ReturnValue
argument_list|,
name|llvm
operator|::
name|Value
operator|*
name|Chain
operator|=
name|nullptr
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

begin_function_decl
name|RValue
name|EmitSimpleCallExpr
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

begin_function_decl
name|CGCallee
name|EmitCallee
parameter_list|(
specifier|const
name|Expr
modifier|*
name|E
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|checkTargetFeatures
parameter_list|(
specifier|const
name|CallExpr
modifier|*
name|E
parameter_list|,
specifier|const
name|FunctionDecl
modifier|*
name|TargetDecl
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

begin_decl_stmt
name|CGCallee
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
decl_stmt|;
end_decl_stmt

begin_function_decl
name|CGCallee
name|BuildAppleKextVirtualDestructorCall
parameter_list|(
specifier|const
name|CXXDestructorDecl
modifier|*
name|DD
parameter_list|,
name|CXXDtorType
name|Type
parameter_list|,
specifier|const
name|CXXRecordDecl
modifier|*
name|RD
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
name|RValue
name|EmitCXXMemberOrOperatorCall
argument_list|(
specifier|const
name|CXXMethodDecl
operator|*
name|Method
argument_list|,
specifier|const
name|CGCallee
operator|&
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
specifier|const
name|CallExpr
operator|*
name|E
argument_list|,
name|CallArgList
operator|*
name|RtlArgs
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|RValue
name|EmitCXXDestructorCall
argument_list|(
specifier|const
name|CXXDestructorDecl
operator|*
name|DD
argument_list|,
specifier|const
name|CGCallee
operator|&
name|Callee
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
specifier|const
name|CallExpr
operator|*
name|E
argument_list|,
name|StructorType
name|Type
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
name|EmitCXXMemberOrOperatorMemberCallExpr
parameter_list|(
specifier|const
name|CallExpr
modifier|*
name|CE
parameter_list|,
specifier|const
name|CXXMethodDecl
modifier|*
name|MD
parameter_list|,
name|ReturnValueSlot
name|ReturnValue
parameter_list|,
name|bool
name|HasQualifier
parameter_list|,
name|NestedNameSpecifier
modifier|*
name|Qualifier
parameter_list|,
name|bool
name|IsArrow
parameter_list|,
specifier|const
name|Expr
modifier|*
name|Base
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|// Compute the object pointer.
end_comment

begin_decl_stmt
name|Address
name|EmitCXXMemberDataPointerAddress
argument_list|(
specifier|const
name|Expr
operator|*
name|E
argument_list|,
name|Address
name|base
argument_list|,
name|llvm
operator|::
name|Value
operator|*
name|memberPtr
argument_list|,
specifier|const
name|MemberPointerType
operator|*
name|memberPtrType
argument_list|,
name|LValueBaseInfo
operator|*
name|BaseInfo
operator|=
name|nullptr
argument_list|)
decl_stmt|;
end_decl_stmt

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
name|EmitCXXPseudoDestructorExpr
parameter_list|(
specifier|const
name|CXXPseudoDestructorExpr
modifier|*
name|E
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
name|EmitNVPTXDevicePrintfCallExpr
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
parameter_list|,
name|ReturnValueSlot
name|ReturnValue
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
name|EmitCommonNeonBuiltinExpr
argument_list|(
argument|unsigned BuiltinID
argument_list|,
argument|unsigned LLVMIntrinsic
argument_list|,
argument|unsigned AltLLVMIntrinsic
argument_list|,
argument|const char *NameHint
argument_list|,
argument|unsigned Modifier
argument_list|,
argument|const CallExpr *E
argument_list|,
argument|SmallVectorImpl<llvm::Value *>&Ops
argument_list|,
argument|Address PtrOp0
argument_list|,
argument|Address PtrOp1
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|llvm
operator|::
name|Function
operator|*
name|LookupNeonLLVMIntrinsic
argument_list|(
argument|unsigned IntrinsicID
argument_list|,
argument|unsigned Modifier
argument_list|,
argument|llvm::Type *ArgTy
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
name|vectorWrapScalar16
argument_list|(
name|llvm
operator|::
name|Value
operator|*
name|Op
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
name|EmitAMDGPUBuiltinExpr
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
name|EmitSystemZBuiltinExpr
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
name|EmitNVPTXBuiltinExpr
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
name|EmitWebAssemblyBuiltinExpr
argument_list|(
argument|unsigned BuiltinID
argument_list|,
argument|const CallExpr *E
argument_list|)
expr_stmt|;
end_expr_stmt

begin_label
name|private
label|:
end_label

begin_decl_stmt
name|enum
name|class
name|MSVCIntrin
decl_stmt|;
end_decl_stmt

begin_label
name|public
label|:
end_label

begin_expr_stmt
name|llvm
operator|::
name|Value
operator|*
name|EmitMSVCBuiltinExpr
argument_list|(
argument|MSVCIntrin BuiltinID
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
name|EmitBuiltinAvailable
argument_list|(
name|ArrayRef
operator|<
name|llvm
operator|::
name|Value
operator|*
operator|>
name|Args
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
name|Address
name|addr
argument_list|,
name|llvm
operator|::
name|Value
operator|*
name|value
argument_list|)
decl_stmt|;
end_decl_stmt

begin_function_decl
name|void
name|EmitARCDestroyWeak
parameter_list|(
name|Address
name|addr
parameter_list|)
function_decl|;
end_function_decl

begin_expr_stmt
name|llvm
operator|::
name|Value
operator|*
name|EmitARCLoadWeak
argument_list|(
argument|Address addr
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
argument|Address addr
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
argument|Address addr
argument_list|,
argument|llvm::Value *value
argument_list|,
argument|bool ignored
argument_list|)
expr_stmt|;
end_expr_stmt

begin_function_decl
name|void
name|EmitARCCopyWeak
parameter_list|(
name|Address
name|dst
parameter_list|,
name|Address
name|src
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|EmitARCMoveWeak
parameter_list|(
name|Address
name|dst
parameter_list|,
name|Address
name|src
parameter_list|)
function_decl|;
end_function_decl

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
argument|Address addr
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

begin_function_decl
name|void
name|EmitARCDestroyStrong
parameter_list|(
name|Address
name|addr
parameter_list|,
name|ARCPreciseLifetime_t
name|precise
parameter_list|)
function_decl|;
end_function_decl

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
name|llvm
operator|::
name|Value
operator|*
name|EmitARCUnsafeClaimAutoreleasedReturnValue
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
name|EmitARCStoreUnsafeUnretained
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
name|EmitARCReclaimReturnedObject
argument_list|(
argument|const Expr *e
argument_list|,
argument|bool allowUnsafeClaim
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

begin_expr_stmt
name|llvm
operator|::
name|Value
operator|*
name|EmitARCUnsafeUnretainedScalarExpr
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
specifier|static
name|Destroyer
name|emitARCIntrinsicUse
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
comment|/// Emit a conversion from the specified type to the specified destination
end_comment

begin_comment
comment|/// type, both of which are LLVM scalar types.
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
argument_list|,
argument|SourceLocation Loc
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// Emit a conversion from the specified complex type to the specified
end_comment

begin_comment
comment|/// destination type, where the destination type is an LLVM scalar type.
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
argument_list|,
argument|SourceLocation Loc
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

begin_function_decl
name|Address
name|emitAddrOfRealComponent
parameter_list|(
name|Address
name|complex
parameter_list|,
name|QualType
name|complexType
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|Address
name|emitAddrOfImagComponent
parameter_list|(
name|Address
name|complex
parameter_list|,
name|QualType
name|complexType
parameter_list|)
function_decl|;
end_function_decl

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

begin_expr_stmt
name|llvm
operator|::
name|Constant
operator|*
name|createAtExitStub
argument_list|(
specifier|const
name|VarDecl
operator|&
name|VD
argument_list|,
name|llvm
operator|::
name|Constant
operator|*
name|Dtor
argument_list|,
name|llvm
operator|::
name|Constant
operator|*
name|Addr
argument_list|)
expr_stmt|;
end_expr_stmt

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
name|Function
operator|*
operator|>
name|CXXThreadLocals
argument_list|,
name|Address
name|Guard
operator|=
name|Address
operator|::
name|invalid
argument_list|()
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
name|WeakTrackingVH
argument_list|,
name|llvm
operator|::
name|Constant
operator|*
operator|>>
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

begin_function_decl
name|void
name|EmitSynthesizedCXXCopyCtor
parameter_list|(
name|Address
name|Dest
parameter_list|,
name|Address
name|Src
parameter_list|,
specifier|const
name|Expr
modifier|*
name|Exp
parameter_list|)
function_decl|;
end_function_decl

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

begin_function_decl
name|RValue
name|EmitAtomicExpr
parameter_list|(
name|AtomicExpr
modifier|*
name|E
parameter_list|)
function_decl|;
end_function_decl

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

begin_function_decl
name|Address
name|EmitFieldAnnotations
parameter_list|(
specifier|const
name|FieldDecl
modifier|*
name|D
parameter_list|,
name|Address
name|V
parameter_list|)
function_decl|;
end_function_decl

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
comment|/// Determine if the given statement might introduce a declaration into the
end_comment

begin_comment
comment|/// current scope, by being a (possibly-labelled) DeclStmt.
end_comment

begin_function_decl
specifier|static
name|bool
name|mightAddDeclToScope
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
parameter_list|,
name|bool
name|AllowLabels
init|=
name|false
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
argument_list|,
name|bool
name|AllowLabels
operator|=
name|false
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

begin_comment
comment|/// TrueCount should be the number of times we expect the condition to
end_comment

begin_comment
comment|/// evaluate to true based on PGO data.
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
argument_list|,
name|uint64_t
name|TrueCount
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// Given an assignment `*LHS = RHS`, emit a test that checks if \p RHS is
end_comment

begin_comment
comment|/// nonnull, if \p LHS is marked _Nonnull.
end_comment

begin_decl_stmt
name|void
name|EmitNullabilityCheck
argument_list|(
name|LValue
name|LHS
argument_list|,
name|llvm
operator|::
name|Value
operator|*
name|RHS
argument_list|,
name|SourceLocation
name|Loc
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// Same as IRBuilder::CreateInBoundsGEP, but additionally emits a check to
end_comment

begin_comment
comment|/// detect undefined behavior when the pointer overflow sanitizer is enabled.
end_comment

begin_expr_stmt
name|llvm
operator|::
name|Value
operator|*
name|EmitCheckedInBoundsGEP
argument_list|(
argument|llvm::Value *Ptr
argument_list|,
argument|ArrayRef<llvm::Value *> IdxList
argument_list|,
argument|SourceLocation Loc
argument_list|,
argument|const Twine&Name =
literal|""
argument_list|)
expr_stmt|;
end_expr_stmt

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
name|ArrayRef
operator|<
name|std
operator|::
name|pair
operator|<
name|llvm
operator|::
name|Value
operator|*
argument_list|,
name|SanitizerMask
operator|>>
name|Checked
argument_list|,
name|SanitizerHandler
name|Check
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
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// \brief Emit a slow path cross-DSO CFI check which calls __cfi_slowpath
end_comment

begin_comment
comment|/// if Cond if false.
end_comment

begin_decl_stmt
name|void
name|EmitCfiSlowPathCheck
argument_list|(
name|SanitizerMask
name|Kind
argument_list|,
name|llvm
operator|::
name|Value
operator|*
name|Cond
argument_list|,
name|llvm
operator|::
name|ConstantInt
operator|*
name|TypeId
argument_list|,
name|llvm
operator|::
name|Value
operator|*
name|Ptr
argument_list|,
name|ArrayRef
operator|<
name|llvm
operator|::
name|Constant
operator|*
operator|>
name|StaticArgs
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
comment|/// \brief Emit a call to trap or debugtrap and attach function attribute
end_comment

begin_comment
comment|/// "trap-func-name" if specified.
end_comment

begin_expr_stmt
name|llvm
operator|::
name|CallInst
operator|*
name|EmitTrapCall
argument_list|(
argument|llvm::Intrinsic::ID IntrID
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// \brief Emit a stub for the cross-DSO CFI check function.
end_comment

begin_function_decl
name|void
name|EmitCfiCheckStub
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/// \brief Emit a cross-DSO CFI failure handling function.
end_comment

begin_function_decl
name|void
name|EmitCfiCheckFail
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/// \brief Create a check for a function parameter that may potentially be
end_comment

begin_comment
comment|/// declared as non-null.
end_comment

begin_function_decl
name|void
name|EmitNonNullArgCheck
parameter_list|(
name|RValue
name|RV
parameter_list|,
name|QualType
name|ArgType
parameter_list|,
name|SourceLocation
name|ArgLoc
parameter_list|,
name|AbstractCallee
name|AC
parameter_list|,
name|unsigned
name|ParmNum
parameter_list|)
function_decl|;
end_function_decl

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

begin_decl_stmt
name|void
name|deferPlaceholderReplacement
argument_list|(
name|llvm
operator|::
name|Instruction
operator|*
name|Old
argument_list|,
name|llvm
operator|::
name|Value
operator|*
name|New
argument_list|)
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|llvm
operator|::
name|SmallVector
operator|<
name|std
operator|::
name|pair
operator|<
name|llvm
operator|::
name|Instruction
operator|*
operator|,
name|llvm
operator|::
name|Value
operator|*
operator|>
operator|,
literal|4
operator|>
name|DeferredReplacements
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// Set the address of a local variable.
end_comment

begin_function
name|void
name|setAddrOfLocalVar
parameter_list|(
specifier|const
name|VarDecl
modifier|*
name|VD
parameter_list|,
name|Address
name|Addr
parameter_list|)
block|{
name|assert
argument_list|(
operator|!
name|LocalDeclMap
operator|.
name|count
argument_list|(
name|VD
argument_list|)
operator|&&
literal|"Decl already exists in LocalDeclMap!"
argument_list|)
expr_stmt|;
name|LocalDeclMap
operator|.
name|insert
argument_list|(
block|{
name|VD
block|,
name|Addr
block|}
argument_list|)
expr_stmt|;
block|}
end_function

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

begin_decl_stmt
name|void
name|ExpandTypeFromArgs
argument_list|(
name|QualType
name|Ty
argument_list|,
name|LValue
name|Dst
argument_list|,
name|SmallVectorImpl
operator|<
name|llvm
operator|::
name|Value
operator|*
operator|>
operator|::
name|iterator
operator|&
name|AI
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// ExpandTypeToArgs - Expand an RValue \arg RV, with the LLVM type for \arg
end_comment

begin_comment
comment|/// Ty, into individual arguments on the provided vector \arg IRCallArgs,
end_comment

begin_comment
comment|/// starting at index \arg IRCallArgPos. See ABIArgInfo::Expand.
end_comment

begin_decl_stmt
name|void
name|ExpandTypeToArgs
argument_list|(
name|QualType
name|Ty
argument_list|,
name|RValue
name|RV
argument_list|,
name|llvm
operator|::
name|FunctionType
operator|*
name|IRFuncTy
argument_list|,
name|SmallVectorImpl
operator|<
name|llvm
operator|::
name|Value
operator|*
operator|>
operator|&
name|IRCallArgs
argument_list|,
name|unsigned
operator|&
name|IRCallArgPos
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
comment|/// \brief Attempts to statically evaluate the object size of E. If that
end_comment

begin_comment
comment|/// fails, emits code to figure the size of E out for us. This is
end_comment

begin_comment
comment|/// pass_object_size aware.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// If EmittedExpr is non-null, this will use that instead of re-emitting E.
end_comment

begin_expr_stmt
name|llvm
operator|::
name|Value
operator|*
name|evaluateOrEmitBuiltinObjectSize
argument_list|(
argument|const Expr *E
argument_list|,
argument|unsigned Type
argument_list|,
argument|llvm::IntegerType *ResType
argument_list|,
argument|llvm::Value *EmittedE
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// \brief Emits the size of E, as required by __builtin_object_size. This
end_comment

begin_comment
comment|/// function is aware of pass_object_size parameters, and will act accordingly
end_comment

begin_comment
comment|/// if E is a parameter with the pass_object_size attribute.
end_comment

begin_expr_stmt
name|llvm
operator|::
name|Value
operator|*
name|emitBuiltinObjectSize
argument_list|(
argument|const Expr *E
argument_list|,
argument|unsigned Type
argument_list|,
argument|llvm::IntegerType *ResType
argument_list|,
argument|llvm::Value *EmittedE
argument_list|)
expr_stmt|;
end_expr_stmt

begin_label
name|public
label|:
end_label

begin_ifndef
ifndef|#
directive|ifndef
name|NDEBUG
end_ifndef

begin_comment
comment|// Determine whether the given argument is an Objective-C method
end_comment

begin_comment
comment|// that may have type parameters in its signature.
end_comment

begin_function
specifier|static
name|bool
name|isObjCMethodWithTypeParams
parameter_list|(
specifier|const
name|ObjCMethodDecl
modifier|*
name|method
parameter_list|)
block|{
specifier|const
name|DeclContext
modifier|*
name|dc
init|=
name|method
operator|->
name|getDeclContext
argument_list|()
decl_stmt|;
if|if
condition|(
specifier|const
name|ObjCInterfaceDecl
modifier|*
name|classDecl
init|=
name|dyn_cast
operator|<
name|ObjCInterfaceDecl
operator|>
operator|(
name|dc
operator|)
condition|)
block|{
return|return
name|classDecl
operator|->
name|getTypeParamListAsWritten
argument_list|()
return|;
block|}
if|if
condition|(
specifier|const
name|ObjCCategoryDecl
modifier|*
name|catDecl
init|=
name|dyn_cast
operator|<
name|ObjCCategoryDecl
operator|>
operator|(
name|dc
operator|)
condition|)
block|{
return|return
name|catDecl
operator|->
name|getTypeParamList
argument_list|()
return|;
block|}
return|return
name|false
return|;
block|}
end_function

begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|>
specifier|static
name|bool
name|isObjCMethodWithTypeParams
argument_list|(
argument|const T *
argument_list|)
block|{
return|return
name|false
return|;
block|}
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
name|enum
name|class
name|EvaluationOrder
block|{
comment|///! No language constraints on evaluation order.
name|Default
operator|,
comment|///! Language semantics require left-to-right evaluation.
name|ForceLeftToRight
operator|,
comment|///! Language semantics require right-to-left evaluation.
name|ForceRightToLeft
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|/// EmitCallArgs - Emit call arguments for a function.
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
argument|CallArgList&Args
argument_list|,
argument|const T *CallArgTypeInfo
argument_list|,
argument|llvm::iterator_range<CallExpr::const_arg_iterator> ArgRange
argument_list|,
argument|AbstractCallee AC = AbstractCallee()
argument_list|,
argument|unsigned ParamsToSkip =
literal|0
argument_list|,
argument|EvaluationOrder Order = EvaluationOrder::Default
argument_list|)
block|{
name|SmallVector
operator|<
name|QualType
block|,
literal|16
operator|>
name|ArgTypes
block|;
name|CallExpr
operator|::
name|const_arg_iterator
name|Arg
operator|=
name|ArgRange
operator|.
name|begin
argument_list|()
block|;
name|assert
argument_list|(
operator|(
name|ParamsToSkip
operator|==
literal|0
operator|||
name|CallArgTypeInfo
operator|)
operator|&&
literal|"Can't skip parameters if type info is not provided"
argument_list|)
block|;
if|if
condition|(
name|CallArgTypeInfo
condition|)
block|{
ifndef|#
directive|ifndef
name|NDEBUG
name|bool
name|isGenericMethod
init|=
name|isObjCMethodWithTypeParams
argument_list|(
name|CallArgTypeInfo
argument_list|)
decl_stmt|;
endif|#
directive|endif
comment|// First, use the argument types that the type info knows about
for|for
control|(
name|auto
name|I
init|=
name|CallArgTypeInfo
operator|->
name|param_type_begin
argument_list|()
operator|+
name|ParamsToSkip
init|,
name|E
init|=
name|CallArgTypeInfo
operator|->
name|param_type_end
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
name|ArgRange
operator|.
name|end
argument_list|()
operator|&&
literal|"Running over edge of argument list!"
argument_list|)
expr_stmt|;
name|assert
argument_list|(
operator|(
name|isGenericMethod
operator|||
operator|(
operator|(
operator|*
name|I
operator|)
operator|->
name|isVariablyModifiedType
argument_list|()
operator|||
operator|(
operator|*
name|I
operator|)
operator|.
name|getNonReferenceType
argument_list|()
operator|->
name|isObjCRetainableType
argument_list|()
operator|||
name|getContext
argument_list|()
operator|.
name|getCanonicalType
argument_list|(
operator|(
operator|*
name|I
operator|)
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
operator|(
operator|*
name|Arg
operator|)
operator|->
name|getType
argument_list|()
argument_list|)
operator|.
name|getTypePtr
argument_list|()
operator|)
operator|)
operator|&&
literal|"type mismatch in call argument!"
argument_list|)
expr_stmt|;
name|ArgTypes
operator|.
name|push_back
argument_list|(
operator|*
name|I
argument_list|)
expr_stmt|;
block|}
end_expr_stmt

begin_comment
unit|}
comment|// Either we've emitted all the call args, or we have a call to variadic
end_comment

begin_comment
comment|// function.
end_comment

begin_expr_stmt
unit|assert
operator|(
operator|(
name|Arg
operator|==
name|ArgRange
operator|.
name|end
argument_list|()
operator|||
operator|!
name|CallArgTypeInfo
operator|||
name|CallArgTypeInfo
operator|->
name|isVariadic
argument_list|()
operator|)
operator|&&
literal|"Extra arguments in non-variadic function!"
operator|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|// If we still have any arguments, emit them using the type of the argument.
end_comment

begin_for
for|for
control|(
name|auto
operator|*
name|A
operator|:
name|llvm
operator|::
name|make_range
argument_list|(
name|Arg
argument_list|,
name|ArgRange
operator|.
name|end
argument_list|()
argument_list|)
control|)
name|ArgTypes
operator|.
name|push_back
argument_list|(
name|CallArgTypeInfo
condition|?
name|getVarArgType
argument_list|(
name|A
argument_list|)
else|:
name|A
operator|->
name|getType
argument_list|()
argument_list|)
expr_stmt|;
end_for

begin_expr_stmt
name|EmitCallArgs
argument_list|(
name|Args
argument_list|,
name|ArgTypes
argument_list|,
name|ArgRange
argument_list|,
name|AC
argument_list|,
name|ParamsToSkip
argument_list|,
name|Order
argument_list|)
expr_stmt|;
end_expr_stmt

begin_macro
unit|}    void
name|EmitCallArgs
argument_list|(
argument|CallArgList&Args
argument_list|,
argument|ArrayRef<QualType> ArgTypes
argument_list|,
argument|llvm::iterator_range<CallExpr::const_arg_iterator> ArgRange
argument_list|,
argument|AbstractCallee AC = AbstractCallee()
argument_list|,
argument|unsigned ParamsToSkip =
literal|0
argument_list|,
argument|EvaluationOrder Order = EvaluationOrder::Default
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|/// EmitPointerWithAlignment - Given an expression with a pointer type,
end_comment

begin_comment
comment|/// emit the value and compute our best estimate of the alignment of the
end_comment

begin_comment
comment|/// pointee.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param BaseInfo - If non-null, this will be initialized with
end_comment

begin_comment
comment|/// information about the source of the alignment and the may-alias
end_comment

begin_comment
comment|/// attribute.  Note that this function will conservatively fall back on
end_comment

begin_comment
comment|/// the type when it doesn't recognize the expression and may-alias will
end_comment

begin_comment
comment|/// be set to false.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// One reasonable way to use this information is when there's a language
end_comment

begin_comment
comment|/// guarantee that the pointer must be aligned to some stricter value, and
end_comment

begin_comment
comment|/// we're simply trying to ensure that sufficiently obvious uses of under-
end_comment

begin_comment
comment|/// aligned objects don't get miscompiled; for example, a placement new
end_comment

begin_comment
comment|/// into the address of a local variable.  In such a case, it's quite
end_comment

begin_comment
comment|/// reasonable to just ignore the returned alignment when it isn't from an
end_comment

begin_comment
comment|/// explicit source.
end_comment

begin_function_decl
name|Address
name|EmitPointerWithAlignment
parameter_list|(
specifier|const
name|Expr
modifier|*
name|Addr
parameter_list|,
name|LValueBaseInfo
modifier|*
name|BaseInfo
init|=
name|nullptr
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
name|void
name|EmitSanitizerStatReport
argument_list|(
name|llvm
operator|::
name|SanitizerStatKind
name|SSK
argument_list|)
decl_stmt|;
end_decl_stmt

begin_label
name|private
label|:
end_label

begin_function_decl
name|QualType
name|getVarArgType
parameter_list|(
specifier|const
name|Expr
modifier|*
name|Arg
parameter_list|)
function_decl|;
end_function_decl

begin_expr_stmt
specifier|const
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

begin_decl_stmt
name|BlockByrefHelpers
modifier|*
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
decl_stmt|;
end_decl_stmt

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

begin_expr_stmt
name|llvm
operator|::
name|Value
operator|*
name|GetValueForARMHint
argument_list|(
argument|unsigned BuiltinID
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
comment|// Otherwise, we need an alloca.
name|auto
name|align
init|=
name|CharUnits
operator|::
name|fromQuantity
argument_list|(
name|CGF
operator|.
name|CGM
operator|.
name|getDataLayout
argument_list|()
operator|.
name|getPrefTypeAlignment
argument_list|(
name|value
operator|->
name|getType
argument_list|()
argument_list|)
argument_list|)
decl_stmt|;
name|Address
name|alloca
init|=
name|CGF
operator|.
name|CreateTempAlloca
argument_list|(
name|value
operator|->
name|getType
argument_list|()
argument_list|,
name|align
argument_list|,
literal|"cond-cleanup.save"
argument_list|)
decl_stmt|;
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
operator|.
name|getPointer
argument_list|()
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
comment|// If the value says it wasn't saved, trust that it's still dominating.
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
comment|// Otherwise, it should be an alloca instruction, as set up in save().
name|auto
name|alloca
operator|=
name|cast
operator|<
name|llvm
operator|::
name|AllocaInst
operator|>
operator|(
name|value
operator|.
name|getPointer
argument_list|()
operator|)
expr_stmt|;
return|return
name|CGF
operator|.
name|Builder
operator|.
name|CreateAlignedLoad
argument_list|(
name|alloca
argument_list|,
name|alloca
operator|->
name|getAlignment
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
comment|/// A specialization of DominatingValue for Address.
end_comment

begin_expr_stmt
name|template
operator|<
operator|>
expr|struct
name|DominatingValue
operator|<
name|Address
operator|>
block|{
typedef|typedef
name|Address
name|type
typedef|;
block|struct
name|saved_type
block|{
name|DominatingLLVMValue
operator|::
name|saved_type
name|SavedValue
block|;
name|CharUnits
name|Alignment
block|;   }
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
name|DominatingLLVMValue
operator|::
name|needsSaving
argument_list|(
name|value
operator|.
name|getPointer
argument_list|()
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
block|{
name|DominatingLLVMValue
operator|::
name|save
argument_list|(
name|CGF
argument_list|,
name|value
operator|.
name|getPointer
argument_list|()
argument_list|)
block|,
name|value
operator|.
name|getAlignment
argument_list|()
block|}
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
name|Address
argument_list|(
name|DominatingLLVMValue
operator|::
name|restore
argument_list|(
name|CGF
argument_list|,
name|value
operator|.
name|SavedValue
argument_list|)
argument_list|,
name|value
operator|.
name|Alignment
argument_list|)
return|;
block|}
end_function

begin_comment
unit|};
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
name|unsigned
name|K
operator|:
literal|3
block|;
name|unsigned
name|Align
operator|:
literal|29
block|;
name|saved_type
argument_list|(
argument|llvm::Value *v
argument_list|,
argument|Kind k
argument_list|,
argument|unsigned a =
literal|0
argument_list|)
operator|:
name|Value
argument_list|(
name|v
argument_list|)
block|,
name|K
argument_list|(
name|k
argument_list|)
block|,
name|Align
argument_list|(
argument|a
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
comment|// implementations in CGCleanup.cpp
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

