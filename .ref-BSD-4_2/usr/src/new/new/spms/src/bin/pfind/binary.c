begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $Header$ */
end_comment

begin_comment
comment|/*  * Author: Peter J. Nicklin  */
end_comment

begin_include
include|#
directive|include
file|"yesno.h"
end_include

begin_decl_stmt
specifier|static
name|char
modifier|*
modifier|*
name|STRINGS
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* pointer array containing strings */
end_comment

begin_decl_stmt
specifier|static
name|int
name|NSTRINGS
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* number of strings in STRINGS */
end_comment

begin_comment
comment|/*  * bininit() initializes and sorts the STRINGS pointer array.  */
end_comment

begin_function
name|void
name|bininit
parameter_list|(
name|argc
parameter_list|,
name|argv
parameter_list|)
name|int
name|argc
decl_stmt|;
name|char
modifier|*
modifier|*
name|argv
decl_stmt|;
block|{
name|int
name|qsort
parameter_list|()
function_decl|;
comment|/* quicker sort */
name|int
name|strpcmp
parameter_list|()
function_decl|;
comment|/* pointed-to string comparison */
name|NSTRINGS
operator|=
name|argc
expr_stmt|;
name|STRINGS
operator|=
name|argv
expr_stmt|;
name|qsort
argument_list|(
operator|(
name|char
operator|*
operator|)
name|STRINGS
argument_list|,
name|NSTRINGS
argument_list|,
sizeof|sizeof
argument_list|(
name|char
operator|*
argument_list|)
argument_list|,
name|strpcmp
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/*  * binsearch() returns integer YES if string is found in sorted pointer  * array STRINGS, otherwise NO. Uses binary search.  */
end_comment

begin_macro
name|binsearch
argument_list|(
argument|string
argument_list|)
end_macro

begin_decl_stmt
name|char
modifier|*
name|string
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* string to be matched */
end_comment

begin_block
block|{
name|int
name|comp
decl_stmt|;
comment|/* compare string values */
name|int
name|high
decl_stmt|;
comment|/* upper limit of array */
name|int
name|low
decl_stmt|;
comment|/* lower limit of array */
name|int
name|mid
decl_stmt|;
comment|/* middle of search range */
name|int
name|strcmp
parameter_list|()
function_decl|;
comment|/* string comparison */
name|low
operator|=
literal|0
expr_stmt|;
name|high
operator|=
name|NSTRINGS
operator|-
literal|1
expr_stmt|;
while|while
condition|(
name|low
operator|<=
name|high
condition|)
block|{
name|mid
operator|=
operator|(
name|low
operator|+
name|high
operator|)
operator|/
literal|2
expr_stmt|;
if|if
condition|(
operator|(
name|comp
operator|=
name|strcmp
argument_list|(
name|string
argument_list|,
name|STRINGS
index|[
name|mid
index|]
argument_list|)
operator|)
operator|<
literal|0
condition|)
name|high
operator|=
name|mid
operator|-
literal|1
expr_stmt|;
elseif|else
if|if
condition|(
name|comp
operator|>
literal|0
condition|)
name|low
operator|=
name|mid
operator|+
literal|1
expr_stmt|;
else|else
return|return
operator|(
name|YES
operator|)
return|;
block|}
return|return
operator|(
name|NO
operator|)
return|;
block|}
end_block

begin_comment
comment|/*  * strpcmp() compares strings in a pointer array. Returns whatever strcmp()  * returns.  */
end_comment

begin_function
specifier|static
name|int
name|strpcmp
parameter_list|(
name|s1
parameter_list|,
name|s2
parameter_list|)
name|char
modifier|*
modifier|*
name|s1
decl_stmt|;
name|char
modifier|*
modifier|*
name|s2
decl_stmt|;
block|{
name|int
name|strcmp
parameter_list|()
function_decl|;
comment|/* string comparison */
return|return
operator|(
name|strcmp
argument_list|(
operator|*
name|s1
argument_list|,
operator|*
name|s2
argument_list|)
operator|)
return|;
block|}
end_function

end_unit

