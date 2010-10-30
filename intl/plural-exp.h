begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Expression parsing and evaluation for plural form selection.    Copyright (C) 2000, 2001, 2002 Free Software Foundation, Inc.    Written by Ulrich Drepper<drepper@cygnus.com>, 2000.     This program is free software; you can redistribute it and/or modify it    under the terms of the GNU Library General Public License as published    by the Free Software Foundation; either version 2, or (at your option)    any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU    Library General Public License for more details.     You should have received a copy of the GNU Library General Public    License along with this program; if not, write to the Free Software    Foundation, Inc., 51 Franklin Street - Fifth Floor, Boston, MA 02110-1301,    USA.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_PLURAL_EXP_H
end_ifndef

begin_define
define|#
directive|define
name|_PLURAL_EXP_H
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|PARAMS
end_ifndef

begin_if
if|#
directive|if
name|__STDC__
operator|||
name|defined
name|__GNUC__
operator|||
name|defined
name|__SUNPRO_C
operator|||
name|defined
name|__cplusplus
operator|||
name|__PROTOTYPES
end_if

begin_define
define|#
directive|define
name|PARAMS
parameter_list|(
name|args
parameter_list|)
value|args
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|PARAMS
parameter_list|(
name|args
parameter_list|)
value|()
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|internal_function
end_ifndef

begin_define
define|#
directive|define
name|internal_function
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|attribute_hidden
end_ifndef

begin_define
define|#
directive|define
name|attribute_hidden
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* This is the representation of the expressions to determine the    plural form.  */
end_comment

begin_struct
struct|struct
name|expression
block|{
name|int
name|nargs
decl_stmt|;
comment|/* Number of arguments.  */
enum|enum
name|operator
block|{
comment|/* Without arguments:  */
name|var
block|,
comment|/* The variable "n".  */
name|num
block|,
comment|/* Decimal number.  */
comment|/* Unary operators:  */
name|lnot
block|,
comment|/* Logical NOT.  */
comment|/* Binary operators:  */
name|mult
block|,
comment|/* Multiplication.  */
name|divide
block|,
comment|/* Division.  */
name|module
block|,
comment|/* Modulo operation.  */
name|plus
block|,
comment|/* Addition.  */
name|minus
block|,
comment|/* Subtraction.  */
name|less_than
block|,
comment|/* Comparison.  */
name|greater_than
block|,
comment|/* Comparison.  */
name|less_or_equal
block|,
comment|/* Comparison.  */
name|greater_or_equal
block|,
comment|/* Comparison.  */
name|equal
block|,
comment|/* Comparison for equality.  */
name|not_equal
block|,
comment|/* Comparison for inequality.  */
name|land
block|,
comment|/* Logical AND.  */
name|lor
block|,
comment|/* Logical OR.  */
comment|/* Ternary operators:  */
name|qmop
comment|/* Question mark operator.  */
block|}
name|operation
enum|;
union|union
block|{
name|unsigned
name|long
name|int
name|num
decl_stmt|;
comment|/* Number value for `num'.  */
name|struct
name|expression
modifier|*
name|args
index|[
literal|3
index|]
decl_stmt|;
comment|/* Up to three arguments.  */
block|}
name|val
union|;
block|}
struct|;
end_struct

begin_comment
comment|/* This is the data structure to pass information to the parser and get    the result in a thread-safe way.  */
end_comment

begin_struct
struct|struct
name|parse_args
block|{
specifier|const
name|char
modifier|*
name|cp
decl_stmt|;
name|struct
name|expression
modifier|*
name|res
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* Names for the libintl functions are a problem.  This source code is used    1. in the GNU C Library library,    2. in the GNU libintl library,    3. in the GNU gettext tools.    The function names in each situation must be different, to allow for    binary incompatible changes in 'struct expression'.  Furthermore,    1. in the GNU C Library library, the names have a __ prefix,    2.+3. in the GNU libintl library and in the GNU gettext tools, the names          must follow ANSI C and not start with __.    So we have to distinguish the three cases.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|_LIBC
end_ifdef

begin_define
define|#
directive|define
name|FREE_EXPRESSION
value|__gettext_free_exp
end_define

begin_define
define|#
directive|define
name|PLURAL_PARSE
value|__gettextparse
end_define

begin_define
define|#
directive|define
name|GERMANIC_PLURAL
value|__gettext_germanic_plural
end_define

begin_define
define|#
directive|define
name|EXTRACT_PLURAL_EXPRESSION
value|__gettext_extract_plural
end_define

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|IN_LIBINTL
argument_list|)
end_elif

begin_define
define|#
directive|define
name|FREE_EXPRESSION
value|libintl_gettext_free_exp
end_define

begin_define
define|#
directive|define
name|PLURAL_PARSE
value|libintl_gettextparse
end_define

begin_define
define|#
directive|define
name|GERMANIC_PLURAL
value|libintl_gettext_germanic_plural
end_define

begin_define
define|#
directive|define
name|EXTRACT_PLURAL_EXPRESSION
value|libintl_gettext_extract_plural
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|FREE_EXPRESSION
value|free_plural_expression
end_define

begin_define
define|#
directive|define
name|PLURAL_PARSE
value|parse_plural_expression
end_define

begin_define
define|#
directive|define
name|GERMANIC_PLURAL
value|germanic_plural
end_define

begin_define
define|#
directive|define
name|EXTRACT_PLURAL_EXPRESSION
value|extract_plural_expression
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
specifier|extern
name|void
name|FREE_EXPRESSION
name|PARAMS
argument_list|(
operator|(
expr|struct
name|expression
operator|*
name|exp
operator|)
argument_list|)
name|internal_function
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|PLURAL_PARSE
name|PARAMS
argument_list|(
operator|(
name|void
operator|*
name|arg
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|expression
name|GERMANIC_PLURAL
name|attribute_hidden
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|EXTRACT_PLURAL_EXPRESSION
name|PARAMS
argument_list|(
operator|(
specifier|const
name|char
operator|*
name|nullentry
operator|,
expr|struct
name|expression
operator|*
operator|*
name|pluralp
operator|,
name|unsigned
name|long
name|int
operator|*
name|npluralsp
operator|)
argument_list|)
name|internal_function
decl_stmt|;
end_decl_stmt

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|_LIBC
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|IN_LIBINTL
argument_list|)
end_if

begin_decl_stmt
specifier|extern
name|unsigned
name|long
name|int
name|plural_eval
name|PARAMS
argument_list|(
operator|(
expr|struct
name|expression
operator|*
name|pexp
operator|,
name|unsigned
name|long
name|int
name|n
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _PLURAL_EXP_H */
end_comment

end_unit

