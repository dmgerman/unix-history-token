begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * ----------------------------------------------------------------------------  * "THE BEER-WARE LICENSE" (Revision 42):  *<phk@FreeBSD.ORG> wrote this file.  As long as you retain this notice you  * can do whatever you want with this stuff. If we meet some day, and you think  * this stuff is worth it, you can buy me a beer in return.   Poul-Henning Kamp  * ----------------------------------------------------------------------------  *  * $FreeBSD$  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SYS_DISK_H_
end_ifndef

begin_define
define|#
directive|define
name|_SYS_DISK_H_
end_define

begin_include
include|#
directive|include
file|<sys/ioccom.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_include
include|#
directive|include
file|<sys/queue.h>
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|_SYS_CONF_H_
end_ifndef

begin_include
include|#
directive|include
file|<sys/conf.h>
end_include

begin_comment
comment|/* XXX: temporary to avoid breakage */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
name|int
name|disk_open_t
parameter_list|(
name|struct
name|disk
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|int
name|disk_close_t
parameter_list|(
name|struct
name|disk
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|void
name|disk_strategy_t
parameter_list|(
name|struct
name|bio
modifier|*
name|bp
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|int
name|disk_ioctl_t
parameter_list|(
name|struct
name|disk
modifier|*
parameter_list|,
name|u_long
name|cmd
parameter_list|,
name|void
modifier|*
name|data
parameter_list|,
name|int
name|fflag
parameter_list|,
name|struct
name|thread
modifier|*
name|td
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/* NB: disk_ioctl_t SHALL be cast'able to d_ioctl_t */
end_comment

begin_struct_decl
struct_decl|struct
name|g_geom
struct_decl|;
end_struct_decl

begin_struct
struct|struct
name|disk
block|{
comment|/* Fields which are private to geom_disk */
name|struct
name|cdevsw
modifier|*
name|d_devsw
decl_stmt|;
name|d_open_t
modifier|*
name|d_copen
decl_stmt|;
comment|/* Compat */
name|d_close_t
modifier|*
name|d_cclose
decl_stmt|;
comment|/* Compat */
name|d_ioctl_t
modifier|*
name|d_cioctl
decl_stmt|;
comment|/* Compat */
name|struct
name|g_geom
modifier|*
name|d_geom
decl_stmt|;
comment|/* Shared fields */
name|u_int
name|d_flags
decl_stmt|;
specifier|const
name|char
modifier|*
name|d_name
decl_stmt|;
name|u_int
name|d_unit
decl_stmt|;
name|dev_t
name|d_dev
decl_stmt|;
comment|/* Compat */
comment|/* Disk methods  */
name|disk_open_t
modifier|*
name|d_open
decl_stmt|;
name|disk_close_t
modifier|*
name|d_close
decl_stmt|;
name|disk_strategy_t
modifier|*
name|d_strategy
decl_stmt|;
name|disk_ioctl_t
modifier|*
name|d_ioctl
decl_stmt|;
name|dumper_t
modifier|*
name|d_dump
decl_stmt|;
comment|/* Info fields from driver to geom_disk.c. Valid when open */
name|u_int
name|d_sectorsize
decl_stmt|;
name|off_t
name|d_mediasize
decl_stmt|;
name|u_int
name|d_fwsectors
decl_stmt|;
name|u_int
name|d_fwheads
decl_stmt|;
name|u_int
name|d_stripe_offset
decl_stmt|;
name|u_int
name|d_stripe_width
decl_stmt|;
name|u_int
name|d_max_request
decl_stmt|;
comment|/* Fields private to the driver */
name|void
modifier|*
name|d_drv1
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|DISKFLAG_NOGIANT
value|0x1
end_define

begin_define
define|#
directive|define
name|DISKFLAG_OPEN
value|0x2
end_define

begin_define
define|#
directive|define
name|DISKFLAG_CANDELETE
value|0x4
end_define

begin_function_decl
name|dev_t
name|disk_create
parameter_list|(
name|int
name|unit
parameter_list|,
name|struct
name|disk
modifier|*
name|disk
parameter_list|,
name|int
name|flags
parameter_list|,
name|struct
name|cdevsw
modifier|*
name|cdevsw
parameter_list|,
name|void
modifier|*
name|unused
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|disk_destroy
parameter_list|(
name|dev_t
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|disk
modifier|*
name|disk_enumerate
parameter_list|(
name|struct
name|disk
modifier|*
name|disk
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|disk_err
parameter_list|(
name|struct
name|bio
modifier|*
name|bp
parameter_list|,
specifier|const
name|char
modifier|*
name|what
parameter_list|,
name|int
name|blkdone
parameter_list|,
name|int
name|nl
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|DIOCGSECTORSIZE
value|_IOR('d', 128, u_int)
end_define

begin_comment
comment|/*- 	 * Get the sectorsize of the device in bytes.  The sectorsize is the 	 * smallest unit of data which can be transfered from this device. 	 * Usually this is a power of two but it may not be. (ie: CDROM audio) 	 */
end_comment

begin_define
define|#
directive|define
name|DIOCGMEDIASIZE
value|_IOR('d', 129, off_t)
end_define

begin_comment
comment|/* Get media size in bytes */
end_comment

begin_comment
comment|/*- 	 * Get the size of the entire device in bytes.  This should be a 	 * multiple of the sectorsize. 	 */
end_comment

begin_define
define|#
directive|define
name|DIOCGFWSECTORS
value|_IOR('d', 130, u_int)
end_define

begin_comment
comment|/* Get firmware sectorcount */
end_comment

begin_comment
comment|/*- 	 * Get the firmwares notion of number of sectors per track.  This 	 * value is mostly used for compatibility with various ill designed 	 * disk label formats.  Don't use it unless you have to. 	 */
end_comment

begin_define
define|#
directive|define
name|DIOCGFWHEADS
value|_IOR('d', 131, u_int)
end_define

begin_comment
comment|/* Get firmware headcount */
end_comment

begin_comment
comment|/*- 	 * Get the firmwares notion of number of heads per cylinder.  This 	 * value is mostly used for compatibility with various ill designed 	 * disk label formats.  Don't use it unless you have to. 	 */
end_comment

begin_define
define|#
directive|define
name|DIOCSKERNELDUMP
value|_IOW('d', 133, u_int)
end_define

begin_comment
comment|/* Set/Clear kernel dumps */
end_comment

begin_comment
comment|/*- 	 * Enable/Disable (the argument is boolean) the device for kernel 	 * core dumps. 	 */
end_comment

begin_define
define|#
directive|define
name|DIOCGFRONTSTUFF
value|_IOR('d', 134, off_t)
end_define

begin_comment
comment|/*- 	 * Many disk formats have some amount of space reserved at the 	 * start of the disk to hold bootblocks, various disklabels and 	 * similar stuff.  This ioctl returns the number of such bytes 	 * which may apply to the device. 	 */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _SYS_DISK_H_ */
end_comment

end_unit

