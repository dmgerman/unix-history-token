begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Copyright (C) 1991, 1992 Aladdin Enterprises.  All rights reserved.    Distributed by Free Software Foundation, Inc.  This file is part of Ghostscript.  Ghostscript is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY.  No author or distributor accepts responsibility to anyone for the consequences of using it or for whether it serves any particular purpose or works at all, unless he says so in writing.  Refer to the Ghostscript General Public License for full details.  Everyone is granted permission to copy, modify and redistribute Ghostscript, but only under the conditions described in the Ghostscript General Public License.  A copy of this license is supposed to have been given to you along with Ghostscript so you can know your rights and responsibilities.  It should be in a file named COPYING.  Among other things, the copyright notice and this notice must be preserved on all copies.  */
end_comment

begin_comment
comment|/* gp_iwatc.c */
end_comment

begin_comment
comment|/* Intel processor, Watcom C-specific routines for Ghostscript */
end_comment

begin_include
include|#
directive|include
file|"dos_.h"
end_include

begin_include
include|#
directive|include
file|<fcntl.h>
end_include

begin_include
include|#
directive|include
file|<signal.h>
end_include

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_include
include|#
directive|include
file|"stat_.h"
end_include

begin_include
include|#
directive|include
file|"string_.h"
end_include

begin_include
include|#
directive|include
file|"gx.h"
end_include

begin_include
include|#
directive|include
file|"gp.h"
end_include

begin_comment
comment|/* Define the size of the C stack. */
end_comment

begin_decl_stmt
name|unsigned
name|_stklen
init|=
literal|8000
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* default is 4096, we need more */
end_comment

begin_comment
comment|/* Define a substitute for stdprn (see below). */
end_comment

begin_decl_stmt
name|private
name|FILE
modifier|*
name|gs_stdprn
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Forward declarations */
end_comment

begin_decl_stmt
name|private
name|void
name|handle_FPE
argument_list|(
name|P1
argument_list|(
name|int
argument_list|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Do platform-dependent initialization. */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|gp_init_console
argument_list|(
name|P0
argument_list|()
argument_list|)
decl_stmt|;
end_decl_stmt

begin_function
name|void
name|gp_init
parameter_list|()
block|{
name|_fmode
operator|=
name|O_BINARY
expr_stmt|;
comment|/* Open files in 'binary' mode */
name|gs_stdprn
operator|=
literal|0
expr_stmt|;
comment|/* Set up the handler for numeric exceptions. */
name|signal
argument_list|(
name|SIGFPE
argument_list|,
name|handle_FPE
argument_list|)
expr_stmt|;
name|gp_init_console
argument_list|()
expr_stmt|;
block|}
end_function

begin_comment
comment|/* Trap numeric exceptions.  Someday we will do something */
end_comment

begin_comment
comment|/* more appropriate with these. */
end_comment

begin_function
name|private
name|void
name|handle_FPE
parameter_list|(
name|int
name|sig
parameter_list|)
block|{
name|eprintf
argument_list|(
literal|"Numeric exception:\n"
argument_list|)
expr_stmt|;
name|exit
argument_list|(
literal|1
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/* Do platform-dependent cleanup. */
end_comment

begin_function
name|void
name|gp_exit
parameter_list|()
block|{ }
end_function

begin_comment
comment|/* ------ Printer accessing ------ */
end_comment

begin_comment
comment|/* Open a connection to a printer.  A null file name means use the */
end_comment

begin_comment
comment|/* standard printer connected to the machine, if any. */
end_comment

begin_comment
comment|/* Return NULL if the connection could not be opened. */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|gp_set_printer_binary
argument_list|(
name|P1
argument_list|(
name|int
argument_list|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_function
name|FILE
modifier|*
name|gp_open_printer
parameter_list|(
name|char
modifier|*
name|fname
parameter_list|)
block|{
if|if
condition|(
name|strlen
argument_list|(
name|fname
argument_list|)
operator|==
literal|0
operator|||
operator|!
name|strcmp
argument_list|(
name|fname
argument_list|,
literal|"PRN"
argument_list|)
condition|)
block|{
if|if
condition|(
name|gs_stdprn
operator|==
literal|0
condition|)
block|{
comment|/* We have to effectively reopen the printer, */
comment|/* because the Watcom library does \n -> \r\n */
comment|/* substitution on the stdprn stream. */
name|int
name|fno
init|=
name|dup
argument_list|(
name|fileno
argument_list|(
name|stdprn
argument_list|)
argument_list|)
decl_stmt|;
name|setmode
argument_list|(
name|fno
argument_list|,
name|O_BINARY
argument_list|)
expr_stmt|;
name|gs_stdprn
operator|=
name|fdopen
argument_list|(
name|fno
argument_list|,
literal|"wb"
argument_list|)
expr_stmt|;
name|gp_set_printer_binary
argument_list|(
name|fileno
argument_list|(
name|gs_stdprn
argument_list|)
argument_list|)
expr_stmt|;
block|}
return|return
name|gs_stdprn
return|;
block|}
else|else
return|return
name|fopen
argument_list|(
name|fname
argument_list|,
literal|"wb"
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/* Close the connection to the printer. */
end_comment

begin_function
name|void
name|gp_close_printer
parameter_list|(
name|FILE
modifier|*
name|pfile
parameter_list|,
specifier|const
name|char
modifier|*
name|fname
parameter_list|)
block|{
name|fclose
argument_list|(
name|pfile
argument_list|)
expr_stmt|;
if|if
condition|(
name|pfile
operator|==
name|gs_stdprn
condition|)
name|gs_stdprn
operator|=
literal|0
expr_stmt|;
block|}
end_function

begin_comment
comment|/* ------ File names ------ */
end_comment

begin_comment
comment|/* Create and open a scratch file with a given name prefix. */
end_comment

begin_comment
comment|/* Write the actual file name at fname. */
end_comment

begin_function
name|FILE
modifier|*
name|gp_open_scratch_file
parameter_list|(
specifier|const
name|char
modifier|*
name|prefix
parameter_list|,
name|char
modifier|*
name|fname
parameter_list|,
specifier|const
name|char
modifier|*
name|mode
parameter_list|)
block|{
comment|/* Unfortunately, Watcom C doesn't provide mktemp, */
comment|/* so we have to simulate it ourselves. */
name|struct
name|stat
name|fst
decl_stmt|;
name|char
modifier|*
name|end
decl_stmt|;
name|strcpy
argument_list|(
name|fname
argument_list|,
name|prefix
argument_list|)
expr_stmt|;
name|strcat
argument_list|(
name|fname
argument_list|,
literal|"AA.AAA"
argument_list|)
expr_stmt|;
name|end
operator|=
name|fname
operator|+
name|strlen
argument_list|(
name|fname
argument_list|)
operator|-
literal|1
expr_stmt|;
while|while
condition|(
name|stat
argument_list|(
name|fname
argument_list|,
operator|&
name|fst
argument_list|)
operator|==
literal|0
condition|)
block|{
name|char
modifier|*
name|inc
init|=
name|end
decl_stmt|;
while|while
condition|(
operator|*
name|inc
operator|==
literal|'Z'
operator|||
operator|*
name|inc
operator|==
literal|'.'
condition|)
block|{
if|if
condition|(
operator|*
name|inc
operator|==
literal|'Z'
condition|)
operator|*
name|inc
operator|=
literal|'A'
expr_stmt|;
name|inc
operator|--
expr_stmt|;
if|if
condition|(
name|end
operator|-
name|inc
operator|==
literal|6
condition|)
return|return
literal|0
return|;
block|}
operator|++
operator|*
name|inc
expr_stmt|;
block|}
return|return
name|fopen
argument_list|(
name|fname
argument_list|,
name|mode
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/* ------ File operations ------ */
end_comment

begin_comment
comment|/* If the file given by fname exists, fill in its status and return 1; */
end_comment

begin_comment
comment|/* otherwise return 0. */
end_comment

begin_function
name|int
name|gp_file_status
parameter_list|(
specifier|const
name|char
modifier|*
name|fname
parameter_list|,
name|file_status
modifier|*
name|pstatus
parameter_list|)
block|{
name|struct
name|stat
name|fst
decl_stmt|;
if|if
condition|(
name|stat
argument_list|(
name|fname
argument_list|,
operator|&
name|fst
argument_list|)
operator|<
literal|0
condition|)
return|return
literal|0
return|;
name|pstatus
operator|->
name|size_pages
operator|=
operator|(
name|fst
operator|.
name|st_size
operator|+
literal|1023
operator|)
operator|>>
literal|10
expr_stmt|;
name|pstatus
operator|->
name|size_bytes
operator|=
name|fst
operator|.
name|st_size
expr_stmt|;
comment|/****** CONVERSION PROBABLY REQUIRED HERE ******/
name|pstatus
operator|->
name|time_referenced
operator|=
name|fst
operator|.
name|st_atime
expr_stmt|;
name|pstatus
operator|->
name|time_created
operator|=
name|fst
operator|.
name|st_mtime
expr_stmt|;
return|return
literal|1
return|;
block|}
end_function

end_unit

