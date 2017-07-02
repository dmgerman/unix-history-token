begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- IRTransformLayer.h - Run all IR through a functor --------*- C++ -*-===//
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
comment|// Run all IR passed in through a user supplied functor.
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
name|LLVM_EXECUTIONENGINE_ORC_IRTRANSFORMLAYER_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_EXECUTIONENGINE_ORC_IRTRANSFORMLAYER_H
end_define

begin_include
include|#
directive|include
file|"llvm/ExecutionEngine/JITSymbol.h"
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
name|class
name|Module
decl_stmt|;
name|namespace
name|orc
block|{
comment|/// @brief IR mutating layer.
comment|///
comment|///   This layer applies a user supplied transform to each module that is added,
comment|/// then adds the transformed module to the layer below.
name|template
operator|<
name|typename
name|BaseLayerT
operator|,
name|typename
name|TransformFtor
operator|>
name|class
name|IRTransformLayer
block|{
name|public
operator|:
comment|/// @brief Handle to a set of added modules.
name|using
name|ModuleHandleT
operator|=
name|typename
name|BaseLayerT
operator|::
name|ModuleHandleT
block|;
comment|/// @brief Construct an IRTransformLayer with the given BaseLayer
name|IRTransformLayer
argument_list|(
argument|BaseLayerT&BaseLayer
argument_list|,
argument|TransformFtor Transform = TransformFtor()
argument_list|)
operator|:
name|BaseLayer
argument_list|(
name|BaseLayer
argument_list|)
block|,
name|Transform
argument_list|(
argument|std::move(Transform)
argument_list|)
block|{}
comment|/// @brief Apply the transform functor to the module, then add the module to
comment|///        the layer below, along with the memory manager and symbol resolver.
comment|///
comment|/// @return A handle for the added modules.
name|template
operator|<
name|typename
name|MemoryManagerPtrT
block|,
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
name|BaseLayer
operator|.
name|addModule
argument_list|(
name|Transform
argument_list|(
name|std
operator|::
name|move
argument_list|(
name|M
argument_list|)
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
comment|/// @brief Remove the module associated with the handle H.
name|void
name|removeModule
argument_list|(
argument|ModuleHandleT H
argument_list|)
block|{
name|BaseLayer
operator|.
name|removeModule
argument_list|(
name|H
argument_list|)
block|; }
comment|/// @brief Search for the given named symbol.
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
comment|/// @brief Get the address of the given symbol in the context of the module
comment|///        represented by the handle H. This call is forwarded to the base
comment|///        layer's implementation.
comment|/// @param H The handle for the module to search in.
comment|/// @param Name The name of the symbol to search for.
comment|/// @param ExportedSymbolsOnly If true, search only for exported symbols.
comment|/// @return A handle for the given named symbol, if it is found in the
comment|///         given module.
name|JITSymbol
name|findSymbolIn
argument_list|(
argument|ModuleHandleT H
argument_list|,
argument|const std::string&Name
argument_list|,
argument|bool ExportedSymbolsOnly
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
comment|/// @brief Immediately emit and finalize the module represented by the given
comment|///        handle.
comment|/// @param H Handle for module to emit/finalize.
name|void
name|emitAndFinalize
argument_list|(
argument|ModuleHandleT H
argument_list|)
block|{
name|BaseLayer
operator|.
name|emitAndFinalize
argument_list|(
name|H
argument_list|)
block|;   }
comment|/// @brief Access the transform functor directly.
name|TransformFtor
operator|&
name|getTransform
argument_list|()
block|{
return|return
name|Transform
return|;
block|}
comment|/// @brief Access the mumate functor directly.
specifier|const
name|TransformFtor
operator|&
name|getTransform
argument_list|()
specifier|const
block|{
return|return
name|Transform
return|;
block|}
name|private
operator|:
name|BaseLayerT
operator|&
name|BaseLayer
block|;
name|TransformFtor
name|Transform
block|; }
expr_stmt|;
block|}
comment|// end namespace orc
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
comment|// LLVM_EXECUTIONENGINE_ORC_IRTRANSFORMLAYER_H
end_comment

end_unit

