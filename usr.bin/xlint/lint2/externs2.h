begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$NetBSD: externs2.h,v 1.2 1995/07/03 21:24:46 cgd Exp $	*/
end_comment

begin_comment
comment|/*  * Copyright (c) 1994, 1995 Jochen Pohl  * All Rights Reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *      This product includes software developed by Jochen Pohl for  *	The NetBSD Project.  * 4. The name of the author may not be used to endorse or promote products  *    derived from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_comment
comment|/*  * main.c  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|xflag
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|uflag
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|Cflag
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|char
modifier|*
name|libname
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|pflag
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|sflag
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|tflag
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|Hflag
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|hflag
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|Fflag
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * hash.c  */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|inithash
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
name|hte_t
modifier|*
name|hsearch
name|__P
argument_list|(
operator|(
specifier|const
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
name|void
name|forall
name|__P
argument_list|(
operator|(
name|void
argument_list|(
operator|*
argument_list|)
argument_list|(
name|hte_t
operator|*
argument_list|)
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * read.c  */
end_comment

begin_decl_stmt
specifier|extern
specifier|const
name|char
modifier|*
modifier|*
name|fnames
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|type_t
modifier|*
modifier|*
name|tlst
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|readfile
name|__P
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|mkstatic
name|__P
argument_list|(
operator|(
name|hte_t
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * mem2.c  */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|initmem
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
modifier|*
name|xalloc
name|__P
argument_list|(
operator|(
name|size_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * chk.c  */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|inittyp
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
name|mainused
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
name|chkname
name|__P
argument_list|(
operator|(
name|hte_t
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * msg.c  */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|msg
name|__P
argument_list|(
operator|(
name|int
operator|,
operator|...
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|char
modifier|*
name|mkpos
name|__P
argument_list|(
operator|(
name|pos_t
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * emit2.c  */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|outlib
name|__P
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

end_unit

