begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* ** $Id: lobject.h,v 2.71.1.2 2014/05/07 14:14:58 roberto Exp $ ** Type definitions for Lua objects ** See Copyright Notice in lua.h */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|lobject_h
end_ifndef

begin_define
define|#
directive|define
name|lobject_h
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
comment|/* ** Extra tags for non-values */
end_comment

begin_define
define|#
directive|define
name|LUA_TPROTO
value|LUA_NUMTAGS
end_define

begin_define
define|#
directive|define
name|LUA_TUPVAL
value|(LUA_NUMTAGS+1)
end_define

begin_define
define|#
directive|define
name|LUA_TDEADKEY
value|(LUA_NUMTAGS+2)
end_define

begin_comment
comment|/* ** number of all possible tags (including LUA_TNONE but excluding DEADKEY) */
end_comment

begin_define
define|#
directive|define
name|LUA_TOTALTAGS
value|(LUA_TUPVAL+2)
end_define

begin_comment
comment|/* ** tags for Tagged Values have the following use of bits: ** bits 0-3: actual tag (a LUA_T* value) ** bits 4-5: variant bits ** bit 6: whether value is collectable */
end_comment

begin_define
define|#
directive|define
name|VARBITS
value|(3<< 4)
end_define

begin_comment
comment|/* ** LUA_TFUNCTION variants: ** 0 - Lua function ** 1 - light C function ** 2 - regular C function (closure) */
end_comment

begin_comment
comment|/* Variant tags for functions */
end_comment

begin_define
define|#
directive|define
name|LUA_TLCL
value|(LUA_TFUNCTION | (0<< 4))
end_define

begin_comment
comment|/* Lua closure */
end_comment

begin_define
define|#
directive|define
name|LUA_TLCF
value|(LUA_TFUNCTION | (1<< 4))
end_define

begin_comment
comment|/* light C function */
end_comment

begin_define
define|#
directive|define
name|LUA_TCCL
value|(LUA_TFUNCTION | (2<< 4))
end_define

begin_comment
comment|/* C closure */
end_comment

begin_comment
comment|/* Variant tags for strings */
end_comment

begin_define
define|#
directive|define
name|LUA_TSHRSTR
value|(LUA_TSTRING | (0<< 4))
end_define

begin_comment
comment|/* short strings */
end_comment

begin_define
define|#
directive|define
name|LUA_TLNGSTR
value|(LUA_TSTRING | (1<< 4))
end_define

begin_comment
comment|/* long strings */
end_comment

begin_comment
comment|/* Bit mark for collectable types */
end_comment

begin_define
define|#
directive|define
name|BIT_ISCOLLECTABLE
value|(1<< 6)
end_define

begin_comment
comment|/* mark a tag as collectable */
end_comment

begin_define
define|#
directive|define
name|ctb
parameter_list|(
name|t
parameter_list|)
value|((t) | BIT_ISCOLLECTABLE)
end_define

begin_comment
comment|/* ** Union of all collectable objects */
end_comment

begin_typedef
typedef|typedef
name|union
name|GCObject
name|GCObject
typedef|;
end_typedef

begin_comment
comment|/* ** Common Header for all collectable objects (in macro form, to be ** included in other objects) */
end_comment

begin_define
define|#
directive|define
name|CommonHeader
value|GCObject *next; lu_byte tt; lu_byte marked
end_define

begin_comment
comment|/* ** Common header in struct form */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|GCheader
block|{
name|CommonHeader
expr_stmt|;
block|}
name|GCheader
typedef|;
end_typedef

begin_comment
comment|/* ** Union of all Lua values */
end_comment

begin_typedef
typedef|typedef
name|union
name|Value
name|Value
typedef|;
end_typedef

begin_define
define|#
directive|define
name|numfield
value|lua_Number n;
end_define

begin_comment
comment|/* numbers */
end_comment

begin_comment
comment|/* ** Tagged Values. This is the basic representation of values in Lua, ** an actual value plus a tag with its type. */
end_comment

begin_define
define|#
directive|define
name|TValuefields
value|Value value_; int tt_
end_define

begin_typedef
typedef|typedef
name|struct
name|lua_TValue
name|TValue
typedef|;
end_typedef

begin_comment
comment|/* macro defining a nil value */
end_comment

begin_define
define|#
directive|define
name|NILCONSTANT
value|{NULL}, LUA_TNIL
end_define

begin_define
define|#
directive|define
name|val_
parameter_list|(
name|o
parameter_list|)
value|((o)->value_)
end_define

begin_define
define|#
directive|define
name|num_
parameter_list|(
name|o
parameter_list|)
value|(val_(o).n)
end_define

begin_comment
comment|/* raw type tag of a TValue */
end_comment

begin_define
define|#
directive|define
name|rttype
parameter_list|(
name|o
parameter_list|)
value|((o)->tt_)
end_define

begin_comment
comment|/* tag with no variants (bits 0-3) */
end_comment

begin_define
define|#
directive|define
name|novariant
parameter_list|(
name|x
parameter_list|)
value|((x)& 0x0F)
end_define

begin_comment
comment|/* type tag of a TValue (bits 0-3 for tags + variant bits 4-5) */
end_comment

begin_define
define|#
directive|define
name|ttype
parameter_list|(
name|o
parameter_list|)
value|(rttype(o)& 0x3F)
end_define

begin_comment
comment|/* type tag of a TValue with no variants (bits 0-3) */
end_comment

begin_define
define|#
directive|define
name|ttypenv
parameter_list|(
name|o
parameter_list|)
value|(novariant(rttype(o)))
end_define

begin_comment
comment|/* Macros to test type */
end_comment

begin_define
define|#
directive|define
name|checktag
parameter_list|(
name|o
parameter_list|,
name|t
parameter_list|)
value|(rttype(o) == (t))
end_define

begin_define
define|#
directive|define
name|checktype
parameter_list|(
name|o
parameter_list|,
name|t
parameter_list|)
value|(ttypenv(o) == (t))
end_define

begin_define
define|#
directive|define
name|ttisnumber
parameter_list|(
name|o
parameter_list|)
value|checktag((o), LUA_TNUMBER)
end_define

begin_define
define|#
directive|define
name|ttisnil
parameter_list|(
name|o
parameter_list|)
value|checktag((o), LUA_TNIL)
end_define

begin_define
define|#
directive|define
name|ttisboolean
parameter_list|(
name|o
parameter_list|)
value|checktag((o), LUA_TBOOLEAN)
end_define

begin_define
define|#
directive|define
name|ttislightuserdata
parameter_list|(
name|o
parameter_list|)
value|checktag((o), LUA_TLIGHTUSERDATA)
end_define

begin_define
define|#
directive|define
name|ttisstring
parameter_list|(
name|o
parameter_list|)
value|checktype((o), LUA_TSTRING)
end_define

begin_define
define|#
directive|define
name|ttisshrstring
parameter_list|(
name|o
parameter_list|)
value|checktag((o), ctb(LUA_TSHRSTR))
end_define

begin_define
define|#
directive|define
name|ttislngstring
parameter_list|(
name|o
parameter_list|)
value|checktag((o), ctb(LUA_TLNGSTR))
end_define

begin_define
define|#
directive|define
name|ttistable
parameter_list|(
name|o
parameter_list|)
value|checktag((o), ctb(LUA_TTABLE))
end_define

begin_define
define|#
directive|define
name|ttisfunction
parameter_list|(
name|o
parameter_list|)
value|checktype(o, LUA_TFUNCTION)
end_define

begin_define
define|#
directive|define
name|ttisclosure
parameter_list|(
name|o
parameter_list|)
value|((rttype(o)& 0x1F) == LUA_TFUNCTION)
end_define

begin_define
define|#
directive|define
name|ttisCclosure
parameter_list|(
name|o
parameter_list|)
value|checktag((o), ctb(LUA_TCCL))
end_define

begin_define
define|#
directive|define
name|ttisLclosure
parameter_list|(
name|o
parameter_list|)
value|checktag((o), ctb(LUA_TLCL))
end_define

begin_define
define|#
directive|define
name|ttislcf
parameter_list|(
name|o
parameter_list|)
value|checktag((o), LUA_TLCF)
end_define

begin_define
define|#
directive|define
name|ttisuserdata
parameter_list|(
name|o
parameter_list|)
value|checktag((o), ctb(LUA_TUSERDATA))
end_define

begin_define
define|#
directive|define
name|ttisthread
parameter_list|(
name|o
parameter_list|)
value|checktag((o), ctb(LUA_TTHREAD))
end_define

begin_define
define|#
directive|define
name|ttisdeadkey
parameter_list|(
name|o
parameter_list|)
value|checktag((o), LUA_TDEADKEY)
end_define

begin_define
define|#
directive|define
name|ttisequal
parameter_list|(
name|o1
parameter_list|,
name|o2
parameter_list|)
value|(rttype(o1) == rttype(o2))
end_define

begin_comment
comment|/* Macros to access values */
end_comment

begin_define
define|#
directive|define
name|nvalue
parameter_list|(
name|o
parameter_list|)
value|check_exp(ttisnumber(o), num_(o))
end_define

begin_define
define|#
directive|define
name|gcvalue
parameter_list|(
name|o
parameter_list|)
value|check_exp(iscollectable(o), val_(o).gc)
end_define

begin_define
define|#
directive|define
name|pvalue
parameter_list|(
name|o
parameter_list|)
value|check_exp(ttislightuserdata(o), val_(o).p)
end_define

begin_define
define|#
directive|define
name|rawtsvalue
parameter_list|(
name|o
parameter_list|)
value|check_exp(ttisstring(o),&val_(o).gc->ts)
end_define

begin_define
define|#
directive|define
name|tsvalue
parameter_list|(
name|o
parameter_list|)
value|(&rawtsvalue(o)->tsv)
end_define

begin_define
define|#
directive|define
name|rawuvalue
parameter_list|(
name|o
parameter_list|)
value|check_exp(ttisuserdata(o),&val_(o).gc->u)
end_define

begin_define
define|#
directive|define
name|uvalue
parameter_list|(
name|o
parameter_list|)
value|(&rawuvalue(o)->uv)
end_define

begin_define
define|#
directive|define
name|clvalue
parameter_list|(
name|o
parameter_list|)
value|check_exp(ttisclosure(o),&val_(o).gc->cl)
end_define

begin_define
define|#
directive|define
name|clLvalue
parameter_list|(
name|o
parameter_list|)
value|check_exp(ttisLclosure(o),&val_(o).gc->cl.l)
end_define

begin_define
define|#
directive|define
name|clCvalue
parameter_list|(
name|o
parameter_list|)
value|check_exp(ttisCclosure(o),&val_(o).gc->cl.c)
end_define

begin_define
define|#
directive|define
name|fvalue
parameter_list|(
name|o
parameter_list|)
value|check_exp(ttislcf(o), val_(o).f)
end_define

begin_define
define|#
directive|define
name|hvalue
parameter_list|(
name|o
parameter_list|)
value|check_exp(ttistable(o),&val_(o).gc->h)
end_define

begin_define
define|#
directive|define
name|bvalue
parameter_list|(
name|o
parameter_list|)
value|check_exp(ttisboolean(o), val_(o).b)
end_define

begin_define
define|#
directive|define
name|thvalue
parameter_list|(
name|o
parameter_list|)
value|check_exp(ttisthread(o),&val_(o).gc->th)
end_define

begin_comment
comment|/* a dead value may get the 'gc' field, but cannot access its contents */
end_comment

begin_define
define|#
directive|define
name|deadvalue
parameter_list|(
name|o
parameter_list|)
value|check_exp(ttisdeadkey(o), cast(void *, val_(o).gc))
end_define

begin_define
define|#
directive|define
name|l_isfalse
parameter_list|(
name|o
parameter_list|)
value|(ttisnil(o) || (ttisboolean(o)&& bvalue(o) == 0))
end_define

begin_define
define|#
directive|define
name|iscollectable
parameter_list|(
name|o
parameter_list|)
value|(rttype(o)& BIT_ISCOLLECTABLE)
end_define

begin_comment
comment|/* Macros for internal tests */
end_comment

begin_define
define|#
directive|define
name|righttt
parameter_list|(
name|obj
parameter_list|)
value|(ttype(obj) == gcvalue(obj)->gch.tt)
end_define

begin_define
define|#
directive|define
name|checkliveness
parameter_list|(
name|g
parameter_list|,
name|obj
parameter_list|)
define|\
value|lua_longassert(!iscollectable(obj) || \ 			(righttt(obj)&& !isdead(g,gcvalue(obj))))
end_define

begin_comment
comment|/* Macros to set values */
end_comment

begin_define
define|#
directive|define
name|settt_
parameter_list|(
name|o
parameter_list|,
name|t
parameter_list|)
value|((o)->tt_=(t))
end_define

begin_define
define|#
directive|define
name|setnvalue
parameter_list|(
name|obj
parameter_list|,
name|x
parameter_list|)
define|\
value|{ TValue *io=(obj); num_(io)=(x); settt_(io, LUA_TNUMBER); }
end_define

begin_define
define|#
directive|define
name|setnilvalue
parameter_list|(
name|obj
parameter_list|)
value|settt_(obj, LUA_TNIL)
end_define

begin_define
define|#
directive|define
name|setfvalue
parameter_list|(
name|obj
parameter_list|,
name|x
parameter_list|)
define|\
value|{ TValue *io=(obj); val_(io).f=(x); settt_(io, LUA_TLCF); }
end_define

begin_define
define|#
directive|define
name|setpvalue
parameter_list|(
name|obj
parameter_list|,
name|x
parameter_list|)
define|\
value|{ TValue *io=(obj); val_(io).p=(x); settt_(io, LUA_TLIGHTUSERDATA); }
end_define

begin_define
define|#
directive|define
name|setbvalue
parameter_list|(
name|obj
parameter_list|,
name|x
parameter_list|)
define|\
value|{ TValue *io=(obj); val_(io).b=(x); settt_(io, LUA_TBOOLEAN); }
end_define

begin_define
define|#
directive|define
name|setgcovalue
parameter_list|(
name|L
parameter_list|,
name|obj
parameter_list|,
name|x
parameter_list|)
define|\
value|{ TValue *io=(obj); GCObject *i_g=(x); \     val_(io).gc=i_g; settt_(io, ctb(gch(i_g)->tt)); }
end_define

begin_define
define|#
directive|define
name|setsvalue
parameter_list|(
name|L
parameter_list|,
name|obj
parameter_list|,
name|x
parameter_list|)
define|\
value|{ TValue *io=(obj); \     TString *x_ = (x); \     val_(io).gc=cast(GCObject *, x_); settt_(io, ctb(x_->tsv.tt)); \     checkliveness(G(L),io); }
end_define

begin_define
define|#
directive|define
name|setuvalue
parameter_list|(
name|L
parameter_list|,
name|obj
parameter_list|,
name|x
parameter_list|)
define|\
value|{ TValue *io=(obj); \     val_(io).gc=cast(GCObject *, (x)); settt_(io, ctb(LUA_TUSERDATA)); \     checkliveness(G(L),io); }
end_define

begin_define
define|#
directive|define
name|setthvalue
parameter_list|(
name|L
parameter_list|,
name|obj
parameter_list|,
name|x
parameter_list|)
define|\
value|{ TValue *io=(obj); \     val_(io).gc=cast(GCObject *, (x)); settt_(io, ctb(LUA_TTHREAD)); \     checkliveness(G(L),io); }
end_define

begin_define
define|#
directive|define
name|setclLvalue
parameter_list|(
name|L
parameter_list|,
name|obj
parameter_list|,
name|x
parameter_list|)
define|\
value|{ TValue *io=(obj); \     val_(io).gc=cast(GCObject *, (x)); settt_(io, ctb(LUA_TLCL)); \     checkliveness(G(L),io); }
end_define

begin_define
define|#
directive|define
name|setclCvalue
parameter_list|(
name|L
parameter_list|,
name|obj
parameter_list|,
name|x
parameter_list|)
define|\
value|{ TValue *io=(obj); \     val_(io).gc=cast(GCObject *, (x)); settt_(io, ctb(LUA_TCCL)); \     checkliveness(G(L),io); }
end_define

begin_define
define|#
directive|define
name|sethvalue
parameter_list|(
name|L
parameter_list|,
name|obj
parameter_list|,
name|x
parameter_list|)
define|\
value|{ TValue *io=(obj); \     val_(io).gc=cast(GCObject *, (x)); settt_(io, ctb(LUA_TTABLE)); \     checkliveness(G(L),io); }
end_define

begin_define
define|#
directive|define
name|setdeadvalue
parameter_list|(
name|obj
parameter_list|)
value|settt_(obj, LUA_TDEADKEY)
end_define

begin_define
define|#
directive|define
name|setobj
parameter_list|(
name|L
parameter_list|,
name|obj1
parameter_list|,
name|obj2
parameter_list|)
define|\
value|{ const TValue *io2=(obj2); TValue *io1=(obj1); \ 	  io1->value_ = io2->value_; io1->tt_ = io2->tt_; \ 	  checkliveness(G(L),io1); }
end_define

begin_comment
comment|/* ** different types of assignments, according to destination */
end_comment

begin_comment
comment|/* from stack to (same) stack */
end_comment

begin_define
define|#
directive|define
name|setobjs2s
value|setobj
end_define

begin_comment
comment|/* to stack (not from same stack) */
end_comment

begin_define
define|#
directive|define
name|setobj2s
value|setobj
end_define

begin_define
define|#
directive|define
name|setsvalue2s
value|setsvalue
end_define

begin_define
define|#
directive|define
name|sethvalue2s
value|sethvalue
end_define

begin_define
define|#
directive|define
name|setptvalue2s
value|setptvalue
end_define

begin_comment
comment|/* from table to same table */
end_comment

begin_define
define|#
directive|define
name|setobjt2t
value|setobj
end_define

begin_comment
comment|/* to table */
end_comment

begin_define
define|#
directive|define
name|setobj2t
value|setobj
end_define

begin_comment
comment|/* to new object */
end_comment

begin_define
define|#
directive|define
name|setobj2n
value|setobj
end_define

begin_define
define|#
directive|define
name|setsvalue2n
value|setsvalue
end_define

begin_comment
comment|/* check whether a number is valid (useful only for NaN trick) */
end_comment

begin_define
define|#
directive|define
name|luai_checknum
parameter_list|(
name|L
parameter_list|,
name|o
parameter_list|,
name|c
parameter_list|)
value|{
comment|/* empty */
value|}
end_define

begin_comment
comment|/* ** {====================================================== ** NaN Trick ** ======================================================= */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|LUA_NANTRICK
argument_list|)
end_if

begin_comment
comment|/* ** numbers are represented in the 'd_' field. All other values have the ** value (NNMARK | tag) in 'tt__'. A number with such pattern would be ** a "signaled NaN", which is never generated by regular operations by ** the CPU (nor by 'strtod') */
end_comment

begin_comment
comment|/* allows for external implementation for part of the trick */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|NNMARK
argument_list|)
end_if

begin_comment
comment|/* { */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|LUA_IEEEENDIAN
argument_list|)
end_if

begin_error
error|#
directive|error
error|option 'LUA_NANTRICK' needs 'LUA_IEEEENDIAN'
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|NNMARK
value|0x7FF7A500
end_define

begin_define
define|#
directive|define
name|NNMASK
value|0x7FFFFF00
end_define

begin_undef
undef|#
directive|undef
name|TValuefields
end_undef

begin_undef
undef|#
directive|undef
name|NILCONSTANT
end_undef

begin_if
if|#
directive|if
operator|(
name|LUA_IEEEENDIAN
operator|==
literal|0
operator|)
end_if

begin_comment
comment|/* { */
end_comment

begin_comment
comment|/* little endian */
end_comment

begin_define
define|#
directive|define
name|TValuefields
define|\
value|union { struct { Value v__; int tt__; } i; double d__; } u
end_define

begin_define
define|#
directive|define
name|NILCONSTANT
value|{{{NULL}, tag2tt(LUA_TNIL)}}
end_define

begin_comment
comment|/* field-access macros */
end_comment

begin_define
define|#
directive|define
name|v_
parameter_list|(
name|o
parameter_list|)
value|((o)->u.i.v__)
end_define

begin_define
define|#
directive|define
name|d_
parameter_list|(
name|o
parameter_list|)
value|((o)->u.d__)
end_define

begin_define
define|#
directive|define
name|tt_
parameter_list|(
name|o
parameter_list|)
value|((o)->u.i.tt__)
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* }{ */
end_comment

begin_comment
comment|/* big endian */
end_comment

begin_define
define|#
directive|define
name|TValuefields
define|\
value|union { struct { int tt__; Value v__; } i; double d__; } u
end_define

begin_define
define|#
directive|define
name|NILCONSTANT
value|{{tag2tt(LUA_TNIL), {NULL}}}
end_define

begin_comment
comment|/* field-access macros */
end_comment

begin_define
define|#
directive|define
name|v_
parameter_list|(
name|o
parameter_list|)
value|((o)->u.i.v__)
end_define

begin_define
define|#
directive|define
name|d_
parameter_list|(
name|o
parameter_list|)
value|((o)->u.d__)
end_define

begin_define
define|#
directive|define
name|tt_
parameter_list|(
name|o
parameter_list|)
value|((o)->u.i.tt__)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* } */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* } */
end_comment

begin_comment
comment|/* correspondence with standard representation */
end_comment

begin_undef
undef|#
directive|undef
name|val_
end_undef

begin_define
define|#
directive|define
name|val_
parameter_list|(
name|o
parameter_list|)
value|v_(o)
end_define

begin_undef
undef|#
directive|undef
name|num_
end_undef

begin_define
define|#
directive|define
name|num_
parameter_list|(
name|o
parameter_list|)
value|d_(o)
end_define

begin_undef
undef|#
directive|undef
name|numfield
end_undef

begin_define
define|#
directive|define
name|numfield
end_define

begin_comment
comment|/* no such field; numbers are the entire struct */
end_comment

begin_comment
comment|/* basic check to distinguish numbers from non-numbers */
end_comment

begin_undef
undef|#
directive|undef
name|ttisnumber
end_undef

begin_define
define|#
directive|define
name|ttisnumber
parameter_list|(
name|o
parameter_list|)
value|((tt_(o)& NNMASK) != NNMARK)
end_define

begin_define
define|#
directive|define
name|tag2tt
parameter_list|(
name|t
parameter_list|)
value|(NNMARK | (t))
end_define

begin_undef
undef|#
directive|undef
name|rttype
end_undef

begin_define
define|#
directive|define
name|rttype
parameter_list|(
name|o
parameter_list|)
value|(ttisnumber(o) ? LUA_TNUMBER : tt_(o)& 0xff)
end_define

begin_undef
undef|#
directive|undef
name|settt_
end_undef

begin_define
define|#
directive|define
name|settt_
parameter_list|(
name|o
parameter_list|,
name|t
parameter_list|)
value|(tt_(o) = tag2tt(t))
end_define

begin_undef
undef|#
directive|undef
name|setnvalue
end_undef

begin_define
define|#
directive|define
name|setnvalue
parameter_list|(
name|obj
parameter_list|,
name|x
parameter_list|)
define|\
value|{ TValue *io_=(obj); num_(io_)=(x); lua_assert(ttisnumber(io_)); }
end_define

begin_undef
undef|#
directive|undef
name|setobj
end_undef

begin_define
define|#
directive|define
name|setobj
parameter_list|(
name|L
parameter_list|,
name|obj1
parameter_list|,
name|obj2
parameter_list|)
define|\
value|{ const TValue *o2_=(obj2); TValue *o1_=(obj1); \ 	  o1_->u = o2_->u; \ 	  checkliveness(G(L),o1_); }
end_define

begin_comment
comment|/* ** these redefinitions are not mandatory, but these forms are more efficient */
end_comment

begin_undef
undef|#
directive|undef
name|checktag
end_undef

begin_undef
undef|#
directive|undef
name|checktype
end_undef

begin_define
define|#
directive|define
name|checktag
parameter_list|(
name|o
parameter_list|,
name|t
parameter_list|)
value|(tt_(o) == tag2tt(t))
end_define

begin_define
define|#
directive|define
name|checktype
parameter_list|(
name|o
parameter_list|,
name|t
parameter_list|)
value|(ctb(tt_(o) | VARBITS) == ctb(tag2tt(t) | VARBITS))
end_define

begin_undef
undef|#
directive|undef
name|ttisequal
end_undef

begin_define
define|#
directive|define
name|ttisequal
parameter_list|(
name|o1
parameter_list|,
name|o2
parameter_list|)
define|\
value|(ttisnumber(o1) ? ttisnumber(o2) : (tt_(o1) == tt_(o2)))
end_define

begin_undef
undef|#
directive|undef
name|luai_checknum
end_undef

begin_define
define|#
directive|define
name|luai_checknum
parameter_list|(
name|L
parameter_list|,
name|o
parameter_list|,
name|c
parameter_list|)
value|{ if (!ttisnumber(o)) c; }
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* }====================================================== */
end_comment

begin_comment
comment|/* ** {====================================================== ** types and prototypes ** ======================================================= */
end_comment

begin_union
union|union
name|Value
block|{
name|GCObject
modifier|*
name|gc
decl_stmt|;
comment|/* collectable objects */
name|void
modifier|*
name|p
decl_stmt|;
comment|/* light userdata */
name|int
name|b
decl_stmt|;
comment|/* booleans */
name|lua_CFunction
name|f
decl_stmt|;
comment|/* light C functions */
name|numfield
comment|/* numbers */
block|}
union|;
end_union

begin_struct
struct|struct
name|lua_TValue
block|{
name|TValuefields
expr_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|TValue
modifier|*
name|StkId
typedef|;
end_typedef

begin_comment
comment|/* index to stack elements */
end_comment

begin_comment
comment|/* ** Header for string value; string bytes follow the end of this structure */
end_comment

begin_typedef
typedef|typedef
union|union
name|TString
block|{
name|L_Umaxalign
name|dummy
decl_stmt|;
comment|/* ensures maximum alignment for strings */
struct|struct
block|{
name|CommonHeader
expr_stmt|;
name|lu_byte
name|extra
decl_stmt|;
comment|/* reserved words for short strings; "has hash" for longs */
name|unsigned
name|int
name|hash
decl_stmt|;
name|size_t
name|len
decl_stmt|;
comment|/* number of characters in string */
block|}
name|tsv
struct|;
block|}
name|TString
typedef|;
end_typedef

begin_comment
comment|/* get the actual string (array of bytes) from a TString */
end_comment

begin_define
define|#
directive|define
name|getstr
parameter_list|(
name|ts
parameter_list|)
value|cast(const char *, (ts) + 1)
end_define

begin_comment
comment|/* get the actual string (array of bytes) from a Lua value */
end_comment

begin_define
define|#
directive|define
name|svalue
parameter_list|(
name|o
parameter_list|)
value|getstr(rawtsvalue(o))
end_define

begin_comment
comment|/* ** Header for userdata; memory area follows the end of this structure */
end_comment

begin_typedef
typedef|typedef
union|union
name|Udata
block|{
name|L_Umaxalign
name|dummy
decl_stmt|;
comment|/* ensures maximum alignment for `local' udata */
struct|struct
block|{
name|CommonHeader
expr_stmt|;
name|struct
name|Table
modifier|*
name|metatable
decl_stmt|;
name|struct
name|Table
modifier|*
name|env
decl_stmt|;
name|size_t
name|len
decl_stmt|;
comment|/* number of bytes */
block|}
name|uv
struct|;
block|}
name|Udata
typedef|;
end_typedef

begin_comment
comment|/* ** Description of an upvalue for function prototypes */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|Upvaldesc
block|{
name|TString
modifier|*
name|name
decl_stmt|;
comment|/* upvalue name (for debug information) */
name|lu_byte
name|instack
decl_stmt|;
comment|/* whether it is in stack */
name|lu_byte
name|idx
decl_stmt|;
comment|/* index of upvalue (in stack or in outer function's list) */
block|}
name|Upvaldesc
typedef|;
end_typedef

begin_comment
comment|/* ** Description of a local variable for function prototypes ** (used for debug information) */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|LocVar
block|{
name|TString
modifier|*
name|varname
decl_stmt|;
name|int
name|startpc
decl_stmt|;
comment|/* first point where variable is active */
name|int
name|endpc
decl_stmt|;
comment|/* first point where variable is dead */
block|}
name|LocVar
typedef|;
end_typedef

begin_comment
comment|/* ** Function Prototypes */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|Proto
block|{
name|CommonHeader
expr_stmt|;
name|TValue
modifier|*
name|k
decl_stmt|;
comment|/* constants used by the function */
name|Instruction
modifier|*
name|code
decl_stmt|;
name|struct
name|Proto
modifier|*
modifier|*
name|p
decl_stmt|;
comment|/* functions defined inside the function */
name|int
modifier|*
name|lineinfo
decl_stmt|;
comment|/* map from opcodes to source lines (debug information) */
name|LocVar
modifier|*
name|locvars
decl_stmt|;
comment|/* information about local variables (debug information) */
name|Upvaldesc
modifier|*
name|upvalues
decl_stmt|;
comment|/* upvalue information */
name|union
name|Closure
modifier|*
name|cache
decl_stmt|;
comment|/* last created closure with this prototype */
name|TString
modifier|*
name|source
decl_stmt|;
comment|/* used for debug information */
name|int
name|sizeupvalues
decl_stmt|;
comment|/* size of 'upvalues' */
name|int
name|sizek
decl_stmt|;
comment|/* size of `k' */
name|int
name|sizecode
decl_stmt|;
name|int
name|sizelineinfo
decl_stmt|;
name|int
name|sizep
decl_stmt|;
comment|/* size of `p' */
name|int
name|sizelocvars
decl_stmt|;
name|int
name|linedefined
decl_stmt|;
name|int
name|lastlinedefined
decl_stmt|;
name|GCObject
modifier|*
name|gclist
decl_stmt|;
name|lu_byte
name|numparams
decl_stmt|;
comment|/* number of fixed parameters */
name|lu_byte
name|is_vararg
decl_stmt|;
name|lu_byte
name|maxstacksize
decl_stmt|;
comment|/* maximum stack used by this function */
block|}
name|Proto
typedef|;
end_typedef

begin_comment
comment|/* ** Lua Upvalues */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|UpVal
block|{
name|CommonHeader
expr_stmt|;
name|TValue
modifier|*
name|v
decl_stmt|;
comment|/* points to stack or to its own value */
union|union
block|{
name|TValue
name|value
decl_stmt|;
comment|/* the value (when closed) */
struct|struct
block|{
comment|/* double linked list (when open) */
name|struct
name|UpVal
modifier|*
name|prev
decl_stmt|;
name|struct
name|UpVal
modifier|*
name|next
decl_stmt|;
block|}
name|l
struct|;
block|}
name|u
union|;
block|}
name|UpVal
typedef|;
end_typedef

begin_comment
comment|/* ** Closures */
end_comment

begin_define
define|#
directive|define
name|ClosureHeader
define|\
value|CommonHeader; lu_byte nupvalues; GCObject *gclist
end_define

begin_typedef
typedef|typedef
struct|struct
name|CClosure
block|{
name|ClosureHeader
expr_stmt|;
name|lua_CFunction
name|f
decl_stmt|;
name|TValue
name|upvalue
index|[
literal|1
index|]
decl_stmt|;
comment|/* list of upvalues */
block|}
name|CClosure
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|LClosure
block|{
name|ClosureHeader
expr_stmt|;
name|struct
name|Proto
modifier|*
name|p
decl_stmt|;
name|UpVal
modifier|*
name|upvals
index|[
literal|1
index|]
decl_stmt|;
comment|/* list of upvalues */
block|}
name|LClosure
typedef|;
end_typedef

begin_typedef
typedef|typedef
union|union
name|Closure
block|{
name|CClosure
name|c
decl_stmt|;
name|LClosure
name|l
decl_stmt|;
block|}
name|Closure
typedef|;
end_typedef

begin_define
define|#
directive|define
name|isLfunction
parameter_list|(
name|o
parameter_list|)
value|ttisLclosure(o)
end_define

begin_define
define|#
directive|define
name|getproto
parameter_list|(
name|o
parameter_list|)
value|(clLvalue(o)->p)
end_define

begin_comment
comment|/* ** Tables */
end_comment

begin_typedef
typedef|typedef
union|union
name|TKey
block|{
struct|struct
block|{
name|TValuefields
expr_stmt|;
name|struct
name|Node
modifier|*
name|next
decl_stmt|;
comment|/* for chaining */
block|}
name|nk
struct|;
name|TValue
name|tvk
decl_stmt|;
block|}
name|TKey
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|Node
block|{
name|TValue
name|i_val
decl_stmt|;
name|TKey
name|i_key
decl_stmt|;
block|}
name|Node
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|Table
block|{
name|CommonHeader
expr_stmt|;
name|lu_byte
name|flags
decl_stmt|;
comment|/* 1<<p means tagmethod(p) is not present */
name|lu_byte
name|lsizenode
decl_stmt|;
comment|/* log2 of size of `node' array */
name|int
name|sizearray
decl_stmt|;
comment|/* size of `array' array */
name|TValue
modifier|*
name|array
decl_stmt|;
comment|/* array part */
name|Node
modifier|*
name|node
decl_stmt|;
name|Node
modifier|*
name|lastfree
decl_stmt|;
comment|/* any free position is before this position */
name|struct
name|Table
modifier|*
name|metatable
decl_stmt|;
name|GCObject
modifier|*
name|gclist
decl_stmt|;
block|}
name|Table
typedef|;
end_typedef

begin_comment
comment|/* ** `module' operation for hashing (size is always a power of 2) */
end_comment

begin_define
define|#
directive|define
name|lmod
parameter_list|(
name|s
parameter_list|,
name|size
parameter_list|)
define|\
value|(check_exp((size&(size-1))==0, (cast(int, (s)& ((size)-1)))))
end_define

begin_define
define|#
directive|define
name|twoto
parameter_list|(
name|x
parameter_list|)
value|(1<<(x))
end_define

begin_define
define|#
directive|define
name|sizenode
parameter_list|(
name|t
parameter_list|)
value|(twoto((t)->lsizenode))
end_define

begin_comment
comment|/* ** (address of) a fixed nil value */
end_comment

begin_define
define|#
directive|define
name|luaO_nilobject
value|(&luaO_nilobject_)
end_define

begin_decl_stmt
name|LUAI_DDEC
specifier|const
name|TValue
name|luaO_nilobject_
decl_stmt|;
end_decl_stmt

begin_function_decl
name|LUAI_FUNC
name|int
name|luaO_int2fb
parameter_list|(
name|unsigned
name|int
name|x
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|LUAI_FUNC
name|int
name|luaO_fb2int
parameter_list|(
name|int
name|x
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|LUAI_FUNC
name|int
name|luaO_ceillog2
parameter_list|(
name|unsigned
name|int
name|x
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|LUAI_FUNC
name|lua_Number
name|luaO_arith
parameter_list|(
name|int
name|op
parameter_list|,
name|lua_Number
name|v1
parameter_list|,
name|lua_Number
name|v2
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|LUAI_FUNC
name|int
name|luaO_str2d
parameter_list|(
specifier|const
name|char
modifier|*
name|s
parameter_list|,
name|size_t
name|len
parameter_list|,
name|lua_Number
modifier|*
name|result
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|LUAI_FUNC
name|int
name|luaO_hexavalue
parameter_list|(
name|int
name|c
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|LUAI_FUNC
specifier|const
name|char
modifier|*
name|luaO_pushvfstring
parameter_list|(
name|lua_State
modifier|*
name|L
parameter_list|,
specifier|const
name|char
modifier|*
name|fmt
parameter_list|,
name|va_list
name|argp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|LUAI_FUNC
specifier|const
name|char
modifier|*
name|luaO_pushfstring
parameter_list|(
name|lua_State
modifier|*
name|L
parameter_list|,
specifier|const
name|char
modifier|*
name|fmt
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|LUAI_FUNC
name|void
name|luaO_chunkid
parameter_list|(
name|char
modifier|*
name|out
parameter_list|,
specifier|const
name|char
modifier|*
name|source
parameter_list|,
name|size_t
name|len
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

end_unit

