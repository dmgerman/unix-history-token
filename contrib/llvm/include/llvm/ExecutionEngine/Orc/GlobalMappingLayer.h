begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- GlobalMappingLayer.h - Run all IR through a functor ------*- C++ -*-===//
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
comment|// Convenience layer for injecting symbols that will appear in calls to
end_comment

begin_comment
comment|// findSymbol.
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
name|LLVM_EXECUTIONENGINE_ORC_GLOBALMAPPINGLAYER_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_EXECUTIONENGINE_ORC_GLOBALMAPPINGLAYER_H
end_define

begin_include
include|#
directive|include
file|"llvm/ExecutionEngine/JITSymbol.h"
end_include

begin_include
include|#
directive|include
file|<map>
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
comment|/// @brief Global mapping layer.
comment|///
comment|///   This layer overrides the findSymbol method to first search a local symbol
comment|/// table that the client can define. It can be used to inject new symbol
comment|/// mappings into the JIT. Beware, however: symbols within a single IR module or
comment|/// object file will still resolve locally (via RuntimeDyld's symbol table) -
comment|/// such internal references cannot be overriden via this layer.
name|template
operator|<
name|typename
name|BaseLayerT
operator|>
name|class
name|GlobalMappingLayer
block|{
name|public
operator|:
comment|/// @brief Handle to a set of added modules.
name|using
name|ModuleSetHandleT
operator|=
name|typename
name|BaseLayerT
operator|::
name|ModuleSetHandleT
block|;
comment|/// @brief Construct an GlobalMappingLayer with the given BaseLayer
name|GlobalMappingLayer
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
comment|/// @brief Add the given module set to the JIT.
comment|/// @return A handle for the added modules.
name|template
operator|<
name|typename
name|ModuleSetT
block|,
name|typename
name|MemoryManagerPtrT
block|,
name|typename
name|SymbolResolverPtrT
operator|>
name|ModuleSetHandleT
name|addModuleSet
argument_list|(
argument|ModuleSetT Ms
argument_list|,
argument|MemoryManagerPtrT MemMgr
argument_list|,
argument|SymbolResolverPtrT Resolver
argument_list|)
block|{
return|return
name|BaseLayer
operator|.
name|addModuleSet
argument_list|(
name|std
operator|::
name|move
argument_list|(
name|Ms
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
comment|/// @brief Remove the module set associated with the handle H.
name|void
name|removeModuleSet
argument_list|(
argument|ModuleSetHandleT H
argument_list|)
block|{
name|BaseLayer
operator|.
name|removeModuleSet
argument_list|(
name|H
argument_list|)
block|; }
comment|/// @brief Manually set the address to return for the given symbol.
name|void
name|setGlobalMapping
argument_list|(
argument|const std::string&Name
argument_list|,
argument|JITTargetAddress Addr
argument_list|)
block|{
name|SymbolTable
index|[
name|Name
index|]
operator|=
name|Addr
block|;   }
comment|/// @brief Remove the given symbol from the global mapping.
name|void
name|eraseGlobalMapping
argument_list|(
argument|const std::string&Name
argument_list|)
block|{
name|SymbolTable
operator|.
name|erase
argument_list|(
name|Name
argument_list|)
block|;   }
comment|/// @brief Search for the given named symbol.
comment|///
comment|///          This method will first search the local symbol table, returning
comment|///        any symbol found there. If the symbol is not found in the local
comment|///        table then this call will be passed through to the base layer.
comment|///
comment|/// @param Name The name of the symbol to search for.
comment|/// @param ExportedSymbolsOnly If true, search only for exported symbols.
comment|/// @return A handle for the given named symbol, if it exists.
name|JITSymbol
name|findSymbol
argument_list|(
argument|const std::string&Name
argument_list|,
argument|bool ExportedSymbolsOnly
argument_list|)
block|{
name|auto
name|I
operator|=
name|SymbolTable
operator|.
name|find
argument_list|(
name|Name
argument_list|)
block|;
if|if
condition|(
name|I
operator|!=
name|SymbolTable
operator|.
name|end
argument_list|()
condition|)
return|return
name|JITSymbol
argument_list|(
name|I
operator|->
name|second
argument_list|,
name|JITSymbolFlags
operator|::
name|Exported
argument_list|)
return|;
return|return
name|BaseLayer
operator|.
name|findSymbol
argument_list|(
name|Name
argument_list|,
name|ExportedSymbolsOnly
argument_list|)
return|;
block|}
comment|/// @brief Get the address of the given symbol in the context of the set of
comment|///        modules represented by the handle H. This call is forwarded to the
comment|///        base layer's implementation.
comment|/// @param H The handle for the module set to search in.
comment|/// @param Name The name of the symbol to search for.
comment|/// @param ExportedSymbolsOnly If true, search only for exported symbols.
comment|/// @return A handle for the given named symbol, if it is found in the
comment|///         given module set.
name|JITSymbol
name|findSymbolIn
argument_list|(
name|ModuleSetHandleT
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
name|BaseLayer
operator|.
name|findSymbolIn
argument_list|(
name|H
argument_list|,
name|Name
argument_list|,
name|ExportedSymbolsOnly
argument_list|)
return|;
block|}
comment|/// @brief Immediately emit and finalize the module set represented by the
comment|///        given handle.
comment|/// @param H Handle for module set to emit/finalize.
name|void
name|emitAndFinalize
parameter_list|(
name|ModuleSetHandleT
name|H
parameter_list|)
block|{
name|BaseLayer
operator|.
name|emitAndFinalize
argument_list|(
name|H
argument_list|)
expr_stmt|;
block|}
name|private
label|:
name|BaseLayerT
modifier|&
name|BaseLayer
decl_stmt|;
name|std
operator|::
name|map
operator|<
name|std
operator|::
name|string
operator|,
name|JITTargetAddress
operator|>
name|SymbolTable
expr_stmt|;
block|}
empty_stmt|;
block|}
end_decl_stmt

begin_comment
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
comment|// LLVM_EXECUTIONENGINE_ORC_GLOBALMAPPINGLAYER_H
end_comment

end_unit

