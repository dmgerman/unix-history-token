begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * dane.h -- defines for the DNS-Based Authentication of Named Entities (DANE)  *                           Transport Layer Security (TLS) Protocol: TLSA  *  * Copyright (c) 2012, NLnet Labs. All rights reserved.  *  * See LICENSE for the license.  *  */
end_comment

begin_comment
comment|/**  * \file  *  * This module contains base functions for creating and verifying TLSA RR's  * with PKIX certificates, certificate chains and validation stores.  * (See RFC6394 and RFC6698).  *   * Since those functions heavily rely op cryptographic operations,  * this module is dependent on openssl.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|LDNS_DANE_H
end_ifndef

begin_define
define|#
directive|define
name|LDNS_DANE_H
end_define

begin_if
if|#
directive|if
name|LDNS_BUILD_CONFIG_USE_DANE
end_if

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

begin_if
if|#
directive|if
name|LDNS_BUILD_CONFIG_HAVE_SSL
end_if

begin_include
include|#
directive|include
file|<openssl/ssl.h>
end_include

begin_include
include|#
directive|include
file|<openssl/err.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* LDNS_BUILD_CONFIG_HAVE_SSL */
end_comment

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
comment|/**  * The different "Certificate usage" rdata field values for a TLSA RR.  */
enum|enum
name|ldns_enum_tlsa_certificate_usage
block|{
comment|/** CA constraint */
name|LDNS_TLSA_USAGE_CA_CONSTRAINT
init|=
literal|0
block|,
comment|/** Sevice certificate constraint */
name|LDNS_TLSA_USAGE_SERVICE_CERTIFICATE_CONSTRAINT
init|=
literal|1
block|,
comment|/** Trust anchor assertion */
name|LDNS_TLSA_USAGE_TRUST_ANCHOR_ASSERTION
init|=
literal|2
block|,
comment|/** Domain issued certificate */
name|LDNS_TLSA_USAGE_DOMAIN_ISSUED_CERTIFICATE
init|=
literal|3
block|}
enum|;
typedef|typedef
name|enum
name|ldns_enum_tlsa_certificate_usage
name|ldns_tlsa_certificate_usage
typedef|;
comment|/**  * The different "Selector" rdata field values for a TLSA RR.  */
enum|enum
name|ldns_enum_tlsa_selector
block|{
comment|/**  	 * Full certificate: the Certificate binary structure 	 * as defined in [RFC5280] 	 */
name|LDNS_TLSA_SELECTOR_FULL_CERTIFICATE
init|=
literal|0
block|,
comment|/**  	 * SubjectPublicKeyInfo: DER-encoded binary structure 	 * as defined in [RFC5280] 	 */
name|LDNS_TLSA_SELECTOR_SUBJECTPUBLICKEYINFO
init|=
literal|1
block|}
enum|;
typedef|typedef
name|enum
name|ldns_enum_tlsa_selector
name|ldns_tlsa_selector
typedef|;
comment|/**  * The different "Matching type" rdata field values for a TLSA RR.  */
enum|enum
name|ldns_enum_tlsa_matching_type
block|{
comment|/** Exact match on selected content */
name|LDNS_TLSA_MATCHING_TYPE_NO_HASH_USED
init|=
literal|0
block|,
comment|/** SHA-256 hash of selected content [RFC6234] */
name|LDNS_TLSA_MATCHING_TYPE_SHA256
init|=
literal|1
block|,
comment|/** SHA-512 hash of selected content [RFC6234] */
name|LDNS_TLSA_MATCHING_TYPE_SHA512
init|=
literal|2
block|}
enum|;
typedef|typedef
name|enum
name|ldns_enum_tlsa_matching_type
name|ldns_tlsa_matching_type
typedef|;
comment|/**  * Known transports to use with TLSA owner names.  */
enum|enum
name|ldns_enum_dane_transport
block|{
comment|/** TCP */
name|LDNS_DANE_TRANSPORT_TCP
init|=
literal|0
block|,
comment|/** UDP */
name|LDNS_DANE_TRANSPORT_UDP
init|=
literal|1
block|,
comment|/** SCTP */
name|LDNS_DANE_TRANSPORT_SCTP
init|=
literal|2
block|}
enum|;
typedef|typedef
name|enum
name|ldns_enum_dane_transport
name|ldns_dane_transport
typedef|;
comment|/**  * Creates a dname consisting of the given name, prefixed by the service port  * and type of transport: _<EM>port</EM>._<EM>transport</EM>.<EM>name</EM>.  *  * \param[out] tlsa_owner The created dname.  * \param[in] name The dname that should be prefixed.  * \param[in] port The service port number for wich the name should be created.  * \param[in] transport The transport for wich the name should be created.  * \return LDNS_STATUS_OK on success or an error code otherwise.  */
name|ldns_status
name|ldns_dane_create_tlsa_owner
parameter_list|(
name|ldns_rdf
modifier|*
modifier|*
name|tlsa_owner
parameter_list|,
specifier|const
name|ldns_rdf
modifier|*
name|name
parameter_list|,
name|uint16_t
name|port
parameter_list|,
name|ldns_dane_transport
name|transport
parameter_list|)
function_decl|;
if|#
directive|if
name|LDNS_BUILD_CONFIG_HAVE_SSL
comment|/**  * Creates a LDNS_RDF_TYPE_HEX type rdf based on the binary data choosen by  * the selector and encoded using matching_type.  *  * \param[out] rdf The created created rdf of type LDNS_RDF_TYPE_HEX.  * \param[in] cert The certificate from which the data is selected  * \param[in] selector The full certificate or the public key  * \param[in] matching_type The full data or the SHA256 or SHA512 hash  *            of the selected data  * \return LDNS_STATUS_OK on success or an error code otherwise.  */
name|ldns_status
name|ldns_dane_cert2rdf
parameter_list|(
name|ldns_rdf
modifier|*
modifier|*
name|rdf
parameter_list|,
name|X509
modifier|*
name|cert
parameter_list|,
name|ldns_tlsa_selector
name|selector
parameter_list|,
name|ldns_tlsa_matching_type
name|matching_type
parameter_list|)
function_decl|;
comment|/**  * Selects the certificate from cert, extra_certs or the pkix_validation_store  * based on the value of cert_usage and index.  *  * \param[out] selected_cert The selected cert.  * \param[in] cert The certificate to validate (or not)  * \param[in] extra_certs Intermediate certificates that might be necessary  *            during validation. May be NULL, except when the certificate   *            usage is "Trust Anchor Assertion" because the trust anchor has  *            to be provided.(otherwise choose a "Domain issued certificate!"  * \param[in] pkix_validation_store Used when the certificate usage is   *            "CA constraint" or "Service Certificate Constraint" to   *            validate the certificate and, in case of "CA constraint",  *            select the CA.  *            When pkix_validation_store is NULL, validation is explicitely  *            turned off and the behaviour is then the same as for "Trust  *            anchor assertion" and "Domain issued certificate" respectively.  * \param[in] cert_usage Which certificate to use and how to validate.  * \param[in] index Used to select the trust anchor when certificate usage  *            is "Trust Anchor Assertion". 0 is the last certificate in the  *            validation chain. 1 the one but last, etc. When index is -1,  *            the last certificate is used that MUST be self-signed.  *            This can help to make sure that the intended (self signed)  *            trust anchor is actually present in extra_certs (which is a  *            DANE requirement).  *  * \return LDNS_STATUS_OK on success or an error code otherwise.  */
name|ldns_status
name|ldns_dane_select_certificate
argument_list|(
name|X509
operator|*
operator|*
name|selected_cert
argument_list|,
name|X509
operator|*
name|cert
argument_list|,
name|STACK_OF
argument_list|(
name|X509
argument_list|)
operator|*
name|extra_certs
argument_list|,
name|X509_STORE
operator|*
name|pkix_validation_store
argument_list|,
name|ldns_tlsa_certificate_usage
name|cert_usage
argument_list|,
name|int
name|index
argument_list|)
decl_stmt|;
comment|/**  * Creates a TLSA resource record from the certificate.  * No PKIX validation is performed! The given certificate is used as data  * regardless the value of certificate_usage.  *  * \param[out] tlsa The created TLSA resource record.  * \param[in] certificate_usage The value for the Certificate Usage field  * \param[in] selector The value for the Selector field  * \param[in] matching_type The value for the Matching Type field  * \param[in] cert The certificate which data will be represented  *  * \return LDNS_STATUS_OK on success or an error code otherwise.  */
name|ldns_status
name|ldns_dane_create_tlsa_rr
parameter_list|(
name|ldns_rr
modifier|*
modifier|*
name|tlsa
parameter_list|,
name|ldns_tlsa_certificate_usage
name|certificate_usage
parameter_list|,
name|ldns_tlsa_selector
name|selector
parameter_list|,
name|ldns_tlsa_matching_type
name|matching_type
parameter_list|,
name|X509
modifier|*
name|cert
parameter_list|)
function_decl|;
comment|/**  * Verify if the given TLSA resource record matches the given certificate.  * Reporting on a TLSA rr mismatch (LDNS_STATUS_DANE_TLSA_DID_NOT_MATCH)  * is preferred over PKIX failure  (LDNS_STATUS_DANE_PKIX_DID_NOT_VALIDATE).  * So when PKIX validation is required by the TLSA Certificate usage,  * but the TLSA data does not match, LDNS_STATUS_DANE_TLSA_DID_NOT_MATCH  * is returned whether the PKIX validated or not.  *  * \param[in] tlsa_rr The resource record that specifies what and how to  *            match the certificate. With tlsa_rr == NULL, regular PKIX  *            validation is performed.  * \param[in] cert The certificate to match (and validate)  * \param[in] extra_certs Intermediate certificates that might be necessary  *            creating the validation chain.  * \param[in] pkix_validation_store Used when the certificate usage is   *            "CA constraint" or "Service Certificate Constraint" to   *            validate the certificate.  *  * \return LDNS_STATUS_OK on success,  *         LDNS_STATUS_DANE_TLSA_DID_NOT_MATCH on TLSA data mismatch,  *         LDNS_STATUS_DANE_PKIX_DID_NOT_VALIDATE when TLSA matched,  *         but the PKIX validation failed, or other ldns_status errors.  */
name|ldns_status
name|ldns_dane_verify_rr
argument_list|(
specifier|const
name|ldns_rr
operator|*
name|tlsa_rr
argument_list|,
name|X509
operator|*
name|cert
argument_list|,
name|STACK_OF
argument_list|(
name|X509
argument_list|)
operator|*
name|extra_certs
argument_list|,
name|X509_STORE
operator|*
name|pkix_validation_store
argument_list|)
decl_stmt|;
comment|/**  * Verify if any of the given TLSA resource records matches the given  * certificate.  *  * \param[in] tlsas The resource records that specify what and how to  *            match the certificate. One must match for this function  *            to succeed. With tlsas == NULL or the number of TLSA records  *            in tlsas == 0, regular PKIX validation is performed.  * \param[in] cert The certificate to match (and validate)  * \param[in] extra_certs Intermediate certificates that might be necessary  *            creating the validation chain.  * \param[in] pkix_validation_store Used when the certificate usage is   *            "CA constraint" or "Service Certificate Constraint" to   *            validate the certificate.  *  * \return LDNS_STATUS_OK on success,  *         LDNS_STATUS_DANE_PKIX_DID_NOT_VALIDATE when one of the TLSA's  *         matched but the PKIX validation failed,  *         LDNS_STATUS_DANE_TLSA_DID_NOT_MATCH when none of the TLSA's matched,  *         or other ldns_status errors.  */
name|ldns_status
name|ldns_dane_verify
argument_list|(
name|ldns_rr_list
operator|*
name|tlsas
argument_list|,
name|X509
operator|*
name|cert
argument_list|,
name|STACK_OF
argument_list|(
name|X509
argument_list|)
operator|*
name|extra_certs
argument_list|,
name|X509_STORE
operator|*
name|pkix_validation_store
argument_list|)
decl_stmt|;
endif|#
directive|endif
comment|/* LDNS_BUILD_CONFIG_HAVE_SSL */
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
comment|/* LDNS_BUILD_CONFIG_USE_DANE */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* LDNS_DANE_H */
end_comment

end_unit

