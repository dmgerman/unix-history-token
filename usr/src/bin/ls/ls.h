begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1989 The Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Michael Fischbein. %copyright%  *	@(#)ls.h	5.9 (Berkeley) %G%  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_lsstruct
block|{
name|char
modifier|*
name|name
decl_stmt|;
comment|/* file name */
name|int
name|len
decl_stmt|;
comment|/* file name length */
name|struct
name|stat
name|lstat
decl_stmt|;
comment|/* lstat(2) for file */
block|}
name|LS
typedef|;
end_typedef

begin_comment
comment|/*  * overload -- we probably have to save blocks and/or maxlen with the lstat  * array, so tabdir() stuffs it into unused fields in the first stat structure.  * If there's ever a type larger than u_long, fix this.  Any calls to qsort  * must save and restore the values.  */
end_comment

begin_define
define|#
directive|define
name|st_btotal
value|st_flags
end_define

begin_define
define|#
directive|define
name|st_maxlen
value|st_gen
end_define

begin_decl_stmt
specifier|extern
name|int
name|errno
decl_stmt|;
end_decl_stmt

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
name|f_group
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* show group ownership of a file */
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
name|f_kblocks
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* print size in kilobytes */
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
name|f_singlecol
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* use single column output */
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
name|f_total
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* if precede with "total" line */
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

end_unit

