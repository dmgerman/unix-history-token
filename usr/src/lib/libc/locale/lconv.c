begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1991, 1993  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|LIBC_SCCS
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|lint
argument_list|)
end_if

begin_decl_stmt
specifier|static
name|char
name|sccsid
index|[]
init|=
literal|"@(#)lconv.c	8.1 (Berkeley) 6/4/93"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* LIBC_SCCS and not lint */
end_comment

begin_include
include|#
directive|include
file|<limits.h>
end_include

begin_include
include|#
directive|include
file|<locale.h>
end_include

begin_decl_stmt
specifier|static
name|char
name|empty
index|[]
init|=
literal|""
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * Default (C) locale conversion.  */
end_comment

begin_decl_stmt
specifier|static
name|struct
name|lconv
name|C_lconv
init|=
block|{
literal|"."
block|,
comment|/* decimal_point */
name|empty
block|,
comment|/* thousands_sep */
name|empty
block|,
comment|/* grouping */
name|empty
block|,
comment|/* int_curr_symbol */
name|empty
block|,
comment|/* currency_symbol */
name|empty
block|,
comment|/* mon_decimal_point */
name|empty
block|,
comment|/* mon_thousands_sep */
name|empty
block|,
comment|/* mon_grouping */
name|empty
block|,
comment|/* positive_sign */
name|empty
block|,
comment|/* negative_sign */
name|CHAR_MAX
block|,
comment|/* int_frac_digits */
name|CHAR_MAX
block|,
comment|/* frac_digits */
name|CHAR_MAX
block|,
comment|/* p_cs_precedes */
name|CHAR_MAX
block|,
comment|/* p_sep_by_space */
name|CHAR_MAX
block|,
comment|/* n_cs_precedes */
name|CHAR_MAX
block|,
comment|/* n_sep_by_space */
name|CHAR_MAX
block|,
comment|/* p_sign_posn */
name|CHAR_MAX
block|,
comment|/* n_sign_posn */
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * Current locale conversion.  */
end_comment

begin_decl_stmt
name|struct
name|lconv
modifier|*
name|__lconv
init|=
operator|&
name|C_lconv
decl_stmt|;
end_decl_stmt

end_unit

