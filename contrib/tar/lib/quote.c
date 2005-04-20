begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Written by Paul Eggert<eggert@twinsun.com> */
end_comment

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

begin_if
if|#
directive|if
name|HAVE_STDDEF_H
end_if

begin_include
include|#
directive|include
file|<stddef.h>
end_include

begin_comment
comment|/* For the definition of size_t on windows w/MSVC.  */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<quotearg.h>
end_include

begin_include
include|#
directive|include
file|<quote.h>
end_include

begin_comment
comment|/* Return an unambiguous printable representated, allocated in slot N,    for NAME, suitable for diagnostics.  */
end_comment

begin_function
name|char
specifier|const
modifier|*
name|quote_n
parameter_list|(
name|int
name|n
parameter_list|,
name|char
specifier|const
modifier|*
name|name
parameter_list|)
block|{
return|return
name|quotearg_n_style
argument_list|(
name|n
argument_list|,
name|locale_quoting_style
argument_list|,
name|name
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/* Return an unambiguous printable representation of NAME, suitable    for diagnostics.  */
end_comment

begin_function
name|char
specifier|const
modifier|*
name|quote
parameter_list|(
name|char
specifier|const
modifier|*
name|name
parameter_list|)
block|{
return|return
name|quote_n
argument_list|(
literal|0
argument_list|,
name|name
argument_list|)
return|;
block|}
end_function

end_unit

