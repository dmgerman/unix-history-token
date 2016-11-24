begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-LTO.h - LLVM Link Time Optimizer ------------------------------------===//
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
comment|// This file declares functions and classes used to support LTO. It is intended
end_comment

begin_comment
comment|// to be used both by LTO classes as well as by clients (gold-plugin) that
end_comment

begin_comment
comment|// don't utilize the LTO code generator interfaces.
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
name|LLVM_LTO_LTO_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_LTO_LTO_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/StringMap.h"
end_include

begin_include
include|#
directive|include
file|"llvm/IR/ModuleSummaryIndex.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|LLVMContext
decl_stmt|;
name|class
name|MemoryBufferRef
decl_stmt|;
name|class
name|Module
decl_stmt|;
comment|/// Helper to load a module from bitcode.
name|std
operator|::
name|unique_ptr
operator|<
name|Module
operator|>
name|loadModuleFromBuffer
argument_list|(
argument|const MemoryBufferRef&Buffer
argument_list|,
argument|LLVMContext&Context
argument_list|,
argument|bool Lazy
argument_list|)
expr_stmt|;
comment|/// Provide a "loader" for the FunctionImporter to access function from other
comment|/// modules.
name|class
name|ModuleLoader
block|{
comment|/// The context that will be used for importing.
name|LLVMContext
modifier|&
name|Context
decl_stmt|;
comment|/// Map from Module identifier to MemoryBuffer. Used by clients like the
comment|/// FunctionImported to request loading a Module.
name|StringMap
operator|<
name|MemoryBufferRef
operator|>
operator|&
name|ModuleMap
expr_stmt|;
name|public
label|:
name|ModuleLoader
argument_list|(
name|LLVMContext
operator|&
name|Context
argument_list|,
name|StringMap
operator|<
name|MemoryBufferRef
operator|>
operator|&
name|ModuleMap
argument_list|)
operator|:
name|Context
argument_list|(
name|Context
argument_list|)
operator|,
name|ModuleMap
argument_list|(
argument|ModuleMap
argument_list|)
block|{}
comment|/// Load a module on demand.
name|std
operator|::
name|unique_ptr
operator|<
name|Module
operator|>
name|operator
argument_list|()
operator|(
name|StringRef
name|Identifier
operator|)
block|{
return|return
name|loadModuleFromBuffer
argument_list|(
name|ModuleMap
index|[
name|Identifier
index|]
argument_list|,
name|Context
argument_list|,
comment|/*Lazy*/
name|true
argument_list|)
return|;
block|}
block|}
empty_stmt|;
comment|/// Resolve Weak and LinkOnce values in the \p Index. Linkage changes recorded
comment|/// in the index and the ThinLTO backends must apply the changes to the Module
comment|/// via thinLTOResolveWeakForLinkerModule.
comment|///
comment|/// This is done for correctness (if value exported, ensure we always
comment|/// emit a copy), and compile-time optimization (allow drop of duplicates).
name|void
name|thinLTOResolveWeakForLinkerInIndex
argument_list|(
name|ModuleSummaryIndex
operator|&
name|Index
argument_list|,
name|function_ref
operator|<
name|bool
argument_list|(
name|GlobalValue
operator|::
name|GUID
argument_list|,
specifier|const
name|GlobalValueSummary
operator|*
argument_list|)
operator|>
name|isPrevailing
argument_list|,
name|function_ref
operator|<
name|void
argument_list|(
name|StringRef
argument_list|,
name|GlobalValue
operator|::
name|GUID
argument_list|,
name|GlobalValue
operator|::
name|LinkageTypes
argument_list|)
operator|>
name|recordNewLinkage
argument_list|)
decl_stmt|;
comment|/// Update the linkages in the given \p Index to mark exported values
comment|/// as external and non-exported values as internal. The ThinLTO backends
comment|/// must apply the changes to the Module via thinLTOInternalizeModule.
name|void
name|thinLTOInternalizeAndPromoteInIndex
argument_list|(
name|ModuleSummaryIndex
operator|&
name|Index
argument_list|,
name|function_ref
operator|<
name|bool
argument_list|(
name|StringRef
argument_list|,
name|GlobalValue
operator|::
name|GUID
argument_list|)
operator|>
name|isExported
argument_list|)
decl_stmt|;
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

