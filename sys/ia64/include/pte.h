begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2001 Doug Rabson  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_MACHINE_PTE_H_
end_ifndef

begin_define
define|#
directive|define
name|_MACHINE_PTE_H_
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|LOCORE
end_ifdef

begin_define
define|#
directive|define
name|PTE_P
value|(1<<0)
end_define

begin_define
define|#
directive|define
name|PTE_MA_WB
value|(0<<2)
end_define

begin_define
define|#
directive|define
name|PTE_MA_UC
value|(4<<2)
end_define

begin_define
define|#
directive|define
name|PTE_MA_UCE
value|(5<<2)
end_define

begin_define
define|#
directive|define
name|PTE_MA_WC
value|(6<<2)
end_define

begin_define
define|#
directive|define
name|PTE_MA_NATPAGE
value|(7<<2)
end_define

begin_define
define|#
directive|define
name|PTE_A
value|(1<<5)
end_define

begin_define
define|#
directive|define
name|PTE_D
value|(1<<6)
end_define

begin_define
define|#
directive|define
name|PTE_PL_KERN
value|(0<<7)
end_define

begin_define
define|#
directive|define
name|PTE_PL_USER
value|(3<<7)
end_define

begin_define
define|#
directive|define
name|PTE_AR_R
value|(0<<9)
end_define

begin_define
define|#
directive|define
name|PTE_AR_RX
value|(1<<9)
end_define

begin_define
define|#
directive|define
name|PTE_AR_RW
value|(2<<9)
end_define

begin_define
define|#
directive|define
name|PTE_AR_RWX
value|(3<<9)
end_define

begin_define
define|#
directive|define
name|PTE_AR_R_RW
value|(4<<9)
end_define

begin_define
define|#
directive|define
name|PTE_AR_RX_RWX
value|(5<<9)
end_define

begin_define
define|#
directive|define
name|PTE_AR_RWX_RW
value|(6<<9)
end_define

begin_define
define|#
directive|define
name|PTE_AR_X_RX
value|(7<<9)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|PTE_MA_WB
value|0
end_define

begin_define
define|#
directive|define
name|PTE_MA_UC
value|4
end_define

begin_define
define|#
directive|define
name|PTE_MA_UCE
value|5
end_define

begin_define
define|#
directive|define
name|PTE_MA_WC
value|6
end_define

begin_define
define|#
directive|define
name|PTE_MA_NATPAGE
value|7
end_define

begin_define
define|#
directive|define
name|PTE_PL_KERN
value|0
end_define

begin_define
define|#
directive|define
name|PTE_PL_USER
value|3
end_define

begin_define
define|#
directive|define
name|PTE_AR_R
value|0
end_define

begin_define
define|#
directive|define
name|PTE_AR_RX
value|1
end_define

begin_define
define|#
directive|define
name|PTE_AR_RW
value|2
end_define

begin_define
define|#
directive|define
name|PTE_AR_RWX
value|3
end_define

begin_define
define|#
directive|define
name|PTE_AR_R_RW
value|4
end_define

begin_define
define|#
directive|define
name|PTE_AR_RX_RWX
value|5
end_define

begin_define
define|#
directive|define
name|PTE_AR_RWX_RW
value|6
end_define

begin_define
define|#
directive|define
name|PTE_AR_X_RX
value|7
end_define

begin_define
define|#
directive|define
name|PTE_IG_WIRED
value|1
end_define

begin_define
define|#
directive|define
name|PTE_IG_MANAGED
value|2
end_define

begin_comment
comment|/*  * A short-format VHPT entry. Also matches the TLB insertion format.  */
end_comment

begin_struct
struct|struct
name|ia64_pte
block|{
name|u_int64_t
name|pte_p
range|:
literal|1
decl_stmt|;
comment|/* bits 0..0 */
name|u_int64_t
name|pte_rv1
range|:
literal|1
decl_stmt|;
comment|/* bits 1..1 */
name|u_int64_t
name|pte_ma
range|:
literal|3
decl_stmt|;
comment|/* bits 2..4 */
name|u_int64_t
name|pte_a
range|:
literal|1
decl_stmt|;
comment|/* bits 5..5 */
name|u_int64_t
name|pte_d
range|:
literal|1
decl_stmt|;
comment|/* bits 6..6 */
name|u_int64_t
name|pte_pl
range|:
literal|2
decl_stmt|;
comment|/* bits 7..8 */
name|u_int64_t
name|pte_ar
range|:
literal|3
decl_stmt|;
comment|/* bits 9..11 */
name|u_int64_t
name|pte_ppn
range|:
literal|38
decl_stmt|;
comment|/* bits 12..49 */
name|u_int64_t
name|pte_rv2
range|:
literal|2
decl_stmt|;
comment|/* bits 50..51 */
name|u_int64_t
name|pte_ed
range|:
literal|1
decl_stmt|;
comment|/* bits 52..52 */
name|u_int64_t
name|pte_ig
range|:
literal|11
decl_stmt|;
comment|/* bits 53..63 */
block|}
struct|;
end_struct

begin_comment
comment|/*  * A long-format VHPT entry.  */
end_comment

begin_struct
struct|struct
name|ia64_lpte
block|{
name|u_int64_t
name|pte_p
range|:
literal|1
decl_stmt|;
comment|/* bits 0..0 */
name|u_int64_t
name|pte_rv1
range|:
literal|1
decl_stmt|;
comment|/* bits 1..1 */
name|u_int64_t
name|pte_ma
range|:
literal|3
decl_stmt|;
comment|/* bits 2..4 */
name|u_int64_t
name|pte_a
range|:
literal|1
decl_stmt|;
comment|/* bits 5..5 */
name|u_int64_t
name|pte_d
range|:
literal|1
decl_stmt|;
comment|/* bits 6..6 */
name|u_int64_t
name|pte_pl
range|:
literal|2
decl_stmt|;
comment|/* bits 7..8 */
name|u_int64_t
name|pte_ar
range|:
literal|3
decl_stmt|;
comment|/* bits 9..11 */
name|u_int64_t
name|pte_ppn
range|:
literal|38
decl_stmt|;
comment|/* bits 12..49 */
name|u_int64_t
name|pte_rv2
range|:
literal|2
decl_stmt|;
comment|/* bits 50..51 */
name|u_int64_t
name|pte_ed
range|:
literal|1
decl_stmt|;
comment|/* bits 52..52 */
name|u_int64_t
name|pte_ig
range|:
literal|11
decl_stmt|;
comment|/* bits 53..63 */
name|u_int64_t
name|pte_rv3
range|:
literal|2
decl_stmt|;
comment|/* bits 0..1 */
name|u_int64_t
name|pte_ps
range|:
literal|6
decl_stmt|;
comment|/* bits 2..7 */
name|u_int64_t
name|pte_key
range|:
literal|24
decl_stmt|;
comment|/* bits 8..31 */
name|u_int64_t
name|pte_rv4
range|:
literal|32
decl_stmt|;
comment|/* bits 32..63 */
name|u_int64_t
name|pte_tag
decl_stmt|;
comment|/* includes ti */
name|u_int64_t
name|pte_chain
decl_stmt|;
comment|/* pa of collision chain */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Layout of cr.itir.  */
end_comment

begin_struct
struct|struct
name|ia64_itir
block|{
name|u_int64_t
name|itir_rv1
range|:
literal|2
decl_stmt|;
comment|/* bits 0..1 */
name|u_int64_t
name|itir_ps
range|:
literal|6
decl_stmt|;
comment|/* bits 2..7 */
name|u_int64_t
name|itir_key
range|:
literal|24
decl_stmt|;
comment|/* bits 8..31 */
name|u_int64_t
name|itir_rv2
range|:
literal|32
decl_stmt|;
comment|/* bits 32..63 */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Layout of cr.ifa.  */
end_comment

begin_struct
struct|struct
name|ia64_ifa
block|{
name|u_int64_t
name|ifa_ig
range|:
literal|12
decl_stmt|;
comment|/* bits 0..11 */
name|u_int64_t
name|ifa_vpn
range|:
literal|52
decl_stmt|;
comment|/* bits 12..63 */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Layout of rr[x].  */
end_comment

begin_struct
struct|struct
name|ia64_rr
block|{
name|u_int64_t
name|rr_ve
range|:
literal|1
decl_stmt|;
comment|/* bits 0..0 */
name|u_int64_t
name|rr_rv1
range|:
literal|1
decl_stmt|;
comment|/* bits 1..1 */
name|u_int64_t
name|rr_ps
range|:
literal|6
decl_stmt|;
comment|/* bits 2..7 */
name|u_int64_t
name|rr_rid
range|:
literal|24
decl_stmt|;
comment|/* bits 8..31 */
name|u_int64_t
name|rr_rv2
range|:
literal|32
decl_stmt|;
comment|/* bits 32..63 */
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !LOCORE */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_MACHINE_PTE_H_ */
end_comment

end_unit

