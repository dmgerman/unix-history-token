begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* xexit.c -- exit with attention to return values and closing stdout.    $Id: xexit.c,v 1.5 1999/02/19 14:13:51 karl Exp $     Copyright (C) 1999 Free Software Foundation, Inc.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2, or (at your option)    any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License along    with this program; if not, write to the Free Software Foundation, Inc.,    59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_include
include|#
directive|include
file|"system.h"
end_include

begin_comment
comment|/* SunOS 4.1.1 gets STDC_HEADERS defined, but it doesn't provide    EXIT_FAILURE.  So far no system has defined one of EXIT_FAILURE and    EXIT_SUCCESS without the other.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|EXIT_SUCCESS
end_ifdef

begin_comment
comment|/* The following test is to work around the gross typo in     systems like Sony NEWS-OS Release 4.0C, whereby EXIT_FAILURE     is defined to 0, not 1.  */
end_comment

begin_if
if|#
directive|if
operator|!
name|EXIT_FAILURE
end_if

begin_undef
undef|#
directive|undef
name|EXIT_FAILURE
end_undef

begin_define
define|#
directive|define
name|EXIT_FAILURE
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* not EXIT_SUCCESS */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|VMS
end_ifdef

begin_comment
comment|/* these values suppress some messages; from gnuplot */
end_comment

begin_define
define|#
directive|define
name|EXIT_SUCCESS
value|1
end_define

begin_define
define|#
directive|define
name|EXIT_FAILURE
value|0x10000002
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* not VMS */
end_comment

begin_define
define|#
directive|define
name|EXIT_SUCCESS
value|0
end_define

begin_define
define|#
directive|define
name|EXIT_FAILURE
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not VMS */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not EXIT_SUCCESS */
end_comment

begin_comment
comment|/* Flush stdout first, exit if failure.  Otherwise, if EXIT_STATUS is    zero, exit successfully, else unsuccessfully.  */
end_comment

begin_function
name|void
name|xexit
parameter_list|(
name|exit_status
parameter_list|)
name|int
name|exit_status
decl_stmt|;
block|{
if|if
condition|(
name|ferror
argument_list|(
name|stdout
argument_list|)
condition|)
block|{
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"ferror on stdout"
argument_list|)
expr_stmt|;
name|exit_status
operator|=
literal|1
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|fflush
argument_list|(
name|stdout
argument_list|)
operator|!=
literal|0
condition|)
block|{
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"fflush error on stdout"
argument_list|)
expr_stmt|;
name|exit_status
operator|=
literal|1
expr_stmt|;
block|}
name|exit_status
operator|=
name|exit_status
operator|==
literal|0
condition|?
name|EXIT_SUCCESS
else|:
name|EXIT_FAILURE
expr_stmt|;
name|exit
argument_list|(
name|exit_status
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/* Why do we care about stdout you may ask?  Here's why, from Jim    Meyering in the lib/closeout.c file.  */
end_comment

begin_comment
comment|/* If a program writes *anything* to stdout, that program should close    stdout and make sure that the close succeeds.  Otherwise, suppose that    you go to the extreme of checking the return status of every function    that does an explicit write to stdout.  The last printf can succeed in    writing to the internal stream buffer, and yet the fclose(stdout) could    still fail (due e.g., to a disk full error) when it tries to write    out that buffered data.  Thus, you would be left with an incomplete    output file and the offending program would exit successfully.     Besides, it's wasteful to check the return value from every call    that writes to stdout -- just let the internal stream state record    the failure.  That's what the ferror test is checking below.     It's important to detect such failures and exit nonzero because many    tools (most notably `make' and other build-management systems) depend    on being able to detect failure in other tools via their exit status.  */
end_comment

end_unit

