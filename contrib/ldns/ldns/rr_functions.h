begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * rr_functions.h  *  * the .h file with defs for the per rr  * functions  *  * a Net::DNS like library for C  *   * (c) NLnet Labs, 2005-2006  *   * See the file LICENSE for the license  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|LDNS_RR_FUNCTIONS_H
end_ifndef

begin_define
define|#
directive|define
name|LDNS_RR_FUNCTIONS_H
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
comment|/**  * \file  *  * Defines some extra convenience functions for ldns_rr structures  */
comment|/* A / AAAA */
comment|/**  * returns the address of a LDNS_RR_TYPE_A rr  * \param[in] r the resource record  * \return a ldns_rdf* with the address or NULL on failure  */
name|ldns_rdf
modifier|*
name|ldns_rr_a_address
parameter_list|(
specifier|const
name|ldns_rr
modifier|*
name|r
parameter_list|)
function_decl|;
comment|/**  * sets the address of a LDNS_RR_TYPE_A rr  * \param[in] r the rr to use  * \param[in] f the address to set  * \return true on success, false otherwise  */
name|bool
name|ldns_rr_a_set_address
parameter_list|(
name|ldns_rr
modifier|*
name|r
parameter_list|,
name|ldns_rdf
modifier|*
name|f
parameter_list|)
function_decl|;
comment|/* NS */
comment|/**  * returns the name of a LDNS_RR_TYPE_NS rr  * \param[in] r the resource record  * \return a ldns_rdf* with the name or NULL on failure  */
name|ldns_rdf
modifier|*
name|ldns_rr_ns_nsdname
parameter_list|(
specifier|const
name|ldns_rr
modifier|*
name|r
parameter_list|)
function_decl|;
comment|/* MX */
comment|/**  * returns the mx pref. of a LDNS_RR_TYPE_MX rr  * \param[in] r the resource record  * \return a ldns_rdf* with the preference or NULL on failure  */
name|ldns_rdf
modifier|*
name|ldns_rr_mx_preference
parameter_list|(
specifier|const
name|ldns_rr
modifier|*
name|r
parameter_list|)
function_decl|;
comment|/**  * returns the mx host of a LDNS_RR_TYPE_MX rr  * \param[in] r the resource record  * \return a ldns_rdf* with the name of the MX host or NULL on failure  */
name|ldns_rdf
modifier|*
name|ldns_rr_mx_exchange
parameter_list|(
specifier|const
name|ldns_rr
modifier|*
name|r
parameter_list|)
function_decl|;
comment|/* RRSIG */
comment|/**  * returns the type covered of a LDNS_RR_TYPE_RRSIG rr  * \param[in] r the resource record  * \return a ldns_rdf* with the type covered or NULL on failure  */
name|ldns_rdf
modifier|*
name|ldns_rr_rrsig_typecovered
parameter_list|(
specifier|const
name|ldns_rr
modifier|*
name|r
parameter_list|)
function_decl|;
comment|/**  * sets the typecovered of a LDNS_RR_TYPE_RRSIG rr  * \param[in] r the rr to use  * \param[in] f the typecovered to set  * \return true on success, false otherwise  */
name|bool
name|ldns_rr_rrsig_set_typecovered
parameter_list|(
name|ldns_rr
modifier|*
name|r
parameter_list|,
name|ldns_rdf
modifier|*
name|f
parameter_list|)
function_decl|;
comment|/**  * returns the algorithm of a LDNS_RR_TYPE_RRSIG RR  * \param[in] r the resource record  * \return a ldns_rdf* with the algorithm or NULL on failure  */
name|ldns_rdf
modifier|*
name|ldns_rr_rrsig_algorithm
parameter_list|(
specifier|const
name|ldns_rr
modifier|*
name|r
parameter_list|)
function_decl|;
comment|/**  * sets the algorithm of a LDNS_RR_TYPE_RRSIG rr  * \param[in] r the rr to use  * \param[in] f the algorithm to set  * \return true on success, false otherwise  */
name|bool
name|ldns_rr_rrsig_set_algorithm
parameter_list|(
name|ldns_rr
modifier|*
name|r
parameter_list|,
name|ldns_rdf
modifier|*
name|f
parameter_list|)
function_decl|;
comment|/**  * returns the number of labels of a LDNS_RR_TYPE_RRSIG RR  * \param[in] r the resource record  * \return a ldns_rdf* with the number of labels or NULL on failure  */
name|ldns_rdf
modifier|*
name|ldns_rr_rrsig_labels
parameter_list|(
specifier|const
name|ldns_rr
modifier|*
name|r
parameter_list|)
function_decl|;
comment|/**  * sets the number of labels of a LDNS_RR_TYPE_RRSIG rr  * \param[in] r the rr to use  * \param[in] f the number of labels to set  * \return true on success, false otherwise  */
name|bool
name|ldns_rr_rrsig_set_labels
parameter_list|(
name|ldns_rr
modifier|*
name|r
parameter_list|,
name|ldns_rdf
modifier|*
name|f
parameter_list|)
function_decl|;
comment|/**  * returns the original TTL of a LDNS_RR_TYPE_RRSIG RR  * \param[in] r the resource record  * \return a ldns_rdf* with the original TTL or NULL on failure  */
name|ldns_rdf
modifier|*
name|ldns_rr_rrsig_origttl
parameter_list|(
specifier|const
name|ldns_rr
modifier|*
name|r
parameter_list|)
function_decl|;
comment|/**  * sets the original TTL of a LDNS_RR_TYPE_RRSIG rr  * \param[in] r the rr to use  * \param[in] f the original TTL to set  * \return true on success, false otherwise  */
name|bool
name|ldns_rr_rrsig_set_origttl
parameter_list|(
name|ldns_rr
modifier|*
name|r
parameter_list|,
name|ldns_rdf
modifier|*
name|f
parameter_list|)
function_decl|;
comment|/**  * returns the expiration time of a LDNS_RR_TYPE_RRSIG RR  * \param[in] r the resource record  * \return a ldns_rdf* with the expiration time or NULL on failure  */
name|ldns_rdf
modifier|*
name|ldns_rr_rrsig_expiration
parameter_list|(
specifier|const
name|ldns_rr
modifier|*
name|r
parameter_list|)
function_decl|;
comment|/**  * sets the expireation date of a LDNS_RR_TYPE_RRSIG rr  * \param[in] r the rr to use  * \param[in] f the expireation date to set  * \return true on success, false otherwise  */
name|bool
name|ldns_rr_rrsig_set_expiration
parameter_list|(
name|ldns_rr
modifier|*
name|r
parameter_list|,
name|ldns_rdf
modifier|*
name|f
parameter_list|)
function_decl|;
comment|/**  * returns the inception time of a LDNS_RR_TYPE_RRSIG RR  * \param[in] r the resource record  * \return a ldns_rdf* with the inception time or NULL on failure  */
name|ldns_rdf
modifier|*
name|ldns_rr_rrsig_inception
parameter_list|(
specifier|const
name|ldns_rr
modifier|*
name|r
parameter_list|)
function_decl|;
comment|/**  * sets the inception date of a LDNS_RR_TYPE_RRSIG rr  * \param[in] r the rr to use  * \param[in] f the inception date to set  * \return true on success, false otherwise  */
name|bool
name|ldns_rr_rrsig_set_inception
parameter_list|(
name|ldns_rr
modifier|*
name|r
parameter_list|,
name|ldns_rdf
modifier|*
name|f
parameter_list|)
function_decl|;
comment|/**  * returns the keytag of a LDNS_RR_TYPE_RRSIG RR  * \param[in] r the resource record  * \return a ldns_rdf* with the keytag or NULL on failure  */
name|ldns_rdf
modifier|*
name|ldns_rr_rrsig_keytag
parameter_list|(
specifier|const
name|ldns_rr
modifier|*
name|r
parameter_list|)
function_decl|;
comment|/**  * sets the keytag of a LDNS_RR_TYPE_RRSIG rr  * \param[in] r the rr to use  * \param[in] f the keytag to set  * \return true on success, false otherwise  */
name|bool
name|ldns_rr_rrsig_set_keytag
parameter_list|(
name|ldns_rr
modifier|*
name|r
parameter_list|,
name|ldns_rdf
modifier|*
name|f
parameter_list|)
function_decl|;
comment|/**  * returns the signers name of a LDNS_RR_TYPE_RRSIG RR  * \param[in] r the resource record  * \return a ldns_rdf* with the signers name or NULL on failure  */
name|ldns_rdf
modifier|*
name|ldns_rr_rrsig_signame
parameter_list|(
specifier|const
name|ldns_rr
modifier|*
name|r
parameter_list|)
function_decl|;
comment|/**  * sets the signers name of a LDNS_RR_TYPE_RRSIG rr  * \param[in] r the rr to use  * \param[in] f the signers name to set  * \return true on success, false otherwise  */
name|bool
name|ldns_rr_rrsig_set_signame
parameter_list|(
name|ldns_rr
modifier|*
name|r
parameter_list|,
name|ldns_rdf
modifier|*
name|f
parameter_list|)
function_decl|;
comment|/**  * returns the signature data of a LDNS_RR_TYPE_RRSIG RR  * \param[in] r the resource record  * \return a ldns_rdf* with the signature data or NULL on failure  */
name|ldns_rdf
modifier|*
name|ldns_rr_rrsig_sig
parameter_list|(
specifier|const
name|ldns_rr
modifier|*
name|r
parameter_list|)
function_decl|;
comment|/**  * sets the signature data of a LDNS_RR_TYPE_RRSIG rr  * \param[in] r the rr to use  * \param[in] f the signature data to set  * \return true on success, false otherwise  */
name|bool
name|ldns_rr_rrsig_set_sig
parameter_list|(
name|ldns_rr
modifier|*
name|r
parameter_list|,
name|ldns_rdf
modifier|*
name|f
parameter_list|)
function_decl|;
comment|/* DNSKEY */
comment|/**  * returns the flags of a LDNS_RR_TYPE_DNSKEY rr  * \param[in] r the resource record  * \return a ldns_rdf* with the flags or NULL on failure  */
name|ldns_rdf
modifier|*
name|ldns_rr_dnskey_flags
parameter_list|(
specifier|const
name|ldns_rr
modifier|*
name|r
parameter_list|)
function_decl|;
comment|/**  * sets the flags of a LDNS_RR_TYPE_DNSKEY rr  * \param[in] r the rr to use  * \param[in] f the flags to set  * \return true on success, false otherwise  */
name|bool
name|ldns_rr_dnskey_set_flags
parameter_list|(
name|ldns_rr
modifier|*
name|r
parameter_list|,
name|ldns_rdf
modifier|*
name|f
parameter_list|)
function_decl|;
comment|/**  * returns the protocol of a LDNS_RR_TYPE_DNSKEY rr  * \param[in] r the resource record  * \return a ldns_rdf* with the protocol or NULL on failure  */
name|ldns_rdf
modifier|*
name|ldns_rr_dnskey_protocol
parameter_list|(
specifier|const
name|ldns_rr
modifier|*
name|r
parameter_list|)
function_decl|;
comment|/**  * sets the protocol of a LDNS_RR_TYPE_DNSKEY rr  * \param[in] r the rr to use  * \param[in] f the protocol to set  * \return true on success, false otherwise  */
name|bool
name|ldns_rr_dnskey_set_protocol
parameter_list|(
name|ldns_rr
modifier|*
name|r
parameter_list|,
name|ldns_rdf
modifier|*
name|f
parameter_list|)
function_decl|;
comment|/**  * returns the algorithm of a LDNS_RR_TYPE_DNSKEY rr  * \param[in] r the resource record  * \return a ldns_rdf* with the algorithm or NULL on failure  */
name|ldns_rdf
modifier|*
name|ldns_rr_dnskey_algorithm
parameter_list|(
specifier|const
name|ldns_rr
modifier|*
name|r
parameter_list|)
function_decl|;
comment|/**  * sets the algorithm of a LDNS_RR_TYPE_DNSKEY rr  * \param[in] r the rr to use  * \param[in] f the algorithm to set  * \return true on success, false otherwise  */
name|bool
name|ldns_rr_dnskey_set_algorithm
parameter_list|(
name|ldns_rr
modifier|*
name|r
parameter_list|,
name|ldns_rdf
modifier|*
name|f
parameter_list|)
function_decl|;
comment|/**  * returns the key data of a LDNS_RR_TYPE_DNSKEY rr  * \param[in] r the resource record  * \return a ldns_rdf* with the key data or NULL on failure  */
name|ldns_rdf
modifier|*
name|ldns_rr_dnskey_key
parameter_list|(
specifier|const
name|ldns_rr
modifier|*
name|r
parameter_list|)
function_decl|;
comment|/**  * sets the key data of a LDNS_RR_TYPE_DNSKEY rr  * \param[in] r the rr to use  * \param[in] f the key data to set  * \return true on success, false otherwise  */
name|bool
name|ldns_rr_dnskey_set_key
parameter_list|(
name|ldns_rr
modifier|*
name|r
parameter_list|,
name|ldns_rdf
modifier|*
name|f
parameter_list|)
function_decl|;
comment|/**  * get the length of the keydata in bits  * \param[in] keydata the raw key data  * \param[in] len the length of the keydata  * \param[in] alg the cryptographic algorithm this is a key for  * \return the keysize in bits, or 0 on error  */
name|size_t
name|ldns_rr_dnskey_key_size_raw
parameter_list|(
specifier|const
name|unsigned
name|char
modifier|*
name|keydata
parameter_list|,
specifier|const
name|size_t
name|len
parameter_list|,
specifier|const
name|ldns_algorithm
name|alg
parameter_list|)
function_decl|;
comment|/**  * get the length of the keydata in bits  * \param[in] key the key rr to use  * \return the keysize in bits  */
name|size_t
name|ldns_rr_dnskey_key_size
parameter_list|(
specifier|const
name|ldns_rr
modifier|*
name|key
parameter_list|)
function_decl|;
comment|/**  * The type of function to be passed to ldns_rr_soa_increment_func,  * ldns_rr_soa_increment_func_data or ldns_rr_soa_increment_int.  * The function will be called with as the first argument the current serial  * number of the SOA RR to be updated, and as the second argument a value  * given when calling ldns_rr_soa_increment_func_data or   * ldns_rr_soa_increment_int. With ldns_rr_soa_increment_int the pointer  * value holds the integer value passed to ldns_rr_soa_increment_int,  * and it should be cast to intptr_t to be used as an integer by the  * serial modifying function.  */
typedef|typedef
name|uint32_t
function_decl|(
modifier|*
name|ldns_soa_serial_increment_func_t
function_decl|)
parameter_list|(
name|uint32_t
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
comment|/**  * Function to be used with dns_rr_soa_increment_func_int, to set the soa  * serial number.   * \param[in] unused the (unused) current serial number.  * \param[in] data the serial number to be set.  */
name|uint32_t
name|ldns_soa_serial_identity
parameter_list|(
name|uint32_t
name|unused
parameter_list|,
name|void
modifier|*
name|data
parameter_list|)
function_decl|;
comment|/**  * Function to be used with dns_rr_soa_increment_func, to increment the soa  * serial number with one.   * \param[in] s the current serial number.  * \param[in] unused unused.  */
name|uint32_t
name|ldns_soa_serial_increment
parameter_list|(
name|uint32_t
name|s
parameter_list|,
name|void
modifier|*
name|unused
parameter_list|)
function_decl|;
comment|/**  * Function to be used with dns_rr_soa_increment_func_int, to increment the soa  * serial number with a certain amount.   * \param[in] s the current serial number.  * \param[in] data the amount to add to the current serial number.  */
name|uint32_t
name|ldns_soa_serial_increment_by
parameter_list|(
name|uint32_t
name|s
parameter_list|,
name|void
modifier|*
name|data
parameter_list|)
function_decl|;
comment|/**  * Function to be used with ldns_rr_soa_increment_func or   * ldns_rr_soa_increment_func_int to set the soa serial to the number of   * seconds since unix epoch (1-1-1970 00:00).   * When data is given (i.e. the function is called via  * ldns_rr_soa_increment_func_int), it is used as the current time.   * When the resulting serial number is smaller than the current serial number,  * the current serial number is increased by one.  * \param[in] s the current serial number.  * \param[in] data the time in seconds since 1-1-1970 00:00  */
name|uint32_t
name|ldns_soa_serial_unixtime
parameter_list|(
name|uint32_t
name|s
parameter_list|,
name|void
modifier|*
name|data
parameter_list|)
function_decl|;
comment|/**  * Function to be used with ldns_rr_soa_increment_func or   * ldns_rr_soa_increment_func_int to set the soa serial to the current date  * succeeded by a two digit iteration (datecounter).  * When data is given (i.e. the function is called via  * ldns_rr_soa_increment_func_int), it is used as the current time.   * When the resulting serial number is smaller than the current serial number,  * the current serial number is increased by one.  * \param[in] s the current serial number.  * \param[in] data the time in seconds since 1-1-1970 00:00  */
name|uint32_t
name|ldns_soa_serial_datecounter
parameter_list|(
name|uint32_t
name|s
parameter_list|,
name|void
modifier|*
name|data
parameter_list|)
function_decl|;
comment|/**  * Increment the serial number of the given SOA by one.  * \param[in] soa The soa rr to be incremented  */
name|void
name|ldns_rr_soa_increment
parameter_list|(
name|ldns_rr
modifier|*
name|soa
parameter_list|)
function_decl|;
comment|/**  * Increment the serial number of the given SOA with the given function.  * Included functions to be used here are: ldns_rr_soa_increment,   * ldns_soa_serial_unixtime and ldns_soa_serial_datecounter.  * \param[in] soa The soa rr to be incremented  * \param[in] f the function to use to increment the soa rr.  */
name|void
name|ldns_rr_soa_increment_func
parameter_list|(
name|ldns_rr
modifier|*
name|soa
parameter_list|,
name|ldns_soa_serial_increment_func_t
name|f
parameter_list|)
function_decl|;
comment|/**  * Increment the serial number of the given SOA with the given function  * passing it the given data argument.  * \param[in] soa The soa rr to be incremented  * \param[in] f the function to use to increment the soa rr.  * \param[in] data this argument will be passed to f as the second argument.  */
name|void
name|ldns_rr_soa_increment_func_data
parameter_list|(
name|ldns_rr
modifier|*
name|soa
parameter_list|,
name|ldns_soa_serial_increment_func_t
name|f
parameter_list|,
name|void
modifier|*
name|data
parameter_list|)
function_decl|;
comment|/**  * Increment the serial number of the given SOA with the given function  * using data as an argument for the function.  * Included functions to be used here are: ldns_soa_serial_identity,  * ldns_rr_soa_increment_by, ldns_soa_serial_unixtime and   * ldns_soa_serial_datecounter.  * \param[in] soa The soa rr to be incremented  * \param[in] f the function to use to increment the soa rr.  * \param[in] data this argument will be passed to f as the second argument  *                 (by casting it to void*).  */
name|void
name|ldns_rr_soa_increment_func_int
parameter_list|(
name|ldns_rr
modifier|*
name|soa
parameter_list|,
name|ldns_soa_serial_increment_func_t
name|f
parameter_list|,
name|int
name|data
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
comment|/* LDNS_RR_FUNCTIONS_H */
end_comment

end_unit

