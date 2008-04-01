begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
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
value|_PATH_DEVNULL
end_define

begin_define
define|#
directive|define
name|MNT_LINE_MAX
value|1024
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

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_OPENSOLARIS_MNTTAB_H_ */
end_comment

end_unit

