begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1982, 1986, 1988 Regents of the University of California.  * All rights reserved.  The Berkeley software License Agreement  * specifies the terms and conditions for redistribution.  *  *	@(#)savax.h	7.5 (Berkeley) 7/9/88  */
end_comment

begin_comment
comment|/*  * Standalone definitions peculiar to vaxen:  *  * The mba devices in the standalone system are addressed as  *	type(mba, 0, drive, partition)		(disks)  *	type(mba, formatter, transport, file)	(tapes)  *  * The mbadrv macro gives the address of the device registers  * for the specified unit.  *  * The uba devices in the standalone system are addressed as  *	type(uba, ctlr, drive, partition)	(disks)  *	type(uba, formatter, transport, file)	(tapes)  *  * The ubamem macro converts a specified unibus address (ala pdp-11)  * into a unibus memory address space address.  */
end_comment

begin_define
define|#
directive|define
name|mbadrv
parameter_list|(
name|mba
parameter_list|,
name|unit
parameter_list|)
value|(&mbamba(mba)->mba_drv[unit])
end_define

begin_comment
comment|/* compute an I/O page physical address from a 16/18/22-bit bus address */
end_comment

begin_define
define|#
directive|define
name|ubamem
parameter_list|(
name|uba
parameter_list|,
name|off
parameter_list|)
value|(uioaddr[uba] + ubdevreg(off))
end_define

begin_define
define|#
directive|define
name|mbamba
parameter_list|(
name|mba
parameter_list|)
value|(mbaddr[mba])
end_define

begin_define
define|#
directive|define
name|ubauba
parameter_list|(
name|uba
parameter_list|)
value|(ubaddr[uba])
end_define

begin_define
define|#
directive|define
name|MAXNMBA
value|8
end_define

begin_define
define|#
directive|define
name|MAXNUBA
value|8
end_define

begin_define
define|#
directive|define
name|MAXNKDB
value|2
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
name|int
name|nmba
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|caddr_t
modifier|*
name|uioaddr
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

begin_decl_stmt
name|int
name|nuba
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|VAX8200
end_ifdef

begin_decl_stmt
name|caddr_t
name|kdbaddr
index|[
name|MAXNKDB
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|nkdb
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
name|int
name|cpu
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* see ../vax/cpu.h */
end_comment

end_unit

