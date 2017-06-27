begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- LazyEmittingLayer.h - Lazily emit IR to lower JIT layers -*- C++ -*-===//
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
comment|// Contains the definition for a lazy-emitting layer for the JIT.
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
name|LLVM_EXECUTIONENGINE_ORC_LAZYEMITTINGLAYER_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_EXECUTIONENGINE_ORC_LAZYEMITTINGLAYER_H
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
file|"llvm/ExecutionEngine/JITSymbol.h"
end_include

begin_include
include|#
directive|include
file|"llvm/IR/GlobalValue.h"
end_include

begin_include
include|#
directive|include
file|"llvm/IR/Mangler.h"
end_include

begin_include
include|#
directive|include
file|"llvm/IR/Module.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/ErrorHandling.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/raw_ostream.h"
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

begin_decl_stmt
name|namespace
name|llvm
block|{
name|namespace
name|orc
block|{
comment|/// @brief Lazy-emitting IR layer.
comment|///
comment|///   This layer accepts LLVM IR Modules (via addModule), but does not
comment|/// immediately emit them the layer below. Instead, emissing to the base layer
comment|/// is deferred until the first time the client requests the address (via
comment|/// JITSymbol::getAddress) for a symbol contained in this layer.
name|template
operator|<
name|typename
name|BaseLayerT
operator|>
name|class
name|LazyEmittingLayer
block|{
name|public
operator|:
name|using
name|BaseLayerHandleT
operator|=
name|typename
name|BaseLayerT
operator|::
name|ModuleHandleT
block|;
name|private
operator|:
name|class
name|EmissionDeferredModule
block|{
name|public
operator|:
name|EmissionDeferredModule
argument_list|()
operator|=
expr|default
block|;
name|virtual
operator|~
name|EmissionDeferredModule
argument_list|()
operator|=
expr|default
block|;
name|JITSymbol
name|find
argument_list|(
argument|StringRef Name
argument_list|,
argument|bool ExportedSymbolsOnly
argument_list|,
argument|BaseLayerT&B
argument_list|)
block|{
switch|switch
condition|(
name|EmitState
condition|)
block|{
case|case
name|NotEmitted
case|:
if|if
condition|(
name|auto
name|GV
init|=
name|searchGVs
argument_list|(
name|Name
argument_list|,
name|ExportedSymbolsOnly
argument_list|)
condition|)
block|{
comment|// Create a std::string version of Name to capture here - the argument
comment|// (a StringRef) may go away before the lambda is executed.
comment|// FIXME: Use capture-init when we move to C++14.
name|std
operator|::
name|string
name|PName
operator|=
name|Name
expr_stmt|;
name|JITSymbolFlags
name|Flags
init|=
name|JITSymbolFlags
operator|::
name|fromGlobalValue
argument_list|(
operator|*
name|GV
argument_list|)
decl_stmt|;
name|auto
name|GetAddress
init|=
index|[
name|this
operator|,
name|ExportedSymbolsOnly
operator|,
name|PName
operator|,
operator|&
name|B
index|]
operator|(
operator|)
operator|->
name|JITTargetAddress
block|{
if|if
condition|(
name|this
operator|->
name|EmitState
operator|==
name|Emitting
condition|)
return|return
literal|0
return|;
elseif|else
if|if
condition|(
name|this
operator|->
name|EmitState
operator|==
name|NotEmitted
condition|)
block|{
name|this
operator|->
name|EmitState
operator|=
name|Emitting
expr_stmt|;
name|Handle
operator|=
name|this
operator|->
name|emitToBaseLayer
argument_list|(
name|B
argument_list|)
expr_stmt|;
name|this
operator|->
name|EmitState
operator|=
name|Emitted
expr_stmt|;
block|}
name|auto
name|Sym
init|=
name|B
operator|.
name|findSymbolIn
argument_list|(
name|Handle
argument_list|,
name|PName
argument_list|,
name|ExportedSymbolsOnly
argument_list|)
decl_stmt|;
return|return
name|Sym
operator|.
name|getAddress
argument_list|()
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
else|else
return|return
name|nullptr
return|;
case|case
name|Emitting
case|:
comment|// Calling "emit" can trigger a recursive call to 'find' (e.g. to check
comment|// for pre-existing definitions of common-symbol), but any symbol in
comment|// this module would already have been found internally (in the
comment|// RuntimeDyld that did the lookup), so just return a nullptr here.
return|return
name|nullptr
return|;
case|case
name|Emitted
case|:
return|return
name|B
operator|.
name|findSymbolIn
argument_list|(
name|Handle
argument_list|,
name|Name
argument_list|,
name|ExportedSymbolsOnly
argument_list|)
return|;
block|}
name|llvm_unreachable
argument_list|(
literal|"Invalid emit-state."
argument_list|)
block|;     }
name|void
name|removeModuleFromBaseLayer
argument_list|(
argument|BaseLayerT&BaseLayer
argument_list|)
block|{
if|if
condition|(
name|EmitState
operator|!=
name|NotEmitted
condition|)
name|BaseLayer
operator|.
name|removeModule
argument_list|(
name|Handle
argument_list|)
expr_stmt|;
block|}
name|void
name|emitAndFinalize
parameter_list|(
name|BaseLayerT
modifier|&
name|BaseLayer
parameter_list|)
block|{
name|assert
argument_list|(
name|EmitState
operator|!=
name|Emitting
operator|&&
literal|"Cannot emitAndFinalize while already emitting"
argument_list|)
expr_stmt|;
if|if
condition|(
name|EmitState
operator|==
name|NotEmitted
condition|)
block|{
name|EmitState
operator|=
name|Emitting
expr_stmt|;
name|Handle
operator|=
name|emitToBaseLayer
argument_list|(
name|BaseLayer
argument_list|)
expr_stmt|;
name|EmitState
operator|=
name|Emitted
expr_stmt|;
block|}
name|BaseLayer
operator|.
name|emitAndFinalize
argument_list|(
name|Handle
argument_list|)
expr_stmt|;
block|}
name|template
operator|<
name|typename
name|MemoryManagerPtrT
operator|,
name|typename
name|SymbolResolverPtrT
operator|>
specifier|static
name|std
operator|::
name|unique_ptr
operator|<
name|EmissionDeferredModule
operator|>
name|create
argument_list|(
argument|BaseLayerT&B
argument_list|,
argument|std::shared_ptr<Module> M
argument_list|,
argument|MemoryManagerPtrT MemMgr
argument_list|,
argument|SymbolResolverPtrT Resolver
argument_list|)
expr_stmt|;
name|protected
label|:
name|virtual
specifier|const
name|GlobalValue
modifier|*
name|searchGVs
argument_list|(
name|StringRef
name|Name
argument_list|,
name|bool
name|ExportedSymbolsOnly
argument_list|)
decl|const
init|=
literal|0
decl_stmt|;
name|virtual
name|BaseLayerHandleT
name|emitToBaseLayer
parameter_list|(
name|BaseLayerT
modifier|&
name|BaseLayer
parameter_list|)
init|=
literal|0
function_decl|;
name|private
label|:
enum|enum
block|{
name|NotEmitted
block|,
name|Emitting
block|,
name|Emitted
block|}
name|EmitState
init|=
name|NotEmitted
enum|;
name|BaseLayerHandleT
name|Handle
decl_stmt|;
block|}
empty_stmt|;
name|template
operator|<
name|typename
name|MemoryManagerPtrT
operator|,
name|typename
name|SymbolResolverPtrT
operator|>
name|class
name|EmissionDeferredModuleImpl
operator|:
name|public
name|EmissionDeferredModule
block|{
name|public
operator|:
name|EmissionDeferredModuleImpl
argument_list|(
argument|std::shared_ptr<Module> M
argument_list|,
argument|MemoryManagerPtrT MemMgr
argument_list|,
argument|SymbolResolverPtrT Resolver
argument_list|)
operator|:
name|M
argument_list|(
name|std
operator|::
name|move
argument_list|(
name|M
argument_list|)
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
block|{}
name|protected
operator|:
specifier|const
name|GlobalValue
operator|*
name|searchGVs
argument_list|(
argument|StringRef Name
argument_list|,
argument|bool ExportedSymbolsOnly
argument_list|)
specifier|const
name|override
block|{
comment|// FIXME: We could clean all this up if we had a way to reliably demangle
comment|//        names: We could just demangle name and search, rather than
comment|//        mangling everything else.
comment|// If we have already built the mangled name set then just search it.
if|if
condition|(
name|MangledSymbols
condition|)
block|{
name|auto
name|VI
init|=
name|MangledSymbols
operator|->
name|find
argument_list|(
name|Name
argument_list|)
decl_stmt|;
if|if
condition|(
name|VI
operator|==
name|MangledSymbols
operator|->
name|end
argument_list|()
condition|)
return|return
name|nullptr
return|;
name|auto
name|GV
init|=
name|VI
operator|->
name|second
decl_stmt|;
if|if
condition|(
operator|!
name|ExportedSymbolsOnly
operator|||
name|GV
operator|->
name|hasDefaultVisibility
argument_list|()
condition|)
return|return
name|GV
return|;
return|return
name|nullptr
return|;
block|}
comment|// If we haven't built the mangled name set yet, try to build it. As an
comment|// optimization this will leave MangledNames set to nullptr if we find
comment|// Name in the process of building the set.
return|return
name|buildMangledSymbols
argument_list|(
name|Name
argument_list|,
name|ExportedSymbolsOnly
argument_list|)
return|;
block|}
name|BaseLayerHandleT
name|emitToBaseLayer
argument_list|(
argument|BaseLayerT&BaseLayer
argument_list|)
name|override
block|{
comment|// We don't need the mangled names set any more: Once we've emitted this
comment|// to the base layer we'll just look for symbols there.
name|MangledSymbols
operator|.
name|reset
argument_list|()
block|;
return|return
name|BaseLayer
operator|.
name|addModule
argument_list|(
name|std
operator|::
name|move
argument_list|(
name|M
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
argument_list|)
return|;
block|}
name|private
operator|:
comment|// If the mangled name of the given GlobalValue matches the given search
comment|// name (and its visibility conforms to the ExportedSymbolsOnly flag) then
comment|// return the symbol. Otherwise, add the mangled name to the Names map and
comment|// return nullptr.
specifier|const
name|GlobalValue
operator|*
name|addGlobalValue
argument_list|(
argument|StringMap<const GlobalValue*>&Names
argument_list|,
argument|const GlobalValue&GV
argument_list|,
argument|const Mangler&Mang
argument_list|,
argument|StringRef SearchName
argument_list|,
argument|bool ExportedSymbolsOnly
argument_list|)
specifier|const
block|{
comment|// Modules don't "provide" decls or common symbols.
if|if
condition|(
name|GV
operator|.
name|isDeclaration
argument_list|()
operator|||
name|GV
operator|.
name|hasCommonLinkage
argument_list|()
condition|)
return|return
name|nullptr
return|;
comment|// Mangle the GV name.
name|std
operator|::
name|string
name|MangledName
block|;
block|{
name|raw_string_ostream
name|MangledNameStream
argument_list|(
name|MangledName
argument_list|)
block|;
name|Mang
operator|.
name|getNameWithPrefix
argument_list|(
name|MangledNameStream
argument_list|,
operator|&
name|GV
argument_list|,
name|false
argument_list|)
block|;       }
comment|// Check whether this is the name we were searching for, and if it is then
comment|// bail out early.
if|if
condition|(
name|MangledName
operator|==
name|SearchName
condition|)
if|if
condition|(
operator|!
name|ExportedSymbolsOnly
operator|||
name|GV
operator|.
name|hasDefaultVisibility
argument_list|()
condition|)
return|return
operator|&
name|GV
return|;
comment|// Otherwise add this to the map for later.
name|Names
index|[
name|MangledName
index|]
operator|=
operator|&
name|GV
expr_stmt|;
return|return
name|nullptr
return|;
block|}
end_decl_stmt

begin_comment
comment|// Build the MangledSymbols map. Bails out early (with MangledSymbols left set
end_comment

begin_comment
comment|// to nullptr) if the given SearchName is found while building the map.
end_comment

begin_decl_stmt
specifier|const
name|GlobalValue
modifier|*
name|buildMangledSymbols
argument_list|(
name|StringRef
name|SearchName
argument_list|,
name|bool
name|ExportedSymbolsOnly
argument_list|)
decl|const
block|{
name|assert
argument_list|(
operator|!
name|MangledSymbols
operator|&&
literal|"Mangled symbols map already exists?"
argument_list|)
expr_stmt|;
name|auto
name|Symbols
init|=
name|llvm
operator|::
name|make_unique
operator|<
name|StringMap
operator|<
specifier|const
name|GlobalValue
operator|*
operator|>>
operator|(
operator|)
decl_stmt|;
name|Mangler
name|Mang
decl_stmt|;
for|for
control|(
specifier|const
specifier|auto
modifier|&
name|GO
range|:
name|M
operator|->
name|global_objects
argument_list|()
control|)
if|if
condition|(
name|auto
name|GV
init|=
name|addGlobalValue
argument_list|(
operator|*
name|Symbols
argument_list|,
name|GO
argument_list|,
name|Mang
argument_list|,
name|SearchName
argument_list|,
name|ExportedSymbolsOnly
argument_list|)
condition|)
return|return
name|GV
return|;
name|MangledSymbols
operator|=
name|std
operator|::
name|move
argument_list|(
name|Symbols
argument_list|)
expr_stmt|;
return|return
name|nullptr
return|;
block|}
end_decl_stmt

begin_expr_stmt
name|std
operator|::
name|shared_ptr
operator|<
name|Module
operator|>
name|M
expr_stmt|;
end_expr_stmt

begin_decl_stmt
name|MemoryManagerPtrT
name|MemMgr
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|SymbolResolverPtrT
name|Resolver
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|mutable
name|std
operator|::
name|unique_ptr
operator|<
name|StringMap
operator|<
specifier|const
name|GlobalValue
operator|*
operator|>>
name|MangledSymbols
expr_stmt|;
end_expr_stmt

begin_decl_stmt
unit|};
name|using
name|ModuleListT
init|=
name|std
operator|::
name|list
operator|<
name|std
operator|::
name|unique_ptr
operator|<
name|EmissionDeferredModule
operator|>>
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|BaseLayerT
modifier|&
name|BaseLayer
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|ModuleListT
name|ModuleList
decl_stmt|;
end_decl_stmt

begin_label
name|public
label|:
end_label

begin_comment
comment|/// @brief Handle to a loaded module.
end_comment

begin_decl_stmt
name|using
name|ModuleHandleT
init|=
name|typename
name|ModuleListT
operator|::
name|iterator
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// @brief Construct a lazy emitting layer.
end_comment

begin_expr_stmt
name|LazyEmittingLayer
argument_list|(
name|BaseLayerT
operator|&
name|BaseLayer
argument_list|)
operator|:
name|BaseLayer
argument_list|(
argument|BaseLayer
argument_list|)
block|{}
comment|/// @brief Add the given module to the lazy emitting layer.
name|template
operator|<
name|typename
name|MemoryManagerPtrT
operator|,
name|typename
name|SymbolResolverPtrT
operator|>
name|ModuleHandleT
name|addModule
argument_list|(
argument|std::shared_ptr<Module> M
argument_list|,
argument|MemoryManagerPtrT MemMgr
argument_list|,
argument|SymbolResolverPtrT Resolver
argument_list|)
block|{
return|return
name|ModuleList
operator|.
name|insert
argument_list|(
name|ModuleList
operator|.
name|end
argument_list|()
argument_list|,
name|EmissionDeferredModule
operator|::
name|create
argument_list|(
name|BaseLayer
argument_list|,
name|std
operator|::
name|move
argument_list|(
name|M
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
argument_list|)
argument_list|)
return|;
block|}
end_expr_stmt

begin_comment
comment|/// @brief Remove the module represented by the given handle.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|///   This method will free the memory associated with the given module, both
end_comment

begin_comment
comment|/// in this layer, and the base layer.
end_comment

begin_function
name|void
name|removeModule
parameter_list|(
name|ModuleHandleT
name|H
parameter_list|)
block|{
operator|(
operator|*
name|H
operator|)
operator|->
name|removeModuleFromBaseLayer
argument_list|(
name|BaseLayer
argument_list|)
expr_stmt|;
name|ModuleList
operator|.
name|erase
argument_list|(
name|H
argument_list|)
expr_stmt|;
block|}
end_function

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

begin_decl_stmt
name|JITSymbol
name|findSymbol
argument_list|(
specifier|const
name|std
operator|::
name|string
operator|&
name|Name
argument_list|,
name|bool
name|ExportedSymbolsOnly
argument_list|)
block|{
comment|// Look for the symbol among existing definitions.
if|if
condition|(
name|auto
name|Symbol
init|=
name|BaseLayer
operator|.
name|findSymbol
argument_list|(
name|Name
argument_list|,
name|ExportedSymbolsOnly
argument_list|)
condition|)
return|return
name|Symbol
return|;
comment|// If not found then search the deferred modules. If any of these contain a
comment|// definition of 'Name' then they will return a JITSymbol that will emit
comment|// the corresponding module when the symbol address is requested.
for|for
control|(
name|auto
operator|&
name|DeferredMod
operator|:
name|ModuleList
control|)
if|if
condition|(
name|auto
name|Symbol
init|=
name|DeferredMod
operator|->
name|find
argument_list|(
name|Name
argument_list|,
name|ExportedSymbolsOnly
argument_list|,
name|BaseLayer
argument_list|)
condition|)
return|return
name|Symbol
return|;
comment|// If no definition found anywhere return a null symbol.
return|return
name|nullptr
return|;
block|}
end_decl_stmt

begin_comment
comment|/// @brief Get the address of the given symbol in the context of the of
end_comment

begin_comment
comment|///        compiled modules represented by the handle H.
end_comment

begin_decl_stmt
name|JITSymbol
name|findSymbolIn
argument_list|(
name|ModuleHandleT
name|H
argument_list|,
specifier|const
name|std
operator|::
name|string
operator|&
name|Name
argument_list|,
name|bool
name|ExportedSymbolsOnly
argument_list|)
block|{
return|return
operator|(
operator|*
name|H
operator|)
operator|->
name|find
argument_list|(
name|Name
argument_list|,
name|ExportedSymbolsOnly
argument_list|,
name|BaseLayer
argument_list|)
return|;
block|}
end_decl_stmt

begin_comment
comment|/// @brief Immediately emit and finalize the module represented by the given
end_comment

begin_comment
comment|///        handle.
end_comment

begin_comment
comment|/// @param H Handle for module to emit/finalize.
end_comment

begin_function
name|void
name|emitAndFinalize
parameter_list|(
name|ModuleHandleT
name|H
parameter_list|)
block|{
operator|(
operator|*
name|H
operator|)
operator|->
name|emitAndFinalize
argument_list|(
name|BaseLayer
argument_list|)
expr_stmt|;
block|}
end_function

begin_expr_stmt
unit|};
name|template
operator|<
name|typename
name|BaseLayerT
operator|>
name|template
operator|<
name|typename
name|MemoryManagerPtrT
operator|,
name|typename
name|SymbolResolverPtrT
operator|>
name|std
operator|::
name|unique_ptr
operator|<
name|typename
name|LazyEmittingLayer
operator|<
name|BaseLayerT
operator|>
operator|::
name|EmissionDeferredModule
operator|>
name|LazyEmittingLayer
operator|<
name|BaseLayerT
operator|>
operator|::
name|EmissionDeferredModule
operator|::
name|create
argument_list|(
argument|BaseLayerT&B
argument_list|,
argument|std::shared_ptr<Module> M
argument_list|,
argument|MemoryManagerPtrT MemMgr
argument_list|,
argument|SymbolResolverPtrT Resolver
argument_list|)
block|{
name|using
name|EDS
operator|=
name|EmissionDeferredModuleImpl
operator|<
name|MemoryManagerPtrT
block|,
name|SymbolResolverPtrT
operator|>
block|;
return|return
name|llvm
operator|::
name|make_unique
operator|<
name|EDS
operator|>
operator|(
name|std
operator|::
name|move
argument_list|(
name|M
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
operator|)
return|;
block|}
end_expr_stmt

begin_comment
unit|}
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
comment|// LLVM_EXECUTIONENGINE_ORC_LAZYEMITTINGLAYER_H
end_comment

end_unit

