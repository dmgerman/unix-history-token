begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * parseutil.h - parse utilities for string and wire conversion  *  * (c) NLnet Labs, 2004  *  * See the file LICENSE for the license  */
end_comment

begin_comment
comment|/**  * \file  *  * Utility functions for parsing, base32(DNS variant) and base64 encoding  * and decoding, Hex, Time units, Escape codes.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|LDNS_PARSEUTIL_H
end_ifndef

begin_define
define|#
directive|define
name|LDNS_PARSEUTIL_H
end_define

begin_struct_decl
struct_decl|struct
name|tm
struct_decl|;
end_struct_decl

begin_comment
comment|/**   *  A general purpose lookup table  *    *  Lookup tables are arrays of (id, name) pairs,  *  So you can for instance lookup the RCODE 3, which is "NXDOMAIN",  *  and vice versa. The lookup tables themselves are defined wherever needed,  *  for instance in host2str.c  */
end_comment

begin_struct
struct|struct
name|sldns_struct_lookup_table
block|{
name|int
name|id
decl_stmt|;
specifier|const
name|char
modifier|*
name|name
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|sldns_struct_lookup_table
name|sldns_lookup_table
typedef|;
end_typedef

begin_comment
comment|/**  * Looks up the table entry by name, returns NULL if not found.  * \param[in] table the lookup table to search in  * \param[in] name what to search for  * \return the item found  */
end_comment

begin_function_decl
name|sldns_lookup_table
modifier|*
name|sldns_lookup_by_name
parameter_list|(
name|sldns_lookup_table
name|table
index|[]
parameter_list|,
specifier|const
name|char
modifier|*
name|name
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Looks up the table entry by id, returns NULL if not found.  * \param[in] table the lookup table to search in  * \param[in] id what to search for  * \return the item found  */
end_comment

begin_function_decl
name|sldns_lookup_table
modifier|*
name|sldns_lookup_by_id
parameter_list|(
name|sldns_lookup_table
name|table
index|[]
parameter_list|,
name|int
name|id
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Convert TM to seconds since epoch (midnight, January 1st, 1970).  * Like timegm(3), which is not always available.  * \param[in] tm a struct tm* with the date  * \return the seconds since epoch  */
end_comment

begin_function_decl
name|time_t
name|sldns_mktime_from_utc
parameter_list|(
specifier|const
name|struct
name|tm
modifier|*
name|tm
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * The function interprets time as the number of seconds since epoch  * with respect to now using serial arithmitics (rfc1982).  * That number of seconds is then converted to broken-out time information.  * This is especially usefull when converting the inception and expiration  * fields of RRSIG records.  *  * \param[in] time number of seconds since epoch (midnight, January 1st, 1970)  *            to be intepreted as a serial arithmitics number relative to now.  * \param[in] now number of seconds since epoch (midnight, January 1st, 1970)  *            to which the time value is compared to determine the final value.  * \param[out] result the struct with the broken-out time information  * \return result on success or NULL on error  */
end_comment

begin_function_decl
name|struct
name|tm
modifier|*
name|sldns_serial_arithmitics_gmtime_r
parameter_list|(
name|int32_t
name|time
parameter_list|,
name|time_t
name|now
parameter_list|,
name|struct
name|tm
modifier|*
name|result
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * converts a ttl value (like 5d2h) to a long.  * \param[in] nptr the start of the string  * \param[out] endptr points to the last char in case of error  * \return the convert duration value  */
end_comment

begin_function_decl
name|uint32_t
name|sldns_str2period
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
end_function_decl

begin_comment
comment|/**  * Returns the int value of the given (hex) digit  * \param[in] ch the hex char to convert  * \return the converted decimal value  */
end_comment

begin_function_decl
name|int
name|sldns_hexdigit_to_int
parameter_list|(
name|char
name|ch
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * calculates the size needed to store the result of b64_ntop  */
end_comment

begin_function_decl
name|size_t
name|sldns_b64_ntop_calculate_size
parameter_list|(
name|size_t
name|srcsize
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|sldns_b64_ntop
parameter_list|(
name|uint8_t
specifier|const
modifier|*
name|src
parameter_list|,
name|size_t
name|srclength
parameter_list|,
name|char
modifier|*
name|target
parameter_list|,
name|size_t
name|targsize
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * calculates the size needed to store the result of sldns_b64_pton  */
end_comment

begin_function_decl
name|size_t
name|sldns_b64_pton_calculate_size
parameter_list|(
name|size_t
name|srcsize
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|sldns_b64_pton
parameter_list|(
name|char
specifier|const
modifier|*
name|src
parameter_list|,
name|uint8_t
modifier|*
name|target
parameter_list|,
name|size_t
name|targsize
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * calculates the size needed to store the result of b32_ntop  */
end_comment

begin_function_decl
name|size_t
name|sldns_b32_ntop_calculate_size
parameter_list|(
name|size_t
name|src_data_length
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|size_t
name|sldns_b32_ntop_calculate_size_no_padding
parameter_list|(
name|size_t
name|src_data_length
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|sldns_b32_ntop
parameter_list|(
specifier|const
name|uint8_t
modifier|*
name|src_data
parameter_list|,
name|size_t
name|src_data_length
parameter_list|,
name|char
modifier|*
name|target_text_buffer
parameter_list|,
name|size_t
name|target_text_buffer_size
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|sldns_b32_ntop_extended_hex
parameter_list|(
specifier|const
name|uint8_t
modifier|*
name|src_data
parameter_list|,
name|size_t
name|src_data_length
parameter_list|,
name|char
modifier|*
name|target_text_buffer
parameter_list|,
name|size_t
name|target_text_buffer_size
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * calculates the size needed to store the result of b32_pton  */
end_comment

begin_function_decl
name|size_t
name|sldns_b32_pton_calculate_size
parameter_list|(
name|size_t
name|src_text_length
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|sldns_b32_pton
parameter_list|(
specifier|const
name|char
modifier|*
name|src_text
parameter_list|,
name|size_t
name|src_text_length
parameter_list|,
name|uint8_t
modifier|*
name|target_data_buffer
parameter_list|,
name|size_t
name|target_data_buffer_size
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|sldns_b32_pton_extended_hex
parameter_list|(
specifier|const
name|char
modifier|*
name|src_text
parameter_list|,
name|size_t
name|src_text_length
parameter_list|,
name|uint8_t
modifier|*
name|target_data_buffer
parameter_list|,
name|size_t
name|target_data_buffer_size
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Checks whether the escaped value at **s is an octal value or  * a 'normally' escaped character (and not eos)  *  * @param ch_p: the parsed character  * @param str_p: the string. moved along for characters read.  * The string pointer at *s is increased by either 0 (on error), 1 (on  * normal escapes), or 3 (on octals)  *  * @return 0 on error  */
end_comment

begin_function_decl
name|int
name|sldns_parse_escape
parameter_list|(
name|uint8_t
modifier|*
name|ch_p
parameter_list|,
specifier|const
name|char
modifier|*
modifier|*
name|str_p
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   * Parse one character, with escape codes,  * @param ch_p: the parsed character  * @param str_p: the string. moved along for characters read.  * @return 0 on error  */
end_comment

begin_function_decl
name|int
name|sldns_parse_char
parameter_list|(
name|uint8_t
modifier|*
name|ch_p
parameter_list|,
specifier|const
name|char
modifier|*
modifier|*
name|str_p
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* LDNS_PARSEUTIL_H */
end_comment

end_unit

