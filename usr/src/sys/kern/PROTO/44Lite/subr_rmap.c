begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1982, 1986, 1993  *	The Regents of the University of California.  All rights reserved.  * (c) UNIX System Laboratories, Inc.  * All or some portions of this file are derived from material licensed  * to the University of California by American Telephone and Telegraph  * Co. or Unix System Laboratories, Inc. and are reproduced herein with  * the permission of UNIX System Laboratories, Inc.  *  * %sccs.include.redist.c%  *  *	from: @(#)subr_rmap.c	8.1 (Berkeley) 6/10/93  */
end_comment

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<sys/map.h>
end_include

begin_include
include|#
directive|include
file|<sys/proc.h>
end_include

begin_function
name|void
name|rminit
parameter_list|(
name|a1
parameter_list|,
name|a2
parameter_list|,
name|a3
parameter_list|,
name|a4
parameter_list|,
name|a5
parameter_list|)
name|struct
name|map
modifier|*
name|a1
decl_stmt|;
name|long
name|a2
decl_stmt|,
name|a3
decl_stmt|;
name|char
modifier|*
name|a4
decl_stmt|;
name|int
name|a5
decl_stmt|;
block|{
comment|/* 	 * Body deleted. 	 */
return|return;
block|}
end_function

begin_function
name|long
name|rmalloc
parameter_list|(
name|a1
parameter_list|,
name|a2
parameter_list|)
name|struct
name|map
modifier|*
name|a1
decl_stmt|;
name|long
name|a2
decl_stmt|;
block|{
comment|/* 	 * Body deleted. 	 */
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_function

begin_function
name|void
name|rmfree
parameter_list|(
name|a1
parameter_list|,
name|a2
parameter_list|,
name|a3
parameter_list|)
name|struct
name|map
modifier|*
name|a1
decl_stmt|;
name|long
name|a2
decl_stmt|,
name|a3
decl_stmt|;
block|{
comment|/* 	 * Body deleted. 	 */
return|return;
block|}
end_function

end_unit

