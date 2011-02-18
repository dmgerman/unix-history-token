begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Intel 80386 opcode table    Copyright 2007    Free Software Foundation, Inc.     This file is part of GAS, the GNU Assembler, and GDB, the GNU Debugger.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2 of the License, or    (at your option) any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software    Foundation, Inc., 51 Franklin Street - Fifth Floor, Boston, MA 02110-1301, USA.  */
end_comment

begin_include
include|#
directive|include
file|"sysdep.h"
end_include

begin_include
include|#
directive|include
file|"libiberty.h"
end_include

begin_include
include|#
directive|include
file|"i386-opc.h"
end_include

begin_include
include|#
directive|include
file|"i386-tbl.h"
end_include

begin_comment
comment|/* Segment stuff.  */
end_comment

begin_decl_stmt
specifier|const
name|seg_entry
name|cs
init|=
block|{
literal|"cs"
block|,
literal|0x2e
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|seg_entry
name|ds
init|=
block|{
literal|"ds"
block|,
literal|0x3e
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|seg_entry
name|ss
init|=
block|{
literal|"ss"
block|,
literal|0x36
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|seg_entry
name|es
init|=
block|{
literal|"es"
block|,
literal|0x26
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|seg_entry
name|fs
init|=
block|{
literal|"fs"
block|,
literal|0x64
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|seg_entry
name|gs
init|=
block|{
literal|"gs"
block|,
literal|0x65
block|}
decl_stmt|;
end_decl_stmt

end_unit

