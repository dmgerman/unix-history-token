begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- RTDyldMemoryManager.cpp - Memory manager for MC-JIT -----*- C++ -*-===//
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
comment|// Interface of the runtime dynamic memory manager base class.
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
name|LLVM_EXECUTIONENGINE_RTDYLDMEMORYMANAGER_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_EXECUTIONENGINE_RTDYLDMEMORYMANAGER_H
end_define

begin_include
include|#
directive|include
file|"llvm/ExecutionEngine/JITSymbol.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ExecutionEngine/RuntimeDyld.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/CBindingWrapping.h"
end_include

begin_include
include|#
directive|include
file|"llvm-c/ExecutionEngine.h"
end_include

begin_include
include|#
directive|include
file|<cstddef>
end_include

begin_include
include|#
directive|include
file|<cstdint>
end_include

begin_include
include|#
directive|include
file|<string>
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|ExecutionEngine
decl_stmt|;
name|namespace
name|object
block|{
name|class
name|ObjectFile
decl_stmt|;
block|}
comment|// end namespace object
name|class
name|MCJITMemoryManager
range|:
name|public
name|RuntimeDyld
operator|::
name|MemoryManager
block|{
name|public
operator|:
comment|// Don't hide the notifyObjectLoaded method from RuntimeDyld::MemoryManager.
name|using
name|RuntimeDyld
operator|::
name|MemoryManager
operator|::
name|notifyObjectLoaded
block|;
comment|/// This method is called after an object has been loaded into memory but
comment|/// before relocations are applied to the loaded sections.  The object load
comment|/// may have been initiated by MCJIT to resolve an external symbol for another
comment|/// object that is being finalized.  In that case, the object about which
comment|/// the memory manager is being notified will be finalized immediately after
comment|/// the memory manager returns from this call.
comment|///
comment|/// Memory managers which are preparing code for execution in an external
comment|/// address space can use this call to remap the section addresses for the
comment|/// newly loaded object.
name|virtual
name|void
name|notifyObjectLoaded
argument_list|(
argument|ExecutionEngine *EE
argument_list|,
argument|const object::ObjectFile&
argument_list|)
block|{}
block|}
decl_stmt|;
comment|// RuntimeDyld clients often want to handle the memory management of
comment|// what gets placed where. For JIT clients, this is the subset of
comment|// JITMemoryManager required for dynamic loading of binaries.
comment|//
comment|// FIXME: As the RuntimeDyld fills out, additional routines will be needed
comment|//        for the varying types of objects to be allocated.
name|class
name|RTDyldMemoryManager
range|:
name|public
name|MCJITMemoryManager
decl_stmt|,
name|public
name|JITSymbolResolver
block|{
name|public
label|:
name|RTDyldMemoryManager
argument_list|()
operator|=
expr|default
expr_stmt|;
name|RTDyldMemoryManager
argument_list|(
specifier|const
name|RTDyldMemoryManager
operator|&
argument_list|)
operator|=
name|delete
expr_stmt|;
name|void
name|operator
init|=
operator|(
specifier|const
name|RTDyldMemoryManager
operator|&
operator|)
operator|=
name|delete
decl_stmt|;
operator|~
name|RTDyldMemoryManager
argument_list|()
name|override
expr_stmt|;
comment|/// Register EH frames in the current process.
specifier|static
name|void
name|registerEHFramesInProcess
parameter_list|(
name|uint8_t
modifier|*
name|Addr
parameter_list|,
name|size_t
name|Size
parameter_list|)
function_decl|;
comment|/// Deregister EH frames in the current proces.
specifier|static
name|void
name|deregisterEHFramesInProcess
parameter_list|(
name|uint8_t
modifier|*
name|Addr
parameter_list|,
name|size_t
name|Size
parameter_list|)
function_decl|;
name|void
name|registerEHFrames
argument_list|(
name|uint8_t
operator|*
name|Addr
argument_list|,
name|uint64_t
name|LoadAddr
argument_list|,
name|size_t
name|Size
argument_list|)
name|override
decl_stmt|;
name|void
name|deregisterEHFrames
argument_list|()
name|override
expr_stmt|;
comment|/// This method returns the address of the specified function or variable in
comment|/// the current process.
specifier|static
name|uint64_t
name|getSymbolAddressInProcess
argument_list|(
specifier|const
name|std
operator|::
name|string
operator|&
name|Name
argument_list|)
decl_stmt|;
comment|/// Legacy symbol lookup - DEPRECATED! Please override findSymbol instead.
comment|///
comment|/// This method returns the address of the specified function or variable.
comment|/// It is used to resolve symbols during module linking.
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
block|{
return|return
name|getSymbolAddressInProcess
argument_list|(
name|Name
argument_list|)
return|;
block|}
comment|/// This method returns a RuntimeDyld::SymbolInfo for the specified function
comment|/// or variable. It is used to resolve symbols during module linking.
comment|///
comment|/// By default this falls back on the legacy lookup method:
comment|/// 'getSymbolAddress'. The address returned by getSymbolAddress is treated as
comment|/// a strong, exported symbol, consistent with historical treatment by
comment|/// RuntimeDyld.
comment|///
comment|/// Clients writing custom RTDyldMemoryManagers are encouraged to override
comment|/// this method and return a SymbolInfo with the flags set correctly. This is
comment|/// necessary for RuntimeDyld to correctly handle weak and non-exported symbols.
name|JITSymbol
name|findSymbol
argument_list|(
specifier|const
name|std
operator|::
name|string
operator|&
name|Name
argument_list|)
name|override
block|{
return|return
name|JITSymbol
argument_list|(
name|getSymbolAddress
argument_list|(
name|Name
argument_list|)
argument_list|,
name|JITSymbolFlags
operator|::
name|Exported
argument_list|)
return|;
block|}
comment|/// Legacy symbol lookup -- DEPRECATED! Please override
comment|/// findSymbolInLogicalDylib instead.
comment|///
comment|/// Default to treating all modules as separate.
name|virtual
name|uint64_t
name|getSymbolAddressInLogicalDylib
argument_list|(
specifier|const
name|std
operator|::
name|string
operator|&
name|Name
argument_list|)
block|{
return|return
literal|0
return|;
block|}
comment|/// Default to treating all modules as separate.
comment|///
comment|/// By default this falls back on the legacy lookup method:
comment|/// 'getSymbolAddressInLogicalDylib'. The address returned by
comment|/// getSymbolAddressInLogicalDylib is treated as a strong, exported symbol,
comment|/// consistent with historical treatment by RuntimeDyld.
comment|///
comment|/// Clients writing custom RTDyldMemoryManagers are encouraged to override
comment|/// this method and return a SymbolInfo with the flags set correctly. This is
comment|/// necessary for RuntimeDyld to correctly handle weak and non-exported symbols.
name|JITSymbol
name|findSymbolInLogicalDylib
argument_list|(
specifier|const
name|std
operator|::
name|string
operator|&
name|Name
argument_list|)
name|override
block|{
return|return
name|JITSymbol
argument_list|(
name|getSymbolAddressInLogicalDylib
argument_list|(
name|Name
argument_list|)
argument_list|,
name|JITSymbolFlags
operator|::
name|Exported
argument_list|)
return|;
block|}
comment|/// This method returns the address of the specified function. As such it is
comment|/// only useful for resolving library symbols, not code generated symbols.
comment|///
comment|/// If \p AbortOnFailure is false and no function with the given name is
comment|/// found, this function returns a null pointer. Otherwise, it prints a
comment|/// message to stderr and aborts.
comment|///
comment|/// This function is deprecated for memory managers to be used with
comment|/// MCJIT or RuntimeDyld.  Use getSymbolAddress instead.
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
name|private
label|:
struct|struct
name|EHFrame
block|{
name|uint8_t
modifier|*
name|Addr
decl_stmt|;
name|size_t
name|Size
decl_stmt|;
block|}
struct|;
name|std
operator|::
name|vector
operator|<
name|EHFrame
operator|>
name|EHFrames
expr_stmt|;
block|}
empty_stmt|;
comment|// Create wrappers for C Binding types (see CBindingWrapping.h).
name|DEFINE_SIMPLE_CONVERSION_FUNCTIONS
argument_list|(
argument|RTDyldMemoryManager
argument_list|,
argument|LLVMMCJITMemoryManagerRef
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
comment|// LLVM_EXECUTIONENGINE_RTDYLDMEMORYMANAGER_H
end_comment

end_unit

