begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_comment
comment|/* defines.h.  Generated from defines.h.in by configure.  */
end_comment

begin_comment
comment|/* defines.h.in.  Generated from configure.ac by autoheader.  */
end_comment

begin_comment
comment|/* Unix definition file for less.  -*- C -*-  *  * This file has 3 sections:  * User preferences.  * Settings always true on Unix.  * Settings automatically determined by configure.  *  * * * * * *  WARNING  * * * * * *  * If you edit defines.h by hand, do "touch stamp-h" before you run make  * so config.status doesn't overwrite your changes.  */
end_comment

begin_comment
comment|/* User preferences.  */
end_comment

begin_comment
comment|/*  * SECURE is 1 if you wish to disable a bunch of features in order to  * be safe to run by unprivileged users.  * SECURE_COMPILE is set by the --with-secure configure option.  */
end_comment

begin_define
define|#
directive|define
name|SECURE
value|SECURE_COMPILE
end_define

begin_comment
comment|/*  * SHELL_ESCAPE is 1 if you wish to allow shell escapes.  * (This is possible only if your system supplies the system() function.)  */
end_comment

begin_define
define|#
directive|define
name|SHELL_ESCAPE
value|(!SECURE)
end_define

begin_comment
comment|/*  * EXAMINE is 1 if you wish to allow examining files by name from within less.  */
end_comment

begin_define
define|#
directive|define
name|EXAMINE
value|(!SECURE)
end_define

begin_comment
comment|/*  * TAB_COMPLETE_FILENAME is 1 if you wish to allow the TAB key  * to complete filenames at prompts.  */
end_comment

begin_define
define|#
directive|define
name|TAB_COMPLETE_FILENAME
value|(!SECURE)
end_define

begin_comment
comment|/*  * CMD_HISTORY is 1 if you wish to allow keys to cycle through  * previous commands at prompts.  */
end_comment

begin_define
define|#
directive|define
name|CMD_HISTORY
value|1
end_define

begin_comment
comment|/*  * HILITE_SEARCH is 1 if you wish to have search targets to be   * displayed in standout mode.  */
end_comment

begin_define
define|#
directive|define
name|HILITE_SEARCH
value|1
end_define

begin_comment
comment|/*  * EDITOR is 1 if you wish to allow editor invocation (the "v" command).  * (This is possible only if your system supplies the system() function.)  * EDIT_PGM is the name of the (default) editor to be invoked.  */
end_comment

begin_define
define|#
directive|define
name|EDITOR
value|(!SECURE)
end_define

begin_comment
comment|/*  * TAGS is 1 if you wish to support tag files.  */
end_comment

begin_define
define|#
directive|define
name|TAGS
value|(!SECURE)
end_define

begin_comment
comment|/*  * USERFILE is 1 if you wish to allow a .less file to specify   * user-defined key bindings.  */
end_comment

begin_define
define|#
directive|define
name|USERFILE
value|(!SECURE)
end_define

begin_comment
comment|/*  * GLOB is 1 if you wish to have shell metacharacters expanded in filenames.  * This will generally work if your system provides the "popen" function  * and the "echo" shell command.  */
end_comment

begin_define
define|#
directive|define
name|GLOB
value|(!SECURE)
end_define

begin_comment
comment|/*  * PIPEC is 1 if you wish to have the "|" command  * which allows the user to pipe data into a shell command.  */
end_comment

begin_define
define|#
directive|define
name|PIPEC
value|(!SECURE)
end_define

begin_comment
comment|/*  * LOGFILE is 1 if you wish to allow the -l option (to create log files).  */
end_comment

begin_define
define|#
directive|define
name|LOGFILE
value|(!SECURE)
end_define

begin_comment
comment|/*  * GNU_OPTIONS is 1 if you wish to support the GNU-style command  * line options --help and --version.  */
end_comment

begin_define
define|#
directive|define
name|GNU_OPTIONS
value|1
end_define

begin_comment
comment|/*  * ONLY_RETURN is 1 if you want RETURN to be the only input which  * will continue past an error message.  * Otherwise, any key will continue past an error message.  */
end_comment

begin_define
define|#
directive|define
name|ONLY_RETURN
value|0
end_define

begin_comment
comment|/*  * LESSKEYFILE is the filename of the default lesskey output file   * (in the HOME directory).  * LESSKEYFILE_SYS is the filename of the system-wide lesskey output file.  * DEF_LESSKEYINFILE is the filename of the default lesskey input   * (in the HOME directory).  * LESSHISTFILE is the filename of the history file  * (in the HOME directory).  */
end_comment

begin_define
define|#
directive|define
name|LESSKEYFILE
value|".less"
end_define

begin_define
define|#
directive|define
name|LESSKEYFILE_SYS
value|"/etc/lesskey"
end_define

begin_define
define|#
directive|define
name|DEF_LESSKEYINFILE
value|".lesskey"
end_define

begin_define
define|#
directive|define
name|LESSHISTFILE
value|".lesshst"
end_define

begin_comment
comment|/* Settings always true on Unix.  */
end_comment

begin_comment
comment|/*  * Define MSDOS_COMPILER if compiling under Microsoft C.  */
end_comment

begin_define
define|#
directive|define
name|MSDOS_COMPILER
value|0
end_define

begin_comment
comment|/*  * Pathname separator character.  */
end_comment

begin_define
define|#
directive|define
name|PATHNAME_SEP
value|"/"
end_define

begin_comment
comment|/*  * The value returned from tgetent on success.  * Some HP-UX systems return 0 on success.  */
end_comment

begin_define
define|#
directive|define
name|TGETENT_OK
value|1
end_define

begin_comment
comment|/*  * HAVE_ANSI_PROTOS	is 1 if your compiler supports ANSI function prototypes.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_ANSI_PROTOS
value|1
end_define

begin_comment
comment|/*  * HAVE_SYS_TYPES_H is 1 if your system has<sys/types.h>.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_SYS_TYPES_H
value|1
end_define

begin_comment
comment|/*  * Define if you have the<sgstat.h> header file.  */
end_comment

begin_comment
comment|/* #undef HAVE_SGSTAT_H */
end_comment

begin_comment
comment|/*  * HAVE_PERROR is 1 if your system has the perror() call.  * (Actually, if it has sys_errlist, sys_nerr and errno.)  */
end_comment

begin_define
define|#
directive|define
name|HAVE_PERROR
value|1
end_define

begin_comment
comment|/*  * HAVE_TIME is 1 if your system has the time() call.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_TIME
value|1
end_define

begin_comment
comment|/*  * HAVE_SHELL is 1 if your system supports a SHELL command interpreter.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_SHELL
value|1
end_define

begin_comment
comment|/*  * Default shell metacharacters and meta-escape character.  */
end_comment

begin_define
define|#
directive|define
name|DEF_METACHARS
value|"; *?\t\n'\"()<>[]|&^`#\\$%=~"
end_define

begin_define
define|#
directive|define
name|DEF_METAESCAPE
value|"\\"
end_define

begin_comment
comment|/*   * HAVE_DUP is 1 if your system has the dup() call.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_DUP
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the memcpy() function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_MEMCPY
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the strchr() function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_STRCHR
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the strstr() function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_STRSTR
value|1
end_define

begin_comment
comment|/*  * Sizes of various buffers.  */
end_comment

begin_if
if|#
directive|if
literal|0
end_if

begin_comment
comment|/* old sizes for small memory machines */
end_comment

begin_define
define|#
directive|define
name|CMDBUF_SIZE
value|512
end_define

begin_comment
comment|/* Buffer for multichar commands */
end_comment

begin_define
define|#
directive|define
name|UNGOT_SIZE
value|100
end_define

begin_comment
comment|/* Max chars to unget() */
end_comment

begin_define
define|#
directive|define
name|LINEBUF_SIZE
value|1024
end_define

begin_comment
comment|/* Max size of line in input file */
end_comment

begin_define
define|#
directive|define
name|OUTBUF_SIZE
value|1024
end_define

begin_comment
comment|/* Output buffer */
end_comment

begin_define
define|#
directive|define
name|PROMPT_SIZE
value|200
end_define

begin_comment
comment|/* Max size of prompt string */
end_comment

begin_define
define|#
directive|define
name|TERMBUF_SIZE
value|2048
end_define

begin_comment
comment|/* Termcap buffer for tgetent */
end_comment

begin_define
define|#
directive|define
name|TERMSBUF_SIZE
value|1024
end_define

begin_comment
comment|/* Buffer to hold termcap strings */
end_comment

begin_define
define|#
directive|define
name|TAGLINE_SIZE
value|512
end_define

begin_comment
comment|/* Max size of line in tags file */
end_comment

begin_define
define|#
directive|define
name|TABSTOP_MAX
value|32
end_define

begin_comment
comment|/* Max number of custom tab stops */
end_comment

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* more reasonable sizes for modern machines */
end_comment

begin_define
define|#
directive|define
name|CMDBUF_SIZE
value|2048
end_define

begin_comment
comment|/* Buffer for multichar commands */
end_comment

begin_define
define|#
directive|define
name|UNGOT_SIZE
value|200
end_define

begin_comment
comment|/* Max chars to unget() */
end_comment

begin_define
define|#
directive|define
name|LINEBUF_SIZE
value|1024
end_define

begin_comment
comment|/* Initial max size of line in input file */
end_comment

begin_define
define|#
directive|define
name|OUTBUF_SIZE
value|1024
end_define

begin_comment
comment|/* Output buffer */
end_comment

begin_define
define|#
directive|define
name|PROMPT_SIZE
value|2048
end_define

begin_comment
comment|/* Max size of prompt string */
end_comment

begin_define
define|#
directive|define
name|TERMBUF_SIZE
value|2048
end_define

begin_comment
comment|/* Termcap buffer for tgetent */
end_comment

begin_define
define|#
directive|define
name|TERMSBUF_SIZE
value|1024
end_define

begin_comment
comment|/* Buffer to hold termcap strings */
end_comment

begin_define
define|#
directive|define
name|TAGLINE_SIZE
value|1024
end_define

begin_comment
comment|/* Max size of line in tags file */
end_comment

begin_define
define|#
directive|define
name|TABSTOP_MAX
value|128
end_define

begin_comment
comment|/* Max number of custom tab stops */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Settings automatically determined by configure.  */
end_comment

begin_comment
comment|/* Define EDIT_PGM to your editor. */
end_comment

begin_define
define|#
directive|define
name|EDIT_PGM
value|"vi"
end_define

begin_comment
comment|/* Define HAVE_CONST if your compiler supports the "const" modifier. */
end_comment

begin_define
define|#
directive|define
name|HAVE_CONST
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the<ctype.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_CTYPE_H
value|1
end_define

begin_comment
comment|/* Define HAVE_ERRNO if you have the errno variable. */
end_comment

begin_define
define|#
directive|define
name|HAVE_ERRNO
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the<errno.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_ERRNO_H
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `fchmod' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_FCHMOD
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the<fcntl.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_FCNTL_H
value|1
end_define

begin_comment
comment|/* Define HAVE_FILENO if you have the fileno() macro. */
end_comment

begin_define
define|#
directive|define
name|HAVE_FILENO
value|1
end_define

begin_comment
comment|/* Define HAVE_FLOAT if your compiler supports the "double" type. */
end_comment

begin_define
define|#
directive|define
name|HAVE_FLOAT
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `fsync' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_FSYNC
value|1
end_define

begin_comment
comment|/* GNU regex library */
end_comment

begin_comment
comment|/* #undef HAVE_GNU_REGEX */
end_comment

begin_comment
comment|/* Define to 1 if you have the<inttypes.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_INTTYPES_H
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the<limits.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_LIMITS_H
value|1
end_define

begin_comment
comment|/* Define HAVE_LOCALE if you have locale.h and setlocale. */
end_comment

begin_define
define|#
directive|define
name|HAVE_LOCALE
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the<memory.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_MEMORY_H
value|1
end_define

begin_comment
comment|/* Define HAVE_OSPEED if your termcap library has the ospeed variable. */
end_comment

begin_define
define|#
directive|define
name|HAVE_OSPEED
value|1
end_define

begin_comment
comment|/* PCRE (Perl-compatible regular expression) library */
end_comment

begin_comment
comment|/* #undef HAVE_PCRE */
end_comment

begin_comment
comment|/* Define to 1 if you have the `popen' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_POPEN
value|1
end_define

begin_comment
comment|/* POSIX regcomp() and regex.h */
end_comment

begin_define
define|#
directive|define
name|HAVE_POSIX_REGCOMP
value|1
end_define

begin_comment
comment|/* System V regcmp() */
end_comment

begin_comment
comment|/* #undef HAVE_REGCMP */
end_comment

begin_comment
comment|/* */
end_comment

begin_comment
comment|/* #undef HAVE_REGEXEC2 */
end_comment

begin_comment
comment|/* BSD re_comp() */
end_comment

begin_comment
comment|/* #undef HAVE_RE_COMP */
end_comment

begin_comment
comment|/* Define HAVE_SIGEMPTYSET if you have the sigemptyset macro. */
end_comment

begin_define
define|#
directive|define
name|HAVE_SIGEMPTYSET
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `sigprocmask' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_SIGPROCMASK
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `sigsetmask' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_SIGSETMASK
value|1
end_define

begin_comment
comment|/* Define to 1 if the system has the type `sigset_t'. */
end_comment

begin_define
define|#
directive|define
name|HAVE_SIGSET_T
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `snprintf' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_SNPRINTF
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `stat' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_STAT
value|1
end_define

begin_comment
comment|/* Define HAVE_STAT_INO if your struct stat has st_ino and st_dev. */
end_comment

begin_define
define|#
directive|define
name|HAVE_STAT_INO
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the<stdint.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_STDINT_H
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the<stdio.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_STDIO_H
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the<stdlib.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_STDLIB_H
value|1
end_define

begin_comment
comment|/* Define HAVE_STRERROR if you have the strerror() function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_STRERROR
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the<strings.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_STRINGS_H
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the<string.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_STRING_H
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `system' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_SYSTEM
value|1
end_define

begin_comment
comment|/* Define HAVE_SYS_ERRLIST if you have the sys_errlist[] variable. */
end_comment

begin_define
define|#
directive|define
name|HAVE_SYS_ERRLIST
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the<sys/ioctl.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_SYS_IOCTL_H
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the<sys/stat.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_SYS_STAT_H
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the<sys/stream.h> header file. */
end_comment

begin_comment
comment|/* #undef HAVE_SYS_STREAM_H */
end_comment

begin_comment
comment|/* Define to 1 if you have the<sys/types.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_SYS_TYPES_H
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the<termcap.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_TERMCAP_H
value|1
end_define

begin_comment
comment|/* Define HAVE_TERMIOS_FUNCS if you have tcgetattr/tcsetattr. */
end_comment

begin_define
define|#
directive|define
name|HAVE_TERMIOS_FUNCS
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the<termios.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_TERMIOS_H
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the<termio.h> header file. */
end_comment

begin_comment
comment|/* #undef HAVE_TERMIO_H */
end_comment

begin_comment
comment|/* Define to 1 if you have the<time.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_TIME_H
value|1
end_define

begin_comment
comment|/* Define HAVE_TIME_T if your system supports the "time_t" type. */
end_comment

begin_define
define|#
directive|define
name|HAVE_TIME_T
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the<unistd.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_UNISTD_H
value|1
end_define

begin_comment
comment|/* Define HAVE_UPPER_LOWER if you have isupper, islower, toupper, tolower. */
end_comment

begin_define
define|#
directive|define
name|HAVE_UPPER_LOWER
value|1
end_define

begin_comment
comment|/* Henry Spencer V8 regcomp() and regexp.h */
end_comment

begin_comment
comment|/* #undef HAVE_V8_REGCOMP */
end_comment

begin_comment
comment|/* Define to 1 if you have the<values.h> header file. */
end_comment

begin_comment
comment|/* #undef HAVE_VALUES_H */
end_comment

begin_comment
comment|/* Define HAVE_VOID if your compiler supports the "void" type. */
end_comment

begin_define
define|#
directive|define
name|HAVE_VOID
value|1
end_define

begin_comment
comment|/* Define HAVE_WCTYPE if you have iswupper, iswlower, towupper, towlower. */
end_comment

begin_define
define|#
directive|define
name|HAVE_WCTYPE
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the<wctype.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_WCTYPE_H
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `_setjmp' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE__SETJMP
value|1
end_define

begin_comment
comment|/* Define MUST_DEFINE_ERRNO if you have errno but it is not define in errno.h.    */
end_comment

begin_comment
comment|/* #undef MUST_DEFINE_ERRNO */
end_comment

begin_comment
comment|/* Define MUST_DEFINE_OSPEED if you have ospeed but it is not defined in    termcap.h. */
end_comment

begin_comment
comment|/* #undef MUST_DEFINE_OSPEED */
end_comment

begin_comment
comment|/* pattern matching is supported, but without metacharacters. */
end_comment

begin_comment
comment|/* #undef NO_REGEX */
end_comment

begin_comment
comment|/* Define to the address where bug reports for this package should be sent. */
end_comment

begin_define
define|#
directive|define
name|PACKAGE_BUGREPORT
value|""
end_define

begin_comment
comment|/* Define to the full name of this package. */
end_comment

begin_define
define|#
directive|define
name|PACKAGE_NAME
value|"less"
end_define

begin_comment
comment|/* Define to the full name and version of this package. */
end_comment

begin_define
define|#
directive|define
name|PACKAGE_STRING
value|"less 1"
end_define

begin_comment
comment|/* Define to the one symbol short name of this package. */
end_comment

begin_define
define|#
directive|define
name|PACKAGE_TARNAME
value|"less"
end_define

begin_comment
comment|/* Define to the home page for this package. */
end_comment

begin_define
define|#
directive|define
name|PACKAGE_URL
value|""
end_define

begin_comment
comment|/* Define to the version of this package. */
end_comment

begin_define
define|#
directive|define
name|PACKAGE_VERSION
value|"1"
end_define

begin_comment
comment|/* Define as the return type of signal handlers (`int' or `void'). */
end_comment

begin_define
define|#
directive|define
name|RETSIGTYPE
value|void
end_define

begin_comment
comment|/* Define SECURE_COMPILE=1 to build a secure version of less. */
end_comment

begin_define
define|#
directive|define
name|SECURE_COMPILE
value|0
end_define

begin_comment
comment|/* Define to 1 if the `S_IS*' macros in<sys/stat.h> do not work properly. */
end_comment

begin_comment
comment|/* #undef STAT_MACROS_BROKEN */
end_comment

begin_comment
comment|/* Define to 1 if you have the ANSI C header files. */
end_comment

begin_define
define|#
directive|define
name|STDC_HEADERS
value|1
end_define

begin_comment
comment|/* Define to 1 if you can safely include both<sys/time.h> and<time.h>. */
end_comment

begin_define
define|#
directive|define
name|TIME_WITH_SYS_TIME
value|1
end_define

begin_comment
comment|/* Enable large inode numbers on Mac OS X 10.5.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_DARWIN_USE_64_BIT_INODE
end_ifndef

begin_define
define|#
directive|define
name|_DARWIN_USE_64_BIT_INODE
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Number of bits in a file offset, on hosts where this is settable. */
end_comment

begin_comment
comment|/* #undef _FILE_OFFSET_BITS */
end_comment

begin_comment
comment|/* Define for large files, on AIX-style hosts. */
end_comment

begin_comment
comment|/* #undef _LARGE_FILES */
end_comment

begin_comment
comment|/* Define to empty if `const' does not conform to ANSI C. */
end_comment

begin_comment
comment|/* #undef const */
end_comment

begin_comment
comment|/* Define to `long int' if<sys/types.h> does not define. */
end_comment

begin_comment
comment|/* #undef off_t */
end_comment

begin_comment
comment|/* Define to `unsigned int' if<sys/types.h> does not define. */
end_comment

begin_comment
comment|/* #undef size_t */
end_comment

end_unit

