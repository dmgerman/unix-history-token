begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1989 The Regents of the University of California.  * All rights reserved.  *  * %sccs.include.redist.c%  *  *	@(#)dirent.h	7.1 (Berkeley) %G%  */
end_comment

begin_comment
comment|/*  * The dirent structure defines the format of directory entries returned by   * the getdirentries(2) system call.  *  * A directory entry has a struct dirent at the front of it, containing its  * inode number, the length of the entry, and the length of the name  * contained in the entry.  These are followed by the name padded to a 4  * byte boundary with null bytes.  All names are guaranteed null terminated.  * The maximum length of a name in a directory is MAXNAMLEN.  */
end_comment

begin_struct
struct|struct
name|dirent
block|{
name|u_long
name|d_fileno
decl_stmt|;
comment|/* file number of entry */
name|u_short
name|d_reclen
decl_stmt|;
comment|/* length of this record */
name|u_short
name|d_namlen
decl_stmt|;
comment|/* length of string in d_name */
ifdef|#
directive|ifdef
name|_POSIX_SOURCE
name|char
name|d_name
index|[
literal|255
operator|+
literal|1
index|]
decl_stmt|;
comment|/* name must be no longer than this */
else|#
directive|else
define|#
directive|define
name|MAXNAMLEN
value|255
name|char
name|d_name
index|[
name|MAXNAMLEN
operator|+
literal|1
index|]
decl_stmt|;
comment|/* name must be no longer than this */
endif|#
directive|endif
block|}
struct|;
end_struct

end_unit

