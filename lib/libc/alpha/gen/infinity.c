begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1994, 1995 Carnegie-Mellon University.  * All rights reserved.  *  * Author: Chris G. Demetriou  *   * Permission to use, copy, modify and distribute this software and  * its documentation is hereby granted, provided that both the copyright  * notice and this permission notice appear in all copies of the  * software, derivative works or modified versions, and any portions  * thereof, and that both notices appear in supporting documentation.  *   * CARNEGIE MELLON ALLOWS FREE USE OF THIS SOFTWARE IN ITS "AS IS"   * CONDITION.  CARNEGIE MELLON DISCLAIMS ANY LIABILITY OF ANY KIND   * FOR ANY DAMAGES WHATSOEVER RESULTING FROM THE USE OF THIS SOFTWARE.  *   * Carnegie Mellon requests users of this software to return to  *  *  Software Distribution Coordinator  or  Software.Distribution@CS.CMU.EDU  *  School of Computer Science  *  Carnegie Mellon University  *  Pittsburgh PA 15213-3890  *  * any improvements or extensions that they make and grant Carnegie the  * rights to redistribute these changes.  *  *	$NetBSD: infinity.c,v 1.1 1995/02/10 17:50:23 cgd Exp $  */
end_comment

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_expr_stmt
name|__FBSDID
argument_list|(
literal|"$FreeBSD$"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_include
include|#
directive|include
file|<math.h>
end_include

begin_comment
comment|/* bytes for +Infinity on an Alpha (IEEE double format) */
end_comment

begin_decl_stmt
specifier|const
name|union
name|__infinity_un
name|__infinity
init|=
block|{
block|{
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0xf0
block|,
literal|0x7f
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* bytes for NaN */
end_comment

begin_decl_stmt
specifier|const
name|union
name|__nan_un
name|__nan
init|=
block|{
block|{
literal|0
block|,
literal|0
block|,
literal|0xc0
block|,
literal|0xff
block|}
block|}
decl_stmt|;
end_decl_stmt

end_unit

