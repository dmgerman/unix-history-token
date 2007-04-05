begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1990, 1993  *	The Regents of the University of California.  All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Chris Torek.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)stdio.h	8.5 (Berkeley) 4/29/95  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_STDIO_H_
end_ifndef

begin_define
define|#
directive|define
name|_STDIO_H_
end_define

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_include
include|#
directive|include
file|<sys/_null.h>
end_include

begin_include
include|#
directive|include
file|<sys/_types.h>
end_include

begin_typedef
typedef|typedef
name|__off_t
name|fpos_t
typedef|;
end_typedef

begin_ifndef
ifndef|#
directive|ifndef
name|_SIZE_T_DECLARED
end_ifndef

begin_typedef
typedef|typedef
name|__size_t
name|size_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|_SIZE_T_DECLARED
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|__BSD_VISIBLE
operator|||
name|__POSIX_VISIBLE
operator|>=
literal|200112
operator|||
name|__XSI_VISIBLE
end_if

begin_ifndef
ifndef|#
directive|ifndef
name|_VA_LIST_DECLARED
end_ifndef

begin_typedef
typedef|typedef
name|__va_list
name|va_list
typedef|;
end_typedef

begin_define
define|#
directive|define
name|_VA_LIST_DECLARED
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|_FSTDIO
end_define

begin_comment
comment|/* Define for new stdio with functions. */
end_comment

begin_comment
comment|/*  * NB: to fit things in six character monocase externals, the stdio  * code uses the prefix `__s' for stdio objects, typically followed  * by a three-character attempt at a mnemonic.  */
end_comment

begin_comment
comment|/* stdio buffers */
end_comment

begin_struct
struct|struct
name|__sbuf
block|{
name|unsigned
name|char
modifier|*
name|_base
decl_stmt|;
name|int
name|_size
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* hold a buncha junk that would grow the ABI */
end_comment

begin_struct_decl
struct_decl|struct
name|__sFILEX
struct_decl|;
end_struct_decl

begin_comment
comment|/*  * stdio state variables.  *  * The following always hold:  *  *	if (_flags&(__SLBF|__SWR)) == (__SLBF|__SWR),  *		_lbfsize is -_bf._size, else _lbfsize is 0  *	if _flags&__SRD, _w is 0  *	if _flags&__SWR, _r is 0  *  * This ensures that the getc and putc macros (or inline functions) never  * try to write or read from a file that is in `read' or `write' mode.  * (Moreover, they can, and do, automatically switch from read mode to  * write mode, and back, on "r+" and "w+" files.)  *  * _lbfsize is used only to make the inline line-buffered output stream  * code as compact as possible.  *  * _ub, _up, and _ur are used when ungetc() pushes back more characters  * than fit in the current _bf, or when ungetc() pushes back a character  * that does not match the previous one in _bf.  When this happens,  * _ub._base becomes non-nil (i.e., a stream has ungetc() data iff  * _ub._base!=NULL) and _up and _ur save the current values of _p and _r.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|__sFILE
block|{
name|unsigned
name|char
modifier|*
name|_p
decl_stmt|;
comment|/* current position in (some) buffer */
name|int
name|_r
decl_stmt|;
comment|/* read space left for getc() */
name|int
name|_w
decl_stmt|;
comment|/* write space left for putc() */
name|short
name|_flags
decl_stmt|;
comment|/* flags, below; this FILE is free if 0 */
name|short
name|_file
decl_stmt|;
comment|/* fileno, if Unix descriptor, else -1 */
name|struct
name|__sbuf
name|_bf
decl_stmt|;
comment|/* the buffer (at least 1 byte, if !NULL) */
name|int
name|_lbfsize
decl_stmt|;
comment|/* 0 or -_bf._size, for inline putc */
comment|/* operations */
name|void
modifier|*
name|_cookie
decl_stmt|;
comment|/* cookie passed to io functions */
name|int
function_decl|(
modifier|*
name|_close
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|_read
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
name|fpos_t
function_decl|(
modifier|*
name|_seek
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|,
name|fpos_t
parameter_list|,
name|int
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|_write
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
comment|/* separate buffer for long sequences of ungetc() */
name|struct
name|__sbuf
name|_ub
decl_stmt|;
comment|/* ungetc buffer */
name|struct
name|__sFILEX
modifier|*
name|_extra
decl_stmt|;
comment|/* additions to FILE to not break ABI */
name|int
name|_ur
decl_stmt|;
comment|/* saved _r when _r is counting ungetc data */
comment|/* tricks to meet minimum requirements even when malloc() fails */
name|unsigned
name|char
name|_ubuf
index|[
literal|3
index|]
decl_stmt|;
comment|/* guarantee an ungetc() buffer */
name|unsigned
name|char
name|_nbuf
index|[
literal|1
index|]
decl_stmt|;
comment|/* guarantee a getc() buffer */
comment|/* separate buffer for fgetln() when line crosses buffer boundary */
name|struct
name|__sbuf
name|_lb
decl_stmt|;
comment|/* buffer for fgetln() */
comment|/* Unix stdio files get aligned to block boundaries on fseek() */
name|int
name|_blksize
decl_stmt|;
comment|/* stat.st_blksize (may be != _bf._size) */
name|fpos_t
name|_offset
decl_stmt|;
comment|/* current lseek offset */
block|}
name|FILE
typedef|;
end_typedef

begin_ifndef
ifndef|#
directive|ifndef
name|_STDSTREAM_DECLARED
end_ifndef

begin_decl_stmt
name|__BEGIN_DECLS
specifier|extern
name|FILE
modifier|*
name|__stdinp
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|FILE
modifier|*
name|__stdoutp
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|FILE
modifier|*
name|__stderrp
decl_stmt|;
end_decl_stmt

begin_function_decl
name|__END_DECLS
define|#
directive|define
name|_STDSTREAM_DECLARED
endif|#
directive|endif
define|#
directive|define
name|__SLBF
value|0x0001
comment|/* line buffered */
define|#
directive|define
name|__SNBF
value|0x0002
comment|/* unbuffered */
define|#
directive|define
name|__SRD
value|0x0004
comment|/* OK to read */
define|#
directive|define
name|__SWR
value|0x0008
comment|/* OK to write */
comment|/* RD and WR are never simultaneously asserted */
define|#
directive|define
name|__SRW
value|0x0010
comment|/* open for reading& writing */
define|#
directive|define
name|__SEOF
value|0x0020
comment|/* found EOF */
define|#
directive|define
name|__SERR
value|0x0040
comment|/* found error */
define|#
directive|define
name|__SMBF
value|0x0080
comment|/* _buf is from malloc */
define|#
directive|define
name|__SAPP
value|0x0100
comment|/* fdopen()ed in append mode */
define|#
directive|define
name|__SSTR
value|0x0200
comment|/* this is an sprintf/snprintf string */
define|#
directive|define
name|__SOPT
value|0x0400
comment|/* do fseek() optimization */
define|#
directive|define
name|__SNPT
value|0x0800
comment|/* do not do fseek() optimization */
define|#
directive|define
name|__SOFF
value|0x1000
comment|/* set iff _offset is in fact correct */
define|#
directive|define
name|__SMOD
value|0x2000
comment|/* true => fgetln modified _p text */
define|#
directive|define
name|__SALC
value|0x4000
comment|/* allocate string space dynamically */
define|#
directive|define
name|__SIGN
value|0x8000
comment|/* ignore this file in _fwalk */
comment|/*  * The following three definitions are for ANSI C, which took them  * from System V, which brilliantly took internal interface macros and  * made them official arguments to setvbuf(), without renaming them.  * Hence, these ugly _IOxxx names are *supposed* to appear in user code.  *  * Although numbered as their counterparts above, the implementation  * does not rely on this.  */
define|#
directive|define
name|_IOFBF
value|0
comment|/* setvbuf should set fully buffered */
define|#
directive|define
name|_IOLBF
value|1
comment|/* setvbuf should set line buffered */
define|#
directive|define
name|_IONBF
value|2
comment|/* setvbuf should set unbuffered */
define|#
directive|define
name|BUFSIZ
value|1024
comment|/* size of buffer used by setbuf */
define|#
directive|define
name|EOF
value|(-1)
comment|/*  * FOPEN_MAX is a minimum maximum, and is the number of streams that  * stdio can provide without attempting to allocate further resources  * (which could fail).  Do not use this for anything.  */
comment|/* must be == _POSIX_STREAM_MAX<limits.h> */
define|#
directive|define
name|FOPEN_MAX
value|20
comment|/* must be<= OPEN_MAX<sys/syslimits.h> */
define|#
directive|define
name|FILENAME_MAX
value|1024
comment|/* must be<= PATH_MAX<sys/syslimits.h> */
comment|/* System V/ANSI C; this is the wrong way to do this, do *not* use these. */
if|#
directive|if
name|__XSI_VISIBLE
define|#
directive|define
name|P_tmpdir
value|"/var/tmp/"
endif|#
directive|endif
define|#
directive|define
name|L_tmpnam
value|1024
comment|/* XXX must be == PATH_MAX */
define|#
directive|define
name|TMP_MAX
value|308915776
ifndef|#
directive|ifndef
name|SEEK_SET
define|#
directive|define
name|SEEK_SET
value|0
comment|/* set file offset to offset */
endif|#
directive|endif
ifndef|#
directive|ifndef
name|SEEK_CUR
define|#
directive|define
name|SEEK_CUR
value|1
comment|/* set file offset to current plus offset */
endif|#
directive|endif
ifndef|#
directive|ifndef
name|SEEK_END
define|#
directive|define
name|SEEK_END
value|2
comment|/* set file offset to EOF plus offset */
endif|#
directive|endif
ifndef|#
directive|ifndef
name|SEEK_DATA
define|#
directive|define
name|SEEK_DATA
value|3
comment|/* set file offset to next data past offset */
endif|#
directive|endif
ifndef|#
directive|ifndef
name|SEEK_HOLE
define|#
directive|define
name|SEEK_HOLE
value|4
comment|/* set file offset to next hole past offset */
endif|#
directive|endif
define|#
directive|define
name|stdin
value|__stdinp
define|#
directive|define
name|stdout
value|__stdoutp
define|#
directive|define
name|stderr
value|__stderrp
name|__BEGIN_DECLS
comment|/*  * Functions defined in ANSI C standard.  */
name|void
name|clearerr
parameter_list|(
name|FILE
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|fclose
parameter_list|(
name|FILE
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|feof
parameter_list|(
name|FILE
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ferror
parameter_list|(
name|FILE
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|fflush
parameter_list|(
name|FILE
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|fgetc
parameter_list|(
name|FILE
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|fgetpos
parameter_list|(
name|FILE
modifier|*
name|__restrict
parameter_list|,
name|fpos_t
modifier|*
name|__restrict
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|fgets
parameter_list|(
name|char
modifier|*
name|__restrict
parameter_list|,
name|int
parameter_list|,
name|FILE
modifier|*
name|__restrict
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|FILE
modifier|*
name|fopen
parameter_list|(
specifier|const
name|char
modifier|*
name|__restrict
parameter_list|,
specifier|const
name|char
modifier|*
name|__restrict
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|fprintf
parameter_list|(
name|FILE
modifier|*
name|__restrict
parameter_list|,
specifier|const
name|char
modifier|*
name|__restrict
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|fputc
parameter_list|(
name|int
parameter_list|,
name|FILE
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|fputs
parameter_list|(
specifier|const
name|char
modifier|*
name|__restrict
parameter_list|,
name|FILE
modifier|*
name|__restrict
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|size_t
name|fread
parameter_list|(
name|void
modifier|*
name|__restrict
parameter_list|,
name|size_t
parameter_list|,
name|size_t
parameter_list|,
name|FILE
modifier|*
name|__restrict
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|FILE
modifier|*
name|freopen
parameter_list|(
specifier|const
name|char
modifier|*
name|__restrict
parameter_list|,
specifier|const
name|char
modifier|*
name|__restrict
parameter_list|,
name|FILE
modifier|*
name|__restrict
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|fscanf
parameter_list|(
name|FILE
modifier|*
name|__restrict
parameter_list|,
specifier|const
name|char
modifier|*
name|__restrict
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|fseek
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
name|int
name|fsetpos
parameter_list|(
name|FILE
modifier|*
parameter_list|,
specifier|const
name|fpos_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|long
name|ftell
parameter_list|(
name|FILE
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|size_t
name|fwrite
parameter_list|(
specifier|const
name|void
modifier|*
name|__restrict
parameter_list|,
name|size_t
parameter_list|,
name|size_t
parameter_list|,
name|FILE
modifier|*
name|__restrict
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|getc
parameter_list|(
name|FILE
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|getchar
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|gets
parameter_list|(
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|perror
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|printf
parameter_list|(
specifier|const
name|char
modifier|*
name|__restrict
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|putc
parameter_list|(
name|int
parameter_list|,
name|FILE
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|putchar
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|puts
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|remove
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|rename
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
name|rewind
parameter_list|(
name|FILE
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|scanf
parameter_list|(
specifier|const
name|char
modifier|*
name|__restrict
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|setbuf
parameter_list|(
name|FILE
modifier|*
name|__restrict
parameter_list|,
name|char
modifier|*
name|__restrict
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|setvbuf
parameter_list|(
name|FILE
modifier|*
name|__restrict
parameter_list|,
name|char
modifier|*
name|__restrict
parameter_list|,
name|int
parameter_list|,
name|size_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|sprintf
parameter_list|(
name|char
modifier|*
name|__restrict
parameter_list|,
specifier|const
name|char
modifier|*
name|__restrict
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|sscanf
parameter_list|(
specifier|const
name|char
modifier|*
name|__restrict
parameter_list|,
specifier|const
name|char
modifier|*
name|__restrict
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|FILE
modifier|*
name|tmpfile
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|tmpnam
parameter_list|(
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ungetc
parameter_list|(
name|int
parameter_list|,
name|FILE
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|vfprintf
parameter_list|(
name|FILE
modifier|*
name|__restrict
parameter_list|,
specifier|const
name|char
modifier|*
name|__restrict
parameter_list|,
name|__va_list
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|vprintf
parameter_list|(
specifier|const
name|char
modifier|*
name|__restrict
parameter_list|,
name|__va_list
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|vsprintf
parameter_list|(
name|char
modifier|*
name|__restrict
parameter_list|,
specifier|const
name|char
modifier|*
name|__restrict
parameter_list|,
name|__va_list
parameter_list|)
function_decl|;
end_function_decl

begin_if
if|#
directive|if
name|__ISO_C_VISIBLE
operator|>=
literal|1999
end_if

begin_function_decl
name|int
name|snprintf
parameter_list|(
name|char
modifier|*
name|__restrict
parameter_list|,
name|size_t
parameter_list|,
specifier|const
name|char
modifier|*
name|__restrict
parameter_list|,
modifier|...
parameter_list|)
function_decl|__printflike
parameter_list|(
function_decl|3
operator|,
function_decl|4
end_function_decl

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_function_decl
name|int
name|vfscanf
parameter_list|(
name|FILE
modifier|*
name|__restrict
parameter_list|,
specifier|const
name|char
modifier|*
name|__restrict
parameter_list|,
name|__va_list
parameter_list|)
function_decl|__scanflike
parameter_list|(
function_decl|2
operator|,
function_decl|0
end_function_decl

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_function_decl
name|int
name|vscanf
parameter_list|(
specifier|const
name|char
modifier|*
name|__restrict
parameter_list|,
name|__va_list
parameter_list|)
function_decl|__scanflike
parameter_list|(
function_decl|1
operator|,
function_decl|0
end_function_decl

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_function_decl
name|int
name|vsnprintf
parameter_list|(
name|char
modifier|*
name|__restrict
parameter_list|,
name|size_t
parameter_list|,
specifier|const
name|char
modifier|*
name|__restrict
parameter_list|,
name|__va_list
parameter_list|)
function_decl|__printflike
parameter_list|(
function_decl|3
operator|,
function_decl|0
end_function_decl

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_function_decl
name|int
name|vsscanf
parameter_list|(
specifier|const
name|char
modifier|*
name|__restrict
parameter_list|,
specifier|const
name|char
modifier|*
name|__restrict
parameter_list|,
name|__va_list
parameter_list|)
function_decl|__scanflike
parameter_list|(
function_decl|2
operator|,
function_decl|0
end_function_decl

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Functions defined in all versions of POSIX 1003.1.  */
end_comment

begin_if
if|#
directive|if
name|__BSD_VISIBLE
operator|||
name|__POSIX_VISIBLE
operator|<=
literal|199506
end_if

begin_comment
comment|/* size for cuserid(3); UT_NAMESIZE + 1, see<utmp.h> */
end_comment

begin_define
define|#
directive|define
name|L_cuserid
value|17
end_define

begin_comment
comment|/* legacy */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|__POSIX_VISIBLE
end_if

begin_define
define|#
directive|define
name|L_ctermid
value|1024
end_define

begin_comment
comment|/* size for ctermid(3); PATH_MAX */
end_comment

begin_function_decl
name|char
modifier|*
name|ctermid
parameter_list|(
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|FILE
modifier|*
name|fdopen
parameter_list|(
name|int
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|fileno
parameter_list|(
name|FILE
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __POSIX_VISIBLE */
end_comment

begin_if
if|#
directive|if
name|__POSIX_VISIBLE
operator|>=
literal|199209
end_if

begin_function_decl
name|int
name|pclose
parameter_list|(
name|FILE
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|FILE
modifier|*
name|popen
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

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|__POSIX_VISIBLE
operator|>=
literal|199506
end_if

begin_function_decl
name|int
name|ftrylockfile
parameter_list|(
name|FILE
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|flockfile
parameter_list|(
name|FILE
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|funlockfile
parameter_list|(
name|FILE
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * These are normally used through macros as defined below, but POSIX  * requires functions as well.  */
end_comment

begin_function_decl
name|int
name|getc_unlocked
parameter_list|(
name|FILE
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|getchar_unlocked
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|putc_unlocked
parameter_list|(
name|int
parameter_list|,
name|FILE
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|putchar_unlocked
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|__BSD_VISIBLE
end_if

begin_function_decl
name|void
name|clearerr_unlocked
parameter_list|(
name|FILE
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|feof_unlocked
parameter_list|(
name|FILE
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ferror_unlocked
parameter_list|(
name|FILE
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|fileno_unlocked
parameter_list|(
name|FILE
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|__POSIX_VISIBLE
operator|>=
literal|200112
end_if

begin_function_decl
name|int
name|fseeko
parameter_list|(
name|FILE
modifier|*
parameter_list|,
name|__off_t
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|__off_t
name|ftello
parameter_list|(
name|FILE
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|__BSD_VISIBLE
operator|||
name|__XSI_VISIBLE
operator|>
literal|0
operator|&&
name|__XSI_VISIBLE
operator|<
literal|600
end_if

begin_function_decl
name|int
name|getw
parameter_list|(
name|FILE
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|putw
parameter_list|(
name|int
parameter_list|,
name|FILE
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* BSD or X/Open before issue 6 */
end_comment

begin_if
if|#
directive|if
name|__XSI_VISIBLE
end_if

begin_function_decl
name|char
modifier|*
name|tempnam
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

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Routines that are purely local.  */
end_comment

begin_if
if|#
directive|if
name|__BSD_VISIBLE
end_if

begin_function_decl
name|int
name|asprintf
parameter_list|(
name|char
modifier|*
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
modifier|...
parameter_list|)
function_decl|__printflike
parameter_list|(
function_decl|2
operator|,
function_decl|3
end_function_decl

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_function_decl
name|char
modifier|*
name|ctermid_r
parameter_list|(
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|fcloseall
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|fgetln
parameter_list|(
name|FILE
modifier|*
parameter_list|,
name|size_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|__const
name|char
modifier|*
name|fmtcheck
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|__format_arg
parameter_list|(
function_decl|2
end_function_decl

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_function_decl
name|int
name|fpurge
parameter_list|(
name|FILE
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|setbuffer
parameter_list|(
name|FILE
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
name|setlinebuf
parameter_list|(
name|FILE
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|vasprintf
parameter_list|(
name|char
modifier|*
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|__va_list
parameter_list|)
function_decl|__printflike
parameter_list|(
function_decl|2
operator|,
function_decl|0
end_function_decl

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_comment
comment|/*  * The system error table contains messages for the first sys_nerr  * positive errno values.  Use strerror() or strerror_r() from<string.h>  * instead.  */
end_comment

begin_decl_stmt
specifier|extern
name|__const
name|int
name|sys_nerr
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|__const
name|char
modifier|*
name|__const
name|sys_errlist
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * Stdio function-access interface.  */
end_comment

begin_function_decl
name|FILE
modifier|*
name|funopen
parameter_list|(
specifier|const
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
parameter_list|,
name|char
modifier|*
parameter_list|,
name|int
parameter_list|)
parameter_list|,
name|int
function_decl|(
modifier|*
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|int
parameter_list|)
parameter_list|,
name|fpos_t
function_decl|(
modifier|*
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|,
name|fpos_t
parameter_list|,
name|int
parameter_list|)
parameter_list|,
name|int
function_decl|(
modifier|*
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|)
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|fropen
parameter_list|(
name|cookie
parameter_list|,
name|fn
parameter_list|)
value|funopen(cookie, fn, 0, 0, 0)
end_define

begin_define
define|#
directive|define
name|fwopen
parameter_list|(
name|cookie
parameter_list|,
name|fn
parameter_list|)
value|funopen(cookie, 0, fn, 0, 0)
end_define

begin_comment
comment|/*  * Portability hacks.  See<sys/types.h>.  */
end_comment

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
name|__off_t
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

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
name|__off_t
name|lseek
parameter_list|(
name|int
parameter_list|,
name|__off_t
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|_MMAP_DECLARED
end_ifndef

begin_define
define|#
directive|define
name|_MMAP_DECLARED
end_define

begin_function_decl
name|void
modifier|*
name|mmap
parameter_list|(
name|void
modifier|*
parameter_list|,
name|size_t
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|,
name|__off_t
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

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
name|__off_t
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __BSD_VISIBLE */
end_comment

begin_comment
comment|/*  * Functions internal to the implementation.  */
end_comment

begin_function_decl
name|int
name|__srget
parameter_list|(
name|FILE
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|__swbuf
parameter_list|(
name|int
parameter_list|,
name|FILE
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * The __sfoo macros are here so that we can  * define function versions in the C library.  */
end_comment

begin_define
define|#
directive|define
name|__sgetc
parameter_list|(
name|p
parameter_list|)
value|(--(p)->_r< 0 ? __srget(p) : (int)(*(p)->_p++))
end_define

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__GNUC__
argument_list|)
operator|&&
name|defined
argument_list|(
name|__STDC__
argument_list|)
end_if

begin_function
specifier|static
name|__inline
name|int
name|__sputc
parameter_list|(
name|int
name|_c
parameter_list|,
name|FILE
modifier|*
name|_p
parameter_list|)
block|{
if|if
condition|(
operator|--
name|_p
operator|->
name|_w
operator|>=
literal|0
operator|||
operator|(
name|_p
operator|->
name|_w
operator|>=
name|_p
operator|->
name|_lbfsize
operator|&&
operator|(
name|char
operator|)
name|_c
operator|!=
literal|'\n'
operator|)
condition|)
return|return
operator|(
operator|*
name|_p
operator|->
name|_p
operator|++
operator|=
name|_c
operator|)
return|;
else|else
return|return
operator|(
name|__swbuf
argument_list|(
name|_c
argument_list|,
name|_p
argument_list|)
operator|)
return|;
block|}
end_function

begin_else
else|#
directive|else
end_else

begin_comment
comment|/*  * This has been tuned to generate reasonable code on the vax using pcc.  */
end_comment

begin_define
define|#
directive|define
name|__sputc
parameter_list|(
name|c
parameter_list|,
name|p
parameter_list|)
define|\
value|(--(p)->_w< 0 ? \ 		(p)->_w>= (p)->_lbfsize ? \ 			(*(p)->_p = (c)), *(p)->_p != '\n' ? \ 				(int)*(p)->_p++ : \ 				__swbuf('\n', p) : \ 			__swbuf((int)(c), p) : \ 		(*(p)->_p = (c), (int)*(p)->_p++))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|__sfeof
parameter_list|(
name|p
parameter_list|)
value|(((p)->_flags& __SEOF) != 0)
end_define

begin_define
define|#
directive|define
name|__sferror
parameter_list|(
name|p
parameter_list|)
value|(((p)->_flags& __SERR) != 0)
end_define

begin_define
define|#
directive|define
name|__sclearerr
parameter_list|(
name|p
parameter_list|)
value|((void)((p)->_flags&= ~(__SERR|__SEOF)))
end_define

begin_define
define|#
directive|define
name|__sfileno
parameter_list|(
name|p
parameter_list|)
value|((p)->_file)
end_define

begin_decl_stmt
specifier|extern
name|int
name|__isthreaded
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|feof
parameter_list|(
name|p
parameter_list|)
value|(!__isthreaded ? __sfeof(p) : (feof)(p))
end_define

begin_define
define|#
directive|define
name|ferror
parameter_list|(
name|p
parameter_list|)
value|(!__isthreaded ? __sferror(p) : (ferror)(p))
end_define

begin_define
define|#
directive|define
name|clearerr
parameter_list|(
name|p
parameter_list|)
value|(!__isthreaded ? __sclearerr(p) : (clearerr)(p))
end_define

begin_if
if|#
directive|if
name|__POSIX_VISIBLE
end_if

begin_define
define|#
directive|define
name|fileno
parameter_list|(
name|p
parameter_list|)
value|(!__isthreaded ? __sfileno(p) : (fileno)(p))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|getc
parameter_list|(
name|fp
parameter_list|)
value|(!__isthreaded ? __sgetc(fp) : (getc)(fp))
end_define

begin_define
define|#
directive|define
name|putc
parameter_list|(
name|x
parameter_list|,
name|fp
parameter_list|)
value|(!__isthreaded ? __sputc(x, fp) : (putc)(x, fp))
end_define

begin_define
define|#
directive|define
name|getchar
parameter_list|()
value|getc(stdin)
end_define

begin_define
define|#
directive|define
name|putchar
parameter_list|(
name|x
parameter_list|)
value|putc(x, stdout)
end_define

begin_if
if|#
directive|if
name|__BSD_VISIBLE
end_if

begin_comment
comment|/*  * See ISO/IEC 9945-1 ANSI/IEEE Std 1003.1 Second Edition 1996-07-12  * B.8.2.7 for the rationale behind the *_unlocked() macros.  */
end_comment

begin_define
define|#
directive|define
name|feof_unlocked
parameter_list|(
name|p
parameter_list|)
value|__sfeof(p)
end_define

begin_define
define|#
directive|define
name|ferror_unlocked
parameter_list|(
name|p
parameter_list|)
value|__sferror(p)
end_define

begin_define
define|#
directive|define
name|clearerr_unlocked
parameter_list|(
name|p
parameter_list|)
value|__sclearerr(p)
end_define

begin_define
define|#
directive|define
name|fileno_unlocked
parameter_list|(
name|p
parameter_list|)
value|__sfileno(p)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|__POSIX_VISIBLE
operator|>=
literal|199506
end_if

begin_define
define|#
directive|define
name|getc_unlocked
parameter_list|(
name|fp
parameter_list|)
value|__sgetc(fp)
end_define

begin_define
define|#
directive|define
name|putc_unlocked
parameter_list|(
name|x
parameter_list|,
name|fp
parameter_list|)
value|__sputc(x, fp)
end_define

begin_define
define|#
directive|define
name|getchar_unlocked
parameter_list|()
value|getc_unlocked(stdin)
end_define

begin_define
define|#
directive|define
name|putchar_unlocked
parameter_list|(
name|x
parameter_list|)
value|putc_unlocked(x, stdout)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_macro
name|__END_DECLS
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_STDIO_H_ */
end_comment

end_unit

