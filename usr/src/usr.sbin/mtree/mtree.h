begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1990 The Regents of the University of California.  * All rights reserved.  *  * %sccs.include.redist.c%  *  *	@(#)mtree.h	5.2 (Berkeley) %G%  */
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

begin_typedef
typedef|typedef
struct|struct
name|_id
block|{
name|struct
name|_id
modifier|*
name|next
decl_stmt|;
name|u_int
name|id
decl_stmt|;
name|u_long
name|cnt
decl_stmt|;
block|}
name|ID
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_info
block|{
define|#
directive|define
name|F_CKSUM
value|0x001
comment|/* check sum */
define|#
directive|define
name|F_DMODE
value|0x002
comment|/* directory mode */
define|#
directive|define
name|F_FMODE
value|0x004
comment|/* directory mode */
define|#
directive|define
name|F_GROUP
value|0x008
comment|/* group */
define|#
directive|define
name|F_MODE
value|0x010
comment|/* directory mode */
define|#
directive|define
name|F_NLINK
value|0x020
comment|/* number of links */
define|#
directive|define
name|F_OWNER
value|0x040
comment|/* owner */
define|#
directive|define
name|F_SIZE
value|0x080
comment|/* size */
define|#
directive|define
name|F_SLINK
value|0x100
comment|/* link count */
define|#
directive|define
name|F_TYPE
value|0x200
comment|/* file type */
name|u_int
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
name|F_FILE
value|0x008
comment|/* regular file */
define|#
directive|define
name|F_LINK
value|0x010
comment|/* symbolic link */
define|#
directive|define
name|F_SOCK
value|0x020
comment|/* socket */
name|u_int
name|type
decl_stmt|;
comment|/* file type */
name|uid_t
name|st_uid
decl_stmt|;
name|gid_t
name|st_gid
decl_stmt|;
name|off_t
name|st_size
decl_stmt|;
name|mode_t
name|st_mode
decl_stmt|;
name|nlink_t
name|st_nlink
decl_stmt|;
name|u_long
name|cksum
decl_stmt|;
comment|/* check sum */
name|char
modifier|*
name|slink
decl_stmt|;
comment|/* symbolic link reference */
block|}
name|INFO
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_entry
block|{
name|struct
name|_entry
modifier|*
name|next
decl_stmt|,
modifier|*
name|child
decl_stmt|,
modifier|*
name|parent
decl_stmt|;
comment|/* tree links */
name|INFO
name|info
decl_stmt|;
comment|/* node info structure */
define|#
directive|define
name|F_DONE
value|0x01
comment|/* directory done */
define|#
directive|define
name|F_IGN
value|0x02
comment|/* ignore this node on down */
define|#
directive|define
name|F_VISIT
value|0x04
comment|/* visited this node */
name|u_int
name|flags
decl_stmt|;
comment|/* flags */
name|char
modifier|*
name|name
decl_stmt|;
comment|/* node name */
name|int
name|nlen
decl_stmt|;
comment|/* name length */
block|}
name|ENTRY
typedef|;
end_typedef

end_unit

