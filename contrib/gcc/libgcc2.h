begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Header file for libgcc2.c.  */
end_comment

begin_comment
comment|/* Copyright (C) 2000, 2001    Free Software Foundation, Inc.  This file is part of GCC.  GCC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GCC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GCC; see the file COPYING.  If not, write to the Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|GCC_LIBGCC2_H
end_ifndef

begin_define
define|#
directive|define
name|GCC_LIBGCC2_H
end_define

begin_function_decl
specifier|extern
name|int
name|__gcc_bcmp
parameter_list|(
specifier|const
name|unsigned
name|char
modifier|*
parameter_list|,
specifier|const
name|unsigned
name|char
modifier|*
parameter_list|,
name|size_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|__clear_cache
parameter_list|(
name|char
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|__eprintf
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|unsigned
name|int
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(__noreturn__
end_function_decl

begin_empty_stmt
unit|))
empty_stmt|;
end_empty_stmt

begin_struct_decl
struct_decl|struct
name|bb
struct_decl|;
end_struct_decl

begin_function_decl
specifier|extern
name|void
name|__bb_exit_func
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|__bb_init_func
parameter_list|(
name|struct
name|bb
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|__bb_fork_func
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|__bb_trace_func
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|__bb_trace_ret
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|__bb_init_trace_func
parameter_list|(
name|struct
name|bb
modifier|*
parameter_list|,
name|unsigned
name|long
parameter_list|)
function_decl|;
end_function_decl

begin_struct_decl
struct_decl|struct
name|exception_descriptor
struct_decl|;
end_struct_decl

begin_function_decl
specifier|extern
name|short
name|int
name|__get_eh_table_language
parameter_list|(
name|struct
name|exception_descriptor
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|short
name|int
name|__get_eh_table_version
parameter_list|(
name|struct
name|exception_descriptor
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Permit the tm.h file to select the endianness to use just for this    file.  This is used when the endianness is determined when the    compiler is run.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|LIBGCC2_WORDS_BIG_ENDIAN
end_ifndef

begin_define
define|#
directive|define
name|LIBGCC2_WORDS_BIG_ENDIAN
value|WORDS_BIG_ENDIAN
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|LIBGCC2_LONG_DOUBLE_TYPE_SIZE
end_ifndef

begin_define
define|#
directive|define
name|LIBGCC2_LONG_DOUBLE_TYPE_SIZE
value|LONG_DOUBLE_TYPE_SIZE
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|MIN_UNITS_PER_WORD
end_ifndef

begin_define
define|#
directive|define
name|MIN_UNITS_PER_WORD
value|UNITS_PER_WORD
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* In the first part of this file, we are interfacing to calls generated    by the compiler itself.  These calls pass values into these routines    which have very specific modes (rather than very specific types), and    these compiler-generated calls also expect any return values to have    very specific modes (rather than very specific types).  Thus, we need    to avoid using regular C language type names in this part of the file    because the sizes for those types can be configured to be anything.    Instead we use the following special type names.  */
end_comment

begin_typedef
typedef|typedef
name|int
name|QItype
name|__attribute__
typedef|((
name|mode
typedef|(
name|QI
typedef|)));
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|int
name|UQItype
name|__attribute__
typedef|((
name|mode
typedef|(
name|QI
typedef|)));
end_typedef

begin_typedef
typedef|typedef
name|int
name|HItype
name|__attribute__
typedef|((
name|mode
typedef|(
name|HI
typedef|)));
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|int
name|UHItype
name|__attribute__
typedef|((
name|mode
typedef|(
name|HI
typedef|)));
end_typedef

begin_if
if|#
directive|if
name|MIN_UNITS_PER_WORD
operator|>
literal|1
end_if

begin_comment
comment|/* These typedefs are usually forbidden on dsp's with UNITS_PER_WORD 1 */
end_comment

begin_typedef
typedef|typedef
name|int
name|SItype
name|__attribute__
typedef|((
name|mode
typedef|(
name|SI
typedef|)));
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|int
name|USItype
name|__attribute__
typedef|((
name|mode
typedef|(
name|SI
typedef|)));
end_typedef

begin_if
if|#
directive|if
name|LONG_LONG_TYPE_SIZE
operator|>
literal|32
end_if

begin_comment
comment|/* These typedefs are usually forbidden on archs with UNITS_PER_WORD 2 */
end_comment

begin_typedef
typedef|typedef
name|int
name|DItype
name|__attribute__
typedef|((
name|mode
typedef|(
name|DI
typedef|)));
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|int
name|UDItype
name|__attribute__
typedef|((
name|mode
typedef|(
name|DI
typedef|)));
end_typedef

begin_if
if|#
directive|if
name|MIN_UNITS_PER_WORD
operator|>
literal|4
end_if

begin_comment
comment|/* These typedefs are usually forbidden on archs with UNITS_PER_WORD 4 */
end_comment

begin_typedef
typedef|typedef
name|int
name|TItype
name|__attribute__
typedef|((
name|mode
typedef|(
name|TI
typedef|)));
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|int
name|UTItype
name|__attribute__
typedef|((
name|mode
typedef|(
name|TI
typedef|)));
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|BITS_PER_UNIT
operator|==
literal|8
end_if

begin_typedef
typedef|typedef
name|float
name|SFtype
name|__attribute__
typedef|((
name|mode
typedef|(
name|SF
typedef|)));
end_typedef

begin_typedef
typedef|typedef
name|float
name|DFtype
name|__attribute__
typedef|((
name|mode
typedef|(
name|DF
typedef|)));
end_typedef

begin_if
if|#
directive|if
name|LIBGCC2_LONG_DOUBLE_TYPE_SIZE
operator|==
literal|96
end_if

begin_typedef
typedef|typedef
name|float
name|XFtype
name|__attribute__
typedef|((
name|mode
typedef|(
name|XF
typedef|)));
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|LIBGCC2_LONG_DOUBLE_TYPE_SIZE
operator|==
literal|128
end_if

begin_typedef
typedef|typedef
name|float
name|TFtype
name|__attribute__
typedef|((
name|mode
typedef|(
name|TF
typedef|)));
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* BITS_PER_UNIT != 8 */
end_comment

begin_comment
comment|/* On dsp's there are usually qf/hf/tqf modes used instead of the above.    For now we don't support them in libgcc2.c.  */
end_comment

begin_undef
undef|#
directive|undef
name|L_fixdfdi
end_undef

begin_undef
undef|#
directive|undef
name|L_fixsfdi
end_undef

begin_undef
undef|#
directive|undef
name|L_fixtfdi
end_undef

begin_undef
undef|#
directive|undef
name|L_fixunsdfdi
end_undef

begin_undef
undef|#
directive|undef
name|L_fixunsdfsi
end_undef

begin_undef
undef|#
directive|undef
name|L_fixunssfdi
end_undef

begin_undef
undef|#
directive|undef
name|L_fixunssfsi
end_undef

begin_undef
undef|#
directive|undef
name|L_fixunstfdi
end_undef

begin_undef
undef|#
directive|undef
name|L_fixunsxfdi
end_undef

begin_undef
undef|#
directive|undef
name|L_fixunsxfsi
end_undef

begin_undef
undef|#
directive|undef
name|L_fixxfdi
end_undef

begin_undef
undef|#
directive|undef
name|L_floatdidf
end_undef

begin_undef
undef|#
directive|undef
name|L_floatdisf
end_undef

begin_undef
undef|#
directive|undef
name|L_floatditf
end_undef

begin_undef
undef|#
directive|undef
name|L_floatdixf
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* BITS_PER_UNIT != 8 */
end_comment

begin_typedef
typedef|typedef
name|int
name|word_type
name|__attribute__
typedef|((
name|mode
typedef|(
name|__word__
typedef|)));
end_typedef

begin_comment
comment|/* Make sure that we don't accidentally use any normal C language built-in    type names in the first part of this file.  Instead we want to use *only*    the type names defined above.  The following macro definitions insure    that if we *do* accidentally use some normal C language built-in type name,    we will get a syntax error.  */
end_comment

begin_define
define|#
directive|define
name|char
value|bogus_type
end_define

begin_define
define|#
directive|define
name|short
value|bogus_type
end_define

begin_define
define|#
directive|define
name|int
value|bogus_type
end_define

begin_define
define|#
directive|define
name|long
value|bogus_type
end_define

begin_define
define|#
directive|define
name|unsigned
value|bogus_type
end_define

begin_define
define|#
directive|define
name|float
value|bogus_type
end_define

begin_define
define|#
directive|define
name|double
value|bogus_type
end_define

begin_if
if|#
directive|if
name|MIN_UNITS_PER_WORD
operator|>
literal|4
end_if

begin_define
define|#
directive|define
name|W_TYPE_SIZE
value|(8 * BITS_PER_UNIT)
end_define

begin_define
define|#
directive|define
name|Wtype
value|DItype
end_define

begin_define
define|#
directive|define
name|UWtype
value|UDItype
end_define

begin_define
define|#
directive|define
name|HWtype
value|DItype
end_define

begin_define
define|#
directive|define
name|UHWtype
value|UDItype
end_define

begin_define
define|#
directive|define
name|DWtype
value|TItype
end_define

begin_define
define|#
directive|define
name|UDWtype
value|UTItype
end_define

begin_define
define|#
directive|define
name|__NW
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|__ ## a ## di ## b
end_define

begin_define
define|#
directive|define
name|__NDW
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|__ ## a ## ti ## b
end_define

begin_elif
elif|#
directive|elif
name|MIN_UNITS_PER_WORD
operator|>
literal|2
expr|\
operator|||
operator|(
name|MIN_UNITS_PER_WORD
operator|>
literal|1
operator|&&
name|LONG_LONG_TYPE_SIZE
operator|>
literal|32
operator|)
end_elif

begin_define
define|#
directive|define
name|W_TYPE_SIZE
value|(4 * BITS_PER_UNIT)
end_define

begin_define
define|#
directive|define
name|Wtype
value|SItype
end_define

begin_define
define|#
directive|define
name|UWtype
value|USItype
end_define

begin_define
define|#
directive|define
name|HWtype
value|SItype
end_define

begin_define
define|#
directive|define
name|UHWtype
value|USItype
end_define

begin_define
define|#
directive|define
name|DWtype
value|DItype
end_define

begin_define
define|#
directive|define
name|UDWtype
value|UDItype
end_define

begin_define
define|#
directive|define
name|__NW
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|__ ## a ## si ## b
end_define

begin_define
define|#
directive|define
name|__NDW
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|__ ## a ## di ## b
end_define

begin_elif
elif|#
directive|elif
name|MIN_UNITS_PER_WORD
operator|>
literal|1
end_elif

begin_define
define|#
directive|define
name|W_TYPE_SIZE
value|(2 * BITS_PER_UNIT)
end_define

begin_define
define|#
directive|define
name|Wtype
value|HItype
end_define

begin_define
define|#
directive|define
name|UWtype
value|UHItype
end_define

begin_define
define|#
directive|define
name|HWtype
value|HItype
end_define

begin_define
define|#
directive|define
name|UHWtype
value|UHItype
end_define

begin_define
define|#
directive|define
name|DWtype
value|SItype
end_define

begin_define
define|#
directive|define
name|UDWtype
value|USItype
end_define

begin_define
define|#
directive|define
name|__NW
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|__ ## a ## hi ## b
end_define

begin_define
define|#
directive|define
name|__NDW
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|__ ## a ## si ## b
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|W_TYPE_SIZE
value|BITS_PER_UNIT
end_define

begin_define
define|#
directive|define
name|Wtype
value|QItype
end_define

begin_define
define|#
directive|define
name|UWtype
value|UQItype
end_define

begin_define
define|#
directive|define
name|HWtype
value|QItype
end_define

begin_define
define|#
directive|define
name|UHWtype
value|UQItype
end_define

begin_define
define|#
directive|define
name|DWtype
value|HItype
end_define

begin_define
define|#
directive|define
name|UDWtype
value|UHItype
end_define

begin_define
define|#
directive|define
name|__NW
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|__ ## a ## qi ## b
end_define

begin_define
define|#
directive|define
name|__NDW
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|__ ## a ## hi ## b
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|Wtype_MAX
value|((Wtype)(((UWtype)1<< (W_TYPE_SIZE - 1)) - 1))
end_define

begin_define
define|#
directive|define
name|Wtype_MIN
value|(- Wtype_MAX - 1)
end_define

begin_define
define|#
directive|define
name|__muldi3
value|__NDW(mul,3)
end_define

begin_define
define|#
directive|define
name|__divdi3
value|__NDW(div,3)
end_define

begin_define
define|#
directive|define
name|__udivdi3
value|__NDW(udiv,3)
end_define

begin_define
define|#
directive|define
name|__moddi3
value|__NDW(mod,3)
end_define

begin_define
define|#
directive|define
name|__umoddi3
value|__NDW(umod,3)
end_define

begin_define
define|#
directive|define
name|__negdi2
value|__NDW(neg,2)
end_define

begin_define
define|#
directive|define
name|__lshrdi3
value|__NDW(lshr,3)
end_define

begin_define
define|#
directive|define
name|__ashldi3
value|__NDW(ashl,3)
end_define

begin_define
define|#
directive|define
name|__ashrdi3
value|__NDW(ashr,3)
end_define

begin_define
define|#
directive|define
name|__ffsdi2
value|__NDW(ffs,2)
end_define

begin_define
define|#
directive|define
name|__cmpdi2
value|__NDW(cmp,2)
end_define

begin_define
define|#
directive|define
name|__ucmpdi2
value|__NDW(ucmp,2)
end_define

begin_define
define|#
directive|define
name|__udivmoddi4
value|__NDW(udivmod,4)
end_define

begin_define
define|#
directive|define
name|__fixunstfDI
value|__NDW(fixunstf,)
end_define

begin_define
define|#
directive|define
name|__fixtfdi
value|__NDW(fixtf,)
end_define

begin_define
define|#
directive|define
name|__fixunsxfDI
value|__NDW(fixunsxf,)
end_define

begin_define
define|#
directive|define
name|__fixxfdi
value|__NDW(fixxf,)
end_define

begin_define
define|#
directive|define
name|__fixunsdfDI
value|__NDW(fixunsdf,)
end_define

begin_define
define|#
directive|define
name|__fixdfdi
value|__NDW(fixdf,)
end_define

begin_define
define|#
directive|define
name|__fixunssfDI
value|__NDW(fixunssf,)
end_define

begin_define
define|#
directive|define
name|__fixsfdi
value|__NDW(fixsf,)
end_define

begin_define
define|#
directive|define
name|__floatdixf
value|__NDW(float,xf)
end_define

begin_define
define|#
directive|define
name|__floatditf
value|__NDW(float,tf)
end_define

begin_define
define|#
directive|define
name|__floatdidf
value|__NDW(float,df)
end_define

begin_define
define|#
directive|define
name|__floatdisf
value|__NDW(float,sf)
end_define

begin_define
define|#
directive|define
name|__fixunsxfSI
value|__NW(fixunsxf,)
end_define

begin_define
define|#
directive|define
name|__fixunstfSI
value|__NW(fixunstf,)
end_define

begin_define
define|#
directive|define
name|__fixunsdfSI
value|__NW(fixunsdf,)
end_define

begin_define
define|#
directive|define
name|__fixunssfSI
value|__NW(fixunssf,)
end_define

begin_function_decl
specifier|extern
name|DWtype
name|__muldi3
parameter_list|(
name|DWtype
parameter_list|,
name|DWtype
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|DWtype
name|__divdi3
parameter_list|(
name|DWtype
parameter_list|,
name|DWtype
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|UDWtype
name|__udivdi3
parameter_list|(
name|UDWtype
parameter_list|,
name|UDWtype
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|UDWtype
name|__umoddi3
parameter_list|(
name|UDWtype
parameter_list|,
name|UDWtype
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|DWtype
name|__moddi3
parameter_list|(
name|DWtype
parameter_list|,
name|DWtype
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* __udivmoddi4 is static inline when building other libgcc2 portions.  */
end_comment

begin_if
if|#
directive|if
operator|(
operator|!
name|defined
argument_list|(
name|L_udivdi3
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|L_divdi3
argument_list|)
operator|&&
expr|\
operator|!
name|defined
argument_list|(
name|L_umoddi3
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|L_moddi3
argument_list|)
operator|)
end_if

begin_function_decl
specifier|extern
name|UDWtype
name|__udivmoddi4
parameter_list|(
name|UDWtype
parameter_list|,
name|UDWtype
parameter_list|,
name|UDWtype
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __negdi2 is static inline when building other libgcc2 portions.  */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|L_divdi3
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|L_moddi3
argument_list|)
end_if

begin_function_decl
specifier|extern
name|DWtype
name|__negdi2
parameter_list|(
name|DWtype
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
specifier|extern
name|DWtype
name|__lshrdi3
parameter_list|(
name|DWtype
parameter_list|,
name|word_type
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|DWtype
name|__ashldi3
parameter_list|(
name|DWtype
parameter_list|,
name|word_type
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|DWtype
name|__ashrdi3
parameter_list|(
name|DWtype
parameter_list|,
name|word_type
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|DWtype
name|__ffsdi2
parameter_list|(
name|DWtype
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* __udiv_w_sdiv is static inline when building other libgcc2 portions.  */
end_comment

begin_if
if|#
directive|if
operator|(
operator|!
name|defined
argument_list|(
name|L_udivdi3
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|L_divdi3
argument_list|)
operator|&&
expr|\
operator|!
name|defined
argument_list|(
name|L_umoddi3
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|L_moddi3
argument_list|)
operator|)
end_if

begin_function_decl
specifier|extern
name|UWtype
name|__udiv_w_sdiv
parameter_list|(
name|UWtype
modifier|*
parameter_list|,
name|UWtype
parameter_list|,
name|UWtype
parameter_list|,
name|UWtype
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
specifier|extern
name|word_type
name|__cmpdi2
parameter_list|(
name|DWtype
parameter_list|,
name|DWtype
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|word_type
name|__ucmpdi2
parameter_list|(
name|DWtype
parameter_list|,
name|DWtype
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|Wtype
name|__absvsi2
parameter_list|(
name|Wtype
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|DWtype
name|__absvdi2
parameter_list|(
name|DWtype
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|Wtype
name|__addvsi3
parameter_list|(
name|Wtype
parameter_list|,
name|Wtype
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|DWtype
name|__addvdi3
parameter_list|(
name|DWtype
parameter_list|,
name|DWtype
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|Wtype
name|__subvsi3
parameter_list|(
name|Wtype
parameter_list|,
name|Wtype
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|DWtype
name|__subvdi3
parameter_list|(
name|DWtype
parameter_list|,
name|DWtype
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|Wtype
name|__mulvsi3
parameter_list|(
name|Wtype
parameter_list|,
name|Wtype
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|DWtype
name|__mulvdi3
parameter_list|(
name|DWtype
parameter_list|,
name|DWtype
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|Wtype
name|__negvsi2
parameter_list|(
name|Wtype
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|DWtype
name|__negvdi2
parameter_list|(
name|DWtype
parameter_list|)
function_decl|;
end_function_decl

begin_if
if|#
directive|if
name|BITS_PER_UNIT
operator|==
literal|8
end_if

begin_function_decl
specifier|extern
name|DWtype
name|__fixdfdi
parameter_list|(
name|DFtype
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|DWtype
name|__fixsfdi
parameter_list|(
name|SFtype
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|DFtype
name|__floatdidf
parameter_list|(
name|DWtype
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|SFtype
name|__floatdisf
parameter_list|(
name|DWtype
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|UWtype
name|__fixunsdfSI
parameter_list|(
name|DFtype
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|UWtype
name|__fixunssfSI
parameter_list|(
name|SFtype
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|DWtype
name|__fixunsdfDI
parameter_list|(
name|DFtype
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|DWtype
name|__fixunssfDI
parameter_list|(
name|SFtype
parameter_list|)
function_decl|;
end_function_decl

begin_if
if|#
directive|if
name|LIBGCC2_LONG_DOUBLE_TYPE_SIZE
operator|==
literal|96
end_if

begin_function_decl
specifier|extern
name|DWtype
name|__fixxfdi
parameter_list|(
name|XFtype
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|DWtype
name|__fixunsxfDI
parameter_list|(
name|XFtype
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|XFtype
name|__floatdixf
parameter_list|(
name|DWtype
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|UWtype
name|__fixunsxfSI
parameter_list|(
name|XFtype
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|LIBGCC2_LONG_DOUBLE_TYPE_SIZE
operator|==
literal|128
end_if

begin_function_decl
specifier|extern
name|DWtype
name|__fixunstfDI
parameter_list|(
name|TFtype
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|DWtype
name|__fixtfdi
parameter_list|(
name|TFtype
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|TFtype
name|__floatditf
parameter_list|(
name|DWtype
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* BITS_PER_UNIT == 8 */
end_comment

begin_comment
comment|/* DWstructs are pairs of Wtype values in the order determined by    LIBGCC2_WORDS_BIG_ENDIAN.  */
end_comment

begin_if
if|#
directive|if
name|LIBGCC2_WORDS_BIG_ENDIAN
end_if

begin_struct
struct|struct
name|DWstruct
block|{
name|Wtype
name|high
decl_stmt|,
name|low
decl_stmt|;
block|}
struct|;
end_struct

begin_else
else|#
directive|else
end_else

begin_struct
struct|struct
name|DWstruct
block|{
name|Wtype
name|low
decl_stmt|,
name|high
decl_stmt|;
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* We need this union to unpack/pack DImode values, since we don't have    any arithmetic yet.  Incoming DImode parameters are stored into the    `ll' field, and the unpacked result is read from the struct `s'.  */
end_comment

begin_typedef
typedef|typedef
union|union
block|{
name|struct
name|DWstruct
name|s
decl_stmt|;
name|DWtype
name|ll
decl_stmt|;
block|}
name|DWunion
typedef|;
end_typedef

begin_include
include|#
directive|include
file|"longlong.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! GCC_LIBGCC2_H */
end_comment

end_unit

