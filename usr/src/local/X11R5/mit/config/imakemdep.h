begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * $XConsortium: imakemdep.h,v 1.38 91/08/25 11:36:39 rws Exp $  *   * This file contains machine-dependent constants for the imake utility.  * When porting imake, read each of the steps below and add in any necessary  * definitions.  Do *not* edit ccimake.c or imake.c!  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|CCIMAKE
end_ifdef

begin_comment
comment|/*  * Step 1:  imake_ccflags  *     Define any special flags that will be needed to get imake.c to compile.  *     These will be passed to the compile along with the contents of the  *     make variable BOOTSTRAPCFLAGS.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|hpux
end_ifdef

begin_ifdef
ifdef|#
directive|ifdef
name|hp9000s800
end_ifdef

begin_define
define|#
directive|define
name|imake_ccflags
value|"-DSYSV"
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|imake_ccflags
value|"-Wc,-Nd4000,-Ns3000 -DSYSV"
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
name|macII
argument_list|)
operator|||
name|defined
argument_list|(
name|_AUX_SOURCE
argument_list|)
end_if

begin_define
define|#
directive|define
name|imake_ccflags
value|"-DmacII -DSYSV"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|stellar
end_ifdef

begin_define
define|#
directive|define
name|imake_ccflags
value|"-DSYSV"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|att
end_ifdef

begin_define
define|#
directive|define
name|imake_ccflags
value|"-Xc -DSVR4"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|sony
end_ifdef

begin_ifdef
ifdef|#
directive|ifdef
name|SYSTYPE_SYSV
end_ifdef

begin_define
define|#
directive|define
name|imake_ccflags
value|"-DSVR4"
end_define

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_if
if|#
directive|if
name|NEWSOS
operator|<
literal|41
end_if

begin_define
define|#
directive|define
name|imake_ccflags
value|"-Dbsd43 -DNOSTDHDRS"
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|imake_ccflags
value|"-Dbsd43"
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
name|CRAY
end_ifdef

begin_comment
comment|/* -DX_NOT_STDC_ENV is just so we can bootstrap with cc instead of scc */
end_comment

begin_define
define|#
directive|define
name|imake_ccflags
value|"-DSYSV -DUSG -DX_NOT_STDC_ENV"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|_IBMR2
end_ifdef

begin_define
define|#
directive|define
name|imake_ccflags
value|"-Daix -DSYSV -D_IBMR2"
end_define

begin_else
else|#
directive|else
end_else

begin_ifdef
ifdef|#
directive|ifdef
name|aix
end_ifdef

begin_define
define|#
directive|define
name|imake_ccflags
value|"-Daix -DSYSV"
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
name|Mips
end_ifdef

begin_if
if|#
directive|if
name|defined
argument_list|(
name|SYSTYPE_BSD
argument_list|)
operator|||
name|defined
argument_list|(
name|BSD
argument_list|)
operator|||
name|defined
argument_list|(
name|BSD43
argument_list|)
end_if

begin_define
define|#
directive|define
name|imake_ccflags
value|"-DMips -DBSD43"
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|imake_ccflags
value|"-DMips -DSYSV"
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
name|is68k
end_ifdef

begin_define
define|#
directive|define
name|imake_ccflags
value|"-Dluna -Duniosb"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|SYSV386
end_ifdef

begin_ifdef
ifdef|#
directive|ifdef
name|SVR4
end_ifdef

begin_define
define|#
directive|define
name|imake_ccflags
value|"-Xc -DSVR4"
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|imake_ccflags
value|"-DSYSV"
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
name|__convex__
end_ifdef

begin_define
define|#
directive|define
name|imake_ccflags
value|"-fn -tm c1"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|apollo
end_ifdef

begin_define
define|#
directive|define
name|imake_ccflags
value|"-DX_NOT_POSIX"
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
comment|/* not CCIMAKE */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|MAKEDEPEND
end_ifndef

begin_comment
comment|/*  * Step 2:  dup2  *     If your OS doesn't have a dup2() system call to duplicate one file  *     descriptor onto another, define such a mechanism here (if you don't  *     already fall under the existing category(ies).  */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|SYSV
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|CRAY
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|Mips
argument_list|)
end_if

begin_define
define|#
directive|define
name|dup2
parameter_list|(
name|fd1
parameter_list|,
name|fd2
parameter_list|)
value|((fd1 == fd2) ? fd1 : (close(fd2), \ 					       fcntl(fd1, F_DUPFD, fd2)))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Step 3:  FIXUP_CPP_WHITESPACE  *     If your cpp collapses tabs macro expansions into a single space and  *     replaces escaped newlines with a space, define this symbol.  This will  *     cause imake to attempt to patch up the generated Makefile by looking  *     for lines that have colons in them (this is why the rules file escapes  *     all colons).  One way to tell if you need this is to see whether or not  *     your Makefiles have no tabs in them and lots of @@ strings.  */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|sun
argument_list|)
operator|||
name|defined
argument_list|(
name|SYSV
argument_list|)
operator|||
name|defined
argument_list|(
name|SVR4
argument_list|)
operator|||
name|defined
argument_list|(
name|hcx
argument_list|)
end_if

begin_define
define|#
directive|define
name|FIXUP_CPP_WHITESPACE
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Step 4:  DEFAULT_CPP  *     If the C preprocessor does not live in /lib/cpp, set this symbol to   *     the appropriate location.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|apollo
end_ifdef

begin_define
define|#
directive|define
name|DEFAULT_CPP
value|"/usr/lib/cpp"
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
name|_IBMR2
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|DEFAULT_CPP
argument_list|)
end_if

begin_define
define|#
directive|define
name|DEFAULT_CPP
value|"/usr/lpp/X11/Xamples/util/cpp/cpp"
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
name|hp9000
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|DEFAULT_CPP
argument_list|)
end_if

begin_define
define|#
directive|define
name|DEFAULT_CPP
value|"/usr/libexec/cpp"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Step 5:  cpp_argv  *     The following table contains the cpp flags that should be passed to   *     cpp whenever a Makefile is being generated.  If your preprocessor   *     doesn't predefine any unique symbols, choose one and add it to the  *     end of this table.  Then, do the following:  *   *         a.  Use this symbol at the top of Imake.tmpl when setting MacroFile.  *         b.  Put this symbol in the definition of BootstrapCFlags in your  *<platform>.cf file.  *         c.  When doing a make World, always add "BOOTSTRAPCFLAGS=-Dsymbol"   *             to the end of the command line.  *   *     Note that you may define more than one symbols (useful for platforms   *     that support multiple operating systems).  */
end_comment

begin_define
define|#
directive|define
name|ARGUMENTS
value|50
end_define

begin_comment
comment|/* number of arguments in various arrays */
end_comment

begin_decl_stmt
name|char
modifier|*
name|cpp_argv
index|[
name|ARGUMENTS
index|]
init|=
block|{
ifdef|#
directive|ifdef
name|USE_CC_E
literal|"cc"
block|,
comment|/* replaced by the actual cpp program to exec */
literal|"-E"
block|,
else|#
directive|else
literal|"cpp"
block|,
comment|/* replaced by the actual cpp program to exec */
endif|#
directive|endif
comment|/* USE_CC_E */
literal|"-I."
block|,
comment|/* add current directory to include path */
ifdef|#
directive|ifdef
name|unix
literal|"-Uunix"
block|,
comment|/* remove unix symbol so that filename unix.c okay */
endif|#
directive|endif
ifdef|#
directive|ifdef
name|hp9000
literal|"-traditional"
block|,
endif|#
directive|endif
ifdef|#
directive|ifdef
name|M4330
literal|"-DM4330"
block|,
comment|/* Tektronix */
endif|#
directive|endif
ifdef|#
directive|ifdef
name|M4310
literal|"-DM4310"
block|,
comment|/* Tektronix */
endif|#
directive|endif
if|#
directive|if
name|defined
argument_list|(
name|macII
argument_list|)
operator|||
name|defined
argument_list|(
name|_AUX_SOURCE
argument_list|)
literal|"-DmacII"
block|,
comment|/* Apple A/UX */
endif|#
directive|endif
ifdef|#
directive|ifdef
name|att
literal|"-Datt"
block|,
comment|/* AT&T products */
endif|#
directive|endif
ifdef|#
directive|ifdef
name|sony
literal|"-Dsony"
block|,
comment|/* Sony */
ifndef|#
directive|ifndef
name|SYSTYPE_SYSV
literal|"-Dbsd43"
block|,
endif|#
directive|endif
endif|#
directive|endif
ifdef|#
directive|ifdef
name|_IBMR2
literal|"-D_IBMR2"
block|,
comment|/* IBM RS-6000 (we ensured that aix is defined above */
ifndef|#
directive|ifndef
name|aix
define|#
directive|define
name|aix
comment|/* allow BOOTSTRAPCFLAGS="-D_IBMR2" */
endif|#
directive|endif
endif|#
directive|endif
comment|/* _IBMR2 */
ifdef|#
directive|ifdef
name|aix
literal|"-Daix"
block|,
comment|/* AIX instead of AOS */
ifndef|#
directive|ifndef
name|ibm
define|#
directive|define
name|ibm
comment|/* allow BOOTSTRAPCFLAGS="-Daix" */
endif|#
directive|endif
endif|#
directive|endif
comment|/* aix */
ifdef|#
directive|ifdef
name|ibm
literal|"-Dibm"
block|,
comment|/* IBM PS/2 and RT under both AOS and AIX */
endif|#
directive|endif
ifdef|#
directive|ifdef
name|luna
literal|"-Dluna"
block|,
comment|/* OMRON luna 68K and 88K */
ifdef|#
directive|ifdef
name|luna1
literal|"-Dluna1"
block|,
endif|#
directive|endif
ifdef|#
directive|ifdef
name|luna88k
comment|/* need not on UniOS-Mach Vers. 1.13 */
literal|"-traditional"
block|,
comment|/* for some older version            */
endif|#
directive|endif
comment|/* instead of "-DXCOMM=\\#"          */
ifdef|#
directive|ifdef
name|uniosb
literal|"-Duniosb"
block|,
endif|#
directive|endif
ifdef|#
directive|ifdef
name|uniosu
literal|"-Duniosu"
block|,
endif|#
directive|endif
endif|#
directive|endif
comment|/* luna */
ifdef|#
directive|ifdef
name|CRAY
comment|/* Cray */
literal|"-Ucray"
block|,
endif|#
directive|endif
ifdef|#
directive|ifdef
name|Mips
literal|"-DMips"
block|,
comment|/* Define and use Mips for Mips Co. OS/mach. */
if|#
directive|if
name|defined
argument_list|(
name|SYSTYPE_BSD
argument_list|)
operator|||
name|defined
argument_list|(
name|BSD
argument_list|)
operator|||
name|defined
argument_list|(
name|BSD43
argument_list|)
literal|"-DBSD43"
block|,
comment|/* Mips RISCOS supports two environments */
else|#
directive|else
literal|"-DSYSV"
block|,
comment|/* System V environment is the default */
endif|#
directive|endif
endif|#
directive|endif
comment|/* Mips */
ifdef|#
directive|ifdef
name|MOTOROLA
literal|"-DMOTOROLA"
block|,
comment|/* Motorola Delta Systems */
ifdef|#
directive|ifdef
name|SYSV
literal|"-DSYSV"
block|,
endif|#
directive|endif
ifdef|#
directive|ifdef
name|SVR4
literal|"-DSVR4"
block|,
endif|#
directive|endif
endif|#
directive|endif
comment|/* MOTOROLA */
ifdef|#
directive|ifdef
name|SYSV386
comment|/* System V/386 folks */
literal|"-DSYSV386"
block|,
ifdef|#
directive|ifdef
name|SVR4
literal|"-DSVR4"
block|,
endif|#
directive|endif
ifdef|#
directive|ifdef
name|ISC
literal|"-DISC"
block|,
comment|/* ISC 2.2.1 */
endif|#
directive|endif
ifdef|#
directive|ifdef
name|SCO
literal|"-DSCO"
block|,
endif|#
directive|endif
ifdef|#
directive|ifdef
name|ESIX
literal|"-DESIX"
block|,
endif|#
directive|endif
ifdef|#
directive|ifdef
name|ATT
literal|"-DATT"
block|,
endif|#
directive|endif
ifdef|#
directive|ifdef
name|DELL
literal|"-DDELL"
block|,
endif|#
directive|endif
endif|#
directive|endif
block|}
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* else MAKEDEPEND */
end_comment

begin_comment
comment|/*  * Step 6:  predefs  *     If your compiler and/or preprocessor define any specific symbols, add  *     them to the the following table.  The definition of struct symtab is  *     in util/makedepend/def.h.  */
end_comment

begin_decl_stmt
name|struct
name|symtab
name|predefs
index|[]
init|=
block|{
ifdef|#
directive|ifdef
name|apollo
block|{
literal|"apollo"
block|,
literal|"1"
block|}
block|,
endif|#
directive|endif
ifdef|#
directive|ifdef
name|ibm032
block|{
literal|"ibm032"
block|,
literal|"1"
block|}
block|,
endif|#
directive|endif
ifdef|#
directive|ifdef
name|ibm
block|{
literal|"ibm"
block|,
literal|"1"
block|}
block|,
endif|#
directive|endif
ifdef|#
directive|ifdef
name|aix
block|{
literal|"aix"
block|,
literal|"1"
block|}
block|,
endif|#
directive|endif
ifdef|#
directive|ifdef
name|sun
block|{
literal|"sun"
block|,
literal|"1"
block|}
block|,
endif|#
directive|endif
ifdef|#
directive|ifdef
name|hpux
block|{
literal|"hpux"
block|,
literal|"1"
block|}
block|,
endif|#
directive|endif
ifdef|#
directive|ifdef
name|hp9000
block|{
literal|"hp9000"
block|,
literal|"1"
block|}
block|,
endif|#
directive|endif
ifdef|#
directive|ifdef
name|vax
block|{
literal|"vax"
block|,
literal|"1"
block|}
block|,
endif|#
directive|endif
ifdef|#
directive|ifdef
name|VMS
block|{
literal|"VMS"
block|,
literal|"1"
block|}
block|,
endif|#
directive|endif
ifdef|#
directive|ifdef
name|cray
block|{
literal|"cray"
block|,
literal|"1"
block|}
block|,
endif|#
directive|endif
ifdef|#
directive|ifdef
name|CRAY
block|{
literal|"CRAY"
block|,
literal|"1"
block|}
block|,
endif|#
directive|endif
ifdef|#
directive|ifdef
name|att
block|{
literal|"att"
block|,
literal|"1"
block|}
block|,
endif|#
directive|endif
ifdef|#
directive|ifdef
name|mips
block|{
literal|"mips"
block|,
literal|"1"
block|}
block|,
endif|#
directive|endif
ifdef|#
directive|ifdef
name|ultrix
block|{
literal|"ultrix"
block|,
literal|"1"
block|}
block|,
endif|#
directive|endif
ifdef|#
directive|ifdef
name|stellar
block|{
literal|"stellar"
block|,
literal|"1"
block|}
block|,
endif|#
directive|endif
ifdef|#
directive|ifdef
name|mc68000
block|{
literal|"mc68000"
block|,
literal|"1"
block|}
block|,
endif|#
directive|endif
ifdef|#
directive|ifdef
name|mc68020
block|{
literal|"mc68020"
block|,
literal|"1"
block|}
block|,
endif|#
directive|endif
ifdef|#
directive|ifdef
name|__GNUC__
block|{
literal|"__GNUC__"
block|,
literal|"1"
block|}
block|,
endif|#
directive|endif
if|#
directive|if
name|__STDC__
block|{
literal|"__STDC__"
block|,
literal|"1"
block|}
block|,
endif|#
directive|endif
ifdef|#
directive|ifdef
name|__HIGHC__
block|{
literal|"__HIGHC__"
block|,
literal|"1"
block|}
block|,
endif|#
directive|endif
ifdef|#
directive|ifdef
name|CMU
block|{
literal|"CMU"
block|,
literal|"1"
block|}
block|,
endif|#
directive|endif
ifdef|#
directive|ifdef
name|luna
block|{
literal|"luna"
block|,
literal|"1"
block|}
block|,
ifdef|#
directive|ifdef
name|luna1
block|{
literal|"luna1"
block|,
literal|"1"
block|}
block|,
endif|#
directive|endif
ifdef|#
directive|ifdef
name|luna2
block|{
literal|"luna2"
block|,
literal|"1"
block|}
block|,
endif|#
directive|endif
ifdef|#
directive|ifdef
name|luna88k
block|{
literal|"luna88k"
block|,
literal|"1"
block|}
block|,
endif|#
directive|endif
ifdef|#
directive|ifdef
name|uniosb
block|{
literal|"uniosb"
block|,
literal|"1"
block|}
block|,
endif|#
directive|endif
ifdef|#
directive|ifdef
name|uniosu
block|{
literal|"uniosu"
block|,
literal|"1"
block|}
block|,
endif|#
directive|endif
endif|#
directive|endif
ifdef|#
directive|ifdef
name|ieeep754
block|{
literal|"ieeep754"
block|,
literal|"1"
block|}
block|,
endif|#
directive|endif
ifdef|#
directive|ifdef
name|is68k
block|{
literal|"is68k"
block|,
literal|"1"
block|}
block|,
endif|#
directive|endif
ifdef|#
directive|ifdef
name|m68k
block|{
literal|"m68k"
block|,
literal|"1"
block|}
block|,
endif|#
directive|endif
ifdef|#
directive|ifdef
name|m88k
block|{
literal|"m88k"
block|,
literal|"1"
block|}
block|,
endif|#
directive|endif
ifdef|#
directive|ifdef
name|bsd43
block|{
literal|"bsd43"
block|,
literal|"1"
block|}
block|,
endif|#
directive|endif
ifdef|#
directive|ifdef
name|hcx
block|{
literal|"hcx"
block|,
literal|1
block|}
block|,
endif|#
directive|endif
comment|/* add any additional symbols before this line */
block|{
name|NULL
block|,
name|NULL
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* MAKEDEPEND */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CCIMAKE */
end_comment

end_unit

