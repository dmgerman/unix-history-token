begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- IRCompileLayer.h -- Eagerly compile IR for JIT -----------*- C++ -*-===//
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
file|"llvm/ADT/STLExtras.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ExecutionEngine/JITSymbol.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/Error.h"
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
comment|/// @brief Eager IR compiling layer.
comment|///
comment|///   This layer immediately compiles each IR module added via addModule to an
comment|/// object file and adds this module file to the layer below, which must
comment|/// implement the object layer concept.
name|template
operator|<
name|typename
name|BaseLayerT
operator|,
name|typename
name|CompileFtor
operator|>
name|class
name|IRCompileLayer
block|{
name|public
operator|:
comment|/// @brief Handle to a compiled module.
name|using
name|ModuleHandleT
operator|=
name|typename
name|BaseLayerT
operator|::
name|ObjHandleT
block|;
comment|/// @brief Construct an IRCompileLayer with the given BaseLayer, which must
comment|///        implement the ObjectLayer concept.
name|IRCompileLayer
argument_list|(
argument|BaseLayerT&BaseLayer
argument_list|,
argument|CompileFtor Compile
argument_list|)
operator|:
name|BaseLayer
argument_list|(
name|BaseLayer
argument_list|)
block|,
name|Compile
argument_list|(
argument|std::move(Compile)
argument_list|)
block|{}
comment|/// @brief Get a reference to the compiler functor.
name|CompileFtor
operator|&
name|getCompiler
argument_list|()
block|{
return|return
name|Compile
return|;
block|}
comment|/// @brief Compile the module, and add the resulting object to the base layer
comment|///        along with the given memory manager and symbol resolver.
comment|///
comment|/// @return A handle for the added module.
name|Expected
operator|<
name|ModuleHandleT
operator|>
name|addModule
argument_list|(
argument|std::shared_ptr<Module> M
argument_list|,
argument|std::shared_ptr<JITSymbolResolver> Resolver
argument_list|)
block|{
name|using
name|CompileResult
operator|=
name|decltype
argument_list|(
name|Compile
argument_list|(
operator|*
name|M
argument_list|)
argument_list|)
block|;
name|auto
name|Obj
operator|=
name|std
operator|::
name|make_shared
operator|<
name|CompileResult
operator|>
operator|(
name|Compile
argument_list|(
operator|*
name|M
argument_list|)
operator|)
block|;
return|return
name|BaseLayer
operator|.
name|addObject
argument_list|(
name|std
operator|::
name|move
argument_list|(
name|Obj
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
name|Error
name|removeModule
argument_list|(
argument|ModuleHandleT H
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
comment|/// @brief Get the address of the given symbol in compiled module represented
comment|///        by the handle H. This call is forwarded to the base layer's
comment|///        implementation.
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
name|Error
name|emitAndFinalize
argument_list|(
argument|ModuleHandleT H
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
name|private
operator|:
name|BaseLayerT
operator|&
name|BaseLayer
block|;
name|CompileFtor
name|Compile
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
comment|// LLVM_EXECUTIONENGINE_ORC_IRCOMPILINGLAYER_H
end_comment

end_unit

