begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/**  * \file higher.h  *  * Specifies some higher level functions that could  * be useful for certain applications  */
end_comment

begin_comment
comment|/*  * a Net::DNS like library for C  *  * (c) NLnet Labs, 2005-2006  *  * See the file LICENSE for the license  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|LDNS_HIGHER_H
end_ifndef

begin_define
define|#
directive|define
name|LDNS_HIGHER_H
end_define

begin_include
include|#
directive|include
file|<ldns/resolver.h>
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
file|<ldns/host2str.h>
end_include

begin_include
include|#
directive|include
file|<ldns/tsig.h>
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
comment|/**  * Ask the resolver about name  * and return all address records  * \param[in] r the resolver to use  * \param[in] name the name to look for  * \param[in] c the class to use  * \param[in] flags give some optional flags to the query  */
name|ldns_rr_list
modifier|*
name|ldns_get_rr_list_addr_by_name
parameter_list|(
name|ldns_resolver
modifier|*
name|r
parameter_list|,
name|ldns_rdf
modifier|*
name|name
parameter_list|,
name|ldns_rr_class
name|c
parameter_list|,
name|uint16_t
name|flags
parameter_list|)
function_decl|;
comment|/**  * ask the resolver about the address  * and return the name  * \param[in] r the resolver to use  * \param[in] addr the addr to look for  * \param[in] c the class to use  * \param[in] flags give some optional flags to the query  */
name|ldns_rr_list
modifier|*
name|ldns_get_rr_list_name_by_addr
parameter_list|(
name|ldns_resolver
modifier|*
name|r
parameter_list|,
name|ldns_rdf
modifier|*
name|addr
parameter_list|,
name|ldns_rr_class
name|c
parameter_list|,
name|uint16_t
name|flags
parameter_list|)
function_decl|;
comment|/**  * wade through fp (a /etc/hosts like file)  * and return a rr_list containing all the   * defined hosts in there  * \param[in] fp the file pointer to use  * \return ldns_rr_list * with the names  */
name|ldns_rr_list
modifier|*
name|ldns_get_rr_list_hosts_frm_fp
parameter_list|(
name|FILE
modifier|*
name|fp
parameter_list|)
function_decl|;
comment|/**  * wade through fp (a /etc/hosts like file)  * and return a rr_list containing all the   * defined hosts in there  * \param[in] fp the file pointer to use  * \param[in] line_nr pointer to an integer containing the current line number (for debugging purposes)  * \return ldns_rr_list * with the names  */
name|ldns_rr_list
modifier|*
name|ldns_get_rr_list_hosts_frm_fp_l
parameter_list|(
name|FILE
modifier|*
name|fp
parameter_list|,
name|int
modifier|*
name|line_nr
parameter_list|)
function_decl|;
comment|/**  * wade through fp (a /etc/hosts like file)  * and return a rr_list containing all the   * defined hosts in there  * \param[in] filename the filename to use (NULL for /etc/hosts)  * \return ldns_rr_list * with the names  */
name|ldns_rr_list
modifier|*
name|ldns_get_rr_list_hosts_frm_file
parameter_list|(
name|char
modifier|*
name|filename
parameter_list|)
function_decl|;
comment|/**  * This function is a wrapper function for ldns_get_rr_list_name_by_addr  * and ldns_get_rr_list_addr_by_name. It's name is from the getaddrinfo()   * library call. It tries to mimic that call, but without the lowlevel  * stuff.  * \param[in] res The resolver. If this value is NULL then a resolver will  * be created by ldns_getaddrinfo.  * \param[in] node the name or ip address to look up  * \param[in] c the class to look in  * \param[out] list put the found RR's in this list  * \return the number of RR found.  */
name|uint16_t
name|ldns_getaddrinfo
parameter_list|(
name|ldns_resolver
modifier|*
name|res
parameter_list|,
name|ldns_rdf
modifier|*
name|node
parameter_list|,
name|ldns_rr_class
name|c
parameter_list|,
name|ldns_rr_list
modifier|*
modifier|*
name|list
parameter_list|)
function_decl|;
comment|/**  * Check if t is enumerated in the nsec type rdata  * \param[in] nsec the NSEC Record to look in  * \param[in] t the type to check for  * \return true when t is found, otherwise return false  */
name|bool
name|ldns_nsec_type_check
parameter_list|(
name|ldns_rr
modifier|*
name|nsec
parameter_list|,
name|ldns_rr_type
name|t
parameter_list|)
function_decl|;
comment|/**  * Print a number of rdf's of the RR. The rdfnum-list must   * be ended by -1, otherwise unpredictable things might happen.  * rdfs may be printed multiple times  * \param[in] fp FILE * to write to  * \param[in] r RR to write  * \param[in] rdfnum a list of rdf to print.  */
name|void
name|ldns_print_rr_rdf
parameter_list|(
name|FILE
modifier|*
name|fp
parameter_list|,
name|ldns_rr
modifier|*
name|r
parameter_list|,
name|int
name|rdfnum
parameter_list|,
modifier|...
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
comment|/* LDNS_HIGHER_H */
end_comment

end_unit

