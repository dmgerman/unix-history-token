begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1988, 1989, 1990 The Regents of the University of California.  * Copyright (c) 1988, 1989 by Adam de Boor  * Copyright (c) 1989 by Berkeley Softworks  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Adam de Boor.  *  * %sccs.include.redist.c%  *  *	@(#)config.h	5.9 (Berkeley) %G%  */
end_comment

begin_define
define|#
directive|define
name|DEFSHELL
value|1
end_define

begin_comment
comment|/* Bourne shell */
end_comment

begin_comment
comment|/*  * DEFMAXJOBS  * DEFMAXLOCAL  *	These control the default concurrency. On no occasion will more  *	than DEFMAXJOBS targets be created at once (locally or remotely)  *	DEFMAXLOCAL is the highest number of targets which will be  *	created on the local machine at once. Note that if you set this  *	to 0, nothing will ever happen...  */
end_comment

begin_define
define|#
directive|define
name|DEFMAXJOBS
value|4
end_define

begin_define
define|#
directive|define
name|DEFMAXLOCAL
value|1
end_define

begin_comment
comment|/*  * INCLUDES  * LIBRARIES  *	These control the handling of the .INCLUDES and .LIBS variables.  *	If INCLUDES is defined, the .INCLUDES variable will be filled  *	from the search paths of those suffixes which are marked by  *	.INCLUDES dependency lines. Similarly for LIBRARIES and .LIBS  *	See suff.c for more details.  */
end_comment

begin_define
define|#
directive|define
name|INCLUDES
end_define

begin_define
define|#
directive|define
name|LIBRARIES
end_define

begin_comment
comment|/*  * LIBSUFF  *	Is the suffix used to denote libraries and is used by the Suff module  *	to find the search path on which to seek any -l<xx> targets.  *  * RECHECK  *	If defined, Make_Update will check a target for its current  *	modification time after it has been re-made, setting it to the  *	starting time of the make only if the target still doesn't exist.  *	Unfortunately, under NFS the modification time often doesn't  *	get updated in time, so a target will appear to not have been  *	re-made, causing later targets to appear up-to-date. On systems  *	that don't have this problem, you should defined this. Under  *	NFS you probably should not, unless you aren't exporting jobs.  *  * POSIX  *	If the POSIX standard for Make is to be followed. There are  *	several areas that I dislike, hence this constant.  */
end_comment

begin_define
define|#
directive|define
name|LIBSUFF
value|".a"
end_define

begin_define
define|#
directive|define
name|RECHECK
end_define

begin_comment
comment|/*#define POSIX*/
end_comment

end_unit

