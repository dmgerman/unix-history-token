begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Reads arbitrarily long string from input file, returning it as a dynamic buffer.      Copyright (C) 1989 Free Software Foundation, Inc.    written by Douglas C. Schmidt (schmidt@ics.uci.edu)  This file is part of GNU GPERF.  GNU GPERF is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 1, or (at your option) any later version.  GNU GPERF is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GNU GPERF; see the file COPYING.  If not, write to the Free Software Foundation, 675 Mass Ave, Cambridge, MA 02139, USA.  */
end_comment

begin_comment
comment|/* Returns a pointer to an arbitrary length string.  Returns NULL on error or EOF    The storage for the string is dynamically allocated by new. */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_readline_h
end_ifndef

begin_define
define|#
directive|define
name|_readline_h
end_define

begin_include
include|#
directive|include
file|"prototype.h"
end_include

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|read_line
name|P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _readline_h */
end_comment

end_unit

