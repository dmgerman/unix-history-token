begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Definitions for simple data type for positive real numbers.    Copyright (C) 2002, 2003 Free Software Foundation, Inc.  This file is part of GCC.  GCC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GCC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GCC; see the file COPYING.  If not, write to the Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|GCC_SREAL_H
end_ifndef

begin_define
define|#
directive|define
name|GCC_SREAL_H
end_define

begin_comment
comment|/* SREAL_PART_BITS has to be an even number.  */
end_comment

begin_if
if|#
directive|if
operator|(
name|HOST_BITS_PER_WIDE_INT
operator|/
literal|2
operator|)
operator|%
literal|2
operator|==
literal|1
end_if

begin_define
define|#
directive|define
name|SREAL_PART_BITS
value|(HOST_BITS_PER_WIDE_INT / 2 - 1)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|SREAL_PART_BITS
value|(HOST_BITS_PER_WIDE_INT / 2)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|uhwi
value|unsigned HOST_WIDE_INT
end_define

begin_define
define|#
directive|define
name|MAX_HOST_WIDE_INT
value|(((uhwi) 1<< (HOST_BITS_PER_WIDE_INT - 1)) - 1)
end_define

begin_define
define|#
directive|define
name|SREAL_MIN_SIG
value|((uhwi) 1<< (SREAL_PART_BITS - 1))
end_define

begin_define
define|#
directive|define
name|SREAL_MAX_SIG
value|(((uhwi) 1<< SREAL_PART_BITS) - 1)
end_define

begin_define
define|#
directive|define
name|SREAL_MAX_EXP
value|(INT_MAX / 4)
end_define

begin_if
if|#
directive|if
name|SREAL_PART_BITS
operator|<
literal|32
end_if

begin_define
define|#
directive|define
name|SREAL_BITS
value|(SREAL_PART_BITS * 2)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|SREAL_BITS
value|SREAL_PART_BITS
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Structure for holding a simple real number.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|sreal
block|{
if|#
directive|if
name|SREAL_PART_BITS
operator|<
literal|32
name|unsigned
name|HOST_WIDE_INT
name|sig_lo
decl_stmt|;
comment|/* Significant (lower part).  */
name|unsigned
name|HOST_WIDE_INT
name|sig_hi
decl_stmt|;
comment|/* Significant (higher part).  */
else|#
directive|else
name|unsigned
name|HOST_WIDE_INT
name|sig
decl_stmt|;
comment|/* Significant.  */
endif|#
directive|endif
name|signed
name|int
name|exp
decl_stmt|;
comment|/* Exponent.  */
block|}
name|sreal
typedef|;
end_typedef

begin_function_decl
specifier|extern
name|void
name|dump_sreal
parameter_list|(
name|FILE
modifier|*
parameter_list|,
name|sreal
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|sreal
modifier|*
name|sreal_init
parameter_list|(
name|sreal
modifier|*
parameter_list|,
name|unsigned
name|HOST_WIDE_INT
parameter_list|,
name|signed
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|HOST_WIDE_INT
name|sreal_to_int
parameter_list|(
name|sreal
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|sreal_compare
parameter_list|(
name|sreal
modifier|*
parameter_list|,
name|sreal
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|sreal
modifier|*
name|sreal_add
parameter_list|(
name|sreal
modifier|*
parameter_list|,
name|sreal
modifier|*
parameter_list|,
name|sreal
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|sreal
modifier|*
name|sreal_sub
parameter_list|(
name|sreal
modifier|*
parameter_list|,
name|sreal
modifier|*
parameter_list|,
name|sreal
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|sreal
modifier|*
name|sreal_mul
parameter_list|(
name|sreal
modifier|*
parameter_list|,
name|sreal
modifier|*
parameter_list|,
name|sreal
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|sreal
modifier|*
name|sreal_div
parameter_list|(
name|sreal
modifier|*
parameter_list|,
name|sreal
modifier|*
parameter_list|,
name|sreal
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

end_unit

