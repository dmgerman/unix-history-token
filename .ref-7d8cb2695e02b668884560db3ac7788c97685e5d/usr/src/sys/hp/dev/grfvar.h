begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1988 University of Utah.  * Copyright (c) 1990 The Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * the Systems Programming Group of the University of Utah Computer  * Science Department.  *  * %sccs.include.redist.c%  *  * from: Utah $Hdr: grfvar.h 1.10 92/01/21$  *  *	@(#)grfvar.h	7.4 (Berkeley) %G%  */
end_comment

begin_comment
comment|/* internal structure of lock page */
end_comment

begin_define
define|#
directive|define
name|GRFMAXLCK
value|256
end_define

begin_struct
struct|struct
name|grf_lockpage
block|{
name|u_char
name|gl_locks
index|[
name|GRFMAXLCK
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|gl_lockslot
value|gl_locks[0]
end_define

begin_comment
comment|/*  * Static configuration info for display types  */
end_comment

begin_struct
struct|struct
name|grfsw
block|{
name|int
name|gd_hwid
decl_stmt|;
comment|/* id returned by hardware */
name|int
name|gd_swid
decl_stmt|;
comment|/* id to be returned by software */
name|char
modifier|*
name|gd_desc
decl_stmt|;
comment|/* description printed at config time */
name|int
function_decl|(
modifier|*
name|gd_init
function_decl|)
parameter_list|()
function_decl|;
comment|/* boot time init routine */
name|int
function_decl|(
modifier|*
name|gd_mode
function_decl|)
parameter_list|()
function_decl|;
comment|/* misc function routine */
block|}
struct|;
end_struct

begin_comment
comment|/* per display info */
end_comment

begin_struct
struct|struct
name|grf_softc
block|{
name|int
name|g_flags
decl_stmt|;
comment|/* software flags */
name|struct
name|grfsw
modifier|*
name|g_sw
decl_stmt|;
comment|/* static configuration info */
name|caddr_t
name|g_regkva
decl_stmt|;
comment|/* KVA of registers */
name|caddr_t
name|g_fbkva
decl_stmt|;
comment|/* KVA of framebuffer */
name|struct
name|grfinfo
name|g_display
decl_stmt|;
comment|/* hardware description (for ioctl) */
name|struct
name|grf_lockpage
modifier|*
name|g_lock
decl_stmt|;
comment|/* lock page associated with device */
name|struct
name|proc
modifier|*
name|g_lockp
decl_stmt|;
comment|/* process holding lock */
name|short
modifier|*
name|g_pid
decl_stmt|;
comment|/* array of pids with device open */
name|int
name|g_lockpslot
decl_stmt|;
comment|/* g_pid entry of g_lockp */
name|caddr_t
name|g_data
decl_stmt|;
comment|/* device dependent data */
block|}
struct|;
end_struct

begin_comment
comment|/* flags */
end_comment

begin_define
define|#
directive|define
name|GF_ALIVE
value|0x01
end_define

begin_define
define|#
directive|define
name|GF_OPEN
value|0x02
end_define

begin_define
define|#
directive|define
name|GF_EXCLUDE
value|0x04
end_define

begin_define
define|#
directive|define
name|GF_WANTED
value|0x08
end_define

begin_define
define|#
directive|define
name|GF_BSDOPEN
value|0x10
end_define

begin_define
define|#
directive|define
name|GF_HPUXOPEN
value|0x20
end_define

begin_comment
comment|/* requests to mode routine */
end_comment

begin_define
define|#
directive|define
name|GM_GRFON
value|1
end_define

begin_define
define|#
directive|define
name|GM_GRFOFF
value|2
end_define

begin_define
define|#
directive|define
name|GM_GRFOVON
value|3
end_define

begin_define
define|#
directive|define
name|GM_GRFOVOFF
value|4
end_define

begin_define
define|#
directive|define
name|GM_DESCRIBE
value|5
end_define

begin_comment
comment|/* minor device interpretation */
end_comment

begin_define
define|#
directive|define
name|GRFOVDEV
value|0x10
end_define

begin_comment
comment|/* overlay planes */
end_comment

begin_define
define|#
directive|define
name|GRFIMDEV
value|0x20
end_define

begin_comment
comment|/* images planes */
end_comment

begin_define
define|#
directive|define
name|GRFUNIT
parameter_list|(
name|d
parameter_list|)
value|((d)& 0x7)
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|KERNEL
end_ifdef

begin_decl_stmt
specifier|extern
name|struct
name|grf_softc
name|grf_softc
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|grfsw
name|grfsw
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|ngrfsw
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

