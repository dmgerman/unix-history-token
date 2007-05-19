begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* calloc -- allocate memory which has been initialized to zero.    This function is in the public domain. */
end_comment

begin_comment
comment|/*  @deftypefn Supplemental void* calloc (size_t @var{nelem}, size_t @var{elsize})  Uses @code{malloc} to allocate storage for @var{nelem} objects of @var{elsize} bytes each, then zeros the memory.  @end deftypefn  */
end_comment

begin_include
include|#
directive|include
file|"ansidecl.h"
end_include

begin_include
include|#
directive|include
file|<stddef.h>
end_include

begin_comment
comment|/* For systems with larger pointers than ints, this must be declared.  */
end_comment

begin_function_decl
name|PTR
name|malloc
parameter_list|(
name|size_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|bzero
parameter_list|(
name|PTR
parameter_list|,
name|size_t
parameter_list|)
function_decl|;
end_function_decl

begin_function
name|PTR
name|calloc
parameter_list|(
name|size_t
name|nelem
parameter_list|,
name|size_t
name|elsize
parameter_list|)
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

