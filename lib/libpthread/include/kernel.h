begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* ==== kernel.h ============================================================  * Copyright (c) 1993 by Chris Provenzano, proven@athena.mit.edu  *  * Description : mutex header.  *  *  1.00 93/07/22 proven  *      -Started coding this file.  */
end_comment

begin_comment
comment|/*  * Defines only for the pthread user kernel.  */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|PTHREAD_KERNEL
argument_list|)
end_if

begin_define
define|#
directive|define
name|PANIC
parameter_list|()
value|abort()
end_define

begin_comment
comment|/* Time each rr thread gets */
end_comment

begin_define
define|#
directive|define
name|PTHREAD_RR_TIMEOUT
value|100000000
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

