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
file|<i386/linux/linux.h>
end_include

begin_define
define|#
directive|define
name|offsetof
parameter_list|(
name|type
parameter_list|,
name|member
parameter_list|)
value|((size_t)(&((type *)0)->member))
end_define

begin_define
define|#
directive|define
name|OS
parameter_list|(
name|s
parameter_list|,
name|m
parameter_list|)
value|((u_int)offsetof(struct s, m))
end_define

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
name|printf
argument_list|(
literal|"#define\tLINUX_SIGF_HANDLER %u\n"
argument_list|,
name|OS
argument_list|(
name|linux_sigframe
argument_list|,
name|sf_handler
argument_list|)
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define\tLINUX_SIGF_SC %u\n"
argument_list|,
name|OS
argument_list|(
name|linux_sigframe
argument_list|,
name|sf_sc
argument_list|)
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define\tLINUX_SC_GS %u\n"
argument_list|,
name|OS
argument_list|(
name|linux_sigcontext
argument_list|,
name|sc_gs
argument_list|)
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define\tLINUX_SC_EFLAGS %u\n"
argument_list|,
name|OS
argument_list|(
name|linux_sigcontext
argument_list|,
name|sc_eflags
argument_list|)
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

