begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1982, 1986 Regents of the University of California.  * All rights reserved.  The Berkeley software License Agreement  * specifies the terms and conditions for redistribution.  *  *	@(#)mbareg.h	7.1 (Berkeley) 6/5/86  */
end_comment

begin_comment
comment|/*  * VAX MASSBUS adapter registers  */
end_comment

begin_struct
struct|struct
name|mba_regs
block|{
name|int
name|mba_csr
decl_stmt|;
comment|/* configuration register */
name|int
name|mba_cr
decl_stmt|;
comment|/* control register */
name|int
name|mba_sr
decl_stmt|;
comment|/* status register */
name|int
name|mba_var
decl_stmt|;
comment|/* virtual address register */
name|int
name|mba_bcr
decl_stmt|;
comment|/* byte count register */
name|int
name|mba_dr
decl_stmt|;
name|int
name|mba_pad1
index|[
literal|250
index|]
decl_stmt|;
struct|struct
name|mba_drv
block|{
comment|/* per drive registers */
name|int
name|mbd_cs1
decl_stmt|;
comment|/* control status */
name|int
name|mbd_ds
decl_stmt|;
comment|/* drive status */
name|int
name|mbd_er1
decl_stmt|;
comment|/* error register */
name|int
name|mbd_mr1
decl_stmt|;
comment|/* maintenance register */
name|int
name|mbd_as
decl_stmt|;
comment|/* attention status */
name|int
name|mbd_da
decl_stmt|;
comment|/* desired address (disks) */
define|#
directive|define
name|mbd_fc
value|mbd_da
comment|/* frame count (tapes) */
name|int
name|mbd_dt
decl_stmt|;
comment|/* drive type */
name|int
name|mbd_la
decl_stmt|;
comment|/* look ahead (disks) */
define|#
directive|define
name|mbd_ck
value|mbd_la
comment|/* ??? (tapes) */
name|int
name|mbd_sn
decl_stmt|;
comment|/* serial number */
name|int
name|mbd_of
decl_stmt|;
comment|/* ??? */
define|#
directive|define
name|mbd_tc
value|mbd_of
comment|/* ??? */
name|int
name|mbd_fill
index|[
literal|22
index|]
decl_stmt|;
block|}
name|mba_drv
index|[
literal|8
index|]
struct|;
name|struct
name|pte
name|mba_map
index|[
literal|256
index|]
decl_stmt|;
comment|/* io space virtual map */
name|int
name|mba_pad2
index|[
literal|256
operator|*
literal|5
index|]
decl_stmt|;
comment|/* to size of a nexus */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Bits in mba_cr  */
end_comment

begin_define
define|#
directive|define
name|MBCR_INIT
value|0x1
end_define

begin_comment
comment|/* init mba */
end_comment

begin_define
define|#
directive|define
name|MBCR_IE
value|0x4
end_define

begin_comment
comment|/* enable mba interrupts */
end_comment

begin_comment
comment|/*  * Bits in mba_sr  */
end_comment

begin_define
define|#
directive|define
name|MBSR_DTBUSY
value|0x80000000
end_define

begin_comment
comment|/* data transfer busy */
end_comment

begin_define
define|#
directive|define
name|MBSR_NRCONF
value|0x40000000
end_define

begin_comment
comment|/* no response confirmation */
end_comment

begin_define
define|#
directive|define
name|MBSR_CRD
value|0x20000000
end_define

begin_comment
comment|/* corrected read data */
end_comment

begin_define
define|#
directive|define
name|MBSR_CBHUNG
value|0x00800000
end_define

begin_comment
comment|/* control bus hung */
end_comment

begin_define
define|#
directive|define
name|MBSR_PGE
value|0x00080000
end_define

begin_comment
comment|/* programming error */
end_comment

begin_define
define|#
directive|define
name|MBSR_NED
value|0x00040000
end_define

begin_comment
comment|/* non-existant drive */
end_comment

begin_define
define|#
directive|define
name|MBSR_MCPE
value|0x00020000
end_define

begin_comment
comment|/* massbus control parity error */
end_comment

begin_define
define|#
directive|define
name|MBSR_ATTN
value|0x00010000
end_define

begin_comment
comment|/* attention from massbus */
end_comment

begin_define
define|#
directive|define
name|MBSR_SPE
value|0x00004000
end_define

begin_comment
comment|/* silo parity error */
end_comment

begin_define
define|#
directive|define
name|MBSR_DTCMP
value|0x00002000
end_define

begin_comment
comment|/* data transfer completed */
end_comment

begin_define
define|#
directive|define
name|MBSR_DTABT
value|0x00001000
end_define

begin_comment
comment|/* data transfer aborted */
end_comment

begin_define
define|#
directive|define
name|MBSR_DLT
value|0x00000800
end_define

begin_comment
comment|/* data late */
end_comment

begin_define
define|#
directive|define
name|MBSR_WCKUP
value|0x00000400
end_define

begin_comment
comment|/* write check upper */
end_comment

begin_define
define|#
directive|define
name|MBSR_WCKLWR
value|0x00000200
end_define

begin_comment
comment|/* write check lower */
end_comment

begin_define
define|#
directive|define
name|MBSR_MXF
value|0x00000100
end_define

begin_comment
comment|/* miss transfer error */
end_comment

begin_define
define|#
directive|define
name|MBSR_MBEXC
value|0x00000080
end_define

begin_comment
comment|/* massbus exception */
end_comment

begin_define
define|#
directive|define
name|MBSR_MDPE
value|0x00000040
end_define

begin_comment
comment|/* massbus data parity error */
end_comment

begin_define
define|#
directive|define
name|MBSR_MAPPE
value|0x00000020
end_define

begin_comment
comment|/* page frame map parity error */
end_comment

begin_define
define|#
directive|define
name|MBSR_INVMAP
value|0x00000010
end_define

begin_comment
comment|/* invalid map */
end_comment

begin_define
define|#
directive|define
name|MBSR_ERRCONF
value|0x00000008
end_define

begin_comment
comment|/* error confirmation */
end_comment

begin_define
define|#
directive|define
name|MBSR_RDS
value|0x00000004
end_define

begin_comment
comment|/* read data substitute */
end_comment

begin_define
define|#
directive|define
name|MBSR_ISTIMO
value|0x00000002
end_define

begin_comment
comment|/* interface sequence timeout */
end_comment

begin_define
define|#
directive|define
name|MBSR_RDTIMO
value|0x00000001
end_define

begin_comment
comment|/* read data timeout */
end_comment

begin_define
define|#
directive|define
name|MBSR_BITS
define|\
value|"\20\40DTBUSY\37NRCONF\36CRD\30CBHUNG\24PGE\23NED\22MCPE\21ATTN\ \17SPE\16DTCMP\15DTABT\14DLT\13WCKUP\12WCKLWR\11MXF\10MBEXC\7MDPE\ \6MAPPE\5INVMAP\4ERRCONF\3RDS\2ISTIMO\1RDTIMO"
end_define

begin_define
define|#
directive|define
name|MBSR_HARD
value|(MBSR_PGE|MBSR_ERRCONF|MBSR_ISTIMO|MBSR_RDTIMO)
end_define

begin_define
define|#
directive|define
name|MBSR_EBITS
value|(~(MBSR_DTBUSY|MBSR_CRD|MBSR_ATTN|MBSR_DTCMP))
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|KERNEL
end_ifdef

begin_decl_stmt
specifier|extern
name|char
name|mbsr_bits
index|[]
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Commands for mbd_cs1  */
end_comment

begin_define
define|#
directive|define
name|MB_WCOM
value|0x30
end_define

begin_define
define|#
directive|define
name|MB_RCOM
value|0x38
end_define

begin_define
define|#
directive|define
name|MB_GO
value|0x1
end_define

begin_comment
comment|/*  * Bits in mbd_ds.  */
end_comment

begin_define
define|#
directive|define
name|MBDS_ERR
value|0x00004000
end_define

begin_comment
comment|/* error in drive */
end_comment

begin_define
define|#
directive|define
name|MBDS_MOL
value|0x00001000
end_define

begin_comment
comment|/* medium on line */
end_comment

begin_define
define|#
directive|define
name|MBDS_DPR
value|0x00000100
end_define

begin_comment
comment|/* drive present */
end_comment

begin_define
define|#
directive|define
name|MBDS_DRY
value|0x00000080
end_define

begin_comment
comment|/* drive ready */
end_comment

begin_define
define|#
directive|define
name|MBDS_DREADY
value|(MBDS_MOL|MBDS_DPR|MBDS_DRY)
end_define

begin_comment
comment|/*  * Bits in mbd_dt  */
end_comment

begin_define
define|#
directive|define
name|MBDT_NSA
value|0x8000
end_define

begin_comment
comment|/* not sector addressible */
end_comment

begin_define
define|#
directive|define
name|MBDT_TAP
value|0x4000
end_define

begin_comment
comment|/* is a tape */
end_comment

begin_define
define|#
directive|define
name|MBDT_MOH
value|0x2000
end_define

begin_comment
comment|/* moving head */
end_comment

begin_define
define|#
directive|define
name|MBDT_7CH
value|0x1000
end_define

begin_comment
comment|/* 7 channel */
end_comment

begin_define
define|#
directive|define
name|MBDT_DRQ
value|0x800
end_define

begin_comment
comment|/* drive request required */
end_comment

begin_define
define|#
directive|define
name|MBDT_SPR
value|0x400
end_define

begin_comment
comment|/* slave present */
end_comment

begin_define
define|#
directive|define
name|MBDT_TYPE
value|0x1ff
end_define

begin_define
define|#
directive|define
name|MBDT_MASK
value|(MBDT_NSA|MBDT_TAP|MBDT_TYPE)
end_define

begin_comment
comment|/* type codes for disk drives */
end_comment

begin_define
define|#
directive|define
name|MBDT_RP04
value|020
end_define

begin_define
define|#
directive|define
name|MBDT_RP05
value|021
end_define

begin_define
define|#
directive|define
name|MBDT_RP06
value|022
end_define

begin_define
define|#
directive|define
name|MBDT_RP07
value|042
end_define

begin_define
define|#
directive|define
name|MBDT_RM02
value|025
end_define

begin_define
define|#
directive|define
name|MBDT_RM03
value|024
end_define

begin_define
define|#
directive|define
name|MBDT_RM05
value|027
end_define

begin_define
define|#
directive|define
name|MBDT_RM80
value|026
end_define

begin_define
define|#
directive|define
name|MBDT_ML11A
value|0110
end_define

begin_define
define|#
directive|define
name|MBDT_ML11B
value|0111
end_define

begin_comment
comment|/* type codes for tape drives */
end_comment

begin_define
define|#
directive|define
name|MBDT_TM03
value|050
end_define

begin_define
define|#
directive|define
name|MBDT_TE16
value|051
end_define

begin_define
define|#
directive|define
name|MBDT_TU45
value|052
end_define

begin_define
define|#
directive|define
name|MBDT_TU77
value|054
end_define

begin_define
define|#
directive|define
name|MBDT_TU78
value|0101
end_define

end_unit

