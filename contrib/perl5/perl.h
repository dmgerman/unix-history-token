begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*    perl.h  *  *    Copyright (c) 1987-2001, Larry Wall  *  *    You may distribute under the terms of either the GNU General Public  *    License or the Artistic License, as specified in the README file.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|H_PERL
end_ifndef

begin_define
define|#
directive|define
name|H_PERL
value|1
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|PERL_FOR_X2P
end_ifdef

begin_comment
comment|/*  * This file is being used for x2p stuff.   * Above symbol is defined via -D in 'x2p/Makefile.SH'  * Decouple x2p stuff from some of perls more extreme eccentricities.   */
end_comment

begin_undef
undef|#
directive|undef
name|MULTIPLICITY
end_undef

begin_undef
undef|#
directive|undef
name|USE_STDIO
end_undef

begin_define
define|#
directive|define
name|USE_STDIO
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* PERL_FOR_X2P */
end_comment

begin_define
define|#
directive|define
name|VOIDUSED
value|1
end_define

begin_include
include|#
directive|include
file|"config.h"
end_include

begin_if
if|#
directive|if
name|defined
argument_list|(
name|USE_ITHREADS
argument_list|)
operator|&&
name|defined
argument_list|(
name|USE_5005THREADS
argument_list|)
end_if

begin_include
include|#
directive|include
file|"error: USE_ITHREADS and USE_5005THREADS are incompatible"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* XXX This next guard can disappear if the sources are revised    to use USE_5005THREADS throughout. -- A.D  1/6/2000 */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|USE_ITHREADS
argument_list|)
operator|&&
name|defined
argument_list|(
name|USE_THREADS
argument_list|)
end_if

begin_include
include|#
directive|include
file|"error: USE_ITHREADS and USE_THREADS are incompatible"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* See L<perlguts/"The Perl API"> for detailed notes on  * PERL_IMPLICIT_CONTEXT and PERL_IMPLICIT_SYS */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|USE_ITHREADS
end_ifdef

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|MULTIPLICITY
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|PERL_OBJECT
argument_list|)
end_if

begin_define
define|#
directive|define
name|MULTIPLICITY
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
name|USE_THREADS
end_ifdef

begin_ifndef
ifndef|#
directive|ifndef
name|PERL_IMPLICIT_CONTEXT
end_ifndef

begin_define
define|#
directive|define
name|PERL_IMPLICIT_CONTEXT
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|MULTIPLICITY
argument_list|)
end_if

begin_ifndef
ifndef|#
directive|ifndef
name|PERL_IMPLICIT_CONTEXT
end_ifndef

begin_define
define|#
directive|define
name|PERL_IMPLICIT_CONTEXT
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
name|PERL_CAPI
end_ifdef

begin_undef
undef|#
directive|undef
name|PERL_OBJECT
end_undef

begin_ifndef
ifndef|#
directive|ifndef
name|MULTIPLICITY
end_ifndef

begin_define
define|#
directive|define
name|MULTIPLICITY
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|PERL_IMPLICIT_CONTEXT
end_ifndef

begin_define
define|#
directive|define
name|PERL_IMPLICIT_CONTEXT
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|PERL_IMPLICIT_SYS
end_ifndef

begin_define
define|#
directive|define
name|PERL_IMPLICIT_SYS
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
name|PERL_OBJECT
end_ifdef

begin_ifndef
ifndef|#
directive|ifndef
name|PERL_IMPLICIT_CONTEXT
end_ifndef

begin_define
define|#
directive|define
name|PERL_IMPLICIT_CONTEXT
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|PERL_IMPLICIT_SYS
end_ifndef

begin_define
define|#
directive|define
name|PERL_IMPLICIT_SYS
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
name|PERL_OBJECT
end_ifdef

begin_comment
comment|/* PERL_OBJECT explained  - DickH and DougL @ ActiveState.com  Defining PERL_OBJECT turns on creation of a C++ object that contains all writable core perl global variables and functions. Stated another way, all necessary global variables and functions are members of a big C++ object. This object's class is CPerlObj. This allows a Perl Host to have multiple, independent perl interpreters in the same process space. This is very important on Win32 systems as the overhead of process creation is quite high -- this could be even higher than the script compile and execute time for small scripts.  The perl executable implementation on Win32 is composed of perl.exe (the Perl Host) and perlX.dll. (the Perl Core). This allows the same Perl Core to easily be embedded in other applications that use the perl interpreter.  +-----------+ | Perl Host | +-----------+       ^       |       v +-----------+   +-----------+ | Perl Core |<->| Extension | +-----------+   +-----------+ ...  Defining PERL_OBJECT has the following effects:  PERL CORE 1. CPerlObj is defined (this is the PERL_OBJECT) 2. all static functions that needed to access either global variables or functions needed are made member functions 3. all writable static variables are made member variables 4. all global variables and functions are defined as: 	#define var CPerlObj::PL_var 	#define func CPerlObj::Perl_func 	* these are in embed.h This necessitated renaming some local variables and functions that had the same name as a global variable or function. This was probably a _good_ thing anyway.   EXTENSIONS 1. Access to global variables and perl functions is through a pointer to the PERL_OBJECT. This pointer type is CPerlObj*. This is made transparent to extension developers by the following macros: 	#define var pPerl->PL_var 	#define func pPerl->Perl_func 	* these are done in objXSUB.h This requires that the extension be compiled as C++, which means that the code must be ANSI C and not K&R C. For K&R extensions, please see the C API notes located in Win32/GenCAPI.pl. This script creates a perlCAPI.lib that provides a K& R compatible C interface to the PERL_OBJECT. 2. Local variables and functions cannot have the same name as perl's variables or functions since the macros will redefine these. Look for this if you get some strange error message and it does not look like the code that you had written. This often happens with variables that are local to a function.  PERL HOST 1. The perl host is linked with perlX.lib to get perl_alloc. This function will return a pointer to CPerlObj (the PERL_OBJECT). It takes pointers to the various PerlXXX_YYY interfaces (see iperlsys.h for more information on this). 2. The perl host calls the same functions as normally would be called in setting up and running a perl script, except that the functions are now member functions of the PERL_OBJECT.  */
end_comment

begin_decl_stmt
name|class
name|CPerlObj
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|STATIC
end_define

begin_define
define|#
directive|define
name|CPERLscope
parameter_list|(
name|x
parameter_list|)
value|CPerlObj::x
end_define

begin_define
define|#
directive|define
name|CALL_FPTR
parameter_list|(
name|fptr
parameter_list|)
value|(aTHXo->*fptr)
end_define

begin_define
define|#
directive|define
name|pTHXo
value|CPerlObj *pPerl
end_define

begin_define
define|#
directive|define
name|pTHXo_
value|pTHXo,
end_define

begin_define
define|#
directive|define
name|aTHXo
value|this
end_define

begin_define
define|#
directive|define
name|aTHXo_
value|this,
end_define

begin_define
define|#
directive|define
name|PERL_OBJECT_THIS
value|aTHXo
end_define

begin_define
define|#
directive|define
name|PERL_OBJECT_THIS_
value|aTHXo_
end_define

begin_define
define|#
directive|define
name|dTHXoa
parameter_list|(
name|a
parameter_list|)
value|pTHXo = (CPerlObj*)a
end_define

begin_define
define|#
directive|define
name|dTHXo
value|pTHXo = PERL_GET_THX
end_define

begin_define
define|#
directive|define
name|pTHXx
value|void
end_define

begin_define
define|#
directive|define
name|pTHXx_
end_define

begin_define
define|#
directive|define
name|aTHXx
end_define

begin_define
define|#
directive|define
name|aTHXx_
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* !PERL_OBJECT */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|PERL_IMPLICIT_CONTEXT
end_ifdef

begin_ifdef
ifdef|#
directive|ifdef
name|USE_THREADS
end_ifdef

begin_struct_decl
struct_decl|struct
name|perl_thread
struct_decl|;
end_struct_decl

begin_define
define|#
directive|define
name|pTHX
value|register struct perl_thread *thr
end_define

begin_define
define|#
directive|define
name|aTHX
value|thr
end_define

begin_define
define|#
directive|define
name|dTHR
value|dNOOP
end_define

begin_comment
comment|/* only backward compatibility */
end_comment

begin_define
define|#
directive|define
name|dTHXa
parameter_list|(
name|a
parameter_list|)
value|pTHX = (struct perl_thread*)a
end_define

begin_else
else|#
directive|else
end_else

begin_ifndef
ifndef|#
directive|ifndef
name|MULTIPLICITY
end_ifndef

begin_define
define|#
directive|define
name|MULTIPLICITY
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|pTHX
value|register PerlInterpreter *my_perl
end_define

begin_define
define|#
directive|define
name|aTHX
value|my_perl
end_define

begin_define
define|#
directive|define
name|dTHXa
parameter_list|(
name|a
parameter_list|)
value|pTHX = (PerlInterpreter*)a
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|dTHX
value|pTHX = PERL_GET_THX
end_define

begin_define
define|#
directive|define
name|pTHX_
value|pTHX,
end_define

begin_define
define|#
directive|define
name|aTHX_
value|aTHX,
end_define

begin_define
define|#
directive|define
name|pTHX_1
value|2
end_define

begin_define
define|#
directive|define
name|pTHX_2
value|3
end_define

begin_define
define|#
directive|define
name|pTHX_3
value|4
end_define

begin_define
define|#
directive|define
name|pTHX_4
value|5
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|STATIC
value|static
end_define

begin_define
define|#
directive|define
name|CPERLscope
parameter_list|(
name|x
parameter_list|)
value|x
end_define

begin_define
define|#
directive|define
name|CPERLarg
value|void
end_define

begin_define
define|#
directive|define
name|CPERLarg_
end_define

begin_define
define|#
directive|define
name|_CPERLarg
end_define

begin_define
define|#
directive|define
name|PERL_OBJECT_THIS
end_define

begin_define
define|#
directive|define
name|_PERL_OBJECT_THIS
end_define

begin_define
define|#
directive|define
name|PERL_OBJECT_THIS_
end_define

begin_define
define|#
directive|define
name|CALL_FPTR
parameter_list|(
name|fptr
parameter_list|)
value|(*fptr)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* PERL_OBJECT */
end_comment

begin_define
define|#
directive|define
name|CALLRUNOPS
value|CALL_FPTR(PL_runops)
end_define

begin_define
define|#
directive|define
name|CALLREGCOMP
value|CALL_FPTR(PL_regcompp)
end_define

begin_define
define|#
directive|define
name|CALLREGEXEC
value|CALL_FPTR(PL_regexecp)
end_define

begin_define
define|#
directive|define
name|CALLREG_INTUIT_START
value|CALL_FPTR(PL_regint_start)
end_define

begin_define
define|#
directive|define
name|CALLREG_INTUIT_STRING
value|CALL_FPTR(PL_regint_string)
end_define

begin_define
define|#
directive|define
name|CALLREGFREE
value|CALL_FPTR(PL_regfree)
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|PERL_FLEXIBLE_EXCEPTIONS
end_ifdef

begin_define
define|#
directive|define
name|CALLPROTECT
value|CALL_FPTR(PL_protect)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|NOOP
value|(void)0
end_define

begin_define
define|#
directive|define
name|dNOOP
value|extern int Perl___notused
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|pTHX
end_ifndef

begin_define
define|#
directive|define
name|pTHX
value|void
end_define

begin_define
define|#
directive|define
name|pTHX_
end_define

begin_define
define|#
directive|define
name|aTHX
end_define

begin_define
define|#
directive|define
name|aTHX_
end_define

begin_define
define|#
directive|define
name|dTHXa
parameter_list|(
name|a
parameter_list|)
value|dNOOP
end_define

begin_define
define|#
directive|define
name|dTHX
value|dNOOP
end_define

begin_define
define|#
directive|define
name|pTHX_1
value|1
end_define

begin_define
define|#
directive|define
name|pTHX_2
value|2
end_define

begin_define
define|#
directive|define
name|pTHX_3
value|3
end_define

begin_define
define|#
directive|define
name|pTHX_4
value|4
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|pTHXo
end_ifndef

begin_define
define|#
directive|define
name|pTHXo
value|pTHX
end_define

begin_define
define|#
directive|define
name|pTHXo_
value|pTHX_
end_define

begin_define
define|#
directive|define
name|aTHXo
value|aTHX
end_define

begin_define
define|#
directive|define
name|aTHXo_
value|aTHX_
end_define

begin_define
define|#
directive|define
name|dTHXo
value|dTHX
end_define

begin_define
define|#
directive|define
name|dTHXoa
parameter_list|(
name|x
parameter_list|)
value|dTHXa(x)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|pTHXx
end_ifndef

begin_define
define|#
directive|define
name|pTHXx
value|register PerlInterpreter *my_perl
end_define

begin_define
define|#
directive|define
name|pTHXx_
value|pTHXx,
end_define

begin_define
define|#
directive|define
name|aTHXx
value|my_perl
end_define

begin_define
define|#
directive|define
name|aTHXx_
value|aTHXx,
end_define

begin_define
define|#
directive|define
name|dTHXx
value|dTHX
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_undef
undef|#
directive|undef
name|START_EXTERN_C
end_undef

begin_undef
undef|#
directive|undef
name|END_EXTERN_C
end_undef

begin_undef
undef|#
directive|undef
name|EXTERN_C
end_undef

begin_ifdef
ifdef|#
directive|ifdef
name|__cplusplus
end_ifdef

begin_define
define|#
directive|define
name|START_EXTERN_C
value|extern "C" {
end_define

begin_define
define|#
directive|define
name|END_EXTERN_C
value|}
end_define

begin_define
define|#
directive|define
name|EXTERN_C
value|extern "C"
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|START_EXTERN_C
end_define

begin_define
define|#
directive|define
name|END_EXTERN_C
end_define

begin_define
define|#
directive|define
name|EXTERN_C
value|extern
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|OP_IN_REGISTER
end_ifdef

begin_ifdef
ifdef|#
directive|ifdef
name|__GNUC__
end_ifdef

begin_define
define|#
directive|define
name|stringify_immed
parameter_list|(
name|s
parameter_list|)
value|#s
end_define

begin_define
define|#
directive|define
name|stringify
parameter_list|(
name|s
parameter_list|)
value|stringify_immed(s)
end_define

begin_decl_stmt
specifier|register
name|struct
name|op
modifier|*
name|Perl_op
name|asm
argument_list|(
name|stringify
argument_list|(
name|OP_IN_REGISTER
argument_list|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * STMT_START { statements; } STMT_END;  * can be used as a single statement, as in  * if (x) STMT_START { ... } STMT_END; else ...  *  * Trying to select a version that gives no warnings...  */
end_comment

begin_if
if|#
directive|if
operator|!
operator|(
name|defined
argument_list|(
name|STMT_START
argument_list|)
operator|&&
name|defined
argument_list|(
name|STMT_END
argument_list|)
operator|)
end_if

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__GNUC__
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|__STRICT_ANSI__
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|__cplusplus
argument_list|)
end_if

begin_define
define|#
directive|define
name|STMT_START
value|(void)(
end_define

begin_comment
comment|/* gcc supports ``({ STATEMENTS; })'' */
end_comment

begin_define
define|#
directive|define
name|STMT_END
value|)
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* Now which other defined()s do we need here ??? */
end_comment

begin_if
if|#
directive|if
operator|(
name|VOIDFLAGS
operator|)
operator|&&
operator|(
name|defined
argument_list|(
name|sun
argument_list|)
operator|||
name|defined
argument_list|(
name|__sun__
argument_list|)
operator|)
end_if

begin_define
define|#
directive|define
name|STMT_START
value|if (1)
end_define

begin_define
define|#
directive|define
name|STMT_END
value|else (void)0
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|STMT_START
value|do
end_define

begin_define
define|#
directive|define
name|STMT_END
value|while (0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|WITH_THX
parameter_list|(
name|s
parameter_list|)
value|STMT_START { dTHX; s; } STMT_END
end_define

begin_define
define|#
directive|define
name|WITH_THR
parameter_list|(
name|s
parameter_list|)
value|WITH_THX(s)
end_define

begin_comment
comment|/*  * SOFT_CAST can be used for args to prototyped functions to retain some  * type checking; it only casts if the compiler does not know prototypes.  */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|CAN_PROTOTYPE
argument_list|)
operator|&&
name|defined
argument_list|(
name|DEBUGGING_COMPILE
argument_list|)
end_if

begin_define
define|#
directive|define
name|SOFT_CAST
parameter_list|(
name|type
parameter_list|)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|SOFT_CAST
parameter_list|(
name|type
parameter_list|)
value|(type)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|BYTEORDER
end_ifndef

begin_comment
comment|/* Should never happen -- byteorder is in config.h */
end_comment

begin_define
define|#
directive|define
name|BYTEORDER
value|0x1234
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Overall memory policy? */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|CONSERVATIVE
end_ifndef

begin_define
define|#
directive|define
name|LIBERAL
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
literal|'A'
operator|==
literal|65
operator|&&
literal|'I'
operator|==
literal|73
operator|&&
literal|'J'
operator|==
literal|74
operator|&&
literal|'Z'
operator|==
literal|90
end_if

begin_define
define|#
directive|define
name|ASCIIish
end_define

begin_else
else|#
directive|else
end_else

begin_undef
undef|#
directive|undef
name|ASCIIish
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * The following contortions are brought to you on behalf of all the  * standards, semi-standards, de facto standards, not-so-de-facto standards  * of the world, as well as all the other botches anyone ever thought of.  * The basic theory is that if we work hard enough here, the rest of the  * code can be a lot prettier.  Well, so much for theory.  Sorry, Henry...  */
end_comment

begin_comment
comment|/* define this once if either system, instead of cluttering up the src */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|MSDOS
argument_list|)
operator|||
name|defined
argument_list|(
name|atarist
argument_list|)
operator|||
name|defined
argument_list|(
name|WIN32
argument_list|)
end_if

begin_define
define|#
directive|define
name|DOSISH
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__STDC__
argument_list|)
operator|||
name|defined
argument_list|(
name|vax11c
argument_list|)
operator|||
name|defined
argument_list|(
name|_AIX
argument_list|)
operator|||
name|defined
argument_list|(
name|__stdc__
argument_list|)
operator|||
name|defined
argument_list|(
name|__cplusplus
argument_list|)
operator|||
name|defined
argument_list|(
name|EPOC
argument_list|)
end_if

begin_define
define|#
directive|define
name|STANDARD_C
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__cplusplus
argument_list|)
operator|||
name|defined
argument_list|(
name|WIN32
argument_list|)
operator|||
name|defined
argument_list|(
name|__sgi
argument_list|)
operator|||
name|defined
argument_list|(
name|OS2
argument_list|)
operator|||
name|defined
argument_list|(
name|__DGUX
argument_list|)
operator|||
name|defined
argument_list|(
name|EPOC
argument_list|)
operator|||
name|defined
argument_list|(
name|__QNX__
argument_list|)
end_if

begin_define
define|#
directive|define
name|DONT_DECLARE_STD
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|HASVOLATILE
argument_list|)
operator|||
name|defined
argument_list|(
name|STANDARD_C
argument_list|)
end_if

begin_ifdef
ifdef|#
directive|ifdef
name|__cplusplus
end_ifdef

begin_define
define|#
directive|define
name|VOL
end_define

begin_comment
comment|// to temporarily suppress warnings
end_comment

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|VOL
value|volatile
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|VOL
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|TAINT
value|(PL_tainted = TRUE)
end_define

begin_define
define|#
directive|define
name|TAINT_NOT
value|(PL_tainted = FALSE)
end_define

begin_define
define|#
directive|define
name|TAINT_IF
parameter_list|(
name|c
parameter_list|)
value|if (c) { PL_tainted = TRUE; }
end_define

begin_define
define|#
directive|define
name|TAINT_ENV
parameter_list|()
value|if (PL_tainting) { taint_env(); }
end_define

begin_define
define|#
directive|define
name|TAINT_PROPER
parameter_list|(
name|s
parameter_list|)
value|if (PL_tainting) { taint_proper(Nullch, s); }
end_define

begin_comment
comment|/* XXX All process group stuff is handled in pp_sys.c.  Should these     defines move there?  If so, I could simplify this a lot. --AD  9/96. */
end_comment

begin_comment
comment|/* Process group stuff changed from traditional BSD to POSIX.    perlfunc.pod documents the traditional BSD-style syntax, so we'll    try to preserve that, if possible. */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HAS_SETPGID
end_ifdef

begin_define
define|#
directive|define
name|BSD_SETPGRP
parameter_list|(
name|pid
parameter_list|,
name|pgrp
parameter_list|)
value|setpgid((pid), (pgrp))
end_define

begin_else
else|#
directive|else
end_else

begin_if
if|#
directive|if
name|defined
argument_list|(
name|HAS_SETPGRP
argument_list|)
operator|&&
name|defined
argument_list|(
name|USE_BSD_SETPGRP
argument_list|)
end_if

begin_define
define|#
directive|define
name|BSD_SETPGRP
parameter_list|(
name|pid
parameter_list|,
name|pgrp
parameter_list|)
value|setpgrp((pid), (pgrp))
end_define

begin_else
else|#
directive|else
end_else

begin_ifdef
ifdef|#
directive|ifdef
name|HAS_SETPGRP2
end_ifdef

begin_comment
comment|/* DG/UX */
end_comment

begin_define
define|#
directive|define
name|BSD_SETPGRP
parameter_list|(
name|pid
parameter_list|,
name|pgrp
parameter_list|)
value|setpgrp2((pid), (pgrp))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|BSD_SETPGRP
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|HAS_SETPGRP
argument_list|)
end_if

begin_define
define|#
directive|define
name|HAS_SETPGRP
end_define

begin_comment
comment|/* Well, effectively it does . . . */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* getpgid isn't POSIX, but at least Solaris and Linux have it, and it makes     our life easier :-) so we'll try it. */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HAS_GETPGID
end_ifdef

begin_define
define|#
directive|define
name|BSD_GETPGRP
parameter_list|(
name|pid
parameter_list|)
value|getpgid((pid))
end_define

begin_else
else|#
directive|else
end_else

begin_if
if|#
directive|if
name|defined
argument_list|(
name|HAS_GETPGRP
argument_list|)
operator|&&
name|defined
argument_list|(
name|USE_BSD_GETPGRP
argument_list|)
end_if

begin_define
define|#
directive|define
name|BSD_GETPGRP
parameter_list|(
name|pid
parameter_list|)
value|getpgrp((pid))
end_define

begin_else
else|#
directive|else
end_else

begin_ifdef
ifdef|#
directive|ifdef
name|HAS_GETPGRP2
end_ifdef

begin_comment
comment|/* DG/UX */
end_comment

begin_define
define|#
directive|define
name|BSD_GETPGRP
parameter_list|(
name|pid
parameter_list|)
value|getpgrp2((pid))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|BSD_GETPGRP
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|HAS_GETPGRP
argument_list|)
end_if

begin_define
define|#
directive|define
name|HAS_GETPGRP
end_define

begin_comment
comment|/* Well, effectively it does . . . */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* These are not exact synonyms, since setpgrp() and getpgrp() may     have different behaviors, but perl.h used to define USE_BSDPGRP    (prior to 5.003_05) so some extension might depend on it. */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|USE_BSD_SETPGRP
argument_list|)
operator|||
name|defined
argument_list|(
name|USE_BSD_GETPGRP
argument_list|)
end_if

begin_ifndef
ifndef|#
directive|ifndef
name|USE_BSDPGRP
end_ifndef

begin_define
define|#
directive|define
name|USE_BSDPGRP
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HP-UX 10.X CMA (Common Multithreaded Architecure) insists that    pthread.h must be included before all other header files. */
end_comment

begin_if
if|#
directive|if
operator|(
name|defined
argument_list|(
name|USE_THREADS
argument_list|)
operator|||
name|defined
argument_list|(
name|USE_ITHREADS
argument_list|)
operator|)
expr|\
operator|&&
name|defined
argument_list|(
name|PTHREAD_H_FIRST
argument_list|)
operator|&&
name|defined
argument_list|(
name|I_PTHREAD
argument_list|)
end_if

begin_include
include|#
directive|include
file|<pthread.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|_TYPES_
end_ifndef

begin_comment
comment|/* If types.h defines this it's easy. */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|major
end_ifndef

begin_comment
comment|/* Does everyone's types.h define this? */
end_comment

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

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
name|__cplusplus
end_ifdef

begin_ifndef
ifndef|#
directive|ifndef
name|I_STDARG
end_ifndef

begin_define
define|#
directive|define
name|I_STDARG
value|1
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
name|I_STDARG
end_ifdef

begin_include
include|#
directive|include
file|<stdarg.h>
end_include

begin_else
else|#
directive|else
end_else

begin_ifdef
ifdef|#
directive|ifdef
name|I_VARARGS
end_ifdef

begin_include
include|#
directive|include
file|<varargs.h>
end_include

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
name|USE_NEXT_CTYPE
end_ifdef

begin_if
if|#
directive|if
name|NX_CURRENT_COMPILER_RELEASE
operator|>=
literal|500
end_if

begin_include
include|#
directive|include
file|<bsd/ctypes.h>
end_include

begin_else
else|#
directive|else
end_else

begin_if
if|#
directive|if
name|NX_CURRENT_COMPILER_RELEASE
operator|>=
literal|400
end_if

begin_include
include|#
directive|include
file|<objc/NXCType.h>
end_include

begin_else
else|#
directive|else
end_else

begin_comment
comment|/*  NX_CURRENT_COMPILER_RELEASE< 400 */
end_comment

begin_include
include|#
directive|include
file|<appkit/NXCType.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  NX_CURRENT_COMPILER_RELEASE>= 400 */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  NX_CURRENT_COMPILER_RELEASE>= 500 */
end_comment

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* !USE_NEXT_CTYPE */
end_comment

begin_include
include|#
directive|include
file|<ctype.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* USE_NEXT_CTYPE */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|METHOD
end_ifdef

begin_comment
comment|/* Defined by OSF/1 v3.0 by ctype.h */
end_comment

begin_undef
undef|#
directive|undef
name|METHOD
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|I_LOCALE
end_ifdef

begin_include
include|#
directive|include
file|<locale.h>
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
name|NO_LOCALE
argument_list|)
operator|&&
name|defined
argument_list|(
name|HAS_SETLOCALE
argument_list|)
end_if

begin_define
define|#
directive|define
name|USE_LOCALE
end_define

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|NO_LOCALE_COLLATE
argument_list|)
operator|&&
name|defined
argument_list|(
name|LC_COLLATE
argument_list|)
expr|\
operator|&&
name|defined
argument_list|(
name|HAS_STRXFRM
argument_list|)
end_if

begin_define
define|#
directive|define
name|USE_LOCALE_COLLATE
end_define

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
name|NO_LOCALE_CTYPE
argument_list|)
operator|&&
name|defined
argument_list|(
name|LC_CTYPE
argument_list|)
end_if

begin_define
define|#
directive|define
name|USE_LOCALE_CTYPE
end_define

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
name|NO_LOCALE_NUMERIC
argument_list|)
operator|&&
name|defined
argument_list|(
name|LC_NUMERIC
argument_list|)
end_if

begin_define
define|#
directive|define
name|USE_LOCALE_NUMERIC
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !NO_LOCALE&& HAS_SETLOCALE */
end_comment

begin_include
include|#
directive|include
file|<setjmp.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|I_SYS_PARAM
end_ifdef

begin_ifdef
ifdef|#
directive|ifdef
name|PARAM_NEEDS_TYPES
end_ifdef

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Use all the "standard" definitions? */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|STANDARD_C
argument_list|)
operator|&&
name|defined
argument_list|(
name|I_STDLIB
argument_list|)
end_if

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* If this causes problems, set i_unistd=undef in the hint file.  */
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

begin_ifdef
ifdef|#
directive|ifdef
name|PERL_MICRO
end_ifdef

begin_comment
comment|/* Last chance to export Perl_my_swap */
end_comment

begin_define
define|#
directive|define
name|MYSWAP
end_define

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
name|PERL_FOR_X2P
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|WIN32
argument_list|)
end_if

begin_include
include|#
directive|include
file|"embed.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|MEM_SIZE
value|Size_t
end_define

begin_if
if|#
directive|if
name|defined
argument_list|(
name|STANDARD_C
argument_list|)
operator|&&
name|defined
argument_list|(
name|I_STDDEF
argument_list|)
end_if

begin_include
include|#
directive|include
file|<stddef.h>
end_include

begin_define
define|#
directive|define
name|STRUCT_OFFSET
parameter_list|(
name|s
parameter_list|,
name|m
parameter_list|)
value|offsetof(s,m)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|STRUCT_OFFSET
parameter_list|(
name|s
parameter_list|,
name|m
parameter_list|)
value|(Size_t)(&(((s *)0)->m))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|I_STRING
argument_list|)
operator|||
name|defined
argument_list|(
name|__cplusplus
argument_list|)
end_if

begin_include
include|#
directive|include
file|<string.h>
end_include

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|<strings.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* This comes after<stdlib.h> so we don't try to change the standard  * library prototypes; we'll use our own in proto.h instead. */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|MYMALLOC
end_ifdef

begin_ifdef
ifdef|#
directive|ifdef
name|PERL_POLLUTE_MALLOC
end_ifdef

begin_ifndef
ifndef|#
directive|ifndef
name|PERL_EXTMALLOC_DEF
end_ifndef

begin_define
define|#
directive|define
name|Perl_malloc
value|malloc
end_define

begin_define
define|#
directive|define
name|Perl_calloc
value|calloc
end_define

begin_define
define|#
directive|define
name|Perl_realloc
value|realloc
end_define

begin_define
define|#
directive|define
name|Perl_mfree
value|free
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|EMBEDMYMALLOC
end_define

begin_comment
comment|/* for compatibility */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
name|Malloc_t
name|Perl_malloc
parameter_list|(
name|MEM_SIZE
name|nbytes
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|Malloc_t
name|Perl_calloc
parameter_list|(
name|MEM_SIZE
name|elements
parameter_list|,
name|MEM_SIZE
name|size
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|Malloc_t
name|Perl_realloc
parameter_list|(
name|Malloc_t
name|where
parameter_list|,
name|MEM_SIZE
name|nbytes
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* 'mfree' rather than 'free', since there is already a 'perl_free'  * that causes clashes with case-insensitive linkers */
end_comment

begin_function_decl
name|Free_t
name|Perl_mfree
parameter_list|(
name|Malloc_t
name|where
parameter_list|)
function_decl|;
end_function_decl

begin_typedef
typedef|typedef
name|struct
name|perl_mstats
name|perl_mstats_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|safemalloc
value|Perl_malloc
end_define

begin_define
define|#
directive|define
name|safecalloc
value|Perl_calloc
end_define

begin_define
define|#
directive|define
name|saferealloc
value|Perl_realloc
end_define

begin_define
define|#
directive|define
name|safefree
value|Perl_mfree
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* MYMALLOC */
end_comment

begin_define
define|#
directive|define
name|safemalloc
value|safesysmalloc
end_define

begin_define
define|#
directive|define
name|safecalloc
value|safesyscalloc
end_define

begin_define
define|#
directive|define
name|saferealloc
value|safesysrealloc
end_define

begin_define
define|#
directive|define
name|safefree
value|safesysfree
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* MYMALLOC */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|HAS_STRCHR
argument_list|)
operator|&&
name|defined
argument_list|(
name|HAS_INDEX
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|strchr
argument_list|)
end_if

begin_define
define|#
directive|define
name|strchr
value|index
end_define

begin_define
define|#
directive|define
name|strrchr
value|rindex
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|I_MEMORY
end_ifdef

begin_include
include|#
directive|include
file|<memory.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|HAS_MEMCPY
end_ifdef

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
name|I_STRING
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|I_MEMORY
argument_list|)
end_if

begin_ifndef
ifndef|#
directive|ifndef
name|memcpy
end_ifndef

begin_function_decl
specifier|extern
name|char
modifier|*
name|memcpy
parameter_list|(
name|char
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_else
else|#
directive|else
end_else

begin_ifndef
ifndef|#
directive|ifndef
name|memcpy
end_ifndef

begin_ifdef
ifdef|#
directive|ifdef
name|HAS_BCOPY
end_ifdef

begin_define
define|#
directive|define
name|memcpy
parameter_list|(
name|d
parameter_list|,
name|s
parameter_list|,
name|l
parameter_list|)
value|bcopy(s,d,l)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|memcpy
parameter_list|(
name|d
parameter_list|,
name|s
parameter_list|,
name|l
parameter_list|)
value|my_bcopy(s,d,l)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HAS_MEMCPY */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HAS_MEMSET
end_ifdef

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
name|I_STRING
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|I_MEMORY
argument_list|)
end_if

begin_ifndef
ifndef|#
directive|ifndef
name|memset
end_ifndef

begin_function_decl
specifier|extern
name|char
modifier|*
name|memset
parameter_list|(
name|char
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|memset
parameter_list|(
name|d
parameter_list|,
name|c
parameter_list|,
name|l
parameter_list|)
value|my_memset(d,c,l)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HAS_MEMSET */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|HAS_MEMMOVE
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|memmove
argument_list|)
end_if

begin_if
if|#
directive|if
name|defined
argument_list|(
name|HAS_BCOPY
argument_list|)
operator|&&
name|defined
argument_list|(
name|HAS_SAFE_BCOPY
argument_list|)
end_if

begin_define
define|#
directive|define
name|memmove
parameter_list|(
name|d
parameter_list|,
name|s
parameter_list|,
name|l
parameter_list|)
value|bcopy(s,d,l)
end_define

begin_else
else|#
directive|else
end_else

begin_if
if|#
directive|if
name|defined
argument_list|(
name|HAS_MEMCPY
argument_list|)
operator|&&
name|defined
argument_list|(
name|HAS_SAFE_MEMCPY
argument_list|)
end_if

begin_define
define|#
directive|define
name|memmove
parameter_list|(
name|d
parameter_list|,
name|s
parameter_list|,
name|l
parameter_list|)
value|memcpy(d,s,l)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|memmove
parameter_list|(
name|d
parameter_list|,
name|s
parameter_list|,
name|l
parameter_list|)
value|my_bcopy(s,d,l)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|mips
argument_list|)
operator|&&
name|defined
argument_list|(
name|ultrix
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|__STDC__
argument_list|)
end_if

begin_undef
undef|#
directive|undef
name|HAS_MEMCMP
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|HAS_MEMCMP
argument_list|)
operator|&&
name|defined
argument_list|(
name|HAS_SANE_MEMCMP
argument_list|)
end_if

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
name|I_STRING
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|I_MEMORY
argument_list|)
end_if

begin_ifndef
ifndef|#
directive|ifndef
name|memcmp
end_ifndef

begin_function_decl
specifier|extern
name|int
name|memcmp
parameter_list|(
name|char
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

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
name|BUGGY_MSC
end_ifdef

begin_pragma
pragma|#
directive|pragma
name|function
name|(
name|memcmp
name|)
end_pragma

begin_endif
endif|#
directive|endif
end_endif

begin_else
else|#
directive|else
end_else

begin_ifndef
ifndef|#
directive|ifndef
name|memcmp
end_ifndef

begin_define
define|#
directive|define
name|memcmp
value|my_memcmp
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HAS_MEMCMP&& HAS_SANE_MEMCMP */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|memzero
end_ifndef

begin_ifdef
ifdef|#
directive|ifdef
name|HAS_MEMSET
end_ifdef

begin_define
define|#
directive|define
name|memzero
parameter_list|(
name|d
parameter_list|,
name|l
parameter_list|)
value|memset(d,0,l)
end_define

begin_else
else|#
directive|else
end_else

begin_ifdef
ifdef|#
directive|ifdef
name|HAS_BZERO
end_ifdef

begin_define
define|#
directive|define
name|memzero
parameter_list|(
name|d
parameter_list|,
name|l
parameter_list|)
value|bzero(d,l)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|memzero
parameter_list|(
name|d
parameter_list|,
name|l
parameter_list|)
value|my_bzero(d,l)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|memchr
end_ifndef

begin_ifndef
ifndef|#
directive|ifndef
name|HAS_MEMCHR
end_ifndef

begin_define
define|#
directive|define
name|memchr
parameter_list|(
name|s
parameter_list|,
name|c
parameter_list|,
name|n
parameter_list|)
value|ninstr((char*)(s), ((char*)(s)) + n,&(c),&(c) + 1)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|HAS_BCMP
end_ifndef

begin_ifndef
ifndef|#
directive|ifndef
name|bcmp
end_ifndef

begin_define
define|#
directive|define
name|bcmp
parameter_list|(
name|s1
parameter_list|,
name|s2
parameter_list|,
name|l
parameter_list|)
value|memcmp(s1,s2,l)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !HAS_BCMP */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|I_NETINET_IN
end_ifdef

begin_include
include|#
directive|include
file|<netinet/in.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|I_ARPA_INET
end_ifdef

begin_include
include|#
directive|include
file|<arpa/inet.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|SF_APPEND
argument_list|)
operator|&&
name|defined
argument_list|(
name|USE_SFIO
argument_list|)
operator|&&
name|defined
argument_list|(
name|I_SFIO
argument_list|)
end_if

begin_comment
comment|/*<sfio.h> defines SF_APPEND and<sys/stat.h> might define SF_APPEND  * (the neo-BSD seem to do this).  */
end_comment

begin_undef
undef|#
directive|undef
name|SF_APPEND
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|I_SYS_STAT
end_ifdef

begin_include
include|#
directive|include
file|<sys/stat.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* The stat macros for Amdahl UTS, Unisoft System V/88 (and derivatives    like UTekV) are broken, sometimes giving false positives.  Undefine    them here and let the code below set them to proper values.     The ghs macro stands for GreenHills Software C-1.8.5 which    is the C compiler for sysV88 and the various derivatives.    This header file bug is corrected in gcc-2.5.8 and later versions.    --Kaveh Ghazi (ghazi@noc.rutgers.edu) 10/3/94.  */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|uts
argument_list|)
operator|||
operator|(
name|defined
argument_list|(
name|m88k
argument_list|)
operator|&&
name|defined
argument_list|(
name|ghs
argument_list|)
operator|)
end_if

begin_undef
undef|#
directive|undef
name|S_ISDIR
end_undef

begin_undef
undef|#
directive|undef
name|S_ISCHR
end_undef

begin_undef
undef|#
directive|undef
name|S_ISBLK
end_undef

begin_undef
undef|#
directive|undef
name|S_ISREG
end_undef

begin_undef
undef|#
directive|undef
name|S_ISFIFO
end_undef

begin_undef
undef|#
directive|undef
name|S_ISLNK
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|I_TIME
end_ifdef

begin_include
include|#
directive|include
file|<time.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|I_SYS_TIME
end_ifdef

begin_ifdef
ifdef|#
directive|ifdef
name|I_SYS_TIME_KERNEL
end_ifdef

begin_define
define|#
directive|define
name|KERNEL
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<sys/time.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|I_SYS_TIME_KERNEL
end_ifdef

begin_undef
undef|#
directive|undef
name|KERNEL
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|HAS_TIMES
argument_list|)
operator|&&
name|defined
argument_list|(
name|I_SYS_TIMES
argument_list|)
end_if

begin_include
include|#
directive|include
file|<sys/times.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|HAS_STRERROR
argument_list|)
operator|&&
operator|(
operator|!
name|defined
argument_list|(
name|HAS_MKDIR
argument_list|)
operator|||
operator|!
name|defined
argument_list|(
name|HAS_RMDIR
argument_list|)
operator|)
end_if

begin_undef
undef|#
directive|undef
name|HAS_STRERROR
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<errno.h>
end_include

begin_if
if|#
directive|if
name|defined
argument_list|(
name|WIN32
argument_list|)
operator|&&
operator|(
name|defined
argument_list|(
name|PERL_OBJECT
argument_list|)
operator|||
name|defined
argument_list|(
name|PERL_IMPLICIT_SYS
argument_list|)
operator|||
name|defined
argument_list|(
name|PERL_CAPI
argument_list|)
operator|)
end_if

begin_define
define|#
directive|define
name|WIN32SCK_IS_STDSCK
end_define

begin_comment
comment|/* don't pull in custom wsock layer */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|HAS_SOCKET
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|VMS
argument_list|)
end_if

begin_comment
comment|/* VMS handles sockets via vmsish.h */
end_comment

begin_include
include|#
directive|include
file|<sys/socket.h>
end_include

begin_if
if|#
directive|if
name|defined
argument_list|(
name|USE_SOCKS
argument_list|)
operator|&&
name|defined
argument_list|(
name|I_SOCKS
argument_list|)
end_if

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|INCLUDE_PROTOTYPES
argument_list|)
end_if

begin_define
define|#
directive|define
name|INCLUDE_PROTOTYPES
end_define

begin_comment
comment|/* for<socks.h> */
end_comment

begin_define
define|#
directive|define
name|PERL_SOCKS_NEED_PROTOTYPES
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|USE_THREADS
end_ifdef

begin_define
define|#
directive|define
name|PERL_USE_THREADS
end_define

begin_comment
comment|/* store our value */
end_comment

begin_undef
undef|#
directive|undef
name|USE_THREADS
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<socks.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|USE_THREADS
end_ifdef

begin_undef
undef|#
directive|undef
name|USE_THREADS
end_undef

begin_comment
comment|/* socks.h does this on its own */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|PERL_USE_THREADS
end_ifdef

begin_define
define|#
directive|define
name|USE_THREADS
end_define

begin_comment
comment|/* restore our value */
end_comment

begin_undef
undef|#
directive|undef
name|PERL_USE_THREADS
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|PERL_SOCKS_NEED_PROTOTYPES
end_ifdef

begin_comment
comment|/* keep cpp space clean */
end_comment

begin_undef
undef|#
directive|undef
name|INCLUDE_PROTOTYPES
end_undef

begin_undef
undef|#
directive|undef
name|PERL_SOCKS_NEED_PROTOTYPES
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|USE_64_BIT_ALL
end_ifdef

begin_define
define|#
directive|define
name|SOCKS_64BIT_BUG
end_define

begin_comment
comment|/* until proven otherwise */
end_comment

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
name|I_NETDB
end_ifdef

begin_include
include|#
directive|include
file|<netdb.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ENOTSOCK
end_ifndef

begin_ifdef
ifdef|#
directive|ifdef
name|I_NET_ERRNO
end_ifdef

begin_include
include|#
directive|include
file|<net/errno.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

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
name|SETERRNO
end_ifdef

begin_undef
undef|#
directive|undef
name|SETERRNO
end_undef

begin_comment
comment|/* SOCKS might have defined this */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|VMS
end_ifdef

begin_define
define|#
directive|define
name|SETERRNO
parameter_list|(
name|errcode
parameter_list|,
name|vmserrcode
parameter_list|)
define|\
value|STMT_START {			\ 	    set_errno(errcode);		\ 	    set_vaxc_errno(vmserrcode);	\ 	} STMT_END
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|SETERRNO
parameter_list|(
name|errcode
parameter_list|,
name|vmserrcode
parameter_list|)
value|(errno = (errcode))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|USE_THREADS
end_ifdef

begin_define
define|#
directive|define
name|ERRSV
value|(thr->errsv)
end_define

begin_define
define|#
directive|define
name|DEFSV
value|THREADSV(0)
end_define

begin_define
define|#
directive|define
name|SAVE_DEFSV
value|save_threadsv(0)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|ERRSV
value|GvSV(PL_errgv)
end_define

begin_define
define|#
directive|define
name|DEFSV
value|GvSV(PL_defgv)
end_define

begin_define
define|#
directive|define
name|SAVE_DEFSV
value|SAVESPTR(GvSV(PL_defgv))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* USE_THREADS */
end_comment

begin_define
define|#
directive|define
name|ERRHV
value|GvHV(PL_errgv)
end_define

begin_comment
comment|/* XXX unused, here for compatibility */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|errno
end_ifndef

begin_decl_stmt
specifier|extern
name|int
name|errno
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* ANSI allows errno to be an lvalue expr. 			       * For example in multithreaded environments 			       * something like this might happen: 			       * extern int *_errno(void); 			       * #define errno (*_errno()) */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|HAS_STRERROR
end_ifdef

begin_ifdef
ifdef|#
directive|ifdef
name|VMS
end_ifdef

begin_function_decl
name|char
modifier|*
name|strerror
parameter_list|(
name|int
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_else
else|#
directive|else
end_else

begin_ifndef
ifndef|#
directive|ifndef
name|DONT_DECLARE_STD
end_ifndef

begin_function_decl
name|char
modifier|*
name|strerror
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|Strerror
end_ifndef

begin_define
define|#
directive|define
name|Strerror
value|strerror
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_else
else|#
directive|else
end_else

begin_ifdef
ifdef|#
directive|ifdef
name|HAS_SYS_ERRLIST
end_ifdef

begin_decl_stmt
specifier|extern
name|int
name|sys_nerr
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|sys_errlist
index|[]
decl_stmt|;
end_decl_stmt

begin_ifndef
ifndef|#
directive|ifndef
name|Strerror
end_ifndef

begin_define
define|#
directive|define
name|Strerror
parameter_list|(
name|e
parameter_list|)
define|\
value|((e)< 0 || (e)>= sys_nerr ? "(unknown)" : sys_errlist[e])
end_define

begin_endif
endif|#
directive|endif
end_endif

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
name|I_SYS_IOCTL
end_ifdef

begin_ifndef
ifndef|#
directive|ifndef
name|_IOCTL_
end_ifndef

begin_include
include|#
directive|include
file|<sys/ioctl.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|mc300
argument_list|)
operator|||
name|defined
argument_list|(
name|mc500
argument_list|)
operator|||
name|defined
argument_list|(
name|mc700
argument_list|)
operator|||
name|defined
argument_list|(
name|mc6000
argument_list|)
end_if

begin_ifdef
ifdef|#
directive|ifdef
name|HAS_SOCKETPAIR
end_ifdef

begin_undef
undef|#
directive|undef
name|HAS_SOCKETPAIR
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|I_NDBM
end_ifdef

begin_undef
undef|#
directive|undef
name|I_NDBM
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|INTSIZE
operator|==
literal|2
end_if

begin_define
define|#
directive|define
name|htoni
value|htons
end_define

begin_define
define|#
directive|define
name|ntohi
value|ntohs
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|htoni
value|htonl
end_define

begin_define
define|#
directive|define
name|ntohi
value|ntohl
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Configure already sets Direntry_t */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|I_DIRENT
argument_list|)
end_if

begin_include
include|#
directive|include
file|<dirent.h>
end_include

begin_comment
comment|/* NeXT needs dirent + sys/dir.h */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|I_SYS_DIR
argument_list|)
operator|&&
operator|(
name|defined
argument_list|(
name|NeXT
argument_list|)
operator|||
name|defined
argument_list|(
name|__NeXT__
argument_list|)
operator|)
end_if

begin_include
include|#
directive|include
file|<sys/dir.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_else
else|#
directive|else
end_else

begin_ifdef
ifdef|#
directive|ifdef
name|I_SYS_NDIR
end_ifdef

begin_include
include|#
directive|include
file|<sys/ndir.h>
end_include

begin_else
else|#
directive|else
end_else

begin_ifdef
ifdef|#
directive|ifdef
name|I_SYS_DIR
end_ifdef

begin_ifdef
ifdef|#
directive|ifdef
name|hp9000s500
end_ifdef

begin_include
include|#
directive|include
file|<ndir.h>
end_include

begin_comment
comment|/* may be wrong in the future */
end_comment

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|<sys/dir.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

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
name|FPUTS_BOTCH
end_ifdef

begin_comment
comment|/* work around botch in SunOS 4.0.1 and 4.0.2 */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|fputs
end_ifndef

begin_define
define|#
directive|define
name|fputs
parameter_list|(
name|sv
parameter_list|,
name|fp
parameter_list|)
value|fprintf(fp,"%s",sv)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * The following gobbledygook brought to you on behalf of __STDC__.  * (I could just use #ifndef __STDC__, but this is more bulletproof  * in the face of half-implementations.)  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|I_SYSMODE
end_ifdef

begin_include
include|#
directive|include
file|<sys/mode.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|S_IFMT
end_ifndef

begin_ifdef
ifdef|#
directive|ifdef
name|_S_IFMT
end_ifdef

begin_define
define|#
directive|define
name|S_IFMT
value|_S_IFMT
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|S_IFMT
value|0170000
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|S_ISDIR
end_ifndef

begin_define
define|#
directive|define
name|S_ISDIR
parameter_list|(
name|m
parameter_list|)
value|((m& S_IFMT) == S_IFDIR)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|S_ISCHR
end_ifndef

begin_define
define|#
directive|define
name|S_ISCHR
parameter_list|(
name|m
parameter_list|)
value|((m& S_IFMT) == S_IFCHR)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|S_ISBLK
end_ifndef

begin_ifdef
ifdef|#
directive|ifdef
name|S_IFBLK
end_ifdef

begin_define
define|#
directive|define
name|S_ISBLK
parameter_list|(
name|m
parameter_list|)
value|((m& S_IFMT) == S_IFBLK)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|S_ISBLK
parameter_list|(
name|m
parameter_list|)
value|(0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|S_ISREG
end_ifndef

begin_define
define|#
directive|define
name|S_ISREG
parameter_list|(
name|m
parameter_list|)
value|((m& S_IFMT) == S_IFREG)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|S_ISFIFO
end_ifndef

begin_ifdef
ifdef|#
directive|ifdef
name|S_IFIFO
end_ifdef

begin_define
define|#
directive|define
name|S_ISFIFO
parameter_list|(
name|m
parameter_list|)
value|((m& S_IFMT) == S_IFIFO)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|S_ISFIFO
parameter_list|(
name|m
parameter_list|)
value|(0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|S_ISLNK
end_ifndef

begin_ifdef
ifdef|#
directive|ifdef
name|_S_ISLNK
end_ifdef

begin_define
define|#
directive|define
name|S_ISLNK
parameter_list|(
name|m
parameter_list|)
value|_S_ISLNK(m)
end_define

begin_else
else|#
directive|else
end_else

begin_ifdef
ifdef|#
directive|ifdef
name|_S_IFLNK
end_ifdef

begin_define
define|#
directive|define
name|S_ISLNK
parameter_list|(
name|m
parameter_list|)
value|((m& S_IFMT) == _S_IFLNK)
end_define

begin_else
else|#
directive|else
end_else

begin_ifdef
ifdef|#
directive|ifdef
name|S_IFLNK
end_ifdef

begin_define
define|#
directive|define
name|S_ISLNK
parameter_list|(
name|m
parameter_list|)
value|((m& S_IFMT) == S_IFLNK)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|S_ISLNK
parameter_list|(
name|m
parameter_list|)
value|(0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|S_ISSOCK
end_ifndef

begin_ifdef
ifdef|#
directive|ifdef
name|_S_ISSOCK
end_ifdef

begin_define
define|#
directive|define
name|S_ISSOCK
parameter_list|(
name|m
parameter_list|)
value|_S_ISSOCK(m)
end_define

begin_else
else|#
directive|else
end_else

begin_ifdef
ifdef|#
directive|ifdef
name|_S_IFSOCK
end_ifdef

begin_define
define|#
directive|define
name|S_ISSOCK
parameter_list|(
name|m
parameter_list|)
value|((m& S_IFMT) == _S_IFSOCK)
end_define

begin_else
else|#
directive|else
end_else

begin_ifdef
ifdef|#
directive|ifdef
name|S_IFSOCK
end_ifdef

begin_define
define|#
directive|define
name|S_ISSOCK
parameter_list|(
name|m
parameter_list|)
value|((m& S_IFMT) == S_IFSOCK)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|S_ISSOCK
parameter_list|(
name|m
parameter_list|)
value|(0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|S_IRUSR
end_ifndef

begin_ifdef
ifdef|#
directive|ifdef
name|S_IREAD
end_ifdef

begin_define
define|#
directive|define
name|S_IRUSR
value|S_IREAD
end_define

begin_define
define|#
directive|define
name|S_IWUSR
value|S_IWRITE
end_define

begin_define
define|#
directive|define
name|S_IXUSR
value|S_IEXEC
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|S_IRUSR
value|0400
end_define

begin_define
define|#
directive|define
name|S_IWUSR
value|0200
end_define

begin_define
define|#
directive|define
name|S_IXUSR
value|0100
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|S_IRGRP
end_ifndef

begin_ifdef
ifdef|#
directive|ifdef
name|S_IRUSR
end_ifdef

begin_define
define|#
directive|define
name|S_IRGRP
value|(S_IRUSR>>3)
end_define

begin_define
define|#
directive|define
name|S_IWGRP
value|(S_IWUSR>>3)
end_define

begin_define
define|#
directive|define
name|S_IXGRP
value|(S_IXUSR>>3)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|S_IRGRP
value|0040
end_define

begin_define
define|#
directive|define
name|S_IWGRP
value|0020
end_define

begin_define
define|#
directive|define
name|S_IXGRP
value|0010
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|S_IROTH
end_ifndef

begin_ifdef
ifdef|#
directive|ifdef
name|S_IRUSR
end_ifdef

begin_define
define|#
directive|define
name|S_IROTH
value|(S_IRUSR>>6)
end_define

begin_define
define|#
directive|define
name|S_IWOTH
value|(S_IWUSR>>6)
end_define

begin_define
define|#
directive|define
name|S_IXOTH
value|(S_IXUSR>>6)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|S_IROTH
value|0040
end_define

begin_define
define|#
directive|define
name|S_IWOTH
value|0020
end_define

begin_define
define|#
directive|define
name|S_IXOTH
value|0010
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|S_ISUID
end_ifndef

begin_define
define|#
directive|define
name|S_ISUID
value|04000
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|S_ISGID
end_ifndef

begin_define
define|#
directive|define
name|S_ISGID
value|02000
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|S_IRWXU
end_ifndef

begin_define
define|#
directive|define
name|S_IRWXU
value|(S_IRUSR|S_IWUSR|S_IXUSR)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|S_IRWXG
end_ifndef

begin_define
define|#
directive|define
name|S_IRWXG
value|(S_IRGRP|S_IWGRP|S_IXGRP)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|S_IRWXO
end_ifndef

begin_define
define|#
directive|define
name|S_IRWXO
value|(S_IROTH|S_IWOTH|S_IXOTH)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|S_IREAD
end_ifndef

begin_define
define|#
directive|define
name|S_IREAD
value|S_IRUSR
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|S_IWRITE
end_ifndef

begin_define
define|#
directive|define
name|S_IWRITE
value|S_IWUSR
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|S_IEXEC
end_ifndef

begin_define
define|#
directive|define
name|S_IEXEC
value|S_IXUSR
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|ff_next
end_ifdef

begin_undef
undef|#
directive|undef
name|ff_next
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|cray
argument_list|)
operator|||
name|defined
argument_list|(
name|gould
argument_list|)
operator|||
name|defined
argument_list|(
name|i860
argument_list|)
operator|||
name|defined
argument_list|(
name|pyr
argument_list|)
end_if

begin_define
define|#
directive|define
name|SLOPPYDIVIDE
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|UV
end_ifdef

begin_undef
undef|#
directive|undef
name|UV
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*     The IV type is supposed to be long enough to hold any integral     value or a pointer.     --Andy Dougherty	August 1996 */
end_comment

begin_typedef
typedef|typedef
name|IVTYPE
name|IV
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|UVTYPE
name|UV
typedef|;
end_typedef

begin_if
if|#
directive|if
name|defined
argument_list|(
name|USE_64_BIT_INT
argument_list|)
operator|&&
name|defined
argument_list|(
name|HAS_QUAD
argument_list|)
end_if

begin_if
if|#
directive|if
name|QUADKIND
operator|==
name|QUAD_IS_INT64_T
operator|&&
name|defined
argument_list|(
name|INT64_MAX
argument_list|)
end_if

begin_define
define|#
directive|define
name|IV_MAX
value|INT64_MAX
end_define

begin_define
define|#
directive|define
name|IV_MIN
value|INT64_MIN
end_define

begin_define
define|#
directive|define
name|UV_MAX
value|UINT64_MAX
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|UINT64_MIN
end_ifndef

begin_define
define|#
directive|define
name|UINT64_MIN
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|UV_MIN
value|UINT64_MIN
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|IV_MAX
value|PERL_QUAD_MAX
end_define

begin_define
define|#
directive|define
name|IV_MIN
value|PERL_QUAD_MIN
end_define

begin_define
define|#
directive|define
name|UV_MAX
value|PERL_UQUAD_MAX
end_define

begin_define
define|#
directive|define
name|UV_MIN
value|PERL_UQUAD_MIN
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|IV_IS_QUAD
end_define

begin_define
define|#
directive|define
name|UV_IS_QUAD
end_define

begin_else
else|#
directive|else
end_else

begin_if
if|#
directive|if
name|defined
argument_list|(
name|INT32_MAX
argument_list|)
operator|&&
name|IVSIZE
operator|==
literal|4
end_if

begin_define
define|#
directive|define
name|IV_MAX
value|INT32_MAX
end_define

begin_define
define|#
directive|define
name|IV_MIN
value|INT32_MIN
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|UINT32_MAX_BROKEN
end_ifndef

begin_comment
comment|/* e.g. HP-UX with gcc messes this up */
end_comment

begin_define
define|#
directive|define
name|UV_MAX
value|UINT32_MAX
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|UV_MAX
value|4294967295U
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|UINT32_MIN
end_ifndef

begin_define
define|#
directive|define
name|UINT32_MIN
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|UV_MIN
value|UINT32_MIN
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|IV_MAX
value|PERL_LONG_MAX
end_define

begin_define
define|#
directive|define
name|IV_MIN
value|PERL_LONG_MIN
end_define

begin_define
define|#
directive|define
name|UV_MAX
value|PERL_ULONG_MAX
end_define

begin_define
define|#
directive|define
name|UV_MIN
value|PERL_ULONG_MIN
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|IVSIZE
operator|==
literal|8
end_if

begin_define
define|#
directive|define
name|IV_IS_QUAD
end_define

begin_define
define|#
directive|define
name|UV_IS_QUAD
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|HAS_QUAD
end_ifndef

begin_define
define|#
directive|define
name|HAS_QUAD
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_else
else|#
directive|else
end_else

begin_undef
undef|#
directive|undef
name|IV_IS_QUAD
end_undef

begin_undef
undef|#
directive|undef
name|UV_IS_QUAD
end_undef

begin_undef
undef|#
directive|undef
name|HAS_QUAD
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|IV_DIG
value|(BIT_DIGITS(IVSIZE * 8))
end_define

begin_define
define|#
directive|define
name|UV_DIG
value|(BIT_DIGITS(UVSIZE * 8))
end_define

begin_comment
comment|/*     *  The macros INT2PTR and NUM2PTR are (despite their names)  *  bi-directional: they will convert int/float to or from pointers.  *  However the conversion to int/float are named explicitly:  *  PTR2IV, PTR2UV, PTR2NV.  *  *  For int conversions we do not need two casts if pointers are  *  the same size as IV and UV.   Otherwise we need an explicit  *  cast (PTRV) to avoid compiler warnings.  */
end_comment

begin_if
if|#
directive|if
operator|(
name|IVSIZE
operator|==
name|PTRSIZE
operator|)
operator|&&
operator|(
name|UVSIZE
operator|==
name|PTRSIZE
operator|)
end_if

begin_define
define|#
directive|define
name|PTRV
value|UV
end_define

begin_define
define|#
directive|define
name|INT2PTR
parameter_list|(
name|any
parameter_list|,
name|d
parameter_list|)
value|(any)(d)
end_define

begin_else
else|#
directive|else
end_else

begin_if
if|#
directive|if
name|PTRSIZE
operator|==
name|LONGSIZE
end_if

begin_define
define|#
directive|define
name|PTRV
value|unsigned long
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|PTRV
value|unsigned
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|INT2PTR
parameter_list|(
name|any
parameter_list|,
name|d
parameter_list|)
value|(any)(PTRV)(d)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|NUM2PTR
parameter_list|(
name|any
parameter_list|,
name|d
parameter_list|)
value|(any)(PTRV)(d)
end_define

begin_define
define|#
directive|define
name|PTR2IV
parameter_list|(
name|p
parameter_list|)
value|INT2PTR(IV,p)
end_define

begin_define
define|#
directive|define
name|PTR2UV
parameter_list|(
name|p
parameter_list|)
value|INT2PTR(UV,p)
end_define

begin_define
define|#
directive|define
name|PTR2NV
parameter_list|(
name|p
parameter_list|)
value|NUM2PTR(NV,p)
end_define

begin_if
if|#
directive|if
name|PTRSIZE
operator|==
name|LONGSIZE
end_if

begin_define
define|#
directive|define
name|PTR2ul
parameter_list|(
name|p
parameter_list|)
value|(unsigned long)(p)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|PTR2ul
parameter_list|(
name|p
parameter_list|)
value|INT2PTR(unsigned long,p)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|USE_LONG_DOUBLE
end_ifdef

begin_if
if|#
directive|if
name|defined
argument_list|(
name|HAS_LONG_DOUBLE
argument_list|)
operator|&&
name|LONG_DOUBLESIZE
operator|==
name|DOUBLESIZE
end_if

begin_define
define|#
directive|define
name|LONG_DOUBLE_EQUALS_DOUBLE
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|!
operator|(
name|defined
argument_list|(
name|HAS_LONG_DOUBLE
argument_list|)
operator|&&
operator|(
name|LONG_DOUBLESIZE
operator|>
name|DOUBLESIZE
operator|)
operator|)
end_if

begin_undef
undef|#
directive|undef
name|USE_LONG_DOUBLE
end_undef

begin_comment
comment|/* Ouch! */
end_comment

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
name|OVR_DBL_DIG
end_ifdef

begin_comment
comment|/* Use an overridden DBL_DIG */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|DBL_DIG
end_ifdef

begin_undef
undef|#
directive|undef
name|DBL_DIG
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|DBL_DIG
value|OVR_DBL_DIG
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* The following is all to get DBL_DIG, in order to pick a nice    default value for printing floating point numbers in Gconvert.    (see config.h) */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|I_LIMITS
end_ifdef

begin_include
include|#
directive|include
file|<limits.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|I_FLOAT
end_ifdef

begin_include
include|#
directive|include
file|<float.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|HAS_DBL_DIG
end_ifndef

begin_define
define|#
directive|define
name|DBL_DIG
value|15
end_define

begin_comment
comment|/* A guess that works lots of places */
end_comment

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
name|I_FLOAT
end_ifdef

begin_include
include|#
directive|include
file|<float.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|HAS_DBL_DIG
end_ifndef

begin_define
define|#
directive|define
name|DBL_DIG
value|15
end_define

begin_comment
comment|/* A guess that works lots of places */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|OVR_LDBL_DIG
end_ifdef

begin_comment
comment|/* Use an overridden LDBL_DIG */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|LDBL_DIG
end_ifdef

begin_undef
undef|#
directive|undef
name|LDBL_DIG
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|LDBL_DIG
value|OVR_LDBL_DIG
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* The following is all to get LDBL_DIG, in order to pick a nice    default value for printing floating point numbers in Gconvert.    (see config.h) */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|I_LIMITS
end_ifdef

begin_include
include|#
directive|include
file|<limits.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|I_FLOAT
end_ifdef

begin_include
include|#
directive|include
file|<float.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|HAS_LDBL_DIG
end_ifndef

begin_if
if|#
directive|if
name|LONG_DOUBLESIZE
operator|==
literal|10
end_if

begin_define
define|#
directive|define
name|LDBL_DIG
value|18
end_define

begin_comment
comment|/* assume IEEE */
end_comment

begin_else
else|#
directive|else
end_else

begin_if
if|#
directive|if
name|LONG_DOUBLESIZE
operator|==
literal|12
end_if

begin_define
define|#
directive|define
name|LDBL_DIG
value|18
end_define

begin_comment
comment|/* gcc? */
end_comment

begin_else
else|#
directive|else
end_else

begin_if
if|#
directive|if
name|LONG_DOUBLESIZE
operator|==
literal|16
end_if

begin_define
define|#
directive|define
name|LDBL_DIG
value|33
end_define

begin_comment
comment|/* assume IEEE */
end_comment

begin_else
else|#
directive|else
end_else

begin_if
if|#
directive|if
name|LONG_DOUBLESIZE
operator|==
name|DOUBLESIZE
end_if

begin_define
define|#
directive|define
name|LDBL_DIG
value|DBL_DIG
end_define

begin_comment
comment|/* bummer */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
name|NVTYPE
name|NV
typedef|;
end_typedef

begin_ifdef
ifdef|#
directive|ifdef
name|I_IEEEFP
end_ifdef

begin_include
include|#
directive|include
file|<ieeefp.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|USE_LONG_DOUBLE
end_ifdef

begin_ifdef
ifdef|#
directive|ifdef
name|I_SUNMATH
end_ifdef

begin_include
include|#
directive|include
file|<sunmath.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|NV_DIG
value|LDBL_DIG
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|LDBL_MANT_DIG
end_ifdef

begin_define
define|#
directive|define
name|NV_MANT_DIG
value|LDBL_MANT_DIG
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|LDBL_MAX
end_ifdef

begin_define
define|#
directive|define
name|NV_MAX
value|LDBL_MAX
end_define

begin_define
define|#
directive|define
name|NV_MIN
value|LDBL_MIN
end_define

begin_else
else|#
directive|else
end_else

begin_ifdef
ifdef|#
directive|ifdef
name|HUGE_VALL
end_ifdef

begin_define
define|#
directive|define
name|NV_MAX
value|HUGE_VALL
end_define

begin_else
else|#
directive|else
end_else

begin_ifdef
ifdef|#
directive|ifdef
name|HUGE_VAL
end_ifdef

begin_define
define|#
directive|define
name|NV_MAX
value|((NV)HUGE_VAL)
end_define

begin_endif
endif|#
directive|endif
end_endif

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
name|HAS_SQRTL
end_ifdef

begin_define
define|#
directive|define
name|Perl_cos
value|cosl
end_define

begin_define
define|#
directive|define
name|Perl_sin
value|sinl
end_define

begin_define
define|#
directive|define
name|Perl_sqrt
value|sqrtl
end_define

begin_define
define|#
directive|define
name|Perl_exp
value|expl
end_define

begin_define
define|#
directive|define
name|Perl_log
value|logl
end_define

begin_define
define|#
directive|define
name|Perl_atan2
value|atan2l
end_define

begin_define
define|#
directive|define
name|Perl_pow
value|powl
end_define

begin_define
define|#
directive|define
name|Perl_floor
value|floorl
end_define

begin_define
define|#
directive|define
name|Perl_fmod
value|fmodl
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* e.g. libsunmath doesn't have modfl and frexpl as of mid-March 2000 */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HAS_MODFL
end_ifdef

begin_define
define|#
directive|define
name|Perl_modf
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|modfl(x,y)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|Perl_modf
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|((long double)modf((double)(x),(double*)(y)))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|HAS_FREXPL
end_ifdef

begin_define
define|#
directive|define
name|Perl_frexp
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|frexpl(x,y)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|Perl_frexp
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|((long double)frexp((double)(x),y))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|HAS_ISNANL
end_ifdef

begin_define
define|#
directive|define
name|Perl_isnan
parameter_list|(
name|x
parameter_list|)
value|isnanl(x)
end_define

begin_else
else|#
directive|else
end_else

begin_ifdef
ifdef|#
directive|ifdef
name|HAS_ISNAN
end_ifdef

begin_define
define|#
directive|define
name|Perl_isnan
parameter_list|(
name|x
parameter_list|)
value|isnan((double)(x))
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|Perl_isnan
parameter_list|(
name|x
parameter_list|)
value|((x)!=(x))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|NV_DIG
value|DBL_DIG
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|DBL_MANT_DIG
end_ifdef

begin_define
define|#
directive|define
name|NV_MANT_DIG
value|DBL_MANT_DIG
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|DBL_MAX
end_ifdef

begin_define
define|#
directive|define
name|NV_MAX
value|DBL_MAX
end_define

begin_define
define|#
directive|define
name|NV_MIN
value|DBL_MIN
end_define

begin_else
else|#
directive|else
end_else

begin_ifdef
ifdef|#
directive|ifdef
name|HUGE_VAL
end_ifdef

begin_define
define|#
directive|define
name|NV_MAX
value|HUGE_VAL
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|Perl_cos
value|cos
end_define

begin_define
define|#
directive|define
name|Perl_sin
value|sin
end_define

begin_define
define|#
directive|define
name|Perl_sqrt
value|sqrt
end_define

begin_define
define|#
directive|define
name|Perl_exp
value|exp
end_define

begin_define
define|#
directive|define
name|Perl_log
value|log
end_define

begin_define
define|#
directive|define
name|Perl_atan2
value|atan2
end_define

begin_define
define|#
directive|define
name|Perl_pow
value|pow
end_define

begin_define
define|#
directive|define
name|Perl_floor
value|floor
end_define

begin_define
define|#
directive|define
name|Perl_fmod
value|fmod
end_define

begin_define
define|#
directive|define
name|Perl_modf
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|modf(x,y)
end_define

begin_define
define|#
directive|define
name|Perl_frexp
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|frexp(x,y)
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|HAS_ISNAN
end_ifdef

begin_define
define|#
directive|define
name|Perl_isnan
parameter_list|(
name|x
parameter_list|)
value|isnan(x)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|Perl_isnan
parameter_list|(
name|x
parameter_list|)
value|((x)!=(x))
end_define

begin_endif
endif|#
directive|endif
end_endif

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
name|Perl_atof
argument_list|)
operator|&&
name|defined
argument_list|(
name|USE_LONG_DOUBLE
argument_list|)
operator|&&
name|defined
argument_list|(
name|HAS_LONG_DOUBLE
argument_list|)
end_if

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|Perl_atof
argument_list|)
operator|&&
name|defined
argument_list|(
name|HAS_STRTOLD
argument_list|)
end_if

begin_define
define|#
directive|define
name|Perl_atof
parameter_list|(
name|s
parameter_list|)
value|(NV)strtold(s, (char**)NULL)
end_define

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
name|Perl_atof
argument_list|)
operator|&&
name|defined
argument_list|(
name|HAS_ATOLF
argument_list|)
end_if

begin_define
define|#
directive|define
name|Perl_atof
value|(NV)atolf
end_define

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
name|Perl_atof
argument_list|)
operator|&&
name|defined
argument_list|(
name|PERL_SCNfldbl
argument_list|)
end_if

begin_define
define|#
directive|define
name|Perl_atof
value|PERL_SCNfldbl
end_define

begin_define
define|#
directive|define
name|Perl_atof2
parameter_list|(
name|s
parameter_list|,
name|f
parameter_list|)
value|sscanf((s), "%"PERL_SCNfldbl,&(f))
end_define

begin_endif
endif|#
directive|endif
end_endif

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
name|Perl_atof
argument_list|)
end_if

begin_define
define|#
directive|define
name|Perl_atof
value|atof
end_define

begin_comment
comment|/* we assume atof being available anywhere */
end_comment

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
name|Perl_atof2
argument_list|)
end_if

begin_define
define|#
directive|define
name|Perl_atof2
parameter_list|(
name|s
parameter_list|,
name|f
parameter_list|)
value|((f) = (NV)Perl_atof(s))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Previously these definitions used hardcoded figures.   * It is hoped these formula are more portable, although  * no data one way or another is presently known to me.  * The "PERL_" names are used because these calculated constants  * do not meet the ANSI requirements for LONG_MAX, etc., which  * need to be constants acceptable to #if - kja  *    define PERL_LONG_MAX        2147483647L  *    define PERL_LONG_MIN        (-LONG_MAX - 1)  *    define PERL ULONG_MAX       4294967295L  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|I_LIMITS
end_ifdef

begin_comment
comment|/* Needed for cast_xxx() functions below. */
end_comment

begin_include
include|#
directive|include
file|<limits.h>
end_include

begin_else
else|#
directive|else
end_else

begin_ifdef
ifdef|#
directive|ifdef
name|I_VALUES
end_ifdef

begin_include
include|#
directive|include
file|<values.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Try to figure out max and min values for the integral types.  THE CORRECT  * SOLUTION TO THIS MESS: ADAPT enquire.c FROM GCC INTO CONFIGURE.  The  * following hacks are used if neither limits.h or values.h provide them:  * U<TYPE>_MAX: for types>= int: ~(unsigned TYPE)0  *              for types<  int:  (unsigned TYPE)~(unsigned)0  *	The argument to ~ must be unsigned so that later signed->unsigned  *	conversion can't modify the value's bit pattern (e.g. -0 -> +0),  *	and it must not be smaller than int because ~ does integral promotion.  *<type>_MAX: (<type>) (U<type>_MAX>> 1)  *<type>_MIN: -<type>_MAX -<is_twos_complement_architecture: (3& -1) == 3>.  *	The latter is a hack which happens to work on some machines but  *	does *not* catch any random system, or things like integer types  *	with NaN if that is possible.  *  * All of the types are explicitly cast to prevent accidental loss of  * numeric range, and in the hope that they will be less likely to confuse  * over-eager optimizers.  *  */
end_comment

begin_define
define|#
directive|define
name|PERL_UCHAR_MIN
value|((unsigned char)0)
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|UCHAR_MAX
end_ifdef

begin_define
define|#
directive|define
name|PERL_UCHAR_MAX
value|((unsigned char)UCHAR_MAX)
end_define

begin_else
else|#
directive|else
end_else

begin_ifdef
ifdef|#
directive|ifdef
name|MAXUCHAR
end_ifdef

begin_define
define|#
directive|define
name|PERL_UCHAR_MAX
value|((unsigned char)MAXUCHAR)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|PERL_UCHAR_MAX
value|((unsigned char)~(unsigned)0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * CHAR_MIN and CHAR_MAX are not included here, as the (char) type may be  * ambiguous. It may be equivalent to (signed char) or (unsigned char)  * depending on local options. Until Configure detects this (or at least  * detects whether the "signed" keyword is available) the CHAR ranges  * will not be included. UCHAR functions normally.  *                                                           - kja  */
end_comment

begin_define
define|#
directive|define
name|PERL_USHORT_MIN
value|((unsigned short)0)
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|USHORT_MAX
end_ifdef

begin_define
define|#
directive|define
name|PERL_USHORT_MAX
value|((unsigned short)USHORT_MAX)
end_define

begin_else
else|#
directive|else
end_else

begin_ifdef
ifdef|#
directive|ifdef
name|MAXUSHORT
end_ifdef

begin_define
define|#
directive|define
name|PERL_USHORT_MAX
value|((unsigned short)MAXUSHORT)
end_define

begin_else
else|#
directive|else
end_else

begin_ifdef
ifdef|#
directive|ifdef
name|USHRT_MAX
end_ifdef

begin_define
define|#
directive|define
name|PERL_USHORT_MAX
value|((unsigned short)USHRT_MAX)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|PERL_USHORT_MAX
value|((unsigned short)~(unsigned)0)
end_define

begin_endif
endif|#
directive|endif
end_endif

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
name|SHORT_MAX
end_ifdef

begin_define
define|#
directive|define
name|PERL_SHORT_MAX
value|((short)SHORT_MAX)
end_define

begin_else
else|#
directive|else
end_else

begin_ifdef
ifdef|#
directive|ifdef
name|MAXSHORT
end_ifdef

begin_comment
comment|/* Often used in<values.h> */
end_comment

begin_define
define|#
directive|define
name|PERL_SHORT_MAX
value|((short)MAXSHORT)
end_define

begin_else
else|#
directive|else
end_else

begin_ifdef
ifdef|#
directive|ifdef
name|SHRT_MAX
end_ifdef

begin_define
define|#
directive|define
name|PERL_SHORT_MAX
value|((short)SHRT_MAX)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|PERL_SHORT_MAX
value|((short) (PERL_USHORT_MAX>> 1))
end_define

begin_endif
endif|#
directive|endif
end_endif

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
name|SHORT_MIN
end_ifdef

begin_define
define|#
directive|define
name|PERL_SHORT_MIN
value|((short)SHORT_MIN)
end_define

begin_else
else|#
directive|else
end_else

begin_ifdef
ifdef|#
directive|ifdef
name|MINSHORT
end_ifdef

begin_define
define|#
directive|define
name|PERL_SHORT_MIN
value|((short)MINSHORT)
end_define

begin_else
else|#
directive|else
end_else

begin_ifdef
ifdef|#
directive|ifdef
name|SHRT_MIN
end_ifdef

begin_define
define|#
directive|define
name|PERL_SHORT_MIN
value|((short)SHRT_MIN)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|PERL_SHORT_MIN
value|(-PERL_SHORT_MAX - ((3& -1) == 3))
end_define

begin_endif
endif|#
directive|endif
end_endif

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
name|UINT_MAX
end_ifdef

begin_define
define|#
directive|define
name|PERL_UINT_MAX
value|((unsigned int)UINT_MAX)
end_define

begin_else
else|#
directive|else
end_else

begin_ifdef
ifdef|#
directive|ifdef
name|MAXUINT
end_ifdef

begin_define
define|#
directive|define
name|PERL_UINT_MAX
value|((unsigned int)MAXUINT)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|PERL_UINT_MAX
value|(~(unsigned int)0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|PERL_UINT_MIN
value|((unsigned int)0)
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|INT_MAX
end_ifdef

begin_define
define|#
directive|define
name|PERL_INT_MAX
value|((int)INT_MAX)
end_define

begin_else
else|#
directive|else
end_else

begin_ifdef
ifdef|#
directive|ifdef
name|MAXINT
end_ifdef

begin_comment
comment|/* Often used in<values.h> */
end_comment

begin_define
define|#
directive|define
name|PERL_INT_MAX
value|((int)MAXINT)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|PERL_INT_MAX
value|((int)(PERL_UINT_MAX>> 1))
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
name|INT_MIN
end_ifdef

begin_define
define|#
directive|define
name|PERL_INT_MIN
value|((int)INT_MIN)
end_define

begin_else
else|#
directive|else
end_else

begin_ifdef
ifdef|#
directive|ifdef
name|MININT
end_ifdef

begin_define
define|#
directive|define
name|PERL_INT_MIN
value|((int)MININT)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|PERL_INT_MIN
value|(-PERL_INT_MAX - ((3& -1) == 3))
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
name|ULONG_MAX
end_ifdef

begin_define
define|#
directive|define
name|PERL_ULONG_MAX
value|((unsigned long)ULONG_MAX)
end_define

begin_else
else|#
directive|else
end_else

begin_ifdef
ifdef|#
directive|ifdef
name|MAXULONG
end_ifdef

begin_define
define|#
directive|define
name|PERL_ULONG_MAX
value|((unsigned long)MAXULONG)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|PERL_ULONG_MAX
value|(~(unsigned long)0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|PERL_ULONG_MIN
value|((unsigned long)0L)
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|LONG_MAX
end_ifdef

begin_define
define|#
directive|define
name|PERL_LONG_MAX
value|((long)LONG_MAX)
end_define

begin_else
else|#
directive|else
end_else

begin_ifdef
ifdef|#
directive|ifdef
name|MAXLONG
end_ifdef

begin_comment
comment|/* Often used in<values.h> */
end_comment

begin_define
define|#
directive|define
name|PERL_LONG_MAX
value|((long)MAXLONG)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|PERL_LONG_MAX
value|((long) (PERL_ULONG_MAX>> 1))
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
name|LONG_MIN
end_ifdef

begin_define
define|#
directive|define
name|PERL_LONG_MIN
value|((long)LONG_MIN)
end_define

begin_else
else|#
directive|else
end_else

begin_ifdef
ifdef|#
directive|ifdef
name|MINLONG
end_ifdef

begin_define
define|#
directive|define
name|PERL_LONG_MIN
value|((long)MINLONG)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|PERL_LONG_MIN
value|(-PERL_LONG_MAX - ((3& -1) == 3))
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
name|UV_IS_QUAD
end_ifdef

begin_define
define|#
directive|define
name|PERL_UQUAD_MAX
value|(~(UV)0)
end_define

begin_define
define|#
directive|define
name|PERL_UQUAD_MIN
value|((UV)0)
end_define

begin_define
define|#
directive|define
name|PERL_QUAD_MAX
value|((IV) (PERL_UQUAD_MAX>> 1))
end_define

begin_define
define|#
directive|define
name|PERL_QUAD_MIN
value|(-PERL_QUAD_MAX - ((3& -1) == 3))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_struct
struct|struct
name|perl_mstats
block|{
name|UV
modifier|*
name|nfree
decl_stmt|;
name|UV
modifier|*
name|ntotal
decl_stmt|;
name|IV
name|topbucket
decl_stmt|,
name|topbucket_ev
decl_stmt|,
name|topbucket_odd
decl_stmt|,
name|totfree
decl_stmt|,
name|total
decl_stmt|,
name|total_chain
decl_stmt|;
name|IV
name|total_sbrk
decl_stmt|,
name|sbrks
decl_stmt|,
name|sbrk_good
decl_stmt|,
name|sbrk_slack
decl_stmt|,
name|start_slack
decl_stmt|,
name|sbrked_remains
decl_stmt|;
name|IV
name|minbucket
decl_stmt|;
comment|/* Level 1 info */
name|UV
modifier|*
name|bucket_mem_size
decl_stmt|;
name|UV
modifier|*
name|bucket_available_size
decl_stmt|;
name|UV
name|nbuckets
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|MEM_SIZE
name|STRLEN
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|op
name|OP
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|cop
name|COP
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|unop
name|UNOP
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|binop
name|BINOP
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|listop
name|LISTOP
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|logop
name|LOGOP
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|pmop
name|PMOP
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|svop
name|SVOP
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|padop
name|PADOP
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|pvop
name|PVOP
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|loop
name|LOOP
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|interpreter
name|PerlInterpreter
typedef|;
end_typedef

begin_ifdef
ifdef|#
directive|ifdef
name|UTS
end_ifdef

begin_define
define|#
directive|define
name|STRUCT_SV
value|perl_sv
end_define

begin_comment
comment|/* Amdahl's<ksync.h> has struct sv */
end_comment

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|STRUCT_SV
value|sv
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
name|struct
name|STRUCT_SV
name|SV
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|av
name|AV
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|hv
name|HV
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|cv
name|CV
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|regexp
name|REGEXP
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|gp
name|GP
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|gv
name|GV
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|io
name|IO
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|context
name|PERL_CONTEXT
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|block
name|BLOCK
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|magic
name|MAGIC
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|xrv
name|XRV
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|xpv
name|XPV
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|xpviv
name|XPVIV
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|xpvuv
name|XPVUV
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|xpvnv
name|XPVNV
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|xpvmg
name|XPVMG
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|xpvlv
name|XPVLV
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|xpvav
name|XPVAV
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|xpvhv
name|XPVHV
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|xpvgv
name|XPVGV
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|xpvcv
name|XPVCV
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|xpvbm
name|XPVBM
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|xpvfm
name|XPVFM
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|xpvio
name|XPVIO
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|mgvtbl
name|MGVTBL
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|union
name|any
name|ANY
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|ptr_tbl_ent
name|PTR_TBL_ENT_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|ptr_tbl
name|PTR_TBL_t
typedef|;
end_typedef

begin_include
include|#
directive|include
file|"handy.h"
end_include

begin_if
if|#
directive|if
name|defined
argument_list|(
name|USE_LARGE_FILES
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|NO_64_BIT_RAWIO
argument_list|)
end_if

begin_if
if|#
directive|if
name|LSEEKSIZE
operator|==
literal|8
operator|&&
operator|!
name|defined
argument_list|(
name|USE_64_BIT_RAWIO
argument_list|)
end_if

begin_define
define|#
directive|define
name|USE_64_BIT_RAWIO
end_define

begin_comment
comment|/* implicit */
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
comment|/* Notice the use of HAS_FSEEKO: now we are obligated to always use  * fseeko/ftello if possible.  Don't go #defining ftell to ftello yourself,  * however, because operating systems like to do that themself. */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|FSEEKSIZE
end_ifndef

begin_ifdef
ifdef|#
directive|ifdef
name|HAS_FSEEKO
end_ifdef

begin_define
define|#
directive|define
name|FSEEKSIZE
value|LSEEKSIZE
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|FSEEKSIZE
value|LONGSIZE
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|USE_LARGE_FILES
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|NO_64_BIT_STDIO
argument_list|)
end_if

begin_if
if|#
directive|if
name|FSEEKSIZE
operator|==
literal|8
operator|&&
operator|!
name|defined
argument_list|(
name|USE_64_BIT_STDIO
argument_list|)
end_if

begin_define
define|#
directive|define
name|USE_64_BIT_STDIO
end_define

begin_comment
comment|/* implicit */
end_comment

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
name|USE_64_BIT_RAWIO
end_ifdef

begin_ifdef
ifdef|#
directive|ifdef
name|HAS_OFF64_T
end_ifdef

begin_undef
undef|#
directive|undef
name|Off_t
end_undef

begin_define
define|#
directive|define
name|Off_t
value|off64_t
end_define

begin_undef
undef|#
directive|undef
name|LSEEKSIZE
end_undef

begin_define
define|#
directive|define
name|LSEEKSIZE
value|8
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Most 64-bit environments have defines like _LARGEFILE_SOURCE that  * will trigger defines like the ones below.  Some 64-bit environments,  * however, do not.  Therefore we have to explicitly mix and match. */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|USE_OPEN64
argument_list|)
end_if

begin_define
define|#
directive|define
name|open
value|open64
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|USE_LSEEK64
argument_list|)
end_if

begin_define
define|#
directive|define
name|lseek
value|lseek64
end_define

begin_else
else|#
directive|else
end_else

begin_if
if|#
directive|if
name|defined
argument_list|(
name|USE_LLSEEK
argument_list|)
end_if

begin_define
define|#
directive|define
name|lseek
value|llseek
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|USE_STAT64
argument_list|)
end_if

begin_define
define|#
directive|define
name|stat
value|stat64
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|USE_FSTAT64
argument_list|)
end_if

begin_define
define|#
directive|define
name|fstat
value|fstat64
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|USE_LSTAT64
argument_list|)
end_if

begin_define
define|#
directive|define
name|lstat
value|lstat64
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|USE_FLOCK64
argument_list|)
end_if

begin_define
define|#
directive|define
name|flock
value|flock64
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|USE_LOCKF64
argument_list|)
end_if

begin_define
define|#
directive|define
name|lockf
value|lockf64
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|USE_FCNTL64
argument_list|)
end_if

begin_define
define|#
directive|define
name|fcntl
value|fcntl64
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|USE_TRUNCATE64
argument_list|)
end_if

begin_define
define|#
directive|define
name|truncate
value|truncate64
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|USE_FTRUNCATE64
argument_list|)
end_if

begin_define
define|#
directive|define
name|ftruncate
value|ftruncate64
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
name|USE_64_BIT_STDIO
end_ifdef

begin_ifdef
ifdef|#
directive|ifdef
name|HAS_FPOS64_T
end_ifdef

begin_undef
undef|#
directive|undef
name|Fpos_t
end_undef

begin_define
define|#
directive|define
name|Fpos_t
value|fpos64_t
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Most 64-bit environments have defines like _LARGEFILE_SOURCE that  * will trigger defines like the ones below.  Some 64-bit environments,  * however, do not. */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|USE_FOPEN64
argument_list|)
end_if

begin_define
define|#
directive|define
name|fopen
value|fopen64
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|USE_FSEEK64
argument_list|)
end_if

begin_define
define|#
directive|define
name|fseek
value|fseek64
end_define

begin_comment
comment|/* don't do fseeko here, see perlio.c */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|USE_FTELL64
argument_list|)
end_if

begin_define
define|#
directive|define
name|ftell
value|ftell64
end_define

begin_comment
comment|/* don't do ftello here, see perlio.c */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|USE_FSETPOS64
argument_list|)
end_if

begin_define
define|#
directive|define
name|fsetpos
value|fsetpos64
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|USE_FGETPOS64
argument_list|)
end_if

begin_define
define|#
directive|define
name|fgetpos
value|fgetpos64
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|USE_TMPFILE64
argument_list|)
end_if

begin_define
define|#
directive|define
name|tmpfile
value|tmpfile64
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|USE_FREOPEN64
argument_list|)
end_if

begin_define
define|#
directive|define
name|freopen
value|freopen64
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|OS2
argument_list|)
end_if

begin_include
include|#
directive|include
file|"iperlsys.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__OPEN_VM
argument_list|)
end_if

begin_include
include|#
directive|include
file|"vmesa/vmesaish.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|DOSISH
end_ifdef

begin_if
if|#
directive|if
name|defined
argument_list|(
name|OS2
argument_list|)
end_if

begin_include
include|#
directive|include
file|"os2ish.h"
end_include

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|"dosish.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_else
else|#
directive|else
end_else

begin_if
if|#
directive|if
name|defined
argument_list|(
name|VMS
argument_list|)
end_if

begin_include
include|#
directive|include
file|"vmsish.h"
end_include

begin_else
else|#
directive|else
end_else

begin_if
if|#
directive|if
name|defined
argument_list|(
name|PLAN9
argument_list|)
end_if

begin_include
include|#
directive|include
file|"./plan9/plan9ish.h"
end_include

begin_else
else|#
directive|else
end_else

begin_if
if|#
directive|if
name|defined
argument_list|(
name|MPE
argument_list|)
end_if

begin_include
include|#
directive|include
file|"mpeix/mpeixish.h"
end_include

begin_else
else|#
directive|else
end_else

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__VOS__
argument_list|)
end_if

begin_include
include|#
directive|include
file|"vosish.h"
end_include

begin_else
else|#
directive|else
end_else

begin_if
if|#
directive|if
name|defined
argument_list|(
name|EPOC
argument_list|)
end_if

begin_include
include|#
directive|include
file|"epocish.h"
end_include

begin_else
else|#
directive|else
end_else

begin_if
if|#
directive|if
name|defined
argument_list|(
name|MACOS_TRADITIONAL
argument_list|)
end_if

begin_include
include|#
directive|include
file|"macos/macish.h"
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|NO_ENVIRON_ARRAY
end_ifndef

begin_define
define|#
directive|define
name|NO_ENVIRON_ARRAY
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|"unixish.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|NO_ENVIRON_ARRAY
end_ifndef

begin_define
define|#
directive|define
name|USE_ENVIRON_ARRAY
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|JPL
end_ifdef

begin_comment
comment|/* E.g. JPL needs to operate on a copy of the real environment.      * JDK 1.2 and 1.3 seem to get upset if the original environment      * is diddled with. */
end_comment

begin_define
define|#
directive|define
name|NEED_ENVIRON_DUP_FOR_MODIFY
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|PERL_SYS_INIT3
end_ifndef

begin_define
define|#
directive|define
name|PERL_SYS_INIT3
parameter_list|(
name|argvp
parameter_list|,
name|argcp
parameter_list|,
name|envp
parameter_list|)
value|PERL_SYS_INIT(argvp,argcp)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|MAXPATHLEN
end_ifndef

begin_ifdef
ifdef|#
directive|ifdef
name|PATH_MAX
end_ifdef

begin_ifdef
ifdef|#
directive|ifdef
name|_POSIX_PATH_MAX
end_ifdef

begin_if
if|#
directive|if
name|PATH_MAX
operator|>
name|_POSIX_PATH_MAX
end_if

begin_comment
comment|/* MAXPATHLEN is supposed to include the final null character,  * as opposed to PATH_MAX and _POSIX_PATH_MAX. */
end_comment

begin_define
define|#
directive|define
name|MAXPATHLEN
value|(PATH_MAX+1)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|MAXPATHLEN
value|(_POSIX_PATH_MAX+1)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|MAXPATHLEN
value|(PATH_MAX+1)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_else
else|#
directive|else
end_else

begin_ifdef
ifdef|#
directive|ifdef
name|_POSIX_PATH_MAX
end_ifdef

begin_define
define|#
directive|define
name|MAXPATHLEN
value|(_POSIX_PATH_MAX+1)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|MAXPATHLEN
value|1024
end_define

begin_comment
comment|/* Err on the large side. */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*   * USE_THREADS needs to be after unixish.h as<pthread.h> includes  *<sys/signal.h> which defines NSIG - which will stop inclusion of<signal.h>  * this results in many functions being undeclared which bothers C++  * May make sense to have threads after "*ish.h" anyway  */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|USE_THREADS
argument_list|)
operator|||
name|defined
argument_list|(
name|USE_ITHREADS
argument_list|)
end_if

begin_if
if|#
directive|if
name|defined
argument_list|(
name|USE_THREADS
argument_list|)
end_if

begin_comment
comment|/* pending resolution of licensing issues, we avoid the erstwhile     * atomic.h everywhere */
end_comment

begin_define
define|#
directive|define
name|EMULATE_ATOMIC_REFCOUNTS
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|FAKE_THREADS
end_ifdef

begin_include
include|#
directive|include
file|"fakethr.h"
end_include

begin_else
else|#
directive|else
end_else

begin_ifdef
ifdef|#
directive|ifdef
name|WIN32
end_ifdef

begin_include
include|#
directive|include
file|<win32thread.h>
end_include

begin_else
else|#
directive|else
end_else

begin_ifdef
ifdef|#
directive|ifdef
name|OS2
end_ifdef

begin_include
include|#
directive|include
file|"os2thread.h"
end_include

begin_else
else|#
directive|else
end_else

begin_ifdef
ifdef|#
directive|ifdef
name|I_MACH_CTHREADS
end_ifdef

begin_include
include|#
directive|include
file|<mach/cthreads.h>
end_include

begin_if
if|#
directive|if
operator|(
name|defined
argument_list|(
name|NeXT
argument_list|)
operator|||
name|defined
argument_list|(
name|__NeXT__
argument_list|)
operator|)
operator|&&
name|defined
argument_list|(
name|PERL_POLLUTE_MALLOC
argument_list|)
end_if

begin_define
define|#
directive|define
name|MUTEX_INIT_CALLS_MALLOC
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
name|cthread_t
name|perl_os_thread
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|mutex_t
name|perl_mutex
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|condition_t
name|perl_cond
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|void
modifier|*
name|perl_key
typedef|;
end_typedef

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* Posix threads */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|I_PTHREAD
end_ifdef

begin_include
include|#
directive|include
file|<pthread.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
name|pthread_t
name|perl_os_thread
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|pthread_mutex_t
name|perl_mutex
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|pthread_cond_t
name|perl_cond
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|pthread_key_t
name|perl_key
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* I_MACH_CTHREADS */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* OS2 */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* WIN32 */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* FAKE_THREADS */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* USE_THREADS || USE_ITHREADS */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|WIN32
end_ifdef

begin_include
include|#
directive|include
file|"win32.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|VMS
end_ifdef

begin_define
define|#
directive|define
name|STATUS_NATIVE
value|PL_statusvalue_vms
end_define

begin_define
define|#
directive|define
name|STATUS_NATIVE_EXPORT
define|\
value|(((I32)PL_statusvalue_vms == -1 ? 44 : PL_statusvalue_vms) | (VMSISH_HUSHED ? 0x10000000 : 0))
end_define

begin_define
define|#
directive|define
name|STATUS_NATIVE_SET
parameter_list|(
name|n
parameter_list|)
define|\
value|STMT_START {							\ 	    PL_statusvalue_vms = (n);					\ 	    if ((I32)PL_statusvalue_vms == -1)				\ 		PL_statusvalue = -1;					\ 	    else if (PL_statusvalue_vms& STS$M_SUCCESS)		\ 		PL_statusvalue = 0;					\ 	    else if ((PL_statusvalue_vms& STS$M_SEVERITY) == 0)	\ 		PL_statusvalue = 1<< 8;				\ 	    else							\ 		PL_statusvalue = (PL_statusvalue_vms& STS$M_SEVERITY)<< 8;	\ 	} STMT_END
end_define

begin_define
define|#
directive|define
name|STATUS_POSIX
value|PL_statusvalue
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|VMSISH_STATUS
end_ifdef

begin_define
define|#
directive|define
name|STATUS_CURRENT
value|(VMSISH_STATUS ? STATUS_NATIVE : STATUS_POSIX)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|STATUS_CURRENT
value|STATUS_POSIX
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|STATUS_POSIX_SET
parameter_list|(
name|n
parameter_list|)
define|\
value|STMT_START {					\ 	    PL_statusvalue = (n);				\ 	    if (PL_statusvalue != -1) {			\ 		PL_statusvalue&= 0xFFFF;			\ 		PL_statusvalue_vms = PL_statusvalue ? 44 : 1;	\ 	    }						\ 	    else PL_statusvalue_vms = -1;			\ 	} STMT_END
end_define

begin_define
define|#
directive|define
name|STATUS_ALL_SUCCESS
value|(PL_statusvalue = 0, PL_statusvalue_vms = 1)
end_define

begin_define
define|#
directive|define
name|STATUS_ALL_FAILURE
value|(PL_statusvalue = 1, PL_statusvalue_vms = 44)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|STATUS_NATIVE
value|STATUS_POSIX
end_define

begin_define
define|#
directive|define
name|STATUS_NATIVE_EXPORT
value|STATUS_POSIX
end_define

begin_define
define|#
directive|define
name|STATUS_NATIVE_SET
value|STATUS_POSIX_SET
end_define

begin_define
define|#
directive|define
name|STATUS_POSIX
value|PL_statusvalue
end_define

begin_define
define|#
directive|define
name|STATUS_POSIX_SET
parameter_list|(
name|n
parameter_list|)
define|\
value|STMT_START {			\ 	    PL_statusvalue = (n);		\ 	    if (PL_statusvalue != -1)	\ 		PL_statusvalue&= 0xFFFF;	\ 	} STMT_END
end_define

begin_define
define|#
directive|define
name|STATUS_CURRENT
value|STATUS_POSIX
end_define

begin_define
define|#
directive|define
name|STATUS_ALL_SUCCESS
value|(PL_statusvalue = 0)
end_define

begin_define
define|#
directive|define
name|STATUS_ALL_FAILURE
value|(PL_statusvalue = 1)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* flags in PL_exit_flags for nature of exit() */
end_comment

begin_define
define|#
directive|define
name|PERL_EXIT_EXPECTED
value|0x01
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|MEMBER_TO_FPTR
end_ifndef

begin_define
define|#
directive|define
name|MEMBER_TO_FPTR
parameter_list|(
name|name
parameter_list|)
value|name
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* format to use for version numbers in file/directory names */
end_comment

begin_comment
comment|/* XXX move to Configure? */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|PERL_FS_VER_FMT
end_ifndef

begin_define
define|#
directive|define
name|PERL_FS_VER_FMT
value|"%d.%d.%d"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* This defines a way to flush all output buffers.  This may be a  * performance issue, so we allow people to disable it.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|PERL_FLUSHALL_FOR_CHILD
end_ifndef

begin_if
if|#
directive|if
name|defined
argument_list|(
name|FFLUSH_NULL
argument_list|)
operator|||
name|defined
argument_list|(
name|USE_SFIO
argument_list|)
end_if

begin_define
define|#
directive|define
name|PERL_FLUSHALL_FOR_CHILD
value|PerlIO_flush((PerlIO*)NULL)
end_define

begin_else
else|#
directive|else
end_else

begin_ifdef
ifdef|#
directive|ifdef
name|FFLUSH_ALL
end_ifdef

begin_define
define|#
directive|define
name|PERL_FLUSHALL_FOR_CHILD
value|my_fflush_all()
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|PERL_FLUSHALL_FOR_CHILD
value|NOOP
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|PERL_WAIT_FOR_CHILDREN
end_ifndef

begin_define
define|#
directive|define
name|PERL_WAIT_FOR_CHILDREN
value|NOOP
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* the traditional thread-unsafe notion of "current interpreter". */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|PERL_SET_INTERP
end_ifndef

begin_define
define|#
directive|define
name|PERL_SET_INTERP
parameter_list|(
name|i
parameter_list|)
value|(PL_curinterp = (PerlInterpreter*)(i))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|PERL_GET_INTERP
end_ifndef

begin_define
define|#
directive|define
name|PERL_GET_INTERP
value|(PL_curinterp)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|PERL_IMPLICIT_CONTEXT
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|PERL_GET_THX
argument_list|)
end_if

begin_ifdef
ifdef|#
directive|ifdef
name|USE_THREADS
end_ifdef

begin_define
define|#
directive|define
name|PERL_GET_THX
value|((struct perl_thread *)PERL_GET_CONTEXT)
end_define

begin_else
else|#
directive|else
end_else

begin_ifdef
ifdef|#
directive|ifdef
name|MULTIPLICITY
end_ifdef

begin_define
define|#
directive|define
name|PERL_GET_THX
value|((PerlInterpreter *)PERL_GET_CONTEXT)
end_define

begin_else
else|#
directive|else
end_else

begin_ifdef
ifdef|#
directive|ifdef
name|PERL_OBJECT
end_ifdef

begin_define
define|#
directive|define
name|PERL_GET_THX
value|((CPerlObj *)PERL_GET_CONTEXT)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|PERL_SET_THX
parameter_list|(
name|t
parameter_list|)
value|PERL_SET_CONTEXT(t)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|SVf
end_ifndef

begin_ifdef
ifdef|#
directive|ifdef
name|CHECK_FORMAT
end_ifdef

begin_define
define|#
directive|define
name|SVf
value|"p"
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|SVf
value|"_"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|UVf
end_ifndef

begin_ifdef
ifdef|#
directive|ifdef
name|CHECK_FORMAT
end_ifdef

begin_define
define|#
directive|define
name|UVf
value|UVuf
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|UVf
value|"Vu"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|VDf
end_ifndef

begin_ifdef
ifdef|#
directive|ifdef
name|CHECK_FORMAT
end_ifdef

begin_define
define|#
directive|define
name|VDf
value|"p"
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|VDf
value|"vd"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Some unistd.h's give a prototype for pause() even though    HAS_PAUSE ends up undefined.  This causes the #define    below to be rejected by the compiler.  Sigh. */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HAS_PAUSE
end_ifdef

begin_define
define|#
directive|define
name|Pause
value|pause
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|Pause
parameter_list|()
value|sleep((32767<<16)+32767)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|IOCPARM_LEN
end_ifndef

begin_ifdef
ifdef|#
directive|ifdef
name|IOCPARM_MASK
end_ifdef

begin_comment
comment|/* on BSDish systes we're safe */
end_comment

begin_define
define|#
directive|define
name|IOCPARM_LEN
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 16)& IOCPARM_MASK)
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* otherwise guess at what's safe */
end_comment

begin_define
define|#
directive|define
name|IOCPARM_LEN
parameter_list|(
name|x
parameter_list|)
value|256
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__CYGWIN__
argument_list|)
end_if

begin_comment
comment|/* USEMYBINMODE  *   This symbol, if defined, indicates that the program should  *   use the routine my_binmode(FILE *fp, char iotype, int mode) to insure  *   that a file is in "binary" mode -- that is, that no translation  *   of bytes occurs on read or write operations.  */
end_comment

begin_define
define|#
directive|define
name|USEMYBINMODE
value|/ **/
end_define

begin_define
define|#
directive|define
name|my_binmode
parameter_list|(
name|fp
parameter_list|,
name|iotype
parameter_list|,
name|mode
parameter_list|)
define|\
value|(PerlLIO_setmode(PerlIO_fileno(fp), mode) != -1 ? TRUE : FALSE)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|UNION_ANY_DEFINITION
end_ifdef

begin_expr_stmt
name|UNION_ANY_DEFINITION
expr_stmt|;
end_expr_stmt

begin_else
else|#
directive|else
end_else

begin_union
union|union
name|any
block|{
name|void
modifier|*
name|any_ptr
decl_stmt|;
name|I32
name|any_i32
decl_stmt|;
name|IV
name|any_iv
decl_stmt|;
name|long
name|any_long
decl_stmt|;
name|void
function_decl|(
modifier|*
name|any_dptr
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|any_dxptr
function_decl|)
parameter_list|(
name|pTHXo_
name|void
modifier|*
parameter_list|)
function_decl|;
block|}
union|;
end_union

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|USE_THREADS
end_ifdef

begin_define
define|#
directive|define
name|ARGSproto
value|struct perl_thread *thr
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|ARGSproto
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* USE_THREADS */
end_comment

begin_typedef
typedef|typedef
name|I32
function_decl|(
modifier|*
name|filter_t
function_decl|)
parameter_list|(
name|pTHXo_
name|int
parameter_list|,
name|SV
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_typedef

begin_define
define|#
directive|define
name|FILTER_READ
parameter_list|(
name|idx
parameter_list|,
name|sv
parameter_list|,
name|len
parameter_list|)
value|filter_read(idx, sv, len)
end_define

begin_define
define|#
directive|define
name|FILTER_DATA
parameter_list|(
name|idx
parameter_list|)
value|(AvARRAY(PL_rsfp_filters)[idx])
end_define

begin_define
define|#
directive|define
name|FILTER_ISREADER
parameter_list|(
name|idx
parameter_list|)
value|(idx>= AvFILLp(PL_rsfp_filters))
end_define

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|OS2
argument_list|)
end_if

begin_include
include|#
directive|include
file|"iperlsys.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|"regexp.h"
end_include

begin_include
include|#
directive|include
file|"sv.h"
end_include

begin_include
include|#
directive|include
file|"util.h"
end_include

begin_include
include|#
directive|include
file|"form.h"
end_include

begin_include
include|#
directive|include
file|"gv.h"
end_include

begin_include
include|#
directive|include
file|"cv.h"
end_include

begin_include
include|#
directive|include
file|"opnames.h"
end_include

begin_include
include|#
directive|include
file|"op.h"
end_include

begin_include
include|#
directive|include
file|"cop.h"
end_include

begin_include
include|#
directive|include
file|"av.h"
end_include

begin_include
include|#
directive|include
file|"hv.h"
end_include

begin_include
include|#
directive|include
file|"mg.h"
end_include

begin_include
include|#
directive|include
file|"scope.h"
end_include

begin_include
include|#
directive|include
file|"warnings.h"
end_include

begin_include
include|#
directive|include
file|"utf8.h"
end_include

begin_comment
comment|/* Current curly descriptor */
end_comment

begin_typedef
typedef|typedef
name|struct
name|curcur
name|CURCUR
typedef|;
end_typedef

begin_struct
struct|struct
name|curcur
block|{
name|int
name|parenfloor
decl_stmt|;
comment|/* how far back to strip paren data */
name|int
name|cur
decl_stmt|;
comment|/* how many instances of scan we've matched */
name|int
name|min
decl_stmt|;
comment|/* the minimal number of scans to match */
name|int
name|max
decl_stmt|;
comment|/* the maximal number of scans to match */
name|int
name|minmod
decl_stmt|;
comment|/* whether to work our way up or down */
name|regnode
modifier|*
name|scan
decl_stmt|;
comment|/* the thing to match */
name|regnode
modifier|*
name|next
decl_stmt|;
comment|/* what has to match after it */
name|char
modifier|*
name|lastloc
decl_stmt|;
comment|/* where we started matching this scan */
name|CURCUR
modifier|*
name|oldcc
decl_stmt|;
comment|/* current curly before we started this one */
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|_sublex_info
name|SUBLEXINFO
typedef|;
end_typedef

begin_struct
struct|struct
name|_sublex_info
block|{
name|I32
name|super_state
decl_stmt|;
comment|/* lexer state to save */
name|I32
name|sub_inwhat
decl_stmt|;
comment|/* "lex_inwhat" to use */
name|OP
modifier|*
name|sub_op
decl_stmt|;
comment|/* "lex_op" to use */
name|char
modifier|*
name|super_bufptr
decl_stmt|;
comment|/* PL_bufptr that was */
name|char
modifier|*
name|super_bufend
decl_stmt|;
comment|/* PL_bufend that was */
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|magic_state
name|MGS
typedef|;
end_typedef

begin_comment
comment|/* struct magic_state defined in mg.c */
end_comment

begin_struct_decl
struct_decl|struct
name|scan_data_t
struct_decl|;
end_struct_decl

begin_comment
comment|/* Used in S_* functions in regcomp.c */
end_comment

begin_struct_decl
struct_decl|struct
name|regnode_charclass_class
struct_decl|;
end_struct_decl

begin_comment
comment|/* Used in S_* functions in regcomp.c */
end_comment

begin_typedef
typedef|typedef
name|I32
name|CHECKPOINT
typedef|;
end_typedef

begin_struct
struct|struct
name|ptr_tbl_ent
block|{
name|struct
name|ptr_tbl_ent
modifier|*
name|next
decl_stmt|;
name|void
modifier|*
name|oldval
decl_stmt|;
name|void
modifier|*
name|newval
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|ptr_tbl
block|{
name|struct
name|ptr_tbl_ent
modifier|*
modifier|*
name|tbl_ary
decl_stmt|;
name|UV
name|tbl_max
decl_stmt|;
name|UV
name|tbl_items
decl_stmt|;
block|}
struct|;
end_struct

begin_if
if|#
directive|if
name|defined
argument_list|(
name|iAPX286
argument_list|)
operator|||
name|defined
argument_list|(
name|M_I286
argument_list|)
operator|||
name|defined
argument_list|(
name|I80286
argument_list|)
end_if

begin_define
define|#
directive|define
name|I286
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|htonl
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|HAS_HTONL
argument_list|)
end_if

begin_define
define|#
directive|define
name|HAS_HTONL
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|htons
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|HAS_HTONS
argument_list|)
end_if

begin_define
define|#
directive|define
name|HAS_HTONS
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|ntohl
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|HAS_NTOHL
argument_list|)
end_if

begin_define
define|#
directive|define
name|HAS_NTOHL
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|ntohs
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|HAS_NTOHS
argument_list|)
end_if

begin_define
define|#
directive|define
name|HAS_NTOHS
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|HAS_HTONL
end_ifndef

begin_if
if|#
directive|if
operator|(
name|BYTEORDER
operator|&
literal|0xffff
operator|)
operator|!=
literal|0x4321
end_if

begin_define
define|#
directive|define
name|HAS_HTONS
end_define

begin_define
define|#
directive|define
name|HAS_HTONL
end_define

begin_define
define|#
directive|define
name|HAS_NTOHS
end_define

begin_define
define|#
directive|define
name|HAS_NTOHL
end_define

begin_define
define|#
directive|define
name|MYSWAP
end_define

begin_define
define|#
directive|define
name|htons
value|my_swap
end_define

begin_define
define|#
directive|define
name|htonl
value|my_htonl
end_define

begin_define
define|#
directive|define
name|ntohs
value|my_swap
end_define

begin_define
define|#
directive|define
name|ntohl
value|my_ntohl
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_else
else|#
directive|else
end_else

begin_if
if|#
directive|if
operator|(
name|BYTEORDER
operator|&
literal|0xffff
operator|)
operator|==
literal|0x4321
end_if

begin_undef
undef|#
directive|undef
name|HAS_HTONS
end_undef

begin_undef
undef|#
directive|undef
name|HAS_HTONL
end_undef

begin_undef
undef|#
directive|undef
name|HAS_NTOHS
end_undef

begin_undef
undef|#
directive|undef
name|HAS_NTOHL
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Little-endian byte order functions - 'v' for 'VAX', or 'reVerse'.  * -DWS  */
end_comment

begin_if
if|#
directive|if
name|BYTEORDER
operator|!=
literal|0x1234
end_if

begin_define
define|#
directive|define
name|HAS_VTOHL
end_define

begin_define
define|#
directive|define
name|HAS_VTOHS
end_define

begin_define
define|#
directive|define
name|HAS_HTOVL
end_define

begin_define
define|#
directive|define
name|HAS_HTOVS
end_define

begin_if
if|#
directive|if
name|BYTEORDER
operator|==
literal|0x4321
operator|||
name|BYTEORDER
operator|==
literal|0x87654321
end_if

begin_define
define|#
directive|define
name|vtohl
parameter_list|(
name|x
parameter_list|)
value|((((x)&0xFF)<<24)	\ 			+(((x)>>24)&0xFF)	\ 			+(((x)&0x0000FF00)<<8)	\ 			+(((x)&0x00FF0000)>>8)	)
end_define

begin_define
define|#
directive|define
name|vtohs
parameter_list|(
name|x
parameter_list|)
value|((((x)&0xFF)<<8) + (((x)>>8)&0xFF))
end_define

begin_define
define|#
directive|define
name|htovl
parameter_list|(
name|x
parameter_list|)
value|vtohl(x)
end_define

begin_define
define|#
directive|define
name|htovs
parameter_list|(
name|x
parameter_list|)
value|vtohs(x)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* otherwise default to functions in util.c */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|CASTNEGFLOAT
end_ifdef

begin_define
define|#
directive|define
name|U_S
parameter_list|(
name|what
parameter_list|)
value|((U16)(what))
end_define

begin_define
define|#
directive|define
name|U_I
parameter_list|(
name|what
parameter_list|)
value|((unsigned int)(what))
end_define

begin_define
define|#
directive|define
name|U_L
parameter_list|(
name|what
parameter_list|)
value|((U32)(what))
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|U_S
parameter_list|(
name|what
parameter_list|)
value|((U16)cast_ulong((NV)(what)))
end_define

begin_define
define|#
directive|define
name|U_I
parameter_list|(
name|what
parameter_list|)
value|((unsigned int)cast_ulong((NV)(what)))
end_define

begin_define
define|#
directive|define
name|U_L
parameter_list|(
name|what
parameter_list|)
value|(cast_ulong((NV)(what)))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|CASTI32
end_ifdef

begin_define
define|#
directive|define
name|I_32
parameter_list|(
name|what
parameter_list|)
value|((I32)(what))
end_define

begin_define
define|#
directive|define
name|I_V
parameter_list|(
name|what
parameter_list|)
value|((IV)(what))
end_define

begin_define
define|#
directive|define
name|U_V
parameter_list|(
name|what
parameter_list|)
value|((UV)(what))
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|I_32
parameter_list|(
name|what
parameter_list|)
value|(cast_i32((NV)(what)))
end_define

begin_define
define|#
directive|define
name|I_V
parameter_list|(
name|what
parameter_list|)
value|(cast_iv((NV)(what)))
end_define

begin_define
define|#
directive|define
name|U_V
parameter_list|(
name|what
parameter_list|)
value|(cast_uv((NV)(what)))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* These do not care about the fractional part, only about the range. */
end_comment

begin_define
define|#
directive|define
name|NV_WITHIN_IV
parameter_list|(
name|nv
parameter_list|)
value|(I_V(nv)>= IV_MIN&& I_V(nv)<= IV_MAX)
end_define

begin_define
define|#
directive|define
name|NV_WITHIN_UV
parameter_list|(
name|nv
parameter_list|)
value|((nv)>=0.0&& U_V(nv)>= UV_MIN&& U_V(nv)<= UV_MAX)
end_define

begin_comment
comment|/* Used with UV/IV arguments: */
end_comment

begin_comment
comment|/* XXXX: need to speed it up */
end_comment

begin_define
define|#
directive|define
name|CLUMP_2UV
parameter_list|(
name|iv
parameter_list|)
value|((iv)< 0 ? 0 : (UV)(iv))
end_define

begin_define
define|#
directive|define
name|CLUMP_2IV
parameter_list|(
name|uv
parameter_list|)
value|((uv)> (UV)IV_MAX ? IV_MAX : (IV)(uv))
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|MAXSYSFD
end_ifndef

begin_define
define|#
directive|define
name|MAXSYSFD
value|2
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|__cplusplus
end_ifndef

begin_function_decl
name|Uid_t
name|getuid
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|Uid_t
name|geteuid
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|Gid_t
name|getgid
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|Gid_t
name|getegid
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|Perl_debug_log
end_ifndef

begin_define
define|#
directive|define
name|Perl_debug_log
value|PerlIO_stderr()
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|Perl_error_log
end_ifndef

begin_define
define|#
directive|define
name|Perl_error_log
value|(PL_stderrgv			\&& GvIOp(PL_stderrgv)          \&& IoOFP(GvIOp(PL_stderrgv))	\ 				 ? IoOFP(GvIOp(PL_stderrgv))	\ 				 : PerlIO_stderr())
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|DEBUGGING
end_ifdef

begin_undef
undef|#
directive|undef
name|YYDEBUG
end_undef

begin_define
define|#
directive|define
name|YYDEBUG
value|1
end_define

begin_define
define|#
directive|define
name|DEB
parameter_list|(
name|a
parameter_list|)
value|a
end_define

begin_define
define|#
directive|define
name|DEBUG
parameter_list|(
name|a
parameter_list|)
value|if (PL_debug)		a
end_define

begin_define
define|#
directive|define
name|DEBUG_p
parameter_list|(
name|a
parameter_list|)
value|if (PL_debug& 1)	a
end_define

begin_define
define|#
directive|define
name|DEBUG_s
parameter_list|(
name|a
parameter_list|)
value|if (PL_debug& 2)	a
end_define

begin_define
define|#
directive|define
name|DEBUG_l
parameter_list|(
name|a
parameter_list|)
value|if (PL_debug& 4)	a
end_define

begin_define
define|#
directive|define
name|DEBUG_t
parameter_list|(
name|a
parameter_list|)
value|if (PL_debug& 8)	a
end_define

begin_define
define|#
directive|define
name|DEBUG_o
parameter_list|(
name|a
parameter_list|)
value|if (PL_debug& 16)	a
end_define

begin_define
define|#
directive|define
name|DEBUG_c
parameter_list|(
name|a
parameter_list|)
value|if (PL_debug& 32)	a
end_define

begin_define
define|#
directive|define
name|DEBUG_P
parameter_list|(
name|a
parameter_list|)
value|if (PL_debug& 64)	a
end_define

begin_if
if|#
directive|if
name|defined
argument_list|(
name|PERL_OBJECT
argument_list|)
end_if

begin_define
define|#
directive|define
name|DEBUG_m
parameter_list|(
name|a
parameter_list|)
value|if (PL_debug& 128)	a
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* Temporarily turn off memory debugging in case the a       * does memory allocation, either directly or indirectly. */
end_comment

begin_define
define|#
directive|define
name|DEBUG_m
parameter_list|(
name|a
parameter_list|)
define|\
value|STMT_START {							\         if (PERL_GET_INTERP) { dTHX; if (PL_debug& 128) {PL_debug&=~128; a; PL_debug|=128;} } \     } STMT_END
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|DEBUG_f
parameter_list|(
name|a
parameter_list|)
value|if (PL_debug& 256)	a
end_define

begin_define
define|#
directive|define
name|DEBUG_r
parameter_list|(
name|a
parameter_list|)
value|if (PL_debug& 512)	a
end_define

begin_define
define|#
directive|define
name|DEBUG_x
parameter_list|(
name|a
parameter_list|)
value|if (PL_debug& 1024)	a
end_define

begin_define
define|#
directive|define
name|DEBUG_u
parameter_list|(
name|a
parameter_list|)
value|if (PL_debug& 2048)	a
end_define

begin_define
define|#
directive|define
name|DEBUG_L
parameter_list|(
name|a
parameter_list|)
value|if (PL_debug& 4096)	a
end_define

begin_define
define|#
directive|define
name|DEBUG_H
parameter_list|(
name|a
parameter_list|)
value|if (PL_debug& 8192)	a
end_define

begin_define
define|#
directive|define
name|DEBUG_X
parameter_list|(
name|a
parameter_list|)
value|if (PL_debug& 16384)	a
end_define

begin_define
define|#
directive|define
name|DEBUG_D
parameter_list|(
name|a
parameter_list|)
value|if (PL_debug& 32768)	a
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|USE_THREADS
end_ifdef

begin_define
define|#
directive|define
name|DEBUG_S
parameter_list|(
name|a
parameter_list|)
value|if (PL_debug& (1<<16))	a
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|DEBUG_S
parameter_list|(
name|a
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|DEBUG_T
parameter_list|(
name|a
parameter_list|)
value|if (PL_debug& (1<<17))	a
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|DEB
parameter_list|(
name|a
parameter_list|)
end_define

begin_define
define|#
directive|define
name|DEBUG
parameter_list|(
name|a
parameter_list|)
end_define

begin_define
define|#
directive|define
name|DEBUG_p
parameter_list|(
name|a
parameter_list|)
end_define

begin_define
define|#
directive|define
name|DEBUG_s
parameter_list|(
name|a
parameter_list|)
end_define

begin_define
define|#
directive|define
name|DEBUG_l
parameter_list|(
name|a
parameter_list|)
end_define

begin_define
define|#
directive|define
name|DEBUG_t
parameter_list|(
name|a
parameter_list|)
end_define

begin_define
define|#
directive|define
name|DEBUG_o
parameter_list|(
name|a
parameter_list|)
end_define

begin_define
define|#
directive|define
name|DEBUG_c
parameter_list|(
name|a
parameter_list|)
end_define

begin_define
define|#
directive|define
name|DEBUG_P
parameter_list|(
name|a
parameter_list|)
end_define

begin_define
define|#
directive|define
name|DEBUG_m
parameter_list|(
name|a
parameter_list|)
end_define

begin_define
define|#
directive|define
name|DEBUG_f
parameter_list|(
name|a
parameter_list|)
end_define

begin_define
define|#
directive|define
name|DEBUG_r
parameter_list|(
name|a
parameter_list|)
end_define

begin_define
define|#
directive|define
name|DEBUG_x
parameter_list|(
name|a
parameter_list|)
end_define

begin_define
define|#
directive|define
name|DEBUG_u
parameter_list|(
name|a
parameter_list|)
end_define

begin_define
define|#
directive|define
name|DEBUG_S
parameter_list|(
name|a
parameter_list|)
end_define

begin_define
define|#
directive|define
name|DEBUG_H
parameter_list|(
name|a
parameter_list|)
end_define

begin_define
define|#
directive|define
name|DEBUG_X
parameter_list|(
name|a
parameter_list|)
end_define

begin_define
define|#
directive|define
name|DEBUG_D
parameter_list|(
name|a
parameter_list|)
end_define

begin_define
define|#
directive|define
name|DEBUG_S
parameter_list|(
name|a
parameter_list|)
end_define

begin_define
define|#
directive|define
name|DEBUG_T
parameter_list|(
name|a
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|YYMAXDEPTH
value|300
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|assert
end_ifndef

begin_comment
comment|/*<assert.h> might have been included somehow */
end_comment

begin_define
define|#
directive|define
name|assert
parameter_list|(
name|what
parameter_list|)
value|DEB( {						\ 	if (!(what)) {							\ 	    Perl_croak(aTHX_ "Assertion failed: file \"%s\", line %d",	\ 		__FILE__, __LINE__);					\ 	    PerlProc_exit(1);						\ 	}})
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_struct
struct|struct
name|ufuncs
block|{
name|I32
function_decl|(
modifier|*
name|uf_val
function_decl|)
parameter_list|(
name|IV
parameter_list|,
name|SV
modifier|*
parameter_list|)
function_decl|;
name|I32
function_decl|(
modifier|*
name|uf_set
function_decl|)
parameter_list|(
name|IV
parameter_list|,
name|SV
modifier|*
parameter_list|)
function_decl|;
name|IV
name|uf_index
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* Fix these up for __STDC__ */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|DONT_DECLARE_STD
end_ifndef

begin_function_decl
name|char
modifier|*
name|mktemp
parameter_list|(
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_ifndef
ifndef|#
directive|ifndef
name|atof
end_ifndef

begin_function_decl
name|double
name|atof
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|STANDARD_C
end_ifndef

begin_comment
comment|/* All of these are in stdlib.h or time.h for ANSI C */
end_comment

begin_function_decl
name|Time_t
name|time
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
name|struct
name|tm
modifier|*
name|gmtime
argument_list|()
decl_stmt|,
modifier|*
name|localtime
argument_list|()
decl_stmt|;
end_decl_stmt

begin_if
if|#
directive|if
name|defined
argument_list|(
name|OEMVS
argument_list|)
operator|||
name|defined
argument_list|(
name|__OPEN_VM
argument_list|)
end_if

begin_decl_stmt
name|char
modifier|*
argument_list|(
name|strchr
argument_list|)
argument_list|()
decl_stmt|,
modifier|*
argument_list|(
name|strrchr
argument_list|)
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
argument_list|(
name|strcpy
argument_list|)
argument_list|()
decl_stmt|,
modifier|*
argument_list|(
name|strcat
argument_list|)
argument_list|()
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_decl_stmt
name|char
modifier|*
name|strchr
argument_list|()
decl_stmt|,
modifier|*
name|strrchr
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|strcpy
argument_list|()
decl_stmt|,
modifier|*
name|strcat
argument_list|()
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! STANDARD_C */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|I_MATH
end_ifdef

begin_include
include|#
directive|include
file|<math.h>
end_include

begin_else
else|#
directive|else
end_else

begin_function_decl
name|START_EXTERN_C
name|double
name|exp
parameter_list|(
name|double
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|double
name|log
parameter_list|(
name|double
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|double
name|log10
parameter_list|(
name|double
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|double
name|sqrt
parameter_list|(
name|double
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|double
name|frexp
parameter_list|(
name|double
parameter_list|,
name|int
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|double
name|ldexp
parameter_list|(
name|double
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|double
name|modf
parameter_list|(
name|double
parameter_list|,
name|double
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|double
name|sin
parameter_list|(
name|double
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|double
name|cos
parameter_list|(
name|double
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|double
name|atan2
parameter_list|(
name|double
parameter_list|,
name|double
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|double
name|pow
parameter_list|(
name|double
parameter_list|,
name|double
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|END_EXTERN_C
endif|#
directive|endif
ifndef|#
directive|ifndef
name|__cplusplus
if|#
directive|if
name|defined
argument_list|(
name|NeXT
argument_list|)
operator|||
name|defined
argument_list|(
name|__NeXT__
argument_list|)
comment|/* or whatever catches all NeXTs */
name|char
modifier|*
name|crypt
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* Maybe more hosts will need the unprototyped version */
end_comment

begin_else
else|#
directive|else
end_else

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|WIN32
argument_list|)
end_if

begin_function_decl
name|char
modifier|*
name|crypt
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !WIN32 */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !NeXT&& !__NeXT__ */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|DONT_DECLARE_STD
end_ifndef

begin_ifndef
ifndef|#
directive|ifndef
name|getenv
end_ifndef

begin_function_decl
name|char
modifier|*
name|getenv
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !getenv */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|HAS_LSEEK_PROTO
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|EPOC
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|__hpux
argument_list|)
end_if

begin_ifdef
ifdef|#
directive|ifdef
name|_FILE_OFFSET_BITS
end_ifdef

begin_if
if|#
directive|if
name|_FILE_OFFSET_BITS
operator|==
literal|64
end_if

begin_function_decl
name|Off_t
name|lseek
parameter_list|(
name|int
parameter_list|,
name|Off_t
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !DONT_DECLARE_STD */
end_comment

begin_function_decl
name|char
modifier|*
name|getlogin
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !__cplusplus */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|UNLINK_ALL_VERSIONS
end_ifdef

begin_comment
comment|/* Currently only makes sense for VMS */
end_comment

begin_define
define|#
directive|define
name|UNLINK
value|unlnk
end_define

begin_function_decl
name|I32
name|unlnk
parameter_list|(
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|UNLINK
value|PerlLIO_unlink
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|HAS_SETREUID
end_ifndef

begin_ifdef
ifdef|#
directive|ifdef
name|HAS_SETRESUID
end_ifdef

begin_define
define|#
directive|define
name|setreuid
parameter_list|(
name|r
parameter_list|,
name|e
parameter_list|)
value|setresuid(r,e,(Uid_t)-1)
end_define

begin_define
define|#
directive|define
name|HAS_SETREUID
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|HAS_SETREGID
end_ifndef

begin_ifdef
ifdef|#
directive|ifdef
name|HAS_SETRESGID
end_ifdef

begin_define
define|#
directive|define
name|setregid
parameter_list|(
name|r
parameter_list|,
name|e
parameter_list|)
value|setresgid(r,e,(Gid_t)-1)
end_define

begin_define
define|#
directive|define
name|HAS_SETREGID
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Sighandler_t defined in iperlsys.h */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HAS_SIGACTION
end_ifdef

begin_typedef
typedef|typedef
name|struct
name|sigaction
name|Sigsave_t
typedef|;
end_typedef

begin_else
else|#
directive|else
end_else

begin_typedef
typedef|typedef
name|Sighandler_t
name|Sigsave_t
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|SCAN_DEF
value|0
end_define

begin_define
define|#
directive|define
name|SCAN_TR
value|1
end_define

begin_define
define|#
directive|define
name|SCAN_REPL
value|2
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|DEBUGGING
end_ifdef

begin_ifndef
ifndef|#
directive|ifndef
name|register
end_ifndef

begin_define
define|#
directive|define
name|register
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|PAD_SV
parameter_list|(
name|po
parameter_list|)
value|pad_sv(po)
end_define

begin_define
define|#
directive|define
name|RUNOPS_DEFAULT
value|Perl_runops_debug
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|PAD_SV
parameter_list|(
name|po
parameter_list|)
value|PL_curpad[po]
end_define

begin_define
define|#
directive|define
name|RUNOPS_DEFAULT
value|Perl_runops_standard
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|MYMALLOC
end_ifdef

begin_ifdef
ifdef|#
directive|ifdef
name|MUTEX_INIT_CALLS_MALLOC
end_ifdef

begin_define
define|#
directive|define
name|MALLOC_INIT
define|\
value|STMT_START {					\ 		PL_malloc_mutex = NULL;			\ 		MUTEX_INIT(&PL_malloc_mutex);		\ 	} STMT_END
end_define

begin_define
define|#
directive|define
name|MALLOC_TERM
define|\
value|STMT_START {					\ 		perl_mutex tmp = PL_malloc_mutex;	\ 		PL_malloc_mutex = NULL;			\ 		MUTEX_DESTROY(&tmp);			\ 	} STMT_END
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|MALLOC_INIT
value|MUTEX_INIT(&PL_malloc_mutex)
end_define

begin_define
define|#
directive|define
name|MALLOC_TERM
value|MUTEX_DESTROY(&PL_malloc_mutex)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|MALLOC_INIT
end_define

begin_define
define|#
directive|define
name|MALLOC_TERM
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
name|int
argument_list|(
name|CPERLscope
argument_list|(
operator|*
name|runops_proc_t
argument_list|)
argument_list|)
argument_list|(
name|pTHX
argument_list|)
expr_stmt|;
end_typedef

begin_typedef
typedef|typedef
name|OP
argument_list|*
operator|(
name|CPERLscope
argument_list|(
operator|*
name|PPADDR_t
argument_list|)
index|[]
operator|)
operator|(
name|pTHX
operator|)
argument_list|;
comment|/* _ (for $_) must be first in the following list (DEFSV requires it) */
define|#
directive|define
name|THREADSV_NAMES
value|"_123456789&`'+/.,\\\";^-%=|~:\001\005!@"
comment|/* NeXT has problems with crt0.o globals */
if|#
directive|if
name|defined
argument_list|(
name|__DYNAMIC__
argument_list|)
operator|&&
expr|\
operator|(
name|defined
argument_list|(
name|NeXT
argument_list|)
operator|||
name|defined
argument_list|(
name|__NeXT__
argument_list|)
operator|||
name|defined
argument_list|(
name|__APPLE__
argument_list|)
operator|)
if|#
directive|if
name|defined
argument_list|(
name|NeXT
argument_list|)
operator|||
name|defined
argument_list|(
name|__NeXT
argument_list|)
include|#
directive|include
file|<mach-o/dyld.h>
define|#
directive|define
name|environ
value|(*environ_pointer)
name|EXT
name|char
operator|*
operator|*
operator|*
name|environ_pointer
argument_list|;
else|#
directive|else
if|#
directive|if
name|defined
argument_list|(
name|__APPLE__
argument_list|)
operator|&&
name|defined
argument_list|(
name|PERL_CORE
argument_list|)
include|#
directive|include
file|<crt_externs.h>
comment|/* for the env array */
define|#
directive|define
name|environ
value|(*_NSGetEnviron())
endif|#
directive|endif
endif|#
directive|endif
else|#
directive|else
comment|/* VMS and some other platforms don't use the environ array */
ifdef|#
directive|ifdef
name|USE_ENVIRON_ARRAY
if|#
directive|if
operator|!
name|defined
argument_list|(
name|DONT_DECLARE_STD
argument_list|)
operator|||
expr|\
operator|(
name|defined
argument_list|(
name|__svr4__
argument_list|)
operator|&&
name|defined
argument_list|(
name|__GNUC__
argument_list|)
operator|&&
name|defined
argument_list|(
name|sun
argument_list|)
operator|)
operator|||
expr|\
name|defined
argument_list|(
name|__sgi
argument_list|)
operator|||
expr|\
name|defined
argument_list|(
name|__DGUX
argument_list|)
specifier|extern
name|char
operator|*
operator|*
name|environ
argument_list|;
comment|/* environment variables supplied via exec */
endif|#
directive|endif
endif|#
directive|endif
endif|#
directive|endif
name|START_EXTERN_C
comment|/* handy constants */
name|EXTCONST
name|char
name|PL_warn_uninit
index|[]
name|INIT
argument_list|(
literal|"Use of uninitialized value%s%s"
argument_list|)
argument_list|;
name|EXTCONST
name|char
name|PL_warn_nosemi
index|[]
name|INIT
argument_list|(
literal|"Semicolon seems to be missing"
argument_list|)
argument_list|;
name|EXTCONST
name|char
name|PL_warn_reserved
index|[]
name|INIT
argument_list|(
literal|"Unquoted string \"%s\" may clash with future reserved word"
argument_list|)
argument_list|;
name|EXTCONST
name|char
name|PL_warn_nl
index|[]
name|INIT
argument_list|(
literal|"Unsuccessful %s on filename containing newline"
argument_list|)
argument_list|;
name|EXTCONST
name|char
name|PL_no_wrongref
index|[]
name|INIT
argument_list|(
literal|"Can't use %s ref as %s ref"
argument_list|)
argument_list|;
name|EXTCONST
name|char
name|PL_no_symref
index|[]
name|INIT
argument_list|(
literal|"Can't use string (\"%.32s\") as %s ref while \"strict refs\" in use"
argument_list|)
argument_list|;
name|EXTCONST
name|char
name|PL_no_usym
index|[]
name|INIT
argument_list|(
literal|"Can't use an undefined value as %s reference"
argument_list|)
argument_list|;
name|EXTCONST
name|char
name|PL_no_aelem
index|[]
name|INIT
argument_list|(
literal|"Modification of non-creatable array value attempted, subscript %d"
argument_list|)
argument_list|;
name|EXTCONST
name|char
name|PL_no_helem
index|[]
name|INIT
argument_list|(
literal|"Modification of non-creatable hash value attempted, subscript \"%s\""
argument_list|)
argument_list|;
name|EXTCONST
name|char
name|PL_no_modify
index|[]
name|INIT
argument_list|(
literal|"Modification of a read-only value attempted"
argument_list|)
argument_list|;
name|EXTCONST
name|char
name|PL_no_mem
index|[]
name|INIT
argument_list|(
literal|"Out of memory!\n"
argument_list|)
argument_list|;
name|EXTCONST
name|char
name|PL_no_security
index|[]
name|INIT
argument_list|(
literal|"Insecure dependency in %s%s"
argument_list|)
argument_list|;
name|EXTCONST
name|char
name|PL_no_sock_func
index|[]
name|INIT
argument_list|(
literal|"Unsupported socket function \"%s\" called"
argument_list|)
argument_list|;
name|EXTCONST
name|char
name|PL_no_dir_func
index|[]
name|INIT
argument_list|(
literal|"Unsupported directory function \"%s\" called"
argument_list|)
argument_list|;
name|EXTCONST
name|char
name|PL_no_func
index|[]
name|INIT
argument_list|(
literal|"The %s function is unimplemented"
argument_list|)
argument_list|;
name|EXTCONST
name|char
name|PL_no_myglob
index|[]
name|INIT
argument_list|(
literal|"\"my\" variable %s can't be in a package"
argument_list|)
argument_list|;
name|EXTCONST
name|char
name|PL_uuemap
index|[
literal|65
index|]
name|INIT
argument_list|(
literal|"`!\"#$%&'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\\]^_"
argument_list|)
argument_list|;
ifdef|#
directive|ifdef
name|DOINIT
name|EXT
name|char
operator|*
name|PL_sig_name
index|[]
operator|=
block|{
name|SIG_NAME
block|}
argument_list|;
name|EXT
name|int
name|PL_sig_num
index|[]
operator|=
block|{
name|SIG_NUM
block|}
argument_list|;
else|#
directive|else
name|EXT
name|char
operator|*
name|PL_sig_name
index|[]
argument_list|;
name|EXT
name|int
name|PL_sig_num
index|[]
argument_list|;
endif|#
directive|endif
comment|/* fast case folding tables */
ifdef|#
directive|ifdef
name|DOINIT
ifdef|#
directive|ifdef
name|EBCDIC
name|EXT
name|unsigned
name|char
name|PL_fold
index|[]
operator|=
block|{
comment|/* fast EBCDIC case folding table */
literal|0
block|,
literal|1
block|,
literal|2
block|,
literal|3
block|,
literal|4
block|,
literal|5
block|,
literal|6
block|,
literal|7
block|,
literal|8
block|,
literal|9
block|,
literal|10
block|,
literal|11
block|,
literal|12
block|,
literal|13
block|,
literal|14
block|,
literal|15
block|,
literal|16
block|,
literal|17
block|,
literal|18
block|,
literal|19
block|,
literal|20
block|,
literal|21
block|,
literal|22
block|,
literal|23
block|,
literal|24
block|,
literal|25
block|,
literal|26
block|,
literal|27
block|,
literal|28
block|,
literal|29
block|,
literal|30
block|,
literal|31
block|,
literal|32
block|,
literal|33
block|,
literal|34
block|,
literal|35
block|,
literal|36
block|,
literal|37
block|,
literal|38
block|,
literal|39
block|,
literal|40
block|,
literal|41
block|,
literal|42
block|,
literal|43
block|,
literal|44
block|,
literal|45
block|,
literal|46
block|,
literal|47
block|,
literal|48
block|,
literal|49
block|,
literal|50
block|,
literal|51
block|,
literal|52
block|,
literal|53
block|,
literal|54
block|,
literal|55
block|,
literal|56
block|,
literal|57
block|,
literal|58
block|,
literal|59
block|,
literal|60
block|,
literal|61
block|,
literal|62
block|,
literal|63
block|,
literal|64
block|,
literal|65
block|,
literal|66
block|,
literal|67
block|,
literal|68
block|,
literal|69
block|,
literal|70
block|,
literal|71
block|,
literal|72
block|,
literal|73
block|,
literal|74
block|,
literal|75
block|,
literal|76
block|,
literal|77
block|,
literal|78
block|,
literal|79
block|,
literal|80
block|,
literal|81
block|,
literal|82
block|,
literal|83
block|,
literal|84
block|,
literal|85
block|,
literal|86
block|,
literal|87
block|,
literal|88
block|,
literal|89
block|,
literal|90
block|,
literal|91
block|,
literal|92
block|,
literal|93
block|,
literal|94
block|,
literal|95
block|,
literal|96
block|,
literal|97
block|,
literal|98
block|,
literal|99
block|,
literal|100
block|,
literal|101
block|,
literal|102
block|,
literal|103
block|,
literal|104
block|,
literal|105
block|,
literal|106
block|,
literal|107
block|,
literal|108
block|,
literal|109
block|,
literal|110
block|,
literal|111
block|,
literal|112
block|,
literal|113
block|,
literal|114
block|,
literal|115
block|,
literal|116
block|,
literal|117
block|,
literal|118
block|,
literal|119
block|,
literal|120
block|,
literal|121
block|,
literal|122
block|,
literal|123
block|,
literal|124
block|,
literal|125
block|,
literal|126
block|,
literal|127
block|,
literal|128
block|,
literal|'A'
block|,
literal|'B'
block|,
literal|'C'
block|,
literal|'D'
block|,
literal|'E'
block|,
literal|'F'
block|,
literal|'G'
block|,
literal|'H'
block|,
literal|'I'
block|,
literal|138
block|,
literal|139
block|,
literal|140
block|,
literal|141
block|,
literal|142
block|,
literal|143
block|,
literal|144
block|,
literal|'J'
block|,
literal|'K'
block|,
literal|'L'
block|,
literal|'M'
block|,
literal|'N'
block|,
literal|'O'
block|,
literal|'P'
block|,
literal|'Q'
block|,
literal|'R'
block|,
literal|154
block|,
literal|155
block|,
literal|156
block|,
literal|157
block|,
literal|158
block|,
literal|159
block|,
literal|160
block|,
literal|161
block|,
literal|'S'
block|,
literal|'T'
block|,
literal|'U'
block|,
literal|'V'
block|,
literal|'W'
block|,
literal|'X'
block|,
literal|'Y'
block|,
literal|'Z'
block|,
literal|170
block|,
literal|171
block|,
literal|172
block|,
literal|173
block|,
literal|174
block|,
literal|175
block|,
literal|176
block|,
literal|177
block|,
literal|178
block|,
literal|179
block|,
literal|180
block|,
literal|181
block|,
literal|182
block|,
literal|183
block|,
literal|184
block|,
literal|185
block|,
literal|186
block|,
literal|187
block|,
literal|188
block|,
literal|189
block|,
literal|190
block|,
literal|191
block|,
literal|192
block|,
literal|'a'
block|,
literal|'b'
block|,
literal|'c'
block|,
literal|'d'
block|,
literal|'e'
block|,
literal|'f'
block|,
literal|'g'
block|,
literal|'h'
block|,
literal|'i'
block|,
literal|202
block|,
literal|203
block|,
literal|204
block|,
literal|205
block|,
literal|206
block|,
literal|207
block|,
literal|208
block|,
literal|'j'
block|,
literal|'k'
block|,
literal|'l'
block|,
literal|'m'
block|,
literal|'n'
block|,
literal|'o'
block|,
literal|'p'
block|,
literal|'q'
block|,
literal|'r'
block|,
literal|218
block|,
literal|219
block|,
literal|220
block|,
literal|221
block|,
literal|222
block|,
literal|223
block|,
literal|224
block|,
literal|225
block|,
literal|'s'
block|,
literal|'t'
block|,
literal|'u'
block|,
literal|'v'
block|,
literal|'w'
block|,
literal|'x'
block|,
literal|'y'
block|,
literal|'z'
block|,
literal|234
block|,
literal|235
block|,
literal|236
block|,
literal|237
block|,
literal|238
block|,
literal|239
block|,
literal|240
block|,
literal|241
block|,
literal|242
block|,
literal|243
block|,
literal|244
block|,
literal|245
block|,
literal|246
block|,
literal|247
block|,
literal|248
block|,
literal|249
block|,
literal|250
block|,
literal|251
block|,
literal|252
block|,
literal|253
block|,
literal|254
block|,
literal|255
block|}
argument_list|;
else|#
directive|else
comment|/* ascii rather than ebcdic */
name|EXTCONST
name|unsigned
name|char
name|PL_fold
index|[]
operator|=
block|{
literal|0
block|,
literal|1
block|,
literal|2
block|,
literal|3
block|,
literal|4
block|,
literal|5
block|,
literal|6
block|,
literal|7
block|,
literal|8
block|,
literal|9
block|,
literal|10
block|,
literal|11
block|,
literal|12
block|,
literal|13
block|,
literal|14
block|,
literal|15
block|,
literal|16
block|,
literal|17
block|,
literal|18
block|,
literal|19
block|,
literal|20
block|,
literal|21
block|,
literal|22
block|,
literal|23
block|,
literal|24
block|,
literal|25
block|,
literal|26
block|,
literal|27
block|,
literal|28
block|,
literal|29
block|,
literal|30
block|,
literal|31
block|,
literal|32
block|,
literal|33
block|,
literal|34
block|,
literal|35
block|,
literal|36
block|,
literal|37
block|,
literal|38
block|,
literal|39
block|,
literal|40
block|,
literal|41
block|,
literal|42
block|,
literal|43
block|,
literal|44
block|,
literal|45
block|,
literal|46
block|,
literal|47
block|,
literal|48
block|,
literal|49
block|,
literal|50
block|,
literal|51
block|,
literal|52
block|,
literal|53
block|,
literal|54
block|,
literal|55
block|,
literal|56
block|,
literal|57
block|,
literal|58
block|,
literal|59
block|,
literal|60
block|,
literal|61
block|,
literal|62
block|,
literal|63
block|,
literal|64
block|,
literal|'a'
block|,
literal|'b'
block|,
literal|'c'
block|,
literal|'d'
block|,
literal|'e'
block|,
literal|'f'
block|,
literal|'g'
block|,
literal|'h'
block|,
literal|'i'
block|,
literal|'j'
block|,
literal|'k'
block|,
literal|'l'
block|,
literal|'m'
block|,
literal|'n'
block|,
literal|'o'
block|,
literal|'p'
block|,
literal|'q'
block|,
literal|'r'
block|,
literal|'s'
block|,
literal|'t'
block|,
literal|'u'
block|,
literal|'v'
block|,
literal|'w'
block|,
literal|'x'
block|,
literal|'y'
block|,
literal|'z'
block|,
literal|91
block|,
literal|92
block|,
literal|93
block|,
literal|94
block|,
literal|95
block|,
literal|96
block|,
literal|'A'
block|,
literal|'B'
block|,
literal|'C'
block|,
literal|'D'
block|,
literal|'E'
block|,
literal|'F'
block|,
literal|'G'
block|,
literal|'H'
block|,
literal|'I'
block|,
literal|'J'
block|,
literal|'K'
block|,
literal|'L'
block|,
literal|'M'
block|,
literal|'N'
block|,
literal|'O'
block|,
literal|'P'
block|,
literal|'Q'
block|,
literal|'R'
block|,
literal|'S'
block|,
literal|'T'
block|,
literal|'U'
block|,
literal|'V'
block|,
literal|'W'
block|,
literal|'X'
block|,
literal|'Y'
block|,
literal|'Z'
block|,
literal|123
block|,
literal|124
block|,
literal|125
block|,
literal|126
block|,
literal|127
block|,
literal|128
block|,
literal|129
block|,
literal|130
block|,
literal|131
block|,
literal|132
block|,
literal|133
block|,
literal|134
block|,
literal|135
block|,
literal|136
block|,
literal|137
block|,
literal|138
block|,
literal|139
block|,
literal|140
block|,
literal|141
block|,
literal|142
block|,
literal|143
block|,
literal|144
block|,
literal|145
block|,
literal|146
block|,
literal|147
block|,
literal|148
block|,
literal|149
block|,
literal|150
block|,
literal|151
block|,
literal|152
block|,
literal|153
block|,
literal|154
block|,
literal|155
block|,
literal|156
block|,
literal|157
block|,
literal|158
block|,
literal|159
block|,
literal|160
block|,
literal|161
block|,
literal|162
block|,
literal|163
block|,
literal|164
block|,
literal|165
block|,
literal|166
block|,
literal|167
block|,
literal|168
block|,
literal|169
block|,
literal|170
block|,
literal|171
block|,
literal|172
block|,
literal|173
block|,
literal|174
block|,
literal|175
block|,
literal|176
block|,
literal|177
block|,
literal|178
block|,
literal|179
block|,
literal|180
block|,
literal|181
block|,
literal|182
block|,
literal|183
block|,
literal|184
block|,
literal|185
block|,
literal|186
block|,
literal|187
block|,
literal|188
block|,
literal|189
block|,
literal|190
block|,
literal|191
block|,
literal|192
block|,
literal|193
block|,
literal|194
block|,
literal|195
block|,
literal|196
block|,
literal|197
block|,
literal|198
block|,
literal|199
block|,
literal|200
block|,
literal|201
block|,
literal|202
block|,
literal|203
block|,
literal|204
block|,
literal|205
block|,
literal|206
block|,
literal|207
block|,
literal|208
block|,
literal|209
block|,
literal|210
block|,
literal|211
block|,
literal|212
block|,
literal|213
block|,
literal|214
block|,
literal|215
block|,
literal|216
block|,
literal|217
block|,
literal|218
block|,
literal|219
block|,
literal|220
block|,
literal|221
block|,
literal|222
block|,
literal|223
block|,
literal|224
block|,
literal|225
block|,
literal|226
block|,
literal|227
block|,
literal|228
block|,
literal|229
block|,
literal|230
block|,
literal|231
block|,
literal|232
block|,
literal|233
block|,
literal|234
block|,
literal|235
block|,
literal|236
block|,
literal|237
block|,
literal|238
block|,
literal|239
block|,
literal|240
block|,
literal|241
block|,
literal|242
block|,
literal|243
block|,
literal|244
block|,
literal|245
block|,
literal|246
block|,
literal|247
block|,
literal|248
block|,
literal|249
block|,
literal|250
block|,
literal|251
block|,
literal|252
block|,
literal|253
block|,
literal|254
block|,
literal|255
block|}
argument_list|;
endif|#
directive|endif
comment|/* !EBCDIC */
else|#
directive|else
name|EXTCONST
name|unsigned
name|char
name|PL_fold
index|[]
argument_list|;
endif|#
directive|endif
ifdef|#
directive|ifdef
name|DOINIT
name|EXT
name|unsigned
name|char
name|PL_fold_locale
index|[]
operator|=
block|{
literal|0
block|,
literal|1
block|,
literal|2
block|,
literal|3
block|,
literal|4
block|,
literal|5
block|,
literal|6
block|,
literal|7
block|,
literal|8
block|,
literal|9
block|,
literal|10
block|,
literal|11
block|,
literal|12
block|,
literal|13
block|,
literal|14
block|,
literal|15
block|,
literal|16
block|,
literal|17
block|,
literal|18
block|,
literal|19
block|,
literal|20
block|,
literal|21
block|,
literal|22
block|,
literal|23
block|,
literal|24
block|,
literal|25
block|,
literal|26
block|,
literal|27
block|,
literal|28
block|,
literal|29
block|,
literal|30
block|,
literal|31
block|,
literal|32
block|,
literal|33
block|,
literal|34
block|,
literal|35
block|,
literal|36
block|,
literal|37
block|,
literal|38
block|,
literal|39
block|,
literal|40
block|,
literal|41
block|,
literal|42
block|,
literal|43
block|,
literal|44
block|,
literal|45
block|,
literal|46
block|,
literal|47
block|,
literal|48
block|,
literal|49
block|,
literal|50
block|,
literal|51
block|,
literal|52
block|,
literal|53
block|,
literal|54
block|,
literal|55
block|,
literal|56
block|,
literal|57
block|,
literal|58
block|,
literal|59
block|,
literal|60
block|,
literal|61
block|,
literal|62
block|,
literal|63
block|,
literal|64
block|,
literal|'a'
block|,
literal|'b'
block|,
literal|'c'
block|,
literal|'d'
block|,
literal|'e'
block|,
literal|'f'
block|,
literal|'g'
block|,
literal|'h'
block|,
literal|'i'
block|,
literal|'j'
block|,
literal|'k'
block|,
literal|'l'
block|,
literal|'m'
block|,
literal|'n'
block|,
literal|'o'
block|,
literal|'p'
block|,
literal|'q'
block|,
literal|'r'
block|,
literal|'s'
block|,
literal|'t'
block|,
literal|'u'
block|,
literal|'v'
block|,
literal|'w'
block|,
literal|'x'
block|,
literal|'y'
block|,
literal|'z'
block|,
literal|91
block|,
literal|92
block|,
literal|93
block|,
literal|94
block|,
literal|95
block|,
literal|96
block|,
literal|'A'
block|,
literal|'B'
block|,
literal|'C'
block|,
literal|'D'
block|,
literal|'E'
block|,
literal|'F'
block|,
literal|'G'
block|,
literal|'H'
block|,
literal|'I'
block|,
literal|'J'
block|,
literal|'K'
block|,
literal|'L'
block|,
literal|'M'
block|,
literal|'N'
block|,
literal|'O'
block|,
literal|'P'
block|,
literal|'Q'
block|,
literal|'R'
block|,
literal|'S'
block|,
literal|'T'
block|,
literal|'U'
block|,
literal|'V'
block|,
literal|'W'
block|,
literal|'X'
block|,
literal|'Y'
block|,
literal|'Z'
block|,
literal|123
block|,
literal|124
block|,
literal|125
block|,
literal|126
block|,
literal|127
block|,
literal|128
block|,
literal|129
block|,
literal|130
block|,
literal|131
block|,
literal|132
block|,
literal|133
block|,
literal|134
block|,
literal|135
block|,
literal|136
block|,
literal|137
block|,
literal|138
block|,
literal|139
block|,
literal|140
block|,
literal|141
block|,
literal|142
block|,
literal|143
block|,
literal|144
block|,
literal|145
block|,
literal|146
block|,
literal|147
block|,
literal|148
block|,
literal|149
block|,
literal|150
block|,
literal|151
block|,
literal|152
block|,
literal|153
block|,
literal|154
block|,
literal|155
block|,
literal|156
block|,
literal|157
block|,
literal|158
block|,
literal|159
block|,
literal|160
block|,
literal|161
block|,
literal|162
block|,
literal|163
block|,
literal|164
block|,
literal|165
block|,
literal|166
block|,
literal|167
block|,
literal|168
block|,
literal|169
block|,
literal|170
block|,
literal|171
block|,
literal|172
block|,
literal|173
block|,
literal|174
block|,
literal|175
block|,
literal|176
block|,
literal|177
block|,
literal|178
block|,
literal|179
block|,
literal|180
block|,
literal|181
block|,
literal|182
block|,
literal|183
block|,
literal|184
block|,
literal|185
block|,
literal|186
block|,
literal|187
block|,
literal|188
block|,
literal|189
block|,
literal|190
block|,
literal|191
block|,
literal|192
block|,
literal|193
block|,
literal|194
block|,
literal|195
block|,
literal|196
block|,
literal|197
block|,
literal|198
block|,
literal|199
block|,
literal|200
block|,
literal|201
block|,
literal|202
block|,
literal|203
block|,
literal|204
block|,
literal|205
block|,
literal|206
block|,
literal|207
block|,
literal|208
block|,
literal|209
block|,
literal|210
block|,
literal|211
block|,
literal|212
block|,
literal|213
block|,
literal|214
block|,
literal|215
block|,
literal|216
block|,
literal|217
block|,
literal|218
block|,
literal|219
block|,
literal|220
block|,
literal|221
block|,
literal|222
block|,
literal|223
block|,
literal|224
block|,
literal|225
block|,
literal|226
block|,
literal|227
block|,
literal|228
block|,
literal|229
block|,
literal|230
block|,
literal|231
block|,
literal|232
block|,
literal|233
block|,
literal|234
block|,
literal|235
block|,
literal|236
block|,
literal|237
block|,
literal|238
block|,
literal|239
block|,
literal|240
block|,
literal|241
block|,
literal|242
block|,
literal|243
block|,
literal|244
block|,
literal|245
block|,
literal|246
block|,
literal|247
block|,
literal|248
block|,
literal|249
block|,
literal|250
block|,
literal|251
block|,
literal|252
block|,
literal|253
block|,
literal|254
block|,
literal|255
block|}
argument_list|;
else|#
directive|else
name|EXT
name|unsigned
name|char
name|PL_fold_locale
index|[]
argument_list|;
endif|#
directive|endif
ifdef|#
directive|ifdef
name|DOINIT
ifdef|#
directive|ifdef
name|EBCDIC
name|EXT
name|unsigned
name|char
name|PL_freq
index|[]
operator|=
block|{
comment|/* EBCDIC frequencies for mixed English/C */
literal|1
block|,
literal|2
block|,
literal|84
block|,
literal|151
block|,
literal|154
block|,
literal|155
block|,
literal|156
block|,
literal|157
block|,
literal|165
block|,
literal|246
block|,
literal|250
block|,
literal|3
block|,
literal|158
block|,
literal|7
block|,
literal|18
block|,
literal|29
block|,
literal|40
block|,
literal|51
block|,
literal|62
block|,
literal|73
block|,
literal|85
block|,
literal|96
block|,
literal|107
block|,
literal|118
block|,
literal|129
block|,
literal|140
block|,
literal|147
block|,
literal|148
block|,
literal|149
block|,
literal|150
block|,
literal|152
block|,
literal|153
block|,
literal|255
block|,
literal|6
block|,
literal|8
block|,
literal|9
block|,
literal|10
block|,
literal|11
block|,
literal|12
block|,
literal|13
block|,
literal|14
block|,
literal|15
block|,
literal|24
block|,
literal|25
block|,
literal|26
block|,
literal|27
block|,
literal|28
block|,
literal|226
block|,
literal|29
block|,
literal|30
block|,
literal|31
block|,
literal|32
block|,
literal|33
block|,
literal|43
block|,
literal|44
block|,
literal|45
block|,
literal|46
block|,
literal|47
block|,
literal|48
block|,
literal|49
block|,
literal|50
block|,
literal|76
block|,
literal|77
block|,
literal|78
block|,
literal|79
block|,
literal|80
block|,
literal|81
block|,
literal|82
block|,
literal|83
block|,
literal|84
block|,
literal|85
block|,
literal|86
block|,
literal|87
block|,
literal|94
block|,
literal|95
block|,
literal|234
block|,
literal|181
block|,
literal|233
block|,
literal|187
block|,
literal|190
block|,
literal|180
block|,
literal|96
block|,
literal|97
block|,
literal|98
block|,
literal|99
block|,
literal|100
block|,
literal|101
block|,
literal|102
block|,
literal|104
block|,
literal|112
block|,
literal|182
block|,
literal|174
block|,
literal|236
block|,
literal|232
block|,
literal|229
block|,
literal|103
block|,
literal|228
block|,
literal|226
block|,
literal|114
block|,
literal|115
block|,
literal|116
block|,
literal|117
block|,
literal|118
block|,
literal|119
block|,
literal|120
block|,
literal|121
block|,
literal|122
block|,
literal|235
block|,
literal|176
block|,
literal|230
block|,
literal|194
block|,
literal|162
block|,
literal|130
block|,
literal|131
block|,
literal|132
block|,
literal|133
block|,
literal|134
block|,
literal|135
block|,
literal|136
block|,
literal|137
block|,
literal|138
block|,
literal|139
block|,
literal|201
block|,
literal|205
block|,
literal|163
block|,
literal|217
block|,
literal|220
block|,
literal|224
block|,
literal|5
block|,
literal|248
block|,
literal|227
block|,
literal|244
block|,
literal|242
block|,
literal|255
block|,
literal|241
block|,
literal|231
block|,
literal|240
block|,
literal|253
block|,
literal|16
block|,
literal|197
block|,
literal|19
block|,
literal|20
block|,
literal|21
block|,
literal|187
block|,
literal|23
block|,
literal|169
block|,
literal|210
block|,
literal|245
block|,
literal|237
block|,
literal|249
block|,
literal|247
block|,
literal|239
block|,
literal|168
block|,
literal|252
block|,
literal|34
block|,
literal|196
block|,
literal|36
block|,
literal|37
block|,
literal|38
block|,
literal|39
block|,
literal|41
block|,
literal|42
block|,
literal|251
block|,
literal|254
block|,
literal|238
block|,
literal|223
block|,
literal|221
block|,
literal|213
block|,
literal|225
block|,
literal|177
block|,
literal|52
block|,
literal|53
block|,
literal|54
block|,
literal|55
block|,
literal|56
block|,
literal|57
block|,
literal|58
block|,
literal|59
block|,
literal|60
block|,
literal|61
block|,
literal|63
block|,
literal|64
block|,
literal|65
block|,
literal|66
block|,
literal|67
block|,
literal|68
block|,
literal|69
block|,
literal|70
block|,
literal|71
block|,
literal|72
block|,
literal|74
block|,
literal|75
block|,
literal|205
block|,
literal|208
block|,
literal|186
block|,
literal|202
block|,
literal|200
block|,
literal|218
block|,
literal|198
block|,
literal|179
block|,
literal|178
block|,
literal|214
block|,
literal|88
block|,
literal|89
block|,
literal|90
block|,
literal|91
block|,
literal|92
block|,
literal|93
block|,
literal|217
block|,
literal|166
block|,
literal|170
block|,
literal|207
block|,
literal|199
block|,
literal|209
block|,
literal|206
block|,
literal|204
block|,
literal|160
block|,
literal|212
block|,
literal|105
block|,
literal|106
block|,
literal|108
block|,
literal|109
block|,
literal|110
block|,
literal|111
block|,
literal|203
block|,
literal|113
block|,
literal|216
block|,
literal|215
block|,
literal|192
block|,
literal|175
block|,
literal|193
block|,
literal|243
block|,
literal|172
block|,
literal|161
block|,
literal|123
block|,
literal|124
block|,
literal|125
block|,
literal|126
block|,
literal|127
block|,
literal|128
block|,
literal|222
block|,
literal|219
block|,
literal|211
block|,
literal|195
block|,
literal|188
block|,
literal|193
block|,
literal|185
block|,
literal|184
block|,
literal|191
block|,
literal|183
block|,
literal|141
block|,
literal|142
block|,
literal|143
block|,
literal|144
block|,
literal|145
block|,
literal|146
block|}
argument_list|;
else|#
directive|else
comment|/* ascii rather than ebcdic */
name|EXTCONST
name|unsigned
name|char
name|PL_freq
index|[]
operator|=
block|{
comment|/* letter frequencies for mixed English/C */
literal|1
block|,
literal|2
block|,
literal|84
block|,
literal|151
block|,
literal|154
block|,
literal|155
block|,
literal|156
block|,
literal|157
block|,
literal|165
block|,
literal|246
block|,
literal|250
block|,
literal|3
block|,
literal|158
block|,
literal|7
block|,
literal|18
block|,
literal|29
block|,
literal|40
block|,
literal|51
block|,
literal|62
block|,
literal|73
block|,
literal|85
block|,
literal|96
block|,
literal|107
block|,
literal|118
block|,
literal|129
block|,
literal|140
block|,
literal|147
block|,
literal|148
block|,
literal|149
block|,
literal|150
block|,
literal|152
block|,
literal|153
block|,
literal|255
block|,
literal|182
block|,
literal|224
block|,
literal|205
block|,
literal|174
block|,
literal|176
block|,
literal|180
block|,
literal|217
block|,
literal|233
block|,
literal|232
block|,
literal|236
block|,
literal|187
block|,
literal|235
block|,
literal|228
block|,
literal|234
block|,
literal|226
block|,
literal|222
block|,
literal|219
block|,
literal|211
block|,
literal|195
block|,
literal|188
block|,
literal|193
block|,
literal|185
block|,
literal|184
block|,
literal|191
block|,
literal|183
block|,
literal|201
block|,
literal|229
block|,
literal|181
block|,
literal|220
block|,
literal|194
block|,
literal|162
block|,
literal|163
block|,
literal|208
block|,
literal|186
block|,
literal|202
block|,
literal|200
block|,
literal|218
block|,
literal|198
block|,
literal|179
block|,
literal|178
block|,
literal|214
block|,
literal|166
block|,
literal|170
block|,
literal|207
block|,
literal|199
block|,
literal|209
block|,
literal|206
block|,
literal|204
block|,
literal|160
block|,
literal|212
block|,
literal|216
block|,
literal|215
block|,
literal|192
block|,
literal|175
block|,
literal|173
block|,
literal|243
block|,
literal|172
block|,
literal|161
block|,
literal|190
block|,
literal|203
block|,
literal|189
block|,
literal|164
block|,
literal|230
block|,
literal|167
block|,
literal|248
block|,
literal|227
block|,
literal|244
block|,
literal|242
block|,
literal|255
block|,
literal|241
block|,
literal|231
block|,
literal|240
block|,
literal|253
block|,
literal|169
block|,
literal|210
block|,
literal|245
block|,
literal|237
block|,
literal|249
block|,
literal|247
block|,
literal|239
block|,
literal|168
block|,
literal|252
block|,
literal|251
block|,
literal|254
block|,
literal|238
block|,
literal|223
block|,
literal|221
block|,
literal|213
block|,
literal|225
block|,
literal|177
block|,
literal|197
block|,
literal|171
block|,
literal|196
block|,
literal|159
block|,
literal|4
block|,
literal|5
block|,
literal|6
block|,
literal|8
block|,
literal|9
block|,
literal|10
block|,
literal|11
block|,
literal|12
block|,
literal|13
block|,
literal|14
block|,
literal|15
block|,
literal|16
block|,
literal|17
block|,
literal|19
block|,
literal|20
block|,
literal|21
block|,
literal|22
block|,
literal|23
block|,
literal|24
block|,
literal|25
block|,
literal|26
block|,
literal|27
block|,
literal|28
block|,
literal|30
block|,
literal|31
block|,
literal|32
block|,
literal|33
block|,
literal|34
block|,
literal|35
block|,
literal|36
block|,
literal|37
block|,
literal|38
block|,
literal|39
block|,
literal|41
block|,
literal|42
block|,
literal|43
block|,
literal|44
block|,
literal|45
block|,
literal|46
block|,
literal|47
block|,
literal|48
block|,
literal|49
block|,
literal|50
block|,
literal|52
block|,
literal|53
block|,
literal|54
block|,
literal|55
block|,
literal|56
block|,
literal|57
block|,
literal|58
block|,
literal|59
block|,
literal|60
block|,
literal|61
block|,
literal|63
block|,
literal|64
block|,
literal|65
block|,
literal|66
block|,
literal|67
block|,
literal|68
block|,
literal|69
block|,
literal|70
block|,
literal|71
block|,
literal|72
block|,
literal|74
block|,
literal|75
block|,
literal|76
block|,
literal|77
block|,
literal|78
block|,
literal|79
block|,
literal|80
block|,
literal|81
block|,
literal|82
block|,
literal|83
block|,
literal|86
block|,
literal|87
block|,
literal|88
block|,
literal|89
block|,
literal|90
block|,
literal|91
block|,
literal|92
block|,
literal|93
block|,
literal|94
block|,
literal|95
block|,
literal|97
block|,
literal|98
block|,
literal|99
block|,
literal|100
block|,
literal|101
block|,
literal|102
block|,
literal|103
block|,
literal|104
block|,
literal|105
block|,
literal|106
block|,
literal|108
block|,
literal|109
block|,
literal|110
block|,
literal|111
block|,
literal|112
block|,
literal|113
block|,
literal|114
block|,
literal|115
block|,
literal|116
block|,
literal|117
block|,
literal|119
block|,
literal|120
block|,
literal|121
block|,
literal|122
block|,
literal|123
block|,
literal|124
block|,
literal|125
block|,
literal|126
block|,
literal|127
block|,
literal|128
block|,
literal|130
block|,
literal|131
block|,
literal|132
block|,
literal|133
block|,
literal|134
block|,
literal|135
block|,
literal|136
block|,
literal|137
block|,
literal|138
block|,
literal|139
block|,
literal|141
block|,
literal|142
block|,
literal|143
block|,
literal|144
block|,
literal|145
block|,
literal|146
block|}
argument_list|;
endif|#
directive|endif
else|#
directive|else
name|EXTCONST
name|unsigned
name|char
name|PL_freq
index|[]
argument_list|;
endif|#
directive|endif
ifdef|#
directive|ifdef
name|DEBUGGING
ifdef|#
directive|ifdef
name|DOINIT
name|EXTCONST
name|char
operator|*
name|PL_block_type
index|[]
operator|=
block|{
literal|"NULL"
block|,
literal|"SUB"
block|,
literal|"EVAL"
block|,
literal|"LOOP"
block|,
literal|"SUBST"
block|,
literal|"BLOCK"
block|, }
argument_list|;
else|#
directive|else
name|EXTCONST
name|char
operator|*
name|PL_block_type
index|[]
argument_list|;
endif|#
directive|endif
endif|#
directive|endif
name|END_EXTERN_C
comment|/*****************************************************************************/
comment|/* This lexer/parser stuff is currently global since yacc is hard to reenter */
comment|/*****************************************************************************/
comment|/* XXX This needs to be revisited, since BEGIN makes yacc re-enter... */
include|#
directive|include
file|"perly.h"
define|#
directive|define
name|LEX_NOTPARSING
value|11
comment|/* borrowed from toke.c */
typedef|typedef
enum|enum
block|{
name|XOPERATOR
block|,
name|XTERM
block|,
name|XREF
block|,
name|XSTATE
block|,
name|XBLOCK
block|,
name|XATTRBLOCK
block|,
name|XATTRTERM
block|,
name|XTERMBLOCK
block|}
name|expectation
typedef|;
end_typedef

begin_enum
enum|enum
block|{
comment|/* pass one of these to get_vtbl */
name|want_vtbl_sv
block|,
name|want_vtbl_env
block|,
name|want_vtbl_envelem
block|,
name|want_vtbl_sig
block|,
name|want_vtbl_sigelem
block|,
name|want_vtbl_pack
block|,
name|want_vtbl_packelem
block|,
name|want_vtbl_dbline
block|,
name|want_vtbl_isa
block|,
name|want_vtbl_isaelem
block|,
name|want_vtbl_arylen
block|,
name|want_vtbl_glob
block|,
name|want_vtbl_mglob
block|,
name|want_vtbl_nkeys
block|,
name|want_vtbl_taint
block|,
name|want_vtbl_substr
block|,
name|want_vtbl_vec
block|,
name|want_vtbl_pos
block|,
name|want_vtbl_bm
block|,
name|want_vtbl_fm
block|,
name|want_vtbl_uvar
block|,
name|want_vtbl_defelem
block|,
name|want_vtbl_regexp
block|,
name|want_vtbl_collxfrm
block|,
name|want_vtbl_amagic
block|,
name|want_vtbl_amagicelem
block|,
ifdef|#
directive|ifdef
name|USE_THREADS
name|want_vtbl_mutex
block|,
endif|#
directive|endif
name|want_vtbl_regdata
block|,
name|want_vtbl_regdatum
block|,
name|want_vtbl_backref
block|}
enum|;
end_enum

begin_comment
comment|/* Note: the lowest 8 bits are reserved for 				   stuffing into op->op_private */
end_comment

begin_define
define|#
directive|define
name|HINT_PRIVATE_MASK
value|0x000000ff
end_define

begin_define
define|#
directive|define
name|HINT_INTEGER
value|0x00000001
end_define

begin_define
define|#
directive|define
name|HINT_STRICT_REFS
value|0x00000002
end_define

begin_comment
comment|/* #define HINT_notused4	0x00000004 */
end_comment

begin_define
define|#
directive|define
name|HINT_BYTE
value|0x00000008
end_define

begin_comment
comment|/* #define HINT_notused10	0x00000010 */
end_comment

begin_comment
comment|/* Note: 20,40,80 used for NATIVE_HINTS */
end_comment

begin_define
define|#
directive|define
name|HINT_BLOCK_SCOPE
value|0x00000100
end_define

begin_define
define|#
directive|define
name|HINT_STRICT_SUBS
value|0x00000200
end_define

begin_define
define|#
directive|define
name|HINT_STRICT_VARS
value|0x00000400
end_define

begin_define
define|#
directive|define
name|HINT_LOCALE
value|0x00000800
end_define

begin_define
define|#
directive|define
name|HINT_NEW_INTEGER
value|0x00001000
end_define

begin_define
define|#
directive|define
name|HINT_NEW_FLOAT
value|0x00002000
end_define

begin_define
define|#
directive|define
name|HINT_NEW_BINARY
value|0x00004000
end_define

begin_define
define|#
directive|define
name|HINT_NEW_STRING
value|0x00008000
end_define

begin_define
define|#
directive|define
name|HINT_NEW_RE
value|0x00010000
end_define

begin_define
define|#
directive|define
name|HINT_LOCALIZE_HH
value|0x00020000
end_define

begin_comment
comment|/* %^H needs to be copied */
end_comment

begin_define
define|#
directive|define
name|HINT_RE_TAINT
value|0x00100000
end_define

begin_define
define|#
directive|define
name|HINT_RE_EVAL
value|0x00200000
end_define

begin_define
define|#
directive|define
name|HINT_FILETEST_ACCESS
value|0x00400000
end_define

begin_define
define|#
directive|define
name|HINT_UTF8
value|0x00800000
end_define

begin_comment
comment|/* Various states of an input record separator SV (rs, nrs) */
end_comment

begin_define
define|#
directive|define
name|RsSNARF
parameter_list|(
name|sv
parameter_list|)
value|(! SvOK(sv))
end_define

begin_define
define|#
directive|define
name|RsSIMPLE
parameter_list|(
name|sv
parameter_list|)
value|(SvOK(sv)&& (! SvPOK(sv) || SvCUR(sv)))
end_define

begin_define
define|#
directive|define
name|RsPARA
parameter_list|(
name|sv
parameter_list|)
value|(SvPOK(sv)&& ! SvCUR(sv))
end_define

begin_define
define|#
directive|define
name|RsRECORD
parameter_list|(
name|sv
parameter_list|)
value|(SvROK(sv)&& (SvIV(SvRV(sv))> 0))
end_define

begin_comment
comment|/* Enable variables which are pointers to functions */
end_comment

begin_typedef
typedef|typedef
name|regexp
operator|*
operator|(
name|CPERLscope
argument_list|(
operator|*
name|regcomp_t
argument_list|)
operator|)
operator|(
name|pTHX_
name|char
operator|*
name|exp
operator|,
name|char
operator|*
name|xend
operator|,
name|PMOP
operator|*
name|pm
operator|)
expr_stmt|;
end_typedef

begin_typedef
typedef|typedef
name|I32
argument_list|(
argument|CPERLscope(*regexec_t)
argument_list|)
operator|(
name|pTHX_
name|regexp
operator|*
name|prog
operator|,
name|char
operator|*
name|stringarg
operator|,
name|char
operator|*
name|strend
operator|,
name|char
operator|*
name|strbeg
operator|,
name|I32
name|minend
operator|,
name|SV
operator|*
name|screamer
operator|,
name|void
operator|*
name|data
operator|,
name|U32
name|flags
operator|)
expr_stmt|;
end_typedef

begin_typedef
typedef|typedef
name|char
operator|*
operator|(
name|CPERLscope
argument_list|(
operator|*
name|re_intuit_start_t
argument_list|)
operator|)
operator|(
name|pTHX_
name|regexp
operator|*
name|prog
operator|,
name|SV
operator|*
name|sv
operator|,
name|char
operator|*
name|strpos
operator|,
name|char
operator|*
name|strend
operator|,
name|U32
name|flags
operator|,
expr|struct
name|re_scream_pos_data_s
operator|*
name|d
operator|)
expr_stmt|;
end_typedef

begin_typedef
typedef|typedef
name|SV
operator|*
operator|(
name|CPERLscope
argument_list|(
operator|*
name|re_intuit_string_t
argument_list|)
operator|)
operator|(
name|pTHX_
name|regexp
operator|*
name|prog
operator|)
expr_stmt|;
end_typedef

begin_typedef
typedef|typedef
name|void
argument_list|(
name|CPERLscope
argument_list|(
operator|*
name|regfree_t
argument_list|)
argument_list|)
argument_list|(
name|pTHX_
expr|struct
name|regexp
operator|*
name|r
argument_list|)
expr_stmt|;
end_typedef

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|DESTRUCTORFUNC_NOCONTEXT_t
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|DESTRUCTORFUNC_t
function_decl|)
parameter_list|(
name|pTHXo_
name|void
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|SVFUNC_t
function_decl|)
parameter_list|(
name|pTHXo_
name|SV
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|I32
function_decl|(
modifier|*
name|SVCOMPARE_t
function_decl|)
parameter_list|(
name|pTHXo_
name|SV
modifier|*
parameter_list|,
name|SV
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|XSINIT_t
function_decl|)
parameter_list|(
name|pTHXo
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|ATEXIT_t
function_decl|)
parameter_list|(
name|pTHXo_
name|void
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|XSUBADDR_t
function_decl|)
parameter_list|(
name|pTHXo_
name|CV
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/* Set up PERLVAR macros for populating structs */
end_comment

begin_define
define|#
directive|define
name|PERLVAR
parameter_list|(
name|var
parameter_list|,
name|type
parameter_list|)
value|type var;
end_define

begin_define
define|#
directive|define
name|PERLVARA
parameter_list|(
name|var
parameter_list|,
name|n
parameter_list|,
name|type
parameter_list|)
value|type var[n];
end_define

begin_define
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
value|type var;
end_define

begin_define
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
value|type var;
end_define

begin_comment
comment|/* Interpreter exitlist entry */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|exitlistentry
block|{
name|void
function_decl|(
modifier|*
name|fn
function_decl|)
parameter_list|(
name|pTHXo_
name|void
modifier|*
parameter_list|)
function_decl|;
name|void
modifier|*
name|ptr
decl_stmt|;
block|}
name|PerlExitListEntry
typedef|;
end_typedef

begin_ifdef
ifdef|#
directive|ifdef
name|PERL_GLOBAL_STRUCT
end_ifdef

begin_struct
struct|struct
name|perl_vars
block|{
include|#
directive|include
file|"perlvars.h"
block|}
struct|;
end_struct

begin_ifdef
ifdef|#
directive|ifdef
name|PERL_CORE
end_ifdef

begin_decl_stmt
name|EXT
name|struct
name|perl_vars
name|PL_Vars
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|EXT
name|struct
name|perl_vars
modifier|*
name|PL_VarsPtr
name|INIT
argument_list|(
operator|&
name|PL_Vars
argument_list|)
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* PERL_CORE */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|__GNUC__
argument_list|)
operator|||
operator|!
name|defined
argument_list|(
name|WIN32
argument_list|)
end_if

begin_decl_stmt
name|EXT
endif|#
directive|endif
comment|/* WIN32 */
name|struct
name|perl_vars
modifier|*
name|PL_VarsPtr
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|PL_Vars
value|(*((PL_VarsPtr) \ 		       ? PL_VarsPtr : (PL_VarsPtr = Perl_GetVars(aTHX))))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* PERL_CORE */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* PERL_GLOBAL_STRUCT */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|MULTIPLICITY
argument_list|)
operator|||
name|defined
argument_list|(
name|PERL_OBJECT
argument_list|)
end_if

begin_comment
comment|/* If we have multiple interpreters define a struct     holding variables which must be per-interpreter    If we don't have threads anything that would have     be per-thread is per-interpreter. */
end_comment

begin_struct
struct|struct
name|interpreter
block|{
ifndef|#
directive|ifndef
name|USE_THREADS
include|#
directive|include
file|"thrdvar.h"
endif|#
directive|endif
include|#
directive|include
file|"intrpvar.h"
comment|/*  * The following is a buffer where new variables must  * be defined to maintain binary compatibility with PERL_OBJECT  */
name|PERLVARA
argument_list|(
argument|object_compatibility
argument_list|,
literal|30
argument_list|,
argument|char
argument_list|)
block|}
struct|;
end_struct

begin_else
else|#
directive|else
end_else

begin_struct
struct|struct
name|interpreter
block|{
name|char
name|broiled
decl_stmt|;
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* MULTIPLICITY || PERL_OBJECT */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|USE_THREADS
end_ifdef

begin_comment
comment|/* If we have threads define a struct with all the variables  * that have to be per-thread  */
end_comment

begin_struct
struct|struct
name|perl_thread
block|{
include|#
directive|include
file|"thrdvar.h"
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|perl_thread
modifier|*
name|Thread
typedef|;
end_typedef

begin_else
else|#
directive|else
end_else

begin_typedef
typedef|typedef
name|void
modifier|*
name|Thread
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Done with PERLVAR macros for now ... */
end_comment

begin_undef
undef|#
directive|undef
name|PERLVAR
end_undef

begin_undef
undef|#
directive|undef
name|PERLVARA
end_undef

begin_undef
undef|#
directive|undef
name|PERLVARI
end_undef

begin_undef
undef|#
directive|undef
name|PERLVARIC
end_undef

begin_include
include|#
directive|include
file|"thread.h"
end_include

begin_include
include|#
directive|include
file|"pp.h"
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|PERL_CALLCONV
end_ifndef

begin_define
define|#
directive|define
name|PERL_CALLCONV
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|NEXT30_NO_ATTRIBUTE
end_ifndef

begin_ifndef
ifndef|#
directive|ifndef
name|HASATTRIBUTE
end_ifndef

begin_comment
comment|/* disable GNU-cc attribute checking? */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__attribute__
end_ifdef

begin_comment
comment|/* Avoid possible redefinition errors */
end_comment

begin_undef
undef|#
directive|undef
name|__attribute__
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|__attribute__
parameter_list|(
name|attr
parameter_list|)
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
name|PERL_OBJECT
end_ifdef

begin_define
define|#
directive|define
name|PERL_DECL_PROT
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_undef
undef|#
directive|undef
name|PERL_CKDEF
end_undef

begin_undef
undef|#
directive|undef
name|PERL_PPDEF
end_undef

begin_define
define|#
directive|define
name|PERL_CKDEF
parameter_list|(
name|s
parameter_list|)
value|OP *s (pTHX_ OP *o);
end_define

begin_define
define|#
directive|define
name|PERL_PPDEF
parameter_list|(
name|s
parameter_list|)
value|OP *s (pTHX);
end_define

begin_include
include|#
directive|include
file|"proto.h"
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|PERL_OBJECT
end_ifdef

begin_undef
undef|#
directive|undef
name|PERL_DECL_PROT
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|PERL_OBJECT
end_ifndef

begin_comment
comment|/* this has structure inits, so it cannot be included before here */
end_comment

begin_include
include|#
directive|include
file|"opcode.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* The following must follow proto.h as #defines mess up syntax */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|PERL_FOR_X2P
argument_list|)
end_if

begin_include
include|#
directive|include
file|"embedvar.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Now include all the 'global' variables   * If we don't have threads or multiple interpreters  * these include variables that would have been their struct-s   */
end_comment

begin_define
define|#
directive|define
name|PERLVAR
parameter_list|(
name|var
parameter_list|,
name|type
parameter_list|)
value|EXT type PL_##var;
end_define

begin_define
define|#
directive|define
name|PERLVARA
parameter_list|(
name|var
parameter_list|,
name|n
parameter_list|,
name|type
parameter_list|)
value|EXT type PL_##var[n];
end_define

begin_define
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
value|EXT type  PL_##var INIT(init);
end_define

begin_define
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
value|EXTCONST type PL_##var INIT(init);
end_define

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|MULTIPLICITY
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|PERL_OBJECT
argument_list|)
end_if

begin_decl_stmt
name|START_EXTERN_C
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
name|END_EXTERN_C
endif|#
directive|endif
ifdef|#
directive|ifdef
name|PERL_OBJECT
include|#
directive|include
file|"embed.h"
ifdef|#
directive|ifdef
name|DOINIT
include|#
directive|include
file|"INTERN.h"
else|#
directive|else
include|#
directive|include
file|"EXTERN.h"
endif|#
directive|endif
comment|/* this has structure inits, so it cannot be included before here */
include|#
directive|include
file|"opcode.h"
else|#
directive|else
if|#
directive|if
name|defined
argument_list|(
name|WIN32
argument_list|)
include|#
directive|include
file|"embed.h"
endif|#
directive|endif
endif|#
directive|endif
comment|/* PERL_OBJECT */
ifndef|#
directive|ifndef
name|PERL_GLOBAL_STRUCT
name|START_EXTERN_C
include|#
directive|include
file|"perlvars.h"
name|END_EXTERN_C
endif|#
directive|endif
undef|#
directive|undef
name|PERLVAR
undef|#
directive|undef
name|PERLVARA
undef|#
directive|undef
name|PERLVARI
undef|#
directive|undef
name|PERLVARIC
name|START_EXTERN_C
ifdef|#
directive|ifdef
name|DOINIT
name|EXT
name|MGVTBL
name|PL_vtbl_sv
init|=
block|{
name|MEMBER_TO_FPTR
argument_list|(
name|Perl_magic_get
argument_list|)
block|,
name|MEMBER_TO_FPTR
argument_list|(
name|Perl_magic_set
argument_list|)
block|,
name|MEMBER_TO_FPTR
argument_list|(
name|Perl_magic_len
argument_list|)
block|,
literal|0
block|,
literal|0
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|EXT
name|MGVTBL
name|PL_vtbl_env
init|=
block|{
literal|0
block|,
name|MEMBER_TO_FPTR
argument_list|(
name|Perl_magic_set_all_env
argument_list|)
block|,
literal|0
block|,
name|MEMBER_TO_FPTR
argument_list|(
name|Perl_magic_clear_all_env
argument_list|)
block|,
literal|0
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|EXT
name|MGVTBL
name|PL_vtbl_envelem
init|=
block|{
literal|0
block|,
name|MEMBER_TO_FPTR
argument_list|(
name|Perl_magic_setenv
argument_list|)
block|,
literal|0
block|,
name|MEMBER_TO_FPTR
argument_list|(
name|Perl_magic_clearenv
argument_list|)
block|,
literal|0
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|EXT
name|MGVTBL
name|PL_vtbl_sig
init|=
block|{
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|EXT
name|MGVTBL
name|PL_vtbl_sigelem
init|=
block|{
name|MEMBER_TO_FPTR
argument_list|(
name|Perl_magic_getsig
argument_list|)
block|,
name|MEMBER_TO_FPTR
argument_list|(
name|Perl_magic_setsig
argument_list|)
block|,
literal|0
block|,
name|MEMBER_TO_FPTR
argument_list|(
name|Perl_magic_clearsig
argument_list|)
block|,
literal|0
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|EXT
name|MGVTBL
name|PL_vtbl_pack
init|=
block|{
literal|0
block|,
literal|0
block|,
name|MEMBER_TO_FPTR
argument_list|(
name|Perl_magic_sizepack
argument_list|)
block|,
name|MEMBER_TO_FPTR
argument_list|(
name|Perl_magic_wipepack
argument_list|)
block|,
literal|0
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|EXT
name|MGVTBL
name|PL_vtbl_packelem
init|=
block|{
name|MEMBER_TO_FPTR
argument_list|(
name|Perl_magic_getpack
argument_list|)
block|,
name|MEMBER_TO_FPTR
argument_list|(
name|Perl_magic_setpack
argument_list|)
block|,
literal|0
block|,
name|MEMBER_TO_FPTR
argument_list|(
name|Perl_magic_clearpack
argument_list|)
block|,
literal|0
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|EXT
name|MGVTBL
name|PL_vtbl_dbline
init|=
block|{
literal|0
block|,
name|MEMBER_TO_FPTR
argument_list|(
name|Perl_magic_setdbline
argument_list|)
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|EXT
name|MGVTBL
name|PL_vtbl_isa
init|=
block|{
literal|0
block|,
name|MEMBER_TO_FPTR
argument_list|(
name|Perl_magic_setisa
argument_list|)
block|,
literal|0
block|,
name|MEMBER_TO_FPTR
argument_list|(
name|Perl_magic_setisa
argument_list|)
block|,
literal|0
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|EXT
name|MGVTBL
name|PL_vtbl_isaelem
init|=
block|{
literal|0
block|,
name|MEMBER_TO_FPTR
argument_list|(
name|Perl_magic_setisa
argument_list|)
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|EXT
name|MGVTBL
name|PL_vtbl_arylen
init|=
block|{
name|MEMBER_TO_FPTR
argument_list|(
name|Perl_magic_getarylen
argument_list|)
block|,
name|MEMBER_TO_FPTR
argument_list|(
name|Perl_magic_setarylen
argument_list|)
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|EXT
name|MGVTBL
name|PL_vtbl_glob
init|=
block|{
name|MEMBER_TO_FPTR
argument_list|(
name|Perl_magic_getglob
argument_list|)
block|,
name|MEMBER_TO_FPTR
argument_list|(
name|Perl_magic_setglob
argument_list|)
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|EXT
name|MGVTBL
name|PL_vtbl_mglob
init|=
block|{
literal|0
block|,
name|MEMBER_TO_FPTR
argument_list|(
name|Perl_magic_setmglob
argument_list|)
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|EXT
name|MGVTBL
name|PL_vtbl_nkeys
init|=
block|{
name|MEMBER_TO_FPTR
argument_list|(
name|Perl_magic_getnkeys
argument_list|)
block|,
name|MEMBER_TO_FPTR
argument_list|(
name|Perl_magic_setnkeys
argument_list|)
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|EXT
name|MGVTBL
name|PL_vtbl_taint
init|=
block|{
name|MEMBER_TO_FPTR
argument_list|(
name|Perl_magic_gettaint
argument_list|)
block|,
name|MEMBER_TO_FPTR
argument_list|(
name|Perl_magic_settaint
argument_list|)
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|EXT
name|MGVTBL
name|PL_vtbl_substr
init|=
block|{
name|MEMBER_TO_FPTR
argument_list|(
name|Perl_magic_getsubstr
argument_list|)
block|,
name|MEMBER_TO_FPTR
argument_list|(
name|Perl_magic_setsubstr
argument_list|)
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|EXT
name|MGVTBL
name|PL_vtbl_vec
init|=
block|{
name|MEMBER_TO_FPTR
argument_list|(
name|Perl_magic_getvec
argument_list|)
block|,
name|MEMBER_TO_FPTR
argument_list|(
name|Perl_magic_setvec
argument_list|)
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|EXT
name|MGVTBL
name|PL_vtbl_pos
init|=
block|{
name|MEMBER_TO_FPTR
argument_list|(
name|Perl_magic_getpos
argument_list|)
block|,
name|MEMBER_TO_FPTR
argument_list|(
name|Perl_magic_setpos
argument_list|)
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|EXT
name|MGVTBL
name|PL_vtbl_bm
init|=
block|{
literal|0
block|,
name|MEMBER_TO_FPTR
argument_list|(
name|Perl_magic_setbm
argument_list|)
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|EXT
name|MGVTBL
name|PL_vtbl_fm
init|=
block|{
literal|0
block|,
name|MEMBER_TO_FPTR
argument_list|(
name|Perl_magic_setfm
argument_list|)
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|EXT
name|MGVTBL
name|PL_vtbl_uvar
init|=
block|{
name|MEMBER_TO_FPTR
argument_list|(
name|Perl_magic_getuvar
argument_list|)
block|,
name|MEMBER_TO_FPTR
argument_list|(
name|Perl_magic_setuvar
argument_list|)
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|}
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|USE_THREADS
end_ifdef

begin_decl_stmt
name|EXT
name|MGVTBL
name|PL_vtbl_mutex
init|=
block|{
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
name|MEMBER_TO_FPTR
argument_list|(
argument|Perl_magic_mutexfree
argument_list|)
block|}
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
name|EXT
name|MGVTBL
name|PL_vtbl_defelem
init|=
block|{
name|MEMBER_TO_FPTR
argument_list|(
name|Perl_magic_getdefelem
argument_list|)
block|,
name|MEMBER_TO_FPTR
argument_list|(
name|Perl_magic_setdefelem
argument_list|)
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|EXT
name|MGVTBL
name|PL_vtbl_regexp
init|=
block|{
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
name|MEMBER_TO_FPTR
argument_list|(
argument|Perl_magic_freeregexp
argument_list|)
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|EXT
name|MGVTBL
name|PL_vtbl_regdata
init|=
block|{
literal|0
block|,
literal|0
block|,
name|MEMBER_TO_FPTR
argument_list|(
name|Perl_magic_regdata_cnt
argument_list|)
block|,
literal|0
block|,
literal|0
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|EXT
name|MGVTBL
name|PL_vtbl_regdatum
init|=
block|{
name|MEMBER_TO_FPTR
argument_list|(
name|Perl_magic_regdatum_get
argument_list|)
block|,
name|MEMBER_TO_FPTR
argument_list|(
name|Perl_magic_regdatum_set
argument_list|)
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|}
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|USE_LOCALE_COLLATE
end_ifdef

begin_decl_stmt
name|EXT
name|MGVTBL
name|PL_vtbl_collxfrm
init|=
block|{
literal|0
block|,
name|MEMBER_TO_FPTR
argument_list|(
name|Perl_magic_setcollxfrm
argument_list|)
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|}
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
name|EXT
name|MGVTBL
name|PL_vtbl_amagic
init|=
block|{
literal|0
block|,
name|MEMBER_TO_FPTR
argument_list|(
name|Perl_magic_setamagic
argument_list|)
block|,
literal|0
block|,
literal|0
block|,
name|MEMBER_TO_FPTR
argument_list|(
argument|Perl_magic_setamagic
argument_list|)
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|EXT
name|MGVTBL
name|PL_vtbl_amagicelem
init|=
block|{
literal|0
block|,
name|MEMBER_TO_FPTR
argument_list|(
name|Perl_magic_setamagic
argument_list|)
block|,
literal|0
block|,
literal|0
block|,
name|MEMBER_TO_FPTR
argument_list|(
argument|Perl_magic_setamagic
argument_list|)
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|EXT
name|MGVTBL
name|PL_vtbl_backref
init|=
block|{
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
name|MEMBER_TO_FPTR
argument_list|(
argument|Perl_magic_killbackrefs
argument_list|)
block|}
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* !DOINIT */
end_comment

begin_decl_stmt
name|EXT
name|MGVTBL
name|PL_vtbl_sv
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|EXT
name|MGVTBL
name|PL_vtbl_env
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|EXT
name|MGVTBL
name|PL_vtbl_envelem
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|EXT
name|MGVTBL
name|PL_vtbl_sig
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|EXT
name|MGVTBL
name|PL_vtbl_sigelem
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|EXT
name|MGVTBL
name|PL_vtbl_pack
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|EXT
name|MGVTBL
name|PL_vtbl_packelem
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|EXT
name|MGVTBL
name|PL_vtbl_dbline
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|EXT
name|MGVTBL
name|PL_vtbl_isa
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|EXT
name|MGVTBL
name|PL_vtbl_isaelem
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|EXT
name|MGVTBL
name|PL_vtbl_arylen
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|EXT
name|MGVTBL
name|PL_vtbl_glob
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|EXT
name|MGVTBL
name|PL_vtbl_mglob
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|EXT
name|MGVTBL
name|PL_vtbl_nkeys
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|EXT
name|MGVTBL
name|PL_vtbl_taint
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|EXT
name|MGVTBL
name|PL_vtbl_substr
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|EXT
name|MGVTBL
name|PL_vtbl_vec
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|EXT
name|MGVTBL
name|PL_vtbl_pos
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|EXT
name|MGVTBL
name|PL_vtbl_bm
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|EXT
name|MGVTBL
name|PL_vtbl_fm
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|EXT
name|MGVTBL
name|PL_vtbl_uvar
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|USE_THREADS
end_ifdef

begin_decl_stmt
name|EXT
name|MGVTBL
name|PL_vtbl_mutex
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
name|EXT
name|MGVTBL
name|PL_vtbl_defelem
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|EXT
name|MGVTBL
name|PL_vtbl_regexp
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|EXT
name|MGVTBL
name|PL_vtbl_regdata
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|EXT
name|MGVTBL
name|PL_vtbl_regdatum
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|USE_LOCALE_COLLATE
end_ifdef

begin_decl_stmt
name|EXT
name|MGVTBL
name|PL_vtbl_collxfrm
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
name|EXT
name|MGVTBL
name|PL_vtbl_amagic
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|EXT
name|MGVTBL
name|PL_vtbl_amagicelem
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|EXT
name|MGVTBL
name|PL_vtbl_backref
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !DOINIT */
end_comment

begin_enum
enum|enum
block|{
name|fallback_amg
block|,
name|abs_amg
block|,
name|bool__amg
block|,
name|nomethod_amg
block|,
name|string_amg
block|,
name|numer_amg
block|,
name|add_amg
block|,
name|add_ass_amg
block|,
name|subtr_amg
block|,
name|subtr_ass_amg
block|,
name|mult_amg
block|,
name|mult_ass_amg
block|,
name|div_amg
block|,
name|div_ass_amg
block|,
name|modulo_amg
block|,
name|modulo_ass_amg
block|,
name|pow_amg
block|,
name|pow_ass_amg
block|,
name|lshift_amg
block|,
name|lshift_ass_amg
block|,
name|rshift_amg
block|,
name|rshift_ass_amg
block|,
name|band_amg
block|,
name|band_ass_amg
block|,
name|bor_amg
block|,
name|bor_ass_amg
block|,
name|bxor_amg
block|,
name|bxor_ass_amg
block|,
name|lt_amg
block|,
name|le_amg
block|,
name|gt_amg
block|,
name|ge_amg
block|,
name|eq_amg
block|,
name|ne_amg
block|,
name|ncmp_amg
block|,
name|scmp_amg
block|,
name|slt_amg
block|,
name|sle_amg
block|,
name|sgt_amg
block|,
name|sge_amg
block|,
name|seq_amg
block|,
name|sne_amg
block|,
name|not_amg
block|,
name|compl_amg
block|,
name|inc_amg
block|,
name|dec_amg
block|,
name|atan2_amg
block|,
name|cos_amg
block|,
name|sin_amg
block|,
name|exp_amg
block|,
name|log_amg
block|,
name|sqrt_amg
block|,
name|repeat_amg
block|,
name|repeat_ass_amg
block|,
name|concat_amg
block|,
name|concat_ass_amg
block|,
name|copy_amg
block|,
name|neg_amg
block|,
name|to_sv_amg
block|,
name|to_av_amg
block|,
name|to_hv_amg
block|,
name|to_gv_amg
block|,
name|to_cv_amg
block|,
name|iter_amg
block|,
name|max_amg_code
comment|/* Do not leave a trailing comma here.  C9X allows it, C89 doesn't. */
block|}
enum|;
end_enum

begin_define
define|#
directive|define
name|NofAMmeth
value|max_amg_code
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|DOINIT
end_ifdef

begin_decl_stmt
name|EXTCONST
name|char
modifier|*
name|PL_AMG_names
index|[
name|NofAMmeth
index|]
init|=
block|{
literal|"fallback"
block|,
literal|"abs"
block|,
comment|/* "fallback" should be the first. */
literal|"bool"
block|,
literal|"nomethod"
block|,
literal|"\"\""
block|,
literal|"0+"
block|,
literal|"+"
block|,
literal|"+="
block|,
literal|"-"
block|,
literal|"-="
block|,
literal|"*"
block|,
literal|"*="
block|,
literal|"/"
block|,
literal|"/="
block|,
literal|"%"
block|,
literal|"%="
block|,
literal|"**"
block|,
literal|"**="
block|,
literal|"<<"
block|,
literal|"<<="
block|,
literal|">>"
block|,
literal|">>="
block|,
literal|"&"
block|,
literal|"&="
block|,
literal|"|"
block|,
literal|"|="
block|,
literal|"^"
block|,
literal|"^="
block|,
literal|"<"
block|,
literal|"<="
block|,
literal|">"
block|,
literal|">="
block|,
literal|"=="
block|,
literal|"!="
block|,
literal|"<=>"
block|,
literal|"cmp"
block|,
literal|"lt"
block|,
literal|"le"
block|,
literal|"gt"
block|,
literal|"ge"
block|,
literal|"eq"
block|,
literal|"ne"
block|,
literal|"!"
block|,
literal|"~"
block|,
literal|"++"
block|,
literal|"--"
block|,
literal|"atan2"
block|,
literal|"cos"
block|,
literal|"sin"
block|,
literal|"exp"
block|,
literal|"log"
block|,
literal|"sqrt"
block|,
literal|"x"
block|,
literal|"x="
block|,
literal|"."
block|,
literal|".="
block|,
literal|"="
block|,
literal|"neg"
block|,
literal|"${}"
block|,
literal|"@{}"
block|,
literal|"%{}"
block|,
literal|"*{}"
block|,
literal|"&{}"
block|,
literal|"<>"
block|, }
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_decl_stmt
name|EXTCONST
name|char
modifier|*
name|PL_AMG_names
index|[
name|NofAMmeth
index|]
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* def INITAMAGIC */
end_comment

begin_macro
name|END_EXTERN_C
end_macro

begin_struct
struct|struct
name|am_table
block|{
name|long
name|was_ok_sub
decl_stmt|;
name|long
name|was_ok_am
decl_stmt|;
name|U32
name|flags
decl_stmt|;
name|CV
modifier|*
name|table
index|[
name|NofAMmeth
index|]
decl_stmt|;
name|long
name|fallback
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|am_table_short
block|{
name|long
name|was_ok_sub
decl_stmt|;
name|long
name|was_ok_am
decl_stmt|;
name|U32
name|flags
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|am_table
name|AMT
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|am_table_short
name|AMTS
typedef|;
end_typedef

begin_define
define|#
directive|define
name|AMGfallNEVER
value|1
end_define

begin_define
define|#
directive|define
name|AMGfallNO
value|2
end_define

begin_define
define|#
directive|define
name|AMGfallYES
value|3
end_define

begin_define
define|#
directive|define
name|AMTf_AMAGIC
value|1
end_define

begin_define
define|#
directive|define
name|AMT_AMAGIC
parameter_list|(
name|amt
parameter_list|)
value|((amt)->flags& AMTf_AMAGIC)
end_define

begin_define
define|#
directive|define
name|AMT_AMAGIC_on
parameter_list|(
name|amt
parameter_list|)
value|((amt)->flags |= AMTf_AMAGIC)
end_define

begin_define
define|#
directive|define
name|AMT_AMAGIC_off
parameter_list|(
name|amt
parameter_list|)
value|((amt)->flags&= ~AMTf_AMAGIC)
end_define

begin_comment
comment|/*  * some compilers like to redefine cos et alia as faster  * (and less accurate?) versions called F_cos et cetera (Quidquid  * latine dictum sit, altum viditur.)  This trick collides with  * the Perl overloading (amg).  The following #defines fool both.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|_FASTMATH
end_ifdef

begin_ifdef
ifdef|#
directive|ifdef
name|atan2
end_ifdef

begin_define
define|#
directive|define
name|F_atan2_amg
value|atan2_amg
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|cos
end_ifdef

begin_define
define|#
directive|define
name|F_cos_amg
value|cos_amg
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|exp
end_ifdef

begin_define
define|#
directive|define
name|F_exp_amg
value|exp_amg
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|log
end_ifdef

begin_define
define|#
directive|define
name|F_log_amg
value|log_amg
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|pow
end_ifdef

begin_define
define|#
directive|define
name|F_pow_amg
value|pow_amg
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|sin
end_ifdef

begin_define
define|#
directive|define
name|F_sin_amg
value|sin_amg
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|sqrt
end_ifdef

begin_define
define|#
directive|define
name|F_sqrt_amg
value|sqrt_amg
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _FASTMATH */
end_comment

begin_define
define|#
directive|define
name|PERLDB_ALL
value|(PERLDBf_SUB	| PERLDBf_LINE	|	\ 				 PERLDBf_NOOPT	| PERLDBf_INTER	|	\ 				 PERLDBf_SUBLINE| PERLDBf_SINGLE|	\ 				 PERLDBf_NAMEEVAL| PERLDBf_NAMEANON)
end_define

begin_comment
comment|/* No _NONAME, _GOTO */
end_comment

begin_define
define|#
directive|define
name|PERLDBf_SUB
value|0x01
end_define

begin_comment
comment|/* Debug sub enter/exit */
end_comment

begin_define
define|#
directive|define
name|PERLDBf_LINE
value|0x02
end_define

begin_comment
comment|/* Keep line # */
end_comment

begin_define
define|#
directive|define
name|PERLDBf_NOOPT
value|0x04
end_define

begin_comment
comment|/* Switch off optimizations */
end_comment

begin_define
define|#
directive|define
name|PERLDBf_INTER
value|0x08
end_define

begin_comment
comment|/* Preserve more data for 					   later inspections  */
end_comment

begin_define
define|#
directive|define
name|PERLDBf_SUBLINE
value|0x10
end_define

begin_comment
comment|/* Keep subr source lines */
end_comment

begin_define
define|#
directive|define
name|PERLDBf_SINGLE
value|0x20
end_define

begin_comment
comment|/* Start with single-step on */
end_comment

begin_define
define|#
directive|define
name|PERLDBf_NONAME
value|0x40
end_define

begin_comment
comment|/* For _SUB: no name of the subr */
end_comment

begin_define
define|#
directive|define
name|PERLDBf_GOTO
value|0x80
end_define

begin_comment
comment|/* Report goto: call DB::goto */
end_comment

begin_define
define|#
directive|define
name|PERLDBf_NAMEEVAL
value|0x100
end_define

begin_comment
comment|/* Informative names for evals */
end_comment

begin_define
define|#
directive|define
name|PERLDBf_NAMEANON
value|0x200
end_define

begin_comment
comment|/* Informative names for anon subs */
end_comment

begin_define
define|#
directive|define
name|PERLDB_SUB
value|(PL_perldb&& (PL_perldb& PERLDBf_SUB))
end_define

begin_define
define|#
directive|define
name|PERLDB_LINE
value|(PL_perldb&& (PL_perldb& PERLDBf_LINE))
end_define

begin_define
define|#
directive|define
name|PERLDB_NOOPT
value|(PL_perldb&& (PL_perldb& PERLDBf_NOOPT))
end_define

begin_define
define|#
directive|define
name|PERLDB_INTER
value|(PL_perldb&& (PL_perldb& PERLDBf_INTER))
end_define

begin_define
define|#
directive|define
name|PERLDB_SUBLINE
value|(PL_perldb&& (PL_perldb& PERLDBf_SUBLINE))
end_define

begin_define
define|#
directive|define
name|PERLDB_SINGLE
value|(PL_perldb&& (PL_perldb& PERLDBf_SINGLE))
end_define

begin_define
define|#
directive|define
name|PERLDB_SUB_NN
value|(PL_perldb&& (PL_perldb& (PERLDBf_NONAME)))
end_define

begin_define
define|#
directive|define
name|PERLDB_GOTO
value|(PL_perldb&& (PL_perldb& PERLDBf_GOTO))
end_define

begin_define
define|#
directive|define
name|PERLDB_NAMEEVAL
value|(PL_perldb&& (PL_perldb& PERLDBf_NAMEEVAL))
end_define

begin_define
define|#
directive|define
name|PERLDB_NAMEANON
value|(PL_perldb&& (PL_perldb& PERLDBf_NAMEANON))
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|USE_LOCALE_NUMERIC
end_ifdef

begin_define
define|#
directive|define
name|SET_NUMERIC_STANDARD
parameter_list|()
define|\
value|set_numeric_standard();
end_define

begin_define
define|#
directive|define
name|SET_NUMERIC_LOCAL
parameter_list|()
define|\
value|set_numeric_local();
end_define

begin_define
define|#
directive|define
name|IS_NUMERIC_RADIX
parameter_list|(
name|s
parameter_list|)
define|\
value|((PL_hints& HINT_LOCALE)&& \ 	  PL_numeric_radix_sv&& memEQ(s, SvPVX(PL_numeric_radix_sv), SvCUR(PL_numeric_radix_sv)))
end_define

begin_define
define|#
directive|define
name|STORE_NUMERIC_LOCAL_SET_STANDARD
parameter_list|()
define|\
value|bool was_local = (PL_hints& HINT_LOCALE)&& PL_numeric_local; \ 	if (was_local) SET_NUMERIC_STANDARD();
end_define

begin_define
define|#
directive|define
name|STORE_NUMERIC_STANDARD_SET_LOCAL
parameter_list|()
define|\
value|bool was_standard = (PL_hints& HINT_LOCALE)&& PL_numeric_standard; \ 	if (was_standard) SET_NUMERIC_LOCAL();
end_define

begin_define
define|#
directive|define
name|RESTORE_NUMERIC_LOCAL
parameter_list|()
define|\
value|if (was_local) SET_NUMERIC_LOCAL();
end_define

begin_define
define|#
directive|define
name|RESTORE_NUMERIC_STANDARD
parameter_list|()
define|\
value|if (was_standard) SET_NUMERIC_STANDARD();
end_define

begin_define
define|#
directive|define
name|Atof
value|my_atof
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* !USE_LOCALE_NUMERIC */
end_comment

begin_define
define|#
directive|define
name|SET_NUMERIC_STANDARD
parameter_list|()
end_define

begin_comment
comment|/**/
end_comment

begin_define
define|#
directive|define
name|SET_NUMERIC_LOCAL
parameter_list|()
end_define

begin_comment
comment|/**/
end_comment

begin_define
define|#
directive|define
name|IS_NUMERIC_RADIX
parameter_list|(
name|c
parameter_list|)
value|(0)
end_define

begin_define
define|#
directive|define
name|STORE_NUMERIC_LOCAL_SET_STANDARD
parameter_list|()
end_define

begin_comment
comment|/**/
end_comment

begin_define
define|#
directive|define
name|STORE_NUMERIC_STANDARD_SET_LOCAL
parameter_list|()
end_define

begin_comment
comment|/**/
end_comment

begin_define
define|#
directive|define
name|RESTORE_NUMERIC_LOCAL
parameter_list|()
end_define

begin_comment
comment|/**/
end_comment

begin_define
define|#
directive|define
name|RESTORE_NUMERIC_STANDARD
parameter_list|()
end_define

begin_comment
comment|/**/
end_comment

begin_define
define|#
directive|define
name|Atof
value|Perl_atof
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !USE_LOCALE_NUMERIC */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|Strtol
argument_list|)
operator|&&
name|defined
argument_list|(
name|USE_64_BIT_INT
argument_list|)
operator|&&
name|defined
argument_list|(
name|IV_IS_QUAD
argument_list|)
operator|&&
name|QUADKIND
operator|==
name|QUAD_IS_LONG_LONG
end_if

begin_ifdef
ifdef|#
directive|ifdef
name|__hpux
end_ifdef

begin_define
define|#
directive|define
name|strtoll
value|__strtoll
end_define

begin_comment
comment|/* secret handshake */
end_comment

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
name|Strtol
argument_list|)
operator|&&
name|defined
argument_list|(
name|HAS_STRTOLL
argument_list|)
end_if

begin_define
define|#
directive|define
name|Strtol
value|strtoll
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* is there atoq() anywhere? */
end_comment

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
name|Strtol
argument_list|)
operator|&&
name|defined
argument_list|(
name|HAS_STRTOL
argument_list|)
end_if

begin_define
define|#
directive|define
name|Strtol
value|strtol
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|Atol
end_ifndef

begin_comment
comment|/* It would be more fashionable to use Strtol() to define atol()  * (as is done for Atoul(), see below) but for backward compatibility  * we just assume atol(). */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|USE_64_BIT_INT
argument_list|)
operator|&&
name|defined
argument_list|(
name|IV_IS_QUAD
argument_list|)
operator|&&
name|QUADKIND
operator|==
name|QUAD_IS_LONG_LONG
operator|&&
name|defined
argument_list|(
name|HAS_ATOLL
argument_list|)
end_if

begin_define
define|#
directive|define
name|Atol
value|atoll
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|Atol
value|atol
end_define

begin_endif
endif|#
directive|endif
end_endif

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
name|Strtoul
argument_list|)
operator|&&
name|defined
argument_list|(
name|USE_64_BIT_INT
argument_list|)
operator|&&
name|defined
argument_list|(
name|UV_IS_QUAD
argument_list|)
operator|&&
name|QUADKIND
operator|==
name|QUAD_IS_LONG_LONG
end_if

begin_ifdef
ifdef|#
directive|ifdef
name|__hpux
end_ifdef

begin_define
define|#
directive|define
name|strtoull
value|__strtoull
end_define

begin_comment
comment|/* secret handshake */
end_comment

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
name|Strtoul
argument_list|)
operator|&&
name|defined
argument_list|(
name|HAS_STRTOULL
argument_list|)
end_if

begin_define
define|#
directive|define
name|Strtoul
value|strtoull
end_define

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
name|Strtoul
argument_list|)
operator|&&
name|defined
argument_list|(
name|HAS_STRTOUQ
argument_list|)
end_if

begin_define
define|#
directive|define
name|Strtoul
value|strtouq
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* is there atouq() anywhere? */
end_comment

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
name|Strtoul
argument_list|)
operator|&&
name|defined
argument_list|(
name|HAS_STRTOUL
argument_list|)
end_if

begin_define
define|#
directive|define
name|Strtoul
value|strtoul
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|Atoul
end_ifndef

begin_define
define|#
directive|define
name|Atoul
parameter_list|(
name|s
parameter_list|)
value|Strtoul(s, (char **)NULL, 10)
end_define

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
name|PERLIO_IS_STDIO
argument_list|)
operator|&&
name|defined
argument_list|(
name|HASATTRIBUTE
argument_list|)
end_if

begin_comment
comment|/*   * Now we have __attribute__ out of the way   * Remap printf   */
end_comment

begin_undef
undef|#
directive|undef
name|printf
end_undef

begin_define
define|#
directive|define
name|printf
value|PerlIO_stdoutf
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* if these never got defined, they need defaults */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|PERL_SET_CONTEXT
end_ifndef

begin_define
define|#
directive|define
name|PERL_SET_CONTEXT
parameter_list|(
name|i
parameter_list|)
value|PERL_SET_INTERP(i)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|PERL_GET_CONTEXT
end_ifndef

begin_define
define|#
directive|define
name|PERL_GET_CONTEXT
value|PERL_GET_INTERP
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|PERL_GET_THX
end_ifndef

begin_define
define|#
directive|define
name|PERL_GET_THX
value|((void*)NULL)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|PERL_SET_THX
end_ifndef

begin_define
define|#
directive|define
name|PERL_SET_THX
parameter_list|(
name|t
parameter_list|)
value|NOOP
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|PERL_SCRIPT_MODE
end_ifndef

begin_define
define|#
directive|define
name|PERL_SCRIPT_MODE
value|"r"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Some operating systems are stingy with stack allocation,  * so perl may have to guard against stack overflow.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|PERL_STACK_OVERFLOW_CHECK
end_ifndef

begin_define
define|#
directive|define
name|PERL_STACK_OVERFLOW_CHECK
parameter_list|()
value|NOOP
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Some nonpreemptive operating systems find it convenient to  * check for asynchronous conditions after each op execution.  * Keep this check simple, or it may slow down execution  * massively.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|PERL_ASYNC_CHECK
end_ifndef

begin_define
define|#
directive|define
name|PERL_ASYNC_CHECK
parameter_list|()
value|NOOP
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * On some operating systems, a memory allocation may succeed,  * but put the process too close to the system's comfort limit.  * In this case, PERL_ALLOC_CHECK frees the pointer and sets  * it to NULL.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|PERL_ALLOC_CHECK
end_ifndef

begin_define
define|#
directive|define
name|PERL_ALLOC_CHECK
parameter_list|(
name|p
parameter_list|)
value|NOOP
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * nice_chunk and nice_chunk size need to be set  * and queried under the protection of sv_mutex  */
end_comment

begin_define
define|#
directive|define
name|offer_nice_chunk
parameter_list|(
name|chunk
parameter_list|,
name|chunk_size
parameter_list|)
value|do {	\ 	LOCK_SV_MUTEX;					\ 	if (!PL_nice_chunk) {				\ 	    PL_nice_chunk = (char*)(chunk);		\ 	    PL_nice_chunk_size = (chunk_size);		\ 	}						\ 	else {						\ 	    Safefree(chunk);				\ 	}						\ 	UNLOCK_SV_MUTEX;				\     } while (0)
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|HAS_SEM
end_ifdef

begin_include
include|#
directive|include
file|<sys/ipc.h>
end_include

begin_include
include|#
directive|include
file|<sys/sem.h>
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|HAS_UNION_SEMUN
end_ifndef

begin_comment
comment|/* Provide the union semun. */
end_comment

begin_union
union|union
name|semun
block|{
name|int
name|val
decl_stmt|;
name|struct
name|semid_ds
modifier|*
name|buf
decl_stmt|;
name|unsigned
name|short
modifier|*
name|array
decl_stmt|;
block|}
union|;
end_union

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|USE_SEMCTL_SEMUN
end_ifdef

begin_ifdef
ifdef|#
directive|ifdef
name|IRIX32_SEMUN_BROKEN_BY_GCC
end_ifdef

begin_union
union|union
name|gccbug_semun
block|{
name|int
name|val
decl_stmt|;
name|struct
name|semid_ds
modifier|*
name|buf
decl_stmt|;
name|unsigned
name|short
modifier|*
name|array
decl_stmt|;
name|char
name|__dummy
index|[
literal|5
index|]
decl_stmt|;
block|}
union|;
end_union

begin_define
define|#
directive|define
name|semun
value|gccbug_semun
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|Semctl
parameter_list|(
name|id
parameter_list|,
name|num
parameter_list|,
name|cmd
parameter_list|,
name|semun
parameter_list|)
value|semctl(id, num, cmd, semun)
end_define

begin_else
else|#
directive|else
end_else

begin_ifdef
ifdef|#
directive|ifdef
name|USE_SEMCTL_SEMID_DS
end_ifdef

begin_ifdef
ifdef|#
directive|ifdef
name|EXTRA_F_IN_SEMUN_BUF
end_ifdef

begin_define
define|#
directive|define
name|Semctl
parameter_list|(
name|id
parameter_list|,
name|num
parameter_list|,
name|cmd
parameter_list|,
name|semun
parameter_list|)
value|semctl(id, num, cmd, semun.buff)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|Semctl
parameter_list|(
name|id
parameter_list|,
name|num
parameter_list|,
name|cmd
parameter_list|,
name|semun
parameter_list|)
value|semctl(id, num, cmd, semun.buf)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

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

begin_ifndef
ifndef|#
directive|ifndef
name|O_RDONLY
end_ifndef

begin_comment
comment|/* Assume UNIX defaults */
end_comment

begin_define
define|#
directive|define
name|O_RDONLY
value|0000
end_define

begin_define
define|#
directive|define
name|O_WRONLY
value|0001
end_define

begin_define
define|#
directive|define
name|O_RDWR
value|0002
end_define

begin_define
define|#
directive|define
name|O_CREAT
value|0100
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|O_BINARY
end_ifndef

begin_define
define|#
directive|define
name|O_BINARY
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|O_TEXT
end_ifndef

begin_define
define|#
directive|define
name|O_TEXT
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|IAMSUID
end_ifdef

begin_ifdef
ifdef|#
directive|ifdef
name|I_SYS_STATVFS
end_ifdef

begin_include
include|#
directive|include
file|<sys/statvfs.h>
end_include

begin_comment
comment|/* for f?statvfs() */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|I_SYS_MOUNT
end_ifdef

begin_include
include|#
directive|include
file|<sys/mount.h>
end_include

begin_comment
comment|/* for *BSD f?statfs() */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|I_MNTENT
end_ifdef

begin_include
include|#
directive|include
file|<mntent.h>
end_include

begin_comment
comment|/* for getmntent() */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|I_SYS_STATFS
end_ifdef

begin_include
include|#
directive|include
file|<sys/statfs.h>
end_include

begin_comment
comment|/* for some statfs() */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|I_SYS_VFS
end_ifdef

begin_ifdef
ifdef|#
directive|ifdef
name|__sgi
end_ifdef

begin_define
define|#
directive|define
name|sv
value|IRIX_sv
end_define

begin_comment
comment|/* kludge: IRIX has an sv of its own */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<sys/vfs.h>
end_include

begin_comment
comment|/* for some statfs() */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__sgi
end_ifdef

begin_undef
undef|#
directive|undef
name|IRIX_sv
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
name|I_USTAT
end_ifdef

begin_include
include|#
directive|include
file|<ustat.h>
end_include

begin_comment
comment|/* for ustat() */
end_comment

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
name|PERL_MOUNT_NOSUID
argument_list|)
operator|&&
name|defined
argument_list|(
name|MOUNT_NOSUID
argument_list|)
end_if

begin_define
define|#
directive|define
name|PERL_MOUNT_NOSUID
value|MOUNT_NOSUID
end_define

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
name|PERL_MOUNT_NOSUID
argument_list|)
operator|&&
name|defined
argument_list|(
name|MNT_NOSUID
argument_list|)
end_if

begin_define
define|#
directive|define
name|PERL_MOUNT_NOSUID
value|MNT_NOSUID
end_define

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
name|PERL_MOUNT_NOSUID
argument_list|)
operator|&&
name|defined
argument_list|(
name|MS_NOSUID
argument_list|)
end_if

begin_define
define|#
directive|define
name|PERL_MOUNT_NOSUID
value|MS_NOSUID
end_define

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
name|PERL_MOUNT_NOSUID
argument_list|)
operator|&&
name|defined
argument_list|(
name|M_NOSUID
argument_list|)
end_if

begin_define
define|#
directive|define
name|PERL_MOUNT_NOSUID
value|M_NOSUID
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* IAMSUID */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|I_LIBUTIL
end_ifdef

begin_include
include|#
directive|include
file|<libutil.h>
end_include

begin_comment
comment|/* setproctitle() in some FreeBSDs */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|EXEC_ARGV_CAST
end_ifndef

begin_define
define|#
directive|define
name|EXEC_ARGV_CAST
parameter_list|(
name|x
parameter_list|)
value|x
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* and finally... */
end_comment

begin_define
define|#
directive|define
name|PERL_PATCHLEVEL_H_IMPLICIT
end_define

begin_include
include|#
directive|include
file|"patchlevel.h"
end_include

begin_undef
undef|#
directive|undef
name|PERL_PATCHLEVEL_H_IMPLICIT
end_undef

begin_comment
comment|/* Mention        NV_PRESERVES_UV     HAS_ICONV    I_ICONV     HAS_MKSTEMP    HAS_MKSTEMPS    HAS_MKDTEMP     HAS_GETCWD     HAS_MMAP    HAS_MPROTECT    HAS_MSYNC    HAS_MADVISE    HAS_MUNMAP    I_SYSMMAN    Mmap_t     NVef    NVff    NVgf     so that Configure picks them up. */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Include guard */
end_comment

end_unit

