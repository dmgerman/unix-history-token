begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1990 The Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * William Jolitz.  *  * %sccs.include.noredist.c%  *  *	@(#)reg.h	5.1 (Berkeley) %G%  */
end_comment

begin_comment
comment|/*  * Location of the users' stored  * registers within appropriate frame of 'trap' and 'syscall', relative to  * base of stack frame.  * Normal usage is u.u_ar0[XX] in kernel.  */
end_comment

begin_comment
comment|/* When referenced during a trap/exception, registers are at these offsets */
end_comment

begin_define
define|#
directive|define
name|tES
value|(0)
end_define

begin_define
define|#
directive|define
name|tDS
value|(1)
end_define

begin_define
define|#
directive|define
name|tEDI
value|(2)
end_define

begin_define
define|#
directive|define
name|tESI
value|(3)
end_define

begin_define
define|#
directive|define
name|tEBP
value|(4)
end_define

begin_define
define|#
directive|define
name|tEBX
value|(6)
end_define

begin_define
define|#
directive|define
name|tEDX
value|(7)
end_define

begin_define
define|#
directive|define
name|tECX
value|(8)
end_define

begin_define
define|#
directive|define
name|tEAX
value|(9)
end_define

begin_define
define|#
directive|define
name|tEIP
value|(12)
end_define

begin_define
define|#
directive|define
name|tCS
value|(13)
end_define

begin_define
define|#
directive|define
name|tEFLAGS
value|(14)
end_define

begin_define
define|#
directive|define
name|tESP
value|(15)
end_define

begin_define
define|#
directive|define
name|tSS
value|(16)
end_define

begin_comment
comment|/* During a system call, registers are at these offsets instead of above. */
end_comment

begin_define
define|#
directive|define
name|sEDI
value|(0)
end_define

begin_define
define|#
directive|define
name|sESI
value|(1)
end_define

begin_define
define|#
directive|define
name|sEBP
value|(2)
end_define

begin_define
define|#
directive|define
name|sEBX
value|(4)
end_define

begin_define
define|#
directive|define
name|sEDX
value|(5)
end_define

begin_define
define|#
directive|define
name|sECX
value|(6)
end_define

begin_define
define|#
directive|define
name|sEAX
value|(7)
end_define

begin_define
define|#
directive|define
name|sEFLAGS
value|(8)
end_define

begin_define
define|#
directive|define
name|sEIP
value|(9)
end_define

begin_define
define|#
directive|define
name|sCS
value|(10)
end_define

begin_define
define|#
directive|define
name|sESP
value|(11)
end_define

begin_define
define|#
directive|define
name|sSS
value|(12)
end_define

begin_comment
comment|/*  * Registers accessible to ptrace(2) syscall for debugger  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|IPCREG
end_ifdef

begin_define
define|#
directive|define
name|NIPCREG
value|14
end_define

begin_decl_stmt
name|int
name|ipcreg
index|[
name|NIPCREG
index|]
init|=
block|{
name|tES
block|,
name|tDS
block|,
name|tEDI
block|,
name|tESI
block|,
name|tEBP
block|,
name|tEBX
block|,
name|tEDX
block|,
name|tECX
block|,
name|tEAX
block|,
name|tEIP
block|,
name|tCS
block|,
name|tEFLAGS
block|,
name|tESP
block|,
name|tSS
block|}
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

