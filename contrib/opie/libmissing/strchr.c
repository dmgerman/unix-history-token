begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* strchr.c: A replacement for the strchr function  %%% copyright-cmetz This software is Copyright 1996 by Craig Metz, All Rights Reserved. The Inner Net License Version 2 applies to this software. You should have received a copy of the license with this software. If you didn't get a copy, you may request one from<license@inner.net>.          History:  	Created by cmetz for OPIE 2.3. */
end_comment

begin_include
include|#
directive|include
file|"opie_cfg.h"
end_include

begin_include
include|#
directive|include
file|"opie.h"
end_include

begin_decl_stmt
name|char
modifier|*
name|strchr
name|FUNCTION
argument_list|(
operator|(
name|s
operator|,
name|c
operator|)
argument_list|,
name|char
operator|*
name|s
name|AND
name|int
name|c
argument_list|)
block|{
if|#
directive|if
name|HAVE_INDEX
return|return
name|index
argument_list|(
name|s
argument_list|,
name|c
argument_list|)
return|;
else|#
directive|else
comment|/* HAVE_INDEX */
while|while
condition|(
operator|*
name|s
operator|&&
operator|(
operator|*
name|s
operator|!=
name|c
operator|)
condition|)
name|s
operator|++
expr_stmt|;
return|return
operator|*
name|s
condition|?
name|s
else|:
operator|(
name|char
operator|*
operator|)
literal|0
return|;
endif|#
directive|endif
comment|/* HAVE_INDEX */
block|}
end_decl_stmt

end_unit

