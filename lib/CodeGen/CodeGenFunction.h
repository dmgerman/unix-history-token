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
file|"clang/AST/CharUnits.h"
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
name|namespace
name|CodeGen
block|{
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
name|class
name|CGBlockInfo
decl_stmt|;
comment|/// A branch fixup.  These are required when emitting a goto to a
comment|/// label which hasn't been emitted yet.  The goto is optimistically
comment|/// emitted as a branch to the basic block for the label, and (if it
comment|/// occurs in a scope with non-trivial cleanups) a fixup is added to
comment|/// the innermost cleanup.  When a (normal) cleanup is popped, any
comment|/// unresolved fixups in that scope are threaded through the cleanup.
struct|struct
name|BranchFixup
block|{
comment|/// The origin of the branch.  Any switch-index stores required by
comment|/// cleanup threading are added before this instruction.
name|llvm
operator|::
name|Instruction
operator|*
name|Origin
expr_stmt|;
comment|/// The destination of the branch.
comment|///
comment|/// This can be set to null to indicate that this fixup was
comment|/// successfully resolved.
name|llvm
operator|::
name|BasicBlock
operator|*
name|Destination
expr_stmt|;
comment|/// The last branch of the fixup.  It is an invariant that
comment|/// LatestBranch->getSuccessor(LatestBranchIndex) == Destination.
comment|///
comment|/// The branch is always either a BranchInst or a SwitchInst.
name|llvm
operator|::
name|TerminatorInst
operator|*
name|LatestBranch
expr_stmt|;
name|unsigned
name|LatestBranchIndex
decl_stmt|;
block|}
struct|;
comment|/// A stack of scopes which respond to exceptions, including cleanups
comment|/// and catch blocks.
name|class
name|EHScopeStack
block|{
name|public
label|:
comment|/// A saved depth on the scope stack.  This is necessary because
comment|/// pushing scopes onto the stack invalidates iterators.
name|class
name|stable_iterator
block|{
name|friend
name|class
name|EHScopeStack
decl_stmt|;
comment|/// Offset from StartOfData to EndOfBuffer.
name|ptrdiff_t
name|Size
decl_stmt|;
name|stable_iterator
argument_list|(
argument|ptrdiff_t Size
argument_list|)
block|:
name|Size
argument_list|(
argument|Size
argument_list|)
block|{}
name|public
label|:
specifier|static
name|stable_iterator
name|invalid
parameter_list|()
block|{
return|return
name|stable_iterator
argument_list|(
operator|-
literal|1
argument_list|)
return|;
block|}
name|stable_iterator
argument_list|()
operator|:
name|Size
argument_list|(
argument|-
literal|1
argument_list|)
block|{}
name|bool
name|isValid
argument_list|()
specifier|const
block|{
return|return
name|Size
operator|>=
literal|0
return|;
block|}
name|friend
name|bool
name|operator
operator|==
operator|(
name|stable_iterator
name|A
operator|,
name|stable_iterator
name|B
operator|)
block|{
return|return
name|A
operator|.
name|Size
operator|==
name|B
operator|.
name|Size
return|;
block|}
name|friend
name|bool
name|operator
operator|!=
operator|(
name|stable_iterator
name|A
operator|,
name|stable_iterator
name|B
operator|)
block|{
return|return
name|A
operator|.
name|Size
operator|!=
name|B
operator|.
name|Size
return|;
block|}
block|}
empty_stmt|;
name|private
label|:
comment|// The implementation for this class is in CGException.h and
comment|// CGException.cpp; the definition is here because it's used as a
comment|// member of CodeGenFunction.
comment|/// The start of the scope-stack buffer, i.e. the allocated pointer
comment|/// for the buffer.  All of these pointers are either simultaneously
comment|/// null or simultaneously valid.
name|char
modifier|*
name|StartOfBuffer
decl_stmt|;
comment|/// The end of the buffer.
name|char
modifier|*
name|EndOfBuffer
decl_stmt|;
comment|/// The first valid entry in the buffer.
name|char
modifier|*
name|StartOfData
decl_stmt|;
comment|/// The innermost normal cleanup on the stack.
name|stable_iterator
name|InnermostNormalCleanup
decl_stmt|;
comment|/// The innermost EH cleanup on the stack.
name|stable_iterator
name|InnermostEHCleanup
decl_stmt|;
comment|/// The number of catches on the stack.
name|unsigned
name|CatchDepth
decl_stmt|;
comment|/// The current set of branch fixups.  A branch fixup is a jump to
comment|/// an as-yet unemitted label, i.e. a label for which we don't yet
comment|/// know the EH stack depth.  Whenever we pop a cleanup, we have
comment|/// to thread all the current branch fixups through it.
comment|///
comment|/// Fixups are recorded as the Use of the respective branch or
comment|/// switch statement.  The use points to the final destination.
comment|/// When popping out of a cleanup, these uses are threaded through
comment|/// the cleanup and adjusted to point to the new cleanup.
comment|///
comment|/// Note that branches are allowed to jump into protected scopes
comment|/// in certain situations;  e.g. the following code is legal:
comment|///     struct A { ~A(); }; // trivial ctor, non-trivial dtor
comment|///     goto foo;
comment|///     A a;
comment|///    foo:
comment|///     bar();
name|llvm
operator|::
name|SmallVector
operator|<
name|BranchFixup
operator|,
literal|8
operator|>
name|BranchFixups
expr_stmt|;
name|char
modifier|*
name|allocate
parameter_list|(
name|size_t
name|Size
parameter_list|)
function_decl|;
name|void
name|popNullFixups
parameter_list|()
function_decl|;
name|public
label|:
name|EHScopeStack
argument_list|()
operator|:
name|StartOfBuffer
argument_list|(
literal|0
argument_list|)
operator|,
name|EndOfBuffer
argument_list|(
literal|0
argument_list|)
operator|,
name|StartOfData
argument_list|(
literal|0
argument_list|)
operator|,
name|InnermostNormalCleanup
argument_list|(
name|stable_end
argument_list|()
argument_list|)
operator|,
name|InnermostEHCleanup
argument_list|(
name|stable_end
argument_list|()
argument_list|)
operator|,
name|CatchDepth
argument_list|(
literal|0
argument_list|)
block|{}
operator|~
name|EHScopeStack
argument_list|()
block|{
name|delete
index|[]
name|StartOfBuffer
block|; }
comment|/// Push a cleanup on the stack.
name|void
name|pushCleanup
argument_list|(
name|llvm
operator|::
name|BasicBlock
operator|*
name|NormalEntry
argument_list|,
name|llvm
operator|::
name|BasicBlock
operator|*
name|NormalExit
argument_list|,
name|llvm
operator|::
name|BasicBlock
operator|*
name|EHEntry
argument_list|,
name|llvm
operator|::
name|BasicBlock
operator|*
name|EHExit
argument_list|)
expr_stmt|;
comment|/// Pops a cleanup scope off the stack.  This should only be called
comment|/// by CodeGenFunction::PopCleanupBlock.
name|void
name|popCleanup
parameter_list|()
function_decl|;
comment|/// Push a set of catch handlers on the stack.  The catch is
comment|/// uninitialized and will need to have the given number of handlers
comment|/// set on it.
name|class
name|EHCatchScope
modifier|*
name|pushCatch
parameter_list|(
name|unsigned
name|NumHandlers
parameter_list|)
function_decl|;
comment|/// Pops a catch scope off the stack.
name|void
name|popCatch
parameter_list|()
function_decl|;
comment|/// Push an exceptions filter on the stack.
name|class
name|EHFilterScope
modifier|*
name|pushFilter
parameter_list|(
name|unsigned
name|NumFilters
parameter_list|)
function_decl|;
comment|/// Pops an exceptions filter off the stack.
name|void
name|popFilter
parameter_list|()
function_decl|;
comment|/// Push a terminate handler on the stack.
name|void
name|pushTerminate
parameter_list|()
function_decl|;
comment|/// Pops a terminate handler off the stack.
name|void
name|popTerminate
parameter_list|()
function_decl|;
comment|/// Determines whether the exception-scopes stack is empty.
name|bool
name|empty
argument_list|()
specifier|const
block|{
return|return
name|StartOfData
operator|==
name|EndOfBuffer
return|;
block|}
name|bool
name|requiresLandingPad
argument_list|()
specifier|const
block|{
return|return
operator|(
name|CatchDepth
operator|||
name|hasEHCleanups
argument_list|()
operator|)
return|;
block|}
comment|/// Determines whether there are any normal cleanups on the stack.
name|bool
name|hasNormalCleanups
argument_list|()
specifier|const
block|{
return|return
name|InnermostNormalCleanup
operator|!=
name|stable_end
argument_list|()
return|;
block|}
comment|/// Returns the innermost normal cleanup on the stack, or
comment|/// stable_end() if there are no normal cleanups.
name|stable_iterator
name|getInnermostNormalCleanup
argument_list|()
specifier|const
block|{
return|return
name|InnermostNormalCleanup
return|;
block|}
comment|/// Determines whether there are any EH cleanups on the stack.
name|bool
name|hasEHCleanups
argument_list|()
specifier|const
block|{
return|return
name|InnermostEHCleanup
operator|!=
name|stable_end
argument_list|()
return|;
block|}
comment|/// Returns the innermost EH cleanup on the stack, or stable_end()
comment|/// if there are no EH cleanups.
name|stable_iterator
name|getInnermostEHCleanup
argument_list|()
specifier|const
block|{
return|return
name|InnermostEHCleanup
return|;
block|}
comment|/// An unstable reference to a scope-stack depth.  Invalidated by
comment|/// pushes but not pops.
name|class
name|iterator
decl_stmt|;
comment|/// Returns an iterator pointing to the innermost EH scope.
name|iterator
name|begin
argument_list|()
specifier|const
expr_stmt|;
comment|/// Returns an iterator pointing to the outermost EH scope.
name|iterator
name|end
argument_list|()
specifier|const
expr_stmt|;
comment|/// Create a stable reference to the top of the EH stack.  The
comment|/// returned reference is valid until that scope is popped off the
comment|/// stack.
name|stable_iterator
name|stable_begin
argument_list|()
specifier|const
block|{
return|return
name|stable_iterator
argument_list|(
name|EndOfBuffer
operator|-
name|StartOfData
argument_list|)
return|;
block|}
comment|/// Create a stable reference to the bottom of the EH stack.
specifier|static
name|stable_iterator
name|stable_end
parameter_list|()
block|{
return|return
name|stable_iterator
argument_list|(
literal|0
argument_list|)
return|;
block|}
comment|/// Translates an iterator into a stable_iterator.
name|stable_iterator
name|stabilize
argument_list|(
name|iterator
name|it
argument_list|)
decl|const
decl_stmt|;
comment|/// Finds the nearest cleanup enclosing the given iterator.
comment|/// Returns stable_iterator::invalid() if there are no such cleanups.
name|stable_iterator
name|getEnclosingEHCleanup
argument_list|(
name|iterator
name|it
argument_list|)
decl|const
decl_stmt|;
comment|/// Turn a stable reference to a scope depth into a unstable pointer
comment|/// to the EH stack.
name|iterator
name|find
argument_list|(
name|stable_iterator
name|save
argument_list|)
decl|const
decl_stmt|;
comment|/// Removes the cleanup pointed to by the given stable_iterator.
name|void
name|removeCleanup
parameter_list|(
name|stable_iterator
name|save
parameter_list|)
function_decl|;
comment|/// Add a branch fixup to the current cleanup scope.
name|BranchFixup
modifier|&
name|addBranchFixup
parameter_list|()
block|{
name|assert
argument_list|(
name|hasNormalCleanups
argument_list|()
operator|&&
literal|"adding fixup in scope without cleanups"
argument_list|)
expr_stmt|;
name|BranchFixups
operator|.
name|push_back
argument_list|(
name|BranchFixup
argument_list|()
argument_list|)
expr_stmt|;
return|return
name|BranchFixups
operator|.
name|back
argument_list|()
return|;
block|}
name|unsigned
name|getNumBranchFixups
argument_list|()
specifier|const
block|{
return|return
name|BranchFixups
operator|.
name|size
argument_list|()
return|;
block|}
name|BranchFixup
modifier|&
name|getBranchFixup
parameter_list|(
name|unsigned
name|I
parameter_list|)
block|{
name|assert
argument_list|(
name|I
operator|<
name|getNumBranchFixups
argument_list|()
argument_list|)
expr_stmt|;
return|return
name|BranchFixups
index|[
name|I
index|]
return|;
block|}
comment|/// Mark any branch fixups leading to the given block as resolved.
name|void
name|resolveBranchFixups
argument_list|(
name|llvm
operator|::
name|BasicBlock
operator|*
name|Dest
argument_list|)
decl_stmt|;
block|}
empty_stmt|;
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
comment|/// A jump destination is a pair of a basic block and a cleanup
comment|/// depth.  They are used to implement direct jumps across cleanup
comment|/// scopes, e.g. goto, break, continue, and return.
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
block|{}
name|JumpDest
argument_list|(
argument|llvm::BasicBlock *Block
argument_list|,
argument|EHScopeStack::stable_iterator Depth
argument_list|)
operator|:
name|Block
argument_list|(
name|Block
argument_list|)
block|,
name|ScopeDepth
argument_list|(
argument|Depth
argument_list|)
block|{}
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
comment|/// CurGD - The GlobalDecl for the current function being compiled.
name|GlobalDecl
name|CurGD
decl_stmt|;
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
comment|// intptr_t, i32, i64
specifier|const
name|llvm
operator|::
name|IntegerType
operator|*
name|IntPtrTy
operator|,
operator|*
name|Int32Ty
operator|,
operator|*
name|Int64Ty
expr_stmt|;
name|uint32_t
name|LLVMPointerWidth
decl_stmt|;
name|bool
name|Exceptions
decl_stmt|;
name|bool
name|CatchUndefined
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
comment|/// The exception slot.  All landing pads write the current
comment|/// exception pointer into this alloca.
name|llvm
operator|::
name|Value
operator|*
name|ExceptionSlot
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
comment|// A struct holding information about a finally block's IR
comment|// generation.  For now, doesn't actually hold anything.
struct|struct
name|FinallyInfo
block|{   }
struct|;
name|FinallyInfo
name|EnterFinallyBlock
argument_list|(
specifier|const
name|Stmt
operator|*
name|Stmt
argument_list|,
name|llvm
operator|::
name|Constant
operator|*
name|BeginCatchFn
argument_list|,
name|llvm
operator|::
name|Constant
operator|*
name|EndCatchFn
argument_list|,
name|llvm
operator|::
name|Constant
operator|*
name|RethrowFn
argument_list|)
decl_stmt|;
name|void
name|ExitFinallyBlock
parameter_list|(
name|FinallyInfo
modifier|&
name|FinallyInfo
parameter_list|)
function_decl|;
enum|enum
name|CleanupKind
block|{
name|NormalAndEHCleanup
block|,
name|EHCleanup
block|,
name|NormalCleanup
block|}
enum|;
comment|/// PushDestructorCleanup - Push a cleanup to call the
comment|/// complete-object destructor of an object of the given type at the
comment|/// given address.  Does nothing if T is not a C++ class type with a
comment|/// non-trivial destructor.
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
comment|/// PopCleanupBlock - Will pop the cleanup entry on the stack and
comment|/// process all branch fixups.
name|void
name|PopCleanupBlock
parameter_list|()
function_decl|;
comment|/// CleanupBlock - RAII object that will create a cleanup block and
comment|/// set the insert point to that block. When destructed, it sets the
comment|/// insert point to the previous block and pushes a new cleanup
comment|/// entry on the stack.
name|class
name|CleanupBlock
block|{
name|CodeGenFunction
modifier|&
name|CGF
decl_stmt|;
name|CGBuilderTy
operator|::
name|InsertPoint
name|SavedIP
expr_stmt|;
name|llvm
operator|::
name|BasicBlock
operator|*
name|NormalCleanupEntryBB
expr_stmt|;
name|llvm
operator|::
name|BasicBlock
operator|*
name|NormalCleanupExitBB
expr_stmt|;
name|llvm
operator|::
name|BasicBlock
operator|*
name|EHCleanupEntryBB
expr_stmt|;
name|public
label|:
name|CleanupBlock
argument_list|(
argument|CodeGenFunction&CGF
argument_list|,
argument|CleanupKind Kind
argument_list|)
empty_stmt|;
comment|/// If we're currently writing a normal cleanup, tie that off and
comment|/// start writing an EH cleanup.
name|void
name|beginEHCleanup
parameter_list|()
function_decl|;
operator|~
name|CleanupBlock
argument_list|()
expr_stmt|;
block|}
empty_stmt|;
comment|/// \brief Enters a new scope for capturing cleanups, all of which
comment|/// will be executed once the scope is exited.
name|class
name|RunCleanupsScope
block|{
name|CodeGenFunction
modifier|&
name|CGF
decl_stmt|;
name|EHScopeStack
operator|::
name|stable_iterator
name|CleanupStackDepth
expr_stmt|;
name|bool
name|OldDidCallStackSave
decl_stmt|;
name|bool
name|PerformCleanup
decl_stmt|;
name|RunCleanupsScope
argument_list|(
specifier|const
name|RunCleanupsScope
operator|&
argument_list|)
expr_stmt|;
comment|// DO NOT IMPLEMENT
name|RunCleanupsScope
modifier|&
name|operator
init|=
operator|(
specifier|const
name|RunCleanupsScope
operator|&
operator|)
decl_stmt|;
comment|// DO NOT IMPLEMENT
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
name|EHStack
operator|.
name|stable_begin
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
argument_list|)
expr_stmt|;
name|PerformCleanup
operator|=
name|false
expr_stmt|;
block|}
block|}
empty_stmt|;
comment|/// PopCleanupBlocks - Takes the old cleanup stack size and emits
comment|/// the cleanup blocks that have been added.
name|void
name|PopCleanupBlocks
argument_list|(
name|EHScopeStack
operator|::
name|stable_iterator
name|OldCleanupStackSize
argument_list|)
decl_stmt|;
comment|/// The given basic block lies in the current EH scope, but may be a
comment|/// target of a potentially scope-crossing jump; get a stable handle
comment|/// to which we can perform this jump later.
name|JumpDest
name|getJumpDestInCurrentScope
argument_list|(
name|llvm
operator|::
name|BasicBlock
operator|*
name|Target
argument_list|)
decl|const
block|{
return|return
name|JumpDest
argument_list|(
name|Target
argument_list|,
name|EHStack
operator|.
name|stable_begin
argument_list|()
argument_list|)
return|;
block|}
comment|/// The given basic block lies in the current EH scope, but may be a
comment|/// target of a potentially scope-crossing jump; get a stable handle
comment|/// to which we can perform this jump later.
name|JumpDest
name|getJumpDestInCurrentScope
parameter_list|(
specifier|const
name|char
modifier|*
name|Name
init|=
literal|0
parameter_list|)
block|{
return|return
name|JumpDest
argument_list|(
name|createBasicBlock
argument_list|(
name|Name
argument_list|)
argument_list|,
name|EHStack
operator|.
name|stable_begin
argument_list|()
argument_list|)
return|;
block|}
comment|/// EmitBranchThroughCleanup - Emit a branch from the current insert
comment|/// block through the normal cleanup handling code (if any) and then
comment|/// on to \arg Dest.
name|void
name|EmitBranchThroughCleanup
parameter_list|(
name|JumpDest
name|Dest
parameter_list|)
function_decl|;
comment|/// EmitBranchThroughEHCleanup - Emit a branch from the current
comment|/// insert block through the EH cleanup handling code (if any) and
comment|/// then on to \arg Dest.
name|void
name|EmitBranchThroughEHCleanup
parameter_list|(
name|JumpDest
name|Dest
parameter_list|)
function_decl|;
comment|/// BeginConditionalBranch - Should be called before a conditional part of an
comment|/// expression is emitted. For example, before the RHS of the expression below
comment|/// is emitted:
comment|///
comment|/// b&& f(T());
comment|///
comment|/// This is used to make sure that any temporaries created in the conditional
comment|/// branch are only destroyed if the branch is taken.
name|void
name|BeginConditionalBranch
parameter_list|()
block|{
operator|++
name|ConditionalBranchLevel
expr_stmt|;
block|}
comment|/// EndConditionalBranch - Should be called after a conditional part of an
comment|/// expression has been emitted.
name|void
name|EndConditionalBranch
parameter_list|()
block|{
name|assert
argument_list|(
name|ConditionalBranchLevel
operator|!=
literal|0
operator|&&
literal|"Conditional branch mismatch!"
argument_list|)
expr_stmt|;
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
name|JumpDest
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
comment|/// A block containing a single 'unreachable' instruction.  Created
comment|/// lazily by getUnreachableBlock().
name|llvm
operator|::
name|BasicBlock
operator|*
name|UnreachableBlock
expr_stmt|;
comment|/// CXXThisDecl - When generating code for a C++ member function,
comment|/// this will hold the implicit 'this' declaration.
name|ImplicitParamDecl
modifier|*
name|CXXThisDecl
decl_stmt|;
name|llvm
operator|::
name|Value
operator|*
name|CXXThisValue
expr_stmt|;
comment|/// CXXVTTDecl - When generating code for a base object constructor or
comment|/// base object destructor with virtual bases, this will hold the implicit
comment|/// VTT parameter.
name|ImplicitParamDecl
modifier|*
name|CXXVTTDecl
decl_stmt|;
name|llvm
operator|::
name|Value
operator|*
name|CXXVTTValue
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
name|llvm
operator|::
name|BasicBlock
operator|*
name|TerminateLandingPad
expr_stmt|;
name|llvm
operator|::
name|BasicBlock
operator|*
name|TerminateHandler
expr_stmt|;
name|llvm
operator|::
name|BasicBlock
operator|*
name|TrapBB
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
comment|/// Returns a pointer to the function's exception object slot, which
comment|/// is assigned in every landing pad.
name|llvm
operator|::
name|Value
operator|*
name|getExceptionSlot
argument_list|()
expr_stmt|;
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
return|return
name|UnreachableBlock
return|;
block|}
name|llvm
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
return|return
name|getInvokeDestImpl
argument_list|()
return|;
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
name|bool
name|IndirectObjCSetterArg
parameter_list|(
specifier|const
name|CGFunctionInfo
modifier|&
name|FI
parameter_list|)
function_decl|;
name|bool
name|IvarTypeWithAggrGCObjects
parameter_list|(
name|QualType
name|Ty
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
argument|const BlockExpr *
argument_list|,
argument|bool BlockHasCopyDispose
argument_list|,
argument|CharUnits Size
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
argument|GlobalDecl GD
argument_list|,
argument|const BlockExpr *BExpr
argument_list|,
argument|CGBlockInfo&Info
argument_list|,
argument|const Decl *OuterFuncDecl
argument_list|,
argument|llvm::DenseMap<const Decl*
argument_list|,
argument|llvm::Value*> ldm
argument_list|)
expr_stmt|;
name|llvm
operator|::
name|Value
operator|*
name|LoadBlockStruct
argument_list|()
expr_stmt|;
name|void
name|AllocateBlockCXXThisPointer
parameter_list|(
specifier|const
name|CXXThisExpr
modifier|*
name|E
parameter_list|)
function_decl|;
name|void
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
argument|const BlockDeclRefExpr *E
argument_list|)
block|{
return|return
name|GetAddrOfBlockDecl
argument_list|(
name|E
operator|->
name|getDecl
argument_list|()
argument_list|,
name|E
operator|->
name|isByRef
argument_list|()
argument_list|)
return|;
block|}
name|llvm
operator|::
name|Value
operator|*
name|GetAddrOfBlockDecl
argument_list|(
argument|const ValueDecl *D
argument_list|,
argument|bool ByRef
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
name|void
name|EmitConstructorBody
parameter_list|(
name|FunctionArgList
modifier|&
name|Args
parameter_list|)
function_decl|;
name|void
name|EmitDestructorBody
parameter_list|(
name|FunctionArgList
modifier|&
name|Args
parameter_list|)
function_decl|;
name|void
name|EmitFunctionBody
parameter_list|(
name|FunctionArgList
modifier|&
name|Args
parameter_list|)
function_decl|;
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
comment|/// GenerateThunk - Generate a thunk for the given method.
name|void
name|GenerateThunk
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
name|ThunkInfo
operator|&
name|Thunk
argument_list|)
decl_stmt|;
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
comment|/// InitializeVTablePointer - Initialize the vtable pointer of the given
comment|/// subobject.
comment|///
name|void
name|InitializeVTablePointer
argument_list|(
name|BaseSubobject
name|Base
argument_list|,
specifier|const
name|CXXRecordDecl
operator|*
name|NearestVBase
argument_list|,
name|uint64_t
name|OffsetFromNearestVBase
argument_list|,
name|llvm
operator|::
name|Constant
operator|*
name|VTable
argument_list|,
specifier|const
name|CXXRecordDecl
operator|*
name|VTableClass
argument_list|)
decl_stmt|;
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
name|void
name|InitializeVTablePointers
argument_list|(
name|BaseSubobject
name|Base
argument_list|,
specifier|const
name|CXXRecordDecl
operator|*
name|NearestVBase
argument_list|,
name|uint64_t
name|OffsetFromNearestVBase
argument_list|,
name|bool
name|BaseIsNonVirtualPrimaryBase
argument_list|,
name|llvm
operator|::
name|Constant
operator|*
name|VTable
argument_list|,
specifier|const
name|CXXRecordDecl
operator|*
name|VTableClass
argument_list|,
name|VisitedVirtualBasesSetTy
operator|&
name|VBases
argument_list|)
decl_stmt|;
name|void
name|InitializeVTablePointers
parameter_list|(
specifier|const
name|CXXRecordDecl
modifier|*
name|ClassDecl
parameter_list|)
function_decl|;
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
comment|/// ShouldInstrumentFunction - Return true if the current function should be
comment|/// instrumented with __cyg_profile_func_* calls
name|bool
name|ShouldInstrumentFunction
parameter_list|()
function_decl|;
comment|/// EmitFunctionInstrumentation - Emit LLVM code to call the specified
comment|/// instrumentation function with the current function and the call site, if
comment|/// function instrumentation is enabled.
name|void
name|EmitFunctionInstrumentation
parameter_list|(
specifier|const
name|char
modifier|*
name|Fn
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
parameter_list|(
specifier|const
name|CGFunctionInfo
modifier|&
name|FI
parameter_list|)
function_decl|;
comment|/// EmitStartEHSpec - Emit the start of the exception spec.
name|void
name|EmitStartEHSpec
parameter_list|(
specifier|const
name|Decl
modifier|*
name|D
parameter_list|)
function_decl|;
comment|/// EmitEndEHSpec - Emit the end of the exception spec.
name|void
name|EmitEndEHSpec
parameter_list|(
specifier|const
name|Decl
modifier|*
name|D
parameter_list|)
function_decl|;
comment|/// getTerminateLandingPad - Return a landing pad that just calls terminate.
name|llvm
operator|::
name|BasicBlock
operator|*
name|getTerminateLandingPad
argument_list|()
expr_stmt|;
comment|/// getTerminateHandler - Return a handler (not a landing pad, just
comment|/// a catch handler) that just calls terminate.  This is used when
comment|/// a terminate scope encloses a try.
name|llvm
operator|::
name|BasicBlock
operator|*
name|getTerminateHandler
argument_list|()
expr_stmt|;
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
specifier|const
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

begin_function_decl
name|JumpDest
name|getJumpDestForLabel
parameter_list|(
specifier|const
name|LabelStmt
modifier|*
name|S
parameter_list|)
function_decl|;
end_function_decl

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
argument|const llvm::Twine&Name =
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
argument|const llvm::Twine&Name =
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
comment|/// EmitsAnyExprToMem - Emits the code necessary to evaluate an
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
name|bool
name|IsLocationVolatile
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
name|CXXVTTValue
operator|&&
literal|"no VTT value for this function"
argument_list|)
block|;
return|return
name|CXXVTTValue
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
argument|const CXXBaseSpecifierArray&BasePath
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
argument|const CXXBaseSpecifierArray&BasePath
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
name|GetVirtualBaseClassOffset
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
name|Function
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
name|bool
name|ForVirtualBase
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

begin_decl_stmt
name|void
name|EmitCheck
argument_list|(
name|llvm
operator|::
name|Value
operator|*
argument_list|,
name|unsigned
name|Size
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
parameter_list|,
name|SpecialInitFn
modifier|*
name|SpecialInit
init|=
literal|0
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
name|void
name|EmitStaticBlockVarDecl
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
comment|/// EmitCheckedLValue - Same as EmitLValue but additionally we generate
end_comment

begin_comment
comment|/// checking code to guard against undefined behavior.  This is only
end_comment

begin_comment
comment|/// suitable when we know that the address will be used to access the
end_comment

begin_comment
comment|/// object.
end_comment

begin_function_decl
name|LValue
name|EmitCheckedLValue
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

begin_function_decl
name|LValue
name|EmitCompoundAssignOperatorLValue
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
name|CXXScalarValueInitExpr
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
name|EmitLValueForAnonRecordField
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
name|unsigned
name|CVRQualifiers
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// EmitLValueForFieldInitialization - Like EmitLValueForField, except that
end_comment

begin_comment
comment|/// if the Field is a reference, this will return the address of the reference
end_comment

begin_comment
comment|/// and not the address of the value stored in the reference.
end_comment

begin_decl_stmt
name|LValue
name|EmitLValueForFieldInitialization
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
name|CallSite
name|EmitCallOrInvoke
argument_list|(
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
specifier|const
operator|*
name|ArgBegin
argument_list|,
name|llvm
operator|::
name|Value
operator|*
specifier|const
operator|*
name|ArgEnd
argument_list|,
specifier|const
name|llvm
operator|::
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
name|VTT
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
argument|llvm::SmallVectorImpl<llvm::Value*>&O
argument_list|,
argument|const char *name
argument_list|,
argument|bool splat = false
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
argument|const llvm::Type *Ty
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

begin_function_decl
name|RValue
name|EmitObjCPropertyGet
parameter_list|(
specifier|const
name|Expr
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
parameter_list|,
name|ReturnValueSlot
name|Return
init|=
name|ReturnValueSlot
argument_list|()
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
specifier|const
name|NamedDecl
modifier|*
name|InitializedDecl
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
comment|/// AddInitializerToGlobalBlockVarDecl - Add the initializer for 'D' to the
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
name|AddInitializerToGlobalBlockVarDecl
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
name|llvm
operator|::
name|Constant
operator|*
operator|*
name|Decls
argument_list|,
name|unsigned
name|NumDecls
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// GenerateCXXGlobalDtorFunc - Generates code for destroying global
end_comment

begin_comment
comment|/// variables.
end_comment

begin_decl_stmt
name|void
name|GenerateCXXGlobalDtorFunc
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

begin_comment
comment|/// getTrapBB - Create a basic block that will call the trap intrinsic.  We'll
end_comment

begin_comment
comment|/// generate a branch around the created basic block as necessary.
end_comment

begin_expr_stmt
name|llvm
operator|::
name|BasicBlock
operator|*
name|getTrapBB
argument_list|()
expr_stmt|;
end_expr_stmt

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
comment|/// EmitDelegateCallArg - We are performing a delegate call; that
end_comment

begin_comment
comment|/// is, the current function is delegating to another one.  Produce
end_comment

begin_comment
comment|/// a r-value suitable for passing the given parameter.
end_comment

begin_function_decl
name|RValue
name|EmitDelegateCallArg
parameter_list|(
specifier|const
name|VarDecl
modifier|*
name|Param
parameter_list|)
function_decl|;
end_function_decl

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

begin_comment
unit|};   }
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

