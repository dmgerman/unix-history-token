begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- ObjectLinkingLayer.h - Add object files to a JIT process -*- C++ -*-===//
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
comment|// Contains the definition for the object layer of the JIT.
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
name|LLVM_EXECUTIONENGINE_ORC_OBJECTLINKINGLAYER_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_EXECUTIONENGINE_ORC_OBJECTLINKINGLAYER_H
end_define

begin_include
include|#
directive|include
file|"JITSymbol.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/STLExtras.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ExecutionEngine/ExecutionEngine.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ExecutionEngine/SectionMemoryManager.h"
end_include

begin_include
include|#
directive|include
file|<list>
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
name|orc
block|{
name|class
name|ObjectLinkingLayerBase
block|{
name|protected
label|:
comment|/// @brief Holds a set of objects to be allocated/linked as a unit in the JIT.
comment|///
comment|/// An instance of this class will be created for each set of objects added
comment|/// via JITObjectLayer::addObjectSet. Deleting the instance (via
comment|/// removeObjectSet) frees its memory, removing all symbol definitions that
comment|/// had been provided by this instance. Higher level layers are responsible
comment|/// for taking any action required to handle the missing symbols.
name|class
name|LinkedObjectSet
block|{
name|LinkedObjectSet
argument_list|(
specifier|const
name|LinkedObjectSet
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
name|LinkedObjectSet
operator|&
operator|)
operator|=
name|delete
decl_stmt|;
name|public
label|:
name|LinkedObjectSet
argument_list|(
argument|RuntimeDyld::MemoryManager&MemMgr
argument_list|,
argument|RuntimeDyld::SymbolResolver&Resolver
argument_list|,
argument|bool ProcessAllSections
argument_list|)
block|:
name|RTDyld
argument_list|(
name|llvm
operator|::
name|make_unique
operator|<
name|RuntimeDyld
operator|>
operator|(
name|MemMgr
operator|,
name|Resolver
operator|)
argument_list|)
operator|,
name|State
argument_list|(
argument|Raw
argument_list|)
block|{
name|RTDyld
operator|->
name|setProcessAllSections
argument_list|(
name|ProcessAllSections
argument_list|)
block|;     }
name|virtual
operator|~
name|LinkedObjectSet
argument_list|()
block|{}
name|std
operator|::
name|unique_ptr
operator|<
name|RuntimeDyld
operator|::
name|LoadedObjectInfo
operator|>
name|addObject
argument_list|(
argument|const object::ObjectFile&Obj
argument_list|)
block|{
return|return
name|RTDyld
operator|->
name|loadObject
argument_list|(
name|Obj
argument_list|)
return|;
block|}
name|RuntimeDyld
operator|::
name|SymbolInfo
name|getSymbol
argument_list|(
argument|StringRef Name
argument_list|)
specifier|const
block|{
return|return
name|RTDyld
operator|->
name|getSymbol
argument_list|(
name|Name
argument_list|)
return|;
block|}
name|bool
name|NeedsFinalization
argument_list|()
specifier|const
block|{
return|return
operator|(
name|State
operator|==
name|Raw
operator|)
return|;
block|}
name|virtual
name|void
name|Finalize
parameter_list|()
init|=
literal|0
function_decl|;
name|void
name|mapSectionAddress
parameter_list|(
specifier|const
name|void
modifier|*
name|LocalAddress
parameter_list|,
name|TargetAddress
name|TargetAddr
parameter_list|)
block|{
name|assert
argument_list|(
operator|(
name|State
operator|!=
name|Finalized
operator|)
operator|&&
literal|"Attempting to remap sections for finalized objects."
argument_list|)
expr_stmt|;
name|RTDyld
operator|->
name|mapSectionAddress
argument_list|(
name|LocalAddress
argument_list|,
name|TargetAddr
argument_list|)
expr_stmt|;
block|}
name|protected
label|:
name|std
operator|::
name|unique_ptr
operator|<
name|RuntimeDyld
operator|>
name|RTDyld
expr_stmt|;
enum|enum
block|{
name|Raw
block|,
name|Finalizing
block|,
name|Finalized
block|}
name|State
enum|;
block|}
empty_stmt|;
typedef|typedef
name|std
operator|::
name|list
operator|<
name|std
operator|::
name|unique_ptr
operator|<
name|LinkedObjectSet
operator|>>
name|LinkedObjectSetListT
expr_stmt|;
name|public
label|:
comment|/// @brief Handle to a set of loaded objects.
typedef|typedef
name|LinkedObjectSetListT
operator|::
name|iterator
name|ObjSetHandleT
expr_stmt|;
block|}
empty_stmt|;
comment|/// @brief Default (no-op) action to perform when loading objects.
name|class
name|DoNothingOnNotifyLoaded
block|{
name|public
label|:
name|template
operator|<
name|typename
name|ObjSetT
operator|,
name|typename
name|LoadResult
operator|>
name|void
name|operator
argument_list|()
operator|(
name|ObjectLinkingLayerBase
operator|::
name|ObjSetHandleT
operator|,
specifier|const
name|ObjSetT
operator|&
operator|,
specifier|const
name|LoadResult
operator|&
operator|)
block|{}
block|}
empty_stmt|;
comment|/// @brief Bare bones object linking layer.
comment|///
comment|///   This class is intended to be used as the base layer for a JIT. It allows
comment|/// object files to be loaded into memory, linked, and the addresses of their
comment|/// symbols queried. All objects added to this layer can see each other's
comment|/// symbols.
name|template
operator|<
name|typename
name|NotifyLoadedFtor
operator|=
name|DoNothingOnNotifyLoaded
operator|>
name|class
name|ObjectLinkingLayer
operator|:
name|public
name|ObjectLinkingLayerBase
block|{
name|private
operator|:
name|template
operator|<
name|typename
name|MemoryManagerPtrT
block|,
name|typename
name|SymbolResolverPtrT
operator|>
name|class
name|ConcreteLinkedObjectSet
operator|:
name|public
name|LinkedObjectSet
block|{
name|public
operator|:
name|ConcreteLinkedObjectSet
argument_list|(
argument|MemoryManagerPtrT MemMgr
argument_list|,
argument|SymbolResolverPtrT Resolver
argument_list|,
argument|bool ProcessAllSections
argument_list|)
operator|:
name|LinkedObjectSet
argument_list|(
operator|*
name|MemMgr
argument_list|,
operator|*
name|Resolver
argument_list|,
name|ProcessAllSections
argument_list|)
block|,
name|MemMgr
argument_list|(
name|std
operator|::
name|move
argument_list|(
name|MemMgr
argument_list|)
argument_list|)
block|,
name|Resolver
argument_list|(
argument|std::move(Resolver)
argument_list|)
block|{ }
name|void
name|Finalize
argument_list|()
name|override
block|{
name|State
operator|=
name|Finalizing
block|;
name|RTDyld
operator|->
name|finalizeWithMemoryManagerLocking
argument_list|()
block|;
name|State
operator|=
name|Finalized
block|;     }
name|private
operator|:
name|MemoryManagerPtrT
name|MemMgr
block|;
name|SymbolResolverPtrT
name|Resolver
block|;   }
block|;
name|template
operator|<
name|typename
name|MemoryManagerPtrT
block|,
name|typename
name|SymbolResolverPtrT
operator|>
name|std
operator|::
name|unique_ptr
operator|<
name|LinkedObjectSet
operator|>
name|createLinkedObjectSet
argument_list|(
argument|MemoryManagerPtrT MemMgr
argument_list|,
argument|SymbolResolverPtrT Resolver
argument_list|,
argument|bool ProcessAllSections
argument_list|)
block|{
typedef|typedef
name|ConcreteLinkedObjectSet
operator|<
name|MemoryManagerPtrT
operator|,
name|SymbolResolverPtrT
operator|>
name|LOS
expr_stmt|;
return|return
name|llvm
operator|::
name|make_unique
operator|<
name|LOS
operator|>
operator|(
name|std
operator|::
name|move
argument_list|(
name|MemMgr
argument_list|)
operator|,
name|std
operator|::
name|move
argument_list|(
name|Resolver
argument_list|)
operator|,
name|ProcessAllSections
operator|)
return|;
block|}
name|public
label|:
comment|/// @brief LoadedObjectInfo list. Contains a list of owning pointers to
comment|///        RuntimeDyld::LoadedObjectInfo instances.
typedef|typedef
name|std
operator|::
name|vector
operator|<
name|std
operator|::
name|unique_ptr
operator|<
name|RuntimeDyld
operator|::
name|LoadedObjectInfo
operator|>>
name|LoadedObjInfoList
expr_stmt|;
comment|/// @brief Functor for receiving finalization notifications.
typedef|typedef
name|std
operator|::
name|function
operator|<
name|void
argument_list|(
name|ObjSetHandleT
argument_list|)
operator|>
name|NotifyFinalizedFtor
expr_stmt|;
comment|/// @brief Construct an ObjectLinkingLayer with the given NotifyLoaded,
comment|///        and NotifyFinalized functors.
name|ObjectLinkingLayer
argument_list|(
argument|NotifyLoadedFtor NotifyLoaded = NotifyLoadedFtor()
argument_list|,
argument|NotifyFinalizedFtor NotifyFinalized = NotifyFinalizedFtor()
argument_list|)
block|:
name|NotifyLoaded
argument_list|(
name|std
operator|::
name|move
argument_list|(
name|NotifyLoaded
argument_list|)
argument_list|)
operator|,
name|NotifyFinalized
argument_list|(
name|std
operator|::
name|move
argument_list|(
name|NotifyFinalized
argument_list|)
argument_list|)
operator|,
name|ProcessAllSections
argument_list|(
argument|false
argument_list|)
block|{}
comment|/// @brief Set the 'ProcessAllSections' flag.
comment|///
comment|/// If set to true, all sections in each object file will be allocated using
comment|/// the memory manager, rather than just the sections required for execution.
comment|///
comment|/// This is kludgy, and may be removed in the future.
name|void
name|setProcessAllSections
argument_list|(
argument|bool ProcessAllSections
argument_list|)
block|{
name|this
operator|->
name|ProcessAllSections
operator|=
name|ProcessAllSections
block|;   }
comment|/// @brief Add a set of objects (or archives) that will be treated as a unit
comment|///        for the purposes of symbol lookup and memory management.
comment|///
comment|/// @return A pair containing (1) A handle that can be used to free the memory
comment|///         allocated for the objects, and (2) a LoadedObjInfoList containing
comment|///         one LoadedObjInfo instance for each object at the corresponding
comment|///         index in the Objects list.
comment|///
comment|///   This version of this method allows the client to pass in an
comment|/// RTDyldMemoryManager instance that will be used to allocate memory and look
comment|/// up external symbol addresses for the given objects.
name|template
operator|<
name|typename
name|ObjSetT
operator|,
name|typename
name|MemoryManagerPtrT
operator|,
name|typename
name|SymbolResolverPtrT
operator|>
name|ObjSetHandleT
name|addObjectSet
argument_list|(
argument|const ObjSetT&Objects
argument_list|,
argument|MemoryManagerPtrT MemMgr
argument_list|,
argument|SymbolResolverPtrT Resolver
argument_list|)
block|{
name|ObjSetHandleT
name|Handle
operator|=
name|LinkedObjSetList
operator|.
name|insert
argument_list|(
name|LinkedObjSetList
operator|.
name|end
argument_list|()
argument_list|,
name|createLinkedObjectSet
argument_list|(
name|std
operator|::
name|move
argument_list|(
name|MemMgr
argument_list|)
argument_list|,
name|std
operator|::
name|move
argument_list|(
name|Resolver
argument_list|)
argument_list|,
name|ProcessAllSections
argument_list|)
argument_list|)
block|;
name|LinkedObjectSet
operator|&
name|LOS
operator|=
operator|*
operator|*
name|Handle
block|;
name|LoadedObjInfoList
name|LoadedObjInfos
block|;
for|for
control|(
name|auto
operator|&
name|Obj
operator|:
name|Objects
control|)
name|LoadedObjInfos
operator|.
name|push_back
argument_list|(
name|LOS
operator|.
name|addObject
argument_list|(
operator|*
name|Obj
argument_list|)
argument_list|)
expr_stmt|;
name|NotifyLoaded
argument_list|(
name|Handle
argument_list|,
name|Objects
argument_list|,
name|LoadedObjInfos
argument_list|)
expr_stmt|;
return|return
name|Handle
return|;
block|}
comment|/// @brief Remove the set of objects associated with handle H.
comment|///
comment|///   All memory allocated for the objects will be freed, and the sections and
comment|/// symbols they provided will no longer be available. No attempt is made to
comment|/// re-emit the missing symbols, and any use of these symbols (directly or
comment|/// indirectly) will result in undefined behavior. If dependence tracking is
comment|/// required to detect or resolve such issues it should be added at a higher
comment|/// layer.
name|void
name|removeObjectSet
parameter_list|(
name|ObjSetHandleT
name|H
parameter_list|)
block|{
comment|// How do we invalidate the symbols in H?
name|LinkedObjSetList
operator|.
name|erase
argument_list|(
name|H
argument_list|)
expr_stmt|;
block|}
comment|/// @brief Search for the given named symbol.
comment|/// @param Name The name of the symbol to search for.
comment|/// @param ExportedSymbolsOnly If true, search only for exported symbols.
comment|/// @return A handle for the given named symbol, if it exists.
name|JITSymbol
name|findSymbol
parameter_list|(
name|StringRef
name|Name
parameter_list|,
name|bool
name|ExportedSymbolsOnly
parameter_list|)
block|{
for|for
control|(
name|auto
name|I
init|=
name|LinkedObjSetList
operator|.
name|begin
argument_list|()
init|,
name|E
init|=
name|LinkedObjSetList
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
if|if
condition|(
name|auto
name|Symbol
init|=
name|findSymbolIn
argument_list|(
name|I
argument_list|,
name|Name
argument_list|,
name|ExportedSymbolsOnly
argument_list|)
condition|)
return|return
name|Symbol
return|;
return|return
name|nullptr
return|;
block|}
comment|/// @brief Search for the given named symbol in the context of the set of
comment|///        loaded objects represented by the handle H.
comment|/// @param H The handle for the object set to search in.
comment|/// @param Name The name of the symbol to search for.
comment|/// @param ExportedSymbolsOnly If true, search only for exported symbols.
comment|/// @return A handle for the given named symbol, if it is found in the
comment|///         given object set.
name|JITSymbol
name|findSymbolIn
parameter_list|(
name|ObjSetHandleT
name|H
parameter_list|,
name|StringRef
name|Name
parameter_list|,
name|bool
name|ExportedSymbolsOnly
parameter_list|)
block|{
if|if
condition|(
name|auto
name|Sym
init|=
operator|(
operator|*
name|H
operator|)
operator|->
name|getSymbol
argument_list|(
name|Name
argument_list|)
condition|)
block|{
if|if
condition|(
name|Sym
operator|.
name|isExported
argument_list|()
operator|||
operator|!
name|ExportedSymbolsOnly
condition|)
block|{
name|auto
name|Addr
init|=
name|Sym
operator|.
name|getAddress
argument_list|()
decl_stmt|;
name|auto
name|Flags
init|=
name|Sym
operator|.
name|getFlags
argument_list|()
decl_stmt|;
if|if
condition|(
operator|!
operator|(
operator|*
name|H
operator|)
operator|->
name|NeedsFinalization
argument_list|()
condition|)
block|{
comment|// If this instance has already been finalized then we can just return
comment|// the address.
return|return
name|JITSymbol
argument_list|(
name|Addr
argument_list|,
name|Flags
argument_list|)
return|;
block|}
else|else
block|{
comment|// If this instance needs finalization return a functor that will do
comment|// it. The functor still needs to double-check whether finalization is
comment|// required, in case someone else finalizes this set before the
comment|// functor is called.
name|auto
name|GetAddress
init|=
index|[
name|this
operator|,
name|Addr
operator|,
name|H
index|]
operator|(
operator|)
block|{
if|if
condition|(
operator|(
operator|*
name|H
operator|)
operator|->
name|NeedsFinalization
argument_list|()
condition|)
block|{
operator|(
operator|*
name|H
operator|)
operator|->
name|Finalize
argument_list|()
expr_stmt|;
if|if
condition|(
name|NotifyFinalized
condition|)
name|NotifyFinalized
argument_list|(
name|H
argument_list|)
expr_stmt|;
block|}
return|return
name|Addr
return|;
block|}
empty_stmt|;
return|return
name|JITSymbol
argument_list|(
name|std
operator|::
name|move
argument_list|(
name|GetAddress
argument_list|)
argument_list|,
name|Flags
argument_list|)
return|;
block|}
block|}
block|}
return|return
name|nullptr
return|;
block|}
end_decl_stmt

begin_comment
comment|/// @brief Map section addresses for the objects associated with the handle H.
end_comment

begin_function
name|void
name|mapSectionAddress
parameter_list|(
name|ObjSetHandleT
name|H
parameter_list|,
specifier|const
name|void
modifier|*
name|LocalAddress
parameter_list|,
name|TargetAddress
name|TargetAddr
parameter_list|)
block|{
operator|(
operator|*
name|H
operator|)
operator|->
name|mapSectionAddress
argument_list|(
name|LocalAddress
argument_list|,
name|TargetAddr
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/// @brief Immediately emit and finalize the object set represented by the
end_comment

begin_comment
comment|///        given handle.
end_comment

begin_comment
comment|/// @param H Handle for object set to emit/finalize.
end_comment

begin_function
name|void
name|emitAndFinalize
parameter_list|(
name|ObjSetHandleT
name|H
parameter_list|)
block|{
operator|(
operator|*
name|H
operator|)
operator|->
name|Finalize
argument_list|()
expr_stmt|;
if|if
condition|(
name|NotifyFinalized
condition|)
name|NotifyFinalized
argument_list|(
name|H
argument_list|)
expr_stmt|;
block|}
end_function

begin_label
name|private
label|:
end_label

begin_decl_stmt
name|LinkedObjectSetListT
name|LinkedObjSetList
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|NotifyLoadedFtor
name|NotifyLoaded
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|NotifyFinalizedFtor
name|NotifyFinalized
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|bool
name|ProcessAllSections
decl_stmt|;
end_decl_stmt

begin_comment
unit|};  }
comment|// End namespace orc.
end_comment

begin_comment
unit|}
comment|// End namespace llvm
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// LLVM_EXECUTIONENGINE_ORC_OBJECTLINKINGLAYER_H
end_comment

end_unit

