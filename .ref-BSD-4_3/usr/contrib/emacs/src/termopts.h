begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Flags and paramaters describing user options for handling the terminal.    Copyright (C) 1985 Richard M. Stallman.  This file is part of GNU Emacs.  GNU Emacs is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY.  No author or distributor accepts responsibility to anyone for the consequences of using it or for whether it serves any particular purpose or works at all, unless he says so in writing.  Refer to the GNU Emacs General Public License for full details.  Everyone is granted permission to copy, modify and redistribute GNU Emacs, but only under the conditions described in the GNU Emacs General Public License.   A copy of this license is supposed to have been given to you along with GNU Emacs so you can know your rights and responsibilities.  It should be in a file named COPYING.  Among other things, the copyright notice and this notice must be preserved on all copies.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|visible_bell
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* If true and the terminal will support it 				   then the screen will flash instead of 				   feeping when an error occurs */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|inverse_video
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* If true and the terminal will support it 				   then we will use inverse video */
end_comment

begin_comment
comment|/* Nonzero means use ^S/^Q as cretinous flow control.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|flow_control
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Nonzero means use interrupt-driven input.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|interrupt_input
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|MetaFlag
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Terminal has meta key */
end_comment

begin_comment
comment|/* Nonzero means truncate lines in all windows less wide than the screen */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|truncate_partial_width_windows
decl_stmt|;
end_decl_stmt

end_unit

