begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1991 The Regents of the University of California.  * All rights reserved.  *  * %sccs.include.redist.c%  *  *	@(#)locale.h	5.1 (Berkeley) %G%  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_LOCALE_H_
end_ifndef

begin_define
define|#
directive|define
name|_LOCALE_H_
end_define

begin_struct
struct|struct
name|lconv
block|{
name|char
modifier|*
name|decimal_point
decl_stmt|;
name|char
modifier|*
name|thousands_sep
decl_stmt|;
name|char
modifier|*
name|grouping
decl_stmt|;
name|char
modifier|*
name|int_curr_symbol
decl_stmt|;
name|char
modifier|*
name|currency_symbol
decl_stmt|;
name|char
modifier|*
name|mon_decimal_point
decl_stmt|;
name|char
modifier|*
name|mon_thousands_sep
decl_stmt|;
name|char
modifier|*
name|mon_grouping
decl_stmt|;
name|char
modifier|*
name|positive_sign
decl_stmt|;
name|char
modifier|*
name|negative_sign
decl_stmt|;
name|char
name|int_frac_digits
decl_stmt|;
name|char
name|frac_digits
decl_stmt|;
name|char
name|p_cs_precedes
decl_stmt|;
name|char
name|p_sep_by_space
decl_stmt|;
name|char
name|n_cs_precedes
decl_stmt|;
name|char
name|n_sep_by_space
decl_stmt|;
name|char
name|p_sign_posn
decl_stmt|;
name|char
name|n_sign_posn
decl_stmt|;
block|}
struct|;
end_struct

begin_ifndef
ifndef|#
directive|ifndef
name|NULL
end_ifndef

begin_define
define|#
directive|define
name|NULL
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|LC_ALL
value|0
end_define

begin_define
define|#
directive|define
name|LC_COLLATE
value|1
end_define

begin_define
define|#
directive|define
name|LC_CTYPE
value|2
end_define

begin_define
define|#
directive|define
name|LC_MONETARY
value|3
end_define

begin_define
define|#
directive|define
name|LC_NUMERIC
value|4
end_define

begin_define
define|#
directive|define
name|LC_TIME
value|5
end_define

begin_define
define|#
directive|define
name|_LC_LAST
value|6
end_define

begin_comment
comment|/* marks end */
end_comment

begin_if
if|#
directive|if
name|__STDC__
operator|||
name|c_plusplus
end_if

begin_function_decl
name|char
modifier|*
name|setlocale
parameter_list|(
name|int
name|_category
parameter_list|,
specifier|const
name|char
modifier|*
name|_locale
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|lconv
modifier|*
name|localeconv
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_else
else|#
directive|else
end_else

begin_function_decl
name|char
modifier|*
name|setlocale
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|lconv
modifier|*
name|localeconv
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _LOCALE_H_ */
end_comment

end_unit

