begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_comment
comment|/*  * Written by J.T. Conklin, 10/05/94  * Public domain.  */
end_comment

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|__indr_reference
end_ifdef

begin_expr_stmt
name|__indr_reference
argument_list|(
name|_catclose
argument_list|,
name|catclose
argument_list|)
expr_stmt|;
end_expr_stmt

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|<nl_types.h>
end_include

begin_decl_stmt
specifier|extern
name|int
name|_catclose
name|__P
argument_list|(
operator|(
name|nl_catd
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_function
name|int
name|catclose
parameter_list|(
name|catd
parameter_list|)
name|nl_catd
name|catd
decl_stmt|;
block|{
return|return
name|_catclose
argument_list|(
name|catd
argument_list|)
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

end_unit

