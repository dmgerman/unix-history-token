begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1980, 1993  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|lint
end_ifndef

begin_decl_stmt
specifier|static
name|char
name|sccsid
index|[]
init|=
literal|"@(#)CONFIG.c	8.1 (Berkeley) 6/6/93"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not lint */
end_comment

begin_comment
comment|/*      *	make sure you are editing      *		CONFIG.c      *	editing config.c won't work      */
end_comment

begin_comment
comment|/*      *	the version of translator      */
end_comment

begin_decl_stmt
name|char
modifier|*
name|version
init|=
literal|"VERSION (DATE)"
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*      *	the location of the error strings      *	and the length of the path to it      *	(in case of execution as a.something)      */
end_comment

begin_decl_stmt
name|char
modifier|*
name|err_file
init|=
literal|"LIBDATA/ERRORSTRINGS"
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|err_pathlen
init|=
sizeof|sizeof
argument_list|(
literal|"LIBDATA/"
argument_list|)
operator|-
literal|1
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*      *	the location of the short explanation      *	and the length of the path to it      *	the null at the end is so pix can change it to pi'x' from pi.      */
end_comment

begin_decl_stmt
name|char
name|how_string
index|[]
init|=
literal|"LIBDATA/HOWFILE\0"
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|how_file
init|=
name|how_string
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|how_pathlen
init|=
sizeof|sizeof
argument_list|(
literal|"LIBDATA/"
argument_list|)
operator|-
literal|1
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*      *	things about the interpreter.      *	these are not used by the compiler.      */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|PC
end_ifndef

begin_decl_stmt
name|char
modifier|*
name|px_header
init|=
literal|"LIBEXEC/px_header"
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* px_header's name */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|PXP
end_ifndef

begin_decl_stmt
name|char
modifier|*
name|pi_comp
init|=
literal|"INSTALLDIR/pi"
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* the compiler's name */
end_comment

begin_decl_stmt
name|char
modifier|*
name|px_intrp
init|=
literal|"INSTALLDIR/px"
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* the interpreter's name */
end_comment

begin_decl_stmt
name|char
modifier|*
name|px_debug
init|=
literal|"INSTALLDIR/pdx"
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* the debugger's name */
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

