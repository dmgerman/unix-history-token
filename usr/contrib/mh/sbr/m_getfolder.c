begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* m_getfolder.c - get the current folder */
end_comment

begin_include
include|#
directive|include
file|"../h/mh.h"
end_include

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_function
name|char
modifier|*
name|m_getfolder
parameter_list|()
block|{
specifier|register
name|char
modifier|*
name|folder
decl_stmt|;
if|if
condition|(
operator|(
name|folder
operator|=
name|m_find
argument_list|(
name|pfolder
argument_list|)
operator|)
operator|==
name|NULL
operator|||
operator|*
name|folder
operator|==
literal|0
condition|)
name|folder
operator|=
name|defalt
expr_stmt|;
return|return
name|folder
return|;
block|}
end_function

end_unit

