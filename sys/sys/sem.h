begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_comment
comment|/*	$NetBSD: sem.h,v 1.5 1994/06/29 06:45:15 cgd Exp $	*/
end_comment

begin_comment
comment|/*  * SVID compatible sem.h file  *  * Author:  Daniel Boulet  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SYS_SEM_H_
end_ifndef

begin_define
define|#
directive|define
name|_SYS_SEM_H_
end_define

begin_include
include|#
directive|include
file|<sys/ipc.h>
end_include

begin_struct_decl
struct_decl|struct
name|sem
struct_decl|;
end_struct_decl

begin_struct
struct|struct
name|semid_ds
block|{
name|struct
name|ipc_perm
name|sem_perm
decl_stmt|;
comment|/* operation permission struct */
name|struct
name|sem
modifier|*
name|sem_base
decl_stmt|;
comment|/* pointer to first semaphore in set */
name|u_short
name|sem_nsems
decl_stmt|;
comment|/* number of sems in set */
name|time_t
name|sem_otime
decl_stmt|;
comment|/* last operation time */
name|long
name|sem_pad1
decl_stmt|;
comment|/* SVABI/386 says I need this here */
name|time_t
name|sem_ctime
decl_stmt|;
comment|/* last change time */
comment|/* Times measured in secs since */
comment|/* 00:00:00 GMT, Jan. 1, 1970 */
name|long
name|sem_pad2
decl_stmt|;
comment|/* SVABI/386 says I need this here */
name|long
name|sem_pad3
index|[
literal|4
index|]
decl_stmt|;
comment|/* SVABI/386 says I need this here */
block|}
struct|;
end_struct

begin_comment
comment|/*  * semop's sops parameter structure  */
end_comment

begin_struct
struct|struct
name|sembuf
block|{
name|u_short
name|sem_num
decl_stmt|;
comment|/* semaphore # */
name|short
name|sem_op
decl_stmt|;
comment|/* semaphore operation */
name|short
name|sem_flg
decl_stmt|;
comment|/* operation flags */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|SEM_UNDO
value|010000
end_define

begin_comment
comment|/*  * semctl's arg parameter structure  */
end_comment

begin_union
union|union
name|semun
block|{
name|int
name|val
decl_stmt|;
comment|/* value for SETVAL */
name|struct
name|semid_ds
modifier|*
name|buf
decl_stmt|;
comment|/* buffer for IPC_STAT& IPC_SET */
name|u_short
modifier|*
name|array
decl_stmt|;
comment|/* array for GETALL& SETALL */
block|}
union|;
end_union

begin_comment
comment|/*  * commands for semctl  */
end_comment

begin_define
define|#
directive|define
name|GETNCNT
value|3
end_define

begin_comment
comment|/* Return the value of semncnt {READ} */
end_comment

begin_define
define|#
directive|define
name|GETPID
value|4
end_define

begin_comment
comment|/* Return the value of sempid {READ} */
end_comment

begin_define
define|#
directive|define
name|GETVAL
value|5
end_define

begin_comment
comment|/* Return the value of semval {READ} */
end_comment

begin_define
define|#
directive|define
name|GETALL
value|6
end_define

begin_comment
comment|/* Return semvals into arg.array {READ} */
end_comment

begin_define
define|#
directive|define
name|GETZCNT
value|7
end_define

begin_comment
comment|/* Return the value of semzcnt {READ} */
end_comment

begin_define
define|#
directive|define
name|SETVAL
value|8
end_define

begin_comment
comment|/* Set the value of semval to arg.val {ALTER} */
end_comment

begin_define
define|#
directive|define
name|SETALL
value|9
end_define

begin_comment
comment|/* Set semvals from arg.array {ALTER} */
end_comment

begin_define
define|#
directive|define
name|SEM_STAT
value|10
end_define

begin_comment
comment|/* Like IPC_STAT but treats semid as sema-index */
end_comment

begin_define
define|#
directive|define
name|SEM_INFO
value|11
end_define

begin_comment
comment|/* Like IPC_INFO but treats semid as sema-index */
end_comment

begin_comment
comment|/*  * Permissions  */
end_comment

begin_define
define|#
directive|define
name|SEM_A
value|IPC_W
end_define

begin_comment
comment|/* alter permission */
end_comment

begin_define
define|#
directive|define
name|SEM_R
value|IPC_R
end_define

begin_comment
comment|/* read permission */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_comment
comment|/*  * semaphore info struct  */
end_comment

begin_struct
struct|struct
name|seminfo
block|{
name|int
name|semmap
decl_stmt|,
comment|/* # of entries in semaphore map */
name|semmni
decl_stmt|,
comment|/* # of semaphore identifiers */
name|semmns
decl_stmt|,
comment|/* # of semaphores in system */
name|semmnu
decl_stmt|,
comment|/* # of undo structures in system */
name|semmsl
decl_stmt|,
comment|/* max # of semaphores per id */
name|semopm
decl_stmt|,
comment|/* max # of operations per semop call */
name|semume
decl_stmt|,
comment|/* max # of undo entries per process */
name|semusz
decl_stmt|,
comment|/* size in bytes of undo structure */
name|semvmx
decl_stmt|,
comment|/* semaphore maximum value */
name|semaem
decl_stmt|;
comment|/* adjust on exit max value */
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|struct
name|seminfo
name|seminfo
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* internal "mode" bits */
end_comment

begin_define
define|#
directive|define
name|SEM_ALLOC
value|01000
end_define

begin_comment
comment|/* semaphore is allocated */
end_comment

begin_define
define|#
directive|define
name|SEM_DEST
value|02000
end_define

begin_comment
comment|/* semaphore will be destroyed on last detach */
end_comment

begin_comment
comment|/*  * Process sem_undo vectors at proc exit.  */
end_comment

begin_function_decl
name|void
name|semexit
parameter_list|(
name|struct
name|proc
modifier|*
name|p
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _KERNEL */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_KERNEL
end_ifndef

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_function_decl
name|__BEGIN_DECLS
name|int
name|semsys
parameter_list|(
name|int
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|semctl
parameter_list|(
name|int
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|semget
parameter_list|(
name|key_t
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|semop
parameter_list|(
name|int
parameter_list|,
name|struct
name|sembuf
modifier|*
parameter_list|,
name|unsigned
parameter_list|)
function_decl|;
end_function_decl

begin_macro
name|__END_DECLS
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_KERNEL */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_SEM_H_ */
end_comment

end_unit

