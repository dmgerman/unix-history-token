begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * XXX: We don't have dlopen& friends in statically linked programs  * XXX: so we avoid using them.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|PIC
end_ifdef

begin_include
include|#
directive|include
file|"../../../contrib/tcl/generic/tclLoad.c"
end_include

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|"../../../contrib/tcl/generic/tclLoadNone.c"
end_include

begin_endif
endif|#
directive|endif
end_endif

end_unit

