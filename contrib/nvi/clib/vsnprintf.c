begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_include
include|#
directive|include
file|"config.h"
end_include

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|__STDC__
end_ifdef

begin_include
include|#
directive|include
file|<stdarg.h>
end_include

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|<varargs.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * PUBLIC: #ifndef HAVE_VSNPRINTF  * PUBLIC: int vsnprintf __P((char *, size_t, const char *, ...));  * PUBLIC: #endif  */
end_comment

begin_function
name|int
name|vsnprintf
parameter_list|(
name|str
parameter_list|,
name|n
parameter_list|,
name|fmt
parameter_list|,
name|ap
parameter_list|)
name|char
modifier|*
name|str
decl_stmt|;
name|size_t
name|n
decl_stmt|;
specifier|const
name|char
modifier|*
name|fmt
decl_stmt|;
name|va_list
name|ap
decl_stmt|;
block|{
ifdef|#
directive|ifdef
name|SPRINTF_RET_CHARPNT
operator|(
name|void
operator|)
name|vsprintf
argument_list|(
name|str
argument_list|,
name|fmt
argument_list|,
name|ap
argument_list|)
expr_stmt|;
return|return
operator|(
name|strlen
argument_list|(
name|str
argument_list|)
operator|)
return|;
else|#
directive|else
return|return
operator|(
name|vsprintf
argument_list|(
name|str
argument_list|,
name|fmt
argument_list|,
name|ap
argument_list|)
operator|)
return|;
endif|#
directive|endif
block|}
end_function

end_unit

