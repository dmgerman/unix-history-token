begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$NetBSD: rf_strutils.c,v 1.3 1999/02/05 00:06:18 oster Exp $	*/
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

begin_comment
comment|/*  * rf_strutils.c  *  * String-parsing funcs  */
end_comment

begin_comment
comment|/*  * Copyright (c) 1995 Carnegie-Mellon University.  * All rights reserved.  *  * Author: Mark Holland  *  * Permission to use, copy, modify and distribute this software and  * its documentation is hereby granted, provided that both the copyright  * notice and this permission notice appear in all copies of the  * software, derivative works or modified versions, and any portions  * thereof, and that both notices appear in supporting documentation.  *  * CARNEGIE MELLON ALLOWS FREE USE OF THIS SOFTWARE IN ITS "AS IS"  * CONDITION.  CARNEGIE MELLON DISCLAIMS ANY LIABILITY OF ANY KIND  * FOR ANY DAMAGES WHATSOEVER RESULTING FROM THE USE OF THIS SOFTWARE.  *  * Carnegie Mellon requests users of this software to return to  *  *  Software Distribution Coordinator  or  Software.Distribution@CS.CMU.EDU  *  School of Computer Science  *  Carnegie Mellon University  *  Pittsburgh PA 15213-3890  *  * any improvements or extensions that they make and grant Carnegie the  * rights to redistribute these changes.  */
end_comment

begin_comment
comment|/*  * rf_strutils.c -- some simple utilities for munging on strings.  * I put them in a file by themselves because they're needed in  * setconfig, in the user-level driver, and in the kernel.  *  */
end_comment

begin_include
include|#
directive|include
file|<dev/raidframe/rf_utils.h>
end_include

begin_comment
comment|/* finds a non-white character in the line */
end_comment

begin_function
name|char
modifier|*
name|rf_find_non_white
parameter_list|(
name|char
modifier|*
name|p
parameter_list|)
block|{
for|for
control|(
init|;
operator|*
name|p
operator|!=
literal|'\0'
operator|&&
operator|(
operator|*
name|p
operator|==
literal|' '
operator|||
operator|*
name|p
operator|==
literal|'\t'
operator|)
condition|;
name|p
operator|++
control|)
empty_stmt|;
return|return
operator|(
name|p
operator|)
return|;
block|}
end_function

begin_comment
comment|/* finds a white character in the line */
end_comment

begin_function
name|char
modifier|*
name|rf_find_white
parameter_list|(
name|char
modifier|*
name|p
parameter_list|)
block|{
for|for
control|(
init|;
operator|*
name|p
operator|!=
literal|'\0'
operator|&&
operator|(
operator|*
name|p
operator|!=
literal|' '
operator|&&
operator|*
name|p
operator|!=
literal|'\t'
operator|)
condition|;
name|p
operator|++
control|)
empty_stmt|;
return|return
operator|(
name|p
operator|)
return|;
block|}
end_function

end_unit

