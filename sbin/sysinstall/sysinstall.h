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
name|BOOT1
value|"/stand/sdboot"
end_define

begin_define
define|#
directive|define
name|BOOT2
value|"/stand/bootsd"
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
name|MAX_NO_FS
value|30
end_define

begin_define
define|#
directive|define
name|MAXFS
value|MAX_NO_FS
end_define

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_include
include|#
directive|include
file|<unistd.h>
end_include

begin_include
include|#
directive|include
file|<ncurses.h>
end_include

begin_include
include|#
directive|include
file|<string.h>
end_include

begin_include
include|#
directive|include
file|<errno.h>
end_include

begin_include
include|#
directive|include
file|<dialog.h>
end_include

begin_include
include|#
directive|include
file|<ctype.h>
end_include

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<sys/ioctl.h>
end_include

begin_include
include|#
directive|include
file|<sys/dkbad.h>
end_include

begin_include
include|#
directive|include
file|<sys/disklabel.h>
end_include

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
value|18
end_define

begin_define
define|#
directive|define
name|DEFSWAPSIZE
value|16
end_define

begin_define
define|#
directive|define
name|DEFUSRSIZE
value|80
end_define

begin_define
define|#
directive|define
name|DEFFSIZE
value|1024
end_define

begin_define
define|#
directive|define
name|DEFFRAG
value|8
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
name|HELPME_FILE
value|"/DISKSPACE.FAQ"
end_define

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

begin_comment
comment|/* All this "disk" stuff */
end_comment

begin_decl_stmt
name|EXTERN
name|int
name|Ndisk
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|EXTERN
name|struct
name|disklabel
modifier|*
name|Dlbl
index|[
name|MAX_NO_DISKS
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|EXTERN
name|char
modifier|*
name|Dname
index|[
name|MAX_NO_DISKS
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|EXTERN
name|int
name|Dfd
index|[
name|MAX_NO_DISKS
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|EXTERN
name|int
name|MP
index|[
name|MAX_NO_DISKS
index|]
index|[
name|MAXPARTITIONS
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* All this "filesystem" stuff */
end_comment

begin_decl_stmt
name|EXTERN
name|int
name|Nfs
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|EXTERN
name|char
modifier|*
name|Fname
index|[
name|MAX_NO_FS
operator|+
literal|1
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|EXTERN
name|char
modifier|*
name|Fmount
index|[
name|MAX_NO_FS
operator|+
literal|1
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|EXTERN
name|char
modifier|*
name|Ftype
index|[
name|MAX_NO_FS
operator|+
literal|1
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|EXTERN
name|u_long
name|Fsize
index|[
name|MAX_NO_FS
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
name|EXTERN
name|char
name|selection
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|EXTERN
name|int
name|debug_fd
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|unsigned
name|char
modifier|*
modifier|*
name|avail_disknames
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
name|unsigned
name|char
modifier|*
modifier|*
name|avail_disknames
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
name|int
name|strheight
name|__P
argument_list|(
operator|(
specifier|const
name|char
operator|*
name|p
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|strwidth
name|__P
argument_list|(
operator|(
specifier|const
name|char
operator|*
name|p
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|Abort
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
name|ExitSysinstall
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
name|Debug
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
name|void
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
name|mountpoint
operator|,
name|int
name|do_mkdir
operator|,
name|int
name|flags
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|Mkdir
name|__P
argument_list|(
operator|(
name|char
operator|*
name|path
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|Link
name|__P
argument_list|(
operator|(
name|char
operator|*
name|from
operator|,
name|char
operator|*
name|to
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|CopyFile
name|__P
argument_list|(
operator|(
name|char
operator|*
name|p1
operator|,
name|char
operator|*
name|p2
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_function_decl
name|u_long
name|PartMb
parameter_list|(
name|struct
name|disklabel
modifier|*
name|lbl
parameter_list|,
name|int
name|part
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
name|char
modifier|*
name|SetMount
name|__P
argument_list|(
operator|(
name|int
name|disk
operator|,
name|int
name|part
operator|,
name|char
operator|*
name|path
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|CleanMount
name|__P
argument_list|(
operator|(
name|int
name|disk
operator|,
name|int
name|part
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* exec.c */
end_comment

begin_decl_stmt
name|int
name|exec
name|__P
argument_list|(
operator|(
name|int
name|magic
operator|,
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

begin_define
define|#
directive|define
name|EXEC_MAXARG
value|100
end_define

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
comment|/* stage4.c */
end_comment

begin_decl_stmt
name|void
name|stage4
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* stage5.c */
end_comment

begin_decl_stmt
name|void
name|stage5
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

begin_comment
comment|/* makedevs.c */
end_comment

begin_decl_stmt
name|int
name|makedevs
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* ourcurses.c */
end_comment

begin_decl_stmt
name|int
name|edit_line
name|__P
argument_list|(
operator|(
name|WINDOW
operator|*
name|window
operator|,
name|int
name|y
operator|,
name|int
name|x
operator|,
name|char
operator|*
name|field
operator|,
name|int
name|width
operator|,
name|int
name|maxlen
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|AskEm
name|__P
argument_list|(
operator|(
name|WINDOW
operator|*
name|w
operator|,
name|char
operator|*
name|prompt
operator|,
name|char
operator|*
name|answer
operator|,
name|int
name|len
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|ShowFile
name|__P
argument_list|(
operator|(
name|char
operator|*
name|filename
operator|,
name|char
operator|*
name|header
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* bootarea.c */
end_comment

begin_decl_stmt
name|void
name|enable_label
name|__P
argument_list|(
operator|(
name|int
name|fd
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|disable_label
name|__P
argument_list|(
operator|(
name|int
name|fd
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|write_bootblocks
name|__P
argument_list|(
operator|(
name|int
name|fd
operator|,
expr|struct
name|disklabel
operator|*
name|lbl
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|build_bootblocks
name|__P
argument_list|(
operator|(
name|int
name|dfd
operator|,
expr|struct
name|disklabel
operator|*
name|label
operator|,
expr|struct
name|dos_partition
operator|*
name|dospart
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

end_unit

