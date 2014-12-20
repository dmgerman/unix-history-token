begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_ifndef
ifndef|#
directive|ifndef
name|__JSMN_H_
end_ifndef

begin_define
define|#
directive|define
name|__JSMN_H_
end_define

begin_comment
comment|/**  * JSON type identifier. Basic types are:  * 	o Object  * 	o Array  * 	o String  * 	o Other primitive: number, boolean (true/false) or null  */
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|JSMN_PRIMITIVE
init|=
literal|0
block|,
name|JSMN_OBJECT
init|=
literal|1
block|,
name|JSMN_ARRAY
init|=
literal|2
block|,
name|JSMN_STRING
init|=
literal|3
block|}
name|jsmntype_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
enum|enum
block|{
comment|/* Not enough tokens were provided */
name|JSMN_ERROR_NOMEM
init|=
operator|-
literal|1
block|,
comment|/* Invalid character inside JSON string */
name|JSMN_ERROR_INVAL
init|=
operator|-
literal|2
block|,
comment|/* The string is not a full JSON packet, more bytes expected */
name|JSMN_ERROR_PART
init|=
operator|-
literal|3
block|,
comment|/* Everything was fine */
name|JSMN_SUCCESS
init|=
literal|0
block|}
name|jsmnerr_t
typedef|;
end_typedef

begin_comment
comment|/**  * JSON token description.  * @param		type	type (object, array, string etc.)  * @param		start	start position in JSON data string  * @param		end		end position in JSON data string  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|jsmntype_t
name|type
decl_stmt|;
name|int
name|start
decl_stmt|;
name|int
name|end
decl_stmt|;
name|int
name|size
decl_stmt|;
ifdef|#
directive|ifdef
name|JSMN_PARENT_LINKS
name|int
name|parent
decl_stmt|;
endif|#
directive|endif
block|}
name|jsmntok_t
typedef|;
end_typedef

begin_comment
comment|/**  * JSON parser. Contains an array of token blocks available. Also stores  * the string being parsed now and current position in that string  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|unsigned
name|int
name|pos
decl_stmt|;
comment|/* offset in the JSON string */
name|int
name|toknext
decl_stmt|;
comment|/* next token to allocate */
name|int
name|toksuper
decl_stmt|;
comment|/* superior token node, e.g parent object or array */
block|}
name|jsmn_parser
typedef|;
end_typedef

begin_comment
comment|/**  * Create JSON parser over an array of tokens  */
end_comment

begin_function_decl
name|void
name|jsmn_init
parameter_list|(
name|jsmn_parser
modifier|*
name|parser
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Run JSON parser. It parses a JSON data string into and array of tokens, each describing  * a single JSON object.  */
end_comment

begin_function_decl
name|jsmnerr_t
name|jsmn_parse
parameter_list|(
name|jsmn_parser
modifier|*
name|parser
parameter_list|,
specifier|const
name|char
modifier|*
name|js
parameter_list|,
name|jsmntok_t
modifier|*
name|tokens
parameter_list|,
name|unsigned
name|int
name|num_tokens
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __JSMN_H_ */
end_comment

end_unit

