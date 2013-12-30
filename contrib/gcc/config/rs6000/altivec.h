begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* PowerPC AltiVec include file.    Copyright (C) 2002, 2003, 2004, 2005 Free Software Foundation, Inc.    Contributed by Aldy Hernandez (aldyh@redhat.com).    Rewritten by Paolo Bonzini (bonzini@gnu.org).     This file is part of GCC.     GCC is free software; you can redistribute it and/or modify it    under the terms of the GNU General Public License as published    by the Free Software Foundation; either version 2, or (at your    option) any later version.     GCC is distributed in the hope that it will be useful, but WITHOUT    ANY WARRANTY; without even the implied warranty of MERCHANTABILITY    or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public    License for more details.     You should have received a copy of the GNU General Public License    along with GCC; see the file COPYING.  If not, write to the    Free Software Foundation, 51 Franklin Street, Fifth Floor, Boston,    MA 02110-1301, USA.  */
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

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|__VEC__
argument_list|)
operator|||
operator|!
name|defined
argument_list|(
name|__ALTIVEC__
argument_list|)
end_if

begin_error
error|#
directive|error
error|Use the "-maltivec" flag to enable PowerPC AltiVec support
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* If __APPLE_ALTIVEC__ is defined, the compiler supports 'vector',    'pixel' and 'bool' as context-sensitive AltiVec keywords (in     non-AltiVec contexts, they revert to their original meanings,    if any), so we do not need to define them as macros.  */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|__APPLE_ALTIVEC__
argument_list|)
end_if

begin_comment
comment|/* You are allowed to undef these for C++ compatibility.  */
end_comment

begin_define
define|#
directive|define
name|vector
value|__vector
end_define

begin_define
define|#
directive|define
name|pixel
value|__pixel
end_define

begin_define
define|#
directive|define
name|bool
value|__bool
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Condition register codes for AltiVec predicates. */
end_comment

begin_define
define|#
directive|define
name|__CR6_EQ
value|0
end_define

begin_define
define|#
directive|define
name|__CR6_EQ_REV
value|1
end_define

begin_define
define|#
directive|define
name|__CR6_LT
value|2
end_define

begin_define
define|#
directive|define
name|__CR6_LT_REV
value|3
end_define

begin_comment
comment|/* Synonyms.  */
end_comment

begin_define
define|#
directive|define
name|vec_vaddcuw
value|vec_addc
end_define

begin_define
define|#
directive|define
name|vec_vand
value|vec_and
end_define

begin_define
define|#
directive|define
name|vec_vandc
value|vec_andc
end_define

begin_define
define|#
directive|define
name|vec_vrfip
value|vec_ceil
end_define

begin_define
define|#
directive|define
name|vec_vcmpbfp
value|vec_cmpb
end_define

begin_define
define|#
directive|define
name|vec_vcmpgefp
value|vec_cmpge
end_define

begin_define
define|#
directive|define
name|vec_vctsxs
value|vec_cts
end_define

begin_define
define|#
directive|define
name|vec_vctuxs
value|vec_ctu
end_define

begin_define
define|#
directive|define
name|vec_vexptefp
value|vec_expte
end_define

begin_define
define|#
directive|define
name|vec_vrfim
value|vec_floor
end_define

begin_define
define|#
directive|define
name|vec_lvx
value|vec_ld
end_define

begin_define
define|#
directive|define
name|vec_lvxl
value|vec_ldl
end_define

begin_define
define|#
directive|define
name|vec_vlogefp
value|vec_loge
end_define

begin_define
define|#
directive|define
name|vec_vmaddfp
value|vec_madd
end_define

begin_define
define|#
directive|define
name|vec_vmhaddshs
value|vec_madds
end_define

begin_define
define|#
directive|define
name|vec_vmladduhm
value|vec_mladd
end_define

begin_define
define|#
directive|define
name|vec_vmhraddshs
value|vec_mradds
end_define

begin_define
define|#
directive|define
name|vec_vnmsubfp
value|vec_nmsub
end_define

begin_define
define|#
directive|define
name|vec_vnor
value|vec_nor
end_define

begin_define
define|#
directive|define
name|vec_vor
value|vec_or
end_define

begin_define
define|#
directive|define
name|vec_vpkpx
value|vec_packpx
end_define

begin_define
define|#
directive|define
name|vec_vperm
value|vec_perm
end_define

begin_define
define|#
directive|define
name|vec_vrefp
value|vec_re
end_define

begin_define
define|#
directive|define
name|vec_vrfin
value|vec_round
end_define

begin_define
define|#
directive|define
name|vec_vrsqrtefp
value|vec_rsqrte
end_define

begin_define
define|#
directive|define
name|vec_vsel
value|vec_sel
end_define

begin_define
define|#
directive|define
name|vec_vsldoi
value|vec_sld
end_define

begin_define
define|#
directive|define
name|vec_vsl
value|vec_sll
end_define

begin_define
define|#
directive|define
name|vec_vslo
value|vec_slo
end_define

begin_define
define|#
directive|define
name|vec_vspltisb
value|vec_splat_s8
end_define

begin_define
define|#
directive|define
name|vec_vspltish
value|vec_splat_s16
end_define

begin_define
define|#
directive|define
name|vec_vspltisw
value|vec_splat_s32
end_define

begin_define
define|#
directive|define
name|vec_vsr
value|vec_srl
end_define

begin_define
define|#
directive|define
name|vec_vsro
value|vec_sro
end_define

begin_define
define|#
directive|define
name|vec_stvx
value|vec_st
end_define

begin_define
define|#
directive|define
name|vec_stvxl
value|vec_stl
end_define

begin_define
define|#
directive|define
name|vec_vsubcuw
value|vec_subc
end_define

begin_define
define|#
directive|define
name|vec_vsum2sws
value|vec_sum2s
end_define

begin_define
define|#
directive|define
name|vec_vsumsws
value|vec_sums
end_define

begin_define
define|#
directive|define
name|vec_vrfiz
value|vec_trunc
end_define

begin_define
define|#
directive|define
name|vec_vxor
value|vec_xor
end_define

begin_comment
comment|/* Functions that are resolved by the backend to one of the    typed builtins.  */
end_comment

begin_define
define|#
directive|define
name|vec_vaddfp
value|__builtin_vec_vaddfp
end_define

begin_define
define|#
directive|define
name|vec_addc
value|__builtin_vec_addc
end_define

begin_define
define|#
directive|define
name|vec_vaddsws
value|__builtin_vec_vaddsws
end_define

begin_define
define|#
directive|define
name|vec_vaddshs
value|__builtin_vec_vaddshs
end_define

begin_define
define|#
directive|define
name|vec_vaddsbs
value|__builtin_vec_vaddsbs
end_define

begin_define
define|#
directive|define
name|vec_vavgsw
value|__builtin_vec_vavgsw
end_define

begin_define
define|#
directive|define
name|vec_vavguw
value|__builtin_vec_vavguw
end_define

begin_define
define|#
directive|define
name|vec_vavgsh
value|__builtin_vec_vavgsh
end_define

begin_define
define|#
directive|define
name|vec_vavguh
value|__builtin_vec_vavguh
end_define

begin_define
define|#
directive|define
name|vec_vavgsb
value|__builtin_vec_vavgsb
end_define

begin_define
define|#
directive|define
name|vec_vavgub
value|__builtin_vec_vavgub
end_define

begin_define
define|#
directive|define
name|vec_ceil
value|__builtin_vec_ceil
end_define

begin_define
define|#
directive|define
name|vec_cmpb
value|__builtin_vec_cmpb
end_define

begin_define
define|#
directive|define
name|vec_vcmpeqfp
value|__builtin_vec_vcmpeqfp
end_define

begin_define
define|#
directive|define
name|vec_cmpge
value|__builtin_vec_cmpge
end_define

begin_define
define|#
directive|define
name|vec_vcmpgtfp
value|__builtin_vec_vcmpgtfp
end_define

begin_define
define|#
directive|define
name|vec_vcmpgtsw
value|__builtin_vec_vcmpgtsw
end_define

begin_define
define|#
directive|define
name|vec_vcmpgtuw
value|__builtin_vec_vcmpgtuw
end_define

begin_define
define|#
directive|define
name|vec_vcmpgtsh
value|__builtin_vec_vcmpgtsh
end_define

begin_define
define|#
directive|define
name|vec_vcmpgtuh
value|__builtin_vec_vcmpgtuh
end_define

begin_define
define|#
directive|define
name|vec_vcmpgtsb
value|__builtin_vec_vcmpgtsb
end_define

begin_define
define|#
directive|define
name|vec_vcmpgtub
value|__builtin_vec_vcmpgtub
end_define

begin_define
define|#
directive|define
name|vec_vcfsx
value|__builtin_vec_vcfsx
end_define

begin_define
define|#
directive|define
name|vec_vcfux
value|__builtin_vec_vcfux
end_define

begin_define
define|#
directive|define
name|vec_cts
value|__builtin_vec_cts
end_define

begin_define
define|#
directive|define
name|vec_ctu
value|__builtin_vec_ctu
end_define

begin_define
define|#
directive|define
name|vec_expte
value|__builtin_vec_expte
end_define

begin_define
define|#
directive|define
name|vec_floor
value|__builtin_vec_floor
end_define

begin_define
define|#
directive|define
name|vec_loge
value|__builtin_vec_loge
end_define

begin_define
define|#
directive|define
name|vec_madd
value|__builtin_vec_madd
end_define

begin_define
define|#
directive|define
name|vec_madds
value|__builtin_vec_madds
end_define

begin_define
define|#
directive|define
name|vec_mtvscr
value|__builtin_vec_mtvscr
end_define

begin_define
define|#
directive|define
name|vec_vmaxfp
value|__builtin_vec_vmaxfp
end_define

begin_define
define|#
directive|define
name|vec_vmaxsw
value|__builtin_vec_vmaxsw
end_define

begin_define
define|#
directive|define
name|vec_vmaxsh
value|__builtin_vec_vmaxsh
end_define

begin_define
define|#
directive|define
name|vec_vmaxsb
value|__builtin_vec_vmaxsb
end_define

begin_define
define|#
directive|define
name|vec_vminfp
value|__builtin_vec_vminfp
end_define

begin_define
define|#
directive|define
name|vec_vminsw
value|__builtin_vec_vminsw
end_define

begin_define
define|#
directive|define
name|vec_vminsh
value|__builtin_vec_vminsh
end_define

begin_define
define|#
directive|define
name|vec_vminsb
value|__builtin_vec_vminsb
end_define

begin_define
define|#
directive|define
name|vec_mradds
value|__builtin_vec_mradds
end_define

begin_define
define|#
directive|define
name|vec_vmsumshm
value|__builtin_vec_vmsumshm
end_define

begin_define
define|#
directive|define
name|vec_vmsumuhm
value|__builtin_vec_vmsumuhm
end_define

begin_define
define|#
directive|define
name|vec_vmsummbm
value|__builtin_vec_vmsummbm
end_define

begin_define
define|#
directive|define
name|vec_vmsumubm
value|__builtin_vec_vmsumubm
end_define

begin_define
define|#
directive|define
name|vec_vmsumshs
value|__builtin_vec_vmsumshs
end_define

begin_define
define|#
directive|define
name|vec_vmsumuhs
value|__builtin_vec_vmsumuhs
end_define

begin_define
define|#
directive|define
name|vec_vmulesb
value|__builtin_vec_vmulesb
end_define

begin_define
define|#
directive|define
name|vec_vmulesh
value|__builtin_vec_vmulesh
end_define

begin_define
define|#
directive|define
name|vec_vmuleuh
value|__builtin_vec_vmuleuh
end_define

begin_define
define|#
directive|define
name|vec_vmuleub
value|__builtin_vec_vmuleub
end_define

begin_define
define|#
directive|define
name|vec_vmulosh
value|__builtin_vec_vmulosh
end_define

begin_define
define|#
directive|define
name|vec_vmulouh
value|__builtin_vec_vmulouh
end_define

begin_define
define|#
directive|define
name|vec_vmulosb
value|__builtin_vec_vmulosb
end_define

begin_define
define|#
directive|define
name|vec_vmuloub
value|__builtin_vec_vmuloub
end_define

begin_define
define|#
directive|define
name|vec_nmsub
value|__builtin_vec_nmsub
end_define

begin_define
define|#
directive|define
name|vec_packpx
value|__builtin_vec_packpx
end_define

begin_define
define|#
directive|define
name|vec_vpkswss
value|__builtin_vec_vpkswss
end_define

begin_define
define|#
directive|define
name|vec_vpkuwus
value|__builtin_vec_vpkuwus
end_define

begin_define
define|#
directive|define
name|vec_vpkshss
value|__builtin_vec_vpkshss
end_define

begin_define
define|#
directive|define
name|vec_vpkuhus
value|__builtin_vec_vpkuhus
end_define

begin_define
define|#
directive|define
name|vec_vpkswus
value|__builtin_vec_vpkswus
end_define

begin_define
define|#
directive|define
name|vec_vpkshus
value|__builtin_vec_vpkshus
end_define

begin_define
define|#
directive|define
name|vec_re
value|__builtin_vec_re
end_define

begin_define
define|#
directive|define
name|vec_round
value|__builtin_vec_round
end_define

begin_define
define|#
directive|define
name|vec_rsqrte
value|__builtin_vec_rsqrte
end_define

begin_define
define|#
directive|define
name|vec_vsubfp
value|__builtin_vec_vsubfp
end_define

begin_define
define|#
directive|define
name|vec_subc
value|__builtin_vec_subc
end_define

begin_define
define|#
directive|define
name|vec_vsubsws
value|__builtin_vec_vsubsws
end_define

begin_define
define|#
directive|define
name|vec_vsubshs
value|__builtin_vec_vsubshs
end_define

begin_define
define|#
directive|define
name|vec_vsubsbs
value|__builtin_vec_vsubsbs
end_define

begin_define
define|#
directive|define
name|vec_sum4s
value|__builtin_vec_sum4s
end_define

begin_define
define|#
directive|define
name|vec_vsum4shs
value|__builtin_vec_vsum4shs
end_define

begin_define
define|#
directive|define
name|vec_vsum4sbs
value|__builtin_vec_vsum4sbs
end_define

begin_define
define|#
directive|define
name|vec_vsum4ubs
value|__builtin_vec_vsum4ubs
end_define

begin_define
define|#
directive|define
name|vec_sum2s
value|__builtin_vec_sum2s
end_define

begin_define
define|#
directive|define
name|vec_sums
value|__builtin_vec_sums
end_define

begin_define
define|#
directive|define
name|vec_trunc
value|__builtin_vec_trunc
end_define

begin_define
define|#
directive|define
name|vec_vupkhpx
value|__builtin_vec_vupkhpx
end_define

begin_define
define|#
directive|define
name|vec_vupkhsh
value|__builtin_vec_vupkhsh
end_define

begin_define
define|#
directive|define
name|vec_vupkhsb
value|__builtin_vec_vupkhsb
end_define

begin_define
define|#
directive|define
name|vec_vupklpx
value|__builtin_vec_vupklpx
end_define

begin_define
define|#
directive|define
name|vec_vupklsh
value|__builtin_vec_vupklsh
end_define

begin_define
define|#
directive|define
name|vec_vupklsb
value|__builtin_vec_vupklsb
end_define

begin_define
define|#
directive|define
name|vec_abs
value|__builtin_vec_abs
end_define

begin_define
define|#
directive|define
name|vec_abss
value|__builtin_vec_abss
end_define

begin_define
define|#
directive|define
name|vec_add
value|__builtin_vec_add
end_define

begin_define
define|#
directive|define
name|vec_adds
value|__builtin_vec_adds
end_define

begin_define
define|#
directive|define
name|vec_and
value|__builtin_vec_and
end_define

begin_define
define|#
directive|define
name|vec_andc
value|__builtin_vec_andc
end_define

begin_define
define|#
directive|define
name|vec_avg
value|__builtin_vec_avg
end_define

begin_define
define|#
directive|define
name|vec_cmpeq
value|__builtin_vec_cmpeq
end_define

begin_define
define|#
directive|define
name|vec_cmpgt
value|__builtin_vec_cmpgt
end_define

begin_define
define|#
directive|define
name|vec_ctf
value|__builtin_vec_ctf
end_define

begin_define
define|#
directive|define
name|vec_dst
value|__builtin_vec_dst
end_define

begin_define
define|#
directive|define
name|vec_dstst
value|__builtin_vec_dstst
end_define

begin_define
define|#
directive|define
name|vec_dststt
value|__builtin_vec_dststt
end_define

begin_define
define|#
directive|define
name|vec_dstt
value|__builtin_vec_dstt
end_define

begin_define
define|#
directive|define
name|vec_ld
value|__builtin_vec_ld
end_define

begin_define
define|#
directive|define
name|vec_lde
value|__builtin_vec_lde
end_define

begin_define
define|#
directive|define
name|vec_ldl
value|__builtin_vec_ldl
end_define

begin_define
define|#
directive|define
name|vec_lvebx
value|__builtin_vec_lvebx
end_define

begin_define
define|#
directive|define
name|vec_lvehx
value|__builtin_vec_lvehx
end_define

begin_define
define|#
directive|define
name|vec_lvewx
value|__builtin_vec_lvewx
end_define

begin_define
define|#
directive|define
name|vec_lvsl
value|__builtin_vec_lvsl
end_define

begin_define
define|#
directive|define
name|vec_lvsr
value|__builtin_vec_lvsr
end_define

begin_define
define|#
directive|define
name|vec_max
value|__builtin_vec_max
end_define

begin_define
define|#
directive|define
name|vec_mergeh
value|__builtin_vec_mergeh
end_define

begin_define
define|#
directive|define
name|vec_mergel
value|__builtin_vec_mergel
end_define

begin_define
define|#
directive|define
name|vec_min
value|__builtin_vec_min
end_define

begin_define
define|#
directive|define
name|vec_mladd
value|__builtin_vec_mladd
end_define

begin_define
define|#
directive|define
name|vec_msum
value|__builtin_vec_msum
end_define

begin_define
define|#
directive|define
name|vec_msums
value|__builtin_vec_msums
end_define

begin_define
define|#
directive|define
name|vec_mule
value|__builtin_vec_mule
end_define

begin_define
define|#
directive|define
name|vec_mulo
value|__builtin_vec_mulo
end_define

begin_define
define|#
directive|define
name|vec_nor
value|__builtin_vec_nor
end_define

begin_define
define|#
directive|define
name|vec_or
value|__builtin_vec_or
end_define

begin_define
define|#
directive|define
name|vec_pack
value|__builtin_vec_pack
end_define

begin_define
define|#
directive|define
name|vec_packs
value|__builtin_vec_packs
end_define

begin_define
define|#
directive|define
name|vec_packsu
value|__builtin_vec_packsu
end_define

begin_define
define|#
directive|define
name|vec_perm
value|__builtin_vec_perm
end_define

begin_define
define|#
directive|define
name|vec_rl
value|__builtin_vec_rl
end_define

begin_define
define|#
directive|define
name|vec_sel
value|__builtin_vec_sel
end_define

begin_define
define|#
directive|define
name|vec_sl
value|__builtin_vec_sl
end_define

begin_define
define|#
directive|define
name|vec_sld
value|__builtin_vec_sld
end_define

begin_define
define|#
directive|define
name|vec_sll
value|__builtin_vec_sll
end_define

begin_define
define|#
directive|define
name|vec_slo
value|__builtin_vec_slo
end_define

begin_define
define|#
directive|define
name|vec_splat
value|__builtin_vec_splat
end_define

begin_define
define|#
directive|define
name|vec_sr
value|__builtin_vec_sr
end_define

begin_define
define|#
directive|define
name|vec_sra
value|__builtin_vec_sra
end_define

begin_define
define|#
directive|define
name|vec_srl
value|__builtin_vec_srl
end_define

begin_define
define|#
directive|define
name|vec_sro
value|__builtin_vec_sro
end_define

begin_define
define|#
directive|define
name|vec_st
value|__builtin_vec_st
end_define

begin_define
define|#
directive|define
name|vec_ste
value|__builtin_vec_ste
end_define

begin_define
define|#
directive|define
name|vec_stl
value|__builtin_vec_stl
end_define

begin_define
define|#
directive|define
name|vec_stvebx
value|__builtin_vec_stvebx
end_define

begin_define
define|#
directive|define
name|vec_stvehx
value|__builtin_vec_stvehx
end_define

begin_define
define|#
directive|define
name|vec_stvewx
value|__builtin_vec_stvewx
end_define

begin_define
define|#
directive|define
name|vec_sub
value|__builtin_vec_sub
end_define

begin_define
define|#
directive|define
name|vec_subs
value|__builtin_vec_subs
end_define

begin_define
define|#
directive|define
name|vec_sum
value|__builtin_vec_sum
end_define

begin_define
define|#
directive|define
name|vec_unpackh
value|__builtin_vec_unpackh
end_define

begin_define
define|#
directive|define
name|vec_unpackl
value|__builtin_vec_unpackl
end_define

begin_define
define|#
directive|define
name|vec_vaddubm
value|__builtin_vec_vaddubm
end_define

begin_define
define|#
directive|define
name|vec_vaddubs
value|__builtin_vec_vaddubs
end_define

begin_define
define|#
directive|define
name|vec_vadduhm
value|__builtin_vec_vadduhm
end_define

begin_define
define|#
directive|define
name|vec_vadduhs
value|__builtin_vec_vadduhs
end_define

begin_define
define|#
directive|define
name|vec_vadduwm
value|__builtin_vec_vadduwm
end_define

begin_define
define|#
directive|define
name|vec_vadduws
value|__builtin_vec_vadduws
end_define

begin_define
define|#
directive|define
name|vec_vcmpequb
value|__builtin_vec_vcmpequb
end_define

begin_define
define|#
directive|define
name|vec_vcmpequh
value|__builtin_vec_vcmpequh
end_define

begin_define
define|#
directive|define
name|vec_vcmpequw
value|__builtin_vec_vcmpequw
end_define

begin_define
define|#
directive|define
name|vec_vmaxub
value|__builtin_vec_vmaxub
end_define

begin_define
define|#
directive|define
name|vec_vmaxuh
value|__builtin_vec_vmaxuh
end_define

begin_define
define|#
directive|define
name|vec_vmaxuw
value|__builtin_vec_vmaxuw
end_define

begin_define
define|#
directive|define
name|vec_vminub
value|__builtin_vec_vminub
end_define

begin_define
define|#
directive|define
name|vec_vminuh
value|__builtin_vec_vminuh
end_define

begin_define
define|#
directive|define
name|vec_vminuw
value|__builtin_vec_vminuw
end_define

begin_define
define|#
directive|define
name|vec_vmrghb
value|__builtin_vec_vmrghb
end_define

begin_define
define|#
directive|define
name|vec_vmrghh
value|__builtin_vec_vmrghh
end_define

begin_define
define|#
directive|define
name|vec_vmrghw
value|__builtin_vec_vmrghw
end_define

begin_define
define|#
directive|define
name|vec_vmrglb
value|__builtin_vec_vmrglb
end_define

begin_define
define|#
directive|define
name|vec_vmrglh
value|__builtin_vec_vmrglh
end_define

begin_define
define|#
directive|define
name|vec_vmrglw
value|__builtin_vec_vmrglw
end_define

begin_define
define|#
directive|define
name|vec_vpkuhum
value|__builtin_vec_vpkuhum
end_define

begin_define
define|#
directive|define
name|vec_vpkuwum
value|__builtin_vec_vpkuwum
end_define

begin_define
define|#
directive|define
name|vec_vrlb
value|__builtin_vec_vrlb
end_define

begin_define
define|#
directive|define
name|vec_vrlh
value|__builtin_vec_vrlh
end_define

begin_define
define|#
directive|define
name|vec_vrlw
value|__builtin_vec_vrlw
end_define

begin_define
define|#
directive|define
name|vec_vslb
value|__builtin_vec_vslb
end_define

begin_define
define|#
directive|define
name|vec_vslh
value|__builtin_vec_vslh
end_define

begin_define
define|#
directive|define
name|vec_vslw
value|__builtin_vec_vslw
end_define

begin_define
define|#
directive|define
name|vec_vspltb
value|__builtin_vec_vspltb
end_define

begin_define
define|#
directive|define
name|vec_vsplth
value|__builtin_vec_vsplth
end_define

begin_define
define|#
directive|define
name|vec_vspltw
value|__builtin_vec_vspltw
end_define

begin_define
define|#
directive|define
name|vec_vsrab
value|__builtin_vec_vsrab
end_define

begin_define
define|#
directive|define
name|vec_vsrah
value|__builtin_vec_vsrah
end_define

begin_define
define|#
directive|define
name|vec_vsraw
value|__builtin_vec_vsraw
end_define

begin_define
define|#
directive|define
name|vec_vsrb
value|__builtin_vec_vsrb
end_define

begin_define
define|#
directive|define
name|vec_vsrh
value|__builtin_vec_vsrh
end_define

begin_define
define|#
directive|define
name|vec_vsrw
value|__builtin_vec_vsrw
end_define

begin_define
define|#
directive|define
name|vec_vsububs
value|__builtin_vec_vsububs
end_define

begin_define
define|#
directive|define
name|vec_vsububm
value|__builtin_vec_vsububm
end_define

begin_define
define|#
directive|define
name|vec_vsubuhm
value|__builtin_vec_vsubuhm
end_define

begin_define
define|#
directive|define
name|vec_vsubuhs
value|__builtin_vec_vsubuhs
end_define

begin_define
define|#
directive|define
name|vec_vsubuwm
value|__builtin_vec_vsubuwm
end_define

begin_define
define|#
directive|define
name|vec_vsubuws
value|__builtin_vec_vsubuws
end_define

begin_define
define|#
directive|define
name|vec_xor
value|__builtin_vec_xor
end_define

begin_comment
comment|/* Predicates.    For C++, we use templates in order to allow non-parenthesized arguments.    For C, instead, we use macros since non-parenthesized arguments were    not allowed even in older GCC implementation of AltiVec.     In the future, we may add more magic to the back-end, so that no    one- or two-argument macros are used.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__cplusplus__
end_ifdef

begin_define
define|#
directive|define
name|__altivec_unary_pred
parameter_list|(
name|NAME
parameter_list|,
name|CALL
parameter_list|)
define|\
value|template<class T> int NAME (T a1) { return CALL; }
end_define

begin_define
define|#
directive|define
name|__altivec_scalar_pred
parameter_list|(
name|NAME
parameter_list|,
name|CALL
parameter_list|)
define|\
value|template<class T, class U> int NAME (T a1, U a2) { return CALL; }
end_define

begin_comment
comment|/* Given the vec_step of a type, return the corresponding bool type.  */
end_comment

begin_expr_stmt
name|template
operator|<
name|int
name|STEP
operator|>
name|class
name|__altivec_bool_ret
block|{ }
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|template
operator|<
operator|>
name|class
name|__altivec_bool_ret
operator|<
literal|4
operator|>
block|{
typedef|typedef
name|__vector
name|__bool
name|int
name|__ret
typedef|;
block|}
end_expr_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_expr_stmt
name|template
operator|<
operator|>
name|class
name|__altivec_bool_ret
operator|<
literal|8
operator|>
block|{
typedef|typedef
name|__vector
name|__bool
name|short
name|__ret
typedef|;
block|}
end_expr_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_expr_stmt
name|template
operator|<
operator|>
name|class
name|__altivec_bool_ret
operator|<
literal|16
operator|>
block|{
typedef|typedef
name|__vector
name|__bool
name|char
name|__ret
typedef|;
block|}
end_expr_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|/* Be very liberal in the pairs we accept.  Mistakes such as passing    a `vector char' and `vector short' will be caught by the middle-end,    while any attempt to detect them here would produce hard to understand    error messages involving the implementation details of AltiVec.  */
end_comment

begin_define
define|#
directive|define
name|__altivec_binary_pred
parameter_list|(
name|NAME
parameter_list|,
name|CALL
parameter_list|)
define|\
value|template<class T, class U> \ typename __altivec_bool_ret<vec_step (T)>::__ret \ NAME (T a1, U a2) \ { \   return CALL; \ }
end_define

begin_macro
name|__altivec_binary_pred
argument_list|(
argument|vec_cmplt
argument_list|,
argument|__builtin_vec_cmpgt (a2, a1)
argument_list|)
end_macro

begin_macro
name|__altivec_binary_pred
argument_list|(
argument|vec_cmple
argument_list|,
argument|__builtin_vec_cmpge (a2, a1)
argument_list|)
end_macro

begin_macro
name|__altivec_scalar_pred
argument_list|(
argument|vec_all_in
argument_list|,
argument|__builtin_altivec_vcmpbfp_p (__CR6_EQ, a1, a2)
argument_list|)
end_macro

begin_macro
name|__altivec_scalar_pred
argument_list|(
argument|vec_any_out
argument_list|,
argument|__builtin_altivec_vcmpbfp_p (__CR6_EQ_REV, a1, a2)
argument_list|)
end_macro

begin_macro
name|__altivec_unary_pred
argument_list|(
argument|vec_all_nan
argument_list|,
argument|__builtin_altivec_vcmpeqfp_p (__CR6_EQ, a1, a1)
argument_list|)
end_macro

begin_macro
name|__altivec_unary_pred
argument_list|(
argument|vec_any_nan
argument_list|,
argument|__builtin_altivec_vcmpeqfp_p (__CR6_LT_REV, a1, a1)
argument_list|)
end_macro

begin_macro
name|__altivec_unary_pred
argument_list|(
argument|vec_all_numeric
argument_list|,
argument|__builtin_altivec_vcmpeqfp_p (__CR6_LT, a1, a1)
argument_list|)
end_macro

begin_macro
name|__altivec_unary_pred
argument_list|(
argument|vec_any_numeric
argument_list|,
argument|__builtin_altivec_vcmpeqfp_p (__CR6_EQ_REV, a1, a1)
argument_list|)
end_macro

begin_macro
name|__altivec_scalar_pred
argument_list|(
argument|vec_all_eq
argument_list|,
argument|__builtin_vec_vcmpeq_p (__CR6_LT, a1, a2)
argument_list|)
end_macro

begin_macro
name|__altivec_scalar_pred
argument_list|(
argument|vec_all_ne
argument_list|,
argument|__builtin_vec_vcmpeq_p (__CR6_EQ, a1, a2)
argument_list|)
end_macro

begin_macro
name|__altivec_scalar_pred
argument_list|(
argument|vec_any_eq
argument_list|,
argument|__builtin_vec_vcmpeq_p (__CR6_EQ_REV, a1, a2)
argument_list|)
end_macro

begin_macro
name|__altivec_scalar_pred
argument_list|(
argument|vec_any_ne
argument_list|,
argument|__builtin_vec_vcmpeq_p (__CR6_LT_REV, a1, a2)
argument_list|)
end_macro

begin_macro
name|__altivec_scalar_pred
argument_list|(
argument|vec_all_gt
argument_list|,
argument|__builtin_vec_vcmpgt_p (__CR6_LT, a1, a2)
argument_list|)
end_macro

begin_macro
name|__altivec_scalar_pred
argument_list|(
argument|vec_all_lt
argument_list|,
argument|__builtin_vec_vcmpgt_p (__CR6_LT, a2, a1)
argument_list|)
end_macro

begin_macro
name|__altivec_scalar_pred
argument_list|(
argument|vec_any_gt
argument_list|,
argument|__builtin_vec_vcmpgt_p (__CR6_EQ_REV, a1, a2)
argument_list|)
end_macro

begin_macro
name|__altivec_scalar_pred
argument_list|(
argument|vec_any_lt
argument_list|,
argument|__builtin_vec_vcmpgt_p (__CR6_EQ_REV, a2, a1)
argument_list|)
end_macro

begin_macro
name|__altivec_scalar_pred
argument_list|(
argument|vec_all_ngt
argument_list|,
argument|__builtin_altivec_vcmpgtfp_p (__CR6_EQ, a1, a2)
argument_list|)
end_macro

begin_macro
name|__altivec_scalar_pred
argument_list|(
argument|vec_all_nlt
argument_list|,
argument|__builtin_altivec_vcmpgtfp_p (__CR6_EQ, a2, a1)
argument_list|)
end_macro

begin_macro
name|__altivec_scalar_pred
argument_list|(
argument|vec_any_ngt
argument_list|,
argument|__builtin_altivec_vcmpgtfp_p (__CR6_LT_REV, a1, a2)
argument_list|)
end_macro

begin_macro
name|__altivec_scalar_pred
argument_list|(
argument|vec_any_nlt
argument_list|,
argument|__builtin_altivec_vcmpgtfp_p (__CR6_LT_REV, a2, a1)
argument_list|)
end_macro

begin_comment
comment|/* __builtin_vec_vcmpge_p is vcmpgefp for floating-point vector types,    while for integer types it is converted to __builtin_vec_vcmpgt_p,    with inverted args and condition code.  */
end_comment

begin_macro
name|__altivec_scalar_pred
argument_list|(
argument|vec_all_le
argument_list|,
argument|__builtin_vec_vcmpge_p (__CR6_LT, a2, a1)
argument_list|)
end_macro

begin_macro
name|__altivec_scalar_pred
argument_list|(
argument|vec_all_ge
argument_list|,
argument|__builtin_vec_vcmpge_p (__CR6_LT, a1, a2)
argument_list|)
end_macro

begin_macro
name|__altivec_scalar_pred
argument_list|(
argument|vec_any_le
argument_list|,
argument|__builtin_vec_vcmpge_p (__CR6_EQ_REV, a2, a1)
argument_list|)
end_macro

begin_macro
name|__altivec_scalar_pred
argument_list|(
argument|vec_any_ge
argument_list|,
argument|__builtin_vec_vcmpge_p (__CR6_EQ_REV, a1, a2)
argument_list|)
end_macro

begin_macro
name|__altivec_scalar_pred
argument_list|(
argument|vec_all_nge
argument_list|,
argument|__builtin_altivec_vcmpgefp_p (__CR6_EQ, a1, a2)
argument_list|)
end_macro

begin_macro
name|__altivec_scalar_pred
argument_list|(
argument|vec_all_nle
argument_list|,
argument|__builtin_altivec_vcmpgefp_p (__CR6_EQ, a2, a1)
argument_list|)
end_macro

begin_macro
name|__altivec_scalar_pred
argument_list|(
argument|vec_any_nge
argument_list|,
argument|__builtin_altivec_vcmpgefp_p (__CR6_LT_REV, a1, a2)
argument_list|)
end_macro

begin_macro
name|__altivec_scalar_pred
argument_list|(
argument|vec_any_nle
argument_list|,
argument|__builtin_altivec_vcmpgefp_p (__CR6_LT_REV, a2, a1)
argument_list|)
end_macro

begin_undef
undef|#
directive|undef
name|__altivec_scalar_pred
end_undef

begin_undef
undef|#
directive|undef
name|__altivec_unary_pred
end_undef

begin_undef
undef|#
directive|undef
name|__altivec_binary_pred
end_undef

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|vec_cmplt
parameter_list|(
name|a1
parameter_list|,
name|a2
parameter_list|)
value|__builtin_vec_cmpgt ((a2), (a1))
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
value|__builtin_vec_cmpge ((a2), (a1))
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
value|__builtin_altivec_vcmpbfp_p (__CR6_EQ, (a1), (a2))
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
value|__builtin_altivec_vcmpbfp_p (__CR6_EQ_REV, (a1), (a2))
end_define

begin_define
define|#
directive|define
name|vec_all_nan
parameter_list|(
name|a1
parameter_list|)
value|__builtin_altivec_vcmpeqfp_p (__CR6_EQ, (a1), (a1))
end_define

begin_define
define|#
directive|define
name|vec_any_nan
parameter_list|(
name|a1
parameter_list|)
value|__builtin_altivec_vcmpeqfp_p (__CR6_LT_REV, (a1), (a1))
end_define

begin_define
define|#
directive|define
name|vec_all_numeric
parameter_list|(
name|a1
parameter_list|)
value|__builtin_altivec_vcmpeqfp_p (__CR6_LT, (a1), (a1))
end_define

begin_define
define|#
directive|define
name|vec_any_numeric
parameter_list|(
name|a1
parameter_list|)
value|__builtin_altivec_vcmpeqfp_p (__CR6_EQ_REV, (a1), (a1))
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
value|__builtin_vec_vcmpeq_p (__CR6_LT, (a1), (a2))
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
value|__builtin_vec_vcmpeq_p (__CR6_EQ, (a1), (a2))
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
value|__builtin_vec_vcmpeq_p (__CR6_EQ_REV, (a1), (a2))
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
value|__builtin_vec_vcmpeq_p (__CR6_LT_REV, (a1), (a2))
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
value|__builtin_vec_vcmpgt_p (__CR6_LT, (a1), (a2))
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
value|__builtin_vec_vcmpgt_p (__CR6_LT, (a2), (a1))
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
value|__builtin_vec_vcmpgt_p (__CR6_EQ_REV, (a1), (a2))
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
value|__builtin_vec_vcmpgt_p (__CR6_EQ_REV, (a2), (a1))
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
value|__builtin_altivec_vcmpgtfp_p (__CR6_EQ, (a1), (a2))
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
value|__builtin_altivec_vcmpgtfp_p (__CR6_EQ, (a2), (a1))
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
value|__builtin_altivec_vcmpgtfp_p (__CR6_LT_REV, (a1), (a2))
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
value|__builtin_altivec_vcmpgtfp_p (__CR6_LT_REV, (a2), (a1))
end_define

begin_comment
comment|/* __builtin_vec_vcmpge_p is vcmpgefp for floating-point vector types,    while for integer types it is converted to __builtin_vec_vcmpgt_p,    with inverted args and condition code.  */
end_comment

begin_define
define|#
directive|define
name|vec_all_le
parameter_list|(
name|a1
parameter_list|,
name|a2
parameter_list|)
value|__builtin_vec_vcmpge_p (__CR6_LT, (a2), (a1))
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
value|__builtin_vec_vcmpge_p (__CR6_LT, (a1), (a2))
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
value|__builtin_vec_vcmpge_p (__CR6_EQ_REV, (a2), (a1))
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
value|__builtin_vec_vcmpge_p (__CR6_EQ_REV, (a1), (a2))
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
value|__builtin_altivec_vcmpgefp_p (__CR6_EQ, (a1), (a2))
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
value|__builtin_altivec_vcmpgefp_p (__CR6_EQ, (a2), (a1))
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
value|__builtin_altivec_vcmpgefp_p (__CR6_LT_REV, (a1), (a2))
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
value|__builtin_altivec_vcmpgefp_p (__CR6_LT_REV, (a2), (a1))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* These do not accept vectors, so they do not have a __builtin_vec_*    counterpart.  */
end_comment

begin_define
define|#
directive|define
name|vec_dss
parameter_list|(
name|x
parameter_list|)
value|__builtin_altivec_dss((x))
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
name|vec_mfvscr
parameter_list|()
value|((__vector unsigned short) __builtin_altivec_mfvscr ())
end_define

begin_define
define|#
directive|define
name|vec_splat_s8
parameter_list|(
name|x
parameter_list|)
value|__builtin_altivec_vspltisb ((x))
end_define

begin_define
define|#
directive|define
name|vec_splat_s16
parameter_list|(
name|x
parameter_list|)
value|__builtin_altivec_vspltish ((x))
end_define

begin_define
define|#
directive|define
name|vec_splat_s32
parameter_list|(
name|x
parameter_list|)
value|__builtin_altivec_vspltisw ((x))
end_define

begin_define
define|#
directive|define
name|vec_splat_u8
parameter_list|(
name|x
parameter_list|)
value|((__vector unsigned char) vec_splat_s8 ((x)))
end_define

begin_define
define|#
directive|define
name|vec_splat_u16
parameter_list|(
name|x
parameter_list|)
value|((__vector unsigned short) vec_splat_s16 ((x)))
end_define

begin_define
define|#
directive|define
name|vec_splat_u32
parameter_list|(
name|x
parameter_list|)
value|((__vector unsigned int) vec_splat_s32 ((x)))
end_define

begin_comment
comment|/* This also accepts a type for its parameter, so it is not enough    to #define vec_step to __builtin_vec_step.  */
end_comment

begin_define
define|#
directive|define
name|vec_step
parameter_list|(
name|x
parameter_list|)
value|__builtin_vec_step (* (__typeof__ (x) *) 0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _ALTIVEC_H */
end_comment

end_unit

