begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$NetBSD: trap.h,v 1.1 2001/02/23 03:48:19 ichiro Exp $	*/
end_comment

begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_MACHINE_TRAP_H_
end_ifndef

begin_define
define|#
directive|define
name|_MACHINE_TRAP_H_
end_define

begin_define
define|#
directive|define
name|GDB_BREAKPOINT
value|0xe6000011
end_define

begin_define
define|#
directive|define
name|GDB5_BREAKPOINT
value|0xe7ffdefe
end_define

begin_define
define|#
directive|define
name|PTRACE_BREAKPOINT
value|0xe7fffff0
end_define

begin_define
define|#
directive|define
name|KERNEL_BREAKPOINT
value|0xe7ffffff
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _MACHINE_TRAP_H_ */
end_comment

end_unit

