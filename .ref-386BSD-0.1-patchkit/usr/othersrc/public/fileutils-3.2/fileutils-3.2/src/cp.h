begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* cp.h  -- file copying (data definitions)    Copyright (C) 1989, 1990, 1991 Free Software Foundation.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2, or (at your option)    any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software    Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.     Written by Torbjorn Granlund, Sweden (tege@sics.se). */
end_comment

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|"system.h"
end_include

begin_struct
struct|struct
name|dir_list
block|{
name|struct
name|dir_list
modifier|*
name|parent
decl_stmt|;
name|ino_t
name|ino
decl_stmt|;
name|dev_t
name|dev
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|entry
block|{
name|ino_t
name|ino
decl_stmt|;
name|dev_t
name|dev
decl_stmt|;
name|char
modifier|*
name|node
decl_stmt|;
comment|/* Path name, or&new_file for new inodes.  */
name|struct
name|entry
modifier|*
name|coll_link
decl_stmt|;
comment|/* 0 = entry not occupied.  */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|htab
block|{
name|unsigned
name|modulus
decl_stmt|;
comment|/* Size of the `hash' pointer vector.  */
name|struct
name|entry
modifier|*
name|entry_tab
decl_stmt|;
comment|/* Pointer to dynamically growing vector.  */
name|unsigned
name|entry_tab_size
decl_stmt|;
comment|/* Size of current `entry_tab' allocation.  */
name|unsigned
name|first_free_entry
decl_stmt|;
comment|/* Index in `entry_tab'.  */
name|struct
name|entry
modifier|*
name|hash
index|[
literal|1
index|]
decl_stmt|;
comment|/* Vector of pointers in `entry_tab'.  */
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|int
name|exit_status
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|htab
modifier|*
name|htab
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* For created inodes, a pointer in the search structure to this    character identifies that the inode as new.  */
end_comment

begin_decl_stmt
specifier|extern
name|char
name|new_file
decl_stmt|;
end_decl_stmt

begin_function_decl
name|char
modifier|*
name|basename
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|xmalloc
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|xrealloc
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|forget_copied
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|forget_all
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|copy_reg
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|hash_init
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|remember_copied
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|remember_created
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|error
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|usage
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|savedir
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|stpcpy
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|yesno
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|do_copy
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|copy
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|copy_dir
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|strip_trailing_slashes
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|is_ancestor
parameter_list|()
function_decl|;
end_function_decl

begin_ifndef
ifndef|#
directive|ifndef
name|S_IWRITE
end_ifndef

begin_define
define|#
directive|define
name|S_IWRITE
value|S_IWUSR
end_define

begin_define
define|#
directive|define
name|S_IEXEC
value|S_IXUSR
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* stat and lstat need to be declared because we use their addresses. */
end_comment

begin_function_decl
name|int
name|stat
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|lstat
parameter_list|()
function_decl|;
end_function_decl

end_unit

