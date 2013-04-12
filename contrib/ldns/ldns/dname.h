begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * dname.h  *  * dname definitions  *  * a Net::DNS like library for C  *  * (c) NLnet Labs, 2004-2006  *  * See the file LICENSE for the license  */
end_comment

begin_comment
comment|/**  * \file dname.h  *  * dname contains function to read and manipulate domain names.  *  * Example domain names are "www.nlnetlabs.nl." and "." (the root)  *  * If a domain name ends with a dot ("."), it is called a Fully Qualified  * Domain Name (FQDN). In certain places (for instance when reading a zone  * file), an origin (which is just another domain name) non-FQDNs will be  * placed after the current. For instance, if i have a zone file where the  * origin has been set to "nl.", and my file contains the name  * "www.nlnetlabs", it will result in "www.nlnetlabs.nl.". Internally, dnames are  * always absolute (the dot is added when it is missing and there is no origin).  *  * An FQDN is also  * known as an absolute domain name, therefore the function to check this is  * called \ref ldns_dname_str_absolute  *  * Domain names are stored in \ref ldns_rdf structures, with the type  * \ref LDNS_RDF_TYPE_DNAME  *  * This module is *NOT* about the RR type called DNAME.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|LDNS_DNAME_H
end_ifndef

begin_define
define|#
directive|define
name|LDNS_DNAME_H
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
define|#
directive|define
name|LDNS_DNAME_NORMALIZE
value|tolower
comment|/**  * concatenates two dnames together  * \param[in] rd1 the leftside  * \param[in] rd2 the rightside  * \return a new rdf with leftside/rightside  */
name|ldns_rdf
modifier|*
name|ldns_dname_cat_clone
parameter_list|(
specifier|const
name|ldns_rdf
modifier|*
name|rd1
parameter_list|,
specifier|const
name|ldns_rdf
modifier|*
name|rd2
parameter_list|)
function_decl|;
comment|/**  * concatenates rd2 after rd1 (rd2 is copied, rd1 is modified)  * \param[in] rd1 the leftside  * \param[in] rd2 the rightside  * \return LDNS_STATUS_OK on success  */
name|ldns_status
name|ldns_dname_cat
parameter_list|(
name|ldns_rdf
modifier|*
name|rd1
parameter_list|,
name|ldns_rdf
modifier|*
name|rd2
parameter_list|)
function_decl|;
comment|/**  * Returns a clone of the given dname with the labels  * reversed  * \param[in] d the dname to reverse  * \return clone of the dname with the labels reversed.  */
name|ldns_rdf
modifier|*
name|ldns_dname_reverse
parameter_list|(
specifier|const
name|ldns_rdf
modifier|*
name|d
parameter_list|)
function_decl|;
comment|/**  * Clones the given dname from the nth label on  * \param[in] d The dname to clone  * \param[in] n the label nr to clone from, if this is 0, the complete  *              dname is cloned  * \return A newly allocated *rdf structure, containing the cloned dname,  *         or NULL if either d was NULL, not a dname, or if n>=  *         label_count  */
name|ldns_rdf
modifier|*
name|ldns_dname_clone_from
parameter_list|(
specifier|const
name|ldns_rdf
modifier|*
name|d
parameter_list|,
name|uint16_t
name|n
parameter_list|)
function_decl|;
comment|/**  * chop one label off the left side of a dname. so  * wwww.nlnetlabs.nl, becomes nlnetlabs.nl  * This new name is a clone and must be freed with ldns_deep_free()  * \param[in] d the dname to chop  * \return the remaining dname  */
name|ldns_rdf
modifier|*
name|ldns_dname_left_chop
parameter_list|(
specifier|const
name|ldns_rdf
modifier|*
name|d
parameter_list|)
function_decl|;
comment|/**  * count the number of labels inside a LDNS_RDF_DNAME type rdf.  * \param[in] *r the rdf  * \return the number of labels  */
name|uint8_t
name|ldns_dname_label_count
parameter_list|(
specifier|const
name|ldns_rdf
modifier|*
name|r
parameter_list|)
function_decl|;
comment|/**  * creates a new dname rdf from a string.  * \param[in] str string to use  * \return ldns_rdf* or NULL in case of an error  */
name|ldns_rdf
modifier|*
name|ldns_dname_new_frm_str
parameter_list|(
specifier|const
name|char
modifier|*
name|str
parameter_list|)
function_decl|;
comment|/**  * Create a new dname rdf from a string  * \param[in] s the size of the new dname  * \param[in] *data pointer to the actual data  *  * \return ldns_rdf*  */
name|ldns_rdf
modifier|*
name|ldns_dname_new
parameter_list|(
name|uint16_t
name|s
parameter_list|,
name|void
modifier|*
name|data
parameter_list|)
function_decl|;
comment|/**  * Create a new dname rdf from data (the data is copied)  * \param[in] size the size of the data  * \param[in] *data pointer to the actual data  *  * \return ldns_rdf*  */
name|ldns_rdf
modifier|*
name|ldns_dname_new_frm_data
parameter_list|(
name|uint16_t
name|size
parameter_list|,
specifier|const
name|void
modifier|*
name|data
parameter_list|)
function_decl|;
comment|/**  * Put a dname into canonical fmt - ie. lowercase it  * \param[in] rdf the dname to lowercase  * \return void  */
name|void
name|ldns_dname2canonical
parameter_list|(
specifier|const
name|ldns_rdf
modifier|*
name|rdf
parameter_list|)
function_decl|;
comment|/**  * test wether the name sub falls under parent (i.e. is a subdomain  * of parent). This function will return false if the given dnames are  * equal.  * \param[in] sub the name to test  * \param[in] parent the parent's name  * \return true if sub falls under parent, otherwise false  */
name|bool
name|ldns_dname_is_subdomain
parameter_list|(
specifier|const
name|ldns_rdf
modifier|*
name|sub
parameter_list|,
specifier|const
name|ldns_rdf
modifier|*
name|parent
parameter_list|)
function_decl|;
comment|/**  * Compares the two dname rdf's according to the algorithm for ordering  * in RFC4034 Section 6.  * \param[in] dname1 First dname rdf to compare  * \param[in] dname2 Second dname rdf to compare  * \return -1 if dname1 comes before dname2, 1 if dname1 comes after dname2, and 0 if they are equal.  */
name|int
name|ldns_dname_compare
parameter_list|(
specifier|const
name|ldns_rdf
modifier|*
name|dname1
parameter_list|,
specifier|const
name|ldns_rdf
modifier|*
name|dname2
parameter_list|)
function_decl|;
name|int
name|ldns_dname_compare_v
parameter_list|(
specifier|const
name|void
modifier|*
parameter_list|,
specifier|const
name|void
modifier|*
parameter_list|)
function_decl|;
comment|/**  * Checks whether the dname matches the given wildcard  * \param[in] dname The dname to check  * \param[in] wildcard The wildcard to check with  * \return 1 If the wildcard matches, OR if 'wildcard' is not a wildcard and  *           the names are *exactly* the same  *         0 If the wildcard does not match, or if it is not a wildcard and  *           the names are not the same  */
name|int
name|ldns_dname_match_wildcard
parameter_list|(
specifier|const
name|ldns_rdf
modifier|*
name|dname
parameter_list|,
specifier|const
name|ldns_rdf
modifier|*
name|wildcard
parameter_list|)
function_decl|;
comment|/**  * check if middle lays in the interval defined by prev and next  * prev<= middle< next. This is usefull for nsec checking  * \param[in] prev the previous dname  * \param[in] middle the dname to check  * \param[in] next the next dname  * return 0 on error or unknown, -1 when middle is in the interval, +1 when not  */
name|int
name|ldns_dname_interval
parameter_list|(
specifier|const
name|ldns_rdf
modifier|*
name|prev
parameter_list|,
specifier|const
name|ldns_rdf
modifier|*
name|middle
parameter_list|,
specifier|const
name|ldns_rdf
modifier|*
name|next
parameter_list|)
function_decl|;
comment|/**  * Checks whether the given dname string is absolute (i.e. ends with a '.')  * \param[in] *dname_str a string representing the dname  * \return true or false  */
name|bool
name|ldns_dname_str_absolute
parameter_list|(
specifier|const
name|char
modifier|*
name|dname_str
parameter_list|)
function_decl|;
comment|/**  * Checks whether the given dname is absolute (i.e. ends with a '.')  * \param[in] *dname a rdf representing the dname  * \return true or false  */
name|bool
name|ldns_dname_absolute
parameter_list|(
specifier|const
name|ldns_rdf
modifier|*
name|dname
parameter_list|)
function_decl|;
comment|/**  * look inside the rdf and if it is an LDNS_RDF_TYPE_DNAME  * try and retrieve a specific label. The labels are numbered  * starting from 0 (left most).  * \param[in] rdf the rdf to look in  * \param[in] labelpos return the label with this number  * \return a ldns_rdf* with the label as name or NULL on error  */
name|ldns_rdf
modifier|*
name|ldns_dname_label
parameter_list|(
specifier|const
name|ldns_rdf
modifier|*
name|rdf
parameter_list|,
name|uint8_t
name|labelpos
parameter_list|)
function_decl|;
comment|/**  * Check if dname is a wildcard, starts with *.  * \param[in] dname: the rdf to look in  * \return true if a wildcard, false if not.  */
name|int
name|ldns_dname_is_wildcard
parameter_list|(
specifier|const
name|ldns_rdf
modifier|*
name|dname
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
comment|/* LDNS_DNAME_H */
end_comment

end_unit

