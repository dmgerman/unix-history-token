begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (C) 2004, 2006  Internet Systems Consortium, Inc. ("ISC")  * Copyright (C) 1999-2003  Internet Software Consortium.  *  * Permission to use, copy, modify, and distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND ISC DISCLAIMS ALL WARRANTIES WITH  * REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY  * AND FITNESS.  IN NO EVENT SHALL ISC BE LIABLE FOR ANY SPECIAL, DIRECT,  * INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM  * LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE  * OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR  * PERFORMANCE OF THIS SOFTWARE.  */
end_comment

begin_comment
comment|/* $Id: message.h,v 1.100.2.3.8.10 2006/02/28 06:32:54 marka Exp $ */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|DNS_MESSAGE_H
end_ifndef

begin_define
define|#
directive|define
name|DNS_MESSAGE_H
value|1
end_define

begin_comment
comment|/***  ***	Imports  ***/
end_comment

begin_include
include|#
directive|include
file|<isc/lang.h>
end_include

begin_include
include|#
directive|include
file|<isc/magic.h>
end_include

begin_include
include|#
directive|include
file|<dns/compress.h>
end_include

begin_include
include|#
directive|include
file|<dns/masterdump.h>
end_include

begin_include
include|#
directive|include
file|<dns/types.h>
end_include

begin_include
include|#
directive|include
file|<dst/dst.h>
end_include

begin_comment
comment|/*  * How this beast works:  *  * When a dns message is received in a buffer, dns_message_fromwire() is called  * on the memory region.  Various items are checked including the format  * of the message (if counts are right, if counts consume the entire sections,  * and if sections consume the entire message) and known pseudo-RRs in the  * additional data section are analyzed and removed.  *  * TSIG checking is also done at this layer, and any DNSSEC transaction  * signatures should also be checked here.  *  * Notes on using the gettemp*() and puttemp*() functions:  *  * These functions return items (names, rdatasets, etc) allocated from some  * internal state of the dns_message_t.  *  * Names and rdatasets must be put back into the dns_message_t in  * one of two ways.  Assume a name was allocated via  * dns_message_gettempname():  *  *	(1) insert it into a section, using dns_message_addname().  *  *	(2) return it to the message using dns_message_puttempname().  *  * The same applies to rdatasets.  *  * On the other hand, offsets, rdatalists and rdatas allocated using  * dns_message_gettemp*() will always be freed automatically  * when the message is reset or destroyed; calling dns_message_puttemp*()  * on rdatalists and rdatas is optional and serves only to enable the item  * to be reused multiple times during the lifetime of the message; offsets  * cannot be reused.  *  * Buffers allocated using isc_buffer_allocate() can be automatically freed  * as well by giving the buffer to the message using dns_message_takebuffer().  * Doing this will cause the buffer to be freed using isc_buffer_free()  * when the section lists are cleared, such as in a reset or in a destroy.  * Since the buffer itself exists until the message is destroyed, this sort  * of code can be written:  *  *	buffer = isc_buffer_allocate(mctx, 512);  *	name = NULL;  *	name = dns_message_gettempname(message,&name);  *	dns_name_init(name, NULL);  *	result = dns_name_fromtext(name,&source, dns_rootname, ISC_FALSE,  *				   buffer);  *	dns_message_takebuffer(message,&buffer);  *  *  * TODO:  *  * XXX Needed:  ways to set and retrieve EDNS information, add rdata to a  * section, move rdata from one section to another, remove rdata, etc.  */
end_comment

begin_define
define|#
directive|define
name|DNS_MESSAGEFLAG_QR
value|0x8000U
end_define

begin_define
define|#
directive|define
name|DNS_MESSAGEFLAG_AA
value|0x0400U
end_define

begin_define
define|#
directive|define
name|DNS_MESSAGEFLAG_TC
value|0x0200U
end_define

begin_define
define|#
directive|define
name|DNS_MESSAGEFLAG_RD
value|0x0100U
end_define

begin_define
define|#
directive|define
name|DNS_MESSAGEFLAG_RA
value|0x0080U
end_define

begin_define
define|#
directive|define
name|DNS_MESSAGEFLAG_AD
value|0x0020U
end_define

begin_define
define|#
directive|define
name|DNS_MESSAGEFLAG_CD
value|0x0010U
end_define

begin_define
define|#
directive|define
name|DNS_MESSAGEEXTFLAG_DO
value|0x8000U
end_define

begin_define
define|#
directive|define
name|DNS_MESSAGE_REPLYPRESERVE
value|(DNS_MESSAGEFLAG_RD|DNS_MESSAGEFLAG_CD)
end_define

begin_define
define|#
directive|define
name|DNS_MESSAGEEXTFLAG_REPLYPRESERVE
value|(DNS_MESSAGEEXTFLAG_DO)
end_define

begin_define
define|#
directive|define
name|DNS_MESSAGE_HEADERLEN
value|12
end_define

begin_comment
comment|/* 6 isc_uint16_t's */
end_comment

begin_define
define|#
directive|define
name|DNS_MESSAGE_MAGIC
value|ISC_MAGIC('M','S','G','@')
end_define

begin_define
define|#
directive|define
name|DNS_MESSAGE_VALID
parameter_list|(
name|msg
parameter_list|)
value|ISC_MAGIC_VALID(msg, DNS_MESSAGE_MAGIC)
end_define

begin_comment
comment|/*  * Ordering here matters.  DNS_SECTION_ANY must be the lowest and negative,  * and DNS_SECTION_MAX must be one greater than the last used section.  */
end_comment

begin_typedef
typedef|typedef
name|int
name|dns_section_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|DNS_SECTION_ANY
value|(-1)
end_define

begin_define
define|#
directive|define
name|DNS_SECTION_QUESTION
value|0
end_define

begin_define
define|#
directive|define
name|DNS_SECTION_ANSWER
value|1
end_define

begin_define
define|#
directive|define
name|DNS_SECTION_AUTHORITY
value|2
end_define

begin_define
define|#
directive|define
name|DNS_SECTION_ADDITIONAL
value|3
end_define

begin_define
define|#
directive|define
name|DNS_SECTION_MAX
value|4
end_define

begin_typedef
typedef|typedef
name|int
name|dns_pseudosection_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|DNS_PSEUDOSECTION_ANY
value|(-1)
end_define

begin_define
define|#
directive|define
name|DNS_PSEUDOSECTION_OPT
value|0
end_define

begin_define
define|#
directive|define
name|DNS_PSEUDOSECTION_TSIG
value|1
end_define

begin_define
define|#
directive|define
name|DNS_PSEUDOSECTION_SIG0
value|2
end_define

begin_define
define|#
directive|define
name|DNS_PSEUDOSECTION_MAX
value|3
end_define

begin_typedef
typedef|typedef
name|int
name|dns_messagetextflag_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|DNS_MESSAGETEXTFLAG_NOCOMMENTS
value|0x0001
end_define

begin_define
define|#
directive|define
name|DNS_MESSAGETEXTFLAG_NOHEADERS
value|0x0002
end_define

begin_comment
comment|/*  * Dynamic update names for these sections.  */
end_comment

begin_define
define|#
directive|define
name|DNS_SECTION_ZONE
value|DNS_SECTION_QUESTION
end_define

begin_define
define|#
directive|define
name|DNS_SECTION_PREREQUISITE
value|DNS_SECTION_ANSWER
end_define

begin_define
define|#
directive|define
name|DNS_SECTION_UPDATE
value|DNS_SECTION_AUTHORITY
end_define

begin_comment
comment|/*  * These tell the message library how the created dns_message_t will be used.  */
end_comment

begin_define
define|#
directive|define
name|DNS_MESSAGE_INTENTUNKNOWN
value|0
end_define

begin_comment
comment|/* internal use only */
end_comment

begin_define
define|#
directive|define
name|DNS_MESSAGE_INTENTPARSE
value|1
end_define

begin_comment
comment|/* parsing messages */
end_comment

begin_define
define|#
directive|define
name|DNS_MESSAGE_INTENTRENDER
value|2
end_define

begin_comment
comment|/* rendering */
end_comment

begin_comment
comment|/*  * Control behavior of parsing  */
end_comment

begin_define
define|#
directive|define
name|DNS_MESSAGEPARSE_PRESERVEORDER
value|0x0001
end_define

begin_comment
comment|/* preserve rdata order */
end_comment

begin_define
define|#
directive|define
name|DNS_MESSAGEPARSE_BESTEFFORT
value|0x0002
end_define

begin_comment
comment|/* return a message if a 						   recoverable parse error 						   occurs */
end_comment

begin_define
define|#
directive|define
name|DNS_MESSAGEPARSE_CLONEBUFFER
value|0x0004
end_define

begin_comment
comment|/* save a copy of the 						   source buffer */
end_comment

begin_define
define|#
directive|define
name|DNS_MESSAGEPARSE_IGNORETRUNCATION
value|0x0008
end_define

begin_comment
comment|/* trucation errors are 						  * not fatal. */
end_comment

begin_comment
comment|/*  * Control behavior of rendering  */
end_comment

begin_define
define|#
directive|define
name|DNS_MESSAGERENDER_ORDERED
value|0x0001
end_define

begin_comment
comment|/* don't change order */
end_comment

begin_define
define|#
directive|define
name|DNS_MESSAGERENDER_PARTIAL
value|0x0002
end_define

begin_comment
comment|/* allow a partial rdataset */
end_comment

begin_define
define|#
directive|define
name|DNS_MESSAGERENDER_OMITDNSSEC
value|0x0004
end_define

begin_comment
comment|/* omit DNSSEC records */
end_comment

begin_define
define|#
directive|define
name|DNS_MESSAGERENDER_PREFER_A
value|0x0008
end_define

begin_comment
comment|/* prefer A records in 						 * additional section. */
end_comment

begin_define
define|#
directive|define
name|DNS_MESSAGERENDER_PREFER_AAAA
value|0x0010
end_define

begin_comment
comment|/* prefer AAAA records in 						 * additional section. */
end_comment

begin_typedef
typedef|typedef
name|struct
name|dns_msgblock
name|dns_msgblock_t
typedef|;
end_typedef

begin_struct
struct|struct
name|dns_message
block|{
comment|/* public from here down */
name|unsigned
name|int
name|magic
decl_stmt|;
name|dns_messageid_t
name|id
decl_stmt|;
name|unsigned
name|int
name|flags
decl_stmt|;
name|dns_rcode_t
name|rcode
decl_stmt|;
name|unsigned
name|int
name|opcode
decl_stmt|;
name|dns_rdataclass_t
name|rdclass
decl_stmt|;
comment|/* 4 real, 1 pseudo */
name|unsigned
name|int
name|counts
index|[
name|DNS_SECTION_MAX
index|]
decl_stmt|;
comment|/* private from here down */
name|dns_namelist_t
name|sections
index|[
name|DNS_SECTION_MAX
index|]
decl_stmt|;
name|dns_name_t
modifier|*
name|cursors
index|[
name|DNS_SECTION_MAX
index|]
decl_stmt|;
name|dns_rdataset_t
modifier|*
name|opt
decl_stmt|;
name|dns_rdataset_t
modifier|*
name|sig0
decl_stmt|;
name|dns_rdataset_t
modifier|*
name|tsig
decl_stmt|;
name|int
name|state
decl_stmt|;
name|unsigned
name|int
name|from_to_wire
range|:
literal|2
decl_stmt|;
name|unsigned
name|int
name|header_ok
range|:
literal|1
decl_stmt|;
name|unsigned
name|int
name|question_ok
range|:
literal|1
decl_stmt|;
name|unsigned
name|int
name|tcp_continuation
range|:
literal|1
decl_stmt|;
name|unsigned
name|int
name|verified_sig
range|:
literal|1
decl_stmt|;
name|unsigned
name|int
name|verify_attempted
range|:
literal|1
decl_stmt|;
name|unsigned
name|int
name|free_query
range|:
literal|1
decl_stmt|;
name|unsigned
name|int
name|free_saved
range|:
literal|1
decl_stmt|;
name|unsigned
name|int
name|opt_reserved
decl_stmt|;
name|unsigned
name|int
name|sig_reserved
decl_stmt|;
name|unsigned
name|int
name|reserved
decl_stmt|;
comment|/* reserved space (render) */
name|isc_buffer_t
modifier|*
name|buffer
decl_stmt|;
name|dns_compress_t
modifier|*
name|cctx
decl_stmt|;
name|isc_mem_t
modifier|*
name|mctx
decl_stmt|;
name|isc_mempool_t
modifier|*
name|namepool
decl_stmt|;
name|isc_mempool_t
modifier|*
name|rdspool
decl_stmt|;
name|isc_bufferlist_t
name|scratchpad
decl_stmt|;
name|isc_bufferlist_t
name|cleanup
decl_stmt|;
name|ISC_LIST
argument_list|(
argument|dns_msgblock_t
argument_list|)
name|rdatas
expr_stmt|;
name|ISC_LIST
argument_list|(
argument|dns_msgblock_t
argument_list|)
name|rdatalists
expr_stmt|;
name|ISC_LIST
argument_list|(
argument|dns_msgblock_t
argument_list|)
name|offsets
expr_stmt|;
name|ISC_LIST
argument_list|(
argument|dns_rdata_t
argument_list|)
name|freerdata
expr_stmt|;
name|ISC_LIST
argument_list|(
argument|dns_rdatalist_t
argument_list|)
name|freerdatalist
expr_stmt|;
name|dns_rcode_t
name|tsigstatus
decl_stmt|;
name|dns_rcode_t
name|querytsigstatus
decl_stmt|;
name|dns_name_t
modifier|*
name|tsigname
decl_stmt|;
comment|/* Owner name of TSIG, if any */
name|dns_rdataset_t
modifier|*
name|querytsig
decl_stmt|;
name|dns_tsigkey_t
modifier|*
name|tsigkey
decl_stmt|;
name|dst_context_t
modifier|*
name|tsigctx
decl_stmt|;
name|int
name|sigstart
decl_stmt|;
name|int
name|timeadjust
decl_stmt|;
name|dns_name_t
modifier|*
name|sig0name
decl_stmt|;
comment|/* Owner name of SIG0, if any */
name|dst_key_t
modifier|*
name|sig0key
decl_stmt|;
name|dns_rcode_t
name|sig0status
decl_stmt|;
name|isc_region_t
name|query
decl_stmt|;
name|isc_region_t
name|saved
decl_stmt|;
name|dns_rdatasetorderfunc_t
name|order
decl_stmt|;
specifier|const
name|void
modifier|*
name|order_arg
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/***  *** Functions  ***/
end_comment

begin_function_decl
name|ISC_LANG_BEGINDECLS
name|isc_result_t
name|dns_message_create
parameter_list|(
name|isc_mem_t
modifier|*
name|mctx
parameter_list|,
name|unsigned
name|int
name|intent
parameter_list|,
name|dns_message_t
modifier|*
modifier|*
name|msgp
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Create msg structure.  *  * This function will allocate some internal blocks of memory that are  * expected to be needed for parsing or rendering nearly any type of message.  *  * Requires:  *	'mctx' be a valid memory context.  *  *	'msgp' be non-null and '*msg' be NULL.  *  *	'intent' must be one of DNS_MESSAGE_INTENTPARSE or  *	DNS_MESSAGE_INTENTRENDER.  *  * Ensures:  *	The data in "*msg" is set to indicate an unused and empty msg  *	structure.  *  * Returns:  *	ISC_R_NOMEMORY		-- out of memory  *	ISC_R_SUCCESS		-- success  */
end_comment

begin_function_decl
name|void
name|dns_message_reset
parameter_list|(
name|dns_message_t
modifier|*
name|msg
parameter_list|,
name|unsigned
name|int
name|intent
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Reset a message structure to default state.  All internal lists are freed  * or reset to a default state as well.  This is simply a more efficient  * way to call dns_message_destroy() followed by dns_message_allocate(),  * since it avoid many memory allocations.  *  * If any data loanouts (buffers, names, rdatas, etc) were requested,  * the caller must no longer use them after this call.  *  * The intended next use of the message will be 'intent'.  *  * Requires:  *  *	'msg' be valid.  *  *	'intent' is DNS_MESSAGE_INTENTPARSE or DNS_MESSAGE_INTENTRENDER  */
end_comment

begin_function_decl
name|void
name|dns_message_destroy
parameter_list|(
name|dns_message_t
modifier|*
modifier|*
name|msgp
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Destroy all state in the message.  *  * Requires:  *  *	'msgp' be valid.  *  * Ensures:  *	'*msgp' == NULL  */
end_comment

begin_function_decl
name|isc_result_t
name|dns_message_sectiontotext
parameter_list|(
name|dns_message_t
modifier|*
name|msg
parameter_list|,
name|dns_section_t
name|section
parameter_list|,
specifier|const
name|dns_master_style_t
modifier|*
name|style
parameter_list|,
name|dns_messagetextflag_t
name|flags
parameter_list|,
name|isc_buffer_t
modifier|*
name|target
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|isc_result_t
name|dns_message_pseudosectiontotext
parameter_list|(
name|dns_message_t
modifier|*
name|msg
parameter_list|,
name|dns_pseudosection_t
name|section
parameter_list|,
specifier|const
name|dns_master_style_t
modifier|*
name|style
parameter_list|,
name|dns_messagetextflag_t
name|flags
parameter_list|,
name|isc_buffer_t
modifier|*
name|target
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Convert section 'section' or 'pseudosection' of message 'msg' to  * a cleartext representation  *  * Notes:  *      See dns_message_totext for meanings of flags.  *  * Requires:  *  *	'msg' is a valid message.  *  *	'style' is a valid master dump style.  *  *	'target' is a valid buffer.  *  *	'section' is a valid section label.  *  * Ensures:  *  *	If the result is success:  *  *		The used space in 'target' is updated.  *  * Returns:  *  *	ISC_R_SUCCESS  *	ISC_R_NOSPACE  *	ISC_R_NOMORE  *  *	Note: On error return, *target may be partially filled with data. */
end_comment

begin_function_decl
name|isc_result_t
name|dns_message_totext
parameter_list|(
name|dns_message_t
modifier|*
name|msg
parameter_list|,
specifier|const
name|dns_master_style_t
modifier|*
name|style
parameter_list|,
name|dns_messagetextflag_t
name|flags
parameter_list|,
name|isc_buffer_t
modifier|*
name|target
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Convert all sections of message 'msg' to a cleartext representation  *  * Notes:  *      In flags, If DNS_MESSAGETEXTFLAG_OMITDOT is set, then the  *      final '.' in absolute names will not be emitted.  If  *      DNS_MESSAGETEXTFLAG_NOCOMMENTS is cleared, lines beginning  *      with ";;" will be emitted indicating section name.  If  *      DNS_MESSAGETEXTFLAG_NOHEADERS is cleared, header lines will  *      be emitted.  *  * Requires:  *  *	'msg' is a valid message.  *  *	'style' is a valid master dump style.  *  *	'target' is a valid buffer.  *  * Ensures:  *  *	If the result is success:  *  *		The used space in 'target' is updated.  *  * Returns:  *  *	ISC_R_SUCCESS  *	ISC_R_NOSPACE  *	ISC_R_NOMORE  *  *	Note: On error return, *target may be partially filled with data.  */
end_comment

begin_function_decl
name|isc_result_t
name|dns_message_parse
parameter_list|(
name|dns_message_t
modifier|*
name|msg
parameter_list|,
name|isc_buffer_t
modifier|*
name|source
parameter_list|,
name|unsigned
name|int
name|options
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Parse raw wire data in 'source' as a DNS message.  *  * OPT records are detected and stored in the pseudo-section "opt".  * TSIGs are detected and stored in the pseudo-section "tsig".  *  * If DNS_MESSAGEPARSE_PRESERVEORDER is set, or if the opcode of the message  * is UPDATE, a separate dns_name_t object will be created for each RR in the  * message.  Each such dns_name_t will have a single rdataset containing the  * single RR, and the order of the RRs in the message is preserved.  * Otherwise, only one dns_name_t object will be created for each unique  * owner name in the section, and each such dns_name_t will have a list  * of rdatasets.  To access the names and their data, use  * dns_message_firstname() and dns_message_nextname().  *  * If DNS_MESSAGEPARSE_BESTEFFORT is set, errors in message content will  * not be considered FORMERRs.  If the entire message can be parsed, it  * will be returned and DNS_R_RECOVERABLE will be returned.  *  * If DNS_MESSAGEPARSE_IGNORETRUNCATION is set then return as many complete  * RR's as possible, DNS_R_RECOVERABLE will be returned.  *  * OPT and TSIG records are always handled specially, regardless of the  * 'preserve_order' setting.  *  * Requires:  *	"msg" be valid.  *  *	"buffer" be a wire format buffer.  *  * Ensures:  *	The buffer's data format is correct.  *  *	The buffer's contents verify as correct regarding header bits, buffer  * 	and rdata sizes, etc.  *  * Returns:  *	ISC_R_SUCCESS		-- all is well  *	ISC_R_NOMEMORY		-- no memory  *	DNS_R_RECOVERABLE	-- the message parsed properly, but contained  *				   errors.  *	Many other errors possible XXXMLG  */
end_comment

begin_function_decl
name|isc_result_t
name|dns_message_renderbegin
parameter_list|(
name|dns_message_t
modifier|*
name|msg
parameter_list|,
name|dns_compress_t
modifier|*
name|cctx
parameter_list|,
name|isc_buffer_t
modifier|*
name|buffer
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Begin rendering on a message.  Only one call can be made to this function  * per message.  *  * The compression context is "owned" by the message library until  * dns_message_renderend() is called.  It must be invalidated by the caller.  *  * The buffer is "owned" by the message library until dns_message_renderend()  * is called.  *  * Requires:  *  *	'msg' be valid.  *  *	'cctx' be valid.  *  *	'buffer' is a valid buffer.  *  * Side Effects:  *  *	The buffer is cleared before it is used.  *  * Returns:  *	ISC_R_SUCCESS		-- all is well  *	ISC_R_NOSPACE		-- output buffer is too small  */
end_comment

begin_function_decl
name|isc_result_t
name|dns_message_renderchangebuffer
parameter_list|(
name|dns_message_t
modifier|*
name|msg
parameter_list|,
name|isc_buffer_t
modifier|*
name|buffer
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Reset the buffer.  This can be used after growing the old buffer  * on a ISC_R_NOSPACE return from most of the render functions.  *  * On successful completion, the old buffer is no longer used by the  * library.  The new buffer is owned by the library until  * dns_message_renderend() is called.  *  * Requires:  *  *	'msg' be valid.  *  *	dns_message_renderbegin() was called.  *  *	buffer != NULL.  *  * Returns:  *	ISC_R_NOSPACE		-- new buffer is too small  *	ISC_R_SUCCESS		-- all is well.  */
end_comment

begin_function_decl
name|isc_result_t
name|dns_message_renderreserve
parameter_list|(
name|dns_message_t
modifier|*
name|msg
parameter_list|,
name|unsigned
name|int
name|space
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * XXXMLG should use size_t rather than unsigned int once the buffer  * API is cleaned up  *  * Reserve "space" bytes in the given buffer.  *  * Requires:  *  *	'msg' be valid.  *  *	dns_message_renderbegin() was called.  *  * Returns:  *	ISC_R_SUCCESS		-- all is well.  *	ISC_R_NOSPACE		-- not enough free space in the buffer.  */
end_comment

begin_function_decl
name|void
name|dns_message_renderrelease
parameter_list|(
name|dns_message_t
modifier|*
name|msg
parameter_list|,
name|unsigned
name|int
name|space
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * XXXMLG should use size_t rather than unsigned int once the buffer  * API is cleaned up  *  * Release "space" bytes in the given buffer that was previously reserved.  *  * Requires:  *  *	'msg' be valid.  *  *	'space' is less than or equal to the total amount of space reserved  *	via prior calls to dns_message_renderreserve().  *  *	dns_message_renderbegin() was called.  */
end_comment

begin_function_decl
name|isc_result_t
name|dns_message_rendersection
parameter_list|(
name|dns_message_t
modifier|*
name|msg
parameter_list|,
name|dns_section_t
name|section
parameter_list|,
name|unsigned
name|int
name|options
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Render all names, rdatalists, etc from the given section at the  * specified priority or higher.  *  * Requires:  *	'msg' be valid.  *  *	'section' be a valid section.  *  *	dns_message_renderbegin() was called.  *  * Returns:  *	ISC_R_SUCCESS		-- all records were written, and there are  *				   no more records for this section.  *	ISC_R_NOSPACE		-- Not enough room in the buffer to write  *				   all records requested.  *	DNS_R_MOREDATA		-- All requested records written, and there  *				   are records remaining for this section.  */
end_comment

begin_function_decl
name|void
name|dns_message_renderheader
parameter_list|(
name|dns_message_t
modifier|*
name|msg
parameter_list|,
name|isc_buffer_t
modifier|*
name|target
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Render the message header.  This is implicitly called by  * dns_message_renderend().  *  * Requires:  *  *	'msg' be a valid message.  *  *	dns_message_renderbegin() was called.  *  *	'target' is a valid buffer with enough space to hold a message header  */
end_comment

begin_function_decl
name|isc_result_t
name|dns_message_renderend
parameter_list|(
name|dns_message_t
modifier|*
name|msg
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Finish rendering to the buffer.  Note that more data can be in the  * 'msg' structure.  Destroying the structure will free this, or in a multi-  * part EDNS1 message this data can be rendered to another buffer later.  *  * Requires:  *  *	'msg' be a valid message.  *  *	dns_message_renderbegin() was called.  *  * Returns:  *	ISC_R_SUCCESS		-- all is well.  */
end_comment

begin_function_decl
name|void
name|dns_message_renderreset
parameter_list|(
name|dns_message_t
modifier|*
name|msg
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Reset the message so that it may be rendered again.  *  * Notes:  *  *	If dns_message_renderbegin() has been called, dns_message_renderend()  *	must be called before calling this function.  *  * Requires:  *  *	'msg' be a valid message with rendering intent.  */
end_comment

begin_function_decl
name|isc_result_t
name|dns_message_firstname
parameter_list|(
name|dns_message_t
modifier|*
name|msg
parameter_list|,
name|dns_section_t
name|section
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Set internal per-section name pointer to the beginning of the section.  *  * The functions dns_message_firstname() and dns_message_nextname() may  * be used for iterating over the owner names in a section.  *  * Requires:  *  *   	'msg' be valid.  *  *	'section' be a valid section.  *  * Returns:  *	ISC_R_SUCCESS		-- All is well.  *	ISC_R_NOMORE		-- No names on given section.  */
end_comment

begin_function_decl
name|isc_result_t
name|dns_message_nextname
parameter_list|(
name|dns_message_t
modifier|*
name|msg
parameter_list|,
name|dns_section_t
name|section
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Sets the internal per-section name pointer to point to the next name  * in that section.  *  * Requires:  *  *   	'msg' be valid.  *  *	'section' be a valid section.  *  *	dns_message_firstname() must have been called on this section,  *	and the result was ISC_R_SUCCESS.  *  * Returns:  *	ISC_R_SUCCESS		-- All is well.  *	ISC_R_NOMORE		-- No more names in given section.  */
end_comment

begin_function_decl
name|void
name|dns_message_currentname
parameter_list|(
name|dns_message_t
modifier|*
name|msg
parameter_list|,
name|dns_section_t
name|section
parameter_list|,
name|dns_name_t
modifier|*
modifier|*
name|name
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Sets 'name' to point to the name where the per-section internal name  * pointer is currently set.  *  * This function returns the name in the database, so any data associated  * with it (via the name's "list" member) contains the actual rdatasets.  *  * Requires:  *  *	'msg' be valid.  *  *	'name' be non-NULL, and *name be NULL.  *  *	'section' be a valid section.  *  *	dns_message_firstname() must have been called on this section,  *	and the result of it and any dns_message_nextname() calls was  *	ISC_R_SUCCESS.  */
end_comment

begin_function_decl
name|isc_result_t
name|dns_message_findname
parameter_list|(
name|dns_message_t
modifier|*
name|msg
parameter_list|,
name|dns_section_t
name|section
parameter_list|,
name|dns_name_t
modifier|*
name|target
parameter_list|,
name|dns_rdatatype_t
name|type
parameter_list|,
name|dns_rdatatype_t
name|covers
parameter_list|,
name|dns_name_t
modifier|*
modifier|*
name|foundname
parameter_list|,
name|dns_rdataset_t
modifier|*
modifier|*
name|rdataset
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Search for a name in the specified section.  If it is found, *name is  * set to point to the name, and *rdataset is set to point to the found  * rdataset (if type is specified as other than dns_rdatatype_any).  *  * Requires:  *	'msg' be valid.  *  *	'section' be a valid section.  *  *	If a pointer to the name is desired, 'foundname' should be non-NULL.  *	If it is non-NULL, '*foundname' MUST be NULL.  *  *	If a type other than dns_datatype_any is searched for, 'rdataset'  *	may be non-NULL, '*rdataset' be NULL, and will point at the found  *	rdataset.  If the type is dns_datatype_any, 'rdataset' must be NULL.  *  *	'target' be a valid name.  *  *	'type' be a valid type.  *  *	If 'type' is dns_rdatatype_rrsig, 'covers' must be a valid type.  *	Otherwise it should be 0.  *  * Returns:  *	ISC_R_SUCCESS		-- all is well.  *	DNS_R_NXDOMAIN		-- name does not exist in that section.  *	DNS_R_NXRRSET		-- The name does exist, but the desired  *				   type does not.  */
end_comment

begin_function_decl
name|isc_result_t
name|dns_message_findtype
parameter_list|(
name|dns_name_t
modifier|*
name|name
parameter_list|,
name|dns_rdatatype_t
name|type
parameter_list|,
name|dns_rdatatype_t
name|covers
parameter_list|,
name|dns_rdataset_t
modifier|*
modifier|*
name|rdataset
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Search the name for the specified type.  If it is found, *rdataset is  * filled in with a pointer to that rdataset.  *  * Requires:  *	if '**rdataset' is non-NULL, *rdataset needs to be NULL.  *  *	'type' be a valid type, and NOT dns_rdatatype_any.  *  *	If 'type' is dns_rdatatype_rrsig, 'covers' must be a valid type.  *	Otherwise it should be 0.  *  * Returns:  *	ISC_R_SUCCESS		-- all is well.  *	ISC_R_NOTFOUND		-- the desired type does not exist.  */
end_comment

begin_function_decl
name|isc_result_t
name|dns_message_find
parameter_list|(
name|dns_name_t
modifier|*
name|name
parameter_list|,
name|dns_rdataclass_t
name|rdclass
parameter_list|,
name|dns_rdatatype_t
name|type
parameter_list|,
name|dns_rdatatype_t
name|covers
parameter_list|,
name|dns_rdataset_t
modifier|*
modifier|*
name|rdataset
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Search the name for the specified rdclass and type.  If it is found,  * *rdataset is filled in with a pointer to that rdataset.  *  * Requires:  *\li	if '**rdataset' is non-NULL, *rdataset needs to be NULL.  *  *\li	'type' be a valid type, and NOT dns_rdatatype_any.  *  *\li	If 'type' is dns_rdatatype_rrsig, 'covers' must be a valid type.  *	Otherwise it should be 0.  *  * Returns:  *\li	#ISC_R_SUCCESS		-- all is well.  *\li	#ISC_R_NOTFOUND		-- the desired type does not exist.  */
end_comment

begin_function_decl
name|void
name|dns_message_movename
parameter_list|(
name|dns_message_t
modifier|*
name|msg
parameter_list|,
name|dns_name_t
modifier|*
name|name
parameter_list|,
name|dns_section_t
name|fromsection
parameter_list|,
name|dns_section_t
name|tosection
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Move a name from one section to another.  *  * Requires:  *  *	'msg' be valid.  *  *	'name' must be a name already in 'fromsection'.  *  *	'fromsection' must be a valid section.  *  *	'tosection' must be a valid section.  */
end_comment

begin_function_decl
name|void
name|dns_message_addname
parameter_list|(
name|dns_message_t
modifier|*
name|msg
parameter_list|,
name|dns_name_t
modifier|*
name|name
parameter_list|,
name|dns_section_t
name|section
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Adds the name to the given section.  *  * It is the caller's responsibility to enforce any unique name requirements  * in a section.  *  * Requires:  *  *	'msg' be valid, and be a renderable message.  *  *	'name' be a valid absolute name.  *  *	'section' be a named section.  */
end_comment

begin_comment
comment|/*  * LOANOUT FUNCTIONS  *  * Each of these functions loan a particular type of data to the caller.  * The storage for these will vanish when the message is destroyed or  * reset, and must NOT be used after these operations.  */
end_comment

begin_function_decl
name|isc_result_t
name|dns_message_gettempname
parameter_list|(
name|dns_message_t
modifier|*
name|msg
parameter_list|,
name|dns_name_t
modifier|*
modifier|*
name|item
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Return a name that can be used for any temporary purpose, including  * inserting into the message's linked lists.  The name must be returned  * to the message code using dns_message_puttempname() or inserted into  * one of the message's sections before the message is destroyed.  *  * It is the caller's responsibility to initialize this name.  *  * Requires:  *	msg be a valid message  *  *	item != NULL&& *item == NULL  *  * Returns:  *	ISC_R_SUCCESS		-- All is well.  *	ISC_R_NOMEMORY		-- No item can be allocated.  */
end_comment

begin_function_decl
name|isc_result_t
name|dns_message_gettempoffsets
parameter_list|(
name|dns_message_t
modifier|*
name|msg
parameter_list|,
name|dns_offsets_t
modifier|*
modifier|*
name|item
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Return an offsets array that can be used for any temporary purpose,  * such as attaching to a temporary name.  The offsets will be freed  * when the message is destroyed or reset.  *  * Requires:  *	msg be a valid message  *  *	item != NULL&& *item == NULL  *  * Returns:  *	ISC_R_SUCCESS		-- All is well.  *	ISC_R_NOMEMORY		-- No item can be allocated.  */
end_comment

begin_function_decl
name|isc_result_t
name|dns_message_gettemprdata
parameter_list|(
name|dns_message_t
modifier|*
name|msg
parameter_list|,
name|dns_rdata_t
modifier|*
modifier|*
name|item
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Return a rdata that can be used for any temporary purpose, including  * inserting into the message's linked lists.  The rdata will be freed  * when the message is destroyed or reset.  *  * Requires:  *	msg be a valid message  *  *	item != NULL&& *item == NULL  *  * Returns:  *	ISC_R_SUCCESS		-- All is well.  *	ISC_R_NOMEMORY		-- No item can be allocated.  */
end_comment

begin_function_decl
name|isc_result_t
name|dns_message_gettemprdataset
parameter_list|(
name|dns_message_t
modifier|*
name|msg
parameter_list|,
name|dns_rdataset_t
modifier|*
modifier|*
name|item
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Return a rdataset that can be used for any temporary purpose, including  * inserting into the message's linked lists. The name must be returned  * to the message code using dns_message_puttempname() or inserted into  * one of the message's sections before the message is destroyed.  *  * Requires:  *	msg be a valid message  *  *	item != NULL&& *item == NULL  *  * Returns:  *	ISC_R_SUCCESS		-- All is well.  *	ISC_R_NOMEMORY		-- No item can be allocated.  */
end_comment

begin_function_decl
name|isc_result_t
name|dns_message_gettemprdatalist
parameter_list|(
name|dns_message_t
modifier|*
name|msg
parameter_list|,
name|dns_rdatalist_t
modifier|*
modifier|*
name|item
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Return a rdatalist that can be used for any temporary purpose, including  * inserting into the message's linked lists.  The rdatalist will be  * destroyed when the message is destroyed or reset.  *  * Requires:  *	msg be a valid message  *  *	item != NULL&& *item == NULL  *  * Returns:  *	ISC_R_SUCCESS		-- All is well.  *	ISC_R_NOMEMORY		-- No item can be allocated.  */
end_comment

begin_function_decl
name|void
name|dns_message_puttempname
parameter_list|(
name|dns_message_t
modifier|*
name|msg
parameter_list|,
name|dns_name_t
modifier|*
modifier|*
name|item
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Return a borrowed name to the message's name free list.  *  * Requires:  *	msg be a valid message  *  *	item != NULL&& *item point to a name returned by  *	dns_message_gettempname()  *  * Ensures:  *	*item == NULL  */
end_comment

begin_function_decl
name|void
name|dns_message_puttemprdata
parameter_list|(
name|dns_message_t
modifier|*
name|msg
parameter_list|,
name|dns_rdata_t
modifier|*
modifier|*
name|item
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Return a borrowed rdata to the message's rdata free list.  *  * Requires:  *	msg be a valid message  *  *	item != NULL&& *item point to a rdata returned by  *	dns_message_gettemprdata()  *  * Ensures:  *	*item == NULL  */
end_comment

begin_function_decl
name|void
name|dns_message_puttemprdataset
parameter_list|(
name|dns_message_t
modifier|*
name|msg
parameter_list|,
name|dns_rdataset_t
modifier|*
modifier|*
name|item
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Return a borrowed rdataset to the message's rdataset free list.  *  * Requires:  *	msg be a valid message  *  *	item != NULL&& *item point to a rdataset returned by  *	dns_message_gettemprdataset()  *  * Ensures:  *	*item == NULL  */
end_comment

begin_function_decl
name|void
name|dns_message_puttemprdatalist
parameter_list|(
name|dns_message_t
modifier|*
name|msg
parameter_list|,
name|dns_rdatalist_t
modifier|*
modifier|*
name|item
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Return a borrowed rdatalist to the message's rdatalist free list.  *  * Requires:  *	msg be a valid message  *  *	item != NULL&& *item point to a rdatalist returned by  *	dns_message_gettemprdatalist()  *  * Ensures:  *	*item == NULL  */
end_comment

begin_function_decl
name|isc_result_t
name|dns_message_peekheader
parameter_list|(
name|isc_buffer_t
modifier|*
name|source
parameter_list|,
name|dns_messageid_t
modifier|*
name|idp
parameter_list|,
name|unsigned
name|int
modifier|*
name|flagsp
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Assume the remaining region of "source" is a DNS message.  Peek into  * it and fill in "*idp" with the message id, and "*flagsp" with the flags.  *  * Requires:  *  *	source != NULL  *  * Ensures:  *  *	if (idp != NULL) *idp == message id.  *  *	if (flagsp != NULL) *flagsp == message flags.  *  * Returns:  *  *	ISC_R_SUCCESS		-- all is well.  *  *	ISC_R_UNEXPECTEDEND	-- buffer doesn't contain enough for a header.  */
end_comment

begin_function_decl
name|isc_result_t
name|dns_message_reply
parameter_list|(
name|dns_message_t
modifier|*
name|msg
parameter_list|,
name|isc_boolean_t
name|want_question_section
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Start formatting a reply to the query in 'msg'.  *  * Requires:  *  *	'msg' is a valid message with parsing intent, and contains a query.  *  * Ensures:  *  *	The message will have a rendering intent.  If 'want_question_section'  *	is true, the message opcode is query or notify, and the question  *	section is present and properly formatted, then the question section  *	will be included in the reply.  All other sections will be cleared.  *	The QR flag will be set, the RD flag will be preserved, and all other  *	flags will be cleared.  *  * Returns:  *  *	ISC_R_SUCCESS		-- all is well.  *  *	DNS_R_FORMERR		-- the header or question section of the  *				   message is invalid, replying is impossible.  *				   If DNS_R_FORMERR is returned when  *				   want_question_section is ISC_FALSE, then  *				   it's the header section that's bad;  *				   otherwise either of the header or question  *				   sections may be bad.  */
end_comment

begin_function_decl
name|dns_rdataset_t
modifier|*
name|dns_message_getopt
parameter_list|(
name|dns_message_t
modifier|*
name|msg
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Get the OPT record for 'msg'.  *  * Requires:  *  *	'msg' is a valid message.  *  * Returns:  *  *	The OPT rdataset of 'msg', or NULL if there isn't one.  */
end_comment

begin_function_decl
name|isc_result_t
name|dns_message_setopt
parameter_list|(
name|dns_message_t
modifier|*
name|msg
parameter_list|,
name|dns_rdataset_t
modifier|*
name|opt
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Set the OPT record for 'msg'.  *  * Requires:  *  *	'msg' is a valid message with rendering intent  *	and no sections have been rendered.  *  *	'opt' is a valid OPT record.  *  * Ensures:  *  *	The OPT record has either been freed or ownership of it has  *	been transferred to the message.  *  *	If ISC_R_SUCCESS was returned, the OPT record will be rendered   *	when dns_message_renderend() is called.  *  * Returns:  *  *	ISC_R_SUCCESS		-- all is well.  *  *	ISC_R_NOSPACE		-- there is no space for the OPT record.  */
end_comment

begin_function_decl
name|dns_rdataset_t
modifier|*
name|dns_message_gettsig
parameter_list|(
name|dns_message_t
modifier|*
name|msg
parameter_list|,
name|dns_name_t
modifier|*
modifier|*
name|owner
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Get the TSIG record and owner for 'msg'.  *  * Requires:  *  *	'msg' is a valid message.  *	'owner' is NULL or *owner is NULL.  *  * Returns:  *  *	The TSIG rdataset of 'msg', or NULL if there isn't one.  *  * Ensures:  *  * 	If 'owner' is not NULL, it will point to the owner name.  */
end_comment

begin_function_decl
name|isc_result_t
name|dns_message_settsigkey
parameter_list|(
name|dns_message_t
modifier|*
name|msg
parameter_list|,
name|dns_tsigkey_t
modifier|*
name|key
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Set the tsig key for 'msg'.  This is only necessary for when rendering a  * query or parsing a response.  The key (if non-NULL) is attached to, and  * will be detached when the message is destroyed.  *  * Requires:  *  *	'msg' is a valid message with rendering intent,  *	dns_message_renderbegin() has been called, and no sections have been  *	rendered.  *	'key' is a valid tsig key or NULL.  *  * Returns:  *  *	ISC_R_SUCCESS		-- all is well.  *  *	ISC_R_NOSPACE		-- there is no space for the TSIG record.  */
end_comment

begin_function_decl
name|dns_tsigkey_t
modifier|*
name|dns_message_gettsigkey
parameter_list|(
name|dns_message_t
modifier|*
name|msg
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Gets the tsig key for 'msg'.  *  * Requires:  *  *	'msg' is a valid message  */
end_comment

begin_function_decl
name|isc_result_t
name|dns_message_setquerytsig
parameter_list|(
name|dns_message_t
modifier|*
name|msg
parameter_list|,
name|isc_buffer_t
modifier|*
name|querytsig
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Indicates that 'querytsig' is the TSIG from the signed query for which  * 'msg' is the response.  This is also used for chained TSIGs in TCP  * responses.  *  * Requires:  *  *	'querytsig' is a valid buffer as returned by dns_message_getquerytsig()  *	or NULL  *  *	'msg' is a valid message  *  * Returns:  *  *	ISC_R_SUCCESS  *	ISC_R_NOMEMORY  */
end_comment

begin_function_decl
name|isc_result_t
name|dns_message_getquerytsig
parameter_list|(
name|dns_message_t
modifier|*
name|msg
parameter_list|,
name|isc_mem_t
modifier|*
name|mctx
parameter_list|,
name|isc_buffer_t
modifier|*
modifier|*
name|querytsig
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Gets the tsig from the TSIG from the signed query 'msg'.  This is also used  * for chained TSIGs in TCP responses.  Unlike dns_message_gettsig, this makes  * a copy of the data, so can be used if the message is destroyed.  *  * Requires:  *  *	'msg' is a valid signed message  *	'mctx' is a valid memory context  *	querytsig != NULL&& *querytsig == NULL  *  * Returns:  *  *	ISC_R_SUCCESS  *	ISC_R_NOMEMORY  *  * Ensures:  * 	'tsig' points to NULL or an allocated buffer which must be freed  * 	by the caller.  */
end_comment

begin_function_decl
name|dns_rdataset_t
modifier|*
name|dns_message_getsig0
parameter_list|(
name|dns_message_t
modifier|*
name|msg
parameter_list|,
name|dns_name_t
modifier|*
modifier|*
name|owner
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Get the SIG(0) record and owner for 'msg'.  *  * Requires:  *  *	'msg' is a valid message.  *	'owner' is NULL or *owner is NULL.  *  * Returns:  *  *	The SIG(0) rdataset of 'msg', or NULL if there isn't one.  *  * Ensures:  *  * 	If 'owner' is not NULL, it will point to the owner name.  */
end_comment

begin_function_decl
name|isc_result_t
name|dns_message_setsig0key
parameter_list|(
name|dns_message_t
modifier|*
name|msg
parameter_list|,
name|dst_key_t
modifier|*
name|key
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Set the SIG(0) key for 'msg'.  *  * Requires:  *  *	'msg' is a valid message with rendering intent,  *	dns_message_renderbegin() has been called, and no sections have been  *	rendered.  *	'key' is a valid sig key or NULL.  *  * Returns:  *  *	ISC_R_SUCCESS		-- all is well.  *  *	ISC_R_NOSPACE		-- there is no space for the SIG(0) record.  */
end_comment

begin_function_decl
name|dst_key_t
modifier|*
name|dns_message_getsig0key
parameter_list|(
name|dns_message_t
modifier|*
name|msg
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Gets the SIG(0) key for 'msg'.  *  * Requires:  *  *	'msg' is a valid message  */
end_comment

begin_function_decl
name|void
name|dns_message_takebuffer
parameter_list|(
name|dns_message_t
modifier|*
name|msg
parameter_list|,
name|isc_buffer_t
modifier|*
modifier|*
name|buffer
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Give the *buffer to the message code to clean up when it is no  * longer needed.  This is usually when the message is reset or  * destroyed.  *  * Requires:  *  *	msg be a valid message.  *  *	buffer != NULL&& *buffer is a valid isc_buffer_t, which was  *	dynamincally allocated via isc_buffer_allocate().  */
end_comment

begin_function_decl
name|isc_result_t
name|dns_message_signer
parameter_list|(
name|dns_message_t
modifier|*
name|msg
parameter_list|,
name|dns_name_t
modifier|*
name|signer
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * If this message was signed, return the identity of the signer.  * Unless ISC_R_NOTFOUND is returned, signer will reflect the name of the  * key that signed the message.  *  * Requires:  *  *	msg is a valid parsed message.  *	signer is a valid name  *  * Returns:  *  *	ISC_R_SUCCESS		- the message was signed, and *signer  *				  contains the signing identity  *  *	ISC_R_NOTFOUND		- no TSIG or SIG(0) record is present in the  *				  message  *  *	DNS_R_TSIGVERIFYFAILURE	- the message was signed by a TSIG, but the  *				  signature failed to verify  *  *	DNS_R_TSIGERRORSET	- the message was signed by a TSIG and  *				  verified, but the query was rejected by  *				  the server  *  *	DNS_R_NOIDENTITY	- the message was signed by a TSIG and  *				  verified, but the key has no identity since  *				  it was generated by an unsigned TKEY process  *  *	DNS_R_SIGINVALID	- the message was signed by a SIG(0), but  *				  the signature failed to verify  *  *	DNS_R_NOTVERIFIEDYET	- the message was signed by a TSIG or SIG(0),  *				  but the signature has not been verified yet  */
end_comment

begin_function_decl
name|isc_result_t
name|dns_message_checksig
parameter_list|(
name|dns_message_t
modifier|*
name|msg
parameter_list|,
name|dns_view_t
modifier|*
name|view
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * If this message was signed, verify the signature.  *  * Requires:  *  *	msg is a valid parsed message.  *	view is a valid view or NULL  *  * Returns:  *  *	ISC_R_SUCCESS		- the message was unsigned, or the message  *				  was signed correctly.  *  *	DNS_R_EXPECTEDTSIG	- A TSIG was expected, but not seen  *	DNS_R_UNEXPECTEDTSIG	- A TSIG was seen but not expected  *	DNS_R_TSIGVERIFYFAILURE - The TSIG failed to verify  */
end_comment

begin_function_decl
name|isc_result_t
name|dns_message_rechecksig
parameter_list|(
name|dns_message_t
modifier|*
name|msg
parameter_list|,
name|dns_view_t
modifier|*
name|view
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Reset the signature state and then if the message was signed,  * verify the message.  *  * Requires:  *  *	msg is a valid parsed message.  *	view is a valid view or NULL  *  * Returns:  *  *	ISC_R_SUCCESS		- the message was unsigned, or the message  *				  was signed correctly.  *  *	DNS_R_EXPECTEDTSIG	- A TSIG was expected, but not seen  *	DNS_R_UNEXPECTEDTSIG	- A TSIG was seen but not expected  *	DNS_R_TSIGVERIFYFAILURE - The TSIG failed to verify  */
end_comment

begin_function_decl
name|void
name|dns_message_resetsig
parameter_list|(
name|dns_message_t
modifier|*
name|msg
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Reset the signature state.  *  * Requires:  *	'msg' is a valid parsed message.  */
end_comment

begin_function_decl
name|isc_region_t
modifier|*
name|dns_message_getrawmessage
parameter_list|(
name|dns_message_t
modifier|*
name|msg
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Retrieve the raw message in compressed wire format.  The message must  * have been successfully parsed for it to have been saved.  *  * Requires:  *	msg is a valid parsed message.  *  * Returns:  *	NULL	if there is no saved message.  *	a pointer to a region which refers the dns message.  */
end_comment

begin_function_decl
name|void
name|dns_message_setsortorder
parameter_list|(
name|dns_message_t
modifier|*
name|msg
parameter_list|,
name|dns_rdatasetorderfunc_t
name|order
parameter_list|,
specifier|const
name|void
modifier|*
name|order_arg
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Define the order in which RR sets get rendered by  * dns_message_rendersection() to be the ascending order  * defined by the integer value returned by 'order' when  * given each RR and 'arg' as arguments.  If 'order' and  * 'order_arg' are NULL, a default order is used.  *  * Requires:  *	msg be a valid message.  *	order_arg is NULL if and only if order is NULL.  */
end_comment

begin_function_decl
name|void
name|dns_message_settimeadjust
parameter_list|(
name|dns_message_t
modifier|*
name|msg
parameter_list|,
name|int
name|timeadjust
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Adjust the time used to sign/verify a message by timeadjust.  * Currently only TSIG.  *  * Requires:  *	msg be a valid message.  */
end_comment

begin_function_decl
name|int
name|dns_message_gettimeadjust
parameter_list|(
name|dns_message_t
modifier|*
name|msg
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Return the current time adjustment.  *  * Requires:  *	msg be a valid message.  */
end_comment

begin_macro
name|ISC_LANG_ENDDECLS
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* DNS_MESSAGE_H */
end_comment

end_unit

