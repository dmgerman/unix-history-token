begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Declarations for getopt.    Copyright (C) 1989-1994,1996-1999,2001,2003,2004    Free Software Foundation, Inc.    This file is part of the GNU C Library.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2, or (at your option)    any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License along    with this program; if not, write to the Free Software Foundation,    Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_GETOPT_H
end_ifndef

begin_ifndef
ifndef|#
directive|ifndef
name|__need_getopt
end_ifndef

begin_define
define|#
directive|define
name|_GETOPT_H
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* If __GNU_LIBRARY__ is not already defined, either we are being used    standalone, or this is the first header included in the source file.    If we are being used with glibc, we need to include<features.h>, but    that does not exist if we are standalone.  So: if __GNU_LIBRARY__ is    not defined, include<ctype.h>, which will pull in<features.h> for us    if it's from glibc.  (Why ctype.h?  It's guaranteed to exist and it    doesn't flood the namespace with stuff the way some other headers do.)  */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
name|__GNU_LIBRARY__
end_if

begin_include
include|#
directive|include
file|<ctype.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|__THROW
end_ifndef

begin_ifndef
ifndef|#
directive|ifndef
name|__GNUC_PREREQ
end_ifndef

begin_define
define|#
directive|define
name|__GNUC_PREREQ
parameter_list|(
name|maj
parameter_list|,
name|min
parameter_list|)
value|(0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
name|__cplusplus
operator|&&
name|__GNUC_PREREQ
argument_list|(
literal|2
operator|,
literal|8
argument_list|)
end_if

begin_define
define|#
directive|define
name|__THROW
value|throw ()
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|__THROW
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
comment|/* For communication from `getopt' to the caller.    When `getopt' finds an option that takes an argument,    the argument value is returned here.    Also, when `ordering' is RETURN_IN_ORDER,    each non-option ARGV-element is returned here.  */
specifier|extern
name|char
modifier|*
name|optarg
decl_stmt|;
comment|/* Index in ARGV of the next element to be scanned.    This is used for communication to and from the caller    and for communication between successive calls to `getopt'.     On entry to `getopt', zero means this is the first call; initialize.     When `getopt' returns -1, this is the index of the first of the    non-option elements that the caller should itself scan.     Otherwise, `optind' communicates from one call to the next    how much of ARGV has been scanned so far.  */
specifier|extern
name|int
name|optind
decl_stmt|;
comment|/* Callers store zero here to inhibit the error message `getopt' prints    for unrecognized options.  */
specifier|extern
name|int
name|opterr
decl_stmt|;
comment|/* Set to an option character which was unrecognized.  */
specifier|extern
name|int
name|optopt
decl_stmt|;
ifndef|#
directive|ifndef
name|__need_getopt
comment|/* Describe the long-named options requested by the application.    The LONG_OPTIONS argument to getopt_long or getopt_long_only is a vector    of `struct option' terminated by an element containing a name which is    zero.     The field `has_arg' is:    no_argument		(or 0) if the option does not take an argument,    required_argument	(or 1) if the option requires an argument,    optional_argument 	(or 2) if the option takes an optional argument.     If the field `flag' is not NULL, it points to a variable that is set    to the value given in the field `val' when the option is found, but    left unchanged if the option is not found.     To have a long-named option do something other than set an `int' to    a compiled-in constant, such as set a value from `optarg', set the    option's `flag' field to zero and its `val' field to a nonzero    value (the equivalent single-letter option character, if there is    one).  For long options that have a zero `flag' field, `getopt'    returns the contents of the `val' field.  */
struct|struct
name|option
block|{
specifier|const
name|char
modifier|*
name|name
decl_stmt|;
comment|/* has_arg can't be an enum because some compilers complain about      type mismatches in all the code that assumes it is an int.  */
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
comment|/* Names for the values of the `has_arg' field of `struct option'.  */
define|#
directive|define
name|no_argument
value|0
define|#
directive|define
name|required_argument
value|1
define|#
directive|define
name|optional_argument
value|2
endif|#
directive|endif
comment|/* need getopt */
comment|/* Get definitions and prototypes for functions to process the    arguments in ARGV (ARGC of them, minus the program name) for    options given in OPTS.     Return the option character from OPTS just read.  Return -1 when    there are no more options.  For unrecognized options, or options    missing arguments, `optopt' is set to the option letter, and '?' is    returned.     The OPTS string is a list of characters which are recognized option    letters, optionally followed by colons, specifying that that letter    takes an argument, to be placed in `optarg'.     If a letter in OPTS is followed by two colons, its argument is    optional.  This behavior is specific to the GNU `getopt'.     The argument `--' causes premature termination of argument    scanning, explicitly telling `getopt' that there are no more    options.     If OPTS begins with `--', then non-option arguments are treated as    arguments to the option '\0'.  This behavior is specific to the GNU    `getopt'.  */
ifdef|#
directive|ifdef
name|__GNU_LIBRARY__
comment|/* Many other libraries have conflicting prototypes for getopt, with    differences in the consts, in stdlib.h.  To avoid compilation    errors, only prototype getopt for the GNU C library.  */
specifier|extern
name|int
name|getopt
argument_list|(
name|int
name|___argc
argument_list|,
name|char
operator|*
specifier|const
operator|*
name|___argv
argument_list|,
specifier|const
name|char
operator|*
name|__shortopts
argument_list|)
name|__THROW
decl_stmt|;
else|#
directive|else
comment|/* not __GNU_LIBRARY__ */
specifier|extern
name|int
name|getopt
parameter_list|()
function_decl|;
endif|#
directive|endif
comment|/* __GNU_LIBRARY__ */
ifndef|#
directive|ifndef
name|__need_getopt
specifier|extern
name|int
name|getopt_long
argument_list|(
name|int
name|___argc
argument_list|,
name|char
operator|*
specifier|const
operator|*
name|___argv
argument_list|,
specifier|const
name|char
operator|*
name|__shortopts
argument_list|,
specifier|const
expr|struct
name|option
operator|*
name|__longopts
argument_list|,
name|int
operator|*
name|__longind
argument_list|)
name|__THROW
decl_stmt|;
specifier|extern
name|int
name|getopt_long_only
argument_list|(
name|int
name|___argc
argument_list|,
name|char
operator|*
specifier|const
operator|*
name|___argv
argument_list|,
specifier|const
name|char
operator|*
name|__shortopts
argument_list|,
specifier|const
expr|struct
name|option
operator|*
name|__longopts
argument_list|,
name|int
operator|*
name|__longind
argument_list|)
name|__THROW
decl_stmt|;
endif|#
directive|endif
ifdef|#
directive|ifdef
name|__cplusplus
block|}
end_extern

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Make sure we later can get all the definitions and declarations.  */
end_comment

begin_undef
undef|#
directive|undef
name|__need_getopt
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* getopt.h */
end_comment

end_unit

