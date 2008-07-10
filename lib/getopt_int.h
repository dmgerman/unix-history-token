begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Internal declarations for getopt.    Copyright (C) 1989-1994,1996-1999,2001,2003,2004    Free Software Foundation, Inc.    This file is part of the GNU C Library.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2, or (at your option)    any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License along    with this program; if not, write to the Free Software Foundation,    Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_GETOPT_INT_H
end_ifndef

begin_define
define|#
directive|define
name|_GETOPT_INT_H
value|1
end_define

begin_function_decl
specifier|extern
name|int
name|_getopt_internal
parameter_list|(
name|int
name|___argc
parameter_list|,
name|char
modifier|*
modifier|*
name|___argv
parameter_list|,
specifier|const
name|char
modifier|*
name|__shortopts
parameter_list|,
specifier|const
name|struct
name|option
modifier|*
name|__longopts
parameter_list|,
name|int
modifier|*
name|__longind
parameter_list|,
name|int
name|__long_only
parameter_list|,
name|int
name|__posixly_correct
parameter_list|)
function_decl|;
end_function_decl

begin_escape
end_escape

begin_comment
comment|/* Reentrant versions which can handle parsing multiple argument    vectors at the same time.  */
end_comment

begin_comment
comment|/* Data type for reentrant functions.  */
end_comment

begin_struct
struct|struct
name|_getopt_data
block|{
comment|/* These have exactly the same meaning as the corresponding global      variables, except that they are used for the reentrant      versions of getopt.  */
name|int
name|optind
decl_stmt|;
name|int
name|opterr
decl_stmt|;
name|int
name|optopt
decl_stmt|;
name|char
modifier|*
name|optarg
decl_stmt|;
comment|/* Internal members.  */
comment|/* True if the internal members have been initialized.  */
name|int
name|__initialized
decl_stmt|;
comment|/* The next char to be scanned in the option-element      in which the last option character we returned was found.      This allows us to pick up the scan where we left off.       If this is zero, or a null string, it means resume the scan      by advancing to the next ARGV-element.  */
name|char
modifier|*
name|__nextchar
decl_stmt|;
comment|/* Describe how to deal with options that follow non-option ARGV-elements.       If the caller did not specify anything,      the default is REQUIRE_ORDER if the environment variable      POSIXLY_CORRECT is defined, PERMUTE otherwise.       REQUIRE_ORDER means don't recognize them as options;      stop option processing when the first non-option is seen.      This is what Unix does.      This mode of operation is selected by either setting the environment      variable POSIXLY_CORRECT, or using `+' as the first character      of the list of option characters, or by calling getopt.       PERMUTE is the default.  We permute the contents of ARGV as we      scan, so that eventually all the non-options are at the end.      This allows options to be given in any order, even with programs      that were not written to expect this.       RETURN_IN_ORDER is an option available to programs that were      written to expect options and other ARGV-elements in any order      and that care about the ordering of the two.  We describe each      non-option ARGV-element as if it were the argument of an option      with character code 1.  Using `-' as the first character of the      list of option characters selects this mode of operation.       The special argument `--' forces an end of option-scanning regardless      of the value of `ordering'.  In the case of RETURN_IN_ORDER, only      `--' can cause `getopt' to return -1 with `optind' != ARGC.  */
enum|enum
block|{
name|REQUIRE_ORDER
block|,
name|PERMUTE
block|,
name|RETURN_IN_ORDER
block|}
name|__ordering
enum|;
comment|/* If the POSIXLY_CORRECT environment variable is set      or getopt was called.  */
name|int
name|__posixly_correct
decl_stmt|;
comment|/* Handle permutation of arguments.  */
comment|/* Describe the part of ARGV that contains non-options that have      been skipped.  `first_nonopt' is the index in ARGV of the first      of them; `last_nonopt' is the index after the last of them.  */
name|int
name|__first_nonopt
decl_stmt|;
name|int
name|__last_nonopt
decl_stmt|;
if|#
directive|if
name|defined
name|_LIBC
operator|&&
name|defined
name|USE_NONOPTION_FLAGS
name|int
name|__nonoption_flags_max_len
decl_stmt|;
name|int
name|__nonoption_flags_len
decl_stmt|;
endif|#
directive|endif
block|}
struct|;
end_struct

begin_comment
comment|/* The initializer is necessary to set OPTIND and OPTERR to their    default values and to clear the initialization flag.  */
end_comment

begin_define
define|#
directive|define
name|_GETOPT_DATA_INITIALIZER
value|{ 1, 1 }
end_define

begin_function_decl
specifier|extern
name|int
name|_getopt_internal_r
parameter_list|(
name|int
name|___argc
parameter_list|,
name|char
modifier|*
modifier|*
name|___argv
parameter_list|,
specifier|const
name|char
modifier|*
name|__shortopts
parameter_list|,
specifier|const
name|struct
name|option
modifier|*
name|__longopts
parameter_list|,
name|int
modifier|*
name|__longind
parameter_list|,
name|int
name|__long_only
parameter_list|,
name|int
name|__posixly_correct
parameter_list|,
name|struct
name|_getopt_data
modifier|*
name|__data
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|_getopt_long_r
parameter_list|(
name|int
name|___argc
parameter_list|,
name|char
modifier|*
modifier|*
name|___argv
parameter_list|,
specifier|const
name|char
modifier|*
name|__shortopts
parameter_list|,
specifier|const
name|struct
name|option
modifier|*
name|__longopts
parameter_list|,
name|int
modifier|*
name|__longind
parameter_list|,
name|struct
name|_getopt_data
modifier|*
name|__data
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|_getopt_long_only_r
parameter_list|(
name|int
name|___argc
parameter_list|,
name|char
modifier|*
modifier|*
name|___argv
parameter_list|,
specifier|const
name|char
modifier|*
name|__shortopts
parameter_list|,
specifier|const
name|struct
name|option
modifier|*
name|__longopts
parameter_list|,
name|int
modifier|*
name|__longind
parameter_list|,
name|struct
name|_getopt_data
modifier|*
name|__data
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* getopt_int.h */
end_comment

end_unit

