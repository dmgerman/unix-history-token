begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_include
include|#
directive|include
file|<tommath.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|BN_ERROR_C
end_ifdef

begin_comment
comment|/* LibTomMath, multiple-precision integer library -- Tom St Denis  *  * LibTomMath is a library that provides multiple-precision  * integer arithmetic as well as number theoretic functionality.  *  * The library was designed directly after the MPI library by  * Michael Fromberger but has been written from scratch with  * additional optimizations in place.  *  * The library is free for all purposes without any express  * guarantee it works.  *  * Tom St Denis, tomstdenis@gmail.com, http://libtom.org  */
end_comment

begin_struct
specifier|static
specifier|const
struct|struct
block|{
name|int
name|code
decl_stmt|;
name|char
modifier|*
name|msg
decl_stmt|;
block|}
name|msgs
index|[]
init|=
block|{
block|{
name|MP_OKAY
block|,
literal|"Successful"
block|}
block|,
block|{
name|MP_MEM
block|,
literal|"Out of heap"
block|}
block|,
block|{
name|MP_VAL
block|,
literal|"Value out of range"
block|}
block|}
struct|;
end_struct

begin_comment
comment|/* return a char * string for a given code */
end_comment

begin_function
name|char
modifier|*
name|mp_error_to_string
parameter_list|(
name|int
name|code
parameter_list|)
block|{
name|int
name|x
decl_stmt|;
comment|/* scan the lookup table for the given message */
for|for
control|(
name|x
operator|=
literal|0
init|;
name|x
operator|<
call|(
name|int
call|)
argument_list|(
sizeof|sizeof
argument_list|(
name|msgs
argument_list|)
operator|/
sizeof|sizeof
argument_list|(
name|msgs
index|[
literal|0
index|]
argument_list|)
argument_list|)
condition|;
name|x
operator|++
control|)
block|{
if|if
condition|(
name|msgs
index|[
name|x
index|]
operator|.
name|code
operator|==
name|code
condition|)
block|{
return|return
name|msgs
index|[
name|x
index|]
operator|.
name|msg
return|;
block|}
block|}
comment|/* generic reply for invalid code */
return|return
literal|"Invalid error code"
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* $Source: /cvs/libtom/libtommath/bn_error.c,v $ */
end_comment

begin_comment
comment|/* $Revision: 1.4 $ */
end_comment

begin_comment
comment|/* $Date: 2006/12/28 01:25:13 $ */
end_comment

end_unit

