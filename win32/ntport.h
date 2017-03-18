begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*$Header: /p/tcsh/cvsroot/tcsh/win32/ntport.h,v 1.15 2014/08/13 23:39:34 amold Exp $*/
end_comment

begin_comment
comment|/*-  * Copyright (c) 1980, 1991 The Regents of the University of California.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_comment
comment|// ntport.h
end_comment

begin_comment
comment|// the main header.
end_comment

begin_comment
comment|// -amol
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|NTPORT_H
end_ifndef

begin_define
define|#
directive|define
name|NTPORT_H
end_define

begin_define
define|#
directive|define
name|WIN32_LEAN_AND_MEAN
end_define

begin_include
include|#
directive|include
file|<windows.h>
end_include

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_include
include|#
directive|include
file|<time.h>
end_include

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<sys/stat.h>
end_include

begin_include
include|#
directive|include
file|<io.h>
end_include

begin_include
include|#
directive|include
file|<direct.h>
end_include

begin_include
include|#
directive|include
file|"dirent.h"
end_include

begin_include
include|#
directive|include
file|"version.h"
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|WINDOWS_ONLY
end_ifndef

begin_define
define|#
directive|define
name|STRSAFE_NO_DEPRECATE
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* WINDOWS_ONLY*/
end_comment

begin_define
define|#
directive|define
name|STRSAFE_LIB
end_define

begin_define
define|#
directive|define
name|STR_NO_CCH_FUNCTIONS
end_define

begin_include
include|#
directive|include
file|<strsafe.h>
end_include

begin_comment
comment|// These needed for fork(), which controls the heap management.
end_comment

begin_pragma
pragma|#
directive|pragma
name|data_seg
name|(
literal|".fusrdata"
name|)
end_pragma

begin_define
define|#
directive|define
name|INIT_ZERO
value|=0
end_define

begin_define
define|#
directive|define
name|INIT_ZERO_STRUCT
value|={0}
end_define

begin_define
define|#
directive|define
name|malloc
value|fmalloc
end_define

begin_define
define|#
directive|define
name|calloc
value|fcalloc
end_define

begin_define
define|#
directive|define
name|realloc
value|frealloc
end_define

begin_define
define|#
directive|define
name|free
value|ffree
end_define

begin_undef
undef|#
directive|undef
name|min
end_undef

begin_undef
undef|#
directive|undef
name|max
end_undef

begin_define
define|#
directive|define
name|heap_alloc
parameter_list|(
name|s
parameter_list|)
value|HeapAlloc(GetProcessHeap(),HEAP_ZERO_MEMORY,(s))
end_define

begin_define
define|#
directive|define
name|heap_free
parameter_list|(
name|p
parameter_list|)
value|HeapFree(GetProcessHeap(),0,(p))
end_define

begin_define
define|#
directive|define
name|heap_realloc
parameter_list|(
name|p
parameter_list|,
name|s
parameter_list|)
value|HeapReAlloc(GetProcessHeap(),HEAP_ZERO_MEMORY,(p),(s))
end_define

begin_pragma
pragma|#
directive|pragma
name|warning
name|(
name|disable
name|:
name|4018
name|)
end_pragma

begin_comment
comment|//signed-unsigned mismatch
end_comment

begin_define
define|#
directive|define
name|HAVENOLIMIT
end_define

begin_comment
comment|/* os-dependent stuff. belongs in tc.os.h, but I never said this would be pretty */
end_comment

begin_define
define|#
directive|define
name|lstat
value|stat
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|S_IFMT
end_ifdef

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|S_ISDIR
argument_list|)
operator|&&
name|defined
argument_list|(
name|S_IFDIR
argument_list|)
end_if

begin_define
define|#
directive|define
name|S_ISDIR
parameter_list|(
name|a
parameter_list|)
value|(((a)& S_IFMT) == S_IFDIR)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! S_ISDIR&& S_IFDIR */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|S_ISCHR
argument_list|)
operator|&&
name|defined
argument_list|(
name|S_IFCHR
argument_list|)
end_if

begin_define
define|#
directive|define
name|S_ISCHR
parameter_list|(
name|a
parameter_list|)
value|(((a)& S_IFMT) == S_IFCHR)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! S_ISCHR&& S_IFCHR */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|S_ISBLK
argument_list|)
operator|&&
name|defined
argument_list|(
name|S_IFBLK
argument_list|)
end_if

begin_define
define|#
directive|define
name|S_ISBLK
parameter_list|(
name|a
parameter_list|)
value|(((a)& S_IFMT) == S_IFBLK)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! S_ISBLK&& S_IFBLK */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|S_ISREG
argument_list|)
operator|&&
name|defined
argument_list|(
name|S_IFREG
argument_list|)
end_if

begin_define
define|#
directive|define
name|S_ISREG
parameter_list|(
name|a
parameter_list|)
value|(((a)& S_IFMT) == S_IFREG)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! S_ISREG&& S_IFREG */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|S_ISFIFO
argument_list|)
operator|&&
name|defined
argument_list|(
name|S_IFIFO
argument_list|)
end_if

begin_define
define|#
directive|define
name|S_ISFIFO
parameter_list|(
name|a
parameter_list|)
value|(((a)& S_IFMT) == S_IFIFO)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! S_ISFIFO&& S_IFIFO */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|S_ISNAM
argument_list|)
operator|&&
name|defined
argument_list|(
name|S_IFNAM
argument_list|)
end_if

begin_define
define|#
directive|define
name|S_ISNAM
parameter_list|(
name|a
parameter_list|)
value|(((a)& S_IFMT) == S_IFNAM)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! S_ISNAM&& S_IFNAM */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|S_ISLNK
argument_list|)
operator|&&
name|defined
argument_list|(
name|S_IFLNK
argument_list|)
end_if

begin_define
define|#
directive|define
name|S_ISLNK
parameter_list|(
name|a
parameter_list|)
value|(((a)& S_IFMT) == S_IFLNK)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! S_ISLNK&& S_IFLNK */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|S_ISSOCK
argument_list|)
operator|&&
name|defined
argument_list|(
name|S_IFSOCK
argument_list|)
end_if

begin_define
define|#
directive|define
name|S_ISSOCK
parameter_list|(
name|a
parameter_list|)
value|(((a)& S_IFMT) == S_IFSOCK)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! S_ISSOCK&& S_IFSOCK */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* S_IFMT */
end_comment

begin_comment
comment|/* port defines */
end_comment

begin_define
define|#
directive|define
name|getpid
value|GetCurrentProcessId
end_define

begin_define
define|#
directive|define
name|getpgrp
value|GetCurrentProcessId
end_define

begin_define
define|#
directive|define
name|tcgetpgrp
parameter_list|(
name|a
parameter_list|)
value|GetCurrentProcessId()
end_define

begin_define
define|#
directive|define
name|tcsetpgrp
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|0
end_define

begin_define
define|#
directive|define
name|setpgid
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|0
end_define

begin_define
define|#
directive|define
name|close
parameter_list|(
name|a
parameter_list|)
value|nt_close(a)
end_define

begin_define
define|#
directive|define
name|execv
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|nt_exec((a),(b))
end_define

begin_define
define|#
directive|define
name|execve
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|)
value|nt_execve((a),(b),(c))
end_define

begin_define
define|#
directive|define
name|open
value|nt_open
end_define

begin_define
define|#
directive|define
name|read
parameter_list|(
name|f
parameter_list|,
name|b
parameter_list|,
name|n
parameter_list|)
value|nt_read((f),(b),(n))
end_define

begin_define
define|#
directive|define
name|write
parameter_list|(
name|f
parameter_list|,
name|b
parameter_list|,
name|n
parameter_list|)
value|nt_write((f),(b),(n))
end_define

begin_define
define|#
directive|define
name|creat
parameter_list|(
name|f
parameter_list|,
name|m
parameter_list|)
value|nt_creat((f),(m))
end_define

begin_define
define|#
directive|define
name|_exit
parameter_list|(
name|a
parameter_list|)
value|ExitProcess((a))
end_define

begin_define
define|#
directive|define
name|chdir
parameter_list|(
name|a
parameter_list|)
value|nt_chdir(a)
end_define

begin_undef
undef|#
directive|undef
name|putc
end_undef

begin_undef
undef|#
directive|undef
name|putchar
end_undef

begin_define
define|#
directive|define
name|fgetc
parameter_list|(
name|a
parameter_list|)
value|nt_fgetc(a)
end_define

begin_define
define|#
directive|define
name|fputs
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|nt_fputs((a),(b))
end_define

begin_define
define|#
directive|define
name|putc
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|nt_putc((char)(a),(b))
end_define

begin_define
define|#
directive|define
name|fflush
parameter_list|(
name|a
parameter_list|)
value|nt_fflush((a))
end_define

begin_define
define|#
directive|define
name|fputc
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|nt_fputc((char)(a),(b))
end_define

begin_define
define|#
directive|define
name|fprintf
value|nt_fprintf
end_define

begin_define
define|#
directive|define
name|puts
parameter_list|(
name|a
parameter_list|)
value|nt_puts(a)
end_define

begin_define
define|#
directive|define
name|putchar
parameter_list|(
name|a
parameter_list|)
value|nt_putchar((char)(a))
end_define

begin_define
define|#
directive|define
name|fclose
parameter_list|(
name|p
parameter_list|)
value|nt_fclose(p)
end_define

begin_define
define|#
directive|define
name|_get_osfhandle
value|__nt_get_osfhandle
end_define

begin_define
define|#
directive|define
name|_open_osfhandle
value|__nt_open_osfhandle
end_define

begin_define
define|#
directive|define
name|clearerr
value|nt_clearerr
end_define

begin_define
define|#
directive|define
name|dup2
value|nt_dup2
end_define

begin_define
define|#
directive|define
name|fdopen
value|nt_fdopen
end_define

begin_define
define|#
directive|define
name|fgets
value|nt_fgets
end_define

begin_define
define|#
directive|define
name|fileno
value|nt_fileno
end_define

begin_define
define|#
directive|define
name|fopen
value|nt_fopen
end_define

begin_define
define|#
directive|define
name|fread
value|nt_fread
end_define

begin_define
define|#
directive|define
name|fseek
value|nt_fseek
end_define

begin_define
define|#
directive|define
name|ftell
value|nt_ftell
end_define

begin_define
define|#
directive|define
name|fwrite
value|nt_fwrite
end_define

begin_define
define|#
directive|define
name|isatty
value|nt_isatty
end_define

begin_define
define|#
directive|define
name|lseek
value|nt_lseek
end_define

begin_define
define|#
directive|define
name|printf
value|nt_printf
end_define

begin_define
define|#
directive|define
name|access
value|nt_access
end_define

begin_define
define|#
directive|define
name|fstat
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|nt_fstat((a),(b))
end_define

begin_define
define|#
directive|define
name|stat
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|nt_stat((a),(b))
end_define

begin_define
define|#
directive|define
name|setvbuf
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|,
name|d
parameter_list|)
end_define

begin_define
define|#
directive|define
name|setpgrp
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|(-1)
end_define

begin_define
define|#
directive|define
name|tcsetattr
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|)
value|0
end_define

begin_define
define|#
directive|define
name|inline
value|__inline
end_define

begin_undef
undef|#
directive|undef
name|stdin
end_undef

begin_undef
undef|#
directive|undef
name|stdout
end_undef

begin_undef
undef|#
directive|undef
name|stderr
end_undef

begin_define
define|#
directive|define
name|stdin
value|((FILE*)my_stdin)
end_define

begin_define
define|#
directive|define
name|stdout
value|((FILE*)my_stdout)
end_define

begin_define
define|#
directive|define
name|stderr
value|((FILE*)my_stderr)
end_define

begin_define
define|#
directive|define
name|dup
parameter_list|(
name|f
parameter_list|)
value|nt_dup((f))
end_define

begin_define
define|#
directive|define
name|sleep
parameter_list|(
name|a
parameter_list|)
value|Sleep((a)*1000)
end_define

begin_define
define|#
directive|define
name|getcwd
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|forward_slash_get_cwd((a),(b))
end_define

begin_define
define|#
directive|define
name|L_SET
value|SEEK_SET
end_define

begin_define
define|#
directive|define
name|L_XTND
value|SEEK_END
end_define

begin_define
define|#
directive|define
name|L_INCR
value|SEEK_CUR
end_define

begin_define
define|#
directive|define
name|S_IXUSR
value|S_IEXEC
end_define

begin_define
define|#
directive|define
name|S_IXGRP
value|S_IEXEC
end_define

begin_define
define|#
directive|define
name|S_IXOTH
value|S_IEXEC
end_define

begin_define
define|#
directive|define
name|NOFILE
value|64
end_define

begin_define
define|#
directive|define
name|ARG_MAX
value|1024
end_define

begin_define
define|#
directive|define
name|MAXSIG
value|NSIG
end_define

begin_comment
comment|/* mode Value	Checks File For  00	Existence only 02 	Write permission 04	Read permission 06	Read and write permission */
end_comment

begin_define
define|#
directive|define
name|F_OK
value|0
end_define

begin_define
define|#
directive|define
name|X_OK
value|1
end_define

begin_define
define|#
directive|define
name|W_OK
value|2
end_define

begin_define
define|#
directive|define
name|R_OK
value|4
end_define

begin_define
define|#
directive|define
name|XD_OK
value|9
end_define

begin_comment
comment|//executable and not directory
end_comment

begin_comment
comment|/* base key mappings + ctrl-key mappings + alt-key mappings */
end_comment

begin_comment
comment|/* see nt.bind.c  to figure these out */
end_comment

begin_comment
comment|/*  256 +  	4*24 (fkeys) +  	4*4 (arrow) +  	4*2 (pgup/dn) + 	4*2 (home/end) +  	4*2 (ins/del)  */
end_comment

begin_define
define|#
directive|define
name|NT_NUM_KEYS
value|392
end_define

begin_define
define|#
directive|define
name|NT_SPECIFIC_BINDING_OFFSET
value|256
end_define

begin_comment
comment|/* where our bindings start */
end_comment

begin_define
define|#
directive|define
name|KEYPAD_MAPPING_BEGIN
value|24
end_define

begin_comment
comment|/* offset from NT_SPECIFIC  										  where keypad mappings begin */
end_comment

begin_define
define|#
directive|define
name|INS_DEL_MAPPING_BEGIN
value|32
end_define

begin_define
define|#
directive|define
name|SINGLE_KEY_OFFSET
value|0
end_define

begin_comment
comment|/*if no ctrl or alt pressed */
end_comment

begin_define
define|#
directive|define
name|CTRL_KEY_OFFSET
value|34
end_define

begin_define
define|#
directive|define
name|ALT_KEY_OFFSET
value|(34*2)
end_define

begin_define
define|#
directive|define
name|SHIFT_KEY_OFFSET
value|(34*3)
end_define

begin_typedef
typedef|typedef
name|int
name|pid_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|int
name|speed_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|char
name|u_char
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|size_t
name|caddr_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|int
name|sig_atomic_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|int
name|mode_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|UINT32
name|uint32_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|char
name|uint8_t
typedef|;
end_typedef

begin_struct
struct|struct
name|timeval
block|{
name|long
name|tv_sec
decl_stmt|;
name|long
name|tv_usec
decl_stmt|;
block|}
struct|;
end_struct

begin_struct_decl
struct_decl|struct
name|termios
struct_decl|;
end_struct_decl

begin_comment
comment|/* struct timezone{ 	int tz_minuteswest; 	int dsttime; }; */
end_comment

begin_struct
struct|struct
name|rusage
block|{
name|struct
name|timeval
name|ru_utime
decl_stmt|;
comment|/* user time used */
name|struct
name|timeval
name|ru_stime
decl_stmt|;
comment|/* system time used */
name|long
name|ru_maxrss
decl_stmt|;
comment|/* maximum resident set size */
name|long
name|ru_ixrss
decl_stmt|;
comment|/* integral shared memory size */
name|long
name|ru_idrss
decl_stmt|;
comment|/* integral unshared data size */
name|long
name|ru_isrss
decl_stmt|;
comment|/* integral unshared stack size */
name|long
name|ru_minflt
decl_stmt|;
comment|/* page reclaims */
name|long
name|ru_majflt
decl_stmt|;
comment|/* page faults */
name|long
name|ru_nswap
decl_stmt|;
comment|/* swaps */
name|long
name|ru_inblock
decl_stmt|;
comment|/* block input operations */
name|long
name|ru_oublock
decl_stmt|;
comment|/* block output operations */
name|long
name|ru_msgsnd
decl_stmt|;
comment|/* messages sent */
name|long
name|ru_msgrcv
decl_stmt|;
comment|/* messages received */
name|long
name|ru_nsignals
decl_stmt|;
comment|/* signals received */
name|long
name|ru_nvcsw
decl_stmt|;
comment|/* voluntary context switches */
name|long
name|ru_nivcsw
decl_stmt|;
comment|/* involuntary context switches */
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|int
name|uid_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|int
name|gid_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|long
name|ssize_t
typedef|;
end_typedef

begin_struct
struct|struct
name|passwd
block|{
name|char
modifier|*
name|pw_name
decl_stmt|;
comment|/* user name */
name|char
modifier|*
name|pw_passwd
decl_stmt|;
comment|/* user password */
name|uid_t
name|pw_uid
decl_stmt|;
comment|/* user id */
name|gid_t
name|pw_gid
decl_stmt|;
comment|/* group id */
name|char
modifier|*
name|pw_gecos
decl_stmt|;
comment|/* real name */
name|char
modifier|*
name|pw_dir
decl_stmt|;
comment|/* home directory */
name|char
modifier|*
name|pw_shell
decl_stmt|;
comment|/* shell program */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|group
block|{
name|char
modifier|*
name|gr_name
decl_stmt|;
comment|/* group name */
name|char
modifier|*
name|gr_passwd
decl_stmt|;
comment|/* group password */
name|gid_t
name|gr_gid
decl_stmt|;
comment|/* group id */
name|char
modifier|*
modifier|*
name|gr_mem
decl_stmt|;
comment|/* group members */
block|}
struct|;
end_struct

begin_ifndef
ifndef|#
directive|ifndef
name|_INTPTR_T_DEFINED
end_ifndef

begin_ifdef
ifdef|#
directive|ifdef
name|_WIN64
end_ifdef

begin_typedef
typedef|typedef
name|__int64
name|intptr_t
typedef|;
end_typedef

begin_else
else|#
directive|else
end_else

begin_typedef
typedef|typedef
name|int
name|intptr_t
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|_INTPTR_T_DEFINED
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ntport.c */
end_comment

begin_function_decl
specifier|extern
name|char
modifier|*
name|ttyname
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|struct
name|passwd
modifier|*
name|getpwuid
parameter_list|(
name|uid_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|struct
name|group
modifier|*
name|getgrgid
parameter_list|(
name|gid_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|struct
name|passwd
modifier|*
name|getpwnam
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|struct
name|group
modifier|*
name|getgrnam
parameter_list|(
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|gid_t
name|getuid
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|gid_t
name|getgid
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|gid_t
name|geteuid
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|gid_t
name|getegid
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_ifdef
ifdef|#
directive|ifdef
name|NTDBG
end_ifdef

begin_function_decl
specifier|extern
name|void
name|dprintf
parameter_list|(
name|char
modifier|*
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|DBreak
parameter_list|()
value|__asm {int 3}
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|dprintf
value|(void)
end_define

begin_endif
endif|#
directive|endif
endif|NTDBG
end_endif

begin_define
define|#
directive|define
name|pipe
parameter_list|(
name|a
parameter_list|)
value|nt_pipe(a)
end_define

begin_comment
comment|/* support.c */
end_comment

begin_function_decl
specifier|extern
name|void
name|nt_init
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
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
specifier|extern
name|char
modifier|*
name|forward_slash_get_cwd
parameter_list|(
name|char
modifier|*
parameter_list|,
name|size_t
name|len
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|nt_chdir
parameter_list|(
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|nt_execve
parameter_list|(
name|char
modifier|*
parameter_list|,
name|char
modifier|*
modifier|*
parameter_list|,
name|char
modifier|*
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|nt_exec
parameter_list|(
name|char
modifier|*
parameter_list|,
name|char
modifier|*
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|quoteProtect
parameter_list|(
name|char
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|,
name|unsigned
name|long
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
name|fix_path_for_child
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|restore_path
parameter_list|(
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|copy_quote_and_fix_slashes
parameter_list|(
name|char
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|,
name|int
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
name|concat_args_and_quote
parameter_list|(
name|char
modifier|*
modifier|*
parameter_list|,
name|char
modifier|*
modifier|*
parameter_list|,
name|char
modifier|*
modifier|*
parameter_list|,
name|unsigned
name|int
modifier|*
parameter_list|,
name|char
modifier|*
modifier|*
parameter_list|,
name|unsigned
name|int
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|is_nt_executable
parameter_list|(
name|char
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* io.c */
end_comment

begin_function_decl
specifier|extern
name|int
name|force_read
parameter_list|(
name|int
parameter_list|,
name|unsigned
name|char
modifier|*
parameter_list|,
name|size_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|nt_read
parameter_list|(
name|int
parameter_list|,
name|unsigned
name|char
modifier|*
parameter_list|,
name|size_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|nt_write
parameter_list|(
name|int
parameter_list|,
specifier|const
name|unsigned
name|char
modifier|*
parameter_list|,
name|size_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|stringtable_read
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

begin_comment
comment|/* tparse.c */
end_comment

begin_function_decl
specifier|extern
name|int
name|tc_putc
parameter_list|(
name|char
parameter_list|,
name|FILE
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|nt_cleanup
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* stdio.c */
end_comment

begin_function_decl
specifier|extern
name|int
name|nt_creat
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
specifier|extern
name|int
name|nt_close
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|nt_open
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|int
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|nt_pipe
parameter_list|(
name|int
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|restore_fds
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|copy_fds
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|close_copied_fds
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|nt_fgetc
parameter_list|(
name|FILE
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|nt_dup
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|nt_fputs
parameter_list|(
name|char
modifier|*
parameter_list|,
name|FILE
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|nt_putc
parameter_list|(
name|char
parameter_list|,
name|FILE
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|nt_fflush
parameter_list|(
name|FILE
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|nt_fputc
parameter_list|(
name|char
parameter_list|,
name|FILE
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|nt_fprintf
parameter_list|(
name|FILE
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|nt_puts
parameter_list|(
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|nt_putchar
parameter_list|(
name|char
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|nt_fclose
parameter_list|(
name|FILE
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|nt_fputs
parameter_list|(
name|char
modifier|*
parameter_list|,
name|FILE
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|intptr_t
name|__nt_get_osfhandle
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|__nt_open_osfhandle
parameter_list|(
name|intptr_t
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|nt_clearerr
parameter_list|(
name|FILE
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|nt_dup2
parameter_list|(
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|FILE
modifier|*
name|nt_fdopen
parameter_list|(
name|int
parameter_list|,
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
name|nt_fgets
parameter_list|(
name|char
modifier|*
parameter_list|,
name|int
parameter_list|,
name|FILE
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|nt_fileno
parameter_list|(
name|FILE
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|FILE
modifier|*
name|nt_fopen
parameter_list|(
name|char
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|nt_fread
parameter_list|(
name|void
modifier|*
parameter_list|,
name|size_t
parameter_list|,
name|size_t
parameter_list|,
name|FILE
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|nt_fwrite
parameter_list|(
name|void
modifier|*
parameter_list|,
name|size_t
parameter_list|,
name|size_t
parameter_list|,
name|FILE
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|nt_fseek
parameter_list|(
name|FILE
modifier|*
parameter_list|,
name|long
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|long
name|nt_ftell
parameter_list|(
name|FILE
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|nt_isatty
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|nt_lseek
parameter_list|(
name|int
parameter_list|,
name|long
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|nt_printf
parameter_list|(
name|char
modifier|*
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|nt_access
parameter_list|(
name|char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|nt_fstat
parameter_list|(
name|int
parameter_list|,
name|struct
name|stat
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|nt_stat
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|struct
name|stat
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|nt_close_on_exec
parameter_list|(
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|init_stdio
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|is_resource_file
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_ifndef
ifndef|#
directive|ifndef
name|STDIO_C
end_ifndef

begin_decl_stmt
specifier|extern
name|void
modifier|*
name|my_stdin
decl_stmt|,
modifier|*
name|my_stdout
decl_stmt|,
modifier|*
name|my_stderr
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
endif|STDIO_C
end_endif

begin_comment
comment|/* nt.char.c */
end_comment

begin_function_decl
specifier|extern
name|unsigned
name|char
name|oem_it
parameter_list|(
name|unsigned
name|char
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
name|nt_cgets
parameter_list|(
name|int
parameter_list|,
name|int
parameter_list|,
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|nls_dll_init
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|nls_dll_unload
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|nt_autoset_dspmbyte
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* fork.c */
end_comment

begin_function_decl
specifier|extern
name|int
name|fork_init
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|fork
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
modifier|*
name|sbrk
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
modifier|*
name|fmalloc
parameter_list|(
name|size_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|ffree
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
modifier|*
name|frealloc
parameter_list|(
name|void
modifier|*
parameter_list|,
name|size_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
modifier|*
name|fcalloc
parameter_list|(
name|size_t
parameter_list|,
name|size_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|set_stackbase
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* console.c */
end_comment

begin_function_decl
specifier|extern
name|void
name|do_nt_cooked_mode
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|do_nt_raw_mode
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|do_nt_check_cooked_mode
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|set_cons_attr
parameter_list|(
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|NT_MoveToLineOrChar
parameter_list|(
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|nt_term_init
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|nt_term_cleanup
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|nt_set_size
parameter_list|(
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|//extern DWORD set_cooked_mode(HANDLE);
end_comment

begin_comment
comment|//extern void set_raw_mode(HANDLE);
end_comment

begin_comment
comment|//extern void set_arbitrary_mode(HANDLE,DWORD);
end_comment

begin_function_decl
specifier|extern
name|void
name|set_attributes
parameter_list|(
specifier|const
name|unsigned
name|char
modifier|*
name|color
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* ../sh.exec.c */
end_comment

begin_function_decl
specifier|extern
name|int
name|nt_check_if_windir
parameter_list|(
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|nt_check_name_and_hash
parameter_list|(
name|int
parameter_list|,
name|char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* clip.c */
end_comment

begin_function_decl
specifier|extern
name|void
name|cut_clip
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|paste_clip
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|init_clipboard
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|HANDLE
name|create_clip_writer_thread
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|HANDLE
name|create_clip_reader_thread
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* signal.c */
end_comment

begin_function_decl
specifier|extern
name|int
name|kill
parameter_list|(
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|nice
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|nt_init_signals
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|nt_cleanup_signals
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|start_sigchild_thread
parameter_list|(
name|HANDLE
parameter_list|,
name|DWORD
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* nt.who.c */
end_comment

begin_function_decl
specifier|extern
name|void
name|start_ncbs
parameter_list|(
name|short
modifier|*
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|cleanup_netbios
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* ntfunc.c */
end_comment

begin_struct_decl
struct_decl|struct
name|command
struct_decl|;
end_struct_decl

begin_function_decl
specifier|extern
name|void
name|dostart
parameter_list|(
name|short
modifier|*
modifier|*
parameter_list|,
name|struct
name|command
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|docls
parameter_list|(
name|short
modifier|*
modifier|*
parameter_list|,
name|struct
name|command
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|dotitle
parameter_list|(
name|short
modifier|*
modifier|*
parameter_list|,
name|struct
name|command
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|dostacksize
parameter_list|(
name|short
modifier|*
modifier|*
parameter_list|,
name|struct
name|command
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|dosourceresource
parameter_list|(
name|short
modifier|*
modifier|*
parameter_list|,
name|struct
name|command
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|doprintresource
parameter_list|(
name|short
modifier|*
modifier|*
parameter_list|,
name|struct
name|command
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_ifdef
ifdef|#
directive|ifdef
name|NTDBG
end_ifdef

begin_function_decl
specifier|extern
name|void
name|dodebugbreak
parameter_list|(
name|short
modifier|*
modifier|*
parameter_list|,
name|struct
name|command
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
endif|NTDBG
end_endif

begin_function_decl
specifier|extern
name|void
name|nt_set_env
parameter_list|(
specifier|const
name|short
modifier|*
parameter_list|,
specifier|const
name|short
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
name|hb_subst
parameter_list|(
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|init_hb_subst
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|init_shell_dll
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|try_shell_ex
parameter_list|(
name|char
modifier|*
modifier|*
parameter_list|,
name|int
parameter_list|,
name|BOOL
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|nt_try_fast_exec
parameter_list|(
name|struct
name|command
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|nt_feed_to_cmd
parameter_list|(
name|char
modifier|*
parameter_list|,
name|char
modifier|*
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|short
name|nt_translate_bindkey
parameter_list|(
specifier|const
name|short
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|struct
name|biltins
modifier|*
name|nt_check_additional_builtins
parameter_list|(
name|short
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|nt_print_builtins
parameter_list|(
name|size_t
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* ps.c */
end_comment

begin_function_decl
specifier|extern
name|void
name|init_plister
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|dops
parameter_list|(
name|short
modifier|*
modifier|*
parameter_list|,
name|struct
name|command
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|doshutdown
parameter_list|(
name|short
modifier|*
modifier|*
parameter_list|,
name|struct
name|command
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|kill_by_wm_close
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* globals.c */
end_comment

begin_function_decl
specifier|extern
name|int
name|is_gui
parameter_list|(
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|is_9x_gui
parameter_list|(
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Global variables */
end_comment

begin_decl_stmt
specifier|extern
name|unsigned
name|short
name|__nt_want_vcode
decl_stmt|,
name|__nt_vcode
decl_stmt|,
name|__nt_really_exec
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|__dup_stdin
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|__nt_only_start_exes
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|unsigned
name|short
name|__nt_child_nohupped
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|DWORD
name|gdwPlatform
decl_stmt|,
name|gdwVersion
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|is_dev_clipboard_active
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|HANDLE
name|ghdevclipthread
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|DWORD
name|gdwStackSize
decl_stmt|;
end_decl_stmt

begin_comment
comment|// bogus
end_comment

begin_define
define|#
directive|define
name|getppid
parameter_list|()
value|0
end_define

begin_struct
struct|struct
name|tms
block|{
name|clock_t
name|tms_utime
decl_stmt|;
name|clock_t
name|tms_stime
decl_stmt|;
name|clock_t
name|tms_cutime
decl_stmt|;
name|clock_t
name|tms_cstime
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|UT_UNKNOWN
value|0
end_define

begin_define
define|#
directive|define
name|DEAD_PROCESS
value|7
end_define

begin_define
define|#
directive|define
name|USER_PROCESS
value|8
end_define

begin_define
define|#
directive|define
name|UT_LINESIZE
value|16
end_define

begin_define
define|#
directive|define
name|UT_NAMESIZE
value|8
end_define

begin_define
define|#
directive|define
name|UT_HOSTSIZE
value|16
end_define

begin_struct
struct|struct
name|utmp
block|{
name|short
name|ut_type
decl_stmt|;
comment|/* type of login */
name|pid_t
name|ut_pid
decl_stmt|;
name|char
name|ut_line
index|[
name|UT_LINESIZE
index|]
decl_stmt|;
comment|/* device pref'/dev/' */
name|char
name|ut_id
index|[
literal|2
index|]
decl_stmt|;
comment|/*abbrev tty name */
name|time_t
name|ut_time
decl_stmt|;
comment|/* login time */
name|char
name|ut_user
index|[
name|UT_NAMESIZE
index|]
decl_stmt|;
comment|/* user name */
name|char
name|ut_host
index|[
name|UT_HOSTSIZE
index|]
decl_stmt|;
comment|/* hostname for rlogin */
name|long
name|ut_addr
decl_stmt|;
comment|/*ipaddr of remote host */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|ut_name
value|ut_user
end_define

begin_define
define|#
directive|define
name|killpg
value|kill
end_define

begin_endif
endif|#
directive|endif
endif|NTPORT_H
end_endif

end_unit

