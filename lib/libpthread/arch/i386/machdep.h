begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* ==== machdep.h ============================================================  * Copyright (c) 1993 Chris Provenzano, proven@athena.mit.edu  *  */
end_comment

begin_include
include|#
directive|include
file|<pthread/copyright.h>
end_include

begin_comment
comment|/*  * The first machine dependent functions are the SEMAPHORES  * needing the test and set instruction.  */
end_comment

begin_define
define|#
directive|define
name|SEMAPHORE_CLEAR
value|0
end_define

begin_define
define|#
directive|define
name|SEMAPHORE_SET
value|1
end_define

begin_define
define|#
directive|define
name|SEMAPHORE_TEST_AND_SET
parameter_list|(
name|lock
parameter_list|)
define|\
value|({										\ volatile long temp = SEMAPHORE_SET;     \ 										\ __asm__("xchgl %0,(%2)"                 \         :"=r" (temp)                    \         :"0" (temp),"r" (lock));        \ temp;                                   \ })
end_define

begin_define
define|#
directive|define
name|SEMAPHORE_RESET
parameter_list|(
name|lock
parameter_list|)
value|*lock = SEMAPHORE_CLEAR
end_define

begin_comment
comment|/*  * Minimum stack size  */
end_comment

begin_define
define|#
directive|define
name|PTHREAD_STACK_MIN
value|1024
end_define

end_unit

