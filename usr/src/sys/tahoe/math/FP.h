begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1985 The Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Computer Consoles Inc.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)FP.h	7.1 (Berkeley) 12/6/90  */
end_comment

begin_comment
comment|/*  * General definitions of the floating point stuff on Power 6/32.  * The floating point format definition is:  *  *		S    (exp-128)  *	    (-1)  * 2	       * F  *  *	Where exp is the exponent field and F is the binary  *	mantissa following it, including the hidden bit.  *	The hidden bit actually is 1/2, so F is known to  *	satisfy the range:  *		1/2<= F< 1  */
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

