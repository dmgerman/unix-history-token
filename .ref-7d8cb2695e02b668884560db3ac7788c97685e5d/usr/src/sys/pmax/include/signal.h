begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1992 Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Ralph Campbell.  *  * %sccs.include.redist.c%  *  *	@(#)signal.h	7.1 (Berkeley) %G%  */
end_comment

begin_comment
comment|/*  * Machine-dependent signal definitions  */
end_comment

begin_typedef
typedef|typedef
name|int
name|sig_atomic_t
typedef|;
end_typedef

begin_comment
comment|/*  * Information pushed on stack when a signal is delivered.  * This is used by the kernel to restore state following  * execution of the signal handler.  It is also made available  * to the handler to allow it to restore state properly if  * a non-standard exit is performed.  */
end_comment

begin_struct
struct|struct
name|sigcontext
block|{
name|int
name|sc_onstack
decl_stmt|;
comment|/* sigstack state to restore */
name|int
name|sc_mask
decl_stmt|;
comment|/* signal mask to restore */
name|int
name|sc_pc
decl_stmt|;
comment|/* pc at time of signal */
name|int
name|sc_regs
index|[
literal|34
index|]
decl_stmt|;
comment|/* processor regs 0 to 31, mullo, mullhi */
name|int
name|sc_fpused
decl_stmt|;
comment|/* fp has been used */
name|int
name|sc_fpregs
index|[
literal|33
index|]
decl_stmt|;
comment|/* fp regs 0 to 31 and csr */
name|int
name|sc_fpc_eir
decl_stmt|;
comment|/* floating point exception instruction reg */
block|}
struct|;
end_struct

end_unit

