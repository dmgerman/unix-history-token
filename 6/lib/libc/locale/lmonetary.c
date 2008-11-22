begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2000, 2001 Alexey Zelkin<phantom@FreeBSD.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_expr_stmt
name|__FBSDID
argument_list|(
literal|"$FreeBSD$"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_include
include|#
directive|include
file|<limits.h>
end_include

begin_include
include|#
directive|include
file|<stddef.h>
end_include

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_include
include|#
directive|include
file|"ldpart.h"
end_include

begin_include
include|#
directive|include
file|"lmonetary.h"
end_include

begin_decl_stmt
specifier|extern
name|int
name|__mlocale_changed
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
specifier|const
name|char
modifier|*
name|__fix_locale_grouping_str
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|LCMONETARY_SIZE_FULL
value|(sizeof(struct lc_monetary_T) / sizeof(char *))
end_define

begin_define
define|#
directive|define
name|LCMONETARY_SIZE_MIN
define|\
value|(offsetof(struct lc_monetary_T, int_p_cs_precedes) / \ 		    sizeof(char *))
end_define

begin_decl_stmt
specifier|static
name|char
name|empty
index|[]
init|=
literal|""
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|char
name|numempty
index|[]
init|=
block|{
name|CHAR_MAX
block|,
literal|'\0'
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|struct
name|lc_monetary_T
name|_C_monetary_locale
init|=
block|{
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
name|numempty
block|,
comment|/* mon_grouping */
name|empty
block|,
comment|/* positive_sign */
name|empty
block|,
comment|/* negative_sign */
name|numempty
block|,
comment|/* int_frac_digits */
name|numempty
block|,
comment|/* frac_digits */
name|numempty
block|,
comment|/* p_cs_precedes */
name|numempty
block|,
comment|/* p_sep_by_space */
name|numempty
block|,
comment|/* n_cs_precedes */
name|numempty
block|,
comment|/* n_sep_by_space */
name|numempty
block|,
comment|/* p_sign_posn */
name|numempty
block|,
comment|/* n_sign_posn */
name|numempty
block|,
comment|/* int_p_cs_precedes */
name|numempty
block|,
comment|/* int_n_cs_precedes */
name|numempty
block|,
comment|/* int_p_sep_by_space */
name|numempty
block|,
comment|/* int_n_sep_by_space */
name|numempty
block|,
comment|/* int_p_sign_posn */
name|numempty
comment|/* int_n_sign_posn */
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|struct
name|lc_monetary_T
name|_monetary_locale
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|int
name|_monetary_using_locale
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|char
modifier|*
name|_monetary_locale_buf
decl_stmt|;
end_decl_stmt

begin_function
specifier|static
name|char
name|cnv
parameter_list|(
specifier|const
name|char
modifier|*
name|str
parameter_list|)
block|{
name|int
name|i
init|=
name|strtol
argument_list|(
name|str
argument_list|,
name|NULL
argument_list|,
literal|10
argument_list|)
decl_stmt|;
if|if
condition|(
name|i
operator|==
operator|-
literal|1
condition|)
name|i
operator|=
name|CHAR_MAX
expr_stmt|;
return|return
operator|(
operator|(
name|char
operator|)
name|i
operator|)
return|;
block|}
end_function

begin_function
name|int
name|__monetary_load_locale
parameter_list|(
specifier|const
name|char
modifier|*
name|name
parameter_list|)
block|{
name|int
name|ret
decl_stmt|;
name|ret
operator|=
name|__part_load_locale
argument_list|(
name|name
argument_list|,
operator|&
name|_monetary_using_locale
argument_list|,
operator|&
name|_monetary_locale_buf
argument_list|,
literal|"LC_MONETARY"
argument_list|,
name|LCMONETARY_SIZE_FULL
argument_list|,
name|LCMONETARY_SIZE_MIN
argument_list|,
operator|(
specifier|const
name|char
operator|*
operator|*
operator|)
operator|&
name|_monetary_locale
argument_list|)
expr_stmt|;
if|if
condition|(
name|ret
operator|!=
name|_LDP_ERROR
condition|)
name|__mlocale_changed
operator|=
literal|1
expr_stmt|;
if|if
condition|(
name|ret
operator|==
name|_LDP_LOADED
condition|)
block|{
name|_monetary_locale
operator|.
name|mon_grouping
operator|=
name|__fix_locale_grouping_str
argument_list|(
name|_monetary_locale
operator|.
name|mon_grouping
argument_list|)
expr_stmt|;
define|#
directive|define
name|M_ASSIGN_CHAR
parameter_list|(
name|NAME
parameter_list|)
value|(((char *)_monetary_locale.NAME)[0] = \ 			     cnv(_monetary_locale.NAME))
name|M_ASSIGN_CHAR
argument_list|(
name|int_frac_digits
argument_list|)
expr_stmt|;
name|M_ASSIGN_CHAR
argument_list|(
name|frac_digits
argument_list|)
expr_stmt|;
name|M_ASSIGN_CHAR
argument_list|(
name|p_cs_precedes
argument_list|)
expr_stmt|;
name|M_ASSIGN_CHAR
argument_list|(
name|p_sep_by_space
argument_list|)
expr_stmt|;
name|M_ASSIGN_CHAR
argument_list|(
name|n_cs_precedes
argument_list|)
expr_stmt|;
name|M_ASSIGN_CHAR
argument_list|(
name|n_sep_by_space
argument_list|)
expr_stmt|;
name|M_ASSIGN_CHAR
argument_list|(
name|p_sign_posn
argument_list|)
expr_stmt|;
name|M_ASSIGN_CHAR
argument_list|(
name|n_sign_posn
argument_list|)
expr_stmt|;
comment|/* 		 * The six additional C99 international monetary formatting 		 * parameters default to the national parameters when 		 * reading FreeBSD LC_MONETARY data files. 		 */
define|#
directive|define
name|M_ASSIGN_ICHAR
parameter_list|(
name|NAME
parameter_list|)
define|\
value|do {							\ 			if (_monetary_locale.int_##NAME == NULL)	\ 				_monetary_locale.int_##NAME =		\ 				    _monetary_locale.NAME;		\ 			else						\ 				M_ASSIGN_CHAR(int_##NAME);		\ 		} while (0)
name|M_ASSIGN_ICHAR
argument_list|(
name|p_cs_precedes
argument_list|)
expr_stmt|;
name|M_ASSIGN_ICHAR
argument_list|(
name|n_cs_precedes
argument_list|)
expr_stmt|;
name|M_ASSIGN_ICHAR
argument_list|(
name|p_sep_by_space
argument_list|)
expr_stmt|;
name|M_ASSIGN_ICHAR
argument_list|(
name|n_sep_by_space
argument_list|)
expr_stmt|;
name|M_ASSIGN_ICHAR
argument_list|(
name|p_sign_posn
argument_list|)
expr_stmt|;
name|M_ASSIGN_ICHAR
argument_list|(
name|n_sign_posn
argument_list|)
expr_stmt|;
block|}
return|return
operator|(
name|ret
operator|)
return|;
block|}
end_function

begin_function
name|struct
name|lc_monetary_T
modifier|*
name|__get_current_monetary_locale
parameter_list|(
name|void
parameter_list|)
block|{
return|return
operator|(
name|_monetary_using_locale
condition|?
operator|&
name|_monetary_locale
else|:
operator|(
expr|struct
name|lc_monetary_T
operator|*
operator|)
operator|&
name|_C_monetary_locale
operator|)
return|;
block|}
end_function

begin_ifdef
ifdef|#
directive|ifdef
name|LOCALE_DEBUG
end_ifdef

begin_function
name|void
name|monetdebug
parameter_list|()
block|{
name|printf
argument_list|(
literal|"int_curr_symbol = %s\n"
literal|"currency_symbol = %s\n"
literal|"mon_decimal_point = %s\n"
literal|"mon_thousands_sep = %s\n"
literal|"mon_grouping = %s\n"
literal|"positive_sign = %s\n"
literal|"negative_sign = %s\n"
literal|"int_frac_digits = %d\n"
literal|"frac_digits = %d\n"
literal|"p_cs_precedes = %d\n"
literal|"p_sep_by_space = %d\n"
literal|"n_cs_precedes = %d\n"
literal|"n_sep_by_space = %d\n"
literal|"p_sign_posn = %d\n"
literal|"n_sign_posn = %d\n"
argument_list|,
literal|"int_p_cs_precedes = %d\n"
literal|"int_p_sep_by_space = %d\n"
literal|"int_n_cs_precedes = %d\n"
literal|"int_n_sep_by_space = %d\n"
literal|"int_p_sign_posn = %d\n"
literal|"int_n_sign_posn = %d\n"
argument_list|,
name|_monetary_locale
operator|.
name|int_curr_symbol
argument_list|,
name|_monetary_locale
operator|.
name|currency_symbol
argument_list|,
name|_monetary_locale
operator|.
name|mon_decimal_point
argument_list|,
name|_monetary_locale
operator|.
name|mon_thousands_sep
argument_list|,
name|_monetary_locale
operator|.
name|mon_grouping
argument_list|,
name|_monetary_locale
operator|.
name|positive_sign
argument_list|,
name|_monetary_locale
operator|.
name|negative_sign
argument_list|,
name|_monetary_locale
operator|.
name|int_frac_digits
index|[
literal|0
index|]
argument_list|,
name|_monetary_locale
operator|.
name|frac_digits
index|[
literal|0
index|]
argument_list|,
name|_monetary_locale
operator|.
name|p_cs_precedes
index|[
literal|0
index|]
argument_list|,
name|_monetary_locale
operator|.
name|p_sep_by_space
index|[
literal|0
index|]
argument_list|,
name|_monetary_locale
operator|.
name|n_cs_precedes
index|[
literal|0
index|]
argument_list|,
name|_monetary_locale
operator|.
name|n_sep_by_space
index|[
literal|0
index|]
argument_list|,
name|_monetary_locale
operator|.
name|p_sign_posn
index|[
literal|0
index|]
argument_list|,
name|_monetary_locale
operator|.
name|n_sign_posn
index|[
literal|0
index|]
argument_list|,
name|_monetary_locale
operator|.
name|int_p_cs_precedes
index|[
literal|0
index|]
argument_list|,
name|_monetary_locale
operator|.
name|int_p_sep_by_space
index|[
literal|0
index|]
argument_list|,
name|_monetary_locale
operator|.
name|int_n_cs_precedes
index|[
literal|0
index|]
argument_list|,
name|_monetary_locale
operator|.
name|int_n_sep_by_space
index|[
literal|0
index|]
argument_list|,
name|_monetary_locale
operator|.
name|int_p_sign_posn
index|[
literal|0
index|]
argument_list|,
name|_monetary_locale
operator|.
name|int_n_sign_posn
index|[
literal|0
index|]
argument_list|)
expr_stmt|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* LOCALE_DEBUG */
end_comment

end_unit

