begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Mach Operating System  * Copyright (c) 1992, 1991 Carnegie Mellon University  * All Rights Reserved.  *   * Permission to use, copy, modify and distribute this software and its  * documentation is hereby granted, provided that both the copyright  * notice and this permission notice appear in all copies of the  * software, derivative works or modified versions, and any portions  * thereof, and that both notices appear in supporting documentation.  *   * CARNEGIE MELLON ALLOWS FREE USE OF THIS SOFTWARE IN ITS "AS IS"  * CONDITION.  CARNEGIE MELLON DISCLAIMS ANY LIABILITY OF ANY KIND FOR  * ANY DAMAGES WHATSOEVER RESULTING FROM THE USE OF THIS SOFTWARE.  *   * Carnegie Mellon requests users of this software to return to  *   *  Software Distribution Coordinator  or  Software.Distribution@CS.CMU.EDU  *  School of Computer Science  *  Carnegie Mellon University  *  Pittsburgh PA 15213-3890  *   * any improvements or extensions that they make and grant Carnegie Mellon  * the rights to redistribute these changes.  *  *	from: Mach, Revision 2.2  92/04/04  11:35:03  rpd  * $FreeBSD$  */
end_comment

begin_include
include|#
directive|include
file|"types.h"
end_include

begin_include
include|#
directive|include
file|"param.h"
end_include

begin_include
include|#
directive|include
file|"quota.h"
end_include

begin_include
include|#
directive|include
file|"fs.h"
end_include

begin_include
include|#
directive|include
file|"inode.h"
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
name|long
name|dosdev
decl_stmt|,
name|slice
decl_stmt|,
name|unit
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

begin_function_decl
specifier|extern
name|void
name|bsdboot
parameter_list|(
name|int
name|d
parameter_list|,
name|long
name|howto
parameter_list|,
name|char
modifier|*
name|kernel
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|pbzero
parameter_list|(
name|unsigned
name|long
name|addr
parameter_list|,
name|unsigned
name|long
name|size
parameter_list|)
function_decl|;
end_function_decl

end_unit

