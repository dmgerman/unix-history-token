begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  *	@(#)FP.h	5.1 (Berkeley) 11/3/86  *  * General definitions of the floating point stuff on Power 6/32.  * The floating point format definition is:  *  *		S    (exp-128)  *	    (-1)  * 2	       * F  *  *	Where exp is the exponent field and F is the binary  *	mantissa following it, including the hidden bit.  *	The hidden bit actually is 1/2, so F is known to  *	satisfy the range:  *		1/2<= F< 1  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|unsigned
name|sign
range|:
literal|1
decl_stmt|;
name|unsigned
name|exponent
range|:
literal|8
decl_stmt|;
name|unsigned
name|mantissa
range|:
literal|23
decl_stmt|;
block|}
name|sp_format
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|unsigned
name|sign
range|:
literal|1
decl_stmt|;
name|unsigned
name|exponent
range|:
literal|8
decl_stmt|;
name|unsigned
name|mantissa
range|:
literal|23
decl_stmt|;
name|unsigned
name|mantissa_lst
decl_stmt|;
block|}
name|dp_format
typedef|;
end_typedef

begin_define
define|#
directive|define
name|EXP_BIAS
value|128
end_define

begin_comment
comment|/* Exponent bias */
end_comment

begin_define
define|#
directive|define
name|SIGN_BIT
value|0x80000000
end_define

begin_comment
comment|/* S bit mask */
end_comment

end_unit

