begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Tracing function calls.    Copyright (C) 1989-1998 Free Software Foundation, Inc.    written by Douglas C. Schmidt (schmidt@ics.uci.edu)  This file is part of GNU GPERF.  GNU GPERF is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 1, or (at your option) any later version.  GNU GPERF is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GNU GPERF; see the file COPYING.  If not, write to the Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111, USA.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|trace_h
end_ifndef

begin_define
define|#
directive|define
name|trace_h
value|1
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|TRACE
end_ifdef

begin_define
define|#
directive|define
name|T
parameter_list|(
name|X
parameter_list|)
value|X
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|T
parameter_list|(
name|X
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
name|class
name|Trace
block|{
name|private
label|:
specifier|static
name|int
name|nesting
decl_stmt|;
specifier|const
name|char
modifier|*
name|name
decl_stmt|;
name|public
label|:
name|Trace
argument_list|(
specifier|const
name|char
operator|*
name|n
argument_list|)
expr_stmt|;
operator|~
name|Trace
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

