begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1984 The Regents of the University of California.  * All rights reserved.  *  * %sccs.include.redist.c%  *  *	@(#)ptrace.h	7.3 (Berkeley) %G%  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_PTRACE_H_
end_ifndef

begin_define
define|#
directive|define
name|_PTRACE_H_
end_define

begin_define
define|#
directive|define
name|PT_TRACE_ME
value|0
end_define

begin_comment
comment|/* child declares it's being traced */
end_comment

begin_define
define|#
directive|define
name|PT_READ_I
value|1
end_define

begin_comment
comment|/* read word in child's I space */
end_comment

begin_define
define|#
directive|define
name|PT_READ_D
value|2
end_define

begin_comment
comment|/* read word in child's D space */
end_comment

begin_define
define|#
directive|define
name|PT_READ_U
value|3
end_define

begin_comment
comment|/* read word in child's user structure */
end_comment

begin_define
define|#
directive|define
name|PT_WRITE_I
value|4
end_define

begin_comment
comment|/* write word in child's I space */
end_comment

begin_define
define|#
directive|define
name|PT_WRITE_D
value|5
end_define

begin_comment
comment|/* write word in child's D space */
end_comment

begin_define
define|#
directive|define
name|PT_WRITE_U
value|6
end_define

begin_comment
comment|/* write word in child's user structure */
end_comment

begin_define
define|#
directive|define
name|PT_CONTINUE
value|7
end_define

begin_comment
comment|/* continue the child */
end_comment

begin_define
define|#
directive|define
name|PT_KILL
value|8
end_define

begin_comment
comment|/* kill the child process */
end_comment

begin_define
define|#
directive|define
name|PT_STEP
value|9
end_define

begin_comment
comment|/* single step the child */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_PTRACE_H_ */
end_comment

end_unit

