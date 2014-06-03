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
name|LLVM_EXECUTIONENGINE_EXECUTIONENGINE_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_EXECUTIONENGINE_EXECUTIONENGINE_H
end_define

begin_include
include|#
directive|include
file|"llvm-c/ExecutionEngine.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/SmallVector.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/StringRef.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/ValueMap.h"
end_include

begin_include
include|#
directive|include
file|"llvm/MC/MCCodeGenInfo.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/ErrorHandling.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/Mutex.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/ValueHandle.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Target/TargetMachine.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Target/TargetOptions.h"
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
file|<vector>
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
name|DataLayout
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
name|MutexGuard
decl_stmt|;
name|class
name|ObjectCache
decl_stmt|;
name|class
name|RTDyldMemoryManager
decl_stmt|;
name|class
name|Triple
decl_stmt|;
name|class
name|Type
decl_stmt|;
comment|/// \brief Helper class for helping synchronize access to the global address map
comment|/// table.
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
comment|/// \brief Erase an entry from the mapping table.
comment|///
comment|/// \returns The address that \p ToUnmap was happed to.
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

begin_comment
comment|/// \brief Abstract interface for implementation execution of LLVM modules,
end_comment

begin_comment
comment|/// designed to support both interpreter and just-in-time (JIT) compiler
end_comment

begin_comment
comment|/// implementations.
end_comment

begin_decl_stmt
name|class
name|ExecutionEngine
block|{
comment|/// The state object holding the global address mapping, which must be
comment|/// accessed synchronously.
comment|//
comment|// FIXME: There is no particular need the entire map needs to be
comment|// synchronized.  Wouldn't a reader-writer design be better here?
name|ExecutionEngineState
name|EEState
decl_stmt|;
comment|/// The target data for the platform for which execution is being performed.
specifier|const
name|DataLayout
modifier|*
name|TD
decl_stmt|;
comment|/// Whether lazy JIT compilation is enabled.
name|bool
name|CompilingLazily
decl_stmt|;
comment|/// Whether JIT compilation of external global variables is allowed.
name|bool
name|GVCompilationDisabled
decl_stmt|;
comment|/// Whether the JIT should perform lookups of external symbols (e.g.,
comment|/// using dlsym).
name|bool
name|SymbolSearchingDisabled
decl_stmt|;
name|friend
name|class
name|EngineBuilder
decl_stmt|;
comment|// To allow access to JITCtor and InterpCtor.
name|protected
label|:
comment|/// The list of Modules that we are JIT'ing from.  We use a SmallVector to
comment|/// optimize for the case where there is only one module.
name|SmallVector
operator|<
name|Module
operator|*
operator|,
literal|1
operator|>
name|Modules
expr_stmt|;
name|void
name|setDataLayout
parameter_list|(
specifier|const
name|DataLayout
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
comment|// libraries, the execution engine implementations set these functions to ctor
comment|// pointers at startup time if they are linked in.
specifier|static
name|ExecutionEngine
operator|*
operator|(
operator|*
name|JITCtor
operator|)
operator|(
name|Module
operator|*
name|M
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
name|bool
name|GVsWithCode
operator|,
name|TargetMachine
operator|*
name|TM
operator|)
expr_stmt|;
specifier|static
name|ExecutionEngine
operator|*
operator|(
operator|*
name|MCJITCtor
operator|)
operator|(
name|Module
operator|*
name|M
operator|,
name|std
operator|::
name|string
operator|*
name|ErrorStr
operator|,
name|RTDyldMemoryManager
operator|*
name|MCJMM
operator|,
name|bool
name|GVsWithCode
operator|,
name|TargetMachine
operator|*
name|TM
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
name|Module
operator|*
name|M
argument_list|,
name|std
operator|::
name|string
operator|*
name|ErrorStr
argument_list|)
expr_stmt|;
comment|/// LazyFunctionCreator - If an unknown function is needed, this function
comment|/// pointer is invoked to create it.  If this returns null, the JIT will
comment|/// abort.
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
name|public
operator|:
comment|/// lock - This lock protects the ExecutionEngine, MCJIT, JIT, JITResolver and
comment|/// JITEmitter classes.  It must be held while changing the internal state of
comment|/// any of those classes.
name|sys
operator|::
name|Mutex
name|lock
argument_list|;
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
comment|/// module.
comment|///
comment|/// \param GVsWithCode - Allocating globals with code breaks
comment|/// freeMachineCodeForFunction and is probably unsafe and bad for performance.
comment|/// However, we have clients who depend on this behavior, so we must support
comment|/// it.  Eventually, when we're willing to break some backwards compatibility,
comment|/// this flag should be flipped to false, so that by default
comment|/// freeMachineCodeForFunction works.
specifier|static
name|ExecutionEngine
operator|*
name|create
argument_list|(
argument|Module *M
argument_list|,
argument|bool ForceInterpreter = false
argument_list|,
argument|std::string *ErrorStr =
literal|0
argument_list|,
argument|CodeGenOpt::Level OptLevel =                                  CodeGenOpt::Default
argument_list|,
argument|bool GVsWithCode = true
argument_list|)
argument_list|;
comment|/// createJIT - This is the factory method for creating a JIT for the current
comment|/// machine, it does not fall back to the interpreter.  This takes ownership
comment|/// of the Module and JITMemoryManager if successful.
comment|///
comment|/// Clients should make sure to initialize targets prior to calling this
comment|/// function.
specifier|static
name|ExecutionEngine
operator|*
name|createJIT
argument_list|(
argument|Module *M
argument_list|,
argument|std::string *ErrorStr =
literal|0
argument_list|,
argument|JITMemoryManager *JMM =
literal|0
argument_list|,
argument|CodeGenOpt::Level OptLevel =                                     CodeGenOpt::Default
argument_list|,
argument|bool GVsWithCode = true
argument_list|,
argument|Reloc::Model RM = Reloc::Default
argument_list|,
argument|CodeModel::Model CMM =                                     CodeModel::JITDefault
argument_list|)
argument_list|;
comment|/// addModule - Add a Module to the list of modules that we can JIT from.
comment|/// Note that this takes ownership of the Module: when the ExecutionEngine is
comment|/// destroyed, it destroys the Module as well.
name|virtual
name|void
name|addModule
argument_list|(
argument|Module *M
argument_list|)
block|{
name|Modules
operator|.
name|push_back
argument_list|(
name|M
argument_list|)
block|;   }
comment|//===--------------------------------------------------------------------===//
specifier|const
name|DataLayout
operator|*
name|getDataLayout
argument_list|()
specifier|const
block|{
return|return
name|TD
return|;
block|}
comment|/// removeModule - Remove a Module from the list of modules.  Returns true if
comment|/// M is found.
name|virtual
name|bool
name|removeModule
parameter_list|(
name|Module
modifier|*
name|M
parameter_list|)
function_decl|;
comment|/// FindFunctionNamed - Search all of the active modules to find the one that
comment|/// defines FnName.  This is very slow operation and shouldn't be used for
comment|/// general code.
name|virtual
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
comment|/// getPointerToNamedFunction - This method returns the address of the
comment|/// specified function by using the dlsym function call.  As such it is only
comment|/// useful for resolving library symbols, not code generated symbols.
comment|///
comment|/// If AbortOnFailure is false and no function with the given name is
comment|/// found, this function silently returns a null pointer. Otherwise,
comment|/// it prints a message to stderr and aborts.
comment|///
comment|/// This function is deprecated for the MCJIT execution engine.
comment|///
comment|/// FIXME: the JIT and MCJIT interfaces should be disentangled or united
comment|/// again, if possible.
comment|///
name|virtual
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
init|=
literal|0
decl_stmt|;
comment|/// mapSectionAddress - map a section to its target address space value.
comment|/// Map the address of a JIT section as returned from the memory manager
comment|/// to the address in the target process as the running code will see it.
comment|/// This is the address which will be used for relocation resolution.
name|virtual
name|void
name|mapSectionAddress
parameter_list|(
specifier|const
name|void
modifier|*
name|LocalAddress
parameter_list|,
name|uint64_t
name|TargetAddress
parameter_list|)
block|{
name|llvm_unreachable
argument_list|(
literal|"Re-mapping of section addresses not supported with this "
literal|"EE!"
argument_list|)
expr_stmt|;
block|}
comment|/// generateCodeForModule - Run code generationen for the specified module and
comment|/// load it into memory.
comment|///
comment|/// When this function has completed, all code and data for the specified
comment|/// module, and any module on which this module depends, will be generated
comment|/// and loaded into memory, but relocations will not yet have been applied
comment|/// and all memory will be readable and writable but not executable.
comment|///
comment|/// This function is primarily useful when generating code for an external
comment|/// target, allowing the client an opportunity to remap section addresses
comment|/// before relocations are applied.  Clients that intend to execute code
comment|/// locally can use the getFunctionAddress call, which will generate code
comment|/// and apply final preparations all in one step.
comment|///
comment|/// This method has no effect for the legacy JIT engine or the interpeter.
name|virtual
name|void
name|generateCodeForModule
parameter_list|(
name|Module
modifier|*
name|M
parameter_list|)
block|{}
comment|/// finalizeObject - ensure the module is fully processed and is usable.
comment|///
comment|/// It is the user-level function for completing the process of making the
comment|/// object usable for execution.  It should be called after sections within an
comment|/// object have been relocated using mapSectionAddress.  When this method is
comment|/// called the MCJIT execution engine will reapply relocations for a loaded
comment|/// object.  This method has no effect for the legacy JIT engine or the
comment|/// interpeter.
name|virtual
name|void
name|finalizeObject
parameter_list|()
block|{}
comment|/// runStaticConstructorsDestructors - This method is used to execute all of
comment|/// the static constructors or destructors for a program.
comment|///
comment|/// \param isDtors - Run the destructors instead of constructors.
name|virtual
name|void
name|runStaticConstructorsDestructors
parameter_list|(
name|bool
name|isDtors
parameter_list|)
function_decl|;
comment|/// runStaticConstructorsDestructors - This method is used to execute all of
comment|/// the static constructors or destructors for a particular module.
comment|///
comment|/// \param isDtors - Run the destructors instead of constructors.
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
comment|/// clearAllGlobalMappings - Clear all global mappings and start over again,
comment|/// for use in dynamic compilation scenarios to move globals.
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
comment|/// This function is deprecated for the MCJIT execution engine.  It doesn't
comment|/// seem to be needed in that case, but an equivalent can be added if it is.
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
comment|/// value. This may involve code generation if it's a function.
comment|///
comment|/// This function is deprecated for the MCJIT execution engine.  Use
comment|/// getGlobalValueAddress instead.
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
comment|/// This function is deprecated for the MCJIT execution engine.  Use
comment|/// getFunctionAddress instead.
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
comment|/// This function will not be implemented for the MCJIT execution engine.
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
comment|/// This function is deprecated for the MCJIT execution engine.  Use
comment|/// getFunctionAddress instead.
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
comment|/// getGlobalValueAddress - Return the address of the specified global
comment|/// value. This may involve code generation.
comment|///
comment|/// This function should not be called with the JIT or interpreter engines.
name|virtual
name|uint64_t
name|getGlobalValueAddress
argument_list|(
specifier|const
name|std
operator|::
name|string
operator|&
name|Name
argument_list|)
block|{
comment|// Default implementation for JIT and interpreter.  MCJIT will override this.
comment|// JIT and interpreter clients should use getPointerToGlobal instead.
return|return
literal|0
return|;
block|}
comment|/// getFunctionAddress - Return the address of the specified function.
comment|/// This may involve code generation.
name|virtual
name|uint64_t
name|getFunctionAddress
argument_list|(
specifier|const
name|std
operator|::
name|string
operator|&
name|Name
argument_list|)
block|{
comment|// Default implementation for JIT and interpreter.  MCJIT will override this.
comment|// JIT and interpreter clients should use getPointerToFunction instead.
return|return
literal|0
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
comment|/// StoreValueToMemory - Stores the data in Val of type Ty at address Ptr.
comment|/// Ptr is the address of the memory at which to store Val, cast to
comment|/// GenericValue *.  It is not a pointer to a GenericValue containing the
comment|/// address at which to store Val.
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
comment|/// recompileAndRelinkFunction - This method is used to force a function which
comment|/// has already been compiled to be compiled again, possibly after it has been
comment|/// modified.  Then the entry to the old copy is overwritten with a branch to
comment|/// the new copy.  If there was no old copy, this acts just like
comment|/// VM::getPointerToFunction().
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
comment|///
comment|/// This function is deprecated for the MCJIT execution engine.  Use
comment|/// getGlobalValueAddress instead.
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
specifier|const
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
comment|/// Sets the pre-compiled object cache.  The ownership of the ObjectCache is
comment|/// not changed.  Supported by MCJIT but not JIT.
name|virtual
name|void
name|setObjectCache
parameter_list|(
name|ObjectCache
modifier|*
parameter_list|)
block|{
name|llvm_unreachable
argument_list|(
literal|"No support for an object cache"
argument_list|)
expr_stmt|;
block|}
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
name|protected
label|:
name|explicit
name|ExecutionEngine
parameter_list|(
name|Module
modifier|*
name|M
parameter_list|)
function_decl|;
name|void
name|emitGlobals
parameter_list|()
function_decl|;
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
name|Module
modifier|*
name|M
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
name|RTDyldMemoryManager
modifier|*
name|MCJMM
decl_stmt|;
name|JITMemoryManager
modifier|*
name|JMM
decl_stmt|;
name|bool
name|AllocateGVsWithCode
decl_stmt|;
name|TargetOptions
name|Options
decl_stmt|;
name|Reloc
operator|::
name|Model
name|RelocModel
expr_stmt|;
name|CodeModel
operator|::
name|Model
name|CMModel
expr_stmt|;
name|std
operator|::
name|string
name|MArch
expr_stmt|;
name|std
operator|::
name|string
name|MCPU
expr_stmt|;
name|SmallVector
operator|<
name|std
operator|::
name|string
operator|,
literal|4
operator|>
name|MAttrs
expr_stmt|;
name|bool
name|UseMCJIT
decl_stmt|;
comment|/// InitEngine - Does the common initialization of default options.
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
name|MCJMM
operator|=
name|NULL
expr_stmt|;
name|JMM
operator|=
name|NULL
expr_stmt|;
name|Options
operator|=
name|TargetOptions
argument_list|()
expr_stmt|;
name|AllocateGVsWithCode
operator|=
name|false
expr_stmt|;
name|RelocModel
operator|=
name|Reloc
operator|::
name|Default
expr_stmt|;
name|CMModel
operator|=
name|CodeModel
operator|::
name|JITDefault
expr_stmt|;
name|UseMCJIT
operator|=
name|false
expr_stmt|;
block|}
name|public
label|:
comment|/// EngineBuilder - Constructor for EngineBuilder.  If create() is called and
comment|/// is successful, the created engine takes ownership of the module.
name|EngineBuilder
argument_list|(
name|Module
operator|*
name|m
argument_list|)
operator|:
name|M
argument_list|(
argument|m
argument_list|)
block|{
name|InitEngine
argument_list|()
block|;   }
comment|/// setEngineKind - Controls whether the user wants the interpreter, the JIT,
comment|/// or whichever engine works.  This option defaults to EngineKind::Either.
name|EngineBuilder
operator|&
name|setEngineKind
argument_list|(
argument|EngineKind::Kind w
argument_list|)
block|{
name|WhichEngine
operator|=
name|w
block|;
return|return
operator|*
name|this
return|;
block|}
comment|/// setMCJITMemoryManager - Sets the MCJIT memory manager to use. This allows
comment|/// clients to customize their memory allocation policies for the MCJIT. This
comment|/// is only appropriate for the MCJIT; setting this and configuring the builder
comment|/// to create anything other than MCJIT will cause a runtime error. If create()
comment|/// is called and is successful, the created engine takes ownership of the
comment|/// memory manager. This option defaults to NULL. Using this option nullifies
comment|/// the setJITMemoryManager() option.
name|EngineBuilder
modifier|&
name|setMCJITMemoryManager
parameter_list|(
name|RTDyldMemoryManager
modifier|*
name|mcjmm
parameter_list|)
block|{
name|MCJMM
operator|=
name|mcjmm
expr_stmt|;
name|JMM
operator|=
name|NULL
expr_stmt|;
return|return
operator|*
name|this
return|;
block|}
comment|/// setJITMemoryManager - Sets the JIT memory manager to use.  This allows
comment|/// clients to customize their memory allocation policies.  This is only
comment|/// appropriate for either JIT or MCJIT; setting this and configuring the
comment|/// builder to create an interpreter will cause a runtime error. If create()
comment|/// is called and is successful, the created engine takes ownership of the
comment|/// memory manager.  This option defaults to NULL. This option overrides
comment|/// setMCJITMemoryManager() as well.
name|EngineBuilder
modifier|&
name|setJITMemoryManager
parameter_list|(
name|JITMemoryManager
modifier|*
name|jmm
parameter_list|)
block|{
name|MCJMM
operator|=
name|NULL
expr_stmt|;
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
comment|/// setTargetOptions - Set the target options that the ExecutionEngine
comment|/// target is using. Defaults to TargetOptions().
name|EngineBuilder
modifier|&
name|setTargetOptions
parameter_list|(
specifier|const
name|TargetOptions
modifier|&
name|Opts
parameter_list|)
block|{
name|Options
operator|=
name|Opts
expr_stmt|;
return|return
operator|*
name|this
return|;
block|}
comment|/// setRelocationModel - Set the relocation model that the ExecutionEngine
comment|/// target is using. Defaults to target specific default "Reloc::Default".
name|EngineBuilder
modifier|&
name|setRelocationModel
argument_list|(
name|Reloc
operator|::
name|Model
name|RM
argument_list|)
block|{
name|RelocModel
operator|=
name|RM
expr_stmt|;
return|return
operator|*
name|this
return|;
block|}
comment|/// setCodeModel - Set the CodeModel that the ExecutionEngine target
comment|/// data is using. Defaults to target specific default
comment|/// "CodeModel::JITDefault".
name|EngineBuilder
modifier|&
name|setCodeModel
argument_list|(
name|CodeModel
operator|::
name|Model
name|M
argument_list|)
block|{
name|CMModel
operator|=
name|M
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
comment|/// setMArch - Override the architecture set by the Module's triple.
name|EngineBuilder
modifier|&
name|setMArch
parameter_list|(
name|StringRef
name|march
parameter_list|)
block|{
name|MArch
operator|.
name|assign
argument_list|(
name|march
operator|.
name|begin
argument_list|()
argument_list|,
name|march
operator|.
name|end
argument_list|()
argument_list|)
expr_stmt|;
return|return
operator|*
name|this
return|;
block|}
comment|/// setMCPU - Target a specific cpu type.
name|EngineBuilder
modifier|&
name|setMCPU
parameter_list|(
name|StringRef
name|mcpu
parameter_list|)
block|{
name|MCPU
operator|.
name|assign
argument_list|(
name|mcpu
operator|.
name|begin
argument_list|()
argument_list|,
name|mcpu
operator|.
name|end
argument_list|()
argument_list|)
expr_stmt|;
return|return
operator|*
name|this
return|;
block|}
comment|/// setUseMCJIT - Set whether the MC-JIT implementation should be used
comment|/// (experimental).
name|EngineBuilder
modifier|&
name|setUseMCJIT
parameter_list|(
name|bool
name|Value
parameter_list|)
block|{
name|UseMCJIT
operator|=
name|Value
expr_stmt|;
return|return
operator|*
name|this
return|;
block|}
comment|/// setMAttrs - Set cpu-specific attributes.
name|template
operator|<
name|typename
name|StringSequence
operator|>
name|EngineBuilder
operator|&
name|setMAttrs
argument_list|(
argument|const StringSequence&mattrs
argument_list|)
block|{
name|MAttrs
operator|.
name|clear
argument_list|()
block|;
name|MAttrs
operator|.
name|append
argument_list|(
name|mattrs
operator|.
name|begin
argument_list|()
argument_list|,
name|mattrs
operator|.
name|end
argument_list|()
argument_list|)
block|;
return|return
operator|*
name|this
return|;
block|}
name|TargetMachine
modifier|*
name|selectTarget
parameter_list|()
function_decl|;
comment|/// selectTarget - Pick a target either via -march or by guessing the native
comment|/// arch.  Add any CPU features specified via -mcpu or -mattr.
name|TargetMachine
modifier|*
name|selectTarget
argument_list|(
specifier|const
name|Triple
operator|&
name|TargetTriple
argument_list|,
name|StringRef
name|MArch
argument_list|,
name|StringRef
name|MCPU
argument_list|,
specifier|const
name|SmallVectorImpl
operator|<
name|std
operator|::
name|string
operator|>
operator|&
name|MAttrs
argument_list|)
decl_stmt|;
name|ExecutionEngine
modifier|*
name|create
parameter_list|()
block|{
return|return
name|create
argument_list|(
name|selectTarget
argument_list|()
argument_list|)
return|;
block|}
name|ExecutionEngine
modifier|*
name|create
parameter_list|(
name|TargetMachine
modifier|*
name|TM
parameter_list|)
function_decl|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|// Create wrappers for C Binding types (see CBindingWrapping.h).
end_comment

begin_macro
name|DEFINE_SIMPLE_CONVERSION_FUNCTIONS
argument_list|(
argument|ExecutionEngine
argument_list|,
argument|LLVMExecutionEngineRef
argument_list|)
end_macro

begin_comment
unit|}
comment|// End llvm namespace
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

