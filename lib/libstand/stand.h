begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1998 Michael Smith.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	$Id: stand.h,v 1.6 1998/09/26 10:48:50 dfr Exp $  * From	$NetBSD: stand.h,v 1.22 1997/06/26 19:17:40 drochner Exp $	  */
end_comment

begin_comment
comment|/*-  * Copyright (c) 1993  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)stand.h	8.1 (Berkeley) 6/11/93  */
end_comment

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_include
include|#
directive|include
file|<sys/stat.h>
end_include

begin_define
define|#
directive|define
name|CHK
parameter_list|(
name|fmt
parameter_list|,
name|args
modifier|...
parameter_list|)
value|printf("%s(%d): " fmt "\n", __FUNCTION__, __LINE__ , ##args)
end_define

begin_define
define|#
directive|define
name|PCHK
parameter_list|(
name|fmt
parameter_list|,
name|args
modifier|...
parameter_list|)
value|{printf("%s(%d): " fmt "\n", __FUNCTION__, __LINE__ , ##args); getchar();}
end_define

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

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Avoid unwanted userlandish components */
end_comment

begin_define
define|#
directive|define
name|KERNEL
end_define

begin_include
include|#
directive|include
file|<sys/errno.h>
end_include

begin_undef
undef|#
directive|undef
name|KERNEL
end_undef

begin_comment
comment|/* special stand error codes */
end_comment

begin_define
define|#
directive|define
name|EADAPT
value|(ELAST+1)
end_define

begin_comment
comment|/* bad adaptor */
end_comment

begin_define
define|#
directive|define
name|ECTLR
value|(ELAST+2)
end_define

begin_comment
comment|/* bad controller */
end_comment

begin_define
define|#
directive|define
name|EUNIT
value|(ELAST+3)
end_define

begin_comment
comment|/* bad unit */
end_comment

begin_define
define|#
directive|define
name|ESLICE
value|(ELAST+4)
end_define

begin_comment
comment|/* bad slice */
end_comment

begin_define
define|#
directive|define
name|EPART
value|(ELAST+5)
end_define

begin_comment
comment|/* bad partition */
end_comment

begin_define
define|#
directive|define
name|ERDLAB
value|(ELAST+6)
end_define

begin_comment
comment|/* can't read disk label */
end_comment

begin_define
define|#
directive|define
name|EUNLAB
value|(ELAST+7)
end_define

begin_comment
comment|/* unlabeled disk */
end_comment

begin_define
define|#
directive|define
name|EOFFSET
value|(ELAST+8)
end_define

begin_comment
comment|/* relative seek not supported */
end_comment

begin_define
define|#
directive|define
name|ESALAST
value|(ELAST+8)
end_define

begin_comment
comment|/* */
end_comment

begin_struct_decl
struct_decl|struct
name|open_file
struct_decl|;
end_struct_decl

begin_comment
comment|/*  * This structure is used to define file system operations in a file system  * independent way.  *  * XXX note that filesystem providers should export a pointer to their fs_ops  *     struct, so that consumers can reference this and thus include the  *     filesystems that they require.  */
end_comment

begin_struct
struct|struct
name|fs_ops
block|{
specifier|const
name|char
modifier|*
name|fs_name
decl_stmt|;
name|int
function_decl|(
modifier|*
name|fo_open
function_decl|)
parameter_list|(
specifier|const
name|char
modifier|*
name|path
parameter_list|,
name|struct
name|open_file
modifier|*
name|f
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|fo_close
function_decl|)
parameter_list|(
name|struct
name|open_file
modifier|*
name|f
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|fo_read
function_decl|)
parameter_list|(
name|struct
name|open_file
modifier|*
name|f
parameter_list|,
name|void
modifier|*
name|buf
parameter_list|,
name|size_t
name|size
parameter_list|,
name|size_t
modifier|*
name|resid
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|fo_write
function_decl|)
parameter_list|(
name|struct
name|open_file
modifier|*
name|f
parameter_list|,
name|void
modifier|*
name|buf
parameter_list|,
name|size_t
name|size
parameter_list|,
name|size_t
modifier|*
name|resid
parameter_list|)
function_decl|;
name|off_t
function_decl|(
modifier|*
name|fo_seek
function_decl|)
parameter_list|(
name|struct
name|open_file
modifier|*
name|f
parameter_list|,
name|off_t
name|offset
parameter_list|,
name|int
name|where
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|fo_stat
function_decl|)
parameter_list|(
name|struct
name|open_file
modifier|*
name|f
parameter_list|,
name|struct
name|stat
modifier|*
name|sb
parameter_list|)
function_decl|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * libstand-supplied filesystems  */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|fs_ops
name|ufs_fsops
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|fs_ops
name|tftp_fsops
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|fs_ops
name|nfs_fsops
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|fs_ops
name|cd9660_fsops
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|fs_ops
name|zipfs_fsops
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|fs_ops
name|dosfs_fsops
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* where values for lseek(2) */
end_comment

begin_define
define|#
directive|define
name|SEEK_SET
value|0
end_define

begin_comment
comment|/* set file offset to offset */
end_comment

begin_define
define|#
directive|define
name|SEEK_CUR
value|1
end_define

begin_comment
comment|/* set file offset to current plus offset */
end_comment

begin_define
define|#
directive|define
name|SEEK_END
value|2
end_define

begin_comment
comment|/* set file offset to EOF plus offset */
end_comment

begin_comment
comment|/*   * Device switch  */
end_comment

begin_struct
struct|struct
name|devsw
block|{
specifier|const
name|char
name|dv_name
index|[
literal|8
index|]
decl_stmt|;
name|int
name|dv_type
decl_stmt|;
comment|/* opaque type constant, arch-dependant */
name|int
function_decl|(
modifier|*
name|dv_init
function_decl|)
parameter_list|(
name|void
parameter_list|)
function_decl|;
comment|/* early probe call */
name|int
function_decl|(
modifier|*
name|dv_strategy
function_decl|)
parameter_list|(
name|void
modifier|*
name|devdata
parameter_list|,
name|int
name|rw
parameter_list|,
name|daddr_t
name|blk
parameter_list|,
name|size_t
name|size
parameter_list|,
name|void
modifier|*
name|buf
parameter_list|,
name|size_t
modifier|*
name|rsize
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|dv_open
function_decl|)
parameter_list|(
name|struct
name|open_file
modifier|*
name|f
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|dv_close
function_decl|)
parameter_list|(
name|struct
name|open_file
modifier|*
name|f
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|dv_ioctl
function_decl|)
parameter_list|(
name|struct
name|open_file
modifier|*
name|f
parameter_list|,
name|u_long
name|cmd
parameter_list|,
name|void
modifier|*
name|data
parameter_list|)
function_decl|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|int
name|errno
decl_stmt|;
end_decl_stmt

begin_struct
struct|struct
name|open_file
block|{
name|int
name|f_flags
decl_stmt|;
comment|/* see F_* below */
name|struct
name|devsw
modifier|*
name|f_dev
decl_stmt|;
comment|/* pointer to device operations */
name|void
modifier|*
name|f_devdata
decl_stmt|;
comment|/* device specific data */
name|struct
name|fs_ops
modifier|*
name|f_ops
decl_stmt|;
comment|/* pointer to file system operations */
name|void
modifier|*
name|f_fsdata
decl_stmt|;
comment|/* file system specific data */
name|off_t
name|f_offset
decl_stmt|;
comment|/* current file offset (F_RAW) */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|SOPEN_MAX
value|8
end_define

begin_decl_stmt
specifier|extern
name|struct
name|open_file
name|files
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* f_flags values */
end_comment

begin_define
define|#
directive|define
name|F_READ
value|0x0001
end_define

begin_comment
comment|/* file opened for reading */
end_comment

begin_define
define|#
directive|define
name|F_WRITE
value|0x0002
end_define

begin_comment
comment|/* file opened for writing */
end_comment

begin_define
define|#
directive|define
name|F_RAW
value|0x0004
end_define

begin_comment
comment|/* raw device open - no file system */
end_comment

begin_define
define|#
directive|define
name|F_NODEV
value|0x0008
end_define

begin_comment
comment|/* network open - no device */
end_comment

begin_define
define|#
directive|define
name|isupper
parameter_list|(
name|c
parameter_list|)
value|((c)>= 'A'&& (c)<= 'Z')
end_define

begin_define
define|#
directive|define
name|islower
parameter_list|(
name|c
parameter_list|)
value|((c)>= 'a'&& (c)<= 'z')
end_define

begin_define
define|#
directive|define
name|isspace
parameter_list|(
name|c
parameter_list|)
value|((c) == ' ' || (c) == '\t')
end_define

begin_define
define|#
directive|define
name|isdigit
parameter_list|(
name|c
parameter_list|)
value|((c)>= '0'&& (c)<= '9')
end_define

begin_define
define|#
directive|define
name|isxdigit
parameter_list|(
name|c
parameter_list|)
value|(isdigit(c) || ((c)>= 'a'&& (c)<= 'f') || ((c)>= 'A'&& (c)<= 'F'))
end_define

begin_define
define|#
directive|define
name|isascii
parameter_list|(
name|c
parameter_list|)
value|((c)>= 0 || (c<= 0x7f))
end_define

begin_define
define|#
directive|define
name|isalpha
parameter_list|(
name|c
parameter_list|)
value|(isupper(c) || (islower(c)))
end_define

begin_define
define|#
directive|define
name|toupper
parameter_list|(
name|c
parameter_list|)
value|((c) - 'a' + 'A')
end_define

begin_define
define|#
directive|define
name|tolower
parameter_list|(
name|c
parameter_list|)
value|((c) - 'A' + 'a')
end_define

begin_comment
comment|/* sbrk emulation */
end_comment

begin_function_decl
specifier|extern
name|void
name|setheap
parameter_list|(
name|void
modifier|*
name|base
parameter_list|,
name|void
modifier|*
name|top
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
name|sbrk
parameter_list|(
name|int
name|incr
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Matt Dillon's zalloc/zmalloc */
end_comment

begin_function_decl
specifier|extern
name|void
modifier|*
name|malloc
parameter_list|(
name|size_t
name|bytes
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|free
parameter_list|(
name|void
modifier|*
name|ptr
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*#define free(p)	{CHK("free %p", p); free(p);} */
end_comment

begin_comment
comment|/* use for catching guard violations */
end_comment

begin_function_decl
specifier|extern
name|void
modifier|*
name|calloc
parameter_list|(
name|size_t
name|n1
parameter_list|,
name|size_t
name|n2
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
modifier|*
name|realloc
parameter_list|(
name|void
modifier|*
name|ptr
parameter_list|,
name|size_t
name|size
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
modifier|*
name|reallocf
parameter_list|(
name|void
modifier|*
name|ptr
parameter_list|,
name|size_t
name|size
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|mallocstats
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* disklabel support (undocumented, may be junk) */
end_comment

begin_struct_decl
struct_decl|struct
name|disklabel
struct_decl|;
end_struct_decl

begin_function_decl
specifier|extern
name|char
modifier|*
name|getdisklabel
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|struct
name|disklabel
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|dkcksum
parameter_list|(
name|struct
name|disklabel
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|printf
parameter_list|(
specifier|const
name|char
modifier|*
name|fmt
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|vprintf
parameter_list|(
specifier|const
name|char
modifier|*
name|fmt
parameter_list|,
name|_BSD_VA_LIST_
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|sprintf
parameter_list|(
name|char
modifier|*
name|buf
parameter_list|,
specifier|const
name|char
modifier|*
name|cfmt
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|twiddle
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|ngets
parameter_list|(
name|char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|gets
parameter_list|(
name|x
parameter_list|)
value|ngets((x), 0)
end_define

begin_function_decl
specifier|extern
name|int
name|fgetstr
parameter_list|(
name|char
modifier|*
name|buf
parameter_list|,
name|int
name|size
parameter_list|,
name|int
name|fd
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|open
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|O_RDONLY
value|0x0
end_define

begin_define
define|#
directive|define
name|O_WRONLY
value|0x1
end_define

begin_comment
comment|/* writing not (yet?) supported */
end_comment

begin_define
define|#
directive|define
name|O_RDWR
value|0x2
end_define

begin_function_decl
specifier|extern
name|int
name|close
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|closeall
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
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
specifier|extern
name|ssize_t
name|write
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
specifier|extern
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

begin_function_decl
specifier|extern
name|int
name|stat
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
name|srandom
parameter_list|(
name|u_long
name|seed
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|u_long
name|random
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* imports from stdlib, locally modified */
end_comment

begin_function_decl
specifier|extern
name|long
name|strtol
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|char
modifier|*
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
name|strerror
parameter_list|(
name|int
name|err
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
specifier|extern
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

begin_comment
comment|/* pager.c */
end_comment

begin_function_decl
specifier|extern
name|void
name|pager_open
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|pager_close
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|pager_output
parameter_list|(
specifier|const
name|char
modifier|*
name|lines
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|pager_file
parameter_list|(
specifier|const
name|char
modifier|*
name|fname
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* environment.c */
end_comment

begin_define
define|#
directive|define
name|EV_DYNAMIC
value|(1<<0)
end_define

begin_comment
comment|/* value was dynamically allocated, free if changed/unset */
end_comment

begin_define
define|#
directive|define
name|EV_VOLATILE
value|(1<<1)
end_define

begin_comment
comment|/* value is volatile, make a copy of it */
end_comment

begin_define
define|#
directive|define
name|EV_NOHOOK
value|(1<<2)
end_define

begin_comment
comment|/* don't call hook when setting */
end_comment

begin_struct_decl
struct_decl|struct
name|env_var
struct_decl|;
end_struct_decl

begin_typedef
typedef|typedef
name|char
modifier|*
function_decl|(
name|ev_format_t
function_decl|)
parameter_list|(
name|struct
name|env_var
modifier|*
name|ev
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|int
function_decl|(
name|ev_sethook_t
function_decl|)
parameter_list|(
name|struct
name|env_var
modifier|*
name|ev
parameter_list|,
name|int
name|flags
parameter_list|,
name|void
modifier|*
name|value
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|int
function_decl|(
name|ev_unsethook_t
function_decl|)
parameter_list|(
name|struct
name|env_var
modifier|*
name|ev
parameter_list|)
function_decl|;
end_typedef

begin_struct
struct|struct
name|env_var
block|{
name|char
modifier|*
name|ev_name
decl_stmt|;
name|int
name|ev_flags
decl_stmt|;
name|void
modifier|*
name|ev_value
decl_stmt|;
name|ev_sethook_t
modifier|*
name|ev_sethook
decl_stmt|;
name|ev_unsethook_t
modifier|*
name|ev_unsethook
decl_stmt|;
name|struct
name|env_var
modifier|*
name|ev_next
decl_stmt|,
modifier|*
name|ev_prev
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|struct
name|env_var
modifier|*
name|environ
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|struct
name|env_var
modifier|*
name|env_getenv
parameter_list|(
specifier|const
name|char
modifier|*
name|name
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|env_setenv
parameter_list|(
specifier|const
name|char
modifier|*
name|name
parameter_list|,
name|int
name|flags
parameter_list|,
name|void
modifier|*
name|value
parameter_list|,
name|ev_sethook_t
name|sethook
parameter_list|,
name|ev_unsethook_t
name|unsethook
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
name|getenv
parameter_list|(
specifier|const
name|char
modifier|*
name|name
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|setenv
parameter_list|(
specifier|const
name|char
modifier|*
name|name
parameter_list|,
name|char
modifier|*
name|value
parameter_list|,
name|int
name|overwrite
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|putenv
parameter_list|(
specifier|const
name|char
modifier|*
name|string
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|unsetenv
parameter_list|(
specifier|const
name|char
modifier|*
name|name
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|ev_sethook_t
name|env_noset
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* refuse set operation */
end_comment

begin_decl_stmt
specifier|extern
name|ev_unsethook_t
name|env_nounset
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* refuse unset operation */
end_comment

begin_comment
comment|/* BCD conversions (undocumented) */
end_comment

begin_decl_stmt
specifier|extern
name|u_char
specifier|const
name|bcd2bin_data
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|u_char
specifier|const
name|bin2bcd_data
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
specifier|const
name|hex2ascii_data
index|[]
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|bcd2bin
parameter_list|(
name|bcd
parameter_list|)
value|(bcd2bin_data[bcd])
end_define

begin_define
define|#
directive|define
name|bin2bcd
parameter_list|(
name|bin
parameter_list|)
value|(bin2bcd_data[bin])
end_define

begin_define
define|#
directive|define
name|hex2ascii
parameter_list|(
name|hex
parameter_list|)
value|(hex2ascii_data[hex])
end_define

begin_comment
comment|/* min/max (undocumented) */
end_comment

begin_function
specifier|static
name|__inline
name|int
name|imax
parameter_list|(
name|int
name|a
parameter_list|,
name|int
name|b
parameter_list|)
block|{
return|return
operator|(
name|a
operator|>
name|b
condition|?
name|a
else|:
name|b
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|int
name|imin
parameter_list|(
name|int
name|a
parameter_list|,
name|int
name|b
parameter_list|)
block|{
return|return
operator|(
name|a
operator|<
name|b
condition|?
name|a
else|:
name|b
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|long
name|lmax
parameter_list|(
name|long
name|a
parameter_list|,
name|long
name|b
parameter_list|)
block|{
return|return
operator|(
name|a
operator|>
name|b
condition|?
name|a
else|:
name|b
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|long
name|lmin
parameter_list|(
name|long
name|a
parameter_list|,
name|long
name|b
parameter_list|)
block|{
return|return
operator|(
name|a
operator|<
name|b
condition|?
name|a
else|:
name|b
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|u_int
name|max
parameter_list|(
name|u_int
name|a
parameter_list|,
name|u_int
name|b
parameter_list|)
block|{
return|return
operator|(
name|a
operator|>
name|b
condition|?
name|a
else|:
name|b
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|u_int
name|min
parameter_list|(
name|u_int
name|a
parameter_list|,
name|u_int
name|b
parameter_list|)
block|{
return|return
operator|(
name|a
operator|<
name|b
condition|?
name|a
else|:
name|b
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|quad_t
name|qmax
parameter_list|(
name|quad_t
name|a
parameter_list|,
name|quad_t
name|b
parameter_list|)
block|{
return|return
operator|(
name|a
operator|>
name|b
condition|?
name|a
else|:
name|b
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|quad_t
name|qmin
parameter_list|(
name|quad_t
name|a
parameter_list|,
name|quad_t
name|b
parameter_list|)
block|{
return|return
operator|(
name|a
operator|<
name|b
condition|?
name|a
else|:
name|b
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|u_long
name|ulmax
parameter_list|(
name|u_long
name|a
parameter_list|,
name|u_long
name|b
parameter_list|)
block|{
return|return
operator|(
name|a
operator|>
name|b
condition|?
name|a
else|:
name|b
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|u_long
name|ulmin
parameter_list|(
name|u_long
name|a
parameter_list|,
name|u_long
name|b
parameter_list|)
block|{
return|return
operator|(
name|a
operator|<
name|b
condition|?
name|a
else|:
name|b
operator|)
return|;
block|}
end_function

begin_comment
comment|/* swaps (undocumented, useful?) */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__i386__
end_ifdef

begin_function_decl
specifier|extern
name|u_int32_t
name|bswap32
parameter_list|(
name|u_int32_t
name|x
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|u_int64_t
name|bswap64
parameter_list|(
name|u_int32_t
name|x
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* null functions for device/filesystem switches (undocumented) */
end_comment

begin_function_decl
specifier|extern
name|int
name|nodev
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|noioctl
parameter_list|(
name|struct
name|open_file
modifier|*
parameter_list|,
name|u_long
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|nullsys
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|null_open
parameter_list|(
specifier|const
name|char
modifier|*
name|path
parameter_list|,
name|struct
name|open_file
modifier|*
name|f
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|null_close
parameter_list|(
name|struct
name|open_file
modifier|*
name|f
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|ssize_t
name|null_read
parameter_list|(
name|struct
name|open_file
modifier|*
name|f
parameter_list|,
name|void
modifier|*
name|buf
parameter_list|,
name|size_t
name|size
parameter_list|,
name|size_t
modifier|*
name|resid
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|ssize_t
name|null_write
parameter_list|(
name|struct
name|open_file
modifier|*
name|f
parameter_list|,
name|void
modifier|*
name|buf
parameter_list|,
name|size_t
name|size
parameter_list|,
name|size_t
modifier|*
name|resid
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|off_t
name|null_seek
parameter_list|(
name|struct
name|open_file
modifier|*
name|f
parameter_list|,
name|off_t
name|offset
parameter_list|,
name|int
name|where
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|null_stat
parameter_list|(
name|struct
name|open_file
modifier|*
name|f
parameter_list|,
name|struct
name|stat
modifier|*
name|sb
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*   * Machine dependent functions and data, must be provided or stubbed by   * the consumer   */
end_comment

begin_function_decl
specifier|extern
name|int
name|getchar
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|ischar
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|putchar
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|devopen
parameter_list|(
name|struct
name|open_file
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|devclose
parameter_list|(
name|struct
name|open_file
modifier|*
name|f
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|void
name|panic
argument_list|(
specifier|const
name|char
operator|*
argument_list|,
operator|...
argument_list|)
name|__dead2
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|fs_ops
modifier|*
name|file_system
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|devsw
modifier|*
name|devsw
index|[]
decl_stmt|;
end_decl_stmt

begin_if
if|#
directive|if
literal|0
end_if

begin_define
unit|static inline void * malloc_debug(size_t size, const char *file, int line) {     void *p;     printf("%s:%d malloc(%ld)", file, line, size);     p = malloc(size);     printf("=%p\n", p);     return p; }  static inline void free_debug(void *p, const char *file, int line) {     printf("%s:%d free(%p)\n", file, line, p);     free(p); }
define|#
directive|define
name|malloc
parameter_list|(
name|x
parameter_list|)
value|malloc_debug(x, __FILE__, __LINE__)
end_define

begin_define
define|#
directive|define
name|free
parameter_list|(
name|x
parameter_list|)
value|free_debug(x, __FILE__, __LINE__)
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

