begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1982, 1986  *	The Regents of the University of California.  All rights reserved.  * (c) UNIX System Laboratories, Inc.  * All or some portions of this file are derived from material licensed  * to the University of California by American Telephone and Telegraph  * Co. or Unix System Laboratories, Inc. and are reproduced herein with  * the permission of UNIX System Laboratories, Inc.  *  * %sccs.include.redist.c%  *  *	@(#)ubareg.h	7.9 (Berkeley) %G%  */
end_comment

begin_comment
comment|/*  * VAX UNIBUS adapter registers  */
end_comment

begin_comment
comment|/*  * "UNIBUS" adaptor types.  * This code is used for both UNIBUSes and Q-buses  * with different types of adaptors.  * Definition of a type includes support code for that type.  */
end_comment

begin_if
if|#
directive|if
name|VAX780
operator|||
name|VAX8600
end_if

begin_define
define|#
directive|define
name|DW780
value|1
end_define

begin_comment
comment|/* has adaptor regs, sr: 780/785/8600 */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|VAX750
end_if

begin_define
define|#
directive|define
name|DW750
value|2
end_define

begin_comment
comment|/* has adaptor regs, no sr: 750, 730 */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|VAX730
end_if

begin_define
define|#
directive|define
name|DW730
value|3
end_define

begin_comment
comment|/* has adaptor regs, no sr: 750, 730 */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|VAX630
operator|||
name|VAX650
end_if

begin_define
define|#
directive|define
name|QBA
value|4
end_define

begin_comment
comment|/* 22-bit Q-bus, no adaptor regs: uVAX II */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|VAX8200
operator|||
name|VAX8500
operator|||
name|VAX8800
end_if

begin_define
define|#
directive|define
name|DWBUA
value|5
end_define

begin_comment
comment|/* BI UNIBUS adaptor: 8200/8500/8800 */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Size of unibus memory address space in pages  * (also number of map registers).  * QBAPAGES should be 8192, but we don't need nearly that much  * address space, and the return from the allocation routine  * can accommodate at most 2047 (ubavar.h: UBA_MAXMR);  * QBAPAGES must be at least UBAPAGES.  Choose pragmatically.  */
end_comment

begin_define
define|#
directive|define
name|UBAPAGES
value|496
end_define

begin_define
define|#
directive|define
name|NUBMREG
value|496
end_define

begin_if
if|#
directive|if
name|defined
argument_list|(
name|GATEWAY
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|QNIVERT
argument_list|)
end_if

begin_define
define|#
directive|define
name|QBAPAGES
value|1024
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|QBAPAGES
value|UBAPAGES
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|UBAIOADDR
value|0760000
end_define

begin_comment
comment|/* start of I/O page */
end_comment

begin_define
define|#
directive|define
name|UBAIOPAGES
value|16
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|LOCORE
end_ifndef

begin_comment
comment|/*  * DWBUA hardware registers.  */
end_comment

begin_struct
struct|struct
name|dwbua_regs
block|{
name|int
name|pad1
index|[
literal|456
index|]
decl_stmt|;
comment|/* actually bii regs + pad */
name|int
name|bua_csr
decl_stmt|;
comment|/* control and status register */
name|int
name|bua_offset
decl_stmt|;
comment|/* vector offset register */
name|int
name|bua_fubar
decl_stmt|;
comment|/* failed UNIBUS address register */
name|int
name|bua_bifar
decl_stmt|;
comment|/* BI failed address register */
name|int
name|bua_udiag
index|[
literal|5
index|]
decl_stmt|;
comment|/* micro diagnostics (R/O) */
name|int
name|pad2
index|[
literal|3
index|]
decl_stmt|;
comment|/* dpr[0] is for DDP; dpr's 1 through 5 are for BPD's 1 through 5 */
name|int
name|bua_dpr
index|[
literal|6
index|]
decl_stmt|;
comment|/* data path registers */
name|int
name|pad3
index|[
literal|10
index|]
decl_stmt|;
name|int
name|bua_bdps
index|[
literal|20
index|]
decl_stmt|;
comment|/* buffered data path space */
comment|/*???*/
name|int
name|pad4
index|[
literal|8
index|]
decl_stmt|;
name|struct
name|pte
name|bua_map
index|[
name|UBAPAGES
index|]
decl_stmt|;
comment|/* unibus map registers */
name|int
name|pad5
index|[
name|UBAIOPAGES
index|]
decl_stmt|;
comment|/* no maps for device address space */
block|}
struct|;
end_struct

begin_ifdef
ifdef|#
directive|ifdef
name|DWBUA
end_ifdef

begin_comment
comment|/* bua_csr */
end_comment

begin_define
define|#
directive|define
name|BUACSR_ERR
value|0x80000000
end_define

begin_comment
comment|/* composite error */
end_comment

begin_define
define|#
directive|define
name|BUACSR_BIF
value|0x10000000
end_define

begin_comment
comment|/* BI failure */
end_comment

begin_define
define|#
directive|define
name|BUACSR_SSYNTO
value|0x08000000
end_define

begin_comment
comment|/* slave sync timeout */
end_comment

begin_define
define|#
directive|define
name|BUACSR_UIE
value|0x04000000
end_define

begin_comment
comment|/* unibus interlock error */
end_comment

begin_define
define|#
directive|define
name|BUACSR_IVMR
value|0x02000000
end_define

begin_comment
comment|/* invalid map register */
end_comment

begin_define
define|#
directive|define
name|BUACSR_BADBDP
value|0x01000000
end_define

begin_comment
comment|/* bad BDP select */
end_comment

begin_define
define|#
directive|define
name|BUACSR_BUAEIE
value|0x00100000
end_define

begin_comment
comment|/* bua error interrupt enable (?) */
end_comment

begin_define
define|#
directive|define
name|BUACSR_UPI
value|0x00020000
end_define

begin_comment
comment|/* unibus power init */
end_comment

begin_define
define|#
directive|define
name|BUACSR_UREGDUMP
value|0x00010000
end_define

begin_comment
comment|/* microdiag register dump */
end_comment

begin_define
define|#
directive|define
name|BUACSR_IERRNO
value|0x000000ff
end_define

begin_comment
comment|/* mask for internal errror number */
end_comment

begin_comment
comment|/* bua_offset */
end_comment

begin_define
define|#
directive|define
name|BUAOFFSET_MASK
value|0x00003e00
end_define

begin_comment
comment|/* hence max offset = 15872 */
end_comment

begin_comment
comment|/* bua_dpr */
end_comment

begin_define
define|#
directive|define
name|BUADPR_DPSEL
value|0x00e00000
end_define

begin_comment
comment|/* data path select (?) */
end_comment

begin_define
define|#
directive|define
name|BUADPR_PURGE
value|0x00000001
end_define

begin_comment
comment|/* purge bdp */
end_comment

begin_comment
comment|/* bua_map -- in particular, those bits that are not in DW780s& DW750s */
end_comment

begin_define
define|#
directive|define
name|BUAMR_IOADR
value|0x40000000
end_define

begin_comment
comment|/* I/O address space */
end_comment

begin_define
define|#
directive|define
name|BUAMR_LAE
value|0x04000000
end_define

begin_comment
comment|/* longword access enable */
end_comment

begin_comment
comment|/* I see no reason to use either one, though ... act 6 Aug 1987 */
end_comment

begin_define
define|#
directive|define
name|UBA_PURGEBUA
parameter_list|(
name|uba
parameter_list|,
name|bdp
parameter_list|)
define|\
value|(((struct dwbua_regs *)(uba))->bua_dpr[bdp] |= BUADPR_PURGE)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|UBA_PURGEBUA
parameter_list|(
name|uba
parameter_list|,
name|bdp
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * DW780/DW750 hardware registers  */
end_comment

begin_struct
struct|struct
name|uba_regs
block|{
name|int
name|uba_cnfgr
decl_stmt|;
comment|/* configuration register */
name|int
name|uba_cr
decl_stmt|;
comment|/* control register */
name|int
name|uba_sr
decl_stmt|;
comment|/* status register */
name|int
name|uba_dcr
decl_stmt|;
comment|/* diagnostic control register */
name|int
name|uba_fmer
decl_stmt|;
comment|/* failed map entry register */
name|int
name|uba_fubar
decl_stmt|;
comment|/* failed UNIBUS address register */
name|int
name|pad1
index|[
literal|2
index|]
decl_stmt|;
name|int
name|uba_brsvr
index|[
literal|4
index|]
decl_stmt|;
name|int
name|uba_brrvr
index|[
literal|4
index|]
decl_stmt|;
comment|/* receive vector registers */
name|int
name|uba_dpr
index|[
literal|16
index|]
decl_stmt|;
comment|/* buffered data path register */
name|int
name|pad2
index|[
literal|480
index|]
decl_stmt|;
name|struct
name|pte
name|uba_map
index|[
name|UBAPAGES
index|]
decl_stmt|;
comment|/* unibus map register */
name|int
name|pad3
index|[
name|UBAIOPAGES
index|]
decl_stmt|;
comment|/* no maps for device address space */
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|DW780
end_ifdef

begin_comment
comment|/* uba_cnfgr */
end_comment

begin_define
define|#
directive|define
name|UBACNFGR_UBINIT
value|0x00040000
end_define

begin_comment
comment|/* unibus init asserted */
end_comment

begin_define
define|#
directive|define
name|UBACNFGR_UBPDN
value|0x00020000
end_define

begin_comment
comment|/* unibus power down */
end_comment

begin_define
define|#
directive|define
name|UBACNFGR_UBIC
value|0x00010000
end_define

begin_comment
comment|/* unibus init complete */
end_comment

begin_define
define|#
directive|define
name|UBACNFGR_BITS
define|\
value|"\40\40PARFLT\37WSQFLT\36URDFLT\35ISQFLT\34MXTFLT\33XMTFLT\30ADPDN\27ADPUP\23UBINIT\22UBPDN\21UBIC"
end_define

begin_comment
comment|/* uba_cr */
end_comment

begin_define
define|#
directive|define
name|UBACR_MRD16
value|0x40000000
end_define

begin_comment
comment|/* map reg disable bit 4 */
end_comment

begin_define
define|#
directive|define
name|UBACR_MRD8
value|0x20000000
end_define

begin_comment
comment|/* map reg disable bit 3 */
end_comment

begin_define
define|#
directive|define
name|UBACR_MRD4
value|0x10000000
end_define

begin_comment
comment|/* map reg disable bit 2 */
end_comment

begin_define
define|#
directive|define
name|UBACR_MRD2
value|0x08000000
end_define

begin_comment
comment|/* map reg disable bit 1 */
end_comment

begin_define
define|#
directive|define
name|UBACR_MRD1
value|0x04000000
end_define

begin_comment
comment|/* map reg disable bit 0 */
end_comment

begin_define
define|#
directive|define
name|UBACR_IFS
value|0x00000040
end_define

begin_comment
comment|/* interrupt field switch */
end_comment

begin_define
define|#
directive|define
name|UBACR_BRIE
value|0x00000020
end_define

begin_comment
comment|/* BR interrupt enable */
end_comment

begin_define
define|#
directive|define
name|UBACR_USEFIE
value|0x00000010
end_define

begin_comment
comment|/* UNIBUS to SBI error field IE */
end_comment

begin_define
define|#
directive|define
name|UBACR_SUEFIE
value|0x00000008
end_define

begin_comment
comment|/* SBI to UNIBUS error field IE */
end_comment

begin_define
define|#
directive|define
name|UBACR_CNFIE
value|0x00000004
end_define

begin_comment
comment|/* configuration IE */
end_comment

begin_define
define|#
directive|define
name|UBACR_UPF
value|0x00000002
end_define

begin_comment
comment|/* UNIBUS power fail */
end_comment

begin_define
define|#
directive|define
name|UBACR_ADINIT
value|0x00000001
end_define

begin_comment
comment|/* adapter init */
end_comment

begin_comment
comment|/* uba_sr */
end_comment

begin_define
define|#
directive|define
name|UBASR_BR7FULL
value|0x08000000
end_define

begin_comment
comment|/* BR7 receive vector reg full */
end_comment

begin_define
define|#
directive|define
name|UBASR_BR6FULL
value|0x04000000
end_define

begin_comment
comment|/* BR6 receive vector reg full */
end_comment

begin_define
define|#
directive|define
name|UBASR_BR5FULL
value|0x02000000
end_define

begin_comment
comment|/* BR5 receive vector reg full */
end_comment

begin_define
define|#
directive|define
name|UBASR_BR4FULL
value|0x01000000
end_define

begin_comment
comment|/* BR4 receive vector reg full */
end_comment

begin_define
define|#
directive|define
name|UBASR_RDTO
value|0x00000400
end_define

begin_comment
comment|/* UNIBUS to SBI read data timeout */
end_comment

begin_define
define|#
directive|define
name|UBASR_RDS
value|0x00000200
end_define

begin_comment
comment|/* read data substitute */
end_comment

begin_define
define|#
directive|define
name|UBASR_CRD
value|0x00000100
end_define

begin_comment
comment|/* corrected read data */
end_comment

begin_define
define|#
directive|define
name|UBASR_CXTER
value|0x00000080
end_define

begin_comment
comment|/* command transmit error */
end_comment

begin_define
define|#
directive|define
name|UBASR_CXTMO
value|0x00000040
end_define

begin_comment
comment|/* command transmit timeout */
end_comment

begin_define
define|#
directive|define
name|UBASR_DPPE
value|0x00000020
end_define

begin_comment
comment|/* data path parity error */
end_comment

begin_define
define|#
directive|define
name|UBASR_IVMR
value|0x00000010
end_define

begin_comment
comment|/* invalid map register */
end_comment

begin_define
define|#
directive|define
name|UBASR_MRPF
value|0x00000008
end_define

begin_comment
comment|/* map register parity failure */
end_comment

begin_define
define|#
directive|define
name|UBASR_LEB
value|0x00000004
end_define

begin_comment
comment|/* lost error */
end_comment

begin_define
define|#
directive|define
name|UBASR_UBSTO
value|0x00000002
end_define

begin_comment
comment|/* UNIBUS select timeout */
end_comment

begin_define
define|#
directive|define
name|UBASR_UBSSYNTO
value|0x00000001
end_define

begin_comment
comment|/* UNIBUS slave sync timeout */
end_comment

begin_define
define|#
directive|define
name|UBASR_BITS
define|\
value|"\20\13RDTO\12RDS\11CRD\10CXTER\7CXTMO\6DPPE\5IVMR\4MRPF\3LEB\2UBSTO\1UBSSYNTO"
end_define

begin_comment
comment|/* uba_brrvr[] */
end_comment

begin_define
define|#
directive|define
name|UBABRRVR_AIRI
value|0x80000000
end_define

begin_comment
comment|/* adapter interrupt request */
end_comment

begin_define
define|#
directive|define
name|UBABRRVR_DIV
value|0x0000ffff
end_define

begin_comment
comment|/* device interrupt vector field */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* uba_dpr */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|DW780
end_ifdef

begin_define
define|#
directive|define
name|UBADPR_BNE
value|0x80000000
end_define

begin_comment
comment|/* buffer not empty - purge */
end_comment

begin_define
define|#
directive|define
name|UBADPR_BTE
value|0x40000000
end_define

begin_comment
comment|/* buffer transfer error */
end_comment

begin_define
define|#
directive|define
name|UBADPR_DPF
value|0x20000000
end_define

begin_comment
comment|/* DP function (RO) */
end_comment

begin_define
define|#
directive|define
name|UBADPR_BS
value|0x007f0000
end_define

begin_comment
comment|/* buffer state field */
end_comment

begin_define
define|#
directive|define
name|UBADPR_BUBA
value|0x0000ffff
end_define

begin_comment
comment|/* buffered UNIBUS address */
end_comment

begin_define
define|#
directive|define
name|UBA_PURGE780
parameter_list|(
name|uba
parameter_list|,
name|bdp
parameter_list|)
define|\
value|((uba)->uba_dpr[bdp] |= UBADPR_BNE)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|UBA_PURGE780
parameter_list|(
name|uba
parameter_list|,
name|bdp
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|DW750
end_ifdef

begin_define
define|#
directive|define
name|UBADPR_ERROR
value|0x80000000
end_define

begin_comment
comment|/* error occurred */
end_comment

begin_define
define|#
directive|define
name|UBADPR_NXM
value|0x40000000
end_define

begin_comment
comment|/* nxm from memory */
end_comment

begin_define
define|#
directive|define
name|UBADPR_UCE
value|0x20000000
end_define

begin_comment
comment|/* uncorrectable error */
end_comment

begin_define
define|#
directive|define
name|UBADPR_PURGE
value|0x00000001
end_define

begin_comment
comment|/* purge bdp */
end_comment

begin_comment
comment|/* the DELAY is for a hardware problem */
end_comment

begin_define
define|#
directive|define
name|UBA_PURGE750
parameter_list|(
name|uba
parameter_list|,
name|bdp
parameter_list|)
value|{ \     ((uba)->uba_dpr[bdp] |= (UBADPR_PURGE|UBADPR_NXM|UBADPR_UCE)); \     DELAY(8); \ }
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|UBA_PURGE750
parameter_list|(
name|uba
parameter_list|,
name|bdp
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Macros for fast buffered data path purging in time-critical routines.  *  * Too bad C pre-processor doesn't have the power of LISP in macro  * expansion...  */
end_comment

begin_comment
comment|/* THIS IS WRONG, should use pointer to uba_hd */
end_comment

begin_if
if|#
directive|if
name|DWBUA
operator|||
name|DW780
operator|||
name|DW750
end_if

begin_define
define|#
directive|define
name|UBAPURGE
parameter_list|(
name|uba
parameter_list|,
name|bdp
parameter_list|)
value|{ \ 	switch (cpu) { \ 	case VAX_8200: UBA_PURGEBUA(uba, bdp); break; \ 	case VAX_8600: case VAX_780: UBA_PURGE780((uba), (bdp)); break; \ 	case VAX_750: UBA_PURGE750((uba), (bdp)); break; \ 	} \ }
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|UBAPURGE
parameter_list|(
name|uba
parameter_list|,
name|bdp
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* uba_mr[] */
end_comment

begin_define
define|#
directive|define
name|UBAMR_MRV
value|0x80000000
end_define

begin_comment
comment|/* map register valid */
end_comment

begin_define
define|#
directive|define
name|UBAMR_BO
value|0x02000000
end_define

begin_comment
comment|/* byte offset bit */
end_comment

begin_define
define|#
directive|define
name|UBAMR_DPDB
value|0x01e00000
end_define

begin_comment
comment|/* data path designator field */
end_comment

begin_define
define|#
directive|define
name|UBAMR_SBIPFN
value|0x001fffff
end_define

begin_comment
comment|/* SBI page address field */
end_comment

begin_define
define|#
directive|define
name|UBAMR_DPSHIFT
value|21
end_define

begin_comment
comment|/* shift to data path designator */
end_comment

begin_comment
comment|/*  * Number of unibus buffered data paths and possible uba's per cpu type.  */
end_comment

begin_define
define|#
directive|define
name|NBDP8600
value|15
end_define

begin_define
define|#
directive|define
name|NBDP780
value|15
end_define

begin_define
define|#
directive|define
name|NBDPBUA
value|5
end_define

begin_define
define|#
directive|define
name|NBDP750
value|3
end_define

begin_define
define|#
directive|define
name|NBDP730
value|0
end_define

begin_define
define|#
directive|define
name|MAXNBDP
value|15
end_define

begin_comment
comment|/*  * Symbolic BUS addresses for UBAs.  */
end_comment

begin_if
if|#
directive|if
name|VAX630
operator|||
name|VAX650
end_if

begin_define
define|#
directive|define
name|QBAMAP630
value|((struct pte *)0x20088000)
end_define

begin_define
define|#
directive|define
name|QMEM630
value|0x30000000
end_define

begin_define
define|#
directive|define
name|QIOPAGE630
value|0x20000000
end_define

begin_comment
comment|/*  * Q-bus control registers  */
end_comment

begin_define
define|#
directive|define
name|QIPCR
value|0x1f40
end_define

begin_comment
comment|/* from start of iopage */
end_comment

begin_comment
comment|/* bits in QIPCR */
end_comment

begin_define
define|#
directive|define
name|Q_DBIRQ
value|0x0001
end_define

begin_comment
comment|/* doorbell interrupt request */
end_comment

begin_define
define|#
directive|define
name|Q_LMEAE
value|0x0020
end_define

begin_comment
comment|/* local mem external access enable */
end_comment

begin_define
define|#
directive|define
name|Q_DBIIE
value|0x0040
end_define

begin_comment
comment|/* doorbell interrupt enable */
end_comment

begin_define
define|#
directive|define
name|Q_AUXHLT
value|0x0100
end_define

begin_comment
comment|/* auxiliary processor halt */
end_comment

begin_define
define|#
directive|define
name|Q_DMAQPE
value|0x8000
end_define

begin_comment
comment|/* Q22 bus address space parity error */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|VAX730
end_if

begin_define
define|#
directive|define
name|UMEM730
value|0xfc0000
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|VAX750
end_if

begin_define
define|#
directive|define
name|UMEM750
parameter_list|(
name|i
parameter_list|)
value|(0xfc0000-(i)*0x40000)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|VAX780
end_if

begin_define
define|#
directive|define
name|UMEM780
parameter_list|(
name|i
parameter_list|)
value|(0x20100000+(i)*0x40000)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|VAX8200
end_if

begin_comment
comment|/* BEWARE, argument is node, not ubanum */
end_comment

begin_define
define|#
directive|define
name|UMEM8200
parameter_list|(
name|i
parameter_list|)
value|(0x20400000+(i)*0x40000)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|VAX8600
end_if

begin_define
define|#
directive|define
name|UMEMA8600
parameter_list|(
name|i
parameter_list|)
value|(0x20100000+(i)*0x40000)
end_define

begin_define
define|#
directive|define
name|UMEMB8600
parameter_list|(
name|i
parameter_list|)
value|(0x22100000+(i)*0x40000)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Macro to offset a UNIBUS device address, often expressed as  * something like 0172520, by forcing it into the last 8K  * of UNIBUS memory space.  */
end_comment

begin_define
define|#
directive|define
name|ubdevreg
parameter_list|(
name|addr
parameter_list|)
value|((addr)& 017777)
end_define

end_unit

