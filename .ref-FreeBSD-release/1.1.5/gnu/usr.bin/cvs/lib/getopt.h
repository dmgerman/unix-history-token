begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* declarations for getopt    Copyright (C) 1989, 1990, 1991, 1992 Free Software Foundation, Inc.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2, or (at your option)    any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software    Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.  */
end_comment

begin_comment
comment|/* @(#)getopt.h 1.6 92/03/31 */
end_comment

begin_comment
comment|/* For communication from `getopt' to the caller.    When `getopt' finds an option that takes an argument,    the argument value is returned here.    Also, when `ordering' is RETURN_IN_ORDER,    each non-option ARGV-element is returned here.  */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|optarg
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Index in ARGV of the next element to be scanned.    This is used for communication to and from the caller    and for communication between successive calls to `getopt'.     On entry to `getopt', zero means this is the first call; initialize.     When `getopt' returns EOF, this is the index of the first of the    non-option elements that the caller should itself scan.     Otherwise, `optind' communicates from one call to the next    how much of ARGV has been scanned so far.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|optind
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Callers store zero here to inhibit the error message `getopt' prints    for unrecognized options.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|opterr
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Describe the long-named options requested by the application.    _GETOPT_LONG_OPTIONS is a vector of `struct option' terminated by an    element containing a name which is zero.     The field `has_arg' is:    0 if the option does not take an argument,    1 if the option requires an argument,    2 if the option takes an optional argument.     If the field `flag' is nonzero, it points to a variable that is set    to the value given in the field `val' when the option is found, but    left unchanged if the option is not found.     To have a long-named option do something other than set an `int' to    a compiled-in constant, such as set a value from `optarg', set the    option's `flag' field to zero and its `val' field to a nonzero    value (the equivalent single-letter option character, if there is    one).  For long options that have a zero `flag' field, `getopt'    returns the contents of the `val' field.  */
end_comment

begin_struct
struct|struct
name|option
block|{
name|char
modifier|*
name|name
decl_stmt|;
name|int
name|has_arg
decl_stmt|;
name|int
modifier|*
name|flag
decl_stmt|;
name|int
name|val
decl_stmt|;
block|}
struct|;
end_struct

begin_if
if|#
directive|if
name|__STDC__
end_if

begin_decl_stmt
specifier|extern
specifier|const
name|struct
name|option
modifier|*
name|_getopt_long_options
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_decl_stmt
specifier|extern
name|struct
name|option
modifier|*
name|_getopt_long_options
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* If nonzero, '-' can introduce long-named options.    Set by getopt_long_only.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|_getopt_long_only
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* The index in GETOPT_LONG_OPTIONS of the long-named option found.    Only valid when a long-named option has been found by the most    recent call to `getopt'.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|option_index
decl_stmt|;
end_decl_stmt

begin_if
if|#
directive|if
name|__STDC__
end_if

begin_function_decl
name|int
name|gnu_getopt
parameter_list|(
name|int
name|argc
parameter_list|,
name|char
modifier|*
modifier|*
name|argv
parameter_list|,
specifier|const
name|char
modifier|*
name|shortopts
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|gnu_getopt_long
parameter_list|(
name|int
name|argc
parameter_list|,
name|char
modifier|*
modifier|*
name|argv
parameter_list|,
specifier|const
name|char
modifier|*
name|shortopts
parameter_list|,
specifier|const
name|struct
name|option
modifier|*
name|longopts
parameter_list|,
name|int
modifier|*
name|longind
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|gnu_getopt_long_only
parameter_list|(
name|int
name|argc
parameter_list|,
name|char
modifier|*
modifier|*
name|argv
parameter_list|,
specifier|const
name|char
modifier|*
name|shortopts
parameter_list|,
specifier|const
name|struct
name|option
modifier|*
name|longopts
parameter_list|,
name|int
modifier|*
name|longind
parameter_list|)
function_decl|;
end_function_decl

begin_else
else|#
directive|else
end_else

begin_function_decl
name|int
name|gnu_getopt
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|gnu_getopt_long
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|gnu_getopt_long_only
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

end_unit

