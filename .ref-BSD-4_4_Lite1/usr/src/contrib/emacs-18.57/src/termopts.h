begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Flags and paramaters describing user options for handling the terminal.    Copyright (C) 1985, 1986 Free Software Foundation, Inc.  This file is part of GNU Emacs.  GNU Emacs is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 1, or (at your option) any later version.  GNU Emacs is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GNU Emacs; see the file COPYING.  If not, write to the Free Software Foundation, 675 Mass Ave, Cambridge, MA 02139, USA.  */
end_comment

begin_comment
comment|/* Nonzero means flash the screen instead of ringing the bell.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|visible_bell
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Nonzero means invert white and black for the entire screen.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|inverse_video
decl_stmt|;
end_decl_stmt

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

begin_comment
comment|/* Nonzero while interrupts are temporarily deferred during redisplay.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|interrupts_deferred
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Nonzero if terminal has a meta key.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|meta_key
decl_stmt|;
end_decl_stmt

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

