begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- SelectHelper.h ------------------------------------------*- C++ -*-===//
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
name|liblldb_SelectHelper_h_
end_ifndef

begin_define
define|#
directive|define
name|liblldb_SelectHelper_h_
end_define

begin_include
include|#
directive|include
file|"lldb/Utility/Error.h"
end_include

begin_comment
comment|// for Error
end_comment

begin_include
include|#
directive|include
file|"lldb/lldb-types.h"
end_include

begin_comment
comment|// for socket_t
end_comment

begin_include
include|#
directive|include
file|"llvm/ADT/DenseMap.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/Optional.h"
end_include

begin_include
include|#
directive|include
file|<chrono>
end_include

begin_decl_stmt
name|class
name|SelectHelper
block|{
name|public
label|:
comment|// Defaults to infinite wait for select unless you call SetTimeout()
name|SelectHelper
argument_list|()
expr_stmt|;
comment|// Call SetTimeout() before calling SelectHelper::Select() to set the
comment|// timeout based on the current time + the timeout. This allows multiple
comment|// calls to SelectHelper::Select() without having to worry about the
comment|// absolute timeout as this class manages to set the relative timeout
comment|// correctly.
name|void
name|SetTimeout
argument_list|(
specifier|const
name|std
operator|::
name|chrono
operator|::
name|microseconds
operator|&
name|timeout
argument_list|)
decl_stmt|;
comment|// Call the FDSet*() functions before calling SelectHelper::Select() to
comment|// set the file descriptors that we will watch for when calling
comment|// select. This will cause FD_SET() to be called prior to calling select
comment|// using the "fd" provided.
name|void
name|FDSetRead
argument_list|(
name|lldb
operator|::
name|socket_t
name|fd
argument_list|)
decl_stmt|;
name|void
name|FDSetWrite
argument_list|(
name|lldb
operator|::
name|socket_t
name|fd
argument_list|)
decl_stmt|;
name|void
name|FDSetError
argument_list|(
name|lldb
operator|::
name|socket_t
name|fd
argument_list|)
decl_stmt|;
comment|// Call the FDIsSet*() functions after calling SelectHelper::Select()
comment|// to check which file descriptors are ready for read/write/error. This
comment|// will contain the result of FD_ISSET after calling select for a given
comment|// file descriptor.
name|bool
name|FDIsSetRead
argument_list|(
name|lldb
operator|::
name|socket_t
name|fd
argument_list|)
decl|const
decl_stmt|;
name|bool
name|FDIsSetWrite
argument_list|(
name|lldb
operator|::
name|socket_t
name|fd
argument_list|)
decl|const
decl_stmt|;
name|bool
name|FDIsSetError
argument_list|(
name|lldb
operator|::
name|socket_t
name|fd
argument_list|)
decl|const
decl_stmt|;
comment|// Call the system's select() to wait for descriptors using
comment|// timeout provided in a call the SelectHelper::SetTimeout(),
comment|// or infinite wait if no timeout was set.
name|lldb_private
operator|::
name|Error
name|Select
argument_list|()
expr_stmt|;
name|protected
label|:
struct|struct
name|FDInfo
block|{
name|FDInfo
argument_list|()
operator|:
name|read_set
argument_list|(
name|false
argument_list|)
operator|,
name|write_set
argument_list|(
name|false
argument_list|)
operator|,
name|error_set
argument_list|(
name|false
argument_list|)
operator|,
name|read_is_set
argument_list|(
name|false
argument_list|)
operator|,
name|write_is_set
argument_list|(
name|false
argument_list|)
operator|,
name|error_is_set
argument_list|(
argument|false
argument_list|)
block|{}
name|void
name|PrepareForSelect
argument_list|()
block|{
name|read_is_set
operator|=
name|false
block|;
name|write_is_set
operator|=
name|false
block|;
name|error_is_set
operator|=
name|false
block|;     }
name|bool
name|read_set
operator|:
literal|1
operator|,
name|write_set
operator|:
literal|1
operator|,
name|error_set
operator|:
literal|1
operator|,
name|read_is_set
operator|:
literal|1
operator|,
name|write_is_set
operator|:
literal|1
operator|,
name|error_is_set
operator|:
literal|1
expr_stmt|;
block|}
struct|;
name|llvm
operator|::
name|DenseMap
operator|<
name|lldb
operator|::
name|socket_t
operator|,
name|FDInfo
operator|>
name|m_fd_map
expr_stmt|;
name|llvm
operator|::
name|Optional
operator|<
name|std
operator|::
name|chrono
operator|::
name|steady_clock
operator|::
name|time_point
operator|>
name|m_end_time
expr_stmt|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// liblldb_SelectHelper_h_
end_comment

end_unit

