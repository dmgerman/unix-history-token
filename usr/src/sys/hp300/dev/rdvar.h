begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1988 University of Utah.  * Copyright (c) 1982, 1990 The Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * the Systems Programming Group of the University of Utah Computer  * Science Department.  *  * %sccs.include.redist.c%  *  * from: Utah $Hdr: rdvar.h 1.1 92/12/21$  *  *	@(#)rdvar.h	7.1 (Berkeley) %G%  */
end_comment

begin_struct
struct|struct
name|rdidentinfo
block|{
name|short
name|ri_hwid
decl_stmt|;
comment|/* 2 byte HW id */
name|short
name|ri_maxunum
decl_stmt|;
comment|/* maximum allowed unit number */
name|char
modifier|*
name|ri_desc
decl_stmt|;
comment|/* drive type description */
name|int
name|ri_nblocks
decl_stmt|;
comment|/* DEV_BSIZE blocks on disk */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|rdinfo
block|{
name|struct
name|disklabel
name|ri_label
decl_stmt|;
comment|/* label */
name|int
name|ri_bopen
decl_stmt|;
comment|/* mask of open block devs */
name|int
name|ri_copen
decl_stmt|;
comment|/* mask of open char devs */
name|int
name|ri_open
decl_stmt|;
comment|/* composite mask of open devs */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|rd_softc
block|{
name|struct
name|hp_device
modifier|*
name|sc_hd
decl_stmt|;
name|int
name|sc_flags
decl_stmt|;
name|short
name|sc_type
decl_stmt|;
name|short
name|sc_punit
decl_stmt|;
name|char
modifier|*
name|sc_addr
decl_stmt|;
name|int
name|sc_resid
decl_stmt|;
name|u_int
name|sc_wpms
decl_stmt|;
name|struct
name|rdinfo
name|sc_info
decl_stmt|;
name|struct
name|devqueue
name|sc_dq
decl_stmt|;
name|struct
name|rd_iocmd
name|sc_ioc
decl_stmt|;
name|struct
name|rd_rscmd
name|sc_rsc
decl_stmt|;
name|struct
name|rd_stat
name|sc_stat
decl_stmt|;
name|struct
name|rd_ssmcmd
name|sc_ssmc
decl_stmt|;
name|struct
name|rd_srcmd
name|sc_src
decl_stmt|;
name|struct
name|rd_clearcmd
name|sc_clear
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* sc_flags values */
end_comment

begin_define
define|#
directive|define
name|RDF_ALIVE
value|0x01
end_define

begin_define
define|#
directive|define
name|RDF_SEEK
value|0x02
end_define

begin_define
define|#
directive|define
name|RDF_SWAIT
value|0x04
end_define

begin_define
define|#
directive|define
name|RDF_OPENING
value|0x08
end_define

begin_define
define|#
directive|define
name|RDF_CLOSING
value|0x10
end_define

begin_define
define|#
directive|define
name|RDF_WANTED
value|0x20
end_define

begin_define
define|#
directive|define
name|RDF_WLABEL
value|0x40
end_define

begin_struct
struct|struct
name|rdstats
block|{
name|long
name|rdretries
decl_stmt|;
name|long
name|rdresets
decl_stmt|;
name|long
name|rdtimeouts
decl_stmt|;
name|long
name|rdpolltries
decl_stmt|;
name|long
name|rdpollwaits
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|rdunit
parameter_list|(
name|x
parameter_list|)
value|(minor(x)>> 3)
end_define

begin_define
define|#
directive|define
name|rdpart
parameter_list|(
name|x
parameter_list|)
value|(minor(x)& 0x7)
end_define

begin_define
define|#
directive|define
name|rdpunit
parameter_list|(
name|x
parameter_list|)
value|((x)& 7)
end_define

begin_define
define|#
directive|define
name|rdlabdev
parameter_list|(
name|d
parameter_list|)
value|(dev_t)(((int)(d)&~7)|2)
end_define

begin_comment
comment|/* rd?c */
end_comment

begin_define
define|#
directive|define
name|b_cylin
value|b_resid
end_define

begin_define
define|#
directive|define
name|RDRETRY
value|5
end_define

begin_define
define|#
directive|define
name|RDWAITC
value|1
end_define

begin_comment
comment|/* min time for timeout in seconds */
end_comment

end_unit

