begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_include
include|#
directive|include
file|<sccs.h>
end_include

begin_macro
name|SCCSID
argument_list|(
argument|@(#)freebuf.c
literal|7.1
literal|2
argument|/
literal|5
argument|/
literal|81
argument_list|)
end_macro

begin_comment
comment|/* **  FREEBUF.C -- more routines for LIFO dynamic buffer allocation [need.c] ** **	These routines allow the deallocation of a need() type buffer, **	and also using the same buffer for various SERIALIZED purposes **	by marking the end of one, beginning of the next. ** **	Defines: **		freebuf() **		markbuf() **		seterr() */
end_comment

begin_comment
comment|/* structure that the routines use to allocate space */
end_comment

begin_struct
struct|struct
name|nodbuffer
block|{
name|int
name|nleft
decl_stmt|;
comment|/* bytes left */
name|int
name|err_num
decl_stmt|;
comment|/* error code on overflow */
name|int
function_decl|(
modifier|*
name|err_func
function_decl|)
parameter_list|()
function_decl|;
comment|/* error function on overflow */
name|char
modifier|*
name|xfree
decl_stmt|;
comment|/* next free byte */
name|char
name|buffer
index|[
literal|1
index|]
decl_stmt|;
comment|/*beginning of buffer area */
block|}
struct|;
end_struct

begin_escape
end_escape

begin_comment
comment|/* **  MARKBUF -- Mark a place in the buffer to deallocate to ** **	Parameters: **		bf -- buffer ** **	Returns: **		int>= 0 marking place in buffer (should be used in calling **			freebuf()) ** **	Side Effects: **		none */
end_comment

begin_macro
name|markbuf
argument_list|(
argument|bf
argument_list|)
end_macro

begin_decl_stmt
name|struct
name|nodbuffer
modifier|*
name|bf
decl_stmt|;
end_decl_stmt

begin_block
block|{
specifier|register
name|struct
name|nodbuffer
modifier|*
name|buf
decl_stmt|;
name|buf
operator|=
name|bf
expr_stmt|;
return|return
operator|(
name|buf
operator|->
name|nleft
operator|)
return|;
block|}
end_block

begin_escape
end_escape

begin_comment
comment|/* **  FREEBUF -- frees part of a buffer ** **	Parameters: **		bf -- buffer **		bytes -- a previous return from markbuf(). ** **	Returns: **		none ** **	Side Effects: **		none */
end_comment

begin_macro
name|freebuf
argument_list|(
argument|bf
argument_list|,
argument|bytes
argument_list|)
end_macro

begin_decl_stmt
name|struct
name|nodbuffer
modifier|*
name|bf
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|bytes
decl_stmt|;
end_decl_stmt

begin_block
block|{
specifier|register
name|struct
name|nodbuffer
modifier|*
name|buf
decl_stmt|;
specifier|register
name|int
name|i
decl_stmt|;
name|buf
operator|=
name|bf
expr_stmt|;
name|i
operator|=
name|bytes
operator|-
name|buf
operator|->
name|nleft
expr_stmt|;
if|if
condition|(
name|i
operator|<
literal|0
condition|)
name|syserr
argument_list|(
literal|"freebuf %d, %d"
argument_list|,
name|i
argument_list|,
name|bytes
argument_list|)
expr_stmt|;
name|buf
operator|->
name|xfree
operator|-=
name|i
expr_stmt|;
name|buf
operator|->
name|nleft
operator|+=
name|i
expr_stmt|;
block|}
end_block

begin_escape
end_escape

begin_comment
comment|/* **  SETERR -- change the error info for a buffer ** **	Parameters: **		bf -- buffer **		errnum -- new overflow error code **		err_func -- new error handler ** **	Returns: **		none ** **	Side Effects: **		adjusts buffer structure */
end_comment

begin_macro
name|seterr
argument_list|(
argument|bf
argument_list|,
argument|errnum
argument_list|,
argument|err_func
argument_list|)
end_macro

begin_decl_stmt
name|struct
name|nodbuffer
modifier|*
name|bf
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|errnum
decl_stmt|;
end_decl_stmt

begin_function_decl
name|int
function_decl|(
modifier|*
name|err_func
function_decl|)
parameter_list|()
function_decl|;
end_function_decl

begin_block
block|{
specifier|register
name|struct
name|nodbuffer
modifier|*
name|buf
decl_stmt|;
specifier|register
name|int
function_decl|(
modifier|*
name|erf
function_decl|)
parameter_list|()
function_decl|;
name|buf
operator|=
name|bf
expr_stmt|;
name|erf
operator|=
name|err_func
expr_stmt|;
name|buf
operator|->
name|err_num
operator|=
name|errnum
expr_stmt|;
name|bf
operator|->
name|err_func
operator|=
name|erf
expr_stmt|;
block|}
end_block

end_unit

