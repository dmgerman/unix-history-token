begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1997, 1998  *	Nan Yang Computer Services Limited.  All rights reserved.  *  *  This software is distributed under the so-called ``Berkeley  *  License'':  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by Nan Yang Computer  *      Services Limited.  * 4. Neither the name of the Company nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * This software is provided ``as is'', and any express or implied  * warranties, including, but not limited to, the implied warranties of  * merchantability and fitness for a particular purpose are disclaimed.  * In no event shall the company or contributors be liable for any  * direct, indirect, incidental, special, exemplary, or consequential  * damages (including, but not limited to, procurement of substitute  * goods or services; loss of use, data, or profits; or business  * interruption) however caused and on any theory of liability, whether  * in contract, strict liability, or tort (including negligence or  * otherwise) arising in any way out of the use of this software, even if  * advised of the possibility of such damage.  */
end_comment

begin_comment
comment|/*  * $Id: vext.h,v 1.17 2000/05/07 04:17:12 grog Exp grog $  * $FreeBSD$  */
end_comment

begin_define
define|#
directive|define
name|MAXARGS
value|64
end_define

begin_comment
comment|/* maximum number of args on a line */
end_comment

begin_define
define|#
directive|define
name|PLEXINITSIZE
value|65536
end_define

begin_comment
comment|/* init in this size chunks */
end_comment

begin_define
define|#
directive|define
name|MAXPLEXINITSIZE
value|65536
end_define

begin_comment
comment|/* max chunk size to use for init */
end_comment

begin_define
define|#
directive|define
name|MAXDATETEXT
value|128
end_define

begin_comment
comment|/* date text in history (far too much) */
end_comment

begin_enum
enum|enum
block|{
name|KILOBYTE
init|=
literal|1024
block|,
name|MEGABYTE
init|=
literal|1048576
block|,
name|GIGABYTE
init|=
literal|1073741824
block|}
enum|;
end_enum

begin_define
define|#
directive|define
name|VINUMMOD
value|"vinum"
end_define

begin_define
define|#
directive|define
name|DEFAULT_HISTORYFILE
value|"/var/log/vinum_history"
end_define

begin_comment
comment|/* default name for history stuff */
end_comment

begin_comment
comment|/* Prototype declarations */
end_comment

begin_function_decl
name|void
name|parseline
parameter_list|(
name|int
name|c
parameter_list|,
name|char
modifier|*
name|args
index|[]
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* parse a line with c parameters at args */
end_comment

begin_function_decl
name|void
name|checkentry
parameter_list|(
name|int
name|index
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|haveargs
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* check arg, error message if not valid */
end_comment

begin_function_decl
name|void
name|setsigs
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|catchsig
parameter_list|(
name|int
name|ignore
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|vinum_create
parameter_list|(
name|int
name|argc
parameter_list|,
name|char
modifier|*
name|argv
index|[]
parameter_list|,
name|char
modifier|*
name|arg0
index|[]
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|vinum_read
parameter_list|(
name|int
name|argc
parameter_list|,
name|char
modifier|*
name|argv
index|[]
parameter_list|,
name|char
modifier|*
name|arg0
index|[]
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|vinum_modify
parameter_list|(
name|int
name|argc
parameter_list|,
name|char
modifier|*
name|argv
index|[]
parameter_list|,
name|char
modifier|*
name|arg0
index|[]
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|vinum_volume
parameter_list|(
name|int
name|argc
parameter_list|,
name|char
modifier|*
name|argv
index|[]
parameter_list|,
name|char
modifier|*
name|arg0
index|[]
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|vinum_plex
parameter_list|(
name|int
name|argc
parameter_list|,
name|char
modifier|*
name|argv
index|[]
parameter_list|,
name|char
modifier|*
name|arg0
index|[]
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|vinum_sd
parameter_list|(
name|int
name|argc
parameter_list|,
name|char
modifier|*
name|argv
index|[]
parameter_list|,
name|char
modifier|*
name|arg0
index|[]
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|vinum_drive
parameter_list|(
name|int
name|argc
parameter_list|,
name|char
modifier|*
name|argv
index|[]
parameter_list|,
name|char
modifier|*
name|arg0
index|[]
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|vinum_list
parameter_list|(
name|int
name|argc
parameter_list|,
name|char
modifier|*
name|argv
index|[]
parameter_list|,
name|char
modifier|*
name|arg0
index|[]
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|vinum_info
parameter_list|(
name|int
name|argc
parameter_list|,
name|char
modifier|*
name|argv
index|[]
parameter_list|,
name|char
modifier|*
name|arg0
index|[]
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|vinum_set
parameter_list|(
name|int
name|argc
parameter_list|,
name|char
modifier|*
name|argv
index|[]
parameter_list|,
name|char
modifier|*
name|arg0
index|[]
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|vinum_rm
parameter_list|(
name|int
name|argc
parameter_list|,
name|char
modifier|*
name|argv
index|[]
parameter_list|,
name|char
modifier|*
name|arg0
index|[]
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|vinum_mv
parameter_list|(
name|int
name|argc
parameter_list|,
name|char
modifier|*
name|argv
index|[]
parameter_list|,
name|char
modifier|*
name|arg0
index|[]
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|vinum_init
parameter_list|(
name|int
name|argc
parameter_list|,
name|char
modifier|*
name|argv
index|[]
parameter_list|,
name|char
modifier|*
name|arg0
index|[]
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|initvol
parameter_list|(
name|int
name|volno
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|initplex
parameter_list|(
name|int
name|plexno
parameter_list|,
name|char
modifier|*
name|name
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|initsd
parameter_list|(
name|int
name|sdno
parameter_list|,
name|int
name|dowait
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|vinum_resetconfig
parameter_list|(
name|int
name|argc
parameter_list|,
name|char
modifier|*
name|argv
index|[]
parameter_list|,
name|char
modifier|*
name|arg0
index|[]
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|vinum_start
parameter_list|(
name|int
name|argc
parameter_list|,
name|char
modifier|*
name|argv
index|[]
parameter_list|,
name|char
modifier|*
name|arg0
index|[]
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|continue_revive
parameter_list|(
name|int
name|plexno
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|vinum_stop
parameter_list|(
name|int
name|argc
parameter_list|,
name|char
modifier|*
name|argv
index|[]
parameter_list|,
name|char
modifier|*
name|arg0
index|[]
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|vinum_makedev
parameter_list|(
name|int
name|argc
parameter_list|,
name|char
modifier|*
name|argv
index|[]
parameter_list|,
name|char
modifier|*
name|arg0
index|[]
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|vinum_help
parameter_list|(
name|int
name|argc
parameter_list|,
name|char
modifier|*
name|argv
index|[]
parameter_list|,
name|char
modifier|*
name|arg0
index|[]
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|vinum_quit
parameter_list|(
name|int
name|argc
parameter_list|,
name|char
modifier|*
name|argv
index|[]
parameter_list|,
name|char
modifier|*
name|arg0
index|[]
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|vinum_setdaemon
parameter_list|(
name|int
name|argc
parameter_list|,
name|char
modifier|*
name|argv
index|[]
parameter_list|,
name|char
modifier|*
name|arg0
index|[]
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|vinum_replace
parameter_list|(
name|int
name|argc
parameter_list|,
name|char
modifier|*
name|argv
index|[]
parameter_list|,
name|char
modifier|*
name|arg0
index|[]
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|vinum_readpol
parameter_list|(
name|int
name|argc
parameter_list|,
name|char
modifier|*
name|argv
index|[]
parameter_list|,
name|char
modifier|*
name|arg0
index|[]
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|reset_volume_stats
parameter_list|(
name|int
name|volno
parameter_list|,
name|int
name|recurse
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|reset_plex_stats
parameter_list|(
name|int
name|plexno
parameter_list|,
name|int
name|recurse
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|reset_sd_stats
parameter_list|(
name|int
name|sdno
parameter_list|,
name|int
name|recurse
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|reset_drive_stats
parameter_list|(
name|int
name|driveno
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|vinum_resetstats
parameter_list|(
name|int
name|argc
parameter_list|,
name|char
modifier|*
name|argv
index|[]
parameter_list|,
name|char
modifier|*
name|arg0
index|[]
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|vinum_attach
parameter_list|(
name|int
name|argc
parameter_list|,
name|char
modifier|*
name|argv
index|[]
parameter_list|,
name|char
modifier|*
name|argv0
index|[]
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|vinum_detach
parameter_list|(
name|int
name|argc
parameter_list|,
name|char
modifier|*
name|argv
index|[]
parameter_list|,
name|char
modifier|*
name|argv0
index|[]
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|vinum_rename
parameter_list|(
name|int
name|argc
parameter_list|,
name|char
modifier|*
name|argv
index|[]
parameter_list|,
name|char
modifier|*
name|argv0
index|[]
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|vinum_rename_2
parameter_list|(
name|char
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|vinum_replace
parameter_list|(
name|int
name|argc
parameter_list|,
name|char
modifier|*
name|argv
index|[]
parameter_list|,
name|char
modifier|*
name|argv0
index|[]
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|vinum_printconfig
parameter_list|(
name|int
name|argc
parameter_list|,
name|char
modifier|*
name|argv
index|[]
parameter_list|,
name|char
modifier|*
name|argv0
index|[]
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|printconfig
parameter_list|(
name|FILE
modifier|*
name|of
parameter_list|,
name|char
modifier|*
name|comment
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|vinum_saveconfig
parameter_list|(
name|int
name|argc
parameter_list|,
name|char
modifier|*
name|argv
index|[]
parameter_list|,
name|char
modifier|*
name|argv0
index|[]
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|checkupdates
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|genvolname
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|drive
modifier|*
name|create_drive
parameter_list|(
name|char
modifier|*
name|devicename
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|vinum_concat
parameter_list|(
name|int
name|argc
parameter_list|,
name|char
modifier|*
name|argv
index|[]
parameter_list|,
name|char
modifier|*
name|argv0
index|[]
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|vinum_stripe
parameter_list|(
name|int
name|argc
parameter_list|,
name|char
modifier|*
name|argv
index|[]
parameter_list|,
name|char
modifier|*
name|argv0
index|[]
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|vinum_raid4
parameter_list|(
name|int
name|argc
parameter_list|,
name|char
modifier|*
name|argv
index|[]
parameter_list|,
name|char
modifier|*
name|argv0
index|[]
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|vinum_raid5
parameter_list|(
name|int
name|argc
parameter_list|,
name|char
modifier|*
name|argv
index|[]
parameter_list|,
name|char
modifier|*
name|argv0
index|[]
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|vinum_mirror
parameter_list|(
name|int
name|argc
parameter_list|,
name|char
modifier|*
name|argv
index|[]
parameter_list|,
name|char
modifier|*
name|argv0
index|[]
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|vinum_label
parameter_list|(
name|int
name|argc
parameter_list|,
name|char
modifier|*
name|argv
index|[]
parameter_list|,
name|char
modifier|*
name|arg0
index|[]
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|vinum_ld
parameter_list|(
name|int
name|argc
parameter_list|,
name|char
modifier|*
name|argv
index|[]
parameter_list|,
name|char
modifier|*
name|arg0
index|[]
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|vinum_ls
parameter_list|(
name|int
name|argc
parameter_list|,
name|char
modifier|*
name|argv
index|[]
parameter_list|,
name|char
modifier|*
name|arg0
index|[]
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|vinum_lp
parameter_list|(
name|int
name|argc
parameter_list|,
name|char
modifier|*
name|argv
index|[]
parameter_list|,
name|char
modifier|*
name|arg0
index|[]
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|vinum_lv
parameter_list|(
name|int
name|argc
parameter_list|,
name|char
modifier|*
name|argv
index|[]
parameter_list|,
name|char
modifier|*
name|arg0
index|[]
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|vinum_setstate
parameter_list|(
name|int
name|argc
parameter_list|,
name|char
modifier|*
name|argv
index|[]
parameter_list|,
name|char
modifier|*
name|argv0
index|[]
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|vinum_checkparity
parameter_list|(
name|int
name|argc
parameter_list|,
name|char
modifier|*
name|argv
index|[]
parameter_list|,
name|char
modifier|*
name|argv0
index|[]
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|vinum_rebuildparity
parameter_list|(
name|int
name|argc
parameter_list|,
name|char
modifier|*
name|argv
index|[]
parameter_list|,
name|char
modifier|*
name|argv0
index|[]
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|parityops
parameter_list|(
name|int
name|argc
parameter_list|,
name|char
modifier|*
name|argv
index|[]
parameter_list|,
name|enum
name|parityop
name|op
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|start_daemon
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_ifdef
ifdef|#
directive|ifdef
name|VINUMDEBUG
end_ifdef

begin_function_decl
name|void
name|vinum_debug
parameter_list|(
name|int
name|argc
parameter_list|,
name|char
modifier|*
name|argv
index|[]
parameter_list|,
name|char
modifier|*
name|arg0
index|[]
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
name|struct
name|drive
modifier|*
name|find_drive_by_devname
parameter_list|(
name|char
modifier|*
name|name
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|make_devices
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|make_vol_dev
parameter_list|(
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|make_plex_dev
parameter_list|(
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|make_sd_dev
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|list_defective_objects
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|vinum_dumpconfig
parameter_list|(
name|int
name|argc
parameter_list|,
name|char
modifier|*
name|argv
index|[]
parameter_list|,
name|char
modifier|*
name|argv0
index|[]
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|dumpconfig
parameter_list|(
name|char
modifier|*
name|part
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|check_drive
parameter_list|(
name|char
modifier|*
name|devicename
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|get_drive_info
parameter_list|(
name|struct
name|drive
modifier|*
name|drive
parameter_list|,
name|int
name|index
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|get_sd_info
parameter_list|(
name|struct
name|sd
modifier|*
name|sd
parameter_list|,
name|int
name|index
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|get_plex_sd_info
parameter_list|(
name|struct
name|sd
modifier|*
name|sd
parameter_list|,
name|int
name|plexno
parameter_list|,
name|int
name|sdno
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|get_plex_info
parameter_list|(
name|struct
name|plex
modifier|*
name|plex
parameter_list|,
name|int
name|index
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|get_volume_info
parameter_list|(
name|struct
name|volume
modifier|*
name|volume
parameter_list|,
name|int
name|index
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|drive
modifier|*
name|find_drive_by_devname
parameter_list|(
name|char
modifier|*
name|name
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|find_object
parameter_list|(
specifier|const
name|char
modifier|*
name|name
parameter_list|,
name|enum
name|objecttype
modifier|*
name|type
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|lltoa
parameter_list|(
name|int64_t
name|l
parameter_list|,
name|char
modifier|*
name|s
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|vinum_ldi
parameter_list|(
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|vinum_lvi
parameter_list|(
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|vinum_lpi
parameter_list|(
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|vinum_lsi
parameter_list|(
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|vinum_li
parameter_list|(
name|int
name|object
parameter_list|,
name|enum
name|objecttype
name|type
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|roughlength
parameter_list|(
name|int64_t
name|bytes
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|u_int64_t
name|sizespec
parameter_list|(
name|char
modifier|*
name|spec
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|timestamp
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|int
name|force
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* set to 1 to force some dangerous ops */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|interval
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* interval in ms between init/revive */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|vflag
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* set verbose operation or verify */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|Verbose
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* very verbose operation */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|recurse
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* set recursion */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|sflag
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* show statistics */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|SSize
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* sector size for revive */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|dowait
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* wait for children to exit */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|objectname
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* name for some functions */
end_comment

begin_decl_stmt
specifier|extern
name|FILE
modifier|*
name|history
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* history file */
end_comment

begin_comment
comment|/* Structures to read kernel data into */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|_vinum_conf
name|vinum_conf
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* configuration information */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|volume
name|vol
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|plex
name|plex
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|sd
name|sd
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|drive
name|drive
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|jmp_buf
name|command_fail
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* return on a failed command */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|superdev
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* vinum super device */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|line
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* stdin line number for error messages */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|file_line
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* and line in input file (yes, this is tacky) */
end_comment

begin_decl_stmt
specifier|extern
name|char
name|buffer
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* buffer to read in to */
end_comment

begin_define
define|#
directive|define
name|min
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|a< b? a: b
end_define

end_unit

