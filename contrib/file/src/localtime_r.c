begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$File: localtime_r.c,v 1.2 2015/07/11 14:41:37 christos Exp $	*/
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
literal|"@(#)$File: localtime_r.c,v 1.2 2015/07/11 14:41:37 christos Exp $"
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
name|struct
name|tm
modifier|*
name|localtime_r
parameter_list|(
specifier|const
name|time_t
modifier|*
name|t
parameter_list|,
name|struct
name|tm
modifier|*
name|tm
parameter_list|)
block|{
name|struct
name|tm
modifier|*
name|tmp
init|=
name|localtime
argument_list|(
name|t
argument_list|)
decl_stmt|;
if|if
condition|(
name|tmp
operator|==
name|NULL
condition|)
return|return
name|NULL
return|;
name|memcpy
argument_list|(
name|tm
argument_list|,
name|tmp
argument_list|,
sizeof|sizeof
argument_list|(
operator|*
name|tm
argument_list|)
argument_list|)
expr_stmt|;
return|return
name|tmp
return|;
block|}
end_function

end_unit

