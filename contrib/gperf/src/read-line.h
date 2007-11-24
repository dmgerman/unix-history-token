begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* This may look like C code, but it is really -*- C++ -*- */
end_comment

begin_comment
comment|/* Reads arbitrarily long string from input file, returning it as a    dynamically allocated buffer.     Copyright (C) 1989-1998 Free Software Foundation, Inc.    written by Douglas C. Schmidt (schmidt@ics.uci.edu)  This file is part of GNU GPERF.  GNU GPERF is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 1, or (at your option) any later version.  GNU GPERF is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GNU GPERF; see the file COPYING.  If not, write to the Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111, USA.  */
end_comment

begin_comment
comment|/* Returns a pointer to an arbitrary length string.  Returns NULL on error or EOF    The storage for the string is dynamically allocated by new. */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|read_line_h
end_ifndef

begin_define
define|#
directive|define
name|read_line_h
value|1
end_define

begin_include
include|#
directive|include
file|<stdio.h>
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
name|public
label|:
name|Read_Line
argument_list|(
name|FILE
operator|*
name|stream
operator|=
name|stdin
argument_list|)
operator|:
name|fp
argument_list|(
argument|stream
argument_list|)
block|{}
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

begin_include
include|#
directive|include
file|"trace.h"
end_include

begin_define
define|#
directive|define
name|INLINE
value|inline
end_define

begin_include
include|#
directive|include
file|"read-line.icc"
end_include

begin_undef
undef|#
directive|undef
name|INLINE
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

end_unit

