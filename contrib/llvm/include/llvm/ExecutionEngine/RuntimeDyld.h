begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- RuntimeDyld.h - Run-time dynamic linker for MC-JIT -------*- C++ -*-===//
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
file|"llvm/ADT/STLExtras.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/StringRef.h"
end_include

begin_include
include|#
directive|include
file|"llvm/DebugInfo/DIContext.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ExecutionEngine/JITSymbol.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Object/ObjectFile.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/Error.h"
end_include

begin_include
include|#
directive|include
file|<algorithm>
end_include

begin_include
include|#
directive|include
file|<cassert>
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
file|<system_error>
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|namespace
name|object
block|{
name|template
operator|<
name|typename
name|T
operator|>
name|class
name|OwningBinary
expr_stmt|;
block|}
comment|// end namespace object
comment|/// Base class for errors originating in RuntimeDyld, e.g. missing relocation
comment|/// support.
name|class
name|RuntimeDyldError
range|:
name|public
name|ErrorInfo
operator|<
name|RuntimeDyldError
operator|>
block|{
name|public
operator|:
specifier|static
name|char
name|ID
block|;
name|RuntimeDyldError
argument_list|(
argument|std::string ErrMsg
argument_list|)
operator|:
name|ErrMsg
argument_list|(
argument|std::move(ErrMsg)
argument_list|)
block|{}
name|void
name|log
argument_list|(
argument|raw_ostream&OS
argument_list|)
specifier|const
name|override
block|;
specifier|const
name|std
operator|::
name|string
operator|&
name|getErrorMessage
argument_list|()
specifier|const
block|{
return|return
name|ErrMsg
return|;
block|}
name|std
operator|::
name|error_code
name|convertToErrorCode
argument_list|()
specifier|const
name|override
block|;
name|private
operator|:
name|std
operator|::
name|string
name|ErrMsg
block|; }
decl_stmt|;
name|class
name|RuntimeDyldCheckerImpl
decl_stmt|;
name|class
name|RuntimeDyldImpl
decl_stmt|;
name|class
name|RuntimeDyld
block|{
name|friend
name|class
name|RuntimeDyldCheckerImpl
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
range|:
name|public
name|llvm
operator|::
name|LoadedObjectInfo
block|{
name|friend
name|class
name|RuntimeDyldImpl
block|;
name|public
operator|:
name|using
name|ObjSectionToIDMap
operator|=
name|std
operator|::
name|map
operator|<
name|object
operator|::
name|SectionRef
block|,
name|unsigned
operator|>
block|;
name|LoadedObjectInfo
argument_list|(
argument|RuntimeDyldImpl&RTDyld
argument_list|,
argument|ObjSectionToIDMap ObjSecToIDMap
argument_list|)
operator|:
name|RTDyld
argument_list|(
name|RTDyld
argument_list|)
block|,
name|ObjSecToIDMap
argument_list|(
argument|std::move(ObjSecToIDMap)
argument_list|)
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
block|;
name|uint64_t
name|getSectionLoadAddress
argument_list|(
argument|const object::SectionRef&Sec
argument_list|)
specifier|const
name|override
block|;
name|protected
operator|:
name|virtual
name|void
name|anchor
argument_list|()
block|;
name|RuntimeDyldImpl
operator|&
name|RTDyld
block|;
name|ObjSectionToIDMap
name|ObjSecToIDMap
block|;   }
decl_stmt|;
comment|/// \brief Memory Management.
name|class
name|MemoryManager
block|{
name|friend
name|class
name|RuntimeDyld
decl_stmt|;
name|public
label|:
name|MemoryManager
argument_list|()
operator|=
expr|default
expr_stmt|;
name|virtual
operator|~
name|MemoryManager
argument_list|()
operator|=
expr|default
expr_stmt|;
comment|/// Allocate a memory block of (at least) the given size suitable for
comment|/// executable code. The SectionID is a unique identifier assigned by the
comment|/// RuntimeDyld instance, and optionally recorded by the memory manager to
comment|/// access a loaded section.
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
comment|/// Inform the memory manager about the total amount of memory required to
comment|/// allocate all sections to be loaded:
comment|/// \p CodeSize - the total size of all code sections
comment|/// \p DataSizeRO - the total size of all read-only data sections
comment|/// \p DataSizeRW - the total size of all read-write data sections
comment|///
comment|/// Note that by default the callback is disabled. To enable it
comment|/// redefine the method needsToReserveAllocationSpace to return true.
name|virtual
name|void
name|reserveAllocationSpace
parameter_list|(
name|uintptr_t
name|CodeSize
parameter_list|,
name|uint32_t
name|CodeAlign
parameter_list|,
name|uintptr_t
name|RODataSize
parameter_list|,
name|uint32_t
name|RODataAlign
parameter_list|,
name|uintptr_t
name|RWDataSize
parameter_list|,
name|uint32_t
name|RWDataAlign
parameter_list|)
block|{}
comment|/// Override to return true to enable the reserveAllocationSpace callback.
name|virtual
name|bool
name|needsToReserveAllocationSpace
parameter_list|()
block|{
return|return
name|false
return|;
block|}
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
init|=
literal|0
function_decl|;
name|virtual
name|void
name|deregisterEHFrames
parameter_list|()
init|=
literal|0
function_decl|;
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
name|nullptr
argument_list|)
init|=
literal|0
decl_stmt|;
comment|/// This method is called after an object has been loaded into memory but
comment|/// before relocations are applied to the loaded sections.
comment|///
comment|/// Memory managers which are preparing code for execution in an external
comment|/// address space can use this call to remap the section addresses for the
comment|/// newly loaded object.
comment|///
comment|/// For clients that do not need access to an ExecutionEngine instance this
comment|/// method should be preferred to its cousin
comment|/// MCJITMemoryManager::notifyObjectLoaded as this method is compatible with
comment|/// ORC JIT stacks.
name|virtual
name|void
name|notifyObjectLoaded
argument_list|(
name|RuntimeDyld
operator|&
name|RTDyld
argument_list|,
specifier|const
name|object
operator|::
name|ObjectFile
operator|&
name|Obj
argument_list|)
block|{}
name|private
label|:
name|virtual
name|void
name|anchor
parameter_list|()
function_decl|;
name|bool
name|FinalizationLocked
init|=
name|false
decl_stmt|;
block|}
empty_stmt|;
comment|/// \brief Construct a RuntimeDyld instance.
name|RuntimeDyld
argument_list|(
name|MemoryManager
operator|&
name|MemMgr
argument_list|,
name|JITSymbolResolver
operator|&
name|Resolver
argument_list|)
expr_stmt|;
name|RuntimeDyld
argument_list|(
specifier|const
name|RuntimeDyld
operator|&
argument_list|)
operator|=
name|delete
expr_stmt|;
name|RuntimeDyld
modifier|&
name|operator
init|=
operator|(
specifier|const
name|RuntimeDyld
operator|&
operator|)
operator|=
name|delete
decl_stmt|;
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
name|getSymbolLocalAddress
argument_list|(
name|StringRef
name|Name
argument_list|)
decl|const
decl_stmt|;
comment|/// Get the target address and flags for the named symbol.
comment|/// This address is the one used for relocation.
name|JITEvaluatedSymbol
name|getSymbol
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
comment|/// Perform all actions needed to make the code owned by this RuntimeDyld
comment|/// instance executable:
comment|///
comment|/// 1) Apply relocations.
comment|/// 2) Register EH frames.
comment|/// 3) Update memory permissions*.
comment|///
comment|/// * Finalization is potentially recursive**, and the 3rd step will only be
comment|///   applied by the outermost call to finalize. This allows different
comment|///   RuntimeDyld instances to share a memory manager without the innermost
comment|///   finalization locking the memory and causing relocation fixup errors in
comment|///   outer instances.
comment|///
comment|/// ** Recursive finalization occurs when one RuntimeDyld instances needs the
comment|///   address of a symbol owned by some other instance in order to apply
comment|///   relocations.
comment|///
name|void
name|finalizeWithMemoryManagerLocking
parameter_list|()
function_decl|;
name|private
label|:
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
name|MemoryManager
modifier|&
name|MemMgr
decl_stmt|;
name|JITSymbolResolver
modifier|&
name|Resolver
decl_stmt|;
name|bool
name|ProcessAllSections
decl_stmt|;
name|RuntimeDyldCheckerImpl
modifier|*
name|Checker
decl_stmt|;
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

begin_comment
comment|// LLVM_EXECUTIONENGINE_RUNTIMEDYLD_H
end_comment

end_unit

