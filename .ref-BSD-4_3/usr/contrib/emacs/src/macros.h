begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Definitions for keyboard macro interpretation in GNU Emacs.    Copyright (C) 1985 Richard M. Stallman.  This file is part of GNU Emacs.  GNU Emacs is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY.  No author or distributor accepts responsibility to anyone for the consequences of using it or for whether it serves any particular purpose or works at all, unless he says so in writing.  Refer to the GNU Emacs General Public License for full details.  Everyone is granted permission to copy, modify and redistribute GNU Emacs, but only under the conditions described in the GNU Emacs General Public License.   A copy of this license is supposed to have been given to you along with GNU Emacs so you can know your rights and responsibilities.  It should be in a file named COPYING.  Among other things, the copyright notice and this notice must be preserved on all copies.  */
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

