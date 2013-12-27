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
file|"llvm/ExecutionEngine/RuntimeDyld.h"
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
name|ObjectImage
decl_stmt|;
comment|// FIXME: This makes all kinds of horrible assumptions for the time being,
comment|// like only having one module, not needing to worry about multi-threading,
comment|// blah blah. Purely in get-it-up-and-limping mode for now.
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
name|TargetMachine
operator|*
name|TM
block|;
name|MCContext
operator|*
name|Ctx
block|;
name|RTDyldMemoryManager
operator|*
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
comment|// FIXME: Add support for multiple modules
name|bool
name|IsLoaded
block|;
name|Module
operator|*
name|M
block|;
name|OwningPtr
operator|<
name|ObjectImage
operator|>
name|LoadedObject
block|;
comment|// An optional ObjectCache to be notified of compiled objects and used to
comment|// perform lookup of pre-compiled code to avoid re-compilation.
name|ObjectCache
operator|*
name|ObjCache
block|;
name|public
operator|:
operator|~
name|MCJIT
argument_list|()
block|;
comment|/// @name ExecutionEngine interface implementation
comment|/// @{
comment|/// Sets the object manager that MCJIT should use to avoid compilation.
name|virtual
name|void
name|setObjectCache
argument_list|(
name|ObjectCache
operator|*
name|manager
argument_list|)
block|;
name|virtual
name|void
name|finalizeObject
argument_list|()
block|;
name|virtual
name|void
operator|*
name|getPointerToBasicBlock
argument_list|(
name|BasicBlock
operator|*
name|BB
argument_list|)
block|;
name|virtual
name|void
operator|*
name|getPointerToFunction
argument_list|(
name|Function
operator|*
name|F
argument_list|)
block|;
name|virtual
name|void
operator|*
name|recompileAndRelinkFunction
argument_list|(
name|Function
operator|*
name|F
argument_list|)
block|;
name|virtual
name|void
name|freeMachineCodeForFunction
argument_list|(
name|Function
operator|*
name|F
argument_list|)
block|;
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
name|virtual
name|void
operator|*
name|getPointerToNamedFunction
argument_list|(
argument|const std::string&Name
argument_list|,
argument|bool AbortOnFailure = true
argument_list|)
block|;
comment|/// mapSectionAddress - map a section to its target address space value.
comment|/// Map the address of a JIT section as returned from the memory manager
comment|/// to the address in the target process as the running code will see it.
comment|/// This is the address which will be used for relocation resolution.
name|virtual
name|void
name|mapSectionAddress
argument_list|(
argument|const void *LocalAddress
argument_list|,
argument|uint64_t TargetAddress
argument_list|)
block|{
name|Dyld
operator|.
name|mapSectionAddress
argument_list|(
name|LocalAddress
argument_list|,
name|TargetAddress
argument_list|)
block|;   }
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
comment|/// @}
comment|/// @name (Private) Registration Interfaces
comment|/// @{
specifier|static
name|void
name|Register
argument_list|()
block|{
name|MCJITCtor
operator|=
name|createJIT
block|;   }
specifier|static
name|ExecutionEngine
operator|*
name|createJIT
argument_list|(
argument|Module *M
argument_list|,
argument|std::string *ErrorStr
argument_list|,
argument|JITMemoryManager *JMM
argument_list|,
argument|bool GVsWithCode
argument_list|,
argument|TargetMachine *TM
argument_list|)
block|;
comment|// @}
name|protected
operator|:
comment|/// emitObject -- Generate a JITed object in memory from the specified module
comment|/// Currently, MCJIT only supports a single module and the module passed to
comment|/// this function call is expected to be the contained module.  The module
comment|/// is passed as a parameter here to prepare for multiple module support in
comment|/// the future.
name|ObjectBufferStream
operator|*
name|emitObject
argument_list|(
name|Module
operator|*
name|M
argument_list|)
block|;
name|void
name|loadObject
argument_list|(
name|Module
operator|*
name|M
argument_list|)
block|;
name|void
name|NotifyObjectEmitted
argument_list|(
specifier|const
name|ObjectImage
operator|&
name|Obj
argument_list|)
block|;
name|void
name|NotifyFreeingObject
argument_list|(
specifier|const
name|ObjectImage
operator|&
name|Obj
argument_list|)
block|; }
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

