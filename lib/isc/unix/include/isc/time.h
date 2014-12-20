begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (C) 2004-2009  Internet Systems Consortium, Inc. ("ISC")  * Copyright (C) 1998-2001  Internet Software Consortium.  *  * Permission to use, copy, modify, and/or distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND ISC DISCLAIMS ALL WARRANTIES WITH  * REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY  * AND FITNESS.  IN NO EVENT SHALL ISC BE LIABLE FOR ANY SPECIAL, DIRECT,  * INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM  * LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE  * OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR  * PERFORMANCE OF THIS SOFTWARE.  */
end_comment

begin_comment
comment|/* $Id: time.h,v 1.40 2009/01/05 23:47:54 tbox Exp $ */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|ISC_TIME_H
end_ifndef

begin_define
define|#
directive|define
name|ISC_TIME_H
value|1
end_define

begin_comment
comment|/*! \file */
end_comment

begin_include
include|#
directive|include
file|<isc/lang.h>
end_include

begin_include
include|#
directive|include
file|<isc/types.h>
end_include

begin_comment
comment|/***  *** Intervals  ***/
end_comment

begin_comment
comment|/*!  *  \brief  * The contents of this structure are private, and MUST NOT be accessed  * directly by callers.  *  * The contents are exposed only to allow callers to avoid dynamic allocation.  */
end_comment

begin_struct
struct|struct
name|isc_interval
block|{
name|unsigned
name|int
name|seconds
decl_stmt|;
name|unsigned
name|int
name|nanoseconds
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|isc_interval_t
modifier|*
name|isc_interval_zero
decl_stmt|;
end_decl_stmt

begin_function_decl
name|ISC_LANG_BEGINDECLS
name|void
name|isc_interval_set
parameter_list|(
name|isc_interval_t
modifier|*
name|i
parameter_list|,
name|unsigned
name|int
name|seconds
parameter_list|,
name|unsigned
name|int
name|nanoseconds
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Set 'i' to a value representing an interval of 'seconds' seconds and  * 'nanoseconds' nanoseconds, suitable for use in isc_time_add() and  * isc_time_subtract().  *  * Requires:  *  *\li	't' is a valid pointer.  *\li	nanoseconds< 1000000000.  */
end_comment

begin_function_decl
name|isc_boolean_t
name|isc_interval_iszero
parameter_list|(
specifier|const
name|isc_interval_t
modifier|*
name|i
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Returns ISC_TRUE iff. 'i' is the zero interval.  *  * Requires:  *  *\li	'i' is a valid pointer.  */
end_comment

begin_comment
comment|/***  *** Absolute Times  ***/
end_comment

begin_comment
comment|/*%  * The contents of this structure are private, and MUST NOT be accessed  * directly by callers.  *  * The contents are exposed only to allow callers to avoid dynamic allocation.  */
end_comment

begin_struct
struct|struct
name|isc_time
block|{
name|unsigned
name|int
name|seconds
decl_stmt|;
name|unsigned
name|int
name|nanoseconds
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|isc_time_t
modifier|*
name|isc_time_epoch
decl_stmt|;
end_decl_stmt

begin_function_decl
name|void
name|isc_time_set
parameter_list|(
name|isc_time_t
modifier|*
name|t
parameter_list|,
name|unsigned
name|int
name|seconds
parameter_list|,
name|unsigned
name|int
name|nanoseconds
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Set 't' to a value which represents the given number of seconds and  * nanoseconds since 00:00:00 January 1, 1970, UTC.  *  * Notes:  *\li	The Unix version of this call is equivalent to:  *\code  *	isc_time_settoepoch(t);  *	isc_interval_set(i, seconds, nanoseconds);  *	isc_time_add(t, i, t);  *\endcode  *  * Requires:  *\li	't' is a valid pointer.  *\li	nanoseconds< 1000000000.  */
end_comment

begin_function_decl
name|void
name|isc_time_settoepoch
parameter_list|(
name|isc_time_t
modifier|*
name|t
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Set 't' to the time of the epoch.  *  * Notes:  *\li	The date of the epoch is platform-dependent.  *  * Requires:  *  *\li	't' is a valid pointer.  */
end_comment

begin_function_decl
name|isc_boolean_t
name|isc_time_isepoch
parameter_list|(
specifier|const
name|isc_time_t
modifier|*
name|t
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Returns ISC_TRUE iff. 't' is the epoch ("time zero").  *  * Requires:  *  *\li	't' is a valid pointer.  */
end_comment

begin_function_decl
name|isc_result_t
name|isc_time_now
parameter_list|(
name|isc_time_t
modifier|*
name|t
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Set 't' to the current absolute time.  *  * Requires:  *  *\li	't' is a valid pointer.  *  * Returns:  *  *\li	Success  *\li	Unexpected error  *		Getting the time from the system failed.  *\li	Out of range  *		The time from the system is too large to be represented  *		in the current definition of isc_time_t.  */
end_comment

begin_function_decl
name|isc_result_t
name|isc_time_nowplusinterval
parameter_list|(
name|isc_time_t
modifier|*
name|t
parameter_list|,
specifier|const
name|isc_interval_t
modifier|*
name|i
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Set *t to the current absolute time + i.  *  * Note:  *\li	This call is equivalent to:  *  *\code  *		isc_time_now(t);  *		isc_time_add(t, i, t);  *\endcode  *  * Requires:  *  *\li	't' and 'i' are valid pointers.  *  * Returns:  *  *\li	Success  *\li	Unexpected error  *		Getting the time from the system failed.  *\li	Out of range  *		The interval added to the time from the system is too large to  *		be represented in the current definition of isc_time_t.  */
end_comment

begin_function_decl
name|int
name|isc_time_compare
parameter_list|(
specifier|const
name|isc_time_t
modifier|*
name|t1
parameter_list|,
specifier|const
name|isc_time_t
modifier|*
name|t2
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Compare the times referenced by 't1' and 't2'  *  * Requires:  *  *\li	't1' and 't2' are valid pointers.  *  * Returns:  *  *\li	-1		t1< t2		(comparing times, not pointers)  *\li	0		t1 = t2  *\li	1		t1> t2  */
end_comment

begin_function_decl
name|isc_result_t
name|isc_time_add
parameter_list|(
specifier|const
name|isc_time_t
modifier|*
name|t
parameter_list|,
specifier|const
name|isc_interval_t
modifier|*
name|i
parameter_list|,
name|isc_time_t
modifier|*
name|result
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Add 'i' to 't', storing the result in 'result'.  *  * Requires:  *  *\li	't', 'i', and 'result' are valid pointers.  *  * Returns:  *\li	Success  *\li	Out of range  * 		The interval added to the time is too large to  *		be represented in the current definition of isc_time_t.  */
end_comment

begin_function_decl
name|isc_result_t
name|isc_time_subtract
parameter_list|(
specifier|const
name|isc_time_t
modifier|*
name|t
parameter_list|,
specifier|const
name|isc_interval_t
modifier|*
name|i
parameter_list|,
name|isc_time_t
modifier|*
name|result
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Subtract 'i' from 't', storing the result in 'result'.  *  * Requires:  *  *\li	't', 'i', and 'result' are valid pointers.  *  * Returns:  *\li	Success  *\li	Out of range  *		The interval is larger than the time since the epoch.  */
end_comment

begin_function_decl
name|isc_uint64_t
name|isc_time_microdiff
parameter_list|(
specifier|const
name|isc_time_t
modifier|*
name|t1
parameter_list|,
specifier|const
name|isc_time_t
modifier|*
name|t2
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Find the difference in microseconds between time t1 and time t2.  * t2 is the subtrahend of t1; ie, difference = t1 - t2.  *  * Requires:  *  *\li	't1' and 't2' are valid pointers.  *  * Returns:  *\li	The difference of t1 - t2, or 0 if t1<= t2.  */
end_comment

begin_function_decl
name|isc_uint32_t
name|isc_time_seconds
parameter_list|(
specifier|const
name|isc_time_t
modifier|*
name|t
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Return the number of seconds since the epoch stored in a time structure.  *  * Requires:  *  *\li	't' is a valid pointer.  */
end_comment

begin_function_decl
name|isc_result_t
name|isc_time_secondsastimet
parameter_list|(
specifier|const
name|isc_time_t
modifier|*
name|t
parameter_list|,
name|time_t
modifier|*
name|secondsp
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Ensure the number of seconds in an isc_time_t is representable by a time_t.  *  * Notes:  *\li	The number of seconds stored in an isc_time_t might be larger  *	than the number of seconds a time_t is able to handle.  Since  *	time_t is mostly opaque according to the ANSI/ISO standard  *	(essentially, all you can be sure of is that it is an arithmetic type,  *	not even necessarily integral), it can be tricky to ensure that  *	the isc_time_t is in the range a time_t can handle.  Use this  *	function in place of isc_time_seconds() any time you need to set a  *	time_t from an isc_time_t.  *  * Requires:  *\li	't' is a valid pointer.  *  * Returns:  *\li	Success  *\li	Out of range  */
end_comment

begin_function_decl
name|isc_uint32_t
name|isc_time_nanoseconds
parameter_list|(
specifier|const
name|isc_time_t
modifier|*
name|t
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Return the number of nanoseconds stored in a time structure.  *  * Notes:  *\li	This is the number of nanoseconds in excess of the number  *	of seconds since the epoch; it will always be less than one  *	full second.  *  * Requires:  *\li	't' is a valid pointer.  *  * Ensures:  *\li	The returned value is less than 1*10^9.  */
end_comment

begin_function_decl
name|void
name|isc_time_formattimestamp
parameter_list|(
specifier|const
name|isc_time_t
modifier|*
name|t
parameter_list|,
name|char
modifier|*
name|buf
parameter_list|,
name|unsigned
name|int
name|len
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Format the time 't' into the buffer 'buf' of length 'len',  * using a format like "30-Aug-2000 04:06:47.997" and the local time zone.  * If the text does not fit in the buffer, the result is indeterminate,  * but is always guaranteed to be null terminated.  *  *  Requires:  *\li      'len'> 0  *\li      'buf' points to an array of at least len chars  *  */
end_comment

begin_function_decl
name|void
name|isc_time_formathttptimestamp
parameter_list|(
specifier|const
name|isc_time_t
modifier|*
name|t
parameter_list|,
name|char
modifier|*
name|buf
parameter_list|,
name|unsigned
name|int
name|len
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Format the time 't' into the buffer 'buf' of length 'len',  * using a format like "Mon, 30 Aug 2000 04:06:47 GMT"  * If the text does not fit in the buffer, the result is indeterminate,  * but is always guaranteed to be null terminated.  *  *  Requires:  *\li      'len'> 0  *\li      'buf' points to an array of at least len chars  *  */
end_comment

begin_function_decl
name|void
name|isc_time_formatISO8601
parameter_list|(
specifier|const
name|isc_time_t
modifier|*
name|t
parameter_list|,
name|char
modifier|*
name|buf
parameter_list|,
name|unsigned
name|int
name|len
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Format the time 't' into the buffer 'buf' of length 'len',  * using the ISO8601 format: "yyyy-mm-ddThh:mm:ssZ"  * If the text does not fit in the buffer, the result is indeterminate,  * but is always guaranteed to be null terminated.  *  *  Requires:  *\li      'len'> 0  *\li      'buf' points to an array of at least len chars  *  */
end_comment

begin_macro
name|ISC_LANG_ENDDECLS
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ISC_TIME_H */
end_comment

end_unit

