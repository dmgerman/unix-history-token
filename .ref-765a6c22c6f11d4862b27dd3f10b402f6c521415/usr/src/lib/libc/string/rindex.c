begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* @(#)rindex.c	4.1 (Berkeley) %G% */
end_comment

begin_comment
comment|/*  * Return the ptr in sp at which the character c last  * appears; NULL if not found */
end_comment

begin_define
define|#
directive|define
name|NULL
value|0
end_define

begin_function
name|char
modifier|*
name|rindex
parameter_list|(
name|sp
parameter_list|,
name|c
parameter_list|)
specifier|register
name|char
modifier|*
name|sp
decl_stmt|,
name|c
decl_stmt|;
block|{
specifier|register
name|char
modifier|*
name|r
decl_stmt|;
name|r
operator|=
name|NULL
expr_stmt|;
do|do
block|{
if|if
condition|(
operator|*
name|sp
operator|==
name|c
condition|)
name|r
operator|=
name|sp
expr_stmt|;
block|}
do|while
condition|(
operator|*
name|sp
operator|++
condition|)
do|;
return|return
operator|(
name|r
operator|)
return|;
block|}
end_function

end_unit

