begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Copyright (c) 1982, Regents, University of California */
end_comment

begin_struct
struct|struct
name|sdot
block|{
name|long
name|I
decl_stmt|;
name|struct
name|sdot
modifier|*
name|CDR
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|vl
block|{
name|long
name|high
decl_stmt|;
name|long
name|low
decl_stmt|;
block|}
struct|;
end_struct

begin_function
name|long
name|dodiv
parameter_list|(
name|top
parameter_list|,
name|bottom
parameter_list|)
name|long
modifier|*
name|top
decl_stmt|,
decl|*
name|bottom
decl_stmt|;
end_function

begin_comment
comment|/* top least significant; bottom most */
end_comment

begin_block
block|{
name|struct
name|vl
name|work
decl_stmt|;
name|char
name|error
decl_stmt|;
specifier|register
name|long
modifier|*
name|p
init|=
name|bottom
decl_stmt|;
comment|/* r12 */
specifier|register
name|long
name|rem
init|=
literal|0
decl_stmt|;
comment|/* r11 */
for|for
control|(
init|;
name|p
operator|<=
name|top
condition|;
name|p
operator|++
control|)
block|{
comment|/*	emul(0x40000000,rem,*p,&work);		*/
comment|/*	*p = ediv(&work,1000000000,&error);	*/
comment|/*	rem = work.high;			*/
asm|asm("emul	$0x40000000,r11,(r12),r0");
asm|asm("ediv	$1000000000,r0,(r12),r11");
block|}
return|return
operator|(
name|rem
operator|)
return|;
block|}
end_block

begin_function
name|long
name|dsneg
parameter_list|(
name|top
parameter_list|,
name|bottom
parameter_list|)
name|long
modifier|*
name|top
decl_stmt|,
decl|*
name|bottom
decl_stmt|;
end_function

begin_block
block|{
specifier|register
name|long
modifier|*
name|p
init|=
name|top
decl_stmt|;
specifier|register
name|carry
operator|=
literal|0
expr_stmt|;
specifier|register
name|digit
expr_stmt|;
while|while
condition|(
name|p
operator|>=
name|bottom
condition|)
block|{
name|digit
operator|=
name|carry
operator|-
operator|*
name|p
expr_stmt|;
comment|/* carry = digit>> 30; is slow on 68K */
if|if
condition|(
name|digit
operator|<
literal|0
condition|)
name|carry
operator|=
operator|-
literal|2
expr_stmt|;
if|if
condition|(
name|digit
operator|&
literal|0x40000000
condition|)
name|carry
operator|+=
literal|1
expr_stmt|;
operator|*
name|p
operator|--
operator|=
name|digit
operator|&
literal|0x3fffffff
expr_stmt|;
block|}
block|}
end_block

end_unit

