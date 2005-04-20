begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1983, 1993  *	The Regents of the University of California.  All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Edward Wang at The University of California, Berkeley.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
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
literal|"@(#)ttf100.c	8.1 (Berkeley) 6/6/93"
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|char
name|rcsid
index|[]
init|=
literal|"$FreeBSD$"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not lint */
end_comment

begin_include
include|#
directive|include
file|"ww.h"
end_include

begin_include
include|#
directive|include
file|"tt.h"
end_include

begin_comment
comment|/*  * Freedom 100  */
end_comment

begin_define
define|#
directive|define
name|G
value|(WWM_GRP<< WWC_MSHIFT)
end_define

begin_decl_stmt
name|short
name|f100_frame
index|[
literal|16
index|]
init|=
block|{
literal|' '
block|,
literal|'J'
operator||
name|G
block|,
literal|'K'
operator||
name|G
block|,
literal|'A'
operator||
name|G
block|,
literal|'J'
operator||
name|G
block|,
literal|'J'
operator||
name|G
block|,
literal|'B'
operator||
name|G
block|,
literal|'M'
operator||
name|G
block|,
literal|'K'
operator||
name|G
block|,
literal|'D'
operator||
name|G
block|,
literal|'K'
operator||
name|G
block|,
literal|'O'
operator||
name|G
block|,
literal|'C'
operator||
name|G
block|,
literal|'L'
operator||
name|G
block|,
literal|'N'
operator||
name|G
block|,
literal|'I'
operator||
name|G
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|tt_str
modifier|*
name|gen_AE
decl_stmt|,
modifier|*
name|gen_AS
decl_stmt|;
end_decl_stmt

begin_macro
name|tt_f100
argument_list|()
end_macro

begin_block
block|{
specifier|static
name|struct
name|tt_str
name|ae
init|=
block|{
literal|"\033%"
block|,
literal|2
block|}
decl_stmt|;
specifier|static
name|struct
name|tt_str
name|as
init|=
block|{
literal|"\033$"
block|,
literal|2
block|}
decl_stmt|;
if|if
condition|(
name|tt_generic
argument_list|()
operator|<
literal|0
condition|)
return|return
operator|-
literal|1
return|;
name|tt
operator|.
name|tt_frame
operator|=
name|f100_frame
expr_stmt|;
name|tt
operator|.
name|tt_availmodes
operator||=
name|WWM_GRP
expr_stmt|;
name|gen_AS
operator|=
operator|&
name|as
expr_stmt|;
name|gen_AE
operator|=
operator|&
name|ae
expr_stmt|;
return|return
literal|0
return|;
block|}
end_block

end_unit

