begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* fsusage.h -- declarations for filesystem space usage info    Copyright (C) 1991, 1992 Free Software Foundation, Inc.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2, or (at your option)    any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software    Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.  */
end_comment

begin_comment
comment|/* Space usage statistics for a filesystem.  Blocks are 1024-byte. */
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

begin_if
if|#
directive|if
name|__STDC__
end_if

begin_function_decl
name|int
name|get_fs_usage
parameter_list|(
name|char
modifier|*
name|path
parameter_list|,
name|struct
name|fs_usage
modifier|*
name|fsp
parameter_list|)
function_decl|;
end_function_decl

begin_else
else|#
directive|else
end_else

begin_function_decl
name|int
name|get_fs_usage
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

end_unit

