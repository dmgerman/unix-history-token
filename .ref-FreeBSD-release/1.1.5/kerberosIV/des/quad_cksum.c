begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * $Source: /afs/athena.mit.edu/astaff/project/kerberos/src/lib/des/RCS/quad_cksum.c,v $  * $Author: jtkohl $  *  * Copyright 1985, 1986, 1987, 1988 by the Massachusetts Institute  * of Technology.  *  * For copying and distribution information, please see the file  *<mit-copyright.h>.  *  * Quadratic Congruential Manipulation Dectection Code  *  * ref: "Message Authentication"  *		R.R. Jueneman, S. M. Matyas, C.H. Meyer  *		IEEE Communications Magazine,  *		Sept 1985 Vol 23 No 9 p 29-40  *  * This routine, part of the Athena DES library built for the Kerberos  * authentication system, calculates a manipulation detection code for  * a message.  It is a much faster alternative to the DES-checksum  * method. No guarantees are offered for its security.	Refer to the  * paper noted above for more information  *  * Implementation for 4.2bsd  * by S.P. Miller	Project Athena/MIT  */
end_comment

begin_comment
comment|/*  * Algorithm (per paper):  *		define:  *		message to be composed of n m-bit blocks X1,...,Xn  *		optional secret seed S in block X1  *		MDC in block Xn+1  *		prime modulus N  *		accumulator Z  *		initial (secret) value of accumulator C  *		N, C, and S are known at both ends  *		C and , optionally, S, are hidden from the end users  *		then  *			(read array references as subscripts over time)  *			Z[0] = c;  *			for i = 1...n  *				Z[i] = (Z[i+1] + X[i])**2 modulo N  *			X[n+1] = Z[n] = MDC  *  *		Then pick  *			N = 2**31 -1  *			m = 16  *			iterate 4 times over plaintext, also use Zn  *			from iteration j as seed for iteration j+1,  *			total MDC is then a 128 bit array of the four  *			Zn;  *  *			return the last Zn and optionally, all  *			four as output args.  *  * Modifications:  *	To inhibit brute force searches of the seed space, this  *	implementation is modified to have  *	Z	= 64 bit accumulator  *	C	= 64 bit C seed  *	N	= 2**63 - 1  *  S	= S seed is not implemented here  *	arithmetic is not quite real double integer precision, since we  *	cant get at the carry or high order results from multiply,  *	but nontheless is 64 bit arithmetic.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|lint
end_ifndef

begin_decl_stmt
specifier|static
name|char
name|rcsid_quad_cksum_c
index|[]
init|=
literal|"$Id: quad_cksum.c,v 4.13 90/01/02 13:46:34 jtkohl Exp $"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
endif|lint
end_endif

begin_include
include|#
directive|include
file|<mit-copyright.h>
end_include

begin_comment
comment|/* System include files */
end_comment

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<errno.h>
end_include

begin_comment
comment|/* Application include files */
end_comment

begin_include
include|#
directive|include
file|<des.h>
end_include

begin_include
include|#
directive|include
file|"des_internal.h"
end_include

begin_comment
comment|/* Definitions for byte swapping */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|LSBFIRST
end_ifdef

begin_ifdef
ifdef|#
directive|ifdef
name|MUSTALIGN
end_ifdef

begin_function_decl
specifier|static
name|unsigned
name|long
name|vaxtohl
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|unsigned
name|short
name|vaxtohs
parameter_list|()
function_decl|;
end_function_decl

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* ! MUSTALIGN */
end_comment

begin_define
define|#
directive|define
name|vaxtohl
parameter_list|(
name|x
parameter_list|)
value|*((unsigned long *)(x))
end_define

begin_define
define|#
directive|define
name|vaxtohs
parameter_list|(
name|x
parameter_list|)
value|*((unsigned short *)(x))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* MUSTALIGN */
end_comment

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* !LSBFIRST */
end_comment

begin_function_decl
specifier|static
name|unsigned
name|long
name|four_bytes_vax_to_nets
parameter_list|()
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|vaxtohl
parameter_list|(
name|x
parameter_list|)
value|four_bytes_vax_to_nets((char *)(x))
end_define

begin_function_decl
specifier|static
name|unsigned
name|short
name|two_bytes_vax_to_nets
parameter_list|()
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|vaxtohs
parameter_list|(
name|x
parameter_list|)
value|two_bytes_vax_to_nets((char *)(x))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Externals */
end_comment

begin_function_decl
specifier|extern
name|char
modifier|*
name|errmsg
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|int
name|errno
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|des_debug
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*** Routines ***************************************************** */
end_comment

begin_function
name|unsigned
name|long
name|des_quad_cksum
parameter_list|(
name|in
parameter_list|,
name|out
parameter_list|,
name|length
parameter_list|,
name|out_count
parameter_list|,
name|c_seed
parameter_list|)
name|des_cblock
modifier|*
name|c_seed
decl_stmt|;
comment|/* secret seed, 8 bytes */
name|unsigned
name|char
modifier|*
name|in
decl_stmt|;
comment|/* input block */
name|unsigned
name|long
modifier|*
name|out
decl_stmt|;
comment|/* optional longer output */
name|int
name|out_count
decl_stmt|;
comment|/* number of iterations */
name|long
name|length
decl_stmt|;
comment|/* original length in bytes */
block|{
comment|/*      * this routine both returns the low order of the final (last in      * time) 32bits of the checksum, and if "out" is not a null      * pointer, a longer version, up to entire 32 bytes of the      * checksum is written unto the address pointed to.      */
specifier|register
name|unsigned
name|long
name|z
decl_stmt|;
specifier|register
name|unsigned
name|long
name|z2
decl_stmt|;
specifier|register
name|unsigned
name|long
name|x
decl_stmt|;
specifier|register
name|unsigned
name|long
name|x2
decl_stmt|;
specifier|register
name|unsigned
name|char
modifier|*
name|p
decl_stmt|;
specifier|register
name|long
name|len
decl_stmt|;
specifier|register
name|int
name|i
decl_stmt|;
comment|/* use all 8 bytes of seed */
name|z
operator|=
name|vaxtohl
argument_list|(
name|c_seed
argument_list|)
expr_stmt|;
name|z2
operator|=
name|vaxtohl
argument_list|(
operator|(
name|char
operator|*
operator|)
name|c_seed
operator|+
literal|4
argument_list|)
expr_stmt|;
if|if
condition|(
name|out
operator|==
name|NULL
condition|)
name|out_count
operator|=
literal|1
expr_stmt|;
comment|/* default */
comment|/* This is repeated n times!! */
for|for
control|(
name|i
operator|=
literal|1
init|;
name|i
operator|<=
literal|4
operator|&&
name|i
operator|<=
name|out_count
condition|;
name|i
operator|++
control|)
block|{
name|len
operator|=
name|length
expr_stmt|;
name|p
operator|=
name|in
expr_stmt|;
while|while
condition|(
name|len
condition|)
block|{
if|if
condition|(
name|len
operator|>
literal|1
condition|)
block|{
name|x
operator|=
operator|(
name|z
operator|+
name|vaxtohs
argument_list|(
name|p
argument_list|)
operator|)
expr_stmt|;
name|p
operator|+=
literal|2
expr_stmt|;
name|len
operator|-=
literal|2
expr_stmt|;
block|}
else|else
block|{
name|x
operator|=
operator|(
name|z
operator|+
operator|*
operator|(
name|char
operator|*
operator|)
name|p
operator|++
operator|)
expr_stmt|;
name|len
operator|=
literal|0
expr_stmt|;
block|}
name|x2
operator|=
name|z2
expr_stmt|;
name|z
operator|=
operator|(
operator|(
name|x
operator|*
name|x
operator|)
operator|+
operator|(
name|x2
operator|*
name|x2
operator|)
operator|)
operator|%
literal|0x7fffffff
expr_stmt|;
name|z2
operator|=
operator|(
name|x
operator|*
operator|(
name|x2
operator|+
literal|83653421
operator|)
operator|)
operator|%
literal|0x7fffffff
expr_stmt|;
comment|/* modulo */
if|if
condition|(
name|des_debug
operator|&
literal|8
condition|)
name|printf
argument_list|(
literal|"%d %d\n"
argument_list|,
name|z
argument_list|,
name|z2
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
name|out
operator|!=
name|NULL
condition|)
block|{
operator|*
name|out
operator|++
operator|=
name|z
expr_stmt|;
operator|*
name|out
operator|++
operator|=
name|z2
expr_stmt|;
block|}
block|}
comment|/* return final z value as 32 bit version of checksum */
return|return
name|z
return|;
block|}
end_function

begin_ifdef
ifdef|#
directive|ifdef
name|MSBFIRST
end_ifdef

begin_function
specifier|static
name|unsigned
name|short
name|two_bytes_vax_to_nets
parameter_list|(
name|p
parameter_list|)
name|char
modifier|*
name|p
decl_stmt|;
block|{
union|union
block|{
name|char
name|pieces
index|[
literal|2
index|]
decl_stmt|;
name|unsigned
name|short
name|result
decl_stmt|;
block|}
name|short_conv
union|;
name|short_conv
operator|.
name|pieces
index|[
literal|0
index|]
operator|=
name|p
index|[
literal|1
index|]
expr_stmt|;
name|short_conv
operator|.
name|pieces
index|[
literal|1
index|]
operator|=
name|p
index|[
literal|0
index|]
expr_stmt|;
return|return
operator|(
name|short_conv
operator|.
name|result
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|unsigned
name|long
name|four_bytes_vax_to_nets
parameter_list|(
name|p
parameter_list|)
name|char
modifier|*
name|p
decl_stmt|;
block|{
specifier|static
union|union
block|{
name|char
name|pieces
index|[
literal|4
index|]
decl_stmt|;
name|unsigned
name|long
name|result
decl_stmt|;
block|}
name|long_conv
union|;
name|long_conv
operator|.
name|pieces
index|[
literal|0
index|]
operator|=
name|p
index|[
literal|3
index|]
expr_stmt|;
name|long_conv
operator|.
name|pieces
index|[
literal|1
index|]
operator|=
name|p
index|[
literal|2
index|]
expr_stmt|;
name|long_conv
operator|.
name|pieces
index|[
literal|2
index|]
operator|=
name|p
index|[
literal|1
index|]
expr_stmt|;
name|long_conv
operator|.
name|pieces
index|[
literal|3
index|]
operator|=
name|p
index|[
literal|0
index|]
expr_stmt|;
return|return
operator|(
name|long_conv
operator|.
name|result
operator|)
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|LSBFIRST
end_ifdef

begin_ifdef
ifdef|#
directive|ifdef
name|MUSTALIGN
end_ifdef

begin_function
specifier|static
name|unsigned
name|long
name|vaxtohl
parameter_list|(
name|x
parameter_list|)
name|char
modifier|*
name|x
decl_stmt|;
block|{
name|unsigned
name|long
name|val
decl_stmt|;
name|bcopy
argument_list|(
name|x
argument_list|,
operator|(
name|char
operator|*
operator|)
operator|&
name|val
argument_list|,
sizeof|sizeof
argument_list|(
name|val
argument_list|)
argument_list|)
expr_stmt|;
return|return
operator|(
name|val
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|unsigned
name|short
name|vaxtohs
parameter_list|(
name|x
parameter_list|)
name|char
modifier|*
name|x
decl_stmt|;
block|{
name|unsigned
name|short
name|val
decl_stmt|;
name|bcopy
argument_list|(
name|x
argument_list|,
operator|(
name|char
operator|*
operator|)
operator|&
name|val
argument_list|,
sizeof|sizeof
argument_list|(
name|val
argument_list|)
argument_list|)
expr_stmt|;
return|return
operator|(
name|val
operator|)
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* MUSTALIGN */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* LSBFIRST */
end_comment

end_unit

