begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1989, 1993  *	The Regents of the University of California.  All rights reserved.  * (c) UNIX System Laboratories, Inc.  * All or some portions of this file are derived from material licensed  * to the University of California by American Telephone and Telegraph  * Co. or Unix System Laboratories, Inc. and are reproduced herein with  * the permission of UNIX System Laboratories, Inc.  *  * %sccs.include.redist.c%  *  *	@(#)grp.h	8.2 (Berkeley) %G%  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_GRP_H_
end_ifndef

begin_define
define|#
directive|define
name|_GRP_H_
end_define

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

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_decl_stmt
name|__BEGIN_DECLS
name|struct
name|group
modifier|*
name|getgrgid
name|__P
argument_list|(
operator|(
name|gid_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|group
modifier|*
name|getgrnam
name|__P
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_ifndef
ifndef|#
directive|ifndef
name|_POSIX_SOURCE
end_ifndef

begin_decl_stmt
name|struct
name|group
modifier|*
name|getgrent
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|setgrent
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
name|endgrent
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
name|setgrfile
name|__P
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|setgroupent
name|__P
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_macro
name|__END_DECLS
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_GRP_H_ */
end_comment

end_unit

