begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1982, 1990 The Regents of the University of California.  * All rights reserved.  *  * %sccs.include.redist.c%  *  *	@(#)hpibvar.h	7.1 (Berkeley) %G%  */
end_comment

begin_define
define|#
directive|define
name|HPIBA
value|32
end_define

begin_define
define|#
directive|define
name|HPIBB
value|1
end_define

begin_define
define|#
directive|define
name|HPIBC
value|8
end_define

begin_define
define|#
directive|define
name|HPIBA_BA
value|21
end_define

begin_define
define|#
directive|define
name|HPIBC_BA
value|30
end_define

begin_define
define|#
directive|define
name|CSA_BA
value|0x1F
end_define

begin_define
define|#
directive|define
name|C_DCL
value|20
end_define

begin_define
define|#
directive|define
name|C_LAG
value|32
end_define

begin_define
define|#
directive|define
name|C_UNL
value|63
end_define

begin_define
define|#
directive|define
name|C_TAG
value|64
end_define

begin_define
define|#
directive|define
name|C_UNA
value|94
end_define

begin_define
define|#
directive|define
name|C_UNT
value|95
end_define

begin_define
define|#
directive|define
name|C_SCG
value|96
end_define

begin_struct
struct|struct
name|hpib_softc
block|{
name|char
name|sc_alive
decl_stmt|;
name|char
name|sc_type
decl_stmt|;
name|int
name|sc_ba
decl_stmt|;
name|char
modifier|*
name|sc_addr
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|struct
name|hpib_softc
name|hpib_softc
index|[]
decl_stmt|;
end_decl_stmt

end_unit

