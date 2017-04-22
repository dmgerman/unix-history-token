begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- sanitizer_linux.h ---------------------------------------*- C++ -*-===//
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
comment|// Linux-specific syscall wrappers and classes.
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
name|SANITIZER_LINUX_H
end_ifndef

begin_define
define|#
directive|define
name|SANITIZER_LINUX_H
end_define

begin_include
include|#
directive|include
file|"sanitizer_platform.h"
end_include

begin_if
if|#
directive|if
name|SANITIZER_FREEBSD
operator|||
name|SANITIZER_LINUX
end_if

begin_include
include|#
directive|include
file|"sanitizer_common.h"
end_include

begin_include
include|#
directive|include
file|"sanitizer_internal_defs.h"
end_include

begin_include
include|#
directive|include
file|"sanitizer_posix.h"
end_include

begin_include
include|#
directive|include
file|"sanitizer_platform_limits_posix.h"
end_include

begin_struct_decl
struct_decl|struct
name|link_map
struct_decl|;
end_struct_decl

begin_comment
comment|// Opaque type returned by dlopen().
end_comment

begin_struct_decl
struct_decl|struct
name|sigaltstack
struct_decl|;
end_struct_decl

begin_decl_stmt
name|namespace
name|__sanitizer
block|{
comment|// Dirent structure for getdents(). Note that this structure is different from
comment|// the one in<dirent.h>, which is used by readdir().
struct_decl|struct
name|linux_dirent
struct_decl|;
comment|// Syscall wrappers.
name|uptr
name|internal_getdents
parameter_list|(
name|fd_t
name|fd
parameter_list|,
name|struct
name|linux_dirent
modifier|*
name|dirp
parameter_list|,
name|unsigned
name|int
name|count
parameter_list|)
function_decl|;
name|uptr
name|internal_sigaltstack
parameter_list|(
specifier|const
name|struct
name|sigaltstack
modifier|*
name|ss
parameter_list|,
name|struct
name|sigaltstack
modifier|*
name|oss
parameter_list|)
function_decl|;
name|uptr
name|internal_sigprocmask
parameter_list|(
name|int
name|how
parameter_list|,
name|__sanitizer_sigset_t
modifier|*
name|set
parameter_list|,
name|__sanitizer_sigset_t
modifier|*
name|oldset
parameter_list|)
function_decl|;
comment|// Linux-only syscalls.
if|#
directive|if
name|SANITIZER_LINUX
name|uptr
name|internal_prctl
parameter_list|(
name|int
name|option
parameter_list|,
name|uptr
name|arg2
parameter_list|,
name|uptr
name|arg3
parameter_list|,
name|uptr
name|arg4
parameter_list|,
name|uptr
name|arg5
parameter_list|)
function_decl|;
comment|// Used only by sanitizer_stoptheworld. Signal handlers that are actually used
comment|// (like the process-wide error reporting SEGV handler) must use
comment|// internal_sigaction instead.
name|int
name|internal_sigaction_norestorer
parameter_list|(
name|int
name|signum
parameter_list|,
specifier|const
name|void
modifier|*
name|act
parameter_list|,
name|void
modifier|*
name|oldact
parameter_list|)
function_decl|;
if|#
directive|if
operator|(
name|defined
argument_list|(
name|__x86_64__
argument_list|)
operator|||
name|SANITIZER_MIPS64
operator|)
operator|&&
operator|!
name|SANITIZER_GO
comment|// Uses a raw system call to avoid interceptors.
name|int
name|internal_sigaction_syscall
parameter_list|(
name|int
name|signum
parameter_list|,
specifier|const
name|void
modifier|*
name|act
parameter_list|,
name|void
modifier|*
name|oldact
parameter_list|)
function_decl|;
endif|#
directive|endif
name|void
name|internal_sigdelset
parameter_list|(
name|__sanitizer_sigset_t
modifier|*
name|set
parameter_list|,
name|int
name|signum
parameter_list|)
function_decl|;
if|#
directive|if
name|defined
argument_list|(
name|__x86_64__
argument_list|)
operator|||
name|defined
argument_list|(
name|__mips__
argument_list|)
operator|||
name|defined
argument_list|(
name|__aarch64__
argument_list|)
expr|\
operator|||
name|defined
argument_list|(
name|__powerpc64__
argument_list|)
operator|||
name|defined
argument_list|(
name|__s390__
argument_list|)
operator|||
name|defined
argument_list|(
name|__i386__
argument_list|)
expr|\
operator|||
name|defined
argument_list|(
name|__arm__
argument_list|)
name|uptr
name|internal_clone
parameter_list|(
name|int
function_decl|(
modifier|*
name|fn
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|)
parameter_list|,
name|void
modifier|*
name|child_stack
parameter_list|,
name|int
name|flags
parameter_list|,
name|void
modifier|*
name|arg
parameter_list|,
name|int
modifier|*
name|parent_tidptr
parameter_list|,
name|void
modifier|*
name|newtls
parameter_list|,
name|int
modifier|*
name|child_tidptr
parameter_list|)
function_decl|;
endif|#
directive|endif
endif|#
directive|endif
comment|// SANITIZER_LINUX
comment|// This class reads thread IDs from /proc/<pid>/task using only syscalls.
name|class
name|ThreadLister
block|{
name|public
label|:
name|explicit
name|ThreadLister
parameter_list|(
name|int
name|pid
parameter_list|)
function_decl|;
operator|~
name|ThreadLister
argument_list|()
expr_stmt|;
comment|// GetNextTID returns -1 if the list of threads is exhausted, or if there has
comment|// been an error.
name|int
name|GetNextTID
parameter_list|()
function_decl|;
name|void
name|Reset
parameter_list|()
function_decl|;
name|bool
name|error
parameter_list|()
function_decl|;
name|private
label|:
name|bool
name|GetDirectoryEntries
parameter_list|()
function_decl|;
name|int
name|pid_
decl_stmt|;
name|int
name|descriptor_
decl_stmt|;
name|InternalScopedBuffer
operator|<
name|char
operator|>
name|buffer_
expr_stmt|;
name|bool
name|error_
decl_stmt|;
name|struct
name|linux_dirent
modifier|*
name|entry_
decl_stmt|;
name|int
name|bytes_read_
decl_stmt|;
block|}
empty_stmt|;
comment|// Exposed for testing.
name|uptr
name|ThreadDescriptorSize
parameter_list|()
function_decl|;
name|uptr
name|ThreadSelf
parameter_list|()
function_decl|;
name|uptr
name|ThreadSelfOffset
parameter_list|()
function_decl|;
comment|// Matches a library's file name against a base name (stripping path and version
comment|// information).
name|bool
name|LibraryNameIs
parameter_list|(
specifier|const
name|char
modifier|*
name|full_name
parameter_list|,
specifier|const
name|char
modifier|*
name|base_name
parameter_list|)
function_decl|;
comment|// Call cb for each region mapped by map.
name|void
name|ForEachMappedRegion
parameter_list|(
name|link_map
modifier|*
name|map
parameter_list|,
name|void
function_decl|(
modifier|*
name|cb
function_decl|)
parameter_list|(
specifier|const
name|void
modifier|*
parameter_list|,
name|uptr
parameter_list|)
parameter_list|)
function_decl|;
block|}
end_decl_stmt

begin_comment
comment|// namespace __sanitizer
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// SANITIZER_FREEBSD || SANITIZER_LINUX
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// SANITIZER_LINUX_H
end_comment

end_unit

