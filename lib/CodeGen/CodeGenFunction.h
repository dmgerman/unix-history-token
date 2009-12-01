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
file|"clang/AST/Type.h"
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
file|"clang/Basic/TargetInfo.h"
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
file|"llvm/Support/ValueHandle.h"
end_include

begin_include
include|#
directive|include
file|<map>
end_include

begin_include
include|#
directive|include
file|"CodeGenModule.h"
end_include

begin_include
include|#
directive|include
file|"CGBlocks.h"
end_include

begin_include
include|#
directive|include
file|"CGBuilder.h"
end_include

begin_include
include|#
directive|include
file|"CGCall.h"
end_include

begin_include
include|#
directive|include
file|"CGCXX.h"
end_include

begin_include
include|#
directive|include
file|"CGValue.h"
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
name|CXXDestructorDecl
decl_stmt|;
name|class
name|CXXTryStmt
decl_stmt|;
name|class
name|Decl
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
name|namespace
name|CodeGen
block|{
name|class
name|CodeGenModule
decl_stmt|;
name|class
name|CodeGenTypes
decl_stmt|;
name|class
name|CGDebugInfo
decl_stmt|;
name|class
name|CGFunctionInfo
decl_stmt|;
name|class
name|CGRecordLayout
decl_stmt|;
comment|/// CodeGenFunction - This class organizes the per-function state that is used
comment|/// while generating LLVM code.
name|class
name|CodeGenFunction
range|:
name|public
name|BlockFunction
block|{
name|CodeGenFunction
argument_list|(
specifier|const
name|CodeGenFunction
operator|&
argument_list|)
block|;
comment|// DO NOT IMPLEMENT
name|void
name|operator
operator|=
operator|(
specifier|const
name|CodeGenFunction
operator|&
operator|)
block|;
comment|// DO NOT IMPLEMENT
name|public
operator|:
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
comment|/// CurFuncDecl - Holds the Decl for the current function or ObjC method.
comment|/// This excludes BlockDecls.
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
comment|/// ReturnBlock - Unified return block.
name|llvm
operator|::
name|BasicBlock
operator|*
name|ReturnBlock
expr_stmt|;
comment|/// ReturnValue - The temporary alloca to hold the return value. This is null
comment|/// iff the function has no return value.
name|llvm
operator|::
name|Instruction
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
specifier|const
name|llvm
operator|::
name|Type
operator|*
name|LLVMIntTy
expr_stmt|;
name|uint32_t
name|LLVMPointerWidth
decl_stmt|;
name|public
label|:
comment|/// ObjCEHValueStack - Stack of Objective-C exception values, used for
comment|/// rethrows.
name|llvm
operator|::
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
comment|/// PushCleanupBlock - Push a new cleanup entry on the stack and set the
comment|/// passed in block as the cleanup block.
name|void
name|PushCleanupBlock
argument_list|(
name|llvm
operator|::
name|BasicBlock
operator|*
name|CleanupEntryBlock
argument_list|,
name|llvm
operator|::
name|BasicBlock
operator|*
name|CleanupExitBlock
operator|=
literal|0
argument_list|)
decl_stmt|;
comment|/// CleanupBlockInfo - A struct representing a popped cleanup block.
struct|struct
name|CleanupBlockInfo
block|{
comment|/// CleanupEntryBlock - the cleanup entry block
name|llvm
operator|::
name|BasicBlock
operator|*
name|CleanupBlock
expr_stmt|;
comment|/// SwitchBlock - the block (if any) containing the switch instruction used
comment|/// for jumping to the final destination.
name|llvm
operator|::
name|BasicBlock
operator|*
name|SwitchBlock
expr_stmt|;
comment|/// EndBlock - the default destination for the switch instruction.
name|llvm
operator|::
name|BasicBlock
operator|*
name|EndBlock
expr_stmt|;
name|CleanupBlockInfo
argument_list|(
name|llvm
operator|::
name|BasicBlock
operator|*
name|cb
argument_list|,
name|llvm
operator|::
name|BasicBlock
operator|*
name|sb
argument_list|,
name|llvm
operator|::
name|BasicBlock
operator|*
name|eb
argument_list|)
operator|:
name|CleanupBlock
argument_list|(
name|cb
argument_list|)
operator|,
name|SwitchBlock
argument_list|(
name|sb
argument_list|)
operator|,
name|EndBlock
argument_list|(
argument|eb
argument_list|)
block|{}
block|}
struct|;
comment|/// PopCleanupBlock - Will pop the cleanup entry on the stack, process all
comment|/// branch fixups and return a block info struct with the switch block and end
comment|/// block.
name|CleanupBlockInfo
name|PopCleanupBlock
parameter_list|()
function_decl|;
comment|/// DelayedCleanupBlock - RAII object that will create a cleanup block and set
comment|/// the insert point to that block. When destructed, it sets the insert point
comment|/// to the previous block and pushes a new cleanup entry on the stack.
name|class
name|DelayedCleanupBlock
block|{
name|CodeGenFunction
modifier|&
name|CGF
decl_stmt|;
name|llvm
operator|::
name|BasicBlock
operator|*
name|CurBB
expr_stmt|;
name|llvm
operator|::
name|BasicBlock
operator|*
name|CleanupEntryBB
expr_stmt|;
name|llvm
operator|::
name|BasicBlock
operator|*
name|CleanupExitBB
expr_stmt|;
name|public
label|:
name|DelayedCleanupBlock
argument_list|(
name|CodeGenFunction
operator|&
name|cgf
argument_list|)
operator|:
name|CGF
argument_list|(
name|cgf
argument_list|)
operator|,
name|CurBB
argument_list|(
name|CGF
operator|.
name|Builder
operator|.
name|GetInsertBlock
argument_list|()
argument_list|)
operator|,
name|CleanupEntryBB
argument_list|(
name|CGF
operator|.
name|createBasicBlock
argument_list|(
literal|"cleanup"
argument_list|)
argument_list|)
operator|,
name|CleanupExitBB
argument_list|(
literal|0
argument_list|)
block|{
name|CGF
operator|.
name|Builder
operator|.
name|SetInsertPoint
argument_list|(
name|CleanupEntryBB
argument_list|)
block|;     }
name|llvm
operator|::
name|BasicBlock
operator|*
name|getCleanupExitBlock
argument_list|()
block|{
if|if
condition|(
operator|!
name|CleanupExitBB
condition|)
name|CleanupExitBB
operator|=
name|CGF
operator|.
name|createBasicBlock
argument_list|(
literal|"cleanup.exit"
argument_list|)
expr_stmt|;
return|return
name|CleanupExitBB
return|;
block|}
operator|~
name|DelayedCleanupBlock
argument_list|()
block|{
name|CGF
operator|.
name|PushCleanupBlock
argument_list|(
name|CleanupEntryBB
argument_list|,
name|CleanupExitBB
argument_list|)
block|;
comment|// FIXME: This is silly, move this into the builder.
if|if
condition|(
name|CurBB
condition|)
name|CGF
operator|.
name|Builder
operator|.
name|SetInsertPoint
argument_list|(
name|CurBB
argument_list|)
expr_stmt|;
else|else
name|CGF
operator|.
name|Builder
operator|.
name|ClearInsertionPoint
argument_list|()
expr_stmt|;
block|}
block|}
empty_stmt|;
comment|/// \brief Enters a new scope for capturing cleanups, all of which will be
comment|/// executed once the scope is exited.
name|class
name|CleanupScope
block|{
name|CodeGenFunction
modifier|&
name|CGF
decl_stmt|;
name|size_t
name|CleanupStackDepth
decl_stmt|;
name|bool
name|OldDidCallStackSave
decl_stmt|;
name|bool
name|PerformCleanup
decl_stmt|;
name|CleanupScope
argument_list|(
specifier|const
name|CleanupScope
operator|&
argument_list|)
expr_stmt|;
comment|// DO NOT IMPLEMENT
name|CleanupScope
modifier|&
name|operator
init|=
operator|(
specifier|const
name|CleanupScope
operator|&
operator|)
decl_stmt|;
comment|// DO NOT IMPLEMENT
name|public
label|:
comment|/// \brief Enter a new cleanup scope.
name|explicit
name|CleanupScope
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
name|PerformCleanup
argument_list|(
argument|true
argument_list|)
block|{
name|CleanupStackDepth
operator|=
name|CGF
operator|.
name|CleanupEntries
operator|.
name|size
argument_list|()
block|;
name|OldDidCallStackSave
operator|=
name|CGF
operator|.
name|DidCallStackSave
block|;     }
comment|/// \brief Exit this cleanup scope, emitting any accumulated
comment|/// cleanups.
operator|~
name|CleanupScope
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
name|EmitCleanupBlocks
argument_list|(
name|CleanupStackDepth
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
name|CleanupEntries
operator|.
name|size
argument_list|()
operator|>
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
name|EmitCleanupBlocks
argument_list|(
name|CleanupStackDepth
argument_list|)
expr_stmt|;
name|PerformCleanup
operator|=
name|false
expr_stmt|;
block|}
block|}
empty_stmt|;
comment|/// EmitCleanupBlocks - Takes the old cleanup stack size and emits the cleanup
comment|/// blocks that have been added.
name|void
name|EmitCleanupBlocks
parameter_list|(
name|size_t
name|OldCleanupStackSize
parameter_list|)
function_decl|;
comment|/// EmitBranchThroughCleanup - Emit a branch from the current insert block
comment|/// through the cleanup handling code (if any) and then on to \arg Dest.
comment|///
comment|/// FIXME: Maybe this should really be in EmitBranch? Don't we always want
comment|/// this behavior for branches?
name|void
name|EmitBranchThroughCleanup
argument_list|(
name|llvm
operator|::
name|BasicBlock
operator|*
name|Dest
argument_list|)
decl_stmt|;
comment|/// StartConditionalBranch - Should be called before a conditional part of an
comment|/// expression is emitted. For example, before the RHS of the expression below
comment|/// is emitted:
comment|///
comment|/// b&& f(T());
comment|///
comment|/// This is used to make sure that any temporaries created in the conditional
comment|/// branch are only destroyed if the branch is taken.
name|void
name|StartConditionalBranch
parameter_list|()
block|{
operator|++
name|ConditionalBranchLevel
expr_stmt|;
block|}
comment|/// FinishConditionalBranch - Should be called after a conditional part of an
comment|/// expression has been emitted.
name|void
name|FinishConditionalBranch
parameter_list|()
block|{
operator|--
name|ConditionalBranchLevel
expr_stmt|;
block|}
name|private
label|:
name|CGDebugInfo
modifier|*
name|DebugInfo
decl_stmt|;
comment|/// IndirectBranch - The first time an indirect goto is seen we create a block
comment|/// with an indirect branch.  Every time we see the address of a label taken,
comment|/// we add the label to the indirect goto.  Every subsequent indirect goto is
comment|/// codegen'd as a jump to the IndirectBranch's basic block.
name|llvm
operator|::
name|IndirectBrInst
operator|*
name|IndirectBranch
expr_stmt|;
comment|/// LocalDeclMap - This keeps track of the LLVM allocas or globals for local C
comment|/// decls.
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
name|LocalDeclMap
expr_stmt|;
comment|/// LabelMap - This keeps track of the LLVM basic block for each C label.
name|llvm
operator|::
name|DenseMap
operator|<
specifier|const
name|LabelStmt
operator|*
operator|,
name|llvm
operator|::
name|BasicBlock
operator|*
operator|>
name|LabelMap
expr_stmt|;
comment|// BreakContinueStack - This keeps track of where break and continue
comment|// statements should jump to.
struct|struct
name|BreakContinue
block|{
name|BreakContinue
argument_list|(
name|llvm
operator|::
name|BasicBlock
operator|*
name|bb
argument_list|,
name|llvm
operator|::
name|BasicBlock
operator|*
name|cb
argument_list|)
operator|:
name|BreakBlock
argument_list|(
name|bb
argument_list|)
operator|,
name|ContinueBlock
argument_list|(
argument|cb
argument_list|)
block|{}
name|llvm
operator|::
name|BasicBlock
operator|*
name|BreakBlock
expr_stmt|;
name|llvm
operator|::
name|BasicBlock
operator|*
name|ContinueBlock
expr_stmt|;
block|}
struct|;
name|llvm
operator|::
name|SmallVector
operator|<
name|BreakContinue
operator|,
literal|8
operator|>
name|BreakContinueStack
expr_stmt|;
comment|/// SwitchInsn - This is nearest current switch instruction. It is null if if
comment|/// current context is not in a switch.
name|llvm
operator|::
name|SwitchInst
operator|*
name|SwitchInsn
expr_stmt|;
comment|/// CaseRangeBlock - This block holds if condition check for last case
comment|/// statement range in current switch instruction.
name|llvm
operator|::
name|BasicBlock
operator|*
name|CaseRangeBlock
expr_stmt|;
comment|/// InvokeDest - This is the nearest exception target for calls
comment|/// which can unwind, when exceptions are being used.
name|llvm
operator|::
name|BasicBlock
operator|*
name|InvokeDest
expr_stmt|;
comment|// VLASizeMap - This keeps track of the associated size for each VLA type.
comment|// We track this by the size expression rather than the type itself because
comment|// in certain situations, like a const qualifier applied to an VLA typedef,
comment|// multiple VLA types can share the same size expression.
comment|// FIXME: Maybe this could be a stack of maps that is pushed/popped as we
comment|// enter/leave scopes.
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
comment|/// DidCallStackSave - Whether llvm.stacksave has been called. Used to avoid
comment|/// calling llvm.stacksave for multiple VLAs in the same scope.
name|bool
name|DidCallStackSave
decl_stmt|;
struct|struct
name|CleanupEntry
block|{
comment|/// CleanupEntryBlock - The block of code that does the actual cleanup.
name|llvm
operator|::
name|BasicBlock
operator|*
name|CleanupEntryBlock
expr_stmt|;
comment|/// CleanupExitBlock - The cleanup exit block.
name|llvm
operator|::
name|BasicBlock
operator|*
name|CleanupExitBlock
expr_stmt|;
comment|/// Blocks - Basic blocks that were emitted in the current cleanup scope.
name|std
operator|::
name|vector
operator|<
name|llvm
operator|::
name|BasicBlock
operator|*
operator|>
name|Blocks
expr_stmt|;
comment|/// BranchFixups - Branch instructions to basic blocks that haven't been
comment|/// inserted into the current function yet.
name|std
operator|::
name|vector
operator|<
name|llvm
operator|::
name|BranchInst
operator|*
operator|>
name|BranchFixups
expr_stmt|;
name|explicit
name|CleanupEntry
argument_list|(
name|llvm
operator|::
name|BasicBlock
operator|*
name|CleanupEntryBlock
argument_list|,
name|llvm
operator|::
name|BasicBlock
operator|*
name|CleanupExitBlock
argument_list|)
range|:
name|CleanupEntryBlock
argument_list|(
name|CleanupEntryBlock
argument_list|)
decl_stmt|,
name|CleanupExitBlock
argument_list|(
name|CleanupExitBlock
argument_list|)
block|{}
block|}
struct|;
comment|/// CleanupEntries - Stack of cleanup entries.
name|llvm
operator|::
name|SmallVector
operator|<
name|CleanupEntry
operator|,
literal|8
operator|>
name|CleanupEntries
expr_stmt|;
typedef|typedef
name|llvm
operator|::
name|DenseMap
operator|<
name|llvm
operator|::
name|BasicBlock
operator|*
operator|,
name|size_t
operator|>
name|BlockScopeMap
expr_stmt|;
comment|/// BlockScopes - Map of which "cleanup scope" scope basic blocks have.
name|BlockScopeMap
name|BlockScopes
decl_stmt|;
comment|/// CXXThisDecl - When generating code for a C++ member function,
comment|/// this will hold the implicit 'this' declaration.
name|ImplicitParamDecl
modifier|*
name|CXXThisDecl
decl_stmt|;
comment|/// CXXVTTDecl - When generating code for a base object constructor or
comment|/// base object destructor with virtual bases, this will hold the implicit
comment|/// VTT parameter.
name|ImplicitParamDecl
modifier|*
name|CXXVTTDecl
decl_stmt|;
comment|/// CXXLiveTemporaryInfo - Holds information about a live C++ temporary.
struct|struct
name|CXXLiveTemporaryInfo
block|{
comment|/// Temporary - The live temporary.
specifier|const
name|CXXTemporary
modifier|*
name|Temporary
decl_stmt|;
comment|/// ThisPtr - The pointer to the temporary.
name|llvm
operator|::
name|Value
operator|*
name|ThisPtr
expr_stmt|;
comment|/// DtorBlock - The destructor block.
name|llvm
operator|::
name|BasicBlock
operator|*
name|DtorBlock
expr_stmt|;
comment|/// CondPtr - If this is a conditional temporary, this is the pointer to the
comment|/// condition variable that states whether the destructor should be called
comment|/// or not.
name|llvm
operator|::
name|Value
operator|*
name|CondPtr
expr_stmt|;
name|CXXLiveTemporaryInfo
argument_list|(
specifier|const
name|CXXTemporary
operator|*
name|temporary
argument_list|,
name|llvm
operator|::
name|Value
operator|*
name|thisptr
argument_list|,
name|llvm
operator|::
name|BasicBlock
operator|*
name|dtorblock
argument_list|,
name|llvm
operator|::
name|Value
operator|*
name|condptr
argument_list|)
operator|:
name|Temporary
argument_list|(
name|temporary
argument_list|)
operator|,
name|ThisPtr
argument_list|(
name|thisptr
argument_list|)
operator|,
name|DtorBlock
argument_list|(
name|dtorblock
argument_list|)
operator|,
name|CondPtr
argument_list|(
argument|condptr
argument_list|)
block|{ }
block|}
struct|;
name|llvm
operator|::
name|SmallVector
operator|<
name|CXXLiveTemporaryInfo
operator|,
literal|4
operator|>
name|LiveTemporaries
expr_stmt|;
comment|/// ConditionalBranchLevel - Contains the nesting level of the current
comment|/// conditional branch. This is used so that we know if a temporary should be
comment|/// destroyed conditionally.
name|unsigned
name|ConditionalBranchLevel
decl_stmt|;
comment|/// ByrefValueInfoMap - For each __block variable, contains a pair of the LLVM
comment|/// type as well as the field number that contains the actual data.
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
specifier|const
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
comment|/// getByrefValueFieldNumber - Given a declaration, returns the LLVM field
comment|/// number that holds the value.
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
name|public
label|:
name|CodeGenFunction
argument_list|(
name|CodeGenModule
operator|&
name|cgm
argument_list|)
expr_stmt|;
name|ASTContext
operator|&
name|getContext
argument_list|()
specifier|const
expr_stmt|;
name|CGDebugInfo
modifier|*
name|getDebugInfo
parameter_list|()
block|{
return|return
name|DebugInfo
return|;
block|}
name|llvm
operator|::
name|BasicBlock
operator|*
name|getInvokeDest
argument_list|()
block|{
return|return
name|InvokeDest
return|;
block|}
name|void
name|setInvokeDest
argument_list|(
name|llvm
operator|::
name|BasicBlock
operator|*
name|B
argument_list|)
block|{
name|InvokeDest
operator|=
name|B
expr_stmt|;
block|}
name|llvm
operator|::
name|LLVMContext
operator|&
name|getLLVMContext
argument_list|()
block|{
return|return
name|VMContext
return|;
block|}
comment|//===--------------------------------------------------------------------===//
comment|//                                  Objective-C
comment|//===--------------------------------------------------------------------===//
name|void
name|GenerateObjCMethod
parameter_list|(
specifier|const
name|ObjCMethodDecl
modifier|*
name|OMD
parameter_list|)
function_decl|;
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
comment|/// GenerateObjCGetter - Synthesize an Objective-C property getter function.
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
comment|/// GenerateObjCSetter - Synthesize an Objective-C property setter function
comment|/// for the given property.
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
comment|//===--------------------------------------------------------------------===//
comment|//                                  Block Bits
comment|//===--------------------------------------------------------------------===//
name|llvm
operator|::
name|Value
operator|*
name|BuildBlockLiteralTmp
argument_list|(
specifier|const
name|BlockExpr
operator|*
argument_list|)
expr_stmt|;
name|llvm
operator|::
name|Constant
operator|*
name|BuildDescriptorBlockDecl
argument_list|(
argument|bool BlockHasCopyDispose
argument_list|,
argument|uint64_t Size
argument_list|,
argument|const llvm::StructType *
argument_list|,
argument|std::vector<HelperInfo> *
argument_list|)
expr_stmt|;
name|llvm
operator|::
name|Function
operator|*
name|GenerateBlockFunction
argument_list|(
specifier|const
name|BlockExpr
operator|*
name|BExpr
argument_list|,
specifier|const
name|BlockInfo
operator|&
name|Info
argument_list|,
specifier|const
name|Decl
operator|*
name|OuterFuncDecl
argument_list|,
name|llvm
operator|::
name|DenseMap
operator|<
specifier|const
name|Decl
operator|*
argument_list|,
name|llvm
operator|::
name|Value
operator|*
operator|>
name|ldm
argument_list|,
name|uint64_t
operator|&
name|Size
argument_list|,
name|uint64_t
operator|&
name|Align
argument_list|,
name|llvm
operator|::
name|SmallVector
operator|<
specifier|const
name|Expr
operator|*
argument_list|,
literal|8
operator|>
operator|&
name|subBlockDeclRefDecls
argument_list|,
name|bool
operator|&
name|subBlockHasCopyDispose
argument_list|)
expr_stmt|;
name|void
name|BlockForwardSelf
parameter_list|()
function_decl|;
name|llvm
operator|::
name|Value
operator|*
name|LoadBlockStruct
argument_list|()
expr_stmt|;
name|uint64_t
name|AllocateBlockDecl
parameter_list|(
specifier|const
name|BlockDeclRefExpr
modifier|*
name|E
parameter_list|)
function_decl|;
name|llvm
operator|::
name|Value
operator|*
name|GetAddrOfBlockDecl
argument_list|(
specifier|const
name|BlockDeclRefExpr
operator|*
name|E
argument_list|)
expr_stmt|;
specifier|const
name|llvm
operator|::
name|Type
operator|*
name|BuildByRefType
argument_list|(
specifier|const
name|ValueDecl
operator|*
name|D
argument_list|)
expr_stmt|;
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
argument_list|)
decl_stmt|;
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
name|FunctionArgList
operator|&
name|Args
argument_list|,
name|SourceLocation
name|StartLoc
argument_list|)
decl_stmt|;
comment|/// EmitReturnBlock - Emit the unified return block, trying to avoid its
comment|/// emission when possible.
name|void
name|EmitReturnBlock
parameter_list|()
function_decl|;
comment|/// FinishFunction - Complete IR generation of the current function. It is
comment|/// legal to call this function even if there is no current insertion point.
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
comment|/// DynamicTypeAdjust - Do the non-virtual and virtual adjustments on an
comment|/// object pointer to alter the dynamic type of the pointer.  Used by
comment|/// GenerateCovariantThunk for building thunks.
name|llvm
operator|::
name|Value
operator|*
name|DynamicTypeAdjust
argument_list|(
name|llvm
operator|::
name|Value
operator|*
name|V
argument_list|,
specifier|const
name|ThunkAdjustment
operator|&
name|Adjustment
argument_list|)
expr_stmt|;
comment|/// GenerateThunk - Generate a thunk for the given method
name|llvm
operator|::
name|Constant
operator|*
name|GenerateThunk
argument_list|(
argument|llvm::Function *Fn
argument_list|,
argument|const CXXMethodDecl *MD
argument_list|,
argument|bool Extern
argument_list|,
argument|const ThunkAdjustment&ThisAdjustment
argument_list|)
expr_stmt|;
name|llvm
operator|::
name|Constant
operator|*
name|GenerateCovariantThunk
argument_list|(
argument|llvm::Function *Fn
argument_list|,
argument|const CXXMethodDecl *MD
argument_list|,
argument|bool Extern
argument_list|,
argument|const CovariantThunkAdjustment&Adjustment
argument_list|)
expr_stmt|;
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
parameter_list|)
function_decl|;
name|void
name|SynthesizeCXXCopyConstructor
argument_list|(
specifier|const
name|CXXConstructorDecl
operator|*
name|Ctor
argument_list|,
name|CXXCtorType
name|Type
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
name|void
name|SynthesizeCXXCopyAssignment
argument_list|(
specifier|const
name|CXXMethodDecl
operator|*
name|CD
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
name|void
name|SynthesizeDefaultConstructor
argument_list|(
specifier|const
name|CXXConstructorDecl
operator|*
name|Ctor
argument_list|,
name|CXXCtorType
name|Type
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
name|void
name|SynthesizeDefaultDestructor
argument_list|(
specifier|const
name|CXXDestructorDecl
operator|*
name|Dtor
argument_list|,
name|CXXDtorType
name|Type
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
comment|/// EmitDtorEpilogue - Emit all code that comes at the end of class's
comment|/// destructor. This is to call destructors on members and base classes in
comment|/// reverse order of their construction.
name|void
name|EmitDtorEpilogue
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
comment|/// EmitFunctionProlog - Emit the target specific LLVM code to load the
comment|/// arguments for the given function. This is also responsible for naming the
comment|/// LLVM function arguments.
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
comment|/// EmitFunctionEpilog - Emit the target specific LLVM code to return the
comment|/// given temporary.
name|void
name|EmitFunctionEpilog
argument_list|(
specifier|const
name|CGFunctionInfo
operator|&
name|FI
argument_list|,
name|llvm
operator|::
name|Value
operator|*
name|ReturnValue
argument_list|)
decl_stmt|;
specifier|const
name|llvm
operator|::
name|Type
operator|*
name|ConvertTypeForMem
argument_list|(
argument|QualType T
argument_list|)
expr_stmt|;
specifier|const
name|llvm
operator|::
name|Type
operator|*
name|ConvertType
argument_list|(
argument|QualType T
argument_list|)
expr_stmt|;
comment|/// LoadObjCSelf - Load the value of self. This function is only valid while
comment|/// generating code for an Objective-C method.
name|llvm
operator|::
name|Value
operator|*
name|LoadObjCSelf
argument_list|()
expr_stmt|;
comment|/// TypeOfSelfObject - Return type of object that this self represents.
name|QualType
name|TypeOfSelfObject
parameter_list|()
function_decl|;
comment|/// hasAggregateLLVMType - Return true if the specified AST type will map into
comment|/// an aggregate LLVM type or is void.
specifier|static
name|bool
name|hasAggregateLLVMType
parameter_list|(
name|QualType
name|T
parameter_list|)
function_decl|;
comment|/// createBasicBlock - Create an LLVM basic block.
name|llvm
operator|::
name|BasicBlock
operator|*
name|createBasicBlock
argument_list|(
argument|const char *Name=
literal|""
argument_list|,
argument|llvm::Function *Parent=
literal|0
argument_list|,
argument|llvm::BasicBlock *InsertBefore=
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
name|VMContext
argument_list|,
literal|""
argument_list|,
name|Parent
argument_list|,
name|InsertBefore
argument_list|)
return|;
else|#
directive|else
return|return
name|llvm
operator|::
name|BasicBlock
operator|::
name|Create
argument_list|(
name|VMContext
argument_list|,
name|Name
argument_list|,
name|Parent
argument_list|,
name|InsertBefore
argument_list|)
return|;
endif|#
directive|endif
block|}
end_decl_stmt

begin_comment
comment|/// getBasicBlockForLabel - Return the LLVM basicblock that the specified
end_comment

begin_comment
comment|/// label maps to.
end_comment

begin_expr_stmt
name|llvm
operator|::
name|BasicBlock
operator|*
name|getBasicBlockForLabel
argument_list|(
specifier|const
name|LabelStmt
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
parameter_list|,
name|bool
name|OmitOnError
init|=
name|false
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
name|Qualifiers
name|MakeQualifiers
parameter_list|(
name|QualType
name|T
parameter_list|)
block|{
name|Qualifiers
name|Quals
init|=
name|getContext
argument_list|()
operator|.
name|getCanonicalType
argument_list|(
name|T
argument_list|)
operator|.
name|getQualifiers
argument_list|()
decl_stmt|;
name|Quals
operator|.
name|setObjCGCAttr
argument_list|(
name|getContext
argument_list|()
operator|.
name|getObjCGCAttrKind
argument_list|(
name|T
argument_list|)
argument_list|)
expr_stmt|;
return|return
name|Quals
return|;
block|}
end_function

begin_comment
comment|/// CreateTempAlloca - This creates a alloca and inserts it into the entry
end_comment

begin_comment
comment|/// block.
end_comment

begin_expr_stmt
name|llvm
operator|::
name|AllocaInst
operator|*
name|CreateTempAlloca
argument_list|(
specifier|const
name|llvm
operator|::
name|Type
operator|*
name|Ty
argument_list|,
specifier|const
name|llvm
operator|::
name|Twine
operator|&
name|Name
operator|=
literal|"tmp"
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
comment|/// \param IgnoreResult - True if the resulting value isn't used.
end_comment

begin_decl_stmt
name|RValue
name|EmitAnyExpr
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
name|AggLoc
operator|=
literal|0
argument_list|,
name|bool
name|IsAggLocVolatile
operator|=
name|false
argument_list|,
name|bool
name|IgnoreResult
operator|=
name|false
argument_list|,
name|bool
name|IsInitializer
operator|=
name|false
argument_list|)
decl_stmt|;
end_decl_stmt

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
parameter_list|,
name|bool
name|IsAggLocVolatile
init|=
name|false
parameter_list|,
name|bool
name|IsInitializer
init|=
name|false
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// EmitAggregateCopy - Emit an aggrate copy.
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
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|EmitAggregateClear
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
comment|/// GetAddrOfStaticLocalVar - Return the address of a static local variable.
end_comment

begin_expr_stmt
name|llvm
operator|::
name|Constant
operator|*
name|GetAddrOfStaticLocalVar
argument_list|(
specifier|const
name|VarDecl
operator|*
name|BVD
argument_list|)
expr_stmt|;
end_expr_stmt

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
specifier|const
name|VarDecl
operator|*
name|VD
argument_list|)
expr_stmt|;
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
name|LabelStmt
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
comment|/// EmitMemSetToZero - Generate code to memset a value of the given type to 0.
end_comment

begin_decl_stmt
name|void
name|EmitMemSetToZero
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
comment|/// EmitVLASize - Generate code for any VLA size expressions that might occur
end_comment

begin_comment
comment|/// in a variably modified type. If Ty is a VLA, will return the value that
end_comment

begin_comment
comment|/// corresponds to the size in bytes of the VLA type. Will return 0 otherwise.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This function can be called with a null (unreachable) insert point.
end_comment

begin_expr_stmt
name|llvm
operator|::
name|Value
operator|*
name|EmitVLASize
argument_list|(
argument|QualType Ty
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|// GetVLASize - Returns an LLVM value that corresponds to the size in bytes
end_comment

begin_comment
comment|// of a variable length array type.
end_comment

begin_expr_stmt
name|llvm
operator|::
name|Value
operator|*
name|GetVLASize
argument_list|(
specifier|const
name|VariableArrayType
operator|*
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
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// GetAddressOfBaseClass - This function will add the necessary delta to the
end_comment

begin_comment
comment|/// load of 'this' and returns address of the base class.
end_comment

begin_comment
comment|// FIXME. This currently only does a derived to non-virtual base conversion.
end_comment

begin_comment
comment|// Other kinds of conversions will come later.
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
argument|const CXXRecordDecl *ClassDecl
argument_list|,
argument|const CXXRecordDecl *BaseClassDecl
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
argument|const CXXRecordDecl *ClassDecl
argument_list|,
argument|const CXXRecordDecl *DerivedClassDecl
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
name|GetVirtualCXXBaseClassOffset
argument_list|(
name|llvm
operator|::
name|Value
operator|*
name|This
argument_list|,
specifier|const
name|CXXRecordDecl
operator|*
name|ClassDecl
argument_list|,
specifier|const
name|CXXRecordDecl
operator|*
name|BaseClassDecl
argument_list|)
expr_stmt|;
end_expr_stmt

begin_decl_stmt
name|void
name|EmitClassAggrMemberwiseCopy
argument_list|(
name|llvm
operator|::
name|Value
operator|*
name|DestValue
argument_list|,
name|llvm
operator|::
name|Value
operator|*
name|SrcValue
argument_list|,
specifier|const
name|ArrayType
operator|*
name|Array
argument_list|,
specifier|const
name|CXXRecordDecl
operator|*
name|BaseClassDecl
argument_list|,
name|QualType
name|Ty
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|EmitClassAggrCopyAssignment
argument_list|(
name|llvm
operator|::
name|Value
operator|*
name|DestValue
argument_list|,
name|llvm
operator|::
name|Value
operator|*
name|SrcValue
argument_list|,
specifier|const
name|ArrayType
operator|*
name|Array
argument_list|,
specifier|const
name|CXXRecordDecl
operator|*
name|BaseClassDecl
argument_list|,
name|QualType
name|Ty
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|EmitClassMemberwiseCopy
argument_list|(
name|llvm
operator|::
name|Value
operator|*
name|DestValue
argument_list|,
name|llvm
operator|::
name|Value
operator|*
name|SrcValue
argument_list|,
specifier|const
name|CXXRecordDecl
operator|*
name|ClassDecl
argument_list|,
specifier|const
name|CXXRecordDecl
operator|*
name|BaseClassDecl
argument_list|,
name|QualType
name|Ty
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|EmitClassCopyAssignment
argument_list|(
name|llvm
operator|::
name|Value
operator|*
name|DestValue
argument_list|,
name|llvm
operator|::
name|Value
operator|*
name|SrcValue
argument_list|,
specifier|const
name|CXXRecordDecl
operator|*
name|ClassDecl
argument_list|,
specifier|const
name|CXXRecordDecl
operator|*
name|BaseClassDecl
argument_list|,
name|QualType
name|Ty
argument_list|)
decl_stmt|;
end_decl_stmt

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
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|EmitCXXAggrDestructorCall
argument_list|(
specifier|const
name|CXXDestructorDecl
operator|*
name|D
argument_list|,
specifier|const
name|ArrayType
operator|*
name|Array
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
name|EmitCXXAggrDestructorCall
argument_list|(
specifier|const
name|CXXDestructorDecl
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
name|This
argument_list|)
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|llvm
operator|::
name|Constant
operator|*
name|GenerateCXXAggrDestructorHelper
argument_list|(
specifier|const
name|CXXDestructorDecl
operator|*
name|D
argument_list|,
specifier|const
name|ArrayType
operator|*
name|Array
argument_list|,
name|llvm
operator|::
name|Value
operator|*
name|This
argument_list|)
expr_stmt|;
end_expr_stmt

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
name|PushCXXTemporary
argument_list|(
specifier|const
name|CXXTemporary
operator|*
name|Temporary
argument_list|,
name|llvm
operator|::
name|Value
operator|*
name|Ptr
argument_list|)
decl_stmt|;
end_decl_stmt

begin_function_decl
name|void
name|PopCXXTemporary
parameter_list|()
function_decl|;
end_function_decl

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
comment|/// EmitBlockVarDecl - Emit a block variable declaration.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This function can be called with a null (unreachable) insert point.
end_comment

begin_function_decl
name|void
name|EmitBlockVarDecl
parameter_list|(
specifier|const
name|VarDecl
modifier|&
name|D
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// EmitLocalBlockVarDecl - Emit a local block variable declaration.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This function can be called with a null (unreachable) insert point.
end_comment

begin_function_decl
name|void
name|EmitLocalBlockVarDecl
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
name|EmitStaticBlockVarDecl
parameter_list|(
specifier|const
name|VarDecl
modifier|&
name|D
parameter_list|)
function_decl|;
end_function_decl

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
argument_list|)
decl_stmt|;
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

begin_decl_stmt
name|RValue
name|EmitCompoundStmt
argument_list|(
specifier|const
name|CompoundStmt
operator|&
name|S
argument_list|,
name|bool
name|GetLast
operator|=
name|false
argument_list|,
name|llvm
operator|::
name|Value
operator|*
name|AggLoc
operator|=
literal|0
argument_list|,
name|bool
name|isAggVol
operator|=
name|false
argument_list|)
decl_stmt|;
end_decl_stmt

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
name|LabelStmt
modifier|&
name|S
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
name|EmitCXXTryStmt
parameter_list|(
specifier|const
name|CXXTryStmt
modifier|&
name|S
parameter_list|)
function_decl|;
end_function_decl

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
argument|QualType Ty
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
name|QualType
name|Ty
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
name|QualType
name|LVType
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|RValue
name|EmitLoadOfExtVectorElementLValue
parameter_list|(
name|LValue
name|V
parameter_list|,
name|QualType
name|LVType
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
name|QualType
name|ExprType
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|RValue
name|EmitLoadOfPropertyRefLValue
parameter_list|(
name|LValue
name|LV
parameter_list|,
name|QualType
name|ExprType
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|RValue
name|EmitLoadOfKVCRefLValue
parameter_list|(
name|LValue
name|LV
parameter_list|,
name|QualType
name|ExprType
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
name|QualType
name|Ty
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
parameter_list|,
name|QualType
name|Ty
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|EmitStoreThroughPropertyRefLValue
parameter_list|(
name|RValue
name|Src
parameter_list|,
name|LValue
name|Dst
parameter_list|,
name|QualType
name|Ty
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|EmitStoreThroughKVCRefLValue
parameter_list|(
name|RValue
name|Src
parameter_list|,
name|LValue
name|Dst
parameter_list|,
name|QualType
name|Ty
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// EmitStoreThroughLValue - Store Src into Dst with same constraints as
end_comment

begin_comment
comment|/// EmitStoreThroughLValue.
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
name|QualType
name|Ty
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
comment|// Note: only availabe for agg return types
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
name|EmitPredefinedFunctionName
parameter_list|(
name|unsigned
name|Type
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
name|EmitConditionalOperatorLValue
parameter_list|(
specifier|const
name|ConditionalOperator
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
name|EmitNullInitializationLValue
parameter_list|(
specifier|const
name|CXXZeroInitValueExpr
modifier|*
name|E
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|LValue
name|EmitPointerToDataMemberLValue
parameter_list|(
specifier|const
name|FieldDecl
modifier|*
name|Field
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

begin_decl_stmt
name|LValue
name|EmitLValueForField
argument_list|(
name|llvm
operator|::
name|Value
operator|*
name|Base
argument_list|,
specifier|const
name|FieldDecl
operator|*
name|Field
argument_list|,
name|bool
name|isUnion
argument_list|,
name|unsigned
name|CVRQualifiers
argument_list|)
decl_stmt|;
end_decl_stmt

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

begin_decl_stmt
name|LValue
name|EmitLValueForBitfield
argument_list|(
name|llvm
operator|::
name|Value
operator|*
name|Base
argument_list|,
specifier|const
name|FieldDecl
operator|*
name|Field
argument_list|,
name|unsigned
name|CVRQualifiers
argument_list|)
decl_stmt|;
end_decl_stmt

begin_function_decl
name|LValue
name|EmitBlockDeclRefLValue
parameter_list|(
specifier|const
name|BlockDeclRefExpr
modifier|*
name|E
parameter_list|)
function_decl|;
end_function_decl

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
name|EmitCXXExprWithTemporariesLValue
parameter_list|(
specifier|const
name|CXXExprWithTemporaries
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
name|EmitObjCPropertyRefLValue
parameter_list|(
specifier|const
name|ObjCPropertyRefExpr
modifier|*
name|E
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|LValue
name|EmitObjCKVCRefLValue
parameter_list|(
specifier|const
name|ObjCImplicitSetterGetterRefExpr
modifier|*
name|E
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|LValue
name|EmitObjCSuperExprLValue
parameter_list|(
specifier|const
name|ObjCSuperExpr
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
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|RValue
name|EmitCall
argument_list|(
name|llvm
operator|::
name|Value
operator|*
name|Callee
argument_list|,
name|QualType
name|FnType
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
parameter_list|)
function_decl|;
end_function_decl

begin_expr_stmt
name|llvm
operator|::
name|Value
operator|*
name|BuildVirtualCall
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
name|This
argument_list|,
specifier|const
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
name|BuildVirtualCall
argument_list|(
argument|const CXXDestructorDecl *DD
argument_list|,
argument|CXXDtorType Type
argument_list|,
argument|llvm::Value *&This
argument_list|,
argument|const llvm::Type *Ty
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
name|llvm
operator|::
name|Value
operator|*
name|Callee
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

begin_function_decl
name|RValue
name|EmitCXXMemberCallExpr
parameter_list|(
specifier|const
name|CXXMemberCallExpr
modifier|*
name|E
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
name|EmitShuffleVector
argument_list|(
name|llvm
operator|::
name|Value
operator|*
name|V1
argument_list|,
name|llvm
operator|::
name|Value
operator|*
name|V2
argument_list|,
operator|...
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|llvm
operator|::
name|Value
operator|*
name|EmitVector
argument_list|(
argument|llvm::Value * const *Vals
argument_list|,
argument|unsigned NumVals
argument_list|,
argument|bool isSplat = false
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
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|RValue
name|EmitObjCPropertyGet
parameter_list|(
specifier|const
name|Expr
modifier|*
name|E
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|RValue
name|EmitObjCSuperPropertyGet
parameter_list|(
specifier|const
name|Expr
modifier|*
name|Exp
parameter_list|,
specifier|const
name|Selector
modifier|&
name|S
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|EmitObjCPropertySet
parameter_list|(
specifier|const
name|Expr
modifier|*
name|E
parameter_list|,
name|RValue
name|Src
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|EmitObjCSuperPropertySet
parameter_list|(
specifier|const
name|Expr
modifier|*
name|E
parameter_list|,
specifier|const
name|Selector
modifier|&
name|S
parameter_list|,
name|RValue
name|Src
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// EmitReferenceBindingToExpr - Emits a reference binding to the passed in
end_comment

begin_comment
comment|/// expression. Will emit a temporary variable if E is not an LValue.
end_comment

begin_function_decl
name|RValue
name|EmitReferenceBindingToExpr
parameter_list|(
specifier|const
name|Expr
modifier|*
name|E
parameter_list|,
name|QualType
name|DestType
parameter_list|,
name|bool
name|IsInitializer
init|=
name|false
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
comment|/// EmitAggExpr - Emit the computation of the specified expression of
end_comment

begin_comment
comment|/// aggregate type.  The result is computed into DestPtr.  Note that if
end_comment

begin_comment
comment|/// DestPtr is null, the value of the aggregate expression is not needed.
end_comment

begin_decl_stmt
name|void
name|EmitAggExpr
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
name|DestPtr
argument_list|,
name|bool
name|VolatileDest
argument_list|,
name|bool
name|IgnoreResult
operator|=
name|false
argument_list|,
name|bool
name|IsInitializer
operator|=
name|false
argument_list|,
name|bool
name|RequiresGCollection
operator|=
name|false
argument_list|)
decl_stmt|;
end_decl_stmt

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
parameter_list|,
name|bool
name|IgnoreRealAssign
init|=
name|false
parameter_list|,
name|bool
name|IgnoreImagAssign
init|=
name|false
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// EmitComplexExprIntoAddr - Emit the computation of the specified expression
end_comment

begin_comment
comment|/// of complex type, storing into the specified Value*.
end_comment

begin_decl_stmt
name|void
name|EmitComplexExprIntoAddr
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
name|DestAddr
argument_list|,
name|bool
name|DestIsVolatile
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// StoreComplexToAddr - Store a complex number into the specified address.
end_comment

begin_decl_stmt
name|void
name|StoreComplexToAddr
argument_list|(
name|ComplexPairTy
name|V
argument_list|,
name|llvm
operator|::
name|Value
operator|*
name|DestAddr
argument_list|,
name|bool
name|DestIsVolatile
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// LoadComplexFromAddr - Load a complex number from the specified address.
end_comment

begin_decl_stmt
name|ComplexPairTy
name|LoadComplexFromAddr
argument_list|(
name|llvm
operator|::
name|Value
operator|*
name|SrcAddr
argument_list|,
name|bool
name|SrcIsVolatile
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// CreateStaticBlockVarDecl - Create a zero-initialized LLVM global for a
end_comment

begin_comment
comment|/// static block var decl.
end_comment

begin_expr_stmt
name|llvm
operator|::
name|GlobalVariable
operator|*
name|CreateStaticBlockVarDecl
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
comment|/// EmitStaticCXXBlockVarDeclInit - Create the initializer for a C++ runtime
end_comment

begin_comment
comment|/// initialized static block var decl.
end_comment

begin_decl_stmt
name|void
name|EmitStaticCXXBlockVarDeclInit
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
decl_stmt|;
end_decl_stmt

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
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// EmitCXXGlobalDtorRegistration - Emits a call to register the global ptr
end_comment

begin_comment
comment|/// with the C++ runtime so that its destructor will be called at exit.
end_comment

begin_decl_stmt
name|void
name|EmitCXXGlobalDtorRegistration
argument_list|(
name|llvm
operator|::
name|Constant
operator|*
name|DtorFn
argument_list|,
name|llvm
operator|::
name|Constant
operator|*
name|DeclPtr
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
specifier|const
name|VarDecl
operator|*
operator|*
name|Decls
argument_list|,
name|unsigned
name|NumDecls
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|EmitCXXConstructExpr
argument_list|(
name|llvm
operator|::
name|Value
operator|*
name|Dest
argument_list|,
specifier|const
name|CXXConstructExpr
operator|*
name|E
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|RValue
name|EmitCXXExprWithTemporaries
argument_list|(
specifier|const
name|CXXExprWithTemporaries
operator|*
name|E
argument_list|,
name|llvm
operator|::
name|Value
operator|*
name|AggLoc
operator|=
literal|0
argument_list|,
name|bool
name|IsAggLocVolatile
operator|=
name|false
argument_list|,
name|bool
name|IsInitializer
operator|=
name|false
argument_list|)
decl_stmt|;
end_decl_stmt

begin_function_decl
name|void
name|EmitCXXThrowExpr
parameter_list|(
specifier|const
name|CXXThrowExpr
modifier|*
name|E
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
comment|/// ConstantFoldsToSimpleInteger - If the specified expression does not fold
end_comment

begin_comment
comment|/// to a constant, or if it does but contains a label, return 0.  If it
end_comment

begin_comment
comment|/// constant folds to 'true' and does not contain a label, return 1, if it
end_comment

begin_comment
comment|/// constant folds to 'false' and does not contain a label, return -1.
end_comment

begin_function_decl
name|int
name|ConstantFoldsToSimpleInteger
parameter_list|(
specifier|const
name|Expr
modifier|*
name|Cond
parameter_list|)
function_decl|;
end_function_decl

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

begin_label
name|private
label|:
end_label

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
name|llvm
operator|::
name|SmallVector
operator|<
name|llvm
operator|::
name|Value
operator|*
argument_list|,
literal|16
operator|>
operator|&
name|Args
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
name|AsmStmt
operator|&
name|S
argument_list|,
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

begin_comment
comment|/// EmitCleanupBlock - emits a single cleanup block.
end_comment

begin_function_decl
name|void
name|EmitCleanupBlock
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/// AddBranchFixup - adds a branch instruction to the list of fixups for the
end_comment

begin_comment
comment|/// current cleanup scope.
end_comment

begin_decl_stmt
name|void
name|AddBranchFixup
argument_list|(
name|llvm
operator|::
name|BranchInst
operator|*
name|BI
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// EmitCallArg - Emit a single call argument.
end_comment

begin_function_decl
name|RValue
name|EmitCallArg
parameter_list|(
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
argument_list|)
block|{
name|CallExpr
operator|::
name|const_arg_iterator
name|Arg
operator|=
name|ArgBeg
block|;
comment|// First, use the argument types that the type info knows about
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
name|Arg
operator|->
name|getType
argument_list|()
argument_list|)
operator|.
name|getTypePtr
argument_list|()
operator|&&
literal|"type mismatch in call argument!"
argument_list|)
expr_stmt|;
name|Args
operator|.
name|push_back
argument_list|(
name|std
operator|::
name|make_pair
argument_list|(
name|EmitCallArg
argument_list|(
operator|*
name|Arg
argument_list|,
name|ArgType
argument_list|)
argument_list|,
name|ArgType
argument_list|)
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
end_expr_stmt

begin_comment
unit|}
comment|// If we still have any arguments, emit them using the type of the argument.
end_comment

begin_expr_stmt
unit|for
operator|(
expr|;
name|Arg
operator|!=
name|ArgEnd
expr|;
operator|++
name|Arg
operator|)
block|{
name|QualType
name|ArgType
operator|=
name|Arg
operator|->
name|getType
argument_list|()
block|;
name|Args
operator|.
name|push_back
argument_list|(
name|std
operator|::
name|make_pair
argument_list|(
name|EmitCallArg
argument_list|(
operator|*
name|Arg
argument_list|,
name|ArgType
argument_list|)
argument_list|,
name|ArgType
argument_list|)
argument_list|)
block|;     }
end_expr_stmt

begin_empty_stmt
unit|} }
empty_stmt|;
end_empty_stmt

begin_comment
unit|}
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

