begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1994, Paul Richards.  *  * All rights reserved.  *  * This software may be used, modified, copied, distributed, and  * sold, in both source and binary form provided that the above  * copyright and these terms are retained, verbatim, as the first  * lines of this file.  Under no circumstances is the author  * responsible for the proper functioning of this software, nor does  * the author assume any responsibility for damages incurred with  * its use.  */
end_comment

begin_define
define|#
directive|define
name|TITLE
value|"FreeBSD 2.0.1-Development Installation"
end_define

begin_define
define|#
directive|define
name|MAXFS
value|25
end_define

begin_define
define|#
directive|define
name|MAX_NO_DISKS
value|10
end_define

begin_define
define|#
directive|define
name|SCRATCHSIZE
value|1024
end_define

begin_define
define|#
directive|define
name|ERRMSGSIZE
value|256
end_define

begin_define
define|#
directive|define
name|DEFROOTSIZE
value|16
end_define

begin_define
define|#
directive|define
name|DEFSWAPSIZE
value|32
end_define

begin_define
define|#
directive|define
name|DEFUSRSIZE
value|120
end_define

begin_define
define|#
directive|define
name|BOOT_MAGIC
value|0xAA55
end_define

begin_define
define|#
directive|define
name|ACTIVE
value|0x80
end_define

begin_define
define|#
directive|define
name|COPYRIGHT_FILE
value|"/COPYRIGHT"
end_define

begin_define
define|#
directive|define
name|README_FILE
value|"/README"
end_define

begin_define
define|#
directive|define
name|STATUSFILE
value|"sysinstall.stat"
end_define

begin_define
define|#
directive|define
name|NOT_INSTALLED
value|0
end_define

begin_define
define|#
directive|define
name|DISK_READY
value|1
end_define

begin_define
define|#
directive|define
name|INSTALLED_BASE
value|2
end_define

begin_struct
struct|struct
name|sysinstall
block|{
name|char
name|media
index|[
literal|90
index|]
decl_stmt|;
name|int
name|status
decl_stmt|;
name|char
name|seq_name
index|[
literal|64
index|]
decl_stmt|;
name|int
name|seq_size
decl_stmt|;
name|int
name|seq_no
decl_stmt|;
name|char
name|archive
index|[
literal|64
index|]
decl_stmt|;
name|char
name|root_dev
index|[
literal|90
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_ifndef
ifndef|#
directive|ifndef
name|EXTERN
end_ifndef

begin_define
define|#
directive|define
name|EXTERN
value|extern
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
name|EXTERN
name|char
modifier|*
name|devicename
index|[
name|MAXFS
operator|+
literal|1
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|EXTERN
name|char
modifier|*
name|mountpoint
index|[
name|MAXFS
operator|+
literal|1
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|EXTERN
name|int
name|dialog_active
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|no_disks
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|inst_disk
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|unsigned
name|char
modifier|*
name|scratch
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|unsigned
name|char
modifier|*
name|errmsg
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
modifier|*
name|avail_fds
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|disklabel
modifier|*
name|avail_disklabels
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|u_short
name|dkcksum
parameter_list|(
name|struct
name|disklabel
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* utils.c */
end_comment

begin_decl_stmt
name|void
name|TellEm
name|__P
argument_list|(
operator|(
name|char
operator|*
name|fmt
operator|,
operator|...
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|stage0
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
modifier|*
name|Malloc
name|__P
argument_list|(
operator|(
name|size_t
name|size
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|StrAlloc
name|__P
argument_list|(
operator|(
name|char
operator|*
name|str
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|Fatal
name|__P
argument_list|(
operator|(
name|char
operator|*
name|fmt
operator|,
operator|...
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|AskAbort
name|__P
argument_list|(
operator|(
name|char
operator|*
name|fmt
operator|,
operator|...
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|exec
name|__P
argument_list|(
operator|(
name|char
operator|*
name|cmd
operator|,
name|char
operator|*
name|args
operator|,
operator|...
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|MountUfs
name|__P
argument_list|(
operator|(
name|char
operator|*
name|device
operator|,
name|char
operator|*
name|prefix
operator|,
name|char
operator|*
name|mountpoint
operator|,
name|int
name|do_mkdir
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* stage0.c */
end_comment

begin_decl_stmt
name|void
name|stage0
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* stage1.c */
end_comment

begin_decl_stmt
name|void
name|stage1
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* stage2.c */
end_comment

begin_decl_stmt
name|void
name|stage2
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* stage3.c */
end_comment

begin_decl_stmt
name|void
name|stage3
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* termcap.c */
end_comment

begin_decl_stmt
name|int
name|set_termcap
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

end_unit

