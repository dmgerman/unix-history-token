begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  C K C D E B . H  */
end_comment

begin_comment
comment|/*   This file is included by all C-Kermit modules, including the modules   that aren't specific to Kermit (like the command parser and the ck?tio and   ck?fio modules.  It specifies format codes for debug(), tlog(), and similar   functions, and includes any necessary definitions to be used by all C-Kermit   modules, and also includes some feature selection compile-time switches, and   also system- or compiler-dependent definitions, plus #includes and prototypes   required by all C-Kermit modules. */
end_comment

begin_comment
comment|/*   Author: Frank da Cruz (fdc@columbia.edu, FDCCU@CUVMA.BITNET),   Columbia University Center for Computing Activities.   First released January 1985.   Copyright (C) 1985, 1992, Trustees of Columbia University in the City of New   York.  Permission is granted to any individual or institution to use this   software as long as it is not sold for profit.  This copyright notice must be   retained.  This software may not be included in commercial products without   written permission of Columbia University. */
end_comment

begin_comment
comment|/*   Etymology: The name of this file means "C-Kermit Common-C-Language Debugging   Header", because originally it contained only the formats (F000-F111) for   the debug() and tlog() functions.  See how it has grown... */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|CKCDEB_H
end_ifndef

begin_comment
comment|/* Don't include me more than once. */
end_comment

begin_define
define|#
directive|define
name|CKCDEB_H
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|OS2
end_ifdef

begin_comment
comment|/* For OS/2 debugging */
end_comment

begin_include
include|#
directive|include
file|"ckoker.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* OS2 */
end_comment

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_comment
comment|/* Begin by including this. */
end_comment

begin_include
include|#
directive|include
file|<ctype.h>
end_include

begin_comment
comment|/* and this. */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|MAC
end_ifdef

begin_comment
comment|/*  * The MAC doesn't use standard stdio routines.  */
end_comment

begin_undef
undef|#
directive|undef
name|getchar
end_undef

begin_undef
undef|#
directive|undef
name|putchar
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* MAC */
end_comment

begin_comment
comment|/* System-type compilation switches */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|FT21
end_ifdef

begin_comment
comment|/* Fortune For:Pro 2.1 implies 1.8 */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|FT18
end_ifndef

begin_define
define|#
directive|define
name|FT18
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* FT18 */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* FT21 */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|AIXPS2
end_ifdef

begin_comment
comment|/* AIXPS2 implies AIX370 */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|AIX370
end_ifndef

begin_define
define|#
directive|define
name|AIX370
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* AIX370 */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* AIXPS2 */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|AIX370
end_ifdef

begin_comment
comment|/* AIX PS/2 or 370 implies BSD4 */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|BSD4
end_ifndef

begin_define
define|#
directive|define
name|BSD4
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* BSD4 */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* AIX370 */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|DGUX540
end_ifdef

begin_comment
comment|/* DG UX 5.40 implies Sys V R 4 */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SVR4
end_ifndef

begin_define
define|#
directive|define
name|SVR4
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* SVR4 */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* DGUX540 */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|SUNOS41
end_ifdef

begin_comment
comment|/* SUNOS41 implies SUNOS4 */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SUNOS4
end_ifndef

begin_define
define|#
directive|define
name|SUNOS4
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* SUNOS4 */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* SUNOS41 */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|SUN4S5
end_ifdef

begin_comment
comment|/* Sun-4 System V environment */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SVR3
end_ifndef

begin_comment
comment|/* implies System V R3 or later */
end_comment

begin_define
define|#
directive|define
name|SVR3
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* SVR3 */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* SUN4S5 */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|MIPS
end_ifdef

begin_comment
comment|/* MIPS System V environment */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SVR3
end_ifndef

begin_comment
comment|/* implies System V R3 or later */
end_comment

begin_define
define|#
directive|define
name|SVR3
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* SVR3 */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* MIPS */
end_comment

begin_comment
comment|/*   4.4BSD is a mixture of System V R4, POSIX, and 4.3BSD. */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|BSD44
end_ifdef

begin_comment
comment|/* 4.4 BSD */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SVR4
end_ifndef

begin_comment
comment|/* BSD44 implies SVR4 */
end_comment

begin_define
define|#
directive|define
name|SVR4
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* SVR4 */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|NOSETBUF
end_ifndef

begin_comment
comment|/* NOSETBUF is safe */
end_comment

begin_define
define|#
directive|define
name|NOSETBUF
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* NOSETBUF */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|DIRENT
end_ifndef

begin_comment
comment|/* Uses<dirent.h> */
end_comment

begin_define
define|#
directive|define
name|DIRENT
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* DIRENT */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* BSD44 */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|SVR3
end_ifdef

begin_comment
comment|/* SVR3 implies ATTSV */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|ATTSV
end_ifndef

begin_define
define|#
directive|define
name|ATTSV
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ATTSV */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* SVR3 */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|SVR4
end_ifdef

begin_comment
comment|/* SVR4 implies ATTSV */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|ATTSV
end_ifndef

begin_define
define|#
directive|define
name|ATTSV
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ATTSV */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SVR3
end_ifndef

begin_comment
comment|/* ...as well as SVR3 */
end_comment

begin_define
define|#
directive|define
name|SVR3
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* SVR3 */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* SVR4 */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|UTSV
end_ifdef

begin_comment
comment|/* UTSV implies ATTSV */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|ATTSV
end_ifndef

begin_define
define|#
directive|define
name|ATTSV
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ATTSV */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* UTSV */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|XENIX
end_ifdef

begin_comment
comment|/* XENIX implies ATTSV */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|ATTSV
end_ifndef

begin_define
define|#
directive|define
name|ATTSV
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ATTSV */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* XENIX */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|AUX
end_ifdef

begin_comment
comment|/* AUX implies ATTSV */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|ATTSV
end_ifndef

begin_define
define|#
directive|define
name|ATTSV
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ATTSV */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* AUX */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|ATT7300
end_ifdef

begin_comment
comment|/* ATT7300 implies ATTSV */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|ATTSV
end_ifndef

begin_define
define|#
directive|define
name|ATTSV
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ATTSV */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ATT7300 */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|ATT6300
end_ifdef

begin_comment
comment|/* ATT6300 implies ATTSV */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|ATTSV
end_ifndef

begin_define
define|#
directive|define
name|ATTSV
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ATTSV */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ATT6300 */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HPUX
end_ifdef

begin_comment
comment|/* HPUX implies ATTSV */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|ATTSV
end_ifndef

begin_define
define|#
directive|define
name|ATTSV
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ATTSV */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HPUX */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|ISIII
end_ifdef

begin_comment
comment|/* ISIII implies ATTSV */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|ATTSV
end_ifndef

begin_define
define|#
directive|define
name|ATTSV
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ATTSV */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ISIII */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|NEXT
end_ifdef

begin_comment
comment|/* NEXT implies BSD4 */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|BSD4
end_ifndef

begin_define
define|#
directive|define
name|BSD4
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* BSD4 */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* NEXT */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|SUNOS4
end_ifdef

begin_comment
comment|/* SUNOS4 implies BSD4 */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|BSD4
end_ifndef

begin_define
define|#
directive|define
name|BSD4
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* BSD4 */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* SUNOS4 */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|BSD41
end_ifdef

begin_comment
comment|/* BSD41 implies BSD4 */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|BSD4
end_ifndef

begin_define
define|#
directive|define
name|BSD4
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* BSD4 */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* BSD41 */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|BSD43
end_ifdef

begin_comment
comment|/* BSD43 implies BSD4 */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|BSD4
end_ifndef

begin_define
define|#
directive|define
name|BSD4
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* BSD4 */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* BSD43 */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|BSD4
end_ifdef

begin_comment
comment|/* BSD4 implies ANYBSD */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|ANYBSD
end_ifndef

begin_define
define|#
directive|define
name|ANYBSD
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ANYBSD */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* BSD4 */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|BSD29
end_ifdef

begin_comment
comment|/* BSD29 implies ANYBSD */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|ANYBSD
end_ifndef

begin_define
define|#
directive|define
name|ANYBSD
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ANYBSD */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* BSD29 */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|ATTSV
end_ifdef

begin_comment
comment|/* ATTSV implies UNIX */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|UNIX
end_ifndef

begin_define
define|#
directive|define
name|UNIX
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* UNIX */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ATTSV */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|ANYBSD
end_ifdef

begin_comment
comment|/* ANYBSD implies UNIX */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|UNIX
end_ifndef

begin_define
define|#
directive|define
name|UNIX
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* UNIX */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ANYBSD */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|POSIX
end_ifdef

begin_comment
comment|/* POSIX implies UNIX */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|UNIX
end_ifndef

begin_define
define|#
directive|define
name|UNIX
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* UNIX */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|DIRENT
end_ifndef

begin_comment
comment|/* and DIRENT, i.e.<dirent.h> */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SDIRENT
end_ifndef

begin_define
define|#
directive|define
name|DIRENT
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* SDIRENT */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* DIRENT */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|NOFILEH
end_ifndef

begin_comment
comment|/* POSIX doesn't use<sys/file.h> */
end_comment

begin_define
define|#
directive|define
name|NOFILEH
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* NOFILEH */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* POSIX */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|V7
end_ifdef

begin_ifndef
ifndef|#
directive|ifndef
name|UNIX
end_ifndef

begin_define
define|#
directive|define
name|UNIX
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* UNIX */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* V7 */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|COHERENT
end_ifdef

begin_ifndef
ifndef|#
directive|ifndef
name|UNIX
end_ifndef

begin_define
define|#
directive|define
name|UNIX
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* UNIX */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* COHERENT */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|MINIX
end_ifdef

begin_ifndef
ifndef|#
directive|ifndef
name|UNIX
end_ifndef

begin_define
define|#
directive|define
name|UNIX
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* UNIX */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* MINIX */
end_comment

begin_comment
comment|/*   The symbol SVORPOSIX is defined for both AT&T and POSIX compilations   to make it easier to select items that System V and POSIX have in common,   but which BSD, V7, etc, do not have. */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|ATTSV
end_ifdef

begin_ifndef
ifndef|#
directive|ifndef
name|SVORPOSIX
end_ifndef

begin_define
define|#
directive|define
name|SVORPOSIX
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* SVORPOSIX */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ATTSV */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|POSIX
end_ifdef

begin_ifndef
ifndef|#
directive|ifndef
name|SVORPOSIX
end_ifndef

begin_define
define|#
directive|define
name|SVORPOSIX
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* SVORPOSIX */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* POSIX */
end_comment

begin_comment
comment|/*   The symbol SVR4ORPOSIX is defined for both AT&T System V R4 and POSIX    compilations to make it easier to select items that System V R4 and POSIX    have in common, but which BSD, V7, and System V R3 and earlier, etc, do   not have. */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|POSIX
end_ifdef

begin_ifndef
ifndef|#
directive|ifndef
name|SVR4ORPOSIX
end_ifndef

begin_define
define|#
directive|define
name|SVR4ORPOSIX
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* SVR4ORPOSIX */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* POSIX */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|SVR4
end_ifdef

begin_ifndef
ifndef|#
directive|ifndef
name|SVR4ORPOSIX
end_ifndef

begin_define
define|#
directive|define
name|SVR4ORPOSIX
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* SVR4ORPOSIX */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* SVR4 */
end_comment

begin_comment
comment|/*   The symbol BSD44ORPOSIX is defined for both 4.4BSD and POSIX compilations   to make it easier to select items that 4.4BSD and POSIX have in common,   but which System V, BSD, V7, etc, do not have. */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|BSD44
end_ifdef

begin_ifndef
ifndef|#
directive|ifndef
name|BSD44ORPOSIX
end_ifndef

begin_define
define|#
directive|define
name|BSD44ORPOSIX
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* BSD44ORPOSIX */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* BSD44 */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|POSIX
end_ifdef

begin_ifndef
ifndef|#
directive|ifndef
name|BSD44ORPOSIX
end_ifndef

begin_define
define|#
directive|define
name|BSD44ORPOSIX
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* BSD44ORPOSIX */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* POSIX */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|apollo
end_ifdef

begin_comment
comment|/* May be ANSI-C, check further */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__STDCPP__
end_ifdef

begin_define
define|#
directive|define
name|CK_ANSIC
end_define

begin_comment
comment|/* Yes, this is real ANSI-C */
end_comment

begin_define
define|#
directive|define
name|SIG_V
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|NOANSI
end_define

begin_comment
comment|/* Nope, not ANSI */
end_comment

begin_undef
undef|#
directive|undef
name|__STDC__
end_undef

begin_comment
comment|/* Even though it say it is! */
end_comment

begin_define
define|#
directive|define
name|SIG_I
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __STDCPP__ */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* apollo */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|POSIX
end_ifdef

begin_comment
comment|/* -DPOSIX on cc command line */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_POSIX_SOURCE
end_ifndef

begin_comment
comment|/* Implies _POSIX_SOURCE */
end_comment

begin_define
define|#
directive|define
name|_POSIX_SOURCE
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _POSIX_SOURCE */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* POSIX */
end_comment

begin_comment
comment|/*   ANSI C?  That is, do we have function prototypes, new-style   function declarations, and parameter type checking and coercion? */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|MAC
end_ifdef

begin_comment
comment|/* MPW C is ANSI */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|NOANSI
end_ifndef

begin_ifndef
ifndef|#
directive|ifndef
name|CK_ANSIC
end_ifndef

begin_define
define|#
directive|define
name|CK_ANSIC
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CK_ANSIC */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* NOANSI */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* MAC */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|NOANSI
end_ifndef

begin_ifdef
ifdef|#
directive|ifdef
name|__STDC__
end_ifdef

begin_comment
comment|/* __STDC__ means ANSI C */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|CK_ANSIC
end_ifndef

begin_define
define|#
directive|define
name|CK_ANSIC
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CK_ANSIC */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __STDC__ */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* NOANSI */
end_comment

begin_comment
comment|/*   _PROTOTYP() is used for forward declarations of functions so we can have   parameter and return value type checking if the compiler offers it.   __STDC__ should be defined by the compiler only if function prototypes are   allowed.  Otherwise, we get old-style forward declarations.  Our own private   CK_ANSIC symbol tells whether we use ANSI C prototypes.  To force use of   ANSI prototypes, include -DCK_ANSIC on the cc command line.  To disable the   use of ANSI prototypes, include -DNOANSI. */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|CK_ANSIC
end_ifdef

begin_define
define|#
directive|define
name|_PROTOTYP
parameter_list|(
name|func
parameter_list|,
name|parms
parameter_list|)
value|func parms
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* Not ANSI C */
end_comment

begin_define
define|#
directive|define
name|_PROTOTYP
parameter_list|(
name|func
parameter_list|,
name|parms
parameter_list|)
value|func()
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CK_ANSIC */
end_comment

begin_comment
comment|/*   Altos-specific items: 486, 586, 986 models... */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|A986
end_ifdef

begin_define
define|#
directive|define
name|M_VOID
end_define

begin_define
define|#
directive|define
name|void
value|int
end_define

begin_define
define|#
directive|define
name|CHAR
value|char
end_define

begin_define
define|#
directive|define
name|SIG_I
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* A986 */
end_comment

begin_comment
comment|/* Void type */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|VOID
end_ifndef

begin_comment
comment|/* Used throughout all C-Kermit */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|CK_ANSIC
end_ifdef

begin_comment
comment|/* modules... */
end_comment

begin_define
define|#
directive|define
name|VOID
value|void
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|VOID
value|int
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CK_ANSIC */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* VOID */
end_comment

begin_comment
comment|/* Signal type */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SIG_V
end_ifndef

begin_comment
comment|/* signal() type, if not def'd yet */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SIG_I
end_ifndef

begin_ifdef
ifdef|#
directive|ifdef
name|OS2
end_ifdef

begin_define
define|#
directive|define
name|SIG_V
end_define

begin_else
else|#
directive|else
end_else

begin_ifdef
ifdef|#
directive|ifdef
name|POSIX
end_ifdef

begin_define
define|#
directive|define
name|SIG_V
end_define

begin_else
else|#
directive|else
end_else

begin_ifdef
ifdef|#
directive|ifdef
name|SVR3
end_ifdef

begin_comment
comment|/* System V R3 and later */
end_comment

begin_define
define|#
directive|define
name|SIG_V
end_define

begin_else
else|#
directive|else
end_else

begin_ifdef
ifdef|#
directive|ifdef
name|SUNOS4
end_ifdef

begin_comment
comment|/* SUNOS V 4.0 and later */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|sun386
end_ifndef

begin_define
define|#
directive|define
name|SIG_V
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|SIG_I
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* sun386 */
end_comment

begin_else
else|#
directive|else
end_else

begin_ifdef
ifdef|#
directive|ifdef
name|NEXT
end_ifdef

begin_comment
comment|/* NeXT */
end_comment

begin_define
define|#
directive|define
name|SIG_V
end_define

begin_else
else|#
directive|else
end_else

begin_ifdef
ifdef|#
directive|ifdef
name|AIX370
end_ifdef

begin_define
define|#
directive|define
name|SIG_V
end_define

begin_define
define|#
directive|define
name|SIGTYP
value|__SIGVOID
end_define

begin_comment
comment|/* AIX370 */
end_comment

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|SIG_I
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* AIX370 */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* NEXT */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* SUNOS4 */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* SVR3 */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* POSIX */
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
comment|/* SIG_I */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* SIG_V */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|SIG_I
end_ifdef

begin_define
define|#
directive|define
name|SIGRETURN
value|return(0)
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|SIGTYP
end_ifndef

begin_define
define|#
directive|define
name|SIGTYP
value|int
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* SIGTYP */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* SIG_I */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|SIG_V
end_ifdef

begin_define
define|#
directive|define
name|SIGRETURN
value|return
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|SIGTYP
end_ifndef

begin_define
define|#
directive|define
name|SIGTYP
value|void
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* SIGTYP */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* SIG_V */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SIGTYP
end_ifndef

begin_define
define|#
directive|define
name|SIGTYP
value|int
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* SIGTYP */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SIGRETURN
end_ifndef

begin_define
define|#
directive|define
name|SIGRETURN
value|return(0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* SIGRETURN */
end_comment

begin_comment
comment|/* We want all characters to be unsigned if the compiler supports it */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|PROVX1
end_ifdef

begin_typedef
typedef|typedef
name|char
name|CHAR
typedef|;
end_typedef

begin_comment
comment|/* typedef long LONG; */
end_comment

begin_typedef
typedef|typedef
name|int
name|void
typedef|;
end_typedef

begin_else
else|#
directive|else
end_else

begin_ifdef
ifdef|#
directive|ifdef
name|MINIX
end_ifdef

begin_typedef
typedef|typedef
name|unsigned
name|char
name|CHAR
typedef|;
end_typedef

begin_else
else|#
directive|else
end_else

begin_ifdef
ifdef|#
directive|ifdef
name|V7
end_ifdef

begin_typedef
typedef|typedef
name|char
name|CHAR
typedef|;
end_typedef

begin_else
else|#
directive|else
end_else

begin_ifdef
ifdef|#
directive|ifdef
name|C70
end_ifdef

begin_typedef
typedef|typedef
name|char
name|CHAR
typedef|;
end_typedef

begin_comment
comment|/* typedef long LONG; */
end_comment

begin_else
else|#
directive|else
end_else

begin_ifdef
ifdef|#
directive|ifdef
name|BSD29
end_ifdef

begin_typedef
typedef|typedef
name|char
name|CHAR
typedef|;
end_typedef

begin_comment
comment|/* typedef long LONG; */
end_comment

begin_else
else|#
directive|else
end_else

begin_ifdef
ifdef|#
directive|ifdef
name|datageneral
end_ifdef

begin_define
define|#
directive|define
name|CHAR
value|unsigned char
end_define

begin_comment
comment|/* 3.22 compiler */
end_comment

begin_else
else|#
directive|else
end_else

begin_ifdef
ifdef|#
directive|ifdef
name|CHAR
end_ifdef

begin_undef
undef|#
directive|undef
name|CHAR
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CHAR */
end_comment

begin_typedef
typedef|typedef
name|unsigned
name|char
name|CHAR
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* datageneral */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* BSD29 */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* C70 */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* V7 */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* MINIX */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* PROVX1 */
end_comment

begin_comment
comment|/*  Debug and transaction logging is included automatically unless you define  NODEBUG or NOTLOG.  Do this if you want to save the space and overhead.  (Note, in version 4F these definitions changed from "{}" to the null string  to avoid problems with semicolons after braces, as in: "if (x) tlog(this);  else tlog(that);" */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|NODEBUG
end_ifndef

begin_ifndef
ifndef|#
directive|ifndef
name|DEBUG
end_ifndef

begin_define
define|#
directive|define
name|DEBUG
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* DEBUG */
end_comment

begin_else
else|#
directive|else
end_else

begin_ifdef
ifdef|#
directive|ifdef
name|DEBUG
end_ifdef

begin_undef
undef|#
directive|undef
name|DEBUG
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* DEBUG */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* NODEBUG */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|NOTLOG
end_ifndef

begin_ifndef
ifndef|#
directive|ifndef
name|TLOG
end_ifndef

begin_define
define|#
directive|define
name|TLOG
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* TLOG */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* NOTLOG */
end_comment

begin_comment
comment|/* debug() macro style selection. */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|MAC
end_ifdef

begin_ifndef
ifndef|#
directive|ifndef
name|IFDEBUG
end_ifndef

begin_define
define|#
directive|define
name|IFDEBUG
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* IFDEBUG */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* MAC */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|OS2
end_ifdef

begin_ifndef
ifndef|#
directive|ifndef
name|IFDEBUG
end_ifndef

begin_define
define|#
directive|define
name|IFDEBUG
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* IFDEBUG */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* OS2 */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|DEBUG
end_ifndef

begin_comment
comment|/* Compile all the debug() statements away.  Saves a lot of space and time. */
end_comment

begin_define
define|#
directive|define
name|debug
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|,
name|d
parameter_list|)
end_define

begin_else
else|#
directive|else
end_else

begin_ifndef
ifndef|#
directive|ifndef
name|CKCMAI
end_ifndef

begin_comment
comment|/* Debugging included.  Declare debug log flag in main program only. */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|deblog
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CKCMAI */
end_comment

begin_comment
comment|/* Now define the debug() macro. */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|IFDEBUG
end_ifdef

begin_comment
comment|/* Use this form to avoid function calls: */
end_comment

begin_define
define|#
directive|define
name|debug
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|,
name|d
parameter_list|)
value|if (deblog) dodebug(a,b,(char *)c,(long)d)
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* Use this form to save space: */
end_comment

begin_define
define|#
directive|define
name|debug
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|,
name|d
parameter_list|)
value|dodebug(a,b,(char *)c,(long)d)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* MAC */
end_comment

begin_macro
name|_PROTOTYP
argument_list|(
argument|int dodebug
argument_list|,
argument|(int, char *, char *, long)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* DEBUG */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|TLOG
end_ifndef

begin_define
define|#
directive|define
name|tlog
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|,
name|d
parameter_list|)
end_define

begin_else
else|#
directive|else
end_else

begin_macro
name|_PROTOTYP
argument_list|(
argument|VOID tlog
argument_list|,
argument|(int, char *, char *, long)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* TLOG */
end_comment

begin_comment
comment|/* Formats for debug() and tlog() */
end_comment

begin_define
define|#
directive|define
name|F000
value|0
end_define

begin_define
define|#
directive|define
name|F001
value|1
end_define

begin_define
define|#
directive|define
name|F010
value|2
end_define

begin_define
define|#
directive|define
name|F011
value|3
end_define

begin_define
define|#
directive|define
name|F100
value|4
end_define

begin_define
define|#
directive|define
name|F101
value|5
end_define

begin_define
define|#
directive|define
name|F110
value|6
end_define

begin_define
define|#
directive|define
name|F111
value|7
end_define

begin_comment
comment|/* Kermit feature selection */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|MAC
end_ifdef

begin_comment
comment|/* For Macintosh, no escape */
end_comment

begin_define
define|#
directive|define
name|NOPUSH
end_define

begin_comment
comment|/* to operating system */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* MAC */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|UNIX
end_ifdef

begin_ifndef
ifndef|#
directive|ifndef
name|NOPARSEN
end_ifndef

begin_define
define|#
directive|define
name|PARSENSE
end_define

begin_comment
comment|/* Automatic parity detection */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* NOPARSEN */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* UNIX */
end_comment

begin_comment
comment|/* for Unix */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|VMS
end_ifdef

begin_comment
comment|/* ... and VMS */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|NOPARSEN
end_ifndef

begin_define
define|#
directive|define
name|PARSENSE
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* NOPARSEN */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* VMS */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|MAC
end_ifdef

begin_comment
comment|/* and Macintosh */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|NOPARSEN
end_ifndef

begin_define
define|#
directive|define
name|PARSENSE
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* NOPARSEN */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* MAC */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|VMS
end_ifdef

begin_comment
comment|/* Use dynamic memory allocation */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|DYNAMIC
end_ifndef

begin_define
define|#
directive|define
name|DYNAMIC
end_define

begin_comment
comment|/* in VMS version. */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* DYNAMIC */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* VMS */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|CK_LBRK
end_ifndef

begin_comment
comment|/* Can send Long BREAK */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|UNIX
end_ifdef

begin_comment
comment|/* (everybody but OS-9) */
end_comment

begin_define
define|#
directive|define
name|CK_LBRK
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* UNIX */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|VMS
end_ifdef

begin_define
define|#
directive|define
name|CK_LBRK
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* VMS */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|datageneral
end_ifdef

begin_define
define|#
directive|define
name|CK_LBRK
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* datageneral */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|GEMDOS
end_ifdef

begin_define
define|#
directive|define
name|CK_LBRK
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* GEMDOS */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|OS2
end_ifdef

begin_define
define|#
directive|define
name|CK_LBRK
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* OS2 */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|AMIGA
end_ifdef

begin_define
define|#
directive|define
name|CK_LBRK
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* AMIGA */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CK_LBRK */
end_comment

begin_comment
comment|/* Carrier treatment */
end_comment

begin_comment
comment|/* These are defined here because they are shared by the system dependent */
end_comment

begin_comment
comment|/* and the system independent modules. */
end_comment

begin_define
define|#
directive|define
name|CAR_OFF
value|0
end_define

begin_comment
comment|/* On: heed carrier always, except during DIAL. */
end_comment

begin_define
define|#
directive|define
name|CAR_ON
value|1
end_define

begin_comment
comment|/* Off: ignore carrier always. */
end_comment

begin_define
define|#
directive|define
name|CAR_AUT
value|2
end_define

begin_comment
comment|/* Auto: heed carrier, but only if line is declared */
end_comment

begin_comment
comment|/* to be a modem line, and only during CONNECT. */
end_comment

begin_comment
comment|/* Hangup by modem command supported by default */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|NODIAL
end_ifndef

begin_ifndef
ifndef|#
directive|ifndef
name|NOMDMHUP
end_ifndef

begin_ifndef
ifndef|#
directive|ifndef
name|MDMHUP
end_ifndef

begin_define
define|#
directive|define
name|MDMHUP
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* MDMHUP */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* NOMDMHUP */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* NODIAL */
end_comment

begin_comment
comment|/* Types of flow control available */
end_comment

begin_define
define|#
directive|define
name|CK_XONXOFF
end_define

begin_comment
comment|/* Everybody can do this, right? */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|AMIGA
end_ifdef

begin_comment
comment|/* Commodore Amiga */
end_comment

begin_define
define|#
directive|define
name|CK_RTSCTS
end_define

begin_comment
comment|/* has RTS/CTS */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* AMIGA */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|SUN4S5
end_ifdef

begin_comment
comment|/* SunOS in System V environment */
end_comment

begin_define
define|#
directive|define
name|CK_RTSCTS
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* SunOS 4.0/4.1 in BSD environment */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|SUNOS4
end_ifdef

begin_comment
comment|/* SunOS 4.0+later supports RTS/CTS */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|SUNOS41
end_ifdef

begin_comment
comment|/* Easy in 4.1 and later */
end_comment

begin_define
define|#
directive|define
name|CK_RTSCTS
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* Harder in 4.0 */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__GNUC__
end_ifndef

begin_comment
comment|/* (see tthflow() in ckutio.c) */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|GNUC
end_ifndef

begin_define
define|#
directive|define
name|CK_RTSCTS
end_define

begin_comment
comment|/* Only if not using GNU gcc */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __GNUC__ */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* GNUC */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* SUNOS41 */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* SUNOS4 */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* SUN4S5 */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|BSD44
end_ifdef

begin_comment
comment|/* And in 4.4 BSD */
end_comment

begin_define
define|#
directive|define
name|CK_RTSCTS
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* BSD44 */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|TERMIOX
end_ifdef

begin_comment
comment|/* Sys V R4<termiox.h> */
end_comment

begin_define
define|#
directive|define
name|CK_RTSCTS
end_define

begin_comment
comment|/* has RTS/CTS */
end_comment

begin_define
define|#
directive|define
name|CK_DTRCD
end_define

begin_comment
comment|/* and DTR/CD */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* TERMIOX */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|STERMIOX
end_ifdef

begin_comment
comment|/* Sys V R4<sys/termiox.h> */
end_comment

begin_define
define|#
directive|define
name|CK_RTSCTS
end_define

begin_comment
comment|/* Ditto. */
end_comment

begin_define
define|#
directive|define
name|CK_DTRCD
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* STERMIOX */
end_comment

begin_comment
comment|/*  Systems where we can expand tilde at the beginning of file or directory names */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|POSIX
end_ifdef

begin_ifndef
ifndef|#
directive|ifndef
name|DTILDE
end_ifndef

begin_define
define|#
directive|define
name|DTILDE
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* DTILDE */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* POSIX */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|BSD4
end_ifdef

begin_ifndef
ifndef|#
directive|ifndef
name|DTILDE
end_ifndef

begin_define
define|#
directive|define
name|DTILDE
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* DTILDE */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* BSD4 */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|ATTSV
end_ifdef

begin_ifndef
ifndef|#
directive|ifndef
name|DTILDE
end_ifndef

begin_define
define|#
directive|define
name|DTILDE
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* DTILDE */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ATTSV */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|OSK
end_ifdef

begin_ifndef
ifndef|#
directive|ifndef
name|DTILDE
end_ifndef

begin_define
define|#
directive|define
name|DTILDE
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* DTILDE */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* OSK */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HPUX
end_ifdef

begin_comment
comment|/* I don't know why this is */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|DTILDE
end_ifndef

begin_comment
comment|/* necessary, since -DHPUX */
end_comment

begin_define
define|#
directive|define
name|DTILDE
end_define

begin_comment
comment|/* automatically defines ATTSV */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* DTILDE */
end_comment

begin_comment
comment|/* (see above) ... */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HPUX */
end_comment

begin_comment
comment|/* Line delimiter for text files */
end_comment

begin_comment
comment|/*  If the system uses a single character for text file line delimitation,  define NLCHAR to the value of that character.  For text files, that  character will be converted to CRLF upon output, and CRLF will be converted  to that character on input during text-mode (default) packet operations. */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|MAC
end_ifdef

begin_comment
comment|/* Macintosh */
end_comment

begin_define
define|#
directive|define
name|NLCHAR
value|015
end_define

begin_else
else|#
directive|else
end_else

begin_ifdef
ifdef|#
directive|ifdef
name|OSK
end_ifdef

begin_comment
comment|/* OS-9/68K */
end_comment

begin_define
define|#
directive|define
name|NLCHAR
value|015
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* All Unix-like systems */
end_comment

begin_define
define|#
directive|define
name|NLCHAR
value|012
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* OSK */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* MAC */
end_comment

begin_comment
comment|/*  At this point, if there's a system that uses ordinary CRLF line  delimitation AND the C compiler actually returns both the CR and  the LF when doing input from a file, then #undef NLCHAR. */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|OS2
end_ifdef

begin_comment
comment|/* OS/2 */
end_comment

begin_undef
undef|#
directive|undef
name|NLCHAR
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* OS2 */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|GEMDOS
end_ifdef

begin_comment
comment|/* Atari ST */
end_comment

begin_undef
undef|#
directive|undef
name|NLCHAR
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* GEMDOS */
end_comment

begin_comment
comment|/*   VMS file formats are so complicated we need to do all the conversion    work in the CKVFIO module, so we tell the rest of C-Kermit not to fiddle   with the bytes. */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|vms
end_ifdef

begin_undef
undef|#
directive|undef
name|NLCHAR
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* vms */
end_comment

begin_comment
comment|/* The device name of a job's controlling terminal */
end_comment

begin_comment
comment|/* Special for VMS, same for all Unixes (?), not used by Macintosh */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|vms
end_ifdef

begin_define
define|#
directive|define
name|CTTNAM
value|"TT:"
end_define

begin_else
else|#
directive|else
end_else

begin_ifdef
ifdef|#
directive|ifdef
name|datageneral
end_ifdef

begin_define
define|#
directive|define
name|CTTNAM
value|"@output"
end_define

begin_else
else|#
directive|else
end_else

begin_ifdef
ifdef|#
directive|ifdef
name|OSK
end_ifdef

begin_decl_stmt
specifier|extern
name|char
name|myttystr
index|[]
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|CTTNAM
value|myttystr
end_define

begin_else
else|#
directive|else
end_else

begin_ifdef
ifdef|#
directive|ifdef
name|OS2
end_ifdef

begin_define
define|#
directive|define
name|CTTNAM
value|"con"
end_define

begin_else
else|#
directive|else
end_else

begin_ifdef
ifdef|#
directive|ifdef
name|UNIX
end_ifdef

begin_define
define|#
directive|define
name|CTTNAM
value|"/dev/tty"
end_define

begin_else
else|#
directive|else
end_else

begin_ifdef
ifdef|#
directive|ifdef
name|GEMDOS
end_ifdef

begin_define
define|#
directive|define
name|CTTNAM
value|"aux:"
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* Anyone else... */
end_comment

begin_define
define|#
directive|define
name|CTTNAM
value|"stdout"
end_define

begin_comment
comment|/* This is a kludge used by Mac */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* GEMDOS */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* UNIX */
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
comment|/* OSK */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* datageneral */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* vms */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|SUNS4S5
end_ifdef

begin_define
define|#
directive|define
name|tolower
value|_tolower
end_define

begin_define
define|#
directive|define
name|toupper
value|_toupper
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* SUNS4S5 */
end_comment

begin_comment
comment|/* Error number */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|VMS
end_ifndef

begin_ifndef
ifndef|#
directive|ifndef
name|OS2
end_ifndef

begin_comment
comment|/*   The following declaration causes problems for VMS and OS/2, in which   errno is an "extern volatile int noshare"... */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|errno
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Needed by most modules. */
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
comment|/* VMS */
end_comment

begin_comment
comment|/* File System Defaults */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|VMS
end_ifdef

begin_define
define|#
directive|define
name|DBLKSIZ
value|512
end_define

begin_define
define|#
directive|define
name|DLRECL
value|512
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|DBLKSIZ
value|0
end_define

begin_define
define|#
directive|define
name|DLRECL
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Program return codes for DECUS C and UNIX (VMS uses UNIX codes) */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|decus
end_ifdef

begin_define
define|#
directive|define
name|GOOD_EXIT
value|IO_NORMAL
end_define

begin_define
define|#
directive|define
name|BAD_EXIT
value|IO_ERROR
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|GOOD_EXIT
value|0
end_define

begin_define
define|#
directive|define
name|BAD_EXIT
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* decus */
end_comment

begin_comment
comment|/* Special hack for Fortune, which doesn't have<sys/file.h>... */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|FT18
end_ifdef

begin_define
define|#
directive|define
name|FREAD
value|0x01
end_define

begin_define
define|#
directive|define
name|FWRITE
value|0x10
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* FT18 */
end_comment

begin_comment
comment|/* Special hack for OS-9/68k */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|OSK
end_ifdef

begin_define
define|#
directive|define
name|SIGALRM
value|30
end_define

begin_comment
comment|/* May always cancel I/O */
end_comment

begin_define
define|#
directive|define
name|SIGARB
value|1234
end_define

begin_comment
comment|/* Arbitrary for I/O */
end_comment

begin_expr_stmt
name|SIGTYP
argument_list|(
operator|*
name|signal
argument_list|()
argument_list|)
argument_list|()
expr_stmt|;
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* OSK */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|OS2
end_ifdef

begin_ifdef
ifdef|#
directive|ifdef
name|putchar
end_ifdef

begin_comment
comment|/* MSC 5.1 simply uses a macro which causes */
end_comment

begin_undef
undef|#
directive|undef
name|putchar
end_undef

begin_comment
comment|/* no problems. */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* putchar */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* OS2 */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|MINIX
end_ifdef

begin_ifdef
ifdef|#
directive|ifdef
name|putchar
end_ifdef

begin_undef
undef|#
directive|undef
name|putchar
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* putchar */
end_comment

begin_define
define|#
directive|define
name|putchar
parameter_list|(
name|c
parameter_list|)
value|{putc(c,stdout);fflush(stdout);}
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* MINIX */
end_comment

begin_comment
comment|/* Escape/quote character used by the command parser */
end_comment

begin_define
define|#
directive|define
name|CMDQ
value|'\\'
end_define

begin_comment
comment|/* Symbols for RS-232 modem signals */
end_comment

begin_define
define|#
directive|define
name|KM_FG
value|1
end_define

begin_comment
comment|/* Frame ground */
end_comment

begin_define
define|#
directive|define
name|KM_TXD
value|2
end_define

begin_comment
comment|/* Transmit */
end_comment

begin_define
define|#
directive|define
name|KM_RXD
value|3
end_define

begin_comment
comment|/* Receive */
end_comment

begin_define
define|#
directive|define
name|KM_RTS
value|4
end_define

begin_comment
comment|/* Request to Send */
end_comment

begin_define
define|#
directive|define
name|KM_CTS
value|5
end_define

begin_comment
comment|/* Clear to Send */
end_comment

begin_define
define|#
directive|define
name|KM_DSR
value|6
end_define

begin_comment
comment|/* Data Set Ready */
end_comment

begin_define
define|#
directive|define
name|KM_SG
value|7
end_define

begin_comment
comment|/* Signal ground */
end_comment

begin_define
define|#
directive|define
name|KM_DCD
value|8
end_define

begin_comment
comment|/* Carrier Detect */
end_comment

begin_define
define|#
directive|define
name|KM_DTR
value|20
end_define

begin_comment
comment|/* Data Terminal Ready */
end_comment

begin_define
define|#
directive|define
name|KM_RI
value|22
end_define

begin_comment
comment|/* Ring Indication */
end_comment

begin_comment
comment|/* Bit mask values for modem signals */
end_comment

begin_define
define|#
directive|define
name|BM_CTS
value|0001
end_define

begin_comment
comment|/* Clear to send       (From DCE) */
end_comment

begin_define
define|#
directive|define
name|BM_DSR
value|0002
end_define

begin_comment
comment|/* Dataset ready       (From DCE) */
end_comment

begin_define
define|#
directive|define
name|BM_DCD
value|0004
end_define

begin_comment
comment|/* Carrier             (From DCE) */
end_comment

begin_define
define|#
directive|define
name|BM_RNG
value|0010
end_define

begin_comment
comment|/* Ring Indicator      (From DCE) */
end_comment

begin_define
define|#
directive|define
name|BM_DTR
value|0020
end_define

begin_comment
comment|/* Data Terminal Ready (From DTE) */
end_comment

begin_define
define|#
directive|define
name|BM_RTS
value|0040
end_define

begin_comment
comment|/* Request to Send     (From DTE) */
end_comment

begin_comment
comment|/* Codes for full duplex flow control */
end_comment

begin_define
define|#
directive|define
name|FLO_NONE
value|0
end_define

begin_comment
comment|/* None */
end_comment

begin_define
define|#
directive|define
name|FLO_XONX
value|1
end_define

begin_comment
comment|/* Xon/Xoff (soft) */
end_comment

begin_define
define|#
directive|define
name|FLO_RTSC
value|2
end_define

begin_comment
comment|/* RTS/CTS (hard) */
end_comment

begin_define
define|#
directive|define
name|FLO_DTRC
value|3
end_define

begin_comment
comment|/* DTR/CD (hard) */
end_comment

begin_define
define|#
directive|define
name|FLO_ETXA
value|4
end_define

begin_comment
comment|/* ETX/ACK (soft) */
end_comment

begin_define
define|#
directive|define
name|FLO_STRG
value|5
end_define

begin_comment
comment|/* String-based (soft) */
end_comment

begin_define
define|#
directive|define
name|FLO_DIAL
value|6
end_define

begin_comment
comment|/* DIALing kludge */
end_comment

begin_define
define|#
directive|define
name|FLO_DIAX
value|7
end_define

begin_comment
comment|/* Cancel dialing kludge */
end_comment

begin_define
define|#
directive|define
name|FLO_DTRT
value|8
end_define

begin_comment
comment|/* DTR/CTS (hard) */
end_comment

begin_define
define|#
directive|define
name|FLO_KEEP
value|9
end_define

begin_comment
comment|/* Keep, i.e. don't touch or change */
end_comment

begin_comment
comment|/* And finally... */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|COMMENT
end_ifdef

begin_comment
comment|/* Make sure this is NOT defined! */
end_comment

begin_undef
undef|#
directive|undef
name|COMMENT
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* COMMENT */
end_comment

begin_comment
comment|/* Structure definitions for Kermit file attributes */
end_comment

begin_comment
comment|/* All strings come as pointer and length combinations */
end_comment

begin_comment
comment|/* Empty string (or for numeric variables, -1) = unused attribute. */
end_comment

begin_struct
struct|struct
name|zstr
block|{
comment|/* string format */
name|int
name|len
decl_stmt|;
comment|/* length */
name|char
modifier|*
name|val
decl_stmt|;
comment|/* value */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|zattr
block|{
comment|/* Kermit File Attribute structure */
name|long
name|lengthk
decl_stmt|;
comment|/* (!) file length in K */
name|struct
name|zstr
name|type
decl_stmt|;
comment|/* (") file type (text or binary) */
name|struct
name|zstr
name|date
decl_stmt|;
comment|/* (#) file creation date yyyymmdd[ hh:mm[:ss]] */
name|struct
name|zstr
name|creator
decl_stmt|;
comment|/* ($) file creator id */
name|struct
name|zstr
name|account
decl_stmt|;
comment|/* (%) file account */
name|struct
name|zstr
name|area
decl_stmt|;
comment|/* (&) area (e.g. directory) for file */
name|struct
name|zstr
name|passwd
decl_stmt|;
comment|/* (') password for area */
name|long
name|blksize
decl_stmt|;
comment|/* (() file blocksize */
name|struct
name|zstr
name|access
decl_stmt|;
comment|/* ()) file access: new, supersede, append, warn */
name|struct
name|zstr
name|encoding
decl_stmt|;
comment|/* (*) encoding (transfer syntax) */
name|struct
name|zstr
name|disp
decl_stmt|;
comment|/* (+) disposition (mail, message, print, etc) */
name|struct
name|zstr
name|lprotect
decl_stmt|;
comment|/* (,) protection (local syntax) */
name|struct
name|zstr
name|gprotect
decl_stmt|;
comment|/* (-) protection (generic syntax) */
name|struct
name|zstr
name|systemid
decl_stmt|;
comment|/* (.) ID for system of origin */
name|struct
name|zstr
name|recfm
decl_stmt|;
comment|/* (/) record format */
name|struct
name|zstr
name|sysparam
decl_stmt|;
comment|/* (0) system-dependent parameter string */
name|long
name|length
decl_stmt|;
comment|/* (1) exact length on system of origin */
name|struct
name|zstr
name|charset
decl_stmt|;
comment|/* (2) transfer syntax character set */
name|struct
name|zstr
name|reply
decl_stmt|;
comment|/* This goes last, used for attribute reply */
block|}
struct|;
end_struct

begin_comment
comment|/* Kermit file information structure */
end_comment

begin_struct
struct|struct
name|filinfo
block|{
name|int
name|bs
decl_stmt|;
comment|/* Blocksize */
name|int
name|cs
decl_stmt|;
comment|/* Character set */
name|long
name|rl
decl_stmt|;
comment|/* Record length */
name|int
name|org
decl_stmt|;
comment|/* Organization */
name|int
name|fmt
decl_stmt|;
comment|/* Record format */
name|int
name|cc
decl_stmt|;
comment|/* Carriage control */
name|int
name|typ
decl_stmt|;
comment|/* Type (text/binary) */
name|int
name|dsp
decl_stmt|;
comment|/* Disposition */
name|char
modifier|*
name|os_specific
decl_stmt|;
comment|/* OS-specific attributes */
name|unsigned
name|int
name|lblopts
decl_stmt|;
comment|/* LABELED FILE options bitmask */
block|}
struct|;
end_struct

begin_comment
comment|/* VMS values for LABELED FILE options bitmask */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|VMS
end_ifdef

begin_define
define|#
directive|define
name|LBL_NAM
value|1
end_define

begin_comment
comment|/* Ignore incoming name if set */
end_comment

begin_define
define|#
directive|define
name|LBL_PTH
value|2
end_define

begin_comment
comment|/* Use complete path if set */
end_comment

begin_define
define|#
directive|define
name|LBL_ACL
value|4
end_define

begin_comment
comment|/* Preserve ACLs if set */
end_comment

begin_define
define|#
directive|define
name|LBL_BCK
value|8
end_define

begin_comment
comment|/* Preserve backup date if set */
end_comment

begin_define
define|#
directive|define
name|LBL_OWN
value|16
end_define

begin_comment
comment|/* Preserve ownership if set */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* VMS */
end_comment

begin_comment
comment|/*   Data types.  First the header file for data types so we can pick up the   types used for pids, uids, and gids.  Override this section by putting   -DCKTYP_H=xxx on the command line to specify the header file where your   system defines these types. */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|OSK
end_ifdef

begin_comment
comment|/* OS-9 */
end_comment

begin_include
include|#
directive|include
file|<types.h>
end_include

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* General case, not OS-9 */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|CKTYP_H
end_ifndef

begin_ifndef
ifndef|#
directive|ifndef
name|VMS
end_ifndef

begin_ifndef
ifndef|#
directive|ifndef
name|MAC
end_ifndef

begin_ifndef
ifndef|#
directive|ifndef
name|AMIGA
end_ifndef

begin_define
define|#
directive|define
name|CKTYP_H
value|<sys/types.h>
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* AMIGA */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* MAC */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* VMS */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CKTYP_H */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|GEMDOS
end_ifdef

begin_undef
undef|#
directive|undef
name|CKTYP_H
end_undef

begin_include
include|#
directive|include
file|<types.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* GEMDOS */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|CKTYP_H
end_ifdef

begin_comment
comment|/* Include it. */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|COHERENT
end_ifdef

begin_comment
comment|/* Except for COHERENT */
end_comment

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_else
else|#
directive|else
end_else

begin_ifdef
ifdef|#
directive|ifdef
name|datageneral
end_ifdef

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_comment
comment|/* Compiler didn't like other */
end_comment

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
include|CKTYP_H
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* datageneral */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* COHERENT */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CKTYP_H */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* OSK */
end_comment

begin_comment
comment|/* End of types.h section */
end_comment

begin_comment
comment|/*   Data type for pids.  If your system uses a different type, put something   like -DPID_T=pid_t on command line, or override here. */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|PID_T
end_ifndef

begin_define
define|#
directive|define
name|PID_T
value|int
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* PID_T */
end_comment

begin_comment
comment|/*   Data types for uids and gids.  Same deal as for pids.   Wouldn't be nice if there was a preprocessor test to find out if a   typedef existed? */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|VMS
end_ifdef

begin_comment
comment|/* Not used in VMS so who cares */
end_comment

begin_define
define|#
directive|define
name|UID_T
value|int
end_define

begin_define
define|#
directive|define
name|GID_T
value|int
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* VMS */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|POSIX
end_ifdef

begin_comment
comment|/* Or would it be better (or worse?) to use _POSIX_SOURCE here? */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|UID_T
end_ifndef

begin_define
define|#
directive|define
name|UID_T
value|uid_t
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* UID_T */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|GID_T
end_ifndef

begin_define
define|#
directive|define
name|GID_T
value|gid_t
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* GID_T */
end_comment

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* Not POSIX */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|SVR4
end_ifdef

begin_comment
comment|/* SVR4 and later have uid_t and gid_t. */
end_comment

begin_comment
comment|/* SVR3 and earlier use int, or unsigned short, or.... */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|UID_T
end_ifndef

begin_define
define|#
directive|define
name|UID_T
value|uid_t
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* UID_T */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|GID_T
end_ifndef

begin_define
define|#
directive|define
name|GID_T
value|gid_t
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* GID_T */
end_comment

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* Not SVR4 */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|BSD43
end_ifdef

begin_ifndef
ifndef|#
directive|ifndef
name|UID_T
end_ifndef

begin_define
define|#
directive|define
name|UID_T
value|uid_t
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* UID_T */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|GID_T
end_ifndef

begin_define
define|#
directive|define
name|GID_T
value|gid_t
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* GID_T */
end_comment

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* Not BSD43 */
end_comment

begin_comment
comment|/* Default these to int for older UNIX versions */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|UID_T
end_ifndef

begin_define
define|#
directive|define
name|UID_T
value|int
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* UID_T */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|GID_T
end_ifndef

begin_define
define|#
directive|define
name|GID_T
value|int
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* GID_T */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* BSD43 */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* SVR4  */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* POSIX */
end_comment

begin_comment
comment|/*    getpwuid() arg type, which is not necessarily the same as UID_T,   e.g. in SCO UNIX SVR3, it's int. */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|PWID_T
end_ifndef

begin_define
define|#
directive|define
name|PWID_T
value|UID_T
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* PWID_T */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|NEXT
end_ifdef

begin_comment
comment|/* Argument for wait() */
end_comment

begin_include
include|#
directive|include
file|<sys/wait.h>
end_include

begin_typedef
typedef|typedef
name|union
name|wait
name|WAIT_T
typedef|;
end_typedef

begin_else
else|#
directive|else
end_else

begin_ifdef
ifdef|#
directive|ifdef
name|POSIX
end_ifdef

begin_include
include|#
directive|include
file|<sys/wait.h>
end_include

begin_define
define|#
directive|define
name|WAIT_T
value|pid_t
end_define

begin_else
else|#
directive|else
end_else

begin_typedef
typedef|typedef
name|int
name|WAIT_T
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* POSIX */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* NEXT */
end_comment

begin_comment
comment|/* Forward declarations of system-dependent functions callable from all */
end_comment

begin_comment
comment|/* C-Kermit modules. */
end_comment

begin_comment
comment|/* File-related functions from system-dependent file i/o module */
end_comment

begin_macro
name|_PROTOTYP
argument_list|(
argument|int zkself
argument_list|,
argument|(void)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYP
argument_list|(
argument|int zopeni
argument_list|,
argument|(int, char *)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYP
argument_list|(
argument|int zopeno
argument_list|,
argument|(int, char *, struct zattr *, struct filinfo *)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYP
argument_list|(
argument|int zclose
argument_list|,
argument|(int)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_ifndef
ifndef|#
directive|ifndef
name|MAC
end_ifndef

begin_macro
name|_PROTOTYP
argument_list|(
argument|int zchin
argument_list|,
argument|(int, int *)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* MAC */
end_comment

begin_macro
name|_PROTOTYP
argument_list|(
argument|int zsinl
argument_list|,
argument|(int, char *, int)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYP
argument_list|(
argument|int zinfill
argument_list|,
argument|(void)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYP
argument_list|(
argument|int zsout
argument_list|,
argument|(int, char*)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYP
argument_list|(
argument|int zsoutl
argument_list|,
argument|(int, char*)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYP
argument_list|(
argument|int zsoutx
argument_list|,
argument|(int, char*, int)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYP
argument_list|(
argument|int zchout
argument_list|,
argument|(int, char)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYP
argument_list|(
argument|int zoutdump
argument_list|,
argument|(void)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYP
argument_list|(
argument|int zsyscmd
argument_list|,
argument|(char *)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYP
argument_list|(
argument|int zshcmd
argument_list|,
argument|(char *)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYP
argument_list|(
argument|int chkfn
argument_list|,
argument|(int)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYP
argument_list|(
argument|long zchki
argument_list|,
argument|(char *)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYP
argument_list|(
argument|int iswild
argument_list|,
argument|(char *)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYP
argument_list|(
argument|int zchko
argument_list|,
argument|(char *)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYP
argument_list|(
argument|int zdelet
argument_list|,
argument|(char *)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYP
argument_list|(
argument|VOID zrtol
argument_list|,
argument|(char *,char *)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYP
argument_list|(
argument|VOID zltor
argument_list|,
argument|(char *,char *)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYP
argument_list|(
argument|VOID zstrip
argument_list|,
argument|(char *,char **)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYP
argument_list|(
argument|int zchdir
argument_list|,
argument|(char *)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_expr_stmt
name|_PROTOTYP
argument_list|(
name|char
operator|*
name|zhome
argument_list|,
operator|(
name|void
operator|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|_PROTOTYP
argument_list|(
name|char
operator|*
name|zgtdir
argument_list|,
operator|(
name|void
operator|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_macro
name|_PROTOTYP
argument_list|(
argument|int zxcmd
argument_list|,
argument|(int, char *)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_ifndef
ifndef|#
directive|ifndef
name|MAC
end_ifndef

begin_macro
name|_PROTOTYP
argument_list|(
argument|int zclosf
argument_list|,
argument|(int)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* MAC */
end_comment

begin_macro
name|_PROTOTYP
argument_list|(
argument|int zxpand
argument_list|,
argument|(char *)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYP
argument_list|(
argument|int znext
argument_list|,
argument|(char *)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYP
argument_list|(
argument|int zchkspa
argument_list|,
argument|(char *, long)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYP
argument_list|(
argument|VOID znewn
argument_list|,
argument|(char *, char **)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYP
argument_list|(
argument|int zrename
argument_list|,
argument|(char *, char *)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYP
argument_list|(
argument|int zsattr
argument_list|,
argument|(struct zattr *)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYP
argument_list|(
argument|int zfree
argument_list|,
argument|(char *)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_expr_stmt
name|_PROTOTYP
argument_list|(
name|char
operator|*
name|zfcdat
argument_list|,
operator|(
name|char
operator|*
operator|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_macro
name|_PROTOTYP
argument_list|(
argument|int zstime
argument_list|,
argument|(char *, struct zattr *, int)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYP
argument_list|(
argument|int zmail
argument_list|,
argument|(char *, char *)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYP
argument_list|(
argument|int zprint
argument_list|,
argument|(char *, char *)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_expr_stmt
name|_PROTOTYP
argument_list|(
name|char
operator|*
name|tilde_expand
argument_list|,
operator|(
name|char
operator|*
operator|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* Functions from system-dependent terminal i/o module */
end_comment

begin_macro
name|_PROTOTYP
argument_list|(
argument|int ttopen
argument_list|,
argument|(char *, int *, int, int)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|/* tty functions */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|MAC
end_ifndef

begin_macro
name|_PROTOTYP
argument_list|(
argument|int ttclos
argument_list|,
argument|(int)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* MAC */
end_comment

begin_macro
name|_PROTOTYP
argument_list|(
argument|int tthang
argument_list|,
argument|(void)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYP
argument_list|(
argument|int ttres
argument_list|,
argument|(void)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYP
argument_list|(
argument|int ttpkt
argument_list|,
argument|(long, int, int)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_ifndef
ifndef|#
directive|ifndef
name|MAC
end_ifndef

begin_macro
name|_PROTOTYP
argument_list|(
argument|int ttvt
argument_list|,
argument|(long, int)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* MAC */
end_comment

begin_macro
name|_PROTOTYP
argument_list|(
argument|int ttsspd
argument_list|,
argument|(int)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYP
argument_list|(
argument|long ttgspd
argument_list|,
argument|(void)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYP
argument_list|(
argument|int ttflui
argument_list|,
argument|(void)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYP
argument_list|(
argument|int ttfluo
argument_list|,
argument|(void)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYP
argument_list|(
argument|int ttchk
argument_list|,
argument|(void)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYP
argument_list|(
argument|int ttxin
argument_list|,
argument|(int, CHAR *)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYP
argument_list|(
argument|int ttol
argument_list|,
argument|(CHAR *, int)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYP
argument_list|(
argument|int ttoc
argument_list|,
argument|(char)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYP
argument_list|(
argument|int ttinc
argument_list|,
argument|(int)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYP
argument_list|(
argument|int ttscarr
argument_list|,
argument|(int)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYP
argument_list|(
argument|int ttgmdm
argument_list|,
argument|(void)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYP
argument_list|(
argument|int ttsndb
argument_list|,
argument|(void)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYP
argument_list|(
argument|int ttsndlb
argument_list|,
argument|(void)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|PARSENSE
end_ifdef

begin_ifdef
ifdef|#
directive|ifdef
name|UNIX
end_ifdef

begin_macro
name|_PROTOTYP
argument_list|(
argument|int ttinl
argument_list|,
argument|(CHAR *, int, int, CHAR, CHAR, int)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_else
else|#
directive|else
end_else

begin_ifdef
ifdef|#
directive|ifdef
name|VMS
end_ifdef

begin_macro
name|_PROTOTYP
argument_list|(
argument|int ttinl
argument_list|,
argument|(CHAR *, int, int, CHAR, CHAR, int)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_else
else|#
directive|else
end_else

begin_macro
name|_PROTOTYP
argument_list|(
argument|int ttinl
argument_list|,
argument|(CHAR *, int, int, CHAR, CHAR)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* VMS */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* UNIX */
end_comment

begin_else
else|#
directive|else
end_else

begin_macro
name|_PROTOTYP
argument_list|(
argument|int ttinl
argument_list|,
argument|(CHAR *, int, int, CHAR)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* PARSENSE */
end_comment

begin_comment
comment|/* Console functions */
end_comment

begin_macro
name|_PROTOTYP
argument_list|(
argument|int congm
argument_list|,
argument|(void)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|COMMENT
end_ifdef

begin_macro
name|_PROTOTYP
argument_list|(
argument|VOID conint
argument_list|,
argument|(SIGTYP (*)(int, int), SIGTYP (*)(int, int))
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_else
else|#
directive|else
end_else

begin_macro
name|_PROTOTYP
argument_list|(
argument|VOID conint
argument_list|,
argument|(SIGTYP (*)(int), SIGTYP (*)(int))
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_macro
name|_PROTOTYP
argument_list|(
argument|VOID connoi
argument_list|,
argument|(void)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYP
argument_list|(
argument|int concb
argument_list|,
argument|(char)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYP
argument_list|(
argument|int conbin
argument_list|,
argument|(char)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYP
argument_list|(
argument|int conres
argument_list|,
argument|(void)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYP
argument_list|(
argument|int conoc
argument_list|,
argument|(char)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYP
argument_list|(
argument|int conxo
argument_list|,
argument|(int, char *)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYP
argument_list|(
argument|int conol
argument_list|,
argument|(char *)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYP
argument_list|(
argument|int conola
argument_list|,
argument|(char *[])
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYP
argument_list|(
argument|int conoll
argument_list|,
argument|(char *)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYP
argument_list|(
argument|int conchk
argument_list|,
argument|(void)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYP
argument_list|(
argument|int coninc
argument_list|,
argument|(int)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYP
argument_list|(
argument|int psuspend
argument_list|,
argument|(int)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYP
argument_list|(
argument|int priv_ini
argument_list|,
argument|(void)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYP
argument_list|(
argument|int priv_on
argument_list|,
argument|(void)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYP
argument_list|(
argument|int priv_off
argument_list|,
argument|(void)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYP
argument_list|(
argument|int priv_can
argument_list|,
argument|(void)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYP
argument_list|(
argument|int priv_chk
argument_list|,
argument|(void)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYP
argument_list|(
argument|int priv_opn
argument_list|,
argument|(char *, int)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYP
argument_list|(
argument|int sysinit
argument_list|,
argument|(void)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|/* Misc Kermit functions */
end_comment

begin_macro
name|_PROTOTYP
argument_list|(
argument|int syscleanup
argument_list|,
argument|(void)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYP
argument_list|(
argument|int msleep
argument_list|,
argument|(int)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYP
argument_list|(
argument|VOID rtimer
argument_list|,
argument|(void)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYP
argument_list|(
argument|int gtimer
argument_list|,
argument|(void)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYP
argument_list|(
argument|VOID ttimoff
argument_list|,
argument|(void)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYP
argument_list|(
argument|VOID ztime
argument_list|,
argument|(char **)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYP
argument_list|(
argument|int parchk
argument_list|,
argument|(CHAR *, CHAR, int)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYP
argument_list|(
argument|VOID doexit
argument_list|,
argument|(int, int)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYP
argument_list|(
argument|int askmore
argument_list|,
argument|(void)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYP
argument_list|(
argument|VOID fatal
argument_list|,
argument|(char *)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|/* Key mapping support */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|NOICP
end_ifdef

begin_ifndef
ifndef|#
directive|ifndef
name|NOSETKEY
end_ifndef

begin_define
define|#
directive|define
name|NOSETKEY
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* NOSETKEY */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* NOICP */
end_comment

begin_macro
name|_PROTOTYP
argument_list|(
argument|int congks
argument_list|,
argument|(int)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_ifndef
ifndef|#
directive|ifndef
name|NOSETKEY
end_ifndef

begin_ifdef
ifdef|#
directive|ifdef
name|OS2
end_ifdef

begin_define
define|#
directive|define
name|KMSIZE
value|768
end_define

begin_typedef
typedef|typedef
name|int
name|KEY
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|CHAR
modifier|*
name|MACRO
typedef|;
end_typedef

begin_decl_stmt
specifier|extern
name|int
name|wideresult
decl_stmt|;
end_decl_stmt

begin_macro
name|_PROTOTYP
argument_list|(
argument|VOID keymapinit
argument_list|,
argument|(void)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* Not OS2 */
end_comment

begin_comment
comment|/*   Catch-all for systems where we don't know how to read keyboard scan   codes> 255.  Note: CHAR (i.e. unsigned char) is very important here. */
end_comment

begin_define
define|#
directive|define
name|KMSIZE
value|256
end_define

begin_typedef
typedef|typedef
name|CHAR
name|KEY
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|CHAR
modifier|*
name|MACRO
typedef|;
end_typedef

begin_define
define|#
directive|define
name|congks
value|coninc
end_define

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
comment|/* NOSETKEY */
end_comment

begin_comment
comment|/*   Function prototypes for system and library functions. */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|_POSIX_SOURCE
end_ifdef

begin_ifndef
ifndef|#
directive|ifndef
name|VMS
end_ifndef

begin_ifndef
ifndef|#
directive|ifndef
name|MAC
end_ifndef

begin_define
define|#
directive|define
name|CK_ANSILIBS
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* MAC */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* VMS */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _POSIX_SOURCE */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|NEXT
end_ifdef

begin_define
define|#
directive|define
name|CK_ANSILIBS
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* NEXT */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|SVR4
end_ifdef

begin_define
define|#
directive|define
name|CK_ANSILIBS
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* SVR4 */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|OS2
end_ifdef

begin_define
define|#
directive|define
name|KANJI
end_define

begin_define
define|#
directive|define
name|CK_ANSILIBS
end_define

begin_define
define|#
directive|define
name|MYCURSES
end_define

begin_define
define|#
directive|define
name|CK_RTSCTS
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|__IBMC__
end_ifdef

begin_define
define|#
directive|define
name|S_IFMT
value|0xF000
end_define

begin_define
define|#
directive|define
name|timezone
value|_timezone
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __IBMC__ */
end_comment

begin_include
include|#
directive|include
file|<io.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|__EMX__
end_ifdef

begin_ifndef
ifndef|#
directive|ifndef
name|__32BIT__
end_ifndef

begin_define
define|#
directive|define
name|__32BIT__
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __32BIT__ */
end_comment

begin_include
include|#
directive|include
file|<sys/timeb.h>
end_include

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|<direct.h>
end_include

begin_define
define|#
directive|define
name|SIGALRM
value|SIGUSR1
end_define

begin_macro
name|_PROTOTYP
argument_list|(
argument|unsigned alarm
argument_list|,
argument|(unsigned)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYP
argument_list|(
argument|unsigned sleep
argument_list|,
argument|(unsigned)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __EMX__ */
end_comment

begin_macro
name|_PROTOTYP
argument_list|(
argument|long zdskspace
argument_list|,
argument|(int)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYP
argument_list|(
argument|int zchdsk
argument_list|,
argument|(int)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYP
argument_list|(
argument|int conincraw
argument_list|,
argument|(int)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYP
argument_list|(
argument|int ttiscom
argument_list|,
argument|(int f)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYP
argument_list|(
argument|int IsFileNameValid
argument_list|,
argument|(char *)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYP
argument_list|(
argument|void ChangeNameForFAT
argument_list|,
argument|(char *)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_expr_stmt
name|_PROTOTYP
argument_list|(
name|char
operator|*
name|GetLoadPath
argument_list|,
operator|(
name|void
operator|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* OS2 */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|MYCURSES
end_ifdef

begin_comment
comment|/* MYCURSES implies CK_CURSES */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|CK_CURSES
end_ifndef

begin_define
define|#
directive|define
name|CK_CURSES
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CK_CURSES */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* MYCURSES */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|CK_ANSILIBS
end_ifdef

begin_comment
comment|/*   String library functions.   For ANSI C, get prototypes from<string.h>.   Otherwise, skip the prototypes. */
end_comment

begin_include
include|#
directive|include
file|<string.h>
end_include

begin_comment
comment|/*   Prototypes for other commonly used library functions, such as   malloc, free, getenv, atol, atoi, and exit.  Otherwise, no prototypes. */
end_comment

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|DIAB
end_ifdef

begin_comment
comment|/* DIAB DS90 */
end_comment

begin_comment
comment|/* #include<commonC.h>  */
end_comment

begin_include
include|#
directive|include
file|<sys/wait.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|COMMENT
end_ifdef

begin_function_decl
specifier|extern
name|void
name|exit
parameter_list|(
name|int
name|status
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|_exit
parameter_list|(
name|int
name|status
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|uname
parameter_list|(
name|struct
name|utsname
modifier|*
name|name
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* COMMENT */
end_comment

begin_function_decl
specifier|extern
name|int
name|chmod
parameter_list|(
name|char
modifier|*
name|path
parameter_list|,
name|int
name|mode
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|ioctl
parameter_list|(
name|int
name|fildes
parameter_list|,
name|int
name|request
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|rdchk
parameter_list|(
name|int
name|ttyfd
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|nap
parameter_list|(
name|int
name|m
parameter_list|)
function_decl|;
end_function_decl

begin_ifdef
ifdef|#
directive|ifdef
name|COMMENT
end_ifdef

begin_function_decl
specifier|extern
name|int
name|getppid
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
comment|/* COMMENT */
end_comment

begin_function_decl
specifier|extern
name|int
name|_filbuf
parameter_list|(
name|FILE
modifier|*
name|stream
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|_flsbuf
parameter_list|(
name|char
name|c
parameter_list|,
name|FILE
modifier|*
name|stream
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* DIAB */
end_comment

begin_comment
comment|/*   Prototypes for UNIX functions like access, alarm, chdir, sleep, fork,   and pause.  Otherwise, no prototypes. */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|NEXT
end_ifdef

begin_include
include|#
directive|include
file|<libc.h>
end_include

begin_else
else|#
directive|else
end_else

begin_ifndef
ifndef|#
directive|ifndef
name|AMIGA
end_ifndef

begin_ifndef
ifndef|#
directive|ifndef
name|OS2
end_ifndef

begin_include
include|#
directive|include
file|<unistd.h>
end_include

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
comment|/* AMIGA */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* NEXT */
end_comment

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* Not ANSI libs... */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|MAC
end_ifdef

begin_include
include|#
directive|include
file|<String.h>
end_include

begin_include
include|#
directive|include
file|<StdLib.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* MAC */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|SUNOS41
end_ifdef

begin_include
include|#
directive|include
file|<unistd.h>
end_include

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_else
else|#
directive|else
end_else

begin_comment
comment|/*   It is essential that these are declared correctly! */
end_comment

begin_expr_stmt
name|_PROTOTYP
argument_list|(
name|char
operator|*
name|malloc
argument_list|,
operator|(
name|unsigned
name|int
operator|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|_PROTOTYP
argument_list|(
name|char
operator|*
name|getenv
argument_list|,
operator|(
name|char
operator|*
operator|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_macro
name|_PROTOTYP
argument_list|(
argument|long atol
argument_list|,
argument|(char *)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* SUNOS4 */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CK_ANSILIBS */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|NULL
end_ifndef

begin_comment
comment|/* In case NULL is still not defined */
end_comment

begin_define
define|#
directive|define
name|NULL
value|0L
end_define

begin_comment
comment|/* or #define NULL 0 */
end_comment

begin_comment
comment|/* or #define NULL ((char *) 0) */
end_comment

begin_comment
comment|/* or #define NULL ((void *) 0) */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* NULL */
end_comment

begin_comment
comment|/* Funny names for library functions department... */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|ZILOG
end_ifdef

begin_define
define|#
directive|define
name|setjmp
value|setret
end_define

begin_define
define|#
directive|define
name|longjmp
value|longret
end_define

begin_define
define|#
directive|define
name|jmp_buf
value|ret_buf
end_define

begin_define
define|#
directive|define
name|getcwd
value|curdir
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ZILOG */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CKCDEB_H */
end_comment

begin_comment
comment|/* End of ckcdeb.h */
end_comment

end_unit

