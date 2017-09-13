begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* ** $Id: lzio.h,v 1.26.1.1 2013/04/12 18:48:47 roberto Exp $ ** Buffered streams ** See Copyright Notice in lua.h */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|lzio_h
end_ifndef

begin_define
define|#
directive|define
name|lzio_h
end_define

begin_include
include|#
directive|include
file|"lua.h"
end_include

begin_include
include|#
directive|include
file|"lmem.h"
end_include

begin_define
define|#
directive|define
name|EOZ
value|(-1)
end_define

begin_comment
comment|/* end of stream */
end_comment

begin_typedef
typedef|typedef
name|struct
name|Zio
name|ZIO
typedef|;
end_typedef

begin_define
define|#
directive|define
name|zgetc
parameter_list|(
name|z
parameter_list|)
value|(((z)->n--)>0 ?  cast_uchar(*(z)->p++) : luaZ_fill(z))
end_define

begin_typedef
typedef|typedef
struct|struct
name|Mbuffer
block|{
name|char
modifier|*
name|buffer
decl_stmt|;
name|size_t
name|n
decl_stmt|;
name|size_t
name|buffsize
decl_stmt|;
block|}
name|Mbuffer
typedef|;
end_typedef

begin_define
define|#
directive|define
name|luaZ_initbuffer
parameter_list|(
name|L
parameter_list|,
name|buff
parameter_list|)
value|((buff)->buffer = NULL, (buff)->buffsize = 0)
end_define

begin_define
define|#
directive|define
name|luaZ_buffer
parameter_list|(
name|buff
parameter_list|)
value|((buff)->buffer)
end_define

begin_define
define|#
directive|define
name|luaZ_sizebuffer
parameter_list|(
name|buff
parameter_list|)
value|((buff)->buffsize)
end_define

begin_define
define|#
directive|define
name|luaZ_bufflen
parameter_list|(
name|buff
parameter_list|)
value|((buff)->n)
end_define

begin_define
define|#
directive|define
name|luaZ_resetbuffer
parameter_list|(
name|buff
parameter_list|)
value|((buff)->n = 0)
end_define

begin_define
define|#
directive|define
name|luaZ_resizebuffer
parameter_list|(
name|L
parameter_list|,
name|buff
parameter_list|,
name|size
parameter_list|)
define|\
value|(luaM_reallocvector(L, (buff)->buffer, (buff)->buffsize, size, char), \ 	(buff)->buffsize = size)
end_define

begin_define
define|#
directive|define
name|luaZ_freebuffer
parameter_list|(
name|L
parameter_list|,
name|buff
parameter_list|)
value|luaZ_resizebuffer(L, buff, 0)
end_define

begin_function_decl
name|LUAI_FUNC
name|char
modifier|*
name|luaZ_openspace
parameter_list|(
name|lua_State
modifier|*
name|L
parameter_list|,
name|Mbuffer
modifier|*
name|buff
parameter_list|,
name|size_t
name|n
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|LUAI_FUNC
name|void
name|luaZ_init
parameter_list|(
name|lua_State
modifier|*
name|L
parameter_list|,
name|ZIO
modifier|*
name|z
parameter_list|,
name|lua_Reader
name|reader
parameter_list|,
name|void
modifier|*
name|data
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|LUAI_FUNC
name|size_t
name|luaZ_read
parameter_list|(
name|ZIO
modifier|*
name|z
parameter_list|,
name|void
modifier|*
name|b
parameter_list|,
name|size_t
name|n
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* read next n bytes */
end_comment

begin_comment
comment|/* --------- Private Part ------------------ */
end_comment

begin_struct
struct|struct
name|Zio
block|{
name|size_t
name|n
decl_stmt|;
comment|/* bytes still unread */
specifier|const
name|char
modifier|*
name|p
decl_stmt|;
comment|/* current position in buffer */
name|lua_Reader
name|reader
decl_stmt|;
comment|/* reader function */
name|void
modifier|*
name|data
decl_stmt|;
comment|/* additional data */
name|lua_State
modifier|*
name|L
decl_stmt|;
comment|/* Lua state (for reader) */
block|}
struct|;
end_struct

begin_function_decl
name|LUAI_FUNC
name|int
name|luaZ_fill
parameter_list|(
name|ZIO
modifier|*
name|z
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

end_unit

