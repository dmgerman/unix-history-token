begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Utility to accept --help and --version options as unobtrusively as possible.    Copyright (C) 1993, 1994 Free Software Foundation, Inc.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2, or (at your option)    any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software    Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.  */
end_comment

begin_comment
comment|/* Jim Meyering (meyering@comco.com) */
end_comment

begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_CONFIG_H
end_ifdef

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
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<getopt.h>
end_include

begin_include
include|#
directive|include
file|"long-options.h"
end_include

begin_decl_stmt
specifier|static
name|struct
name|option
specifier|const
name|long_options
index|[]
init|=
block|{
block|{
literal|"help"
block|,
name|no_argument
block|,
literal|0
block|,
literal|'h'
block|}
block|,
block|{
literal|"version"
block|,
name|no_argument
block|,
literal|0
block|,
literal|'v'
block|}
block|,
block|{
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Process long options --help and --version, but only if argc == 2.    Be careful not to gobble up `--'.  */
end_comment

begin_decl_stmt
name|void
name|parse_long_options
argument_list|(
name|argc
argument_list|,
name|argv
argument_list|,
name|command_name
argument_list|,
name|version_string
argument_list|,
name|usage
argument_list|)
name|int
name|argc
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
modifier|*
name|argv
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|char
modifier|*
name|command_name
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|char
modifier|*
name|version_string
decl_stmt|;
end_decl_stmt

begin_function_decl
name|void
function_decl|(
modifier|*
name|usage
function_decl|)
parameter_list|()
function_decl|;
end_function_decl

begin_block
block|{
name|int
name|c
decl_stmt|;
name|int
name|saved_opterr
decl_stmt|;
name|int
name|saved_optind
decl_stmt|;
name|saved_opterr
operator|=
name|opterr
expr_stmt|;
name|saved_optind
operator|=
name|optind
expr_stmt|;
comment|/* Don't print an error message for unrecognized options.  */
name|opterr
operator|=
literal|0
expr_stmt|;
if|if
condition|(
name|argc
operator|==
literal|2
operator|&&
operator|(
name|c
operator|=
name|getopt_long
argument_list|(
name|argc
argument_list|,
name|argv
argument_list|,
literal|"+"
argument_list|,
name|long_options
argument_list|,
operator|(
name|int
operator|*
operator|)
literal|0
argument_list|)
operator|)
operator|!=
name|EOF
condition|)
block|{
switch|switch
condition|(
name|c
condition|)
block|{
case|case
literal|'h'
case|:
call|(
modifier|*
name|usage
call|)
argument_list|(
literal|0
argument_list|)
expr_stmt|;
case|case
literal|'v'
case|:
name|printf
argument_list|(
literal|"%s - %s\n"
argument_list|,
name|command_name
argument_list|,
name|version_string
argument_list|)
expr_stmt|;
name|exit
argument_list|(
literal|0
argument_list|)
expr_stmt|;
default|default:
comment|/* Don't process any other long-named options.  */
break|break;
block|}
block|}
comment|/* Restore previous value.  */
name|opterr
operator|=
name|saved_opterr
expr_stmt|;
comment|/* Restore optind in case it has advanced past a leading `--'.  */
name|optind
operator|=
name|saved_optind
expr_stmt|;
block|}
end_block

end_unit

