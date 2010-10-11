begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|///////////////////////////////////////////////////////////////////////////////
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|/// \file       tuklib_mstr_fw.c
end_comment

begin_comment
comment|/// \brief      Get the field width for printf() e.g. to align table columns
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//  Author:     Lasse Collin
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//  This file has been put into the public domain.
end_comment

begin_comment
comment|//  You can do whatever you want with this file.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|///////////////////////////////////////////////////////////////////////////////
end_comment

begin_include
include|#
directive|include
file|"tuklib_mbstr.h"
end_include

begin_function
specifier|extern
name|int
name|tuklib_mbstr_fw
parameter_list|(
specifier|const
name|char
modifier|*
name|str
parameter_list|,
name|int
name|columns_min
parameter_list|)
block|{
name|size_t
name|len
decl_stmt|;
specifier|const
name|size_t
name|width
init|=
name|tuklib_mbstr_width
argument_list|(
name|str
argument_list|,
operator|&
name|len
argument_list|)
decl_stmt|;
if|if
condition|(
name|width
operator|==
operator|(
name|size_t
operator|)
operator|-
literal|1
condition|)
return|return
operator|-
literal|1
return|;
if|if
condition|(
name|width
operator|>
operator|(
name|size_t
operator|)
name|columns_min
condition|)
return|return
literal|0
return|;
if|if
condition|(
name|width
operator|<
operator|(
name|size_t
operator|)
name|columns_min
condition|)
name|len
operator|+=
operator|(
name|size_t
operator|)
name|columns_min
operator|-
name|width
expr_stmt|;
return|return
name|len
return|;
block|}
end_function

end_unit

