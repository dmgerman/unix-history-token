begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $Id: linux_genassym.c,v 1.6 1997/08/25 23:36:23 bde Exp $ */
end_comment

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<i386/linux/linux.h>
end_include

begin_decl_stmt
name|int
decl|main
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|printf
name|__P
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|,
operator|...
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_function
name|int
name|main
parameter_list|()
block|{
name|struct
name|linux_sigframe
modifier|*
name|linux_sigf
init|=
operator|(
expr|struct
name|linux_sigframe
operator|*
operator|)
literal|0
decl_stmt|;
name|struct
name|linux_sigcontext
modifier|*
name|linux_sc
init|=
operator|(
expr|struct
name|linux_sigcontext
operator|*
operator|)
literal|0
decl_stmt|;
name|printf
argument_list|(
literal|"#define\tLINUX_SIGF_HANDLER %d\n"
argument_list|,
operator|&
name|linux_sigf
operator|->
name|sf_handler
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define\tLINUX_SIGF_SC %d\n"
argument_list|,
operator|&
name|linux_sigf
operator|->
name|sf_sc
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define\tLINUX_SC_FS %d\n"
argument_list|,
operator|&
name|linux_sc
operator|->
name|sc_fs
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define\tLINUX_SC_GS %d\n"
argument_list|,
operator|&
name|linux_sc
operator|->
name|sc_gs
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define\tLINUX_SC_EFLAGS %d\n"
argument_list|,
operator|&
name|linux_sc
operator|->
name|sc_eflags
argument_list|)
expr_stmt|;
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_function

end_unit

