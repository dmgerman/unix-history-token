begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<ctype.h>
end_include

begin_define
define|#
directive|define
name|reg
value|register
end_define

begin_define
define|#
directive|define
name|makelower
parameter_list|(
name|c
parameter_list|)
value|(isupper(c) ? tolower(c) : c)
end_define

begin_comment
comment|/*  * Compare strings:  s1>s2:>0  s1==s2: 0  s1<s2:<0  */
end_comment

begin_macro
name|strcmp
argument_list|(
argument|s1
argument_list|,
argument|s2
argument_list|)
end_macro

begin_decl_stmt
name|reg
name|char
modifier|*
name|s1
decl_stmt|,
modifier|*
name|s2
decl_stmt|;
end_decl_stmt

begin_block
block|{
while|while
condition|(
name|makelower
argument_list|(
operator|*
name|s1
argument_list|)
operator|==
name|makelower
argument_list|(
operator|*
name|s2
argument_list|)
condition|)
block|{
if|if
condition|(
operator|*
name|s1
operator|==
literal|'\0'
condition|)
return|return
literal|0
return|;
name|s1
operator|++
operator|,
name|s2
operator|++
expr_stmt|;
block|}
return|return
operator|*
name|s1
operator|-
operator|*
name|s2
return|;
block|}
end_block

end_unit

