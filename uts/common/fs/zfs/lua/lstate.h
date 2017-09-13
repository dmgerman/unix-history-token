begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* ** $Id: lstate.h,v 2.82.1.1 2013/04/12 18:48:47 roberto Exp $ ** Global State ** See Copyright Notice in lua.h */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|lstate_h
end_ifndef

begin_define
define|#
directive|define
name|lstate_h
end_define

begin_include
include|#
directive|include
file|"lua.h"
end_include

begin_include
include|#
directive|include
file|"lobject.h"
end_include

begin_include
include|#
directive|include
file|"ltm.h"
end_include

begin_include
include|#
directive|include
file|"lzio.h"
end_include

begin_comment
comment|/*  ** Some notes about garbage-collected objects:  All objects in Lua must ** be kept somehow accessible until being freed. ** ** Lua keeps most objects linked in list g->allgc. The link uses field ** 'next' of the CommonHeader. ** ** Strings are kept in several lists headed by the array g->strt.hash. ** ** Open upvalues are not subject to independent garbage collection. They ** are collected together with their respective threads. Lua keeps a ** double-linked list with all open upvalues (g->uvhead) so that it can ** mark objects referred by them. (They are always gray, so they must ** be remarked in the atomic step. Usually their contents would be marked ** when traversing the respective threads, but the thread may already be ** dead, while the upvalue is still accessible through closures.) ** ** Objects with finalizers are kept in the list g->finobj. ** ** The list g->tobefnz links all objects being finalized.  */
end_comment

begin_struct_decl
struct_decl|struct
name|lua_longjmp
struct_decl|;
end_struct_decl

begin_comment
comment|/* defined in ldo.c */
end_comment

begin_comment
comment|/* extra stack space to handle TM calls and some other extras */
end_comment

begin_define
define|#
directive|define
name|EXTRA_STACK
value|5
end_define

begin_define
define|#
directive|define
name|BASIC_STACK_SIZE
value|(2*LUA_MINSTACK)
end_define

begin_comment
comment|/* kinds of Garbage Collection */
end_comment

begin_define
define|#
directive|define
name|KGC_NORMAL
value|0
end_define

begin_define
define|#
directive|define
name|KGC_EMERGENCY
value|1
end_define

begin_comment
comment|/* gc was forced by an allocation failure */
end_comment

begin_define
define|#
directive|define
name|KGC_GEN
value|2
end_define

begin_comment
comment|/* generational collection */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|stringtable
block|{
name|GCObject
modifier|*
modifier|*
name|hash
decl_stmt|;
name|lu_int32
name|nuse
decl_stmt|;
comment|/* number of elements */
name|int
name|size
decl_stmt|;
block|}
name|stringtable
typedef|;
end_typedef

begin_comment
comment|/* ** information about a call */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|CallInfo
block|{
name|StkId
name|func
decl_stmt|;
comment|/* function index in the stack */
name|StkId
name|top
decl_stmt|;
comment|/* top for this function */
name|struct
name|CallInfo
modifier|*
name|previous
decl_stmt|,
modifier|*
name|next
decl_stmt|;
comment|/* dynamic call link */
name|short
name|nresults
decl_stmt|;
comment|/* expected number of results from this function */
name|lu_byte
name|callstatus
decl_stmt|;
name|ptrdiff_t
name|extra
decl_stmt|;
union|union
block|{
struct|struct
block|{
comment|/* only for Lua functions */
name|StkId
name|base
decl_stmt|;
comment|/* base for this function */
specifier|const
name|Instruction
modifier|*
name|savedpc
decl_stmt|;
block|}
name|l
struct|;
struct|struct
block|{
comment|/* only for C functions */
name|int
name|ctx
decl_stmt|;
comment|/* context info. in case of yields */
name|lua_CFunction
name|k
decl_stmt|;
comment|/* continuation in case of yields */
name|ptrdiff_t
name|old_errfunc
decl_stmt|;
name|lu_byte
name|old_allowhook
decl_stmt|;
name|lu_byte
name|status
decl_stmt|;
block|}
name|c
struct|;
block|}
name|u
union|;
block|}
name|CallInfo
typedef|;
end_typedef

begin_comment
comment|/* ** Bits in CallInfo status */
end_comment

begin_define
define|#
directive|define
name|CIST_LUA
value|(1<<0)
end_define

begin_comment
comment|/* call is running a Lua function */
end_comment

begin_define
define|#
directive|define
name|CIST_HOOKED
value|(1<<1)
end_define

begin_comment
comment|/* call is running a debug hook */
end_comment

begin_define
define|#
directive|define
name|CIST_REENTRY
value|(1<<2)
end_define

begin_comment
comment|/* call is running on same invocation of                                    luaV_execute of previous call */
end_comment

begin_define
define|#
directive|define
name|CIST_YIELDED
value|(1<<3)
end_define

begin_comment
comment|/* call reentered after suspension */
end_comment

begin_define
define|#
directive|define
name|CIST_YPCALL
value|(1<<4)
end_define

begin_comment
comment|/* call is a yieldable protected call */
end_comment

begin_define
define|#
directive|define
name|CIST_STAT
value|(1<<5)
end_define

begin_comment
comment|/* call has an error status (pcall) */
end_comment

begin_define
define|#
directive|define
name|CIST_TAIL
value|(1<<6)
end_define

begin_comment
comment|/* call was tail called */
end_comment

begin_define
define|#
directive|define
name|CIST_HOOKYIELD
value|(1<<7)
end_define

begin_comment
comment|/* last hook called yielded */
end_comment

begin_define
define|#
directive|define
name|isLua
parameter_list|(
name|ci
parameter_list|)
value|((ci)->callstatus& CIST_LUA)
end_define

begin_comment
comment|/* ** `global state', shared by all threads of this state */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|global_State
block|{
name|lua_Alloc
name|frealloc
decl_stmt|;
comment|/* function to reallocate memory */
name|void
modifier|*
name|ud
decl_stmt|;
comment|/* auxiliary data to `frealloc' */
name|lu_mem
name|totalbytes
decl_stmt|;
comment|/* number of bytes currently allocated - GCdebt */
name|l_mem
name|GCdebt
decl_stmt|;
comment|/* bytes allocated not yet compensated by the collector */
name|lu_mem
name|GCmemtrav
decl_stmt|;
comment|/* memory traversed by the GC */
name|lu_mem
name|GCestimate
decl_stmt|;
comment|/* an estimate of the non-garbage memory in use */
name|stringtable
name|strt
decl_stmt|;
comment|/* hash table for strings */
name|TValue
name|l_registry
decl_stmt|;
name|unsigned
name|int
name|seed
decl_stmt|;
comment|/* randomized seed for hashes */
name|lu_byte
name|currentwhite
decl_stmt|;
name|lu_byte
name|gcstate
decl_stmt|;
comment|/* state of garbage collector */
name|lu_byte
name|gckind
decl_stmt|;
comment|/* kind of GC running */
name|lu_byte
name|gcrunning
decl_stmt|;
comment|/* true if GC is running */
name|int
name|sweepstrgc
decl_stmt|;
comment|/* position of sweep in `strt' */
name|GCObject
modifier|*
name|allgc
decl_stmt|;
comment|/* list of all collectable objects */
name|GCObject
modifier|*
name|finobj
decl_stmt|;
comment|/* list of collectable objects with finalizers */
name|GCObject
modifier|*
modifier|*
name|sweepgc
decl_stmt|;
comment|/* current position of sweep in list 'allgc' */
name|GCObject
modifier|*
modifier|*
name|sweepfin
decl_stmt|;
comment|/* current position of sweep in list 'finobj' */
name|GCObject
modifier|*
name|gray
decl_stmt|;
comment|/* list of gray objects */
name|GCObject
modifier|*
name|grayagain
decl_stmt|;
comment|/* list of objects to be traversed atomically */
name|GCObject
modifier|*
name|weak
decl_stmt|;
comment|/* list of tables with weak values */
name|GCObject
modifier|*
name|ephemeron
decl_stmt|;
comment|/* list of ephemeron tables (weak keys) */
name|GCObject
modifier|*
name|allweak
decl_stmt|;
comment|/* list of all-weak tables */
name|GCObject
modifier|*
name|tobefnz
decl_stmt|;
comment|/* list of userdata to be GC */
name|UpVal
name|uvhead
decl_stmt|;
comment|/* head of double-linked list of all open upvalues */
name|Mbuffer
name|buff
decl_stmt|;
comment|/* temporary buffer for string concatenation */
name|int
name|gcpause
decl_stmt|;
comment|/* size of pause between successive GCs */
name|int
name|gcmajorinc
decl_stmt|;
comment|/* pause between major collections (only in gen. mode) */
name|int
name|gcstepmul
decl_stmt|;
comment|/* GC `granularity' */
name|lua_CFunction
name|panic
decl_stmt|;
comment|/* to be called in unprotected errors */
name|struct
name|lua_State
modifier|*
name|mainthread
decl_stmt|;
specifier|const
name|lua_Number
modifier|*
name|version
decl_stmt|;
comment|/* pointer to version number */
name|TString
modifier|*
name|memerrmsg
decl_stmt|;
comment|/* memory-error message */
name|TString
modifier|*
name|tmname
index|[
name|TM_N
index|]
decl_stmt|;
comment|/* array with tag-method names */
name|struct
name|Table
modifier|*
name|mt
index|[
name|LUA_NUMTAGS
index|]
decl_stmt|;
comment|/* metatables for basic types */
block|}
name|global_State
typedef|;
end_typedef

begin_comment
comment|/* ** `per thread' state */
end_comment

begin_struct
struct|struct
name|lua_State
block|{
name|CommonHeader
expr_stmt|;
name|lu_byte
name|status
decl_stmt|;
name|StkId
name|top
decl_stmt|;
comment|/* first free slot in the stack */
name|global_State
modifier|*
name|l_G
decl_stmt|;
name|CallInfo
modifier|*
name|ci
decl_stmt|;
comment|/* call info for current function */
specifier|const
name|Instruction
modifier|*
name|oldpc
decl_stmt|;
comment|/* last pc traced */
name|StkId
name|stack_last
decl_stmt|;
comment|/* last free slot in the stack */
name|StkId
name|stack
decl_stmt|;
comment|/* stack base */
name|int
name|stacksize
decl_stmt|;
name|unsigned
name|short
name|nny
decl_stmt|;
comment|/* number of non-yieldable calls in stack */
name|unsigned
name|short
name|nCcalls
decl_stmt|;
comment|/* number of nested C calls */
name|lu_byte
name|hookmask
decl_stmt|;
name|lu_byte
name|allowhook
decl_stmt|;
name|int
name|basehookcount
decl_stmt|;
name|int
name|hookcount
decl_stmt|;
name|lua_Hook
name|hook
decl_stmt|;
name|GCObject
modifier|*
name|openupval
decl_stmt|;
comment|/* list of open upvalues in this stack */
name|GCObject
modifier|*
name|gclist
decl_stmt|;
name|struct
name|lua_longjmp
modifier|*
name|errorJmp
decl_stmt|;
comment|/* current error recover point */
name|ptrdiff_t
name|errfunc
decl_stmt|;
comment|/* current error handling function (stack index) */
name|CallInfo
name|base_ci
decl_stmt|;
comment|/* CallInfo for first level (C calling Lua) */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|G
parameter_list|(
name|L
parameter_list|)
value|(L->l_G)
end_define

begin_comment
comment|/* ** Union of all collectable objects */
end_comment

begin_union
union|union
name|GCObject
block|{
name|GCheader
name|gch
decl_stmt|;
comment|/* common header */
name|union
name|TString
name|ts
decl_stmt|;
name|union
name|Udata
name|u
decl_stmt|;
name|union
name|Closure
name|cl
decl_stmt|;
name|struct
name|Table
name|h
decl_stmt|;
name|struct
name|Proto
name|p
decl_stmt|;
name|struct
name|UpVal
name|uv
decl_stmt|;
name|struct
name|lua_State
name|th
decl_stmt|;
comment|/* thread */
block|}
union|;
end_union

begin_define
define|#
directive|define
name|gch
parameter_list|(
name|o
parameter_list|)
value|(&(o)->gch)
end_define

begin_comment
comment|/* macros to convert a GCObject into a specific value */
end_comment

begin_define
define|#
directive|define
name|rawgco2ts
parameter_list|(
name|o
parameter_list|)
define|\
value|check_exp(novariant((o)->gch.tt) == LUA_TSTRING,&((o)->ts))
end_define

begin_define
define|#
directive|define
name|gco2ts
parameter_list|(
name|o
parameter_list|)
value|(&rawgco2ts(o)->tsv)
end_define

begin_define
define|#
directive|define
name|rawgco2u
parameter_list|(
name|o
parameter_list|)
value|check_exp((o)->gch.tt == LUA_TUSERDATA,&((o)->u))
end_define

begin_define
define|#
directive|define
name|gco2u
parameter_list|(
name|o
parameter_list|)
value|(&rawgco2u(o)->uv)
end_define

begin_define
define|#
directive|define
name|gco2lcl
parameter_list|(
name|o
parameter_list|)
value|check_exp((o)->gch.tt == LUA_TLCL,&((o)->cl.l))
end_define

begin_define
define|#
directive|define
name|gco2ccl
parameter_list|(
name|o
parameter_list|)
value|check_exp((o)->gch.tt == LUA_TCCL,&((o)->cl.c))
end_define

begin_define
define|#
directive|define
name|gco2cl
parameter_list|(
name|o
parameter_list|)
define|\
value|check_exp(novariant((o)->gch.tt) == LUA_TFUNCTION,&((o)->cl))
end_define

begin_define
define|#
directive|define
name|gco2t
parameter_list|(
name|o
parameter_list|)
value|check_exp((o)->gch.tt == LUA_TTABLE,&((o)->h))
end_define

begin_define
define|#
directive|define
name|gco2p
parameter_list|(
name|o
parameter_list|)
value|check_exp((o)->gch.tt == LUA_TPROTO,&((o)->p))
end_define

begin_define
define|#
directive|define
name|gco2uv
parameter_list|(
name|o
parameter_list|)
value|check_exp((o)->gch.tt == LUA_TUPVAL,&((o)->uv))
end_define

begin_define
define|#
directive|define
name|gco2th
parameter_list|(
name|o
parameter_list|)
value|check_exp((o)->gch.tt == LUA_TTHREAD,&((o)->th))
end_define

begin_comment
comment|/* macro to convert any Lua object into a GCObject */
end_comment

begin_define
define|#
directive|define
name|obj2gco
parameter_list|(
name|v
parameter_list|)
value|(cast(GCObject *, (v)))
end_define

begin_comment
comment|/* actual number of total bytes allocated */
end_comment

begin_define
define|#
directive|define
name|gettotalbytes
parameter_list|(
name|g
parameter_list|)
value|((g)->totalbytes + (g)->GCdebt)
end_define

begin_function_decl
name|LUAI_FUNC
name|void
name|luaE_setdebt
parameter_list|(
name|global_State
modifier|*
name|g
parameter_list|,
name|l_mem
name|debt
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|LUAI_FUNC
name|void
name|luaE_freethread
parameter_list|(
name|lua_State
modifier|*
name|L
parameter_list|,
name|lua_State
modifier|*
name|L1
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|LUAI_FUNC
name|CallInfo
modifier|*
name|luaE_extendCI
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
name|luaE_freeCI
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

