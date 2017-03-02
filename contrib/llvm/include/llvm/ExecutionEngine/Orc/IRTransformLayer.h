begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===----- IRTransformLayer.h - Run all IR through a functor ----*- C++ -*-===//
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

begin_decl_stmt
name|namespace
name|llvm
block|{
name|namespace
name|orc
block|{
comment|/// @brief IR mutating layer.
comment|///
comment|///   This layer accepts sets of LLVM IR Modules (via addModuleSet). It
comment|/// immediately applies the user supplied functor to each module, then adds
comment|/// the set of transformed modules to the layer below.
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
typedef|typedef
name|typename
name|BaseLayerT
operator|::
name|ModuleSetHandleT
name|ModuleSetHandleT
expr_stmt|;
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
operator|,
name|Transform
argument_list|(
argument|std::move(Transform)
argument_list|)
block|{}
comment|/// @brief Apply the transform functor to each module in the module set, then
comment|///        add the resulting set of modules to the base layer, along with the
comment|///        memory manager and symbol resolver.
comment|///
comment|/// @return A handle for the added modules.
name|template
operator|<
name|typename
name|ModuleSetT
operator|,
name|typename
name|MemoryManagerPtrT
operator|,
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
for|for
control|(
name|auto
name|I
init|=
name|Ms
operator|.
name|begin
argument_list|()
init|,
name|E
init|=
name|Ms
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
operator|*
name|I
operator|=
name|Transform
argument_list|(
name|std
operator|::
name|move
argument_list|(
operator|*
name|I
argument_list|)
argument_list|)
expr_stmt|;
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
parameter_list|(
name|ModuleSetHandleT
name|H
parameter_list|)
block|{
name|BaseLayer
operator|.
name|removeModuleSet
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
comment|/// @brief Access the transform functor directly.
name|TransformFtor
modifier|&
name|getTransform
parameter_list|()
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
label|:
name|BaseLayerT
modifier|&
name|BaseLayer
decl_stmt|;
name|TransformFtor
name|Transform
decl_stmt|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
unit|}
comment|// End namespace orc.
end_comment

begin_comment
unit|}
comment|// End namespace llvm.
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// LLVM_EXECUTIONENGINE_ORC_IRTRANSFORMLAYER_H
end_comment

end_unit

