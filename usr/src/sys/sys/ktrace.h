begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1988 The Regents of the University of California.  * All rights reserved.  *  * Redistribution and use in source and binary forms are permitted  * provided that the above copyright notice and this paragraph are  * duplicated in all such forms and that any documentation,  * advertising materials, and other materials related to such  * distribution and use acknowledge that the software was developed  * by the University of California, Berkeley.  The name of the  * University may not be used to endorse or promote products derived  * from this software without specific prior written permission.  * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED  * WARRANTIES OF MERCHANTIBILITY AND FITNESS FOR A PARTICULAR PURPOSE.  *  *	@(#)ktrace.h	7.1 (Berkeley) %G%  */
end_comment

begin_comment
comment|/*  * operations to ktrace system call  (op& 0x3)  */
end_comment

begin_define
define|#
directive|define
name|KTROP_SET
value|0
end_define

begin_comment
comment|/* set traces */
end_comment

begin_define
define|#
directive|define
name|KTROP_CLEAR
value|1
end_define

begin_comment
comment|/* clear traces */
end_comment

begin_define
define|#
directive|define
name|KTROP_CLEARFILE
value|2
end_define

begin_comment
comment|/* stop all tracing to file */
end_comment

begin_comment
comment|/*  * flags to OR in with operation  */
end_comment

begin_define
define|#
directive|define
name|KTROP_INHERITFLAG
value|4
end_define

begin_comment
comment|/* pass to children flag */
end_comment

begin_comment
comment|/*  * ktrace record header  */
end_comment

begin_struct
struct|struct
name|ktr_header
block|{
name|int
name|ktr_len
decl_stmt|;
comment|/* length of buf */
name|short
name|ktr_type
decl_stmt|;
comment|/* trace record type */
name|pid_t
name|ktr_pid
decl_stmt|;
comment|/* process id */
name|char
name|ktr_comm
index|[
name|MAXCOMLEN
operator|+
literal|1
index|]
decl_stmt|;
comment|/* command name */
name|struct
name|timeval
name|ktr_time
decl_stmt|;
comment|/* timestamp */
name|caddr_t
name|ktr_buf
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Test for kernel trace point  */
end_comment

begin_define
define|#
directive|define
name|KTRPOINT
parameter_list|(
name|p
parameter_list|,
name|type
parameter_list|)
value|((p)->p_traceflag& (1<<(type)))
end_define

begin_comment
comment|/*  * ktrace record types - add new ones here  */
end_comment

begin_comment
comment|/*  * KTR_SYSCALL - system call record  */
end_comment

begin_define
define|#
directive|define
name|KTR_SYSCALL
value|0x1
end_define

begin_struct
struct|struct
name|ktr_syscall
block|{
name|short
name|ktr_code
decl_stmt|;
comment|/* syscall number */
name|short
name|ktr_narg
decl_stmt|;
comment|/* number of arguments */
comment|/* 	 * followed by ktr_narg ints 	 */
block|}
struct|;
end_struct

begin_comment
comment|/*  * KTR_SYSRET - return from system call record  */
end_comment

begin_define
define|#
directive|define
name|KTR_SYSRET
value|0x2
end_define

begin_struct
struct|struct
name|ktr_sysret
block|{
name|short
name|ktr_code
decl_stmt|;
name|short
name|ktr_eosys
decl_stmt|;
name|int
name|ktr_error
decl_stmt|;
name|int
name|ktr_retval
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * KTR_NAMEI - namei record  */
end_comment

begin_define
define|#
directive|define
name|KTR_NAMEI
value|0x3
end_define

begin_comment
comment|/* record contains pathname */
end_comment

begin_comment
comment|/*  * KTR_GENIO - trace generic process i/o  */
end_comment

begin_define
define|#
directive|define
name|KTR_GENIO
value|0x4
end_define

begin_struct
struct|struct
name|ktr_genio
block|{
name|int
name|ktr_fd
decl_stmt|;
name|enum
name|uio_rw
name|ktr_rw
decl_stmt|;
comment|/* 	 * followed by data successfully read/written 	 */
block|}
struct|;
end_struct

begin_comment
comment|/*  * kernel trace facilities  */
end_comment

begin_define
define|#
directive|define
name|KTRFAC_SYSCALL
value|(1<<KTR_SYSCALL)
end_define

begin_define
define|#
directive|define
name|KTRFAC_SYSRET
value|(1<<KTR_SYSRET)
end_define

begin_define
define|#
directive|define
name|KTRFAC_NAMEI
value|(1<<KTR_NAMEI)
end_define

begin_define
define|#
directive|define
name|KTRFAC_GENIO
value|(1<<KTR_GENIO)
end_define

end_unit

