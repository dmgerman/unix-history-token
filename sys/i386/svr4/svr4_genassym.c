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

begin_struct_decl
struct_decl|struct
name|proc
struct_decl|;
end_struct_decl

begin_include
include|#
directive|include
file|<svr4/svr4.h>
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
literal|"#define\tSVR4_SIGF_HANDLER %u\n"
argument_list|,
name|OS
argument_list|(
name|svr4_sigframe
argument_list|,
name|sf_handler
argument_list|)
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define\tSVR4_SIGF_UC %u\n"
argument_list|,
name|OS
argument_list|(
name|svr4_sigframe
argument_list|,
name|sf_uc
argument_list|)
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"#define\tSVR4_UC_FS %u\n"
argument_list|,
name|OS
argument_list|(
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
name|printf
argument_list|(
literal|"#define\tSVR4_UC_GS %u\n"
argument_list|,
name|OS
argument_list|(
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
name|printf
argument_list|(
literal|"#define\tSVR4_UC_EFLAGS %u\n"
argument_list|,
name|OS
argument_list|(
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
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_function

end_unit

