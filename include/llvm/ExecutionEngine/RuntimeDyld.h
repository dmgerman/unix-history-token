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
name|LLVM_RUNTIME_DYLD_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_RUNTIME_DYLD_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/StringRef.h"
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
name|MemoryBuffer
decl_stmt|;
comment|// RuntimeDyld clients often want to handle the memory management of
comment|// what gets placed where. For JIT clients, this is an abstraction layer
comment|// over the JITMemoryManager, which references objects by their source
comment|// representations in LLVM IR.
comment|// FIXME: As the RuntimeDyld fills out, additional routines will be needed
comment|//        for the varying types of objects to be allocated.
name|class
name|RTDyldMemoryManager
block|{
name|RTDyldMemoryManager
argument_list|(
specifier|const
name|RTDyldMemoryManager
operator|&
argument_list|)
expr_stmt|;
comment|// DO NOT IMPLEMENT
name|void
name|operator
init|=
operator|(
specifier|const
name|RTDyldMemoryManager
operator|&
operator|)
decl_stmt|;
comment|// DO NOT IMPLEMENT
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
comment|/// allocateCodeSection - Allocate a memory block of (at least) the given
comment|/// size suitable for executable code.
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
comment|/// allocateDataSection - Allocate a memory block of (at least) the given
comment|/// size suitable for data.
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
parameter_list|)
init|=
literal|0
function_decl|;
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
block|}
empty_stmt|;
name|class
name|RuntimeDyld
block|{
name|RuntimeDyld
argument_list|(
specifier|const
name|RuntimeDyld
operator|&
argument_list|)
expr_stmt|;
comment|// DO NOT IMPLEMENT
name|void
name|operator
init|=
operator|(
specifier|const
name|RuntimeDyld
operator|&
operator|)
decl_stmt|;
comment|// DO NOT IMPLEMENT
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
name|bool
name|loadObject
parameter_list|(
name|MemoryBuffer
modifier|*
name|InputBuffer
parameter_list|)
function_decl|;
comment|// Get the address of our local copy of the symbol. This may or may not
comment|// be the address used for relocation (clients can copy the data around
comment|// and resolve relocatons based on where they put it).
name|void
modifier|*
name|getSymbolAddress
parameter_list|(
name|StringRef
name|Name
parameter_list|)
function_decl|;
comment|// Resolve the relocations for all symbols we currently know about.
name|void
name|resolveRelocations
parameter_list|()
function_decl|;
comment|/// mapSectionAddress - map a section to its target address space value.
comment|/// Map the address of a JIT section as returned from the memory manager
comment|/// to the address in the target process as the running code will see it.
comment|/// This is the address which will be used for relocation resolution.
name|void
name|mapSectionAddress
parameter_list|(
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

