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

begin_ifndef
ifndef|#
directive|ifndef
name|COMMON_SYSCALLDEFS_MI_H
end_ifndef

begin_define
define|#
directive|define
name|COMMON_SYSCALLDEFS_MI_H
end_define

begin_comment
comment|// Machine independent definitions.
end_comment

begin_comment
comment|// Socket address families.
end_comment

begin_define
define|#
directive|define
name|CLOUDABI_AF_UNSPEC
value|0
end_define

begin_define
define|#
directive|define
name|CLOUDABI_AF_INET
value|1
end_define

begin_define
define|#
directive|define
name|CLOUDABI_AF_INET6
value|2
end_define

begin_define
define|#
directive|define
name|CLOUDABI_AF_UNIX
value|3
end_define

begin_comment
comment|// File and memory I/O advice.
end_comment

begin_define
define|#
directive|define
name|CLOUDABI_ADVICE_DONTNEED
value|1
end_define

begin_define
define|#
directive|define
name|CLOUDABI_ADVICE_NOREUSE
value|2
end_define

begin_define
define|#
directive|define
name|CLOUDABI_ADVICE_NORMAL
value|3
end_define

begin_define
define|#
directive|define
name|CLOUDABI_ADVICE_RANDOM
value|4
end_define

begin_define
define|#
directive|define
name|CLOUDABI_ADVICE_SEQUENTIAL
value|5
end_define

begin_define
define|#
directive|define
name|CLOUDABI_ADVICE_WILLNEED
value|6
end_define

begin_comment
comment|// Auxiliary vector entries. All entries that are also part of the
end_comment

begin_comment
comment|// x86-64 ABI use the same number. All extensions start at 256.
end_comment

begin_define
define|#
directive|define
name|CLOUDABI_AT_ARGDATA
value|256
end_define

begin_define
define|#
directive|define
name|CLOUDABI_AT_ARGDATALEN
value|257
end_define

begin_define
define|#
directive|define
name|CLOUDABI_AT_CANARY
value|258
end_define

begin_define
define|#
directive|define
name|CLOUDABI_AT_CANARYLEN
value|259
end_define

begin_define
define|#
directive|define
name|CLOUDABI_AT_NCPUS
value|260
end_define

begin_define
define|#
directive|define
name|CLOUDABI_AT_NULL
value|0
end_define

begin_define
define|#
directive|define
name|CLOUDABI_AT_PAGESZ
value|6
end_define

begin_define
define|#
directive|define
name|CLOUDABI_AT_PHDR
value|3
end_define

begin_define
define|#
directive|define
name|CLOUDABI_AT_PHNUM
value|4
end_define

begin_define
define|#
directive|define
name|CLOUDABI_AT_TID
value|261
end_define

begin_comment
comment|// Clocks.
end_comment

begin_define
define|#
directive|define
name|CLOUDABI_CLOCK_MONOTONIC
value|1
end_define

begin_define
define|#
directive|define
name|CLOUDABI_CLOCK_PROCESS_CPUTIME_ID
value|2
end_define

begin_define
define|#
directive|define
name|CLOUDABI_CLOCK_REALTIME
value|3
end_define

begin_define
define|#
directive|define
name|CLOUDABI_CLOCK_THREAD_CPUTIME_ID
value|4
end_define

begin_comment
comment|// Condition variables.
end_comment

begin_define
define|#
directive|define
name|CLOUDABI_CONDVAR_HAS_NO_WAITERS
value|0
end_define

begin_comment
comment|// The start of a directory, to be passed to readdir().
end_comment

begin_define
define|#
directive|define
name|CLOUDABI_DIRCOOKIE_START
value|0
end_define

begin_comment
comment|// POSIX standard error numbers.
end_comment

begin_define
define|#
directive|define
name|CLOUDABI_E2BIG
value|1
end_define

begin_define
define|#
directive|define
name|CLOUDABI_EACCES
value|2
end_define

begin_define
define|#
directive|define
name|CLOUDABI_EADDRINUSE
value|3
end_define

begin_define
define|#
directive|define
name|CLOUDABI_EADDRNOTAVAIL
value|4
end_define

begin_define
define|#
directive|define
name|CLOUDABI_EAFNOSUPPORT
value|5
end_define

begin_define
define|#
directive|define
name|CLOUDABI_EAGAIN
value|6
end_define

begin_define
define|#
directive|define
name|CLOUDABI_EALREADY
value|7
end_define

begin_define
define|#
directive|define
name|CLOUDABI_EBADF
value|8
end_define

begin_define
define|#
directive|define
name|CLOUDABI_EBADMSG
value|9
end_define

begin_define
define|#
directive|define
name|CLOUDABI_EBUSY
value|10
end_define

begin_define
define|#
directive|define
name|CLOUDABI_ECANCELED
value|11
end_define

begin_define
define|#
directive|define
name|CLOUDABI_ECHILD
value|12
end_define

begin_define
define|#
directive|define
name|CLOUDABI_ECONNABORTED
value|13
end_define

begin_define
define|#
directive|define
name|CLOUDABI_ECONNREFUSED
value|14
end_define

begin_define
define|#
directive|define
name|CLOUDABI_ECONNRESET
value|15
end_define

begin_define
define|#
directive|define
name|CLOUDABI_EDEADLK
value|16
end_define

begin_define
define|#
directive|define
name|CLOUDABI_EDESTADDRREQ
value|17
end_define

begin_define
define|#
directive|define
name|CLOUDABI_EDOM
value|18
end_define

begin_define
define|#
directive|define
name|CLOUDABI_EDQUOT
value|19
end_define

begin_define
define|#
directive|define
name|CLOUDABI_EEXIST
value|20
end_define

begin_define
define|#
directive|define
name|CLOUDABI_EFAULT
value|21
end_define

begin_define
define|#
directive|define
name|CLOUDABI_EFBIG
value|22
end_define

begin_define
define|#
directive|define
name|CLOUDABI_EHOSTUNREACH
value|23
end_define

begin_define
define|#
directive|define
name|CLOUDABI_EIDRM
value|24
end_define

begin_define
define|#
directive|define
name|CLOUDABI_EILSEQ
value|25
end_define

begin_define
define|#
directive|define
name|CLOUDABI_EINPROGRESS
value|26
end_define

begin_define
define|#
directive|define
name|CLOUDABI_EINTR
value|27
end_define

begin_define
define|#
directive|define
name|CLOUDABI_EINVAL
value|28
end_define

begin_define
define|#
directive|define
name|CLOUDABI_EIO
value|29
end_define

begin_define
define|#
directive|define
name|CLOUDABI_EISCONN
value|30
end_define

begin_define
define|#
directive|define
name|CLOUDABI_EISDIR
value|31
end_define

begin_define
define|#
directive|define
name|CLOUDABI_ELOOP
value|32
end_define

begin_define
define|#
directive|define
name|CLOUDABI_EMFILE
value|33
end_define

begin_define
define|#
directive|define
name|CLOUDABI_EMLINK
value|34
end_define

begin_define
define|#
directive|define
name|CLOUDABI_EMSGSIZE
value|35
end_define

begin_define
define|#
directive|define
name|CLOUDABI_EMULTIHOP
value|36
end_define

begin_define
define|#
directive|define
name|CLOUDABI_ENAMETOOLONG
value|37
end_define

begin_define
define|#
directive|define
name|CLOUDABI_ENETDOWN
value|38
end_define

begin_define
define|#
directive|define
name|CLOUDABI_ENETRESET
value|39
end_define

begin_define
define|#
directive|define
name|CLOUDABI_ENETUNREACH
value|40
end_define

begin_define
define|#
directive|define
name|CLOUDABI_ENFILE
value|41
end_define

begin_define
define|#
directive|define
name|CLOUDABI_ENOBUFS
value|42
end_define

begin_define
define|#
directive|define
name|CLOUDABI_ENODEV
value|43
end_define

begin_define
define|#
directive|define
name|CLOUDABI_ENOENT
value|44
end_define

begin_define
define|#
directive|define
name|CLOUDABI_ENOEXEC
value|45
end_define

begin_define
define|#
directive|define
name|CLOUDABI_ENOLCK
value|46
end_define

begin_define
define|#
directive|define
name|CLOUDABI_ENOLINK
value|47
end_define

begin_define
define|#
directive|define
name|CLOUDABI_ENOMEM
value|48
end_define

begin_define
define|#
directive|define
name|CLOUDABI_ENOMSG
value|49
end_define

begin_define
define|#
directive|define
name|CLOUDABI_ENOPROTOOPT
value|50
end_define

begin_define
define|#
directive|define
name|CLOUDABI_ENOSPC
value|51
end_define

begin_define
define|#
directive|define
name|CLOUDABI_ENOSYS
value|52
end_define

begin_define
define|#
directive|define
name|CLOUDABI_ENOTCONN
value|53
end_define

begin_define
define|#
directive|define
name|CLOUDABI_ENOTDIR
value|54
end_define

begin_define
define|#
directive|define
name|CLOUDABI_ENOTEMPTY
value|55
end_define

begin_define
define|#
directive|define
name|CLOUDABI_ENOTRECOVERABLE
value|56
end_define

begin_define
define|#
directive|define
name|CLOUDABI_ENOTSOCK
value|57
end_define

begin_define
define|#
directive|define
name|CLOUDABI_ENOTSUP
value|58
end_define

begin_define
define|#
directive|define
name|CLOUDABI_ENOTTY
value|59
end_define

begin_define
define|#
directive|define
name|CLOUDABI_ENXIO
value|60
end_define

begin_define
define|#
directive|define
name|CLOUDABI_EOVERFLOW
value|61
end_define

begin_define
define|#
directive|define
name|CLOUDABI_EOWNERDEAD
value|62
end_define

begin_define
define|#
directive|define
name|CLOUDABI_EPERM
value|63
end_define

begin_define
define|#
directive|define
name|CLOUDABI_EPIPE
value|64
end_define

begin_define
define|#
directive|define
name|CLOUDABI_EPROTO
value|65
end_define

begin_define
define|#
directive|define
name|CLOUDABI_EPROTONOSUPPORT
value|66
end_define

begin_define
define|#
directive|define
name|CLOUDABI_EPROTOTYPE
value|67
end_define

begin_define
define|#
directive|define
name|CLOUDABI_ERANGE
value|68
end_define

begin_define
define|#
directive|define
name|CLOUDABI_EROFS
value|69
end_define

begin_define
define|#
directive|define
name|CLOUDABI_ESPIPE
value|70
end_define

begin_define
define|#
directive|define
name|CLOUDABI_ESRCH
value|71
end_define

begin_define
define|#
directive|define
name|CLOUDABI_ESTALE
value|72
end_define

begin_define
define|#
directive|define
name|CLOUDABI_ETIMEDOUT
value|73
end_define

begin_define
define|#
directive|define
name|CLOUDABI_ETXTBSY
value|74
end_define

begin_define
define|#
directive|define
name|CLOUDABI_EXDEV
value|75
end_define

begin_comment
comment|// Non-standard error numbers.
end_comment

begin_define
define|#
directive|define
name|CLOUDABI_ENOTCAPABLE
value|76
end_define

begin_define
define|#
directive|define
name|CLOUDABI_EVENT_FD_READWRITE_HANGUP
value|0x1
end_define

begin_comment
comment|// Filter types for cloudabi_eventtype_t.
end_comment

begin_define
define|#
directive|define
name|CLOUDABI_EVENTTYPE_CLOCK
value|1
end_define

begin_define
define|#
directive|define
name|CLOUDABI_EVENTTYPE_CONDVAR
value|2
end_define

begin_define
define|#
directive|define
name|CLOUDABI_EVENTTYPE_FD_READ
value|3
end_define

begin_define
define|#
directive|define
name|CLOUDABI_EVENTTYPE_FD_WRITE
value|4
end_define

begin_define
define|#
directive|define
name|CLOUDABI_EVENTTYPE_LOCK_RDLOCK
value|5
end_define

begin_define
define|#
directive|define
name|CLOUDABI_EVENTTYPE_LOCK_WRLOCK
value|6
end_define

begin_define
define|#
directive|define
name|CLOUDABI_EVENTTYPE_PROC_TERMINATE
value|7
end_define

begin_comment
comment|// File descriptor behavior flags.
end_comment

begin_define
define|#
directive|define
name|CLOUDABI_FDFLAG_APPEND
value|0x1
end_define

begin_define
define|#
directive|define
name|CLOUDABI_FDFLAG_DSYNC
value|0x2
end_define

begin_define
define|#
directive|define
name|CLOUDABI_FDFLAG_NONBLOCK
value|0x4
end_define

begin_define
define|#
directive|define
name|CLOUDABI_FDFLAG_RSYNC
value|0x8
end_define

begin_define
define|#
directive|define
name|CLOUDABI_FDFLAG_SYNC
value|0x10
end_define

begin_comment
comment|// fdstat_put() flags.
end_comment

begin_define
define|#
directive|define
name|CLOUDABI_FDSTAT_FLAGS
value|0x1
end_define

begin_define
define|#
directive|define
name|CLOUDABI_FDSTAT_RIGHTS
value|0x2
end_define

begin_comment
comment|// filestat_put() flags.
end_comment

begin_define
define|#
directive|define
name|CLOUDABI_FILESTAT_ATIM
value|0x1
end_define

begin_define
define|#
directive|define
name|CLOUDABI_FILESTAT_ATIM_NOW
value|0x2
end_define

begin_define
define|#
directive|define
name|CLOUDABI_FILESTAT_MTIM
value|0x4
end_define

begin_define
define|#
directive|define
name|CLOUDABI_FILESTAT_MTIM_NOW
value|0x8
end_define

begin_define
define|#
directive|define
name|CLOUDABI_FILESTAT_SIZE
value|0x10
end_define

begin_comment
comment|// File types returned through struct stat::st_mode.
end_comment

begin_define
define|#
directive|define
name|CLOUDABI_FILETYPE_UNKNOWN
value|0
end_define

begin_define
define|#
directive|define
name|CLOUDABI_FILETYPE_BLOCK_DEVICE
value|0x10
end_define

begin_define
define|#
directive|define
name|CLOUDABI_FILETYPE_CHARACTER_DEVICE
value|0x11
end_define

begin_define
define|#
directive|define
name|CLOUDABI_FILETYPE_DIRECTORY
value|0x20
end_define

begin_define
define|#
directive|define
name|CLOUDABI_FILETYPE_FIFO
value|0x30
end_define

begin_define
define|#
directive|define
name|CLOUDABI_FILETYPE_POLL
value|0x40
end_define

begin_define
define|#
directive|define
name|CLOUDABI_FILETYPE_PROCESS
value|0x50
end_define

begin_define
define|#
directive|define
name|CLOUDABI_FILETYPE_REGULAR_FILE
value|0x60
end_define

begin_define
define|#
directive|define
name|CLOUDABI_FILETYPE_SHARED_MEMORY
value|0x70
end_define

begin_define
define|#
directive|define
name|CLOUDABI_FILETYPE_SOCKET_DGRAM
value|0x80
end_define

begin_define
define|#
directive|define
name|CLOUDABI_FILETYPE_SOCKET_SEQPACKET
value|0x81
end_define

begin_define
define|#
directive|define
name|CLOUDABI_FILETYPE_SOCKET_STREAM
value|0x82
end_define

begin_define
define|#
directive|define
name|CLOUDABI_FILETYPE_SYMBOLIC_LINK
value|0x90
end_define

begin_comment
comment|// Read-write lock related constants.
end_comment

begin_define
define|#
directive|define
name|CLOUDABI_LOCK_UNLOCKED
value|0
end_define

begin_comment
comment|// Lock is unlocked.
end_comment

begin_define
define|#
directive|define
name|CLOUDABI_LOCK_WRLOCKED
value|0x40000000
end_define

begin_comment
comment|// Lock is write locked.
end_comment

begin_define
define|#
directive|define
name|CLOUDABI_LOCK_KERNEL_MANAGED
value|0x80000000
end_define

begin_comment
comment|// Lock has waiters.
end_comment

begin_define
define|#
directive|define
name|CLOUDABI_LOCK_BOGUS
value|0x80000000
end_define

begin_comment
comment|// Lock is broken.
end_comment

begin_comment
comment|// Lookup properties for *at() functions.
end_comment

begin_define
define|#
directive|define
name|CLOUDABI_LOOKUP_SYMLINK_FOLLOW
value|(UINT64_C(0x1)<< 32)
end_define

begin_comment
comment|// Open flags for openat(), etc.
end_comment

begin_define
define|#
directive|define
name|CLOUDABI_O_CREAT
value|0x1
end_define

begin_define
define|#
directive|define
name|CLOUDABI_O_DIRECTORY
value|0x2
end_define

begin_define
define|#
directive|define
name|CLOUDABI_O_EXCL
value|0x4
end_define

begin_define
define|#
directive|define
name|CLOUDABI_O_TRUNC
value|0x8
end_define

begin_comment
comment|// File descriptor returned to pdfork()'s child process.
end_comment

begin_define
define|#
directive|define
name|CLOUDABI_PROCESS_CHILD
value|0xffffffff
end_define

begin_comment
comment|// mmap() map flags.
end_comment

begin_define
define|#
directive|define
name|CLOUDABI_MAP_ANON
value|0x1
end_define

begin_define
define|#
directive|define
name|CLOUDABI_MAP_FIXED
value|0x2
end_define

begin_define
define|#
directive|define
name|CLOUDABI_MAP_PRIVATE
value|0x4
end_define

begin_define
define|#
directive|define
name|CLOUDABI_MAP_SHARED
value|0x8
end_define

begin_comment
comment|// File descriptor that must be passed in when using CLOUDABI_MAP_ANON.
end_comment

begin_define
define|#
directive|define
name|CLOUDABI_MAP_ANON_FD
value|0xffffffff
end_define

begin_comment
comment|// msync() flags.
end_comment

begin_define
define|#
directive|define
name|CLOUDABI_MS_ASYNC
value|0x1
end_define

begin_define
define|#
directive|define
name|CLOUDABI_MS_INVALIDATE
value|0x2
end_define

begin_define
define|#
directive|define
name|CLOUDABI_MS_SYNC
value|0x4
end_define

begin_comment
comment|// send() and recv() flags.
end_comment

begin_define
define|#
directive|define
name|CLOUDABI_MSG_CTRUNC
value|0x1
end_define

begin_comment
comment|// Control data truncated.
end_comment

begin_define
define|#
directive|define
name|CLOUDABI_MSG_EOR
value|0x2
end_define

begin_comment
comment|// Terminates a record.
end_comment

begin_define
define|#
directive|define
name|CLOUDABI_MSG_PEEK
value|0x4
end_define

begin_comment
comment|// Leave received data in queue.
end_comment

begin_define
define|#
directive|define
name|CLOUDABI_MSG_TRUNC
value|0x8
end_define

begin_comment
comment|// Normal data truncated.
end_comment

begin_define
define|#
directive|define
name|CLOUDABI_MSG_WAITALL
value|0x10
end_define

begin_comment
comment|// Attempt to fill the read buffer.
end_comment

begin_comment
comment|// mmap()/mprotect() protection flags.
end_comment

begin_define
define|#
directive|define
name|CLOUDABI_PROT_EXEC
value|0x1
end_define

begin_define
define|#
directive|define
name|CLOUDABI_PROT_WRITE
value|0x2
end_define

begin_define
define|#
directive|define
name|CLOUDABI_PROT_READ
value|0x4
end_define

begin_comment
comment|// File descriptor capabilities/rights.
end_comment

begin_define
define|#
directive|define
name|CLOUDABI_RIGHT_BIT
parameter_list|(
name|bit
parameter_list|)
value|(UINT64_C(1)<< (bit))
end_define

begin_define
define|#
directive|define
name|CLOUDABI_RIGHT_FD_DATASYNC
value|CLOUDABI_RIGHT_BIT(0)
end_define

begin_define
define|#
directive|define
name|CLOUDABI_RIGHT_FD_READ
value|CLOUDABI_RIGHT_BIT(1)
end_define

begin_define
define|#
directive|define
name|CLOUDABI_RIGHT_FD_SEEK
value|CLOUDABI_RIGHT_BIT(2)
end_define

begin_define
define|#
directive|define
name|CLOUDABI_RIGHT_FD_STAT_PUT_FLAGS
value|CLOUDABI_RIGHT_BIT(3)
end_define

begin_define
define|#
directive|define
name|CLOUDABI_RIGHT_FD_SYNC
value|CLOUDABI_RIGHT_BIT(4)
end_define

begin_define
define|#
directive|define
name|CLOUDABI_RIGHT_FD_TELL
value|CLOUDABI_RIGHT_BIT(5)
end_define

begin_define
define|#
directive|define
name|CLOUDABI_RIGHT_FD_WRITE
value|CLOUDABI_RIGHT_BIT(6)
end_define

begin_define
define|#
directive|define
name|CLOUDABI_RIGHT_FILE_ADVISE
value|CLOUDABI_RIGHT_BIT(7)
end_define

begin_define
define|#
directive|define
name|CLOUDABI_RIGHT_FILE_ALLOCATE
value|CLOUDABI_RIGHT_BIT(8)
end_define

begin_define
define|#
directive|define
name|CLOUDABI_RIGHT_FILE_CREATE_DIRECTORY
value|CLOUDABI_RIGHT_BIT(9)
end_define

begin_define
define|#
directive|define
name|CLOUDABI_RIGHT_FILE_CREATE_FILE
value|CLOUDABI_RIGHT_BIT(10)
end_define

begin_define
define|#
directive|define
name|CLOUDABI_RIGHT_FILE_CREATE_FIFO
value|CLOUDABI_RIGHT_BIT(11)
end_define

begin_define
define|#
directive|define
name|CLOUDABI_RIGHT_FILE_LINK_SOURCE
value|CLOUDABI_RIGHT_BIT(12)
end_define

begin_define
define|#
directive|define
name|CLOUDABI_RIGHT_FILE_LINK_TARGET
value|CLOUDABI_RIGHT_BIT(13)
end_define

begin_define
define|#
directive|define
name|CLOUDABI_RIGHT_FILE_OPEN
value|CLOUDABI_RIGHT_BIT(14)
end_define

begin_define
define|#
directive|define
name|CLOUDABI_RIGHT_FILE_READDIR
value|CLOUDABI_RIGHT_BIT(15)
end_define

begin_define
define|#
directive|define
name|CLOUDABI_RIGHT_FILE_READLINK
value|CLOUDABI_RIGHT_BIT(16)
end_define

begin_define
define|#
directive|define
name|CLOUDABI_RIGHT_FILE_RENAME_SOURCE
value|CLOUDABI_RIGHT_BIT(17)
end_define

begin_define
define|#
directive|define
name|CLOUDABI_RIGHT_FILE_RENAME_TARGET
value|CLOUDABI_RIGHT_BIT(18)
end_define

begin_define
define|#
directive|define
name|CLOUDABI_RIGHT_FILE_STAT_FGET
value|CLOUDABI_RIGHT_BIT(19)
end_define

begin_define
define|#
directive|define
name|CLOUDABI_RIGHT_FILE_STAT_FPUT_SIZE
value|CLOUDABI_RIGHT_BIT(20)
end_define

begin_define
define|#
directive|define
name|CLOUDABI_RIGHT_FILE_STAT_FPUT_TIMES
value|CLOUDABI_RIGHT_BIT(21)
end_define

begin_define
define|#
directive|define
name|CLOUDABI_RIGHT_FILE_STAT_GET
value|CLOUDABI_RIGHT_BIT(22)
end_define

begin_define
define|#
directive|define
name|CLOUDABI_RIGHT_FILE_STAT_PUT_TIMES
value|CLOUDABI_RIGHT_BIT(23)
end_define

begin_define
define|#
directive|define
name|CLOUDABI_RIGHT_FILE_SYMLINK
value|CLOUDABI_RIGHT_BIT(24)
end_define

begin_define
define|#
directive|define
name|CLOUDABI_RIGHT_FILE_UNLINK
value|CLOUDABI_RIGHT_BIT(25)
end_define

begin_define
define|#
directive|define
name|CLOUDABI_RIGHT_MEM_MAP
value|CLOUDABI_RIGHT_BIT(26)
end_define

begin_define
define|#
directive|define
name|CLOUDABI_RIGHT_MEM_MAP_EXEC
value|CLOUDABI_RIGHT_BIT(27)
end_define

begin_define
define|#
directive|define
name|CLOUDABI_RIGHT_POLL_FD_READWRITE
value|CLOUDABI_RIGHT_BIT(28)
end_define

begin_define
define|#
directive|define
name|CLOUDABI_RIGHT_POLL_MODIFY
value|CLOUDABI_RIGHT_BIT(29)
end_define

begin_define
define|#
directive|define
name|CLOUDABI_RIGHT_POLL_PROC_TERMINATE
value|CLOUDABI_RIGHT_BIT(30)
end_define

begin_define
define|#
directive|define
name|CLOUDABI_RIGHT_POLL_WAIT
value|CLOUDABI_RIGHT_BIT(31)
end_define

begin_define
define|#
directive|define
name|CLOUDABI_RIGHT_PROC_EXEC
value|CLOUDABI_RIGHT_BIT(32)
end_define

begin_define
define|#
directive|define
name|CLOUDABI_RIGHT_SOCK_ACCEPT
value|CLOUDABI_RIGHT_BIT(33)
end_define

begin_define
define|#
directive|define
name|CLOUDABI_RIGHT_SOCK_BIND_DIRECTORY
value|CLOUDABI_RIGHT_BIT(34)
end_define

begin_define
define|#
directive|define
name|CLOUDABI_RIGHT_SOCK_BIND_SOCKET
value|CLOUDABI_RIGHT_BIT(35)
end_define

begin_define
define|#
directive|define
name|CLOUDABI_RIGHT_SOCK_CONNECT_DIRECTORY
value|CLOUDABI_RIGHT_BIT(36)
end_define

begin_define
define|#
directive|define
name|CLOUDABI_RIGHT_SOCK_CONNECT_SOCKET
value|CLOUDABI_RIGHT_BIT(37)
end_define

begin_define
define|#
directive|define
name|CLOUDABI_RIGHT_SOCK_LISTEN
value|CLOUDABI_RIGHT_BIT(38)
end_define

begin_define
define|#
directive|define
name|CLOUDABI_RIGHT_SOCK_SHUTDOWN
value|CLOUDABI_RIGHT_BIT(39)
end_define

begin_define
define|#
directive|define
name|CLOUDABI_RIGHT_SOCK_STAT_GET
value|CLOUDABI_RIGHT_BIT(40)
end_define

begin_comment
comment|// Socket shutdown flags.
end_comment

begin_define
define|#
directive|define
name|CLOUDABI_SHUT_RD
value|0x1
end_define

begin_define
define|#
directive|define
name|CLOUDABI_SHUT_WR
value|0x2
end_define

begin_comment
comment|// Signals.
end_comment

begin_define
define|#
directive|define
name|CLOUDABI_SIGABRT
value|1
end_define

begin_define
define|#
directive|define
name|CLOUDABI_SIGALRM
value|2
end_define

begin_define
define|#
directive|define
name|CLOUDABI_SIGBUS
value|3
end_define

begin_define
define|#
directive|define
name|CLOUDABI_SIGCHLD
value|4
end_define

begin_define
define|#
directive|define
name|CLOUDABI_SIGCONT
value|5
end_define

begin_define
define|#
directive|define
name|CLOUDABI_SIGFPE
value|6
end_define

begin_define
define|#
directive|define
name|CLOUDABI_SIGHUP
value|7
end_define

begin_define
define|#
directive|define
name|CLOUDABI_SIGILL
value|8
end_define

begin_define
define|#
directive|define
name|CLOUDABI_SIGINT
value|9
end_define

begin_define
define|#
directive|define
name|CLOUDABI_SIGKILL
value|10
end_define

begin_define
define|#
directive|define
name|CLOUDABI_SIGPIPE
value|11
end_define

begin_define
define|#
directive|define
name|CLOUDABI_SIGQUIT
value|12
end_define

begin_define
define|#
directive|define
name|CLOUDABI_SIGSEGV
value|13
end_define

begin_define
define|#
directive|define
name|CLOUDABI_SIGSTOP
value|14
end_define

begin_define
define|#
directive|define
name|CLOUDABI_SIGSYS
value|15
end_define

begin_define
define|#
directive|define
name|CLOUDABI_SIGTERM
value|16
end_define

begin_define
define|#
directive|define
name|CLOUDABI_SIGTRAP
value|17
end_define

begin_define
define|#
directive|define
name|CLOUDABI_SIGTSTP
value|18
end_define

begin_define
define|#
directive|define
name|CLOUDABI_SIGTTIN
value|19
end_define

begin_define
define|#
directive|define
name|CLOUDABI_SIGTTOU
value|20
end_define

begin_define
define|#
directive|define
name|CLOUDABI_SIGURG
value|21
end_define

begin_define
define|#
directive|define
name|CLOUDABI_SIGUSR1
value|22
end_define

begin_define
define|#
directive|define
name|CLOUDABI_SIGUSR2
value|23
end_define

begin_define
define|#
directive|define
name|CLOUDABI_SIGVTALRM
value|24
end_define

begin_define
define|#
directive|define
name|CLOUDABI_SIGXCPU
value|25
end_define

begin_define
define|#
directive|define
name|CLOUDABI_SIGXFSZ
value|26
end_define

begin_comment
comment|// sockstat() flags.
end_comment

begin_define
define|#
directive|define
name|CLOUDABI_SOCKSTAT_CLEAR_ERROR
value|0x1
end_define

begin_comment
comment|// sockstat() state.
end_comment

begin_define
define|#
directive|define
name|CLOUDABI_SOCKSTAT_ACCEPTCONN
value|0x1
end_define

begin_comment
comment|// cloudabi_subscription_t flags.
end_comment

begin_define
define|#
directive|define
name|CLOUDABI_SUBSCRIPTION_ADD
value|0x1
end_define

begin_define
define|#
directive|define
name|CLOUDABI_SUBSCRIPTION_CLEAR
value|0x2
end_define

begin_define
define|#
directive|define
name|CLOUDABI_SUBSCRIPTION_DELETE
value|0x4
end_define

begin_define
define|#
directive|define
name|CLOUDABI_SUBSCRIPTION_DISABLE
value|0x8
end_define

begin_define
define|#
directive|define
name|CLOUDABI_SUBSCRIPTION_ENABLE
value|0x10
end_define

begin_define
define|#
directive|define
name|CLOUDABI_SUBSCRIPTION_ONESHOT
value|0x20
end_define

begin_comment
comment|// cloudabi_subscription_t::clock.flags.
end_comment

begin_define
define|#
directive|define
name|CLOUDABI_SUBSCRIPTION_CLOCK_ABSTIME
value|0x1
end_define

begin_comment
comment|// cloudabi_subscription_t::fd_readwrite.flags.
end_comment

begin_define
define|#
directive|define
name|CLOUDABI_SUBSCRIPTION_FD_READWRITE_POLL
value|0x1
end_define

begin_comment
comment|// unlinkat().
end_comment

begin_define
define|#
directive|define
name|CLOUDABI_UNLINK_REMOVEDIR
value|0x1
end_define

begin_comment
comment|// Seeking.
end_comment

begin_define
define|#
directive|define
name|CLOUDABI_WHENCE_CUR
value|1
end_define

begin_define
define|#
directive|define
name|CLOUDABI_WHENCE_END
value|2
end_define

begin_define
define|#
directive|define
name|CLOUDABI_WHENCE_SET
value|3
end_define

begin_typedef
typedef|typedef
name|uint8_t
name|cloudabi_advice_t
typedef|;
end_typedef

begin_comment
comment|// posix_fadvise() and posix_madvise().
end_comment

begin_typedef
typedef|typedef
name|uint32_t
name|cloudabi_backlog_t
typedef|;
end_typedef

begin_comment
comment|// listen().
end_comment

begin_typedef
typedef|typedef
name|uint32_t
name|cloudabi_clockid_t
typedef|;
end_typedef

begin_comment
comment|// clock_*().
end_comment

begin_typedef
typedef|typedef
name|uint32_t
name|cloudabi_condvar_t
typedef|;
end_typedef

begin_comment
comment|// pthread_cond_*().
end_comment

begin_typedef
typedef|typedef
name|uint64_t
name|cloudabi_device_t
typedef|;
end_typedef

begin_comment
comment|// struct stat::st_dev.
end_comment

begin_typedef
typedef|typedef
name|uint64_t
name|cloudabi_dircookie_t
typedef|;
end_typedef

begin_comment
comment|// readdir().
end_comment

begin_typedef
typedef|typedef
name|uint16_t
name|cloudabi_errno_t
typedef|;
end_typedef

begin_comment
comment|// errno.
end_comment

begin_typedef
typedef|typedef
name|uint8_t
name|cloudabi_eventtype_t
typedef|;
end_typedef

begin_comment
comment|// poll().
end_comment

begin_typedef
typedef|typedef
name|uint32_t
name|cloudabi_exitcode_t
typedef|;
end_typedef

begin_comment
comment|// _exit() and _Exit().
end_comment

begin_typedef
typedef|typedef
name|uint32_t
name|cloudabi_fd_t
typedef|;
end_typedef

begin_comment
comment|// File descriptors.
end_comment

begin_typedef
typedef|typedef
name|uint16_t
name|cloudabi_fdflags_t
typedef|;
end_typedef

begin_comment
comment|// cloudabi_fdstat_t.
end_comment

begin_typedef
typedef|typedef
name|uint16_t
name|cloudabi_fdsflags_t
typedef|;
end_typedef

begin_comment
comment|// fd_stat_put().
end_comment

begin_typedef
typedef|typedef
name|int64_t
name|cloudabi_filedelta_t
typedef|;
end_typedef

begin_comment
comment|// lseek().
end_comment

begin_typedef
typedef|typedef
name|uint64_t
name|cloudabi_filesize_t
typedef|;
end_typedef

begin_comment
comment|// ftruncate(), struct stat::st_size.
end_comment

begin_typedef
typedef|typedef
name|uint8_t
name|cloudabi_filetype_t
typedef|;
end_typedef

begin_comment
comment|// struct stat::st_mode.
end_comment

begin_typedef
typedef|typedef
name|uint16_t
name|cloudabi_fsflags_t
typedef|;
end_typedef

begin_comment
comment|// file_stat_put().
end_comment

begin_typedef
typedef|typedef
name|uint64_t
name|cloudabi_inode_t
typedef|;
end_typedef

begin_comment
comment|// struct stat::st_ino.
end_comment

begin_typedef
typedef|typedef
name|uint32_t
name|cloudabi_linkcount_t
typedef|;
end_typedef

begin_comment
comment|// struct stat::st_nlink.
end_comment

begin_typedef
typedef|typedef
name|uint32_t
name|cloudabi_lock_t
typedef|;
end_typedef

begin_comment
comment|// pthread_{mutex,rwlock}_*().
end_comment

begin_typedef
typedef|typedef
name|uint64_t
name|cloudabi_lookup_t
typedef|;
end_typedef

begin_comment
comment|// openat(), linkat(), etc.
end_comment

begin_typedef
typedef|typedef
name|uint8_t
name|cloudabi_mflags_t
typedef|;
end_typedef

begin_comment
comment|// mmap().
end_comment

begin_typedef
typedef|typedef
name|uint8_t
name|cloudabi_mprot_t
typedef|;
end_typedef

begin_comment
comment|// mmap().
end_comment

begin_typedef
typedef|typedef
name|uint8_t
name|cloudabi_msflags_t
typedef|;
end_typedef

begin_comment
comment|// msync().
end_comment

begin_typedef
typedef|typedef
name|uint16_t
name|cloudabi_msgflags_t
typedef|;
end_typedef

begin_comment
comment|// send() and recv().
end_comment

begin_typedef
typedef|typedef
name|uint32_t
name|cloudabi_nthreads_t
typedef|;
end_typedef

begin_comment
comment|// pthread_cond_*().
end_comment

begin_typedef
typedef|typedef
name|uint16_t
name|cloudabi_oflags_t
typedef|;
end_typedef

begin_comment
comment|// openat(), etc.
end_comment

begin_typedef
typedef|typedef
name|uint64_t
name|cloudabi_rights_t
typedef|;
end_typedef

begin_comment
comment|// File descriptor rights.
end_comment

begin_typedef
typedef|typedef
name|uint8_t
name|cloudabi_sa_family_t
typedef|;
end_typedef

begin_comment
comment|// Socket address family.
end_comment

begin_typedef
typedef|typedef
name|uint8_t
name|cloudabi_sdflags_t
typedef|;
end_typedef

begin_comment
comment|// shutdown().
end_comment

begin_typedef
typedef|typedef
name|uint8_t
name|cloudabi_ssflags_t
typedef|;
end_typedef

begin_comment
comment|// sockstat().
end_comment

begin_typedef
typedef|typedef
name|uint8_t
name|cloudabi_signal_t
typedef|;
end_typedef

begin_comment
comment|// raise().
end_comment

begin_typedef
typedef|typedef
name|uint32_t
name|cloudabi_tid_t
typedef|;
end_typedef

begin_comment
comment|// Thread ID.
end_comment

begin_typedef
typedef|typedef
name|uint64_t
name|cloudabi_timestamp_t
typedef|;
end_typedef

begin_comment
comment|// clock_*(), struct stat::st_*tim.
end_comment

begin_typedef
typedef|typedef
name|uint8_t
name|cloudabi_ulflags_t
typedef|;
end_typedef

begin_comment
comment|// unlinkat().
end_comment

begin_typedef
typedef|typedef
name|uint64_t
name|cloudabi_userdata_t
typedef|;
end_typedef

begin_comment
comment|// User-supplied data for callbacks.
end_comment

begin_typedef
typedef|typedef
name|uint8_t
name|cloudabi_whence_t
typedef|;
end_typedef

begin_comment
comment|// lseek().
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
name|offset
parameter_list|)
define|\
value|static_assert(offsetof(cloudabi_##type, field) == (offset), \                 "Offset incorrect")
end_define

begin_define
define|#
directive|define
name|ASSERT_SIZE
parameter_list|(
name|type
parameter_list|,
name|size
parameter_list|)
define|\
value|static_assert(sizeof(cloudabi_##type) == (size), "Size incorrect")
end_define

begin_comment
comment|// Directory entries.
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|MEMBER
argument_list|(
argument|cloudabi_dircookie_t
argument_list|)
name|d_next
expr_stmt|;
comment|// Cookie of the next entry.
name|MEMBER
argument_list|(
argument|cloudabi_inode_t
argument_list|)
name|d_ino
expr_stmt|;
comment|// Inode number of the current entry.
name|MEMBER
argument_list|(
argument|uint32_t
argument_list|)
name|d_namlen
expr_stmt|;
comment|// Length of the name of the current entry.
name|MEMBER
argument_list|(
argument|cloudabi_filetype_t
argument_list|)
name|d_type
expr_stmt|;
comment|// File type of the current entry.
block|}
name|cloudabi_dirent_t
typedef|;
end_typedef

begin_expr_stmt
name|ASSERT_OFFSET
argument_list|(
name|dirent_t
argument_list|,
name|d_next
argument_list|,
literal|0
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|ASSERT_OFFSET
argument_list|(
name|dirent_t
argument_list|,
name|d_ino
argument_list|,
literal|8
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|ASSERT_OFFSET
argument_list|(
name|dirent_t
argument_list|,
name|d_namlen
argument_list|,
literal|16
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|ASSERT_OFFSET
argument_list|(
name|dirent_t
argument_list|,
name|d_type
argument_list|,
literal|20
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|ASSERT_SIZE
argument_list|(
name|dirent_t
argument_list|,
literal|24
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|// File descriptor status.
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|MEMBER
argument_list|(
argument|cloudabi_filetype_t
argument_list|)
name|fs_filetype
expr_stmt|;
comment|// File descriptor type.
name|MEMBER
argument_list|(
argument|cloudabi_fdflags_t
argument_list|)
name|fs_flags
expr_stmt|;
comment|// Non-blocking mode, etc.
name|MEMBER
argument_list|(
argument|cloudabi_rights_t
argument_list|)
name|fs_rights_base
expr_stmt|;
comment|// Base rights.
name|MEMBER
argument_list|(
argument|cloudabi_rights_t
argument_list|)
name|fs_rights_inheriting
expr_stmt|;
comment|// Inheriting rights.
block|}
name|cloudabi_fdstat_t
typedef|;
end_typedef

begin_expr_stmt
name|ASSERT_OFFSET
argument_list|(
name|fdstat_t
argument_list|,
name|fs_filetype
argument_list|,
literal|0
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|ASSERT_OFFSET
argument_list|(
name|fdstat_t
argument_list|,
name|fs_flags
argument_list|,
literal|2
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|ASSERT_OFFSET
argument_list|(
name|fdstat_t
argument_list|,
name|fs_rights_base
argument_list|,
literal|8
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|ASSERT_OFFSET
argument_list|(
name|fdstat_t
argument_list|,
name|fs_rights_inheriting
argument_list|,
literal|16
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|ASSERT_SIZE
argument_list|(
name|fdstat_t
argument_list|,
literal|24
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|// File status.
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|MEMBER
argument_list|(
argument|cloudabi_device_t
argument_list|)
name|st_dev
expr_stmt|;
comment|// Device storing the file.
name|MEMBER
argument_list|(
argument|cloudabi_inode_t
argument_list|)
name|st_ino
expr_stmt|;
comment|// Inode of the file.
name|MEMBER
argument_list|(
argument|cloudabi_filetype_t
argument_list|)
name|st_filetype
expr_stmt|;
comment|// File type.
name|MEMBER
argument_list|(
argument|cloudabi_linkcount_t
argument_list|)
name|st_nlink
expr_stmt|;
comment|// Number of hardlinks.
name|MEMBER
argument_list|(
argument|cloudabi_filesize_t
argument_list|)
name|st_size
expr_stmt|;
comment|// Size of the file.
name|MEMBER
argument_list|(
argument|cloudabi_timestamp_t
argument_list|)
name|st_atim
expr_stmt|;
comment|// Access time.
name|MEMBER
argument_list|(
argument|cloudabi_timestamp_t
argument_list|)
name|st_mtim
expr_stmt|;
comment|// Modification time.
name|MEMBER
argument_list|(
argument|cloudabi_timestamp_t
argument_list|)
name|st_ctim
expr_stmt|;
comment|// Change time.
block|}
name|cloudabi_filestat_t
typedef|;
end_typedef

begin_expr_stmt
name|ASSERT_OFFSET
argument_list|(
name|filestat_t
argument_list|,
name|st_dev
argument_list|,
literal|0
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|ASSERT_OFFSET
argument_list|(
name|filestat_t
argument_list|,
name|st_ino
argument_list|,
literal|8
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|ASSERT_OFFSET
argument_list|(
name|filestat_t
argument_list|,
name|st_filetype
argument_list|,
literal|16
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|ASSERT_OFFSET
argument_list|(
name|filestat_t
argument_list|,
name|st_nlink
argument_list|,
literal|20
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|ASSERT_OFFSET
argument_list|(
name|filestat_t
argument_list|,
name|st_size
argument_list|,
literal|24
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|ASSERT_OFFSET
argument_list|(
name|filestat_t
argument_list|,
name|st_atim
argument_list|,
literal|32
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|ASSERT_OFFSET
argument_list|(
name|filestat_t
argument_list|,
name|st_mtim
argument_list|,
literal|40
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|ASSERT_OFFSET
argument_list|(
name|filestat_t
argument_list|,
name|st_ctim
argument_list|,
literal|48
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|ASSERT_SIZE
argument_list|(
name|filestat_t
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
argument|cloudabi_sa_family_t
argument_list|)
name|sa_family
expr_stmt|;
union|union
block|{
struct|struct
block|{
comment|// IPv4 address and port number.
name|MEMBER
argument_list|(
argument|uint8_t
argument_list|)
name|addr
index|[
literal|4
index|]
expr_stmt|;
name|MEMBER
argument_list|(
argument|uint16_t
argument_list|)
name|port
expr_stmt|;
block|}
name|sa_inet
struct|;
struct|struct
block|{
comment|// IPv6 address and port number.
comment|// TODO(ed): What about the flow info and scope ID?
name|MEMBER
argument_list|(
argument|uint8_t
argument_list|)
name|addr
index|[
literal|16
index|]
expr_stmt|;
name|MEMBER
argument_list|(
argument|uint16_t
argument_list|)
name|port
expr_stmt|;
block|}
name|sa_inet6
struct|;
block|}
union|;
block|}
name|cloudabi_sockaddr_t
typedef|;
end_typedef

begin_expr_stmt
name|ASSERT_OFFSET
argument_list|(
name|sockaddr_t
argument_list|,
name|sa_family
argument_list|,
literal|0
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|ASSERT_OFFSET
argument_list|(
name|sockaddr_t
argument_list|,
name|sa_inet
operator|.
name|addr
argument_list|,
literal|2
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|ASSERT_OFFSET
argument_list|(
name|sockaddr_t
argument_list|,
name|sa_inet
operator|.
name|port
argument_list|,
literal|6
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|ASSERT_OFFSET
argument_list|(
name|sockaddr_t
argument_list|,
name|sa_inet6
operator|.
name|addr
argument_list|,
literal|2
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|ASSERT_OFFSET
argument_list|(
name|sockaddr_t
argument_list|,
name|sa_inet6
operator|.
name|port
argument_list|,
literal|18
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|ASSERT_SIZE
argument_list|(
name|sockaddr_t
argument_list|,
literal|20
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|// Socket status.
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|MEMBER
argument_list|(
argument|cloudabi_sockaddr_t
argument_list|)
name|ss_sockname
expr_stmt|;
comment|// Socket address.
name|MEMBER
argument_list|(
argument|cloudabi_sockaddr_t
argument_list|)
name|ss_peername
expr_stmt|;
comment|// Peer address.
name|MEMBER
argument_list|(
argument|cloudabi_errno_t
argument_list|)
name|ss_error
expr_stmt|;
comment|// Current error state.
name|MEMBER
argument_list|(
argument|uint32_t
argument_list|)
name|ss_state
expr_stmt|;
comment|// State flags.
block|}
name|cloudabi_sockstat_t
typedef|;
end_typedef

begin_expr_stmt
name|ASSERT_OFFSET
argument_list|(
name|sockstat_t
argument_list|,
name|ss_sockname
argument_list|,
literal|0
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|ASSERT_OFFSET
argument_list|(
name|sockstat_t
argument_list|,
name|ss_peername
argument_list|,
literal|20
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|ASSERT_OFFSET
argument_list|(
name|sockstat_t
argument_list|,
name|ss_error
argument_list|,
literal|40
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|ASSERT_OFFSET
argument_list|(
name|sockstat_t
argument_list|,
name|ss_state
argument_list|,
literal|44
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|ASSERT_SIZE
argument_list|(
name|sockstat_t
argument_list|,
literal|48
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

begin_endif
endif|#
directive|endif
end_endif

end_unit

