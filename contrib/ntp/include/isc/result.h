begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (C) 1998-2001  Internet Software Consortium.  *  * Permission to use, copy, modify, and distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND INTERNET SOFTWARE CONSORTIUM  * DISCLAIMS ALL WARRANTIES WITH REGARD TO THIS SOFTWARE INCLUDING ALL  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL  * INTERNET SOFTWARE CONSORTIUM BE LIABLE FOR ANY SPECIAL, DIRECT,  * INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING  * FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT,  * NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION  * WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.  */
end_comment

begin_comment
comment|/* $Id: result.h,v 1.59 2001/11/30 01:02:17 gson Exp $ */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|ISC_RESULT_H
end_ifndef

begin_define
define|#
directive|define
name|ISC_RESULT_H
value|1
end_define

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

begin_define
define|#
directive|define
name|ISC_R_SUCCESS
value|0
end_define

begin_comment
comment|/* success */
end_comment

begin_define
define|#
directive|define
name|ISC_R_NOMEMORY
value|1
end_define

begin_comment
comment|/* out of memory */
end_comment

begin_define
define|#
directive|define
name|ISC_R_TIMEDOUT
value|2
end_define

begin_comment
comment|/* timed out */
end_comment

begin_define
define|#
directive|define
name|ISC_R_NOTHREADS
value|3
end_define

begin_comment
comment|/* no available threads */
end_comment

begin_define
define|#
directive|define
name|ISC_R_ADDRNOTAVAIL
value|4
end_define

begin_comment
comment|/* address not available */
end_comment

begin_define
define|#
directive|define
name|ISC_R_ADDRINUSE
value|5
end_define

begin_comment
comment|/* address in use */
end_comment

begin_define
define|#
directive|define
name|ISC_R_NOPERM
value|6
end_define

begin_comment
comment|/* permission denied */
end_comment

begin_define
define|#
directive|define
name|ISC_R_NOCONN
value|7
end_define

begin_comment
comment|/* no pending connections */
end_comment

begin_define
define|#
directive|define
name|ISC_R_NETUNREACH
value|8
end_define

begin_comment
comment|/* network unreachable */
end_comment

begin_define
define|#
directive|define
name|ISC_R_HOSTUNREACH
value|9
end_define

begin_comment
comment|/* host unreachable */
end_comment

begin_define
define|#
directive|define
name|ISC_R_NETDOWN
value|10
end_define

begin_comment
comment|/* network down */
end_comment

begin_define
define|#
directive|define
name|ISC_R_HOSTDOWN
value|11
end_define

begin_comment
comment|/* host down */
end_comment

begin_define
define|#
directive|define
name|ISC_R_CONNREFUSED
value|12
end_define

begin_comment
comment|/* connection refused */
end_comment

begin_define
define|#
directive|define
name|ISC_R_NORESOURCES
value|13
end_define

begin_comment
comment|/* not enough free resources */
end_comment

begin_define
define|#
directive|define
name|ISC_R_EOF
value|14
end_define

begin_comment
comment|/* end of file */
end_comment

begin_define
define|#
directive|define
name|ISC_R_BOUND
value|15
end_define

begin_comment
comment|/* socket already bound */
end_comment

begin_define
define|#
directive|define
name|ISC_R_RELOAD
value|16
end_define

begin_comment
comment|/* reload */
end_comment

begin_define
define|#
directive|define
name|ISC_R_LOCKBUSY
value|17
end_define

begin_comment
comment|/* lock busy */
end_comment

begin_define
define|#
directive|define
name|ISC_R_EXISTS
value|18
end_define

begin_comment
comment|/* already exists */
end_comment

begin_define
define|#
directive|define
name|ISC_R_NOSPACE
value|19
end_define

begin_comment
comment|/* ran out of space */
end_comment

begin_define
define|#
directive|define
name|ISC_R_CANCELED
value|20
end_define

begin_comment
comment|/* operation canceled */
end_comment

begin_define
define|#
directive|define
name|ISC_R_NOTBOUND
value|21
end_define

begin_comment
comment|/* socket is not bound */
end_comment

begin_define
define|#
directive|define
name|ISC_R_SHUTTINGDOWN
value|22
end_define

begin_comment
comment|/* shutting down */
end_comment

begin_define
define|#
directive|define
name|ISC_R_NOTFOUND
value|23
end_define

begin_comment
comment|/* not found */
end_comment

begin_define
define|#
directive|define
name|ISC_R_UNEXPECTEDEND
value|24
end_define

begin_comment
comment|/* unexpected end of input */
end_comment

begin_define
define|#
directive|define
name|ISC_R_FAILURE
value|25
end_define

begin_comment
comment|/* generic failure */
end_comment

begin_define
define|#
directive|define
name|ISC_R_IOERROR
value|26
end_define

begin_comment
comment|/* I/O error */
end_comment

begin_define
define|#
directive|define
name|ISC_R_NOTIMPLEMENTED
value|27
end_define

begin_comment
comment|/* not implemented */
end_comment

begin_define
define|#
directive|define
name|ISC_R_UNBALANCED
value|28
end_define

begin_comment
comment|/* unbalanced parentheses */
end_comment

begin_define
define|#
directive|define
name|ISC_R_NOMORE
value|29
end_define

begin_comment
comment|/* no more */
end_comment

begin_define
define|#
directive|define
name|ISC_R_INVALIDFILE
value|30
end_define

begin_comment
comment|/* invalid file */
end_comment

begin_define
define|#
directive|define
name|ISC_R_BADBASE64
value|31
end_define

begin_comment
comment|/* bad base64 encoding */
end_comment

begin_define
define|#
directive|define
name|ISC_R_UNEXPECTEDTOKEN
value|32
end_define

begin_comment
comment|/* unexpected token */
end_comment

begin_define
define|#
directive|define
name|ISC_R_QUOTA
value|33
end_define

begin_comment
comment|/* quota reached */
end_comment

begin_define
define|#
directive|define
name|ISC_R_UNEXPECTED
value|34
end_define

begin_comment
comment|/* unexpected error */
end_comment

begin_define
define|#
directive|define
name|ISC_R_ALREADYRUNNING
value|35
end_define

begin_comment
comment|/* already running */
end_comment

begin_define
define|#
directive|define
name|ISC_R_IGNORE
value|36
end_define

begin_comment
comment|/* ignore */
end_comment

begin_define
define|#
directive|define
name|ISC_R_MASKNONCONTIG
value|37
end_define

begin_comment
comment|/* addr mask not contiguous */
end_comment

begin_define
define|#
directive|define
name|ISC_R_FILENOTFOUND
value|38
end_define

begin_comment
comment|/* file not found */
end_comment

begin_define
define|#
directive|define
name|ISC_R_FILEEXISTS
value|39
end_define

begin_comment
comment|/* file already exists */
end_comment

begin_define
define|#
directive|define
name|ISC_R_NOTCONNECTED
value|40
end_define

begin_comment
comment|/* socket is not connected */
end_comment

begin_define
define|#
directive|define
name|ISC_R_RANGE
value|41
end_define

begin_comment
comment|/* out of range */
end_comment

begin_define
define|#
directive|define
name|ISC_R_NOENTROPY
value|42
end_define

begin_comment
comment|/* out of entropy */
end_comment

begin_define
define|#
directive|define
name|ISC_R_MULTICAST
value|43
end_define

begin_comment
comment|/* invalid use of multicast */
end_comment

begin_define
define|#
directive|define
name|ISC_R_NOTFILE
value|44
end_define

begin_comment
comment|/* not a file */
end_comment

begin_define
define|#
directive|define
name|ISC_R_NOTDIRECTORY
value|45
end_define

begin_comment
comment|/* not a directory */
end_comment

begin_define
define|#
directive|define
name|ISC_R_QUEUEFULL
value|46
end_define

begin_comment
comment|/* queue is full */
end_comment

begin_define
define|#
directive|define
name|ISC_R_FAMILYMISMATCH
value|47
end_define

begin_comment
comment|/* address family mismatch */
end_comment

begin_define
define|#
directive|define
name|ISC_R_FAMILYNOSUPPORT
value|48
end_define

begin_comment
comment|/* AF not supported */
end_comment

begin_define
define|#
directive|define
name|ISC_R_BADHEX
value|49
end_define

begin_comment
comment|/* bad hex encoding */
end_comment

begin_define
define|#
directive|define
name|ISC_R_TOOMANYOPENFILES
value|50
end_define

begin_comment
comment|/* too many open files */
end_comment

begin_define
define|#
directive|define
name|ISC_R_NOTBLOCKING
value|51
end_define

begin_comment
comment|/* not blocking */
end_comment

begin_define
define|#
directive|define
name|ISC_R_UNBALANCEDQUOTES
value|52
end_define

begin_comment
comment|/* unbalanced quotes */
end_comment

begin_define
define|#
directive|define
name|ISC_R_INPROGRESS
value|53
end_define

begin_comment
comment|/* operation in progress */
end_comment

begin_define
define|#
directive|define
name|ISC_R_CONNECTIONRESET
value|54
end_define

begin_comment
comment|/* connection reset */
end_comment

begin_define
define|#
directive|define
name|ISC_R_SOFTQUOTA
value|55
end_define

begin_comment
comment|/* soft quota reached */
end_comment

begin_define
define|#
directive|define
name|ISC_R_BADNUMBER
value|56
end_define

begin_comment
comment|/* not a valid number */
end_comment

begin_comment
comment|/*  * Not a result code: the number of results.  */
end_comment

begin_define
define|#
directive|define
name|ISC_R_NRESULTS
value|57
end_define

begin_function_decl
name|ISC_LANG_BEGINDECLS
specifier|const
name|char
modifier|*
name|isc_result_totext
parameter_list|(
name|isc_result_t
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Convert an isc_result_t into a string message describing the result.  */
end_comment

begin_function_decl
name|isc_result_t
name|isc_result_register
parameter_list|(
name|unsigned
name|int
name|base
parameter_list|,
name|unsigned
name|int
name|nresults
parameter_list|,
specifier|const
name|char
modifier|*
modifier|*
name|text
parameter_list|,
name|isc_msgcat_t
modifier|*
name|msgcat
parameter_list|,
name|int
name|set
parameter_list|)
function_decl|;
end_function_decl

begin_macro
name|ISC_LANG_ENDDECLS
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ISC_RESULT_H */
end_comment

end_unit

