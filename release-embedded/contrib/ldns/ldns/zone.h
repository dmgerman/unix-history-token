begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/**  * zone.h  *  * zone definitions  *  - what is it  *  - get_glue function  *  - search etc  *  * a Net::DNS like library for C  *  * (c) NLnet Labs, 2005-2006  *  * See the file LICENSE for the license  */
end_comment

begin_comment
comment|/**  * \file  *  * Defines the ldns_zone structure and functions to manipulate it.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|LDNS_ZONE_H
end_ifndef

begin_define
define|#
directive|define
name|LDNS_ZONE_H
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
file|<ldns/rr.h>
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
comment|/**   * DNS Zone  *  * A list of RR's with some  * extra information which comes from the SOA RR  * Note: nothing has been done to make this efficient (yet).  */
struct|struct
name|ldns_struct_zone
block|{
comment|/** the soa defines a zone */
name|ldns_rr
modifier|*
name|_soa
decl_stmt|;
comment|/* basicly a zone is a list of rr's */
name|ldns_rr_list
modifier|*
name|_rrs
decl_stmt|;
comment|/* we could change this to be a b-tree etc etc todo */
block|}
struct|;
typedef|typedef
name|struct
name|ldns_struct_zone
name|ldns_zone
typedef|;
comment|/**  * create a new ldns_zone structure  * \return a pointer to a ldns_zone structure  */
name|ldns_zone
modifier|*
name|ldns_zone_new
parameter_list|(
name|void
parameter_list|)
function_decl|;
comment|/**  * Return the soa record of a zone  * \param[in] z the zone to read from  * \return the soa record in the zone  */
name|ldns_rr
modifier|*
name|ldns_zone_soa
parameter_list|(
specifier|const
name|ldns_zone
modifier|*
name|z
parameter_list|)
function_decl|;
comment|/**  * Returns the number of resource records in the zone, NOT counting the SOA record  * \param[in] z the zone to read from  * \return the number of rr's in the zone  */
name|size_t
name|ldns_zone_rr_count
parameter_list|(
specifier|const
name|ldns_zone
modifier|*
name|z
parameter_list|)
function_decl|;
comment|/**  * Set the zone's soa record  * \param[in] z the zone to put the new soa in  * \param[in] soa the soa to set  */
name|void
name|ldns_zone_set_soa
parameter_list|(
name|ldns_zone
modifier|*
name|z
parameter_list|,
name|ldns_rr
modifier|*
name|soa
parameter_list|)
function_decl|;
comment|/**  * Get a list of a zone's content. Note that the SOA  * isn't included in this list. You need to get the   * with ldns_zone_soa.  * \param[in] z the zone to read from  * \return the rrs from this zone  */
name|ldns_rr_list
modifier|*
name|ldns_zone_rrs
parameter_list|(
specifier|const
name|ldns_zone
modifier|*
name|z
parameter_list|)
function_decl|;
comment|/**  * Set the zone's contents  * \param[in] z the zone to put the new soa in  * \param[in] rrlist the rrlist to use  */
name|void
name|ldns_zone_set_rrs
parameter_list|(
name|ldns_zone
modifier|*
name|z
parameter_list|,
name|ldns_rr_list
modifier|*
name|rrlist
parameter_list|)
function_decl|;
comment|/**  * push an rrlist to a zone structure. This function use pointer  * copying, so the rr_list structure inside z is modified!  * \param[in] z the zone to add to  * \param[in] list the list to add  * \return a true on succes otherwise falsed  */
name|bool
name|ldns_zone_push_rr_list
parameter_list|(
name|ldns_zone
modifier|*
name|z
parameter_list|,
name|ldns_rr_list
modifier|*
name|list
parameter_list|)
function_decl|;
comment|/**  * push an single rr to a zone structure. This function use pointer  * copying, so the rr_list structure inside z is modified!  * \param[in] z the zone to add to  * \param[in] rr the rr to add  * \return a true on succes otherwise falsed  */
name|bool
name|ldns_zone_push_rr
parameter_list|(
name|ldns_zone
modifier|*
name|z
parameter_list|,
name|ldns_rr
modifier|*
name|rr
parameter_list|)
function_decl|;
comment|/**  * Retrieve all resource records from the zone that are glue  * records. The resulting list does are pointer references  * to the zone's data.  *  * Due to the current zone implementation (as a list of rr's), this  * function is extremely slow. Another (probably better) way to do this  * is to use an ldns_dnssec_zone structure and the   * ldns_dnssec_mark_and_get_glue() function.  *  * \param[in] z the zone to look for glue  * \return the rr_list with the glue  */
name|ldns_rr_list
modifier|*
name|ldns_zone_glue_rr_list
parameter_list|(
specifier|const
name|ldns_zone
modifier|*
name|z
parameter_list|)
function_decl|;
comment|/**  * Create a new zone from a file  * \param[out] z the new zone  * \param[in] *fp the filepointer to use  * \param[in] *origin the zones' origin  * \param[in] ttl default ttl to use  * \param[in] c default class to use (IN)  *  * \return ldns_status mesg with an error or LDNS_STATUS_OK  */
name|ldns_status
name|ldns_zone_new_frm_fp
parameter_list|(
name|ldns_zone
modifier|*
modifier|*
name|z
parameter_list|,
name|FILE
modifier|*
name|fp
parameter_list|,
name|ldns_rdf
modifier|*
name|origin
parameter_list|,
name|uint32_t
name|ttl
parameter_list|,
name|ldns_rr_class
name|c
parameter_list|)
function_decl|;
comment|/**  * Create a new zone from a file, keep track of the line numbering  * \param[out] z the new zone  * \param[in] *fp the filepointer to use  * \param[in] *origin the zones' origin  * \param[in] ttl default ttl to use  * \param[in] c default class to use (IN)  * \param[out] line_nr used for error msg, to get to the line number  *  * \return ldns_status mesg with an error or LDNS_STATUS_OK  */
name|ldns_status
name|ldns_zone_new_frm_fp_l
parameter_list|(
name|ldns_zone
modifier|*
modifier|*
name|z
parameter_list|,
name|FILE
modifier|*
name|fp
parameter_list|,
name|ldns_rdf
modifier|*
name|origin
parameter_list|,
name|uint32_t
name|ttl
parameter_list|,
name|ldns_rr_class
name|c
parameter_list|,
name|int
modifier|*
name|line_nr
parameter_list|)
function_decl|;
comment|/**  * Frees the allocated memory for the zone, and the rr_list structure in it  * \param[in] zone the zone to free  */
name|void
name|ldns_zone_free
parameter_list|(
name|ldns_zone
modifier|*
name|zone
parameter_list|)
function_decl|;
comment|/**  * Frees the allocated memory for the zone, the soa rr in it,   * and the rr_list structure in it, including the rr's in that. etc.  * \param[in] zone the zone to free  */
name|void
name|ldns_zone_deep_free
parameter_list|(
name|ldns_zone
modifier|*
name|zone
parameter_list|)
function_decl|;
comment|/**  * Sort the rrs in a zone, with the current impl. this is slow  * \param[in] zone the zone to sort  */
name|void
name|ldns_zone_sort
parameter_list|(
name|ldns_zone
modifier|*
name|zone
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
comment|/* LDNS_ZONE_H */
end_comment

end_unit

