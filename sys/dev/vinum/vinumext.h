begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1997, 1998  *	Nan Yang Computer Services Limited.  All rights reserved.  *  *  This software is distributed under the so-called ``Berkeley  *  License'':  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by Nan Yang Computer  *      Services Limited.  * 4. Neither the name of the Company nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * This software is provided ``as is'', and any express or implied  * warranties, including, but not limited to, the implied warranties of  * merchantability and fitness for a particular purpose are disclaimed.  * In no event shall the company or contributors be liable for any  * direct, indirect, incidental, special, exemplary, or consequential  * damages (including, but not limited to, procurement of substitute  * goods or services; loss of use, data, or profits; or business  * interruption) however caused and on any theory of liability, whether  * in contract, strict liability, or tort (including negligence or  * otherwise) arising in any way out of the use of this software, even if  * advised of the possibility of such damage.  *  * $Id: vinumext.h,v 1.27 2001/05/22 04:07:22 grog Exp grog $  * $FreeBSD$  */
end_comment

begin_comment
comment|/* vinumext.h: external definitions */
end_comment

begin_comment
comment|/* *sigh* We still need this at the moment. */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

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

begin_else
else|#
directive|else
end_else

begin_decl_stmt
specifier|extern
name|struct
name|__vinum_conf
name|vinum_conf
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* configuration information */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|VINUMDEBUG
end_ifdef

begin_decl_stmt
specifier|extern
name|int
name|debug
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* debug flags */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Physical read and write drive */
end_comment

begin_define
define|#
directive|define
name|read_drive
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|,
name|d
parameter_list|)
value|driveio (a, b, c, d, BIO_READ)
end_define

begin_define
define|#
directive|define
name|write_drive
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|,
name|d
parameter_list|)
value|driveio (a, b, c, d, BIO_WRITE)
end_define

begin_define
define|#
directive|define
name|CHECKALLOC
parameter_list|(
name|ptr
parameter_list|,
name|msg
parameter_list|)
define|\
value|if (ptr == NULL) \     { \     printf (msg); \     longjmp (command_fail, -1); \     }
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|_KERNEL
end_ifndef

begin_struct_decl
struct_decl|struct
name|vnode
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|thread
struct_decl|;
end_struct_decl

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_function_decl
name|int
name|vinum_inactive
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|free_vinum
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|give_sd_to_plex
parameter_list|(
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
name|give_sd_to_drive
parameter_list|(
name|int
name|sdno
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|give_plex_to_volume
parameter_list|(
name|int
name|volno
parameter_list|,
name|int
name|plexno
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|drive
modifier|*
name|check_drive
parameter_list|(
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|enum
name|drive_label_info
name|read_drive_label
parameter_list|(
name|struct
name|drive
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|parse_config
parameter_list|(
name|char
modifier|*
parameter_list|,
name|struct
name|keywordset
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|parse_user_config
parameter_list|(
name|char
modifier|*
name|cptr
parameter_list|,
name|struct
name|keywordset
modifier|*
name|keyset
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
name|int
name|volume_index
parameter_list|(
name|struct
name|volume
modifier|*
name|volume
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|plex_index
parameter_list|(
name|struct
name|plex
modifier|*
name|plex
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|sd_index
parameter_list|(
name|struct
name|sd
modifier|*
name|sd
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|drive_index
parameter_list|(
name|struct
name|drive
modifier|*
name|drive
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|my_plex
parameter_list|(
name|int
name|volno
parameter_list|,
name|int
name|plexno
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|my_sd
parameter_list|(
name|int
name|plexno
parameter_list|,
name|int
name|sdno
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|get_empty_drive
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|find_drive
parameter_list|(
specifier|const
name|char
modifier|*
name|name
parameter_list|,
name|int
name|create
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|find_drive_by_dev
parameter_list|(
specifier|const
name|char
modifier|*
name|devname
parameter_list|,
name|int
name|create
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|get_empty_sd
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|find_subdisk
parameter_list|(
specifier|const
name|char
modifier|*
name|name
parameter_list|,
name|int
name|create
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|return_drive_space
parameter_list|(
name|int
name|driveno
parameter_list|,
name|int64_t
name|offset
parameter_list|,
name|int
name|length
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|free_sd
parameter_list|(
name|int
name|sdno
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|free_volume
parameter_list|(
name|int
name|volno
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|get_empty_plex
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|find_plex
parameter_list|(
specifier|const
name|char
modifier|*
name|name
parameter_list|,
name|int
name|create
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|free_plex
parameter_list|(
name|int
name|plexno
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|get_empty_volume
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|find_volume
parameter_list|(
specifier|const
name|char
modifier|*
name|name
parameter_list|,
name|int
name|create
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|config_subdisk
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|config_plex
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|config_volume
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|config_drive
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|updateconfig
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|update_sd_config
parameter_list|(
name|int
name|sdno
parameter_list|,
name|int
name|kernelstate
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|update_plex_config
parameter_list|(
name|int
name|plexno
parameter_list|,
name|int
name|kernelstate
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|update_volume_config
parameter_list|(
name|int
name|volno
parameter_list|,
name|int
name|kernelstate
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|update_config
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|drive_io_done
parameter_list|(
name|struct
name|buf
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|save_config
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|daemon_save_config
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|write_config
parameter_list|(
name|char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|start_config
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|finish_config
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|remove
parameter_list|(
name|struct
name|vinum_ioctl_msg
modifier|*
name|msg
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|remove_drive_entry
parameter_list|(
name|int
name|driveno
parameter_list|,
name|int
name|force
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|remove_sd_entry
parameter_list|(
name|int
name|sdno
parameter_list|,
name|int
name|force
parameter_list|,
name|int
name|recurse
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|remove_plex_entry
parameter_list|(
name|int
name|plexno
parameter_list|,
name|int
name|force
parameter_list|,
name|int
name|recurse
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|remove_volume_entry
parameter_list|(
name|int
name|volno
parameter_list|,
name|int
name|force
parameter_list|,
name|int
name|recurse
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|checkdiskconfig
parameter_list|(
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|open_drive
parameter_list|(
name|struct
name|drive
modifier|*
parameter_list|,
name|struct
name|thread
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|close_drive
parameter_list|(
name|struct
name|drive
modifier|*
name|drive
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|close_locked_drive
parameter_list|(
name|struct
name|drive
modifier|*
name|drive
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|driveio
parameter_list|(
name|struct
name|drive
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|,
name|size_t
parameter_list|,
name|off_t
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|set_drive_parms
parameter_list|(
name|struct
name|drive
modifier|*
name|drive
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|init_drive
parameter_list|(
name|struct
name|drive
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* void throw_rude_remark (int, struct _ioctl_reply *, char *, ...); XXX */
end_comment

begin_function_decl
name|void
name|throw_rude_remark
parameter_list|(
name|int
parameter_list|,
name|char
modifier|*
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* XXX die die */
end_comment

begin_function_decl
name|void
name|format_config
parameter_list|(
name|char
modifier|*
name|config
parameter_list|,
name|int
name|len
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|checkkernel
parameter_list|(
name|char
modifier|*
name|op
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|free_drive
parameter_list|(
name|struct
name|drive
modifier|*
name|drive
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|down_drive
parameter_list|(
name|struct
name|drive
modifier|*
name|drive
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|remove_drive
parameter_list|(
name|int
name|driveno
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|vinum_scandisk
parameter_list|(
name|char
modifier|*
name|drivename
index|[]
parameter_list|,
name|int
name|drives
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* I/O */
end_comment

begin_decl_stmt
name|d_open_t
name|vinumopen
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_close_t
name|vinumclose
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_strategy_t
name|vinumstrategy
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_ioctl_t
name|vinumioctl
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_psize_t
name|vinumsize
decl_stmt|;
end_decl_stmt

begin_function_decl
name|int
name|vinumstart
parameter_list|(
name|struct
name|buf
modifier|*
name|bp
parameter_list|,
name|int
name|reviveok
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|launch_requests
parameter_list|(
name|struct
name|request
modifier|*
name|rq
parameter_list|,
name|int
name|reviveok
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|sdio
parameter_list|(
name|struct
name|buf
modifier|*
name|bp
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* XXX Do we need this? */
end_comment

begin_function_decl
name|int
name|vinumpart
parameter_list|(
name|dev_t
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|jmp_buf
name|command_fail
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* return here if config fails */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|VINUMDEBUG
end_ifdef

begin_comment
comment|/* Memory allocation and request tracing */
end_comment

begin_function_decl
name|void
name|vinum_meminfo
parameter_list|(
name|caddr_t
name|data
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|vinum_mallocinfo
parameter_list|(
name|caddr_t
name|data
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|vinum_rqinfo
parameter_list|(
name|caddr_t
name|data
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|LongJmp
parameter_list|(
name|jmp_buf
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|basename
parameter_list|(
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
name|void
name|expand_table
parameter_list|(
name|void
modifier|*
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_struct_decl
struct_decl|struct
name|request
struct_decl|;
end_struct_decl

begin_function_decl
name|struct
name|rqgroup
modifier|*
name|allocrqg
parameter_list|(
name|struct
name|request
modifier|*
name|rq
parameter_list|,
name|int
name|elements
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|deallocrqg
parameter_list|(
name|struct
name|rqgroup
modifier|*
name|rqg
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Device number decoding */
end_comment

begin_function_decl
name|int
name|Volno
parameter_list|(
name|dev_t
name|x
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|Plexno
parameter_list|(
name|dev_t
name|x
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|Sdno
parameter_list|(
name|dev_t
name|x
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* State transitions */
end_comment

begin_function_decl
name|int
name|set_drive_state
parameter_list|(
name|int
name|driveno
parameter_list|,
name|enum
name|drivestate
name|state
parameter_list|,
name|enum
name|setstateflags
name|flags
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|set_sd_state
parameter_list|(
name|int
name|sdno
parameter_list|,
name|enum
name|sdstate
name|state
parameter_list|,
name|enum
name|setstateflags
name|flags
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|enum
name|requeststatus
name|checksdstate
parameter_list|(
name|struct
name|sd
modifier|*
name|sd
parameter_list|,
name|struct
name|request
modifier|*
name|rq
parameter_list|,
name|daddr_t
name|diskaddr
parameter_list|,
name|daddr_t
name|diskend
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|set_plex_state
parameter_list|(
name|int
name|plexno
parameter_list|,
name|enum
name|plexstate
name|state
parameter_list|,
name|enum
name|setstateflags
name|flags
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|set_volume_state
parameter_list|(
name|int
name|volumeno
parameter_list|,
name|enum
name|volumestate
name|state
parameter_list|,
name|enum
name|setstateflags
name|flags
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|update_sd_state
parameter_list|(
name|int
name|sdno
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|forceup
parameter_list|(
name|int
name|plexno
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|update_plex_state
parameter_list|(
name|int
name|plexno
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|update_volume_state
parameter_list|(
name|int
name|volno
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|invalidate_subdisks
parameter_list|(
name|struct
name|plex
modifier|*
parameter_list|,
name|enum
name|sdstate
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|get_volume_label
parameter_list|(
name|char
modifier|*
name|name
parameter_list|,
name|int
name|plexes
parameter_list|,
name|u_int64_t
name|size
parameter_list|,
name|struct
name|disklabel
modifier|*
name|lp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|write_volume_label
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|start_object
parameter_list|(
name|struct
name|vinum_ioctl_msg
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|stop_object
parameter_list|(
name|struct
name|vinum_ioctl_msg
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|setstate
parameter_list|(
name|struct
name|vinum_ioctl_msg
modifier|*
name|msg
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|setstate_by_force
parameter_list|(
name|struct
name|vinum_ioctl_msg
modifier|*
name|msg
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|vinum_label
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|vinum_writedisklabel
parameter_list|(
name|struct
name|volume
modifier|*
parameter_list|,
name|struct
name|disklabel
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|initsd
parameter_list|(
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|buf
modifier|*
name|parityrebuild
parameter_list|(
name|struct
name|plex
modifier|*
parameter_list|,
name|u_int64_t
parameter_list|,
name|int
parameter_list|,
name|enum
name|parityop
parameter_list|,
name|struct
name|rangelock
modifier|*
modifier|*
parameter_list|,
name|off_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|enum
name|requeststatus
name|sddownstate
parameter_list|(
name|struct
name|request
modifier|*
name|rq
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|restart_plex
parameter_list|(
name|int
name|plexno
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|revive_read
parameter_list|(
name|struct
name|sd
modifier|*
name|sd
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|revive_block
parameter_list|(
name|int
name|sdno
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|parityops
parameter_list|(
name|struct
name|vinum_ioctl_msg
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Auxiliary functions */
end_comment

begin_function_decl
name|enum
name|sdstates
name|sdstatemap
parameter_list|(
name|struct
name|plex
modifier|*
name|plex
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|enum
name|volplexstate
name|vpstate
parameter_list|(
name|struct
name|plex
modifier|*
name|plex
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
name|validdrive
parameter_list|(
name|int
name|driveno
parameter_list|,
name|struct
name|_ioctl_reply
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|sd
modifier|*
name|validsd
parameter_list|(
name|int
name|sdno
parameter_list|,
name|struct
name|_ioctl_reply
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|plex
modifier|*
name|validplex
parameter_list|(
name|int
name|plexno
parameter_list|,
name|struct
name|_ioctl_reply
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|volume
modifier|*
name|validvol
parameter_list|(
name|int
name|volno
parameter_list|,
name|struct
name|_ioctl_reply
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|resetstats
parameter_list|(
name|struct
name|vinum_ioctl_msg
modifier|*
name|msg
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Locking */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|VINUMDEBUG
end_ifdef

begin_function_decl
name|int
name|lockdrive
parameter_list|(
name|struct
name|drive
modifier|*
name|drive
parameter_list|,
name|char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_else
else|#
directive|else
end_else

begin_function_decl
name|int
name|lockdrive
parameter_list|(
name|struct
name|drive
modifier|*
name|drive
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
name|void
name|unlockdrive
parameter_list|(
name|struct
name|drive
modifier|*
name|drive
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|lockvol
parameter_list|(
name|struct
name|volume
modifier|*
name|vol
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|unlockvol
parameter_list|(
name|struct
name|volume
modifier|*
name|vol
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|lockplex
parameter_list|(
name|struct
name|plex
modifier|*
name|plex
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|unlockplex
parameter_list|(
name|struct
name|plex
modifier|*
name|plex
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|rangelock
modifier|*
name|lockrange
parameter_list|(
name|daddr_t
name|stripe
parameter_list|,
name|struct
name|buf
modifier|*
name|bp
parameter_list|,
name|struct
name|plex
modifier|*
name|plex
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|lock_config
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|unlock_config
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Dæmon */
end_comment

begin_function_decl
name|void
name|vinum_daemon
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|vinum_finddaemon
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|vinum_setdaemonopts
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|struct
name|daemonq
modifier|*
name|daemonq
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* daemon's work queue */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|daemonq
modifier|*
name|dqend
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* and the end of the queue */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|cdevsw
name|vinum_cdevsw
decl_stmt|;
end_decl_stmt

begin_undef
undef|#
directive|undef
name|Free
end_undef

begin_comment
comment|/* defined in some funny net stuff */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_ifdef
ifdef|#
directive|ifdef
name|VINUMDEBUG
end_ifdef

begin_define
define|#
directive|define
name|Malloc
parameter_list|(
name|x
parameter_list|)
value|MMalloc ((x), __FILE__, __LINE__)
end_define

begin_comment
comment|/* show where we came from */
end_comment

begin_define
define|#
directive|define
name|Free
parameter_list|(
name|x
parameter_list|)
value|FFree ((x), __FILE__, __LINE__)
end_define

begin_comment
comment|/* show where we came from */
end_comment

begin_function_decl
name|caddr_t
name|MMalloc
parameter_list|(
name|int
name|size
parameter_list|,
name|char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|FFree
parameter_list|(
name|void
modifier|*
name|mem
parameter_list|,
name|char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|LOCKDRIVE
parameter_list|(
name|d
parameter_list|)
value|lockdrive (d, __FILE__, __LINE__)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|Malloc
parameter_list|(
name|x
parameter_list|)
value|malloc((x), M_DEVBUF, \ 	curthread->td_proc->p_intr_nesting_level == 0? M_WAITOK: M_NOWAIT)
end_define

begin_define
define|#
directive|define
name|Free
parameter_list|(
name|x
parameter_list|)
value|free((x), M_DEVBUF)
end_define

begin_define
define|#
directive|define
name|LOCKDRIVE
parameter_list|(
name|d
parameter_list|)
value|lockdrive (d)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|Malloc
parameter_list|(
name|x
parameter_list|)
value|malloc ((x))
end_define

begin_comment
comment|/* just the size */
end_comment

begin_define
define|#
directive|define
name|Free
parameter_list|(
name|x
parameter_list|)
value|free ((x))
end_define

begin_comment
comment|/* just the address */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Local Variables: */
end_comment

begin_comment
comment|/* fill-column: 50 */
end_comment

begin_comment
comment|/* End: */
end_comment

end_unit

