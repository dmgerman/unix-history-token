begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1990 The Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Chris Torek.  *  * %sccs.include.redist.c%  *  *	@(#)stdio.h	5.8 (Berkeley) %G%  */
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

begin_comment
comment|/*  * NB: to fit things in six character monocase externals, the stdio  * code uses the prefix `__s' for stdio objects, typically followed  * by a three-character attempt at a mnemonic.  */
end_comment

begin_include
include|#
directive|include
file|<machine/types.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|_SIZE_T_
end_ifdef

begin_typedef
typedef|typedef
name|_SIZE_T_
name|size_t
typedef|;
end_typedef

begin_undef
undef|#
directive|undef
name|_SIZE_T_
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

begin_typedef
typedef|typedef
name|long
name|fpos_t
typedef|;
end_typedef

begin_comment
comment|/* Must match off_t<sys/types.h> */
end_comment

begin_define
define|#
directive|define
name|_FSTDIO
end_define

begin_comment
comment|/* Define for new stdio with functions. */
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
if|#
directive|if
name|__STDC__
operator|||
name|c_plusplus
name|int
function_decl|(
modifier|*
name|_read
function_decl|)
parameter_list|(
name|void
modifier|*
name|_cookie
parameter_list|,
name|char
modifier|*
name|_buf
parameter_list|,
name|int
name|_n
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
name|_cookie
parameter_list|,
specifier|const
name|char
modifier|*
name|_buf
parameter_list|,
name|int
name|_n
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
name|_cookie
parameter_list|,
name|fpos_t
name|_offset
parameter_list|,
name|int
name|_whence
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|_close
function_decl|)
parameter_list|(
name|void
modifier|*
name|_cookie
parameter_list|)
function_decl|;
else|#
directive|else
name|int
function_decl|(
modifier|*
name|_read
function_decl|)
parameter_list|()
function_decl|;
name|int
function_decl|(
modifier|*
name|_write
function_decl|)
parameter_list|()
function_decl|;
name|fpos_t
function_decl|(
modifier|*
name|_seek
function_decl|)
parameter_list|()
function_decl|;
name|int
function_decl|(
modifier|*
name|_close
function_decl|)
parameter_list|()
function_decl|;
endif|#
directive|endif
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
comment|/* separate buffer for fgetline() when line crosses buffer boundary */
name|struct
name|__sbuf
name|_lb
decl_stmt|;
comment|/* buffer for fgetline() */
comment|/* Unix stdio files get aligned to block boundaries on fseek() */
name|int
name|_blksize
decl_stmt|;
comment|/* stat.st_blksize (may be != _bf._size) */
name|int
name|_offset
decl_stmt|;
comment|/* current lseek offset */
block|}
name|FILE
typedef|;
end_typedef

begin_decl_stmt
specifier|extern
name|FILE
name|__sF
index|[]
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|__SLBF
value|0x0001
end_define

begin_comment
comment|/* line buffered */
end_comment

begin_define
define|#
directive|define
name|__SNBF
value|0x0002
end_define

begin_comment
comment|/* unbuffered */
end_comment

begin_define
define|#
directive|define
name|__SRD
value|0x0004
end_define

begin_comment
comment|/* OK to read */
end_comment

begin_define
define|#
directive|define
name|__SWR
value|0x0008
end_define

begin_comment
comment|/* OK to write */
end_comment

begin_comment
comment|/* RD and WR are never simultaneously asserted */
end_comment

begin_define
define|#
directive|define
name|__SRW
value|0x0010
end_define

begin_comment
comment|/* open for reading& writing */
end_comment

begin_define
define|#
directive|define
name|__SEOF
value|0x0020
end_define

begin_comment
comment|/* found EOF */
end_comment

begin_define
define|#
directive|define
name|__SERR
value|0x0040
end_define

begin_comment
comment|/* found error */
end_comment

begin_define
define|#
directive|define
name|__SMBF
value|0x0080
end_define

begin_comment
comment|/* _buf is from malloc */
end_comment

begin_define
define|#
directive|define
name|__SAPP
value|0x0100
end_define

begin_comment
comment|/* fdopen()ed in append mode */
end_comment

begin_define
define|#
directive|define
name|__SSTR
value|0x0200
end_define

begin_comment
comment|/* this is an sprintf/snprintf string */
end_comment

begin_define
define|#
directive|define
name|__SOPT
value|0x0400
end_define

begin_comment
comment|/* do fseek() optimisation */
end_comment

begin_define
define|#
directive|define
name|__SNPT
value|0x0800
end_define

begin_comment
comment|/* do not do fseek() optimisation */
end_comment

begin_define
define|#
directive|define
name|__SOFF
value|0x1000
end_define

begin_comment
comment|/* set iff _offset is in fact correct */
end_comment

begin_define
define|#
directive|define
name|__SMOD
value|0x2000
end_define

begin_comment
comment|/* true => fgetline modified _p text */
end_comment

begin_comment
comment|/*  * The following three definitions are for ANSI C, which took them  * from System V, which brilliantly took internal interface macros and  * made them official arguments to setvbuf(), without renaming them.  * Hence, these ugly _IOxxx names are *supposed* to appear in user code.  *  * Although numbered as their counterparts above, the implementation  * does not rely on this.  */
end_comment

begin_define
define|#
directive|define
name|_IOFBF
value|0
end_define

begin_comment
comment|/* setvbuf should set fully buffered */
end_comment

begin_define
define|#
directive|define
name|_IOLBF
value|1
end_define

begin_comment
comment|/* setvbuf should set line buffered */
end_comment

begin_define
define|#
directive|define
name|_IONBF
value|2
end_define

begin_comment
comment|/* setvbuf should set unbuffered */
end_comment

begin_define
define|#
directive|define
name|BUFSIZ
value|1024
end_define

begin_comment
comment|/* size of buffer used by setbuf */
end_comment

begin_define
define|#
directive|define
name|EOF
value|(-1)
end_define

begin_comment
comment|/*  * FOPEN_MAX is a minimum maximum, and should be the number of descriptors  * that the kernel can provide without allocation of a resource that can  * fail without the process sleeping.  Do not use this for anything.  */
end_comment

begin_define
define|#
directive|define
name|FOPEN_MAX
value|20
end_define

begin_comment
comment|/* must be<= OPEN_MAX<sys/syslimits.h> */
end_comment

begin_define
define|#
directive|define
name|FILENAME_MAX
value|1024
end_define

begin_comment
comment|/* must be<= PATH_MAX<sys/syslimits.h> */
end_comment

begin_comment
comment|/* System V/ANSI C; this is the wrong way to do this, do *not* use these. */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_ANSI_SOURCE
end_ifndef

begin_define
define|#
directive|define
name|P_tmpdir
value|"/usr/tmp/"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|L_tmpnam
value|1024
end_define

begin_comment
comment|/* XXX must be == PATH_MAX */
end_comment

begin_define
define|#
directive|define
name|TMP_MAX
value|308915776
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|SEEK_SET
end_ifndef

begin_define
define|#
directive|define
name|SEEK_SET
value|0
end_define

begin_comment
comment|/* set file offset to offset */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|SEEK_CUR
end_ifndef

begin_define
define|#
directive|define
name|SEEK_CUR
value|1
end_define

begin_comment
comment|/* set file offset to current plus offset */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|SEEK_END
end_ifndef

begin_define
define|#
directive|define
name|SEEK_END
value|2
end_define

begin_comment
comment|/* set file offset to EOF plus offset */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|stdin
value|(&__sF[0])
end_define

begin_define
define|#
directive|define
name|stdout
value|(&__sF[1])
end_define

begin_define
define|#
directive|define
name|stderr
value|(&__sF[2])
end_define

begin_comment
comment|/*  * Functions defined in ANSI C standard.  */
end_comment

begin_if
if|#
directive|if
name|__STDC__
operator|||
name|c_plusplus
end_if

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
name|_old
parameter_list|,
specifier|const
name|char
modifier|*
name|_new
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
name|fclose
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
name|FILE
modifier|*
name|fopen
parameter_list|(
specifier|const
name|char
modifier|*
name|_name
parameter_list|,
specifier|const
name|char
modifier|*
name|_type
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
name|_name
parameter_list|,
specifier|const
name|char
modifier|*
name|_type
parameter_list|,
name|FILE
modifier|*
name|_stream
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|setbuf
parameter_list|(
name|FILE
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|setvbuf
parameter_list|(
name|FILE
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|,
name|int
parameter_list|,
name|size_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|fprintf
parameter_list|(
name|FILE
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
name|fscanf
parameter_list|(
name|FILE
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
name|printf
parameter_list|(
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
name|scanf
parameter_list|(
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
name|sprintf
parameter_list|(
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
name|sscanf
parameter_list|(
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
name|vfprintf
parameter_list|(
name|FILE
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|_VA_LIST_
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
parameter_list|,
name|_VA_LIST_
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|vsprintf
parameter_list|(
name|char
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|_VA_LIST_
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
name|char
modifier|*
name|fgets
parameter_list|(
name|char
modifier|*
parameter_list|,
name|size_t
parameter_list|,
name|FILE
modifier|*
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
parameter_list|,
name|FILE
modifier|*
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
name|fread
parameter_list|(
name|void
modifier|*
parameter_list|,
name|size_t
name|_size
parameter_list|,
name|size_t
name|_n
parameter_list|,
name|FILE
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|fwrite
parameter_list|(
specifier|const
name|void
modifier|*
parameter_list|,
name|size_t
name|_size
parameter_list|,
name|size_t
name|_n
parameter_list|,
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
parameter_list|,
name|fpos_t
modifier|*
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
specifier|const
name|FILE
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
name|void
name|perror
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_else
else|#
directive|else
end_else

begin_function_decl
name|int
name|remove
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|rename
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|FILE
modifier|*
name|tmpfile
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|tmpnam
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|fclose
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|fflush
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|FILE
modifier|*
name|fopen
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|FILE
modifier|*
name|freopen
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|setbuf
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|setvbuf
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|fprintf
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|fscanf
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|printf
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|scanf
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|sprintf
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|sscanf
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|vfprintf
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|vprintf
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|vsprintf
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|fgetc
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|fgets
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|fputc
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|fputs
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|getc
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|getchar
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|gets
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|putc
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|putchar
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|puts
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ungetc
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|fread
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|fwrite
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|fgetpos
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|fseek
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|fsetpos
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|long
name|ftell
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|rewind
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|clearerr
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|feof
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ferror
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|perror
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Functions defined in POSIX 1003.1.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_ANSI_SOURCE
end_ifndef

begin_define
define|#
directive|define
name|L_cuserid
value|9
end_define

begin_comment
comment|/* size for cuserid(); UT_NAMESIZE + 1 */
end_comment

begin_define
define|#
directive|define
name|L_ctermid
value|1024
end_define

begin_comment
comment|/* size for ctermid(); PATH_MAX */
end_comment

begin_if
if|#
directive|if
name|__STDC__
operator|||
name|c_plusplus
end_if

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

begin_else
else|#
directive|else
end_else

begin_function_decl
name|FILE
modifier|*
name|fdopen
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|fileno
parameter_list|()
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
comment|/*  * Routines that are purely local.  */
end_comment

begin_if
if|#
directive|if
name|__STDC__
operator|||
name|c_plusplus
end_if

begin_function_decl
name|char
modifier|*
name|fgetline
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
name|int
name|fpurge
parameter_list|(
name|FILE
modifier|*
parameter_list|)
function_decl|;
end_function_decl

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
name|_name
parameter_list|,
specifier|const
name|char
modifier|*
name|_type
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
name|snprintf
parameter_list|(
name|char
modifier|*
parameter_list|,
name|size_t
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
name|vsnprintf
parameter_list|(
name|char
modifier|*
parameter_list|,
name|size_t
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|_VA_LIST_
parameter_list|)
function_decl|;
end_function_decl

begin_else
else|#
directive|else
end_else

begin_function_decl
name|char
modifier|*
name|fgetline
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|fpurge
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|getw
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|pclose
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|FILE
modifier|*
name|popen
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|putw
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|setbuffer
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|setlinebuf
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|snprintf
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|vsnprintf
parameter_list|()
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
comment|/* _ANSI_SOURCE */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_ANSI_SOURCE
end_ifndef

begin_comment
comment|/*  * Stdio function-access interface.  */
end_comment

begin_if
if|#
directive|if
name|__STDC__
operator|||
name|c_plusplus
end_if

begin_function_decl
name|FILE
modifier|*
name|funopen
parameter_list|(
specifier|const
name|void
modifier|*
name|_cookie
parameter_list|,
name|int
function_decl|(
modifier|*
name|readfn
function_decl|)
parameter_list|(
name|void
modifier|*
name|_cookie
parameter_list|,
name|char
modifier|*
name|_buf
parameter_list|,
name|int
name|_n
parameter_list|)
parameter_list|,
name|int
function_decl|(
modifier|*
name|writefn
function_decl|)
parameter_list|(
name|void
modifier|*
name|_cookie
parameter_list|,
specifier|const
name|char
modifier|*
name|_buf
parameter_list|,
name|int
name|_n
parameter_list|)
parameter_list|,
name|fpos_t
function_decl|(
modifier|*
name|seekfn
function_decl|)
parameter_list|(
name|void
modifier|*
name|_cookie
parameter_list|,
name|fpos_t
name|_off
parameter_list|,
name|int
name|_whence
parameter_list|)
parameter_list|,
name|int
function_decl|(
modifier|*
name|closefn
function_decl|)
parameter_list|(
name|void
modifier|*
name|_cookie
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

begin_else
else|#
directive|else
end_else

begin_function_decl
name|FILE
modifier|*
name|funopen
parameter_list|()
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
define|\
value|funopen(cookie, fn, (int (*)())0, (fpos_t (*)())0, (int (*)())0)
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
define|\
value|funopen(cookie, (int (*)())0, fn, (fpos_t (*)())0, (int (*)())0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Functions internal to the implementation.  */
end_comment

begin_if
if|#
directive|if
name|__STDC__
operator|||
name|c_plusplus
end_if

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

begin_else
else|#
directive|else
end_else

begin_function_decl
name|int
name|__srget
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|__swbuf
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * The __sfoo macros are here so that we can   * define function versions in the C library.  */
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

begin_ifdef
ifdef|#
directive|ifdef
name|__GNUC__
end_ifdef

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
comment|/* _STDIO_H_ */
end_comment

end_unit

