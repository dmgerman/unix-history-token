begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Driver program for the Perfect hash function generator.    Copyright (C) 1989 Free Software Foundation, Inc.    written by Douglas C. Schmidt (schmidt@ics.uci.edu)  This file is part of GNU GPERF.  GNU GPERF is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 1, or (at your option) any later version.  GNU GPERF is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GNU GPERF; see the file COPYING.  If not, write to the Free Software Foundation, 675 Mass Ave, Cambridge, MA 02139, USA.  */
end_comment

begin_comment
comment|/* Simple driver program for the Perfect.hash function generator.    Most of the hard work is done in class Perfect and its class methods. */
end_comment

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<time.h>
end_include

begin_include
include|#
directive|include
file|"stderr.h"
end_include

begin_include
include|#
directive|include
file|"options.h"
end_include

begin_include
include|#
directive|include
file|"perfect.h"
end_include

begin_comment
comment|/* Calls the appropriate intialization routines for each    ADT.  Note that certain initialization routines require    initialization *after* certain values are computed.  Therefore,    they cannot be called here. */
end_comment

begin_function
specifier|static
name|void
name|init_all
parameter_list|(
name|argc
parameter_list|,
name|argv
parameter_list|)
name|int
name|argc
decl_stmt|;
name|char
modifier|*
name|argv
index|[]
decl_stmt|;
block|{
ifdef|#
directive|ifdef
name|RLIMIT_STACK
comment|/* Get rid of any avoidable limit on stack size.  */
block|{
name|struct
name|rlimit
name|rlim
decl_stmt|;
comment|/* Set the stack limit huge so that alloca does not fail. */
name|getrlimit
argument_list|(
name|RLIMIT_STACK
argument_list|,
operator|&
name|rlim
argument_list|)
expr_stmt|;
name|rlim
operator|.
name|rlim_cur
operator|=
name|rlim
operator|.
name|rlim_max
expr_stmt|;
name|setrlimit
argument_list|(
name|RLIMIT_STACK
argument_list|,
operator|&
name|rlim
argument_list|)
expr_stmt|;
block|}
endif|#
directive|endif
comment|/* RLIMIT_STACK */
name|options_init
argument_list|(
name|argc
argument_list|,
name|argv
argument_list|)
expr_stmt|;
name|key_list_init
argument_list|()
expr_stmt|;
name|perfect_init
argument_list|()
expr_stmt|;
block|}
end_function

begin_comment
comment|/* Calls appropriate destruction routines for each ADT.  These    routines print diagnostics if the debugging option is enabled. */
end_comment

begin_function
specifier|static
name|void
name|destroy_all
parameter_list|()
block|{
name|options_destroy
argument_list|()
expr_stmt|;
name|key_list_destroy
argument_list|()
expr_stmt|;
name|perfect_destroy
argument_list|()
expr_stmt|;
block|}
end_function

begin_comment
comment|/* Driver for perfect hash function generation. */
end_comment

begin_function
name|int
name|main
parameter_list|(
name|argc
parameter_list|,
name|argv
parameter_list|)
name|int
name|argc
decl_stmt|;
name|char
modifier|*
name|argv
index|[]
decl_stmt|;
block|{
name|struct
name|tm
modifier|*
name|tm
decl_stmt|;
name|time_t
name|clock
decl_stmt|;
name|int
name|status
decl_stmt|;
name|time
argument_list|(
operator|&
name|clock
argument_list|)
expr_stmt|;
name|tm
operator|=
name|localtime
argument_list|(
operator|&
name|clock
argument_list|)
expr_stmt|;
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"/* starting time is %d:%d:%d */\n"
argument_list|,
name|tm
operator|->
name|tm_hour
argument_list|,
name|tm
operator|->
name|tm_min
argument_list|,
name|tm
operator|->
name|tm_sec
argument_list|)
expr_stmt|;
comment|/* Sets the options. */
name|init_all
argument_list|(
name|argc
argument_list|,
name|argv
argument_list|)
expr_stmt|;
comment|/* Generates the perfect hash table.      Also prints generated code neatly to the output. */
name|status
operator|=
name|perfect_generate
argument_list|()
expr_stmt|;
name|destroy_all
argument_list|()
expr_stmt|;
name|time
argument_list|(
operator|&
name|clock
argument_list|)
expr_stmt|;
name|tm
operator|=
name|localtime
argument_list|(
operator|&
name|clock
argument_list|)
expr_stmt|;
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"/* ending time is %d:%d:%d */\n"
argument_list|,
name|tm
operator|->
name|tm_hour
argument_list|,
name|tm
operator|->
name|tm_min
argument_list|,
name|tm
operator|->
name|tm_sec
argument_list|)
expr_stmt|;
return|return
name|status
return|;
block|}
end_function

end_unit

