begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* argmatch.h -- definitions and prototypes for argmatch.c     Copyright (C) 1990, 1998, 1999, 2001, 2002, 2004 Free Software    Foundation, Inc.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2, or (at your option)    any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software Foundation,    Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_comment
comment|/* Written by David MacKenzie<djm@ai.mit.edu>    Modified by Akim Demaille<demaille@inf.enst.fr> */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|ARGMATCH_H_
end_ifndef

begin_define
define|#
directive|define
name|ARGMATCH_H_
value|1
end_define

begin_include
include|#
directive|include
file|<stddef.h>
end_include

begin_define
define|#
directive|define
name|ARRAY_CARDINALITY
parameter_list|(
name|Array
parameter_list|)
value|(sizeof (Array) / sizeof *(Array))
end_define

begin_define
define|#
directive|define
name|ARGMATCH_CONSTRAINT
parameter_list|(
name|Arglist
parameter_list|,
name|Vallist
parameter_list|)
define|\
value|(ARRAY_CARDINALITY (Arglist) == ARRAY_CARDINALITY (Vallist) + 1)
end_define

begin_comment
comment|/* Assert there are as many real arguments as there are values    (argument list ends with a NULL guard).  ARGMATCH_VERIFY is    preferred, since it is guaranteed to be checked at compile-time.    ARGMATCH_ASSERT is for backward compatibility only.  */
end_comment

begin_define
define|#
directive|define
name|ARGMATCH_VERIFY
parameter_list|(
name|Arglist
parameter_list|,
name|Vallist
parameter_list|)
define|\
value|struct argmatch_verify						  \   {									  \     char argmatch_verify[ARGMATCH_CONSTRAINT(Arglist, Vallist) ? 1 : -1]; \   }
end_define

begin_define
define|#
directive|define
name|ARGMATCH_ASSERT
parameter_list|(
name|Arglist
parameter_list|,
name|Vallist
parameter_list|)
define|\
value|assert (ARGMATCH_CONSTRAINT (Arglist, Vallist))
end_define

begin_comment
comment|/* Return the index of the element of ARGLIST (NULL terminated) that    matches with ARG.  If VALLIST is not NULL, then use it to resolve    false ambiguities (i.e., different matches of ARG but corresponding    to the same values in VALLIST).  */
end_comment

begin_function_decl
name|ptrdiff_t
name|argmatch
parameter_list|(
name|char
specifier|const
modifier|*
name|arg
parameter_list|,
name|char
specifier|const
modifier|*
specifier|const
modifier|*
name|arglist
parameter_list|,
name|char
specifier|const
modifier|*
name|vallist
parameter_list|,
name|size_t
name|valsize
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|ARGMATCH
parameter_list|(
name|Arg
parameter_list|,
name|Arglist
parameter_list|,
name|Vallist
parameter_list|)
define|\
value|argmatch (Arg, Arglist, (char const *) (Vallist), sizeof *(Vallist))
end_define

begin_comment
comment|/* xargmatch calls this function when it fails.  This function should not    return.  By default, this is a function that calls ARGMATCH_DIE which    in turn defaults to `exit (exit_failure)'.  */
end_comment

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|argmatch_exit_fn
function_decl|)
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_typedef

begin_decl_stmt
specifier|extern
name|argmatch_exit_fn
name|argmatch_die
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Report on stderr why argmatch failed.  Report correct values. */
end_comment

begin_function_decl
name|void
name|argmatch_invalid
parameter_list|(
name|char
specifier|const
modifier|*
name|context
parameter_list|,
name|char
specifier|const
modifier|*
name|value
parameter_list|,
name|ptrdiff_t
name|problem
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Left for compatibility with the old name invalid_arg */
end_comment

begin_define
define|#
directive|define
name|invalid_arg
parameter_list|(
name|Context
parameter_list|,
name|Value
parameter_list|,
name|Problem
parameter_list|)
define|\
value|argmatch_invalid (Context, Value, Problem)
end_define

begin_comment
comment|/* Report on stderr the list of possible arguments.  */
end_comment

begin_function_decl
name|void
name|argmatch_valid
parameter_list|(
name|char
specifier|const
modifier|*
specifier|const
modifier|*
name|arglist
parameter_list|,
name|char
specifier|const
modifier|*
name|vallist
parameter_list|,
name|size_t
name|valsize
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|ARGMATCH_VALID
parameter_list|(
name|Arglist
parameter_list|,
name|Vallist
parameter_list|)
define|\
value|argmatch_valid (Arglist, (char const *) (Vallist), sizeof *(Vallist))
end_define

begin_comment
comment|/* Same as argmatch, but upon failure, reports a explanation on the    failure, and exits using the function EXIT_FN. */
end_comment

begin_function_decl
name|ptrdiff_t
name|__xargmatch_internal
parameter_list|(
name|char
specifier|const
modifier|*
name|context
parameter_list|,
name|char
specifier|const
modifier|*
name|arg
parameter_list|,
name|char
specifier|const
modifier|*
specifier|const
modifier|*
name|arglist
parameter_list|,
name|char
specifier|const
modifier|*
name|vallist
parameter_list|,
name|size_t
name|valsize
parameter_list|,
name|argmatch_exit_fn
name|exit_fn
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Programmer friendly interface to __xargmatch_internal. */
end_comment

begin_define
define|#
directive|define
name|XARGMATCH
parameter_list|(
name|Context
parameter_list|,
name|Arg
parameter_list|,
name|Arglist
parameter_list|,
name|Vallist
parameter_list|)
define|\
value|((Vallist) [__xargmatch_internal (Context, Arg, Arglist,	\ 				    (char const *) (Vallist),	\ 				    sizeof *(Vallist),		\ 				    argmatch_die)])
end_define

begin_comment
comment|/* Convert a value into a corresponding argument. */
end_comment

begin_function_decl
name|char
specifier|const
modifier|*
name|argmatch_to_argument
parameter_list|(
name|char
specifier|const
modifier|*
name|value
parameter_list|,
name|char
specifier|const
modifier|*
specifier|const
modifier|*
name|arglist
parameter_list|,
name|char
specifier|const
modifier|*
name|vallist
parameter_list|,
name|size_t
name|valsize
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|ARGMATCH_TO_ARGUMENT
parameter_list|(
name|Value
parameter_list|,
name|Arglist
parameter_list|,
name|Vallist
parameter_list|)
define|\
value|argmatch_to_argument (Value, Arglist,					\ 			(char const *) (Vallist), sizeof *(Vallist))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ARGMATCH_H_ */
end_comment

end_unit

