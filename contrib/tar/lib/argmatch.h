begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* argmatch.h -- definitions and prototypes for argmatch.c    Copyright (C) 1990, 1998, 1999 Free Software Foundation, Inc.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2, or (at your option)    any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software Foundation,    Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
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

begin_if
if|#
directive|if
name|HAVE_CONFIG_H
end_if

begin_include
include|#
directive|include
file|<config.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|PARAMS
end_ifndef

begin_if
if|#
directive|if
name|PROTOTYPES
operator|||
operator|(
name|defined
argument_list|(
name|__STDC__
argument_list|)
operator|&&
name|__STDC__
operator|)
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

begin_comment
comment|/* GCC.  */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Not PARAMS.  */
end_comment

begin_comment
comment|/* Assert there are as many real arguments as there are values    (argument list ends with a NULL guard).  There is no execution    cost, since it will be statically evalauted to `assert (0)' or    `assert (1)'.  Unfortunately there is no -Wassert-0. */
end_comment

begin_undef
undef|#
directive|undef
name|ARRAY_CARDINALITY
end_undef

begin_define
define|#
directive|define
name|ARRAY_CARDINALITY
parameter_list|(
name|Array
parameter_list|)
value|(sizeof ((Array)) / sizeof (*(Array)))
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
value|assert (ARRAY_CARDINALITY ((Arglist)) == ARRAY_CARDINALITY ((Vallist)) + 1)
end_define

begin_comment
comment|/* Return the index of the element of ARGLIST (NULL terminated) that    matches with ARG.  If VALLIST is not NULL, then use it to resolve    false ambiguities (i.e., different matches of ARG but corresponding    to the same values in VALLIST).  */
end_comment

begin_decl_stmt
name|int
name|argmatch
name|PARAMS
argument_list|(
operator|(
specifier|const
name|char
operator|*
name|arg
operator|,
specifier|const
name|char
operator|*
specifier|const
operator|*
name|arglist
operator|,
specifier|const
name|char
operator|*
name|vallist
operator|,
name|size_t
name|valsize
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|argcasematch
name|PARAMS
argument_list|(
operator|(
specifier|const
name|char
operator|*
name|arg
operator|,
specifier|const
name|char
operator|*
specifier|const
operator|*
name|arglist
operator|,
specifier|const
name|char
operator|*
name|vallist
operator|,
name|size_t
name|valsize
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

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
value|argmatch ((Arg), (Arglist), (const char *) (Vallist), sizeof (*(Vallist)))
end_define

begin_define
define|#
directive|define
name|ARGCASEMATCH
parameter_list|(
name|Arg
parameter_list|,
name|Arglist
parameter_list|,
name|Vallist
parameter_list|)
define|\
value|argcasematch ((Arg), (Arglist), (const char *) (Vallist), sizeof (*(Vallist)))
end_define

begin_comment
comment|/* xargmatch calls this function when it fails.  This function should not    return.  By default, this is a function that calls ARGMATCH_DIE which    in turn defaults to `exit (EXIT_FAILURE)'.  */
end_comment

begin_typedef
typedef|typedef
name|void
argument_list|(
argument|*argmatch_exit_fn
argument_list|)
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
expr_stmt|;
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

begin_decl_stmt
name|void
name|argmatch_invalid
name|PARAMS
argument_list|(
operator|(
specifier|const
name|char
operator|*
name|context
operator|,
specifier|const
name|char
operator|*
name|value
operator|,
name|int
name|problem
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

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
value|argmatch_invalid ((Context), (Value), (Problem))
end_define

begin_comment
comment|/* Report on stderr the list of possible arguments.  */
end_comment

begin_decl_stmt
name|void
name|argmatch_valid
name|PARAMS
argument_list|(
operator|(
specifier|const
name|char
operator|*
specifier|const
operator|*
name|arglist
operator|,
specifier|const
name|char
operator|*
name|vallist
operator|,
name|size_t
name|valsize
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

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
value|argmatch_valid (Arglist, (const char *) Vallist, sizeof (*(Vallist)))
end_define

begin_comment
comment|/* Same as argmatch, but upon failure, reports a explanation on the    failure, and exits using the function EXIT_FN. */
end_comment

begin_decl_stmt
name|int
name|__xargmatch_internal
name|PARAMS
argument_list|(
operator|(
specifier|const
name|char
operator|*
name|context
operator|,
specifier|const
name|char
operator|*
name|arg
operator|,
specifier|const
name|char
operator|*
specifier|const
operator|*
name|arglist
operator|,
specifier|const
name|char
operator|*
name|vallist
operator|,
name|size_t
name|valsize
operator|,
name|int
name|case_sensitive
operator|,
name|argmatch_exit_fn
name|exit_fn
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

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
value|(Vallist [__xargmatch_internal ((Context), (Arg), (Arglist),	\                                   (const char *) (Vallist),	\ 				  sizeof (*(Vallist)),		\ 				  1, argmatch_die)])
end_define

begin_define
define|#
directive|define
name|XARGCASEMATCH
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
value|(Vallist [__xargmatch_internal ((Context), (Arg), (Arglist),	\                                   (const char *) (Vallist),	\ 				  sizeof (*(Vallist)),		\ 				  0, argmatch_die)])
end_define

begin_comment
comment|/* Convert a value into a corresponding argument. */
end_comment

begin_decl_stmt
specifier|const
name|char
modifier|*
name|argmatch_to_argument
name|PARAMS
argument_list|(
operator|(
name|char
specifier|const
operator|*
name|value
operator|,
specifier|const
name|char
operator|*
specifier|const
operator|*
name|arglist
operator|,
specifier|const
name|char
operator|*
name|vallist
operator|,
name|size_t
name|valsize
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

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
value|argmatch_to_argument ((char const *)&(Value), (Arglist), 		\ 		        (const char *) (Vallist), sizeof (*(Vallist)))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ARGMATCH_H_ */
end_comment

end_unit

