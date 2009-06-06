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
name|Module
decl_stmt|;
name|class
name|SwitchInst
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
name|CleanupBlock
argument_list|)
decl_stmt|;
comment|/// CleanupBlockInfo - A struct representing a popped cleanup block.
struct|struct
name|CleanupBlockInfo
block|{
comment|/// CleanupBlock - the cleanup block
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
comment|/// CleanupScope - RAII object that will create a cleanup block and set the
comment|/// insert point to that block. When destructed, it sets the insert point to
comment|/// the previous block and pushes a new cleanup entry on the stack.
name|class
name|CleanupScope
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
name|CleanupBB
expr_stmt|;
name|public
label|:
name|CleanupScope
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
argument|CGF.Builder.GetInsertBlock()
argument_list|)
block|{
name|CleanupBB
operator|=
name|CGF
operator|.
name|createBasicBlock
argument_list|(
literal|"cleanup"
argument_list|)
block|;
name|CGF
operator|.
name|Builder
operator|.
name|SetInsertPoint
argument_list|(
name|CleanupBB
argument_list|)
block|;     }
operator|~
name|CleanupScope
argument_list|()
block|{
name|CGF
operator|.
name|PushCleanupBlock
argument_list|(
name|CleanupBB
argument_list|)
block|;
name|CGF
operator|.
name|Builder
operator|.
name|SetInsertPoint
argument_list|(
name|CurBB
argument_list|)
block|;     }
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
comment|/// PushConditionalTempDestruction - Should be called before a conditional
comment|/// part of an expression is emitted. For example, before the RHS of the
comment|/// expression below is emitted:
comment|///
comment|/// b&& f(T());
comment|///
comment|/// This is used to make sure that any temporaryes created in the conditional
comment|/// branch are only destroyed if the branch is taken.
name|void
name|PushConditionalTempDestruction
parameter_list|()
function_decl|;
comment|/// PopConditionalTempDestruction - Should be called after a conditional
comment|/// part of an expression has been emitted.
name|void
name|PopConditionalTempDestruction
parameter_list|()
function_decl|;
name|private
label|:
name|CGDebugInfo
modifier|*
name|DebugInfo
decl_stmt|;
comment|/// LabelIDs - Track arbitrary ids assigned to labels for use in implementing
comment|/// the GCC address-of-label extension and indirect goto. IDs are assigned to
comment|/// labels inside getIDForAddrOfLabel().
name|std
operator|::
name|map
operator|<
specifier|const
name|LabelStmt
operator|*
operator|,
name|unsigned
operator|>
name|LabelIDs
expr_stmt|;
comment|/// IndirectSwitches - Record the list of switches for indirect
comment|/// gotos. Emission of the actual switching code needs to be delayed until all
comment|/// AddrLabelExprs have been seen.
name|std
operator|::
name|vector
operator|<
name|llvm
operator|::
name|SwitchInst
operator|*
operator|>
name|IndirectSwitches
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
comment|// FIXME: Maybe this could be a stack of maps that is pushed/popped as we
comment|// enter/leave scopes.
name|llvm
operator|::
name|DenseMap
operator|<
specifier|const
name|VariableArrayType
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
comment|/// CleanupBlock - The block of code that does the actual cleanup.
name|llvm
operator|::
name|BasicBlock
operator|*
name|CleanupBlock
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
name|cb
argument_list|)
range|:
name|CleanupBlock
argument_list|(
argument|cb
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
comment|/// CXXThisDecl - When parsing an C++ function, this will hold the implicit
comment|/// 'this' declaration.
name|ImplicitParamDecl
modifier|*
name|CXXThisDecl
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
comment|/// CondPtr - If this is a conditional temporary, this is the pointer to
comment|/// the condition variable that states whether the destructor should be
comment|/// called or not.
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
comment|/// ConditionalTempDestructionStack - Contains the number of live temporaries
comment|/// when PushConditionalTempDestruction was called. This is used so that
comment|/// we know how many temporaries were created by a certain expression.
name|llvm
operator|::
name|SmallVector
operator|<
name|size_t
operator|,
literal|4
operator|>
name|ConditionalTempDestructionStack
expr_stmt|;
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
argument|QualType Ty
argument_list|,
argument|uint64_t Align
argument_list|)
expr_stmt|;
name|void
name|GenerateCode
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
name|void
name|StartFunction
argument_list|(
specifier|const
name|Decl
operator|*
name|D
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
comment|/// getBasicBlockForLabel - Return the LLVM basicblock that the specified
comment|/// label maps to.
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
comment|/// SimplifyForwardingBlocks - If the given basic block is only a
comment|/// branch to another basic block, simplify it. This assumes that no
comment|/// other code could potentially reference the basic block.
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
comment|/// EmitBlock - Emit the given block \arg BB and set it as the insert point,
comment|/// adding a fall-through branch from the current insert block if
comment|/// necessary. It is legal to call this function even if there is no current
comment|/// insertion point.
comment|///
comment|/// IsFinished - If true, indicates that the caller has finished emitting
comment|/// branches to the given block and does not expect to emit code into it. This
comment|/// means the block can be ignored if it is unreachable.
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
comment|/// EmitBranch - Emit a branch to the specified basic block from the current
comment|/// insert block, taking care to avoid creation of branches from dummy
comment|/// blocks. It is legal to call this function even if there is no current
comment|/// insertion point.
comment|///
comment|/// This function clears the current insertion point. The caller should follow
comment|/// calls to this function with calls to Emit*Block prior to generation new
comment|/// code.
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
comment|/// HaveInsertPoint - True if an insertion point is defined. If not, this
comment|/// indicates that the current code being emitted is unreachable.
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
comment|/// EnsureInsertPoint - Ensure that an insertion point is defined so that
comment|/// emitted IR has a place to go. Note that by definition, if this function
comment|/// creates a block then that block is unreachable; callers may do better to
comment|/// detect when no insertion point is defined and simply skip IR generation.
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
comment|/// ErrorUnsupported - Print out an error that codegen doesn't support the
comment|/// specified stmt yet.
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
comment|//===--------------------------------------------------------------------===//
comment|//                                  Helpers
comment|//===--------------------------------------------------------------------===//
comment|/// CreateTempAlloca - This creates a alloca and inserts it into the entry
comment|/// block.
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
name|char
operator|*
name|Name
operator|=
literal|"tmp"
argument_list|)
expr_stmt|;
comment|/// EvaluateExprAsBool - Perform the usual unary conversions on the specified
comment|/// expression and compare the result against zero, returning an Int1Ty value.
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
comment|/// EmitAnyExpr - Emit code to compute the specified expression which can have
comment|/// any type.  The result is returned as an RValue struct.  If this is an
comment|/// aggregate expression, the aggloc/agglocvolatile arguments indicate where
comment|/// the result should be returned.
comment|///
comment|/// \param IgnoreResult - True if the resulting value isn't used.
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
name|isAggLocVolatile
operator|=
name|false
argument_list|,
name|bool
name|IgnoreResult
operator|=
name|false
argument_list|)
decl_stmt|;
comment|// EmitVAListRef - Emit a "reference" to a va_list; this is either the address
comment|// or the value of the expression, depending on how va_list is defined.
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
comment|/// EmitAnyExprToTemp - Similary to EmitAnyExpr(), however, the result will
comment|/// always be accessible even if no aggregate location is provided.
name|RValue
name|EmitAnyExprToTemp
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
name|isAggLocVolatile
operator|=
name|false
argument_list|)
decl_stmt|;
comment|/// EmitAggregateCopy - Emit an aggrate copy.
comment|///
comment|/// \param isVolatile - True iff either the source or the destination is
comment|/// volatile.
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
comment|/// StartBlock - Start new block named N. If insert block is a dummy block
comment|/// then reuse it.
name|void
name|StartBlock
parameter_list|(
specifier|const
name|char
modifier|*
name|N
parameter_list|)
function_decl|;
comment|/// getCGRecordLayout - Return record layout info.
specifier|const
name|CGRecordLayout
modifier|*
name|getCGRecordLayout
parameter_list|(
name|CodeGenTypes
modifier|&
name|CGT
parameter_list|,
name|QualType
name|RTy
parameter_list|)
function_decl|;
comment|/// GetAddrOfStaticLocalVar - Return the address of a static local variable.
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
comment|/// GetAddrOfLocalVar - Return the address of a local variable.
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
comment|/// getAccessedFieldNo - Given an encoded value and a result number, return
comment|/// the input field number being accessed.
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
name|unsigned
name|GetIDForAddrOfLabel
parameter_list|(
specifier|const
name|LabelStmt
modifier|*
name|L
parameter_list|)
function_decl|;
comment|/// EmitMemSetToZero - Generate code to memset a value of the given type to 0.
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
comment|// EmitVAArg - Generate code to get an argument from the passed in pointer
comment|// and update it accordingly. The return value is a pointer to the argument.
comment|// FIXME: We should be able to get rid of this method and use the va_arg
comment|// instruction in LLVM instead once it works well enough.
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
comment|// EmitVLASize - Generate code for any VLA size expressions that might occur
comment|// in a variably modified type. If Ty is a VLA, will return the value that
comment|// corresponds to the size in bytes of the VLA type. Will return 0 otherwise.
name|llvm
operator|::
name|Value
operator|*
name|EmitVLASize
argument_list|(
argument|QualType Ty
argument_list|)
expr_stmt|;
comment|// GetVLASize - Returns an LLVM value that corresponds to the size in bytes
comment|// of a variable length array type.
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
comment|/// LoadCXXThis - Load the value of 'this'. This function is only valid while
comment|/// generating code for an C++ member function.
name|llvm
operator|::
name|Value
operator|*
name|LoadCXXThis
argument_list|()
expr_stmt|;
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
name|void
name|PopCXXTemporary
parameter_list|()
function_decl|;
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
comment|//===--------------------------------------------------------------------===//
comment|//                            Declaration Emission
comment|//===--------------------------------------------------------------------===//
name|void
name|EmitDecl
parameter_list|(
specifier|const
name|Decl
modifier|&
name|D
parameter_list|)
function_decl|;
name|void
name|EmitBlockVarDecl
parameter_list|(
specifier|const
name|VarDecl
modifier|&
name|D
parameter_list|)
function_decl|;
name|void
name|EmitLocalBlockVarDecl
parameter_list|(
specifier|const
name|VarDecl
modifier|&
name|D
parameter_list|)
function_decl|;
name|void
name|EmitStaticBlockVarDecl
parameter_list|(
specifier|const
name|VarDecl
modifier|&
name|D
parameter_list|)
function_decl|;
comment|/// EmitParmDecl - Emit a ParmVarDecl or an ImplicitParamDecl.
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
comment|//===--------------------------------------------------------------------===//
comment|//                             Statement Emission
comment|//===--------------------------------------------------------------------===//
comment|/// EmitStopPoint - Emit a debug stoppoint if we are emitting debug info.
name|void
name|EmitStopPoint
parameter_list|(
specifier|const
name|Stmt
modifier|*
name|S
parameter_list|)
function_decl|;
comment|/// EmitStmt - Emit the code for the statement \arg S. It is legal to call
comment|/// this function even if there is no current insertion point.
comment|///
comment|/// This function may clear the current insertion point; callers should use
comment|/// EnsureInsertPoint if they wish to subsequently generate code without first
comment|/// calling EmitBlock, EmitBranch, or EmitStmt.
name|void
name|EmitStmt
parameter_list|(
specifier|const
name|Stmt
modifier|*
name|S
parameter_list|)
function_decl|;
comment|/// EmitSimpleStmt - Try to emit a "simple" statement which does not
comment|/// necessarily require an insertion point or debug information; typically
comment|/// because the statement amounts to a jump or a container of other
comment|/// statements.
comment|///
comment|/// \return True if the statement was handled.
name|bool
name|EmitSimpleStmt
parameter_list|(
specifier|const
name|Stmt
modifier|*
name|S
parameter_list|)
function_decl|;
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
comment|/// EmitLabel - Emit the block for the given label. It is legal to call this
comment|/// function even if there is no current insertion point.
name|void
name|EmitLabel
parameter_list|(
specifier|const
name|LabelStmt
modifier|&
name|S
parameter_list|)
function_decl|;
comment|// helper for EmitLabelStmt.
name|void
name|EmitLabelStmt
parameter_list|(
specifier|const
name|LabelStmt
modifier|&
name|S
parameter_list|)
function_decl|;
name|void
name|EmitGotoStmt
parameter_list|(
specifier|const
name|GotoStmt
modifier|&
name|S
parameter_list|)
function_decl|;
name|void
name|EmitIndirectGotoStmt
parameter_list|(
specifier|const
name|IndirectGotoStmt
modifier|&
name|S
parameter_list|)
function_decl|;
name|void
name|EmitIfStmt
parameter_list|(
specifier|const
name|IfStmt
modifier|&
name|S
parameter_list|)
function_decl|;
name|void
name|EmitWhileStmt
parameter_list|(
specifier|const
name|WhileStmt
modifier|&
name|S
parameter_list|)
function_decl|;
name|void
name|EmitDoStmt
parameter_list|(
specifier|const
name|DoStmt
modifier|&
name|S
parameter_list|)
function_decl|;
name|void
name|EmitForStmt
parameter_list|(
specifier|const
name|ForStmt
modifier|&
name|S
parameter_list|)
function_decl|;
name|void
name|EmitReturnStmt
parameter_list|(
specifier|const
name|ReturnStmt
modifier|&
name|S
parameter_list|)
function_decl|;
name|void
name|EmitDeclStmt
parameter_list|(
specifier|const
name|DeclStmt
modifier|&
name|S
parameter_list|)
function_decl|;
name|void
name|EmitBreakStmt
parameter_list|(
specifier|const
name|BreakStmt
modifier|&
name|S
parameter_list|)
function_decl|;
name|void
name|EmitContinueStmt
parameter_list|(
specifier|const
name|ContinueStmt
modifier|&
name|S
parameter_list|)
function_decl|;
name|void
name|EmitSwitchStmt
parameter_list|(
specifier|const
name|SwitchStmt
modifier|&
name|S
parameter_list|)
function_decl|;
name|void
name|EmitDefaultStmt
parameter_list|(
specifier|const
name|DefaultStmt
modifier|&
name|S
parameter_list|)
function_decl|;
name|void
name|EmitCaseStmt
parameter_list|(
specifier|const
name|CaseStmt
modifier|&
name|S
parameter_list|)
function_decl|;
name|void
name|EmitCaseStmtRange
parameter_list|(
specifier|const
name|CaseStmt
modifier|&
name|S
parameter_list|)
function_decl|;
name|void
name|EmitAsmStmt
parameter_list|(
specifier|const
name|AsmStmt
modifier|&
name|S
parameter_list|)
function_decl|;
name|void
name|EmitObjCForCollectionStmt
parameter_list|(
specifier|const
name|ObjCForCollectionStmt
modifier|&
name|S
parameter_list|)
function_decl|;
name|void
name|EmitObjCAtTryStmt
parameter_list|(
specifier|const
name|ObjCAtTryStmt
modifier|&
name|S
parameter_list|)
function_decl|;
name|void
name|EmitObjCAtThrowStmt
parameter_list|(
specifier|const
name|ObjCAtThrowStmt
modifier|&
name|S
parameter_list|)
function_decl|;
name|void
name|EmitObjCAtSynchronizedStmt
parameter_list|(
specifier|const
name|ObjCAtSynchronizedStmt
modifier|&
name|S
parameter_list|)
function_decl|;
comment|//===--------------------------------------------------------------------===//
comment|//                         LValue Expression Emission
comment|//===--------------------------------------------------------------------===//
comment|/// GetUndefRValue - Get an appropriate 'undef' rvalue for the given type.
name|RValue
name|GetUndefRValue
parameter_list|(
name|QualType
name|Ty
parameter_list|)
function_decl|;
comment|/// EmitUnsupportedRValue - Emit a dummy r-value using the type of E
comment|/// and issue an ErrorUnsupported style diagnostic (using the
comment|/// provided Name).
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
comment|/// EmitUnsupportedLValue - Emit a dummy l-value using the type of E and issue
comment|/// an ErrorUnsupported style diagnostic (using the provided Name).
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
comment|/// EmitLValue - Emit code to compute a designator that specifies the location
comment|/// of the expression.
comment|///
comment|/// This can return one of two things: a simple address or a bitfield
comment|/// reference.  In either case, the LLVM Value* in the LValue structure is
comment|/// guaranteed to be an LLVM pointer type.
comment|///
comment|/// If this returns a bitfield reference, nothing about the pointee type of
comment|/// the LLVM value is known: For example, it may not be a pointer to an
comment|/// integer.
comment|///
comment|/// If this returns a normal address, and if the lvalue's C type is fixed
comment|/// size, this method guarantees that the returned pointer type will point to
comment|/// an LLVM type of the same size of the lvalue's type.  If the lvalue has a
comment|/// variable length type, this is not possible.
comment|///
name|LValue
name|EmitLValue
parameter_list|(
specifier|const
name|Expr
modifier|*
name|E
parameter_list|)
function_decl|;
comment|/// EmitLoadOfScalar - Load a scalar value from an address, taking
comment|/// care to appropriately convert from the memory representation to
comment|/// the LLVM value representation.
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
comment|/// EmitStoreOfScalar - Store a scalar value to an address, taking
comment|/// care to appropriately convert from the memory representation to
comment|/// the LLVM value representation.
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
comment|/// EmitLoadOfLValue - Given an expression that represents a value lvalue,
comment|/// this method emits the address of the lvalue, then loads the result as an
comment|/// rvalue, returning the rvalue.
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
comment|/// EmitStoreThroughLValue - Store the specified rvalue into the specified
comment|/// lvalue, where both are guaranteed to the have the same type, and that type
comment|/// is 'Ty'.
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
comment|/// EmitStoreThroughLValue - Store Src into Dst with same constraints as
comment|/// EmitStoreThroughLValue.
comment|///
comment|/// \param Result [out] - If non-null, this will be set to a Value* for the
comment|/// bit-field contents after the store, appropriate for use as the result of
comment|/// an assignment to the bit-field.
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
comment|// Note: only availabe for agg return types
name|LValue
name|EmitBinaryOperatorLValue
parameter_list|(
specifier|const
name|BinaryOperator
modifier|*
name|E
parameter_list|)
function_decl|;
comment|// Note: only available for agg return types
name|LValue
name|EmitCallExprLValue
parameter_list|(
specifier|const
name|CallExpr
modifier|*
name|E
parameter_list|)
function_decl|;
comment|// Note: only available for agg return types
name|LValue
name|EmitVAArgExprLValue
parameter_list|(
specifier|const
name|VAArgExpr
modifier|*
name|E
parameter_list|)
function_decl|;
name|LValue
name|EmitDeclRefLValue
parameter_list|(
specifier|const
name|DeclRefExpr
modifier|*
name|E
parameter_list|)
function_decl|;
name|LValue
name|EmitStringLiteralLValue
parameter_list|(
specifier|const
name|StringLiteral
modifier|*
name|E
parameter_list|)
function_decl|;
name|LValue
name|EmitObjCEncodeExprLValue
parameter_list|(
specifier|const
name|ObjCEncodeExpr
modifier|*
name|E
parameter_list|)
function_decl|;
name|LValue
name|EmitPredefinedFunctionName
parameter_list|(
name|unsigned
name|Type
parameter_list|)
function_decl|;
name|LValue
name|EmitPredefinedLValue
parameter_list|(
specifier|const
name|PredefinedExpr
modifier|*
name|E
parameter_list|)
function_decl|;
name|LValue
name|EmitUnaryOpLValue
parameter_list|(
specifier|const
name|UnaryOperator
modifier|*
name|E
parameter_list|)
function_decl|;
name|LValue
name|EmitArraySubscriptExpr
parameter_list|(
specifier|const
name|ArraySubscriptExpr
modifier|*
name|E
parameter_list|)
function_decl|;
name|LValue
name|EmitExtVectorElementExpr
parameter_list|(
specifier|const
name|ExtVectorElementExpr
modifier|*
name|E
parameter_list|)
function_decl|;
name|LValue
name|EmitMemberExpr
parameter_list|(
specifier|const
name|MemberExpr
modifier|*
name|E
parameter_list|)
function_decl|;
name|LValue
name|EmitCompoundLiteralLValue
parameter_list|(
specifier|const
name|CompoundLiteralExpr
modifier|*
name|E
parameter_list|)
function_decl|;
name|LValue
name|EmitConditionalOperator
parameter_list|(
specifier|const
name|ConditionalOperator
modifier|*
name|E
parameter_list|)
function_decl|;
name|LValue
name|EmitCastLValue
parameter_list|(
specifier|const
name|CastExpr
modifier|*
name|E
parameter_list|)
function_decl|;
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
name|LValue
name|EmitLValueForField
argument_list|(
name|llvm
operator|::
name|Value
operator|*
name|Base
argument_list|,
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
name|LValue
name|EmitLValueForBitfield
argument_list|(
name|llvm
operator|::
name|Value
operator|*
name|Base
argument_list|,
name|FieldDecl
operator|*
name|Field
argument_list|,
name|unsigned
name|CVRQualifiers
argument_list|)
decl_stmt|;
name|LValue
name|EmitBlockDeclRefLValue
parameter_list|(
specifier|const
name|BlockDeclRefExpr
modifier|*
name|E
parameter_list|)
function_decl|;
name|LValue
name|EmitCXXConditionDeclLValue
parameter_list|(
specifier|const
name|CXXConditionDeclExpr
modifier|*
name|E
parameter_list|)
function_decl|;
name|LValue
name|EmitCXXConstructLValue
parameter_list|(
specifier|const
name|CXXConstructExpr
modifier|*
name|E
parameter_list|)
function_decl|;
name|LValue
name|EmitCXXBindTemporaryLValue
parameter_list|(
specifier|const
name|CXXBindTemporaryExpr
modifier|*
name|E
parameter_list|)
function_decl|;
name|LValue
name|EmitObjCMessageExprLValue
parameter_list|(
specifier|const
name|ObjCMessageExpr
modifier|*
name|E
parameter_list|)
function_decl|;
name|LValue
name|EmitObjCIvarRefLValue
parameter_list|(
specifier|const
name|ObjCIvarRefExpr
modifier|*
name|E
parameter_list|)
function_decl|;
name|LValue
name|EmitObjCPropertyRefLValue
parameter_list|(
specifier|const
name|ObjCPropertyRefExpr
modifier|*
name|E
parameter_list|)
function_decl|;
name|LValue
name|EmitObjCKVCRefLValue
parameter_list|(
specifier|const
name|ObjCKVCRefExpr
modifier|*
name|E
parameter_list|)
function_decl|;
name|LValue
name|EmitObjCSuperExprLValue
parameter_list|(
specifier|const
name|ObjCSuperExpr
modifier|*
name|E
parameter_list|)
function_decl|;
name|LValue
name|EmitStmtExprLValue
parameter_list|(
specifier|const
name|StmtExpr
modifier|*
name|E
parameter_list|)
function_decl|;
comment|//===--------------------------------------------------------------------===//
comment|//                         Scalar Expression Emission
comment|//===--------------------------------------------------------------------===//
comment|/// EmitCall - Generate a call of the given function, expecting the given
comment|/// result type, and using the given argument list which specifies both the
comment|/// LLVM arguments and the types they were derived from.
comment|///
comment|/// \param TargetDecl - If given, the decl of the function in a
comment|/// direct call; used to set attributes on the call (noreturn,
comment|/// etc.).
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
name|RValue
name|EmitCallExpr
parameter_list|(
specifier|const
name|CallExpr
modifier|*
name|E
parameter_list|)
function_decl|;
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
name|RValue
name|EmitCXXMemberCallExpr
parameter_list|(
specifier|const
name|CXXMemberCallExpr
modifier|*
name|E
parameter_list|)
function_decl|;
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
name|RValue
name|EmitBlockCallExpr
parameter_list|(
specifier|const
name|CallExpr
modifier|*
name|E
parameter_list|)
function_decl|;
comment|/// EmitTargetBuiltinExpr - Emit the given builtin call. Returns 0 if the call
comment|/// is unhandled by the current target.
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
name|RValue
name|EmitObjCMessageExpr
parameter_list|(
specifier|const
name|ObjCMessageExpr
modifier|*
name|E
parameter_list|)
function_decl|;
name|RValue
name|EmitObjCPropertyGet
parameter_list|(
specifier|const
name|Expr
modifier|*
name|E
parameter_list|)
function_decl|;
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
comment|/// EmitReferenceBindingToExpr - Emits a reference binding to the passed in
comment|/// expression. Will emit a temporary variable if E is not an LValue.
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
parameter_list|)
function_decl|;
comment|//===--------------------------------------------------------------------===//
comment|//                           Expression Emission
comment|//===--------------------------------------------------------------------===//
comment|// Expressions are broken into three classes: scalar, complex, aggregate.
comment|/// EmitScalarExpr - Emit the computation of the specified expression of LLVM
comment|/// scalar type, returning the result.
name|llvm
operator|::
name|Value
operator|*
name|EmitScalarExpr
argument_list|(
argument|const Expr *E
argument_list|,
argument|bool IgnoreResultAssign=false
argument_list|)
expr_stmt|;
comment|/// EmitScalarConversion - Emit a conversion from the specified type to the
comment|/// specified destination type, both of which are LLVM scalar types.
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
comment|/// EmitComplexToScalarConversion - Emit a conversion from the specified
comment|/// complex type to the specified destination type, where the destination type
comment|/// is an LLVM scalar type.
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
comment|/// EmitAggExpr - Emit the computation of the specified expression of
comment|/// aggregate type.  The result is computed into DestPtr.  Note that if
comment|/// DestPtr is null, the value of the aggregate expression is not needed.
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
argument_list|)
decl_stmt|;
comment|/// EmitComplexExpr - Emit the computation of the specified expression of
comment|/// complex type, returning the result.
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
comment|/// EmitComplexExprIntoAddr - Emit the computation of the specified expression
comment|/// of complex type, storing into the specified Value*.
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
comment|/// StoreComplexToAddr - Store a complex number into the specified address.
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
comment|/// LoadComplexFromAddr - Load a complex number from the specified address.
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
comment|/// CreateStaticBlockVarDecl - Create a zero-initialized LLVM global
comment|/// for a static block var decl.
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
argument|llvm::GlobalValue::LinkageTypes                                                   Linkage
argument_list|)
expr_stmt|;
comment|/// GenerateStaticCXXBlockVarDecl - Create the initializer for a C++
comment|/// runtime initialized static block var decl.
name|void
name|GenerateStaticCXXBlockVarDeclInit
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
name|isAggLocVolatile
operator|=
name|false
argument_list|)
decl_stmt|;
comment|//===--------------------------------------------------------------------===//
comment|//                             Internal Helpers
comment|//===--------------------------------------------------------------------===//
comment|/// ContainsLabel - Return true if the statement contains a label in it.  If
comment|/// this statement is not executed normally, it not containing a label means
comment|/// that we can just remove the code.
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
comment|/// ConstantFoldsToSimpleInteger - If the specified expression does not fold
comment|/// to a constant, or if it does but contains a label, return 0.  If it
comment|/// constant folds to 'true' and does not contain a label, return 1, if it
comment|/// constant folds to 'false' and does not contain a label, return -1.
name|int
name|ConstantFoldsToSimpleInteger
parameter_list|(
specifier|const
name|Expr
modifier|*
name|Cond
parameter_list|)
function_decl|;
comment|/// EmitBranchOnBoolExpr - Emit a branch on a boolean condition (e.g. for an
comment|/// if statement) to the specified blocks.  Based on the condition, this might
comment|/// try to simplify the codegen of the conditional based on the branch.
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
name|private
label|:
comment|/// EmitIndirectSwitches - Emit code for all of the switch
comment|/// instructions in IndirectSwitches.
name|void
name|EmitIndirectSwitches
parameter_list|()
function_decl|;
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
comment|/// ExpandTypeFromArgs - Reconstruct a structure of type \arg Ty
comment|/// from function arguments into \arg Dst. See ABIArgInfo::Expand.
comment|///
comment|/// \param AI - The first function argument of the expansion.
comment|/// \return The argument following the last expanded function
comment|/// argument.
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
comment|/// ExpandTypeToArgs - Expand an RValue \arg Src, with the LLVM type for \arg
comment|/// Ty, into individual arguments on the provided vector \arg Args. See
comment|/// ABIArgInfo::Expand.
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
comment|/// EmitCleanupBlock - emits a single cleanup block.
name|void
name|EmitCleanupBlock
parameter_list|()
function_decl|;
comment|/// AddBranchFixup - adds a branch instruction to the list of fixups for the
comment|/// current cleanup scope.
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
comment|/// EmitCallArg - Emit a single call argument.
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
comment|/// EmitCallArgs - Emit call arguments for a function.
comment|/// The CallArgTypeInfo parameter is used for iterating over the known
comment|/// argument types of the function being called.
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
block|}
comment|// If we still have any arguments, emit them using the type of the argument.
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
name|QualType
name|ArgType
init|=
name|Arg
operator|->
name|getType
argument_list|()
decl_stmt|;
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
block|}
block|}
end_decl_stmt

begin_empty_stmt
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

