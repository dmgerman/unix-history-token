begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * vi configuration file  * We try to automatically configure to various compilers and operating  * systems. Extend the autoconf section as needed.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_CONFIG_H
end_ifndef

begin_define
define|#
directive|define
name|_CONFIG_H
end_define

begin_comment
comment|/*************************** autoconf section ************************/
end_comment

begin_comment
comment|/* Commodore-Amiga */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|amiga
end_ifdef

begin_define
define|#
directive|define
name|AMIGA
value|1
end_define

begin_define
define|#
directive|define
name|COMPILED_BY
value|"Manx Aztec C 5.2b"
end_define

begin_define
define|#
directive|define
name|TINYSTACK
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* standard unix V (?) */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|M_SYSV
end_ifdef

begin_define
define|#
directive|define
name|UNIXV
value|1
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|M_XENIX
end_ifdef

begin_ifndef
ifndef|#
directive|ifndef
name|M_I386
end_ifndef

begin_define
define|#
directive|define
name|TINYSTACK
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

begin_undef
undef|#
directive|undef
name|COHERENT
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* xelos system, University of Ulm */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|xelos
end_ifdef

begin_define
define|#
directive|define
name|UNIXV
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* BSD UNIX? */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|bsd
end_ifdef

begin_define
define|#
directive|define
name|BSD
value|1
end_define

begin_else
else|#
directive|else
end_else

begin_ifdef
ifdef|#
directive|ifdef
name|sun
end_ifdef

begin_ifndef
ifndef|#
directive|ifndef
name|M_SYSV
end_ifndef

begin_define
define|#
directive|define
name|BSD
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

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Microsoft C: sorry, Watcom does the same thing */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|M_I86
end_ifdef

begin_ifndef
ifndef|#
directive|ifndef
name|M_SYSV
end_ifndef

begin_define
define|#
directive|define
name|MSDOS
value|1
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|IBMC2
end_ifdef

begin_define
define|#
directive|define
name|COMPILED_BY
value|"IBM C/2 1.00"
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|MICROSOFT
value|1
end_define

begin_define
define|#
directive|define
name|COMPILED_BY
value|"Microsoft C 5.10"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|TINYSTACK
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

begin_comment
comment|/* Borland's Turbo C */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__TURBOC__
end_ifdef

begin_define
define|#
directive|define
name|MSDOS
value|1
end_define

begin_define
define|#
directive|define
name|TURBOC
value|1
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|__BORLANDC__
end_ifdef

begin_define
define|#
directive|define
name|COMPILED_BY
value|"Borland C 2.00"
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|COMPILED_BY
value|(__TURBOC__>= 661 ? "Turbo C++ 1.00" : "Turbo C 2.00")
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|TINYSTACK
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Tos Mark-Williams */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|M68000
end_ifdef

begin_define
define|#
directive|define
name|TOS
value|1
end_define

begin_define
define|#
directive|define
name|COMPILED_BY
value|"Mark Williams C"
end_define

begin_define
define|#
directive|define
name|TINYSTACK
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Tos GNU-C */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__atarist__
end_ifdef

begin_ifdef
ifdef|#
directive|ifdef
name|__gem__
end_ifdef

begin_define
define|#
directive|define
name|TOS
value|1
end_define

begin_define
define|#
directive|define
name|COMPILED_BY
value|"GNU-C " __VERSION__
end_define

begin_define
define|#
directive|define
name|TINYSTACK
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

begin_comment
comment|/* OS9/68000 */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|OSK
end_ifdef

begin_define
define|#
directive|define
name|COMPILED_BY
value|"Microware C V2.3 Edition 40"
end_define

begin_define
define|#
directive|define
name|TINYSTACK
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* DEC Rainbow, running MS-DOS (handled by earlier MS-DOS tests) */
end_comment

begin_comment
comment|/* (would need -DRAINBOW in CFLAGS to compile a Rainbow-compatible .EXE) */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|VMS
end_ifdef

begin_define
define|#
directive|define
name|COMPILED_BY
value|"VAX/VMS VAXC compiler"
end_define

begin_undef
undef|#
directive|undef
name|VMS
end_undef

begin_define
define|#
directive|define
name|VMS
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|COHERENT
end_ifdef

begin_ifdef
ifdef|#
directive|ifdef
name|_I386
end_ifdef

begin_define
define|#
directive|define
name|COH_386
value|1
end_define

begin_define
define|#
directive|define
name|COH_286
value|0
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|COH_386
value|0
end_define

begin_define
define|#
directive|define
name|COH_286
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_undef
undef|#
directive|undef
name|COHERENT
end_undef

begin_define
define|#
directive|define
name|COHERENT
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*************************** end of autoconf section ************************/
end_comment

begin_comment
comment|/* All undefined symbols are defined to zero here, to allow for older    */
end_comment

begin_comment
comment|/* compilers which dont understand #if defined() or #if UNDEFINED_SYMBOL */
end_comment

begin_comment
comment|/*************************** operating systems *****************************/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|BSD
end_ifndef

begin_define
define|#
directive|define
name|BSD
value|0
end_define

begin_comment
comment|/* UNIX - Berkeley 4.x */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|UNIXV
end_ifndef

begin_define
define|#
directive|define
name|UNIXV
value|0
end_define

begin_comment
comment|/* UNIX - AT&T SYSV */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|UNIX7
end_ifndef

begin_define
define|#
directive|define
name|UNIX7
value|0
end_define

begin_comment
comment|/* UNIX - version 7 */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|MSDOS
end_ifndef

begin_define
define|#
directive|define
name|MSDOS
value|0
end_define

begin_comment
comment|/* PC		*/
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|TOS
end_ifndef

begin_define
define|#
directive|define
name|TOS
value|0
end_define

begin_comment
comment|/* Atari ST	*/
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|AMIGA
end_ifndef

begin_define
define|#
directive|define
name|AMIGA
value|0
end_define

begin_comment
comment|/* Commodore Amiga */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|OSK
end_ifndef

begin_define
define|#
directive|define
name|OSK
value|0
end_define

begin_comment
comment|/* OS-9 / 68k */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|COHERENT
end_ifndef

begin_define
define|#
directive|define
name|COHERENT
value|0
end_define

begin_comment
comment|/* Coherent */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|RAINBOW
end_ifndef

begin_comment
comment|/* DEC Rainbow support, under MS-DOS */
end_comment

begin_define
define|#
directive|define
name|RAINBOW
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|VMS
end_ifndef

begin_define
define|#
directive|define
name|VMS
value|0
end_define

begin_comment
comment|/* VAX/VMS */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Minix has no predefines */
end_comment

begin_if
if|#
directive|if
operator|!
name|BSD
operator|&&
operator|!
name|UNIXV
operator|&&
operator|!
name|UNIX7
operator|&&
operator|!
name|MSDOS
operator|&&
operator|!
name|TOS
operator|&&
operator|!
name|AMIGA
operator|&&
operator|!
name|OSK
operator|&&
operator|!
name|COHERENT
operator|&&
operator|!
name|VMS
end_if

begin_define
define|#
directive|define
name|MINIX
value|1
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|MINIX
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* generic combination of Unices */
end_comment

begin_if
if|#
directive|if
name|UNIXV
operator|||
name|UNIX7
operator|||
name|BSD
operator|||
name|MINIX
operator|||
name|COHERENT
end_if

begin_define
define|#
directive|define
name|ANY_UNIX
value|1
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|ANY_UNIX
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|TINYSTACK
end_ifndef

begin_define
define|#
directive|define
name|TINYSTACK
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*************************** compilers **************************************/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|AZTEC_C
end_ifndef

begin_define
define|#
directive|define
name|AZTEC_C
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|MICROSOFT
end_ifndef

begin_define
define|#
directive|define
name|MICROSOFT
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|TURBOC
end_ifndef

begin_define
define|#
directive|define
name|TURBOC
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Should we use "new style" ANSI C prototypes? */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__STDC__
end_ifdef

begin_define
define|#
directive|define
name|NEWSTYLE
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|__cplusplus
end_ifdef

begin_define
define|#
directive|define
name|NEWSTYLE
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|NEWSTYLE
end_ifndef

begin_define
define|#
directive|define
name|NEWSTYLE
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|NEWSTYLE
end_if

begin_define
define|#
directive|define
name|P_
parameter_list|(
name|s
parameter_list|)
value|s
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|P_
parameter_list|(
name|s
parameter_list|)
value|()
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/******************************* Credit ************************************/
end_comment

begin_if
if|#
directive|if
name|MSDOS
end_if

begin_define
define|#
directive|define
name|CREDIT
value|"Ported to MS-DOS by Guntram Blohm& Martin Patzel"
end_define

begin_if
if|#
directive|if
name|RAINBOW
end_if

begin_define
define|#
directive|define
name|CREDIT2
value|"Rainbow support added by Willett Kempton"
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
name|AMIGA
end_if

begin_define
define|#
directive|define
name|CREDIT
value|"Ported to AmigaDOS 2.04 by Mike Rieser& Dale Rahn"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|TOS
end_if

begin_define
define|#
directive|define
name|CREDIT
value|"Ported to Atari/TOS by Guntram Blohm& Martin Patzel"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|OSK
end_if

begin_define
define|#
directive|define
name|CREDIT
value|"Ported to Microware OS9/68k by Peter Reinig"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|COHERENT
end_if

begin_define
define|#
directive|define
name|CREDIT
value|"Ported to Coherent by Esa Ahola"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|VMS
end_if

begin_define
define|#
directive|define
name|CREDIT
value|"Ported to VAX/VMS by John Campbell"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*************************** functions depending on OS *********************/
end_comment

begin_comment
comment|/* There are two terminal-related functions that we need: ttyread() and  * ttywrite().  The ttyread() function implements read-with-timeout and is  * a true function on all systems.  The ttywrite() function is almost always  * just a macro...  */
end_comment

begin_if
if|#
directive|if
operator|!
name|TOS
operator|&&
operator|!
name|AMIGA
end_if

begin_define
define|#
directive|define
name|ttywrite
parameter_list|(
name|buf
parameter_list|,
name|len
parameter_list|)
value|write(1, buf, (unsigned)(len))
end_define

begin_comment
comment|/* raw write */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* The strchr() function is an official standard now, so everybody has it  * except Unix version 7 (which is old) and BSD Unix (which is academic).  * Those guys use something called index() to do the same thing.  */
end_comment

begin_if
if|#
directive|if
name|BSD
operator|||
name|UNIX7
operator|||
name|OSK
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

begin_if
if|#
directive|if
operator|!
name|NEWSTYLE
end_if

begin_function_decl
specifier|extern
name|char
modifier|*
name|strchr
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* BSD uses bcopy() instead of memcpy() */
end_comment

begin_if
if|#
directive|if
name|BSD
end_if

begin_define
define|#
directive|define
name|memcpy
parameter_list|(
name|dest
parameter_list|,
name|src
parameter_list|,
name|siz
parameter_list|)
value|bcopy(src, dest, siz)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* BSD uses getwd() instead of getcwd().  The arguments are a little different,  * but we'll ignore that and hope for the best; adding arguments to the macro  * would mess up an "extern" declaration of the function.  *  * Also, the Coherent-286 uses getwd(), but Coherent-386 uses getcwd()  */
end_comment

begin_if
if|#
directive|if
name|BSD
end_if

begin_ifndef
ifndef|#
directive|ifndef
name|__386BSD__
end_ifndef

begin_define
define|#
directive|define
name|getcwd
value|getwd
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
name|COH_286
end_if

begin_define
define|#
directive|define
name|getcwd
value|getwd
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
specifier|extern
name|char
modifier|*
name|getcwd
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* text versa binary mode for read/write */
end_comment

begin_if
if|#
directive|if
operator|!
name|TOS
end_if

begin_define
define|#
directive|define
name|tread
parameter_list|(
name|fd
parameter_list|,
name|buf
parameter_list|,
name|n
parameter_list|)
value|read(fd,buf,(unsigned)(n))
end_define

begin_define
define|#
directive|define
name|twrite
parameter_list|(
name|fd
parameter_list|,
name|buf
parameter_list|,
name|n
parameter_list|)
value|write(fd,buf,(unsigned)(n))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/**************************** Compiler quirks *********************************/
end_comment

begin_comment
comment|/* the UNIX version 7 and (some) TOS compilers, don't allow "void" */
end_comment

begin_if
if|#
directive|if
name|UNIX7
operator|||
name|TOS
end_if

begin_define
define|#
directive|define
name|void
value|int
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* as far as I know, all compilers except version 7 support unsigned char */
end_comment

begin_comment
comment|/* NEWFLASH: the Minix-ST compiler has subtle problems with unsigned char */
end_comment

begin_if
if|#
directive|if
name|UNIX7
operator|||
name|MINIX
end_if

begin_define
define|#
directive|define
name|UCHAR
parameter_list|(
name|c
parameter_list|)
value|((c)& 0xff)
end_define

begin_define
define|#
directive|define
name|uchar
value|char
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|UCHAR
parameter_list|(
name|c
parameter_list|)
value|((unsigned char)(c))
end_define

begin_define
define|#
directive|define
name|uchar
value|unsigned char
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Some compilers prefer to have malloc declared as returning a (void *) */
end_comment

begin_comment
comment|/* ANSI, on the other hand, needs the arguments to free() to be cast */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__STDC__
end_ifndef

begin_if
if|#
directive|if
name|BSD
operator|||
name|AMIGA
operator|||
name|MINIX
end_if

begin_function_decl
specifier|extern
name|void
modifier|*
name|malloc
parameter_list|()
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|_free_
parameter_list|(
name|ptr
parameter_list|)
value|free((void *)ptr)
end_define

begin_else
else|#
directive|else
end_else

begin_function_decl
specifier|extern
name|char
modifier|*
name|malloc
parameter_list|()
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|_free_
parameter_list|(
name|ptr
parameter_list|)
value|free((char *)ptr)
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
name|_free_
parameter_list|(
name|ptr
parameter_list|)
value|free((void *)ptr)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __STDC__ */
end_comment

begin_comment
comment|/* everybody but Amiga wants lseek declared here */
end_comment

begin_if
if|#
directive|if
operator|!
name|AMIGA
end_if

begin_function_decl
specifier|extern
name|long
name|lseek
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ANSI C has getenv() declared in stdlib.h, which we've already included.  * Other compilers will need it declared here, though.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__STDC__
end_ifndef

begin_function_decl
specifier|extern
name|char
modifier|*
name|getenv
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Signal handler functions used to return an int value, which was ignored.  * On newer systems, signal handlers are void functions.  Here, we try to  * guess the proper return type for this system.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__STDC__
end_ifdef

begin_define
define|#
directive|define
name|SIGTYPE
value|void
end_define

begin_else
else|#
directive|else
end_else

begin_if
if|#
directive|if
name|MSDOS
end_if

begin_define
define|#
directive|define
name|SIGTYPE
value|void
end_define

begin_else
else|#
directive|else
end_else

begin_if
if|#
directive|if
name|UNIXV
end_if

begin_define
define|#
directive|define
name|SIGTYPE
value|void
end_define

begin_comment
comment|/* Note: This is wrong for SCO Xenix. */
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

begin_ifndef
ifndef|#
directive|ifndef
name|SIGTYPE
end_ifndef

begin_define
define|#
directive|define
name|SIGTYPE
value|int
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/******************* Names of files and environment vars **********************/
end_comment

begin_if
if|#
directive|if
name|ANY_UNIX
end_if

begin_ifndef
ifndef|#
directive|ifndef
name|TMPDIR
end_ifndef

begin_if
if|#
directive|if
name|MINIX
end_if

begin_define
define|#
directive|define
name|TMPDIR
value|"/usr/tmp"
end_define

begin_comment
comment|/* Keep elvis' temp files off RAM disk! */
end_comment

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|TMPDIR
value|"/var/tmp"
end_define

begin_comment
comment|/* directory where temp files live */
end_comment

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
name|PRSVDIR
end_ifndef

begin_define
define|#
directive|define
name|PRSVDIR
value|"/var/preserve"
end_define

begin_comment
comment|/* directory where preserved file live */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|PRSVINDEX
end_ifndef

begin_define
define|#
directive|define
name|PRSVINDEX
value|"/var/preserve/Index"
end_define

begin_comment
comment|/* index of files in PRSVDIR */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|EXRC
end_ifndef

begin_define
define|#
directive|define
name|EXRC
value|".exrc"
end_define

begin_comment
comment|/* init file in current directory */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|SCRATCHOUT
value|"%s/soXXXXXX"
end_define

begin_comment
comment|/* temp file used as input to filter */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SHELL
end_ifndef

begin_define
define|#
directive|define
name|SHELL
value|"/bin/sh"
end_define

begin_comment
comment|/* default shell */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|COHERENT
end_if

begin_ifndef
ifndef|#
directive|ifndef
name|REDIRECT
end_ifndef

begin_define
define|#
directive|define
name|REDIRECT
value|">"
end_define

begin_comment
comment|/* Coherent CC writes errors to stdout */
end_comment

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
name|gethome
parameter_list|(
name|x
parameter_list|)
value|getenv("HOME")
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|AMIGA
end_if

begin_comment
comment|/* Specify AMIGA environment */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|CC_COMMAND
end_ifndef

begin_define
define|#
directive|define
name|CC_COMMAND
value|"cc"
end_define

begin_comment
comment|/* generic C compiler */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|COLON
end_ifndef

begin_define
define|#
directive|define
name|COLON
value|':'
end_define

begin_comment
comment|/* Amiga files can also end in `:' */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|SYSEXRC
end_ifndef

begin_define
define|#
directive|define
name|SYSEXRC
value|"S:" EXRC
end_define

begin_comment
comment|/* name of ".exrc" file in system dir */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|MAXRCLEN
end_ifndef

begin_define
define|#
directive|define
name|MAXRCLEN
value|2048
end_define

begin_comment
comment|/* max size of a .exrc file */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|NBUFS
end_ifndef

begin_define
define|#
directive|define
name|NBUFS
value|10
end_define

begin_comment
comment|/* must be at least 3 -- more is better */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|NEEDSYNC
end_ifndef

begin_define
define|#
directive|define
name|NEEDSYNC
value|TRUE
end_define

begin_comment
comment|/* assume ":se sync" by default */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|PRSVDIR
end_ifndef

begin_define
define|#
directive|define
name|PRSVDIR
value|"Elvis:"
end_define

begin_comment
comment|/* directory where preserved file live */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|PRSVINDEX
end_ifndef

begin_define
define|#
directive|define
name|PRSVINDEX
value|"Elvis:Index"
end_define

begin_comment
comment|/* index of files in PRSVDIR */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|REDIRECT
end_ifndef

begin_define
define|#
directive|define
name|REDIRECT
value|">"
end_define

begin_comment
comment|/* Amiga writes errors to stdout */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|SCRATCHIN
end_ifndef

begin_define
define|#
directive|define
name|SCRATCHIN
value|"%sSIXXXXXX"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|SCRATCHOUT
end_ifndef

begin_define
define|#
directive|define
name|SCRATCHOUT
value|"%sSOXXXXXX"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|SHELL
end_ifndef

begin_define
define|#
directive|define
name|SHELL
value|"newshell"
end_define

begin_comment
comment|/* default shell */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|TERMTYPE
end_ifndef

begin_define
define|#
directive|define
name|TERMTYPE
value|"amiga"
end_define

begin_comment
comment|/* default termtype */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|TMPDIR
end_ifndef

begin_comment
comment|/* for AMIGA should end in `:' or `/' */
end_comment

begin_define
define|#
directive|define
name|TMPDIR
value|"T:"
end_define

begin_comment
comment|/* directory where temp files live */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|TMPNAME
end_ifndef

begin_define
define|#
directive|define
name|TMPNAME
value|"%selv_%x.%x"
end_define

begin_comment
comment|/* format of names for temp files */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|gethome
parameter_list|(
name|x
parameter_list|)
value|getenv("HOME")
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|MSDOS
operator|||
name|TOS
end_if

begin_comment
comment|/* do not change TMPNAME and SCRATCH*: they MUST begin with '%s\\'! */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|TMPDIR
end_ifndef

begin_define
define|#
directive|define
name|TMPDIR
value|"C:\\tmp"
end_define

begin_comment
comment|/* directory where temp files live */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|PRSVDIR
end_ifndef

begin_define
define|#
directive|define
name|PRSVDIR
value|"C:\\preserve"
end_define

begin_comment
comment|/* directory where preserved file live */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|PRSVINDEX
end_ifndef

begin_define
define|#
directive|define
name|PRSVINDEX
value|"C:\\preserve\\Index"
end_define

begin_comment
comment|/* index of files in PRSVDIR */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|TMPNAME
value|"%s\\elv_%x.%x"
end_define

begin_comment
comment|/* temp file */
end_comment

begin_if
if|#
directive|if
name|MSDOS
end_if

begin_if
if|#
directive|if
name|MICROSOFT
end_if

begin_define
define|#
directive|define
name|CC_COMMAND
value|"cl -c"
end_define

begin_comment
comment|/* C compiler */
end_comment

begin_else
else|#
directive|else
end_else

begin_if
if|#
directive|if
name|__BORLANDC__
end_if

begin_comment
comment|/* Borland C */
end_comment

begin_define
define|#
directive|define
name|CC_COMMAND
value|"bcc"
end_define

begin_comment
comment|/* C compiler */
end_comment

begin_else
else|#
directive|else
end_else

begin_if
if|#
directive|if
name|TURBOC
end_if

begin_comment
comment|/* Turbo C */
end_comment

begin_define
define|#
directive|define
name|CC_COMMAND
value|"tcc"
end_define

begin_comment
comment|/* C compiler */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* TURBOC */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* BORLANDC */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* MICROSOFT */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* MSDOS */
end_comment

begin_define
define|#
directive|define
name|SCRATCHIN
value|"%s\\siXXXXXX"
end_define

begin_comment
comment|/* DOS ONLY - output of filter program */
end_comment

begin_define
define|#
directive|define
name|SCRATCHOUT
value|"%s\\soXXXXXX"
end_define

begin_comment
comment|/* temp file used as input to filter */
end_comment

begin_define
define|#
directive|define
name|SLASH
value|'\\'
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|SHELL
end_ifndef

begin_if
if|#
directive|if
name|TOS
end_if

begin_define
define|#
directive|define
name|SHELL
value|"shell.ttp"
end_define

begin_comment
comment|/* default shell */
end_comment

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|SHELL
value|"command.com"
end_define

begin_comment
comment|/* default shell */
end_comment

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
name|NEEDSYNC
value|TRUE
end_define

begin_comment
comment|/* assume ":se sync" by default */
end_comment

begin_if
if|#
directive|if
name|TOS
operator|&&
name|__GNUC__
end_if

begin_comment
comment|/* probably on other systems, too */
end_comment

begin_define
define|#
directive|define
name|REDIRECT
value|"2>"
end_define

begin_comment
comment|/* GNUC reports on 2, others on 1 */
end_comment

begin_define
define|#
directive|define
name|CC_COMMAND
value|"gcc -c"
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|REDIRECT
value|">"
end_define

begin_comment
comment|/* shell's redirection of stderr */
end_comment

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
name|VMS
end_if

begin_comment
comment|/* do not change TMPNAME, and SCRATCH*: they MUST begin with '%s\\'! */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|TMPDIR
end_ifndef

begin_define
define|#
directive|define
name|TMPDIR
value|"sys$scratch:"
end_define

begin_comment
comment|/* directory where temp files live */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|TMPNAME
value|"%selv_%x.%x;1"
end_define

begin_comment
comment|/* temp file */
end_comment

begin_define
define|#
directive|define
name|SCRATCHIN
value|"%ssiXXXXXX"
end_define

begin_comment
comment|/* DOS ONLY - output of filter program */
end_comment

begin_define
define|#
directive|define
name|SCRATCHOUT
value|"%ssoXXXXXX"
end_define

begin_comment
comment|/* temp file used as input to filter */
end_comment

begin_define
define|#
directive|define
name|SLASH
value|'\:'
end_define

begin_comment
comment|/* Worry point... jdc */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SHELL
end_ifndef

begin_define
define|#
directive|define
name|SHELL
value|""
end_define

begin_comment
comment|/* default shell */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|REDIRECT
value|">"
end_define

begin_comment
comment|/* shell's redirection of stderr */
end_comment

begin_define
define|#
directive|define
name|tread
parameter_list|(
name|fd
parameter_list|,
name|buf
parameter_list|,
name|n
parameter_list|)
value|vms_read(fd,buf,(unsigned)(n))
end_define

begin_define
define|#
directive|define
name|close
value|vms_close
end_define

begin_define
define|#
directive|define
name|lseek
value|vms_lseek
end_define

begin_define
define|#
directive|define
name|unlink
value|vms_delete
end_define

begin_define
define|#
directive|define
name|delete
value|__delete
end_define

begin_comment
comment|/* local routine conflicts w/VMS rtl routine. */
end_comment

begin_define
define|#
directive|define
name|rpipe
value|vms_rpipe
end_define

begin_define
define|#
directive|define
name|rpclose
value|vms_rpclose
end_define

begin_define
define|#
directive|define
name|ttyread
value|vms_ttyread
end_define

begin_define
define|#
directive|define
name|gethome
parameter_list|(
name|x
parameter_list|)
value|getenv("HOME")
end_define

begin_comment
comment|/* There is no sync() on vms */
end_comment

begin_define
define|#
directive|define
name|sync
parameter_list|()
end_define

begin_comment
comment|/* jdc -- seems VMS external symbols are case insensitive */
end_comment

begin_define
define|#
directive|define
name|m_fWord
value|m_fw_ord
end_define

begin_define
define|#
directive|define
name|m_bWord
value|m_bw_ord
end_define

begin_define
define|#
directive|define
name|m_eWord
value|m_ew_ord
end_define

begin_define
define|#
directive|define
name|m_Nsrch
value|m_n_srch
end_define

begin_define
define|#
directive|define
name|m_Fch
value|m_f_ch
end_define

begin_define
define|#
directive|define
name|m_Tch
value|m_t_ch
end_define

begin_define
define|#
directive|define
name|v_Xchar
value|v_x_char
end_define

begin_comment
comment|/* jdc -- also, braindead vms curses always found by linker. */
end_comment

begin_define
define|#
directive|define
name|LINES
value|elvis_LINES
end_define

begin_define
define|#
directive|define
name|COLS
value|elvis_COLS
end_define

begin_define
define|#
directive|define
name|curscr
value|elvis_curscr
end_define

begin_define
define|#
directive|define
name|stdscr
value|elvis_stdscr
end_define

begin_define
define|#
directive|define
name|initscr
value|elvis_initscr
end_define

begin_define
define|#
directive|define
name|endwin
value|elvis_endwin
end_define

begin_define
define|#
directive|define
name|wrefresh
value|elvis_wrefresh
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|OSK
end_if

begin_ifndef
ifndef|#
directive|ifndef
name|TMPDIR
end_ifndef

begin_define
define|#
directive|define
name|TMPDIR
value|"/dd/tmp"
end_define

begin_comment
comment|/* directory where temp files live */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|PRSVDIR
end_ifndef

begin_define
define|#
directive|define
name|PRSVDIR
value|"/dd/usr/preserve"
end_define

begin_comment
comment|/* directory where preserved file live */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|PRSVINDEX
end_ifndef

begin_define
define|#
directive|define
name|PRSVINDEX
value|"/dd/usr/preserve/Index"
end_define

begin_comment
comment|/* index of files in PRSVDIR */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|CC_COMMAND
end_ifndef

begin_define
define|#
directive|define
name|CC_COMMAND
value|"cc -r"
end_define

begin_comment
comment|/* name of the compiler */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|EXRC
end_ifndef

begin_define
define|#
directive|define
name|EXRC
value|".exrc"
end_define

begin_comment
comment|/* init file in current directory */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|SCRATCHOUT
value|"%s/soXXXXXX"
end_define

begin_comment
comment|/* temp file used as input to filter */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SHELL
end_ifndef

begin_define
define|#
directive|define
name|SHELL
value|"shell"
end_define

begin_comment
comment|/* default shell */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|FILEPERMS
value|(S_IREAD|S_IWRITE)
end_define

begin_comment
comment|/* file permissions used for creat() */
end_comment

begin_define
define|#
directive|define
name|REDIRECT
value|">>-"
end_define

begin_comment
comment|/* shell's redirection of stderr */
end_comment

begin_define
define|#
directive|define
name|sync
parameter_list|()
end_define

begin_comment
comment|/* OS9 doesn't need a sync() */
end_comment

begin_define
define|#
directive|define
name|gethome
parameter_list|(
name|x
parameter_list|)
value|getenv("HOME")
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|TAGS
end_ifndef

begin_define
define|#
directive|define
name|TAGS
value|"tags"
end_define

begin_comment
comment|/* name of the tags file */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|TMPNAME
end_ifndef

begin_define
define|#
directive|define
name|TMPNAME
value|"%s/elv_%x.%x"
end_define

begin_comment
comment|/* format of names for temp files */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|EXINIT
end_ifndef

begin_define
define|#
directive|define
name|EXINIT
value|"EXINIT"
end_define

begin_comment
comment|/* name of EXINIT environment variable */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|EXRC
end_ifndef

begin_define
define|#
directive|define
name|EXRC
value|"elvis.rc"
end_define

begin_comment
comment|/* name of ".exrc" file in current dir */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|HMEXRC
end_ifndef

begin_define
define|#
directive|define
name|HMEXRC
value|EXRC
end_define

begin_comment
comment|/* name of ".exrc" file in home dir */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|KEYWORDPRG
end_ifndef

begin_define
define|#
directive|define
name|KEYWORDPRG
value|"ref"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|SCRATCHOUT
end_ifndef

begin_define
define|#
directive|define
name|SCRATCHIN
value|"%s/SIXXXXXX"
end_define

begin_define
define|#
directive|define
name|SCRATCHOUT
value|"%s/SOXXXXXX"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ERRLIST
end_ifndef

begin_define
define|#
directive|define
name|ERRLIST
value|"errs"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|SLASH
end_ifndef

begin_define
define|#
directive|define
name|SLASH
value|'/'
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|SHELL
end_ifndef

begin_define
define|#
directive|define
name|SHELL
value|"shell"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|REG
end_ifndef

begin_define
define|#
directive|define
name|REG
value|register
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|NEEDSYNC
end_ifndef

begin_define
define|#
directive|define
name|NEEDSYNC
value|FALSE
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|FILEPERMS
end_ifndef

begin_define
define|#
directive|define
name|FILEPERMS
value|0666
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|PRESERVE
end_ifndef

begin_define
define|#
directive|define
name|PRESERVE
value|"/usr/libexec/elvispreserve"
end_define

begin_comment
comment|/* name of the "preserve" program */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|CC_COMMAND
end_ifndef

begin_define
define|#
directive|define
name|CC_COMMAND
value|"cc -c"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|MAKE_COMMAND
end_ifndef

begin_define
define|#
directive|define
name|MAKE_COMMAND
value|"make"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|REDIRECT
end_ifndef

begin_define
define|#
directive|define
name|REDIRECT
value|"2>"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|BLKSIZE
end_ifndef

begin_ifdef
ifdef|#
directive|ifdef
name|CRUNCH
end_ifdef

begin_define
define|#
directive|define
name|BLKSIZE
value|1024
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|BLKSIZE
value|2048
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
name|KEYBUFSIZE
end_ifndef

begin_define
define|#
directive|define
name|KEYBUFSIZE
value|1000
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|MAILER
end_ifndef

begin_define
define|#
directive|define
name|MAILER
value|"mail"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|gethome
end_ifndef

begin_function_decl
specifier|extern
name|char
modifier|*
name|gethome
parameter_list|()
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

begin_comment
comment|/* ndef _CONFIG_H */
end_comment

end_unit

