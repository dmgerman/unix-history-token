begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Definitions of external routines and variables for tn3270  */
end_comment

begin_comment
comment|/*  * Pieces exported from the telnet susbsection.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
if|#
directive|if
name|defined
argument_list|(
name|unix
argument_list|)
name|HaveInput
decl_stmt|,
endif|#
directive|endif
comment|/* defined(unix) */
name|tout
decl_stmt|,
name|tin
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|transcom
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|netflush
argument_list|()
decl_stmt|,
name|quit
argument_list|()
decl_stmt|,
name|TtyChars
argument_list|()
decl_stmt|,
name|DataToTerminal
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|outputPurge
argument_list|()
decl_stmt|,
name|EmptyTerminal
argument_list|()
decl_stmt|,
name|StringToTerminal
argument_list|()
decl_stmt|,
name|_putchar
argument_list|()
decl_stmt|,
name|ExitPerror
argument_list|()
decl_stmt|,
name|setcommandmode
argument_list|()
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * Pieces exported from other random locations.  */
end_comment

begin_function_decl
specifier|extern
name|char
modifier|*
name|strsave
parameter_list|()
function_decl|;
end_function_decl

end_unit

