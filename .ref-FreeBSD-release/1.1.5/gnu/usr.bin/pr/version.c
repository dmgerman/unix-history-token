begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_CONFIG_H
end_ifdef

begin_if
if|#
directive|if
name|defined
argument_list|(
name|CONFIG_BROKETS
argument_list|)
end_if

begin_comment
comment|/* We use<config.h> instead of "config.h" so that a compilation    using -I. -I$srcdir will use ./config.h rather than $srcdir/config.h    (which it would do because it found this file in $srcdir).  */
end_comment

begin_include
include|#
directive|include
file|<config.h>
end_include

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|"config.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|"version.h"
end_include

begin_decl_stmt
specifier|const
name|char
modifier|*
name|version_string
init|=
literal|"GNU textutils 1.9"
decl_stmt|;
end_decl_stmt

end_unit

