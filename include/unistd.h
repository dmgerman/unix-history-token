begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1991, 1993, 1994  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)unistd.h	8.12 (Berkeley) 4/27/95  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_UNISTD_H_
end_ifndef

begin_define
define|#
directive|define
name|_UNISTD_H_
end_define

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<sys/unistd.h>
end_include

begin_define
define|#
directive|define
name|STDIN_FILENO
value|0
end_define

begin_comment
comment|/* standard input file descriptor */
end_comment

begin_define
define|#
directive|define
name|STDOUT_FILENO
value|1
end_define

begin_comment
comment|/* standard output file descriptor */
end_comment

begin_define
define|#
directive|define
name|STDERR_FILENO
value|2
end_define

begin_comment
comment|/* standard error file descriptor */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|NULL
end_ifndef

begin_define
define|#
directive|define
name|NULL
value|0
end_define

begin_comment
comment|/* null pointer constant */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|_POSIX_SOURCE
end_ifndef

begin_define
define|#
directive|define
name|F_ULOCK
value|0
end_define

begin_comment
comment|/* unlock locked section */
end_comment

begin_define
define|#
directive|define
name|F_LOCK
value|1
end_define

begin_comment
comment|/* lock a section for exclusive use */
end_comment

begin_define
define|#
directive|define
name|F_TLOCK
value|2
end_define

begin_comment
comment|/* test and lock a section for exclusive use */
end_comment

begin_define
define|#
directive|define
name|F_TEST
value|3
end_define

begin_comment
comment|/* test a section for locks by other procs */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
name|__BEGIN_DECLS
name|void
name|_exit
argument_list|(
name|int
argument_list|)
name|__dead2
decl_stmt|;
end_decl_stmt

begin_function_decl
name|int
name|access
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|unsigned
name|int
name|alarm
parameter_list|(
name|unsigned
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|chdir
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|chown
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|uid_t
parameter_list|,
name|gid_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|close
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|dup
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|dup2
parameter_list|(
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|eaccess
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|execl
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|execle
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|execlp
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|execv
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|char
modifier|*
specifier|const
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|execve
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|char
modifier|*
specifier|const
modifier|*
parameter_list|,
name|char
modifier|*
specifier|const
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|execvp
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|char
modifier|*
specifier|const
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|pid_t
name|fork
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|long
name|fpathconf
parameter_list|(
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|getcwd
parameter_list|(
name|char
modifier|*
parameter_list|,
name|size_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|gid_t
name|getegid
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|uid_t
name|geteuid
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|gid_t
name|getgid
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|getgroups
parameter_list|(
name|int
parameter_list|,
name|gid_t
index|[]
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|getlogin
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|pid_t
name|getpgrp
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|pid_t
name|getpid
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|pid_t
name|getppid
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|uid_t
name|getuid
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|isatty
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|link
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_ifndef
ifndef|#
directive|ifndef
name|_LSEEK_DECLARED
end_ifndef

begin_define
define|#
directive|define
name|_LSEEK_DECLARED
end_define

begin_function_decl
name|off_t
name|lseek
parameter_list|(
name|int
parameter_list|,
name|off_t
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
name|long
name|pathconf
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|pause
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|pipe
parameter_list|(
name|int
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ssize_t
name|read
parameter_list|(
name|int
parameter_list|,
name|void
modifier|*
parameter_list|,
name|size_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|rmdir
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|setgid
parameter_list|(
name|gid_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|setpgid
parameter_list|(
name|pid_t
parameter_list|,
name|pid_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|setproctitle
parameter_list|(
specifier|const
name|char
modifier|*
name|_fmt
parameter_list|,
modifier|...
parameter_list|)
function_decl|__printf0like
parameter_list|(
function_decl|1
operator|,
function_decl|2
end_function_decl

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_function_decl
name|pid_t
name|setsid
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|setuid
parameter_list|(
name|uid_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|unsigned
name|int
name|sleep
parameter_list|(
name|unsigned
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|long
name|sysconf
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|pid_t
name|tcgetpgrp
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|tcsetpgrp
parameter_list|(
name|int
parameter_list|,
name|pid_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|ttyname
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|unlink
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ssize_t
name|write
parameter_list|(
name|int
parameter_list|,
specifier|const
name|void
modifier|*
parameter_list|,
name|size_t
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|optarg
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* getopt(3) external variables */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|optind
decl_stmt|,
name|opterr
decl_stmt|,
name|optopt
decl_stmt|;
end_decl_stmt

begin_function_decl
name|int
name|getopt
parameter_list|(
name|int
parameter_list|,
name|char
modifier|*
specifier|const
type|[]
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_ifndef
ifndef|#
directive|ifndef
name|_POSIX_SOURCE
end_ifndef

begin_struct_decl
struct_decl|struct
name|timeval
struct_decl|;
end_struct_decl

begin_comment
comment|/* select(2) */
end_comment

begin_function_decl
name|int
name|acct
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|async_daemon
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|brk
parameter_list|(
specifier|const
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|chroot
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|size_t
name|confstr
parameter_list|(
name|int
parameter_list|,
name|char
modifier|*
parameter_list|,
name|size_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|crypt
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|__const
name|char
modifier|*
name|crypt_get_format
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|crypt_set_format
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|des_cipher
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|,
name|long
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|des_setkey
parameter_list|(
specifier|const
name|char
modifier|*
name|key
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|encrypt
parameter_list|(
name|char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|endusershell
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|exect
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|char
modifier|*
specifier|const
modifier|*
parameter_list|,
name|char
modifier|*
specifier|const
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|fchdir
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|fchown
parameter_list|(
name|int
parameter_list|,
name|uid_t
parameter_list|,
name|gid_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|fflagstostr
parameter_list|(
name|u_long
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|fsync
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_ifndef
ifndef|#
directive|ifndef
name|_FTRUNCATE_DECLARED
end_ifndef

begin_define
define|#
directive|define
name|_FTRUNCATE_DECLARED
end_define

begin_function_decl
name|int
name|ftruncate
parameter_list|(
name|int
parameter_list|,
name|off_t
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
name|int
name|getdomainname
parameter_list|(
name|char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|getdtablesize
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|getgrouplist
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|gid_t
parameter_list|,
name|gid_t
modifier|*
parameter_list|,
name|int
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|long
name|gethostid
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|gethostname
parameter_list|(
name|char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|getlogin_r
parameter_list|(
name|char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|mode_t
name|getmode
parameter_list|(
specifier|const
name|void
modifier|*
parameter_list|,
name|mode_t
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
name|int
name|getpagesize
argument_list|(
name|void
argument_list|)
name|__pure2
decl_stmt|;
end_decl_stmt

begin_function_decl
name|char
modifier|*
name|getpass
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|getpeereid
parameter_list|(
name|int
parameter_list|,
name|uid_t
modifier|*
parameter_list|,
name|gid_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|getpgid
parameter_list|(
name|pid_t
name|_pid
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|getresgid
parameter_list|(
name|gid_t
modifier|*
parameter_list|,
name|gid_t
modifier|*
parameter_list|,
name|gid_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|getresuid
parameter_list|(
name|uid_t
modifier|*
parameter_list|,
name|uid_t
modifier|*
parameter_list|,
name|uid_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|getsid
parameter_list|(
name|pid_t
name|_pid
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|getusershell
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|getwd
parameter_list|(
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* obsoleted by getcwd() */
end_comment

begin_function_decl
name|int
name|initgroups
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|gid_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|iruserok
parameter_list|(
name|unsigned
name|long
parameter_list|,
name|int
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|iruserok_sa
parameter_list|(
specifier|const
name|void
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|issetugid
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|lchown
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|uid_t
parameter_list|,
name|gid_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|lockf
parameter_list|(
name|int
parameter_list|,
name|int
parameter_list|,
name|off_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|mkdtemp
parameter_list|(
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|mknod
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|mode_t
parameter_list|,
name|dev_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|mkstemp
parameter_list|(
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|mkstemps
parameter_list|(
name|char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|mktemp
parameter_list|(
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|nfsclnt
parameter_list|(
name|int
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|nfssvc
parameter_list|(
name|int
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|nice
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ssize_t
name|pread
parameter_list|(
name|int
parameter_list|,
name|void
modifier|*
parameter_list|,
name|size_t
parameter_list|,
name|off_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|profil
parameter_list|(
name|char
modifier|*
parameter_list|,
name|size_t
parameter_list|,
name|vm_offset_t
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ssize_t
name|pwrite
parameter_list|(
name|int
parameter_list|,
specifier|const
name|void
modifier|*
parameter_list|,
name|size_t
parameter_list|,
name|off_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|rcmd
parameter_list|(
name|char
modifier|*
modifier|*
parameter_list|,
name|int
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|int
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|rcmd_af
parameter_list|(
name|char
modifier|*
modifier|*
parameter_list|,
name|int
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|int
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|rcmdsh
parameter_list|(
name|char
modifier|*
modifier|*
parameter_list|,
name|int
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|re_comp
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|re_exec
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|readlink
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|reboot
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|revoke
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|pid_t
name|rfork
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|pid_t
name|rfork_thread
parameter_list|(
name|int
parameter_list|,
name|void
modifier|*
parameter_list|,
name|int
function_decl|(
modifier|*
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|)
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|rresvport
parameter_list|(
name|int
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|rresvport_af
parameter_list|(
name|int
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ruserok
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|int
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
modifier|*
name|sbrk
parameter_list|(
name|intptr_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|select
parameter_list|(
name|int
parameter_list|,
name|fd_set
modifier|*
parameter_list|,
name|fd_set
modifier|*
parameter_list|,
name|fd_set
modifier|*
parameter_list|,
name|struct
name|timeval
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|setdomainname
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|setegid
parameter_list|(
name|gid_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|seteuid
parameter_list|(
name|uid_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|setgroups
parameter_list|(
name|int
parameter_list|,
specifier|const
name|gid_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|sethostid
parameter_list|(
name|long
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|sethostname
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|setkey
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|setlogin
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
modifier|*
name|setmode
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|setpgrp
parameter_list|(
name|pid_t
name|_pid
parameter_list|,
name|pid_t
name|_pgrp
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* obsoleted by setpgid() */
end_comment

begin_function_decl
name|int
name|setregid
parameter_list|(
name|gid_t
parameter_list|,
name|gid_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|setresgid
parameter_list|(
name|gid_t
parameter_list|,
name|gid_t
parameter_list|,
name|gid_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|setresuid
parameter_list|(
name|uid_t
parameter_list|,
name|uid_t
parameter_list|,
name|uid_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|setreuid
parameter_list|(
name|uid_t
parameter_list|,
name|uid_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|setrgid
parameter_list|(
name|gid_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|setruid
parameter_list|(
name|uid_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|setusershell
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|strtofflags
parameter_list|(
name|char
modifier|*
modifier|*
parameter_list|,
name|u_long
modifier|*
parameter_list|,
name|u_long
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|swapon
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|symlink
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|sync
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|syscall
parameter_list|(
name|int
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|off_t
name|__syscall
parameter_list|(
name|quad_t
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_ifndef
ifndef|#
directive|ifndef
name|_TRUNCATE_DECLARED
end_ifndef

begin_define
define|#
directive|define
name|_TRUNCATE_DECLARED
end_define

begin_function_decl
name|int
name|truncate
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|off_t
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
name|int
name|ttyslot
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|unsigned
name|int
name|ualarm
parameter_list|(
name|unsigned
name|int
parameter_list|,
name|unsigned
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|undelete
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|unwhiteout
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|usleep
parameter_list|(
name|unsigned
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
modifier|*
name|valloc
parameter_list|(
name|size_t
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* obsoleted by malloc() */
end_comment

begin_function_decl
name|pid_t
name|vfork
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|suboptarg
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* getsubopt(3) external variable */
end_comment

begin_function_decl
name|int
name|getsubopt
parameter_list|(
name|char
modifier|*
modifier|*
parameter_list|,
name|char
modifier|*
specifier|const
modifier|*
parameter_list|,
name|char
modifier|*
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_POSIX_SOURCE */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|optreset
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* getopt(3) external variable */
end_comment

begin_macro
name|__END_DECLS
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_UNISTD_H_ */
end_comment

end_unit

