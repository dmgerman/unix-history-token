begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2, or (at your option)    any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.  */
end_comment

begin_comment
comment|/* Data type definitions and declarations for hardlink management.  */
end_comment

begin_comment
comment|/* This file should be #included in CVS source files after cvs.h    since it relies on types and macros defined there. */
end_comment

begin_comment
comment|/* The `checked_out' member of a hardlink_info struct is used only    when files are being checked out or updated.  It is used only when    hardlinked files are being checked out. */
end_comment

begin_struct
struct|struct
name|hardlink_info
block|{
name|Ctype
name|status
decl_stmt|;
comment|/* as returned from Classify_File() */
name|int
name|checked_out
decl_stmt|;
comment|/* has this file been checked out lately? */
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|List
modifier|*
name|hardlist
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|working_dir
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|Node
modifier|*
name|lookup_file_by_inode
name|PROTO
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|update_hardlink_info
name|PROTO
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|List
modifier|*
name|list_linked_files_on_disk
name|PROTO
argument_list|(
operator|(
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|compare_linkage_lists
name|PROTO
argument_list|(
operator|(
name|List
operator|*
operator|,
name|List
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|find_checkedout_proc
name|PROTO
argument_list|(
operator|(
name|Node
operator|*
operator|,
name|void
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

end_unit

