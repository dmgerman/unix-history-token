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
file|"llvm/ADT/ArrayRef.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/Optional.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/SmallVector.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/StringMap.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/StringRef.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ExecutionEngine/JITSymbol.h"
end_include

begin_include
include|#
directive|include
file|"llvm/IR/DataLayout.h"
end_include

begin_include
include|#
directive|include
file|"llvm/IR/Module.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Object/Binary.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/CBindingWrapping.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/CodeGen.h"
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
file|<algorithm>
end_include

begin_include
include|#
directive|include
file|<cstdint>
end_include

begin_include
include|#
directive|include
file|<functional>
end_include

begin_include
include|#
directive|include
file|<map>
end_include

begin_include
include|#
directive|include
file|<memory>
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
name|Constant
decl_stmt|;
name|class
name|Function
decl_stmt|;
struct_decl|struct
name|GenericValue
struct_decl|;
name|class
name|GlobalValue
decl_stmt|;
name|class
name|GlobalVariable
decl_stmt|;
name|class
name|JITEventListener
decl_stmt|;
name|class
name|MCJITMemoryManager
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
name|namespace
name|object
block|{
name|class
name|Archive
decl_stmt|;
name|class
name|ObjectFile
decl_stmt|;
block|}
comment|// end namespace object
comment|/// \brief Helper class for helping synchronize access to the global address map
comment|/// table.  Access to this class should be serialized under a mutex.
name|class
name|ExecutionEngineState
block|{
name|public
label|:
name|using
name|GlobalAddressMapTy
init|=
name|StringMap
operator|<
name|uint64_t
operator|>
decl_stmt|;
name|private
label|:
comment|/// GlobalAddressMap - A mapping between LLVM global symbol names values and
comment|/// their actualized version...
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
name|uint64_t
operator|,
name|std
operator|::
name|string
operator|>
name|GlobalAddressReverseMap
expr_stmt|;
name|public
label|:
name|GlobalAddressMapTy
modifier|&
name|getGlobalAddressMap
parameter_list|()
block|{
return|return
name|GlobalAddressMap
return|;
block|}
name|std
operator|::
name|map
operator|<
name|uint64_t
operator|,
name|std
operator|::
name|string
operator|>
operator|&
name|getGlobalAddressReverseMap
argument_list|()
block|{
return|return
name|GlobalAddressReverseMap
return|;
block|}
comment|/// \brief Erase an entry from the mapping table.
comment|///
comment|/// \returns The address that \p ToUnmap was happed to.
name|uint64_t
name|RemoveMapping
parameter_list|(
name|StringRef
name|Name
parameter_list|)
function_decl|;
block|}
empty_stmt|;
name|using
name|FunctionCreator
init|=
name|std
operator|::
name|function
operator|<
name|void
operator|*
operator|(
specifier|const
name|std
operator|::
name|string
operator|&
operator|)
operator|>
decl_stmt|;
comment|/// \brief Abstract interface for implementation execution of LLVM modules,
comment|/// designed to support both interpreter and just-in-time (JIT) compiler
comment|/// implementations.
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
comment|///
comment|/// Note: the DataLayout is LLVMContext specific because it has an
comment|/// internal cache based on type pointers. It makes unsafe to reuse the
comment|/// ExecutionEngine across context, we don't enforce this rule but undefined
comment|/// behavior can occurs if the user tries to do it.
specifier|const
name|DataLayout
name|DL
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
comment|/// Whether the JIT should verify IR modules during compilation.
name|bool
name|VerifyModules
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
name|std
operator|::
name|unique_ptr
operator|<
name|Module
operator|>
operator|,
literal|1
operator|>
name|Modules
expr_stmt|;
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
specifier|static
name|ExecutionEngine
operator|*
call|(
modifier|*
name|MCJITCtor
call|)
argument_list|(
name|std
operator|::
name|unique_ptr
operator|<
name|Module
operator|>
name|M
argument_list|,
name|std
operator|::
name|string
operator|*
name|ErrorStr
argument_list|,
name|std
operator|::
name|shared_ptr
operator|<
name|MCJITMemoryManager
operator|>
name|MM
argument_list|,
name|std
operator|::
name|shared_ptr
operator|<
name|JITSymbolResolver
operator|>
name|SR
argument_list|,
name|std
operator|::
name|unique_ptr
operator|<
name|TargetMachine
operator|>
name|TM
argument_list|)
expr_stmt|;
specifier|static
name|ExecutionEngine
operator|*
call|(
modifier|*
name|OrcMCJITReplacementCtor
call|)
argument_list|(
name|std
operator|::
name|string
operator|*
name|ErrorStr
argument_list|,
name|std
operator|::
name|shared_ptr
operator|<
name|MCJITMemoryManager
operator|>
name|MM
argument_list|,
name|std
operator|::
name|shared_ptr
operator|<
name|JITSymbolResolver
operator|>
name|SR
argument_list|,
name|std
operator|::
name|unique_ptr
operator|<
name|TargetMachine
operator|>
name|TM
argument_list|)
expr_stmt|;
specifier|static
name|ExecutionEngine
operator|*
call|(
modifier|*
name|InterpCtor
call|)
argument_list|(
name|std
operator|::
name|unique_ptr
operator|<
name|Module
operator|>
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
name|FunctionCreator
name|LazyFunctionCreator
decl_stmt|;
comment|/// getMangledName - Get mangled name.
name|std
operator|::
name|string
name|getMangledName
argument_list|(
specifier|const
name|GlobalValue
operator|*
name|GV
argument_list|)
expr_stmt|;
name|public
label|:
comment|/// lock - This lock protects the ExecutionEngine and MCJIT classes. It must
comment|/// be held while changing the internal state of any of those classes.
name|sys
operator|::
name|Mutex
name|lock
expr_stmt|;
comment|//===--------------------------------------------------------------------===//
comment|//  ExecutionEngine Startup
comment|//===--------------------------------------------------------------------===//
name|virtual
operator|~
name|ExecutionEngine
argument_list|()
expr_stmt|;
comment|/// Add a Module to the list of modules that we can JIT from.
name|virtual
name|void
name|addModule
argument_list|(
name|std
operator|::
name|unique_ptr
operator|<
name|Module
operator|>
name|M
argument_list|)
block|{
name|Modules
operator|.
name|push_back
argument_list|(
name|std
operator|::
name|move
argument_list|(
name|M
argument_list|)
argument_list|)
expr_stmt|;
block|}
comment|/// addObjectFile - Add an ObjectFile to the execution engine.
comment|///
comment|/// This method is only supported by MCJIT.  MCJIT will immediately load the
comment|/// object into memory and adds its symbols to the list used to resolve
comment|/// external symbols while preparing other objects for execution.
comment|///
comment|/// Objects added using this function will not be made executable until
comment|/// needed by another object.
comment|///
comment|/// MCJIT will take ownership of the ObjectFile.
name|virtual
name|void
name|addObjectFile
argument_list|(
name|std
operator|::
name|unique_ptr
operator|<
name|object
operator|::
name|ObjectFile
operator|>
name|O
argument_list|)
decl_stmt|;
name|virtual
name|void
name|addObjectFile
argument_list|(
name|object
operator|::
name|OwningBinary
operator|<
name|object
operator|::
name|ObjectFile
operator|>
name|O
argument_list|)
decl_stmt|;
comment|/// addArchive - Add an Archive to the execution engine.
comment|///
comment|/// This method is only supported by MCJIT.  MCJIT will use the archive to
comment|/// resolve external symbols in objects it is loading.  If a symbol is found
comment|/// in the Archive the contained object file will be extracted (in memory)
comment|/// and loaded for possible execution.
name|virtual
name|void
name|addArchive
argument_list|(
name|object
operator|::
name|OwningBinary
operator|<
name|object
operator|::
name|Archive
operator|>
name|A
argument_list|)
decl_stmt|;
comment|//===--------------------------------------------------------------------===//
specifier|const
name|DataLayout
operator|&
name|getDataLayout
argument_list|()
specifier|const
block|{
return|return
name|DL
return|;
block|}
comment|/// removeModule - Removes a Module from the list of modules, but does not
comment|/// free the module's memory. Returns true if M is found, in which case the
comment|/// caller assumes responsibility for deleting the module.
comment|//
comment|// FIXME: This stealth ownership transfer is horrible. This will probably be
comment|//        fixed by deleting ExecutionEngine.
name|virtual
name|bool
name|removeModule
parameter_list|(
name|Module
modifier|*
name|M
parameter_list|)
function_decl|;
comment|/// FindFunctionNamed - Search all of the active modules to find the function that
comment|/// defines FnName.  This is very slow operation and shouldn't be used for
comment|/// general code.
name|virtual
name|Function
modifier|*
name|FindFunctionNamed
parameter_list|(
name|StringRef
name|FnName
parameter_list|)
function_decl|;
comment|/// FindGlobalVariableNamed - Search all of the active modules to find the global variable
comment|/// that defines Name.  This is very slow operation and shouldn't be used for
comment|/// general code.
name|virtual
name|GlobalVariable
modifier|*
name|FindGlobalVariableNamed
parameter_list|(
name|StringRef
name|Name
parameter_list|,
name|bool
name|AllowInternal
init|=
name|false
parameter_list|)
function_decl|;
comment|/// runFunction - Execute the specified function with the specified arguments,
comment|/// and return the result.
comment|///
comment|/// For MCJIT execution engines, clients are encouraged to use the
comment|/// "GetFunctionAddress" method (rather than runFunction) and cast the
comment|/// returned uint64_t to the desired function pointer type. However, for
comment|/// backwards compatibility MCJIT's implementation can execute 'main-like'
comment|/// function (i.e. those returning void or int, and taking either no
comment|/// arguments or (int, char*[])).
name|virtual
name|GenericValue
name|runFunction
argument_list|(
name|Function
operator|*
name|F
argument_list|,
name|ArrayRef
operator|<
name|GenericValue
operator|>
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
name|virtual
name|void
modifier|*
name|getPointerToNamedFunction
parameter_list|(
name|StringRef
name|Name
parameter_list|,
name|bool
name|AbortOnFailure
init|=
name|true
parameter_list|)
init|=
literal|0
function_decl|;
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
comment|/// generateCodeForModule - Run code generation for the specified module and
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
comment|/// This method has no effect for the interpeter.
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
comment|/// object.  This method has no effect for the interpeter.
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
comment|/// This method is used to execute all of the static constructors or
comment|/// destructors for a particular module.
comment|///
comment|/// \param isDtors - Run the destructors instead of constructors.
name|void
name|runStaticConstructorsDestructors
parameter_list|(
name|Module
modifier|&
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
comment|/// existing data in memory. Values to be mapped should be named, and have
comment|/// external or weak linkage. Mappings are automatically removed when their
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
name|void
name|addGlobalMapping
parameter_list|(
name|StringRef
name|Name
parameter_list|,
name|uint64_t
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
name|uint64_t
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
name|uint64_t
name|updateGlobalMapping
parameter_list|(
name|StringRef
name|Name
parameter_list|,
name|uint64_t
name|Addr
parameter_list|)
function_decl|;
comment|/// getAddressToGlobalIfAvailable - This returns the address of the specified
comment|/// global symbol.
name|uint64_t
name|getAddressToGlobalIfAvailable
parameter_list|(
name|StringRef
name|S
parameter_list|)
function_decl|;
comment|/// getPointerToGlobalIfAvailable - This returns the address of the specified
comment|/// global value if it is has already been codegen'd, otherwise it returns
comment|/// null.
name|void
modifier|*
name|getPointerToGlobalIfAvailable
parameter_list|(
name|StringRef
name|S
parameter_list|)
function_decl|;
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
comment|/// This function should not be called with the interpreter engine.
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
comment|// Default implementation for the interpreter.  MCJIT will override this.
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
comment|// Default implementation for the interpreter.  MCJIT will override this.
comment|// Interpreter clients should use getPointerToFunction instead.
return|return
literal|0
return|;
block|}
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
comment|/// not changed.  Supported by MCJIT but not the interpreter.
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
comment|/// setProcessAllSections (MCJIT Only): By default, only sections that are
comment|/// "required for execution" are passed to the RTDyldMemoryManager, and other
comment|/// sections are discarded. Passing 'true' to this method will cause
comment|/// RuntimeDyld to pass all sections to its RTDyldMemoryManager regardless
comment|/// of whether they are "required to execute" in the usual sense.
comment|///
comment|/// Rationale: Some MCJIT clients want to be able to inspect metadata
comment|/// sections (e.g. Dwarf, Stack-maps) to enable functionality or analyze
comment|/// performance. Passing these sections to the memory manager allows the
comment|/// client to make policy about the relevant sections, rather than having
comment|/// MCJIT do it.
name|virtual
name|void
name|setProcessAllSections
parameter_list|(
name|bool
name|ProcessAllSections
parameter_list|)
block|{
name|llvm_unreachable
argument_list|(
literal|"No support for ProcessAllSections option"
argument_list|)
expr_stmt|;
block|}
comment|/// Return the target machine (if available).
name|virtual
name|TargetMachine
modifier|*
name|getTargetMachine
parameter_list|()
block|{
return|return
name|nullptr
return|;
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
comment|/// Enable/Disable IR module verification.
comment|///
comment|/// Note: Module verification is enabled by default in Debug builds, and
comment|/// disabled by default in Release. Use this method to override the default.
name|void
name|setVerifyModules
parameter_list|(
name|bool
name|Verify
parameter_list|)
block|{
name|VerifyModules
operator|=
name|Verify
expr_stmt|;
block|}
name|bool
name|getVerifyModules
argument_list|()
specifier|const
block|{
return|return
name|VerifyModules
return|;
block|}
comment|/// InstallLazyFunctionCreator - If an unknown function is needed, the
comment|/// specified function pointer is invoked to create it.  If it returns null,
comment|/// the JIT will abort.
name|void
name|InstallLazyFunctionCreator
parameter_list|(
name|FunctionCreator
name|C
parameter_list|)
block|{
name|LazyFunctionCreator
operator|=
name|std
operator|::
name|move
argument_list|(
name|C
argument_list|)
expr_stmt|;
block|}
name|protected
label|:
name|ExecutionEngine
argument_list|(
argument|DataLayout DL
argument_list|)
block|:
name|DL
argument_list|(
argument|std::move(DL)
argument_list|)
block|{}
name|explicit
name|ExecutionEngine
argument_list|(
name|DataLayout
name|DL
argument_list|,
name|std
operator|::
name|unique_ptr
operator|<
name|Module
operator|>
name|M
argument_list|)
decl_stmt|;
name|explicit
name|ExecutionEngine
argument_list|(
name|std
operator|::
name|unique_ptr
operator|<
name|Module
operator|>
name|M
argument_list|)
decl_stmt|;
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
name|private
label|:
name|void
name|Init
argument_list|(
name|std
operator|::
name|unique_ptr
operator|<
name|Module
operator|>
name|M
argument_list|)
decl_stmt|;
block|}
empty_stmt|;
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
comment|// end namespace EngineKind
comment|/// Builder class for ExecutionEngines. Use this by stack-allocating a builder,
comment|/// chaining the various set* methods, and terminating it with a .create()
comment|/// call.
name|class
name|EngineBuilder
block|{
name|private
label|:
name|std
operator|::
name|unique_ptr
operator|<
name|Module
operator|>
name|M
expr_stmt|;
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
name|std
operator|::
name|shared_ptr
operator|<
name|MCJITMemoryManager
operator|>
name|MemMgr
expr_stmt|;
name|std
operator|::
name|shared_ptr
operator|<
name|JITSymbolResolver
operator|>
name|Resolver
expr_stmt|;
name|TargetOptions
name|Options
decl_stmt|;
name|Optional
operator|<
name|Reloc
operator|::
name|Model
operator|>
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
name|VerifyModules
decl_stmt|;
name|bool
name|UseOrcMCJITReplacement
decl_stmt|;
name|public
label|:
comment|/// Default constructor for EngineBuilder.
name|EngineBuilder
argument_list|()
expr_stmt|;
comment|/// Constructor for EngineBuilder.
name|EngineBuilder
argument_list|(
name|std
operator|::
name|unique_ptr
operator|<
name|Module
operator|>
name|M
argument_list|)
expr_stmt|;
comment|// Out-of-line since we don't have the def'n of RTDyldMemoryManager here.
operator|~
name|EngineBuilder
argument_list|()
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
comment|/// setMCJITMemoryManager - Sets the MCJIT memory manager to use. This allows
comment|/// clients to customize their memory allocation policies for the MCJIT. This
comment|/// is only appropriate for the MCJIT; setting this and configuring the builder
comment|/// to create anything other than MCJIT will cause a runtime error. If create()
comment|/// is called and is successful, the created engine takes ownership of the
comment|/// memory manager. This option defaults to NULL.
name|EngineBuilder
modifier|&
name|setMCJITMemoryManager
argument_list|(
name|std
operator|::
name|unique_ptr
operator|<
name|RTDyldMemoryManager
operator|>
name|mcjmm
argument_list|)
decl_stmt|;
name|EngineBuilder
modifier|&
name|setMemoryManager
argument_list|(
name|std
operator|::
name|unique_ptr
operator|<
name|MCJITMemoryManager
operator|>
name|MM
argument_list|)
decl_stmt|;
name|EngineBuilder
modifier|&
name|setSymbolResolver
argument_list|(
name|std
operator|::
name|unique_ptr
operator|<
name|JITSymbolResolver
operator|>
name|SR
argument_list|)
decl_stmt|;
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
comment|/// setVerifyModules - Set whether the JIT implementation should verify
comment|/// IR modules during compilation.
name|EngineBuilder
modifier|&
name|setVerifyModules
parameter_list|(
name|bool
name|Verify
parameter_list|)
block|{
name|VerifyModules
operator|=
name|Verify
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
comment|// \brief Use OrcMCJITReplacement instead of MCJIT. Off by default.
name|void
name|setUseOrcMCJITReplacement
parameter_list|(
name|bool
name|UseOrcMCJITReplacement
parameter_list|)
block|{
name|this
operator|->
name|UseOrcMCJITReplacement
operator|=
name|UseOrcMCJITReplacement
expr_stmt|;
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
empty_stmt|;
comment|// Create wrappers for C Binding types (see CBindingWrapping.h).
name|DEFINE_SIMPLE_CONVERSION_FUNCTIONS
argument_list|(
argument|ExecutionEngine
argument_list|,
argument|LLVMExecutionEngineRef
argument_list|)
block|}
end_decl_stmt

begin_comment
comment|// end namespace llvm
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// LLVM_EXECUTIONENGINE_EXECUTIONENGINE_H
end_comment

end_unit

