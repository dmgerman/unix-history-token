begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1990, 1993  *	The Regents of the University of California.  All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Chris Torek.  *  * Copyright (c) 2011 The FreeBSD Foundation  * All rights reserved.  * Portions of this software were developed by David Chisnall  * under sponsorship from the FreeBSD Foundation.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)local.h	8.3 (Berkeley) 7/3/94  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_STDIO_LOCAL_H
end_ifndef

begin_define
define|#
directive|define
name|_STDIO_LOCAL_H
end_define

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

begin_include
include|#
directive|include
file|<locale.h>
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
name|__fgetwc_mbs
parameter_list|(
name|FILE
modifier|*
parameter_list|,
name|mbstate_t
modifier|*
parameter_list|,
name|int
modifier|*
parameter_list|,
name|locale_t
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
parameter_list|,
name|locale_t
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
name|locale_t
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
parameter_list|,
name|locale_t
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
name|locale_t
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
name|locale_t
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
name|locale_t
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

begin_function
specifier|static
specifier|inline
name|wint_t
name|__fgetwc
parameter_list|(
name|FILE
modifier|*
name|fp
parameter_list|,
name|locale_t
name|locale
parameter_list|)
block|{
name|int
name|nread
decl_stmt|;
return|return
operator|(
name|__fgetwc_mbs
argument_list|(
name|fp
argument_list|,
operator|&
name|fp
operator|->
name|_mbstate
argument_list|,
operator|&
name|nread
argument_list|,
name|locale
argument_list|)
operator|)
return|;
block|}
end_function

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
comment|/*  * Structure initializations for 'fake' FILE objects.  */
end_comment

begin_define
define|#
directive|define
name|FAKE_FILE
value|{				\ 	._file = -1,				\ 	._fl_mutex = PTHREAD_MUTEX_INITIALIZER, \ }
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

begin_function_decl
name|void
name|__stdio_cancel_cleanup
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|FLOCKFILE_CANCELSAFE
parameter_list|(
name|fp
parameter_list|)
define|\
value|{								\ 		struct _pthread_cleanup_info __cleanup_info__;		\ 		if (__isthreaded) {					\ 			_FLOCKFILE(fp);					\ 			___pthread_cleanup_push_imp(			\ 			    __stdio_cancel_cleanup, (fp), 		\&__cleanup_info__);				\ 		} else {						\ 			___pthread_cleanup_push_imp(			\ 			    __stdio_cancel_cleanup, NULL, 		\&__cleanup_info__);				\ 		}							\ 		{
end_define

begin_define
define|#
directive|define
name|FUNLOCKFILE_CANCELSAFE
parameter_list|()
define|\
value|(void)0;					\ 		}							\ 		___pthread_cleanup_pop_imp(1);				\ 	}
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _STDIO_LOCAL_H */
end_comment

end_unit

