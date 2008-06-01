begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Getopt for GNU.     Copyright (C) 1987, 1989, 1992 Free Software Foundation, Inc.    (Modified by Douglas C. Schmidt for use with GNU G++.)  This file is part of the GNU C++ Library.  This library is free software; you can redistribute it and/or modify it under the terms of the GNU Library General Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version.  This library is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU Library General Public License for more details. You should have received a copy of the GNU Library General Public License along with this library; if not, write to the Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA. */
end_comment

begin_escape
end_escape

begin_comment
comment|/* This version of `getopt' appears to the caller like standard Unix `getopt'    but it behaves differently for the user, since it allows the user    to intersperse the options with the other arguments.     As `getopt' works, it permutes the elements of `argv' so that,    when it is done, all the options precede everything else.  Thus    all application programs are extended to handle flexible argument order.     Setting the environment variable _POSIX_OPTION_ORDER disables permutation.    Then the behavior is completely standard.     GNU application programs can use a third alternative mode in which    they can distinguish the relative order of options and other arguments.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|GetOpt_h
end_ifndef

begin_ifdef
ifdef|#
directive|ifdef
name|__GNUG__
end_ifdef

begin_pragma
pragma|#
directive|pragma
name|interface
end_pragma

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|GetOpt_h
value|1
end_define

begin_include
include|#
directive|include
file|<std.h>
end_include

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_decl_stmt
name|class
name|GetOpt
block|{
name|private
label|:
comment|/* The next char to be scanned in the option-element      in which the last option character we returned was found.      This allows us to pick up the scan where we left off.               If this is zero, or a null string, it means resume the scan      by advancing to the next ARGV-element.  */
specifier|static
name|char
modifier|*
name|nextchar
decl_stmt|;
comment|/* Describe how to deal with options that follow non-option ARGV-elements.          UNSPECIFIED means the caller did not specify anything;     the default is then REQUIRE_ORDER if the environment variable     _OPTIONS_FIRST is defined, PERMUTE otherwise.            REQUIRE_ORDER means don't recognize them as options.     Stop option processing when the first non-option is seen.     This is what Unix does.                  PERMUTE is the default.  We permute the contents of `argv' as we scan,     so that eventually all the options are at the end.  This allows options     to be given in any order, even with programs that were not written to     expect this.              RETURN_IN_ORDER is an option available to programs that were written     to expect options and other ARGV-elements in any order and that care about     the ordering of the two.  We describe each non-option ARGV-element     as if it were the argument of an option with character code zero.     Using `-' as the first character of the list of option characters     requests this mode of operation.                          The special argument `--' forces an end of option-scanning regardless     of the value of `ordering'.  In the case of RETURN_IN_ORDER, only     `--' can cause `getopt' to return EOF with `optind' != ARGC.  */
enum|enum
name|OrderingEnum
block|{
name|REQUIRE_ORDER
block|,
name|PERMUTE
block|,
name|RETURN_IN_ORDER
block|}
enum|;
name|OrderingEnum
name|ordering
decl_stmt|;
comment|/* Handle permutation of arguments.  */
comment|/* Describe the part of ARGV that contains non-options that have      been skipped.  `first_nonopt' is the index in ARGV of the first of them;      `last_nonopt' is the index after the last of them.  */
specifier|static
name|int
name|first_nonopt
decl_stmt|;
specifier|static
name|int
name|last_nonopt
decl_stmt|;
name|void
name|exchange
parameter_list|(
name|char
modifier|*
modifier|*
name|argv
parameter_list|)
function_decl|;
name|public
label|:
comment|/* For communication from `getopt' to the caller.      When `getopt' finds an option that takes an argument,      the argument value is returned here.      Also, when `ordering' is RETURN_IN_ORDER,      each non-option ARGV-element is returned here.  */
name|char
modifier|*
name|optarg
decl_stmt|;
comment|/* Index in ARGV of the next element to be scanned.      This is used for communication to and from the caller      and for communication between successive calls to `getopt'.      On entry to `getopt', zero means this is the first call; initialize.                 When `getopt' returns EOF, this is the index of the first of the      non-option elements that the caller should itself scan.                     Otherwise, `optind' communicates from one call to the next      how much of ARGV has been scanned so far.  */
name|int
name|optind
decl_stmt|;
comment|/* Callers store zero here to inhibit the error message      for unrecognized options.  */
name|int
name|opterr
decl_stmt|;
name|int
name|nargc
decl_stmt|;
name|char
modifier|*
modifier|*
name|nargv
decl_stmt|;
specifier|const
name|char
modifier|*
name|noptstring
decl_stmt|;
name|GetOpt
argument_list|(
argument|int argc
argument_list|,
argument|char **argv
argument_list|,
argument|const char *optstring
argument_list|)
empty_stmt|;
name|int
name|operator
argument_list|()
argument_list|(
name|void
argument_list|)
expr_stmt|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

