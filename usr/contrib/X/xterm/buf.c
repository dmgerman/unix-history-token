begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_include
include|#
directive|include
file|<X/mit-copyright.h>
end_include

begin_comment
comment|/* Copyright    Massachusetts Institute of Technology    1984, 1985	*/
end_comment

begin_comment
comment|/* buf.c */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|lint
end_ifndef

begin_decl_stmt
specifier|static
name|char
modifier|*
name|rcsid_buf_c
init|=
literal|"$Header: buf.c,v 10.8 86/02/01 16:05:37 tony Rel $"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
endif|lint
end_endif

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<errno.h>
end_include

begin_include
include|#
directive|include
file|<X/Xlib.h>
end_include

begin_include
include|#
directive|include
file|"ptyx.h"
end_include

begin_include
include|#
directive|include
file|<ctype.h>
end_include

begin_decl_stmt
specifier|extern
name|int
name|errno
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|am_slave
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * If no input available, returns -1. Else, reads characters from  * trmbuf->fildes and puts them in the buffer, then returns first  * character read.  */
end_comment

begin_expr_stmt
name|fill
argument_list|(
name|trmbuf
argument_list|)
specifier|register
name|Buffer
operator|*
name|trmbuf
expr_stmt|;
end_expr_stmt

begin_block
block|{
ifdef|#
directive|ifdef
name|JUMPSCROLL
specifier|extern
name|Terminal
name|term
decl_stmt|;
specifier|register
name|Screen
modifier|*
name|screen
init|=
operator|&
name|term
operator|.
name|screen
decl_stmt|;
if|if
condition|(
name|screen
operator|->
name|scroll_amt
condition|)
name|FlushScroll
argument_list|(
name|screen
argument_list|)
expr_stmt|;
endif|#
directive|endif
endif|JUMPSCROLL
name|trmbuf
operator|->
name|ptr
operator|=
operator|&
name|trmbuf
operator|->
name|buf
index|[
literal|0
index|]
expr_stmt|;
name|trmbuf
operator|->
name|cnt
operator|=
name|read
argument_list|(
name|trmbuf
operator|->
name|fildes
argument_list|,
name|trmbuf
operator|->
name|ptr
argument_list|,
name|BUF_SIZE
argument_list|)
expr_stmt|;
if|if
condition|(
name|trmbuf
operator|->
name|cnt
operator|==
operator|-
literal|1
condition|)
block|{
if|if
condition|(
name|errno
operator|!=
name|EWOULDBLOCK
condition|)
block|{
if|if
condition|(
name|errno
operator|==
name|EIO
operator|&&
name|am_slave
condition|)
name|exit
argument_list|(
literal|0
argument_list|)
expr_stmt|;
comment|/* pty closed */
else|else
name|Panic
argument_list|(
literal|"fill: read returned unexpected error (%d)\n"
argument_list|,
name|errno
argument_list|)
expr_stmt|;
block|}
return|return
operator|(
operator|-
literal|1
operator|)
return|;
block|}
if|if
condition|(
operator|--
name|trmbuf
operator|->
name|cnt
operator|<
literal|0
condition|)
name|Panic
argument_list|(
literal|"fill: read returned %d\n"
argument_list|,
name|trmbuf
operator|->
name|cnt
operator|+
literal|1
argument_list|)
expr_stmt|;
return|return
operator|(
operator|*
name|trmbuf
operator|->
name|ptr
operator|++
operator|&
literal|0177
operator|)
return|;
block|}
end_block

end_unit

