begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- ObjectTransformLayer.h - Run all objects through functor -*- C++ -*-===//
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
comment|// Run all objects passed in through a user supplied functor.
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
name|LLVM_EXECUTIONENGINE_ORC_OBJECTTRANSFORMLAYER_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_EXECUTIONENGINE_ORC_OBJECTTRANSFORMLAYER_H
end_define

begin_include
include|#
directive|include
file|"JITSymbol.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|namespace
name|orc
block|{
comment|/// @brief Object mutating layer.
comment|///
comment|///   This layer accepts sets of ObjectFiles (via addObjectSet). It
comment|/// immediately applies the user supplied functor to each object, then adds
comment|/// the set of transformed objects to the layer below.
name|template
operator|<
name|typename
name|BaseLayerT
operator|,
name|typename
name|TransformFtor
operator|>
name|class
name|ObjectTransformLayer
block|{
name|public
operator|:
comment|/// @brief Handle to a set of added objects.
typedef|typedef
name|typename
name|BaseLayerT
operator|::
name|ObjSetHandleT
name|ObjSetHandleT
expr_stmt|;
comment|/// @brief Construct an ObjectTransformLayer with the given BaseLayer
name|ObjectTransformLayer
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
comment|/// @brief Apply the transform functor to each object in the object set, then
comment|///        add the resulting set of objects to the base layer, along with the
comment|///        memory manager and symbol resolver.
comment|///
comment|/// @return A handle for the added objects.
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
argument|ObjSetT&Objects
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
name|Objects
operator|.
name|begin
argument_list|()
init|,
name|E
init|=
name|Objects
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
name|addObjectSet
argument_list|(
name|Objects
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
comment|/// @brief Remove the object set associated with the handle H.
name|void
name|removeObjectSet
parameter_list|(
name|ObjSetHandleT
name|H
parameter_list|)
block|{
name|BaseLayer
operator|.
name|removeObjectSet
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
comment|///        objects represented by the handle H. This call is forwarded to the
comment|///        base layer's implementation.
comment|/// @param H The handle for the object set to search in.
comment|/// @param Name The name of the symbol to search for.
comment|/// @param ExportedSymbolsOnly If true, search only for exported symbols.
comment|/// @return A handle for the given named symbol, if it is found in the
comment|///         given object set.
name|JITSymbol
name|findSymbolIn
argument_list|(
name|ObjSetHandleT
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
comment|/// @brief Immediately emit and finalize the object set represented by the
comment|///        given handle.
comment|/// @param H Handle for object set to emit/finalize.
name|void
name|emitAndFinalize
parameter_list|(
name|ObjSetHandleT
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
comment|/// @brief Map section addresses for the objects associated with the handle H.
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
name|BaseLayer
operator|.
name|mapSectionAddress
argument_list|(
name|H
argument_list|,
name|LocalAddress
argument_list|,
name|TargetAddr
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
comment|// LLVM_EXECUTIONENGINE_ORC_OBJECTTRANSFORMLAYER_H
end_comment

end_unit

