begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1991, 1993  *	The Regents of the University of California.  All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Kenneth Almquist.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)var.h	8.2 (Berkeley) 5/4/95  * $FreeBSD$  */
end_comment

begin_comment
comment|/*  * Shell variables.  */
end_comment

begin_comment
comment|/* flags */
end_comment

begin_define
define|#
directive|define
name|VEXPORT
value|0x01
end_define

begin_comment
comment|/* variable is exported */
end_comment

begin_define
define|#
directive|define
name|VREADONLY
value|0x02
end_define

begin_comment
comment|/* variable cannot be modified */
end_comment

begin_define
define|#
directive|define
name|VSTRFIXED
value|0x04
end_define

begin_comment
comment|/* variable struct is staticly allocated */
end_comment

begin_define
define|#
directive|define
name|VTEXTFIXED
value|0x08
end_define

begin_comment
comment|/* text is staticly allocated */
end_comment

begin_define
define|#
directive|define
name|VSTACK
value|0x10
end_define

begin_comment
comment|/* text is allocated on the stack */
end_comment

begin_define
define|#
directive|define
name|VUNSET
value|0x20
end_define

begin_comment
comment|/* the variable is not set */
end_comment

begin_define
define|#
directive|define
name|VNOFUNC
value|0x40
end_define

begin_comment
comment|/* don't call the callback function */
end_comment

begin_struct
struct|struct
name|var
block|{
name|struct
name|var
modifier|*
name|next
decl_stmt|;
comment|/* next entry in hash list */
name|int
name|flags
decl_stmt|;
comment|/* flags are defined above */
name|char
modifier|*
name|text
decl_stmt|;
comment|/* name=value */
name|void
function_decl|(
modifier|*
name|func
function_decl|)
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
comment|/* function to be called when  */
comment|/* the variable gets set/unset */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|localvar
block|{
name|struct
name|localvar
modifier|*
name|next
decl_stmt|;
comment|/* next local variable in list */
name|struct
name|var
modifier|*
name|vp
decl_stmt|;
comment|/* the variable that was made local */
name|int
name|flags
decl_stmt|;
comment|/* saved flags */
name|char
modifier|*
name|text
decl_stmt|;
comment|/* saved text */
block|}
struct|;
end_struct

begin_decl_stmt
name|struct
name|localvar
modifier|*
name|localvars
decl_stmt|;
end_decl_stmt

begin_if
if|#
directive|if
name|ATTY
end_if

begin_decl_stmt
specifier|extern
name|struct
name|var
name|vatty
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
specifier|extern
name|struct
name|var
name|vifs
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|var
name|vmail
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|var
name|vmpath
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|var
name|vpath
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|var
name|vps1
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|var
name|vps2
decl_stmt|;
end_decl_stmt

begin_if
if|#
directive|if
name|ATTY
end_if

begin_decl_stmt
specifier|extern
name|struct
name|var
name|vterm
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|NO_HISTORY
end_ifndef

begin_decl_stmt
specifier|extern
name|struct
name|var
name|vhistsize
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * The following macros access the values of the above variables.  * They have to skip over the name.  They return the null string  * for unset variables.  */
end_comment

begin_define
define|#
directive|define
name|ifsval
parameter_list|()
value|(vifs.text + 4)
end_define

begin_define
define|#
directive|define
name|ifsset
parameter_list|()
value|((vifs.flags& VUNSET) == 0)
end_define

begin_define
define|#
directive|define
name|mailval
parameter_list|()
value|(vmail.text + 5)
end_define

begin_define
define|#
directive|define
name|mpathval
parameter_list|()
value|(vmpath.text + 9)
end_define

begin_define
define|#
directive|define
name|pathval
parameter_list|()
value|(vpath.text + 5)
end_define

begin_define
define|#
directive|define
name|ps1val
parameter_list|()
value|(vps1.text + 4)
end_define

begin_define
define|#
directive|define
name|ps2val
parameter_list|()
value|(vps2.text + 4)
end_define

begin_if
if|#
directive|if
name|ATTY
end_if

begin_define
define|#
directive|define
name|termval
parameter_list|()
value|(vterm.text + 5)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|optindval
parameter_list|()
value|(voptind.text + 7)
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|NO_HISTORY
end_ifndef

begin_define
define|#
directive|define
name|histsizeval
parameter_list|()
value|(vhistsize.text + 9)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|ATTY
end_if

begin_define
define|#
directive|define
name|attyset
parameter_list|()
value|((vatty.flags& VUNSET) == 0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|mpathset
parameter_list|()
value|((vmpath.flags& VUNSET) == 0)
end_define

begin_function_decl
name|void
name|initvar
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|setvar
parameter_list|(
name|char
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
name|void
name|setvareq
parameter_list|(
name|char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_struct_decl
struct_decl|struct
name|strlist
struct_decl|;
end_struct_decl

begin_function_decl
name|void
name|listsetvar
parameter_list|(
name|struct
name|strlist
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|lookupvar
parameter_list|(
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|bltinlookup
parameter_list|(
name|char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
modifier|*
name|environment
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|shprocvar
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|showvarscmd
parameter_list|(
name|int
parameter_list|,
name|char
modifier|*
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|exportcmd
parameter_list|(
name|int
parameter_list|,
name|char
modifier|*
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|localcmd
parameter_list|(
name|int
parameter_list|,
name|char
modifier|*
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|mklocal
parameter_list|(
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|poplocalvars
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|setvarcmd
parameter_list|(
name|int
parameter_list|,
name|char
modifier|*
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|unsetcmd
parameter_list|(
name|int
parameter_list|,
name|char
modifier|*
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|unsetvar
parameter_list|(
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|setvarsafe
parameter_list|(
name|char
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

end_unit

