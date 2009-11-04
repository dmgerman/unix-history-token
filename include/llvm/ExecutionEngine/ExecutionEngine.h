begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- ExecutionEngine.h - Abstract Execution Engine Interface --*- C++ -*-===//
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
comment|// This file defines the abstract interface that implements execution support
end_comment

begin_comment
comment|// for LLVM.
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
name|LLVM_EXECUTION_ENGINE_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_EXECUTION_ENGINE_H
end_define

begin_include
include|#
directive|include
file|<vector>
end_include

begin_include
include|#
directive|include
file|<map>
end_include

begin_include
include|#
directive|include
file|<string>
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/SmallVector.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/ValueMap.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/ValueHandle.h"
end_include

begin_include
include|#
directive|include
file|"llvm/System/Mutex.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Target/TargetMachine.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
struct_decl|struct
name|GenericValue
struct_decl|;
name|class
name|Constant
decl_stmt|;
name|class
name|ExecutionEngine
decl_stmt|;
name|class
name|Function
decl_stmt|;
name|class
name|GlobalVariable
decl_stmt|;
name|class
name|GlobalValue
decl_stmt|;
name|class
name|JITEventListener
decl_stmt|;
name|class
name|JITMemoryManager
decl_stmt|;
name|class
name|MachineCodeInfo
decl_stmt|;
name|class
name|Module
decl_stmt|;
name|class
name|ModuleProvider
decl_stmt|;
name|class
name|MutexGuard
decl_stmt|;
name|class
name|TargetData
decl_stmt|;
name|class
name|Type
decl_stmt|;
name|class
name|ExecutionEngineState
block|{
name|public
label|:
name|struct
name|AddressMapConfig
range|:
name|public
name|ValueMapConfig
operator|<
specifier|const
name|GlobalValue
operator|*
operator|>
block|{
typedef|typedef
name|ExecutionEngineState
modifier|*
name|ExtraData
typedef|;
specifier|static
name|sys
operator|::
name|Mutex
operator|*
name|getMutex
argument_list|(
name|ExecutionEngineState
operator|*
name|EES
argument_list|)
decl_stmt|;
specifier|static
name|void
name|onDelete
parameter_list|(
name|ExecutionEngineState
modifier|*
name|EES
parameter_list|,
specifier|const
name|GlobalValue
modifier|*
name|Old
parameter_list|)
function_decl|;
specifier|static
name|void
name|onRAUW
parameter_list|(
name|ExecutionEngineState
modifier|*
parameter_list|,
specifier|const
name|GlobalValue
modifier|*
parameter_list|,
specifier|const
name|GlobalValue
modifier|*
parameter_list|)
function_decl|;
block|}
empty_stmt|;
typedef|typedef
name|ValueMap
operator|<
specifier|const
name|GlobalValue
operator|*
operator|,
name|void
operator|*
operator|,
name|AddressMapConfig
operator|>
name|GlobalAddressMapTy
expr_stmt|;
name|private
label|:
name|ExecutionEngine
modifier|&
name|EE
decl_stmt|;
comment|/// GlobalAddressMap - A mapping between LLVM global values and their
comment|/// actualized version...
name|GlobalAddressMapTy
name|GlobalAddressMap
decl_stmt|;
comment|/// GlobalAddressReverseMap - This is the reverse mapping of GlobalAddressMap,
comment|/// used to convert raw addresses into the LLVM global value that is emitted
comment|/// at the address.  This map is not computed unless getGlobalValueAtAddress
comment|/// is called at some point.
name|std
operator|::
name|map
operator|<
name|void
operator|*
operator|,
name|AssertingVH
operator|<
specifier|const
name|GlobalValue
operator|>
expr|>
name|GlobalAddressReverseMap
expr_stmt|;
name|public
label|:
name|ExecutionEngineState
argument_list|(
name|ExecutionEngine
operator|&
name|EE
argument_list|)
expr_stmt|;
name|GlobalAddressMapTy
modifier|&
name|getGlobalAddressMap
parameter_list|(
specifier|const
name|MutexGuard
modifier|&
parameter_list|)
block|{
return|return
name|GlobalAddressMap
return|;
block|}
name|std
operator|::
name|map
operator|<
name|void
operator|*
operator|,
name|AssertingVH
operator|<
specifier|const
name|GlobalValue
operator|>
expr|>
operator|&
name|getGlobalAddressReverseMap
argument_list|(
argument|const MutexGuard&
argument_list|)
block|{
return|return
name|GlobalAddressReverseMap
return|;
block|}
comment|// Returns the address ToUnmap was mapped to.
name|void
modifier|*
name|RemoveMapping
parameter_list|(
specifier|const
name|MutexGuard
modifier|&
parameter_list|,
specifier|const
name|GlobalValue
modifier|*
name|ToUnmap
parameter_list|)
function_decl|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_decl_stmt
name|class
name|ExecutionEngine
block|{
specifier|const
name|TargetData
modifier|*
name|TD
decl_stmt|;
name|ExecutionEngineState
name|EEState
decl_stmt|;
name|bool
name|CompilingLazily
decl_stmt|;
name|bool
name|GVCompilationDisabled
decl_stmt|;
name|bool
name|SymbolSearchingDisabled
decl_stmt|;
name|bool
name|DlsymStubsEnabled
decl_stmt|;
name|friend
name|class
name|EngineBuilder
decl_stmt|;
comment|// To allow access to JITCtor and InterpCtor.
name|protected
label|:
comment|/// Modules - This is a list of ModuleProvider's that we are JIT'ing from.  We
comment|/// use a smallvector to optimize for the case where there is only one module.
name|SmallVector
operator|<
name|ModuleProvider
operator|*
operator|,
literal|1
operator|>
name|Modules
expr_stmt|;
name|void
name|setTargetData
parameter_list|(
specifier|const
name|TargetData
modifier|*
name|td
parameter_list|)
block|{
name|TD
operator|=
name|td
expr_stmt|;
block|}
comment|/// getMemoryforGV - Allocate memory for a global variable.
name|virtual
name|char
modifier|*
name|getMemoryForGV
parameter_list|(
specifier|const
name|GlobalVariable
modifier|*
name|GV
parameter_list|)
function_decl|;
comment|// To avoid having libexecutionengine depend on the JIT and interpreter
comment|// libraries, the JIT and Interpreter set these functions to ctor pointers
comment|// at startup time if they are linked in.
specifier|static
name|ExecutionEngine
operator|*
operator|(
operator|*
name|JITCtor
operator|)
operator|(
name|ModuleProvider
operator|*
name|MP
operator|,
name|std
operator|::
name|string
operator|*
name|ErrorStr
operator|,
name|JITMemoryManager
operator|*
name|JMM
operator|,
name|CodeGenOpt
operator|::
name|Level
name|OptLevel
operator|,
name|bool
name|GVsWithCode
operator|)
expr_stmt|;
specifier|static
name|ExecutionEngine
operator|*
call|(
modifier|*
name|InterpCtor
call|)
argument_list|(
name|ModuleProvider
operator|*
name|MP
argument_list|,
name|std
operator|::
name|string
operator|*
name|ErrorStr
argument_list|)
expr_stmt|;
comment|/// LazyFunctionCreator - If an unknown function is needed, this function
comment|/// pointer is invoked to create it. If this returns null, the JIT will abort.
name|void
argument_list|*
call|(
modifier|*
name|LazyFunctionCreator
call|)
argument_list|(
specifier|const
name|std
operator|::
name|string
operator|&
argument_list|)
argument_list|;
comment|/// ExceptionTableRegister - If Exception Handling is set, the JIT will
comment|/// register dwarf tables with this function
argument_list|typedef
name|void
argument_list|(
operator|*
name|EERegisterFn
argument_list|)
argument_list|(
name|void
operator|*
argument_list|)
argument_list|;
specifier|static
name|EERegisterFn
name|ExceptionTableRegister
argument_list|;
name|public
operator|:
comment|/// lock - This lock is protects the ExecutionEngine, JIT, JITResolver and
comment|/// JITEmitter classes.  It must be held while changing the internal state of
comment|/// any of those classes.
name|sys
operator|::
name|Mutex
name|lock
argument_list|;
comment|// Used to make this class and subclasses thread-safe
comment|//===--------------------------------------------------------------------===//
comment|//  ExecutionEngine Startup
comment|//===--------------------------------------------------------------------===//
name|virtual
operator|~
name|ExecutionEngine
argument_list|()
argument_list|;
comment|/// create - This is the factory method for creating an execution engine which
comment|/// is appropriate for the current machine.  This takes ownership of the
comment|/// module provider.
specifier|static
name|ExecutionEngine
operator|*
name|create
argument_list|(
argument|ModuleProvider *MP
argument_list|,
argument|bool ForceInterpreter = false
argument_list|,
argument|std::string *ErrorStr =
literal|0
argument_list|,
argument|CodeGenOpt::Level OptLevel =                                    CodeGenOpt::Default
argument_list|,
comment|// Allocating globals with code breaks
comment|// freeMachineCodeForFunction and is probably
comment|// unsafe and bad for performance.  However,
comment|// we have clients who depend on this
comment|// behavior, so we must support it.
comment|// Eventually, when we're willing to break
comment|// some backwards compatability, this flag
comment|// should be flipped to false, so that by
comment|// default freeMachineCodeForFunction works.
argument|bool GVsWithCode = true
argument_list|)
argument_list|;
comment|/// create - This is the factory method for creating an execution engine which
comment|/// is appropriate for the current machine.  This takes ownership of the
comment|/// module.
specifier|static
name|ExecutionEngine
operator|*
name|create
argument_list|(
name|Module
operator|*
name|M
argument_list|)
argument_list|;
comment|/// createJIT - This is the factory method for creating a JIT for the current
comment|/// machine, it does not fall back to the interpreter.  This takes ownership
comment|/// of the ModuleProvider and JITMemoryManager if successful.
comment|///
comment|/// Clients should make sure to initialize targets prior to calling this
comment|/// function.
specifier|static
name|ExecutionEngine
operator|*
name|createJIT
argument_list|(
argument|ModuleProvider *MP
argument_list|,
argument|std::string *ErrorStr =
literal|0
argument_list|,
argument|JITMemoryManager *JMM =
literal|0
argument_list|,
argument|CodeGenOpt::Level OptLevel =                                       CodeGenOpt::Default
argument_list|,
argument|bool GVsWithCode = true
argument_list|)
argument_list|;
comment|/// addModuleProvider - Add a ModuleProvider to the list of modules that we
comment|/// can JIT from.  Note that this takes ownership of the ModuleProvider: when
comment|/// the ExecutionEngine is destroyed, it destroys the MP as well.
name|virtual
name|void
name|addModuleProvider
argument_list|(
argument|ModuleProvider *P
argument_list|)
block|{
name|Modules
operator|.
name|push_back
argument_list|(
name|P
argument_list|)
block|;   }
comment|//===----------------------------------------------------------------------===//
specifier|const
name|TargetData
operator|*
name|getTargetData
argument_list|()
specifier|const
block|{
return|return
name|TD
return|;
block|}
comment|/// removeModuleProvider - Remove a ModuleProvider from the list of modules.
comment|/// Relases the Module from the ModuleProvider, materializing it in the
comment|/// process, and returns the materialized Module.
name|virtual
name|Module
modifier|*
name|removeModuleProvider
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
decl_stmt|;
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
decl_stmt|;
comment|/// FindFunctionNamed - Search all of the active modules to find the one that
comment|/// defines FnName.  This is very slow operation and shouldn't be used for
comment|/// general code.
name|Function
modifier|*
name|FindFunctionNamed
parameter_list|(
specifier|const
name|char
modifier|*
name|FnName
parameter_list|)
function_decl|;
comment|/// runFunction - Execute the specified function with the specified arguments,
comment|/// and return the result.
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
init|=
literal|0
decl_stmt|;
comment|/// runStaticConstructorsDestructors - This method is used to execute all of
comment|/// the static constructors or destructors for a program, depending on the
comment|/// value of isDtors.
name|void
name|runStaticConstructorsDestructors
parameter_list|(
name|bool
name|isDtors
parameter_list|)
function_decl|;
comment|/// runStaticConstructorsDestructors - This method is used to execute all of
comment|/// the static constructors or destructors for a module, depending on the
comment|/// value of isDtors.
name|void
name|runStaticConstructorsDestructors
parameter_list|(
name|Module
modifier|*
name|module
parameter_list|,
name|bool
name|isDtors
parameter_list|)
function_decl|;
comment|/// runFunctionAsMain - This is a helper function which wraps runFunction to
comment|/// handle the common task of starting up main with the specified argc, argv,
comment|/// and envp parameters.
name|int
name|runFunctionAsMain
argument_list|(
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
name|string
operator|>
operator|&
name|argv
argument_list|,
specifier|const
name|char
operator|*
specifier|const
operator|*
name|envp
argument_list|)
decl_stmt|;
comment|/// addGlobalMapping - Tell the execution engine that the specified global is
comment|/// at the specified location.  This is used internally as functions are JIT'd
comment|/// and as global variables are laid out in memory.  It can and should also be
comment|/// used by clients of the EE that want to have an LLVM global overlay
comment|/// existing data in memory.  Mappings are automatically removed when their
comment|/// GlobalValue is destroyed.
name|void
name|addGlobalMapping
parameter_list|(
specifier|const
name|GlobalValue
modifier|*
name|GV
parameter_list|,
name|void
modifier|*
name|Addr
parameter_list|)
function_decl|;
comment|/// clearAllGlobalMappings - Clear all global mappings and start over again
comment|/// use in dynamic compilation scenarios when you want to move globals
name|void
name|clearAllGlobalMappings
parameter_list|()
function_decl|;
comment|/// clearGlobalMappingsFromModule - Clear all global mappings that came from a
comment|/// particular module, because it has been removed from the JIT.
name|void
name|clearGlobalMappingsFromModule
parameter_list|(
name|Module
modifier|*
name|M
parameter_list|)
function_decl|;
comment|/// updateGlobalMapping - Replace an existing mapping for GV with a new
comment|/// address.  This updates both maps as required.  If "Addr" is null, the
comment|/// entry for the global is removed from the mappings.  This returns the old
comment|/// value of the pointer, or null if it was not in the map.
name|void
modifier|*
name|updateGlobalMapping
parameter_list|(
specifier|const
name|GlobalValue
modifier|*
name|GV
parameter_list|,
name|void
modifier|*
name|Addr
parameter_list|)
function_decl|;
comment|/// getPointerToGlobalIfAvailable - This returns the address of the specified
comment|/// global value if it is has already been codegen'd, otherwise it returns
comment|/// null.
comment|///
name|void
modifier|*
name|getPointerToGlobalIfAvailable
parameter_list|(
specifier|const
name|GlobalValue
modifier|*
name|GV
parameter_list|)
function_decl|;
comment|/// getPointerToGlobal - This returns the address of the specified global
comment|/// value.  This may involve code generation if it's a function.
comment|///
name|void
modifier|*
name|getPointerToGlobal
parameter_list|(
specifier|const
name|GlobalValue
modifier|*
name|GV
parameter_list|)
function_decl|;
comment|/// getPointerToFunction - The different EE's represent function bodies in
comment|/// different ways.  They should each implement this to say what a function
comment|/// pointer should look like.  When F is destroyed, the ExecutionEngine will
comment|/// remove its global mapping and free any machine code.  Be sure no threads
comment|/// are running inside F when that happens.
comment|///
name|virtual
name|void
modifier|*
name|getPointerToFunction
parameter_list|(
name|Function
modifier|*
name|F
parameter_list|)
init|=
literal|0
function_decl|;
comment|/// getPointerToBasicBlock - The different EE's represent basic blocks in
comment|/// different ways.  Return the representation for a blockaddress of the
comment|/// specified block.
comment|///
name|virtual
name|void
modifier|*
name|getPointerToBasicBlock
parameter_list|(
name|BasicBlock
modifier|*
name|BB
parameter_list|)
init|=
literal|0
function_decl|;
comment|/// getPointerToFunctionOrStub - If the specified function has been
comment|/// code-gen'd, return a pointer to the function.  If not, compile it, or use
comment|/// a stub to implement lazy compilation if available.  See
comment|/// getPointerToFunction for the requirements on destroying F.
comment|///
name|virtual
name|void
modifier|*
name|getPointerToFunctionOrStub
parameter_list|(
name|Function
modifier|*
name|F
parameter_list|)
block|{
comment|// Default implementation, just codegen the function.
return|return
name|getPointerToFunction
argument_list|(
name|F
argument_list|)
return|;
block|}
comment|// The JIT overrides a version that actually does this.
name|virtual
name|void
name|runJITOnFunction
parameter_list|(
name|Function
modifier|*
parameter_list|,
name|MachineCodeInfo
modifier|*
init|=
literal|0
parameter_list|)
block|{ }
comment|/// getGlobalValueAtAddress - Return the LLVM global value object that starts
comment|/// at the specified address.
comment|///
specifier|const
name|GlobalValue
modifier|*
name|getGlobalValueAtAddress
parameter_list|(
name|void
modifier|*
name|Addr
parameter_list|)
function_decl|;
name|void
name|StoreValueToMemory
parameter_list|(
specifier|const
name|GenericValue
modifier|&
name|Val
parameter_list|,
name|GenericValue
modifier|*
name|Ptr
parameter_list|,
specifier|const
name|Type
modifier|*
name|Ty
parameter_list|)
function_decl|;
name|void
name|InitializeMemory
parameter_list|(
specifier|const
name|Constant
modifier|*
name|Init
parameter_list|,
name|void
modifier|*
name|Addr
parameter_list|)
function_decl|;
comment|/// recompileAndRelinkFunction - This method is used to force a function
comment|/// which has already been compiled to be compiled again, possibly
comment|/// after it has been modified. Then the entry to the old copy is overwritten
comment|/// with a branch to the new copy. If there was no old copy, this acts
comment|/// just like VM::getPointerToFunction().
comment|///
name|virtual
name|void
modifier|*
name|recompileAndRelinkFunction
parameter_list|(
name|Function
modifier|*
name|F
parameter_list|)
init|=
literal|0
function_decl|;
comment|/// freeMachineCodeForFunction - Release memory in the ExecutionEngine
comment|/// corresponding to the machine code emitted to execute this function, useful
comment|/// for garbage-collecting generated code.
comment|///
name|virtual
name|void
name|freeMachineCodeForFunction
parameter_list|(
name|Function
modifier|*
name|F
parameter_list|)
init|=
literal|0
function_decl|;
comment|/// getOrEmitGlobalVariable - Return the address of the specified global
comment|/// variable, possibly emitting it to memory if needed.  This is used by the
comment|/// Emitter.
name|virtual
name|void
modifier|*
name|getOrEmitGlobalVariable
parameter_list|(
specifier|const
name|GlobalVariable
modifier|*
name|GV
parameter_list|)
block|{
return|return
name|getPointerToGlobal
argument_list|(
operator|(
name|GlobalValue
operator|*
operator|)
name|GV
argument_list|)
return|;
block|}
comment|/// Registers a listener to be called back on various events within
comment|/// the JIT.  See JITEventListener.h for more details.  Does not
comment|/// take ownership of the argument.  The argument may be NULL, in
comment|/// which case these functions do nothing.
name|virtual
name|void
name|RegisterJITEventListener
parameter_list|(
name|JITEventListener
modifier|*
parameter_list|)
block|{}
name|virtual
name|void
name|UnregisterJITEventListener
parameter_list|(
name|JITEventListener
modifier|*
parameter_list|)
block|{}
comment|/// DisableLazyCompilation - When lazy compilation is off (the default), the
comment|/// JIT will eagerly compile every function reachable from the argument to
comment|/// getPointerToFunction.  If lazy compilation is turned on, the JIT will only
comment|/// compile the one function and emit stubs to compile the rest when they're
comment|/// first called.  If lazy compilation is turned off again while some lazy
comment|/// stubs are still around, and one of those stubs is called, the program will
comment|/// abort.
comment|///
comment|/// In order to safely compile lazily in a threaded program, the user must
comment|/// ensure that 1) only one thread at a time can call any particular lazy
comment|/// stub, and 2) any thread modifying LLVM IR must hold the JIT's lock
comment|/// (ExecutionEngine::lock) or otherwise ensure that no other thread calls a
comment|/// lazy stub.  See http://llvm.org/PR5184 for details.
name|void
name|DisableLazyCompilation
parameter_list|(
name|bool
name|Disabled
init|=
name|true
parameter_list|)
block|{
name|CompilingLazily
operator|=
operator|!
name|Disabled
expr_stmt|;
block|}
name|bool
name|isCompilingLazily
argument_list|()
specifier|const
block|{
return|return
name|CompilingLazily
return|;
block|}
comment|// Deprecated in favor of isCompilingLazily (to reduce double-negatives).
comment|// Remove this in LLVM 2.8.
name|bool
name|isLazyCompilationDisabled
argument_list|()
specifier|const
block|{
return|return
operator|!
name|CompilingLazily
return|;
block|}
comment|/// DisableGVCompilation - If called, the JIT will abort if it's asked to
comment|/// allocate space and populate a GlobalVariable that is not internal to
comment|/// the module.
name|void
name|DisableGVCompilation
parameter_list|(
name|bool
name|Disabled
init|=
name|true
parameter_list|)
block|{
name|GVCompilationDisabled
operator|=
name|Disabled
expr_stmt|;
block|}
name|bool
name|isGVCompilationDisabled
argument_list|()
specifier|const
block|{
return|return
name|GVCompilationDisabled
return|;
block|}
comment|/// DisableSymbolSearching - If called, the JIT will not try to lookup unknown
comment|/// symbols with dlsym.  A client can still use InstallLazyFunctionCreator to
comment|/// resolve symbols in a custom way.
name|void
name|DisableSymbolSearching
parameter_list|(
name|bool
name|Disabled
init|=
name|true
parameter_list|)
block|{
name|SymbolSearchingDisabled
operator|=
name|Disabled
expr_stmt|;
block|}
name|bool
name|isSymbolSearchingDisabled
argument_list|()
specifier|const
block|{
return|return
name|SymbolSearchingDisabled
return|;
block|}
comment|/// EnableDlsymStubs -
name|void
name|EnableDlsymStubs
parameter_list|(
name|bool
name|Enabled
init|=
name|true
parameter_list|)
block|{
name|DlsymStubsEnabled
operator|=
name|Enabled
expr_stmt|;
block|}
name|bool
name|areDlsymStubsEnabled
argument_list|()
specifier|const
block|{
return|return
name|DlsymStubsEnabled
return|;
block|}
comment|/// InstallLazyFunctionCreator - If an unknown function is needed, the
comment|/// specified function pointer is invoked to create it.  If it returns null,
comment|/// the JIT will abort.
name|void
name|InstallLazyFunctionCreator
argument_list|(
name|void
operator|*
call|(
modifier|*
name|P
call|)
argument_list|(
specifier|const
name|std
operator|::
name|string
operator|&
argument_list|)
argument_list|)
block|{
name|LazyFunctionCreator
operator|=
name|P
expr_stmt|;
block|}
comment|/// InstallExceptionTableRegister - The JIT will use the given function
comment|/// to register the exception tables it generates.
specifier|static
name|void
name|InstallExceptionTableRegister
parameter_list|(
name|void
function_decl|(
modifier|*
name|F
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|)
parameter_list|)
block|{
name|ExceptionTableRegister
operator|=
name|F
expr_stmt|;
block|}
comment|/// RegisterTable - Registers the given pointer as an exception table. It uses
comment|/// the ExceptionTableRegister function.
specifier|static
name|void
name|RegisterTable
parameter_list|(
name|void
modifier|*
name|res
parameter_list|)
block|{
if|if
condition|(
name|ExceptionTableRegister
condition|)
name|ExceptionTableRegister
argument_list|(
name|res
argument_list|)
expr_stmt|;
block|}
name|protected
label|:
name|explicit
name|ExecutionEngine
parameter_list|(
name|ModuleProvider
modifier|*
name|P
parameter_list|)
function_decl|;
name|void
name|emitGlobals
parameter_list|()
function_decl|;
comment|// EmitGlobalVariable - This method emits the specified global variable to the
comment|// address specified in GlobalAddresses, or allocates new memory if it's not
comment|// already in the map.
name|void
name|EmitGlobalVariable
parameter_list|(
specifier|const
name|GlobalVariable
modifier|*
name|GV
parameter_list|)
function_decl|;
name|GenericValue
name|getConstantValue
parameter_list|(
specifier|const
name|Constant
modifier|*
name|C
parameter_list|)
function_decl|;
name|void
name|LoadValueFromMemory
parameter_list|(
name|GenericValue
modifier|&
name|Result
parameter_list|,
name|GenericValue
modifier|*
name|Ptr
parameter_list|,
specifier|const
name|Type
modifier|*
name|Ty
parameter_list|)
function_decl|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_decl_stmt
name|namespace
name|EngineKind
block|{
comment|// These are actually bitmasks that get or-ed together.
enum|enum
name|Kind
block|{
name|JIT
init|=
literal|0x1
block|,
name|Interpreter
init|=
literal|0x2
block|}
enum|;
specifier|const
specifier|static
name|Kind
name|Either
init|=
call|(
name|Kind
call|)
argument_list|(
name|JIT
operator||
name|Interpreter
argument_list|)
decl_stmt|;
block|}
end_decl_stmt

begin_comment
comment|/// EngineBuilder - Builder class for ExecutionEngines.  Use this by
end_comment

begin_comment
comment|/// stack-allocating a builder, chaining the various set* methods, and
end_comment

begin_comment
comment|/// terminating it with a .create() call.
end_comment

begin_decl_stmt
name|class
name|EngineBuilder
block|{
name|private
label|:
name|ModuleProvider
modifier|*
name|MP
decl_stmt|;
name|EngineKind
operator|::
name|Kind
name|WhichEngine
expr_stmt|;
name|std
operator|::
name|string
operator|*
name|ErrorStr
expr_stmt|;
name|CodeGenOpt
operator|::
name|Level
name|OptLevel
expr_stmt|;
name|JITMemoryManager
modifier|*
name|JMM
decl_stmt|;
name|bool
name|AllocateGVsWithCode
decl_stmt|;
comment|/// InitEngine - Does the common initialization of default options.
comment|///
name|void
name|InitEngine
parameter_list|()
block|{
name|WhichEngine
operator|=
name|EngineKind
operator|::
name|Either
expr_stmt|;
name|ErrorStr
operator|=
name|NULL
expr_stmt|;
name|OptLevel
operator|=
name|CodeGenOpt
operator|::
name|Default
expr_stmt|;
name|JMM
operator|=
name|NULL
expr_stmt|;
name|AllocateGVsWithCode
operator|=
name|false
expr_stmt|;
block|}
name|public
label|:
comment|/// EngineBuilder - Constructor for EngineBuilder.  If create() is called and
comment|/// is successful, the created engine takes ownership of the module
comment|/// provider.
name|EngineBuilder
argument_list|(
name|ModuleProvider
operator|*
name|mp
argument_list|)
operator|:
name|MP
argument_list|(
argument|mp
argument_list|)
block|{
name|InitEngine
argument_list|()
block|;   }
comment|/// EngineBuilder - Overloaded constructor that automatically creates an
comment|/// ExistingModuleProvider for an existing module.
name|EngineBuilder
argument_list|(
name|Module
operator|*
name|m
argument_list|)
expr_stmt|;
comment|/// setEngineKind - Controls whether the user wants the interpreter, the JIT,
comment|/// or whichever engine works.  This option defaults to EngineKind::Either.
name|EngineBuilder
modifier|&
name|setEngineKind
argument_list|(
name|EngineKind
operator|::
name|Kind
name|w
argument_list|)
block|{
name|WhichEngine
operator|=
name|w
expr_stmt|;
return|return
operator|*
name|this
return|;
block|}
comment|/// setJITMemoryManager - Sets the memory manager to use.  This allows
comment|/// clients to customize their memory allocation policies.  If create() is
comment|/// called and is successful, the created engine takes ownership of the
comment|/// memory manager.  This option defaults to NULL.
name|EngineBuilder
modifier|&
name|setJITMemoryManager
parameter_list|(
name|JITMemoryManager
modifier|*
name|jmm
parameter_list|)
block|{
name|JMM
operator|=
name|jmm
expr_stmt|;
return|return
operator|*
name|this
return|;
block|}
comment|/// setErrorStr - Set the error string to write to on error.  This option
comment|/// defaults to NULL.
name|EngineBuilder
modifier|&
name|setErrorStr
argument_list|(
name|std
operator|::
name|string
operator|*
name|e
argument_list|)
block|{
name|ErrorStr
operator|=
name|e
expr_stmt|;
return|return
operator|*
name|this
return|;
block|}
comment|/// setOptLevel - Set the optimization level for the JIT.  This option
comment|/// defaults to CodeGenOpt::Default.
name|EngineBuilder
modifier|&
name|setOptLevel
argument_list|(
name|CodeGenOpt
operator|::
name|Level
name|l
argument_list|)
block|{
name|OptLevel
operator|=
name|l
expr_stmt|;
return|return
operator|*
name|this
return|;
block|}
comment|/// setAllocateGVsWithCode - Sets whether global values should be allocated
comment|/// into the same buffer as code.  For most applications this should be set
comment|/// to false.  Allocating globals with code breaks freeMachineCodeForFunction
comment|/// and is probably unsafe and bad for performance.  However, we have clients
comment|/// who depend on this behavior, so we must support it.  This option defaults
comment|/// to false so that users of the new API can safely use the new memory
comment|/// manager and free machine code.
name|EngineBuilder
modifier|&
name|setAllocateGVsWithCode
parameter_list|(
name|bool
name|a
parameter_list|)
block|{
name|AllocateGVsWithCode
operator|=
name|a
expr_stmt|;
return|return
operator|*
name|this
return|;
block|}
name|ExecutionEngine
modifier|*
name|create
parameter_list|()
function_decl|;
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

