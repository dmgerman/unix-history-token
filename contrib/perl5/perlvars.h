begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/****************/
end_comment

begin_comment
comment|/* Truly global */
end_comment

begin_comment
comment|/****************/
end_comment

begin_comment
comment|/* Don't forget to re-run embed.pl to propagate changes! */
end_comment

begin_comment
comment|/* This file describes the "global" variables used by perl  * This used to be in perl.h directly but we want to abstract out into  * distinct files which are per-thread, per-interpreter or really global,  * and how they're initialized.  *  * The 'G' prefix is only needed for vars that need appropriate #defines  * generated when built with or without EMBED.  It is also used to generate  * the appropriate export list for win32.  *  * Avoid build-specific #ifdefs here, like DEBUGGING.  That way,  * we can keep binary compatibility of the curinterp structure */
end_comment

begin_comment
comment|/* global state */
end_comment

begin_macro
name|PERLVAR
argument_list|(
argument|Gcurinterp
argument_list|,
argument|PerlInterpreter *
argument_list|)
end_macro

begin_comment
comment|/* currently running interpreter */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|USE_THREADS
end_ifdef

begin_macro
name|PERLVAR
argument_list|(
argument|Gthr_key
argument_list|,
argument|perl_key
argument_list|)
end_macro

begin_comment
comment|/* For per-thread struct perl_thread* */
end_comment

begin_macro
name|PERLVAR
argument_list|(
argument|Gsv_mutex
argument_list|,
argument|perl_mutex
argument_list|)
end_macro

begin_comment
comment|/* Mutex for allocating SVs in sv.c */
end_comment

begin_macro
name|PERLVAR
argument_list|(
argument|Gmalloc_mutex
argument_list|,
argument|perl_mutex
argument_list|)
end_macro

begin_comment
comment|/* Mutex for malloc */
end_comment

begin_macro
name|PERLVAR
argument_list|(
argument|Geval_mutex
argument_list|,
argument|perl_mutex
argument_list|)
end_macro

begin_comment
comment|/* Mutex for doeval */
end_comment

begin_macro
name|PERLVAR
argument_list|(
argument|Geval_cond
argument_list|,
argument|perl_cond
argument_list|)
end_macro

begin_comment
comment|/* Condition variable for doeval */
end_comment

begin_macro
name|PERLVAR
argument_list|(
argument|Geval_owner
argument_list|,
argument|struct perl_thread *
argument_list|)
end_macro

begin_comment
comment|/* Owner thread for doeval */
end_comment

begin_macro
name|PERLVAR
argument_list|(
argument|Gnthreads
argument_list|,
argument|int
argument_list|)
end_macro

begin_comment
comment|/* Number of threads currently */
end_comment

begin_macro
name|PERLVAR
argument_list|(
argument|Gthreads_mutex
argument_list|,
argument|perl_mutex
argument_list|)
end_macro

begin_comment
comment|/* Mutex for nthreads and thread list */
end_comment

begin_macro
name|PERLVAR
argument_list|(
argument|Gnthreads_cond
argument_list|,
argument|perl_cond
argument_list|)
end_macro

begin_comment
comment|/* Condition variable for nthreads */
end_comment

begin_macro
name|PERLVAR
argument_list|(
argument|Gsvref_mutex
argument_list|,
argument|perl_mutex
argument_list|)
end_macro

begin_comment
comment|/* Mutex for SvREFCNT_{inc,dec} */
end_comment

begin_macro
name|PERLVARI
argument_list|(
argument|Gthreadsv_names
argument_list|,
argument|char *
argument_list|,
argument|THREADSV_NAMES
argument_list|)
end_macro

begin_ifdef
ifdef|#
directive|ifdef
name|FAKE_THREADS
end_ifdef

begin_macro
name|PERLVAR
argument_list|(
argument|Gcurthr
argument_list|,
argument|struct perl_thread *
argument_list|)
end_macro

begin_comment
comment|/* Currently executing (fake) thread */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* USE_THREADS */
end_comment

begin_macro
name|PERLVAR
argument_list|(
argument|Gninterps
argument_list|,
argument|int
argument_list|)
end_macro

begin_comment
comment|/* number of active interpreters */
end_comment

begin_macro
name|PERLVAR
argument_list|(
argument|Guid
argument_list|,
argument|int
argument_list|)
end_macro

begin_comment
comment|/* current real user id */
end_comment

begin_macro
name|PERLVAR
argument_list|(
argument|Geuid
argument_list|,
argument|int
argument_list|)
end_macro

begin_comment
comment|/* current effective user id */
end_comment

begin_macro
name|PERLVAR
argument_list|(
argument|Ggid
argument_list|,
argument|int
argument_list|)
end_macro

begin_comment
comment|/* current real group id */
end_comment

begin_macro
name|PERLVAR
argument_list|(
argument|Gegid
argument_list|,
argument|int
argument_list|)
end_macro

begin_comment
comment|/* current effective group id */
end_comment

begin_macro
name|PERLVAR
argument_list|(
argument|Gnomemok
argument_list|,
argument|bool
argument_list|)
end_macro

begin_comment
comment|/* let malloc context handle nomem */
end_comment

begin_macro
name|PERLVAR
argument_list|(
argument|Gan
argument_list|,
argument|U32
argument_list|)
end_macro

begin_comment
comment|/* malloc sequence number */
end_comment

begin_macro
name|PERLVAR
argument_list|(
argument|Gcop_seqmax
argument_list|,
argument|U32
argument_list|)
end_macro

begin_comment
comment|/* statement sequence number */
end_comment

begin_macro
name|PERLVAR
argument_list|(
argument|Gop_seqmax
argument_list|,
argument|U16
argument_list|)
end_macro

begin_comment
comment|/* op sequence number */
end_comment

begin_macro
name|PERLVAR
argument_list|(
argument|Gevalseq
argument_list|,
argument|U32
argument_list|)
end_macro

begin_comment
comment|/* eval sequence number */
end_comment

begin_macro
name|PERLVAR
argument_list|(
argument|Gorigenviron
argument_list|,
argument|char **
argument_list|)
end_macro

begin_macro
name|PERLVAR
argument_list|(
argument|Gorigalen
argument_list|,
argument|U32
argument_list|)
end_macro

begin_macro
name|PERLVAR
argument_list|(
argument|Gpidstatus
argument_list|,
argument|HV *
argument_list|)
end_macro

begin_comment
comment|/* pid-to-status mappings for waitpid */
end_comment

begin_macro
name|PERLVARI
argument_list|(
argument|Gmaxo
argument_list|,
argument|int
argument_list|,
argument|MAXO
argument_list|)
end_macro

begin_comment
comment|/* maximum number of ops */
end_comment

begin_macro
name|PERLVAR
argument_list|(
argument|Gosname
argument_list|,
argument|char *
argument_list|)
end_macro

begin_comment
comment|/* operating system */
end_comment

begin_macro
name|PERLVARI
argument_list|(
argument|Gsh_path
argument_list|,
argument|char *
argument_list|,
argument|SH_PATH
argument_list|)
end_macro

begin_comment
comment|/* full path of shell */
end_comment

begin_macro
name|PERLVAR
argument_list|(
argument|Gsighandlerp
argument_list|,
argument|Sighandler_t
argument_list|)
end_macro

begin_macro
name|PERLVAR
argument_list|(
argument|Gxiv_arenaroot
argument_list|,
argument|XPV*
argument_list|)
end_macro

begin_comment
comment|/* list of allocated xiv areas */
end_comment

begin_macro
name|PERLVAR
argument_list|(
argument|Gxiv_root
argument_list|,
argument|IV *
argument_list|)
end_macro

begin_comment
comment|/* free xiv list--shared by interpreters */
end_comment

begin_macro
name|PERLVAR
argument_list|(
argument|Gxnv_root
argument_list|,
argument|double *
argument_list|)
end_macro

begin_comment
comment|/* free xnv list--shared by interpreters */
end_comment

begin_macro
name|PERLVAR
argument_list|(
argument|Gxrv_root
argument_list|,
argument|XRV *
argument_list|)
end_macro

begin_comment
comment|/* free xrv list--shared by interpreters */
end_comment

begin_macro
name|PERLVAR
argument_list|(
argument|Gxpv_root
argument_list|,
argument|XPV *
argument_list|)
end_macro

begin_comment
comment|/* free xpv list--shared by interpreters */
end_comment

begin_macro
name|PERLVAR
argument_list|(
argument|Ghe_root
argument_list|,
argument|HE *
argument_list|)
end_macro

begin_comment
comment|/* free he list--shared by interpreters */
end_comment

begin_macro
name|PERLVAR
argument_list|(
argument|Gnice_chunk
argument_list|,
argument|char *
argument_list|)
end_macro

begin_comment
comment|/* a nice chunk of memory to reuse */
end_comment

begin_macro
name|PERLVAR
argument_list|(
argument|Gnice_chunk_size
argument_list|,
argument|U32
argument_list|)
end_macro

begin_comment
comment|/* how nice the chunk of memory is */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|PERL_OBJECT
end_ifdef

begin_macro
name|PERLVARI
argument_list|(
argument|Grunops
argument_list|,
argument|runops_proc_t
argument_list|,
argument|FUNC_NAME_TO_PTR(RUNOPS_DEFAULT)
argument_list|)
end_macro

begin_else
else|#
directive|else
end_else

begin_macro
name|PERLVARI
argument_list|(
argument|Grunops
argument_list|,
argument|runops_proc_t *
argument_list|,
argument|RUNOPS_DEFAULT
argument_list|)
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_macro
name|PERLVAR
argument_list|(
argument|Gtokenbuf[
literal|256
argument|]
argument_list|,
argument|char
argument_list|)
end_macro

begin_macro
name|PERLVAR
argument_list|(
argument|Gna
argument_list|,
argument|STRLEN
argument_list|)
end_macro

begin_comment
comment|/* for use in SvPV when length is 					   Not Applicable */
end_comment

begin_macro
name|PERLVAR
argument_list|(
argument|Gsv_undef
argument_list|,
argument|SV
argument_list|)
end_macro

begin_macro
name|PERLVAR
argument_list|(
argument|Gsv_no
argument_list|,
argument|SV
argument_list|)
end_macro

begin_macro
name|PERLVAR
argument_list|(
argument|Gsv_yes
argument_list|,
argument|SV
argument_list|)
end_macro

begin_ifdef
ifdef|#
directive|ifdef
name|CSH
end_ifdef

begin_macro
name|PERLVARI
argument_list|(
argument|Gcshname
argument_list|,
argument|char *
argument_list|,
argument|CSH
argument_list|)
end_macro

begin_macro
name|PERLVAR
argument_list|(
argument|Gcshlen
argument_list|,
argument|I32
argument_list|)
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_macro
name|PERLVAR
argument_list|(
argument|Glex_state
argument_list|,
argument|U32
argument_list|)
end_macro

begin_comment
comment|/* next token is determined */
end_comment

begin_macro
name|PERLVAR
argument_list|(
argument|Glex_defer
argument_list|,
argument|U32
argument_list|)
end_macro

begin_comment
comment|/* state after determined token */
end_comment

begin_macro
name|PERLVAR
argument_list|(
argument|Glex_expect
argument_list|,
argument|expectation
argument_list|)
end_macro

begin_comment
comment|/* expect after determined token */
end_comment

begin_macro
name|PERLVAR
argument_list|(
argument|Glex_brackets
argument_list|,
argument|I32
argument_list|)
end_macro

begin_comment
comment|/* bracket count */
end_comment

begin_macro
name|PERLVAR
argument_list|(
argument|Glex_formbrack
argument_list|,
argument|I32
argument_list|)
end_macro

begin_comment
comment|/* bracket count at outer format level */
end_comment

begin_macro
name|PERLVAR
argument_list|(
argument|Glex_fakebrack
argument_list|,
argument|I32
argument_list|)
end_macro

begin_comment
comment|/* outer bracket is mere delimiter */
end_comment

begin_macro
name|PERLVAR
argument_list|(
argument|Glex_casemods
argument_list|,
argument|I32
argument_list|)
end_macro

begin_comment
comment|/* casemod count */
end_comment

begin_macro
name|PERLVAR
argument_list|(
argument|Glex_dojoin
argument_list|,
argument|I32
argument_list|)
end_macro

begin_comment
comment|/* doing an array interpolation */
end_comment

begin_macro
name|PERLVAR
argument_list|(
argument|Glex_starts
argument_list|,
argument|I32
argument_list|)
end_macro

begin_comment
comment|/* how many interps done on level */
end_comment

begin_macro
name|PERLVAR
argument_list|(
argument|Glex_stuff
argument_list|,
argument|SV *
argument_list|)
end_macro

begin_comment
comment|/* runtime pattern from m// or s/// */
end_comment

begin_macro
name|PERLVAR
argument_list|(
argument|Glex_repl
argument_list|,
argument|SV *
argument_list|)
end_macro

begin_comment
comment|/* runtime replacement from s/// */
end_comment

begin_macro
name|PERLVAR
argument_list|(
argument|Glex_op
argument_list|,
argument|OP *
argument_list|)
end_macro

begin_comment
comment|/* extra info to pass back on op */
end_comment

begin_macro
name|PERLVAR
argument_list|(
argument|Glex_inpat
argument_list|,
argument|OP *
argument_list|)
end_macro

begin_comment
comment|/* in pattern $) and $| are special */
end_comment

begin_macro
name|PERLVAR
argument_list|(
argument|Glex_inwhat
argument_list|,
argument|I32
argument_list|)
end_macro

begin_comment
comment|/* what kind of quoting are we in */
end_comment

begin_macro
name|PERLVAR
argument_list|(
argument|Glex_brackstack
argument_list|,
argument|char *
argument_list|)
end_macro

begin_comment
comment|/* what kind of brackets to pop */
end_comment

begin_macro
name|PERLVAR
argument_list|(
argument|Glex_casestack
argument_list|,
argument|char *
argument_list|)
end_macro

begin_comment
comment|/* what kind of case mods in effect */
end_comment

begin_comment
comment|/* What we know when we're in LEX_KNOWNEXT state. */
end_comment

begin_macro
name|PERLVAR
argument_list|(
argument|Gnextval[
literal|5
argument|]
argument_list|,
argument|YYSTYPE
argument_list|)
end_macro

begin_comment
comment|/* value of next token, if any */
end_comment

begin_macro
name|PERLVAR
argument_list|(
argument|Gnexttype[
literal|5
argument|]
argument_list|,
argument|I32
argument_list|)
end_macro

begin_comment
comment|/* type of next token */
end_comment

begin_macro
name|PERLVAR
argument_list|(
argument|Gnexttoke
argument_list|,
argument|I32
argument_list|)
end_macro

begin_macro
name|PERLVAR
argument_list|(
argument|Glinestr
argument_list|,
argument|SV *
argument_list|)
end_macro

begin_macro
name|PERLVAR
argument_list|(
argument|Gbufptr
argument_list|,
argument|char *
argument_list|)
end_macro

begin_macro
name|PERLVAR
argument_list|(
argument|Goldbufptr
argument_list|,
argument|char *
argument_list|)
end_macro

begin_macro
name|PERLVAR
argument_list|(
argument|Goldoldbufptr
argument_list|,
argument|char *
argument_list|)
end_macro

begin_macro
name|PERLVAR
argument_list|(
argument|Gbufend
argument_list|,
argument|char *
argument_list|)
end_macro

begin_macro
name|PERLVARI
argument_list|(
argument|Gexpect
argument_list|,
argument|expectation
argument_list|,
argument|XSTATE
argument_list|)
end_macro

begin_comment
comment|/* how to interpret ambiguous tokens */
end_comment

begin_macro
name|PERLVAR
argument_list|(
argument|Gmulti_start
argument_list|,
argument|I32
argument_list|)
end_macro

begin_comment
comment|/* 1st line of multi-line string */
end_comment

begin_macro
name|PERLVAR
argument_list|(
argument|Gmulti_end
argument_list|,
argument|I32
argument_list|)
end_macro

begin_comment
comment|/* last line of multi-line string */
end_comment

begin_macro
name|PERLVAR
argument_list|(
argument|Gmulti_open
argument_list|,
argument|I32
argument_list|)
end_macro

begin_comment
comment|/* delimiter of said string */
end_comment

begin_macro
name|PERLVAR
argument_list|(
argument|Gmulti_close
argument_list|,
argument|I32
argument_list|)
end_macro

begin_comment
comment|/* delimiter of said string */
end_comment

begin_macro
name|PERLVAR
argument_list|(
argument|Gerror_count
argument_list|,
argument|I32
argument_list|)
end_macro

begin_comment
comment|/* how many errors so far, max 10 */
end_comment

begin_macro
name|PERLVAR
argument_list|(
argument|Gsubline
argument_list|,
argument|I32
argument_list|)
end_macro

begin_comment
comment|/* line this subroutine began on */
end_comment

begin_macro
name|PERLVAR
argument_list|(
argument|Gsubname
argument_list|,
argument|SV *
argument_list|)
end_macro

begin_comment
comment|/* name of current subroutine */
end_comment

begin_macro
name|PERLVAR
argument_list|(
argument|Gmin_intro_pending
argument_list|,
argument|I32
argument_list|)
end_macro

begin_comment
comment|/* start of vars to introduce */
end_comment

begin_macro
name|PERLVAR
argument_list|(
argument|Gmax_intro_pending
argument_list|,
argument|I32
argument_list|)
end_macro

begin_comment
comment|/* end of vars to introduce */
end_comment

begin_macro
name|PERLVAR
argument_list|(
argument|Gpadix
argument_list|,
argument|I32
argument_list|)
end_macro

begin_comment
comment|/* max used index in current "register" pad */
end_comment

begin_macro
name|PERLVAR
argument_list|(
argument|Gpadix_floor
argument_list|,
argument|I32
argument_list|)
end_macro

begin_comment
comment|/* how low may inner block reset padix */
end_comment

begin_macro
name|PERLVAR
argument_list|(
argument|Gpad_reset_pending
argument_list|,
argument|I32
argument_list|)
end_macro

begin_comment
comment|/* reset pad on next attempted alloc */
end_comment

begin_macro
name|PERLVAR
argument_list|(
argument|Gthisexpr
argument_list|,
argument|I32
argument_list|)
end_macro

begin_comment
comment|/* name id for nothing_in_common() */
end_comment

begin_macro
name|PERLVAR
argument_list|(
argument|Glast_uni
argument_list|,
argument|char *
argument_list|)
end_macro

begin_comment
comment|/* position of last named-unary op */
end_comment

begin_macro
name|PERLVAR
argument_list|(
argument|Glast_lop
argument_list|,
argument|char *
argument_list|)
end_macro

begin_comment
comment|/* position of last list operator */
end_comment

begin_macro
name|PERLVAR
argument_list|(
argument|Glast_lop_op
argument_list|,
argument|OPCODE
argument_list|)
end_macro

begin_comment
comment|/* last list operator */
end_comment

begin_macro
name|PERLVAR
argument_list|(
argument|Gin_my
argument_list|,
argument|bool
argument_list|)
end_macro

begin_comment
comment|/* we're compiling a "my" declaration */
end_comment

begin_macro
name|PERLVAR
argument_list|(
argument|Gin_my_stash
argument_list|,
argument|HV *
argument_list|)
end_macro

begin_comment
comment|/* declared class of this "my" declaration */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|FCRYPT
end_ifdef

begin_macro
name|PERLVAR
argument_list|(
argument|Gcryptseen
argument_list|,
argument|I32
argument_list|)
end_macro

begin_comment
comment|/* has fast crypt() been initialized? */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_macro
name|PERLVAR
argument_list|(
argument|Ghints
argument_list|,
argument|U32
argument_list|)
end_macro

begin_comment
comment|/* pragma-tic compile-time flags */
end_comment

begin_macro
name|PERLVAR
argument_list|(
argument|Gdo_undump
argument_list|,
argument|bool
argument_list|)
end_macro

begin_comment
comment|/* -u or dump seen? */
end_comment

begin_macro
name|PERLVAR
argument_list|(
argument|Gdebug
argument_list|,
argument|VOL U32
argument_list|)
end_macro

begin_comment
comment|/* flags given to -D switch */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|OVERLOAD
end_ifdef

begin_macro
name|PERLVAR
argument_list|(
argument|Gamagic_generation
argument_list|,
argument|long
argument_list|)
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|USE_LOCALE_COLLATE
end_ifdef

begin_macro
name|PERLVAR
argument_list|(
argument|Gcollation_ix
argument_list|,
argument|U32
argument_list|)
end_macro

begin_comment
comment|/* Collation generation index */
end_comment

begin_macro
name|PERLVAR
argument_list|(
argument|Gcollation_name
argument_list|,
argument|char *
argument_list|)
end_macro

begin_comment
comment|/* Name of current collation */
end_comment

begin_macro
name|PERLVARI
argument_list|(
argument|Gcollation_standard
argument_list|,
argument|bool
argument_list|,
argument|TRUE
argument_list|)
end_macro

begin_comment
comment|/* Assume simple collation */
end_comment

begin_macro
name|PERLVAR
argument_list|(
argument|Gcollxfrm_base
argument_list|,
argument|Size_t
argument_list|)
end_macro

begin_comment
comment|/* Basic overhead in *xfrm() */
end_comment

begin_macro
name|PERLVARI
argument_list|(
argument|Gcollxfrm_mult
argument_list|,
argument|Size_t
argument_list|,
literal|2
argument_list|)
end_macro

begin_comment
comment|/* Expansion factor in *xfrm() */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* USE_LOCALE_COLLATE */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|USE_LOCALE_NUMERIC
end_ifdef

begin_macro
name|PERLVAR
argument_list|(
argument|Gnumeric_name
argument_list|,
argument|char *
argument_list|)
end_macro

begin_comment
comment|/* Name of current numeric locale */
end_comment

begin_macro
name|PERLVARI
argument_list|(
argument|Gnumeric_standard
argument_list|,
argument|bool
argument_list|,
argument|TRUE
argument_list|)
end_macro

begin_comment
comment|/* Assume simple numerics */
end_comment

begin_macro
name|PERLVARI
argument_list|(
argument|Gnumeric_local
argument_list|,
argument|bool
argument_list|,
argument|TRUE
argument_list|)
end_macro

begin_comment
comment|/* Assume local numerics */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !USE_LOCALE_NUMERIC */
end_comment

begin_comment
comment|/* constants (these are not literals to facilitate pointer comparisons) */
end_comment

begin_macro
name|PERLVARIC
argument_list|(
argument|GYes
argument_list|,
argument|char *
argument_list|,
literal|"1"
argument_list|)
end_macro

begin_macro
name|PERLVARIC
argument_list|(
argument|GNo
argument_list|,
argument|char *
argument_list|,
literal|""
argument_list|)
end_macro

begin_macro
name|PERLVARIC
argument_list|(
argument|Ghexdigit
argument_list|,
argument|char *
argument_list|,
literal|"0123456789abcdef0123456789ABCDEF"
argument_list|)
end_macro

begin_macro
name|PERLVARIC
argument_list|(
argument|Gpatleave
argument_list|,
argument|char *
argument_list|,
literal|"\\.^$@dDwWsSbB+*?|()-nrtfeaxc0123456789[{]}"
argument_list|)
end_macro

begin_macro
name|PERLVAR
argument_list|(
argument|Gspecialsv_list[
literal|4
argument|]
argument_list|,
argument|SV *
argument_list|)
end_macro

begin_comment
comment|/* from byterun.h */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|USE_THREADS
end_ifdef

begin_macro
name|PERLVAR
argument_list|(
argument|Gcred_mutex
argument_list|,
argument|perl_mutex
argument_list|)
end_macro

begin_comment
comment|/* altered credentials in effect */
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

