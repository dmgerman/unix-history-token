begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_include
include|#
directive|include
file|"f2c.h"
end_include

begin_function
name|VOID
ifdef|#
directive|ifdef
name|KR_headers
name|d_cnjg
parameter_list|(
name|resx
parameter_list|,
name|z
parameter_list|)
name|doublecomplex
modifier|*
name|resx
decl_stmt|,
decl|*
name|z
decl_stmt|;
end_function

begin_else
else|#
directive|else
end_else

begin_macro
name|d_cnjg
argument_list|(
argument|doublecomplex *resx
argument_list|,
argument|doublecomplex *z
argument_list|)
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_block
block|{
name|doublecomplex
name|res
decl_stmt|;
name|res
operator|.
name|r
operator|=
name|z
operator|->
name|r
expr_stmt|;
name|res
operator|.
name|i
operator|=
operator|-
name|z
operator|->
name|i
expr_stmt|;
name|resx
operator|->
name|r
operator|=
name|res
operator|.
name|r
expr_stmt|;
name|resx
operator|->
name|i
operator|=
name|res
operator|.
name|i
expr_stmt|;
block|}
end_block

end_unit

