begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_include
include|#
directive|include
file|"f2c.h"
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|KR_headers
end_ifdef

begin_expr_stmt
name|ftnint
name|iargc_
argument_list|()
else|#
directive|else
name|ftnint
name|iargc_
argument_list|(
argument|void
argument_list|)
endif|#
directive|endif
block|{
specifier|extern
name|int
name|xargc
block|;
return|return
operator|(
name|xargc
operator|-
literal|1
operator|)
return|;
block|}
end_expr_stmt

end_unit

