begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===--- Frontend/PCHContainerOperations.h - PCH Containers -----*- C++ -*-===//
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
name|LLVM_CLANG_PCH_CONTAINER_OPERATIONS_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_PCH_CONTAINER_OPERATIONS_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/SmallVector.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/MemoryBuffer.h"
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
name|class
name|raw_pwrite_stream
decl_stmt|;
name|class
name|BitstreamReader
decl_stmt|;
block|}
end_decl_stmt

begin_decl_stmt
name|namespace
name|clang
block|{
name|class
name|ASTConsumer
decl_stmt|;
name|class
name|CodeGenOptions
decl_stmt|;
name|class
name|DiagnosticsEngine
decl_stmt|;
name|class
name|HeaderSearchOptions
decl_stmt|;
name|class
name|LangOptions
decl_stmt|;
name|class
name|PreprocessorOptions
decl_stmt|;
name|class
name|TargetOptions
decl_stmt|;
struct|struct
name|PCHBuffer
block|{
name|bool
name|IsComplete
decl_stmt|;
name|llvm
operator|::
name|SmallVector
operator|<
name|char
operator|,
literal|0
operator|>
name|Data
expr_stmt|;
block|}
struct|;
comment|/// \brief This abstract interface provides operations for creating
comment|/// and unwrapping containers for serialized ASTs (precompiled headers
comment|/// and clang modules).
name|class
name|PCHContainerOperations
block|{
name|public
label|:
name|virtual
operator|~
name|PCHContainerOperations
argument_list|()
expr_stmt|;
comment|/// \brief Return an ASTConsumer that can be chained with a
comment|/// PCHGenerator that produces a wrapper file format containing a
comment|/// serialized AST bitstream.
name|virtual
name|std
operator|::
name|unique_ptr
operator|<
name|ASTConsumer
operator|>
name|CreatePCHContainerGenerator
argument_list|(
argument|DiagnosticsEngine&Diags
argument_list|,
argument|const HeaderSearchOptions&HSO
argument_list|,
argument|const PreprocessorOptions&PPO
argument_list|,
argument|const TargetOptions&TO
argument_list|,
argument|const LangOptions&LO
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
operator|=
literal|0
expr_stmt|;
comment|/// \brief Initialize an llvm::BitstreamReader with the serialized AST inside
comment|/// the PCH container Buffer.
name|virtual
name|void
name|ExtractPCH
argument_list|(
name|llvm
operator|::
name|MemoryBufferRef
name|Buffer
argument_list|,
name|llvm
operator|::
name|BitstreamReader
operator|&
name|StreamFile
argument_list|)
decl|const
init|=
literal|0
decl_stmt|;
block|}
empty_stmt|;
comment|/// \brief Implements a raw pass-through PCH container.
name|class
name|RawPCHContainerOperations
range|:
name|public
name|PCHContainerOperations
block|{
comment|/// \brief Return an ASTConsumer that can be chained with a
comment|/// PCHGenerator that writes the module to a flat file.
name|std
operator|::
name|unique_ptr
operator|<
name|ASTConsumer
operator|>
name|CreatePCHContainerGenerator
argument_list|(
argument|DiagnosticsEngine&Diags
argument_list|,
argument|const HeaderSearchOptions&HSO
argument_list|,
argument|const PreprocessorOptions&PPO
argument_list|,
argument|const TargetOptions&TO
argument_list|,
argument|const LangOptions&LO
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
block|;
comment|/// \brief Initialize an llvm::BitstreamReader with Buffer.
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

