begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* PowerPC AltiVec include file.    Copyright (C) 2002 Free Software Foundation, Inc.    Contributed by Aldy Hernandez (aldyh@redhat.com).  This file is part of GNU CC.  GNU CC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GNU CC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GNU CC; see the file COPYING.  If not, write to the Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_comment
comment|/* As a special exception, if you include this header file into source    files compiled by GCC, this header file does not by itself cause    the resulting executable to be covered by the GNU General Public    License.  This exception does not however invalidate any other    reasons why the executable file might be covered by the GNU General    Public License.  */
end_comment

begin_comment
comment|/* Implemented to conform to the specification included in the AltiVec    Technology Programming Interface Manual (ALTIVECPIM/D 6/1999 Rev 0).  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_ALTIVEC_H
end_ifndef

begin_define
define|#
directive|define
name|_ALTIVEC_H
value|1
end_define

begin_comment
comment|/* Required by Motorola specs.  */
end_comment

begin_define
define|#
directive|define
name|__VEC__
value|10206
end_define

begin_define
define|#
directive|define
name|__ALTIVEC__
value|1
end_define

begin_define
define|#
directive|define
name|__vector
value|__attribute__((vector_size(16)))
end_define

begin_comment
comment|/* Dummy prototype.  */
end_comment

begin_function_decl
specifier|extern
name|void
name|__altivec_link_error_invalid_argument
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* You are allowed to undef this for C++ compatability.  */
end_comment

begin_define
define|#
directive|define
name|vector
value|__vector
end_define

begin_comment
comment|/* Helper macros.  */
end_comment

begin_define
define|#
directive|define
name|__bin_args_eq
parameter_list|(
name|xtype
parameter_list|,
name|x
parameter_list|,
name|ytype
parameter_list|,
name|y
parameter_list|)
define|\
value|(__builtin_types_compatible_p (xtype, typeof (x))		\&& __builtin_types_compatible_p (ytype, typeof (y)))
end_define

begin_define
define|#
directive|define
name|__un_args_eq
parameter_list|(
name|xtype
parameter_list|,
name|x
parameter_list|)
define|\
value|__builtin_types_compatible_p (xtype, typeof (x))
end_define

begin_define
define|#
directive|define
name|__tern_args_eq
parameter_list|(
name|xtype
parameter_list|,
name|x
parameter_list|,
name|ytype
parameter_list|,
name|y
parameter_list|,
name|ztype
parameter_list|,
name|z
parameter_list|)
define|\
value|(__builtin_types_compatible_p (xtype, typeof (x))               \&& __builtin_types_compatible_p (ytype, typeof (y))		\&& __builtin_types_compatible_p (ztype, typeof (z)))
end_define

begin_define
define|#
directive|define
name|__ch
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|,
name|z
parameter_list|)
value|__builtin_choose_expr (x, y, z)
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|__cplusplus
end_ifdef

begin_comment
comment|/* C++ stuff here.  */
end_comment

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* not C++ */
end_comment

begin_comment
comment|/* Hairy macros that implement the AltiVec high-level programming    interface for C.  */
end_comment

begin_define
define|#
directive|define
name|vec_add
parameter_list|(
name|a1
parameter_list|,
name|a2
parameter_list|)
define|\
value|__ch (__bin_args_eq (vector signed char, a1, vector signed char, a2), \       (vector signed char) __builtin_altivec_vaddubm ((vector signed char) a1, (vector signed char) a2), \ __ch (__bin_args_eq (vector signed char, a1, vector unsigned char, a2), \       (vector unsigned char) __builtin_altivec_vaddubm ((vector signed char) a1, (vector signed char) a2), \ __ch (__bin_args_eq (vector unsigned char, a1, vector signed char, a2), \       (vector unsigned char) __builtin_altivec_vaddubm ((vector signed char) a1, (vector signed char) a2), \ __ch (__bin_args_eq (vector unsigned char, a1, vector unsigned char, a2), \       (vector unsigned char) __builtin_altivec_vaddubm ((vector signed char) a1, (vector signed char) a2), \ __ch (__bin_args_eq (vector signed short, a1, vector signed short, a2), \       (vector signed short) __builtin_altivec_vadduhm ((vector signed short) a1, (vector signed short) a2), \ __ch (__bin_args_eq (vector signed short, a1, vector unsigned short, a2), \       (vector unsigned short) __builtin_altivec_vadduhm ((vector signed short) a1, (vector signed short) a2), \ __ch (__bin_args_eq (vector unsigned short, a1, vector signed short, a2), \       (vector unsigned short) __builtin_altivec_vadduhm ((vector signed short) a1, (vector signed short) a2), \ __ch (__bin_args_eq (vector unsigned short, a1, vector unsigned short, a2), \       (vector unsigned short) __builtin_altivec_vadduhm ((vector signed short) a1, (vector signed short) a2), \ __ch (__bin_args_eq (vector signed int, a1, vector signed int, a2), \       (vector signed int) __builtin_altivec_vadduwm ((vector signed int) a1, (vector signed int) a2), \ __ch (__bin_args_eq (vector signed int, a1, vector unsigned int, a2), \       (vector unsigned int) __builtin_altivec_vadduwm ((vector signed int) a1, (vector signed int) a2), \ __ch (__bin_args_eq (vector unsigned int, a1, vector signed int, a2), \       (vector unsigned int) __builtin_altivec_vadduwm ((vector signed int) a1, (vector signed int) a2), \ __ch (__bin_args_eq (vector unsigned int, a1, vector unsigned int, a2), \       (vector unsigned int) __builtin_altivec_vadduwm ((vector signed int) a1, (vector signed int) a2), \ __ch (__bin_args_eq (vector float, a1, vector float, a2), \       (vector float) __builtin_altivec_vaddfp ((vector float) a1, (vector float) a2), \     __altivec_link_error_invalid_argument ())))))))))))))
end_define

begin_define
define|#
directive|define
name|vec_addc
parameter_list|(
name|a1
parameter_list|,
name|a2
parameter_list|)
value|__builtin_altivec_vaddcuw (a1, a2)
end_define

begin_define
define|#
directive|define
name|vec_adds
parameter_list|(
name|a1
parameter_list|,
name|a2
parameter_list|)
define|\
value|__ch (__bin_args_eq (vector signed char, a1, vector unsigned char, a2), \       (vector unsigned char) __builtin_altivec_vaddubs ((vector signed char) a1, (vector signed char) a2), \ __ch (__bin_args_eq (vector unsigned char, a1, vector signed char, a2), \       (vector unsigned char) __builtin_altivec_vaddubs ((vector signed char) a1, (vector signed char) a2), \ __ch (__bin_args_eq (vector unsigned char, a1, vector unsigned char, a2), \       (vector unsigned char) __builtin_altivec_vaddubs ((vector signed char) a1, (vector signed char) a2), \ __ch (__bin_args_eq (vector signed char, a1, vector signed char, a2), \       (vector signed char) __builtin_altivec_vaddsbs ((vector signed char) a1, (vector signed char) a2), \ __ch (__bin_args_eq (vector signed short, a1, vector unsigned short, a2), \       (vector unsigned short) __builtin_altivec_vadduhs ((vector signed short) a1, (vector signed short) a2), \ __ch (__bin_args_eq (vector unsigned short, a1, vector signed short, a2), \       (vector unsigned short) __builtin_altivec_vadduhs ((vector signed short) a1, (vector signed short) a2), \ __ch (__bin_args_eq (vector unsigned short, a1, vector unsigned short, a2), \       (vector unsigned short) __builtin_altivec_vadduhs ((vector signed short) a1, (vector signed short) a2), \ __ch (__bin_args_eq (vector signed short, a1, vector signed short, a2), \       (vector signed short) __builtin_altivec_vaddshs ((vector signed short) a1, (vector signed short) a2), \ __ch (__bin_args_eq (vector signed int, a1, vector unsigned int, a2), \       (vector unsigned int) __builtin_altivec_vadduws ((vector signed int) a1, (vector signed int) a2), \ __ch (__bin_args_eq (vector unsigned int, a1, vector signed int, a2), \       (vector unsigned int) __builtin_altivec_vadduws ((vector signed int) a1, (vector signed int) a2), \ __ch (__bin_args_eq (vector unsigned int, a1, vector unsigned int, a2), \       (vector unsigned int) __builtin_altivec_vadduws ((vector signed int) a1, (vector signed int) a2), \ __ch (__bin_args_eq (vector signed int, a1, vector signed int, a2), \       (vector signed int) __builtin_altivec_vaddsws ((vector signed int) a1, (vector signed int) a2), \     __altivec_link_error_invalid_argument ()))))))))))))
end_define

begin_define
define|#
directive|define
name|vec_and
parameter_list|(
name|a1
parameter_list|,
name|a2
parameter_list|)
define|\
value|__ch (__bin_args_eq (vector float, a1, vector float, a2), \       (vector float) __builtin_altivec_vand ((vector signed int) a1, (vector signed int) a2), \ __ch (__bin_args_eq (vector float, a1, vector signed int, a2), \       (vector float) __builtin_altivec_vand ((vector signed int) a1, (vector signed int) a2), \ __ch (__bin_args_eq (vector signed int, a1, vector float, a2), \       (vector float) __builtin_altivec_vand ((vector signed int) a1, (vector signed int) a2), \ __ch (__bin_args_eq (vector signed int, a1, vector signed int, a2), \       (vector signed int) __builtin_altivec_vand ((vector signed int) a1, (vector signed int) a2), \ __ch (__bin_args_eq (vector signed int, a1, vector unsigned int, a2), \       (vector unsigned int) __builtin_altivec_vand ((vector signed int) a1, (vector signed int) a2), \ __ch (__bin_args_eq (vector unsigned int, a1, vector signed int, a2), \       (vector unsigned int) __builtin_altivec_vand ((vector signed int) a1, (vector signed int) a2), \ __ch (__bin_args_eq (vector unsigned int, a1, vector unsigned int, a2), \       (vector unsigned int) __builtin_altivec_vand ((vector signed int) a1, (vector signed int) a2), \ __ch (__bin_args_eq (vector signed short, a1, vector signed short, a2), \       (vector signed short) __builtin_altivec_vand ((vector signed int) a1, (vector signed int) a2), \ __ch (__bin_args_eq (vector signed short, a1, vector unsigned short, a2), \       (vector unsigned short) __builtin_altivec_vand ((vector signed int) a1, (vector signed int) a2), \ __ch (__bin_args_eq (vector unsigned short, a1, vector signed short, a2), \       (vector unsigned short) __builtin_altivec_vand ((vector signed int) a1, (vector signed int) a2), \ __ch (__bin_args_eq (vector unsigned short, a1, vector unsigned short, a2), \       (vector unsigned short) __builtin_altivec_vand ((vector signed int) a1, (vector signed int) a2), \ __ch (__bin_args_eq (vector signed char, a1, vector signed char, a2), \       (vector signed char) __builtin_altivec_vand ((vector signed int) a1, (vector signed int) a2), \ __ch (__bin_args_eq (vector signed char, a1, vector unsigned char, a2), \       (vector unsigned char) __builtin_altivec_vand ((vector signed int) a1, (vector signed int) a2), \ __ch (__bin_args_eq (vector unsigned char, a1, vector signed char, a2), \       (vector unsigned char) __builtin_altivec_vand ((vector signed int) a1, (vector signed int) a2), \ __ch (__bin_args_eq (vector unsigned char, a1, vector unsigned char, a2), \       (vector unsigned char) __builtin_altivec_vand ((vector signed int) a1, (vector signed int) a2), \     __altivec_link_error_invalid_argument ())))))))))))))))
end_define

begin_define
define|#
directive|define
name|vec_andc
parameter_list|(
name|a1
parameter_list|,
name|a2
parameter_list|)
define|\
value|__ch (__bin_args_eq (vector float, a1, vector float, a2), \       (vector float) __builtin_altivec_vandc ((vector signed int) a1, (vector signed int) a2), \ __ch (__bin_args_eq (vector float, a1, vector signed int, a2), \       (vector float) __builtin_altivec_vandc ((vector signed int) a1, (vector signed int) a2), \ __ch (__bin_args_eq (vector signed int, a1, vector float, a2), \       (vector float) __builtin_altivec_vandc ((vector signed int) a1, (vector signed int) a2), \ __ch (__bin_args_eq (vector signed int, a1, vector signed int, a2), \       (vector signed int) __builtin_altivec_vandc ((vector signed int) a1, (vector signed int) a2), \ __ch (__bin_args_eq (vector signed int, a1, vector unsigned int, a2), \       (vector unsigned int) __builtin_altivec_vandc ((vector signed int) a1, (vector signed int) a2), \ __ch (__bin_args_eq (vector unsigned int, a1, vector signed int, a2), \       (vector unsigned int) __builtin_altivec_vandc ((vector signed int) a1, (vector signed int) a2), \ __ch (__bin_args_eq (vector unsigned int, a1, vector unsigned int, a2), \       (vector unsigned int) __builtin_altivec_vandc ((vector signed int) a1, (vector signed int) a2), \ __ch (__bin_args_eq (vector signed short, a1, vector signed short, a2), \       (vector signed short) __builtin_altivec_vandc ((vector signed int) a1, (vector signed int) a2), \ __ch (__bin_args_eq (vector signed short, a1, vector unsigned short, a2), \       (vector unsigned short) __builtin_altivec_vandc ((vector signed int) a1, (vector signed int) a2), \ __ch (__bin_args_eq (vector unsigned short, a1, vector signed short, a2), \       (vector unsigned short) __builtin_altivec_vandc ((vector signed int) a1, (vector signed int) a2), \ __ch (__bin_args_eq (vector unsigned short, a1, vector unsigned short, a2), \       (vector unsigned short) __builtin_altivec_vandc ((vector signed int) a1, (vector signed int) a2), \ __ch (__bin_args_eq (vector signed char, a1, vector signed char, a2), \       (vector signed char) __builtin_altivec_vandc ((vector signed int) a1, (vector signed int) a2), \ __ch (__bin_args_eq (vector signed char, a1, vector unsigned char, a2), \       (vector unsigned char) __builtin_altivec_vandc ((vector signed int) a1, (vector signed int) a2), \ __ch (__bin_args_eq (vector unsigned char, a1, vector signed char, a2), \       (vector unsigned char) __builtin_altivec_vandc ((vector signed int) a1, (vector signed int) a2), \ __ch (__bin_args_eq (vector unsigned char, a1, vector unsigned char, a2), \       (vector unsigned char) __builtin_altivec_vandc ((vector signed int) a1, (vector signed int) a2), \     __altivec_link_error_invalid_argument ())))))))))))))))
end_define

begin_define
define|#
directive|define
name|vec_avg
parameter_list|(
name|a1
parameter_list|,
name|a2
parameter_list|)
define|\
value|__ch (__bin_args_eq (vector unsigned char, a1, vector unsigned char, a2), \       (vector unsigned char) __builtin_altivec_vavgub ((vector signed char) a1, (vector signed char) a2), \ __ch (__bin_args_eq (vector signed char, a1, vector signed char, a2), \       (vector signed char) __builtin_altivec_vavgsb ((vector signed char) a1, (vector signed char) a2), \ __ch (__bin_args_eq (vector unsigned short, a1, vector unsigned short, a2), \       (vector unsigned short) __builtin_altivec_vavguh ((vector signed short) a1, (vector signed short) a2), \ __ch (__bin_args_eq (vector signed short, a1, vector signed short, a2), \       (vector signed short) __builtin_altivec_vavgsh ((vector signed short) a1, (vector signed short) a2), \ __ch (__bin_args_eq (vector unsigned int, a1, vector unsigned int, a2), \       (vector unsigned int) __builtin_altivec_vavguw ((vector signed int) a1, (vector signed int) a2), \ __ch (__bin_args_eq (vector signed int, a1, vector signed int, a2), \       (vector signed int) __builtin_altivec_vavgsw ((vector signed int) a1, (vector signed int) a2), \     __altivec_link_error_invalid_argument ()))))))
end_define

begin_define
define|#
directive|define
name|vec_ceil
parameter_list|(
name|a1
parameter_list|)
value|__builtin_altivec_vrfip (a1)
end_define

begin_define
define|#
directive|define
name|vec_cmpb
parameter_list|(
name|a1
parameter_list|,
name|a2
parameter_list|)
value|__builtin_altivec_vcmpbfp (a1, a2)
end_define

begin_define
define|#
directive|define
name|vec_cmpeq
parameter_list|(
name|a1
parameter_list|,
name|a2
parameter_list|)
define|\
value|__ch (__bin_args_eq (vector signed char, a1, vector signed char, a2), \       (vector signed char) __builtin_altivec_vcmpequb ((vector signed char) a1, (vector signed char) a2), \ __ch (__bin_args_eq (vector unsigned char, a1, vector unsigned char, a2), \       (vector signed char) __builtin_altivec_vcmpequb ((vector signed char) a1, (vector signed char) a2), \ __ch (__bin_args_eq (vector signed short, a1, vector signed short, a2), \       (vector signed short) __builtin_altivec_vcmpequh ((vector signed short) a1, (vector signed short) a2), \ __ch (__bin_args_eq (vector unsigned short, a1, vector unsigned short, a2), \       (vector signed short) __builtin_altivec_vcmpequh ((vector signed short) a1, (vector signed short) a2), \ __ch (__bin_args_eq (vector signed int, a1, vector signed int, a2), \       (vector signed int) __builtin_altivec_vcmpequw ((vector signed int) a1, (vector signed int) a2), \ __ch (__bin_args_eq (vector unsigned int, a1, vector unsigned int, a2), \       (vector signed int) __builtin_altivec_vcmpequw ((vector signed int) a1, (vector signed int) a2), \ __ch (__bin_args_eq (vector float, a1, vector float, a2), \       (vector signed int) __builtin_altivec_vcmpeqfp ((vector float) a1, (vector float) a2), \     __altivec_link_error_invalid_argument ())))))))
end_define

begin_define
define|#
directive|define
name|vec_cmpge
parameter_list|(
name|a1
parameter_list|,
name|a2
parameter_list|)
value|__builtin_altivec_vcmpgefp (a1, a2)
end_define

begin_define
define|#
directive|define
name|vec_cmpgt
parameter_list|(
name|a1
parameter_list|,
name|a2
parameter_list|)
define|\
value|__ch (__bin_args_eq (vector unsigned char, a1, vector unsigned char, a2), \       (vector signed char) __builtin_altivec_vcmpgtub ((vector signed char) a1, (vector signed char) a2), \ __ch (__bin_args_eq (vector signed char, a1, vector signed char, a2), \       (vector signed char) __builtin_altivec_vcmpgtsb ((vector signed char) a1, (vector signed char) a2), \ __ch (__bin_args_eq (vector unsigned short, a1, vector unsigned short, a2), \       (vector signed short) __builtin_altivec_vcmpgtuh ((vector signed short) a1, (vector signed short) a2), \ __ch (__bin_args_eq (vector signed short, a1, vector signed short, a2), \       (vector signed short) __builtin_altivec_vcmpgtsh ((vector signed short) a1, (vector signed short) a2), \ __ch (__bin_args_eq (vector unsigned int, a1, vector unsigned int, a2), \       (vector signed int) __builtin_altivec_vcmpgtuw ((vector signed int) a1, (vector signed int) a2), \ __ch (__bin_args_eq (vector signed int, a1, vector signed int, a2), \       (vector signed int) __builtin_altivec_vcmpgtsw ((vector signed int) a1, (vector signed int) a2), \ __ch (__bin_args_eq (vector float, a1, vector float, a2), \       (vector signed int) __builtin_altivec_vcmpgtfp ((vector float) a1, (vector float) a2), \     __altivec_link_error_invalid_argument ())))))))
end_define

begin_define
define|#
directive|define
name|vec_cmple
parameter_list|(
name|a1
parameter_list|,
name|a2
parameter_list|)
value|__builtin_altivec_vcmpgefp (a1, a2)
end_define

begin_define
define|#
directive|define
name|vec_cmplt
parameter_list|(
name|a1
parameter_list|,
name|a2
parameter_list|)
define|\
value|__ch (__bin_args_eq (vector unsigned char, a1, vector unsigned char, a2), \       (vector signed char) __builtin_altivec_vcmpgtub ((vector signed char) a1, (vector signed char) a2), \ __ch (__bin_args_eq (vector signed char, a1, vector signed char, a2), \       (vector signed char) __builtin_altivec_vcmpgtsb ((vector signed char) a1, (vector signed char) a2), \ __ch (__bin_args_eq (vector unsigned short, a1, vector unsigned short, a2), \       (vector signed short) __builtin_altivec_vcmpgtuh ((vector signed short) a1, (vector signed short) a2), \ __ch (__bin_args_eq (vector signed short, a1, vector signed short, a2), \       (vector signed short) __builtin_altivec_vcmpgtsh ((vector signed short) a1, (vector signed short) a2), \ __ch (__bin_args_eq (vector unsigned int, a1, vector unsigned int, a2), \       (vector signed int) __builtin_altivec_vcmpgtuw ((vector signed int) a1, (vector signed int) a2), \ __ch (__bin_args_eq (vector signed int, a1, vector signed int, a2), \       (vector signed int) __builtin_altivec_vcmpgtsw ((vector signed int) a1, (vector signed int) a2), \ __ch (__bin_args_eq (vector float, a1, vector float, a2), \       (vector signed int) __builtin_altivec_vcmpgtfp ((vector float) a1, (vector float) a2), \     __altivec_link_error_invalid_argument ())))))))
end_define

begin_define
define|#
directive|define
name|vec_ctf
parameter_list|(
name|a1
parameter_list|,
name|a2
parameter_list|)
define|\
value|__ch (__bin_args_eq (vector unsigned int, a1, const char, a2), \       (vector float) __builtin_altivec_vcfux ((vector signed int) a1, (const char) a2), \ __ch (__bin_args_eq (vector signed int, a1, const char, a2), \       (vector float) __builtin_altivec_vcfsx ((vector signed int) a1, (const char) a2), \     __altivec_link_error_invalid_argument ()))
end_define

begin_define
define|#
directive|define
name|vec_cts
parameter_list|(
name|a1
parameter_list|,
name|a2
parameter_list|)
value|__builtin_altivec_vctsxs (a1, a2)
end_define

begin_define
define|#
directive|define
name|vec_ctu
parameter_list|(
name|a1
parameter_list|,
name|a2
parameter_list|)
value|__builtin_altivec_vctuxs (a1, a2)
end_define

begin_define
define|#
directive|define
name|vec_dss
parameter_list|(
name|a1
parameter_list|)
value|__builtin_altivec_dss (a1)
end_define

begin_define
define|#
directive|define
name|vec_dssall
parameter_list|()
value|__builtin_altivec_dssall ()
end_define

begin_define
define|#
directive|define
name|vec_dst
parameter_list|(
name|a1
parameter_list|,
name|a2
parameter_list|,
name|a3
parameter_list|)
value|__builtin_altivec_dst (a1, a2, a3)
end_define

begin_define
define|#
directive|define
name|vec_dstst
parameter_list|(
name|a1
parameter_list|,
name|a2
parameter_list|,
name|a3
parameter_list|)
value|__builtin_altivec_dstst (a1, a2, a3)
end_define

begin_define
define|#
directive|define
name|vec_dststt
parameter_list|(
name|a1
parameter_list|,
name|a2
parameter_list|,
name|a3
parameter_list|)
value|__builtin_altivec_dststt (a1, a2, a3)
end_define

begin_define
define|#
directive|define
name|vec_dstt
parameter_list|(
name|a1
parameter_list|,
name|a2
parameter_list|,
name|a3
parameter_list|)
value|__builtin_altivec_dstt (a1, a2, a3)
end_define

begin_define
define|#
directive|define
name|vec_expte
parameter_list|(
name|a1
parameter_list|)
value|__builtin_altivec_vexptefp (a1)
end_define

begin_define
define|#
directive|define
name|vec_floor
parameter_list|(
name|a1
parameter_list|)
value|__builtin_altivec_vrfim (a1)
end_define

begin_define
define|#
directive|define
name|vec_ld
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
define|\
value|__ch (__un_args_eq (vector unsigned char *, b), \       (vector unsigned char) __builtin_altivec_lvx (a, b), \ __ch (__un_args_eq (unsigned char *, b), \       (vector unsigned char) __builtin_altivec_lvx (a, b), \ __ch (__un_args_eq (vector signed char *, b), \       (vector signed char) __builtin_altivec_lvx (a, b), \ __ch (__un_args_eq (signed char *, b), \       (vector signed char) __builtin_altivec_lvx (a, b), \ __ch (__un_args_eq (vector unsigned short *, b), \       (vector unsigned short) __builtin_altivec_lvx (a, b), \ __ch (__un_args_eq (unsigned short *, b), \       (vector unsigned short) __builtin_altivec_lvx (a, b), \ __ch (__un_args_eq (vector signed short *, b), \       (vector signed short) __builtin_altivec_lvx (a, b), \ __ch (__un_args_eq (signed short *, b), \       (vector signed short) __builtin_altivec_lvx (a, b), \ __ch (__un_args_eq (vector unsigned int *, b), \       (vector unsigned int) __builtin_altivec_lvx (a, b), \ __ch (__un_args_eq (unsigned int *, b), \       (vector unsigned int) __builtin_altivec_lvx (a, b), \ __ch (__un_args_eq (vector signed int *, b), \       (vector signed int) __builtin_altivec_lvx (a, b), \ __ch (__un_args_eq (signed int *, b), \       (vector signed int) __builtin_altivec_lvx (a, b), \ __ch (__un_args_eq (vector float *, b), \       (vector float) __builtin_altivec_lvx (a, b), \ __ch (__un_args_eq (float *, b), \       (vector float) __builtin_altivec_lvx (a, b), \ __altivec_link_error_invalid_argument ()))))))))))))))
end_define

begin_define
define|#
directive|define
name|vec_lde
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
define|\
value|__ch (__un_args_eq (unsigned char *, b), \       (vector unsigned char) __builtin_altivec_lvebx (a, b), \ __ch (__un_args_eq (signed char *, b), \       (vector signed char) __builtin_altivec_lvebx (a, b), \ __ch (__un_args_eq (unsigned short *, b), \       (vector unsigned short) __builtin_altivec_lvehx (a, b), \ __ch (__un_args_eq (signed short *, b), \       (vector signed short) __builtin_altivec_lvehx (a, b), \ __ch (__un_args_eq (unsigned int *, b), \       (vector unsigned int) __builtin_altivec_lvewx (a, b), \ __ch (__un_args_eq (signed int *, b), \       (vector signed int) __builtin_altivec_lvewx (a, b), \ __altivec_link_error_invalid_argument ()))))))
end_define

begin_define
define|#
directive|define
name|vec_ldl
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
define|\
value|__ch (__un_args_eq (vector unsigned char *, b), \       (vector unsigned char) __builtin_altivec_lvxl (a, b), \ __ch (__un_args_eq (unsigned char *, b), \       (vector unsigned char) __builtin_altivec_lvxl (a, b), \ __ch (__un_args_eq (vector signed char *, b), \       (vector signed char) __builtin_altivec_lvxl (a, b), \ __ch (__un_args_eq (signed char *, b), \       (vector signed char) __builtin_altivec_lvxl (a, b), \ __ch (__un_args_eq (vector unsigned short *, b), \       (vector unsigned short) __builtin_altivec_lvxl (a, b), \ __ch (__un_args_eq (unsigned short *, b), \       (vector unsigned short) __builtin_altivec_lvxl (a, b), \ __ch (__un_args_eq (vector signed short *, b), \       (vector signed short) __builtin_altivec_lvxl (a, b), \ __ch (__un_args_eq (signed short *, b), \       (vector signed short) __builtin_altivec_lvxl (a, b), \ __ch (__un_args_eq (vector unsigned int *, b), \       (vector unsigned int) __builtin_altivec_lvxl (a, b), \ __ch (__un_args_eq (unsigned int *, b), \       (vector unsigned int) __builtin_altivec_lvxl (a, b), \ __ch (__un_args_eq (vector signed int *, b), \       (vector signed int) __builtin_altivec_lvxl (a, b), \ __ch (__un_args_eq (signed int *, b), \       (vector signed int) __builtin_altivec_lvxl (a, b), \ __ch (__un_args_eq (vector float *, b), \       (vector float) __builtin_altivec_lvxl (a, b), \ __ch (__un_args_eq (float *, b), \       (vector float) __builtin_altivec_lvxl (a, b), \ __altivec_link_error_invalid_argument ()))))))))))))))
end_define

begin_define
define|#
directive|define
name|vec_loge
parameter_list|(
name|a1
parameter_list|)
value|__builtin_altivec_vlogefp (a1)
end_define

begin_define
define|#
directive|define
name|vec_lvsl
parameter_list|(
name|a1
parameter_list|,
name|a2
parameter_list|)
value|__builtin_altivec_lvsl (a1, a2)
end_define

begin_define
define|#
directive|define
name|vec_lvsr
parameter_list|(
name|a1
parameter_list|,
name|a2
parameter_list|)
value|__builtin_altivec_lvsr (a1, a2)
end_define

begin_define
define|#
directive|define
name|vec_madd
parameter_list|(
name|a1
parameter_list|,
name|a2
parameter_list|,
name|a3
parameter_list|)
value|__builtin_altivec_vmaddfp (a1, a2, a3)
end_define

begin_define
define|#
directive|define
name|vec_madds
parameter_list|(
name|a1
parameter_list|,
name|a2
parameter_list|,
name|a3
parameter_list|)
value|__builtin_altivec_vmhaddshs (a1, a2, a3)
end_define

begin_define
define|#
directive|define
name|vec_max
parameter_list|(
name|a1
parameter_list|,
name|a2
parameter_list|)
define|\
value|__ch (__bin_args_eq (vector signed char, a1, vector unsigned char, a2), \       (vector unsigned char) __builtin_altivec_vmaxub ((vector signed char) a1, (vector signed char) a2), \ __ch (__bin_args_eq (vector unsigned char, a1, vector signed char, a2), \       (vector unsigned char) __builtin_altivec_vmaxub ((vector signed char) a1, (vector signed char) a2), \ __ch (__bin_args_eq (vector unsigned char, a1, vector unsigned char, a2), \       (vector unsigned char) __builtin_altivec_vmaxub ((vector signed char) a1, (vector signed char) a2), \ __ch (__bin_args_eq (vector signed char, a1, vector signed char, a2), \       (vector signed char) __builtin_altivec_vmaxsb ((vector signed char) a1, (vector signed char) a2), \ __ch (__bin_args_eq (vector signed short, a1, vector unsigned short, a2), \       (vector unsigned short) __builtin_altivec_vmaxuh ((vector signed short) a1, (vector signed short) a2), \ __ch (__bin_args_eq (vector unsigned short, a1, vector signed short, a2), \       (vector unsigned short) __builtin_altivec_vmaxuh ((vector signed short) a1, (vector signed short) a2), \ __ch (__bin_args_eq (vector unsigned short, a1, vector unsigned short, a2), \       (vector unsigned short) __builtin_altivec_vmaxuh ((vector signed short) a1, (vector signed short) a2), \ __ch (__bin_args_eq (vector signed short, a1, vector signed short, a2), \       (vector signed short) __builtin_altivec_vmaxsh ((vector signed short) a1, (vector signed short) a2), \ __ch (__bin_args_eq (vector signed int, a1, vector unsigned int, a2), \       (vector unsigned int) __builtin_altivec_vmaxuw ((vector signed int) a1, (vector signed int) a2), \ __ch (__bin_args_eq (vector unsigned int, a1, vector signed int, a2), \       (vector unsigned int) __builtin_altivec_vmaxuw ((vector signed int) a1, (vector signed int) a2), \ __ch (__bin_args_eq (vector unsigned int, a1, vector unsigned int, a2), \       (vector unsigned int) __builtin_altivec_vmaxuw ((vector signed int) a1, (vector signed int) a2), \ __ch (__bin_args_eq (vector signed int, a1, vector signed int, a2), \       (vector signed int) __builtin_altivec_vmaxsw ((vector signed int) a1, (vector signed int) a2), \ __ch (__bin_args_eq (vector float, a1, vector float, a2), \       (vector float) __builtin_altivec_vmaxfp ((vector float) a1, (vector float) a2), \     __altivec_link_error_invalid_argument ())))))))))))))
end_define

begin_define
define|#
directive|define
name|vec_mergeh
parameter_list|(
name|a1
parameter_list|,
name|a2
parameter_list|)
define|\
value|__ch (__bin_args_eq (vector signed char, a1, vector signed char, a2), \       (vector signed char) __builtin_altivec_vmrghb ((vector signed char) a1, (vector signed char) a2), \ __ch (__bin_args_eq (vector unsigned char, a1, vector unsigned char, a2), \       (vector unsigned char) __builtin_altivec_vmrghb ((vector signed char) a1, (vector signed char) a2), \ __ch (__bin_args_eq (vector signed short, a1, vector signed short, a2), \       (vector signed short) __builtin_altivec_vmrghh ((vector signed short) a1, (vector signed short) a2), \ __ch (__bin_args_eq (vector unsigned short, a1, vector unsigned short, a2), \       (vector unsigned short) __builtin_altivec_vmrghh ((vector signed short) a1, (vector signed short) a2), \ __ch (__bin_args_eq (vector float, a1, vector float, a2), \       (vector float) __builtin_altivec_vmrghw ((vector signed int) a1, (vector signed int) a2), \ __ch (__bin_args_eq (vector signed int, a1, vector signed int, a2), \       (vector signed int) __builtin_altivec_vmrghw ((vector signed int) a1, (vector signed int) a2), \ __ch (__bin_args_eq (vector unsigned int, a1, vector unsigned int, a2), \       (vector unsigned int) __builtin_altivec_vmrghw ((vector signed int) a1, (vector signed int) a2), \     __altivec_link_error_invalid_argument ())))))))
end_define

begin_define
define|#
directive|define
name|vec_mergel
parameter_list|(
name|a1
parameter_list|,
name|a2
parameter_list|)
define|\
value|__ch (__bin_args_eq (vector signed char, a1, vector signed char, a2), \       (vector signed char) __builtin_altivec_vmrglb ((vector signed char) a1, (vector signed char) a2), \ __ch (__bin_args_eq (vector unsigned char, a1, vector unsigned char, a2), \       (vector unsigned char) __builtin_altivec_vmrglb ((vector signed char) a1, (vector signed char) a2), \ __ch (__bin_args_eq (vector signed short, a1, vector signed short, a2), \       (vector signed short) __builtin_altivec_vmrglh ((vector signed short) a1, (vector signed short) a2), \ __ch (__bin_args_eq (vector unsigned short, a1, vector unsigned short, a2), \       (vector unsigned short) __builtin_altivec_vmrglh ((vector signed short) a1, (vector signed short) a2), \ __ch (__bin_args_eq (vector float, a1, vector float, a2), \       (vector float) __builtin_altivec_vmrglw ((vector signed int) a1, (vector signed int) a2), \ __ch (__bin_args_eq (vector signed int, a1, vector signed int, a2), \       (vector signed int) __builtin_altivec_vmrglw ((vector signed int) a1, (vector signed int) a2), \ __ch (__bin_args_eq (vector unsigned int, a1, vector unsigned int, a2), \       (vector unsigned int) __builtin_altivec_vmrglw ((vector signed int) a1, (vector signed int) a2), \     __altivec_link_error_invalid_argument ())))))))
end_define

begin_define
define|#
directive|define
name|vec_mfvscr
parameter_list|()
value|__builtin_altivec_mfvscr ()
end_define

begin_define
define|#
directive|define
name|vec_min
parameter_list|(
name|a1
parameter_list|,
name|a2
parameter_list|)
define|\
value|__ch (__bin_args_eq (vector signed char, a1, vector unsigned char, a2), \       (vector unsigned char) __builtin_altivec_vminub ((vector signed char) a1, (vector signed char) a2), \ __ch (__bin_args_eq (vector unsigned char, a1, vector signed char, a2), \       (vector unsigned char) __builtin_altivec_vminub ((vector signed char) a1, (vector signed char) a2), \ __ch (__bin_args_eq (vector unsigned char, a1, vector unsigned char, a2), \       (vector unsigned char) __builtin_altivec_vminub ((vector signed char) a1, (vector signed char) a2), \ __ch (__bin_args_eq (vector signed char, a1, vector signed char, a2), \       (vector signed char) __builtin_altivec_vminsb ((vector signed char) a1, (vector signed char) a2), \ __ch (__bin_args_eq (vector signed short, a1, vector unsigned short, a2), \       (vector unsigned short) __builtin_altivec_vminuh ((vector signed short) a1, (vector signed short) a2), \ __ch (__bin_args_eq (vector unsigned short, a1, vector signed short, a2), \       (vector unsigned short) __builtin_altivec_vminuh ((vector signed short) a1, (vector signed short) a2), \ __ch (__bin_args_eq (vector unsigned short, a1, vector unsigned short, a2), \       (vector unsigned short) __builtin_altivec_vminuh ((vector signed short) a1, (vector signed short) a2), \ __ch (__bin_args_eq (vector signed short, a1, vector signed short, a2), \       (vector signed short) __builtin_altivec_vminsh ((vector signed short) a1, (vector signed short) a2), \ __ch (__bin_args_eq (vector signed int, a1, vector unsigned int, a2), \       (vector unsigned int) __builtin_altivec_vminuw ((vector signed int) a1, (vector signed int) a2), \ __ch (__bin_args_eq (vector unsigned int, a1, vector signed int, a2), \       (vector unsigned int) __builtin_altivec_vminuw ((vector signed int) a1, (vector signed int) a2), \ __ch (__bin_args_eq (vector unsigned int, a1, vector unsigned int, a2), \       (vector unsigned int) __builtin_altivec_vminuw ((vector signed int) a1, (vector signed int) a2), \ __ch (__bin_args_eq (vector signed int, a1, vector signed int, a2), \       (vector signed int) __builtin_altivec_vminsw ((vector signed int) a1, (vector signed int) a2), \ __ch (__bin_args_eq (vector float, a1, vector float, a2), \       (vector float) __builtin_altivec_vminfp ((vector float) a1, (vector float) a2), \     __altivec_link_error_invalid_argument ())))))))))))))
end_define

begin_define
define|#
directive|define
name|vec_mladd
parameter_list|(
name|a1
parameter_list|,
name|a2
parameter_list|,
name|a3
parameter_list|)
define|\
value|__ch (__tern_args_eq (vector signed short, a1, vector signed short, a2, vector signed short, a3), \       (vector signed short) __builtin_altivec_vmladduhm ((vector signed short) a1, (vector signed short) a2, (vector signed short) a3), \ __ch (__tern_args_eq (vector signed short, a1, vector unsigned short, a2, vector unsigned short, a3), \       (vector signed short) __builtin_altivec_vmladduhm ((vector signed short) a1, (vector signed short) a2, (vector signed short) a3), \ __ch (__tern_args_eq (vector unsigned short, a1, vector signed short, a2, vector signed short, a3), \       (vector signed short) __builtin_altivec_vmladduhm ((vector signed short) a1, (vector signed short) a2, (vector signed short) a3), \ __ch (__tern_args_eq (vector unsigned short, a1, vector unsigned short, a2, vector unsigned short, a3), \       (vector unsigned short) __builtin_altivec_vmladduhm ((vector signed short) a1, (vector signed short) a2, (vector signed short) a3), \     __altivec_link_error_invalid_argument ()))))
end_define

begin_define
define|#
directive|define
name|vec_mradds
parameter_list|(
name|a1
parameter_list|,
name|a2
parameter_list|,
name|a3
parameter_list|)
value|__builtin_altivec_vmhraddshs (a1, a2, a3)
end_define

begin_define
define|#
directive|define
name|vec_msum
parameter_list|(
name|a1
parameter_list|,
name|a2
parameter_list|,
name|a3
parameter_list|)
define|\
value|__ch (__tern_args_eq (vector unsigned char, a1, vector unsigned char, a2, vector unsigned int, a3), \       (vector unsigned int) __builtin_altivec_vmsumubm ((vector signed char) a1, (vector signed char) a2, (vector signed int) a3), \ __ch (__tern_args_eq (vector signed char, a1, vector unsigned char, a2, vector signed int, a3), \       (vector signed int) __builtin_altivec_vmsummbm ((vector signed char) a1, (vector signed char) a2, (vector signed int) a3), \ __ch (__tern_args_eq (vector unsigned short, a1, vector unsigned short, a2, vector unsigned int, a3), \       (vector unsigned int) __builtin_altivec_vmsumuhm ((vector signed short) a1, (vector signed short) a2, (vector signed int) a3), \ __ch (__tern_args_eq (vector signed short, a1, vector signed short, a2, vector signed int, a3), \       (vector signed int) __builtin_altivec_vmsumshm ((vector signed short) a1, (vector signed short) a2, (vector signed int) a3), \     __altivec_link_error_invalid_argument ()))))
end_define

begin_define
define|#
directive|define
name|vec_msums
parameter_list|(
name|a1
parameter_list|,
name|a2
parameter_list|,
name|a3
parameter_list|)
define|\
value|__ch (__tern_args_eq (vector unsigned short, a1, vector unsigned short, a2, vector unsigned int, a3), \       (vector unsigned int) __builtin_altivec_vmsumuhs ((vector signed short) a1, (vector signed short) a2, (vector signed int) a3), \ __ch (__tern_args_eq (vector signed short, a1, vector signed short, a2, vector signed int, a3), \       (vector signed int) __builtin_altivec_vmsumshs ((vector signed short) a1, (vector signed short) a2, (vector signed int) a3), \     __altivec_link_error_invalid_argument ()))
end_define

begin_define
define|#
directive|define
name|vec_mtvscr
parameter_list|(
name|a1
parameter_list|)
define|\
value|__ch (__un_args_eq (vector signed int, a1), \       __builtin_altivec_mtvscr ((vector signed int) a1), \ __ch (__un_args_eq (vector unsigned int, a1), \       __builtin_altivec_mtvscr ((vector signed int) a1), \ __ch (__un_args_eq (vector signed short, a1), \       __builtin_altivec_mtvscr ((vector signed int) a1), \ __ch (__un_args_eq (vector unsigned short, a1), \       __builtin_altivec_mtvscr ((vector signed int) a1), \ __ch (__un_args_eq (vector signed char, a1), \       __builtin_altivec_mtvscr ((vector signed int) a1), \ __ch (__un_args_eq (vector unsigned char, a1), \       __builtin_altivec_mtvscr ((vector signed int) a1), \     __altivec_link_error_invalid_argument ()))))))
end_define

begin_define
define|#
directive|define
name|vec_mule
parameter_list|(
name|a1
parameter_list|,
name|a2
parameter_list|)
define|\
value|__ch (__bin_args_eq (vector unsigned char, a1, vector unsigned char, a2), \       (vector unsigned short) __builtin_altivec_vmuleub ((vector signed char) a1, (vector signed char) a2), \ __ch (__bin_args_eq (vector signed char, a1, vector signed char, a2), \       (vector signed short) __builtin_altivec_vmulesb ((vector signed char) a1, (vector signed char) a2), \ __ch (__bin_args_eq (vector unsigned short, a1, vector unsigned short, a2), \       (vector unsigned int) __builtin_altivec_vmuleuh ((vector signed short) a1, (vector signed short) a2), \ __ch (__bin_args_eq (vector signed short, a1, vector signed short, a2), \       (vector signed int) __builtin_altivec_vmulesh ((vector signed short) a1, (vector signed short) a2), \     __altivec_link_error_invalid_argument ()))))
end_define

begin_define
define|#
directive|define
name|vec_mulo
parameter_list|(
name|a1
parameter_list|,
name|a2
parameter_list|)
define|\
value|__ch (__bin_args_eq (vector unsigned char, a1, vector unsigned char, a2), \       (vector unsigned short) __builtin_altivec_vmuloub ((vector signed char) a1, (vector signed char) a2), \ __ch (__bin_args_eq (vector signed char, a1, vector signed char, a2), \       (vector signed short) __builtin_altivec_vmulosb ((vector signed char) a1, (vector signed char) a2), \ __ch (__bin_args_eq (vector unsigned short, a1, vector unsigned short, a2), \       (vector unsigned int) __builtin_altivec_vmulouh ((vector signed short) a1, (vector signed short) a2), \ __ch (__bin_args_eq (vector signed short, a1, vector signed short, a2), \       (vector signed int) __builtin_altivec_vmulosh ((vector signed short) a1, (vector signed short) a2), \     __altivec_link_error_invalid_argument ()))))
end_define

begin_define
define|#
directive|define
name|vec_nmsub
parameter_list|(
name|a1
parameter_list|,
name|a2
parameter_list|,
name|a3
parameter_list|)
value|__builtin_altivec_vnmsubfp (a1, a2, a3)
end_define

begin_define
define|#
directive|define
name|vec_nor
parameter_list|(
name|a1
parameter_list|,
name|a2
parameter_list|)
define|\
value|__ch (__bin_args_eq (vector float, a1, vector float, a2), \       (vector float) __builtin_altivec_vnor ((vector signed int) a1, (vector signed int) a2), \ __ch (__bin_args_eq (vector signed int, a1, vector signed int, a2), \       (vector signed int) __builtin_altivec_vnor ((vector signed int) a1, (vector signed int) a2), \ __ch (__bin_args_eq (vector unsigned int, a1, vector unsigned int, a2), \       (vector unsigned int) __builtin_altivec_vnor ((vector signed int) a1, (vector signed int) a2), \ __ch (__bin_args_eq (vector signed short, a1, vector signed short, a2), \       (vector signed short) __builtin_altivec_vnor ((vector signed int) a1, (vector signed int) a2), \ __ch (__bin_args_eq (vector unsigned short, a1, vector unsigned short, a2), \       (vector unsigned short) __builtin_altivec_vnor ((vector signed int) a1, (vector signed int) a2), \ __ch (__bin_args_eq (vector signed char, a1, vector signed char, a2), \       (vector signed char) __builtin_altivec_vnor ((vector signed int) a1, (vector signed int) a2), \ __ch (__bin_args_eq (vector unsigned char, a1, vector unsigned char, a2), \       (vector unsigned char) __builtin_altivec_vnor ((vector signed int) a1, (vector signed int) a2), \     __altivec_link_error_invalid_argument ())))))))
end_define

begin_define
define|#
directive|define
name|vec_or
parameter_list|(
name|a1
parameter_list|,
name|a2
parameter_list|)
define|\
value|__ch (__bin_args_eq (vector float, a1, vector float, a2), \       (vector float) __builtin_altivec_vor ((vector signed int) a1, (vector signed int) a2), \ __ch (__bin_args_eq (vector float, a1, vector signed int, a2), \       (vector float) __builtin_altivec_vor ((vector signed int) a1, (vector signed int) a2), \ __ch (__bin_args_eq (vector signed int, a1, vector float, a2), \       (vector float) __builtin_altivec_vor ((vector signed int) a1, (vector signed int) a2), \ __ch (__bin_args_eq (vector signed int, a1, vector signed int, a2), \       (vector signed int) __builtin_altivec_vor ((vector signed int) a1, (vector signed int) a2), \ __ch (__bin_args_eq (vector signed int, a1, vector unsigned int, a2), \       (vector unsigned int) __builtin_altivec_vor ((vector signed int) a1, (vector signed int) a2), \ __ch (__bin_args_eq (vector unsigned int, a1, vector signed int, a2), \       (vector unsigned int) __builtin_altivec_vor ((vector signed int) a1, (vector signed int) a2), \ __ch (__bin_args_eq (vector unsigned int, a1, vector unsigned int, a2), \       (vector unsigned int) __builtin_altivec_vor ((vector signed int) a1, (vector signed int) a2), \ __ch (__bin_args_eq (vector signed short, a1, vector signed short, a2), \       (vector signed short) __builtin_altivec_vor ((vector signed int) a1, (vector signed int) a2), \ __ch (__bin_args_eq (vector signed short, a1, vector unsigned short, a2), \       (vector unsigned short) __builtin_altivec_vor ((vector signed int) a1, (vector signed int) a2), \ __ch (__bin_args_eq (vector unsigned short, a1, vector signed short, a2), \       (vector unsigned short) __builtin_altivec_vor ((vector signed int) a1, (vector signed int) a2), \ __ch (__bin_args_eq (vector unsigned short, a1, vector unsigned short, a2), \       (vector unsigned short) __builtin_altivec_vor ((vector signed int) a1, (vector signed int) a2), \ __ch (__bin_args_eq (vector signed char, a1, vector signed char, a2), \       (vector signed char) __builtin_altivec_vor ((vector signed int) a1, (vector signed int) a2), \ __ch (__bin_args_eq (vector signed char, a1, vector unsigned char, a2), \       (vector unsigned char) __builtin_altivec_vor ((vector signed int) a1, (vector signed int) a2), \ __ch (__bin_args_eq (vector unsigned char, a1, vector signed char, a2), \       (vector unsigned char) __builtin_altivec_vor ((vector signed int) a1, (vector signed int) a2), \ __ch (__bin_args_eq (vector unsigned char, a1, vector unsigned char, a2), \       (vector unsigned char) __builtin_altivec_vor ((vector signed int) a1, (vector signed int) a2), \     __altivec_link_error_invalid_argument ())))))))))))))))
end_define

begin_define
define|#
directive|define
name|vec_pack
parameter_list|(
name|a1
parameter_list|,
name|a2
parameter_list|)
define|\
value|__ch (__bin_args_eq (vector signed short, a1, vector signed short, a2), \       (vector signed char) __builtin_altivec_vpkuhum ((vector signed short) a1, (vector signed short) a2), \ __ch (__bin_args_eq (vector unsigned short, a1, vector unsigned short, a2), \       (vector unsigned char) __builtin_altivec_vpkuhum ((vector signed short) a1, (vector signed short) a2), \ __ch (__bin_args_eq (vector signed int, a1, vector signed int, a2), \       (vector signed short) __builtin_altivec_vpkuwum ((vector signed int) a1, (vector signed int) a2), \ __ch (__bin_args_eq (vector unsigned int, a1, vector unsigned int, a2), \       (vector unsigned short) __builtin_altivec_vpkuwum ((vector signed int) a1, (vector signed int) a2), \     __altivec_link_error_invalid_argument ()))))
end_define

begin_define
define|#
directive|define
name|vec_packpx
parameter_list|(
name|a1
parameter_list|,
name|a2
parameter_list|)
value|__builtin_altivec_vpkpx (a1, a2)
end_define

begin_define
define|#
directive|define
name|vec_packs
parameter_list|(
name|a1
parameter_list|,
name|a2
parameter_list|)
define|\
value|__ch (__bin_args_eq (vector unsigned short, a1, vector unsigned short, a2), \       (vector unsigned char) __builtin_altivec_vpkuhus ((vector signed short) a1, (vector signed short) a2), \ __ch (__bin_args_eq (vector signed short, a1, vector signed short, a2), \       (vector signed char) __builtin_altivec_vpkshss ((vector signed short) a1, (vector signed short) a2), \ __ch (__bin_args_eq (vector unsigned int, a1, vector unsigned int, a2), \       (vector unsigned short) __builtin_altivec_vpkuwus ((vector signed int) a1, (vector signed int) a2), \ __ch (__bin_args_eq (vector signed int, a1, vector signed int, a2), \       (vector signed short) __builtin_altivec_vpkswss ((vector signed int) a1, (vector signed int) a2), \     __altivec_link_error_invalid_argument ()))))
end_define

begin_define
define|#
directive|define
name|vec_packsu
parameter_list|(
name|a1
parameter_list|,
name|a2
parameter_list|)
define|\
value|__ch (__bin_args_eq (vector unsigned short, a1, vector unsigned short, a2), \       (vector unsigned char) __builtin_altivec_vpkuhus ((vector signed short) a1, (vector signed short) a2), \ __ch (__bin_args_eq (vector signed short, a1, vector signed short, a2), \       (vector unsigned char) __builtin_altivec_vpkshus ((vector signed short) a1, (vector signed short) a2), \ __ch (__bin_args_eq (vector unsigned int, a1, vector unsigned int, a2), \       (vector unsigned short) __builtin_altivec_vpkuwus ((vector signed int) a1, (vector signed int) a2), \ __ch (__bin_args_eq (vector signed int, a1, vector signed int, a2), \       (vector unsigned short) __builtin_altivec_vpkswus ((vector signed int) a1, (vector signed int) a2), \     __altivec_link_error_invalid_argument ()))))
end_define

begin_define
define|#
directive|define
name|vec_perm
parameter_list|(
name|a1
parameter_list|,
name|a2
parameter_list|,
name|a3
parameter_list|,
name|a4
parameter_list|)
define|\
value|__ch (__tern_args_eq (vector float, a1, vector float, a2, vector unsigned char, a3), \       (vector float) __builtin_altivec_vperm_4si ((vector signed int) a1, (vector signed int) a2, (vector signed char) a3), \ __ch (__tern_args_eq (vector signed int, a1, vector signed int, a2, vector unsigned char, a3), \       (vector signed int) __builtin_altivec_vperm_4si ((vector signed int) a1, (vector signed int) a2, (vector signed char) a3), \ __ch (__tern_args_eq (vector unsigned int, a1, vector unsigned int, a2, vector unsigned char, a3), \       (vector unsigned int) __builtin_altivec_vperm_4si ((vector signed int) a1, (vector signed int) a2, (vector signed char) a3), \ __ch (__tern_args_eq (vector signed short, a1, vector signed short, a2, vector unsigned char, a3), \       (vector signed short) __builtin_altivec_vperm_4si ((vector signed int) a1, (vector signed int) a2, (vector signed char) a3), \ __ch (__tern_args_eq (vector unsigned short, a1, vector unsigned short, a2, vector unsigned char, a3), \       (vector unsigned short) __builtin_altivec_vperm_4si ((vector signed int) a1, (vector signed int) a2, (vector signed char) a3), \ __ch (__tern_args_eq (vector signed char, a1, vector signed char, a2, vector unsigned char, a3), \       (vector signed char) __builtin_altivec_vperm_4si ((vector signed int) a1, (vector signed int) a2, (vector signed char) a3), \ __ch (__tern_args_eq (vector unsigned char, a1, vector unsigned char, a2, vector unsigned char, a3), \       (vector unsigned char) __builtin_altivec_vperm_4si ((vector signed int) a1, (vector signed int) a2, (vector signed char) a3), \     __altivec_link_error_invalid_argument ())))))))
end_define

begin_define
define|#
directive|define
name|vec_re
parameter_list|(
name|a1
parameter_list|)
value|__builtin_altivec_vrefp (a1)
end_define

begin_define
define|#
directive|define
name|vec_rl
parameter_list|(
name|a1
parameter_list|,
name|a2
parameter_list|)
define|\
value|__ch (__bin_args_eq (vector signed char, a1, vector unsigned char, a2), \       (vector signed char) __builtin_altivec_vrlb ((vector signed char) a1, (vector signed char) a2), \ __ch (__bin_args_eq (vector unsigned char, a1, vector unsigned char, a2), \       (vector unsigned char) __builtin_altivec_vrlb ((vector signed char) a1, (vector signed char) a2), \ __ch (__bin_args_eq (vector signed short, a1, vector unsigned short, a2), \       (vector signed short) __builtin_altivec_vrlh ((vector signed short) a1, (vector signed short) a2), \ __ch (__bin_args_eq (vector unsigned short, a1, vector unsigned short, a2), \       (vector unsigned short) __builtin_altivec_vrlh ((vector signed short) a1, (vector signed short) a2), \ __ch (__bin_args_eq (vector signed int, a1, vector unsigned int, a2), \       (vector signed int) __builtin_altivec_vrlw ((vector signed int) a1, (vector signed int) a2), \ __ch (__bin_args_eq (vector unsigned int, a1, vector unsigned int, a2), \       (vector unsigned int) __builtin_altivec_vrlw ((vector signed int) a1, (vector signed int) a2), \     __altivec_link_error_invalid_argument ()))))))
end_define

begin_define
define|#
directive|define
name|vec_round
parameter_list|(
name|a1
parameter_list|)
value|__builtin_altivec_vrfin (a1)
end_define

begin_define
define|#
directive|define
name|vec_rsqrte
parameter_list|(
name|a1
parameter_list|)
value|__builtin_altivec_vrsqrtefp (a1)
end_define

begin_define
define|#
directive|define
name|vec_sel
parameter_list|(
name|a1
parameter_list|,
name|a2
parameter_list|,
name|a3
parameter_list|)
define|\
value|__ch (__tern_args_eq (vector float, a1, vector float, a2, vector signed int, a3), \       (vector float) __builtin_altivec_vsel_4si ((vector signed int) a1, (vector signed int) a2, (vector signed int) a3), \ __ch (__tern_args_eq (vector float, a1, vector float, a2, vector unsigned int, a3), \       (vector float) __builtin_altivec_vsel_4si ((vector signed int) a1, (vector signed int) a2, (vector signed int) a3), \ __ch (__tern_args_eq (vector signed int, a1, vector signed int, a2, vector signed int, a3), \       (vector signed int) __builtin_altivec_vsel_4si ((vector signed int) a1, (vector signed int) a2, (vector signed int) a3), \ __ch (__tern_args_eq (vector signed int, a1, vector signed int, a2, vector unsigned int, a3), \       (vector signed int) __builtin_altivec_vsel_4si ((vector signed int) a1, (vector signed int) a2, (vector signed int) a3), \ __ch (__tern_args_eq (vector unsigned int, a1, vector unsigned int, a2, vector signed int, a3), \       (vector unsigned int) __builtin_altivec_vsel_4si ((vector signed int) a1, (vector signed int) a2, (vector signed int) a3), \ __ch (__tern_args_eq (vector unsigned int, a1, vector unsigned int, a2, vector unsigned int, a3), \       (vector unsigned int) __builtin_altivec_vsel_4si ((vector signed int) a1, (vector signed int) a2, (vector signed int) a3), \ __ch (__tern_args_eq (vector signed short, a1, vector signed short, a2, vector signed short, a3), \       (vector signed short) __builtin_altivec_vsel_4si ((vector signed int) a1, (vector signed int) a2, (vector signed int) a3), \ __ch (__tern_args_eq (vector signed short, a1, vector signed short, a2, vector unsigned short, a3), \       (vector signed short) __builtin_altivec_vsel_4si ((vector signed int) a1, (vector signed int) a2, (vector signed int) a3), \ __ch (__tern_args_eq (vector unsigned short, a1, vector unsigned short, a2, vector signed short, a3), \       (vector unsigned short) __builtin_altivec_vsel_4si ((vector signed int) a1, (vector signed int) a2, (vector signed int) a3), \ __ch (__tern_args_eq (vector unsigned short, a1, vector unsigned short, a2, vector unsigned short, a3), \       (vector unsigned short) __builtin_altivec_vsel_4si ((vector signed int) a1, (vector signed int) a2, (vector signed int) a3), \ __ch (__tern_args_eq (vector signed char, a1, vector signed char, a2, vector signed char, a3), \       (vector signed char) __builtin_altivec_vsel_4si ((vector signed int) a1, (vector signed int) a2, (vector signed int) a3), \ __ch (__tern_args_eq (vector signed char, a1, vector signed char, a2, vector unsigned char, a3), \       (vector signed char) __builtin_altivec_vsel_4si ((vector signed int) a1, (vector signed int) a2, (vector signed int) a3), \ __ch (__tern_args_eq (vector unsigned char, a1, vector unsigned char, a2, vector signed char, a3), \       (vector unsigned char) __builtin_altivec_vsel_4si ((vector signed int) a1, (vector signed int) a2, (vector signed int) a3), \ __ch (__tern_args_eq (vector unsigned char, a1, vector unsigned char, a2, vector unsigned char, a3), \       (vector unsigned char) __builtin_altivec_vsel_4si ((vector signed int) a1, (vector signed int) a2, (vector signed int) a3), \     __altivec_link_error_invalid_argument ()))))))))))))))
end_define

begin_define
define|#
directive|define
name|vec_sl
parameter_list|(
name|a1
parameter_list|,
name|a2
parameter_list|)
define|\
value|__ch (__bin_args_eq (vector signed char, a1, vector unsigned char, a2), \       (vector signed char) __builtin_altivec_vslb ((vector signed char) a1, (vector signed char) a2), \ __ch (__bin_args_eq (vector unsigned char, a1, vector unsigned char, a2), \       (vector unsigned char) __builtin_altivec_vslb ((vector signed char) a1, (vector signed char) a2), \ __ch (__bin_args_eq (vector signed short, a1, vector unsigned short, a2), \       (vector signed short) __builtin_altivec_vslh ((vector signed short) a1, (vector signed short) a2), \ __ch (__bin_args_eq (vector unsigned short, a1, vector unsigned short, a2), \       (vector unsigned short) __builtin_altivec_vslh ((vector signed short) a1, (vector signed short) a2), \ __ch (__bin_args_eq (vector signed int, a1, vector unsigned int, a2), \       (vector signed int) __builtin_altivec_vslw ((vector signed int) a1, (vector signed int) a2), \ __ch (__bin_args_eq (vector unsigned int, a1, vector unsigned int, a2), \       (vector unsigned int) __builtin_altivec_vslw ((vector signed int) a1, (vector signed int) a2), \     __altivec_link_error_invalid_argument ()))))))
end_define

begin_define
define|#
directive|define
name|vec_sld
parameter_list|(
name|a1
parameter_list|,
name|a2
parameter_list|,
name|a3
parameter_list|)
define|\
value|__ch (__tern_args_eq (vector float, a1, vector float, a2, const char, a3), \       (vector float) __builtin_altivec_vsldoi_4si ((vector signed int) a1, (vector signed int) a2, (const char) a3), \ __ch (__tern_args_eq (vector signed int, a1, vector signed int, a2, const char, a3), \       (vector signed int) __builtin_altivec_vsldoi_4si ((vector signed int) a1, (vector signed int) a2, (const char) a3), \ __ch (__tern_args_eq (vector unsigned int, a1, vector unsigned int, a2, const char, a3), \       (vector unsigned int) __builtin_altivec_vsldoi_4si ((vector signed int) a1, (vector signed int) a2, (const char) a3), \ __ch (__tern_args_eq (vector signed short, a1, vector signed short, a2, const char, a3), \       (vector signed short) __builtin_altivec_vsldoi_4si ((vector signed int) a1, (vector signed int) a2, (const char) a3), \ __ch (__tern_args_eq (vector unsigned short, a1, vector unsigned short, a2, const char, a3), \       (vector unsigned short) __builtin_altivec_vsldoi_4si ((vector signed int) a1, (vector signed int) a2, (const char) a3), \ __ch (__tern_args_eq (vector signed char, a1, vector signed char, a2, const char, a3), \       (vector signed char) __builtin_altivec_vsldoi_4si ((vector signed int) a1, (vector signed int) a2, (const char) a3), \ __ch (__tern_args_eq (vector unsigned char, a1, vector unsigned char, a2, const char, a3), \       (vector unsigned char) __builtin_altivec_vsldoi_4si ((vector signed int) a1, (vector signed int) a2, (const char) a3), \     __altivec_link_error_invalid_argument ())))))))
end_define

begin_define
define|#
directive|define
name|vec_sll
parameter_list|(
name|a1
parameter_list|,
name|a2
parameter_list|)
define|\
value|__ch (__bin_args_eq (vector signed int, a1, vector unsigned int, a2), \       (vector signed int) __builtin_altivec_vsl ((vector signed int) a1, (vector signed int) a2), \ __ch (__bin_args_eq (vector signed int, a1, vector unsigned short, a2), \       (vector signed int) __builtin_altivec_vsl ((vector signed int) a1, (vector signed int) a2), \ __ch (__bin_args_eq (vector signed int, a1, vector unsigned char, a2), \       (vector signed int) __builtin_altivec_vsl ((vector signed int) a1, (vector signed int) a2), \ __ch (__bin_args_eq (vector unsigned int, a1, vector unsigned int, a2), \       (vector unsigned int) __builtin_altivec_vsl ((vector signed int) a1, (vector signed int) a2), \ __ch (__bin_args_eq (vector unsigned int, a1, vector unsigned short, a2), \       (vector unsigned int) __builtin_altivec_vsl ((vector signed int) a1, (vector signed int) a2), \ __ch (__bin_args_eq (vector unsigned int, a1, vector unsigned char, a2), \       (vector unsigned int) __builtin_altivec_vsl ((vector signed int) a1, (vector signed int) a2), \ __ch (__bin_args_eq (vector signed short, a1, vector unsigned int, a2), \       (vector signed short) __builtin_altivec_vsl ((vector signed int) a1, (vector signed int) a2), \ __ch (__bin_args_eq (vector signed short, a1, vector unsigned short, a2), \       (vector signed short) __builtin_altivec_vsl ((vector signed int) a1, (vector signed int) a2), \ __ch (__bin_args_eq (vector signed short, a1, vector unsigned char, a2), \       (vector signed short) __builtin_altivec_vsl ((vector signed int) a1, (vector signed int) a2), \ __ch (__bin_args_eq (vector unsigned short, a1, vector unsigned int, a2), \       (vector unsigned short) __builtin_altivec_vsl ((vector signed int) a1, (vector signed int) a2), \ __ch (__bin_args_eq (vector unsigned short, a1, vector unsigned short, a2), \       (vector unsigned short) __builtin_altivec_vsl ((vector signed int) a1, (vector signed int) a2), \ __ch (__bin_args_eq (vector unsigned short, a1, vector unsigned char, a2), \       (vector unsigned short) __builtin_altivec_vsl ((vector signed int) a1, (vector signed int) a2), \ __ch (__bin_args_eq (vector signed char, a1, vector unsigned int, a2), \       (vector signed char) __builtin_altivec_vsl ((vector signed int) a1, (vector signed int) a2), \ __ch (__bin_args_eq (vector signed char, a1, vector unsigned short, a2), \       (vector signed char) __builtin_altivec_vsl ((vector signed int) a1, (vector signed int) a2), \ __ch (__bin_args_eq (vector signed char, a1, vector unsigned char, a2), \       (vector signed char) __builtin_altivec_vsl ((vector signed int) a1, (vector signed int) a2), \ __ch (__bin_args_eq (vector unsigned char, a1, vector unsigned int, a2), \       (vector unsigned char) __builtin_altivec_vsl ((vector signed int) a1, (vector signed int) a2), \ __ch (__bin_args_eq (vector unsigned char, a1, vector unsigned short, a2), \       (vector unsigned char) __builtin_altivec_vsl ((vector signed int) a1, (vector signed int) a2), \ __ch (__bin_args_eq (vector unsigned char, a1, vector unsigned char, a2), \       (vector unsigned char) __builtin_altivec_vsl ((vector signed int) a1, (vector signed int) a2), \     __altivec_link_error_invalid_argument ()))))))))))))))))))
end_define

begin_define
define|#
directive|define
name|vec_slo
parameter_list|(
name|a1
parameter_list|,
name|a2
parameter_list|)
define|\
value|__ch (__bin_args_eq (vector float, a1, vector signed char, a2), \       (vector float) __builtin_altivec_vslo ((vector signed int) a1, (vector signed int) a2), \ __ch (__bin_args_eq (vector float, a1, vector unsigned char, a2), \       (vector float) __builtin_altivec_vslo ((vector signed int) a1, (vector signed int) a2), \ __ch (__bin_args_eq (vector signed int, a1, vector signed char, a2), \       (vector signed int) __builtin_altivec_vslo ((vector signed int) a1, (vector signed int) a2), \ __ch (__bin_args_eq (vector signed int, a1, vector unsigned char, a2), \       (vector signed int) __builtin_altivec_vslo ((vector signed int) a1, (vector signed int) a2), \ __ch (__bin_args_eq (vector unsigned int, a1, vector signed char, a2), \       (vector unsigned int) __builtin_altivec_vslo ((vector signed int) a1, (vector signed int) a2), \ __ch (__bin_args_eq (vector unsigned int, a1, vector unsigned char, a2), \       (vector unsigned int) __builtin_altivec_vslo ((vector signed int) a1, (vector signed int) a2), \ __ch (__bin_args_eq (vector signed short, a1, vector signed char, a2), \       (vector signed short) __builtin_altivec_vslo ((vector signed int) a1, (vector signed int) a2), \ __ch (__bin_args_eq (vector signed short, a1, vector unsigned char, a2), \       (vector signed short) __builtin_altivec_vslo ((vector signed int) a1, (vector signed int) a2), \ __ch (__bin_args_eq (vector unsigned short, a1, vector signed char, a2), \       (vector unsigned short) __builtin_altivec_vslo ((vector signed int) a1, (vector signed int) a2), \ __ch (__bin_args_eq (vector unsigned short, a1, vector unsigned char, a2), \       (vector unsigned short) __builtin_altivec_vslo ((vector signed int) a1, (vector signed int) a2), \ __ch (__bin_args_eq (vector signed char, a1, vector signed char, a2), \       (vector signed char) __builtin_altivec_vslo ((vector signed int) a1, (vector signed int) a2), \ __ch (__bin_args_eq (vector signed char, a1, vector unsigned char, a2), \       (vector signed char) __builtin_altivec_vslo ((vector signed int) a1, (vector signed int) a2), \ __ch (__bin_args_eq (vector unsigned char, a1, vector signed char, a2), \       (vector unsigned char) __builtin_altivec_vslo ((vector signed int) a1, (vector signed int) a2), \ __ch (__bin_args_eq (vector unsigned char, a1, vector unsigned char, a2), \       (vector unsigned char) __builtin_altivec_vslo ((vector signed int) a1, (vector signed int) a2), \     __altivec_link_error_invalid_argument ()))))))))))))))
end_define

begin_define
define|#
directive|define
name|vec_splat
parameter_list|(
name|a1
parameter_list|,
name|a2
parameter_list|)
define|\
value|__ch (__bin_args_eq (vector signed char, a1, const char, a2), \       (vector signed char) __builtin_altivec_vspltb ((vector signed char) a1, (const char) a2), \ __ch (__bin_args_eq (vector unsigned char, a1, const char, a2), \       (vector unsigned char) __builtin_altivec_vspltb ((vector signed char) a1, (const char) a2), \ __ch (__bin_args_eq (vector signed short, a1, const char, a2), \       (vector signed short) __builtin_altivec_vsplth ((vector signed short) a1, (const char) a2), \ __ch (__bin_args_eq (vector unsigned short, a1, const char, a2), \       (vector unsigned short) __builtin_altivec_vsplth ((vector signed short) a1, (const char) a2), \ __ch (__bin_args_eq (vector float, a1, const char, a2), \       (vector float) __builtin_altivec_vspltw ((vector signed int) a1, (const char) a2), \ __ch (__bin_args_eq (vector signed int, a1, const char, a2), \       (vector signed int) __builtin_altivec_vspltw ((vector signed int) a1, (const char) a2), \ __ch (__bin_args_eq (vector unsigned int, a1, const char, a2), \       (vector unsigned int) __builtin_altivec_vspltw ((vector signed int) a1, (const char) a2), \     __altivec_link_error_invalid_argument ())))))))
end_define

begin_define
define|#
directive|define
name|vec_splat_s8
parameter_list|(
name|a1
parameter_list|)
value|__builtin_altivec_vspltisb (a1)
end_define

begin_define
define|#
directive|define
name|vec_splat_s16
parameter_list|(
name|a1
parameter_list|)
value|__builtin_altivec_vspltish (a1)
end_define

begin_define
define|#
directive|define
name|vec_splat_s32
parameter_list|(
name|a1
parameter_list|)
value|__builtin_altivec_vspltisw (a1)
end_define

begin_define
define|#
directive|define
name|vec_splat_u8
parameter_list|(
name|a1
parameter_list|)
value|__builtin_altivec_vspltisb (a1)
end_define

begin_define
define|#
directive|define
name|vec_splat_u16
parameter_list|(
name|a1
parameter_list|)
value|__builtin_altivec_vspltish (a1)
end_define

begin_define
define|#
directive|define
name|vec_splat_u32
parameter_list|(
name|a1
parameter_list|)
value|__builtin_altivec_vspltisw (a1)
end_define

begin_define
define|#
directive|define
name|vec_sr
parameter_list|(
name|a1
parameter_list|,
name|a2
parameter_list|)
define|\
value|__ch (__bin_args_eq (vector signed char, a1, vector unsigned char, a2), \       (vector signed char) __builtin_altivec_vsrb ((vector signed char) a1, (vector signed char) a2), \ __ch (__bin_args_eq (vector unsigned char, a1, vector unsigned char, a2), \       (vector unsigned char) __builtin_altivec_vsrb ((vector signed char) a1, (vector signed char) a2), \ __ch (__bin_args_eq (vector signed short, a1, vector unsigned short, a2), \       (vector signed short) __builtin_altivec_vsrh ((vector signed short) a1, (vector signed short) a2), \ __ch (__bin_args_eq (vector unsigned short, a1, vector unsigned short, a2), \       (vector unsigned short) __builtin_altivec_vsrh ((vector signed short) a1, (vector signed short) a2), \ __ch (__bin_args_eq (vector signed int, a1, vector unsigned int, a2), \       (vector signed int) __builtin_altivec_vsrw ((vector signed int) a1, (vector signed int) a2), \ __ch (__bin_args_eq (vector unsigned int, a1, vector unsigned int, a2), \       (vector unsigned int) __builtin_altivec_vsrw ((vector signed int) a1, (vector signed int) a2), \     __altivec_link_error_invalid_argument ()))))))
end_define

begin_define
define|#
directive|define
name|vec_sra
parameter_list|(
name|a1
parameter_list|,
name|a2
parameter_list|)
define|\
value|__ch (__bin_args_eq (vector signed char, a1, vector unsigned char, a2), \       (vector signed char) __builtin_altivec_vsrab ((vector signed char) a1, (vector signed char) a2), \ __ch (__bin_args_eq (vector unsigned char, a1, vector unsigned char, a2), \       (vector unsigned char) __builtin_altivec_vsrab ((vector signed char) a1, (vector signed char) a2), \ __ch (__bin_args_eq (vector signed short, a1, vector unsigned short, a2), \       (vector signed short) __builtin_altivec_vsrah ((vector signed short) a1, (vector signed short) a2), \ __ch (__bin_args_eq (vector unsigned short, a1, vector unsigned short, a2), \       (vector unsigned short) __builtin_altivec_vsrah ((vector signed short) a1, (vector signed short) a2), \ __ch (__bin_args_eq (vector signed int, a1, vector unsigned int, a2), \       (vector signed int) __builtin_altivec_vsraw ((vector signed int) a1, (vector signed int) a2), \ __ch (__bin_args_eq (vector unsigned int, a1, vector unsigned int, a2), \       (vector unsigned int) __builtin_altivec_vsraw ((vector signed int) a1, (vector signed int) a2), \     __altivec_link_error_invalid_argument ()))))))
end_define

begin_define
define|#
directive|define
name|vec_srl
parameter_list|(
name|a1
parameter_list|,
name|a2
parameter_list|)
define|\
value|__ch (__bin_args_eq (vector signed int, a1, vector unsigned int, a2), \       (vector signed int) __builtin_altivec_vsr ((vector signed int) a1, (vector signed int) a2), \ __ch (__bin_args_eq (vector signed int, a1, vector unsigned short, a2), \       (vector signed int) __builtin_altivec_vsr ((vector signed int) a1, (vector signed int) a2), \ __ch (__bin_args_eq (vector signed int, a1, vector unsigned char, a2), \       (vector signed int) __builtin_altivec_vsr ((vector signed int) a1, (vector signed int) a2), \ __ch (__bin_args_eq (vector unsigned int, a1, vector unsigned int, a2), \       (vector unsigned int) __builtin_altivec_vsr ((vector signed int) a1, (vector signed int) a2), \ __ch (__bin_args_eq (vector unsigned int, a1, vector unsigned short, a2), \       (vector unsigned int) __builtin_altivec_vsr ((vector signed int) a1, (vector signed int) a2), \ __ch (__bin_args_eq (vector unsigned int, a1, vector unsigned char, a2), \       (vector unsigned int) __builtin_altivec_vsr ((vector signed int) a1, (vector signed int) a2), \ __ch (__bin_args_eq (vector signed short, a1, vector unsigned int, a2), \       (vector signed short) __builtin_altivec_vsr ((vector signed int) a1, (vector signed int) a2), \ __ch (__bin_args_eq (vector signed short, a1, vector unsigned short, a2), \       (vector signed short) __builtin_altivec_vsr ((vector signed int) a1, (vector signed int) a2), \ __ch (__bin_args_eq (vector signed short, a1, vector unsigned char, a2), \       (vector signed short) __builtin_altivec_vsr ((vector signed int) a1, (vector signed int) a2), \ __ch (__bin_args_eq (vector unsigned short, a1, vector unsigned int, a2), \       (vector unsigned short) __builtin_altivec_vsr ((vector signed int) a1, (vector signed int) a2), \ __ch (__bin_args_eq (vector unsigned short, a1, vector unsigned short, a2), \       (vector unsigned short) __builtin_altivec_vsr ((vector signed int) a1, (vector signed int) a2), \ __ch (__bin_args_eq (vector unsigned short, a1, vector unsigned char, a2), \       (vector unsigned short) __builtin_altivec_vsr ((vector signed int) a1, (vector signed int) a2), \ __ch (__bin_args_eq (vector signed char, a1, vector unsigned int, a2), \       (vector signed char) __builtin_altivec_vsr ((vector signed int) a1, (vector signed int) a2), \ __ch (__bin_args_eq (vector signed char, a1, vector unsigned short, a2), \       (vector signed char) __builtin_altivec_vsr ((vector signed int) a1, (vector signed int) a2), \ __ch (__bin_args_eq (vector signed char, a1, vector unsigned char, a2), \       (vector signed char) __builtin_altivec_vsr ((vector signed int) a1, (vector signed int) a2), \ __ch (__bin_args_eq (vector unsigned char, a1, vector unsigned int, a2), \       (vector unsigned char) __builtin_altivec_vsr ((vector signed int) a1, (vector signed int) a2), \ __ch (__bin_args_eq (vector unsigned char, a1, vector unsigned short, a2), \       (vector unsigned char) __builtin_altivec_vsr ((vector signed int) a1, (vector signed int) a2), \ __ch (__bin_args_eq (vector unsigned char, a1, vector unsigned char, a2), \       (vector unsigned char) __builtin_altivec_vsr ((vector signed int) a1, (vector signed int) a2), \     __altivec_link_error_invalid_argument ()))))))))))))))))))
end_define

begin_define
define|#
directive|define
name|vec_sro
parameter_list|(
name|a1
parameter_list|,
name|a2
parameter_list|)
define|\
value|__ch (__bin_args_eq (vector float, a1, vector signed char, a2), \       (vector float) __builtin_altivec_vsro ((vector signed int) a1, (vector signed int) a2), \ __ch (__bin_args_eq (vector float, a1, vector unsigned char, a2), \       (vector float) __builtin_altivec_vsro ((vector signed int) a1, (vector signed int) a2), \ __ch (__bin_args_eq (vector signed int, a1, vector signed char, a2), \       (vector signed int) __builtin_altivec_vsro ((vector signed int) a1, (vector signed int) a2), \ __ch (__bin_args_eq (vector signed int, a1, vector unsigned char, a2), \       (vector signed int) __builtin_altivec_vsro ((vector signed int) a1, (vector signed int) a2), \ __ch (__bin_args_eq (vector unsigned int, a1, vector signed char, a2), \       (vector unsigned int) __builtin_altivec_vsro ((vector signed int) a1, (vector signed int) a2), \ __ch (__bin_args_eq (vector unsigned int, a1, vector unsigned char, a2), \       (vector unsigned int) __builtin_altivec_vsro ((vector signed int) a1, (vector signed int) a2), \ __ch (__bin_args_eq (vector signed short, a1, vector signed char, a2), \       (vector signed short) __builtin_altivec_vsro ((vector signed int) a1, (vector signed int) a2), \ __ch (__bin_args_eq (vector signed short, a1, vector unsigned char, a2), \       (vector signed short) __builtin_altivec_vsro ((vector signed int) a1, (vector signed int) a2), \ __ch (__bin_args_eq (vector unsigned short, a1, vector signed char, a2), \       (vector unsigned short) __builtin_altivec_vsro ((vector signed int) a1, (vector signed int) a2), \ __ch (__bin_args_eq (vector unsigned short, a1, vector unsigned char, a2), \       (vector unsigned short) __builtin_altivec_vsro ((vector signed int) a1, (vector signed int) a2), \ __ch (__bin_args_eq (vector signed char, a1, vector signed char, a2), \       (vector signed char) __builtin_altivec_vsro ((vector signed int) a1, (vector signed int) a2), \ __ch (__bin_args_eq (vector signed char, a1, vector unsigned char, a2), \       (vector signed char) __builtin_altivec_vsro ((vector signed int) a1, (vector signed int) a2), \ __ch (__bin_args_eq (vector unsigned char, a1, vector signed char, a2), \       (vector unsigned char) __builtin_altivec_vsro ((vector signed int) a1, (vector signed int) a2), \ __ch (__bin_args_eq (vector unsigned char, a1, vector unsigned char, a2), \       (vector unsigned char) __builtin_altivec_vsro ((vector signed int) a1, (vector signed int) a2), \     __altivec_link_error_invalid_argument ()))))))))))))))
end_define

begin_define
define|#
directive|define
name|vec_st
parameter_list|(
name|a1
parameter_list|,
name|a2
parameter_list|,
name|a3
parameter_list|)
define|\
value|__builtin_altivec_stvx ((vector signed int) a1, a2, a3)
end_define

begin_define
define|#
directive|define
name|vec_stl
parameter_list|(
name|a1
parameter_list|,
name|a2
parameter_list|,
name|a3
parameter_list|)
define|\
value|__builtin_altivec_stvxl ((vector signed int) a1, a2, a3)
end_define

begin_define
define|#
directive|define
name|vec_ste
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|)
define|\
value|__ch (__un_args_eq (vector unsigned char, a), \       __builtin_altivec_stvebx ((vector signed char) a, b, c), \ __ch (__un_args_eq (vector signed char, a), \       __builtin_altivec_stvebx ((vector signed char) a, b, c), \ __ch (__un_args_eq (vector unsigned short, a), \      __builtin_altivec_stvehx ((vector signed short) a, b, c), \ __ch (__un_args_eq (vector signed short, a), \      __builtin_altivec_stvehx ((vector signed short) a, b, c), \ __ch (__un_args_eq (vector unsigned int, a), \      __builtin_altivec_stvewx ((vector signed int) a, b, c), \ __ch (__un_args_eq (vector signed int, a), \      __builtin_altivec_stvewx ((vector signed int) a, b, c), \ __ch (__un_args_eq (vector float, a), \      __builtin_altivec_stvewx ((vector signed int) a, b, c), \      __altivec_link_error_invalid_argument ())))))))
end_define

begin_define
define|#
directive|define
name|vec_sub
parameter_list|(
name|a1
parameter_list|,
name|a2
parameter_list|)
define|\
value|__ch (__bin_args_eq (vector signed char, a1, vector signed char, a2), \       (vector signed char) __builtin_altivec_vsububm ((vector signed char) a1, (vector signed char) a2), \ __ch (__bin_args_eq (vector signed char, a1, vector unsigned char, a2), \       (vector unsigned char) __builtin_altivec_vsububm ((vector signed char) a1, (vector signed char) a2), \ __ch (__bin_args_eq (vector unsigned char, a1, vector signed char, a2), \       (vector unsigned char) __builtin_altivec_vsububm ((vector signed char) a1, (vector signed char) a2), \ __ch (__bin_args_eq (vector unsigned char, a1, vector unsigned char, a2), \       (vector unsigned char) __builtin_altivec_vsububm ((vector signed char) a1, (vector signed char) a2), \ __ch (__bin_args_eq (vector signed short, a1, vector signed short, a2), \       (vector signed short) __builtin_altivec_vsubuhm ((vector signed short) a1, (vector signed short) a2), \ __ch (__bin_args_eq (vector signed short, a1, vector unsigned short, a2), \       (vector unsigned short) __builtin_altivec_vsubuhm ((vector signed short) a1, (vector signed short) a2), \ __ch (__bin_args_eq (vector unsigned short, a1, vector signed short, a2), \       (vector unsigned short) __builtin_altivec_vsubuhm ((vector signed short) a1, (vector signed short) a2), \ __ch (__bin_args_eq (vector unsigned short, a1, vector unsigned short, a2), \       (vector unsigned short) __builtin_altivec_vsubuhm ((vector signed short) a1, (vector signed short) a2), \ __ch (__bin_args_eq (vector signed int, a1, vector signed int, a2), \       (vector signed int) __builtin_altivec_vsubuwm ((vector signed int) a1, (vector signed int) a2), \ __ch (__bin_args_eq (vector signed int, a1, vector unsigned int, a2), \       (vector unsigned int) __builtin_altivec_vsubuwm ((vector signed int) a1, (vector signed int) a2), \ __ch (__bin_args_eq (vector unsigned int, a1, vector signed int, a2), \       (vector unsigned int) __builtin_altivec_vsubuwm ((vector signed int) a1, (vector signed int) a2), \ __ch (__bin_args_eq (vector unsigned int, a1, vector unsigned int, a2), \       (vector unsigned int) __builtin_altivec_vsubuwm ((vector signed int) a1, (vector signed int) a2), \ __ch (__bin_args_eq (vector float, a1, vector float, a2), \       (vector float) __builtin_altivec_vsubfp ((vector float) a1, (vector float) a2), \     __altivec_link_error_invalid_argument ())))))))))))))
end_define

begin_define
define|#
directive|define
name|vec_subc
parameter_list|(
name|a1
parameter_list|,
name|a2
parameter_list|)
value|__builtin_altivec_vsubcuw (a1, a2)
end_define

begin_define
define|#
directive|define
name|vec_subs
parameter_list|(
name|a1
parameter_list|,
name|a2
parameter_list|)
define|\
value|__ch (__bin_args_eq (vector signed char, a1, vector unsigned char, a2), \       (vector unsigned char) __builtin_altivec_vsububs ((vector signed char) a1, (vector signed char) a2), \ __ch (__bin_args_eq (vector unsigned char, a1, vector signed char, a2), \       (vector unsigned char) __builtin_altivec_vsububs ((vector signed char) a1, (vector signed char) a2), \ __ch (__bin_args_eq (vector unsigned char, a1, vector unsigned char, a2), \       (vector unsigned char) __builtin_altivec_vsububs ((vector signed char) a1, (vector signed char) a2), \ __ch (__bin_args_eq (vector signed char, a1, vector signed char, a2), \       (vector signed char) __builtin_altivec_vsubsbs ((vector signed char) a1, (vector signed char) a2), \ __ch (__bin_args_eq (vector signed short, a1, vector unsigned short, a2), \       (vector unsigned short) __builtin_altivec_vsubuhs ((vector signed short) a1, (vector signed short) a2), \ __ch (__bin_args_eq (vector unsigned short, a1, vector signed short, a2), \       (vector unsigned short) __builtin_altivec_vsubuhs ((vector signed short) a1, (vector signed short) a2), \ __ch (__bin_args_eq (vector unsigned short, a1, vector unsigned short, a2), \       (vector unsigned short) __builtin_altivec_vsubuhs ((vector signed short) a1, (vector signed short) a2), \ __ch (__bin_args_eq (vector signed short, a1, vector signed short, a2), \       (vector signed short) __builtin_altivec_vsubshs ((vector signed short) a1, (vector signed short) a2), \ __ch (__bin_args_eq (vector signed int, a1, vector unsigned int, a2), \       (vector unsigned int) __builtin_altivec_vsubuws ((vector signed int) a1, (vector signed int) a2), \ __ch (__bin_args_eq (vector unsigned int, a1, vector signed int, a2), \       (vector unsigned int) __builtin_altivec_vsubuws ((vector signed int) a1, (vector signed int) a2), \ __ch (__bin_args_eq (vector unsigned int, a1, vector unsigned int, a2), \       (vector unsigned int) __builtin_altivec_vsubuws ((vector signed int) a1, (vector signed int) a2), \ __ch (__bin_args_eq (vector signed int, a1, vector signed int, a2), \       (vector signed int) __builtin_altivec_vsubsws ((vector signed int) a1, (vector signed int) a2), \     __altivec_link_error_invalid_argument ()))))))))))))
end_define

begin_define
define|#
directive|define
name|vec_sum4s
parameter_list|(
name|a1
parameter_list|,
name|a2
parameter_list|)
define|\
value|__ch (__bin_args_eq (vector unsigned char, a1, vector unsigned int, a2), \       (vector unsigned int) __builtin_altivec_vsum4ubs ((vector signed char) a1, (vector signed int) a2), \ __ch (__bin_args_eq (vector signed char, a1, vector signed int, a2), \       (vector signed int) __builtin_altivec_vsum4sbs ((vector signed char) a1, (vector signed int) a2), \ __ch (__bin_args_eq (vector signed short, a1, vector signed int, a2), \       (vector signed int) __builtin_altivec_vsum4shs ((vector signed short) a1, (vector signed int) a2), \     __altivec_link_error_invalid_argument ())))
end_define

begin_define
define|#
directive|define
name|vec_sum2s
parameter_list|(
name|a1
parameter_list|,
name|a2
parameter_list|)
value|__builtin_altivec_vsum2sws (a1, a2)
end_define

begin_define
define|#
directive|define
name|vec_sums
parameter_list|(
name|a1
parameter_list|,
name|a2
parameter_list|)
value|__builtin_altivec_vsumsws (a1, a2)
end_define

begin_define
define|#
directive|define
name|vec_trunc
parameter_list|(
name|a1
parameter_list|)
value|__builtin_altivec_vrfiz (a1)
end_define

begin_define
define|#
directive|define
name|vec_unpackh
parameter_list|(
name|a1
parameter_list|)
define|\
value|__ch (__un_args_eq (vector signed char, a1), \       (vector signed short) __builtin_altivec_vupkhsb ((vector signed char) a1), \ __ch (__un_args_eq (vector signed short, a1), \       (vector unsigned int) __builtin_altivec_vupkhpx ((vector signed short) a1), \ __ch (__un_args_eq (vector signed short, a1), \       (vector signed int) __builtin_altivec_vupkhsh ((vector signed short) a1), \     __altivec_link_error_invalid_argument ())))
end_define

begin_define
define|#
directive|define
name|vec_unpackl
parameter_list|(
name|a1
parameter_list|)
define|\
value|__ch (__un_args_eq (vector signed char, a1), \       (vector signed short) __builtin_altivec_vupklsb ((vector signed char) a1), \ __ch (__un_args_eq (vector signed short, a1), \       (vector unsigned int) __builtin_altivec_vupklpx ((vector signed short) a1), \ __ch (__un_args_eq (vector signed short, a1), \       (vector signed int) __builtin_altivec_vupklsh ((vector signed short) a1), \     __altivec_link_error_invalid_argument ())))
end_define

begin_define
define|#
directive|define
name|vec_xor
parameter_list|(
name|a1
parameter_list|,
name|a2
parameter_list|)
define|\
value|__ch (__bin_args_eq (vector float, a1, vector float, a2), \       (vector float) __builtin_altivec_vxor ((vector signed int) a1, (vector signed int) a2), \ __ch (__bin_args_eq (vector float, a1, vector signed int, a2), \       (vector float) __builtin_altivec_vxor ((vector signed int) a1, (vector signed int) a2), \ __ch (__bin_args_eq (vector signed int, a1, vector float, a2), \       (vector float) __builtin_altivec_vxor ((vector signed int) a1, (vector signed int) a2), \ __ch (__bin_args_eq (vector signed int, a1, vector signed int, a2), \       (vector signed int) __builtin_altivec_vxor ((vector signed int) a1, (vector signed int) a2), \ __ch (__bin_args_eq (vector signed int, a1, vector unsigned int, a2), \       (vector unsigned int) __builtin_altivec_vxor ((vector signed int) a1, (vector signed int) a2), \ __ch (__bin_args_eq (vector unsigned int, a1, vector signed int, a2), \       (vector unsigned int) __builtin_altivec_vxor ((vector signed int) a1, (vector signed int) a2), \ __ch (__bin_args_eq (vector unsigned int, a1, vector unsigned int, a2), \       (vector unsigned int) __builtin_altivec_vxor ((vector signed int) a1, (vector signed int) a2), \ __ch (__bin_args_eq (vector signed short, a1, vector signed short, a2), \       (vector signed short) __builtin_altivec_vxor ((vector signed int) a1, (vector signed int) a2), \ __ch (__bin_args_eq (vector signed short, a1, vector unsigned short, a2), \       (vector unsigned short) __builtin_altivec_vxor ((vector signed int) a1, (vector signed int) a2), \ __ch (__bin_args_eq (vector unsigned short, a1, vector signed short, a2), \       (vector unsigned short) __builtin_altivec_vxor ((vector signed int) a1, (vector signed int) a2), \ __ch (__bin_args_eq (vector unsigned short, a1, vector unsigned short, a2), \       (vector unsigned short) __builtin_altivec_vxor ((vector signed int) a1, (vector signed int) a2), \ __ch (__bin_args_eq (vector signed char, a1, vector signed char, a2), \       (vector signed char) __builtin_altivec_vxor ((vector signed int) a1, (vector signed int) a2), \ __ch (__bin_args_eq (vector signed char, a1, vector unsigned char, a2), \       (vector unsigned char) __builtin_altivec_vxor ((vector signed int) a1, (vector signed int) a2), \ __ch (__bin_args_eq (vector unsigned char, a1, vector signed char, a2), \       (vector unsigned char) __builtin_altivec_vxor ((vector signed int) a1, (vector signed int) a2), \ __ch (__bin_args_eq (vector unsigned char, a1, vector unsigned char, a2), \       (vector unsigned char) __builtin_altivec_vxor ((vector signed int) a1, (vector signed int) a2), \     __altivec_link_error_invalid_argument ())))))))))))))))
end_define

begin_define
define|#
directive|define
name|vec_all_eq
parameter_list|(
name|a1
parameter_list|,
name|a2
parameter_list|)
define|\
value|__ch (__bin_args_eq (vector signed char, a1, vector unsigned char, a2), \       (vector signed int) __builtin_altivec_vcmpequb_p ((vector signed char) a1, (vector signed char) a2), \ __ch (__bin_args_eq (vector signed char, a1, vector signed char, a2), \       (vector signed int) __builtin_altivec_vcmpequb_p ((vector signed char) a1, (vector signed char) a2), \ __ch (__bin_args_eq (vector unsigned char, a1, vector signed char, a2), \       (vector signed int) __builtin_altivec_vcmpequb_p ((vector signed char) a1, (vector signed char) a2), \ __ch (__bin_args_eq (vector unsigned char, a1, vector unsigned char, a2), \       (vector signed int) __builtin_altivec_vcmpequb_p ((vector signed char) a1, (vector signed char) a2), \ __ch (__bin_args_eq (vector signed short, a1, vector unsigned short, a2), \       (vector signed int) __builtin_altivec_vcmpequh_p ((vector signed short) a1, (vector signed short) a2), \ __ch (__bin_args_eq (vector signed short, a1, vector signed short, a2), \       (vector signed int) __builtin_altivec_vcmpequh_p ((vector signed short) a1, (vector signed short) a2), \ __ch (__bin_args_eq (vector unsigned short, a1, vector signed short, a2), \       (vector signed int) __builtin_altivec_vcmpequh_p ((vector signed short) a1, (vector signed short) a2), \ __ch (__bin_args_eq (vector unsigned short, a1, vector unsigned short, a2), \       (vector signed int) __builtin_altivec_vcmpequh_p ((vector signed short) a1, (vector signed short) a2), \ __ch (__bin_args_eq (vector signed int, a1, vector unsigned int, a2), \       (vector signed int) __builtin_altivec_vcmpequw_p ((vector signed int) a1, (vector signed int) a2), \ __ch (__bin_args_eq (vector signed int, a1, vector signed int, a2), \       (vector signed int) __builtin_altivec_vcmpequw_p ((vector signed int) a1, (vector signed int) a2), \ __ch (__bin_args_eq (vector unsigned int, a1, vector signed int, a2), \       (vector signed int) __builtin_altivec_vcmpequw_p ((vector signed int) a1, (vector signed int) a2), \ __ch (__bin_args_eq (vector unsigned int, a1, vector unsigned int, a2), \       (vector signed int) __builtin_altivec_vcmpequw_p ((vector signed int) a1, (vector signed int) a2), \ __ch (__bin_args_eq (vector float, a1, vector float, a2), \       (vector signed int) __builtin_altivec_vcmpeqfp_p ((vector float) a1, (vector float) a2), \     __altivec_link_error_invalid_argument ())))))))))))))
end_define

begin_define
define|#
directive|define
name|vec_all_ge
parameter_list|(
name|a1
parameter_list|,
name|a2
parameter_list|)
define|\
value|__ch (__bin_args_eq (vector signed char, a1, vector unsigned char, a2), \       (vector signed int) __builtin_altivec_vcmpgtub_p ((vector signed char) a1, (vector signed char) a2), \ __ch (__bin_args_eq (vector unsigned char, a1, vector signed char, a2), \       (vector signed int) __builtin_altivec_vcmpgtub_p ((vector signed char) a1, (vector signed char) a2), \ __ch (__bin_args_eq (vector unsigned char, a1, vector unsigned char, a2), \       (vector signed int) __builtin_altivec_vcmpgtub_p ((vector signed char) a1, (vector signed char) a2), \ __ch (__bin_args_eq (vector signed char, a1, vector signed char, a2), \       (vector signed int) __builtin_altivec_vcmpgtsb_p ((vector signed char) a1, (vector signed char) a2), \ __ch (__bin_args_eq (vector signed short, a1, vector unsigned short, a2), \       (vector signed int) __builtin_altivec_vcmpgtuh_p ((vector signed short) a1, (vector signed short) a2), \ __ch (__bin_args_eq (vector unsigned short, a1, vector signed short, a2), \       (vector signed int) __builtin_altivec_vcmpgtuh_p ((vector signed short) a1, (vector signed short) a2), \ __ch (__bin_args_eq (vector unsigned short, a1, vector unsigned short, a2), \       (vector signed int) __builtin_altivec_vcmpgtuh_p ((vector signed short) a1, (vector signed short) a2), \ __ch (__bin_args_eq (vector signed short, a1, vector signed short, a2), \       (vector signed int) __builtin_altivec_vcmpgtsh_p ((vector signed short) a1, (vector signed short) a2), \ __ch (__bin_args_eq (vector signed int, a1, vector unsigned int, a2), \       (vector signed int) __builtin_altivec_vcmpgtuw_p ((vector signed int) a1, (vector signed int) a2), \ __ch (__bin_args_eq (vector unsigned int, a1, vector signed int, a2), \       (vector signed int) __builtin_altivec_vcmpgtuw_p ((vector signed int) a1, (vector signed int) a2), \ __ch (__bin_args_eq (vector unsigned int, a1, vector unsigned int, a2), \       (vector signed int) __builtin_altivec_vcmpgtuw_p ((vector signed int) a1, (vector signed int) a2), \ __ch (__bin_args_eq (vector signed int, a1, vector signed int, a2), \       (vector signed int) __builtin_altivec_vcmpgtsw_p ((vector signed int) a1, (vector signed int) a2), \ __ch (__bin_args_eq (vector float, a1, vector float, a2), \       (vector signed int) __builtin_altivec_vcmpgefp_p ((vector float) a1, (vector float) a2), \     __altivec_link_error_invalid_argument ())))))))))))))
end_define

begin_define
define|#
directive|define
name|vec_all_gt
parameter_list|(
name|a1
parameter_list|,
name|a2
parameter_list|)
define|\
value|__ch (__bin_args_eq (vector signed char, a1, vector unsigned char, a2), \       (vector signed int) __builtin_altivec_vcmpgtub_p ((vector signed char) a1, (vector signed char) a2), \ __ch (__bin_args_eq (vector unsigned char, a1, vector signed char, a2), \       (vector signed int) __builtin_altivec_vcmpgtub_p ((vector signed char) a1, (vector signed char) a2), \ __ch (__bin_args_eq (vector unsigned char, a1, vector unsigned char, a2), \       (vector signed int) __builtin_altivec_vcmpgtub_p ((vector signed char) a1, (vector signed char) a2), \ __ch (__bin_args_eq (vector signed char, a1, vector signed char, a2), \       (vector signed int) __builtin_altivec_vcmpgtsb_p ((vector signed char) a1, (vector signed char) a2), \ __ch (__bin_args_eq (vector signed short, a1, vector unsigned short, a2), \       (vector signed int) __builtin_altivec_vcmpgtuh_p ((vector signed short) a1, (vector signed short) a2), \ __ch (__bin_args_eq (vector unsigned short, a1, vector signed short, a2), \       (vector signed int) __builtin_altivec_vcmpgtuh_p ((vector signed short) a1, (vector signed short) a2), \ __ch (__bin_args_eq (vector unsigned short, a1, vector unsigned short, a2), \       (vector signed int) __builtin_altivec_vcmpgtuh_p ((vector signed short) a1, (vector signed short) a2), \ __ch (__bin_args_eq (vector signed short, a1, vector signed short, a2), \       (vector signed int) __builtin_altivec_vcmpgtsh_p ((vector signed short) a1, (vector signed short) a2), \ __ch (__bin_args_eq (vector signed int, a1, vector unsigned int, a2), \       (vector signed int) __builtin_altivec_vcmpgtuw_p ((vector signed int) a1, (vector signed int) a2), \ __ch (__bin_args_eq (vector unsigned int, a1, vector signed int, a2), \       (vector signed int) __builtin_altivec_vcmpgtuw_p ((vector signed int) a1, (vector signed int) a2), \ __ch (__bin_args_eq (vector unsigned int, a1, vector unsigned int, a2), \       (vector signed int) __builtin_altivec_vcmpgtuw_p ((vector signed int) a1, (vector signed int) a2), \ __ch (__bin_args_eq (vector signed int, a1, vector signed int, a2), \       (vector signed int) __builtin_altivec_vcmpgtsw_p ((vector signed int) a1, (vector signed int) a2), \ __ch (__bin_args_eq (vector float, a1, vector float, a2), \       (vector signed int) __builtin_altivec_vcmpgtfp_p ((vector float) a1, (vector float) a2), \     __altivec_link_error_invalid_argument ())))))))))))))
end_define

begin_define
define|#
directive|define
name|vec_all_in
parameter_list|(
name|a1
parameter_list|,
name|a2
parameter_list|)
value|__builtin_altivec_vcmpbfp_p (a1, a2)
end_define

begin_define
define|#
directive|define
name|vec_all_le
parameter_list|(
name|a1
parameter_list|,
name|a2
parameter_list|)
define|\
value|__ch (__bin_args_eq (vector signed char, a1, vector unsigned char, a2), \       (vector signed int) __builtin_altivec_vcmpgtub_p ((vector signed char) a1, (vector signed char) a2), \ __ch (__bin_args_eq (vector unsigned char, a1, vector signed char, a2), \       (vector signed int) __builtin_altivec_vcmpgtub_p ((vector signed char) a1, (vector signed char) a2), \ __ch (__bin_args_eq (vector unsigned char, a1, vector unsigned char, a2), \       (vector signed int) __builtin_altivec_vcmpgtub_p ((vector signed char) a1, (vector signed char) a2), \ __ch (__bin_args_eq (vector signed char, a1, vector signed char, a2), \       (vector signed int) __builtin_altivec_vcmpgtsb_p ((vector signed char) a1, (vector signed char) a2), \ __ch (__bin_args_eq (vector signed short, a1, vector unsigned short, a2), \       (vector signed int) __builtin_altivec_vcmpgtuh_p ((vector signed short) a1, (vector signed short) a2), \ __ch (__bin_args_eq (vector unsigned short, a1, vector signed short, a2), \       (vector signed int) __builtin_altivec_vcmpgtuh_p ((vector signed short) a1, (vector signed short) a2), \ __ch (__bin_args_eq (vector unsigned short, a1, vector unsigned short, a2), \       (vector signed int) __builtin_altivec_vcmpgtuh_p ((vector signed short) a1, (vector signed short) a2), \ __ch (__bin_args_eq (vector signed short, a1, vector signed short, a2), \       (vector signed int) __builtin_altivec_vcmpgtsh_p ((vector signed short) a1, (vector signed short) a2), \ __ch (__bin_args_eq (vector signed int, a1, vector unsigned int, a2), \       (vector signed int) __builtin_altivec_vcmpgtuw_p ((vector signed int) a1, (vector signed int) a2), \ __ch (__bin_args_eq (vector unsigned int, a1, vector signed int, a2), \       (vector signed int) __builtin_altivec_vcmpgtuw_p ((vector signed int) a1, (vector signed int) a2), \ __ch (__bin_args_eq (vector unsigned int, a1, vector unsigned int, a2), \       (vector signed int) __builtin_altivec_vcmpgtuw_p ((vector signed int) a1, (vector signed int) a2), \ __ch (__bin_args_eq (vector signed int, a1, vector signed int, a2), \       (vector signed int) __builtin_altivec_vcmpgtsw_p ((vector signed int) a1, (vector signed int) a2), \ __ch (__bin_args_eq (vector float, a1, vector float, a2), \       (vector signed int) __builtin_altivec_vcmpgefp_p ((vector float) a1, (vector float) a2), \     __altivec_link_error_invalid_argument ())))))))))))))
end_define

begin_define
define|#
directive|define
name|vec_all_lt
parameter_list|(
name|a1
parameter_list|,
name|a2
parameter_list|)
define|\
value|__ch (__bin_args_eq (vector signed char, a1, vector unsigned char, a2), \       (vector signed int) __builtin_altivec_vcmpgtub_p ((vector signed char) a1, (vector signed char) a2), \ __ch (__bin_args_eq (vector unsigned char, a1, vector signed char, a2), \       (vector signed int) __builtin_altivec_vcmpgtub_p ((vector signed char) a1, (vector signed char) a2), \ __ch (__bin_args_eq (vector unsigned char, a1, vector unsigned char, a2), \       (vector signed int) __builtin_altivec_vcmpgtub_p ((vector signed char) a1, (vector signed char) a2), \ __ch (__bin_args_eq (vector signed char, a1, vector signed char, a2), \       (vector signed int) __builtin_altivec_vcmpgtsb_p ((vector signed char) a1, (vector signed char) a2), \ __ch (__bin_args_eq (vector signed short, a1, vector unsigned short, a2), \       (vector signed int) __builtin_altivec_vcmpgtuh_p ((vector signed short) a1, (vector signed short) a2), \ __ch (__bin_args_eq (vector unsigned short, a1, vector signed short, a2), \       (vector signed int) __builtin_altivec_vcmpgtuh_p ((vector signed short) a1, (vector signed short) a2), \ __ch (__bin_args_eq (vector unsigned short, a1, vector unsigned short, a2), \       (vector signed int) __builtin_altivec_vcmpgtuh_p ((vector signed short) a1, (vector signed short) a2), \ __ch (__bin_args_eq (vector signed short, a1, vector signed short, a2), \       (vector signed int) __builtin_altivec_vcmpgtsh_p ((vector signed short) a1, (vector signed short) a2), \ __ch (__bin_args_eq (vector signed int, a1, vector unsigned int, a2), \       (vector signed int) __builtin_altivec_vcmpgtuw_p ((vector signed int) a1, (vector signed int) a2), \ __ch (__bin_args_eq (vector unsigned int, a1, vector signed int, a2), \       (vector signed int) __builtin_altivec_vcmpgtuw_p ((vector signed int) a1, (vector signed int) a2), \ __ch (__bin_args_eq (vector unsigned int, a1, vector unsigned int, a2), \       (vector signed int) __builtin_altivec_vcmpgtuw_p ((vector signed int) a1, (vector signed int) a2), \ __ch (__bin_args_eq (vector signed int, a1, vector signed int, a2), \       (vector signed int) __builtin_altivec_vcmpgtsw_p ((vector signed int) a1, (vector signed int) a2), \ __ch (__bin_args_eq (vector float, a1, vector float, a2), \       (vector signed int) __builtin_altivec_vcmpgtfp_p ((vector float) a1, (vector float) a2), \     __altivec_link_error_invalid_argument ())))))))))))))
end_define

begin_define
define|#
directive|define
name|vec_all_nan
parameter_list|(
name|a1
parameter_list|)
value|__builtin_altivec_vcmpeqfp_p (a1)
end_define

begin_define
define|#
directive|define
name|vec_all_ne
parameter_list|(
name|a1
parameter_list|,
name|a2
parameter_list|)
define|\
value|__ch (__bin_args_eq (vector signed char, a1, vector unsigned char, a2), \       (vector signed int) __builtin_altivec_vcmpequb_p ((vector signed char) a1, (vector signed char) a2), \ __ch (__bin_args_eq (vector signed char, a1, vector signed char, a2), \       (vector signed int) __builtin_altivec_vcmpequb_p ((vector signed char) a1, (vector signed char) a2), \ __ch (__bin_args_eq (vector unsigned char, a1, vector signed char, a2), \       (vector signed int) __builtin_altivec_vcmpequb_p ((vector signed char) a1, (vector signed char) a2), \ __ch (__bin_args_eq (vector unsigned char, a1, vector unsigned char, a2), \       (vector signed int) __builtin_altivec_vcmpequb_p ((vector signed char) a1, (vector signed char) a2), \ __ch (__bin_args_eq (vector signed short, a1, vector unsigned short, a2), \       (vector signed int) __builtin_altivec_vcmpequh_p ((vector signed short) a1, (vector signed short) a2), \ __ch (__bin_args_eq (vector signed short, a1, vector signed short, a2), \       (vector signed int) __builtin_altivec_vcmpequh_p ((vector signed short) a1, (vector signed short) a2), \ __ch (__bin_args_eq (vector unsigned short, a1, vector signed short, a2), \       (vector signed int) __builtin_altivec_vcmpequh_p ((vector signed short) a1, (vector signed short) a2), \ __ch (__bin_args_eq (vector unsigned short, a1, vector unsigned short, a2), \       (vector signed int) __builtin_altivec_vcmpequh_p ((vector signed short) a1, (vector signed short) a2), \ __ch (__bin_args_eq (vector signed int, a1, vector unsigned int, a2), \       (vector signed int) __builtin_altivec_vcmpequw_p ((vector signed int) a1, (vector signed int) a2), \ __ch (__bin_args_eq (vector signed int, a1, vector signed int, a2), \       (vector signed int) __builtin_altivec_vcmpequw_p ((vector signed int) a1, (vector signed int) a2), \ __ch (__bin_args_eq (vector unsigned int, a1, vector signed int, a2), \       (vector signed int) __builtin_altivec_vcmpequw_p ((vector signed int) a1, (vector signed int) a2), \ __ch (__bin_args_eq (vector unsigned int, a1, vector unsigned int, a2), \       (vector signed int) __builtin_altivec_vcmpequw_p ((vector signed int) a1, (vector signed int) a2), \ __ch (__bin_args_eq (vector float, a1, vector float, a2), \       (vector signed int) __builtin_altivec_vcmpeqfp_p ((vector float) a1, (vector float) a2), \     __altivec_link_error_invalid_argument ())))))))))))))
end_define

begin_define
define|#
directive|define
name|vec_all_nge
parameter_list|(
name|a1
parameter_list|,
name|a2
parameter_list|)
value|__builtin_altivec_vcmpgefp_p (a1, a2)
end_define

begin_define
define|#
directive|define
name|vec_all_ngt
parameter_list|(
name|a1
parameter_list|,
name|a2
parameter_list|)
value|__builtin_altivec_vcmpgtfp_p (a1, a2)
end_define

begin_define
define|#
directive|define
name|vec_all_nle
parameter_list|(
name|a1
parameter_list|,
name|a2
parameter_list|)
value|__builtin_altivec_vcmpgefp_p (a1, a2)
end_define

begin_define
define|#
directive|define
name|vec_all_nlt
parameter_list|(
name|a1
parameter_list|,
name|a2
parameter_list|)
value|__builtin_altivec_vcmpgtfp_p (a1, a2)
end_define

begin_define
define|#
directive|define
name|vec_all_numeric
parameter_list|(
name|a1
parameter_list|)
value|__builtin_altivec_vcmpeqfp_p (a1)
end_define

begin_define
define|#
directive|define
name|vec_any_eq
parameter_list|(
name|a1
parameter_list|,
name|a2
parameter_list|)
define|\
value|__ch (__bin_args_eq (vector signed char, a1, vector unsigned char, a2), \       (vector signed int) __builtin_altivec_vcmpequb_p ((vector signed char) a1, (vector signed char) a2), \ __ch (__bin_args_eq (vector signed char, a1, vector signed char, a2), \       (vector signed int) __builtin_altivec_vcmpequb_p ((vector signed char) a1, (vector signed char) a2), \ __ch (__bin_args_eq (vector unsigned char, a1, vector signed char, a2), \       (vector signed int) __builtin_altivec_vcmpequb_p ((vector signed char) a1, (vector signed char) a2), \ __ch (__bin_args_eq (vector unsigned char, a1, vector unsigned char, a2), \       (vector signed int) __builtin_altivec_vcmpequb_p ((vector signed char) a1, (vector signed char) a2), \ __ch (__bin_args_eq (vector signed short, a1, vector unsigned short, a2), \       (vector signed int) __builtin_altivec_vcmpequh_p ((vector signed short) a1, (vector signed short) a2), \ __ch (__bin_args_eq (vector signed short, a1, vector signed short, a2), \       (vector signed int) __builtin_altivec_vcmpequh_p ((vector signed short) a1, (vector signed short) a2), \ __ch (__bin_args_eq (vector unsigned short, a1, vector signed short, a2), \       (vector signed int) __builtin_altivec_vcmpequh_p ((vector signed short) a1, (vector signed short) a2), \ __ch (__bin_args_eq (vector unsigned short, a1, vector unsigned short, a2), \       (vector signed int) __builtin_altivec_vcmpequh_p ((vector signed short) a1, (vector signed short) a2), \ __ch (__bin_args_eq (vector signed int, a1, vector unsigned int, a2), \       (vector signed int) __builtin_altivec_vcmpequw_p ((vector signed int) a1, (vector signed int) a2), \ __ch (__bin_args_eq (vector signed int, a1, vector signed int, a2), \       (vector signed int) __builtin_altivec_vcmpequw_p ((vector signed int) a1, (vector signed int) a2), \ __ch (__bin_args_eq (vector unsigned int, a1, vector signed int, a2), \       (vector signed int) __builtin_altivec_vcmpequw_p ((vector signed int) a1, (vector signed int) a2), \ __ch (__bin_args_eq (vector unsigned int, a1, vector unsigned int, a2), \       (vector signed int) __builtin_altivec_vcmpequw_p ((vector signed int) a1, (vector signed int) a2), \ __ch (__bin_args_eq (vector float, a1, vector float, a2), \       (vector signed int) __builtin_altivec_vcmpeqfp_p ((vector float) a1, (vector float) a2), \     __altivec_link_error_invalid_argument ())))))))))))))
end_define

begin_define
define|#
directive|define
name|vec_any_ge
parameter_list|(
name|a1
parameter_list|,
name|a2
parameter_list|)
define|\
value|__ch (__bin_args_eq (vector signed char, a1, vector unsigned char, a2), \       (vector signed int) __builtin_altivec_vcmpgtub_p ((vector signed char) a1, (vector signed char) a2), \ __ch (__bin_args_eq (vector unsigned char, a1, vector signed char, a2), \       (vector signed int) __builtin_altivec_vcmpgtub_p ((vector signed char) a1, (vector signed char) a2), \ __ch (__bin_args_eq (vector unsigned char, a1, vector unsigned char, a2), \       (vector signed int) __builtin_altivec_vcmpgtub_p ((vector signed char) a1, (vector signed char) a2), \ __ch (__bin_args_eq (vector signed char, a1, vector signed char, a2), \       (vector signed int) __builtin_altivec_vcmpgtsb_p ((vector signed char) a1, (vector signed char) a2), \ __ch (__bin_args_eq (vector signed short, a1, vector unsigned short, a2), \       (vector signed int) __builtin_altivec_vcmpgtuh_p ((vector signed short) a1, (vector signed short) a2), \ __ch (__bin_args_eq (vector unsigned short, a1, vector signed short, a2), \       (vector signed int) __builtin_altivec_vcmpgtuh_p ((vector signed short) a1, (vector signed short) a2), \ __ch (__bin_args_eq (vector unsigned short, a1, vector unsigned short, a2), \       (vector signed int) __builtin_altivec_vcmpgtuh_p ((vector signed short) a1, (vector signed short) a2), \ __ch (__bin_args_eq (vector signed short, a1, vector signed short, a2), \       (vector signed int) __builtin_altivec_vcmpgtsh_p ((vector signed short) a1, (vector signed short) a2), \ __ch (__bin_args_eq (vector signed int, a1, vector unsigned int, a2), \       (vector signed int) __builtin_altivec_vcmpgtuw_p ((vector signed int) a1, (vector signed int) a2), \ __ch (__bin_args_eq (vector unsigned int, a1, vector signed int, a2), \       (vector signed int) __builtin_altivec_vcmpgtuw_p ((vector signed int) a1, (vector signed int) a2), \ __ch (__bin_args_eq (vector unsigned int, a1, vector unsigned int, a2), \       (vector signed int) __builtin_altivec_vcmpgtuw_p ((vector signed int) a1, (vector signed int) a2), \ __ch (__bin_args_eq (vector signed int, a1, vector signed int, a2), \       (vector signed int) __builtin_altivec_vcmpgtsw_p ((vector signed int) a1, (vector signed int) a2), \ __ch (__bin_args_eq (vector float, a1, vector float, a2), \       (vector signed int) __builtin_altivec_vcmpgefp_p ((vector float) a1, (vector float) a2), \     __altivec_link_error_invalid_argument ())))))))))))))
end_define

begin_define
define|#
directive|define
name|vec_any_gt
parameter_list|(
name|a1
parameter_list|,
name|a2
parameter_list|)
define|\
value|__ch (__bin_args_eq (vector signed char, a1, vector unsigned char, a2), \       (vector signed int) __builtin_altivec_vcmpgtub_p ((vector signed char) a1, (vector signed char) a2), \ __ch (__bin_args_eq (vector unsigned char, a1, vector signed char, a2), \       (vector signed int) __builtin_altivec_vcmpgtub_p ((vector signed char) a1, (vector signed char) a2), \ __ch (__bin_args_eq (vector unsigned char, a1, vector unsigned char, a2), \       (vector signed int) __builtin_altivec_vcmpgtub_p ((vector signed char) a1, (vector signed char) a2), \ __ch (__bin_args_eq (vector signed char, a1, vector signed char, a2), \       (vector signed int) __builtin_altivec_vcmpgtsb_p ((vector signed char) a1, (vector signed char) a2), \ __ch (__bin_args_eq (vector signed short, a1, vector unsigned short, a2), \       (vector signed int) __builtin_altivec_vcmpgtuh_p ((vector signed short) a1, (vector signed short) a2), \ __ch (__bin_args_eq (vector unsigned short, a1, vector signed short, a2), \       (vector signed int) __builtin_altivec_vcmpgtuh_p ((vector signed short) a1, (vector signed short) a2), \ __ch (__bin_args_eq (vector unsigned short, a1, vector unsigned short, a2), \       (vector signed int) __builtin_altivec_vcmpgtuh_p ((vector signed short) a1, (vector signed short) a2), \ __ch (__bin_args_eq (vector signed short, a1, vector signed short, a2), \       (vector signed int) __builtin_altivec_vcmpgtsh_p ((vector signed short) a1, (vector signed short) a2), \ __ch (__bin_args_eq (vector signed int, a1, vector unsigned int, a2), \       (vector signed int) __builtin_altivec_vcmpgtuw_p ((vector signed int) a1, (vector signed int) a2), \ __ch (__bin_args_eq (vector unsigned int, a1, vector signed int, a2), \       (vector signed int) __builtin_altivec_vcmpgtuw_p ((vector signed int) a1, (vector signed int) a2), \ __ch (__bin_args_eq (vector unsigned int, a1, vector unsigned int, a2), \       (vector signed int) __builtin_altivec_vcmpgtuw_p ((vector signed int) a1, (vector signed int) a2), \ __ch (__bin_args_eq (vector signed int, a1, vector signed int, a2), \       (vector signed int) __builtin_altivec_vcmpgtsw_p ((vector signed int) a1, (vector signed int) a2), \ __ch (__bin_args_eq (vector float, a1, vector float, a2), \       (vector signed int) __builtin_altivec_vcmpgtfp_p ((vector float) a1, (vector float) a2), \     __altivec_link_error_invalid_argument ())))))))))))))
end_define

begin_define
define|#
directive|define
name|vec_any_le
parameter_list|(
name|a1
parameter_list|,
name|a2
parameter_list|)
define|\
value|__ch (__bin_args_eq (vector signed char, a1, vector unsigned char, a2), \       (vector signed int) __builtin_altivec_vcmpgtub_p ((vector signed char) a1, (vector signed char) a2), \ __ch (__bin_args_eq (vector unsigned char, a1, vector signed char, a2), \       (vector signed int) __builtin_altivec_vcmpgtub_p ((vector signed char) a1, (vector signed char) a2), \ __ch (__bin_args_eq (vector unsigned char, a1, vector unsigned char, a2), \       (vector signed int) __builtin_altivec_vcmpgtub_p ((vector signed char) a1, (vector signed char) a2), \ __ch (__bin_args_eq (vector signed char, a1, vector signed char, a2), \       (vector signed int) __builtin_altivec_vcmpgtsb_p ((vector signed char) a1, (vector signed char) a2), \ __ch (__bin_args_eq (vector signed short, a1, vector unsigned short, a2), \       (vector signed int) __builtin_altivec_vcmpgtuh_p ((vector signed short) a1, (vector signed short) a2), \ __ch (__bin_args_eq (vector unsigned short, a1, vector signed short, a2), \       (vector signed int) __builtin_altivec_vcmpgtuh_p ((vector signed short) a1, (vector signed short) a2), \ __ch (__bin_args_eq (vector unsigned short, a1, vector unsigned short, a2), \       (vector signed int) __builtin_altivec_vcmpgtuh_p ((vector signed short) a1, (vector signed short) a2), \ __ch (__bin_args_eq (vector signed short, a1, vector signed short, a2), \       (vector signed int) __builtin_altivec_vcmpgtsh_p ((vector signed short) a1, (vector signed short) a2), \ __ch (__bin_args_eq (vector signed int, a1, vector unsigned int, a2), \       (vector signed int) __builtin_altivec_vcmpgtuw_p ((vector signed int) a1, (vector signed int) a2), \ __ch (__bin_args_eq (vector unsigned int, a1, vector signed int, a2), \       (vector signed int) __builtin_altivec_vcmpgtuw_p ((vector signed int) a1, (vector signed int) a2), \ __ch (__bin_args_eq (vector unsigned int, a1, vector unsigned int, a2), \       (vector signed int) __builtin_altivec_vcmpgtuw_p ((vector signed int) a1, (vector signed int) a2), \ __ch (__bin_args_eq (vector signed int, a1, vector signed int, a2), \       (vector signed int) __builtin_altivec_vcmpgtsw_p ((vector signed int) a1, (vector signed int) a2), \ __ch (__bin_args_eq (vector float, a1, vector float, a2), \       (vector signed int) __builtin_altivec_vcmpgefp_p ((vector float) a1, (vector float) a2), \     __altivec_link_error_invalid_argument ())))))))))))))
end_define

begin_define
define|#
directive|define
name|vec_any_lt
parameter_list|(
name|a1
parameter_list|,
name|a2
parameter_list|)
define|\
value|__ch (__bin_args_eq (vector signed char, a1, vector unsigned char, a2), \       (vector signed int) __builtin_altivec_vcmpgtub_p ((vector signed char) a1, (vector signed char) a2), \ __ch (__bin_args_eq (vector unsigned char, a1, vector signed char, a2), \       (vector signed int) __builtin_altivec_vcmpgtub_p ((vector signed char) a1, (vector signed char) a2), \ __ch (__bin_args_eq (vector unsigned char, a1, vector unsigned char, a2), \       (vector signed int) __builtin_altivec_vcmpgtub_p ((vector signed char) a1, (vector signed char) a2), \ __ch (__bin_args_eq (vector signed char, a1, vector signed char, a2), \       (vector signed int) __builtin_altivec_vcmpgtsb_p ((vector signed char) a1, (vector signed char) a2), \ __ch (__bin_args_eq (vector signed short, a1, vector unsigned short, a2), \       (vector signed int) __builtin_altivec_vcmpgtuh_p ((vector signed short) a1, (vector signed short) a2), \ __ch (__bin_args_eq (vector unsigned short, a1, vector signed short, a2), \       (vector signed int) __builtin_altivec_vcmpgtuh_p ((vector signed short) a1, (vector signed short) a2), \ __ch (__bin_args_eq (vector unsigned short, a1, vector unsigned short, a2), \       (vector signed int) __builtin_altivec_vcmpgtuh_p ((vector signed short) a1, (vector signed short) a2), \ __ch (__bin_args_eq (vector signed short, a1, vector signed short, a2), \       (vector signed int) __builtin_altivec_vcmpgtsh_p ((vector signed short) a1, (vector signed short) a2), \ __ch (__bin_args_eq (vector signed int, a1, vector unsigned int, a2), \       (vector signed int) __builtin_altivec_vcmpgtuw_p ((vector signed int) a1, (vector signed int) a2), \ __ch (__bin_args_eq (vector unsigned int, a1, vector signed int, a2), \       (vector signed int) __builtin_altivec_vcmpgtuw_p ((vector signed int) a1, (vector signed int) a2), \ __ch (__bin_args_eq (vector unsigned int, a1, vector unsigned int, a2), \       (vector signed int) __builtin_altivec_vcmpgtuw_p ((vector signed int) a1, (vector signed int) a2), \ __ch (__bin_args_eq (vector signed int, a1, vector signed int, a2), \       (vector signed int) __builtin_altivec_vcmpgtsw_p ((vector signed int) a1, (vector signed int) a2), \ __ch (__bin_args_eq (vector float, a1, vector float, a2), \       (vector signed int) __builtin_altivec_vcmpgtfp_p ((vector float) a1, (vector float) a2), \     __altivec_link_error_invalid_argument ())))))))))))))
end_define

begin_define
define|#
directive|define
name|vec_any_nan
parameter_list|(
name|a1
parameter_list|)
value|__builtin_altivec_vcmpeqfp_p (a1)
end_define

begin_define
define|#
directive|define
name|vec_any_ne
parameter_list|(
name|a1
parameter_list|,
name|a2
parameter_list|)
define|\
value|__ch (__bin_args_eq (vector signed char, a1, vector unsigned char, a2), \       (vector signed int) __builtin_altivec_vcmpequb_p ((vector signed char) a1, (vector signed char) a2), \ __ch (__bin_args_eq (vector signed char, a1, vector signed char, a2), \       (vector signed int) __builtin_altivec_vcmpequb_p ((vector signed char) a1, (vector signed char) a2), \ __ch (__bin_args_eq (vector unsigned char, a1, vector signed char, a2), \       (vector signed int) __builtin_altivec_vcmpequb_p ((vector signed char) a1, (vector signed char) a2), \ __ch (__bin_args_eq (vector unsigned char, a1, vector unsigned char, a2), \       (vector signed int) __builtin_altivec_vcmpequb_p ((vector signed char) a1, (vector signed char) a2), \ __ch (__bin_args_eq (vector signed short, a1, vector unsigned short, a2), \       (vector signed int) __builtin_altivec_vcmpequh_p ((vector signed short) a1, (vector signed short) a2), \ __ch (__bin_args_eq (vector signed short, a1, vector signed short, a2), \       (vector signed int) __builtin_altivec_vcmpequh_p ((vector signed short) a1, (vector signed short) a2), \ __ch (__bin_args_eq (vector unsigned short, a1, vector signed short, a2), \       (vector signed int) __builtin_altivec_vcmpequh_p ((vector signed short) a1, (vector signed short) a2), \ __ch (__bin_args_eq (vector unsigned short, a1, vector unsigned short, a2), \       (vector signed int) __builtin_altivec_vcmpequh_p ((vector signed short) a1, (vector signed short) a2), \ __ch (__bin_args_eq (vector signed int, a1, vector unsigned int, a2), \       (vector signed int) __builtin_altivec_vcmpequw_p ((vector signed int) a1, (vector signed int) a2), \ __ch (__bin_args_eq (vector signed int, a1, vector signed int, a2), \       (vector signed int) __builtin_altivec_vcmpequw_p ((vector signed int) a1, (vector signed int) a2), \ __ch (__bin_args_eq (vector unsigned int, a1, vector signed int, a2), \       (vector signed int) __builtin_altivec_vcmpequw_p ((vector signed int) a1, (vector signed int) a2), \ __ch (__bin_args_eq (vector unsigned int, a1, vector unsigned int, a2), \       (vector signed int) __builtin_altivec_vcmpequw_p ((vector signed int) a1, (vector signed int) a2), \ __ch (__bin_args_eq (vector float, a1, vector float, a2), \       (vector signed int) __builtin_altivec_vcmpeqfp_p ((vector float) a1, (vector float) a2), \     __altivec_link_error_invalid_argument ())))))))))))))
end_define

begin_define
define|#
directive|define
name|vec_any_nge
parameter_list|(
name|a1
parameter_list|,
name|a2
parameter_list|)
value|__builtin_altivec_vcmpgefp_p (a1, a2)
end_define

begin_define
define|#
directive|define
name|vec_any_ngt
parameter_list|(
name|a1
parameter_list|,
name|a2
parameter_list|)
value|__builtin_altivec_vcmpgtfp_p (a1, a2)
end_define

begin_define
define|#
directive|define
name|vec_any_nle
parameter_list|(
name|a1
parameter_list|,
name|a2
parameter_list|)
value|__builtin_altivec_vcmpgefp_p (a1, a2)
end_define

begin_define
define|#
directive|define
name|vec_any_nlt
parameter_list|(
name|a1
parameter_list|,
name|a2
parameter_list|)
value|__builtin_altivec_vcmpgtfp_p (a1, a2)
end_define

begin_define
define|#
directive|define
name|vec_any_numeric
parameter_list|(
name|a1
parameter_list|)
value|__builtin_altivec_vcmpeqfp_p (a1)
end_define

begin_define
define|#
directive|define
name|vec_any_out
parameter_list|(
name|a1
parameter_list|,
name|a2
parameter_list|)
value|__builtin_altivec_vcmpbfp_p (a1, a2)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __cplusplus */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _ALTIVEC_H */
end_comment

end_unit

