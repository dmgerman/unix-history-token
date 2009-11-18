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
file|"llvm/PassManager.h"
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
name|ModuleProvider
modifier|*
name|MP
decl_stmt|;
comment|// ModuleProvider used to create the PM
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
name|ModuleProvider
operator|*
name|MP
argument_list|)
operator|:
name|PM
argument_list|(
name|MP
argument_list|)
operator|,
name|MP
argument_list|(
argument|MP
argument_list|)
block|{}
name|FunctionPassManager
operator|&
name|getPM
argument_list|(
argument|const MutexGuard&L
argument_list|)
block|{
return|return
name|PM
return|;
block|}
name|ModuleProvider
operator|*
name|getMP
argument_list|()
specifier|const
block|{
return|return
name|MP
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
argument_list|(
argument|const MutexGuard&L
argument_list|)
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
name|TargetMachine
operator|&
name|TM
block|;
comment|// The current target we are compiling to
name|TargetJITInfo
operator|&
name|TJI
block|;
comment|// The JITInfo for the target we are compiling to
name|JITCodeEmitter
operator|*
name|JCE
block|;
comment|// JCE object
name|std
operator|::
name|vector
operator|<
name|JITEventListener
operator|*
operator|>
name|EventListeners
block|;
comment|/// AllocateGVsWithCode - Some applications require that global variables and
comment|/// code be allocated into the same region of memory, in which case this flag
comment|/// should be set to true.  Doing so breaks freeMachineCodeForFunction.
name|bool
name|AllocateGVsWithCode
block|;
name|JITState
operator|*
name|jitstate
block|;
name|JIT
argument_list|(
argument|ModuleProvider *MP
argument_list|,
argument|TargetMachine&tm
argument_list|,
argument|TargetJITInfo&tji
argument_list|,
argument|JITMemoryManager *JMM
argument_list|,
argument|CodeGenOpt::Level OptLevel
argument_list|,
argument|bool AllocateGVsWithCode
argument_list|)
block|;
name|public
operator|:
operator|~
name|JIT
argument_list|()
block|;
specifier|static
name|void
name|Register
argument_list|()
block|{
name|JITCtor
operator|=
name|create
block|;   }
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
operator|*
name|create
argument_list|(
argument|ModuleProvider *MP
argument_list|,
argument|std::string *Err
argument_list|,
argument|JITMemoryManager *JMM
argument_list|,
argument|CodeGenOpt::Level OptLevel =                                    CodeGenOpt::Default
argument_list|,
argument|bool GVsWithCode = true
argument_list|,
argument|CodeModel::Model CMM = CodeModel::Default
argument_list|)
block|{
return|return
name|ExecutionEngine
operator|::
name|createJIT
argument_list|(
name|MP
argument_list|,
name|Err
argument_list|,
name|JMM
argument_list|,
name|OptLevel
argument_list|,
name|GVsWithCode
argument_list|,
name|CMM
argument_list|)
return|;
block|}
name|virtual
name|void
name|addModuleProvider
argument_list|(
name|ModuleProvider
operator|*
name|MP
argument_list|)
block|;
comment|/// removeModuleProvider - Remove a ModuleProvider from the list of modules.
comment|/// Relases the Module from the ModuleProvider, materializing it in the
comment|/// process, and returns the materialized Module.
name|virtual
name|Module
operator|*
name|removeModuleProvider
argument_list|(
name|ModuleProvider
operator|*
name|MP
argument_list|,
name|std
operator|::
name|string
operator|*
name|ErrInfo
operator|=
literal|0
argument_list|)
block|;
comment|/// deleteModuleProvider - Remove a ModuleProvider from the list of modules,
comment|/// and deletes the ModuleProvider and owned Module.  Avoids materializing
comment|/// the underlying module.
name|virtual
name|void
name|deleteModuleProvider
argument_list|(
name|ModuleProvider
operator|*
name|P
argument_list|,
name|std
operator|::
name|string
operator|*
name|ErrInfo
operator|=
literal|0
argument_list|)
block|;
comment|/// runFunction - Start execution with the specified function and arguments.
comment|///
name|virtual
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
block|;
comment|/// getPointerToNamedFunction - This method returns the address of the
comment|/// specified function by using the dlsym function call.  As such it is only
comment|/// useful for resolving library symbols, not code generated symbols.
comment|///
comment|/// If AbortOnFailure is false and no function with the given name is
comment|/// found, this function silently returns a null pointer. Otherwise,
comment|/// it prints a message to stderr and aborts.
comment|///
name|void
operator|*
name|getPointerToNamedFunction
argument_list|(
argument|const std::string&Name
argument_list|,
argument|bool AbortOnFailure = true
argument_list|)
block|;
comment|// CompilationCallback - Invoked the first time that a call site is found,
comment|// which causes lazy compilation of the target function.
comment|//
specifier|static
name|void
name|CompilationCallback
argument_list|()
block|;
comment|/// getPointerToFunction - This returns the address of the specified function,
comment|/// compiling it if necessary.
comment|///
name|void
operator|*
name|getPointerToFunction
argument_list|(
name|Function
operator|*
name|F
argument_list|)
block|;
name|void
operator|*
name|getPointerToBasicBlock
argument_list|(
argument|BasicBlock *BB
argument_list|)
block|{
name|assert
argument_list|(
literal|0
operator|&&
literal|"JIT does not support address-of-label yet!"
argument_list|)
block|;
return|return
literal|0
return|;
block|}
comment|/// getOrEmitGlobalVariable - Return the address of the specified global
comment|/// variable, possibly emitting it to memory if needed.  This is used by the
comment|/// Emitter.
name|void
operator|*
name|getOrEmitGlobalVariable
argument_list|(
specifier|const
name|GlobalVariable
operator|*
name|GV
argument_list|)
block|;
comment|/// getPointerToFunctionOrStub - If the specified function has been
comment|/// code-gen'd, return a pointer to the function.  If not, compile it, or use
comment|/// a stub to implement lazy compilation if available.
comment|///
name|void
operator|*
name|getPointerToFunctionOrStub
argument_list|(
name|Function
operator|*
name|F
argument_list|)
block|;
comment|/// recompileAndRelinkFunction - This method is used to force a function
comment|/// which has already been compiled, to be compiled again, possibly
comment|/// after it has been modified. Then the entry to the old copy is overwritten
comment|/// with a branch to the new copy. If there was no old copy, this acts
comment|/// just like JIT::getPointerToFunction().
comment|///
name|void
operator|*
name|recompileAndRelinkFunction
argument_list|(
name|Function
operator|*
name|F
argument_list|)
block|;
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
block|;
comment|/// addPendingFunction - while jitting non-lazily, a called but non-codegen'd
comment|/// function was encountered.  Add it to a pending list to be processed after
comment|/// the current function.
comment|///
name|void
name|addPendingFunction
argument_list|(
name|Function
operator|*
name|F
argument_list|)
block|;
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
comment|/// selectTarget - Pick a target either via -march or by guessing the native
comment|/// arch.  Add any CPU features specified via -mcpu or -mattr.
specifier|static
name|TargetMachine
operator|*
name|selectTarget
argument_list|(
name|ModuleProvider
operator|*
name|MP
argument_list|,
name|std
operator|::
name|string
operator|*
name|Err
argument_list|)
block|;
specifier|static
name|ExecutionEngine
operator|*
name|createJIT
argument_list|(
argument|ModuleProvider *MP
argument_list|,
argument|std::string *ErrorStr
argument_list|,
argument|JITMemoryManager *JMM
argument_list|,
argument|CodeGenOpt::Level OptLevel
argument_list|,
argument|bool GVsWithCode
argument_list|,
argument|CodeModel::Model CMM
argument_list|)
block|;
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
literal|0
argument_list|)
block|;
name|virtual
name|void
name|RegisterJITEventListener
argument_list|(
name|JITEventListener
operator|*
name|L
argument_list|)
block|;
name|virtual
name|void
name|UnregisterJITEventListener
argument_list|(
name|JITEventListener
operator|*
name|L
argument_list|)
block|;
comment|/// These functions correspond to the methods on JITEventListener.  They
comment|/// iterate over the registered listeners and call the corresponding method on
comment|/// each.
name|void
name|NotifyFunctionEmitted
argument_list|(
argument|const Function&F
argument_list|,
argument|void *Code
argument_list|,
argument|size_t Size
argument_list|,
argument|const JITEvent_EmittedFunctionDetails&Details
argument_list|)
block|;
name|void
name|NotifyFreeingMachineCode
argument_list|(
name|void
operator|*
name|OldPtr
argument_list|)
block|;
name|private
operator|:
specifier|static
name|JITCodeEmitter
operator|*
name|createEmitter
argument_list|(
name|JIT
operator|&
name|J
argument_list|,
name|JITMemoryManager
operator|*
name|JMM
argument_list|,
name|TargetMachine
operator|&
name|tm
argument_list|)
block|;
name|void
name|runJITOnFunctionUnlocked
argument_list|(
name|Function
operator|*
name|F
argument_list|,
specifier|const
name|MutexGuard
operator|&
name|locked
argument_list|)
block|;
name|void
name|updateFunctionStub
argument_list|(
name|Function
operator|*
name|F
argument_list|)
block|;
name|protected
operator|:
comment|/// getMemoryforGV - Allocate memory for a global variable.
name|virtual
name|char
operator|*
name|getMemoryForGV
argument_list|(
specifier|const
name|GlobalVariable
operator|*
name|GV
argument_list|)
block|;  }
decl_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// End llvm namespace
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

