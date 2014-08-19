begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * rr.h -  resource record definitions  *  * a Net::DNS like library for C  *  * (c) NLnet Labs, 2005-2006  *  * See the file LICENSE for the license  */
end_comment

begin_comment
comment|/**  * \file  *  * Contains the definition of ldns_rr and functions to manipulate those.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|LDNS_RR_H
end_ifndef

begin_define
define|#
directive|define
name|LDNS_RR_H
end_define

begin_include
include|#
directive|include
file|<ldns/common.h>
end_include

begin_include
include|#
directive|include
file|<ldns/rdata.h>
end_include

begin_include
include|#
directive|include
file|<ldns/buffer.h>
end_include

begin_include
include|#
directive|include
file|<ldns/error.h>
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
comment|/* The first fields are contiguous and can be referenced instantly */
define|#
directive|define
name|LDNS_RDATA_FIELD_DESCRIPTORS_COMMON
value|258
comment|/**  *  The different RR classes.  */
enum|enum
name|ldns_enum_rr_class
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
name|ldns_enum_rr_class
name|ldns_rr_class
typedef|;
comment|/**  *  Used to specify whether compression is allowed.  */
enum|enum
name|ldns_enum_rr_compress
block|{
comment|/** compression is allowed */
name|LDNS_RR_COMPRESS
block|,
name|LDNS_RR_NO_COMPRESS
block|}
enum|;
typedef|typedef
name|enum
name|ldns_enum_rr_compress
name|ldns_rr_compress
typedef|;
comment|/**  * The different RR types.  */
enum|enum
name|ldns_enum_rr_type
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
name|LDNS_RR_TYPE_EUI48
init|=
literal|108
block|,
comment|/* RFC 7043 */
name|LDNS_RR_TYPE_EUI64
init|=
literal|109
block|,
comment|/* RFC 7043 */
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
name|ldns_enum_rr_type
name|ldns_rr_type
typedef|;
comment|/**  * Resource Record  *  * This is the basic DNS element that contains actual data  *  * From RFC1035:  *<pre> 3.2.1. Format  All RRs have the same top level format shown below:                                      1  1  1  1  1  1       0  1  2  3  4  5  6  7  8  9  0  1  2  3  4  5     +--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+     |                                               |     /                                               /     /                      NAME                     /     |                                               |     +--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+     |                      TYPE                     |     +--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+     |                     CLASS                     |     +--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+     |                      TTL                      |     |                                               |     +--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+     |                   RDLENGTH                    |     +--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--|     /                     RDATA                     /     /                                               /     +--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+  where:  NAME            an owner name, i.e., the name of the node to which this                 resource record pertains.  TYPE            two octets containing one of the RR TYPE codes.  CLASS           two octets containing one of the RR CLASS codes.  TTL             a 32 bit signed integer that specifies the time interval                 that the resource record may be cached before the source                 of the information should again be consulted.  Zero                 values are interpreted to mean that the RR can only be                 used for the transaction in progress, and should not be                 cached.  For example, SOA records are always distributed                 with a zero TTL to prohibit caching.  Zero values can                 also be used for extremely volatile data.  RDLENGTH        an unsigned 16 bit integer that specifies the length in                 octets of the RDATA field.  RDATA           a variable length string of octets that describes the                 resource.  The format of this information varies                 according to the TYPE and CLASS of the resource record.  *</pre>  *  * The actual amount and type of rdata fields depend on the RR type of the  * RR, and can be found by using \ref ldns_rr_descriptor functions.  */
struct|struct
name|ldns_struct_rr
block|{
comment|/**  Owner name, uncompressed */
name|ldns_rdf
modifier|*
name|_owner
decl_stmt|;
comment|/**  Time to live  */
name|uint32_t
name|_ttl
decl_stmt|;
comment|/**  Number of data fields */
name|size_t
name|_rd_count
decl_stmt|;
comment|/**  the type of the RR. A, MX etc. */
name|ldns_rr_type
name|_rr_type
decl_stmt|;
comment|/**  Class of the resource record.  */
name|ldns_rr_class
name|_rr_class
decl_stmt|;
comment|/* everything in the rdata is in network order */
comment|/**  The array of rdata's */
name|ldns_rdf
modifier|*
modifier|*
name|_rdata_fields
decl_stmt|;
comment|/**  question rr [it would be nicer if thous is after _rd_count] 		 ABI change: Fix this in next major release 	 */
name|bool
name|_rr_question
decl_stmt|;
block|}
struct|;
typedef|typedef
name|struct
name|ldns_struct_rr
name|ldns_rr
typedef|;
comment|/**  * List or Set of Resource Records  *  * Contains a list of rr's<br>  * No official RFC-like checks are made  */
struct|struct
name|ldns_struct_rr_list
block|{
name|size_t
name|_rr_count
decl_stmt|;
name|size_t
name|_rr_capacity
decl_stmt|;
name|ldns_rr
modifier|*
modifier|*
name|_rrs
decl_stmt|;
block|}
struct|;
typedef|typedef
name|struct
name|ldns_struct_rr_list
name|ldns_rr_list
typedef|;
comment|/**  * Contains all information about resource record types.  *  * This structure contains, for all rr types, the rdata fields that are defined.  */
struct|struct
name|ldns_struct_rr_descriptor
block|{
comment|/** Type of the RR that is described here */
name|ldns_rr_type
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
name|ldns_rdf_type
modifier|*
name|_wireformat
decl_stmt|;
comment|/** Special rdf types */
name|ldns_rdf_type
name|_variable
decl_stmt|;
comment|/** Specifies whether compression can be used for dnames in this RR type. */
name|ldns_rr_compress
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
name|ldns_struct_rr_descriptor
name|ldns_rr_descriptor
typedef|;
comment|/**  * Create a rr type bitmap rdf providing enough space to set all   * known (to ldns) rr types.  * \param[out] rdf the constructed rdf  * \return LDNS_STATUS_OK if all went well.  */
name|ldns_status
name|ldns_rdf_bitmap_known_rr_types_space
parameter_list|(
name|ldns_rdf
modifier|*
modifier|*
name|rdf
parameter_list|)
function_decl|;
comment|/**  * Create a rr type bitmap rdf with at least all known (to ldns) rr types set.  * \param[out] rdf the constructed rdf  * \return LDNS_STATUS_OK if all went well.  */
name|ldns_status
name|ldns_rdf_bitmap_known_rr_types
parameter_list|(
name|ldns_rdf
modifier|*
modifier|*
name|rdf
parameter_list|)
function_decl|;
comment|/**  * creates a new rr structure.  * \return ldns_rr *  */
name|ldns_rr
modifier|*
name|ldns_rr_new
parameter_list|(
name|void
parameter_list|)
function_decl|;
comment|/**  * creates a new rr structure, based on the given type.  * alloc enough space to hold all the rdf's  */
name|ldns_rr
modifier|*
name|ldns_rr_new_frm_type
parameter_list|(
name|ldns_rr_type
name|t
parameter_list|)
function_decl|;
comment|/**  * frees an RR structure  * \param[in] *rr the RR to be freed  * \return void  */
name|void
name|ldns_rr_free
parameter_list|(
name|ldns_rr
modifier|*
name|rr
parameter_list|)
function_decl|;
comment|/**  * creates an rr from a string.  * The string should be a fully filled-in rr, like  * ownername&lt;space&gt; TTL&lt;space&gt; CLASS&lt;space&gt;  * TYPE&lt;space&gt; RDATA.  * \param[out] n the rr to return  * \param[in] str the string to convert  * \param[in] default_ttl default ttl value for the rr.  *            If 0 DEF_TTL will be used  * \param[in] origin when the owner is relative add this.  *	The caller must ldns_rdf_deep_free it.  * \param[out] prev the previous ownername. if this value is not NULL,  * the function overwrites this with the ownername found in this  * string. The caller must then ldns_rdf_deep_free it.  * \return a status msg describing an error or LDNS_STATUS_OK  */
name|ldns_status
name|ldns_rr_new_frm_str
parameter_list|(
name|ldns_rr
modifier|*
modifier|*
name|n
parameter_list|,
specifier|const
name|char
modifier|*
name|str
parameter_list|,
name|uint32_t
name|default_ttl
parameter_list|,
name|ldns_rdf
modifier|*
name|origin
parameter_list|,
name|ldns_rdf
modifier|*
modifier|*
name|prev
parameter_list|)
function_decl|;
comment|/**  * creates an rr for the question section from a string, i.e.  * without RDATA fields  * Origin and previous RR functionality are the same as in  * ldns_rr_new_frm_str()  * \param[out] n the rr to return  * \param[in] str the string to convert  * \param[in] origin when the owner is relative add this.  *	The caller must ldns_rdf_deep_free it.  * \param prev the previous ownername. the function overwrite this with  * the current found ownername. The caller must ldns_rdf_deep_free it.  * \return a status msg describing an error or LDNS_STATUS_OK  */
name|ldns_status
name|ldns_rr_new_question_frm_str
parameter_list|(
name|ldns_rr
modifier|*
modifier|*
name|n
parameter_list|,
specifier|const
name|char
modifier|*
name|str
parameter_list|,
name|ldns_rdf
modifier|*
name|origin
parameter_list|,
name|ldns_rdf
modifier|*
modifier|*
name|prev
parameter_list|)
function_decl|;
comment|/**  * creates a new rr from a file containing a string.  * \param[out] rr the new rr  * \param[in] fp the file pointer to use  * \param[in] default_ttl pointer to a default ttl for the rr. If NULL DEF_TTL will be used  *            the pointer will be updated if the file contains a $TTL directive  * \param[in] origin when the owner is relative add this  * 	      the pointer will be updated if the file contains a $ORIGIN directive  *	      The caller must ldns_rdf_deep_free it.  * \param[in] prev when the owner is whitespaces use this as the * ownername  *            the pointer will be updated after the call  *	      The caller must ldns_rdf_deep_free it.  * \return a ldns_status with an error or LDNS_STATUS_OK  */
name|ldns_status
name|ldns_rr_new_frm_fp
parameter_list|(
name|ldns_rr
modifier|*
modifier|*
name|rr
parameter_list|,
name|FILE
modifier|*
name|fp
parameter_list|,
name|uint32_t
modifier|*
name|default_ttl
parameter_list|,
name|ldns_rdf
modifier|*
modifier|*
name|origin
parameter_list|,
name|ldns_rdf
modifier|*
modifier|*
name|prev
parameter_list|)
function_decl|;
comment|/**  * creates a new rr from a file containing a string.  * \param[out] rr the new rr  * \param[in] fp the file pointer to use  * \param[in] default_ttl a default ttl for the rr. If NULL DEF_TTL will be used  *            the pointer will be updated if the file contains a $TTL directive  * \param[in] origin when the owner is relative add this  * 	      the pointer will be updated if the file contains a $ORIGIN directive  *	      The caller must ldns_rdf_deep_free it.  * \param[in] line_nr pointer to an integer containing the current line number (for debugging purposes)  * \param[in] prev when the owner is whitespaces use this as the * ownername  *            the pointer will be updated after the call  *	      The caller must ldns_rdf_deep_free it.  * \return a ldns_status with an error or LDNS_STATUS_OK  */
name|ldns_status
name|ldns_rr_new_frm_fp_l
parameter_list|(
name|ldns_rr
modifier|*
modifier|*
name|rr
parameter_list|,
name|FILE
modifier|*
name|fp
parameter_list|,
name|uint32_t
modifier|*
name|default_ttl
parameter_list|,
name|ldns_rdf
modifier|*
modifier|*
name|origin
parameter_list|,
name|ldns_rdf
modifier|*
modifier|*
name|prev
parameter_list|,
name|int
modifier|*
name|line_nr
parameter_list|)
function_decl|;
comment|/**  * sets the owner in the rr structure.  * \param[in] *rr rr to operate on  * \param[in] *owner set to this owner  * \return void  */
name|void
name|ldns_rr_set_owner
parameter_list|(
name|ldns_rr
modifier|*
name|rr
parameter_list|,
name|ldns_rdf
modifier|*
name|owner
parameter_list|)
function_decl|;
comment|/**  * sets the question flag in the rr structure.  * \param[in] *rr rr to operate on  * \param[in] question question flag  * \return void  */
name|void
name|ldns_rr_set_question
parameter_list|(
name|ldns_rr
modifier|*
name|rr
parameter_list|,
name|bool
name|question
parameter_list|)
function_decl|;
comment|/**  * sets the ttl in the rr structure.  * \param[in] *rr rr to operate on  * \param[in] ttl set to this ttl  * \return void  */
name|void
name|ldns_rr_set_ttl
parameter_list|(
name|ldns_rr
modifier|*
name|rr
parameter_list|,
name|uint32_t
name|ttl
parameter_list|)
function_decl|;
comment|/**  * sets the rd_count in the rr.  * \param[in] *rr rr to operate on  * \param[in] count set to this count  * \return void  */
name|void
name|ldns_rr_set_rd_count
parameter_list|(
name|ldns_rr
modifier|*
name|rr
parameter_list|,
name|size_t
name|count
parameter_list|)
function_decl|;
comment|/**  * sets the type in the rr.  * \param[in] *rr rr to operate on  * \param[in] rr_type set to this type  * \return void  */
name|void
name|ldns_rr_set_type
parameter_list|(
name|ldns_rr
modifier|*
name|rr
parameter_list|,
name|ldns_rr_type
name|rr_type
parameter_list|)
function_decl|;
comment|/**  * sets the class in the rr.  * \param[in] *rr rr to operate on  * \param[in] rr_class set to this class  * \return void  */
name|void
name|ldns_rr_set_class
parameter_list|(
name|ldns_rr
modifier|*
name|rr
parameter_list|,
name|ldns_rr_class
name|rr_class
parameter_list|)
function_decl|;
comment|/**  * sets a rdf member, it will be set on the  * position given. The old value is returned, like pop.  * \param[in] *rr the rr to operate on  * \param[in] *f the rdf to set  * \param[in] position the position the set the rdf  * \return  the old value in the rr, NULL on failyre  */
name|ldns_rdf
modifier|*
name|ldns_rr_set_rdf
parameter_list|(
name|ldns_rr
modifier|*
name|rr
parameter_list|,
specifier|const
name|ldns_rdf
modifier|*
name|f
parameter_list|,
name|size_t
name|position
parameter_list|)
function_decl|;
comment|/**  * sets rd_field member, it will be  * placed in the next available spot.  * \param[in] *rr rr to operate on  * \param[in] *f the data field member to set  * \return bool  */
name|bool
name|ldns_rr_push_rdf
parameter_list|(
name|ldns_rr
modifier|*
name|rr
parameter_list|,
specifier|const
name|ldns_rdf
modifier|*
name|f
parameter_list|)
function_decl|;
comment|/**  * removes a rd_field member, it will be  * popped from the last position.  * \param[in] *rr rr to operate on  * \return rdf which was popped (null if nothing)  */
name|ldns_rdf
modifier|*
name|ldns_rr_pop_rdf
parameter_list|(
name|ldns_rr
modifier|*
name|rr
parameter_list|)
function_decl|;
comment|/**  * returns the rdata field member counter.  * \param[in] *rr rr to operate on  * \param[in] nr the number of the rdf to return  * \return ldns_rdf *  */
name|ldns_rdf
modifier|*
name|ldns_rr_rdf
parameter_list|(
specifier|const
name|ldns_rr
modifier|*
name|rr
parameter_list|,
name|size_t
name|nr
parameter_list|)
function_decl|;
comment|/**  * returns the owner name of an rr structure.  * \param[in] *rr rr to operate on  * \return ldns_rdf *  */
name|ldns_rdf
modifier|*
name|ldns_rr_owner
parameter_list|(
specifier|const
name|ldns_rr
modifier|*
name|rr
parameter_list|)
function_decl|;
comment|/**  * returns the question flag of an rr structure.  * \param[in] *rr rr to operate on  * \return bool true if question  */
name|bool
name|ldns_rr_is_question
parameter_list|(
specifier|const
name|ldns_rr
modifier|*
name|rr
parameter_list|)
function_decl|;
comment|/**  * returns the ttl of an rr structure.  * \param[in] *rr the rr to read from  * \return the ttl of the rr  */
name|uint32_t
name|ldns_rr_ttl
parameter_list|(
specifier|const
name|ldns_rr
modifier|*
name|rr
parameter_list|)
function_decl|;
comment|/**  * returns the rd_count of an rr structure.  * \param[in] *rr the rr to read from  * \return the rd count of the rr  */
name|size_t
name|ldns_rr_rd_count
parameter_list|(
specifier|const
name|ldns_rr
modifier|*
name|rr
parameter_list|)
function_decl|;
comment|/**  * returns the type of the rr.  * \param[in] *rr the rr to read from  * \return the type of the rr  */
name|ldns_rr_type
name|ldns_rr_get_type
parameter_list|(
specifier|const
name|ldns_rr
modifier|*
name|rr
parameter_list|)
function_decl|;
comment|/**  * returns the class of the rr.  * \param[in] *rr the rr to read from  * \return the class of the rr  */
name|ldns_rr_class
name|ldns_rr_get_class
parameter_list|(
specifier|const
name|ldns_rr
modifier|*
name|rr
parameter_list|)
function_decl|;
comment|/* rr_lists */
comment|/**  * returns the number of rr's in an rr_list.  * \param[in] rr_list  the rr_list to read from  * \return the number of rr's  */
name|size_t
name|ldns_rr_list_rr_count
parameter_list|(
specifier|const
name|ldns_rr_list
modifier|*
name|rr_list
parameter_list|)
function_decl|;
comment|/**  * sets the number of rr's in an rr_list.  * \param[in] rr_list the rr_list to set the count on  * \param[in] count the number of rr in this list  * \return void  */
name|void
name|ldns_rr_list_set_rr_count
parameter_list|(
name|ldns_rr_list
modifier|*
name|rr_list
parameter_list|,
name|size_t
name|count
parameter_list|)
function_decl|;
comment|/**  * set a rr on a specific index in a ldns_rr_list  * \param[in] rr_list the rr_list to use  * \param[in] r the rr to set  * \param[in] count index into the rr_list  * \return the old rr which was stored in the rr_list, or  * NULL is the index was too large  * set a specific rr */
name|ldns_rr
modifier|*
name|ldns_rr_list_set_rr
parameter_list|(
name|ldns_rr_list
modifier|*
name|rr_list
parameter_list|,
specifier|const
name|ldns_rr
modifier|*
name|r
parameter_list|,
name|size_t
name|count
parameter_list|)
function_decl|;
comment|/**  * returns a specific rr of an rrlist.  * \param[in] rr_list the rr_list to read from  * \param[in] nr return this rr  * \return the rr at position nr  */
name|ldns_rr
modifier|*
name|ldns_rr_list_rr
parameter_list|(
specifier|const
name|ldns_rr_list
modifier|*
name|rr_list
parameter_list|,
name|size_t
name|nr
parameter_list|)
function_decl|;
comment|/**  * creates a new rr_list structure.  * \return a new rr_list structure  */
name|ldns_rr_list
modifier|*
name|ldns_rr_list_new
parameter_list|(
name|void
parameter_list|)
function_decl|;
comment|/**  * frees an rr_list structure.  * \param[in] rr_list the list to free  */
name|void
name|ldns_rr_list_free
parameter_list|(
name|ldns_rr_list
modifier|*
name|rr_list
parameter_list|)
function_decl|;
comment|/**  * frees an rr_list structure and all rrs contained therein.  * \param[in] rr_list the list to free  */
name|void
name|ldns_rr_list_deep_free
parameter_list|(
name|ldns_rr_list
modifier|*
name|rr_list
parameter_list|)
function_decl|;
comment|/**  * concatenates two ldns_rr_lists together. This modifies  * *left (to extend it and add the pointers from *right).  * \param[in] left the leftside  * \param[in] right the rightside  * \return a left with right concatenated to it  */
name|bool
name|ldns_rr_list_cat
parameter_list|(
name|ldns_rr_list
modifier|*
name|left
parameter_list|,
name|ldns_rr_list
modifier|*
name|right
parameter_list|)
function_decl|;
comment|/**  * concatenates two ldns_rr_lists together, but makes clones of the rr's   * (instead of pointer copying).  * \param[in] left the leftside  * \param[in] right the rightside  * \return a new rr_list with leftside/rightside concatenated  */
name|ldns_rr_list
modifier|*
name|ldns_rr_list_cat_clone
parameter_list|(
name|ldns_rr_list
modifier|*
name|left
parameter_list|,
name|ldns_rr_list
modifier|*
name|right
parameter_list|)
function_decl|;
comment|/**  * pushes an rr to an rrlist.  * \param[in] rr_list the rr_list to push to   * \param[in] rr the rr to push   * \return false on error, otherwise true  */
name|bool
name|ldns_rr_list_push_rr
parameter_list|(
name|ldns_rr_list
modifier|*
name|rr_list
parameter_list|,
specifier|const
name|ldns_rr
modifier|*
name|rr
parameter_list|)
function_decl|;
comment|/**  * pushes an rr_list to an rrlist.  * \param[in] rr_list the rr_list to push to   * \param[in] push_list the rr_list to push   * \return false on error, otherwise true  */
name|bool
name|ldns_rr_list_push_rr_list
parameter_list|(
name|ldns_rr_list
modifier|*
name|rr_list
parameter_list|,
specifier|const
name|ldns_rr_list
modifier|*
name|push_list
parameter_list|)
function_decl|;
comment|/**  * pops the last rr from an rrlist.  * \param[in] rr_list the rr_list to pop from  * \return NULL if nothing to pop. Otherwise the popped RR  */
name|ldns_rr
modifier|*
name|ldns_rr_list_pop_rr
parameter_list|(
name|ldns_rr_list
modifier|*
name|rr_list
parameter_list|)
function_decl|;
comment|/**  * pops an  rr_list of size s from an rrlist.  * \param[in] rr_list the rr_list to pop from  * \param[in] size the number of rr's to pop   * \return NULL if nothing to pop. Otherwise the popped rr_list  */
name|ldns_rr_list
modifier|*
name|ldns_rr_list_pop_rr_list
parameter_list|(
name|ldns_rr_list
modifier|*
name|rr_list
parameter_list|,
name|size_t
name|size
parameter_list|)
function_decl|;
comment|/**  * returns true if the given rr is one of the rrs in the  * list, or if it is equal to one  * \param[in] rr_list the rr_list to check  * \param[in] rr the rr to check  * \return true if rr_list contains rr, false otherwise  */
name|bool
name|ldns_rr_list_contains_rr
parameter_list|(
specifier|const
name|ldns_rr_list
modifier|*
name|rr_list
parameter_list|,
name|ldns_rr
modifier|*
name|rr
parameter_list|)
function_decl|;
comment|/**  * checks if an rr_list is a rrset.  * \param[in] rr_list the rr_list to check  * \return true if it is an rrset otherwise false  */
name|bool
name|ldns_is_rrset
parameter_list|(
name|ldns_rr_list
modifier|*
name|rr_list
parameter_list|)
function_decl|;
comment|/**  * pushes an rr to an rrset (which really are rr_list's).  * \param[in] *rr_list the rrset to push the rr to  * \param[in] *rr the rr to push  * \return true if the push succeeded otherwise false  */
name|bool
name|ldns_rr_set_push_rr
parameter_list|(
name|ldns_rr_list
modifier|*
name|rr_list
parameter_list|,
name|ldns_rr
modifier|*
name|rr
parameter_list|)
function_decl|;
comment|/**  * pops the last rr from an rrset. This function is there only  * for the symmetry.  * \param[in] rr_list the rr_list to pop from  * \return NULL if nothing to pop. Otherwise the popped RR  *  */
name|ldns_rr
modifier|*
name|ldns_rr_set_pop_rr
parameter_list|(
name|ldns_rr_list
modifier|*
name|rr_list
parameter_list|)
function_decl|;
comment|/**  * pops the first rrset from the list,  * the list must be sorted, so that all rr's from each rrset  * are next to each other  */
name|ldns_rr_list
modifier|*
name|ldns_rr_list_pop_rrset
parameter_list|(
name|ldns_rr_list
modifier|*
name|rr_list
parameter_list|)
function_decl|;
comment|/**  * retrieves a rrtype by looking up its name.  * \param[in] name a string with the name  * \return the type which corresponds with the name  */
name|ldns_rr_type
name|ldns_get_rr_type_by_name
parameter_list|(
specifier|const
name|char
modifier|*
name|name
parameter_list|)
function_decl|;
comment|/**  * retrieves a class by looking up its name.  * \param[in] name string with the name  * \return the cass which corresponds with the name  */
name|ldns_rr_class
name|ldns_get_rr_class_by_name
parameter_list|(
specifier|const
name|char
modifier|*
name|name
parameter_list|)
function_decl|;
comment|/**  * clones a rr and all its data  * \param[in] rr the rr to clone  * \return the new rr or NULL on failure  */
name|ldns_rr
modifier|*
name|ldns_rr_clone
parameter_list|(
specifier|const
name|ldns_rr
modifier|*
name|rr
parameter_list|)
function_decl|;
comment|/**  * clones an rrlist.  * \param[in] rrlist the rrlist to clone  * \return the cloned rr list  */
name|ldns_rr_list
modifier|*
name|ldns_rr_list_clone
parameter_list|(
specifier|const
name|ldns_rr_list
modifier|*
name|rrlist
parameter_list|)
function_decl|;
comment|/**  * sorts an rr_list (canonical wire format). the sorting is done inband.  * \param[in] unsorted the rr_list to be sorted  * \return void  */
name|void
name|ldns_rr_list_sort
parameter_list|(
name|ldns_rr_list
modifier|*
name|unsorted
parameter_list|)
function_decl|;
comment|/**  * compares two rrs. The TTL is not looked at.  * \param[in] rr1 the first one  * \param[in] rr2 the second one  * \return 0 if equal  *         -1 if rr1 comes before rr2  *         +1 if rr2 comes before rr1  */
name|int
name|ldns_rr_compare
parameter_list|(
specifier|const
name|ldns_rr
modifier|*
name|rr1
parameter_list|,
specifier|const
name|ldns_rr
modifier|*
name|rr2
parameter_list|)
function_decl|;
comment|/**  * compares two rrs, up to the rdata.  * \param[in] rr1 the first one  * \param[in] rr2 the second one  * \return 0 if equal  *         -1 if rr1 comes before rr2  *         +1 if rr2 comes before rr1  */
name|int
name|ldns_rr_compare_no_rdata
parameter_list|(
specifier|const
name|ldns_rr
modifier|*
name|rr1
parameter_list|,
specifier|const
name|ldns_rr
modifier|*
name|rr2
parameter_list|)
function_decl|;
comment|/**  * compares the wireformat of two rrs, contained in the given buffers.  * \param[in] rr1_buf the first one  * \param[in] rr2_buf the second one  * \return 0 if equal  *         -1 if rr1_buf comes before rr2_buf  *         +1 if rr2_buf comes before rr1_buf  */
name|int
name|ldns_rr_compare_wire
parameter_list|(
name|ldns_buffer
modifier|*
name|rr1_buf
parameter_list|,
name|ldns_buffer
modifier|*
name|rr2_buf
parameter_list|)
function_decl|;
comment|/**  * returns true of the given rr's are equal.  * Also returns true if one record is a DS that represents the  * same DNSKEY record as the other record  * \param[in] rr1 the first rr  * \param[in] rr2 the second rr  * \return true if equal otherwise false  */
name|bool
name|ldns_rr_compare_ds
parameter_list|(
specifier|const
name|ldns_rr
modifier|*
name|rr1
parameter_list|,
specifier|const
name|ldns_rr
modifier|*
name|rr2
parameter_list|)
function_decl|;
comment|/**  * compares two rr listss.  * \param[in] rrl1 the first one  * \param[in] rrl2 the second one  * \return 0 if equal  *         -1 if rrl1 comes before rrl2  *         +1 if rrl2 comes before rrl1  */
name|int
name|ldns_rr_list_compare
parameter_list|(
specifier|const
name|ldns_rr_list
modifier|*
name|rrl1
parameter_list|,
specifier|const
name|ldns_rr_list
modifier|*
name|rrl2
parameter_list|)
function_decl|;
comment|/**   * calculates the uncompressed size of an RR.  * \param[in] r the rr to operate on  * \return size of the rr  */
name|size_t
name|ldns_rr_uncompressed_size
parameter_list|(
specifier|const
name|ldns_rr
modifier|*
name|r
parameter_list|)
function_decl|;
comment|/**   * converts each dname in a rr to its canonical form.  * \param[in] rr the rr to work on  * \return void  */
name|void
name|ldns_rr2canonical
parameter_list|(
name|ldns_rr
modifier|*
name|rr
parameter_list|)
function_decl|;
comment|/**   * converts each dname in each rr in a rr_list to its canonical form.  * \param[in] rr_list the rr_list to work on  * \return void  */
name|void
name|ldns_rr_list2canonical
parameter_list|(
name|ldns_rr_list
modifier|*
name|rr_list
parameter_list|)
function_decl|;
comment|/**   * counts the number of labels of the ownername.  * \param[in] rr count the labels of this rr  * \return the number of labels  */
name|uint8_t
name|ldns_rr_label_count
parameter_list|(
name|ldns_rr
modifier|*
name|rr
parameter_list|)
function_decl|;
comment|/**  * returns the resource record descriptor for the given rr type.  *  * \param[in] type the type value of the rr type  *\return the ldns_rr_descriptor for this type  */
specifier|const
name|ldns_rr_descriptor
modifier|*
name|ldns_rr_descript
parameter_list|(
name|uint16_t
name|type
parameter_list|)
function_decl|;
comment|/**  * returns the minimum number of rdata fields of the rr type this descriptor describes.  *  * \param[in]  descriptor for an rr type  * \return the minimum number of rdata fields  */
name|size_t
name|ldns_rr_descriptor_minimum
parameter_list|(
specifier|const
name|ldns_rr_descriptor
modifier|*
name|descriptor
parameter_list|)
function_decl|;
comment|/**  * returns the maximum number of rdata fields of the rr type this descriptor describes.  *  * \param[in]  descriptor for an rr type  * \return the maximum number of rdata fields  */
name|size_t
name|ldns_rr_descriptor_maximum
parameter_list|(
specifier|const
name|ldns_rr_descriptor
modifier|*
name|descriptor
parameter_list|)
function_decl|;
comment|/**  * returns the rdf type for the given rdata field number of the rr type for the given descriptor.  *  * \param[in] descriptor for an rr type  * \param[in] field the field number  * \return the rdf type for the field  */
name|ldns_rdf_type
name|ldns_rr_descriptor_field_type
parameter_list|(
specifier|const
name|ldns_rr_descriptor
modifier|*
name|descriptor
parameter_list|,
name|size_t
name|field
parameter_list|)
function_decl|;
comment|/**  * Return the rr_list which matches the rdf at position field. Think  * type-covered stuff for RRSIG  *   * \param[in] l the rr_list to look in  * \param[in] r the rdf to use for the comparison  * \param[in] pos at which position can we find the rdf  *   * \return a new rr list with only the RRs that match   *  */
name|ldns_rr_list
modifier|*
name|ldns_rr_list_subtype_by_rdf
parameter_list|(
name|ldns_rr_list
modifier|*
name|l
parameter_list|,
name|ldns_rdf
modifier|*
name|r
parameter_list|,
name|size_t
name|pos
parameter_list|)
function_decl|;
comment|/**  * convert an rdf of type LDNS_RDF_TYPE_TYPE to an actual  * LDNS_RR_TYPE. This is usefull in the case when inspecting  * the rrtype covered field of an RRSIG.  * \param[in] rd the rdf to look at  * \return a ldns_rr_type with equivalent LDNS_RR_TYPE  *  */
name|ldns_rr_type
name|ldns_rdf2rr_type
parameter_list|(
specifier|const
name|ldns_rdf
modifier|*
name|rd
parameter_list|)
function_decl|;
comment|/**  * Returns the type of the first element of the RR  * If there are no elements present, 0 is returned  *   * \param[in] rr_list The rr list  * \return rr_type of the first element, or 0 if the list is empty  */
name|ldns_rr_type
name|ldns_rr_list_type
parameter_list|(
specifier|const
name|ldns_rr_list
modifier|*
name|rr_list
parameter_list|)
function_decl|;
comment|/**  * Returns the owner domain name rdf of the first element of the RR  * If there are no elements present, NULL is returned  *   * \param[in] rr_list The rr list  * \return dname of the first element, or NULL if the list is empty  */
name|ldns_rdf
modifier|*
name|ldns_rr_list_owner
parameter_list|(
specifier|const
name|ldns_rr_list
modifier|*
name|rr_list
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
comment|/* LDNS_RR_H */
end_comment

end_unit

