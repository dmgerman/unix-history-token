begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  $Revision: 1.1 $ ** */
end_comment

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|"configdata.h"
end_include

begin_include
include|#
directive|include
file|"nntp.h"
end_include

begin_include
include|#
directive|include
file|"clibrary.h"
end_include

begin_comment
comment|/* **  See if an article is longer than the NNTP line-length limits. */
end_comment

begin_function
name|int
name|NNTPcheckarticle
parameter_list|(
name|p
parameter_list|)
specifier|register
name|char
modifier|*
name|p
decl_stmt|;
block|{
specifier|register
name|char
modifier|*
name|next
decl_stmt|;
for|for
control|(
init|;
name|p
operator|&&
operator|*
name|p
condition|;
name|p
operator|=
name|next
control|)
block|{
if|if
condition|(
operator|(
name|next
operator|=
name|strchr
argument_list|(
name|p
argument_list|,
literal|'\n'
argument_list|)
operator|)
operator|==
name|NULL
condition|)
break|break;
if|if
condition|(
name|next
operator|-
name|p
operator|>
name|NNTP_STRLEN
condition|)
return|return
operator|-
literal|1
return|;
block|}
return|return
literal|0
return|;
block|}
end_function

end_unit

