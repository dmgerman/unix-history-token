begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * config.h  *  * By Ross Ridge  * Public Domain  * 92/02/19 18:56:28  *  * @(#) mytinfo config.h 3.3 92/02/19 public domain, By Ross Ridge  *  * Read the file INSTALL for more information on configuring mytinfo  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_CONFIG_H_
end_ifndef

begin_define
define|#
directive|define
name|_CONFIG_H_
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|__STDC__
end_ifdef

begin_define
define|#
directive|define
name|USE_ANSIC
end_define

begin_comment
comment|/* undefine this if your compiler lies */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|USE_TERMIOS
end_define

begin_comment
comment|/* use POSIX termios */
end_comment

begin_undef
undef|#
directive|undef
name|USE_TERMIO
end_undef

begin_comment
comment|/* use termio (SysIII, SysV) */
end_comment

begin_undef
undef|#
directive|undef
name|USE_SGTTY
end_undef

begin_comment
comment|/* use sgtty (v7, BSD) */
end_comment

begin_define
define|#
directive|define
name|USE_WINSZ
end_define

begin_comment
comment|/* get window size from the tty driver */
end_comment

begin_undef
undef|#
directive|undef
name|USE_STRINGS
end_undef

begin_comment
comment|/* include<strings.h> instead of<string.h> */
end_comment

begin_undef
undef|#
directive|undef
name|USE_MYBSEARCH
end_undef

begin_comment
comment|/* your library doesn't have bsearch */
end_comment

begin_undef
undef|#
directive|undef
name|USE_MYSTRTOK
end_undef

begin_comment
comment|/* your library doesn't have strtok */
end_comment

begin_undef
undef|#
directive|undef
name|USE_MYQSORT
end_undef

begin_comment
comment|/* your library doesn't have qsort */
end_comment

begin_undef
undef|#
directive|undef
name|USE_MYMKDIR
end_undef

begin_comment
comment|/* your library doesn't have mkdir */
end_comment

begin_define
define|#
directive|define
name|USE_MEMORY
end_define

begin_comment
comment|/* you have an<memory.h> header */
end_comment

begin_undef
undef|#
directive|undef
name|USE_FAKE_STDIO
end_undef

begin_comment
comment|/* don't use real stdio */
end_comment

begin_undef
undef|#
directive|undef
name|USE_DOPRNT
end_undef

begin_comment
comment|/* no vfprintf, use _doprnt */
end_comment

begin_undef
undef|#
directive|undef
name|USE_TERMINFO
end_undef

begin_comment
comment|/* look in terminfo dirs for entry */
end_comment

begin_define
define|#
directive|define
name|USE_TERMCAP
end_define

begin_comment
comment|/* look in termcap dirs for entry */
end_comment

begin_undef
undef|#
directive|undef
name|USE_SHORT_BSEARCH
end_undef

begin_comment
comment|/* speeds up MYBSEARCH on most machines */
end_comment

begin_undef
undef|#
directive|undef
name|USE_SMALLMEM
end_undef

begin_comment
comment|/* save some memory */
end_comment

begin_undef
undef|#
directive|undef
name|USE_UPBC_KLUDGE
end_undef

begin_comment
comment|/* do tgoto like real togo */
end_comment

begin_undef
undef|#
directive|undef
name|USE_EXTERN_UPBC
end_undef

begin_comment
comment|/* get cuu1 and cub1 from externs UP and BC */
end_comment

begin_undef
undef|#
directive|undef
name|USE_LITOUT_KLUDGE
end_undef

begin_comment
comment|/* an alternate tgoto kludge, not recommened */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|USE_ANSIC
end_ifndef

begin_undef
undef|#
directive|undef
name|USE_PROTOTYPES
end_undef

begin_comment
comment|/* use ANSI C prototypes */
end_comment

begin_undef
undef|#
directive|undef
name|USE_STDLIB
end_undef

begin_comment
comment|/* you have a<stdlib.h> */
end_comment

begin_undef
undef|#
directive|undef
name|USE_STDARG
end_undef

begin_comment
comment|/* you have a<stdarg.h> */
end_comment

begin_undef
undef|#
directive|undef
name|USE_STDDEF
end_undef

begin_comment
comment|/* you have a<stddef.h> */
end_comment

begin_define
define|#
directive|define
name|const
end_define

begin_define
define|#
directive|define
name|volatile
end_define

begin_define
define|#
directive|define
name|noreturn
end_define

begin_comment
comment|/* a function that doesn't return */
end_comment

begin_typedef
typedef|typedef
name|char
modifier|*
name|anyptr
typedef|;
end_typedef

begin_comment
comment|/* a type that any pointer can be assigned to */
end_comment

begin_define
define|#
directive|define
name|mysize_t
value|unsigned
end_define

begin_comment
comment|/* size_t, the size of an object */
end_comment

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* USE_ANSIC */
end_comment

begin_define
define|#
directive|define
name|USE_PROTOTYPES
end_define

begin_define
define|#
directive|define
name|USE_STDLIB
end_define

begin_define
define|#
directive|define
name|USE_STDARG
end_define

begin_define
define|#
directive|define
name|USE_STDDEF
end_define

begin_typedef
typedef|typedef
name|void
modifier|*
name|anyptr
typedef|;
end_typedef

begin_define
define|#
directive|define
name|mysize_t
value|size_t
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|__GNUC__
end_ifdef

begin_define
define|#
directive|define
name|noreturn
value|volatile
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|noreturn
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
comment|/* USE_ANSIC */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__FreeBSD__
end_ifdef

begin_define
define|#
directive|define
name|TERMCAPFILE
value|"$TERMCAPFILE $HOME/.termcap /usr/share/misc/termcap"
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|TERMCAPFILE
value|"$TERMCAPFILE $HOME/.termcap /etc/termcap"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|TERMINFOSRC
value|"/usr/lib/terminfo/terminfo.src"
end_define

begin_define
define|#
directive|define
name|TERMINFODIR
value|"/usr/lib/terminfo"
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

