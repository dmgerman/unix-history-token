begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*    perl.c  *  *    Copyright (c) 1987-1999 Larry Wall  *  *    You may distribute under the terms of either the GNU General Public  *    License or the Artistic License, as specified in the README file.  *  */
end_comment

begin_comment
comment|/*  * "A ship then new they built for him/of mithril and of elven glass" --Bilbo  */
end_comment

begin_include
include|#
directive|include
file|"EXTERN.h"
end_include

begin_include
include|#
directive|include
file|"perl.h"
end_include

begin_include
include|#
directive|include
file|"patchlevel.h"
end_include

begin_comment
comment|/* XXX If this causes problems, set i_unistd=undef in the hint file.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|I_UNISTD
end_ifdef

begin_include
include|#
directive|include
file|<unistd.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|STANDARD_C
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|HAS_GETENV_PROTOTYPE
argument_list|)
end_if

begin_decl_stmt
name|char
modifier|*
name|getenv
name|_
argument_list|(
operator|(
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Usually in<stdlib.h> */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|I_FCNTL
end_ifdef

begin_include
include|#
directive|include
file|<fcntl.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|I_SYS_FILE
end_ifdef

begin_include
include|#
directive|include
file|<sys/file.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|IAMSUID
end_ifdef

begin_ifndef
ifndef|#
directive|ifndef
name|DOSUID
end_ifndef

begin_define
define|#
directive|define
name|DOSUID
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|SETUID_SCRIPTS_ARE_SECURE_NOW
end_ifdef

begin_ifdef
ifdef|#
directive|ifdef
name|DOSUID
end_ifdef

begin_undef
undef|#
directive|undef
name|DOSUID
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|PERL_OBJECT
end_ifdef

begin_decl_stmt
specifier|static
name|I32
name|read_e_script
name|_
argument_list|(
operator|(
name|CPerlObj
operator|*
name|pPerl
operator|,
name|int
name|idx
operator|,
name|SV
operator|*
name|buf_sv
operator|,
name|int
name|maxlen
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_decl_stmt
specifier|static
name|void
name|find_beginning
name|_
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|void
name|forbid_setid
name|_
argument_list|(
operator|(
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|void
name|incpush
name|_
argument_list|(
operator|(
name|char
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|void
name|init_interp
name|_
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|void
name|init_ids
name|_
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|void
name|init_debugger
name|_
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|void
name|init_lexer
name|_
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|void
name|init_main_stash
name|_
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|USE_THREADS
end_ifdef

begin_decl_stmt
specifier|static
name|struct
name|perl_thread
modifier|*
name|init_main_thread
name|_
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* USE_THREADS */
end_comment

begin_decl_stmt
specifier|static
name|void
name|init_perllib
name|_
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|void
name|init_postdump_symbols
name|_
argument_list|(
operator|(
name|int
operator|,
name|char
operator|*
operator|*
operator|,
name|char
operator|*
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|void
name|init_predump_symbols
name|_
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|void
name|my_exit_jump
name|_
argument_list|(
operator|(
name|void
operator|)
argument_list|)
name|__attribute__
argument_list|(
operator|(
name|noreturn
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|void
name|nuke_stacks
name|_
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|void
name|open_script
name|_
argument_list|(
operator|(
name|char
operator|*
operator|,
name|bool
operator|,
name|SV
operator|*
operator|,
name|int
operator|*
name|fd
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|void
name|usage
name|_
argument_list|(
operator|(
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|IAMSUID
end_ifdef

begin_decl_stmt
specifier|static
name|int
name|fd_on_nosuid_fs
name|_
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
specifier|static
name|void
name|validate_suid
name|_
argument_list|(
operator|(
name|char
operator|*
operator|,
name|char
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|I32
name|read_e_script
name|_
argument_list|(
operator|(
name|int
name|idx
operator|,
name|SV
operator|*
name|buf_sv
operator|,
name|int
name|maxlen
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|PERL_OBJECT
end_ifdef

begin_function
name|CPerlObj
modifier|*
name|perl_alloc
parameter_list|(
name|IPerlMem
modifier|*
name|ipM
parameter_list|,
name|IPerlEnv
modifier|*
name|ipE
parameter_list|,
name|IPerlStdIO
modifier|*
name|ipStd
parameter_list|,
name|IPerlLIO
modifier|*
name|ipLIO
parameter_list|,
name|IPerlDir
modifier|*
name|ipD
parameter_list|,
name|IPerlSock
modifier|*
name|ipS
parameter_list|,
name|IPerlProc
modifier|*
name|ipP
parameter_list|)
block|{
name|CPerlObj
modifier|*
name|pPerl
init|=
name|new
argument_list|(
argument|ipM
argument_list|)
name|CPerlObj
argument_list|(
name|ipM
argument_list|,
name|ipE
argument_list|,
name|ipStd
argument_list|,
name|ipLIO
argument_list|,
name|ipD
argument_list|,
name|ipS
argument_list|,
name|ipP
argument_list|)
decl_stmt|;
if|if
condition|(
name|pPerl
operator|!=
name|NULL
condition|)
name|pPerl
operator|->
name|Init
argument_list|()
expr_stmt|;
return|return
name|pPerl
return|;
block|}
end_function

begin_else
else|#
directive|else
end_else

begin_function
name|PerlInterpreter
modifier|*
name|perl_alloc
parameter_list|(
name|void
parameter_list|)
block|{
name|PerlInterpreter
modifier|*
name|sv_interp
decl_stmt|;
name|PL_curinterp
operator|=
literal|0
expr_stmt|;
name|New
argument_list|(
literal|53
argument_list|,
name|sv_interp
argument_list|,
literal|1
argument_list|,
name|PerlInterpreter
argument_list|)
expr_stmt|;
return|return
name|sv_interp
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* PERL_OBJECT */
end_comment

begin_expr_stmt
name|void
ifdef|#
directive|ifdef
name|PERL_OBJECT
name|CPerlObj
operator|::
name|perl_construct
argument_list|(
argument|void
argument_list|)
else|#
directive|else
name|perl_construct
argument_list|(
argument|register PerlInterpreter *sv_interp
argument_list|)
endif|#
directive|endif
block|{
ifdef|#
directive|ifdef
name|USE_THREADS
name|int
name|i
block|;
ifndef|#
directive|ifndef
name|FAKE_THREADS
block|struct
name|perl_thread
operator|*
name|thr
block|;
endif|#
directive|endif
comment|/* FAKE_THREADS */
endif|#
directive|endif
comment|/* USE_THREADS */
ifndef|#
directive|ifndef
name|PERL_OBJECT
if|if
condition|(
operator|!
operator|(
name|PL_curinterp
operator|=
name|sv_interp
operator|)
condition|)
return|return;
endif|#
directive|endif
ifdef|#
directive|ifdef
name|MULTIPLICITY
operator|++
name|PL_ninterps
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|Zero
argument_list|(
name|sv_interp
argument_list|,
literal|1
argument_list|,
name|PerlInterpreter
argument_list|)
expr_stmt|;
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Init the real globals (and main thread)? */
end_comment

begin_if
if|if
condition|(
operator|!
name|PL_linestr
condition|)
block|{
ifdef|#
directive|ifdef
name|USE_THREADS
name|INIT_THREADS
expr_stmt|;
ifdef|#
directive|ifdef
name|ALLOC_THREAD_KEY
name|ALLOC_THREAD_KEY
expr_stmt|;
else|#
directive|else
if|if
condition|(
name|pthread_key_create
argument_list|(
operator|&
name|PL_thr_key
argument_list|,
literal|0
argument_list|)
condition|)
name|croak
argument_list|(
literal|"panic: pthread_key_create"
argument_list|)
expr_stmt|;
endif|#
directive|endif
name|MUTEX_INIT
argument_list|(
operator|&
name|PL_sv_mutex
argument_list|)
expr_stmt|;
name|MUTEX_INIT
argument_list|(
operator|&
name|PL_cred_mutex
argument_list|)
expr_stmt|;
comment|/* 	 * Safe to use basic SV functions from now on (though 	 * not things like mortals or tainting yet). 	 */
name|MUTEX_INIT
argument_list|(
operator|&
name|PL_eval_mutex
argument_list|)
expr_stmt|;
name|COND_INIT
argument_list|(
operator|&
name|PL_eval_cond
argument_list|)
expr_stmt|;
name|MUTEX_INIT
argument_list|(
operator|&
name|PL_threads_mutex
argument_list|)
expr_stmt|;
name|COND_INIT
argument_list|(
operator|&
name|PL_nthreads_cond
argument_list|)
expr_stmt|;
ifdef|#
directive|ifdef
name|EMULATE_ATOMIC_REFCOUNTS
name|MUTEX_INIT
argument_list|(
operator|&
name|PL_svref_mutex
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* EMULATE_ATOMIC_REFCOUNTS */
name|thr
operator|=
name|init_main_thread
argument_list|()
expr_stmt|;
endif|#
directive|endif
comment|/* USE_THREADS */
name|PL_linestr
operator|=
name|NEWSV
argument_list|(
literal|65
argument_list|,
literal|79
argument_list|)
expr_stmt|;
name|sv_upgrade
argument_list|(
name|PL_linestr
argument_list|,
name|SVt_PVIV
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|SvREADONLY
argument_list|(
operator|&
name|PL_sv_undef
argument_list|)
condition|)
block|{
comment|/* set read-only and try to insure than we wont see REFCNT==0 	       very often */
name|SvREADONLY_on
argument_list|(
operator|&
name|PL_sv_undef
argument_list|)
expr_stmt|;
name|SvREFCNT
argument_list|(
operator|&
name|PL_sv_undef
argument_list|)
operator|=
operator|(
operator|~
operator|(
name|U32
operator|)
literal|0
operator|)
operator|/
literal|2
expr_stmt|;
name|sv_setpv
argument_list|(
operator|&
name|PL_sv_no
argument_list|,
name|PL_No
argument_list|)
expr_stmt|;
name|SvNV
argument_list|(
operator|&
name|PL_sv_no
argument_list|)
expr_stmt|;
name|SvREADONLY_on
argument_list|(
operator|&
name|PL_sv_no
argument_list|)
expr_stmt|;
name|SvREFCNT
argument_list|(
operator|&
name|PL_sv_no
argument_list|)
operator|=
operator|(
operator|~
operator|(
name|U32
operator|)
literal|0
operator|)
operator|/
literal|2
expr_stmt|;
name|sv_setpv
argument_list|(
operator|&
name|PL_sv_yes
argument_list|,
name|PL_Yes
argument_list|)
expr_stmt|;
name|SvNV
argument_list|(
operator|&
name|PL_sv_yes
argument_list|)
expr_stmt|;
name|SvREADONLY_on
argument_list|(
operator|&
name|PL_sv_yes
argument_list|)
expr_stmt|;
name|SvREFCNT
argument_list|(
operator|&
name|PL_sv_yes
argument_list|)
operator|=
operator|(
operator|~
operator|(
name|U32
operator|)
literal|0
operator|)
operator|/
literal|2
expr_stmt|;
block|}
ifdef|#
directive|ifdef
name|PERL_OBJECT
comment|/* TODO: */
comment|/* PL_sighandlerp = sighandler; */
else|#
directive|else
name|PL_sighandlerp
operator|=
name|sighandler
expr_stmt|;
endif|#
directive|endif
name|PL_pidstatus
operator|=
name|newHV
argument_list|()
expr_stmt|;
ifdef|#
directive|ifdef
name|MSDOS
comment|/* 	 * There is no way we can refer to them from Perl so close them to save 	 * space.  The other alternative would be to provide STDAUX and STDPRN 	 * filehandles. 	 */
operator|(
name|void
operator|)
name|fclose
argument_list|(
name|stdaux
argument_list|)
expr_stmt|;
operator|(
name|void
operator|)
name|fclose
argument_list|(
name|stdprn
argument_list|)
expr_stmt|;
endif|#
directive|endif
block|}
end_if

begin_expr_stmt
name|PL_nrs
operator|=
name|newSVpv
argument_list|(
literal|"\n"
argument_list|,
literal|1
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|PL_rs
operator|=
name|SvREFCNT_inc
argument_list|(
name|PL_nrs
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|init_stacks
argument_list|(
name|ARGS
argument_list|)
expr_stmt|;
end_expr_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|MULTIPLICITY
end_ifdef

begin_expr_stmt
name|init_interp
argument_list|()
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|PL_perl_destruct_level
operator|=
literal|1
expr_stmt|;
end_expr_stmt

begin_else
else|#
directive|else
end_else

begin_if
if|if
condition|(
name|PL_perl_destruct_level
operator|>
literal|0
condition|)
name|init_interp
argument_list|()
expr_stmt|;
end_if

begin_endif
endif|#
directive|endif
end_endif

begin_expr_stmt
name|init_ids
argument_list|()
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|PL_lex_state
operator|=
name|LEX_NOTPARSING
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|PL_start_env
operator|.
name|je_prev
operator|=
name|NULL
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|PL_start_env
operator|.
name|je_ret
operator|=
operator|-
literal|1
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|PL_start_env
operator|.
name|je_mustcatch
operator|=
name|TRUE
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|PL_top_env
operator|=
operator|&
name|PL_start_env
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|STATUS_ALL_SUCCESS
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|SET_NUMERIC_STANDARD
argument_list|()
expr_stmt|;
end_expr_stmt

begin_if
if|#
directive|if
name|defined
argument_list|(
name|SUBVERSION
argument_list|)
operator|&&
name|SUBVERSION
operator|>
literal|0
end_if

begin_expr_stmt
name|sprintf
argument_list|(
name|PL_patchlevel
argument_list|,
literal|"%7.5f"
argument_list|,
operator|(
name|double
operator|)
literal|5
operator|+
operator|(
operator|(
name|double
operator|)
name|PATCHLEVEL
operator|/
operator|(
name|double
operator|)
literal|1000
operator|)
operator|+
operator|(
operator|(
name|double
operator|)
name|SUBVERSION
operator|/
operator|(
name|double
operator|)
literal|100000
operator|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_else
else|#
directive|else
end_else

begin_expr_stmt
name|sprintf
argument_list|(
name|PL_patchlevel
argument_list|,
literal|"%5.3f"
argument_list|,
operator|(
name|double
operator|)
literal|5
operator|+
operator|(
operator|(
name|double
operator|)
name|PATCHLEVEL
operator|/
operator|(
name|double
operator|)
literal|1000
operator|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|LOCAL_PATCH_COUNT
argument_list|)
end_if

begin_expr_stmt
name|PL_localpatches
operator|=
name|local_patches
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* For possible -v */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_expr_stmt
name|PerlIO_init
argument_list|()
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* Hook to IO system */
end_comment

begin_expr_stmt
name|PL_fdpid
operator|=
name|newAV
argument_list|()
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* for remembering popen pids by fd */
end_comment

begin_expr_stmt
name|PL_modglobal
operator|=
name|newHV
argument_list|()
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* pointers to per-interpreter module globals */
end_comment

begin_macro
name|DEBUG
argument_list|(
argument|{ 	New(
literal|51
argument|,PL_debname,
literal|128
argument|,char); 	New(
literal|52
argument|,PL_debdelim,
literal|128
argument|,char);     }
argument_list|)
end_macro

begin_expr_stmt
name|ENTER
expr_stmt|;
end_expr_stmt

begin_ifdef
unit|}  void
ifdef|#
directive|ifdef
name|PERL_OBJECT
end_ifdef

begin_expr_stmt
name|CPerlObj
operator|::
name|perl_destruct
argument_list|(
argument|void
argument_list|)
else|#
directive|else
name|perl_destruct
argument_list|(
argument|register PerlInterpreter *sv_interp
argument_list|)
endif|#
directive|endif
block|{
name|dTHR
block|;
name|int
name|destruct_level
block|;
comment|/* 0=none, 1=full, 2=full with checks */
name|I32
name|last_sv_count
block|;
name|HV
operator|*
name|hv
block|;
ifdef|#
directive|ifdef
name|USE_THREADS
name|Thread
name|t
block|;
endif|#
directive|endif
comment|/* USE_THREADS */
ifndef|#
directive|ifndef
name|PERL_OBJECT
if|if
condition|(
operator|!
operator|(
name|PL_curinterp
operator|=
name|sv_interp
operator|)
condition|)
return|return;
endif|#
directive|endif
ifdef|#
directive|ifdef
name|USE_THREADS
ifndef|#
directive|ifndef
name|FAKE_THREADS
comment|/* Pass 1 on any remaining threads: detach joinables, join zombies */
name|retry_cleanup
operator|:
name|MUTEX_LOCK
argument_list|(
operator|&
name|PL_threads_mutex
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|DEBUG_S
argument_list|(
name|PerlIO_printf
argument_list|(
name|PerlIO_stderr
argument_list|()
argument_list|,
literal|"perl_destruct: waiting for %d threads...\n"
argument_list|,
name|PL_nthreads
operator|-
literal|1
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_for
for|for
control|(
name|t
operator|=
name|thr
operator|->
name|next
init|;
name|t
operator|!=
name|thr
condition|;
name|t
operator|=
name|t
operator|->
name|next
control|)
block|{
name|MUTEX_LOCK
argument_list|(
operator|&
name|t
operator|->
name|mutex
argument_list|)
expr_stmt|;
switch|switch
condition|(
name|ThrSTATE
argument_list|(
name|t
argument_list|)
condition|)
block|{
name|AV
modifier|*
name|av
decl_stmt|;
case|case
name|THRf_ZOMBIE
case|:
name|DEBUG_S
argument_list|(
name|PerlIO_printf
argument_list|(
name|PerlIO_stderr
argument_list|()
argument_list|,
literal|"perl_destruct: joining zombie %p\n"
argument_list|,
name|t
argument_list|)
argument_list|)
expr_stmt|;
name|ThrSETSTATE
argument_list|(
name|t
argument_list|,
name|THRf_DEAD
argument_list|)
expr_stmt|;
name|MUTEX_UNLOCK
argument_list|(
operator|&
name|t
operator|->
name|mutex
argument_list|)
expr_stmt|;
name|PL_nthreads
operator|--
expr_stmt|;
comment|/* 	     * The SvREFCNT_dec below may take a long time (e.g. av 	     * may contain an object scalar whose destructor gets 	     * called) so we have to unlock threads_mutex and start 	     * all over again. 	     */
name|MUTEX_UNLOCK
argument_list|(
operator|&
name|PL_threads_mutex
argument_list|)
expr_stmt|;
name|JOIN
argument_list|(
name|t
argument_list|,
operator|&
name|av
argument_list|)
expr_stmt|;
name|SvREFCNT_dec
argument_list|(
operator|(
name|SV
operator|*
operator|)
name|av
argument_list|)
expr_stmt|;
name|DEBUG_S
argument_list|(
name|PerlIO_printf
argument_list|(
name|PerlIO_stderr
argument_list|()
argument_list|,
literal|"perl_destruct: joined zombie %p OK\n"
argument_list|,
name|t
argument_list|)
argument_list|)
expr_stmt|;
goto|goto
name|retry_cleanup
goto|;
case|case
name|THRf_R_JOINABLE
case|:
name|DEBUG_S
argument_list|(
name|PerlIO_printf
argument_list|(
name|PerlIO_stderr
argument_list|()
argument_list|,
literal|"perl_destruct: detaching thread %p\n"
argument_list|,
name|t
argument_list|)
argument_list|)
expr_stmt|;
name|ThrSETSTATE
argument_list|(
name|t
argument_list|,
name|THRf_R_DETACHED
argument_list|)
expr_stmt|;
comment|/*  	     * We unlock threads_mutex and t->mutex in the opposite order 	     * from which we locked them just so that DETACH won't 	     * deadlock if it panics. It's only a breach of good style 	     * not a bug since they are unlocks not locks. 	     */
name|MUTEX_UNLOCK
argument_list|(
operator|&
name|PL_threads_mutex
argument_list|)
expr_stmt|;
name|DETACH
argument_list|(
name|t
argument_list|)
expr_stmt|;
name|MUTEX_UNLOCK
argument_list|(
operator|&
name|t
operator|->
name|mutex
argument_list|)
expr_stmt|;
goto|goto
name|retry_cleanup
goto|;
default|default:
name|DEBUG_S
argument_list|(
name|PerlIO_printf
argument_list|(
name|PerlIO_stderr
argument_list|()
argument_list|,
literal|"perl_destruct: ignoring %p (state %u)\n"
argument_list|,
name|t
argument_list|,
name|ThrSTATE
argument_list|(
name|t
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|MUTEX_UNLOCK
argument_list|(
operator|&
name|t
operator|->
name|mutex
argument_list|)
expr_stmt|;
comment|/* fall through and out */
block|}
block|}
end_for

begin_comment
comment|/* We leave the above "Pass 1" loop with threads_mutex still locked */
end_comment

begin_comment
comment|/* Pass 2 on remaining threads: wait for the thread count to drop to one */
end_comment

begin_while
while|while
condition|(
name|PL_nthreads
operator|>
literal|1
condition|)
block|{
name|DEBUG_S
argument_list|(
name|PerlIO_printf
argument_list|(
name|PerlIO_stderr
argument_list|()
argument_list|,
literal|"perl_destruct: final wait for %d threads\n"
argument_list|,
name|PL_nthreads
operator|-
literal|1
argument_list|)
argument_list|)
expr_stmt|;
name|COND_WAIT
argument_list|(
operator|&
name|PL_nthreads_cond
argument_list|,
operator|&
name|PL_threads_mutex
argument_list|)
expr_stmt|;
block|}
end_while

begin_comment
comment|/* At this point, we're the last thread */
end_comment

begin_expr_stmt
name|MUTEX_UNLOCK
argument_list|(
operator|&
name|PL_threads_mutex
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|DEBUG_S
argument_list|(
name|PerlIO_printf
argument_list|(
name|PerlIO_stderr
argument_list|()
argument_list|,
literal|"perl_destruct: armageddon has arrived\n"
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|MUTEX_DESTROY
argument_list|(
operator|&
name|PL_threads_mutex
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|COND_DESTROY
argument_list|(
operator|&
name|PL_nthreads_cond
argument_list|)
expr_stmt|;
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !defined(FAKE_THREADS) */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* USE_THREADS */
end_comment

begin_expr_stmt
name|destruct_level
operator|=
name|PL_perl_destruct_level
expr_stmt|;
end_expr_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|DEBUGGING
end_ifdef

begin_block
block|{
name|char
modifier|*
name|s
decl_stmt|;
if|if
condition|(
name|s
operator|=
name|PerlEnv_getenv
argument_list|(
literal|"PERL_DESTRUCT_LEVEL"
argument_list|)
condition|)
block|{
name|int
name|i
init|=
name|atoi
argument_list|(
name|s
argument_list|)
decl_stmt|;
if|if
condition|(
name|destruct_level
operator|<
name|i
condition|)
name|destruct_level
operator|=
name|i
expr_stmt|;
block|}
block|}
end_block

begin_endif
endif|#
directive|endif
end_endif

begin_expr_stmt
name|LEAVE
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|FREETMPS
expr_stmt|;
end_expr_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|MULTIPLICITY
end_ifdef

begin_expr_stmt
operator|--
name|PL_ninterps
expr_stmt|;
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* We must account for everything.  */
end_comment

begin_comment
comment|/* Destroy the main CV and syntax tree */
end_comment

begin_if
if|if
condition|(
name|PL_main_root
condition|)
block|{
name|PL_curpad
operator|=
name|AvARRAY
argument_list|(
name|PL_comppad
argument_list|)
expr_stmt|;
name|op_free
argument_list|(
name|PL_main_root
argument_list|)
expr_stmt|;
name|PL_main_root
operator|=
name|Nullop
expr_stmt|;
block|}
end_if

begin_expr_stmt
name|PL_curcop
operator|=
operator|&
name|PL_compiling
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|PL_main_start
operator|=
name|Nullop
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|SvREFCNT_dec
argument_list|(
name|PL_main_cv
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|PL_main_cv
operator|=
name|Nullcv
expr_stmt|;
end_expr_stmt

begin_if
if|if
condition|(
name|PL_sv_objcount
condition|)
block|{
comment|/* 	 * Try to destruct global references.  We do this first so that the 	 * destructors and destructees still exist.  Some sv's might remain. 	 * Non-referenced objects are on their own. 	 */
name|PL_dirty
operator|=
name|TRUE
expr_stmt|;
name|sv_clean_objs
argument_list|()
expr_stmt|;
block|}
end_if

begin_comment
comment|/* unhook hooks which will soon be, or use, destroyed data */
end_comment

begin_expr_stmt
name|SvREFCNT_dec
argument_list|(
name|PL_warnhook
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|PL_warnhook
operator|=
name|Nullsv
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|SvREFCNT_dec
argument_list|(
name|PL_diehook
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|PL_diehook
operator|=
name|Nullsv
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|SvREFCNT_dec
argument_list|(
name|PL_parsehook
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|PL_parsehook
operator|=
name|Nullsv
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* call exit list functions */
end_comment

begin_while
while|while
condition|(
name|PL_exitlistlen
operator|--
operator|>
literal|0
condition|)
name|PL_exitlist
index|[
name|PL_exitlistlen
index|]
operator|.
name|fn
argument_list|(
argument|PERL_OBJECT_THIS_ PL_exitlist[PL_exitlistlen].ptr
argument_list|)
expr_stmt|;
end_while

begin_expr_stmt
name|Safefree
argument_list|(
name|PL_exitlist
argument_list|)
expr_stmt|;
end_expr_stmt

begin_if
if|if
condition|(
name|destruct_level
operator|==
literal|0
condition|)
block|{
name|DEBUG_P
argument_list|(
name|debprofdump
argument_list|()
argument_list|)
expr_stmt|;
comment|/* The exit() function will do everything that needs doing. */
return|return;
block|}
end_if

begin_comment
comment|/* loosen bonds of global variables */
end_comment

begin_if
if|if
condition|(
name|PL_rsfp
condition|)
block|{
operator|(
name|void
operator|)
name|PerlIO_close
argument_list|(
name|PL_rsfp
argument_list|)
expr_stmt|;
name|PL_rsfp
operator|=
name|Nullfp
expr_stmt|;
block|}
end_if

begin_comment
comment|/* Filters for program text */
end_comment

begin_expr_stmt
name|SvREFCNT_dec
argument_list|(
name|PL_rsfp_filters
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|PL_rsfp_filters
operator|=
name|Nullav
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* switches */
end_comment

begin_expr_stmt
name|PL_preprocess
operator|=
name|FALSE
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|PL_minus_n
operator|=
name|FALSE
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|PL_minus_p
operator|=
name|FALSE
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|PL_minus_l
operator|=
name|FALSE
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|PL_minus_a
operator|=
name|FALSE
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|PL_minus_F
operator|=
name|FALSE
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|PL_doswitches
operator|=
name|FALSE
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|PL_dowarn
operator|=
name|FALSE
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|PL_doextract
operator|=
name|FALSE
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|PL_sawampersand
operator|=
name|FALSE
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* must save all match strings */
end_comment

begin_expr_stmt
name|PL_sawstudy
operator|=
name|FALSE
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* do fbm_instr on all strings */
end_comment

begin_expr_stmt
name|PL_sawvec
operator|=
name|FALSE
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|PL_unsafe
operator|=
name|FALSE
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|Safefree
argument_list|(
name|PL_inplace
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|PL_inplace
operator|=
name|Nullch
expr_stmt|;
end_expr_stmt

begin_if
if|if
condition|(
name|PL_e_script
condition|)
block|{
name|SvREFCNT_dec
argument_list|(
name|PL_e_script
argument_list|)
expr_stmt|;
name|PL_e_script
operator|=
name|Nullsv
expr_stmt|;
block|}
end_if

begin_comment
comment|/* magical thingies */
end_comment

begin_expr_stmt
name|Safefree
argument_list|(
name|PL_ofs
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* $, */
end_comment

begin_expr_stmt
name|PL_ofs
operator|=
name|Nullch
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|Safefree
argument_list|(
name|PL_ors
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* $\ */
end_comment

begin_expr_stmt
name|PL_ors
operator|=
name|Nullch
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|SvREFCNT_dec
argument_list|(
name|PL_rs
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* $/ */
end_comment

begin_expr_stmt
name|PL_rs
operator|=
name|Nullsv
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|SvREFCNT_dec
argument_list|(
name|PL_nrs
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* $/ helper */
end_comment

begin_expr_stmt
name|PL_nrs
operator|=
name|Nullsv
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|PL_multiline
operator|=
literal|0
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* $* */
end_comment

begin_expr_stmt
name|SvREFCNT_dec
argument_list|(
name|PL_statname
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|PL_statname
operator|=
name|Nullsv
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|PL_statgv
operator|=
name|Nullgv
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* defgv, aka *_ should be taken care of elsewhere */
end_comment

begin_comment
comment|/* clean up after study() */
end_comment

begin_expr_stmt
name|SvREFCNT_dec
argument_list|(
name|PL_lastscream
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|PL_lastscream
operator|=
name|Nullsv
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|Safefree
argument_list|(
name|PL_screamfirst
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|PL_screamfirst
operator|=
literal|0
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|Safefree
argument_list|(
name|PL_screamnext
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|PL_screamnext
operator|=
literal|0
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* startup and shutdown function lists */
end_comment

begin_expr_stmt
name|SvREFCNT_dec
argument_list|(
name|PL_beginav
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|SvREFCNT_dec
argument_list|(
name|PL_endav
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|SvREFCNT_dec
argument_list|(
name|PL_initav
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|PL_beginav
operator|=
name|Nullav
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|PL_endav
operator|=
name|Nullav
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|PL_initav
operator|=
name|Nullav
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* shortcuts just get cleared */
end_comment

begin_expr_stmt
name|PL_envgv
operator|=
name|Nullgv
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|PL_siggv
operator|=
name|Nullgv
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|PL_incgv
operator|=
name|Nullgv
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|PL_hintgv
operator|=
name|Nullgv
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|PL_errgv
operator|=
name|Nullgv
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|PL_argvgv
operator|=
name|Nullgv
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|PL_argvoutgv
operator|=
name|Nullgv
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|PL_stdingv
operator|=
name|Nullgv
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|PL_last_in_gv
operator|=
name|Nullgv
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|PL_replgv
operator|=
name|Nullgv
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* reset so print() ends up where we expect */
end_comment

begin_expr_stmt
name|setdefout
argument_list|(
name|Nullgv
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* Prepare to destruct main symbol table.  */
end_comment

begin_expr_stmt
name|hv
operator|=
name|PL_defstash
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|PL_defstash
operator|=
literal|0
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|SvREFCNT_dec
argument_list|(
name|hv
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|FREETMPS
expr_stmt|;
end_expr_stmt

begin_if
if|if
condition|(
name|destruct_level
operator|>=
literal|2
condition|)
block|{
if|if
condition|(
name|PL_scopestack_ix
operator|!=
literal|0
condition|)
name|warn
argument_list|(
literal|"Unbalanced scopes: %ld more ENTERs than LEAVEs\n"
argument_list|,
operator|(
name|long
operator|)
name|PL_scopestack_ix
argument_list|)
expr_stmt|;
if|if
condition|(
name|PL_savestack_ix
operator|!=
literal|0
condition|)
name|warn
argument_list|(
literal|"Unbalanced saves: %ld more saves than restores\n"
argument_list|,
operator|(
name|long
operator|)
name|PL_savestack_ix
argument_list|)
expr_stmt|;
if|if
condition|(
name|PL_tmps_floor
operator|!=
operator|-
literal|1
condition|)
name|warn
argument_list|(
literal|"Unbalanced tmps: %ld more allocs than frees\n"
argument_list|,
operator|(
name|long
operator|)
name|PL_tmps_floor
operator|+
literal|1
argument_list|)
expr_stmt|;
if|if
condition|(
name|cxstack_ix
operator|!=
operator|-
literal|1
condition|)
name|warn
argument_list|(
literal|"Unbalanced context: %ld more PUSHes than POPs\n"
argument_list|,
operator|(
name|long
operator|)
name|cxstack_ix
operator|+
literal|1
argument_list|)
expr_stmt|;
block|}
end_if

begin_comment
comment|/* Now absolutely destruct everything, somehow or other, loops or no. */
end_comment

begin_expr_stmt
name|last_sv_count
operator|=
literal|0
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|SvFLAGS
argument_list|(
name|PL_strtab
argument_list|)
operator||=
name|SVTYPEMASK
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* don't clean out strtab now */
end_comment

begin_while
while|while
condition|(
name|PL_sv_count
operator|!=
literal|0
operator|&&
name|PL_sv_count
operator|!=
name|last_sv_count
condition|)
block|{
name|last_sv_count
operator|=
name|PL_sv_count
expr_stmt|;
name|sv_clean_all
argument_list|()
expr_stmt|;
block|}
end_while

begin_expr_stmt
name|SvFLAGS
argument_list|(
name|PL_strtab
argument_list|)
operator|&=
operator|~
name|SVTYPEMASK
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|SvFLAGS
argument_list|(
name|PL_strtab
argument_list|)
operator||=
name|SVt_PVHV
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* Destruct the global string table. */
end_comment

begin_block
block|{
comment|/* Yell and reset the HeVAL() slots that are still holding refcounts, 	 * so that sv_free() won't fail on them. 	 */
name|I32
name|riter
decl_stmt|;
name|I32
name|max
decl_stmt|;
name|HE
modifier|*
name|hent
decl_stmt|;
name|HE
modifier|*
modifier|*
name|array
decl_stmt|;
name|riter
operator|=
literal|0
expr_stmt|;
name|max
operator|=
name|HvMAX
argument_list|(
name|PL_strtab
argument_list|)
expr_stmt|;
name|array
operator|=
name|HvARRAY
argument_list|(
name|PL_strtab
argument_list|)
expr_stmt|;
name|hent
operator|=
name|array
index|[
literal|0
index|]
expr_stmt|;
for|for
control|(
init|;
condition|;
control|)
block|{
if|if
condition|(
name|hent
condition|)
block|{
name|warn
argument_list|(
literal|"Unbalanced string table refcount: (%d) for \"%s\""
argument_list|,
name|HeVAL
argument_list|(
name|hent
argument_list|)
operator|-
name|Nullsv
argument_list|,
name|HeKEY
argument_list|(
name|hent
argument_list|)
argument_list|)
expr_stmt|;
name|HeVAL
argument_list|(
name|hent
argument_list|)
operator|=
name|Nullsv
expr_stmt|;
name|hent
operator|=
name|HeNEXT
argument_list|(
name|hent
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
operator|!
name|hent
condition|)
block|{
if|if
condition|(
operator|++
name|riter
operator|>
name|max
condition|)
break|break;
name|hent
operator|=
name|array
index|[
name|riter
index|]
expr_stmt|;
block|}
block|}
block|}
end_block

begin_expr_stmt
name|SvREFCNT_dec
argument_list|(
name|PL_strtab
argument_list|)
expr_stmt|;
end_expr_stmt

begin_if
if|if
condition|(
name|PL_sv_count
operator|!=
literal|0
condition|)
name|warn
argument_list|(
literal|"Scalars leaked: %ld\n"
argument_list|,
operator|(
name|long
operator|)
name|PL_sv_count
argument_list|)
expr_stmt|;
end_if

begin_expr_stmt
name|sv_free_arenas
argument_list|()
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* No SVs have survived, need to clean out */
end_comment

begin_expr_stmt
name|PL_linestr
operator|=
name|NULL
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|PL_pidstatus
operator|=
name|Nullhv
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|Safefree
argument_list|(
name|PL_origfilename
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|Safefree
argument_list|(
name|PL_archpat_auto
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|Safefree
argument_list|(
name|PL_reg_start_tmp
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|Safefree
argument_list|(
name|HeKEY_hek
argument_list|(
operator|&
name|PL_hv_fetch_ent_mh
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|Safefree
argument_list|(
name|PL_op_mask
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|nuke_stacks
argument_list|()
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|PL_hints
operator|=
literal|0
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* Reset hints. Should hints be per-interpreter ? */
end_comment

begin_expr_stmt
name|DEBUG_P
argument_list|(
name|debprofdump
argument_list|()
argument_list|)
expr_stmt|;
end_expr_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|USE_THREADS
end_ifdef

begin_expr_stmt
name|MUTEX_DESTROY
argument_list|(
operator|&
name|PL_strtab_mutex
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|MUTEX_DESTROY
argument_list|(
operator|&
name|PL_sv_mutex
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|MUTEX_DESTROY
argument_list|(
operator|&
name|PL_cred_mutex
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|MUTEX_DESTROY
argument_list|(
operator|&
name|PL_eval_mutex
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|COND_DESTROY
argument_list|(
operator|&
name|PL_eval_cond
argument_list|)
expr_stmt|;
end_expr_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|EMULATE_ATOMIC_REFCOUNTS
end_ifdef

begin_expr_stmt
name|MUTEX_DESTROY
argument_list|(
operator|&
name|PL_svref_mutex
argument_list|)
expr_stmt|;
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* EMULATE_ATOMIC_REFCOUNTS */
end_comment

begin_comment
comment|/* As the penultimate thing, free the non-arena SV for thrsv */
end_comment

begin_expr_stmt
name|Safefree
argument_list|(
name|SvPVX
argument_list|(
name|PL_thrsv
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|Safefree
argument_list|(
name|SvANY
argument_list|(
name|PL_thrsv
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|Safefree
argument_list|(
name|PL_thrsv
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|PL_thrsv
operator|=
name|Nullsv
expr_stmt|;
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* USE_THREADS */
end_comment

begin_comment
comment|/* As the absolutely last thing, free the non-arena SV for mess() */
end_comment

begin_if
if|if
condition|(
name|PL_mess_sv
condition|)
block|{
comment|/* it could have accumulated taint magic */
if|if
condition|(
name|SvTYPE
argument_list|(
name|PL_mess_sv
argument_list|)
operator|>=
name|SVt_PVMG
condition|)
block|{
name|MAGIC
modifier|*
name|mg
decl_stmt|;
name|MAGIC
modifier|*
name|moremagic
decl_stmt|;
for|for
control|(
name|mg
operator|=
name|SvMAGIC
argument_list|(
name|PL_mess_sv
argument_list|)
init|;
name|mg
condition|;
name|mg
operator|=
name|moremagic
control|)
block|{
name|moremagic
operator|=
name|mg
operator|->
name|mg_moremagic
expr_stmt|;
if|if
condition|(
name|mg
operator|->
name|mg_ptr
operator|&&
name|mg
operator|->
name|mg_type
operator|!=
literal|'g'
operator|&&
name|mg
operator|->
name|mg_len
operator|>=
literal|0
condition|)
name|Safefree
argument_list|(
name|mg
operator|->
name|mg_ptr
argument_list|)
expr_stmt|;
name|Safefree
argument_list|(
name|mg
argument_list|)
expr_stmt|;
block|}
block|}
comment|/* we know that type>= SVt_PV */
name|SvOOK_off
argument_list|(
name|PL_mess_sv
argument_list|)
expr_stmt|;
name|Safefree
argument_list|(
name|SvPVX
argument_list|(
name|PL_mess_sv
argument_list|)
argument_list|)
expr_stmt|;
name|Safefree
argument_list|(
name|SvANY
argument_list|(
name|PL_mess_sv
argument_list|)
argument_list|)
expr_stmt|;
name|Safefree
argument_list|(
name|PL_mess_sv
argument_list|)
expr_stmt|;
name|PL_mess_sv
operator|=
name|Nullsv
expr_stmt|;
block|}
end_if

begin_ifdef
unit|}  void
ifdef|#
directive|ifdef
name|PERL_OBJECT
end_ifdef

begin_expr_stmt
name|CPerlObj
operator|::
name|perl_free
argument_list|(
argument|void
argument_list|)
else|#
directive|else
name|perl_free
argument_list|(
argument|PerlInterpreter *sv_interp
argument_list|)
endif|#
directive|endif
block|{
ifdef|#
directive|ifdef
name|PERL_OBJECT
name|Safefree
argument_list|(
name|this
argument_list|)
block|;
else|#
directive|else
if|if
condition|(
operator|!
operator|(
name|PL_curinterp
operator|=
name|sv_interp
operator|)
condition|)
return|return;
name|Safefree
argument_list|(
name|sv_interp
argument_list|)
expr_stmt|;
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
unit|}  void
ifdef|#
directive|ifdef
name|PERL_OBJECT
end_ifdef

begin_expr_stmt
name|CPerlObj
operator|::
name|perl_atexit
argument_list|(
argument|void (*fn) (CPerlObj*,void *)
argument_list|,
argument|void *ptr
argument_list|)
else|#
directive|else
name|perl_atexit
argument_list|(
argument|void (*fn) (void *)
argument_list|,
argument|void *ptr
argument_list|)
endif|#
directive|endif
block|{
name|Renew
argument_list|(
name|PL_exitlist
argument_list|,
name|PL_exitlistlen
operator|+
literal|1
argument_list|,
name|PerlExitListEntry
argument_list|)
block|;
name|PL_exitlist
index|[
name|PL_exitlistlen
index|]
operator|.
name|fn
operator|=
name|fn
block|;
name|PL_exitlist
index|[
name|PL_exitlistlen
index|]
operator|.
name|ptr
operator|=
name|ptr
block|;
operator|++
name|PL_exitlistlen
block|; }
name|int
ifdef|#
directive|ifdef
name|PERL_OBJECT
name|CPerlObj
operator|::
name|perl_parse
argument_list|(
argument|void (*xsinit) (CPerlObj*)
argument_list|,
argument|int argc
argument_list|,
argument|char **argv
argument_list|,
argument|char **env
argument_list|)
else|#
directive|else
name|perl_parse
argument_list|(
argument|PerlInterpreter *sv_interp
argument_list|,
argument|void (*xsinit) (void)
argument_list|,
argument|int argc
argument_list|,
argument|char **argv
argument_list|,
argument|char **env
argument_list|)
endif|#
directive|endif
block|{
name|dTHR
block|;
specifier|register
name|SV
operator|*
name|sv
block|;
specifier|register
name|char
operator|*
name|s
block|;
name|char
operator|*
name|scriptname
operator|=
name|NULL
block|;
name|VOL
name|bool
name|dosearch
operator|=
name|FALSE
block|;
name|char
operator|*
name|validarg
operator|=
literal|""
block|;
name|I32
name|oldscope
block|;
name|AV
operator|*
name|comppadlist
block|;
name|dJMPENV
block|;
name|int
name|ret
block|;
name|int
name|fdscript
operator|=
operator|-
literal|1
block|;
ifdef|#
directive|ifdef
name|SETUID_SCRIPTS_ARE_SECURE_NOW
ifdef|#
directive|ifdef
name|IAMSUID
undef|#
directive|undef
name|IAMSUID
name|croak
argument_list|(
literal|"suidperl is no longer needed since the kernel can now execute\n\ setuid perl scripts securely.\n"
argument_list|)
block|;
endif|#
directive|endif
endif|#
directive|endif
ifndef|#
directive|ifndef
name|PERL_OBJECT
if|if
condition|(
operator|!
operator|(
name|PL_curinterp
operator|=
name|sv_interp
operator|)
condition|)
return|return
literal|255
return|;
endif|#
directive|endif
if|#
directive|if
name|defined
argument_list|(
name|NeXT
argument_list|)
operator|&&
name|defined
argument_list|(
name|__DYNAMIC__
argument_list|)
name|_dyld_lookup_and_bind
argument_list|(
literal|"__environ"
argument_list|,
operator|(
name|unsigned
name|long
operator|*
operator|)
operator|&
name|environ_pointer
argument_list|,
name|NULL
argument_list|)
expr_stmt|;
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* environ */
end_comment

begin_expr_stmt
name|PL_origargv
operator|=
name|argv
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|PL_origargc
operator|=
name|argc
expr_stmt|;
end_expr_stmt

begin_ifndef
ifndef|#
directive|ifndef
name|VMS
end_ifndef

begin_comment
comment|/* VMS doesn't have environ array */
end_comment

begin_expr_stmt
name|PL_origenviron
operator|=
name|environ
expr_stmt|;
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|if
condition|(
name|PL_do_undump
condition|)
block|{
comment|/* Come here if running an undumped a.out. */
name|PL_origfilename
operator|=
name|savepv
argument_list|(
name|argv
index|[
literal|0
index|]
argument_list|)
expr_stmt|;
name|PL_do_undump
operator|=
name|FALSE
expr_stmt|;
name|cxstack_ix
operator|=
operator|-
literal|1
expr_stmt|;
comment|/* start label stack again */
name|init_ids
argument_list|()
expr_stmt|;
name|init_postdump_symbols
argument_list|(
name|argc
argument_list|,
name|argv
argument_list|,
name|env
argument_list|)
expr_stmt|;
return|return
literal|0
return|;
block|}
end_if

begin_if
if|if
condition|(
name|PL_main_root
condition|)
block|{
name|PL_curpad
operator|=
name|AvARRAY
argument_list|(
name|PL_comppad
argument_list|)
expr_stmt|;
name|op_free
argument_list|(
name|PL_main_root
argument_list|)
expr_stmt|;
name|PL_main_root
operator|=
name|Nullop
expr_stmt|;
block|}
end_if

begin_expr_stmt
name|PL_main_start
operator|=
name|Nullop
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|SvREFCNT_dec
argument_list|(
name|PL_main_cv
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|PL_main_cv
operator|=
name|Nullcv
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|time
argument_list|(
operator|&
name|PL_basetime
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|oldscope
operator|=
name|PL_scopestack_ix
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|JMPENV_PUSH
argument_list|(
name|ret
argument_list|)
expr_stmt|;
end_expr_stmt

begin_switch
switch|switch
condition|(
name|ret
condition|)
block|{
case|case
literal|1
case|:
name|STATUS_ALL_FAILURE
expr_stmt|;
comment|/* FALL THROUGH */
case|case
literal|2
case|:
comment|/* my_exit() was called */
while|while
condition|(
name|PL_scopestack_ix
operator|>
name|oldscope
condition|)
name|LEAVE
expr_stmt|;
name|FREETMPS
expr_stmt|;
name|PL_curstash
operator|=
name|PL_defstash
expr_stmt|;
if|if
condition|(
name|PL_endav
condition|)
name|call_list
argument_list|(
name|oldscope
argument_list|,
name|PL_endav
argument_list|)
expr_stmt|;
name|JMPENV_POP
expr_stmt|;
return|return
name|STATUS_NATIVE_EXPORT
return|;
case|case
literal|3
case|:
name|JMPENV_POP
expr_stmt|;
name|PerlIO_printf
argument_list|(
name|PerlIO_stderr
argument_list|()
argument_list|,
literal|"panic: top_env\n"
argument_list|)
expr_stmt|;
return|return
literal|1
return|;
block|}
end_switch

begin_expr_stmt
name|sv_setpvn
argument_list|(
name|PL_linestr
argument_list|,
literal|""
argument_list|,
literal|0
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|sv
operator|=
name|newSVpv
argument_list|(
literal|""
argument_list|,
literal|0
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* first used for -I flags */
end_comment

begin_expr_stmt
name|SAVEFREESV
argument_list|(
name|sv
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|init_main_stash
argument_list|()
expr_stmt|;
end_expr_stmt

begin_for
for|for
control|(
name|argc
operator|--
operator|,
name|argv
operator|++
init|;
name|argc
operator|>
literal|0
condition|;
name|argc
operator|--
operator|,
name|argv
operator|++
control|)
block|{
if|if
condition|(
name|argv
index|[
literal|0
index|]
index|[
literal|0
index|]
operator|!=
literal|'-'
operator|||
operator|!
name|argv
index|[
literal|0
index|]
index|[
literal|1
index|]
condition|)
break|break;
ifdef|#
directive|ifdef
name|DOSUID
if|if
condition|(
operator|*
name|validarg
condition|)
name|validarg
operator|=
literal|" PHOOEY "
expr_stmt|;
else|else
name|validarg
operator|=
name|argv
index|[
literal|0
index|]
expr_stmt|;
endif|#
directive|endif
name|s
operator|=
name|argv
index|[
literal|0
index|]
operator|+
literal|1
expr_stmt|;
name|reswitch
label|:
switch|switch
condition|(
operator|*
name|s
condition|)
block|{
ifndef|#
directive|ifndef
name|PERL_STRICT_CR
case|case
literal|'\r'
case|:
endif|#
directive|endif
case|case
literal|' '
case|:
case|case
literal|'0'
case|:
case|case
literal|'F'
case|:
case|case
literal|'a'
case|:
case|case
literal|'c'
case|:
case|case
literal|'d'
case|:
case|case
literal|'D'
case|:
case|case
literal|'h'
case|:
case|case
literal|'i'
case|:
case|case
literal|'l'
case|:
case|case
literal|'M'
case|:
case|case
literal|'m'
case|:
case|case
literal|'n'
case|:
case|case
literal|'p'
case|:
case|case
literal|'s'
case|:
case|case
literal|'u'
case|:
case|case
literal|'U'
case|:
case|case
literal|'v'
case|:
case|case
literal|'w'
case|:
if|if
condition|(
name|s
operator|=
name|moreswitches
argument_list|(
name|s
argument_list|)
condition|)
goto|goto
name|reswitch
goto|;
break|break;
case|case
literal|'T'
case|:
name|PL_tainting
operator|=
name|TRUE
expr_stmt|;
name|s
operator|++
expr_stmt|;
goto|goto
name|reswitch
goto|;
case|case
literal|'e'
case|:
if|if
condition|(
name|PL_euid
operator|!=
name|PL_uid
operator|||
name|PL_egid
operator|!=
name|PL_gid
condition|)
name|croak
argument_list|(
literal|"No -e allowed in setuid scripts"
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|PL_e_script
condition|)
block|{
name|PL_e_script
operator|=
name|newSVpv
argument_list|(
literal|""
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|filter_add
argument_list|(
name|read_e_script
argument_list|,
name|NULL
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
operator|*
operator|++
name|s
condition|)
name|sv_catpv
argument_list|(
name|PL_e_script
argument_list|,
name|s
argument_list|)
expr_stmt|;
elseif|else
if|if
condition|(
name|argv
index|[
literal|1
index|]
condition|)
block|{
name|sv_catpv
argument_list|(
name|PL_e_script
argument_list|,
name|argv
index|[
literal|1
index|]
argument_list|)
expr_stmt|;
name|argc
operator|--
operator|,
name|argv
operator|++
expr_stmt|;
block|}
else|else
name|croak
argument_list|(
literal|"No code specified for -e"
argument_list|)
expr_stmt|;
name|sv_catpv
argument_list|(
name|PL_e_script
argument_list|,
literal|"\n"
argument_list|)
expr_stmt|;
break|break;
case|case
literal|'I'
case|:
comment|/* -I handled both here and in moreswitches() */
name|forbid_setid
argument_list|(
literal|"-I"
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
operator|*
operator|++
name|s
operator|&&
operator|(
name|s
operator|=
name|argv
index|[
literal|1
index|]
operator|)
operator|!=
name|Nullch
condition|)
block|{
name|argc
operator|--
operator|,
name|argv
operator|++
expr_stmt|;
block|}
while|while
condition|(
name|s
operator|&&
name|isSPACE
argument_list|(
operator|*
name|s
argument_list|)
condition|)
operator|++
name|s
expr_stmt|;
if|if
condition|(
name|s
operator|&&
operator|*
name|s
condition|)
block|{
name|char
modifier|*
name|e
decl_stmt|,
modifier|*
name|p
decl_stmt|;
for|for
control|(
name|e
operator|=
name|s
init|;
operator|*
name|e
operator|&&
operator|!
name|isSPACE
argument_list|(
operator|*
name|e
argument_list|)
condition|;
name|e
operator|++
control|)
empty_stmt|;
name|p
operator|=
name|savepvn
argument_list|(
name|s
argument_list|,
name|e
operator|-
name|s
argument_list|)
expr_stmt|;
name|incpush
argument_list|(
name|p
argument_list|,
name|TRUE
argument_list|)
expr_stmt|;
name|sv_catpv
argument_list|(
name|sv
argument_list|,
literal|"-I"
argument_list|)
expr_stmt|;
name|sv_catpv
argument_list|(
name|sv
argument_list|,
name|p
argument_list|)
expr_stmt|;
name|sv_catpv
argument_list|(
name|sv
argument_list|,
literal|" "
argument_list|)
expr_stmt|;
name|Safefree
argument_list|(
name|p
argument_list|)
expr_stmt|;
block|}
comment|/* XXX else croak? */
break|break;
case|case
literal|'P'
case|:
name|forbid_setid
argument_list|(
literal|"-P"
argument_list|)
expr_stmt|;
name|PL_preprocess
operator|=
name|TRUE
expr_stmt|;
name|s
operator|++
expr_stmt|;
goto|goto
name|reswitch
goto|;
case|case
literal|'S'
case|:
name|forbid_setid
argument_list|(
literal|"-S"
argument_list|)
expr_stmt|;
name|dosearch
operator|=
name|TRUE
expr_stmt|;
name|s
operator|++
expr_stmt|;
goto|goto
name|reswitch
goto|;
case|case
literal|'V'
case|:
if|if
condition|(
operator|!
name|PL_preambleav
condition|)
name|PL_preambleav
operator|=
name|newAV
argument_list|()
expr_stmt|;
name|av_push
argument_list|(
name|PL_preambleav
argument_list|,
name|newSVpv
argument_list|(
literal|"use Config qw(myconfig config_vars)"
argument_list|,
literal|0
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
operator|*
operator|++
name|s
operator|!=
literal|':'
condition|)
block|{
name|PL_Sv
operator|=
name|newSVpv
argument_list|(
literal|"print myconfig();"
argument_list|,
literal|0
argument_list|)
expr_stmt|;
ifdef|#
directive|ifdef
name|VMS
name|sv_catpv
argument_list|(
name|PL_Sv
argument_list|,
literal|"print \"\\nCharacteristics of this PERLSHR image: \\n\","
argument_list|)
expr_stmt|;
else|#
directive|else
name|sv_catpv
argument_list|(
name|PL_Sv
argument_list|,
literal|"print \"\\nCharacteristics of this binary (from libperl): \\n\","
argument_list|)
expr_stmt|;
endif|#
directive|endif
if|#
directive|if
name|defined
argument_list|(
name|DEBUGGING
argument_list|)
operator|||
name|defined
argument_list|(
name|NO_EMBED
argument_list|)
operator|||
name|defined
argument_list|(
name|MULTIPLICITY
argument_list|)
name|sv_catpv
argument_list|(
name|PL_Sv
argument_list|,
literal|"\"  Compile-time options:"
argument_list|)
expr_stmt|;
ifdef|#
directive|ifdef
name|DEBUGGING
name|sv_catpv
argument_list|(
name|PL_Sv
argument_list|,
literal|" DEBUGGING"
argument_list|)
expr_stmt|;
endif|#
directive|endif
ifdef|#
directive|ifdef
name|NO_EMBED
name|sv_catpv
argument_list|(
name|PL_Sv
argument_list|,
literal|" NO_EMBED"
argument_list|)
expr_stmt|;
endif|#
directive|endif
ifdef|#
directive|ifdef
name|MULTIPLICITY
name|sv_catpv
argument_list|(
name|PL_Sv
argument_list|,
literal|" MULTIPLICITY"
argument_list|)
expr_stmt|;
endif|#
directive|endif
name|sv_catpv
argument_list|(
name|PL_Sv
argument_list|,
literal|"\\n\","
argument_list|)
expr_stmt|;
endif|#
directive|endif
if|#
directive|if
name|defined
argument_list|(
name|LOCAL_PATCH_COUNT
argument_list|)
if|if
condition|(
name|LOCAL_PATCH_COUNT
operator|>
literal|0
condition|)
block|{
name|int
name|i
decl_stmt|;
name|sv_catpv
argument_list|(
name|PL_Sv
argument_list|,
literal|"\"  Locally applied patches:\\n\","
argument_list|)
expr_stmt|;
for|for
control|(
name|i
operator|=
literal|1
init|;
name|i
operator|<=
name|LOCAL_PATCH_COUNT
condition|;
name|i
operator|++
control|)
block|{
if|if
condition|(
name|PL_localpatches
index|[
name|i
index|]
condition|)
name|sv_catpvf
argument_list|(
name|PL_Sv
argument_list|,
literal|"\"  \\t%s\\n\","
argument_list|,
name|PL_localpatches
index|[
name|i
index|]
argument_list|)
expr_stmt|;
block|}
block|}
endif|#
directive|endif
name|sv_catpvf
argument_list|(
name|PL_Sv
argument_list|,
literal|"\"  Built under %s\\n\""
argument_list|,
name|OSNAME
argument_list|)
expr_stmt|;
ifdef|#
directive|ifdef
name|__DATE__
ifdef|#
directive|ifdef
name|__TIME__
name|sv_catpvf
argument_list|(
name|PL_Sv
argument_list|,
literal|",\"  Compiled at %s %s\\n\""
argument_list|,
name|__DATE__
argument_list|,
name|__TIME__
argument_list|)
expr_stmt|;
else|#
directive|else
name|sv_catpvf
argument_list|(
name|PL_Sv
argument_list|,
literal|",\"  Compiled on %s\\n\""
argument_list|,
name|__DATE__
argument_list|)
expr_stmt|;
endif|#
directive|endif
endif|#
directive|endif
name|sv_catpv
argument_list|(
name|PL_Sv
argument_list|,
literal|"; \ $\"=\"\\n    \"; \ @env = map { \"$_=\\\"$ENV{$_}\\\"\" } sort grep {/^PERL/} keys %ENV; \ print \"  \\%ENV:\\n    @env\\n\" if @env; \ print \"  \\@INC:\\n    @INC\\n\";"
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|PL_Sv
operator|=
name|newSVpv
argument_list|(
literal|"config_vars(qw("
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|sv_catpv
argument_list|(
name|PL_Sv
argument_list|,
operator|++
name|s
argument_list|)
expr_stmt|;
name|sv_catpv
argument_list|(
name|PL_Sv
argument_list|,
literal|"))"
argument_list|)
expr_stmt|;
name|s
operator|+=
name|strlen
argument_list|(
name|s
argument_list|)
expr_stmt|;
block|}
name|av_push
argument_list|(
name|PL_preambleav
argument_list|,
name|PL_Sv
argument_list|)
expr_stmt|;
name|scriptname
operator|=
name|BIT_BUCKET
expr_stmt|;
comment|/* don't look for script or read stdin */
goto|goto
name|reswitch
goto|;
case|case
literal|'x'
case|:
name|PL_doextract
operator|=
name|TRUE
expr_stmt|;
name|s
operator|++
expr_stmt|;
if|if
condition|(
operator|*
name|s
condition|)
name|PL_cddir
operator|=
name|savepv
argument_list|(
name|s
argument_list|)
expr_stmt|;
break|break;
case|case
literal|0
case|:
break|break;
case|case
literal|'-'
case|:
if|if
condition|(
operator|!
operator|*
operator|++
name|s
operator|||
name|isSPACE
argument_list|(
operator|*
name|s
argument_list|)
condition|)
block|{
name|argc
operator|--
operator|,
name|argv
operator|++
expr_stmt|;
goto|goto
name|switch_end
goto|;
block|}
comment|/* catch use of gnu style long options */
if|if
condition|(
name|strEQ
argument_list|(
name|s
argument_list|,
literal|"version"
argument_list|)
condition|)
block|{
name|s
operator|=
literal|"v"
expr_stmt|;
goto|goto
name|reswitch
goto|;
block|}
if|if
condition|(
name|strEQ
argument_list|(
name|s
argument_list|,
literal|"help"
argument_list|)
condition|)
block|{
name|s
operator|=
literal|"h"
expr_stmt|;
goto|goto
name|reswitch
goto|;
block|}
name|s
operator|--
expr_stmt|;
comment|/* FALL THROUGH */
default|default:
name|croak
argument_list|(
literal|"Unrecognized switch: -%s  (-h will show valid options)"
argument_list|,
name|s
argument_list|)
expr_stmt|;
block|}
block|}
end_for

begin_label
name|switch_end
label|:
end_label

begin_if
if|if
condition|(
operator|!
name|PL_tainting
operator|&&
operator|(
name|s
operator|=
name|PerlEnv_getenv
argument_list|(
literal|"PERL5OPT"
argument_list|)
operator|)
condition|)
block|{
while|while
condition|(
name|s
operator|&&
operator|*
name|s
condition|)
block|{
while|while
condition|(
name|isSPACE
argument_list|(
operator|*
name|s
argument_list|)
condition|)
name|s
operator|++
expr_stmt|;
if|if
condition|(
operator|*
name|s
operator|==
literal|'-'
condition|)
block|{
name|s
operator|++
expr_stmt|;
if|if
condition|(
name|isSPACE
argument_list|(
operator|*
name|s
argument_list|)
condition|)
continue|continue;
block|}
if|if
condition|(
operator|!
operator|*
name|s
condition|)
break|break;
if|if
condition|(
operator|!
name|strchr
argument_list|(
literal|"DIMUdmw"
argument_list|,
operator|*
name|s
argument_list|)
condition|)
name|croak
argument_list|(
literal|"Illegal switch in PERL5OPT: -%c"
argument_list|,
operator|*
name|s
argument_list|)
expr_stmt|;
name|s
operator|=
name|moreswitches
argument_list|(
name|s
argument_list|)
expr_stmt|;
block|}
block|}
end_if

begin_if
if|if
condition|(
operator|!
name|scriptname
condition|)
name|scriptname
operator|=
name|argv
index|[
literal|0
index|]
expr_stmt|;
end_if

begin_if
if|if
condition|(
name|PL_e_script
condition|)
block|{
name|argc
operator|++
operator|,
name|argv
operator|--
expr_stmt|;
name|scriptname
operator|=
name|BIT_BUCKET
expr_stmt|;
comment|/* don't look for script or read stdin */
block|}
elseif|else
if|if
condition|(
name|scriptname
operator|==
name|Nullch
condition|)
block|{
ifdef|#
directive|ifdef
name|MSDOS
if|if
condition|(
name|PerlLIO_isatty
argument_list|(
name|PerlIO_fileno
argument_list|(
name|PerlIO_stdin
argument_list|()
argument_list|)
argument_list|)
condition|)
name|moreswitches
argument_list|(
literal|"h"
argument_list|)
expr_stmt|;
endif|#
directive|endif
name|scriptname
operator|=
literal|"-"
expr_stmt|;
block|}
end_if

begin_expr_stmt
name|init_perllib
argument_list|()
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|open_script
argument_list|(
name|scriptname
argument_list|,
name|dosearch
argument_list|,
name|sv
argument_list|,
operator|&
name|fdscript
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|validate_suid
argument_list|(
name|validarg
argument_list|,
name|scriptname
argument_list|,
name|fdscript
argument_list|)
expr_stmt|;
end_expr_stmt

begin_if
if|if
condition|(
name|PL_doextract
condition|)
name|find_beginning
argument_list|()
expr_stmt|;
end_if

begin_expr_stmt
name|PL_main_cv
operator|=
name|PL_compcv
operator|=
operator|(
name|CV
operator|*
operator|)
name|NEWSV
argument_list|(
literal|1104
argument_list|,
literal|0
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|sv_upgrade
argument_list|(
operator|(
name|SV
operator|*
operator|)
name|PL_compcv
argument_list|,
name|SVt_PVCV
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|CvUNIQUE_on
argument_list|(
name|PL_compcv
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|PL_comppad
operator|=
name|newAV
argument_list|()
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|av_push
argument_list|(
name|PL_comppad
argument_list|,
name|Nullsv
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|PL_curpad
operator|=
name|AvARRAY
argument_list|(
name|PL_comppad
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|PL_comppad_name
operator|=
name|newAV
argument_list|()
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|PL_comppad_name_fill
operator|=
literal|0
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|PL_min_intro_pending
operator|=
literal|0
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|PL_padix
operator|=
literal|0
expr_stmt|;
end_expr_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|USE_THREADS
end_ifdef

begin_expr_stmt
name|av_store
argument_list|(
name|PL_comppad_name
argument_list|,
literal|0
argument_list|,
name|newSVpv
argument_list|(
literal|"@_"
argument_list|,
literal|2
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|PL_curpad
index|[
literal|0
index|]
operator|=
operator|(
name|SV
operator|*
operator|)
name|newAV
argument_list|()
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|SvPADMY_on
argument_list|(
name|PL_curpad
index|[
literal|0
index|]
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* XXX Needed? */
end_comment

begin_expr_stmt
name|CvOWNER
argument_list|(
name|PL_compcv
argument_list|)
operator|=
literal|0
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|New
argument_list|(
literal|666
argument_list|,
name|CvMUTEXP
argument_list|(
name|PL_compcv
argument_list|)
argument_list|,
literal|1
argument_list|,
name|perl_mutex
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|MUTEX_INIT
argument_list|(
name|CvMUTEXP
argument_list|(
name|PL_compcv
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* USE_THREADS */
end_comment

begin_expr_stmt
name|comppadlist
operator|=
name|newAV
argument_list|()
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|AvREAL_off
argument_list|(
name|comppadlist
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|av_store
argument_list|(
name|comppadlist
argument_list|,
literal|0
argument_list|,
operator|(
name|SV
operator|*
operator|)
name|PL_comppad_name
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|av_store
argument_list|(
name|comppadlist
argument_list|,
literal|1
argument_list|,
operator|(
name|SV
operator|*
operator|)
name|PL_comppad
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|CvPADLIST
argument_list|(
name|PL_compcv
argument_list|)
operator|=
name|comppadlist
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|boot_core_UNIVERSAL
argument_list|()
expr_stmt|;
end_expr_stmt

begin_if
if|if
condition|(
name|xsinit
condition|)
call|(
modifier|*
name|xsinit
call|)
argument_list|(
name|PERL_OBJECT_THIS
argument_list|)
expr_stmt|;
end_if

begin_comment
comment|/* in case linked C routines want magical variables */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|VMS
argument_list|)
operator|||
name|defined
argument_list|(
name|WIN32
argument_list|)
operator|||
name|defined
argument_list|(
name|DJGPP
argument_list|)
end_if

begin_expr_stmt
name|init_os_extras
argument_list|()
expr_stmt|;
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_expr_stmt
name|init_predump_symbols
argument_list|()
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* init_postdump_symbols not currently designed to be called */
end_comment

begin_comment
comment|/* more than once (ENV isn't cleared first, for example)	 */
end_comment

begin_comment
comment|/* But running with -u leaves %ENV& @ARGV undefined!    XXX */
end_comment

begin_if
if|if
condition|(
operator|!
name|PL_do_undump
condition|)
name|init_postdump_symbols
argument_list|(
name|argc
argument_list|,
name|argv
argument_list|,
name|env
argument_list|)
expr_stmt|;
end_if

begin_expr_stmt
name|init_lexer
argument_list|()
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* now parse the script */
end_comment

begin_expr_stmt
name|SETERRNO
argument_list|(
literal|0
argument_list|,
name|SS$_NORMAL
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|PL_error_count
operator|=
literal|0
expr_stmt|;
end_expr_stmt

begin_if
if|if
condition|(
name|yyparse
argument_list|()
operator|||
name|PL_error_count
condition|)
block|{
if|if
condition|(
name|PL_minus_c
condition|)
name|croak
argument_list|(
literal|"%s had compilation errors.\n"
argument_list|,
name|PL_origfilename
argument_list|)
expr_stmt|;
else|else
block|{
name|croak
argument_list|(
literal|"Execution of %s aborted due to compilation errors.\n"
argument_list|,
name|PL_origfilename
argument_list|)
expr_stmt|;
block|}
block|}
end_if

begin_expr_stmt
name|PL_curcop
operator|->
name|cop_line
operator|=
literal|0
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|PL_curstash
operator|=
name|PL_defstash
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|PL_preprocess
operator|=
name|FALSE
expr_stmt|;
end_expr_stmt

begin_if
if|if
condition|(
name|PL_e_script
condition|)
block|{
name|SvREFCNT_dec
argument_list|(
name|PL_e_script
argument_list|)
expr_stmt|;
name|PL_e_script
operator|=
name|Nullsv
expr_stmt|;
block|}
end_if

begin_comment
comment|/* now that script is parsed, we can modify record separator */
end_comment

begin_expr_stmt
name|SvREFCNT_dec
argument_list|(
name|PL_rs
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|PL_rs
operator|=
name|SvREFCNT_inc
argument_list|(
name|PL_nrs
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|sv_setsv
argument_list|(
name|perl_get_sv
argument_list|(
literal|"/"
argument_list|,
name|TRUE
argument_list|)
argument_list|,
name|PL_rs
argument_list|)
expr_stmt|;
end_expr_stmt

begin_if
if|if
condition|(
name|PL_do_undump
condition|)
name|my_unexec
argument_list|()
expr_stmt|;
end_if

begin_if
if|if
condition|(
name|PL_dowarn
condition|)
name|gv_check
argument_list|(
name|PL_defstash
argument_list|)
expr_stmt|;
end_if

begin_expr_stmt
name|LEAVE
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|FREETMPS
expr_stmt|;
end_expr_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|MYMALLOC
end_ifdef

begin_if
if|if
condition|(
operator|(
name|s
operator|=
name|PerlEnv_getenv
argument_list|(
literal|"PERL_DEBUG_MSTATS"
argument_list|)
operator|)
operator|&&
name|atoi
argument_list|(
name|s
argument_list|)
operator|>=
literal|2
condition|)
name|dump_mstats
argument_list|(
literal|"after compilation:"
argument_list|)
expr_stmt|;
end_if

begin_endif
endif|#
directive|endif
end_endif

begin_expr_stmt
name|ENTER
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|PL_restartop
operator|=
literal|0
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|JMPENV_POP
expr_stmt|;
end_expr_stmt

begin_return
return|return
literal|0
return|;
end_return

begin_ifdef
unit|}  int
ifdef|#
directive|ifdef
name|PERL_OBJECT
end_ifdef

begin_expr_stmt
name|CPerlObj
operator|::
name|perl_run
argument_list|(
argument|void
argument_list|)
else|#
directive|else
name|perl_run
argument_list|(
argument|PerlInterpreter *sv_interp
argument_list|)
endif|#
directive|endif
block|{
name|dSP
block|;
name|I32
name|oldscope
block|;
name|dJMPENV
block|;
name|int
name|ret
block|;
ifndef|#
directive|ifndef
name|PERL_OBJECT
if|if
condition|(
operator|!
operator|(
name|PL_curinterp
operator|=
name|sv_interp
operator|)
condition|)
return|return
literal|255
return|;
endif|#
directive|endif
name|oldscope
operator|=
name|PL_scopestack_ix
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|JMPENV_PUSH
argument_list|(
name|ret
argument_list|)
expr_stmt|;
end_expr_stmt

begin_switch
switch|switch
condition|(
name|ret
condition|)
block|{
case|case
literal|1
case|:
name|cxstack_ix
operator|=
operator|-
literal|1
expr_stmt|;
comment|/* start context stack again */
break|break;
case|case
literal|2
case|:
comment|/* my_exit() was called */
while|while
condition|(
name|PL_scopestack_ix
operator|>
name|oldscope
condition|)
name|LEAVE
expr_stmt|;
name|FREETMPS
expr_stmt|;
name|PL_curstash
operator|=
name|PL_defstash
expr_stmt|;
if|if
condition|(
name|PL_endav
condition|)
name|call_list
argument_list|(
name|oldscope
argument_list|,
name|PL_endav
argument_list|)
expr_stmt|;
ifdef|#
directive|ifdef
name|MYMALLOC
if|if
condition|(
name|PerlEnv_getenv
argument_list|(
literal|"PERL_DEBUG_MSTATS"
argument_list|)
condition|)
name|dump_mstats
argument_list|(
literal|"after execution:  "
argument_list|)
expr_stmt|;
endif|#
directive|endif
name|JMPENV_POP
expr_stmt|;
return|return
name|STATUS_NATIVE_EXPORT
return|;
case|case
literal|3
case|:
if|if
condition|(
operator|!
name|PL_restartop
condition|)
block|{
name|PerlIO_printf
argument_list|(
name|PerlIO_stderr
argument_list|()
argument_list|,
literal|"panic: restartop\n"
argument_list|)
expr_stmt|;
name|FREETMPS
expr_stmt|;
name|JMPENV_POP
expr_stmt|;
return|return
literal|1
return|;
block|}
name|POPSTACK_TO
argument_list|(
name|PL_mainstack
argument_list|)
expr_stmt|;
break|break;
block|}
end_switch

begin_expr_stmt
name|DEBUG_r
argument_list|(
name|PerlIO_printf
argument_list|(
name|Perl_debug_log
argument_list|,
literal|"%s $` $& $' support.\n"
argument_list|,
name|PL_sawampersand
condition|?
literal|"Enabling"
else|:
literal|"Omitting"
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_if
if|if
condition|(
operator|!
name|PL_restartop
condition|)
block|{
name|DEBUG_x
argument_list|(
name|dump_all
argument_list|()
argument_list|)
expr_stmt|;
name|DEBUG
argument_list|(
name|PerlIO_printf
argument_list|(
name|Perl_debug_log
argument_list|,
literal|"\nEXECUTING...\n\n"
argument_list|)
argument_list|)
expr_stmt|;
name|DEBUG_S
argument_list|(
name|PerlIO_printf
argument_list|(
name|Perl_debug_log
argument_list|,
literal|"main thread is 0x%lx\n"
argument_list|,
operator|(
name|unsigned
name|long
operator|)
name|thr
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
name|PL_minus_c
condition|)
block|{
name|PerlIO_printf
argument_list|(
name|PerlIO_stderr
argument_list|()
argument_list|,
literal|"%s syntax OK\n"
argument_list|,
name|PL_origfilename
argument_list|)
expr_stmt|;
name|my_exit
argument_list|(
literal|0
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
name|PERLDB_SINGLE
operator|&&
name|PL_DBsingle
condition|)
name|sv_setiv
argument_list|(
name|PL_DBsingle
argument_list|,
literal|1
argument_list|)
expr_stmt|;
if|if
condition|(
name|PL_initav
condition|)
name|call_list
argument_list|(
name|oldscope
argument_list|,
name|PL_initav
argument_list|)
expr_stmt|;
block|}
end_if

begin_comment
comment|/* do it */
end_comment

begin_if
if|if
condition|(
name|PL_restartop
condition|)
block|{
name|PL_op
operator|=
name|PL_restartop
expr_stmt|;
name|PL_restartop
operator|=
literal|0
expr_stmt|;
name|CALLRUNOPS
argument_list|()
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|PL_main_start
condition|)
block|{
name|CvDEPTH
argument_list|(
name|PL_main_cv
argument_list|)
operator|=
literal|1
expr_stmt|;
name|PL_op
operator|=
name|PL_main_start
expr_stmt|;
name|CALLRUNOPS
argument_list|()
expr_stmt|;
block|}
end_if

begin_expr_stmt
name|my_exit
argument_list|(
literal|0
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* NOTREACHED */
end_comment

begin_return
return|return
literal|0
return|;
end_return

begin_expr_stmt
unit|}  SV
operator|*
name|perl_get_sv
argument_list|(
argument|char *name
argument_list|,
argument|I32 create
argument_list|)
block|{
name|GV
operator|*
name|gv
block|;
ifdef|#
directive|ifdef
name|USE_THREADS
if|if
condition|(
name|name
index|[
literal|1
index|]
operator|==
literal|'\0'
operator|&&
operator|!
name|isALPHA
argument_list|(
name|name
index|[
literal|0
index|]
argument_list|)
condition|)
block|{
name|PADOFFSET
name|tmp
init|=
name|find_threadsv
argument_list|(
name|name
argument_list|)
decl_stmt|;
if|if
condition|(
name|tmp
operator|!=
name|NOT_IN_PAD
condition|)
block|{
name|dTHR
expr_stmt|;
return|return
name|THREADSV
argument_list|(
name|tmp
argument_list|)
return|;
block|}
end_expr_stmt

begin_endif
unit|}
endif|#
directive|endif
end_endif

begin_comment
comment|/* USE_THREADS */
end_comment

begin_expr_stmt
unit|gv
operator|=
name|gv_fetchpv
argument_list|(
name|name
argument_list|,
name|create
argument_list|,
name|SVt_PV
argument_list|)
expr_stmt|;
end_expr_stmt

begin_if
if|if
condition|(
name|gv
condition|)
return|return
name|GvSV
argument_list|(
name|gv
argument_list|)
return|;
end_if

begin_return
return|return
name|Nullsv
return|;
end_return

begin_expr_stmt
unit|}  AV
operator|*
name|perl_get_av
argument_list|(
argument|char *name
argument_list|,
argument|I32 create
argument_list|)
block|{
name|GV
operator|*
name|gv
operator|=
name|gv_fetchpv
argument_list|(
name|name
argument_list|,
name|create
argument_list|,
name|SVt_PVAV
argument_list|)
block|;
if|if
condition|(
name|create
condition|)
return|return
name|GvAVn
argument_list|(
name|gv
argument_list|)
return|;
end_expr_stmt

begin_if
if|if
condition|(
name|gv
condition|)
return|return
name|GvAV
argument_list|(
name|gv
argument_list|)
return|;
end_if

begin_return
return|return
name|Nullav
return|;
end_return

begin_expr_stmt
unit|}  HV
operator|*
name|perl_get_hv
argument_list|(
argument|char *name
argument_list|,
argument|I32 create
argument_list|)
block|{
name|GV
operator|*
name|gv
operator|=
name|gv_fetchpv
argument_list|(
name|name
argument_list|,
name|create
argument_list|,
name|SVt_PVHV
argument_list|)
block|;
if|if
condition|(
name|create
condition|)
return|return
name|GvHVn
argument_list|(
name|gv
argument_list|)
return|;
end_expr_stmt

begin_if
if|if
condition|(
name|gv
condition|)
return|return
name|GvHV
argument_list|(
name|gv
argument_list|)
return|;
end_if

begin_return
return|return
name|Nullhv
return|;
end_return

begin_expr_stmt
unit|}  CV
operator|*
name|perl_get_cv
argument_list|(
argument|char *name
argument_list|,
argument|I32 create
argument_list|)
block|{
name|GV
operator|*
name|gv
operator|=
name|gv_fetchpv
argument_list|(
name|name
argument_list|,
name|create
argument_list|,
name|SVt_PVCV
argument_list|)
block|;
comment|/* XXX unsafe for threads if eval_owner isn't held */
if|if
condition|(
name|create
operator|&&
operator|!
name|GvCVu
argument_list|(
name|gv
argument_list|)
condition|)
return|return
name|newSUB
argument_list|(
name|start_subparse
argument_list|(
name|FALSE
argument_list|,
literal|0
argument_list|)
argument_list|,
name|newSVOP
argument_list|(
name|OP_CONST
argument_list|,
literal|0
argument_list|,
name|newSVpv
argument_list|(
name|name
argument_list|,
literal|0
argument_list|)
argument_list|)
argument_list|,
name|Nullop
argument_list|,
name|Nullop
argument_list|)
return|;
end_expr_stmt

begin_if
if|if
condition|(
name|gv
condition|)
return|return
name|GvCVu
argument_list|(
name|gv
argument_list|)
return|;
end_if

begin_return
return|return
name|Nullcv
return|;
end_return

begin_comment
unit|}
comment|/* Be sure to refetch the stack pointer after calling these routines. */
end_comment

begin_macro
unit|I32
name|perl_call_argv
argument_list|(
argument|char *sub_name
argument_list|,
argument|I32 flags
argument_list|,
argument|register char **argv
argument_list|)
end_macro

begin_comment
comment|/* See G_* flags in cop.h */
end_comment

begin_comment
comment|/* null terminated arg list */
end_comment

begin_block
block|{
name|dSP
expr_stmt|;
name|PUSHMARK
argument_list|(
name|SP
argument_list|)
expr_stmt|;
if|if
condition|(
name|argv
condition|)
block|{
while|while
condition|(
operator|*
name|argv
condition|)
block|{
name|XPUSHs
argument_list|(
name|sv_2mortal
argument_list|(
name|newSVpv
argument_list|(
operator|*
name|argv
argument_list|,
literal|0
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|argv
operator|++
expr_stmt|;
block|}
name|PUTBACK
expr_stmt|;
block|}
return|return
name|perl_call_pv
argument_list|(
name|sub_name
argument_list|,
name|flags
argument_list|)
return|;
block|}
end_block

begin_function
name|I32
name|perl_call_pv
parameter_list|(
name|char
modifier|*
name|sub_name
parameter_list|,
name|I32
name|flags
parameter_list|)
comment|/* name of the subroutine */
comment|/* See G_* flags in cop.h */
block|{
return|return
name|perl_call_sv
argument_list|(
operator|(
name|SV
operator|*
operator|)
name|perl_get_cv
argument_list|(
name|sub_name
argument_list|,
name|TRUE
argument_list|)
argument_list|,
name|flags
argument_list|)
return|;
block|}
end_function

begin_function
name|I32
name|perl_call_method
parameter_list|(
name|char
modifier|*
name|methname
parameter_list|,
name|I32
name|flags
parameter_list|)
comment|/* name of the subroutine */
comment|/* See G_* flags in cop.h */
block|{
name|dSP
expr_stmt|;
name|OP
name|myop
decl_stmt|;
if|if
condition|(
operator|!
name|PL_op
condition|)
name|PL_op
operator|=
operator|&
name|myop
expr_stmt|;
name|XPUSHs
argument_list|(
name|sv_2mortal
argument_list|(
name|newSVpv
argument_list|(
name|methname
argument_list|,
literal|0
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|PUTBACK
expr_stmt|;
name|pp_method
argument_list|(
name|ARGS
argument_list|)
expr_stmt|;
if|if
condition|(
name|PL_op
operator|==
operator|&
name|myop
condition|)
name|PL_op
operator|=
name|Nullop
expr_stmt|;
return|return
name|perl_call_sv
argument_list|(
operator|*
name|PL_stack_sp
operator|--
argument_list|,
name|flags
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/* May be called with any of a CV, a GV, or an SV containing the name. */
end_comment

begin_function
name|I32
name|perl_call_sv
parameter_list|(
name|SV
modifier|*
name|sv
parameter_list|,
name|I32
name|flags
parameter_list|)
comment|/* See G_* flags in cop.h */
block|{
name|dSP
expr_stmt|;
name|LOGOP
name|myop
decl_stmt|;
comment|/* fake syntax tree node */
name|I32
name|oldmark
decl_stmt|;
name|I32
name|retval
decl_stmt|;
name|I32
name|oldscope
decl_stmt|;
name|bool
name|oldcatch
init|=
name|CATCH_GET
decl_stmt|;
name|dJMPENV
expr_stmt|;
name|int
name|ret
decl_stmt|;
name|OP
modifier|*
name|oldop
init|=
name|PL_op
decl_stmt|;
if|if
condition|(
name|flags
operator|&
name|G_DISCARD
condition|)
block|{
name|ENTER
expr_stmt|;
name|SAVETMPS
expr_stmt|;
block|}
name|Zero
argument_list|(
operator|&
name|myop
argument_list|,
literal|1
argument_list|,
name|LOGOP
argument_list|)
expr_stmt|;
name|myop
operator|.
name|op_next
operator|=
name|Nullop
expr_stmt|;
if|if
condition|(
operator|!
operator|(
name|flags
operator|&
name|G_NOARGS
operator|)
condition|)
name|myop
operator|.
name|op_flags
operator||=
name|OPf_STACKED
expr_stmt|;
name|myop
operator|.
name|op_flags
operator||=
operator|(
operator|(
name|flags
operator|&
name|G_VOID
operator|)
condition|?
name|OPf_WANT_VOID
else|:
operator|(
name|flags
operator|&
name|G_ARRAY
operator|)
condition|?
name|OPf_WANT_LIST
else|:
name|OPf_WANT_SCALAR
operator|)
expr_stmt|;
name|SAVEOP
argument_list|()
expr_stmt|;
name|PL_op
operator|=
operator|(
name|OP
operator|*
operator|)
operator|&
name|myop
expr_stmt|;
name|EXTEND
argument_list|(
name|PL_stack_sp
argument_list|,
literal|1
argument_list|)
expr_stmt|;
operator|*
operator|++
name|PL_stack_sp
operator|=
name|sv
expr_stmt|;
name|oldmark
operator|=
name|TOPMARK
expr_stmt|;
name|oldscope
operator|=
name|PL_scopestack_ix
expr_stmt|;
if|if
condition|(
name|PERLDB_SUB
operator|&&
name|PL_curstash
operator|!=
name|PL_debstash
comment|/* Handle first BEGIN of -d. */
operator|&&
operator|(
name|PL_DBcv
operator|||
operator|(
name|PL_DBcv
operator|=
name|GvCV
argument_list|(
name|PL_DBsub
argument_list|)
operator|)
operator|)
comment|/* Try harder, since this may have been a sighandler, thus 	    * curstash may be meaningless. */
operator|&&
operator|(
name|SvTYPE
argument_list|(
name|sv
argument_list|)
operator|!=
name|SVt_PVCV
operator|||
name|CvSTASH
argument_list|(
operator|(
name|CV
operator|*
operator|)
name|sv
argument_list|)
operator|!=
name|PL_debstash
operator|)
operator|&&
operator|!
operator|(
name|flags
operator|&
name|G_NODEBUG
operator|)
condition|)
name|PL_op
operator|->
name|op_private
operator||=
name|OPpENTERSUB_DB
expr_stmt|;
if|if
condition|(
name|flags
operator|&
name|G_EVAL
condition|)
block|{
name|cLOGOP
operator|->
name|op_other
operator|=
name|PL_op
expr_stmt|;
name|PL_markstack_ptr
operator|--
expr_stmt|;
comment|/* we're trying to emulate pp_entertry() here */
block|{
specifier|register
name|PERL_CONTEXT
modifier|*
name|cx
decl_stmt|;
name|I32
name|gimme
init|=
name|GIMME_V
decl_stmt|;
name|ENTER
expr_stmt|;
name|SAVETMPS
expr_stmt|;
name|push_return
argument_list|(
name|PL_op
operator|->
name|op_next
argument_list|)
expr_stmt|;
name|PUSHBLOCK
argument_list|(
name|cx
argument_list|,
name|CXt_EVAL
argument_list|,
name|PL_stack_sp
argument_list|)
expr_stmt|;
name|PUSHEVAL
argument_list|(
name|cx
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|PL_eval_root
operator|=
name|PL_op
expr_stmt|;
comment|/* Only needed so that goto works right. */
name|PL_in_eval
operator|=
literal|1
expr_stmt|;
if|if
condition|(
name|flags
operator|&
name|G_KEEPERR
condition|)
name|PL_in_eval
operator||=
literal|4
expr_stmt|;
else|else
name|sv_setpv
argument_list|(
name|ERRSV
argument_list|,
literal|""
argument_list|)
expr_stmt|;
block|}
name|PL_markstack_ptr
operator|++
expr_stmt|;
name|JMPENV_PUSH
argument_list|(
name|ret
argument_list|)
expr_stmt|;
switch|switch
condition|(
name|ret
condition|)
block|{
case|case
literal|0
case|:
break|break;
case|case
literal|1
case|:
name|STATUS_ALL_FAILURE
expr_stmt|;
comment|/* FALL THROUGH */
case|case
literal|2
case|:
comment|/* my_exit() was called */
name|PL_curstash
operator|=
name|PL_defstash
expr_stmt|;
name|FREETMPS
expr_stmt|;
name|JMPENV_POP
expr_stmt|;
if|if
condition|(
name|PL_statusvalue
condition|)
name|croak
argument_list|(
literal|"Callback called exit"
argument_list|)
expr_stmt|;
name|my_exit_jump
argument_list|()
expr_stmt|;
comment|/* NOTREACHED */
case|case
literal|3
case|:
if|if
condition|(
name|PL_restartop
condition|)
block|{
name|PL_op
operator|=
name|PL_restartop
expr_stmt|;
name|PL_restartop
operator|=
literal|0
expr_stmt|;
break|break;
block|}
name|PL_stack_sp
operator|=
name|PL_stack_base
operator|+
name|oldmark
expr_stmt|;
if|if
condition|(
name|flags
operator|&
name|G_ARRAY
condition|)
name|retval
operator|=
literal|0
expr_stmt|;
else|else
block|{
name|retval
operator|=
literal|1
expr_stmt|;
operator|*
operator|++
name|PL_stack_sp
operator|=
operator|&
name|PL_sv_undef
expr_stmt|;
block|}
goto|goto
name|cleanup
goto|;
block|}
block|}
else|else
name|CATCH_SET
argument_list|(
name|TRUE
argument_list|)
expr_stmt|;
if|if
condition|(
name|PL_op
operator|==
operator|(
name|OP
operator|*
operator|)
operator|&
name|myop
condition|)
name|PL_op
operator|=
name|pp_entersub
argument_list|(
name|ARGS
argument_list|)
expr_stmt|;
if|if
condition|(
name|PL_op
condition|)
name|CALLRUNOPS
argument_list|()
expr_stmt|;
name|retval
operator|=
name|PL_stack_sp
operator|-
operator|(
name|PL_stack_base
operator|+
name|oldmark
operator|)
expr_stmt|;
if|if
condition|(
operator|(
name|flags
operator|&
name|G_EVAL
operator|)
operator|&&
operator|!
operator|(
name|flags
operator|&
name|G_KEEPERR
operator|)
condition|)
name|sv_setpv
argument_list|(
name|ERRSV
argument_list|,
literal|""
argument_list|)
expr_stmt|;
name|cleanup
label|:
if|if
condition|(
name|flags
operator|&
name|G_EVAL
condition|)
block|{
if|if
condition|(
name|PL_scopestack_ix
operator|>
name|oldscope
condition|)
block|{
name|SV
modifier|*
modifier|*
name|newsp
decl_stmt|;
name|PMOP
modifier|*
name|newpm
decl_stmt|;
name|I32
name|gimme
decl_stmt|;
specifier|register
name|PERL_CONTEXT
modifier|*
name|cx
decl_stmt|;
name|I32
name|optype
decl_stmt|;
name|POPBLOCK
argument_list|(
name|cx
argument_list|,
name|newpm
argument_list|)
expr_stmt|;
name|POPEVAL
argument_list|(
name|cx
argument_list|)
expr_stmt|;
name|pop_return
argument_list|()
expr_stmt|;
name|PL_curpm
operator|=
name|newpm
expr_stmt|;
name|LEAVE
expr_stmt|;
block|}
name|JMPENV_POP
expr_stmt|;
block|}
else|else
name|CATCH_SET
argument_list|(
name|oldcatch
argument_list|)
expr_stmt|;
if|if
condition|(
name|flags
operator|&
name|G_DISCARD
condition|)
block|{
name|PL_stack_sp
operator|=
name|PL_stack_base
operator|+
name|oldmark
expr_stmt|;
name|retval
operator|=
literal|0
expr_stmt|;
name|FREETMPS
expr_stmt|;
name|LEAVE
expr_stmt|;
block|}
name|PL_op
operator|=
name|oldop
expr_stmt|;
return|return
name|retval
return|;
block|}
end_function

begin_comment
comment|/* Eval a string. The G_EVAL flag is always assumed. */
end_comment

begin_function
name|I32
name|perl_eval_sv
parameter_list|(
name|SV
modifier|*
name|sv
parameter_list|,
name|I32
name|flags
parameter_list|)
comment|/* See G_* flags in cop.h */
block|{
name|dSP
expr_stmt|;
name|UNOP
name|myop
decl_stmt|;
comment|/* fake syntax tree node */
name|I32
name|oldmark
init|=
name|SP
operator|-
name|PL_stack_base
decl_stmt|;
name|I32
name|retval
decl_stmt|;
name|I32
name|oldscope
decl_stmt|;
name|dJMPENV
expr_stmt|;
name|int
name|ret
decl_stmt|;
name|OP
modifier|*
name|oldop
init|=
name|PL_op
decl_stmt|;
if|if
condition|(
name|flags
operator|&
name|G_DISCARD
condition|)
block|{
name|ENTER
expr_stmt|;
name|SAVETMPS
expr_stmt|;
block|}
name|SAVEOP
argument_list|()
expr_stmt|;
name|PL_op
operator|=
operator|(
name|OP
operator|*
operator|)
operator|&
name|myop
expr_stmt|;
name|Zero
argument_list|(
name|PL_op
argument_list|,
literal|1
argument_list|,
name|UNOP
argument_list|)
expr_stmt|;
name|EXTEND
argument_list|(
name|PL_stack_sp
argument_list|,
literal|1
argument_list|)
expr_stmt|;
operator|*
operator|++
name|PL_stack_sp
operator|=
name|sv
expr_stmt|;
name|oldscope
operator|=
name|PL_scopestack_ix
expr_stmt|;
if|if
condition|(
operator|!
operator|(
name|flags
operator|&
name|G_NOARGS
operator|)
condition|)
name|myop
operator|.
name|op_flags
operator|=
name|OPf_STACKED
expr_stmt|;
name|myop
operator|.
name|op_next
operator|=
name|Nullop
expr_stmt|;
name|myop
operator|.
name|op_type
operator|=
name|OP_ENTEREVAL
expr_stmt|;
name|myop
operator|.
name|op_flags
operator||=
operator|(
operator|(
name|flags
operator|&
name|G_VOID
operator|)
condition|?
name|OPf_WANT_VOID
else|:
operator|(
name|flags
operator|&
name|G_ARRAY
operator|)
condition|?
name|OPf_WANT_LIST
else|:
name|OPf_WANT_SCALAR
operator|)
expr_stmt|;
if|if
condition|(
name|flags
operator|&
name|G_KEEPERR
condition|)
name|myop
operator|.
name|op_flags
operator||=
name|OPf_SPECIAL
expr_stmt|;
name|JMPENV_PUSH
argument_list|(
name|ret
argument_list|)
expr_stmt|;
switch|switch
condition|(
name|ret
condition|)
block|{
case|case
literal|0
case|:
break|break;
case|case
literal|1
case|:
name|STATUS_ALL_FAILURE
expr_stmt|;
comment|/* FALL THROUGH */
case|case
literal|2
case|:
comment|/* my_exit() was called */
name|PL_curstash
operator|=
name|PL_defstash
expr_stmt|;
name|FREETMPS
expr_stmt|;
name|JMPENV_POP
expr_stmt|;
if|if
condition|(
name|PL_statusvalue
condition|)
name|croak
argument_list|(
literal|"Callback called exit"
argument_list|)
expr_stmt|;
name|my_exit_jump
argument_list|()
expr_stmt|;
comment|/* NOTREACHED */
case|case
literal|3
case|:
if|if
condition|(
name|PL_restartop
condition|)
block|{
name|PL_op
operator|=
name|PL_restartop
expr_stmt|;
name|PL_restartop
operator|=
literal|0
expr_stmt|;
break|break;
block|}
name|PL_stack_sp
operator|=
name|PL_stack_base
operator|+
name|oldmark
expr_stmt|;
if|if
condition|(
name|flags
operator|&
name|G_ARRAY
condition|)
name|retval
operator|=
literal|0
expr_stmt|;
else|else
block|{
name|retval
operator|=
literal|1
expr_stmt|;
operator|*
operator|++
name|PL_stack_sp
operator|=
operator|&
name|PL_sv_undef
expr_stmt|;
block|}
goto|goto
name|cleanup
goto|;
block|}
if|if
condition|(
name|PL_op
operator|==
operator|(
name|OP
operator|*
operator|)
operator|&
name|myop
condition|)
name|PL_op
operator|=
name|pp_entereval
argument_list|(
name|ARGS
argument_list|)
expr_stmt|;
if|if
condition|(
name|PL_op
condition|)
name|CALLRUNOPS
argument_list|()
expr_stmt|;
name|retval
operator|=
name|PL_stack_sp
operator|-
operator|(
name|PL_stack_base
operator|+
name|oldmark
operator|)
expr_stmt|;
if|if
condition|(
operator|!
operator|(
name|flags
operator|&
name|G_KEEPERR
operator|)
condition|)
name|sv_setpv
argument_list|(
name|ERRSV
argument_list|,
literal|""
argument_list|)
expr_stmt|;
name|cleanup
label|:
name|JMPENV_POP
expr_stmt|;
if|if
condition|(
name|flags
operator|&
name|G_DISCARD
condition|)
block|{
name|PL_stack_sp
operator|=
name|PL_stack_base
operator|+
name|oldmark
expr_stmt|;
name|retval
operator|=
literal|0
expr_stmt|;
name|FREETMPS
expr_stmt|;
name|LEAVE
expr_stmt|;
block|}
name|PL_op
operator|=
name|oldop
expr_stmt|;
return|return
name|retval
return|;
block|}
end_function

begin_function
name|SV
modifier|*
name|perl_eval_pv
parameter_list|(
name|char
modifier|*
name|p
parameter_list|,
name|I32
name|croak_on_error
parameter_list|)
block|{
name|dSP
expr_stmt|;
name|SV
modifier|*
name|sv
init|=
name|newSVpv
argument_list|(
name|p
argument_list|,
literal|0
argument_list|)
decl_stmt|;
name|PUSHMARK
argument_list|(
name|SP
argument_list|)
expr_stmt|;
name|perl_eval_sv
argument_list|(
name|sv
argument_list|,
name|G_SCALAR
argument_list|)
expr_stmt|;
name|SvREFCNT_dec
argument_list|(
name|sv
argument_list|)
expr_stmt|;
name|SPAGAIN
expr_stmt|;
name|sv
operator|=
name|POPs
expr_stmt|;
name|PUTBACK
expr_stmt|;
if|if
condition|(
name|croak_on_error
operator|&&
name|SvTRUE
argument_list|(
name|ERRSV
argument_list|)
condition|)
block|{
name|STRLEN
name|n_a
decl_stmt|;
name|croak
argument_list|(
name|SvPVx
argument_list|(
name|ERRSV
argument_list|,
name|n_a
argument_list|)
argument_list|)
expr_stmt|;
block|}
return|return
name|sv
return|;
block|}
end_function

begin_comment
comment|/* Require a module. */
end_comment

begin_function
name|void
name|perl_require_pv
parameter_list|(
name|char
modifier|*
name|pv
parameter_list|)
block|{
name|SV
modifier|*
name|sv
decl_stmt|;
name|dSP
expr_stmt|;
name|PUSHSTACKi
argument_list|(
name|PERLSI_REQUIRE
argument_list|)
expr_stmt|;
name|PUTBACK
expr_stmt|;
name|sv
operator|=
name|sv_newmortal
argument_list|()
expr_stmt|;
name|sv_setpv
argument_list|(
name|sv
argument_list|,
literal|"require '"
argument_list|)
expr_stmt|;
name|sv_catpv
argument_list|(
name|sv
argument_list|,
name|pv
argument_list|)
expr_stmt|;
name|sv_catpv
argument_list|(
name|sv
argument_list|,
literal|"'"
argument_list|)
expr_stmt|;
name|perl_eval_sv
argument_list|(
name|sv
argument_list|,
name|G_DISCARD
argument_list|)
expr_stmt|;
name|SPAGAIN
expr_stmt|;
name|POPSTACK
expr_stmt|;
block|}
end_function

begin_function
name|void
name|magicname
parameter_list|(
name|char
modifier|*
name|sym
parameter_list|,
name|char
modifier|*
name|name
parameter_list|,
name|I32
name|namlen
parameter_list|)
block|{
specifier|register
name|GV
modifier|*
name|gv
decl_stmt|;
if|if
condition|(
name|gv
operator|=
name|gv_fetchpv
argument_list|(
name|sym
argument_list|,
name|TRUE
argument_list|,
name|SVt_PV
argument_list|)
condition|)
name|sv_magic
argument_list|(
name|GvSV
argument_list|(
name|gv
argument_list|)
argument_list|,
operator|(
name|SV
operator|*
operator|)
name|gv
argument_list|,
literal|0
argument_list|,
name|name
argument_list|,
name|namlen
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
name|STATIC
name|void
name|usage
parameter_list|(
name|char
modifier|*
name|name
parameter_list|)
comment|/* XXX move this out into a module ? */
block|{
comment|/* This message really ought to be max 23 lines.      * Removed -h because the user already knows that opton. Others? */
specifier|static
name|char
modifier|*
name|usage_msg
index|[]
init|=
block|{
literal|"-0[octal]       specify record separator (\\0, if no argument)"
block|,
literal|"-a              autosplit mode with -n or -p (splits $_ into @F)"
block|,
literal|"-c              check syntax only (runs BEGIN and END blocks)"
block|,
literal|"-d[:debugger]   run scripts under debugger"
block|,
literal|"-D[number/list] set debugging flags (argument is a bit mask or flags)"
block|,
literal|"-e 'command'    one line of script. Several -e's allowed. Omit [programfile]."
block|,
literal|"-F/pattern/     split() pattern for autosplit (-a). The //'s are optional."
block|,
literal|"-i[extension]   edit<> files in place (make backup if extension supplied)"
block|,
literal|"-Idirectory     specify @INC/#include directory (may be used more than once)"
block|,
literal|"-l[octal]       enable line ending processing, specifies line terminator"
block|,
literal|"-[mM][-]module.. executes `use/no module...' before executing your script."
block|,
literal|"-n              assume 'while (<>) { ... }' loop around your script"
block|,
literal|"-p              assume loop like -n but print line also like sed"
block|,
literal|"-P              run script through C preprocessor before compilation"
block|,
literal|"-s              enable some switch parsing for switches after script name"
block|,
literal|"-S              look for the script using PATH environment variable"
block|,
literal|"-T              turn on tainting checks"
block|,
literal|"-u              dump core after parsing script"
block|,
literal|"-U              allow unsafe operations"
block|,
literal|"-v              print version number, patchlevel plus VERY IMPORTANT perl info"
block|,
literal|"-V[:variable]   print perl configuration information"
block|,
literal|"-w              TURN WARNINGS ON FOR COMPILATION OF YOUR SCRIPT. Recommended."
block|,
literal|"-x[directory]   strip off text before #!perl line and perhaps cd to directory"
block|,
literal|"\n"
block|,
name|NULL
block|}
decl_stmt|;
name|char
modifier|*
modifier|*
name|p
init|=
name|usage_msg
decl_stmt|;
name|printf
argument_list|(
literal|"\nUsage: %s [switches] [--] [programfile] [arguments]"
argument_list|,
name|name
argument_list|)
expr_stmt|;
while|while
condition|(
operator|*
name|p
condition|)
name|printf
argument_list|(
literal|"\n  %s"
argument_list|,
operator|*
name|p
operator|++
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/* This routine handles any switches that can be given during run */
end_comment

begin_function
name|char
modifier|*
name|moreswitches
parameter_list|(
name|char
modifier|*
name|s
parameter_list|)
block|{
name|I32
name|numlen
decl_stmt|;
name|U32
name|rschar
decl_stmt|;
switch|switch
condition|(
operator|*
name|s
condition|)
block|{
case|case
literal|'0'
case|:
block|{
name|dTHR
expr_stmt|;
name|rschar
operator|=
name|scan_oct
argument_list|(
name|s
argument_list|,
literal|4
argument_list|,
operator|&
name|numlen
argument_list|)
expr_stmt|;
name|SvREFCNT_dec
argument_list|(
name|PL_nrs
argument_list|)
expr_stmt|;
if|if
condition|(
name|rschar
operator|&
operator|~
operator|(
operator|(
name|U8
operator|)
operator|~
literal|0
operator|)
condition|)
name|PL_nrs
operator|=
operator|&
name|PL_sv_undef
expr_stmt|;
elseif|else
if|if
condition|(
operator|!
name|rschar
operator|&&
name|numlen
operator|>=
literal|2
condition|)
name|PL_nrs
operator|=
name|newSVpv
argument_list|(
literal|""
argument_list|,
literal|0
argument_list|)
expr_stmt|;
else|else
block|{
name|char
name|ch
init|=
name|rschar
decl_stmt|;
name|PL_nrs
operator|=
name|newSVpv
argument_list|(
operator|&
name|ch
argument_list|,
literal|1
argument_list|)
expr_stmt|;
block|}
return|return
name|s
operator|+
name|numlen
return|;
block|}
case|case
literal|'F'
case|:
name|PL_minus_F
operator|=
name|TRUE
expr_stmt|;
name|PL_splitstr
operator|=
name|savepv
argument_list|(
name|s
operator|+
literal|1
argument_list|)
expr_stmt|;
name|s
operator|+=
name|strlen
argument_list|(
name|s
argument_list|)
expr_stmt|;
return|return
name|s
return|;
case|case
literal|'a'
case|:
name|PL_minus_a
operator|=
name|TRUE
expr_stmt|;
name|s
operator|++
expr_stmt|;
return|return
name|s
return|;
case|case
literal|'c'
case|:
name|PL_minus_c
operator|=
name|TRUE
expr_stmt|;
name|s
operator|++
expr_stmt|;
return|return
name|s
return|;
case|case
literal|'d'
case|:
name|forbid_setid
argument_list|(
literal|"-d"
argument_list|)
expr_stmt|;
name|s
operator|++
expr_stmt|;
if|if
condition|(
operator|*
name|s
operator|==
literal|':'
operator|||
operator|*
name|s
operator|==
literal|'='
condition|)
block|{
name|my_setenv
argument_list|(
literal|"PERL5DB"
argument_list|,
name|form
argument_list|(
literal|"use Devel::%s;"
argument_list|,
operator|++
name|s
argument_list|)
argument_list|)
expr_stmt|;
name|s
operator|+=
name|strlen
argument_list|(
name|s
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
operator|!
name|PL_perldb
condition|)
block|{
name|PL_perldb
operator|=
name|PERLDB_ALL
expr_stmt|;
name|init_debugger
argument_list|()
expr_stmt|;
block|}
return|return
name|s
return|;
case|case
literal|'D'
case|:
ifdef|#
directive|ifdef
name|DEBUGGING
name|forbid_setid
argument_list|(
literal|"-D"
argument_list|)
expr_stmt|;
if|if
condition|(
name|isALPHA
argument_list|(
name|s
index|[
literal|1
index|]
argument_list|)
condition|)
block|{
specifier|static
name|char
name|debopts
index|[]
init|=
literal|"psltocPmfrxuLHXDS"
decl_stmt|;
name|char
modifier|*
name|d
decl_stmt|;
for|for
control|(
name|s
operator|++
init|;
operator|*
name|s
operator|&&
operator|(
name|d
operator|=
name|strchr
argument_list|(
name|debopts
argument_list|,
operator|*
name|s
argument_list|)
operator|)
condition|;
name|s
operator|++
control|)
name|PL_debug
operator||=
literal|1
operator|<<
operator|(
name|d
operator|-
name|debopts
operator|)
expr_stmt|;
block|}
else|else
block|{
name|PL_debug
operator|=
name|atoi
argument_list|(
name|s
operator|+
literal|1
argument_list|)
expr_stmt|;
for|for
control|(
name|s
operator|++
init|;
name|isDIGIT
argument_list|(
operator|*
name|s
argument_list|)
condition|;
name|s
operator|++
control|)
empty_stmt|;
block|}
name|PL_debug
operator||=
literal|0x80000000
expr_stmt|;
else|#
directive|else
name|warn
argument_list|(
literal|"Recompile perl with -DDEBUGGING to use -D switch\n"
argument_list|)
expr_stmt|;
for|for
control|(
name|s
operator|++
init|;
name|isALNUM
argument_list|(
operator|*
name|s
argument_list|)
condition|;
name|s
operator|++
control|)
empty_stmt|;
endif|#
directive|endif
comment|/*SUPPRESS 530*/
return|return
name|s
return|;
case|case
literal|'h'
case|:
name|usage
argument_list|(
name|PL_origargv
index|[
literal|0
index|]
argument_list|)
expr_stmt|;
name|PerlProc_exit
argument_list|(
literal|0
argument_list|)
expr_stmt|;
case|case
literal|'i'
case|:
if|if
condition|(
name|PL_inplace
condition|)
name|Safefree
argument_list|(
name|PL_inplace
argument_list|)
expr_stmt|;
name|PL_inplace
operator|=
name|savepv
argument_list|(
name|s
operator|+
literal|1
argument_list|)
expr_stmt|;
comment|/*SUPPRESS 530*/
for|for
control|(
name|s
operator|=
name|PL_inplace
init|;
operator|*
name|s
operator|&&
operator|!
name|isSPACE
argument_list|(
operator|*
name|s
argument_list|)
condition|;
name|s
operator|++
control|)
empty_stmt|;
if|if
condition|(
operator|*
name|s
condition|)
block|{
operator|*
name|s
operator|++
operator|=
literal|'\0'
expr_stmt|;
if|if
condition|(
operator|*
name|s
operator|==
literal|'-'
condition|)
comment|/* Additional switches on #! line. */
name|s
operator|++
expr_stmt|;
block|}
return|return
name|s
return|;
case|case
literal|'I'
case|:
comment|/* -I handled both here and in parse_perl() */
name|forbid_setid
argument_list|(
literal|"-I"
argument_list|)
expr_stmt|;
operator|++
name|s
expr_stmt|;
while|while
condition|(
operator|*
name|s
operator|&&
name|isSPACE
argument_list|(
operator|*
name|s
argument_list|)
condition|)
operator|++
name|s
expr_stmt|;
if|if
condition|(
operator|*
name|s
condition|)
block|{
name|char
modifier|*
name|e
decl_stmt|,
modifier|*
name|p
decl_stmt|;
for|for
control|(
name|e
operator|=
name|s
init|;
operator|*
name|e
operator|&&
operator|!
name|isSPACE
argument_list|(
operator|*
name|e
argument_list|)
condition|;
name|e
operator|++
control|)
empty_stmt|;
name|p
operator|=
name|savepvn
argument_list|(
name|s
argument_list|,
name|e
operator|-
name|s
argument_list|)
expr_stmt|;
name|incpush
argument_list|(
name|p
argument_list|,
name|TRUE
argument_list|)
expr_stmt|;
name|Safefree
argument_list|(
name|p
argument_list|)
expr_stmt|;
name|s
operator|=
name|e
expr_stmt|;
block|}
else|else
name|croak
argument_list|(
literal|"No space allowed after -I"
argument_list|)
expr_stmt|;
return|return
name|s
return|;
case|case
literal|'l'
case|:
name|PL_minus_l
operator|=
name|TRUE
expr_stmt|;
name|s
operator|++
expr_stmt|;
if|if
condition|(
name|PL_ors
condition|)
name|Safefree
argument_list|(
name|PL_ors
argument_list|)
expr_stmt|;
if|if
condition|(
name|isDIGIT
argument_list|(
operator|*
name|s
argument_list|)
condition|)
block|{
name|PL_ors
operator|=
name|savepv
argument_list|(
literal|"\n"
argument_list|)
expr_stmt|;
name|PL_orslen
operator|=
literal|1
expr_stmt|;
operator|*
name|PL_ors
operator|=
name|scan_oct
argument_list|(
name|s
argument_list|,
literal|3
operator|+
operator|(
operator|*
name|s
operator|==
literal|'0'
operator|)
argument_list|,
operator|&
name|numlen
argument_list|)
expr_stmt|;
name|s
operator|+=
name|numlen
expr_stmt|;
block|}
else|else
block|{
name|dTHR
expr_stmt|;
if|if
condition|(
name|RsPARA
argument_list|(
name|PL_nrs
argument_list|)
condition|)
block|{
name|PL_ors
operator|=
literal|"\n\n"
expr_stmt|;
name|PL_orslen
operator|=
literal|2
expr_stmt|;
block|}
else|else
name|PL_ors
operator|=
name|SvPV
argument_list|(
name|PL_nrs
argument_list|,
name|PL_orslen
argument_list|)
expr_stmt|;
name|PL_ors
operator|=
name|savepvn
argument_list|(
name|PL_ors
argument_list|,
name|PL_orslen
argument_list|)
expr_stmt|;
block|}
return|return
name|s
return|;
case|case
literal|'M'
case|:
name|forbid_setid
argument_list|(
literal|"-M"
argument_list|)
expr_stmt|;
comment|/* XXX ? */
comment|/* FALL THROUGH */
case|case
literal|'m'
case|:
name|forbid_setid
argument_list|(
literal|"-m"
argument_list|)
expr_stmt|;
comment|/* XXX ? */
if|if
condition|(
operator|*
operator|++
name|s
condition|)
block|{
name|char
modifier|*
name|start
decl_stmt|;
name|SV
modifier|*
name|sv
decl_stmt|;
name|char
modifier|*
name|use
init|=
literal|"use "
decl_stmt|;
comment|/* -M-foo == 'no foo'	*/
if|if
condition|(
operator|*
name|s
operator|==
literal|'-'
condition|)
block|{
name|use
operator|=
literal|"no "
expr_stmt|;
operator|++
name|s
expr_stmt|;
block|}
name|sv
operator|=
name|newSVpv
argument_list|(
name|use
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|start
operator|=
name|s
expr_stmt|;
comment|/* We allow -M'Module qw(Foo Bar)'	*/
while|while
condition|(
name|isALNUM
argument_list|(
operator|*
name|s
argument_list|)
operator|||
operator|*
name|s
operator|==
literal|':'
condition|)
operator|++
name|s
expr_stmt|;
if|if
condition|(
operator|*
name|s
operator|!=
literal|'='
condition|)
block|{
name|sv_catpv
argument_list|(
name|sv
argument_list|,
name|start
argument_list|)
expr_stmt|;
if|if
condition|(
operator|*
operator|(
name|start
operator|-
literal|1
operator|)
operator|==
literal|'m'
condition|)
block|{
if|if
condition|(
operator|*
name|s
operator|!=
literal|'\0'
condition|)
name|croak
argument_list|(
literal|"Can't use '%c' after -mname"
argument_list|,
operator|*
name|s
argument_list|)
expr_stmt|;
name|sv_catpv
argument_list|(
name|sv
argument_list|,
literal|" ()"
argument_list|)
expr_stmt|;
block|}
block|}
else|else
block|{
name|sv_catpvn
argument_list|(
name|sv
argument_list|,
name|start
argument_list|,
name|s
operator|-
name|start
argument_list|)
expr_stmt|;
name|sv_catpv
argument_list|(
name|sv
argument_list|,
literal|" split(/,/,q{"
argument_list|)
expr_stmt|;
name|sv_catpv
argument_list|(
name|sv
argument_list|,
operator|++
name|s
argument_list|)
expr_stmt|;
name|sv_catpv
argument_list|(
name|sv
argument_list|,
literal|"})"
argument_list|)
expr_stmt|;
block|}
name|s
operator|+=
name|strlen
argument_list|(
name|s
argument_list|)
expr_stmt|;
if|if
condition|(
name|PL_preambleav
operator|==
name|NULL
condition|)
name|PL_preambleav
operator|=
name|newAV
argument_list|()
expr_stmt|;
name|av_push
argument_list|(
name|PL_preambleav
argument_list|,
name|sv
argument_list|)
expr_stmt|;
block|}
else|else
name|croak
argument_list|(
literal|"No space allowed after -%c"
argument_list|,
operator|*
operator|(
name|s
operator|-
literal|1
operator|)
argument_list|)
expr_stmt|;
return|return
name|s
return|;
case|case
literal|'n'
case|:
name|PL_minus_n
operator|=
name|TRUE
expr_stmt|;
name|s
operator|++
expr_stmt|;
return|return
name|s
return|;
case|case
literal|'p'
case|:
name|PL_minus_p
operator|=
name|TRUE
expr_stmt|;
name|s
operator|++
expr_stmt|;
return|return
name|s
return|;
case|case
literal|'s'
case|:
name|forbid_setid
argument_list|(
literal|"-s"
argument_list|)
expr_stmt|;
name|PL_doswitches
operator|=
name|TRUE
expr_stmt|;
name|s
operator|++
expr_stmt|;
return|return
name|s
return|;
case|case
literal|'T'
case|:
if|if
condition|(
operator|!
name|PL_tainting
condition|)
name|croak
argument_list|(
literal|"Too late for \"-T\" option"
argument_list|)
expr_stmt|;
name|s
operator|++
expr_stmt|;
return|return
name|s
return|;
case|case
literal|'u'
case|:
name|PL_do_undump
operator|=
name|TRUE
expr_stmt|;
name|s
operator|++
expr_stmt|;
return|return
name|s
return|;
case|case
literal|'U'
case|:
name|PL_unsafe
operator|=
name|TRUE
expr_stmt|;
name|s
operator|++
expr_stmt|;
return|return
name|s
return|;
case|case
literal|'v'
case|:
if|#
directive|if
name|defined
argument_list|(
name|SUBVERSION
argument_list|)
operator|&&
name|SUBVERSION
operator|>
literal|0
name|printf
argument_list|(
literal|"\nThis is perl, version 5.%03d_%02d built for %s"
argument_list|,
name|PATCHLEVEL
argument_list|,
name|SUBVERSION
argument_list|,
name|ARCHNAME
argument_list|)
expr_stmt|;
else|#
directive|else
name|printf
argument_list|(
literal|"\nThis is perl, version %s built for %s"
argument_list|,
name|PL_patchlevel
argument_list|,
name|ARCHNAME
argument_list|)
expr_stmt|;
endif|#
directive|endif
if|#
directive|if
name|defined
argument_list|(
name|LOCAL_PATCH_COUNT
argument_list|)
if|if
condition|(
name|LOCAL_PATCH_COUNT
operator|>
literal|0
condition|)
name|printf
argument_list|(
literal|"\n(with %d registered patch%s, see perl -V for more detail)"
argument_list|,
name|LOCAL_PATCH_COUNT
argument_list|,
operator|(
name|LOCAL_PATCH_COUNT
operator|!=
literal|1
operator|)
condition|?
literal|"es"
else|:
literal|""
argument_list|)
expr_stmt|;
endif|#
directive|endif
name|printf
argument_list|(
literal|"\n\nCopyright 1987-1999, Larry Wall\n"
argument_list|)
expr_stmt|;
ifdef|#
directive|ifdef
name|MSDOS
name|printf
argument_list|(
literal|"\nMS-DOS port Copyright (c) 1989, 1990, Diomidis Spinellis\n"
argument_list|)
expr_stmt|;
endif|#
directive|endif
ifdef|#
directive|ifdef
name|DJGPP
name|printf
argument_list|(
literal|"djgpp v2 port (jpl5003c) by Hirofumi Watanabe, 1996\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"djgpp v2 port (perl5004+) by Laszlo Molnar, 1997-1998\n"
argument_list|)
expr_stmt|;
endif|#
directive|endif
ifdef|#
directive|ifdef
name|OS2
name|printf
argument_list|(
literal|"\n\nOS/2 port Copyright (c) 1990, 1991, Raymond Chen, Kai Uwe Rommel\n"
literal|"Version 5 port Copyright (c) 1994-1998, Andreas Kaiser, Ilya Zakharevich\n"
argument_list|)
expr_stmt|;
endif|#
directive|endif
ifdef|#
directive|ifdef
name|atarist
name|printf
argument_list|(
literal|"atariST series port, ++jrb  bammi@cadence.com\n"
argument_list|)
expr_stmt|;
endif|#
directive|endif
ifdef|#
directive|ifdef
name|__BEOS__
name|printf
argument_list|(
literal|"BeOS port Copyright Tom Spindler, 1997-1998\n"
argument_list|)
expr_stmt|;
endif|#
directive|endif
ifdef|#
directive|ifdef
name|MPE
name|printf
argument_list|(
literal|"MPE/iX port Copyright by Mark Klein and Mark Bixby, 1996-1998\n"
argument_list|)
expr_stmt|;
endif|#
directive|endif
ifdef|#
directive|ifdef
name|OEMVS
name|printf
argument_list|(
literal|"MVS (OS390) port by Mortice Kern Systems, 1997-1998\n"
argument_list|)
expr_stmt|;
endif|#
directive|endif
ifdef|#
directive|ifdef
name|__VOS__
name|printf
argument_list|(
literal|"Stratus VOS port by Paul_Green@stratus.com, 1997-1999\n"
argument_list|)
expr_stmt|;
endif|#
directive|endif
ifdef|#
directive|ifdef
name|__MINT__
name|printf
argument_list|(
literal|"MiNT port by Guido Flohr, 1997\n"
argument_list|)
expr_stmt|;
endif|#
directive|endif
ifdef|#
directive|ifdef
name|BINARY_BUILD_NOTICE
name|BINARY_BUILD_NOTICE
expr_stmt|;
endif|#
directive|endif
name|printf
argument_list|(
literal|"\n\ Perl may be copied only under the terms of either the Artistic License or the\n\ GNU General Public License, which may be found in the Perl 5.0 source kit.\n\n\ Complete documentation for Perl, including FAQ lists, should be found on\n\ this system using `man perl' or `perldoc perl'.  If you have access to the\n\ Internet, point your browser at http://www.perl.com/, the Perl Home Page.\n\n"
argument_list|)
expr_stmt|;
name|PerlProc_exit
argument_list|(
literal|0
argument_list|)
expr_stmt|;
case|case
literal|'w'
case|:
name|PL_dowarn
operator|=
name|TRUE
expr_stmt|;
name|s
operator|++
expr_stmt|;
return|return
name|s
return|;
case|case
literal|'*'
case|:
case|case
literal|' '
case|:
if|if
condition|(
name|s
index|[
literal|1
index|]
operator|==
literal|'-'
condition|)
comment|/* Additional switches on #! line. */
return|return
name|s
operator|+
literal|2
return|;
break|break;
case|case
literal|'-'
case|:
case|case
literal|0
case|:
if|#
directive|if
name|defined
argument_list|(
name|WIN32
argument_list|)
operator|||
operator|!
name|defined
argument_list|(
name|PERL_STRICT_CR
argument_list|)
case|case
literal|'\r'
case|:
endif|#
directive|endif
case|case
literal|'\n'
case|:
case|case
literal|'\t'
case|:
break|break;
ifdef|#
directive|ifdef
name|ALTERNATE_SHEBANG
case|case
literal|'S'
case|:
comment|/* OS/2 needs -S on "extproc" line. */
break|break;
endif|#
directive|endif
case|case
literal|'P'
case|:
if|if
condition|(
name|PL_preprocess
condition|)
return|return
name|s
operator|+
literal|1
return|;
comment|/* FALL THROUGH */
default|default:
name|croak
argument_list|(
literal|"Can't emulate -%.1s on #! line"
argument_list|,
name|s
argument_list|)
expr_stmt|;
block|}
return|return
name|Nullch
return|;
block|}
end_function

begin_comment
comment|/* compliments of Tom Christiansen */
end_comment

begin_comment
comment|/* unexec() can be found in the Gnu emacs distribution */
end_comment

begin_comment
comment|/* Known to work with -DUNEXEC and using unexelf.c from GNU emacs-20.2 */
end_comment

begin_function
name|void
name|my_unexec
parameter_list|(
name|void
parameter_list|)
block|{
ifdef|#
directive|ifdef
name|UNEXEC
name|SV
modifier|*
name|prog
decl_stmt|;
name|SV
modifier|*
name|file
decl_stmt|;
name|int
name|status
init|=
literal|1
decl_stmt|;
specifier|extern
name|int
name|etext
decl_stmt|;
name|prog
operator|=
name|newSVpv
argument_list|(
name|BIN_EXP
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|sv_catpv
argument_list|(
name|prog
argument_list|,
literal|"/perl"
argument_list|)
expr_stmt|;
name|file
operator|=
name|newSVpv
argument_list|(
name|PL_origfilename
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|sv_catpv
argument_list|(
name|file
argument_list|,
literal|".perldump"
argument_list|)
expr_stmt|;
name|unexec
argument_list|(
name|SvPVX
argument_list|(
name|file
argument_list|)
argument_list|,
name|SvPVX
argument_list|(
name|prog
argument_list|)
argument_list|,
operator|&
name|etext
argument_list|,
name|sbrk
argument_list|(
literal|0
argument_list|)
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|/* unexec prints msg to stderr in case of failure */
name|PerlProc_exit
argument_list|(
name|status
argument_list|)
expr_stmt|;
else|#
directive|else
ifdef|#
directive|ifdef
name|VMS
include|#
directive|include
file|<lib$routines.h>
name|lib$signal
argument_list|(
name|SS$_DEBUG
argument_list|)
expr_stmt|;
comment|/* ssdef.h #included from vmsish.h */
else|#
directive|else
name|ABORT
argument_list|()
expr_stmt|;
comment|/* for use with undump */
endif|#
directive|endif
endif|#
directive|endif
block|}
end_function

begin_comment
comment|/* initialize curinterp */
end_comment

begin_function
name|STATIC
name|void
name|init_interp
parameter_list|(
name|void
parameter_list|)
block|{
ifdef|#
directive|ifdef
name|PERL_OBJECT
comment|/* XXX kludge */
define|#
directive|define
name|I_REINIT
define|\
value|STMT_START {				\     PL_chopset		= " \n-";	\     PL_copline		= NOLINE;	\     PL_curcop		=&PL_compiling;\     PL_curcopdb		= NULL;		\     PL_dbargs		= 0;		\     PL_dlmax		= 128;		\     PL_laststatval	= -1;		\     PL_laststype	= OP_STAT;	\     PL_maxscream	= -1;		\     PL_maxsysfd		= MAXSYSFD;	\     PL_statname		= Nullsv;	\     PL_tmps_floor	= -1;		\     PL_tmps_ix		= -1;		\     PL_op_mask		= NULL;		\     PL_dlmax		= 128;		\     PL_laststatval	= -1;		\     PL_laststype	= OP_STAT;	\     PL_mess_sv		= Nullsv;	\     PL_splitstr		= " ";		\     PL_generation	= 100;		\     PL_exitlist		= NULL;		\     PL_exitlistlen	= 0;		\     PL_regindent	= 0;		\     PL_in_clean_objs	= FALSE;	\     PL_in_clean_all	= FALSE;	\     PL_profiledata	= NULL;		\     PL_rsfp		= Nullfp;	\     PL_rsfp_filters	= Nullav;	\   } STMT_END
name|I_REINIT
expr_stmt|;
else|#
directive|else
ifdef|#
directive|ifdef
name|MULTIPLICITY
define|#
directive|define
name|PERLVAR
parameter_list|(
name|var
parameter_list|,
name|type
parameter_list|)
define|#
directive|define
name|PERLVARI
parameter_list|(
name|var
parameter_list|,
name|type
parameter_list|,
name|init
parameter_list|)
value|PL_curinterp->var = init;
define|#
directive|define
name|PERLVARIC
parameter_list|(
name|var
parameter_list|,
name|type
parameter_list|,
name|init
parameter_list|)
value|PL_curinterp->var = init;
include|#
directive|include
file|"intrpvar.h"
ifndef|#
directive|ifndef
name|USE_THREADS
include|#
directive|include
file|"thrdvar.h"
endif|#
directive|endif
undef|#
directive|undef
name|PERLVAR
undef|#
directive|undef
name|PERLVARI
undef|#
directive|undef
name|PERLVARIC
else|#
directive|else
define|#
directive|define
name|PERLVAR
parameter_list|(
name|var
parameter_list|,
name|type
parameter_list|)
define|#
directive|define
name|PERLVARI
parameter_list|(
name|var
parameter_list|,
name|type
parameter_list|,
name|init
parameter_list|)
value|PL_##var = init;
define|#
directive|define
name|PERLVARIC
parameter_list|(
name|var
parameter_list|,
name|type
parameter_list|,
name|init
parameter_list|)
value|PL_##var = init;
include|#
directive|include
file|"intrpvar.h"
ifndef|#
directive|ifndef
name|USE_THREADS
include|#
directive|include
file|"thrdvar.h"
endif|#
directive|endif
undef|#
directive|undef
name|PERLVAR
undef|#
directive|undef
name|PERLVARI
undef|#
directive|undef
name|PERLVARIC
endif|#
directive|endif
endif|#
directive|endif
block|}
end_function

begin_function
name|STATIC
name|void
name|init_main_stash
parameter_list|(
name|void
parameter_list|)
block|{
name|dTHR
expr_stmt|;
name|GV
modifier|*
name|gv
decl_stmt|;
comment|/* Note that strtab is a rather special HV.  Assumptions are made        about not iterating on it, and not adding tie magic to it.        It is properly deallocated in perl_destruct() */
name|PL_strtab
operator|=
name|newHV
argument_list|()
expr_stmt|;
ifdef|#
directive|ifdef
name|USE_THREADS
name|MUTEX_INIT
argument_list|(
operator|&
name|PL_strtab_mutex
argument_list|)
expr_stmt|;
endif|#
directive|endif
name|HvSHAREKEYS_off
argument_list|(
name|PL_strtab
argument_list|)
expr_stmt|;
comment|/* mandatory */
name|hv_ksplit
argument_list|(
name|PL_strtab
argument_list|,
literal|512
argument_list|)
expr_stmt|;
name|PL_curstash
operator|=
name|PL_defstash
operator|=
name|newHV
argument_list|()
expr_stmt|;
name|PL_curstname
operator|=
name|newSVpv
argument_list|(
literal|"main"
argument_list|,
literal|4
argument_list|)
expr_stmt|;
name|gv
operator|=
name|gv_fetchpv
argument_list|(
literal|"main::"
argument_list|,
name|TRUE
argument_list|,
name|SVt_PVHV
argument_list|)
expr_stmt|;
name|SvREFCNT_dec
argument_list|(
name|GvHV
argument_list|(
name|gv
argument_list|)
argument_list|)
expr_stmt|;
name|GvHV
argument_list|(
name|gv
argument_list|)
operator|=
operator|(
name|HV
operator|*
operator|)
name|SvREFCNT_inc
argument_list|(
name|PL_defstash
argument_list|)
expr_stmt|;
name|SvREADONLY_on
argument_list|(
name|gv
argument_list|)
expr_stmt|;
name|HvNAME
argument_list|(
name|PL_defstash
argument_list|)
operator|=
name|savepv
argument_list|(
literal|"main"
argument_list|)
expr_stmt|;
name|PL_incgv
operator|=
name|gv_HVadd
argument_list|(
name|gv_AVadd
argument_list|(
name|gv_fetchpv
argument_list|(
literal|"INC"
argument_list|,
name|TRUE
argument_list|,
name|SVt_PVAV
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|GvMULTI_on
argument_list|(
name|PL_incgv
argument_list|)
expr_stmt|;
name|PL_hintgv
operator|=
name|gv_fetchpv
argument_list|(
literal|"\010"
argument_list|,
name|TRUE
argument_list|,
name|SVt_PV
argument_list|)
expr_stmt|;
comment|/* ^H */
name|GvMULTI_on
argument_list|(
name|PL_hintgv
argument_list|)
expr_stmt|;
name|PL_defgv
operator|=
name|gv_fetchpv
argument_list|(
literal|"_"
argument_list|,
name|TRUE
argument_list|,
name|SVt_PVAV
argument_list|)
expr_stmt|;
name|PL_errgv
operator|=
name|gv_HVadd
argument_list|(
name|gv_fetchpv
argument_list|(
literal|"@"
argument_list|,
name|TRUE
argument_list|,
name|SVt_PV
argument_list|)
argument_list|)
expr_stmt|;
name|GvMULTI_on
argument_list|(
name|PL_errgv
argument_list|)
expr_stmt|;
name|PL_replgv
operator|=
name|gv_fetchpv
argument_list|(
literal|"\022"
argument_list|,
name|TRUE
argument_list|,
name|SVt_PV
argument_list|)
expr_stmt|;
comment|/* ^R */
name|GvMULTI_on
argument_list|(
name|PL_replgv
argument_list|)
expr_stmt|;
operator|(
name|void
operator|)
name|form
argument_list|(
literal|"%240s"
argument_list|,
literal|""
argument_list|)
expr_stmt|;
comment|/* Preallocate temp - for immediate signals. */
name|sv_grow
argument_list|(
name|ERRSV
argument_list|,
literal|240
argument_list|)
expr_stmt|;
comment|/* Preallocate - for immediate signals. */
name|sv_setpvn
argument_list|(
name|ERRSV
argument_list|,
literal|""
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|PL_curstash
operator|=
name|PL_defstash
expr_stmt|;
name|PL_compiling
operator|.
name|cop_stash
operator|=
name|PL_defstash
expr_stmt|;
name|PL_debstash
operator|=
name|GvHV
argument_list|(
name|gv_fetchpv
argument_list|(
literal|"DB::"
argument_list|,
name|GV_ADDMULTI
argument_list|,
name|SVt_PVHV
argument_list|)
argument_list|)
expr_stmt|;
name|PL_globalstash
operator|=
name|GvHV
argument_list|(
name|gv_fetchpv
argument_list|(
literal|"CORE::GLOBAL::"
argument_list|,
name|GV_ADDMULTI
argument_list|,
name|SVt_PVHV
argument_list|)
argument_list|)
expr_stmt|;
comment|/* We must init $/ before switches are processed. */
name|sv_setpvn
argument_list|(
name|perl_get_sv
argument_list|(
literal|"/"
argument_list|,
name|TRUE
argument_list|)
argument_list|,
literal|"\n"
argument_list|,
literal|1
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
name|STATIC
name|void
name|open_script
parameter_list|(
name|char
modifier|*
name|scriptname
parameter_list|,
name|bool
name|dosearch
parameter_list|,
name|SV
modifier|*
name|sv
parameter_list|,
name|int
modifier|*
name|fdscript
parameter_list|)
block|{
name|dTHR
expr_stmt|;
specifier|register
name|char
modifier|*
name|s
decl_stmt|;
operator|*
name|fdscript
operator|=
operator|-
literal|1
expr_stmt|;
if|if
condition|(
name|PL_e_script
condition|)
block|{
name|PL_origfilename
operator|=
name|savepv
argument_list|(
literal|"-e"
argument_list|)
expr_stmt|;
block|}
else|else
block|{
comment|/* if find_script() returns, it returns a malloc()-ed value */
name|PL_origfilename
operator|=
name|scriptname
operator|=
name|find_script
argument_list|(
name|scriptname
argument_list|,
name|dosearch
argument_list|,
name|NULL
argument_list|,
literal|1
argument_list|)
expr_stmt|;
if|if
condition|(
name|strnEQ
argument_list|(
name|scriptname
argument_list|,
literal|"/dev/fd/"
argument_list|,
literal|8
argument_list|)
operator|&&
name|isDIGIT
argument_list|(
name|scriptname
index|[
literal|8
index|]
argument_list|)
condition|)
block|{
name|char
modifier|*
name|s
init|=
name|scriptname
operator|+
literal|8
decl_stmt|;
operator|*
name|fdscript
operator|=
name|atoi
argument_list|(
name|s
argument_list|)
expr_stmt|;
while|while
condition|(
name|isDIGIT
argument_list|(
operator|*
name|s
argument_list|)
condition|)
name|s
operator|++
expr_stmt|;
if|if
condition|(
operator|*
name|s
condition|)
block|{
name|scriptname
operator|=
name|savepv
argument_list|(
name|s
operator|+
literal|1
argument_list|)
expr_stmt|;
name|Safefree
argument_list|(
name|PL_origfilename
argument_list|)
expr_stmt|;
name|PL_origfilename
operator|=
name|scriptname
expr_stmt|;
block|}
block|}
block|}
name|PL_curcop
operator|->
name|cop_filegv
operator|=
name|gv_fetchfile
argument_list|(
name|PL_origfilename
argument_list|)
expr_stmt|;
if|if
condition|(
name|strEQ
argument_list|(
name|PL_origfilename
argument_list|,
literal|"-"
argument_list|)
condition|)
name|scriptname
operator|=
literal|""
expr_stmt|;
if|if
condition|(
operator|*
name|fdscript
operator|>=
literal|0
condition|)
block|{
name|PL_rsfp
operator|=
name|PerlIO_fdopen
argument_list|(
operator|*
name|fdscript
argument_list|,
name|PERL_SCRIPT_MODE
argument_list|)
expr_stmt|;
if|#
directive|if
name|defined
argument_list|(
name|HAS_FCNTL
argument_list|)
operator|&&
name|defined
argument_list|(
name|F_SETFD
argument_list|)
if|if
condition|(
name|PL_rsfp
condition|)
name|fcntl
argument_list|(
name|PerlIO_fileno
argument_list|(
name|PL_rsfp
argument_list|)
argument_list|,
name|F_SETFD
argument_list|,
literal|1
argument_list|)
expr_stmt|;
comment|/* ensure close-on-exec */
endif|#
directive|endif
block|}
elseif|else
if|if
condition|(
name|PL_preprocess
condition|)
block|{
name|char
modifier|*
name|cpp_cfg
init|=
name|CPPSTDIN
decl_stmt|;
name|SV
modifier|*
name|cpp
init|=
name|newSVpv
argument_list|(
literal|""
argument_list|,
literal|0
argument_list|)
decl_stmt|;
name|SV
modifier|*
name|cmd
init|=
name|NEWSV
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
decl_stmt|;
if|if
condition|(
name|strEQ
argument_list|(
name|cpp_cfg
argument_list|,
literal|"cppstdin"
argument_list|)
condition|)
name|sv_catpvf
argument_list|(
name|cpp
argument_list|,
literal|"%s/"
argument_list|,
name|BIN_EXP
argument_list|)
expr_stmt|;
name|sv_catpv
argument_list|(
name|cpp
argument_list|,
name|cpp_cfg
argument_list|)
expr_stmt|;
name|sv_catpv
argument_list|(
name|sv
argument_list|,
literal|"-I"
argument_list|)
expr_stmt|;
name|sv_catpv
argument_list|(
name|sv
argument_list|,
name|PRIVLIB_EXP
argument_list|)
expr_stmt|;
ifdef|#
directive|ifdef
name|MSDOS
name|sv_setpvf
argument_list|(
argument|cmd
argument_list|,
literal|"\ sed %s -e \"/^[^#]/b\" \  -e \"/^#[ 	]*include[ 	]/b\" \  -e \"/^#[ 	]*define[ 	]/b\" \  -e \"/^#[ 	]*if[ 	]/b\" \  -e \"/^#[ 	]*ifdef[ 	]/b\" \  -e \"/^#[ 	]*ifndef[ 	]/b\" \  -e \"/^#[ 	]*else/b\" \  -e \"/^#[ 	]*elif[ 	]/b\" \  -e \"/^#[ 	]*undef[ 	]/b\" \  -e \"/^#[ 	]*endif/b\" \  -e \"s/^#.*//\" \  %s | %_ -C %_ %s"
argument_list|,
argument|(PL_doextract ?
literal|"-e \"1,/^#/d\n\""
argument|:
literal|""
argument|)
argument_list|,
else|#
directive|else
argument|sv_setpvf(cmd,
literal|"\ %s %s -e '/^[^#]/b' \  -e '/^#[ 	]*include[ 	]/b' \  -e '/^#[ 	]*define[ 	]/b' \  -e '/^#[ 	]*if[ 	]/b' \  -e '/^#[ 	]*ifdef[ 	]/b' \  -e '/^#[ 	]*ifndef[ 	]/b' \  -e '/^#[ 	]*else/b' \  -e '/^#[ 	]*elif[ 	]/b' \  -e '/^#[ 	]*undef[ 	]/b' \  -e '/^#[ 	]*endif/b' \  -e 's/^[ 	]*#.*//' \  %s | %_ -C %_ %s"
argument|,
ifdef|#
directive|ifdef
name|LOC_SED
argument|LOC_SED,
else|#
directive|else
literal|"sed"
argument|,
endif|#
directive|endif
argument|(PL_doextract ?
literal|"-e '1,/^#/d\n'"
argument|:
literal|""
argument|),
endif|#
directive|endif
argument|scriptname, cpp, sv, CPPMINUS); 	PL_doextract = FALSE;
ifdef|#
directive|ifdef
name|IAMSUID
comment|/* actually, this is caught earlier */
argument|if (PL_euid != PL_uid&& !PL_euid) {
comment|/* if running suidperl */
ifdef|#
directive|ifdef
name|HAS_SETEUID
argument|(void)seteuid(PL_uid);
comment|/* musn't stay setuid root */
else|#
directive|else
ifdef|#
directive|ifdef
name|HAS_SETREUID
argument|(void)setreuid((Uid_t)-
literal|1
argument|, PL_uid);
else|#
directive|else
ifdef|#
directive|ifdef
name|HAS_SETRESUID
argument|(void)setresuid((Uid_t)-
literal|1
argument|, PL_uid, (Uid_t)-
literal|1
argument|);
else|#
directive|else
argument|PerlProc_setuid(PL_uid);
endif|#
directive|endif
endif|#
directive|endif
endif|#
directive|endif
argument|if (PerlProc_geteuid() != PL_uid) 		croak(
literal|"Can't do seteuid!\n"
argument|); 	}
endif|#
directive|endif
comment|/* IAMSUID */
argument|PL_rsfp = PerlProc_popen(SvPVX(cmd),
literal|"r"
argument|); 	SvREFCNT_dec(cmd); 	SvREFCNT_dec(cpp);     }     else if (!*scriptname) { 	forbid_setid(
literal|"program input from stdin"
argument|); 	PL_rsfp = PerlIO_stdin();     }     else { 	PL_rsfp = PerlIO_open(scriptname,PERL_SCRIPT_MODE);
if|#
directive|if
name|defined
argument_list|(
name|HAS_FCNTL
argument_list|)
operator|&&
name|defined
argument_list|(
name|F_SETFD
argument_list|)
argument|if (PL_rsfp) 	    fcntl(PerlIO_fileno(PL_rsfp),F_SETFD,
literal|1
argument|);
comment|/* ensure close-on-exec */
endif|#
directive|endif
argument|}     if (!PL_rsfp) {
ifdef|#
directive|ifdef
name|DOSUID
ifndef|#
directive|ifndef
name|IAMSUID
comment|/* in case script is not readable before setuid */
argument|if (PL_euid&& 	    PerlLIO_stat(SvPVX(GvSV(PL_curcop->cop_filegv)),&PL_statbuf)>=
literal|0
argument|&& 	    PL_statbuf.st_mode& (S_ISUID|S_ISGID)) 	{
comment|/* try again */
argument|PerlProc_execv(form(
literal|"%s/sperl%s"
argument|, BIN_EXP, PL_patchlevel), PL_origargv); 	    croak(
literal|"Can't do setuid\n"
argument|); 	}
endif|#
directive|endif
endif|#
directive|endif
argument|croak(
literal|"Can't open perl script \"%s\": %s\n"
argument|, 	  SvPVX(GvSV(PL_curcop->cop_filegv)), Strerror(errno));     } }
ifdef|#
directive|ifdef
name|IAMSUID
argument|static int fd_on_nosuid_fs(int fd) {     int on_nosuid  =
literal|0
argument|;     int check_okay =
literal|0
argument|;
comment|/*  * Preferred order: fstatvfs(), fstatfs(), getmntent().  * fstatvfs() is UNIX98.  * fstatfs() is BSD.  * getmntent() is O(number-of-mounted-filesystems) and can hang.  */
ifdef|#
directive|ifdef
name|HAS_FSTATVFS
argument|struct statvfs stfs;     check_okay = fstatvfs(fd,&stfs) ==
literal|0
argument|;     on_nosuid  = check_okay&& (stfs.f_flag& ST_NOSUID);
else|#
directive|else
if|#
directive|if
name|defined
argument_list|(
name|HAS_FSTATFS
argument_list|)
operator|&&
name|defined
argument_list|(
name|HAS_STRUCT_STATFS_FLAGS
argument_list|)
argument|struct statfs  stfs;     check_okay = fstatfs(fd,&stfs)  ==
literal|0
argument|;
undef|#
directive|undef
name|PERL_MOUNT_NOSUID
if|#
directive|if
operator|!
name|defined
argument_list|(
name|PERL_MOUNT_NOSUID
argument_list|)
operator|&&
name|defined
argument_list|(
name|MNT_NOSUID
argument_list|)
define|#
directive|define
name|PERL_MOUNT_NOSUID
value|MNT_NOSUID
endif|#
directive|endif
if|#
directive|if
operator|!
name|defined
argument_list|(
name|PERL_MOUNT_NOSUID
argument_list|)
operator|&&
name|defined
argument_list|(
name|MS_NOSUID
argument_list|)
define|#
directive|define
name|PERL_MOUNT_NOSUID
value|MS_NOSUID
endif|#
directive|endif
if|#
directive|if
operator|!
name|defined
argument_list|(
name|PERL_MOUNT_NOSUID
argument_list|)
operator|&&
name|defined
argument_list|(
name|M_NOSUID
argument_list|)
define|#
directive|define
name|PERL_MOUNT_NOSUID
value|M_NOSUID
endif|#
directive|endif
ifdef|#
directive|ifdef
name|PERL_MOUNT_NOSUID
argument|on_nosuid  = check_okay&& (stfs.f_flags& PERL_MOUNT_NOSUID);
endif|#
directive|endif
else|#
directive|else
if|#
directive|if
name|defined
argument_list|(
name|HAS_GETMNTENT
argument_list|)
operator|&&
name|defined
argument_list|(
name|HAS_HASMNTOPT
argument_list|)
operator|&&
name|defined
argument_list|(
name|MNTOPT_NOSUID
argument_list|)
argument|FILE		*mtab = fopen(
literal|"/etc/mtab"
argument|,
literal|"r"
argument|);     struct mntent	*entry;     struct stat		stb
argument_list|,
argument|fsb;      if (mtab&& (fstat(fd,&stb) ==
literal|0
argument|)) { 	while (entry = getmntent(mtab)) { 	    if (stat(entry->mnt_dir,&fsb) ==
literal|0
argument|&& fsb.st_dev == stb.st_dev) 	    {
comment|/* found the filesystem */
argument|check_okay =
literal|1
argument|; 		if (hasmntopt(entry, MNTOPT_NOSUID)) 		    on_nosuid =
literal|1
argument|; 		break; 	    }
comment|/* A single fs may well fail its stat(). */
argument|}     }     if (mtab) 	fclose(mtab);
endif|#
directive|endif
comment|/* mntent */
endif|#
directive|endif
comment|/* statfs */
endif|#
directive|endif
comment|/* statvfs */
argument|if (!check_okay)  	croak(
literal|"Can't check filesystem of script \"%s\" for nosuid"
argument|, 	      PL_origfilename);     return on_nosuid; }
endif|#
directive|endif
comment|/* IAMSUID */
argument|STATIC void validate_suid(char *validarg, char *scriptname, int fdscript) {     int which;
comment|/* do we need to emulate setuid on scripts? */
comment|/* This code is for those BSD systems that have setuid #! scripts disabled      * in the kernel because of a security problem.  Merely defining DOSUID      * in perl will not fix that problem, but if you have disabled setuid      * scripts in the kernel, this will attempt to emulate setuid and setgid      * on scripts that have those now-otherwise-useless bits set.  The setuid      * root version must be called suidperl or sperlN.NNN.  If regular perl      * discovers that it has opened a setuid script, it calls suidperl with      * the same argv that it had.  If suidperl finds that the script it has      * just opened is NOT setuid root, it sets the effective uid back to the      * uid.  We don't just make perl setuid root because that loses the      * effective uid we had before invoking perl, if it was different from the      * uid.      *      * DOSUID must be defined in both perl and suidperl, and IAMSUID must      * be defined in suidperl only.  suidperl must be setuid root.  The      * Configure script will set this up for you if you want it.      */
ifdef|#
directive|ifdef
name|DOSUID
argument|dTHR;     char *s
argument_list|,
argument|*s2;      if (PerlLIO_fstat(PerlIO_fileno(PL_rsfp),&PL_statbuf)<
literal|0
argument|)
comment|/* normal stat is insecure */
argument|croak(
literal|"Can't stat script \"%s\""
argument|,PL_origfilename);     if (fdscript<
literal|0
argument|&& PL_statbuf.st_mode& (S_ISUID|S_ISGID)) { 	I32 len; 	STRLEN n_a;
ifdef|#
directive|ifdef
name|IAMSUID
ifndef|#
directive|ifndef
name|HAS_SETREUID
comment|/* On this access check to make sure the directories are readable, 	 * there is actually a small window that the user could use to make 	 * filename point to an accessible directory.  So there is a faint 	 * chance that someone could execute a setuid script down in a 	 * non-accessible directory.  I don't know what to do about that. 	 * But I don't think it's too important.  The manual lies when 	 * it says access() is useful in setuid programs. 	 */
argument|if (PerlLIO_access(SvPVX(GvSV(PL_curcop->cop_filegv)),
literal|1
argument|))
comment|/*double check*/
argument|croak(
literal|"Permission denied"
argument|);
else|#
directive|else
comment|/* If we can swap euid and uid, then we can determine access rights 	 * with a simple stat of the file, and then compare device and 	 * inode to make sure we did stat() on the same file we opened. 	 * Then we just have to make sure he or she can execute it. 	 */
argument|{ 	    struct stat tmpstatbuf;  	    if (
ifdef|#
directive|ifdef
name|HAS_SETREUID
argument|setreuid(PL_euid,PL_uid)<
literal|0
else|#
directive|else
if|#
directive|if
name|HAS_SETRESUID
argument|setresuid(PL_euid,PL_uid,(Uid_t)-
literal|1
argument|)<
literal|0
endif|#
directive|endif
endif|#
directive|endif
argument||| PerlProc_getuid() != PL_euid || PerlProc_geteuid() != PL_uid) 		croak(
literal|"Can't swap uid and euid"
argument|);
comment|/* really paranoid */
argument|if (PerlLIO_stat(SvPVX(GvSV(PL_curcop->cop_filegv)),&tmpstatbuf)<
literal|0
argument|) 		croak(
literal|"Permission denied"
argument|);
comment|/* testing full pathname here */
if|#
directive|if
name|defined
argument_list|(
name|IAMSUID
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|NO_NOSUID_CHECK
argument_list|)
argument|if (fd_on_nosuid_fs(PerlIO_fileno(PL_rsfp))) 		croak(
literal|"Permission denied"
argument|);
endif|#
directive|endif
argument|if (tmpstatbuf.st_dev != PL_statbuf.st_dev || 		tmpstatbuf.st_ino != PL_statbuf.st_ino) { 		(void)PerlIO_close(PL_rsfp); 		if (PL_rsfp = PerlProc_popen(
literal|"/bin/mail root"
argument|,
literal|"w"
argument|)) {
comment|/* heh, heh */
argument|PerlIO_printf(PL_rsfp,
literal|"User %ld tried to run dev %ld ino %ld in place of dev %ld ino %ld!\n\ (Filename of set-id script was %s, uid %ld gid %ld.)\n\nSincerely,\nperl\n"
argument|, 			(long)PL_uid,(long)tmpstatbuf.st_dev, (long)tmpstatbuf.st_ino, 			(long)PL_statbuf.st_dev, (long)PL_statbuf.st_ino, 			SvPVX(GvSV(PL_curcop->cop_filegv)), 			(long)PL_statbuf.st_uid, (long)PL_statbuf.st_gid); 		    (void)PerlProc_pclose(PL_rsfp); 		} 		croak(
literal|"Permission denied\n"
argument|); 	    } 	    if (
ifdef|#
directive|ifdef
name|HAS_SETREUID
argument|setreuid(PL_uid,PL_euid)<
literal|0
else|#
directive|else
if|#
directive|if
name|defined
argument_list|(
name|HAS_SETRESUID
argument_list|)
argument|setresuid(PL_uid,PL_euid,(Uid_t)-
literal|1
argument|)<
literal|0
endif|#
directive|endif
endif|#
directive|endif
argument||| PerlProc_getuid() != PL_uid || PerlProc_geteuid() != PL_euid) 		croak(
literal|"Can't reswap uid and euid"
argument|); 	    if (!cando(S_IXUSR,FALSE,&PL_statbuf))
comment|/* can real uid exec? */
argument|croak(
literal|"Permission denied\n"
argument|); 	}
endif|#
directive|endif
comment|/* HAS_SETREUID */
endif|#
directive|endif
comment|/* IAMSUID */
argument|if (!S_ISREG(PL_statbuf.st_mode)) 	    croak(
literal|"Permission denied"
argument|); 	if (PL_statbuf.st_mode& S_IWOTH) 	    croak(
literal|"Setuid/gid script is writable by world"
argument|); 	PL_doswitches = FALSE;
comment|/* -s is insecure in suid */
argument|PL_curcop->cop_line++; 	if (sv_gets(PL_linestr, PL_rsfp,
literal|0
argument|) == Nullch || 	  strnNE(SvPV(PL_linestr,n_a),
literal|"#!"
argument|,
literal|2
argument|) )
comment|/* required even on Sys V */
argument|croak(
literal|"No #! line"
argument|); 	s = SvPV(PL_linestr,n_a)+
literal|2
argument|; 	if (*s ==
literal|' '
argument|) s++; 	while (!isSPACE(*s)) s++; 	for (s2 = s;  (s2> SvPV(PL_linestr,n_a)+
literal|2
argument|&& 		       (isDIGIT(s2[-
literal|1
argument|]) || strchr(
literal|"._-"
argument|, s2[-
literal|1
argument|])));  s2--) ; 	if (strnNE(s2-
literal|4
argument|,
literal|"perl"
argument|,
literal|4
argument|)&& strnNE(s-
literal|9
argument|,
literal|"perl"
argument|,
literal|4
argument|))
comment|/* sanity check */
argument|croak(
literal|"Not a perl script"
argument|); 	while (*s ==
literal|' '
argument||| *s ==
literal|'\t'
argument|) s++;
comment|/* 	 * #! arg must be what we saw above.  They can invoke it by 	 * mentioning suidperl explicitly, but they may not add any strange 	 * arguments beyond what #! says if they do invoke suidperl that way. 	 */
argument|len = strlen(validarg); 	if (strEQ(validarg,
literal|" PHOOEY "
argument|) || 	    strnNE(s,validarg,len) || !isSPACE(s[len])) 	    croak(
literal|"Args must match #! line"
argument|);
ifndef|#
directive|ifndef
name|IAMSUID
argument|if (PL_euid != PL_uid&& (PL_statbuf.st_mode& S_ISUID)&& 	    PL_euid == PL_statbuf.st_uid) 	    if (!PL_do_undump) 		croak(
literal|"YOU HAVEN'T DISABLED SET-ID SCRIPTS IN THE KERNEL YET!\n\ FIX YOUR KERNEL, PUT A C WRAPPER AROUND THIS SCRIPT, OR USE -u AND UNDUMP!\n"
argument|);
endif|#
directive|endif
comment|/* IAMSUID */
argument|if (PL_euid) {
comment|/* oops, we're not the setuid root perl */
argument|(void)PerlIO_close(PL_rsfp);
ifndef|#
directive|ifndef
name|IAMSUID
comment|/* try again */
argument|PerlProc_execv(form(
literal|"%s/sperl%s"
argument|, BIN_EXP, PL_patchlevel), PL_origargv);
endif|#
directive|endif
argument|croak(
literal|"Can't do setuid\n"
argument|); 	}  	if (PL_statbuf.st_mode& S_ISGID&& PL_statbuf.st_gid != PL_egid) {
ifdef|#
directive|ifdef
name|HAS_SETEGID
argument|(void)setegid(PL_statbuf.st_gid);
else|#
directive|else
ifdef|#
directive|ifdef
name|HAS_SETREGID
argument|(void)setregid((Gid_t)-
literal|1
argument|,PL_statbuf.st_gid);
else|#
directive|else
ifdef|#
directive|ifdef
name|HAS_SETRESGID
argument|(void)setresgid((Gid_t)-
literal|1
argument|,PL_statbuf.st_gid,(Gid_t)-
literal|1
argument|);
else|#
directive|else
argument|PerlProc_setgid(PL_statbuf.st_gid);
endif|#
directive|endif
endif|#
directive|endif
endif|#
directive|endif
argument|if (PerlProc_getegid() != PL_statbuf.st_gid) 		croak(
literal|"Can't do setegid!\n"
argument|); 	} 	if (PL_statbuf.st_mode& S_ISUID) { 	    if (PL_statbuf.st_uid != PL_euid)
ifdef|#
directive|ifdef
name|HAS_SETEUID
argument|(void)seteuid(PL_statbuf.st_uid);
comment|/* all that for this */
else|#
directive|else
ifdef|#
directive|ifdef
name|HAS_SETREUID
argument|(void)setreuid((Uid_t)-
literal|1
argument|,PL_statbuf.st_uid);
else|#
directive|else
ifdef|#
directive|ifdef
name|HAS_SETRESUID
argument|(void)setresuid((Uid_t)-
literal|1
argument|,PL_statbuf.st_uid,(Uid_t)-
literal|1
argument|);
else|#
directive|else
argument|PerlProc_setuid(PL_statbuf.st_uid);
endif|#
directive|endif
endif|#
directive|endif
endif|#
directive|endif
argument|if (PerlProc_geteuid() != PL_statbuf.st_uid) 		croak(
literal|"Can't do seteuid!\n"
argument|); 	} 	else if (PL_uid) {
comment|/* oops, mustn't run as root */
ifdef|#
directive|ifdef
name|HAS_SETEUID
argument|(void)seteuid((Uid_t)PL_uid);
else|#
directive|else
ifdef|#
directive|ifdef
name|HAS_SETREUID
argument|(void)setreuid((Uid_t)-
literal|1
argument|,(Uid_t)PL_uid);
else|#
directive|else
ifdef|#
directive|ifdef
name|HAS_SETRESUID
argument|(void)setresuid((Uid_t)-
literal|1
argument|,(Uid_t)PL_uid,(Uid_t)-
literal|1
argument|);
else|#
directive|else
argument|PerlProc_setuid((Uid_t)PL_uid);
endif|#
directive|endif
endif|#
directive|endif
endif|#
directive|endif
argument|if (PerlProc_geteuid() != PL_uid) 		croak(
literal|"Can't do seteuid!\n"
argument|); 	} 	init_ids(); 	if (!cando(S_IXUSR,TRUE,&PL_statbuf)) 	    croak(
literal|"Permission denied\n"
argument|);
comment|/* they can't do this */
argument|}
ifdef|#
directive|ifdef
name|IAMSUID
argument|else if (PL_preprocess) 	croak(
literal|"-P not allowed for setuid/setgid script\n"
argument|);     else if (fdscript>=
literal|0
argument|) 	croak(
literal|"fd script not allowed in suidperl\n"
argument|);     else 	croak(
literal|"Script is not setuid/setgid in suidperl\n"
argument|);
comment|/* We absolutely must clear out any saved ids here, so we */
comment|/* exec the real perl, substituting fd script for scriptname. */
comment|/* (We pass script name as "subdir" of fd, which perl will grok.) */
argument|PerlIO_rewind(PL_rsfp);     PerlLIO_lseek(PerlIO_fileno(PL_rsfp),(Off_t)
literal|0
argument|,
literal|0
argument|);
comment|/* just in case rewind didn't */
argument|for (which =
literal|1
argument|; PL_origargv[which]&& PL_origargv[which] != scriptname; which++) ;     if (!PL_origargv[which]) 	croak(
literal|"Permission denied"
argument|);     PL_origargv[which] = savepv(form(
literal|"/dev/fd/%d/%s"
argument|, 				  PerlIO_fileno(PL_rsfp), PL_origargv[which]));
if|#
directive|if
name|defined
argument_list|(
name|HAS_FCNTL
argument_list|)
operator|&&
name|defined
argument_list|(
name|F_SETFD
argument_list|)
argument|fcntl(PerlIO_fileno(PL_rsfp),F_SETFD,
literal|0
argument|);
comment|/* ensure no close-on-exec */
endif|#
directive|endif
argument|PerlProc_execv(form(
literal|"%s/perl%s"
argument|, BIN_EXP, PL_patchlevel), PL_origargv);
comment|/* try again */
argument|croak(
literal|"Can't do setuid\n"
argument|);
endif|#
directive|endif
comment|/* IAMSUID */
else|#
directive|else
comment|/* !DOSUID */
argument|if (PL_euid != PL_uid || PL_egid != PL_gid) {
comment|/* (suidperl doesn't exist, in fact) */
ifndef|#
directive|ifndef
name|SETUID_SCRIPTS_ARE_SECURE_NOW
argument|dTHR; 	PerlLIO_fstat(PerlIO_fileno(PL_rsfp),&PL_statbuf);
comment|/* may be either wrapped or real suid */
argument|if ((PL_euid != PL_uid&& PL_euid == PL_statbuf.st_uid&& PL_statbuf.st_mode& S_ISUID) 	    || 	    (PL_egid != PL_gid&& PL_egid == PL_statbuf.st_gid&& PL_statbuf.st_mode& S_ISGID) 	   ) 	    if (!PL_do_undump) 		croak(
literal|"YOU HAVEN'T DISABLED SET-ID SCRIPTS IN THE KERNEL YET!\n\ FIX YOUR KERNEL, PUT A C WRAPPER AROUND THIS SCRIPT, OR USE -u AND UNDUMP!\n"
argument|);
endif|#
directive|endif
comment|/* SETUID_SCRIPTS_ARE_SECURE_NOW */
comment|/* not set-id, must be wrapped */
argument|}
endif|#
directive|endif
comment|/* DOSUID */
argument|}  STATIC void find_beginning(void) {     register char *s
argument_list|,
argument|*s2;
comment|/* skip forward in input to the real script? */
argument|forbid_setid(
literal|"-x"
argument|);     while (PL_doextract) { 	if ((s = sv_gets(PL_linestr, PL_rsfp,
literal|0
argument|)) == Nullch) 	    croak(
literal|"No Perl script found in input\n"
argument|); 	if (*s ==
literal|'#'
argument|&& s[
literal|1
argument|] ==
literal|'!'
argument|&& (s = instr(s,
literal|"perl"
argument|))) { 	    PerlIO_ungetc(PL_rsfp,
literal|'\n'
argument|);
comment|/* to keep line count right */
argument|PL_doextract = FALSE; 	    while (*s&& !(isSPACE (*s) || *s ==
literal|'#'
argument|)) s++; 	    s2 = s; 	    while (*s ==
literal|' '
argument||| *s ==
literal|'\t'
argument|) s++; 	    if (*s++ ==
literal|'-'
argument|) { 		while (isDIGIT(s2[-
literal|1
argument|]) || strchr(
literal|"-._"
argument|, s2[-
literal|1
argument|])) s2--; 		if (strnEQ(s2-
literal|4
argument|,
literal|"perl"
argument|,
literal|4
argument|))
comment|/*SUPPRESS 530*/
argument|while (s = moreswitches(s)) ; 	    } 	    if (PL_cddir&& PerlDir_chdir(PL_cddir)<
literal|0
argument|) 		croak(
literal|"Can't chdir to %s"
argument|,PL_cddir); 	}     } }   STATIC void init_ids(void) {     PL_uid = (int)PerlProc_getuid();     PL_euid = (int)PerlProc_geteuid();     PL_gid = (int)PerlProc_getgid();     PL_egid = (int)PerlProc_getegid();
ifdef|#
directive|ifdef
name|VMS
argument|PL_uid |= PL_gid<<
literal|16
argument|;     PL_euid |= PL_egid<<
literal|16
argument|;
endif|#
directive|endif
argument|PL_tainting |= (PL_uid&& (PL_euid != PL_uid || PL_egid != PL_gid)); }  STATIC void forbid_setid(char *s) {     if (PL_euid != PL_uid)         croak(
literal|"No %s allowed while running setuid"
argument|, s);     if (PL_egid != PL_gid)         croak(
literal|"No %s allowed while running setgid"
argument|, s); }  STATIC void init_debugger(void) {     dTHR;     PL_curstash = PL_debstash;     PL_dbargs = GvAV(gv_AVadd((gv_fetchpv(
literal|"args"
argument|, GV_ADDMULTI, SVt_PVAV))));     AvREAL_off(PL_dbargs);     PL_DBgv = gv_fetchpv(
literal|"DB"
argument|, GV_ADDMULTI, SVt_PVGV);     PL_DBline = gv_fetchpv(
literal|"dbline"
argument|, GV_ADDMULTI, SVt_PVAV);     PL_DBsub = gv_HVadd(gv_fetchpv(
literal|"sub"
argument|, GV_ADDMULTI, SVt_PVHV));     PL_DBsingle = GvSV((gv_fetchpv(
literal|"single"
argument|, GV_ADDMULTI, SVt_PV)));     sv_setiv(PL_DBsingle,
literal|0
argument|);      PL_DBtrace = GvSV((gv_fetchpv(
literal|"trace"
argument|, GV_ADDMULTI, SVt_PV)));     sv_setiv(PL_DBtrace,
literal|0
argument|);      PL_DBsignal = GvSV((gv_fetchpv(
literal|"signal"
argument|, GV_ADDMULTI, SVt_PV)));     sv_setiv(PL_DBsignal,
literal|0
argument|);      PL_curstash = PL_defstash; }
ifndef|#
directive|ifndef
name|STRESS_REALLOC
define|#
directive|define
name|REASONABLE
parameter_list|(
name|size
parameter_list|)
value|(size)
else|#
directive|else
define|#
directive|define
name|REASONABLE
parameter_list|(
name|size
parameter_list|)
value|(1)
comment|/* unreasonable */
endif|#
directive|endif
argument|void init_stacks(ARGSproto) {
comment|/* start with 128-item stack and 8K cxstack */
argument|PL_curstackinfo = new_stackinfo(REASONABLE(
literal|128
argument|), 				 REASONABLE(
literal|8192
argument|/sizeof(PERL_CONTEXT) -
literal|1
argument|));     PL_curstackinfo->si_type = PERLSI_MAIN;     PL_curstack = PL_curstackinfo->si_stack;     PL_mainstack = PL_curstack;
comment|/* remember in case we switch stacks */
argument|PL_stack_base = AvARRAY(PL_curstack);     PL_stack_sp = PL_stack_base;     PL_stack_max = PL_stack_base + AvMAX(PL_curstack);      New(
literal|50
argument|,PL_tmps_stack,REASONABLE(
literal|128
argument|),SV*);     PL_tmps_floor = -
literal|1
argument|;     PL_tmps_ix = -
literal|1
argument|;     PL_tmps_max = REASONABLE(
literal|128
argument|);      New(
literal|54
argument|,PL_markstack,REASONABLE(
literal|32
argument|),I32);     PL_markstack_ptr = PL_markstack;     PL_markstack_max = PL_markstack + REASONABLE(
literal|32
argument|);      SET_MARKBASE;      New(
literal|54
argument|,PL_scopestack,REASONABLE(
literal|32
argument|),I32);     PL_scopestack_ix =
literal|0
argument|;     PL_scopestack_max = REASONABLE(
literal|32
argument|);      New(
literal|54
argument|,PL_savestack,REASONABLE(
literal|128
argument|),ANY);     PL_savestack_ix =
literal|0
argument|;     PL_savestack_max = REASONABLE(
literal|128
argument|);      New(
literal|54
argument|,PL_retstack,REASONABLE(
literal|16
argument|),OP*);     PL_retstack_ix =
literal|0
argument|;     PL_retstack_max = REASONABLE(
literal|16
argument|); }
undef|#
directive|undef
name|REASONABLE
argument|STATIC void nuke_stacks(void) {     dTHR;     while (PL_curstackinfo->si_next) 	PL_curstackinfo = PL_curstackinfo->si_next;     while (PL_curstackinfo) { 	PERL_SI *p = PL_curstackinfo->si_prev;
comment|/* curstackinfo->si_stack got nuked by sv_free_arenas() */
argument|Safefree(PL_curstackinfo->si_cxstack); 	Safefree(PL_curstackinfo); 	PL_curstackinfo = p;     }     Safefree(PL_tmps_stack);     Safefree(PL_markstack);     Safefree(PL_scopestack);     Safefree(PL_savestack);     Safefree(PL_retstack);     DEBUG( { 	Safefree(PL_debname); 	Safefree(PL_debdelim);     } ) }
ifndef|#
directive|ifndef
name|PERL_OBJECT
argument|static PerlIO *tmpfp;
comment|/* moved outside init_lexer() because of UNICOS bug */
endif|#
directive|endif
argument|STATIC void init_lexer(void) {
ifdef|#
directive|ifdef
name|PERL_OBJECT
argument|PerlIO *tmpfp;
endif|#
directive|endif
argument|tmpfp = PL_rsfp;     PL_rsfp = Nullfp;     lex_start(PL_linestr);     PL_rsfp = tmpfp;     PL_subname = newSVpv(
literal|"main"
argument|,
literal|4
argument|); }  STATIC void init_predump_symbols(void) {     dTHR;     GV *tmpgv;     GV *othergv;      sv_setpvn(perl_get_sv(
literal|"\""
argument|, TRUE),
literal|" "
argument|,
literal|1
argument|);     PL_stdingv = gv_fetchpv(
literal|"STDIN"
argument|,TRUE, SVt_PVIO);     GvMULTI_on(PL_stdingv);     IoIFP(GvIOp(PL_stdingv)) = PerlIO_stdin();     tmpgv = gv_fetchpv(
literal|"stdin"
argument|,TRUE, SVt_PV);     GvMULTI_on(tmpgv);     GvIOp(tmpgv) = (IO*)SvREFCNT_inc(GvIOp(PL_stdingv));      tmpgv = gv_fetchpv(
literal|"STDOUT"
argument|,TRUE, SVt_PVIO);     GvMULTI_on(tmpgv);     IoOFP(GvIOp(tmpgv)) = IoIFP(GvIOp(tmpgv)) = PerlIO_stdout();     setdefout(tmpgv);     tmpgv = gv_fetchpv(
literal|"stdout"
argument|,TRUE, SVt_PV);     GvMULTI_on(tmpgv);     GvIOp(tmpgv) = (IO*)SvREFCNT_inc(GvIOp(PL_defoutgv));      othergv = gv_fetchpv(
literal|"STDERR"
argument|,TRUE, SVt_PVIO);     GvMULTI_on(othergv);     IoOFP(GvIOp(othergv)) = IoIFP(GvIOp(othergv)) = PerlIO_stderr();     tmpgv = gv_fetchpv(
literal|"stderr"
argument|,TRUE, SVt_PV);     GvMULTI_on(tmpgv);     GvIOp(tmpgv) = (IO*)SvREFCNT_inc(GvIOp(othergv));      PL_statname = NEWSV(
literal|66
argument|,
literal|0
argument|);
comment|/* last filename we did stat on */
argument|if (!PL_osname) 	PL_osname = savepv(OSNAME); }  STATIC void init_postdump_symbols(register int argc, register char **argv, register char **env) {     dTHR;     char *s;     SV *sv;     GV* tmpgv;      argc--
argument_list|,
argument|argv++;
comment|/* skip name of script */
argument|if (PL_doswitches) { 	for (; argc>
literal|0
argument|&& **argv ==
literal|'-'
argument|; argc--,argv++) { 	    if (!argv[
literal|0
argument|][
literal|1
argument|]) 		break; 	    if (argv[
literal|0
argument|][
literal|1
argument|] ==
literal|'-'
argument|) { 		argc--
argument_list|,
argument|argv++; 		break; 	    } 	    if (s = strchr(argv[
literal|0
argument|],
literal|'='
argument|)) { 		*s++ =
literal|'\0'
argument|; 		sv_setpv(GvSV(gv_fetchpv(argv[
literal|0
argument|]+
literal|1
argument|,TRUE, SVt_PV)),s); 	    } 	    else 		sv_setiv(GvSV(gv_fetchpv(argv[
literal|0
argument|]+
literal|1
argument|,TRUE, SVt_PV)),
literal|1
argument|); 	}     }     PL_toptarget = NEWSV(
literal|0
argument|,
literal|0
argument|);     sv_upgrade(PL_toptarget, SVt_PVFM);     sv_setpvn(PL_toptarget,
literal|""
argument|,
literal|0
argument|);     PL_bodytarget = NEWSV(
literal|0
argument|,
literal|0
argument|);     sv_upgrade(PL_bodytarget, SVt_PVFM);     sv_setpvn(PL_bodytarget,
literal|""
argument|,
literal|0
argument|);     PL_formtarget = PL_bodytarget;      TAINT;     if (tmpgv = gv_fetchpv(
literal|"0"
argument|,TRUE, SVt_PV)) { 	sv_setpv(GvSV(tmpgv),PL_origfilename); 	magicname(
literal|"0"
argument|,
literal|"0"
argument|,
literal|1
argument|);     }     if (tmpgv = gv_fetchpv(
literal|"\030"
argument|,TRUE, SVt_PV)) 	sv_setpv(GvSV(tmpgv),PL_origargv[
literal|0
argument|]);     if (PL_argvgv = gv_fetchpv(
literal|"ARGV"
argument|,TRUE, SVt_PVAV)) { 	GvMULTI_on(PL_argvgv); 	(void)gv_AVadd(PL_argvgv); 	av_clear(GvAVn(PL_argvgv)); 	for (; argc>
literal|0
argument|; argc--,argv++) { 	    av_push(GvAVn(PL_argvgv),newSVpv(argv[
literal|0
argument|],
literal|0
argument|)); 	}     }     if (PL_envgv = gv_fetchpv(
literal|"ENV"
argument|,TRUE, SVt_PVHV)) { 	HV *hv; 	GvMULTI_on(PL_envgv); 	hv = GvHVn(PL_envgv); 	hv_magic(hv, PL_envgv,
literal|'E'
argument|);
ifndef|#
directive|ifndef
name|VMS
comment|/* VMS doesn't have environ array */
comment|/* Note that if the supplied env parameter is actually a copy 	   of the global environ then it may now point to free'd memory 	   if the environment has been modified since. To avoid this 	   problem we treat env==NULL as meaning 'use the default' 	*/
argument|if (!env) 	    env = environ; 	if (env != environ) 	    environ[
literal|0
argument|] = Nullch; 	for (; *env; env++) { 	    if (!(s = strchr(*env,
literal|'='
argument|))) 		continue; 	    *s++ =
literal|'\0'
argument|;
if|#
directive|if
name|defined
argument_list|(
name|MSDOS
argument_list|)
argument|(void)strupr(*env);
endif|#
directive|endif
argument|sv = newSVpv(s--,
literal|0
argument|); 	    (void)hv_store(hv, *env, s - *env, sv,
literal|0
argument|); 	    *s =
literal|'='
argument|;
if|#
directive|if
name|defined
argument_list|(
name|__BORLANDC__
argument_list|)
operator|&&
name|defined
argument_list|(
name|USE_WIN32_RTL_ENV
argument_list|)
comment|/* Sins of the RTL. See note in my_setenv(). */
argument|(void)PerlEnv_putenv(savepv(*env));
endif|#
directive|endif
argument|}
endif|#
directive|endif
ifdef|#
directive|ifdef
name|DYNAMIC_ENV_FETCH
argument|HvNAME(hv) = savepv(ENV_HV_NAME);
endif|#
directive|endif
argument|}     TAINT_NOT;     if (tmpgv = gv_fetchpv(
literal|"$"
argument|,TRUE, SVt_PV)) 	sv_setiv(GvSV(tmpgv), (IV)getpid()); }  STATIC void init_perllib(void) {     char *s;     if (!PL_tainting) {
ifndef|#
directive|ifndef
name|VMS
argument|s = PerlEnv_getenv(
literal|"PERL5LIB"
argument|); 	if (s) 	    incpush(s, TRUE); 	else 	    incpush(PerlEnv_getenv(
literal|"PERLLIB"
argument|), FALSE);
else|#
directive|else
comment|/* VMS */
comment|/* Treat PERL5?LIB as a possible search list logical name -- the 	 * "natural" VMS idiom for a Unix path string.  We allow each 	 * element to be a set of |-separated directories for compatibility. 	 */
argument|char buf[
literal|256
argument|]; 	int idx =
literal|0
argument|; 	if (my_trnlnm(
literal|"PERL5LIB"
argument|,buf,
literal|0
argument|)) 	    do { incpush(buf,TRUE); } while (my_trnlnm(
literal|"PERL5LIB"
argument|,buf,++idx)); 	else 	    while (my_trnlnm(
literal|"PERLLIB"
argument|,buf,idx++)) incpush(buf,FALSE);
endif|#
directive|endif
comment|/* VMS */
argument|}
comment|/* Use the ~-expanded versions of APPLLIB (undocumented),     ARCHLIB PRIVLIB SITEARCH and SITELIB  */
ifdef|#
directive|ifdef
name|APPLLIB_EXP
argument|incpush(APPLLIB_EXP, TRUE);
endif|#
directive|endif
ifdef|#
directive|ifdef
name|ARCHLIB_EXP
argument|incpush(ARCHLIB_EXP, FALSE);
endif|#
directive|endif
ifndef|#
directive|ifndef
name|PRIVLIB_EXP
define|#
directive|define
name|PRIVLIB_EXP
value|"/usr/local/lib/perl5:/usr/local/lib/perl"
endif|#
directive|endif
if|#
directive|if
name|defined
argument_list|(
name|WIN32
argument_list|)
argument|incpush(PRIVLIB_EXP, TRUE);
else|#
directive|else
argument|incpush(PRIVLIB_EXP, FALSE);
endif|#
directive|endif
ifdef|#
directive|ifdef
name|SITEARCH_EXP
argument|incpush(SITEARCH_EXP, FALSE);
endif|#
directive|endif
ifdef|#
directive|ifdef
name|SITELIB_EXP
if|#
directive|if
name|defined
argument_list|(
name|WIN32
argument_list|)
argument|incpush(SITELIB_EXP, TRUE);
else|#
directive|else
argument|incpush(SITELIB_EXP, FALSE);
endif|#
directive|endif
endif|#
directive|endif
argument|if (!PL_tainting) 	incpush(
literal|"."
argument|, FALSE); }
if|#
directive|if
name|defined
argument_list|(
name|DOSISH
argument_list|)
define|#
directive|define
name|PERLLIB_SEP
value|';'
else|#
directive|else
if|#
directive|if
name|defined
argument_list|(
name|VMS
argument_list|)
define|#
directive|define
name|PERLLIB_SEP
value|'|'
else|#
directive|else
define|#
directive|define
name|PERLLIB_SEP
value|':'
endif|#
directive|endif
endif|#
directive|endif
ifndef|#
directive|ifndef
name|PERLLIB_MANGLE
define|#
directive|define
name|PERLLIB_MANGLE
parameter_list|(
name|s
parameter_list|,
name|n
parameter_list|)
value|(s)
endif|#
directive|endif
argument|STATIC void incpush(char *p, int addsubdirs) {     SV *subdir = Nullsv;      if (!p) 	return;      if (addsubdirs) { 	subdir = sv_newmortal(); 	if (!PL_archpat_auto) { 	    STRLEN len = (sizeof(ARCHNAME) + strlen(PL_patchlevel) 			  + sizeof(
literal|"//auto"
argument|)); 	    New(
literal|55
argument|, PL_archpat_auto, len, char); 	    sprintf(PL_archpat_auto,
literal|"/%s/%s/auto"
argument|, ARCHNAME, PL_patchlevel);
ifdef|#
directive|ifdef
name|VMS
argument|for (len = sizeof(ARCHNAME) +
literal|2
argument|; 	     PL_archpat_auto[len] !=
literal|'\0'
argument|&& PL_archpat_auto[len] !=
literal|'/'
argument|; len++) 		if (PL_archpat_auto[len] ==
literal|'.'
argument|) PL_archpat_auto[len] =
literal|'_'
argument|;
endif|#
directive|endif
argument|}     }
comment|/* Break at all separators */
argument|while (p&& *p) { 	SV *libdir = NEWSV(
literal|55
argument|,
literal|0
argument|); 	char *s;
comment|/* skip any consecutive separators */
argument|while ( *p == PERLLIB_SEP ) {
comment|/* Uncomment the next line for PATH semantics */
comment|/* av_push(GvAVn(PL_incgv), newSVpv(".", 1)); */
argument|p++; 	}  	if ( (s = strchr(p, PERLLIB_SEP)) != Nullch ) { 	    sv_setpvn(libdir, PERLLIB_MANGLE(p, (STRLEN)(s - p)), 		      (STRLEN)(s - p)); 	    p = s +
literal|1
argument|; 	} 	else { 	    sv_setpv(libdir, PERLLIB_MANGLE(p,
literal|0
argument|)); 	    p = Nullch;
comment|/* break out */
argument|}
comment|/* 	 * BEFORE pushing libdir onto @INC we may first push version- and 	 * archname-specific sub-directories. 	 */
argument|if (addsubdirs) { 	    struct stat tmpstatbuf;
ifdef|#
directive|ifdef
name|VMS
argument|char *unix; 	    STRLEN len;  	    if ((unix = tounixspec_ts(SvPV(libdir,len),Nullch)) != Nullch) { 		len = strlen(unix); 		while (unix[len-
literal|1
argument|] ==
literal|'/'
argument|) len--;
comment|/* Cosmetic */
argument|sv_usepvn(libdir,unix,len); 	    } 	    else 		PerlIO_printf(PerlIO_stderr(),
literal|"Failed to unixify @INC element \"%s\"\n"
argument|, 			      SvPV(libdir,len));
endif|#
directive|endif
comment|/* .../archname/version if -d .../archname/version/auto */
argument|sv_setsv(subdir, libdir); 	    sv_catpv(subdir, PL_archpat_auto); 	    if (PerlLIO_stat(SvPVX(subdir),&tmpstatbuf)>=
literal|0
argument|&& 		  S_ISDIR(tmpstatbuf.st_mode)) 		av_push(GvAVn(PL_incgv), 			newSVpv(SvPVX(subdir), SvCUR(subdir) - sizeof
literal|"auto"
argument|));
comment|/* .../archname if -d .../archname/auto */
argument|sv_insert(subdir, SvCUR(libdir) + sizeof(ARCHNAME), 		      strlen(PL_patchlevel) +
literal|1
argument|,
literal|""
argument|,
literal|0
argument|); 	    if (PerlLIO_stat(SvPVX(subdir),&tmpstatbuf)>=
literal|0
argument|&& 		  S_ISDIR(tmpstatbuf.st_mode)) 		av_push(GvAVn(PL_incgv), 			newSVpv(SvPVX(subdir), SvCUR(subdir) - sizeof
literal|"auto"
argument|)); 	}
comment|/* finally push this lib directory on the end of @INC */
argument|av_push(GvAVn(PL_incgv), libdir);     } }
ifdef|#
directive|ifdef
name|USE_THREADS
argument|STATIC struct perl_thread * init_main_thread() {     struct perl_thread *thr;     XPV *xpv;      Newz(
literal|53
argument|, thr,
literal|1
argument|, struct perl_thread);     PL_curcop =&PL_compiling;     thr->cvcache = newHV();     thr->threadsv = newAV();
comment|/* thr->threadsvp is set when find_threadsv is called */
argument|thr->specific = newAV();     thr->errhv = newHV();     thr->flags = THRf_R_JOINABLE;     MUTEX_INIT(&thr->mutex);
comment|/* Handcraft thrsv similarly to mess_sv */
argument|New(
literal|53
argument|, PL_thrsv,
literal|1
argument|, SV);     Newz(
literal|53
argument|, xpv,
literal|1
argument|, XPV);     SvFLAGS(PL_thrsv) = SVt_PV;     SvANY(PL_thrsv) = (void*)xpv;     SvREFCNT(PL_thrsv) =
literal|1
argument|<<
literal|30
argument|;
comment|/* practically infinite */
argument|SvPVX(PL_thrsv) = (char*)thr;     SvCUR_set(PL_thrsv, sizeof(thr));     SvLEN_set(PL_thrsv, sizeof(thr));     *SvEND(PL_thrsv) =
literal|'\0'
argument|;
comment|/* in the trailing_nul field */
argument|thr->oursv = PL_thrsv;     PL_chopset =
literal|" \n-"
argument|;      MUTEX_LOCK(&PL_threads_mutex);     PL_nthreads++;     thr->tid =
literal|0
argument|;     thr->next = thr;     thr->prev = thr;     MUTEX_UNLOCK(&PL_threads_mutex);
ifdef|#
directive|ifdef
name|HAVE_THREAD_INTERN
argument|init_thread_intern(thr);
endif|#
directive|endif
ifdef|#
directive|ifdef
name|SET_THREAD_SELF
argument|SET_THREAD_SELF(thr);
else|#
directive|else
argument|thr->self = pthread_self();
endif|#
directive|endif
comment|/* SET_THREAD_SELF */
argument|SET_THR(thr);
comment|/*      * These must come after the SET_THR because sv_setpvn does      * SvTAINT and the taint fields require dTHR.      */
argument|PL_toptarget = NEWSV(
literal|0
argument|,
literal|0
argument|);     sv_upgrade(PL_toptarget, SVt_PVFM);     sv_setpvn(PL_toptarget,
literal|""
argument|,
literal|0
argument|);     PL_bodytarget = NEWSV(
literal|0
argument|,
literal|0
argument|);     sv_upgrade(PL_bodytarget, SVt_PVFM);     sv_setpvn(PL_bodytarget,
literal|""
argument|,
literal|0
argument|);     PL_formtarget = PL_bodytarget;     thr->errsv = newSVpv(
literal|""
argument|,
literal|0
argument|);     (void) find_threadsv(
literal|"@"
argument|);
comment|/* Ensure $@ is initialised early */
argument|PL_maxscream = -
literal|1
argument|;     PL_regcompp = FUNC_NAME_TO_PTR(pregcomp);     PL_regexecp = FUNC_NAME_TO_PTR(regexec_flags);     PL_regindent =
literal|0
argument|;     PL_reginterp_cnt =
literal|0
argument|;      return thr; }
endif|#
directive|endif
comment|/* USE_THREADS */
argument|void call_list(I32 oldscope, AV *paramList) {     dTHR;     line_t oldline = PL_curcop->cop_line;     STRLEN len;     dJMPENV;     int ret;      while (AvFILL(paramList)>=
literal|0
argument|) { 	CV *cv = (CV*)av_shift(paramList);  	SAVEFREESV(cv);  	JMPENV_PUSH(ret); 	switch (ret) { 	case
literal|0
argument|: { 		SV* atsv = ERRSV; 		PUSHMARK(PL_stack_sp); 		perl_call_sv((SV*)cv, G_EVAL|G_DISCARD); 		(void)SvPV(atsv, len); 		if (len) { 		    JMPENV_POP; 		    PL_curcop =&PL_compiling; 		    PL_curcop->cop_line = oldline; 		    if (paramList == PL_beginav) 			sv_catpv(atsv,
literal|"BEGIN failed--compilation aborted"
argument|); 		    else 			sv_catpv(atsv,
literal|"END failed--cleanup aborted"
argument|); 		    while (PL_scopestack_ix> oldscope) 			LEAVE; 		    croak(
literal|"%s"
argument|, SvPVX(atsv)); 		} 	    } 	    break; 	case
literal|1
argument|: 	    STATUS_ALL_FAILURE;
comment|/* FALL THROUGH */
argument|case
literal|2
argument|:
comment|/* my_exit() was called */
argument|while (PL_scopestack_ix> oldscope) 		LEAVE; 	    FREETMPS; 	    PL_curstash = PL_defstash; 	    if (PL_endav) 		call_list(oldscope, PL_endav); 	    JMPENV_POP; 	    PL_curcop =&PL_compiling; 	    PL_curcop->cop_line = oldline; 	    if (PL_statusvalue) { 		if (paramList == PL_beginav) 		    croak(
literal|"BEGIN failed--compilation aborted"
argument|); 		else 		    croak(
literal|"END failed--cleanup aborted"
argument|); 	    } 	    my_exit_jump();
comment|/* NOTREACHED */
argument|case
literal|3
argument|: 	    if (!PL_restartop) { 		PerlIO_printf(PerlIO_stderr(),
literal|"panic: restartop\n"
argument|); 		FREETMPS; 		break; 	    } 	    JMPENV_POP; 	    PL_curcop =&PL_compiling; 	    PL_curcop->cop_line = oldline; 	    JMPENV_JUMP(
literal|3
argument|); 	} 	JMPENV_POP;     } }  void my_exit(U32 status) {     dTHR;      DEBUG_S(PerlIO_printf(Perl_debug_log,
literal|"my_exit: thread %p, status %lu\n"
argument|, 			  thr, (unsigned long) status));     switch (status) {     case
literal|0
argument|: 	STATUS_ALL_SUCCESS; 	break;     case
literal|1
argument|: 	STATUS_ALL_FAILURE; 	break;     default: 	STATUS_NATIVE_SET(status); 	break;     }     my_exit_jump(); }  void my_failure_exit(void) {
ifdef|#
directive|ifdef
name|VMS
argument|if (vaxc$errno&
literal|1
argument|) { 	if (STATUS_NATIVE&
literal|1
argument|)
comment|/* fortuitiously includes "-1" */
argument|STATUS_NATIVE_SET(
literal|44
argument|);     }     else { 	if (!vaxc$errno&& errno)
comment|/* unlikely */
argument|STATUS_NATIVE_SET(
literal|44
argument|); 	else 	    STATUS_NATIVE_SET(vaxc$errno);     }
else|#
directive|else
argument|int exitstatus;     if (errno&
literal|255
argument|) 	STATUS_POSIX_SET(errno);     else { 	exitstatus = STATUS_POSIX>>
literal|8
argument|;  	if (exitstatus&
literal|255
argument|) 	    STATUS_POSIX_SET(exitstatus); 	else 	    STATUS_POSIX_SET(
literal|255
argument|);     }
endif|#
directive|endif
argument|my_exit_jump(); }  STATIC void my_exit_jump(void) {     dSP;     register PERL_CONTEXT *cx;     I32 gimme;     SV **newsp;      if (PL_e_script) { 	SvREFCNT_dec(PL_e_script); 	PL_e_script = Nullsv;     }      POPSTACK_TO(PL_mainstack);     if (cxstack_ix>=
literal|0
argument|) { 	if (cxstack_ix>
literal|0
argument|) 	    dounwind(
literal|0
argument|); 	POPBLOCK(cx,PL_curpm); 	LEAVE;     }      JMPENV_JUMP(
literal|2
argument|); }
ifdef|#
directive|ifdef
name|PERL_OBJECT
define|#
directive|define
name|NO_XSLOCKS
endif|#
directive|endif
comment|/* PERL_OBJECT */
include|#
directive|include
file|"XSUB.h"
argument|static I32
ifdef|#
directive|ifdef
name|PERL_OBJECT
argument|read_e_script(CPerlObj *pPerl, int idx, SV *buf_sv, int maxlen)
else|#
directive|else
argument|read_e_script(int idx, SV *buf_sv, int maxlen)
endif|#
directive|endif
argument|{     char *p
argument_list|,
argument|*nl;     p  = SvPVX(PL_e_script);     nl = strchr(p,
literal|'\n'
argument|);     nl = (nl) ? nl+
literal|1
argument|: SvEND(PL_e_script);     if (nl-p ==
literal|0
argument|) { 	filter_del(read_e_script); 	return
literal|0
argument|;     }     sv_catpvn(buf_sv, p, nl-p);     sv_chop(PL_e_script, nl);     return
literal|1
argument|; }
end_function

end_unit

