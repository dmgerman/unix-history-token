begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Mach Operating System  * Copyright (c) 1992, 1991 Carnegie Mellon University  * All Rights Reserved.  *   * Permission to use, copy, modify and distribute this software and its  * documentation is hereby granted, provided that both the copyright  * notice and this permission notice appear in all copies of the  * software, derivative works or modified versions, and any portions  * thereof, and that both notices appear in supporting documentation.  *   * CARNEGIE MELLON ALLOWS FREE USE OF THIS SOFTWARE IN ITS "AS IS"  * CONDITION.  CARNEGIE MELLON DISCLAIMS ANY LIABILITY OF ANY KIND FOR  * ANY DAMAGES WHATSOEVER RESULTING FROM THE USE OF THIS SOFTWARE.  *   * Carnegie Mellon requests users of this software to return to  *   *  Software Distribution Coordinator  or  Software.Distribution@CS.CMU.EDU  *  School of Computer Science  *  Carnegie Mellon University  *  Pittsburgh PA 15213-3890  *   * any improvements or extensions that they make and grant Carnegie Mellon  * the rights to redistribute these changes.  *  *	from: Mach, Revision 2.2  92/04/04  11:35:03  rpd  *	$Id: boot.h,v 1.5 1994/12/18 19:14:15 bde Exp $  */
end_comment

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<sys/time.h>
end_include

begin_include
include|#
directive|include
file|<ufs/ufs/quota.h>
end_include

begin_include
include|#
directive|include
file|<ufs/ffs/fs.h>
end_include

begin_include
include|#
directive|include
file|<ufs/ufs/inode.h>
end_include

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|devs
index|[]
decl_stmt|,
modifier|*
name|name
decl_stmt|,
modifier|*
name|iodest
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|fs
modifier|*
name|fs
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|inode
name|inode
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|dosdev
decl_stmt|,
name|unit
decl_stmt|,
name|slice
decl_stmt|,
name|part
decl_stmt|,
name|maj
decl_stmt|,
name|boff
decl_stmt|,
name|poff
decl_stmt|,
name|bnum
decl_stmt|,
name|cnt
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|unsigned
name|long
name|tw_chars
decl_stmt|;
end_decl_stmt

end_unit

