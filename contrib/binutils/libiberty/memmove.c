begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Wrapper to implement ANSI C's memmove using BSD's bcopy. */
end_comment

begin_comment
comment|/* This function is in the public domain.  --Per Bothner. */
end_comment

begin_include
include|#
directive|include
file|<ansidecl.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|__STDC__
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

begin_function
name|PTR
name|memmove
parameter_list|(
name|s1
parameter_list|,
name|s2
parameter_list|,
name|n
parameter_list|)
name|PTR
name|s1
decl_stmt|;
specifier|const
name|PTR
name|s2
decl_stmt|;
name|size_t
name|n
decl_stmt|;
block|{
name|bcopy
argument_list|(
name|s2
argument_list|,
name|s1
argument_list|,
name|n
argument_list|)
expr_stmt|;
return|return
name|s1
return|;
block|}
end_function

end_unit

