begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1991, 1993  *	The Regents of the University of California.  All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Ozan Yigit at York University.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)extern.h	8.1 (Berkeley) 6/6/93  * $FreeBSD$  */
end_comment

begin_function_decl
name|int
name|expr
parameter_list|(
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ndptr
name|addent
parameter_list|(
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|chrsave
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|cleanup
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|dochc
parameter_list|(
name|char
modifier|*
index|[]
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|dochq
parameter_list|(
name|char
modifier|*
index|[]
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|dodefine
parameter_list|(
name|char
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|dodefn
parameter_list|(
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|dodiv
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|dodump
parameter_list|(
name|char
modifier|*
index|[]
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|doifelse
parameter_list|(
name|char
modifier|*
index|[]
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|doincl
parameter_list|(
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|dopaste
parameter_list|(
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|dopushdef
parameter_list|(
name|char
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|dosub
parameter_list|(
name|char
modifier|*
index|[]
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|doundiv
parameter_list|(
name|char
modifier|*
index|[]
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|eval
parameter_list|(
name|char
modifier|*
index|[]
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|expand
parameter_list|(
name|char
modifier|*
index|[]
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|getdiv
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|hash
parameter_list|(
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|indx
parameter_list|(
name|char
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|killdiv
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ndptr
name|lookup
parameter_list|(
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|map
parameter_list|(
name|char
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|onintr
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|pbnum
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|pbstr
parameter_list|(
name|unsigned
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|putback
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|remhash
parameter_list|(
name|char
modifier|*
parameter_list|,
name|int
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

begin_decl_stmt
specifier|extern
name|ndptr
name|hashtab
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* hash table for macros etc. */
end_comment

begin_decl_stmt
specifier|extern
name|stae
name|mstack
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* stack of m4 machine */
end_comment

begin_decl_stmt
specifier|extern
name|FILE
modifier|*
name|active
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* active output file pointer */
end_comment

begin_decl_stmt
specifier|extern
name|FILE
modifier|*
name|infile
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* input file stack (0=stdin) */
end_comment

begin_decl_stmt
specifier|extern
name|FILE
modifier|*
name|outfile
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* diversion array(0=bitbucket) */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|fp
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* m4 call frame pointer */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|ilevel
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* input file stack pointer */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|oindex
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* diversion index. */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|sp
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* current m4 stack pointer */
end_comment

begin_decl_stmt
specifier|extern
name|unsigned
name|char
modifier|*
name|bp
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* first available character */
end_comment

begin_decl_stmt
specifier|extern
name|unsigned
name|char
name|buf
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* push-back buffer */
end_comment

begin_decl_stmt
specifier|extern
name|unsigned
name|char
modifier|*
name|bufbase
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* buffer base for this ilevel */
end_comment

begin_decl_stmt
specifier|extern
name|unsigned
name|char
modifier|*
name|bbase
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* buffer base per ilevel */
end_comment

begin_decl_stmt
specifier|extern
name|char
name|ecommt
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* end character for comment */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|endest
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* end of string space */
end_comment

begin_decl_stmt
specifier|extern
name|unsigned
name|char
modifier|*
name|endpbb
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* end of push-back buffer */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|ep
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* first free char in strspace */
end_comment

begin_decl_stmt
specifier|extern
name|char
name|lquote
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* left quote character (`) */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|m4dir
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* directory for temporary files */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|m4temp
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* filename for diversions */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|m4wraps
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* m4wrap string default. */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|null
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* as it says.. just a null. */
end_comment

begin_decl_stmt
specifier|extern
name|char
name|rquote
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* right quote character (') */
end_comment

begin_decl_stmt
specifier|extern
name|char
name|scommt
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* start character for comment */
end_comment

end_unit

