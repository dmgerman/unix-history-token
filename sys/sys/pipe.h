begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1996 John S. Dyson  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice immediately at the beginning of the file, without modification,  *    this list of conditions, and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. Absolutely no warranty of function or purpose is made by the author  *    John S. Dyson.  * 4. This work was done expressly for inclusion into FreeBSD.  Other use  *    is allowed if this notation is included.  * 5. Modifications may be freely made to this file if the above conditions  *    are met.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SYS_PIPE_H_
end_ifndef

begin_define
define|#
directive|define
name|_SYS_PIPE_H_
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|_KERNEL
end_ifndef

begin_include
include|#
directive|include
file|<sys/time.h>
end_include

begin_comment
comment|/* for struct timespec */
end_comment

begin_include
include|#
directive|include
file|<sys/select.h>
end_include

begin_comment
comment|/* for struct selinfo */
end_comment

begin_include
include|#
directive|include
file|<vm/vm.h>
end_include

begin_comment
comment|/* for vm_page_t */
end_comment

begin_include
include|#
directive|include
file|<machine/param.h>
end_include

begin_comment
comment|/* for PAGE_SIZE */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Pipe buffer size, keep moderate in value, pipes take kva space.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|PIPE_SIZE
end_ifndef

begin_define
define|#
directive|define
name|PIPE_SIZE
value|16384
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|BIG_PIPE_SIZE
end_ifndef

begin_define
define|#
directive|define
name|BIG_PIPE_SIZE
value|(64*1024)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * PIPE_MINDIRECT MUST be smaller than PIPE_SIZE and MUST be bigger  * than PIPE_BUF.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|PIPE_MINDIRECT
end_ifndef

begin_define
define|#
directive|define
name|PIPE_MINDIRECT
value|8192
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|PIPENPAGES
value|(BIG_PIPE_SIZE / PAGE_SIZE + 1)
end_define

begin_comment
comment|/*  * Pipe buffer information.  * Separate in, out, cnt are used to simplify calculations.  * Buffered write is active when the buffer.cnt field is set.  */
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
comment|/*  * Information to support direct transfers between processes for pipes.  */
end_comment

begin_struct
struct|struct
name|pipemapping
block|{
name|vm_offset_t
name|kva
decl_stmt|;
comment|/* kernel virtual address */
name|vm_size_t
name|cnt
decl_stmt|;
comment|/* number of chars in buffer */
name|vm_size_t
name|pos
decl_stmt|;
comment|/* current position of transfer */
name|int
name|npages
decl_stmt|;
comment|/* number of pages */
name|vm_page_t
name|ms
index|[
name|PIPENPAGES
index|]
decl_stmt|;
comment|/* pages in source process */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Bits in pipe_state.  */
end_comment

begin_define
define|#
directive|define
name|PIPE_ASYNC
value|0x004
end_define

begin_comment
comment|/* Async? I/O. */
end_comment

begin_define
define|#
directive|define
name|PIPE_WANTR
value|0x008
end_define

begin_comment
comment|/* Reader wants some characters. */
end_comment

begin_define
define|#
directive|define
name|PIPE_WANTW
value|0x010
end_define

begin_comment
comment|/* Writer wants space to put characters. */
end_comment

begin_define
define|#
directive|define
name|PIPE_WANT
value|0x020
end_define

begin_comment
comment|/* Pipe is wanted to be run-down. */
end_comment

begin_define
define|#
directive|define
name|PIPE_SEL
value|0x040
end_define

begin_comment
comment|/* Pipe has a select active. */
end_comment

begin_define
define|#
directive|define
name|PIPE_EOF
value|0x080
end_define

begin_comment
comment|/* Pipe is in EOF condition. */
end_comment

begin_define
define|#
directive|define
name|PIPE_LOCK
value|0x100
end_define

begin_comment
comment|/* Process has exclusive access to pointers/data. */
end_comment

begin_define
define|#
directive|define
name|PIPE_LWANT
value|0x200
end_define

begin_comment
comment|/* Process wants exclusive access to pointers/data. */
end_comment

begin_define
define|#
directive|define
name|PIPE_DIRECTW
value|0x400
end_define

begin_comment
comment|/* Pipe direct write active. */
end_comment

begin_define
define|#
directive|define
name|PIPE_DIRECTOK
value|0x800
end_define

begin_comment
comment|/* Direct mode ok. */
end_comment

begin_comment
comment|/*  * Per-pipe data structure.  * Two of these are linked together to produce bi-directional pipes.  */
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
name|pipemapping
name|pipe_map
decl_stmt|;
comment|/* pipe mapping for direct I/O */
name|struct
name|selinfo
name|pipe_sel
decl_stmt|;
comment|/* for compat with select */
name|struct
name|timespec
name|pipe_atime
decl_stmt|;
comment|/* time of last access */
name|struct
name|timespec
name|pipe_mtime
decl_stmt|;
comment|/* time of last modify */
name|struct
name|timespec
name|pipe_ctime
decl_stmt|;
comment|/* time of status change */
name|struct
name|sigio
modifier|*
name|pipe_sigio
decl_stmt|;
comment|/* information for async I/O */
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

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_SYS_PIPE_H_ */
end_comment

end_unit

