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
file|"clang/Basic/Module.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/SmallVector.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/StringMap.h"
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
block|}
end_decl_stmt

begin_expr_stmt
name|using
name|llvm
operator|::
name|StringRef
expr_stmt|;
end_expr_stmt

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
name|CompilerInstance
decl_stmt|;
struct|struct
name|PCHBuffer
block|{
name|ASTFileSignature
name|Signature
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
name|bool
name|IsComplete
decl_stmt|;
block|}
struct|;
comment|/// This abstract interface provides operations for creating
comment|/// containers for serialized ASTs (precompiled headers and clang
comment|/// modules).
name|class
name|PCHContainerWriter
block|{
name|public
label|:
name|virtual
operator|~
name|PCHContainerWriter
argument_list|()
operator|=
literal|0
expr_stmt|;
name|virtual
name|StringRef
name|getFormat
argument_list|()
specifier|const
operator|=
literal|0
expr_stmt|;
comment|/// Return an ASTConsumer that can be chained with a
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
argument|CompilerInstance&CI
argument_list|,
argument|const std::string&MainFileName
argument_list|,
argument|const std::string&OutputFileName
argument_list|,
argument|std::unique_ptr<llvm::raw_pwrite_stream> OS
argument_list|,
argument|std::shared_ptr<PCHBuffer> Buffer
argument_list|)
specifier|const
operator|=
literal|0
expr_stmt|;
block|}
empty_stmt|;
comment|/// This abstract interface provides operations for unwrapping
comment|/// containers for serialized ASTs (precompiled headers and clang
comment|/// modules).
name|class
name|PCHContainerReader
block|{
name|public
label|:
name|virtual
operator|~
name|PCHContainerReader
argument_list|()
operator|=
literal|0
expr_stmt|;
comment|/// Equivalent to the format passed to -fmodule-format=
name|virtual
name|StringRef
name|getFormat
argument_list|()
specifier|const
operator|=
literal|0
expr_stmt|;
comment|/// Returns the serialized AST inside the PCH container Buffer.
name|virtual
name|StringRef
name|ExtractPCH
argument_list|(
name|llvm
operator|::
name|MemoryBufferRef
name|Buffer
argument_list|)
decl|const
init|=
literal|0
decl_stmt|;
block|}
empty_stmt|;
comment|/// Implements write operations for a raw pass-through PCH container.
name|class
name|RawPCHContainerWriter
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
literal|"raw"
return|;
block|}
comment|/// Return an ASTConsumer that can be chained with a
comment|/// PCHGenerator that writes the module to a flat file.
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
argument|std::unique_ptr<llvm::raw_pwrite_stream> OS
argument_list|,
argument|std::shared_ptr<PCHBuffer> Buffer
argument_list|)
specifier|const
name|override
block|; }
decl_stmt|;
comment|/// Implements read operations for a raw pass-through PCH container.
name|class
name|RawPCHContainerReader
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
literal|"raw"
return|;
block|}
comment|/// Simply returns the buffer contained in Buffer.
name|StringRef
name|ExtractPCH
argument_list|(
argument|llvm::MemoryBufferRef Buffer
argument_list|)
specifier|const
name|override
block|; }
decl_stmt|;
comment|/// A registry of PCHContainerWriter and -Reader objects for different formats.
name|class
name|PCHContainerOperations
block|{
name|llvm
operator|::
name|StringMap
operator|<
name|std
operator|::
name|unique_ptr
operator|<
name|PCHContainerWriter
operator|>>
name|Writers
expr_stmt|;
name|llvm
operator|::
name|StringMap
operator|<
name|std
operator|::
name|unique_ptr
operator|<
name|PCHContainerReader
operator|>>
name|Readers
expr_stmt|;
name|public
label|:
comment|/// Automatically registers a RawPCHContainerWriter and
comment|/// RawPCHContainerReader.
name|PCHContainerOperations
argument_list|()
expr_stmt|;
name|void
name|registerWriter
argument_list|(
name|std
operator|::
name|unique_ptr
operator|<
name|PCHContainerWriter
operator|>
name|Writer
argument_list|)
block|{
name|Writers
index|[
name|Writer
operator|->
name|getFormat
argument_list|()
index|]
operator|=
name|std
operator|::
name|move
argument_list|(
name|Writer
argument_list|)
expr_stmt|;
block|}
name|void
name|registerReader
argument_list|(
name|std
operator|::
name|unique_ptr
operator|<
name|PCHContainerReader
operator|>
name|Reader
argument_list|)
block|{
name|Readers
index|[
name|Reader
operator|->
name|getFormat
argument_list|()
index|]
operator|=
name|std
operator|::
name|move
argument_list|(
name|Reader
argument_list|)
expr_stmt|;
block|}
specifier|const
name|PCHContainerWriter
modifier|*
name|getWriterOrNull
parameter_list|(
name|StringRef
name|Format
parameter_list|)
block|{
return|return
name|Writers
index|[
name|Format
index|]
operator|.
name|get
argument_list|()
return|;
block|}
specifier|const
name|PCHContainerReader
modifier|*
name|getReaderOrNull
parameter_list|(
name|StringRef
name|Format
parameter_list|)
block|{
return|return
name|Readers
index|[
name|Format
index|]
operator|.
name|get
argument_list|()
return|;
block|}
specifier|const
name|PCHContainerReader
modifier|&
name|getRawReader
parameter_list|()
block|{
return|return
operator|*
name|getReaderOrNull
argument_list|(
literal|"raw"
argument_list|)
return|;
block|}
block|}
empty_stmt|;
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

