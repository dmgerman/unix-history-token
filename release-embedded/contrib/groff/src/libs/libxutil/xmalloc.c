begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_include
include|#
directive|include
file|<X11/Xlib.h>
end_include

begin_include
include|#
directive|include
file|<X11/Intrinsic.h>
end_include

begin_function
name|char
modifier|*
name|xmalloc
parameter_list|(
name|int
name|n
parameter_list|)
block|{
return|return
name|XtMalloc
argument_list|(
name|n
argument_list|)
return|;
block|}
end_function

end_unit

