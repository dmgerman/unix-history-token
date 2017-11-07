begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* ** $Id: llex.h,v 1.72.1.1 2013/04/12 18:48:47 roberto Exp $ ** Lexical Analyzer ** See Copyright Notice in lua.h */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|llex_h
end_ifndef

begin_define
define|#
directive|define
name|llex_h
end_define

begin_include
include|#
directive|include
file|"lobject.h"
end_include

begin_include
include|#
directive|include
file|"lzio.h"
end_include

begin_define
define|#
directive|define
name|FIRST_RESERVED
value|257
end_define

begin_comment
comment|/* * WARNING: if you change the order of this enumeration, * grep "ORDER RESERVED" */
end_comment

begin_enum
enum|enum
name|RESERVED
block|{
comment|/* terminal symbols denoted by reserved words */
name|TK_AND
init|=
name|FIRST_RESERVED
block|,
name|TK_BREAK
block|,
name|TK_DO
block|,
name|TK_ELSE
block|,
name|TK_ELSEIF
block|,
name|TK_END
block|,
name|TK_FALSE
block|,
name|TK_FOR
block|,
name|TK_FUNCTION
block|,
name|TK_GOTO
block|,
name|TK_IF
block|,
name|TK_IN
block|,
name|TK_LOCAL
block|,
name|TK_NIL
block|,
name|TK_NOT
block|,
name|TK_OR
block|,
name|TK_REPEAT
block|,
name|TK_RETURN
block|,
name|TK_THEN
block|,
name|TK_TRUE
block|,
name|TK_UNTIL
block|,
name|TK_WHILE
block|,
comment|/* other terminal symbols */
name|TK_CONCAT
block|,
name|TK_DOTS
block|,
name|TK_EQ
block|,
name|TK_GE
block|,
name|TK_LE
block|,
name|TK_NE
block|,
name|TK_DBCOLON
block|,
name|TK_EOS
block|,
name|TK_NUMBER
block|,
name|TK_NAME
block|,
name|TK_STRING
block|}
enum|;
end_enum

begin_comment
comment|/* number of reserved words */
end_comment

begin_define
define|#
directive|define
name|NUM_RESERVED
value|(cast(int, TK_WHILE-FIRST_RESERVED+1))
end_define

begin_typedef
typedef|typedef
union|union
block|{
name|lua_Number
name|r
decl_stmt|;
name|TString
modifier|*
name|ts
decl_stmt|;
block|}
name|SemInfo
typedef|;
end_typedef

begin_comment
comment|/* semantics information */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|Token
block|{
name|int
name|token
decl_stmt|;
name|SemInfo
name|seminfo
decl_stmt|;
block|}
name|Token
typedef|;
end_typedef

begin_comment
comment|/* state of the lexer plus state of the parser when shared by all    functions */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|LexState
block|{
name|int
name|current
decl_stmt|;
comment|/* current character (charint) */
name|int
name|linenumber
decl_stmt|;
comment|/* input line counter */
name|int
name|lastline
decl_stmt|;
comment|/* line of last token `consumed' */
name|Token
name|t
decl_stmt|;
comment|/* current token */
name|Token
name|lookahead
decl_stmt|;
comment|/* look ahead token */
name|struct
name|FuncState
modifier|*
name|fs
decl_stmt|;
comment|/* current function (parser) */
name|struct
name|lua_State
modifier|*
name|L
decl_stmt|;
name|ZIO
modifier|*
name|z
decl_stmt|;
comment|/* input stream */
name|Mbuffer
modifier|*
name|buff
decl_stmt|;
comment|/* buffer for tokens */
name|struct
name|Dyndata
modifier|*
name|dyd
decl_stmt|;
comment|/* dynamic structures used by the parser */
name|TString
modifier|*
name|source
decl_stmt|;
comment|/* current source name */
name|TString
modifier|*
name|envn
decl_stmt|;
comment|/* environment variable name */
name|char
name|decpoint
decl_stmt|;
comment|/* locale decimal point */
block|}
name|LexState
typedef|;
end_typedef

begin_function_decl
name|LUAI_FUNC
name|void
name|luaX_init
parameter_list|(
name|lua_State
modifier|*
name|L
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|LUAI_FUNC
name|void
name|luaX_setinput
parameter_list|(
name|lua_State
modifier|*
name|L
parameter_list|,
name|LexState
modifier|*
name|ls
parameter_list|,
name|ZIO
modifier|*
name|z
parameter_list|,
name|TString
modifier|*
name|source
parameter_list|,
name|int
name|firstchar
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|LUAI_FUNC
name|TString
modifier|*
name|luaX_newstring
parameter_list|(
name|LexState
modifier|*
name|ls
parameter_list|,
specifier|const
name|char
modifier|*
name|str
parameter_list|,
name|size_t
name|l
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|LUAI_FUNC
name|void
name|luaX_next
parameter_list|(
name|LexState
modifier|*
name|ls
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|LUAI_FUNC
name|int
name|luaX_lookahead
parameter_list|(
name|LexState
modifier|*
name|ls
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|LUAI_FUNC
name|l_noret
name|luaX_syntaxerror
parameter_list|(
name|LexState
modifier|*
name|ls
parameter_list|,
specifier|const
name|char
modifier|*
name|s
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|LUAI_FUNC
specifier|const
name|char
modifier|*
name|luaX_token2str
parameter_list|(
name|LexState
modifier|*
name|ls
parameter_list|,
name|int
name|token
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

end_unit

