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
file|"llvm/ExecutionEngine/RTDyldMemoryManager.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/Memory.h"
end_include

begin_include
include|#
directive|include
file|<memory>
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|namespace
name|object
block|{
name|class
name|ObjectFile
decl_stmt|;
name|template
operator|<
name|typename
name|T
operator|>
name|class
name|OwningBinary
expr_stmt|;
block|}
name|class
name|RuntimeDyldImpl
decl_stmt|;
name|class
name|RuntimeDyldCheckerImpl
decl_stmt|;
name|class
name|RuntimeDyld
block|{
name|friend
name|class
name|RuntimeDyldCheckerImpl
decl_stmt|;
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
name|std
operator|::
name|unique_ptr
operator|<
name|RuntimeDyldImpl
operator|>
name|Dyld
expr_stmt|;
name|RTDyldMemoryManager
modifier|*
name|MM
decl_stmt|;
name|bool
name|ProcessAllSections
decl_stmt|;
name|RuntimeDyldCheckerImpl
modifier|*
name|Checker
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
comment|/// \brief Information about the loaded object.
name|class
name|LoadedObjectInfo
block|{
name|friend
name|class
name|RuntimeDyldImpl
decl_stmt|;
name|public
label|:
name|LoadedObjectInfo
argument_list|(
argument|RuntimeDyldImpl&RTDyld
argument_list|,
argument|unsigned BeginIdx
argument_list|,
argument|unsigned EndIdx
argument_list|)
block|:
name|RTDyld
argument_list|(
name|RTDyld
argument_list|)
operator|,
name|BeginIdx
argument_list|(
name|BeginIdx
argument_list|)
operator|,
name|EndIdx
argument_list|(
argument|EndIdx
argument_list|)
block|{ }
name|virtual
operator|~
name|LoadedObjectInfo
argument_list|()
block|{}
name|virtual
name|object
operator|::
name|OwningBinary
operator|<
name|object
operator|::
name|ObjectFile
operator|>
name|getObjectForDebug
argument_list|(
argument|const object::ObjectFile&Obj
argument_list|)
specifier|const
operator|=
literal|0
expr_stmt|;
name|uint64_t
name|getSectionLoadAddress
argument_list|(
name|StringRef
name|Name
argument_list|)
decl|const
decl_stmt|;
name|protected
label|:
name|virtual
name|void
name|anchor
parameter_list|()
function_decl|;
name|RuntimeDyldImpl
modifier|&
name|RTDyld
decl_stmt|;
name|unsigned
name|BeginIdx
decl_stmt|,
name|EndIdx
decl_stmt|;
block|}
empty_stmt|;
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
comment|/// Add the referenced object file to the list of objects to be loaded and
comment|/// relocated.
name|std
operator|::
name|unique_ptr
operator|<
name|LoadedObjectInfo
operator|>
name|loadObject
argument_list|(
specifier|const
name|object
operator|::
name|ObjectFile
operator|&
name|O
argument_list|)
expr_stmt|;
comment|/// Get the address of our local copy of the symbol. This may or may not
comment|/// be the address used for relocation (clients can copy the data around
comment|/// and resolve relocatons based on where they put it).
name|void
modifier|*
name|getSymbolAddress
argument_list|(
name|StringRef
name|Name
argument_list|)
decl|const
decl_stmt|;
comment|/// Get the address of the target copy of the symbol. This is the address
comment|/// used for relocation.
name|uint64_t
name|getSymbolLoadAddress
argument_list|(
name|StringRef
name|Name
argument_list|)
decl|const
decl_stmt|;
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
comment|/// Register any EH frame sections that have been loaded but not previously
comment|/// registered with the memory manager.  Note, RuntimeDyld is responsible
comment|/// for identifying the EH frame and calling the memory manager with the
comment|/// EH frame section data.  However, the memory manager itself will handle
comment|/// the actual target-specific EH frame registration.
name|void
name|registerEHFrames
parameter_list|()
function_decl|;
name|void
name|deregisterEHFrames
parameter_list|()
function_decl|;
name|bool
name|hasError
parameter_list|()
function_decl|;
name|StringRef
name|getErrorString
parameter_list|()
function_decl|;
comment|/// By default, only sections that are "required for execution" are passed to
comment|/// the RTDyldMemoryManager, and other sections are discarded. Passing 'true'
comment|/// to this method will cause RuntimeDyld to pass all sections to its
comment|/// memory manager regardless of whether they are "required to execute" in the
comment|/// usual sense. This is useful for inspecting metadata sections that may not
comment|/// contain relocations, E.g. Debug info, stackmaps.
comment|///
comment|/// Must be called before the first object file is loaded.
name|void
name|setProcessAllSections
parameter_list|(
name|bool
name|ProcessAllSections
parameter_list|)
block|{
name|assert
argument_list|(
operator|!
name|Dyld
operator|&&
literal|"setProcessAllSections must be called before loadObject."
argument_list|)
expr_stmt|;
name|this
operator|->
name|ProcessAllSections
operator|=
name|ProcessAllSections
expr_stmt|;
block|}
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

