begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * util.h  * util.c header file   * in ldns  * (c) 2005 NLnet Labs  *  * See the file LICENSE for the license  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_DRILL_UTIL_H_
end_ifndef

begin_define
define|#
directive|define
name|_DRILL_UTIL_H_
end_define

begin_include
include|#
directive|include
file|<ldns/ldns.h>
end_include

begin_comment
comment|/**  * Read  keys from filename and append to key_list.  */
end_comment

begin_function_decl
name|ldns_status
name|read_key_file
parameter_list|(
specifier|const
name|char
modifier|*
name|filename
parameter_list|,
name|ldns_rr_list
modifier|*
name|key_list
parameter_list|,
name|bool
name|silently
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * return a address rdf, either A or AAAA   * NULL if anything goes wrong  */
end_comment

begin_function_decl
name|ldns_rdf
modifier|*
name|ldns_rdf_new_addr_frm_str
parameter_list|(
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * print all the ds of the keys in the packet  */
end_comment

begin_function_decl
name|void
name|print_ds_of_keys
parameter_list|(
name|ldns_pkt
modifier|*
name|p
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * print some rdfs of a signature  */
end_comment

begin_function_decl
name|void
name|print_rrsig_abbr
parameter_list|(
name|FILE
modifier|*
name|fp
parameter_list|,
name|ldns_rr
modifier|*
name|sig
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * print some rdfs of a dnskey  */
end_comment

begin_function_decl
name|void
name|print_dnskey_abbr
parameter_list|(
name|FILE
modifier|*
name|fp
parameter_list|,
name|ldns_rr
modifier|*
name|key
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * print some rdfs of a ds  */
end_comment

begin_function_decl
name|void
name|print_ds_abbr
parameter_list|(
name|FILE
modifier|*
name|fp
parameter_list|,
name|ldns_rr
modifier|*
name|ds
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * print some rdfs of a rr in a rr_list  */
end_comment

begin_function_decl
name|void
name|print_rr_list_abbr
parameter_list|(
name|FILE
modifier|*
name|fp
parameter_list|,
name|ldns_rr_list
modifier|*
name|sig
parameter_list|,
specifier|const
name|char
modifier|*
name|usr
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Alloc some memory, with error checking  */
end_comment

begin_function_decl
name|void
modifier|*
name|xmalloc
parameter_list|(
name|size_t
name|s
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   * Realloc some memory, with error checking  */
end_comment

begin_function_decl
name|void
modifier|*
name|xrealloc
parameter_list|(
name|void
modifier|*
name|p
parameter_list|,
name|size_t
name|s
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Free the data  */
end_comment

begin_function_decl
name|void
name|xfree
parameter_list|(
name|void
modifier|*
name|q
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _DRILL_UTIL_H_ */
end_comment

end_unit

