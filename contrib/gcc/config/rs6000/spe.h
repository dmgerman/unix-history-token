begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* PowerPC E500 user include file.    Copyright (C) 2002, 2003 Free Software Foundation, Inc.    Contributed by Aldy Hernandez (aldyh@redhat.com).  This file is part of GNU CC.  GNU CC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GNU CC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GNU CC; see the file COPYING.  If not, write to the Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_comment
comment|/* As a special exception, if you include this header file into source    files compiled by GCC, this header file does not by itself cause    the resulting executable to be covered by the GNU General Public    License.  This exception does not however invalidate any other    reasons why the executable file might be covered by the GNU General    Public License.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SPE_H
end_ifndef

begin_define
define|#
directive|define
name|_SPE_H
end_define

begin_define
define|#
directive|define
name|__vector
value|__attribute__((vector_size(8)))
end_define

begin_typedef
typedef|typedef
name|int
name|int32_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|uint32_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|short
name|int16_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|short
name|uint16_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|long
name|long
name|int64_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|long
name|long
name|uint64_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|short
name|__vector
name|__ev64_s16__
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|short
name|__vector
name|__ev64_u16__
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|int
name|__vector
name|__ev64_s32__
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|__vector
name|__ev64_u32__
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|long
name|long
name|__vector
name|__ev64_s64__
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|long
name|long
name|__vector
name|__ev64_u64__
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|float
name|__vector
name|__ev64_fs__
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|int
name|__vector
name|__ev64_opaque__
typedef|;
end_typedef

begin_define
define|#
directive|define
name|__v2si
value|__ev64_opaque__
end_define

begin_define
define|#
directive|define
name|__v2sf
value|__ev64_fs__
end_define

begin_define
define|#
directive|define
name|__ev_addw
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|__builtin_spe_evaddw((__v2si) (a), (__v2si) (b))
end_define

begin_define
define|#
directive|define
name|__ev_addiw
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|__builtin_spe_evaddiw ((__v2si) (a), (b))
end_define

begin_define
define|#
directive|define
name|__ev_subfw
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|__builtin_spe_evsubfw ((__v2si) (a), (__v2si) (b))
end_define

begin_define
define|#
directive|define
name|__ev_subw
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|__builtin_spe_evsubfw ((__v2si) (b), (__v2si) (a))
end_define

begin_comment
comment|/* ??? The spe_evsubifw pattern accepts operands reversed, so we need to also    reverse them here between the intrinsic and the builtin function.  */
end_comment

begin_define
define|#
directive|define
name|__ev_subifw
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|__builtin_spe_evsubifw ((__v2si) (b), (a))
end_define

begin_define
define|#
directive|define
name|__ev_subiw
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|__builtin_spe_evsubifw ((__v2si) (a), (b))
end_define

begin_define
define|#
directive|define
name|__ev_abs
parameter_list|(
name|a
parameter_list|)
value|__builtin_spe_evabs ((__v2si) (a))
end_define

begin_define
define|#
directive|define
name|__ev_neg
parameter_list|(
name|a
parameter_list|)
value|__builtin_spe_evneg ((__v2si) (a))
end_define

begin_define
define|#
directive|define
name|__ev_extsb
parameter_list|(
name|a
parameter_list|)
value|__builtin_spe_evextsb ((__v2si) (a))
end_define

begin_define
define|#
directive|define
name|__ev_extsh
parameter_list|(
name|a
parameter_list|)
value|__builtin_spe_evextsh ((__v2si) (a))
end_define

begin_define
define|#
directive|define
name|__ev_and
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|__builtin_spe_evand ((__v2si) (a), (__v2si) (b))
end_define

begin_define
define|#
directive|define
name|__ev_or
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|__builtin_spe_evor ((__v2si) (a), (__v2si) (b))
end_define

begin_define
define|#
directive|define
name|__ev_xor
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|__builtin_spe_evxor ((__v2si) (a), (__v2si) (b))
end_define

begin_define
define|#
directive|define
name|__ev_nand
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|__builtin_spe_evnand ((__v2si) (a), (__v2si) (b))
end_define

begin_define
define|#
directive|define
name|__ev_nor
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|__builtin_spe_evnor ((__v2si) (a), (__v2si) (b))
end_define

begin_define
define|#
directive|define
name|__ev_eqv
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|__builtin_spe_eveqv ((__v2si) (a), (__v2si) (b))
end_define

begin_define
define|#
directive|define
name|__ev_andc
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|__builtin_spe_evandc ((__v2si) (a), (__v2si) (b))
end_define

begin_define
define|#
directive|define
name|__ev_orc
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|__builtin_spe_evorc ((__v2si) (a), (__v2si) (b))
end_define

begin_define
define|#
directive|define
name|__ev_rlw
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|__builtin_spe_evrlw ((__v2si) (a), (__v2si) (b))
end_define

begin_define
define|#
directive|define
name|__ev_rlwi
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|__builtin_spe_evrlwi ((__v2si) (a), (b))
end_define

begin_define
define|#
directive|define
name|__ev_slw
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|__builtin_spe_evslw ((__v2si) (a), (__v2si) (b))
end_define

begin_define
define|#
directive|define
name|__ev_slwi
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|__builtin_spe_evslwi ((__v2si) (a), (b))
end_define

begin_define
define|#
directive|define
name|__ev_srws
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|__builtin_spe_evsrws ((__v2si) (a), (__v2si) (b))
end_define

begin_define
define|#
directive|define
name|__ev_srwu
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|__builtin_spe_evsrwu ((__v2si) (a), (__v2si) (b))
end_define

begin_define
define|#
directive|define
name|__ev_srwis
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|__builtin_spe_evsrwis ((__v2si) (a), (b))
end_define

begin_define
define|#
directive|define
name|__ev_srwiu
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|__builtin_spe_evsrwiu ((__v2si) (a), (b))
end_define

begin_define
define|#
directive|define
name|__ev_cntlzw
parameter_list|(
name|a
parameter_list|)
value|__builtin_spe_evcntlzw ((__v2si) (a))
end_define

begin_define
define|#
directive|define
name|__ev_cntlsw
parameter_list|(
name|a
parameter_list|)
value|__builtin_spe_evcntlsw ((__v2si) (a))
end_define

begin_define
define|#
directive|define
name|__ev_rndw
parameter_list|(
name|a
parameter_list|)
value|__builtin_spe_evrndw ((__v2si) (a))
end_define

begin_define
define|#
directive|define
name|__ev_mergehi
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|__builtin_spe_evmergehi ((__v2si) (a), (__v2si) (b))
end_define

begin_define
define|#
directive|define
name|__ev_mergelo
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|__builtin_spe_evmergelo ((__v2si) (a), (__v2si) (b))
end_define

begin_define
define|#
directive|define
name|__ev_mergelohi
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|__builtin_spe_evmergelohi ((__v2si) (a), (__v2si) (b))
end_define

begin_define
define|#
directive|define
name|__ev_mergehilo
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|__builtin_spe_evmergehilo ((__v2si) (a), (__v2si) (b))
end_define

begin_define
define|#
directive|define
name|__ev_splati
parameter_list|(
name|a
parameter_list|)
value|__builtin_spe_evsplati ((a))
end_define

begin_define
define|#
directive|define
name|__ev_splatfi
parameter_list|(
name|a
parameter_list|)
value|__builtin_spe_evsplatfi ((a))
end_define

begin_define
define|#
directive|define
name|__ev_divws
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|__builtin_spe_evdivws ((__v2si) (a), (__v2si) (b))
end_define

begin_define
define|#
directive|define
name|__ev_divwu
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|__builtin_spe_evdivwu ((__v2si) (a), (__v2si) (b))
end_define

begin_define
define|#
directive|define
name|__ev_mra
parameter_list|(
name|a
parameter_list|)
value|__builtin_spe_evmra ((__v2si) (a))
end_define

begin_define
define|#
directive|define
name|__brinc
value|__builtin_spe_brinc
end_define

begin_comment
comment|/* Loads.  */
end_comment

begin_define
define|#
directive|define
name|__ev_lddx
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|__builtin_spe_evlddx ((void *)(a), (b))
end_define

begin_define
define|#
directive|define
name|__ev_ldwx
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|__builtin_spe_evldwx ((void *)(a), (b))
end_define

begin_define
define|#
directive|define
name|__ev_ldhx
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|__builtin_spe_evldhx ((void *)(a), (b))
end_define

begin_define
define|#
directive|define
name|__ev_lwhex
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|__builtin_spe_evlwhex ((a), (b))
end_define

begin_define
define|#
directive|define
name|__ev_lwhoux
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|__builtin_spe_evlwhoux ((a), (b))
end_define

begin_define
define|#
directive|define
name|__ev_lwhosx
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|__builtin_spe_evlwhosx ((a), (b))
end_define

begin_define
define|#
directive|define
name|__ev_lwwsplatx
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|__builtin_spe_evlwwsplatx ((a), (b))
end_define

begin_define
define|#
directive|define
name|__ev_lwhsplatx
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|__builtin_spe_evlwhsplatx ((a), (b))
end_define

begin_define
define|#
directive|define
name|__ev_lhhesplatx
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|__builtin_spe_evlhhesplatx ((a), (b))
end_define

begin_define
define|#
directive|define
name|__ev_lhhousplatx
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|__builtin_spe_evlhhousplatx ((a), (b))
end_define

begin_define
define|#
directive|define
name|__ev_lhhossplatx
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|__builtin_spe_evlhhossplatx ((a), (b))
end_define

begin_define
define|#
directive|define
name|__ev_ldd
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|__builtin_spe_evldd ((void *)(a), (b))
end_define

begin_define
define|#
directive|define
name|__ev_ldw
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|__builtin_spe_evldw ((void *)(a), (b))
end_define

begin_define
define|#
directive|define
name|__ev_ldh
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|__builtin_spe_evldh ((void *)(a), (b))
end_define

begin_define
define|#
directive|define
name|__ev_lwhe
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|__builtin_spe_evlwhe ((a), (b))
end_define

begin_define
define|#
directive|define
name|__ev_lwhou
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|__builtin_spe_evlwhou ((a), (b))
end_define

begin_define
define|#
directive|define
name|__ev_lwhos
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|__builtin_spe_evlwhos ((a), (b))
end_define

begin_define
define|#
directive|define
name|__ev_lwwsplat
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|__builtin_spe_evlwwsplat ((a), (b))
end_define

begin_define
define|#
directive|define
name|__ev_lwhsplat
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|__builtin_spe_evlwhsplat ((a), (b))
end_define

begin_define
define|#
directive|define
name|__ev_lhhesplat
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|__builtin_spe_evlhhesplat ((a), (b))
end_define

begin_define
define|#
directive|define
name|__ev_lhhousplat
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|__builtin_spe_evlhhousplat ((a), (b))
end_define

begin_define
define|#
directive|define
name|__ev_lhhossplat
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|__builtin_spe_evlhhossplat ((a), (b))
end_define

begin_comment
comment|/* Stores.  */
end_comment

begin_define
define|#
directive|define
name|__ev_stddx
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|)
value|__builtin_spe_evstddx ((__v2si)(a), (void *)(b), (c))
end_define

begin_define
define|#
directive|define
name|__ev_stdwx
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|)
value|__builtin_spe_evstdwx ((__v2si)(a), (void *)(b), (c))
end_define

begin_define
define|#
directive|define
name|__ev_stdhx
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|)
value|__builtin_spe_evstdhx ((__v2si)(a), (void *)(b), (c))
end_define

begin_define
define|#
directive|define
name|__ev_stwwex
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|)
value|__builtin_spe_evstwwex ((__v2si)(a), (b), (c))
end_define

begin_define
define|#
directive|define
name|__ev_stwwox
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|)
value|__builtin_spe_evstwwox ((__v2si)(a), (b), (c))
end_define

begin_define
define|#
directive|define
name|__ev_stwhex
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|)
value|__builtin_spe_evstwhex ((__v2si)(a), (b), (c))
end_define

begin_define
define|#
directive|define
name|__ev_stwhox
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|)
value|__builtin_spe_evstwhox ((__v2si)(a), (b), (c))
end_define

begin_define
define|#
directive|define
name|__ev_stdd
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|)
value|__builtin_spe_evstdd ((__v2si)(a), (void *)(b), (c))
end_define

begin_define
define|#
directive|define
name|__ev_stdw
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|)
value|__builtin_spe_evstdw ((__v2si)(a), (void *)(b), (c))
end_define

begin_define
define|#
directive|define
name|__ev_stdh
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|)
value|__builtin_spe_evstdh ((__v2si)(a), (void *)(b), (c))
end_define

begin_define
define|#
directive|define
name|__ev_stwwe
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|)
value|__builtin_spe_evstwwe ((__v2si)(a), (b), (c))
end_define

begin_define
define|#
directive|define
name|__ev_stwwo
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|)
value|__builtin_spe_evstwwo ((__v2si)(a), (b), (c))
end_define

begin_define
define|#
directive|define
name|__ev_stwhe
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|)
value|__builtin_spe_evstwhe ((__v2si)(a), (b), (c))
end_define

begin_define
define|#
directive|define
name|__ev_stwho
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|)
value|__builtin_spe_evstwho ((__v2si)(a), (b), (c))
end_define

begin_comment
comment|/* Fixed point complex.  */
end_comment

begin_define
define|#
directive|define
name|__ev_mhossf
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|__builtin_spe_evmhossf ((__v2si) (a), (__v2si) (b))
end_define

begin_define
define|#
directive|define
name|__ev_mhosmf
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|__builtin_spe_evmhosmf ((__v2si) (a), (__v2si) (b))
end_define

begin_define
define|#
directive|define
name|__ev_mhosmi
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|__builtin_spe_evmhosmi ((__v2si) (a), (__v2si) (b))
end_define

begin_define
define|#
directive|define
name|__ev_mhoumi
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|__builtin_spe_evmhoumi ((__v2si) (a), (__v2si) (b))
end_define

begin_define
define|#
directive|define
name|__ev_mhessf
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|__builtin_spe_evmhessf ((__v2si) (a), (__v2si) (b))
end_define

begin_define
define|#
directive|define
name|__ev_mhesmf
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|__builtin_spe_evmhesmf ((__v2si) (a), (__v2si) (b))
end_define

begin_define
define|#
directive|define
name|__ev_mhesmi
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|__builtin_spe_evmhesmi ((__v2si) (a), (__v2si) (b))
end_define

begin_define
define|#
directive|define
name|__ev_mheumi
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|__builtin_spe_evmheumi ((__v2si) (a), (__v2si) (b))
end_define

begin_define
define|#
directive|define
name|__ev_mhossfa
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|__builtin_spe_evmhossfa ((__v2si) (a), (__v2si) (b))
end_define

begin_define
define|#
directive|define
name|__ev_mhosmfa
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|__builtin_spe_evmhosmfa ((__v2si) (a), (__v2si) (b))
end_define

begin_define
define|#
directive|define
name|__ev_mhosmia
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|__builtin_spe_evmhosmia ((__v2si) (a), (__v2si) (b))
end_define

begin_define
define|#
directive|define
name|__ev_mhoumia
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|__builtin_spe_evmhoumia ((__v2si) (a), (__v2si) (b))
end_define

begin_define
define|#
directive|define
name|__ev_mhessfa
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|__builtin_spe_evmhessfa ((__v2si) (a), (__v2si) (b))
end_define

begin_define
define|#
directive|define
name|__ev_mhesmfa
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|__builtin_spe_evmhesmfa ((__v2si) (a), (__v2si) (b))
end_define

begin_define
define|#
directive|define
name|__ev_mhesmia
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|__builtin_spe_evmhesmia ((__v2si) (a), (__v2si) (b))
end_define

begin_define
define|#
directive|define
name|__ev_mheumia
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|__builtin_spe_evmheumia ((__v2si) (a), (__v2si) (b))
end_define

begin_define
define|#
directive|define
name|__ev_mhoumf
value|__ev_mhoumi
end_define

begin_define
define|#
directive|define
name|__ev_mheumf
value|__ev_mheumi
end_define

begin_define
define|#
directive|define
name|__ev_mhoumfa
value|__ev_mhoumia
end_define

begin_define
define|#
directive|define
name|__ev_mheumfa
value|__ev_mheumia
end_define

begin_define
define|#
directive|define
name|__ev_mhossfaaw
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|__builtin_spe_evmhossfaaw ((__v2si) (a), (__v2si) (b))
end_define

begin_define
define|#
directive|define
name|__ev_mhossiaaw
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|__builtin_spe_evmhossiaaw ((__v2si) (a), (__v2si) (b))
end_define

begin_define
define|#
directive|define
name|__ev_mhosmfaaw
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|__builtin_spe_evmhosmfaaw ((__v2si) (a), (__v2si) (b))
end_define

begin_define
define|#
directive|define
name|__ev_mhosmiaaw
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|__builtin_spe_evmhosmiaaw ((__v2si) (a), (__v2si) (b))
end_define

begin_define
define|#
directive|define
name|__ev_mhousiaaw
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|__builtin_spe_evmhousiaaw ((__v2si) (a), (__v2si) (b))
end_define

begin_define
define|#
directive|define
name|__ev_mhoumiaaw
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|__builtin_spe_evmhoumiaaw ((__v2si) (a), (__v2si) (b))
end_define

begin_define
define|#
directive|define
name|__ev_mhessfaaw
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|__builtin_spe_evmhessfaaw ((__v2si) (a), (__v2si) (b))
end_define

begin_define
define|#
directive|define
name|__ev_mhessiaaw
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|__builtin_spe_evmhessiaaw ((__v2si) (a), (__v2si) (b))
end_define

begin_define
define|#
directive|define
name|__ev_mhesmfaaw
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|__builtin_spe_evmhesmfaaw ((__v2si) (a), (__v2si) (b))
end_define

begin_define
define|#
directive|define
name|__ev_mhesmiaaw
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|__builtin_spe_evmhesmiaaw ((__v2si) (a), (__v2si) (b))
end_define

begin_define
define|#
directive|define
name|__ev_mheusiaaw
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|__builtin_spe_evmheusiaaw ((__v2si) (a), (__v2si) (b))
end_define

begin_define
define|#
directive|define
name|__ev_mheumiaaw
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|__builtin_spe_evmheumiaaw ((__v2si) (a), (__v2si) (b))
end_define

begin_define
define|#
directive|define
name|__ev_mhousfaaw
value|__ev_mhousiaaw
end_define

begin_define
define|#
directive|define
name|__ev_mhoumfaaw
value|__ev_mhoumiaaw
end_define

begin_define
define|#
directive|define
name|__ev_mheusfaaw
value|__ev_mheusiaaw
end_define

begin_define
define|#
directive|define
name|__ev_mheumfaaw
value|__ev_mheumiaaw
end_define

begin_define
define|#
directive|define
name|__ev_mhossfanw
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|__builtin_spe_evmhossfanw ((__v2si) (a), (__v2si) (b))
end_define

begin_define
define|#
directive|define
name|__ev_mhossianw
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|__builtin_spe_evmhossianw ((__v2si) (a), (__v2si) (b))
end_define

begin_define
define|#
directive|define
name|__ev_mhosmfanw
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|__builtin_spe_evmhosmfanw ((__v2si) (a), (__v2si) (b))
end_define

begin_define
define|#
directive|define
name|__ev_mhosmianw
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|__builtin_spe_evmhosmianw ((__v2si) (a), (__v2si) (b))
end_define

begin_define
define|#
directive|define
name|__ev_mhousianw
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|__builtin_spe_evmhousianw ((__v2si) (a), (__v2si) (b))
end_define

begin_define
define|#
directive|define
name|__ev_mhoumianw
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|__builtin_spe_evmhoumianw ((__v2si) (a), (__v2si) (b))
end_define

begin_define
define|#
directive|define
name|__ev_mhessfanw
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|__builtin_spe_evmhessfanw ((__v2si) (a), (__v2si) (b))
end_define

begin_define
define|#
directive|define
name|__ev_mhessianw
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|__builtin_spe_evmhessianw ((__v2si) (a), (__v2si) (b))
end_define

begin_define
define|#
directive|define
name|__ev_mhesmfanw
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|__builtin_spe_evmhesmfanw ((__v2si) (a), (__v2si) (b))
end_define

begin_define
define|#
directive|define
name|__ev_mhesmianw
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|__builtin_spe_evmhesmianw ((__v2si) (a), (__v2si) (b))
end_define

begin_define
define|#
directive|define
name|__ev_mheusianw
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|__builtin_spe_evmheusianw ((__v2si) (a), (__v2si) (b))
end_define

begin_define
define|#
directive|define
name|__ev_mheumianw
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|__builtin_spe_evmheumianw ((__v2si) (a), (__v2si) (b))
end_define

begin_define
define|#
directive|define
name|__ev_mhousfanw
value|__ev_mhousianw
end_define

begin_define
define|#
directive|define
name|__ev_mhoumfanw
value|__ev_mhoumianw
end_define

begin_define
define|#
directive|define
name|__ev_mheusfanw
value|__ev_mheusianw
end_define

begin_define
define|#
directive|define
name|__ev_mheumfanw
value|__ev_mheumianw
end_define

begin_define
define|#
directive|define
name|__ev_mhogsmfaa
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|__builtin_spe_evmhogsmfaa ((__v2si) (a), (__v2si) (b))
end_define

begin_define
define|#
directive|define
name|__ev_mhogsmiaa
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|__builtin_spe_evmhogsmiaa ((__v2si) (a), (__v2si) (b))
end_define

begin_define
define|#
directive|define
name|__ev_mhogumiaa
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|__builtin_spe_evmhogumiaa ((__v2si) (a), (__v2si) (b))
end_define

begin_define
define|#
directive|define
name|__ev_mhegsmfaa
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|__builtin_spe_evmhegsmfaa ((__v2si) (a), (__v2si) (b))
end_define

begin_define
define|#
directive|define
name|__ev_mhegsmiaa
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|__builtin_spe_evmhegsmiaa ((__v2si) (a), (__v2si) (b))
end_define

begin_define
define|#
directive|define
name|__ev_mhegumiaa
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|__builtin_spe_evmhegumiaa ((__v2si) (a), (__v2si) (b))
end_define

begin_define
define|#
directive|define
name|__ev_mhogumfaa
value|__ev_mhogumiaa
end_define

begin_define
define|#
directive|define
name|__ev_mhegumfaa
value|__ev_mhegumiaa
end_define

begin_define
define|#
directive|define
name|__ev_mhogsmfan
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|__builtin_spe_evmhogsmfan ((__v2si) (a), (__v2si) (b))
end_define

begin_define
define|#
directive|define
name|__ev_mhogsmian
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|__builtin_spe_evmhogsmian ((__v2si) (a), (__v2si) (b))
end_define

begin_define
define|#
directive|define
name|__ev_mhogumian
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|__builtin_spe_evmhogumian ((__v2si) (a), (__v2si) (b))
end_define

begin_define
define|#
directive|define
name|__ev_mhegsmfan
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|__builtin_spe_evmhegsmfan ((__v2si) (a), (__v2si) (b))
end_define

begin_define
define|#
directive|define
name|__ev_mhegsmian
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|__builtin_spe_evmhegsmian ((__v2si) (a), (__v2si) (b))
end_define

begin_define
define|#
directive|define
name|__ev_mhegumian
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|__builtin_spe_evmhegumian ((__v2si) (a), (__v2si) (b))
end_define

begin_define
define|#
directive|define
name|__ev_mhogumfan
value|__ev_mhogumian
end_define

begin_define
define|#
directive|define
name|__ev_mhegumfan
value|__ev_mhegumian
end_define

begin_define
define|#
directive|define
name|__ev_mwhssf
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|__builtin_spe_evmwhssf ((__v2si) (a), (__v2si) (b))
end_define

begin_define
define|#
directive|define
name|__ev_mwhsmf
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|__builtin_spe_evmwhsmf ((__v2si) (a), (__v2si) (b))
end_define

begin_define
define|#
directive|define
name|__ev_mwhsmi
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|__builtin_spe_evmwhsmi ((__v2si) (a), (__v2si) (b))
end_define

begin_define
define|#
directive|define
name|__ev_mwhumi
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|__builtin_spe_evmwhumi ((__v2si) (a), (__v2si) (b))
end_define

begin_define
define|#
directive|define
name|__ev_mwhssfa
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|__builtin_spe_evmwhssfa ((__v2si) (a), (__v2si) (b))
end_define

begin_define
define|#
directive|define
name|__ev_mwhsmfa
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|__builtin_spe_evmwhsmfa ((__v2si) (a), (__v2si) (b))
end_define

begin_define
define|#
directive|define
name|__ev_mwhsmia
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|__builtin_spe_evmwhsmia ((__v2si) (a), (__v2si) (b))
end_define

begin_define
define|#
directive|define
name|__ev_mwhumia
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|__builtin_spe_evmwhumia ((__v2si) (a), (__v2si) (b))
end_define

begin_define
define|#
directive|define
name|__ev_mwhumf
value|__ev_mwhumi
end_define

begin_define
define|#
directive|define
name|__ev_mwhumfa
value|__ev_mwhumia
end_define

begin_define
define|#
directive|define
name|__ev_mwlumi
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|__builtin_spe_evmwlumi ((__v2si) (a), (__v2si) (b))
end_define

begin_define
define|#
directive|define
name|__ev_mwlumia
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|__builtin_spe_evmwlumia ((__v2si) (a), (__v2si) (b))
end_define

begin_define
define|#
directive|define
name|__ev_mwlumiaaw
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|__builtin_spe_evmwlumiaaw ((__v2si) (a), (__v2si) (b))
end_define

begin_define
define|#
directive|define
name|__ev_mwlssiaaw
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|__builtin_spe_evmwlssiaaw ((__v2si) (a), (__v2si) (b))
end_define

begin_define
define|#
directive|define
name|__ev_mwlsmiaaw
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|__builtin_spe_evmwlsmiaaw ((__v2si) (a), (__v2si) (b))
end_define

begin_define
define|#
directive|define
name|__ev_mwlusiaaw
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|__builtin_spe_evmwlusiaaw ((__v2si) (a), (__v2si) (b))
end_define

begin_define
define|#
directive|define
name|__ev_mwlusiaaw
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|__builtin_spe_evmwlusiaaw ((__v2si) (a), (__v2si) (b))
end_define

begin_define
define|#
directive|define
name|__ev_mwlssianw
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|__builtin_spe_evmwlssianw ((__v2si) (a), (__v2si) (b))
end_define

begin_define
define|#
directive|define
name|__ev_mwlsmianw
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|__builtin_spe_evmwlsmianw ((__v2si) (a), (__v2si) (b))
end_define

begin_define
define|#
directive|define
name|__ev_mwlusianw
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|__builtin_spe_evmwlusianw ((__v2si) (a), (__v2si) (b))
end_define

begin_define
define|#
directive|define
name|__ev_mwlumianw
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|__builtin_spe_evmwlumianw ((__v2si) (a), (__v2si) (b))
end_define

begin_define
define|#
directive|define
name|__ev_mwssf
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|__builtin_spe_evmwssf ((__v2si) (a), (__v2si) (b))
end_define

begin_define
define|#
directive|define
name|__ev_mwsmf
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|__builtin_spe_evmwsmf ((__v2si) (a), (__v2si) (b))
end_define

begin_define
define|#
directive|define
name|__ev_mwsmi
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|__builtin_spe_evmwsmi ((__v2si) (a), (__v2si) (b))
end_define

begin_define
define|#
directive|define
name|__ev_mwumi
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|__builtin_spe_evmwumi ((__v2si) (a), (__v2si) (b))
end_define

begin_define
define|#
directive|define
name|__ev_mwssfa
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|__builtin_spe_evmwssfa ((__v2si) (a), (__v2si) (b))
end_define

begin_define
define|#
directive|define
name|__ev_mwsmfa
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|__builtin_spe_evmwsmfa ((__v2si) (a), (__v2si) (b))
end_define

begin_define
define|#
directive|define
name|__ev_mwsmia
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|__builtin_spe_evmwsmia ((__v2si) (a), (__v2si) (b))
end_define

begin_define
define|#
directive|define
name|__ev_mwumia
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|__builtin_spe_evmwumia ((__v2si) (a), (__v2si) (b))
end_define

begin_define
define|#
directive|define
name|__ev_mwumf
value|__ev_mwumi
end_define

begin_define
define|#
directive|define
name|__ev_mwumfa
value|__ev_mwumia
end_define

begin_define
define|#
directive|define
name|__ev_mwssfaa
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|__builtin_spe_evmwssfaa ((__v2si) (a), (__v2si) (b))
end_define

begin_define
define|#
directive|define
name|__ev_mwsmfaa
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|__builtin_spe_evmwsmfaa ((__v2si) (a), (__v2si) (b))
end_define

begin_define
define|#
directive|define
name|__ev_mwsmiaa
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|__builtin_spe_evmwsmiaa ((__v2si) (a), (__v2si) (b))
end_define

begin_define
define|#
directive|define
name|__ev_mwumiaa
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|__builtin_spe_evmwumiaa ((__v2si) (a), (__v2si) (b))
end_define

begin_define
define|#
directive|define
name|__ev_mwumfaa
value|__ev_mwumiaa
end_define

begin_define
define|#
directive|define
name|__ev_mwssfan
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|__builtin_spe_evmwssfan ((__v2si) (a), (__v2si) (b))
end_define

begin_define
define|#
directive|define
name|__ev_mwsmfan
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|__builtin_spe_evmwsmfan ((__v2si) (a), (__v2si) (b))
end_define

begin_define
define|#
directive|define
name|__ev_mwsmian
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|__builtin_spe_evmwsmian ((__v2si) (a), (__v2si) (b))
end_define

begin_define
define|#
directive|define
name|__ev_mwumian
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|__builtin_spe_evmwumian ((__v2si) (a), (__v2si) (b))
end_define

begin_define
define|#
directive|define
name|__ev_mwumfan
value|__ev_mwumian
end_define

begin_define
define|#
directive|define
name|__ev_addssiaaw
parameter_list|(
name|a
parameter_list|)
value|__builtin_spe_evaddssiaaw ((__v2si) (a))
end_define

begin_define
define|#
directive|define
name|__ev_addsmiaaw
parameter_list|(
name|a
parameter_list|)
value|__builtin_spe_evaddsmiaaw ((__v2si) (a))
end_define

begin_define
define|#
directive|define
name|__ev_addusiaaw
parameter_list|(
name|a
parameter_list|)
value|__builtin_spe_evaddusiaaw ((__v2si) (a))
end_define

begin_define
define|#
directive|define
name|__ev_addumiaaw
parameter_list|(
name|a
parameter_list|)
value|__builtin_spe_evaddumiaaw ((__v2si) (a))
end_define

begin_define
define|#
directive|define
name|__ev_addusfaaw
value|__ev_addusiaaw
end_define

begin_define
define|#
directive|define
name|__ev_addumfaaw
value|__ev_addumiaaw
end_define

begin_define
define|#
directive|define
name|__ev_addsmfaaw
value|__ev_addsmiaaw
end_define

begin_define
define|#
directive|define
name|__ev_addssfaaw
value|__ev_addssiaaw
end_define

begin_define
define|#
directive|define
name|__ev_subfssiaaw
parameter_list|(
name|a
parameter_list|)
value|__builtin_spe_evsubfssiaaw ((__v2si) (a))
end_define

begin_define
define|#
directive|define
name|__ev_subfsmiaaw
parameter_list|(
name|a
parameter_list|)
value|__builtin_spe_evsubfsmiaaw ((__v2si) (a))
end_define

begin_define
define|#
directive|define
name|__ev_subfusiaaw
parameter_list|(
name|a
parameter_list|)
value|__builtin_spe_evsubfusiaaw ((__v2si) (a))
end_define

begin_define
define|#
directive|define
name|__ev_subfumiaaw
parameter_list|(
name|a
parameter_list|)
value|__builtin_spe_evsubfumiaaw ((__v2si) (a))
end_define

begin_define
define|#
directive|define
name|__ev_subfusfaaw
value|__ev_subfusiaaw
end_define

begin_define
define|#
directive|define
name|__ev_subfumfaaw
value|__ev_subfumiaaw
end_define

begin_define
define|#
directive|define
name|__ev_subfsmfaaw
value|__ev_subfsmiaaw
end_define

begin_define
define|#
directive|define
name|__ev_subfssfaaw
value|__ev_subfssiaaw
end_define

begin_comment
comment|/* Floating Point SIMD Instructions  */
end_comment

begin_comment
comment|/* These all return V2SF, but we need to cast them to V2SI    because the SPE expect all functions to be __ev64_opaque__.  */
end_comment

begin_define
define|#
directive|define
name|__ev_fsabs
parameter_list|(
name|a
parameter_list|)
value|((__v2si) __builtin_spe_evfsabs ((__v2sf) (a)))
end_define

begin_define
define|#
directive|define
name|__ev_fsnabs
parameter_list|(
name|a
parameter_list|)
value|((__v2si) __builtin_spe_evfsnabs ((__v2sf) (a)))
end_define

begin_define
define|#
directive|define
name|__ev_fsneg
parameter_list|(
name|a
parameter_list|)
value|((__v2si) __builtin_spe_evfsneg ((__v2sf) (a)))
end_define

begin_define
define|#
directive|define
name|__ev_fsadd
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|((__v2si) __builtin_spe_evfsadd ((__v2sf) (a), (__v2sf) (b)))
end_define

begin_define
define|#
directive|define
name|__ev_fssub
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|((__v2si) __builtin_spe_evfssub ((__v2sf) (a), (__v2sf) (b)))
end_define

begin_define
define|#
directive|define
name|__ev_fsmul
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|((__v2si) __builtin_spe_evfsmul ((__v2sf) (a), (__v2sf) b))
end_define

begin_define
define|#
directive|define
name|__ev_fsdiv
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|((__v2si) __builtin_spe_evfsdiv ((__v2sf) (a), (__v2sf) b))
end_define

begin_define
define|#
directive|define
name|__ev_fscfui
parameter_list|(
name|a
parameter_list|)
value|((__v2si) __builtin_spe_evfscfui ((__v2si) (a)))
end_define

begin_define
define|#
directive|define
name|__ev_fscfsi
parameter_list|(
name|a
parameter_list|)
value|((__v2si) __builtin_spe_evfscfsi ((__v2sf) (a)))
end_define

begin_define
define|#
directive|define
name|__ev_fscfuf
parameter_list|(
name|a
parameter_list|)
value|((__v2si) __builtin_spe_evfscfuf ((__v2sf) (a)))
end_define

begin_define
define|#
directive|define
name|__ev_fscfsf
parameter_list|(
name|a
parameter_list|)
value|((__v2si) __builtin_spe_evfscfsf ((__v2sf) (a)))
end_define

begin_define
define|#
directive|define
name|__ev_fsctui
parameter_list|(
name|a
parameter_list|)
value|((__v2si) __builtin_spe_evfsctui ((__v2sf) (a)))
end_define

begin_define
define|#
directive|define
name|__ev_fsctsi
parameter_list|(
name|a
parameter_list|)
value|((__v2si) __builtin_spe_evfsctsi ((__v2sf) (a)))
end_define

begin_define
define|#
directive|define
name|__ev_fsctuf
parameter_list|(
name|a
parameter_list|)
value|((__v2si) __builtin_spe_evfsctuf ((__v2sf) (a)))
end_define

begin_define
define|#
directive|define
name|__ev_fsctsf
parameter_list|(
name|a
parameter_list|)
value|((__v2si) __builtin_spe_evfsctsf ((__v2sf) (a)))
end_define

begin_define
define|#
directive|define
name|__ev_fsctuiz
parameter_list|(
name|a
parameter_list|)
value|((__v2si) __builtin_spe_evfsctuiz ((__v2sf) (a)))
end_define

begin_define
define|#
directive|define
name|__ev_fsctsiz
parameter_list|(
name|a
parameter_list|)
value|((__v2si) __builtin_spe_evfsctsiz ((__v2sf) (a)))
end_define

begin_comment
comment|/* NOT SUPPORTED IN FIRST e500, support via two instructions:  */
end_comment

begin_define
define|#
directive|define
name|__ev_mwhusfaaw
value|__ev_mwhusiaaw
end_define

begin_define
define|#
directive|define
name|__ev_mwhumfaaw
value|__ev_mwhumiaaw
end_define

begin_define
define|#
directive|define
name|__ev_mwhusfanw
value|__ev_mwhusianw
end_define

begin_define
define|#
directive|define
name|__ev_mwhumfanw
value|__ev_mwhumianw
end_define

begin_define
define|#
directive|define
name|__ev_mwhgumfaa
value|__ev_mwhgumiaa
end_define

begin_define
define|#
directive|define
name|__ev_mwhgumfan
value|__ev_mwhgumian
end_define

begin_define
define|#
directive|define
name|__ev_mwhgssfaa
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|__internal_ev_mwhgssfaa ((__v2si) (a), (__v2si) (b))
end_define

begin_define
define|#
directive|define
name|__ev_mwhgsmfaa
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|__internal_ev_mwhgsmfaa ((__v2si) (a), (__v2si) (b))
end_define

begin_define
define|#
directive|define
name|__ev_mwhgsmiaa
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|__internal_ev_mwhgsmiaa ((__v2si) (a), (__v2si) (b))
end_define

begin_define
define|#
directive|define
name|__ev_mwhgumiaa
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|__internal_ev_mwhgumiaa ((__v2si) (a), (__v2si) (b))
end_define

begin_define
define|#
directive|define
name|__ev_mwhgssfan
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|__internal_ev_mwhgssfan ((__v2si) (a), (__v2si) (b))
end_define

begin_define
define|#
directive|define
name|__ev_mwhgsmfan
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|__internal_ev_mwhgsmfan ((__v2si) (a), (__v2si) (b))
end_define

begin_define
define|#
directive|define
name|__ev_mwhgsmian
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|__internal_ev_mwhgsmian ((__v2si) (a), (__v2si) (b))
end_define

begin_define
define|#
directive|define
name|__ev_mwhgumian
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|__internal_ev_mwhgumian ((__v2si) (a), (__v2si) (b))
end_define

begin_define
define|#
directive|define
name|__ev_mwhssiaaw
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|__internal_ev_mwhssiaaw ((__v2si) (a), (__v2si) (b))
end_define

begin_define
define|#
directive|define
name|__ev_mwhssfaaw
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|__internal_ev_mwhssfaaw ((__v2si) (a), (__v2si) (b))
end_define

begin_define
define|#
directive|define
name|__ev_mwhsmfaaw
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|__internal_ev_mwhsmfaaw ((__v2si) (a), (__v2si) (b))
end_define

begin_define
define|#
directive|define
name|__ev_mwhsmiaaw
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|__internal_ev_mwhsmiaaw ((__v2si) (a), (__v2si) (b))
end_define

begin_define
define|#
directive|define
name|__ev_mwhusiaaw
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|__internal_ev_mwhusiaaw ((__v2si) (a), (__v2si) (b))
end_define

begin_define
define|#
directive|define
name|__ev_mwhumiaaw
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|__internal_ev_mwhumiaaw ((__v2si) (a), (__v2si) (b))
end_define

begin_define
define|#
directive|define
name|__ev_mwhssfanw
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|__internal_ev_mwhssfanw ((__v2si) (a), (__v2si) (b))
end_define

begin_define
define|#
directive|define
name|__ev_mwhssianw
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|__internal_ev_mwhssianw ((__v2si) (a), (__v2si) (b))
end_define

begin_define
define|#
directive|define
name|__ev_mwhsmfanw
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|__internal_ev_mwhsmfanw ((__v2si) (a), (__v2si) (b))
end_define

begin_define
define|#
directive|define
name|__ev_mwhsmianw
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|__internal_ev_mwhsmianw ((__v2si) (a), (__v2si) (b))
end_define

begin_define
define|#
directive|define
name|__ev_mwhusianw
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|__internal_ev_mwhusianw ((__v2si) (a), (__v2si) (b))
end_define

begin_define
define|#
directive|define
name|__ev_mwhumianw
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|__internal_ev_mwhumianw ((__v2si) (a), (__v2si) (b))
end_define

begin_function
specifier|static
specifier|inline
name|__ev64_opaque__
name|__internal_ev_mwhssfaaw
parameter_list|(
name|__ev64_opaque__
name|a
parameter_list|,
name|__ev64_opaque__
name|b
parameter_list|)
block|{
name|__ev64_opaque__
name|t
decl_stmt|;
name|t
operator|=
name|__ev_mwhssf
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
expr_stmt|;
return|return
name|__ev_addssiaaw
argument_list|(
name|t
argument_list|)
return|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|__ev64_opaque__
name|__internal_ev_mwhssiaaw
parameter_list|(
name|__ev64_opaque__
name|a
parameter_list|,
name|__ev64_opaque__
name|b
parameter_list|)
block|{
name|__ev64_opaque__
name|t
decl_stmt|;
name|t
operator|=
name|__ev_mwhsmi
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
expr_stmt|;
return|return
name|__ev_addssiaaw
argument_list|(
name|t
argument_list|)
return|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|__ev64_opaque__
name|__internal_ev_mwhsmfaaw
parameter_list|(
name|__ev64_opaque__
name|a
parameter_list|,
name|__ev64_opaque__
name|b
parameter_list|)
block|{
name|__ev64_opaque__
name|t
decl_stmt|;
name|t
operator|=
name|__ev_mwhsmf
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
expr_stmt|;
return|return
name|__ev_addsmiaaw
argument_list|(
name|t
argument_list|)
return|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|__ev64_opaque__
name|__internal_ev_mwhsmiaaw
parameter_list|(
name|__ev64_opaque__
name|a
parameter_list|,
name|__ev64_opaque__
name|b
parameter_list|)
block|{
name|__ev64_opaque__
name|t
decl_stmt|;
name|t
operator|=
name|__ev_mwhsmi
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
expr_stmt|;
return|return
name|__ev_addsmiaaw
argument_list|(
name|t
argument_list|)
return|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|__ev64_opaque__
name|__internal_ev_mwhusiaaw
parameter_list|(
name|__ev64_opaque__
name|a
parameter_list|,
name|__ev64_opaque__
name|b
parameter_list|)
block|{
name|__ev64_opaque__
name|t
decl_stmt|;
name|t
operator|=
name|__ev_mwhumi
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
expr_stmt|;
return|return
name|__ev_addusiaaw
argument_list|(
name|t
argument_list|)
return|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|__ev64_opaque__
name|__internal_ev_mwhumiaaw
parameter_list|(
name|__ev64_opaque__
name|a
parameter_list|,
name|__ev64_opaque__
name|b
parameter_list|)
block|{
name|__ev64_opaque__
name|t
decl_stmt|;
name|t
operator|=
name|__ev_mwhumi
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
expr_stmt|;
return|return
name|__ev_addumiaaw
argument_list|(
name|t
argument_list|)
return|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|__ev64_opaque__
name|__internal_ev_mwhssfanw
parameter_list|(
name|__ev64_opaque__
name|a
parameter_list|,
name|__ev64_opaque__
name|b
parameter_list|)
block|{
name|__ev64_opaque__
name|t
decl_stmt|;
name|t
operator|=
name|__ev_mwhssf
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
expr_stmt|;
return|return
name|__ev_subfssiaaw
argument_list|(
name|t
argument_list|)
return|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|__ev64_opaque__
name|__internal_ev_mwhssianw
parameter_list|(
name|__ev64_opaque__
name|a
parameter_list|,
name|__ev64_opaque__
name|b
parameter_list|)
block|{
name|__ev64_opaque__
name|t
decl_stmt|;
name|t
operator|=
name|__ev_mwhsmi
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
expr_stmt|;
return|return
name|__ev_subfssiaaw
argument_list|(
name|t
argument_list|)
return|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|__ev64_opaque__
name|__internal_ev_mwhsmfanw
parameter_list|(
name|__ev64_opaque__
name|a
parameter_list|,
name|__ev64_opaque__
name|b
parameter_list|)
block|{
name|__ev64_opaque__
name|t
decl_stmt|;
name|t
operator|=
name|__ev_mwhsmf
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
expr_stmt|;
return|return
name|__ev_subfsmiaaw
argument_list|(
name|t
argument_list|)
return|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|__ev64_opaque__
name|__internal_ev_mwhsmianw
parameter_list|(
name|__ev64_opaque__
name|a
parameter_list|,
name|__ev64_opaque__
name|b
parameter_list|)
block|{
name|__ev64_opaque__
name|t
decl_stmt|;
name|t
operator|=
name|__ev_mwhsmi
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
expr_stmt|;
return|return
name|__ev_subfsmiaaw
argument_list|(
name|t
argument_list|)
return|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|__ev64_opaque__
name|__internal_ev_mwhusianw
parameter_list|(
name|__ev64_opaque__
name|a
parameter_list|,
name|__ev64_opaque__
name|b
parameter_list|)
block|{
name|__ev64_opaque__
name|t
decl_stmt|;
name|t
operator|=
name|__ev_mwhumi
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
expr_stmt|;
return|return
name|__ev_subfusiaaw
argument_list|(
name|t
argument_list|)
return|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|__ev64_opaque__
name|__internal_ev_mwhumianw
parameter_list|(
name|__ev64_opaque__
name|a
parameter_list|,
name|__ev64_opaque__
name|b
parameter_list|)
block|{
name|__ev64_opaque__
name|t
decl_stmt|;
name|t
operator|=
name|__ev_mwhumi
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
expr_stmt|;
return|return
name|__ev_subfumiaaw
argument_list|(
name|t
argument_list|)
return|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|__ev64_opaque__
name|__internal_ev_mwhgssfaa
parameter_list|(
name|__ev64_opaque__
name|a
parameter_list|,
name|__ev64_opaque__
name|b
parameter_list|)
block|{
name|__ev64_opaque__
name|t
decl_stmt|;
name|t
operator|=
name|__ev_mwhssf
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
expr_stmt|;
return|return
name|__ev_mwsmiaa
argument_list|(
name|t
argument_list|,
operator|(
operator|(
name|__ev64_s32__
operator|)
block|{
literal|1
block|,
literal|1
block|}
operator|)
argument_list|)
return|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|__ev64_opaque__
name|__internal_ev_mwhgsmfaa
parameter_list|(
name|__ev64_opaque__
name|a
parameter_list|,
name|__ev64_opaque__
name|b
parameter_list|)
block|{
name|__ev64_opaque__
name|t
decl_stmt|;
name|t
operator|=
name|__ev_mwhsmf
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
expr_stmt|;
return|return
name|__ev_mwsmiaa
argument_list|(
name|t
argument_list|,
operator|(
operator|(
name|__ev64_s32__
operator|)
block|{
literal|1
block|,
literal|1
block|}
operator|)
argument_list|)
return|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|__ev64_opaque__
name|__internal_ev_mwhgsmiaa
parameter_list|(
name|__ev64_opaque__
name|a
parameter_list|,
name|__ev64_opaque__
name|b
parameter_list|)
block|{
name|__ev64_opaque__
name|t
decl_stmt|;
name|t
operator|=
name|__ev_mwhsmi
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
expr_stmt|;
return|return
name|__ev_mwsmiaa
argument_list|(
name|t
argument_list|,
operator|(
operator|(
name|__ev64_s32__
operator|)
block|{
literal|1
block|,
literal|1
block|}
operator|)
argument_list|)
return|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|__ev64_opaque__
name|__internal_ev_mwhgumiaa
parameter_list|(
name|__ev64_opaque__
name|a
parameter_list|,
name|__ev64_opaque__
name|b
parameter_list|)
block|{
name|__ev64_opaque__
name|t
decl_stmt|;
name|t
operator|=
name|__ev_mwhumi
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
expr_stmt|;
return|return
name|__ev_mwumiaa
argument_list|(
name|t
argument_list|,
operator|(
operator|(
name|__ev64_s32__
operator|)
block|{
literal|1
block|,
literal|1
block|}
operator|)
argument_list|)
return|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|__ev64_opaque__
name|__internal_ev_mwhgssfan
parameter_list|(
name|__ev64_opaque__
name|a
parameter_list|,
name|__ev64_opaque__
name|b
parameter_list|)
block|{
name|__ev64_opaque__
name|t
decl_stmt|;
name|t
operator|=
name|__ev_mwhssf
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
expr_stmt|;
return|return
name|__ev_mwsmian
argument_list|(
name|t
argument_list|,
operator|(
operator|(
name|__ev64_s32__
operator|)
block|{
literal|1
block|,
literal|1
block|}
operator|)
argument_list|)
return|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|__ev64_opaque__
name|__internal_ev_mwhgsmfan
parameter_list|(
name|__ev64_opaque__
name|a
parameter_list|,
name|__ev64_opaque__
name|b
parameter_list|)
block|{
name|__ev64_opaque__
name|t
decl_stmt|;
name|t
operator|=
name|__ev_mwhsmf
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
expr_stmt|;
return|return
name|__ev_mwsmian
argument_list|(
name|t
argument_list|,
operator|(
operator|(
name|__ev64_s32__
operator|)
block|{
literal|1
block|,
literal|1
block|}
operator|)
argument_list|)
return|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|__ev64_opaque__
name|__internal_ev_mwhgsmian
parameter_list|(
name|__ev64_opaque__
name|a
parameter_list|,
name|__ev64_opaque__
name|b
parameter_list|)
block|{
name|__ev64_opaque__
name|t
decl_stmt|;
name|t
operator|=
name|__ev_mwhsmi
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
expr_stmt|;
return|return
name|__ev_mwsmian
argument_list|(
name|t
argument_list|,
operator|(
operator|(
name|__ev64_s32__
operator|)
block|{
literal|1
block|,
literal|1
block|}
operator|)
argument_list|)
return|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|__ev64_opaque__
name|__internal_ev_mwhgumian
parameter_list|(
name|__ev64_opaque__
name|a
parameter_list|,
name|__ev64_opaque__
name|b
parameter_list|)
block|{
name|__ev64_opaque__
name|t
decl_stmt|;
name|t
operator|=
name|__ev_mwhumi
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
expr_stmt|;
return|return
name|__ev_mwumian
argument_list|(
name|t
argument_list|,
operator|(
operator|(
name|__ev64_s32__
operator|)
block|{
literal|1
block|,
literal|1
block|}
operator|)
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/* END OF NOT SUPPORTED */
end_comment

begin_comment
comment|/* __ev_create* functions.  */
end_comment

begin_define
define|#
directive|define
name|__ev_create_ufix32_u32
value|__ev_create_u32
end_define

begin_define
define|#
directive|define
name|__ev_create_sfix32_s32
value|__ev_create_s32
end_define

begin_function
specifier|static
specifier|inline
name|__ev64_opaque__
name|__ev_create_s16
parameter_list|(
name|int16_t
name|a
parameter_list|,
name|int16_t
name|b
parameter_list|,
name|int16_t
name|c
parameter_list|,
name|int16_t
name|d
parameter_list|)
block|{
union|union
block|{
name|__ev64_opaque__
name|v
decl_stmt|;
name|int16_t
name|i
index|[
literal|4
index|]
decl_stmt|;
block|}
name|u
union|;
name|u
operator|.
name|i
index|[
literal|0
index|]
operator|=
name|a
expr_stmt|;
name|u
operator|.
name|i
index|[
literal|1
index|]
operator|=
name|b
expr_stmt|;
name|u
operator|.
name|i
index|[
literal|2
index|]
operator|=
name|c
expr_stmt|;
name|u
operator|.
name|i
index|[
literal|3
index|]
operator|=
name|d
expr_stmt|;
return|return
name|u
operator|.
name|v
return|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|__ev64_opaque__
name|__ev_create_u16
parameter_list|(
name|uint16_t
name|a
parameter_list|,
name|uint16_t
name|b
parameter_list|,
name|uint16_t
name|c
parameter_list|,
name|uint16_t
name|d
parameter_list|)
block|{
union|union
block|{
name|__ev64_opaque__
name|v
decl_stmt|;
name|uint16_t
name|i
index|[
literal|4
index|]
decl_stmt|;
block|}
name|u
union|;
name|u
operator|.
name|i
index|[
literal|0
index|]
operator|=
name|a
expr_stmt|;
name|u
operator|.
name|i
index|[
literal|1
index|]
operator|=
name|b
expr_stmt|;
name|u
operator|.
name|i
index|[
literal|2
index|]
operator|=
name|c
expr_stmt|;
name|u
operator|.
name|i
index|[
literal|3
index|]
operator|=
name|d
expr_stmt|;
return|return
name|u
operator|.
name|v
return|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|__ev64_opaque__
name|__ev_create_s32
parameter_list|(
name|int32_t
name|a
parameter_list|,
name|int32_t
name|b
parameter_list|)
block|{
union|union
block|{
name|__ev64_opaque__
name|v
decl_stmt|;
name|int32_t
name|i
index|[
literal|2
index|]
decl_stmt|;
block|}
name|u
union|;
name|u
operator|.
name|i
index|[
literal|0
index|]
operator|=
name|a
expr_stmt|;
name|u
operator|.
name|i
index|[
literal|1
index|]
operator|=
name|b
expr_stmt|;
return|return
name|u
operator|.
name|v
return|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|__ev64_opaque__
name|__ev_create_u32
parameter_list|(
name|uint32_t
name|a
parameter_list|,
name|uint32_t
name|b
parameter_list|)
block|{
union|union
block|{
name|__ev64_opaque__
name|v
decl_stmt|;
name|uint32_t
name|i
index|[
literal|2
index|]
decl_stmt|;
block|}
name|u
union|;
name|u
operator|.
name|i
index|[
literal|0
index|]
operator|=
name|a
expr_stmt|;
name|u
operator|.
name|i
index|[
literal|1
index|]
operator|=
name|b
expr_stmt|;
return|return
name|u
operator|.
name|v
return|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|__ev64_opaque__
name|__ev_create_fs
parameter_list|(
name|float
name|a
parameter_list|,
name|float
name|b
parameter_list|)
block|{
union|union
block|{
name|__ev64_opaque__
name|v
decl_stmt|;
name|float
name|f
index|[
literal|2
index|]
decl_stmt|;
block|}
name|u
union|;
name|u
operator|.
name|f
index|[
literal|0
index|]
operator|=
name|a
expr_stmt|;
name|u
operator|.
name|f
index|[
literal|1
index|]
operator|=
name|b
expr_stmt|;
return|return
name|u
operator|.
name|v
return|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|__ev64_opaque__
name|__ev_create_sfix32_fs
parameter_list|(
name|float
name|a
parameter_list|,
name|float
name|b
parameter_list|)
block|{
name|__ev64_opaque__
name|ev
decl_stmt|;
name|ev
operator|=
operator|(
name|__ev64_opaque__
operator|)
name|__ev_create_fs
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
expr_stmt|;
return|return
operator|(
name|__ev64_opaque__
operator|)
name|__builtin_spe_evfsctsf
argument_list|(
operator|(
name|__v2sf
operator|)
name|ev
argument_list|)
return|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|__ev64_opaque__
name|__ev_create_ufix32_fs
parameter_list|(
name|float
name|a
parameter_list|,
name|float
name|b
parameter_list|)
block|{
name|__ev64_opaque__
name|ev
decl_stmt|;
name|ev
operator|=
operator|(
name|__ev64_opaque__
operator|)
name|__ev_create_fs
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
expr_stmt|;
return|return
operator|(
name|__ev64_opaque__
operator|)
name|__builtin_spe_evfsctuf
argument_list|(
operator|(
name|__v2sf
operator|)
name|ev
argument_list|)
return|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|__ev64_opaque__
name|__ev_create_s64
parameter_list|(
name|int64_t
name|a
parameter_list|)
block|{
union|union
block|{
name|__ev64_opaque__
name|v
decl_stmt|;
name|int64_t
name|i
decl_stmt|;
block|}
name|u
union|;
name|u
operator|.
name|i
operator|=
name|a
expr_stmt|;
return|return
name|u
operator|.
name|v
return|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|__ev64_opaque__
name|__ev_create_u64
parameter_list|(
name|uint64_t
name|a
parameter_list|)
block|{
union|union
block|{
name|__ev64_opaque__
name|v
decl_stmt|;
name|uint64_t
name|i
decl_stmt|;
block|}
name|u
union|;
name|u
operator|.
name|i
operator|=
name|a
expr_stmt|;
return|return
name|u
operator|.
name|v
return|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|uint64_t
name|__ev_convert_u64
parameter_list|(
name|__ev64_opaque__
name|a
parameter_list|)
block|{
return|return
operator|(
name|uint64_t
operator|)
name|a
return|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|int64_t
name|__ev_convert_s64
parameter_list|(
name|__ev64_opaque__
name|a
parameter_list|)
block|{
return|return
operator|(
name|int64_t
operator|)
name|a
return|;
block|}
end_function

begin_comment
comment|/* __ev_get_* functions.  */
end_comment

begin_define
define|#
directive|define
name|__ev_get_upper_u32
parameter_list|(
name|a
parameter_list|)
value|__ev_get_u32_internal ((__ev64_opaque__) (a), 0)
end_define

begin_define
define|#
directive|define
name|__ev_get_lower_u32
parameter_list|(
name|a
parameter_list|)
value|__ev_get_u32_internal ((__ev64_opaque__) (a), 1)
end_define

begin_define
define|#
directive|define
name|__ev_get_upper_s32
parameter_list|(
name|a
parameter_list|)
value|__ev_get_s32_internal ((__ev64_opaque__) (a), 0)
end_define

begin_define
define|#
directive|define
name|__ev_get_lower_s32
parameter_list|(
name|a
parameter_list|)
value|__ev_get_s32_internal ((__ev64_opaque__) (a), 1)
end_define

begin_define
define|#
directive|define
name|__ev_get_upper_fs
parameter_list|(
name|a
parameter_list|)
value|__ev_get_fs_internal ((__ev64_opaque__) (a), 0)
end_define

begin_define
define|#
directive|define
name|__ev_get_lower_fs
parameter_list|(
name|a
parameter_list|)
value|__ev_get_fs_internal ((__ev64_opaque__) (a), 1)
end_define

begin_define
define|#
directive|define
name|__ev_get_upper_ufix32_u32
parameter_list|(
name|a
parameter_list|)
value|__ev_get_upper_u32(a)
end_define

begin_define
define|#
directive|define
name|__ev_get_lower_ufix32_u32
parameter_list|(
name|a
parameter_list|)
value|__ev_get_lower_u32(a)
end_define

begin_define
define|#
directive|define
name|__ev_get_upper_sfix32_s32
parameter_list|(
name|a
parameter_list|)
value|__ev_get_upper_s32(a)
end_define

begin_define
define|#
directive|define
name|__ev_get_lower_sfix32_s32
parameter_list|(
name|a
parameter_list|)
value|__ev_get_lower_s32(a)
end_define

begin_define
define|#
directive|define
name|__ev_get_upper_sfix32_fs
parameter_list|(
name|a
parameter_list|)
value|__ev_get_sfix32_fs (a, 0)
end_define

begin_define
define|#
directive|define
name|__ev_get_lower_sfix32_fs
parameter_list|(
name|a
parameter_list|)
value|__ev_get_sfix32_fs (a, 1)
end_define

begin_define
define|#
directive|define
name|__ev_get_upper_ufix32_fs
parameter_list|(
name|a
parameter_list|)
value|__ev_get_ufix32_fs (a, 0)
end_define

begin_define
define|#
directive|define
name|__ev_get_lower_ufix32_fs
parameter_list|(
name|a
parameter_list|)
value|__ev_get_ufix32_fs (a, 1)
end_define

begin_define
define|#
directive|define
name|__ev_get_u32
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|__ev_get_u32_internal ((__ev64_opaque__) (a), b)
end_define

begin_define
define|#
directive|define
name|__ev_get_s32
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|__ev_get_s32_internal ((__ev64_opaque__) (a), b)
end_define

begin_define
define|#
directive|define
name|__ev_get_fs
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|__ev_get_fs_internal ((__ev64_opaque__) (a), b)
end_define

begin_define
define|#
directive|define
name|__ev_get_u16
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|__ev_get_u16_internal ((__ev64_opaque__) (a), b)
end_define

begin_define
define|#
directive|define
name|__ev_get_s16
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|__ev_get_s16_internal ((__ev64_opaque__) (a), b)
end_define

begin_define
define|#
directive|define
name|__ev_get_ufix32_u32
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|__ev_get_u32 (a, b)
end_define

begin_define
define|#
directive|define
name|__ev_get_sfix32_s32
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|__ev_get_s32 (a, b)
end_define

begin_define
define|#
directive|define
name|__ev_get_ufix32_fs
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|__ev_get_ufix32_fs_internal ((__ev64_opaque__)(a), b)
end_define

begin_define
define|#
directive|define
name|__ev_get_sfix32_fs
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|__ev_get_sfix32_fs_internal ((__ev64_opaque__)(a), b)
end_define

begin_function
specifier|static
specifier|inline
name|uint32_t
name|__ev_get_u32_internal
parameter_list|(
name|__ev64_opaque__
name|a
parameter_list|,
name|uint32_t
name|pos
parameter_list|)
block|{
union|union
block|{
name|__ev64_opaque__
name|v
decl_stmt|;
name|uint32_t
name|i
index|[
literal|2
index|]
decl_stmt|;
block|}
name|u
union|;
name|u
operator|.
name|v
operator|=
name|a
expr_stmt|;
return|return
name|u
operator|.
name|i
index|[
name|pos
index|]
return|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|int32_t
name|__ev_get_s32_internal
parameter_list|(
name|__ev64_opaque__
name|a
parameter_list|,
name|uint32_t
name|pos
parameter_list|)
block|{
union|union
block|{
name|__ev64_opaque__
name|v
decl_stmt|;
name|int32_t
name|i
index|[
literal|2
index|]
decl_stmt|;
block|}
name|u
union|;
name|u
operator|.
name|v
operator|=
name|a
expr_stmt|;
return|return
name|u
operator|.
name|i
index|[
name|pos
index|]
return|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|float
name|__ev_get_fs_internal
parameter_list|(
name|__ev64_opaque__
name|a
parameter_list|,
name|uint32_t
name|pos
parameter_list|)
block|{
union|union
block|{
name|__ev64_opaque__
name|v
decl_stmt|;
name|float
name|f
index|[
literal|2
index|]
decl_stmt|;
block|}
name|u
union|;
name|u
operator|.
name|v
operator|=
name|a
expr_stmt|;
return|return
name|u
operator|.
name|f
index|[
name|pos
index|]
return|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|float
name|__ev_get_sfix32_fs_internal
parameter_list|(
name|__ev64_opaque__
name|a
parameter_list|,
name|uint32_t
name|pos
parameter_list|)
block|{
name|__ev64_fs__
name|v
decl_stmt|;
name|v
operator|=
name|__builtin_spe_evfscfsf
argument_list|(
operator|(
name|__v2sf
operator|)
name|a
argument_list|)
expr_stmt|;
return|return
name|__ev_get_fs_internal
argument_list|(
operator|(
name|__ev64_opaque__
operator|)
name|v
argument_list|,
name|pos
argument_list|)
return|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|float
name|__ev_get_ufix32_fs_internal
parameter_list|(
name|__ev64_opaque__
name|a
parameter_list|,
name|uint32_t
name|pos
parameter_list|)
block|{
name|__ev64_fs__
name|v
decl_stmt|;
name|v
operator|=
name|__builtin_spe_evfscfuf
argument_list|(
operator|(
name|__v2sf
operator|)
name|a
argument_list|)
expr_stmt|;
return|return
name|__ev_get_fs_internal
argument_list|(
operator|(
name|__ev64_opaque__
operator|)
name|v
argument_list|,
name|pos
argument_list|)
return|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|uint16_t
name|__ev_get_u16_internal
parameter_list|(
name|__ev64_opaque__
name|a
parameter_list|,
name|uint32_t
name|pos
parameter_list|)
block|{
union|union
block|{
name|__ev64_opaque__
name|v
decl_stmt|;
name|uint16_t
name|i
index|[
literal|4
index|]
decl_stmt|;
block|}
name|u
union|;
name|u
operator|.
name|v
operator|=
name|a
expr_stmt|;
return|return
name|u
operator|.
name|i
index|[
name|pos
index|]
return|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|int16_t
name|__ev_get_s16_internal
parameter_list|(
name|__ev64_opaque__
name|a
parameter_list|,
name|uint32_t
name|pos
parameter_list|)
block|{
union|union
block|{
name|__ev64_opaque__
name|v
decl_stmt|;
name|int16_t
name|i
index|[
literal|4
index|]
decl_stmt|;
block|}
name|u
union|;
name|u
operator|.
name|v
operator|=
name|a
expr_stmt|;
return|return
name|u
operator|.
name|i
index|[
name|pos
index|]
return|;
block|}
end_function

begin_comment
comment|/* __ev_set_* functions.  */
end_comment

begin_define
define|#
directive|define
name|__ev_set_u32
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|)
value|__ev_set_u32_internal ((__ev64_opaque__) a, b, c)
end_define

begin_define
define|#
directive|define
name|__ev_set_s32
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|)
value|__ev_set_s32_internal ((__ev64_opaque__) a, b, c)
end_define

begin_define
define|#
directive|define
name|__ev_set_fs
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|)
value|__ev_set_fs_internal ((__ev64_opaque__) a, b, c)
end_define

begin_define
define|#
directive|define
name|__ev_set_u16
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|)
value|__ev_set_u16_internal ((__ev64_opaque__) a, b, c)
end_define

begin_define
define|#
directive|define
name|__ev_set_s16
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|)
value|__ev_set_s16_internal ((__ev64_opaque__) a, b, c)
end_define

begin_define
define|#
directive|define
name|__ev_set_ufix32_u32
value|__ev_set_u32
end_define

begin_define
define|#
directive|define
name|__ev_set_sfix32_s32
value|__ev_set_s32
end_define

begin_define
define|#
directive|define
name|__ev_set_sfix32_fs
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|)
value|__ev_set_sfix32_fs_internal ((__ev64_opaque__) (a), b, c)
end_define

begin_define
define|#
directive|define
name|__ev_set_ufix32_fs
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|)
value|__ev_set_ufix32_fs_internal ((__ev64_opaque__) (a), b, c)
end_define

begin_define
define|#
directive|define
name|__ev_set_upper_u32
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|__ev_set_u32 (a, b, 0)
end_define

begin_define
define|#
directive|define
name|__ev_set_lower_u32
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|__ev_set_u32 (a, b, 1)
end_define

begin_define
define|#
directive|define
name|__ev_set_upper_s32
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|__ev_set_s32 (a, b, 0)
end_define

begin_define
define|#
directive|define
name|__ev_set_lower_s32
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|__ev_set_s32 (a, b, 1)
end_define

begin_define
define|#
directive|define
name|__ev_set_upper_fs
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|__ev_set_fs (a, b, 0)
end_define

begin_define
define|#
directive|define
name|__ev_set_lower_fs
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|__ev_set_fs (a, b, 1)
end_define

begin_define
define|#
directive|define
name|__ev_set_upper_ufix32_u32
value|__ev_set_upper_u32
end_define

begin_define
define|#
directive|define
name|__ev_set_lower_ufix32_u32
value|__ev_set_lower_u32
end_define

begin_define
define|#
directive|define
name|__ev_set_upper_sfix32_s32
value|__ev_set_upper_s32
end_define

begin_define
define|#
directive|define
name|__ev_set_lower_sfix32_s32
value|__ev_set_lower_s32
end_define

begin_define
define|#
directive|define
name|__ev_set_upper_sfix32_fs
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|__ev_set_sfix32_fs (a, b, 0)
end_define

begin_define
define|#
directive|define
name|__ev_set_lower_sfix32_fs
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|__ev_set_sfix32_fs (a, b, 1)
end_define

begin_define
define|#
directive|define
name|__ev_set_upper_ufix32_fs
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|__ev_set_ufix32_fs (a, b, 0)
end_define

begin_define
define|#
directive|define
name|__ev_set_lower_ufix32_fs
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|__ev_set_ufix32_fs (a, b, 1)
end_define

begin_define
define|#
directive|define
name|__ev_set_acc_vec64
parameter_list|(
name|a
parameter_list|)
value|__builtin_spe_evmra ((__ev64_opaque__)(a))
end_define

begin_function
specifier|static
specifier|inline
name|__ev64_opaque__
name|__ev_set_acc_u64
parameter_list|(
name|uint64_t
name|a
parameter_list|)
block|{
name|__ev64_opaque__
name|ev32
decl_stmt|;
name|ev32
operator|=
name|__ev_create_u64
argument_list|(
name|a
argument_list|)
expr_stmt|;
name|__ev_mra
argument_list|(
name|ev32
argument_list|)
expr_stmt|;
return|return
name|ev32
return|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|__ev64_opaque__
name|__ev_set_acc_s64
parameter_list|(
name|int64_t
name|a
parameter_list|)
block|{
name|__ev64_opaque__
name|ev32
decl_stmt|;
name|ev32
operator|=
name|__ev_create_s64
argument_list|(
name|a
argument_list|)
expr_stmt|;
name|__ev_mra
argument_list|(
name|ev32
argument_list|)
expr_stmt|;
return|return
name|ev32
return|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|__ev64_opaque__
name|__ev_set_u32_internal
parameter_list|(
name|__ev64_opaque__
name|a
parameter_list|,
name|uint32_t
name|b
parameter_list|,
name|uint32_t
name|pos
parameter_list|)
block|{
union|union
block|{
name|__ev64_opaque__
name|v
decl_stmt|;
name|uint32_t
name|i
index|[
literal|2
index|]
decl_stmt|;
block|}
name|u
union|;
name|u
operator|.
name|v
operator|=
name|a
expr_stmt|;
name|u
operator|.
name|i
index|[
name|pos
index|]
operator|=
name|b
expr_stmt|;
return|return
name|u
operator|.
name|v
return|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|__ev64_opaque__
name|__ev_set_s32_internal
parameter_list|(
name|__ev64_opaque__
name|a
parameter_list|,
name|int32_t
name|b
parameter_list|,
name|uint32_t
name|pos
parameter_list|)
block|{
union|union
block|{
name|__ev64_opaque__
name|v
decl_stmt|;
name|int32_t
name|i
index|[
literal|2
index|]
decl_stmt|;
block|}
name|u
union|;
name|u
operator|.
name|v
operator|=
name|a
expr_stmt|;
name|u
operator|.
name|i
index|[
name|pos
index|]
operator|=
name|b
expr_stmt|;
return|return
name|u
operator|.
name|v
return|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|__ev64_opaque__
name|__ev_set_fs_internal
parameter_list|(
name|__ev64_opaque__
name|a
parameter_list|,
name|float
name|b
parameter_list|,
name|uint32_t
name|pos
parameter_list|)
block|{
union|union
block|{
name|__ev64_opaque__
name|v
decl_stmt|;
name|float
name|f
index|[
literal|2
index|]
decl_stmt|;
block|}
name|u
union|;
name|u
operator|.
name|v
operator|=
name|a
expr_stmt|;
name|u
operator|.
name|f
index|[
name|pos
index|]
operator|=
name|b
expr_stmt|;
return|return
name|u
operator|.
name|v
return|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|__ev64_opaque__
name|__ev_set_sfix32_fs_internal
parameter_list|(
name|__ev64_opaque__
name|a
parameter_list|,
name|float
name|b
parameter_list|,
name|uint32_t
name|pos
parameter_list|)
block|{
name|__ev64_opaque__
name|v
decl_stmt|;
name|float
name|other
decl_stmt|;
comment|/* Get other half.  */
name|other
operator|=
name|__ev_get_fs_internal
argument_list|(
name|a
argument_list|,
name|pos
operator|^
literal|1
argument_list|)
expr_stmt|;
comment|/* Make an sfix32 with 'b'.  */
name|v
operator|=
name|__ev_create_sfix32_fs
argument_list|(
name|b
argument_list|,
name|b
argument_list|)
expr_stmt|;
comment|/* Set other half to what it used to be.  */
return|return
name|__ev_set_fs_internal
argument_list|(
name|v
argument_list|,
name|other
argument_list|,
name|pos
operator|^
literal|1
argument_list|)
return|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|__ev64_opaque__
name|__ev_set_ufix32_fs_internal
parameter_list|(
name|__ev64_opaque__
name|a
parameter_list|,
name|float
name|b
parameter_list|,
name|uint32_t
name|pos
parameter_list|)
block|{
name|__ev64_opaque__
name|v
decl_stmt|;
name|float
name|other
decl_stmt|;
comment|/* Get other half.  */
name|other
operator|=
name|__ev_get_fs_internal
argument_list|(
name|a
argument_list|,
name|pos
operator|^
literal|1
argument_list|)
expr_stmt|;
comment|/* Make an ufix32 with 'b'.  */
name|v
operator|=
name|__ev_create_ufix32_fs
argument_list|(
name|b
argument_list|,
name|b
argument_list|)
expr_stmt|;
comment|/* Set other half to what it used to be.  */
return|return
name|__ev_set_fs_internal
argument_list|(
name|v
argument_list|,
name|other
argument_list|,
name|pos
operator|^
literal|1
argument_list|)
return|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|__ev64_opaque__
name|__ev_set_u16_internal
parameter_list|(
name|__ev64_opaque__
name|a
parameter_list|,
name|uint16_t
name|b
parameter_list|,
name|uint32_t
name|pos
parameter_list|)
block|{
union|union
block|{
name|__ev64_opaque__
name|v
decl_stmt|;
name|uint16_t
name|i
index|[
literal|4
index|]
decl_stmt|;
block|}
name|u
union|;
name|u
operator|.
name|v
operator|=
name|a
expr_stmt|;
name|u
operator|.
name|i
index|[
name|pos
index|]
operator|=
name|b
expr_stmt|;
return|return
name|u
operator|.
name|v
return|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|__ev64_opaque__
name|__ev_set_s16_internal
parameter_list|(
name|__ev64_opaque__
name|a
parameter_list|,
name|int16_t
name|b
parameter_list|,
name|uint32_t
name|pos
parameter_list|)
block|{
union|union
block|{
name|__ev64_opaque__
name|v
decl_stmt|;
name|int16_t
name|i
index|[
literal|4
index|]
decl_stmt|;
block|}
name|u
union|;
name|u
operator|.
name|v
operator|=
name|a
expr_stmt|;
name|u
operator|.
name|i
index|[
name|pos
index|]
operator|=
name|b
expr_stmt|;
return|return
name|u
operator|.
name|v
return|;
block|}
end_function

begin_comment
comment|/* Predicates.  */
end_comment

begin_define
define|#
directive|define
name|__pred_all
value|0
end_define

begin_define
define|#
directive|define
name|__pred_any
value|1
end_define

begin_define
define|#
directive|define
name|__pred_upper
value|2
end_define

begin_define
define|#
directive|define
name|__pred_lower
value|3
end_define

begin_define
define|#
directive|define
name|__ev_any_gts
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|__builtin_spe_evcmpgts (__pred_any, (__v2si) (a), (__v2si) (b))
end_define

begin_define
define|#
directive|define
name|__ev_all_gts
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|__builtin_spe_evcmpgts (__pred_all, (__v2si) (a), (__v2si) (b))
end_define

begin_define
define|#
directive|define
name|__ev_upper_gts
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|__builtin_spe_evcmpgts (__pred_upper, (__v2si) (a), (__v2si) (b))
end_define

begin_define
define|#
directive|define
name|__ev_lower_gts
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|__builtin_spe_evcmpgts (__pred_lower, (__v2si) (a), (__v2si) (b))
end_define

begin_define
define|#
directive|define
name|__ev_select_gts
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|,
name|d
parameter_list|)
value|((__v2si) __builtin_spe_evsel_gts ((__v2si) (a), (__v2si) (b), (__v2si) (c), (__v2si) (d)))
end_define

begin_define
define|#
directive|define
name|__ev_any_gtu
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|__builtin_spe_evcmpgtu (__pred_any, (__v2si) (a), (__v2si) (b))
end_define

begin_define
define|#
directive|define
name|__ev_all_gtu
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|__builtin_spe_evcmpgtu (__pred_all, (__v2si) (a), (__v2si) (b))
end_define

begin_define
define|#
directive|define
name|__ev_upper_gtu
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|__builtin_spe_evcmpgtu (__pred_upper, (__v2si) (a), (__v2si) (b))
end_define

begin_define
define|#
directive|define
name|__ev_lower_gtu
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|__builtin_spe_evcmpgtu (__pred_lower, (__v2si) (a), (__v2si) (b))
end_define

begin_define
define|#
directive|define
name|__ev_select_gtu
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|,
name|d
parameter_list|)
value|((__v2si) __builtin_spe_evsel_gtu ((__v2si) (a), (__v2si) (b), (__v2si) (c), (__v2si) (d)))
end_define

begin_define
define|#
directive|define
name|__ev_any_lts
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|__builtin_spe_evcmplts (__pred_any, (__v2si) (a), (__v2si) (b))
end_define

begin_define
define|#
directive|define
name|__ev_all_lts
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|__builtin_spe_evcmplts (__pred_all, (__v2si) (a), (__v2si) (b))
end_define

begin_define
define|#
directive|define
name|__ev_upper_lts
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|__builtin_spe_evcmplts (__pred_upper, (__v2si) (a), (__v2si) (b))
end_define

begin_define
define|#
directive|define
name|__ev_lower_lts
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|__builtin_spe_evcmplts (__pred_lower, (__v2si) (a), (__v2si) (b))
end_define

begin_define
define|#
directive|define
name|__ev_select_lts
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|,
name|d
parameter_list|)
value|((__v2si) __builtin_spe_evsel_lts ((__v2si) (a), (__v2si) (b), (__v2si) (c), (__v2si) (d)))
end_define

begin_define
define|#
directive|define
name|__ev_any_ltu
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|__builtin_spe_evcmpltu (__pred_any, (__v2si) (a), (__v2si) (b))
end_define

begin_define
define|#
directive|define
name|__ev_all_ltu
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|__builtin_spe_evcmpltu (__pred_all, (__v2si) (a), (__v2si) (b))
end_define

begin_define
define|#
directive|define
name|__ev_upper_ltu
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|__builtin_spe_evcmpltu (__pred_upper, (__v2si) (a), (__v2si) (b))
end_define

begin_define
define|#
directive|define
name|__ev_lower_ltu
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|__builtin_spe_evcmpltu (__pred_lower, (__v2si) (a), (__v2si) (b))
end_define

begin_define
define|#
directive|define
name|__ev_select_ltu
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|,
name|d
parameter_list|)
value|((__v2si) __builtin_spe_evsel_ltu ((__v2si) (a), (__v2si) (b), (__v2si) (c), (__v2si) (d)))
end_define

begin_define
define|#
directive|define
name|__ev_any_eq
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|__builtin_spe_evcmpeq (__pred_any, (__v2si) (a), (__v2si) (b))
end_define

begin_define
define|#
directive|define
name|__ev_all_eq
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|__builtin_spe_evcmpeq (__pred_all, (__v2si) (a), (__v2si) (b))
end_define

begin_define
define|#
directive|define
name|__ev_upper_eq
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|__builtin_spe_evcmpeq (__pred_upper, (__v2si) (a), (__v2si) (b))
end_define

begin_define
define|#
directive|define
name|__ev_lower_eq
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|__builtin_spe_evcmpeq (__pred_lower, (__v2si) (a), (__v2si) (b))
end_define

begin_define
define|#
directive|define
name|__ev_select_eq
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|,
name|d
parameter_list|)
value|((__v2si) __builtin_spe_evsel_eq ((__v2si) (a), (__v2si) (b), (__v2si) (c), (__v2si) (d)))
end_define

begin_define
define|#
directive|define
name|__ev_any_fs_gt
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|__builtin_spe_evfscmpgt (__pred_any, (__v2sf) (a), (__v2sf) (b))
end_define

begin_define
define|#
directive|define
name|__ev_all_fs_gt
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|__builtin_spe_evfscmpgt (__pred_all, (__v2sf) (a), (__v2sf) (b))
end_define

begin_define
define|#
directive|define
name|__ev_upper_fs_gt
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|__builtin_spe_evfscmpgt (__pred_upper, (__v2sf) (a), (__v2sf) (b))
end_define

begin_define
define|#
directive|define
name|__ev_lower_fs_gt
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|__builtin_spe_evfscmpgt (__pred_lower, (__v2sf) (a), (__v2sf) (b))
end_define

begin_define
define|#
directive|define
name|__ev_select_fs_gt
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|,
name|d
parameter_list|)
value|((__v2si) __builtin_spe_evsel_fsgt ((__v2sf) (a), (__v2sf) (b), (__v2sf) (c), (__v2sf) (d)))
end_define

begin_define
define|#
directive|define
name|__ev_any_fs_lt
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|__builtin_spe_evfscmplt (__pred_any, (__v2sf) (a), (__v2sf) (b))
end_define

begin_define
define|#
directive|define
name|__ev_all_fs_lt
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|__builtin_spe_evfscmplt (__pred_all, (__v2sf) (a), (__v2sf) (b))
end_define

begin_define
define|#
directive|define
name|__ev_upper_fs_lt
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|__builtin_spe_evfscmplt (__pred_upper, (__v2sf) (a), (__v2sf) (b))
end_define

begin_define
define|#
directive|define
name|__ev_lower_fs_lt
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|__builtin_spe_evfscmplt (__pred_lower, (__v2sf) (a), (__v2sf) (b))
end_define

begin_define
define|#
directive|define
name|__ev_select_fs_lt
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|,
name|d
parameter_list|)
value|((__v2si) __builtin_spe_evsel_fslt ((__v2sf) (a), (__v2sf) (b), (__v2sf) (c), (__v2sf) (d)))
end_define

begin_define
define|#
directive|define
name|__ev_any_fs_eq
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|__builtin_spe_evfscmpeq (__pred_any, (__v2sf) (a), (__v2sf) (b))
end_define

begin_define
define|#
directive|define
name|__ev_all_fs_eq
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|__builtin_spe_evfscmpeq (__pred_all, (__v2sf) (a), (__v2sf) (b))
end_define

begin_define
define|#
directive|define
name|__ev_upper_fs_eq
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|__builtin_spe_evfscmpeq (__pred_upper, (__v2sf) (a), (__v2sf) (b))
end_define

begin_define
define|#
directive|define
name|__ev_lower_fs_eq
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|__builtin_spe_evfscmpeq (__pred_lower, (__v2sf) (a), (__v2sf) (b))
end_define

begin_define
define|#
directive|define
name|__ev_select_fs_eq
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|,
name|d
parameter_list|)
value|((__v2si) __builtin_spe_evsel_fseq ((__v2sf) (a), (__v2sf) (b), (__v2sf) (c), (__v2sf) (d)))
end_define

begin_define
define|#
directive|define
name|__ev_any_fs_tst_gt
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|__builtin_spe_evfststgt (__pred_any, (__v2sf) (a), (__v2sf) (b))
end_define

begin_define
define|#
directive|define
name|__ev_all_fs_tst_gt
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|__builtin_spe_evfststgt (__pred_all, (__v2sf) (a), (__v2sf) (b))
end_define

begin_define
define|#
directive|define
name|__ev_upper_fs_tst_gt
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|__builtin_spe_evfststgt (__pred_upper, (__v2sf) (a), (__v2sf) (b))
end_define

begin_define
define|#
directive|define
name|__ev_lower_fs_tst_gt
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|__builtin_spe_evfststgt (__pred_lower, (__v2sf) (a), (__v2sf) (b))
end_define

begin_define
define|#
directive|define
name|__ev_select_fs_tst_gt
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|,
name|d
parameter_list|)
value|((__v2si) __builtin_spe_evsel_fststgt ((__v2sf) (a), (__v2sf) (b), (__v2sf) (c), (__v2sf) (d)))
end_define

begin_define
define|#
directive|define
name|__ev_any_fs_tst_lt
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|__builtin_spe_evfststlt (__pred_any, (__v2sf) (a), (__v2sf) (b))
end_define

begin_define
define|#
directive|define
name|__ev_all_fs_tst_lt
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|__builtin_spe_evfststlt (__pred_all, (__v2sf) (a), (__v2sf) (b))
end_define

begin_define
define|#
directive|define
name|__ev_upper_fs_tst_lt
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|__builtin_spe_evfststlt (__pred_upper, (__v2sf) (a), (__v2sf) (b))
end_define

begin_define
define|#
directive|define
name|__ev_lower_fs_tst_lt
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|__builtin_spe_evfststlt (__pred_lower, (__v2sf) (a), (__v2sf) (b))
end_define

begin_define
define|#
directive|define
name|__ev_select_fs_tst_lt
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|,
name|d
parameter_list|)
value|((__v2si) __builtin_spe_evsel_fststlt ((__v2sf) (a), (__v2sf) (b), (__v2sf) (c), (__v2sf) (d)))
end_define

begin_define
define|#
directive|define
name|__ev_any_fs_tst_eq
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|__builtin_spe_evfststeq (__pred_any, (__v2sf) (a), (__v2sf) (b))
end_define

begin_define
define|#
directive|define
name|__ev_all_fs_tst_eq
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|__builtin_spe_evfststeq (__pred_all, (__v2sf) (a), (__v2sf) (b))
end_define

begin_define
define|#
directive|define
name|__ev_upper_fs_tst_eq
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|__builtin_spe_evfststeq (__pred_upper, (__v2sf) (a), (__v2sf) (b))
end_define

begin_define
define|#
directive|define
name|__ev_lower_fs_tst_eq
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|__builtin_spe_evfststeq (__pred_lower, (__v2sf) (a), (__v2sf) (b))
end_define

begin_define
define|#
directive|define
name|__ev_select_fs_tst_eq
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|,
name|d
parameter_list|)
value|((__v2si) __builtin_spe_evsel_fststeq ((__v2sf) (a), (__v2sf) (b), (__v2sf) (c), (__v2sf) (d)))
end_define

begin_comment
comment|/* SPEFSCR accesor functions.  */
end_comment

begin_define
define|#
directive|define
name|__SPEFSCR_SOVH
value|0x80000000
end_define

begin_define
define|#
directive|define
name|__SPEFSCR_OVH
value|0x40000000
end_define

begin_define
define|#
directive|define
name|__SPEFSCR_FGH
value|0x20000000
end_define

begin_define
define|#
directive|define
name|__SPEFSCR_FXH
value|0x10000000
end_define

begin_define
define|#
directive|define
name|__SPEFSCR_FINVH
value|0x08000000
end_define

begin_define
define|#
directive|define
name|__SPEFSCR_FDBZH
value|0x04000000
end_define

begin_define
define|#
directive|define
name|__SPEFSCR_FUNFH
value|0x02000000
end_define

begin_define
define|#
directive|define
name|__SPEFSCR_FOVFH
value|0x01000000
end_define

begin_comment
comment|/* 2 unused bits.  */
end_comment

begin_define
define|#
directive|define
name|__SPEFSCR_FINXS
value|0x00200000
end_define

begin_define
define|#
directive|define
name|__SPEFSCR_FINVS
value|0x00100000
end_define

begin_define
define|#
directive|define
name|__SPEFSCR_FDBZS
value|0x00080000
end_define

begin_define
define|#
directive|define
name|__SPEFSCR_FUNFS
value|0x00040000
end_define

begin_define
define|#
directive|define
name|__SPEFSCR_FOVFS
value|0x00020000
end_define

begin_define
define|#
directive|define
name|__SPEFSCR_MODE
value|0x00010000
end_define

begin_define
define|#
directive|define
name|__SPEFSCR_SOV
value|0x00008000
end_define

begin_define
define|#
directive|define
name|__SPEFSCR_OV
value|0x00004000
end_define

begin_define
define|#
directive|define
name|__SPEFSCR_FG
value|0x00002000
end_define

begin_define
define|#
directive|define
name|__SPEFSCR_FX
value|0x00001000
end_define

begin_define
define|#
directive|define
name|__SPEFSCR_FINV
value|0x00000800
end_define

begin_define
define|#
directive|define
name|__SPEFSCR_FDBZ
value|0x00000400
end_define

begin_define
define|#
directive|define
name|__SPEFSCR_FUNF
value|0x00000200
end_define

begin_define
define|#
directive|define
name|__SPEFSCR_FOVF
value|0x00000100
end_define

begin_comment
comment|/* 1 unused bit.  */
end_comment

begin_define
define|#
directive|define
name|__SPEFSCR_FINXE
value|0x00000040
end_define

begin_define
define|#
directive|define
name|__SPEFSCR_FINVE
value|0x00000020
end_define

begin_define
define|#
directive|define
name|__SPEFSCR_FDBZE
value|0x00000010
end_define

begin_define
define|#
directive|define
name|__SPEFSCR_FUNFE
value|0x00000008
end_define

begin_define
define|#
directive|define
name|__SPEFSCR_FOVFE
value|0x00000004
end_define

begin_define
define|#
directive|define
name|__SPEFSCR_FRMC
value|0x00000003
end_define

begin_define
define|#
directive|define
name|__ev_get_spefscr_sovh
parameter_list|()
value|(__builtin_spe_mfspefscr ()& __SPEFSCR_SOVH)
end_define

begin_define
define|#
directive|define
name|__ev_get_spefscr_ovh
parameter_list|()
value|(__builtin_spe_mfspefscr ()& __SPEFSCR_OVH)
end_define

begin_define
define|#
directive|define
name|__ev_get_spefscr_fgh
parameter_list|()
value|(__builtin_spe_mfspefscr ()& __SPEFSCR_FGH)
end_define

begin_define
define|#
directive|define
name|__ev_get_spefscr_fxh
parameter_list|()
value|(__builtin_spe_mfspefscr ()& __SPEFSCR_FXH)
end_define

begin_define
define|#
directive|define
name|__ev_get_spefscr_finvh
parameter_list|()
value|(__builtin_spe_mfspefscr ()& __SPEFSCR_FINVH)
end_define

begin_define
define|#
directive|define
name|__ev_get_spefscr_fdbzh
parameter_list|()
value|(__builtin_spe_mfspefscr ()& __SPEFSCR_FDBZH)
end_define

begin_define
define|#
directive|define
name|__ev_get_spefscr_funfh
parameter_list|()
value|(__builtin_spe_mfspefscr ()& __SPEFSCR_FUNFH)
end_define

begin_define
define|#
directive|define
name|__ev_get_spefscr_fovfh
parameter_list|()
value|(__builtin_spe_mfspefscr ()& __SPEFSCR_FOVFH)
end_define

begin_define
define|#
directive|define
name|__ev_get_spefscr_finxs
parameter_list|()
value|(__builtin_spe_mfspefscr ()& __SPEFSCR_FINXS)
end_define

begin_define
define|#
directive|define
name|__ev_get_spefscr_finvs
parameter_list|()
value|(__builtin_spe_mfspefscr ()& __SPEFSCR_FINVS)
end_define

begin_define
define|#
directive|define
name|__ev_get_spefscr_fdbzs
parameter_list|()
value|(__builtin_spe_mfspefscr ()& __SPEFSCR_FDBZS)
end_define

begin_define
define|#
directive|define
name|__ev_get_spefscr_funfs
parameter_list|()
value|(__builtin_spe_mfspefscr ()& __SPEFSCR_FUNFS)
end_define

begin_define
define|#
directive|define
name|__ev_get_spefscr_fovfs
parameter_list|()
value|(__builtin_spe_mfspefscr ()& __SPEFSCR_FOVFS)
end_define

begin_define
define|#
directive|define
name|__ev_get_spefscr_mode
parameter_list|()
value|(__builtin_spe_mfspefscr ()& __SPEFSCR_MODE)
end_define

begin_define
define|#
directive|define
name|__ev_get_spefscr_sov
parameter_list|()
value|(__builtin_spe_mfspefscr ()& __SPEFSCR_SOV)
end_define

begin_define
define|#
directive|define
name|__ev_get_spefscr_ov
parameter_list|()
value|(__builtin_spe_mfspefscr ()& __SPEFSCR_OV)
end_define

begin_define
define|#
directive|define
name|__ev_get_spefscr_fg
parameter_list|()
value|(__builtin_spe_mfspefscr ()& __SPEFSCR_FG)
end_define

begin_define
define|#
directive|define
name|__ev_get_spefscr_fx
parameter_list|()
value|(__builtin_spe_mfspefscr ()& __SPEFSCR_FX)
end_define

begin_define
define|#
directive|define
name|__ev_get_spefscr_finv
parameter_list|()
value|(__builtin_spe_mfspefscr ()& __SPEFSCR_FINV)
end_define

begin_define
define|#
directive|define
name|__ev_get_spefscr_fdbz
parameter_list|()
value|(__builtin_spe_mfspefscr ()& __SPEFSCR_FDBZ)
end_define

begin_define
define|#
directive|define
name|__ev_get_spefscr_funf
parameter_list|()
value|(__builtin_spe_mfspefscr ()& __SPEFSCR_FUNF)
end_define

begin_define
define|#
directive|define
name|__ev_get_spefscr_fovf
parameter_list|()
value|(__builtin_spe_mfspefscr ()& __SPEFSCR_FOVF)
end_define

begin_define
define|#
directive|define
name|__ev_get_spefscr_finxe
parameter_list|()
value|(__builtin_spe_mfspefscr ()& __SPEFSCR_FINXE)
end_define

begin_define
define|#
directive|define
name|__ev_get_spefscr_finve
parameter_list|()
value|(__builtin_spe_mfspefscr ()& __SPEFSCR_FINVE)
end_define

begin_define
define|#
directive|define
name|__ev_get_spefscr_fdbze
parameter_list|()
value|(__builtin_spe_mfspefscr ()& __SPEFSCR_FDBZE)
end_define

begin_define
define|#
directive|define
name|__ev_get_spefscr_funfe
parameter_list|()
value|(__builtin_spe_mfspefscr ()& __SPEFSCR_FUNFE)
end_define

begin_define
define|#
directive|define
name|__ev_get_spefscr_fovfe
parameter_list|()
value|(__builtin_spe_mfspefscr ()& __SPEFSCR_FOVFE)
end_define

begin_define
define|#
directive|define
name|__ev_get_spefscr_frmc
parameter_list|()
value|(__builtin_spe_mfspefscr ()& __SPEFSCR_FRMC)
end_define

begin_function
specifier|static
specifier|inline
name|void
name|__ev_clr_spefscr_field
parameter_list|(
name|int
name|mask
parameter_list|)
block|{
name|int
name|i
decl_stmt|;
name|i
operator|=
name|__builtin_spe_mfspefscr
argument_list|()
expr_stmt|;
name|i
operator|&=
operator|~
name|mask
expr_stmt|;
name|__builtin_spe_mtspefscr
argument_list|(
name|i
argument_list|)
expr_stmt|;
block|}
end_function

begin_define
define|#
directive|define
name|__ev_clr_spefscr_sovh
parameter_list|()
value|__ev_clr_spefscr_field (__SPEFSCR_SOVH)
end_define

begin_define
define|#
directive|define
name|__ev_clr_spefscr_sov
parameter_list|()
value|__ev_clr_spefscr_field (__SPEFSCR_SOV)
end_define

begin_define
define|#
directive|define
name|__ev_clr_spefscr_finxs
parameter_list|()
value|__ev_clr_spefscr_field (__SPEFSCR_FINXS)
end_define

begin_define
define|#
directive|define
name|__ev_clr_spefscr_finvs
parameter_list|()
value|__ev_clr_spefscr_field (__SPEFSCR_FINVS)
end_define

begin_define
define|#
directive|define
name|__ev_clr_spefscr_fdbzs
parameter_list|()
value|__ev_clr_spefscr_field (__SPEFSCR_FDBZS)
end_define

begin_define
define|#
directive|define
name|__ev_clr_spefscr_funfs
parameter_list|()
value|__ev_clr_spefscr_field (__SPEFSCR_FUNFS)
end_define

begin_define
define|#
directive|define
name|__ev_clr_spefscr_fovfs
parameter_list|()
value|__ev_clr_spefscr_field (__SPEFSCR_FOVFS)
end_define

begin_comment
comment|/* Set rounding mode:      rnd = 0 (nearest)      rnd = 1 (zero)      rnd = 2 (+inf)      rnd = 3 (-inf).  */
end_comment

begin_function
specifier|static
specifier|inline
name|void
name|__ev_set_spefscr_frmc
parameter_list|(
name|int
name|rnd
parameter_list|)
block|{
name|int
name|i
decl_stmt|;
name|i
operator|=
name|__builtin_spe_mfspefscr
argument_list|()
expr_stmt|;
name|i
operator|&=
operator|~
name|__SPEFSCR_FRMC
expr_stmt|;
name|i
operator||=
name|rnd
expr_stmt|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _SPE_H */
end_comment

end_unit

