begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1989 The Regents of the University of California.  * All rights reserved.  *  * Redistribution and use in source and binary forms are permitted  * provided that the above copyright notice and this paragraph are  * duplicated in all such forms and that any documentation,  * advertising materials, and other materials related to such  * distribution and use acknowledge that the software was developed  * by the University of California, Berkeley.  The name of the  * University may not be used to endorse or promote products derived  * from this software without specific prior written permission.  * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED  * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.  *  *	@(#)fts.h	5.3 (Berkeley) %G%  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|fts
block|{
name|struct
name|ftsent
modifier|*
name|fts_cur
decl_stmt|;
comment|/* current node */
name|struct
name|ftsent
modifier|*
name|fts_child
decl_stmt|;
comment|/* linked list of children */
name|struct
name|ftsent
modifier|*
name|fts_savelink
decl_stmt|;
comment|/* saved link if node had a cycle */
name|struct
name|ftsent
modifier|*
modifier|*
name|fts_array
decl_stmt|;
comment|/* sort array */
name|dev_t
name|sdev
decl_stmt|;
comment|/* starting device # */
name|char
modifier|*
name|fts_path
decl_stmt|;
comment|/* path for this descent */
name|char
modifier|*
name|fts_wd
decl_stmt|;
comment|/* starting directory */
name|int
name|fts_pathlen
decl_stmt|;
comment|/* sizeof(path) */
name|int
name|fts_nitems
decl_stmt|;
comment|/* elements in the sort array */
name|int
function_decl|(
modifier|*
name|fts_compar
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
define|#
directive|define
name|FTS_XDEV
value|0x080
comment|/* user: don't cross devices */
name|int
name|fts_options
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
name|fts_parent
decl_stmt|;
comment|/* parent directory */
name|struct
name|ftsent
modifier|*
name|fts_link
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
name|fts_local
union|;
name|char
modifier|*
name|fts_accpath
decl_stmt|;
comment|/* path from current directory */
name|char
modifier|*
name|fts_path
decl_stmt|;
comment|/* path from starting directory */
name|short
name|fts_pathlen
decl_stmt|;
comment|/* strlen(path) */
name|short
name|fts_namelen
decl_stmt|;
comment|/* strlen(name) */
name|short
name|fts_level
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
name|fts_info
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
name|fts_instr
decl_stmt|;
comment|/* setfts() instructions */
name|struct
name|stat
name|fts_statb
decl_stmt|;
comment|/* stat(2) information */
name|char
name|fts_name
index|[
literal|1
index|]
decl_stmt|;
comment|/* file name */
block|}
name|FTSENT
typedef|;
end_typedef

begin_ifdef
ifdef|#
directive|ifdef
name|__STDC__
end_ifdef

begin_decl_stmt
specifier|extern
name|FTS
modifier|*
name|ftsopen
argument_list|(
specifier|const
name|char
operator|*
operator|*
argument_list|,
name|int
argument_list|,
name|int
argument_list|(
operator|*
argument_list|)
argument_list|(
specifier|const
name|FTSENT
operator|*
argument_list|,
specifier|const
name|FTSENT
operator|*
argument_list|)
argument_list|;
specifier|extern
name|FTSENT
operator|*
name|ftsread
argument_list|(
name|FTS
operator|*
argument_list|)
argument_list|;
specifier|extern
name|FTSENT
operator|*
name|ftschildren
argument_list|(
name|FTS
operator|*
argument_list|)
argument_list|;
specifier|extern
name|int
name|ftsset
argument_list|(
name|FTS
operator|*
argument_list|,
name|FTSENT
operator|*
argument_list|,
name|int
argument_list|)
argument_list|;
specifier|extern
name|int
name|ftsclose
argument_list|(
name|FTS
operator|*
argument_list|)
argument_list|;
else|#
directive|else
specifier|extern
name|FTS
operator|*
name|ftsopen
argument_list|()
argument_list|;
specifier|extern
name|FTSENT
operator|*
name|ftschildren
argument_list|()
argument_list|,
operator|*
name|ftsread
argument_list|()
argument_list|;
specifier|extern
name|int
name|ftsclose
argument_list|()
argument_list|,
name|ftsset
argument_list|()
argument_list|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

