begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$File: asctime_r.c,v 1.1 2012/05/15 17:14:36 christos Exp $	*/
end_comment

begin_include
include|#
directive|include
file|"file.h"
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|lint
end_ifndef

begin_macro
name|FILE_RCSID
argument_list|(
literal|"@(#)$File: asctime_r.c,v 1.1 2012/05/15 17:14:36 christos Exp $"
argument_list|)
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* lint */
end_comment

begin_include
include|#
directive|include
file|<time.h>
end_include

begin_include
include|#
directive|include
file|<string.h>
end_include

begin_comment
comment|/* asctime_r is not thread-safe anyway */
end_comment

begin_function
name|char
modifier|*
name|asctime_r
parameter_list|(
specifier|const
name|struct
name|tm
modifier|*
name|t
parameter_list|,
name|char
modifier|*
name|dst
parameter_list|)
block|{
name|char
modifier|*
name|p
init|=
name|asctime
argument_list|(
name|t
argument_list|)
decl_stmt|;
if|if
condition|(
name|p
operator|==
name|NULL
condition|)
return|return
name|NULL
return|;
name|memcpy
argument_list|(
name|dst
argument_list|,
name|p
argument_list|,
literal|26
argument_list|)
expr_stmt|;
return|return
name|dst
return|;
block|}
end_function

end_unit

