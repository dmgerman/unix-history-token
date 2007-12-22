begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  *  Top users/processes display for Unix  *  Version 3  *  *  This program may be freely redistributed,  *  but this entire comment MUST remain intact.  *  *  Copyright (c) 1984, 1989, William LeFebvre, Rice University  *  Copyright (c) 1989, 1990, 1992, William LeFebvre, Northwestern University  */
end_comment

begin_include
include|#
directive|include
file|"top.h"
end_include

begin_include
include|#
directive|include
file|"patchlevel.h"
end_include

begin_decl_stmt
specifier|static
name|char
name|version
index|[
literal|16
index|]
decl_stmt|;
end_decl_stmt

begin_function
name|char
modifier|*
name|version_string
parameter_list|()
block|{
name|sprintf
argument_list|(
name|version
argument_list|,
literal|"%d.%d"
argument_list|,
name|VERSION
argument_list|,
name|PATCHLEVEL
argument_list|)
expr_stmt|;
ifdef|#
directive|ifdef
name|BETA
name|strcat
argument_list|(
name|version
argument_list|,
name|BETA
argument_list|)
expr_stmt|;
endif|#
directive|endif
return|return
operator|(
name|version
operator|)
return|;
block|}
end_function

end_unit

