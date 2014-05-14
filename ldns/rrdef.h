begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * rrdef.h  *  * RR definitions  *  * a Net::DNS like library for C  *  * (c) NLnet Labs, 2005-2006  *  * See the file LICENSE for the license  */
end_comment

begin_comment
comment|/**  * \file  *  * Defines resource record types and constants.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|LDNS_RRDEF_H
end_ifndef

begin_define
define|#
directive|define
name|LDNS_RRDEF_H
end_define

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
comment|/** Maximum length of a dname label */
define|#
directive|define
name|LDNS_MAX_LABELLEN
value|63
comment|/** Maximum length of a complete dname */
define|#
directive|define
name|LDNS_MAX_DOMAINLEN
value|255
comment|/** Maximum number of pointers in 1 dname */
define|#
directive|define
name|LDNS_MAX_POINTERS
value|65535
comment|/** The bytes TTL, CLASS and length use up in an rr */
define|#
directive|define
name|LDNS_RR_OVERHEAD
value|10
define|#
directive|define
name|LDNS_DNSSEC_KEYPROTO
value|3
define|#
directive|define
name|LDNS_KEY_ZONE_KEY
value|0x0100
comment|/* set for ZSK&KSK, rfc 4034 */
define|#
directive|define
name|LDNS_KEY_SEP_KEY
value|0x0001
comment|/* set for KSK, rfc 4034 */
define|#
directive|define
name|LDNS_KEY_REVOKE_KEY
value|0x0080
comment|/* used to revoke KSK, rfc 5011 */
comment|/* The first fields are contiguous and can be referenced instantly */
define|#
directive|define
name|LDNS_RDATA_FIELD_DESCRIPTORS_COMMON
value|258
comment|/** lookuptable for rr classes  */
specifier|extern
name|struct
name|sldns_struct_lookup_table
modifier|*
name|sldns_rr_classes
decl_stmt|;
comment|/**  *  The different RR classes.  */
enum|enum
name|sldns_enum_rr_class
block|{
comment|/** the Internet */
name|LDNS_RR_CLASS_IN
init|=
literal|1
block|,
comment|/** Chaos class */
name|LDNS_RR_CLASS_CH
init|=
literal|3
block|,
comment|/** Hesiod (Dyer 87) */
name|LDNS_RR_CLASS_HS
init|=
literal|4
block|,
comment|/** None class, dynamic update */
name|LDNS_RR_CLASS_NONE
init|=
literal|254
block|,
comment|/** Any class */
name|LDNS_RR_CLASS_ANY
init|=
literal|255
block|,
name|LDNS_RR_CLASS_FIRST
init|=
literal|0
block|,
name|LDNS_RR_CLASS_LAST
init|=
literal|65535
block|,
name|LDNS_RR_CLASS_COUNT
init|=
name|LDNS_RR_CLASS_LAST
operator|-
name|LDNS_RR_CLASS_FIRST
operator|+
literal|1
block|}
enum|;
typedef|typedef
name|enum
name|sldns_enum_rr_class
name|sldns_rr_class
typedef|;
comment|/**  *  Used to specify whether compression is allowed.  */
enum|enum
name|sldns_enum_rr_compress
block|{
comment|/** compression is allowed */
name|LDNS_RR_COMPRESS
block|,
name|LDNS_RR_NO_COMPRESS
block|}
enum|;
typedef|typedef
name|enum
name|sldns_enum_rr_compress
name|sldns_rr_compress
typedef|;
comment|/**  * The different RR types.  */
enum|enum
name|sldns_enum_rr_type
block|{
comment|/**  a host address */
name|LDNS_RR_TYPE_A
init|=
literal|1
block|,
comment|/**  an authoritative name server */
name|LDNS_RR_TYPE_NS
init|=
literal|2
block|,
comment|/**  a mail destination (Obsolete - use MX) */
name|LDNS_RR_TYPE_MD
init|=
literal|3
block|,
comment|/**  a mail forwarder (Obsolete - use MX) */
name|LDNS_RR_TYPE_MF
init|=
literal|4
block|,
comment|/**  the canonical name for an alias */
name|LDNS_RR_TYPE_CNAME
init|=
literal|5
block|,
comment|/**  marks the start of a zone of authority */
name|LDNS_RR_TYPE_SOA
init|=
literal|6
block|,
comment|/**  a mailbox domain name (EXPERIMENTAL) */
name|LDNS_RR_TYPE_MB
init|=
literal|7
block|,
comment|/**  a mail group member (EXPERIMENTAL) */
name|LDNS_RR_TYPE_MG
init|=
literal|8
block|,
comment|/**  a mail rename domain name (EXPERIMENTAL) */
name|LDNS_RR_TYPE_MR
init|=
literal|9
block|,
comment|/**  a null RR (EXPERIMENTAL) */
name|LDNS_RR_TYPE_NULL
init|=
literal|10
block|,
comment|/**  a well known service description */
name|LDNS_RR_TYPE_WKS
init|=
literal|11
block|,
comment|/**  a domain name pointer */
name|LDNS_RR_TYPE_PTR
init|=
literal|12
block|,
comment|/**  host information */
name|LDNS_RR_TYPE_HINFO
init|=
literal|13
block|,
comment|/**  mailbox or mail list information */
name|LDNS_RR_TYPE_MINFO
init|=
literal|14
block|,
comment|/**  mail exchange */
name|LDNS_RR_TYPE_MX
init|=
literal|15
block|,
comment|/**  text strings */
name|LDNS_RR_TYPE_TXT
init|=
literal|16
block|,
comment|/**  RFC1183 */
name|LDNS_RR_TYPE_RP
init|=
literal|17
block|,
comment|/**  RFC1183 */
name|LDNS_RR_TYPE_AFSDB
init|=
literal|18
block|,
comment|/**  RFC1183 */
name|LDNS_RR_TYPE_X25
init|=
literal|19
block|,
comment|/**  RFC1183 */
name|LDNS_RR_TYPE_ISDN
init|=
literal|20
block|,
comment|/**  RFC1183 */
name|LDNS_RR_TYPE_RT
init|=
literal|21
block|,
comment|/**  RFC1706 */
name|LDNS_RR_TYPE_NSAP
init|=
literal|22
block|,
comment|/**  RFC1348 */
name|LDNS_RR_TYPE_NSAP_PTR
init|=
literal|23
block|,
comment|/**  2535typecode */
name|LDNS_RR_TYPE_SIG
init|=
literal|24
block|,
comment|/**  2535typecode */
name|LDNS_RR_TYPE_KEY
init|=
literal|25
block|,
comment|/**  RFC2163 */
name|LDNS_RR_TYPE_PX
init|=
literal|26
block|,
comment|/**  RFC1712 */
name|LDNS_RR_TYPE_GPOS
init|=
literal|27
block|,
comment|/**  ipv6 address */
name|LDNS_RR_TYPE_AAAA
init|=
literal|28
block|,
comment|/**  LOC record  RFC1876 */
name|LDNS_RR_TYPE_LOC
init|=
literal|29
block|,
comment|/**  2535typecode */
name|LDNS_RR_TYPE_NXT
init|=
literal|30
block|,
comment|/**  draft-ietf-nimrod-dns-01.txt */
name|LDNS_RR_TYPE_EID
init|=
literal|31
block|,
comment|/**  draft-ietf-nimrod-dns-01.txt */
name|LDNS_RR_TYPE_NIMLOC
init|=
literal|32
block|,
comment|/**  SRV record RFC2782 */
name|LDNS_RR_TYPE_SRV
init|=
literal|33
block|,
comment|/**  http://www.jhsoft.com/rfc/af-saa-0069.000.rtf */
name|LDNS_RR_TYPE_ATMA
init|=
literal|34
block|,
comment|/**  RFC2915 */
name|LDNS_RR_TYPE_NAPTR
init|=
literal|35
block|,
comment|/**  RFC2230 */
name|LDNS_RR_TYPE_KX
init|=
literal|36
block|,
comment|/**  RFC2538 */
name|LDNS_RR_TYPE_CERT
init|=
literal|37
block|,
comment|/**  RFC2874 */
name|LDNS_RR_TYPE_A6
init|=
literal|38
block|,
comment|/**  RFC2672 */
name|LDNS_RR_TYPE_DNAME
init|=
literal|39
block|,
comment|/**  dnsind-kitchen-sink-02.txt */
name|LDNS_RR_TYPE_SINK
init|=
literal|40
block|,
comment|/**  Pseudo OPT record... */
name|LDNS_RR_TYPE_OPT
init|=
literal|41
block|,
comment|/**  RFC3123 */
name|LDNS_RR_TYPE_APL
init|=
literal|42
block|,
comment|/**  RFC4034, RFC3658 */
name|LDNS_RR_TYPE_DS
init|=
literal|43
block|,
comment|/**  SSH Key Fingerprint */
name|LDNS_RR_TYPE_SSHFP
init|=
literal|44
block|,
comment|/* RFC 4255 */
comment|/**  IPsec Key */
name|LDNS_RR_TYPE_IPSECKEY
init|=
literal|45
block|,
comment|/* RFC 4025 */
comment|/**  DNSSEC */
name|LDNS_RR_TYPE_RRSIG
init|=
literal|46
block|,
comment|/* RFC 4034 */
name|LDNS_RR_TYPE_NSEC
init|=
literal|47
block|,
comment|/* RFC 4034 */
name|LDNS_RR_TYPE_DNSKEY
init|=
literal|48
block|,
comment|/* RFC 4034 */
name|LDNS_RR_TYPE_DHCID
init|=
literal|49
block|,
comment|/* RFC 4701 */
comment|/* NSEC3 */
name|LDNS_RR_TYPE_NSEC3
init|=
literal|50
block|,
comment|/* RFC 5155 */
name|LDNS_RR_TYPE_NSEC3PARAM
init|=
literal|51
block|,
comment|/* RFC 5155 */
name|LDNS_RR_TYPE_NSEC3PARAMS
init|=
literal|51
block|,
name|LDNS_RR_TYPE_TLSA
init|=
literal|52
block|,
comment|/* RFC 6698 */
name|LDNS_RR_TYPE_HIP
init|=
literal|55
block|,
comment|/* RFC 5205 */
comment|/** draft-reid-dnsext-zs */
name|LDNS_RR_TYPE_NINFO
init|=
literal|56
block|,
comment|/** draft-reid-dnsext-rkey */
name|LDNS_RR_TYPE_RKEY
init|=
literal|57
block|,
comment|/** draft-ietf-dnsop-trust-history */
name|LDNS_RR_TYPE_TALINK
init|=
literal|58
block|,
comment|/** draft-barwood-dnsop-ds-publis */
name|LDNS_RR_TYPE_CDS
init|=
literal|59
block|,
name|LDNS_RR_TYPE_SPF
init|=
literal|99
block|,
comment|/* RFC 4408 */
name|LDNS_RR_TYPE_UINFO
init|=
literal|100
block|,
name|LDNS_RR_TYPE_UID
init|=
literal|101
block|,
name|LDNS_RR_TYPE_GID
init|=
literal|102
block|,
name|LDNS_RR_TYPE_UNSPEC
init|=
literal|103
block|,
name|LDNS_RR_TYPE_NID
init|=
literal|104
block|,
comment|/* RFC 6742 */
name|LDNS_RR_TYPE_L32
init|=
literal|105
block|,
comment|/* RFC 6742 */
name|LDNS_RR_TYPE_L64
init|=
literal|106
block|,
comment|/* RFC 6742 */
name|LDNS_RR_TYPE_LP
init|=
literal|107
block|,
comment|/* RFC 6742 */
comment|/** draft-jabley-dnsext-eui48-eui64-rrtypes */
name|LDNS_RR_TYPE_EUI48
init|=
literal|108
block|,
name|LDNS_RR_TYPE_EUI64
init|=
literal|109
block|,
name|LDNS_RR_TYPE_TKEY
init|=
literal|249
block|,
comment|/* RFC 2930 */
name|LDNS_RR_TYPE_TSIG
init|=
literal|250
block|,
name|LDNS_RR_TYPE_IXFR
init|=
literal|251
block|,
name|LDNS_RR_TYPE_AXFR
init|=
literal|252
block|,
comment|/**  A request for mailbox-related records (MB, MG or MR) */
name|LDNS_RR_TYPE_MAILB
init|=
literal|253
block|,
comment|/**  A request for mail agent RRs (Obsolete - see MX) */
name|LDNS_RR_TYPE_MAILA
init|=
literal|254
block|,
comment|/**  any type (wildcard) */
name|LDNS_RR_TYPE_ANY
init|=
literal|255
block|,
comment|/** draft-faltstrom-uri-06 */
name|LDNS_RR_TYPE_URI
init|=
literal|256
block|,
name|LDNS_RR_TYPE_CAA
init|=
literal|257
block|,
comment|/* RFC 6844 */
comment|/** DNSSEC Trust Authorities */
name|LDNS_RR_TYPE_TA
init|=
literal|32768
block|,
comment|/* RFC 4431, 5074, DNSSEC Lookaside Validation */
name|LDNS_RR_TYPE_DLV
init|=
literal|32769
block|,
comment|/* type codes from nsec3 experimental phase 	LDNS_RR_TYPE_NSEC3 = 65324, 	LDNS_RR_TYPE_NSEC3PARAMS = 65325, */
name|LDNS_RR_TYPE_FIRST
init|=
literal|0
block|,
name|LDNS_RR_TYPE_LAST
init|=
literal|65535
block|,
name|LDNS_RR_TYPE_COUNT
init|=
name|LDNS_RR_TYPE_LAST
operator|-
name|LDNS_RR_TYPE_FIRST
operator|+
literal|1
block|}
enum|;
typedef|typedef
name|enum
name|sldns_enum_rr_type
name|sldns_rr_type
typedef|;
comment|/* RDATA */
define|#
directive|define
name|LDNS_MAX_RDFLEN
value|65535
define|#
directive|define
name|LDNS_RDF_SIZE_BYTE
value|1
define|#
directive|define
name|LDNS_RDF_SIZE_WORD
value|2
define|#
directive|define
name|LDNS_RDF_SIZE_DOUBLEWORD
value|4
define|#
directive|define
name|LDNS_RDF_SIZE_6BYTES
value|6
define|#
directive|define
name|LDNS_RDF_SIZE_8BYTES
value|8
define|#
directive|define
name|LDNS_RDF_SIZE_16BYTES
value|16
define|#
directive|define
name|LDNS_NSEC3_VARS_OPTOUT_MASK
value|0x01
define|#
directive|define
name|LDNS_APL_IP4
value|1
define|#
directive|define
name|LDNS_APL_IP6
value|2
define|#
directive|define
name|LDNS_APL_MASK
value|0x7f
define|#
directive|define
name|LDNS_APL_NEGATION
value|0x80
comment|/**  * The different types of RDATA fields.  */
enum|enum
name|sldns_enum_rdf_type
block|{
comment|/** none */
name|LDNS_RDF_TYPE_NONE
block|,
comment|/** domain name */
name|LDNS_RDF_TYPE_DNAME
block|,
comment|/** 8 bits */
name|LDNS_RDF_TYPE_INT8
block|,
comment|/** 16 bits */
name|LDNS_RDF_TYPE_INT16
block|,
comment|/** 32 bits */
name|LDNS_RDF_TYPE_INT32
block|,
comment|/** A record */
name|LDNS_RDF_TYPE_A
block|,
comment|/** AAAA record */
name|LDNS_RDF_TYPE_AAAA
block|,
comment|/** txt string */
name|LDNS_RDF_TYPE_STR
block|,
comment|/** apl data */
name|LDNS_RDF_TYPE_APL
block|,
comment|/** b32 string */
name|LDNS_RDF_TYPE_B32_EXT
block|,
comment|/** b64 string */
name|LDNS_RDF_TYPE_B64
block|,
comment|/** hex string */
name|LDNS_RDF_TYPE_HEX
block|,
comment|/** nsec type codes */
name|LDNS_RDF_TYPE_NSEC
block|,
comment|/** a RR type */
name|LDNS_RDF_TYPE_TYPE
block|,
comment|/** a class */
name|LDNS_RDF_TYPE_CLASS
block|,
comment|/** certificate algorithm */
name|LDNS_RDF_TYPE_CERT_ALG
block|,
comment|/** a key algorithm */
name|LDNS_RDF_TYPE_ALG
block|,
comment|/** unknown types */
name|LDNS_RDF_TYPE_UNKNOWN
block|,
comment|/** time (32 bits) */
name|LDNS_RDF_TYPE_TIME
block|,
comment|/** period */
name|LDNS_RDF_TYPE_PERIOD
block|,
comment|/** tsig time 48 bits */
name|LDNS_RDF_TYPE_TSIGTIME
block|,
comment|/** Represents the Public Key Algorithm, HIT and Public Key fields 	    for the HIP RR types.  A HIP specific rdf type is used because of 	    the unusual layout in wireformat (see RFC 5205 Section 5) */
name|LDNS_RDF_TYPE_HIP
block|,
comment|/** variable length any type rdata where the length             is specified by the first 2 bytes */
name|LDNS_RDF_TYPE_INT16_DATA
block|,
comment|/** protocol and port bitmaps */
name|LDNS_RDF_TYPE_SERVICE
block|,
comment|/** location data */
name|LDNS_RDF_TYPE_LOC
block|,
comment|/** well known services */
name|LDNS_RDF_TYPE_WKS
block|,
comment|/** NSAP */
name|LDNS_RDF_TYPE_NSAP
block|,
comment|/** ATMA */
name|LDNS_RDF_TYPE_ATMA
block|,
comment|/** IPSECKEY */
name|LDNS_RDF_TYPE_IPSECKEY
block|,
comment|/** nsec3 hash salt */
name|LDNS_RDF_TYPE_NSEC3_SALT
block|,
comment|/** nsec3 base32 string (with length byte on wire */
name|LDNS_RDF_TYPE_NSEC3_NEXT_OWNER
block|,
comment|/** 4 shorts represented as 4 * 16 bit hex numbers          *  seperated by colons. For NID and L64.          */
name|LDNS_RDF_TYPE_ILNP64
block|,
comment|/** 6 * 8 bit hex numbers seperated by dashes. For EUI48. */
name|LDNS_RDF_TYPE_EUI48
block|,
comment|/** 8 * 8 bit hex numbers seperated by dashes. For EUI64. */
name|LDNS_RDF_TYPE_EUI64
block|,
comment|/** A non-zero sequence of US-ASCII letters and numbers in lower case.          *  For CAA.          */
name|LDNS_RDF_TYPE_TAG
block|,
comment|/** A<character-string> encoding of the value field as specified           * [RFC1035], Section 5.1., encoded as remaining rdata.          * For CAA.          */
name|LDNS_RDF_TYPE_LONG_STR
block|,
comment|/* Aliases */
name|LDNS_RDF_TYPE_BITMAP
init|=
name|LDNS_RDF_TYPE_NSEC
block|}
enum|;
typedef|typedef
name|enum
name|sldns_enum_rdf_type
name|sldns_rdf_type
typedef|;
comment|/**  * Algorithms used in dns  */
enum|enum
name|sldns_enum_algorithm
block|{
name|LDNS_RSAMD5
init|=
literal|1
block|,
comment|/* RFC 4034,4035 */
name|LDNS_DH
init|=
literal|2
block|,
name|LDNS_DSA
init|=
literal|3
block|,
name|LDNS_ECC
init|=
literal|4
block|,
name|LDNS_RSASHA1
init|=
literal|5
block|,
name|LDNS_DSA_NSEC3
init|=
literal|6
block|,
name|LDNS_RSASHA1_NSEC3
init|=
literal|7
block|,
name|LDNS_RSASHA256
init|=
literal|8
block|,
comment|/* RFC 5702 */
name|LDNS_RSASHA512
init|=
literal|10
block|,
comment|/* RFC 5702 */
name|LDNS_ECC_GOST
init|=
literal|12
block|,
comment|/* RFC 5933 */
name|LDNS_ECDSAP256SHA256
init|=
literal|13
block|,
comment|/* RFC 6605 */
name|LDNS_ECDSAP384SHA384
init|=
literal|14
block|,
comment|/* RFC 6605 */
name|LDNS_INDIRECT
init|=
literal|252
block|,
name|LDNS_PRIVATEDNS
init|=
literal|253
block|,
name|LDNS_PRIVATEOID
init|=
literal|254
block|}
enum|;
typedef|typedef
name|enum
name|sldns_enum_algorithm
name|sldns_algorithm
typedef|;
comment|/**  * Hashing algorithms used in the DS record  */
enum|enum
name|sldns_enum_hash
block|{
name|LDNS_SHA1
init|=
literal|1
block|,
comment|/* RFC 4034 */
name|LDNS_SHA256
init|=
literal|2
block|,
comment|/* RFC 4509 */
name|LDNS_HASH_GOST
init|=
literal|3
block|,
comment|/* RFC 5933 */
name|LDNS_SHA384
init|=
literal|4
comment|/* RFC 6605 */
block|}
enum|;
typedef|typedef
name|enum
name|sldns_enum_hash
name|sldns_hash
typedef|;
comment|/**  * algorithms used in CERT rrs  */
enum|enum
name|sldns_enum_cert_algorithm
block|{
name|LDNS_CERT_PKIX
init|=
literal|1
block|,
name|LDNS_CERT_SPKI
init|=
literal|2
block|,
name|LDNS_CERT_PGP
init|=
literal|3
block|,
name|LDNS_CERT_IPKIX
init|=
literal|4
block|,
name|LDNS_CERT_ISPKI
init|=
literal|5
block|,
name|LDNS_CERT_IPGP
init|=
literal|6
block|,
name|LDNS_CERT_ACPKIX
init|=
literal|7
block|,
name|LDNS_CERT_IACPKIX
init|=
literal|8
block|,
name|LDNS_CERT_URI
init|=
literal|253
block|,
name|LDNS_CERT_OID
init|=
literal|254
block|}
enum|;
typedef|typedef
name|enum
name|sldns_enum_cert_algorithm
name|sldns_cert_algorithm
typedef|;
comment|/**  * EDNS option codes  */
enum|enum
name|sldns_enum_edns_option
block|{
name|LDNS_EDNS_LLQ
init|=
literal|1
block|,
comment|/* http://files.dns-sd.org/draft-sekar-dns-llq.txt */
name|LDNS_EDNS_UL
init|=
literal|2
block|,
comment|/* http://files.dns-sd.org/draft-sekar-dns-ul.txt */
name|LDNS_EDNS_NSID
init|=
literal|3
block|,
comment|/* RFC5001 */
comment|/* 4 draft-cheshire-edns0-owner-option */
name|LDNS_EDNS_DAU
init|=
literal|5
block|,
comment|/* RFC6975 */
name|LDNS_EDNS_DHU
init|=
literal|6
block|,
comment|/* RFC6975 */
name|LDNS_EDNS_N3U
init|=
literal|7
block|,
comment|/* RFC6975 */
name|LDNS_EDNS_CLIENT_SUBNET
init|=
literal|8
comment|/* draft-vandergaast-edns-client-subnet */
block|}
enum|;
typedef|typedef
name|enum
name|sldns_edns_option
name|sldns_edns_option
typedef|;
define|#
directive|define
name|LDNS_EDNS_MASK_DO_BIT
value|0x8000
comment|/**  * Contains all information about resource record types.  *  * This structure contains, for all rr types, the rdata fields that are defined.  */
struct|struct
name|sldns_struct_rr_descriptor
block|{
comment|/** Type of the RR that is described here */
name|sldns_rr_type
name|_type
decl_stmt|;
comment|/** Textual name of the RR type.  */
specifier|const
name|char
modifier|*
name|_name
decl_stmt|;
comment|/** Minimum number of rdata fields in the RRs of this type.  */
name|uint8_t
name|_minimum
decl_stmt|;
comment|/** Maximum number of rdata fields in the RRs of this type.  */
name|uint8_t
name|_maximum
decl_stmt|;
comment|/** Wireformat specification for the rr, i.e. the types of rdata fields in their respective order. */
specifier|const
name|sldns_rdf_type
modifier|*
name|_wireformat
decl_stmt|;
comment|/** Special rdf types */
name|sldns_rdf_type
name|_variable
decl_stmt|;
comment|/** Specifies whether compression can be used for dnames in this RR type. */
name|sldns_rr_compress
name|_compress
decl_stmt|;
comment|/** The number of DNAMEs in the _wireformat string, for parsing. */
name|uint8_t
name|_dname_count
decl_stmt|;
block|}
struct|;
typedef|typedef
name|struct
name|sldns_struct_rr_descriptor
name|sldns_rr_descriptor
typedef|;
comment|/**  * returns the resource record descriptor for the given rr type.  *  * \param[in] type the type value of the rr type  *\return the sldns_rr_descriptor for this type  */
specifier|const
name|sldns_rr_descriptor
modifier|*
name|sldns_rr_descript
parameter_list|(
name|uint16_t
name|type
parameter_list|)
function_decl|;
comment|/**  * returns the minimum number of rdata fields of the rr type this descriptor describes.  *  * \param[in]  descriptor for an rr type  * \return the minimum number of rdata fields  */
name|size_t
name|sldns_rr_descriptor_minimum
parameter_list|(
specifier|const
name|sldns_rr_descriptor
modifier|*
name|descriptor
parameter_list|)
function_decl|;
comment|/**  * returns the maximum number of rdata fields of the rr type this descriptor describes.  *  * \param[in]  descriptor for an rr type  * \return the maximum number of rdata fields  */
name|size_t
name|sldns_rr_descriptor_maximum
parameter_list|(
specifier|const
name|sldns_rr_descriptor
modifier|*
name|descriptor
parameter_list|)
function_decl|;
comment|/**  * returns the rdf type for the given rdata field number of the rr type for the given descriptor.  *  * \param[in] descriptor for an rr type  * \param[in] field the field number  * \return the rdf type for the field  */
name|sldns_rdf_type
name|sldns_rr_descriptor_field_type
parameter_list|(
specifier|const
name|sldns_rr_descriptor
modifier|*
name|descriptor
parameter_list|,
name|size_t
name|field
parameter_list|)
function_decl|;
comment|/**  * retrieves a rrtype by looking up its name.  * \param[in] name a string with the name  * \return the type which corresponds with the name  */
name|sldns_rr_type
name|sldns_get_rr_type_by_name
parameter_list|(
specifier|const
name|char
modifier|*
name|name
parameter_list|)
function_decl|;
comment|/**  * retrieves a class by looking up its name.  * \param[in] name string with the name  * \return the cass which corresponds with the name  */
name|sldns_rr_class
name|sldns_get_rr_class_by_name
parameter_list|(
specifier|const
name|char
modifier|*
name|name
parameter_list|)
function_decl|;
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
comment|/* LDNS_RRDEF_H */
end_comment

end_unit

