begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_if
if|#
directive|if
name|HAVE_CONFIG_H
end_if

begin_include
include|#
directive|include
file|<config.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<stddef.h>
end_include

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_if
if|#
directive|if
name|HAVE_STDIO_EXT_H
end_if

begin_include
include|#
directive|include
file|<stdio_ext.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_DECL___FPENDING
end_ifndef

begin_expr_stmt
literal|"this configure-time declaration test was not run"
endif|#
directive|endif
if|#
directive|if
operator|!
name|HAVE_DECL___FPENDING
name|size_t
name|__fpending
argument_list|(
name|FILE
operator|*
argument_list|)
expr_stmt|;
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

