begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_OPENSOLARIS_MNTTAB_H_
end_ifndef

begin_define
define|#
directive|define
name|_OPENSOLARIS_MNTTAB_H_
end_define

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<sys/mount.h>
end_include

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<paths.h>
end_include

begin_define
define|#
directive|define
name|MNTTAB
value|_PATH_DEVZERO
end_define

begin_define
define|#
directive|define
name|MNT_LINE_MAX
value|1024
end_define

begin_define
define|#
directive|define
name|MS_OVERLAY
value|0x0
end_define

begin_define
define|#
directive|define
name|MS_NOMNTTAB
value|0x0
end_define

begin_define
define|#
directive|define
name|MS_RDONLY
value|0x1
end_define

begin_define
define|#
directive|define
name|umount2
parameter_list|(
name|p
parameter_list|,
name|f
parameter_list|)
value|unmount(p, f)
end_define

begin_struct
struct|struct
name|mnttab
block|{
name|char
modifier|*
name|mnt_special
decl_stmt|;
name|char
modifier|*
name|mnt_mountp
decl_stmt|;
name|char
modifier|*
name|mnt_fstype
decl_stmt|;
name|char
modifier|*
name|mnt_mntopts
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|extmnttab
value|mnttab
end_define

begin_function_decl
name|int
name|getmntany
parameter_list|(
name|FILE
modifier|*
name|fd
parameter_list|,
name|struct
name|mnttab
modifier|*
name|mgetp
parameter_list|,
name|struct
name|mnttab
modifier|*
name|mrefp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|getmntent
parameter_list|(
name|FILE
modifier|*
name|fp
parameter_list|,
name|struct
name|mnttab
modifier|*
name|mp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|hasmntopt
parameter_list|(
name|struct
name|mnttab
modifier|*
name|mnt
parameter_list|,
name|char
modifier|*
name|opt
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|statfs2mnttab
parameter_list|(
name|struct
name|statfs
modifier|*
name|sfs
parameter_list|,
name|struct
name|mnttab
modifier|*
name|mp
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_OPENSOLARIS_MNTTAB_H_ */
end_comment

end_unit

