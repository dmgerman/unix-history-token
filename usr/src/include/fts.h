begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1989 The Regents of the University of California.  * All rights reserved.  *  * Redistribution and use in source and binary forms are permitted  * provided that the above copyright notice and this paragraph are  * duplicated in all such forms and that any documentation,  * advertising materials, and other materials related to such  * distribution and use acknowledge that the software was developed  * by the University of California, Berkeley.  The name of the  * University may not be used to endorse or promote products derived  * from this software without specific prior written permission.  * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED  * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.  *  *	@(#)fts.h	5.1 (Berkeley) %G%  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|fts
block|{
name|struct
name|ftsent
modifier|*
name|cur
decl_stmt|;
comment|/* current node */
name|struct
name|ftsent
modifier|*
name|child
decl_stmt|;
comment|/* linked list of children */
name|struct
name|ftsent
modifier|*
name|savelink
decl_stmt|;
comment|/* saved link if node had a cycle */
name|struct
name|ftsent
modifier|*
modifier|*
name|array
decl_stmt|;
comment|/* sort array */
name|char
modifier|*
name|path
decl_stmt|;
comment|/* path for this descent */
name|char
modifier|*
name|wd
decl_stmt|;
comment|/* starting directory */
name|int
name|pathlen
decl_stmt|;
comment|/* sizeof(path) */
name|int
name|nitems
decl_stmt|;
comment|/* elements in the sort array */
name|int
function_decl|(
modifier|*
name|compar
function_decl|)
parameter_list|()
function_decl|;
comment|/* compare function */
define|#
directive|define
name|FTS__STOP
value|0x001
comment|/* private: unrecoverable error */
define|#
directive|define
name|FTS_LOGICAL
value|0x002
comment|/* user: use stat(2) */
define|#
directive|define
name|FTS_MULTIPLE
value|0x004
comment|/* user: multiple args */
define|#
directive|define
name|FTS_NOCHDIR
value|0x008
comment|/* user: don't use chdir(2) */
define|#
directive|define
name|FTS_NOSTAT
value|0x010
comment|/* user: don't require stat info */
define|#
directive|define
name|FTS_PHYSICAL
value|0x020
comment|/* user: use lstat(2) */
define|#
directive|define
name|FTS_SEEDOT
value|0x040
comment|/* user: return dot and dot-dot */
name|int
name|options
decl_stmt|;
comment|/* openfts() options */
block|}
name|FTS
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|ftsent
block|{
name|struct
name|ftsent
modifier|*
name|parent
decl_stmt|;
comment|/* parent directory */
name|struct
name|ftsent
modifier|*
name|link
decl_stmt|;
comment|/* next/cycle node */
union|union
block|{
name|long
name|number
decl_stmt|;
comment|/* local numeric value */
name|void
modifier|*
name|pointer
decl_stmt|;
comment|/* local address value */
block|}
name|local
union|;
name|char
modifier|*
name|accpath
decl_stmt|;
comment|/* path from current directory */
name|char
modifier|*
name|path
decl_stmt|;
comment|/* path from starting directory */
name|short
name|pathlen
decl_stmt|;
comment|/* strlen(path) */
name|short
name|namelen
decl_stmt|;
comment|/* strlen(name) */
name|short
name|level
decl_stmt|;
comment|/* depth (-1 to N) */
define|#
directive|define
name|FTS_D
value|1
comment|/* preorder directory */
define|#
directive|define
name|FTS_DC
value|2
comment|/* directory that causes cycles */
define|#
directive|define
name|FTS_DNR
value|3
comment|/* unreadable directory */
define|#
directive|define
name|FTS_DNX
value|4
comment|/* unsearchable directory */
define|#
directive|define
name|FTS_DP
value|5
comment|/* postorder directory */
define|#
directive|define
name|FTS_ERR
value|6
comment|/* error; errno is set */
define|#
directive|define
name|FTS_F
value|7
comment|/* regular file */
define|#
directive|define
name|FTS_NS
value|8
comment|/* no stat(2) information */
define|#
directive|define
name|FTS_SL
value|9
comment|/* symbolic link */
define|#
directive|define
name|FTS_SLNONE
value|10
comment|/* symbolic link without target */
define|#
directive|define
name|FTS_DEFAULT
value|11
comment|/* none of the above */
name|u_short
name|info
decl_stmt|;
comment|/* file information */
define|#
directive|define
name|FTS_AGAIN
value|1
comment|/* user: read node again */
define|#
directive|define
name|FTS_SKIP
value|2
comment|/* user: discard node */
define|#
directive|define
name|FTS_FOLLOW
value|3
comment|/* user: follow symbolic link */
name|short
name|instr
decl_stmt|;
comment|/* setfts() instructions */
name|struct
name|stat
name|statb
decl_stmt|;
comment|/* stat(2) information */
name|char
name|name
index|[
literal|1
index|]
decl_stmt|;
comment|/* file name */
block|}
name|FTSENT
typedef|;
end_typedef

begin_function_decl
name|FTS
modifier|*
name|ftsopen
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
name|FTSENT
modifier|*
name|ftschildren
argument_list|()
decl_stmt|,
modifier|*
name|ftsread
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|ftsclose
argument_list|()
decl_stmt|,
name|ftsset
argument_list|()
decl_stmt|;
end_decl_stmt

end_unit

