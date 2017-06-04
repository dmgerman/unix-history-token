begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1989, 1993  *	The Regents of the University of California.  All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Landon Curt Noll.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)primes.h	8.2 (Berkeley) 3/1/94  * $FreeBSD$  */
end_comment

begin_comment
comment|/*  * primes - generate a table of primes between two values  *  * By: Landon Curt Noll chongo@toad.com, ...!{sun,tolsoft}!hoptoad!chongo  *  * chongo<for a good prime call: 391581 * 2^216193 - 1> /\oo/\  */
end_comment

begin_include
include|#
directive|include
file|<stdint.h>
end_include

begin_comment
comment|/* ubig is the type that holds a large unsigned value */
end_comment

begin_typedef
typedef|typedef
name|uint64_t
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

begin_comment
comment|/*  * prime[i] is the (i-1)th prime.  *  * We are able to sieve 2^32-1 because this byte table yields all primes  * up to 65537 and 65537^2> 2^32-1.  */
end_comment

begin_decl_stmt
specifier|extern
specifier|const
name|ubig
name|prime
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|ubig
modifier|*
specifier|const
name|pr_limit
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* largest prime in the prime array */
end_comment

begin_comment
comment|/* Maximum size sieving alone can handle. */
end_comment

begin_define
define|#
directive|define
name|SIEVEMAX
value|4295098368ULL
end_define

begin_comment
comment|/*  * To avoid excessive sieves for small factors, we use the table below to  * setup our sieve blocks.  Each element represents an odd number starting  * with 1.  All non-zero elements are factors of 3, 5, 7, 11 and 13.  */
end_comment

begin_decl_stmt
specifier|extern
specifier|const
name|char
name|pattern
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|size_t
name|pattern_size
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* length of pattern array */
end_comment

begin_comment
comment|/* Test for primality using strong pseudoprime tests. */
end_comment

begin_function_decl
name|int
name|isprime
parameter_list|(
name|ubig
parameter_list|)
function_decl|;
end_function_decl

end_unit

