begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* alloc.c - version 1.0.2 */
end_comment

begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|LINT
end_ifdef

begin_comment
comment|/*    a ridiculous definition, suppressing 	"possible pointer alignment problem" for (long *) malloc() 	"enlarg defined but never used" 	"ftell defined (in<stdio.h>) but never used"    from lint */
end_comment

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_function
name|long
modifier|*
name|alloc
parameter_list|(
name|n
parameter_list|)
name|unsigned
name|n
decl_stmt|;
block|{
name|long
name|dummy
init|=
name|ftell
argument_list|(
name|stderr
argument_list|)
decl_stmt|;
if|if
condition|(
name|n
condition|)
name|dummy
operator|=
literal|0
expr_stmt|;
comment|/* make sure arg is used */
return|return
operator|(
operator|&
name|dummy
operator|)
return|;
block|}
end_function

begin_else
else|#
directive|else
end_else

begin_function
name|long
modifier|*
name|alloc
parameter_list|(
name|lth
parameter_list|)
specifier|register
name|unsigned
name|lth
decl_stmt|;
block|{
specifier|register
name|char
modifier|*
name|ptr
decl_stmt|;
if|if
condition|(
operator|!
operator|(
name|ptr
operator|=
name|malloc
argument_list|(
name|lth
argument_list|)
operator|)
condition|)
name|panic
argument_list|(
literal|"Cannot get %d bytes"
argument_list|,
name|lth
argument_list|)
expr_stmt|;
return|return
operator|(
operator|(
name|long
operator|*
operator|)
name|ptr
operator|)
return|;
block|}
end_function

begin_function
name|long
modifier|*
name|enlarge
parameter_list|(
name|ptr
parameter_list|,
name|lth
parameter_list|)
specifier|register
name|char
modifier|*
name|ptr
decl_stmt|;
specifier|register
name|unsigned
name|lth
decl_stmt|;
block|{
specifier|register
name|char
modifier|*
name|nptr
decl_stmt|;
if|if
condition|(
operator|!
operator|(
name|nptr
operator|=
name|realloc
argument_list|(
name|ptr
argument_list|,
name|lth
argument_list|)
operator|)
condition|)
name|panic
argument_list|(
literal|"Cannot reallocate %d bytes"
argument_list|,
name|lth
argument_list|)
expr_stmt|;
return|return
operator|(
operator|(
name|long
operator|*
operator|)
name|nptr
operator|)
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
endif|LINT
end_endif

end_unit

