begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1989, 1993  *	The Regents of the University of California.  All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Landon Curt Noll.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)primes.h	8.2 (Berkeley) 3/1/94  */
end_comment

begin_comment
comment|/*  * primes - generate a table of primes between two values  *  * By: Landon Curt Noll chongo@toad.com, ...!{sun,tolsoft}!hoptoad!chongo  *  * chongo<for a good prime call: 391581 * 2^216193 - 1> /\oo/\  */
end_comment

begin_comment
comment|/* ubig is the type that holds a large unsigned value */
end_comment

begin_typedef
typedef|typedef
name|unsigned
name|long
name|ubig
typedef|;
end_typedef

begin_comment
comment|/* must be>=32 bit unsigned value */
end_comment

begin_define
define|#
directive|define
name|BIG
value|ULONG_MAX
end_define

begin_comment
comment|/* largest value will sieve */
end_comment

begin_comment
comment|/* bytes in sieve table (must be> 3*5*7*11) */
end_comment

begin_define
define|#
directive|define
name|TABSIZE
value|256*1024
end_define

end_unit

