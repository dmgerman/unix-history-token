begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1980 The Regents of the University of California.  * All rights reserved.  *  * %sccs.include.proprietary.c%  */
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
literal|"@(#)idate_.c	5.2 (Berkeley) %G%"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not lint */
end_comment

begin_comment
comment|/*  * return date in numerical form  *  * calling sequence:  *	integer iarray(3)  *	call idate(iarray)  * where:  *	iarray will receive the current date; day, mon, year.  */
end_comment

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<sys/time.h>
end_include

begin_macro
name|idate_
argument_list|(
argument|iar
argument_list|)
end_macro

begin_struct
struct|struct
block|{
name|long
name|iday
decl_stmt|;
name|long
name|imon
decl_stmt|;
name|long
name|iyer
decl_stmt|;
block|}
modifier|*
name|iar
struct|;
end_struct

begin_block
block|{
name|struct
name|tm
modifier|*
name|localtime
argument_list|()
decl_stmt|,
modifier|*
name|lclt
decl_stmt|;
name|long
name|int
name|time
argument_list|()
decl_stmt|,
name|t
decl_stmt|;
name|t
operator|=
name|time
argument_list|(
literal|0
argument_list|)
expr_stmt|;
name|lclt
operator|=
name|localtime
argument_list|(
operator|&
name|t
argument_list|)
expr_stmt|;
name|iar
operator|->
name|iday
operator|=
name|lclt
operator|->
name|tm_mday
expr_stmt|;
name|iar
operator|->
name|imon
operator|=
name|lclt
operator|->
name|tm_mon
operator|+
literal|1
expr_stmt|;
name|iar
operator|->
name|iyer
operator|=
name|lclt
operator|->
name|tm_year
operator|+
literal|1900
expr_stmt|;
block|}
end_block

end_unit

