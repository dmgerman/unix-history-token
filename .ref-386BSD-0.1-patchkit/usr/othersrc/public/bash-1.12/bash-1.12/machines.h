begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* machines.h --    Included file in the makefile that gets run through Cpp.  This file    tells which machines have what features based on the unique machine    identifier present in Cpp. */
end_comment

begin_comment
comment|/* **************************************************************** */
end_comment

begin_comment
comment|/*                                                                  */
end_comment

begin_comment
comment|/*                Global Assumptions (true for most systems).       */
end_comment

begin_comment
comment|/*                                                                  */
end_comment

begin_comment
comment|/* **************************************************************** */
end_comment

begin_comment
comment|/* We make some global assumptions here.  This can be #undef'ed in    various machine specific entries. */
end_comment

begin_comment
comment|/* If this file is being processed with Gcc, then the user has Gcc. */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__GNUC__
argument_list|)
end_if

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|HAVE_GCC
argument_list|)
end_if

begin_define
define|#
directive|define
name|HAVE_GCC
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HAVE_GCC */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __GNUC__ */
end_comment

begin_comment
comment|/* Assume that all machines have the getwd () system call.  We unset it    for USG systems. */
end_comment

begin_define
define|#
directive|define
name|HAVE_GETWD
end_define

begin_comment
comment|/* Assume that all systems have a working getcwd () call.  We unset it for    ISC systems. */
end_comment

begin_define
define|#
directive|define
name|HAVE_GETCWD
end_define

begin_comment
comment|/* Most (but not all) systems have a good, working version of dup2 ().    For systems that don't have the call (HP/UX), and for systems    that don't set the open-on-exec flag for the dup'ed file descriptors,    (Sequents running Dynix, Ultrix), #undef HAVE_DUP2 in the machine    description. */
end_comment

begin_define
define|#
directive|define
name|HAVE_DUP2
end_define

begin_comment
comment|/* Every machine that has Gcc has alloca as a builtin in Gcc.  If you are    compiling Bash without Gcc, then you must have alloca in a library,    in your C compiler, or be able to assemble or compile the alloca source    that we ship with Bash. */
end_comment

begin_define
define|#
directive|define
name|HAVE_ALLOCA
end_define

begin_comment
comment|/* We like most machines to use the GNU Malloc routines supplied in the    source code because they provide high quality error checking.  On    some machines, our malloc () cannot be used (because of library    conflicts, for example), and for those, you should specifically    #undef USE_GNU_MALLOC in the machine description. */
end_comment

begin_define
define|#
directive|define
name|USE_GNU_MALLOC
end_define

begin_comment
comment|/* **************************************************************** */
end_comment

begin_comment
comment|/*								    */
end_comment

begin_comment
comment|/*			Sun Microsystems Machines	      	    */
end_comment

begin_comment
comment|/*								    */
end_comment

begin_comment
comment|/* **************************************************************** */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|sun
argument_list|)
end_if

begin_comment
comment|/* We aren't currently using GNU Malloc on Suns because of a bug in Sun's    YP which bites us when Sun free ()'s an already free ()'ed address.    When Sun fixes their YP, we can start using our winning malloc again. */
end_comment

begin_undef
undef|#
directive|undef
name|USE_GNU_MALLOC
end_undef

begin_comment
comment|/* Most Sun systems have signal handler functions that are void. */
end_comment

begin_define
define|#
directive|define
name|VOID_SIGHANDLER
end_define

begin_if
if|#
directive|if
name|defined
argument_list|(
name|mc68010
argument_list|)
end_if

begin_define
define|#
directive|define
name|sun2
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
name|mc68020
argument_list|)
end_if

begin_define
define|#
directive|define
name|sun3
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
name|sparc
argument_list|)
end_if

begin_define
define|#
directive|define
name|sun4
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
name|i386
argument_list|)
end_if

begin_define
define|#
directive|define
name|Sun386i
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
name|HAVE_SHARED_LIBS
argument_list|)
end_if

begin_define
define|#
directive|define
name|M_OS
value|SunOS4
end_define

begin_define
define|#
directive|define
name|SunOS4_SYSDEP_CFLAGS
value|-DBSD_GETPGRP
end_define

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
name|sparc
argument_list|)
end_if

begin_undef
undef|#
directive|undef
name|VOID_SIGHANDLER
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|M_OS
value|SunOS3
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
comment|/* sun */
end_comment

begin_comment
comment|/* ************************ */
end_comment

begin_comment
comment|/*			    */
end_comment

begin_comment
comment|/*	    Sun2	    */
end_comment

begin_comment
comment|/*			    */
end_comment

begin_comment
comment|/* ************************ */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|sun2
argument_list|)
end_if

begin_define
define|#
directive|define
name|M_MACHINE
value|"sun2"
end_define

begin_define
define|#
directive|define
name|HAVE_SYS_SIGLIST
end_define

begin_define
define|#
directive|define
name|HAVE_SETLINEBUF
end_define

begin_define
define|#
directive|define
name|HAVE_VFPRINTF
end_define

begin_define
define|#
directive|define
name|HAVE_GETGROUPS
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* sun2 */
end_comment

begin_comment
comment|/* ************************ */
end_comment

begin_comment
comment|/*			    */
end_comment

begin_comment
comment|/*	    Sun3	    */
end_comment

begin_comment
comment|/*			    */
end_comment

begin_comment
comment|/* ************************ */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|sun3
argument_list|)
end_if

begin_define
define|#
directive|define
name|M_MACHINE
value|"sun3"
end_define

begin_if
if|#
directive|if
name|defined
argument_list|(
name|SunOS4_SYSDEP_CFLAGS
argument_list|)
end_if

begin_define
define|#
directive|define
name|SYSDEP_CFLAGS
value|SunOS4_SYSDEP_CFLAGS
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* SunOS4 */
end_comment

begin_define
define|#
directive|define
name|HAVE_SYS_SIGLIST
end_define

begin_define
define|#
directive|define
name|HAVE_SETLINEBUF
end_define

begin_define
define|#
directive|define
name|HAVE_VFPRINTF
end_define

begin_define
define|#
directive|define
name|HAVE_GETGROUPS
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* sun3 */
end_comment

begin_comment
comment|/* ************************ */
end_comment

begin_comment
comment|/*			    */
end_comment

begin_comment
comment|/*	    Sparc	    */
end_comment

begin_comment
comment|/*			    */
end_comment

begin_comment
comment|/* ************************ */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|sun4
argument_list|)
end_if

begin_define
define|#
directive|define
name|M_MACHINE
value|"sparc"
end_define

begin_if
if|#
directive|if
name|defined
argument_list|(
name|SunOS4_SYSDEP_CFLAGS
argument_list|)
end_if

begin_define
define|#
directive|define
name|SYSDEP_CFLAGS
value|SunOS4_SYSDEP_CFLAGS
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* SunOS4 */
end_comment

begin_define
define|#
directive|define
name|HAVE_SYS_SIGLIST
end_define

begin_define
define|#
directive|define
name|HAVE_SETLINEBUF
end_define

begin_define
define|#
directive|define
name|HAVE_VFPRINTF
end_define

begin_define
define|#
directive|define
name|HAVE_GETGROUPS
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* sparc */
end_comment

begin_comment
comment|/* ************************ */
end_comment

begin_comment
comment|/*			    */
end_comment

begin_comment
comment|/*	    Sun386i	    */
end_comment

begin_comment
comment|/*			    */
end_comment

begin_comment
comment|/* ************************ */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|Sun386i
argument_list|)
end_if

begin_define
define|#
directive|define
name|done386
end_define

begin_define
define|#
directive|define
name|M_MACHINE
value|"Sun386i"
end_define

begin_if
if|#
directive|if
name|defined
argument_list|(
name|SunOS4_SYSDEP_CFLAGS
argument_list|)
end_if

begin_define
define|#
directive|define
name|SYSDEP_CFLAGS
value|SunOS4_SYSDEP_CFLAGS
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* SunOS4 */
end_comment

begin_define
define|#
directive|define
name|HAVE_SYS_SIGLIST
end_define

begin_define
define|#
directive|define
name|HAVE_SETLINEBUF
end_define

begin_define
define|#
directive|define
name|HAVE_VFPRINTF
end_define

begin_define
define|#
directive|define
name|HAVE_GETGROUPS
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Sun386i */
end_comment

begin_comment
comment|/* **************************************************************** */
end_comment

begin_comment
comment|/*								    */
end_comment

begin_comment
comment|/*			DEC Machines (vax, decstations)   	    */
end_comment

begin_comment
comment|/*								    */
end_comment

begin_comment
comment|/* **************************************************************** */
end_comment

begin_comment
comment|/* ************************ */
end_comment

begin_comment
comment|/*			    */
end_comment

begin_comment
comment|/*	    Ultrix	    */
end_comment

begin_comment
comment|/*			    */
end_comment

begin_comment
comment|/* ************************ */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|ultrix
argument_list|)
end_if

begin_if
if|#
directive|if
name|defined
argument_list|(
name|MIPSEL
argument_list|)
end_if

begin_undef
undef|#
directive|undef
name|HAVE_ALLOCA_H
end_undef

begin_define
define|#
directive|define
name|M_MACHINE
value|"MIPSEL"
end_define

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|HAVE_GCC
argument_list|)
end_if

begin_define
define|#
directive|define
name|MIPS_CFLAGS
value|-Wf,-XNl3072
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* !MIPSEL */
end_comment

begin_define
define|#
directive|define
name|M_MACHINE
value|"vax"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* MIPSEL */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|MIPS_CFLAGS
argument_list|)
end_if

begin_define
define|#
directive|define
name|SYSDEP_CFLAGS
value|-DBSD_GETPGRP -DTERMIOS_MISSING MIPS_CFLAGS
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|SYSDEP_CFLAGS
value|-DBSD_GETPGRP -DTERMIOS_MISSING
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|M_OS
value|Ultrix
end_define

begin_define
define|#
directive|define
name|VOID_SIGHANDLER
end_define

begin_define
define|#
directive|define
name|HAVE_SYS_SIGLIST
end_define

begin_define
define|#
directive|define
name|HAVE_SETLINEBUF
end_define

begin_define
define|#
directive|define
name|HAVE_VFPRINTF
end_define

begin_define
define|#
directive|define
name|HAVE_GETGROUPS
end_define

begin_undef
undef|#
directive|undef
name|HAVE_DUP2
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ultrix */
end_comment

begin_comment
comment|/* ************************ */
end_comment

begin_comment
comment|/*			    */
end_comment

begin_comment
comment|/*	VAX 4.3 BSD	    */
end_comment

begin_comment
comment|/*			    */
end_comment

begin_comment
comment|/* ************************ */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|vax
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|ultrix
argument_list|)
end_if

begin_define
define|#
directive|define
name|M_MACHINE
value|"vax"
end_define

begin_define
define|#
directive|define
name|M_OS
value|Bsd
end_define

begin_define
define|#
directive|define
name|HAVE_SETLINEBUF
end_define

begin_define
define|#
directive|define
name|HAVE_SYS_SIGLIST
end_define

begin_define
define|#
directive|define
name|HAVE_GETGROUPS
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* vax&& !ultrix */
end_comment

begin_comment
comment|/* **************************************** */
end_comment

begin_comment
comment|/*					    */
end_comment

begin_comment
comment|/*		SGI Iris/IRIX	    	    */
end_comment

begin_comment
comment|/*					    */
end_comment

begin_comment
comment|/* **************************************** */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|sgi
argument_list|)
end_if

begin_if
if|#
directive|if
name|defined
argument_list|(
name|Irix3
argument_list|)
end_if

begin_define
define|#
directive|define
name|M_OS
value|"Irix3"
end_define

begin_define
define|#
directive|define
name|MIPS_CFLAGS
value|-real_frameptr -Wf,-XNl3072
end_define

begin_undef
undef|#
directive|undef
name|HAVE_ALLOCA
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Irix3 */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|Irix4
argument_list|)
end_if

begin_define
define|#
directive|define
name|M_OS
value|"Irix4"
end_define

begin_define
define|#
directive|define
name|MIPS_CFLAGS
value|-Wf,-XNl3072
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Irix4 */
end_comment

begin_define
define|#
directive|define
name|M_MACHINE
value|"sgi"
end_define

begin_define
define|#
directive|define
name|HAVE_GETGROUPS
end_define

begin_define
define|#
directive|define
name|VOID_SIGHANDLER
end_define

begin_define
define|#
directive|define
name|HAVE_SYS_SIGLIST
end_define

begin_define
define|#
directive|define
name|HAVE_SETLINEBUF
end_define

begin_define
define|#
directive|define
name|HAVE_VFPRINTF
end_define

begin_define
define|#
directive|define
name|REQUIRED_LIBRARIES
value|-lsun
end_define

begin_if
if|#
directive|if
name|defined
argument_list|(
name|HAVE_GCC
argument_list|)
operator|||
operator|!
name|defined
argument_list|(
name|mips
argument_list|)
end_if

begin_undef
undef|#
directive|undef
name|MIPS_CFLAGS
end_undef

begin_define
define|#
directive|define
name|MIPS_CFLAGS
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HAVE_GCC || !mips */
end_comment

begin_define
define|#
directive|define
name|SYSDEP_CFLAGS
value|-DUSG -DPGRP_PIPE MIPS_CFLAGS
end_define

begin_undef
undef|#
directive|undef
name|HAVE_GETWD
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* sgi */
end_comment

begin_comment
comment|/* ************************ */
end_comment

begin_comment
comment|/*			    */
end_comment

begin_comment
comment|/*	    Sony	    */
end_comment

begin_comment
comment|/*			    */
end_comment

begin_comment
comment|/* ************************ */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|sony
argument_list|)
end_if

begin_if
if|#
directive|if
name|defined
argument_list|(
name|MIPSEB
argument_list|)
end_if

begin_define
define|#
directive|define
name|M_MACHINE
value|"MIPSEB"
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|M_MACHINE
value|"sony"
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
name|SYSTYPE_SYSV
argument_list|)
operator|||
name|defined
argument_list|(
name|USGr4
argument_list|)
end_if

begin_define
define|#
directive|define
name|M_OS
value|USG
end_define

begin_undef
undef|#
directive|undef
name|HAVE_GETWD
end_undef

begin_define
define|#
directive|define
name|HAVE_VFPRINTF
end_define

begin_define
define|#
directive|define
name|VOID_SIGHANDLER
end_define

begin_comment
comment|/* Alloca requires either Gcc or cc with -lucb. */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|HAVE_GCC
argument_list|)
end_if

begin_define
define|#
directive|define
name|EXTRA_LIB_SEARCH_PATH
value|/usr/ucblib
end_define

begin_define
define|#
directive|define
name|REQUIRED_LIBRARIES
value|-lc -lucb
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !HAVE_GCC */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|MIPSEB
argument_list|)
end_if

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|HAVE_GCC
argument_list|)
end_if

begin_define
define|#
directive|define
name|SYSDEP_CFLAGS
value|-Wf,-XNl3072 -DUSGr4
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|SYSDEP_CFLAGS
value|-DUSGr4
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HAVE_GCC */
end_comment

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|SYSDEP_CFLAGS
value|-DUSGr4
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* MIPSEB */
end_comment

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|M_OS
value|Bsd
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* SYSTYPE_SYSV */
end_comment

begin_define
define|#
directive|define
name|HAVE_SYS_SIGLIST
end_define

begin_define
define|#
directive|define
name|HAVE_SETLINEBUF
end_define

begin_define
define|#
directive|define
name|HAVE_GETGROUPS
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* sony */
end_comment

begin_comment
comment|/* ******************************** */
end_comment

begin_comment
comment|/*				    */
end_comment

begin_comment
comment|/*	   MIPS RISC/os		    */
end_comment

begin_comment
comment|/*				    */
end_comment

begin_comment
comment|/* ******************************** */
end_comment

begin_comment
comment|/* Notes on compiling with "make":     * Place /bsd43/bin in your PATH before /bin.    * Use `$(CC) -E' instead of `/lib/cpp' in Makefile. */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|mips
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|M_MACHINE
argument_list|)
end_if

begin_if
if|#
directive|if
name|defined
argument_list|(
name|MIPSEB
argument_list|)
end_if

begin_define
define|#
directive|define
name|M_MACHINE
value|"MIPSEB"
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
name|MIPSEL
argument_list|)
end_if

begin_define
define|#
directive|define
name|M_MACHINE
value|"MIPSEL"
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|M_MACHINE
value|"mips"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* MIPSEL */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* MIPSEB */
end_comment

begin_define
define|#
directive|define
name|M_OS
value|Bsd
end_define

begin_comment
comment|/* Special things for machines from MIPS Co. */
end_comment

begin_define
define|#
directive|define
name|mips_CFLAGS
value|-DOPENDIR_NOT_ROBUST -DPGRP_PIPE
end_define

begin_if
if|#
directive|if
name|defined
argument_list|(
name|HAVE_GCC
argument_list|)
end_if

begin_define
define|#
directive|define
name|SYSDEP_CFLAGS
value|mips_CFLAGS
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|SYSDEP_CFLAGS
value|-Wf,-XNl3072 -systype bsd43 mips_CFLAGS
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !HAVE_GCC */
end_comment

begin_define
define|#
directive|define
name|HAVE_SYS_SIGLIST
end_define

begin_define
define|#
directive|define
name|HAVE_SETLINEBUF
end_define

begin_define
define|#
directive|define
name|HAVE_VFPRINTF
end_define

begin_define
define|#
directive|define
name|HAVE_GETGROUPS
end_define

begin_comment
comment|/* This is actually present but unavailable in the BSD universe? */
end_comment

begin_undef
undef|#
directive|undef
name|HAVE_UNISTD_H
end_undef

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|HAVE_RESOURCE
argument_list|)
end_if

begin_define
define|#
directive|define
name|HAVE_RESOURCE
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Appears not to work correctly, so why use it? */
end_comment

begin_undef
undef|#
directive|undef
name|HAVE_WAIT_H
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* mips */
end_comment

begin_comment
comment|/* ************************ */
end_comment

begin_comment
comment|/*			    */
end_comment

begin_comment
comment|/*	  Pyramid	    */
end_comment

begin_comment
comment|/*			    */
end_comment

begin_comment
comment|/* ************************ */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|pyr
argument_list|)
end_if

begin_define
define|#
directive|define
name|M_MACHINE
value|"Pyramid"
end_define

begin_define
define|#
directive|define
name|M_OS
value|Bsd
end_define

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|HAVE_GCC
argument_list|)
end_if

begin_undef
undef|#
directive|undef
name|HAVE_ALLOCA
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HAVE_GCC */
end_comment

begin_define
define|#
directive|define
name|HAVE_SYS_SIGLIST
end_define

begin_define
define|#
directive|define
name|HAVE_SETLINEBUF
end_define

begin_comment
comment|/* #define HAVE_VFPRINTF */
end_comment

begin_define
define|#
directive|define
name|HAVE_GETGROUPS
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* pyr */
end_comment

begin_comment
comment|/* ************************ */
end_comment

begin_comment
comment|/*			    */
end_comment

begin_comment
comment|/*	    IBMRT	    */
end_comment

begin_comment
comment|/*			    */
end_comment

begin_comment
comment|/* ************************ */
end_comment

begin_comment
comment|/* Notes:  Compiling with pcc seems to work better than compiling with    the hc compiler.  I had problems when compiling with hc with alloca,    even though the -ma flag was defined.  (bfox) */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|ibm032
argument_list|)
end_if

begin_define
define|#
directive|define
name|M_MACHINE
value|"IBMRT"
end_define

begin_define
define|#
directive|define
name|M_OS
value|Bsd
end_define

begin_define
define|#
directive|define
name|HAVE_SYS_SIGLIST
end_define

begin_define
define|#
directive|define
name|HAVE_SETLINEBUF
end_define

begin_comment
comment|/* Some systems cannot find vfprintf at load time. */
end_comment

begin_comment
comment|/* #define HAVE_VFPRINTF */
end_comment

begin_comment
comment|/* Alloca requires either gcc or pcc with -ma in SYSDEP_CFLAGS. */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|HAVE_GCC
argument_list|)
end_if

begin_define
define|#
directive|define
name|SYSDEP_CFLAGS
value|-ma -U__STDC__
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|HAVE_GETGROUPS
end_define

begin_comment
comment|/* #define USE_GNU_TERMCAP */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ibm032 */
end_comment

begin_comment
comment|/* **************************************************************** */
end_comment

begin_comment
comment|/*								    */
end_comment

begin_comment
comment|/*	  All Intel 386 Processor Machines are Defined Here!	    */
end_comment

begin_comment
comment|/*								    */
end_comment

begin_comment
comment|/* **************************************************************** */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|i386
argument_list|)
end_if

begin_comment
comment|/* 386BSD */
end_comment

begin_comment
comment|/* Use `$(CC) -E' instead of `/lib/cpp' in Makefile. */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|done386
argument_list|)
operator|&&
name|defined
argument_list|(
name|__386BSD__
argument_list|)
end_if

begin_define
define|#
directive|define
name|done386
end_define

begin_define
define|#
directive|define
name|M_MACHINE
value|"i386"
end_define

begin_define
define|#
directive|define
name|M_OS
value|Bsd
end_define

begin_define
define|#
directive|define
name|HAVE_SETLINEBUF
end_define

begin_define
define|#
directive|define
name|HAVE_SYS_SIGLIST
end_define

begin_define
define|#
directive|define
name|HAVE_VFPRINTF
end_define

begin_define
define|#
directive|define
name|HAVE_GETGROUPS
end_define

begin_comment
comment|/*#    define SYSDEP_CFLAGS -traditional ? */
end_comment

begin_define
define|#
directive|define
name|HAVE_STRERROR
end_define

begin_define
define|#
directive|define
name|HAVE_RESOURCE
end_define

begin_define
define|#
directive|define
name|VOID_SIGHANDLER
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* i386&& __386BSD__ */
end_comment

begin_comment
comment|/* **************************************************************** */
end_comment

begin_comment
comment|/*                                                                  */
end_comment

begin_comment
comment|/*                       Sequent Machines                           */
end_comment

begin_comment
comment|/*                                                                  */
end_comment

begin_comment
comment|/* **************************************************************** */
end_comment

begin_comment
comment|/* Sequent Symmetry running Dynix/ptx (System V.3.2) */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|done386
argument_list|)
operator|&&
name|defined
argument_list|(
name|_SEQUENT_
argument_list|)
end_if

begin_define
define|#
directive|define
name|done386
end_define

begin_define
define|#
directive|define
name|M_MACHINE
value|"Symmetry"
end_define

begin_define
define|#
directive|define
name|M_OS
value|USG
end_define

begin_define
define|#
directive|define
name|SYSDEP_CFLAGS
value|-DUSGr3
end_define

begin_define
define|#
directive|define
name|HAVE_VFPRINTF
end_define

begin_define
define|#
directive|define
name|VOID_SIGHANDLER
end_define

begin_define
define|#
directive|define
name|HAVE_ALLOCA
end_define

begin_define
define|#
directive|define
name|REQUIRED_LIBRARIES
value|-lPW -lseq
end_define

begin_undef
undef|#
directive|undef
name|HAVE_GETWD
end_undef

begin_undef
undef|#
directive|undef
name|HAVE_RESOURCE
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _SEQUENT_ */
end_comment

begin_comment
comment|/* Sequent Symmetry running Dynix (4.2 BSD) */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|done386
argument_list|)
operator|&&
name|defined
argument_list|(
name|sequent
argument_list|)
end_if

begin_define
define|#
directive|define
name|done386
end_define

begin_define
define|#
directive|define
name|M_MACHINE
value|"Symmetry"
end_define

begin_define
define|#
directive|define
name|M_OS
value|Bsd
end_define

begin_define
define|#
directive|define
name|SYSDEP_CFLAGS
value|-DCPCC -DHAVE_SETDTABLESIZE
end_define

begin_define
define|#
directive|define
name|HAVE_SETLINEBUF
end_define

begin_define
define|#
directive|define
name|HAVE_SYS_SIGLIST
end_define

begin_define
define|#
directive|define
name|HAVE_GETGROUPS
end_define

begin_undef
undef|#
directive|undef
name|HAVE_DUP2
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Sequent 386 */
end_comment

begin_comment
comment|/* Generic 386 clone running Mach (4.3 BSD-compatible). */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|done386
argument_list|)
operator|&&
name|defined
argument_list|(
name|MACH
argument_list|)
end_if

begin_define
define|#
directive|define
name|done386
end_define

begin_define
define|#
directive|define
name|M_MACHINE
value|"i386"
end_define

begin_define
define|#
directive|define
name|M_OS
value|Bsd
end_define

begin_define
define|#
directive|define
name|HAVE_SETLINEBUF
end_define

begin_define
define|#
directive|define
name|HAVE_SYS_SIGLIST
end_define

begin_define
define|#
directive|define
name|HAVE_GETGROUPS
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* i386&& MACH */
end_comment

begin_comment
comment|/* AIX/PS2 1.2 for the 386. */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|done386
argument_list|)
operator|&&
name|defined
argument_list|(
name|aixpc
argument_list|)
end_if

begin_define
define|#
directive|define
name|done386
end_define

begin_define
define|#
directive|define
name|M_MACHINE
value|"aixpc"
end_define

begin_define
define|#
directive|define
name|M_OS
value|AIX
end_define

begin_define
define|#
directive|define
name|HAVE_VFPRINTF
end_define

begin_define
define|#
directive|define
name|VOID_SIGHANDLER
end_define

begin_define
define|#
directive|define
name|SYSDEP_CFLAGS
value|-D_BSD
end_define

begin_define
define|#
directive|define
name|REQUIRED_LIBRARIES
value|-lbsd
end_define

begin_define
define|#
directive|define
name|HAVE_GETGROUPS
end_define

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|HAVE_GCC
argument_list|)
end_if

begin_undef
undef|#
directive|undef
name|HAVE_ALLOCA
end_undef

begin_undef
undef|#
directive|undef
name|HAVE_ALLOCA_H
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !HAVE_GCC */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* AIXPC i386 */
end_comment

begin_comment
comment|/* System V Release 4 on the 386 */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|done386
argument_list|)
operator|&&
name|defined
argument_list|(
name|USGr4
argument_list|)
end_if

begin_define
define|#
directive|define
name|done386
end_define

begin_define
define|#
directive|define
name|M_MACHINE
value|"i386"
end_define

begin_define
define|#
directive|define
name|M_OS
value|USG
end_define

begin_define
define|#
directive|define
name|HAVE_SYS_SIGLIST
end_define

begin_define
define|#
directive|define
name|HAVE_VFPRINTF
end_define

begin_define
define|#
directive|define
name|VOID_SIGHANDLER
end_define

begin_comment
comment|/* Alloca requires either Gcc or cc with -lucb. */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|HAVE_GCC
argument_list|)
end_if

begin_define
define|#
directive|define
name|EXTRA_LIB_SEARCH_PATH
value|/usr/ucblib
end_define

begin_define
define|#
directive|define
name|REQUIRED_LIBRARIES
value|-lc -lucb
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !HAVE_GCC */
end_comment

begin_define
define|#
directive|define
name|HAVE_GETGROUPS
end_define

begin_define
define|#
directive|define
name|SYSDEP_CFLAGS
value|-DUSGr4
end_define

begin_undef
undef|#
directive|undef
name|HAVE_GETWD
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* System V Release 4 on i386 */
end_comment

begin_comment
comment|/* 386 box running Interactive Unix 2.2 or greater. */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|done386
argument_list|)
operator|&&
name|defined
argument_list|(
name|isc386
argument_list|)
end_if

begin_define
define|#
directive|define
name|done386
end_define

begin_define
define|#
directive|define
name|M_MACHINE
value|"isc386"
end_define

begin_define
define|#
directive|define
name|M_OS
value|USG
end_define

begin_define
define|#
directive|define
name|HAVE_VFPRINTF
end_define

begin_define
define|#
directive|define
name|VOID_SIGHANDLER
end_define

begin_define
define|#
directive|define
name|HAVE_GETGROUPS
end_define

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|HAVE_GCC
argument_list|)
end_if

begin_define
define|#
directive|define
name|REQUIRED_LIBRARIES
value|-lPW -lc_s
end_define

begin_define
define|#
directive|define
name|SYSDEP_LDFLAGS
value|-Xp
end_define

begin_comment
comment|/* ISC's wait.h requires lots of POSIX junk.  Forget it. */
end_comment

begin_undef
undef|#
directive|undef
name|HAVE_WAIT_H
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
name|NOTDEF
argument_list|)
end_if

begin_comment
comment|/* libcposix.a contains putc, getc, fileno. */
end_comment

begin_define
define|#
directive|define
name|REQUIRED_LIBRARIES
value|-lcposix
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* NOTDEF */
end_comment

begin_undef
undef|#
directive|undef
name|HAVE_GETWD
end_undef

begin_undef
undef|#
directive|undef
name|HAVE_GETCWD
end_undef

begin_comment
comment|/*<sys/types.h> uses mode_t, but doesn't define it unless 	_POSIX_SOURCE is defined.  But when _POSIX_SOURCE is defined,<signal.h> tries to use pid_t without including<sys/types.h>! 	What a mess.  	ISC's<sys/fcntl.h> doesn't want to define O_NDELAY if __STDC__ 	is defined.  We fix that here also.  */
end_comment

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
name|HAVE_GCC
argument_list|)
end_if

begin_define
define|#
directive|define
name|SYSDEP_CFLAGS
value|-DUSGr3 -D_POSIX_SOURCE \ 	-Dmode_t="unsigned short" -DO_NDELAY=O_NONBLOCK -DPGRP_PIPE
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|SYSDEP_CFLAGS
value|-DUSGr3 -D_POSIX_SOURCE -DPGRP_PIPE
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __STDC__ || HAVE_GCC */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* isc386 */
end_comment

begin_comment
comment|/* Xenix386 machine. */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|done386
argument_list|)
operator|&&
name|defined
argument_list|(
name|Xenix386
argument_list|)
end_if

begin_define
define|#
directive|define
name|done386
end_define

begin_define
define|#
directive|define
name|M_MACHINE
value|"i386"
end_define

begin_define
define|#
directive|define
name|M_OS
value|Xenix
end_define

begin_define
define|#
directive|define
name|SYSDEP_CFLAGS
value|-DUSGr3 -DREVERSED_SETVBUF_ARGS
end_define

begin_define
define|#
directive|define
name|HAVE_VFPRINTF
end_define

begin_define
define|#
directive|define
name|VOID_SIGHANDLER
end_define

begin_define
define|#
directive|define
name|ALLOCA_ASM
value|x386-alloca.s
end_define

begin_define
define|#
directive|define
name|REQUIRED_LIBRARIES
value|-lx
end_define

begin_undef
undef|#
directive|undef
name|HAVE_ALLOCA
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Xenix386 */
end_comment

begin_comment
comment|/* SCO UNIX 3.2 chip@count.tct.com (Chip Salzenberg) */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|done386
argument_list|)
operator|&&
name|defined
argument_list|(
name|M_UNIX
argument_list|)
end_if

begin_define
define|#
directive|define
name|done386
end_define

begin_define
define|#
directive|define
name|M_MACHINE
value|"i386"
end_define

begin_define
define|#
directive|define
name|M_OS
value|SCO
end_define

begin_define
define|#
directive|define
name|SYSDEP_CFLAGS
value|-DUSG -DUSGr3
end_define

begin_define
define|#
directive|define
name|HAVE_VFPRINTF
end_define

begin_define
define|#
directive|define
name|VOID_SIGHANDLER
end_define

begin_define
define|#
directive|define
name|HAVE_GETGROUPS
end_define

begin_undef
undef|#
directive|undef
name|HAVE_GETWD
end_undef

begin_undef
undef|#
directive|undef
name|HAVE_RESOURCE
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* SCO Unix on 386 boxes. */
end_comment

begin_comment
comment|/* Assume a generic 386 running Sys V Release 3. */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|done386
argument_list|)
end_if

begin_define
define|#
directive|define
name|done386
end_define

begin_define
define|#
directive|define
name|M_MACHINE
value|"i386"
end_define

begin_define
define|#
directive|define
name|M_OS
value|USG
end_define

begin_define
define|#
directive|define
name|SYSDEP_CFLAGS
value|-DUSGr3
end_define

begin_define
define|#
directive|define
name|HAVE_VFPRINTF
end_define

begin_define
define|#
directive|define
name|VOID_SIGHANDLER
end_define

begin_comment
comment|/* Alloca requires either Gcc or cc with libPW.a */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|HAVE_GCC
argument_list|)
end_if

begin_define
define|#
directive|define
name|REQUIRED_LIBRARIES
value|-lPW
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !HAVE_GCC */
end_comment

begin_undef
undef|#
directive|undef
name|HAVE_GETWD
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Generic i386 Box running Sys V release 3. */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* All i386 Machines with an `i386' define in cpp. */
end_comment

begin_comment
comment|/* **************************************************************** */
end_comment

begin_comment
comment|/*								    */
end_comment

begin_comment
comment|/*		      Gould 9000 - UTX/32 R2.1A			    */
end_comment

begin_comment
comment|/*								    */
end_comment

begin_comment
comment|/* **************************************************************** */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|gould
argument_list|)
end_if

begin_comment
comment|/* Maybe should be GOULD_PN ? */
end_comment

begin_define
define|#
directive|define
name|M_MACHINE
value|"gould"
end_define

begin_define
define|#
directive|define
name|M_OS
value|Bsd
end_define

begin_define
define|#
directive|define
name|HAVE_SYS_SIGLIST
end_define

begin_define
define|#
directive|define
name|HAVE_SETLINEBUF
end_define

begin_define
define|#
directive|define
name|HAVE_GETGROUPS
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* gould */
end_comment

begin_comment
comment|/* ************************ */
end_comment

begin_comment
comment|/*			    */
end_comment

begin_comment
comment|/*	    NeXT	    */
end_comment

begin_comment
comment|/*			    */
end_comment

begin_comment
comment|/* ************************ */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|NeXT
argument_list|)
end_if

begin_define
define|#
directive|define
name|M_MACHINE
value|"NeXT"
end_define

begin_define
define|#
directive|define
name|M_OS
value|Bsd
end_define

begin_define
define|#
directive|define
name|HAVE_VFPRINTF
end_define

begin_define
define|#
directive|define
name|HAVE_SYS_SIGLIST
end_define

begin_define
define|#
directive|define
name|HAVE_GETGROUPS
end_define

begin_define
define|#
directive|define
name|HAVE_STRERROR
end_define

begin_define
define|#
directive|define
name|VOID_SIGHANDLER
end_define

begin_undef
undef|#
directive|undef
name|USE_GNU_MALLOC
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ************************ */
end_comment

begin_comment
comment|/*			    */
end_comment

begin_comment
comment|/*	hp9000 4.3 BSD	    */
end_comment

begin_comment
comment|/*			    */
end_comment

begin_comment
comment|/* ************************ */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|hp9000
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|hpux
argument_list|)
end_if

begin_define
define|#
directive|define
name|M_MACHINE
value|"hp9000"
end_define

begin_define
define|#
directive|define
name|M_OS
value|Bsd
end_define

begin_undef
undef|#
directive|undef
name|HAVE_ALLOCA
end_undef

begin_define
define|#
directive|define
name|HAVE_SYS_SIGLIST
end_define

begin_define
define|#
directive|define
name|HAVE_SETLINEBUF
end_define

begin_define
define|#
directive|define
name|HAVE_GETGROUPS
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* hp9000&& !hpux */
end_comment

begin_comment
comment|/* ************************ */
end_comment

begin_comment
comment|/*			    */
end_comment

begin_comment
comment|/*	    hpux	    */
end_comment

begin_comment
comment|/*			    */
end_comment

begin_comment
comment|/* ************************ */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|hpux
argument_list|)
end_if

begin_define
define|#
directive|define
name|M_MACHINE
value|"hpux"
end_define

begin_comment
comment|/* This is for 6.2+ systems with job control. */
end_comment

begin_define
define|#
directive|define
name|M_OS
value|HPUX
end_define

begin_comment
comment|/* For HP-UX systems before 6.2, we don't have job control. */
end_comment

begin_comment
comment|/* #undef M_OS */
end_comment

begin_comment
comment|/* #define M_OS USG */
end_comment

begin_comment
comment|/* For HP-UX 7.0, we don't need the -lBSD. */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__hpux
argument_list|)
end_if

begin_define
define|#
directive|define
name|HPUX_70
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
name|HPUX_70
argument_list|)
end_if

begin_define
define|#
directive|define
name|SYSDEP_CFLAGS
value|-DHPUX_70
end_define

begin_define
define|#
directive|define
name|REQUIRED_LIBRARIES
value|-lPW
end_define

begin_undef
undef|#
directive|undef
name|HAVE_GETWD
end_undef

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* Not 7.0 OS version. */
end_comment

begin_define
define|#
directive|define
name|REQUIRED_LIBRARIES
value|-lPW -lBSD
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __hpux */
end_comment

begin_define
define|#
directive|define
name|HAVE_VFPRINTF
end_define

begin_define
define|#
directive|define
name|VOID_SIGHANDLER
end_define

begin_define
define|#
directive|define
name|HAVE_GETGROUPS
end_define

begin_define
define|#
directive|define
name|HAVE_STRERROR
end_define

begin_define
define|#
directive|define
name|SEARCH_LIB_NEEDS_SPACE
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* hpux */
end_comment

begin_comment
comment|/* ************************ */
end_comment

begin_comment
comment|/*			    */
end_comment

begin_comment
comment|/*	    Xenix286	    */
end_comment

begin_comment
comment|/*			    */
end_comment

begin_comment
comment|/* ************************ */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|Xenix286
argument_list|)
end_if

begin_define
define|#
directive|define
name|M_MACHINE
value|"i286"
end_define

begin_define
define|#
directive|define
name|M_OS
value|Xenix
end_define

begin_undef
undef|#
directive|undef
name|HAVE_ALLOCA
end_undef

begin_define
define|#
directive|define
name|REQUIRED_LIBRARIES
value|-lx
end_define

begin_define
define|#
directive|define
name|SYSDEP_CFLAGS
value|-DREVERSED_SETVBUF_ARGS
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Xenix 386 box not caught in i386 case above. */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|M_MACHINE
argument_list|)
operator|&&
name|defined
argument_list|(
name|Xenix386
argument_list|)
end_if

begin_define
define|#
directive|define
name|M_MACHINE
value|"i386"
end_define

begin_define
define|#
directive|define
name|M_OS
value|Xenix
end_define

begin_define
define|#
directive|define
name|SYSDEP_CFLAGS
value|-DUSGr3 -DREVERSED_SETVBUF_ARGS
end_define

begin_define
define|#
directive|define
name|HAVE_VFPRINTF
end_define

begin_define
define|#
directive|define
name|VOID_SIGHANDLER
end_define

begin_define
define|#
directive|define
name|ALLOCA_ASM
value|x386-alloca.s
end_define

begin_define
define|#
directive|define
name|REQUIRED_LIBRARIES
value|-lx
end_define

begin_undef
undef|#
directive|undef
name|HAVE_ALLOCA
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Xenix386 */
end_comment

begin_comment
comment|/* ************************ */
end_comment

begin_comment
comment|/*			    */
end_comment

begin_comment
comment|/*	    convex	    */
end_comment

begin_comment
comment|/*			    */
end_comment

begin_comment
comment|/* ************************ */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|convex
argument_list|)
end_if

begin_define
define|#
directive|define
name|M_MACHINE
value|"convex"
end_define

begin_define
define|#
directive|define
name|M_OS
value|Bsd
end_define

begin_undef
undef|#
directive|undef
name|HAVE_ALLOCA
end_undef

begin_define
define|#
directive|define
name|HAVE_SETLINEBUF
end_define

begin_define
define|#
directive|define
name|HAVE_SYS_SIGLIST
end_define

begin_define
define|#
directive|define
name|HAVE_GETGROUPS
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* convex */
end_comment

begin_comment
comment|/* ************************ */
end_comment

begin_comment
comment|/*			    */
end_comment

begin_comment
comment|/*	    AIX/RT	    */
end_comment

begin_comment
comment|/*			    */
end_comment

begin_comment
comment|/* ************************ */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|aix
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|aixpc
argument_list|)
end_if

begin_define
define|#
directive|define
name|M_MACHINE
value|"AIX"
end_define

begin_define
define|#
directive|define
name|M_OS
value|Bsd
end_define

begin_undef
undef|#
directive|undef
name|HAVE_ALLOCA
end_undef

begin_define
define|#
directive|define
name|HAVE_VFPRINTF
end_define

begin_define
define|#
directive|define
name|HAVE_SYS_SIGLIST
end_define

begin_define
define|#
directive|define
name|VOID_SIGHANDLER
end_define

begin_define
define|#
directive|define
name|HAVE_GETGROUPS
end_define

begin_define
define|#
directive|define
name|USE_TERMCAP_EMULATION
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* AIX */
end_comment

begin_comment
comment|/* **************************************** */
end_comment

begin_comment
comment|/*					    */
end_comment

begin_comment
comment|/*		IBM RISC 6000		    */
end_comment

begin_comment
comment|/*					    */
end_comment

begin_comment
comment|/* **************************************** */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|RISC6000
argument_list|)
operator|||
name|defined
argument_list|(
name|_IBMR2
argument_list|)
end_if

begin_define
define|#
directive|define
name|M_MACHINE
value|"RISC6000"
end_define

begin_define
define|#
directive|define
name|M_OS
value|"AIX"
end_define

begin_undef
undef|#
directive|undef
name|HAVE_GETWD
end_undef

begin_undef
undef|#
directive|undef
name|HAVE_ALLOCA
end_undef

begin_define
define|#
directive|define
name|HAVE_SYS_SIGLIST
end_define

begin_define
define|#
directive|define
name|HAVE_SETLINEBUF
end_define

begin_define
define|#
directive|define
name|HAVE_VFPRINTF
end_define

begin_define
define|#
directive|define
name|VOID_SIGHANDLER
end_define

begin_define
define|#
directive|define
name|USE_TERMCAP_EMULATION
end_define

begin_define
define|#
directive|define
name|HAVE_GETGROUPS
end_define

begin_define
define|#
directive|define
name|SYSDEP_CFLAGS
value|-DNLS -DUSG
end_define

begin_undef
undef|#
directive|undef
name|USE_GNU_MALLOC
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* RISC6000 */
end_comment

begin_comment
comment|/* **************************************** */
end_comment

begin_comment
comment|/*					    */
end_comment

begin_comment
comment|/*	u370 IBM AIX/370		    */
end_comment

begin_comment
comment|/*					    */
end_comment

begin_comment
comment|/* **************************************** */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|u370
argument_list|)
end_if

begin_if
if|#
directive|if
name|defined
argument_list|(
name|_AIX370
argument_list|)
end_if

begin_define
define|#
directive|define
name|M_MACHINE
value|"AIX370"
end_define

begin_define
define|#
directive|define
name|M_OS
value|Bsd
end_define

begin_define
define|#
directive|define
name|REQUIRED_LIBRARIES
value|-lbsd
end_define

begin_define
define|#
directive|define
name|HAVE_SETLINEBUF
end_define

begin_define
define|#
directive|define
name|HAVE_VFPRINTF
end_define

begin_define
define|#
directive|define
name|SYSDEP_CFLAGS
value|-D_BSD
end_define

begin_define
define|#
directive|define
name|HAVE_GETGROUPS
end_define

begin_define
define|#
directive|define
name|USE_TERMCAP_EMULATION
end_define

begin_undef
undef|#
directive|undef
name|USE_GNU_MALLOC
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _AIX370 */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|USGr4
argument_list|)
end_if

begin_comment
comment|/* System V Release 4 on 370 series architecture. */
end_comment

begin_define
define|#
directive|define
name|M_MACHINE
value|"uxp"
end_define

begin_define
define|#
directive|define
name|M_OS
value|USG
end_define

begin_define
define|#
directive|define
name|HAVE_SYS_SIGLIST
end_define

begin_define
define|#
directive|define
name|HAVE_VPRINTF
end_define

begin_define
define|#
directive|define
name|USE_GNU_MALLOC
end_define

begin_define
define|#
directive|define
name|VOID_SIGHANDLER
end_define

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|HAVE_GCC
argument_list|)
end_if

begin_undef
undef|#
directive|undef
name|HAVE_ALLOCA
end_undef

begin_define
define|#
directive|define
name|EXTRA_LIB_SEARCH_PATH
value|/usr/ucblib
end_define

begin_define
define|#
directive|define
name|REQUIRED_LIBRARIES
value|-lc -lucb
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !HAVE_GCC */
end_comment

begin_define
define|#
directive|define
name|HAVE_GETGROUPS
end_define

begin_define
define|#
directive|define
name|HAVE_RESOURCE
end_define

begin_define
define|#
directive|define
name|SYSDEP_CFLAGS
value|-DUSGr4
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* USGr4 */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* u370 */
end_comment

begin_comment
comment|/* ************************ */
end_comment

begin_comment
comment|/*			    */
end_comment

begin_comment
comment|/*	    ATT 3B	    */
end_comment

begin_comment
comment|/*			    */
end_comment

begin_comment
comment|/* ************************ */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|att3b
argument_list|)
operator|||
name|defined
argument_list|(
name|u3b2
argument_list|)
end_if

begin_if
if|#
directive|if
name|defined
argument_list|(
name|att3b
argument_list|)
end_if

begin_define
define|#
directive|define
name|M_MACHINE
value|"att3b"
end_define

begin_define
define|#
directive|define
name|HAVE_SYS_SIGLIST
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|M_MACHINE
value|"u3b2"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|M_OS
value|USG
end_define

begin_undef
undef|#
directive|undef
name|HAVE_GETWD
end_undef

begin_define
define|#
directive|define
name|HAVE_VFPRINTF
end_define

begin_define
define|#
directive|define
name|VOID_SIGHANDLER
end_define

begin_comment
comment|/* For an AT&T Unix before V.3 take out the -DUSGr3 */
end_comment

begin_define
define|#
directive|define
name|SYSDEP_CFLAGS
value|-DUSGr3
end_define

begin_comment
comment|/* Alloca requires either Gcc or cc with libPW.a. */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|HAVE_GCC
argument_list|)
end_if

begin_define
define|#
directive|define
name|REQUIRED_LIBRARIES
value|-lPW
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !HAVE_GCC */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* att3b */
end_comment

begin_comment
comment|/* ************************ */
end_comment

begin_comment
comment|/*			    */
end_comment

begin_comment
comment|/*	    ATT 386	    */
end_comment

begin_comment
comment|/*			    */
end_comment

begin_comment
comment|/* ************************ */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|att386
argument_list|)
end_if

begin_define
define|#
directive|define
name|M_MACHINE
value|"att386"
end_define

begin_define
define|#
directive|define
name|M_OS
value|USG
end_define

begin_undef
undef|#
directive|undef
name|HAVE_GETWD
end_undef

begin_comment
comment|/* Alloca requires either Gcc or cc with libPW.a. */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|HAVE_GCC
argument_list|)
end_if

begin_define
define|#
directive|define
name|REQUIRED_LIBRARIES
value|-lPW
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HAVE_GCC */
end_comment

begin_define
define|#
directive|define
name|HAVE_SYS_SIGLIST
end_define

begin_define
define|#
directive|define
name|HAVE_VFPRINTF
end_define

begin_define
define|#
directive|define
name|VOID_SIGHANDLER
end_define

begin_comment
comment|/* For an AT&T Unix before V.3 take out the -DUSGr3 */
end_comment

begin_define
define|#
directive|define
name|SYSDEP_CFLAGS
value|-DUSGr3
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* att386 */
end_comment

begin_comment
comment|/* ************************ */
end_comment

begin_comment
comment|/*			    */
end_comment

begin_comment
comment|/*	    Encore	    */
end_comment

begin_comment
comment|/*			    */
end_comment

begin_comment
comment|/* ************************ */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|MULTIMAX
argument_list|)
end_if

begin_if
if|#
directive|if
name|defined
argument_list|(
name|n16
argument_list|)
end_if

begin_define
define|#
directive|define
name|M_MACHINE
value|"Multimax32k"
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|M_MACHINE
value|"Multimax"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* n16 */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|UMAXV
argument_list|)
end_if

begin_define
define|#
directive|define
name|M_OS
value|USG
end_define

begin_define
define|#
directive|define
name|REQUIRED_LIBRARIES
value|-lPW
end_define

begin_define
define|#
directive|define
name|SYSDEP_CFLAGS
value|-DUSGr3
end_define

begin_define
define|#
directive|define
name|HAVE_VFPRINTF
end_define

begin_define
define|#
directive|define
name|USE_TERMCAP_EMULATION
end_define

begin_define
define|#
directive|define
name|VOID_SIGHANDLER
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
name|CMU
argument_list|)
end_if

begin_define
define|#
directive|define
name|M_OS
value|Mach
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|M_OS
value|Bsd
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CMU */
end_comment

begin_define
define|#
directive|define
name|HAVE_SYS_SIGLIST
end_define

begin_define
define|#
directive|define
name|HAVE_STRERROR
end_define

begin_define
define|#
directive|define
name|HAVE_SETLINEBUF
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* UMAXV */
end_comment

begin_define
define|#
directive|define
name|HAVE_GETGROUPS
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* MULTIMAX */
end_comment

begin_comment
comment|/* ******************************************** */
end_comment

begin_comment
comment|/*						*/
end_comment

begin_comment
comment|/*   Encore Series 91 (88K BCS w Job Control)	*/
end_comment

begin_comment
comment|/*						*/
end_comment

begin_comment
comment|/* ******************************************** */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__m88k
argument_list|)
operator|&&
name|defined
argument_list|(
name|__UMAXV__
argument_list|)
end_if

begin_define
define|#
directive|define
name|M_MACHINE
value|"Gemini"
end_define

begin_define
define|#
directive|define
name|M_OS
value|USG
end_define

begin_define
define|#
directive|define
name|REQUIRED_LIBRARIES
value|-lPW
end_define

begin_define
define|#
directive|define
name|USE_TERMCAP_EMULATION
end_define

begin_define
define|#
directive|define
name|HAVE_VFPRINTF
end_define

begin_define
define|#
directive|define
name|HAVE_GETGROUPS
end_define

begin_define
define|#
directive|define
name|VOID_SIGHANDLER
end_define

begin_define
define|#
directive|define
name|SYSDEP_CFLAGS
value|-q ext=pcc -D_POSIX_JOB_CONTROL -D_POSIX_VERSION \ 		      -Dmalloc=_malloc -Dfree=_free -Drealloc=_realloc
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* m88k */
end_comment

begin_comment
comment|/* ******************************************** */
end_comment

begin_comment
comment|/*						*/
end_comment

begin_comment
comment|/*    System V Release 4 on the ICL DRS6000     */
end_comment

begin_comment
comment|/*						*/
end_comment

begin_comment
comment|/* ******************************************** */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|drs6000
argument_list|)
end_if

begin_define
define|#
directive|define
name|M_MACHINE
value|"drs6000"
end_define

begin_define
define|#
directive|define
name|M_OS
value|USG
end_define

begin_define
define|#
directive|define
name|SYSDEP_CFLAGS
value|-Xa -DUSGr4 -Dsys_siglist=_sys_siglist
end_define

begin_define
define|#
directive|define
name|EXTRA_LIB_SEARCH_PATH
value|/usr/ucblib
end_define

begin_define
define|#
directive|define
name|SEARCH_LIB_NEEDS_SPACE
end_define

begin_define
define|#
directive|define
name|REQUIRED_LIBRARIES
value|-lc -lucb
end_define

begin_define
define|#
directive|define
name|HAVE_SYS_SIGLIST
end_define

begin_define
define|#
directive|define
name|HAVE_SETLINEBUF
end_define

begin_define
define|#
directive|define
name|HAVE_VFPRINTF
end_define

begin_define
define|#
directive|define
name|HAVE_GETGROUPS
end_define

begin_define
define|#
directive|define
name|HAVE_STRERROR
end_define

begin_define
define|#
directive|define
name|VOID_SIGHANDLER
end_define

begin_undef
undef|#
directive|undef
name|HAVE_ALLOCA
end_undef

begin_undef
undef|#
directive|undef
name|HAVE_ALLOCA_H
end_undef

begin_undef
undef|#
directive|undef
name|USE_GNU_MALLOC
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* drs6000 */
end_comment

begin_comment
comment|/* ******************************************** */
end_comment

begin_comment
comment|/*						*/
end_comment

begin_comment
comment|/*  System V Release 4 on the Commodore Amiga   */
end_comment

begin_comment
comment|/*						*/
end_comment

begin_comment
comment|/* ******************************************** */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|amiga
argument_list|)
end_if

begin_define
define|#
directive|define
name|M_MACHINE
value|"amiga"
end_define

begin_define
define|#
directive|define
name|M_OS
value|USG
end_define

begin_define
define|#
directive|define
name|SYSDEP_CFLAGS
value|-DUSGr4
end_define

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|HAVE_GCC
argument_list|)
end_if

begin_define
define|#
directive|define
name|EXTRA_LIB_SEARCH_PATH
value|/usr/ucblib
end_define

begin_define
define|#
directive|define
name|REQUIRED_LIBRARIES
value|-lc -lucb
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !HAVE_GCC */
end_comment

begin_define
define|#
directive|define
name|HAVE_SYS_SIGLIST
end_define

begin_define
define|#
directive|define
name|HAVE_VFPRINTF
end_define

begin_define
define|#
directive|define
name|VOID_SIGHANDLER
end_define

begin_define
define|#
directive|define
name|HAVE_GETGROUPS
end_define

begin_define
define|#
directive|define
name|HAVE_STRERROR
end_define

begin_undef
undef|#
directive|undef
name|HAVE_GETWD
end_undef

begin_undef
undef|#
directive|undef
name|USE_GNU_MALLOC
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* System V Release 4 on amiga */
end_comment

begin_comment
comment|/* ************************ */
end_comment

begin_comment
comment|/*			    */
end_comment

begin_comment
comment|/*	    clipper	    */
end_comment

begin_comment
comment|/*			    */
end_comment

begin_comment
comment|/* ************************ */
end_comment

begin_comment
comment|/* This is for the Orion 1/05 (A BSD 4.2 box based on a Clipper processor) */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|clipper
argument_list|)
end_if

begin_define
define|#
directive|define
name|M_MACHINE
value|"clipper"
end_define

begin_define
define|#
directive|define
name|M_OS
value|Bsd
end_define

begin_define
define|#
directive|define
name|HAVE_SETLINEBUF
end_define

begin_define
define|#
directive|define
name|HAVE_GETGROUPS
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* clipper */
end_comment

begin_comment
comment|/* ******************************** */
end_comment

begin_comment
comment|/*				    */
end_comment

begin_comment
comment|/*    Integrated Solutions 68020?   */
end_comment

begin_comment
comment|/*				    */
end_comment

begin_comment
comment|/* ******************************** */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|is68k
argument_list|)
end_if

begin_define
define|#
directive|define
name|M_MACHINE
value|"is68k"
end_define

begin_define
define|#
directive|define
name|M_OS
value|Bsd
end_define

begin_undef
undef|#
directive|undef
name|HAVE_ALLOCA
end_undef

begin_define
define|#
directive|define
name|HAVE_SYS_SIGLIST
end_define

begin_define
define|#
directive|define
name|HAVE_SETLINEBUF
end_define

begin_define
define|#
directive|define
name|HAVE_GETGROUPS
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* is68k */
end_comment

begin_comment
comment|/* ******************************** */
end_comment

begin_comment
comment|/*				    */
end_comment

begin_comment
comment|/*	   Omron Luna/Mach 2.5	    */
end_comment

begin_comment
comment|/*				    */
end_comment

begin_comment
comment|/* ******************************** */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|luna88k
argument_list|)
end_if

begin_define
define|#
directive|define
name|M_MACHINE
value|"Luna88k"
end_define

begin_define
define|#
directive|define
name|M_OS
value|Bsd
end_define

begin_define
define|#
directive|define
name|HAVE_SYS_SIGLIST
end_define

begin_define
define|#
directive|define
name|USE_GNU_MALLOC
end_define

begin_define
define|#
directive|define
name|HAVE_SETLINEBUF
end_define

begin_define
define|#
directive|define
name|HAVE_VFPRINTF
end_define

begin_define
define|#
directive|define
name|HAVE_GETGROUPS
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* luna88k */
end_comment

begin_comment
comment|/* **************************************** */
end_comment

begin_comment
comment|/*					    */
end_comment

begin_comment
comment|/*	    Apollo/SR10.2/BSD4.3	    */
end_comment

begin_comment
comment|/*					    */
end_comment

begin_comment
comment|/* **************************************** */
end_comment

begin_comment
comment|/* This is for the Apollo DN3500 running SR10.2 BSD4.3 */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|apollo
argument_list|)
end_if

begin_define
define|#
directive|define
name|M_MACHINE
value|"apollo"
end_define

begin_define
define|#
directive|define
name|M_OS
value|Bsd
end_define

begin_define
define|#
directive|define
name|SYSDEP_CFLAGS
value|-D_POSIX_VERSION -D_INCLUDE_BSD_SOURCE -D_INCLUDE_POSIX_SOURCE -DTERMIOS_MISSING -DBSD_GETPGRP -Dpid_t=int
end_define

begin_define
define|#
directive|define
name|HAVE_SYS_SIGLIST
end_define

begin_define
define|#
directive|define
name|HAVE_SETLINEBUF
end_define

begin_define
define|#
directive|define
name|HAVE_GETGROUPS
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* apollo */
end_comment

begin_comment
comment|/* ************************ */
end_comment

begin_comment
comment|/*			    */
end_comment

begin_comment
comment|/*	DG AViiON	    */
end_comment

begin_comment
comment|/*			    */
end_comment

begin_comment
comment|/* ************************ */
end_comment

begin_comment
comment|/* This is for the DG AViiON box (runs DG/UX with both AT&T& BSD features.) */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__DGUX__
argument_list|)
operator|||
name|defined
argument_list|(
name|DGUX
argument_list|)
end_if

begin_define
define|#
directive|define
name|M_MACHINE
value|"AViiON"
end_define

begin_define
define|#
directive|define
name|M_OS
value|USG
end_define

begin_undef
undef|#
directive|undef
name|HAVE_GETWD
end_undef

begin_define
define|#
directive|define
name|SYSDEP_CFLAGS
value|-D_DGUX_SOURCE -DPGRP_PIPE
end_define

begin_comment
comment|/* -D_M88K_SOURCE */
end_comment

begin_comment
comment|/* DG/UX comes standard with gcc. */
end_comment

begin_define
define|#
directive|define
name|HAVE_GCC
end_define

begin_define
define|#
directive|define
name|HAVE_FIXED_INCLUDES
end_define

begin_define
define|#
directive|define
name|HAVE_STRERROR
end_define

begin_define
define|#
directive|define
name|HAVE_GETGROUPS
end_define

begin_define
define|#
directive|define
name|VOID_SIGHANDLER
end_define

begin_undef
undef|#
directive|undef
name|USE_GNU_MALLOC
end_undef

begin_comment
comment|/* If you want to build bash for M88K BCS compliance on a DG/UX 5.4    or above system, do the following:       - Add -D_M88K_SOURCE to SYSDEP_CFLAGS above.      - Before running "make" type: "eval `sde-target m88kbcs`" to set        the software development environment to build BCS objects. */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __DGUX__ */
end_comment

begin_comment
comment|/* ************************ */
end_comment

begin_comment
comment|/*                          */
end_comment

begin_comment
comment|/*          XD88            */
end_comment

begin_comment
comment|/*                          */
end_comment

begin_comment
comment|/* ************************ */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|m88k
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|M_MACHNE
argument_list|)
end_if

begin_define
define|#
directive|define
name|M_MACHINE
value|"XD88"
end_define

begin_define
define|#
directive|define
name|M_OS
value|USG
end_define

begin_define
define|#
directive|define
name|HAVE_VPRINTF
end_define

begin_undef
undef|#
directive|undef
name|HAVE_GETWD
end_undef

begin_undef
undef|#
directive|undef
name|HAVE_ALLOCA
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* XD88&& ! M_MACHINE */
end_comment

begin_comment
comment|/* ************************ */
end_comment

begin_comment
comment|/*			    */
end_comment

begin_comment
comment|/*    Harris Night Hawk	    */
end_comment

begin_comment
comment|/*			    */
end_comment

begin_comment
comment|/* ************************ */
end_comment

begin_comment
comment|/* This is for the Harris Night Hawk family. */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|_CX_UX
argument_list|)
end_if

begin_if
if|#
directive|if
name|defined
argument_list|(
name|_M88K
argument_list|)
end_if

begin_define
define|#
directive|define
name|M_MACHINE
value|"nh4000"
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
name|hcx
argument_list|)
end_if

begin_define
define|#
directive|define
name|M_MACHINE
value|"nh2000"
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
name|gcx
argument_list|)
end_if

begin_define
define|#
directive|define
name|M_MACHINE
value|"nh3000"
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
name|M_OS
value|USG
end_define

begin_define
define|#
directive|define
name|SYSDEP_CFLAGS
value|-g -Xa -v -Dgetwd=bash_getwd -D_POSIX_SOURCE -D_POSIX_JOB_CONTROL
end_define

begin_define
define|#
directive|define
name|USE_TERMCAP_EMULATION
end_define

begin_define
define|#
directive|define
name|HAVE_VFPRINTF
end_define

begin_define
define|#
directive|define
name|HAVE_GETGROUPS
end_define

begin_define
define|#
directive|define
name|VOID_SIGHANDLER
end_define

begin_undef
undef|#
directive|undef
name|USE_GNU_MALLOC
end_undef

begin_undef
undef|#
directive|undef
name|HAVE_GETWD
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* **************************************** */
end_comment

begin_comment
comment|/*					    */
end_comment

begin_comment
comment|/*	    	Tektronix	    	    */
end_comment

begin_comment
comment|/*					    */
end_comment

begin_comment
comment|/* **************************************** */
end_comment

begin_comment
comment|/* These are unproven as yet. */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|Tek4132
argument_list|)
end_if

begin_define
define|#
directive|define
name|M_MACHINE
value|"Tek4132"
end_define

begin_define
define|#
directive|define
name|M_OS
value|Bsd
end_define

begin_define
define|#
directive|define
name|HAVE_SYS_SIGLIST
end_define

begin_define
define|#
directive|define
name|HAVE_SETLINEBUF
end_define

begin_define
define|#
directive|define
name|HAVE_GETGROUPS
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Tek4132 */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|Tek4300
argument_list|)
end_if

begin_define
define|#
directive|define
name|M_MACHINE
value|"Tek4300"
end_define

begin_define
define|#
directive|define
name|M_OS
value|Bsd
end_define

begin_define
define|#
directive|define
name|HAVE_SYS_SIGLIST
end_define

begin_define
define|#
directive|define
name|HAVE_SETLINEBUF
end_define

begin_define
define|#
directive|define
name|HAVE_GETGROUPS
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Tek4300 */
end_comment

begin_comment
comment|/* ************************ */
end_comment

begin_comment
comment|/*			    */
end_comment

begin_comment
comment|/*     Sequent Balances     */
end_comment

begin_comment
comment|/*       (Dynix 3.x)	    */
end_comment

begin_comment
comment|/* ************************ */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|sequent
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|M_MACHINE
argument_list|)
end_if

begin_define
define|#
directive|define
name|M_MACHINE
value|"Sequent"
end_define

begin_define
define|#
directive|define
name|M_OS
value|Bsd
end_define

begin_undef
undef|#
directive|undef
name|HAVE_DUP2
end_undef

begin_define
define|#
directive|define
name|HAVE_SYS_SIGLIST
end_define

begin_define
define|#
directive|define
name|HAVE_SETLINEBUF
end_define

begin_define
define|#
directive|define
name|HAVE_GETGROUPS
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* sequent */
end_comment

begin_comment
comment|/* ****************************************** */
end_comment

begin_comment
comment|/*					      */
end_comment

begin_comment
comment|/*    NCR Tower 32, System V Release 3	      */
end_comment

begin_comment
comment|/*					      */
end_comment

begin_comment
comment|/* ****************************************** */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|tower32
argument_list|)
end_if

begin_define
define|#
directive|define
name|M_MACHINE
value|"tower32"
end_define

begin_define
define|#
directive|define
name|M_OS
value|USG
end_define

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|HAVE_GCC
argument_list|)
end_if

begin_define
define|#
directive|define
name|REQUIRED_LIBRARIES
value|-lPW
end_define

begin_comment
comment|/* Disable stack/frame-pointer optimization, incompatible with alloca */
end_comment

begin_define
define|#
directive|define
name|SYSDEP_CFLAGS
value|-DUSGr3 -W2,-aat
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|SYSDEP_CFLAGS
value|-DUSGr3
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !HAVE_GCC */
end_comment

begin_define
define|#
directive|define
name|HAVE_VFPRINTF
end_define

begin_define
define|#
directive|define
name|USE_TERMCAP_EMULATION
end_define

begin_define
define|#
directive|define
name|VOID_SIGHANDLER
end_define

begin_undef
undef|#
directive|undef
name|HAVE_GETWD
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* tower32 */
end_comment

begin_comment
comment|/* ************************ */
end_comment

begin_comment
comment|/*			    */
end_comment

begin_comment
comment|/*    Ardent Titan OS v2.2  */
end_comment

begin_comment
comment|/*			    */
end_comment

begin_comment
comment|/* ************************ */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|ardent
argument_list|)
end_if

begin_define
define|#
directive|define
name|M_MACHINE
value|"Ardent Titan"
end_define

begin_define
define|#
directive|define
name|M_OS
value|Bsd
end_define

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|titan
argument_list|)
end_if

begin_define
define|#
directive|define
name|HAVE_GETGROUPS
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|HAVE_SYS_SIGLIST
end_define

begin_define
define|#
directive|define
name|HAVE_SETLINEBUF
end_define

begin_define
define|#
directive|define
name|SYSDEP_CFLAGS
value|-43 -w
end_define

begin_define
define|#
directive|define
name|SYSDEP_LDFLAGS
value|-43
end_define

begin_undef
undef|#
directive|undef
name|HAVE_ALLOCA
end_undef

begin_undef
undef|#
directive|undef
name|USE_GNU_MALLOC
end_undef

begin_undef
undef|#
directive|undef
name|HAVE_VFPRINTF
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ardent */
end_comment

begin_comment
comment|/* ************************ */
end_comment

begin_comment
comment|/*			    */
end_comment

begin_comment
comment|/*	  Stardent	    */
end_comment

begin_comment
comment|/*			    */
end_comment

begin_comment
comment|/* ************************ */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|stardent
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|M_MACHINE
argument_list|)
end_if

begin_define
define|#
directive|define
name|M_MACHINE
value|"Stardent"
end_define

begin_define
define|#
directive|define
name|M_OS
value|USG
end_define

begin_undef
undef|#
directive|undef
name|HAVE_GETWD
end_undef

begin_undef
undef|#
directive|undef
name|HAVE_ALLOCA
end_undef

begin_define
define|#
directive|define
name|HAVE_SYS_SIGLIST
end_define

begin_define
define|#
directive|define
name|USE_TERMCAP_EMULATION
end_define

begin_define
define|#
directive|define
name|VOID_SIGHANDLER
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* stardent */
end_comment

begin_comment
comment|/* ************************ */
end_comment

begin_comment
comment|/*			    */
end_comment

begin_comment
comment|/*	Concurrent	    */
end_comment

begin_comment
comment|/*			    */
end_comment

begin_comment
comment|/* ************************ */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|concurrent
argument_list|)
end_if

begin_comment
comment|/* Use the BSD universe (`universe ucb') */
end_comment

begin_define
define|#
directive|define
name|M_MACHINE
value|"Concurrent"
end_define

begin_define
define|#
directive|define
name|M_OS
value|Bsd
end_define

begin_define
define|#
directive|define
name|HAVE_SYS_SIGLIST
end_define

begin_define
define|#
directive|define
name|HAVE_SETLINEBUF
end_define

begin_define
define|#
directive|define
name|HAVE_GETGROUPS
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* concurrent */
end_comment

begin_comment
comment|/* **************************************************************** */
end_comment

begin_comment
comment|/*                                                                  */
end_comment

begin_comment
comment|/*             Honeywell Bull X20 (lele@idea.sublink.org)	    */
end_comment

begin_comment
comment|/*                                                                  */
end_comment

begin_comment
comment|/* **************************************************************** */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|hbullx20
argument_list|)
end_if

begin_define
define|#
directive|define
name|M_MACHINE
value|"Honeywell"
end_define

begin_define
define|#
directive|define
name|M_OS
value|USG
end_define

begin_define
define|#
directive|define
name|SYSDEP_CFLAGS
value|-DUSG
end_define

begin_comment
comment|/* Bull x20 needs -lposix for struct dirent. */
end_comment

begin_define
define|#
directive|define
name|REQUIRED_LIBRARIES
value|-lPW -lposix
end_define

begin_define
define|#
directive|define
name|HAVE_VFPRINTF
end_define

begin_define
define|#
directive|define
name|VOID_SIGHANDLER
end_define

begin_define
define|#
directive|define
name|USE_TERMCAP_EMULATION
end_define

begin_undef
undef|#
directive|undef
name|HAVE_GETWD
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* hbullx20 */
end_comment

begin_comment
comment|/* ************************ */
end_comment

begin_comment
comment|/*			    */
end_comment

begin_comment
comment|/*    Cadmus (tested once)  */
end_comment

begin_comment
comment|/*			    */
end_comment

begin_comment
comment|/* ************************ */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|cadmus
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|M_MACHINE
argument_list|)
end_if

begin_define
define|#
directive|define
name|M_MACHINE
value|"cadmus"
end_define

begin_define
define|#
directive|define
name|M_OS
value|BrainDeath
end_define

begin_comment
comment|/* By Far, the worst yet. */
end_comment

begin_define
define|#
directive|define
name|SYSDEP_CFLAGS
value|-DUSG
end_define

begin_define
define|#
directive|define
name|HAVE_VFPRINTF
end_define

begin_define
define|#
directive|define
name|VOID_SIGHANDLER
end_define

begin_define
define|#
directive|define
name|USE_TERMCAP_EMULATION
end_define

begin_undef
undef|#
directive|undef
name|HAVE_GETWD
end_undef

begin_undef
undef|#
directive|undef
name|HAVE_ALLOCA
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* cadmus */
end_comment

begin_comment
comment|/* ************************ */
end_comment

begin_comment
comment|/*			    */
end_comment

begin_comment
comment|/*	MagicStation	    */
end_comment

begin_comment
comment|/*			    */
end_comment

begin_comment
comment|/* ************************ */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|MagicStation
argument_list|)
end_if

begin_define
define|#
directive|define
name|M_MACHINE
value|"MagicStation"
end_define

begin_define
define|#
directive|define
name|M_OS
value|USG
end_define

begin_define
define|#
directive|define
name|SYSDEP_CFLAGS
value|-DUSGr4
end_define

begin_define
define|#
directive|define
name|HAVE_GETGROUPS
end_define

begin_define
define|#
directive|define
name|HAVE_STRERROR
end_define

begin_define
define|#
directive|define
name|VOID_SIGHANDLER
end_define

begin_undef
undef|#
directive|undef
name|HAVE_ALLOCA
end_undef

begin_undef
undef|#
directive|undef
name|HAVE_GETWD
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* MagicStation */
end_comment

begin_comment
comment|/* **************************************************************** */
end_comment

begin_comment
comment|/*								    */
end_comment

begin_comment
comment|/*			Generic Entry   			    */
end_comment

begin_comment
comment|/*								    */
end_comment

begin_comment
comment|/* **************************************************************** */
end_comment

begin_comment
comment|/* Use this entry for your machine if it isn't represented here.  It    is loosely based on a Vax running Bsd. */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|M_MACHINE
argument_list|)
end_if

begin_define
define|#
directive|define
name|UNKNOWN_MACHINE
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|UNKNOWN_MACHINE
end_ifdef

begin_define
define|#
directive|define
name|M_MACHINE
value|"UNKNOWN_MACHINE"
end_define

begin_define
define|#
directive|define
name|M_OS
value|UNKNOWN_OS
end_define

begin_comment
comment|/* Required libraries for building on this system. */
end_comment

begin_define
define|#
directive|define
name|REQUIRED_LIBRARIES
end_define

begin_comment
comment|/* Define HAVE_SYS_SIGLIST if your system has sys_siglist[]. */
end_comment

begin_define
define|#
directive|define
name|HAVE_SYS_SIGLIST
end_define

begin_comment
comment|/* Undef HAVE_ALLOCA if you are not using Gcc, and neither your library    nor compiler has a version of alloca ().  In that case, we will use    our version of alloca () in alloca.c */
end_comment

begin_comment
comment|/* #undef HAVE_ALLOCA */
end_comment

begin_comment
comment|/* Undef USE_GNU_MALLOC if there appear to be library conflicts, or if you    especially desire to use your OS's version of malloc () and friends.  We    reccommend against this because GNU Malloc has debugging code built in. */
end_comment

begin_define
define|#
directive|define
name|USE_GNU_MALLOC
end_define

begin_comment
comment|/* Define USE_GNU_TERMCAP if you want to use the GNU termcap library    instead of your system termcap library. */
end_comment

begin_comment
comment|/* #define USE_GNU_TERMCAP */
end_comment

begin_comment
comment|/* Define HAVE_SETLINEBUF if your machine has the setlinebuf ()    stream library call.  Otherwise, setvbuf () will be used.  If    neither of them work, you can edit in your own buffer control    based upon your machines capabilities. */
end_comment

begin_define
define|#
directive|define
name|HAVE_SETLINEBUF
end_define

begin_comment
comment|/* Define HAVE_VFPRINTF if your machines has the vfprintf () library    call.  Otherwise, printf will be used.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_VFPRINTF
end_define

begin_comment
comment|/* Define HAVE_GETGROUPS if your OS allows you to be in multiple    groups simultaneously by supporting the `getgroups' system call. */
end_comment

begin_comment
comment|/* #define HAVE_GETGROUPS */
end_comment

begin_comment
comment|/* Define SYSDEP_CFLAGS to be the flags to cc that make your compiler    work.  For example, `-ma' on the RT makes alloca () work. */
end_comment

begin_define
define|#
directive|define
name|SYSDEP_CFLAGS
end_define

begin_comment
comment|/* Define HAVE_STRERROR if your system supplies a definition for strerror ()    in the C library, or a macro in a header file. */
end_comment

begin_comment
comment|/* #define HAVE_STRERROR */
end_comment

begin_comment
comment|/* If your system does not supply /usr/lib/libtermcap.a, but includes    the termcap routines as a part of the curses library, then define    this.  This is the case on some System V machines. */
end_comment

begin_comment
comment|/* #define USE_TERMCAP_EMULATION */
end_comment

begin_comment
comment|/* Define VOID_SIGHANDLER if your system's signal () returns a pointer to    a function returning void. */
end_comment

begin_comment
comment|/* #define VOID_SIGHANDLER */
end_comment

begin_comment
comment|/* Define EXTRA_LIB_SEARCH_PATH if your required libraries (or standard)    ones for that matter) are not normally in the ld search path.  For    example, some machines require /usr/ucblib in the ld search path so    that they can use -lucb. */
end_comment

begin_comment
comment|/* #define EXTRA_LIB_SEARCH_PATH /usr/ucblib */
end_comment

begin_comment
comment|/* Define SEARCH_LIB_NEEDS_SPACE if your native ld requires a space after    the -L argument, which gives the name of an alternate directory to search    for libraries specified with -llib.  For example, the HPUX ld requires    this:    	-L lib/readline -lreadline    instead of: 	-Llib/readline -lreadline  */
end_comment

begin_comment
comment|/* #define SEARCH_LIB_NEEDS_SPACE */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* UNKNOWN_MACHINE */
end_comment

end_unit

