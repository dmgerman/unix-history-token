begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (C) 2004  Internet Systems Consortium, Inc. ("ISC")  * Copyright (C) 1998-2003  Internet Software Consortium.  *  * Permission to use, copy, modify, and distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND ISC DISCLAIMS ALL WARRANTIES WITH  * REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY  * AND FITNESS.  IN NO EVENT SHALL ISC BE LIABLE FOR ANY SPECIAL, DIRECT,  * INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM  * LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE  * OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR  * PERFORMANCE OF THIS SOFTWARE.  */
end_comment

begin_comment
comment|/* $Id: result.c,v 1.90.2.9.2.13 2004/05/14 05:06:39 marka Exp $ */
end_comment

begin_include
include|#
directive|include
file|<config.h>
end_include

begin_include
include|#
directive|include
file|<isc/once.h>
end_include

begin_include
include|#
directive|include
file|<isc/util.h>
end_include

begin_include
include|#
directive|include
file|<dns/result.h>
end_include

begin_include
include|#
directive|include
file|<dns/lib.h>
end_include

begin_decl_stmt
specifier|static
specifier|const
name|char
modifier|*
name|text
index|[
name|DNS_R_NRESULTS
index|]
init|=
block|{
literal|"label too long"
block|,
comment|/*  0 DNS_R_LABELTOOLONG	     */
literal|"bad escape"
block|,
comment|/*  1 DNS_R_BADESCAPE	     */
comment|/* 	 * Note that DNS_R_BADBITSTRING and DNS_R_BITSTRINGTOOLONG are 	 * deprecated. 	 */
literal|"bad bitstring"
block|,
comment|/*  2 DNS_R_BADBITSTRING	     */
literal|"bitstring too long"
block|,
comment|/*  3 DNS_R_BITSTRINGTOOLONG  */
literal|"empty label"
block|,
comment|/*  4 DNS_R_EMPTYLABEL	     */
literal|"bad dotted quad"
block|,
comment|/*  5 DNS_R_BADDOTTEDQUAD     */
literal|"invalid NS owner name (wildcard)"
block|,
comment|/*  6 DNS_R_INVALIDNS	     */
literal|"unknown class/type"
block|,
comment|/*  7 DNS_R_UNKNOWN	     */
literal|"bad label type"
block|,
comment|/*  8 DNS_R_BADLABELTYPE	     */
literal|"bad compression pointer"
block|,
comment|/*  9 DNS_R_BADPOINTER	     */
literal|"too many hops"
block|,
comment|/* 10 DNS_R_TOOMANYHOPS	     */
literal|"disallowed (by application policy)"
block|,
comment|/* 11 DNS_R_DISALLOWED	     */
literal|"extra input text"
block|,
comment|/* 12 DNS_R_EXTRATOKEN	     */
literal|"extra input data"
block|,
comment|/* 13 DNS_R_EXTRADATA	     */
literal|"text too long"
block|,
comment|/* 14 DNS_R_TEXTTOOLONG	     */
literal|"not at top of zone"
block|,
comment|/* 15 DNS_R_NOTZONETOP	     */
literal|"syntax error"
block|,
comment|/* 16 DNS_R_SYNTAX	     */
literal|"bad checksum"
block|,
comment|/* 17 DNS_R_BADCKSUM	     */
literal|"bad IPv6 address"
block|,
comment|/* 18 DNS_R_BADAAAA	     */
literal|"no owner"
block|,
comment|/* 19 DNS_R_NOOWNER	     */
literal|"no ttl"
block|,
comment|/* 20 DNS_R_NOTTL	     */
literal|"bad class"
block|,
comment|/* 21 DNS_R_BADCLASS	     */
literal|"name too long"
block|,
comment|/* 22 DNS_R_NAMETOOLONG	     */
literal|"partial match"
block|,
comment|/* 23 DNS_R_PARTIALMATCH	     */
literal|"new origin"
block|,
comment|/* 24 DNS_R_NEWORIGIN	     */
literal|"unchanged"
block|,
comment|/* 25 DNS_R_UNCHANGED	     */
literal|"bad ttl"
block|,
comment|/* 26 DNS_R_BADTTL	     */
literal|"more data needed/to be rendered"
block|,
comment|/* 27 DNS_R_NOREDATA	     */
literal|"continue"
block|,
comment|/* 28 DNS_R_CONTINUE	     */
literal|"delegation"
block|,
comment|/* 29 DNS_R_DELEGATION	     */
literal|"glue"
block|,
comment|/* 30 DNS_R_GLUE		     */
literal|"dname"
block|,
comment|/* 31 DNS_R_DNAME	     */
literal|"cname"
block|,
comment|/* 32 DNS_R_CNAME	     */
literal|"bad database"
block|,
comment|/* 33 DNS_R_BADDB	     */
literal|"zonecut"
block|,
comment|/* 34 DNS_R_ZONECUT	     */
literal|"bad zone"
block|,
comment|/* 35 DNS_R_BADZONE	     */
literal|"more data"
block|,
comment|/* 36 DNS_R_MOREDATA	     */
literal|"up to date"
block|,
comment|/* 37 DNS_R_UPTODATE	     */
literal|"tsig verify failure"
block|,
comment|/* 38 DNS_R_TSIGVERIFYFAILURE */
literal|"tsig indicates error"
block|,
comment|/* 39 DNS_R_TSIGERRORSET	     */
literal|"RRSIG failed to verify"
block|,
comment|/* 40 DNS_R_SIGINVALID	     */
literal|"RRSIG has expired"
block|,
comment|/* 41 DNS_R_SIGEXPIRED	     */
literal|"RRSIG validity period has not begun"
block|,
comment|/* 42 DNS_R_SIGFUTURE	     */
literal|"key is unauthorized to sign data"
block|,
comment|/* 43 DNS_R_KEYUNAUTHORIZED   */
literal|"invalid time"
block|,
comment|/* 44 DNS_R_INVALIDTIME	     */
literal|"expected a TSIG or SIG(0)"
block|,
comment|/* 45 DNS_R_EXPECTEDTSIG	     */
literal|"did not expect a TSIG or SIG(0)"
block|,
comment|/* 46 DNS_R_UNEXPECTEDTSIG    */
literal|"TKEY is unacceptable"
block|,
comment|/* 47 DNS_R_INVALIDTKEY	     */
literal|"hint"
block|,
comment|/* 48 DNS_R_HINT		     */
literal|"drop"
block|,
comment|/* 49 DNS_R_DROP		     */
literal|"zone not loaded"
block|,
comment|/* 50 DNS_R_NOTLOADED	     */
literal|"ncache nxdomain"
block|,
comment|/* 51 DNS_R_NCACHENXDOMAIN    */
literal|"ncache nxrrset"
block|,
comment|/* 52 DNS_R_NCACHENXRRSET     */
literal|"wait"
block|,
comment|/* 53 DNS_R_WAIT		     */
literal|"not verified yet"
block|,
comment|/* 54 DNS_R_NOTVERIFIEDYET    */
literal|"no identity"
block|,
comment|/* 55 DNS_R_NOIDENTITY	     */
literal|"no journal"
block|,
comment|/* 56 DNS_R_NOJOURNAL	     */
literal|"alias"
block|,
comment|/* 57 DNS_R_ALIAS	     */
literal|"use TCP"
block|,
comment|/* 58 DNS_R_USETCP	     */
literal|"no valid RRSIG"
block|,
comment|/* 59 DNS_R_NOVALIDSIG	     */
literal|"no valid NSEC"
block|,
comment|/* 60 DNS_R_NOVALIDNSEC	     */
literal|"not insecure"
block|,
comment|/* 61 DNS_R_NOTINSECURE	     */
literal|"unknown service"
block|,
comment|/* 62 DNS_R_UNKNOWNSERVICE    */
literal|"recoverable error occurred"
block|,
comment|/* 63 DNS_R_RECOVERABLE       */
literal|"unknown opt attribute record"
block|,
comment|/* 64 DNS_R_UNKNOWNOPT	     */
literal|"unexpected message id"
block|,
comment|/* 65 DNS_R_UNEXPECTEDID      */
literal|"seen include file"
block|,
comment|/* 66 DNS_R_SEENINCLUDE       */
literal|"not exact"
block|,
comment|/* 67 DNS_R_NOTEXACT	     */
literal|"address blackholed"
block|,
comment|/* 68 DNS_R_BLACKHOLED	     */
literal|"bad algorithm"
block|,
comment|/* 69 DNS_R_BADALG	     */
literal|"invalid use of a meta type"
block|,
comment|/* 70 DNS_R_METATYPE	     */
literal|"CNAME and other data"
block|,
comment|/* 71 DNS_R_CNAMEANDOTHER     */
literal|"multiple RRs of singleton type"
block|,
comment|/* 72 DNS_R_SINGLETON	     */
literal|"hint nxrrset"
block|,
comment|/* 73 DNS_R_HINTNXRRSET	     */
literal|"no master file configured"
block|,
comment|/* 74 DNS_R_NOMASTERFILE	     */
literal|"unknown protocol"
block|,
comment|/* 75 DNS_R_UNKNOWNPROTO	     */
literal|"clocks are unsynchronized"
block|,
comment|/* 76 DNS_R_CLOCKSKEW	     */
literal|"IXFR failed"
block|,
comment|/* 77 DNS_R_BADIXFR	     */
literal|"not authoritative"
block|,
comment|/* 78 DNS_R_NOTAUTHORITATIVE  */
literal|"no valid KEY"
block|,
comment|/* 79 DNS_R_NOVALIDKEY	     */
literal|"obsolete"
block|,
comment|/* 80 DNS_R_OBSOLETE	     */
literal|"already frozen"
block|,
comment|/* 81 DNS_R_FROZEN	     */
literal|"unknown flag"
block|,
comment|/* 82 DNS_R_UNKNOWNFLAG	     */
literal|"expected a response"
block|,
comment|/* 83 DNS_R_EXPECTEDRESPONSE  */
literal|"no valid DS"
block|,
comment|/* 84 DNS_R_NOVALIDDS	     */
literal|"NS is an address"
block|,
comment|/* 85 DNS_R_NSISADDRESS	     */
literal|"received FORMERR"
block|,
comment|/* 86 DNS_R_REMOTEFORMERR     */
literal|"truncated TCP response"
block|,
comment|/* 87 DNS_R_TRUNCATEDTCP	     */
literal|"lame server detected"
block|,
comment|/* 88 DNS_R_LAME		     */
literal|"unexpected RCODE"
block|,
comment|/* 89 DNS_R_UNEXPECTEDRCODE   */
literal|"unexpected OPCODE"
block|,
comment|/* 90 DNS_R_UNEXPECTEDOPCODE  */
literal|"chase DS servers"
block|,
comment|/* 91 DNS_R_CHASEDSSERVERS    */
literal|"empty name"
block|,
comment|/* 92 DNS_R_EMPTYNAME	     */
literal|"empty wild"
block|,
comment|/* 93 DNS_R_EMPTYWILD	     */
literal|"bad bitmap"
block|,
comment|/* 94 DNS_R_BADBITMAP	     */
literal|"from wildcard"
block|,
comment|/* 95 DNS_R_FROMWILDCARD	     */
literal|"bad owner name (check-names)"
block|,
comment|/* 96 DNS_R_BADOWNERNAME	     */
literal|"bad name (check-names)"
block|,
comment|/* 97 DNS_R_BADNAME	     */
literal|"dynamic zone"
block|,
comment|/* 98 DNS_R_DYNAMIC	     */
literal|"unknown command"
block|,
comment|/* 99 DNS_R_UNKNOWNCOMMAND    */
literal|"must-be-secure"
block|,
comment|/* 100 DNS_R_MUSTBESECURE     */
literal|"covering NSEC record returned"
comment|/* 101 DNS_R_COVERINGNSEC     */
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|char
modifier|*
name|rcode_text
index|[
name|DNS_R_NRCODERESULTS
index|]
init|=
block|{
literal|"NOERROR"
block|,
comment|/*  0 DNS_R_NOEROR	     */
literal|"FORMERR"
block|,
comment|/*  1 DNS_R_FORMERR	     */
literal|"SERVFAIL"
block|,
comment|/*  2 DNS_R_SERVFAIL	     */
literal|"NXDOMAIN"
block|,
comment|/*  3 DNS_R_NXDOMAIN	     */
literal|"NOTIMP"
block|,
comment|/*  4 DNS_R_NOTIMP	     */
literal|"REFUSED"
block|,
comment|/*  5 DNS_R_REFUSED	     */
literal|"YXDOMAIN"
block|,
comment|/*  6 DNS_R_YXDOMAIN	     */
literal|"YXRRSET"
block|,
comment|/*  7 DNS_R_YXRRSET	     */
literal|"NXRRSET"
block|,
comment|/*  8 DNS_R_NXRRSET	     */
literal|"NOTAUTH"
block|,
comment|/*  9 DNS_R_NOTAUTH	     */
literal|"NOTZONE"
block|,
comment|/* 10 DNS_R_NOTZONE 	     */
literal|"<rcode 11>"
block|,
comment|/* 11 has no macro	     */
literal|"<rcode 12>"
block|,
comment|/* 12 has no macro	     */
literal|"<rcode 13>"
block|,
comment|/* 13 has no macro	     */
literal|"<rcode 14>"
block|,
comment|/* 14 has no macro	     */
literal|"<rcode 15>"
block|,
comment|/* 15 has no macro	     */
literal|"BADVERS"
block|,
comment|/* 16 DNS_R_BADVERS	     */
block|}
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|DNS_RESULT_RESULTSET
value|2
end_define

begin_define
define|#
directive|define
name|DNS_RESULT_RCODERESULTSET
value|3
end_define

begin_decl_stmt
specifier|static
name|isc_once_t
name|once
init|=
name|ISC_ONCE_INIT
decl_stmt|;
end_decl_stmt

begin_function
specifier|static
name|void
name|initialize_action
parameter_list|(
name|void
parameter_list|)
block|{
name|isc_result_t
name|result
decl_stmt|;
name|result
operator|=
name|isc_result_register
argument_list|(
name|ISC_RESULTCLASS_DNS
argument_list|,
name|DNS_R_NRESULTS
argument_list|,
name|text
argument_list|,
name|dns_msgcat
argument_list|,
name|DNS_RESULT_RESULTSET
argument_list|)
expr_stmt|;
if|if
condition|(
name|result
operator|==
name|ISC_R_SUCCESS
condition|)
name|result
operator|=
name|isc_result_register
argument_list|(
name|ISC_RESULTCLASS_DNSRCODE
argument_list|,
name|DNS_R_NRCODERESULTS
argument_list|,
name|rcode_text
argument_list|,
name|dns_msgcat
argument_list|,
name|DNS_RESULT_RCODERESULTSET
argument_list|)
expr_stmt|;
if|if
condition|(
name|result
operator|!=
name|ISC_R_SUCCESS
condition|)
name|UNEXPECTED_ERROR
argument_list|(
name|__FILE__
argument_list|,
name|__LINE__
argument_list|,
literal|"isc_result_register() failed: %u"
argument_list|,
name|result
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
specifier|static
name|void
name|initialize
parameter_list|(
name|void
parameter_list|)
block|{
name|dns_lib_initmsgcat
argument_list|()
expr_stmt|;
name|RUNTIME_CHECK
argument_list|(
name|isc_once_do
argument_list|(
operator|&
name|once
argument_list|,
name|initialize_action
argument_list|)
operator|==
name|ISC_R_SUCCESS
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
specifier|const
name|char
modifier|*
name|dns_result_totext
parameter_list|(
name|isc_result_t
name|result
parameter_list|)
block|{
name|initialize
argument_list|()
expr_stmt|;
return|return
operator|(
name|isc_result_totext
argument_list|(
name|result
argument_list|)
operator|)
return|;
block|}
end_function

begin_function
name|void
name|dns_result_register
parameter_list|(
name|void
parameter_list|)
block|{
name|initialize
argument_list|()
expr_stmt|;
block|}
end_function

begin_function
name|dns_rcode_t
name|dns_result_torcode
parameter_list|(
name|isc_result_t
name|result
parameter_list|)
block|{
name|dns_rcode_t
name|rcode
init|=
name|dns_rcode_servfail
decl_stmt|;
if|if
condition|(
name|DNS_RESULT_ISRCODE
argument_list|(
name|result
argument_list|)
condition|)
block|{
comment|/* 		 * Rcodes can't be bigger than 12 bits, which is why we 		 * AND with 0xFFF instead of 0xFFFF. 		 */
return|return
operator|(
call|(
name|dns_rcode_t
call|)
argument_list|(
operator|(
name|result
operator|)
operator|&
literal|0xFFF
argument_list|)
operator|)
return|;
block|}
comment|/* 	 * Try to supply an appropriate rcode. 	 */
switch|switch
condition|(
name|result
condition|)
block|{
case|case
name|ISC_R_SUCCESS
case|:
name|rcode
operator|=
name|dns_rcode_noerror
expr_stmt|;
break|break;
case|case
name|ISC_R_BADBASE64
case|:
case|case
name|ISC_R_NOSPACE
case|:
case|case
name|ISC_R_RANGE
case|:
case|case
name|ISC_R_UNEXPECTEDEND
case|:
case|case
name|DNS_R_BADAAAA
case|:
comment|/* case DNS_R_BADBITSTRING: deprecated */
case|case
name|DNS_R_BADCKSUM
case|:
case|case
name|DNS_R_BADCLASS
case|:
case|case
name|DNS_R_BADLABELTYPE
case|:
case|case
name|DNS_R_BADPOINTER
case|:
case|case
name|DNS_R_BADTTL
case|:
case|case
name|DNS_R_BADZONE
case|:
comment|/* case DNS_R_BITSTRINGTOOLONG: deprecated */
case|case
name|DNS_R_EXTRADATA
case|:
case|case
name|DNS_R_LABELTOOLONG
case|:
case|case
name|DNS_R_NOREDATA
case|:
case|case
name|DNS_R_SYNTAX
case|:
case|case
name|DNS_R_TEXTTOOLONG
case|:
case|case
name|DNS_R_TOOMANYHOPS
case|:
case|case
name|DNS_R_TSIGERRORSET
case|:
case|case
name|DNS_R_UNKNOWN
case|:
name|rcode
operator|=
name|dns_rcode_formerr
expr_stmt|;
break|break;
case|case
name|DNS_R_DISALLOWED
case|:
name|rcode
operator|=
name|dns_rcode_refused
expr_stmt|;
break|break;
case|case
name|DNS_R_TSIGVERIFYFAILURE
case|:
case|case
name|DNS_R_CLOCKSKEW
case|:
name|rcode
operator|=
name|dns_rcode_notauth
expr_stmt|;
break|break;
default|default:
name|rcode
operator|=
name|dns_rcode_servfail
expr_stmt|;
block|}
return|return
operator|(
name|rcode
operator|)
return|;
block|}
end_function

end_unit

