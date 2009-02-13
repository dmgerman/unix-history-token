begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * CDDL HEADER START  *  * The contents of this file are subject to the terms of the  * Common Development and Distribution License, Version 1.0 only  * (the "License").  You may not use this file except in compliance  * with the License.  *  * You can obtain a copy of the license at usr/src/OPENSOLARIS.LICENSE  * or http://www.opensolaris.org/os/licensing.  * See the License for the specific language governing permissions  * and limitations under the License.  *  * When distributing Covered Code, include this CDDL HEADER in each  * file and include the License file at usr/src/OPENSOLARIS.LICENSE.  * If applicable, add the following below this CDDL HEADER, with the  * fields enclosed by brackets "[]" replaced with your own identifying  * information: Portions Copyright [yyyy] [name of copyright owner]  *  * CDDL HEADER END  */
end_comment

begin_comment
comment|/*  * Copyright 2003 Sun Microsystems, Inc.  All rights reserved.  * Use is subject to license terms.  */
end_comment

begin_pragma
pragma|#
directive|pragma
name|ident
literal|"%Z%%M%	%I%	%E% SMI"
end_pragma

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<sgs.h>
end_include

begin_comment
comment|/*  * function that will find a prime'ish number.  Usefull for  * hashbuckets and related things.  */
end_comment

begin_function
name|uint_t
name|findprime
parameter_list|(
name|uint_t
name|count
parameter_list|)
block|{
name|uint_t
name|h
decl_stmt|,
name|f
decl_stmt|;
if|if
condition|(
name|count
operator|<=
literal|3
condition|)
return|return
operator|(
literal|3
operator|)
return|;
comment|/* 	 * Check to see if divisible by two, if so 	 * increment. 	 */
if|if
condition|(
operator|(
name|count
operator|&
literal|0x1
operator|)
operator|==
literal|0
condition|)
name|count
operator|++
expr_stmt|;
for|for
control|(
name|h
operator|=
name|count
operator|,
name|f
operator|=
literal|2
init|;
name|f
operator|*
name|f
operator|<=
name|h
condition|;
name|f
operator|++
control|)
if|if
condition|(
operator|(
name|h
operator|%
name|f
operator|)
operator|==
literal|0
condition|)
name|h
operator|+=
name|f
operator|=
literal|1
expr_stmt|;
return|return
operator|(
name|h
operator|)
return|;
block|}
end_function

end_unit

