begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1992 The Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Sony Corp. and Kazumasa Utashiro of Software Research Associates, Inc.  *  * %sccs.include.redist.c%  *  * from: $Hdr: machid.h,v 4.300 91/06/09 06:35:19 root Rel41 $ SONY  *  *	@(#)machid.h	7.1 (Berkeley) %G%  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__MACHID__
end_ifndef

begin_define
define|#
directive|define
name|__MACHID__
value|1
end_define

begin_comment
comment|/*  * machine id number definition.  */
end_comment

begin_define
define|#
directive|define
name|ICK001
value|1
end_define

begin_define
define|#
directive|define
name|ICK00X
value|2
end_define

begin_define
define|#
directive|define
name|NWS799
value|3
end_define

begin_define
define|#
directive|define
name|NWS800
value|4
end_define

begin_define
define|#
directive|define
name|NWS801
value|5
end_define

begin_define
define|#
directive|define
name|NWS802
value|6
end_define

begin_define
define|#
directive|define
name|NWS711
value|7
end_define

begin_define
define|#
directive|define
name|NWS721
value|8
end_define

begin_define
define|#
directive|define
name|NWS1850
value|9
end_define

begin_define
define|#
directive|define
name|NWS810
value|10
end_define

begin_define
define|#
directive|define
name|NWS811
value|11
end_define

begin_define
define|#
directive|define
name|NWS1830
value|12
end_define

begin_define
define|#
directive|define
name|NWS1750
value|13
end_define

begin_define
define|#
directive|define
name|NWS1720
value|14
end_define

begin_define
define|#
directive|define
name|NWS1930
value|15
end_define

begin_define
define|#
directive|define
name|NWS1960
value|16
end_define

begin_define
define|#
directive|define
name|NWS712
value|17
end_define

begin_define
define|#
directive|define
name|NWS1860
value|18
end_define

begin_define
define|#
directive|define
name|PWS1630
value|19
end_define

begin_define
define|#
directive|define
name|NWS820
value|20
end_define

begin_define
define|#
directive|define
name|NWS821
value|21
end_define

begin_define
define|#
directive|define
name|NWS1760
value|22
end_define

begin_define
define|#
directive|define
name|NWS1710
value|23
end_define

begin_define
define|#
directive|define
name|NWS830
value|30
end_define

begin_define
define|#
directive|define
name|NWS831
value|31
end_define

begin_define
define|#
directive|define
name|NWS841
value|41
end_define

begin_define
define|#
directive|define
name|PWS1570
value|52
end_define

begin_define
define|#
directive|define
name|PWS1590
value|54
end_define

begin_define
define|#
directive|define
name|NWS1520
value|56
end_define

begin_define
define|#
directive|define
name|PWS1550
value|73
end_define

begin_define
define|#
directive|define
name|PWS1520
value|74
end_define

begin_define
define|#
directive|define
name|PWS1560
value|75
end_define

begin_define
define|#
directive|define
name|NWS1530
value|76
end_define

begin_define
define|#
directive|define
name|NWS1580
value|77
end_define

begin_define
define|#
directive|define
name|NWS1510
value|78
end_define

begin_define
define|#
directive|define
name|NWS1410
value|81
end_define

begin_define
define|#
directive|define
name|NWS1450
value|85
end_define

begin_define
define|#
directive|define
name|NWS1460
value|86
end_define

begin_define
define|#
directive|define
name|NWS891
value|91
end_define

begin_define
define|#
directive|define
name|NWS911
value|111
end_define

begin_define
define|#
directive|define
name|NWS921
value|121
end_define

begin_define
define|#
directive|define
name|NWB235
value|235
end_define

begin_define
define|#
directive|define
name|NWB235A
value|236
end_define

begin_define
define|#
directive|define
name|NWXRES
value|255
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|mips
end_ifdef

begin_define
define|#
directive|define
name|MACHID_MODEL
parameter_list|(
name|X
parameter_list|)
value|(((X)>>18)&0x1f)
end_define

begin_define
define|#
directive|define
name|MACHID_SERIAL
parameter_list|(
name|X
parameter_list|)
value|((X)&0x3ffff)
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* mips */
end_comment

begin_define
define|#
directive|define
name|MACHID_MODEL
parameter_list|(
name|X
parameter_list|)
value|(((X)>>16)&0xff)
end_define

begin_define
define|#
directive|define
name|MACHID_SERIAL
parameter_list|(
name|X
parameter_list|)
value|((X)&0xffff)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* mips */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|LOCORE
end_ifndef

begin_comment
comment|/*  * MPU board id number definition.  */
end_comment

begin_define
define|#
directive|define
name|MPU0
value|0
end_define

begin_comment
comment|/* not used */
end_comment

begin_define
define|#
directive|define
name|MPU1
value|1
end_define

begin_comment
comment|/* ICKI */
end_comment

begin_define
define|#
directive|define
name|MPU2
value|2
end_define

begin_comment
comment|/* 799/801/810/811/820/821 */
end_comment

begin_define
define|#
directive|define
name|MPU3
value|3
end_define

begin_comment
comment|/* 802/830/841/911/921 */
end_comment

begin_define
define|#
directive|define
name|MPU4
value|4
end_define

begin_comment
comment|/* 711 */
end_comment

begin_define
define|#
directive|define
name|MPU5
value|5
end_define

begin_comment
comment|/* 1830/1850/1860/1930/1960 */
end_comment

begin_define
define|#
directive|define
name|MPU6
value|6
end_define

begin_comment
comment|/* 712/721 */
end_comment

begin_define
define|#
directive|define
name|MPU7
value|7
end_define

begin_comment
comment|/* 14XX/15XX */
end_comment

begin_define
define|#
directive|define
name|MPU8
value|8
end_define

begin_comment
comment|/* 16XX/17XX */
end_comment

begin_define
define|#
directive|define
name|MPU9
value|9
end_define

begin_comment
comment|/*  */
end_comment

begin_struct
struct|struct
name|machid
block|{
comment|/*00*/
name|u_short
name|m_pwb
decl_stmt|;
comment|/* MPU board number */
comment|/*02*/
name|u_short
name|m_model
decl_stmt|;
comment|/* MPU dependent model code */
comment|/*04*/
name|u_int
name|m_serial
decl_stmt|;
comment|/* machine serial number */
comment|/*08*/
name|u_int
name|m_reserve0
decl_stmt|;
comment|/*0c*/
name|u_int
name|m_reserve1
decl_stmt|;
comment|/*10*/
block|}
struct|;
end_struct

begin_union
union|union
name|omachid
block|{
comment|/*00*/
struct|struct
name|om_field
block|{
name|u_int
name|fi_reserve
range|:
literal|2
decl_stmt|,
name|fi_pwb
range|:
literal|7
decl_stmt|,
comment|/* MPU (printed wired) board number */
name|fi_model
range|:
literal|5
decl_stmt|,
comment|/* MPU dependent model code */
name|fi_serial
range|:
literal|18
decl_stmt|;
comment|/* machine serial number */
block|}
name|om_fi
struct|;
comment|/*00*/
name|u_int
name|om_data
decl_stmt|;
comment|/*04*/
block|}
union|;
end_union

begin_struct
struct|struct
name|machine_type
block|{
comment|/*00*/
name|int
name|m_model_id
decl_stmt|;
comment|/*04*/
name|char
modifier|*
name|m_model_name
decl_stmt|;
comment|/*08*/
name|char
modifier|*
name|m_machine_name
decl_stmt|;
comment|/*0c*/
name|char
modifier|*
name|m_maincpu
decl_stmt|;
comment|/*10*/
name|char
modifier|*
name|m_subcpu
decl_stmt|;
comment|/*14*/
name|char
modifier|*
name|m_fpa
decl_stmt|;
comment|/*18*/
name|int
name|m_board_id
decl_stmt|;
comment|/*1c*/
name|int
name|m_cachecntl
decl_stmt|;
comment|/*20*/
name|int
name|m_maxusers
decl_stmt|;
comment|/* not used */
comment|/*24*/
name|int
name|m_dcachesize
decl_stmt|;
comment|/* not used */
comment|/*28*/
name|int
name|m_icachesize
decl_stmt|;
comment|/* not used */
comment|/*2c*/
block|}
struct|;
end_struct

begin_if
if|#
directive|if
name|defined
argument_list|(
name|news700
argument_list|)
operator|||
name|defined
argument_list|(
name|news800
argument_list|)
operator|||
name|defined
argument_list|(
name|news1700
argument_list|)
operator|||
name|defined
argument_list|(
name|news1800
argument_list|)
end_if

begin_struct
struct|struct
name|idrom
block|{
comment|/*00*/
name|unsigned
name|char
name|id_model
decl_stmt|;
comment|/*01*/
name|unsigned
name|char
name|id_serial
index|[
literal|2
index|]
decl_stmt|;
comment|/*03*/
name|unsigned
name|char
name|id_lot
decl_stmt|;
comment|/*04*/
name|unsigned
name|char
name|id_reserved
index|[
literal|2
index|]
decl_stmt|;
comment|/*06*/
name|unsigned
name|char
name|id_chksum0
index|[
literal|2
index|]
decl_stmt|;
comment|/*08*/
name|unsigned
name|char
name|id_ether
index|[
literal|6
index|]
decl_stmt|;
comment|/*0e*/
name|unsigned
name|char
name|id_chksum1
index|[
literal|2
index|]
decl_stmt|;
comment|/*10*/
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* news700 || news800 || news1700 || news1800 */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|news1200
argument_list|)
operator|||
name|defined
argument_list|(
name|news3400
argument_list|)
operator|||
name|defined
argument_list|(
name|news3800
argument_list|)
end_if

begin_struct
struct|struct
name|idrom
block|{
comment|/*00*/
name|unsigned
name|char
name|id_id
decl_stmt|;
comment|/* always 0xff */
comment|/*01*/
name|unsigned
name|char
name|id_netid
index|[
literal|5
index|]
decl_stmt|;
comment|/* network ID */
comment|/*06*/
name|unsigned
name|short
name|id_csum1
decl_stmt|;
comment|/* checksum 1 */
comment|/*08*/
name|unsigned
name|char
name|id_macadrs
index|[
literal|6
index|]
decl_stmt|;
comment|/* MAC (ethernet) address */
comment|/*0e*/
name|unsigned
name|short
name|id_csum2
decl_stmt|;
comment|/* checksum 2 */
comment|/*10*/
name|unsigned
name|short
name|id_boardid
decl_stmt|;
comment|/* CPU board ID */
comment|/*12*/
name|unsigned
name|short
name|id_modelid
decl_stmt|;
comment|/* model ID */
comment|/*14*/
name|unsigned
name|int
name|id_serial
decl_stmt|;
comment|/* serial number */
comment|/*18*/
name|unsigned
name|short
name|id_year
decl_stmt|;
comment|/*1a*/
name|unsigned
name|short
name|id_month
decl_stmt|;
comment|/*1c*/
name|unsigned
name|char
name|id_zone
index|[
literal|4
index|]
decl_stmt|;
comment|/*20*/
name|char
name|id_board
index|[
literal|16
index|]
decl_stmt|;
comment|/*30*/
name|char
name|id_model
index|[
literal|16
index|]
decl_stmt|;
comment|/*40*/
name|char
name|id_machine
index|[
literal|16
index|]
decl_stmt|;
comment|/*50*/
name|char
name|id_cpu
index|[
literal|16
index|]
decl_stmt|;
comment|/*60*/
name|char
name|id_iop
index|[
literal|16
index|]
decl_stmt|;
comment|/*70*/
name|unsigned
name|char
name|id_reserved
index|[
literal|12
index|]
decl_stmt|;
comment|/*7c*/
name|unsigned
name|int
name|id_csum3
decl_stmt|;
comment|/*80*/
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* news1200 || news3400 || news3800 */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !LOCORE */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __MACHID__ */
end_comment

end_unit

