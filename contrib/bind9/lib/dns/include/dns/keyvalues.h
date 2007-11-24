begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (C) 2004  Internet Systems Consortium, Inc. ("ISC")  * Copyright (C) 1999-2001, 2003  Internet Software Consortium.  *  * Permission to use, copy, modify, and distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND ISC DISCLAIMS ALL WARRANTIES WITH  * REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY  * AND FITNESS.  IN NO EVENT SHALL ISC BE LIABLE FOR ANY SPECIAL, DIRECT,  * INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM  * LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE  * OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR  * PERFORMANCE OF THIS SOFTWARE.  */
end_comment

begin_comment
comment|/* $Id: keyvalues.h,v 1.11.12.3 2004/03/06 08:13:56 marka Exp $ */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|DNS_KEYVALUES_H
end_ifndef

begin_define
define|#
directive|define
name|DNS_KEYVALUES_H
value|1
end_define

begin_comment
comment|/*  * Flags field of the KEY RR rdata  */
end_comment

begin_define
define|#
directive|define
name|DNS_KEYFLAG_TYPEMASK
value|0xC000
end_define

begin_comment
comment|/* Mask for "type" bits */
end_comment

begin_define
define|#
directive|define
name|DNS_KEYTYPE_AUTHCONF
value|0x0000
end_define

begin_comment
comment|/* Key usable for both */
end_comment

begin_define
define|#
directive|define
name|DNS_KEYTYPE_CONFONLY
value|0x8000
end_define

begin_comment
comment|/* Key usable for confidentiality */
end_comment

begin_define
define|#
directive|define
name|DNS_KEYTYPE_AUTHONLY
value|0x4000
end_define

begin_comment
comment|/* Key usable for authentication */
end_comment

begin_define
define|#
directive|define
name|DNS_KEYTYPE_NOKEY
value|0xC000
end_define

begin_comment
comment|/* No key usable for either; no key */
end_comment

begin_define
define|#
directive|define
name|DNS_KEYTYPE_NOAUTH
value|DNS_KEYTYPE_CONFONLY
end_define

begin_define
define|#
directive|define
name|DNS_KEYTYPE_NOCONF
value|DNS_KEYTYPE_AUTHONLY
end_define

begin_define
define|#
directive|define
name|DNS_KEYFLAG_RESERVED2
value|0x2000
end_define

begin_comment
comment|/* reserved - must be zero */
end_comment

begin_define
define|#
directive|define
name|DNS_KEYFLAG_EXTENDED
value|0x1000
end_define

begin_comment
comment|/* key has extended flags */
end_comment

begin_define
define|#
directive|define
name|DNS_KEYFLAG_RESERVED4
value|0x0800
end_define

begin_comment
comment|/* reserved - must be zero */
end_comment

begin_define
define|#
directive|define
name|DNS_KEYFLAG_RESERVED5
value|0x0400
end_define

begin_comment
comment|/* reserved - must be zero */
end_comment

begin_define
define|#
directive|define
name|DNS_KEYFLAG_OWNERMASK
value|0x0300
end_define

begin_comment
comment|/* these bits determine the type */
end_comment

begin_define
define|#
directive|define
name|DNS_KEYOWNER_USER
value|0x0000
end_define

begin_comment
comment|/* key is assoc. with user */
end_comment

begin_define
define|#
directive|define
name|DNS_KEYOWNER_ENTITY
value|0x0200
end_define

begin_comment
comment|/* key is assoc. with entity eg host */
end_comment

begin_define
define|#
directive|define
name|DNS_KEYOWNER_ZONE
value|0x0100
end_define

begin_comment
comment|/* key is zone key */
end_comment

begin_define
define|#
directive|define
name|DNS_KEYOWNER_RESERVED
value|0x0300
end_define

begin_comment
comment|/* reserved meaning */
end_comment

begin_define
define|#
directive|define
name|DNS_KEYFLAG_RESERVED8
value|0x0080
end_define

begin_comment
comment|/* reserved - must be zero */
end_comment

begin_define
define|#
directive|define
name|DNS_KEYFLAG_RESERVED9
value|0x0040
end_define

begin_comment
comment|/* reserved - must be zero */
end_comment

begin_define
define|#
directive|define
name|DNS_KEYFLAG_RESERVED10
value|0x0020
end_define

begin_comment
comment|/* reserved - must be zero */
end_comment

begin_define
define|#
directive|define
name|DNS_KEYFLAG_RESERVED11
value|0x0010
end_define

begin_comment
comment|/* reserved - must be zero */
end_comment

begin_define
define|#
directive|define
name|DNS_KEYFLAG_SIGNATORYMASK
value|0x000F
end_define

begin_comment
comment|/* key can sign RR's of same name */
end_comment

begin_define
define|#
directive|define
name|DNS_KEYFLAG_RESERVEDMASK
value|(DNS_KEYFLAG_RESERVED2 | \ 				  DNS_KEYFLAG_RESERVED4 | \ 				  DNS_KEYFLAG_RESERVED5 | \ 				  DNS_KEYFLAG_RESERVED8 | \ 				  DNS_KEYFLAG_RESERVED9 | \ 				  DNS_KEYFLAG_RESERVED10 | \ 				  DNS_KEYFLAG_RESERVED11 )
end_define

begin_define
define|#
directive|define
name|DNS_KEYFLAG_KSK
value|0x0001
end_define

begin_comment
comment|/* key signing key */
end_comment

begin_define
define|#
directive|define
name|DNS_KEYFLAG_RESERVEDMASK2
value|0xFFFF
end_define

begin_comment
comment|/* no bits defined here */
end_comment

begin_comment
comment|/* The Algorithm field of the KEY and SIG RR's is an integer, {1..254} */
end_comment

begin_define
define|#
directive|define
name|DNS_KEYALG_RSAMD5
value|1
end_define

begin_comment
comment|/* RSA with MD5 */
end_comment

begin_define
define|#
directive|define
name|DNS_KEYALG_RSA
value|DNS_KEYALG_RSAMD5
end_define

begin_define
define|#
directive|define
name|DNS_KEYALG_DH
value|2
end_define

begin_comment
comment|/* Diffie Hellman KEY */
end_comment

begin_define
define|#
directive|define
name|DNS_KEYALG_DSA
value|3
end_define

begin_comment
comment|/* DSA KEY */
end_comment

begin_define
define|#
directive|define
name|DNS_KEYALG_DSS
value|NS_ALG_DSA
end_define

begin_define
define|#
directive|define
name|DNS_KEYALG_ECC
value|4
end_define

begin_define
define|#
directive|define
name|DNS_KEYALG_RSASHA1
value|5
end_define

begin_define
define|#
directive|define
name|DNS_KEYALG_INDIRECT
value|252
end_define

begin_define
define|#
directive|define
name|DNS_KEYALG_PRIVATEDNS
value|253
end_define

begin_define
define|#
directive|define
name|DNS_KEYALG_PRIVATEOID
value|254
end_define

begin_comment
comment|/* Key begins with OID giving alg */
end_comment

begin_comment
comment|/* Protocol values  */
end_comment

begin_define
define|#
directive|define
name|DNS_KEYPROTO_RESERVED
value|0
end_define

begin_define
define|#
directive|define
name|DNS_KEYPROTO_TLS
value|1
end_define

begin_define
define|#
directive|define
name|DNS_KEYPROTO_EMAIL
value|2
end_define

begin_define
define|#
directive|define
name|DNS_KEYPROTO_DNSSEC
value|3
end_define

begin_define
define|#
directive|define
name|DNS_KEYPROTO_IPSEC
value|4
end_define

begin_define
define|#
directive|define
name|DNS_KEYPROTO_ANY
value|255
end_define

begin_comment
comment|/* Signatures */
end_comment

begin_define
define|#
directive|define
name|DNS_SIG_RSAMINBITS
value|512
end_define

begin_comment
comment|/* Size of a mod or exp in bits */
end_comment

begin_define
define|#
directive|define
name|DNS_SIG_RSAMAXBITS
value|2552
end_define

begin_comment
comment|/* Total of binary mod and exp */
end_comment

begin_define
define|#
directive|define
name|DNS_SIG_RSAMAXBYTES
value|((DNS_SIG_RSAMAXBITS+7/8)*2+3)
end_define

begin_comment
comment|/* Max length of text sig block */
end_comment

begin_define
define|#
directive|define
name|DNS_SIG_RSAMAXBASE64
value|(((DNS_SIG_RSAMAXBYTES+2)/3)*4)
end_define

begin_define
define|#
directive|define
name|DNS_SIG_RSAMINSIZE
value|((DNS_SIG_RSAMINBITS+7)/8)
end_define

begin_define
define|#
directive|define
name|DNS_SIG_RSAMAXSIZE
value|((DNS_SIG_RSAMAXBITS+7)/8)
end_define

begin_define
define|#
directive|define
name|DNS_SIG_DSASIGSIZE
value|41
end_define

begin_define
define|#
directive|define
name|DNS_SIG_DSAMINBITS
value|512
end_define

begin_define
define|#
directive|define
name|DNS_SIG_DSAMAXBITS
value|1024
end_define

begin_define
define|#
directive|define
name|DNS_SIG_DSAMINBYTES
value|213
end_define

begin_define
define|#
directive|define
name|DNS_SIG_DSAMAXBYTES
value|405
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* DNS_KEYVALUES_H */
end_comment

end_unit

