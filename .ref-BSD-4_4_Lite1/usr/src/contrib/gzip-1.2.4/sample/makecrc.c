begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Not copyrighted 1990 Mark Adler */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|lint
end_ifndef

begin_decl_stmt
specifier|static
name|char
name|rcsid
index|[]
init|=
literal|"$Id: makecrc.c,v 0.6 1993/05/28 07:42:59 jloup Exp $"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_function
name|main
parameter_list|()
comment|/*   Generate a table for a byte-wise 32-bit CRC calculation on the polynomial:   x^32+x^26+x^23+x^22+x^16+x^12+x^11+x^10+x^8+x^7+x^5+x^4+x^2+x+1.    Polynomials over GF(2) are represented in binary, one bit per coefficient,   with the lowest powers in the most significant bit.  Then adding polynomials   is just exclusive-or, and multiplying a polynomial by x is a right shift by   one.  If we call the above polynomial p, and represent a byte as the   polynomial q, also with the lowest power in the most significant bit (so the   byte 0xb1 is the polynomial x^7+x^3+x+1), then the CRC is (q*x^32) mod p,   where a mod b means the remainder after dividing a by b.    This calculation is done using the shift-register method of multiplying and   taking the remainder.  The register is initialized to zero, and for each   incoming bit, x^32 is added mod p to the register if the bit is a one (where   x^32 mod p is p+x^32 = x^26+...+1), and the register is multiplied mod p by   x (which is shifting right by one and adding x^32 mod p if the bit shifted   out is a one).  We start with the highest power (least significant bit) of   q and repeat for all eight bits of q.    The table is simply the CRC of all possible eight bit values.  This is all   the information needed to generate CRC's on data a byte at a time for all   combinations of CRC register values and incoming bytes.  The table is   written to stdout as 256 long hexadecimal values in C language format. */
block|{
name|unsigned
name|long
name|c
decl_stmt|;
comment|/* crc shift register */
name|unsigned
name|long
name|e
decl_stmt|;
comment|/* polynomial exclusive-or pattern */
name|int
name|i
decl_stmt|;
comment|/* counter for all possible eight bit values */
name|int
name|k
decl_stmt|;
comment|/* byte being shifted into crc apparatus */
comment|/* terms of polynomial defining this crc (except x^32): */
specifier|static
name|int
name|p
index|[]
init|=
block|{
literal|0
block|,
literal|1
block|,
literal|2
block|,
literal|4
block|,
literal|5
block|,
literal|7
block|,
literal|8
block|,
literal|10
block|,
literal|11
block|,
literal|12
block|,
literal|16
block|,
literal|22
block|,
literal|23
block|,
literal|26
block|}
decl_stmt|;
comment|/* Make exclusive-or pattern from polynomial (0xedb88320) */
name|e
operator|=
literal|0
expr_stmt|;
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
sizeof|sizeof
argument_list|(
name|p
argument_list|)
operator|/
sizeof|sizeof
argument_list|(
name|int
argument_list|)
condition|;
name|i
operator|++
control|)
name|e
operator||=
literal|1L
operator|<<
operator|(
literal|31
operator|-
name|p
index|[
name|i
index|]
operator|)
expr_stmt|;
comment|/* Compute and print table of CRC's, five per line */
name|printf
argument_list|(
literal|"  0x00000000L"
argument_list|)
expr_stmt|;
for|for
control|(
name|i
operator|=
literal|1
init|;
name|i
operator|<
literal|256
condition|;
name|i
operator|++
control|)
block|{
name|c
operator|=
name|i
expr_stmt|;
comment|/* The idea to initialize the register with the byte instead of      * zero was stolen from Haruhiko Okumura's ar002      */
for|for
control|(
name|k
operator|=
literal|8
init|;
name|k
condition|;
name|k
operator|--
control|)
name|c
operator|=
name|c
operator|&
literal|1
condition|?
operator|(
name|c
operator|>>
literal|1
operator|)
operator|^
name|e
else|:
name|c
operator|>>
literal|1
expr_stmt|;
name|printf
argument_list|(
name|i
operator|%
literal|5
condition|?
literal|", 0x%08lxL"
else|:
literal|",\n  0x%08lxL"
argument_list|,
name|c
argument_list|)
expr_stmt|;
block|}
name|putchar
argument_list|(
literal|'\n'
argument_list|)
expr_stmt|;
return|return
literal|0
return|;
block|}
end_function

end_unit

