begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1990, 1993  *	The Regents of the University of California.  All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Chris Torek.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)local.h	8.3 (Berkeley) 7/3/94  *  * $FreeBSD$  */
end_comment

begin_comment
comment|/*  * Information local to this implementation of stdio,  * in particular, macros and private variables.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|__sflush
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
specifier|extern
name|FILE
modifier|*
name|__sfp
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|__srefill
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
specifier|extern
name|int
name|__sread
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
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|__swrite
name|__P
argument_list|(
operator|(
name|void
operator|*
operator|,
name|char
specifier|const
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|fpos_t
name|__sseek
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
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|__sclose
name|__P
argument_list|(
operator|(
name|void
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|__sinit
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|_cleanup
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_extern
extern|extern void	(*__cleanup
end_extern

begin_expr_stmt
unit|)
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_decl_stmt
specifier|extern
name|void
name|__smakebuf
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
specifier|extern
name|int
name|__swhatbuf
name|__P
argument_list|(
operator|(
name|FILE
operator|*
operator|,
name|size_t
operator|*
operator|,
name|int
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|_fwalk
name|__P
argument_list|(
operator|(
name|int
argument_list|(
operator|*
argument_list|)
argument_list|(
name|FILE
operator|*
argument_list|)
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|__swsetup
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
specifier|extern
name|int
name|__sflags
name|__P
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|,
name|int
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|__sdidinit
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * Return true iff the given FILE cannot be written now.  */
end_comment

begin_define
define|#
directive|define
name|cantwrite
parameter_list|(
name|fp
parameter_list|)
define|\
value|((((fp)->_flags& __SWR) == 0 || (fp)->_bf._base == NULL)&& \ 	 __swsetup(fp))
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

end_unit

