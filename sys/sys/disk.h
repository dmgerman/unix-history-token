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

begin_decl_stmt
name|dev_t
name|disk_create
name|__P
argument_list|(
operator|(
name|int
name|unit
operator|,
expr|struct
name|disk
operator|*
name|disk
operator|,
name|int
name|flags
operator|,
expr|struct
name|cdevsw
operator|*
name|cdevsw
operator|,
expr|struct
name|cdevsw
operator|*
name|diskdevsw
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|disk_destroy
name|__P
argument_list|(
operator|(
name|dev_t
name|dev
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|disk_dumpcheck
name|__P
argument_list|(
operator|(
name|dev_t
name|dev
operator|,
name|u_int
operator|*
name|count
operator|,
name|u_int
operator|*
name|blkno
operator|,
name|u_int
operator|*
name|secsize
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|disk
modifier|*
name|disk_enumerate
name|__P
argument_list|(
operator|(
expr|struct
name|disk
operator|*
name|disk
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|disk_invalidate
name|__P
argument_list|(
operator|(
expr|struct
name|disk
operator|*
name|disk
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _SYS_DISK_H_ */
end_comment

end_unit

