begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- Signalfd.h ----------------------------------------------*- C++ -*-===//
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
comment|// This file defines signalfd functions& structures
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|liblldb_Host_linux_Signalfd_h_
end_ifndef

begin_define
define|#
directive|define
name|liblldb_Host_linux_Signalfd_h_
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|__ANDROID_NDK__
end_ifdef

begin_include
include|#
directive|include
file|<android/api-level.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__ANDROID_API__
argument_list|)
operator|&&
name|__ANDROID_API__
operator|<
literal|21
end_if

begin_include
include|#
directive|include
file|<linux/types.h>
end_include

begin_include
include|#
directive|include
file|<linux/fcntl.h>
end_include

begin_define
define|#
directive|define
name|SFD_CLOEXEC
value|O_CLOEXEC
end_define

begin_define
define|#
directive|define
name|SFD_NONBLOCK
value|O_NONBLOCK
end_define

begin_struct
struct|struct
name|signalfd_siginfo
block|{
name|__u32
name|ssi_signo
decl_stmt|;
name|__s32
name|ssi_errno
decl_stmt|;
name|__s32
name|ssi_code
decl_stmt|;
name|__u32
name|ssi_pid
decl_stmt|;
name|__u32
name|ssi_uid
decl_stmt|;
name|__s32
name|ssi_fd
decl_stmt|;
name|__u32
name|ssi_tid
decl_stmt|;
name|__u32
name|ssi_band
decl_stmt|;
name|__u32
name|ssi_overrun
decl_stmt|;
name|__u32
name|ssi_trapno
decl_stmt|;
name|__s32
name|ssi_status
decl_stmt|;
name|__s32
name|ssi_int
decl_stmt|;
name|__u64
name|ssi_ptr
decl_stmt|;
name|__u64
name|ssi_utime
decl_stmt|;
name|__u64
name|ssi_stime
decl_stmt|;
name|__u64
name|ssi_addr
decl_stmt|;
name|__u16
name|ssi_addr_lsb
decl_stmt|;
name|__u8
name|__pad
index|[
literal|46
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_function_decl
name|int
name|signalfd
parameter_list|(
name|int
name|fd
parameter_list|,
specifier|const
name|sigset_t
modifier|*
name|mask
parameter_list|,
name|int
name|flags
parameter_list|)
function_decl|;
end_function_decl

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|<sys/signalfd.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// liblldb_Host_linux_Signalfd_h_
end_comment

end_unit

