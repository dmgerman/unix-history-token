begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* ** $Id: lmem.h,v 1.40.1.1 2013/04/12 18:48:47 roberto Exp $ ** Interface to Memory Manager ** See Copyright Notice in lua.h */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|lmem_h
end_ifndef

begin_define
define|#
directive|define
name|lmem_h
end_define

begin_include
include|#
directive|include
file|<sys/zfs_context.h>
end_include

begin_include
include|#
directive|include
file|"llimits.h"
end_include

begin_include
include|#
directive|include
file|"lua.h"
end_include

begin_comment
comment|/* ** This macro avoids the runtime division MAX_SIZET/(e), as 'e' is ** always constant. ** The macro is somewhat complex to avoid warnings: ** +1 avoids warnings of "comparison has constant result"; ** cast to 'void' avoids warnings of "value unused". */
end_comment

begin_define
define|#
directive|define
name|luaM_reallocv
parameter_list|(
name|L
parameter_list|,
name|b
parameter_list|,
name|on
parameter_list|,
name|n
parameter_list|,
name|e
parameter_list|)
define|\
value|(cast(void, \      (cast(size_t, (n)+1)> MAX_SIZET/(e)) ? (luaM_toobig(L), 0) : 0), \    luaM_realloc_(L, (b), (on)*(e), (n)*(e)))
end_define

begin_define
define|#
directive|define
name|luaM_freemem
parameter_list|(
name|L
parameter_list|,
name|b
parameter_list|,
name|s
parameter_list|)
value|luaM_realloc_(L, (b), (s), 0)
end_define

begin_define
define|#
directive|define
name|luaM_free
parameter_list|(
name|L
parameter_list|,
name|b
parameter_list|)
value|luaM_realloc_(L, (b), sizeof(*(b)), 0)
end_define

begin_define
define|#
directive|define
name|luaM_freearray
parameter_list|(
name|L
parameter_list|,
name|b
parameter_list|,
name|n
parameter_list|)
value|luaM_reallocv(L, (b), n, 0, sizeof((b)[0]))
end_define

begin_define
define|#
directive|define
name|luaM_malloc
parameter_list|(
name|L
parameter_list|,
name|s
parameter_list|)
value|luaM_realloc_(L, NULL, 0, (s))
end_define

begin_define
define|#
directive|define
name|luaM_new
parameter_list|(
name|L
parameter_list|,
name|t
parameter_list|)
value|cast(t *, luaM_malloc(L, sizeof(t)))
end_define

begin_define
define|#
directive|define
name|luaM_newvector
parameter_list|(
name|L
parameter_list|,
name|n
parameter_list|,
name|t
parameter_list|)
define|\
value|cast(t *, luaM_reallocv(L, NULL, 0, n, sizeof(t)))
end_define

begin_define
define|#
directive|define
name|luaM_newobject
parameter_list|(
name|L
parameter_list|,
name|tag
parameter_list|,
name|s
parameter_list|)
value|luaM_realloc_(L, NULL, tag, (s))
end_define

begin_define
define|#
directive|define
name|luaM_growvector
parameter_list|(
name|L
parameter_list|,
name|v
parameter_list|,
name|nelems
parameter_list|,
name|size
parameter_list|,
name|t
parameter_list|,
name|limit
parameter_list|,
name|e
parameter_list|)
define|\
value|if ((nelems)+1> (size)) \             ((v)=cast(t *, luaM_growaux_(L,v,&(size),sizeof(t),limit,e)))
end_define

begin_define
define|#
directive|define
name|luaM_reallocvector
parameter_list|(
name|L
parameter_list|,
name|v
parameter_list|,
name|oldn
parameter_list|,
name|n
parameter_list|,
name|t
parameter_list|)
define|\
value|((v)=cast(t *, luaM_reallocv(L, v, oldn, n, sizeof(t))))
end_define

begin_function_decl
name|LUAI_FUNC
name|l_noret
name|luaM_toobig
parameter_list|(
name|lua_State
modifier|*
name|L
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* not to be called directly */
end_comment

begin_function_decl
name|LUAI_FUNC
name|void
modifier|*
name|luaM_realloc_
parameter_list|(
name|lua_State
modifier|*
name|L
parameter_list|,
name|void
modifier|*
name|block
parameter_list|,
name|size_t
name|oldsize
parameter_list|,
name|size_t
name|size
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|LUAI_FUNC
name|void
modifier|*
name|luaM_growaux_
parameter_list|(
name|lua_State
modifier|*
name|L
parameter_list|,
name|void
modifier|*
name|block
parameter_list|,
name|int
modifier|*
name|size
parameter_list|,
name|size_t
name|size_elem
parameter_list|,
name|int
name|limit
parameter_list|,
specifier|const
name|char
modifier|*
name|what
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

end_unit

