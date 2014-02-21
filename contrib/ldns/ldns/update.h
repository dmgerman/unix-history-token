begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * update.h  *  * Functions for RFC 2136 Dynamic Update  *  * Copyright (c) 2005-2008, NLnet Labs. All rights reserved.  *  * See LICENSE for the license.  */
end_comment

begin_comment
comment|/**  * \file  *  * Defines functions to perform UPDATE queries  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|LDNS_UPDATE_H
end_ifndef

begin_define
define|#
directive|define
name|LDNS_UPDATE_H
end_define

begin_include
include|#
directive|include
file|<ldns/resolver.h>
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
comment|/**  * create an update packet from zone name, class and the rr lists  * \param[in] zone_rdf name of the zone  * \param[in] clas zone class  * \param[in] pr_rrlist list of Prerequisite Section RRs  * \param[in] up_rrlist list of Updates Section RRs  * \param[in] ad_rrlist list of Additional Data Section RRs (currently unused)  * \return the new packet  */
name|ldns_pkt
modifier|*
name|ldns_update_pkt_new
parameter_list|(
name|ldns_rdf
modifier|*
name|zone_rdf
parameter_list|,
name|ldns_rr_class
name|clas
parameter_list|,
name|ldns_rr_list
modifier|*
name|pr_rrlist
parameter_list|,
name|ldns_rr_list
modifier|*
name|up_rrlist
parameter_list|,
name|ldns_rr_list
modifier|*
name|ad_rrlist
parameter_list|)
function_decl|;
comment|/**  * add tsig credentials to  * a packet from a resolver  * \param[in] p packet to copy to  * \param[in] r resolver to copy from  *  * \return status wether successfull or not  */
name|ldns_status
name|ldns_update_pkt_tsig_add
parameter_list|(
name|ldns_pkt
modifier|*
name|p
parameter_list|,
name|ldns_resolver
modifier|*
name|r
parameter_list|)
function_decl|;
comment|/* access functions */
comment|/**  * Get the zo count  * \param[in] p the packet  * \return the zo count  */
name|uint16_t
name|ldns_update_zocount
parameter_list|(
specifier|const
name|ldns_pkt
modifier|*
name|p
parameter_list|)
function_decl|;
comment|/**  * Get the zo count  * \param[in] p the packet  * \return the pr count  */
name|uint16_t
name|ldns_update_prcount
parameter_list|(
specifier|const
name|ldns_pkt
modifier|*
name|p
parameter_list|)
function_decl|;
comment|/**  * Get the zo count  * \param[in] p the packet  * \return the up count  */
name|uint16_t
name|ldns_update_upcount
parameter_list|(
specifier|const
name|ldns_pkt
modifier|*
name|p
parameter_list|)
function_decl|;
comment|/**  * Get the zo count  * \param[in] p the packet  * \return the ad count  */
name|uint16_t
name|ldns_update_ad
parameter_list|(
specifier|const
name|ldns_pkt
modifier|*
name|p
parameter_list|)
function_decl|;
comment|/**  * Set the zo count  * \param[in] p the packet  * \param[in] c the zo count to set  */
name|void
name|ldns_update_set_zo
parameter_list|(
name|ldns_pkt
modifier|*
name|p
parameter_list|,
name|uint16_t
name|c
parameter_list|)
function_decl|;
comment|/**  * Set the pr count  * \param[in] p the packet  * \param[in] c the pr count to set  */
name|void
name|ldns_update_set_prcount
parameter_list|(
name|ldns_pkt
modifier|*
name|p
parameter_list|,
name|uint16_t
name|c
parameter_list|)
function_decl|;
comment|/**  * Set the up count  * \param[in] p the packet  * \param[in] c the up count to set  */
name|void
name|ldns_update_set_upcount
parameter_list|(
name|ldns_pkt
modifier|*
name|p
parameter_list|,
name|uint16_t
name|c
parameter_list|)
function_decl|;
comment|/**  * Set the ad count  * \param[in] p the packet  * \param[in] c the ad count to set  */
name|void
name|ldns_update_set_adcount
parameter_list|(
name|ldns_pkt
modifier|*
name|p
parameter_list|,
name|uint16_t
name|c
parameter_list|)
function_decl|;
comment|/* soa functions that need to be configured */
comment|/*  * Not sure if we want to keep these like this, therefore  * not documented  */
name|ldns_status
name|ldns_update_soa_mname
parameter_list|(
name|ldns_rdf
modifier|*
name|zone
parameter_list|,
name|ldns_resolver
modifier|*
name|r
parameter_list|,
name|ldns_rr_class
name|c
parameter_list|,
name|ldns_rdf
modifier|*
modifier|*
name|mname
parameter_list|)
function_decl|;
comment|/*   * Not sure if we want to keep these like this, therefore  * not documented  */
name|ldns_status
name|ldns_update_soa_zone_mname
parameter_list|(
specifier|const
name|char
modifier|*
name|fqdn
parameter_list|,
name|ldns_resolver
modifier|*
name|r
parameter_list|,
name|ldns_rr_class
name|c
parameter_list|,
name|ldns_rdf
modifier|*
modifier|*
name|zone_rdf
parameter_list|,
name|ldns_rdf
modifier|*
modifier|*
name|mname_rdf
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
comment|/* LDNS_UPDATE_H */
end_comment

end_unit

