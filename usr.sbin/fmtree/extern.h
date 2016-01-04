begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1991, 1993  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)extern.h	8.1 (Berkeley) 6/6/93  * $FreeBSD$  */
end_comment

begin_decl_stmt
specifier|extern
name|uint32_t
name|crc_total
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|_FTS_H_
end_ifdef

begin_function_decl
name|int
name|compare
parameter_list|(
name|char
modifier|*
parameter_list|,
name|NODE
modifier|*
parameter_list|,
name|FTSENT
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
name|int
name|crc
parameter_list|(
name|int
parameter_list|,
name|uint32_t
modifier|*
parameter_list|,
name|off_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|cwalk
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|flags_to_string
parameter_list|(
name|u_long
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|const
name|char
modifier|*
name|inotype
parameter_list|(
name|u_int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|u_int
name|parsekey
parameter_list|(
name|char
modifier|*
parameter_list|,
name|int
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|rlink
parameter_list|(
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|NODE
modifier|*
name|mtree_readspec
parameter_list|(
name|FILE
modifier|*
name|fi
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|mtree_verifyspec
parameter_list|(
name|FILE
modifier|*
name|fi
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|mtree_specspec
parameter_list|(
name|FILE
modifier|*
name|fi
parameter_list|,
name|FILE
modifier|*
name|fj
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|check_excludes
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
name|init_excludes
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|read_excludes_file
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|const
name|char
modifier|*
name|ftype
parameter_list|(
name|u_int
name|type
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|int
name|ftsoptions
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|u_int
name|keys
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|lineno
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|dflag
decl_stmt|,
name|eflag
decl_stmt|,
name|iflag
decl_stmt|,
name|nflag
decl_stmt|,
name|qflag
decl_stmt|,
name|rflag
decl_stmt|,
name|sflag
decl_stmt|,
name|uflag
decl_stmt|,
name|wflag
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|MAXPATHLEN
end_ifdef

begin_decl_stmt
specifier|extern
name|char
name|fullpath
index|[
name|MAXPATHLEN
index|]
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

