begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	ubareg.h	4.22	81/04/03	*/
end_comment

begin_comment
comment|/*  * VAX UNIBUS adapter registers  */
end_comment

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
literal|496
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
name|VAX780
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
endif|VAX780
end_endif

begin_comment
comment|/* uba_dpr */
end_comment

begin_if
if|#
directive|if
name|VAX780
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

begin_endif
endif|#
directive|endif
endif|VAX780
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

begin_endif
endif|#
directive|endif
endif|VAX750
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
comment|/*  * Number of UNIBUS map registers.  We can't use the last 8k of UNIBUS  * address space for i/o transfers since it is used by the devices,  * hence have slightly less than 256K of UNIBUS address space.  */
end_comment

begin_define
define|#
directive|define
name|NUBMREG
value|496
end_define

begin_comment
comment|/*  * Number of unibus buffered data paths and possible uba's per cpu type.  */
end_comment

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
name|NBDP7ZZ
value|0
end_define

begin_define
define|#
directive|define
name|MAXNBDP
value|15
end_define

begin_define
define|#
directive|define
name|NUBA780
value|4
end_define

begin_define
define|#
directive|define
name|NUBA750
value|1
end_define

begin_define
define|#
directive|define
name|NUBA7ZZ
value|1
end_define

begin_if
if|#
directive|if
name|VAX780
end_if

begin_define
define|#
directive|define
name|MAXNUBA
value|4
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|MAXNUBA
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Formulas for locations of the last 8k of UNIBUS memory  * for each possible uba.  */
end_comment

begin_if
if|#
directive|if
name|VAX7ZZ
end_if

begin_define
define|#
directive|define
name|UMEM7ZZ
value|((u_short *)(0xffe000))
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
value|((u_short *)(0xffe000-(i)*0x40000))
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
value|((u_short *)(0x2013e000+(i)*0x40000))
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

