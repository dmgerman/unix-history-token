begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1989, 1993  *	The Regents of the University of California.  All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Michael Fischbein.  *  * %sccs.include.redist.c%  *  *	@(#)ls.h	8.1 (Berkeley) %G%  */
end_comment

begin_define
define|#
directive|define
name|NO_PRINT
value|1
end_define

begin_decl_stmt
specifier|extern
name|long
name|blocksize
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* block size units */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|f_accesstime
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* use time of last access */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|f_flags
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* show flags associated with a file */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|f_inode
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* print inode */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|f_longform
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* long listing format */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|f_sectime
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* print the real time for all files */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|f_size
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* list size in short listing */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|f_statustime
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* use time of last mode change */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|f_type
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* add type character for non-regular files */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|FTSENT
modifier|*
name|list
decl_stmt|;
name|u_long
name|btotal
decl_stmt|;
name|int
name|bcfile
decl_stmt|;
name|int
name|entries
decl_stmt|;
name|int
name|maxlen
decl_stmt|;
name|int
name|s_block
decl_stmt|;
name|int
name|s_flags
decl_stmt|;
name|int
name|s_group
decl_stmt|;
name|int
name|s_inode
decl_stmt|;
name|int
name|s_nlink
decl_stmt|;
name|int
name|s_size
decl_stmt|;
name|int
name|s_user
decl_stmt|;
block|}
name|DISPLAY
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|char
modifier|*
name|user
decl_stmt|;
name|char
modifier|*
name|group
decl_stmt|;
name|char
modifier|*
name|flags
decl_stmt|;
name|char
name|data
index|[
literal|1
index|]
decl_stmt|;
block|}
name|NAMES
typedef|;
end_typedef

end_unit

