begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1988 University of Utah.  * Copyright (c) 1990 The Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * the Systems Programming Group of the University of Utah Computer  * Science Department.  *  * %sccs.include.redist.c%  *  * from: Utah $Hdr: mtpr.h 1.5 89/04/11$  *  *	@(#)mtpr.h	7.1 (Berkeley) %G%  */
end_comment

begin_comment
comment|/*  * simulated software interrupt register  */
end_comment

begin_decl_stmt
specifier|extern
name|unsigned
name|char
name|ssir
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|SIR_NET
value|0x1
end_define

begin_define
define|#
directive|define
name|SIR_CLOCK
value|0x2
end_define

begin_define
define|#
directive|define
name|siroff
parameter_list|(
name|x
parameter_list|)
value|ssir&= ~(x)
end_define

begin_define
define|#
directive|define
name|setsoftnet
parameter_list|()
value|ssir |= SIR_NET
end_define

begin_define
define|#
directive|define
name|setsoftclock
parameter_list|()
value|ssir |= SIR_CLOCK
end_define

end_unit

