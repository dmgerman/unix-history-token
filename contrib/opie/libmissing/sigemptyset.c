begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* sigemptyset.c: A replacement for the sigemptyset function  %%% copyright-cmetz This software is Copyright 1996 by Craig Metz, All Rights Reserved. The Inner Net License Version 2 applies to this software. You should have received a copy of the license with this software. If you didn't get a copy, you may request one from<license@inner.net>.          History:  	Created by cmetz for OPIE 2.2. */
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
name|int
name|sigemptyset
name|FUNCTION
argument_list|(
operator|(
name|set
operator|)
argument_list|,
name|sigset_t
operator|*
name|set
argument_list|)
block|{
if|if
condition|(
name|set
condition|)
name|memset
argument_list|(
argument|set
argument_list|,
literal|0
argument_list|,
argument|sizeof(sigset_t)
argument_list|)
return|return
literal|0
return|;
block|}
end_decl_stmt

end_unit

