begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1990 The Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * William Jolitz.  *  * %sccs.include.noredist.c%  *  *	@(#)frame.h	5.1 (Berkeley) %G%  */
end_comment

begin_comment
comment|/*  * System stack frames.  */
end_comment

begin_comment
comment|/*  * Exception/Trap Stack Frame  */
end_comment

begin_struct
struct|struct
name|trapframe
block|{
name|int
name|tf_es
decl_stmt|;
name|int
name|tf_ds
decl_stmt|;
name|int
name|tf_edi
decl_stmt|;
name|int
name|tf_esi
decl_stmt|;
name|int
name|tf_ebp
decl_stmt|;
name|int
name|tf_isp
decl_stmt|;
name|int
name|tf_ebx
decl_stmt|;
name|int
name|tf_edx
decl_stmt|;
name|int
name|tf_ecx
decl_stmt|;
name|int
name|tf_eax
decl_stmt|;
name|int
name|tf_trapno
decl_stmt|;
comment|/* below portion defined in 386 hardware */
name|int
name|tf_err
decl_stmt|;
name|int
name|tf_eip
decl_stmt|;
name|int
name|tf_cs
decl_stmt|;
name|int
name|tf_eflags
decl_stmt|;
comment|/* below only when transitting rings (e.g. user to kernel) */
name|int
name|tf_esp
decl_stmt|;
name|int
name|tf_ss
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* Interrupt stack frame */
end_comment

begin_struct
struct|struct
name|intrframe
block|{
name|int
name|if_vec
decl_stmt|;
name|int
name|if_ppl
decl_stmt|;
name|int
name|if_es
decl_stmt|;
name|int
name|if_ds
decl_stmt|;
name|int
name|if_edi
decl_stmt|;
name|int
name|if_esi
decl_stmt|;
name|int
name|if_ebp
decl_stmt|;
name|int
label|:
literal|32
expr_stmt|;
name|int
name|if_ebx
decl_stmt|;
name|int
name|if_edx
decl_stmt|;
name|int
name|if_ecx
decl_stmt|;
name|int
name|if_eax
decl_stmt|;
name|int
label|:
literal|32
expr_stmt|;
comment|/* for compat with trap frame - trapno */
name|int
label|:
literal|32
expr_stmt|;
comment|/* for compat with trap frame - err */
comment|/* below portion defined in 386 hardware */
name|int
name|if_eip
decl_stmt|;
name|int
name|if_cs
decl_stmt|;
name|int
name|if_eflags
decl_stmt|;
comment|/* below only when transitting rings (e.g. user to kernel) */
name|int
name|if_esp
decl_stmt|;
name|int
name|if_ss
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Call Gate/System Call Stack Frame  */
end_comment

begin_struct
struct|struct
name|syscframe
block|{
name|int
name|sf_edi
decl_stmt|;
name|int
name|sf_esi
decl_stmt|;
name|int
name|sf_ebp
decl_stmt|;
name|int
label|:
literal|32
expr_stmt|;
comment|/* redundant save of isp */
name|int
name|sf_ebx
decl_stmt|;
name|int
name|sf_edx
decl_stmt|;
name|int
name|sf_ecx
decl_stmt|;
name|int
name|sf_eax
decl_stmt|;
name|int
name|sf_eflags
decl_stmt|;
comment|/* below portion defined in 386 hardware */
comment|/*	int	sf_args[N]; 	/* if call gate copy args enabled!*/
name|int
name|sf_eip
decl_stmt|;
name|int
name|sf_cs
decl_stmt|;
comment|/* below only when transitting rings (e.g. user to kernel) */
name|int
name|sf_esp
decl_stmt|;
name|int
name|sf_ss
decl_stmt|;
block|}
struct|;
end_struct

end_unit

