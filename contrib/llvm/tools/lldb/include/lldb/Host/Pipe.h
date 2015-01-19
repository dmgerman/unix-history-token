begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- Pipe.h --------------------------------------------------*- C++ -*-===//
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
name|liblldb_Pipe_h_
end_ifndef

begin_define
define|#
directive|define
name|liblldb_Pipe_h_
end_define

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__cplusplus
argument_list|)
end_if

begin_include
include|#
directive|include
file|<stdarg.h>
end_include

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|"lldb/lldb-private.h"
end_include

begin_decl_stmt
name|namespace
name|lldb_private
block|{
comment|//----------------------------------------------------------------------
comment|/// @class Pipe Pipe.h "lldb/Host/Pipe.h"
comment|/// @brief A class that abtracts unix style pipes.
comment|///
comment|/// A class that abstracts the LLDB core from host pipe functionality.
comment|//----------------------------------------------------------------------
name|class
name|Pipe
block|{
name|public
label|:
specifier|static
name|int
name|kInvalidDescriptor
decl_stmt|;
name|Pipe
argument_list|()
expr_stmt|;
operator|~
name|Pipe
argument_list|()
expr_stmt|;
name|bool
name|Open
parameter_list|()
function_decl|;
name|bool
name|IsValid
argument_list|()
specifier|const
expr_stmt|;
name|bool
name|ReadDescriptorIsValid
argument_list|()
specifier|const
expr_stmt|;
name|bool
name|WriteDescriptorIsValid
argument_list|()
specifier|const
expr_stmt|;
name|int
name|GetReadFileDescriptor
argument_list|()
specifier|const
expr_stmt|;
name|int
name|GetWriteFileDescriptor
argument_list|()
specifier|const
expr_stmt|;
comment|// Close both descriptors
name|void
name|Close
parameter_list|()
function_decl|;
name|bool
name|CloseReadFileDescriptor
parameter_list|()
function_decl|;
name|bool
name|CloseWriteFileDescriptor
parameter_list|()
function_decl|;
name|int
name|ReleaseReadFileDescriptor
parameter_list|()
function_decl|;
name|int
name|ReleaseWriteFileDescriptor
parameter_list|()
function_decl|;
name|size_t
name|Read
parameter_list|(
name|void
modifier|*
name|buf
parameter_list|,
name|size_t
name|size
parameter_list|)
function_decl|;
name|size_t
name|Write
parameter_list|(
specifier|const
name|void
modifier|*
name|buf
parameter_list|,
name|size_t
name|size
parameter_list|)
function_decl|;
name|private
label|:
name|int
name|m_fds
index|[
literal|2
index|]
decl_stmt|;
block|}
empty_stmt|;
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
comment|// #if defined(__cplusplus)
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// liblldb_Pipe_h_
end_comment

end_unit

