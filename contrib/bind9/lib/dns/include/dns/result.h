begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (C) 2004  Internet Systems Consortium, Inc. ("ISC")  * Copyright (C) 1998-2003  Internet Software Consortium.  *  * Permission to use, copy, modify, and distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND ISC DISCLAIMS ALL WARRANTIES WITH  * REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY  * AND FITNESS.  IN NO EVENT SHALL ISC BE LIABLE FOR ANY SPECIAL, DIRECT,  * INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM  * LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE  * OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR  * PERFORMANCE OF THIS SOFTWARE.  */
end_comment

begin_comment
comment|/* $Id: result.h,v 1.81.2.7.2.13 2004/05/14 05:06:41 marka Exp $ */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|DNS_RESULT_H
end_ifndef

begin_define
define|#
directive|define
name|DNS_RESULT_H
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
file|<isc/resultclass.h>
end_include

begin_include
include|#
directive|include
file|<dns/types.h>
end_include

begin_comment
comment|/*  * Nothing in this file truly depends on<isc/result.h>, but the  * DNS result codes are considered to be publicly derived from  * the ISC result codes, so including this file buys you the ISC_R_  * namespace too.  */
end_comment

begin_include
include|#
directive|include
file|<isc/result.h>
end_include

begin_comment
comment|/* Contractual promise. */
end_comment

begin_comment
comment|/*  * DNS library result codes  */
end_comment

begin_define
define|#
directive|define
name|DNS_R_LABELTOOLONG
value|(ISC_RESULTCLASS_DNS + 0)
end_define

begin_define
define|#
directive|define
name|DNS_R_BADESCAPE
value|(ISC_RESULTCLASS_DNS + 1)
end_define

begin_comment
comment|/*  * Since we dropped the support of bitstring labels, deprecate the related  * result codes too.  #define DNS_R_BADBITSTRING		(ISC_RESULTCLASS_DNS + 2) #define DNS_R_BITSTRINGTOOLONG		(ISC_RESULTCLASS_DNS + 3) */
end_comment

begin_define
define|#
directive|define
name|DNS_R_EMPTYLABEL
value|(ISC_RESULTCLASS_DNS + 4)
end_define

begin_define
define|#
directive|define
name|DNS_R_BADDOTTEDQUAD
value|(ISC_RESULTCLASS_DNS + 5)
end_define

begin_define
define|#
directive|define
name|DNS_R_INVALIDNS
value|(ISC_RESULTCLASS_DNS + 6)
end_define

begin_define
define|#
directive|define
name|DNS_R_UNKNOWN
value|(ISC_RESULTCLASS_DNS + 7)
end_define

begin_define
define|#
directive|define
name|DNS_R_BADLABELTYPE
value|(ISC_RESULTCLASS_DNS + 8)
end_define

begin_define
define|#
directive|define
name|DNS_R_BADPOINTER
value|(ISC_RESULTCLASS_DNS + 9)
end_define

begin_define
define|#
directive|define
name|DNS_R_TOOMANYHOPS
value|(ISC_RESULTCLASS_DNS + 10)
end_define

begin_define
define|#
directive|define
name|DNS_R_DISALLOWED
value|(ISC_RESULTCLASS_DNS + 11)
end_define

begin_define
define|#
directive|define
name|DNS_R_EXTRATOKEN
value|(ISC_RESULTCLASS_DNS + 12)
end_define

begin_define
define|#
directive|define
name|DNS_R_EXTRADATA
value|(ISC_RESULTCLASS_DNS + 13)
end_define

begin_define
define|#
directive|define
name|DNS_R_TEXTTOOLONG
value|(ISC_RESULTCLASS_DNS + 14)
end_define

begin_define
define|#
directive|define
name|DNS_R_NOTZONETOP
value|(ISC_RESULTCLASS_DNS + 15)
end_define

begin_define
define|#
directive|define
name|DNS_R_SYNTAX
value|(ISC_RESULTCLASS_DNS + 16)
end_define

begin_define
define|#
directive|define
name|DNS_R_BADCKSUM
value|(ISC_RESULTCLASS_DNS + 17)
end_define

begin_define
define|#
directive|define
name|DNS_R_BADAAAA
value|(ISC_RESULTCLASS_DNS + 18)
end_define

begin_define
define|#
directive|define
name|DNS_R_NOOWNER
value|(ISC_RESULTCLASS_DNS + 19)
end_define

begin_define
define|#
directive|define
name|DNS_R_NOTTL
value|(ISC_RESULTCLASS_DNS + 20)
end_define

begin_define
define|#
directive|define
name|DNS_R_BADCLASS
value|(ISC_RESULTCLASS_DNS + 21)
end_define

begin_define
define|#
directive|define
name|DNS_R_NAMETOOLONG
value|(ISC_RESULTCLASS_DNS + 22)
end_define

begin_define
define|#
directive|define
name|DNS_R_PARTIALMATCH
value|(ISC_RESULTCLASS_DNS + 23)
end_define

begin_define
define|#
directive|define
name|DNS_R_NEWORIGIN
value|(ISC_RESULTCLASS_DNS + 24)
end_define

begin_define
define|#
directive|define
name|DNS_R_UNCHANGED
value|(ISC_RESULTCLASS_DNS + 25)
end_define

begin_define
define|#
directive|define
name|DNS_R_BADTTL
value|(ISC_RESULTCLASS_DNS + 26)
end_define

begin_define
define|#
directive|define
name|DNS_R_NOREDATA
value|(ISC_RESULTCLASS_DNS + 27)
end_define

begin_define
define|#
directive|define
name|DNS_R_CONTINUE
value|(ISC_RESULTCLASS_DNS + 28)
end_define

begin_define
define|#
directive|define
name|DNS_R_DELEGATION
value|(ISC_RESULTCLASS_DNS + 29)
end_define

begin_define
define|#
directive|define
name|DNS_R_GLUE
value|(ISC_RESULTCLASS_DNS + 30)
end_define

begin_define
define|#
directive|define
name|DNS_R_DNAME
value|(ISC_RESULTCLASS_DNS + 31)
end_define

begin_define
define|#
directive|define
name|DNS_R_CNAME
value|(ISC_RESULTCLASS_DNS + 32)
end_define

begin_define
define|#
directive|define
name|DNS_R_BADDB
value|(ISC_RESULTCLASS_DNS + 33)
end_define

begin_define
define|#
directive|define
name|DNS_R_ZONECUT
value|(ISC_RESULTCLASS_DNS + 34)
end_define

begin_define
define|#
directive|define
name|DNS_R_BADZONE
value|(ISC_RESULTCLASS_DNS + 35)
end_define

begin_define
define|#
directive|define
name|DNS_R_MOREDATA
value|(ISC_RESULTCLASS_DNS + 36)
end_define

begin_define
define|#
directive|define
name|DNS_R_UPTODATE
value|(ISC_RESULTCLASS_DNS + 37)
end_define

begin_define
define|#
directive|define
name|DNS_R_TSIGVERIFYFAILURE
value|(ISC_RESULTCLASS_DNS + 38)
end_define

begin_define
define|#
directive|define
name|DNS_R_TSIGERRORSET
value|(ISC_RESULTCLASS_DNS + 39)
end_define

begin_define
define|#
directive|define
name|DNS_R_SIGINVALID
value|(ISC_RESULTCLASS_DNS + 40)
end_define

begin_define
define|#
directive|define
name|DNS_R_SIGEXPIRED
value|(ISC_RESULTCLASS_DNS + 41)
end_define

begin_define
define|#
directive|define
name|DNS_R_SIGFUTURE
value|(ISC_RESULTCLASS_DNS + 42)
end_define

begin_define
define|#
directive|define
name|DNS_R_KEYUNAUTHORIZED
value|(ISC_RESULTCLASS_DNS + 43)
end_define

begin_define
define|#
directive|define
name|DNS_R_INVALIDTIME
value|(ISC_RESULTCLASS_DNS + 44)
end_define

begin_define
define|#
directive|define
name|DNS_R_EXPECTEDTSIG
value|(ISC_RESULTCLASS_DNS + 45)
end_define

begin_define
define|#
directive|define
name|DNS_R_UNEXPECTEDTSIG
value|(ISC_RESULTCLASS_DNS + 46)
end_define

begin_define
define|#
directive|define
name|DNS_R_INVALIDTKEY
value|(ISC_RESULTCLASS_DNS + 47)
end_define

begin_define
define|#
directive|define
name|DNS_R_HINT
value|(ISC_RESULTCLASS_DNS + 48)
end_define

begin_define
define|#
directive|define
name|DNS_R_DROP
value|(ISC_RESULTCLASS_DNS + 49)
end_define

begin_define
define|#
directive|define
name|DNS_R_NOTLOADED
value|(ISC_RESULTCLASS_DNS + 50)
end_define

begin_define
define|#
directive|define
name|DNS_R_NCACHENXDOMAIN
value|(ISC_RESULTCLASS_DNS + 51)
end_define

begin_define
define|#
directive|define
name|DNS_R_NCACHENXRRSET
value|(ISC_RESULTCLASS_DNS + 52)
end_define

begin_define
define|#
directive|define
name|DNS_R_WAIT
value|(ISC_RESULTCLASS_DNS + 53)
end_define

begin_define
define|#
directive|define
name|DNS_R_NOTVERIFIEDYET
value|(ISC_RESULTCLASS_DNS + 54)
end_define

begin_define
define|#
directive|define
name|DNS_R_NOIDENTITY
value|(ISC_RESULTCLASS_DNS + 55)
end_define

begin_define
define|#
directive|define
name|DNS_R_NOJOURNAL
value|(ISC_RESULTCLASS_DNS + 56)
end_define

begin_define
define|#
directive|define
name|DNS_R_ALIAS
value|(ISC_RESULTCLASS_DNS + 57)
end_define

begin_define
define|#
directive|define
name|DNS_R_USETCP
value|(ISC_RESULTCLASS_DNS + 58)
end_define

begin_define
define|#
directive|define
name|DNS_R_NOVALIDSIG
value|(ISC_RESULTCLASS_DNS + 59)
end_define

begin_define
define|#
directive|define
name|DNS_R_NOVALIDNSEC
value|(ISC_RESULTCLASS_DNS + 60)
end_define

begin_define
define|#
directive|define
name|DNS_R_NOTINSECURE
value|(ISC_RESULTCLASS_DNS + 61)
end_define

begin_define
define|#
directive|define
name|DNS_R_UNKNOWNSERVICE
value|(ISC_RESULTCLASS_DNS + 62)
end_define

begin_define
define|#
directive|define
name|DNS_R_RECOVERABLE
value|(ISC_RESULTCLASS_DNS + 63)
end_define

begin_define
define|#
directive|define
name|DNS_R_UNKNOWNOPT
value|(ISC_RESULTCLASS_DNS + 64)
end_define

begin_define
define|#
directive|define
name|DNS_R_UNEXPECTEDID
value|(ISC_RESULTCLASS_DNS + 65)
end_define

begin_define
define|#
directive|define
name|DNS_R_SEENINCLUDE
value|(ISC_RESULTCLASS_DNS + 66)
end_define

begin_define
define|#
directive|define
name|DNS_R_NOTEXACT
value|(ISC_RESULTCLASS_DNS + 67)
end_define

begin_define
define|#
directive|define
name|DNS_R_BLACKHOLED
value|(ISC_RESULTCLASS_DNS + 68)
end_define

begin_define
define|#
directive|define
name|DNS_R_BADALG
value|(ISC_RESULTCLASS_DNS + 69)
end_define

begin_define
define|#
directive|define
name|DNS_R_METATYPE
value|(ISC_RESULTCLASS_DNS + 70)
end_define

begin_define
define|#
directive|define
name|DNS_R_CNAMEANDOTHER
value|(ISC_RESULTCLASS_DNS + 71)
end_define

begin_define
define|#
directive|define
name|DNS_R_SINGLETON
value|(ISC_RESULTCLASS_DNS + 72)
end_define

begin_define
define|#
directive|define
name|DNS_R_HINTNXRRSET
value|(ISC_RESULTCLASS_DNS + 73)
end_define

begin_define
define|#
directive|define
name|DNS_R_NOMASTERFILE
value|(ISC_RESULTCLASS_DNS + 74)
end_define

begin_define
define|#
directive|define
name|DNS_R_UNKNOWNPROTO
value|(ISC_RESULTCLASS_DNS + 75)
end_define

begin_define
define|#
directive|define
name|DNS_R_CLOCKSKEW
value|(ISC_RESULTCLASS_DNS + 76)
end_define

begin_define
define|#
directive|define
name|DNS_R_BADIXFR
value|(ISC_RESULTCLASS_DNS + 77)
end_define

begin_define
define|#
directive|define
name|DNS_R_NOTAUTHORITATIVE
value|(ISC_RESULTCLASS_DNS + 78)
end_define

begin_define
define|#
directive|define
name|DNS_R_NOVALIDKEY
value|(ISC_RESULTCLASS_DNS + 79)
end_define

begin_define
define|#
directive|define
name|DNS_R_OBSOLETE
value|(ISC_RESULTCLASS_DNS + 80)
end_define

begin_define
define|#
directive|define
name|DNS_R_FROZEN
value|(ISC_RESULTCLASS_DNS + 81)
end_define

begin_define
define|#
directive|define
name|DNS_R_UNKNOWNFLAG
value|(ISC_RESULTCLASS_DNS + 82)
end_define

begin_define
define|#
directive|define
name|DNS_R_EXPECTEDRESPONSE
value|(ISC_RESULTCLASS_DNS + 83)
end_define

begin_define
define|#
directive|define
name|DNS_R_NOVALIDDS
value|(ISC_RESULTCLASS_DNS + 84)
end_define

begin_define
define|#
directive|define
name|DNS_R_NSISADDRESS
value|(ISC_RESULTCLASS_DNS + 85)
end_define

begin_define
define|#
directive|define
name|DNS_R_REMOTEFORMERR
value|(ISC_RESULTCLASS_DNS + 86)
end_define

begin_define
define|#
directive|define
name|DNS_R_TRUNCATEDTCP
value|(ISC_RESULTCLASS_DNS + 87)
end_define

begin_define
define|#
directive|define
name|DNS_R_LAME
value|(ISC_RESULTCLASS_DNS + 88)
end_define

begin_define
define|#
directive|define
name|DNS_R_UNEXPECTEDRCODE
value|(ISC_RESULTCLASS_DNS + 89)
end_define

begin_define
define|#
directive|define
name|DNS_R_UNEXPECTEDOPCODE
value|(ISC_RESULTCLASS_DNS + 90)
end_define

begin_define
define|#
directive|define
name|DNS_R_CHASEDSSERVERS
value|(ISC_RESULTCLASS_DNS + 91)
end_define

begin_define
define|#
directive|define
name|DNS_R_EMPTYNAME
value|(ISC_RESULTCLASS_DNS + 92)
end_define

begin_define
define|#
directive|define
name|DNS_R_EMPTYWILD
value|(ISC_RESULTCLASS_DNS + 93)
end_define

begin_define
define|#
directive|define
name|DNS_R_BADBITMAP
value|(ISC_RESULTCLASS_DNS + 94)
end_define

begin_define
define|#
directive|define
name|DNS_R_FROMWILDCARD
value|(ISC_RESULTCLASS_DNS + 95)
end_define

begin_define
define|#
directive|define
name|DNS_R_BADOWNERNAME
value|(ISC_RESULTCLASS_DNS + 96)
end_define

begin_define
define|#
directive|define
name|DNS_R_BADNAME
value|(ISC_RESULTCLASS_DNS + 97)
end_define

begin_define
define|#
directive|define
name|DNS_R_DYNAMIC
value|(ISC_RESULTCLASS_DNS + 98)
end_define

begin_define
define|#
directive|define
name|DNS_R_UNKNOWNCOMMAND
value|(ISC_RESULTCLASS_DNS + 99)
end_define

begin_define
define|#
directive|define
name|DNS_R_MUSTBESECURE
value|(ISC_RESULTCLASS_DNS + 100)
end_define

begin_define
define|#
directive|define
name|DNS_R_COVERINGNSEC
value|(ISC_RESULTCLASS_DNS + 101)
end_define

begin_define
define|#
directive|define
name|DNS_R_NRESULTS
value|102
end_define

begin_comment
comment|/* Number of results */
end_comment

begin_comment
comment|/*  * DNS wire format rcodes.  *  * By making these their own class we can easily convert them into the  * wire-format rcode value simply by masking off the resultclass.  */
end_comment

begin_define
define|#
directive|define
name|DNS_R_NOERROR
value|(ISC_RESULTCLASS_DNSRCODE + 0)
end_define

begin_define
define|#
directive|define
name|DNS_R_FORMERR
value|(ISC_RESULTCLASS_DNSRCODE + 1)
end_define

begin_define
define|#
directive|define
name|DNS_R_SERVFAIL
value|(ISC_RESULTCLASS_DNSRCODE + 2)
end_define

begin_define
define|#
directive|define
name|DNS_R_NXDOMAIN
value|(ISC_RESULTCLASS_DNSRCODE + 3)
end_define

begin_define
define|#
directive|define
name|DNS_R_NOTIMP
value|(ISC_RESULTCLASS_DNSRCODE + 4)
end_define

begin_define
define|#
directive|define
name|DNS_R_REFUSED
value|(ISC_RESULTCLASS_DNSRCODE + 5)
end_define

begin_define
define|#
directive|define
name|DNS_R_YXDOMAIN
value|(ISC_RESULTCLASS_DNSRCODE + 6)
end_define

begin_define
define|#
directive|define
name|DNS_R_YXRRSET
value|(ISC_RESULTCLASS_DNSRCODE + 7)
end_define

begin_define
define|#
directive|define
name|DNS_R_NXRRSET
value|(ISC_RESULTCLASS_DNSRCODE + 8)
end_define

begin_define
define|#
directive|define
name|DNS_R_NOTAUTH
value|(ISC_RESULTCLASS_DNSRCODE + 9)
end_define

begin_define
define|#
directive|define
name|DNS_R_NOTZONE
value|(ISC_RESULTCLASS_DNSRCODE + 10)
end_define

begin_define
define|#
directive|define
name|DNS_R_BADVERS
value|(ISC_RESULTCLASS_DNSRCODE + 16)
end_define

begin_define
define|#
directive|define
name|DNS_R_NRCODERESULTS
value|17
end_define

begin_comment
comment|/* Number of rcode results */
end_comment

begin_define
define|#
directive|define
name|DNS_RESULT_ISRCODE
parameter_list|(
name|result
parameter_list|)
define|\
value|(ISC_RESULTCLASS_INCLASS(ISC_RESULTCLASS_DNSRCODE, (result)))
end_define

begin_function_decl
name|ISC_LANG_BEGINDECLS
specifier|const
name|char
modifier|*
name|dns_result_totext
parameter_list|(
name|isc_result_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|dns_result_register
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|dns_rcode_t
name|dns_result_torcode
parameter_list|(
name|isc_result_t
name|result
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
comment|/* DNS_RESULT_H */
end_comment

end_unit

