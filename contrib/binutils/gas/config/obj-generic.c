begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* This file is obj-generic.c and is intended to be a template for    object format specific source files.     Copyright (C) 1987-1992 Free Software Foundation, Inc.     This file is part of GAS, the GNU Assembler.     GAS is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2, or (at your option)    any later version.     GAS is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with GAS; see the file COPYING.  If not, write to    the Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_comment
comment|/* Chars that can be used to separate mant from exp in floating point nums */
end_comment

begin_decl_stmt
name|char
name|EXP_CHARS
index|[]
init|=
literal|"eE"
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Chars that mean this number is a floating point constant */
end_comment

begin_comment
comment|/* As in 0f12.456 */
end_comment

begin_comment
comment|/* or    0d1.2345e12 */
end_comment

begin_decl_stmt
name|char
name|FLT_CHARS
index|[]
init|=
literal|"rRsSfFdDxXpP"
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* These chars start a comment anywhere in a source file (except inside    another comment */
end_comment

begin_decl_stmt
specifier|const
name|char
name|comment_chars
index|[]
init|=
literal|"#"
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * Local Variables:  * comment-column: 0  * fill-column: 131  * End:  */
end_comment

begin_comment
comment|/* end of obj-generic.c */
end_comment

end_unit

