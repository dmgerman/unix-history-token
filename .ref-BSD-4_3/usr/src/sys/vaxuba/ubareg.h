begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1982, 1986 Regents of the University of California.  * All rights reserved.  The Berkeley software License Agreement  * specifies the terms and conditions for redistribution.  *  *	@(#)ubareg.h	7.1 (Berkeley) 6/5/86  */
end_comment

begin_comment
comment|/*  * VAX UNIBUS adapter registers  */
end_comment

begin_comment
comment|/*  * size of unibus address space in pages  */
end_comment

begin_define
define|#
directive|define
name|UBAPAGES
value|512
end_define

begin_comment
comment|/*  * Number of UNIBUS map registers.  We can't use the last 8k of UNIBUS  * address space for i/o transfers since it is used by the devices,  * hence have slightly less than 256K of UNIBUS address space.  */
end_comment

begin_define
define|#
directive|define
name|NUBMREG
value|496
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|LOCORE
end_ifndef

begin_comment
comment|/*  * UBA hardware registers  */
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
name|NUBMREG
index|]
decl_stmt|;
comment|/* unibus map register */
name|int
name|pad3
index|[
literal|16
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

begin_if
if|#
directive|if
name|defined
argument_list|(
name|VAX780
argument_list|)
operator|||
name|defined
argument_list|(
name|VAX8600
argument_list|)
end_if

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

begin_if
if|#
directive|if
name|defined
argument_list|(
name|VAX780
argument_list|)
operator|||
name|defined
argument_list|(
name|VAX8600
argument_list|)
end_if

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

begin_if
if|#
directive|if
name|VAX750
end_if

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

begin_if
if|#
directive|if
name|defined
argument_list|(
name|VAX8600
argument_list|)
operator|||
name|defined
argument_list|(
name|VAX780
argument_list|)
operator|||
name|defined
argument_list|(
name|VAX750
argument_list|)
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
value|{ \ 	switch (cpu) { \ 	case VAX_8600: case VAX_780: UBA_PURGE780((uba), (bdp)); break; \ 	case VAX_750: UBA_PURGE750((uba), (bdp)); break; \ 	} \ }
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|VAX8600
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|VAX780
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|VAX750
argument_list|)
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
value|0x000fffff
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
name|NBDP630
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
end_if

begin_define
define|#
directive|define
name|UMEM630
value|((u_short *)(0x1ffc2000))
end_define

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
value|((u_short *)(0xfc0000))
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
value|((u_short *)(0xfc0000-(i)*0x40000))
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
value|((u_short *)(0x20100000+(i)*0x40000))
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
value|((u_short *)(0x20100000+(i)*0x40000))
end_define

begin_define
define|#
directive|define
name|UMEMB8600
parameter_list|(
name|i
parameter_list|)
value|((u_short *)(0x22100000+(i)*0x40000))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Macro to offset a UNIBUS device address, often expressed as  * something like 0172520 by forcing it into the last 8K of UNIBUS memory  * space.  */
end_comment

begin_define
define|#
directive|define
name|ubdevreg
parameter_list|(
name|addr
parameter_list|)
value|(0760000|((addr)&017777))
end_define

end_unit

