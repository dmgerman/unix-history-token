begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1988 Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Chris Torek.  *  * Redistribution and use in source and binary forms are permitted  * provided that the above copyright notice and this paragraph are  * duplicated in all such forms and that any documentation,  * advertising materials, and other materials related to such  * distribution and use acknowledge that the software was developed  * by the University of California, Berkeley.  The name of the  * University may not be used to endorse or promote products derived  * from this software without specific prior written permission.  * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED  * WARRANTIES OF MERCHANTIBILITY AND FITNESS FOR A PARTICULAR PURPOSE.  *  *	@(#)bireg.h	7.2 (Berkeley) 7/9/88  */
end_comment

begin_comment
comment|/*  * VAXBI node definitions.  */
end_comment

begin_comment
comment|/*  * BI node addresses  */
end_comment

begin_define
define|#
directive|define
name|BI_BASE
parameter_list|(
name|bi
parameter_list|)
value|((struct bi_node *) (0x20000000 + (bi)*0x2000000))
end_define

begin_define
define|#
directive|define
name|NNODEBI
value|16
end_define

begin_comment
comment|/* 16 nodes per BI */
end_comment

begin_comment
comment|/*	`local space'	0x20800000	/* ??? */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|LOCORE
end_ifndef

begin_comment
comment|/*  * BI nodes all start with BI interface registers (those on the BIIC chip).  * These are followed with interface-specific registers.  *  * NB: This structure does NOT include the four GPRs (not anymore!)  */
end_comment

begin_struct
struct|struct
name|biiregs
block|{
name|u_short
name|bi_dtype
decl_stmt|;
comment|/* device type */
name|u_short
name|bi_revs
decl_stmt|;
comment|/* revisions */
name|u_long
name|bi_csr
decl_stmt|;
comment|/* control and status register */
name|u_long
name|bi_ber
decl_stmt|;
comment|/* bus error register */
name|u_long
name|bi_eintrcsr
decl_stmt|;
comment|/* error interrupt control register */
name|u_long
name|bi_intrdes
decl_stmt|;
comment|/* interrupt destination register */
comment|/* the rest are not required for all nodes */
name|u_long
name|bi_ipintrmsk
decl_stmt|;
comment|/* IP interrupt mask register */
name|u_long
name|bi_fipsdes
decl_stmt|;
comment|/* Force-Bit IPINTR/STOP destination reg */
name|u_long
name|bi_ipintrsrc
decl_stmt|;
comment|/* IPINTR source register */
name|u_long
name|bi_sadr
decl_stmt|;
comment|/* starting address register */
name|u_long
name|bi_eadr
decl_stmt|;
comment|/* ending address register */
name|u_long
name|bi_bcicsr
decl_stmt|;
comment|/* BCI control and status register */
name|u_long
name|bi_wstat
decl_stmt|;
comment|/* write status register */
name|u_long
name|bi_fipscmd
decl_stmt|;
comment|/* Force-Bit IPINTR/STOP command reg */
name|u_long
name|bi_xxx1
index|[
literal|3
index|]
decl_stmt|;
comment|/* unused */
name|u_long
name|bi_uintrcsr
decl_stmt|;
comment|/* user interface interrupt control reg */
name|u_long
name|bi_xxx2
index|[
literal|43
index|]
decl_stmt|;
comment|/* unused */
comment|/* although these are on the BIIC, their interpretation varies */
comment|/*	u_long	bi_gpr[4];	/* general purpose registers */
block|}
struct|;
end_struct

begin_comment
comment|/*  * A generic BI node.  */
end_comment

begin_struct
struct|struct
name|bi_node
block|{
name|struct
name|biiregs
name|biic
decl_stmt|;
comment|/* interface */
name|u_long
name|bi_xxx
index|[
literal|1988
index|]
decl_stmt|;
comment|/* pad to 8K */
block|}
struct|;
end_struct

begin_comment
comment|/*  * A cpu node.  */
end_comment

begin_struct
struct|struct
name|bi_cpu
block|{
name|struct
name|biiregs
name|biic
decl_stmt|;
comment|/* interface chip */
name|u_long
name|bi_gpr
index|[
literal|4
index|]
decl_stmt|;
comment|/* gprs (unused) */
name|u_long
name|bi_sosr
decl_stmt|;
comment|/* slave only status register */
name|u_long
name|bi_xxx
index|[
literal|63
index|]
decl_stmt|;
comment|/* pad */
name|u_long
name|bi_rxcd
decl_stmt|;
comment|/* receive console data register */
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
endif|LOCORE
end_endif

begin_comment
comment|/* device types */
end_comment

begin_define
define|#
directive|define
name|BIDT_MS820
value|0x0001
end_define

begin_comment
comment|/* MS820 memory board */
end_comment

begin_define
define|#
directive|define
name|BIDT_DWBUA
value|0x0102
end_define

begin_comment
comment|/* DWBUA Unibus adapter */
end_comment

begin_define
define|#
directive|define
name|BIDT_KLESI
value|0x0103
end_define

begin_comment
comment|/* KLESI-B adapter */
end_comment

begin_define
define|#
directive|define
name|BIDT_KA820
value|0x0105
end_define

begin_comment
comment|/* KA820 cpu */
end_comment

begin_define
define|#
directive|define
name|BIDT_DB88
value|0x0106
end_define

begin_comment
comment|/* DB88 adapter */
end_comment

begin_define
define|#
directive|define
name|BIDT_DMB32
value|0x0109
end_define

begin_comment
comment|/* DMB32 adapter */
end_comment

begin_define
define|#
directive|define
name|BIDT_KDB50
value|0x010e
end_define

begin_comment
comment|/* KDB50 disk controller */
end_comment

begin_define
define|#
directive|define
name|BIDT_DEBNK
value|0x410e
end_define

begin_comment
comment|/* BI Ethernet (Lance) + TK50 */
end_comment

begin_define
define|#
directive|define
name|BIDT_DEBNA
value|0x410f
end_define

begin_comment
comment|/* BI Ethernet (Lance) adapter */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|notdef
end_ifdef

begin_comment
comment|/* CPU (KA820) bits in bi_revs */
end_comment

begin_define
define|#
directive|define
name|BI_CPUREV
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 11))
end_define

begin_comment
comment|/* CPU revision code */
end_comment

begin_define
define|#
directive|define
name|BI_UPATCHREV
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 1)& 0x3ff)
end_define

begin_comment
comment|/* microcode patch rev */
end_comment

begin_define
define|#
directive|define
name|BI_SPATCHREV
parameter_list|(
name|x
parameter_list|)
value|(((x)& 1)
end_define

begin_comment
comment|/* secondary patch rev */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* bits in bi_csr */
end_comment

begin_define
define|#
directive|define
name|BICSR_IREV
parameter_list|(
name|x
parameter_list|)
value|((u_char)((x)>> 24))
end_define

begin_comment
comment|/* VAXBI interface rev */
end_comment

begin_define
define|#
directive|define
name|BICSR_TYPE
parameter_list|(
name|x
parameter_list|)
value|((u_char)((x)>> 16))
end_define

begin_comment
comment|/* BIIC type */
end_comment

begin_define
define|#
directive|define
name|BICSR_HES
value|0x8000
end_define

begin_comment
comment|/* hard error summary */
end_comment

begin_define
define|#
directive|define
name|BICSR_SES
value|0x4000
end_define

begin_comment
comment|/* soft error summary */
end_comment

begin_define
define|#
directive|define
name|BICSR_INIT
value|0x2000
end_define

begin_comment
comment|/* initialise node */
end_comment

begin_define
define|#
directive|define
name|BICSR_BROKE
value|0x1000
end_define

begin_comment
comment|/* broke */
end_comment

begin_define
define|#
directive|define
name|BICSR_STS
value|0x0800
end_define

begin_comment
comment|/* self test status */
end_comment

begin_define
define|#
directive|define
name|BICSR_NRST
value|0x0400
end_define

begin_comment
comment|/* node reset */
end_comment

begin_define
define|#
directive|define
name|BICSR_UWP
value|0x0100
end_define

begin_comment
comment|/* unlock write pending */
end_comment

begin_define
define|#
directive|define
name|BICSR_HEIE
value|0x0080
end_define

begin_comment
comment|/* hard error interrupt enable */
end_comment

begin_define
define|#
directive|define
name|BICSR_SEIE
value|0x0040
end_define

begin_comment
comment|/* soft error interrupt enable */
end_comment

begin_define
define|#
directive|define
name|BICSR_ARB_MASK
value|0x0030
end_define

begin_comment
comment|/* mask to get arbitration codes */
end_comment

begin_define
define|#
directive|define
name|BICSR_ARB_NONE
value|0x0030
end_define

begin_comment
comment|/* no arbitration */
end_comment

begin_define
define|#
directive|define
name|BICSR_ARB_LOG
value|0x0020
end_define

begin_comment
comment|/* low priority */
end_comment

begin_define
define|#
directive|define
name|BICSR_ARB_HIGH
value|0x0010
end_define

begin_comment
comment|/* high priority */
end_comment

begin_define
define|#
directive|define
name|BICSR_ARB_RR
value|0x0000
end_define

begin_comment
comment|/* round robin */
end_comment

begin_define
define|#
directive|define
name|BICSR_NODEMASK
value|0x000f
end_define

begin_comment
comment|/* node ID */
end_comment

begin_define
define|#
directive|define
name|BICSR_BITS
define|\
value|"\20\20HES\17SES\16INIT\15BROKE\14STS\13NRST\11UWP\10HEIE\7SEIE"
end_define

begin_comment
comment|/* bits in bi_ber */
end_comment

begin_define
define|#
directive|define
name|BIBER_MBZ
value|0x8000fff0
end_define

begin_define
define|#
directive|define
name|BIBER_NMR
value|0x40000000
end_define

begin_comment
comment|/* no ack to multi-responder command */
end_comment

begin_define
define|#
directive|define
name|BIBER_MTCE
value|0x20000000
end_define

begin_comment
comment|/* master transmit check error */
end_comment

begin_define
define|#
directive|define
name|BIBER_CTE
value|0x10000000
end_define

begin_comment
comment|/* control transmit error */
end_comment

begin_define
define|#
directive|define
name|BIBER_MPE
value|0x08000000
end_define

begin_comment
comment|/* master parity error */
end_comment

begin_define
define|#
directive|define
name|BIBER_ISE
value|0x04000000
end_define

begin_comment
comment|/* interlock sequence error */
end_comment

begin_define
define|#
directive|define
name|BIBER_TDF
value|0x02000000
end_define

begin_comment
comment|/* transmitter during fault */
end_comment

begin_define
define|#
directive|define
name|BIBER_IVE
value|0x01000000
end_define

begin_comment
comment|/* ident vector error */
end_comment

begin_define
define|#
directive|define
name|BIBER_CPE
value|0x00800000
end_define

begin_comment
comment|/* command parity error */
end_comment

begin_define
define|#
directive|define
name|BIBER_SPE
value|0x00400000
end_define

begin_comment
comment|/* slave parity error */
end_comment

begin_define
define|#
directive|define
name|BIBER_RDS
value|0x00200000
end_define

begin_comment
comment|/* read data substitute */
end_comment

begin_define
define|#
directive|define
name|BIBER_RTO
value|0x00100000
end_define

begin_comment
comment|/* retry timeout */
end_comment

begin_define
define|#
directive|define
name|BIBER_STO
value|0x00080000
end_define

begin_comment
comment|/* stall timeout */
end_comment

begin_define
define|#
directive|define
name|BIBER_BTO
value|0x00040000
end_define

begin_comment
comment|/* bus timeout */
end_comment

begin_define
define|#
directive|define
name|BIBER_NEX
value|0x00020000
end_define

begin_comment
comment|/* nonexistent address */
end_comment

begin_define
define|#
directive|define
name|BIBER_ICE
value|0x00010000
end_define

begin_comment
comment|/* illegal confirmation error */
end_comment

begin_define
define|#
directive|define
name|BIBER_UPEN
value|0x00000008
end_define

begin_comment
comment|/* user parity enable */
end_comment

begin_define
define|#
directive|define
name|BIBER_IPE
value|0x00000004
end_define

begin_comment
comment|/* ID parity error */
end_comment

begin_define
define|#
directive|define
name|BIBER_CRD
value|0x00000002
end_define

begin_comment
comment|/* corrected read data */
end_comment

begin_define
define|#
directive|define
name|BIBER_NPE
value|0x00000001
end_define

begin_comment
comment|/* null bus parity error */
end_comment

begin_define
define|#
directive|define
name|BIBER_HARD
value|0x4fff0000
end_define

begin_define
define|#
directive|define
name|BIBER_BITS
define|\
value|"\20\37NMR\36MTCE\35CTE\34MPE\33ISE\32TDF\31IVE\30CPE\ \27SPE\26RDS\25RTO\24STO\23BTO\22NEX\21ICE\4UPEN\3IPE\2CRD\1NPE"
end_define

begin_comment
comment|/* bits in bi_eintrcsr */
end_comment

begin_define
define|#
directive|define
name|BIEIC_INTRAB
value|0x01000000
end_define

begin_comment
comment|/* interrupt abort */
end_comment

begin_define
define|#
directive|define
name|BIEIC_INTRC
value|0x00800000
end_define

begin_comment
comment|/* interrupt complete */
end_comment

begin_define
define|#
directive|define
name|BIEIC_INTRSENT
value|0x00200000
end_define

begin_comment
comment|/* interrupt command sent */
end_comment

begin_define
define|#
directive|define
name|BIEIC_INTRFORCE
value|0x00100000
end_define

begin_comment
comment|/* interrupt force */
end_comment

begin_define
define|#
directive|define
name|BIEIC_LEVELMASK
value|0x000f0000
end_define

begin_comment
comment|/* mask for interrupt levels */
end_comment

begin_define
define|#
directive|define
name|BIEIC_IPL17
value|0x00080000
end_define

begin_comment
comment|/* ipl 0x17 */
end_comment

begin_define
define|#
directive|define
name|BIEIC_IPL16
value|0x00040000
end_define

begin_comment
comment|/* ipl 0x16 */
end_comment

begin_define
define|#
directive|define
name|BIEIC_IPL15
value|0x00020000
end_define

begin_comment
comment|/* ipl 0x15 */
end_comment

begin_define
define|#
directive|define
name|BIEIC_IPL14
value|0x00010000
end_define

begin_comment
comment|/* ipl 0x14 */
end_comment

begin_define
define|#
directive|define
name|BIEIC_VECMASK
value|0x00003ffc
end_define

begin_comment
comment|/* vector mask for error intr */
end_comment

begin_comment
comment|/* bits in bi_intrdes */
end_comment

begin_define
define|#
directive|define
name|BIDEST_MASK
value|0x0000ffff
end_define

begin_comment
comment|/* one bit per node to be intr'ed */
end_comment

begin_comment
comment|/* bits in bi_ipintrmsk */
end_comment

begin_define
define|#
directive|define
name|BIIPINTR_MASK
value|0xffff0000
end_define

begin_comment
comment|/* one per node to allow to ipintr */
end_comment

begin_comment
comment|/* bits in bi_fipsdes */
end_comment

begin_define
define|#
directive|define
name|BIFIPSD_MASK
value|0x0000ffff
end_define

begin_comment
comment|/* bits in bi_ipintrsrc */
end_comment

begin_define
define|#
directive|define
name|BIIPSRC_MASK
value|0xffff0000
end_define

begin_comment
comment|/* sadr and eadr are simple addresses */
end_comment

begin_comment
comment|/* bits in bi_bcicsr */
end_comment

begin_define
define|#
directive|define
name|BCI_BURSTEN
value|0x00020000
end_define

begin_comment
comment|/* burst mode enable */
end_comment

begin_define
define|#
directive|define
name|BCI_IPSTOP_FRC
value|0x00010000
end_define

begin_comment
comment|/* ipintr/stop force */
end_comment

begin_define
define|#
directive|define
name|BCI_MCASTEN
value|0x00008000
end_define

begin_comment
comment|/* multicast space enable */
end_comment

begin_define
define|#
directive|define
name|BCI_BCASTEN
value|0x00004000
end_define

begin_comment
comment|/* broadcast enable */
end_comment

begin_define
define|#
directive|define
name|BCI_STOPEN
value|0x00002000
end_define

begin_comment
comment|/* stop enable */
end_comment

begin_define
define|#
directive|define
name|BCI_RSRVDEN
value|0x00001000
end_define

begin_comment
comment|/* reserved enable */
end_comment

begin_define
define|#
directive|define
name|BCI_IDENTEN
value|0x00000800
end_define

begin_comment
comment|/* ident enable */
end_comment

begin_define
define|#
directive|define
name|BCI_INVALEN
value|0x00000400
end_define

begin_comment
comment|/* inval enable */
end_comment

begin_define
define|#
directive|define
name|BCI_WINVEN
value|0x00000200
end_define

begin_comment
comment|/* write invalidate enable */
end_comment

begin_define
define|#
directive|define
name|BCI_UINTEN
value|0x00000100
end_define

begin_comment
comment|/* user interface csr space enable */
end_comment

begin_define
define|#
directive|define
name|BCI_BIICEN
value|0x00000080
end_define

begin_comment
comment|/* BIIC csr space enable */
end_comment

begin_define
define|#
directive|define
name|BCI_INTEN
value|0x00000040
end_define

begin_comment
comment|/* interrupt enable */
end_comment

begin_define
define|#
directive|define
name|BCI_IPINTEN
value|0x00000020
end_define

begin_comment
comment|/* ipintr enable */
end_comment

begin_define
define|#
directive|define
name|BCI_PIPEEN
value|0x00000010
end_define

begin_comment
comment|/* pipeline NXT enable */
end_comment

begin_define
define|#
directive|define
name|BCI_RTOEVEN
value|0x00000008
end_define

begin_comment
comment|/* read timeout EV enable */
end_comment

begin_define
define|#
directive|define
name|BCI_BITS
define|\
value|"\20\22BURSTEN\21IPSTOP_FRC\20MCASTEN\ \17BCASTEN\16STOPEN\15RSRVDEN\14IDENTEN\13INVALEN\12WINVEN\11UINTEN\ \10BIICEN\7INTEN\6IPINTEN\5PIPEEN\4RTOEVEN"
end_define

begin_comment
comment|/* bits in bi_wstat */
end_comment

begin_define
define|#
directive|define
name|BIW_GPR3
value|0x80000000
end_define

begin_comment
comment|/* gpr 3 was written */
end_comment

begin_define
define|#
directive|define
name|BIW_GPR2
value|0x40000000
end_define

begin_comment
comment|/* gpr 2 was written */
end_comment

begin_define
define|#
directive|define
name|BIW_GPR1
value|0x20000000
end_define

begin_comment
comment|/* gpr 1 was written */
end_comment

begin_define
define|#
directive|define
name|BIW_GPR0
value|0x10000000
end_define

begin_comment
comment|/* gpr 0 was written */
end_comment

begin_comment
comment|/* bits in force-bit ipintr/stop command register 8/ #define	BIFIPSC_CMDMASK	0x0000f000	/* command */
end_comment

begin_define
define|#
directive|define
name|BIFIPSC_MIDEN
value|0x00000800
end_define

begin_comment
comment|/* master ID enable */
end_comment

begin_comment
comment|/* bits in bi_uintcsr */
end_comment

begin_define
define|#
directive|define
name|BIUI_INTAB
value|0xf0000000
end_define

begin_comment
comment|/* interrupt abort level */
end_comment

begin_define
define|#
directive|define
name|BIUI_INTC
value|0x0f000000
end_define

begin_comment
comment|/* interrupt complete bits */
end_comment

begin_define
define|#
directive|define
name|BIUI_SENT
value|0x00f00000
end_define

begin_comment
comment|/* interrupt sent bits */
end_comment

begin_define
define|#
directive|define
name|BIUI_FORCE
value|0x000f0000
end_define

begin_comment
comment|/* force interrupt level */
end_comment

begin_define
define|#
directive|define
name|BIUI_EVECEN
value|0x00008000
end_define

begin_comment
comment|/* external vector enable */
end_comment

begin_define
define|#
directive|define
name|BIUI_VEC
value|0x00003ffc
end_define

begin_comment
comment|/* interrupt vector */
end_comment

begin_comment
comment|/* tell if a bi device is a slave (hence has SOSR) */
end_comment

begin_define
define|#
directive|define
name|BIDT_ISSLAVE
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x7f00) == 0)
end_define

begin_comment
comment|/* bits in bi_sosr */
end_comment

begin_define
define|#
directive|define
name|BISOSR_MEMSIZE
value|0x1ffc0000
end_define

begin_comment
comment|/* memory size */
end_comment

begin_define
define|#
directive|define
name|BISOSR_BROKE
value|0x00001000
end_define

begin_comment
comment|/* broke */
end_comment

begin_comment
comment|/* bits in bi_rxcd */
end_comment

begin_define
define|#
directive|define
name|BIRXCD_BUSY2
value|0x80000000
end_define

begin_comment
comment|/* busy 2 */
end_comment

begin_define
define|#
directive|define
name|BIRXCD_NODE2
value|0x0f000000
end_define

begin_comment
comment|/* node id 2 */
end_comment

begin_define
define|#
directive|define
name|BIRXCD_CHAR2
value|0x00ff0000
end_define

begin_comment
comment|/* character 2 */
end_comment

begin_define
define|#
directive|define
name|BIRXCD_BUSY1
value|0x00008000
end_define

begin_comment
comment|/* busy 1 */
end_comment

begin_define
define|#
directive|define
name|BIRXCD_NODE1
value|0x00000f00
end_define

begin_comment
comment|/* node id 1 */
end_comment

begin_define
define|#
directive|define
name|BIRXCD_CHAR1
value|0x000000ff
end_define

begin_comment
comment|/* character 1 */
end_comment

end_unit

