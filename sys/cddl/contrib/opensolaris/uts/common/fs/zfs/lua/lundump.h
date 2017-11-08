begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* ** $Id: lundump.h,v 1.39.1.1 2013/04/12 18:48:47 roberto Exp $ ** load precompiled Lua chunks ** See Copyright Notice in lua.h */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|lundump_h
end_ifndef

begin_define
define|#
directive|define
name|lundump_h
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

begin_comment
comment|/* load one chunk; from lundump.c */
end_comment

begin_function_decl
name|LUAI_FUNC
name|Closure
modifier|*
name|luaU_undump
parameter_list|(
name|lua_State
modifier|*
name|L
parameter_list|,
name|ZIO
modifier|*
name|Z
parameter_list|,
name|Mbuffer
modifier|*
name|buff
parameter_list|,
specifier|const
name|char
modifier|*
name|name
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* make header; from lundump.c */
end_comment

begin_function_decl
name|LUAI_FUNC
name|void
name|luaU_header
parameter_list|(
name|lu_byte
modifier|*
name|h
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* dump one chunk; from ldump.c */
end_comment

begin_function_decl
name|LUAI_FUNC
name|int
name|luaU_dump
parameter_list|(
name|lua_State
modifier|*
name|L
parameter_list|,
specifier|const
name|Proto
modifier|*
name|f
parameter_list|,
name|lua_Writer
name|w
parameter_list|,
name|void
modifier|*
name|data
parameter_list|,
name|int
name|strip
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* data to catch conversion errors */
end_comment

begin_define
define|#
directive|define
name|LUAC_TAIL
value|"\x19\x93\r\n\x1a\n"
end_define

begin_comment
comment|/* size in bytes of header of binary files */
end_comment

begin_define
define|#
directive|define
name|LUAC_HEADERSIZE
value|(sizeof(LUA_SIGNATURE)-sizeof(char)+2+6+sizeof(LUAC_TAIL)-sizeof(char))
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

