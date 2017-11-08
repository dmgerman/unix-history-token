begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* ** $Id: lparser.h,v 1.70.1.1 2013/04/12 18:48:47 roberto Exp $ ** Lua Parser ** See Copyright Notice in lua.h */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|lparser_h
end_ifndef

begin_define
define|#
directive|define
name|lparser_h
end_define

begin_include
include|#
directive|include
file|"llimits.h"
end_include

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
comment|/* ** Expression descriptor */
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|VVOID
block|,
comment|/* no value */
name|VNIL
block|,
name|VTRUE
block|,
name|VFALSE
block|,
name|VK
block|,
comment|/* info = index of constant in `k' */
name|VKNUM
block|,
comment|/* nval = numerical value */
name|VNONRELOC
block|,
comment|/* info = result register */
name|VLOCAL
block|,
comment|/* info = local register */
name|VUPVAL
block|,
comment|/* info = index of upvalue in 'upvalues' */
name|VINDEXED
block|,
comment|/* t = table register/upvalue; idx = index R/K */
name|VJMP
block|,
comment|/* info = instruction pc */
name|VRELOCABLE
block|,
comment|/* info = instruction pc */
name|VCALL
block|,
comment|/* info = instruction pc */
name|VVARARG
comment|/* info = instruction pc */
block|}
name|expkind
typedef|;
end_typedef

begin_define
define|#
directive|define
name|vkisvar
parameter_list|(
name|k
parameter_list|)
value|(VLOCAL<= (k)&& (k)<= VINDEXED)
end_define

begin_define
define|#
directive|define
name|vkisinreg
parameter_list|(
name|k
parameter_list|)
value|((k) == VNONRELOC || (k) == VLOCAL)
end_define

begin_typedef
typedef|typedef
struct|struct
name|expdesc
block|{
name|expkind
name|k
decl_stmt|;
union|union
block|{
struct|struct
block|{
comment|/* for indexed variables (VINDEXED) */
name|short
name|idx
decl_stmt|;
comment|/* index (R/K) */
name|lu_byte
name|t
decl_stmt|;
comment|/* table (register or upvalue) */
name|lu_byte
name|vt
decl_stmt|;
comment|/* whether 't' is register (VLOCAL) or upvalue (VUPVAL) */
block|}
name|ind
struct|;
name|int
name|info
decl_stmt|;
comment|/* for generic use */
name|lua_Number
name|nval
decl_stmt|;
comment|/* for VKNUM */
block|}
name|u
union|;
name|int
name|t
decl_stmt|;
comment|/* patch list of `exit when true' */
name|int
name|f
decl_stmt|;
comment|/* patch list of `exit when false' */
block|}
name|expdesc
typedef|;
end_typedef

begin_comment
comment|/* description of active local variable */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|Vardesc
block|{
name|short
name|idx
decl_stmt|;
comment|/* variable index in stack */
block|}
name|Vardesc
typedef|;
end_typedef

begin_comment
comment|/* description of pending goto statements and label statements */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|Labeldesc
block|{
name|TString
modifier|*
name|name
decl_stmt|;
comment|/* label identifier */
name|int
name|pc
decl_stmt|;
comment|/* position in code */
name|int
name|line
decl_stmt|;
comment|/* line where it appeared */
name|lu_byte
name|nactvar
decl_stmt|;
comment|/* local level where it appears in current block */
block|}
name|Labeldesc
typedef|;
end_typedef

begin_comment
comment|/* list of labels or gotos */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|Labellist
block|{
name|Labeldesc
modifier|*
name|arr
decl_stmt|;
comment|/* array */
name|int
name|n
decl_stmt|;
comment|/* number of entries in use */
name|int
name|size
decl_stmt|;
comment|/* array size */
block|}
name|Labellist
typedef|;
end_typedef

begin_comment
comment|/* dynamic structures used by the parser */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|Dyndata
block|{
struct|struct
block|{
comment|/* list of active local variables */
name|Vardesc
modifier|*
name|arr
decl_stmt|;
name|int
name|n
decl_stmt|;
name|int
name|size
decl_stmt|;
block|}
name|actvar
struct|;
name|Labellist
name|gt
decl_stmt|;
comment|/* list of pending gotos */
name|Labellist
name|label
decl_stmt|;
comment|/* list of active labels */
block|}
name|Dyndata
typedef|;
end_typedef

begin_comment
comment|/* control of blocks */
end_comment

begin_struct_decl
struct_decl|struct
name|BlockCnt
struct_decl|;
end_struct_decl

begin_comment
comment|/* defined in lparser.c */
end_comment

begin_comment
comment|/* state needed to generate code for a given function */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|FuncState
block|{
name|Proto
modifier|*
name|f
decl_stmt|;
comment|/* current function header */
name|Table
modifier|*
name|h
decl_stmt|;
comment|/* table to find (and reuse) elements in `k' */
name|struct
name|FuncState
modifier|*
name|prev
decl_stmt|;
comment|/* enclosing function */
name|struct
name|LexState
modifier|*
name|ls
decl_stmt|;
comment|/* lexical state */
name|struct
name|BlockCnt
modifier|*
name|bl
decl_stmt|;
comment|/* chain of current blocks */
name|int
name|pc
decl_stmt|;
comment|/* next position to code (equivalent to `ncode') */
name|int
name|lasttarget
decl_stmt|;
comment|/* 'label' of last 'jump label' */
name|int
name|jpc
decl_stmt|;
comment|/* list of pending jumps to `pc' */
name|int
name|nk
decl_stmt|;
comment|/* number of elements in `k' */
name|int
name|np
decl_stmt|;
comment|/* number of elements in `p' */
name|int
name|firstlocal
decl_stmt|;
comment|/* index of first local var (in Dyndata array) */
name|short
name|nlocvars
decl_stmt|;
comment|/* number of elements in 'f->locvars' */
name|lu_byte
name|nactvar
decl_stmt|;
comment|/* number of active local variables */
name|lu_byte
name|nups
decl_stmt|;
comment|/* number of upvalues */
name|lu_byte
name|freereg
decl_stmt|;
comment|/* first free register */
block|}
name|FuncState
typedef|;
end_typedef

begin_function_decl
name|LUAI_FUNC
name|Closure
modifier|*
name|luaY_parser
parameter_list|(
name|lua_State
modifier|*
name|L
parameter_list|,
name|ZIO
modifier|*
name|z
parameter_list|,
name|Mbuffer
modifier|*
name|buff
parameter_list|,
name|Dyndata
modifier|*
name|dyd
parameter_list|,
specifier|const
name|char
modifier|*
name|name
parameter_list|,
name|int
name|firstchar
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

end_unit

