begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- lld/ReaderWriter/YamlContext.h - object used in YAML I/O context ---===//
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//                             The LLVM Linker
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
name|LLD_READER_WRITER_YAML_CONTEXT_H
end_ifndef

begin_define
define|#
directive|define
name|LLD_READER_WRITER_YAML_CONTEXT_H
end_define

begin_include
include|#
directive|include
file|"lld/Core/LLVM.h"
end_include

begin_include
include|#
directive|include
file|<functional>
end_include

begin_include
include|#
directive|include
file|<memory>
end_include

begin_include
include|#
directive|include
file|<vector>
end_include

begin_decl_stmt
name|namespace
name|lld
block|{
name|class
name|File
decl_stmt|;
name|class
name|LinkingContext
decl_stmt|;
name|namespace
name|mach_o
block|{
name|namespace
name|normalized
block|{
struct_decl|struct
name|NormalizedFile
struct_decl|;
block|}
block|}
name|using
name|lld
operator|::
name|mach_o
operator|::
name|normalized
operator|::
name|NormalizedFile
expr_stmt|;
comment|/// When YAML I/O is used in lld, the yaml context always holds a YamlContext
comment|/// object.  We need to support hetergenous yaml documents which each require
comment|/// different context info.  This struct supports all clients.
struct|struct
name|YamlContext
block|{
specifier|const
name|LinkingContext
modifier|*
name|_ctx
init|=
name|nullptr
decl_stmt|;
specifier|const
name|Registry
modifier|*
name|_registry
init|=
name|nullptr
decl_stmt|;
name|File
modifier|*
name|_file
init|=
name|nullptr
decl_stmt|;
name|NormalizedFile
modifier|*
name|_normalizeMachOFile
init|=
name|nullptr
decl_stmt|;
name|StringRef
name|_path
decl_stmt|;
block|}
struct|;
block|}
end_decl_stmt

begin_comment
comment|// end namespace lld
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// LLD_READER_WRITER_YAML_CONTEXT_H
end_comment

end_unit

