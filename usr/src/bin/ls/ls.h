begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1989 The Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Michael Fischbein.  *  * %sccs.include.redist.c%  *  *	@(#)ls.h	5.14 (Berkeley) %G%  */
end_comment

begin_comment
comment|/*  * Specify maximum width of flags output. Determined from flags_from_fid  * routine in print.c  */
end_comment

begin_define
define|#
directive|define
name|FLAGSWIDTH
value|10
end_define

begin_define
define|#
directive|define
name|NO_PRINT
value|1
end_define

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
name|f_sectime
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* print the real time for all files */
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

