begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/**  * wire2str.h -  txt presentation of RRs  *  * (c) NLnet Labs, 2005-2006  *  * See the file LICENSE for the license  */
end_comment

begin_comment
comment|/**  * \file  *  * Contains functions to translate the wireformat to text  * representation, as well as functions to print them.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|LDNS_WIRE2STR_H
end_ifndef

begin_define
define|#
directive|define
name|LDNS_WIRE2STR_H
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
struct_decl|struct
name|sldns_struct_lookup_table
struct_decl|;
comment|/* lookup tables for standard DNS stuff  */
comment|/** Taken from RFC 2535, section 7.  */
specifier|extern
name|struct
name|sldns_struct_lookup_table
modifier|*
name|sldns_algorithms
decl_stmt|;
comment|/** DS record hash algorithms */
specifier|extern
name|struct
name|sldns_struct_lookup_table
modifier|*
name|sldns_hashes
decl_stmt|;
comment|/** Taken from RFC 2538, section 2.1.  */
specifier|extern
name|struct
name|sldns_struct_lookup_table
modifier|*
name|sldns_cert_algorithms
decl_stmt|;
comment|/** Response codes */
specifier|extern
name|struct
name|sldns_struct_lookup_table
modifier|*
name|sldns_rcodes
decl_stmt|;
comment|/** Operation codes */
specifier|extern
name|struct
name|sldns_struct_lookup_table
modifier|*
name|sldns_opcodes
decl_stmt|;
comment|/** EDNS flags */
specifier|extern
name|struct
name|sldns_struct_lookup_table
modifier|*
name|sldns_edns_flags
decl_stmt|;
comment|/** EDNS option codes */
specifier|extern
name|struct
name|sldns_struct_lookup_table
modifier|*
name|sldns_edns_options
decl_stmt|;
comment|/** error string from wireparse */
specifier|extern
name|struct
name|sldns_struct_lookup_table
modifier|*
name|sldns_wireparse_errors
decl_stmt|;
comment|/**  * Convert wireformat packet to a string representation  * @param data: wireformat packet data (starting at ID bytes).  * @param len: length of packet.  * @return string(malloced) or NULL on failure.  */
name|char
modifier|*
name|sldns_wire2str_pkt
parameter_list|(
name|uint8_t
modifier|*
name|data
parameter_list|,
name|size_t
name|len
parameter_list|)
function_decl|;
comment|/**  * Convert wireformat RR to a string representation.  * @param rr: the wireformat RR, in uncompressed form.  Starts at the domain  * 	name start, ends with the rdata of the RR.  * @param len: length of the rr wireformat.  * @return string(malloced) or NULL on failure.  */
name|char
modifier|*
name|sldns_wire2str_rr
parameter_list|(
name|uint8_t
modifier|*
name|rr
parameter_list|,
name|size_t
name|len
parameter_list|)
function_decl|;
comment|/**  * Conver wire dname to a string.  * @param dname: the dname in uncompressed wireformat.  * @param dname_len: length of the dname.  * @return string or NULL on failure.  */
name|char
modifier|*
name|sldns_wire2str_dname
parameter_list|(
name|uint8_t
modifier|*
name|dname
parameter_list|,
name|size_t
name|dname_len
parameter_list|)
function_decl|;
comment|/**  * Convert wire RR type to a string, 'MX', 'TYPE1234'...  * @param rrtype: the RR type in host order.  * @return malloced string with the RR type or NULL on malloc failure.  */
name|char
modifier|*
name|sldns_wire2str_type
parameter_list|(
name|uint16_t
name|rrtype
parameter_list|)
function_decl|;
comment|/**  * Convert wire RR class to a string, 'IN', 'CLASS1'.  * @param rrclass: the RR class in host order.  * @return malloced string with the RR class or NULL on malloc failure.  */
name|char
modifier|*
name|sldns_wire2str_class
parameter_list|(
name|uint16_t
name|rrclass
parameter_list|)
function_decl|;
comment|/**  * Convert wire packet rcode to a string, 'NOERROR', 'NXDOMAIN'...  * @param rcode: as integer, host order  * @return malloced string with the rcode or NULL on malloc failure.  */
name|char
modifier|*
name|sldns_wire2str_rcode
parameter_list|(
name|int
name|rcode
parameter_list|)
function_decl|;
comment|/**  * Print to string, move string along for next content. With va_list.  * @param str: string buffer.  Adjusted at end to after the output.  * @param slen: length of the string buffer.  Adjusted at end.  * @param format: printf format string.  * @param args: arguments for printf.  * @return number of characters needed. Can be larger than slen.  */
name|int
name|sldns_str_vprint
parameter_list|(
name|char
modifier|*
modifier|*
name|str
parameter_list|,
name|size_t
modifier|*
name|slen
parameter_list|,
specifier|const
name|char
modifier|*
name|format
parameter_list|,
name|va_list
name|args
parameter_list|)
function_decl|;
comment|/**  * Print to string, move string along for next content.  * @param str: string buffer.  Adjusted at end to after the output.  * @param slen: length of the string buffer.  Adjusted at end.  * @param format: printf format string and arguments for it.  * @return number of characters needed. Can be larger than slen.  */
name|int
name|sldns_str_print
parameter_list|(
name|char
modifier|*
modifier|*
name|str
parameter_list|,
name|size_t
modifier|*
name|slen
parameter_list|,
specifier|const
name|char
modifier|*
name|format
parameter_list|,
modifier|...
parameter_list|)
function_decl|ATTR_FORMAT
parameter_list|(
name|printf
parameter_list|,
function_decl|3
operator|,
function_decl|4
block|)
empty_stmt|;
end_extern

begin_comment
comment|/**  * Convert wireformat packet to a string representation with user buffer  * It appends every RR with default comments.  * For more formatter options use the function: TBD(TODO)  * @param data: wireformat packet data (starting at ID bytes).  * @param data_len: length of packet.  * @param str: the string buffer for the output.  * 	If you pass NULL as the str the return value of the function is  * 	the str_len you need for the entire packet.  It does not include  * 	the 0 byte at the end.  * @param str_len: the size of the string buffer.  If more is needed, it'll  * 	silently truncate the output to fit in the buffer.  * @return the number of characters for this element, excluding zerobyte.  * 	Is larger than str_len if output was truncated.  */
end_comment

begin_function_decl
name|int
name|sldns_wire2str_pkt_buf
parameter_list|(
name|uint8_t
modifier|*
name|data
parameter_list|,
name|size_t
name|data_len
parameter_list|,
name|char
modifier|*
name|str
parameter_list|,
name|size_t
name|str_len
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Scan wireformat packet to a string representation with user buffer  * It appends every RR with default comments.  * For more formatter options use the function: TBD(TODO)  * @param data: wireformat packet data (starting at ID bytes).  * @param data_len: length of packet.  * @param str: the string buffer for the output.  * @param str_len: the size of the string buffer.  * @return number of characters for string.  * returns the number of characters that are needed (except terminating null),  * so it may return a value larger than str_len.  * On error you get less output (i.e. shorter output in str (null terminated))  * On exit the data, data_len, str and str_len values are adjusted to move them  * from their original position along the input and output for the content  * that has been consumed (and produced) by this function.  If the end of the  * output string is reached, *str_len is set to 0.  The output string is null  * terminated (shortening the output if necessary).  If the end of the input  * is reached *data_len is set to 0.  */
end_comment

begin_function_decl
name|int
name|sldns_wire2str_pkt_scan
parameter_list|(
name|uint8_t
modifier|*
modifier|*
name|data
parameter_list|,
name|size_t
modifier|*
name|data_len
parameter_list|,
name|char
modifier|*
modifier|*
name|str
parameter_list|,
name|size_t
modifier|*
name|str_len
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Scan wireformat rr to string, with user buffers.  It shifts the arguments  * to move along (see sldns_wire2str_pkt_scan).  * @param data: wireformat data.  * @param data_len: length of data buffer.  * @param str: string buffer.  * @param str_len: length of string buffer.  * @param pkt: packet for decompression, if NULL no decompression.  * @param pktlen: length of packet buffer.  * @return number of characters (except null) needed to print.  */
end_comment

begin_function_decl
name|int
name|sldns_wire2str_rr_scan
parameter_list|(
name|uint8_t
modifier|*
modifier|*
name|data
parameter_list|,
name|size_t
modifier|*
name|data_len
parameter_list|,
name|char
modifier|*
modifier|*
name|str
parameter_list|,
name|size_t
modifier|*
name|str_len
parameter_list|,
name|uint8_t
modifier|*
name|pkt
parameter_list|,
name|size_t
name|pktlen
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Scan wireformat question rr to string, with user buffers.  * It shifts the arguments to move along (see sldns_wire2str_pkt_scan).  * @param data: wireformat data.  * @param data_len: length of data buffer.  * @param str: string buffer.  * @param str_len: length of string buffer.  * @param pkt: packet for decompression, if NULL no decompression.  * @param pktlen: length of packet buffer.  * @return number of characters (except null) needed to print.  */
end_comment

begin_function_decl
name|int
name|sldns_wire2str_rrquestion_scan
parameter_list|(
name|uint8_t
modifier|*
modifier|*
name|data
parameter_list|,
name|size_t
modifier|*
name|data_len
parameter_list|,
name|char
modifier|*
modifier|*
name|str
parameter_list|,
name|size_t
modifier|*
name|str_len
parameter_list|,
name|uint8_t
modifier|*
name|pkt
parameter_list|,
name|size_t
name|pktlen
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Scan wireformat RR to string in unknown RR format, with user buffers.  * It shifts the arguments to move along (see sldns_wire2str_pkt_scan).  * @param data: wireformat data.  * @param data_len: length of data buffer.  * @param str: string buffer.  * @param str_len: length of string buffer.  * @param pkt: packet for decompression, if NULL no decompression.  * @param pktlen: length of packet buffer.  * @return number of characters (except null) needed to print.  */
end_comment

begin_function_decl
name|int
name|sldns_wire2str_rr_unknown_scan
parameter_list|(
name|uint8_t
modifier|*
modifier|*
name|data
parameter_list|,
name|size_t
modifier|*
name|data_len
parameter_list|,
name|char
modifier|*
modifier|*
name|str
parameter_list|,
name|size_t
modifier|*
name|str_len
parameter_list|,
name|uint8_t
modifier|*
name|pkt
parameter_list|,
name|size_t
name|pktlen
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Print to string the RR-information comment in default format,  * with user buffers.  Moves string along.  * @param str: string buffer.  * @param str_len: length of string buffer.  * @param rr: wireformat data.  * @param rrlen: length of data buffer.  * @param dname_off: offset in buffer behind owner dname, the compressed size  * 	of the owner name.  * @param rrtype: type of the RR, host format.  * @return number of characters (except null) needed to print.  */
end_comment

begin_function_decl
name|int
name|sldns_wire2str_rr_comment_print
parameter_list|(
name|char
modifier|*
modifier|*
name|str
parameter_list|,
name|size_t
modifier|*
name|str_len
parameter_list|,
name|uint8_t
modifier|*
name|rr
parameter_list|,
name|size_t
name|rrlen
parameter_list|,
name|size_t
name|dname_off
parameter_list|,
name|uint16_t
name|rrtype
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Scan wireformat packet header to string, with user buffers.  * It shifts the arguments to move along (see sldns_wire2str_pkt_scan).  * @param data: wireformat data.  * @param data_len: length of data buffer.  * @param str: string buffer.  * @param str_len: length of string buffer.  * @return number of characters (except null) needed to print.  */
end_comment

begin_function_decl
name|int
name|sldns_wire2str_header_scan
parameter_list|(
name|uint8_t
modifier|*
modifier|*
name|data
parameter_list|,
name|size_t
modifier|*
name|data_len
parameter_list|,
name|char
modifier|*
modifier|*
name|str
parameter_list|,
name|size_t
modifier|*
name|str_len
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Scan wireformat rdata to string, with user buffers.  * It shifts the arguments to move along (see sldns_wire2str_pkt_scan).  * @param data: wireformat data.  * @param data_len: length of data buffer.  The length of the rdata in the  * 	buffer.  The rdatalen itself has already been scanned, the data  * 	points to the rdata after the rdatalen.  * @param str: string buffer.  * @param str_len: length of string buffer.  * @param rrtype: RR type of Rdata, host format.  * @param pkt: packet for decompression, if NULL no decompression.  * @param pktlen: length of packet buffer.  * @return number of characters (except null) needed to print.  */
end_comment

begin_function_decl
name|int
name|sldns_wire2str_rdata_scan
parameter_list|(
name|uint8_t
modifier|*
modifier|*
name|data
parameter_list|,
name|size_t
modifier|*
name|data_len
parameter_list|,
name|char
modifier|*
modifier|*
name|str
parameter_list|,
name|size_t
modifier|*
name|str_len
parameter_list|,
name|uint16_t
name|rrtype
parameter_list|,
name|uint8_t
modifier|*
name|pkt
parameter_list|,
name|size_t
name|pktlen
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Scan wireformat rdata to string in unknown format, with user buffers.  * It shifts the arguments to move along (see sldns_wire2str_pkt_scan).  * @param data: wireformat data.  * @param data_len: length of data buffer, the length of the rdata in buffer.  * @param str: string buffer.  * @param str_len: length of string buffer.  * @return number of characters (except null) needed to print.  */
end_comment

begin_function_decl
name|int
name|sldns_wire2str_rdata_unknown_scan
parameter_list|(
name|uint8_t
modifier|*
modifier|*
name|data
parameter_list|,
name|size_t
modifier|*
name|data_len
parameter_list|,
name|char
modifier|*
modifier|*
name|str
parameter_list|,
name|size_t
modifier|*
name|str_len
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Scan wireformat domain name to string, with user buffers.  * It shifts the arguments to move along (see sldns_wire2str_pkt_scan).  * @param data: wireformat data.  * @param data_len: length of data buffer.  * @param str: string buffer.  * @param str_len: length of string buffer.  * @param pkt: packet for decompression, if NULL no decompression.  * @param pktlen: length of packet buffer.  * @return number of characters (except null) needed to print.  */
end_comment

begin_function_decl
name|int
name|sldns_wire2str_dname_scan
parameter_list|(
name|uint8_t
modifier|*
modifier|*
name|data
parameter_list|,
name|size_t
modifier|*
name|data_len
parameter_list|,
name|char
modifier|*
modifier|*
name|str
parameter_list|,
name|size_t
modifier|*
name|str_len
parameter_list|,
name|uint8_t
modifier|*
name|pkt
parameter_list|,
name|size_t
name|pktlen
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Scan wireformat rr type to string, with user buffers.  * It shifts the arguments to move along (see sldns_wire2str_pkt_scan).  * @param data: wireformat data.  * @param data_len: length of data buffer.  * @param str: string buffer.  * @param str_len: length of string buffer.  * @return number of characters (except null) needed to print.  */
end_comment

begin_function_decl
name|int
name|sldns_wire2str_type_scan
parameter_list|(
name|uint8_t
modifier|*
modifier|*
name|data
parameter_list|,
name|size_t
modifier|*
name|data_len
parameter_list|,
name|char
modifier|*
modifier|*
name|str
parameter_list|,
name|size_t
modifier|*
name|str_len
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Scan wireformat rr class to string, with user buffers.  * It shifts the arguments to move along (see sldns_wire2str_pkt_scan).  * @param data: wireformat data.  * @param data_len: length of data buffer.  * @param str: string buffer.  * @param str_len: length of string buffer.  * @return number of characters (except null) needed to print.  */
end_comment

begin_function_decl
name|int
name|sldns_wire2str_class_scan
parameter_list|(
name|uint8_t
modifier|*
modifier|*
name|data
parameter_list|,
name|size_t
modifier|*
name|data_len
parameter_list|,
name|char
modifier|*
modifier|*
name|str
parameter_list|,
name|size_t
modifier|*
name|str_len
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Scan wireformat rr ttl to string, with user buffers.  * It shifts the arguments to move along (see sldns_wire2str_pkt_scan).  * @param data: wireformat data.  * @param data_len: length of data buffer.  * @param str: string buffer.  * @param str_len: length of string buffer.  * @return number of characters (except null) needed to print.  */
end_comment

begin_function_decl
name|int
name|sldns_wire2str_ttl_scan
parameter_list|(
name|uint8_t
modifier|*
modifier|*
name|data
parameter_list|,
name|size_t
modifier|*
name|data_len
parameter_list|,
name|char
modifier|*
modifier|*
name|str
parameter_list|,
name|size_t
modifier|*
name|str_len
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Print host format rr type to string.  Moves string along, user buffers.  * @param str: string buffer.  * @param str_len: length of string buffer.  * @param rrtype: host format rr type.  * @return number of characters (except null) needed to print.  */
end_comment

begin_function_decl
name|int
name|sldns_wire2str_type_print
parameter_list|(
name|char
modifier|*
modifier|*
name|str
parameter_list|,
name|size_t
modifier|*
name|str_len
parameter_list|,
name|uint16_t
name|rrtype
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Print host format rr class to string.  Moves string along, user buffers.  * @param str: string buffer.  * @param str_len: length of string buffer.  * @param rrclass: host format rr class.  * @return number of characters (except null) needed to print.  */
end_comment

begin_function_decl
name|int
name|sldns_wire2str_class_print
parameter_list|(
name|char
modifier|*
modifier|*
name|str
parameter_list|,
name|size_t
modifier|*
name|str_len
parameter_list|,
name|uint16_t
name|rrclass
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Print host format rcode to string.  Moves string along, user buffers.  * @param str: string buffer.  * @param str_len: length of string buffer.  * @param rcode: host format rcode number.  * @return number of characters (except null) needed to print.  */
end_comment

begin_function_decl
name|int
name|sldns_wire2str_rcode_print
parameter_list|(
name|char
modifier|*
modifier|*
name|str
parameter_list|,
name|size_t
modifier|*
name|str_len
parameter_list|,
name|int
name|rcode
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Print host format opcode to string.  Moves string along, user buffers.  * @param str: string buffer.  * @param str_len: length of string buffer.  * @param opcode: host format opcode number.  * @return number of characters (except null) needed to print.  */
end_comment

begin_function_decl
name|int
name|sldns_wire2str_opcode_print
parameter_list|(
name|char
modifier|*
modifier|*
name|str
parameter_list|,
name|size_t
modifier|*
name|str_len
parameter_list|,
name|int
name|opcode
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Print host format EDNS0 option to string.  Moves string along, user buffers.  * @param str: string buffer.  * @param str_len: length of string buffer.  * @param opcode: host format option number.  * @return number of characters (except null) needed to print.  */
end_comment

begin_function_decl
name|int
name|sldns_wire2str_edns_option_code_print
parameter_list|(
name|char
modifier|*
modifier|*
name|str
parameter_list|,
name|size_t
modifier|*
name|str_len
parameter_list|,
name|uint16_t
name|opcode
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Convert RR to string presentation format, on one line.  User buffer.  * @param rr: wireformat RR data  * @param rr_len: length of the rr wire data.  * @param str: the string buffer to write to.  * 	If you pass NULL as the str, the return value of the function is  * 	the str_len you need for the entire packet.  It does not include  * 	the 0 byte at the end.  * @param str_len: the size of the string buffer.  If more is needed, it'll  * 	silently truncate the output to fit in the buffer.  * @return the number of characters for this element, excluding zerobyte.  * 	Is larger than str_len if output was truncated.  */
end_comment

begin_function_decl
name|int
name|sldns_wire2str_rr_buf
parameter_list|(
name|uint8_t
modifier|*
name|rr
parameter_list|,
name|size_t
name|rr_len
parameter_list|,
name|char
modifier|*
name|str
parameter_list|,
name|size_t
name|str_len
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * 3597 printout of an RR in unknown rr format.  * There are more format and comment options available for printout  * with the function: TBD(TODO)  * @param rr: wireformat RR data  * @param rr_len: length of the rr wire data.  * @param str: the string buffer to write to.  * 	If you pass NULL as the str, the return value of the function is  * 	the str_len you need for the entire rr.  It does not include  * 	the 0 byte at the end.  * @param str_len: the size of the string buffer.  If more is needed, it'll  * 	silently truncate the output to fit in the buffer.  * @return the number of characters for this element, excluding zerobyte.  * 	Is larger than str_len if output was truncated.  */
end_comment

begin_function_decl
name|int
name|sldns_wire2str_rr_unknown_buf
parameter_list|(
name|uint8_t
modifier|*
name|rr
parameter_list|,
name|size_t
name|rr_len
parameter_list|,
name|char
modifier|*
name|str
parameter_list|,
name|size_t
name|str_len
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * This creates the comment to print after the RR. ; keytag=... , and other  * basic comments for RRs.  * There are more format and comment options available for printout  * with the function: TBD(TODO)  * @param rr: wireformat RR data  * @param rr_len: length of the rr wire data.  * @param dname_len: length of the dname in front of the RR.  * @param str: the string buffer to write to.  * 	If you pass NULL as the str, the return value of the function is  * 	the str_len you need for the entire comment.  It does not include  * 	the 0 byte at the end.  * @param str_len: the size of the string buffer.  If more is needed, it'll  * 	silently truncate the output to fit in the buffer.  * @return the number of characters for this element, excluding zerobyte.  * 	Is larger than str_len if output was truncated.  */
end_comment

begin_function_decl
name|int
name|sldns_wire2str_rr_comment_buf
parameter_list|(
name|uint8_t
modifier|*
name|rr
parameter_list|,
name|size_t
name|rr_len
parameter_list|,
name|size_t
name|dname_len
parameter_list|,
name|char
modifier|*
name|str
parameter_list|,
name|size_t
name|str_len
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Convert RDATA to string presentation format, on one line.  User buffer.  * @param rdata: wireformat rdata part of an RR.  * @param rdata_len: length of the rr wire data.  * @param str: the string buffer to write to.  * 	If you pass NULL as the str, the return value of the function is  * 	the str_len you need for the entire packet.  It does not include  * 	the 0 byte at the end.  * @param str_len: the size of the string buffer.  If more is needed, it'll  * 	silently truncate the output to fit in the buffer.  * @param rrtype: rr type of the data  * @return the number of characters for this element, excluding zerobyte.  * 	Is larger than str_len if output was truncated.  */
end_comment

begin_function_decl
name|int
name|sldns_wire2str_rdata_buf
parameter_list|(
name|uint8_t
modifier|*
name|rdata
parameter_list|,
name|size_t
name|rdata_len
parameter_list|,
name|char
modifier|*
name|str
parameter_list|,
name|size_t
name|str_len
parameter_list|,
name|uint16_t
name|rrtype
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Convert wire RR type to a string, 'MX', 'TYPE12'.  With user buffer.  * @param rrtype: the RR type in host order.  * @param str: the string to write to.  * @param len: length of str.  * @return the number of characters for this element, excluding zerobyte.  * 	Is larger than str_len if output was truncated.  */
end_comment

begin_function_decl
name|int
name|sldns_wire2str_type_buf
parameter_list|(
name|uint16_t
name|rrtype
parameter_list|,
name|char
modifier|*
name|str
parameter_list|,
name|size_t
name|len
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Convert wire RR class to a string, 'IN', 'CLASS12'.  With user buffer.  * @param rrclass: the RR class in host order.  * @param str: the string to write to.  * @param len: length of str.  * @return the number of characters for this element, excluding zerobyte.  * 	Is larger than str_len if output was truncated.  */
end_comment

begin_function_decl
name|int
name|sldns_wire2str_class_buf
parameter_list|(
name|uint16_t
name|rrclass
parameter_list|,
name|char
modifier|*
name|str
parameter_list|,
name|size_t
name|len
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Convert wire RR rcode to a string, 'NOERROR', 'NXDOMAIN'.  With user buffer.  * @param rcode: rcode as integer in host order  * @param str: the string to write to.  * @param len: length of str.  * @return the number of characters for this element, excluding zerobyte.  * 	Is larger than str_len if output was truncated.  */
end_comment

begin_function_decl
name|int
name|sldns_wire2str_rcode_buf
parameter_list|(
name|int
name|rcode
parameter_list|,
name|char
modifier|*
name|str
parameter_list|,
name|size_t
name|len
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Convert wire dname to a string, "example.com.".  With user buffer.  * @param dname: the dname in uncompressed wireformat.  * @param dname_len: length of the dname.  * @param str: the string to write to.  * @param len: length of string.  * @return the number of characters for this element, excluding zerobyte.  * 	Is larger than str_len if output was truncated.  */
end_comment

begin_function_decl
name|int
name|sldns_wire2str_dname_buf
parameter_list|(
name|uint8_t
modifier|*
name|dname
parameter_list|,
name|size_t
name|dname_len
parameter_list|,
name|char
modifier|*
name|str
parameter_list|,
name|size_t
name|len
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Scan wireformat rdf field to string, with user buffers.  * It shifts the arguments to move along (see sldns_wire2str_pkt_scan).  * @param data: wireformat data.  * @param data_len: length of data buffer.  * @param str: string buffer.  * @param str_len: length of string buffer.  * @param rdftype: the type of the rdata field, enum sldns_rdf_type.  * @param pkt: packet for decompression, if NULL no decompression.  * @param pktlen: length of packet buffer.  * @return number of characters (except null) needed to print.  * 	Can return -1 on failure.  */
end_comment

begin_function_decl
name|int
name|sldns_wire2str_rdf_scan
parameter_list|(
name|uint8_t
modifier|*
modifier|*
name|data
parameter_list|,
name|size_t
modifier|*
name|data_len
parameter_list|,
name|char
modifier|*
modifier|*
name|str
parameter_list|,
name|size_t
modifier|*
name|str_len
parameter_list|,
name|int
name|rdftype
parameter_list|,
name|uint8_t
modifier|*
name|pkt
parameter_list|,
name|size_t
name|pktlen
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Scan wireformat int8 field to string, with user buffers.  * It shifts the arguments to move along (see sldns_wire2str_pkt_scan).  * @param data: wireformat data.  * @param data_len: length of data buffer.  * @param str: string buffer.  * @param str_len: length of string buffer.  * @return number of characters (except null) needed to print.  * 	Can return -1 on failure.  */
end_comment

begin_function_decl
name|int
name|sldns_wire2str_int8_scan
parameter_list|(
name|uint8_t
modifier|*
modifier|*
name|data
parameter_list|,
name|size_t
modifier|*
name|data_len
parameter_list|,
name|char
modifier|*
modifier|*
name|str
parameter_list|,
name|size_t
modifier|*
name|str_len
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Scan wireformat int16 field to string, with user buffers.  * It shifts the arguments to move along (see sldns_wire2str_pkt_scan).  * @param data: wireformat data.  * @param data_len: length of data buffer.  * @param str: string buffer.  * @param str_len: length of string buffer.  * @return number of characters (except null) needed to print.  * 	Can return -1 on failure.  */
end_comment

begin_function_decl
name|int
name|sldns_wire2str_int16_scan
parameter_list|(
name|uint8_t
modifier|*
modifier|*
name|data
parameter_list|,
name|size_t
modifier|*
name|data_len
parameter_list|,
name|char
modifier|*
modifier|*
name|str
parameter_list|,
name|size_t
modifier|*
name|str_len
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Scan wireformat int32 field to string, with user buffers.  * It shifts the arguments to move along (see sldns_wire2str_pkt_scan).  * @param data: wireformat data.  * @param data_len: length of data buffer.  * @param str: string buffer.  * @param str_len: length of string buffer.  * @return number of characters (except null) needed to print.  * 	Can return -1 on failure.  */
end_comment

begin_function_decl
name|int
name|sldns_wire2str_int32_scan
parameter_list|(
name|uint8_t
modifier|*
modifier|*
name|data
parameter_list|,
name|size_t
modifier|*
name|data_len
parameter_list|,
name|char
modifier|*
modifier|*
name|str
parameter_list|,
name|size_t
modifier|*
name|str_len
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Scan wireformat period field to string, with user buffers.  * It shifts the arguments to move along (see sldns_wire2str_pkt_scan).  * @param data: wireformat data.  * @param data_len: length of data buffer.  * @param str: string buffer.  * @param str_len: length of string buffer.  * @return number of characters (except null) needed to print.  * 	Can return -1 on failure.  */
end_comment

begin_function_decl
name|int
name|sldns_wire2str_period_scan
parameter_list|(
name|uint8_t
modifier|*
modifier|*
name|data
parameter_list|,
name|size_t
modifier|*
name|data_len
parameter_list|,
name|char
modifier|*
modifier|*
name|str
parameter_list|,
name|size_t
modifier|*
name|str_len
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Scan wireformat tsigtime field to string, with user buffers.  * It shifts the arguments to move along (see sldns_wire2str_pkt_scan).  * @param data: wireformat data.  * @param data_len: length of data buffer.  * @param str: string buffer.  * @param str_len: length of string buffer.  * @return number of characters (except null) needed to print.  * 	Can return -1 on failure.  */
end_comment

begin_function_decl
name|int
name|sldns_wire2str_tsigtime_scan
parameter_list|(
name|uint8_t
modifier|*
modifier|*
name|data
parameter_list|,
name|size_t
modifier|*
name|data_len
parameter_list|,
name|char
modifier|*
modifier|*
name|str
parameter_list|,
name|size_t
modifier|*
name|str_len
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Scan wireformat ip4 A field to string, with user buffers.  * It shifts the arguments to move along (see sldns_wire2str_pkt_scan).  * @param data: wireformat data.  * @param data_len: length of data buffer.  * @param str: string buffer.  * @param str_len: length of string buffer.  * @return number of characters (except null) needed to print.  * 	Can return -1 on failure.  */
end_comment

begin_function_decl
name|int
name|sldns_wire2str_a_scan
parameter_list|(
name|uint8_t
modifier|*
modifier|*
name|data
parameter_list|,
name|size_t
modifier|*
name|data_len
parameter_list|,
name|char
modifier|*
modifier|*
name|str
parameter_list|,
name|size_t
modifier|*
name|str_len
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Scan wireformat ip6 AAAA field to string, with user buffers.  * It shifts the arguments to move along (see sldns_wire2str_pkt_scan).  * @param data: wireformat data.  * @param data_len: length of data buffer.  * @param str: string buffer.  * @param str_len: length of string buffer.  * @return number of characters (except null) needed to print.  * 	Can return -1 on failure.  */
end_comment

begin_function_decl
name|int
name|sldns_wire2str_aaaa_scan
parameter_list|(
name|uint8_t
modifier|*
modifier|*
name|data
parameter_list|,
name|size_t
modifier|*
name|data_len
parameter_list|,
name|char
modifier|*
modifier|*
name|str
parameter_list|,
name|size_t
modifier|*
name|str_len
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Scan wireformat str field to string, with user buffers.  * It shifts the arguments to move along (see sldns_wire2str_pkt_scan).  * @param data: wireformat data.  * @param data_len: length of data buffer.  * @param str: string buffer.  * @param str_len: length of string buffer.  * @return number of characters (except null) needed to print.  * 	Can return -1 on failure.  */
end_comment

begin_function_decl
name|int
name|sldns_wire2str_str_scan
parameter_list|(
name|uint8_t
modifier|*
modifier|*
name|data
parameter_list|,
name|size_t
modifier|*
name|data_len
parameter_list|,
name|char
modifier|*
modifier|*
name|str
parameter_list|,
name|size_t
modifier|*
name|str_len
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Scan wireformat apl field to string, with user buffers.  * It shifts the arguments to move along (see sldns_wire2str_pkt_scan).  * @param data: wireformat data.  * @param data_len: length of data buffer.  * @param str: string buffer.  * @param str_len: length of string buffer.  * @return number of characters (except null) needed to print.  * 	Can return -1 on failure.  */
end_comment

begin_function_decl
name|int
name|sldns_wire2str_apl_scan
parameter_list|(
name|uint8_t
modifier|*
modifier|*
name|data
parameter_list|,
name|size_t
modifier|*
name|data_len
parameter_list|,
name|char
modifier|*
modifier|*
name|str
parameter_list|,
name|size_t
modifier|*
name|str_len
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Scan wireformat b32_ext field to string, with user buffers.  * It shifts the arguments to move along (see sldns_wire2str_pkt_scan).  * @param data: wireformat data.  * @param data_len: length of data buffer.  * @param str: string buffer.  * @param str_len: length of string buffer.  * @return number of characters (except null) needed to print.  * 	Can return -1 on failure.  */
end_comment

begin_function_decl
name|int
name|sldns_wire2str_b32_ext_scan
parameter_list|(
name|uint8_t
modifier|*
modifier|*
name|data
parameter_list|,
name|size_t
modifier|*
name|data_len
parameter_list|,
name|char
modifier|*
modifier|*
name|str
parameter_list|,
name|size_t
modifier|*
name|str_len
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Scan wireformat b64 field to string, with user buffers.  * It shifts the arguments to move along (see sldns_wire2str_pkt_scan).  * @param data: wireformat data.  * @param data_len: length of data buffer.  * @param str: string buffer.  * @param str_len: length of string buffer.  * @return number of characters (except null) needed to print.  * 	Can return -1 on failure.  */
end_comment

begin_function_decl
name|int
name|sldns_wire2str_b64_scan
parameter_list|(
name|uint8_t
modifier|*
modifier|*
name|data
parameter_list|,
name|size_t
modifier|*
name|data_len
parameter_list|,
name|char
modifier|*
modifier|*
name|str
parameter_list|,
name|size_t
modifier|*
name|str_len
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Scan wireformat hex field to string, with user buffers.  * It shifts the arguments to move along (see sldns_wire2str_pkt_scan).  * @param data: wireformat data.  * @param data_len: length of data buffer.  * @param str: string buffer.  * @param str_len: length of string buffer.  * @return number of characters (except null) needed to print.  * 	Can return -1 on failure.  */
end_comment

begin_function_decl
name|int
name|sldns_wire2str_hex_scan
parameter_list|(
name|uint8_t
modifier|*
modifier|*
name|data
parameter_list|,
name|size_t
modifier|*
name|data_len
parameter_list|,
name|char
modifier|*
modifier|*
name|str
parameter_list|,
name|size_t
modifier|*
name|str_len
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Scan wireformat nsec bitmap field to string, with user buffers.  * It shifts the arguments to move along (see sldns_wire2str_pkt_scan).  * @param data: wireformat data.  * @param data_len: length of data buffer.  * @param str: string buffer.  * @param str_len: length of string buffer.  * @return number of characters (except null) needed to print.  * 	Can return -1 on failure.  */
end_comment

begin_function_decl
name|int
name|sldns_wire2str_nsec_scan
parameter_list|(
name|uint8_t
modifier|*
modifier|*
name|data
parameter_list|,
name|size_t
modifier|*
name|data_len
parameter_list|,
name|char
modifier|*
modifier|*
name|str
parameter_list|,
name|size_t
modifier|*
name|str_len
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Scan wireformat nsec3_salt field to string, with user buffers.  * It shifts the arguments to move along (see sldns_wire2str_pkt_scan).  * @param data: wireformat data.  * @param data_len: length of data buffer.  * @param str: string buffer.  * @param str_len: length of string buffer.  * @return number of characters (except null) needed to print.  * 	Can return -1 on failure.  */
end_comment

begin_function_decl
name|int
name|sldns_wire2str_nsec3_salt_scan
parameter_list|(
name|uint8_t
modifier|*
modifier|*
name|data
parameter_list|,
name|size_t
modifier|*
name|data_len
parameter_list|,
name|char
modifier|*
modifier|*
name|str
parameter_list|,
name|size_t
modifier|*
name|str_len
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Scan wireformat cert_alg field to string, with user buffers.  * It shifts the arguments to move along (see sldns_wire2str_pkt_scan).  * @param data: wireformat data.  * @param data_len: length of data buffer.  * @param str: string buffer.  * @param str_len: length of string buffer.  * @return number of characters (except null) needed to print.  * 	Can return -1 on failure.  */
end_comment

begin_function_decl
name|int
name|sldns_wire2str_cert_alg_scan
parameter_list|(
name|uint8_t
modifier|*
modifier|*
name|data
parameter_list|,
name|size_t
modifier|*
name|data_len
parameter_list|,
name|char
modifier|*
modifier|*
name|str
parameter_list|,
name|size_t
modifier|*
name|str_len
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Scan wireformat alg field to string, with user buffers.  * It shifts the arguments to move along (see sldns_wire2str_pkt_scan).  * @param data: wireformat data.  * @param data_len: length of data buffer.  * @param str: string buffer.  * @param str_len: length of string buffer.  * @return number of characters (except null) needed to print.  * 	Can return -1 on failure.  */
end_comment

begin_function_decl
name|int
name|sldns_wire2str_alg_scan
parameter_list|(
name|uint8_t
modifier|*
modifier|*
name|data
parameter_list|,
name|size_t
modifier|*
name|data_len
parameter_list|,
name|char
modifier|*
modifier|*
name|str
parameter_list|,
name|size_t
modifier|*
name|str_len
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Scan wireformat type unknown field to string, with user buffers.  * It shifts the arguments to move along (see sldns_wire2str_pkt_scan).  * @param data: wireformat data.  * @param data_len: length of data buffer.  * @param str: string buffer.  * @param str_len: length of string buffer.  * @return number of characters (except null) needed to print.  * 	Can return -1 on failure.  */
end_comment

begin_function_decl
name|int
name|sldns_wire2str_unknown_scan
parameter_list|(
name|uint8_t
modifier|*
modifier|*
name|data
parameter_list|,
name|size_t
modifier|*
name|data_len
parameter_list|,
name|char
modifier|*
modifier|*
name|str
parameter_list|,
name|size_t
modifier|*
name|str_len
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Scan wireformat time field to string, with user buffers.  * It shifts the arguments to move along (see sldns_wire2str_pkt_scan).  * @param data: wireformat data.  * @param data_len: length of data buffer.  * @param str: string buffer.  * @param str_len: length of string buffer.  * @return number of characters (except null) needed to print.  * 	Can return -1 on failure.  */
end_comment

begin_function_decl
name|int
name|sldns_wire2str_time_scan
parameter_list|(
name|uint8_t
modifier|*
modifier|*
name|data
parameter_list|,
name|size_t
modifier|*
name|data_len
parameter_list|,
name|char
modifier|*
modifier|*
name|str
parameter_list|,
name|size_t
modifier|*
name|str_len
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Scan wireformat LOC field to string, with user buffers.  * It shifts the arguments to move along (see sldns_wire2str_pkt_scan).  * @param data: wireformat data.  * @param data_len: length of data buffer.  * @param str: string buffer.  * @param str_len: length of string buffer.  * @return number of characters (except null) needed to print.  * 	Can return -1 on failure.  */
end_comment

begin_function_decl
name|int
name|sldns_wire2str_loc_scan
parameter_list|(
name|uint8_t
modifier|*
modifier|*
name|data
parameter_list|,
name|size_t
modifier|*
name|data_len
parameter_list|,
name|char
modifier|*
modifier|*
name|str
parameter_list|,
name|size_t
modifier|*
name|str_len
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Scan wireformat WKS field to string, with user buffers.  * It shifts the arguments to move along (see sldns_wire2str_pkt_scan).  * @param data: wireformat data.  * @param data_len: length of data buffer.  * @param str: string buffer.  * @param str_len: length of string buffer.  * @return number of characters (except null) needed to print.  * 	Can return -1 on failure.  */
end_comment

begin_function_decl
name|int
name|sldns_wire2str_wks_scan
parameter_list|(
name|uint8_t
modifier|*
modifier|*
name|data
parameter_list|,
name|size_t
modifier|*
name|data_len
parameter_list|,
name|char
modifier|*
modifier|*
name|str
parameter_list|,
name|size_t
modifier|*
name|str_len
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Scan wireformat NSAP field to string, with user buffers.  * It shifts the arguments to move along (see sldns_wire2str_pkt_scan).  * @param data: wireformat data.  * @param data_len: length of data buffer.  * @param str: string buffer.  * @param str_len: length of string buffer.  * @return number of characters (except null) needed to print.  * 	Can return -1 on failure.  */
end_comment

begin_function_decl
name|int
name|sldns_wire2str_nsap_scan
parameter_list|(
name|uint8_t
modifier|*
modifier|*
name|data
parameter_list|,
name|size_t
modifier|*
name|data_len
parameter_list|,
name|char
modifier|*
modifier|*
name|str
parameter_list|,
name|size_t
modifier|*
name|str_len
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Scan wireformat ATMA field to string, with user buffers.  * It shifts the arguments to move along (see sldns_wire2str_pkt_scan).  * @param data: wireformat data.  * @param data_len: length of data buffer.  * @param str: string buffer.  * @param str_len: length of string buffer.  * @return number of characters (except null) needed to print.  * 	Can return -1 on failure.  */
end_comment

begin_function_decl
name|int
name|sldns_wire2str_atma_scan
parameter_list|(
name|uint8_t
modifier|*
modifier|*
name|data
parameter_list|,
name|size_t
modifier|*
name|data_len
parameter_list|,
name|char
modifier|*
modifier|*
name|str
parameter_list|,
name|size_t
modifier|*
name|str_len
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Scan wireformat IPSECKEY field to string, with user buffers.  * It shifts the arguments to move along (see sldns_wire2str_pkt_scan).  * @param data: wireformat data.  * @param data_len: length of data buffer.  * @param str: string buffer.  * @param str_len: length of string buffer.  * @param pkt: packet for decompression, if NULL no decompression.  * @param pktlen: length of packet buffer.  * @return number of characters (except null) needed to print.  * 	Can return -1 on failure.  */
end_comment

begin_function_decl
name|int
name|sldns_wire2str_ipseckey_scan
parameter_list|(
name|uint8_t
modifier|*
modifier|*
name|data
parameter_list|,
name|size_t
modifier|*
name|data_len
parameter_list|,
name|char
modifier|*
modifier|*
name|str
parameter_list|,
name|size_t
modifier|*
name|str_len
parameter_list|,
name|uint8_t
modifier|*
name|pkt
parameter_list|,
name|size_t
name|pktlen
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Scan wireformat HIP (algo, HIT, pubkey) field to string, with user buffers.  * It shifts the arguments to move along (see sldns_wire2str_pkt_scan).  * @param data: wireformat data.  * @param data_len: length of data buffer.  * @param str: string buffer.  * @param str_len: length of string buffer.  * @return number of characters (except null) needed to print.  * 	Can return -1 on failure.  */
end_comment

begin_function_decl
name|int
name|sldns_wire2str_hip_scan
parameter_list|(
name|uint8_t
modifier|*
modifier|*
name|data
parameter_list|,
name|size_t
modifier|*
name|data_len
parameter_list|,
name|char
modifier|*
modifier|*
name|str
parameter_list|,
name|size_t
modifier|*
name|str_len
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Scan wireformat int16_data field to string, with user buffers.  * It shifts the arguments to move along (see sldns_wire2str_pkt_scan).  * @param data: wireformat data.  * @param data_len: length of data buffer.  * @param str: string buffer.  * @param str_len: length of string buffer.  * @return number of characters (except null) needed to print.  * 	Can return -1 on failure.  */
end_comment

begin_function_decl
name|int
name|sldns_wire2str_int16_data_scan
parameter_list|(
name|uint8_t
modifier|*
modifier|*
name|data
parameter_list|,
name|size_t
modifier|*
name|data_len
parameter_list|,
name|char
modifier|*
modifier|*
name|str
parameter_list|,
name|size_t
modifier|*
name|str_len
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Scan wireformat nsec3_next_owner field to string, with user buffers.  * It shifts the arguments to move along (see sldns_wire2str_pkt_scan).  * @param data: wireformat data.  * @param data_len: length of data buffer.  * @param str: string buffer.  * @param str_len: length of string buffer.  * @return number of characters (except null) needed to print.  * 	Can return -1 on failure.  */
end_comment

begin_function_decl
name|int
name|sldns_wire2str_nsec3_next_owner_scan
parameter_list|(
name|uint8_t
modifier|*
modifier|*
name|data
parameter_list|,
name|size_t
modifier|*
name|data_len
parameter_list|,
name|char
modifier|*
modifier|*
name|str
parameter_list|,
name|size_t
modifier|*
name|str_len
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Scan wireformat ILNP64 field to string, with user buffers.  * It shifts the arguments to move along (see sldns_wire2str_pkt_scan).  * @param data: wireformat data.  * @param data_len: length of data buffer.  * @param str: string buffer.  * @param str_len: length of string buffer.  * @return number of characters (except null) needed to print.  * 	Can return -1 on failure.  */
end_comment

begin_function_decl
name|int
name|sldns_wire2str_ilnp64_scan
parameter_list|(
name|uint8_t
modifier|*
modifier|*
name|data
parameter_list|,
name|size_t
modifier|*
name|data_len
parameter_list|,
name|char
modifier|*
modifier|*
name|str
parameter_list|,
name|size_t
modifier|*
name|str_len
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Scan wireformat EUI48 field to string, with user buffers.  * It shifts the arguments to move along (see sldns_wire2str_pkt_scan).  * @param data: wireformat data.  * @param data_len: length of data buffer.  * @param str: string buffer.  * @param str_len: length of string buffer.  * @return number of characters (except null) needed to print.  * 	Can return -1 on failure.  */
end_comment

begin_function_decl
name|int
name|sldns_wire2str_eui48_scan
parameter_list|(
name|uint8_t
modifier|*
modifier|*
name|data
parameter_list|,
name|size_t
modifier|*
name|data_len
parameter_list|,
name|char
modifier|*
modifier|*
name|str
parameter_list|,
name|size_t
modifier|*
name|str_len
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Scan wireformat EUI64 field to string, with user buffers.  * It shifts the arguments to move along (see sldns_wire2str_pkt_scan).  * @param data: wireformat data.  * @param data_len: length of data buffer.  * @param str: string buffer.  * @param str_len: length of string buffer.  * @return number of characters (except null) needed to print.  * 	Can return -1 on failure.  */
end_comment

begin_function_decl
name|int
name|sldns_wire2str_eui64_scan
parameter_list|(
name|uint8_t
modifier|*
modifier|*
name|data
parameter_list|,
name|size_t
modifier|*
name|data_len
parameter_list|,
name|char
modifier|*
modifier|*
name|str
parameter_list|,
name|size_t
modifier|*
name|str_len
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Scan wireformat TAG field to string, with user buffers.  * It shifts the arguments to move along (see sldns_wire2str_pkt_scan).  * @param data: wireformat data.  * @param data_len: length of data buffer.  * @param str: string buffer.  * @param str_len: length of string buffer.  * @return number of characters (except null) needed to print.  * 	Can return -1 on failure.  */
end_comment

begin_function_decl
name|int
name|sldns_wire2str_tag_scan
parameter_list|(
name|uint8_t
modifier|*
modifier|*
name|data
parameter_list|,
name|size_t
modifier|*
name|data_len
parameter_list|,
name|char
modifier|*
modifier|*
name|str
parameter_list|,
name|size_t
modifier|*
name|str_len
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Scan wireformat long_str field to string, with user buffers.  * It shifts the arguments to move along (see sldns_wire2str_pkt_scan).  * @param data: wireformat data.  * @param data_len: length of data buffer.  * @param str: string buffer.  * @param str_len: length of string buffer.  * @return number of characters (except null) needed to print.  * 	Can return -1 on failure.  */
end_comment

begin_function_decl
name|int
name|sldns_wire2str_long_str_scan
parameter_list|(
name|uint8_t
modifier|*
modifier|*
name|data
parameter_list|,
name|size_t
modifier|*
name|data_len
parameter_list|,
name|char
modifier|*
modifier|*
name|str
parameter_list|,
name|size_t
modifier|*
name|str_len
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Print EDNS LLQ option data to string.  User buffers, moves string pointers.  * @param str: string buffer.  * @param str_len: length of string buffer.  * @param option_data: buffer with EDNS option code data.  * @param option_len: length of the data for this option.  * @return number of characters (except null) needed to print.  */
end_comment

begin_function_decl
name|int
name|sldns_wire2str_edns_llq_print
parameter_list|(
name|char
modifier|*
modifier|*
name|str
parameter_list|,
name|size_t
modifier|*
name|str_len
parameter_list|,
name|uint8_t
modifier|*
name|option_data
parameter_list|,
name|size_t
name|option_len
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Print EDNS UL option data to string.  User buffers, moves string pointers.  * @param str: string buffer.  * @param str_len: length of string buffer.  * @param option_data: buffer with EDNS option code data.  * @param option_len: length of the data for this option.  * @return number of characters (except null) needed to print.  */
end_comment

begin_function_decl
name|int
name|sldns_wire2str_edns_ul_print
parameter_list|(
name|char
modifier|*
modifier|*
name|str
parameter_list|,
name|size_t
modifier|*
name|str_len
parameter_list|,
name|uint8_t
modifier|*
name|option_data
parameter_list|,
name|size_t
name|option_len
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Print EDNS NSID option data to string.  User buffers, moves string pointers.  * @param str: string buffer.  * @param str_len: length of string buffer.  * @param option_data: buffer with EDNS option code data.  * @param option_len: length of the data for this option.  * @return number of characters (except null) needed to print.  */
end_comment

begin_function_decl
name|int
name|sldns_wire2str_edns_nsid_print
parameter_list|(
name|char
modifier|*
modifier|*
name|str
parameter_list|,
name|size_t
modifier|*
name|str_len
parameter_list|,
name|uint8_t
modifier|*
name|option_data
parameter_list|,
name|size_t
name|option_len
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Print EDNS DAU option data to string.  User buffers, moves string pointers.  * @param str: string buffer.  * @param str_len: length of string buffer.  * @param option_data: buffer with EDNS option code data.  * @param option_len: length of the data for this option.  * @return number of characters (except null) needed to print.  */
end_comment

begin_function_decl
name|int
name|sldns_wire2str_edns_dau_print
parameter_list|(
name|char
modifier|*
modifier|*
name|str
parameter_list|,
name|size_t
modifier|*
name|str_len
parameter_list|,
name|uint8_t
modifier|*
name|option_data
parameter_list|,
name|size_t
name|option_len
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Print EDNS DHU option data to string.  User buffers, moves string pointers.  * @param str: string buffer.  * @param str_len: length of string buffer.  * @param option_data: buffer with EDNS option code data.  * @param option_len: length of the data for this option.  * @return number of characters (except null) needed to print.  */
end_comment

begin_function_decl
name|int
name|sldns_wire2str_edns_dhu_print
parameter_list|(
name|char
modifier|*
modifier|*
name|str
parameter_list|,
name|size_t
modifier|*
name|str_len
parameter_list|,
name|uint8_t
modifier|*
name|option_data
parameter_list|,
name|size_t
name|option_len
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Print EDNS N3U option data to string.  User buffers, moves string pointers.  * @param str: string buffer.  * @param str_len: length of string buffer.  * @param option_data: buffer with EDNS option code data.  * @param option_len: length of the data for this option.  * @return number of characters (except null) needed to print.  */
end_comment

begin_function_decl
name|int
name|sldns_wire2str_edns_n3u_print
parameter_list|(
name|char
modifier|*
modifier|*
name|str
parameter_list|,
name|size_t
modifier|*
name|str_len
parameter_list|,
name|uint8_t
modifier|*
name|option_data
parameter_list|,
name|size_t
name|option_len
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Print EDNS SUBNET option data to string. User buffers, moves string pointers.  * @param str: string buffer.  * @param str_len: length of string buffer.  * @param option_data: buffer with EDNS option code data.  * @param option_len: length of the data for this option.  * @return number of characters (except null) needed to print.  */
end_comment

begin_function_decl
name|int
name|sldns_wire2str_edns_subnet_print
parameter_list|(
name|char
modifier|*
modifier|*
name|str
parameter_list|,
name|size_t
modifier|*
name|str_len
parameter_list|,
name|uint8_t
modifier|*
name|option_data
parameter_list|,
name|size_t
name|option_len
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Print an EDNS option as OPT: VALUE.  User buffers, moves string pointers.  * @param str: string buffer.  * @param str_len: length of string buffer.  * @param option_code: host format EDNS option code.  * @param option_data: buffer with EDNS option code data.  * @param option_len: length of the data for this option.  * @return number of characters (except null) needed to print.  */
end_comment

begin_function_decl
name|int
name|sldns_wire2str_edns_option_print
parameter_list|(
name|char
modifier|*
modifier|*
name|str
parameter_list|,
name|size_t
modifier|*
name|str_len
parameter_list|,
name|uint16_t
name|option_code
parameter_list|,
name|uint8_t
modifier|*
name|option_data
parameter_list|,
name|size_t
name|option_len
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Scan wireformat EDNS OPT to string, with user buffers.  * It shifts the arguments to move along (see sldns_wire2str_pkt_scan).  * @param data: wireformat data.  * @param data_len: length of data buffer.  * @param str: string buffer.  * @param str_len: length of string buffer.  * @param pkt: packet with header and other info (may be NULL)  * @param pktlen: length of packet buffer.  * @return number of characters (except null) needed to print.  */
end_comment

begin_function_decl
name|int
name|sldns_wire2str_edns_scan
parameter_list|(
name|uint8_t
modifier|*
modifier|*
name|data
parameter_list|,
name|size_t
modifier|*
name|data_len
parameter_list|,
name|char
modifier|*
modifier|*
name|str
parameter_list|,
name|size_t
modifier|*
name|str_len
parameter_list|,
name|uint8_t
modifier|*
name|pkt
parameter_list|,
name|size_t
name|pktlen
parameter_list|)
function_decl|;
end_function_decl

begin_ifdef
ifdef|#
directive|ifdef
name|__cplusplus
end_ifdef

begin_endif
unit|}
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* LDNS_WIRE2STR_H */
end_comment

end_unit

