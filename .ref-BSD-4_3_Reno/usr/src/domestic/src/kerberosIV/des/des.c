begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * $Source: /mit/kerberos/src/lib/des/RCS/des.c,v $  * $Author: jtkohl $  *  * Copyright 1985, 1986, 1987, 1988 by the Massachusetts Institute  * of Technology.  *  * For copying and distribution information, please see the file  *<mit-copyright.h>.  *  * These routines perform encryption and decryption using the DES  * private key algorithm, or else a subset of it-- fewer inner loops.  * (AUTH_DES_ITER defaults to 16, may be less.)  *  * Under U.S. law, this software may not be exported outside the US  * without license from the U.S. Commerce department.  *  * The key schedule is passed as an arg, as well as the cleartext or  * ciphertext.  *  * All registers labeled imply Vax using the Ultrix or 4.2bsd  * compiler.  *  *  *	NOTE:  bit and byte numbering:  *			DES algorithm is defined in terms of bits of L  *			followed by bits of R.  *		bit 0  ==> lsb of L  *		bit 63 ==> msb of R  *  * Always work in register pairs, FROM L1,R1 TO L2,R2 to make  * bookkeeping easier.  *  * originally written by Steve Miller, MIT Project Athena  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|lint
end_ifndef

begin_decl_stmt
specifier|static
name|char
name|rcsid_des_c
index|[]
init|=
literal|"$Header: des.c,v 4.13 89/01/21 16:49:55 jtkohl Exp $"
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

begin_include
include|#
directive|include
file|<stdio.h>
end_include

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

begin_include
include|#
directive|include
file|"s_table.h"
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|BIG
end_ifdef

begin_include
include|#
directive|include
file|"p_table.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|DEBUG
end_ifdef

begin_define
define|#
directive|define
name|DBG_PRINT
parameter_list|(
name|s
parameter_list|)
value|if (des_debug& 2) \     des_debug_print(s,i,L1&0xffff,(L1>>16)&0xffff, \ 		R1&0xffff,(R1>>16)&0xffff)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|DBG_PRINT
parameter_list|(
name|s
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
specifier|extern
name|int
name|des_debug
decl_stmt|;
end_decl_stmt

begin_extern
extern|extern des_cblock_print_file (
end_extern

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_extern
extern|extern des_debug_print (
end_extern

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_function
name|int
name|des_ecb_encrypt
parameter_list|(
name|clear
parameter_list|,
name|cipher
parameter_list|,
name|schedule
parameter_list|,
name|encrypt
parameter_list|)
name|unsigned
name|long
modifier|*
name|clear
decl_stmt|;
name|unsigned
name|long
modifier|*
name|cipher
decl_stmt|;
name|int
name|encrypt
decl_stmt|;
comment|/* 0 ==> decrypt, else encrypt */
specifier|register
name|des_key_schedule
name|schedule
decl_stmt|;
comment|/* r11 */
block|{
comment|/* better pass 8 bytes, length not checked here */
specifier|register
name|unsigned
name|long
name|R1
decl_stmt|,
name|L1
decl_stmt|;
comment|/* R1 = r10, L1 = r9 */
specifier|register
name|unsigned
name|long
name|R2
decl_stmt|,
name|L2
decl_stmt|;
comment|/* R2 = r8, L2 = r7 */
name|long
name|i
decl_stmt|;
comment|/* one more registers left on VAX, see below P_temp_p */
ifdef|#
directive|ifdef
name|BITS16
name|sbox_in_16_a
name|S_in_16_a
decl_stmt|;
name|sbox_in_16_b
name|S_in_16_b
decl_stmt|;
name|sbox_in_16_c
name|S_in_16_c
decl_stmt|;
name|unsigned
name|int
modifier|*
name|S_in_a_16_p
init|=
operator|(
name|unsigned
name|int
operator|*
operator|)
operator|&
name|S_in_16_a
decl_stmt|;
name|unsigned
name|int
modifier|*
name|S_in_b_16_p
init|=
operator|(
name|unsigned
name|int
operator|*
operator|)
operator|&
name|S_in_16_b
decl_stmt|;
name|unsigned
name|int
modifier|*
name|S_in_c_16_p
init|=
operator|(
name|unsigned
name|int
operator|*
operator|)
operator|&
name|S_in_16_c
decl_stmt|;
endif|#
directive|endif
ifndef|#
directive|ifndef
name|BITS32
ifndef|#
directive|ifndef
name|BITS16
name|dunno
name|how
name|to
do|do
name|this
name|machine
name|type
decl_stmt|,
name|you
name|lose
decl_stmt|;
endif|#
directive|endif
endif|#
directive|endif
do|unsigned long P_temp;     register unsigned char *P_temp_p = (unsigned char *
block|)
function|& P_temp;
end_function

begin_ifdef
ifdef|#
directive|ifdef
name|BITS16
end_ifdef

begin_decl_stmt
name|sbox_out
name|S_out
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|unsigned
name|long
modifier|*
name|S_out_p
init|=
operator|(
name|unsigned
name|long
operator|*
operator|)
operator|&
name|S_out
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
name|unsigned
name|long
name|R_save
decl_stmt|,
name|L_save
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|DEBUG
end_ifdef

begin_decl_stmt
name|unsigned
name|long
name|dbg_tmp
index|[
literal|2
index|]
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*      * Use L1,R1 and L2,R2 as two sets of "64-bit" registers always      * work from L1,R1 input to L2,R2 output; initialize the cleartext      * into registers.      */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|MUSTALIGN
end_ifdef

begin_ifdef
ifdef|#
directive|ifdef
name|DEBUG
end_ifdef

begin_comment
comment|/*      * If the alignment is wrong, the programmer really screwed up --      * we aren't even getting the right data type.  His problem.  Keep      * this code for debugging.      */
end_comment

begin_comment
comment|/* Make sure schedule is ok */
end_comment

begin_if
if|if
condition|(
operator|(
name|long
operator|)
name|schedule
operator|&
literal|3
condition|)
block|{
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"des.c schedule arg pointer not aligned\n"
argument_list|)
expr_stmt|;
name|abort
argument_list|()
expr_stmt|;
block|}
end_if

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|if
condition|(
operator|(
name|long
operator|)
name|clear
operator|&
literal|3
condition|)
block|{
name|bcopy
argument_list|(
operator|(
name|char
operator|*
operator|)
name|clear
operator|++
argument_list|,
operator|(
name|char
operator|*
operator|)
operator|&
name|L_save
argument_list|,
sizeof|sizeof
argument_list|(
name|L_save
argument_list|)
argument_list|)
expr_stmt|;
name|bcopy
argument_list|(
operator|(
name|char
operator|*
operator|)
name|clear
argument_list|,
operator|(
name|char
operator|*
operator|)
operator|&
name|R_save
argument_list|,
sizeof|sizeof
argument_list|(
name|R_save
argument_list|)
argument_list|)
expr_stmt|;
name|L1
operator|=
name|L_save
expr_stmt|;
name|R1
operator|=
name|R_save
expr_stmt|;
block|}
else|else
endif|#
directive|endif
block|{
if|if
condition|(
name|clear
condition|)
name|L1
operator|=
operator|*
name|clear
operator|++
expr_stmt|;
else|else
name|L1
operator|=
name|NULL
expr_stmt|;
if|if
condition|(
name|clear
condition|)
name|R1
operator|=
operator|*
name|clear
expr_stmt|;
else|else
name|R1
operator|=
name|NULL
expr_stmt|;
block|}
end_if

begin_ifdef
ifdef|#
directive|ifdef
name|DEBUG
end_ifdef

begin_if
if|if
condition|(
name|des_debug
operator|&
literal|2
condition|)
block|{
name|printf
argument_list|(
literal|"All values printed from low byte (bit 0)"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|" --> high byte (bit 63)\n"
argument_list|)
expr_stmt|;
name|i
operator|=
literal|0
expr_stmt|;
name|dbg_tmp
index|[
literal|0
index|]
operator|=
name|L1
expr_stmt|;
name|dbg_tmp
index|[
literal|1
index|]
operator|=
name|R1
expr_stmt|;
name|printf
argument_list|(
literal|"iter = %2d  before IP\n\t\tL1 R1 = "
argument_list|,
name|i
argument_list|)
expr_stmt|;
name|des_cblock_print_file
argument_list|(
name|dbg_tmp
argument_list|,
name|stdout
argument_list|)
expr_stmt|;
block|}
end_if

begin_expr_stmt
name|DBG_PRINT
argument_list|(
literal|"before IP"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*   IP_start:*/
end_comment

begin_comment
comment|/* all the Initial Permutation code is in the include file */
end_comment

begin_include
include|#
directive|include
file|"ip.c"
end_include

begin_comment
comment|/* reset input to L1,R1 */
end_comment

begin_expr_stmt
name|L1
operator|=
name|L2
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|R1
operator|=
name|R2
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* iterate through the inner loop */
end_comment

begin_for
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<=
operator|(
name|AUTH_DES_ITER
operator|-
literal|1
operator|)
condition|;
name|i
operator|++
control|)
block|{
ifdef|#
directive|ifdef
name|DEBUG
if|if
condition|(
name|des_debug
operator|&
literal|2
condition|)
block|{
name|dbg_tmp
index|[
literal|0
index|]
operator|=
name|L1
expr_stmt|;
name|dbg_tmp
index|[
literal|1
index|]
operator|=
name|R1
expr_stmt|;
name|printf
argument_list|(
literal|"iter = %2d	start loop\n\t\tL1 R1 = "
argument_list|,
name|i
argument_list|)
expr_stmt|;
name|des_cblock_print_file
argument_list|(
name|dbg_tmp
argument_list|,
name|stdout
argument_list|)
expr_stmt|;
name|DBG_PRINT
argument_list|(
literal|"start loop"
argument_list|)
expr_stmt|;
block|}
endif|#
directive|endif
name|R_save
operator|=
name|R1
expr_stmt|;
name|L_save
operator|=
name|L1
expr_stmt|;
comment|/*   E_start:*/
comment|/* apply the E permutation from R1 to L2, R2 */
ifndef|#
directive|ifndef
name|VAXASM
ifdef|#
directive|ifdef
name|SLOW_E
include|#
directive|include
file|"e.c"
else|#
directive|else
comment|/* Bill's fast E */
name|L2
operator|=
operator|(
name|R1
operator|<<
literal|1
operator|)
expr_stmt|;
if|if
condition|(
name|R1
operator|&
operator|(
literal|1
operator|<<
literal|31
operator|)
condition|)
name|L2
operator||=
literal|1
operator|<<
literal|0
expr_stmt|;
name|L2
operator|&=
literal|077
expr_stmt|;
name|L2
operator||=
operator|(
name|R1
operator|<<
literal|3
operator|)
operator|&
literal|07700
expr_stmt|;
name|L2
operator||=
operator|(
name|R1
operator|<<
literal|5
operator|)
operator|&
literal|0770000
expr_stmt|;
name|L2
operator||=
operator|(
name|R1
operator|<<
literal|7
operator|)
operator|&
literal|077000000
expr_stmt|;
name|L2
operator||=
operator|(
name|R1
operator|<<
literal|9
operator|)
operator|&
literal|07700000000
expr_stmt|;
name|L2
operator||=
operator|(
name|R1
operator|<<
literal|11
operator|)
operator|&
literal|030000000000
expr_stmt|;
comment|/* now from right to right */
name|R2
operator|=
operator|(
operator|(
name|R1
operator|>>
literal|17
operator|)
operator|&
literal|0176000
operator|)
expr_stmt|;
if|if
condition|(
name|R1
operator|&
operator|(
literal|1
operator|<<
literal|0
operator|)
condition|)
name|R2
operator||=
literal|1
operator|<<
literal|15
expr_stmt|;
name|R2
operator||=
operator|(
operator|(
name|R1
operator|>>
literal|21
operator|)
operator|&
literal|017
operator|)
expr_stmt|;
name|R2
operator||=
operator|(
operator|(
name|R1
operator|>>
literal|19
operator|)
operator|&
literal|01760
operator|)
expr_stmt|;
endif|#
directive|endif
comment|/* SLOW_E */
else|#
directive|else
comment|/* VAXASM */
comment|/* E operations */
comment|/* right to left */
asm|asm("	rotl	$1,r10,r7");
name|L2
operator|&=
literal|077
expr_stmt|;
name|L2
operator||=
operator|(
name|R1
operator|<<
literal|3
operator|)
operator|&
literal|07700
expr_stmt|;
name|L2
operator||=
operator|(
name|R1
operator|<<
literal|5
operator|)
operator|&
literal|0770000
expr_stmt|;
name|L2
operator||=
operator|(
name|R1
operator|<<
literal|7
operator|)
operator|&
literal|077000000
expr_stmt|;
name|L2
operator||=
operator|(
name|R1
operator|<<
literal|9
operator|)
operator|&
literal|07700000000
expr_stmt|;
name|L2
operator||=
operator|(
name|R1
operator|<<
literal|11
operator|)
operator|&
literal|030000000000
expr_stmt|;
asm|asm("	rotl	$-17,r10,r8");
name|R2
operator|&=
literal|0176000
expr_stmt|;
asm|asm("	rotl	$-21,r10,r0");
asm|asm("	bicl2	$-16,r0");
asm|asm("  bisl2	r0,r8");
asm|asm("	rotl	$-19,r10,r0");
asm|asm("	bicl2	$-1009,r0");
asm|asm("  bisl2	r0,r8");
endif|#
directive|endif
comment|/* reset input to L1,R1 */
name|L1
operator|=
name|L2
expr_stmt|;
name|R1
operator|=
name|R2
expr_stmt|;
ifdef|#
directive|ifdef
name|DEBUG
if|if
condition|(
name|des_debug
operator|&
literal|2
condition|)
block|{
name|dbg_tmp
index|[
literal|0
index|]
operator|=
name|L1
expr_stmt|;
name|dbg_tmp
index|[
literal|1
index|]
operator|=
name|R1
expr_stmt|;
name|DBG_PRINT
argument_list|(
literal|"after e"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"iter = %2d	after e\n\t\tL1 R1 = "
argument_list|,
name|i
argument_list|)
expr_stmt|;
name|des_cblock_print_file
argument_list|(
name|dbg_tmp
argument_list|,
name|stdout
argument_list|)
expr_stmt|;
block|}
endif|#
directive|endif
comment|/*   XOR_start:*/
comment|/* 	 * XOR with the key schedule, "schedule" 	 * 	 * If this is an encryption operation, use schedule[i], 	 * otherwise use schedule [AUTH_DES_ITER-i-1] 	 * 	 * First XOR left half. 	 */
if|if
condition|(
name|encrypt
condition|)
block|{
name|L1
operator|^=
operator|*
operator|(
operator|(
operator|(
name|unsigned
name|long
operator|*
operator|)
operator|&
name|schedule
index|[
name|i
index|]
operator|)
operator|+
literal|0
operator|)
expr_stmt|;
comment|/* now right half */
name|R1
operator|^=
operator|*
operator|(
operator|(
operator|(
name|unsigned
name|long
operator|*
operator|)
operator|&
name|schedule
index|[
name|i
index|]
operator|)
operator|+
literal|1
operator|)
expr_stmt|;
block|}
else|else
block|{
name|L1
operator|^=
operator|*
operator|(
operator|(
operator|(
name|unsigned
name|long
operator|*
operator|)
operator|&
name|schedule
index|[
name|AUTH_DES_ITER
operator|-
name|i
operator|-
literal|1
index|]
operator|)
operator|+
literal|0
operator|)
expr_stmt|;
comment|/* now right half */
name|R1
operator|^=
operator|*
operator|(
operator|(
operator|(
name|unsigned
name|long
operator|*
operator|)
operator|&
name|schedule
index|[
name|AUTH_DES_ITER
operator|-
name|i
operator|-
literal|1
index|]
operator|)
operator|+
literal|1
operator|)
expr_stmt|;
block|}
comment|/* dont have to reset input to L1, R1 */
ifdef|#
directive|ifdef
name|DEBUG
if|if
condition|(
name|des_debug
operator|&
literal|2
condition|)
block|{
name|dbg_tmp
index|[
literal|0
index|]
operator|=
name|L1
expr_stmt|;
name|dbg_tmp
index|[
literal|1
index|]
operator|=
name|R1
expr_stmt|;
name|DBG_PRINT
argument_list|(
literal|"after xor"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"iter = %2d	after xor\n\t\tL1 R1 ="
argument_list|,
name|i
argument_list|)
expr_stmt|;
name|des_cblock_print_file
argument_list|(
name|dbg_tmp
argument_list|,
name|stdout
argument_list|)
expr_stmt|;
block|}
endif|#
directive|endif
comment|/*   S_start:*/
comment|/* apply the S selection from L1, R1 to R2 */
ifdef|#
directive|ifdef
name|notdef
include|#
directive|include
file|"s.c"
endif|#
directive|endif
comment|/* S operations , cant use registers for bit field stuff */
comment|/* from S_in to S_out */
ifdef|#
directive|ifdef
name|BITS16
operator|*
name|S_in_a_16_p
operator|=
name|L1
operator|&
literal|0xffff
expr_stmt|;
operator|*
name|S_in_b_16_p
operator|=
operator|(
name|L1
operator|>>
literal|16
operator|)
operator|&
literal|0xffff
expr_stmt|;
operator|*
name|S_in_c_16_p
operator|=
name|R1
operator|&
literal|0xffff
expr_stmt|;
operator|(
operator|*
operator|(
name|unsigned
name|long
operator|*
operator|)
operator|&
name|S_out
operator|)
operator|=
operator|(
name|unsigned
operator|)
name|S_adj
index|[
literal|0
index|]
index|[
name|S_in_16_a
operator|.
name|b0
index|]
expr_stmt|;
name|S_out
operator|.
name|b1
operator|=
operator|(
name|unsigned
operator|)
name|S_adj
index|[
literal|1
index|]
index|[
name|S_in_16_a
operator|.
name|b1
index|]
expr_stmt|;
comment|/* b2 spans two words */
name|S_out
operator|.
name|b2
operator|=
operator|(
name|unsigned
operator|)
name|S_adj
index|[
literal|2
index|]
index|[
operator|(
name|unsigned
operator|)
name|S_in_16_a
operator|.
name|b2
operator|+
operator|(
operator|(
operator|(
name|unsigned
operator|)
name|S_in_16_b
operator|.
name|b2
operator|)
operator|<<
literal|4
operator|)
index|]
expr_stmt|;
name|S_out
operator|.
name|b3
operator|=
operator|(
name|unsigned
operator|)
name|S_adj
index|[
literal|3
index|]
index|[
name|S_in_16_b
operator|.
name|b3
index|]
expr_stmt|;
name|S_out
operator|.
name|b4
operator|=
operator|(
name|unsigned
operator|)
name|S_adj
index|[
literal|4
index|]
index|[
name|S_in_16_b
operator|.
name|b4
index|]
expr_stmt|;
comment|/* b5 spans both parts */
name|S_out
operator|.
name|b5
operator|=
operator|(
name|unsigned
operator|)
name|S_adj
index|[
literal|5
index|]
index|[
operator|(
name|unsigned
operator|)
name|S_in_16_b
operator|.
name|b5
operator|+
operator|(
operator|(
operator|(
name|unsigned
operator|)
name|S_in_16_c
operator|.
name|b5
operator|)
operator|<<
literal|2
operator|)
index|]
expr_stmt|;
name|S_out
operator|.
name|b6
operator|=
operator|(
name|unsigned
operator|)
name|S_adj
index|[
literal|6
index|]
index|[
name|S_in_16_c
operator|.
name|b6
index|]
expr_stmt|;
name|S_out
operator|.
name|b7
operator|=
operator|(
name|unsigned
operator|)
name|S_adj
index|[
literal|7
index|]
index|[
name|S_in_16_c
operator|.
name|b7
index|]
expr_stmt|;
name|R1
operator|=
operator|*
name|S_out_p
expr_stmt|;
else|#
directive|else
comment|/* is a 32 bit sys */
ifndef|#
directive|ifndef
name|VAXASM
name|R2
operator|=
operator|(
name|unsigned
operator|)
name|S_adj
index|[
literal|0
index|]
index|[
name|L1
operator|&
literal|077
index|]
expr_stmt|;
name|L2
operator|=
operator|(
name|unsigned
operator|)
name|S_adj
index|[
literal|1
index|]
index|[
operator|(
name|L1
operator|>>
literal|6
operator|)
operator|&
literal|077
index|]
expr_stmt|;
name|R2
operator||=
operator|(
name|L2
operator|<<
literal|4
operator|)
expr_stmt|;
name|L2
operator|=
operator|(
name|unsigned
operator|)
name|S_adj
index|[
literal|2
index|]
index|[
operator|(
name|L1
operator|>>
literal|12
operator|)
operator|&
literal|077
index|]
expr_stmt|;
name|R2
operator||=
operator|(
name|L2
operator|<<
literal|8
operator|)
expr_stmt|;
name|L2
operator|=
operator|(
name|unsigned
operator|)
name|S_adj
index|[
literal|3
index|]
index|[
operator|(
name|L1
operator|>>
literal|18
operator|)
operator|&
literal|077
index|]
expr_stmt|;
name|R2
operator||=
operator|(
name|L2
operator|<<
literal|12
operator|)
expr_stmt|;
name|L2
operator|=
operator|(
name|unsigned
operator|)
name|S_adj
index|[
literal|4
index|]
index|[
operator|(
name|L1
operator|>>
literal|24
operator|)
operator|&
literal|077
index|]
expr_stmt|;
name|R2
operator||=
operator|(
name|L2
operator|<<
literal|16
operator|)
expr_stmt|;
comment|/* b5 spans both parts */
name|L2
operator|=
operator|(
name|unsigned
operator|)
name|S_adj
index|[
literal|5
index|]
index|[
call|(
name|unsigned
call|)
argument_list|(
operator|(
name|L1
operator|>>
literal|30
operator|)
operator|&
literal|03
argument_list|)
operator|+
operator|(
operator|(
name|R1
operator|&
literal|017
operator|)
operator|<<
literal|2
operator|)
index|]
expr_stmt|;
name|R2
operator||=
operator|(
name|L2
operator|<<
literal|20
operator|)
expr_stmt|;
name|L2
operator|=
operator|(
name|unsigned
operator|)
name|S_adj
index|[
literal|6
index|]
index|[
operator|(
name|R1
operator|>>
literal|4
operator|)
operator|&
literal|077
index|]
expr_stmt|;
name|R2
operator||=
operator|(
name|L2
operator|<<
literal|24
operator|)
expr_stmt|;
name|L2
operator|=
operator|(
name|unsigned
operator|)
name|S_adj
index|[
literal|7
index|]
index|[
operator|(
name|R1
operator|>>
literal|10
operator|)
operator|&
literal|077
index|]
expr_stmt|;
name|R1
operator|=
name|R2
operator||
operator|(
name|L2
operator|<<
literal|28
operator|)
expr_stmt|;
comment|/* reset input to L1, R1 */
else|#
directive|else
comment|/* vaxasm */
comment|/* 	 * this is the c code produced above, with 	 * extzv replaced by rotl 	 */
asm|asm("bicl3	$-64,r9,r0");
asm|asm("movzbl	_S_adj[r0],r8");
asm|asm("rotl	$-6,r9,r0");
asm|asm("bicl2	$-64,r0");
asm|asm("movzbl	_S_adj+64[r0],r7");
asm|asm("ashl	$4,r7,r0");
asm|asm("bisl2	r0,r8");
asm|asm("rotl	$-12,r9,r0");
asm|asm("bicl2	$-64,r0");
asm|asm("movzbl	_S_adj+128[r0],r7");
asm|asm("ashl	$8,r7,r0");
asm|asm("bisl2	r0,r8");
asm|asm("rotl	$-18,r9,r0");
asm|asm("bicl2	$-64,r0");
asm|asm("movzbl	_S_adj+192[r0],r7");
asm|asm("ashl	$12,r7,r0");
asm|asm("bisl2	r0,r8");
asm|asm("rotl	$-24,r9,r0");
asm|asm("bicl2	$-64,r0");
asm|asm("movzbl	_S_adj+256[r0],r7");
asm|asm("ashl	$16,r7,r0");
asm|asm("bisl2	r0,r8");
asm|asm("rotl	$-30,r9,r0");
asm|asm("bicl2	$-4,r0");
asm|asm("bicl3	$-16,r10,r1");
asm|asm("ashl	$2,r1,r1");
asm|asm("addl2	r1,r0");
asm|asm("movzbl	_S_adj+320[r0],r7");
asm|asm("ashl	$20,r7,r0");
asm|asm("bisl2	r0,r8");
asm|asm("rotl	$-4,r10,r0");
asm|asm("bicl2	$-64,r0");
asm|asm("movzbl	_S_adj+384[r0],r7");
asm|asm("ashl	$24,r7,r0");
asm|asm("bisl2	r0,r8");
asm|asm("rotl	$-10,r10,r0");
asm|asm("bicl2	$-64,r0");
asm|asm("movzbl	_S_adj+448[r0],r7");
asm|asm("ashl	$28,r7,r0");
asm|asm("bisl2	r8,r0");
asm|asm("movl	r0,r10");
endif|#
directive|endif
comment|/* vaxasm */
endif|#
directive|endif
ifdef|#
directive|ifdef
name|DEBUG
if|if
condition|(
name|des_debug
operator|&
literal|2
condition|)
block|{
name|dbg_tmp
index|[
literal|0
index|]
operator|=
name|L1
expr_stmt|;
name|dbg_tmp
index|[
literal|1
index|]
operator|=
name|R1
expr_stmt|;
name|DBG_PRINT
argument_list|(
literal|"after s"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"iter = %2d	after s\n\t\tL1 R1 = "
argument_list|,
name|i
argument_list|)
expr_stmt|;
name|des_cblock_print_file
argument_list|(
name|dbg_tmp
argument_list|,
name|stdout
argument_list|)
expr_stmt|;
block|}
endif|#
directive|endif
comment|/*   P_start:*/
comment|/* and then the p permutation from R1 into R2 */
include|#
directive|include
file|"p.c"
comment|/* reset the input to L1, R1 */
name|R1
operator|=
name|R2
expr_stmt|;
ifdef|#
directive|ifdef
name|DEBUG
if|if
condition|(
name|des_debug
operator|&
literal|2
condition|)
block|{
name|dbg_tmp
index|[
literal|0
index|]
operator|=
name|L1
expr_stmt|;
name|dbg_tmp
index|[
literal|1
index|]
operator|=
name|R1
expr_stmt|;
name|DBG_PRINT
argument_list|(
literal|"after p"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"iter = %2d	after p\n\t\tL1 R1 = "
argument_list|,
name|i
argument_list|)
expr_stmt|;
name|des_cblock_print_file
argument_list|(
name|dbg_tmp
argument_list|,
name|stdout
argument_list|)
expr_stmt|;
block|}
endif|#
directive|endif
comment|/* R1 is the output value from the f() */
comment|/* move R[iter] to L[iter+1] */
comment|/*   XOR_2_start:*/
name|L1
operator|=
name|R_save
expr_stmt|;
comment|/* xor with left */
name|R1
operator|=
name|L_save
operator|^
name|R1
expr_stmt|;
comment|/* reset the input */
block|}
end_for

begin_comment
comment|/* flip left and right before final permutation */
end_comment

begin_expr_stmt
name|L2
operator|=
name|R1
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* flip */
end_comment

begin_expr_stmt
name|R2
operator|=
name|L1
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* reset the input */
end_comment

begin_expr_stmt
name|L1
operator|=
name|L2
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|R1
operator|=
name|R2
expr_stmt|;
end_expr_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|DEBUG
end_ifdef

begin_if
if|if
condition|(
name|des_debug
operator|&
literal|2
condition|)
block|{
name|dbg_tmp
index|[
literal|0
index|]
operator|=
name|L1
expr_stmt|;
name|dbg_tmp
index|[
literal|1
index|]
operator|=
name|R1
expr_stmt|;
name|DBG_PRINT
argument_list|(
literal|"before FP"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"iter = %2d  before FP\n\t\tL1 R1 = "
argument_list|,
name|i
argument_list|)
expr_stmt|;
name|des_cblock_print_file
argument_list|(
name|dbg_tmp
argument_list|,
name|stdout
argument_list|)
expr_stmt|;
block|}
end_if

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*FP_start:*/
end_comment

begin_comment
comment|/* do the final permutation from L1R1 to L2R2 */
end_comment

begin_comment
comment|/* all the fp code is in the include file */
end_comment

begin_include
include|#
directive|include
file|"fp.c"
end_include

begin_comment
comment|/* copy the output to the ciphertext string;      * can be same as cleartext      */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|MUSTALIGN
end_ifdef

begin_if
if|if
condition|(
operator|(
name|long
operator|)
name|cipher
operator|&
literal|3
condition|)
block|{
name|L_save
operator|=
name|L2
expr_stmt|;
comment|/* cant bcopy a reg */
name|R_save
operator|=
name|R2
expr_stmt|;
name|bcopy
argument_list|(
operator|(
name|char
operator|*
operator|)
operator|&
name|L_save
argument_list|,
operator|(
name|char
operator|*
operator|)
name|cipher
operator|++
argument_list|,
sizeof|sizeof
argument_list|(
name|L_save
argument_list|)
argument_list|)
expr_stmt|;
name|bcopy
argument_list|(
operator|(
name|char
operator|*
operator|)
operator|&
name|R_save
argument_list|,
operator|(
name|char
operator|*
operator|)
name|cipher
argument_list|,
sizeof|sizeof
argument_list|(
name|R_save
argument_list|)
argument_list|)
expr_stmt|;
block|}
else|else
endif|#
directive|endif
block|{
operator|*
name|cipher
operator|++
operator|=
name|L2
expr_stmt|;
operator|*
name|cipher
operator|=
name|R2
expr_stmt|;
block|}
end_if

begin_ifdef
ifdef|#
directive|ifdef
name|DEBUG
end_ifdef

begin_if
if|if
condition|(
name|des_debug
operator|&
literal|2
condition|)
block|{
name|L1
operator|=
name|L2
expr_stmt|;
name|R1
operator|=
name|R2
expr_stmt|;
name|dbg_tmp
index|[
literal|0
index|]
operator|=
name|L1
expr_stmt|;
name|dbg_tmp
index|[
literal|1
index|]
operator|=
name|R1
expr_stmt|;
name|DBG_PRINT
argument_list|(
literal|"done"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"iter = %2d  done\n\t\tL1 R1 = "
argument_list|,
name|i
argument_list|)
expr_stmt|;
name|des_cblock_print_file
argument_list|(
name|dbg_tmp
argument_list|,
name|stdout
argument_list|)
expr_stmt|;
block|}
end_if

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* that's it, no errors can be returned */
end_comment

begin_return
return|return
literal|0
return|;
end_return

unit|}
end_unit

