begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* STARTUP PROCEDURE FOR UNIX FORTRAN PROGRAMS */
end_comment

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<signal.h>
end_include

begin_decl_stmt
name|int
name|xargc
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
modifier|*
name|xargv
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|_sigfdie
argument_list|()
decl_stmt|,
name|_sigidie
argument_list|()
decl_stmt|,
name|_sigqdie
argument_list|()
decl_stmt|,
name|_sigindie
argument_list|()
decl_stmt|,
name|_sigtdie
argument_list|()
decl_stmt|;
end_decl_stmt

begin_function
name|main
parameter_list|(
name|argc
parameter_list|,
name|argv
parameter_list|,
name|arge
parameter_list|)
name|int
name|argc
decl_stmt|;
name|char
modifier|*
modifier|*
name|argv
decl_stmt|;
name|char
modifier|*
modifier|*
name|arge
decl_stmt|;
block|{
name|xargc
operator|=
name|argc
expr_stmt|;
name|xargv
operator|=
name|argv
expr_stmt|;
name|signal
argument_list|(
name|SIGFPE
argument_list|,
name|_sigfdie
argument_list|)
expr_stmt|;
comment|/* ignore underflow, enable overflow */
name|signal
argument_list|(
name|SIGIOT
argument_list|,
name|_sigidie
argument_list|)
expr_stmt|;
if|if
condition|(
operator|(
name|int
operator|)
name|signal
argument_list|(
name|SIGQUIT
argument_list|,
name|_sigqdie
argument_list|)
operator|&
literal|01
condition|)
name|signal
argument_list|(
name|SIGQUIT
argument_list|,
name|SIG_IGN
argument_list|)
expr_stmt|;
if|if
condition|(
operator|(
name|int
operator|)
name|signal
argument_list|(
name|SIGINT
argument_list|,
name|_sigindie
argument_list|)
operator|&
literal|01
condition|)
name|signal
argument_list|(
name|SIGINT
argument_list|,
name|SIG_IGN
argument_list|)
expr_stmt|;
name|signal
argument_list|(
name|SIGTERM
argument_list|,
name|_sigtdie
argument_list|)
expr_stmt|;
ifdef|#
directive|ifdef
name|pdp11
name|ldfps
argument_list|(
literal|01200
argument_list|)
expr_stmt|;
comment|/* detect overflow as an exception */
endif|#
directive|endif
name|f_init
argument_list|()
expr_stmt|;
name|MAIN__
argument_list|()
expr_stmt|;
name|f_exit
argument_list|()
expr_stmt|;
block|}
end_function

begin_ifdef
ifdef|#
directive|ifdef
name|vax
end_ifdef

begin_decl_stmt
specifier|static
name|char
modifier|*
name|fpenames
index|[]
init|=
block|{
literal|"unknown floating exception"
block|,
literal|"integer overflow"
block|,
literal|"integer divide by zero"
block|,
literal|"floating overflow"
block|,
literal|"floating/decimal divide by zero"
block|,
literal|"floating underflow"
block|,
literal|"decimal overflow"
block|,
literal|"subscript out of range"
block|,
literal|"floating overflow"
block|,
literal|"floating divide by zero"
block|,
literal|"floating underflow"
block|}
decl_stmt|;
end_decl_stmt

begin_macro
name|_sigfdie
argument_list|(
argument|sig
argument_list|,
argument|code
argument_list|)
end_macro

begin_decl_stmt
name|int
name|sig
decl_stmt|,
name|code
decl_stmt|;
end_decl_stmt

begin_block
block|{
if|if
condition|(
name|code
operator|<
literal|0
operator|||
name|code
operator|>=
sizeof|sizeof
name|fpenames
operator|/
sizeof|sizeof
name|fpenames
index|[
literal|0
index|]
condition|)
name|code
operator|=
literal|0
expr_stmt|;
name|_sigdie
argument_list|(
name|fpenames
index|[
name|code
index|]
argument_list|,
literal|1
argument_list|)
expr_stmt|;
block|}
end_block

begin_else
else|#
directive|else
end_else

begin_macro
name|_sigfdie
argument_list|()
end_macro

begin_block
block|{
name|_sigdie
argument_list|(
literal|"floating exception, 1); } #endif  _sigidie() { _sigdie("
argument|IOT Trap
literal|", 1); } _sigqdie() { _sigdie("
argument|Quit signal
literal|", 1); } _sigindie() { _sigdie("
argument|Interrupt
literal|", 0); } _sigtdie() { _sigdie("
argument|Killed
literal|", 0); }  _sigdie(s, kill) 	register char *s; 	int kill; {  	/* print error message, then clear buffers */ 	fflush(stderr); 	fprintf(stderr, "
argument|%s\n
literal|"
end_block

unit|, s); 	f_exit(); 	fflush(stderr); 	if (kill) { 		/* now get a core */ 		signal(SIGIOT, 0); 		abort(); 		/*NOTREACHED*/ 	} 	exit(1); }
end_unit

