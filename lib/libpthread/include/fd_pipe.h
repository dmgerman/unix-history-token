begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* ==== fd_pipe.h ============================================================  * Copyright (c) 1993 by Chris Provenzano, proven@athena.mit.edu  *  * Description : The new fast ITC pipe header.  *  *  1.00 93/08/14 proven  *      -Started coding this file.  */
end_comment

begin_struct
struct|struct
name|__pipe
block|{
name|semaphore
name|lock
decl_stmt|;
name|char
modifier|*
name|buf
decl_stmt|;
name|int
name|size
decl_stmt|;
name|int
name|flags
decl_stmt|;
name|int
name|count
decl_stmt|;
name|int
name|offset
decl_stmt|;
name|struct
name|pthread
modifier|*
name|wait
decl_stmt|;
name|char
modifier|*
name|wait_buf
decl_stmt|;
name|size_t
name|wait_size
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|RD_CLOSED
value|0x01
end_define

begin_define
define|#
directive|define
name|WR_CLOSED
value|0x02
end_define

end_unit

