begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* This may look like C code, but it is really -*- C++ -*- */
end_comment

begin_comment
comment|/* Reads arbitrarily long string from input file, returning it as a dynamic buffer.      Copyright (C) 1989 Free Software Foundation, Inc.    written by Douglas C. Schmidt (schmidt@ics.uci.edu)  This file is part of GNU GPERF.  GNU GPERF is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 1, or (at your option) any later version.  GNU GPERF is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GNU GPERF; see the file COPYING.  If not, write to the Free Software Foundation, 675 Mass Ave, Cambridge, MA 02139, USA.  */
end_comment

begin_comment
comment|/* Returns a pointer to an arbitrary length string.  Returns NULL on error or EOF    The storage for the string is dynamically allocated by new. */
end_comment

begin_pragma
pragma|#
directive|pragma
name|once
end_pragma

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|"trace.h"
end_include

begin_decl_stmt
name|class
name|Read_Line
block|{
name|private
label|:
name|char
modifier|*
name|readln_aux
parameter_list|(
name|int
name|chunks
parameter_list|)
function_decl|;
name|FILE
modifier|*
name|fp
decl_stmt|;
comment|/* FILE pointer to the input stream. */
specifier|const
name|int
name|CHUNK_SIZE
decl_stmt|;
comment|/* Size of each chunk. */
name|public
label|:
name|Read_Line
argument_list|(
argument|FILE *stream = stdin
argument_list|,
argument|int size = BUFSIZ
argument_list|)
block|:
name|fp
argument_list|(
name|stream
argument_list|)
operator|,
name|CHUNK_SIZE
argument_list|(
argument|size
argument_list|)
block|{;}
name|char
operator|*
name|get_line
argument_list|(
name|void
argument_list|)
expr_stmt|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|__OPTIMIZE__
end_ifdef

begin_expr_stmt
specifier|inline
name|char
operator|*
name|Read_Line
operator|::
name|get_line
argument_list|(
argument|void
argument_list|)
block|{
name|T
argument_list|(
argument|Trace t (
literal|"Read_Line::get_line"
argument|);
argument_list|)
name|int
name|c
block|;
if|if
condition|(
operator|(
name|c
operator|=
name|getc
argument_list|(
name|fp
argument_list|)
operator|)
operator|==
literal|'#'
condition|)
block|{
while|while
condition|(
name|getc
argument_list|(
name|fp
argument_list|)
operator|!=
literal|'\n'
condition|)
empty_stmt|;
return|return
name|get_line
argument_list|()
return|;
block|}
end_expr_stmt

begin_else
else|else
block|{
name|ungetc
argument_list|(
name|c
argument_list|,
name|stdin
argument_list|)
expr_stmt|;
return|return
name|readln_aux
argument_list|(
literal|0
argument_list|)
return|;
block|}
end_else

begin_endif
unit|}
endif|#
directive|endif
end_endif

end_unit

