begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*    perl.h  *  *    Copyright (c) 1987-1999, Larry Wall  *  *    You may distribute under the terms of either the GNU General Public  *    License or the Artistic License, as specified in the README file.  *  */
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

begin_define
define|#
directive|define
name|OVERLOAD
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
name|EMBED
end_undef

begin_undef
undef|#
directive|undef
name|NO_EMBED
end_undef

begin_define
define|#
directive|define
name|NO_EMBED
end_define

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

begin_ifdef
ifdef|#
directive|ifdef
name|PERL_OBJECT
end_ifdef

begin_comment
comment|/* PERL_OBJECT explained  - DickH and DougL @ ActiveState.com  Defining PERL_OBJECT turns on creation of a C++ object that contains all writable core perl global variables and functions. Stated another way, all necessary global variables and functions are members of a big C++ object. This object's class is CPerlObj. This allows a Perl Host to have multiple, independent perl interpreters in the same process space. This is very important on Win32 systems as the overhead of process creation is quite high -- this could be even higher than the script compile and execute time for small scripts.  The perl executable implementation on Win32 is composed of perl.exe (the Perl Host) and perlX.dll. (the Perl Core). This allows the same Perl Core to easily be embedded in other applications that use the perl interpreter.  +-----------+ | Perl Host | +-----------+       ^ 	  | 	  v +-----------+   +-----------+ | Perl Core |<->| Extension | +-----------+   +-----------+ ...  Defining PERL_OBJECT has the following effects:  PERL CORE 1. CPerlObj is defined (this is the PERL_OBJECT) 2. all static functions that needed to access either global variables or functions needed are made member functions 3. all writable static variables are made member variables 4. all global variables and functions are defined as: 	#define var CPerlObj::Perl_var 	#define func CPerlObj::Perl_func 	* these are in objpp.h This necessitated renaming some local variables and functions that had the same name as a global variable or function. This was probably a _good_ thing anyway.   EXTENSIONS 1. Access to global variables and perl functions is through a pointer to the PERL_OBJECT. This pointer type is CPerlObj*. This is made transparent to extension developers by the following macros: 	#define var pPerl->Perl_var 	#define func pPerl->Perl_func 	* these are done in objXSUB.h This requires that the extension be compiled as C++, which means that the code must be ANSI C and not K&R C. For K&R extensions, please see the C API notes located in Win32/GenCAPI.pl. This script creates a perlCAPI.lib that provides a K& R compatible C interface to the PERL_OBJECT. 2. Local variables and functions cannot have the same name as perl's variables or functions since the macros will redefine these. Look for this if you get some strange error message and it does not look like the code that you had written. This often happens with variables that are local to a function.  PERL HOST 1. The perl host is linked with perlX.lib to get perl_alloc. This function will return a pointer to CPerlObj (the PERL_OBJECT). It takes pointers to the various PerlXXX_YYY interfaces (see iperlsys.h for more information on this). 2. The perl host calls the same functions as normally would be called in setting up and running a perl script, except that the functions are now member functions of the PERL_OBJECT.  */
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
name|CPERLproto
value|CPerlObj *
end_define

begin_define
define|#
directive|define
name|_CPERLproto
value|,CPERLproto
end_define

begin_define
define|#
directive|define
name|CPERLarg
value|CPerlObj *pPerl
end_define

begin_define
define|#
directive|define
name|CPERLarg_
value|CPERLarg,
end_define

begin_define
define|#
directive|define
name|_CPERLarg
value|,CPERLarg
end_define

begin_define
define|#
directive|define
name|PERL_OBJECT_THIS
value|this
end_define

begin_define
define|#
directive|define
name|_PERL_OBJECT_THIS
value|,this
end_define

begin_define
define|#
directive|define
name|PERL_OBJECT_THIS_
value|this,
end_define

begin_define
define|#
directive|define
name|CALLRUNOPS
value|(this->*PL_runops)
end_define

begin_define
define|#
directive|define
name|CALLREGCOMP
value|(this->*PL_regcompp)
end_define

begin_define
define|#
directive|define
name|CALLREGEXEC
value|(this->*PL_regexecp)
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* !PERL_OBJECT */
end_comment

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
name|CPERLproto
end_define

begin_define
define|#
directive|define
name|_CPERLproto
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
name|CALLRUNOPS
value|PL_runops
end_define

begin_define
define|#
directive|define
name|CALLREGCOMP
value|(*PL_regcompp)
end_define

begin_define
define|#
directive|define
name|CALLREGEXEC
value|(*PL_regexecp)
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
name|VOIDUSED
value|1
end_define

begin_include
include|#
directive|include
file|"config.h"
end_include

begin_include
include|#
directive|include
file|"embed.h"
end_include

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

begin_ifdef
ifdef|#
directive|ifdef
name|EMBED
end_ifdef

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

begin_else
else|#
directive|else
end_else

begin_decl_stmt
specifier|register
name|struct
name|op
modifier|*
name|op
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
name|NOOP
value|(void)0
end_define

begin_define
define|#
directive|define
name|WITH_THR
parameter_list|(
name|s
parameter_list|)
value|STMT_START { dTHR; s; } STMT_END
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

begin_include
include|#
directive|include
file|"iperlsys.h"
end_include

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
comment|/* needed for IAMSUID case for 4.4BSD systems   * XXX there should probably be a Configure variable  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|I_SYS_PARAM
end_ifdef

begin_if
if|#
directive|if
operator|(
name|defined
argument_list|(
name|BSD
argument_list|)
operator|&&
operator|(
name|BSD
operator|>=
literal|199306
operator|)
operator|)
end_if

begin_include
include|#
directive|include
file|<sys/mount.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !BSD */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !I_SYS_PARAM */
end_comment

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

begin_define
define|#
directive|define
name|MEM_SIZE
value|Size_t
end_define

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
name|HIDEMYMALLOC
end_ifdef

begin_define
define|#
directive|define
name|malloc
value|Mymalloc
end_define

begin_define
define|#
directive|define
name|calloc
value|Mycalloc
end_define

begin_define
define|#
directive|define
name|realloc
value|Myrealloc
end_define

begin_define
define|#
directive|define
name|free
value|Myfree
end_define

begin_decl_stmt
name|Malloc_t
name|Mymalloc
name|_
argument_list|(
operator|(
name|MEM_SIZE
name|nbytes
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|Malloc_t
name|Mycalloc
name|_
argument_list|(
operator|(
name|MEM_SIZE
name|elements
operator|,
name|MEM_SIZE
name|size
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|Malloc_t
name|Myrealloc
name|_
argument_list|(
operator|(
name|Malloc_t
name|where
operator|,
name|MEM_SIZE
name|nbytes
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|Free_t
name|Myfree
name|_
argument_list|(
operator|(
name|Malloc_t
name|where
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
name|EMBEDMYMALLOC
end_ifdef

begin_define
define|#
directive|define
name|malloc
value|Perl_malloc
end_define

begin_define
define|#
directive|define
name|calloc
value|Perl_calloc
end_define

begin_define
define|#
directive|define
name|realloc
value|Perl_realloc
end_define

begin_comment
comment|/* VMS' external symbols are case-insensitive, and there's already a */
end_comment

begin_comment
comment|/* perl_free in perl.h */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|VMS
end_ifdef

begin_define
define|#
directive|define
name|free
value|Perl_myfree
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|free
value|Perl_free
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
name|Malloc_t
name|Perl_malloc
name|_
argument_list|(
operator|(
name|MEM_SIZE
name|nbytes
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|Malloc_t
name|Perl_calloc
name|_
argument_list|(
operator|(
name|MEM_SIZE
name|elements
operator|,
name|MEM_SIZE
name|size
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|Malloc_t
name|Perl_realloc
name|_
argument_list|(
operator|(
name|Malloc_t
name|where
operator|,
name|MEM_SIZE
name|nbytes
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|VMS
end_ifdef

begin_decl_stmt
name|Free_t
name|Perl_myfree
name|_
argument_list|(
operator|(
name|Malloc_t
name|where
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_decl_stmt
name|Free_t
name|Perl_free
name|_
argument_list|(
operator|(
name|Malloc_t
name|where
operator|)
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

begin_undef
undef|#
directive|undef
name|safemalloc
end_undef

begin_undef
undef|#
directive|undef
name|safecalloc
end_undef

begin_undef
undef|#
directive|undef
name|saferealloc
end_undef

begin_undef
undef|#
directive|undef
name|safefree
end_undef

begin_define
define|#
directive|define
name|safemalloc
value|malloc
end_define

begin_define
define|#
directive|define
name|safecalloc
value|calloc
end_define

begin_define
define|#
directive|define
name|saferealloc
value|realloc
end_define

begin_define
define|#
directive|define
name|safefree
value|free
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

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|memcpy
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

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|memset
name|_
argument_list|(
operator|(
name|char
operator|*
operator|,
name|int
operator|,
name|int
operator|)
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

begin_decl_stmt
specifier|extern
name|int
name|memcmp
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

begin_ifdef
ifdef|#
directive|ifdef
name|HAS_SOCKET
end_ifdef

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
name|ERRHV
value|(thr->errhv)
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
name|ERRHV
value|GvHV(PL_errgv)
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
comment|/* ANSI allows errno to be an lvalue expr */
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

begin_decl_stmt
name|char
modifier|*
name|strerror
name|_
argument_list|(
operator|(
name|int
operator|,
operator|...
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_ifndef
ifndef|#
directive|ifndef
name|DONT_DECLARE_STD
end_ifndef

begin_decl_stmt
name|char
modifier|*
name|strerror
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

begin_if
if|#
directive|if
name|defined
argument_list|(
name|NeXT
argument_list|)
operator|&&
name|defined
argument_list|(
name|I_SYS_DIR
argument_list|)
end_if

begin_comment
comment|/* NeXT needs dirent + sys/dir.h */
end_comment

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
comment|/*  XXX QUAD stuff is not currently supported on most systems.     Specifically, perl internals don't support long long.  Among     the many problems is that some compilers support long long,     but the underlying library functions (such as sprintf) don't.     Some things do work (such as quad pack/unpack on convex);     also some systems use long long for the fpos_t typedef.  That     seems to work too.      The IV type is supposed to be long enough to hold any integral     value or a pointer.     --Andy Dougherty	August 1996 */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|cray
end_ifdef

begin_define
define|#
directive|define
name|Quad_t
value|int
end_define

begin_else
else|#
directive|else
end_else

begin_ifdef
ifdef|#
directive|ifdef
name|convex
end_ifdef

begin_define
define|#
directive|define
name|Quad_t
value|long long
end_define

begin_else
else|#
directive|else
end_else

begin_if
if|#
directive|if
name|LONGSIZE
operator|==
literal|8
end_if

begin_define
define|#
directive|define
name|Quad_t
value|long
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
comment|/* XXX Experimental set-up for long long.  Just add -DUSE_LONG_LONG    to your ccflags.  --Andy Dougherty   4/1998 */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|USE_LONG_LONG
end_ifdef

begin_if
if|#
directive|if
name|defined
argument_list|(
name|HAS_LONG_LONG
argument_list|)
operator|&&
name|LONGLONGSIZE
operator|==
literal|8
end_if

begin_define
define|#
directive|define
name|Quad_t
value|long long
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
name|Quad_t
end_ifdef

begin_define
define|#
directive|define
name|HAS_QUAD
end_define

begin_typedef
typedef|typedef
name|Quad_t
name|IV
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|Quad_t
name|UV
typedef|;
end_typedef

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

begin_else
else|#
directive|else
end_else

begin_typedef
typedef|typedef
name|long
name|IV
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|long
name|UV
typedef|;
end_typedef

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
name|HAS_QUAD
end_ifdef

begin_ifdef
ifdef|#
directive|ifdef
name|UQUAD_MAX
end_ifdef

begin_define
define|#
directive|define
name|PERL_UQUAD_MAX
value|((UV)UQUAD_MAX)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|PERL_UQUAD_MAX
value|(~(UV)0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|PERL_UQUAD_MIN
value|((UV)0)
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|QUAD_MAX
end_ifdef

begin_define
define|#
directive|define
name|PERL_QUAD_MAX
value|((IV)QUAD_MAX)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|PERL_QUAD_MAX
value|((IV) (PERL_UQUAD_MAX>> 1))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|QUAD_MIN
end_ifdef

begin_define
define|#
directive|define
name|PERL_QUAD_MIN
value|((IV)QUAD_MIN)
end_define

begin_else
else|#
directive|else
end_else

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

begin_endif
endif|#
directive|endif
end_endif

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
name|condop
name|CONDOP
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
name|gvop
name|GVOP
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
name|Outrec
name|Outrec
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|interpreter
name|PerlInterpreter
typedef|;
end_typedef

begin_ifndef
ifndef|#
directive|ifndef
name|__BORLANDC__
end_ifndef

begin_typedef
typedef|typedef
name|struct
name|ff
name|FF
typedef|;
end_typedef

begin_comment
comment|/* XXX not defined anywhere, should go? */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
name|struct
name|sv
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

begin_include
include|#
directive|include
file|"handy.h"
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|PERL_OBJECT
end_ifdef

begin_typedef
typedef|typedef
name|I32
argument_list|(
argument|*filter_t
argument_list|)
name|_
argument_list|(
operator|(
name|CPerlObj
operator|*
operator|,
name|int
operator|,
name|SV
operator|*
operator|,
name|int
operator|)
argument_list|)
expr_stmt|;
end_typedef

begin_else
else|#
directive|else
end_else

begin_typedef
typedef|typedef
name|I32
argument_list|(
argument|*filter_t
argument_list|)
name|_
argument_list|(
operator|(
name|int
operator|,
name|SV
operator|*
operator|,
name|int
operator|)
argument_list|)
expr_stmt|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

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

begin_ifndef
ifndef|#
directive|ifndef
name|FUNC_NAME_TO_PTR
end_ifndef

begin_define
define|#
directive|define
name|FUNC_NAME_TO_PTR
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
comment|/*   * USE_THREADS needs to be after unixish.h as<pthread.h> includes  *<sys/signal.h> which defines NSIG - which will stop inclusion of<signal.h>  * this results in many functions being undeclared which bothers C++  * May make sense to have threads after "*ish.h" anyway  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|USE_THREADS
end_ifdef

begin_comment
comment|/* pending resolution of licensing issues, we avoid the erstwhile     * atomic.h everywhere */
end_comment

begin_define
define|#
directive|define
name|EMULATE_ATOMIC_REFCOUNTS
end_define

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

begin_ifdef
ifdef|#
directive|ifdef
name|NeXT
end_ifdef

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

begin_include
include|#
directive|include
file|<pthread.h>
end_include

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
comment|/* USE_THREADS */
end_comment

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
value|((I32)PL_statusvalue_vms == -1 ? 44 : PL_statusvalue_vms)
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
comment|/* Some unistd.h's give a prototype for pause() even though    HAS_PAUSE ends up undefined.  This causes the #define    below to be rejected by the compmiler.  Sigh. */
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
argument_list|(
argument|CPERLscope(*any_dptr)
argument_list|)
name|_
argument_list|(
operator|(
name|void
operator|*
operator|)
argument_list|)
expr_stmt|;
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
value|void
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* USE_THREADS */
end_comment

begin_comment
comment|/* Work around some cygwin32 problems with importing global symbols */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|CYGWIN32
argument_list|)
operator|&&
name|defined
argument_list|(
name|DLLIMPORT
argument_list|)
end_if

begin_include
include|#
directive|include
file|"cw32imp.h"
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
file|"opcode.h"
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
file|"bytecode.h"
end_include

begin_include
include|#
directive|include
file|"byterun.h"
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
block|}
struct|;
end_struct

begin_ifdef
ifdef|#
directive|ifdef
name|PERL_OBJECT
end_ifdef

begin_struct
struct|struct
name|magic_state
block|{
name|SV
modifier|*
name|mgs_sv
decl_stmt|;
name|U32
name|mgs_flags
decl_stmt|;
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

begin_typedef
typedef|typedef
struct|struct
block|{
name|I32
name|len_min
decl_stmt|;
name|I32
name|len_delta
decl_stmt|;
name|I32
name|pos_min
decl_stmt|;
name|I32
name|pos_delta
decl_stmt|;
name|SV
modifier|*
name|last_found
decl_stmt|;
name|I32
name|last_end
decl_stmt|;
comment|/* min value,<0 unless valid. */
name|I32
name|last_start_min
decl_stmt|;
name|I32
name|last_start_max
decl_stmt|;
name|SV
modifier|*
modifier|*
name|longest
decl_stmt|;
comment|/* Either&l_fixed, or&l_float. */
name|SV
modifier|*
name|longest_fixed
decl_stmt|;
name|I32
name|offset_fixed
decl_stmt|;
name|SV
modifier|*
name|longest_float
decl_stmt|;
name|I32
name|offset_float_min
decl_stmt|;
name|I32
name|offset_float_max
decl_stmt|;
name|I32
name|flags
decl_stmt|;
block|}
name|scan_data_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|I32
name|CHECKPOINT
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* PERL_OBJECT */
end_comment

begin_comment
comment|/* work around some libPW problems */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|DOINIT
end_ifdef

begin_decl_stmt
name|EXT
name|char
name|Error
index|[
literal|1
index|]
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

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

begin_decl_stmt
name|EXTERN_C
name|U32
name|cast_ulong
name|_
argument_list|(
operator|(
name|double
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|U_S
parameter_list|(
name|what
parameter_list|)
value|((U16)cast_ulong((double)(what)))
end_define

begin_define
define|#
directive|define
name|U_I
parameter_list|(
name|what
parameter_list|)
value|((unsigned int)cast_ulong((double)(what)))
end_define

begin_define
define|#
directive|define
name|U_L
parameter_list|(
name|what
parameter_list|)
value|(cast_ulong((double)(what)))
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

begin_decl_stmt
name|START_EXTERN_C
name|I32
name|cast_i32
name|_
argument_list|(
operator|(
name|double
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|IV
name|cast_iv
name|_
argument_list|(
operator|(
name|double
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|UV
name|cast_uv
name|_
argument_list|(
operator|(
name|double
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_macro
name|END_EXTERN_C
end_macro

begin_define
define|#
directive|define
name|I_32
parameter_list|(
name|what
parameter_list|)
value|(cast_i32((double)(what)))
end_define

begin_define
define|#
directive|define
name|I_V
parameter_list|(
name|what
parameter_list|)
value|(cast_iv((double)(what)))
end_define

begin_define
define|#
directive|define
name|U_V
parameter_list|(
name|what
parameter_list|)
value|(cast_uv((double)(what)))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_struct
struct|struct
name|Outrec
block|{
name|I32
name|o_lines
decl_stmt|;
name|char
modifier|*
name|o_str
decl_stmt|;
name|U32
name|o_len
decl_stmt|;
block|}
struct|;
end_struct

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
name|TMPPATH
end_ifndef

begin_define
define|#
directive|define
name|TMPPATH
value|"/tmp/perl-eXXXXXX"
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

begin_decl_stmt
name|Uid_t
name|getuid
name|_
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|Uid_t
name|geteuid
name|_
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|Gid_t
name|getgid
name|_
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|Gid_t
name|getegid
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

begin_ifdef
ifdef|#
directive|ifdef
name|DEBUGGING
end_ifdef

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

begin_define
define|#
directive|define
name|DEBUG_m
parameter_list|(
name|a
parameter_list|)
value|if (PL_curinterp&& PL_debug& 128)	a
end_define

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
value|DEB( {						\ 	if (!(what)) {							\ 	    croak("Assertion failed: file \"%s\", line %d",		\ 		__FILE__, __LINE__);					\ 	    PerlProc_exit(1);							\ 	}})
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
argument_list|(
argument|*uf_val
argument_list|)
name|_
argument_list|(
operator|(
name|IV
operator|,
name|SV
operator|*
operator|)
argument_list|)
expr_stmt|;
name|I32
argument_list|(
argument|*uf_set
argument_list|)
name|_
argument_list|(
operator|(
name|IV
operator|,
name|SV
operator|*
operator|)
argument_list|)
expr_stmt|;
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

begin_decl_stmt
name|char
modifier|*
name|mktemp
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
name|double
name|atof
name|_
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

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

begin_ifdef
ifdef|#
directive|ifdef
name|OEMVS
end_ifdef

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

begin_decl_stmt
name|START_EXTERN_C
name|double
name|exp
name|_
argument_list|(
operator|(
name|double
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|double
name|log
name|_
argument_list|(
operator|(
name|double
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|double
name|log10
name|_
argument_list|(
operator|(
name|double
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|double
name|sqrt
name|_
argument_list|(
operator|(
name|double
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|double
name|frexp
name|_
argument_list|(
operator|(
name|double
operator|,
name|int
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|double
name|ldexp
name|_
argument_list|(
operator|(
name|double
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|double
name|modf
name|_
argument_list|(
operator|(
name|double
operator|,
name|double
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|double
name|sin
name|_
argument_list|(
operator|(
name|double
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|double
name|cos
name|_
argument_list|(
operator|(
name|double
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|double
name|atan2
name|_
argument_list|(
operator|(
name|double
operator|,
name|double
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|double
name|pow
name|_
argument_list|(
operator|(
name|double
operator|,
name|double
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_function_decl
name|END_EXTERN_C
endif|#
directive|endif
ifndef|#
directive|ifndef
name|__cplusplus
ifdef|#
directive|ifdef
name|__NeXT__
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
operator|||
operator|!
name|defined
argument_list|(
name|HAVE_DES_FCRYPT
argument_list|)
end_if

begin_decl_stmt
name|char
modifier|*
name|crypt
name|_
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|,
specifier|const
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !WIN32&& !HAVE_CRYPT_SOURCE */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !__NeXT__ */
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

begin_decl_stmt
name|char
modifier|*
name|getenv
name|_
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !getenv */
end_comment

begin_decl_stmt
name|Off_t
name|lseek
name|_
argument_list|(
operator|(
name|int
operator|,
name|Off_t
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !DONT_DECLARE_STD */
end_comment

begin_decl_stmt
name|char
modifier|*
name|getlogin
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

begin_decl_stmt
name|I32
name|unlnk
name|_
argument_list|(
operator|(
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

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

begin_typedef
typedef|typedef
name|Signal_t
argument_list|(
argument|*Sighandler_t
argument_list|)
name|_
argument_list|(
operator|(
name|int
operator|)
argument_list|)
expr_stmt|;
end_typedef

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
value|runops_debug
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
value|runops_standard
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

begin_comment
comment|/*  * These need prototyping here because<proto.h> isn't  * included until after runops is initialised.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|PERL_OBJECT
end_ifndef

begin_typedef
typedef|typedef
name|int
name|runops_proc_t
name|_
typedef|((
name|void
typedef|));
end_typedef

begin_decl_stmt
name|int
name|runops_standard
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
name|DEBUGGING
end_ifdef

begin_decl_stmt
name|int
name|runops_debug
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

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* PERL_OBJECT */
end_comment

begin_comment
comment|/* _ (for $_) must be first in the following list (DEFSV requires it) */
end_comment

begin_define
define|#
directive|define
name|THREADSV_NAMES
value|"_123456789&`'+/.,\\\";^-%=|~:\001\005!@"
end_define

begin_comment
comment|/* VMS doesn't use environ array and NeXT has problems with crt0.o globals */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|VMS
argument_list|)
operator|&&
operator|!
operator|(
name|defined
argument_list|(
name|NeXT
argument_list|)
operator|&&
name|defined
argument_list|(
name|__DYNAMIC__
argument_list|)
operator|)
end_if

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|DONT_DECLARE_STD
argument_list|)
expr|\
operator|||
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
expr|\
operator|||
name|defined
argument_list|(
name|__sgi
argument_list|)
operator|||
name|defined
argument_list|(
name|__DGUX
argument_list|)
end_if

begin_decl_stmt
specifier|extern
name|char
modifier|*
modifier|*
name|environ
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* environment variables supplied via exec */
end_comment

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
name|NeXT
argument_list|)
operator|&&
name|defined
argument_list|(
name|__DYNAMIC__
argument_list|)
end_if

begin_include
include|#
directive|include
file|<mach-o/dyld.h>
end_include

begin_decl_stmt
name|EXT
name|char
modifier|*
modifier|*
modifier|*
name|environ_pointer
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|environ
value|(*environ_pointer)
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
comment|/* environ processing */
end_comment

begin_comment
comment|/* for tmp use in stupid debuggers */
end_comment

begin_decl_stmt
name|EXT
name|int
modifier|*
name|di
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|EXT
name|short
modifier|*
name|ds
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|EXT
name|char
modifier|*
name|dc
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* handy constants */
end_comment

begin_decl_stmt
name|EXTCONST
name|char
name|warn_uninit
index|[]
name|INIT
argument_list|(
literal|"Use of uninitialized value"
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|EXTCONST
name|char
name|warn_nosemi
index|[]
name|INIT
argument_list|(
literal|"Semicolon seems to be missing"
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|EXTCONST
name|char
name|warn_reserved
index|[]
name|INIT
argument_list|(
literal|"Unquoted string \"%s\" may clash with future reserved word"
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|EXTCONST
name|char
name|warn_nl
index|[]
name|INIT
argument_list|(
literal|"Unsuccessful %s on filename containing newline"
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|EXTCONST
name|char
name|no_wrongref
index|[]
name|INIT
argument_list|(
literal|"Can't use %s ref as %s ref"
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|EXTCONST
name|char
name|no_symref
index|[]
name|INIT
argument_list|(
literal|"Can't use string (\"%.32s\") as %s ref while \"strict refs\" in use"
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|EXTCONST
name|char
name|no_usym
index|[]
name|INIT
argument_list|(
literal|"Can't use an undefined value as %s reference"
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|EXTCONST
name|char
name|no_aelem
index|[]
name|INIT
argument_list|(
literal|"Modification of non-creatable array value attempted, subscript %d"
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|EXTCONST
name|char
name|no_helem
index|[]
name|INIT
argument_list|(
literal|"Modification of non-creatable hash value attempted, subscript \"%s\""
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|EXTCONST
name|char
name|no_modify
index|[]
name|INIT
argument_list|(
literal|"Modification of a read-only value attempted"
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|EXTCONST
name|char
name|no_mem
index|[]
name|INIT
argument_list|(
literal|"Out of memory!\n"
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|EXTCONST
name|char
name|no_security
index|[]
name|INIT
argument_list|(
literal|"Insecure dependency in %s%s"
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|EXTCONST
name|char
name|no_sock_func
index|[]
name|INIT
argument_list|(
literal|"Unsupported socket function \"%s\" called"
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|EXTCONST
name|char
name|no_dir_func
index|[]
name|INIT
argument_list|(
literal|"Unsupported directory function \"%s\" called"
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|EXTCONST
name|char
name|no_func
index|[]
name|INIT
argument_list|(
literal|"The %s function is unimplemented"
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|EXTCONST
name|char
name|no_myglob
index|[]
name|INIT
argument_list|(
literal|"\"my\" variable %s can't be in a package"
argument_list|)
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|DOINIT
end_ifdef

begin_decl_stmt
name|EXT
name|char
modifier|*
name|sig_name
index|[]
init|=
block|{
name|SIG_NAME
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|EXT
name|int
name|sig_num
index|[]
init|=
block|{
name|SIG_NUM
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|EXT
name|SV
modifier|*
name|psig_ptr
index|[
sizeof|sizeof
argument_list|(
name|sig_num
argument_list|)
operator|/
sizeof|sizeof
argument_list|(
operator|*
name|sig_num
argument_list|)
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|EXT
name|SV
modifier|*
name|psig_name
index|[
sizeof|sizeof
argument_list|(
name|sig_num
argument_list|)
operator|/
sizeof|sizeof
argument_list|(
operator|*
name|sig_num
argument_list|)
index|]
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_decl_stmt
name|EXT
name|char
modifier|*
name|sig_name
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|EXT
name|int
name|sig_num
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|EXT
name|SV
modifier|*
name|psig_ptr
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|EXT
name|SV
modifier|*
name|psig_name
index|[]
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* fast case folding tables */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|DOINIT
end_ifdef

begin_ifdef
ifdef|#
directive|ifdef
name|EBCDIC
end_ifdef

begin_decl_stmt
name|EXT
name|unsigned
name|char
name|fold
index|[]
init|=
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
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* ascii rather than ebcdic */
end_comment

begin_decl_stmt
name|EXTCONST
name|unsigned
name|char
name|fold
index|[]
init|=
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
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !EBCDIC */
end_comment

begin_else
else|#
directive|else
end_else

begin_decl_stmt
name|EXTCONST
name|unsigned
name|char
name|fold
index|[]
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|DOINIT
end_ifdef

begin_decl_stmt
name|EXT
name|unsigned
name|char
name|fold_locale
index|[]
init|=
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
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_decl_stmt
name|EXT
name|unsigned
name|char
name|fold_locale
index|[]
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|DOINIT
end_ifdef

begin_ifdef
ifdef|#
directive|ifdef
name|EBCDIC
end_ifdef

begin_decl_stmt
name|EXT
name|unsigned
name|char
name|freq
index|[]
init|=
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
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* ascii rather than ebcdic */
end_comment

begin_decl_stmt
name|EXTCONST
name|unsigned
name|char
name|freq
index|[]
init|=
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
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_else
else|#
directive|else
end_else

begin_decl_stmt
name|EXTCONST
name|unsigned
name|char
name|freq
index|[]
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|DEBUGGING
end_ifdef

begin_ifdef
ifdef|#
directive|ifdef
name|DOINIT
end_ifdef

begin_decl_stmt
name|EXTCONST
name|char
modifier|*
name|block_type
index|[]
init|=
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
name|block_type
index|[]
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
comment|/*****************************************************************************/
end_comment

begin_comment
comment|/* This lexer/parser stuff is currently global since yacc is hard to reenter */
end_comment

begin_comment
comment|/*****************************************************************************/
end_comment

begin_comment
comment|/* XXX This needs to be revisited, since BEGIN makes yacc re-enter... */
end_comment

begin_include
include|#
directive|include
file|"perly.h"
end_include

begin_define
define|#
directive|define
name|LEX_NOTPARSING
value|11
end_define

begin_comment
comment|/* borrowed from toke.c */
end_comment

begin_typedef
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
ifdef|#
directive|ifdef
name|USE_THREADS
block|,
name|want_vtbl_mutex
endif|#
directive|endif
block|}
enum|;
end_enum

begin_comment
comment|/* Note: the lowest 8 bits are reserved for 				   stuffing into op->op_private */
end_comment

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
value|(SvOK(sv)&& SvCUR(sv))
end_define

begin_define
define|#
directive|define
name|RsPARA
parameter_list|(
name|sv
parameter_list|)
value|(SvOK(sv)&& ! SvCUR(sv))
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

begin_ifdef
ifdef|#
directive|ifdef
name|PERL_OBJECT
end_ifdef

begin_typedef
typedef|typedef
name|regexp
operator|*
operator|(
name|CPerlObj
operator|::
operator|*
name|regcomp_t
operator|)
name|_
argument_list|(
operator|(
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
argument_list|)
expr_stmt|;
end_typedef

begin_typedef
typedef|typedef
name|I32
argument_list|(
argument|CPerlObj::*regexec_t
argument_list|)
name|_
argument_list|(
operator|(
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
argument_list|)
expr_stmt|;
end_typedef

begin_else
else|#
directive|else
end_else

begin_typedef
typedef|typedef
name|regexp
operator|*
operator|(
operator|*
name|regcomp_t
operator|)
name|_
argument_list|(
operator|(
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
argument_list|)
expr_stmt|;
end_typedef

begin_typedef
typedef|typedef
name|I32
argument_list|(
argument|*regexec_t
argument_list|)
name|_
argument_list|(
operator|(
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
argument_list|)
expr_stmt|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

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
ifdef|#
directive|ifdef
name|PERL_OBJECT
name|void
argument_list|(
argument|*fn
argument_list|)
name|_
argument_list|(
operator|(
name|CPerlObj
operator|*
operator|,
name|void
operator|*
operator|)
argument_list|)
expr_stmt|;
else|#
directive|else
name|void
argument_list|(
argument|*fn
argument_list|)
name|_
argument_list|(
operator|(
name|void
operator|*
operator|)
argument_list|)
expr_stmt|;
endif|#
directive|endif
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
name|PERL_OBJECT
end_ifdef

begin_extern
extern|extern
literal|"C"
name|CPerlObj
modifier|*
name|perl_alloc
name|_
argument_list|(
operator|(
name|IPerlMem
operator|*
operator|,
name|IPerlEnv
operator|*
operator|,
name|IPerlStdIO
operator|*
operator|,
name|IPerlLIO
operator|*
operator|,
name|IPerlDir
operator|*
operator|,
name|IPerlSock
operator|*
operator|,
name|IPerlProc
operator|*
operator|)
argument_list|)
decl_stmt|;
end_extern

begin_typedef
typedef|typedef
name|int
argument_list|(
argument|CPerlObj::*runops_proc_t
argument_list|)
name|_
argument_list|(
operator|(
name|void
operator|)
argument_list|)
expr_stmt|;
end_typedef

begin_undef
undef|#
directive|undef
name|EXT
end_undef

begin_define
define|#
directive|define
name|EXT
end_define

begin_undef
undef|#
directive|undef
name|EXTCONST
end_undef

begin_define
define|#
directive|define
name|EXTCONST
end_define

begin_undef
undef|#
directive|undef
name|INIT
end_undef

begin_define
define|#
directive|define
name|INIT
parameter_list|(
name|x
parameter_list|)
end_define

begin_decl_stmt
name|class
name|CPerlObj
block|{
name|public
label|:
name|CPerlObj
argument_list|(
name|IPerlMem
operator|*
argument_list|,
name|IPerlEnv
operator|*
argument_list|,
name|IPerlStdIO
operator|*
argument_list|,
name|IPerlLIO
operator|*
argument_list|,
name|IPerlDir
operator|*
argument_list|,
name|IPerlSock
operator|*
argument_list|,
name|IPerlProc
operator|*
argument_list|)
expr_stmt|;
name|void
name|Init
parameter_list|(
name|void
parameter_list|)
function_decl|;
name|void
modifier|*
name|operator
name|new
parameter_list|(
name|size_t
name|nSize
parameter_list|,
name|IPerlMem
modifier|*
name|pvtbl
parameter_list|)
function_decl|;
endif|#
directive|endif
comment|/* PERL_OBJECT */
ifdef|#
directive|ifdef
name|PERL_GLOBAL_STRUCT
struct|struct
name|perl_vars
block|{
include|#
directive|include
file|"perlvars.h"
block|}
struct|;
ifdef|#
directive|ifdef
name|PERL_CORE
name|EXT
name|struct
name|perl_vars
name|PL_Vars
decl_stmt|;
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
else|#
directive|else
comment|/* PERL_CORE */
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
name|EXT
endif|#
directive|endif
comment|/* WIN32 */
name|struct
name|perl_vars
modifier|*
name|PL_VarsPtr
decl_stmt|;
define|#
directive|define
name|PL_Vars
value|(*((PL_VarsPtr) ? PL_VarsPtr : (PL_VarsPtr =  Perl_GetVars())))
endif|#
directive|endif
comment|/* PERL_CORE */
endif|#
directive|endif
comment|/* PERL_GLOBAL_STRUCT */
ifdef|#
directive|ifdef
name|MULTIPLICITY
comment|/* If we have multiple interpreters define a struct     holding variables which must be per-interpreter    If we don't have threads anything that would have     be per-thread is per-interpreter. */
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
block|}
struct|;
else|#
directive|else
struct|struct
name|interpreter
block|{
name|char
name|broiled
decl_stmt|;
block|}
struct|;
endif|#
directive|endif
ifdef|#
directive|ifdef
name|USE_THREADS
comment|/* If we have threads define a struct with all the variables  * that have to be per-thread  */
struct|struct
name|perl_thread
block|{
include|#
directive|include
file|"thrdvar.h"
block|}
struct|;
typedef|typedef
name|struct
name|perl_thread
modifier|*
name|Thread
typedef|;
else|#
directive|else
typedef|typedef
name|void
modifier|*
name|Thread
typedef|;
endif|#
directive|endif
comment|/* Done with PERLVAR macros for now ... */
undef|#
directive|undef
name|PERLVAR
undef|#
directive|undef
name|PERLVARI
undef|#
directive|undef
name|PERLVARIC
include|#
directive|include
file|"thread.h"
include|#
directive|include
file|"pp.h"
include|#
directive|include
file|"proto.h"
ifdef|#
directive|ifdef
name|EMBED
define|#
directive|define
name|Perl_sv_setptrobj
parameter_list|(
name|rv
parameter_list|,
name|ptr
parameter_list|,
name|name
parameter_list|)
value|Perl_sv_setref_iv(rv,name,(IV)ptr)
define|#
directive|define
name|Perl_sv_setptrref
parameter_list|(
name|rv
parameter_list|,
name|ptr
parameter_list|)
value|Perl_sv_setref_iv(rv,Nullch,(IV)ptr)
else|#
directive|else
define|#
directive|define
name|sv_setptrobj
parameter_list|(
name|rv
parameter_list|,
name|ptr
parameter_list|,
name|name
parameter_list|)
value|sv_setref_iv(rv,name,(IV)ptr)
define|#
directive|define
name|sv_setptrref
parameter_list|(
name|rv
parameter_list|,
name|ptr
parameter_list|)
value|sv_setref_iv(rv,Nullch,(IV)ptr)
endif|#
directive|endif
comment|/* The following must follow proto.h as #defines mess up syntax */
include|#
directive|include
file|"embedvar.h"
comment|/* Now include all the 'global' variables   * If we don't have threads or multiple interpreters  * these include variables that would have been their struct-s   */
define|#
directive|define
name|PERLVAR
parameter_list|(
name|var
parameter_list|,
name|type
parameter_list|)
value|EXT type PL_##var;
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
ifndef|#
directive|ifndef
name|PERL_GLOBAL_STRUCT
include|#
directive|include
file|"perlvars.h"
endif|#
directive|endif
ifndef|#
directive|ifndef
name|MULTIPLICITY
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
endif|#
directive|endif
ifdef|#
directive|ifdef
name|PERL_OBJECT
comment|/* from perly.c */
undef|#
directive|undef
name|yydebug
undef|#
directive|undef
name|yynerrs
undef|#
directive|undef
name|yyerrflag
undef|#
directive|undef
name|yychar
undef|#
directive|undef
name|yyssp
undef|#
directive|undef
name|yyvsp
undef|#
directive|undef
name|yyval
undef|#
directive|undef
name|yylval
define|#
directive|define
name|yydebug
value|PL_yydebug
define|#
directive|define
name|yynerrs
value|PL_yynerrs
define|#
directive|define
name|yyerrflag
value|PL_yyerrflag
define|#
directive|define
name|yychar
value|PL_yychar
define|#
directive|define
name|yyssp
value|PL_yyssp
define|#
directive|define
name|yyvsp
value|PL_yyvsp
define|#
directive|define
name|yyval
value|PL_yyval
define|#
directive|define
name|yylval
value|PL_yylval
name|PERLVAR
argument_list|(
argument|yydebug
argument_list|,
argument|int
argument_list|)
name|PERLVAR
argument_list|(
argument|yynerrs
argument_list|,
argument|int
argument_list|)
name|PERLVAR
argument_list|(
argument|yyerrflag
argument_list|,
argument|int
argument_list|)
name|PERLVAR
argument_list|(
argument|yychar
argument_list|,
argument|int
argument_list|)
name|PERLVAR
argument_list|(
argument|yyssp
argument_list|,
argument|short*
argument_list|)
name|PERLVAR
argument_list|(
argument|yyvsp
argument_list|,
argument|YYSTYPE*
argument_list|)
name|PERLVAR
argument_list|(
argument|yyval
argument_list|,
argument|YYSTYPE
argument_list|)
name|PERLVAR
argument_list|(
argument|yylval
argument_list|,
argument|YYSTYPE
argument_list|)
define|#
directive|define
name|efloatbuf
value|PL_efloatbuf
define|#
directive|define
name|efloatsize
value|PL_efloatsize
name|PERLVAR
argument_list|(
argument|efloatbuf
argument_list|,
argument|char *
argument_list|)
name|PERLVAR
argument_list|(
argument|efloatsize
argument_list|,
argument|STRLEN
argument_list|)
define|#
directive|define
name|glob_index
value|PL_glob_index
define|#
directive|define
name|srand_called
value|PL_srand_called
define|#
directive|define
name|uudmap
value|PL_uudmap
define|#
directive|define
name|bitcount
value|PL_bitcount
define|#
directive|define
name|filter_debug
value|PL_filter_debug
name|PERLVAR
argument_list|(
argument|glob_index
argument_list|,
argument|int
argument_list|)
name|PERLVAR
argument_list|(
argument|srand_called
argument_list|,
argument|bool
argument_list|)
name|PERLVAR
argument_list|(
argument|uudmap[
literal|256
argument|]
argument_list|,
argument|char
argument_list|)
name|PERLVAR
argument_list|(
argument|bitcount
argument_list|,
argument|char*
argument_list|)
name|PERLVAR
argument_list|(
argument|filter_debug
argument_list|,
argument|int
argument_list|)
name|PERLVAR
argument_list|(
argument|super_bufptr
argument_list|,
argument|char*
argument_list|)
comment|/* PL_bufptr that was */
name|PERLVAR
argument_list|(
argument|super_bufend
argument_list|,
argument|char*
argument_list|)
comment|/* PL_bufend that was */
comment|/*  * The following is a buffer where new variables must  * be defined to maintain binary compatibility with PERL_OBJECT  * for 5.005  */
name|PERLVAR
argument_list|(
argument|object_compatibility[
literal|30
argument|]
argument_list|,
argument|char
argument_list|)
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_include
include|#
directive|include
file|"objpp.h"
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|DOINIT
end_ifdef

begin_include
include|#
directive|include
file|"INTERN.h"
end_include

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|"EXTERN.h"
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
comment|/* PERL_OBJECT */
end_comment

begin_undef
undef|#
directive|undef
name|PERLVAR
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

begin_if
if|#
directive|if
name|defined
argument_list|(
name|HASATTRIBUTE
argument_list|)
operator|&&
name|defined
argument_list|(
name|WIN32
argument_list|)
end_if

begin_comment
comment|/*  * This provides a layer of functions and macros to ensure extensions will  * get to use the same RTL functions as the core.  * It has to go here or #define of printf messes up __attribute__  * stuff in proto.h    */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|PERL_OBJECT
end_ifndef

begin_include
include|#
directive|include
file|<win32iop.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* PERL_OBJECT */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* WIN32 */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|DOINIT
end_ifdef

begin_decl_stmt
name|EXT
name|MGVTBL
name|vtbl_sv
init|=
block|{
name|magic_get
block|,
name|magic_set
block|,
name|magic_len
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
name|vtbl_env
init|=
block|{
literal|0
block|,
name|magic_set_all_env
block|,
literal|0
block|,
name|magic_clear_all_env
block|,
literal|0
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|EXT
name|MGVTBL
name|vtbl_envelem
init|=
block|{
literal|0
block|,
name|magic_setenv
block|,
literal|0
block|,
name|magic_clearenv
block|,
literal|0
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|EXT
name|MGVTBL
name|vtbl_sig
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
name|vtbl_sigelem
init|=
block|{
name|magic_getsig
block|,
name|magic_setsig
block|,
literal|0
block|,
name|magic_clearsig
block|,
literal|0
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|EXT
name|MGVTBL
name|vtbl_pack
init|=
block|{
literal|0
block|,
literal|0
block|,
name|magic_sizepack
block|,
name|magic_wipepack
block|,
literal|0
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|EXT
name|MGVTBL
name|vtbl_packelem
init|=
block|{
name|magic_getpack
block|,
name|magic_setpack
block|,
literal|0
block|,
name|magic_clearpack
block|,
literal|0
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|EXT
name|MGVTBL
name|vtbl_dbline
init|=
block|{
literal|0
block|,
name|magic_setdbline
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
name|vtbl_isa
init|=
block|{
literal|0
block|,
name|magic_setisa
block|,
literal|0
block|,
name|magic_setisa
block|,
literal|0
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|EXT
name|MGVTBL
name|vtbl_isaelem
init|=
block|{
literal|0
block|,
name|magic_setisa
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
name|vtbl_arylen
init|=
block|{
name|magic_getarylen
block|,
name|magic_setarylen
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
name|vtbl_glob
init|=
block|{
name|magic_getglob
block|,
name|magic_setglob
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
name|vtbl_mglob
init|=
block|{
literal|0
block|,
name|magic_setmglob
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
name|vtbl_nkeys
init|=
block|{
name|magic_getnkeys
block|,
name|magic_setnkeys
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
name|vtbl_taint
init|=
block|{
name|magic_gettaint
block|,
name|magic_settaint
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
name|vtbl_substr
init|=
block|{
name|magic_getsubstr
block|,
name|magic_setsubstr
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
name|vtbl_vec
init|=
block|{
name|magic_getvec
block|,
name|magic_setvec
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
name|vtbl_pos
init|=
block|{
name|magic_getpos
block|,
name|magic_setpos
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
name|vtbl_bm
init|=
block|{
literal|0
block|,
name|magic_setbm
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
name|vtbl_fm
init|=
block|{
literal|0
block|,
name|magic_setfm
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
name|vtbl_uvar
init|=
block|{
name|magic_getuvar
block|,
name|magic_setuvar
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
name|vtbl_mutex
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
name|magic_mutexfree
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
name|vtbl_defelem
init|=
block|{
name|magic_getdefelem
block|,
name|magic_setdefelem
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
name|vtbl_regexp
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
name|magic_freeregexp
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
name|vtbl_collxfrm
init|=
block|{
literal|0
block|,
name|magic_setcollxfrm
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

begin_ifdef
ifdef|#
directive|ifdef
name|OVERLOAD
end_ifdef

begin_decl_stmt
name|EXT
name|MGVTBL
name|vtbl_amagic
init|=
block|{
literal|0
block|,
name|magic_setamagic
block|,
literal|0
block|,
literal|0
block|,
name|magic_setamagic
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|EXT
name|MGVTBL
name|vtbl_amagicelem
init|=
block|{
literal|0
block|,
name|magic_setamagic
block|,
literal|0
block|,
literal|0
block|,
name|magic_setamagic
block|}
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* OVERLOAD */
end_comment

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
name|vtbl_sv
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|EXT
name|MGVTBL
name|vtbl_env
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|EXT
name|MGVTBL
name|vtbl_envelem
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|EXT
name|MGVTBL
name|vtbl_sig
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|EXT
name|MGVTBL
name|vtbl_sigelem
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|EXT
name|MGVTBL
name|vtbl_pack
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|EXT
name|MGVTBL
name|vtbl_packelem
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|EXT
name|MGVTBL
name|vtbl_dbline
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|EXT
name|MGVTBL
name|vtbl_isa
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|EXT
name|MGVTBL
name|vtbl_isaelem
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|EXT
name|MGVTBL
name|vtbl_arylen
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|EXT
name|MGVTBL
name|vtbl_glob
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|EXT
name|MGVTBL
name|vtbl_mglob
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|EXT
name|MGVTBL
name|vtbl_nkeys
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|EXT
name|MGVTBL
name|vtbl_taint
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|EXT
name|MGVTBL
name|vtbl_substr
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|EXT
name|MGVTBL
name|vtbl_vec
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|EXT
name|MGVTBL
name|vtbl_pos
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|EXT
name|MGVTBL
name|vtbl_bm
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|EXT
name|MGVTBL
name|vtbl_fm
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|EXT
name|MGVTBL
name|vtbl_uvar
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
name|vtbl_mutex
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
name|vtbl_defelem
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|EXT
name|MGVTBL
name|vtbl_regexp
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
name|vtbl_collxfrm
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|OVERLOAD
end_ifdef

begin_decl_stmt
name|EXT
name|MGVTBL
name|vtbl_amagic
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|EXT
name|MGVTBL
name|vtbl_amagicelem
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* OVERLOAD */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !DOINIT */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|OVERLOAD
end_ifdef

begin_define
define|#
directive|define
name|NofAMmeth
value|58
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
name|AMG_names
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
block|}
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
name|AMG_names
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
block|}
enum|;
end_enum

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

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* OVERLOAD */
end_comment

begin_define
define|#
directive|define
name|PERLDB_ALL
value|0x3f
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
comment|/* Debug sub enter/exit. */
end_comment

begin_define
define|#
directive|define
name|PERLDBf_LINE
value|0x02
end_define

begin_comment
comment|/* Keep line #. */
end_comment

begin_define
define|#
directive|define
name|PERLDBf_NOOPT
value|0x04
end_define

begin_comment
comment|/* Switch off optimizations. */
end_comment

begin_define
define|#
directive|define
name|PERLDBf_INTER
value|0x08
end_define

begin_comment
comment|/* Preserve more data for 					   later inspections.  */
end_comment

begin_define
define|#
directive|define
name|PERLDBf_SUBLINE
value|0x10
end_define

begin_comment
comment|/* Keep subr source lines. */
end_comment

begin_define
define|#
directive|define
name|PERLDBf_SINGLE
value|0x20
end_define

begin_comment
comment|/* Start with single-step on. */
end_comment

begin_define
define|#
directive|define
name|PERLDBf_NONAME
value|0x40
end_define

begin_comment
comment|/* For _SUB: no name of the subr. */
end_comment

begin_define
define|#
directive|define
name|PERLDBf_GOTO
value|0x80
end_define

begin_comment
comment|/* Report goto: call DB::goto. */
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
value|STMT_START {				\ 	if (! PL_numeric_standard)			\ 	    perl_set_numeric_standard();	\     } STMT_END
end_define

begin_define
define|#
directive|define
name|SET_NUMERIC_LOCAL
parameter_list|()
define|\
value|STMT_START {				\ 	if (! PL_numeric_local)			\ 	    perl_set_numeric_local();		\     } STMT_END
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

begin_ifndef
ifndef|#
directive|ifndef
name|Semctl
end_ifndef

begin_comment
comment|/* Place our bets on the semun horse. */
end_comment

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

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Include guard */
end_comment

end_unit

