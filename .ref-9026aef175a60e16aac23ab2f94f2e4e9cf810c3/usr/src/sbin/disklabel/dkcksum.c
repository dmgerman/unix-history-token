begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1991, 1993  *	The Regents of the University of California.  All rights reserved.  *  * %sccs.include.redist.c%  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|lint
end_ifndef

begin_decl_stmt
specifier|static
name|char
name|sccsid
index|[]
init|=
literal|"@(#)dkcksum.c	8.1 (Berkeley) %G%"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not lint */
end_comment

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<sys/disklabel.h>
end_include

begin_function
name|u_short
name|dkcksum
parameter_list|(
name|lp
parameter_list|)
specifier|register
name|struct
name|disklabel
modifier|*
name|lp
decl_stmt|;
block|{
specifier|register
name|u_short
modifier|*
name|start
decl_stmt|,
modifier|*
name|end
decl_stmt|;
specifier|register
name|u_short
name|sum
init|=
literal|0
decl_stmt|;
name|start
operator|=
operator|(
name|u_short
operator|*
operator|)
name|lp
expr_stmt|;
name|end
operator|=
operator|(
name|u_short
operator|*
operator|)
operator|&
name|lp
operator|->
name|d_partitions
index|[
name|lp
operator|->
name|d_npartitions
index|]
expr_stmt|;
while|while
condition|(
name|start
operator|<
name|end
condition|)
name|sum
operator|^=
operator|*
name|start
operator|++
expr_stmt|;
return|return
operator|(
name|sum
operator|)
return|;
block|}
end_function

end_unit

