begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * ng_parse.h  *  * Copyright (c) 1999 Whistle Communications, Inc.  * All rights reserved.  *   * Subject to the following obligations and disclaimer of warranty, use and  * redistribution of this software, in source or object code forms, with or  * without modifications are expressly permitted by Whistle Communications;  * provided, however, that:  * 1. Any and all reproductions of the source or object code must include the  *    copyright notice above and the following disclaimer of warranties; and  * 2. No rights are granted, in any manner or form, to use Whistle  *    Communications, Inc. trademarks, including the mark "WHISTLE  *    COMMUNICATIONS" on advertising, endorsements, or otherwise except as  *    such appears in the above copyright notice or in the software.  *   * THIS SOFTWARE IS BEING PROVIDED BY WHISTLE COMMUNICATIONS "AS IS", AND  * TO THE MAXIMUM EXTENT PERMITTED BY LAW, WHISTLE COMMUNICATIONS MAKES NO  * REPRESENTATIONS OR WARRANTIES, EXPRESS OR IMPLIED, REGARDING THIS SOFTWARE,  * INCLUDING WITHOUT LIMITATION, ANY AND ALL IMPLIED WARRANTIES OF  * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE, OR NON-INFRINGEMENT.  * WHISTLE COMMUNICATIONS DOES NOT WARRANT, GUARANTEE, OR MAKE ANY  * REPRESENTATIONS REGARDING THE USE OF, OR THE RESULTS OF THE USE OF THIS  * SOFTWARE IN TERMS OF ITS CORRECTNESS, ACCURACY, RELIABILITY OR OTHERWISE.  * IN NO EVENT SHALL WHISTLE COMMUNICATIONS BE LIABLE FOR ANY DAMAGES  * RESULTING FROM OR ARISING OUT OF ANY USE OF THIS SOFTWARE, INCLUDING  * WITHOUT LIMITATION, ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY,  * PUNITIVE, OR CONSEQUENTIAL DAMAGES, PROCUREMENT OF SUBSTITUTE GOODS OR  * SERVICES, LOSS OF USE, DATA OR PROFITS, HOWEVER CAUSED AND UNDER ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF WHISTLE COMMUNICATIONS IS ADVISED OF THE POSSIBILITY  * OF SUCH DAMAGE.  *  * Author: Archie Cobbs<archie@whistle.com>  *  * $Whistle: ng_parse.h,v 1.2 1999/11/29 01:43:48 archie Exp $  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_NETGRAPH_PARSE_H_
end_ifndef

begin_define
define|#
directive|define
name|_NETGRAPH_PARSE_H_
end_define

begin_comment
comment|/*    This defines a library of routines for converting between various C   language types in binary form and ASCII strings.  Types are user   definable.  Several pre-defined types are supplied, for some   common C types: structures, variable and fixed length arrays,   integer types, variable and fixed length strings, IP addresses,   etc.    Syntax   ------      Structures:        '{' [<name>=<value> ... ] '}'        Omitted fields have their default values by implication.       The order in which the fields are specified does not matter.      Arrays:        '[' [ [index=]<value> ... ] ']'        Element value may be specified with or without the "<index>=" prefix;       If omitted, the index after the previous element is used.       Omitted fields have their default values by implication.      Strings:        "foo bar blah\r\n"        That is, strings are specified just like C strings. The usual       backslash escapes are accepted.     Other simple types have their obvious ASCII forms.    Example   -------        Structure			Binary (big endian)       ---------			-------------------        struct foo { 	struct in_addr ip;  	03 03 03 03 	int bar;		00 00 00 00 	u_char num;	  	02 00 	short ary[0];	  	00 05 00 00 00 0a       };        ASCII form:	"{ ip=3.3.3.3 num=3 ary=[ 5 2=10 ] }"      Note that omitted fields or array elements get their default values     ("bar" and ary[2]), and that the alignment is handled automatically     (the extra 00 byte after "num").    To define a type, you can define it as a sub-type of a predefined   type, overriding some of the predefined type's methods and/or its   alignment, or define your own syntax, with the restriction that   the ASCII representation must not contain any whitespace or these   characters: { } [ ] = "  */
end_comment

begin_comment
comment|/************************************************************************ 			METHODS REQUIRED BY A TYPE  ************************************************************************/
end_comment

begin_comment
comment|/*  * Three methods are required for a type. These may be given explicitly  * or, if NULL, inherited from the super-type.  */
end_comment

begin_struct_decl
struct_decl|struct
name|ng_parse_type
struct_decl|;
end_struct_decl

begin_comment
comment|/*  * Convert ASCII to binary according to the supplied type.  *  * The ASCII characters begin at offset *off in 'string'.  The binary  * representation is put into 'buf', which has at least *buflen bytes.  * 'start' points to the first byte output by ng_parse() (ie, start<= buf).  *  * Upon return, *buflen contains the length of the new binary data, and  * *off is updated to point just past the end of the parsed range of  * characters, or, in the case of an error, to the offending character(s).  *  * Return values:  *	0		Success; *buflen holds the length of the data  *			and *off points just past the last char parsed.  *	EALREADY	Field specified twice  *	ENOENT		Unknown field  *	E2BIG		Array or character string overflow  *	ERANGE		Output was longer than *buflen bytes  *	EINVAL		Parse failure or other invalid content  *	ENOMEM		Out of memory  *	EOPNOTSUPP	Mandatory array/structure element missing  */
end_comment

begin_typedef
typedef|typedef
name|int
name|ng_parse_t
parameter_list|(
specifier|const
name|struct
name|ng_parse_type
modifier|*
name|type
parameter_list|,
specifier|const
name|char
modifier|*
name|string
parameter_list|,
name|int
modifier|*
name|off
parameter_list|,
specifier|const
name|u_char
modifier|*
name|start
parameter_list|,
name|u_char
modifier|*
name|buf
parameter_list|,
name|int
modifier|*
name|buflen
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/*  * Convert binary to ASCII according to the supplied type.  *  * The results are put into 'buf', which is at least buflen bytes long.  * *off points to the current byte in 'data' and should be updated  * before return to point just past the last byte unparsed.  *  * Returns:  *	0		Success  *	ERANGE		Output was longer than buflen bytes  */
end_comment

begin_typedef
typedef|typedef
name|int
name|ng_unparse_t
parameter_list|(
specifier|const
name|struct
name|ng_parse_type
modifier|*
name|type
parameter_list|,
specifier|const
name|u_char
modifier|*
name|data
parameter_list|,
name|int
modifier|*
name|off
parameter_list|,
name|char
modifier|*
name|buf
parameter_list|,
name|int
name|buflen
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/*  * Compute the default value according to the supplied type.  *  * Store the result in 'buf', which is at least *buflen bytes long.  * Upon return *buflen contains the length of the output.  *  * Returns:  *	0		Success  *	ERANGE		Output was longer than *buflen bytes  *	EOPNOTSUPP	Default value is not specified for this type  */
end_comment

begin_typedef
typedef|typedef
name|int
name|ng_getDefault_t
parameter_list|(
specifier|const
name|struct
name|ng_parse_type
modifier|*
name|type
parameter_list|,
specifier|const
name|u_char
modifier|*
name|start
parameter_list|,
name|u_char
modifier|*
name|buf
parameter_list|,
name|int
modifier|*
name|buflen
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/*  * Return the alignment requirement of this type.  Zero is same as one.  */
end_comment

begin_typedef
typedef|typedef
name|int
name|ng_getAlign_t
parameter_list|(
specifier|const
name|struct
name|ng_parse_type
modifier|*
name|type
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/************************************************************************ 			TYPE DEFINITION  ************************************************************************/
end_comment

begin_comment
comment|/*  * This structure describes a type, which may be a sub-type of another  * type by pointing to it with 'supertype' and omitting one or more methods.  */
end_comment

begin_struct
struct|struct
name|ng_parse_type
block|{
specifier|const
name|struct
name|ng_parse_type
modifier|*
name|supertype
decl_stmt|;
comment|/* super-type, if any */
specifier|const
name|void
modifier|*
name|info
decl_stmt|;
comment|/* type-specific info */
name|void
modifier|*
name|private
decl_stmt|;
comment|/* client private info */
name|ng_parse_t
modifier|*
name|parse
decl_stmt|;
comment|/* parse method */
name|ng_unparse_t
modifier|*
name|unparse
decl_stmt|;
comment|/* unparse method */
name|ng_getDefault_t
modifier|*
name|getDefault
decl_stmt|;
comment|/* get default value method */
name|ng_getAlign_t
modifier|*
name|getAlign
decl_stmt|;
comment|/* get alignment */
block|}
struct|;
end_struct

begin_comment
comment|/************************************************************************ 			PRE-DEFINED TYPES  ************************************************************************/
end_comment

begin_comment
comment|/*  * Structures  *  *   Default value:		Determined on a per-field basis  *   Additional info:		struct ng_parse_struct_info *  */
end_comment

begin_decl_stmt
specifier|extern
specifier|const
name|struct
name|ng_parse_type
name|ng_parse_struct_type
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Each field has a name, type, and optional alignment override. If the    override is non-zero, the alignment is determined from the field type.    Note: add an extra struct ng_parse_struct_field with name == NULL    to indicate the end of the list. */
end_comment

begin_struct
struct|struct
name|ng_parse_struct_info
block|{
struct|struct
name|ng_parse_struct_field
block|{
specifier|const
name|char
modifier|*
name|name
decl_stmt|;
comment|/* field name */
specifier|const
name|struct
name|ng_parse_type
modifier|*
name|type
decl_stmt|;
comment|/* field type */
name|int
name|alignment
decl_stmt|;
comment|/* override alignment */
block|}
name|fields
index|[
literal|0
index|]
struct|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Fixed length arrays  *  *   Default value:		See below  *   Additional info:		struct ng_parse_fixedarray_info *  */
end_comment

begin_decl_stmt
specifier|extern
specifier|const
name|struct
name|ng_parse_type
name|ng_parse_fixedarray_type
decl_stmt|;
end_decl_stmt

begin_typedef
typedef|typedef
name|int
name|ng_parse_array_getLength_t
parameter_list|(
specifier|const
name|struct
name|ng_parse_type
modifier|*
name|type
parameter_list|,
specifier|const
name|u_char
modifier|*
name|start
parameter_list|,
specifier|const
name|u_char
modifier|*
name|buf
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|int
name|ng_parse_array_getDefault_t
parameter_list|(
specifier|const
name|struct
name|ng_parse_type
modifier|*
name|type
parameter_list|,
name|int
name|index
parameter_list|,
specifier|const
name|u_char
modifier|*
name|start
parameter_list|,
name|u_char
modifier|*
name|buf
parameter_list|,
name|int
modifier|*
name|buflen
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/* The 'getDefault' method may be NULL, in which case the default value    is computed from the element type.  If not, it should fill in the    default value at *buf (having size *buflen) and update *buflen to the    length of the filled-in value before return. */
end_comment

begin_struct
struct|struct
name|ng_parse_fixedarray_info
block|{
specifier|const
name|struct
name|ng_parse_type
modifier|*
name|elementType
decl_stmt|;
name|int
name|length
decl_stmt|;
name|ng_parse_array_getDefault_t
modifier|*
name|getDefault
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Variable length arrays  *  *   Default value:		Same as with fixed length arrays  *   Additional info:		struct ng_parse_array_info *  */
end_comment

begin_decl_stmt
specifier|extern
specifier|const
name|struct
name|ng_parse_type
name|ng_parse_array_type
decl_stmt|;
end_decl_stmt

begin_struct
struct|struct
name|ng_parse_array_info
block|{
specifier|const
name|struct
name|ng_parse_type
modifier|*
name|elementType
decl_stmt|;
name|ng_parse_array_getLength_t
modifier|*
name|getLength
decl_stmt|;
name|ng_parse_array_getDefault_t
modifier|*
name|getDefault
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Arbitrary length strings  *  *   Default value:		Empty string  *   Additional info:		None required  */
end_comment

begin_decl_stmt
specifier|extern
specifier|const
name|struct
name|ng_parse_type
name|ng_parse_string_type
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * Bounded length strings.  These are strings that have a fixed-size  * buffer, and always include a terminating NUL character.  *  *   Default value:		Empty string  *   Additional info:		struct ng_parse_fixedsstring_info *  */
end_comment

begin_decl_stmt
specifier|extern
specifier|const
name|struct
name|ng_parse_type
name|ng_parse_fixedstring_type
decl_stmt|;
end_decl_stmt

begin_struct
struct|struct
name|ng_parse_fixedsstring_info
block|{
name|int
name|bufSize
decl_stmt|;
comment|/* size of buffer (including NUL) */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Some commonly used bounded length string types  */
end_comment

begin_decl_stmt
specifier|extern
specifier|const
name|struct
name|ng_parse_type
name|ng_parse_nodebuf_type
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* NG_NODELEN + 1 */
end_comment

begin_decl_stmt
specifier|extern
specifier|const
name|struct
name|ng_parse_type
name|ng_parse_hookbuf_type
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* NG_HOOKLEN + 1 */
end_comment

begin_decl_stmt
specifier|extern
specifier|const
name|struct
name|ng_parse_type
name|ng_parse_pathbuf_type
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* NG_PATHLEN + 1 */
end_comment

begin_decl_stmt
specifier|extern
specifier|const
name|struct
name|ng_parse_type
name|ng_parse_typebuf_type
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* NG_TYPELEN + 1 */
end_comment

begin_decl_stmt
specifier|extern
specifier|const
name|struct
name|ng_parse_type
name|ng_parse_cmdbuf_type
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* NG_CMDSTRLEN + 1 */
end_comment

begin_comment
comment|/*  * Integer types  *  *   Default value:		0  *   Additional info:		None required  */
end_comment

begin_decl_stmt
specifier|extern
specifier|const
name|struct
name|ng_parse_type
name|ng_parse_int8_type
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|struct
name|ng_parse_type
name|ng_parse_int16_type
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|struct
name|ng_parse_type
name|ng_parse_int32_type
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|struct
name|ng_parse_type
name|ng_parse_int64_type
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * IP address type  *  *   Default value:		0.0.0.0  *   Additional info:		None required  */
end_comment

begin_decl_stmt
specifier|extern
specifier|const
name|struct
name|ng_parse_type
name|ng_parse_ipaddr_type
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * Variable length byte array. The bytes are displayed in hex.  * ASCII form may be either an array of bytes or a string constant,  * in which case the array is zero-filled after the string bytes.  *  *   Default value:		All bytes are zero  *   Additional info:		ng_parse_array_getLength_t *  */
end_comment

begin_decl_stmt
specifier|extern
specifier|const
name|struct
name|ng_parse_type
name|ng_parse_bytearray_type
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * Netgraph control message type  *  *   Default value:		All fields zero  *   Additional info:		None required  */
end_comment

begin_decl_stmt
specifier|extern
specifier|const
name|struct
name|ng_parse_type
name|ng_parse_ng_mesg_type
decl_stmt|;
end_decl_stmt

begin_comment
comment|/************************************************************************ 		CONVERSTION AND PARSING ROUTINES  ************************************************************************/
end_comment

begin_comment
comment|/* Tokens for parsing structs and arrays */
end_comment

begin_enum
enum|enum
name|ng_parse_token
block|{
name|T_LBRACE
block|,
comment|/* '{' */
name|T_RBRACE
block|,
comment|/* '}' */
name|T_LBRACKET
block|,
comment|/* '[' */
name|T_RBRACKET
block|,
comment|/* ']' */
name|T_EQUALS
block|,
comment|/* '=' */
name|T_STRING
block|,
comment|/* string in double quotes */
name|T_ERROR
block|,
comment|/* error parsing string in double quotes */
name|T_WORD
block|,
comment|/* anything else containing no whitespace */
name|T_EOF
block|,
comment|/* end of string reached */
block|}
enum|;
end_enum

begin_comment
comment|/*  * See typedef ng_parse_t for definition  */
end_comment

begin_function_decl
specifier|extern
name|int
name|ng_parse
parameter_list|(
specifier|const
name|struct
name|ng_parse_type
modifier|*
name|type
parameter_list|,
specifier|const
name|char
modifier|*
name|string
parameter_list|,
name|int
modifier|*
name|off
parameter_list|,
name|u_char
modifier|*
name|buf
parameter_list|,
name|int
modifier|*
name|buflen
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * See typedef ng_unparse_t for definition (*off assumed to be zero).  */
end_comment

begin_function_decl
specifier|extern
name|int
name|ng_unparse
parameter_list|(
specifier|const
name|struct
name|ng_parse_type
modifier|*
name|type
parameter_list|,
specifier|const
name|u_char
modifier|*
name|data
parameter_list|,
name|char
modifier|*
name|buf
parameter_list|,
name|int
name|buflen
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * See typedef ng_getDefault_t for definition  */
end_comment

begin_function_decl
specifier|extern
name|int
name|ng_parse_getDefault
parameter_list|(
specifier|const
name|struct
name|ng_parse_type
modifier|*
name|type
parameter_list|,
name|u_char
modifier|*
name|buf
parameter_list|,
name|int
modifier|*
name|buflen
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Parse a token: '*startp' is the offset to start looking.  Upon  * successful return, '*startp' equals the beginning of the token  * and '*lenp' the length.  If error, '*startp' points at the  * offending character(s).  */
end_comment

begin_function_decl
specifier|extern
name|enum
name|ng_parse_token
name|ng_parse_get_token
parameter_list|(
specifier|const
name|char
modifier|*
name|s
parameter_list|,
name|int
modifier|*
name|startp
parameter_list|,
name|int
modifier|*
name|lenp
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Like above, but specifically for getting a string token and returning  * the string value.  The string token must be enclosed in double quotes  * and the normal C backslash escapes are recognized.  The caller must  * eventually free() the returned result.  Returns NULL if token is  * not a string token, or parse or other error.  */
end_comment

begin_function_decl
specifier|extern
name|char
modifier|*
name|ng_get_string_token
parameter_list|(
specifier|const
name|char
modifier|*
name|s
parameter_list|,
name|int
modifier|*
name|startp
parameter_list|,
name|int
modifier|*
name|lenp
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Convert a raw string into a doubly-quoted string including any  * necessary backslash escapes.  Caller must free the result.  * Returns NULL if ENOMEM.  */
end_comment

begin_function_decl
specifier|extern
name|char
modifier|*
name|ng_encode_string
parameter_list|(
specifier|const
name|char
modifier|*
name|s
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _NETGRAPH_PARSE_H_ */
end_comment

end_unit

