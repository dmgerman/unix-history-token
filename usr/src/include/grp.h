begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1989 The Regents of the University of California.  * All rights reserved.  *  * %sccs.include.redist.c%  *  *	@(#)grp.h	5.1 (Berkeley) %G%  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_POSIX_SOURCE
end_ifndef

begin_define
define|#
directive|define
name|_PATH_GROUP
value|"/etc/group"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_struct
struct|struct
name|group
block|{
name|char
modifier|*
name|gr_name
decl_stmt|;
comment|/* group name */
name|char
modifier|*
name|gr_passwd
decl_stmt|;
comment|/* group password */
name|int
name|gr_gid
decl_stmt|;
comment|/* group id */
name|char
modifier|*
modifier|*
name|gr_mem
decl_stmt|;
comment|/* group members */
block|}
struct|;
end_struct

begin_ifdef
ifdef|#
directive|ifdef
name|__STDC__
end_ifdef

begin_function_decl
specifier|extern
name|struct
name|group
modifier|*
name|getgrgid
parameter_list|(
name|gid_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|struct
name|group
modifier|*
name|getgrnam
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_ifndef
ifndef|#
directive|ifndef
name|_POSIX_SOURCE
end_ifndef

begin_function_decl
specifier|extern
name|struct
name|group
modifier|*
name|getgrent
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|setgrent
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|endgrent
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|setgrfile
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|setgroupent
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_else
else|#
directive|else
end_else

begin_function_decl
specifier|extern
name|struct
name|group
modifier|*
name|getgrgid
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|struct
name|group
modifier|*
name|getgrnam
parameter_list|()
function_decl|;
end_function_decl

begin_ifndef
ifndef|#
directive|ifndef
name|_POSIX_SOURCE
end_ifndef

begin_function_decl
specifier|extern
name|struct
name|group
modifier|*
name|getgrent
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|setgrent
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|endgrent
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|setgrfile
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|setgroupent
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

end_unit

