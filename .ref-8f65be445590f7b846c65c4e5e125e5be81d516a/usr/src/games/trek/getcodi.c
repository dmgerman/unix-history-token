begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1980 Regents of the University of California.  * All rights reserved.  *  * %sccs.include.redist.c%  */
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
literal|"@(#)getcodi.c	5.4 (Berkeley) %G%"
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
file|"getpar.h"
end_include

begin_comment
comment|/* **  get course and distance ** **	The user is asked for a course and distance.  This is used by **	move, impulse, and some of the computer functions. ** **	The return value is zero for success, one for an invalid input **	(meaning to drop the request). */
end_comment

begin_macro
name|getcodi
argument_list|(
argument|co
argument_list|,
argument|di
argument_list|)
end_macro

begin_decl_stmt
name|int
modifier|*
name|co
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|double
modifier|*
name|di
decl_stmt|;
end_decl_stmt

begin_block
block|{
operator|*
name|co
operator|=
name|getintpar
argument_list|(
literal|"Course"
argument_list|)
expr_stmt|;
comment|/* course must be in the interval [0, 360] */
if|if
condition|(
operator|*
name|co
operator|<
literal|0
operator|||
operator|*
name|co
operator|>
literal|360
condition|)
return|return
operator|(
literal|1
operator|)
return|;
operator|*
name|di
operator|=
name|getfltpar
argument_list|(
literal|"Distance"
argument_list|)
expr_stmt|;
comment|/* distance must be in the interval [0, 15] */
if|if
condition|(
operator|*
name|di
operator|<=
literal|0.0
operator|||
operator|*
name|di
operator|>
literal|15.0
condition|)
return|return
operator|(
literal|1
operator|)
return|;
comment|/* good return */
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_block

end_unit

