begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Definitions for keyboard macro interpretation in GNU Emacs.    Copyright (C) 1985 Free Software Foundation, Inc.  This file is part of GNU Emacs.  GNU Emacs is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 1, or (at your option) any later version.  GNU Emacs is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GNU Emacs; see the file COPYING.  If not, write to the Free Software Foundation, 675 Mass Ave, Cambridge, MA 02139, USA.  */
end_comment

begin_comment
comment|/* Kbd macro currently being executed (a string) */
end_comment

begin_decl_stmt
specifier|extern
name|Lisp_Object
name|Vexecuting_macro
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Index of next character to fetch from that macro */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|executing_macro_index
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Nonzero while defining a kbd macro */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|defining_kbd_macro
decl_stmt|;
end_decl_stmt

end_unit

