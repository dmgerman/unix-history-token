begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// Copyright (c) 2015 Nuxi, https://nuxi.nl/
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Redistribution and use in source and binary forms, with or without
end_comment

begin_comment
comment|// modification, are permitted provided that the following conditions
end_comment

begin_comment
comment|// are met:
end_comment

begin_comment
comment|// 1. Redistributions of source code must retain the above copyright
end_comment

begin_comment
comment|//    notice, this list of conditions and the following disclaimer.
end_comment

begin_comment
comment|// 2. Redistributions in binary form must reproduce the above copyright
end_comment

begin_comment
comment|//    notice, this list of conditions and the following disclaimer in the
end_comment

begin_comment
comment|//    documentation and/or other materials provided with the distribution.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND
end_comment

begin_comment
comment|// ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
end_comment

begin_comment
comment|// IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
end_comment

begin_comment
comment|// ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE
end_comment

begin_comment
comment|// FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
end_comment

begin_comment
comment|// DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
end_comment

begin_comment
comment|// OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
end_comment

begin_comment
comment|// HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
end_comment

begin_comment
comment|// LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
end_comment

begin_comment
comment|// OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
end_comment

begin_comment
comment|// SUCH DAMAGE.
end_comment

begin_comment
comment|// Machine dependent definitions.
end_comment

begin_comment
comment|// Macro to force sane alignment rules.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// On x86-32 it is the case that 64-bit integers are 4-byte aligned when
end_comment

begin_comment
comment|// embedded in structs, even though they are 8-byte aligned when not
end_comment

begin_comment
comment|// embedded. Force 8-byte alignment explicitly.
end_comment

begin_define
define|#
directive|define
name|MEMBER
parameter_list|(
name|type
parameter_list|)
value|alignas(alignof(type)) type
end_define

begin_define
define|#
directive|define
name|ASSERT_OFFSET
parameter_list|(
name|type
parameter_list|,
name|field
parameter_list|,
name|offset32
parameter_list|,
name|offset64
parameter_list|)
define|\
value|static_assert((sizeof(PTR(void)) == 4&&                        \                  offsetof(IDENT(type), field) == (offset32)) ||   \                     (sizeof(PTR(void)) == 8&&                    \                      offsetof(IDENT(type), field) == (offset64)), \                 "Offset incorrect")
end_define

begin_define
define|#
directive|define
name|ASSERT_SIZE
parameter_list|(
name|type
parameter_list|,
name|size32
parameter_list|,
name|size64
parameter_list|)
define|\
value|static_assert(                                                       \       (sizeof(PTR(void)) == 4&& sizeof(IDENT(type)) == (size32)) ||   \           (sizeof(PTR(void)) == 8&& sizeof(IDENT(type)) == (size64)), \       "Size incorrect")
end_define

begin_typedef
typedef|typedef
name|void
name|IDENT
typedef|(
name|threadentry_t
typedef|)
parameter_list|(
name|cloudabi_tid_t
parameter_list|,
typedef|PTR
parameter_list|(
name|void
parameter_list|)
typedef|);
end_typedef

begin_comment
comment|// Auxiliary vector entry, used to provide paramters on startup.
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|uint32_t
name|a_type
decl_stmt|;
union|union
block|{
name|MEMBER
argument_list|(
argument|IDENT(size_t)
argument_list|)
name|a_val
expr_stmt|;
name|MEMBER
argument_list|(
argument|PTR(void)
argument_list|)
name|a_ptr
expr_stmt|;
block|}
union|;
block|}
name|IDENT
typedef|(
name|auxv_t
typedef|);
end_typedef

begin_expr_stmt
name|ASSERT_OFFSET
argument_list|(
name|auxv_t
argument_list|,
name|a_type
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|ASSERT_OFFSET
argument_list|(
name|auxv_t
argument_list|,
name|a_val
argument_list|,
literal|4
argument_list|,
literal|8
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|ASSERT_OFFSET
argument_list|(
name|auxv_t
argument_list|,
name|a_ptr
argument_list|,
literal|4
argument_list|,
literal|8
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|ASSERT_SIZE
argument_list|(
name|auxv_t
argument_list|,
literal|8
argument_list|,
literal|16
argument_list|)
expr_stmt|;
end_expr_stmt

begin_typedef
typedef|typedef
struct|struct
block|{
name|MEMBER
argument_list|(
argument|PTR(const void)
argument_list|)
name|iov_base
expr_stmt|;
name|MEMBER
argument_list|(
argument|IDENT(size_t)
argument_list|)
name|iov_len
expr_stmt|;
block|}
name|IDENT
typedef|(
name|ciovec_t
typedef|);
end_typedef

begin_expr_stmt
name|ASSERT_OFFSET
argument_list|(
name|ciovec_t
argument_list|,
name|iov_base
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|ASSERT_OFFSET
argument_list|(
name|ciovec_t
argument_list|,
name|iov_len
argument_list|,
literal|4
argument_list|,
literal|8
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|ASSERT_SIZE
argument_list|(
name|ciovec_t
argument_list|,
literal|8
argument_list|,
literal|16
argument_list|)
expr_stmt|;
end_expr_stmt

begin_typedef
typedef|typedef
struct|struct
block|{
name|MEMBER
argument_list|(
argument|cloudabi_userdata_t
argument_list|)
name|userdata
expr_stmt|;
name|MEMBER
argument_list|(
name|cloudabi_errno_t
argument_list|)
name|error
expr_stmt|;
name|MEMBER
argument_list|(
argument|cloudabi_eventtype_t
argument_list|)
name|type
expr_stmt|;
union|union
block|{
comment|// CLOUDABI_EVENTTYPE_CLOCK: Wait until the value of a clock
comment|// exceeds a value.
struct|struct
block|{
name|MEMBER
argument_list|(
argument|cloudabi_userdata_t
argument_list|)
name|identifier
expr_stmt|;
block|}
name|clock
struct|;
comment|// CLOUDABI_EVENTTYPE_CONDVAR: Release a lock and wait on a
comment|// condition variable.
struct|struct
block|{
name|MEMBER
argument_list|(
argument|PTR(_Atomic(cloudabi_condvar_t))
argument_list|)
name|condvar
expr_stmt|;
block|}
name|condvar
struct|;
comment|// CLOUDABI_EVENTTYPE_FD_READ and CLOUDABI_EVENTTYPE_FD_WRITE:
comment|// Wait for a file descriptor to allow read() and write() to be
comment|// called without blocking.
struct|struct
block|{
name|MEMBER
argument_list|(
argument|cloudabi_filesize_t
argument_list|)
name|nbytes
expr_stmt|;
name|MEMBER
argument_list|(
argument|cloudabi_fd_t
argument_list|)
name|fd
expr_stmt|;
name|MEMBER
argument_list|(
argument|uint16_t
argument_list|)
name|flags
expr_stmt|;
block|}
name|fd_readwrite
struct|;
comment|// CLOUDABI_EVENT_LOCK_RDLOCK and CLOUDABI_EVENT_LOCK_WRLOCK: Wait
comment|// and acquire a read or write lock.
struct|struct
block|{
name|MEMBER
argument_list|(
argument|PTR(_Atomic(cloudabi_lock_t))
argument_list|)
name|lock
expr_stmt|;
block|}
name|lock
struct|;
comment|// CLOUDABI_EVENTTYPE_PROC_TERMINATE: Wait for a process to terminate.
struct|struct
block|{
name|MEMBER
argument_list|(
argument|cloudabi_fd_t
argument_list|)
name|fd
expr_stmt|;
name|MEMBER
argument_list|(
argument|cloudabi_signal_t
argument_list|)
name|signal
expr_stmt|;
comment|// Non-zero if process got killed.
name|MEMBER
argument_list|(
argument|cloudabi_exitcode_t
argument_list|)
name|exitcode
expr_stmt|;
comment|// Exit code.
block|}
name|proc_terminate
struct|;
block|}
union|;
block|}
name|IDENT
typedef|(
name|event_t
typedef|);
end_typedef

begin_expr_stmt
name|ASSERT_OFFSET
argument_list|(
name|event_t
argument_list|,
name|userdata
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|ASSERT_OFFSET
argument_list|(
name|event_t
argument_list|,
name|error
argument_list|,
literal|8
argument_list|,
literal|8
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|ASSERT_OFFSET
argument_list|(
name|event_t
argument_list|,
name|type
argument_list|,
literal|10
argument_list|,
literal|10
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|ASSERT_OFFSET
argument_list|(
name|event_t
argument_list|,
name|clock
operator|.
name|identifier
argument_list|,
literal|16
argument_list|,
literal|16
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|ASSERT_OFFSET
argument_list|(
name|event_t
argument_list|,
name|condvar
operator|.
name|condvar
argument_list|,
literal|16
argument_list|,
literal|16
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|ASSERT_OFFSET
argument_list|(
name|event_t
argument_list|,
name|fd_readwrite
operator|.
name|nbytes
argument_list|,
literal|16
argument_list|,
literal|16
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|ASSERT_OFFSET
argument_list|(
name|event_t
argument_list|,
name|fd_readwrite
operator|.
name|fd
argument_list|,
literal|24
argument_list|,
literal|24
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|ASSERT_OFFSET
argument_list|(
name|event_t
argument_list|,
name|fd_readwrite
operator|.
name|flags
argument_list|,
literal|28
argument_list|,
literal|28
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|ASSERT_OFFSET
argument_list|(
name|event_t
argument_list|,
name|lock
operator|.
name|lock
argument_list|,
literal|16
argument_list|,
literal|16
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|ASSERT_OFFSET
argument_list|(
name|event_t
argument_list|,
name|proc_terminate
operator|.
name|fd
argument_list|,
literal|16
argument_list|,
literal|16
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|ASSERT_OFFSET
argument_list|(
name|event_t
argument_list|,
name|proc_terminate
operator|.
name|signal
argument_list|,
literal|20
argument_list|,
literal|20
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|ASSERT_OFFSET
argument_list|(
name|event_t
argument_list|,
name|proc_terminate
operator|.
name|exitcode
argument_list|,
literal|24
argument_list|,
literal|24
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|ASSERT_SIZE
argument_list|(
name|event_t
argument_list|,
literal|32
argument_list|,
literal|32
argument_list|)
expr_stmt|;
end_expr_stmt

begin_typedef
typedef|typedef
struct|struct
block|{
name|MEMBER
argument_list|(
argument|PTR(void)
argument_list|)
name|iov_base
expr_stmt|;
name|MEMBER
argument_list|(
argument|IDENT(size_t)
argument_list|)
name|iov_len
expr_stmt|;
block|}
name|IDENT
typedef|(
name|iovec_t
typedef|);
end_typedef

begin_expr_stmt
name|ASSERT_OFFSET
argument_list|(
name|iovec_t
argument_list|,
name|iov_base
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|ASSERT_OFFSET
argument_list|(
name|iovec_t
argument_list|,
name|iov_len
argument_list|,
literal|4
argument_list|,
literal|8
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|ASSERT_SIZE
argument_list|(
name|iovec_t
argument_list|,
literal|8
argument_list|,
literal|16
argument_list|)
expr_stmt|;
end_expr_stmt

begin_typedef
typedef|typedef
struct|struct
block|{
name|MEMBER
argument_list|(
argument|PTR(const IDENT(iovec_t))
argument_list|)
name|ri_data
expr_stmt|;
comment|// Data I/O vectors.
name|MEMBER
argument_list|(
argument|IDENT(size_t)
argument_list|)
name|ri_datalen
expr_stmt|;
comment|// Number of data I/O vectors.
name|MEMBER
argument_list|(
argument|PTR(cloudabi_fd_t)
argument_list|)
name|ri_fds
expr_stmt|;
comment|// File descriptors.
name|MEMBER
argument_list|(
argument|IDENT(size_t)
argument_list|)
name|ri_fdslen
expr_stmt|;
comment|// Number of file descriptors.
name|MEMBER
argument_list|(
argument|cloudabi_msgflags_t
argument_list|)
name|ri_flags
expr_stmt|;
comment|// Input flags.
block|}
name|IDENT
typedef|(
name|recv_in_t
typedef|);
end_typedef

begin_expr_stmt
name|ASSERT_OFFSET
argument_list|(
name|recv_in_t
argument_list|,
name|ri_data
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|ASSERT_OFFSET
argument_list|(
name|recv_in_t
argument_list|,
name|ri_datalen
argument_list|,
literal|4
argument_list|,
literal|8
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|ASSERT_OFFSET
argument_list|(
name|recv_in_t
argument_list|,
name|ri_fds
argument_list|,
literal|8
argument_list|,
literal|16
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|ASSERT_OFFSET
argument_list|(
name|recv_in_t
argument_list|,
name|ri_fdslen
argument_list|,
literal|12
argument_list|,
literal|24
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|ASSERT_OFFSET
argument_list|(
name|recv_in_t
argument_list|,
name|ri_flags
argument_list|,
literal|16
argument_list|,
literal|32
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|ASSERT_SIZE
argument_list|(
name|recv_in_t
argument_list|,
literal|20
argument_list|,
literal|40
argument_list|)
expr_stmt|;
end_expr_stmt

begin_typedef
typedef|typedef
struct|struct
block|{
name|MEMBER
argument_list|(
argument|IDENT(size_t)
argument_list|)
name|ro_datalen
expr_stmt|;
comment|// Bytes of data received.
name|MEMBER
argument_list|(
argument|IDENT(size_t)
argument_list|)
name|ro_fdslen
expr_stmt|;
comment|// Number of file descriptors received.
name|MEMBER
argument_list|(
argument|cloudabi_sockaddr_t
argument_list|)
name|ro_sockname
expr_stmt|;
comment|// Address of receiver.
name|MEMBER
argument_list|(
argument|cloudabi_sockaddr_t
argument_list|)
name|ro_peername
expr_stmt|;
comment|// Address of sender.
name|MEMBER
argument_list|(
argument|cloudabi_msgflags_t
argument_list|)
name|ro_flags
expr_stmt|;
comment|// Output flags.
block|}
name|IDENT
typedef|(
name|recv_out_t
typedef|);
end_typedef

begin_expr_stmt
name|ASSERT_OFFSET
argument_list|(
name|recv_out_t
argument_list|,
name|ro_datalen
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|ASSERT_OFFSET
argument_list|(
name|recv_out_t
argument_list|,
name|ro_fdslen
argument_list|,
literal|4
argument_list|,
literal|8
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|ASSERT_OFFSET
argument_list|(
name|recv_out_t
argument_list|,
name|ro_sockname
argument_list|,
literal|8
argument_list|,
literal|16
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|ASSERT_OFFSET
argument_list|(
name|recv_out_t
argument_list|,
name|ro_peername
argument_list|,
literal|28
argument_list|,
literal|36
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|ASSERT_OFFSET
argument_list|(
name|recv_out_t
argument_list|,
name|ro_flags
argument_list|,
literal|48
argument_list|,
literal|56
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|ASSERT_SIZE
argument_list|(
name|recv_out_t
argument_list|,
literal|52
argument_list|,
literal|64
argument_list|)
expr_stmt|;
end_expr_stmt

begin_typedef
typedef|typedef
struct|struct
block|{
name|MEMBER
argument_list|(
argument|PTR(const IDENT(ciovec_t))
argument_list|)
name|si_data
expr_stmt|;
comment|// Data I/O vectors.
name|MEMBER
argument_list|(
argument|IDENT(size_t)
argument_list|)
name|si_datalen
expr_stmt|;
comment|// Number of data I/O vectors.
name|MEMBER
argument_list|(
argument|PTR(const cloudabi_fd_t)
argument_list|)
name|si_fds
expr_stmt|;
comment|// File descriptors.
name|MEMBER
argument_list|(
argument|IDENT(size_t)
argument_list|)
name|si_fdslen
expr_stmt|;
comment|// Number of file descriptors.
name|MEMBER
argument_list|(
argument|cloudabi_msgflags_t
argument_list|)
name|si_flags
expr_stmt|;
comment|// Input flags.
block|}
name|IDENT
typedef|(
name|send_in_t
typedef|);
end_typedef

begin_expr_stmt
name|ASSERT_OFFSET
argument_list|(
name|send_in_t
argument_list|,
name|si_data
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|ASSERT_OFFSET
argument_list|(
name|send_in_t
argument_list|,
name|si_datalen
argument_list|,
literal|4
argument_list|,
literal|8
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|ASSERT_OFFSET
argument_list|(
name|send_in_t
argument_list|,
name|si_fds
argument_list|,
literal|8
argument_list|,
literal|16
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|ASSERT_OFFSET
argument_list|(
name|send_in_t
argument_list|,
name|si_fdslen
argument_list|,
literal|12
argument_list|,
literal|24
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|ASSERT_OFFSET
argument_list|(
name|send_in_t
argument_list|,
name|si_flags
argument_list|,
literal|16
argument_list|,
literal|32
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|ASSERT_SIZE
argument_list|(
name|send_in_t
argument_list|,
literal|20
argument_list|,
literal|40
argument_list|)
expr_stmt|;
end_expr_stmt

begin_typedef
typedef|typedef
struct|struct
block|{
name|MEMBER
argument_list|(
argument|IDENT(size_t)
argument_list|)
name|so_datalen
expr_stmt|;
comment|// Bytes of data sent.
block|}
name|IDENT
typedef|(
name|send_out_t
typedef|);
end_typedef

begin_expr_stmt
name|ASSERT_OFFSET
argument_list|(
name|send_out_t
argument_list|,
name|so_datalen
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|ASSERT_SIZE
argument_list|(
name|send_out_t
argument_list|,
literal|4
argument_list|,
literal|8
argument_list|)
expr_stmt|;
end_expr_stmt

begin_typedef
typedef|typedef
struct|struct
block|{
name|MEMBER
argument_list|(
argument|cloudabi_userdata_t
argument_list|)
name|userdata
expr_stmt|;
name|MEMBER
argument_list|(
argument|uint16_t
argument_list|)
name|flags
expr_stmt|;
name|MEMBER
argument_list|(
argument|cloudabi_eventtype_t
argument_list|)
name|type
expr_stmt|;
union|union
block|{
comment|// CLOUDABI_EVENTTYPE_CLOCK: Wait until the value of a clock
comment|// exceeds a value.
struct|struct
block|{
name|MEMBER
argument_list|(
argument|cloudabi_userdata_t
argument_list|)
name|identifier
expr_stmt|;
name|MEMBER
argument_list|(
argument|cloudabi_clockid_t
argument_list|)
name|clock_id
expr_stmt|;
name|MEMBER
argument_list|(
argument|cloudabi_timestamp_t
argument_list|)
name|timeout
expr_stmt|;
name|MEMBER
argument_list|(
argument|cloudabi_timestamp_t
argument_list|)
name|precision
expr_stmt|;
name|MEMBER
argument_list|(
argument|uint16_t
argument_list|)
name|flags
expr_stmt|;
block|}
name|clock
struct|;
comment|// CLOUDABI_EVENTTYPE_CONDVAR: Release a lock and wait on a
comment|// condition variable.
struct|struct
block|{
name|MEMBER
argument_list|(
argument|PTR(_Atomic(cloudabi_condvar_t))
argument_list|)
name|condvar
expr_stmt|;
name|MEMBER
argument_list|(
argument|PTR(_Atomic(cloudabi_lock_t))
argument_list|)
name|lock
expr_stmt|;
name|MEMBER
argument_list|(
argument|cloudabi_mflags_t
argument_list|)
name|condvar_scope
expr_stmt|;
name|MEMBER
argument_list|(
argument|cloudabi_mflags_t
argument_list|)
name|lock_scope
expr_stmt|;
block|}
name|condvar
struct|;
comment|// CLOUDABI_EVENTTYPE_FD_READ and CLOUDABI_EVENTTYPE_FD_WRITE:
comment|// Wait for a file descriptor to allow read() and write() to be
comment|// called without blocking.
struct|struct
block|{
name|MEMBER
argument_list|(
argument|cloudabi_fd_t
argument_list|)
name|fd
expr_stmt|;
name|MEMBER
argument_list|(
argument|uint16_t
argument_list|)
name|flags
expr_stmt|;
block|}
name|fd_readwrite
struct|;
comment|// CLOUDABI_EVENT_LOCK_RDLOCK and CLOUDABI_EVENT_LOCK_WRLOCK: Wait
comment|// and acquire a read or write lock.
struct|struct
block|{
name|MEMBER
argument_list|(
argument|PTR(_Atomic(cloudabi_lock_t))
argument_list|)
name|lock
expr_stmt|;
name|MEMBER
argument_list|(
argument|cloudabi_mflags_t
argument_list|)
name|lock_scope
expr_stmt|;
block|}
name|lock
struct|;
comment|// CLOUDABI_EVENTTYPE_PROC_TERMINATE: Wait for a process to terminate.
struct|struct
block|{
name|MEMBER
argument_list|(
argument|cloudabi_fd_t
argument_list|)
name|fd
expr_stmt|;
block|}
name|proc_terminate
struct|;
block|}
union|;
block|}
name|IDENT
typedef|(
name|subscription_t
typedef|);
end_typedef

begin_expr_stmt
name|ASSERT_OFFSET
argument_list|(
name|subscription_t
argument_list|,
name|userdata
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|ASSERT_OFFSET
argument_list|(
name|subscription_t
argument_list|,
name|flags
argument_list|,
literal|8
argument_list|,
literal|8
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|ASSERT_OFFSET
argument_list|(
name|subscription_t
argument_list|,
name|type
argument_list|,
literal|10
argument_list|,
literal|10
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|ASSERT_OFFSET
argument_list|(
name|subscription_t
argument_list|,
name|clock
operator|.
name|identifier
argument_list|,
literal|16
argument_list|,
literal|16
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|ASSERT_OFFSET
argument_list|(
name|subscription_t
argument_list|,
name|clock
operator|.
name|clock_id
argument_list|,
literal|24
argument_list|,
literal|24
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|ASSERT_OFFSET
argument_list|(
name|subscription_t
argument_list|,
name|clock
operator|.
name|timeout
argument_list|,
literal|32
argument_list|,
literal|32
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|ASSERT_OFFSET
argument_list|(
name|subscription_t
argument_list|,
name|clock
operator|.
name|precision
argument_list|,
literal|40
argument_list|,
literal|40
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|ASSERT_OFFSET
argument_list|(
name|subscription_t
argument_list|,
name|clock
operator|.
name|flags
argument_list|,
literal|48
argument_list|,
literal|48
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|ASSERT_OFFSET
argument_list|(
name|subscription_t
argument_list|,
name|condvar
operator|.
name|condvar
argument_list|,
literal|16
argument_list|,
literal|16
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|ASSERT_OFFSET
argument_list|(
name|subscription_t
argument_list|,
name|condvar
operator|.
name|lock
argument_list|,
literal|20
argument_list|,
literal|24
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|ASSERT_OFFSET
argument_list|(
name|subscription_t
argument_list|,
name|condvar
operator|.
name|condvar_scope
argument_list|,
literal|24
argument_list|,
literal|32
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|ASSERT_OFFSET
argument_list|(
name|subscription_t
argument_list|,
name|condvar
operator|.
name|lock_scope
argument_list|,
literal|25
argument_list|,
literal|33
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|ASSERT_OFFSET
argument_list|(
name|subscription_t
argument_list|,
name|fd_readwrite
operator|.
name|fd
argument_list|,
literal|16
argument_list|,
literal|16
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|ASSERT_OFFSET
argument_list|(
name|subscription_t
argument_list|,
name|fd_readwrite
operator|.
name|flags
argument_list|,
literal|20
argument_list|,
literal|20
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|ASSERT_OFFSET
argument_list|(
name|subscription_t
argument_list|,
name|lock
operator|.
name|lock
argument_list|,
literal|16
argument_list|,
literal|16
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|ASSERT_OFFSET
argument_list|(
name|subscription_t
argument_list|,
name|lock
operator|.
name|lock_scope
argument_list|,
literal|20
argument_list|,
literal|24
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|ASSERT_OFFSET
argument_list|(
name|subscription_t
argument_list|,
name|proc_terminate
operator|.
name|fd
argument_list|,
literal|16
argument_list|,
literal|16
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|ASSERT_SIZE
argument_list|(
name|subscription_t
argument_list|,
literal|56
argument_list|,
literal|56
argument_list|)
expr_stmt|;
end_expr_stmt

begin_typedef
typedef|typedef
struct|struct
block|{
name|MEMBER
argument_list|(
argument|PTR(IDENT(threadentry_t))
argument_list|)
name|entry_point
expr_stmt|;
comment|// Entry point.
name|MEMBER
argument_list|(
argument|PTR(void)
argument_list|)
name|stack
expr_stmt|;
comment|// Pointer to stack buffer.
name|MEMBER
argument_list|(
argument|IDENT(size_t)
argument_list|)
name|stack_size
expr_stmt|;
comment|// Size of stack buffer.
name|MEMBER
argument_list|(
argument|PTR(void)
argument_list|)
name|argument
expr_stmt|;
comment|// Argument to be passed to entry point.
block|}
name|IDENT
typedef|(
name|threadattr_t
typedef|);
end_typedef

begin_expr_stmt
name|ASSERT_OFFSET
argument_list|(
name|threadattr_t
argument_list|,
name|entry_point
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|ASSERT_OFFSET
argument_list|(
name|threadattr_t
argument_list|,
name|stack
argument_list|,
literal|4
argument_list|,
literal|8
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|ASSERT_OFFSET
argument_list|(
name|threadattr_t
argument_list|,
name|stack_size
argument_list|,
literal|8
argument_list|,
literal|16
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|ASSERT_OFFSET
argument_list|(
name|threadattr_t
argument_list|,
name|argument
argument_list|,
literal|12
argument_list|,
literal|24
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|ASSERT_SIZE
argument_list|(
name|threadattr_t
argument_list|,
literal|16
argument_list|,
literal|32
argument_list|)
expr_stmt|;
end_expr_stmt

begin_undef
undef|#
directive|undef
name|MEMBER
end_undef

begin_undef
undef|#
directive|undef
name|ASSERT_OFFSET
end_undef

begin_undef
undef|#
directive|undef
name|ASSERT_SIZE
end_undef

end_unit

