begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1991, 1993  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	from: @(#)extern.h	8.1 (Berkeley) 5/31/93  * $FreeBSD$  */
end_comment

begin_function_decl
name|int
name|acccmp
parameter_list|(
specifier|const
name|FTSENT
modifier|*
parameter_list|,
specifier|const
name|FTSENT
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|revacccmp
parameter_list|(
specifier|const
name|FTSENT
modifier|*
parameter_list|,
specifier|const
name|FTSENT
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|modcmp
parameter_list|(
specifier|const
name|FTSENT
modifier|*
parameter_list|,
specifier|const
name|FTSENT
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|revmodcmp
parameter_list|(
specifier|const
name|FTSENT
modifier|*
parameter_list|,
specifier|const
name|FTSENT
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|namecmp
parameter_list|(
specifier|const
name|FTSENT
modifier|*
parameter_list|,
specifier|const
name|FTSENT
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|revnamecmp
parameter_list|(
specifier|const
name|FTSENT
modifier|*
parameter_list|,
specifier|const
name|FTSENT
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|statcmp
parameter_list|(
specifier|const
name|FTSENT
modifier|*
parameter_list|,
specifier|const
name|FTSENT
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|revstatcmp
parameter_list|(
specifier|const
name|FTSENT
modifier|*
parameter_list|,
specifier|const
name|FTSENT
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|printcol
parameter_list|(
name|DISPLAY
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|printlong
parameter_list|(
name|DISPLAY
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|printscol
parameter_list|(
name|DISPLAY
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|usage
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|size_t
name|len_octal
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
name|prn_octal
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|prn_printable
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_ifdef
ifdef|#
directive|ifdef
name|COLORLS
end_ifdef

begin_function_decl
name|void
name|parsecolors
parameter_list|(
specifier|const
name|char
modifier|*
name|cs
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|colorquit
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|ansi_fgcol
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|ansi_bgcol
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|ansi_coloff
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|attrs_off
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|enter_bold
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

