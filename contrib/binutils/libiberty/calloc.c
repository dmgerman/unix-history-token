begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* calloc -- allocate memory which has been initialized to zero.    This function is in the public domain. */
end_comment

begin_include
include|#
directive|include
file|"ansidecl.h"
end_include

begin_include
include|#
directive|include
file|"libiberty.h"
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|ANSI_PROTOTYPES
end_ifdef

begin_include
include|#
directive|include
file|<stddef.h>
end_include

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|size_t
value|unsigned long
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* For systems with larger pointers than ints, this must be declared.  */
end_comment

begin_decl_stmt
name|PTR
name|malloc
name|PARAMS
argument_list|(
operator|(
name|size_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_function
name|PTR
name|calloc
parameter_list|(
name|nelem
parameter_list|,
name|elsize
parameter_list|)
name|size_t
name|nelem
decl_stmt|,
name|elsize
decl_stmt|;
block|{
specifier|register
name|PTR
name|ptr
decl_stmt|;
if|if
condition|(
name|nelem
operator|==
literal|0
operator|||
name|elsize
operator|==
literal|0
condition|)
name|nelem
operator|=
name|elsize
operator|=
literal|1
expr_stmt|;
name|ptr
operator|=
name|malloc
argument_list|(
name|nelem
operator|*
name|elsize
argument_list|)
expr_stmt|;
if|if
condition|(
name|ptr
condition|)
name|bzero
argument_list|(
name|ptr
argument_list|,
name|nelem
operator|*
name|elsize
argument_list|)
expr_stmt|;
return|return
name|ptr
return|;
block|}
end_function

end_unit

