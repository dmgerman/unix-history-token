begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $Id$ */
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

begin_struct
struct|struct
name|sem
block|{
name|u_short
name|semval
decl_stmt|;
comment|/* semaphore value */
name|pid_t
name|sempid
decl_stmt|;
comment|/* pid of last operation */
name|u_short
name|semncnt
decl_stmt|;
comment|/* # awaiting semval> cval */
name|u_short
name|semzcnt
decl_stmt|;
comment|/* # awaiting semval = 0 */
block|}
struct|;
end_struct

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

begin_define
define|#
directive|define
name|MAX_SOPS
value|5
end_define

begin_comment
comment|/* maximum # of sembuf's per semop call */
end_comment

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

begin_ifdef
ifdef|#
directive|ifdef
name|KERNEL
end_ifdef

begin_comment
comment|/*  * Kernel implementation stuff  */
end_comment

begin_define
define|#
directive|define
name|SEMVMX
value|32767
end_define

begin_comment
comment|/* semaphore maximum value */
end_comment

begin_define
define|#
directive|define
name|SEMAEM
value|16384
end_define

begin_comment
comment|/* adjust on exit max value */
end_comment

begin_comment
comment|/*  * Permissions  */
end_comment

begin_define
define|#
directive|define
name|SEM_A
value|0200
end_define

begin_comment
comment|/* alter permission */
end_comment

begin_define
define|#
directive|define
name|SEM_R
value|0400
end_define

begin_comment
comment|/* read permission */
end_comment

begin_comment
comment|/*  * Undo structure (one per process)  */
end_comment

begin_struct
struct|struct
name|sem_undo
block|{
name|struct
name|sem_undo
modifier|*
name|un_next
decl_stmt|;
comment|/* ptr to next active undo structure */
name|struct
name|proc
modifier|*
name|un_proc
decl_stmt|;
comment|/* owner of this structure */
name|short
name|un_cnt
decl_stmt|;
comment|/* # of active entries */
struct|struct
name|undo
block|{
name|short
name|un_adjval
decl_stmt|;
comment|/* adjust on exit values */
name|short
name|un_num
decl_stmt|;
comment|/* semaphore # */
name|int
name|un_id
decl_stmt|;
comment|/* semid */
block|}
name|un_ent
index|[
literal|1
index|]
struct|;
comment|/* undo entries */
block|}
struct|;
end_struct

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
comment|/*  * Configuration parameters  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SEMMNI
end_ifndef

begin_define
define|#
directive|define
name|SEMMNI
value|10
end_define

begin_comment
comment|/* # of semaphore identifiers */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|SEMMNS
end_ifndef

begin_define
define|#
directive|define
name|SEMMNS
value|60
end_define

begin_comment
comment|/* # of semaphores in system */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|SEMUME
end_ifndef

begin_define
define|#
directive|define
name|SEMUME
value|10
end_define

begin_comment
comment|/* max # of undo entries per process */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|SEMMNU
end_ifndef

begin_define
define|#
directive|define
name|SEMMNU
value|30
end_define

begin_comment
comment|/* # of undo structures in system */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* shouldn't need tuning */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SEMMAP
end_ifndef

begin_define
define|#
directive|define
name|SEMMAP
value|30
end_define

begin_comment
comment|/* # of entries in semaphore map */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|SEMMSL
end_ifndef

begin_define
define|#
directive|define
name|SEMMSL
value|SEMMNS
end_define

begin_comment
comment|/* max # of semaphores per id */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|SEMOPM
end_ifndef

begin_define
define|#
directive|define
name|SEMOPM
value|100
end_define

begin_comment
comment|/* max # of operations per semop call */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* actual size of an undo structure */
end_comment

begin_define
define|#
directive|define
name|SEMUSZ
value|(sizeof(struct sem_undo)+sizeof(struct undo)*SEMUME)
end_define

begin_comment
comment|/*  * Structures allocated in machdep.c  */
end_comment

begin_decl_stmt
name|struct
name|semid_ds
modifier|*
name|sema
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* semaphore id pool */
end_comment

begin_decl_stmt
name|struct
name|sem
modifier|*
name|sem
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* semaphore pool */
end_comment

begin_decl_stmt
name|struct
name|map
modifier|*
name|semmap
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* semaphore allocation map */
end_comment

begin_decl_stmt
name|struct
name|sem_undo
modifier|*
name|semu_list
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* list of active undo structures */
end_comment

begin_decl_stmt
name|int
modifier|*
name|semu
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* undo structure pool */
end_comment

begin_comment
comment|/*  * Macro to find a particular sem_undo vector  */
end_comment

begin_define
define|#
directive|define
name|SEMU
parameter_list|(
name|ix
parameter_list|)
value|((struct sem_undo *)(((long)semu)+ix * SEMUSZ))
end_define

begin_comment
comment|/*  * Parameters to the semconfig system call  */
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|SEM_CONFIG_FREEZE
block|,
comment|/* Freeze the semaphore facility. */
name|SEM_CONFIG_THAW
comment|/* Thaw the semaphore facility. */
block|}
name|semconfig_ctl_t
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* KERNEL */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|KERNEL
end_ifndef

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_decl_stmt
name|__BEGIN_DECLS
name|int
name|semsys
name|__P
argument_list|(
operator|(
name|int
operator|,
operator|...
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|semctl
name|__P
argument_list|(
operator|(
name|int
operator|,
name|int
operator|,
name|int
operator|,
expr|union
name|semun
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|semget
name|__P
argument_list|(
operator|(
name|key_t
operator|,
name|int
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|semop
name|__P
argument_list|(
operator|(
name|int
operator|,
expr|struct
name|sembuf
operator|*
operator|,
name|unsigned
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_macro
name|__END_DECLS
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !KERNEL */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_SEM_H_ */
end_comment

end_unit

