begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* ** $Id: ltm.h,v 2.11.1.1 2013/04/12 18:48:47 roberto Exp $ ** Tag methods ** See Copyright Notice in lua.h */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|ltm_h
end_ifndef

begin_define
define|#
directive|define
name|ltm_h
end_define

begin_include
include|#
directive|include
file|"lobject.h"
end_include

begin_comment
comment|/* * WARNING: if you change the order of this enumeration, * grep "ORDER TM" */
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|TM_INDEX
block|,
name|TM_NEWINDEX
block|,
name|TM_GC
block|,
name|TM_MODE
block|,
name|TM_LEN
block|,
name|TM_EQ
block|,
comment|/* last tag method with `fast' access */
name|TM_ADD
block|,
name|TM_SUB
block|,
name|TM_MUL
block|,
name|TM_DIV
block|,
name|TM_MOD
block|,
name|TM_POW
block|,
name|TM_UNM
block|,
name|TM_LT
block|,
name|TM_LE
block|,
name|TM_CONCAT
block|,
name|TM_CALL
block|,
name|TM_N
comment|/* number of elements in the enum */
block|}
name|TMS
typedef|;
end_typedef

begin_define
define|#
directive|define
name|gfasttm
parameter_list|(
name|g
parameter_list|,
name|et
parameter_list|,
name|e
parameter_list|)
value|((et) == NULL ? NULL : \   ((et)->flags& (1u<<(e))) ? NULL : luaT_gettm(et, e, (g)->tmname[e]))
end_define

begin_define
define|#
directive|define
name|fasttm
parameter_list|(
name|l
parameter_list|,
name|et
parameter_list|,
name|e
parameter_list|)
value|gfasttm(G(l), et, e)
end_define

begin_define
define|#
directive|define
name|ttypename
parameter_list|(
name|x
parameter_list|)
value|luaT_typenames_[(x) + 1]
end_define

begin_define
define|#
directive|define
name|objtypename
parameter_list|(
name|x
parameter_list|)
value|ttypename(ttypenv(x))
end_define

begin_decl_stmt
name|LUAI_DDEC
specifier|const
name|char
modifier|*
specifier|const
name|luaT_typenames_
index|[
name|LUA_TOTALTAGS
index|]
decl_stmt|;
end_decl_stmt

begin_function_decl
name|LUAI_FUNC
specifier|const
name|TValue
modifier|*
name|luaT_gettm
parameter_list|(
name|Table
modifier|*
name|events
parameter_list|,
name|TMS
name|event
parameter_list|,
name|TString
modifier|*
name|ename
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|LUAI_FUNC
specifier|const
name|TValue
modifier|*
name|luaT_gettmbyobj
parameter_list|(
name|lua_State
modifier|*
name|L
parameter_list|,
specifier|const
name|TValue
modifier|*
name|o
parameter_list|,
name|TMS
name|event
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|LUAI_FUNC
name|void
name|luaT_init
parameter_list|(
name|lua_State
modifier|*
name|L
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

end_unit

