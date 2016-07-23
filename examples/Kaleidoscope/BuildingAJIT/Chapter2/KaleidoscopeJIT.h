begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===----- KaleidoscopeJIT.h - A simple JIT for Kaleidoscope ----*- C++ -*-===//
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
comment|// Contains a simple JIT definition for use in the kaleidoscope tutorials.
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
name|LLVM_EXECUTIONENGINE_ORC_KALEIDOSCOPEJIT_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_EXECUTIONENGINE_ORC_KALEIDOSCOPEJIT_H
end_define

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
file|"llvm/ExecutionEngine/Orc/CompileUtils.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ExecutionEngine/Orc/JITSymbol.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ExecutionEngine/Orc/IRCompileLayer.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ExecutionEngine/Orc/IRTransformLayer.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ExecutionEngine/Orc/LambdaResolver.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ExecutionEngine/Orc/ObjectLinkingLayer.h"
end_include

begin_include
include|#
directive|include
file|"llvm/IR/DataLayout.h"
end_include

begin_include
include|#
directive|include
file|"llvm/IR/Mangler.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/DynamicLibrary.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/raw_ostream.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Target/TargetMachine.h"
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
name|KaleidoscopeJIT
block|{
name|private
label|:
name|std
operator|::
name|unique_ptr
operator|<
name|TargetMachine
operator|>
name|TM
expr_stmt|;
specifier|const
name|DataLayout
name|DL
decl_stmt|;
name|ObjectLinkingLayer
operator|<
operator|>
name|ObjectLayer
expr_stmt|;
name|IRCompileLayer
operator|<
name|decltype
argument_list|(
name|ObjectLayer
argument_list|)
operator|>
name|CompileLayer
expr_stmt|;
typedef|typedef
name|std
operator|::
name|function
operator|<
name|std
operator|::
name|unique_ptr
operator|<
name|Module
operator|>
operator|(
name|std
operator|::
name|unique_ptr
operator|<
name|Module
operator|>
operator|)
operator|>
name|OptimizeFunction
expr_stmt|;
name|IRTransformLayer
operator|<
name|decltype
argument_list|(
name|CompileLayer
argument_list|)
operator|,
name|OptimizeFunction
operator|>
name|OptimizeLayer
expr_stmt|;
name|public
label|:
typedef|typedef
name|decltype
argument_list|(
name|OptimizeLayer
argument_list|)
operator|::
name|ModuleSetHandleT
name|ModuleHandle
expr_stmt|;
name|KaleidoscopeJIT
argument_list|()
operator|:
name|TM
argument_list|(
name|EngineBuilder
argument_list|()
operator|.
name|selectTarget
argument_list|()
argument_list|)
operator|,
name|DL
argument_list|(
name|TM
operator|->
name|createDataLayout
argument_list|()
argument_list|)
operator|,
name|CompileLayer
argument_list|(
name|ObjectLayer
argument_list|,
name|SimpleCompiler
argument_list|(
operator|*
name|TM
argument_list|)
argument_list|)
operator|,
name|OptimizeLayer
argument_list|(
argument|CompileLayer
argument_list|,
argument|[this](std::unique_ptr<Module> M) {                         return optimizeModule(std::move(M));                       }
argument_list|)
block|{
name|llvm
operator|::
name|sys
operator|::
name|DynamicLibrary
operator|::
name|LoadLibraryPermanently
argument_list|(
name|nullptr
argument_list|)
block|;   }
name|TargetMachine
operator|&
name|getTargetMachine
argument_list|()
block|{
return|return
operator|*
name|TM
return|;
block|}
name|ModuleHandle
name|addModule
argument_list|(
name|std
operator|::
name|unique_ptr
operator|<
name|Module
operator|>
name|M
argument_list|)
block|{
comment|// Build our symbol resolver:
comment|// Lambda 1: Look back into the JIT itself to find symbols that are part of
comment|//           the same "logical dylib".
comment|// Lambda 2: Search for external symbols in the host process.
name|auto
name|Resolver
init|=
name|createLambdaResolver
argument_list|(
index|[
operator|&
index|]
operator|(
specifier|const
name|std
operator|::
name|string
operator|&
name|Name
operator|)
block|{
if|if
condition|(
name|auto
name|Sym
init|=
name|OptimizeLayer
operator|.
name|findSymbol
argument_list|(
name|Name
argument_list|,
name|false
argument_list|)
condition|)
return|return
name|Sym
operator|.
name|toRuntimeDyldSymbol
argument_list|()
return|;
return|return
name|RuntimeDyld
operator|::
name|SymbolInfo
argument_list|(
name|nullptr
argument_list|)
return|;
block|}
operator|,
index|[]
operator|(
specifier|const
name|std
operator|::
name|string
operator|&
name|Name
operator|)
block|{
if|if
condition|(
name|auto
name|SymAddr
init|=
name|RTDyldMemoryManager
operator|::
name|getSymbolAddressInProcess
argument_list|(
name|Name
argument_list|)
condition|)
return|return
name|RuntimeDyld
operator|::
name|SymbolInfo
argument_list|(
name|SymAddr
argument_list|,
name|JITSymbolFlags
operator|::
name|Exported
argument_list|)
return|;
return|return
name|RuntimeDyld
operator|::
name|SymbolInfo
argument_list|(
name|nullptr
argument_list|)
return|;
block|}
block|)
decl_stmt|;
comment|// Build a singlton module set to hold our module.
name|std
operator|::
name|vector
operator|<
name|std
operator|::
name|unique_ptr
operator|<
name|Module
operator|>>
name|Ms
expr_stmt|;
name|Ms
operator|.
name|push_back
argument_list|(
name|std
operator|::
name|move
argument_list|(
name|M
argument_list|)
argument_list|)
expr_stmt|;
comment|// Add the set to the JIT with the resolver we created above and a newly
comment|// created SectionMemoryManager.
return|return
name|OptimizeLayer
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
name|make_unique
operator|<
name|SectionMemoryManager
operator|>
operator|(
operator|)
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
end_decl_stmt

begin_decl_stmt
name|JITSymbol
name|findSymbol
argument_list|(
specifier|const
name|std
operator|::
name|string
name|Name
argument_list|)
block|{
name|std
operator|::
name|string
name|MangledName
expr_stmt|;
name|raw_string_ostream
name|MangledNameStream
parameter_list|(
name|MangledName
parameter_list|)
function_decl|;
name|Mangler
operator|::
name|getNameWithPrefix
argument_list|(
name|MangledNameStream
argument_list|,
name|Name
argument_list|,
name|DL
argument_list|)
expr_stmt|;
return|return
name|OptimizeLayer
operator|.
name|findSymbol
argument_list|(
name|MangledNameStream
operator|.
name|str
argument_list|()
argument_list|,
name|true
argument_list|)
return|;
block|}
end_decl_stmt

begin_function
name|void
name|removeModule
parameter_list|(
name|ModuleHandle
name|H
parameter_list|)
block|{
name|OptimizeLayer
operator|.
name|removeModuleSet
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

begin_expr_stmt
name|std
operator|::
name|unique_ptr
operator|<
name|Module
operator|>
name|optimizeModule
argument_list|(
argument|std::unique_ptr<Module> M
argument_list|)
block|{
comment|// Create a function pass manager.
name|auto
name|FPM
operator|=
name|llvm
operator|::
name|make_unique
operator|<
name|legacy
operator|::
name|FunctionPassManager
operator|>
operator|(
name|M
operator|.
name|get
argument_list|()
operator|)
block|;
comment|// Add some optimizations.
name|FPM
operator|->
name|add
argument_list|(
name|createInstructionCombiningPass
argument_list|()
argument_list|)
block|;
name|FPM
operator|->
name|add
argument_list|(
name|createReassociatePass
argument_list|()
argument_list|)
block|;
name|FPM
operator|->
name|add
argument_list|(
name|createGVNPass
argument_list|()
argument_list|)
block|;
name|FPM
operator|->
name|add
argument_list|(
name|createCFGSimplificationPass
argument_list|()
argument_list|)
block|;
name|FPM
operator|->
name|doInitialization
argument_list|()
block|;
comment|// Run the optimizations over all functions in the module being added to
comment|// the JIT.
for|for
control|(
name|auto
operator|&
name|F
operator|:
operator|*
name|M
control|)
name|FPM
operator|->
name|run
argument_list|(
name|F
argument_list|)
expr_stmt|;
end_expr_stmt

begin_return
return|return
name|M
return|;
end_return

begin_empty_stmt
unit|}  }
empty_stmt|;
end_empty_stmt

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
comment|// LLVM_EXECUTIONENGINE_ORC_KALEIDOSCOPEJIT_H
end_comment

end_unit

