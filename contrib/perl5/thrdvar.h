begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/***********************************************/
end_comment

begin_comment
comment|/* Global only to current thread               */
end_comment

begin_comment
comment|/***********************************************/
end_comment

begin_comment
comment|/* Don't forget to re-run embed.pl to propagate changes! */
end_comment

begin_comment
comment|/* The 'T' prefix is only needed for vars that need appropriate #defines  * generated when built with or without USE_THREADS.  It is also used  * to generate the appropriate export list for win32.  *  * When building without USE_THREADS, these variables will be truly global.  * When building without USE_THREADS but with MULTIPLICITY, these variables  * will be global per-interpreter.  *  * Avoid build-specific #ifdefs here, like DEBUGGING.  That way,  * we can keep binary compatibility of the curinterp structure */
end_comment

begin_comment
comment|/* Important ones in the first cache line (if alignment is done right) */
end_comment

begin_macro
name|PERLVAR
argument_list|(
argument|Tstack_sp
argument_list|,
argument|SV **
argument_list|)
end_macro

begin_comment
comment|/* top of the stack */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|OP_IN_REGISTER
end_ifdef

begin_macro
name|PERLVAR
argument_list|(
argument|Topsave
argument_list|,
argument|OP *
argument_list|)
end_macro

begin_else
else|#
directive|else
end_else

begin_macro
name|PERLVAR
argument_list|(
argument|Top
argument_list|,
argument|OP *
argument_list|)
end_macro

begin_comment
comment|/* currently executing op */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_macro
name|PERLVAR
argument_list|(
argument|Tcurpad
argument_list|,
argument|SV **
argument_list|)
end_macro

begin_comment
comment|/* active pad (lexicals+tmps) */
end_comment

begin_macro
name|PERLVAR
argument_list|(
argument|Tstack_base
argument_list|,
argument|SV **
argument_list|)
end_macro

begin_macro
name|PERLVAR
argument_list|(
argument|Tstack_max
argument_list|,
argument|SV **
argument_list|)
end_macro

begin_macro
name|PERLVAR
argument_list|(
argument|Tscopestack
argument_list|,
argument|I32 *
argument_list|)
end_macro

begin_comment
comment|/* scopes we've ENTERed */
end_comment

begin_macro
name|PERLVAR
argument_list|(
argument|Tscopestack_ix
argument_list|,
argument|I32
argument_list|)
end_macro

begin_macro
name|PERLVAR
argument_list|(
argument|Tscopestack_max
argument_list|,
argument|I32
argument_list|)
end_macro

begin_macro
name|PERLVAR
argument_list|(
argument|Tsavestack
argument_list|,
argument|ANY *
argument_list|)
end_macro

begin_comment
comment|/* items that need to be restored 					   when LEAVEing scopes we've ENTERed */
end_comment

begin_macro
name|PERLVAR
argument_list|(
argument|Tsavestack_ix
argument_list|,
argument|I32
argument_list|)
end_macro

begin_macro
name|PERLVAR
argument_list|(
argument|Tsavestack_max
argument_list|,
argument|I32
argument_list|)
end_macro

begin_macro
name|PERLVAR
argument_list|(
argument|Ttmps_stack
argument_list|,
argument|SV **
argument_list|)
end_macro

begin_comment
comment|/* mortals we've made */
end_comment

begin_macro
name|PERLVARI
argument_list|(
argument|Ttmps_ix
argument_list|,
argument|I32
argument_list|,
argument|-
literal|1
argument_list|)
end_macro

begin_macro
name|PERLVARI
argument_list|(
argument|Ttmps_floor
argument_list|,
argument|I32
argument_list|,
argument|-
literal|1
argument_list|)
end_macro

begin_macro
name|PERLVAR
argument_list|(
argument|Ttmps_max
argument_list|,
argument|I32
argument_list|)
end_macro

begin_macro
name|PERLVAR
argument_list|(
argument|Tmarkstack
argument_list|,
argument|I32 *
argument_list|)
end_macro

begin_comment
comment|/* stack_sp locations we're remembering */
end_comment

begin_macro
name|PERLVAR
argument_list|(
argument|Tmarkstack_ptr
argument_list|,
argument|I32 *
argument_list|)
end_macro

begin_macro
name|PERLVAR
argument_list|(
argument|Tmarkstack_max
argument_list|,
argument|I32 *
argument_list|)
end_macro

begin_macro
name|PERLVAR
argument_list|(
argument|Tretstack
argument_list|,
argument|OP **
argument_list|)
end_macro

begin_comment
comment|/* OPs we have postponed executing */
end_comment

begin_macro
name|PERLVAR
argument_list|(
argument|Tretstack_ix
argument_list|,
argument|I32
argument_list|)
end_macro

begin_macro
name|PERLVAR
argument_list|(
argument|Tretstack_max
argument_list|,
argument|I32
argument_list|)
end_macro

begin_macro
name|PERLVAR
argument_list|(
argument|TSv
argument_list|,
argument|SV *
argument_list|)
end_macro

begin_comment
comment|/* used to hold temporary values */
end_comment

begin_macro
name|PERLVAR
argument_list|(
argument|TXpv
argument_list|,
argument|XPV *
argument_list|)
end_macro

begin_comment
comment|/* used to hold temporary values */
end_comment

begin_comment
comment|/* stat stuff */
end_comment

begin_macro
name|PERLVAR
argument_list|(
argument|Tstatbuf
argument_list|,
argument|Stat_t
argument_list|)
end_macro

begin_macro
name|PERLVAR
argument_list|(
argument|Tstatcache
argument_list|,
argument|Stat_t
argument_list|)
end_macro

begin_comment
comment|/* _ */
end_comment

begin_macro
name|PERLVAR
argument_list|(
argument|Tstatgv
argument_list|,
argument|GV *
argument_list|)
end_macro

begin_macro
name|PERLVARI
argument_list|(
argument|Tstatname
argument_list|,
argument|SV *
argument_list|,
argument|Nullsv
argument_list|)
end_macro

begin_ifdef
ifdef|#
directive|ifdef
name|HAS_TIMES
end_ifdef

begin_macro
name|PERLVAR
argument_list|(
argument|Ttimesbuf
argument_list|,
argument|struct tms
argument_list|)
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Fields used by magic variables such as $@, $/ and so on */
end_comment

begin_macro
name|PERLVAR
argument_list|(
argument|Ttainted
argument_list|,
argument|bool
argument_list|)
end_macro

begin_comment
comment|/* using variables controlled by $< */
end_comment

begin_macro
name|PERLVAR
argument_list|(
argument|Tcurpm
argument_list|,
argument|PMOP *
argument_list|)
end_macro

begin_comment
comment|/* what to do \ interps in REs from */
end_comment

begin_macro
name|PERLVAR
argument_list|(
argument|Tnrs
argument_list|,
argument|SV *
argument_list|)
end_macro

begin_macro
name|PERLVAR
argument_list|(
argument|Trs
argument_list|,
argument|SV *
argument_list|)
end_macro

begin_comment
comment|/* input record separator $/ */
end_comment

begin_macro
name|PERLVAR
argument_list|(
argument|Tlast_in_gv
argument_list|,
argument|GV *
argument_list|)
end_macro

begin_comment
comment|/* GV used in last<FH> */
end_comment

begin_macro
name|PERLVAR
argument_list|(
argument|Tofs
argument_list|,
argument|char *
argument_list|)
end_macro

begin_comment
comment|/* output field separator $, */
end_comment

begin_macro
name|PERLVAR
argument_list|(
argument|Tofslen
argument_list|,
argument|STRLEN
argument_list|)
end_macro

begin_macro
name|PERLVAR
argument_list|(
argument|Tdefoutgv
argument_list|,
argument|GV *
argument_list|)
end_macro

begin_comment
comment|/* default FH for output */
end_comment

begin_macro
name|PERLVARI
argument_list|(
argument|Tchopset
argument_list|,
argument|char *
argument_list|,
literal|" \n-"
argument_list|)
end_macro

begin_comment
comment|/* $: */
end_comment

begin_macro
name|PERLVAR
argument_list|(
argument|Tformtarget
argument_list|,
argument|SV *
argument_list|)
end_macro

begin_macro
name|PERLVAR
argument_list|(
argument|Tbodytarget
argument_list|,
argument|SV *
argument_list|)
end_macro

begin_macro
name|PERLVAR
argument_list|(
argument|Ttoptarget
argument_list|,
argument|SV *
argument_list|)
end_macro

begin_comment
comment|/* Stashes */
end_comment

begin_macro
name|PERLVAR
argument_list|(
argument|Tdefstash
argument_list|,
argument|HV *
argument_list|)
end_macro

begin_comment
comment|/* main symbol table */
end_comment

begin_macro
name|PERLVAR
argument_list|(
argument|Tcurstash
argument_list|,
argument|HV *
argument_list|)
end_macro

begin_comment
comment|/* symbol table for current package */
end_comment

begin_macro
name|PERLVAR
argument_list|(
argument|Trestartop
argument_list|,
argument|OP *
argument_list|)
end_macro

begin_comment
comment|/* propagating an error from croak? */
end_comment

begin_macro
name|PERLVARI
argument_list|(
argument|Tcurcop
argument_list|,
argument|COP * VOL
argument_list|,
argument|&PL_compiling
argument_list|)
end_macro

begin_macro
name|PERLVAR
argument_list|(
argument|Tin_eval
argument_list|,
argument|VOL int
argument_list|)
end_macro

begin_comment
comment|/* trap "fatal" errors? */
end_comment

begin_macro
name|PERLVAR
argument_list|(
argument|Tdelaymagic
argument_list|,
argument|int
argument_list|)
end_macro

begin_comment
comment|/* ($<,$>) = ... */
end_comment

begin_macro
name|PERLVAR
argument_list|(
argument|Tdirty
argument_list|,
argument|bool
argument_list|)
end_macro

begin_comment
comment|/* in the middle of tearing things down? */
end_comment

begin_macro
name|PERLVAR
argument_list|(
argument|Tlocalizing
argument_list|,
argument|int
argument_list|)
end_macro

begin_comment
comment|/* are we processing a local() list? */
end_comment

begin_macro
name|PERLVAR
argument_list|(
argument|Tcurstack
argument_list|,
argument|AV *
argument_list|)
end_macro

begin_comment
comment|/* THE STACK */
end_comment

begin_macro
name|PERLVAR
argument_list|(
argument|Tcurstackinfo
argument_list|,
argument|PERL_SI *
argument_list|)
end_macro

begin_comment
comment|/* current stack + context */
end_comment

begin_macro
name|PERLVAR
argument_list|(
argument|Tmainstack
argument_list|,
argument|AV *
argument_list|)
end_macro

begin_comment
comment|/* the stack when nothing funny is happening */
end_comment

begin_macro
name|PERLVAR
argument_list|(
argument|Ttop_env
argument_list|,
argument|JMPENV *
argument_list|)
end_macro

begin_comment
comment|/* ptr. to current sigjmp() environment */
end_comment

begin_macro
name|PERLVAR
argument_list|(
argument|Tstart_env
argument_list|,
argument|JMPENV
argument_list|)
end_macro

begin_comment
comment|/* empty startup sigjmp() environment */
end_comment

begin_comment
comment|/* statics "owned" by various functions */
end_comment

begin_macro
name|PERLVAR
argument_list|(
argument|Tav_fetch_sv
argument_list|,
argument|SV *
argument_list|)
end_macro

begin_comment
comment|/* owned by av_fetch() */
end_comment

begin_macro
name|PERLVAR
argument_list|(
argument|Thv_fetch_sv
argument_list|,
argument|SV *
argument_list|)
end_macro

begin_comment
comment|/* owned by hv_fetch() */
end_comment

begin_macro
name|PERLVAR
argument_list|(
argument|Thv_fetch_ent_mh
argument_list|,
argument|HE
argument_list|)
end_macro

begin_comment
comment|/* owned by hv_fetch_ent() */
end_comment

begin_macro
name|PERLVAR
argument_list|(
argument|Tmodcount
argument_list|,
argument|I32
argument_list|)
end_macro

begin_comment
comment|/* how much mod()ification in assignment? */
end_comment

begin_macro
name|PERLVAR
argument_list|(
argument|Tlastgotoprobe
argument_list|,
argument|OP*
argument_list|)
end_macro

begin_comment
comment|/* from pp_ctl.c */
end_comment

begin_comment
comment|/* sort stuff */
end_comment

begin_macro
name|PERLVAR
argument_list|(
argument|Tsortcop
argument_list|,
argument|OP *
argument_list|)
end_macro

begin_comment
comment|/* user defined sort routine */
end_comment

begin_macro
name|PERLVAR
argument_list|(
argument|Tsortstash
argument_list|,
argument|HV *
argument_list|)
end_macro

begin_comment
comment|/* which is in some package or other */
end_comment

begin_macro
name|PERLVAR
argument_list|(
argument|Tfirstgv
argument_list|,
argument|GV *
argument_list|)
end_macro

begin_comment
comment|/* $a */
end_comment

begin_macro
name|PERLVAR
argument_list|(
argument|Tsecondgv
argument_list|,
argument|GV *
argument_list|)
end_macro

begin_comment
comment|/* $b */
end_comment

begin_macro
name|PERLVAR
argument_list|(
argument|Tsortcxix
argument_list|,
argument|I32
argument_list|)
end_macro

begin_comment
comment|/* from pp_ctl.c */
end_comment

begin_comment
comment|/* regex stuff */
end_comment

begin_macro
name|PERLVAR
argument_list|(
argument|Tscreamfirst
argument_list|,
argument|I32 *
argument_list|)
end_macro

begin_macro
name|PERLVAR
argument_list|(
argument|Tscreamnext
argument_list|,
argument|I32 *
argument_list|)
end_macro

begin_macro
name|PERLVARI
argument_list|(
argument|Tmaxscream
argument_list|,
argument|I32
argument_list|,
argument|-
literal|1
argument_list|)
end_macro

begin_macro
name|PERLVAR
argument_list|(
argument|Tlastscream
argument_list|,
argument|SV *
argument_list|)
end_macro

begin_macro
name|PERLVAR
argument_list|(
argument|Tregdummy
argument_list|,
argument|regnode
argument_list|)
end_macro

begin_comment
comment|/* from regcomp.c */
end_comment

begin_macro
name|PERLVAR
argument_list|(
argument|Tregcomp_parse
argument_list|,
argument|char*
argument_list|)
end_macro

begin_comment
comment|/* Input-scan pointer. */
end_comment

begin_macro
name|PERLVAR
argument_list|(
argument|Tregxend
argument_list|,
argument|char*
argument_list|)
end_macro

begin_comment
comment|/* End of input for compile */
end_comment

begin_macro
name|PERLVAR
argument_list|(
argument|Tregcode
argument_list|,
argument|regnode*
argument_list|)
end_macro

begin_comment
comment|/* Code-emit pointer;&regdummy = don't */
end_comment

begin_macro
name|PERLVAR
argument_list|(
argument|Tregnaughty
argument_list|,
argument|I32
argument_list|)
end_macro

begin_comment
comment|/* How bad is this pattern? */
end_comment

begin_macro
name|PERLVAR
argument_list|(
argument|Tregsawback
argument_list|,
argument|I32
argument_list|)
end_macro

begin_comment
comment|/* Did we see \1, ...? */
end_comment

begin_macro
name|PERLVAR
argument_list|(
argument|Tregprecomp
argument_list|,
argument|char *
argument_list|)
end_macro

begin_comment
comment|/* uncompiled string. */
end_comment

begin_macro
name|PERLVAR
argument_list|(
argument|Tregnpar
argument_list|,
argument|I32
argument_list|)
end_macro

begin_comment
comment|/* () count. */
end_comment

begin_macro
name|PERLVAR
argument_list|(
argument|Tregsize
argument_list|,
argument|I32
argument_list|)
end_macro

begin_comment
comment|/* Code size. */
end_comment

begin_macro
name|PERLVAR
argument_list|(
argument|Tregflags
argument_list|,
argument|U16
argument_list|)
end_macro

begin_comment
comment|/* are we folding, multilining? */
end_comment

begin_macro
name|PERLVAR
argument_list|(
argument|Tregseen
argument_list|,
argument|U32
argument_list|)
end_macro

begin_comment
comment|/* from regcomp.c */
end_comment

begin_macro
name|PERLVAR
argument_list|(
argument|Tseen_zerolen
argument_list|,
argument|I32
argument_list|)
end_macro

begin_comment
comment|/* from regcomp.c */
end_comment

begin_macro
name|PERLVAR
argument_list|(
argument|Tseen_evals
argument_list|,
argument|I32
argument_list|)
end_macro

begin_comment
comment|/* from regcomp.c */
end_comment

begin_macro
name|PERLVAR
argument_list|(
argument|Tregcomp_rx
argument_list|,
argument|regexp *
argument_list|)
end_macro

begin_comment
comment|/* from regcomp.c */
end_comment

begin_macro
name|PERLVAR
argument_list|(
argument|Textralen
argument_list|,
argument|I32
argument_list|)
end_macro

begin_comment
comment|/* from regcomp.c */
end_comment

begin_macro
name|PERLVAR
argument_list|(
argument|Tcolorset
argument_list|,
argument|int
argument_list|)
end_macro

begin_comment
comment|/* from regcomp.c */
end_comment

begin_macro
name|PERLVAR
argument_list|(
argument|Tcolors[
literal|4
argument|]
argument_list|,
argument|char *
argument_list|)
end_macro

begin_comment
comment|/* from regcomp.c */
end_comment

begin_macro
name|PERLVAR
argument_list|(
argument|Treginput
argument_list|,
argument|char *
argument_list|)
end_macro

begin_comment
comment|/* String-input pointer. */
end_comment

begin_macro
name|PERLVAR
argument_list|(
argument|Tregbol
argument_list|,
argument|char *
argument_list|)
end_macro

begin_comment
comment|/* Beginning of input, for ^ check. */
end_comment

begin_macro
name|PERLVAR
argument_list|(
argument|Tregeol
argument_list|,
argument|char *
argument_list|)
end_macro

begin_comment
comment|/* End of input, for $ check. */
end_comment

begin_macro
name|PERLVAR
argument_list|(
argument|Tregstartp
argument_list|,
argument|char **
argument_list|)
end_macro

begin_comment
comment|/* Pointer to startp array. */
end_comment

begin_macro
name|PERLVAR
argument_list|(
argument|Tregendp
argument_list|,
argument|char **
argument_list|)
end_macro

begin_comment
comment|/* Ditto for endp. */
end_comment

begin_macro
name|PERLVAR
argument_list|(
argument|Treglastparen
argument_list|,
argument|U32 *
argument_list|)
end_macro

begin_comment
comment|/* Similarly for lastparen. */
end_comment

begin_macro
name|PERLVAR
argument_list|(
argument|Tregtill
argument_list|,
argument|char *
argument_list|)
end_macro

begin_comment
comment|/* How far we are required to go. */
end_comment

begin_macro
name|PERLVAR
argument_list|(
argument|Tregprev
argument_list|,
argument|char
argument_list|)
end_macro

begin_comment
comment|/* char before regbol, \n if none */
end_comment

begin_macro
name|PERLVAR
argument_list|(
argument|Treg_start_tmp
argument_list|,
argument|char **
argument_list|)
end_macro

begin_comment
comment|/* from regexec.c */
end_comment

begin_macro
name|PERLVAR
argument_list|(
argument|Treg_start_tmpl
argument_list|,
argument|U32
argument_list|)
end_macro

begin_comment
comment|/* from regexec.c */
end_comment

begin_macro
name|PERLVAR
argument_list|(
argument|Tregdata
argument_list|,
argument|struct reg_data *
argument_list|)
end_macro

begin_comment
comment|/* from regexec.c renamed was data */
end_comment

begin_macro
name|PERLVAR
argument_list|(
argument|Tbostr
argument_list|,
argument|char *
argument_list|)
end_macro

begin_comment
comment|/* from regexec.c */
end_comment

begin_macro
name|PERLVAR
argument_list|(
argument|Treg_flags
argument_list|,
argument|U32
argument_list|)
end_macro

begin_comment
comment|/* from regexec.c */
end_comment

begin_macro
name|PERLVAR
argument_list|(
argument|Treg_eval_set
argument_list|,
argument|I32
argument_list|)
end_macro

begin_comment
comment|/* from regexec.c */
end_comment

begin_macro
name|PERLVAR
argument_list|(
argument|Tregnarrate
argument_list|,
argument|I32
argument_list|)
end_macro

begin_comment
comment|/* from regexec.c */
end_comment

begin_macro
name|PERLVAR
argument_list|(
argument|Tregprogram
argument_list|,
argument|regnode *
argument_list|)
end_macro

begin_comment
comment|/* from regexec.c */
end_comment

begin_macro
name|PERLVARI
argument_list|(
argument|Tregindent
argument_list|,
argument|int
argument_list|,
literal|0
argument_list|)
end_macro

begin_comment
comment|/* from regexec.c */
end_comment

begin_macro
name|PERLVAR
argument_list|(
argument|Tregcc
argument_list|,
argument|CURCUR *
argument_list|)
end_macro

begin_comment
comment|/* from regexec.c */
end_comment

begin_macro
name|PERLVARI
argument_list|(
argument|Tregcompp
argument_list|,
argument|regcomp_t
argument_list|,
argument|FUNC_NAME_TO_PTR(pregcomp)
argument_list|)
end_macro

begin_comment
comment|/* Pointer to RE compiler */
end_comment

begin_macro
name|PERLVARI
argument_list|(
argument|Tregexecp
argument_list|,
argument|regexec_t
argument_list|,
argument|FUNC_NAME_TO_PTR(regexec_flags)
argument_list|)
end_macro

begin_comment
comment|/* Pointer to RE executer */
end_comment

begin_macro
name|PERLVARI
argument_list|(
argument|Treginterp_cnt
argument_list|,
argument|int
argument_list|,
literal|0
argument_list|)
end_macro

begin_comment
comment|/* Whether `Regexp' 						   was interpolated. */
end_comment

begin_comment
comment|/* Note that the variables below are all explicitly referenced in the code  * as thr->whatever and therefore don't need the 'T' prefix. */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|USE_THREADS
end_ifdef

begin_macro
name|PERLVAR
argument_list|(
argument|oursv
argument_list|,
argument|SV *
argument_list|)
end_macro

begin_macro
name|PERLVAR
argument_list|(
argument|cvcache
argument_list|,
argument|HV *
argument_list|)
end_macro

begin_macro
name|PERLVAR
argument_list|(
argument|self
argument_list|,
argument|perl_os_thread
argument_list|)
end_macro

begin_comment
comment|/* Underlying thread object */
end_comment

begin_macro
name|PERLVAR
argument_list|(
argument|flags
argument_list|,
argument|U32
argument_list|)
end_macro

begin_macro
name|PERLVAR
argument_list|(
argument|threadsv
argument_list|,
argument|AV *
argument_list|)
end_macro

begin_comment
comment|/* Per-thread SVs ($_, $@ etc.) */
end_comment

begin_macro
name|PERLVAR
argument_list|(
argument|threadsvp
argument_list|,
argument|SV **
argument_list|)
end_macro

begin_comment
comment|/* AvARRAY(threadsv) */
end_comment

begin_macro
name|PERLVAR
argument_list|(
argument|specific
argument_list|,
argument|AV *
argument_list|)
end_macro

begin_comment
comment|/* Thread-specific user data */
end_comment

begin_macro
name|PERLVAR
argument_list|(
argument|errsv
argument_list|,
argument|SV *
argument_list|)
end_macro

begin_comment
comment|/* Backing SV for $@ */
end_comment

begin_macro
name|PERLVAR
argument_list|(
argument|errhv
argument_list|,
argument|HV *
argument_list|)
end_macro

begin_comment
comment|/* HV for what was %@ in pp_ctl.c */
end_comment

begin_macro
name|PERLVAR
argument_list|(
argument|mutex
argument_list|,
argument|perl_mutex
argument_list|)
end_macro

begin_comment
comment|/* For the fields others can change */
end_comment

begin_macro
name|PERLVAR
argument_list|(
argument|tid
argument_list|,
argument|U32
argument_list|)
end_macro

begin_macro
name|PERLVAR
argument_list|(
argument|prev
argument_list|,
argument|struct perl_thread *
argument_list|)
end_macro

begin_macro
name|PERLVAR
argument_list|(
argument|next
argument_list|,
argument|struct perl_thread *
argument_list|)
end_macro

begin_comment
comment|/* Circular linked list of threads */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_THREAD_INTERN
end_ifdef

begin_macro
name|PERLVAR
argument_list|(
argument|i
argument_list|,
argument|struct thread_intern
argument_list|)
end_macro

begin_comment
comment|/* Platform-dependent internals */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_macro
name|PERLVAR
argument_list|(
argument|trailing_nul
argument_list|,
argument|char
argument_list|)
end_macro

begin_comment
comment|/* For the sake of thrsv and oursv */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* USE_THREADS */
end_comment

end_unit

