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

begin_struct_decl
struct_decl|struct
name|msg
struct_decl|;
end_struct_decl

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

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

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

begin_decl_stmt
specifier|extern
name|struct
name|msginfo
name|msginfo
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

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
name|msgsys
parameter_list|(
name|int
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|msgctl
parameter_list|(
name|int
parameter_list|,
name|int
parameter_list|,
name|struct
name|msqid_ds
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|msgget
parameter_list|(
name|key_t
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|msgsnd
parameter_list|(
name|int
parameter_list|,
name|void
modifier|*
parameter_list|,
name|size_t
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|msgrcv
parameter_list|(
name|int
parameter_list|,
name|void
modifier|*
parameter_list|,
name|size_t
parameter_list|,
name|long
parameter_list|,
name|int
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

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_SYS_MSG_H_ */
end_comment

end_unit

