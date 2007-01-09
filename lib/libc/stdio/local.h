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
comment|/*  * Information local to this implementation of stdio,  * in particular, macros and private variables.  */
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
comment|/* hold a buncha junk that would grow the ABI */
end_comment

begin_struct
struct|struct
name|__sFILEX
block|{
name|unsigned
name|char
modifier|*
name|_up
decl_stmt|;
comment|/* saved _p when _p is doing ungetc data */
name|pthread_mutex_t
name|fl_mutex
decl_stmt|;
comment|/* used for MT-safety */
name|pthread_t
name|fl_owner
decl_stmt|;
comment|/* current owner */
name|int
name|fl_count
decl_stmt|;
comment|/* recursive lock count */
name|int
name|orientation
decl_stmt|;
comment|/* orientation for fwide() */
name|mbstate_t
name|mbstate
decl_stmt|;
comment|/* multibyte conversion state */
block|}
struct|;
end_struct

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

begin_define
define|#
directive|define
name|INITEXTRA
parameter_list|(
name|fp
parameter_list|)
value|{ \ 	(fp)->_extra->_up = NULL; \ 	(fp)->_extra->fl_mutex = PTHREAD_MUTEX_INITIALIZER; \ 	(fp)->_extra->fl_owner = NULL; \ 	(fp)->_extra->fl_count = 0; \ 	(fp)->_extra->orientation = 0; \ 	memset(&(fp)->_extra->mbstate, 0, sizeof(mbstate_t)); \ }
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
value|do {				\ 	if ((fp)->_extra->orientation == 0)		\ 		(fp)->_extra->orientation = (o);	\ } while (0)
end_define

end_unit

