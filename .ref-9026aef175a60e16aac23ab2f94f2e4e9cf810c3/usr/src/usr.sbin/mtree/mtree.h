begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1990, 1993  *	The Regents of the University of California.  All rights reserved.  *  * %sccs.include.redist.c%  *  *	@(#)mtree.h	8.1 (Berkeley) %G%  */
end_comment

begin_include
include|#
directive|include
file|<string.h>
end_include

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_define
define|#
directive|define
name|KEYDEFAULT
define|\
value|(F_GID | F_MODE | F_NLINK | F_SIZE | F_SLINK | F_TIME | F_UID)
end_define

begin_define
define|#
directive|define
name|MISMATCHEXIT
value|2
end_define

begin_typedef
typedef|typedef
struct|struct
name|_node
block|{
name|struct
name|_node
modifier|*
name|parent
decl_stmt|,
modifier|*
name|child
decl_stmt|;
comment|/* up, down */
name|struct
name|_node
modifier|*
name|prev
decl_stmt|,
modifier|*
name|next
decl_stmt|;
comment|/* left, right */
name|off_t
name|st_size
decl_stmt|;
comment|/* size */
name|struct
name|timespec
name|st_mtimespec
decl_stmt|;
comment|/* last modification time */
name|u_long
name|cksum
decl_stmt|;
comment|/* check sum */
name|char
modifier|*
name|slink
decl_stmt|;
comment|/* symbolic link reference */
name|uid_t
name|st_uid
decl_stmt|;
comment|/* uid */
name|gid_t
name|st_gid
decl_stmt|;
comment|/* gid */
define|#
directive|define
name|MBITS
value|(S_ISUID|S_ISGID|S_ISTXT|S_IRWXU|S_IRWXG|S_IRWXO)
name|mode_t
name|st_mode
decl_stmt|;
comment|/* mode */
name|nlink_t
name|st_nlink
decl_stmt|;
comment|/* link count */
define|#
directive|define
name|F_CKSUM
value|0x0001
comment|/* check sum */
define|#
directive|define
name|F_DONE
value|0x0002
comment|/* directory done */
define|#
directive|define
name|F_GID
value|0x0004
comment|/* gid */
define|#
directive|define
name|F_GNAME
value|0x0008
comment|/* group name */
define|#
directive|define
name|F_IGN
value|0x0010
comment|/* ignore */
define|#
directive|define
name|F_MAGIC
value|0x0020
comment|/* name has magic chars */
define|#
directive|define
name|F_MODE
value|0x0040
comment|/* mode */
define|#
directive|define
name|F_NLINK
value|0x0080
comment|/* number of links */
define|#
directive|define
name|F_SIZE
value|0x0100
comment|/* size */
define|#
directive|define
name|F_SLINK
value|0x0200
comment|/* link count */
define|#
directive|define
name|F_TIME
value|0x0400
comment|/* modification time */
define|#
directive|define
name|F_TYPE
value|0x0800
comment|/* file type */
define|#
directive|define
name|F_UID
value|0x1000
comment|/* uid */
define|#
directive|define
name|F_UNAME
value|0x2000
comment|/* user name */
define|#
directive|define
name|F_VISIT
value|0x4000
comment|/* file visited */
name|u_short
name|flags
decl_stmt|;
comment|/* items set */
define|#
directive|define
name|F_BLOCK
value|0x001
comment|/* block special */
define|#
directive|define
name|F_CHAR
value|0x002
comment|/* char special */
define|#
directive|define
name|F_DIR
value|0x004
comment|/* directory */
define|#
directive|define
name|F_FIFO
value|0x008
comment|/* fifo */
define|#
directive|define
name|F_FILE
value|0x010
comment|/* regular file */
define|#
directive|define
name|F_LINK
value|0x020
comment|/* symbolic link */
define|#
directive|define
name|F_SOCK
value|0x040
comment|/* socket */
name|u_char
name|type
decl_stmt|;
comment|/* file type */
name|char
name|name
index|[
literal|1
index|]
decl_stmt|;
comment|/* file name (must be last) */
block|}
name|NODE
typedef|;
end_typedef

begin_define
define|#
directive|define
name|RP
parameter_list|(
name|p
parameter_list|)
define|\
value|((p)->fts_path[0] == '.'&& (p)->fts_path[1] == '/' ? \ 	    (p)->fts_path + 2 : (p)->fts_path)
end_define

end_unit

