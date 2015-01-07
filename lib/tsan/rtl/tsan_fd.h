begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- tsan_fd.h -----------------------------------------------*- C++ -*-===//
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
comment|// This file is a part of ThreadSanitizer (TSan), a race detector.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// This file handles synchronization via IO.
end_comment

begin_comment
comment|// People use IO for synchronization along the lines of:
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// int X;
end_comment

begin_comment
comment|// int client_socket;  // initialized elsewhere
end_comment

begin_comment
comment|// int server_socket;  // initialized elsewhere
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Thread 1:
end_comment

begin_comment
comment|// X = 42;
end_comment

begin_comment
comment|// send(client_socket, ...);
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Thread 2:
end_comment

begin_comment
comment|// if (recv(server_socket, ...)> 0)
end_comment

begin_comment
comment|//   assert(X == 42);
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// This file determines the scope of the file descriptor (pipe, socket,
end_comment

begin_comment
comment|// all local files, etc) and executes acquire and release operations on
end_comment

begin_comment
comment|// the scope as necessary.  Some scopes are very fine grained (e.g. pipe
end_comment

begin_comment
comment|// operations synchronize only with operations on the same pipe), while
end_comment

begin_comment
comment|// others are corse-grained (e.g. all operations on local files synchronize
end_comment

begin_comment
comment|// with each other).
end_comment

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|TSAN_FD_H
end_ifndef

begin_define
define|#
directive|define
name|TSAN_FD_H
end_define

begin_include
include|#
directive|include
file|"tsan_rtl.h"
end_include

begin_decl_stmt
name|namespace
name|__tsan
block|{
name|void
name|FdInit
parameter_list|()
function_decl|;
name|void
name|FdAcquire
parameter_list|(
name|ThreadState
modifier|*
name|thr
parameter_list|,
name|uptr
name|pc
parameter_list|,
name|int
name|fd
parameter_list|)
function_decl|;
name|void
name|FdRelease
parameter_list|(
name|ThreadState
modifier|*
name|thr
parameter_list|,
name|uptr
name|pc
parameter_list|,
name|int
name|fd
parameter_list|)
function_decl|;
name|void
name|FdAccess
parameter_list|(
name|ThreadState
modifier|*
name|thr
parameter_list|,
name|uptr
name|pc
parameter_list|,
name|int
name|fd
parameter_list|)
function_decl|;
name|void
name|FdClose
parameter_list|(
name|ThreadState
modifier|*
name|thr
parameter_list|,
name|uptr
name|pc
parameter_list|,
name|int
name|fd
parameter_list|)
function_decl|;
name|void
name|FdFileCreate
parameter_list|(
name|ThreadState
modifier|*
name|thr
parameter_list|,
name|uptr
name|pc
parameter_list|,
name|int
name|fd
parameter_list|)
function_decl|;
name|void
name|FdDup
parameter_list|(
name|ThreadState
modifier|*
name|thr
parameter_list|,
name|uptr
name|pc
parameter_list|,
name|int
name|oldfd
parameter_list|,
name|int
name|newfd
parameter_list|)
function_decl|;
name|void
name|FdPipeCreate
parameter_list|(
name|ThreadState
modifier|*
name|thr
parameter_list|,
name|uptr
name|pc
parameter_list|,
name|int
name|rfd
parameter_list|,
name|int
name|wfd
parameter_list|)
function_decl|;
name|void
name|FdEventCreate
parameter_list|(
name|ThreadState
modifier|*
name|thr
parameter_list|,
name|uptr
name|pc
parameter_list|,
name|int
name|fd
parameter_list|)
function_decl|;
name|void
name|FdSignalCreate
parameter_list|(
name|ThreadState
modifier|*
name|thr
parameter_list|,
name|uptr
name|pc
parameter_list|,
name|int
name|fd
parameter_list|)
function_decl|;
name|void
name|FdInotifyCreate
parameter_list|(
name|ThreadState
modifier|*
name|thr
parameter_list|,
name|uptr
name|pc
parameter_list|,
name|int
name|fd
parameter_list|)
function_decl|;
name|void
name|FdPollCreate
parameter_list|(
name|ThreadState
modifier|*
name|thr
parameter_list|,
name|uptr
name|pc
parameter_list|,
name|int
name|fd
parameter_list|)
function_decl|;
name|void
name|FdSocketCreate
parameter_list|(
name|ThreadState
modifier|*
name|thr
parameter_list|,
name|uptr
name|pc
parameter_list|,
name|int
name|fd
parameter_list|)
function_decl|;
name|void
name|FdSocketAccept
parameter_list|(
name|ThreadState
modifier|*
name|thr
parameter_list|,
name|uptr
name|pc
parameter_list|,
name|int
name|fd
parameter_list|,
name|int
name|newfd
parameter_list|)
function_decl|;
name|void
name|FdSocketConnecting
parameter_list|(
name|ThreadState
modifier|*
name|thr
parameter_list|,
name|uptr
name|pc
parameter_list|,
name|int
name|fd
parameter_list|)
function_decl|;
name|void
name|FdSocketConnect
parameter_list|(
name|ThreadState
modifier|*
name|thr
parameter_list|,
name|uptr
name|pc
parameter_list|,
name|int
name|fd
parameter_list|)
function_decl|;
name|bool
name|FdLocation
parameter_list|(
name|uptr
name|addr
parameter_list|,
name|int
modifier|*
name|fd
parameter_list|,
name|int
modifier|*
name|tid
parameter_list|,
name|u32
modifier|*
name|stack
parameter_list|)
function_decl|;
name|void
name|FdOnFork
parameter_list|(
name|ThreadState
modifier|*
name|thr
parameter_list|,
name|uptr
name|pc
parameter_list|)
function_decl|;
name|uptr
name|File2addr
parameter_list|(
specifier|const
name|char
modifier|*
name|path
parameter_list|)
function_decl|;
name|uptr
name|Dir2addr
parameter_list|(
specifier|const
name|char
modifier|*
name|path
parameter_list|)
function_decl|;
block|}
end_decl_stmt

begin_comment
comment|// namespace __tsan
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// TSAN_INTERFACE_H
end_comment

end_unit

