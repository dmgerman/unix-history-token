begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1982, 1990 The Regents of the University of California.  * All rights reserved.  *  * %sccs.include.redist.c%  *  *	@(#)hpibvar.h	7.1 (Berkeley) %G%  */
end_comment

begin_define
define|#
directive|define
name|HPIB_IPL
parameter_list|(
name|x
parameter_list|)
value|((((x)>> 4)& 0x3) + 3)
end_define

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
name|HPIBA_IPL
value|3
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
name|IDS_WDMA
value|0x04
end_define

begin_define
define|#
directive|define
name|IDS_WRITE
value|0x08
end_define

begin_define
define|#
directive|define
name|IDS_IR
value|0x40
end_define

begin_define
define|#
directive|define
name|IDS_IE
value|0x80
end_define

begin_define
define|#
directive|define
name|IDS_DMA
parameter_list|(
name|x
parameter_list|)
value|(1<< (x))
end_define

begin_define
define|#
directive|define
name|C_DCL
value|0x14
end_define

begin_define
define|#
directive|define
name|C_LAG
value|0x20
end_define

begin_define
define|#
directive|define
name|C_UNL
value|0x3f
end_define

begin_define
define|#
directive|define
name|C_TAG
value|0x40
end_define

begin_define
define|#
directive|define
name|C_UNA
value|0x5e
end_define

begin_define
define|#
directive|define
name|C_UNT
value|0x5f
end_define

begin_define
define|#
directive|define
name|C_SCG
value|0x60
end_define

begin_struct
struct|struct
name|hpib_softc
block|{
name|struct
name|hp_ctlr
modifier|*
name|sc_hc
decl_stmt|;
name|int
name|sc_flags
decl_stmt|;
name|struct
name|devqueue
name|sc_dq
decl_stmt|;
name|struct
name|devqueue
name|sc_sq
decl_stmt|;
name|int
name|sc_ba
decl_stmt|;
name|int
name|sc_type
decl_stmt|;
name|char
modifier|*
name|sc_addr
decl_stmt|;
name|int
name|sc_count
decl_stmt|;
name|int
name|sc_curcnt
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* sc_flags */
end_comment

begin_define
define|#
directive|define
name|HPIBF_IO
value|0x1
end_define

begin_define
define|#
directive|define
name|HPIBF_DONE
value|0x2
end_define

begin_define
define|#
directive|define
name|HPIBF_PPOLL
value|0x4
end_define

begin_define
define|#
directive|define
name|HPIBF_READ
value|0x8
end_define

begin_define
define|#
directive|define
name|HPIBF_DMA16
value|0x8000
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|KERNEL
end_ifdef

begin_decl_stmt
specifier|extern
name|struct
name|hpib_softc
name|hpib_softc
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|internalhpib
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

