begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* ldver.h -- Header file for ldver.c.    Copyright 1991, 1992, 1993, 1996 Free Software Foundation, Inc.  This file is part of GLD, the Gnu Linker.  This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version.  This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with this program; if not, write to the Free Software Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_decl_stmt
specifier|extern
specifier|const
name|char
modifier|*
name|ld_program_version
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|ldversion
name|PARAMS
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

end_unit

