begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1989 The Regents of the University of California.  * All rights reserved.  *  * Redistribution and use in source and binary forms are permitted  * provided that the above copyright notice and this paragraph are  * duplicated in all such forms and that any documentation,  * advertising materials, and other materials related to such  * distribution and use acknowledge that the software was developed  * by the University of California, Berkeley.  The name of the  * University may not be used to endorse or promote products derived  * from this software without specific prior written permission.  * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED  * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.  *  *	@(#)ls.h	5.1 (Berkeley) %G%  */
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
comment|/* flags */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|f_listdot
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* list files beginning with . */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|f_listalldot
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* list . and .. as well */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|f_modtime
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* use time of last change for time */
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
name|f_statustime
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* use time of last mode change */
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
name|f_listdir
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* list actual directory, not contents */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|f_specialdir
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* force operands to be directories */
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
name|f_longform
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* long listing format */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|f_nonprint
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* show unprintables as ? */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|f_reversesort
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* reverse whatever sort is used */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|f_recursive
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* ls subdirectories also */
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
name|f_timesort
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* sort by time vice name */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|f_firsttime
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* to control recursion */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|errno
decl_stmt|;
end_decl_stmt

end_unit

