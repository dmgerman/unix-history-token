begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1988 University of Utah.  * Copyright (c) 1990, 1993  *	The Regents of the University of California.  All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * the Systems Programming Group of the University of Utah Computer  * Science Department.  *  * %sccs.include.redist.c%  *  *	@(#)ipc.h	8.2 (Berkeley) %G%  */
end_comment

begin_comment
comment|/*  * SVID compatible ipc.h file  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SYS_IPC_H_
end_ifndef

begin_define
define|#
directive|define
name|_SYS_IPC_H_
end_define

begin_typedef
typedef|typedef
name|long
name|key_t
typedef|;
end_typedef

begin_comment
comment|/* XXX should be in types.h */
end_comment

begin_struct
struct|struct
name|ipc_perm
block|{
name|ushort
name|cuid
decl_stmt|;
comment|/* creator user id */
name|ushort
name|cgid
decl_stmt|;
comment|/* creator group id */
name|ushort
name|uid
decl_stmt|;
comment|/* user id */
name|ushort
name|gid
decl_stmt|;
comment|/* group id */
name|ushort
name|mode
decl_stmt|;
comment|/* r/w permission */
name|ushort
name|seq
decl_stmt|;
comment|/* sequence # (to generate unique msg/sem/shm id) */
name|key_t
name|key
decl_stmt|;
comment|/* user specified msg/sem/shm key */
block|}
struct|;
end_struct

begin_comment
comment|/* common mode bits */
end_comment

begin_define
define|#
directive|define
name|IPC_R
value|00400
end_define

begin_comment
comment|/* read permission */
end_comment

begin_define
define|#
directive|define
name|IPC_W
value|00200
end_define

begin_comment
comment|/* write/alter permission */
end_comment

begin_comment
comment|/* SVID required constants (same values as system 5) */
end_comment

begin_define
define|#
directive|define
name|IPC_CREAT
value|01000
end_define

begin_comment
comment|/* create entry if key does not exist */
end_comment

begin_define
define|#
directive|define
name|IPC_EXCL
value|02000
end_define

begin_comment
comment|/* fail if key exists */
end_comment

begin_define
define|#
directive|define
name|IPC_NOWAIT
value|04000
end_define

begin_comment
comment|/* error if request must wait */
end_comment

begin_define
define|#
directive|define
name|IPC_PRIVATE
value|(key_t)0
end_define

begin_comment
comment|/* private key */
end_comment

begin_define
define|#
directive|define
name|IPC_RMID
value|0
end_define

begin_comment
comment|/* remove identifier */
end_comment

begin_define
define|#
directive|define
name|IPC_SET
value|1
end_define

begin_comment
comment|/* set options */
end_comment

begin_define
define|#
directive|define
name|IPC_STAT
value|2
end_define

begin_comment
comment|/* get options */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_SYS_IPC_H_ */
end_comment

end_unit

