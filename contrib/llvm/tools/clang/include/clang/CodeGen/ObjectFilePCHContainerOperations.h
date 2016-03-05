begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- CodeGen/ObjectFilePCHContainerOperations.h - ------------*- C++ -*-===//
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

begin_ifndef
ifndef|#
directive|ifndef
name|LLVM_CLANG_CODEGEN_OBJECT_FILE_PCH_CONTAINER_OPERATIONS_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_CODEGEN_OBJECT_FILE_PCH_CONTAINER_OPERATIONS_H
end_define

begin_include
include|#
directive|include
file|"clang/Frontend/PCHContainerOperations.h"
end_include

begin_decl_stmt
name|namespace
name|clang
block|{
comment|/// A PCHContainerWriter implementation that uses LLVM to
comment|/// wraps Clang modules inside a COFF, ELF, or Mach-O container.
name|class
name|ObjectFilePCHContainerWriter
range|:
name|public
name|PCHContainerWriter
block|{
name|StringRef
name|getFormat
argument_list|()
specifier|const
name|override
block|{
return|return
literal|"obj"
return|;
block|}
comment|/// Return an ASTConsumer that can be chained with a
comment|/// PCHGenerator that produces a wrapper file format
comment|/// that also contains full debug info for the module.
name|std
operator|::
name|unique_ptr
operator|<
name|ASTConsumer
operator|>
name|CreatePCHContainerGenerator
argument_list|(
argument|CompilerInstance&CI
argument_list|,
argument|const std::string&MainFileName
argument_list|,
argument|const std::string&OutputFileName
argument_list|,
argument|llvm::raw_pwrite_stream *OS
argument_list|,
argument|std::shared_ptr<PCHBuffer> Buffer
argument_list|)
specifier|const
name|override
block|; }
decl_stmt|;
comment|/// A PCHContainerReader implementation that uses LLVM to
comment|/// wraps Clang modules inside a COFF, ELF, or Mach-O container.
name|class
name|ObjectFilePCHContainerReader
range|:
name|public
name|PCHContainerReader
block|{
name|StringRef
name|getFormat
argument_list|()
specifier|const
name|override
block|{
return|return
literal|"obj"
return|;
block|}
comment|/// Initialize an llvm::BitstreamReader with the serialized
comment|/// AST inside the PCH container Buffer.
name|void
name|ExtractPCH
argument_list|(
argument|llvm::MemoryBufferRef Buffer
argument_list|,
argument|llvm::BitstreamReader&StreamFile
argument_list|)
specifier|const
name|override
block|; }
decl_stmt|;
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

