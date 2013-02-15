begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * a error2str function to make sense of all the  * error codes we have laying ardoun  *  * a Net::DNS like library for C  * LibDNS Team @ NLnet Labs  * (c) NLnet Labs, 2005-2006  * See the file LICENSE for the license  */
end_comment

begin_include
include|#
directive|include
file|<ldns/config.h>
end_include

begin_include
include|#
directive|include
file|<ldns/ldns.h>
end_include

begin_decl_stmt
name|ldns_lookup_table
name|ldns_error_str
index|[]
init|=
block|{
block|{
name|LDNS_STATUS_OK
block|,
literal|"All OK"
block|}
block|,
block|{
name|LDNS_STATUS_EMPTY_LABEL
block|,
literal|"Empty label"
block|}
block|,
block|{
name|LDNS_STATUS_LABEL_OVERFLOW
block|,
literal|"Label length overflow"
block|}
block|,
block|{
name|LDNS_STATUS_DOMAINNAME_OVERFLOW
block|,
literal|"Domainname length overflow"
block|}
block|,
block|{
name|LDNS_STATUS_DOMAINNAME_UNDERFLOW
block|,
literal|"Domainname length underflow (zero length)"
block|}
block|,
block|{
name|LDNS_STATUS_DDD_OVERFLOW
block|,
literal|"\\DDD sequence overflow (>255)"
block|}
block|,
block|{
name|LDNS_STATUS_PACKET_OVERFLOW
block|,
literal|"Packet size overflow"
block|}
block|,
block|{
name|LDNS_STATUS_INVALID_POINTER
block|,
literal|"Invalid compression pointer"
block|}
block|,
block|{
name|LDNS_STATUS_MEM_ERR
block|,
literal|"General memory error"
block|}
block|,
block|{
name|LDNS_STATUS_INTERNAL_ERR
block|,
literal|"Internal error, this should not happen"
block|}
block|,
block|{
name|LDNS_STATUS_SSL_ERR
block|,
literal|"Error in SSL library"
block|}
block|,
block|{
name|LDNS_STATUS_ERR
block|,
literal|"General LDNS error"
block|}
block|,
block|{
name|LDNS_STATUS_INVALID_INT
block|,
literal|"Conversion error, integer expected"
block|}
block|,
block|{
name|LDNS_STATUS_INVALID_IP4
block|,
literal|"Conversion error, ip4 addr expected"
block|}
block|,
block|{
name|LDNS_STATUS_INVALID_IP6
block|,
literal|"Conversion error, ip6 addr expected"
block|}
block|,
block|{
name|LDNS_STATUS_INVALID_STR
block|,
literal|"Conversion error, string expected"
block|}
block|,
block|{
name|LDNS_STATUS_INVALID_B32_EXT
block|,
literal|"Conversion error, b32 ext encoding expected"
block|}
block|,
block|{
name|LDNS_STATUS_INVALID_B64
block|,
literal|"Conversion error, b64 encoding expected"
block|}
block|,
block|{
name|LDNS_STATUS_INVALID_HEX
block|,
literal|"Conversion error, hex encoding expected"
block|}
block|,
block|{
name|LDNS_STATUS_INVALID_TIME
block|,
literal|"Conversion error, time encoding expected"
block|}
block|,
block|{
name|LDNS_STATUS_NETWORK_ERR
block|,
literal|"Could not send or receive, because of network error"
block|}
block|,
block|{
name|LDNS_STATUS_ADDRESS_ERR
block|,
literal|"Could not start AXFR, because of address error"
block|}
block|,
block|{
name|LDNS_STATUS_FILE_ERR
block|,
literal|"Could not open the files"
block|}
block|,
block|{
name|LDNS_STATUS_UNKNOWN_INET
block|,
literal|"Uknown address family"
block|}
block|,
block|{
name|LDNS_STATUS_NOT_IMPL
block|,
literal|"This function is not implemented (yet), please notify the developers - or not..."
block|}
block|,
block|{
name|LDNS_STATUS_NULL
block|,
literal|"Supplied value pointer null"
block|}
block|,
block|{
name|LDNS_STATUS_CRYPTO_UNKNOWN_ALGO
block|,
literal|"Unknown cryptographic algorithm"
block|}
block|,
block|{
name|LDNS_STATUS_CRYPTO_ALGO_NOT_IMPL
block|,
literal|"Cryptographic algorithm not implemented"
block|}
block|,
block|{
name|LDNS_STATUS_CRYPTO_NO_RRSIG
block|,
literal|"No DNSSEC signature(s)"
block|}
block|,
block|{
name|LDNS_STATUS_CRYPTO_NO_DNSKEY
block|,
literal|"No DNSSEC public key(s)"
block|}
block|,
block|{
name|LDNS_STATUS_CRYPTO_TYPE_COVERED_ERR
block|,
literal|"The signature does not cover this RRset"
block|}
block|,
block|{
name|LDNS_STATUS_CRYPTO_NO_TRUSTED_DNSKEY
block|,
literal|"No signatures found for trusted DNSSEC public key(s)"
block|}
block|,
block|{
name|LDNS_STATUS_CRYPTO_NO_DS
block|,
literal|"No DS record(s)"
block|}
block|,
block|{
name|LDNS_STATUS_CRYPTO_NO_TRUSTED_DS
block|,
literal|"Could not validate DS record(s)"
block|}
block|,
block|{
name|LDNS_STATUS_CRYPTO_NO_MATCHING_KEYTAG_DNSKEY
block|,
literal|"No keys with the keytag and algorithm from the RRSIG found"
block|}
block|,
block|{
name|LDNS_STATUS_CRYPTO_VALIDATED
block|,
literal|"Valid DNSSEC signature"
block|}
block|,
block|{
name|LDNS_STATUS_CRYPTO_BOGUS
block|,
literal|"Bogus DNSSEC signature"
block|}
block|,
block|{
name|LDNS_STATUS_CRYPTO_SIG_EXPIRED
block|,
literal|"DNSSEC signature has expired"
block|}
block|,
block|{
name|LDNS_STATUS_CRYPTO_SIG_NOT_INCEPTED
block|,
literal|"DNSSEC signature not incepted yet"
block|}
block|,
block|{
name|LDNS_STATUS_CRYPTO_TSIG_BOGUS
block|,
literal|"Bogus TSIG signature"
block|}
block|,
block|{
name|LDNS_STATUS_CRYPTO_TSIG_ERR
block|,
literal|"Could not create TSIG signature"
block|}
block|,
block|{
name|LDNS_STATUS_CRYPTO_EXPIRATION_BEFORE_INCEPTION
block|,
literal|"DNSSEC signature has expiration date earlier than inception date"
block|}
block|,
block|{
name|LDNS_STATUS_ENGINE_KEY_NOT_LOADED
block|,
literal|"Unable to load private key from engine"
block|}
block|,
block|{
name|LDNS_STATUS_NSEC3_ERR
block|,
literal|"Error in NSEC3 denial of existence proof"
block|}
block|,
block|{
name|LDNS_STATUS_RES_NO_NS
block|,
literal|"No (valid) nameservers defined in the resolver"
block|}
block|,
block|{
name|LDNS_STATUS_RES_QUERY
block|,
literal|"No correct query given to resolver"
block|}
block|,
block|{
name|LDNS_STATUS_WIRE_INCOMPLETE_HEADER
block|,
literal|"header section incomplete"
block|}
block|,
block|{
name|LDNS_STATUS_WIRE_INCOMPLETE_QUESTION
block|,
literal|"question section incomplete"
block|}
block|,
block|{
name|LDNS_STATUS_WIRE_INCOMPLETE_ANSWER
block|,
literal|"answer section incomplete"
block|}
block|,
block|{
name|LDNS_STATUS_WIRE_INCOMPLETE_AUTHORITY
block|,
literal|"authority section incomplete"
block|}
block|,
block|{
name|LDNS_STATUS_WIRE_INCOMPLETE_ADDITIONAL
block|,
literal|"additional section incomplete"
block|}
block|,
block|{
name|LDNS_STATUS_NO_DATA
block|,
literal|"No data"
block|}
block|,
block|{
name|LDNS_STATUS_CERT_BAD_ALGORITHM
block|,
literal|"Bad algorithm type for CERT record"
block|}
block|,
block|{
name|LDNS_STATUS_SYNTAX_TYPE_ERR
block|,
literal|"Syntax error, could not parse the RR's type"
block|}
block|,
block|{
name|LDNS_STATUS_SYNTAX_CLASS_ERR
block|,
literal|"Syntax error, could not parse the RR's class"
block|}
block|,
block|{
name|LDNS_STATUS_SYNTAX_TTL_ERR
block|,
literal|"Syntax error, could not parse the RR's TTL"
block|}
block|,
block|{
name|LDNS_STATUS_SYNTAX_INCLUDE_ERR_NOTIMPL
block|,
literal|"Syntax error, $INCLUDE not implemented"
block|}
block|,
block|{
name|LDNS_STATUS_SYNTAX_RDATA_ERR
block|,
literal|"Syntax error, could not parse the RR's rdata"
block|}
block|,
block|{
name|LDNS_STATUS_SYNTAX_DNAME_ERR
block|,
literal|"Syntax error, could not parse the RR's dname(s)"
block|}
block|,
block|{
name|LDNS_STATUS_SYNTAX_VERSION_ERR
block|,
literal|"Syntax error, version mismatch"
block|}
block|,
block|{
name|LDNS_STATUS_SYNTAX_ALG_ERR
block|,
literal|"Syntax error, algorithm unknown or non parseable"
block|}
block|,
block|{
name|LDNS_STATUS_SYNTAX_KEYWORD_ERR
block|,
literal|"Syntax error, unknown keyword in input"
block|}
block|,
block|{
name|LDNS_STATUS_SYNTAX_ERR
block|,
literal|"Syntax error, could not parse the RR"
block|}
block|,
block|{
name|LDNS_STATUS_SYNTAX_EMPTY
block|,
literal|"Empty line was returned"
block|}
block|,
block|{
name|LDNS_STATUS_SYNTAX_TTL
block|,
literal|"$TTL directive was seen in the zone"
block|}
block|,
block|{
name|LDNS_STATUS_SYNTAX_ORIGIN
block|,
literal|"$ORIGIN directive was seen in the zone"
block|}
block|,
block|{
name|LDNS_STATUS_SYNTAX_INCLUDE
block|,
literal|"$INCLUDE directive was seen in the zone"
block|}
block|,
block|{
name|LDNS_STATUS_SYNTAX_ITERATIONS_OVERFLOW
block|,
literal|"Iterations count for NSEC3 record higher than maximum"
block|}
block|,
block|{
name|LDNS_STATUS_SYNTAX_MISSING_VALUE_ERR
block|,
literal|"Syntax error, value expected"
block|}
block|,
block|{
name|LDNS_STATUS_SYNTAX_INTEGER_OVERFLOW
block|,
literal|"Syntax error, integer value too large"
block|}
block|,
block|{
name|LDNS_STATUS_SYNTAX_BAD_ESCAPE
block|,
literal|"Syntax error, bad escape sequence"
block|}
block|,
block|{
name|LDNS_STATUS_SOCKET_ERROR
block|,
literal|"Error creating socket"
block|}
block|,
block|{
name|LDNS_STATUS_DNSSEC_EXISTENCE_DENIED
block|,
literal|"Existence denied by NSEC"
block|}
block|,
block|{
name|LDNS_STATUS_DNSSEC_NSEC_RR_NOT_COVERED
block|,
literal|"RR not covered by the given NSEC RRs"
block|}
block|,
block|{
name|LDNS_STATUS_DNSSEC_NSEC_WILDCARD_NOT_COVERED
block|,
literal|"wildcard not covered by the given NSEC RRs"
block|}
block|,
block|{
name|LDNS_STATUS_DNSSEC_NSEC3_ORIGINAL_NOT_FOUND
block|,
literal|"original of NSEC3 hashed name could not be found"
block|}
block|,
block|{
name|LDNS_STATUS_MISSING_RDATA_FIELDS_RRSIG
block|,
literal|"The RRSIG has to few rdata fields"
block|}
block|,
block|{
name|LDNS_STATUS_MISSING_RDATA_FIELDS_KEY
block|,
literal|"The DNSKEY has to few rdata fields"
block|}
block|,
block|{
name|LDNS_STATUS_CRYPTO_SIG_EXPIRED_WITHIN_MARGIN
block|,
literal|"DNSSEC signature will expire too soon"
block|}
block|,
block|{
name|LDNS_STATUS_CRYPTO_SIG_NOT_INCEPTED_WITHIN_MARGIN
block|,
literal|"DNSSEC signature not incepted long enough"
block|}
block|,
block|{
literal|0
block|,
name|NULL
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_function
specifier|const
name|char
modifier|*
name|ldns_get_errorstr_by_id
parameter_list|(
name|ldns_status
name|err
parameter_list|)
block|{
name|ldns_lookup_table
modifier|*
name|lt
decl_stmt|;
name|lt
operator|=
name|ldns_lookup_by_id
argument_list|(
name|ldns_error_str
argument_list|,
name|err
argument_list|)
expr_stmt|;
if|if
condition|(
name|lt
condition|)
block|{
return|return
name|lt
operator|->
name|name
return|;
block|}
return|return
name|NULL
return|;
block|}
end_function

end_unit

