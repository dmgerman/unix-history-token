begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1989 The Regents of the University of California.  * All rights reserved.  *  * Redistribution and use in source and binary forms are permitted  * provided that the above copyright notice and this paragraph are  * duplicated in all such forms and that any documentation,  * advertising materials, and other materials related to such  * distribution and use acknowledge that the software was developed  * by the University of California, Berkeley.  The name of the  * University may not be used to endorse or promote products derived  * from this software without specific prior written permission.  * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED  * WARRANTIES OF MERCHANTIBILITY AND FITNESS FOR A PARTICULAR PURPOSE.  *  *	@(#)dirent.h	5.1 (Berkeley) %G%  */
end_comment

begin_comment
comment|/*  * A directory entry has a struct direct at the front of it,  * containing its inode number, the length of the entry, and the  * length of the name contained in the entry.  These are followed  * by the name padded to a 4 byte boundary with null bytes.  All  * names are guaranteed null terminated.  The maximum length of a  * name in a directory is MAXNAMLEN.  */
end_comment

begin_define
define|#
directive|define
name|MAXNAMLEN
value|255
end_define

begin_struct
struct|struct
name|dirent
block|{
name|u_long
name|d_ino
decl_stmt|;
comment|/* inode number of entry */
name|u_short
name|d_reclen
decl_stmt|;
comment|/* length of this record */
name|u_short
name|d_namlen
decl_stmt|;
comment|/* length of string in d_name */
name|char
name|d_name
index|[
name|MAXNAMLEN
operator|+
literal|1
index|]
decl_stmt|;
comment|/* name must be no longer than this */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Definitions for library routines operating on directories.  */
end_comment

begin_define
define|#
directive|define
name|DIRBLKSIZ
value|512
end_define

begin_typedef
typedef|typedef
struct|struct
name|_dirdesc
block|{
name|int
name|dd_fd
decl_stmt|;
name|long
name|dd_loc
decl_stmt|;
name|long
name|dd_size
decl_stmt|;
name|char
name|dd_buf
index|[
name|DIRBLKSIZ
index|]
decl_stmt|;
block|}
name|DIR
typedef|;
end_typedef

begin_define
define|#
directive|define
name|dirfd
parameter_list|(
name|dirp
parameter_list|)
value|((dirp)->dd_fd)
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|NULL
end_ifndef

begin_define
define|#
directive|define
name|NULL
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
specifier|extern
name|DIR
modifier|*
name|opendir
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|struct
name|dirent
modifier|*
name|readdir
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|long
name|telldir
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|seekdir
parameter_list|()
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|rewinddir
parameter_list|(
name|dirp
parameter_list|)
value|seekdir((dirp), (long)0)
end_define

begin_function_decl
specifier|extern
name|void
name|closedir
parameter_list|()
function_decl|;
end_function_decl

end_unit

