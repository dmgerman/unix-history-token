begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1991, 1993  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)locale.h	8.1 (Berkeley) 6/2/93  * $FreeBSD$  */
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

begin_include
include|#
directive|include
file|<sys/_null.h>
end_include

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
name|char
name|int_p_cs_precedes
decl_stmt|;
name|char
name|int_n_cs_precedes
decl_stmt|;
name|char
name|int_p_sep_by_space
decl_stmt|;
name|char
name|int_n_sep_by_space
decl_stmt|;
name|char
name|int_p_sign_posn
decl_stmt|;
name|char
name|int_n_sign_posn
decl_stmt|;
block|}
struct|;
end_struct

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
name|LC_MESSAGES
value|6
end_define

begin_define
define|#
directive|define
name|_LC_LAST
value|7
end_define

begin_comment
comment|/* marks end */
end_comment

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_function_decl
name|__BEGIN_DECLS
name|struct
name|lconv
modifier|*
name|localeconv
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|setlocale
parameter_list|(
name|int
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_expr_stmt
name|__END_DECLS
if|#
directive|if
name|__POSIX_VISIBLE
operator|>=
literal|200809
define|#
directive|define
name|LC_COLLATE_MASK
value|(1<<0)
define|#
directive|define
name|LC_CTYPE_MASK
value|(1<<1)
define|#
directive|define
name|LC_MESSAGES_MASK
value|(1<<2)
define|#
directive|define
name|LC_MONETARY_MASK
value|(1<<3)
define|#
directive|define
name|LC_NUMERIC_MASK
value|(1<<4)
define|#
directive|define
name|LC_TIME_MASK
value|(1<<5)
define|#
directive|define
name|LC_ALL_MASK
value|(LC_COLLATE_MASK | LC_CTYPE_MASK | LC_MESSAGES_MASK | \ 		LC_MONETARY_MASK | LC_NUMERIC_MASK | LC_TIME_MASK)
define|#
directive|define
name|LC_GLOBAL_LOCALE
value|((locale_t)-1)
name|__BEGIN_DECLS
end_expr_stmt

begin_typedef
typedef|typedef
name|struct
name|_xlocale
modifier|*
name|locale_t
typedef|;
end_typedef

begin_comment
comment|/**  * Creates a new locale.    */
end_comment

begin_function_decl
name|locale_t
name|newlocale
parameter_list|(
name|int
name|mask
parameter_list|,
specifier|const
name|char
modifier|*
name|locale
parameter_list|,
name|locale_t
name|base
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Returns an identical duplicate of the passed locale.  The returned locale  * must be freed with freelocale().  The returned locale will share components  * with the original.  */
end_comment

begin_function_decl
name|locale_t
name|duplocale
parameter_list|(
name|locale_t
name|base
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Free a locale_t.  This is quite a poorly named function.  It actually  * disclaims a reference to a locale_t, rather than freeing it.    */
end_comment

begin_function_decl
name|int
name|freelocale
parameter_list|(
name|locale_t
name|loc
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Returns the name of the locale for a particular component of a locale_t.  */
end_comment

begin_function_decl
specifier|const
name|char
modifier|*
name|querylocale
parameter_list|(
name|int
name|mask
parameter_list|,
name|locale_t
name|loc
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Installs the specified locale_t as this thread's locale.  */
end_comment

begin_function_decl
name|locale_t
name|uselocale
parameter_list|(
name|locale_t
name|loc
parameter_list|)
function_decl|;
end_function_decl

begin_macro
name|__END_DECLS
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __POSIX_VISIBLE>= 200809 */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _LOCALE_H_ */
end_comment

end_unit

