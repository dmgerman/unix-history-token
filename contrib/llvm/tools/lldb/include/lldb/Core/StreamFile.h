begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- StreamFile.h --------------------------------------------*- C++ -*-===//
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
name|liblldb_StreamFile_h_
end_ifndef

begin_define
define|#
directive|define
name|liblldb_StreamFile_h_
end_define

begin_include
include|#
directive|include
file|"lldb/Host/File.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Utility/Stream.h"
end_include

begin_include
include|#
directive|include
file|"lldb/lldb-defines.h"
end_include

begin_comment
comment|// for DISALLOW_COPY_AND_ASSIGN
end_comment

begin_include
include|#
directive|include
file|"lldb/lldb-enumerations.h"
end_include

begin_comment
comment|// for FilePermissions::eFilePermission...
end_comment

begin_include
include|#
directive|include
file|<stdint.h>
end_include

begin_comment
comment|// for uint32_t
end_comment

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_comment
comment|// for size_t, FILE
end_comment

begin_decl_stmt
name|namespace
name|lldb_private
block|{
name|class
name|StreamFile
range|:
name|public
name|Stream
block|{
name|public
operator|:
comment|//------------------------------------------------------------------
comment|// Constructors and Destructors
comment|//------------------------------------------------------------------
name|StreamFile
argument_list|()
block|;
name|StreamFile
argument_list|(
argument|uint32_t flags
argument_list|,
argument|uint32_t addr_size
argument_list|,
argument|lldb::ByteOrder byte_order
argument_list|)
block|;
name|StreamFile
argument_list|(
argument|int fd
argument_list|,
argument|bool transfer_ownership
argument_list|)
block|;
name|StreamFile
argument_list|(
specifier|const
name|char
operator|*
name|path
argument_list|)
block|;
name|StreamFile
argument_list|(
argument|const char *path
argument_list|,
argument|uint32_t options
argument_list|,
argument|uint32_t permissions = lldb::eFilePermissionsFileDefault
argument_list|)
block|;
name|StreamFile
argument_list|(
argument|FILE *fh
argument_list|,
argument|bool transfer_ownership
argument_list|)
block|;
operator|~
name|StreamFile
argument_list|()
name|override
block|;
name|File
operator|&
name|GetFile
argument_list|()
block|{
return|return
name|m_file
return|;
block|}
specifier|const
name|File
operator|&
name|GetFile
argument_list|()
specifier|const
block|{
return|return
name|m_file
return|;
block|}
name|void
name|Flush
argument_list|()
name|override
block|;
name|size_t
name|Write
argument_list|(
argument|const void *s
argument_list|,
argument|size_t length
argument_list|)
name|override
block|;
name|protected
operator|:
comment|//------------------------------------------------------------------
comment|// Classes that inherit from StreamFile can see and modify these
comment|//------------------------------------------------------------------
name|File
name|m_file
block|;
name|private
operator|:
name|DISALLOW_COPY_AND_ASSIGN
argument_list|(
name|StreamFile
argument_list|)
block|; }
decl_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// namespace lldb_private
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// liblldb_StreamFile_h_
end_comment

end_unit

