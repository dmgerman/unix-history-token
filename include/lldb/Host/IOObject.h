begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- IOObject.h ----------------------------------------------*- C++ -*-===//
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
name|liblldb_Host_Common_IOObject_h_
end_ifndef

begin_define
define|#
directive|define
name|liblldb_Host_Common_IOObject_h_
end_define

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
name|class
name|IOObject
block|{
name|public
label|:
typedef|typedef
enum|enum
block|{
name|eFDTypeFile
block|,
comment|// Other FD requiring read/write
name|eFDTypeSocket
block|,
comment|// Socket requiring send/recv
block|}
name|FDType
typedef|;
comment|// TODO: On Windows this should be a HANDLE, and wait should use
comment|// WaitForMultipleObjects
typedef|typedef
name|int
name|WaitableHandle
typedef|;
specifier|static
specifier|const
name|WaitableHandle
name|kInvalidHandleValue
decl_stmt|;
name|IOObject
argument_list|(
argument|FDType type
argument_list|,
argument|bool should_close
argument_list|)
block|:
name|m_fd_type
argument_list|(
name|type
argument_list|)
operator|,
name|m_should_close_fd
argument_list|(
argument|should_close
argument_list|)
block|{}
name|virtual
operator|~
name|IOObject
argument_list|()
block|{}
name|virtual
name|Status
name|Read
argument_list|(
name|void
operator|*
name|buf
argument_list|,
name|size_t
operator|&
name|num_bytes
argument_list|)
operator|=
literal|0
expr_stmt|;
name|virtual
name|Status
name|Write
parameter_list|(
specifier|const
name|void
modifier|*
name|buf
parameter_list|,
name|size_t
modifier|&
name|num_bytes
parameter_list|)
init|=
literal|0
function_decl|;
name|virtual
name|bool
name|IsValid
argument_list|()
specifier|const
operator|=
literal|0
expr_stmt|;
name|virtual
name|Status
name|Close
parameter_list|()
init|=
literal|0
function_decl|;
name|FDType
name|GetFdType
argument_list|()
specifier|const
block|{
return|return
name|m_fd_type
return|;
block|}
name|virtual
name|WaitableHandle
name|GetWaitableHandle
parameter_list|()
init|=
literal|0
function_decl|;
name|protected
label|:
name|FDType
name|m_fd_type
decl_stmt|;
name|bool
name|m_should_close_fd
decl_stmt|;
comment|// True if this class should close the file descriptor
comment|// when it goes away.
name|private
label|:
name|DISALLOW_COPY_AND_ASSIGN
argument_list|(
name|IOObject
argument_list|)
expr_stmt|;
block|}
empty_stmt|;
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

