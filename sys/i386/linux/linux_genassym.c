begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $FreeBSD$ */
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
file|<i386/linux/linux.h>
end_include

begin_expr_stmt
name|ASSYM
argument_list|(
name|LINUX_SIGF_HANDLER
argument_list|,
name|offsetof
argument_list|(
expr|struct
name|l_sigframe
argument_list|,
name|sf_handler
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|ASSYM
argument_list|(
name|LINUX_SIGF_SC
argument_list|,
name|offsetof
argument_list|(
expr|struct
name|l_sigframe
argument_list|,
name|sf_sc
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|ASSYM
argument_list|(
name|LINUX_SC_GS
argument_list|,
name|offsetof
argument_list|(
expr|struct
name|l_sigcontext
argument_list|,
name|sc_gs
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|ASSYM
argument_list|(
name|LINUX_SC_EFLAGS
argument_list|,
name|offsetof
argument_list|(
expr|struct
name|l_sigcontext
argument_list|,
name|sc_eflags
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|ASSYM
argument_list|(
name|LINUX_RT_SIGF_HANDLER
argument_list|,
name|offsetof
argument_list|(
expr|struct
name|l_rt_sigframe
argument_list|,
name|sf_handler
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|ASSYM
argument_list|(
name|LINUX_RT_SIGF_UC
argument_list|,
name|offsetof
argument_list|(
expr|struct
name|l_rt_sigframe
argument_list|,
name|sf_sc
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

end_unit

