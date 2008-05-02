begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1990, 1993  *	The Regents of the University of California.  All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Chris Torek.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)local.h	8.3 (Berkeley) 7/3/94  * $FreeBSD$  */
end_comment

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_comment
comment|/* for off_t */
end_comment

begin_include
include|#
directive|include
file|<pthread.h>
end_include

begin_include
include|#
directive|include
file|<string.h>
end_include

begin_include
include|#
directive|include
file|<wchar.h>
end_include

begin_comment
comment|/*  * Information local to this implementation of stdio, in particular,  * macros, private functions, private variables, and the definition of  * FILE.  *  * NB: to fit things in six character monocase externals, the stdio  * code uses the prefix `__s' for stdio objects, typically followed  * by a three-character attempt at a mnemonic.  */
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
comment|/*  * stdio state variables.  *  * The following always hold:  *  *	if (_flags&(__SLBF|__SWR)) == (__SLBF|__SWR),  *		_lbfsize is -_bf._size, else _lbfsize is 0  *	if _flags&__SRD, _w is 0  *	if _flags&__SWR, _r is 0  *  * This ensures that the getc and putc macros (or inline functions) never  * try to write or read from a file that is in `read' or `write' mode.  * (Moreover, they can, and do, automatically switch from read mode to  * write mode, and back, on "r+" and "w+" files.)  *  * _lbfsize is used only to make the inline line-buffered output stream  * code as compact as possible.  *  * _ub, _up, and _ur are used when ungetc() pushes back more characters  * than fit in the current _bf, or when ungetc() pushes back a character  * that does not match the previous one in _bf.  When this happens,  * _ub._base becomes non-nil (i.e., a stream has ungetc() data iff  * _ub._base!=NULL) and _up and _ur save the current values of _p and _r.  *  * Certain members of __sFILE are accessed directly via macros or  * inline functions.  To preserve ABI compat, these members must not  * be disturbed.  These members are marked below with (*).  */
end_comment

begin_struct
struct|struct
name|__sFILE
block|{
name|unsigned
name|char
modifier|*
name|_p
decl_stmt|;
comment|/* (*) current position in (some) buffer */
name|int
name|_r
decl_stmt|;
comment|/* (*) read space left for getc() */
name|int
name|_w
decl_stmt|;
comment|/* (*) write space left for putc() */
name|short
name|_flags
decl_stmt|;
comment|/* (*) flags, below; this FILE is free if 0 */
name|short
name|_file
decl_stmt|;
comment|/* (*) fileno, if Unix descriptor, else -1 */
name|struct
name|__sbuf
name|_bf
decl_stmt|;
comment|/* the buffer (at least 1 byte, if !NULL) */
name|int
name|_lbfsize
decl_stmt|;
comment|/* (*) 0 or -_bf._size, for inline putc */
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
comment|/* current lseek offset */
name|pthread_mutex_t
name|_fl_mutex
decl_stmt|;
comment|/* used for MT-safety */
name|pthread_t
name|_fl_owner
decl_stmt|;
comment|/* current owner */
name|int
name|_fl_count
decl_stmt|;
comment|/* recursive lock count */
name|int
name|_orientation
decl_stmt|;
comment|/* orientation for fwide() */
name|mbstate_t
name|_mbstate
decl_stmt|;
comment|/* multibyte conversion state */
block|}
struct|;
end_struct

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
comment|/* do fseek() optimization */
end_comment

begin_define
define|#
directive|define
name|__SNPT
value|0x0800
end_define

begin_comment
comment|/* do not do fseek() optimization */
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
comment|/* true => fgetln modified _p text */
end_comment

begin_define
define|#
directive|define
name|__SALC
value|0x4000
end_define

begin_comment
comment|/* allocate string space dynamically */
end_comment

begin_define
define|#
directive|define
name|__SIGN
value|0x8000
end_define

begin_comment
comment|/* ignore this file in _fwalk */
end_comment

begin_function_decl
specifier|extern
name|int
name|_sread
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
specifier|extern
name|int
name|_swrite
parameter_list|(
name|FILE
modifier|*
parameter_list|,
name|char
specifier|const
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|fpos_t
name|_sseek
parameter_list|(
name|FILE
modifier|*
parameter_list|,
name|fpos_t
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|_ftello
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
specifier|extern
name|int
name|_fseeko
parameter_list|(
name|FILE
modifier|*
parameter_list|,
name|off_t
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|__fflush
parameter_list|(
name|FILE
modifier|*
name|fp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|__fcloseall
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|wint_t
name|__fgetwc
parameter_list|(
name|FILE
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|wint_t
name|__fputwc
parameter_list|(
name|wchar_t
parameter_list|,
name|FILE
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|__sflush
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
name|__sfp
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|__slbexpand
parameter_list|(
name|FILE
modifier|*
parameter_list|,
name|size_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|__srefill
parameter_list|(
name|FILE
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|__sread
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
end_function_decl

begin_function_decl
specifier|extern
name|int
name|__srget
parameter_list|(
name|FILE
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
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

begin_function_decl
specifier|extern
name|int
name|__swrite
parameter_list|(
name|void
modifier|*
parameter_list|,
name|char
specifier|const
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|fpos_t
name|__sseek
parameter_list|(
name|void
modifier|*
parameter_list|,
name|fpos_t
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|__sclose
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|__sinit
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|_cleanup
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|__smakebuf
parameter_list|(
name|FILE
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|__swhatbuf
parameter_list|(
name|FILE
modifier|*
parameter_list|,
name|size_t
modifier|*
parameter_list|,
name|int
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|_fwalk
parameter_list|(
name|int
function_decl|(
modifier|*
function_decl|)
parameter_list|(
name|FILE
modifier|*
parameter_list|)
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|__svfscanf
parameter_list|(
name|FILE
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|__va_list
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|__swsetup
parameter_list|(
name|FILE
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|__sflags
parameter_list|(
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
specifier|extern
name|int
name|__ungetc
parameter_list|(
name|int
parameter_list|,
name|FILE
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|wint_t
name|__ungetwc
parameter_list|(
name|wint_t
parameter_list|,
name|FILE
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|__vfprintf
parameter_list|(
name|FILE
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|__va_list
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|__vfscanf
parameter_list|(
name|FILE
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|__va_list
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|__vfwprintf
parameter_list|(
name|FILE
modifier|*
parameter_list|,
specifier|const
name|wchar_t
modifier|*
parameter_list|,
name|__va_list
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|__vfwscanf
parameter_list|(
name|FILE
modifier|*
name|__restrict
parameter_list|,
specifier|const
name|wchar_t
modifier|*
name|__restrict
parameter_list|,
name|__va_list
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|size_t
name|__fread
parameter_list|(
name|void
modifier|*
name|__restrict
name|buf
parameter_list|,
name|size_t
name|size
parameter_list|,
name|size_t
name|count
parameter_list|,
name|FILE
modifier|*
name|__restrict
name|fp
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|int
name|__sdidinit
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * Get and store individual characters from a file stream.  */
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

begin_comment
comment|/*  * Return true if the file stream has encountered an error.  */
end_comment

begin_define
define|#
directive|define
name|__sferror
parameter_list|(
name|p
parameter_list|)
value|(((p)->_flags& __SERR) != 0)
end_define

begin_comment
comment|/*  * Prepare the given FILE for writing, and return 0 iff it  * can be written now.  Otherwise, return EOF and set errno.  */
end_comment

begin_define
define|#
directive|define
name|prepwrite
parameter_list|(
name|fp
parameter_list|)
define|\
value|((((fp)->_flags& __SWR) == 0 || \  	    ((fp)->_bf._base == NULL&& ((fp)->_flags& __SSTR) == 0))&& \ 	 __swsetup(fp))
end_define

begin_comment
comment|/*  * Test whether the given stdio file has an active ungetc buffer;  * release such a buffer, without restoring ordinary unread data.  */
end_comment

begin_define
define|#
directive|define
name|HASUB
parameter_list|(
name|fp
parameter_list|)
value|((fp)->_ub._base != NULL)
end_define

begin_define
define|#
directive|define
name|FREEUB
parameter_list|(
name|fp
parameter_list|)
value|{ \ 	if ((fp)->_ub._base != (fp)->_ubuf) \ 		free((char *)(fp)->_ub._base); \ 	(fp)->_ub._base = NULL; \ }
end_define

begin_comment
comment|/*  * test for an fgetln() buffer.  */
end_comment

begin_define
define|#
directive|define
name|HASLB
parameter_list|(
name|fp
parameter_list|)
value|((fp)->_lb._base != NULL)
end_define

begin_define
define|#
directive|define
name|FREELB
parameter_list|(
name|fp
parameter_list|)
value|{ \ 	free((char *)(fp)->_lb._base); \ 	(fp)->_lb._base = NULL; \ }
end_define

begin_comment
comment|/*  * Set the orientation for a stream. If o> 0, the stream has wide-  * orientation. If o< 0, the stream has byte-orientation.  */
end_comment

begin_define
define|#
directive|define
name|ORIENT
parameter_list|(
name|fp
parameter_list|,
name|o
parameter_list|)
value|do {				\ 	if ((fp)->_orientation == 0)			\ 		(fp)->_orientation = (o);		\ } while (0)
end_define

end_unit

