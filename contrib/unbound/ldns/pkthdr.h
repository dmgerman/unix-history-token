begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * pkthdr.h - packet header from wire conversion routines  *  * a Net::DNS like library for C  *  * (c) NLnet Labs, 2005-2006  *  * See the file LICENSE for the license  */
end_comment

begin_comment
comment|/**  * \file  *  * Contains functions that translate dns data from the wire format (as sent  * by servers and clients) to the internal structures for the packet header.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|LDNS_PKTHDR_H
end_ifndef

begin_define
define|#
directive|define
name|LDNS_PKTHDR_H
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
comment|/* The length of the header */
define|#
directive|define
name|LDNS_HEADER_SIZE
value|12
comment|/* First octet of flags */
define|#
directive|define
name|LDNS_RD_MASK
value|0x01U
define|#
directive|define
name|LDNS_RD_SHIFT
value|0
define|#
directive|define
name|LDNS_RD_WIRE
parameter_list|(
name|wirebuf
parameter_list|)
value|(*(wirebuf+2)& LDNS_RD_MASK)
define|#
directive|define
name|LDNS_RD_SET
parameter_list|(
name|wirebuf
parameter_list|)
value|(*(wirebuf+2) |= LDNS_RD_MASK)
define|#
directive|define
name|LDNS_RD_CLR
parameter_list|(
name|wirebuf
parameter_list|)
value|(*(wirebuf+2)&= ~LDNS_RD_MASK)
define|#
directive|define
name|LDNS_TC_MASK
value|0x02U
define|#
directive|define
name|LDNS_TC_SHIFT
value|1
define|#
directive|define
name|LDNS_TC_WIRE
parameter_list|(
name|wirebuf
parameter_list|)
value|(*(wirebuf+2)& LDNS_TC_MASK)
define|#
directive|define
name|LDNS_TC_SET
parameter_list|(
name|wirebuf
parameter_list|)
value|(*(wirebuf+2) |= LDNS_TC_MASK)
define|#
directive|define
name|LDNS_TC_CLR
parameter_list|(
name|wirebuf
parameter_list|)
value|(*(wirebuf+2)&= ~LDNS_TC_MASK)
define|#
directive|define
name|LDNS_AA_MASK
value|0x04U
define|#
directive|define
name|LDNS_AA_SHIFT
value|2
define|#
directive|define
name|LDNS_AA_WIRE
parameter_list|(
name|wirebuf
parameter_list|)
value|(*(wirebuf+2)& LDNS_AA_MASK)
define|#
directive|define
name|LDNS_AA_SET
parameter_list|(
name|wirebuf
parameter_list|)
value|(*(wirebuf+2) |= LDNS_AA_MASK)
define|#
directive|define
name|LDNS_AA_CLR
parameter_list|(
name|wirebuf
parameter_list|)
value|(*(wirebuf+2)&= ~LDNS_AA_MASK)
define|#
directive|define
name|LDNS_OPCODE_MASK
value|0x78U
define|#
directive|define
name|LDNS_OPCODE_SHIFT
value|3
define|#
directive|define
name|LDNS_OPCODE_WIRE
parameter_list|(
name|wirebuf
parameter_list|)
value|((*(wirebuf+2)& LDNS_OPCODE_MASK)>> LDNS_OPCODE_SHIFT)
define|#
directive|define
name|LDNS_OPCODE_SET
parameter_list|(
name|wirebuf
parameter_list|,
name|opcode
parameter_list|)
define|\
value|(*(wirebuf+2) = ((*(wirebuf+2))& ~LDNS_OPCODE_MASK) | ((opcode)<< LDNS_OPCODE_SHIFT))
define|#
directive|define
name|LDNS_QR_MASK
value|0x80U
define|#
directive|define
name|LDNS_QR_SHIFT
value|7
define|#
directive|define
name|LDNS_QR_WIRE
parameter_list|(
name|wirebuf
parameter_list|)
value|(*(wirebuf+2)& LDNS_QR_MASK)
define|#
directive|define
name|LDNS_QR_SET
parameter_list|(
name|wirebuf
parameter_list|)
value|(*(wirebuf+2) |= LDNS_QR_MASK)
define|#
directive|define
name|LDNS_QR_CLR
parameter_list|(
name|wirebuf
parameter_list|)
value|(*(wirebuf+2)&= ~LDNS_QR_MASK)
comment|/* Second octet of flags */
define|#
directive|define
name|LDNS_RCODE_MASK
value|0x0fU
define|#
directive|define
name|LDNS_RCODE_SHIFT
value|0
define|#
directive|define
name|LDNS_RCODE_WIRE
parameter_list|(
name|wirebuf
parameter_list|)
value|(*(wirebuf+3)& LDNS_RCODE_MASK)
define|#
directive|define
name|LDNS_RCODE_SET
parameter_list|(
name|wirebuf
parameter_list|,
name|rcode
parameter_list|)
define|\
value|(*(wirebuf+3) = ((*(wirebuf+3))& ~LDNS_RCODE_MASK) | (rcode))
define|#
directive|define
name|LDNS_CD_MASK
value|0x10U
define|#
directive|define
name|LDNS_CD_SHIFT
value|4
define|#
directive|define
name|LDNS_CD_WIRE
parameter_list|(
name|wirebuf
parameter_list|)
value|(*(wirebuf+3)& LDNS_CD_MASK)
define|#
directive|define
name|LDNS_CD_SET
parameter_list|(
name|wirebuf
parameter_list|)
value|(*(wirebuf+3) |= LDNS_CD_MASK)
define|#
directive|define
name|LDNS_CD_CLR
parameter_list|(
name|wirebuf
parameter_list|)
value|(*(wirebuf+3)&= ~LDNS_CD_MASK)
define|#
directive|define
name|LDNS_AD_MASK
value|0x20U
define|#
directive|define
name|LDNS_AD_SHIFT
value|5
define|#
directive|define
name|LDNS_AD_WIRE
parameter_list|(
name|wirebuf
parameter_list|)
value|(*(wirebuf+3)& LDNS_AD_MASK)
define|#
directive|define
name|LDNS_AD_SET
parameter_list|(
name|wirebuf
parameter_list|)
value|(*(wirebuf+3) |= LDNS_AD_MASK)
define|#
directive|define
name|LDNS_AD_CLR
parameter_list|(
name|wirebuf
parameter_list|)
value|(*(wirebuf+3)&= ~LDNS_AD_MASK)
define|#
directive|define
name|LDNS_Z_MASK
value|0x40U
define|#
directive|define
name|LDNS_Z_SHIFT
value|6
define|#
directive|define
name|LDNS_Z_WIRE
parameter_list|(
name|wirebuf
parameter_list|)
value|(*(wirebuf+3)& LDNS_Z_MASK)
define|#
directive|define
name|LDNS_Z_SET
parameter_list|(
name|wirebuf
parameter_list|)
value|(*(wirebuf+3) |= LDNS_Z_MASK)
define|#
directive|define
name|LDNS_Z_CLR
parameter_list|(
name|wirebuf
parameter_list|)
value|(*(wirebuf+3)&= ~LDNS_Z_MASK)
define|#
directive|define
name|LDNS_RA_MASK
value|0x80U
define|#
directive|define
name|LDNS_RA_SHIFT
value|7
define|#
directive|define
name|LDNS_RA_WIRE
parameter_list|(
name|wirebuf
parameter_list|)
value|(*(wirebuf+3)& LDNS_RA_MASK)
define|#
directive|define
name|LDNS_RA_SET
parameter_list|(
name|wirebuf
parameter_list|)
value|(*(wirebuf+3) |= LDNS_RA_MASK)
define|#
directive|define
name|LDNS_RA_CLR
parameter_list|(
name|wirebuf
parameter_list|)
value|(*(wirebuf+3)&= ~LDNS_RA_MASK)
comment|/* Query ID */
define|#
directive|define
name|LDNS_ID_WIRE
parameter_list|(
name|wirebuf
parameter_list|)
value|(sldns_read_uint16(wirebuf))
define|#
directive|define
name|LDNS_ID_SET
parameter_list|(
name|wirebuf
parameter_list|,
name|id
parameter_list|)
value|(sldns_write_uint16(wirebuf, id))
comment|/* Counter of the question section */
define|#
directive|define
name|LDNS_QDCOUNT_OFF
value|4
comment|/* #define	QDCOUNT(wirebuf)		(ntohs(*(uint16_t *)(wirebuf+QDCOUNT_OFF))) */
define|#
directive|define
name|LDNS_QDCOUNT
parameter_list|(
name|wirebuf
parameter_list|)
value|(sldns_read_uint16(wirebuf+LDNS_QDCOUNT_OFF))
comment|/* Counter of the answer section */
define|#
directive|define
name|LDNS_ANCOUNT_OFF
value|6
define|#
directive|define
name|LDNS_ANCOUNT
parameter_list|(
name|wirebuf
parameter_list|)
value|(sldns_read_uint16(wirebuf+LDNS_ANCOUNT_OFF))
comment|/* Counter of the authority section */
define|#
directive|define
name|LDNS_NSCOUNT_OFF
value|8
define|#
directive|define
name|LDNS_NSCOUNT
parameter_list|(
name|wirebuf
parameter_list|)
value|(sldns_read_uint16(wirebuf+LDNS_NSCOUNT_OFF))
comment|/* Counter of the additional section */
define|#
directive|define
name|LDNS_ARCOUNT_OFF
value|10
define|#
directive|define
name|LDNS_ARCOUNT
parameter_list|(
name|wirebuf
parameter_list|)
value|(sldns_read_uint16(wirebuf+LDNS_ARCOUNT_OFF))
comment|/**  * The sections of a packet  */
enum|enum
name|sldns_enum_pkt_section
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
name|sldns_enum_pkt_section
name|sldns_pkt_section
typedef|;
comment|/* opcodes for pkt's */
enum|enum
name|sldns_enum_pkt_opcode
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
name|sldns_enum_pkt_opcode
name|sldns_pkt_opcode
typedef|;
comment|/* rcodes for pkts */
enum|enum
name|sldns_enum_pkt_rcode
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
name|sldns_enum_pkt_rcode
name|sldns_pkt_rcode
typedef|;
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
comment|/* LDNS_PKTHDR_H */
end_comment

end_unit

