begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* mp.h -- Definitions for Berkeley compatible multiple precision functions.  Copyright (C) 1991, 1993, 1994, 1995, 1996 Free Software Foundation, Inc.  This file is part of the GNU MP Library.  The GNU MP Library is free software; you can redistribute it and/or modify it under the terms of the GNU Library General Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version.  The GNU MP Library is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU Library General Public License for more details.  You should have received a copy of the GNU Library General Public License along with the GNU MP Library; see the file COPYING.LIB.  If not, write to the Free Software Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA. */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__MP_H__
end_ifndef

begin_ifndef
ifndef|#
directive|ifndef
name|__GNU_MP__
end_ifndef

begin_define
define|#
directive|define
name|__GNU_MP__
value|2
end_define

begin_define
define|#
directive|define
name|__need_size_t
end_define

begin_include
include|#
directive|include
file|<stddef.h>
end_include

begin_undef
undef|#
directive|undef
name|__need_size_t
end_undef

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__STDC__
argument_list|)
operator|||
name|defined
argument_list|(
name|__cplusplus
argument_list|)
end_if

begin_define
define|#
directive|define
name|__gmp_const
value|const
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|__gmp_const
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
name|__GNUC__
argument_list|)
end_if

begin_define
define|#
directive|define
name|__gmp_inline
value|__inline__
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|__gmp_inline
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|_EXTERN_INLINE
end_ifndef

begin_ifdef
ifdef|#
directive|ifdef
name|__GNUC__
end_ifdef

begin_define
define|#
directive|define
name|_EXTERN_INLINE
value|extern __inline__
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|_EXTERN_INLINE
value|static
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|_SHORT_LIMB
end_ifdef

begin_typedef
typedef|typedef
name|unsigned
name|int
name|mp_limb_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|int
name|mp_limb_signed_t
typedef|;
end_typedef

begin_else
else|#
directive|else
end_else

begin_ifdef
ifdef|#
directive|ifdef
name|_LONG_LONG_LIMB
end_ifdef

begin_typedef
typedef|typedef
name|unsigned
name|long
name|long
name|int
name|mp_limb_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|long
name|long
name|int
name|mp_limb_signed_t
typedef|;
end_typedef

begin_else
else|#
directive|else
end_else

begin_typedef
typedef|typedef
name|unsigned
name|long
name|int
name|mp_limb_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|long
name|int
name|mp_limb_signed_t
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
name|mp_limb_t
modifier|*
name|mp_ptr
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|__gmp_const
name|mp_limb_t
modifier|*
name|mp_srcptr
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|int
name|mp_size_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|long
name|int
name|mp_exp_t
typedef|;
end_typedef

begin_ifndef
ifndef|#
directive|ifndef
name|__MP_SMALL__
end_ifndef

begin_typedef
typedef|typedef
struct|struct
block|{
name|mp_size_t
name|_mp_alloc
decl_stmt|;
comment|/* Number of *limbs* allocated and pointed 				   to by the D field.  */
name|mp_size_t
name|_mp_size
decl_stmt|;
comment|/* abs(SIZE) is the number of limbs 				   the last field points to.  If SIZE 				   is negative this is a negative 				   number.  */
name|mp_limb_t
modifier|*
name|_mp_d
decl_stmt|;
comment|/* Pointer to the limbs.  */
block|}
name|__mpz_struct
typedef|;
end_typedef

begin_else
else|#
directive|else
end_else

begin_typedef
typedef|typedef
struct|struct
block|{
name|short
name|int
name|_mp_alloc
decl_stmt|;
comment|/* Number of *limbs* allocated and pointed 				   to by the D field.  */
name|short
name|int
name|_mp_size
decl_stmt|;
comment|/* abs(SIZE) is the number of limbs 				   the last field points to.  If SIZE 				   is negative this is a negative 				   number.  */
name|mp_limb_t
modifier|*
name|_mp_d
decl_stmt|;
comment|/* Pointer to the limbs.  */
block|}
name|__mpz_struct
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __GNU_MP__ */
end_comment

begin_comment
comment|/* User-visible types.  */
end_comment

begin_typedef
typedef|typedef
name|__mpz_struct
name|MINT
typedef|;
end_typedef

begin_ifdef
ifdef|#
directive|ifdef
name|__STDC__
end_ifdef

begin_function_decl
name|void
name|mp_set_memory_functions
parameter_list|(
name|void
modifier|*
function_decl|(
modifier|*
function_decl|)
parameter_list|(
name|size_t
parameter_list|)
parameter_list|,
name|void
modifier|*
function_decl|(
modifier|*
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|,
name|size_t
parameter_list|,
name|size_t
parameter_list|)
parameter_list|,
name|void
function_decl|(
modifier|*
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|,
name|size_t
parameter_list|)
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|MINT
modifier|*
name|itom
parameter_list|(
name|signed
name|short
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|MINT
modifier|*
name|xtom
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|move
parameter_list|(
specifier|const
name|MINT
modifier|*
parameter_list|,
name|MINT
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|madd
parameter_list|(
specifier|const
name|MINT
modifier|*
parameter_list|,
specifier|const
name|MINT
modifier|*
parameter_list|,
name|MINT
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|msub
parameter_list|(
specifier|const
name|MINT
modifier|*
parameter_list|,
specifier|const
name|MINT
modifier|*
parameter_list|,
name|MINT
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|mult
parameter_list|(
specifier|const
name|MINT
modifier|*
parameter_list|,
specifier|const
name|MINT
modifier|*
parameter_list|,
name|MINT
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|mdiv
parameter_list|(
specifier|const
name|MINT
modifier|*
parameter_list|,
specifier|const
name|MINT
modifier|*
parameter_list|,
name|MINT
modifier|*
parameter_list|,
name|MINT
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|sdiv
parameter_list|(
specifier|const
name|MINT
modifier|*
parameter_list|,
name|signed
name|short
name|int
parameter_list|,
name|MINT
modifier|*
parameter_list|,
name|signed
name|short
name|int
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|msqrt
parameter_list|(
specifier|const
name|MINT
modifier|*
parameter_list|,
name|MINT
modifier|*
parameter_list|,
name|MINT
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|pow
parameter_list|(
specifier|const
name|MINT
modifier|*
parameter_list|,
specifier|const
name|MINT
modifier|*
parameter_list|,
specifier|const
name|MINT
modifier|*
parameter_list|,
name|MINT
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|rpow
parameter_list|(
specifier|const
name|MINT
modifier|*
parameter_list|,
name|signed
name|short
name|int
parameter_list|,
name|MINT
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|gcd
parameter_list|(
specifier|const
name|MINT
modifier|*
parameter_list|,
specifier|const
name|MINT
modifier|*
parameter_list|,
name|MINT
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|mcmp
parameter_list|(
specifier|const
name|MINT
modifier|*
parameter_list|,
specifier|const
name|MINT
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|min
parameter_list|(
name|MINT
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|mout
parameter_list|(
specifier|const
name|MINT
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|mtox
parameter_list|(
specifier|const
name|MINT
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|mfree
parameter_list|(
name|MINT
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_else
else|#
directive|else
end_else

begin_function_decl
name|void
name|mp_set_memory_functions
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|MINT
modifier|*
name|itom
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|MINT
modifier|*
name|xtom
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|move
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|madd
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|msub
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|mult
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|mdiv
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|sdiv
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|msqrt
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|pow
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|rpow
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|gcd
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|mcmp
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|min
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|mout
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|mtox
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|mfree
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|__MP_H__
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __MP_H__ */
end_comment

end_unit

