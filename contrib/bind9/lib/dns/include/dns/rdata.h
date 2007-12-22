begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (C) 2004, 2005  Internet Systems Consortium, Inc. ("ISC")  * Copyright (C) 1998-2003  Internet Software Consortium.  *  * Permission to use, copy, modify, and distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND ISC DISCLAIMS ALL WARRANTIES WITH  * REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY  * AND FITNESS.  IN NO EVENT SHALL ISC BE LIABLE FOR ANY SPECIAL, DIRECT,  * INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM  * LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE  * OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR  * PERFORMANCE OF THIS SOFTWARE.  */
end_comment

begin_comment
comment|/* $Id: rdata.h,v 1.60.18.3 2005/05/19 04:59:56 marka Exp $ */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|DNS_RDATA_H
end_ifndef

begin_define
define|#
directive|define
name|DNS_RDATA_H
value|1
end_define

begin_comment
comment|/*****  ***** Module Info  *****/
end_comment

begin_comment
comment|/*! \file  * \brief  * Provides facilities for manipulating DNS rdata, including conversions to  * and from wire format and text format.  *  * Given the large amount of rdata possible in a nameserver, it was important  * to come up with a very efficient way of storing rdata, but at the same  * time allow it to be manipulated.  *  * The decision was to store rdata in uncompressed wire format,  * and not to make it a fully abstracted object; i.e. certain parts of the  * server know rdata is stored that way.  This saves a lot of memory, and  * makes adding rdata to messages easy.  Having much of the server know  * the representation would be perilous, and we certainly don't want each  * user of rdata to be manipulating such a low-level structure.  This is  * where the rdata module comes in.  The module allows rdata handles to be  * created and attached to uncompressed wire format regions.  All rdata  * operations and conversions are done through these handles.  *  * Implementation Notes:  *  *\li	The routines in this module are expected to be synthesized by the  *	build process from a set of source files, one per rdata type.  For  *	portability, it's probably best that the building be done by a C  *	program.  Adding a new rdata type will be a simple matter of adding  *	a file to a directory and rebuilding the server.  *All* knowlege of  *	the format of a particular rdata type is in this file.  *  * MP:  *\li	Clients of this module must impose any required synchronization.  *  * Reliability:  *\li	This module deals with low-level byte streams.  Errors in any of  *	the functions are likely to crash the server or corrupt memory.  *  *\li	Rdata is typed, and the caller must know what type of rdata it has.  *	A caller that gets this wrong could crash the server.  *  *\li	The fromstruct() and tostruct() routines use a void * pointer to  *	represent the structure.  The caller must ensure that it passes a  *	pointer to the appropriate type, or the server could crash or memory  *	could be corrupted.  *  * Resources:  *\li	None.  *  * Security:  *  *\li	*** WARNING ***  *	dns_rdata_fromwire() deals with raw network data.  An error in  *	this routine could result in the failure or hijacking of the server.  *  * Standards:  *\li	RFC1035  *\li	Draft EDNS0 (0)  *\li	Draft EDNS1 (0)  *\li	Draft Binary Labels (2)  *\li	Draft Local Compression (1)  *\li	Various RFCs for particular types; these will be documented in the  *	 sources files of the types.  *  */
end_comment

begin_comment
comment|/***  *** Imports  ***/
end_comment

begin_include
include|#
directive|include
file|<isc/lang.h>
end_include

begin_include
include|#
directive|include
file|<dns/types.h>
end_include

begin_include
include|#
directive|include
file|<dns/name.h>
end_include

begin_macro
name|ISC_LANG_BEGINDECLS
end_macro

begin_comment
comment|/***  *** Types  ***/
end_comment

begin_comment
comment|/*%  ***** An 'rdata' is a handle to a binary region.  The handle has an RR  ***** class and type, and the data in the binary region is in the format  ***** of the given class and type.  *****/
end_comment

begin_comment
comment|/*%  * Clients are strongly discouraged from using this type directly, with  * the exception of the 'link' field which may be used directly for whatever  * purpose the client desires.  */
end_comment

begin_struct
struct|struct
name|dns_rdata
block|{
name|unsigned
name|char
modifier|*
name|data
decl_stmt|;
name|unsigned
name|int
name|length
decl_stmt|;
name|dns_rdataclass_t
name|rdclass
decl_stmt|;
name|dns_rdatatype_t
name|type
decl_stmt|;
name|unsigned
name|int
name|flags
decl_stmt|;
name|ISC_LINK
argument_list|(
argument|dns_rdata_t
argument_list|)
name|link
expr_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|DNS_RDATA_INIT
value|{ NULL, 0, 0, 0, 0, {(void*)(-1), (void *)(-1)}}
end_define

begin_define
define|#
directive|define
name|DNS_RDATA_UPDATE
value|0x0001
end_define

begin_comment
comment|/*%< update pseudo record */
end_comment

begin_comment
comment|/*  * Flags affecting rdata formatting style.  Flags 0xFFFF0000  * are used by masterfile-level formatting and defined elsewhere.  * See additional comments at dns_rdata_tofmttext().  */
end_comment

begin_comment
comment|/*% Split the rdata into multiple lines to try to keep it  within the "width". */
end_comment

begin_define
define|#
directive|define
name|DNS_STYLEFLAG_MULTILINE
value|0x00000001U
end_define

begin_comment
comment|/*% Output explanatory comments. */
end_comment

begin_define
define|#
directive|define
name|DNS_STYLEFLAG_COMMENT
value|0x00000002U
end_define

begin_define
define|#
directive|define
name|DNS_RDATA_DOWNCASE
value|DNS_NAME_DOWNCASE
end_define

begin_define
define|#
directive|define
name|DNS_RDATA_CHECKNAMES
value|DNS_NAME_CHECKNAMES
end_define

begin_define
define|#
directive|define
name|DNS_RDATA_CHECKNAMESFAIL
value|DNS_NAME_CHECKNAMESFAIL
end_define

begin_define
define|#
directive|define
name|DNS_RDATA_CHECKREVERSE
value|DNS_NAME_CHECKREVERSE
end_define

begin_define
define|#
directive|define
name|DNS_RDATA_CHECKMX
value|DNS_NAME_CHECKMX
end_define

begin_define
define|#
directive|define
name|DNS_RDATA_CHECKMXFAIL
value|DNS_NAME_CHECKMXFAIL
end_define

begin_comment
comment|/***  *** Initialization  ***/
end_comment

begin_function_decl
name|void
name|dns_rdata_init
parameter_list|(
name|dns_rdata_t
modifier|*
name|rdata
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Make 'rdata' empty.  *  * Requires:  *	'rdata' is a valid rdata (i.e. not NULL, points to a struct dns_rdata)  */
end_comment

begin_function_decl
name|void
name|dns_rdata_reset
parameter_list|(
name|dns_rdata_t
modifier|*
name|rdata
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Make 'rdata' empty.  *  * Requires:  *\li	'rdata' is a previously initialized rdata and is not linked.  */
end_comment

begin_function_decl
name|void
name|dns_rdata_clone
parameter_list|(
specifier|const
name|dns_rdata_t
modifier|*
name|src
parameter_list|,
name|dns_rdata_t
modifier|*
name|target
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Clone 'target' from 'src'.  *  * Requires:  *\li	'src' to be initialized.  *\li	'target' to be initialized.  */
end_comment

begin_comment
comment|/***  *** Comparisons  ***/
end_comment

begin_function_decl
name|int
name|dns_rdata_compare
parameter_list|(
specifier|const
name|dns_rdata_t
modifier|*
name|rdata1
parameter_list|,
specifier|const
name|dns_rdata_t
modifier|*
name|rdata2
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Determine the relative ordering under the DNSSEC order relation of  * 'rdata1' and 'rdata2'.  *  * Requires:  *  *\li	'rdata1' is a valid, non-empty rdata  *  *\li	'rdata2' is a valid, non-empty rdata  *  * Returns:  *\li< 0		'rdata1' is less than 'rdata2'  *\li	0		'rdata1' is equal to 'rdata2'  *\li> 0		'rdata1' is greater than 'rdata2'  */
end_comment

begin_comment
comment|/***  *** Conversions  ***/
end_comment

begin_function_decl
name|void
name|dns_rdata_fromregion
parameter_list|(
name|dns_rdata_t
modifier|*
name|rdata
parameter_list|,
name|dns_rdataclass_t
name|rdclass
parameter_list|,
name|dns_rdatatype_t
name|type
parameter_list|,
name|isc_region_t
modifier|*
name|r
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Make 'rdata' refer to region 'r'.  *  * Requires:  *  *\li	The data in 'r' is properly formatted for whatever type it is.  */
end_comment

begin_function_decl
name|void
name|dns_rdata_toregion
parameter_list|(
specifier|const
name|dns_rdata_t
modifier|*
name|rdata
parameter_list|,
name|isc_region_t
modifier|*
name|r
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Make 'r' refer to 'rdata'.  */
end_comment

begin_function_decl
name|isc_result_t
name|dns_rdata_fromwire
parameter_list|(
name|dns_rdata_t
modifier|*
name|rdata
parameter_list|,
name|dns_rdataclass_t
name|rdclass
parameter_list|,
name|dns_rdatatype_t
name|type
parameter_list|,
name|isc_buffer_t
modifier|*
name|source
parameter_list|,
name|dns_decompress_t
modifier|*
name|dctx
parameter_list|,
name|unsigned
name|int
name|options
parameter_list|,
name|isc_buffer_t
modifier|*
name|target
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Copy the possibly-compressed rdata at source into the target region.  *  * Notes:  *\li	Name decompression policy is controlled by 'dctx'.  *  *	'options'  *\li	DNS_RDATA_DOWNCASE	downcase domain names when they are copied  *				into target.  *  * Requires:  *  *\li	'rdclass' and 'type' are valid.  *  *\li	'source' is a valid buffer, and the active region of 'source'  *	references the rdata to be processed.  *  *\li	'target' is a valid buffer.  *  *\li	'dctx' is a valid decompression context.  *  * Ensures,  *	if result is success:  *	\li 	If 'rdata' is not NULL, it is attached to the target.  *	\li	The conditions dns_name_fromwire() ensures for names hold  *		for all names in the rdata.  *	\li	The current location in source is advanced, and the used space  *		in target is updated.  *  * Result:  *\li	Success  *\li	Any non-success status from dns_name_fromwire()  *\li	Various 'Bad Form' class failures depending on class and type  *\li	Bad Form: Input too short  *\li	Resource Limit: Not enough space  */
end_comment

begin_function_decl
name|isc_result_t
name|dns_rdata_towire
parameter_list|(
name|dns_rdata_t
modifier|*
name|rdata
parameter_list|,
name|dns_compress_t
modifier|*
name|cctx
parameter_list|,
name|isc_buffer_t
modifier|*
name|target
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Convert 'rdata' into wire format, compressing it as specified by the  * compression context 'cctx', and storing the result in 'target'.  *  * Notes:  *\li	If the compression context allows global compression, then the  *	global compression table may be updated.  *  * Requires:  *\li	'rdata' is a valid, non-empty rdata  *  *\li	target is a valid buffer  *  *\li	Any offsets specified in a global compression table are valid  *	for target.  *  * Ensures,  *	if the result is success:  *	\li	The used space in target is updated.  *  * Returns:  *\li	Success  *\li	Any non-success status from dns_name_towire()  *\li	Resource Limit: Not enough space  */
end_comment

begin_function_decl
name|isc_result_t
name|dns_rdata_fromtext
parameter_list|(
name|dns_rdata_t
modifier|*
name|rdata
parameter_list|,
name|dns_rdataclass_t
name|rdclass
parameter_list|,
name|dns_rdatatype_t
name|type
parameter_list|,
name|isc_lex_t
modifier|*
name|lexer
parameter_list|,
name|dns_name_t
modifier|*
name|origin
parameter_list|,
name|unsigned
name|int
name|options
parameter_list|,
name|isc_mem_t
modifier|*
name|mctx
parameter_list|,
name|isc_buffer_t
modifier|*
name|target
parameter_list|,
name|dns_rdatacallbacks_t
modifier|*
name|callbacks
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Convert the textual representation of a DNS rdata into uncompressed wire  * form stored in the target region.  Tokens constituting the text of the rdata  * are taken from 'lexer'.  *  * Notes:  *\li	Relative domain names in the rdata will have 'origin' appended to them.  *	A NULL origin implies "origin == dns_rootname".  *  *  *	'options'  *\li	DNS_RDATA_DOWNCASE	downcase domain names when they are copied  *				into target.  *\li	DNS_RDATA_CHECKNAMES 	perform checknames checks.  *\li	DNS_RDATA_CHECKNAMESFAIL fail if the checknames check fail.  If  *				not set a warning will be issued.  *\li	DNS_RDATA_CHECKREVERSE  this should set if the owner name ends  *				in IP6.ARPA, IP6.INT or IN-ADDR.ARPA.  *  * Requires:  *  *\li	'rdclass' and 'type' are valid.  *  *\li	'lexer' is a valid isc_lex_t.  *  *\li	'mctx' is a valid isc_mem_t.  *  *\li	'target' is a valid region.  *  *\li	'origin' if non NULL it must be absolute.  *	  *\li	'callbacks' to be NULL or callbacks->warn and callbacks->error be  *	initialized.  *  * Ensures,   *	if result is success:  *\li	 	If 'rdata' is not NULL, it is attached to the target.   *\li		The conditions dns_name_fromtext() ensures for names hold  *		for all names in the rdata.   *\li		The used space in target is updated.  *  * Result:  *\li	Success  *\li	Translated result codes from isc_lex_gettoken  *\li	Various 'Bad Form' class failures depending on class and type  *\li	Bad Form: Input too short  *\li	Resource Limit: Not enough space  *\li	Resource Limit: Not enough memory  */
end_comment

begin_function_decl
name|isc_result_t
name|dns_rdata_totext
parameter_list|(
name|dns_rdata_t
modifier|*
name|rdata
parameter_list|,
name|dns_name_t
modifier|*
name|origin
parameter_list|,
name|isc_buffer_t
modifier|*
name|target
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Convert 'rdata' into text format, storing the result in 'target'.  * The text will consist of a single line, with fields separated by  * single spaces.  *  * Notes:  *\li	If 'origin' is not NULL, then any names in the rdata that are  *	subdomains of 'origin' will be made relative it.  *  *\li	XXX Do we *really* want to support 'origin'?  I'm inclined towards "no"  *	at the moment.  *  * Requires:  *  *\li	'rdata' is a valid, non-empty rdata  *  *\li	'origin' is NULL, or is a valid name  *  *\li	'target' is a valid text buffer  *  * Ensures,  *	if the result is success:  *  *	\li	The used space in target is updated.  *  * Returns:  *\li	Success  *\li	Any non-success status from dns_name_totext()  *\li	Resource Limit: Not enough space  */
end_comment

begin_function_decl
name|isc_result_t
name|dns_rdata_tofmttext
parameter_list|(
name|dns_rdata_t
modifier|*
name|rdata
parameter_list|,
name|dns_name_t
modifier|*
name|origin
parameter_list|,
name|unsigned
name|int
name|flags
parameter_list|,
name|unsigned
name|int
name|width
parameter_list|,
name|char
modifier|*
name|linebreak
parameter_list|,
name|isc_buffer_t
modifier|*
name|target
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Like dns_rdata_totext, but do formatted output suitable for  * database dumps.  This is intended for use by dns_db_dump();  * library users are discouraged from calling it directly.  *  * If (flags& #DNS_STYLEFLAG_MULTILINE) != 0, attempt to stay  * within 'width' by breaking the text into multiple lines.  * The string 'linebreak' is inserted between lines, and parentheses  * are added when necessary.  Because RRs contain unbreakable elements  * such as domain names whose length is variable, unpredictable, and  * potentially large, there is no guarantee that the lines will  * not exceed 'width' anyway.  *  * If (flags& #DNS_STYLEFLAG_MULTILINE) == 0, the rdata is always  * printed as a single line, and no parentheses are used.  * The 'width' and 'linebreak' arguments are ignored.  *  * If (flags& #DNS_STYLEFLAG_COMMENT) != 0, output explanatory  * comments next to things like the SOA timer fields.  Some  * comments (e.g., the SOA ones) are only printed when multiline  * output is selected.  */
end_comment

begin_function_decl
name|isc_result_t
name|dns_rdata_fromstruct
parameter_list|(
name|dns_rdata_t
modifier|*
name|rdata
parameter_list|,
name|dns_rdataclass_t
name|rdclass
parameter_list|,
name|dns_rdatatype_t
name|type
parameter_list|,
name|void
modifier|*
name|source
parameter_list|,
name|isc_buffer_t
modifier|*
name|target
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Convert the C structure representation of an rdata into uncompressed wire  * format in 'target'.  *  * XXX  Should we have a 'size' parameter as a sanity check on target?  *  * Requires:  *  *\li	'rdclass' and 'type' are valid.  *  *\li	'source' points to a valid C struct for the class and type.  *  *\li	'target' is a valid buffer.  *  *\li	All structure pointers to memory blocks should be NULL if their  *	corresponding length values are zero.  *  * Ensures,  *	if result is success:  *	\li 	If 'rdata' is not NULL, it is attached to the target.  *  *	\li	The used space in 'target' is updated.  *  * Result:  *\li	Success  *\li	Various 'Bad Form' class failures depending on class and type  *\li	Resource Limit: Not enough space  */
end_comment

begin_function_decl
name|isc_result_t
name|dns_rdata_tostruct
parameter_list|(
name|dns_rdata_t
modifier|*
name|rdata
parameter_list|,
name|void
modifier|*
name|target
parameter_list|,
name|isc_mem_t
modifier|*
name|mctx
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Convert an rdata into its C structure representation.  *  * If 'mctx' is NULL then 'rdata' must persist while 'target' is being used.  *  * If 'mctx' is non NULL then memory will be allocated if required.  *  * Requires:  *  *\li	'rdata' is a valid, non-empty rdata.  *  *\li	'target' to point to a valid pointer for the type and class.  *  * Result:  *\li	Success  *\li	Resource Limit: Not enough memory  */
end_comment

begin_function_decl
name|void
name|dns_rdata_freestruct
parameter_list|(
name|void
modifier|*
name|source
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Free dynamic memory attached to 'source' (if any).  *  * Requires:  *  *\li	'source' to point to the structure previously filled in by  *	dns_rdata_tostruct().  */
end_comment

begin_function_decl
name|isc_boolean_t
name|dns_rdatatype_ismeta
parameter_list|(
name|dns_rdatatype_t
name|type
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Return true iff the rdata type 'type' is a meta-type  * like ANY or AXFR.  */
end_comment

begin_function_decl
name|isc_boolean_t
name|dns_rdatatype_issingleton
parameter_list|(
name|dns_rdatatype_t
name|type
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Return true iff the rdata type 'type' is a singleton type,  * like CNAME or SOA.  *  * Requires:  * \li	'type' is a valid rdata type.  *  */
end_comment

begin_function_decl
name|isc_boolean_t
name|dns_rdataclass_ismeta
parameter_list|(
name|dns_rdataclass_t
name|rdclass
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Return true iff the rdata class 'rdclass' is a meta-class  * like ANY or NONE.  */
end_comment

begin_function_decl
name|isc_boolean_t
name|dns_rdatatype_isdnssec
parameter_list|(
name|dns_rdatatype_t
name|type
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Return true iff 'type' is one of the DNSSEC  * rdata types that may exist alongside a CNAME record.  *  * Requires:  * \li	'type' is a valid rdata type.  */
end_comment

begin_function_decl
name|isc_boolean_t
name|dns_rdatatype_iszonecutauth
parameter_list|(
name|dns_rdatatype_t
name|type
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Return true iff rdata of type 'type' is considered authoritative  * data (not glue) in the NSEC chain when it occurs in the parent zone  * at a zone cut.  *  * Requires:  * \li	'type' is a valid rdata type.  *  */
end_comment

begin_function_decl
name|isc_boolean_t
name|dns_rdatatype_isknown
parameter_list|(
name|dns_rdatatype_t
name|type
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Return true iff the rdata type 'type' is known.  *  * Requires:  * \li	'type' is a valid rdata type.  *  */
end_comment

begin_function_decl
name|isc_result_t
name|dns_rdata_additionaldata
parameter_list|(
name|dns_rdata_t
modifier|*
name|rdata
parameter_list|,
name|dns_additionaldatafunc_t
name|add
parameter_list|,
name|void
modifier|*
name|arg
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Call 'add' for each name and type from 'rdata' which is subject to  * additional section processing.  *  * Requires:  *  *\li	'rdata' is a valid, non-empty rdata.  *  *\li	'add' is a valid dns_additionalfunc_t.  *  * Ensures:  *  *\li	If successful, then add() will have been called for each name  *	and type subject to additional section processing.  *  *\li	If add() returns something other than #ISC_R_SUCCESS, that result  *	will be returned as the result of dns_rdata_additionaldata().  *  * Returns:  *  *\li	ISC_R_SUCCESS  *  *\li	Many other results are possible if not successful.  */
end_comment

begin_function_decl
name|isc_result_t
name|dns_rdata_digest
parameter_list|(
name|dns_rdata_t
modifier|*
name|rdata
parameter_list|,
name|dns_digestfunc_t
name|digest
parameter_list|,
name|void
modifier|*
name|arg
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Send 'rdata' in DNSSEC canonical form to 'digest'.  *  * Note:  *\li	'digest' may be called more than once by dns_rdata_digest().  The  *	concatenation of all the regions, in the order they were given  *	to 'digest', will be the DNSSEC canonical form of 'rdata'.  *  * Requires:  *  *\li	'rdata' is a valid, non-empty rdata.  *  *\li	'digest' is a valid dns_digestfunc_t.  *  * Ensures:  *  *\li	If successful, then all of the rdata's data has been sent, in  *	DNSSEC canonical form, to 'digest'.  *  *\li	If digest() returns something other than ISC_R_SUCCESS, that result  *	will be returned as the result of dns_rdata_digest().  *  * Returns:  *  *\li	ISC_R_SUCCESS  *  *\li	Many other results are possible if not successful.  */
end_comment

begin_function_decl
name|isc_boolean_t
name|dns_rdatatype_questiononly
parameter_list|(
name|dns_rdatatype_t
name|type
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Return true iff rdata of type 'type' can only appear in the question  * section of a properly formatted message.  *  * Requires:  * \li	'type' is a valid rdata type.  *  */
end_comment

begin_function_decl
name|isc_boolean_t
name|dns_rdatatype_notquestion
parameter_list|(
name|dns_rdatatype_t
name|type
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Return true iff rdata of type 'type' can not appear in the question  * section of a properly formatted message.  *  * Requires:  * \li	'type' is a valid rdata type.  *  */
end_comment

begin_function_decl
name|isc_boolean_t
name|dns_rdatatype_atparent
parameter_list|(
name|dns_rdatatype_t
name|type
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Return true iff rdata of type 'type' should appear at the parent of  * a zone cut.  *  * Requires:  * \li	'type' is a valid rdata type.  *  */
end_comment

begin_function_decl
name|unsigned
name|int
name|dns_rdatatype_attributes
parameter_list|(
name|dns_rdatatype_t
name|rdtype
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Return attributes for the given type.  *  * Requires:  *\li	'rdtype' are known.  *  * Returns:  *\li	a bitmask consisting of the following flags.  */
end_comment

begin_comment
comment|/*% only one may exist for a name */
end_comment

begin_define
define|#
directive|define
name|DNS_RDATATYPEATTR_SINGLETON
value|0x00000001U
end_define

begin_comment
comment|/*% requires no other data be present */
end_comment

begin_define
define|#
directive|define
name|DNS_RDATATYPEATTR_EXCLUSIVE
value|0x00000002U
end_define

begin_comment
comment|/*% Is a meta type */
end_comment

begin_define
define|#
directive|define
name|DNS_RDATATYPEATTR_META
value|0x00000004U
end_define

begin_comment
comment|/*% Is a DNSSEC type, like RRSIG or NSEC */
end_comment

begin_define
define|#
directive|define
name|DNS_RDATATYPEATTR_DNSSEC
value|0x00000008U
end_define

begin_comment
comment|/*% Is a zone cut authority type */
end_comment

begin_define
define|#
directive|define
name|DNS_RDATATYPEATTR_ZONECUTAUTH
value|0x00000010U
end_define

begin_comment
comment|/*% Is reserved (unusable) */
end_comment

begin_define
define|#
directive|define
name|DNS_RDATATYPEATTR_RESERVED
value|0x00000020U
end_define

begin_comment
comment|/*% Is an unknown type */
end_comment

begin_define
define|#
directive|define
name|DNS_RDATATYPEATTR_UNKNOWN
value|0x00000040U
end_define

begin_comment
comment|/*% Is META, and can only be in a question section */
end_comment

begin_define
define|#
directive|define
name|DNS_RDATATYPEATTR_QUESTIONONLY
value|0x00000080U
end_define

begin_comment
comment|/*% is META, and can NOT be in a question section */
end_comment

begin_define
define|#
directive|define
name|DNS_RDATATYPEATTR_NOTQUESTION
value|0x00000100U
end_define

begin_comment
comment|/*% Is present at zone cuts in the parent, not the child */
end_comment

begin_define
define|#
directive|define
name|DNS_RDATATYPEATTR_ATPARENT
value|0x00000200U
end_define

begin_function_decl
name|dns_rdatatype_t
name|dns_rdata_covers
parameter_list|(
name|dns_rdata_t
modifier|*
name|rdata
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Return the rdatatype that this type covers.  *  * Requires:  *\li	'rdata' is a valid, non-empty rdata.  *  *\li	'rdata' is a type that covers other rdata types.  *  * Returns:  *\li	The type covered.  */
end_comment

begin_function_decl
name|isc_boolean_t
name|dns_rdata_checkowner
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
name|isc_boolean_t
name|wildcard
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Returns whether this is a valid ownername for this<type,class>.  * If wildcard is true allow the first label to be a wildcard if  * appropriate.  *  * Requires:  *	'name' is a valid name.  */
end_comment

begin_function_decl
name|isc_boolean_t
name|dns_rdata_checknames
parameter_list|(
name|dns_rdata_t
modifier|*
name|rdata
parameter_list|,
name|dns_name_t
modifier|*
name|owner
parameter_list|,
name|dns_name_t
modifier|*
name|bad
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Returns whether 'rdata' contains valid domain names.  The checks are  * sensitive to the owner name.  *  * If 'bad' is non-NULL and a domain name fails the check the  * the offending name will be return in 'bad' by cloning from  * the 'rdata' contents.  *  * Requires:  *	'rdata' to be valid.  *	'owner' to be valid.  *	'bad'	to be NULL or valid.  */
end_comment

begin_macro
name|ISC_LANG_ENDDECLS
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* DNS_RDATA_H */
end_comment

end_unit

