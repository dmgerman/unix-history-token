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
file|"JITSymbolFlags.h"
end_include

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
file|"llvm/Object/ObjectFile.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/Memory.h"
end_include

begin_include
include|#
directive|include
file|"llvm/DebugInfo/DIContext.h"
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
specifier|const
name|RuntimeDyld
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
name|RuntimeDyld
operator|&
operator|)
operator|=
name|delete
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
comment|/// \brief Information about a named symbol.
name|class
name|SymbolInfo
range|:
name|public
name|JITSymbolBase
block|{
name|public
operator|:
name|SymbolInfo
argument_list|(
name|std
operator|::
name|nullptr_t
argument_list|)
operator|:
name|JITSymbolBase
argument_list|(
name|JITSymbolFlags
operator|::
name|None
argument_list|)
block|,
name|Address
argument_list|(
literal|0
argument_list|)
block|{}
name|SymbolInfo
argument_list|(
argument|uint64_t Address
argument_list|,
argument|JITSymbolFlags Flags
argument_list|)
operator|:
name|JITSymbolBase
argument_list|(
name|Flags
argument_list|)
block|,
name|Address
argument_list|(
argument|Address
argument_list|)
block|{}
name|explicit
name|operator
name|bool
argument_list|()
specifier|const
block|{
return|return
name|Address
operator|!=
literal|0
return|;
block|}
name|uint64_t
name|getAddress
argument_list|()
specifier|const
block|{
return|return
name|Address
return|;
block|}
name|private
operator|:
name|uint64_t
name|Address
block|;   }
decl_stmt|;
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
typedef|typedef
name|std
operator|::
name|map
operator|<
name|object
operator|::
name|SectionRef
operator|,
name|unsigned
operator|>
name|ObjSectionToIDMap
expr_stmt|;
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
argument|ObjSecToIDMap
argument_list|)
block|{ }
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
decl_stmt|;
name|uint64_t
name|getSectionLoadAddress
argument_list|(
specifier|const
name|object
operator|::
name|SectionRef
operator|&
name|Sec
argument_list|)
decl|const
name|override
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
name|ObjSectionToIDMap
name|ObjSecToIDMap
decl_stmt|;
block|}
empty_stmt|;
name|template
operator|<
name|typename
name|Derived
operator|>
expr|struct
name|LoadedObjectInfoHelper
operator|:
name|LoadedObjectInfo
block|{
name|protected
operator|:
name|LoadedObjectInfoHelper
argument_list|(
specifier|const
name|LoadedObjectInfoHelper
operator|&
argument_list|)
operator|=
expr|default
block|;
name|LoadedObjectInfoHelper
argument_list|()
operator|=
expr|default
block|;
name|public
operator|:
name|LoadedObjectInfoHelper
argument_list|(
argument|RuntimeDyldImpl&RTDyld
argument_list|,
argument|LoadedObjectInfo::ObjSectionToIDMap ObjSecToIDMap
argument_list|)
operator|:
name|LoadedObjectInfo
argument_list|(
argument|RTDyld
argument_list|,
argument|std::move(ObjSecToIDMap)
argument_list|)
block|{}
name|std
operator|::
name|unique_ptr
operator|<
name|llvm
operator|::
name|LoadedObjectInfo
operator|>
name|clone
argument_list|()
specifier|const
name|override
block|{
return|return
name|llvm
operator|::
name|make_unique
operator|<
name|Derived
operator|>
operator|(
name|static_cast
operator|<
specifier|const
name|Derived
operator|&
operator|>
operator|(
operator|*
name|this
operator|)
operator|)
return|;
block|}
expr|}
block|;
comment|/// \brief Memory Management.
name|class
name|MemoryManager
block|{
name|friend
name|class
name|RuntimeDyld
block|;
name|public
operator|:
name|MemoryManager
argument_list|()
operator|:
name|FinalizationLocked
argument_list|(
argument|false
argument_list|)
block|{}
name|virtual
operator|~
name|MemoryManager
argument_list|()
block|{}
comment|/// Allocate a memory block of (at least) the given size suitable for
comment|/// executable code. The SectionID is a unique identifier assigned by the
comment|/// RuntimeDyld instance, and optionally recorded by the memory manager to
comment|/// access a loaded section.
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
operator|=
literal|0
block|;
comment|/// Allocate a memory block of (at least) the given size suitable for data.
comment|/// The SectionID is a unique identifier assigned by the JIT engine, and
comment|/// optionally recorded by the memory manager to access a loaded section.
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
operator|=
literal|0
block|;
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
argument_list|(
argument|uintptr_t CodeSize
argument_list|,
argument|uint32_t CodeAlign
argument_list|,
argument|uintptr_t RODataSize
argument_list|,
argument|uint32_t RODataAlign
argument_list|,
argument|uintptr_t RWDataSize
argument_list|,
argument|uint32_t RWDataAlign
argument_list|)
block|{}
comment|/// Override to return true to enable the reserveAllocationSpace callback.
name|virtual
name|bool
name|needsToReserveAllocationSpace
argument_list|()
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
argument_list|(
argument|uint8_t *Addr
argument_list|,
argument|uint64_t LoadAddr
argument_list|,
argument|size_t Size
argument_list|)
operator|=
literal|0
block|;
name|virtual
name|void
name|deregisterEHFrames
argument_list|(
argument|uint8_t *addr
argument_list|,
argument|uint64_t LoadAddr
argument_list|,
argument|size_t Size
argument_list|)
operator|=
literal|0
block|;
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
operator|=
literal|0
block|;
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
argument|RuntimeDyld&RTDyld
argument_list|,
argument|const object::ObjectFile&Obj
argument_list|)
block|{}
name|private
operator|:
name|virtual
name|void
name|anchor
argument_list|()
block|;
name|bool
name|FinalizationLocked
block|;   }
block|;
comment|/// \brief Symbol resolution.
name|class
name|SymbolResolver
block|{
name|public
operator|:
name|virtual
operator|~
name|SymbolResolver
argument_list|()
block|{}
comment|/// This method returns the address of the specified function or variable.
comment|/// It is used to resolve symbols during module linking.
comment|///
comment|/// If the returned symbol's address is equal to ~0ULL then RuntimeDyld will
comment|/// skip all relocations for that symbol, and the client will be responsible
comment|/// for handling them manually.
name|virtual
name|SymbolInfo
name|findSymbol
argument_list|(
specifier|const
name|std
operator|::
name|string
operator|&
name|Name
argument_list|)
operator|=
literal|0
block|;
comment|/// This method returns the address of the specified symbol if it exists
comment|/// within the logical dynamic library represented by this
comment|/// RTDyldMemoryManager. Unlike getSymbolAddress, queries through this
comment|/// interface should return addresses for hidden symbols.
comment|///
comment|/// This is of particular importance for the Orc JIT APIs, which support lazy
comment|/// compilation by breaking up modules: Each of those broken out modules
comment|/// must be able to resolve hidden symbols provided by the others. Clients
comment|/// writing memory managers for MCJIT can usually ignore this method.
comment|///
comment|/// This method will be queried by RuntimeDyld when checking for previous
comment|/// definitions of common symbols. It will *not* be queried by default when
comment|/// resolving external symbols (this minimises the link-time overhead for
comment|/// MCJIT clients who don't care about Orc features). If you are writing a
comment|/// RTDyldMemoryManager for Orc and want "external" symbol resolution to
comment|/// search the logical dylib, you should override your getSymbolAddress
comment|/// method call this method directly.
name|virtual
name|SymbolInfo
name|findSymbolInLogicalDylib
argument_list|(
specifier|const
name|std
operator|::
name|string
operator|&
name|Name
argument_list|)
operator|=
literal|0
block|;
name|private
operator|:
name|virtual
name|void
name|anchor
argument_list|()
block|;   }
block|;
comment|/// \brief Construct a RuntimeDyld instance.
name|RuntimeDyld
argument_list|(
name|MemoryManager
operator|&
name|MemMgr
argument_list|,
name|SymbolResolver
operator|&
name|Resolver
argument_list|)
block|;
operator|~
name|RuntimeDyld
argument_list|()
block|;
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
block|;
comment|/// Get the address of our local copy of the symbol. This may or may not
comment|/// be the address used for relocation (clients can copy the data around
comment|/// and resolve relocatons based on where they put it).
name|void
operator|*
name|getSymbolLocalAddress
argument_list|(
argument|StringRef Name
argument_list|)
specifier|const
block|;
comment|/// Get the target address and flags for the named symbol.
comment|/// This address is the one used for relocation.
name|SymbolInfo
name|getSymbol
argument_list|(
argument|StringRef Name
argument_list|)
specifier|const
block|;
comment|/// Resolve the relocations for all symbols we currently know about.
name|void
name|resolveRelocations
argument_list|()
block|;
comment|/// Map a section to its target address space value.
comment|/// Map the address of a JIT section as returned from the memory manager
comment|/// to the address in the target process as the running code will see it.
comment|/// This is the address which will be used for relocation resolution.
name|void
name|mapSectionAddress
argument_list|(
argument|const void *LocalAddress
argument_list|,
argument|uint64_t TargetAddress
argument_list|)
block|;
comment|/// Register any EH frame sections that have been loaded but not previously
comment|/// registered with the memory manager.  Note, RuntimeDyld is responsible
comment|/// for identifying the EH frame and calling the memory manager with the
comment|/// EH frame section data.  However, the memory manager itself will handle
comment|/// the actual target-specific EH frame registration.
name|void
name|registerEHFrames
argument_list|()
block|;
name|void
name|deregisterEHFrames
argument_list|()
block|;
name|bool
name|hasError
argument_list|()
block|;
name|StringRef
name|getErrorString
argument_list|()
block|;
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
argument_list|(
argument|bool ProcessAllSections
argument_list|)
block|{
name|assert
argument_list|(
operator|!
name|Dyld
operator|&&
literal|"setProcessAllSections must be called before loadObject."
argument_list|)
block|;
name|this
operator|->
name|ProcessAllSections
operator|=
name|ProcessAllSections
block|;   }
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
argument_list|()
block|;
name|private
operator|:
comment|// RuntimeDyldImpl is the actual class. RuntimeDyld is just the public
comment|// interface.
name|std
operator|::
name|unique_ptr
operator|<
name|RuntimeDyldImpl
operator|>
name|Dyld
block|;
name|MemoryManager
operator|&
name|MemMgr
block|;
name|SymbolResolver
operator|&
name|Resolver
block|;
name|bool
name|ProcessAllSections
block|;
name|RuntimeDyldCheckerImpl
operator|*
name|Checker
block|; }
expr_stmt|;
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

