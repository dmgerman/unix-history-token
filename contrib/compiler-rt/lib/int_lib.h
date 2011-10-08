begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* ===-- int_lib.h - configuration header for compiler-rt  -----------------===  *  *                     The LLVM Compiler Infrastructure  *  * This file is dual licensed under the MIT and the University of Illinois Open  * Source Licenses. See LICENSE.TXT for details.  *  * ===----------------------------------------------------------------------===  *  * This file is a configuration header for compiler-rt.  * This file is not part of the interface of this library.  *  * ===----------------------------------------------------------------------===  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|INT_LIB_H
end_ifndef

begin_define
define|#
directive|define
name|INT_LIB_H
end_define

begin_comment
comment|/* Assumption:  signed integral is 2's complement */
end_comment

begin_comment
comment|/* Assumption:  right shift of signed negative is arithmetic shift */
end_comment

begin_include
include|#
directive|include
file|<limits.h>
end_include

begin_include
include|#
directive|include
file|<stdint.h>
end_include

begin_include
include|#
directive|include
file|"endianness.h"
end_include

begin_include
include|#
directive|include
file|<math.h>
end_include

begin_comment
comment|/* If compiling for kernel use, call panic() instead of abort(). */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|KERNEL_USE
end_ifdef

begin_function_decl
specifier|extern
name|void
name|panic
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|compilerrt_abort
parameter_list|()
define|\
value|panic("%s:%d: abort in %s", __FILE__, __LINE__, __FUNCTION__)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|compilerrt_abort
parameter_list|()
value|abort()
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
name|INFINITY
argument_list|)
operator|&&
name|defined
argument_list|(
name|HUGE_VAL
argument_list|)
end_if

begin_define
define|#
directive|define
name|INFINITY
value|HUGE_VAL
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* INFINITY */
end_comment

begin_typedef
typedef|typedef
name|int
name|si_int
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|su_int
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|long
name|long
name|di_int
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|long
name|long
name|du_int
typedef|;
end_typedef

begin_typedef
typedef|typedef
union|union
block|{
name|di_int
name|all
decl_stmt|;
struct|struct
block|{
if|#
directive|if
name|_YUGA_LITTLE_ENDIAN
name|su_int
name|low
decl_stmt|;
name|si_int
name|high
decl_stmt|;
else|#
directive|else
name|si_int
name|high
decl_stmt|;
name|su_int
name|low
decl_stmt|;
endif|#
directive|endif
comment|/* _YUGA_LITTLE_ENDIAN */
block|}
name|s
struct|;
block|}
name|dwords
typedef|;
end_typedef

begin_typedef
typedef|typedef
union|union
block|{
name|du_int
name|all
decl_stmt|;
struct|struct
block|{
if|#
directive|if
name|_YUGA_LITTLE_ENDIAN
name|su_int
name|low
decl_stmt|;
name|su_int
name|high
decl_stmt|;
else|#
directive|else
name|su_int
name|high
decl_stmt|;
name|su_int
name|low
decl_stmt|;
endif|#
directive|endif
comment|/* _YUGA_LITTLE_ENDIAN */
block|}
name|s
struct|;
block|}
name|udwords
typedef|;
end_typedef

begin_if
if|#
directive|if
name|__x86_64
end_if

begin_typedef
typedef|typedef
name|int
name|ti_int
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
name|tu_int
name|__attribute__
typedef|((
name|mode
typedef|(
name|TI
typedef|)));
end_typedef

begin_typedef
typedef|typedef
union|union
block|{
name|ti_int
name|all
decl_stmt|;
struct|struct
block|{
if|#
directive|if
name|_YUGA_LITTLE_ENDIAN
name|du_int
name|low
decl_stmt|;
name|di_int
name|high
decl_stmt|;
else|#
directive|else
name|di_int
name|high
decl_stmt|;
name|du_int
name|low
decl_stmt|;
endif|#
directive|endif
comment|/* _YUGA_LITTLE_ENDIAN */
block|}
name|s
struct|;
block|}
name|twords
typedef|;
end_typedef

begin_typedef
typedef|typedef
union|union
block|{
name|tu_int
name|all
decl_stmt|;
struct|struct
block|{
if|#
directive|if
name|_YUGA_LITTLE_ENDIAN
name|du_int
name|low
decl_stmt|;
name|du_int
name|high
decl_stmt|;
else|#
directive|else
name|du_int
name|high
decl_stmt|;
name|du_int
name|low
decl_stmt|;
endif|#
directive|endif
comment|/* _YUGA_LITTLE_ENDIAN */
block|}
name|s
struct|;
block|}
name|utwords
typedef|;
end_typedef

begin_function
specifier|static
specifier|inline
name|ti_int
name|make_ti
parameter_list|(
name|di_int
name|h
parameter_list|,
name|di_int
name|l
parameter_list|)
block|{
name|twords
name|r
decl_stmt|;
name|r
operator|.
name|s
operator|.
name|high
operator|=
name|h
expr_stmt|;
name|r
operator|.
name|s
operator|.
name|low
operator|=
name|l
expr_stmt|;
return|return
name|r
operator|.
name|all
return|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|tu_int
name|make_tu
parameter_list|(
name|du_int
name|h
parameter_list|,
name|du_int
name|l
parameter_list|)
block|{
name|utwords
name|r
decl_stmt|;
name|r
operator|.
name|s
operator|.
name|high
operator|=
name|h
expr_stmt|;
name|r
operator|.
name|s
operator|.
name|low
operator|=
name|l
expr_stmt|;
return|return
name|r
operator|.
name|all
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __x86_64 */
end_comment

begin_typedef
typedef|typedef
union|union
block|{
name|su_int
name|u
decl_stmt|;
name|float
name|f
decl_stmt|;
block|}
name|float_bits
typedef|;
end_typedef

begin_typedef
typedef|typedef
union|union
block|{
name|udwords
name|u
decl_stmt|;
name|double
name|f
decl_stmt|;
block|}
name|double_bits
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
if|#
directive|if
name|_YUGA_LITTLE_ENDIAN
name|udwords
name|low
decl_stmt|;
name|udwords
name|high
decl_stmt|;
else|#
directive|else
name|udwords
name|high
decl_stmt|;
name|udwords
name|low
decl_stmt|;
endif|#
directive|endif
comment|/* _YUGA_LITTLE_ENDIAN */
block|}
name|uqwords
typedef|;
end_typedef

begin_typedef
typedef|typedef
union|union
block|{
name|uqwords
name|u
decl_stmt|;
name|long
name|double
name|f
decl_stmt|;
block|}
name|long_double_bits
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* INT_LIB_H */
end_comment

end_unit

