begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* m_gmprot.c - return the msg-protect value */
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

begin_macro
name|m_gmprot
argument_list|()
end_macro

begin_block
block|{
specifier|register
name|char
modifier|*
name|cp
decl_stmt|;
return|return
name|atooi
argument_list|(
operator|(
name|cp
operator|=
name|m_find
argument_list|(
literal|"msg-protect"
argument_list|)
operator|)
operator|&&
operator|*
name|cp
condition|?
name|cp
else|:
name|msgprot
argument_list|)
return|;
block|}
end_block

end_unit

