begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- FileCache.h ---------------------------------------------*- C++ -*-===//
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
name|liblldb_Host_FileCache_h
end_ifndef

begin_define
define|#
directive|define
name|liblldb_Host_FileCache_h
end_define

begin_include
include|#
directive|include
file|<map>
end_include

begin_include
include|#
directive|include
file|<stdint.h>
end_include

begin_include
include|#
directive|include
file|"lldb/lldb-forward.h"
end_include

begin_include
include|#
directive|include
file|"lldb/lldb-types.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Utility/Error.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Utility/FileSpec.h"
end_include

begin_decl_stmt
name|namespace
name|lldb_private
block|{
name|class
name|FileCache
block|{
name|private
label|:
name|FileCache
argument_list|()
block|{}
typedef|typedef
name|std
operator|::
name|map
operator|<
name|lldb
operator|::
name|user_id_t
operator|,
name|lldb
operator|::
name|FileSP
operator|>
name|FDToFileMap
expr_stmt|;
name|public
label|:
specifier|static
name|FileCache
modifier|&
name|GetInstance
parameter_list|()
function_decl|;
name|lldb
operator|::
name|user_id_t
name|OpenFile
argument_list|(
argument|const FileSpec&file_spec
argument_list|,
argument|uint32_t flags
argument_list|,
argument|uint32_t mode
argument_list|,
argument|Error&error
argument_list|)
expr_stmt|;
name|bool
name|CloseFile
argument_list|(
name|lldb
operator|::
name|user_id_t
name|fd
argument_list|,
name|Error
operator|&
name|error
argument_list|)
decl_stmt|;
name|uint64_t
name|WriteFile
argument_list|(
name|lldb
operator|::
name|user_id_t
name|fd
argument_list|,
name|uint64_t
name|offset
argument_list|,
specifier|const
name|void
operator|*
name|src
argument_list|,
name|uint64_t
name|src_len
argument_list|,
name|Error
operator|&
name|error
argument_list|)
decl_stmt|;
name|uint64_t
name|ReadFile
argument_list|(
name|lldb
operator|::
name|user_id_t
name|fd
argument_list|,
name|uint64_t
name|offset
argument_list|,
name|void
operator|*
name|dst
argument_list|,
name|uint64_t
name|dst_len
argument_list|,
name|Error
operator|&
name|error
argument_list|)
decl_stmt|;
name|private
label|:
specifier|static
name|FileCache
modifier|*
name|m_instance
decl_stmt|;
name|FDToFileMap
name|m_cache
decl_stmt|;
block|}
empty_stmt|;
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

