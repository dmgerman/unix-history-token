begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_comment
comment|/* Derived from:  Id: linux_genassym.c,v 1.8 1998/07/29 15:50:41 bde Exp */
end_comment

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<sys/assym.h>
end_include

begin_include
include|#
directive|include
file|<svr4/svr4_signal.h>
end_include

begin_include
include|#
directive|include
file|<svr4/svr4_ucontext.h>
end_include

begin_comment
comment|/* XXX: This bit sucks rocks, but gets rid of compiler errors.  Maybe I should  * fix the include files instead... */
end_comment

begin_define
define|#
directive|define
name|SVR4_MACHDEP_JUST_REGS
end_define

begin_include
include|#
directive|include
file|<i386/svr4/svr4_machdep.h>
end_include

begin_expr_stmt
name|ASSYM
argument_list|(
name|SVR4_SIGF_HANDLER
argument_list|,
name|offsetof
argument_list|(
expr|struct
name|svr4_sigframe
argument_list|,
name|sf_handler
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|ASSYM
argument_list|(
name|SVR4_SIGF_UC
argument_list|,
name|offsetof
argument_list|(
expr|struct
name|svr4_sigframe
argument_list|,
name|sf_uc
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|ASSYM
argument_list|(
name|SVR4_UC_FS
argument_list|,
name|offsetof
argument_list|(
expr|struct
name|svr4_ucontext
argument_list|,
name|uc_mcontext
operator|.
name|greg
index|[
name|SVR4_X86_FS
index|]
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|ASSYM
argument_list|(
name|SVR4_UC_GS
argument_list|,
name|offsetof
argument_list|(
expr|struct
name|svr4_ucontext
argument_list|,
name|uc_mcontext
operator|.
name|greg
index|[
name|SVR4_X86_GS
index|]
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|ASSYM
argument_list|(
name|SVR4_UC_EFLAGS
argument_list|,
name|offsetof
argument_list|(
expr|struct
name|svr4_ucontext
argument_list|,
name|uc_mcontext
operator|.
name|greg
index|[
name|SVR4_X86_EFL
index|]
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

end_unit

