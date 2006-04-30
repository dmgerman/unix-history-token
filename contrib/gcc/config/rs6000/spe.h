begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* PowerPC E500 user include file.    Copyright (C) 2002, 2003 Free Software Foundation, Inc.    Contributed by Aldy Hernandez (aldyh@redhat.com).     This file is part of GCC.     GCC is free software; you can redistribute it and/or modify it    under the terms of the GNU General Public License as published    by the Free Software Foundation; either version 2, or (at your    option) any later version.     GCC is distributed in the hope that it will be useful, but WITHOUT    ANY WARRANTY; without even the implied warranty of MERCHANTABILITY    or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public    License for more details.     You should have received a copy of the GNU General Public License    along with GCC; see the file COPYING.  If not, write to the    Free Software Foundation, 59 Temple Place - Suite 330, Boston,    MA 02111-1307, USA.  */
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
value|__builtin_spe_evaddw
end_define

begin_define
define|#
directive|define
name|__ev_addiw
value|__builtin_spe_evaddiw
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
value|__builtin_spe_evsubfw ((b), (a))
end_define

begin_define
define|#
directive|define
name|__ev_subw
value|__builtin_spe_evsubfw
end_define

begin_define
define|#
directive|define
name|__ev_subifw
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|__builtin_spe_evsubifw ((b), (a))
end_define

begin_define
define|#
directive|define
name|__ev_subiw
value|__builtin_spe_evsubifw
end_define

begin_define
define|#
directive|define
name|__ev_abs
value|__builtin_spe_evabs
end_define

begin_define
define|#
directive|define
name|__ev_neg
value|__builtin_spe_evneg
end_define

begin_define
define|#
directive|define
name|__ev_extsb
value|__builtin_spe_evextsb
end_define

begin_define
define|#
directive|define
name|__ev_extsh
value|__builtin_spe_evextsh
end_define

begin_define
define|#
directive|define
name|__ev_and
value|__builtin_spe_evand
end_define

begin_define
define|#
directive|define
name|__ev_or
value|__builtin_spe_evor
end_define

begin_define
define|#
directive|define
name|__ev_xor
value|__builtin_spe_evxor
end_define

begin_define
define|#
directive|define
name|__ev_nand
value|__builtin_spe_evnand
end_define

begin_define
define|#
directive|define
name|__ev_nor
value|__builtin_spe_evnor
end_define

begin_define
define|#
directive|define
name|__ev_eqv
value|__builtin_spe_eveqv
end_define

begin_define
define|#
directive|define
name|__ev_andc
value|__builtin_spe_evandc
end_define

begin_define
define|#
directive|define
name|__ev_orc
value|__builtin_spe_evorc
end_define

begin_define
define|#
directive|define
name|__ev_rlw
value|__builtin_spe_evrlw
end_define

begin_define
define|#
directive|define
name|__ev_rlwi
value|__builtin_spe_evrlwi
end_define

begin_define
define|#
directive|define
name|__ev_slw
value|__builtin_spe_evslw
end_define

begin_define
define|#
directive|define
name|__ev_slwi
value|__builtin_spe_evslwi
end_define

begin_define
define|#
directive|define
name|__ev_srws
value|__builtin_spe_evsrws
end_define

begin_define
define|#
directive|define
name|__ev_srwu
value|__builtin_spe_evsrwu
end_define

begin_define
define|#
directive|define
name|__ev_srwis
value|__builtin_spe_evsrwis
end_define

begin_define
define|#
directive|define
name|__ev_srwiu
value|__builtin_spe_evsrwiu
end_define

begin_define
define|#
directive|define
name|__ev_cntlzw
value|__builtin_spe_evcntlzw
end_define

begin_define
define|#
directive|define
name|__ev_cntlsw
value|__builtin_spe_evcntlsw
end_define

begin_define
define|#
directive|define
name|__ev_rndw
value|__builtin_spe_evrndw
end_define

begin_define
define|#
directive|define
name|__ev_mergehi
value|__builtin_spe_evmergehi
end_define

begin_define
define|#
directive|define
name|__ev_mergelo
value|__builtin_spe_evmergelo
end_define

begin_define
define|#
directive|define
name|__ev_mergelohi
value|__builtin_spe_evmergelohi
end_define

begin_define
define|#
directive|define
name|__ev_mergehilo
value|__builtin_spe_evmergehilo
end_define

begin_define
define|#
directive|define
name|__ev_splati
value|__builtin_spe_evsplati
end_define

begin_define
define|#
directive|define
name|__ev_splatfi
value|__builtin_spe_evsplatfi
end_define

begin_define
define|#
directive|define
name|__ev_divws
value|__builtin_spe_evdivws
end_define

begin_define
define|#
directive|define
name|__ev_divwu
value|__builtin_spe_evdivwu
end_define

begin_define
define|#
directive|define
name|__ev_mra
value|__builtin_spe_evmra
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
value|__builtin_spe_evlddx
end_define

begin_define
define|#
directive|define
name|__ev_ldwx
value|__builtin_spe_evldwx
end_define

begin_define
define|#
directive|define
name|__ev_ldhx
value|__builtin_spe_evldhx
end_define

begin_define
define|#
directive|define
name|__ev_lwhex
value|__builtin_spe_evlwhex
end_define

begin_define
define|#
directive|define
name|__ev_lwhoux
value|__builtin_spe_evlwhoux
end_define

begin_define
define|#
directive|define
name|__ev_lwhosx
value|__builtin_spe_evlwhosx
end_define

begin_define
define|#
directive|define
name|__ev_lwwsplatx
value|__builtin_spe_evlwwsplatx
end_define

begin_define
define|#
directive|define
name|__ev_lwhsplatx
value|__builtin_spe_evlwhsplatx
end_define

begin_define
define|#
directive|define
name|__ev_lhhesplatx
value|__builtin_spe_evlhhesplatx
end_define

begin_define
define|#
directive|define
name|__ev_lhhousplatx
value|__builtin_spe_evlhhousplatx
end_define

begin_define
define|#
directive|define
name|__ev_lhhossplatx
value|__builtin_spe_evlhhossplatx
end_define

begin_define
define|#
directive|define
name|__ev_ldd
value|__builtin_spe_evldd
end_define

begin_define
define|#
directive|define
name|__ev_ldw
value|__builtin_spe_evldw
end_define

begin_define
define|#
directive|define
name|__ev_ldh
value|__builtin_spe_evldh
end_define

begin_define
define|#
directive|define
name|__ev_lwhe
value|__builtin_spe_evlwhe
end_define

begin_define
define|#
directive|define
name|__ev_lwhou
value|__builtin_spe_evlwhou
end_define

begin_define
define|#
directive|define
name|__ev_lwhos
value|__builtin_spe_evlwhos
end_define

begin_define
define|#
directive|define
name|__ev_lwwsplat
value|__builtin_spe_evlwwsplat
end_define

begin_define
define|#
directive|define
name|__ev_lwhsplat
value|__builtin_spe_evlwhsplat
end_define

begin_define
define|#
directive|define
name|__ev_lhhesplat
value|__builtin_spe_evlhhesplat
end_define

begin_define
define|#
directive|define
name|__ev_lhhousplat
value|__builtin_spe_evlhhousplat
end_define

begin_define
define|#
directive|define
name|__ev_lhhossplat
value|__builtin_spe_evlhhossplat
end_define

begin_comment
comment|/* Stores.  */
end_comment

begin_define
define|#
directive|define
name|__ev_stddx
value|__builtin_spe_evstddx
end_define

begin_define
define|#
directive|define
name|__ev_stdwx
value|__builtin_spe_evstdwx
end_define

begin_define
define|#
directive|define
name|__ev_stdhx
value|__builtin_spe_evstdhx
end_define

begin_define
define|#
directive|define
name|__ev_stwwex
value|__builtin_spe_evstwwex
end_define

begin_define
define|#
directive|define
name|__ev_stwwox
value|__builtin_spe_evstwwox
end_define

begin_define
define|#
directive|define
name|__ev_stwhex
value|__builtin_spe_evstwhex
end_define

begin_define
define|#
directive|define
name|__ev_stwhox
value|__builtin_spe_evstwhox
end_define

begin_define
define|#
directive|define
name|__ev_stdd
value|__builtin_spe_evstdd
end_define

begin_define
define|#
directive|define
name|__ev_stdw
value|__builtin_spe_evstdw
end_define

begin_define
define|#
directive|define
name|__ev_stdh
value|__builtin_spe_evstdh
end_define

begin_define
define|#
directive|define
name|__ev_stwwe
value|__builtin_spe_evstwwe
end_define

begin_define
define|#
directive|define
name|__ev_stwwo
value|__builtin_spe_evstwwo
end_define

begin_define
define|#
directive|define
name|__ev_stwhe
value|__builtin_spe_evstwhe
end_define

begin_define
define|#
directive|define
name|__ev_stwho
value|__builtin_spe_evstwho
end_define

begin_comment
comment|/* Fixed point complex.  */
end_comment

begin_define
define|#
directive|define
name|__ev_mhossf
value|__builtin_spe_evmhossf
end_define

begin_define
define|#
directive|define
name|__ev_mhosmf
value|__builtin_spe_evmhosmf
end_define

begin_define
define|#
directive|define
name|__ev_mhosmi
value|__builtin_spe_evmhosmi
end_define

begin_define
define|#
directive|define
name|__ev_mhoumi
value|__builtin_spe_evmhoumi
end_define

begin_define
define|#
directive|define
name|__ev_mhessf
value|__builtin_spe_evmhessf
end_define

begin_define
define|#
directive|define
name|__ev_mhesmf
value|__builtin_spe_evmhesmf
end_define

begin_define
define|#
directive|define
name|__ev_mhesmi
value|__builtin_spe_evmhesmi
end_define

begin_define
define|#
directive|define
name|__ev_mheumi
value|__builtin_spe_evmheumi
end_define

begin_define
define|#
directive|define
name|__ev_mhossfa
value|__builtin_spe_evmhossfa
end_define

begin_define
define|#
directive|define
name|__ev_mhosmfa
value|__builtin_spe_evmhosmfa
end_define

begin_define
define|#
directive|define
name|__ev_mhosmia
value|__builtin_spe_evmhosmia
end_define

begin_define
define|#
directive|define
name|__ev_mhoumia
value|__builtin_spe_evmhoumia
end_define

begin_define
define|#
directive|define
name|__ev_mhessfa
value|__builtin_spe_evmhessfa
end_define

begin_define
define|#
directive|define
name|__ev_mhesmfa
value|__builtin_spe_evmhesmfa
end_define

begin_define
define|#
directive|define
name|__ev_mhesmia
value|__builtin_spe_evmhesmia
end_define

begin_define
define|#
directive|define
name|__ev_mheumia
value|__builtin_spe_evmheumia
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
value|__builtin_spe_evmhossfaaw
end_define

begin_define
define|#
directive|define
name|__ev_mhossiaaw
value|__builtin_spe_evmhossiaaw
end_define

begin_define
define|#
directive|define
name|__ev_mhosmfaaw
value|__builtin_spe_evmhosmfaaw
end_define

begin_define
define|#
directive|define
name|__ev_mhosmiaaw
value|__builtin_spe_evmhosmiaaw
end_define

begin_define
define|#
directive|define
name|__ev_mhousiaaw
value|__builtin_spe_evmhousiaaw
end_define

begin_define
define|#
directive|define
name|__ev_mhoumiaaw
value|__builtin_spe_evmhoumiaaw
end_define

begin_define
define|#
directive|define
name|__ev_mhessfaaw
value|__builtin_spe_evmhessfaaw
end_define

begin_define
define|#
directive|define
name|__ev_mhessiaaw
value|__builtin_spe_evmhessiaaw
end_define

begin_define
define|#
directive|define
name|__ev_mhesmfaaw
value|__builtin_spe_evmhesmfaaw
end_define

begin_define
define|#
directive|define
name|__ev_mhesmiaaw
value|__builtin_spe_evmhesmiaaw
end_define

begin_define
define|#
directive|define
name|__ev_mheusiaaw
value|__builtin_spe_evmheusiaaw
end_define

begin_define
define|#
directive|define
name|__ev_mheumiaaw
value|__builtin_spe_evmheumiaaw
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
value|__builtin_spe_evmhossfanw
end_define

begin_define
define|#
directive|define
name|__ev_mhossianw
value|__builtin_spe_evmhossianw
end_define

begin_define
define|#
directive|define
name|__ev_mhosmfanw
value|__builtin_spe_evmhosmfanw
end_define

begin_define
define|#
directive|define
name|__ev_mhosmianw
value|__builtin_spe_evmhosmianw
end_define

begin_define
define|#
directive|define
name|__ev_mhousianw
value|__builtin_spe_evmhousianw
end_define

begin_define
define|#
directive|define
name|__ev_mhoumianw
value|__builtin_spe_evmhoumianw
end_define

begin_define
define|#
directive|define
name|__ev_mhessfanw
value|__builtin_spe_evmhessfanw
end_define

begin_define
define|#
directive|define
name|__ev_mhessianw
value|__builtin_spe_evmhessianw
end_define

begin_define
define|#
directive|define
name|__ev_mhesmfanw
value|__builtin_spe_evmhesmfanw
end_define

begin_define
define|#
directive|define
name|__ev_mhesmianw
value|__builtin_spe_evmhesmianw
end_define

begin_define
define|#
directive|define
name|__ev_mheusianw
value|__builtin_spe_evmheusianw
end_define

begin_define
define|#
directive|define
name|__ev_mheumianw
value|__builtin_spe_evmheumianw
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
value|__builtin_spe_evmhogsmfaa
end_define

begin_define
define|#
directive|define
name|__ev_mhogsmiaa
value|__builtin_spe_evmhogsmiaa
end_define

begin_define
define|#
directive|define
name|__ev_mhogumiaa
value|__builtin_spe_evmhogumiaa
end_define

begin_define
define|#
directive|define
name|__ev_mhegsmfaa
value|__builtin_spe_evmhegsmfaa
end_define

begin_define
define|#
directive|define
name|__ev_mhegsmiaa
value|__builtin_spe_evmhegsmiaa
end_define

begin_define
define|#
directive|define
name|__ev_mhegumiaa
value|__builtin_spe_evmhegumiaa
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
value|__builtin_spe_evmhogsmfan
end_define

begin_define
define|#
directive|define
name|__ev_mhogsmian
value|__builtin_spe_evmhogsmian
end_define

begin_define
define|#
directive|define
name|__ev_mhogumian
value|__builtin_spe_evmhogumian
end_define

begin_define
define|#
directive|define
name|__ev_mhegsmfan
value|__builtin_spe_evmhegsmfan
end_define

begin_define
define|#
directive|define
name|__ev_mhegsmian
value|__builtin_spe_evmhegsmian
end_define

begin_define
define|#
directive|define
name|__ev_mhegumian
value|__builtin_spe_evmhegumian
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
value|__builtin_spe_evmwhssf
end_define

begin_define
define|#
directive|define
name|__ev_mwhsmf
value|__builtin_spe_evmwhsmf
end_define

begin_define
define|#
directive|define
name|__ev_mwhsmi
value|__builtin_spe_evmwhsmi
end_define

begin_define
define|#
directive|define
name|__ev_mwhumi
value|__builtin_spe_evmwhumi
end_define

begin_define
define|#
directive|define
name|__ev_mwhssfa
value|__builtin_spe_evmwhssfa
end_define

begin_define
define|#
directive|define
name|__ev_mwhsmfa
value|__builtin_spe_evmwhsmfa
end_define

begin_define
define|#
directive|define
name|__ev_mwhsmia
value|__builtin_spe_evmwhsmia
end_define

begin_define
define|#
directive|define
name|__ev_mwhumia
value|__builtin_spe_evmwhumia
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
value|__builtin_spe_evmwlumi
end_define

begin_define
define|#
directive|define
name|__ev_mwlumia
value|__builtin_spe_evmwlumia
end_define

begin_define
define|#
directive|define
name|__ev_mwlumiaaw
value|__builtin_spe_evmwlumiaaw
end_define

begin_define
define|#
directive|define
name|__ev_mwlssiaaw
value|__builtin_spe_evmwlssiaaw
end_define

begin_define
define|#
directive|define
name|__ev_mwlsmiaaw
value|__builtin_spe_evmwlsmiaaw
end_define

begin_define
define|#
directive|define
name|__ev_mwlusiaaw
value|__builtin_spe_evmwlusiaaw
end_define

begin_define
define|#
directive|define
name|__ev_mwlusiaaw
value|__builtin_spe_evmwlusiaaw
end_define

begin_define
define|#
directive|define
name|__ev_mwlssianw
value|__builtin_spe_evmwlssianw
end_define

begin_define
define|#
directive|define
name|__ev_mwlsmianw
value|__builtin_spe_evmwlsmianw
end_define

begin_define
define|#
directive|define
name|__ev_mwlusianw
value|__builtin_spe_evmwlusianw
end_define

begin_define
define|#
directive|define
name|__ev_mwlumianw
value|__builtin_spe_evmwlumianw
end_define

begin_define
define|#
directive|define
name|__ev_mwssf
value|__builtin_spe_evmwssf
end_define

begin_define
define|#
directive|define
name|__ev_mwsmf
value|__builtin_spe_evmwsmf
end_define

begin_define
define|#
directive|define
name|__ev_mwsmi
value|__builtin_spe_evmwsmi
end_define

begin_define
define|#
directive|define
name|__ev_mwumi
value|__builtin_spe_evmwumi
end_define

begin_define
define|#
directive|define
name|__ev_mwssfa
value|__builtin_spe_evmwssfa
end_define

begin_define
define|#
directive|define
name|__ev_mwsmfa
value|__builtin_spe_evmwsmfa
end_define

begin_define
define|#
directive|define
name|__ev_mwsmia
value|__builtin_spe_evmwsmia
end_define

begin_define
define|#
directive|define
name|__ev_mwumia
value|__builtin_spe_evmwumia
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
value|__builtin_spe_evmwssfaa
end_define

begin_define
define|#
directive|define
name|__ev_mwsmfaa
value|__builtin_spe_evmwsmfaa
end_define

begin_define
define|#
directive|define
name|__ev_mwsmiaa
value|__builtin_spe_evmwsmiaa
end_define

begin_define
define|#
directive|define
name|__ev_mwumiaa
value|__builtin_spe_evmwumiaa
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
value|__builtin_spe_evmwssfan
end_define

begin_define
define|#
directive|define
name|__ev_mwsmfan
value|__builtin_spe_evmwsmfan
end_define

begin_define
define|#
directive|define
name|__ev_mwsmian
value|__builtin_spe_evmwsmian
end_define

begin_define
define|#
directive|define
name|__ev_mwumian
value|__builtin_spe_evmwumian
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
value|__builtin_spe_evaddssiaaw
end_define

begin_define
define|#
directive|define
name|__ev_addsmiaaw
value|__builtin_spe_evaddsmiaaw
end_define

begin_define
define|#
directive|define
name|__ev_addusiaaw
value|__builtin_spe_evaddusiaaw
end_define

begin_define
define|#
directive|define
name|__ev_addumiaaw
value|__builtin_spe_evaddumiaaw
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
value|__builtin_spe_evsubfssiaaw
end_define

begin_define
define|#
directive|define
name|__ev_subfsmiaaw
value|__builtin_spe_evsubfsmiaaw
end_define

begin_define
define|#
directive|define
name|__ev_subfusiaaw
value|__builtin_spe_evsubfusiaaw
end_define

begin_define
define|#
directive|define
name|__ev_subfumiaaw
value|__builtin_spe_evsubfumiaaw
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

begin_define
define|#
directive|define
name|__ev_fsabs
value|__builtin_spe_evfsabs
end_define

begin_define
define|#
directive|define
name|__ev_fsnabs
value|__builtin_spe_evfsnabs
end_define

begin_define
define|#
directive|define
name|__ev_fsneg
value|__builtin_spe_evfsneg
end_define

begin_define
define|#
directive|define
name|__ev_fsadd
value|__builtin_spe_evfsadd
end_define

begin_define
define|#
directive|define
name|__ev_fssub
value|__builtin_spe_evfssub
end_define

begin_define
define|#
directive|define
name|__ev_fsmul
value|__builtin_spe_evfsmul
end_define

begin_define
define|#
directive|define
name|__ev_fsdiv
value|__builtin_spe_evfsdiv
end_define

begin_define
define|#
directive|define
name|__ev_fscfui
value|__builtin_spe_evfscfui
end_define

begin_define
define|#
directive|define
name|__ev_fscfsi
value|__builtin_spe_evfscfsi
end_define

begin_define
define|#
directive|define
name|__ev_fscfuf
value|__builtin_spe_evfscfuf
end_define

begin_define
define|#
directive|define
name|__ev_fscfsf
value|__builtin_spe_evfscfsf
end_define

begin_define
define|#
directive|define
name|__ev_fsctui
value|__builtin_spe_evfsctui
end_define

begin_define
define|#
directive|define
name|__ev_fsctsi
value|__builtin_spe_evfsctsi
end_define

begin_define
define|#
directive|define
name|__ev_fsctuf
value|__builtin_spe_evfsctuf
end_define

begin_define
define|#
directive|define
name|__ev_fsctsf
value|__builtin_spe_evfsctsf
end_define

begin_define
define|#
directive|define
name|__ev_fsctuiz
value|__builtin_spe_evfsctuiz
end_define

begin_define
define|#
directive|define
name|__ev_fsctsiz
value|__builtin_spe_evfsctsiz
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
value|__internal_ev_mwhgssfaa
end_define

begin_define
define|#
directive|define
name|__ev_mwhgsmfaa
value|__internal_ev_mwhgsmfaa
end_define

begin_define
define|#
directive|define
name|__ev_mwhgsmiaa
value|__internal_ev_mwhgsmiaa
end_define

begin_define
define|#
directive|define
name|__ev_mwhgumiaa
value|__internal_ev_mwhgumiaa
end_define

begin_define
define|#
directive|define
name|__ev_mwhgssfan
value|__internal_ev_mwhgssfan
end_define

begin_define
define|#
directive|define
name|__ev_mwhgsmfan
value|__internal_ev_mwhgsmfan
end_define

begin_define
define|#
directive|define
name|__ev_mwhgsmian
value|__internal_ev_mwhgsmian
end_define

begin_define
define|#
directive|define
name|__ev_mwhgumian
value|__internal_ev_mwhgumian
end_define

begin_define
define|#
directive|define
name|__ev_mwhssiaaw
value|__internal_ev_mwhssiaaw
end_define

begin_define
define|#
directive|define
name|__ev_mwhssfaaw
value|__internal_ev_mwhssfaaw
end_define

begin_define
define|#
directive|define
name|__ev_mwhsmfaaw
value|__internal_ev_mwhsmfaaw
end_define

begin_define
define|#
directive|define
name|__ev_mwhsmiaaw
value|__internal_ev_mwhsmiaaw
end_define

begin_define
define|#
directive|define
name|__ev_mwhusiaaw
value|__internal_ev_mwhusiaaw
end_define

begin_define
define|#
directive|define
name|__ev_mwhumiaaw
value|__internal_ev_mwhumiaaw
end_define

begin_define
define|#
directive|define
name|__ev_mwhssfanw
value|__internal_ev_mwhssfanw
end_define

begin_define
define|#
directive|define
name|__ev_mwhssianw
value|__internal_ev_mwhssianw
end_define

begin_define
define|#
directive|define
name|__ev_mwhsmfanw
value|__internal_ev_mwhsmfanw
end_define

begin_define
define|#
directive|define
name|__ev_mwhsmianw
value|__internal_ev_mwhsmianw
end_define

begin_define
define|#
directive|define
name|__ev_mwhusianw
value|__internal_ev_mwhusianw
end_define

begin_define
define|#
directive|define
name|__ev_mwhumianw
value|__internal_ev_mwhumianw
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
value|__ev_get_u32_internal ((a), 0)
end_define

begin_define
define|#
directive|define
name|__ev_get_lower_u32
parameter_list|(
name|a
parameter_list|)
value|__ev_get_u32_internal ((a), 1)
end_define

begin_define
define|#
directive|define
name|__ev_get_upper_s32
parameter_list|(
name|a
parameter_list|)
value|__ev_get_s32_internal ((a), 0)
end_define

begin_define
define|#
directive|define
name|__ev_get_lower_s32
parameter_list|(
name|a
parameter_list|)
value|__ev_get_s32_internal ((a), 1)
end_define

begin_define
define|#
directive|define
name|__ev_get_upper_fs
parameter_list|(
name|a
parameter_list|)
value|__ev_get_fs_internal ((a), 0)
end_define

begin_define
define|#
directive|define
name|__ev_get_lower_fs
parameter_list|(
name|a
parameter_list|)
value|__ev_get_fs_internal ((a), 1)
end_define

begin_define
define|#
directive|define
name|__ev_get_upper_ufix32_u32
value|__ev_get_upper_u32
end_define

begin_define
define|#
directive|define
name|__ev_get_lower_ufix32_u32
value|__ev_get_lower_u32
end_define

begin_define
define|#
directive|define
name|__ev_get_upper_sfix32_s32
value|__ev_get_upper_s32
end_define

begin_define
define|#
directive|define
name|__ev_get_lower_sfix32_s32
value|__ev_get_lower_s32
end_define

begin_define
define|#
directive|define
name|__ev_get_upper_sfix32_fs
parameter_list|(
name|a
parameter_list|)
value|__ev_get_sfix32_fs ((a), 0)
end_define

begin_define
define|#
directive|define
name|__ev_get_lower_sfix32_fs
parameter_list|(
name|a
parameter_list|)
value|__ev_get_sfix32_fs ((a), 1)
end_define

begin_define
define|#
directive|define
name|__ev_get_upper_ufix32_fs
parameter_list|(
name|a
parameter_list|)
value|__ev_get_ufix32_fs ((a), 0)
end_define

begin_define
define|#
directive|define
name|__ev_get_lower_ufix32_fs
parameter_list|(
name|a
parameter_list|)
value|__ev_get_ufix32_fs ((a), 1)
end_define

begin_define
define|#
directive|define
name|__ev_get_u32
value|__ev_get_u32_internal
end_define

begin_define
define|#
directive|define
name|__ev_get_s32
value|__ev_get_s32_internal
end_define

begin_define
define|#
directive|define
name|__ev_get_fs
value|__ev_get_fs_internal
end_define

begin_define
define|#
directive|define
name|__ev_get_u16
value|__ev_get_u16_internal
end_define

begin_define
define|#
directive|define
name|__ev_get_s16
value|__ev_get_s16_internal
end_define

begin_define
define|#
directive|define
name|__ev_get_ufix32_u32
value|__ev_get_u32
end_define

begin_define
define|#
directive|define
name|__ev_get_sfix32_s32
value|__ev_get_s32
end_define

begin_define
define|#
directive|define
name|__ev_get_ufix32_fs
value|__ev_get_ufix32_fs_internal
end_define

begin_define
define|#
directive|define
name|__ev_get_sfix32_fs
value|__ev_get_sfix32_fs_internal
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
value|__ev_set_u32_internal
end_define

begin_define
define|#
directive|define
name|__ev_set_s32
value|__ev_set_s32_internal
end_define

begin_define
define|#
directive|define
name|__ev_set_fs
value|__ev_set_fs_internal
end_define

begin_define
define|#
directive|define
name|__ev_set_u16
value|__ev_set_u16_internal
end_define

begin_define
define|#
directive|define
name|__ev_set_s16
value|__ev_set_s16_internal
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
value|__ev_set_sfix32_fs_internal
end_define

begin_define
define|#
directive|define
name|__ev_set_ufix32_fs
value|__ev_set_ufix32_fs_internal
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
value|__builtin_spe_evmra
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
value|__builtin_spe_evcmpgts (__pred_any, (a), (b))
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
value|__builtin_spe_evcmpgts (__pred_all, (a), (b))
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
value|__builtin_spe_evcmpgts (__pred_upper, (a), (b))
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
value|__builtin_spe_evcmpgts (__pred_lower, (a), (b))
end_define

begin_define
define|#
directive|define
name|__ev_select_gts
value|__builtin_spe_evsel_gts
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
value|__builtin_spe_evcmpgtu (__pred_any, (a), (b))
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
value|__builtin_spe_evcmpgtu (__pred_all, (a), (b))
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
value|__builtin_spe_evcmpgtu (__pred_upper, (a), (b))
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
value|__builtin_spe_evcmpgtu (__pred_lower, (a), (b))
end_define

begin_define
define|#
directive|define
name|__ev_select_gtu
value|__builtin_spe_evsel_gtu
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
value|__builtin_spe_evcmplts (__pred_any, (a), (b))
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
value|__builtin_spe_evcmplts (__pred_all, (a), (b))
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
value|__builtin_spe_evcmplts (__pred_upper, (a), (b))
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
value|__builtin_spe_evcmplts (__pred_lower, (a), (b))
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
value|((__v2si) __builtin_spe_evsel_lts ((a), (b), (c), (d)))
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
value|__builtin_spe_evcmpltu (__pred_any, (a), (b))
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
value|__builtin_spe_evcmpltu (__pred_all, (a), (b))
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
value|__builtin_spe_evcmpltu (__pred_upper, (a), (b))
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
value|__builtin_spe_evcmpltu (__pred_lower, (a), (b))
end_define

begin_define
define|#
directive|define
name|__ev_select_ltu
value|__builtin_spe_evsel_ltu
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
value|__builtin_spe_evcmpeq (__pred_any, (a), (b))
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
value|__builtin_spe_evcmpeq (__pred_all, (a), (b))
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
value|__builtin_spe_evcmpeq (__pred_upper, (a), (b))
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
value|__builtin_spe_evcmpeq (__pred_lower, (a), (b))
end_define

begin_define
define|#
directive|define
name|__ev_select_eq
value|__builtin_spe_evsel_eq
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
value|__builtin_spe_evfscmpgt (__pred_any, (a), (b))
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
value|__builtin_spe_evfscmpgt (__pred_all, (a), (b))
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
value|__builtin_spe_evfscmpgt (__pred_upper, (a), (b))
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
value|__builtin_spe_evfscmpgt (__pred_lower, (a), (b))
end_define

begin_define
define|#
directive|define
name|__ev_select_fs_gt
value|__builtin_spe_evsel_fsgt
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
value|__builtin_spe_evfscmplt (__pred_any, (a), (b))
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
value|__builtin_spe_evfscmplt (__pred_all, (a), (b))
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
value|__builtin_spe_evfscmplt (__pred_upper, (a), (b))
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
value|__builtin_spe_evfscmplt (__pred_lower, (a), (b))
end_define

begin_define
define|#
directive|define
name|__ev_select_fs_lt
value|__builtin_spe_evsel_fslt
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
value|__builtin_spe_evfscmpeq (__pred_any, (a), (b))
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
value|__builtin_spe_evfscmpeq (__pred_all, (a), (b))
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
value|__builtin_spe_evfscmpeq (__pred_upper, (a), (b))
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
value|__builtin_spe_evfscmpeq (__pred_lower, (a), (b))
end_define

begin_define
define|#
directive|define
name|__ev_select_fs_eq
value|__builtin_spe_evsel_fseq
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
value|__builtin_spe_evfststgt (__pred_any, (a), (b))
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
value|__builtin_spe_evfststgt (__pred_all, (a), (b))
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
value|__builtin_spe_evfststgt (__pred_upper, (a), (b))
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
value|__builtin_spe_evfststgt (__pred_lower, (a), (b))
end_define

begin_define
define|#
directive|define
name|__ev_select_fs_tst_gt
value|__builtin_spe_evsel_fststgt
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
value|__builtin_spe_evfststlt (__pred_any, (a), (b))
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
value|__builtin_spe_evfststlt (__pred_all, (a), (b))
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
value|__builtin_spe_evfststlt (__pred_upper, (a), (b))
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
value|__builtin_spe_evfststlt (__pred_lower, (a), (b))
end_define

begin_define
define|#
directive|define
name|__ev_select_fs_tst_lt
value|__builtin_spe_evsel_fststlt
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
value|__builtin_spe_evfststeq (__pred_any, (a), (b))
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
value|__builtin_spe_evfststeq (__pred_all, (a), (b))
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
value|__builtin_spe_evfststeq (__pred_upper, (a), (b))
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
value|__builtin_spe_evfststeq (__pred_lower, (a), (b))
end_define

begin_define
define|#
directive|define
name|__ev_select_fs_tst_eq
value|__builtin_spe_evsel_fststeq
end_define

begin_comment
comment|/* SPEFSCR accessor functions.  */
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
name|__builtin_spe_mtspefscr
argument_list|(
name|i
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/* The SPE PIM says these are declared in<spe.h>, although they are    not provided by GCC: they must be taken from a separate    library.  */
end_comment

begin_function_decl
specifier|extern
name|short
name|int
name|atosfix16
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|atosfix32
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|long
name|long
name|atosfix64
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|unsigned
name|short
name|atoufix16
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|unsigned
name|int
name|atoufix32
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|unsigned
name|long
name|long
name|atoufix64
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|short
name|int
name|strtosfix16
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|char
modifier|*
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|strtosfix32
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|char
modifier|*
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|long
name|long
name|strtosfix64
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|char
modifier|*
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|unsigned
name|short
name|int
name|strtoufix16
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|char
modifier|*
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|unsigned
name|int
name|strtoufix32
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|char
modifier|*
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|unsigned
name|long
name|long
name|strtoufix64
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|char
modifier|*
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _SPE_H */
end_comment

end_unit

