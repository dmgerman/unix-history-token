begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* dlutils.c - handy functions and definitions for dl_*.xs files  *  * Currently this file is simply #included into dl_*.xs/.c files.  * It should really be split into a dlutils.h and dlutils.c  *  */
end_comment

begin_comment
comment|/* pointer to allocated memory for last error message */
end_comment

begin_decl_stmt
specifier|static
name|char
modifier|*
name|LastError
init|=
operator|(
name|char
operator|*
operator|)
name|NULL
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* flag for immediate rather than lazy linking (spots unresolved symbol) */
end_comment

begin_decl_stmt
specifier|static
name|int
name|dl_nonlazy
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|DL_LOADONCEONLY
end_ifdef

begin_decl_stmt
specifier|static
name|HV
modifier|*
name|dl_loaded_files
init|=
name|Nullhv
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* only needed on a few systems */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|DEBUGGING
end_ifdef

begin_decl_stmt
specifier|static
name|int
name|dl_debug
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* value copied from $DynaLoader::dl_error */
end_comment

begin_define
define|#
directive|define
name|DLDEBUG
parameter_list|(
name|level
parameter_list|,
name|code
parameter_list|)
value|if (dl_debug>=level) { code; }
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|DLDEBUG
parameter_list|(
name|level
parameter_list|,
name|code
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_function
specifier|static
name|void
name|dl_generic_private_init
parameter_list|(
name|CPERLarg
parameter_list|)
comment|/* called by dl_*.xs dl_private_init() */
block|{
name|char
modifier|*
name|perl_dl_nonlazy
decl_stmt|;
ifdef|#
directive|ifdef
name|DEBUGGING
name|dl_debug
operator|=
name|SvIV
argument_list|(
name|perl_get_sv
argument_list|(
literal|"DynaLoader::dl_debug"
argument_list|,
literal|0x04
argument_list|)
argument_list|)
expr_stmt|;
endif|#
directive|endif
if|if
condition|(
operator|(
name|perl_dl_nonlazy
operator|=
name|getenv
argument_list|(
literal|"PERL_DL_NONLAZY"
argument_list|)
operator|)
operator|!=
name|NULL
condition|)
name|dl_nonlazy
operator|=
name|atoi
argument_list|(
name|perl_dl_nonlazy
argument_list|)
expr_stmt|;
if|if
condition|(
name|dl_nonlazy
condition|)
name|DLDEBUG
argument_list|(
literal|1
argument_list|,
name|PerlIO_printf
argument_list|(
name|PerlIO_stderr
argument_list|()
argument_list|,
literal|"DynaLoader bind mode is 'non-lazy'\n"
argument_list|)
argument_list|)
expr_stmt|;
ifdef|#
directive|ifdef
name|DL_LOADONCEONLY
if|if
condition|(
operator|!
name|dl_loaded_files
condition|)
name|dl_loaded_files
operator|=
name|newHV
argument_list|()
expr_stmt|;
comment|/* provide cache for dl_*.xs if needed */
endif|#
directive|endif
block|}
end_function

begin_comment
comment|/* SaveError() takes printf style args and saves the result in LastError */
end_comment

begin_function
specifier|static
name|void
name|SaveError
parameter_list|(
name|CPERLarg_
name|char
modifier|*
name|pat
parameter_list|,
modifier|...
parameter_list|)
block|{
name|va_list
name|args
decl_stmt|;
name|char
modifier|*
name|message
decl_stmt|;
name|int
name|len
decl_stmt|;
comment|/* This code is based on croak/warn, see mess() in util.c */
name|va_start
argument_list|(
name|args
argument_list|,
name|pat
argument_list|)
expr_stmt|;
name|message
operator|=
name|mess
argument_list|(
name|pat
argument_list|,
operator|&
name|args
argument_list|)
expr_stmt|;
name|va_end
argument_list|(
name|args
argument_list|)
expr_stmt|;
name|len
operator|=
name|strlen
argument_list|(
name|message
argument_list|)
operator|+
literal|1
expr_stmt|;
comment|/* include terminating null char */
comment|/* Allocate some memory for the error message */
if|if
condition|(
name|LastError
condition|)
name|LastError
operator|=
operator|(
name|char
operator|*
operator|)
name|saferealloc
argument_list|(
name|LastError
argument_list|,
name|len
argument_list|)
expr_stmt|;
else|else
name|LastError
operator|=
operator|(
name|char
operator|*
operator|)
name|safemalloc
argument_list|(
name|len
argument_list|)
expr_stmt|;
comment|/* Copy message into LastError (including terminating null char)	*/
name|strncpy
argument_list|(
name|LastError
argument_list|,
name|message
argument_list|,
name|len
argument_list|)
expr_stmt|;
name|DLDEBUG
argument_list|(
literal|2
argument_list|,
name|PerlIO_printf
argument_list|(
name|PerlIO_stderr
argument_list|()
argument_list|,
literal|"DynaLoader: stored error msg '%s'\n"
argument_list|,
name|LastError
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

