begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* This may look like C code, but it is really -*- C++ -*- */
end_comment

begin_comment
comment|/* Provides a useful variable-length argument error handling abstraction.     Copyright (C) 1989 Free Software Foundation, Inc.    written by Douglas C. Schmidt (schmidt@ics.uci.edu)  This file is part of GNU GPERF.  GNU GPERF is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 1, or (at your option) any later version.  GNU GPERF is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GNU GPERF; see the file COPYING.  If not, write to the Free Software Foundation, 675 Mass Ave, Cambridge, MA 02139, USA.  */
end_comment

begin_pragma
pragma|#
directive|pragma
name|once
end_pragma

begin_decl_stmt
name|class
name|Std_Err
block|{
name|private
label|:
specifier|static
name|char
modifier|*
name|program_name
decl_stmt|;
comment|/* Records the program name. */
name|public
label|:
specifier|static
name|void
name|set_program_name
parameter_list|(
name|char
modifier|*
name|prog_name
parameter_list|)
function_decl|;
specifier|static
name|void
name|report_error
parameter_list|(
name|char
modifier|*
name|format
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

end_unit

