begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Declaration for error-reporting function    Copyright (C) 1995, 1996, 1997 Free Software Foundation, Inc.      NOTE: The canonical source of this file is maintained with the GNU C Library.    Bugs can be reported to bug-glibc@prep.ai.mit.edu.     This program is free software; you can redistribute it and/or modify it    under the terms of the GNU General Public License as published by the    Free Software Foundation; either version 2, or (at your option) any    later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software    Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307,    USA.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_ERROR_H
end_ifndef

begin_define
define|#
directive|define
name|_ERROR_H
value|1
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|__attribute__
end_ifndef

begin_comment
comment|/* This feature is available in gcc versions 2.5 and later.  */
end_comment

begin_if
if|#
directive|if
name|__GNUC__
operator|<
literal|2
operator|||
operator|(
name|__GNUC__
operator|==
literal|2
operator|&&
name|__GNUC_MINOR__
operator|<
literal|5
operator|)
operator|||
name|__STRICT_ANSI__
end_if

begin_define
define|#
directive|define
name|__attribute__
parameter_list|(
name|Spec
parameter_list|)
end_define

begin_comment
comment|/* empty */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* The __-protected variants of `format' and `printf' attributes    are accepted by gcc versions 2.6.4 (effectively 2.7) and later.  */
end_comment

begin_if
if|#
directive|if
name|__GNUC__
operator|<
literal|2
operator|||
operator|(
name|__GNUC__
operator|==
literal|2
operator|&&
name|__GNUC_MINOR__
operator|<
literal|7
operator|)
end_if

begin_define
define|#
directive|define
name|__format__
value|format
end_define

begin_define
define|#
directive|define
name|__printf__
value|printf
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|__cplusplus
end_ifdef

begin_extern
extern|extern
literal|"C"
block|{
endif|#
directive|endif
if|#
directive|if
name|defined
argument_list|(
name|__STDC__
argument_list|)
operator|&&
name|__STDC__
comment|/* Print a message with `fprintf (stderr, FORMAT, ...)';    if ERRNUM is nonzero, follow it with ": " and strerror (ERRNUM).    If STATUS is nonzero, terminate the program with `exit (STATUS)'.  */
specifier|extern
name|void
name|error
parameter_list|(
name|int
name|status
parameter_list|,
name|int
name|errnum
parameter_list|,
specifier|const
name|char
modifier|*
name|format
parameter_list|,
modifier|...
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(__format__
parameter_list|(
name|__printf__
parameter_list|,
function_decl|3
operator|,
function_decl|4
block|)
end_extern

begin_empty_stmt
unit|))
empty_stmt|;
end_empty_stmt

begin_function_decl
specifier|extern
name|void
name|error_at_line
parameter_list|(
name|int
name|status
parameter_list|,
name|int
name|errnum
parameter_list|,
specifier|const
name|char
modifier|*
name|fname
parameter_list|,
name|unsigned
name|int
name|lineno
parameter_list|,
specifier|const
name|char
modifier|*
name|format
parameter_list|,
modifier|...
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(__format__
parameter_list|(
name|__printf__
parameter_list|,
function_decl|5
operator|,
function_decl|6
end_function_decl

begin_empty_stmt
unit|)))
empty_stmt|;
end_empty_stmt

begin_comment
comment|/* If NULL, error will flush stdout, then print on stderr the program    name, a colon and a space.  Otherwise, error will call this    function without parameters instead.  */
end_comment

begin_function_decl
specifier|extern
name|void
function_decl|(
modifier|*
name|error_print_progname
function_decl|)
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
name|void
name|error
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|error_at_line
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
function_decl|(
modifier|*
name|error_print_progname
function_decl|)
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* This variable is incremented each time `error' is called.  */
end_comment

begin_decl_stmt
specifier|extern
name|unsigned
name|int
name|error_message_count
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Sometimes we want to have at most one error per line.  This    variable controls whether this mode is selected or not.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|error_one_per_line
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|__cplusplus
end_ifdef

begin_endif
unit|}
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* error.h */
end_comment

end_unit

