begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_ifndef
ifndef|#
directive|ifndef
name|NON_UNIX_STDIO
end_ifndef

begin_define
define|#
directive|define
name|_INCLUDE_POSIX_SOURCE
end_define

begin_comment
comment|/* for HP-UX */
end_comment

begin_define
define|#
directive|define
name|_INCLUDE_XOPEN_SOURCE
end_define

begin_comment
comment|/* for HP-UX */
end_comment

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<sys/stat.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|"f2c.h"
end_include

begin_include
include|#
directive|include
file|"fio.h"
end_include

begin_function
name|VOID
ifdef|#
directive|ifdef
name|KR_headers
name|g_char
parameter_list|(
name|a
parameter_list|,
name|alen
parameter_list|,
name|b
parameter_list|)
name|char
modifier|*
name|a
decl_stmt|,
decl|*
name|b
decl_stmt|;
end_function

begin_decl_stmt
name|ftnlen
name|alen
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_macro
name|g_char
argument_list|(
argument|char *a
argument_list|,
argument|ftnlen alen
argument_list|,
argument|char *b
argument_list|)
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_block
block|{
name|char
modifier|*
name|x
init|=
name|a
operator|+
name|alen
decl_stmt|,
modifier|*
name|y
init|=
name|b
operator|+
name|alen
decl_stmt|;
for|for
control|(
init|;
condition|;
name|y
operator|--
control|)
block|{
if|if
condition|(
name|x
operator|<=
name|a
condition|)
block|{
operator|*
name|b
operator|=
literal|0
expr_stmt|;
return|return;
block|}
if|if
condition|(
operator|*
operator|--
name|x
operator|!=
literal|' '
condition|)
break|break;
block|}
operator|*
name|y
operator|--
operator|=
literal|0
expr_stmt|;
do|do
operator|*
name|y
operator|--
operator|=
operator|*
name|x
expr_stmt|;
do|while
condition|(
name|x
operator|--
operator|>
name|a
condition|)
do|;
block|}
end_block

begin_function
name|VOID
ifdef|#
directive|ifdef
name|KR_headers
name|b_char
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|blen
parameter_list|)
name|char
modifier|*
name|a
decl_stmt|,
decl|*
name|b
decl_stmt|;
end_function

begin_decl_stmt
name|ftnlen
name|blen
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_macro
name|b_char
argument_list|(
argument|char *a
argument_list|,
argument|char *b
argument_list|,
argument|ftnlen blen
argument_list|)
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_block
block|{
name|int
name|i
decl_stmt|;
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
name|blen
operator|&&
operator|*
name|a
operator|!=
literal|0
condition|;
name|i
operator|++
control|)
operator|*
name|b
operator|++
operator|=
operator|*
name|a
operator|++
expr_stmt|;
for|for
control|(
init|;
name|i
operator|<
name|blen
condition|;
name|i
operator|++
control|)
operator|*
name|b
operator|++
operator|=
literal|' '
expr_stmt|;
block|}
end_block

begin_ifndef
ifndef|#
directive|ifndef
name|NON_UNIX_STDIO
end_ifndef

begin_ifdef
ifdef|#
directive|ifdef
name|KR_headers
end_ifdef

begin_decl_stmt
name|long
name|f__inode
argument_list|(
name|a
argument_list|,
name|dev
argument_list|)
name|char
modifier|*
name|a
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
modifier|*
name|dev
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_function
name|long
name|f__inode
parameter_list|(
name|char
modifier|*
name|a
parameter_list|,
name|int
modifier|*
name|dev
parameter_list|)
endif|#
directive|endif
block|{
name|struct
name|stat
name|x
decl_stmt|;
if|if
condition|(
name|stat
argument_list|(
name|a
argument_list|,
operator|&
name|x
argument_list|)
operator|<
literal|0
condition|)
return|return
operator|(
operator|-
literal|1
operator|)
return|;
operator|*
name|dev
operator|=
name|x
operator|.
name|st_dev
expr_stmt|;
return|return
operator|(
name|x
operator|.
name|st_ino
operator|)
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

end_unit

