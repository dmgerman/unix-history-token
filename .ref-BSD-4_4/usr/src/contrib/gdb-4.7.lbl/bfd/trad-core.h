begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Declarations of BFD back end for traditional Unix core files     Copyright (C) 1990-1991 Free Software Foundation, Inc.    Written by Cygnus Support.  Mostly John Gilmore's fault.  This file is part of BFD, the Binary File Descriptor library.  This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version.  This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with this program; if not, write to the Free Software Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.  */
end_comment

begin_include
include|#
directive|include
file|"ansidecl.h"
end_include

begin_comment
comment|/* forward declaration */
end_comment

begin_expr_stmt
name|PROTO
argument_list|(
name|bfd_target
operator|*
argument_list|,
name|trad_unix_core_file_p
argument_list|,
operator|(
name|bfd
operator|*
name|abfd
operator|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|PROTO
argument_list|(
name|char
operator|*
argument_list|,
name|trad_unix_core_file_failing_command
argument_list|,
operator|(
name|bfd
operator|*
name|abfd
operator|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|PROTO
argument_list|(
name|int
argument_list|,
name|trad_unix_core_file_failing_signal
argument_list|,
operator|(
name|bfd
operator|*
name|abfd
operator|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|PROTO
argument_list|(
name|boolean
argument_list|,
name|trad_unix_core_file_matches_executable_p
argument_list|,
operator|(
name|bfd
operator|*
name|core_bfd
operator|,
name|bfd
operator|*
name|exec_bfd
operator|)
argument_list|)
expr_stmt|;
end_expr_stmt

end_unit

