begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1996 John S. Dyson  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice immediately at the beginning of the file, without modification,  *    this list of conditions, and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. Absolutely no warranty of function or purpose is made by the author  *    John S. Dyson.  * 4. This work was done expressly for inclusion into FreeBSD.  Other use  *    is allowed if this notation is included.  * 5. Modifications may be freely made to this file if the above conditions  *    are met.  *  * $Id: pipe.h,v 1.1 1996/01/28 23:38:22 dyson Exp $  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|OLD_PIPE
end_ifndef

begin_struct_decl
struct_decl|struct
name|vm_object
struct_decl|;
end_struct_decl

begin_comment
comment|/*  * pipe buffer information  * Separate in, out, cnt is used to simplify calculations.  */
end_comment

begin_struct
struct|struct
name|pipebuf
block|{
name|u_int
name|cnt
decl_stmt|;
comment|/* number of chars currently in buffer */
name|u_int
name|in
decl_stmt|;
comment|/* in pointer */
name|u_int
name|out
decl_stmt|;
comment|/* out pointer */
name|u_int
name|size
decl_stmt|;
comment|/* size of buffer */
name|caddr_t
name|buffer
decl_stmt|;
comment|/* kva of buffer */
name|struct
name|vm_object
modifier|*
name|object
decl_stmt|;
comment|/* VM object containing buffer */
block|}
struct|;
end_struct

begin_comment
comment|/*  * pipe_state bits  */
end_comment

begin_define
define|#
directive|define
name|PIPE_NBIO
value|0x1
end_define

begin_comment
comment|/* non-blocking I/O */
end_comment

begin_define
define|#
directive|define
name|PIPE_ASYNC
value|0x4
end_define

begin_comment
comment|/* Async? I/O */
end_comment

begin_define
define|#
directive|define
name|PIPE_WANTR
value|0x8
end_define

begin_comment
comment|/* Reader wants some characters */
end_comment

begin_define
define|#
directive|define
name|PIPE_WANTW
value|0x10
end_define

begin_comment
comment|/* Writer wants space to put characters */
end_comment

begin_define
define|#
directive|define
name|PIPE_WANT
value|0x20
end_define

begin_comment
comment|/* Pipe is wanted to be run-down */
end_comment

begin_define
define|#
directive|define
name|PIPE_SEL
value|0x40
end_define

begin_comment
comment|/* Pipe has a select active */
end_comment

begin_define
define|#
directive|define
name|PIPE_EOF
value|0x80
end_define

begin_comment
comment|/* Pipe is in EOF condition */
end_comment

begin_define
define|#
directive|define
name|PIPE_LOCK
value|0x100
end_define

begin_comment
comment|/* Process has exclusive access to pointers/data */
end_comment

begin_define
define|#
directive|define
name|PIPE_LWANT
value|0x200
end_define

begin_comment
comment|/* Process wants exclusive access to pointers/data */
end_comment

begin_comment
comment|/*  * Per-pipe data structure  * Two of these are linked together to produce bi-directional  * pipes.  */
end_comment

begin_struct
struct|struct
name|pipe
block|{
name|struct
name|pipebuf
name|pipe_buffer
decl_stmt|;
comment|/* data storage */
name|struct
name|selinfo
name|pipe_sel
decl_stmt|;
comment|/* for compat with select */
name|struct
name|timeval
name|pipe_atime
decl_stmt|;
comment|/* time of last access */
name|struct
name|timeval
name|pipe_mtime
decl_stmt|;
comment|/* time of last modify */
name|struct
name|timeval
name|pipe_ctime
decl_stmt|;
comment|/* time of status change */
name|int
name|pipe_pgid
decl_stmt|;
name|struct
name|pipe
modifier|*
name|pipe_peer
decl_stmt|;
comment|/* link with other direction */
name|u_int
name|pipe_state
decl_stmt|;
comment|/* pipe status info */
name|int
name|pipe_busy
decl_stmt|;
comment|/* busy flag, mostly to handle rundown sanely */
block|}
struct|;
end_struct

begin_decl_stmt
name|int
name|pipe_stat
name|__P
argument_list|(
operator|(
expr|struct
name|pipe
operator|*
name|pipe
operator|,
expr|struct
name|stat
operator|*
name|ub
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

