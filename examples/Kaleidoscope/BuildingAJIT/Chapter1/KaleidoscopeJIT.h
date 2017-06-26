begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- KaleidoscopeJIT.h - A simple JIT for Kaleidoscope --------*- C++ -*-===//
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
file|"llvm/ExecutionEngine/JITSymbol.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ExecutionEngine/RTDyldMemoryManager.h"
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
file|"llvm/ExecutionEngine/Orc/IRCompileLayer.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ExecutionEngine/Orc/LambdaResolver.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ExecutionEngine/Orc/RTDyldObjectLinkingLayer.h"
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
name|RTDyldObjectLinkingLayer
name|ObjectLayer
decl_stmt|;
name|IRCompileLayer
operator|<
name|decltype
argument_list|(
name|ObjectLayer
argument_list|)
operator|,
name|SimpleCompiler
operator|>
name|CompileLayer
expr_stmt|;
name|public
label|:
name|using
name|ModuleHandle
init|=
name|decltype
argument_list|(
name|CompileLayer
argument_list|)
operator|::
name|ModuleHandleT
decl_stmt|;
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
argument|ObjectLayer
argument_list|,
argument|SimpleCompiler(*TM)
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
name|CompileLayer
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
return|;
return|return
name|JITSymbol
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
name|JITSymbol
argument_list|(
name|SymAddr
argument_list|,
name|JITSymbolFlags
operator|::
name|Exported
argument_list|)
return|;
return|return
name|JITSymbol
argument_list|(
name|nullptr
argument_list|)
return|;
block|}
block|)
decl_stmt|;
comment|// Add the set to the JIT with the resolver we created above and a newly
comment|// created SectionMemoryManager.
return|return
name|CompileLayer
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
name|CompileLayer
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
name|CompileLayer
operator|.
name|removeModule
argument_list|(
name|H
argument_list|)
expr_stmt|;
block|}
end_function

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
comment|// LLVM_EXECUTIONENGINE_ORC_KALEIDOSCOPEJIT_H
end_comment

end_unit

