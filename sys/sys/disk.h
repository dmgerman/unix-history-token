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

begin_ifndef
ifndef|#
directive|ifndef
name|_SYS_DISKSLICE_H_
end_ifndef

begin_include
include|#
directive|include
file|<sys/diskslice.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _SYS_DISKSLICE_H_ */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SYS_DISKLABEL
end_ifndef

begin_include
include|#
directive|include
file|<sys/disklabel.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _SYS_DISKLABEL */
end_comment

begin_include
include|#
directive|include
file|<sys/queue.h>
end_include

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
name|struct
name|diskslices
modifier|*
name|d_slice
decl_stmt|;
name|struct
name|disklabel
name|d_label
decl_stmt|;
name|LIST_ENTRY
argument_list|(
argument|disk
argument_list|)
name|d_list
expr_stmt|;
name|void
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
name|struct
name|cdevsw
modifier|*
name|diskdevsw
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
name|int
name|disk_dumpcheck
parameter_list|(
name|dev_t
name|dev
parameter_list|,
name|u_int
modifier|*
name|count
parameter_list|,
name|u_int
modifier|*
name|blkno
parameter_list|,
name|u_int
modifier|*
name|secsize
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
name|disk_invalidate
parameter_list|(
name|struct
name|disk
modifier|*
name|disk
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _SYS_DISK_H_ */
end_comment

end_unit

