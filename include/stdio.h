begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1990, 1993  *	The Regents of the University of California.  All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Chris Torek.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)stdio.h	8.5 (Berkeley) 4/29/95  *	$Id: stdio.h,v 1.13 1997/04/13 15:50:07 bde Exp $  */
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
file|<machine/ansi.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|_BSD_SIZE_T_
end_ifdef

begin_typedef
typedef|typedef
name|_BSD_SIZE_T_
name|size_t
typedef|;
end_typedef

begin_undef
undef|#
directive|undef
name|_BSD_SIZE_T_
end_undef

begin_endif
endif|#
directive|endif
end_endif

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
comment|/*  * This is fairly grotesque, but pure ANSI code must not inspect the  * innards of an fpos_t anyway.  The library internally uses off_t,  * which we assume is exactly as big as eight chars.  (When we switch  * to gcc 2.4 we will use __attribute__ here.)  *  * WARNING: the alignment constraints on an off_t and the struct below  * differ on (e.g.) the SPARC.  Hence, the placement of an fpos_t object  * in a structure will change if fpos_t's are not aligned on 8-byte  * boundaries.  THIS IS A CROCK, but for now there is no way around it.  */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|_ANSI_SOURCE
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|__STRICT_ANSI__
argument_list|)
end_if

begin_typedef
typedef|typedef
name|_BSD_OFF_T_
name|fpos_t
typedef|;
end_typedef

begin_else
else|#
directive|else
end_else

begin_typedef
typedef|typedef
struct|struct
name|__sfpos
block|{
name|char
name|_pos
index|[
literal|8
index|]
decl_stmt|;
block|}
name|fpos_t
typedef|;
end_typedef

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
comment|/*  * stdio state variables.  *  * The following always hold:  *  *	if (_flags&(__SLBF|__SWR)) == (__SLBF|__SWR),  *		_lbfsize is -_bf._size, else _lbfsize is 0  *	if _flags&__SRD, _w is 0  *	if _flags&__SWR, _r is 0  *  * This ensures that the getc and putc macros (or inline functions) never  * try to write or read from a file that is in `read' or `write' mode.  * (Moreover, they can, and do, automatically switch from read mode to  * write mode, and back, on "r+" and "w+" files.)  *  * _lbfsize is used only to make the inline line-buffered output stream  * code as compact as possible.  *  * _ub, _up, and _ur are used when ungetc() pushes back more characters  * than fit in the current _bf, or when ungetc() pushes back a character  * that does not match the previous one in _bf.  When this happens,  * _ub._base becomes non-nil (i.e., a stream has ungetc() data iff  * _ub._base!=NULL) and _up and _ur save the current values of _p and _r.  *  * NB: see WARNING above before changing the layout of this structure!  */
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
argument_list|(
argument|*_close
argument_list|)
name|__P
argument_list|(
operator|(
name|void
operator|*
operator|)
argument_list|)
expr_stmt|;
name|int
argument_list|(
argument|*_read
argument_list|)
name|__P
argument_list|(
operator|(
name|void
operator|*
operator|,
name|char
operator|*
operator|,
name|int
operator|)
argument_list|)
expr_stmt|;
name|fpos_t
argument_list|(
argument|*_seek
argument_list|)
name|__P
argument_list|(
operator|(
name|void
operator|*
operator|,
name|fpos_t
operator|,
name|int
operator|)
argument_list|)
expr_stmt|;
name|int
argument_list|(
argument|*_write
argument_list|)
name|__P
argument_list|(
operator|(
name|void
operator|*
operator|,
specifier|const
name|char
operator|*
operator|,
name|int
operator|)
argument_list|)
expr_stmt|;
comment|/* separate buffer for long sequences of ungetc() */
name|struct
name|__sbuf
name|_ub
decl_stmt|;
comment|/* ungetc buffer */
name|unsigned
name|char
modifier|*
name|_up
decl_stmt|;
comment|/* saved _p when _p is doing ungetc data */
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
comment|/* current lseek offset (see WARNING) */
block|}
name|FILE
typedef|;
end_typedef

begin_decl_stmt
name|__BEGIN_DECLS
specifier|extern
name|FILE
name|__sF
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|__END_DECLS
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
ifndef|#
directive|ifndef
name|_ANSI_SOURCE
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
define|#
directive|define
name|stdin
value|(&__sF[0])
define|#
directive|define
name|stdout
value|(&__sF[1])
define|#
directive|define
name|stderr
value|(&__sF[2])
comment|/*  * Functions defined in ANSI C standard.  */
name|__BEGIN_DECLS
name|void
name|clearerr
name|__P
argument_list|(
operator|(
name|FILE
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|fclose
name|__P
argument_list|(
operator|(
name|FILE
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|feof
name|__P
argument_list|(
operator|(
name|FILE
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|ferror
name|__P
argument_list|(
operator|(
name|FILE
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|fflush
name|__P
argument_list|(
operator|(
name|FILE
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|fgetc
name|__P
argument_list|(
operator|(
name|FILE
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|fgetpos
name|__P
argument_list|(
operator|(
name|FILE
operator|*
operator|,
name|fpos_t
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|fgets
name|__P
argument_list|(
operator|(
name|char
operator|*
operator|,
name|int
operator|,
name|FILE
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|FILE
modifier|*
name|fopen
name|__P
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|,
specifier|const
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|fprintf
name|__P
argument_list|(
operator|(
name|FILE
operator|*
operator|,
specifier|const
name|char
operator|*
operator|,
operator|...
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|fputc
name|__P
argument_list|(
operator|(
name|int
operator|,
name|FILE
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|fputs
name|__P
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|,
name|FILE
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|size_t
name|fread
name|__P
argument_list|(
operator|(
name|void
operator|*
operator|,
name|size_t
operator|,
name|size_t
operator|,
name|FILE
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|FILE
modifier|*
name|freopen
name|__P
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|,
specifier|const
name|char
operator|*
operator|,
name|FILE
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|fscanf
name|__P
argument_list|(
operator|(
name|FILE
operator|*
operator|,
specifier|const
name|char
operator|*
operator|,
operator|...
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|fseek
name|__P
argument_list|(
operator|(
name|FILE
operator|*
operator|,
name|long
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|fsetpos
name|__P
argument_list|(
operator|(
name|FILE
operator|*
operator|,
specifier|const
name|fpos_t
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|long
name|ftell
name|__P
argument_list|(
operator|(
name|FILE
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|size_t
name|fwrite
name|__P
argument_list|(
operator|(
specifier|const
name|void
operator|*
operator|,
name|size_t
operator|,
name|size_t
operator|,
name|FILE
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|getc
name|__P
argument_list|(
operator|(
name|FILE
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|getchar
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|gets
name|__P
argument_list|(
operator|(
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|_ANSI_SOURCE
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|_POSIX_SOURCE
argument_list|)
end_if

begin_decl_stmt
specifier|extern
name|__const
name|int
name|sys_nerr
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* perror(3) external variables */
end_comment

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

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
name|void
name|perror
name|__P
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|printf
name|__P
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|,
operator|...
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|putc
name|__P
argument_list|(
operator|(
name|int
operator|,
name|FILE
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|putchar
name|__P
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|puts
name|__P
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|remove
name|__P
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|rename
name|__P
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|,
specifier|const
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|rewind
name|__P
argument_list|(
operator|(
name|FILE
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|scanf
name|__P
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|,
operator|...
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|setbuf
name|__P
argument_list|(
operator|(
name|FILE
operator|*
operator|,
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|setvbuf
name|__P
argument_list|(
operator|(
name|FILE
operator|*
operator|,
name|char
operator|*
operator|,
name|int
operator|,
name|size_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|sprintf
name|__P
argument_list|(
operator|(
name|char
operator|*
operator|,
specifier|const
name|char
operator|*
operator|,
operator|...
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|sscanf
name|__P
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|,
specifier|const
name|char
operator|*
operator|,
operator|...
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|FILE
modifier|*
name|tmpfile
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|tmpnam
name|__P
argument_list|(
operator|(
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|ungetc
name|__P
argument_list|(
operator|(
name|int
operator|,
name|FILE
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|vfprintf
name|__P
argument_list|(
operator|(
name|FILE
operator|*
operator|,
specifier|const
name|char
operator|*
operator|,
name|_BSD_VA_LIST_
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|vprintf
name|__P
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|,
name|_BSD_VA_LIST_
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|vsprintf
name|__P
argument_list|(
operator|(
name|char
operator|*
operator|,
specifier|const
name|char
operator|*
operator|,
name|_BSD_VA_LIST_
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|__END_DECLS
comment|/*  * Functions defined in POSIX 1003.1.  */
ifndef|#
directive|ifndef
name|_ANSI_SOURCE
comment|/* size for cuserid(3); UT_NAMESIZE + 1, see<utmp.h> */
define|#
directive|define
name|L_cuserid
value|17
define|#
directive|define
name|L_ctermid
value|1024
comment|/* size for ctermid(3); PATH_MAX */
name|__BEGIN_DECLS
name|char
modifier|*
name|ctermid
name|__P
argument_list|(
operator|(
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|FILE
modifier|*
name|fdopen
name|__P
argument_list|(
operator|(
name|int
operator|,
specifier|const
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|fileno
name|__P
argument_list|(
operator|(
name|FILE
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|__END_DECLS
endif|#
directive|endif
comment|/* not ANSI */
comment|/*  * Portability hacks.  See<sys/types.h>.  */
if|#
directive|if
operator|!
name|defined
argument_list|(
name|_ANSI_SOURCE
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|_POSIX_SOURCE
argument_list|)
name|__BEGIN_DECLS
ifndef|#
directive|ifndef
name|_FTRUNCATE_DECLARED
define|#
directive|define
name|_FTRUNCATE_DECLARED
name|int
name|ftruncate
name|__P
argument_list|(
operator|(
name|int
operator|,
name|_BSD_OFF_T_
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

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

begin_decl_stmt
name|_BSD_OFF_T_
name|lseek
name|__P
argument_list|(
operator|(
name|int
operator|,
name|_BSD_OFF_T_
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

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

begin_decl_stmt
name|char
modifier|*
name|mmap
name|__P
argument_list|(
operator|(
name|void
operator|*
operator|,
name|size_t
operator|,
name|int
operator|,
name|int
operator|,
name|int
operator|,
name|_BSD_OFF_T_
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

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

begin_decl_stmt
name|int
name|truncate
name|__P
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|,
name|_BSD_OFF_T_
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
name|__END_DECLS
endif|#
directive|endif
comment|/* !_ANSI_SOURCE&& !_POSIX_SOURCE */
comment|/*  * Routines that are purely local.  */
if|#
directive|if
operator|!
name|defined
argument_list|(
name|_ANSI_SOURCE
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|_POSIX_SOURCE
argument_list|)
name|__BEGIN_DECLS
name|int
name|asprintf
name|__P
argument_list|(
operator|(
name|char
operator|*
operator|*
operator|,
specifier|const
name|char
operator|*
operator|,
operator|...
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|fgetln
name|__P
argument_list|(
operator|(
name|FILE
operator|*
operator|,
name|size_t
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|fpurge
name|__P
argument_list|(
operator|(
name|FILE
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|getw
name|__P
argument_list|(
operator|(
name|FILE
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|pclose
name|__P
argument_list|(
operator|(
name|FILE
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|FILE
modifier|*
name|popen
name|__P
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|,
specifier|const
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|putw
name|__P
argument_list|(
operator|(
name|int
operator|,
name|FILE
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|setbuffer
name|__P
argument_list|(
operator|(
name|FILE
operator|*
operator|,
name|char
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|setlinebuf
name|__P
argument_list|(
operator|(
name|FILE
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|tempnam
name|__P
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|,
specifier|const
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|snprintf
name|__P
argument_list|(
operator|(
name|char
operator|*
operator|,
name|size_t
operator|,
specifier|const
name|char
operator|*
operator|,
operator|...
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|vasprintf
name|__P
argument_list|(
operator|(
name|char
operator|*
operator|*
operator|,
specifier|const
name|char
operator|*
operator|,
name|_BSD_VA_LIST_
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|vsnprintf
name|__P
argument_list|(
operator|(
name|char
operator|*
operator|,
name|size_t
operator|,
specifier|const
name|char
operator|*
operator|,
name|_BSD_VA_LIST_
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|vscanf
name|__P
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|,
name|_BSD_VA_LIST_
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|vsscanf
name|__P
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|,
specifier|const
name|char
operator|*
operator|,
name|_BSD_VA_LIST_
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|__END_DECLS
comment|/*  * This is a #define because the function is used internally and  * (unlike vfscanf) the name __svfscanf is guaranteed not to collide  * with a user function when _ANSI_SOURCE or _POSIX_SOURCE is defined.  */
define|#
directive|define
name|vfscanf
value|__svfscanf
comment|/*  * Stdio function-access interface.  */
name|__BEGIN_DECLS
name|FILE
modifier|*
name|funopen
name|__P
argument_list|(
operator|(
specifier|const
name|void
operator|*
operator|,
name|int
argument_list|(
operator|*
argument_list|)
argument_list|(
name|void
operator|*
argument_list|,
name|char
operator|*
argument_list|,
name|int
argument_list|)
operator|,
name|int
argument_list|(
operator|*
argument_list|)
argument_list|(
name|void
operator|*
argument_list|,
specifier|const
name|char
operator|*
argument_list|,
name|int
argument_list|)
operator|,
name|fpos_t
argument_list|(
operator|*
argument_list|)
argument_list|(
name|void
operator|*
argument_list|,
name|fpos_t
argument_list|,
name|int
argument_list|)
operator|,
name|int
argument_list|(
operator|*
argument_list|)
argument_list|(
name|void
operator|*
argument_list|)
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|__END_DECLS
define|#
directive|define
name|fropen
parameter_list|(
name|cookie
parameter_list|,
name|fn
parameter_list|)
value|funopen(cookie, fn, 0, 0, 0)
define|#
directive|define
name|fwopen
parameter_list|(
name|cookie
parameter_list|,
name|fn
parameter_list|)
value|funopen(cookie, 0, fn, 0, 0)
endif|#
directive|endif
comment|/* !_ANSI_SOURCE&& !_POSIX_SOURCE */
comment|/*  * Functions internal to the implementation.  */
name|__BEGIN_DECLS
name|int
name|__srget
name|__P
argument_list|(
operator|(
name|FILE
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|__svfscanf
name|__P
argument_list|(
operator|(
name|FILE
operator|*
operator|,
specifier|const
name|char
operator|*
operator|,
name|_BSD_VA_LIST_
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|__swbuf
name|__P
argument_list|(
operator|(
name|int
operator|,
name|FILE
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_function
name|__END_DECLS
comment|/*  * The __sfoo macros are here so that we can  * define function versions in the C library.  */
define|#
directive|define
name|__sgetc
parameter_list|(
name|p
parameter_list|)
value|(--(p)->_r< 0 ? __srget(p) : (int)(*(p)->_p++))
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

begin_define
define|#
directive|define
name|feof
parameter_list|(
name|p
parameter_list|)
value|__sfeof(p)
end_define

begin_define
define|#
directive|define
name|ferror
parameter_list|(
name|p
parameter_list|)
value|__sferror(p)
end_define

begin_define
define|#
directive|define
name|clearerr
parameter_list|(
name|p
parameter_list|)
value|__sclearerr(p)
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|_ANSI_SOURCE
end_ifndef

begin_define
define|#
directive|define
name|fileno
parameter_list|(
name|p
parameter_list|)
value|__sfileno(p)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|lint
end_ifndef

begin_define
define|#
directive|define
name|getc
parameter_list|(
name|fp
parameter_list|)
value|__sgetc(fp)
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
value|__sputc(x, fp)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* lint */
end_comment

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

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_STDIO_H_ */
end_comment

end_unit

