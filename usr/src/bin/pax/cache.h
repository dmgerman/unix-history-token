begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1992 Keith Muller.  * Copyright (c) 1992, 1993  *	The Regents of the University of California.  All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Keith Muller of the University of California, San Diego.  *  * %sccs.include.redist.c%  *  *      @(#)cache.h	8.1 (Berkeley) %G%  */
end_comment

begin_comment
comment|/*  * Constants and data structures used to implement group and password file  * caches. Traditional passwd/group cache routines perform quite poorly with  * archives. The chances of hitting a valid lookup with an archive is quite a  * bit worse than with files already resident on the file system. These misses  * create a MAJOR performance cost. To adress this problem, these routines  * cache both hits and misses.  *  * NOTE:  name lengths must be as large as those stored in ANY PROTOCOL and  * as stored in the passwd and group files. CACHE SIZES MUST BE PRIME  */
end_comment

begin_define
define|#
directive|define
name|UNMLEN
value|32
end_define

begin_comment
comment|/*>= user name found in any protocol */
end_comment

begin_define
define|#
directive|define
name|GNMLEN
value|32
end_define

begin_comment
comment|/*>= group name found in any protocol */
end_comment

begin_define
define|#
directive|define
name|UID_SZ
value|317
end_define

begin_comment
comment|/* size of user_name/uid cache */
end_comment

begin_define
define|#
directive|define
name|UNM_SZ
value|317
end_define

begin_comment
comment|/* size of user_name/uid cache */
end_comment

begin_define
define|#
directive|define
name|GID_SZ
value|251
end_define

begin_comment
comment|/* size of gid cache */
end_comment

begin_define
define|#
directive|define
name|GNM_SZ
value|317
end_define

begin_comment
comment|/* size of group name cache */
end_comment

begin_define
define|#
directive|define
name|VALID
value|1
end_define

begin_comment
comment|/* entry and name are valid */
end_comment

begin_define
define|#
directive|define
name|INVALID
value|2
end_define

begin_comment
comment|/* entry valid, name NOT valid */
end_comment

begin_comment
comment|/*  * Node structures used in the user, group, uid, and gid caches.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|uidc
block|{
name|int
name|valid
decl_stmt|;
comment|/* is this a valid or a miss entry */
name|char
name|name
index|[
name|UNMLEN
index|]
decl_stmt|;
comment|/* uid name */
name|uid_t
name|uid
decl_stmt|;
comment|/* cached uid */
block|}
name|UIDC
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|gidc
block|{
name|int
name|valid
decl_stmt|;
comment|/* is this a valid or a miss entry */
name|char
name|name
index|[
name|GNMLEN
index|]
decl_stmt|;
comment|/* gid name */
name|gid_t
name|gid
decl_stmt|;
comment|/* cached gid */
block|}
name|GIDC
typedef|;
end_typedef

end_unit

