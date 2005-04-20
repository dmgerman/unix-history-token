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
literal|"$Id: putenv.c,v 1.1 2001/03/29 06:30:33 marka Exp $"
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
file|"port_after.h"
end_include

begin_comment
comment|/*  * To give a little credit to Sun, SGI,  * and many vendors in the SysV world.  */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|NEED_PUTENV
argument_list|)
end_if

begin_decl_stmt
name|int
name|__bindcompat_putenv
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_function
name|int
name|putenv
parameter_list|(
name|char
modifier|*
name|str
parameter_list|)
block|{
name|char
modifier|*
name|tmp
decl_stmt|;
for|for
control|(
name|tmp
operator|=
name|str
init|;
operator|*
name|tmp
operator|&&
operator|(
operator|*
name|tmp
operator|!=
literal|'='
operator|)
condition|;
name|tmp
operator|++
control|)
empty_stmt|;
return|return
operator|(
name|setenv
argument_list|(
name|str
argument_list|,
name|tmp
argument_list|,
literal|1
argument_list|)
operator|)
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

end_unit

