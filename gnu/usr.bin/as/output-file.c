begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* output-file.c -  Deal with the output file    Copyright (C) 1987, 1990, 1991, 1992 Free Software Foundation, Inc.     This file is part of GAS, the GNU Assembler.     GAS is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2, or (at your option)    any later version.     GAS is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with GAS; see the file COPYING.  If not, write to    the Free Software Foundation, 675 Mass Ave, Cambridge, MA 02139, USA.  */
end_comment

begin_comment
comment|/*  * Confines all details of emitting object bytes to this module.  * All O/S specific crocks should live here.  * What we lose in "efficiency" we gain in modularity.  * Note we don't need to #include the "as.h" file. No common coupling!  */
end_comment

begin_comment
comment|/* note that we do need config info.  xoxorich. */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|lint
end_ifndef

begin_decl_stmt
specifier|static
name|char
name|rcsid
index|[]
init|=
literal|"$FreeBSD$"
decl_stmt|;
end_decl_stmt

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
file|"as.h"
end_include

begin_include
include|#
directive|include
file|"output-file.h"
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|BFD_HEADERS
end_ifdef

begin_include
include|#
directive|include
file|"bfd.h"
end_include

begin_decl_stmt
name|bfd
modifier|*
name|stdoutput
decl_stmt|;
end_decl_stmt

begin_function
name|void
name|output_file_create
parameter_list|(
name|name
parameter_list|)
name|char
modifier|*
name|name
decl_stmt|;
block|{
if|if
condition|(
name|name
index|[
literal|0
index|]
operator|==
literal|'-'
operator|&&
name|name
index|[
literal|1
index|]
operator|==
literal|'\0'
condition|)
block|{
name|as_perror
argument_list|(
literal|"FATAL: Can't open a bfd on stdout %s "
argument_list|,
name|name
argument_list|)
expr_stmt|;
block|}
elseif|else
if|if
condition|(
operator|!
operator|(
name|stdoutput
operator|=
name|bfd_openw
argument_list|(
name|name
argument_list|,
name|TARGET_FORMAT
argument_list|)
operator|)
condition|)
block|{
name|as_perror
argument_list|(
literal|"FATAL: Can't create %s"
argument_list|,
name|name
argument_list|)
expr_stmt|;
name|exit
argument_list|(
literal|42
argument_list|)
expr_stmt|;
block|}
name|bfd_set_format
argument_list|(
name|stdoutput
argument_list|,
name|bfd_object
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/* output_file_create() */
end_comment

begin_function
name|void
name|output_file_close
parameter_list|(
name|filename
parameter_list|)
name|char
modifier|*
name|filename
decl_stmt|;
block|{
comment|/* Close the bfd without getting bfd to write out anything by itself */
if|if
condition|(
name|bfd_close_all_done
argument_list|(
name|stdoutput
argument_list|)
operator|==
literal|0
condition|)
block|{
name|as_perror
argument_list|(
literal|"FATAL: Can't close %s\n"
argument_list|,
name|filename
argument_list|)
expr_stmt|;
name|exit
argument_list|(
literal|42
argument_list|)
expr_stmt|;
block|}
name|stdoutput
operator|=
name|NULL
expr_stmt|;
comment|/* Trust nobody! */
block|}
end_function

begin_comment
comment|/* output_file_close() */
end_comment

begin_function
name|void
name|output_file_append
parameter_list|(
name|where
parameter_list|,
name|length
parameter_list|,
name|filename
parameter_list|)
name|char
modifier|*
name|where
decl_stmt|;
name|long
name|length
decl_stmt|;
name|char
modifier|*
name|filename
decl_stmt|;
block|{
name|abort
argument_list|()
expr_stmt|;
comment|/* Never do this */
block|}
end_function

begin_else
else|#
directive|else
end_else

begin_decl_stmt
specifier|static
name|FILE
modifier|*
name|stdoutput
decl_stmt|;
end_decl_stmt

begin_function
name|void
name|output_file_create
parameter_list|(
name|name
parameter_list|)
name|char
modifier|*
name|name
decl_stmt|;
block|{
if|if
condition|(
name|name
index|[
literal|0
index|]
operator|==
literal|'-'
operator|&&
name|name
index|[
literal|1
index|]
operator|==
literal|'\0'
condition|)
name|stdoutput
operator|=
name|stdout
expr_stmt|;
elseif|else
if|if
condition|(
operator|!
operator|(
name|stdoutput
operator|=
name|fopen
argument_list|(
name|name
argument_list|,
literal|"wb"
argument_list|)
operator|)
condition|)
block|{
name|as_perror
argument_list|(
literal|"FATAL: Can't create %s"
argument_list|,
name|name
argument_list|)
expr_stmt|;
name|exit
argument_list|(
literal|42
argument_list|)
expr_stmt|;
block|}
block|}
end_function

begin_comment
comment|/* output_file_create() */
end_comment

begin_function
name|void
name|output_file_close
parameter_list|(
name|filename
parameter_list|)
name|char
modifier|*
name|filename
decl_stmt|;
block|{
if|if
condition|(
name|EOF
operator|==
name|fclose
argument_list|(
name|stdoutput
argument_list|)
condition|)
block|{
name|as_perror
argument_list|(
literal|"FATAL: Can't close %s"
argument_list|,
name|filename
argument_list|)
expr_stmt|;
name|exit
argument_list|(
literal|42
argument_list|)
expr_stmt|;
block|}
name|stdoutput
operator|=
name|NULL
expr_stmt|;
comment|/* Trust nobody! */
block|}
end_function

begin_comment
comment|/* output_file_close() */
end_comment

begin_function
name|void
name|output_file_append
parameter_list|(
name|where
parameter_list|,
name|length
parameter_list|,
name|filename
parameter_list|)
name|char
modifier|*
name|where
decl_stmt|;
name|long
name|length
decl_stmt|;
name|char
modifier|*
name|filename
decl_stmt|;
block|{
for|for
control|(
init|;
name|length
condition|;
name|length
operator|--
operator|,
name|where
operator|++
control|)
block|{
operator|(
name|void
operator|)
name|putc
argument_list|(
operator|*
name|where
argument_list|,
name|stdoutput
argument_list|)
expr_stmt|;
if|if
condition|(
name|ferror
argument_list|(
name|stdoutput
argument_list|)
condition|)
comment|/* if ( EOF == (putc( *where, stdoutput )) ) */
block|{
name|as_perror
argument_list|(
literal|"Failed to emit an object byte"
argument_list|,
name|filename
argument_list|)
expr_stmt|;
name|as_fatal
argument_list|(
literal|"Can't continue"
argument_list|)
expr_stmt|;
block|}
block|}
block|}
end_function

begin_comment
comment|/* output_file_append() */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* end of output-file.c */
end_comment

end_unit

