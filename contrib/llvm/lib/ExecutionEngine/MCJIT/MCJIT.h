begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- MCJIT.h - Class definition for the MCJIT ----------------*- C++ -*-===//
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

begin_ifndef
ifndef|#
directive|ifndef
name|LLVM_LIB_EXECUTIONENGINE_MCJIT_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_LIB_EXECUTIONENGINE_MCJIT_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/DenseMap.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/SmallPtrSet.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/SmallVector.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ExecutionEngine/ExecutionEngine.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ExecutionEngine/ObjectCache.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ExecutionEngine/ObjectImage.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ExecutionEngine/RuntimeDyld.h"
end_include

begin_include
include|#
directive|include
file|"llvm/IR/Module.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|MCJIT
decl_stmt|;
comment|// This is a helper class that the MCJIT execution engine uses for linking
comment|// functions across modules that it owns.  It aggregates the memory manager
comment|// that is passed in to the MCJIT constructor and defers most functionality
comment|// to that object.
name|class
name|LinkingMemoryManager
range|:
name|public
name|RTDyldMemoryManager
block|{
name|public
operator|:
name|LinkingMemoryManager
argument_list|(
name|MCJIT
operator|*
name|Parent
argument_list|,
name|RTDyldMemoryManager
operator|*
name|MM
argument_list|)
operator|:
name|ParentEngine
argument_list|(
name|Parent
argument_list|)
block|,
name|ClientMM
argument_list|(
argument|MM
argument_list|)
block|{}
name|virtual
name|uint64_t
name|getSymbolAddress
argument_list|(
specifier|const
name|std
operator|::
name|string
operator|&
name|Name
argument_list|)
block|;
comment|// Functions deferred to client memory manager
name|virtual
name|uint8_t
operator|*
name|allocateCodeSection
argument_list|(
argument|uintptr_t Size
argument_list|,
argument|unsigned Alignment
argument_list|,
argument|unsigned SectionID
argument_list|,
argument|StringRef SectionName
argument_list|)
block|{
return|return
name|ClientMM
operator|->
name|allocateCodeSection
argument_list|(
name|Size
argument_list|,
name|Alignment
argument_list|,
name|SectionID
argument_list|,
name|SectionName
argument_list|)
return|;
block|}
name|virtual
name|uint8_t
operator|*
name|allocateDataSection
argument_list|(
argument|uintptr_t Size
argument_list|,
argument|unsigned Alignment
argument_list|,
argument|unsigned SectionID
argument_list|,
argument|StringRef SectionName
argument_list|,
argument|bool IsReadOnly
argument_list|)
block|{
return|return
name|ClientMM
operator|->
name|allocateDataSection
argument_list|(
name|Size
argument_list|,
name|Alignment
argument_list|,
name|SectionID
argument_list|,
name|SectionName
argument_list|,
name|IsReadOnly
argument_list|)
return|;
block|}
name|virtual
name|void
name|notifyObjectLoaded
argument_list|(
argument|ExecutionEngine *EE
argument_list|,
argument|const ObjectImage *Obj
argument_list|)
block|{
name|ClientMM
operator|->
name|notifyObjectLoaded
argument_list|(
name|EE
argument_list|,
name|Obj
argument_list|)
block|;   }
name|virtual
name|void
name|registerEHFrames
argument_list|(
argument|uint8_t *Addr
argument_list|,
argument|uint64_t LoadAddr
argument_list|,
argument|size_t Size
argument_list|)
block|{
name|ClientMM
operator|->
name|registerEHFrames
argument_list|(
name|Addr
argument_list|,
name|LoadAddr
argument_list|,
name|Size
argument_list|)
block|;   }
name|virtual
name|void
name|deregisterEHFrames
argument_list|(
argument|uint8_t *Addr
argument_list|,
argument|uint64_t LoadAddr
argument_list|,
argument|size_t Size
argument_list|)
block|{
name|ClientMM
operator|->
name|deregisterEHFrames
argument_list|(
name|Addr
argument_list|,
name|LoadAddr
argument_list|,
name|Size
argument_list|)
block|;   }
name|virtual
name|bool
name|finalizeMemory
argument_list|(
argument|std::string *ErrMsg =
literal|0
argument_list|)
block|{
return|return
name|ClientMM
operator|->
name|finalizeMemory
argument_list|(
name|ErrMsg
argument_list|)
return|;
block|}
name|private
operator|:
name|MCJIT
operator|*
name|ParentEngine
block|;
name|OwningPtr
operator|<
name|RTDyldMemoryManager
operator|>
name|ClientMM
block|; }
decl_stmt|;
comment|// About Module states: added->loaded->finalized.
comment|//
comment|// The purpose of the "added" state is having modules in standby. (added=known
comment|// but not compiled). The idea is that you can add a module to provide function
comment|// definitions but if nothing in that module is referenced by a module in which
comment|// a function is executed (note the wording here because it's not exactly the
comment|// ideal case) then the module never gets compiled. This is sort of lazy
comment|// compilation.
comment|//
comment|// The purpose of the "loaded" state (loaded=compiled and required sections
comment|// copied into local memory but not yet ready for execution) is to have an
comment|// intermediate state wherein clients can remap the addresses of sections, using
comment|// MCJIT::mapSectionAddress, (in preparation for later copying to a new location
comment|// or an external process) before relocations and page permissions are applied.
comment|//
comment|// It might not be obvious at first glance, but the "remote-mcjit" case in the
comment|// lli tool does this.  In that case, the intermediate action is taken by the
comment|// RemoteMemoryManager in response to the notifyObjectLoaded function being
comment|// called.
name|class
name|MCJIT
range|:
name|public
name|ExecutionEngine
block|{
name|MCJIT
argument_list|(
argument|Module *M
argument_list|,
argument|TargetMachine *tm
argument_list|,
argument|RTDyldMemoryManager *MemMgr
argument_list|,
argument|bool AllocateGVsWithCode
argument_list|)
block|;
typedef|typedef
name|llvm
operator|::
name|SmallPtrSet
operator|<
name|Module
operator|*
operator|,
literal|4
operator|>
name|ModulePtrSet
expr_stmt|;
name|class
name|OwningModuleContainer
block|{
name|public
operator|:
name|OwningModuleContainer
argument_list|()
block|{     }
operator|~
name|OwningModuleContainer
argument_list|()
block|{
name|freeModulePtrSet
argument_list|(
name|AddedModules
argument_list|)
block|;
name|freeModulePtrSet
argument_list|(
name|LoadedModules
argument_list|)
block|;
name|freeModulePtrSet
argument_list|(
name|FinalizedModules
argument_list|)
block|;     }
name|ModulePtrSet
operator|::
name|iterator
name|begin_added
argument_list|()
block|{
return|return
name|AddedModules
operator|.
name|begin
argument_list|()
return|;
block|}
name|ModulePtrSet
operator|::
name|iterator
name|end_added
argument_list|()
block|{
return|return
name|AddedModules
operator|.
name|end
argument_list|()
return|;
block|}
name|ModulePtrSet
operator|::
name|iterator
name|begin_loaded
argument_list|()
block|{
return|return
name|LoadedModules
operator|.
name|begin
argument_list|()
return|;
block|}
name|ModulePtrSet
operator|::
name|iterator
name|end_loaded
argument_list|()
block|{
return|return
name|LoadedModules
operator|.
name|end
argument_list|()
return|;
block|}
name|ModulePtrSet
operator|::
name|iterator
name|begin_finalized
argument_list|()
block|{
return|return
name|FinalizedModules
operator|.
name|begin
argument_list|()
return|;
block|}
name|ModulePtrSet
operator|::
name|iterator
name|end_finalized
argument_list|()
block|{
return|return
name|FinalizedModules
operator|.
name|end
argument_list|()
return|;
block|}
name|void
name|addModule
argument_list|(
argument|Module *M
argument_list|)
block|{
name|AddedModules
operator|.
name|insert
argument_list|(
name|M
argument_list|)
block|;     }
name|bool
name|removeModule
argument_list|(
argument|Module *M
argument_list|)
block|{
return|return
name|AddedModules
operator|.
name|erase
argument_list|(
name|M
argument_list|)
operator|||
name|LoadedModules
operator|.
name|erase
argument_list|(
name|M
argument_list|)
operator|||
name|FinalizedModules
operator|.
name|erase
argument_list|(
name|M
argument_list|)
return|;
block|}
name|bool
name|hasModuleBeenAddedButNotLoaded
argument_list|(
argument|Module *M
argument_list|)
block|{
return|return
name|AddedModules
operator|.
name|count
argument_list|(
name|M
argument_list|)
operator|!=
literal|0
return|;
block|}
name|bool
name|hasModuleBeenLoaded
argument_list|(
argument|Module *M
argument_list|)
block|{
comment|// If the module is in either the "loaded" or "finalized" sections it
comment|// has been loaded.
return|return
operator|(
name|LoadedModules
operator|.
name|count
argument_list|(
name|M
argument_list|)
operator|!=
literal|0
operator|)
operator|||
operator|(
name|FinalizedModules
operator|.
name|count
argument_list|(
name|M
argument_list|)
operator|!=
literal|0
operator|)
return|;
block|}
name|bool
name|hasModuleBeenFinalized
argument_list|(
argument|Module *M
argument_list|)
block|{
return|return
name|FinalizedModules
operator|.
name|count
argument_list|(
name|M
argument_list|)
operator|!=
literal|0
return|;
block|}
name|bool
name|ownsModule
argument_list|(
argument|Module* M
argument_list|)
block|{
return|return
operator|(
name|AddedModules
operator|.
name|count
argument_list|(
name|M
argument_list|)
operator|!=
literal|0
operator|)
operator|||
operator|(
name|LoadedModules
operator|.
name|count
argument_list|(
name|M
argument_list|)
operator|!=
literal|0
operator|)
operator|||
operator|(
name|FinalizedModules
operator|.
name|count
argument_list|(
name|M
argument_list|)
operator|!=
literal|0
operator|)
return|;
block|}
name|void
name|markModuleAsLoaded
argument_list|(
argument|Module *M
argument_list|)
block|{
comment|// This checks against logic errors in the MCJIT implementation.
comment|// This function should never be called with either a Module that MCJIT
comment|// does not own or a Module that has already been loaded and/or finalized.
name|assert
argument_list|(
name|AddedModules
operator|.
name|count
argument_list|(
name|M
argument_list|)
operator|&&
literal|"markModuleAsLoaded: Module not found in AddedModules"
argument_list|)
block|;
comment|// Remove the module from the "Added" set.
name|AddedModules
operator|.
name|erase
argument_list|(
name|M
argument_list|)
block|;
comment|// Add the Module to the "Loaded" set.
name|LoadedModules
operator|.
name|insert
argument_list|(
name|M
argument_list|)
block|;     }
name|void
name|markModuleAsFinalized
argument_list|(
argument|Module *M
argument_list|)
block|{
comment|// This checks against logic errors in the MCJIT implementation.
comment|// This function should never be called with either a Module that MCJIT
comment|// does not own, a Module that has not been loaded or a Module that has
comment|// already been finalized.
name|assert
argument_list|(
name|LoadedModules
operator|.
name|count
argument_list|(
name|M
argument_list|)
operator|&&
literal|"markModuleAsFinalized: Module not found in LoadedModules"
argument_list|)
block|;
comment|// Remove the module from the "Loaded" section of the list.
name|LoadedModules
operator|.
name|erase
argument_list|(
name|M
argument_list|)
block|;
comment|// Add the Module to the "Finalized" section of the list by inserting it
comment|// before the 'end' iterator.
name|FinalizedModules
operator|.
name|insert
argument_list|(
name|M
argument_list|)
block|;     }
name|void
name|markAllLoadedModulesAsFinalized
argument_list|()
block|{
for|for
control|(
name|ModulePtrSet
operator|::
name|iterator
name|I
operator|=
name|LoadedModules
operator|.
name|begin
argument_list|()
init|,
name|E
operator|=
name|LoadedModules
operator|.
name|end
argument_list|()
init|;
name|I
operator|!=
name|E
condition|;
operator|++
name|I
control|)
block|{
name|Module
modifier|*
name|M
init|=
operator|*
name|I
decl_stmt|;
name|FinalizedModules
operator|.
name|insert
argument_list|(
name|M
argument_list|)
expr_stmt|;
block|}
name|LoadedModules
operator|.
name|clear
argument_list|()
expr_stmt|;
block|}
name|private
operator|:
name|ModulePtrSet
name|AddedModules
block|;
name|ModulePtrSet
name|LoadedModules
block|;
name|ModulePtrSet
name|FinalizedModules
block|;
name|void
name|freeModulePtrSet
argument_list|(
argument|ModulePtrSet& MPS
argument_list|)
block|{
comment|// Go through the module set and delete everything.
for|for
control|(
name|ModulePtrSet
operator|::
name|iterator
name|I
operator|=
name|MPS
operator|.
name|begin
argument_list|()
init|,
name|E
operator|=
name|MPS
operator|.
name|end
argument_list|()
init|;
name|I
operator|!=
name|E
condition|;
operator|++
name|I
control|)
block|{
name|Module
modifier|*
name|M
init|=
operator|*
name|I
decl_stmt|;
name|delete
name|M
decl_stmt|;
block|}
name|MPS
operator|.
name|clear
argument_list|()
expr_stmt|;
block|}
expr|}
block|;
name|TargetMachine
operator|*
name|TM
block|;
name|MCContext
operator|*
name|Ctx
block|;
name|LinkingMemoryManager
name|MemMgr
block|;
name|RuntimeDyld
name|Dyld
block|;
name|SmallVector
operator|<
name|JITEventListener
operator|*
block|,
literal|2
operator|>
name|EventListeners
block|;
name|OwningModuleContainer
name|OwnedModules
block|;
typedef|typedef
name|DenseMap
operator|<
name|Module
operator|*
operator|,
name|ObjectImage
operator|*
operator|>
name|LoadedObjectMap
expr_stmt|;
name|LoadedObjectMap
name|LoadedObjects
decl_stmt|;
comment|// An optional ObjectCache to be notified of compiled objects and used to
comment|// perform lookup of pre-compiled code to avoid re-compilation.
name|ObjectCache
modifier|*
name|ObjCache
decl_stmt|;
name|Function
modifier|*
name|FindFunctionNamedInModulePtrSet
argument_list|(
specifier|const
name|char
operator|*
name|FnName
argument_list|,
name|ModulePtrSet
operator|::
name|iterator
name|I
argument_list|,
name|ModulePtrSet
operator|::
name|iterator
name|E
argument_list|)
decl_stmt|;
name|void
name|runStaticConstructorsDestructorsInModulePtrSet
argument_list|(
name|bool
name|isDtors
argument_list|,
name|ModulePtrSet
operator|::
name|iterator
name|I
argument_list|,
name|ModulePtrSet
operator|::
name|iterator
name|E
argument_list|)
decl_stmt|;
name|public
label|:
operator|~
name|MCJIT
argument_list|()
expr_stmt|;
comment|/// @name ExecutionEngine interface implementation
comment|/// @{
name|virtual
name|void
name|addModule
parameter_list|(
name|Module
modifier|*
name|M
parameter_list|)
function_decl|;
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
comment|/// Sets the object manager that MCJIT should use to avoid compilation.
name|virtual
name|void
name|setObjectCache
parameter_list|(
name|ObjectCache
modifier|*
name|manager
parameter_list|)
function_decl|;
name|virtual
name|void
name|generateCodeForModule
parameter_list|(
name|Module
modifier|*
name|M
parameter_list|)
function_decl|;
comment|/// finalizeObject - ensure the module is fully processed and is usable.
comment|///
comment|/// It is the user-level function for completing the process of making the
comment|/// object usable for execution. It should be called after sections within an
comment|/// object have been relocated using mapSectionAddress.  When this method is
comment|/// called the MCJIT execution engine will reapply relocations for a loaded
comment|/// object.
comment|/// Is it OK to finalize a set of modules, add modules and finalize again.
comment|// FIXME: Do we really need both of these?
name|virtual
name|void
name|finalizeObject
parameter_list|()
function_decl|;
name|virtual
name|void
name|finalizeModule
parameter_list|(
name|Module
modifier|*
parameter_list|)
function_decl|;
name|void
name|finalizeLoadedModules
parameter_list|()
function_decl|;
comment|/// runStaticConstructorsDestructors - This method is used to execute all of
comment|/// the static constructors or destructors for a program.
comment|///
comment|/// \param isDtors - Run the destructors instead of constructors.
name|void
name|runStaticConstructorsDestructors
parameter_list|(
name|bool
name|isDtors
parameter_list|)
function_decl|;
name|virtual
name|void
modifier|*
name|getPointerToBasicBlock
parameter_list|(
name|BasicBlock
modifier|*
name|BB
parameter_list|)
function_decl|;
name|virtual
name|void
modifier|*
name|getPointerToFunction
parameter_list|(
name|Function
modifier|*
name|F
parameter_list|)
function_decl|;
name|virtual
name|void
modifier|*
name|recompileAndRelinkFunction
parameter_list|(
name|Function
modifier|*
name|F
parameter_list|)
function_decl|;
name|virtual
name|void
name|freeMachineCodeForFunction
parameter_list|(
name|Function
modifier|*
name|F
parameter_list|)
function_decl|;
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
decl_stmt|;
comment|/// getPointerToNamedFunction - This method returns the address of the
comment|/// specified function by using the dlsym function call.  As such it is only
comment|/// useful for resolving library symbols, not code generated symbols.
comment|///
comment|/// If AbortOnFailure is false and no function with the given name is
comment|/// found, this function silently returns a null pointer. Otherwise,
comment|/// it prints a message to stderr and aborts.
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
name|Dyld
operator|.
name|mapSectionAddress
argument_list|(
name|LocalAddress
argument_list|,
name|TargetAddress
argument_list|)
expr_stmt|;
block|}
name|virtual
name|void
name|RegisterJITEventListener
parameter_list|(
name|JITEventListener
modifier|*
name|L
parameter_list|)
function_decl|;
name|virtual
name|void
name|UnregisterJITEventListener
parameter_list|(
name|JITEventListener
modifier|*
name|L
parameter_list|)
function_decl|;
comment|// If successful, these function will implicitly finalize all loaded objects.
comment|// To get a function address within MCJIT without causing a finalize, use
comment|// getSymbolAddress.
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
decl_stmt|;
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
decl_stmt|;
comment|/// @}
comment|/// @name (Private) Registration Interfaces
comment|/// @{
specifier|static
name|void
name|Register
parameter_list|()
block|{
name|MCJITCtor
operator|=
name|createJIT
expr_stmt|;
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
name|RTDyldMemoryManager
operator|*
name|MemMgr
argument_list|,
name|bool
name|GVsWithCode
argument_list|,
name|TargetMachine
operator|*
name|TM
argument_list|)
decl_stmt|;
comment|// @}
comment|// This is not directly exposed via the ExecutionEngine API, but it is
comment|// used by the LinkingMemoryManager.
name|uint64_t
name|getSymbolAddress
argument_list|(
specifier|const
name|std
operator|::
name|string
operator|&
name|Name
argument_list|,
name|bool
name|CheckFunctionsOnly
argument_list|)
decl_stmt|;
name|protected
label|:
comment|/// emitObject -- Generate a JITed object in memory from the specified module
comment|/// Currently, MCJIT only supports a single module and the module passed to
comment|/// this function call is expected to be the contained module.  The module
comment|/// is passed as a parameter here to prepare for multiple module support in
comment|/// the future.
name|ObjectBufferStream
modifier|*
name|emitObject
parameter_list|(
name|Module
modifier|*
name|M
parameter_list|)
function_decl|;
name|void
name|NotifyObjectEmitted
parameter_list|(
specifier|const
name|ObjectImage
modifier|&
name|Obj
parameter_list|)
function_decl|;
name|void
name|NotifyFreeingObject
parameter_list|(
specifier|const
name|ObjectImage
modifier|&
name|Obj
parameter_list|)
function_decl|;
name|uint64_t
name|getExistingSymbolAddress
argument_list|(
specifier|const
name|std
operator|::
name|string
operator|&
name|Name
argument_list|)
decl_stmt|;
name|Module
modifier|*
name|findModuleForSymbol
argument_list|(
specifier|const
name|std
operator|::
name|string
operator|&
name|Name
argument_list|,
name|bool
name|CheckFunctionsOnly
argument_list|)
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

