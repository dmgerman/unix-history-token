begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1982, 1990 The Regents of the University of California.  * All rights reserved.  *  * %sccs.include.redist.c%  *  *	@(#)samachdep.h	7.4 (Berkeley) %G%  */
end_comment

begin_define
define|#
directive|define
name|NHPIB
value|4
end_define

begin_define
define|#
directive|define
name|NSCSI
value|2
end_define

begin_define
define|#
directive|define
name|NRD
value|8
end_define

begin_define
define|#
directive|define
name|NCT
value|8
end_define

begin_define
define|#
directive|define
name|NSD
value|8
end_define

begin_define
define|#
directive|define
name|NITE
value|4
end_define

begin_comment
comment|/* from cpu.h */
end_comment

begin_define
define|#
directive|define
name|IIOV
parameter_list|(
name|x
parameter_list|)
value|(x)
end_define

begin_define
define|#
directive|define
name|DIOBASE
value|(0x600000)
end_define

begin_define
define|#
directive|define
name|DIOCSIZE
value|(0x10000)
end_define

begin_define
define|#
directive|define
name|DIOIIBASE
value|(0x01000000)
end_define

begin_define
define|#
directive|define
name|DIOIICSIZE
value|(0x00400000)
end_define

begin_define
define|#
directive|define
name|HP_320
value|0
end_define

begin_comment
comment|/* 16Mhz 68020+HP MMU+16K external cache */
end_comment

begin_define
define|#
directive|define
name|HP_330
value|1
end_define

begin_comment
comment|/* 16Mhz 68020+68851 MMU */
end_comment

begin_define
define|#
directive|define
name|HP_350
value|2
end_define

begin_comment
comment|/* 25Mhz 68020+HP MMU+32K external cache */
end_comment

begin_define
define|#
directive|define
name|HP_360
value|3
end_define

begin_comment
comment|/* 25Mhz 68030 */
end_comment

begin_define
define|#
directive|define
name|HP_370
value|4
end_define

begin_comment
comment|/* 33Mhz 68030+64K external cache */
end_comment

begin_define
define|#
directive|define
name|HP_340
value|5
end_define

begin_comment
comment|/* 16Mhz 68030 */
end_comment

begin_define
define|#
directive|define
name|HP_375
value|6
end_define

begin_comment
comment|/* 50Mhz 68030+32K external cache */
end_comment

begin_define
define|#
directive|define
name|HP_380
value|7
end_define

begin_comment
comment|/* 25Mhz 68040 */
end_comment

begin_define
define|#
directive|define
name|HP_433
value|8
end_define

begin_comment
comment|/* 33Mhz 68040 */
end_comment

begin_define
define|#
directive|define
name|MHZ_8
value|1
end_define

begin_define
define|#
directive|define
name|MHZ_16
value|2
end_define

begin_define
define|#
directive|define
name|MHZ_25
value|3
end_define

begin_define
define|#
directive|define
name|MHZ_33
value|4
end_define

begin_define
define|#
directive|define
name|MHZ_50
value|6
end_define

begin_decl_stmt
specifier|extern
name|int
name|cpuspeed
decl_stmt|,
name|machineid
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|howto
decl_stmt|,
name|bootdev
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* bogon grfinfo structure to keep grf_softc happy */
end_comment

begin_struct
struct|struct
name|grfinfo
block|{
name|int
name|grf_foo
decl_stmt|;
block|}
struct|;
end_struct

end_unit

