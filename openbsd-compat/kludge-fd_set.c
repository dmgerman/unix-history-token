begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Placed in the public domain.  */
end_comment

begin_comment
comment|/*  * _FORTIFY_SOURCE includes a misguided check for FD_SET(n)/FD_ISSET(b)  * where n> FD_SETSIZE. This breaks OpenSSH and other programs that  * explicitly allocate fd_sets. To avoid this, we wrap FD_SET in a  * function compiled without _FORTIFY_SOURCE.  */
end_comment

begin_include
include|#
directive|include
file|"config.h"
end_include

begin_if
if|#
directive|if
name|defined
argument_list|(
name|HAVE_FEATURES_H
argument_list|)
operator|&&
name|defined
argument_list|(
name|_FORTIFY_SOURCE
argument_list|)
end_if

begin_include
include|#
directive|include
file|<features.h>
end_include

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__GNU_LIBRARY__
argument_list|)
operator|&&
name|defined
argument_list|(
name|__GLIBC_PREREQ
argument_list|)
end_if

begin_if
if|#
directive|if
name|__GLIBC_PREREQ
argument_list|(
literal|2
operator|,
literal|15
argument_list|)
operator|&&
operator|(
name|_FORTIFY_SOURCE
operator|>
literal|0
operator|)
end_if

begin_undef
undef|#
directive|undef
name|_FORTIFY_SOURCE
end_undef

begin_undef
undef|#
directive|undef
name|__USE_FORTIFY_LEVEL
end_undef

begin_include
include|#
directive|include
file|<sys/socket.h>
end_include

begin_function
name|void
name|kludge_FD_SET
parameter_list|(
name|int
name|n
parameter_list|,
name|fd_set
modifier|*
name|set
parameter_list|)
block|{
name|FD_SET
argument_list|(
name|n
argument_list|,
name|set
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
name|int
name|kludge_FD_ISSET
parameter_list|(
name|int
name|n
parameter_list|,
name|fd_set
modifier|*
name|set
parameter_list|)
block|{
return|return
name|FD_ISSET
argument_list|(
name|n
argument_list|,
name|set
argument_list|)
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __GLIBC_PREREQ(2, 15)&& (_FORTIFY_SOURCE> 0) */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __GNU_LIBRARY__&& __GLIBC_PREREQ */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HAVE_FEATURES_H&& _FORTIFY_SOURCE */
end_comment

end_unit

