begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1988 University of Utah.  * Copyright (c) 1990 The Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * the Systems Programming Group of the University of Utah Computer  * Science Department.  *  * %sccs.include.redist.c%  *  * from: Utah $Hdr: grfvar.h 1.8 89/01/18$  *  *	@(#)grfvar.h	7.1 (Berkeley) %G%  */
end_comment

begin_define
define|#
directive|define
name|GRFMAXLCK
value|256
end_define

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
name|int
name|g_type
decl_stmt|;
comment|/* type of display */
name|struct
name|grfinfo
name|g_display
decl_stmt|;
comment|/* hardware description */
name|struct
name|proc
modifier|*
name|g_lockp
decl_stmt|;
comment|/* process holding lock */
name|int
name|g_lockpslot
decl_stmt|;
comment|/* g_pid entry of g_lockp */
name|u_char
modifier|*
name|g_locks
decl_stmt|;
comment|/* lock page associated with device */
name|short
modifier|*
name|g_pid
decl_stmt|;
comment|/* array of pids with device open */
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
comment|/* display types - indices into grfdev */
end_comment

begin_define
define|#
directive|define
name|GT_TOPCAT
value|0
end_define

begin_define
define|#
directive|define
name|GT_GATORBOX
value|1
end_define

begin_define
define|#
directive|define
name|GT_RENAISSANCE
value|2
end_define

begin_define
define|#
directive|define
name|GT_LRCATSEYE
value|3
end_define

begin_define
define|#
directive|define
name|GT_HRCCATSEYE
value|4
end_define

begin_define
define|#
directive|define
name|GT_HRMCATSEYE
value|5
end_define

begin_define
define|#
directive|define
name|GT_DAVINCI
value|6
end_define

begin_struct
struct|struct
name|grfdev
block|{
name|int
name|gd_hardid
decl_stmt|;
comment|/* secondary id returned by hardware */
name|int
name|gd_softid
decl_stmt|;
comment|/* id returned by HP-UX */
name|int
function_decl|(
modifier|*
name|gd_init
function_decl|)
parameter_list|()
function_decl|;
comment|/* boot time initialization */
name|int
function_decl|(
modifier|*
name|gd_mode
function_decl|)
parameter_list|()
function_decl|;
comment|/* misc functions */
name|char
modifier|*
name|gd_desc
decl_stmt|;
comment|/* text description */
block|}
struct|;
end_struct

begin_comment
comment|/* hardware ids */
end_comment

begin_define
define|#
directive|define
name|GID_GATORBOX
value|1
end_define

begin_define
define|#
directive|define
name|GID_TOPCAT
value|2
end_define

begin_define
define|#
directive|define
name|GID_RENAISSANCE
value|4
end_define

begin_define
define|#
directive|define
name|GID_LRCATSEYE
value|5
end_define

begin_define
define|#
directive|define
name|GID_HRCCATSEYE
value|6
end_define

begin_define
define|#
directive|define
name|GID_HRMCATSEYE
value|7
end_define

begin_define
define|#
directive|define
name|GID_DAVINCI
value|8
end_define

begin_comment
comment|/* software ids defined in grfioctl.h */
end_comment

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

begin_struct
struct|struct
name|grfreg
block|{
name|char
name|gr_pad0
decl_stmt|;
name|u_char
name|gr_id
decl_stmt|;
comment|/* +0x01 */
name|char
name|gr_pad1
index|[
literal|0x13
index|]
decl_stmt|;
name|u_char
name|gr_id2
decl_stmt|;
comment|/* +0x15 */
name|char
name|gr_pad2
index|[
literal|0x47
index|]
decl_stmt|;
name|u_char
name|gr_fbomsb
decl_stmt|;
comment|/* +0x5d */
name|char
name|gr_pad3
decl_stmt|;
name|u_char
name|gr_fbolsb
decl_stmt|;
comment|/* +0x5f */
block|}
struct|;
end_struct

begin_comment
comment|/* bitmapped display hardware id */
end_comment

begin_define
define|#
directive|define
name|GRFHWID
value|0x39
end_define

begin_comment
comment|/* internal bitmapped display address */
end_comment

begin_define
define|#
directive|define
name|GRFIADDR
value|0x560000
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

begin_endif
endif|#
directive|endif
end_endif

end_unit

