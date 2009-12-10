begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Copyright (c) 1998, 1999, 2000 Thai Open Source Software Center Ltd    See the file COPYING for copying permission. */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|Expat_INCLUDED
end_ifndef

begin_define
define|#
directive|define
name|Expat_INCLUDED
value|1
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|__VMS
end_ifdef

begin_comment
comment|/*      0        1         2         3      0        1         2         3         1234567890123456789012345678901     1234567890123456789012345678901 */
end_comment

begin_define
define|#
directive|define
name|XML_SetProcessingInstructionHandler
value|XML_SetProcessingInstrHandler
end_define

begin_define
define|#
directive|define
name|XML_SetUnparsedEntityDeclHandler
value|XML_SetUnparsedEntDeclHandler
end_define

begin_define
define|#
directive|define
name|XML_SetStartNamespaceDeclHandler
value|XML_SetStartNamespcDeclHandler
end_define

begin_define
define|#
directive|define
name|XML_SetExternalEntityRefHandlerArg
value|XML_SetExternalEntRefHandlerArg
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_include
include|#
directive|include
file|"expat_external.h"
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
struct_decl|struct
name|XML_ParserStruct
struct_decl|;
typedef|typedef
name|struct
name|XML_ParserStruct
modifier|*
name|XML_Parser
typedef|;
comment|/* Should this be defined using stdbool.h when C99 is available? */
typedef|typedef
name|unsigned
name|char
name|XML_Bool
typedef|;
define|#
directive|define
name|XML_TRUE
value|((XML_Bool) 1)
define|#
directive|define
name|XML_FALSE
value|((XML_Bool) 0)
comment|/* The XML_Status enum gives the possible return values for several    API functions.  The preprocessor #defines are included so this    stanza can be added to code that still needs to support older    versions of Expat 1.95.x:     #ifndef XML_STATUS_OK    #define XML_STATUS_OK    1    #define XML_STATUS_ERROR 0    #endif     Otherwise, the #define hackery is quite ugly and would have been    dropped. */
enum|enum
name|XML_Status
block|{
name|XML_STATUS_ERROR
init|=
literal|0
block|,
define|#
directive|define
name|XML_STATUS_ERROR
value|XML_STATUS_ERROR
name|XML_STATUS_OK
init|=
literal|1
block|,
define|#
directive|define
name|XML_STATUS_OK
value|XML_STATUS_OK
name|XML_STATUS_SUSPENDED
init|=
literal|2
define|#
directive|define
name|XML_STATUS_SUSPENDED
value|XML_STATUS_SUSPENDED
block|}
enum|;
enum|enum
name|XML_Error
block|{
name|XML_ERROR_NONE
block|,
name|XML_ERROR_NO_MEMORY
block|,
name|XML_ERROR_SYNTAX
block|,
name|XML_ERROR_NO_ELEMENTS
block|,
name|XML_ERROR_INVALID_TOKEN
block|,
name|XML_ERROR_UNCLOSED_TOKEN
block|,
name|XML_ERROR_PARTIAL_CHAR
block|,
name|XML_ERROR_TAG_MISMATCH
block|,
name|XML_ERROR_DUPLICATE_ATTRIBUTE
block|,
name|XML_ERROR_JUNK_AFTER_DOC_ELEMENT
block|,
name|XML_ERROR_PARAM_ENTITY_REF
block|,
name|XML_ERROR_UNDEFINED_ENTITY
block|,
name|XML_ERROR_RECURSIVE_ENTITY_REF
block|,
name|XML_ERROR_ASYNC_ENTITY
block|,
name|XML_ERROR_BAD_CHAR_REF
block|,
name|XML_ERROR_BINARY_ENTITY_REF
block|,
name|XML_ERROR_ATTRIBUTE_EXTERNAL_ENTITY_REF
block|,
name|XML_ERROR_MISPLACED_XML_PI
block|,
name|XML_ERROR_UNKNOWN_ENCODING
block|,
name|XML_ERROR_INCORRECT_ENCODING
block|,
name|XML_ERROR_UNCLOSED_CDATA_SECTION
block|,
name|XML_ERROR_EXTERNAL_ENTITY_HANDLING
block|,
name|XML_ERROR_NOT_STANDALONE
block|,
name|XML_ERROR_UNEXPECTED_STATE
block|,
name|XML_ERROR_ENTITY_DECLARED_IN_PE
block|,
name|XML_ERROR_FEATURE_REQUIRES_XML_DTD
block|,
name|XML_ERROR_CANT_CHANGE_FEATURE_ONCE_PARSING
block|,
comment|/* Added in 1.95.7. */
name|XML_ERROR_UNBOUND_PREFIX
block|,
comment|/* Added in 1.95.8. */
name|XML_ERROR_UNDECLARING_PREFIX
block|,
name|XML_ERROR_INCOMPLETE_PE
block|,
name|XML_ERROR_XML_DECL
block|,
name|XML_ERROR_TEXT_DECL
block|,
name|XML_ERROR_PUBLICID
block|,
name|XML_ERROR_SUSPENDED
block|,
name|XML_ERROR_NOT_SUSPENDED
block|,
name|XML_ERROR_ABORTED
block|,
name|XML_ERROR_FINISHED
block|,
name|XML_ERROR_SUSPEND_PE
block|,
comment|/* Added in 2.0. */
name|XML_ERROR_RESERVED_PREFIX_XML
block|,
name|XML_ERROR_RESERVED_PREFIX_XMLNS
block|,
name|XML_ERROR_RESERVED_NAMESPACE_URI
block|}
enum|;
enum|enum
name|XML_Content_Type
block|{
name|XML_CTYPE_EMPTY
init|=
literal|1
block|,
name|XML_CTYPE_ANY
block|,
name|XML_CTYPE_MIXED
block|,
name|XML_CTYPE_NAME
block|,
name|XML_CTYPE_CHOICE
block|,
name|XML_CTYPE_SEQ
block|}
enum|;
enum|enum
name|XML_Content_Quant
block|{
name|XML_CQUANT_NONE
block|,
name|XML_CQUANT_OPT
block|,
name|XML_CQUANT_REP
block|,
name|XML_CQUANT_PLUS
block|}
enum|;
comment|/* If type == XML_CTYPE_EMPTY or XML_CTYPE_ANY, then quant will be    XML_CQUANT_NONE, and the other fields will be zero or NULL.    If type == XML_CTYPE_MIXED, then quant will be NONE or REP and    numchildren will contain number of elements that may be mixed in    and children point to an array of XML_Content cells that will be    all of XML_CTYPE_NAME type with no quantification.     If type == XML_CTYPE_NAME, then the name points to the name, and    the numchildren field will be zero and children will be NULL. The    quant fields indicates any quantifiers placed on the name.     CHOICE and SEQ will have name NULL, the number of children in    numchildren and children will point, recursively, to an array    of XML_Content cells.     The EMPTY, ANY, and MIXED types will only occur at top level. */
typedef|typedef
name|struct
name|XML_cp
name|XML_Content
typedef|;
struct|struct
name|XML_cp
block|{
name|enum
name|XML_Content_Type
name|type
decl_stmt|;
name|enum
name|XML_Content_Quant
name|quant
decl_stmt|;
name|XML_Char
modifier|*
name|name
decl_stmt|;
name|unsigned
name|int
name|numchildren
decl_stmt|;
name|XML_Content
modifier|*
name|children
decl_stmt|;
block|}
struct|;
comment|/* This is called for an element declaration. See above for    description of the model argument. It's the caller's responsibility    to free model when finished with it. */
typedef|typedef
name|void
function_decl|(
name|XMLCALL
modifier|*
name|XML_ElementDeclHandler
function_decl|)
parameter_list|(
name|void
modifier|*
name|userData
parameter_list|,
specifier|const
name|XML_Char
modifier|*
name|name
parameter_list|,
name|XML_Content
modifier|*
name|model
parameter_list|)
function_decl|;
name|XMLPARSEAPI
argument_list|(
argument|void
argument_list|)
name|XML_SetElementDeclHandler
argument_list|(
argument|XML_Parser parser
argument_list|,
argument|XML_ElementDeclHandler eldecl
argument_list|)
empty_stmt|;
comment|/* The Attlist declaration handler is called for *each* attribute. So    a single Attlist declaration with multiple attributes declared will    generate multiple calls to this handler. The "default" parameter    may be NULL in the case of the "#IMPLIED" or "#REQUIRED"    keyword. The "isrequired" parameter will be true and the default    value will be NULL in the case of "#REQUIRED". If "isrequired" is    true and default is non-NULL, then this is a "#FIXED" default. */
typedef|typedef
name|void
function_decl|(
name|XMLCALL
modifier|*
name|XML_AttlistDeclHandler
function_decl|)
parameter_list|(
name|void
modifier|*
name|userData
parameter_list|,
specifier|const
name|XML_Char
modifier|*
name|elname
parameter_list|,
specifier|const
name|XML_Char
modifier|*
name|attname
parameter_list|,
specifier|const
name|XML_Char
modifier|*
name|att_type
parameter_list|,
specifier|const
name|XML_Char
modifier|*
name|dflt
parameter_list|,
name|int
name|isrequired
parameter_list|)
function_decl|;
name|XMLPARSEAPI
argument_list|(
argument|void
argument_list|)
name|XML_SetAttlistDeclHandler
argument_list|(
argument|XML_Parser parser
argument_list|,
argument|XML_AttlistDeclHandler attdecl
argument_list|)
empty_stmt|;
comment|/* The XML declaration handler is called for *both* XML declarations    and text declarations. The way to distinguish is that the version    parameter will be NULL for text declarations. The encoding    parameter may be NULL for XML declarations. The standalone    parameter will be -1, 0, or 1 indicating respectively that there    was no standalone parameter in the declaration, that it was given    as no, or that it was given as yes. */
typedef|typedef
name|void
function_decl|(
name|XMLCALL
modifier|*
name|XML_XmlDeclHandler
function_decl|)
parameter_list|(
name|void
modifier|*
name|userData
parameter_list|,
specifier|const
name|XML_Char
modifier|*
name|version
parameter_list|,
specifier|const
name|XML_Char
modifier|*
name|encoding
parameter_list|,
name|int
name|standalone
parameter_list|)
function_decl|;
name|XMLPARSEAPI
argument_list|(
argument|void
argument_list|)
name|XML_SetXmlDeclHandler
argument_list|(
argument|XML_Parser parser
argument_list|,
argument|XML_XmlDeclHandler xmldecl
argument_list|)
empty_stmt|;
typedef|typedef
struct|struct
block|{
name|void
modifier|*
function_decl|(
modifier|*
name|malloc_fcn
function_decl|)
parameter_list|(
name|size_t
name|size
parameter_list|)
function_decl|;
name|void
modifier|*
function_decl|(
modifier|*
name|realloc_fcn
function_decl|)
parameter_list|(
name|void
modifier|*
name|ptr
parameter_list|,
name|size_t
name|size
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|free_fcn
function_decl|)
parameter_list|(
name|void
modifier|*
name|ptr
parameter_list|)
function_decl|;
block|}
name|XML_Memory_Handling_Suite
typedef|;
comment|/* Constructs a new parser; encoding is the encoding specified by the    external protocol or NULL if there is none specified. */
name|XMLPARSEAPI
argument_list|(
argument|XML_Parser
argument_list|)
name|XML_ParserCreate
argument_list|(
specifier|const
name|XML_Char
operator|*
name|encoding
argument_list|)
expr_stmt|;
comment|/* Constructs a new parser and namespace processor.  Element type    names and attribute names that belong to a namespace will be    expanded; unprefixed attribute names are never expanded; unprefixed    element type names are expanded only if there is a default    namespace. The expanded name is the concatenation of the namespace    URI, the namespace separator character, and the local part of the    name.  If the namespace separator is '\0' then the namespace URI    and the local part will be concatenated without any separator.    It is a programming error to use the separator '\0' with namespace    triplets (see XML_SetReturnNSTriplet). */
name|XMLPARSEAPI
argument_list|(
argument|XML_Parser
argument_list|)
name|XML_ParserCreateNS
argument_list|(
argument|const XML_Char *encoding
argument_list|,
argument|XML_Char namespaceSeparator
argument_list|)
empty_stmt|;
comment|/* Constructs a new parser using the memory management suite referred to    by memsuite. If memsuite is NULL, then use the standard library memory    suite. If namespaceSeparator is non-NULL it creates a parser with    namespace processing as described above. The character pointed at    will serve as the namespace separator.     All further memory operations used for the created parser will come from    the given suite. */
name|XMLPARSEAPI
argument_list|(
argument|XML_Parser
argument_list|)
name|XML_ParserCreate_MM
argument_list|(
specifier|const
name|XML_Char
operator|*
name|encoding
argument_list|,
specifier|const
name|XML_Memory_Handling_Suite
operator|*
name|memsuite
argument_list|,
specifier|const
name|XML_Char
operator|*
name|namespaceSeparator
argument_list|)
expr_stmt|;
comment|/* Prepare a parser object to be re-used.  This is particularly    valuable when memory allocation overhead is disproportionatly high,    such as when a large number of small documnents need to be parsed.    All handlers are cleared from the parser, except for the    unknownEncodingHandler. The parser's external state is re-initialized    except for the values of ns and ns_triplets.     Added in Expat 1.95.3. */
name|XMLPARSEAPI
argument_list|(
argument|XML_Bool
argument_list|)
name|XML_ParserReset
argument_list|(
argument|XML_Parser parser
argument_list|,
argument|const XML_Char *encoding
argument_list|)
empty_stmt|;
comment|/* atts is array of name/value pairs, terminated by 0;    names and values are 0 terminated. */
typedef|typedef
name|void
function_decl|(
name|XMLCALL
modifier|*
name|XML_StartElementHandler
function_decl|)
parameter_list|(
name|void
modifier|*
name|userData
parameter_list|,
specifier|const
name|XML_Char
modifier|*
name|name
parameter_list|,
specifier|const
name|XML_Char
modifier|*
modifier|*
name|atts
parameter_list|)
function_decl|;
typedef|typedef
name|void
function_decl|(
name|XMLCALL
modifier|*
name|XML_EndElementHandler
function_decl|)
parameter_list|(
name|void
modifier|*
name|userData
parameter_list|,
specifier|const
name|XML_Char
modifier|*
name|name
parameter_list|)
function_decl|;
comment|/* s is not 0 terminated. */
typedef|typedef
name|void
function_decl|(
name|XMLCALL
modifier|*
name|XML_CharacterDataHandler
function_decl|)
parameter_list|(
name|void
modifier|*
name|userData
parameter_list|,
specifier|const
name|XML_Char
modifier|*
name|s
parameter_list|,
name|int
name|len
parameter_list|)
function_decl|;
comment|/* target and data are 0 terminated */
typedef|typedef
name|void
function_decl|(
name|XMLCALL
modifier|*
name|XML_ProcessingInstructionHandler
function_decl|)
parameter_list|(
name|void
modifier|*
name|userData
parameter_list|,
specifier|const
name|XML_Char
modifier|*
name|target
parameter_list|,
specifier|const
name|XML_Char
modifier|*
name|data
parameter_list|)
function_decl|;
comment|/* data is 0 terminated */
typedef|typedef
name|void
function_decl|(
name|XMLCALL
modifier|*
name|XML_CommentHandler
function_decl|)
parameter_list|(
name|void
modifier|*
name|userData
parameter_list|,
specifier|const
name|XML_Char
modifier|*
name|data
parameter_list|)
function_decl|;
typedef|typedef
name|void
function_decl|(
name|XMLCALL
modifier|*
name|XML_StartCdataSectionHandler
function_decl|)
parameter_list|(
name|void
modifier|*
name|userData
parameter_list|)
function_decl|;
typedef|typedef
name|void
function_decl|(
name|XMLCALL
modifier|*
name|XML_EndCdataSectionHandler
function_decl|)
parameter_list|(
name|void
modifier|*
name|userData
parameter_list|)
function_decl|;
comment|/* This is called for any characters in the XML document for which    there is no applicable handler.  This includes both characters that    are part of markup which is of a kind that is not reported    (comments, markup declarations), or characters that are part of a    construct which could be reported but for which no handler has been    supplied. The characters are passed exactly as they were in the XML    document except that they will be encoded in UTF-8 or UTF-16.    Line boundaries are not normalized. Note that a byte order mark    character is not passed to the default handler. There are no    guarantees about how characters are divided between calls to the    default handler: for example, a comment might be split between    multiple calls. */
typedef|typedef
name|void
function_decl|(
name|XMLCALL
modifier|*
name|XML_DefaultHandler
function_decl|)
parameter_list|(
name|void
modifier|*
name|userData
parameter_list|,
specifier|const
name|XML_Char
modifier|*
name|s
parameter_list|,
name|int
name|len
parameter_list|)
function_decl|;
comment|/* This is called for the start of the DOCTYPE declaration, before    any DTD or internal subset is parsed. */
typedef|typedef
name|void
function_decl|(
name|XMLCALL
modifier|*
name|XML_StartDoctypeDeclHandler
function_decl|)
parameter_list|(
name|void
modifier|*
name|userData
parameter_list|,
specifier|const
name|XML_Char
modifier|*
name|doctypeName
parameter_list|,
specifier|const
name|XML_Char
modifier|*
name|sysid
parameter_list|,
specifier|const
name|XML_Char
modifier|*
name|pubid
parameter_list|,
name|int
name|has_internal_subset
parameter_list|)
function_decl|;
comment|/* This is called for the start of the DOCTYPE declaration when the    closing> is encountered, but after processing any external    subset. */
typedef|typedef
name|void
function_decl|(
name|XMLCALL
modifier|*
name|XML_EndDoctypeDeclHandler
function_decl|)
parameter_list|(
name|void
modifier|*
name|userData
parameter_list|)
function_decl|;
comment|/* This is called for entity declarations. The is_parameter_entity    argument will be non-zero if the entity is a parameter entity, zero    otherwise.     For internal entities (<!ENTITY foo "bar">), value will    be non-NULL and systemId, publicID, and notationName will be NULL.    The value string is NOT nul-terminated; the length is provided in    the value_length argument. Since it is legal to have zero-length    values, do not use this argument to test for internal entities.     For external entities, value will be NULL and systemId will be    non-NULL. The publicId argument will be NULL unless a public    identifier was provided. The notationName argument will have a    non-NULL value only for unparsed entity declarations.     Note that is_parameter_entity can't be changed to XML_Bool, since    that would break binary compatibility. */
typedef|typedef
name|void
function_decl|(
name|XMLCALL
modifier|*
name|XML_EntityDeclHandler
function_decl|)
parameter_list|(
name|void
modifier|*
name|userData
parameter_list|,
specifier|const
name|XML_Char
modifier|*
name|entityName
parameter_list|,
name|int
name|is_parameter_entity
parameter_list|,
specifier|const
name|XML_Char
modifier|*
name|value
parameter_list|,
name|int
name|value_length
parameter_list|,
specifier|const
name|XML_Char
modifier|*
name|base
parameter_list|,
specifier|const
name|XML_Char
modifier|*
name|systemId
parameter_list|,
specifier|const
name|XML_Char
modifier|*
name|publicId
parameter_list|,
specifier|const
name|XML_Char
modifier|*
name|notationName
parameter_list|)
function_decl|;
name|XMLPARSEAPI
argument_list|(
argument|void
argument_list|)
name|XML_SetEntityDeclHandler
argument_list|(
argument|XML_Parser parser
argument_list|,
argument|XML_EntityDeclHandler handler
argument_list|)
empty_stmt|;
comment|/* OBSOLETE -- OBSOLETE -- OBSOLETE    This handler has been superceded by the EntityDeclHandler above.    It is provided here for backward compatibility.     This is called for a declaration of an unparsed (NDATA) entity.    The base argument is whatever was set by XML_SetBase. The    entityName, systemId and notationName arguments will never be    NULL. The other arguments may be. */
typedef|typedef
name|void
function_decl|(
name|XMLCALL
modifier|*
name|XML_UnparsedEntityDeclHandler
function_decl|)
parameter_list|(
name|void
modifier|*
name|userData
parameter_list|,
specifier|const
name|XML_Char
modifier|*
name|entityName
parameter_list|,
specifier|const
name|XML_Char
modifier|*
name|base
parameter_list|,
specifier|const
name|XML_Char
modifier|*
name|systemId
parameter_list|,
specifier|const
name|XML_Char
modifier|*
name|publicId
parameter_list|,
specifier|const
name|XML_Char
modifier|*
name|notationName
parameter_list|)
function_decl|;
comment|/* This is called for a declaration of notation.  The base argument is    whatever was set by XML_SetBase. The notationName will never be    NULL.  The other arguments can be. */
typedef|typedef
name|void
function_decl|(
name|XMLCALL
modifier|*
name|XML_NotationDeclHandler
function_decl|)
parameter_list|(
name|void
modifier|*
name|userData
parameter_list|,
specifier|const
name|XML_Char
modifier|*
name|notationName
parameter_list|,
specifier|const
name|XML_Char
modifier|*
name|base
parameter_list|,
specifier|const
name|XML_Char
modifier|*
name|systemId
parameter_list|,
specifier|const
name|XML_Char
modifier|*
name|publicId
parameter_list|)
function_decl|;
comment|/* When namespace processing is enabled, these are called once for    each namespace declaration. The call to the start and end element    handlers occur between the calls to the start and end namespace    declaration handlers. For an xmlns attribute, prefix will be    NULL.  For an xmlns="" attribute, uri will be NULL. */
typedef|typedef
name|void
function_decl|(
name|XMLCALL
modifier|*
name|XML_StartNamespaceDeclHandler
function_decl|)
parameter_list|(
name|void
modifier|*
name|userData
parameter_list|,
specifier|const
name|XML_Char
modifier|*
name|prefix
parameter_list|,
specifier|const
name|XML_Char
modifier|*
name|uri
parameter_list|)
function_decl|;
typedef|typedef
name|void
function_decl|(
name|XMLCALL
modifier|*
name|XML_EndNamespaceDeclHandler
function_decl|)
parameter_list|(
name|void
modifier|*
name|userData
parameter_list|,
specifier|const
name|XML_Char
modifier|*
name|prefix
parameter_list|)
function_decl|;
comment|/* This is called if the document is not standalone, that is, it has an    external subset or a reference to a parameter entity, but does not    have standalone="yes". If this handler returns XML_STATUS_ERROR,    then processing will not continue, and the parser will return a    XML_ERROR_NOT_STANDALONE error.    If parameter entity parsing is enabled, then in addition to the    conditions above this handler will only be called if the referenced    entity was actually read. */
typedef|typedef
name|int
function_decl|(
name|XMLCALL
modifier|*
name|XML_NotStandaloneHandler
function_decl|)
parameter_list|(
name|void
modifier|*
name|userData
parameter_list|)
function_decl|;
comment|/* This is called for a reference to an external parsed general    entity.  The referenced entity is not automatically parsed.  The    application can parse it immediately or later using    XML_ExternalEntityParserCreate.     The parser argument is the parser parsing the entity containing the    reference; it can be passed as the parser argument to    XML_ExternalEntityParserCreate.  The systemId argument is the    system identifier as specified in the entity declaration; it will    not be NULL.     The base argument is the system identifier that should be used as    the base for resolving systemId if systemId was relative; this is    set by XML_SetBase; it may be NULL.     The publicId argument is the public identifier as specified in the    entity declaration, or NULL if none was specified; the whitespace    in the public identifier will have been normalized as required by    the XML spec.     The context argument specifies the parsing context in the format    expected by the context argument to XML_ExternalEntityParserCreate;    context is valid only until the handler returns, so if the    referenced entity is to be parsed later, it must be copied.    context is NULL only when the entity is a parameter entity.     The handler should return XML_STATUS_ERROR if processing should not    continue because of a fatal error in the handling of the external    entity.  In this case the calling parser will return an    XML_ERROR_EXTERNAL_ENTITY_HANDLING error.     Note that unlike other handlers the first argument is the parser,    not userData. */
typedef|typedef
name|int
function_decl|(
name|XMLCALL
modifier|*
name|XML_ExternalEntityRefHandler
function_decl|)
parameter_list|(
name|XML_Parser
name|parser
parameter_list|,
specifier|const
name|XML_Char
modifier|*
name|context
parameter_list|,
specifier|const
name|XML_Char
modifier|*
name|base
parameter_list|,
specifier|const
name|XML_Char
modifier|*
name|systemId
parameter_list|,
specifier|const
name|XML_Char
modifier|*
name|publicId
parameter_list|)
function_decl|;
comment|/* This is called in two situations:    1) An entity reference is encountered for which no declaration       has been read *and* this is not an error.    2) An internal entity reference is read, but not expanded, because       XML_SetDefaultHandler has been called.    Note: skipped parameter entities in declarations and skipped general          entities in attribute values cannot be reported, because          the event would be out of sync with the reporting of the          declarations or attribute values */
typedef|typedef
name|void
function_decl|(
name|XMLCALL
modifier|*
name|XML_SkippedEntityHandler
function_decl|)
parameter_list|(
name|void
modifier|*
name|userData
parameter_list|,
specifier|const
name|XML_Char
modifier|*
name|entityName
parameter_list|,
name|int
name|is_parameter_entity
parameter_list|)
function_decl|;
comment|/* This structure is filled in by the XML_UnknownEncodingHandler to    provide information to the parser about encodings that are unknown    to the parser.     The map[b] member gives information about byte sequences whose    first byte is b.     If map[b] is c where c is>= 0, then b by itself encodes the    Unicode scalar value c.     If map[b] is -1, then the byte sequence is malformed.     If map[b] is -n, where n>= 2, then b is the first byte of an    n-byte sequence that encodes a single Unicode scalar value.     The data member will be passed as the first argument to the convert    function.     The convert function is used to convert multibyte sequences; s will    point to a n-byte sequence where map[(unsigned char)*s] == -n.  The    convert function must return the Unicode scalar value represented    by this byte sequence or -1 if the byte sequence is malformed.     The convert function may be NULL if the encoding is a single-byte    encoding, that is if map[b]>= -1 for all bytes b.     When the parser is finished with the encoding, then if release is    not NULL, it will call release passing it the data member; once    release has been called, the convert function will not be called    again.     Expat places certain restrictions on the encodings that are supported    using this mechanism.     1. Every ASCII character that can appear in a well-formed XML document,       other than the characters        $@\^`{}~        must be represented by a single byte, and that byte must be the       same byte that represents that character in ASCII.     2. No character may require more than 4 bytes to encode.     3. All characters encoded must have Unicode scalar values<=       0xFFFF, (i.e., characters that would be encoded by surrogates in       UTF-16 are  not allowed).  Note that this restriction doesn't       apply to the built-in support for UTF-8 and UTF-16.     4. No Unicode character may be encoded by more than one distinct       sequence of bytes. */
typedef|typedef
struct|struct
block|{
name|int
name|map
index|[
literal|256
index|]
decl_stmt|;
name|void
modifier|*
name|data
decl_stmt|;
name|int
function_decl|(
name|XMLCALL
modifier|*
name|convert
function_decl|)
parameter_list|(
name|void
modifier|*
name|data
parameter_list|,
specifier|const
name|char
modifier|*
name|s
parameter_list|)
function_decl|;
name|void
function_decl|(
name|XMLCALL
modifier|*
name|release
function_decl|)
parameter_list|(
name|void
modifier|*
name|data
parameter_list|)
function_decl|;
block|}
name|XML_Encoding
typedef|;
comment|/* This is called for an encoding that is unknown to the parser.     The encodingHandlerData argument is that which was passed as the    second argument to XML_SetUnknownEncodingHandler.     The name argument gives the name of the encoding as specified in    the encoding declaration.     If the callback can provide information about the encoding, it must    fill in the XML_Encoding structure, and return XML_STATUS_OK.    Otherwise it must return XML_STATUS_ERROR.     If info does not describe a suitable encoding, then the parser will    return an XML_UNKNOWN_ENCODING error. */
typedef|typedef
name|int
function_decl|(
name|XMLCALL
modifier|*
name|XML_UnknownEncodingHandler
function_decl|)
parameter_list|(
name|void
modifier|*
name|encodingHandlerData
parameter_list|,
specifier|const
name|XML_Char
modifier|*
name|name
parameter_list|,
name|XML_Encoding
modifier|*
name|info
parameter_list|)
function_decl|;
name|XMLPARSEAPI
argument_list|(
argument|void
argument_list|)
name|XML_SetElementHandler
argument_list|(
argument|XML_Parser parser
argument_list|,
argument|XML_StartElementHandler start
argument_list|,
argument|XML_EndElementHandler end
argument_list|)
empty_stmt|;
name|XMLPARSEAPI
argument_list|(
argument|void
argument_list|)
name|XML_SetStartElementHandler
argument_list|(
argument|XML_Parser parser
argument_list|,
argument|XML_StartElementHandler handler
argument_list|)
empty_stmt|;
name|XMLPARSEAPI
argument_list|(
argument|void
argument_list|)
name|XML_SetEndElementHandler
argument_list|(
argument|XML_Parser parser
argument_list|,
argument|XML_EndElementHandler handler
argument_list|)
empty_stmt|;
name|XMLPARSEAPI
argument_list|(
argument|void
argument_list|)
name|XML_SetCharacterDataHandler
argument_list|(
argument|XML_Parser parser
argument_list|,
argument|XML_CharacterDataHandler handler
argument_list|)
empty_stmt|;
name|XMLPARSEAPI
argument_list|(
argument|void
argument_list|)
name|XML_SetProcessingInstructionHandler
argument_list|(
argument|XML_Parser parser
argument_list|,
argument|XML_ProcessingInstructionHandler handler
argument_list|)
empty_stmt|;
name|XMLPARSEAPI
argument_list|(
argument|void
argument_list|)
name|XML_SetCommentHandler
argument_list|(
argument|XML_Parser parser
argument_list|,
argument|XML_CommentHandler handler
argument_list|)
empty_stmt|;
name|XMLPARSEAPI
argument_list|(
argument|void
argument_list|)
name|XML_SetCdataSectionHandler
argument_list|(
argument|XML_Parser parser
argument_list|,
argument|XML_StartCdataSectionHandler start
argument_list|,
argument|XML_EndCdataSectionHandler end
argument_list|)
empty_stmt|;
name|XMLPARSEAPI
argument_list|(
argument|void
argument_list|)
name|XML_SetStartCdataSectionHandler
argument_list|(
argument|XML_Parser parser
argument_list|,
argument|XML_StartCdataSectionHandler start
argument_list|)
empty_stmt|;
name|XMLPARSEAPI
argument_list|(
argument|void
argument_list|)
name|XML_SetEndCdataSectionHandler
argument_list|(
argument|XML_Parser parser
argument_list|,
argument|XML_EndCdataSectionHandler end
argument_list|)
empty_stmt|;
comment|/* This sets the default handler and also inhibits expansion of    internal entities. These entity references will be passed to the    default handler, or to the skipped entity handler, if one is set. */
name|XMLPARSEAPI
argument_list|(
argument|void
argument_list|)
name|XML_SetDefaultHandler
argument_list|(
argument|XML_Parser parser
argument_list|,
argument|XML_DefaultHandler handler
argument_list|)
empty_stmt|;
comment|/* This sets the default handler but does not inhibit expansion of    internal entities.  The entity reference will not be passed to the    default handler. */
name|XMLPARSEAPI
argument_list|(
argument|void
argument_list|)
name|XML_SetDefaultHandlerExpand
argument_list|(
argument|XML_Parser parser
argument_list|,
argument|XML_DefaultHandler handler
argument_list|)
empty_stmt|;
name|XMLPARSEAPI
argument_list|(
argument|void
argument_list|)
name|XML_SetDoctypeDeclHandler
argument_list|(
argument|XML_Parser parser
argument_list|,
argument|XML_StartDoctypeDeclHandler start
argument_list|,
argument|XML_EndDoctypeDeclHandler end
argument_list|)
empty_stmt|;
name|XMLPARSEAPI
argument_list|(
argument|void
argument_list|)
name|XML_SetStartDoctypeDeclHandler
argument_list|(
argument|XML_Parser parser
argument_list|,
argument|XML_StartDoctypeDeclHandler start
argument_list|)
empty_stmt|;
name|XMLPARSEAPI
argument_list|(
argument|void
argument_list|)
name|XML_SetEndDoctypeDeclHandler
argument_list|(
argument|XML_Parser parser
argument_list|,
argument|XML_EndDoctypeDeclHandler end
argument_list|)
empty_stmt|;
name|XMLPARSEAPI
argument_list|(
argument|void
argument_list|)
name|XML_SetUnparsedEntityDeclHandler
argument_list|(
argument|XML_Parser parser
argument_list|,
argument|XML_UnparsedEntityDeclHandler handler
argument_list|)
empty_stmt|;
name|XMLPARSEAPI
argument_list|(
argument|void
argument_list|)
name|XML_SetNotationDeclHandler
argument_list|(
argument|XML_Parser parser
argument_list|,
argument|XML_NotationDeclHandler handler
argument_list|)
empty_stmt|;
name|XMLPARSEAPI
argument_list|(
argument|void
argument_list|)
name|XML_SetNamespaceDeclHandler
argument_list|(
argument|XML_Parser parser
argument_list|,
argument|XML_StartNamespaceDeclHandler start
argument_list|,
argument|XML_EndNamespaceDeclHandler end
argument_list|)
empty_stmt|;
name|XMLPARSEAPI
argument_list|(
argument|void
argument_list|)
name|XML_SetStartNamespaceDeclHandler
argument_list|(
argument|XML_Parser parser
argument_list|,
argument|XML_StartNamespaceDeclHandler start
argument_list|)
empty_stmt|;
name|XMLPARSEAPI
argument_list|(
argument|void
argument_list|)
name|XML_SetEndNamespaceDeclHandler
argument_list|(
argument|XML_Parser parser
argument_list|,
argument|XML_EndNamespaceDeclHandler end
argument_list|)
empty_stmt|;
name|XMLPARSEAPI
argument_list|(
argument|void
argument_list|)
name|XML_SetNotStandaloneHandler
argument_list|(
argument|XML_Parser parser
argument_list|,
argument|XML_NotStandaloneHandler handler
argument_list|)
empty_stmt|;
name|XMLPARSEAPI
argument_list|(
argument|void
argument_list|)
name|XML_SetExternalEntityRefHandler
argument_list|(
argument|XML_Parser parser
argument_list|,
argument|XML_ExternalEntityRefHandler handler
argument_list|)
empty_stmt|;
comment|/* If a non-NULL value for arg is specified here, then it will be    passed as the first argument to the external entity ref handler    instead of the parser object. */
name|XMLPARSEAPI
argument_list|(
argument|void
argument_list|)
name|XML_SetExternalEntityRefHandlerArg
argument_list|(
argument|XML_Parser parser
argument_list|,
argument|void *arg
argument_list|)
empty_stmt|;
name|XMLPARSEAPI
argument_list|(
argument|void
argument_list|)
name|XML_SetSkippedEntityHandler
argument_list|(
argument|XML_Parser parser
argument_list|,
argument|XML_SkippedEntityHandler handler
argument_list|)
empty_stmt|;
name|XMLPARSEAPI
argument_list|(
argument|void
argument_list|)
name|XML_SetUnknownEncodingHandler
argument_list|(
argument|XML_Parser parser
argument_list|,
argument|XML_UnknownEncodingHandler handler
argument_list|,
argument|void *encodingHandlerData
argument_list|)
empty_stmt|;
comment|/* This can be called within a handler for a start element, end    element, processing instruction or character data.  It causes the    corresponding markup to be passed to the default handler. */
name|XMLPARSEAPI
argument_list|(
argument|void
argument_list|)
name|XML_DefaultCurrent
argument_list|(
argument|XML_Parser parser
argument_list|)
empty_stmt|;
comment|/* If do_nst is non-zero, and namespace processing is in effect, and    a name has a prefix (i.e. an explicit namespace qualifier) then    that name is returned as a triplet in a single string separated by    the separator character specified when the parser was created: URI    + sep + local_name + sep + prefix.     If do_nst is zero, then namespace information is returned in the    default manner (URI + sep + local_name) whether or not the name    has a prefix.     Note: Calling XML_SetReturnNSTriplet after XML_Parse or      XML_ParseBuffer has no effect. */
name|XMLPARSEAPI
argument_list|(
argument|void
argument_list|)
name|XML_SetReturnNSTriplet
argument_list|(
argument|XML_Parser parser
argument_list|,
argument|int do_nst
argument_list|)
empty_stmt|;
comment|/* This value is passed as the userData argument to callbacks. */
name|XMLPARSEAPI
argument_list|(
argument|void
argument_list|)
name|XML_SetUserData
argument_list|(
argument|XML_Parser parser
argument_list|,
argument|void *userData
argument_list|)
empty_stmt|;
comment|/* Returns the last value set by XML_SetUserData or NULL. */
define|#
directive|define
name|XML_GetUserData
parameter_list|(
name|parser
parameter_list|)
value|(*(void **)(parser))
comment|/* This is equivalent to supplying an encoding argument to    XML_ParserCreate. On success XML_SetEncoding returns non-zero,    zero otherwise.    Note: Calling XML_SetEncoding after XML_Parse or XML_ParseBuffer      has no effect and returns XML_STATUS_ERROR. */
name|XMLPARSEAPI
argument_list|(
argument|enum XML_Status
argument_list|)
name|XML_SetEncoding
argument_list|(
argument|XML_Parser parser
argument_list|,
argument|const XML_Char *encoding
argument_list|)
empty_stmt|;
comment|/* If this function is called, then the parser will be passed as the    first argument to callbacks instead of userData.  The userData will    still be accessible using XML_GetUserData. */
name|XMLPARSEAPI
argument_list|(
argument|void
argument_list|)
name|XML_UseParserAsHandlerArg
argument_list|(
argument|XML_Parser parser
argument_list|)
empty_stmt|;
comment|/* If useDTD == XML_TRUE is passed to this function, then the parser    will assume that there is an external subset, even if none is    specified in the document. In such a case the parser will call the    externalEntityRefHandler with a value of NULL for the systemId    argument (the publicId and context arguments will be NULL as well).    Note: For the purpose of checking WFC: Entity Declared, passing      useDTD == XML_TRUE will make the parser behave as if the document      had a DTD with an external subset.    Note: If this function is called, then this must be done before      the first call to XML_Parse or XML_ParseBuffer, since it will      have no effect after that.  Returns      XML_ERROR_CANT_CHANGE_FEATURE_ONCE_PARSING.    Note: If the document does not have a DOCTYPE declaration at all,      then startDoctypeDeclHandler and endDoctypeDeclHandler will not      be called, despite an external subset being parsed.    Note: If XML_DTD is not defined when Expat is compiled, returns      XML_ERROR_FEATURE_REQUIRES_XML_DTD. */
name|XMLPARSEAPI
argument_list|(
argument|enum XML_Error
argument_list|)
name|XML_UseForeignDTD
argument_list|(
argument|XML_Parser parser
argument_list|,
argument|XML_Bool useDTD
argument_list|)
empty_stmt|;
comment|/* Sets the base to be used for resolving relative URIs in system    identifiers in declarations.  Resolving relative identifiers is    left to the application: this value will be passed through as the    base argument to the XML_ExternalEntityRefHandler,    XML_NotationDeclHandler and XML_UnparsedEntityDeclHandler. The base    argument will be copied.  Returns XML_STATUS_ERROR if out of memory,    XML_STATUS_OK otherwise. */
name|XMLPARSEAPI
argument_list|(
argument|enum XML_Status
argument_list|)
name|XML_SetBase
argument_list|(
argument|XML_Parser parser
argument_list|,
argument|const XML_Char *base
argument_list|)
empty_stmt|;
name|XMLPARSEAPI
argument_list|(
argument|const XML_Char *
argument_list|)
name|XML_GetBase
argument_list|(
argument|XML_Parser parser
argument_list|)
empty_stmt|;
comment|/* Returns the number of the attribute/value pairs passed in last call    to the XML_StartElementHandler that were specified in the start-tag    rather than defaulted. Each attribute/value pair counts as 2; thus    this correspondds to an index into the atts array passed to the    XML_StartElementHandler. */
name|XMLPARSEAPI
argument_list|(
argument|int
argument_list|)
name|XML_GetSpecifiedAttributeCount
argument_list|(
argument|XML_Parser parser
argument_list|)
empty_stmt|;
comment|/* Returns the index of the ID attribute passed in the last call to    XML_StartElementHandler, or -1 if there is no ID attribute.  Each    attribute/value pair counts as 2; thus this correspondds to an    index into the atts array passed to the XML_StartElementHandler. */
name|XMLPARSEAPI
argument_list|(
argument|int
argument_list|)
name|XML_GetIdAttributeIndex
argument_list|(
argument|XML_Parser parser
argument_list|)
empty_stmt|;
comment|/* Parses some input. Returns XML_STATUS_ERROR if a fatal error is    detected.  The last call to XML_Parse must have isFinal true; len    may be zero for this call (or any other).     Though the return values for these functions has always been    described as a Boolean value, the implementation, at least for the    1.95.x series, has always returned exactly one of the XML_Status    values. */
name|XMLPARSEAPI
argument_list|(
argument|enum XML_Status
argument_list|)
name|XML_Parse
argument_list|(
argument|XML_Parser parser
argument_list|,
argument|const char *s
argument_list|,
argument|int len
argument_list|,
argument|int isFinal
argument_list|)
empty_stmt|;
name|XMLPARSEAPI
argument_list|(
argument|void *
argument_list|)
name|XML_GetBuffer
argument_list|(
argument|XML_Parser parser
argument_list|,
argument|int len
argument_list|)
empty_stmt|;
name|XMLPARSEAPI
argument_list|(
argument|enum XML_Status
argument_list|)
name|XML_ParseBuffer
argument_list|(
argument|XML_Parser parser
argument_list|,
argument|int len
argument_list|,
argument|int isFinal
argument_list|)
empty_stmt|;
comment|/* Stops parsing, causing XML_Parse() or XML_ParseBuffer() to return.    Must be called from within a call-back handler, except when aborting    (resumable = 0) an already suspended parser. Some call-backs may    still follow because they would otherwise get lost. Examples:    - endElementHandler() for empty elements when stopped in      startElementHandler(),     - endNameSpaceDeclHandler() when stopped in endElementHandler(),     and possibly others.     Can be called from most handlers, including DTD related call-backs,    except when parsing an external parameter entity and resumable != 0.    Returns XML_STATUS_OK when successful, XML_STATUS_ERROR otherwise.    Possible error codes:     - XML_ERROR_SUSPENDED: when suspending an already suspended parser.    - XML_ERROR_FINISHED: when the parser has already finished.    - XML_ERROR_SUSPEND_PE: when suspending while parsing an external PE.     When resumable != 0 (true) then parsing is suspended, that is,     XML_Parse() and XML_ParseBuffer() return XML_STATUS_SUSPENDED.     Otherwise, parsing is aborted, that is, XML_Parse() and XML_ParseBuffer()    return XML_STATUS_ERROR with error code XML_ERROR_ABORTED.     *Note*:    This will be applied to the current parser instance only, that is, if    there is a parent parser then it will continue parsing when the    externalEntityRefHandler() returns. It is up to the implementation of    the externalEntityRefHandler() to call XML_StopParser() on the parent    parser (recursively), if one wants to stop parsing altogether.     When suspended, parsing can be resumed by calling XML_ResumeParser().  */
name|XMLPARSEAPI
argument_list|(
argument|enum XML_Status
argument_list|)
name|XML_StopParser
argument_list|(
argument|XML_Parser parser
argument_list|,
argument|XML_Bool resumable
argument_list|)
empty_stmt|;
comment|/* Resumes parsing after it has been suspended with XML_StopParser().    Must not be called from within a handler call-back. Returns same    status codes as XML_Parse() or XML_ParseBuffer().    Additional error code XML_ERROR_NOT_SUSPENDED possible.        *Note*:    This must be called on the most deeply nested child parser instance    first, and on its parent parser only after the child parser has finished,    to be applied recursively until the document entity's parser is restarted.    That is, the parent parser will not resume by itself and it is up to the    application to call XML_ResumeParser() on it at the appropriate moment. */
name|XMLPARSEAPI
argument_list|(
argument|enum XML_Status
argument_list|)
name|XML_ResumeParser
argument_list|(
argument|XML_Parser parser
argument_list|)
empty_stmt|;
enum|enum
name|XML_Parsing
block|{
name|XML_INITIALIZED
block|,
name|XML_PARSING
block|,
name|XML_FINISHED
block|,
name|XML_SUSPENDED
block|}
enum|;
typedef|typedef
struct|struct
block|{
name|enum
name|XML_Parsing
name|parsing
decl_stmt|;
name|XML_Bool
name|finalBuffer
decl_stmt|;
block|}
name|XML_ParsingStatus
typedef|;
comment|/* Returns status of parser with respect to being initialized, parsing,    finished, or suspended and processing the final buffer.    XXX XML_Parse() and XML_ParseBuffer() should return XML_ParsingStatus,    XXX with XML_FINISHED_OK or XML_FINISHED_ERROR replacing XML_FINISHED */
name|XMLPARSEAPI
argument_list|(
argument|void
argument_list|)
name|XML_GetParsingStatus
argument_list|(
argument|XML_Parser parser
argument_list|,
argument|XML_ParsingStatus *status
argument_list|)
empty_stmt|;
comment|/* Creates an XML_Parser object that can parse an external general    entity; context is a '\0'-terminated string specifying the parse    context; encoding is a '\0'-terminated string giving the name of    the externally specified encoding, or NULL if there is no    externally specified encoding.  The context string consists of a    sequence of tokens separated by formfeeds (\f); a token consisting    of a name specifies that the general entity of the name is open; a    token of the form prefix=uri specifies the namespace for a    particular prefix; a token of the form =uri specifies the default    namespace.  This can be called at any point after the first call to    an ExternalEntityRefHandler so longer as the parser has not yet    been freed.  The new parser is completely independent and may    safely be used in a separate thread.  The handlers and userData are    initialized from the parser argument.  Returns NULL if out of memory.    Otherwise returns a new XML_Parser object. */
name|XMLPARSEAPI
argument_list|(
argument|XML_Parser
argument_list|)
name|XML_ExternalEntityParserCreate
argument_list|(
argument|XML_Parser parser
argument_list|,
argument|const XML_Char *context
argument_list|,
argument|const XML_Char *encoding
argument_list|)
empty_stmt|;
enum|enum
name|XML_ParamEntityParsing
block|{
name|XML_PARAM_ENTITY_PARSING_NEVER
block|,
name|XML_PARAM_ENTITY_PARSING_UNLESS_STANDALONE
block|,
name|XML_PARAM_ENTITY_PARSING_ALWAYS
block|}
enum|;
comment|/* Controls parsing of parameter entities (including the external DTD    subset). If parsing of parameter entities is enabled, then    references to external parameter entities (including the external    DTD subset) will be passed to the handler set with    XML_SetExternalEntityRefHandler.  The context passed will be 0.     Unlike external general entities, external parameter entities can    only be parsed synchronously.  If the external parameter entity is    to be parsed, it must be parsed during the call to the external    entity ref handler: the complete sequence of    XML_ExternalEntityParserCreate, XML_Parse/XML_ParseBuffer and    XML_ParserFree calls must be made during this call.  After    XML_ExternalEntityParserCreate has been called to create the parser    for the external parameter entity (context must be 0 for this    call), it is illegal to make any calls on the old parser until    XML_ParserFree has been called on the newly created parser.    If the library has been compiled without support for parameter    entity parsing (ie without XML_DTD being defined), then    XML_SetParamEntityParsing will return 0 if parsing of parameter    entities is requested; otherwise it will return non-zero.    Note: If XML_SetParamEntityParsing is called after XML_Parse or       XML_ParseBuffer, then it has no effect and will always return 0. */
name|XMLPARSEAPI
argument_list|(
argument|int
argument_list|)
name|XML_SetParamEntityParsing
argument_list|(
argument|XML_Parser parser
argument_list|,
argument|enum XML_ParamEntityParsing parsing
argument_list|)
empty_stmt|;
comment|/* If XML_Parse or XML_ParseBuffer have returned XML_STATUS_ERROR, then    XML_GetErrorCode returns information about the error. */
name|XMLPARSEAPI
argument_list|(
argument|enum XML_Error
argument_list|)
name|XML_GetErrorCode
argument_list|(
argument|XML_Parser parser
argument_list|)
empty_stmt|;
comment|/* These functions return information about the current parse    location.  They may be called from any callback called to report    some parse event; in this case the location is the location of the    first of the sequence of characters that generated the event.  When    called from callbacks generated by declarations in the document    prologue, the location identified isn't as neatly defined, but will    be within the relevant markup.  When called outside of the callback    functions, the position indicated will be just past the last parse    event (regardless of whether there was an associated callback).        They may also be called after returning from a call to XML_Parse    or XML_ParseBuffer.  If the return value is XML_STATUS_ERROR then    the location is the location of the character at which the error    was detected; otherwise the location is the location of the last    parse event, as described above. */
name|XMLPARSEAPI
argument_list|(
argument|XML_Size
argument_list|)
name|XML_GetCurrentLineNumber
argument_list|(
argument|XML_Parser parser
argument_list|)
empty_stmt|;
name|XMLPARSEAPI
argument_list|(
argument|XML_Size
argument_list|)
name|XML_GetCurrentColumnNumber
argument_list|(
argument|XML_Parser parser
argument_list|)
empty_stmt|;
name|XMLPARSEAPI
argument_list|(
argument|XML_Index
argument_list|)
name|XML_GetCurrentByteIndex
argument_list|(
argument|XML_Parser parser
argument_list|)
empty_stmt|;
comment|/* Return the number of bytes in the current event.    Returns 0 if the event is in an internal entity. */
name|XMLPARSEAPI
argument_list|(
argument|int
argument_list|)
name|XML_GetCurrentByteCount
argument_list|(
argument|XML_Parser parser
argument_list|)
empty_stmt|;
comment|/* If XML_CONTEXT_BYTES is defined, returns the input buffer, sets    the integer pointed to by offset to the offset within this buffer    of the current parse position, and sets the integer pointed to by size    to the size of this buffer (the number of input bytes). Otherwise    returns a NULL pointer. Also returns a NULL pointer if a parse isn't    active.     NOTE: The character pointer returned should not be used outside    the handler that makes the call. */
name|XMLPARSEAPI
argument_list|(
argument|const char *
argument_list|)
name|XML_GetInputContext
argument_list|(
argument|XML_Parser parser
argument_list|,
argument|int *offset
argument_list|,
argument|int *size
argument_list|)
empty_stmt|;
comment|/* For backwards compatibility with previous versions. */
define|#
directive|define
name|XML_GetErrorLineNumber
value|XML_GetCurrentLineNumber
define|#
directive|define
name|XML_GetErrorColumnNumber
value|XML_GetCurrentColumnNumber
define|#
directive|define
name|XML_GetErrorByteIndex
value|XML_GetCurrentByteIndex
comment|/* Frees the content model passed to the element declaration handler */
name|XMLPARSEAPI
argument_list|(
argument|void
argument_list|)
name|XML_FreeContentModel
argument_list|(
argument|XML_Parser parser
argument_list|,
argument|XML_Content *model
argument_list|)
empty_stmt|;
comment|/* Exposing the memory handling functions used in Expat */
name|XMLPARSEAPI
argument_list|(
argument|void *
argument_list|)
name|XML_MemMalloc
argument_list|(
argument|XML_Parser parser
argument_list|,
argument|size_t size
argument_list|)
empty_stmt|;
name|XMLPARSEAPI
argument_list|(
argument|void *
argument_list|)
name|XML_MemRealloc
argument_list|(
argument|XML_Parser parser
argument_list|,
argument|void *ptr
argument_list|,
argument|size_t size
argument_list|)
empty_stmt|;
name|XMLPARSEAPI
argument_list|(
argument|void
argument_list|)
name|XML_MemFree
argument_list|(
argument|XML_Parser parser
argument_list|,
argument|void *ptr
argument_list|)
empty_stmt|;
comment|/* Frees memory used by the parser. */
name|XMLPARSEAPI
argument_list|(
argument|void
argument_list|)
name|XML_ParserFree
argument_list|(
argument|XML_Parser parser
argument_list|)
empty_stmt|;
comment|/* Returns a string describing the error. */
name|XMLPARSEAPI
argument_list|(
argument|const XML_LChar *
argument_list|)
name|XML_ErrorString
argument_list|(
argument|enum XML_Error code
argument_list|)
empty_stmt|;
comment|/* Return a string containing the version number of this expat */
name|XMLPARSEAPI
argument_list|(
argument|const XML_LChar *
argument_list|)
name|XML_ExpatVersion
argument_list|(
name|void
argument_list|)
expr_stmt|;
typedef|typedef
struct|struct
block|{
name|int
name|major
decl_stmt|;
name|int
name|minor
decl_stmt|;
name|int
name|micro
decl_stmt|;
block|}
name|XML_Expat_Version
typedef|;
comment|/* Return an XML_Expat_Version structure containing numeric version    number information for this version of expat. */
name|XMLPARSEAPI
argument_list|(
argument|XML_Expat_Version
argument_list|)
name|XML_ExpatVersionInfo
argument_list|(
name|void
argument_list|)
expr_stmt|;
comment|/* Added in Expat 1.95.5. */
enum|enum
name|XML_FeatureEnum
block|{
name|XML_FEATURE_END
init|=
literal|0
block|,
name|XML_FEATURE_UNICODE
block|,
name|XML_FEATURE_UNICODE_WCHAR_T
block|,
name|XML_FEATURE_DTD
block|,
name|XML_FEATURE_CONTEXT_BYTES
block|,
name|XML_FEATURE_MIN_SIZE
block|,
name|XML_FEATURE_SIZEOF_XML_CHAR
block|,
name|XML_FEATURE_SIZEOF_XML_LCHAR
block|,
name|XML_FEATURE_NS
block|,
name|XML_FEATURE_LARGE_SIZE
comment|/* Additional features must be added to the end of this enum. */
block|}
enum|;
typedef|typedef
struct|struct
block|{
name|enum
name|XML_FeatureEnum
name|feature
decl_stmt|;
specifier|const
name|XML_LChar
modifier|*
name|name
decl_stmt|;
name|long
name|int
name|value
decl_stmt|;
block|}
name|XML_Feature
typedef|;
name|XMLPARSEAPI
argument_list|(
argument|const XML_Feature *
argument_list|)
name|XML_GetFeatureList
argument_list|(
name|void
argument_list|)
expr_stmt|;
comment|/* Expat follows the GNU/Linux convention of odd number minor version for    beta/development releases and even number minor version for stable    releases. Micro is bumped with each release, and set to 0 with each    change to major or minor version. */
define|#
directive|define
name|XML_MAJOR_VERSION
value|2
define|#
directive|define
name|XML_MINOR_VERSION
value|0
define|#
directive|define
name|XML_MICRO_VERSION
value|1
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
comment|/* not Expat_INCLUDED */
end_comment

end_unit

