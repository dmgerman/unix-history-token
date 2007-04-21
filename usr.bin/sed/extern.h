begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1992 Diomidis Spinellis.  * Copyright (c) 1992, 1993  *	The Regents of the University of California.  All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Diomidis Spinellis of Imperial College, University of London.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)extern.h	8.1 (Berkeley) 6/6/93  * $FreeBSD$  */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|s_command
modifier|*
name|prog
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|s_appends
modifier|*
name|appends
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|regmatch_t
modifier|*
name|match
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|size_t
name|maxnsub
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|u_long
name|linenum
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|appendnum
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|aflag
decl_stmt|,
name|eflag
decl_stmt|,
name|nflag
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|char
modifier|*
name|fname
decl_stmt|,
modifier|*
name|outfname
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|FILE
modifier|*
name|infile
decl_stmt|,
modifier|*
name|outfile
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|rflags
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* regex flags to use */
end_comment

begin_function_decl
name|void
name|cfclose
parameter_list|(
name|struct
name|s_command
modifier|*
parameter_list|,
name|struct
name|s_command
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|compile
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|cspace
parameter_list|(
name|SPACE
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|size_t
parameter_list|,
name|enum
name|e_spflag
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|cu_fgets
parameter_list|(
name|char
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|mf_fgets
parameter_list|(
name|SPACE
modifier|*
parameter_list|,
name|enum
name|e_spflag
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|lastline
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|process
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|resetranges
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|strregerror
parameter_list|(
name|int
parameter_list|,
name|regex_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

end_unit

