begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1992 The Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Sony Corp. and Kazumasa Utashiro of Software Research Associates, Inc.  *  * %sccs.include.redist.c%  *  * from: $Hdr: sddefs.c,v 4.300 91/06/09 06:38:25 root Rel41 $ SONY  *  *	@(#)sddefs.c	7.2 (Berkeley) %G%  */
end_comment

begin_include
include|#
directive|include
file|"sd.h"
end_include

begin_if
if|#
directive|if
name|NSD
operator|>
literal|0
end_if

begin_comment
comment|/*  * Copyright (c) 1989- by SONY Corporation.  */
end_comment

begin_comment
comment|/*  * SD device configuration file  */
end_comment

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<news3400/iodev/sdreg.h>
end_include

begin_include
include|#
directive|include
file|<news3400/iodev/scsireg.h>
end_include

begin_include
include|#
directive|include
file|<news3400/iodev/scu.h>
end_include

begin_decl_stmt
name|char
name|revs_all
index|[]
init|=
literal|"????"
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*******************************/
end_comment

begin_comment
comment|/* disk partition informations */
end_comment

begin_comment
comment|/*******************************/
end_comment

begin_comment
comment|/* BEGIN sizes */
end_comment

begin_decl_stmt
name|struct
name|size
name|wren3_101_sizes
index|[
name|PNUM
index|]
init|=
block|{
literal|15884
block|,
literal|0
block|,
comment|/* A = cyl   0 thru  93 */
literal|33440
block|,
literal|94
operator|*
literal|34
operator|*
literal|5
block|,
comment|/* B = cyl  94 thru 290 */
literal|169150
block|,
literal|0
block|,
comment|/* C = cyl   0 thru 994 */
literal|15884
block|,
literal|291
operator|*
literal|34
operator|*
literal|5
block|,
comment|/* D = cyl 291 thru 384 */
literal|55936
block|,
literal|385
operator|*
literal|34
operator|*
literal|5
block|,
comment|/* E = cyl 385 thru 714 */
literal|47600
block|,
literal|715
operator|*
literal|34
operator|*
literal|5
block|,
comment|/* F = cyl 715 thru 994 */
literal|119680
block|,
literal|291
operator|*
literal|34
operator|*
literal|5
block|,
comment|/* G = cyl 291 thru 994 */
literal|0
block|,
literal|0
block|,
comment|/* H	Not use		*/
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|size
name|wren3_101_hh_sizes
index|[
name|PNUM
index|]
init|=
block|{
literal|15884
block|,
literal|0
block|,
comment|/* A =  15884 */
literal|33440
block|,
literal|15884
block|,
comment|/* B =  33440 */
literal|178850
block|,
literal|0
block|,
comment|/* C = 178850 */
literal|15884
block|,
literal|49324
block|,
comment|/* D =  15884 */
literal|55936
block|,
literal|65208
block|,
comment|/* E =  55936 */
literal|57706
block|,
literal|121144
block|,
comment|/* F =  57706 */
comment|/* F = C-(A+B+H+D+E) */
literal|129526
block|,
literal|49324
block|,
comment|/* G = 129526 */
comment|/* G = D+E+F */
literal|113642
block|,
literal|65208
block|,
comment|/* H = 113642 */
comment|/* H = E+F */
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|size
name|wren3_182_sizes
index|[
name|PNUM
index|]
init|=
block|{
literal|15884
block|,
literal|0
block|,
comment|/* A = cyl   0 thru  51 */
literal|33440
block|,
literal|52
operator|*
literal|34
operator|*
literal|9
block|,
comment|/* B = cyl  52 thru 161 */
literal|304470
block|,
literal|0
block|,
comment|/* C = cyl   0 thru 994 */
literal|15884
block|,
literal|162
operator|*
literal|34
operator|*
literal|9
block|,
comment|/* D = cyl 162 thru 213 */
literal|55936
block|,
literal|214
operator|*
literal|34
operator|*
literal|9
block|,
comment|/* E = cyl 214 thru 396 */
literal|182988
block|,
literal|397
operator|*
literal|34
operator|*
literal|9
block|,
comment|/* F = cyl 397 thru 994 */
literal|254898
block|,
literal|162
operator|*
literal|34
operator|*
literal|9
block|,
comment|/* G = cyl 162 thru 994 */
literal|0
block|,
literal|0
block|,
comment|/* H	Not use		*/
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* END sizes */
end_comment

begin_comment
comment|/*************************/
end_comment

begin_comment
comment|/* device specifications */
end_comment

begin_comment
comment|/*************************/
end_comment

begin_decl_stmt
name|struct
name|sdst
name|sdst_unknown
init|=
comment|/*   ns, nt,  nspc,  ncyl, rps, xxx,	    sizes */
block|{
literal|1
block|,
literal|1
block|,
literal|1
block|,
literal|1
block|,
literal|60
block|,
literal|0
block|,
name|calc_disk_sizes
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* UNKNOWN_DISK */
end_comment

begin_decl_stmt
name|struct
name|sdst
name|sdst_wren3_101
init|=
block|{
literal|34
block|,
literal|5
block|,
literal|34
operator|*
literal|5
block|,
literal|995
block|,
literal|60
block|,
literal|0
block|,
name|wren3_101_sizes
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* WREN3_101 */
end_comment

begin_decl_stmt
name|struct
name|sdst
name|sdst_wren3_101_hh
init|=
block|{
literal|35
block|,
literal|5
block|,
literal|35
operator|*
literal|5
block|,
literal|1022
block|,
literal|60
block|,
literal|0
block|,
name|wren3_101_hh_sizes
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* WREN3_101_HH */
end_comment

begin_decl_stmt
name|struct
name|sdst
name|sdst_wren3_182
init|=
block|{
literal|34
block|,
literal|9
block|,
literal|34
operator|*
literal|9
block|,
literal|995
block|,
literal|60
block|,
literal|0
block|,
name|wren3_182_sizes
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* WREN3_182 */
end_comment

begin_decl_stmt
name|struct
name|sdst
name|sdst_wren3_182_old
init|=
block|{
literal|35
block|,
literal|9
block|,
literal|35
operator|*
literal|9
block|,
literal|967
block|,
literal|60
block|,
literal|0
block|,
name|wren3_182_sizes
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* WREN3_182_OLD */
end_comment

begin_decl_stmt
name|struct
name|sdst
name|sdst_wren4_286
init|=
block|{
literal|52
block|,
literal|9
block|,
literal|52
operator|*
literal|9
block|,
literal|1365
block|,
literal|60
block|,
literal|0
block|,
name|calc_disk_sizes
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* WREN4_286 */
end_comment

begin_decl_stmt
name|struct
name|sdst
name|sdst_wren5_170_hh
init|=
block|{
literal|52
block|,
literal|5
block|,
literal|52
operator|*
literal|5
block|,
literal|1544
block|,
literal|60
block|,
literal|0
block|,
name|calc_disk_sizes
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* WREN5_170_HH */
end_comment

begin_decl_stmt
name|struct
name|sdst
name|sdst_wren6_415_hh
init|=
block|{
literal|70
block|,
literal|7
block|,
literal|70
operator|*
literal|7
block|,
literal|1756
block|,
literal|60
block|,
literal|0
block|,
name|calc_disk_sizes
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* WREN6_415_HH */
end_comment

begin_decl_stmt
name|struct
name|sdst
name|sdst_st1480n
init|=
block|{
literal|70
block|,
literal|9
block|,
literal|70
operator|*
literal|9
block|,
literal|1476
block|,
literal|74
block|,
literal|0
block|,
name|calc_disk_sizes
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* ST1480N */
end_comment

begin_decl_stmt
name|struct
name|sdst
name|sdst_dk515c_78
init|=
block|{
literal|69
block|,
literal|14
block|,
literal|69
operator|*
literal|14
block|,
literal|1356
block|,
literal|60
block|,
literal|0
block|,
name|calc_disk_sizes
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* DK515C_78 */
end_comment

begin_decl_stmt
name|struct
name|sdst
name|sdst_dk516c_16
init|=
block|{
literal|81
block|,
literal|15
block|,
literal|81
operator|*
literal|15
block|,
literal|2165
block|,
literal|60
block|,
literal|0
block|,
name|calc_disk_sizes
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* DK516C_16 */
end_comment

begin_decl_stmt
name|struct
name|sdst
name|sdst_dk312c_20
init|=
block|{
literal|38
block|,
literal|10
block|,
literal|38
operator|*
literal|10
block|,
literal|1076
block|,
literal|60
block|,
literal|0
block|,
name|calc_disk_sizes
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* DK312C_20 */
end_comment

begin_decl_stmt
name|struct
name|sdst
name|sdst_dk312c_25
init|=
block|{
literal|38
block|,
literal|12
block|,
literal|38
operator|*
literal|12
block|,
literal|1076
block|,
literal|60
block|,
literal|0
block|,
name|calc_disk_sizes
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* DK312C_25 */
end_comment

begin_decl_stmt
name|struct
name|sdst
name|sdst_xt_8760s
init|=
block|{
literal|54
block|,
literal|15
block|,
literal|54
operator|*
literal|15
block|,
literal|1632
block|,
literal|60
block|,
literal|0
block|,
name|calc_disk_sizes
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* XT_8760S */
end_comment

begin_decl_stmt
name|struct
name|sdst
name|sdst_srd2040z
init|=
block|{
literal|33
block|,
literal|4
block|,
literal|33
operator|*
literal|4
block|,
literal|608
block|,
literal|60
block|,
literal|0
block|,
name|calc_disk_sizes
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* SRD-2040Z */
end_comment

begin_decl_stmt
name|struct
name|sdst
name|sdst_smo_s501
init|=
block|{
literal|31
block|,
literal|1
block|,
literal|31
operator|*
literal|1
block|,
literal|18678
block|,
literal|40
block|,
literal|0
block|,
name|calc_disk_sizes
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* SMO_S501 */
end_comment

begin_decl_stmt
name|struct
name|sdst
name|sdst_smo_s501_iso
init|=
block|{
literal|31
block|,
literal|1
block|,
literal|31
operator|*
literal|1
block|,
literal|18646
block|,
literal|40
block|,
literal|0
block|,
name|calc_disk_sizes
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* SMO_S501_ISO */
end_comment

begin_comment
comment|/***************************************************************/
end_comment

begin_comment
comment|/************************************/
end_comment

begin_comment
comment|/* normal Error Recovery Parameters */
end_comment

begin_comment
comment|/************************************/
end_comment

begin_decl_stmt
name|char
name|erp_wren3_old
index|[]
init|=
comment|/* WREN3 old firmware */
block|{
name|SDM_PG_ERR
block|,
literal|0x06
block|,
name|SDM_DCR
block|,
literal|0
block|,
literal|0x08
block|,
literal|0
block|,
literal|0
block|,
literal|0xff
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
name|erp_wren3
index|[]
init|=
comment|/* WREN3 */
block|{
name|SDM_PG_ERR
block|,
literal|0x06
block|,
name|SDM_AWRE
operator||
name|SDM_DCR
block|,
literal|0x09
block|,
literal|0x08
block|,
literal|0
block|,
literal|0
block|,
literal|0xff
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
name|erp_wren4567
index|[]
init|=
comment|/* WREN4567 */
block|{
name|SDM_PG_ERR
block|,
literal|0x06
block|,
name|SDM_AWRE
operator||
name|SDM_DCR
block|,
literal|0x09
block|,
literal|0x0b
block|,
literal|0
block|,
literal|0
block|,
literal|0xff
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
name|erp_st1480n
index|[]
init|=
comment|/* ST1480N */
block|{
name|SDM_PG_ERR
block|,
literal|0x0a
block|,
name|SDM_AWRE
operator||
name|SDM_DCR
block|,
literal|0x09
block|,
literal|0x0b
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|3
block|,
literal|0
block|,
literal|0xff
block|,
literal|0xff
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
name|erp_dk515c_78
index|[]
init|=
comment|/* DK515C_78 */
block|{
name|SDM_PG_ERR
block|,
literal|0x06
block|,
name|SDM_DCR
block|,
literal|0x0a
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
name|erp_dk516c_16
index|[]
init|=
comment|/* DK516C_16 */
block|{
name|SDM_PG_ERR
block|,
literal|0x0a
block|,
name|SDM_DCR
block|,
literal|0x0a
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0x0a
block|,
literal|0
block|,
literal|0x01
block|,
literal|0xf4
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
name|erp_dk312c_25
index|[]
init|=
comment|/* DK312C_25 */
block|{
name|SDM_PG_ERR
block|,
literal|0x06
block|,
name|SDM_DCR
block|,
literal|0x0a
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
name|erp_xt_8760s
index|[]
init|=
comment|/* XT_8760S */
block|{
name|SDM_PG_ERR
block|,
literal|0x06
block|,
name|SDM_DCR
block|,
literal|0x03
block|,
literal|0x0b
block|,
literal|0
block|,
literal|0
block|,
literal|0xff
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
name|erp_srd2040z
index|[]
init|=
comment|/* SRD-2040Z */
block|{
name|SDM_PG_ERR
block|,
literal|0x06
block|,
name|SDM_DCR
block|,
literal|0x03
block|,
literal|0x13
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
name|erp_smo_s501
index|[]
init|=
comment|/* SMO_S501 */
block|{
name|SDM_PG_ERR
block|,
literal|0x06
block|,
name|SDM_AWRE
block|,
literal|0x02
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*********************************/
end_comment

begin_comment
comment|/* max Error Recovery Parameters */
end_comment

begin_comment
comment|/*********************************/
end_comment

begin_decl_stmt
name|char
name|max_erp_wren3_old
index|[]
init|=
comment|/* WREN3 old firmware */
block|{
name|SDM_PG_ERR
block|,
literal|0x06
block|,
literal|0
block|,
literal|0x1b
block|,
literal|0x08
block|,
literal|0
block|,
literal|0
block|,
literal|0xff
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
name|max_erp_wren3
index|[]
init|=
comment|/* WREN3 */
block|{
name|SDM_PG_ERR
block|,
literal|0x06
block|,
literal|0
block|,
literal|0x1b
block|,
literal|0x08
block|,
literal|0
block|,
literal|0
block|,
literal|0xff
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
name|max_erp_wren4567
index|[]
init|=
comment|/* WREN4567 */
block|{
name|SDM_PG_ERR
block|,
literal|0x06
block|,
name|SDM_AWRE
block|,
literal|0x1b
block|,
literal|0x0b
block|,
literal|0
block|,
literal|0
block|,
literal|0xff
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
name|max_erp_st1480n
index|[]
init|=
comment|/* ST1480N */
block|{
name|SDM_PG_ERR
block|,
literal|0x0a
block|,
name|SDM_AWRE
block|,
literal|0x1b
block|,
literal|0x0b
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|3
block|,
literal|0
block|,
literal|0xff
block|,
literal|0xff
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
name|max_erp_dk515c_78
index|[]
init|=
comment|/* DK515C_78 */
block|{
name|SDM_PG_ERR
block|,
literal|0x06
block|,
literal|0
block|,
literal|0x10
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
name|max_erp_dk516c_16
index|[]
init|=
comment|/* DK516C_16 */
block|{
name|SDM_PG_ERR
block|,
literal|0x0a
block|,
literal|0
block|,
literal|0x10
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0x10
block|,
literal|0
block|,
literal|0xff
block|,
literal|0xff
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
name|max_erp_dk312c_25
index|[]
init|=
comment|/* DK312C_25 */
block|{
name|SDM_PG_ERR
block|,
literal|0x06
block|,
literal|0
block|,
literal|0x10
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
name|max_erp_xt_8760s
index|[]
init|=
comment|/* XT_8760S */
block|{
name|SDM_PG_ERR
block|,
literal|0x06
block|,
literal|0
block|,
literal|0x1b
block|,
literal|0x0b
block|,
literal|0
block|,
literal|0
block|,
literal|0xff
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
name|max_erp_srd2040z
index|[]
init|=
comment|/* SRD-2040Z */
block|{
name|SDM_PG_ERR
block|,
literal|0x06
block|,
name|SDM_ARRE
operator||
name|SDM_AWRE
block|,
literal|0x1b
block|,
literal|0x13
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
name|max_erp_smo_s501
index|[]
init|=
comment|/* SMO_S501 */
block|{
name|SDM_PG_ERR
block|,
literal|0x06
block|,
name|SDM_AWRE
block|,
literal|0x10
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/********************/
end_comment

begin_comment
comment|/* Other Parameters */
end_comment

begin_comment
comment|/********************/
end_comment

begin_decl_stmt
name|char
name|cache_off_wren4old
index|[]
init|=
comment|/* WREN4 old */
block|{
name|SDM_PG_CACHE2
block|,
literal|0x0e
block|,
literal|0x01
block|,
literal|0xff
block|,
literal|0x34
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
name|cache_on_wren4567
index|[]
init|=
comment|/* WREN4567 */
block|{
name|SDM_PG_CACHE2
block|,
literal|0x0e
block|,
literal|0x11
block|,
literal|0xff
block|,
literal|0x34
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
name|cache1_on_st1480n
index|[]
init|=
comment|/* ST1480N */
block|{
name|SDM_PG_CACHE1
block|,
literal|0x0a
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0x78
block|,
literal|0
block|,
literal|0
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
name|cache2_on_st1480n
index|[]
init|=
comment|/* ST1480N */
block|{
name|SDM_PG_CACHE2
block|,
literal|0x0e
block|,
literal|0x51
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
name|cache_on_dk515c_78
index|[]
init|=
comment|/* DK515C_78 */
block|{
name|SDM_PG_CACHE1
block|,
literal|0x0a
block|,
literal|0
block|,
literal|0
block|,
literal|0x02
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0x60
block|,
literal|0
block|,
literal|0x60
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
name|modif_dk515c_78
index|[]
init|=
comment|/* DK515C_78 */
block|{
name|SDM_PG_MODIFY
block|,
literal|0x0a
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
name|SDM_RING
operator||
literal|0x01
block|,
name|SDM_ESDT
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
name|cache_on_dk516c_16
index|[]
init|=
comment|/* DK516C_16 */
block|{
name|SDM_PG_CACHE1
block|,
literal|0x0a
block|,
literal|0
block|,
literal|0
block|,
literal|0x08
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0x80
block|,
literal|0
block|,
literal|0x80
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
name|modif_dk516c_16
index|[]
init|=
comment|/* DK516C_16 */
block|{
name|SDM_PG_MODIFY
block|,
literal|0x1e
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|4
block|,
name|SDM_STOD
operator||
name|SDM_ESDT
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0x0e
block|,
literal|0xff
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0x50
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
name|cache_on_dk312c
index|[]
init|=
comment|/* DK312C_25 */
block|{
name|SDM_PG_CACHE1
block|,
literal|0x0a
block|,
literal|0
block|,
literal|0
block|,
literal|0x02
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0x60
block|,
literal|0
block|,
literal|0x60
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
name|cache_off_dk312c
index|[]
init|=
comment|/* DK312C_25 */
block|{
name|SDM_PG_CACHE1
block|,
literal|0x0a
block|,
literal|1
block|,
literal|0
block|,
literal|0x02
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0x60
block|,
literal|0
block|,
literal|0x60
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
name|cache_on_xt_8760s
index|[]
init|=
comment|/* XT_8760S */
block|{
name|SDM_PG_CACHE2
block|,
literal|0x0e
block|,
literal|0x11
block|,
literal|0xff
block|,
literal|0x59
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/************** OTHER PAGES SPECIFICATIONS ********************/
end_comment

begin_decl_stmt
name|char
modifier|*
name|other_wren4old
index|[]
init|=
block|{
name|cache_off_wren4old
block|,
name|NULL
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|other_wren4567
index|[]
init|=
block|{
name|cache_on_wren4567
block|,
name|NULL
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|other_st1480n
index|[]
init|=
block|{
name|cache1_on_st1480n
block|,
name|cache2_on_st1480n
block|,
name|NULL
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|other_dk515c_78
index|[]
init|=
block|{
name|cache_on_dk515c_78
block|,
name|modif_dk515c_78
block|,
name|NULL
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|other_dk516c_16
index|[]
init|=
block|{
name|cache_on_dk516c_16
block|,
name|modif_dk516c_16
block|,
name|NULL
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|other_dk312c_on
index|[]
init|=
block|{
name|cache_on_dk312c
block|,
name|modif_dk515c_78
block|,
name|NULL
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|other_dk312c_off
index|[]
init|=
block|{
name|cache_off_dk312c
block|,
name|modif_dk515c_78
block|,
name|NULL
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|other_xt_8760s
index|[]
init|=
block|{
name|cache_on_xt_8760s
block|,
name|NULL
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/**************************************************************/
end_comment

begin_comment
comment|/*************************/
end_comment

begin_comment
comment|/*			 */
end_comment

begin_comment
comment|/* SD device information */
end_comment

begin_comment
comment|/*			 */
end_comment

begin_comment
comment|/*************************/
end_comment

begin_decl_stmt
name|struct
name|sddevinfo
name|sddevinfo
index|[]
init|=
block|{
block|{
comment|/* UNKNOWN DISK */
literal|1
block|,
comment|/* identify length */
literal|"*"
block|,
comment|/* vendor& product ID */
name|revs_all
block|,
comment|/* revision */
operator|-
literal|1
block|,
comment|/* drive capacity */
literal|"UNKNOWN"
block|,
comment|/* device nickname */
name|UNKNOWN_DISK
block|,
comment|/* device type code */
literal|0
block|,
comment|/* firmware spec */
literal|0
block|,
comment|/* synchronous transfer period */
literal|0
block|,
comment|/* synchronous transfer offset */
name|NULL
block|,
comment|/* device setup commands */
operator|&
name|sdst_unknown
block|,
comment|/* device specifications */
name|NULL
block|,
comment|/* normal Error Recovery Parameters */
name|NULL
block|,
comment|/* max Error Recovery Parameters */
name|NULL
block|,
comment|/* Other Parameters */
name|FMT_DLF_PHYS
block|,
comment|/* Format options */
block|}
block|,
block|{
comment|/* CDC WREN III 94161-5 */
literal|15
block|,
comment|/* identify length */
literal|"CDC     94161-5"
block|,
comment|/* vendor& product ID */
literal|"6296"
block|,
comment|/* revision */
literal|0x029509
block|,
comment|/* drive capacity */
literal|"hd101"
block|,
comment|/* device nickname */
name|WREN3_101
block|,
comment|/* device type code */
name|FIRM_AWRE
block|,
comment|/* firmware spec */
literal|0
block|,
comment|/* synchronous transfer period */
literal|0
block|,
comment|/* synchronous transfer offset */
name|NULL
block|,
comment|/* device setup commands */
operator|&
name|sdst_wren3_101
block|,
comment|/* device specifications */
name|erp_wren3
block|,
comment|/* normal Error Recovery Parameters */
name|max_erp_wren3
block|,
comment|/* max Error Recovery Parameters */
name|NULL
block|,
comment|/* Other Parameters */
literal|0
block|,
comment|/* Format options */
block|}
block|,
block|{
comment|/* CDC WREN III 94161-86 */
literal|16
block|,
comment|/* identify length */
literal|"CDC     94161-86"
block|,
comment|/* vendor& product ID */
literal|"6296"
block|,
comment|/* revision */
literal|0x029509
block|,
comment|/* drive capacity */
literal|"hd101"
block|,
comment|/* device nickname */
name|WREN3_101
block|,
comment|/* device type code */
name|FIRM_AWRE
block|,
comment|/* firmware spec */
literal|0
block|,
comment|/* synchronous transfer period */
literal|0
block|,
comment|/* synchronous transfer offset */
name|NULL
block|,
comment|/* device setup commands */
operator|&
name|sdst_wren3_101
block|,
comment|/* device specifications */
name|erp_wren3
block|,
comment|/* normal Error Recovery Parameters */
name|max_erp_wren3
block|,
comment|/* max Error Recovery Parameters */
name|NULL
block|,
comment|/* Other Parameters */
literal|0
block|,
comment|/* Format options */
block|}
block|,
block|{
comment|/* CDC WREN III 94161-9 */
literal|15
block|,
comment|/* identify length */
literal|"CDC     94161-9"
block|,
comment|/* vendor& product ID */
literal|"6296"
block|,
comment|/* revision */
literal|0x04a5dd
block|,
comment|/* drive capacity */
literal|"hd182"
block|,
comment|/* device nickname */
name|WREN3_182
block|,
comment|/* device type code */
name|FIRM_AWRE
block|,
comment|/* firmware spec */
literal|0
block|,
comment|/* synchronous transfer period */
literal|0
block|,
comment|/* synchronous transfer offset */
name|NULL
block|,
comment|/* device setup commands */
operator|&
name|sdst_wren3_182
block|,
comment|/* device specifications */
name|erp_wren3
block|,
comment|/* normal Error Recovery Parameters */
name|max_erp_wren3
block|,
comment|/* max Error Recovery Parameters */
name|NULL
block|,
comment|/* Other Parameters */
literal|0
block|,
comment|/* Format options */
block|}
block|,
block|{
comment|/* CDC WREN III 94161-155 */
literal|17
block|,
comment|/* identify length */
literal|"CDC     94161-155"
block|,
comment|/* vendor& product ID */
literal|"6296"
block|,
comment|/* revision */
literal|0x04a556
block|,
comment|/* drive capacity */
literal|"hd182"
block|,
comment|/* device nickname */
name|WREN3_182
block|,
comment|/* device type code */
name|FIRM_AWRE
block|,
comment|/* firmware spec */
literal|0
block|,
comment|/* synchronous transfer period */
literal|0
block|,
comment|/* synchronous transfer offset */
name|NULL
block|,
comment|/* device setup commands */
operator|&
name|sdst_wren3_182
block|,
comment|/* device specifications */
name|erp_wren3
block|,
comment|/* normal Error Recovery Parameters */
name|max_erp_wren3
block|,
comment|/* max Error Recovery Parameters */
name|NULL
block|,
comment|/* Other Parameters */
literal|0
block|,
comment|/* Format options */
block|}
block|,
block|{
comment|/* CDC WREN III 94161-155 */
literal|17
block|,
comment|/* identify length */
literal|"CDC     94161-155"
block|,
comment|/* vendor& product ID */
literal|"6296"
block|,
comment|/* revision */
literal|0x04a5dd
block|,
comment|/* drive capacity */
literal|"hd182"
block|,
comment|/* device nickname */
name|WREN3_182
block|,
comment|/* device type code */
name|FIRM_AWRE
block|,
comment|/* firmware spec */
literal|0
block|,
comment|/* synchronous transfer period */
literal|0
block|,
comment|/* synchronous transfer offset */
name|NULL
block|,
comment|/* device setup commands */
operator|&
name|sdst_wren3_182
block|,
comment|/* device specifications */
name|erp_wren3
block|,
comment|/* normal Error Recovery Parameters */
name|max_erp_wren3
block|,
comment|/* max Error Recovery Parameters */
name|NULL
block|,
comment|/* Other Parameters */
literal|0
block|,
comment|/* Format options */
block|}
block|,
block|{
comment|/* CDC WREN III 94161-156 */
literal|17
block|,
comment|/* identify length */
literal|"CDC     94161-156"
block|,
comment|/* vendor& product ID */
literal|"6296"
block|,
comment|/* revision */
literal|0x04a5dd
block|,
comment|/* drive capacity */
literal|"hd182"
block|,
comment|/* device nickname */
name|WREN3_182
block|,
comment|/* device type code */
name|FIRM_AWRE
block|,
comment|/* firmware spec */
literal|0
block|,
comment|/* synchronous transfer period */
literal|0
block|,
comment|/* synchronous transfer offset */
name|NULL
block|,
comment|/* device setup commands */
operator|&
name|sdst_wren3_182
block|,
comment|/* device specifications */
name|erp_wren3
block|,
comment|/* normal Error Recovery Parameters */
name|max_erp_wren3
block|,
comment|/* max Error Recovery Parameters */
name|NULL
block|,
comment|/* Other Parameters */
literal|0
block|,
comment|/* Format options */
block|}
block|,
block|{
comment|/* CDC WREN III 94161-5 */
literal|15
block|,
comment|/* identify length */
literal|"CDC     94161-5"
block|,
comment|/* vendor& product ID */
name|revs_all
block|,
comment|/* revision */
literal|0x029509
block|,
comment|/* drive capacity */
literal|"hd101"
block|,
comment|/* device nickname */
name|WREN3_101
block|,
comment|/* device type code */
literal|0
block|,
comment|/* firmware spec */
literal|0
block|,
comment|/* synchronous transfer period */
literal|0
block|,
comment|/* synchronous transfer offset */
name|NULL
block|,
comment|/* device setup commands */
operator|&
name|sdst_wren3_101
block|,
comment|/* device specifications */
name|erp_wren3_old
block|,
comment|/* normal Error Recovery Parameters */
name|max_erp_wren3_old
block|,
comment|/* max Error Recovery Parameters */
name|NULL
block|,
comment|/* Other Parameters */
literal|0
block|,
comment|/* Format options */
block|}
block|,
block|{
comment|/* CDC WREN III 94161-86 */
literal|16
block|,
comment|/* identify length */
literal|"CDC     94161-86"
block|,
comment|/* vendor& product ID */
name|revs_all
block|,
comment|/* revision */
literal|0x029509
block|,
comment|/* drive capacity */
literal|"hd101"
block|,
comment|/* device nickname */
name|WREN3_101
block|,
comment|/* device type code */
literal|0
block|,
comment|/* firmware spec */
literal|0
block|,
comment|/* synchronous transfer period */
literal|0
block|,
comment|/* synchronous transfer offset */
name|NULL
block|,
comment|/* device setup commands */
operator|&
name|sdst_wren3_101
block|,
comment|/* device specifications */
name|erp_wren3_old
block|,
comment|/* normal Error Recovery Parameters */
name|max_erp_wren3_old
block|,
comment|/* max Error Recovery Parameters */
name|NULL
block|,
comment|/* Other Parameters */
literal|0
block|,
comment|/* Format options */
block|}
block|,
block|{
comment|/* CDC WREN III 94161-9 */
literal|15
block|,
comment|/* identify length */
literal|"CDC     94161-9"
block|,
comment|/* vendor& product ID */
name|revs_all
block|,
comment|/* revision */
literal|0x04a5dd
block|,
comment|/* drive capacity */
literal|"hd182"
block|,
comment|/* device nickname */
name|WREN3_182
block|,
comment|/* device type code */
literal|0
block|,
comment|/* firmware spec */
literal|0
block|,
comment|/* synchronous transfer period */
literal|0
block|,
comment|/* synchronous transfer offset */
name|NULL
block|,
comment|/* device setup commands */
operator|&
name|sdst_wren3_182
block|,
comment|/* device specifications */
name|erp_wren3_old
block|,
comment|/* normal Error Recovery Parameters */
name|max_erp_wren3_old
block|,
comment|/* max Error Recovery Parameters */
name|NULL
block|,
comment|/* Other Parameters */
literal|0
block|,
comment|/* Format options */
block|}
block|,
block|{
comment|/* CDC WREN III 94161-155 */
literal|17
block|,
comment|/* identify length */
literal|"CDC     94161-155"
block|,
comment|/* vendor& product ID */
name|revs_all
block|,
comment|/* revision */
literal|0x04a556
block|,
comment|/* drive capacity */
literal|"hd182"
block|,
comment|/* device nickname */
name|WREN3_182
block|,
comment|/* device type code */
literal|0
block|,
comment|/* firmware spec */
literal|0
block|,
comment|/* synchronous transfer period */
literal|0
block|,
comment|/* synchronous transfer offset */
name|NULL
block|,
comment|/* device setup commands */
operator|&
name|sdst_wren3_182
block|,
comment|/* device specifications */
name|erp_wren3_old
block|,
comment|/* normal Error Recovery Parameters */
name|max_erp_wren3_old
block|,
comment|/* max Error Recovery Parameters */
name|NULL
block|,
comment|/* Other Parameters */
literal|0
block|,
comment|/* Format options */
block|}
block|,
block|{
comment|/* CDC WREN III 94161-155 */
literal|17
block|,
comment|/* identify length */
literal|"CDC     94161-155"
block|,
comment|/* vendor& product ID */
name|revs_all
block|,
comment|/* revision */
literal|0x04a5dd
block|,
comment|/* drive capacity */
literal|"hd182"
block|,
comment|/* device nickname */
name|WREN3_182
block|,
comment|/* device type code */
literal|0
block|,
comment|/* firmware spec */
literal|0
block|,
comment|/* synchronous transfer period */
literal|0
block|,
comment|/* synchronous transfer offset */
name|NULL
block|,
comment|/* device setup commands */
operator|&
name|sdst_wren3_182
block|,
comment|/* device specifications */
name|erp_wren3_old
block|,
comment|/* normal Error Recovery Parameters */
name|max_erp_wren3_old
block|,
comment|/* max Error Recovery Parameters */
name|NULL
block|,
comment|/* Other Parameters */
literal|0
block|,
comment|/* Format options */
block|}
block|,
block|{
comment|/* CDC WREN III 94161-156 */
literal|17
block|,
comment|/* identify length */
literal|"CDC     94161-156"
block|,
comment|/* vendor& product ID */
name|revs_all
block|,
comment|/* revision */
literal|0x04a5dd
block|,
comment|/* drive capacity */
literal|"hd182"
block|,
comment|/* device nickname */
name|WREN3_182
block|,
comment|/* device type code */
literal|0
block|,
comment|/* firmware spec */
literal|0
block|,
comment|/* synchronous transfer period */
literal|0
block|,
comment|/* synchronous transfer offset */
name|NULL
block|,
comment|/* device setup commands */
operator|&
name|sdst_wren3_182
block|,
comment|/* device specifications */
name|erp_wren3_old
block|,
comment|/* normal Error Recovery Parameters */
name|max_erp_wren3_old
block|,
comment|/* max Error Recovery Parameters */
name|NULL
block|,
comment|/* Other Parameters */
literal|0
block|,
comment|/* Format options */
block|}
block|,
block|{
comment|/* CDC WREN III HH 94211-5 */
literal|15
block|,
comment|/* identify length */
literal|"CDC     94211-5"
block|,
comment|/* vendor& product ID */
name|revs_all
block|,
comment|/* revision */
literal|0x02baa2
block|,
comment|/* drive capacity */
literal|"hd101_hh"
block|,
comment|/* device nickname */
name|WREN3_101_HH
block|,
comment|/* device type code */
literal|0
block|,
comment|/* firmware spec */
literal|0
block|,
comment|/* synchronous transfer period */
literal|0
block|,
comment|/* synchronous transfer offset */
name|NULL
block|,
comment|/* device setup commands */
operator|&
name|sdst_wren3_101_hh
block|,
comment|/* device specifications */
name|erp_wren3_old
block|,
comment|/* normal Error Recovery Parameters */
name|max_erp_wren3_old
block|,
comment|/* max Error Recovery Parameters */
name|NULL
block|,
comment|/* Other Parameters */
literal|0
block|,
comment|/* Format options */
block|}
block|,
block|{
comment|/* CDC WREN III HH 94216-5 */
literal|15
block|,
comment|/* identify length */
literal|"CDC     94216-5"
block|,
comment|/* vendor& product ID */
name|revs_all
block|,
comment|/* revision */
literal|0x02baa2
block|,
comment|/* drive capacity */
literal|"hd101_hh"
block|,
comment|/* device nickname */
name|WREN3_101_HH
block|,
comment|/* device type code */
name|FIRM_AWRE
block|,
comment|/* firmware spec */
literal|0
block|,
comment|/* synchronous transfer period */
literal|0
block|,
comment|/* synchronous transfer offset */
name|NULL
block|,
comment|/* device setup commands */
operator|&
name|sdst_wren3_101_hh
block|,
comment|/* device specifications */
name|erp_wren3
block|,
comment|/* normal Error Recovery Parameters */
name|max_erp_wren3
block|,
comment|/* max Error Recovery Parameters */
name|NULL
block|,
comment|/* Other Parameters */
literal|0
block|,
comment|/* Format options */
block|}
block|,
block|{
comment|/* CDC WREN IV 94171-9 */
literal|15
block|,
comment|/* identify length */
literal|"CDC     94171-9"
block|,
comment|/* vendor& product ID */
literal|"6981"
block|,
comment|/* revision */
literal|0x08f40c
block|,
comment|/* drive capacity */
literal|"hd286"
block|,
comment|/* device nickname */
name|WREN4_286
block|,
comment|/* device type code */
literal|0
block|,
comment|/* firmware spec */
literal|0x4b
block|,
comment|/* synchronous transfer period */
literal|0
block|,
comment|/* synchronous transfer offset */
name|NULL
block|,
comment|/* device setup commands */
operator|&
name|sdst_wren4_286
block|,
comment|/* device specifications */
name|erp_wren4567
block|,
comment|/* normal Error Recovery Parameters */
name|max_erp_wren4567
block|,
comment|/* max Error Recovery Parameters */
name|other_wren4old
block|,
comment|/* Other Parameters */
name|FMT_DLF_PHYS
block|,
comment|/* Format options */
block|}
block|,
block|{
comment|/* CDC WREN IV 94171-9 */
literal|15
block|,
comment|/* identify length */
literal|"CDC     94171-9"
block|,
comment|/* vendor& product ID */
literal|"8794"
block|,
comment|/* revision */
literal|0x08f40c
block|,
comment|/* drive capacity */
literal|"hd286"
block|,
comment|/* device nickname */
name|WREN4_286
block|,
comment|/* device type code */
literal|0
block|,
comment|/* firmware spec */
literal|0x4b
block|,
comment|/* synchronous transfer period */
literal|0
block|,
comment|/* synchronous transfer offset */
name|NULL
block|,
comment|/* device setup commands */
operator|&
name|sdst_wren4_286
block|,
comment|/* device specifications */
name|erp_wren4567
block|,
comment|/* normal Error Recovery Parameters */
name|max_erp_wren4567
block|,
comment|/* max Error Recovery Parameters */
name|other_wren4old
block|,
comment|/* Other Parameters */
name|FMT_DLF_PHYS
block|,
comment|/* Format options */
block|}
block|,
block|{
comment|/* CDC WREN IV 94171-9 */
literal|15
block|,
comment|/* identify length */
literal|"CDC     94171-9"
block|,
comment|/* vendor& product ID */
literal|"8814"
block|,
comment|/* revision */
literal|0x08f40c
block|,
comment|/* drive capacity */
literal|"hd286"
block|,
comment|/* device nickname */
name|WREN4_286
block|,
comment|/* device type code */
literal|0
block|,
comment|/* firmware spec */
literal|0x4b
block|,
comment|/* synchronous transfer period */
literal|0
block|,
comment|/* synchronous transfer offset */
name|NULL
block|,
comment|/* device setup commands */
operator|&
name|sdst_wren4_286
block|,
comment|/* device specifications */
name|erp_wren4567
block|,
comment|/* normal Error Recovery Parameters */
name|max_erp_wren4567
block|,
comment|/* max Error Recovery Parameters */
name|other_wren4old
block|,
comment|/* Other Parameters */
name|FMT_DLF_PHYS
block|,
comment|/* Format options */
block|}
block|,
block|{
comment|/* CDC WREN IV 94171-9 */
literal|15
block|,
comment|/* identify length */
literal|"CDC     94171-9"
block|,
comment|/* vendor& product ID */
name|revs_all
block|,
comment|/* revision */
literal|0x08f40c
block|,
comment|/* drive capacity */
literal|"hd286"
block|,
comment|/* device nickname */
name|WREN4_286
block|,
comment|/* device type code */
name|FIRM_CACHE_ON
operator||
name|FIRM_SYNCTR
operator||
name|FIRM_AWRE
block|,
comment|/* firmware spec */
literal|0x4b
block|,
comment|/* synchronous transfer period */
literal|0
block|,
comment|/* synchronous transfer offset */
name|NULL
block|,
comment|/* device setup commands */
operator|&
name|sdst_wren4_286
block|,
comment|/* device specifications */
name|erp_wren4567
block|,
comment|/* normal Error Recovery Parameters */
name|max_erp_wren4567
block|,
comment|/* max Error Recovery Parameters */
name|other_wren4567
block|,
comment|/* Other Parameters */
name|FMT_DLF_PHYS
block|,
comment|/* Format options */
block|}
block|,
block|{
comment|/* CDC WREN V HH 94221-5 */
literal|15
block|,
comment|/* identify length */
literal|"CDC     94221-5"
block|,
comment|/* vendor& product ID */
name|revs_all
block|,
comment|/* revision */
literal|0x05564a
block|,
comment|/* drive capacity */
literal|"hd170_hh"
block|,
comment|/* device nickname */
name|WREN5_170_HH
block|,
comment|/* device type code */
name|FIRM_CACHE_ON
operator||
name|FIRM_SYNCTR
operator||
name|FIRM_AWRE
block|,
comment|/* firmware spec */
literal|0x3f
block|,
comment|/* MIN synchronous transfer period */
literal|15
block|,
comment|/* MAX synchronous transfer offset */
name|NULL
block|,
comment|/* device setup commands */
operator|&
name|sdst_wren5_170_hh
block|,
comment|/* device specifications */
name|erp_wren4567
block|,
comment|/* normal Error Recovery Parameters */
name|max_erp_wren4567
block|,
comment|/* max Error Recovery Parameters */
name|other_wren4567
block|,
comment|/* Other Parameters */
literal|0
block|,
comment|/* Format options */
block|}
block|,
block|{
comment|/* IMPRIMIS WREN VI HH 94241-7 */
literal|15
block|,
comment|/* identify length */
literal|"IMPRIMIS94241-7"
block|,
comment|/* vendor& product ID */
literal|"0207"
block|,
comment|/* revision */
literal|0xcfa13
block|,
comment|/* drive capacity */
literal|"hd415_hh"
block|,
comment|/* device nickname */
name|WREN6_415_HH
block|,
comment|/* device type code */
name|FIRM_CACHE_ON
operator||
name|FIRM_SYNCTR
operator||
name|FIRM_AWRE
block|,
comment|/* firmware spec */
literal|0x35
block|,
comment|/* MIN synchronous transfer period */
literal|15
block|,
comment|/* MAX synchronous transfer offset */
name|NULL
block|,
comment|/* device setup commands */
operator|&
name|sdst_wren6_415_hh
block|,
comment|/* device specifications */
name|erp_wren4567
block|,
comment|/* normal Error Recovery Parameters */
name|max_erp_wren4567
block|,
comment|/* max Error Recovery Parameters */
name|other_wren4567
block|,
comment|/* Other Parameters */
name|FMT_DLF_PHYS
block|,
comment|/* Format options */
block|}
block|,
block|{
comment|/* SEAGATE ST1480N */
literal|15
block|,
comment|/* identify length */
literal|"SEAGATE ST1480 "
block|,
comment|/* vendor& product ID */
name|revs_all
block|,
comment|/* revision */
literal|0xcb40f
block|,
comment|/* drive capacity */
literal|"hd406"
block|,
comment|/* device nickname */
comment|/* ???? */
name|ST1480N
block|,
comment|/* device type code */
name|FIRM_CACHE_ON
operator||
name|FIRM_AWRE
block|,
comment|/* firmware spec */
literal|0x35
block|,
comment|/* MIN synchronous transfer period */
literal|0
block|,
comment|/* MAX synchronous transfer offset */
name|NULL
block|,
comment|/* device setup commands */
operator|&
name|sdst_st1480n
block|,
comment|/* device specifications */
name|erp_st1480n
block|,
comment|/* normal Error Recovery Parameters */
name|max_erp_st1480n
block|,
comment|/* max Error Recovery Parameters */
name|other_st1480n
block|,
comment|/* Other Parameters */
name|FMT_DLF_PHYS
block|,
comment|/* Format options */
block|}
block|,
block|{
comment|/* HITACHI DK515C-78 */
literal|14
block|,
comment|/* identify length */
literal|"HITACHI DK515C"
block|,
comment|/* vendor& product ID */
name|revs_all
block|,
comment|/* revision */
literal|0x13fcc8
block|,
comment|/* drive capacity */
literal|"hd639"
block|,
comment|/* device nickname */
name|DK515C_78
block|,
comment|/* device type code */
name|FIRM_CACHE_ON
operator||
name|FIRM_SYNCTR
block|,
comment|/* firmware spec */
literal|0x3e
block|,
comment|/* MIN synchronous transfer period */
literal|8
block|,
comment|/* MAX synchronous transfer offset */
name|NULL
block|,
comment|/* device setup commands */
operator|&
name|sdst_dk515c_78
block|,
comment|/* device specifications */
name|erp_dk515c_78
block|,
comment|/* normal Error Recovery Parameters */
name|max_erp_dk515c_78
block|,
comment|/* max Error Recovery Parameters */
name|other_dk515c_78
block|,
comment|/* Other Parameters */
name|FMT_DLF_BLK
block|,
comment|/* Format options */
block|}
block|,
block|{
comment|/* HITACHI DK516C-16 */
literal|14
block|,
comment|/* identify length */
literal|"HITACHI DK516C"
block|,
comment|/* vendor& product ID */
name|revs_all
block|,
comment|/* revision */
literal|0x2800a4
block|,
comment|/* drive capacity */
literal|"hd1280"
block|,
comment|/* device nickname */
name|DK516C_16
block|,
comment|/* device type code */
name|FIRM_CACHE_ON
operator||
name|FIRM_SYNCTR
block|,
comment|/* firmware spec */
literal|0x3e
block|,
comment|/* synchronous transfer period */
literal|15
block|,
comment|/* synchronous transfer offset */
name|NULL
block|,
comment|/* device setup commands */
operator|&
name|sdst_dk516c_16
block|,
comment|/* device specifications */
name|erp_dk516c_16
block|,
comment|/* normal Error Recovery Parameters */
name|max_erp_dk516c_16
block|,
comment|/* max Error Recovery Parameters */
name|other_dk516c_16
block|,
comment|/* Other Parameters */
name|FMT_DLF_BLK
block|,
comment|/* Format options */
block|}
block|,
block|{
comment|/* HITACHI DK312C-20 */
literal|14
block|,
comment|/* identify length */
literal|"HITACHI DK312C"
block|,
comment|/* vendor& product ID */
literal|"CM73"
block|,
comment|/* revision */
literal|0x063d30
block|,
comment|/* drive capacity */
literal|"hd199"
block|,
comment|/* device nickname */
name|DK312C_20
block|,
comment|/* device type code */
name|FIRM_CACHE_ON
operator||
name|FIRM_SYNCTR
block|,
comment|/* firmware spec */
literal|0x3e
block|,
comment|/* MIN synchronous transfer period */
literal|7
block|,
comment|/* MAX synchronous transfer offset */
literal|0
block|,
comment|/* synchronous transfer register set */
operator|&
name|sdst_dk312c_20
block|,
comment|/* device specifications */
name|erp_dk312c_25
block|,
comment|/* normal Error Recovery Parameters */
name|max_erp_dk312c_25
block|,
comment|/* max Error Recovery Parameters */
name|other_dk312c_off
block|,
comment|/* Other Parameters */
name|FMT_DLF_BLK
block|,
comment|/* Format options */
block|}
block|,
block|{
comment|/* HITACHI DK312C-25 */
literal|14
block|,
comment|/* identify length */
literal|"HITACHI DK312C"
block|,
comment|/* vendor& product ID */
literal|"CM73"
block|,
comment|/* revision */
literal|0x077ca0
block|,
comment|/* drive capacity */
literal|"hd239"
block|,
comment|/* device nickname */
name|DK312C_25
block|,
comment|/* device type code */
name|FIRM_CACHE_ON
operator||
name|FIRM_SYNCTR
block|,
comment|/* firmware spec */
literal|0x3e
block|,
comment|/* MIN synchronous transfer period */
literal|7
block|,
comment|/* MAX synchronous transfer offset */
name|NULL
block|,
comment|/* device setup commands */
operator|&
name|sdst_dk312c_25
block|,
comment|/* device specifications */
name|erp_dk312c_25
block|,
comment|/* normal Error Recovery Parameters */
name|max_erp_dk312c_25
block|,
comment|/* max Error Recovery Parameters */
name|other_dk312c_off
block|,
comment|/* Other Parameters */
name|FMT_DLF_BLK
block|,
comment|/* Format options */
block|}
block|,
block|{
comment|/* HITACHI DK312C-20 */
literal|14
block|,
comment|/* identify length */
literal|"HITACHI DK312C"
block|,
comment|/* vendor& product ID */
literal|"CM76"
block|,
comment|/* revision */
literal|0x063d30
block|,
comment|/* drive capacity */
literal|"hd199"
block|,
comment|/* device nickname */
name|DK312C_20
block|,
comment|/* device type code */
name|FIRM_CACHE_ON
operator||
name|FIRM_SYNCTR
block|,
comment|/* firmware spec */
literal|0x3e
block|,
comment|/* MIN synchronous transfer period */
literal|7
block|,
comment|/* MAX synchronous transfer offset */
literal|0
block|,
comment|/* synchronous transfer register set */
operator|&
name|sdst_dk312c_20
block|,
comment|/* device specifications */
name|erp_dk312c_25
block|,
comment|/* normal Error Recovery Parameters */
name|max_erp_dk312c_25
block|,
comment|/* max Error Recovery Parameters */
name|other_dk312c_off
block|,
comment|/* Other Parameters */
name|FMT_DLF_BLK
block|,
comment|/* Format options */
block|}
block|,
block|{
comment|/* HITACHI DK312C-25 */
literal|14
block|,
comment|/* identify length */
literal|"HITACHI DK312C"
block|,
comment|/* vendor& product ID */
literal|"CM76"
block|,
comment|/* revision */
literal|0x077ca0
block|,
comment|/* drive capacity */
literal|"hd239"
block|,
comment|/* device nickname */
name|DK312C_25
block|,
comment|/* device type code */
name|FIRM_CACHE_ON
operator||
name|FIRM_SYNCTR
block|,
comment|/* firmware spec */
literal|0x3e
block|,
comment|/* MIN synchronous transfer period */
literal|7
block|,
comment|/* MAX synchronous transfer offset */
name|NULL
block|,
comment|/* device setup commands */
operator|&
name|sdst_dk312c_25
block|,
comment|/* device specifications */
name|erp_dk312c_25
block|,
comment|/* normal Error Recovery Parameters */
name|max_erp_dk312c_25
block|,
comment|/* max Error Recovery Parameters */
name|other_dk312c_off
block|,
comment|/* Other Parameters */
name|FMT_DLF_BLK
block|,
comment|/* Format options */
block|}
block|,
block|{
comment|/* HITACHI DK312C-20 */
literal|14
block|,
comment|/* identify length */
literal|"HITACHI DK312C"
block|,
comment|/* vendor& product ID */
name|revs_all
block|,
comment|/* revision */
literal|0x063d30
block|,
comment|/* drive capacity */
literal|"hd199"
block|,
comment|/* device nickname */
name|DK312C_20
block|,
comment|/* device type code */
name|FIRM_CACHE_ON
operator||
name|FIRM_SYNCTR
block|,
comment|/* firmware spec */
literal|0x3e
block|,
comment|/* MIN synchronous transfer period */
literal|7
block|,
comment|/* MAX synchronous transfer offset */
literal|0
block|,
comment|/* synchronous transfer register set */
operator|&
name|sdst_dk312c_20
block|,
comment|/* device specifications */
name|erp_dk312c_25
block|,
comment|/* normal Error Recovery Parameters */
name|max_erp_dk312c_25
block|,
comment|/* max Error Recovery Parameters */
name|other_dk312c_on
block|,
comment|/* Other Parameters */
name|FMT_DLF_BLK
block|,
comment|/* Format options */
block|}
block|,
block|{
comment|/* HITACHI DK312C-25 */
literal|14
block|,
comment|/* identify length */
literal|"HITACHI DK312C"
block|,
comment|/* vendor& product ID */
name|revs_all
block|,
comment|/* revision */
literal|0x077ca0
block|,
comment|/* drive capacity */
literal|"hd239"
block|,
comment|/* device nickname */
name|DK312C_25
block|,
comment|/* device type code */
name|FIRM_CACHE_ON
operator||
name|FIRM_SYNCTR
block|,
comment|/* firmware spec */
literal|0x3e
block|,
comment|/* MIN synchronous transfer period */
literal|7
block|,
comment|/* MAX synchronous transfer offset */
name|NULL
block|,
comment|/* device setup commands */
operator|&
name|sdst_dk312c_25
block|,
comment|/* device specifications */
name|erp_dk312c_25
block|,
comment|/* normal Error Recovery Parameters */
name|max_erp_dk312c_25
block|,
comment|/* max Error Recovery Parameters */
name|other_dk312c_on
block|,
comment|/* Other Parameters */
name|FMT_DLF_BLK
block|,
comment|/* Format options */
block|}
block|,
block|{
comment|/* MAXTOR XT-8760S B5A */
literal|16
block|,
comment|/* identify length */
literal|"MAXTOR  XT-8760S"
block|,
comment|/* vendor& product ID */
literal|"B5A "
block|,
comment|/* revision */
literal|0x13bc99
block|,
comment|/* drive capacity */
literal|"xt_8760s"
block|,
comment|/* device nickname */
name|XT_8760S
block|,
comment|/* device type code */
name|FIRM_CACHE_ON
operator||
name|FIRM_SYNCTR
block|,
comment|/* firmware spec */
literal|0x35
block|,
comment|/* MIN synchronous transfer period */
literal|15
block|,
comment|/* MAX synchronous transfer offset */
name|NULL
block|,
comment|/* device setup commands */
operator|&
name|sdst_xt_8760s
block|,
comment|/* device specifications */
name|erp_xt_8760s
block|,
comment|/* normal Error Recovery Parameters */
name|max_erp_xt_8760s
block|,
comment|/* max Error Recovery Parameters */
name|other_xt_8760s
block|,
comment|/* Other Parameters */
name|FMT_DLF_PHYS
block|,
comment|/* Format options */
block|}
block|,
block|{
comment|/* MAXTOR XT-8760S B3C */
literal|16
block|,
comment|/* identify length */
literal|"MAXTOR  XT-8760S"
block|,
comment|/* vendor& product ID */
literal|"B3C "
block|,
comment|/* revision */
literal|0x13bc99
block|,
comment|/* drive capacity */
literal|"xt_8760s"
block|,
comment|/* device nickname */
name|XT_8760S
block|,
comment|/* device type code */
literal|0
block|,
comment|/* firmware spec */
literal|0
block|,
comment|/* synchronous transfer period */
literal|0
block|,
comment|/* synchronous transfer offset */
name|NULL
block|,
comment|/* device setup commands */
operator|&
name|sdst_xt_8760s
block|,
comment|/* device specifications */
name|erp_xt_8760s
block|,
comment|/* normal Error Recovery Parameters */
name|max_erp_xt_8760s
block|,
comment|/* max Error Recovery Parameters */
name|NULL
block|,
comment|/* Other Parameters */
name|FMT_DLF_PHYS
block|,
comment|/* Format options */
block|}
block|,
block|{
comment|/* SONY SRD2040Z */
literal|16
block|,
comment|/* identify length */
literal|"SONY    SRD2040Z"
block|,
comment|/* vendor& product ID */
name|revs_all
block|,
comment|/* revision */
literal|0x014124
block|,
comment|/* drive capacity */
literal|"hd41"
block|,
comment|/* device nickname */
name|SRD_2040Z
block|,
comment|/* device type code */
literal|0
block|,
comment|/* firmware spec */
literal|0
block|,
comment|/* synchronous transfer period */
literal|0
block|,
comment|/* synchronous transfer offset */
name|NULL
block|,
comment|/* device setup commands */
operator|&
name|sdst_srd2040z
block|,
comment|/* device specifications */
name|erp_srd2040z
block|,
comment|/* normal Error Recovery Parameters */
name|max_erp_srd2040z
block|,
comment|/* max Error Recovery Parameters */
name|NULL
block|,
comment|/* Other Parameters */
name|FMT_DLF_BLK
block|,
comment|/* Format options */
block|}
block|,
block|{
comment|/* SONY SMO-S501 SONY format */
literal|16
block|,
comment|/* identify length */
literal|"SONY    SMO-C501"
block|,
comment|/* vendor& product ID */
literal|"1.??"
block|,
comment|/* revision */
literal|0x08d5c0
block|,
comment|/* drive capacity */
literal|"od282"
block|,
comment|/* device nickname */
name|SMO_S501
block|,
comment|/* device type code */
name|FIRM_AWRE
block|,
comment|/* firmware spec */
literal|0
block|,
comment|/* synchronous transfer period */
literal|0
block|,
comment|/* synchronous transfer offset */
name|NULL
block|,
comment|/* device setup commands */
operator|&
name|sdst_smo_s501
block|,
comment|/* device specifications */
name|erp_smo_s501
block|,
comment|/* normal Error Recovery Parameters */
name|max_erp_smo_s501
block|,
comment|/* max Error Recovery Parameters */
name|NULL
block|,
comment|/* Other Parameters */
name|FMT_DLF_PHYS
block|,
comment|/* Format options */
block|}
block|,
block|{
comment|/* SONY SMO-S501 ISO format */
literal|16
block|,
comment|/* identify length */
literal|"SONY    SMO-C501"
block|,
comment|/* vendor& product ID */
literal|"2.??"
block|,
comment|/* revision */
literal|0x08cde7
block|,
comment|/* drive capacity */
literal|"od282iso"
block|,
comment|/* device nickname */
name|SMO_S501_ISO2
block|,
comment|/* device type code */
name|FIRM_AWRE
block|,
comment|/* firmware spec */
literal|0
block|,
comment|/* synchronous transfer period */
literal|0
block|,
comment|/* synchronous transfer offset */
name|NULL
block|,
comment|/* device setup commands */
operator|&
name|sdst_smo_s501_iso
block|,
comment|/* device specifications */
name|erp_smo_s501
block|,
comment|/* normal Error Recovery Parameters */
name|max_erp_smo_s501
block|,
comment|/* max Error Recovery Parameters */
name|NULL
block|,
comment|/* Other Parameters */
name|FMT_DLF_PHYS
block|,
comment|/* Format options */
block|}
block|,
block|{
comment|/* SONY SMO-S501 ISO format */
literal|16
block|,
comment|/* identify length */
literal|"SONY    SMO-C501"
block|,
comment|/* vendor& product ID */
literal|"2.??"
block|,
comment|/* revision */
literal|0x08d1e7
block|,
comment|/* drive capacity */
literal|"od282i"
block|,
comment|/* device nickname */
name|SMO_S501_ISO
block|,
comment|/* device type code */
name|FIRM_AWRE
block|,
comment|/* firmware spec */
literal|0
block|,
comment|/* synchronous transfer period */
literal|0
block|,
comment|/* synchronous transfer offset */
name|NULL
block|,
comment|/* device setup commands */
operator|&
name|sdst_smo_s501_iso
block|,
comment|/* device specifications */
name|erp_smo_s501
block|,
comment|/* normal Error Recovery Parameters */
name|max_erp_smo_s501
block|,
comment|/* max Error Recovery Parameters */
name|NULL
block|,
comment|/* Other Parameters */
name|FMT_DLF_PHYS
block|,
comment|/* Format options */
block|}
block|,
block|{
comment|/* SONY SMO-S501 SONY format */
literal|16
block|,
comment|/* identify length */
literal|"SONY    SMO-C501"
block|,
comment|/* vendor& product ID */
literal|"2.??"
block|,
comment|/* revision */
literal|0x08d5c0
block|,
comment|/* drive capacity */
literal|"od282"
block|,
comment|/* device nickname */
name|SMO_S501
block|,
comment|/* device type code */
name|FIRM_AWRE
block|,
comment|/* firmware spec */
literal|0
block|,
comment|/* synchronous transfer period */
literal|0
block|,
comment|/* synchronous transfer offset */
name|NULL
block|,
comment|/* device setup commands */
operator|&
name|sdst_smo_s501
block|,
comment|/* device specifications */
name|erp_smo_s501
block|,
comment|/* normal Error Recovery Parameters */
name|max_erp_smo_s501
block|,
comment|/* max Error Recovery Parameters */
name|NULL
block|,
comment|/* Other Parameters */
name|FMT_DLF_PHYS
block|,
comment|/* Format options */
block|}
block|,
block|{
comment|/* End of table */
operator|-
literal|1
block|,     }
block|}
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* NSD> 0 */
end_comment

end_unit

