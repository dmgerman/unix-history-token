begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* unix.cfg: Configuration file for sgmls on Unix. */
end_comment

begin_comment
comment|/* A list of filename templates to use for searching for external entities. The filenames are separated by the character specified in PATH_FILE_SEP. See sgmls.man for details. */
end_comment

begin_define
define|#
directive|define
name|DEFAULT_PATH
value|"/usr/share/sgml/%O/%C/%T:%N.%X:%N.%D"
end_define

begin_comment
comment|/* The character that separates the filenames templates. */
end_comment

begin_define
define|#
directive|define
name|PATH_FILE_SEP
value|':'
end_define

begin_comment
comment|/* The character that separates filenames in a system identifier. Usually the same as PATH_FILE_SEP. */
end_comment

begin_define
define|#
directive|define
name|SYSID_FILE_SEP
value|':'
end_define

begin_comment
comment|/* The environment variable that contains the list of filename templates. */
end_comment

begin_define
define|#
directive|define
name|PATH_ENV_VAR
value|"SGML_PATH"
end_define

begin_comment
comment|/* A macro that returns non-zero if the filename is relative to the    current directory. */
end_comment

begin_define
define|#
directive|define
name|FILE_IS_RELATIVE
parameter_list|(
name|p
parameter_list|)
value|((p)[0] != '/')
end_define

begin_comment
comment|/* A string containing the characters that can separate the directory    part of a filename from the basename. */
end_comment

begin_define
define|#
directive|define
name|DIR_BASE_SEP
value|"/"
end_define

begin_comment
comment|/* The environment variable that contains the list of catalog entry files.    Filenames are separated by PATH_FILE_SEP. */
end_comment

begin_define
define|#
directive|define
name|CATALOG_FILES_ENV_VAR
value|"SGML_CATALOG_FILES"
end_define

begin_comment
comment|/* Default list of catalog entry files. */
end_comment

begin_define
define|#
directive|define
name|DEFAULT_CATALOG_FILES
value|"CATALOG:/usr/share/sgml/CATALOG"
end_define

begin_comment
comment|/* MIN_DAT_SUBS_FROM and MIN_DATS_SUBS_TO tell sgmls how to transform a name or system identifier into a legal filename.  A character in MIN_DAT_SUBS_FROM will be transformed into the character in the corresponding position in MIN_DAT_SUBS_TO.  If there is no such position, then the character is removed. */
end_comment

begin_comment
comment|/* This says that spaces should be transformed to underscores, and slashes to percents. */
end_comment

begin_define
define|#
directive|define
name|MIN_DAT_SUBS_FROM
value|" /"
end_define

begin_define
define|#
directive|define
name|MIN_DAT_SUBS_TO
value|"_%"
end_define

begin_comment
comment|/* Define this to allow tracing. */
end_comment

begin_comment
comment|/* #define TRACE 1 */
end_comment

begin_comment
comment|/* Define this you want support for subdocuments.  This is implemented using features that are not part of Standard C, so you might not want to define it if you are porting to a new system.  Otherwise I suggest you leave it defined. */
end_comment

begin_define
define|#
directive|define
name|SUPPORT_SUBDOC
value|1
end_define

begin_comment
comment|/* Define HAVE_EXTENDED_PRINTF if your *printf functions supports X/Open extensions; if they do, then, for example,    printf("%2$s%1$s", "bar", "foo")  should print `foobar'.  */
end_comment

begin_comment
comment|/* #define HAVE_EXTENDED_PRINTF 1 */
end_comment

begin_comment
comment|/* Define HAVE_CAT if your system provides the X/Open message catalogue functions catopen() and catgets(), and you want to use them. An implementations of these functions is included and will be used if you don't define this.  On SunOS 4.1.1, if you do define this you should set CC=/usr/xpg2bin/cc in the makefile. */
end_comment

begin_define
define|#
directive|define
name|HAVE_CAT
value|1
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|__STDC__
end_ifdef

begin_comment
comment|/* Define this if your compiler supports prototypes. */
end_comment

begin_define
define|#
directive|define
name|USE_PROTOTYPES
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Can't use<stdarg.h> without prototypes. */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|USE_PROTOTYPES
end_ifndef

begin_define
define|#
directive|define
name|VARARGS
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* If your compiler defines __STDC__ but doesn't provide<stdarg.h>, you must define VARARGS yourself here. */
end_comment

begin_comment
comment|/* #define VARARGS 1 */
end_comment

begin_comment
comment|/* Define this if you do not have strerror(). */
end_comment

begin_comment
comment|/* #define STRERROR_MISSING 1 */
end_comment

begin_comment
comment|/* Define this unless the character testing functions in ctype.h are defined for all values representable as an unsigned char.  You do not need to define this if your system is ANSI C conformant.  You should define for old Unix systems. */
end_comment

begin_comment
comment|/* #define USE_ISASCII 1 */
end_comment

begin_comment
comment|/* Define this if your system provides the BSD style string operations rather than ANSI C ones (eg bcopy() rather than memcpy(), and index() rather than strchr()). */
end_comment

begin_comment
comment|/* #define BSD_STRINGS 1 */
end_comment

begin_comment
comment|/* Define this if you have getopt(). */
end_comment

begin_define
define|#
directive|define
name|HAVE_GETOPT
value|1
end_define

begin_comment
comment|/* Define this if you have access(). */
end_comment

begin_define
define|#
directive|define
name|HAVE_ACCESS
value|1
end_define

begin_comment
comment|/* Define this if you have<unistd.h>. */
end_comment

begin_define
define|#
directive|define
name|HAVE_UNISTD_H
value|1
end_define

begin_comment
comment|/* Define this if you have<sys/stat.h>. */
end_comment

begin_define
define|#
directive|define
name|HAVE_SYS_STAT_H
value|1
end_define

begin_comment
comment|/* Define this if you have waitpid(). */
end_comment

begin_define
define|#
directive|define
name|HAVE_WAITPID
value|1
end_define

begin_comment
comment|/* Define this if your system is POSIX.1 (ISO 9945-1:1990) compliant. */
end_comment

begin_define
define|#
directive|define
name|POSIX
value|1
end_define

begin_comment
comment|/* Define this if you have the vfork() system call. */
end_comment

begin_define
define|#
directive|define
name|HAVE_VFORK
value|1
end_define

begin_comment
comment|/* Define this if you have<vfork.h>. */
end_comment

begin_comment
comment|/* #define HAVE_VFORK_H 1 */
end_comment

begin_comment
comment|/* Define this if you don't have<stdlib.h> */
end_comment

begin_comment
comment|/* #define STDLIB_H_MISSING 1 */
end_comment

begin_comment
comment|/* Define this if you don't have<stddef.h> */
end_comment

begin_comment
comment|/* #define STDDEF_H_MISSING 1 */
end_comment

begin_comment
comment|/* Define this if you don't have<limits.h> */
end_comment

begin_comment
comment|/* #define LIMITS_H_MISSING 1 */
end_comment

begin_comment
comment|/* Define this if you don't have remove(); unlink() will be used instead. */
end_comment

begin_comment
comment|/* #define REMOVE_MISSING 1 */
end_comment

begin_comment
comment|/* Define this if you don't have raise(); kill() will be used instead. */
end_comment

begin_comment
comment|/* #define RAISE_MISSING 1 */
end_comment

begin_comment
comment|/* Define this if you don't have fsetpos() and fgetpos(). */
end_comment

begin_comment
comment|/* #define FPOS_MISSING 1 */
end_comment

begin_comment
comment|/* Universal pointer type. */
end_comment

begin_comment
comment|/* If your compiler doesn't fully support void *, change `void' to `char'. */
end_comment

begin_typedef
typedef|typedef
name|void
modifier|*
name|UNIV
typedef|;
end_typedef

begin_comment
comment|/* If your compiler doesn't support void as a function return type, change `void' to `int'. */
end_comment

begin_typedef
typedef|typedef
name|void
name|VOID
typedef|;
end_typedef

begin_comment
comment|/* If you don't have an ANSI C conformant<limits.h>, define CHAR_SIGNED as 1 or 0 according to whether the `char' type is signed. The<limits.h> on some versions of System Release V 3.2 is not ANSI C conformant: the value of CHAR_MIN is 0 even though the `char' type is signed. */
end_comment

begin_comment
comment|/* #define CHAR_SIGNED 1 */
end_comment

begin_comment
comment|/* #define CHAR_SIGNED 0 */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|CHAR_SIGNED
end_ifndef

begin_include
include|#
directive|include
file|<limits.h>
end_include

begin_if
if|#
directive|if
name|CHAR_MIN
operator|<
literal|0
end_if

begin_define
define|#
directive|define
name|CHAR_SIGNED
value|1
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|CHAR_SIGNED
value|0
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
comment|/* not CHAR_SIGNED */
end_comment

begin_comment
comment|/* Assume the system character set is ISO Latin-1. */
end_comment

begin_include
include|#
directive|include
file|"latin1.h"
end_include

end_unit

