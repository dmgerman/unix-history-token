begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- RTDyldObjectLinkingLayer.h - RTDyld-based jit linking  --*- C++ -*-===//
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
comment|// Contains the definition for an RTDyld-based, in-process object linking layer.
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
name|LLVM_EXECUTIONENGINE_ORC_RTDYLDOBJECTLINKINGLAYER_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_EXECUTIONENGINE_ORC_RTDYLDOBJECTLINKINGLAYER_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/STLExtras.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/StringMap.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/StringRef.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ExecutionEngine/ExecutionEngine.h"
end_include

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
file|"llvm/ExecutionEngine/SectionMemoryManager.h"
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
file|<cassert>
end_include

begin_include
include|#
directive|include
file|<algorithm>
end_include

begin_include
include|#
directive|include
file|<functional>
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

begin_include
include|#
directive|include
file|<string>
end_include

begin_include
include|#
directive|include
file|<utility>
end_include

begin_include
include|#
directive|include
file|<vector>
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|namespace
name|orc
block|{
name|class
name|RTDyldObjectLinkingLayerBase
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
name|public
label|:
name|LinkedObjectSet
argument_list|()
operator|=
expr|default
expr_stmt|;
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
name|virtual
operator|~
name|LinkedObjectSet
argument_list|()
operator|=
expr|default
expr_stmt|;
name|virtual
name|void
name|finalize
parameter_list|()
init|=
literal|0
function_decl|;
name|virtual
name|JITSymbol
operator|::
name|GetAddressFtor
name|getSymbolMaterializer
argument_list|(
argument|std::string Name
argument_list|)
operator|=
literal|0
expr_stmt|;
name|virtual
name|void
name|mapSectionAddress
argument_list|(
specifier|const
name|void
operator|*
name|LocalAddress
argument_list|,
name|JITTargetAddress
name|TargetAddr
argument_list|)
decl|const
init|=
literal|0
decl_stmt|;
name|JITSymbol
name|getSymbol
parameter_list|(
name|StringRef
name|Name
parameter_list|,
name|bool
name|ExportedSymbolsOnly
parameter_list|)
block|{
name|auto
name|SymEntry
init|=
name|SymbolTable
operator|.
name|find
argument_list|(
name|Name
argument_list|)
decl_stmt|;
if|if
condition|(
name|SymEntry
operator|==
name|SymbolTable
operator|.
name|end
argument_list|()
condition|)
return|return
name|nullptr
return|;
if|if
condition|(
operator|!
name|SymEntry
operator|->
name|second
operator|.
name|getFlags
argument_list|()
operator|.
name|isExported
argument_list|()
operator|&&
name|ExportedSymbolsOnly
condition|)
return|return
name|nullptr
return|;
if|if
condition|(
operator|!
name|Finalized
condition|)
return|return
name|JITSymbol
argument_list|(
name|getSymbolMaterializer
argument_list|(
name|Name
argument_list|)
argument_list|,
name|SymEntry
operator|->
name|second
operator|.
name|getFlags
argument_list|()
argument_list|)
return|;
return|return
name|JITSymbol
argument_list|(
name|SymEntry
operator|->
name|second
argument_list|)
return|;
block|}
name|protected
label|:
name|StringMap
operator|<
name|JITEvaluatedSymbol
operator|>
name|SymbolTable
expr_stmt|;
name|bool
name|Finalized
init|=
name|false
decl_stmt|;
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
name|RTDyldObjectLinkingLayerBase
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
name|RTDyldObjectLinkingLayer
operator|:
name|public
name|RTDyldObjectLinkingLayerBase
block|{
name|public
operator|:
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
name|private
operator|:
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
operator|,
name|typename
name|FinalizerFtor
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
argument|ObjSetT Objects
argument_list|,
argument|MemoryManagerPtrT MemMgr
argument_list|,
argument|SymbolResolverPtrT Resolver
argument_list|,
argument|FinalizerFtor Finalizer
argument_list|,
argument|bool ProcessAllSections
argument_list|)
operator|:
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
name|PFC
argument_list|(
argument|llvm::make_unique<PreFinalizeContents>(std::move(Objects),                                                    std::move(Resolver),                                                    std::move(Finalizer),                                                    ProcessAllSections)
argument_list|)
block|{
name|buildInitialSymbolTable
argument_list|(
name|PFC
operator|->
name|Objects
argument_list|)
block|;     }
operator|~
name|ConcreteLinkedObjectSet
argument_list|()
name|override
block|{
name|MemMgr
operator|->
name|deregisterEHFrames
argument_list|()
block|;     }
name|void
name|setHandle
argument_list|(
argument|ObjSetHandleT H
argument_list|)
block|{
name|PFC
operator|->
name|Handle
operator|=
name|H
block|;     }
name|void
name|finalize
argument_list|()
name|override
block|{
name|assert
argument_list|(
name|PFC
operator|&&
literal|"mapSectionAddress called on finalized LinkedObjectSet"
argument_list|)
block|;
name|RuntimeDyld
name|RTDyld
argument_list|(
operator|*
name|MemMgr
argument_list|,
operator|*
name|PFC
operator|->
name|Resolver
argument_list|)
block|;
name|RTDyld
operator|.
name|setProcessAllSections
argument_list|(
name|PFC
operator|->
name|ProcessAllSections
argument_list|)
block|;
name|PFC
operator|->
name|RTDyld
operator|=
operator|&
name|RTDyld
block|;
name|this
operator|->
name|Finalized
operator|=
name|true
block|;
name|PFC
operator|->
name|Finalizer
argument_list|(
name|PFC
operator|->
name|Handle
argument_list|,
name|RTDyld
argument_list|,
name|std
operator|::
name|move
argument_list|(
name|PFC
operator|->
name|Objects
argument_list|)
argument_list|,
index|[
operator|&
index|]
operator|(
operator|)
block|{
name|this
operator|->
name|updateSymbolTable
argument_list|(
name|RTDyld
argument_list|)
block|;                      }
argument_list|)
block|;
comment|// Release resources.
name|PFC
operator|=
name|nullptr
block|;     }
name|JITSymbol
operator|::
name|GetAddressFtor
name|getSymbolMaterializer
argument_list|(
argument|std::string Name
argument_list|)
name|override
block|{
return|return
index|[
name|this
operator|,
name|Name
index|]
operator|(
operator|)
block|{
comment|// The symbol may be materialized between the creation of this lambda
comment|// and its execution, so we need to double check.
if|if
condition|(
operator|!
name|this
operator|->
name|Finalized
condition|)
name|this
operator|->
name|finalize
argument_list|()
expr_stmt|;
return|return
name|this
operator|->
name|getSymbol
argument_list|(
name|Name
argument_list|,
name|false
argument_list|)
operator|.
name|getAddress
argument_list|()
return|;
block|}
block|;     }
name|void
name|mapSectionAddress
argument_list|(
argument|const void *LocalAddress
argument_list|,
argument|JITTargetAddress TargetAddr
argument_list|)
specifier|const
name|override
block|{
name|assert
argument_list|(
name|PFC
operator|&&
literal|"mapSectionAddress called on finalized LinkedObjectSet"
argument_list|)
block|;
name|assert
argument_list|(
name|PFC
operator|->
name|RTDyld
operator|&&
literal|"mapSectionAddress called on raw LinkedObjectSet"
argument_list|)
block|;
name|PFC
operator|->
name|RTDyld
operator|->
name|mapSectionAddress
argument_list|(
name|LocalAddress
argument_list|,
name|TargetAddr
argument_list|)
block|;     }
name|private
operator|:
name|void
name|buildInitialSymbolTable
argument_list|(
argument|const ObjSetT&Objects
argument_list|)
block|{
for|for
control|(
specifier|const
specifier|auto
modifier|&
name|Obj
range|:
name|Objects
control|)
for|for
control|(
name|auto
operator|&
name|Symbol
operator|:
name|getObject
argument_list|(
operator|*
name|Obj
argument_list|)
operator|.
name|symbols
argument_list|()
control|)
block|{
if|if
condition|(
name|Symbol
operator|.
name|getFlags
argument_list|()
operator|&
name|object
operator|::
name|SymbolRef
operator|::
name|SF_Undefined
condition|)
continue|continue;
name|Expected
operator|<
name|StringRef
operator|>
name|SymbolName
operator|=
name|Symbol
operator|.
name|getName
argument_list|()
expr_stmt|;
comment|// FIXME: Raise an error for bad symbols.
if|if
condition|(
operator|!
name|SymbolName
condition|)
block|{
name|consumeError
argument_list|(
name|SymbolName
operator|.
name|takeError
argument_list|()
argument_list|)
expr_stmt|;
continue|continue;
block|}
name|auto
name|Flags
init|=
name|JITSymbolFlags
operator|::
name|fromObjectSymbol
argument_list|(
name|Symbol
argument_list|)
decl_stmt|;
name|SymbolTable
operator|.
name|insert
argument_list|(
name|std
operator|::
name|make_pair
argument_list|(
operator|*
name|SymbolName
argument_list|,
name|JITEvaluatedSymbol
argument_list|(
literal|0
argument_list|,
name|Flags
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
block|}
block|}
name|void
name|updateSymbolTable
argument_list|(
argument|const RuntimeDyld&RTDyld
argument_list|)
block|{
for|for
control|(
name|auto
operator|&
name|SymEntry
operator|:
name|SymbolTable
control|)
name|SymEntry
operator|.
name|second
operator|=
name|RTDyld
operator|.
name|getSymbol
argument_list|(
name|SymEntry
operator|.
name|first
argument_list|()
argument_list|)
expr_stmt|;
block|}
comment|// Contains the information needed prior to finalization: the object files,
comment|// memory manager, resolver, and flags needed for RuntimeDyld.
struct|struct
name|PreFinalizeContents
block|{
name|PreFinalizeContents
argument_list|(
argument|ObjSetT Objects
argument_list|,
argument|SymbolResolverPtrT Resolver
argument_list|,
argument|FinalizerFtor Finalizer
argument_list|,
argument|bool ProcessAllSections
argument_list|)
block|:
name|Objects
argument_list|(
name|std
operator|::
name|move
argument_list|(
name|Objects
argument_list|)
argument_list|)
operator|,
name|Resolver
argument_list|(
name|std
operator|::
name|move
argument_list|(
name|Resolver
argument_list|)
argument_list|)
operator|,
name|Finalizer
argument_list|(
name|std
operator|::
name|move
argument_list|(
name|Finalizer
argument_list|)
argument_list|)
operator|,
name|ProcessAllSections
argument_list|(
argument|ProcessAllSections
argument_list|)
block|{}
name|ObjSetT
name|Objects
expr_stmt|;
name|SymbolResolverPtrT
name|Resolver
decl_stmt|;
name|FinalizerFtor
name|Finalizer
decl_stmt|;
name|bool
name|ProcessAllSections
decl_stmt|;
name|ObjSetHandleT
name|Handle
decl_stmt|;
name|RuntimeDyld
modifier|*
name|RTDyld
decl_stmt|;
block|}
struct|;
name|MemoryManagerPtrT
name|MemMgr
decl_stmt|;
name|std
operator|::
name|unique_ptr
operator|<
name|PreFinalizeContents
operator|>
name|PFC
expr_stmt|;
block|}
empty_stmt|;
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
operator|,
name|typename
name|FinalizerFtor
operator|>
name|std
operator|::
name|unique_ptr
operator|<
name|ConcreteLinkedObjectSet
operator|<
name|ObjSetT
operator|,
name|MemoryManagerPtrT
operator|,
name|SymbolResolverPtrT
operator|,
name|FinalizerFtor
operator|>>
name|createLinkedObjectSet
argument_list|(
argument|ObjSetT Objects
argument_list|,
argument|MemoryManagerPtrT MemMgr
argument_list|,
argument|SymbolResolverPtrT Resolver
argument_list|,
argument|FinalizerFtor Finalizer
argument_list|,
argument|bool ProcessAllSections
argument_list|)
block|{
typedef|typedef
name|ConcreteLinkedObjectSet
operator|<
name|ObjSetT
operator|,
name|MemoryManagerPtrT
operator|,
name|SymbolResolverPtrT
operator|,
name|FinalizerFtor
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
name|Objects
argument_list|)
operator|,
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
name|std
operator|::
name|move
argument_list|(
name|Finalizer
argument_list|)
operator|,
name|ProcessAllSections
operator|)
return|;
block|}
end_decl_stmt

begin_label
name|public
label|:
end_label

begin_comment
comment|/// @brief LoadedObjectInfo list. Contains a list of owning pointers to
end_comment

begin_comment
comment|///        RuntimeDyld::LoadedObjectInfo instances.
end_comment

begin_typedef
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
end_typedef

begin_comment
comment|/// @brief Construct an ObjectLinkingLayer with the given NotifyLoaded,
end_comment

begin_comment
comment|///        and NotifyFinalized functors.
end_comment

begin_macro
name|RTDyldObjectLinkingLayer
argument_list|(
argument|NotifyLoadedFtor NotifyLoaded = NotifyLoadedFtor()
argument_list|,
argument|NotifyFinalizedFtor NotifyFinalized = NotifyFinalizedFtor()
argument_list|)
end_macro

begin_expr_stmt
unit|:
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
comment|/// @return A handle that can be used to refer to the loaded objects (for
comment|///         symbol searching, finalization, freeing memory, etc.).
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
argument|ObjSetT Objects
argument_list|,
argument|MemoryManagerPtrT MemMgr
argument_list|,
argument|SymbolResolverPtrT Resolver
argument_list|)
block|{
name|auto
name|Finalizer
operator|=
index|[
operator|&
index|]
operator|(
name|ObjSetHandleT
name|H
operator|,
name|RuntimeDyld
operator|&
name|RTDyld
operator|,
specifier|const
name|ObjSetT
operator|&
name|Objs
operator|,
name|std
operator|::
name|function
operator|<
name|void
argument_list|()
operator|>
name|LOSHandleLoad
operator|)
block|{
name|LoadedObjInfoList
name|LoadedObjInfos
block|;
for|for
control|(
name|auto
operator|&
name|Obj
operator|:
name|Objs
control|)
name|LoadedObjInfos
operator|.
name|push_back
argument_list|(
name|RTDyld
operator|.
name|loadObject
argument_list|(
name|this
operator|->
name|getObject
argument_list|(
operator|*
name|Obj
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|LOSHandleLoad
argument_list|()
block|;
name|this
operator|->
name|NotifyLoaded
argument_list|(
name|H
argument_list|,
name|Objs
argument_list|,
name|LoadedObjInfos
argument_list|)
block|;
name|RTDyld
operator|.
name|finalizeWithMemoryManagerLocking
argument_list|()
block|;
if|if
condition|(
name|this
operator|->
name|NotifyFinalized
condition|)
name|this
operator|->
name|NotifyFinalized
argument_list|(
name|H
argument_list|)
expr_stmt|;
block|}
end_expr_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_decl_stmt
name|auto
name|LOS
init|=
name|createLinkedObjectSet
argument_list|(
name|std
operator|::
name|move
argument_list|(
name|Objects
argument_list|)
argument_list|,
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
name|std
operator|::
name|move
argument_list|(
name|Finalizer
argument_list|)
argument_list|,
name|ProcessAllSections
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|// LOS is an owning-ptr. Keep a non-owning one so that we can set the handle
end_comment

begin_comment
comment|// below.
end_comment

begin_expr_stmt
name|auto
operator|*
name|LOSPtr
operator|=
name|LOS
operator|.
name|get
argument_list|()
expr_stmt|;
end_expr_stmt

begin_decl_stmt
name|ObjSetHandleT
name|Handle
init|=
name|LinkedObjSetList
operator|.
name|insert
argument_list|(
name|LinkedObjSetList
operator|.
name|end
argument_list|()
argument_list|,
name|std
operator|::
name|move
argument_list|(
name|LOS
argument_list|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|LOSPtr
operator|->
name|setHandle
argument_list|(
name|Handle
argument_list|)
expr_stmt|;
end_expr_stmt

begin_return
return|return
name|Handle
return|;
end_return

begin_comment
unit|}
comment|/// @brief Remove the set of objects associated with handle H.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|///   All memory allocated for the objects will be freed, and the sections and
end_comment

begin_comment
comment|/// symbols they provided will no longer be available. No attempt is made to
end_comment

begin_comment
comment|/// re-emit the missing symbols, and any use of these symbols (directly or
end_comment

begin_comment
comment|/// indirectly) will result in undefined behavior. If dependence tracking is
end_comment

begin_comment
comment|/// required to detect or resolve such issues it should be added at a higher
end_comment

begin_comment
comment|/// layer.
end_comment

begin_macro
unit|void
name|removeObjectSet
argument_list|(
argument|ObjSetHandleT H
argument_list|)
end_macro

begin_block
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
end_block

begin_comment
comment|/// @brief Search for the given named symbol.
end_comment

begin_comment
comment|/// @param Name The name of the symbol to search for.
end_comment

begin_comment
comment|/// @param ExportedSymbolsOnly If true, search only for exported symbols.
end_comment

begin_comment
comment|/// @return A handle for the given named symbol, if it exists.
end_comment

begin_function
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
end_function

begin_comment
comment|/// @brief Search for the given named symbol in the context of the set of
end_comment

begin_comment
comment|///        loaded objects represented by the handle H.
end_comment

begin_comment
comment|/// @param H The handle for the object set to search in.
end_comment

begin_comment
comment|/// @param Name The name of the symbol to search for.
end_comment

begin_comment
comment|/// @param ExportedSymbolsOnly If true, search only for exported symbols.
end_comment

begin_comment
comment|/// @return A handle for the given named symbol, if it is found in the
end_comment

begin_comment
comment|///         given object set.
end_comment

begin_function
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
return|return
operator|(
operator|*
name|H
operator|)
operator|->
name|getSymbol
argument_list|(
name|Name
argument_list|,
name|ExportedSymbolsOnly
argument_list|)
return|;
block|}
end_function

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
name|JITTargetAddress
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
name|finalize
argument_list|()
expr_stmt|;
block|}
end_function

begin_label
name|private
label|:
end_label

begin_expr_stmt
specifier|static
specifier|const
name|object
operator|::
name|ObjectFile
operator|&
name|getObject
argument_list|(
argument|const object::ObjectFile&Obj
argument_list|)
block|{
return|return
name|Obj
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|template
operator|<
name|typename
name|ObjT
operator|>
specifier|static
specifier|const
name|object
operator|::
name|ObjectFile
operator|&
name|getObject
argument_list|(
argument|const object::OwningBinary<ObjT>&Obj
argument_list|)
block|{
return|return
operator|*
name|Obj
operator|.
name|getBinary
argument_list|()
return|;
block|}
end_expr_stmt

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
comment|// end namespace orc
end_comment

begin_comment
unit|}
comment|// end namespace llvm
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// LLVM_EXECUTIONENGINE_ORC_RTDYLDOBJECTLINKINGLAYER_H
end_comment

end_unit

