begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $Header$ */
end_comment

begin_comment
comment|/*  * Author: Peter J. Nicklin  */
end_comment

begin_comment
comment|/*  * xorpath() strips pathname p1 from pathname p2 if p1 is a leading  * component of pathname p2. Returns p2.  */
end_comment

begin_include
include|#
directive|include
file|"path.h"
end_include

begin_function
name|char
modifier|*
name|xorpath
parameter_list|(
name|p1
parameter_list|,
name|p2
parameter_list|)
specifier|register
name|char
modifier|*
name|p1
decl_stmt|;
comment|/* subpathname */
specifier|register
name|char
modifier|*
name|p2
decl_stmt|;
comment|/* pathname */
block|{
name|char
modifier|*
name|sp2
decl_stmt|;
comment|/* start of pathname */
name|sp2
operator|=
name|p2
expr_stmt|;
for|for
control|(
init|;
operator|*
name|p1
operator|==
operator|*
name|p2
condition|;
name|p1
operator|++
operator|,
name|p2
operator|++
control|)
if|if
condition|(
operator|*
name|p1
operator|==
literal|'\0'
condition|)
break|break;
if|if
condition|(
operator|*
name|p1
operator|==
literal|'\0'
condition|)
return|return
operator|(
operator|(
operator|*
name|p2
operator|==
name|_PSC
operator|)
condition|?
operator|++
name|p2
else|:
name|p2
operator|)
return|;
else|else
return|return
operator|(
name|sp2
operator|)
return|;
block|}
end_function

end_unit

