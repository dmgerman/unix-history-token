begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_if
if|#
directive|if
name|HAVE_CONFIG_H
end_if

begin_include
include|#
directive|include
file|<config.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<yaml.h>
end_include

begin_include
include|#
directive|include
file|<assert.h>
end_include

begin_include
include|#
directive|include
file|<limits.h>
end_include

begin_comment
comment|/*  * Memory management.  */
end_comment

begin_macro
name|YAML_DECLARE
argument_list|(
argument|void *
argument_list|)
end_macro

begin_macro
name|yaml_malloc
argument_list|(
argument|size_t size
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|YAML_DECLARE
argument_list|(
argument|void *
argument_list|)
end_macro

begin_macro
name|yaml_realloc
argument_list|(
argument|void *ptr
argument_list|,
argument|size_t size
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|YAML_DECLARE
argument_list|(
argument|void
argument_list|)
end_macro

begin_expr_stmt
name|yaml_free
argument_list|(
name|void
operator|*
name|ptr
argument_list|)
expr_stmt|;
end_expr_stmt

begin_macro
name|YAML_DECLARE
argument_list|(
argument|yaml_char_t *
argument_list|)
end_macro

begin_expr_stmt
name|yaml_strdup
argument_list|(
specifier|const
name|yaml_char_t
operator|*
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/*  * Reader: Ensure that the buffer contains at least `length` characters.  */
end_comment

begin_macro
name|YAML_DECLARE
argument_list|(
argument|int
argument_list|)
end_macro

begin_macro
name|yaml_parser_update_buffer
argument_list|(
argument|yaml_parser_t *parser
argument_list|,
argument|size_t length
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|/*  * Scanner: Ensure that the token stack contains at least one token ready.  */
end_comment

begin_macro
name|YAML_DECLARE
argument_list|(
argument|int
argument_list|)
end_macro

begin_expr_stmt
name|yaml_parser_fetch_more_tokens
argument_list|(
name|yaml_parser_t
operator|*
name|parser
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/*  * The size of the input raw buffer.  */
end_comment

begin_define
define|#
directive|define
name|INPUT_RAW_BUFFER_SIZE
value|16384
end_define

begin_comment
comment|/*  * The size of the input buffer.  *  * It should be possible to decode the whole raw buffer.  */
end_comment

begin_define
define|#
directive|define
name|INPUT_BUFFER_SIZE
value|(INPUT_RAW_BUFFER_SIZE*3)
end_define

begin_comment
comment|/*  * The size of the output buffer.  */
end_comment

begin_define
define|#
directive|define
name|OUTPUT_BUFFER_SIZE
value|16384
end_define

begin_comment
comment|/*  * The size of the output raw buffer.  *  * It should be possible to encode the whole output buffer.  */
end_comment

begin_define
define|#
directive|define
name|OUTPUT_RAW_BUFFER_SIZE
value|(OUTPUT_BUFFER_SIZE*2+2)
end_define

begin_comment
comment|/*  * The size of other stacks and queues.  */
end_comment

begin_define
define|#
directive|define
name|INITIAL_STACK_SIZE
value|16
end_define

begin_define
define|#
directive|define
name|INITIAL_QUEUE_SIZE
value|16
end_define

begin_define
define|#
directive|define
name|INITIAL_STRING_SIZE
value|16
end_define

begin_comment
comment|/*  * Buffer management.  */
end_comment

begin_define
define|#
directive|define
name|BUFFER_INIT
parameter_list|(
name|context
parameter_list|,
name|buffer
parameter_list|,
name|size
parameter_list|)
define|\
value|(((buffer).start = yaml_malloc(size)) ?                                     \         ((buffer).last = (buffer).pointer = (buffer).start,                     \          (buffer).end = (buffer).start+(size),                                  \          1) :                                                                   \         ((context)->error = YAML_MEMORY_ERROR,                                  \          0))
end_define

begin_define
define|#
directive|define
name|BUFFER_DEL
parameter_list|(
name|context
parameter_list|,
name|buffer
parameter_list|)
define|\
value|(yaml_free((buffer).start),                                                 \      (buffer).start = (buffer).pointer = (buffer).end = 0)
end_define

begin_comment
comment|/*  * String management.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|yaml_char_t
modifier|*
name|start
decl_stmt|;
name|yaml_char_t
modifier|*
name|end
decl_stmt|;
name|yaml_char_t
modifier|*
name|pointer
decl_stmt|;
block|}
name|yaml_string_t
typedef|;
end_typedef

begin_macro
name|YAML_DECLARE
argument_list|(
argument|int
argument_list|)
end_macro

begin_expr_stmt
name|yaml_string_extend
argument_list|(
name|yaml_char_t
operator|*
operator|*
name|start
argument_list|,
name|yaml_char_t
operator|*
operator|*
name|pointer
argument_list|,
name|yaml_char_t
operator|*
operator|*
name|end
argument_list|)
expr_stmt|;
end_expr_stmt

begin_macro
name|YAML_DECLARE
argument_list|(
argument|int
argument_list|)
end_macro

begin_expr_stmt
name|yaml_string_join
argument_list|(
name|yaml_char_t
operator|*
operator|*
name|a_start
argument_list|,
name|yaml_char_t
operator|*
operator|*
name|a_pointer
argument_list|,
name|yaml_char_t
operator|*
operator|*
name|a_end
argument_list|,
name|yaml_char_t
operator|*
operator|*
name|b_start
argument_list|,
name|yaml_char_t
operator|*
operator|*
name|b_pointer
argument_list|,
name|yaml_char_t
operator|*
operator|*
name|b_end
argument_list|)
expr_stmt|;
end_expr_stmt

begin_define
define|#
directive|define
name|NULL_STRING
value|{ NULL, NULL, NULL }
end_define

begin_define
define|#
directive|define
name|STRING
parameter_list|(
name|string
parameter_list|,
name|length
parameter_list|)
value|{ (string), (string)+(length), (string) }
end_define

begin_define
define|#
directive|define
name|STRING_ASSIGN
parameter_list|(
name|value
parameter_list|,
name|string
parameter_list|,
name|length
parameter_list|)
define|\
value|((value).start = (string),                                                  \      (value).end = (string)+(length),                                           \      (value).pointer = (string))
end_define

begin_define
define|#
directive|define
name|STRING_INIT
parameter_list|(
name|context
parameter_list|,
name|string
parameter_list|,
name|size
parameter_list|)
define|\
value|(((string).start = yaml_malloc(size)) ?                                     \         ((string).pointer = (string).start,                                     \          (string).end = (string).start+(size),                                  \          memset((string).start, 0, (size)),                                     \          1) :                                                                   \         ((context)->error = YAML_MEMORY_ERROR,                                  \          0))
end_define

begin_define
define|#
directive|define
name|STRING_DEL
parameter_list|(
name|context
parameter_list|,
name|string
parameter_list|)
define|\
value|(yaml_free((string).start),                                                 \      (string).start = (string).pointer = (string).end = 0)
end_define

begin_define
define|#
directive|define
name|STRING_EXTEND
parameter_list|(
name|context
parameter_list|,
name|string
parameter_list|)
define|\
value|(((string).pointer+5< (string).end)                                        \         || yaml_string_extend(&(string).start,                                  \&(string).pointer,&(string).end))
end_define

begin_define
define|#
directive|define
name|CLEAR
parameter_list|(
name|context
parameter_list|,
name|string
parameter_list|)
define|\
value|((string).pointer = (string).start,                                         \      memset((string).start, 0, (string).end-(string).start))
end_define

begin_define
define|#
directive|define
name|JOIN
parameter_list|(
name|context
parameter_list|,
name|string_a
parameter_list|,
name|string_b
parameter_list|)
define|\
value|((yaml_string_join(&(string_a).start,&(string_a).pointer,                  \&(string_a).end,&(string_b).start,                      \&(string_b).pointer,&(string_b).end)) ?                 \         ((string_b).pointer = (string_b).start,                                 \          1) :                                                                   \         ((context)->error = YAML_MEMORY_ERROR,                                  \          0))
end_define

begin_comment
comment|/*  * String check operations.  */
end_comment

begin_comment
comment|/*  * Check the octet at the specified position.  */
end_comment

begin_define
define|#
directive|define
name|CHECK_AT
parameter_list|(
name|string
parameter_list|,
name|octet
parameter_list|,
name|offset
parameter_list|)
define|\
value|((string).pointer[offset] == (yaml_char_t)(octet))
end_define

begin_comment
comment|/*  * Check the current octet in the buffer.  */
end_comment

begin_define
define|#
directive|define
name|CHECK
parameter_list|(
name|string
parameter_list|,
name|octet
parameter_list|)
value|CHECK_AT((string),(octet),0)
end_define

begin_comment
comment|/*  * Check if the character at the specified position is an alphabetical  * character, a digit, '_', or '-'.  */
end_comment

begin_define
define|#
directive|define
name|IS_ALPHA_AT
parameter_list|(
name|string
parameter_list|,
name|offset
parameter_list|)
define|\
value|(((string).pointer[offset]>= (yaml_char_t) '0'&&                         \        (string).pointer[offset]<= (yaml_char_t) '9') ||                        \       ((string).pointer[offset]>= (yaml_char_t) 'A'&&                         \        (string).pointer[offset]<= (yaml_char_t) 'Z') ||                        \       ((string).pointer[offset]>= (yaml_char_t) 'a'&&                         \        (string).pointer[offset]<= (yaml_char_t) 'z') ||                        \       (string).pointer[offset] == '_' ||                                        \       (string).pointer[offset] == '-')
end_define

begin_define
define|#
directive|define
name|IS_ALPHA
parameter_list|(
name|string
parameter_list|)
value|IS_ALPHA_AT((string),0)
end_define

begin_comment
comment|/*  * Check if the character at the specified position is a digit.  */
end_comment

begin_define
define|#
directive|define
name|IS_DIGIT_AT
parameter_list|(
name|string
parameter_list|,
name|offset
parameter_list|)
define|\
value|(((string).pointer[offset]>= (yaml_char_t) '0'&&                         \        (string).pointer[offset]<= (yaml_char_t) '9'))
end_define

begin_define
define|#
directive|define
name|IS_DIGIT
parameter_list|(
name|string
parameter_list|)
value|IS_DIGIT_AT((string),0)
end_define

begin_comment
comment|/*  * Get the value of a digit.  */
end_comment

begin_define
define|#
directive|define
name|AS_DIGIT_AT
parameter_list|(
name|string
parameter_list|,
name|offset
parameter_list|)
define|\
value|((string).pointer[offset] - (yaml_char_t) '0')
end_define

begin_define
define|#
directive|define
name|AS_DIGIT
parameter_list|(
name|string
parameter_list|)
value|AS_DIGIT_AT((string),0)
end_define

begin_comment
comment|/*  * Check if the character at the specified position is a hex-digit.  */
end_comment

begin_define
define|#
directive|define
name|IS_HEX_AT
parameter_list|(
name|string
parameter_list|,
name|offset
parameter_list|)
define|\
value|(((string).pointer[offset]>= (yaml_char_t) '0'&&                         \        (string).pointer[offset]<= (yaml_char_t) '9') ||                        \       ((string).pointer[offset]>= (yaml_char_t) 'A'&&                         \        (string).pointer[offset]<= (yaml_char_t) 'F') ||                        \       ((string).pointer[offset]>= (yaml_char_t) 'a'&&                         \        (string).pointer[offset]<= (yaml_char_t) 'f'))
end_define

begin_define
define|#
directive|define
name|IS_HEX
parameter_list|(
name|string
parameter_list|)
value|IS_HEX_AT((string),0)
end_define

begin_comment
comment|/*  * Get the value of a hex-digit.  */
end_comment

begin_define
define|#
directive|define
name|AS_HEX_AT
parameter_list|(
name|string
parameter_list|,
name|offset
parameter_list|)
define|\
value|(((string).pointer[offset]>= (yaml_char_t) 'A'&&                        \         (string).pointer[offset]<= (yaml_char_t) 'F') ?                        \        ((string).pointer[offset] - (yaml_char_t) 'A' + 10) :                    \        ((string).pointer[offset]>= (yaml_char_t) 'a'&&                        \         (string).pointer[offset]<= (yaml_char_t) 'f') ?                        \        ((string).pointer[offset] - (yaml_char_t) 'a' + 10) :                    \        ((string).pointer[offset] - (yaml_char_t) '0'))
end_define

begin_define
define|#
directive|define
name|AS_HEX
parameter_list|(
name|string
parameter_list|)
value|AS_HEX_AT((string),0)
end_define

begin_comment
comment|/*  * Check if the character is ASCII.  */
end_comment

begin_define
define|#
directive|define
name|IS_ASCII_AT
parameter_list|(
name|string
parameter_list|,
name|offset
parameter_list|)
define|\
value|((string).pointer[offset]<= (yaml_char_t) '\x7F')
end_define

begin_define
define|#
directive|define
name|IS_ASCII
parameter_list|(
name|string
parameter_list|)
value|IS_ASCII_AT((string),0)
end_define

begin_comment
comment|/*  * Check if the character can be printed unescaped.  */
end_comment

begin_define
define|#
directive|define
name|IS_PRINTABLE_AT
parameter_list|(
name|string
parameter_list|,
name|offset
parameter_list|)
define|\
value|(((string).pointer[offset] == 0x0A)
comment|/* . == #x0A */
value|\      || ((string).pointer[offset]>= 0x20
comment|/* #x20<= .<= #x7E */
value|\&& (string).pointer[offset]<= 0x7E)                                   \      || ((string).pointer[offset] == 0xC2
comment|/* #0xA0<= .<= #xD7FF */
value|\&& (string).pointer[offset+1]>= 0xA0)                                 \      || ((string).pointer[offset]> 0xC2                                        \&& (string).pointer[offset]< 0xED)                                    \      || ((string).pointer[offset] == 0xED                                       \&& (string).pointer[offset+1]< 0xA0)                                  \      || ((string).pointer[offset] == 0xEE)                                      \      || ((string).pointer[offset] == 0xEF
comment|/* #xE000<= .<= #xFFFD */
value|\&& !((string).pointer[offset+1] == 0xBB
comment|/*&& . != #xFEFF */
value|\&& (string).pointer[offset+2] == 0xBF)                             \&& !((string).pointer[offset+1] == 0xBF                                \&& ((string).pointer[offset+2] == 0xBE                             \                  || (string).pointer[offset+2] == 0xBF))))
end_define

begin_define
define|#
directive|define
name|IS_PRINTABLE
parameter_list|(
name|string
parameter_list|)
value|IS_PRINTABLE_AT((string),0)
end_define

begin_comment
comment|/*  * Check if the character at the specified position is NUL.  */
end_comment

begin_define
define|#
directive|define
name|IS_Z_AT
parameter_list|(
name|string
parameter_list|,
name|offset
parameter_list|)
value|CHECK_AT((string),'\0',(offset))
end_define

begin_define
define|#
directive|define
name|IS_Z
parameter_list|(
name|string
parameter_list|)
value|IS_Z_AT((string),0)
end_define

begin_comment
comment|/*  * Check if the character at the specified position is BOM.  */
end_comment

begin_define
define|#
directive|define
name|IS_BOM_AT
parameter_list|(
name|string
parameter_list|,
name|offset
parameter_list|)
define|\
value|(CHECK_AT((string),'\xEF',(offset))                                        \&& CHECK_AT((string),'\xBB',(offset)+1)                                   \&& CHECK_AT((string),'\xBF',(offset)+2))
end_define

begin_comment
comment|/* BOM (#xFEFF) */
end_comment

begin_define
define|#
directive|define
name|IS_BOM
parameter_list|(
name|string
parameter_list|)
value|IS_BOM_AT(string,0)
end_define

begin_comment
comment|/*  * Check if the character at the specified position is space.  */
end_comment

begin_define
define|#
directive|define
name|IS_SPACE_AT
parameter_list|(
name|string
parameter_list|,
name|offset
parameter_list|)
value|CHECK_AT((string),' ',(offset))
end_define

begin_define
define|#
directive|define
name|IS_SPACE
parameter_list|(
name|string
parameter_list|)
value|IS_SPACE_AT((string),0)
end_define

begin_comment
comment|/*  * Check if the character at the specified position is tab.  */
end_comment

begin_define
define|#
directive|define
name|IS_TAB_AT
parameter_list|(
name|string
parameter_list|,
name|offset
parameter_list|)
value|CHECK_AT((string),'\t',(offset))
end_define

begin_define
define|#
directive|define
name|IS_TAB
parameter_list|(
name|string
parameter_list|)
value|IS_TAB_AT((string),0)
end_define

begin_comment
comment|/*  * Check if the character at the specified position is blank (space or tab).  */
end_comment

begin_define
define|#
directive|define
name|IS_BLANK_AT
parameter_list|(
name|string
parameter_list|,
name|offset
parameter_list|)
define|\
value|(IS_SPACE_AT((string),(offset)) || IS_TAB_AT((string),(offset)))
end_define

begin_define
define|#
directive|define
name|IS_BLANK
parameter_list|(
name|string
parameter_list|)
value|IS_BLANK_AT((string),0)
end_define

begin_comment
comment|/*  * Check if the character at the specified position is a line break.  */
end_comment

begin_define
define|#
directive|define
name|IS_BREAK_AT
parameter_list|(
name|string
parameter_list|,
name|offset
parameter_list|)
define|\
value|(CHECK_AT((string),'\r',(offset))
comment|/* CR (#xD)*/
value|\      || CHECK_AT((string),'\n',(offset))
comment|/* LF (#xA) */
value|\      || (CHECK_AT((string),'\xC2',(offset))                                     \&& CHECK_AT((string),'\x85',(offset)+1))
comment|/* NEL (#x85) */
value|\      || (CHECK_AT((string),'\xE2',(offset))                                     \&& CHECK_AT((string),'\x80',(offset)+1)                                \&& CHECK_AT((string),'\xA8',(offset)+2))
comment|/* LS (#x2028) */
value|\      || (CHECK_AT((string),'\xE2',(offset))                                     \&& CHECK_AT((string),'\x80',(offset)+1)                                \&& CHECK_AT((string),'\xA9',(offset)+2)))
end_define

begin_comment
comment|/* PS (#x2029) */
end_comment

begin_define
define|#
directive|define
name|IS_BREAK
parameter_list|(
name|string
parameter_list|)
value|IS_BREAK_AT((string),0)
end_define

begin_define
define|#
directive|define
name|IS_CRLF_AT
parameter_list|(
name|string
parameter_list|,
name|offset
parameter_list|)
define|\
value|(CHECK_AT((string),'\r',(offset))&& CHECK_AT((string),'\n',(offset)+1))
end_define

begin_define
define|#
directive|define
name|IS_CRLF
parameter_list|(
name|string
parameter_list|)
value|IS_CRLF_AT((string),0)
end_define

begin_comment
comment|/*  * Check if the character is a line break or NUL.  */
end_comment

begin_define
define|#
directive|define
name|IS_BREAKZ_AT
parameter_list|(
name|string
parameter_list|,
name|offset
parameter_list|)
define|\
value|(IS_BREAK_AT((string),(offset)) || IS_Z_AT((string),(offset)))
end_define

begin_define
define|#
directive|define
name|IS_BREAKZ
parameter_list|(
name|string
parameter_list|)
value|IS_BREAKZ_AT((string),0)
end_define

begin_comment
comment|/*  * Check if the character is a line break, space, or NUL.  */
end_comment

begin_define
define|#
directive|define
name|IS_SPACEZ_AT
parameter_list|(
name|string
parameter_list|,
name|offset
parameter_list|)
define|\
value|(IS_SPACE_AT((string),(offset)) || IS_BREAKZ_AT((string),(offset)))
end_define

begin_define
define|#
directive|define
name|IS_SPACEZ
parameter_list|(
name|string
parameter_list|)
value|IS_SPACEZ_AT((string),0)
end_define

begin_comment
comment|/*  * Check if the character is a line break, space, tab, or NUL.  */
end_comment

begin_define
define|#
directive|define
name|IS_BLANKZ_AT
parameter_list|(
name|string
parameter_list|,
name|offset
parameter_list|)
define|\
value|(IS_BLANK_AT((string),(offset)) || IS_BREAKZ_AT((string),(offset)))
end_define

begin_define
define|#
directive|define
name|IS_BLANKZ
parameter_list|(
name|string
parameter_list|)
value|IS_BLANKZ_AT((string),0)
end_define

begin_comment
comment|/*  * Determine the width of the character.  */
end_comment

begin_define
define|#
directive|define
name|WIDTH_AT
parameter_list|(
name|string
parameter_list|,
name|offset
parameter_list|)
define|\
value|(((string).pointer[offset]& 0x80) == 0x00 ? 1 :                           \       ((string).pointer[offset]& 0xE0) == 0xC0 ? 2 :                           \       ((string).pointer[offset]& 0xF0) == 0xE0 ? 3 :                           \       ((string).pointer[offset]& 0xF8) == 0xF0 ? 4 : 0)
end_define

begin_define
define|#
directive|define
name|WIDTH
parameter_list|(
name|string
parameter_list|)
value|WIDTH_AT((string),0)
end_define

begin_comment
comment|/*  * Move the string pointer to the next character.  */
end_comment

begin_define
define|#
directive|define
name|MOVE
parameter_list|(
name|string
parameter_list|)
value|((string).pointer += WIDTH((string)))
end_define

begin_comment
comment|/*  * Copy a character and move the pointers of both strings.  */
end_comment

begin_define
define|#
directive|define
name|COPY
parameter_list|(
name|string_a
parameter_list|,
name|string_b
parameter_list|)
define|\
value|((*(string_b).pointer& 0x80) == 0x00 ?                                     \      (*((string_a).pointer++) = *((string_b).pointer++)) :                      \      (*(string_b).pointer& 0xE0) == 0xC0 ?                                     \      (*((string_a).pointer++) = *((string_b).pointer++),                        \       *((string_a).pointer++) = *((string_b).pointer++)) :                      \      (*(string_b).pointer& 0xF0) == 0xE0 ?                                     \      (*((string_a).pointer++) = *((string_b).pointer++),                        \       *((string_a).pointer++) = *((string_b).pointer++),                        \       *((string_a).pointer++) = *((string_b).pointer++)) :                      \      (*(string_b).pointer& 0xF8) == 0xF0 ?                                     \      (*((string_a).pointer++) = *((string_b).pointer++),                        \       *((string_a).pointer++) = *((string_b).pointer++),                        \       *((string_a).pointer++) = *((string_b).pointer++),                        \       *((string_a).pointer++) = *((string_b).pointer++)) : 0)
end_define

begin_comment
comment|/*  * Stack and queue management.  */
end_comment

begin_macro
name|YAML_DECLARE
argument_list|(
argument|int
argument_list|)
end_macro

begin_expr_stmt
name|yaml_stack_extend
argument_list|(
name|void
operator|*
operator|*
name|start
argument_list|,
name|void
operator|*
operator|*
name|top
argument_list|,
name|void
operator|*
operator|*
name|end
argument_list|)
expr_stmt|;
end_expr_stmt

begin_macro
name|YAML_DECLARE
argument_list|(
argument|int
argument_list|)
end_macro

begin_expr_stmt
name|yaml_queue_extend
argument_list|(
name|void
operator|*
operator|*
name|start
argument_list|,
name|void
operator|*
operator|*
name|head
argument_list|,
name|void
operator|*
operator|*
name|tail
argument_list|,
name|void
operator|*
operator|*
name|end
argument_list|)
expr_stmt|;
end_expr_stmt

begin_define
define|#
directive|define
name|STACK_INIT
parameter_list|(
name|context
parameter_list|,
name|stack
parameter_list|,
name|size
parameter_list|)
define|\
value|(((stack).start = yaml_malloc((size)*sizeof(*(stack).start))) ?             \         ((stack).top = (stack).start,                                           \          (stack).end = (stack).start+(size),                                    \          1) :                                                                   \         ((context)->error = YAML_MEMORY_ERROR,                                  \          0))
end_define

begin_define
define|#
directive|define
name|STACK_DEL
parameter_list|(
name|context
parameter_list|,
name|stack
parameter_list|)
define|\
value|(yaml_free((stack).start),                                                  \      (stack).start = (stack).top = (stack).end = 0)
end_define

begin_define
define|#
directive|define
name|STACK_EMPTY
parameter_list|(
name|context
parameter_list|,
name|stack
parameter_list|)
define|\
value|((stack).start == (stack).top)
end_define

begin_define
define|#
directive|define
name|PUSH
parameter_list|(
name|context
parameter_list|,
name|stack
parameter_list|,
name|value
parameter_list|)
define|\
value|(((stack).top != (stack).end                                                \       || yaml_stack_extend((void **)&(stack).start,                             \               (void **)&(stack).top, (void **)&(stack).end)) ?                  \         (*((stack).top++) = value,                                              \          1) :                                                                   \         ((context)->error = YAML_MEMORY_ERROR,                                  \          0))
end_define

begin_define
define|#
directive|define
name|POP
parameter_list|(
name|context
parameter_list|,
name|stack
parameter_list|)
define|\
value|(*(--(stack).top))
end_define

begin_define
define|#
directive|define
name|QUEUE_INIT
parameter_list|(
name|context
parameter_list|,
name|queue
parameter_list|,
name|size
parameter_list|)
define|\
value|(((queue).start = yaml_malloc((size)*sizeof(*(queue).start))) ?             \         ((queue).head = (queue).tail = (queue).start,                           \          (queue).end = (queue).start+(size),                                    \          1) :                                                                   \         ((context)->error = YAML_MEMORY_ERROR,                                  \          0))
end_define

begin_define
define|#
directive|define
name|QUEUE_DEL
parameter_list|(
name|context
parameter_list|,
name|queue
parameter_list|)
define|\
value|(yaml_free((queue).start),                                                  \      (queue).start = (queue).head = (queue).tail = (queue).end = 0)
end_define

begin_define
define|#
directive|define
name|QUEUE_EMPTY
parameter_list|(
name|context
parameter_list|,
name|queue
parameter_list|)
define|\
value|((queue).head == (queue).tail)
end_define

begin_define
define|#
directive|define
name|ENQUEUE
parameter_list|(
name|context
parameter_list|,
name|queue
parameter_list|,
name|value
parameter_list|)
define|\
value|(((queue).tail != (queue).end                                               \       || yaml_queue_extend((void **)&(queue).start, (void **)&(queue).head,     \             (void **)&(queue).tail, (void **)&(queue).end)) ?                   \         (*((queue).tail++) = value,                                             \          1) :                                                                   \         ((context)->error = YAML_MEMORY_ERROR,                                  \          0))
end_define

begin_define
define|#
directive|define
name|DEQUEUE
parameter_list|(
name|context
parameter_list|,
name|queue
parameter_list|)
define|\
value|(*((queue).head++))
end_define

begin_define
define|#
directive|define
name|QUEUE_INSERT
parameter_list|(
name|context
parameter_list|,
name|queue
parameter_list|,
name|index
parameter_list|,
name|value
parameter_list|)
define|\
value|(((queue).tail != (queue).end                                               \       || yaml_queue_extend((void **)&(queue).start, (void **)&(queue).head,     \             (void **)&(queue).tail, (void **)&(queue).end)) ?                   \         (memmove((queue).head+(index)+1,(queue).head+(index),                   \             ((queue).tail-(queue).head-(index))*sizeof(*(queue).start)),        \          *((queue).head+(index)) = value,                                       \          (queue).tail++,                                                        \          1) :                                                                   \         ((context)->error = YAML_MEMORY_ERROR,                                  \          0))
end_define

begin_comment
comment|/*  * Token initializers.  */
end_comment

begin_define
define|#
directive|define
name|TOKEN_INIT
parameter_list|(
name|token
parameter_list|,
name|token_type
parameter_list|,
name|token_start_mark
parameter_list|,
name|token_end_mark
parameter_list|)
define|\
value|(memset(&(token), 0, sizeof(yaml_token_t)),                                 \      (token).type = (token_type),                                               \      (token).start_mark = (token_start_mark),                                   \      (token).end_mark = (token_end_mark))
end_define

begin_define
define|#
directive|define
name|STREAM_START_TOKEN_INIT
parameter_list|(
name|token
parameter_list|,
name|token_encoding
parameter_list|,
name|start_mark
parameter_list|,
name|end_mark
parameter_list|)
define|\
value|(TOKEN_INIT((token),YAML_STREAM_START_TOKEN,(start_mark),(end_mark)),       \      (token).data.stream_start.encoding = (token_encoding))
end_define

begin_define
define|#
directive|define
name|STREAM_END_TOKEN_INIT
parameter_list|(
name|token
parameter_list|,
name|start_mark
parameter_list|,
name|end_mark
parameter_list|)
define|\
value|(TOKEN_INIT((token),YAML_STREAM_END_TOKEN,(start_mark),(end_mark)))
end_define

begin_define
define|#
directive|define
name|ALIAS_TOKEN_INIT
parameter_list|(
name|token
parameter_list|,
name|token_value
parameter_list|,
name|start_mark
parameter_list|,
name|end_mark
parameter_list|)
define|\
value|(TOKEN_INIT((token),YAML_ALIAS_TOKEN,(start_mark),(end_mark)),              \      (token).data.alias.value = (token_value))
end_define

begin_define
define|#
directive|define
name|ANCHOR_TOKEN_INIT
parameter_list|(
name|token
parameter_list|,
name|token_value
parameter_list|,
name|start_mark
parameter_list|,
name|end_mark
parameter_list|)
define|\
value|(TOKEN_INIT((token),YAML_ANCHOR_TOKEN,(start_mark),(end_mark)),             \      (token).data.anchor.value = (token_value))
end_define

begin_define
define|#
directive|define
name|TAG_TOKEN_INIT
parameter_list|(
name|token
parameter_list|,
name|token_handle
parameter_list|,
name|token_suffix
parameter_list|,
name|start_mark
parameter_list|,
name|end_mark
parameter_list|)
define|\
value|(TOKEN_INIT((token),YAML_TAG_TOKEN,(start_mark),(end_mark)),                \      (token).data.tag.handle = (token_handle),                                  \      (token).data.tag.suffix = (token_suffix))
end_define

begin_define
define|#
directive|define
name|SCALAR_TOKEN_INIT
parameter_list|(
name|token
parameter_list|,
name|token_value
parameter_list|,
name|token_length
parameter_list|,
name|token_style
parameter_list|,
name|start_mark
parameter_list|,
name|end_mark
parameter_list|)
define|\
value|(TOKEN_INIT((token),YAML_SCALAR_TOKEN,(start_mark),(end_mark)),             \      (token).data.scalar.value = (token_value),                                 \      (token).data.scalar.length = (token_length),                               \      (token).data.scalar.style = (token_style))
end_define

begin_define
define|#
directive|define
name|VERSION_DIRECTIVE_TOKEN_INIT
parameter_list|(
name|token
parameter_list|,
name|token_major
parameter_list|,
name|token_minor
parameter_list|,
name|start_mark
parameter_list|,
name|end_mark
parameter_list|)
define|\
value|(TOKEN_INIT((token),YAML_VERSION_DIRECTIVE_TOKEN,(start_mark),(end_mark)),  \      (token).data.version_directive.major = (token_major),                      \      (token).data.version_directive.minor = (token_minor))
end_define

begin_define
define|#
directive|define
name|TAG_DIRECTIVE_TOKEN_INIT
parameter_list|(
name|token
parameter_list|,
name|token_handle
parameter_list|,
name|token_prefix
parameter_list|,
name|start_mark
parameter_list|,
name|end_mark
parameter_list|)
define|\
value|(TOKEN_INIT((token),YAML_TAG_DIRECTIVE_TOKEN,(start_mark),(end_mark)),      \      (token).data.tag_directive.handle = (token_handle),                        \      (token).data.tag_directive.prefix = (token_prefix))
end_define

begin_comment
comment|/*  * Event initializers.  */
end_comment

begin_define
define|#
directive|define
name|EVENT_INIT
parameter_list|(
name|event
parameter_list|,
name|event_type
parameter_list|,
name|event_start_mark
parameter_list|,
name|event_end_mark
parameter_list|)
define|\
value|(memset(&(event), 0, sizeof(yaml_event_t)),                                 \      (event).type = (event_type),                                               \      (event).start_mark = (event_start_mark),                                   \      (event).end_mark = (event_end_mark))
end_define

begin_define
define|#
directive|define
name|STREAM_START_EVENT_INIT
parameter_list|(
name|event
parameter_list|,
name|event_encoding
parameter_list|,
name|start_mark
parameter_list|,
name|end_mark
parameter_list|)
define|\
value|(EVENT_INIT((event),YAML_STREAM_START_EVENT,(start_mark),(end_mark)),       \      (event).data.stream_start.encoding = (event_encoding))
end_define

begin_define
define|#
directive|define
name|STREAM_END_EVENT_INIT
parameter_list|(
name|event
parameter_list|,
name|start_mark
parameter_list|,
name|end_mark
parameter_list|)
define|\
value|(EVENT_INIT((event),YAML_STREAM_END_EVENT,(start_mark),(end_mark)))
end_define

begin_define
define|#
directive|define
name|DOCUMENT_START_EVENT_INIT
parameter_list|(
name|event
parameter_list|,
name|event_version_directive
parameter_list|,                \
name|event_tag_directives_start
parameter_list|,
name|event_tag_directives_end
parameter_list|,
name|event_implicit
parameter_list|,
name|start_mark
parameter_list|,
name|end_mark
parameter_list|)
define|\
value|(EVENT_INIT((event),YAML_DOCUMENT_START_EVENT,(start_mark),(end_mark)),     \      (event).data.document_start.version_directive = (event_version_directive), \      (event).data.document_start.tag_directives.start = (event_tag_directives_start),   \      (event).data.document_start.tag_directives.end = (event_tag_directives_end),   \      (event).data.document_start.implicit = (event_implicit))
end_define

begin_define
define|#
directive|define
name|DOCUMENT_END_EVENT_INIT
parameter_list|(
name|event
parameter_list|,
name|event_implicit
parameter_list|,
name|start_mark
parameter_list|,
name|end_mark
parameter_list|)
define|\
value|(EVENT_INIT((event),YAML_DOCUMENT_END_EVENT,(start_mark),(end_mark)),       \      (event).data.document_end.implicit = (event_implicit))
end_define

begin_define
define|#
directive|define
name|ALIAS_EVENT_INIT
parameter_list|(
name|event
parameter_list|,
name|event_anchor
parameter_list|,
name|start_mark
parameter_list|,
name|end_mark
parameter_list|)
define|\
value|(EVENT_INIT((event),YAML_ALIAS_EVENT,(start_mark),(end_mark)),              \      (event).data.alias.anchor = (event_anchor))
end_define

begin_define
define|#
directive|define
name|SCALAR_EVENT_INIT
parameter_list|(
name|event
parameter_list|,
name|event_anchor
parameter_list|,
name|event_tag
parameter_list|,
name|event_value
parameter_list|,
name|event_length
parameter_list|,    \
name|event_plain_implicit
parameter_list|,
name|event_quoted_implicit
parameter_list|,
name|event_style
parameter_list|,
name|start_mark
parameter_list|,
name|end_mark
parameter_list|)
define|\
value|(EVENT_INIT((event),YAML_SCALAR_EVENT,(start_mark),(end_mark)),             \      (event).data.scalar.anchor = (event_anchor),                               \      (event).data.scalar.tag = (event_tag),                                     \      (event).data.scalar.value = (event_value),                                 \      (event).data.scalar.length = (event_length),                               \      (event).data.scalar.plain_implicit = (event_plain_implicit),               \      (event).data.scalar.quoted_implicit = (event_quoted_implicit),             \      (event).data.scalar.style = (event_style))
end_define

begin_define
define|#
directive|define
name|SEQUENCE_START_EVENT_INIT
parameter_list|(
name|event
parameter_list|,
name|event_anchor
parameter_list|,
name|event_tag
parameter_list|,                 \
name|event_implicit
parameter_list|,
name|event_style
parameter_list|,
name|start_mark
parameter_list|,
name|end_mark
parameter_list|)
define|\
value|(EVENT_INIT((event),YAML_SEQUENCE_START_EVENT,(start_mark),(end_mark)),     \      (event).data.sequence_start.anchor = (event_anchor),                       \      (event).data.sequence_start.tag = (event_tag),                             \      (event).data.sequence_start.implicit = (event_implicit),                   \      (event).data.sequence_start.style = (event_style))
end_define

begin_define
define|#
directive|define
name|SEQUENCE_END_EVENT_INIT
parameter_list|(
name|event
parameter_list|,
name|start_mark
parameter_list|,
name|end_mark
parameter_list|)
define|\
value|(EVENT_INIT((event),YAML_SEQUENCE_END_EVENT,(start_mark),(end_mark)))
end_define

begin_define
define|#
directive|define
name|MAPPING_START_EVENT_INIT
parameter_list|(
name|event
parameter_list|,
name|event_anchor
parameter_list|,
name|event_tag
parameter_list|,                  \
name|event_implicit
parameter_list|,
name|event_style
parameter_list|,
name|start_mark
parameter_list|,
name|end_mark
parameter_list|)
define|\
value|(EVENT_INIT((event),YAML_MAPPING_START_EVENT,(start_mark),(end_mark)),      \      (event).data.mapping_start.anchor = (event_anchor),                        \      (event).data.mapping_start.tag = (event_tag),                              \      (event).data.mapping_start.implicit = (event_implicit),                    \      (event).data.mapping_start.style = (event_style))
end_define

begin_define
define|#
directive|define
name|MAPPING_END_EVENT_INIT
parameter_list|(
name|event
parameter_list|,
name|start_mark
parameter_list|,
name|end_mark
parameter_list|)
define|\
value|(EVENT_INIT((event),YAML_MAPPING_END_EVENT,(start_mark),(end_mark)))
end_define

begin_comment
comment|/*  * Document initializer.  */
end_comment

begin_define
define|#
directive|define
name|DOCUMENT_INIT
parameter_list|(
name|document
parameter_list|,
name|document_nodes_start
parameter_list|,
name|document_nodes_end
parameter_list|,         \
name|document_version_directive
parameter_list|,
name|document_tag_directives_start
parameter_list|,               \
name|document_tag_directives_end
parameter_list|,
name|document_start_implicit
parameter_list|,                    \
name|document_end_implicit
parameter_list|,
name|document_start_mark
parameter_list|,
name|document_end_mark
parameter_list|)
define|\
value|(memset(&(document), 0, sizeof(yaml_document_t)),                           \      (document).nodes.start = (document_nodes_start),                           \      (document).nodes.end = (document_nodes_end),                               \      (document).nodes.top = (document_nodes_start),                             \      (document).version_directive = (document_version_directive),               \      (document).tag_directives.start = (document_tag_directives_start),         \      (document).tag_directives.end = (document_tag_directives_end),             \      (document).start_implicit = (document_start_implicit),                     \      (document).end_implicit = (document_end_implicit),                         \      (document).start_mark = (document_start_mark),                             \      (document).end_mark = (document_end_mark))
end_define

begin_comment
comment|/*  * Node initializers.  */
end_comment

begin_define
define|#
directive|define
name|NODE_INIT
parameter_list|(
name|node
parameter_list|,
name|node_type
parameter_list|,
name|node_tag
parameter_list|,
name|node_start_mark
parameter_list|,
name|node_end_mark
parameter_list|)
define|\
value|(memset(&(node), 0, sizeof(yaml_node_t)),                                   \      (node).type = (node_type),                                                 \      (node).tag = (node_tag),                                                   \      (node).start_mark = (node_start_mark),                                     \      (node).end_mark = (node_end_mark))
end_define

begin_define
define|#
directive|define
name|SCALAR_NODE_INIT
parameter_list|(
name|node
parameter_list|,
name|node_tag
parameter_list|,
name|node_value
parameter_list|,
name|node_length
parameter_list|,                  \
name|node_style
parameter_list|,
name|start_mark
parameter_list|,
name|end_mark
parameter_list|)
define|\
value|(NODE_INIT((node),YAML_SCALAR_NODE,(node_tag),(start_mark),(end_mark)),     \      (node).data.scalar.value = (node_value),                                   \      (node).data.scalar.length = (node_length),                                 \      (node).data.scalar.style = (node_style))
end_define

begin_define
define|#
directive|define
name|SEQUENCE_NODE_INIT
parameter_list|(
name|node
parameter_list|,
name|node_tag
parameter_list|,
name|node_items_start
parameter_list|,
name|node_items_end
parameter_list|,       \
name|node_style
parameter_list|,
name|start_mark
parameter_list|,
name|end_mark
parameter_list|)
define|\
value|(NODE_INIT((node),YAML_SEQUENCE_NODE,(node_tag),(start_mark),(end_mark)),   \      (node).data.sequence.items.start = (node_items_start),                     \      (node).data.sequence.items.end = (node_items_end),                         \      (node).data.sequence.items.top = (node_items_start),                       \      (node).data.sequence.style = (node_style))
end_define

begin_define
define|#
directive|define
name|MAPPING_NODE_INIT
parameter_list|(
name|node
parameter_list|,
name|node_tag
parameter_list|,
name|node_pairs_start
parameter_list|,
name|node_pairs_end
parameter_list|,        \
name|node_style
parameter_list|,
name|start_mark
parameter_list|,
name|end_mark
parameter_list|)
define|\
value|(NODE_INIT((node),YAML_MAPPING_NODE,(node_tag),(start_mark),(end_mark)),    \      (node).data.mapping.pairs.start = (node_pairs_start),                      \      (node).data.mapping.pairs.end = (node_pairs_end),                          \      (node).data.mapping.pairs.top = (node_pairs_start),                        \      (node).data.mapping.style = (node_style))
end_define

end_unit

