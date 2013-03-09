begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/**  * @file yaml.h  * @brief Public interface for libyaml.  *   * Include the header file with the code:  * @code  * #include<yaml.h>  * @endcode  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|YAML_H
end_ifndef

begin_define
define|#
directive|define
name|YAML_H
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
include|#
directive|include
file|<stdlib.h>
include|#
directive|include
file|<stdio.h>
include|#
directive|include
file|<string.h>
comment|/**  * @defgroup export Export Definitions  * @{  */
comment|/** The public API declaration. */
ifdef|#
directive|ifdef
name|_WIN32
if|#
directive|if
name|defined
argument_list|(
name|YAML_DECLARE_STATIC
argument_list|)
define|#
directive|define
name|YAML_DECLARE
parameter_list|(
name|type
parameter_list|)
value|type
elif|#
directive|elif
name|defined
argument_list|(
name|YAML_DECLARE_EXPORT
argument_list|)
define|#
directive|define
name|YAML_DECLARE
parameter_list|(
name|type
parameter_list|)
value|__declspec(dllexport) type
else|#
directive|else
define|#
directive|define
name|YAML_DECLARE
parameter_list|(
name|type
parameter_list|)
value|__declspec(dllimport) type
endif|#
directive|endif
else|#
directive|else
define|#
directive|define
name|YAML_DECLARE
parameter_list|(
name|type
parameter_list|)
value|type
endif|#
directive|endif
comment|/** @} */
comment|/**  * @defgroup version Version Information  * @{  */
comment|/**  * Get the library version as a string.  *  * @returns The function returns the pointer to a static string of the form  * @c "X.Y.Z", where @c X is the major version number, @c Y is a minor version  * number, and @c Z is the patch version number.  */
name|YAML_DECLARE
argument_list|(
argument|const char *
argument_list|)
name|yaml_get_version_string
argument_list|(
name|void
argument_list|)
expr_stmt|;
comment|/**  * Get the library version numbers.  *  * @param[out]      major   Major version number.  * @param[out]      minor   Minor version number.  * @param[out]      patch   Patch version number.  */
name|YAML_DECLARE
argument_list|(
argument|void
argument_list|)
name|yaml_get_version
argument_list|(
name|int
operator|*
name|major
argument_list|,
name|int
operator|*
name|minor
argument_list|,
name|int
operator|*
name|patch
argument_list|)
expr_stmt|;
comment|/** @} */
comment|/**  * @defgroup basic Basic Types  * @{  */
comment|/** The character type (UTF-8 octet). */
typedef|typedef
name|unsigned
name|char
name|yaml_char_t
typedef|;
comment|/** The version directive data. */
typedef|typedef
struct|struct
name|yaml_version_directive_s
block|{
comment|/** The major version number. */
name|int
name|major
decl_stmt|;
comment|/** The minor version number. */
name|int
name|minor
decl_stmt|;
block|}
name|yaml_version_directive_t
typedef|;
comment|/** The tag directive data. */
typedef|typedef
struct|struct
name|yaml_tag_directive_s
block|{
comment|/** The tag handle. */
name|yaml_char_t
modifier|*
name|handle
decl_stmt|;
comment|/** The tag prefix. */
name|yaml_char_t
modifier|*
name|prefix
decl_stmt|;
block|}
name|yaml_tag_directive_t
typedef|;
comment|/** The stream encoding. */
typedef|typedef
enum|enum
name|yaml_encoding_e
block|{
comment|/** Let the parser choose the encoding. */
name|YAML_ANY_ENCODING
block|,
comment|/** The default UTF-8 encoding. */
name|YAML_UTF8_ENCODING
block|,
comment|/** The UTF-16-LE encoding with BOM. */
name|YAML_UTF16LE_ENCODING
block|,
comment|/** The UTF-16-BE encoding with BOM. */
name|YAML_UTF16BE_ENCODING
block|}
name|yaml_encoding_t
typedef|;
comment|/** Line break types. */
typedef|typedef
enum|enum
name|yaml_break_e
block|{
comment|/** Let the parser choose the break type. */
name|YAML_ANY_BREAK
block|,
comment|/** Use CR for line breaks (Mac style). */
name|YAML_CR_BREAK
block|,
comment|/** Use LN for line breaks (Unix style). */
name|YAML_LN_BREAK
block|,
comment|/** Use CR LN for line breaks (DOS style). */
name|YAML_CRLN_BREAK
block|}
name|yaml_break_t
typedef|;
comment|/** Many bad things could happen with the parser and emitter. */
typedef|typedef
enum|enum
name|yaml_error_type_e
block|{
comment|/** No error is produced. */
name|YAML_NO_ERROR
block|,
comment|/** Cannot allocate or reallocate a block of memory. */
name|YAML_MEMORY_ERROR
block|,
comment|/** Cannot read or decode the input stream. */
name|YAML_READER_ERROR
block|,
comment|/** Cannot scan the input stream. */
name|YAML_SCANNER_ERROR
block|,
comment|/** Cannot parse the input stream. */
name|YAML_PARSER_ERROR
block|,
comment|/** Cannot compose a YAML document. */
name|YAML_COMPOSER_ERROR
block|,
comment|/** Cannot write to the output stream. */
name|YAML_WRITER_ERROR
block|,
comment|/** Cannot emit a YAML stream. */
name|YAML_EMITTER_ERROR
block|}
name|yaml_error_type_t
typedef|;
comment|/** The pointer position. */
typedef|typedef
struct|struct
name|yaml_mark_s
block|{
comment|/** The position index. */
name|size_t
name|index
decl_stmt|;
comment|/** The position line. */
name|size_t
name|line
decl_stmt|;
comment|/** The position column. */
name|size_t
name|column
decl_stmt|;
block|}
name|yaml_mark_t
typedef|;
comment|/** @} */
comment|/**  * @defgroup styles Node Styles  * @{  */
comment|/** Scalar styles. */
typedef|typedef
enum|enum
name|yaml_scalar_style_e
block|{
comment|/** Let the emitter choose the style. */
name|YAML_ANY_SCALAR_STYLE
block|,
comment|/** The plain scalar style. */
name|YAML_PLAIN_SCALAR_STYLE
block|,
comment|/** The single-quoted scalar style. */
name|YAML_SINGLE_QUOTED_SCALAR_STYLE
block|,
comment|/** The double-quoted scalar style. */
name|YAML_DOUBLE_QUOTED_SCALAR_STYLE
block|,
comment|/** The literal scalar style. */
name|YAML_LITERAL_SCALAR_STYLE
block|,
comment|/** The folded scalar style. */
name|YAML_FOLDED_SCALAR_STYLE
block|}
name|yaml_scalar_style_t
typedef|;
comment|/** Sequence styles. */
typedef|typedef
enum|enum
name|yaml_sequence_style_e
block|{
comment|/** Let the emitter choose the style. */
name|YAML_ANY_SEQUENCE_STYLE
block|,
comment|/** The block sequence style. */
name|YAML_BLOCK_SEQUENCE_STYLE
block|,
comment|/** The flow sequence style. */
name|YAML_FLOW_SEQUENCE_STYLE
block|}
name|yaml_sequence_style_t
typedef|;
comment|/** Mapping styles. */
typedef|typedef
enum|enum
name|yaml_mapping_style_e
block|{
comment|/** Let the emitter choose the style. */
name|YAML_ANY_MAPPING_STYLE
block|,
comment|/** The block mapping style. */
name|YAML_BLOCK_MAPPING_STYLE
block|,
comment|/** The flow mapping style. */
name|YAML_FLOW_MAPPING_STYLE
comment|/*    YAML_FLOW_SET_MAPPING_STYLE   */
block|}
name|yaml_mapping_style_t
typedef|;
comment|/** @} */
comment|/**  * @defgroup tokens Tokens  * @{  */
comment|/** Token types. */
typedef|typedef
enum|enum
name|yaml_token_type_e
block|{
comment|/** An empty token. */
name|YAML_NO_TOKEN
block|,
comment|/** A STREAM-START token. */
name|YAML_STREAM_START_TOKEN
block|,
comment|/** A STREAM-END token. */
name|YAML_STREAM_END_TOKEN
block|,
comment|/** A VERSION-DIRECTIVE token. */
name|YAML_VERSION_DIRECTIVE_TOKEN
block|,
comment|/** A TAG-DIRECTIVE token. */
name|YAML_TAG_DIRECTIVE_TOKEN
block|,
comment|/** A DOCUMENT-START token. */
name|YAML_DOCUMENT_START_TOKEN
block|,
comment|/** A DOCUMENT-END token. */
name|YAML_DOCUMENT_END_TOKEN
block|,
comment|/** A BLOCK-SEQUENCE-START token. */
name|YAML_BLOCK_SEQUENCE_START_TOKEN
block|,
comment|/** A BLOCK-SEQUENCE-END token. */
name|YAML_BLOCK_MAPPING_START_TOKEN
block|,
comment|/** A BLOCK-END token. */
name|YAML_BLOCK_END_TOKEN
block|,
comment|/** A FLOW-SEQUENCE-START token. */
name|YAML_FLOW_SEQUENCE_START_TOKEN
block|,
comment|/** A FLOW-SEQUENCE-END token. */
name|YAML_FLOW_SEQUENCE_END_TOKEN
block|,
comment|/** A FLOW-MAPPING-START token. */
name|YAML_FLOW_MAPPING_START_TOKEN
block|,
comment|/** A FLOW-MAPPING-END token. */
name|YAML_FLOW_MAPPING_END_TOKEN
block|,
comment|/** A BLOCK-ENTRY token. */
name|YAML_BLOCK_ENTRY_TOKEN
block|,
comment|/** A FLOW-ENTRY token. */
name|YAML_FLOW_ENTRY_TOKEN
block|,
comment|/** A KEY token. */
name|YAML_KEY_TOKEN
block|,
comment|/** A VALUE token. */
name|YAML_VALUE_TOKEN
block|,
comment|/** An ALIAS token. */
name|YAML_ALIAS_TOKEN
block|,
comment|/** An ANCHOR token. */
name|YAML_ANCHOR_TOKEN
block|,
comment|/** A TAG token. */
name|YAML_TAG_TOKEN
block|,
comment|/** A SCALAR token. */
name|YAML_SCALAR_TOKEN
block|}
name|yaml_token_type_t
typedef|;
comment|/** The token structure. */
typedef|typedef
struct|struct
name|yaml_token_s
block|{
comment|/** The token type. */
name|yaml_token_type_t
name|type
decl_stmt|;
comment|/** The token data. */
union|union
block|{
comment|/** The stream start (for @c YAML_STREAM_START_TOKEN). */
struct|struct
block|{
comment|/** The stream encoding. */
name|yaml_encoding_t
name|encoding
decl_stmt|;
block|}
name|stream_start
struct|;
comment|/** The alias (for @c YAML_ALIAS_TOKEN). */
struct|struct
block|{
comment|/** The alias value. */
name|yaml_char_t
modifier|*
name|value
decl_stmt|;
block|}
name|alias
struct|;
comment|/** The anchor (for @c YAML_ANCHOR_TOKEN). */
struct|struct
block|{
comment|/** The anchor value. */
name|yaml_char_t
modifier|*
name|value
decl_stmt|;
block|}
name|anchor
struct|;
comment|/** The tag (for @c YAML_TAG_TOKEN). */
struct|struct
block|{
comment|/** The tag handle. */
name|yaml_char_t
modifier|*
name|handle
decl_stmt|;
comment|/** The tag suffix. */
name|yaml_char_t
modifier|*
name|suffix
decl_stmt|;
block|}
name|tag
struct|;
comment|/** The scalar value (for @c YAML_SCALAR_TOKEN). */
struct|struct
block|{
comment|/** The scalar value. */
name|yaml_char_t
modifier|*
name|value
decl_stmt|;
comment|/** The length of the scalar value. */
name|size_t
name|length
decl_stmt|;
comment|/** The scalar style. */
name|yaml_scalar_style_t
name|style
decl_stmt|;
block|}
name|scalar
struct|;
comment|/** The version directive (for @c YAML_VERSION_DIRECTIVE_TOKEN). */
struct|struct
block|{
comment|/** The major version number. */
name|int
name|major
decl_stmt|;
comment|/** The minor version number. */
name|int
name|minor
decl_stmt|;
block|}
name|version_directive
struct|;
comment|/** The tag directive (for @c YAML_TAG_DIRECTIVE_TOKEN). */
struct|struct
block|{
comment|/** The tag handle. */
name|yaml_char_t
modifier|*
name|handle
decl_stmt|;
comment|/** The tag prefix. */
name|yaml_char_t
modifier|*
name|prefix
decl_stmt|;
block|}
name|tag_directive
struct|;
block|}
name|data
union|;
comment|/** The beginning of the token. */
name|yaml_mark_t
name|start_mark
decl_stmt|;
comment|/** The end of the token. */
name|yaml_mark_t
name|end_mark
decl_stmt|;
block|}
name|yaml_token_t
typedef|;
comment|/**  * Free any memory allocated for a token object.  *  * @param[in,out]   token   A token object.  */
name|YAML_DECLARE
argument_list|(
argument|void
argument_list|)
name|yaml_token_delete
argument_list|(
name|yaml_token_t
operator|*
name|token
argument_list|)
expr_stmt|;
comment|/** @} */
comment|/**  * @defgroup events Events  * @{  */
comment|/** Event types. */
typedef|typedef
enum|enum
name|yaml_event_type_e
block|{
comment|/** An empty event. */
name|YAML_NO_EVENT
block|,
comment|/** A STREAM-START event. */
name|YAML_STREAM_START_EVENT
block|,
comment|/** A STREAM-END event. */
name|YAML_STREAM_END_EVENT
block|,
comment|/** A DOCUMENT-START event. */
name|YAML_DOCUMENT_START_EVENT
block|,
comment|/** A DOCUMENT-END event. */
name|YAML_DOCUMENT_END_EVENT
block|,
comment|/** An ALIAS event. */
name|YAML_ALIAS_EVENT
block|,
comment|/** A SCALAR event. */
name|YAML_SCALAR_EVENT
block|,
comment|/** A SEQUENCE-START event. */
name|YAML_SEQUENCE_START_EVENT
block|,
comment|/** A SEQUENCE-END event. */
name|YAML_SEQUENCE_END_EVENT
block|,
comment|/** A MAPPING-START event. */
name|YAML_MAPPING_START_EVENT
block|,
comment|/** A MAPPING-END event. */
name|YAML_MAPPING_END_EVENT
block|}
name|yaml_event_type_t
typedef|;
comment|/** The event structure. */
typedef|typedef
struct|struct
name|yaml_event_s
block|{
comment|/** The event type. */
name|yaml_event_type_t
name|type
decl_stmt|;
comment|/** The event data. */
union|union
block|{
comment|/** The stream parameters (for @c YAML_STREAM_START_EVENT). */
struct|struct
block|{
comment|/** The document encoding. */
name|yaml_encoding_t
name|encoding
decl_stmt|;
block|}
name|stream_start
struct|;
comment|/** The document parameters (for @c YAML_DOCUMENT_START_EVENT). */
struct|struct
block|{
comment|/** The version directive. */
name|yaml_version_directive_t
modifier|*
name|version_directive
decl_stmt|;
comment|/** The list of tag directives. */
struct|struct
block|{
comment|/** The beginning of the tag directives list. */
name|yaml_tag_directive_t
modifier|*
name|start
decl_stmt|;
comment|/** The end of the tag directives list. */
name|yaml_tag_directive_t
modifier|*
name|end
decl_stmt|;
block|}
name|tag_directives
struct|;
comment|/** Is the document indicator implicit? */
name|int
name|implicit
decl_stmt|;
block|}
name|document_start
struct|;
comment|/** The document end parameters (for @c YAML_DOCUMENT_END_EVENT). */
struct|struct
block|{
comment|/** Is the document end indicator implicit? */
name|int
name|implicit
decl_stmt|;
block|}
name|document_end
struct|;
comment|/** The alias parameters (for @c YAML_ALIAS_EVENT). */
struct|struct
block|{
comment|/** The anchor. */
name|yaml_char_t
modifier|*
name|anchor
decl_stmt|;
block|}
name|alias
struct|;
comment|/** The scalar parameters (for @c YAML_SCALAR_EVENT). */
struct|struct
block|{
comment|/** The anchor. */
name|yaml_char_t
modifier|*
name|anchor
decl_stmt|;
comment|/** The tag. */
name|yaml_char_t
modifier|*
name|tag
decl_stmt|;
comment|/** The scalar value. */
name|yaml_char_t
modifier|*
name|value
decl_stmt|;
comment|/** The length of the scalar value. */
name|size_t
name|length
decl_stmt|;
comment|/** Is the tag optional for the plain style? */
name|int
name|plain_implicit
decl_stmt|;
comment|/** Is the tag optional for any non-plain style? */
name|int
name|quoted_implicit
decl_stmt|;
comment|/** The scalar style. */
name|yaml_scalar_style_t
name|style
decl_stmt|;
block|}
name|scalar
struct|;
comment|/** The sequence parameters (for @c YAML_SEQUENCE_START_EVENT). */
struct|struct
block|{
comment|/** The anchor. */
name|yaml_char_t
modifier|*
name|anchor
decl_stmt|;
comment|/** The tag. */
name|yaml_char_t
modifier|*
name|tag
decl_stmt|;
comment|/** Is the tag optional? */
name|int
name|implicit
decl_stmt|;
comment|/** The sequence style. */
name|yaml_sequence_style_t
name|style
decl_stmt|;
block|}
name|sequence_start
struct|;
comment|/** The mapping parameters (for @c YAML_MAPPING_START_EVENT). */
struct|struct
block|{
comment|/** The anchor. */
name|yaml_char_t
modifier|*
name|anchor
decl_stmt|;
comment|/** The tag. */
name|yaml_char_t
modifier|*
name|tag
decl_stmt|;
comment|/** Is the tag optional? */
name|int
name|implicit
decl_stmt|;
comment|/** The mapping style. */
name|yaml_mapping_style_t
name|style
decl_stmt|;
block|}
name|mapping_start
struct|;
block|}
name|data
union|;
comment|/** The beginning of the event. */
name|yaml_mark_t
name|start_mark
decl_stmt|;
comment|/** The end of the event. */
name|yaml_mark_t
name|end_mark
decl_stmt|;
block|}
name|yaml_event_t
typedef|;
comment|/**  * Create the STREAM-START event.  *  * @param[out]      event       An empty event object.  * @param[in]       encoding    The stream encoding.  *  * @returns @c 1 if the function succeeded, @c 0 on error.  */
name|YAML_DECLARE
argument_list|(
argument|int
argument_list|)
name|yaml_stream_start_event_initialize
argument_list|(
argument|yaml_event_t *event
argument_list|,
argument|yaml_encoding_t encoding
argument_list|)
empty_stmt|;
comment|/**  * Create the STREAM-END event.  *  * @param[out]      event       An empty event object.  *  * @returns @c 1 if the function succeeded, @c 0 on error.  */
name|YAML_DECLARE
argument_list|(
argument|int
argument_list|)
name|yaml_stream_end_event_initialize
argument_list|(
name|yaml_event_t
operator|*
name|event
argument_list|)
expr_stmt|;
comment|/**  * Create the DOCUMENT-START event.  *  * The @a implicit argument is considered as a stylistic parameter and may be  * ignored by the emitter.  *  * @param[out]      event                   An empty event object.  * @param[in]       version_directive       The %YAML directive value or  *                                          @c NULL.  * @param[in]       tag_directives_start    The beginning of the %TAG  *                                          directives list.  * @param[in]       tag_directives_end      The end of the %TAG directives  *                                          list.  * @param[in]       implicit                If the document start indicator is  *                                          implicit.  *  * @returns @c 1 if the function succeeded, @c 0 on error.  */
name|YAML_DECLARE
argument_list|(
argument|int
argument_list|)
name|yaml_document_start_event_initialize
argument_list|(
argument|yaml_event_t *event
argument_list|,
argument|yaml_version_directive_t *version_directive
argument_list|,
argument|yaml_tag_directive_t *tag_directives_start
argument_list|,
argument|yaml_tag_directive_t *tag_directives_end
argument_list|,
argument|int implicit
argument_list|)
empty_stmt|;
comment|/**  * Create the DOCUMENT-END event.  *  * The @a implicit argument is considered as a stylistic parameter and may be  * ignored by the emitter.  *  * @param[out]      event       An empty event object.  * @param[in]       implicit    If the document end indicator is implicit.  *  * @returns @c 1 if the function succeeded, @c 0 on error.  */
name|YAML_DECLARE
argument_list|(
argument|int
argument_list|)
name|yaml_document_end_event_initialize
argument_list|(
argument|yaml_event_t *event
argument_list|,
argument|int implicit
argument_list|)
empty_stmt|;
comment|/**  * Create an ALIAS event.  *  * @param[out]      event       An empty event object.  * @param[in]       anchor      The anchor value.  *  * @returns @c 1 if the function succeeded, @c 0 on error.  */
name|YAML_DECLARE
argument_list|(
argument|int
argument_list|)
name|yaml_alias_event_initialize
argument_list|(
name|yaml_event_t
operator|*
name|event
argument_list|,
name|yaml_char_t
operator|*
name|anchor
argument_list|)
expr_stmt|;
comment|/**  * Create a SCALAR event.  *  * The @a style argument may be ignored by the emitter.  *  * Either the @a tag attribute or one of the @a plain_implicit and  * @a quoted_implicit flags must be set.  *  * @param[out]      event           An empty event object.  * @param[in]       anchor          The scalar anchor or @c NULL.  * @param[in]       tag             The scalar tag or @c NULL.  * @param[in]       value           The scalar value.  * @param[in]       length          The length of the scalar value.  * @param[in]       plain_implicit  If the tag may be omitted for the plain  *                                  style.  * @param[in]       quoted_implicit If the tag may be omitted for any  *                                  non-plain style.  * @param[in]       style           The scalar style.  *  * @returns @c 1 if the function succeeded, @c 0 on error.  */
name|YAML_DECLARE
argument_list|(
argument|int
argument_list|)
name|yaml_scalar_event_initialize
argument_list|(
argument|yaml_event_t *event
argument_list|,
argument|yaml_char_t *anchor
argument_list|,
argument|yaml_char_t *tag
argument_list|,
argument|yaml_char_t *value
argument_list|,
argument|int length
argument_list|,
argument|int plain_implicit
argument_list|,
argument|int quoted_implicit
argument_list|,
argument|yaml_scalar_style_t style
argument_list|)
empty_stmt|;
comment|/**  * Create a SEQUENCE-START event.  *  * The @a style argument may be ignored by the emitter.  *  * Either the @a tag attribute or the @a implicit flag must be set.  *  * @param[out]      event       An empty event object.  * @param[in]       anchor      The sequence anchor or @c NULL.  * @param[in]       tag         The sequence tag or @c NULL.  * @param[in]       implicit    If the tag may be omitted.  * @param[in]       style       The sequence style.  *  * @returns @c 1 if the function succeeded, @c 0 on error.  */
name|YAML_DECLARE
argument_list|(
argument|int
argument_list|)
name|yaml_sequence_start_event_initialize
argument_list|(
argument|yaml_event_t *event
argument_list|,
argument|yaml_char_t *anchor
argument_list|,
argument|yaml_char_t *tag
argument_list|,
argument|int implicit
argument_list|,
argument|yaml_sequence_style_t style
argument_list|)
empty_stmt|;
comment|/**  * Create a SEQUENCE-END event.  *  * @param[out]      event       An empty event object.  *  * @returns @c 1 if the function succeeded, @c 0 on error.  */
name|YAML_DECLARE
argument_list|(
argument|int
argument_list|)
name|yaml_sequence_end_event_initialize
argument_list|(
name|yaml_event_t
operator|*
name|event
argument_list|)
expr_stmt|;
comment|/**  * Create a MAPPING-START event.  *  * The @a style argument may be ignored by the emitter.  *  * Either the @a tag attribute or the @a implicit flag must be set.  *  * @param[out]      event       An empty event object.  * @param[in]       anchor      The mapping anchor or @c NULL.  * @param[in]       tag         The mapping tag or @c NULL.  * @param[in]       implicit    If the tag may be omitted.  * @param[in]       style       The mapping style.  *  * @returns @c 1 if the function succeeded, @c 0 on error.  */
name|YAML_DECLARE
argument_list|(
argument|int
argument_list|)
name|yaml_mapping_start_event_initialize
argument_list|(
argument|yaml_event_t *event
argument_list|,
argument|yaml_char_t *anchor
argument_list|,
argument|yaml_char_t *tag
argument_list|,
argument|int implicit
argument_list|,
argument|yaml_mapping_style_t style
argument_list|)
empty_stmt|;
comment|/**  * Create a MAPPING-END event.  *  * @param[out]      event       An empty event object.  *  * @returns @c 1 if the function succeeded, @c 0 on error.  */
name|YAML_DECLARE
argument_list|(
argument|int
argument_list|)
name|yaml_mapping_end_event_initialize
argument_list|(
name|yaml_event_t
operator|*
name|event
argument_list|)
expr_stmt|;
comment|/**  * Free any memory allocated for an event object.  *  * @param[in,out]   event   An event object.  */
name|YAML_DECLARE
argument_list|(
argument|void
argument_list|)
name|yaml_event_delete
argument_list|(
name|yaml_event_t
operator|*
name|event
argument_list|)
expr_stmt|;
comment|/** @} */
comment|/**  * @defgroup nodes Nodes  * @{  */
comment|/** The tag @c !!null with the only possible value: @c null. */
define|#
directive|define
name|YAML_NULL_TAG
value|"tag:yaml.org,2002:null"
comment|/** The tag @c !!bool with the values: @c true and @c falce. */
define|#
directive|define
name|YAML_BOOL_TAG
value|"tag:yaml.org,2002:bool"
comment|/** The tag @c !!str for string values. */
define|#
directive|define
name|YAML_STR_TAG
value|"tag:yaml.org,2002:str"
comment|/** The tag @c !!int for integer values. */
define|#
directive|define
name|YAML_INT_TAG
value|"tag:yaml.org,2002:int"
comment|/** The tag @c !!float for float values. */
define|#
directive|define
name|YAML_FLOAT_TAG
value|"tag:yaml.org,2002:float"
comment|/** The tag @c !!timestamp for date and time values. */
define|#
directive|define
name|YAML_TIMESTAMP_TAG
value|"tag:yaml.org,2002:timestamp"
comment|/** The tag @c !!seq is used to denote sequences. */
define|#
directive|define
name|YAML_SEQ_TAG
value|"tag:yaml.org,2002:seq"
comment|/** The tag @c !!map is used to denote mapping. */
define|#
directive|define
name|YAML_MAP_TAG
value|"tag:yaml.org,2002:map"
comment|/** The default scalar tag is @c !!str. */
define|#
directive|define
name|YAML_DEFAULT_SCALAR_TAG
value|YAML_STR_TAG
comment|/** The default sequence tag is @c !!seq. */
define|#
directive|define
name|YAML_DEFAULT_SEQUENCE_TAG
value|YAML_SEQ_TAG
comment|/** The default mapping tag is @c !!map. */
define|#
directive|define
name|YAML_DEFAULT_MAPPING_TAG
value|YAML_MAP_TAG
comment|/** Node types. */
typedef|typedef
enum|enum
name|yaml_node_type_e
block|{
comment|/** An empty node. */
name|YAML_NO_NODE
block|,
comment|/** A scalar node. */
name|YAML_SCALAR_NODE
block|,
comment|/** A sequence node. */
name|YAML_SEQUENCE_NODE
block|,
comment|/** A mapping node. */
name|YAML_MAPPING_NODE
block|}
name|yaml_node_type_t
typedef|;
comment|/** The forward definition of a document node structure. */
typedef|typedef
name|struct
name|yaml_node_s
name|yaml_node_t
typedef|;
comment|/** An element of a sequence node. */
typedef|typedef
name|int
name|yaml_node_item_t
typedef|;
comment|/** An element of a mapping node. */
typedef|typedef
struct|struct
name|yaml_node_pair_s
block|{
comment|/** The key of the element. */
name|int
name|key
decl_stmt|;
comment|/** The value of the element. */
name|int
name|value
decl_stmt|;
block|}
name|yaml_node_pair_t
typedef|;
comment|/** The node structure. */
struct|struct
name|yaml_node_s
block|{
comment|/** The node type. */
name|yaml_node_type_t
name|type
decl_stmt|;
comment|/** The node tag. */
name|yaml_char_t
modifier|*
name|tag
decl_stmt|;
comment|/** The node data. */
union|union
block|{
comment|/** The scalar parameters (for @c YAML_SCALAR_NODE). */
struct|struct
block|{
comment|/** The scalar value. */
name|yaml_char_t
modifier|*
name|value
decl_stmt|;
comment|/** The length of the scalar value. */
name|size_t
name|length
decl_stmt|;
comment|/** The scalar style. */
name|yaml_scalar_style_t
name|style
decl_stmt|;
block|}
name|scalar
struct|;
comment|/** The sequence parameters (for @c YAML_SEQUENCE_NODE). */
struct|struct
block|{
comment|/** The stack of sequence items. */
struct|struct
block|{
comment|/** The beginning of the stack. */
name|yaml_node_item_t
modifier|*
name|start
decl_stmt|;
comment|/** The end of the stack. */
name|yaml_node_item_t
modifier|*
name|end
decl_stmt|;
comment|/** The top of the stack. */
name|yaml_node_item_t
modifier|*
name|top
decl_stmt|;
block|}
name|items
struct|;
comment|/** The sequence style. */
name|yaml_sequence_style_t
name|style
decl_stmt|;
block|}
name|sequence
struct|;
comment|/** The mapping parameters (for @c YAML_MAPPING_NODE). */
struct|struct
block|{
comment|/** The stack of mapping pairs (key, value). */
struct|struct
block|{
comment|/** The beginning of the stack. */
name|yaml_node_pair_t
modifier|*
name|start
decl_stmt|;
comment|/** The end of the stack. */
name|yaml_node_pair_t
modifier|*
name|end
decl_stmt|;
comment|/** The top of the stack. */
name|yaml_node_pair_t
modifier|*
name|top
decl_stmt|;
block|}
name|pairs
struct|;
comment|/** The mapping style. */
name|yaml_mapping_style_t
name|style
decl_stmt|;
block|}
name|mapping
struct|;
block|}
name|data
union|;
comment|/** The beginning of the node. */
name|yaml_mark_t
name|start_mark
decl_stmt|;
comment|/** The end of the node. */
name|yaml_mark_t
name|end_mark
decl_stmt|;
block|}
struct|;
comment|/** The document structure. */
typedef|typedef
struct|struct
name|yaml_document_s
block|{
comment|/** The document nodes. */
struct|struct
block|{
comment|/** The beginning of the stack. */
name|yaml_node_t
modifier|*
name|start
decl_stmt|;
comment|/** The end of the stack. */
name|yaml_node_t
modifier|*
name|end
decl_stmt|;
comment|/** The top of the stack. */
name|yaml_node_t
modifier|*
name|top
decl_stmt|;
block|}
name|nodes
struct|;
comment|/** The version directive. */
name|yaml_version_directive_t
modifier|*
name|version_directive
decl_stmt|;
comment|/** The list of tag directives. */
struct|struct
block|{
comment|/** The beginning of the tag directives list. */
name|yaml_tag_directive_t
modifier|*
name|start
decl_stmt|;
comment|/** The end of the tag directives list. */
name|yaml_tag_directive_t
modifier|*
name|end
decl_stmt|;
block|}
name|tag_directives
struct|;
comment|/** Is the document start indicator implicit? */
name|int
name|start_implicit
decl_stmt|;
comment|/** Is the document end indicator implicit? */
name|int
name|end_implicit
decl_stmt|;
comment|/** The beginning of the document. */
name|yaml_mark_t
name|start_mark
decl_stmt|;
comment|/** The end of the document. */
name|yaml_mark_t
name|end_mark
decl_stmt|;
block|}
name|yaml_document_t
typedef|;
comment|/**  * Create a YAML document.  *  * @param[out]      document                An empty document object.  * @param[in]       version_directive       The %YAML directive value or  *                                          @c NULL.  * @param[in]       tag_directives_start    The beginning of the %TAG  *                                          directives list.  * @param[in]       tag_directives_end      The end of the %TAG directives  *                                          list.  * @param[in]       start_implicit          If the document start indicator is  *                                          implicit.  * @param[in]       end_implicit            If the document end indicator is  *                                          implicit.  *  * @returns @c 1 if the function succeeded, @c 0 on error.  */
name|YAML_DECLARE
argument_list|(
argument|int
argument_list|)
name|yaml_document_initialize
argument_list|(
argument|yaml_document_t *document
argument_list|,
argument|yaml_version_directive_t *version_directive
argument_list|,
argument|yaml_tag_directive_t *tag_directives_start
argument_list|,
argument|yaml_tag_directive_t *tag_directives_end
argument_list|,
argument|int start_implicit
argument_list|,
argument|int end_implicit
argument_list|)
empty_stmt|;
comment|/**  * Delete a YAML document and all its nodes.  *  * @param[in,out]   document        A document object.  */
name|YAML_DECLARE
argument_list|(
argument|void
argument_list|)
name|yaml_document_delete
argument_list|(
name|yaml_document_t
operator|*
name|document
argument_list|)
expr_stmt|;
comment|/**  * Get a node of a YAML document.  *  * The pointer returned by this function is valid until any of the functions  * modifying the documents are called.  *  * @param[in]       document        A document object.  * @param[in]       index           The node id.  *  * @returns the node objct or @c NULL if @c node_id is out of range.  */
name|YAML_DECLARE
argument_list|(
argument|yaml_node_t *
argument_list|)
name|yaml_document_get_node
argument_list|(
argument|yaml_document_t *document
argument_list|,
argument|int index
argument_list|)
empty_stmt|;
comment|/**  * Get the root of a YAML document node.  *  * The root object is the first object added to the document.  *  * The pointer returned by this function is valid until any of the functions  * modifying the documents are called.  *  * An empty document produced by the parser signifies the end of a YAML  * stream.  *  * @param[in]       document        A document object.  *  * @returns the node object or @c NULL if the document is empty.  */
name|YAML_DECLARE
argument_list|(
argument|yaml_node_t *
argument_list|)
name|yaml_document_get_root_node
argument_list|(
name|yaml_document_t
operator|*
name|document
argument_list|)
expr_stmt|;
comment|/**  * Create a SCALAR node and attach it to the document.  *  * The @a style argument may be ignored by the emitter.  *  * @param[in,out]   document        A document object.  * @param[in]       tag             The scalar tag.  * @param[in]       value           The scalar value.  * @param[in]       length          The length of the scalar value.  * @param[in]       style           The scalar style.  *  * @returns the node id or @c 0 on error.  */
name|YAML_DECLARE
argument_list|(
argument|int
argument_list|)
name|yaml_document_add_scalar
argument_list|(
argument|yaml_document_t *document
argument_list|,
argument|yaml_char_t *tag
argument_list|,
argument|yaml_char_t *value
argument_list|,
argument|int length
argument_list|,
argument|yaml_scalar_style_t style
argument_list|)
empty_stmt|;
comment|/**  * Create a SEQUENCE node and attach it to the document.  *  * The @a style argument may be ignored by the emitter.  *  * @param[in,out]   document    A document object.  * @param[in]       tag         The sequence tag.  * @param[in]       style       The sequence style.  *  * @returns the node id or @c 0 on error.  */
name|YAML_DECLARE
argument_list|(
argument|int
argument_list|)
name|yaml_document_add_sequence
argument_list|(
argument|yaml_document_t *document
argument_list|,
argument|yaml_char_t *tag
argument_list|,
argument|yaml_sequence_style_t style
argument_list|)
empty_stmt|;
comment|/**  * Create a MAPPING node and attach it to the document.  *  * The @a style argument may be ignored by the emitter.  *  * @param[in,out]   document    A document object.  * @param[in]       tag         The sequence tag.  * @param[in]       style       The sequence style.  *  * @returns the node id or @c 0 on error.  */
name|YAML_DECLARE
argument_list|(
argument|int
argument_list|)
name|yaml_document_add_mapping
argument_list|(
argument|yaml_document_t *document
argument_list|,
argument|yaml_char_t *tag
argument_list|,
argument|yaml_mapping_style_t style
argument_list|)
empty_stmt|;
comment|/**  * Add an item to a SEQUENCE node.  *  * @param[in,out]   document    A document object.  * @param[in]       sequence    The sequence node id.  * @param[in]       item        The item node id. *  * @returns @c 1 if the function succeeded, @c 0 on error.  */
name|YAML_DECLARE
argument_list|(
argument|int
argument_list|)
name|yaml_document_append_sequence_item
argument_list|(
argument|yaml_document_t *document
argument_list|,
argument|int sequence
argument_list|,
argument|int item
argument_list|)
empty_stmt|;
comment|/**  * Add a pair of a key and a value to a MAPPING node.  *  * @param[in,out]   document    A document object.  * @param[in]       mapping     The mapping node id.  * @param[in]       key         The key node id.  * @param[in]       value       The value node id. *  * @returns @c 1 if the function succeeded, @c 0 on error.  */
name|YAML_DECLARE
argument_list|(
argument|int
argument_list|)
name|yaml_document_append_mapping_pair
argument_list|(
argument|yaml_document_t *document
argument_list|,
argument|int mapping
argument_list|,
argument|int key
argument_list|,
argument|int value
argument_list|)
empty_stmt|;
comment|/** @} */
comment|/**  * @defgroup parser Parser Definitions  * @{  */
comment|/**  * The prototype of a read handler.  *  * The read handler is called when the parser needs to read more bytes from the  * source.  The handler should write not more than @a size bytes to the @a  * buffer.  The number of written bytes should be set to the @a length variable.  *  * @param[in,out]   data        A pointer to an application data specified by  *                              yaml_parser_set_input().  * @param[out]      buffer      The buffer to write the data from the source.  * @param[in]       size        The size of the buffer.  * @param[out]      size_read   The actual number of bytes read from the source.  *  * @returns On success, the handler should return @c 1.  If the handler failed,  * the returned value should be @c 0.  On EOF, the handler should set the  * @a size_read to @c 0 and return @c 1.  */
typedef|typedef
name|int
name|yaml_read_handler_t
parameter_list|(
name|void
modifier|*
name|data
parameter_list|,
name|unsigned
name|char
modifier|*
name|buffer
parameter_list|,
name|size_t
name|size
parameter_list|,
name|size_t
modifier|*
name|size_read
parameter_list|)
function_decl|;
comment|/**  * This structure holds information about a potential simple key.  */
typedef|typedef
struct|struct
name|yaml_simple_key_s
block|{
comment|/** Is a simple key possible? */
name|int
name|possible
decl_stmt|;
comment|/** Is a simple key required? */
name|int
name|required
decl_stmt|;
comment|/** The number of the token. */
name|size_t
name|token_number
decl_stmt|;
comment|/** The position mark. */
name|yaml_mark_t
name|mark
decl_stmt|;
block|}
name|yaml_simple_key_t
typedef|;
comment|/**  * The states of the parser.  */
typedef|typedef
enum|enum
name|yaml_parser_state_e
block|{
comment|/** Expect STREAM-START. */
name|YAML_PARSE_STREAM_START_STATE
block|,
comment|/** Expect the beginning of an implicit document. */
name|YAML_PARSE_IMPLICIT_DOCUMENT_START_STATE
block|,
comment|/** Expect DOCUMENT-START. */
name|YAML_PARSE_DOCUMENT_START_STATE
block|,
comment|/** Expect the content of a document. */
name|YAML_PARSE_DOCUMENT_CONTENT_STATE
block|,
comment|/** Expect DOCUMENT-END. */
name|YAML_PARSE_DOCUMENT_END_STATE
block|,
comment|/** Expect a block node. */
name|YAML_PARSE_BLOCK_NODE_STATE
block|,
comment|/** Expect a block node or indentless sequence. */
name|YAML_PARSE_BLOCK_NODE_OR_INDENTLESS_SEQUENCE_STATE
block|,
comment|/** Expect a flow node. */
name|YAML_PARSE_FLOW_NODE_STATE
block|,
comment|/** Expect the first entry of a block sequence. */
name|YAML_PARSE_BLOCK_SEQUENCE_FIRST_ENTRY_STATE
block|,
comment|/** Expect an entry of a block sequence. */
name|YAML_PARSE_BLOCK_SEQUENCE_ENTRY_STATE
block|,
comment|/** Expect an entry of an indentless sequence. */
name|YAML_PARSE_INDENTLESS_SEQUENCE_ENTRY_STATE
block|,
comment|/** Expect the first key of a block mapping. */
name|YAML_PARSE_BLOCK_MAPPING_FIRST_KEY_STATE
block|,
comment|/** Expect a block mapping key. */
name|YAML_PARSE_BLOCK_MAPPING_KEY_STATE
block|,
comment|/** Expect a block mapping value. */
name|YAML_PARSE_BLOCK_MAPPING_VALUE_STATE
block|,
comment|/** Expect the first entry of a flow sequence. */
name|YAML_PARSE_FLOW_SEQUENCE_FIRST_ENTRY_STATE
block|,
comment|/** Expect an entry of a flow sequence. */
name|YAML_PARSE_FLOW_SEQUENCE_ENTRY_STATE
block|,
comment|/** Expect a key of an ordered mapping. */
name|YAML_PARSE_FLOW_SEQUENCE_ENTRY_MAPPING_KEY_STATE
block|,
comment|/** Expect a value of an ordered mapping. */
name|YAML_PARSE_FLOW_SEQUENCE_ENTRY_MAPPING_VALUE_STATE
block|,
comment|/** Expect the and of an ordered mapping entry. */
name|YAML_PARSE_FLOW_SEQUENCE_ENTRY_MAPPING_END_STATE
block|,
comment|/** Expect the first key of a flow mapping. */
name|YAML_PARSE_FLOW_MAPPING_FIRST_KEY_STATE
block|,
comment|/** Expect a key of a flow mapping. */
name|YAML_PARSE_FLOW_MAPPING_KEY_STATE
block|,
comment|/** Expect a value of a flow mapping. */
name|YAML_PARSE_FLOW_MAPPING_VALUE_STATE
block|,
comment|/** Expect an empty value of a flow mapping. */
name|YAML_PARSE_FLOW_MAPPING_EMPTY_VALUE_STATE
block|,
comment|/** Expect nothing. */
name|YAML_PARSE_END_STATE
block|}
name|yaml_parser_state_t
typedef|;
comment|/**  * This structure holds aliases data.  */
typedef|typedef
struct|struct
name|yaml_alias_data_s
block|{
comment|/** The anchor. */
name|yaml_char_t
modifier|*
name|anchor
decl_stmt|;
comment|/** The node id. */
name|int
name|index
decl_stmt|;
comment|/** The anchor mark. */
name|yaml_mark_t
name|mark
decl_stmt|;
block|}
name|yaml_alias_data_t
typedef|;
comment|/**  * The parser structure.  *  * All members are internal.  Manage the structure using the @c yaml_parser_  * family of functions.  */
typedef|typedef
struct|struct
name|yaml_parser_s
block|{
comment|/**      * @name Error handling      * @{      */
comment|/** Error type. */
name|yaml_error_type_t
name|error
decl_stmt|;
comment|/** Error description. */
specifier|const
name|char
modifier|*
name|problem
decl_stmt|;
comment|/** The byte about which the problem occured. */
name|size_t
name|problem_offset
decl_stmt|;
comment|/** The problematic value (@c -1 is none). */
name|int
name|problem_value
decl_stmt|;
comment|/** The problem position. */
name|yaml_mark_t
name|problem_mark
decl_stmt|;
comment|/** The error context. */
specifier|const
name|char
modifier|*
name|context
decl_stmt|;
comment|/** The context position. */
name|yaml_mark_t
name|context_mark
decl_stmt|;
comment|/**      * @}      */
comment|/**      * @name Reader stuff      * @{      */
comment|/** Read handler. */
name|yaml_read_handler_t
modifier|*
name|read_handler
decl_stmt|;
comment|/** A pointer for passing to the read handler. */
name|void
modifier|*
name|read_handler_data
decl_stmt|;
comment|/** Standard (string or file) input data. */
union|union
block|{
comment|/** String input data. */
struct|struct
block|{
comment|/** The string start pointer. */
specifier|const
name|unsigned
name|char
modifier|*
name|start
decl_stmt|;
comment|/** The string end pointer. */
specifier|const
name|unsigned
name|char
modifier|*
name|end
decl_stmt|;
comment|/** The string current position. */
specifier|const
name|unsigned
name|char
modifier|*
name|current
decl_stmt|;
block|}
name|string
struct|;
comment|/** File input data. */
name|FILE
modifier|*
name|file
decl_stmt|;
block|}
name|input
union|;
comment|/** EOF flag */
name|int
name|eof
decl_stmt|;
comment|/** The working buffer. */
struct|struct
block|{
comment|/** The beginning of the buffer. */
name|yaml_char_t
modifier|*
name|start
decl_stmt|;
comment|/** The end of the buffer. */
name|yaml_char_t
modifier|*
name|end
decl_stmt|;
comment|/** The current position of the buffer. */
name|yaml_char_t
modifier|*
name|pointer
decl_stmt|;
comment|/** The last filled position of the buffer. */
name|yaml_char_t
modifier|*
name|last
decl_stmt|;
block|}
name|buffer
struct|;
comment|/* The number of unread characters in the buffer. */
name|size_t
name|unread
decl_stmt|;
comment|/** The raw buffer. */
struct|struct
block|{
comment|/** The beginning of the buffer. */
name|unsigned
name|char
modifier|*
name|start
decl_stmt|;
comment|/** The end of the buffer. */
name|unsigned
name|char
modifier|*
name|end
decl_stmt|;
comment|/** The current position of the buffer. */
name|unsigned
name|char
modifier|*
name|pointer
decl_stmt|;
comment|/** The last filled position of the buffer. */
name|unsigned
name|char
modifier|*
name|last
decl_stmt|;
block|}
name|raw_buffer
struct|;
comment|/** The input encoding. */
name|yaml_encoding_t
name|encoding
decl_stmt|;
comment|/** The offset of the current position (in bytes). */
name|size_t
name|offset
decl_stmt|;
comment|/** The mark of the current position. */
name|yaml_mark_t
name|mark
decl_stmt|;
comment|/**      * @}      */
comment|/**      * @name Scanner stuff      * @{      */
comment|/** Have we started to scan the input stream? */
name|int
name|stream_start_produced
decl_stmt|;
comment|/** Have we reached the end of the input stream? */
name|int
name|stream_end_produced
decl_stmt|;
comment|/** The number of unclosed '[' and '{' indicators. */
name|int
name|flow_level
decl_stmt|;
comment|/** The tokens queue. */
struct|struct
block|{
comment|/** The beginning of the tokens queue. */
name|yaml_token_t
modifier|*
name|start
decl_stmt|;
comment|/** The end of the tokens queue. */
name|yaml_token_t
modifier|*
name|end
decl_stmt|;
comment|/** The head of the tokens queue. */
name|yaml_token_t
modifier|*
name|head
decl_stmt|;
comment|/** The tail of the tokens queue. */
name|yaml_token_t
modifier|*
name|tail
decl_stmt|;
block|}
name|tokens
struct|;
comment|/** The number of tokens fetched from the queue. */
name|size_t
name|tokens_parsed
decl_stmt|;
comment|/* Does the tokens queue contain a token ready for dequeueing. */
name|int
name|token_available
decl_stmt|;
comment|/** The indentation levels stack. */
struct|struct
block|{
comment|/** The beginning of the stack. */
name|int
modifier|*
name|start
decl_stmt|;
comment|/** The end of the stack. */
name|int
modifier|*
name|end
decl_stmt|;
comment|/** The top of the stack. */
name|int
modifier|*
name|top
decl_stmt|;
block|}
name|indents
struct|;
comment|/** The current indentation level. */
name|int
name|indent
decl_stmt|;
comment|/** May a simple key occur at the current position? */
name|int
name|simple_key_allowed
decl_stmt|;
comment|/** The stack of simple keys. */
struct|struct
block|{
comment|/** The beginning of the stack. */
name|yaml_simple_key_t
modifier|*
name|start
decl_stmt|;
comment|/** The end of the stack. */
name|yaml_simple_key_t
modifier|*
name|end
decl_stmt|;
comment|/** The top of the stack. */
name|yaml_simple_key_t
modifier|*
name|top
decl_stmt|;
block|}
name|simple_keys
struct|;
comment|/**      * @}      */
comment|/**      * @name Parser stuff      * @{      */
comment|/** The parser states stack. */
struct|struct
block|{
comment|/** The beginning of the stack. */
name|yaml_parser_state_t
modifier|*
name|start
decl_stmt|;
comment|/** The end of the stack. */
name|yaml_parser_state_t
modifier|*
name|end
decl_stmt|;
comment|/** The top of the stack. */
name|yaml_parser_state_t
modifier|*
name|top
decl_stmt|;
block|}
name|states
struct|;
comment|/** The current parser state. */
name|yaml_parser_state_t
name|state
decl_stmt|;
comment|/** The stack of marks. */
struct|struct
block|{
comment|/** The beginning of the stack. */
name|yaml_mark_t
modifier|*
name|start
decl_stmt|;
comment|/** The end of the stack. */
name|yaml_mark_t
modifier|*
name|end
decl_stmt|;
comment|/** The top of the stack. */
name|yaml_mark_t
modifier|*
name|top
decl_stmt|;
block|}
name|marks
struct|;
comment|/** The list of TAG directives. */
struct|struct
block|{
comment|/** The beginning of the list. */
name|yaml_tag_directive_t
modifier|*
name|start
decl_stmt|;
comment|/** The end of the list. */
name|yaml_tag_directive_t
modifier|*
name|end
decl_stmt|;
comment|/** The top of the list. */
name|yaml_tag_directive_t
modifier|*
name|top
decl_stmt|;
block|}
name|tag_directives
struct|;
comment|/**      * @}      */
comment|/**      * @name Dumper stuff      * @{      */
comment|/** The alias data. */
struct|struct
block|{
comment|/** The beginning of the list. */
name|yaml_alias_data_t
modifier|*
name|start
decl_stmt|;
comment|/** The end of the list. */
name|yaml_alias_data_t
modifier|*
name|end
decl_stmt|;
comment|/** The top of the list. */
name|yaml_alias_data_t
modifier|*
name|top
decl_stmt|;
block|}
name|aliases
struct|;
comment|/** The currently parsed document. */
name|yaml_document_t
modifier|*
name|document
decl_stmt|;
comment|/**      * @}      */
block|}
name|yaml_parser_t
typedef|;
comment|/**  * Initialize a parser.  *  * This function creates a new parser object.  An application is responsible  * for destroying the object using the yaml_parser_delete() function.  *  * @param[out]      parser  An empty parser object.  *  * @returns @c 1 if the function succeeded, @c 0 on error.  */
name|YAML_DECLARE
argument_list|(
argument|int
argument_list|)
name|yaml_parser_initialize
argument_list|(
name|yaml_parser_t
operator|*
name|parser
argument_list|)
expr_stmt|;
comment|/**  * Destroy a parser.  *  * @param[in,out]   parser  A parser object.  */
name|YAML_DECLARE
argument_list|(
argument|void
argument_list|)
name|yaml_parser_delete
argument_list|(
name|yaml_parser_t
operator|*
name|parser
argument_list|)
expr_stmt|;
comment|/**  * Set a string input.  *  * Note that the @a input pointer must be valid while the @a parser object  * exists.  The application is responsible for destroing @a input after  * destroying the @a parser.  *  * @param[in,out]   parser  A parser object.  * @param[in]       input   A source data.  * @param[in]       size    The length of the source data in bytes.  */
name|YAML_DECLARE
argument_list|(
argument|void
argument_list|)
name|yaml_parser_set_input_string
argument_list|(
argument|yaml_parser_t *parser
argument_list|,
argument|const unsigned char *input
argument_list|,
argument|size_t size
argument_list|)
empty_stmt|;
comment|/**  * Set a file input.  *  * @a file should be a file object open for reading.  The application is  * responsible for closing the @a file.  *  * @param[in,out]   parser  A parser object.  * @param[in]       file    An open file.  */
name|YAML_DECLARE
argument_list|(
argument|void
argument_list|)
name|yaml_parser_set_input_file
argument_list|(
name|yaml_parser_t
operator|*
name|parser
argument_list|,
name|FILE
operator|*
name|file
argument_list|)
expr_stmt|;
comment|/**  * Set a generic input handler.  *  * @param[in,out]   parser  A parser object.  * @param[in]       handler A read handler.  * @param[in]       data    Any application data for passing to the read  *                          handler.  */
name|YAML_DECLARE
argument_list|(
argument|void
argument_list|)
name|yaml_parser_set_input
argument_list|(
name|yaml_parser_t
operator|*
name|parser
argument_list|,
name|yaml_read_handler_t
operator|*
name|handler
argument_list|,
name|void
operator|*
name|data
argument_list|)
expr_stmt|;
comment|/**  * Set the source encoding.  *  * @param[in,out]   parser      A parser object.  * @param[in]       encoding    The source encoding.  */
name|YAML_DECLARE
argument_list|(
argument|void
argument_list|)
name|yaml_parser_set_encoding
argument_list|(
argument|yaml_parser_t *parser
argument_list|,
argument|yaml_encoding_t encoding
argument_list|)
empty_stmt|;
comment|/**  * Scan the input stream and produce the next token.  *  * Call the function subsequently to produce a sequence of tokens corresponding  * to the input stream.  The initial token has the type  * @c YAML_STREAM_START_TOKEN while the ending token has the type  * @c YAML_STREAM_END_TOKEN.  *  * An application is responsible for freeing any buffers associated with the  * produced token object using the @c yaml_token_delete function.  *  * An application must not alternate the calls of yaml_parser_scan() with the  * calls of yaml_parser_parse() or yaml_parser_load(). Doing this will break  * the parser.  *  * @param[in,out]   parser      A parser object.  * @param[out]      token       An empty token object.  *  * @returns @c 1 if the function succeeded, @c 0 on error.  */
name|YAML_DECLARE
argument_list|(
argument|int
argument_list|)
name|yaml_parser_scan
argument_list|(
name|yaml_parser_t
operator|*
name|parser
argument_list|,
name|yaml_token_t
operator|*
name|token
argument_list|)
expr_stmt|;
comment|/**  * Parse the input stream and produce the next parsing event.  *  * Call the function subsequently to produce a sequence of events corresponding  * to the input stream.  The initial event has the type  * @c YAML_STREAM_START_EVENT while the ending event has the type  * @c YAML_STREAM_END_EVENT.  *  * An application is responsible for freeing any buffers associated with the  * produced event object using the yaml_event_delete() function.  *  * An application must not alternate the calls of yaml_parser_parse() with the  * calls of yaml_parser_scan() or yaml_parser_load(). Doing this will break the  * parser.  *  * @param[in,out]   parser      A parser object.  * @param[out]      event       An empty event object.  *  * @returns @c 1 if the function succeeded, @c 0 on error.  */
name|YAML_DECLARE
argument_list|(
argument|int
argument_list|)
name|yaml_parser_parse
argument_list|(
name|yaml_parser_t
operator|*
name|parser
argument_list|,
name|yaml_event_t
operator|*
name|event
argument_list|)
expr_stmt|;
comment|/**  * Parse the input stream and produce the next YAML document.  *  * Call this function subsequently to produce a sequence of documents  * constituting the input stream.  *  * If the produced document has no root node, it means that the document  * end has been reached.  *  * An application is responsible for freeing any data associated with the  * produced document object using the yaml_document_delete() function.  *  * An application must not alternate the calls of yaml_parser_load() with the  * calls of yaml_parser_scan() or yaml_parser_parse(). Doing this will break  * the parser.  *  * @param[in,out]   parser      A parser object.  * @param[out]      document    An empty document object.  *  * @return @c 1 if the function succeeded, @c 0 on error.  */
name|YAML_DECLARE
argument_list|(
argument|int
argument_list|)
name|yaml_parser_load
argument_list|(
name|yaml_parser_t
operator|*
name|parser
argument_list|,
name|yaml_document_t
operator|*
name|document
argument_list|)
expr_stmt|;
comment|/** @} */
comment|/**  * @defgroup emitter Emitter Definitions  * @{  */
comment|/**  * The prototype of a write handler.  *  * The write handler is called when the emitter needs to flush the accumulated  * characters to the output.  The handler should write @a size bytes of the  * @a buffer to the output.  *  * @param[in,out]   data        A pointer to an application data specified by  *                              yaml_emitter_set_output().  * @param[in]       buffer      The buffer with bytes to be written.  * @param[in]       size        The size of the buffer.  *  * @returns On success, the handler should return @c 1.  If the handler failed,  * the returned value should be @c 0.  */
typedef|typedef
name|int
name|yaml_write_handler_t
parameter_list|(
name|void
modifier|*
name|data
parameter_list|,
name|unsigned
name|char
modifier|*
name|buffer
parameter_list|,
name|size_t
name|size
parameter_list|)
function_decl|;
comment|/** The emitter states. */
typedef|typedef
enum|enum
name|yaml_emitter_state_e
block|{
comment|/** Expect STREAM-START. */
name|YAML_EMIT_STREAM_START_STATE
block|,
comment|/** Expect the first DOCUMENT-START or STREAM-END. */
name|YAML_EMIT_FIRST_DOCUMENT_START_STATE
block|,
comment|/** Expect DOCUMENT-START or STREAM-END. */
name|YAML_EMIT_DOCUMENT_START_STATE
block|,
comment|/** Expect the content of a document. */
name|YAML_EMIT_DOCUMENT_CONTENT_STATE
block|,
comment|/** Expect DOCUMENT-END. */
name|YAML_EMIT_DOCUMENT_END_STATE
block|,
comment|/** Expect the first item of a flow sequence. */
name|YAML_EMIT_FLOW_SEQUENCE_FIRST_ITEM_STATE
block|,
comment|/** Expect an item of a flow sequence. */
name|YAML_EMIT_FLOW_SEQUENCE_ITEM_STATE
block|,
comment|/** Expect the first key of a flow mapping. */
name|YAML_EMIT_FLOW_MAPPING_FIRST_KEY_STATE
block|,
comment|/** Expect a key of a flow mapping. */
name|YAML_EMIT_FLOW_MAPPING_KEY_STATE
block|,
comment|/** Expect a value for a simple key of a flow mapping. */
name|YAML_EMIT_FLOW_MAPPING_SIMPLE_VALUE_STATE
block|,
comment|/** Expect a value of a flow mapping. */
name|YAML_EMIT_FLOW_MAPPING_VALUE_STATE
block|,
comment|/** Expect the first item of a block sequence. */
name|YAML_EMIT_BLOCK_SEQUENCE_FIRST_ITEM_STATE
block|,
comment|/** Expect an item of a block sequence. */
name|YAML_EMIT_BLOCK_SEQUENCE_ITEM_STATE
block|,
comment|/** Expect the first key of a block mapping. */
name|YAML_EMIT_BLOCK_MAPPING_FIRST_KEY_STATE
block|,
comment|/** Expect the key of a block mapping. */
name|YAML_EMIT_BLOCK_MAPPING_KEY_STATE
block|,
comment|/** Expect a value for a simple key of a block mapping. */
name|YAML_EMIT_BLOCK_MAPPING_SIMPLE_VALUE_STATE
block|,
comment|/** Expect a value of a block mapping. */
name|YAML_EMIT_BLOCK_MAPPING_VALUE_STATE
block|,
comment|/** Expect nothing. */
name|YAML_EMIT_END_STATE
block|}
name|yaml_emitter_state_t
typedef|;
comment|/**  * The emitter structure.  *  * All members are internal.  Manage the structure using the @c yaml_emitter_  * family of functions.  */
typedef|typedef
struct|struct
name|yaml_emitter_s
block|{
comment|/**      * @name Error handling      * @{      */
comment|/** Error type. */
name|yaml_error_type_t
name|error
decl_stmt|;
comment|/** Error description. */
specifier|const
name|char
modifier|*
name|problem
decl_stmt|;
comment|/**      * @}      */
comment|/**      * @name Writer stuff      * @{      */
comment|/** Write handler. */
name|yaml_write_handler_t
modifier|*
name|write_handler
decl_stmt|;
comment|/** A pointer for passing to the white handler. */
name|void
modifier|*
name|write_handler_data
decl_stmt|;
comment|/** Standard (string or file) output data. */
union|union
block|{
comment|/** String output data. */
struct|struct
block|{
comment|/** The buffer pointer. */
name|unsigned
name|char
modifier|*
name|buffer
decl_stmt|;
comment|/** The buffer size. */
name|size_t
name|size
decl_stmt|;
comment|/** The number of written bytes. */
name|size_t
modifier|*
name|size_written
decl_stmt|;
block|}
name|string
struct|;
comment|/** File output data. */
name|FILE
modifier|*
name|file
decl_stmt|;
block|}
name|output
union|;
comment|/** The working buffer. */
struct|struct
block|{
comment|/** The beginning of the buffer. */
name|yaml_char_t
modifier|*
name|start
decl_stmt|;
comment|/** The end of the buffer. */
name|yaml_char_t
modifier|*
name|end
decl_stmt|;
comment|/** The current position of the buffer. */
name|yaml_char_t
modifier|*
name|pointer
decl_stmt|;
comment|/** The last filled position of the buffer. */
name|yaml_char_t
modifier|*
name|last
decl_stmt|;
block|}
name|buffer
struct|;
comment|/** The raw buffer. */
struct|struct
block|{
comment|/** The beginning of the buffer. */
name|unsigned
name|char
modifier|*
name|start
decl_stmt|;
comment|/** The end of the buffer. */
name|unsigned
name|char
modifier|*
name|end
decl_stmt|;
comment|/** The current position of the buffer. */
name|unsigned
name|char
modifier|*
name|pointer
decl_stmt|;
comment|/** The last filled position of the buffer. */
name|unsigned
name|char
modifier|*
name|last
decl_stmt|;
block|}
name|raw_buffer
struct|;
comment|/** The stream encoding. */
name|yaml_encoding_t
name|encoding
decl_stmt|;
comment|/**      * @}      */
comment|/**      * @name Emitter stuff      * @{      */
comment|/** If the output is in the canonical style? */
name|int
name|canonical
decl_stmt|;
comment|/** The number of indentation spaces. */
name|int
name|best_indent
decl_stmt|;
comment|/** The preferred width of the output lines. */
name|int
name|best_width
decl_stmt|;
comment|/** Allow unescaped non-ASCII characters? */
name|int
name|unicode
decl_stmt|;
comment|/** The preferred line break. */
name|yaml_break_t
name|line_break
decl_stmt|;
comment|/** The stack of states. */
struct|struct
block|{
comment|/** The beginning of the stack. */
name|yaml_emitter_state_t
modifier|*
name|start
decl_stmt|;
comment|/** The end of the stack. */
name|yaml_emitter_state_t
modifier|*
name|end
decl_stmt|;
comment|/** The top of the stack. */
name|yaml_emitter_state_t
modifier|*
name|top
decl_stmt|;
block|}
name|states
struct|;
comment|/** The current emitter state. */
name|yaml_emitter_state_t
name|state
decl_stmt|;
comment|/** The event queue. */
struct|struct
block|{
comment|/** The beginning of the event queue. */
name|yaml_event_t
modifier|*
name|start
decl_stmt|;
comment|/** The end of the event queue. */
name|yaml_event_t
modifier|*
name|end
decl_stmt|;
comment|/** The head of the event queue. */
name|yaml_event_t
modifier|*
name|head
decl_stmt|;
comment|/** The tail of the event queue. */
name|yaml_event_t
modifier|*
name|tail
decl_stmt|;
block|}
name|events
struct|;
comment|/** The stack of indentation levels. */
struct|struct
block|{
comment|/** The beginning of the stack. */
name|int
modifier|*
name|start
decl_stmt|;
comment|/** The end of the stack. */
name|int
modifier|*
name|end
decl_stmt|;
comment|/** The top of the stack. */
name|int
modifier|*
name|top
decl_stmt|;
block|}
name|indents
struct|;
comment|/** The list of tag directives. */
struct|struct
block|{
comment|/** The beginning of the list. */
name|yaml_tag_directive_t
modifier|*
name|start
decl_stmt|;
comment|/** The end of the list. */
name|yaml_tag_directive_t
modifier|*
name|end
decl_stmt|;
comment|/** The top of the list. */
name|yaml_tag_directive_t
modifier|*
name|top
decl_stmt|;
block|}
name|tag_directives
struct|;
comment|/** The current indentation level. */
name|int
name|indent
decl_stmt|;
comment|/** The current flow level. */
name|int
name|flow_level
decl_stmt|;
comment|/** Is it the document root context? */
name|int
name|root_context
decl_stmt|;
comment|/** Is it a sequence context? */
name|int
name|sequence_context
decl_stmt|;
comment|/** Is it a mapping context? */
name|int
name|mapping_context
decl_stmt|;
comment|/** Is it a simple mapping key context? */
name|int
name|simple_key_context
decl_stmt|;
comment|/** The current line. */
name|int
name|line
decl_stmt|;
comment|/** The current column. */
name|int
name|column
decl_stmt|;
comment|/** If the last character was a whitespace? */
name|int
name|whitespace
decl_stmt|;
comment|/** If the last character was an indentation character (' ', '-', '?', ':')? */
name|int
name|indention
decl_stmt|;
comment|/** If an explicit document end is required? */
name|int
name|open_ended
decl_stmt|;
comment|/** Anchor analysis. */
struct|struct
block|{
comment|/** The anchor value. */
name|yaml_char_t
modifier|*
name|anchor
decl_stmt|;
comment|/** The anchor length. */
name|size_t
name|anchor_length
decl_stmt|;
comment|/** Is it an alias? */
name|int
name|alias
decl_stmt|;
block|}
name|anchor_data
struct|;
comment|/** Tag analysis. */
struct|struct
block|{
comment|/** The tag handle. */
name|yaml_char_t
modifier|*
name|handle
decl_stmt|;
comment|/** The tag handle length. */
name|size_t
name|handle_length
decl_stmt|;
comment|/** The tag suffix. */
name|yaml_char_t
modifier|*
name|suffix
decl_stmt|;
comment|/** The tag suffix length. */
name|size_t
name|suffix_length
decl_stmt|;
block|}
name|tag_data
struct|;
comment|/** Scalar analysis. */
struct|struct
block|{
comment|/** The scalar value. */
name|yaml_char_t
modifier|*
name|value
decl_stmt|;
comment|/** The scalar length. */
name|size_t
name|length
decl_stmt|;
comment|/** Does the scalar contain line breaks? */
name|int
name|multiline
decl_stmt|;
comment|/** Can the scalar be expessed in the flow plain style? */
name|int
name|flow_plain_allowed
decl_stmt|;
comment|/** Can the scalar be expressed in the block plain style? */
name|int
name|block_plain_allowed
decl_stmt|;
comment|/** Can the scalar be expressed in the single quoted style? */
name|int
name|single_quoted_allowed
decl_stmt|;
comment|/** Can the scalar be expressed in the literal or folded styles? */
name|int
name|block_allowed
decl_stmt|;
comment|/** The output style. */
name|yaml_scalar_style_t
name|style
decl_stmt|;
block|}
name|scalar_data
struct|;
comment|/**      * @}      */
comment|/**      * @name Dumper stuff      * @{      */
comment|/** If the stream was already opened? */
name|int
name|opened
decl_stmt|;
comment|/** If the stream was already closed? */
name|int
name|closed
decl_stmt|;
comment|/** The information associated with the document nodes. */
struct|struct
block|{
comment|/** The number of references. */
name|int
name|references
decl_stmt|;
comment|/** The anchor id. */
name|int
name|anchor
decl_stmt|;
comment|/** If the node has been emitted? */
name|int
name|serialized
decl_stmt|;
block|}
modifier|*
name|anchors
struct|;
comment|/** The last assigned anchor id. */
name|int
name|last_anchor_id
decl_stmt|;
comment|/** The currently emitted document. */
name|yaml_document_t
modifier|*
name|document
decl_stmt|;
comment|/**      * @}      */
block|}
name|yaml_emitter_t
typedef|;
comment|/**  * Initialize an emitter.  *  * This function creates a new emitter object.  An application is responsible  * for destroying the object using the yaml_emitter_delete() function.  *  * @param[out]      emitter     An empty parser object.  *  * @returns @c 1 if the function succeeded, @c 0 on error.  */
name|YAML_DECLARE
argument_list|(
argument|int
argument_list|)
name|yaml_emitter_initialize
argument_list|(
name|yaml_emitter_t
operator|*
name|emitter
argument_list|)
expr_stmt|;
comment|/**  * Destroy an emitter.  *  * @param[in,out]   emitter     An emitter object.  */
name|YAML_DECLARE
argument_list|(
argument|void
argument_list|)
name|yaml_emitter_delete
argument_list|(
name|yaml_emitter_t
operator|*
name|emitter
argument_list|)
expr_stmt|;
comment|/**  * Set a string output.  *  * The emitter will write the output characters to the @a output buffer of the  * size @a size.  The emitter will set @a size_written to the number of written  * bytes.  If the buffer is smaller than required, the emitter produces the  * YAML_WRITE_ERROR error.  *  * @param[in,out]   emitter         An emitter object.  * @param[in]       output          An output buffer.  * @param[in]       size            The buffer size.  * @param[in]       size_written    The pointer to save the number of written  *                                  bytes.  */
name|YAML_DECLARE
argument_list|(
argument|void
argument_list|)
name|yaml_emitter_set_output_string
argument_list|(
argument|yaml_emitter_t *emitter
argument_list|,
argument|unsigned char *output
argument_list|,
argument|size_t size
argument_list|,
argument|size_t *size_written
argument_list|)
empty_stmt|;
comment|/**  * Set a file output.  *  * @a file should be a file object open for writing.  The application is  * responsible for closing the @a file.  *  * @param[in,out]   emitter     An emitter object.  * @param[in]       file        An open file.  */
name|YAML_DECLARE
argument_list|(
argument|void
argument_list|)
name|yaml_emitter_set_output_file
argument_list|(
name|yaml_emitter_t
operator|*
name|emitter
argument_list|,
name|FILE
operator|*
name|file
argument_list|)
expr_stmt|;
comment|/**  * Set a generic output handler.  *  * @param[in,out]   emitter     An emitter object.  * @param[in]       handler     A write handler.  * @param[in]       data        Any application data for passing to the write  *                              handler.  */
name|YAML_DECLARE
argument_list|(
argument|void
argument_list|)
name|yaml_emitter_set_output
argument_list|(
name|yaml_emitter_t
operator|*
name|emitter
argument_list|,
name|yaml_write_handler_t
operator|*
name|handler
argument_list|,
name|void
operator|*
name|data
argument_list|)
expr_stmt|;
comment|/**  * Set the output encoding.  *  * @param[in,out]   emitter     An emitter object.  * @param[in]       encoding    The output encoding.  */
name|YAML_DECLARE
argument_list|(
argument|void
argument_list|)
name|yaml_emitter_set_encoding
argument_list|(
argument|yaml_emitter_t *emitter
argument_list|,
argument|yaml_encoding_t encoding
argument_list|)
empty_stmt|;
comment|/**  * Set if the output should be in the "canonical" format as in the YAML  * specification.  *  * @param[in,out]   emitter     An emitter object.  * @param[in]       canonical   If the output is canonical.  */
name|YAML_DECLARE
argument_list|(
argument|void
argument_list|)
name|yaml_emitter_set_canonical
argument_list|(
argument|yaml_emitter_t *emitter
argument_list|,
argument|int canonical
argument_list|)
empty_stmt|;
comment|/**  * Set the intendation increment.  *  * @param[in,out]   emitter     An emitter object.  * @param[in]       indent      The indentation increment (1< .< 10).  */
name|YAML_DECLARE
argument_list|(
argument|void
argument_list|)
name|yaml_emitter_set_indent
argument_list|(
argument|yaml_emitter_t *emitter
argument_list|,
argument|int indent
argument_list|)
empty_stmt|;
comment|/**  * Set the preferred line width. @c -1 means unlimited.  *  * @param[in,out]   emitter     An emitter object.  * @param[in]       width       The preferred line width.  */
name|YAML_DECLARE
argument_list|(
argument|void
argument_list|)
name|yaml_emitter_set_width
argument_list|(
argument|yaml_emitter_t *emitter
argument_list|,
argument|int width
argument_list|)
empty_stmt|;
comment|/**  * Set if unescaped non-ASCII characters are allowed.  *  * @param[in,out]   emitter     An emitter object.  * @param[in]       unicode     If unescaped Unicode characters are allowed.  */
name|YAML_DECLARE
argument_list|(
argument|void
argument_list|)
name|yaml_emitter_set_unicode
argument_list|(
argument|yaml_emitter_t *emitter
argument_list|,
argument|int unicode
argument_list|)
empty_stmt|;
comment|/**  * Set the preferred line break.  *  * @param[in,out]   emitter     An emitter object.  * @param[in]       line_break  The preferred line break.  */
name|YAML_DECLARE
argument_list|(
argument|void
argument_list|)
name|yaml_emitter_set_break
argument_list|(
argument|yaml_emitter_t *emitter
argument_list|,
argument|yaml_break_t line_break
argument_list|)
empty_stmt|;
comment|/**  * Emit an event.  *  * The event object may be generated using the yaml_parser_parse() function.  * The emitter takes the responsibility for the event object and destroys its  * content after it is emitted. The event object is destroyed even if the  * function fails.  *  * @param[in,out]   emitter     An emitter object.  * @param[in,out]   event       An event object.  *  * @returns @c 1 if the function succeeded, @c 0 on error.  */
name|YAML_DECLARE
argument_list|(
argument|int
argument_list|)
name|yaml_emitter_emit
argument_list|(
name|yaml_emitter_t
operator|*
name|emitter
argument_list|,
name|yaml_event_t
operator|*
name|event
argument_list|)
expr_stmt|;
comment|/**  * Start a YAML stream.  *  * This function should be used before yaml_emitter_dump() is called.  *  * @param[in,out]   emitter     An emitter object.  *  * @returns @c 1 if the function succeeded, @c 0 on error.  */
name|YAML_DECLARE
argument_list|(
argument|int
argument_list|)
name|yaml_emitter_open
argument_list|(
name|yaml_emitter_t
operator|*
name|emitter
argument_list|)
expr_stmt|;
comment|/**  * Finish a YAML stream.  *  * This function should be used after yaml_emitter_dump() is called.  *  * @param[in,out]   emitter     An emitter object.  *  * @returns @c 1 if the function succeeded, @c 0 on error.  */
name|YAML_DECLARE
argument_list|(
argument|int
argument_list|)
name|yaml_emitter_close
argument_list|(
name|yaml_emitter_t
operator|*
name|emitter
argument_list|)
expr_stmt|;
comment|/**  * Emit a YAML document.  *  * The documen object may be generated using the yaml_parser_load() function  * or the yaml_document_initialize() function.  The emitter takes the  * responsibility for the document object and destoys its content after  * it is emitted. The document object is destroyedeven if the function fails.  *  * @param[in,out]   emitter     An emitter object.  * @param[in,out]   document    A document object.  *  * @returns @c 1 if the function succeeded, @c 0 on error.  */
name|YAML_DECLARE
argument_list|(
argument|int
argument_list|)
name|yaml_emitter_dump
argument_list|(
name|yaml_emitter_t
operator|*
name|emitter
argument_list|,
name|yaml_document_t
operator|*
name|document
argument_list|)
expr_stmt|;
comment|/**  * Flush the accumulated characters to the output.  *  * @param[in,out]   emitter     An emitter object.  *  * @returns @c 1 if the function succeeded, @c 0 on error.  */
name|YAML_DECLARE
argument_list|(
argument|int
argument_list|)
name|yaml_emitter_flush
argument_list|(
name|yaml_emitter_t
operator|*
name|emitter
argument_list|)
expr_stmt|;
comment|/** @} */
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
comment|/* #ifndef YAML_H */
end_comment

end_unit

