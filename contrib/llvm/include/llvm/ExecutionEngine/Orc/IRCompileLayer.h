begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===------ IRCompileLayer.h -- Eagerly compile IR for JIT ------*- C++ -*-===//
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
comment|// Contains the definition for a basic, eagerly compiling layer of the JIT.
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
name|LLVM_EXECUTIONENGINE_ORC_IRCOMPILELAYER_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_EXECUTIONENGINE_ORC_IRCOMPILELAYER_H
end_define

begin_include
include|#
directive|include
file|"llvm/ExecutionEngine/JITSymbol.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ExecutionEngine/ObjectCache.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Object/ObjectFile.h"
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
comment|/// @brief Eager IR compiling layer.
comment|///
comment|///   This layer accepts sets of LLVM IR Modules (via addModuleSet). It
comment|/// immediately compiles each IR module to an object file (each IR Module is
comment|/// compiled separately). The resulting set of object files is then added to
comment|/// the layer below, which must implement the object layer concept.
name|template
operator|<
name|typename
name|BaseLayerT
operator|>
name|class
name|IRCompileLayer
block|{
name|public
operator|:
typedef|typedef
name|std
operator|::
name|function
operator|<
name|object
operator|::
name|OwningBinary
operator|<
name|object
operator|::
name|ObjectFile
operator|>
operator|(
name|Module
operator|&
operator|)
operator|>
name|CompileFtor
expr_stmt|;
name|private
operator|:
typedef|typedef
name|typename
name|BaseLayerT
operator|::
name|ObjSetHandleT
name|ObjSetHandleT
expr_stmt|;
name|public
label|:
comment|/// @brief Handle to a set of compiled modules.
typedef|typedef
name|ObjSetHandleT
name|ModuleSetHandleT
typedef|;
comment|/// @brief Construct an IRCompileLayer with the given BaseLayer, which must
comment|///        implement the ObjectLayer concept.
name|IRCompileLayer
argument_list|(
argument|BaseLayerT&BaseLayer
argument_list|,
argument|CompileFtor Compile
argument_list|)
block|:
name|BaseLayer
argument_list|(
name|BaseLayer
argument_list|)
operator|,
name|Compile
argument_list|(
name|std
operator|::
name|move
argument_list|(
name|Compile
argument_list|)
argument_list|)
operator|,
name|ObjCache
argument_list|(
argument|nullptr
argument_list|)
block|{}
comment|/// @brief Set an ObjectCache to query before compiling.
name|void
name|setObjectCache
argument_list|(
argument|ObjectCache *NewCache
argument_list|)
block|{
name|ObjCache
operator|=
name|NewCache
block|; }
comment|/// @brief Compile each module in the given module set, then add the resulting
comment|///        set of objects to the base layer along with the memory manager and
comment|///        symbol resolver.
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
name|std
operator|::
name|vector
operator|<
name|std
operator|::
name|unique_ptr
operator|<
name|object
operator|::
name|OwningBinary
operator|<
name|object
operator|::
name|ObjectFile
operator|>>>
name|Objects
block|;
for|for
control|(
specifier|const
specifier|auto
modifier|&
name|M
range|:
name|Ms
control|)
block|{
name|auto
name|Object
init|=
name|llvm
operator|::
name|make_unique
operator|<
name|object
operator|::
name|OwningBinary
operator|<
name|object
operator|::
name|ObjectFile
operator|>>
operator|(
operator|)
decl_stmt|;
if|if
condition|(
name|ObjCache
condition|)
operator|*
name|Object
operator|=
name|tryToLoadFromObjectCache
argument_list|(
operator|*
name|M
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|Object
operator|->
name|getBinary
argument_list|()
condition|)
block|{
operator|*
name|Object
operator|=
name|Compile
argument_list|(
operator|*
name|M
argument_list|)
expr_stmt|;
if|if
condition|(
name|ObjCache
condition|)
name|ObjCache
operator|->
name|notifyObjectCompiled
argument_list|(
operator|&
operator|*
name|M
argument_list|,
name|Object
operator|->
name|getBinary
argument_list|()
operator|->
name|getMemoryBufferRef
argument_list|()
argument_list|)
expr_stmt|;
block|}
name|Objects
operator|.
name|push_back
argument_list|(
name|std
operator|::
name|move
argument_list|(
name|Object
argument_list|)
argument_list|)
expr_stmt|;
block|}
name|ModuleSetHandleT
name|H
init|=
name|BaseLayer
operator|.
name|addObjectSet
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
argument_list|)
decl_stmt|;
return|return
name|H
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
comment|///        compiled modules represented by the handle H. This call is
comment|///        forwarded to the base layer's implementation.
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
comment|/// @brief Immediately emit and finalize the moduleOB set represented by the
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
name|object
operator|::
name|OwningBinary
operator|<
name|object
operator|::
name|ObjectFile
operator|>
name|tryToLoadFromObjectCache
argument_list|(
argument|const Module&M
argument_list|)
block|{
name|std
operator|::
name|unique_ptr
operator|<
name|MemoryBuffer
operator|>
name|ObjBuffer
operator|=
name|ObjCache
operator|->
name|getObject
argument_list|(
operator|&
name|M
argument_list|)
block|;
if|if
condition|(
operator|!
name|ObjBuffer
condition|)
return|return
name|object
operator|::
name|OwningBinary
operator|<
name|object
operator|::
name|ObjectFile
operator|>
operator|(
operator|)
return|;
name|Expected
operator|<
name|std
operator|::
name|unique_ptr
operator|<
name|object
operator|::
name|ObjectFile
operator|>>
name|Obj
operator|=
name|object
operator|::
name|ObjectFile
operator|::
name|createObjectFile
argument_list|(
name|ObjBuffer
operator|->
name|getMemBufferRef
argument_list|()
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|Obj
condition|)
block|{
comment|// TODO: Actually report errors helpfully.
name|consumeError
argument_list|(
name|Obj
operator|.
name|takeError
argument_list|()
argument_list|)
expr_stmt|;
return|return
name|object
operator|::
name|OwningBinary
operator|<
name|object
operator|::
name|ObjectFile
operator|>
operator|(
operator|)
return|;
block|}
return|return
name|object
operator|::
name|OwningBinary
operator|<
name|object
operator|::
name|ObjectFile
operator|>
operator|(
name|std
operator|::
name|move
argument_list|(
operator|*
name|Obj
argument_list|)
operator|,
name|std
operator|::
name|move
argument_list|(
name|ObjBuffer
argument_list|)
operator|)
return|;
block|}
end_decl_stmt

begin_decl_stmt
name|BaseLayerT
modifier|&
name|BaseLayer
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|CompileFtor
name|Compile
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|ObjectCache
modifier|*
name|ObjCache
decl_stmt|;
end_decl_stmt

begin_comment
unit|};  }
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
comment|// LLVM_EXECUTIONENGINE_ORC_IRCOMPILINGLAYER_H
end_comment

end_unit

