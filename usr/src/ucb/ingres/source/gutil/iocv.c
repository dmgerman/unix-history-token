begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_include
include|#
directive|include
file|<sccs.h>
end_include

begin_macro
name|SCCSID
argument_list|(
argument|@(#)iocv.c
literal|7.1
literal|2
argument|/
literal|5
argument|/
literal|81
argument_list|)
end_macro

begin_comment
comment|/* **  INTEGER OUTPUT CONVERSION ** **	The integer `i' is converted to ascii using itoa and put **	into the static buffer `buf'.  The address of `buf' is **	returned. */
end_comment

begin_function
name|char
modifier|*
name|iocv
parameter_list|(
name|i
parameter_list|)
name|int
name|i
decl_stmt|;
block|{
specifier|static
name|char
name|buf
index|[
literal|7
index|]
decl_stmt|;
name|itoa
argument_list|(
name|i
argument_list|,
name|buf
argument_list|)
expr_stmt|;
return|return
operator|(
name|buf
operator|)
return|;
block|}
end_function

end_unit

