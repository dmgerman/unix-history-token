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

begin_struct_decl
struct_decl|struct
name|g_geom
struct_decl|;
end_struct_decl

begin_struct
struct|struct
name|disk
block|{
name|u_int
name|d_flags
decl_stmt|;
name|u_int
name|d_dsflags
decl_stmt|;
name|struct
name|cdevsw
modifier|*
name|d_devsw
decl_stmt|;
name|dev_t
name|d_dev
decl_stmt|;
comment|/* These four fields must be valid while opened */
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
name|struct
name|g_geom
modifier|*
name|d_softc
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|DISKFLAG_LOCK
value|0x1
end_define

begin_define
define|#
directive|define
name|DISKFLAG_WANTED
value|0x2
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

