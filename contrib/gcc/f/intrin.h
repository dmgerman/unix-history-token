begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* intrin.h -- Public interface for intrin.c    Copyright (C) 1995-1997 Free Software Foundation, Inc.    Contributed by James Craig Burley (burley@gnu.org).  This file is part of GNU Fortran.  GNU Fortran is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GNU Fortran is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GNU Fortran; see the file COPYING.  If not, write to the Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_H_f_intrin
end_ifndef

begin_define
define|#
directive|define
name|_H_f_intrin
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|FFEINTRIN_DOC
end_ifndef

begin_define
define|#
directive|define
name|FFEINTRIN_DOC
value|0
end_define

begin_comment
comment|/* 1 means intrinsic documentation only (intdoc.c). */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
enum|enum
block|{
name|FFEINTRIN_familyNONE
block|,
comment|/* Not in any family. */
name|FFEINTRIN_familyF77
block|,
comment|/* ANSI FORTRAN 77. */
name|FFEINTRIN_familyGNU
block|,
comment|/* GNU Fortran intrinsics. */
name|FFEINTRIN_familyF2C
block|,
comment|/* f2c intrinsics. */
name|FFEINTRIN_familyF90
block|,
comment|/* Fortran 90. */
name|FFEINTRIN_familyF95
init|=
name|FFEINTRIN_familyF90
block|,
name|FFEINTRIN_familyVXT
block|,
comment|/* VAX/VMS FORTRAN. */
name|FFEINTRIN_familyMIL
block|,
comment|/* MIL STD 1753 (MVBITS, etc), in mil, vxt, and f90. */
name|FFEINTRIN_familyASC
block|,
comment|/* ASCII-related (ACHAR, IACHAR), both f2c and f90. */
name|FFEINTRIN_familyFVZ
block|,
comment|/* in both f2c and VAX/VMS FORTRAN. */
name|FFEINTRIN_familyF2U
block|,
comment|/* libf2c/libU77 UNIX system intrinsics. */
name|FFEINTRIN_familyBADU77
block|,
comment|/* libU77 UNIX system intrinsics with bad form. */
name|FFEINTRIN_family
block|}
name|ffeintrinFamily
typedef|;
end_typedef

begin_typedef
typedef|typedef
enum|enum
block|{
define|#
directive|define
name|DEFNAME
parameter_list|(
name|UPPER
parameter_list|,
name|LOWER
parameter_list|,
name|MIXED
parameter_list|,
name|GEN
parameter_list|,
name|SPEC
parameter_list|)
define|#
directive|define
name|DEFGEN
parameter_list|(
name|CODE
parameter_list|,
name|NAME
parameter_list|,
name|SPEC1
parameter_list|,
name|SPEC2
parameter_list|)
value|FFEINTRIN_gen ## CODE,
define|#
directive|define
name|DEFSPEC
parameter_list|(
name|CODE
parameter_list|,
name|NAME
parameter_list|,
name|CALLABLE
parameter_list|,
name|FAMILY
parameter_list|,
name|IMP
parameter_list|)
define|#
directive|define
name|DEFIMP
parameter_list|(
name|CODE
parameter_list|,
name|NAME
parameter_list|,
name|GFRTDIRECT
parameter_list|,
name|GFRTF2C
parameter_list|,
name|GFRTGNU
parameter_list|,
name|CONTROL
parameter_list|)
include|#
directive|include
file|"intrin.def"
undef|#
directive|undef
name|DEFNAME
undef|#
directive|undef
name|DEFGEN
undef|#
directive|undef
name|DEFSPEC
undef|#
directive|undef
name|DEFIMP
name|FFEINTRIN_gen
block|}
name|ffeintrinGen
typedef|;
end_typedef

begin_typedef
typedef|typedef
enum|enum
block|{
define|#
directive|define
name|DEFNAME
parameter_list|(
name|UPPER
parameter_list|,
name|LOWER
parameter_list|,
name|MIXED
parameter_list|,
name|GEN
parameter_list|,
name|SPEC
parameter_list|)
define|#
directive|define
name|DEFGEN
parameter_list|(
name|CODE
parameter_list|,
name|NAME
parameter_list|,
name|SPEC1
parameter_list|,
name|SPEC2
parameter_list|)
define|#
directive|define
name|DEFSPEC
parameter_list|(
name|CODE
parameter_list|,
name|NAME
parameter_list|,
name|CALLABLE
parameter_list|,
name|FAMILY
parameter_list|,
name|IMP
parameter_list|)
value|FFEINTRIN_spec ## CODE,
define|#
directive|define
name|DEFIMP
parameter_list|(
name|CODE
parameter_list|,
name|NAME
parameter_list|,
name|GFRTDIRECT
parameter_list|,
name|GFRTF2C
parameter_list|,
name|GFRTGNU
parameter_list|,
name|CONTROL
parameter_list|)
include|#
directive|include
file|"intrin.def"
undef|#
directive|undef
name|DEFNAME
undef|#
directive|undef
name|DEFGEN
undef|#
directive|undef
name|DEFSPEC
undef|#
directive|undef
name|DEFIMP
name|FFEINTRIN_spec
block|}
name|ffeintrinSpec
typedef|;
end_typedef

begin_typedef
typedef|typedef
enum|enum
block|{
define|#
directive|define
name|DEFNAME
parameter_list|(
name|UPPER
parameter_list|,
name|LOWER
parameter_list|,
name|MIXED
parameter_list|,
name|GEN
parameter_list|,
name|SPEC
parameter_list|)
define|#
directive|define
name|DEFGEN
parameter_list|(
name|CODE
parameter_list|,
name|NAME
parameter_list|,
name|SPEC1
parameter_list|,
name|SPEC2
parameter_list|)
define|#
directive|define
name|DEFSPEC
parameter_list|(
name|CODE
parameter_list|,
name|NAME
parameter_list|,
name|CALLABLE
parameter_list|,
name|FAMILY
parameter_list|,
name|IMP
parameter_list|)
define|#
directive|define
name|DEFIMP
parameter_list|(
name|CODE
parameter_list|,
name|NAME
parameter_list|,
name|GFRTDIRECT
parameter_list|,
name|GFRTF2C
parameter_list|,
name|GFRTGNU
parameter_list|,
name|CONTROL
parameter_list|)
define|\
value|FFEINTRIN_imp ## CODE,
include|#
directive|include
file|"intrin.def"
undef|#
directive|undef
name|DEFNAME
undef|#
directive|undef
name|DEFGEN
undef|#
directive|undef
name|DEFSPEC
undef|#
directive|undef
name|DEFIMP
name|FFEINTRIN_imp
block|}
name|ffeintrinImp
typedef|;
end_typedef

begin_if
if|#
directive|if
operator|!
name|FFEINTRIN_DOC
end_if

begin_include
include|#
directive|include
file|"bld.h"
end_include

begin_include
include|#
directive|include
file|"info.h"
end_include

begin_function_decl
name|ffeinfoBasictype
name|ffeintrin_basictype
parameter_list|(
name|ffeintrinSpec
name|spec
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ffeintrinFamily
name|ffeintrin_family
parameter_list|(
name|ffeintrinSpec
name|spec
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ffeintrin_fulfill_generic
parameter_list|(
name|ffebld
modifier|*
name|expr
parameter_list|,
name|ffeinfo
modifier|*
name|info
parameter_list|,
name|ffelexToken
name|t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ffeintrin_fulfill_specific
parameter_list|(
name|ffebld
modifier|*
name|expr
parameter_list|,
name|ffeinfo
modifier|*
name|info
parameter_list|,
name|bool
modifier|*
name|check_intrin
parameter_list|,
name|ffelexToken
name|t
parameter_list|)
function_decl|;
end_function_decl

begin_if
if|#
directive|if
name|FFECOM_targetCURRENT
operator|==
name|FFECOM_targetGCC
end_if

begin_function_decl
name|ffecomGfrt
name|ffeintrin_gfrt_direct
parameter_list|(
name|ffeintrinImp
name|imp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ffecomGfrt
name|ffeintrin_gfrt_indirect
parameter_list|(
name|ffeintrinImp
name|imp
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* FFECOM_targetCURRENT == FFECOM_targetGCC */
end_comment

begin_function_decl
name|void
name|ffeintrin_init_0
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|ffeintrin_init_1
parameter_list|()
end_define

begin_define
define|#
directive|define
name|ffeintrin_init_2
parameter_list|()
end_define

begin_define
define|#
directive|define
name|ffeintrin_init_3
parameter_list|()
end_define

begin_define
define|#
directive|define
name|ffeintrin_init_4
parameter_list|()
end_define

begin_function_decl
name|bool
name|ffeintrin_is_actualarg
parameter_list|(
name|ffeintrinSpec
name|spec
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|ffeintrin_is_intrinsic
parameter_list|(
name|char
modifier|*
name|name
parameter_list|,
name|ffelexToken
name|t
parameter_list|,
name|bool
name|explicit
parameter_list|,
name|ffeintrinGen
modifier|*
name|gen
parameter_list|,
name|ffeintrinSpec
modifier|*
name|spec
parameter_list|,
name|ffeintrinImp
modifier|*
name|imp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|ffeintrin_is_standard
parameter_list|(
name|ffeintrinGen
name|gen
parameter_list|,
name|ffeintrinSpec
name|spec
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ffeinfoKindtype
name|ffeintrin_kindtype
parameter_list|(
name|ffeintrinSpec
name|spec
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|ffeintrin_name_generic
parameter_list|(
name|ffeintrinGen
name|gen
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|ffeintrin_name_implementation
parameter_list|(
name|ffeintrinImp
name|imp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|ffeintrin_name_specific
parameter_list|(
name|ffeintrinSpec
name|spec
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ffeIntrinsicState
name|ffeintrin_state_family
parameter_list|(
name|ffeintrinFamily
name|family
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|ffeintrin_terminate_0
parameter_list|()
end_define

begin_define
define|#
directive|define
name|ffeintrin_terminate_1
parameter_list|()
end_define

begin_define
define|#
directive|define
name|ffeintrin_terminate_2
parameter_list|()
end_define

begin_define
define|#
directive|define
name|ffeintrin_terminate_3
parameter_list|()
end_define

begin_define
define|#
directive|define
name|ffeintrin_terminate_4
parameter_list|()
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !FFEINTRIN_DOC */
end_comment

begin_comment
comment|/* End of #include file. */
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

