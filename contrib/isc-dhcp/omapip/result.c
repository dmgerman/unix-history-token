begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* result.c     Cheap knock-off of libisc result table code.   This is just a place-holder    until the actual libisc merge. */
end_comment

begin_comment
comment|/*  * Copyright (c) 2004 by Internet Systems Consortium, Inc. ("ISC")  * Copyright (c) 1999-2003 by Internet Software Consortium  *  * Permission to use, copy, modify, and distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND ISC DISCLAIMS ALL WARRANTIES  * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF  * MERCHANTABILITY AND FITNESS.  IN NO EVENT SHALL ISC BE LIABLE FOR  * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES  * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN  * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT  * OF OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.  *  *   Internet Systems Consortium, Inc.  *   950 Charter Street  *   Redwood City, CA 94063  *<info@isc.org>  *   http://www.isc.org/  *  * This software has been written for Internet Systems Consortium  * by Ted Lemon in cooperation with Vixie Enterprises and Nominum, Inc.  * To learn more about Internet Systems Consortium, see  * ``http://www.isc.org/''.  To learn more about Vixie Enterprises,  * see ``http://www.vix.com''.   To learn more about Nominum, Inc., see  * ``http://www.nominum.com''.  */
end_comment

begin_include
include|#
directive|include
file|<omapip/omapip_p.h>
end_include

begin_decl_stmt
specifier|static
specifier|const
name|char
modifier|*
name|text
index|[
name|ISC_R_NRESULTS
index|]
init|=
block|{
literal|"success"
block|,
comment|/*  0 */
literal|"out of memory"
block|,
comment|/*  1 */
literal|"timed out"
block|,
comment|/*  2 */
literal|"no available threads"
block|,
comment|/*  3 */
literal|"address not available"
block|,
comment|/*  4 */
literal|"address in use"
block|,
comment|/*  5 */
literal|"permission denied"
block|,
comment|/*  6 */
literal|"no pending connections"
block|,
comment|/*  7 */
literal|"network unreachable"
block|,
comment|/*  8 */
literal|"host unreachable"
block|,
comment|/*  9 */
literal|"network down"
block|,
comment|/* 10 */
literal|"host down"
block|,
comment|/* 11 */
literal|"connection refused"
block|,
comment|/* 12 */
literal|"not enough free resources"
block|,
comment|/* 13 */
literal|"end of file"
block|,
comment|/* 14 */
literal|"socket already bound"
block|,
comment|/* 15 */
literal|"task is done"
block|,
comment|/* 16 */
literal|"lock busy"
block|,
comment|/* 17 */
literal|"already exists"
block|,
comment|/* 18 */
literal|"ran out of space"
block|,
comment|/* 19 */
literal|"operation canceled"
block|,
comment|/* 20 */
literal|"sending events is not allowed"
block|,
comment|/* 21 */
literal|"shutting down"
block|,
comment|/* 22 */
literal|"not found"
block|,
comment|/* 23 */
literal|"unexpected end of input"
block|,
comment|/* 24 */
literal|"failure"
block|,
comment|/* 25 */
literal|"I/O error"
block|,
comment|/* 26 */
literal|"not implemented"
block|,
comment|/* 27 */
literal|"unbalanced parentheses"
block|,
comment|/* 28 */
literal|"no more"
block|,
comment|/* 29 */
literal|"invalid file"
block|,
comment|/* 30 */
literal|"bad base64 encoding"
block|,
comment|/* 31 */
literal|"unexpected token"
block|,
comment|/* 32 */
literal|"quota reached"
block|,
comment|/* 33 */
literal|"unexpected error"
block|,
comment|/* 34 */
literal|"already running"
block|,
comment|/* 35 */
literal|"host unknown"
block|,
comment|/* 36 */
literal|"protocol version mismatch"
block|,
comment|/* 37 */
literal|"protocol error"
block|,
comment|/* 38 */
literal|"invalid argument"
block|,
comment|/* 39 */
literal|"not connected"
block|,
comment|/* 40 */
literal|"data not yet available"
block|,
comment|/* 41 */
literal|"object unchanged"
block|,
comment|/* 42 */
literal|"more than one object matches key"
block|,
comment|/* 43 */
literal|"key conflict"
block|,
comment|/* 44 */
literal|"parse error(s) occurred"
block|,
comment|/* 45 */
literal|"no key specified"
block|,
comment|/* 46 */
literal|"zone TSIG key not known"
block|,
comment|/* 47 */
literal|"invalid TSIG key"
block|,
comment|/* 48 */
literal|"operation in progress"
block|,
comment|/* 49 */
literal|"DNS format error"
block|,
comment|/* 50 */
literal|"DNS server failed"
block|,
comment|/* 51 */
literal|"no such domain"
block|,
comment|/* 52 */
literal|"not implemented"
block|,
comment|/* 53 */
literal|"refused"
block|,
comment|/* 54 */
literal|"domain already exists"
block|,
comment|/* 55 */
literal|"RRset already exists"
block|,
comment|/* 56 */
literal|"no such RRset"
block|,
comment|/* 57 */
literal|"not authorized"
block|,
comment|/* 58 */
literal|"not a zone"
block|,
comment|/* 59 */
literal|"bad DNS signature"
block|,
comment|/* 60 */
literal|"bad DNS key"
block|,
comment|/* 61 */
literal|"clock skew too great"
block|,
comment|/* 62 */
literal|"no root zone"
block|,
comment|/* 63 */
literal|"destination address required"
block|,
comment|/* 64 */
literal|"cross-zone update"
block|,
comment|/* 65 */
literal|"no TSIG signature"
block|,
comment|/* 66 */
literal|"not equal"
block|,
comment|/* 67 */
literal|"connection reset by peer"
block|,
comment|/* 68 */
literal|"unknown attribute"
comment|/* 69 */
block|}
decl_stmt|;
end_decl_stmt

begin_function
specifier|const
name|char
modifier|*
name|isc_result_totext
parameter_list|(
name|isc_result_t
name|result
parameter_list|)
block|{
specifier|static
name|char
name|ebuf
index|[
literal|40
index|]
decl_stmt|;
if|if
condition|(
name|result
operator|>=
name|ISC_R_SUCCESS
operator|&&
name|result
operator|<
name|ISC_R_NRESULTS
condition|)
return|return
name|text
index|[
name|result
index|]
return|;
name|sprintf
argument_list|(
name|ebuf
argument_list|,
literal|"unknown error: %d"
argument_list|,
name|result
argument_list|)
expr_stmt|;
return|return
name|ebuf
return|;
block|}
end_function

end_unit

