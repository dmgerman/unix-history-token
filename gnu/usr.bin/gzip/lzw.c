begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* lzw.c -- compress files in LZW format.  * This is a dummy version avoiding patent problems.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|lint
end_ifndef

begin_decl_stmt
specifier|static
name|char
name|rcsid
index|[]
init|=
literal|"$Id: lzw.c,v 0.8 1993/04/25 08:09:58 jloup Exp $"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|"tailor.h"
end_include

begin_include
include|#
directive|include
file|"gzip.h"
end_include

begin_include
include|#
directive|include
file|"lzw.h"
end_include

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_decl_stmt
specifier|static
name|int
name|msg_done
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Compress in to out with lzw method. */
end_comment

begin_function
name|int
name|lzw
parameter_list|(
name|in
parameter_list|,
name|out
parameter_list|)
name|int
name|in
decl_stmt|,
name|out
decl_stmt|;
block|{
if|if
condition|(
name|msg_done
condition|)
return|return
name|ERROR
return|;
name|msg_done
operator|=
literal|1
expr_stmt|;
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"output in compress .Z format not supported\n"
argument_list|)
expr_stmt|;
name|in
operator|++
operator|,
name|out
operator|++
expr_stmt|;
comment|/* avoid warnings on unused variables */
name|exit_code
operator|=
name|ERROR
expr_stmt|;
return|return
name|ERROR
return|;
block|}
end_function

end_unit

