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
name|LLVM_EXECUTIONENGINE_RT_DYLD_MEMORY_MANAGER_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_EXECUTIONENGINE_RT_DYLD_MEMORY_MANAGER_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/StringRef.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/CBindingWrapping.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/Memory.h"
end_include

begin_include
include|#
directive|include
file|"llvm-c/ExecutionEngine.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|ExecutionEngine
decl_stmt|;
name|class
name|ObjectImage
decl_stmt|;
comment|// RuntimeDyld clients often want to handle the memory management of
comment|// what gets placed where. For JIT clients, this is the subset of
comment|// JITMemoryManager required for dynamic loading of binaries.
comment|//
comment|// FIXME: As the RuntimeDyld fills out, additional routines will be needed
comment|//        for the varying types of objects to be allocated.
name|class
name|RTDyldMemoryManager
block|{
name|RTDyldMemoryManager
argument_list|(
argument|const RTDyldMemoryManager&
argument_list|)
name|LLVM_DELETED_FUNCTION
expr_stmt|;
name|void
name|operator
init|=
operator|(
specifier|const
name|RTDyldMemoryManager
operator|&
operator|)
name|LLVM_DELETED_FUNCTION
decl_stmt|;
name|public
label|:
name|RTDyldMemoryManager
argument_list|()
block|{}
name|virtual
operator|~
name|RTDyldMemoryManager
argument_list|()
expr_stmt|;
comment|/// Allocate a memory block of (at least) the given size suitable for
comment|/// executable code. The SectionID is a unique identifier assigned by the JIT
comment|/// engine, and optionally recorded by the memory manager to access a loaded
comment|/// section.
name|virtual
name|uint8_t
modifier|*
name|allocateCodeSection
parameter_list|(
name|uintptr_t
name|Size
parameter_list|,
name|unsigned
name|Alignment
parameter_list|,
name|unsigned
name|SectionID
parameter_list|,
name|StringRef
name|SectionName
parameter_list|)
init|=
literal|0
function_decl|;
comment|/// Allocate a memory block of (at least) the given size suitable for data.
comment|/// The SectionID is a unique identifier assigned by the JIT engine, and
comment|/// optionally recorded by the memory manager to access a loaded section.
name|virtual
name|uint8_t
modifier|*
name|allocateDataSection
parameter_list|(
name|uintptr_t
name|Size
parameter_list|,
name|unsigned
name|Alignment
parameter_list|,
name|unsigned
name|SectionID
parameter_list|,
name|StringRef
name|SectionName
parameter_list|,
name|bool
name|IsReadOnly
parameter_list|)
init|=
literal|0
function_decl|;
comment|/// Register the EH frames with the runtime so that c++ exceptions work.
comment|///
comment|/// \p Addr parameter provides the local address of the EH frame section
comment|/// data, while \p LoadAddr provides the address of the data in the target
comment|/// address space.  If the section has not been remapped (which will usually
comment|/// be the case for local execution) these two values will be the same.
name|virtual
name|void
name|registerEHFrames
parameter_list|(
name|uint8_t
modifier|*
name|Addr
parameter_list|,
name|uint64_t
name|LoadAddr
parameter_list|,
name|size_t
name|Size
parameter_list|)
function_decl|;
name|virtual
name|void
name|deregisterEHFrames
parameter_list|(
name|uint8_t
modifier|*
name|Addr
parameter_list|,
name|uint64_t
name|LoadAddr
parameter_list|,
name|size_t
name|Size
parameter_list|)
function_decl|;
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
decl_stmt|;
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
parameter_list|(
name|ExecutionEngine
modifier|*
name|EE
parameter_list|,
specifier|const
name|ObjectImage
modifier|*
parameter_list|)
block|{}
comment|/// This method is called when object loading is complete and section page
comment|/// permissions can be applied.  It is up to the memory manager implementation
comment|/// to decide whether or not to act on this method.  The memory manager will
comment|/// typically allocate all sections as read-write and then apply specific
comment|/// permissions when this method is called.  Code sections cannot be executed
comment|/// until this function has been called.  In addition, any cache coherency
comment|/// operations needed to reliably use the memory are also performed.
comment|///
comment|/// Returns true if an error occurred, false otherwise.
name|virtual
name|bool
name|finalizeMemory
argument_list|(
name|std
operator|::
name|string
operator|*
name|ErrMsg
operator|=
literal|0
argument_list|)
init|=
literal|0
decl_stmt|;
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
comment|// namespace llvm
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// LLVM_EXECUTIONENGINE_RT_DYLD_MEMORY_MANAGER_H
end_comment

end_unit

