begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1980, 1993  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
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
literal|"@(#)roll.c	8.1 (Berkeley) 5/31/93"
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
comment|/*  *	This routine rolls ndie nside-sided dice.  */
end_comment

begin_define
define|#
directive|define
name|reg
value|register
end_define

begin_if
if|#
directive|if
name|defined
argument_list|(
name|pdp11
argument_list|)
end_if

begin_define
define|#
directive|define
name|MAXRAND
value|32767L
end_define

begin_macro
name|roll
argument_list|(
argument|ndie
argument_list|,
argument|nsides
argument_list|)
end_macro

begin_decl_stmt
name|int
name|ndie
decl_stmt|,
name|nsides
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|reg
name|long
name|tot
decl_stmt|;
name|reg
name|unsigned
name|n
decl_stmt|,
name|r
decl_stmt|;
name|tot
operator|=
literal|0
expr_stmt|;
name|n
operator|=
name|ndie
expr_stmt|;
while|while
condition|(
name|n
operator|--
condition|)
name|tot
operator|+=
name|rand
argument_list|()
expr_stmt|;
return|return
call|(
name|int
call|)
argument_list|(
operator|(
name|tot
operator|*
operator|(
name|long
operator|)
name|nsides
operator|)
operator|/
operator|(
operator|(
name|long
operator|)
name|MAXRAND
operator|+
literal|1
operator|)
argument_list|)
operator|+
name|ndie
return|;
block|}
end_block

begin_else
else|#
directive|else
end_else

begin_macro
name|roll
argument_list|(
argument|ndie
argument_list|,
argument|nsides
argument_list|)
end_macro

begin_decl_stmt
name|reg
name|int
name|ndie
decl_stmt|,
name|nsides
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|reg
name|int
name|tot
decl_stmt|,
name|r
decl_stmt|;
name|reg
name|double
name|num_sides
decl_stmt|;
name|num_sides
operator|=
name|nsides
expr_stmt|;
name|tot
operator|=
literal|0
expr_stmt|;
while|while
condition|(
name|ndie
operator|--
condition|)
name|tot
operator|+=
operator|(
name|r
operator|=
name|rand
argument_list|()
operator|)
operator|*
operator|(
name|num_sides
operator|/
literal|017777777777
operator|)
operator|+
literal|1
expr_stmt|;
return|return
name|tot
return|;
block|}
end_block

begin_endif
endif|#
directive|endif
end_endif

end_unit

