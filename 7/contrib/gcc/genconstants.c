begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Generate from machine description:    a series of #define statements, one for each constant named in    a (define_constants ...) pattern.     Copyright (C) 1987, 1991, 1995, 1998, 1999, 2000, 2001, 2003, 2004    Free Software Foundation, Inc.  This file is part of GCC.  GCC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GCC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GCC; see the file COPYING.  If not, write to the Free Software Foundation, 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.  */
end_comment

begin_comment
comment|/* This program does not use gensupport.c because it does not need to    look at insn patterns, only (define_constants), and we want to    minimize dependencies.  */
end_comment

begin_include
include|#
directive|include
file|"bconfig.h"
end_include

begin_include
include|#
directive|include
file|"system.h"
end_include

begin_include
include|#
directive|include
file|"coretypes.h"
end_include

begin_include
include|#
directive|include
file|"tm.h"
end_include

begin_include
include|#
directive|include
file|"rtl.h"
end_include

begin_include
include|#
directive|include
file|"errors.h"
end_include

begin_include
include|#
directive|include
file|"gensupport.h"
end_include

begin_comment
comment|/* Called via traverse_md_constants; emit a #define for    the current constant definition.  */
end_comment

begin_function
specifier|static
name|int
name|print_md_constant
parameter_list|(
name|void
modifier|*
modifier|*
name|slot
parameter_list|,
name|void
modifier|*
name|info
parameter_list|)
block|{
name|struct
name|md_constant
modifier|*
name|def
init|=
operator|(
expr|struct
name|md_constant
operator|*
operator|)
operator|*
name|slot
decl_stmt|;
name|FILE
modifier|*
name|file
init|=
operator|(
name|FILE
operator|*
operator|)
name|info
decl_stmt|;
name|fprintf
argument_list|(
name|file
argument_list|,
literal|"#define %s %s\n"
argument_list|,
name|def
operator|->
name|name
argument_list|,
name|def
operator|->
name|value
argument_list|)
expr_stmt|;
return|return
literal|1
return|;
block|}
end_function

begin_function
name|int
name|main
parameter_list|(
name|int
name|argc
parameter_list|,
name|char
modifier|*
modifier|*
name|argv
parameter_list|)
block|{
name|progname
operator|=
literal|"genconstants"
expr_stmt|;
if|if
condition|(
name|init_md_reader_args
argument_list|(
name|argc
argument_list|,
name|argv
argument_list|)
operator|!=
name|SUCCESS_EXIT_CODE
condition|)
return|return
operator|(
name|FATAL_EXIT_CODE
operator|)
return|;
comment|/* Initializing the MD reader has the side effect of loading up      the constants table that we wish to scan.  */
name|puts
argument_list|(
literal|"/* Generated automatically by the program `genconstants'"
argument_list|)
expr_stmt|;
name|puts
argument_list|(
literal|"   from the machine description file `md'.  */\n"
argument_list|)
expr_stmt|;
name|puts
argument_list|(
literal|"#ifndef GCC_INSN_CONSTANTS_H"
argument_list|)
expr_stmt|;
name|puts
argument_list|(
literal|"#define GCC_INSN_CONSTANTS_H\n"
argument_list|)
expr_stmt|;
name|traverse_md_constants
argument_list|(
name|print_md_constant
argument_list|,
name|stdout
argument_list|)
expr_stmt|;
name|puts
argument_list|(
literal|"\n#endif /* GCC_INSN_CONSTANTS_H */"
argument_list|)
expr_stmt|;
if|if
condition|(
name|ferror
argument_list|(
name|stdout
argument_list|)
operator|||
name|fflush
argument_list|(
name|stdout
argument_list|)
operator|||
name|fclose
argument_list|(
name|stdout
argument_list|)
condition|)
return|return
name|FATAL_EXIT_CODE
return|;
return|return
name|SUCCESS_EXIT_CODE
return|;
block|}
end_function

end_unit

