begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1989, 1993  *	The Regents of the University of California.  All rights reserved.  *  * %sccs.include.redist.c%  *  *	@(#)ucred.h	8.2 (Berkeley) %G%  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SYS_UCRED_H_
end_ifndef

begin_define
define|#
directive|define
name|_SYS_UCRED_H_
end_define

begin_comment
comment|/*  * Credentials.  */
end_comment

begin_struct
struct|struct
name|ucred
block|{
name|u_short
name|cr_ref
decl_stmt|;
comment|/* reference count */
name|uid_t
name|cr_uid
decl_stmt|;
comment|/* effective user id */
name|short
name|cr_ngroups
decl_stmt|;
comment|/* number of groups */
name|gid_t
name|cr_groups
index|[
name|NGROUPS
index|]
decl_stmt|;
comment|/* groups */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|cr_gid
value|cr_groups[0]
end_define

begin_define
define|#
directive|define
name|NOCRED
value|((struct ucred *)-1)
end_define

begin_comment
comment|/* no credential available */
end_comment

begin_define
define|#
directive|define
name|FSCRED
value|((struct ucred *)-2)
end_define

begin_comment
comment|/* filesystem credential */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|KERNEL
end_ifdef

begin_define
define|#
directive|define
name|crhold
parameter_list|(
name|cr
parameter_list|)
value|(cr)->cr_ref++
end_define

begin_function_decl
name|struct
name|ucred
modifier|*
name|crget
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|ucred
modifier|*
name|crcopy
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|ucred
modifier|*
name|crdup
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* KERNEL */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_SYS_UCRED_H_ */
end_comment

end_unit

