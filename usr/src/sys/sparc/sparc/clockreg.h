begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1992 The Regents of the University of California.  * All rights reserved.  *  * This software was developed by the Computer Systems Engineering group  * at Lawrence Berkeley Laboratory under DARPA contract BG 91-66 and  * contributed to Berkeley.  *  * All advertising materials mentioning features or use of this software  * must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Lawrence Berkeley Laboratory.  *  * %sccs.include.redist.c%  *  *	@(#)clockreg.h	7.3 (Berkeley) %G%  *  * from: $Header: clockreg.h,v 1.6 92/11/26 03:04:48 torek Exp $ (LBL)  */
end_comment

begin_comment
comment|/*  * Sun-4c clock Mostek TOD clock.  This includes the ``id prom''.  */
end_comment

begin_comment
comment|/*  * ID prom format.  The ``host id'' is set up by taking the machine  * ID as the top byte and the hostid field as the remaining three.  * The id_xxx0 field appears to contain some other number.  The id_xxx1  * contains a bunch of 00's and a5's on my machines, suggesting it is  * not actually used.  The checksum seems to include them, however.  */
end_comment

begin_struct
struct|struct
name|sun4c_idprom
block|{
name|u_char
name|id_format
decl_stmt|;
comment|/* format identifier (= 1) */
name|u_char
name|id_machine
decl_stmt|;
comment|/* machine type (see cpu.h) */
name|u_char
name|id_ether
index|[
literal|6
index|]
decl_stmt|;
comment|/* ethernet address */
name|long
name|id_xxx0
decl_stmt|;
comment|/* ??? */
name|u_char
name|id_hostid
index|[
literal|3
index|]
decl_stmt|;
comment|/* ``host id'' bytes */
name|u_char
name|id_checksum
decl_stmt|;
comment|/* xor of everything else */
name|char
name|id_xxx1
index|[
literal|16
index|]
decl_stmt|;
comment|/* ??? */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Mostek MK48T02 clock.  *  * The clock includes 2040 bytes of RAM, the last 32 of which serve to  * identify the kind of Sun 4c this is.  */
end_comment

begin_struct
struct|struct
name|clockreg
block|{
name|char
name|cl_nvram
index|[
literal|2008
index|]
decl_stmt|;
comment|/* `free' nonvolatile memory */
name|struct
name|sun4c_idprom
name|cl_idprom
decl_stmt|;
comment|/* `id prom' */
specifier|volatile
name|u_char
name|cl_csr
decl_stmt|;
comment|/* control register */
specifier|volatile
name|u_char
name|cl_sec
decl_stmt|;
comment|/* seconds (0..59; BCD) */
specifier|volatile
name|u_char
name|cl_min
decl_stmt|;
comment|/* minutes (0..59; BCD) */
specifier|volatile
name|u_char
name|cl_hour
decl_stmt|;
comment|/* hour (0..23; BCD) */
specifier|volatile
name|u_char
name|cl_wday
decl_stmt|;
comment|/* weekday (1..7) */
specifier|volatile
name|u_char
name|cl_mday
decl_stmt|;
comment|/* day in month (1..31; BCD) */
specifier|volatile
name|u_char
name|cl_month
decl_stmt|;
comment|/* month (1..12; BCD) */
specifier|volatile
name|u_char
name|cl_year
decl_stmt|;
comment|/* year (0..99; BCD) */
block|}
struct|;
end_struct

begin_comment
comment|/* bits in cl_csr */
end_comment

begin_define
define|#
directive|define
name|CLK_WRITE
value|0x80
end_define

begin_comment
comment|/* want to write */
end_comment

begin_define
define|#
directive|define
name|CLK_READ
value|0x40
end_define

begin_comment
comment|/* want to read (freeze clock) */
end_comment

begin_decl_stmt
name|struct
name|clockreg
modifier|*
name|clockreg
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * Sun chose the year `68' as their base count, so that  * cl_year==0 means 1968.  */
end_comment

begin_define
define|#
directive|define
name|YEAR0
value|68
end_define

end_unit

