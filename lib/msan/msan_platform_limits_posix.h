begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- msan_platform_limits.h ----------------------------------*- C++ -*-===//
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
comment|// This file is a part of MemorySanitizer.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Sizes and layouts of platform-specific data structures.
end_comment

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|MSAN_PLATFORM_LIMITS_H
end_ifndef

begin_define
define|#
directive|define
name|MSAN_PLATFORM_LIMITS_H
end_define

begin_decl_stmt
name|namespace
name|__msan
block|{
specifier|extern
name|unsigned
name|struct_utsname_sz
decl_stmt|;
specifier|extern
name|unsigned
name|struct_stat_sz
decl_stmt|;
specifier|extern
name|unsigned
name|struct_stat64_sz
decl_stmt|;
specifier|extern
name|unsigned
name|struct_rlimit_sz
decl_stmt|;
specifier|extern
name|unsigned
name|struct_rlimit64_sz
decl_stmt|;
specifier|extern
name|unsigned
name|struct_dirent_sz
decl_stmt|;
specifier|extern
name|unsigned
name|struct_statfs_sz
decl_stmt|;
specifier|extern
name|unsigned
name|struct_statfs64_sz
decl_stmt|;
specifier|extern
name|unsigned
name|struct_epoll_event_sz
decl_stmt|;
specifier|extern
name|unsigned
name|struct_rusage_sz
decl_stmt|;
name|void
modifier|*
name|__msan_get_msghdr_iov_iov_base
parameter_list|(
name|void
modifier|*
name|msg
parameter_list|,
name|int
name|idx
parameter_list|)
function_decl|;
name|uptr
name|__msan_get_msghdr_iov_iov_len
parameter_list|(
name|void
modifier|*
name|msg
parameter_list|,
name|int
name|idx
parameter_list|)
function_decl|;
name|uptr
name|__msan_get_msghdr_iovlen
parameter_list|(
name|void
modifier|*
name|msg
parameter_list|)
function_decl|;
name|uptr
name|__msan_get_socklen_t
parameter_list|(
name|void
modifier|*
name|socklen_ptr
parameter_list|)
function_decl|;
block|}
end_decl_stmt

begin_comment
comment|// namespace __msan
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

