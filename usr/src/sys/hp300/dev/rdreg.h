begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1988 University of Utah.  * Copyright (c) 1982, 1990 The Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * the Systems Programming Group of the University of Utah Computer  * Science Department.  *  * %sccs.include.redist.c%  *  * from: Utah $Hdr: rdreg.h 1.14 89/02/27$  *  *	@(#)rdreg.h	7.1 (Berkeley) %G%  */
end_comment

begin_struct
struct|struct
name|rd_iocmd
block|{
name|char
name|c_pad
decl_stmt|;
name|char
name|c_unit
decl_stmt|;
name|char
name|c_volume
decl_stmt|;
name|char
name|c_saddr
decl_stmt|;
name|short
name|c_hiaddr
decl_stmt|;
name|long
name|c_addr
decl_stmt|;
name|char
name|c_nop2
decl_stmt|;
name|char
name|c_slen
decl_stmt|;
name|long
name|c_len
decl_stmt|;
name|char
name|c_cmd
decl_stmt|;
name|char
name|c_pad2
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|rd_rscmd
block|{
name|char
name|c_unit
decl_stmt|;
name|char
name|c_sram
decl_stmt|;
name|char
name|c_ram
decl_stmt|;
name|char
name|c_cmd
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|rd_stat
block|{
name|char
name|c_vu
decl_stmt|;
name|char
name|c_pend
decl_stmt|;
name|short
name|c_ref
decl_stmt|;
name|short
name|c_fef
decl_stmt|;
name|short
name|c_aef
decl_stmt|;
name|short
name|c_ief
decl_stmt|;
union|union
block|{
name|char
name|cu_raw
index|[
literal|10
index|]
decl_stmt|;
struct|struct
block|{
name|short
name|cu_msw
decl_stmt|;
name|long
name|cu_lsl
decl_stmt|;
block|}
name|cu_sva
struct|;
struct|struct
block|{
name|long
name|cu_cyhd
decl_stmt|;
name|short
name|cu_sect
decl_stmt|;
block|}
name|cu_tva
struct|;
block|}
name|c_pf
union|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|c_raw
value|c_pf.cu_raw
end_define

begin_define
define|#
directive|define
name|c_blk
value|c_pf.cu_sva.cu_lsl
end_define

begin_comment
comment|/* for now */
end_comment

begin_define
define|#
directive|define
name|c_tva
value|c_pf.cu_tva
end_define

begin_struct
struct|struct
name|rd_ssmcmd
block|{
name|char
name|c_unit
decl_stmt|;
name|char
name|c_cmd
decl_stmt|;
name|short
name|c_refm
decl_stmt|;
name|short
name|c_fefm
decl_stmt|;
name|short
name|c_aefm
decl_stmt|;
name|short
name|c_iefm
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|rd_srcmd
block|{
name|char
name|c_unit
decl_stmt|;
name|char
name|c_nop
decl_stmt|;
name|char
name|c_cmd
decl_stmt|;
name|char
name|c_param
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|rd_clearcmd
block|{
name|char
name|c_unit
decl_stmt|;
name|char
name|c_cmd
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|rd_describe
block|{
name|u_int
name|d_iuw
range|:
literal|16
decl_stmt|,
comment|/* controller: installed unit word */
name|d_cmaxxfr
range|:
literal|16
decl_stmt|,
comment|/* controller: max transfer rate (Kb) */
name|d_ctype
range|:
literal|8
decl_stmt|,
comment|/* controller: controller type */
name|d_utype
range|:
literal|8
decl_stmt|,
comment|/* unit: unit type */
name|d_name
range|:
literal|24
decl_stmt|,
comment|/* unit: name (6 BCD digits) */
name|d_sectsize
range|:
literal|16
decl_stmt|,
comment|/* unit: # of bytes per block (sector) */
name|d_blkbuf
range|:
literal|8
decl_stmt|,
comment|/* unit: # of blocks which can be buffered */
name|d_burstsize
range|:
literal|8
decl_stmt|,
comment|/* unit: recommended burst size */
name|d_blocktime
range|:
literal|16
decl_stmt|,
comment|/* unit: block time (u-sec) */
name|d_uavexfr
range|:
literal|16
decl_stmt|,
comment|/* unit: average transfer rate (Kb) */
name|d_retry
range|:
literal|16
decl_stmt|,
comment|/* unit: optimal retry time (1/100-sec) */
name|d_access
range|:
literal|16
decl_stmt|,
comment|/* unit: access time param (1/100-sec) */
name|d_maxint
range|:
literal|8
decl_stmt|,
comment|/* unit: maximum interleave */
name|d_fvbyte
range|:
literal|8
decl_stmt|,
comment|/* unit: fixed volume byte */
name|d_rvbyte
range|:
literal|8
decl_stmt|,
comment|/* unit: removeable volume byte */
name|d_maxcyl
range|:
literal|24
decl_stmt|,
comment|/* volume: maximum cylinder */
name|d_maxhead
range|:
literal|8
decl_stmt|,
comment|/* volume: maximum head */
name|d_maxsect
range|:
literal|16
decl_stmt|,
comment|/* volume: maximum sector on track */
name|d_maxvsecth
range|:
literal|16
decl_stmt|,
comment|/* volume: maximum sector on volume (MSW) */
name|d_maxvsectl
range|:
literal|32
decl_stmt|,
comment|/* volume: maximum sector on volume (LSWs) */
name|d_interleave
range|:
literal|8
decl_stmt|;
comment|/* volume: current interleave */
block|}
struct|;
end_struct

begin_comment
comment|/* indicies into rdinfo -- order is arbitrary */
end_comment

begin_define
define|#
directive|define
name|RD7945A
value|0
end_define

begin_define
define|#
directive|define
name|RD9134D
value|1
end_define

begin_define
define|#
directive|define
name|RD9122S
value|2
end_define

begin_define
define|#
directive|define
name|RD7912P
value|3
end_define

begin_define
define|#
directive|define
name|RD7914P
value|4
end_define

begin_define
define|#
directive|define
name|RD7958A
value|5
end_define

begin_define
define|#
directive|define
name|RD7957A
value|6
end_define

begin_define
define|#
directive|define
name|RD7933H
value|7
end_define

begin_define
define|#
directive|define
name|RD9134L
value|8
end_define

begin_define
define|#
directive|define
name|RD7936H
value|9
end_define

begin_define
define|#
directive|define
name|RD7937H
value|10
end_define

begin_define
define|#
directive|define
name|RD7914CT
value|11
end_define

begin_define
define|#
directive|define
name|RD7946A
value|12
end_define

begin_define
define|#
directive|define
name|RD9122D
value|13
end_define

begin_define
define|#
directive|define
name|RD7957B
value|14
end_define

begin_define
define|#
directive|define
name|RD7958B
value|15
end_define

begin_define
define|#
directive|define
name|RD7959B
value|16
end_define

begin_comment
comment|/* HW ids */
end_comment

begin_define
define|#
directive|define
name|RD7946AID
value|0x220
end_define

begin_comment
comment|/* also 7945A */
end_comment

begin_define
define|#
directive|define
name|RD9134DID
value|0x221
end_define

begin_comment
comment|/* also 9122S */
end_comment

begin_define
define|#
directive|define
name|RD9134LID
value|0x222
end_define

begin_comment
comment|/* also 9122D */
end_comment

begin_define
define|#
directive|define
name|RD7912PID
value|0x209
end_define

begin_define
define|#
directive|define
name|RD7914CTID
value|0x20A
end_define

begin_define
define|#
directive|define
name|RD7914PID
value|0x20B
end_define

begin_define
define|#
directive|define
name|RD7958AID
value|0x22B
end_define

begin_define
define|#
directive|define
name|RD7957AID
value|0x22A
end_define

begin_define
define|#
directive|define
name|RD7933HID
value|0x212
end_define

begin_define
define|#
directive|define
name|RD7936HID
value|0x213
end_define

begin_comment
comment|/* just guessing -- as of yet unknown */
end_comment

begin_define
define|#
directive|define
name|RD7937HID
value|0x214
end_define

begin_define
define|#
directive|define
name|RD7957BID
value|0x22C
end_define

begin_comment
comment|/* another guess based on 7958B */
end_comment

begin_define
define|#
directive|define
name|RD7958BID
value|0x22D
end_define

begin_define
define|#
directive|define
name|RD7959BID
value|0x22E
end_define

begin_comment
comment|/* another guess based on 7958B */
end_comment

begin_define
define|#
directive|define
name|NRD7945ABPT
value|(32>> (DEV_BSHIFT-8))
end_define

begin_define
define|#
directive|define
name|NRD7945ATRK
value|7
end_define

begin_define
define|#
directive|define
name|NRD9134DBPT
value|(32>> (DEV_BSHIFT-8))
end_define

begin_define
define|#
directive|define
name|NRD9134DTRK
value|6
end_define

begin_define
define|#
directive|define
name|NRD9122SBPT
value|(16>> (DEV_BSHIFT-8))
end_define

begin_define
define|#
directive|define
name|NRD9122STRK
value|2
end_define

begin_define
define|#
directive|define
name|NRD7912PBPT
value|(64>> (DEV_BSHIFT-8))
end_define

begin_define
define|#
directive|define
name|NRD7912PTRK
value|7
end_define

begin_define
define|#
directive|define
name|NRD7914PBPT
value|(64>> (DEV_BSHIFT-8))
end_define

begin_define
define|#
directive|define
name|NRD7914PTRK
value|7
end_define

begin_define
define|#
directive|define
name|NRD7933HBPT
value|(92>> (DEV_BSHIFT-8))
end_define

begin_define
define|#
directive|define
name|NRD7933HTRK
value|13
end_define

begin_define
define|#
directive|define
name|NRD9134LBPT
value|(32>> (DEV_BSHIFT-8))
end_define

begin_define
define|#
directive|define
name|NRD9134LTRK
value|5
end_define

begin_comment
comment|/*  * Several HP drives have an odd number of 256 byte sectors per track.  * This makes it rather difficult to break them into 512 and 1024 byte blocks.  * So...we just do like HPUX and don't bother to respect hardware track/head  * boundries -- we just mold the disk so that we use the entire capacity.  * HPUX also sometimes doen't abide by cylinder boundries, we attempt to  * whenever possible.  *  * DISK		REAL (256 BPS)		HPUX (1024 BPS)		BSD (512 BPS)  * 		SPT x HD x CYL		SPT x HD x CYL		SPT x HD x CYL  * -----	---------------		---------------		--------------  * 7936:	123 x  7 x 1396		25 x  7 x 1716		123 x  7 x  698  * 7937:	123 x 13 x 1396		25 x 16 x 1395		123 x 13 x  698  *  * 7957A:	 63 x  5 x 1013		11 x  7 x 1036		 22 x  7 x 1036  * 7958A:	 63 x  8 x 1013		21 x  6 x 1013		 36 x  7 x 1013  *  * 7957B:	 63 x  4 x 1269		 9 x  7 x 1269		 18 x  7 x 1269  * 7958B:	 63 x  6 x 1572		21 x  9 x  786		 42 x  9 x  786  * 7959B:	 63 x 12 x 1572		21 x  9 x 1572		 42 x  9 x 1572  */
end_comment

begin_if
if|#
directive|if
name|DEV_BSIZE
operator|==
literal|512
end_if

begin_define
define|#
directive|define
name|NRD7936HBPT
value|123
end_define

begin_define
define|#
directive|define
name|NRD7936HTRK
value|7
end_define

begin_define
define|#
directive|define
name|NRD7937HBPT
value|123
end_define

begin_define
define|#
directive|define
name|NRD7937HTRK
value|13
end_define

begin_define
define|#
directive|define
name|NRD7957ABPT
value|22
end_define

begin_define
define|#
directive|define
name|NRD7957ATRK
value|7
end_define

begin_define
define|#
directive|define
name|NRD7958ABPT
value|36
end_define

begin_define
define|#
directive|define
name|NRD7958ATRK
value|7
end_define

begin_define
define|#
directive|define
name|NRD7957BBPT
value|18
end_define

begin_define
define|#
directive|define
name|NRD7957BTRK
value|7
end_define

begin_define
define|#
directive|define
name|NRD7958BBPT
value|42
end_define

begin_define
define|#
directive|define
name|NRD7958BTRK
value|9
end_define

begin_define
define|#
directive|define
name|NRD7959BBPT
value|42
end_define

begin_define
define|#
directive|define
name|NRD7959BTRK
value|9
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|DEV_BSIZE
operator|==
literal|1024
end_if

begin_define
define|#
directive|define
name|NRD7957ABPT
value|11
end_define

begin_define
define|#
directive|define
name|NRD7957ATRK
value|7
end_define

begin_define
define|#
directive|define
name|NRD7958ABPT
value|21
end_define

begin_define
define|#
directive|define
name|NRD7958ATRK
value|6
end_define

begin_define
define|#
directive|define
name|NRD7957BBPT
value|9
end_define

begin_define
define|#
directive|define
name|NRD7957BTRK
value|7
end_define

begin_define
define|#
directive|define
name|NRD7958BBPT
value|21
end_define

begin_define
define|#
directive|define
name|NRD7958BTRK
value|9
end_define

begin_define
define|#
directive|define
name|NRD7959BBPT
value|21
end_define

begin_define
define|#
directive|define
name|NRD7959BTRK
value|9
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* controller "unit" number */
end_comment

begin_define
define|#
directive|define
name|RDCTLR
value|15
end_define

begin_comment
comment|/* convert 512 byte count into DEV_BSIZE count */
end_comment

begin_define
define|#
directive|define
name|RDSZ
parameter_list|(
name|x
parameter_list|)
value|((x)>> (DEV_BSHIFT-9))
end_define

begin_comment
comment|/* convert block number into sector number and back */
end_comment

begin_define
define|#
directive|define
name|RDBTOS
parameter_list|(
name|x
parameter_list|)
value|((x)<< (DEV_BSHIFT-8))
end_define

begin_define
define|#
directive|define
name|RDSTOB
parameter_list|(
name|x
parameter_list|)
value|((x)>> (DEV_BSHIFT-8))
end_define

begin_comment
comment|/* extract cyl/head/sect info from three-vector address */
end_comment

begin_define
define|#
directive|define
name|RDCYL
parameter_list|(
name|tva
parameter_list|)
value|((u_long)(tva).cu_cyhd>> 8)
end_define

begin_define
define|#
directive|define
name|RDHEAD
parameter_list|(
name|tva
parameter_list|)
value|((tva).cu_cyhd& 0xFF)
end_define

begin_define
define|#
directive|define
name|RDSECT
parameter_list|(
name|tva
parameter_list|)
value|((tva).cu_sect)
end_define

begin_define
define|#
directive|define
name|REF_MASK
value|0x0
end_define

begin_define
define|#
directive|define
name|FEF_MASK
value|0x0
end_define

begin_define
define|#
directive|define
name|AEF_MASK
value|0x0
end_define

begin_define
define|#
directive|define
name|IEF_MASK
value|0xF970
end_define

begin_define
define|#
directive|define
name|FEF_CU
value|0x4000
end_define

begin_comment
comment|/* cross-unit */
end_comment

begin_define
define|#
directive|define
name|FEF_DR
value|0x0080
end_define

begin_comment
comment|/* diagnostic result */
end_comment

begin_define
define|#
directive|define
name|FEF_IMR
value|0x0008
end_define

begin_comment
comment|/* internal maintenance release */
end_comment

begin_define
define|#
directive|define
name|FEF_PF
value|0x0002
end_define

begin_comment
comment|/* power fail */
end_comment

begin_define
define|#
directive|define
name|FEF_REXMT
value|0x0001
end_define

begin_comment
comment|/* retransmit */
end_comment

begin_define
define|#
directive|define
name|AEF_UD
value|0x0040
end_define

begin_comment
comment|/* unrecoverable data */
end_comment

begin_define
define|#
directive|define
name|IEF_RRMASK
value|0xe000
end_define

begin_comment
comment|/* request release bits */
end_comment

begin_define
define|#
directive|define
name|IEF_MD
value|0x0020
end_define

begin_comment
comment|/* marginal data */
end_comment

begin_define
define|#
directive|define
name|IEF_RD
value|0x0010
end_define

begin_comment
comment|/* recoverable data */
end_comment

begin_define
define|#
directive|define
name|C_READ
value|0x00
end_define

begin_define
define|#
directive|define
name|C_RAM
value|0x00
end_define

begin_comment
comment|/* single vector (i.e. sector number) */
end_comment

begin_define
define|#
directive|define
name|C_WRITE
value|0x02
end_define

begin_define
define|#
directive|define
name|C_CLEAR
value|0x08
end_define

begin_define
define|#
directive|define
name|C_STATUS
value|0x0d
end_define

begin_define
define|#
directive|define
name|C_SADDR
value|0x10
end_define

begin_define
define|#
directive|define
name|C_SLEN
value|0x18
end_define

begin_define
define|#
directive|define
name|C_SUNIT
parameter_list|(
name|x
parameter_list|)
value|(0x20 | (x))
end_define

begin_define
define|#
directive|define
name|C_SVOL
parameter_list|(
name|x
parameter_list|)
value|(0x40 | (x))
end_define

begin_define
define|#
directive|define
name|C_NOP
value|0x34
end_define

begin_define
define|#
directive|define
name|C_DESC
value|0x35
end_define

begin_define
define|#
directive|define
name|C_SREL
value|0x3b
end_define

begin_define
define|#
directive|define
name|C_SSM
value|0x3e
end_define

begin_define
define|#
directive|define
name|C_SRAM
value|0x48
end_define

begin_define
define|#
directive|define
name|C_REL
value|0x140
end_define

begin_define
define|#
directive|define
name|C_CMD
value|0x05
end_define

begin_define
define|#
directive|define
name|C_EXEC
value|0x0e
end_define

begin_define
define|#
directive|define
name|C_QSTAT
value|0x10
end_define

begin_define
define|#
directive|define
name|C_TCMD
value|0x12
end_define

end_unit

