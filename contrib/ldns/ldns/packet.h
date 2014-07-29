begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * packet.h  *  * DNS packet definitions  *  * a Net::DNS like library for C  *  * (c) NLnet Labs, 2005-2006  *  * See the file LICENSE for the license  */
end_comment

begin_comment
comment|/**  * \file  *  * Contains the definition of ldns_pkt and its parts, as well  * as functions to manipulate those.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|LDNS_PACKET_H
end_ifndef

begin_define
define|#
directive|define
name|LDNS_PACKET_H
end_define

begin_define
define|#
directive|define
name|LDNS_MAX_PACKETLEN
value|65535
end_define

begin_comment
comment|/* allow flags to be given to mk_query */
end_comment

begin_define
define|#
directive|define
name|LDNS_QR
value|1
end_define

begin_comment
comment|/* QueRy - query flag */
end_comment

begin_define
define|#
directive|define
name|LDNS_AA
value|2
end_define

begin_comment
comment|/* Authoritative Answer - server flag */
end_comment

begin_define
define|#
directive|define
name|LDNS_TC
value|4
end_define

begin_comment
comment|/* TrunCated - server flag */
end_comment

begin_define
define|#
directive|define
name|LDNS_RD
value|8
end_define

begin_comment
comment|/* Recursion Desired - query flag */
end_comment

begin_define
define|#
directive|define
name|LDNS_CD
value|16
end_define

begin_comment
comment|/* Checking Disabled - query flag */
end_comment

begin_define
define|#
directive|define
name|LDNS_RA
value|32
end_define

begin_comment
comment|/* Recursion Available - server flag */
end_comment

begin_define
define|#
directive|define
name|LDNS_AD
value|64
end_define

begin_comment
comment|/* Authenticated Data - server flag */
end_comment

begin_include
include|#
directive|include
file|<ldns/error.h>
end_include

begin_include
include|#
directive|include
file|<ldns/common.h>
end_include

begin_include
include|#
directive|include
file|<ldns/rr.h>
end_include

begin_include
include|#
directive|include
file|<sys/time.h>
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
comment|/* opcodes for pkt's */
enum|enum
name|ldns_enum_pkt_opcode
block|{
name|LDNS_PACKET_QUERY
init|=
literal|0
block|,
name|LDNS_PACKET_IQUERY
init|=
literal|1
block|,
name|LDNS_PACKET_STATUS
init|=
literal|2
block|,
comment|/* there is no 3?? DNS is weird */
name|LDNS_PACKET_NOTIFY
init|=
literal|4
block|,
name|LDNS_PACKET_UPDATE
init|=
literal|5
block|}
enum|;
typedef|typedef
name|enum
name|ldns_enum_pkt_opcode
name|ldns_pkt_opcode
typedef|;
comment|/* rcodes for pkts */
enum|enum
name|ldns_enum_pkt_rcode
block|{
name|LDNS_RCODE_NOERROR
init|=
literal|0
block|,
name|LDNS_RCODE_FORMERR
init|=
literal|1
block|,
name|LDNS_RCODE_SERVFAIL
init|=
literal|2
block|,
name|LDNS_RCODE_NXDOMAIN
init|=
literal|3
block|,
name|LDNS_RCODE_NOTIMPL
init|=
literal|4
block|,
name|LDNS_RCODE_REFUSED
init|=
literal|5
block|,
name|LDNS_RCODE_YXDOMAIN
init|=
literal|6
block|,
name|LDNS_RCODE_YXRRSET
init|=
literal|7
block|,
name|LDNS_RCODE_NXRRSET
init|=
literal|8
block|,
name|LDNS_RCODE_NOTAUTH
init|=
literal|9
block|,
name|LDNS_RCODE_NOTZONE
init|=
literal|10
block|}
enum|;
typedef|typedef
name|enum
name|ldns_enum_pkt_rcode
name|ldns_pkt_rcode
typedef|;
comment|/**  *  Header of a dns packet  *  * Contains the information about the packet itself, as specified in RFC1035<pre> 4.1.1. Header section format  The header contains the following fields:                                      1  1  1  1  1  1       0  1  2  3  4  5  6  7  8  9  0  1  2  3  4  5     +--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+     |                      ID                       |     +--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+     |QR|   Opcode  |AA|TC|RD|RA|   Z    |   RCODE   |     +--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+     |                    QDCOUNT                    |     +--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+     |                    ANCOUNT                    |     +--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+     |                    NSCOUNT                    |     +--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+     |                    ARCOUNT                    |     +--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+  where:  ID              A 16 bit identifier assigned by the program that                 generates any kind of query.  This identifier is copied                 the corresponding reply and can be used by the requester                 to match up replies to outstanding queries.  QR              A one bit field that specifies whether this message is a                 query (0), or a response (1).  OPCODE          A four bit field that specifies kind of query in this                 message.  This value is set by the originator of a query                 and copied into the response.  The values are:                  0               a standard query (QUERY)                  1               an inverse query (IQUERY)                  2               a server status request (STATUS)                  3-15            reserved for future use  AA              Authoritative Answer - this bit is valid in responses,                 and specifies that the responding name server is an                 authority for the domain name in question section.                  Note that the contents of the answer section may have                 multiple owner names because of aliases.  The AA bit                  corresponds to the name which matches the query name, or                 the first owner name in the answer section.  TC              TrunCation - specifies that this message was truncated                 due to length greater than that permitted on the                 transmission channel.  RD              Recursion Desired - this bit may be set in a query and                 is copied into the response.  If RD is set, it directs                 the name server to pursue the query recursively.                 Recursive query support is optional.  RA              Recursion Available - this be is set or cleared in a                 response, and denotes whether recursive query support is                 available in the name server.  Z               Reserved for future use.  Must be zero in all queries                 and responses.  RCODE           Response code - this 4 bit field is set as part of                 responses.  The values have the following                 interpretation:                  0               No error condition                  1               Format error - The name server was                                 unable to interpret the query.                  2               Server failure - The name server was                                 unable to process this query due to a                                 problem with the name server.                  3               Name Error - Meaningful only for                                 responses from an authoritative name                                 server, this code signifies that the                                 domain name referenced in the query does                                 not exist.                  4               Not Implemented - The name server does                                 not support the requested kind of query.                  5               Refused - The name server refuses to                                 perform the specified operation for                                 policy reasons.  For example, a name                                 server may not wish to provide the                                 information to the particular requester,                                 or a name server may not wish to perform                                 a particular operation (e.g., zone                                  transfer) for particular data.                  6-15            Reserved for future use.  QDCOUNT         an unsigned 16 bit integer specifying the number of                 entries in the question section.  ANCOUNT         an unsigned 16 bit integer specifying the number of                 resource records in the answer section.  NSCOUNT         an unsigned 16 bit integer specifying the number of name                 server resource records in the authority records                 section.  ARCOUNT         an unsigned 16 bit integer specifying the number of                 resource records in the additional records section.</pre>  */
struct|struct
name|ldns_struct_hdr
block|{
comment|/**  Id of a packet */
name|uint16_t
name|_id
decl_stmt|;
comment|/**  Query bit (0=query, 1=answer) */
name|bool
name|_qr
decl_stmt|;
comment|/**  Authoritative answer */
name|bool
name|_aa
decl_stmt|;
comment|/**  Packet truncated */
name|bool
name|_tc
decl_stmt|;
comment|/**  Recursion desired */
name|bool
name|_rd
decl_stmt|;
comment|/**  Checking disabled */
name|bool
name|_cd
decl_stmt|;
comment|/**  Recursion available */
name|bool
name|_ra
decl_stmt|;
comment|/**  Authentic data */
name|bool
name|_ad
decl_stmt|;
comment|/**  Query type */
name|ldns_pkt_opcode
name|_opcode
decl_stmt|;
comment|/* XXX 8 bits? */
comment|/**  Response code */
name|uint8_t
name|_rcode
decl_stmt|;
comment|/**  question sec */
name|uint16_t
name|_qdcount
decl_stmt|;
comment|/**  answer sec */
name|uint16_t
name|_ancount
decl_stmt|;
comment|/**  auth sec */
name|uint16_t
name|_nscount
decl_stmt|;
comment|/**  add sec */
name|uint16_t
name|_arcount
decl_stmt|;
block|}
struct|;
typedef|typedef
name|struct
name|ldns_struct_hdr
name|ldns_hdr
typedef|;
comment|/**  * DNS packet  *  * This structure contains a complete DNS packet (either a query or an answer)  *  * It is the complete representation of what you actually send to a  * nameserver, and what it sends back (assuming you are the client here).  */
struct|struct
name|ldns_struct_pkt
block|{
comment|/** Header section */
name|ldns_hdr
modifier|*
name|_header
decl_stmt|;
comment|/* extra items needed in a packet */
comment|/** The size of the wire format of the packet in octets */
name|ldns_rdf
modifier|*
name|_answerfrom
decl_stmt|;
comment|/** Timestamp of the time the packet was sent or created */
name|struct
name|timeval
name|timestamp
decl_stmt|;
comment|/** The duration of the query this packet is an answer to */
name|uint32_t
name|_querytime
decl_stmt|;
comment|/** The size of the wire format of the packet in octets */
name|size_t
name|_size
decl_stmt|;
comment|/** Optional tsig rr */
name|ldns_rr
modifier|*
name|_tsig_rr
decl_stmt|;
comment|/** EDNS0 available buffer size, see RFC2671 */
name|uint16_t
name|_edns_udp_size
decl_stmt|;
comment|/** EDNS0 Extended rcode */
name|uint8_t
name|_edns_extended_rcode
decl_stmt|;
comment|/** EDNS Version */
name|uint8_t
name|_edns_version
decl_stmt|;
comment|/** Reserved EDNS data bits */
name|uint16_t
name|_edns_z
decl_stmt|;
comment|/** Arbitrary EDNS rdata */
name|ldns_rdf
modifier|*
name|_edns_data
decl_stmt|;
comment|/**  Question section */
name|ldns_rr_list
modifier|*
name|_question
decl_stmt|;
comment|/**  Answer section */
name|ldns_rr_list
modifier|*
name|_answer
decl_stmt|;
comment|/**  Authority section */
name|ldns_rr_list
modifier|*
name|_authority
decl_stmt|;
comment|/**  Additional section */
name|ldns_rr_list
modifier|*
name|_additional
decl_stmt|;
block|}
struct|;
typedef|typedef
name|struct
name|ldns_struct_pkt
name|ldns_pkt
typedef|;
comment|/**  * The sections of a packet  */
enum|enum
name|ldns_enum_pkt_section
block|{
name|LDNS_SECTION_QUESTION
init|=
literal|0
block|,
name|LDNS_SECTION_ANSWER
init|=
literal|1
block|,
name|LDNS_SECTION_AUTHORITY
init|=
literal|2
block|,
name|LDNS_SECTION_ADDITIONAL
init|=
literal|3
block|,
comment|/** bogus section, if not interested */
name|LDNS_SECTION_ANY
init|=
literal|4
block|,
comment|/** used to get all non-question rrs from a packet */
name|LDNS_SECTION_ANY_NOQUESTION
init|=
literal|5
block|}
enum|;
typedef|typedef
name|enum
name|ldns_enum_pkt_section
name|ldns_pkt_section
typedef|;
comment|/**  * The different types of packets  */
enum|enum
name|ldns_enum_pkt_type
block|{
name|LDNS_PACKET_QUESTION
block|,
name|LDNS_PACKET_REFERRAL
block|,
name|LDNS_PACKET_ANSWER
block|,
name|LDNS_PACKET_NXDOMAIN
block|,
name|LDNS_PACKET_NODATA
block|,
name|LDNS_PACKET_UNKNOWN
block|}
enum|;
typedef|typedef
name|enum
name|ldns_enum_pkt_type
name|ldns_pkt_type
typedef|;
comment|/* prototypes */
comment|/* read */
comment|/**  * Read the packet id  * \param[in] p the packet  * \return the packet id  */
name|uint16_t
name|ldns_pkt_id
parameter_list|(
specifier|const
name|ldns_pkt
modifier|*
name|p
parameter_list|)
function_decl|;
comment|/**  * Read the packet's qr bit  * \param[in] p the packet  * \return value of the bit  */
name|bool
name|ldns_pkt_qr
parameter_list|(
specifier|const
name|ldns_pkt
modifier|*
name|p
parameter_list|)
function_decl|;
comment|/**  * Read the packet's aa bit  * \param[in] p the packet  * \return value of the bit  */
name|bool
name|ldns_pkt_aa
parameter_list|(
specifier|const
name|ldns_pkt
modifier|*
name|p
parameter_list|)
function_decl|;
comment|/**  * Read the packet's tc bit  * \param[in] p the packet  * \return value of the bit  */
name|bool
name|ldns_pkt_tc
parameter_list|(
specifier|const
name|ldns_pkt
modifier|*
name|p
parameter_list|)
function_decl|;
comment|/**  * Read the packet's rd bit  * \param[in] p the packet  * \return value of the bit  */
name|bool
name|ldns_pkt_rd
parameter_list|(
specifier|const
name|ldns_pkt
modifier|*
name|p
parameter_list|)
function_decl|;
comment|/**  * Read the packet's cd bit  * \param[in] p the packet  * \return value of the bit  */
name|bool
name|ldns_pkt_cd
parameter_list|(
specifier|const
name|ldns_pkt
modifier|*
name|p
parameter_list|)
function_decl|;
comment|/**  * Read the packet's ra bit  * \param[in] p the packet  * \return value of the bit  */
name|bool
name|ldns_pkt_ra
parameter_list|(
specifier|const
name|ldns_pkt
modifier|*
name|p
parameter_list|)
function_decl|;
comment|/**  * Read the packet's ad bit  * \param[in] p the packet  * \return value of the bit  */
name|bool
name|ldns_pkt_ad
parameter_list|(
specifier|const
name|ldns_pkt
modifier|*
name|p
parameter_list|)
function_decl|;
comment|/**  * Read the packet's code  * \param[in] p the packet  * \return the opcode  */
name|ldns_pkt_opcode
name|ldns_pkt_get_opcode
parameter_list|(
specifier|const
name|ldns_pkt
modifier|*
name|p
parameter_list|)
function_decl|;
comment|/**  * Return the packet's respons code  * \param[in] p the packet  * \return the respons code  */
name|ldns_pkt_rcode
name|ldns_pkt_get_rcode
parameter_list|(
specifier|const
name|ldns_pkt
modifier|*
name|p
parameter_list|)
function_decl|;
comment|/**  * Return the packet's qd count   * \param[in] p the packet  * \return the qd count  */
name|uint16_t
name|ldns_pkt_qdcount
parameter_list|(
specifier|const
name|ldns_pkt
modifier|*
name|p
parameter_list|)
function_decl|;
comment|/**  * Return the packet's an count  * \param[in] p the packet  * \return the an count  */
name|uint16_t
name|ldns_pkt_ancount
parameter_list|(
specifier|const
name|ldns_pkt
modifier|*
name|p
parameter_list|)
function_decl|;
comment|/**  * Return the packet's ns count  * \param[in] p the packet  * \return the ns count  */
name|uint16_t
name|ldns_pkt_nscount
parameter_list|(
specifier|const
name|ldns_pkt
modifier|*
name|p
parameter_list|)
function_decl|;
comment|/**  * Return the packet's ar count  * \param[in] p the packet  * \return the ar count  */
name|uint16_t
name|ldns_pkt_arcount
parameter_list|(
specifier|const
name|ldns_pkt
modifier|*
name|p
parameter_list|)
function_decl|;
comment|/**   * Return the packet's answerfrom  * \param[in] p packet  * \return the name of the server  */
name|ldns_rdf
modifier|*
name|ldns_pkt_answerfrom
parameter_list|(
specifier|const
name|ldns_pkt
modifier|*
name|p
parameter_list|)
function_decl|;
comment|/**  * Return the packet's timestamp  * \param[in] p the packet  * \return the timestamp  */
name|struct
name|timeval
name|ldns_pkt_timestamp
parameter_list|(
specifier|const
name|ldns_pkt
modifier|*
name|p
parameter_list|)
function_decl|;
comment|/**  * Return the packet's querytime  * \param[in] p the packet  * \return the querytime  */
name|uint32_t
name|ldns_pkt_querytime
parameter_list|(
specifier|const
name|ldns_pkt
modifier|*
name|p
parameter_list|)
function_decl|;
comment|/**  * Return the packet's size in bytes  * \param[in] p the packet  * \return the size  */
name|size_t
name|ldns_pkt_size
parameter_list|(
specifier|const
name|ldns_pkt
modifier|*
name|p
parameter_list|)
function_decl|;
comment|/**  * Return the number of RRs in the given section.  * Returns the sum of all RRs when LDNS_SECTION_ANY is given.  * Returns the sum of all non-question RRs when LDNS_SECTION_ANY_NOQUESTION  * is given.  * \param[in] p the packet  * \param[in] s the section  * \return the number of RRs in the given section  */
name|uint16_t
name|ldns_pkt_section_count
parameter_list|(
specifier|const
name|ldns_pkt
modifier|*
name|p
parameter_list|,
name|ldns_pkt_section
name|s
parameter_list|)
function_decl|;
comment|/**  * Return the packet's tsig pseudo rr's  * \param[in] p the packet  * \return the tsig rr  */
name|ldns_rr
modifier|*
name|ldns_pkt_tsig
parameter_list|(
specifier|const
name|ldns_pkt
modifier|*
name|p
parameter_list|)
function_decl|;
comment|/**  * Return the packet's question section  * \param[in] p the packet  * \return the section  */
name|ldns_rr_list
modifier|*
name|ldns_pkt_question
parameter_list|(
specifier|const
name|ldns_pkt
modifier|*
name|p
parameter_list|)
function_decl|;
comment|/**  * Return the packet's answer section  * \param[in] p the packet  * \return the section  */
name|ldns_rr_list
modifier|*
name|ldns_pkt_answer
parameter_list|(
specifier|const
name|ldns_pkt
modifier|*
name|p
parameter_list|)
function_decl|;
comment|/**  * Return the packet's authority section  * \param[in] p the packet  * \return the section  */
name|ldns_rr_list
modifier|*
name|ldns_pkt_authority
parameter_list|(
specifier|const
name|ldns_pkt
modifier|*
name|p
parameter_list|)
function_decl|;
comment|/**  * Return the packet's additional section  * \param[in] p the packet  * \return the section  */
name|ldns_rr_list
modifier|*
name|ldns_pkt_additional
parameter_list|(
specifier|const
name|ldns_pkt
modifier|*
name|p
parameter_list|)
function_decl|;
comment|/**  * Return the packet's question, answer, authority and additional sections  * concatenated, in a new rr_list clone.  * \param[in] p the packet  * \return the rrs  */
name|ldns_rr_list
modifier|*
name|ldns_pkt_all
parameter_list|(
specifier|const
name|ldns_pkt
modifier|*
name|p
parameter_list|)
function_decl|;
comment|/**  * Return the packet's answer, authority and additional sections concatenated,   * in a new rr_list clone.  Like ldns_pkt_all but without the questions.  * \param[in] p the packet  * \return the rrs except the question rrs  */
name|ldns_rr_list
modifier|*
name|ldns_pkt_all_noquestion
parameter_list|(
specifier|const
name|ldns_pkt
modifier|*
name|p
parameter_list|)
function_decl|;
comment|/**  * return all the rr_list's in the packet. Clone the lists, instead  * of returning pointers.   * \param[in] p the packet to look in  * \param[in] s what section(s) to return  * \return ldns_rr_list with the rr's or NULL if none were found  */
name|ldns_rr_list
modifier|*
name|ldns_pkt_get_section_clone
parameter_list|(
specifier|const
name|ldns_pkt
modifier|*
name|p
parameter_list|,
name|ldns_pkt_section
name|s
parameter_list|)
function_decl|;
comment|/**  * return all the rr with a specific name from a packet. Optionally  * specify from which section in the packet  * \param[in] p the packet  * \param[in] r the name  * \param[in] s the packet's section  * \return a list with the rr's or NULL if none were found  */
name|ldns_rr_list
modifier|*
name|ldns_pkt_rr_list_by_name
parameter_list|(
name|ldns_pkt
modifier|*
name|p
parameter_list|,
name|ldns_rdf
modifier|*
name|r
parameter_list|,
name|ldns_pkt_section
name|s
parameter_list|)
function_decl|;
comment|/**  * return all the rr with a specific type from a packet. Optionally  * specify from which section in the packet  * \param[in] p the packet  * \param[in] t the type  * \param[in] s the packet's section  * \return a list with the rr's or NULL if none were found  */
name|ldns_rr_list
modifier|*
name|ldns_pkt_rr_list_by_type
parameter_list|(
specifier|const
name|ldns_pkt
modifier|*
name|p
parameter_list|,
name|ldns_rr_type
name|t
parameter_list|,
name|ldns_pkt_section
name|s
parameter_list|)
function_decl|;
comment|/**  * return all the rr with a specific type and type from a packet. Optionally  * specify from which section in the packet  * \param[in] packet the packet  * \param[in] ownername the name  * \param[in] type the type  * \param[in] sec the packet's section  * \return a list with the rr's or NULL if none were found  */
name|ldns_rr_list
modifier|*
name|ldns_pkt_rr_list_by_name_and_type
parameter_list|(
specifier|const
name|ldns_pkt
modifier|*
name|packet
parameter_list|,
specifier|const
name|ldns_rdf
modifier|*
name|ownername
parameter_list|,
name|ldns_rr_type
name|type
parameter_list|,
name|ldns_pkt_section
name|sec
parameter_list|)
function_decl|;
comment|/**  * check to see if an rr exist in the packet  * \param[in] pkt the packet to examine  * \param[in] sec in which section to look  * \param[in] rr the rr to look for  */
name|bool
name|ldns_pkt_rr
parameter_list|(
name|ldns_pkt
modifier|*
name|pkt
parameter_list|,
name|ldns_pkt_section
name|sec
parameter_list|,
name|ldns_rr
modifier|*
name|rr
parameter_list|)
function_decl|;
comment|/**  * sets the flags in a packet.  * \param[in] pkt the packet to operate on  * \param[in] flags ORed values: LDNS_QR| LDNS_AR for instance  * \return true on success otherwise false  */
name|bool
name|ldns_pkt_set_flags
parameter_list|(
name|ldns_pkt
modifier|*
name|pkt
parameter_list|,
name|uint16_t
name|flags
parameter_list|)
function_decl|;
comment|/**  * Set the packet's id  * \param[in] p the packet  * \param[in] id the id to set  */
name|void
name|ldns_pkt_set_id
parameter_list|(
name|ldns_pkt
modifier|*
name|p
parameter_list|,
name|uint16_t
name|id
parameter_list|)
function_decl|;
comment|/**  * Set the packet's id to a random value  * \param[in] p the packet  */
name|void
name|ldns_pkt_set_random_id
parameter_list|(
name|ldns_pkt
modifier|*
name|p
parameter_list|)
function_decl|;
comment|/**  * Set the packet's qr bit  * \param[in] p the packet  * \param[in] b the value to set (boolean)  */
name|void
name|ldns_pkt_set_qr
parameter_list|(
name|ldns_pkt
modifier|*
name|p
parameter_list|,
name|bool
name|b
parameter_list|)
function_decl|;
comment|/**  * Set the packet's aa bit  * \param[in] p the packet  * \param[in] b the value to set (boolean)  */
name|void
name|ldns_pkt_set_aa
parameter_list|(
name|ldns_pkt
modifier|*
name|p
parameter_list|,
name|bool
name|b
parameter_list|)
function_decl|;
comment|/**  * Set the packet's tc bit  * \param[in] p the packet  * \param[in] b the value to set (boolean)  */
name|void
name|ldns_pkt_set_tc
parameter_list|(
name|ldns_pkt
modifier|*
name|p
parameter_list|,
name|bool
name|b
parameter_list|)
function_decl|;
comment|/**  * Set the packet's rd bit  * \param[in] p the packet  * \param[in] b the value to set (boolean)  */
name|void
name|ldns_pkt_set_rd
parameter_list|(
name|ldns_pkt
modifier|*
name|p
parameter_list|,
name|bool
name|b
parameter_list|)
function_decl|;
comment|/**  * Set the packet's cd bit  * \param[in] p the packet  * \param[in] b the value to set (boolean)  */
name|void
name|ldns_pkt_set_cd
parameter_list|(
name|ldns_pkt
modifier|*
name|p
parameter_list|,
name|bool
name|b
parameter_list|)
function_decl|;
comment|/**  * Set the packet's ra bit  * \param[in] p the packet  * \param[in] b the value to set (boolean)  */
name|void
name|ldns_pkt_set_ra
parameter_list|(
name|ldns_pkt
modifier|*
name|p
parameter_list|,
name|bool
name|b
parameter_list|)
function_decl|;
comment|/**  * Set the packet's ad bit  * \param[in] p the packet  * \param[in] b the value to set (boolean)  */
name|void
name|ldns_pkt_set_ad
parameter_list|(
name|ldns_pkt
modifier|*
name|p
parameter_list|,
name|bool
name|b
parameter_list|)
function_decl|;
comment|/**  * Set the packet's opcode  * \param[in] p the packet  * \param[in] c the opcode  */
name|void
name|ldns_pkt_set_opcode
parameter_list|(
name|ldns_pkt
modifier|*
name|p
parameter_list|,
name|ldns_pkt_opcode
name|c
parameter_list|)
function_decl|;
comment|/**  * Set the packet's respons code  * \param[in] p the packet  * \param[in] c the rcode  */
name|void
name|ldns_pkt_set_rcode
parameter_list|(
name|ldns_pkt
modifier|*
name|p
parameter_list|,
name|uint8_t
name|c
parameter_list|)
function_decl|;
comment|/**  * Set the packet's qd count  * \param[in] p the packet  * \param[in] c the count  */
name|void
name|ldns_pkt_set_qdcount
parameter_list|(
name|ldns_pkt
modifier|*
name|p
parameter_list|,
name|uint16_t
name|c
parameter_list|)
function_decl|;
comment|/**  * Set the packet's an count  * \param[in] p the packet  * \param[in] c the count  */
name|void
name|ldns_pkt_set_ancount
parameter_list|(
name|ldns_pkt
modifier|*
name|p
parameter_list|,
name|uint16_t
name|c
parameter_list|)
function_decl|;
comment|/**  * Set the packet's ns count  * \param[in] p the packet  * \param[in] c the count  */
name|void
name|ldns_pkt_set_nscount
parameter_list|(
name|ldns_pkt
modifier|*
name|p
parameter_list|,
name|uint16_t
name|c
parameter_list|)
function_decl|;
comment|/**  * Set the packet's arcount  * \param[in] p the packet  * \param[in] c the count  */
name|void
name|ldns_pkt_set_arcount
parameter_list|(
name|ldns_pkt
modifier|*
name|p
parameter_list|,
name|uint16_t
name|c
parameter_list|)
function_decl|;
comment|/**  * Set the packet's answering server  * \param[in] p the packet  * \param[in] r the address  */
name|void
name|ldns_pkt_set_answerfrom
parameter_list|(
name|ldns_pkt
modifier|*
name|p
parameter_list|,
name|ldns_rdf
modifier|*
name|r
parameter_list|)
function_decl|;
comment|/**  * Set the packet's query time  * \param[in] p the packet  * \param[in] t the querytime in msec  */
name|void
name|ldns_pkt_set_querytime
parameter_list|(
name|ldns_pkt
modifier|*
name|p
parameter_list|,
name|uint32_t
name|t
parameter_list|)
function_decl|;
comment|/**  * Set the packet's size  * \param[in] p the packet  * \param[in] s the size  */
name|void
name|ldns_pkt_set_size
parameter_list|(
name|ldns_pkt
modifier|*
name|p
parameter_list|,
name|size_t
name|s
parameter_list|)
function_decl|;
comment|/**  * Set the packet's timestamp  * \param[in] p the packet  * \param[in] timeval the timestamp  */
name|void
name|ldns_pkt_set_timestamp
parameter_list|(
name|ldns_pkt
modifier|*
name|p
parameter_list|,
name|struct
name|timeval
name|timeval
parameter_list|)
function_decl|;
comment|/**  * Set a packet's section count to x  * \param[in] p the packet  * \param[in] s the section  * \param[in] x the section count  */
name|void
name|ldns_pkt_set_section_count
parameter_list|(
name|ldns_pkt
modifier|*
name|p
parameter_list|,
name|ldns_pkt_section
name|s
parameter_list|,
name|uint16_t
name|x
parameter_list|)
function_decl|;
comment|/**  * Set the packet's tsig rr  * \param[in] p the packet  * \param[in] t the tsig rr  */
name|void
name|ldns_pkt_set_tsig
parameter_list|(
name|ldns_pkt
modifier|*
name|p
parameter_list|,
name|ldns_rr
modifier|*
name|t
parameter_list|)
function_decl|;
comment|/**  * looks inside the packet to determine  * what kind of packet it is, AUTH, NXDOMAIN, REFERRAL, etc.  * \param[in] p the packet to examine  * \return the type of packet  */
name|ldns_pkt_type
name|ldns_pkt_reply_type
parameter_list|(
name|ldns_pkt
modifier|*
name|p
parameter_list|)
function_decl|;
comment|/**  * return the packet's edns udp size  * \param[in] packet the packet  * \return the size  */
name|uint16_t
name|ldns_pkt_edns_udp_size
parameter_list|(
specifier|const
name|ldns_pkt
modifier|*
name|packet
parameter_list|)
function_decl|;
comment|/**  * return the packet's edns extended rcode  * \param[in] packet the packet  * \return the rcode  */
name|uint8_t
name|ldns_pkt_edns_extended_rcode
parameter_list|(
specifier|const
name|ldns_pkt
modifier|*
name|packet
parameter_list|)
function_decl|;
comment|/**  * return the packet's edns version  * \param[in] packet the packet  * \return the version  */
name|uint8_t
name|ldns_pkt_edns_version
parameter_list|(
specifier|const
name|ldns_pkt
modifier|*
name|packet
parameter_list|)
function_decl|;
comment|/**  * return the packet's edns z value  * \param[in] packet the packet  * \return the z value  */
name|uint16_t
name|ldns_pkt_edns_z
parameter_list|(
specifier|const
name|ldns_pkt
modifier|*
name|packet
parameter_list|)
function_decl|;
comment|/**  * return the packet's edns data  * \param[in] packet the packet  * \return the data  */
name|ldns_rdf
modifier|*
name|ldns_pkt_edns_data
parameter_list|(
specifier|const
name|ldns_pkt
modifier|*
name|packet
parameter_list|)
function_decl|;
comment|/**  * return the packet's edns do bit  * \param[in] packet the packet  * \return the bit's value  */
name|bool
name|ldns_pkt_edns_do
parameter_list|(
specifier|const
name|ldns_pkt
modifier|*
name|packet
parameter_list|)
function_decl|;
comment|/**  * Set the packet's edns do bit  * \param[in] packet the packet  * \param[in] value the bit's new value  */
name|void
name|ldns_pkt_set_edns_do
parameter_list|(
name|ldns_pkt
modifier|*
name|packet
parameter_list|,
name|bool
name|value
parameter_list|)
function_decl|;
comment|/**  * returns true if this packet needs and EDNS rr to be sent.  * At the moment the only reason is an expected packet  * size larger than 512 bytes, but for instance dnssec would  * be a good reason too.  *  * \param[in] packet the packet to check  * \return true if packet needs edns rr  */
name|bool
name|ldns_pkt_edns
parameter_list|(
specifier|const
name|ldns_pkt
modifier|*
name|packet
parameter_list|)
function_decl|;
comment|/**  * Set the packet's edns udp size  * \param[in] packet the packet  * \param[in] s the size  */
name|void
name|ldns_pkt_set_edns_udp_size
parameter_list|(
name|ldns_pkt
modifier|*
name|packet
parameter_list|,
name|uint16_t
name|s
parameter_list|)
function_decl|;
comment|/**  * Set the packet's edns extended rcode  * \param[in] packet the packet  * \param[in] c the code  */
name|void
name|ldns_pkt_set_edns_extended_rcode
parameter_list|(
name|ldns_pkt
modifier|*
name|packet
parameter_list|,
name|uint8_t
name|c
parameter_list|)
function_decl|;
comment|/**  * Set the packet's edns version  * \param[in] packet the packet  * \param[in] v the version  */
name|void
name|ldns_pkt_set_edns_version
parameter_list|(
name|ldns_pkt
modifier|*
name|packet
parameter_list|,
name|uint8_t
name|v
parameter_list|)
function_decl|;
comment|/**  * Set the packet's edns z value  * \param[in] packet the packet  * \param[in] z the value  */
name|void
name|ldns_pkt_set_edns_z
parameter_list|(
name|ldns_pkt
modifier|*
name|packet
parameter_list|,
name|uint16_t
name|z
parameter_list|)
function_decl|;
comment|/**  * Set the packet's edns data  * \param[in] packet the packet  * \param[in] data the data  */
name|void
name|ldns_pkt_set_edns_data
parameter_list|(
name|ldns_pkt
modifier|*
name|packet
parameter_list|,
name|ldns_rdf
modifier|*
name|data
parameter_list|)
function_decl|;
comment|/**  * allocates and initializes a ldns_pkt structure.  * \return pointer to the new packet  */
name|ldns_pkt
modifier|*
name|ldns_pkt_new
parameter_list|(
name|void
parameter_list|)
function_decl|;
comment|/**  * frees the packet structure and all data that it contains.  * \param[in] packet The packet structure to free  * \return void  */
name|void
name|ldns_pkt_free
parameter_list|(
name|ldns_pkt
modifier|*
name|packet
parameter_list|)
function_decl|;
comment|/**  * creates a query packet for the given name, type, class.  * \param[out] p the packet to be returned  * \param[in] rr_name the name to query for (as string)  * \param[in] rr_type the type to query for  * \param[in] rr_class the class to query for  * \param[in] flags packet flags  * \return LDNS_STATUS_OK or a ldns_status mesg with the error  */
name|ldns_status
name|ldns_pkt_query_new_frm_str
parameter_list|(
name|ldns_pkt
modifier|*
modifier|*
name|p
parameter_list|,
specifier|const
name|char
modifier|*
name|rr_name
parameter_list|,
name|ldns_rr_type
name|rr_type
parameter_list|,
name|ldns_rr_class
name|rr_class
parameter_list|,
name|uint16_t
name|flags
parameter_list|)
function_decl|;
comment|/**  * creates an IXFR request packet for the given name, class.  * adds the SOA record to the authority section.  * \param[out] p the packet to be returned  * \param[in] rr_name the name to query for (as string)  * \param[in] rr_class the class to query for  * \param[in] flags packet flags  * \param[in] soa soa record to be added to the authority section  * \return LDNS_STATUS_OK or a ldns_status mesg with the error  */
name|ldns_status
name|ldns_pkt_ixfr_request_new_frm_str
parameter_list|(
name|ldns_pkt
modifier|*
modifier|*
name|p
parameter_list|,
specifier|const
name|char
modifier|*
name|rr_name
parameter_list|,
name|ldns_rr_class
name|rr_class
parameter_list|,
name|uint16_t
name|flags
parameter_list|,
name|ldns_rr
modifier|*
name|soa
parameter_list|)
function_decl|;
comment|/**  * creates a packet with a query in it for the given name, type and class.  * \param[in] rr_name the name to query for  * \param[in] rr_type the type to query for  * \param[in] rr_class the class to query for  * \param[in] flags packet flags  * \return ldns_pkt* a pointer to the new pkt  */
name|ldns_pkt
modifier|*
name|ldns_pkt_query_new
parameter_list|(
name|ldns_rdf
modifier|*
name|rr_name
parameter_list|,
name|ldns_rr_type
name|rr_type
parameter_list|,
name|ldns_rr_class
name|rr_class
parameter_list|,
name|uint16_t
name|flags
parameter_list|)
function_decl|;
comment|/**  * creates an IXFR request packet for the given name, type and class.  * adds the SOA record to the authority section.  * \param[in] rr_name the name to query for  * \param[in] rr_class the class to query for  * \param[in] flags packet flags  * \param[in] soa soa record to be added to the authority section  * \return ldns_pkt* a pointer to the new pkt  */
name|ldns_pkt
modifier|*
name|ldns_pkt_ixfr_request_new
parameter_list|(
name|ldns_rdf
modifier|*
name|rr_name
parameter_list|,
name|ldns_rr_class
name|rr_class
parameter_list|,
name|uint16_t
name|flags
parameter_list|,
name|ldns_rr
modifier|*
name|soa
parameter_list|)
function_decl|;
comment|/**  * clones the given packet, creating a fully allocated copy  *  * \param[in] pkt the packet to clone  * \return ldns_pkt* pointer to the new packet  */
name|ldns_pkt
modifier|*
name|ldns_pkt_clone
parameter_list|(
name|ldns_pkt
modifier|*
name|pkt
parameter_list|)
function_decl|;
comment|/**  * directly set the additional section  * \param[in] p packet to operate on  * \param[in] rr rrlist to set  */
name|void
name|ldns_pkt_set_additional
parameter_list|(
name|ldns_pkt
modifier|*
name|p
parameter_list|,
name|ldns_rr_list
modifier|*
name|rr
parameter_list|)
function_decl|;
comment|/**  * directly set the answer section  * \param[in] p packet to operate on  * \param[in] rr rrlist to set  */
name|void
name|ldns_pkt_set_answer
parameter_list|(
name|ldns_pkt
modifier|*
name|p
parameter_list|,
name|ldns_rr_list
modifier|*
name|rr
parameter_list|)
function_decl|;
comment|/**  * directly set the question section  * \param[in] p packet to operate on  * \param[in] rr rrlist to set  */
name|void
name|ldns_pkt_set_question
parameter_list|(
name|ldns_pkt
modifier|*
name|p
parameter_list|,
name|ldns_rr_list
modifier|*
name|rr
parameter_list|)
function_decl|;
comment|/**  * directly set the auhority section  * \param[in] p packet to operate on  * \param[in] rr rrlist to set  */
name|void
name|ldns_pkt_set_authority
parameter_list|(
name|ldns_pkt
modifier|*
name|p
parameter_list|,
name|ldns_rr_list
modifier|*
name|rr
parameter_list|)
function_decl|;
comment|/**  * push an rr on a packet  * \param[in] packet packet to operate on  * \param[in] section where to put it  * \param[in] rr rr to push  * \return a boolean which is true when the rr was added  */
name|bool
name|ldns_pkt_push_rr
parameter_list|(
name|ldns_pkt
modifier|*
name|packet
parameter_list|,
name|ldns_pkt_section
name|section
parameter_list|,
name|ldns_rr
modifier|*
name|rr
parameter_list|)
function_decl|;
comment|/**  * push an rr on a packet, provided the RR is not there.  * \param[in] pkt packet to operate on  * \param[in] sec where to put it  * \param[in] rr rr to push  * \return a boolean which is true when the rr was added  */
name|bool
name|ldns_pkt_safe_push_rr
parameter_list|(
name|ldns_pkt
modifier|*
name|pkt
parameter_list|,
name|ldns_pkt_section
name|sec
parameter_list|,
name|ldns_rr
modifier|*
name|rr
parameter_list|)
function_decl|;
comment|/**  * push a rr_list on a packet  * \param[in] packet packet to operate on  * \param[in] section where to put it  * \param[in] list the rr_list to push  * \return a boolean which is true when the rr was added  */
name|bool
name|ldns_pkt_push_rr_list
parameter_list|(
name|ldns_pkt
modifier|*
name|packet
parameter_list|,
name|ldns_pkt_section
name|section
parameter_list|,
name|ldns_rr_list
modifier|*
name|list
parameter_list|)
function_decl|;
comment|/**  * push an rr_list to a packet, provided the RRs are not already there.  * \param[in] pkt packet to operate on  * \param[in] sec where to put it  * \param[in] list the rr_list to push  * \return a boolean which is true when the rr was added  */
name|bool
name|ldns_pkt_safe_push_rr_list
parameter_list|(
name|ldns_pkt
modifier|*
name|pkt
parameter_list|,
name|ldns_pkt_section
name|sec
parameter_list|,
name|ldns_rr_list
modifier|*
name|list
parameter_list|)
function_decl|;
comment|/**  * check if a packet is empty  * \param[in] p packet  * \return true: empty, false: not empty  */
name|bool
name|ldns_pkt_empty
parameter_list|(
name|ldns_pkt
modifier|*
name|p
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
comment|/* LDNS_PACKET_H */
end_comment

end_unit

