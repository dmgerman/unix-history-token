begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* mp.h -- Definitions for Berkeley compatible multiple precision functions.  Copyright (C) 1991, 1993 Free Software Foundation, Inc.  This file is part of the GNU MP Library.  The GNU MP Library is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  The GNU MP Library is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with the GNU MP Library; see the file COPYING.  If not, write to the Free Software Foundation, 675 Mass Ave, Cambridge, MA 02139, USA.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__MP_H__
end_ifndef

begin_define
define|#
directive|define
name|__MP_H__
end_define

begin_define
define|#
directive|define
name|__GNU_MP__
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|__GMP_H__
end_ifndef

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

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|MP_INT
end_ifndef

begin_ifndef
ifndef|#
directive|ifndef
name|__MP_SMALL__
end_ifndef

begin_typedef
typedef|typedef
struct|struct
block|{
name|long
name|int
name|alloc
decl_stmt|;
comment|/* Number of *limbs* allocated and pointed 				   to by the D field.  */
name|long
name|int
name|size
decl_stmt|;
comment|/* abs(SIZE) is the number of limbs 				   the last field points to.  If SIZE 				   is negative this is a negative 				   number.  */
name|unsigned
name|long
name|int
modifier|*
name|d
decl_stmt|;
comment|/* Pointer to the limbs.  */
block|}
name|__MP_INT
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
name|alloc
decl_stmt|;
comment|/* Number of *limbs* allocated and pointed 				   to by the D field.  */
name|short
name|int
name|size
decl_stmt|;
comment|/* abs(SIZE) is the number of limbs 				   the last field points to.  If SIZE 				   is negative this is a negative 				   number.  */
name|unsigned
name|long
name|int
modifier|*
name|d
decl_stmt|;
comment|/* Pointer to the limbs.  */
block|}
name|__MP_INT
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

begin_define
define|#
directive|define
name|MINT
value|__MP_INT
end_define

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

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __MP_H__ */
end_comment

end_unit

