begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|///////////////////////////////////////////////////////////////////////////////
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|/// \file       tuklib_mstr_width.c
end_comment

begin_comment
comment|/// \brief      Calculate width of a multibyte string
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

begin_if
if|#
directive|if
name|defined
argument_list|(
name|HAVE_MBRTOWC
argument_list|)
operator|&&
name|defined
argument_list|(
name|HAVE_WCWIDTH
argument_list|)
end_if

begin_include
include|#
directive|include
file|<wchar.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_function
specifier|extern
name|size_t
name|tuklib_mbstr_width
parameter_list|(
specifier|const
name|char
modifier|*
name|str
parameter_list|,
name|size_t
modifier|*
name|bytes
parameter_list|)
block|{
specifier|const
name|size_t
name|len
init|=
name|strlen
argument_list|(
name|str
argument_list|)
decl_stmt|;
if|if
condition|(
name|bytes
operator|!=
name|NULL
condition|)
operator|*
name|bytes
operator|=
name|len
expr_stmt|;
if|#
directive|if
operator|!
operator|(
name|defined
argument_list|(
name|HAVE_MBRTOWC
argument_list|)
operator|&&
name|defined
argument_list|(
name|HAVE_WCWIDTH
argument_list|)
operator|)
comment|// In single-byte mode, the width of the string is the same
comment|// as its length.
return|return
name|len
return|;
else|#
directive|else
name|mbstate_t
name|state
decl_stmt|;
name|memset
argument_list|(
operator|&
name|state
argument_list|,
literal|0
argument_list|,
sizeof|sizeof
argument_list|(
name|state
argument_list|)
argument_list|)
expr_stmt|;
name|size_t
name|width
init|=
literal|0
decl_stmt|;
name|size_t
name|i
init|=
literal|0
decl_stmt|;
comment|// Convert one multibyte character at a time to wchar_t
comment|// and get its width using wcwidth().
while|while
condition|(
name|i
operator|<
name|len
condition|)
block|{
name|wchar_t
name|wc
decl_stmt|;
specifier|const
name|size_t
name|ret
init|=
name|mbrtowc
argument_list|(
operator|&
name|wc
argument_list|,
name|str
operator|+
name|i
argument_list|,
name|len
operator|-
name|i
argument_list|,
operator|&
name|state
argument_list|)
decl_stmt|;
if|if
condition|(
name|ret
operator|<
literal|1
operator|||
name|ret
operator|>
name|len
condition|)
return|return
operator|(
name|size_t
operator|)
operator|-
literal|1
return|;
name|i
operator|+=
name|ret
expr_stmt|;
specifier|const
name|int
name|wc_width
init|=
name|wcwidth
argument_list|(
name|wc
argument_list|)
decl_stmt|;
if|if
condition|(
name|wc_width
operator|<
literal|0
condition|)
return|return
operator|(
name|size_t
operator|)
operator|-
literal|1
return|;
name|width
operator|+=
name|wc_width
expr_stmt|;
block|}
comment|// Require that the string ends in the initial shift state.
comment|// This way the caller can be combine the string with other
comment|// strings without needing to worry about the shift states.
if|if
condition|(
operator|!
name|mbsinit
argument_list|(
operator|&
name|state
argument_list|)
condition|)
return|return
operator|(
name|size_t
operator|)
operator|-
literal|1
return|;
return|return
name|width
return|;
endif|#
directive|endif
block|}
end_function

end_unit

