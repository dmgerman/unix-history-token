begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2008 ARM Ltd  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. The name of the company may not be used to endorse or promote  *    products derived from this software without specific prior written  *    permission.  *  * THIS SOFTWARE IS PROVIDED BY ARM LTD ``AS IS'' AND ANY EXPRESS OR IMPLIED  * WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF  * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL ARM LTD BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,  * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED  * TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR  * PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF  * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING  * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS  * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_include
include|#
directive|include
file|"arm_asm.h"
end_include

begin_include
include|#
directive|include
file|<limits.h>
end_include

begin_include
include|#
directive|include
file|<stddef.h>
end_include

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__OPTIMIZE_SIZE__
argument_list|)
operator|||
name|defined
argument_list|(
name|PREFER_SIZE_OVER_SPEED
argument_list|)
operator|||
expr|\
operator|(
name|defined
argument_list|(
name|__thumb__
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|__thumb2__
argument_list|)
operator|)
end_if

begin_function
name|size_t
name|strlen
parameter_list|(
specifier|const
name|char
modifier|*
name|str
parameter_list|)
block|{
name|int
name|scratch
decl_stmt|;
if|#
directive|if
name|defined
argument_list|(
name|__thumb__
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|__thumb2__
argument_list|)
name|size_t
name|len
decl_stmt|;
asm|asm ("mov	%0, #0\n"        "1:\n\t"        "ldrb	%1, [%2, %0]\n\t"        "add 	%0, %0, #1\n\t"        "cmp	%1, #0\n\t"        "bne	1b"        : "=&r" (len), "=&r" (scratch) : "r" (str) : "memory", "cc");
return|return
name|len
operator|-
literal|1
return|;
else|#
directive|else
specifier|const
name|char
modifier|*
name|end
decl_stmt|;
asm|asm ("1:\n\t"        "ldrb	%1, [%0], #1\n\t"        "cmp	%1, #0\n\t"        "bne	1b"        : "=&r" (end), "=&r" (scratch) : "0" (str) : "memory", "cc");
return|return
name|end
operator|-
name|str
operator|-
literal|1
return|;
endif|#
directive|endif
block|}
end_function

begin_else
else|#
directive|else
end_else

begin_decl_stmt
name|size_t
name|__attribute__
argument_list|(
operator|(
name|naked
operator|)
argument_list|)
name|strlen
argument_list|(
specifier|const
name|char
operator|*
name|str
argument_list|)
block|{
asm|asm ("len .req r0\n\t"        "data .req r3\n\t"        "addr .req r1\n\t"         "optpld r0\n\t"
comment|/* Word-align address */
asm|"bic	addr, r0, #3\n\t"
comment|/* Get adjustment for start ... */
asm|"ands	len, r0, #3\n\t"        "neg	len, len\n\t"
comment|/* First word of data */
asm|"ldr	data, [addr], #4\n\t"
comment|/* Ensure bytes preceeding start ... */
asm|"add	ip, len, #4\n\t"        "mov	ip, ip, asl #3\n\t"        "mvn	r2, #0\n\t"
comment|/* ... are masked out */
ifdef|#
directive|ifdef
name|__thumb__
asm|"itt	ne\n\t"
ifdef|#
directive|ifdef
name|__ARMEB__
asm|"lslne	r2, ip\n\t"
else|#
directive|else
asm|"lsrne	r2, ip\n\t"
endif|#
directive|endif
asm|"orrne	data, data, r2\n\t"
else|#
directive|else
asm|"it	ne\n\t"
ifdef|#
directive|ifdef
name|__ARMEB__
asm|"orrne	data, data, r2, lsl ip\n\t"
else|#
directive|else
asm|"orrne	data, data, r2, lsr ip\n\t"
endif|#
directive|endif
endif|#
directive|endif
comment|/* Magic const 0x01010101 */
ifdef|#
directive|ifdef
name|_ISA_ARM_7
asm|"movw	ip, #0x101\n\t"
else|#
directive|else
asm|"mov	ip, #0x1\n\t"        "orr	ip, ip, ip, lsl #8\n\t"
endif|#
directive|endif
asm|"orr	ip, ip, ip, lsl #16\n"
comment|/* This is the main loop.  We subtract one from each byte in 	   the word: the sign bit changes iff the byte was zero or 	   0x80 -- we eliminate the latter case by anding the result 	   with the 1-s complement of the data.  */
asm|"1:\n\t"
comment|/* test (data - 0x01010101)  */
asm|"sub	r2, data, ip\n\t"
comment|/* ...& ~data */
asm|"bic	r2, r2, data\n\t"
comment|/* ...& 0x80808080 == 0? */
asm|"ands	r2, r2, ip, lsl #7\n\t"
ifdef|#
directive|ifdef
name|_ISA_ARM_7
comment|/* yes, get more data... */
asm|"itt	eq\n\t"        "ldreq	data, [addr], #4\n\t"
comment|/* and 4 more bytes  */
asm|"addeq	len, len, #4\n\t"
comment|/* If we have PLD, then unroll the loop a bit.  */
asm|"optpld addr, #8\n\t"
comment|/*  test (data - 0x01010101)  */
asm|"ittt	eq\n\t"        "subeq	r2, data, ip\n\t"
comment|/* ...& ~data */
asm|"biceq	r2, r2, data\n\t"
comment|/* ...& 0x80808080 == 0? */
asm|"andeqs	r2, r2, ip, lsl #7\n\t"
endif|#
directive|endif
asm|"itt	eq\n\t"
comment|/* yes, get more data... */
asm|"ldreq	data, [addr], #4\n\t"
comment|/* and 4 more bytes  */
asm|"addeq	len, len, #4\n\t"        "beq	1b\n\t"
ifdef|#
directive|ifdef
name|__ARMEB__
asm|"tst	data, #0xff000000\n\t"        "itttt	ne\n\t"        "addne	len, len, #1\n\t"        "tstne	data, #0xff0000\n\t"        "addne	len, len, #1\n\t"        "tstne	data, #0xff00\n\t"        "it	ne\n\t"        "addne	len, len, #1\n\t"
else|#
directive|else
ifdef|#
directive|ifdef
name|_ISA_ARM_5
comment|/* R2 is the residual sign bits from the above test.  All we 	need to do now is establish the position of the first zero 	byte... */
comment|/* Little-endian is harder, we need the number of trailing 	zeros / 8 */
ifdef|#
directive|ifdef
name|_ISA_ARM_7
asm|"rbit	r2, r2\n\t"        "clz	r2, r2\n\t"
else|#
directive|else
asm|"rsb	r1, r2, #0\n\t"        "and	r2, r2, r1\n\t"        "clz	r2, r2\n\t"        "rsb	r2, r2, #31\n\t"
endif|#
directive|endif
asm|"add	len, len, r2, lsr #3\n\t"
else|#
directive|else
comment|/* No CLZ instruction */
asm|"tst	data, #0xff\n\t"        "itttt	ne\n\t"        "addne	len, len, #1\n\t"        "tstne	data, #0xff00\n\t"        "addne	len, len, #1\n\t"        "tstne	data, #0xff0000\n\t"        "it	ne\n\t"        "addne	len, len, #1\n\t"
endif|#
directive|endif
endif|#
directive|endif
asm|"RETURN");
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

