begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1988 Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Chris Torek.  *  * Redistribution and use in source and binary forms are permitted  * provided that the above copyright notice and this paragraph are  * duplicated in all such forms and that any documentation,  * advertising materials, and other materials related to such  * distribution and use acknowledge that the software was developed  * by the University of California, Berkeley.  The name of the  * University may not be used to endorse or promote products derived  * from this software without specific prior written permission.  * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED  * WARRANTIES OF MERCHANTIBILITY AND FITNESS FOR A PARTICULAR PURPOSE.  *  *	@(#)nireg.h	7.2 (Berkeley) 7/9/88  */
end_comment

begin_comment
comment|/*  * Registers for the DEBNA and DEBNK Ethernet interfaces  * (DEC calls these Network Interfaces, hence nireg.h)  */
end_comment

begin_comment
comment|/*  * this seems to be intended to be more general, but I have no details,  * so it goes here for now  *  * BI Vax Port (BVP) stuff first:  */
end_comment

begin_struct
struct|struct
name|bvpregs
block|{
name|u_long
name|p_pcr
decl_stmt|;
comment|/* port control register */
name|u_long
name|p_psr
decl_stmt|;
comment|/* port status register */
name|u_long
name|p_per
decl_stmt|;
comment|/* port error register */
name|u_long
name|p_pdr
decl_stmt|;
comment|/* port data register */
block|}
struct|;
end_struct

begin_comment
comment|/*  * BI node space registers  */
end_comment

begin_struct
struct|struct
name|ni_regs
block|{
name|struct
name|biiregs
name|ni_bi
decl_stmt|;
comment|/* BIIC registers, except GPRs */
name|struct
name|bvpregs
name|ni_tkp
decl_stmt|;
comment|/* tk50 port control via BIIC GPRs */
name|u_long
name|ni_xxx
index|[
literal|64
index|]
decl_stmt|;
comment|/* unused */
name|u_long
name|ni_rxcd
decl_stmt|;
comment|/* receive console data */
name|struct
name|bvpregs
name|ni_nip
decl_stmt|;
comment|/* NI port control via BCI3 GPRs */
name|u_long
name|ni_pudr
decl_stmt|;
comment|/* power-up diagnostic register */
block|}
struct|;
end_struct

begin_comment
comment|/* bits in ni_pudr */
end_comment

begin_define
define|#
directive|define
name|PUDR_TAPE
value|0x40000000
end_define

begin_comment
comment|/* tk50& assoc logic ok */
end_comment

begin_define
define|#
directive|define
name|PUDR_PATCH
value|0x20000000
end_define

begin_comment
comment|/* patch logic ok */
end_comment

begin_define
define|#
directive|define
name|PUDR_VRAM
value|0x10000000
end_define

begin_comment
comment|/* DEBNx onboard RAM ok */
end_comment

begin_define
define|#
directive|define
name|PUDR_VROM1
value|0x08000000
end_define

begin_comment
comment|/* uVax ROM 1 ok */
end_comment

begin_comment
comment|/* ? */
end_comment

begin_define
define|#
directive|define
name|PUDR_VROM2
value|0x04000000
end_define

begin_comment
comment|/* uVax ROM 2 ok */
end_comment

begin_define
define|#
directive|define
name|PUDR_VROM3
value|0x02000000
end_define

begin_comment
comment|/* uVax ROM 3 ok */
end_comment

begin_define
define|#
directive|define
name|PUDR_VROM4
value|0x01000000
end_define

begin_comment
comment|/* uVax ROM 4 ok */
end_comment

begin_define
define|#
directive|define
name|PUDR_UVAX
value|0x00800000
end_define

begin_comment
comment|/* uVax passes self test */
end_comment

begin_define
define|#
directive|define
name|PUDR_BI
value|0x00400000
end_define

begin_comment
comment|/* BIIC and BCI3 chips ok */
end_comment

begin_define
define|#
directive|define
name|PUDR_TMR
value|0x00200000
end_define

begin_comment
comment|/* interval timer ok */
end_comment

begin_define
define|#
directive|define
name|PUDR_IRQ
value|0x00100000
end_define

begin_comment
comment|/* no IRQ lines stuck */
end_comment

begin_define
define|#
directive|define
name|PUDR_NI
value|0x00080000
end_define

begin_comment
comment|/* Ethernet ctlr ok */
end_comment

begin_define
define|#
directive|define
name|PUDR_TK50
value|0x00040000
end_define

begin_comment
comment|/* tk50 present */
end_comment

begin_define
define|#
directive|define
name|PUDR_PRES
value|0x00001000
end_define

begin_comment
comment|/* tk50 present (again?!) */
end_comment

begin_define
define|#
directive|define
name|PUDR_UVINT
value|0x00000800
end_define

begin_comment
comment|/* uVax-to-80186 intr logic ok */
end_comment

begin_define
define|#
directive|define
name|PUDR_BUSHD
value|0x00000400
end_define

begin_comment
comment|/* no bus hold errors */
end_comment

begin_define
define|#
directive|define
name|PUDR_II32
value|0x00000200
end_define

begin_comment
comment|/* II32 transceivers ok */
end_comment

begin_define
define|#
directive|define
name|PUDR_MPSC
value|0x00000100
end_define

begin_comment
comment|/* MPSC logic ok */
end_comment

begin_define
define|#
directive|define
name|PUDR_GAP
value|0x00000080
end_define

begin_comment
comment|/* gap-detect logic ok */
end_comment

begin_define
define|#
directive|define
name|PUDR_MISC
value|0x00000040
end_define

begin_comment
comment|/* misc. registers ok */
end_comment

begin_define
define|#
directive|define
name|PUDR_UNEXP
value|0x00000020
end_define

begin_comment
comment|/* unexpected interrupt trapped */
end_comment

begin_define
define|#
directive|define
name|PUDR_80186
value|0x00000010
end_define

begin_comment
comment|/* 80186 ok */
end_comment

begin_define
define|#
directive|define
name|PUDR_PATCH
value|0x00000008
end_define

begin_comment
comment|/* patch logic ok (again) */
end_comment

begin_define
define|#
directive|define
name|PUDR_8RAM
value|0x00000004
end_define

begin_comment
comment|/* 80186 RAM ok */
end_comment

begin_define
define|#
directive|define
name|PUDR_8ROM2
value|0x00000002
end_define

begin_comment
comment|/* 80186 ROM1 ok */
end_comment

begin_define
define|#
directive|define
name|PUDR_8ROM1
value|0x00000001
end_define

begin_comment
comment|/* 80186 ROM2 ok */
end_comment

end_unit

