begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_comment
comment|/*	$NetBSD: msg.h,v 1.4 1994/06/29 06:44:43 cgd Exp $	*/
end_comment

begin_comment
comment|/*  * SVID compatible msg.h file  *  * Author:  Daniel Boulet  *  * Copyright 1993 Daniel Boulet and RTMX Inc.  *  * This system call was implemented by Daniel Boulet under contract from RTMX.  *  * Redistribution and use in source forms, with and without modification,  * are permitted provided that this entire comment appears intact.  *  * Redistribution in binary form may occur without any restrictions.  * Obviously, it would be nice if you gave credit where credit is due  * but requiring it would be too onerous.  *  * This software is provided ``AS IS'' without any warranties of any kind.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SYS_MSG_H_
end_ifndef

begin_define
define|#
directive|define
name|_SYS_MSG_H_
end_define

begin_include
include|#
directive|include
file|<sys/ipc.h>
end_include

begin_comment
comment|/*  * The MSG_NOERROR identifier value, the msqid_ds struct and the msg struct  * are as defined by the SV API Intel 386 Processor Supplement.  */
end_comment

begin_define
define|#
directive|define
name|MSG_NOERROR
value|010000
end_define

begin_comment
comment|/* don't complain about too long msgs */
end_comment

begin_struct
struct|struct
name|msqid_ds
block|{
name|struct
name|ipc_perm
name|msg_perm
decl_stmt|;
comment|/* msg queue permission bits */
name|struct
name|msg
modifier|*
name|msg_first
decl_stmt|;
comment|/* first message in the queue */
name|struct
name|msg
modifier|*
name|msg_last
decl_stmt|;
comment|/* last message in the queue */
name|u_long
name|msg_cbytes
decl_stmt|;
comment|/* number of bytes in use on the queue */
name|u_long
name|msg_qnum
decl_stmt|;
comment|/* number of msgs in the queue */
name|u_long
name|msg_qbytes
decl_stmt|;
comment|/* max # of bytes on the queue */
name|pid_t
name|msg_lspid
decl_stmt|;
comment|/* pid of last msgsnd() */
name|pid_t
name|msg_lrpid
decl_stmt|;
comment|/* pid of last msgrcv() */
name|time_t
name|msg_stime
decl_stmt|;
comment|/* time of last msgsnd() */
name|long
name|msg_pad1
decl_stmt|;
name|time_t
name|msg_rtime
decl_stmt|;
comment|/* time of last msgrcv() */
name|long
name|msg_pad2
decl_stmt|;
name|time_t
name|msg_ctime
decl_stmt|;
comment|/* time of last msgctl() */
name|long
name|msg_pad3
decl_stmt|;
name|long
name|msg_pad4
index|[
literal|4
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|msg
block|{
name|struct
name|msg
modifier|*
name|msg_next
decl_stmt|;
comment|/* next msg in the chain */
name|long
name|msg_type
decl_stmt|;
comment|/* type of this message */
comment|/*>0 -> type of this message */
comment|/* 0 -> free header */
name|u_short
name|msg_ts
decl_stmt|;
comment|/* size of this message */
name|short
name|msg_spot
decl_stmt|;
comment|/* location of start of msg in buffer */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Structure describing a message.  The SVID doesn't suggest any  * particular name for this structure.  There is a reference in the  * msgop man page that reads "The structure mymsg is an example of what  * this user defined buffer might look like, and includes the following  * members:".  This sentence is followed by two lines equivalent  * to the mtype and mtext field declarations below.  It isn't clear  * if "mymsg" refers to the naem of the structure type or the name of an  * instance of the structure...  */
end_comment

begin_struct
struct|struct
name|mymsg
block|{
name|long
name|mtype
decl_stmt|;
comment|/* message type (+ve integer) */
name|char
name|mtext
index|[
literal|1
index|]
decl_stmt|;
comment|/* message body */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Based on the configuration parameters described in an SVR2 (yes, two)  * config(1m) man page.  *  * Each message is broken up and stored in segments that are msgssz bytes  * long.  For efficiency reasons, this should be a power of two.  Also,  * it doesn't make sense if it is less than 8 or greater than about 256.  * Consequently, msginit in kern/sysv_msg.c checks that msgssz is a power of  * two between 8 and 1024 inclusive (and panic's if it isn't).  */
end_comment

begin_struct
struct|struct
name|msginfo
block|{
name|int
name|msgmax
decl_stmt|,
comment|/* max chars in a message */
name|msgmni
decl_stmt|,
comment|/* max message queue identifiers */
name|msgmnb
decl_stmt|,
comment|/* max chars in a queue */
name|msgtql
decl_stmt|,
comment|/* max messages in system */
name|msgssz
decl_stmt|,
comment|/* size of a message segment (see notes above) */
name|msgseg
decl_stmt|;
comment|/* number of message segments */
block|}
struct|;
end_struct

begin_ifdef
ifdef|#
directive|ifdef
name|KERNEL
end_ifdef

begin_decl_stmt
specifier|extern
name|struct
name|msginfo
name|msginfo
decl_stmt|;
end_decl_stmt

begin_ifndef
ifndef|#
directive|ifndef
name|MSGSSZ
end_ifndef

begin_define
define|#
directive|define
name|MSGSSZ
value|8
end_define

begin_comment
comment|/* Each segment must be 2^N long */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|MSGSEG
end_ifndef

begin_define
define|#
directive|define
name|MSGSEG
value|2048
end_define

begin_comment
comment|/* must be less than 32767 */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|MSGMAX
value|(MSGSSZ*MSGSEG)
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|MSGMNB
end_ifndef

begin_define
define|#
directive|define
name|MSGMNB
value|2048
end_define

begin_comment
comment|/* max # of bytes in a queue */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|MSGMNI
end_ifndef

begin_define
define|#
directive|define
name|MSGMNI
value|40
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|MSGTQL
end_ifndef

begin_define
define|#
directive|define
name|MSGTQL
value|40
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * macros to convert between msqid_ds's and msqid's.  * (specific to this implementation)  */
end_comment

begin_define
define|#
directive|define
name|MSQID
parameter_list|(
name|ix
parameter_list|,
name|ds
parameter_list|)
value|((ix)& 0xffff | (((ds).msg_perm.seq<< 16)& 0xffff0000))
end_define

begin_define
define|#
directive|define
name|MSQID_IX
parameter_list|(
name|id
parameter_list|)
value|((id)& 0xffff)
end_define

begin_define
define|#
directive|define
name|MSQID_SEQ
parameter_list|(
name|id
parameter_list|)
value|(((id)>> 16)& 0xffff)
end_define

begin_comment
comment|/*  * The rest of this file is specific to this particular implementation.  */
end_comment

begin_comment
comment|/*  * Stuff allocated in machdep.h  */
end_comment

begin_struct
struct|struct
name|msgmap
block|{
name|short
name|next
decl_stmt|;
comment|/* next segment in buffer */
comment|/* -1 -> available */
comment|/* 0..(MSGSEG-1) -> index of next segment */
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|msgpool
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* MSGMAX byte long msg buffer pool */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|msgmap
modifier|*
name|msgmaps
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* MSGSEG msgmap structures */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|msg
modifier|*
name|msghdrs
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* MSGTQL msg headers */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|msqid_ds
modifier|*
name|msqids
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* MSGMNI msqid_ds struct's */
end_comment

begin_define
define|#
directive|define
name|MSG_LOCKED
value|01000
end_define

begin_comment
comment|/* Is this msqid_ds locked? */
end_comment

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
name|msgsys
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
name|msgctl
name|__P
argument_list|(
operator|(
name|int
operator|,
name|int
operator|,
expr|struct
name|msqid_ds
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|msgget
name|__P
argument_list|(
operator|(
name|key_t
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|msgsnd
name|__P
argument_list|(
operator|(
name|int
operator|,
name|void
operator|*
operator|,
name|size_t
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|msgrcv
name|__P
argument_list|(
operator|(
name|int
operator|,
name|void
operator|*
operator|,
name|size_t
operator|,
name|long
operator|,
name|int
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
comment|/* !_SYS_MSG_H_ */
end_comment

end_unit

