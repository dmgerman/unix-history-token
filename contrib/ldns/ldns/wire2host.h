begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * wire2host.h - from wire conversion routines  *  * a Net::DNS like library for C  *  * (c) NLnet Labs, 2005-2006  *  * See the file LICENSE for the license  */
end_comment

begin_comment
comment|/**  * \file  *  * Contains functions that translate dns data from the wire format (as sent  * by servers and clients) to the internal structures.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|LDNS_WIRE2HOST_H
end_ifndef

begin_define
define|#
directive|define
name|LDNS_WIRE2HOST_H
end_define

begin_include
include|#
directive|include
file|<ldns/rdata.h>
end_include

begin_include
include|#
directive|include
file|<ldns/common.h>
end_include

begin_include
include|#
directive|include
file|<ldns/error.h>
end_include

begin_include
include|#
directive|include
file|<ldns/rr.h>
end_include

begin_include
include|#
directive|include
file|<ldns/packet.h>
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
value|(ldns_read_uint16(wirebuf))
define|#
directive|define
name|LDNS_ID_SET
parameter_list|(
name|wirebuf
parameter_list|,
name|id
parameter_list|)
value|(ldns_write_uint16(wirebuf, id))
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
value|(ldns_read_uint16(wirebuf+LDNS_QDCOUNT_OFF))
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
value|(ldns_read_uint16(wirebuf+LDNS_ANCOUNT_OFF))
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
value|(ldns_read_uint16(wirebuf+LDNS_NSCOUNT_OFF))
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
value|(ldns_read_uint16(wirebuf+LDNS_ARCOUNT_OFF))
comment|/**  * converts the data on the uint8_t bytearray (in wire format) to a DNS packet.  * This function will initialize and allocate memory space for the packet   * structure.  *   * \param[in] packet pointer to the structure to hold the packet  * \param[in] data pointer to the buffer with the data  * \param[in] len the length of the data buffer (in bytes)  * \return LDNS_STATUS_OK if everything succeeds, error otherwise  */
name|ldns_status
name|ldns_wire2pkt
parameter_list|(
name|ldns_pkt
modifier|*
modifier|*
name|packet
parameter_list|,
specifier|const
name|uint8_t
modifier|*
name|data
parameter_list|,
name|size_t
name|len
parameter_list|)
function_decl|;
comment|/**  * converts the data on the uint8_t bytearray (in wire format) to a DNS packet.  * This function will initialize and allocate memory space for the packet   * structure.  *   * \param[in] packet pointer to the structure to hold the packet  * \param[in] buffer the buffer with the data  * \return LDNS_STATUS_OK if everything succeeds, error otherwise  */
name|ldns_status
name|ldns_buffer2pkt_wire
parameter_list|(
name|ldns_pkt
modifier|*
modifier|*
name|packet
parameter_list|,
name|ldns_buffer
modifier|*
name|buffer
parameter_list|)
function_decl|;
comment|/**  * converts the data on the uint8_t bytearray (in wire format) to a DNS   * dname rdata field. This function will initialize and allocate memory  * space for the dname structure. The length of the wiredata of this rdf   * is added to the *pos value.  *  * \param[in] dname pointer to the structure to hold the rdata value  * \param[in] wire pointer to the buffer with the data  * \param[in] max the length of the data buffer (in bytes)  * \param[in] pos the position of the rdf in the buffer (ie. the number of bytes   *            from the start of the buffer)  * \return LDNS_STATUS_OK if everything succeeds, error otherwise  */
name|ldns_status
name|ldns_wire2dname
parameter_list|(
name|ldns_rdf
modifier|*
modifier|*
name|dname
parameter_list|,
specifier|const
name|uint8_t
modifier|*
name|wire
parameter_list|,
name|size_t
name|max
parameter_list|,
name|size_t
modifier|*
name|pos
parameter_list|)
function_decl|;
comment|/**  * converts the data on the uint8_t bytearray (in wire format) to DNS   * rdata fields, and adds them to the list of rdfs of the given rr.  * This function will initialize and allocate memory space for the dname  * structures.  * The length of the wiredata of these rdfs is added to the *pos value.  *  * All rdfs belonging to the RR are read; the rr should have no rdfs  * yet. An error is returned if the format cannot be parsed.  *  * \param[in] rr pointer to the ldns_rr structure to hold the rdata value  * \param[in] wire pointer to the buffer with the data  * \param[in] max the length of the data buffer (in bytes)  * \param[in] pos the position of the rdf in the buffer (ie. the number of bytes   *            from the start of the buffer)  * \return LDNS_STATUS_OK if everything succeeds, error otherwise  */
name|ldns_status
name|ldns_wire2rdf
parameter_list|(
name|ldns_rr
modifier|*
name|rr
parameter_list|,
specifier|const
name|uint8_t
modifier|*
name|wire
parameter_list|,
name|size_t
name|max
parameter_list|,
name|size_t
modifier|*
name|pos
parameter_list|)
function_decl|;
comment|/**  * converts the data on the uint8_t bytearray (in wire format) to a DNS   * resource record.  * This function will initialize and allocate memory space for the rr  * structure.  * The length of the wiredata of this rr is added to the *pos value.  *   * \param[in] rr pointer to the structure to hold the rdata value  * \param[in] wire pointer to the buffer with the data  * \param[in] max the length of the data buffer (in bytes)  * \param[in] pos the position of the rr in the buffer (ie. the number of bytes   *            from the start of the buffer)  * \param[in] section the section in the packet the rr is meant for  * \return LDNS_STATUS_OK if everything succeeds, error otherwise  */
name|ldns_status
name|ldns_wire2rr
parameter_list|(
name|ldns_rr
modifier|*
modifier|*
name|rr
parameter_list|,
specifier|const
name|uint8_t
modifier|*
name|wire
parameter_list|,
name|size_t
name|max
parameter_list|,
name|size_t
modifier|*
name|pos
parameter_list|,
name|ldns_pkt_section
name|section
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
comment|/* LDNS_WIRE2HOST_H */
end_comment

end_unit

