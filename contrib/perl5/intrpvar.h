begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/***********************************************/
end_comment

begin_comment
comment|/* Global only to current interpreter instance */
end_comment

begin_comment
comment|/***********************************************/
end_comment

begin_comment
comment|/* Don't forget to re-run embed.pl to propagate changes! */
end_comment

begin_comment
comment|/* The 'I' prefix is only needed for vars that need appropriate #defines  * generated when built with or without MULTIPLICITY.  It is also used  * to generate the appropriate export list for win32.  *  * When building without MULTIPLICITY, these variables will be truly global.  *  * Avoid build-specific #ifdefs here, like DEBUGGING.  That way,  * we can keep binary compatibility of the curinterp structure */
end_comment

begin_comment
comment|/* pseudo environmental stuff */
end_comment

begin_macro
name|PERLVAR
argument_list|(
argument|Iorigargc
argument_list|,
argument|int
argument_list|)
end_macro

begin_macro
name|PERLVAR
argument_list|(
argument|Iorigargv
argument_list|,
argument|char **
argument_list|)
end_macro

begin_macro
name|PERLVAR
argument_list|(
argument|Ienvgv
argument_list|,
argument|GV *
argument_list|)
end_macro

begin_macro
name|PERLVAR
argument_list|(
argument|Isiggv
argument_list|,
argument|GV *
argument_list|)
end_macro

begin_macro
name|PERLVAR
argument_list|(
argument|Iincgv
argument_list|,
argument|GV *
argument_list|)
end_macro

begin_macro
name|PERLVAR
argument_list|(
argument|Ihintgv
argument_list|,
argument|GV *
argument_list|)
end_macro

begin_macro
name|PERLVAR
argument_list|(
argument|Iorigfilename
argument_list|,
argument|char *
argument_list|)
end_macro

begin_macro
name|PERLVAR
argument_list|(
argument|Idiehook
argument_list|,
argument|SV *
argument_list|)
end_macro

begin_macro
name|PERLVAR
argument_list|(
argument|Iwarnhook
argument_list|,
argument|SV *
argument_list|)
end_macro

begin_macro
name|PERLVAR
argument_list|(
argument|Iparsehook
argument_list|,
argument|SV *
argument_list|)
end_macro

begin_macro
name|PERLVAR
argument_list|(
argument|Icddir
argument_list|,
argument|char *
argument_list|)
end_macro

begin_comment
comment|/* switches */
end_comment

begin_macro
name|PERLVAR
argument_list|(
argument|Iminus_c
argument_list|,
argument|bool
argument_list|)
end_macro

begin_macro
name|PERLVAR
argument_list|(
argument|Ipatchlevel[
literal|10
argument|]
argument_list|,
argument|char
argument_list|)
end_macro

begin_macro
name|PERLVAR
argument_list|(
argument|Ilocalpatches
argument_list|,
argument|char **
argument_list|)
end_macro

begin_macro
name|PERLVARI
argument_list|(
argument|Isplitstr
argument_list|,
argument|char *
argument_list|,
literal|" "
argument_list|)
end_macro

begin_macro
name|PERLVAR
argument_list|(
argument|Ipreprocess
argument_list|,
argument|bool
argument_list|)
end_macro

begin_macro
name|PERLVAR
argument_list|(
argument|Iminus_n
argument_list|,
argument|bool
argument_list|)
end_macro

begin_macro
name|PERLVAR
argument_list|(
argument|Iminus_p
argument_list|,
argument|bool
argument_list|)
end_macro

begin_macro
name|PERLVAR
argument_list|(
argument|Iminus_l
argument_list|,
argument|bool
argument_list|)
end_macro

begin_macro
name|PERLVAR
argument_list|(
argument|Iminus_a
argument_list|,
argument|bool
argument_list|)
end_macro

begin_macro
name|PERLVAR
argument_list|(
argument|Iminus_F
argument_list|,
argument|bool
argument_list|)
end_macro

begin_macro
name|PERLVAR
argument_list|(
argument|Idoswitches
argument_list|,
argument|bool
argument_list|)
end_macro

begin_macro
name|PERLVAR
argument_list|(
argument|Idowarn
argument_list|,
argument|bool
argument_list|)
end_macro

begin_macro
name|PERLVAR
argument_list|(
argument|Idoextract
argument_list|,
argument|bool
argument_list|)
end_macro

begin_macro
name|PERLVAR
argument_list|(
argument|Isawampersand
argument_list|,
argument|bool
argument_list|)
end_macro

begin_comment
comment|/* must save all match strings */
end_comment

begin_macro
name|PERLVAR
argument_list|(
argument|Isawstudy
argument_list|,
argument|bool
argument_list|)
end_macro

begin_comment
comment|/* do fbm_instr on all strings */
end_comment

begin_macro
name|PERLVAR
argument_list|(
argument|Isawvec
argument_list|,
argument|bool
argument_list|)
end_macro

begin_macro
name|PERLVAR
argument_list|(
argument|Iunsafe
argument_list|,
argument|bool
argument_list|)
end_macro

begin_macro
name|PERLVAR
argument_list|(
argument|Iinplace
argument_list|,
argument|char *
argument_list|)
end_macro

begin_macro
name|PERLVAR
argument_list|(
argument|Ie_script
argument_list|,
argument|SV *
argument_list|)
end_macro

begin_macro
name|PERLVAR
argument_list|(
argument|Iperldb
argument_list|,
argument|U32
argument_list|)
end_macro

begin_comment
comment|/* This value may be raised by extensions for testing purposes */
end_comment

begin_comment
comment|/* 0=none, 1=full, 2=full with checks */
end_comment

begin_macro
name|PERLVARI
argument_list|(
argument|Iperl_destruct_level
argument_list|,
argument|int
argument_list|,
literal|0
argument_list|)
end_macro

begin_comment
comment|/* magical thingies */
end_comment

begin_macro
name|PERLVAR
argument_list|(
argument|Ibasetime
argument_list|,
argument|Time_t
argument_list|)
end_macro

begin_comment
comment|/* $^T */
end_comment

begin_macro
name|PERLVAR
argument_list|(
argument|Iformfeed
argument_list|,
argument|SV *
argument_list|)
end_macro

begin_comment
comment|/* $^L */
end_comment

begin_macro
name|PERLVARI
argument_list|(
argument|Imaxsysfd
argument_list|,
argument|I32
argument_list|,
argument|MAXSYSFD
argument_list|)
end_macro

begin_comment
comment|/* top fd to pass to subprocesses */
end_comment

begin_macro
name|PERLVAR
argument_list|(
argument|Imultiline
argument_list|,
argument|int
argument_list|)
end_macro

begin_comment
comment|/* $*--do strings hold>1 line? */
end_comment

begin_macro
name|PERLVAR
argument_list|(
argument|Istatusvalue
argument_list|,
argument|I32
argument_list|)
end_macro

begin_comment
comment|/* $? */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|VMS
end_ifdef

begin_macro
name|PERLVAR
argument_list|(
argument|Istatusvalue_vms
argument_list|,
argument|U32
argument_list|)
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* shortcuts to various I/O objects */
end_comment

begin_macro
name|PERLVAR
argument_list|(
argument|Istdingv
argument_list|,
argument|GV *
argument_list|)
end_macro

begin_macro
name|PERLVAR
argument_list|(
argument|Idefgv
argument_list|,
argument|GV *
argument_list|)
end_macro

begin_macro
name|PERLVAR
argument_list|(
argument|Iargvgv
argument_list|,
argument|GV *
argument_list|)
end_macro

begin_macro
name|PERLVAR
argument_list|(
argument|Iargvoutgv
argument_list|,
argument|GV *
argument_list|)
end_macro

begin_comment
comment|/* shortcuts to regexp stuff */
end_comment

begin_comment
comment|/* XXX these three aren't used anywhere */
end_comment

begin_macro
name|PERLVAR
argument_list|(
argument|Ileftgv
argument_list|,
argument|GV *
argument_list|)
end_macro

begin_macro
name|PERLVAR
argument_list|(
argument|Iampergv
argument_list|,
argument|GV *
argument_list|)
end_macro

begin_macro
name|PERLVAR
argument_list|(
argument|Irightgv
argument_list|,
argument|GV *
argument_list|)
end_macro

begin_comment
comment|/* this one needs to be moved to thrdvar.h and accessed via  * find_threadsv() when USE_THREADS */
end_comment

begin_macro
name|PERLVAR
argument_list|(
argument|Ireplgv
argument_list|,
argument|GV *
argument_list|)
end_macro

begin_comment
comment|/* shortcuts to misc objects */
end_comment

begin_macro
name|PERLVAR
argument_list|(
argument|Ierrgv
argument_list|,
argument|GV *
argument_list|)
end_macro

begin_comment
comment|/* shortcuts to debugging objects */
end_comment

begin_macro
name|PERLVAR
argument_list|(
argument|IDBgv
argument_list|,
argument|GV *
argument_list|)
end_macro

begin_macro
name|PERLVAR
argument_list|(
argument|IDBline
argument_list|,
argument|GV *
argument_list|)
end_macro

begin_macro
name|PERLVAR
argument_list|(
argument|IDBsub
argument_list|,
argument|GV *
argument_list|)
end_macro

begin_macro
name|PERLVAR
argument_list|(
argument|IDBsingle
argument_list|,
argument|SV *
argument_list|)
end_macro

begin_macro
name|PERLVAR
argument_list|(
argument|IDBtrace
argument_list|,
argument|SV *
argument_list|)
end_macro

begin_macro
name|PERLVAR
argument_list|(
argument|IDBsignal
argument_list|,
argument|SV *
argument_list|)
end_macro

begin_macro
name|PERLVAR
argument_list|(
argument|Ilineary
argument_list|,
argument|AV *
argument_list|)
end_macro

begin_comment
comment|/* lines of script for debugger */
end_comment

begin_macro
name|PERLVAR
argument_list|(
argument|Idbargs
argument_list|,
argument|AV *
argument_list|)
end_macro

begin_comment
comment|/* args to call listed by caller function */
end_comment

begin_comment
comment|/* symbol tables */
end_comment

begin_macro
name|PERLVAR
argument_list|(
argument|Idebstash
argument_list|,
argument|HV *
argument_list|)
end_macro

begin_comment
comment|/* symbol table for perldb package */
end_comment

begin_macro
name|PERLVAR
argument_list|(
argument|Iglobalstash
argument_list|,
argument|HV *
argument_list|)
end_macro

begin_comment
comment|/* global keyword overrides imported here */
end_comment

begin_macro
name|PERLVAR
argument_list|(
argument|Icurstname
argument_list|,
argument|SV *
argument_list|)
end_macro

begin_comment
comment|/* name of current package */
end_comment

begin_macro
name|PERLVAR
argument_list|(
argument|Ibeginav
argument_list|,
argument|AV *
argument_list|)
end_macro

begin_comment
comment|/* names of BEGIN subroutines */
end_comment

begin_macro
name|PERLVAR
argument_list|(
argument|Iendav
argument_list|,
argument|AV *
argument_list|)
end_macro

begin_comment
comment|/* names of END subroutines */
end_comment

begin_macro
name|PERLVAR
argument_list|(
argument|Iinitav
argument_list|,
argument|AV *
argument_list|)
end_macro

begin_comment
comment|/* names of INIT subroutines */
end_comment

begin_macro
name|PERLVAR
argument_list|(
argument|Istrtab
argument_list|,
argument|HV *
argument_list|)
end_macro

begin_comment
comment|/* shared string table */
end_comment

begin_macro
name|PERLVARI
argument_list|(
argument|Isub_generation
argument_list|,
argument|U32
argument_list|,
literal|1
argument_list|)
end_macro

begin_comment
comment|/* incr to invalidate method cache */
end_comment

begin_comment
comment|/* memory management */
end_comment

begin_macro
name|PERLVAR
argument_list|(
argument|Isv_count
argument_list|,
argument|I32
argument_list|)
end_macro

begin_comment
comment|/* how many SV* are currently allocated */
end_comment

begin_macro
name|PERLVAR
argument_list|(
argument|Isv_objcount
argument_list|,
argument|I32
argument_list|)
end_macro

begin_comment
comment|/* how many objects are currently allocated */
end_comment

begin_macro
name|PERLVAR
argument_list|(
argument|Isv_root
argument_list|,
argument|SV*
argument_list|)
end_macro

begin_comment
comment|/* storage for SVs belonging to interp */
end_comment

begin_macro
name|PERLVAR
argument_list|(
argument|Isv_arenaroot
argument_list|,
argument|SV*
argument_list|)
end_macro

begin_comment
comment|/* list of areas for garbage collection */
end_comment

begin_comment
comment|/* funky return mechanisms */
end_comment

begin_macro
name|PERLVAR
argument_list|(
argument|Ilastspbase
argument_list|,
argument|I32
argument_list|)
end_macro

begin_macro
name|PERLVAR
argument_list|(
argument|Ilastsize
argument_list|,
argument|I32
argument_list|)
end_macro

begin_macro
name|PERLVAR
argument_list|(
argument|Iforkprocess
argument_list|,
argument|int
argument_list|)
end_macro

begin_comment
comment|/* so do_open |- can return proc# */
end_comment

begin_comment
comment|/* subprocess state */
end_comment

begin_macro
name|PERLVAR
argument_list|(
argument|Ifdpid
argument_list|,
argument|AV *
argument_list|)
end_macro

begin_comment
comment|/* keep fd-to-pid mappings for my_popen */
end_comment

begin_comment
comment|/* internal state */
end_comment

begin_macro
name|PERLVAR
argument_list|(
argument|Itainting
argument_list|,
argument|bool
argument_list|)
end_macro

begin_comment
comment|/* doing taint checks */
end_comment

begin_macro
name|PERLVARI
argument_list|(
argument|Iop_mask
argument_list|,
argument|char *
argument_list|,
argument|NULL
argument_list|)
end_macro

begin_comment
comment|/* masked operations for safe evals */
end_comment

begin_macro
name|PERLVAR
argument_list|(
argument|Ilast_proto
argument_list|,
argument|char *
argument_list|)
end_macro

begin_comment
comment|/* Prototype of last sub seen. */
end_comment

begin_comment
comment|/* trace state */
end_comment

begin_macro
name|PERLVAR
argument_list|(
argument|Idlevel
argument_list|,
argument|I32
argument_list|)
end_macro

begin_macro
name|PERLVARI
argument_list|(
argument|Idlmax
argument_list|,
argument|I32
argument_list|,
literal|128
argument_list|)
end_macro

begin_macro
name|PERLVAR
argument_list|(
argument|Idebname
argument_list|,
argument|char *
argument_list|)
end_macro

begin_macro
name|PERLVAR
argument_list|(
argument|Idebdelim
argument_list|,
argument|char *
argument_list|)
end_macro

begin_comment
comment|/* current interpreter roots */
end_comment

begin_macro
name|PERLVAR
argument_list|(
argument|Imain_cv
argument_list|,
argument|CV *
argument_list|)
end_macro

begin_macro
name|PERLVAR
argument_list|(
argument|Imain_root
argument_list|,
argument|OP *
argument_list|)
end_macro

begin_macro
name|PERLVAR
argument_list|(
argument|Imain_start
argument_list|,
argument|OP *
argument_list|)
end_macro

begin_macro
name|PERLVAR
argument_list|(
argument|Ieval_root
argument_list|,
argument|OP *
argument_list|)
end_macro

begin_macro
name|PERLVAR
argument_list|(
argument|Ieval_start
argument_list|,
argument|OP *
argument_list|)
end_macro

begin_comment
comment|/* runtime control stuff */
end_comment

begin_macro
name|PERLVARI
argument_list|(
argument|Icurcopdb
argument_list|,
argument|COP *
argument_list|,
argument|NULL
argument_list|)
end_macro

begin_macro
name|PERLVARI
argument_list|(
argument|Icopline
argument_list|,
argument|line_t
argument_list|,
argument|NOLINE
argument_list|)
end_macro

begin_comment
comment|/* statics moved here for shared library purposes */
end_comment

begin_macro
name|PERLVAR
argument_list|(
argument|Istrchop
argument_list|,
argument|SV
argument_list|)
end_macro

begin_comment
comment|/* return value from chop */
end_comment

begin_macro
name|PERLVAR
argument_list|(
argument|Ifilemode
argument_list|,
argument|int
argument_list|)
end_macro

begin_comment
comment|/* so nextargv() can preserve mode */
end_comment

begin_macro
name|PERLVAR
argument_list|(
argument|Ilastfd
argument_list|,
argument|int
argument_list|)
end_macro

begin_comment
comment|/* what to preserve mode on */
end_comment

begin_macro
name|PERLVAR
argument_list|(
argument|Ioldname
argument_list|,
argument|char *
argument_list|)
end_macro

begin_comment
comment|/* what to preserve mode on */
end_comment

begin_macro
name|PERLVAR
argument_list|(
argument|IArgv
argument_list|,
argument|char **
argument_list|)
end_macro

begin_comment
comment|/* stuff to free from do_aexec, vfork safe */
end_comment

begin_macro
name|PERLVAR
argument_list|(
argument|ICmd
argument_list|,
argument|char *
argument_list|)
end_macro

begin_comment
comment|/* stuff to free from do_aexec, vfork safe */
end_comment

begin_macro
name|PERLVAR
argument_list|(
argument|Imystrk
argument_list|,
argument|SV *
argument_list|)
end_macro

begin_comment
comment|/* temp key string for do_each() */
end_comment

begin_macro
name|PERLVAR
argument_list|(
argument|Idumplvl
argument_list|,
argument|I32
argument_list|)
end_macro

begin_comment
comment|/* indentation level on syntax tree dump */
end_comment

begin_macro
name|PERLVAR
argument_list|(
argument|Ioldlastpm
argument_list|,
argument|PMOP *
argument_list|)
end_macro

begin_comment
comment|/* for saving regexp context in debugger */
end_comment

begin_macro
name|PERLVAR
argument_list|(
argument|Igensym
argument_list|,
argument|I32
argument_list|)
end_macro

begin_comment
comment|/* next symbol for getsym() to define */
end_comment

begin_macro
name|PERLVAR
argument_list|(
argument|Ipreambled
argument_list|,
argument|bool
argument_list|)
end_macro

begin_macro
name|PERLVAR
argument_list|(
argument|Ipreambleav
argument_list|,
argument|AV *
argument_list|)
end_macro

begin_macro
name|PERLVARI
argument_list|(
argument|Ilaststatval
argument_list|,
argument|int
argument_list|,
argument|-
literal|1
argument_list|)
end_macro

begin_macro
name|PERLVARI
argument_list|(
argument|Ilaststype
argument_list|,
argument|I32
argument_list|,
argument|OP_STAT
argument_list|)
end_macro

begin_macro
name|PERLVAR
argument_list|(
argument|Imess_sv
argument_list|,
argument|SV *
argument_list|)
end_macro

begin_comment
comment|/* XXX shouldn't these be per-thread? --GSAR */
end_comment

begin_macro
name|PERLVAR
argument_list|(
argument|Iors
argument_list|,
argument|char *
argument_list|)
end_macro

begin_comment
comment|/* output record separator $\ */
end_comment

begin_macro
name|PERLVAR
argument_list|(
argument|Iorslen
argument_list|,
argument|STRLEN
argument_list|)
end_macro

begin_macro
name|PERLVAR
argument_list|(
argument|Iofmt
argument_list|,
argument|char *
argument_list|)
end_macro

begin_comment
comment|/* output format for numbers $# */
end_comment

begin_comment
comment|/* interpreter atexit processing */
end_comment

begin_macro
name|PERLVARI
argument_list|(
argument|Iexitlist
argument_list|,
argument|PerlExitListEntry *
argument_list|,
argument|NULL
argument_list|)
end_macro

begin_comment
comment|/* list of exit functions */
end_comment

begin_macro
name|PERLVARI
argument_list|(
argument|Iexitlistlen
argument_list|,
argument|I32
argument_list|,
literal|0
argument_list|)
end_macro

begin_comment
comment|/* length of same */
end_comment

begin_macro
name|PERLVAR
argument_list|(
argument|Imodglobal
argument_list|,
argument|HV *
argument_list|)
end_macro

begin_comment
comment|/* per-interp module data */
end_comment

begin_comment
comment|/* these used to be in global before 5.004_68 */
end_comment

begin_macro
name|PERLVARI
argument_list|(
argument|Iprofiledata
argument_list|,
argument|U32 *
argument_list|,
argument|NULL
argument_list|)
end_macro

begin_comment
comment|/* table of ops, counts */
end_comment

begin_macro
name|PERLVARI
argument_list|(
argument|Irsfp
argument_list|,
argument|PerlIO * VOL
argument_list|,
argument|Nullfp
argument_list|)
end_macro

begin_comment
comment|/* current source file pointer */
end_comment

begin_macro
name|PERLVARI
argument_list|(
argument|Irsfp_filters
argument_list|,
argument|AV *
argument_list|,
argument|Nullav
argument_list|)
end_macro

begin_comment
comment|/* keeps active source filters */
end_comment

begin_macro
name|PERLVAR
argument_list|(
argument|Icompiling
argument_list|,
argument|COP
argument_list|)
end_macro

begin_comment
comment|/* compiling/done executing marker */
end_comment

begin_macro
name|PERLVAR
argument_list|(
argument|Icompcv
argument_list|,
argument|CV *
argument_list|)
end_macro

begin_comment
comment|/* currently compiling subroutine */
end_comment

begin_macro
name|PERLVAR
argument_list|(
argument|Icomppad
argument_list|,
argument|AV *
argument_list|)
end_macro

begin_comment
comment|/* storage for lexically scoped temporaries */
end_comment

begin_macro
name|PERLVAR
argument_list|(
argument|Icomppad_name
argument_list|,
argument|AV *
argument_list|)
end_macro

begin_comment
comment|/* variable names for "my" variables */
end_comment

begin_macro
name|PERLVAR
argument_list|(
argument|Icomppad_name_fill
argument_list|,
argument|I32
argument_list|)
end_macro

begin_comment
comment|/* last "introduced" variable offset */
end_comment

begin_macro
name|PERLVAR
argument_list|(
argument|Icomppad_name_floor
argument_list|,
argument|I32
argument_list|)
end_macro

begin_comment
comment|/* start of vars in innermost block */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_INTERP_INTERN
end_ifdef

begin_macro
name|PERLVAR
argument_list|(
argument|Isys_intern
argument_list|,
argument|struct interp_intern
argument_list|)
end_macro

begin_comment
comment|/* platform internals */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* more statics moved here */
end_comment

begin_macro
name|PERLVARI
argument_list|(
argument|Igeneration
argument_list|,
argument|int
argument_list|,
literal|100
argument_list|)
end_macro

begin_comment
comment|/* from op.c */
end_comment

begin_macro
name|PERLVAR
argument_list|(
argument|IDBcv
argument_list|,
argument|CV *
argument_list|)
end_macro

begin_comment
comment|/* from perl.c */
end_comment

begin_macro
name|PERLVAR
argument_list|(
argument|Iarchpat_auto
argument_list|,
argument|char*
argument_list|)
end_macro

begin_comment
comment|/* from perl.c */
end_comment

begin_macro
name|PERLVARI
argument_list|(
argument|Iin_clean_objs
argument_list|,
argument|bool
argument_list|,
argument|FALSE
argument_list|)
end_macro

begin_comment
comment|/* from sv.c */
end_comment

begin_macro
name|PERLVARI
argument_list|(
argument|Iin_clean_all
argument_list|,
argument|bool
argument_list|,
argument|FALSE
argument_list|)
end_macro

begin_comment
comment|/* from sv.c */
end_comment

begin_macro
name|PERLVAR
argument_list|(
argument|Ilinestart
argument_list|,
argument|char *
argument_list|)
end_macro

begin_comment
comment|/* beg. of most recently read line */
end_comment

begin_macro
name|PERLVAR
argument_list|(
argument|Ipending_ident
argument_list|,
argument|char
argument_list|)
end_macro

begin_comment
comment|/* pending identifier lookup */
end_comment

begin_macro
name|PERLVAR
argument_list|(
argument|Isublex_info
argument_list|,
argument|SUBLEXINFO
argument_list|)
end_macro

begin_comment
comment|/* from toke.c */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|USE_THREADS
end_ifdef

begin_macro
name|PERLVAR
argument_list|(
argument|Ithrsv
argument_list|,
argument|SV *
argument_list|)
end_macro

begin_comment
comment|/* struct perl_thread for main thread */
end_comment

begin_macro
name|PERLVARI
argument_list|(
argument|Ithreadnum
argument_list|,
argument|U32
argument_list|,
literal|0
argument_list|)
end_macro

begin_comment
comment|/* incremented each thread creation */
end_comment

begin_macro
name|PERLVAR
argument_list|(
argument|Istrtab_mutex
argument_list|,
argument|perl_mutex
argument_list|)
end_macro

begin_comment
comment|/* Mutex for string table access */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* USE_THREADS */
end_comment

begin_macro
name|PERLVARI
argument_list|(
argument|Ibytecode_iv_overflows
argument_list|,
argument|int
argument_list|,
literal|0
argument_list|)
end_macro

begin_comment
comment|/* from bytecode.h */
end_comment

begin_macro
name|PERLVAR
argument_list|(
argument|Ibytecode_sv
argument_list|,
argument|SV *
argument_list|)
end_macro

begin_macro
name|PERLVAR
argument_list|(
argument|Ibytecode_pv
argument_list|,
argument|XPV
argument_list|)
end_macro

begin_macro
name|PERLVAR
argument_list|(
argument|Ibytecode_obj_list
argument_list|,
argument|void **
argument_list|)
end_macro

begin_macro
name|PERLVARI
argument_list|(
argument|Ibytecode_obj_list_fill
argument_list|,
argument|I32
argument_list|,
argument|-
literal|1
argument_list|)
end_macro

begin_ifdef
ifdef|#
directive|ifdef
name|PERL_OBJECT
end_ifdef

begin_macro
name|PERLVARI
argument_list|(
argument|piMem
argument_list|,
argument|IPerlMem*
argument_list|,
argument|NULL
argument_list|)
end_macro

begin_macro
name|PERLVARI
argument_list|(
argument|piENV
argument_list|,
argument|IPerlEnv*
argument_list|,
argument|NULL
argument_list|)
end_macro

begin_macro
name|PERLVARI
argument_list|(
argument|piStdIO
argument_list|,
argument|IPerlStdIO*
argument_list|,
argument|NULL
argument_list|)
end_macro

begin_macro
name|PERLVARI
argument_list|(
argument|piLIO
argument_list|,
argument|IPerlLIO*
argument_list|,
argument|NULL
argument_list|)
end_macro

begin_macro
name|PERLVARI
argument_list|(
argument|piDir
argument_list|,
argument|IPerlDir*
argument_list|,
argument|NULL
argument_list|)
end_macro

begin_macro
name|PERLVARI
argument_list|(
argument|piSock
argument_list|,
argument|IPerlSock*
argument_list|,
argument|NULL
argument_list|)
end_macro

begin_macro
name|PERLVARI
argument_list|(
argument|piProc
argument_list|,
argument|IPerlProc*
argument_list|,
argument|NULL
argument_list|)
end_macro

begin_endif
endif|#
directive|endif
end_endif

end_unit

