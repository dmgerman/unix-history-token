begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1989, 1993  *	The Regents of the University of California.  All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Landon Curt Noll.  *  * %sccs.include.redist.c%  *  *	@(#)primes.h	8.3 (Berkeley) %G%  */
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

