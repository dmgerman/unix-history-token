begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * vi configuration file  */
end_comment

begin_define
define|#
directive|define
name|BSD
value|1
end_define

begin_comment
comment|/* All undefined symbols are defined to zero here, to allow for older    */
end_comment

begin_comment
comment|/* compilers which dont understand #if defined() or #if UNDEFINED_SYMBOL */
end_comment

begin_define
define|#
directive|define
name|UNIXV
value|0
end_define

begin_comment
comment|/* UNIX - AT&T SYSV */
end_comment

begin_define
define|#
directive|define
name|UNIX7
value|0
end_define

begin_comment
comment|/* UNIX - version 7 */
end_comment

begin_define
define|#
directive|define
name|MSDOS
value|0
end_define

begin_comment
comment|/* PC		*/
end_comment

begin_define
define|#
directive|define
name|TOS
value|0
end_define

begin_comment
comment|/* Atari ST	*/
end_comment

begin_define
define|#
directive|define
name|AMIGA
value|0
end_define

begin_comment
comment|/* Commodore Amiga */
end_comment

begin_define
define|#
directive|define
name|OSK
value|0
end_define

begin_comment
comment|/* OS-9 / 68k */
end_comment

begin_define
define|#
directive|define
name|COHERENT
value|0
end_define

begin_comment
comment|/* Coherent */
end_comment

begin_define
define|#
directive|define
name|MINIX
value|0
end_define

begin_define
define|#
directive|define
name|ANY_UNIX
value|1
end_define

begin_comment
comment|/*************************** compilers **************************************/
end_comment

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

begin_comment
comment|/*************************** functions depending on OS *********************/
end_comment

begin_comment
comment|/* Only MSDOS, TOS, and OS9 need a special function for reading from the  * keyboard.  All others just read from file descriptor 0.  */
end_comment

begin_if
if|#
directive|if
operator|!
name|MSDOS
operator|&&
operator|!
name|TOS
operator|&&
operator|!
name|OSK
end_if

begin_define
define|#
directive|define
name|ttyread
parameter_list|(
name|buf
parameter_list|,
name|len
parameter_list|)
value|read(0, buf, (unsigned)len)
end_define

begin_comment
comment|/* raw read */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|!
name|TOS
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

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
specifier|extern
name|char
modifier|*
name|strchr
parameter_list|()
function_decl|;
end_function_decl

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

begin_if
if|#
directive|if
name|BSD
end_if

begin_function_decl
specifier|extern
name|void
modifier|*
name|malloc
parameter_list|()
function_decl|;
end_function_decl

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

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Most compilers could benefit from using the "register" storage class */
end_comment

begin_if
if|#
directive|if
literal|1
end_if

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

begin_comment
comment|/******************* Names of files and environment vars **********************/
end_comment

begin_define
define|#
directive|define
name|TMPDIR
value|"/var/tmp"
end_define

begin_define
define|#
directive|define
name|TMPNAME
value|"%s/elv%x%04x%03x"
end_define

begin_comment
comment|/* temp file */
end_comment

begin_define
define|#
directive|define
name|CUTNAME
value|"%s/elv_%04x%03x"
end_define

begin_comment
comment|/* cut buffer's temp file */
end_comment

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
name|EXINIT
end_ifndef

begin_define
define|#
directive|define
name|EXINIT
value|"EXINIT"
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
value|"/bin/sh"
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
name|TAGS
end_ifndef

begin_define
define|#
directive|define
name|TAGS
value|"tags"
end_define

begin_comment
comment|/* tags file */
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
value|"%s/elv%x%04x.%03x"
end_define

begin_comment
comment|/* temp file */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|CUTNAME
end_ifndef

begin_define
define|#
directive|define
name|CUTNAME
value|"%s/elv_%04x.%03x"
end_define

begin_comment
comment|/* cut buffer's temp file */
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

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|HMEXRC
end_ifndef

begin_if
if|#
directive|if
operator|!
name|MSDOS
operator|&&
operator|!
name|TOS
end_if

begin_define
define|#
directive|define
name|HMEXRC
value|EXRC
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
value|"errlist"
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
name|MAXMAPS
end_ifndef

begin_define
define|#
directive|define
name|MAXMAPS
value|20
end_define

begin_comment
comment|/* number of :map keys */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|MAXDIGS
end_ifndef

begin_define
define|#
directive|define
name|MAXDIGS
value|30
end_define

begin_comment
comment|/* number of :digraph combos */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|MAXABBR
end_ifndef

begin_define
define|#
directive|define
name|MAXABBR
value|20
end_define

begin_comment
comment|/* number of :abbr entries */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|LETS_GET_SMALL
end_ifdef

begin_define
define|#
directive|define
name|NO_CHARATTR
end_define

begin_define
define|#
directive|define
name|NO_DIGRAPH
end_define

begin_define
define|#
directive|define
name|NO_SENTENCE
end_define

begin_define
define|#
directive|define
name|NO_EXTENSIONS
end_define

begin_define
define|#
directive|define
name|NO_MAGIC
end_define

begin_define
define|#
directive|define
name|NO_ERRLIST
end_define

begin_define
define|#
directive|define
name|NO_MODELINE
end_define

begin_define
define|#
directive|define
name|NO_SHOWMATCH
end_define

begin_define
define|#
directive|define
name|NO_SHOWMODE
end_define

begin_define
define|#
directive|define
name|NO_OPTCOLS
end_define

begin_define
define|#
directive|define
name|NO_MKEXRC
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

