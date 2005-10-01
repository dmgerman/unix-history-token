begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Default definition for ARGP_PROGRAM_BUG_ADDRESS.    Copyright (C) 1996, 1997, 1999 Free Software Foundation, Inc.    This file is part of the GNU C Library.    Written by Miles Bader<miles@gnu.ai.mit.edu>.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2, or (at your option)    any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License along    with this program; if not, write to the Free Software Foundation,    Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_comment
comment|/* If set by the user program, it should point to string that is the    bug-reporting address for the program.  It will be printed by argp_help if    the ARGP_HELP_BUG_ADDR flag is set (as it is by various standard help    messages), embedded in a sentence that says something like `Report bugs to    ADDR.'.  */
end_comment

begin_decl_stmt
specifier|const
name|char
modifier|*
name|argp_program_bug_address
decl_stmt|;
end_decl_stmt

end_unit

