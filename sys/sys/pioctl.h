begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * procfs ioctl definitions.  *  * $Id: pioctl.h,v 1.3 1997/12/08 22:09:39 sef Exp $  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SYS_PIOCTL_H
end_ifndef

begin_define
define|#
directive|define
name|_SYS_PIOCTL_H
end_define

begin_include
include|#
directive|include
file|<sys/ioccom.h>
end_include

begin_struct
struct|struct
name|procfs_status
block|{
name|int
name|state
decl_stmt|;
comment|/* Running, stopped, something else? */
name|int
name|flags
decl_stmt|;
comment|/* Any flags */
name|unsigned
name|long
name|events
decl_stmt|;
comment|/* Events to stop on */
name|int
name|why
decl_stmt|;
comment|/* What event, if any, proc stopped on */
name|unsigned
name|long
name|val
decl_stmt|;
comment|/* Any extra data */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|PIOCBIS
value|_IO('p', 1)
end_define

begin_comment
comment|/* Set event flag */
end_comment

begin_define
define|#
directive|define
name|PIOCBIC
value|_IO('p', 2)
end_define

begin_comment
comment|/* Clear event flag */
end_comment

begin_define
define|#
directive|define
name|PIOCSFL
value|_IO('p', 3)
end_define

begin_comment
comment|/* Set flags */
end_comment

begin_comment
comment|/* wait for proc to stop */
end_comment

begin_define
define|#
directive|define
name|PIOCWAIT
value|_IOR('p', 4, struct procfs_status)
end_define

begin_define
define|#
directive|define
name|PIOCCONT
value|_IO('p', 5)
end_define

begin_comment
comment|/* Continue a process */
end_comment

begin_comment
comment|/* Get proc status */
end_comment

begin_define
define|#
directive|define
name|PIOCSTATUS
value|_IOR('p', 6, struct procfs_status)
end_define

begin_define
define|#
directive|define
name|PIOCGFL
value|_IOR('p', 7, unsigned int)
end_define

begin_comment
comment|/* Get flags */
end_comment

begin_define
define|#
directive|define
name|S_EXEC
value|0x00000001
end_define

begin_comment
comment|/* stop-on-exec */
end_comment

begin_define
define|#
directive|define
name|S_SIG
value|0x00000002
end_define

begin_comment
comment|/* stop-on-signal */
end_comment

begin_define
define|#
directive|define
name|S_SCE
value|0x00000004
end_define

begin_comment
comment|/* stop on syscall entry */
end_comment

begin_define
define|#
directive|define
name|S_SCX
value|0x00000008
end_define

begin_comment
comment|/* stop on syscall exit */
end_comment

begin_define
define|#
directive|define
name|S_CORE
value|0x00000010
end_define

begin_comment
comment|/* stop on coredump */
end_comment

begin_define
define|#
directive|define
name|S_EXIT
value|0x00000020
end_define

begin_comment
comment|/* stop on exit */
end_comment

begin_comment
comment|/*  * If PF_LINGER is set in procp->p_pfsflags, then the last close  * of a /proc/<pid>/mem file will nto clear out the stops and continue  * the process.  */
end_comment

begin_define
define|#
directive|define
name|PF_LINGER
value|0x01
end_define

begin_comment
comment|/* Keep stops around after last close */
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

