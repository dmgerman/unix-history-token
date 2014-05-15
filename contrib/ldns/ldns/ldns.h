begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * dns.h -- defines for the Domain Name System  *  * Copyright (c) 2005-2008, NLnet Labs. All rights reserved.  *  * See LICENSE for the license.  *  * This library was created by:  * Jelte Jansen, Erik Rozendaal and Miek Gieben  *  * A bunch of defines that are used in the DNS.  */
end_comment

begin_comment
comment|/** \mainpage LDNS Documentation  \section introduction Introduction  The goal of ldns is to simplify DNS programming, it supports recent RFCs like the DNSSEC documents, and allow developers to easily create software conforming to current RFCs, and experimental software for current Internet drafts. A secondary benefit of using ldns is speed, because ldns is written in C, and although it is not optimized for performance, it should be a lot faster than Perl.  The first main tool to use ldns is Drill, from which part of the library was derived. From version 1.0.0 on, drill is included in the ldns release and will not be distributed separately anymore. The library also includes some other examples and tools to show how it can be used. These can be found in the examples/ directory in the tarball.  ldns depends on OpenSSL for it's cryptographic functions. Feature list    - Transparent IPv4 and IPv6 support (overridable if necessary),   - TSIG support,   - DNSSEC support; signing and verification,   - small size,   - online documentation as well as manual pages.  If you want to send us patches please use the code from git.  \section using_ldns Using ldns  Almost all interaction between an application and ldns goes through the ldns data structures (\ref ldns_rr, \ref ldns_pkt, etc.). These are input or output to the functions of ldns. For example, \ref ldns_zone_new_frm_fp reads a zone from a \c FILE pointer, and returns an \ref ldns_zone structure.   Let's use Drill as an example. Drill is a tool much like dig, whose most basic function is to send 1 query to a nameserver and print the response.  To be able to do this, drill uses the resolver module of ldns, which acts as a stub resolver. The resolver module uses the net module to actually send the query that drill requested. It then uses the wire2host module to translate the response and place it in ldns' internal structures. These are passed back to drill, which then uses the host2str module to print the response in presentation format.  \section gettingstarted Getting Started  See the \ref design page for a very high level description of the design choices made for ldns.   For an overview of the functions and types ldns provides, you can check out the \ref ldns ldns header file descriptions.  If you want to see some libdns action, you can read our tutorials:   - \ref tutorial1_mx   - \ref tutorial2_zone   - \ref tutorial3_signzone  Or you can just use the menu above to browse through the API docs.<div style="visibility:hidden;"> \image html LogoInGradientBar2-y100.png</div> */
end_comment

begin_comment
comment|/**  * \file ldns.h  *  * Including this file will include all ldns files, and define some lookup tables.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|LDNS_DNS_H
end_ifndef

begin_define
define|#
directive|define
name|LDNS_DNS_H
end_define

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_include
include|#
directive|include
file|<ldns/util.h>
end_include

begin_include
include|#
directive|include
file|<ldns/buffer.h>
end_include

begin_include
include|#
directive|include
file|<ldns/common.h>
end_include

begin_include
include|#
directive|include
file|<ldns/dane.h>
end_include

begin_include
include|#
directive|include
file|<ldns/dname.h>
end_include

begin_include
include|#
directive|include
file|<ldns/dnssec.h>
end_include

begin_include
include|#
directive|include
file|<ldns/dnssec_verify.h>
end_include

begin_include
include|#
directive|include
file|<ldns/dnssec_sign.h>
end_include

begin_include
include|#
directive|include
file|<ldns/duration.h>
end_include

begin_include
include|#
directive|include
file|<ldns/error.h>
end_include

begin_include
include|#
directive|include
file|<ldns/higher.h>
end_include

begin_include
include|#
directive|include
file|<ldns/host2str.h>
end_include

begin_include
include|#
directive|include
file|<ldns/host2wire.h>
end_include

begin_include
include|#
directive|include
file|<ldns/net.h>
end_include

begin_include
include|#
directive|include
file|<ldns/packet.h>
end_include

begin_include
include|#
directive|include
file|<ldns/rdata.h>
end_include

begin_include
include|#
directive|include
file|<ldns/resolver.h>
end_include

begin_include
include|#
directive|include
file|<ldns/rr.h>
end_include

begin_include
include|#
directive|include
file|<ldns/str2host.h>
end_include

begin_include
include|#
directive|include
file|<ldns/tsig.h>
end_include

begin_include
include|#
directive|include
file|<ldns/update.h>
end_include

begin_include
include|#
directive|include
file|<ldns/wire2host.h>
end_include

begin_include
include|#
directive|include
file|<ldns/rr_functions.h>
end_include

begin_include
include|#
directive|include
file|<ldns/keys.h>
end_include

begin_include
include|#
directive|include
file|<ldns/parse.h>
end_include

begin_include
include|#
directive|include
file|<ldns/zone.h>
end_include

begin_include
include|#
directive|include
file|<ldns/dnssec_zone.h>
end_include

begin_include
include|#
directive|include
file|<ldns/radix.h>
end_include

begin_include
include|#
directive|include
file|<ldns/rbtree.h>
end_include

begin_include
include|#
directive|include
file|<ldns/sha1.h>
end_include

begin_include
include|#
directive|include
file|<ldns/sha2.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|__cplusplus
end_ifdef

begin_extern
extern|extern
literal|"C"
block|{
endif|#
directive|endif
define|#
directive|define
name|LDNS_IP4ADDRLEN
value|(32/8)
define|#
directive|define
name|LDNS_IP6ADDRLEN
value|(128/8)
define|#
directive|define
name|LDNS_PORT
value|53
define|#
directive|define
name|LDNS_ROOT_LABEL_STR
value|"."
define|#
directive|define
name|LDNS_DEFAULT_TTL
value|3600
comment|/* lookup tables for standard DNS stuff  */
comment|/** Taken from RFC 2538, section 2.1.  */
specifier|extern
name|ldns_lookup_table
name|ldns_certificate_types
index|[]
decl_stmt|;
comment|/** Taken from RFC 2535, section 7.  */
specifier|extern
name|ldns_lookup_table
name|ldns_algorithms
index|[]
decl_stmt|;
comment|/** Taken from RFC 2538.  */
specifier|extern
name|ldns_lookup_table
name|ldns_cert_algorithms
index|[]
decl_stmt|;
comment|/** rr types  */
specifier|extern
name|ldns_lookup_table
name|ldns_rr_classes
index|[]
decl_stmt|;
comment|/** Response codes */
specifier|extern
name|ldns_lookup_table
name|ldns_rcodes
index|[]
decl_stmt|;
comment|/** Operation codes */
specifier|extern
name|ldns_lookup_table
name|ldns_opcodes
index|[]
decl_stmt|;
comment|/** EDNS flags */
specifier|extern
name|ldns_lookup_table
name|ldns_edns_flags
index|[]
decl_stmt|;
ifdef|#
directive|ifdef
name|__cplusplus
block|}
end_extern

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* LDNS_DNS_H */
end_comment

end_unit

