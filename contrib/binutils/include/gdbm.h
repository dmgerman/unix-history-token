begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* GNU DBM - DataBase Manager include file    Copyright 1989, 1991  Free Software Foundation, Inc.    Written by Philip A. Nelson.  This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version.  This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with this program; if not, write to the Free Software Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_comment
comment|/* You may contact the author by:        e-mail:  phil@wwu.edu       us-mail:  Philip A. Nelson                 Computer Science Department                 Western Washington University                 Bellingham, WA 98226         phone:  (206) 676-3035         *************************************************************************/
end_comment

begin_comment
comment|/* Parameters to gdbm_open for READERS, WRITERS, and WRITERS who    can create the database. */
end_comment

begin_define
define|#
directive|define
name|GDBM_READER
value|0
end_define

begin_define
define|#
directive|define
name|GDBM_WRITER
value|1
end_define

begin_define
define|#
directive|define
name|GDBM_WRCREAT
value|2
end_define

begin_define
define|#
directive|define
name|GDBM_NEWDB
value|3
end_define

begin_comment
comment|/* Parameters to gdbm_store for simple insertion or replacement. */
end_comment

begin_define
define|#
directive|define
name|GDBM_INSERT
value|0
end_define

begin_define
define|#
directive|define
name|GDBM_REPLACE
value|1
end_define

begin_comment
comment|/* The data and key structure.  This structure is defined for compatibility. */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|char
modifier|*
name|dptr
decl_stmt|;
name|int
name|dsize
decl_stmt|;
block|}
name|datum
typedef|;
end_typedef

begin_comment
comment|/* The file information header. This is good enough for most applications. */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|int
name|dummy
index|[
literal|10
index|]
decl_stmt|;
block|}
typedef|*
name|GDBM_FILE
typedef|;
end_typedef

begin_comment
comment|/* These are the routines! */
end_comment

begin_function_decl
specifier|extern
name|GDBM_FILE
name|gdbm_open
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|gdbm_close
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|datum
name|gdbm_fetch
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|gdbm_store
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|gdbm_delete
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|datum
name|gdbm_firstkey
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|datum
name|gdbm_nextkey
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|gdbm_reorganize
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* gdbm sends back the following error codes in the variable gdbm_errno. */
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|NO_ERROR
block|,
name|MALLOC_ERROR
block|,
name|BLOCK_SIZE_ERROR
block|,
name|FILE_OPEN_ERROR
block|,
name|FILE_WRITE_ERROR
block|,
name|FILE_SEEK_ERROR
block|,
name|FILE_READ_ERROR
block|,
name|BAD_MAGIC_NUMBER
block|,
name|EMPTY_DATABASE
block|,
name|CANT_BE_READER
block|,
name|CANT_BE_WRITER
block|,
name|READER_CANT_RECOVER
block|,
name|READER_CANT_DELETE
block|,
name|READER_CANT_STORE
block|,
name|READER_CANT_REORGANIZE
block|,
name|UNKNOWN_UPDATE
block|,
name|ITEM_NOT_FOUND
block|,
name|REORGANIZE_FAILED
block|,
name|CANNOT_REPLACE
block|}
name|gdbm_error
typedef|;
end_typedef

end_unit

