begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1982, 1986 Regents of the University of California.  * All rights reserved.  The Berkeley software License Agreement  * specifies the terms and conditions for redistribution.  *  *	@(#)savax.h	7.1 (Berkeley) 6/5/86  */
end_comment

begin_comment
comment|/*  * Standalone definitions peculiar to vaxen  * The mba devices in the standalone system are addressed as   *	xx(unit,section)  * where unit is  *	8*mbanum+drive  * The mbadrv macro gives the address of the device registers  * for the specified unit; the mbamba macro gives the address of the  * mba registers themselves.  *  * The uba devices are also addressed by giving, as unit,  *	8*ubanum+drive  * The ubamem macro converts a specified unibus address (ala pdp-11)  * into a unibus memory address space address.  */
end_comment

begin_decl_stmt
name|int
name|cpu
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* see<sys/cpu.h> */
end_comment

begin_define
define|#
directive|define
name|MAXNMBA
value|4
end_define

begin_define
define|#
directive|define
name|MAXNUBA
value|4
end_define

begin_decl_stmt
name|struct
name|mba_regs
modifier|*
modifier|*
name|mbaddr
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|mbaact
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|caddr_t
modifier|*
name|umaddr
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|uba_regs
modifier|*
modifier|*
name|ubaddr
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|UNITTOMBA
parameter_list|(
name|unit
parameter_list|)
value|((unit)>>3)
end_define

begin_define
define|#
directive|define
name|UNITTODRIVE
parameter_list|(
name|unit
parameter_list|)
value|((unit)&07)
end_define

begin_define
define|#
directive|define
name|mbamba
parameter_list|(
name|unit
parameter_list|)
value|(mbaddr[UNITTOMBA(unit)])
end_define

begin_define
define|#
directive|define
name|mbadrv
parameter_list|(
name|unit
parameter_list|)
value|(&mbamba(unit)->mba_drv[UNITTODRIVE(unit)])
end_define

begin_define
define|#
directive|define
name|UNITTOUBA
parameter_list|(
name|unit
parameter_list|)
value|((unit)>>3)
end_define

begin_define
define|#
directive|define
name|ubauba
parameter_list|(
name|unit
parameter_list|)
value|(ubaddr[UNITTOUBA(unit)])
end_define

begin_define
define|#
directive|define
name|ubamem
parameter_list|(
name|unit
parameter_list|,
name|off
parameter_list|)
value|((umaddr[UNITTOUBA(unit)]+ubdevreg(off)))
end_define

begin_define
define|#
directive|define
name|PHYSUBA0
value|0x20006000
end_define

begin_define
define|#
directive|define
name|PHYSMBA0
value|0x20010000
end_define

begin_define
define|#
directive|define
name|PHYSMBA1
value|0x20012000
end_define

begin_define
define|#
directive|define
name|PHYSUMEM
value|0x2013e000
end_define

begin_comment
comment|/*  * RM03/5 (4-byte header plus CRC) format information:  * codes for sector header word 1  */
end_comment

begin_define
define|#
directive|define
name|HDR1_FMT22
value|0x1000
end_define

begin_comment
comment|/* standard 16 bit format */
end_comment

begin_define
define|#
directive|define
name|HDR1_OKSCT
value|0xc000
end_define

begin_comment
comment|/* sector ok */
end_comment

begin_define
define|#
directive|define
name|HDR1_SSF
value|0x2000
end_define

begin_comment
comment|/* skip sector flag */
end_comment

end_unit

