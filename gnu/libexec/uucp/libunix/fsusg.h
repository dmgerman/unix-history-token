begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* fsusage.h -- declarations for filesystem space usage info    Copyright (C) 1991, 1992 Free Software Foundation, Inc.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2, or (at your option)    any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software    Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.     This files was modified slightly by Ian Lance Taylor for use with    Taylor UUCP.  */
end_comment

begin_comment
comment|/* Space usage statistics for a filesystem.  Blocks are 512-byte. */
end_comment

begin_struct
struct|struct
name|fs_usage
block|{
name|long
name|fsu_blocks
decl_stmt|;
comment|/* Total blocks. */
name|long
name|fsu_bfree
decl_stmt|;
comment|/* Free blocks available to superuser. */
name|long
name|fsu_bavail
decl_stmt|;
comment|/* Free blocks available to non-superuser. */
name|long
name|fsu_files
decl_stmt|;
comment|/* Total file nodes. */
name|long
name|fsu_ffree
decl_stmt|;
comment|/* Free file nodes. */
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|int
name|get_fs_usage
name|P
argument_list|(
operator|(
name|char
operator|*
name|path
operator|,
name|char
operator|*
name|disk
operator|,
expr|struct
name|fs_usage
operator|*
name|fsp
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

end_unit

