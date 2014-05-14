begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * ldns-testpkts. Data file parse for test packets, and query matching.  *  * Data storage for specially crafted replies for testing purposes.  *  * (c) NLnet Labs, 2005, 2006, 2007  * See the file LICENSE for the license  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|LDNS_TESTPKTS_H
end_ifndef

begin_define
define|#
directive|define
name|LDNS_TESTPKTS_H
end_define

begin_comment
comment|/**  * \file  *   * This is a debugging aid. It is not efficient, especially  * with a long config file, but it can give any reply to any query.  * This can help the developer pre-script replies for queries.  *  * You can specify a packet RR by RR with header flags to return.  *  * Missing features:  *		- matching content different from reply content.  *		- find way to adjust mangled packets?  *  */
end_comment

begin_comment
comment|/* 	The data file format is as follows: 	 	; comment. 	; a number of entries, these are processed first to last. 	; a line based format.  	$ORIGIN origin 	$TTL default_ttl  	ENTRY_BEGIN 	; first give MATCH lines, that say what queries are matched 	; by this entry. 	; 'opcode' makes the query match the opcode from the reply 	; if you leave it out, any opcode matches this entry. 	; 'qtype' makes the query match the qtype from the reply 	; 'qname' makes the query match the qname from the reply 	; 'subdomain' makes the query match subdomains of qname from the reply 	; 'serial=1023' makes the query match if ixfr serial is 1023.  	; 'all' has to match header byte for byte and all rrs in packet. 	; 'ttl' used with all, rrs in packet must also have matching TTLs. 	; 'DO' will match only queries with DO bit set. 	; 'noedns' matches queries without EDNS OPT records. 	; 'ednsdata' matches queries to HEX_EDNS section. 	MATCH [opcode] [qtype] [qname] [serial=<value>] [all] [ttl] 	MATCH [UDP|TCP] DO 	MATCH ... 	; Then the REPLY header is specified. 	REPLY opcode, rcode or flags. 		(opcode)  QUERY IQUERY STATUS NOTIFY UPDATE 		(rcode)   NOERROR FORMERR SERVFAIL NXDOMAIN NOTIMPL YXDOMAIN 		 		YXRRSET NXRRSET NOTAUTH NOTZONE 		(flags)   QR AA TC RD CD RA AD DO 	REPLY ... 	; any additional actions to do. 	; 'copy_id' copies the ID from the query to the answer. 	ADJUST copy_id 	; 'copy_query' copies the query name, type and class to the answer. 	ADJUST copy_query 	; 'sleep=10' sleeps for 10 seconds before giving the answer (TCP is open) 	ADJUST [sleep=<num>]    ; sleep before giving any reply 	ADJUST [packet_sleep=<num>]  ; sleep before this packet in sequence 	SECTION QUESTION<RRs, one per line>    ; the RRcount is determined automatically. 	SECTION ANSWER<RRs, one per line> 	SECTION AUTHORITY<RRs, one per line> 	SECTION ADDITIONAL<RRs, one per line> 	EXTRA_PACKET		; follow with SECTION, REPLY for more packets. 	HEX_ANSWER_BEGIN	; follow with hex data 				; this replaces any answer packet constructed 				; with the SECTION keywords (only SECTION QUERY 				; is used to match queries). If the data cannot 				; be parsed, ADJUST rules for the answer packet 				; are ignored. Only copy_id is done. 	HEX_ANSWER_END 	HEX_EDNS_BEGIN	; follow with hex data. 					; Raw EDNS data to match against. It must be an  					; exact match (all options are matched) and will be  					; evaluated only when 'MATCH ednsdata' given. 	HEX_EDNS_END 	ENTRY_END    	Example data file: $ORIGIN nlnetlabs.nl $TTL 3600  ENTRY_BEGIN MATCH qname REPLY NOERROR ADJUST copy_id SECTION QUESTION www.nlnetlabs.nl.	IN	A SECTION ANSWER www.nlnetlabs.nl.	IN	A	195.169.215.155 SECTION AUTHORITY nlnetlabs.nl.		IN	NS	www.nlnetlabs.nl. ENTRY_END  ENTRY_BEGIN MATCH qname REPLY NOERROR ADJUST copy_id SECTION QUESTION www2.nlnetlabs.nl.	IN	A HEX_ANSWER_BEGIN ; 0  1  2  3  4  5  6  7  8  9 10 11 12 13 14 15 16 17 18 19 ;-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --  00 bf 81 80 00 01 00 01 00 02 00 02 03 77 77 77 0b 6b 61 6e	;	   1-  20  61 72 69 65 70 69 65 74 03 63 6f 6d 00 00 01 00 01 03 77 77	;	  21-  40  77 0b 6b 61 6e 61 72 69 65 70 69 65 74 03 63 6f 6d 00 00 01	;	  41-  60  00 01 00 01 50 8b 00 04 52 5e ed 32 0b 6b 61 6e 61 72 69 65	;	  61-  80  70 69 65 74 03 63 6f 6d 00 00 02 00 01 00 01 50 8b 00 11 03	;	  81- 100  6e 73 31 08 68 65 78 6f 6e 2d 69 73 02 6e 6c 00 0b 6b 61 6e	;	 101- 120  61 72 69 65 70 69 65 74 03 63 6f 6d 00 00 02 00 01 00 01 50	;	 121- 140  8b 00 11 03 6e 73 32 08 68 65 78 6f 6e 2d 69 73 02 6e 6c 00	;	 141- 160  03 6e 73 31 08 68 65 78 6f 6e 2d 69 73 02 6e 6c 00 00 01 00	;	 161- 180  01 00 00 46 53 00 04 52 5e ed 02 03 6e 73 32 08 68 65 78 6f	;	 181- 200  6e 2d 69 73 02 6e 6c 00 00 01 00 01 00 00 46 53 00 04 d4 cc	;	 201- 220  db 5b HEX_ANSWER_END ENTRY_END       note that this file will link with your    void verbose(int level, char* format, ...); output function. */
end_comment

begin_include
include|#
directive|include
file|<ldns/ldns.h>
end_include

begin_comment
comment|/** Type of transport, since some entries match based on UDP or TCP of query */
end_comment

begin_enum
enum|enum
name|transport_type
block|{
name|transport_any
init|=
literal|0
block|,
name|transport_udp
block|,
name|transport_tcp
block|}
enum|;
end_enum

begin_comment
comment|/** struct to keep a linked list of reply packets for a query */
end_comment

begin_struct
struct|struct
name|reply_packet
block|{
comment|/** next in list of reply packets, for TCP multiple pkts on wire */
name|struct
name|reply_packet
modifier|*
name|next
decl_stmt|;
comment|/** the reply pkt */
name|ldns_pkt
modifier|*
name|reply
decl_stmt|;
comment|/** Additional EDNS data for matching queries. */
name|ldns_buffer
modifier|*
name|raw_ednsdata
decl_stmt|;
comment|/** or reply pkt in hex if not parsable */
name|ldns_buffer
modifier|*
name|reply_from_hex
decl_stmt|;
comment|/** seconds to sleep before giving packet */
name|unsigned
name|int
name|packet_sleep
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/** data structure to keep the canned queries in.    format is the 'matching query' and the 'canned answer' */
end_comment

begin_struct
struct|struct
name|entry
block|{
comment|/* match */
comment|/* How to match an incoming query with this canned reply */
comment|/** match query opcode with answer opcode */
name|bool
name|match_opcode
decl_stmt|;
comment|/** match qtype with answer qtype */
name|bool
name|match_qtype
decl_stmt|;
comment|/** match qname with answer qname */
name|bool
name|match_qname
decl_stmt|;
comment|/** match qname as subdomain of answer qname */
name|bool
name|match_subdomain
decl_stmt|;
comment|/** match SOA serial number, from auth section */
name|bool
name|match_serial
decl_stmt|;
comment|/** match all of the packet */
name|bool
name|match_all
decl_stmt|;
comment|/** match ttls in the packet */
name|bool
name|match_ttl
decl_stmt|;
comment|/** match DO bit */
name|bool
name|match_do
decl_stmt|;
comment|/** match absence of EDNS OPT record in query */
name|bool
name|match_noedns
decl_stmt|;
comment|/** match edns data field given in hex */
name|bool
name|match_ednsdata_raw
decl_stmt|;
comment|/** match query serial with this value. */
name|uint32_t
name|ixfr_soa_serial
decl_stmt|;
comment|/** match on UDP/TCP */
name|enum
name|transport_type
name|match_transport
decl_stmt|;
comment|/** pre canned reply */
name|struct
name|reply_packet
modifier|*
name|reply_list
decl_stmt|;
comment|/** how to adjust the reply packet */
comment|/** copy over the ID from the query into the answer */
name|bool
name|copy_id
decl_stmt|;
comment|/** copy the query nametypeclass from query into the answer */
name|bool
name|copy_query
decl_stmt|;
comment|/** in seconds */
name|unsigned
name|int
name|sleeptime
decl_stmt|;
comment|/** some number that names this entry, line number in file or so */
name|int
name|lineno
decl_stmt|;
comment|/** next in list */
name|struct
name|entry
modifier|*
name|next
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/**  * reads the canned reply file and returns a list of structs   * does an exit on error.  * @param name: name of the file to read.  * @param skip_whitespace: skip leftside whitespace.  */
end_comment

begin_function_decl
name|struct
name|entry
modifier|*
name|read_datafile
parameter_list|(
specifier|const
name|char
modifier|*
name|name
parameter_list|,
name|int
name|skip_whitespace
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Delete linked list of entries.  */
end_comment

begin_function_decl
name|void
name|delete_entry
parameter_list|(
name|struct
name|entry
modifier|*
name|list
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Read one entry from the data file.  * @param in: file to read from. Filepos must be at the start of a new line.  * @param name: name of the file for prettier errors.  * @param lineno: line number in file, incremented as lines are read.  *	for prettier errors.  * @param default_ttl: on first call set to default TTL for entries,  *	later it stores the $TTL value last seen. Try 3600 first call.  * @param origin: domain name for origin appending. Can be&NULL on first call.  *	later it stores the $ORIGIN value last seen. Often&NULL or the zone  *	name on first call.  * @param prev_rr: previous rr name for correcter parsing.&NULL on first call.  * @param skip_whitespace: skip leftside whitespace.  * @return: The entry read (malloced) or NULL if no entry could be read.  */
end_comment

begin_function_decl
name|struct
name|entry
modifier|*
name|read_entry
parameter_list|(
name|FILE
modifier|*
name|in
parameter_list|,
specifier|const
name|char
modifier|*
name|name
parameter_list|,
name|int
modifier|*
name|lineno
parameter_list|,
name|uint32_t
modifier|*
name|default_ttl
parameter_list|,
name|ldns_rdf
modifier|*
modifier|*
name|origin
parameter_list|,
name|ldns_rdf
modifier|*
modifier|*
name|prev_rr
parameter_list|,
name|int
name|skip_whitespace
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * finds entry in list, or returns NULL.  */
end_comment

begin_function_decl
name|struct
name|entry
modifier|*
name|find_match
parameter_list|(
name|struct
name|entry
modifier|*
name|entries
parameter_list|,
name|ldns_pkt
modifier|*
name|query_pkt
parameter_list|,
name|enum
name|transport_type
name|transport
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * copy& adjust packet   */
end_comment

begin_function_decl
name|void
name|adjust_packet
parameter_list|(
name|struct
name|entry
modifier|*
name|match
parameter_list|,
name|ldns_pkt
modifier|*
name|answer_pkt
parameter_list|,
name|ldns_pkt
modifier|*
name|query_pkt
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Parses data buffer to a query, finds the correct answer   * and calls the given function for every packet to send.  * if verbose_out filename is given, packets are dumped there.  * @param inbuf: the packet that came in  * @param inlen: length of packet.  * @param entries: entries read in from datafile.  * @param count: is increased to count number of queries answered.  * @param transport: set to UDP or TCP to match some types of entries.  * @param sendfunc: called to send answer (buffer, size, userarg).  * @param userdata: userarg to give to sendfunc.  * @param verbose_out: if not NULL, verbose messages are printed there.  */
end_comment

begin_function_decl
name|void
name|handle_query
parameter_list|(
name|uint8_t
modifier|*
name|inbuf
parameter_list|,
name|ssize_t
name|inlen
parameter_list|,
name|struct
name|entry
modifier|*
name|entries
parameter_list|,
name|int
modifier|*
name|count
parameter_list|,
name|enum
name|transport_type
name|transport
parameter_list|,
name|void
function_decl|(
modifier|*
name|sendfunc
function_decl|)
parameter_list|(
name|uint8_t
modifier|*
parameter_list|,
name|size_t
parameter_list|,
name|void
modifier|*
parameter_list|)
parameter_list|,
name|void
modifier|*
name|userdata
parameter_list|,
name|FILE
modifier|*
name|verbose_out
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* LDNS_TESTPKTS_H */
end_comment

end_unit

