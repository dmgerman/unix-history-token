begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * host2wire.h - 2wire conversion routines  *  * a Net::DNS like library for C  *  * (c) NLnet Labs, 2005-2006  *  * See the file LICENSE for the license  */
end_comment

begin_comment
comment|/**  * \file  *  * Contains all functions to translate the main structures to wire format  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|LDNS_HOST2WIRE_H
end_ifndef

begin_define
define|#
directive|define
name|LDNS_HOST2WIRE_H
end_define

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
file|<ldns/rdata.h>
end_include

begin_include
include|#
directive|include
file|<ldns/packet.h>
end_include

begin_include
include|#
directive|include
file|<ldns/buffer.h>
end_include

begin_include
include|#
directive|include
file|<ctype.h>
end_include

begin_include
include|#
directive|include
file|"ldns/util.h"
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
comment|/**  * Copies the dname data to the buffer in wire format  * \param[out] *buffer buffer to append the result to  * \param[in] *name rdata dname to convert  * \return ldns_status  */
name|ldns_status
name|ldns_dname2buffer_wire
parameter_list|(
name|ldns_buffer
modifier|*
name|buffer
parameter_list|,
specifier|const
name|ldns_rdf
modifier|*
name|name
parameter_list|)
function_decl|;
comment|/**  * Copies the rdata data to the buffer in wire format  * \param[out] *output buffer to append the result to  * \param[in] *rdf rdata to convert  * \return ldns_status  */
name|ldns_status
name|ldns_rdf2buffer_wire
parameter_list|(
name|ldns_buffer
modifier|*
name|output
parameter_list|,
specifier|const
name|ldns_rdf
modifier|*
name|rdf
parameter_list|)
function_decl|;
comment|/**  * Copies the rdata data to the buffer in wire format  * If the rdata is a dname, the letters will be lowercased  * during the conversion  * \param[out] *output buffer to append the result to  * \param[in] *rdf rdata to convert  * \return ldns_status  */
name|ldns_status
name|ldns_rdf2buffer_wire_canonical
parameter_list|(
name|ldns_buffer
modifier|*
name|output
parameter_list|,
specifier|const
name|ldns_rdf
modifier|*
name|rdf
parameter_list|)
function_decl|;
comment|/**  * Copies the rr data to the buffer in wire format  * \param[out] *output buffer to append the result to  * \param[in] *rr resource record to convert  * \param[in] section the section in the packet this rr is supposed to be in  *            (to determine whether to add rdata or not)  * \return ldns_status  */
name|ldns_status
name|ldns_rr2buffer_wire
parameter_list|(
name|ldns_buffer
modifier|*
name|output
parameter_list|,
specifier|const
name|ldns_rr
modifier|*
name|rr
parameter_list|,
name|int
name|section
parameter_list|)
function_decl|;
comment|/**  * Copies the rr data to the buffer in wire format, in canonical format  * according to RFC3597 (every dname in rdata fields of RR's mentioned in  * that RFC will be lowercased)  * \param[out] *output buffer to append the result to  * \param[in] *rr resource record to convert  * \param[in] section the section in the packet this rr is supposed to be in  *            (to determine whether to add rdata or not)  * \return ldns_status  */
name|ldns_status
name|ldns_rr2buffer_wire_canonical
parameter_list|(
name|ldns_buffer
modifier|*
name|output
parameter_list|,
specifier|const
name|ldns_rr
modifier|*
name|rr
parameter_list|,
name|int
name|section
parameter_list|)
function_decl|;
comment|/**  * Converts a rrsig to wireformat BUT EXCLUDE the rrsig rdata  * This is needed in DNSSEC verification  * \param[out] output buffer to append the result to  * \param[in] sigrr signature rr to operate on  * \return ldns_status  */
name|ldns_status
name|ldns_rrsig2buffer_wire
parameter_list|(
name|ldns_buffer
modifier|*
name|output
parameter_list|,
specifier|const
name|ldns_rr
modifier|*
name|sigrr
parameter_list|)
function_decl|;
comment|/**  * Converts an rr's rdata to wireformat, while excluding  * the ownername and all the stuff before the rdata.  * This is needed in DNSSEC keytag calculation, the ds  * calcalution from the key and maybe elsewhere.  *  * \param[out] *output buffer where to put the result  * \param[in] *rr rr to operate on  * \return ldns_status  */
name|ldns_status
name|ldns_rr_rdata2buffer_wire
parameter_list|(
name|ldns_buffer
modifier|*
name|output
parameter_list|,
specifier|const
name|ldns_rr
modifier|*
name|rr
parameter_list|)
function_decl|;
comment|/**  * Copies the packet data to the buffer in wire format  * \param[out] *output buffer to append the result to  * \param[in] *pkt packet to convert  * \return ldns_status  */
name|ldns_status
name|ldns_pkt2buffer_wire
parameter_list|(
name|ldns_buffer
modifier|*
name|output
parameter_list|,
specifier|const
name|ldns_pkt
modifier|*
name|pkt
parameter_list|)
function_decl|;
comment|/**  * Copies the rr_list data to the buffer in wire format  * \param[out] *output buffer to append the result to  * \param[in] *rrlist rr_list to to convert  * \return ldns_status  */
name|ldns_status
name|ldns_rr_list2buffer_wire
parameter_list|(
name|ldns_buffer
modifier|*
name|output
parameter_list|,
specifier|const
name|ldns_rr_list
modifier|*
name|rrlist
parameter_list|)
function_decl|;
comment|/**  * Allocates an array of uint8_t at dest, and puts the wireformat of the  * given rdf in that array. The result_size value contains the  * length of the array, if it succeeds, and 0 otherwise (in which case  * the function also returns NULL)  *  * \param[out] dest pointer to the array of bytes to be created  * \param[in] rdf the rdata field to convert  * \param[out] size the size of the converted result  */
name|ldns_status
name|ldns_rdf2wire
parameter_list|(
name|uint8_t
modifier|*
modifier|*
name|dest
parameter_list|,
specifier|const
name|ldns_rdf
modifier|*
name|rdf
parameter_list|,
name|size_t
modifier|*
name|size
parameter_list|)
function_decl|;
comment|/**  * Allocates an array of uint8_t at dest, and puts the wireformat of the  * given rr in that array. The result_size value contains the  * length of the array, if it succeeds, and 0 otherwise (in which case  * the function also returns NULL)  *  * If the section argument is LDNS_SECTION_QUESTION, data like ttl and rdata  * are not put into the result  *  * \param[out] dest pointer to the array of bytes to be created  * \param[in] rr the rr to convert  * \param[out] size the size of the converted result  */
name|ldns_status
name|ldns_rr2wire
parameter_list|(
name|uint8_t
modifier|*
modifier|*
name|dest
parameter_list|,
specifier|const
name|ldns_rr
modifier|*
name|rr
parameter_list|,
name|int
parameter_list|,
name|size_t
modifier|*
name|size
parameter_list|)
function_decl|;
comment|/**  * Allocates an array of uint8_t at dest, and puts the wireformat of the  * given packet in that array. The result_size value contains the  * length of the array, if it succeeds, and 0 otherwise (in which case  * the function also returns NULL)  */
name|ldns_status
name|ldns_pkt2wire
parameter_list|(
name|uint8_t
modifier|*
modifier|*
name|dest
parameter_list|,
specifier|const
name|ldns_pkt
modifier|*
name|p
parameter_list|,
name|size_t
modifier|*
name|size
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
comment|/* LDNS_HOST2WIRE_H */
end_comment

end_unit

