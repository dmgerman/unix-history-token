begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* ==== pthread_attr.c =======================================================  * Copyright (c) 1993 by Chris Provenzano, proven@athena.mit.edu  *  * Description : Pthread attribute functions.  *  *  1.00 93/11/04 proven  *      -Started coding this file.  */
end_comment

begin_include
include|#
directive|include
file|<pthread/copyright.h>
end_include

begin_include
include|#
directive|include
file|"pthread.h"
end_include

begin_include
include|#
directive|include
file|<errno.h>
end_include

begin_comment
comment|/* Currently we do no locking, should we just to be safe? CAP */
end_comment

begin_comment
comment|/* ==========================================================================  * pthread_attr_init()  */
end_comment

begin_function
name|int
name|pthread_attr_init
parameter_list|(
name|pthread_attr_t
modifier|*
name|attr
parameter_list|)
block|{
name|memcpy
argument_list|(
name|attr
argument_list|,
operator|&
name|pthread_default_attr
argument_list|,
sizeof|sizeof
argument_list|(
name|pthread_attr_t
argument_list|)
argument_list|)
expr_stmt|;
return|return
operator|(
name|OK
operator|)
return|;
block|}
end_function

begin_comment
comment|/* ==========================================================================  * pthread_attr_destroy()  */
end_comment

begin_function
name|int
name|pthread_attr_destroy
parameter_list|(
name|pthread_attr_t
modifier|*
name|attr
parameter_list|)
block|{
return|return
operator|(
name|OK
operator|)
return|;
block|}
end_function

begin_comment
comment|/* ==========================================================================  * pthread_attr_getstacksize()  */
end_comment

begin_function
name|int
name|pthread_attr_getstacksize
parameter_list|(
name|pthread_attr_t
modifier|*
name|attr
parameter_list|,
name|size_t
modifier|*
name|stacksize
parameter_list|)
block|{
operator|*
name|stacksize
operator|=
name|attr
operator|->
name|stacksize_attr
expr_stmt|;
return|return
operator|(
name|OK
operator|)
return|;
block|}
end_function

begin_comment
comment|/* ==========================================================================  * pthread_attr_setstacksize()  */
end_comment

begin_function
name|int
name|pthread_attr_setstacksize
parameter_list|(
name|pthread_attr_t
modifier|*
name|attr
parameter_list|,
name|size_t
name|stacksize
parameter_list|)
block|{
if|if
condition|(
name|stacksize
operator|>=
name|PTHREAD_STACK_MIN
condition|)
block|{
name|attr
operator|->
name|stacksize_attr
operator|=
name|stacksize
expr_stmt|;
return|return
operator|(
name|OK
operator|)
return|;
block|}
return|return
operator|(
name|EINVAL
operator|)
return|;
block|}
end_function

begin_comment
comment|/* ==========================================================================  * pthread_attr_getstackaddr()  */
end_comment

begin_function
name|int
name|pthread_attr_getstackaddr
parameter_list|(
name|pthread_attr_t
modifier|*
name|attr
parameter_list|,
name|void
modifier|*
modifier|*
name|stackaddr
parameter_list|)
block|{
operator|*
name|stackaddr
operator|=
name|attr
operator|->
name|stackaddr_attr
expr_stmt|;
return|return
operator|(
name|OK
operator|)
return|;
block|}
end_function

begin_comment
comment|/* ==========================================================================  * pthread_attr_setstackaddr()  */
end_comment

begin_function
name|int
name|pthread_attr_setstackaddr
parameter_list|(
name|pthread_attr_t
modifier|*
name|attr
parameter_list|,
name|void
modifier|*
name|stackaddr
parameter_list|)
block|{
name|attr
operator|->
name|stackaddr_attr
operator|=
name|stackaddr
expr_stmt|;
return|return
operator|(
name|OK
operator|)
return|;
block|}
end_function

end_unit

