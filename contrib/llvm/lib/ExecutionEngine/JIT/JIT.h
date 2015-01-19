begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- JIT.h - Class definition for the JIT --------------------*- C++ -*-===//
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
comment|// This file defines the top-level JIT data structure.
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
name|JIT_H
end_ifndef

begin_define
define|#
directive|define
name|JIT_H
end_define

begin_include
include|#
directive|include
file|"llvm/ExecutionEngine/ExecutionEngine.h"
end_include

begin_include
include|#
directive|include
file|"llvm/IR/ValueHandle.h"
end_include

begin_include
include|#
directive|include
file|"llvm/PassManager.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|Function
decl_stmt|;
struct_decl|struct
name|JITEvent_EmittedFunctionDetails
struct_decl|;
name|class
name|MachineCodeEmitter
decl_stmt|;
name|class
name|MachineCodeInfo
decl_stmt|;
name|class
name|TargetJITInfo
decl_stmt|;
name|class
name|TargetMachine
decl_stmt|;
name|class
name|JITState
block|{
name|private
label|:
name|FunctionPassManager
name|PM
decl_stmt|;
comment|// Passes to compile a function
name|Module
modifier|*
name|M
decl_stmt|;
comment|// Module used to create the PM
comment|/// PendingFunctions - Functions which have not been code generated yet, but
comment|/// were called from a function being code generated.
name|std
operator|::
name|vector
operator|<
name|AssertingVH
operator|<
name|Function
operator|>
expr|>
name|PendingFunctions
expr_stmt|;
name|public
label|:
name|explicit
name|JITState
argument_list|(
name|Module
operator|*
name|M
argument_list|)
operator|:
name|PM
argument_list|(
name|M
argument_list|)
operator|,
name|M
argument_list|(
argument|M
argument_list|)
block|{}
name|FunctionPassManager
operator|&
name|getPM
argument_list|()
block|{
return|return
name|PM
return|;
block|}
name|Module
operator|*
name|getModule
argument_list|()
specifier|const
block|{
return|return
name|M
return|;
block|}
name|std
operator|::
name|vector
operator|<
name|AssertingVH
operator|<
name|Function
operator|>
expr|>
operator|&
name|getPendingFunctions
argument_list|()
block|{
return|return
name|PendingFunctions
return|;
block|}
block|}
empty_stmt|;
name|class
name|JIT
range|:
name|public
name|ExecutionEngine
block|{
comment|/// types
typedef|typedef
name|ValueMap
operator|<
specifier|const
name|BasicBlock
operator|*
operator|,
name|void
operator|*
operator|>
name|BasicBlockAddressMapTy
expr_stmt|;
comment|/// data
name|TargetMachine
operator|&
name|TM
decl_stmt|;
comment|// The current target we are compiling to
name|TargetJITInfo
modifier|&
name|TJI
decl_stmt|;
comment|// The JITInfo for the target we are compiling to
name|JITCodeEmitter
modifier|*
name|JCE
decl_stmt|;
comment|// JCE object
name|JITMemoryManager
modifier|*
name|JMM
decl_stmt|;
name|std
operator|::
name|vector
operator|<
name|JITEventListener
operator|*
operator|>
name|EventListeners
expr_stmt|;
comment|/// AllocateGVsWithCode - Some applications require that global variables and
comment|/// code be allocated into the same region of memory, in which case this flag
comment|/// should be set to true.  Doing so breaks freeMachineCodeForFunction.
name|bool
name|AllocateGVsWithCode
decl_stmt|;
comment|/// True while the JIT is generating code.  Used to assert against recursive
comment|/// entry.
name|bool
name|isAlreadyCodeGenerating
decl_stmt|;
name|JITState
modifier|*
name|jitstate
decl_stmt|;
comment|/// BasicBlockAddressMap - A mapping between LLVM basic blocks and their
comment|/// actualized version, only filled for basic blocks that have their address
comment|/// taken.
name|BasicBlockAddressMapTy
name|BasicBlockAddressMap
decl_stmt|;
name|JIT
argument_list|(
argument|Module *M
argument_list|,
argument|TargetMachine&tm
argument_list|,
argument|TargetJITInfo&tji
argument_list|,
argument|JITMemoryManager *JMM
argument_list|,
argument|bool AllocateGVsWithCode
argument_list|)
empty_stmt|;
name|public
label|:
operator|~
name|JIT
argument_list|()
expr_stmt|;
specifier|static
name|void
name|Register
parameter_list|()
block|{
name|JITCtor
operator|=
name|createJIT
expr_stmt|;
block|}
comment|/// getJITInfo - Return the target JIT information structure.
comment|///
name|TargetJITInfo
operator|&
name|getJITInfo
argument_list|()
specifier|const
block|{
return|return
name|TJI
return|;
block|}
comment|/// create - Create an return a new JIT compiler if there is one available
comment|/// for the current target.  Otherwise, return null.
comment|///
specifier|static
name|ExecutionEngine
modifier|*
name|create
argument_list|(
name|Module
operator|*
name|M
argument_list|,
name|std
operator|::
name|string
operator|*
name|Err
argument_list|,
name|JITMemoryManager
operator|*
name|JMM
argument_list|,
name|CodeGenOpt
operator|::
name|Level
name|OptLevel
operator|=
name|CodeGenOpt
operator|::
name|Default
argument_list|,
name|bool
name|GVsWithCode
operator|=
name|true
argument_list|,
name|Reloc
operator|::
name|Model
name|RM
operator|=
name|Reloc
operator|::
name|Default
argument_list|,
name|CodeModel
operator|::
name|Model
name|CMM
operator|=
name|CodeModel
operator|::
name|JITDefault
argument_list|)
block|{
return|return
name|ExecutionEngine
operator|::
name|createJIT
argument_list|(
name|M
argument_list|,
name|Err
argument_list|,
name|JMM
argument_list|,
name|OptLevel
argument_list|,
name|GVsWithCode
argument_list|,
name|RM
argument_list|,
name|CMM
argument_list|)
return|;
block|}
name|void
name|addModule
argument_list|(
name|Module
operator|*
name|M
argument_list|)
name|override
decl_stmt|;
comment|/// removeModule - Remove a Module from the list of modules.  Returns true if
comment|/// M is found.
name|bool
name|removeModule
argument_list|(
name|Module
operator|*
name|M
argument_list|)
name|override
decl_stmt|;
comment|/// runFunction - Start execution with the specified function and arguments.
comment|///
name|GenericValue
name|runFunction
argument_list|(
name|Function
operator|*
name|F
argument_list|,
specifier|const
name|std
operator|::
name|vector
operator|<
name|GenericValue
operator|>
operator|&
name|ArgValues
argument_list|)
name|override
decl_stmt|;
comment|/// getPointerToNamedFunction - This method returns the address of the
comment|/// specified function by using the MemoryManager. As such it is only
comment|/// useful for resolving library symbols, not code generated symbols.
comment|///
comment|/// If AbortOnFailure is false and no function with the given name is
comment|/// found, this function silently returns a null pointer. Otherwise,
comment|/// it prints a message to stderr and aborts.
comment|///
name|void
modifier|*
name|getPointerToNamedFunction
argument_list|(
specifier|const
name|std
operator|::
name|string
operator|&
name|Name
argument_list|,
name|bool
name|AbortOnFailure
operator|=
name|true
argument_list|)
name|override
decl_stmt|;
comment|// CompilationCallback - Invoked the first time that a call site is found,
comment|// which causes lazy compilation of the target function.
comment|//
specifier|static
name|void
name|CompilationCallback
parameter_list|()
function_decl|;
comment|/// getPointerToFunction - This returns the address of the specified function,
comment|/// compiling it if necessary.
comment|///
name|void
modifier|*
name|getPointerToFunction
argument_list|(
name|Function
operator|*
name|F
argument_list|)
name|override
decl_stmt|;
comment|/// addPointerToBasicBlock - Adds address of the specific basic block.
name|void
name|addPointerToBasicBlock
parameter_list|(
specifier|const
name|BasicBlock
modifier|*
name|BB
parameter_list|,
name|void
modifier|*
name|Addr
parameter_list|)
function_decl|;
comment|/// clearPointerToBasicBlock - Removes address of specific basic block.
name|void
name|clearPointerToBasicBlock
parameter_list|(
specifier|const
name|BasicBlock
modifier|*
name|BB
parameter_list|)
function_decl|;
comment|/// getPointerToBasicBlock - This returns the address of the specified basic
comment|/// block, assuming function is compiled.
name|void
modifier|*
name|getPointerToBasicBlock
argument_list|(
name|BasicBlock
operator|*
name|BB
argument_list|)
name|override
decl_stmt|;
comment|/// getOrEmitGlobalVariable - Return the address of the specified global
comment|/// variable, possibly emitting it to memory if needed.  This is used by the
comment|/// Emitter.
name|void
modifier|*
name|getOrEmitGlobalVariable
argument_list|(
specifier|const
name|GlobalVariable
operator|*
name|GV
argument_list|)
name|override
decl_stmt|;
comment|/// getPointerToFunctionOrStub - If the specified function has been
comment|/// code-gen'd, return a pointer to the function.  If not, compile it, or use
comment|/// a stub to implement lazy compilation if available.
comment|///
name|void
modifier|*
name|getPointerToFunctionOrStub
argument_list|(
name|Function
operator|*
name|F
argument_list|)
name|override
decl_stmt|;
comment|/// recompileAndRelinkFunction - This method is used to force a function
comment|/// which has already been compiled, to be compiled again, possibly
comment|/// after it has been modified. Then the entry to the old copy is overwritten
comment|/// with a branch to the new copy. If there was no old copy, this acts
comment|/// just like JIT::getPointerToFunction().
comment|///
name|void
modifier|*
name|recompileAndRelinkFunction
argument_list|(
name|Function
operator|*
name|F
argument_list|)
name|override
decl_stmt|;
comment|/// freeMachineCodeForFunction - deallocate memory used to code-generate this
comment|/// Function.
comment|///
name|void
name|freeMachineCodeForFunction
argument_list|(
name|Function
operator|*
name|F
argument_list|)
name|override
decl_stmt|;
comment|/// addPendingFunction - while jitting non-lazily, a called but non-codegen'd
comment|/// function was encountered.  Add it to a pending list to be processed after
comment|/// the current function.
comment|///
name|void
name|addPendingFunction
parameter_list|(
name|Function
modifier|*
name|F
parameter_list|)
function_decl|;
comment|/// getCodeEmitter - Return the code emitter this JIT is emitting into.
comment|///
name|JITCodeEmitter
operator|*
name|getCodeEmitter
argument_list|()
specifier|const
block|{
return|return
name|JCE
return|;
block|}
specifier|static
name|ExecutionEngine
modifier|*
name|createJIT
argument_list|(
name|Module
operator|*
name|M
argument_list|,
name|std
operator|::
name|string
operator|*
name|ErrorStr
argument_list|,
name|JITMemoryManager
operator|*
name|JMM
argument_list|,
name|bool
name|GVsWithCode
argument_list|,
name|TargetMachine
operator|*
name|TM
argument_list|)
decl_stmt|;
comment|// Run the JIT on F and return information about the generated code
name|void
name|runJITOnFunction
argument_list|(
name|Function
operator|*
name|F
argument_list|,
name|MachineCodeInfo
operator|*
name|MCI
operator|=
name|nullptr
argument_list|)
name|override
decl_stmt|;
name|void
name|RegisterJITEventListener
argument_list|(
name|JITEventListener
operator|*
name|L
argument_list|)
name|override
decl_stmt|;
name|void
name|UnregisterJITEventListener
argument_list|(
name|JITEventListener
operator|*
name|L
argument_list|)
name|override
decl_stmt|;
name|TargetMachine
modifier|*
name|getTargetMachine
parameter_list|()
function|override
block|{
return|return
operator|&
name|TM
return|;
block|}
comment|/// These functions correspond to the methods on JITEventListener.  They
comment|/// iterate over the registered listeners and call the corresponding method on
comment|/// each.
name|void
name|NotifyFunctionEmitted
parameter_list|(
specifier|const
name|Function
modifier|&
name|F
parameter_list|,
name|void
modifier|*
name|Code
parameter_list|,
name|size_t
name|Size
parameter_list|,
specifier|const
name|JITEvent_EmittedFunctionDetails
modifier|&
name|Details
parameter_list|)
function_decl|;
name|void
name|NotifyFreeingMachineCode
parameter_list|(
name|void
modifier|*
name|OldPtr
parameter_list|)
function_decl|;
name|BasicBlockAddressMapTy
modifier|&
name|getBasicBlockAddressMap
parameter_list|()
block|{
return|return
name|BasicBlockAddressMap
return|;
block|}
name|private
label|:
specifier|static
name|JITCodeEmitter
modifier|*
name|createEmitter
parameter_list|(
name|JIT
modifier|&
name|J
parameter_list|,
name|JITMemoryManager
modifier|*
name|JMM
parameter_list|,
name|TargetMachine
modifier|&
name|tm
parameter_list|)
function_decl|;
name|void
name|runJITOnFunctionUnlocked
parameter_list|(
name|Function
modifier|*
name|F
parameter_list|)
function_decl|;
name|void
name|updateFunctionStubUnlocked
parameter_list|(
name|Function
modifier|*
name|F
parameter_list|)
function_decl|;
name|void
name|jitTheFunctionUnlocked
parameter_list|(
name|Function
modifier|*
name|F
parameter_list|)
function_decl|;
name|protected
label|:
comment|/// getMemoryforGV - Allocate memory for a global variable.
name|char
modifier|*
name|getMemoryForGV
argument_list|(
specifier|const
name|GlobalVariable
operator|*
name|GV
argument_list|)
name|override
decl_stmt|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
unit|}
comment|// End llvm namespace
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

