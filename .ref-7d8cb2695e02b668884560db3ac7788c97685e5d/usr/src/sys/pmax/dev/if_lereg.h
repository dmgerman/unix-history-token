begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1992 The Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Ralph Campbell and Rick Macklem.  *  * %sccs.include.redist.c%  *  *	@(#)if_lereg.h	7.3 (Berkeley) %G%  */
end_comment

begin_define
define|#
directive|define
name|LEMTU
value|1518
end_define

begin_define
define|#
directive|define
name|LEBLEN
value|1520
end_define

begin_comment
comment|/* LEMTU up to a multiple of 16 */
end_comment

begin_define
define|#
directive|define
name|LEMINSIZE
value|60
end_define

begin_comment
comment|/* should be 64 if mode DTCR is set */
end_comment

begin_define
define|#
directive|define
name|LERBUF
value|32
end_define

begin_define
define|#
directive|define
name|LERBUFLOG2
value|5
end_define

begin_define
define|#
directive|define
name|LE_RLEN
value|(LERBUFLOG2<< 13)
end_define

begin_define
define|#
directive|define
name|LETBUF
value|8
end_define

begin_define
define|#
directive|define
name|LETBUFLOG2
value|3
end_define

begin_define
define|#
directive|define
name|LE_TLEN
value|(LETBUFLOG2<< 13)
end_define

begin_comment
comment|/*  * LANCE registers.  */
end_comment

begin_struct
struct|struct
name|lereg1
block|{
name|u_short
name|ler1_rdp
decl_stmt|;
comment|/* data port */
name|short
name|pad0
decl_stmt|;
name|u_short
name|ler1_rap
decl_stmt|;
comment|/* register select port */
name|short
name|pad1
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * This structure is overlayed on the network dual-port RAM.  * Currently 32 * 1520 receive plus 8 * 1520 transmit buffers plus  * buffer descriptor rings.  * There are two variants of the structure, one for the Pmax/3min/maxine  * with 2 byte pads between entries and one for the 3max and turbochannel  * option densely packed.  */
end_comment

begin_struct
struct|struct
name|lermd
block|{
comment|/* +0x0020 */
name|u_short
name|rmd0
decl_stmt|;
name|u_short
name|rmd1
decl_stmt|;
name|short
name|rmd2
decl_stmt|;
name|u_short
name|rmd3
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|letmd
block|{
comment|/* +0x0058 */
name|u_short
name|tmd0
decl_stmt|;
name|u_short
name|tmd1
decl_stmt|;
name|short
name|tmd2
decl_stmt|;
name|u_short
name|tmd3
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|lermdpad
block|{
comment|/* +0x0020 */
name|u_short
name|rmd0
decl_stmt|;
name|short
name|pad0
decl_stmt|;
name|u_short
name|rmd1
decl_stmt|;
name|short
name|pad1
decl_stmt|;
name|short
name|rmd2
decl_stmt|;
name|short
name|pad2
decl_stmt|;
name|u_short
name|rmd3
decl_stmt|;
name|short
name|pad3
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|letmdpad
block|{
comment|/* +0x0058 */
name|u_short
name|tmd0
decl_stmt|;
name|short
name|pad0
decl_stmt|;
name|u_short
name|tmd1
decl_stmt|;
name|short
name|pad1
decl_stmt|;
name|short
name|tmd2
decl_stmt|;
name|short
name|pad2
decl_stmt|;
name|u_short
name|tmd3
decl_stmt|;
name|short
name|pad3
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|lereg2
block|{
comment|/* init block */
comment|/* CHIP address */
name|u_short
name|ler2_mode
decl_stmt|;
comment|/* +0x0000 */
name|u_short
name|ler2_padr0
decl_stmt|;
comment|/* +0x0002 */
name|u_short
name|ler2_padr1
decl_stmt|;
comment|/* +0x0004 */
name|u_short
name|ler2_padr2
decl_stmt|;
comment|/* +0x0006 */
name|u_short
name|ler2_ladrf0
decl_stmt|;
comment|/* +0x0008 */
name|u_short
name|ler2_ladrf1
decl_stmt|;
comment|/* +0x000A */
name|u_short
name|ler2_ladrf2
decl_stmt|;
comment|/* +0x000C */
name|u_short
name|ler2_ladrf3
decl_stmt|;
comment|/* +0x000E */
name|u_short
name|ler2_rdra
decl_stmt|;
comment|/* +0x0010 */
name|u_short
name|ler2_rlen
decl_stmt|;
comment|/* +0x0012 */
name|u_short
name|ler2_tdra
decl_stmt|;
comment|/* +0x0014 */
name|u_short
name|ler2_tlen
decl_stmt|;
comment|/* +0x0016 */
name|short
name|pad0
index|[
literal|4
index|]
decl_stmt|;
comment|/* Pad to 16 shorts */
comment|/* receive message descriptors */
name|struct
name|lermd
name|ler2_rmd
index|[
name|LERBUF
index|]
decl_stmt|;
comment|/* transmit message descriptors */
name|struct
name|letmd
name|ler2_tmd
index|[
name|LETBUF
index|]
decl_stmt|;
name|char
name|ler2_rbuf
index|[
name|LERBUF
index|]
index|[
name|LEBLEN
index|]
decl_stmt|;
comment|/* +0x0060 */
name|char
name|ler2_tbuf
index|[
name|LETBUF
index|]
index|[
name|LEBLEN
index|]
decl_stmt|;
comment|/* +0x2FD0 */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|lereg2pad
block|{
comment|/* init block */
comment|/* CHIP address */
name|u_short
name|ler2_mode
decl_stmt|;
comment|/* +0x0000 */
name|short
name|pad0
decl_stmt|;
name|u_short
name|ler2_padr0
decl_stmt|;
comment|/* +0x0002 */
name|short
name|pad1
decl_stmt|;
name|u_short
name|ler2_padr1
decl_stmt|;
comment|/* +0x0004 */
name|short
name|pad2
decl_stmt|;
name|u_short
name|ler2_padr2
decl_stmt|;
comment|/* +0x0006 */
name|short
name|pad3
decl_stmt|;
name|u_short
name|ler2_ladrf0
decl_stmt|;
comment|/* +0x0008 */
name|short
name|pad4
decl_stmt|;
name|u_short
name|ler2_ladrf1
decl_stmt|;
comment|/* +0x000A */
name|short
name|pad5
decl_stmt|;
name|u_short
name|ler2_ladrf2
decl_stmt|;
comment|/* +0x000C */
name|short
name|pad6
decl_stmt|;
name|u_short
name|ler2_ladrf3
decl_stmt|;
comment|/* +0x000E */
name|short
name|pad7
decl_stmt|;
name|u_short
name|ler2_rdra
decl_stmt|;
comment|/* +0x0010 */
name|short
name|pad8
decl_stmt|;
name|u_short
name|ler2_rlen
decl_stmt|;
comment|/* +0x0012 */
name|short
name|pad9
decl_stmt|;
name|u_short
name|ler2_tdra
decl_stmt|;
comment|/* +0x0014 */
name|short
name|pad10
decl_stmt|;
name|u_short
name|ler2_tlen
decl_stmt|;
comment|/* +0x0016 */
name|short
name|pad11
index|[
literal|9
index|]
decl_stmt|;
comment|/* Pad to 32 shorts */
comment|/* receive message descriptors */
name|struct
name|lermdpad
name|ler2_rmd
index|[
name|LERBUF
index|]
decl_stmt|;
comment|/* transmit message descriptors */
name|struct
name|letmdpad
name|ler2_tmd
index|[
name|LETBUF
index|]
decl_stmt|;
name|short
name|ler2_rbuf
index|[
name|LERBUF
index|]
index|[
name|LEBLEN
index|]
decl_stmt|;
comment|/* +0x0060 */
name|short
name|ler2_tbuf
index|[
name|LETBUF
index|]
index|[
name|LEBLEN
index|]
decl_stmt|;
comment|/* +0x2FD0 */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Now for some truly ugly macros to access the structure fields  * padded/non-padded at runtime. (For once, a Pascal like record variant  * would be nice to have.)  */
end_comment

begin_define
define|#
directive|define
name|LER2_RMDADDR
parameter_list|(
name|p
parameter_list|,
name|i
parameter_list|)
define|\
value|(le->sc_ler2pad ? \ 		 (volatile void *)&(((struct lereg2pad *)(p))->ler2_rmd[(i)]) : \ 		 (volatile void *)&(((struct lereg2 *)(p))->ler2_rmd[(i)]))
end_define

begin_define
define|#
directive|define
name|LER2_TMDADDR
parameter_list|(
name|p
parameter_list|,
name|i
parameter_list|)
define|\
value|((le->sc_ler2pad ? \ 		 (volatile void *)&(((struct lereg2pad *)(p))->ler2_tmd[(i)]) : \ 		 (volatile void *)&(((struct lereg2 *)(p))->ler2_tmd[(i)])))
end_define

begin_define
define|#
directive|define
name|LER2_RBUFADDR
parameter_list|(
name|p
parameter_list|,
name|i
parameter_list|)
define|\
value|((le->sc_ler2pad ? \ 		 (volatile void *)(((struct lereg2pad *)(p))->ler2_rbuf[(i)]) : \ 		 (volatile void *)(((struct lereg2 *)(p))->ler2_rbuf[(i)])))
end_define

begin_define
define|#
directive|define
name|LER2_TBUFADDR
parameter_list|(
name|p
parameter_list|,
name|i
parameter_list|)
define|\
value|((le->sc_ler2pad ? \ 		 (volatile void *)(((struct lereg2pad *)(p))->ler2_tbuf[(i)]) : \ 		 (volatile void *)(((struct lereg2 *)(p))->ler2_tbuf[(i)])))
end_define

begin_define
define|#
directive|define
name|LER2_mode
parameter_list|(
name|p
parameter_list|,
name|v
parameter_list|)
define|\
value|(le->sc_ler2pad ? (((volatile struct lereg2pad *)(p))->ler2_mode = (v)) : \ 	 (((volatile struct lereg2 *)(p))->ler2_mode = (v)))
end_define

begin_define
define|#
directive|define
name|LER2V_mode
parameter_list|(
name|p
parameter_list|)
define|\
value|(le->sc_ler2pad ? ((volatile struct lereg2pad *)(p))->ler2_mode : \ 	 ((volatile struct lereg2 *)(p))->ler2_mode)
end_define

begin_define
define|#
directive|define
name|LER2_padr0
parameter_list|(
name|p
parameter_list|,
name|v
parameter_list|)
define|\
value|(le->sc_ler2pad ? (((volatile struct lereg2pad *)(p))->ler2_padr0 = (v)) : \ 	 (((volatile struct lereg2 *)(p))->ler2_padr0 = (v)))
end_define

begin_define
define|#
directive|define
name|LER2V_padr0
parameter_list|(
name|p
parameter_list|)
define|\
value|(le->sc_ler2pad ? ((volatile struct lereg2pad *)(p))->ler2_padr0 : \ 	 ((volatile struct lereg2 *)(p))->ler2_padr0)
end_define

begin_define
define|#
directive|define
name|LER2_padr1
parameter_list|(
name|p
parameter_list|,
name|v
parameter_list|)
define|\
value|(le->sc_ler2pad ? (((volatile struct lereg2pad *)(p))->ler2_padr1 = (v)) : \ 	 (((volatile struct lereg2 *)(p))->ler2_padr1 = (v)))
end_define

begin_define
define|#
directive|define
name|LER2V_padr1
parameter_list|(
name|p
parameter_list|)
define|\
value|(le->sc_ler2pad ? ((volatile struct lereg2pad *)(p))->ler2_padr1 : \ 	 ((volatile struct lereg2 *)(p))->ler2_padr1)
end_define

begin_define
define|#
directive|define
name|LER2_padr2
parameter_list|(
name|p
parameter_list|,
name|v
parameter_list|)
define|\
value|(le->sc_ler2pad ? (((volatile struct lereg2pad *)(p))->ler2_padr2 = (v)) : \ 	 (((volatile struct lereg2 *)(p))->ler2_padr2 = (v)))
end_define

begin_define
define|#
directive|define
name|LER2V_padr2
parameter_list|(
name|p
parameter_list|)
define|\
value|(le->sc_ler2pad ? ((volatile struct lereg2pad *)(p))->ler2_padr2 : \ 	 ((volatile struct lereg2 *)(p))->ler2_padr2)
end_define

begin_define
define|#
directive|define
name|LER2_ladrf0
parameter_list|(
name|p
parameter_list|,
name|v
parameter_list|)
define|\
value|(le->sc_ler2pad ? (((volatile struct lereg2pad *)(p))->ler2_ladrf0 = (v)) : \ 	 (((volatile struct lereg2 *)(p))->ler2_ladrf0 = (v)))
end_define

begin_define
define|#
directive|define
name|LER2V_ladrf0
parameter_list|(
name|p
parameter_list|)
define|\
value|(le->sc_ler2pad ? ((volatile struct lereg2pad *)(p))->ler2_ladrf0 : \ 	 ((volatile struct lereg2 *)(p))->ler2_ladrf0)
end_define

begin_define
define|#
directive|define
name|LER2_ladrf1
parameter_list|(
name|p
parameter_list|,
name|v
parameter_list|)
define|\
value|(le->sc_ler2pad ? (((volatile struct lereg2pad *)(p))->ler2_ladrf1 = (v)) : \ 	 (((volatile struct lereg2 *)(p))->ler2_ladrf1 = (v)))
end_define

begin_define
define|#
directive|define
name|LER2V_ladrf1
parameter_list|(
name|p
parameter_list|)
define|\
value|(le->sc_ler2pad ? ((volatile struct lereg2pad *)(p))->ler2_ladrf1 : \ 	 ((volatile struct lereg2 *)(p))->ler2_ladrf1)
end_define

begin_define
define|#
directive|define
name|LER2_ladrf2
parameter_list|(
name|p
parameter_list|,
name|v
parameter_list|)
define|\
value|(le->sc_ler2pad ? (((volatile struct lereg2pad *)(p))->ler2_ladrf2 = (v)) : \ 	 (((volatile struct lereg2 *)(p))->ler2_ladrf2 = (v)))
end_define

begin_define
define|#
directive|define
name|LER2V_ladrf2
parameter_list|(
name|p
parameter_list|)
define|\
value|(le->sc_ler2pad ? ((volatile struct lereg2pad *)(p))->ler2_ladrf2 : \ 	 ((volatile struct lereg2 *)(p))->ler2_ladrf2)
end_define

begin_define
define|#
directive|define
name|LER2_ladrf3
parameter_list|(
name|p
parameter_list|,
name|v
parameter_list|)
define|\
value|(le->sc_ler2pad ? (((volatile struct lereg2pad *)(p))->ler2_ladrf3 = (v)) : \ 	 (((volatile struct lereg2 *)(p))->ler2_ladrf3 = (v)))
end_define

begin_define
define|#
directive|define
name|LER2V_ladrf3
parameter_list|(
name|p
parameter_list|)
define|\
value|(le->sc_ler2pad ? ((volatile struct lereg2pad *)(p))->ler2_ladrf3 : \ 	 ((volatile struct lereg2 *)(p))->ler2_ladrf3)
end_define

begin_define
define|#
directive|define
name|LER2_rdra
parameter_list|(
name|p
parameter_list|,
name|v
parameter_list|)
define|\
value|(le->sc_ler2pad ? (((volatile struct lereg2pad *)(p))->ler2_rdra = (v)) : \ 	 (((volatile struct lereg2 *)(p))->ler2_rdra = (v)))
end_define

begin_define
define|#
directive|define
name|LER2V_rdra
parameter_list|(
name|p
parameter_list|)
define|\
value|(le->sc_ler2pad ? ((volatile struct lereg2pad *)(p))->ler2_rdra : \ 	 ((volatile struct lereg2 *)(p))->ler2_rdra)
end_define

begin_define
define|#
directive|define
name|LER2_rlen
parameter_list|(
name|p
parameter_list|,
name|v
parameter_list|)
define|\
value|(le->sc_ler2pad ? (((volatile struct lereg2pad *)(p))->ler2_rlen = (v)) : \ 	 (((volatile struct lereg2 *)(p))->ler2_rlen = (v)))
end_define

begin_define
define|#
directive|define
name|LER2V_rlen
parameter_list|(
name|p
parameter_list|)
define|\
value|(le->sc_ler2pad ? ((volatile struct lereg2pad *)(p))->ler2_rlen : \ 	 ((volatile struct lereg2 *)(p))->ler2_rlen)
end_define

begin_define
define|#
directive|define
name|LER2_tdra
parameter_list|(
name|p
parameter_list|,
name|v
parameter_list|)
define|\
value|(le->sc_ler2pad ? (((volatile struct lereg2pad *)(p))->ler2_tdra = (v)) : \ 	 (((volatile struct lereg2 *)(p))->ler2_tdra = (v)))
end_define

begin_define
define|#
directive|define
name|LER2V_tdra
parameter_list|(
name|p
parameter_list|)
define|\
value|(le->sc_ler2pad ? ((volatile struct lereg2pad *)(p))->ler2_tdra : \ 	 ((volatile struct lereg2 *)(p))->ler2_tdra)
end_define

begin_define
define|#
directive|define
name|LER2_tlen
parameter_list|(
name|p
parameter_list|,
name|v
parameter_list|)
define|\
value|(le->sc_ler2pad ? (((volatile struct lereg2pad *)(p))->ler2_tlen = (v)) : \ 	 (((volatile struct lereg2 *)(p))->ler2_tlen = (v)))
end_define

begin_define
define|#
directive|define
name|LER2V_tlen
parameter_list|(
name|p
parameter_list|)
define|\
value|(le->sc_ler2pad ? ((volatile struct lereg2pad *)(p))->ler2_tlen : \ 	 ((volatile struct lereg2 *)(p))->ler2_tlen)
end_define

begin_define
define|#
directive|define
name|LER2_rmd0
parameter_list|(
name|p
parameter_list|,
name|v
parameter_list|)
define|\
value|(le->sc_ler2pad ? (((volatile struct lermdpad *)(p))->rmd0 = (v)) : \ 	 ((((volatile struct lermd *)(p))->rmd0 = (v))))
end_define

begin_define
define|#
directive|define
name|LER2V_rmd0
parameter_list|(
name|p
parameter_list|)
define|\
value|(le->sc_ler2pad ? ((volatile struct lermdpad *)(p))->rmd0 : \ 	 ((volatile struct lermd *)(p))->rmd0)
end_define

begin_define
define|#
directive|define
name|LER2_rmd1
parameter_list|(
name|p
parameter_list|,
name|v
parameter_list|)
define|\
value|(le->sc_ler2pad ? (((volatile struct lermdpad *)(p))->rmd1 = (v)) : \ 	 (((volatile struct lermd *)(p))->rmd1 = (v)))
end_define

begin_define
define|#
directive|define
name|LER2V_rmd1
parameter_list|(
name|p
parameter_list|)
define|\
value|(le->sc_ler2pad ? ((volatile struct lermdpad *)(p))->rmd1 : \ 	 ((volatile struct lermd *)(p))->rmd1)
end_define

begin_define
define|#
directive|define
name|LER2_rmd2
parameter_list|(
name|p
parameter_list|,
name|v
parameter_list|)
define|\
value|(le->sc_ler2pad ? (((volatile struct lermdpad *)(p))->rmd2 = (v)) : \ 	 (((volatile struct lermd *)(p))->rmd2 = (v)))
end_define

begin_define
define|#
directive|define
name|LER2V_rmd2
parameter_list|(
name|p
parameter_list|)
define|\
value|(le->sc_ler2pad ? ((volatile struct lermdpad *)(p))->rmd2 : \ 	 ((volatile struct lermd *)(p))->rmd2)
end_define

begin_define
define|#
directive|define
name|LER2_rmd3
parameter_list|(
name|p
parameter_list|,
name|v
parameter_list|)
define|\
value|(le->sc_ler2pad ? (((volatile struct lermdpad *)(p))->rmd3 = (v)) : \ 	 (((volatile struct lermd *)(p))->rmd3 = (v)))
end_define

begin_define
define|#
directive|define
name|LER2V_rmd3
parameter_list|(
name|p
parameter_list|)
define|\
value|(le->sc_ler2pad ? ((volatile struct lermdpad *)(p))->rmd3 : \ 	 ((volatile struct lermd *)(p))->rmd3)
end_define

begin_define
define|#
directive|define
name|LER2_tmd0
parameter_list|(
name|p
parameter_list|,
name|v
parameter_list|)
define|\
value|(le->sc_ler2pad ? (((volatile struct letmdpad *)(p))->tmd0 = (v)) : \ 	 (((volatile struct letmd *)(p))->tmd0 = (v)))
end_define

begin_define
define|#
directive|define
name|LER2V_tmd0
parameter_list|(
name|p
parameter_list|)
define|\
value|(le->sc_ler2pad ? ((volatile struct letmdpad *)(p))->tmd0 : \ 	 ((volatile struct letmd *)(p))->tmd0)
end_define

begin_define
define|#
directive|define
name|LER2_tmd1
parameter_list|(
name|p
parameter_list|,
name|v
parameter_list|)
define|\
value|(le->sc_ler2pad ? (((volatile struct letmdpad *)(p))->tmd1 = (v)) : \ 	 (((volatile struct letmd *)(p))->tmd1 = (v)))
end_define

begin_define
define|#
directive|define
name|LER2V_tmd1
parameter_list|(
name|p
parameter_list|)
define|\
value|(le->sc_ler2pad ? ((volatile struct letmdpad *)(p))->tmd1 : \ 	 ((volatile struct letmd *)(p))->tmd1)
end_define

begin_define
define|#
directive|define
name|LER2_tmd2
parameter_list|(
name|p
parameter_list|,
name|v
parameter_list|)
define|\
value|(le->sc_ler2pad ? (((volatile struct letmdpad *)(p))->tmd2 = (v)) : \ 	 (((volatile struct letmd *)(p))->tmd2 = (v)))
end_define

begin_define
define|#
directive|define
name|LER2V_tmd2
parameter_list|(
name|p
parameter_list|)
define|\
value|(le->sc_ler2pad ? ((volatile struct letmdpad *)(p))->tmd2 : \ 	 ((volatile struct letmd *)(p))->tmd2)
end_define

begin_define
define|#
directive|define
name|LER2_tmd3
parameter_list|(
name|p
parameter_list|,
name|v
parameter_list|)
define|\
value|(le->sc_ler2pad ? (((volatile struct letmdpad *)(p))->tmd3 = (v)) : \ 	 (((volatile struct letmd *)(p))->tmd3 = (v)))
end_define

begin_define
define|#
directive|define
name|LER2V_tmd3
parameter_list|(
name|p
parameter_list|)
define|\
value|(le->sc_ler2pad ? ((volatile struct letmdpad *)(p))->tmd3 : \ 	 ((volatile struct letmd *)(p))->tmd3)
end_define

begin_comment
comment|/*  * Control and status bits -- lereg0  */
end_comment

begin_define
define|#
directive|define
name|LE_IE
value|0x80
end_define

begin_comment
comment|/* interrupt enable */
end_comment

begin_define
define|#
directive|define
name|LE_IR
value|0x40
end_define

begin_comment
comment|/* interrupt requested */
end_comment

begin_define
define|#
directive|define
name|LE_LOCK
value|0x08
end_define

begin_comment
comment|/* lock status register */
end_comment

begin_define
define|#
directive|define
name|LE_ACK
value|0x04
end_define

begin_comment
comment|/* ack of lock */
end_comment

begin_define
define|#
directive|define
name|LE_JAB
value|0x02
end_define

begin_comment
comment|/* loss of tx clock (???) */
end_comment

begin_define
define|#
directive|define
name|LE_IPL
parameter_list|(
name|x
parameter_list|)
value|((((x)>> 4)& 0x3) + 3)
end_define

begin_comment
comment|/*  * Control and status bits -- lereg1  */
end_comment

begin_define
define|#
directive|define
name|LE_CSR0
value|0
end_define

begin_define
define|#
directive|define
name|LE_CSR1
value|1
end_define

begin_define
define|#
directive|define
name|LE_CSR2
value|2
end_define

begin_define
define|#
directive|define
name|LE_CSR3
value|3
end_define

begin_define
define|#
directive|define
name|LE_SERR
value|0x8000
end_define

begin_define
define|#
directive|define
name|LE_BABL
value|0x4000
end_define

begin_define
define|#
directive|define
name|LE_CERR
value|0x2000
end_define

begin_define
define|#
directive|define
name|LE_MISS
value|0x1000
end_define

begin_define
define|#
directive|define
name|LE_MERR
value|0x0800
end_define

begin_define
define|#
directive|define
name|LE_RINT
value|0x0400
end_define

begin_define
define|#
directive|define
name|LE_TINT
value|0x0200
end_define

begin_define
define|#
directive|define
name|LE_IDON
value|0x0100
end_define

begin_define
define|#
directive|define
name|LE_INTR
value|0x0080
end_define

begin_define
define|#
directive|define
name|LE_INEA
value|0x0040
end_define

begin_define
define|#
directive|define
name|LE_RXON
value|0x0020
end_define

begin_define
define|#
directive|define
name|LE_TXON
value|0x0010
end_define

begin_define
define|#
directive|define
name|LE_TDMD
value|0x0008
end_define

begin_define
define|#
directive|define
name|LE_STOP
value|0x0004
end_define

begin_define
define|#
directive|define
name|LE_STRT
value|0x0002
end_define

begin_define
define|#
directive|define
name|LE_INIT
value|0x0001
end_define

begin_define
define|#
directive|define
name|LE_BSWP
value|0x4
end_define

begin_define
define|#
directive|define
name|LE_MODE
value|0x0
end_define

begin_comment
comment|/*  * Control and status bits -- lereg2  */
end_comment

begin_define
define|#
directive|define
name|LE_OWN
value|0x8000
end_define

begin_define
define|#
directive|define
name|LE_ERR
value|0x4000
end_define

begin_define
define|#
directive|define
name|LE_STP
value|0x0200
end_define

begin_define
define|#
directive|define
name|LE_ENP
value|0x0100
end_define

begin_define
define|#
directive|define
name|LE_FRAM
value|0x2000
end_define

begin_define
define|#
directive|define
name|LE_OFLO
value|0x1000
end_define

begin_define
define|#
directive|define
name|LE_CRC
value|0x0800
end_define

begin_define
define|#
directive|define
name|LE_RBUFF
value|0x0400
end_define

begin_define
define|#
directive|define
name|LE_MORE
value|0x1000
end_define

begin_define
define|#
directive|define
name|LE_ONE
value|0x0800
end_define

begin_define
define|#
directive|define
name|LE_DEF
value|0x0400
end_define

begin_define
define|#
directive|define
name|LE_TBUFF
value|0x8000
end_define

begin_define
define|#
directive|define
name|LE_UFLO
value|0x4000
end_define

begin_define
define|#
directive|define
name|LE_LCOL
value|0x1000
end_define

begin_define
define|#
directive|define
name|LE_LCAR
value|0x0800
end_define

begin_define
define|#
directive|define
name|LE_RTRY
value|0x0400
end_define

end_unit

