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
file|"llvm/ExecutionEngine/JITSymbol.h"
end_include

begin_include
include|#
directive|include
file|<algorithm>
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
comment|/// @brief Object mutating layer.
comment|///
comment|///   This layer accepts sets of ObjectFiles (via addObject). It
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
name|using
name|ObjHandleT
operator|=
name|typename
name|BaseLayerT
operator|::
name|ObjHandleT
block|;
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
block|,
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
name|ObjectPtr
operator|>
name|Expected
operator|<
name|ObjHandleT
operator|>
name|addObject
argument_list|(
argument|ObjectPtr Obj
argument_list|,
argument|std::shared_ptr<JITSymbolResolver> Resolver
argument_list|)
block|{
return|return
name|BaseLayer
operator|.
name|addObject
argument_list|(
name|Transform
argument_list|(
name|std
operator|::
name|move
argument_list|(
name|Obj
argument_list|)
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
name|Error
name|removeObject
argument_list|(
argument|ObjHandleT H
argument_list|)
block|{
return|return
name|BaseLayer
operator|.
name|removeObject
argument_list|(
name|H
argument_list|)
return|;
block|}
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
argument|ObjHandleT H
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
comment|/// @brief Immediately emit and finalize the object set represented by the
comment|///        given handle.
comment|/// @param H Handle for object set to emit/finalize.
name|Error
name|emitAndFinalize
argument_list|(
argument|ObjHandleT H
argument_list|)
block|{
return|return
name|BaseLayer
operator|.
name|emitAndFinalize
argument_list|(
name|H
argument_list|)
return|;
block|}
comment|/// @brief Map section addresses for the objects associated with the handle H.
name|void
name|mapSectionAddress
argument_list|(
argument|ObjHandleT H
argument_list|,
argument|const void *LocalAddress
argument_list|,
argument|JITTargetAddress TargetAddr
argument_list|)
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
comment|// LLVM_EXECUTIONENGINE_ORC_OBJECTTRANSFORMLAYER_H
end_comment

end_unit

