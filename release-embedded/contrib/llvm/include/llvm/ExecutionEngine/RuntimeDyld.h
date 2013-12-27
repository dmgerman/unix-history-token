begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- RuntimeDyld.h - Run-time dynamic linker for MC-JIT ------*- C++ -*-===//
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
comment|// Interface for the runtime dynamic linker facilities of the MC-JIT.
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
name|LLVM_EXECUTIONENGINE_RUNTIMEDYLD_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_EXECUTIONENGINE_RUNTIMEDYLD_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/StringRef.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ExecutionEngine/ObjectBuffer.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/Memory.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|RuntimeDyldImpl
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
name|bool
name|IsReadOnly
parameter_list|)
init|=
literal|0
function_decl|;
comment|/// This method returns the address of the specified function. As such it is
comment|/// only useful for resolving library symbols, not code generated symbols.
comment|///
comment|/// If AbortOnFailure is false and no function with the given name is
comment|/// found, this function returns a null pointer. Otherwise, it prints a
comment|/// message to stderr and aborts.
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
comment|/// This method is called when object loading is complete and section page
comment|/// permissions can be applied.  It is up to the memory manager implementation
comment|/// to decide whether or not to act on this method.  The memory manager will
comment|/// typically allocate all sections as read-write and then apply specific
comment|/// permissions when this method is called.
comment|///
comment|/// Returns true if an error occurred, false otherwise.
name|virtual
name|bool
name|applyPermissions
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
comment|/// Register the EH frames with the runtime so that c++ exceptions work. The
comment|/// default implementation does nothing. Look at SectionMemoryManager for one
comment|/// that uses __register_frame.
name|virtual
name|void
name|registerEHFrames
parameter_list|(
name|StringRef
name|SectionData
parameter_list|)
function_decl|;
block|}
empty_stmt|;
name|class
name|RuntimeDyld
block|{
name|RuntimeDyld
argument_list|(
argument|const RuntimeDyld&
argument_list|)
name|LLVM_DELETED_FUNCTION
expr_stmt|;
name|void
name|operator
init|=
operator|(
specifier|const
name|RuntimeDyld
operator|&
operator|)
name|LLVM_DELETED_FUNCTION
decl_stmt|;
comment|// RuntimeDyldImpl is the actual class. RuntimeDyld is just the public
comment|// interface.
name|RuntimeDyldImpl
modifier|*
name|Dyld
decl_stmt|;
name|RTDyldMemoryManager
modifier|*
name|MM
decl_stmt|;
name|protected
label|:
comment|// Change the address associated with a section when resolving relocations.
comment|// Any relocations already associated with the symbol will be re-resolved.
name|void
name|reassignSectionAddress
parameter_list|(
name|unsigned
name|SectionID
parameter_list|,
name|uint64_t
name|Addr
parameter_list|)
function_decl|;
name|public
label|:
name|RuntimeDyld
argument_list|(
name|RTDyldMemoryManager
operator|*
argument_list|)
expr_stmt|;
operator|~
name|RuntimeDyld
argument_list|()
expr_stmt|;
comment|/// Prepare the object contained in the input buffer for execution.
comment|/// Ownership of the input buffer is transferred to the ObjectImage
comment|/// instance returned from this function if successful. In the case of load
comment|/// failure, the input buffer will be deleted.
name|ObjectImage
modifier|*
name|loadObject
parameter_list|(
name|ObjectBuffer
modifier|*
name|InputBuffer
parameter_list|)
function_decl|;
comment|/// Get the address of our local copy of the symbol. This may or may not
comment|/// be the address used for relocation (clients can copy the data around
comment|/// and resolve relocatons based on where they put it).
name|void
modifier|*
name|getSymbolAddress
parameter_list|(
name|StringRef
name|Name
parameter_list|)
function_decl|;
comment|/// Get the address of the target copy of the symbol. This is the address
comment|/// used for relocation.
name|uint64_t
name|getSymbolLoadAddress
parameter_list|(
name|StringRef
name|Name
parameter_list|)
function_decl|;
comment|/// Resolve the relocations for all symbols we currently know about.
name|void
name|resolveRelocations
parameter_list|()
function_decl|;
comment|/// Map a section to its target address space value.
comment|/// Map the address of a JIT section as returned from the memory manager
comment|/// to the address in the target process as the running code will see it.
comment|/// This is the address which will be used for relocation resolution.
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
function_decl|;
name|StringRef
name|getErrorString
parameter_list|()
function_decl|;
name|StringRef
name|getEHFrameSection
parameter_list|()
function_decl|;
block|}
empty_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// end namespace llvm
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

