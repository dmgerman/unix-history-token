begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* mountlist.h -- declarations for list of mounted filesystems    Copyright (C) 1991, 1992 Free Software Foundation, Inc.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2, or (at your option)    any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software    Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.  */
end_comment

begin_comment
comment|/* A mount table entry. */
end_comment

begin_struct
struct|struct
name|mount_entry
block|{
name|char
modifier|*
name|me_devname
decl_stmt|;
comment|/* Device node pathname, including "/dev/". */
name|char
modifier|*
name|me_mountdir
decl_stmt|;
comment|/* Mount point directory pathname. */
name|char
modifier|*
name|me_type
decl_stmt|;
comment|/* "nfs", "4.2", etc. */
name|dev_t
name|me_dev
decl_stmt|;
comment|/* Device number of me_mountdir. */
name|struct
name|mount_entry
modifier|*
name|me_next
decl_stmt|;
block|}
struct|;
end_struct

begin_if
if|#
directive|if
name|__STDC__
end_if

begin_function_decl
name|struct
name|mount_entry
modifier|*
name|read_filesystem_list
parameter_list|(
name|int
name|need_fs_type
parameter_list|,
name|int
name|all_fs
parameter_list|)
function_decl|;
end_function_decl

begin_else
else|#
directive|else
end_else

begin_function_decl
name|struct
name|mount_entry
modifier|*
name|read_filesystem_list
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

end_unit

