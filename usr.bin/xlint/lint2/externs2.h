begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $NetBSD: externs2.h,v 1.7 2001/05/28 12:40:38 lukem Exp $ */
end_comment

begin_comment
comment|/*  * Copyright (c) 1996 Christopher G. Demetriou.  All Rights Reserved.  * Copyright (c) 1994, 1995 Jochen Pohl  * All Rights Reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *      This product includes software developed by Jochen Pohl for  *	The NetBSD Project.  * 4. The name of the author may not be used to endorse or promote products  *    derived from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
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

begin_function_decl
specifier|extern
name|void
name|_inithash
parameter_list|(
name|hte_t
modifier|*
modifier|*
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|hte_t
modifier|*
name|_hsearch
parameter_list|(
name|hte_t
modifier|*
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|_forall
parameter_list|(
name|hte_t
modifier|*
modifier|*
parameter_list|,
name|void
function_decl|(
modifier|*
function_decl|)
parameter_list|(
name|hte_t
modifier|*
parameter_list|)
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|_destroyhash
parameter_list|(
name|hte_t
modifier|*
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|inithash
parameter_list|()
value|_inithash(NULL);
end_define

begin_define
define|#
directive|define
name|hsearch
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|_hsearch(NULL, (a), (b))
end_define

begin_define
define|#
directive|define
name|forall
parameter_list|(
name|a
parameter_list|)
value|_forall(NULL, (a))
end_define

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

begin_function_decl
specifier|extern
name|void
name|readfile
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|mkstatic
parameter_list|(
name|hte_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * mem2.c  */
end_comment

begin_function_decl
specifier|extern
name|void
name|initmem
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
modifier|*
name|xalloc
parameter_list|(
name|size_t
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * chk.c  */
end_comment

begin_function_decl
specifier|extern
name|void
name|inittyp
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|mainused
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|chkname
parameter_list|(
name|hte_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * msg.c  */
end_comment

begin_function_decl
specifier|extern
name|void
name|msg
parameter_list|(
name|int
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
specifier|const
name|char
modifier|*
name|mkpos
parameter_list|(
name|pos_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * emit2.c  */
end_comment

begin_function_decl
specifier|extern
name|void
name|outlib
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|addoutfile
parameter_list|(
name|short
parameter_list|)
function_decl|;
end_function_decl

end_unit

