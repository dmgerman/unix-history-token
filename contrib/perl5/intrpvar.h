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
comment|/* The 'I' prefix is only needed for vars that need appropriate #defines  * generated when built with or without MULTIPLICITY.  It is also used  * to generate the appropriate export list for win32.  *  * When building without MULTIPLICITY, these variables will be truly global. */
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
argument|Ipatchlevel
argument_list|,
argument|SV *
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

begin_comment
comment|/* =for apidoc mn|bool|PL_dowarn  The C variable which corresponds to Perl's $^W warning variable.  =cut */
end_comment

begin_macro
name|PERLVAR
argument_list|(
argument|Idowarn
argument_list|,
argument|U8
argument_list|)
end_macro

begin_macro
name|PERLVAR
argument_list|(
argument|Iwidesyscalls
argument_list|,
argument|bool
argument_list|)
end_macro

begin_comment
comment|/* wide system calls */
end_comment

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
comment|/* This value may be set when embedding for full cleanup  */
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

begin_macro
name|PERLVAR
argument_list|(
argument|Iexit_flags
argument_list|,
argument|U8
argument_list|)
end_macro

begin_comment
comment|/* was exit() unexpected, etc. */
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
argument|Istderrgv
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

begin_macro
name|PERLVAR
argument_list|(
argument|Iargvout_stack
argument_list|,
argument|AV *
argument_list|)
end_macro

begin_comment
comment|/* shortcuts to regexp stuff */
end_comment

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

begin_comment
comment|/* =for apidoc mn|GV *|PL_DBsub When Perl is run in debugging mode, with the B<-d> switch, this GV contains the SV which holds the name of the sub being debugged.  This is the C variable which corresponds to Perl's $DB::sub variable.  See C<PL_DBsingle>.  =for apidoc mn|SV *|PL_DBsingle When Perl is run in debugging mode, with the B<-d> switch, this SV is a boolean which indicates whether subs are being single-stepped.  Single-stepping is automatically turned on after every step.  This is the C variable which corresponds to Perl's $DB::single variable.  See C<PL_DBsub>.  =for apidoc mn|SV *|PL_DBtrace Trace variable used when Perl is run in debugging mode, with the B<-d> switch.  This is the C variable which corresponds to Perl's $DB::trace variable.  See C<PL_DBsingle>.  =cut */
end_comment

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
argument|Icheckav
argument_list|,
argument|AV *
argument_list|)
end_macro

begin_comment
comment|/* names of CHECK subroutines */
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

begin_comment
comment|/* =for apidoc Amn|HV*|PL_modglobal  C<PL_modglobal> is a general purpose, interpreter global HV for use by  extensions that need to keep information on a per-interpreter basis. In a pinch, it can also be used as a symbol table for extensions  to share data among each other.  It is a good idea to use keys  prefixed by the package name of the extension that owns the data.  =cut */
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
name|PERLVAR
argument_list|(
argument|Iuid
argument_list|,
argument|Uid_t
argument_list|)
end_macro

begin_comment
comment|/* current real user id */
end_comment

begin_macro
name|PERLVAR
argument_list|(
argument|Ieuid
argument_list|,
argument|Uid_t
argument_list|)
end_macro

begin_comment
comment|/* current effective user id */
end_comment

begin_macro
name|PERLVAR
argument_list|(
argument|Igid
argument_list|,
argument|Gid_t
argument_list|)
end_macro

begin_comment
comment|/* current real group id */
end_comment

begin_macro
name|PERLVAR
argument_list|(
argument|Iegid
argument_list|,
argument|Gid_t
argument_list|)
end_macro

begin_comment
comment|/* current effective group id */
end_comment

begin_macro
name|PERLVAR
argument_list|(
argument|Inomemok
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
argument|Ian
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
argument|Icop_seqmax
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
argument|Iop_seqmax
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
argument|Ievalseq
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
argument|Iorigenviron
argument_list|,
argument|char **
argument_list|)
end_macro

begin_macro
name|PERLVAR
argument_list|(
argument|Iorigalen
argument_list|,
argument|U32
argument_list|)
end_macro

begin_macro
name|PERLVAR
argument_list|(
argument|Ipidstatus
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
argument|Imaxo
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
argument|Iosname
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
argument|Ish_path
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
argument|Isighandlerp
argument_list|,
argument|Sighandler_t
argument_list|)
end_macro

begin_macro
name|PERLVAR
argument_list|(
argument|Ixiv_arenaroot
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
argument|Ixiv_root
argument_list|,
argument|IV *
argument_list|)
end_macro

begin_comment
comment|/* free xiv list */
end_comment

begin_macro
name|PERLVAR
argument_list|(
argument|Ixnv_root
argument_list|,
argument|NV *
argument_list|)
end_macro

begin_comment
comment|/* free xnv list */
end_comment

begin_macro
name|PERLVAR
argument_list|(
argument|Ixrv_root
argument_list|,
argument|XRV *
argument_list|)
end_macro

begin_comment
comment|/* free xrv list */
end_comment

begin_macro
name|PERLVAR
argument_list|(
argument|Ixpv_root
argument_list|,
argument|XPV *
argument_list|)
end_macro

begin_comment
comment|/* free xpv list */
end_comment

begin_macro
name|PERLVAR
argument_list|(
argument|Ixpviv_root
argument_list|,
argument|XPVIV *
argument_list|)
end_macro

begin_comment
comment|/* free xpviv list */
end_comment

begin_macro
name|PERLVAR
argument_list|(
argument|Ixpvnv_root
argument_list|,
argument|XPVNV *
argument_list|)
end_macro

begin_comment
comment|/* free xpvnv list */
end_comment

begin_macro
name|PERLVAR
argument_list|(
argument|Ixpvcv_root
argument_list|,
argument|XPVCV *
argument_list|)
end_macro

begin_comment
comment|/* free xpvcv list */
end_comment

begin_macro
name|PERLVAR
argument_list|(
argument|Ixpvav_root
argument_list|,
argument|XPVAV *
argument_list|)
end_macro

begin_comment
comment|/* free xpvav list */
end_comment

begin_macro
name|PERLVAR
argument_list|(
argument|Ixpvhv_root
argument_list|,
argument|XPVHV *
argument_list|)
end_macro

begin_comment
comment|/* free xpvhv list */
end_comment

begin_macro
name|PERLVAR
argument_list|(
argument|Ixpvmg_root
argument_list|,
argument|XPVMG *
argument_list|)
end_macro

begin_comment
comment|/* free xpvmg list */
end_comment

begin_macro
name|PERLVAR
argument_list|(
argument|Ixpvlv_root
argument_list|,
argument|XPVLV *
argument_list|)
end_macro

begin_comment
comment|/* free xpvlv list */
end_comment

begin_macro
name|PERLVAR
argument_list|(
argument|Ixpvbm_root
argument_list|,
argument|XPVBM *
argument_list|)
end_macro

begin_comment
comment|/* free xpvbm list */
end_comment

begin_macro
name|PERLVAR
argument_list|(
argument|Ihe_root
argument_list|,
argument|HE *
argument_list|)
end_macro

begin_comment
comment|/* free he list */
end_comment

begin_macro
name|PERLVAR
argument_list|(
argument|Inice_chunk
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
argument|Inice_chunk_size
argument_list|,
argument|U32
argument_list|)
end_macro

begin_comment
comment|/* how nice the chunk of memory is */
end_comment

begin_macro
name|PERLVARI
argument_list|(
argument|Irunops
argument_list|,
argument|runops_proc_t
argument_list|,
argument|MEMBER_TO_FPTR(RUNOPS_DEFAULT)
argument_list|)
end_macro

begin_macro
name|PERLVARA
argument_list|(
argument|Itokenbuf
argument_list|,
literal|256
argument_list|,
argument|char
argument_list|)
end_macro

begin_comment
comment|/* =for apidoc Amn|SV|PL_sv_undef This is the C<undef> SV.  Always refer to this as C<&PL_sv_undef>.  =for apidoc Amn|SV|PL_sv_no This is the C<false> SV.  See C<PL_sv_yes>.  Always refer to this as C<&PL_sv_no>.  =for apidoc Amn|SV|PL_sv_yes This is the C<true> SV.  See C<PL_sv_no>.  Always refer to this as C<&PL_sv_yes>.  =cut */
end_comment

begin_macro
name|PERLVAR
argument_list|(
argument|Isv_undef
argument_list|,
argument|SV
argument_list|)
end_macro

begin_macro
name|PERLVAR
argument_list|(
argument|Isv_no
argument_list|,
argument|SV
argument_list|)
end_macro

begin_macro
name|PERLVAR
argument_list|(
argument|Isv_yes
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
argument|Icshname
argument_list|,
argument|char *
argument_list|,
argument|CSH
argument_list|)
end_macro

begin_macro
name|PERLVAR
argument_list|(
argument|Icshlen
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
argument|Ilex_state
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
argument|Ilex_defer
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
argument|Ilex_expect
argument_list|,
argument|int
argument_list|)
end_macro

begin_comment
comment|/* expect after determined token */
end_comment

begin_macro
name|PERLVAR
argument_list|(
argument|Ilex_brackets
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
argument|Ilex_formbrack
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
argument|Ilex_casemods
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
argument|Ilex_dojoin
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
argument|Ilex_starts
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
argument|Ilex_stuff
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
argument|Ilex_repl
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
argument|Ilex_op
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
argument|Ilex_inpat
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
argument|Ilex_inwhat
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
argument|Ilex_brackstack
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
argument|Ilex_casestack
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
name|PERLVARA
argument_list|(
argument|Inextval
argument_list|,
literal|5
argument_list|,
argument|YYSTYPE
argument_list|)
end_macro

begin_comment
comment|/* value of next token, if any */
end_comment

begin_macro
name|PERLVARA
argument_list|(
argument|Inexttype
argument_list|,
literal|5
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
argument|Inexttoke
argument_list|,
argument|I32
argument_list|)
end_macro

begin_macro
name|PERLVAR
argument_list|(
argument|Ilinestr
argument_list|,
argument|SV *
argument_list|)
end_macro

begin_macro
name|PERLVAR
argument_list|(
argument|Ibufptr
argument_list|,
argument|char *
argument_list|)
end_macro

begin_macro
name|PERLVAR
argument_list|(
argument|Ioldbufptr
argument_list|,
argument|char *
argument_list|)
end_macro

begin_macro
name|PERLVAR
argument_list|(
argument|Ioldoldbufptr
argument_list|,
argument|char *
argument_list|)
end_macro

begin_macro
name|PERLVAR
argument_list|(
argument|Ibufend
argument_list|,
argument|char *
argument_list|)
end_macro

begin_macro
name|PERLVARI
argument_list|(
argument|Iexpect
argument_list|,
argument|int
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
argument|Imulti_start
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
argument|Imulti_end
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
argument|Imulti_open
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
argument|Imulti_close
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
argument|Ierror_count
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
argument|Isubline
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
argument|Isubname
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
argument|Imin_intro_pending
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
argument|Imax_intro_pending
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
argument|Ipadix
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
argument|Ipadix_floor
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
argument|Ipad_reset_pending
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
argument|Ilast_uni
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
argument|Ilast_lop
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
argument|Ilast_lop_op
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
argument|Iin_my
argument_list|,
argument|I32
argument_list|)
end_macro

begin_comment
comment|/* we're compiling a "my" (or "our") declaration */
end_comment

begin_macro
name|PERLVAR
argument_list|(
argument|Iin_my_stash
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
argument|Icryptseen
argument_list|,
argument|bool
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
argument|Ihints
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
argument|Idebug
argument_list|,
argument|VOL U32
argument_list|)
end_macro

begin_comment
comment|/* flags given to -D switch */
end_comment

begin_macro
name|PERLVAR
argument_list|(
argument|Iamagic_generation
argument_list|,
argument|long
argument_list|)
end_macro

begin_ifdef
ifdef|#
directive|ifdef
name|USE_LOCALE_COLLATE
end_ifdef

begin_macro
name|PERLVAR
argument_list|(
argument|Icollation_ix
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
argument|Icollation_name
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
argument|Icollation_standard
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
argument|Icollxfrm_base
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
argument|Icollxfrm_mult
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
argument|Inumeric_name
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
argument|Inumeric_standard
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
argument|Inumeric_local
argument_list|,
argument|bool
argument_list|,
argument|TRUE
argument_list|)
end_macro

begin_comment
comment|/* Assume local numerics */
end_comment

begin_macro
name|PERLVAR
argument_list|(
argument|Idummy1_bincompat
argument_list|,
argument|char
argument_list|)
end_macro

begin_comment
comment|/* Used to be numeric_radix */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !USE_LOCALE_NUMERIC */
end_comment

begin_comment
comment|/* utf8 character classes */
end_comment

begin_macro
name|PERLVAR
argument_list|(
argument|Iutf8_alnum
argument_list|,
argument|SV *
argument_list|)
end_macro

begin_macro
name|PERLVAR
argument_list|(
argument|Iutf8_alnumc
argument_list|,
argument|SV *
argument_list|)
end_macro

begin_macro
name|PERLVAR
argument_list|(
argument|Iutf8_ascii
argument_list|,
argument|SV *
argument_list|)
end_macro

begin_macro
name|PERLVAR
argument_list|(
argument|Iutf8_alpha
argument_list|,
argument|SV *
argument_list|)
end_macro

begin_macro
name|PERLVAR
argument_list|(
argument|Iutf8_space
argument_list|,
argument|SV *
argument_list|)
end_macro

begin_macro
name|PERLVAR
argument_list|(
argument|Iutf8_cntrl
argument_list|,
argument|SV *
argument_list|)
end_macro

begin_macro
name|PERLVAR
argument_list|(
argument|Iutf8_graph
argument_list|,
argument|SV *
argument_list|)
end_macro

begin_macro
name|PERLVAR
argument_list|(
argument|Iutf8_digit
argument_list|,
argument|SV *
argument_list|)
end_macro

begin_macro
name|PERLVAR
argument_list|(
argument|Iutf8_upper
argument_list|,
argument|SV *
argument_list|)
end_macro

begin_macro
name|PERLVAR
argument_list|(
argument|Iutf8_lower
argument_list|,
argument|SV *
argument_list|)
end_macro

begin_macro
name|PERLVAR
argument_list|(
argument|Iutf8_print
argument_list|,
argument|SV *
argument_list|)
end_macro

begin_macro
name|PERLVAR
argument_list|(
argument|Iutf8_punct
argument_list|,
argument|SV *
argument_list|)
end_macro

begin_macro
name|PERLVAR
argument_list|(
argument|Iutf8_xdigit
argument_list|,
argument|SV *
argument_list|)
end_macro

begin_macro
name|PERLVAR
argument_list|(
argument|Iutf8_mark
argument_list|,
argument|SV *
argument_list|)
end_macro

begin_macro
name|PERLVAR
argument_list|(
argument|Iutf8_toupper
argument_list|,
argument|SV *
argument_list|)
end_macro

begin_macro
name|PERLVAR
argument_list|(
argument|Iutf8_totitle
argument_list|,
argument|SV *
argument_list|)
end_macro

begin_macro
name|PERLVAR
argument_list|(
argument|Iutf8_tolower
argument_list|,
argument|SV *
argument_list|)
end_macro

begin_macro
name|PERLVAR
argument_list|(
argument|Ilast_swash_hv
argument_list|,
argument|HV *
argument_list|)
end_macro

begin_macro
name|PERLVAR
argument_list|(
argument|Ilast_swash_klen
argument_list|,
argument|U32
argument_list|)
end_macro

begin_macro
name|PERLVARA
argument_list|(
argument|Ilast_swash_key
argument_list|,
literal|10
argument_list|,
argument|U8
argument_list|)
end_macro

begin_macro
name|PERLVAR
argument_list|(
argument|Ilast_swash_tmps
argument_list|,
argument|U8 *
argument_list|)
end_macro

begin_macro
name|PERLVAR
argument_list|(
argument|Ilast_swash_slen
argument_list|,
argument|STRLEN
argument_list|)
end_macro

begin_comment
comment|/* perly.c globals */
end_comment

begin_macro
name|PERLVAR
argument_list|(
argument|Iyydebug
argument_list|,
argument|int
argument_list|)
end_macro

begin_macro
name|PERLVAR
argument_list|(
argument|Iyynerrs
argument_list|,
argument|int
argument_list|)
end_macro

begin_macro
name|PERLVAR
argument_list|(
argument|Iyyerrflag
argument_list|,
argument|int
argument_list|)
end_macro

begin_macro
name|PERLVAR
argument_list|(
argument|Iyychar
argument_list|,
argument|int
argument_list|)
end_macro

begin_macro
name|PERLVAR
argument_list|(
argument|Iyyval
argument_list|,
argument|YYSTYPE
argument_list|)
end_macro

begin_macro
name|PERLVAR
argument_list|(
argument|Iyylval
argument_list|,
argument|YYSTYPE
argument_list|)
end_macro

begin_macro
name|PERLVAR
argument_list|(
argument|Iglob_index
argument_list|,
argument|int
argument_list|)
end_macro

begin_macro
name|PERLVAR
argument_list|(
argument|Isrand_called
argument_list|,
argument|bool
argument_list|)
end_macro

begin_macro
name|PERLVARA
argument_list|(
argument|Iuudmap
argument_list|,
literal|256
argument_list|,
argument|char
argument_list|)
end_macro

begin_macro
name|PERLVAR
argument_list|(
argument|Ibitcount
argument_list|,
argument|char *
argument_list|)
end_macro

begin_ifdef
ifdef|#
directive|ifdef
name|USE_THREADS
end_ifdef

begin_macro
name|PERLVAR
argument_list|(
argument|Isv_mutex
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
argument|Ieval_mutex
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
argument|Ieval_cond
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
argument|Ieval_owner
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
argument|Inthreads
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
argument|Ithreads_mutex
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
argument|Inthreads_cond
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
argument|Isvref_mutex
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
argument|Ithreadsv_names
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
argument|Icurthr
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

begin_macro
name|PERLVAR
argument_list|(
argument|Icred_mutex
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

begin_comment
comment|/* USE_THREADS */
end_comment

begin_macro
name|PERLVAR
argument_list|(
argument|Ipsig_ptr
argument_list|,
argument|SV**
argument_list|)
end_macro

begin_macro
name|PERLVAR
argument_list|(
argument|Ipsig_name
argument_list|,
argument|SV**
argument_list|)
end_macro

begin_if
if|#
directive|if
name|defined
argument_list|(
name|PERL_IMPLICIT_SYS
argument_list|)
end_if

begin_macro
name|PERLVAR
argument_list|(
argument|IMem
argument_list|,
argument|struct IPerlMem*
argument_list|)
end_macro

begin_macro
name|PERLVAR
argument_list|(
argument|IMemShared
argument_list|,
argument|struct IPerlMem*
argument_list|)
end_macro

begin_macro
name|PERLVAR
argument_list|(
argument|IMemParse
argument_list|,
argument|struct IPerlMem*
argument_list|)
end_macro

begin_macro
name|PERLVAR
argument_list|(
argument|IEnv
argument_list|,
argument|struct IPerlEnv*
argument_list|)
end_macro

begin_macro
name|PERLVAR
argument_list|(
argument|IStdIO
argument_list|,
argument|struct IPerlStdIO*
argument_list|)
end_macro

begin_macro
name|PERLVAR
argument_list|(
argument|ILIO
argument_list|,
argument|struct IPerlLIO*
argument_list|)
end_macro

begin_macro
name|PERLVAR
argument_list|(
argument|IDir
argument_list|,
argument|struct IPerlDir*
argument_list|)
end_macro

begin_macro
name|PERLVAR
argument_list|(
argument|ISock
argument_list|,
argument|struct IPerlSock*
argument_list|)
end_macro

begin_macro
name|PERLVAR
argument_list|(
argument|IProc
argument_list|,
argument|struct IPerlProc*
argument_list|)
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|USE_ITHREADS
argument_list|)
end_if

begin_macro
name|PERLVAR
argument_list|(
argument|Iptr_table
argument_list|,
argument|PTR_TBL_t*
argument_list|)
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_macro
name|PERLVARI
argument_list|(
argument|Ibeginav_save
argument_list|,
argument|AV*
argument_list|,
argument|Nullav
argument_list|)
end_macro

begin_comment
comment|/* save BEGIN{}s when compiling */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|USE_THREADS
end_ifdef

begin_macro
name|PERLVAR
argument_list|(
argument|Ifdpid_mutex
argument_list|,
argument|perl_mutex
argument_list|)
end_macro

begin_comment
comment|/* mutex for fdpid array */
end_comment

begin_macro
name|PERLVAR
argument_list|(
argument|Isv_lock_mutex
argument_list|,
argument|perl_mutex
argument_list|)
end_macro

begin_comment
comment|/* mutex for SvLOCK macro */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_macro
name|PERLVAR
argument_list|(
argument|Inullstash
argument_list|,
argument|HV *
argument_list|)
end_macro

begin_comment
comment|/* illegal symbols end up here */
end_comment

begin_macro
name|PERLVAR
argument_list|(
argument|Ixnv_arenaroot
argument_list|,
argument|XPV*
argument_list|)
end_macro

begin_comment
comment|/* list of allocated xnv areas */
end_comment

begin_macro
name|PERLVAR
argument_list|(
argument|Ixrv_arenaroot
argument_list|,
argument|XPV*
argument_list|)
end_macro

begin_comment
comment|/* list of allocated xrv areas */
end_comment

begin_macro
name|PERLVAR
argument_list|(
argument|Ixpv_arenaroot
argument_list|,
argument|XPV*
argument_list|)
end_macro

begin_comment
comment|/* list of allocated xpv areas */
end_comment

begin_macro
name|PERLVAR
argument_list|(
argument|Ixpviv_arenaroot
argument_list|,
argument|XPVIV*
argument_list|)
end_macro

begin_comment
comment|/* list of allocated xpviv areas */
end_comment

begin_macro
name|PERLVAR
argument_list|(
argument|Ixpvnv_arenaroot
argument_list|,
argument|XPVNV*
argument_list|)
end_macro

begin_comment
comment|/* list of allocated xpvnv areas */
end_comment

begin_macro
name|PERLVAR
argument_list|(
argument|Ixpvcv_arenaroot
argument_list|,
argument|XPVCV*
argument_list|)
end_macro

begin_comment
comment|/* list of allocated xpvcv areas */
end_comment

begin_macro
name|PERLVAR
argument_list|(
argument|Ixpvav_arenaroot
argument_list|,
argument|XPVAV*
argument_list|)
end_macro

begin_comment
comment|/* list of allocated xpvav areas */
end_comment

begin_macro
name|PERLVAR
argument_list|(
argument|Ixpvhv_arenaroot
argument_list|,
argument|XPVHV*
argument_list|)
end_macro

begin_comment
comment|/* list of allocated xpvhv areas */
end_comment

begin_macro
name|PERLVAR
argument_list|(
argument|Ixpvmg_arenaroot
argument_list|,
argument|XPVMG*
argument_list|)
end_macro

begin_comment
comment|/* list of allocated xpvmg areas */
end_comment

begin_macro
name|PERLVAR
argument_list|(
argument|Ixpvlv_arenaroot
argument_list|,
argument|XPVLV*
argument_list|)
end_macro

begin_comment
comment|/* list of allocated xpvlv areas */
end_comment

begin_macro
name|PERLVAR
argument_list|(
argument|Ixpvbm_arenaroot
argument_list|,
argument|XPVBM*
argument_list|)
end_macro

begin_comment
comment|/* list of allocated xpvbm areas */
end_comment

begin_macro
name|PERLVAR
argument_list|(
argument|Ihe_arenaroot
argument_list|,
argument|XPV*
argument_list|)
end_macro

begin_comment
comment|/* list of allocated he areas */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|USE_LOCALE_NUMERIC
end_ifdef

begin_macro
name|PERLVAR
argument_list|(
argument|Inumeric_radix_sv
argument_list|,
argument|SV *
argument_list|)
end_macro

begin_comment
comment|/* The radix separator if not '.' */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* New variables must be added to the very end for binary compatibility.  * XSUB.h provides wrapper functions via perlapi.h that make this  * irrelevant, but not all code may be expected to #include XSUB.h. */
end_comment

end_unit

