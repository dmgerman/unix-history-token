begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	uba.h	4.1	11/9/80	*/
end_comment

begin_comment
comment|/*  * Unibus adapter  */
end_comment

begin_define
define|#
directive|define
name|UBA0
value|0x80060000
end_define

begin_comment
comment|/* sys virt i/o for UBA 0 */
end_comment

begin_define
define|#
directive|define
name|UBA0_DEV
value|(UBA0+0x2000-0160000)
end_define

begin_comment
comment|/* sys virt of device regs */
end_comment

begin_define
define|#
directive|define
name|UNIBASE
value|0760000
end_define

begin_comment
comment|/* UNIBUS phys base of i/o reg's */
end_comment

begin_comment
comment|/* UBA Configuration Register, CNFGR */
end_comment

begin_define
define|#
directive|define
name|PARFLT
value|0x80000000
end_define

begin_comment
comment|/* SBI Parity Fault */
end_comment

begin_define
define|#
directive|define
name|WSQFLT
value|0x40000000
end_define

begin_comment
comment|/* SBI Write Sequence Fault */
end_comment

begin_define
define|#
directive|define
name|URDFLT
value|0x20000000
end_define

begin_comment
comment|/* SBI Unexpected Read Fault */
end_comment

begin_define
define|#
directive|define
name|ISQFLT
value|0x10000000
end_define

begin_comment
comment|/* SBI Interlock Sequence Fault */
end_comment

begin_define
define|#
directive|define
name|MXTFLT
value|0x8000000
end_define

begin_comment
comment|/* SBI Multiple Transmitter Fault */
end_comment

begin_define
define|#
directive|define
name|XMTFLT
value|0x4000000
end_define

begin_comment
comment|/* UBA is transmit faulter */
end_comment

begin_define
define|#
directive|define
name|ADPDN
value|0x800000
end_define

begin_comment
comment|/* Adapter Power Down */
end_comment

begin_define
define|#
directive|define
name|ADPUP
value|0x400000
end_define

begin_comment
comment|/* Adapter Power Up */
end_comment

begin_define
define|#
directive|define
name|UBINIT
value|0x40000
end_define

begin_comment
comment|/* UNIBUS INIT is asserted */
end_comment

begin_define
define|#
directive|define
name|UBPDN
value|0x20000
end_define

begin_comment
comment|/* UNIBUS Power Down */
end_comment

begin_define
define|#
directive|define
name|UBIC
value|0x10000
end_define

begin_comment
comment|/* UNIBUS Initialization */
end_comment

begin_comment
comment|/* UNIBUS Ready */
end_comment

begin_define
define|#
directive|define
name|UBACOD
value|0xff
end_define

begin_comment
comment|/* UBA Code bits */
end_comment

begin_comment
comment|/* UBA Control Register, UBACR */
end_comment

begin_define
define|#
directive|define
name|MRD16
value|0x40000000
end_define

begin_comment
comment|/* Map Reg Disable Bit 4 */
end_comment

begin_define
define|#
directive|define
name|MRD8
value|0x20000000
end_define

begin_comment
comment|/* Map Reg Disable Bit 3 */
end_comment

begin_define
define|#
directive|define
name|MRD4
value|0x10000000
end_define

begin_comment
comment|/* Map Reg Disable Bit 2 */
end_comment

begin_define
define|#
directive|define
name|MRD2
value|0x8000000
end_define

begin_comment
comment|/* Map Reg Disable Bit 1 */
end_comment

begin_define
define|#
directive|define
name|MRD1
value|0x4000000
end_define

begin_comment
comment|/* Map Reg Disable Bit 0 */
end_comment

begin_define
define|#
directive|define
name|IFS
value|0x40
end_define

begin_comment
comment|/* Interrupt Field Switch */
end_comment

begin_define
define|#
directive|define
name|BRIE
value|0x20
end_define

begin_comment
comment|/* BR Interrupt Enable */
end_comment

begin_define
define|#
directive|define
name|USEFIE
value|0x10
end_define

begin_comment
comment|/* UNIBUS to SBI Error Field IE */
end_comment

begin_define
define|#
directive|define
name|SUEFIE
value|0x8
end_define

begin_comment
comment|/* SBI to UNIBUS Error Field IE */
end_comment

begin_define
define|#
directive|define
name|CNFIE
value|0x4
end_define

begin_comment
comment|/* Configuration IE */
end_comment

begin_define
define|#
directive|define
name|UPF
value|0x2
end_define

begin_comment
comment|/* UNIBUS Power Fail */
end_comment

begin_define
define|#
directive|define
name|ADINIT
value|0x1
end_define

begin_comment
comment|/* Adapter Init */
end_comment

begin_comment
comment|/* UBA Status Register, UASR */
end_comment

begin_define
define|#
directive|define
name|BR7FULL
value|0x8000000
end_define

begin_comment
comment|/* BR7 Receive Vector Rg Full */
end_comment

begin_define
define|#
directive|define
name|BR6FULL
value|0x4000000
end_define

begin_comment
comment|/* BR6 Receive Vector Reg Full */
end_comment

begin_define
define|#
directive|define
name|BR5FULL
value|0x2000000
end_define

begin_comment
comment|/* BR5 Receive Vector Reg Full */
end_comment

begin_define
define|#
directive|define
name|BR4FULL
value|0x1000000
end_define

begin_comment
comment|/* BR4 Receive Vector Reg Full */
end_comment

begin_define
define|#
directive|define
name|RDTO
value|0x400
end_define

begin_comment
comment|/* UNIBUS to SBI Read Data Timeout */
end_comment

begin_define
define|#
directive|define
name|RDS
value|0x200
end_define

begin_comment
comment|/* Read Data Substitute */
end_comment

begin_define
define|#
directive|define
name|CRD
value|0x100
end_define

begin_comment
comment|/* Corrected Read Data */
end_comment

begin_define
define|#
directive|define
name|CXTER
value|0x80
end_define

begin_comment
comment|/* Command Transmit Error */
end_comment

begin_define
define|#
directive|define
name|CXTMO
value|0x40
end_define

begin_comment
comment|/* Command Transmit Timeout */
end_comment

begin_define
define|#
directive|define
name|DPPE
value|0x20
end_define

begin_comment
comment|/* Data Path Parity Error */
end_comment

begin_define
define|#
directive|define
name|IVMR
value|0x10
end_define

begin_comment
comment|/* Invalid Map Register */
end_comment

begin_define
define|#
directive|define
name|MRPF
value|0x8
end_define

begin_comment
comment|/* Map Register Parity Failure */
end_comment

begin_define
define|#
directive|define
name|LEB
value|0x4
end_define

begin_comment
comment|/* Lost Error */
end_comment

begin_define
define|#
directive|define
name|UBSTO
value|0x2
end_define

begin_comment
comment|/* UNIBUS Select Timeout */
end_comment

begin_define
define|#
directive|define
name|UBSSTO
value|0x1
end_define

begin_comment
comment|/* UNIBUS Slave Sync Timeout */
end_comment

begin_comment
comment|/* Failed Map Entry Register, FMER */
end_comment

begin_define
define|#
directive|define
name|FMRN
value|0x1ff
end_define

begin_comment
comment|/* Failed Map Reg. No. Field */
end_comment

begin_comment
comment|/* Failed UNIBUS Address Register, FUBAR */
end_comment

begin_define
define|#
directive|define
name|FUA
value|0xffff
end_define

begin_comment
comment|/* Failed UNIBUS Address Field */
end_comment

begin_comment
comment|/* BR Receive Vector register, BRRVR */
end_comment

begin_define
define|#
directive|define
name|AIRI
value|0x80000000
end_define

begin_comment
comment|/* Adapter Interrupt Request */
end_comment

begin_define
define|#
directive|define
name|DIV
value|0xffff
end_define

begin_comment
comment|/* Device Interrupt Vector Field */
end_comment

begin_comment
comment|/* Data Path Register, DPR */
end_comment

begin_define
define|#
directive|define
name|BNE
value|0x80000000
end_define

begin_comment
comment|/* Buffer Not Empty - Purge */
end_comment

begin_define
define|#
directive|define
name|BTE
value|0x40000000
end_define

begin_comment
comment|/* Buffer Transfer Error */
end_comment

begin_define
define|#
directive|define
name|DPF
value|0x20000000
end_define

begin_comment
comment|/* DP Function (RO) */
end_comment

begin_define
define|#
directive|define
name|BS
value|0x7f0000
end_define

begin_comment
comment|/* Buffer State Field */
end_comment

begin_define
define|#
directive|define
name|BUBA
value|0xffff
end_define

begin_comment
comment|/* Buffered UNIBUS Address */
end_comment

begin_comment
comment|/* Map Register, MR */
end_comment

begin_define
define|#
directive|define
name|MRV
value|0x80000000
end_define

begin_comment
comment|/* Map Register Valid */
end_comment

begin_define
define|#
directive|define
name|BO
value|0x2000000
end_define

begin_comment
comment|/* Byte Offset Bit */
end_comment

begin_define
define|#
directive|define
name|DPDB
value|0x1e00000
end_define

begin_comment
comment|/* Data Path Designator Field */
end_comment

begin_define
define|#
directive|define
name|SBIPFN
value|0xfffff
end_define

begin_comment
comment|/* SBI Page Address Field */
end_comment

begin_comment
comment|/*  * Unibus maps  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|KERNEL
end_ifdef

begin_define
define|#
directive|define
name|UAMSIZ
value|50
end_define

begin_decl_stmt
name|struct
name|map
name|ubamap
index|[
name|UAMSIZ
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
name|bdpwant
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* someone is waiting for buffered data path */
end_comment

begin_decl_stmt
name|struct
name|map
name|bdpmap
index|[
literal|15
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
name|umrwant
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* ... for unibus map registers */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * UBA registers  */
end_comment

begin_struct
struct|struct
name|uba_regs
block|{
name|int
name|uba_cnfgr
decl_stmt|;
name|int
name|uba_cr
decl_stmt|;
name|int
name|uba_sr
decl_stmt|;
name|int
name|uba_dcr
decl_stmt|;
name|int
name|uba_fmer
decl_stmt|;
name|int
name|uba_fubar
decl_stmt|;
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
name|int
name|uba_dpr
index|[
literal|16
index|]
decl_stmt|;
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
block|}
struct|;
end_struct

begin_union
union|union
name|ub_info
block|{
struct|struct
name|ub_Info
block|{
name|unsigned
name|int
name|Ub_off
range|:
literal|18
decl_stmt|,
name|Ub_npf
range|:
literal|10
decl_stmt|,
name|Ub_bdp
range|:
literal|4
decl_stmt|;
block|}
name|ub_I
struct|;
name|int
name|ub_word
decl_stmt|;
block|}
union|;
end_union

begin_define
define|#
directive|define
name|ub_off
value|ub_I.Ub_off
end_define

begin_define
define|#
directive|define
name|ub_npf
value|ub_I.Ub_npf
end_define

begin_define
define|#
directive|define
name|ub_bdp
value|ub_I.Ub_bdp
end_define

end_unit

