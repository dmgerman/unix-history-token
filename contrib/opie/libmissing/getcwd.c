begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* getcwd.c: A replacement for the getcwd function  %%% copyright-cmetz This software is Copyright 1996 by Craig Metz, All Rights Reserved. The Inner Net License Version 2 applies to this software. You should have received a copy of the license with this software. If you didn't get a copy, you may request one from<license@inner.net>.          History:  	Created by cmetz for OPIE 2.3. */
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
name|getcwd
name|FUNCTION
argument_list|(
operator|(
name|c
operator|,
name|l
operator|)
argument_list|,
name|char
operator|*
name|c
name|AND
name|int
name|l
argument_list|)
block|{
if|#
directive|if
name|HAVE_GETWD
return|return
name|getwd
argument_list|(
name|c
argument_list|)
return|;
else|#
directive|else
comment|/* HAVE_INDEX */
error|#
directive|error
error|Need getwd() to build a replacement getcwd()
endif|#
directive|endif
comment|/* HAVE_INDEX */
block|}
end_decl_stmt

end_unit

