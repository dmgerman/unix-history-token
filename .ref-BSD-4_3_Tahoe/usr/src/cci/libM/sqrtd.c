begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Square Root.  * New version by Les Powers (3/26/85).  * If the argument is less than zero, an error is reported.  * The single precision square root instruction "sqrtf" is  * used to generate the initial approximation.  Then two  * iterations of the Newton-Raphson method are used to improve  * the result to 56 bits.  Each iteration of the Newton-Raphson  * method uses the following replacement:  * 	B = (B + A/B)/2  * where A is the argument and B is the approximation.  * In the following assembly code, the division by two is  * accomplished by subtracting one from the exponent field.  * To subtract one from the exponent field, the hex integer value  * 0x00800000 is subtracted from the first longword of the double  * precision number in registers r0 and r1.  The hex value 0x00800000  * is equal to decimal value 8838608.  */
end_comment

begin_include
include|#
directive|include
file|<errno.h>
end_include

begin_decl_stmt
name|int
name|errno
decl_stmt|;
end_decl_stmt

begin_function
name|double
name|sqrt
parameter_list|(
name|arg
parameter_list|)
name|double
name|arg
decl_stmt|;
block|{
if|if
condition|(
name|arg
operator|>
literal|0.0
condition|)
block|{
asm|asm("	ldf	4(fp)") 		asm("	sqrtf") 		asm("	clrl	r1") 		asm("	stf	r0") 		asm("	ldd	4(fp)") 		asm("	divd	r0") 		asm("	addd	r0") 		asm("	std	r0") 		asm("	subl2	$8388608,r0") 		asm("	ldd	4(fp)") 		asm("	divd	r0") 		asm("	addd	r0") 		asm("	std	r0") 		asm("	subl2	$8388608,r0")
block|}
else|else
block|{
if|if
condition|(
name|arg
operator|<
literal|0.0
condition|)
name|errno
operator|=
name|EDOM
expr_stmt|;
return|return
operator|(
literal|0.0
operator|)
return|;
block|}
block|}
end_function

end_unit

