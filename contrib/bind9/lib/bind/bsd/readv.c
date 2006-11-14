begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_ifndef
ifndef|#
directive|ifndef
name|LINT
end_ifndef

begin_decl_stmt
specifier|static
specifier|const
name|char
name|rcsid
index|[]
init|=
literal|"$Id: readv.c,v 1.1 2001/03/29 06:30:35 marka Exp $"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|"port_before.h"
end_include

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<sys/uio.h>
end_include

begin_include
include|#
directive|include
file|<sys/stat.h>
end_include

begin_include
include|#
directive|include
file|<sys/socket.h>
end_include

begin_include
include|#
directive|include
file|"port_after.h"
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|NEED_READV
end_ifndef

begin_decl_stmt
name|int
name|__bindcompat_readv
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_function
name|int
name|__readv
parameter_list|(
name|fd
parameter_list|,
name|vp
parameter_list|,
name|vpcount
parameter_list|)
name|int
name|fd
decl_stmt|;
specifier|const
name|struct
name|iovec
modifier|*
name|vp
decl_stmt|;
name|int
name|vpcount
decl_stmt|;
block|{
name|int
name|count
init|=
literal|0
decl_stmt|;
while|while
condition|(
name|vpcount
operator|--
operator|>
literal|0
condition|)
block|{
name|int
name|bytes
init|=
name|read
argument_list|(
name|fd
argument_list|,
name|vp
operator|->
name|iov_base
argument_list|,
name|vp
operator|->
name|iov_len
argument_list|)
decl_stmt|;
if|if
condition|(
name|bytes
operator|<
literal|0
condition|)
return|return
operator|(
operator|-
literal|1
operator|)
return|;
name|count
operator|+=
name|bytes
expr_stmt|;
if|if
condition|(
name|bytes
operator|!=
name|vp
operator|->
name|iov_len
condition|)
break|break;
name|vp
operator|++
expr_stmt|;
block|}
return|return
operator|(
name|count
operator|)
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* NEED_READV */
end_comment

end_unit

