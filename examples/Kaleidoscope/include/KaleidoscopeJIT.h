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
file|"llvm/ADT/iterator_range.h"
end_include

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
name|public
label|:
name|using
name|ObjLayerT
init|=
name|RTDyldObjectLinkingLayer
decl_stmt|;
name|using
name|CompileLayerT
init|=
name|IRCompileLayer
operator|<
name|ObjLayerT
decl_stmt|,
name|SimpleCompiler
decl|>
decl_stmt|;
name|using
name|ModuleHandleT
init|=
name|CompileLayerT
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
name|ObjectLayer
argument_list|(
index|[]
operator|(
operator|)
block|{
return|return
name|std
operator|::
name|make_shared
operator|<
name|SectionMemoryManager
operator|>
operator|(
operator|)
return|;
block|}
block|)
decl_stmt|,
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
expr_stmt|;
block|}
name|TargetMachine
modifier|&
name|getTargetMachine
parameter_list|()
block|{
return|return
operator|*
name|TM
return|;
block|}
name|ModuleHandleT
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
comment|// We need a memory manager to allocate memory and resolve symbols for this
comment|// new module. Create one that resolves symbols by looking back into the
comment|// JIT.
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
name|findMangledSymbol
argument_list|(
name|Name
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
name|S
operator|)
block|{
return|return
name|nullptr
return|;
block|}
block|)
decl_stmt|;
name|auto
name|H
init|=
name|cantFail
argument_list|(
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
name|std
operator|::
name|move
argument_list|(
name|Resolver
argument_list|)
argument_list|)
argument_list|)
decl_stmt|;
name|ModuleHandles
operator|.
name|push_back
argument_list|(
name|H
argument_list|)
expr_stmt|;
return|return
name|H
return|;
block|}
end_decl_stmt

begin_function
name|void
name|removeModule
parameter_list|(
name|ModuleHandleT
name|H
parameter_list|)
block|{
name|ModuleHandles
operator|.
name|erase
argument_list|(
name|find
argument_list|(
name|ModuleHandles
argument_list|,
name|H
argument_list|)
argument_list|)
expr_stmt|;
name|cantFail
argument_list|(
name|CompileLayer
operator|.
name|removeModule
argument_list|(
name|H
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function

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
return|return
name|findMangledSymbol
argument_list|(
name|mangle
argument_list|(
name|Name
argument_list|)
argument_list|)
return|;
block|}
end_decl_stmt

begin_label
name|private
label|:
end_label

begin_expr_stmt
name|std
operator|::
name|string
name|mangle
argument_list|(
argument|const std::string&Name
argument_list|)
block|{
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
block|;     }
return|return
name|MangledName
return|;
block|}
end_expr_stmt

begin_decl_stmt
name|JITSymbol
name|findMangledSymbol
argument_list|(
specifier|const
name|std
operator|::
name|string
operator|&
name|Name
argument_list|)
block|{
ifdef|#
directive|ifdef
name|LLVM_ON_WIN32
comment|// The symbol lookup of ObjectLinkingLayer uses the SymbolRef::SF_Exported
comment|// flag to decide whether a symbol will be visible or not, when we call
comment|// IRCompileLayer::findSymbolIn with ExportedSymbolsOnly set to true.
comment|//
comment|// But for Windows COFF objects, this flag is currently never set.
comment|// For a potential solution see: https://reviews.llvm.org/rL258665
comment|// For now, we allow non-exported symbols on Windows as a workaround.
specifier|const
name|bool
name|ExportedSymbolsOnly
init|=
name|false
decl_stmt|;
else|#
directive|else
specifier|const
name|bool
name|ExportedSymbolsOnly
init|=
name|true
decl_stmt|;
endif|#
directive|endif
comment|// Search modules in reverse order: from last added to first added.
comment|// This is the opposite of the usual search order for dlsym, but makes more
comment|// sense in a REPL where we want to bind to the newest available definition.
for|for
control|(
name|auto
name|H
range|:
name|make_range
argument_list|(
name|ModuleHandles
operator|.
name|rbegin
argument_list|()
argument_list|,
name|ModuleHandles
operator|.
name|rend
argument_list|()
argument_list|)
control|)
if|if
condition|(
name|auto
name|Sym
init|=
name|CompileLayer
operator|.
name|findSymbolIn
argument_list|(
name|H
argument_list|,
name|Name
argument_list|,
name|ExportedSymbolsOnly
argument_list|)
condition|)
return|return
name|Sym
return|;
comment|// If we can't find the symbol in the JIT, try looking in the host process.
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
ifdef|#
directive|ifdef
name|LLVM_ON_WIN32
comment|// For Windows retry without "_" at beginning, as RTDyldMemoryManager uses
comment|// GetProcAddress and standard libraries like msvcrt.dll use names
comment|// with and without "_" (for example "_itoa" but "sin").
if|if
condition|(
name|Name
operator|.
name|length
argument_list|()
operator|>
literal|2
operator|&&
name|Name
index|[
literal|0
index|]
operator|==
literal|'_'
condition|)
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
operator|.
name|substr
argument_list|(
literal|1
argument_list|)
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
endif|#
directive|endif
return|return
name|nullptr
return|;
block|}
end_decl_stmt

begin_expr_stmt
name|std
operator|::
name|unique_ptr
operator|<
name|TargetMachine
operator|>
name|TM
expr_stmt|;
end_expr_stmt

begin_decl_stmt
specifier|const
name|DataLayout
name|DL
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|ObjLayerT
name|ObjectLayer
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|CompileLayerT
name|CompileLayer
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|std
operator|::
name|vector
operator|<
name|ModuleHandleT
operator|>
name|ModuleHandles
expr_stmt|;
end_expr_stmt

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

