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
file|"lnumeric.h"
end_include

begin_include
include|#
directive|include
file|"ldpart.h"
end_include

begin_decl_stmt
specifier|extern
name|int
name|__nlocale_changed
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
name|LCNUMERIC_SIZE
value|(sizeof(struct lc_numeric_T) / sizeof(char *))
end_define

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
name|lc_numeric_T
name|_C_numeric_locale
init|=
block|{
literal|"."
block|,
comment|/* decimal_point */
literal|""
block|,
comment|/* thousands_sep */
name|numempty
comment|/* grouping */
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|struct
name|lc_numeric_T
name|_numeric_locale
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|int
name|_numeric_using_locale
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|char
modifier|*
name|_numeric_locale_buf
decl_stmt|;
end_decl_stmt

begin_function
name|int
name|__numeric_load_locale
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
name|__nlocale_changed
operator|=
literal|1
expr_stmt|;
name|ret
operator|=
name|__part_load_locale
argument_list|(
name|name
argument_list|,
operator|&
name|_numeric_using_locale
argument_list|,
name|_numeric_locale_buf
argument_list|,
literal|"LC_NUMERIC"
argument_list|,
name|LCNUMERIC_SIZE
argument_list|,
name|LCNUMERIC_SIZE
argument_list|,
operator|(
specifier|const
name|char
operator|*
operator|*
operator|)
operator|&
name|_numeric_locale
argument_list|)
expr_stmt|;
if|if
condition|(
name|ret
operator|==
literal|0
operator|&&
name|_numeric_using_locale
condition|)
name|_numeric_locale
operator|.
name|grouping
operator|=
name|__fix_locale_grouping_str
argument_list|(
name|_numeric_locale
operator|.
name|grouping
argument_list|)
expr_stmt|;
return|return
name|ret
return|;
block|}
end_function

begin_function
name|struct
name|lc_numeric_T
modifier|*
name|__get_current_numeric_locale
parameter_list|(
name|void
parameter_list|)
block|{
return|return
operator|(
name|_numeric_using_locale
condition|?
operator|&
name|_numeric_locale
else|:
operator|(
expr|struct
name|lc_numeric_T
operator|*
operator|)
operator|&
name|_C_numeric_locale
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
name|numericdebug
parameter_list|(
name|void
parameter_list|)
block|{
name|printf
argument_list|(
literal|"decimal_point = %s\n"
literal|"thousands_sep = %s\n"
literal|"grouping = %s\n"
argument_list|,
name|_numeric_locale
operator|.
name|decimal_point
argument_list|,
name|_numeric_locale
operator|.
name|thousands_sep
argument_list|,
name|_numeric_locale
operator|.
name|grouping
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

