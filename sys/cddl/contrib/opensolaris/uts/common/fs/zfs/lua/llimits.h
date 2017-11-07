begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* ** $Id: llimits.h,v 1.103.1.1 2013/04/12 18:48:47 roberto Exp $ ** Limits, basic types, and some other `installation-dependent' definitions ** See Copyright Notice in lua.h */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|llimits_h
end_ifndef

begin_define
define|#
directive|define
name|llimits_h
end_define

begin_include
include|#
directive|include
file|<sys/zfs_context.h>
end_include

begin_include
include|#
directive|include
file|"lua.h"
end_include

begin_typedef
typedef|typedef
name|unsigned
name|LUA_INT32
name|lu_int32
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|LUAI_UMEM
name|lu_mem
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|LUAI_MEM
name|l_mem
typedef|;
end_typedef

begin_comment
comment|/* chars used as small naturals (so that `char' is reserved for characters) */
end_comment

begin_typedef
typedef|typedef
name|unsigned
name|char
name|lu_byte
typedef|;
end_typedef

begin_define
define|#
directive|define
name|MAX_SIZET
value|((size_t)(~(size_t)0)-2)
end_define

begin_define
define|#
directive|define
name|MAX_LUMEM
value|((lu_mem)(~(lu_mem)0)-2)
end_define

begin_define
define|#
directive|define
name|MAX_LMEM
value|((l_mem) ((MAX_LUMEM>> 1) - 2))
end_define

begin_define
define|#
directive|define
name|MAX_INT
value|(INT_MAX-2)
end_define

begin_comment
comment|/* maximum value of an int (-2 for safety) */
end_comment

begin_comment
comment|/* ** conversion of pointer to integer ** this is for hashing only; there is no problem if the integer ** cannot hold the whole pointer value */
end_comment

begin_define
define|#
directive|define
name|IntPoint
parameter_list|(
name|p
parameter_list|)
value|((unsigned int)(lu_mem)(p))
end_define

begin_comment
comment|/* type to ensure maximum alignment */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|LUAI_USER_ALIGNMENT_T
argument_list|)
end_if

begin_define
define|#
directive|define
name|LUAI_USER_ALIGNMENT_T
value|union { double u; void *s; long l; }
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
name|LUAI_USER_ALIGNMENT_T
name|L_Umaxalign
typedef|;
end_typedef

begin_comment
comment|/* result of a `usual argument conversion' over lua_Number */
end_comment

begin_typedef
typedef|typedef
name|LUAI_UACNUMBER
name|l_uacNumber
typedef|;
end_typedef

begin_comment
comment|/* internal assertions for in-house debugging */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|lua_assert
argument_list|)
end_if

begin_define
define|#
directive|define
name|check_exp
parameter_list|(
name|c
parameter_list|,
name|e
parameter_list|)
value|(lua_assert(c), (e))
end_define

begin_comment
comment|/* to avoid problems with conditions too long */
end_comment

begin_define
define|#
directive|define
name|lua_longassert
parameter_list|(
name|c
parameter_list|)
value|{ if (!(c)) lua_assert(0); }
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|lua_assert
parameter_list|(
name|c
parameter_list|)
value|((void)0)
end_define

begin_define
define|#
directive|define
name|check_exp
parameter_list|(
name|c
parameter_list|,
name|e
parameter_list|)
value|(e)
end_define

begin_define
define|#
directive|define
name|lua_longassert
parameter_list|(
name|c
parameter_list|)
value|((void)0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ** assertion for checking API calls */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|luai_apicheck
argument_list|)
end_if

begin_if
if|#
directive|if
name|defined
argument_list|(
name|LUA_USE_APICHECK
argument_list|)
end_if

begin_include
include|#
directive|include
file|<assert.h>
end_include

begin_define
define|#
directive|define
name|luai_apicheck
parameter_list|(
name|L
parameter_list|,
name|e
parameter_list|)
value|assert(e)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|luai_apicheck
parameter_list|(
name|L
parameter_list|,
name|e
parameter_list|)
value|lua_assert(e)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|api_check
parameter_list|(
name|l
parameter_list|,
name|e
parameter_list|,
name|msg
parameter_list|)
value|luai_apicheck(l,(e)&& msg)
end_define

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|UNUSED
argument_list|)
end_if

begin_define
define|#
directive|define
name|UNUSED
parameter_list|(
name|x
parameter_list|)
value|((void)(x))
end_define

begin_comment
comment|/* to avoid warnings */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|cast
parameter_list|(
name|t
parameter_list|,
name|exp
parameter_list|)
value|((t)(exp))
end_define

begin_define
define|#
directive|define
name|cast_byte
parameter_list|(
name|i
parameter_list|)
value|cast(lu_byte, (i))
end_define

begin_define
define|#
directive|define
name|cast_num
parameter_list|(
name|i
parameter_list|)
value|cast(lua_Number, (i))
end_define

begin_define
define|#
directive|define
name|cast_int
parameter_list|(
name|i
parameter_list|)
value|cast(int, (i))
end_define

begin_define
define|#
directive|define
name|cast_uchar
parameter_list|(
name|i
parameter_list|)
value|cast(unsigned char, (i))
end_define

begin_comment
comment|/* ** non-return type */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__GNUC__
argument_list|)
end_if

begin_define
define|#
directive|define
name|l_noret
value|void __attribute__((noreturn))
end_define

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|_MSC_VER
argument_list|)
end_elif

begin_define
define|#
directive|define
name|l_noret
value|void __declspec(noreturn)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|l_noret
value|void
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ** maximum depth for nested C calls and syntactical nested non-terminals ** in a program. (Value must fit in an unsigned short int.) ** ** Note: On amd64 platform, the limit has been measured to be 45.  We set ** the maximum lower to give a margin for changing the amount of stack ** used by various functions involved in parsing and executing code. */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|LUAI_MAXCCALLS
argument_list|)
end_if

begin_define
define|#
directive|define
name|LUAI_MAXCCALLS
value|20
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ** maximum number of upvalues in a closure (both C and Lua). (Value ** must fit in an unsigned char.) */
end_comment

begin_define
define|#
directive|define
name|MAXUPVAL
value|UCHAR_MAX
end_define

begin_comment
comment|/* ** type for virtual-machine instructions ** must be an unsigned with (at least) 4 bytes (see details in lopcodes.h) */
end_comment

begin_typedef
typedef|typedef
name|lu_int32
name|Instruction
typedef|;
end_typedef

begin_comment
comment|/* maximum stack for a Lua function */
end_comment

begin_define
define|#
directive|define
name|MAXSTACK
value|250
end_define

begin_comment
comment|/* minimum size for the string table (must be power of 2) */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|MINSTRTABSIZE
argument_list|)
end_if

begin_define
define|#
directive|define
name|MINSTRTABSIZE
value|32
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* minimum size for string buffer */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|LUA_MINBUFFER
argument_list|)
end_if

begin_define
define|#
directive|define
name|LUA_MINBUFFER
value|32
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|lua_lock
argument_list|)
end_if

begin_define
define|#
directive|define
name|lua_lock
parameter_list|(
name|L
parameter_list|)
value|((void) 0)
end_define

begin_define
define|#
directive|define
name|lua_unlock
parameter_list|(
name|L
parameter_list|)
value|((void) 0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|luai_threadyield
argument_list|)
end_if

begin_define
define|#
directive|define
name|luai_threadyield
parameter_list|(
name|L
parameter_list|)
value|{lua_unlock(L); lua_lock(L);}
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ** these macros allow user-specific actions on threads when you defined ** LUAI_EXTRASPACE and need to do something extra when a thread is ** created/deleted/resumed/yielded. */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|luai_userstateopen
argument_list|)
end_if

begin_define
define|#
directive|define
name|luai_userstateopen
parameter_list|(
name|L
parameter_list|)
value|((void)L)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|luai_userstateclose
argument_list|)
end_if

begin_define
define|#
directive|define
name|luai_userstateclose
parameter_list|(
name|L
parameter_list|)
value|((void)L)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|luai_userstatethread
argument_list|)
end_if

begin_define
define|#
directive|define
name|luai_userstatethread
parameter_list|(
name|L
parameter_list|,
name|L1
parameter_list|)
value|((void)L)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|luai_userstatefree
argument_list|)
end_if

begin_define
define|#
directive|define
name|luai_userstatefree
parameter_list|(
name|L
parameter_list|,
name|L1
parameter_list|)
value|((void)L)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|luai_userstateresume
argument_list|)
end_if

begin_define
define|#
directive|define
name|luai_userstateresume
parameter_list|(
name|L
parameter_list|,
name|n
parameter_list|)
value|((void)L)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|luai_userstateyield
argument_list|)
end_if

begin_define
define|#
directive|define
name|luai_userstateyield
parameter_list|(
name|L
parameter_list|,
name|n
parameter_list|)
value|((void)L)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ** lua_number2int is a macro to convert lua_Number to int. ** lua_number2integer is a macro to convert lua_Number to lua_Integer. ** lua_number2unsigned is a macro to convert a lua_Number to a lua_Unsigned. ** lua_unsigned2number is a macro to convert a lua_Unsigned to a lua_Number. ** luai_hashnum is a macro to hash a lua_Number value into an integer. ** The hash must be deterministic and give reasonable values for ** both small and large values (outside the range of integers). */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|MS_ASMTRICK
argument_list|)
operator|||
name|defined
argument_list|(
name|LUA_MSASMTRICK
argument_list|)
end_if

begin_comment
comment|/* { */
end_comment

begin_comment
comment|/* trick with Microsoft assembler for X86 */
end_comment

begin_define
define|#
directive|define
name|lua_number2int
parameter_list|(
name|i
parameter_list|,
name|n
parameter_list|)
value|__asm {__asm fld n   __asm fistp i}
end_define

begin_define
define|#
directive|define
name|lua_number2integer
parameter_list|(
name|i
parameter_list|,
name|n
parameter_list|)
value|lua_number2int(i, n)
end_define

begin_define
define|#
directive|define
name|lua_number2unsigned
parameter_list|(
name|i
parameter_list|,
name|n
parameter_list|)
define|\
value|{__int64 l; __asm {__asm fld n   __asm fistp l} i = (unsigned int)l;}
end_define

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|LUA_IEEE754TRICK
argument_list|)
end_elif

begin_comment
comment|/* }{ */
end_comment

begin_comment
comment|/* the next trick should work on any machine using IEEE754 with    a 32-bit int type */
end_comment

begin_union
union|union
name|luai_Cast
block|{
name|double
name|l_d
decl_stmt|;
name|LUA_INT32
name|l_p
index|[
literal|2
index|]
decl_stmt|;
block|}
union|;
end_union

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|LUA_IEEEENDIAN
argument_list|)
end_if

begin_comment
comment|/* { */
end_comment

begin_define
define|#
directive|define
name|LUAI_EXTRAIEEE
define|\
value|static const union luai_Cast ieeeendian = {-(33.0 + 6755399441055744.0)};
end_define

begin_define
define|#
directive|define
name|LUA_IEEEENDIANLOC
value|(ieeeendian.l_p[1] == 33)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|LUA_IEEEENDIANLOC
value|LUA_IEEEENDIAN
end_define

begin_define
define|#
directive|define
name|LUAI_EXTRAIEEE
end_define

begin_comment
comment|/* empty */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* } */
end_comment

begin_define
define|#
directive|define
name|lua_number2int32
parameter_list|(
name|i
parameter_list|,
name|n
parameter_list|,
name|t
parameter_list|)
define|\
value|{ LUAI_EXTRAIEEE \     volatile union luai_Cast u; u.l_d = (n) + 6755399441055744.0; \     (i) = (t)u.l_p[LUA_IEEEENDIANLOC]; }
end_define

begin_define
define|#
directive|define
name|luai_hashnum
parameter_list|(
name|i
parameter_list|,
name|n
parameter_list|)
define|\
value|{ volatile union luai_Cast u; u.l_d = (n) + 1.0;
comment|/* avoid -0 */
value|\     (i) = u.l_p[0]; (i) += u.l_p[1]; }
end_define

begin_comment
comment|/* add double bits for his hash */
end_comment

begin_define
define|#
directive|define
name|lua_number2int
parameter_list|(
name|i
parameter_list|,
name|n
parameter_list|)
value|lua_number2int32(i, n, int)
end_define

begin_define
define|#
directive|define
name|lua_number2unsigned
parameter_list|(
name|i
parameter_list|,
name|n
parameter_list|)
value|lua_number2int32(i, n, lua_Unsigned)
end_define

begin_comment
comment|/* the trick can be expanded to lua_Integer when it is a 32-bit value */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|LUA_IEEELL
argument_list|)
end_if

begin_define
define|#
directive|define
name|lua_number2integer
parameter_list|(
name|i
parameter_list|,
name|n
parameter_list|)
value|lua_number2int32(i, n, lua_Integer)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* } */
end_comment

begin_comment
comment|/* the following definitions always work, but may be slow */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|lua_number2int
argument_list|)
end_if

begin_define
define|#
directive|define
name|lua_number2int
parameter_list|(
name|i
parameter_list|,
name|n
parameter_list|)
value|((i)=(int)(n))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|lua_number2integer
argument_list|)
end_if

begin_define
define|#
directive|define
name|lua_number2integer
parameter_list|(
name|i
parameter_list|,
name|n
parameter_list|)
value|((i)=(lua_Integer)(n))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|lua_number2unsigned
argument_list|)
end_if

begin_comment
comment|/* { */
end_comment

begin_comment
comment|/* the following definition assures proper modulo behavior */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|LUA_NUMBER_DOUBLE
argument_list|)
operator|||
name|defined
argument_list|(
name|LUA_NUMBER_FLOAT
argument_list|)
end_if

begin_include
include|#
directive|include
file|<math.h>
end_include

begin_define
define|#
directive|define
name|SUPUNSIGNED
value|((lua_Number)(~(lua_Unsigned)0) + 1)
end_define

begin_define
define|#
directive|define
name|lua_number2unsigned
parameter_list|(
name|i
parameter_list|,
name|n
parameter_list|)
define|\
value|((i)=(lua_Unsigned)((n) - floor((n)/SUPUNSIGNED)*SUPUNSIGNED))
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|lua_number2unsigned
parameter_list|(
name|i
parameter_list|,
name|n
parameter_list|)
value|((i)=(lua_Unsigned)(n))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* } */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|lua_unsigned2number
argument_list|)
end_if

begin_comment
comment|/* on several machines, coercion from unsigned to double is slow,    so it may be worth to avoid */
end_comment

begin_define
define|#
directive|define
name|lua_unsigned2number
parameter_list|(
name|u
parameter_list|)
define|\
value|(((u)<= (lua_Unsigned)INT_MAX) ? (lua_Number)(int)(u) : (lua_Number)(u))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|ltable_c
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|luai_hashnum
argument_list|)
end_if

begin_function_decl
specifier|extern
name|int
name|lcompat_hashnum
parameter_list|(
name|int64_t
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|luai_hashnum
parameter_list|(
name|i
parameter_list|,
name|n
parameter_list|)
value|(i = lcompat_hashnum(n))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ** macro to control inclusion of some hard tests on stack reallocation */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|HARDSTACKTESTS
argument_list|)
end_if

begin_define
define|#
directive|define
name|condmovestack
parameter_list|(
name|L
parameter_list|)
value|((void)0)
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* realloc stack keeping its size */
end_comment

begin_define
define|#
directive|define
name|condmovestack
parameter_list|(
name|L
parameter_list|)
value|luaD_reallocstack((L), (L)->stacksize)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|HARDMEMTESTS
argument_list|)
end_if

begin_define
define|#
directive|define
name|condchangemem
parameter_list|(
name|L
parameter_list|)
value|condmovestack(L)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|condchangemem
parameter_list|(
name|L
parameter_list|)
define|\
value|((void)(!(G(L)->gcrunning) || (luaC_fullgc(L, 0), 1)))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

end_unit

