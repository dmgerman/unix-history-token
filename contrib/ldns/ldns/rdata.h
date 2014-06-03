begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * rdata.h  *  * rdata definitions  *  * a Net::DNS like library for C  *  * (c) NLnet Labs, 2005-2006  *  * See the file LICENSE for the license  */
end_comment

begin_comment
comment|/**  * \file  *  * Defines ldns_rdf and functions to manipulate those.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|LDNS_RDATA_H
end_ifndef

begin_define
define|#
directive|define
name|LDNS_RDATA_H
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
name|LDNS_MAX_RDFLEN
value|65535
define|#
directive|define
name|LDNS_RDF_SIZE_BYTE
value|1
define|#
directive|define
name|LDNS_RDF_SIZE_WORD
value|2
define|#
directive|define
name|LDNS_RDF_SIZE_DOUBLEWORD
value|4
define|#
directive|define
name|LDNS_RDF_SIZE_6BYTES
value|6
define|#
directive|define
name|LDNS_RDF_SIZE_8BYTES
value|8
define|#
directive|define
name|LDNS_RDF_SIZE_16BYTES
value|16
define|#
directive|define
name|LDNS_NSEC3_VARS_OPTOUT_MASK
value|0x01
comment|/**  * The different types of RDATA fields.  */
enum|enum
name|ldns_enum_rdf_type
block|{
comment|/** none */
name|LDNS_RDF_TYPE_NONE
block|,
comment|/** domain name */
name|LDNS_RDF_TYPE_DNAME
block|,
comment|/** 8 bits */
name|LDNS_RDF_TYPE_INT8
block|,
comment|/** 16 bits */
name|LDNS_RDF_TYPE_INT16
block|,
comment|/** 32 bits */
name|LDNS_RDF_TYPE_INT32
block|,
comment|/** A record */
name|LDNS_RDF_TYPE_A
block|,
comment|/** AAAA record */
name|LDNS_RDF_TYPE_AAAA
block|,
comment|/** txt string */
name|LDNS_RDF_TYPE_STR
block|,
comment|/** apl data */
name|LDNS_RDF_TYPE_APL
block|,
comment|/** b32 string */
name|LDNS_RDF_TYPE_B32_EXT
block|,
comment|/** b64 string */
name|LDNS_RDF_TYPE_B64
block|,
comment|/** hex string */
name|LDNS_RDF_TYPE_HEX
block|,
comment|/** nsec type codes */
name|LDNS_RDF_TYPE_NSEC
block|,
comment|/** a RR type */
name|LDNS_RDF_TYPE_TYPE
block|,
comment|/** a class */
name|LDNS_RDF_TYPE_CLASS
block|,
comment|/** certificate algorithm */
name|LDNS_RDF_TYPE_CERT_ALG
block|,
comment|/** a key algorithm */
name|LDNS_RDF_TYPE_ALG
block|,
comment|/** unknown types */
name|LDNS_RDF_TYPE_UNKNOWN
block|,
comment|/** time (32 bits) */
name|LDNS_RDF_TYPE_TIME
block|,
comment|/** period */
name|LDNS_RDF_TYPE_PERIOD
block|,
comment|/** tsig time 48 bits */
name|LDNS_RDF_TYPE_TSIGTIME
block|,
comment|/** Represents the Public Key Algorithm, HIT and Public Key fields 	    for the HIP RR types.  A HIP specific rdf type is used because of 	    the unusual layout in wireformat (see RFC 5205 Section 5) */
name|LDNS_RDF_TYPE_HIP
block|,
comment|/** variable length any type rdata where the length 	    is specified by the first 2 bytes */
name|LDNS_RDF_TYPE_INT16_DATA
block|,
comment|/** protocol and port bitmaps */
name|LDNS_RDF_TYPE_SERVICE
block|,
comment|/** location data */
name|LDNS_RDF_TYPE_LOC
block|,
comment|/** well known services */
name|LDNS_RDF_TYPE_WKS
block|,
comment|/** NSAP */
name|LDNS_RDF_TYPE_NSAP
block|,
comment|/** ATMA */
name|LDNS_RDF_TYPE_ATMA
block|,
comment|/** IPSECKEY */
name|LDNS_RDF_TYPE_IPSECKEY
block|,
comment|/** nsec3 hash salt */
name|LDNS_RDF_TYPE_NSEC3_SALT
block|,
comment|/** nsec3 base32 string (with length byte on wire */
name|LDNS_RDF_TYPE_NSEC3_NEXT_OWNER
block|,
comment|/** 4 shorts represented as 4 * 16 bit hex numbers 	 *  separated by colons. For NID and L64. 	 */
name|LDNS_RDF_TYPE_ILNP64
block|,
comment|/** 6 * 8 bit hex numbers separated by dashes. For EUI48. */
name|LDNS_RDF_TYPE_EUI48
block|,
comment|/** 8 * 8 bit hex numbers separated by dashes. For EUI64. */
name|LDNS_RDF_TYPE_EUI64
block|,
comment|/** A non-zero sequence of US-ASCII letters and numbers in lower case. 	 *  For CAA. 	 */
name|LDNS_RDF_TYPE_TAG
block|,
comment|/** A<character-string> encoding of the value field as specified  	 * [RFC1035], Section 5.1., encoded as remaining rdata. 	 * For CAA. 	 */
name|LDNS_RDF_TYPE_LONG_STR
block|,
comment|/* Aliases */
name|LDNS_RDF_TYPE_BITMAP
init|=
name|LDNS_RDF_TYPE_NSEC
block|}
enum|;
typedef|typedef
name|enum
name|ldns_enum_rdf_type
name|ldns_rdf_type
typedef|;
comment|/**  * algorithms used in CERT rrs  */
enum|enum
name|ldns_enum_cert_algorithm
block|{
name|LDNS_CERT_PKIX
init|=
literal|1
block|,
name|LDNS_CERT_SPKI
init|=
literal|2
block|,
name|LDNS_CERT_PGP
init|=
literal|3
block|,
name|LDNS_CERT_IPKIX
init|=
literal|4
block|,
name|LDNS_CERT_ISPKI
init|=
literal|5
block|,
name|LDNS_CERT_IPGP
init|=
literal|6
block|,
name|LDNS_CERT_ACPKIX
init|=
literal|7
block|,
name|LDNS_CERT_IACPKIX
init|=
literal|8
block|,
name|LDNS_CERT_URI
init|=
literal|253
block|,
name|LDNS_CERT_OID
init|=
literal|254
block|}
enum|;
typedef|typedef
name|enum
name|ldns_enum_cert_algorithm
name|ldns_cert_algorithm
typedef|;
comment|/**  * Resource record data field.  *  * The data is a network ordered array of bytes, which size is specified by  * the (16-bit) size field. To correctly parse it, use the type  * specified in the (16-bit) type field with a value from \ref ldns_rdf_type.  */
struct|struct
name|ldns_struct_rdf
block|{
comment|/** The size of the data (in octets) */
name|size_t
name|_size
decl_stmt|;
comment|/** The type of the data */
name|ldns_rdf_type
name|_type
decl_stmt|;
comment|/** Pointer to the data (raw octets) */
name|void
modifier|*
name|_data
decl_stmt|;
block|}
struct|;
typedef|typedef
name|struct
name|ldns_struct_rdf
name|ldns_rdf
typedef|;
comment|/* prototypes */
comment|/* write access functions */
comment|/**  * sets the size of the rdf.  * \param[in] *rd the rdf to operate on  * \param[in] size the new size  * \return void  */
name|void
name|ldns_rdf_set_size
parameter_list|(
name|ldns_rdf
modifier|*
name|rd
parameter_list|,
name|size_t
name|size
parameter_list|)
function_decl|;
comment|/**  * sets the size of the rdf.  * \param[in] *rd the rdf to operate on  * \param[in] type the new type  * \return void  */
name|void
name|ldns_rdf_set_type
parameter_list|(
name|ldns_rdf
modifier|*
name|rd
parameter_list|,
name|ldns_rdf_type
name|type
parameter_list|)
function_decl|;
comment|/**  * sets the size of the rdf.  * \param[in] *rd the rdf to operate on  * \param[in] *data pointer to the new data  * \return void  */
name|void
name|ldns_rdf_set_data
parameter_list|(
name|ldns_rdf
modifier|*
name|rd
parameter_list|,
name|void
modifier|*
name|data
parameter_list|)
function_decl|;
comment|/* read access */
comment|/**  * returns the size of the rdf.  * \param[in] *rd the rdf to read from  * \return uint16_t with the size  */
name|size_t
name|ldns_rdf_size
parameter_list|(
specifier|const
name|ldns_rdf
modifier|*
name|rd
parameter_list|)
function_decl|;
comment|/**  * returns the type of the rdf. We need to insert _get_  * here to prevent conflict the the rdf_type TYPE.  * \param[in] *rd the rdf to read from  * \return ldns_rdf_type with the type  */
name|ldns_rdf_type
name|ldns_rdf_get_type
parameter_list|(
specifier|const
name|ldns_rdf
modifier|*
name|rd
parameter_list|)
function_decl|;
comment|/**  * returns the data of the rdf.  * \param[in] *rd the rdf to read from  *  * \return uint8_t* pointer to the rdf's data  */
name|uint8_t
modifier|*
name|ldns_rdf_data
parameter_list|(
specifier|const
name|ldns_rdf
modifier|*
name|rd
parameter_list|)
function_decl|;
comment|/* creator functions */
comment|/**  * allocates a new rdf structure and fills it.  * This function DOES NOT copy the contents from  * the buffer, unlinke ldns_rdf_new_frm_data()  * \param[in] type type of the rdf  * \param[in] size size of the buffer  * \param[in] data pointer to the buffer to be copied  * \return the new rdf structure or NULL on failure  */
name|ldns_rdf
modifier|*
name|ldns_rdf_new
parameter_list|(
name|ldns_rdf_type
name|type
parameter_list|,
name|size_t
name|size
parameter_list|,
name|void
modifier|*
name|data
parameter_list|)
function_decl|;
comment|/**  * allocates a new rdf structure and fills it.  * This function _does_ copy the contents from  * the buffer, unlinke ldns_rdf_new()  * \param[in] type type of the rdf  * \param[in] size size of the buffer  * \param[in] data pointer to the buffer to be copied  * \return the new rdf structure or NULL on failure  */
name|ldns_rdf
modifier|*
name|ldns_rdf_new_frm_data
parameter_list|(
name|ldns_rdf_type
name|type
parameter_list|,
name|size_t
name|size
parameter_list|,
specifier|const
name|void
modifier|*
name|data
parameter_list|)
function_decl|;
comment|/**  * creates a new rdf from a string.  * \param[in] type   type to use  * \param[in] str string to use  * \return ldns_rdf* or NULL in case of an error  */
name|ldns_rdf
modifier|*
name|ldns_rdf_new_frm_str
parameter_list|(
name|ldns_rdf_type
name|type
parameter_list|,
specifier|const
name|char
modifier|*
name|str
parameter_list|)
function_decl|;
comment|/**  * creates a new rdf from a file containing a string.  * \param[out] r the new rdf  * \param[in] type   type to use  * \param[in] fp the file pointer  to use  * \return LDNS_STATUS_OK or the error  */
name|ldns_status
name|ldns_rdf_new_frm_fp
parameter_list|(
name|ldns_rdf
modifier|*
modifier|*
name|r
parameter_list|,
name|ldns_rdf_type
name|type
parameter_list|,
name|FILE
modifier|*
name|fp
parameter_list|)
function_decl|;
comment|/**  * creates a new rdf from a file containing a string.  * \param[out] r the new rdf  * \param[in] type   type to use  * \param[in] fp the file pointer  to use  * \param[in] line_nr pointer to an integer containing the current line number (for debugging purposes)  * \return LDNS_STATUS_OK or the error  */
name|ldns_status
name|ldns_rdf_new_frm_fp_l
parameter_list|(
name|ldns_rdf
modifier|*
modifier|*
name|r
parameter_list|,
name|ldns_rdf_type
name|type
parameter_list|,
name|FILE
modifier|*
name|fp
parameter_list|,
name|int
modifier|*
name|line_nr
parameter_list|)
function_decl|;
comment|/* destroy functions */
comment|/**  * frees a rdf structure, leaving the  * data pointer intact.  * \param[in] rd the pointer to be freed  * \return void  */
name|void
name|ldns_rdf_free
parameter_list|(
name|ldns_rdf
modifier|*
name|rd
parameter_list|)
function_decl|;
comment|/**  * frees a rdf structure _and_ frees the  * data. rdf should be created with _new_frm_data  * \param[in] rd the rdf structure to be freed  * \return void  */
name|void
name|ldns_rdf_deep_free
parameter_list|(
name|ldns_rdf
modifier|*
name|rd
parameter_list|)
function_decl|;
comment|/* conversion functions */
comment|/**  * returns the rdf containing the native uint8_t repr.  * \param[in] type the ldns_rdf type to use  * \param[in] value the uint8_t to use  * \return ldns_rdf* with the converted value  */
name|ldns_rdf
modifier|*
name|ldns_native2rdf_int8
parameter_list|(
name|ldns_rdf_type
name|type
parameter_list|,
name|uint8_t
name|value
parameter_list|)
function_decl|;
comment|/**  * returns the rdf containing the native uint16_t representation.  * \param[in] type the ldns_rdf type to use  * \param[in] value the uint16_t to use  * \return ldns_rdf* with the converted value  */
name|ldns_rdf
modifier|*
name|ldns_native2rdf_int16
parameter_list|(
name|ldns_rdf_type
name|type
parameter_list|,
name|uint16_t
name|value
parameter_list|)
function_decl|;
comment|/**  * returns an rdf that contains the given int32 value.  *  * Because multiple rdf types can contain an int32, the  * type must be specified  * \param[in] type the ldns_rdf type to use  * \param[in] value the uint32_t to use  * \return ldns_rdf* with the converted value  */
name|ldns_rdf
modifier|*
name|ldns_native2rdf_int32
parameter_list|(
name|ldns_rdf_type
name|type
parameter_list|,
name|uint32_t
name|value
parameter_list|)
function_decl|;
comment|/**  * returns an int16_data rdf that contains the data in the  * given array, preceded by an int16 specifying the length.  *  * The memory is copied, and an LDNS_RDF_TYPE_INT16DATA is returned  * \param[in] size the size of the data  * \param[in] *data pointer to the actual data  *  * \return ldns_rd* the rdf with the data  */
name|ldns_rdf
modifier|*
name|ldns_native2rdf_int16_data
parameter_list|(
name|size_t
name|size
parameter_list|,
name|uint8_t
modifier|*
name|data
parameter_list|)
function_decl|;
comment|/**  * reverses an rdf, only actually useful for AAAA and A records.  * The returned rdf has the type LDNS_RDF_TYPE_DNAME!  * \param[in] *rd rdf to be reversed  * \return the reversed rdf (a newly created rdf)  */
name|ldns_rdf
modifier|*
name|ldns_rdf_address_reverse
parameter_list|(
name|ldns_rdf
modifier|*
name|rd
parameter_list|)
function_decl|;
comment|/**  * returns the native uint8_t representation from the rdf.  * \param[in] rd the ldns_rdf to operate on  * \return uint8_t the value extracted  */
name|uint8_t
name|ldns_rdf2native_int8
parameter_list|(
specifier|const
name|ldns_rdf
modifier|*
name|rd
parameter_list|)
function_decl|;
comment|/**  * returns the native uint16_t representation from the rdf.  * \param[in] rd the ldns_rdf to operate on  * \return uint16_t the value extracted  */
name|uint16_t
name|ldns_rdf2native_int16
parameter_list|(
specifier|const
name|ldns_rdf
modifier|*
name|rd
parameter_list|)
function_decl|;
comment|/**  * returns the native uint32_t representation from the rdf.  * \param[in] rd the ldns_rdf to operate on  * \return uint32_t the value extracted  */
name|uint32_t
name|ldns_rdf2native_int32
parameter_list|(
specifier|const
name|ldns_rdf
modifier|*
name|rd
parameter_list|)
function_decl|;
comment|/**  * returns the native time_t representation from the rdf.  * \param[in] rd the ldns_rdf to operate on  * \return time_t the value extracted (32 bits currently)  */
name|time_t
name|ldns_rdf2native_time_t
parameter_list|(
specifier|const
name|ldns_rdf
modifier|*
name|rd
parameter_list|)
function_decl|;
comment|/**  * converts a ttl value (like 5d2h) to a long.  * \param[in] nptr the start of the string  * \param[out] endptr points to the last char in case of error  * \return the convert duration value  */
name|uint32_t
name|ldns_str2period
parameter_list|(
specifier|const
name|char
modifier|*
name|nptr
parameter_list|,
specifier|const
name|char
modifier|*
modifier|*
name|endptr
parameter_list|)
function_decl|;
comment|/**  * removes \\DDD, \\[space] and other escapes from the input.  * See RFC 1035, section 5.1.  * \param[in] word what to check  * \param[in] length the string  * \return ldns_status mesg  */
name|ldns_status
name|ldns_octet
parameter_list|(
name|char
modifier|*
name|word
parameter_list|,
name|size_t
modifier|*
name|length
parameter_list|)
function_decl|;
comment|/**  * clones a rdf structure. The data is copied.  * \param[in] rd rdf to be copied  * \return a new rdf structure  */
name|ldns_rdf
modifier|*
name|ldns_rdf_clone
parameter_list|(
specifier|const
name|ldns_rdf
modifier|*
name|rd
parameter_list|)
function_decl|;
comment|/**  * compares two rdf's on their wire formats.  * (To order dnames according to rfc4034, use ldns_dname_compare)  * \param[in] rd1 the first one  * \param[in] rd2 the second one  * \return 0 if equal  * \return -1 if rd1 comes before rd2  * \return +1 if rd2 comes before rd1  */
name|int
name|ldns_rdf_compare
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
comment|/**  * Gets the algorithm value, the HIT and Public Key data from the rdf with  * type LDNS_RDF_TYPE_HIP.  * \param[in] rdf the rdf with type LDNS_RDF_TYPE_HIP  * \param[out] alg      the algorithm  * \param[out] hit_size the size of the HIT data  * \param[out] hit      the hit data  * \param[out] pk_size  the size of the Public Key data  * \param[out] pk       the  Public Key data  * \return LDNS_STATUS_OK on success, and the error otherwise  */
name|ldns_status
name|ldns_rdf_hip_get_alg_hit_pk
parameter_list|(
name|ldns_rdf
modifier|*
name|rdf
parameter_list|,
name|uint8_t
modifier|*
name|alg
parameter_list|,
name|uint8_t
modifier|*
name|hit_size
parameter_list|,
name|uint8_t
modifier|*
modifier|*
name|hit
parameter_list|,
name|uint16_t
modifier|*
name|pk_size
parameter_list|,
name|uint8_t
modifier|*
modifier|*
name|pk
parameter_list|)
function_decl|;
comment|/**  * Creates a new LDNS_RDF_TYPE_HIP rdf from given data.  * \param[out] rdf      the newly created LDNS_RDF_TYPE_HIP rdf  * \param[in]  alg      the algorithm  * \param[in]  hit_size the size of the HIT data  * \param[in]  hit      the hit data  * \param[in]  pk_size  the size of the Public Key data  * \param[in]  pk       the  Public Key data  * \return LDNS_STATUS_OK on success, and the error otherwise  */
name|ldns_status
name|ldns_rdf_hip_new_frm_alg_hit_pk
parameter_list|(
name|ldns_rdf
modifier|*
modifier|*
name|rdf
parameter_list|,
name|uint8_t
name|alg
parameter_list|,
name|uint8_t
name|hit_size
parameter_list|,
name|uint8_t
modifier|*
name|hit
parameter_list|,
name|uint16_t
name|pk_size
parameter_list|,
name|uint8_t
modifier|*
name|pk
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
comment|/* LDNS_RDATA_H */
end_comment

end_unit

