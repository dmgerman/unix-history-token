begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* ** $Id: lgc.h,v 2.58.1.1 2013/04/12 18:48:47 roberto Exp $ ** Garbage Collector ** See Copyright Notice in lua.h */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|lgc_h
end_ifndef

begin_define
define|#
directive|define
name|lgc_h
end_define

begin_include
include|#
directive|include
file|"lobject.h"
end_include

begin_include
include|#
directive|include
file|"lstate.h"
end_include

begin_comment
comment|/* ** Collectable objects may have one of three colors: white, which ** means the object is not marked; gray, which means the ** object is marked, but its references may be not marked; and ** black, which means that the object and all its references are marked. ** The main invariant of the garbage collector, while marking objects, ** is that a black object can never point to a white one. Moreover, ** any gray object must be in a "gray list" (gray, grayagain, weak, ** allweak, ephemeron) so that it can be visited again before finishing ** the collection cycle. These lists have no meaning when the invariant ** is not being enforced (e.g., sweep phase). */
end_comment

begin_comment
comment|/* how much to allocate before next GC step */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|GCSTEPSIZE
argument_list|)
end_if

begin_comment
comment|/* ~100 small strings */
end_comment

begin_define
define|#
directive|define
name|GCSTEPSIZE
value|(cast_int(100 * sizeof(TString)))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ** Possible states of the Garbage Collector */
end_comment

begin_define
define|#
directive|define
name|GCSpropagate
value|0
end_define

begin_define
define|#
directive|define
name|GCSatomic
value|1
end_define

begin_define
define|#
directive|define
name|GCSsweepstring
value|2
end_define

begin_define
define|#
directive|define
name|GCSsweepudata
value|3
end_define

begin_define
define|#
directive|define
name|GCSsweep
value|4
end_define

begin_define
define|#
directive|define
name|GCSpause
value|5
end_define

begin_define
define|#
directive|define
name|issweepphase
parameter_list|(
name|g
parameter_list|)
define|\
value|(GCSsweepstring<= (g)->gcstate&& (g)->gcstate<= GCSsweep)
end_define

begin_define
define|#
directive|define
name|isgenerational
parameter_list|(
name|g
parameter_list|)
value|((g)->gckind == KGC_GEN)
end_define

begin_comment
comment|/* ** macros to tell when main invariant (white objects cannot point to black ** ones) must be kept. During a non-generational collection, the sweep ** phase may break the invariant, as objects turned white may point to ** still-black objects. The invariant is restored when sweep ends and ** all objects are white again. During a generational collection, the ** invariant must be kept all times. */
end_comment

begin_define
define|#
directive|define
name|keepinvariant
parameter_list|(
name|g
parameter_list|)
value|(isgenerational(g) || g->gcstate<= GCSatomic)
end_define

begin_comment
comment|/* ** Outside the collector, the state in generational mode is kept in ** 'propagate', so 'keepinvariant' is always true. */
end_comment

begin_define
define|#
directive|define
name|keepinvariantout
parameter_list|(
name|g
parameter_list|)
define|\
value|check_exp(g->gcstate == GCSpropagate || !isgenerational(g),  \             g->gcstate<= GCSatomic)
end_define

begin_comment
comment|/* ** some useful bit tricks */
end_comment

begin_define
define|#
directive|define
name|resetbits
parameter_list|(
name|x
parameter_list|,
name|m
parameter_list|)
value|((x)&= cast(lu_byte, ~(m)))
end_define

begin_define
define|#
directive|define
name|setbits
parameter_list|(
name|x
parameter_list|,
name|m
parameter_list|)
value|((x) |= (m))
end_define

begin_define
define|#
directive|define
name|testbits
parameter_list|(
name|x
parameter_list|,
name|m
parameter_list|)
value|((x)& (m))
end_define

begin_define
define|#
directive|define
name|bitmask
parameter_list|(
name|b
parameter_list|)
value|(1<<(b))
end_define

begin_define
define|#
directive|define
name|bit2mask
parameter_list|(
name|b1
parameter_list|,
name|b2
parameter_list|)
value|(bitmask(b1) | bitmask(b2))
end_define

begin_define
define|#
directive|define
name|l_setbit
parameter_list|(
name|x
parameter_list|,
name|b
parameter_list|)
value|setbits(x, bitmask(b))
end_define

begin_define
define|#
directive|define
name|resetbit
parameter_list|(
name|x
parameter_list|,
name|b
parameter_list|)
value|resetbits(x, bitmask(b))
end_define

begin_define
define|#
directive|define
name|testbit
parameter_list|(
name|x
parameter_list|,
name|b
parameter_list|)
value|testbits(x, bitmask(b))
end_define

begin_comment
comment|/* Layout for bit use in `marked' field: */
end_comment

begin_define
define|#
directive|define
name|WHITE0BIT
value|0
end_define

begin_comment
comment|/* object is white (type 0) */
end_comment

begin_define
define|#
directive|define
name|WHITE1BIT
value|1
end_define

begin_comment
comment|/* object is white (type 1) */
end_comment

begin_define
define|#
directive|define
name|BLACKBIT
value|2
end_define

begin_comment
comment|/* object is black */
end_comment

begin_define
define|#
directive|define
name|FINALIZEDBIT
value|3
end_define

begin_comment
comment|/* object has been separated for finalization */
end_comment

begin_define
define|#
directive|define
name|SEPARATED
value|4
end_define

begin_comment
comment|/* object is in 'finobj' list or in 'tobefnz' */
end_comment

begin_define
define|#
directive|define
name|FIXEDBIT
value|5
end_define

begin_comment
comment|/* object is fixed (should not be collected) */
end_comment

begin_define
define|#
directive|define
name|OLDBIT
value|6
end_define

begin_comment
comment|/* object is old (only in generational mode) */
end_comment

begin_comment
comment|/* bit 7 is currently used by tests (luaL_checkmemory) */
end_comment

begin_define
define|#
directive|define
name|WHITEBITS
value|bit2mask(WHITE0BIT, WHITE1BIT)
end_define

begin_define
define|#
directive|define
name|iswhite
parameter_list|(
name|x
parameter_list|)
value|testbits((x)->gch.marked, WHITEBITS)
end_define

begin_define
define|#
directive|define
name|isblack
parameter_list|(
name|x
parameter_list|)
value|testbit((x)->gch.marked, BLACKBIT)
end_define

begin_define
define|#
directive|define
name|isgray
parameter_list|(
name|x
parameter_list|)
comment|/* neither white nor black */
define|\
value|(!testbits((x)->gch.marked, WHITEBITS | bitmask(BLACKBIT)))
end_define

begin_define
define|#
directive|define
name|isold
parameter_list|(
name|x
parameter_list|)
value|testbit((x)->gch.marked, OLDBIT)
end_define

begin_comment
comment|/* MOVE OLD rule: whenever an object is moved to the beginning of    a GC list, its old bit must be cleared */
end_comment

begin_define
define|#
directive|define
name|resetoldbit
parameter_list|(
name|o
parameter_list|)
value|resetbit((o)->gch.marked, OLDBIT)
end_define

begin_define
define|#
directive|define
name|otherwhite
parameter_list|(
name|g
parameter_list|)
value|(g->currentwhite ^ WHITEBITS)
end_define

begin_define
define|#
directive|define
name|isdeadm
parameter_list|(
name|ow
parameter_list|,
name|m
parameter_list|)
value|(!(((m) ^ WHITEBITS)& (ow)))
end_define

begin_define
define|#
directive|define
name|isdead
parameter_list|(
name|g
parameter_list|,
name|v
parameter_list|)
value|isdeadm(otherwhite(g), (v)->gch.marked)
end_define

begin_define
define|#
directive|define
name|changewhite
parameter_list|(
name|x
parameter_list|)
value|((x)->gch.marked ^= WHITEBITS)
end_define

begin_define
define|#
directive|define
name|gray2black
parameter_list|(
name|x
parameter_list|)
value|l_setbit((x)->gch.marked, BLACKBIT)
end_define

begin_define
define|#
directive|define
name|valiswhite
parameter_list|(
name|x
parameter_list|)
value|(iscollectable(x)&& iswhite(gcvalue(x)))
end_define

begin_define
define|#
directive|define
name|luaC_white
parameter_list|(
name|g
parameter_list|)
value|cast(lu_byte, (g)->currentwhite& WHITEBITS)
end_define

begin_define
define|#
directive|define
name|luaC_condGC
parameter_list|(
name|L
parameter_list|,
name|c
parameter_list|)
define|\
value|{if (G(L)->GCdebt> 0) {c;}; condchangemem(L);}
end_define

begin_define
define|#
directive|define
name|luaC_checkGC
parameter_list|(
name|L
parameter_list|)
value|luaC_condGC(L, luaC_step(L);)
end_define

begin_define
define|#
directive|define
name|luaC_barrier
parameter_list|(
name|L
parameter_list|,
name|p
parameter_list|,
name|v
parameter_list|)
value|{ if (valiswhite(v)&& isblack(obj2gco(p)))  \ 	luaC_barrier_(L,obj2gco(p),gcvalue(v)); }
end_define

begin_define
define|#
directive|define
name|luaC_barrierback
parameter_list|(
name|L
parameter_list|,
name|p
parameter_list|,
name|v
parameter_list|)
value|{ if (valiswhite(v)&& isblack(obj2gco(p)))  \ 	luaC_barrierback_(L,p); }
end_define

begin_define
define|#
directive|define
name|luaC_objbarrier
parameter_list|(
name|L
parameter_list|,
name|p
parameter_list|,
name|o
parameter_list|)
define|\
value|{ if (iswhite(obj2gco(o))&& isblack(obj2gco(p))) \ 		luaC_barrier_(L,obj2gco(p),obj2gco(o)); }
end_define

begin_define
define|#
directive|define
name|luaC_objbarrierback
parameter_list|(
name|L
parameter_list|,
name|p
parameter_list|,
name|o
parameter_list|)
define|\
value|{ if (iswhite(obj2gco(o))&& isblack(obj2gco(p))) luaC_barrierback_(L,p); }
end_define

begin_define
define|#
directive|define
name|luaC_barrierproto
parameter_list|(
name|L
parameter_list|,
name|p
parameter_list|,
name|c
parameter_list|)
define|\
value|{ if (isblack(obj2gco(p))) luaC_barrierproto_(L,p,c); }
end_define

begin_function_decl
name|LUAI_FUNC
name|void
name|luaC_freeallobjects
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
name|luaC_step
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
name|luaC_forcestep
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
name|luaC_runtilstate
parameter_list|(
name|lua_State
modifier|*
name|L
parameter_list|,
name|int
name|statesmask
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|LUAI_FUNC
name|void
name|luaC_fullgc
parameter_list|(
name|lua_State
modifier|*
name|L
parameter_list|,
name|int
name|isemergency
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|LUAI_FUNC
name|GCObject
modifier|*
name|luaC_newobj
parameter_list|(
name|lua_State
modifier|*
name|L
parameter_list|,
name|int
name|tt
parameter_list|,
name|size_t
name|sz
parameter_list|,
name|GCObject
modifier|*
modifier|*
name|list
parameter_list|,
name|int
name|offset
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|LUAI_FUNC
name|void
name|luaC_barrier_
parameter_list|(
name|lua_State
modifier|*
name|L
parameter_list|,
name|GCObject
modifier|*
name|o
parameter_list|,
name|GCObject
modifier|*
name|v
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|LUAI_FUNC
name|void
name|luaC_barrierback_
parameter_list|(
name|lua_State
modifier|*
name|L
parameter_list|,
name|GCObject
modifier|*
name|o
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|LUAI_FUNC
name|void
name|luaC_barrierproto_
parameter_list|(
name|lua_State
modifier|*
name|L
parameter_list|,
name|Proto
modifier|*
name|p
parameter_list|,
name|Closure
modifier|*
name|c
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|LUAI_FUNC
name|void
name|luaC_checkfinalizer
parameter_list|(
name|lua_State
modifier|*
name|L
parameter_list|,
name|GCObject
modifier|*
name|o
parameter_list|,
name|Table
modifier|*
name|mt
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|LUAI_FUNC
name|void
name|luaC_checkupvalcolor
parameter_list|(
name|global_State
modifier|*
name|g
parameter_list|,
name|UpVal
modifier|*
name|uv
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|LUAI_FUNC
name|void
name|luaC_changemode
parameter_list|(
name|lua_State
modifier|*
name|L
parameter_list|,
name|int
name|mode
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

end_unit

