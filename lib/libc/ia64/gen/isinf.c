begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$NetBSD: isinf.c,v 1.1 1995/02/10 17:50:23 cgd Exp $	*/
end_comment

begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_comment
comment|/*  * Copyright (c) 1994, 1995 Carnegie-Mellon University.  * All rights reserved.  *  * Author: Chris G. Demetriou  *   * Permission to use, copy, modify and distribute this software and  * its documentation is hereby granted, provided that both the copyright  * notice and this permission notice appear in all copies of the  * software, derivative works or modified versions, and any portions  * thereof, and that both notices appear in supporting documentation.  *   * CARNEGIE MELLON ALLOWS FREE USE OF THIS SOFTWARE IN ITS "AS IS"   * CONDITION.  CARNEGIE MELLON DISCLAIMS ANY LIABILITY OF ANY KIND   * FOR ANY DAMAGES WHATSOEVER RESULTING FROM THE USE OF THIS SOFTWARE.  *   * Carnegie Mellon requests users of this software to return to  *  *  Software Distribution Coordinator  or  Software.Distribution@CS.CMU.EDU  *  School of Computer Science  *  Carnegie Mellon University  *  Pittsburgh PA 15213-3890  *  * any improvements or extensions that they make and grant Carnegie the  * rights to redistribute these changes.  */
end_comment

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<machine/ieee.h>
end_include

begin_include
include|#
directive|include
file|<math.h>
end_include

begin_function
name|int
name|isnan
parameter_list|(
name|d
parameter_list|)
name|double
name|d
decl_stmt|;
block|{
name|struct
name|ieee_double
modifier|*
name|p
init|=
operator|(
expr|struct
name|ieee_double
operator|*
operator|)
operator|&
name|d
decl_stmt|;
return|return
operator|(
name|p
operator|->
name|dbl_exp
operator|==
name|DBL_EXP_INFNAN
operator|&&
operator|(
name|p
operator|->
name|dbl_frach
operator|||
name|p
operator|->
name|dbl_fracl
operator|)
operator|)
return|;
block|}
end_function

begin_function
name|int
name|isinf
parameter_list|(
name|d
parameter_list|)
name|double
name|d
decl_stmt|;
block|{
name|struct
name|ieee_double
modifier|*
name|p
init|=
operator|(
expr|struct
name|ieee_double
operator|*
operator|)
operator|&
name|d
decl_stmt|;
return|return
operator|(
name|p
operator|->
name|dbl_exp
operator|==
name|DBL_EXP_INFNAN
operator|&&
operator|!
name|p
operator|->
name|dbl_frach
operator|&&
operator|!
name|p
operator|->
name|dbl_fracl
operator|)
return|;
block|}
end_function

end_unit

