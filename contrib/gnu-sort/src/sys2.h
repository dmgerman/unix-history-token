begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* WARNING -- this file is temporary.  It is shared between the    sh-utils, fileutils, and textutils packages.  Once I find a little    more time, I'll merge the remaining things in system.h and everything    in this file will go back there. */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|S_IFMT
end_ifndef

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

begin_if
if|#
directive|if
name|STAT_MACROS_BROKEN
end_if

begin_undef
undef|#
directive|undef
name|S_ISBLK
end_undef

begin_undef
undef|#
directive|undef
name|S_ISCHR
end_undef

begin_undef
undef|#
directive|undef
name|S_ISDIR
end_undef

begin_undef
undef|#
directive|undef
name|S_ISDOOR
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

begin_undef
undef|#
directive|undef
name|S_ISNAM
end_undef

begin_undef
undef|#
directive|undef
name|S_ISMPB
end_undef

begin_undef
undef|#
directive|undef
name|S_ISMPC
end_undef

begin_undef
undef|#
directive|undef
name|S_ISNWK
end_undef

begin_undef
undef|#
directive|undef
name|S_ISREG
end_undef

begin_undef
undef|#
directive|undef
name|S_ISSOCK
end_undef

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
value|(((m)& S_IFMT) == S_IFBLK)
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

begin_ifndef
ifndef|#
directive|ifndef
name|S_ISCHR
end_ifndef

begin_ifdef
ifdef|#
directive|ifdef
name|S_IFCHR
end_ifdef

begin_define
define|#
directive|define
name|S_ISCHR
parameter_list|(
name|m
parameter_list|)
value|(((m)& S_IFMT) == S_IFCHR)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|S_ISCHR
parameter_list|(
name|m
parameter_list|)
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

begin_ifndef
ifndef|#
directive|ifndef
name|S_ISDIR
end_ifndef

begin_ifdef
ifdef|#
directive|ifdef
name|S_IFDIR
end_ifdef

begin_define
define|#
directive|define
name|S_ISDIR
parameter_list|(
name|m
parameter_list|)
value|(((m)& S_IFMT) == S_IFDIR)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|S_ISDIR
parameter_list|(
name|m
parameter_list|)
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

begin_ifndef
ifndef|#
directive|ifndef
name|S_ISDOOR
end_ifndef

begin_comment
comment|/* Solaris 2.5 and up */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|S_IFDOOR
end_ifdef

begin_define
define|#
directive|define
name|S_ISDOOR
parameter_list|(
name|m
parameter_list|)
value|(((m)& S_IFMT) == S_IFDOOR)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|S_ISDOOR
parameter_list|(
name|m
parameter_list|)
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
value|(((m)& S_IFMT) == S_IFIFO)
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

begin_ifndef
ifndef|#
directive|ifndef
name|S_ISLNK
end_ifndef

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
value|(((m)& S_IFMT) == S_IFLNK)
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

begin_ifndef
ifndef|#
directive|ifndef
name|S_ISMPB
end_ifndef

begin_comment
comment|/* V7 */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|S_IFMPB
end_ifdef

begin_define
define|#
directive|define
name|S_ISMPB
parameter_list|(
name|m
parameter_list|)
value|(((m)& S_IFMT) == S_IFMPB)
end_define

begin_define
define|#
directive|define
name|S_ISMPC
parameter_list|(
name|m
parameter_list|)
value|(((m)& S_IFMT) == S_IFMPC)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|S_ISMPB
parameter_list|(
name|m
parameter_list|)
value|0
end_define

begin_define
define|#
directive|define
name|S_ISMPC
parameter_list|(
name|m
parameter_list|)
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

begin_ifndef
ifndef|#
directive|ifndef
name|S_ISNAM
end_ifndef

begin_comment
comment|/* Xenix */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|S_IFNAM
end_ifdef

begin_define
define|#
directive|define
name|S_ISNAM
parameter_list|(
name|m
parameter_list|)
value|(((m)& S_IFMT) == S_IFNAM)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|S_ISNAM
parameter_list|(
name|m
parameter_list|)
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

begin_ifndef
ifndef|#
directive|ifndef
name|S_ISNWK
end_ifndef

begin_comment
comment|/* HP/UX */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|S_IFNWK
end_ifdef

begin_define
define|#
directive|define
name|S_ISNWK
parameter_list|(
name|m
parameter_list|)
value|(((m)& S_IFMT) == S_IFNWK)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|S_ISNWK
parameter_list|(
name|m
parameter_list|)
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

begin_ifndef
ifndef|#
directive|ifndef
name|S_ISREG
end_ifndef

begin_ifdef
ifdef|#
directive|ifdef
name|S_IFREG
end_ifdef

begin_define
define|#
directive|define
name|S_ISREG
parameter_list|(
name|m
parameter_list|)
value|(((m)& S_IFMT) == S_IFREG)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|S_ISREG
parameter_list|(
name|m
parameter_list|)
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

begin_ifndef
ifndef|#
directive|ifndef
name|S_ISSOCK
end_ifndef

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
value|(((m)& S_IFMT) == S_IFSOCK)
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

begin_ifndef
ifndef|#
directive|ifndef
name|S_TYPEISSEM
end_ifndef

begin_ifdef
ifdef|#
directive|ifdef
name|S_INSEM
end_ifdef

begin_define
define|#
directive|define
name|S_TYPEISSEM
parameter_list|(
name|p
parameter_list|)
value|(S_ISNAM ((p)->st_mode)&& (p)->st_rdev == S_INSEM)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|S_TYPEISSEM
parameter_list|(
name|p
parameter_list|)
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

begin_ifndef
ifndef|#
directive|ifndef
name|S_TYPEISSHM
end_ifndef

begin_ifdef
ifdef|#
directive|ifdef
name|S_INSHD
end_ifdef

begin_define
define|#
directive|define
name|S_TYPEISSHM
parameter_list|(
name|p
parameter_list|)
value|(S_ISNAM ((p)->st_mode)&& (p)->st_rdev == S_INSHD)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|S_TYPEISSHM
parameter_list|(
name|p
parameter_list|)
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

begin_ifndef
ifndef|#
directive|ifndef
name|S_TYPEISMQ
end_ifndef

begin_define
define|#
directive|define
name|S_TYPEISMQ
parameter_list|(
name|p
parameter_list|)
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* If any of the following are undefined,    define them to their de facto standard values.  */
end_comment

begin_if
if|#
directive|if
operator|!
name|S_ISUID
end_if

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

begin_if
if|#
directive|if
operator|!
name|S_ISGID
end_if

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

begin_comment
comment|/* S_ISVTX is a common extension to POSIX.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|S_ISVTX
end_ifndef

begin_define
define|#
directive|define
name|S_ISVTX
value|01000
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|!
name|S_IRUSR
operator|&&
name|S_IREAD
end_if

begin_define
define|#
directive|define
name|S_IRUSR
value|S_IREAD
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|!
name|S_IRUSR
end_if

begin_define
define|#
directive|define
name|S_IRUSR
value|00400
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|!
name|S_IRGRP
end_if

begin_define
define|#
directive|define
name|S_IRGRP
value|(S_IRUSR>> 3)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|!
name|S_IROTH
end_if

begin_define
define|#
directive|define
name|S_IROTH
value|(S_IRUSR>> 6)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|!
name|S_IWUSR
operator|&&
name|S_IWRITE
end_if

begin_define
define|#
directive|define
name|S_IWUSR
value|S_IWRITE
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|!
name|S_IWUSR
end_if

begin_define
define|#
directive|define
name|S_IWUSR
value|00200
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|!
name|S_IWGRP
end_if

begin_define
define|#
directive|define
name|S_IWGRP
value|(S_IWUSR>> 3)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|!
name|S_IWOTH
end_if

begin_define
define|#
directive|define
name|S_IWOTH
value|(S_IWUSR>> 6)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|!
name|S_IXUSR
operator|&&
name|S_IEXEC
end_if

begin_define
define|#
directive|define
name|S_IXUSR
value|S_IEXEC
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|!
name|S_IXUSR
end_if

begin_define
define|#
directive|define
name|S_IXUSR
value|00100
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|!
name|S_IXGRP
end_if

begin_define
define|#
directive|define
name|S_IXGRP
value|(S_IXUSR>> 3)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|!
name|S_IXOTH
end_if

begin_define
define|#
directive|define
name|S_IXOTH
value|(S_IXUSR>> 6)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|!
name|S_IRWXU
end_if

begin_define
define|#
directive|define
name|S_IRWXU
value|(S_IRUSR | S_IWUSR | S_IXUSR)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|!
name|S_IRWXG
end_if

begin_define
define|#
directive|define
name|S_IRWXG
value|(S_IRGRP | S_IWGRP | S_IXGRP)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|!
name|S_IRWXO
end_if

begin_define
define|#
directive|define
name|S_IRWXO
value|(S_IROTH | S_IWOTH | S_IXOTH)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* S_IXUGO is a common extension to POSIX.  */
end_comment

begin_if
if|#
directive|if
operator|!
name|S_IXUGO
end_if

begin_define
define|#
directive|define
name|S_IXUGO
value|(S_IXUSR | S_IXGRP | S_IXOTH)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|S_IRWXUGO
end_ifndef

begin_define
define|#
directive|define
name|S_IRWXUGO
value|(S_IRWXU | S_IRWXG | S_IRWXO)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* All the mode bits that can be affected by chmod.  */
end_comment

begin_define
define|#
directive|define
name|CHMOD_MODE_BITS
define|\
value|(S_ISUID | S_ISGID | S_ISVTX | S_IRWXU | S_IRWXG | S_IRWXO)
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|ST_MTIM_NSEC
end_ifdef

begin_define
define|#
directive|define
name|ST_TIME_CMP_NS
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|ns
parameter_list|)
value|((a).ns< (b).ns ? -1 : (a).ns> (b).ns)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|ST_TIME_CMP_NS
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|ns
parameter_list|)
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|ST_TIME_CMP
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|s
parameter_list|,
name|ns
parameter_list|)
define|\
value|((a).s< (b).s ? -1 : (a).s> (b).s ? 1 : ST_TIME_CMP_NS(a, b, ns))
end_define

begin_define
define|#
directive|define
name|ATIME_CMP
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|ST_TIME_CMP (a, b, st_atime, st_atim.ST_MTIM_NSEC)
end_define

begin_define
define|#
directive|define
name|CTIME_CMP
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|ST_TIME_CMP (a, b, st_ctime, st_ctim.ST_MTIM_NSEC)
end_define

begin_define
define|#
directive|define
name|MTIME_CMP
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|ST_TIME_CMP (a, b, st_mtime, st_mtim.ST_MTIM_NSEC)
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|RETSIGTYPE
end_ifndef

begin_define
define|#
directive|define
name|RETSIGTYPE
value|void
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|__GNUC__
end_if

begin_ifndef
ifndef|#
directive|ifndef
name|alloca
end_ifndef

begin_define
define|#
directive|define
name|alloca
value|__builtin_alloca
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
name|HAVE_ALLOCA_H
end_if

begin_include
include|#
directive|include
file|<alloca.h>
end_include

begin_else
else|#
directive|else
end_else

begin_ifdef
ifdef|#
directive|ifdef
name|_AIX
end_ifdef

begin_pragma
pragma|#
directive|pragma
name|alloca
end_pragma

begin_else
else|#
directive|else
end_else

begin_ifdef
ifdef|#
directive|ifdef
name|_WIN32
end_ifdef

begin_include
include|#
directive|include
file|<malloc.h>
end_include

begin_include
include|#
directive|include
file|<io.h>
end_include

begin_else
else|#
directive|else
end_else

begin_ifndef
ifndef|#
directive|ifndef
name|alloca
end_ifndef

begin_function_decl
name|char
modifier|*
name|alloca
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
name|__DJGPP__
end_ifdef

begin_comment
comment|/* We need the declaration of setmode.  */
end_comment

begin_include
include|#
directive|include
file|<io.h>
end_include

begin_comment
comment|/* We need the declaration of __djgpp_set_ctrl_c.  */
end_comment

begin_include
include|#
directive|include
file|<sys/exceptn.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|HAVE_STDINT_H
end_if

begin_include
include|#
directive|include
file|<stdint.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|HAVE_INTTYPES_H
end_if

begin_include
include|#
directive|include
file|<inttypes.h>
end_include

begin_comment
comment|/* for the definition of UINTMAX_MAX */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<ctype.h>
end_include

begin_comment
comment|/* Jim Meyering writes:     "... Some ctype macros are valid only for character codes that    isascii says are ASCII (SGI's IRIX-4.0.5 is one such system --when    using /bin/cc or gcc but without giving an ansi option).  So, all    ctype uses should be through macros like ISPRINT...  If    STDC_HEADERS is defined, then autoconf has verified that the ctype    macros don't need to be guarded with references to isascii. ...    Defining isascii to 1 should let any compiler worth its salt    eliminate the&& through constant folding."     Bruno Haible adds:     "... Furthermore, isupper(c) etc. have an undefined result if c is    outside the range -1<= c<= 255. One is tempted to write isupper(c)    with c being of type `char', but this is wrong if c is an 8-bit    character>= 128 which gets sign-extended to a negative value.    The macro ISUPPER protects against this as well."  */
end_comment

begin_if
if|#
directive|if
name|STDC_HEADERS
operator|||
operator|(
operator|!
name|defined
argument_list|(
name|isascii
argument_list|)
operator|&&
operator|!
name|HAVE_ISASCII
operator|)
end_if

begin_define
define|#
directive|define
name|IN_CTYPE_DOMAIN
parameter_list|(
name|c
parameter_list|)
value|1
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|IN_CTYPE_DOMAIN
parameter_list|(
name|c
parameter_list|)
value|isascii(c)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|isblank
end_ifdef

begin_define
define|#
directive|define
name|ISBLANK
parameter_list|(
name|c
parameter_list|)
value|(IN_CTYPE_DOMAIN (c)&& isblank (c))
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|ISBLANK
parameter_list|(
name|c
parameter_list|)
value|((c) == ' ' || (c) == '\t')
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|isgraph
end_ifdef

begin_define
define|#
directive|define
name|ISGRAPH
parameter_list|(
name|c
parameter_list|)
value|(IN_CTYPE_DOMAIN (c)&& isgraph (c))
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|ISGRAPH
parameter_list|(
name|c
parameter_list|)
value|(IN_CTYPE_DOMAIN (c)&& isprint (c)&& !isspace (c))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* This is defined in<sys/euc.h> on at least Solaris2.6 systems.  */
end_comment

begin_undef
undef|#
directive|undef
name|ISPRINT
end_undef

begin_define
define|#
directive|define
name|ISPRINT
parameter_list|(
name|c
parameter_list|)
value|(IN_CTYPE_DOMAIN (c)&& isprint (c))
end_define

begin_define
define|#
directive|define
name|ISALNUM
parameter_list|(
name|c
parameter_list|)
value|(IN_CTYPE_DOMAIN (c)&& isalnum (c))
end_define

begin_define
define|#
directive|define
name|ISALPHA
parameter_list|(
name|c
parameter_list|)
value|(IN_CTYPE_DOMAIN (c)&& isalpha (c))
end_define

begin_define
define|#
directive|define
name|ISCNTRL
parameter_list|(
name|c
parameter_list|)
value|(IN_CTYPE_DOMAIN (c)&& iscntrl (c))
end_define

begin_define
define|#
directive|define
name|ISLOWER
parameter_list|(
name|c
parameter_list|)
value|(IN_CTYPE_DOMAIN (c)&& islower (c))
end_define

begin_define
define|#
directive|define
name|ISPUNCT
parameter_list|(
name|c
parameter_list|)
value|(IN_CTYPE_DOMAIN (c)&& ispunct (c))
end_define

begin_define
define|#
directive|define
name|ISSPACE
parameter_list|(
name|c
parameter_list|)
value|(IN_CTYPE_DOMAIN (c)&& isspace (c))
end_define

begin_define
define|#
directive|define
name|ISUPPER
parameter_list|(
name|c
parameter_list|)
value|(IN_CTYPE_DOMAIN (c)&& isupper (c))
end_define

begin_define
define|#
directive|define
name|ISXDIGIT
parameter_list|(
name|c
parameter_list|)
value|(IN_CTYPE_DOMAIN (c)&& isxdigit (c))
end_define

begin_define
define|#
directive|define
name|ISDIGIT_LOCALE
parameter_list|(
name|c
parameter_list|)
value|(IN_CTYPE_DOMAIN (c)&& isdigit (c))
end_define

begin_if
if|#
directive|if
name|STDC_HEADERS
end_if

begin_define
define|#
directive|define
name|TOLOWER
parameter_list|(
name|Ch
parameter_list|)
value|tolower (Ch)
end_define

begin_define
define|#
directive|define
name|TOUPPER
parameter_list|(
name|Ch
parameter_list|)
value|toupper (Ch)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|TOLOWER
parameter_list|(
name|Ch
parameter_list|)
value|(ISUPPER (Ch) ? tolower (Ch) : (Ch))
end_define

begin_define
define|#
directive|define
name|TOUPPER
parameter_list|(
name|Ch
parameter_list|)
value|(ISLOWER (Ch) ? toupper (Ch) : (Ch))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ISDIGIT differs from ISDIGIT_LOCALE, as follows:    - Its arg may be any int or unsigned int; it need not be an unsigned char.    - It's guaranteed to evaluate its argument exactly once.    - It's typically faster.    POSIX says that only '0' through '9' are digits.  Prefer ISDIGIT to    ISDIGIT_LOCALE unless it's important to use the locale's definition    of `digit' even when the host does not conform to POSIX.  */
end_comment

begin_define
define|#
directive|define
name|ISDIGIT
parameter_list|(
name|c
parameter_list|)
value|((unsigned) (c) - '0'<= 9)
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|PARAMS
end_ifndef

begin_if
if|#
directive|if
name|PROTOTYPES
end_if

begin_define
define|#
directive|define
name|PARAMS
parameter_list|(
name|Args
parameter_list|)
value|Args
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|PARAMS
parameter_list|(
name|Args
parameter_list|)
value|()
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
comment|/* Take care of NLS matters.  */
end_comment

begin_if
if|#
directive|if
name|HAVE_LOCALE_H
end_if

begin_include
include|#
directive|include
file|<locale.h>
end_include

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|setlocale
parameter_list|(
name|Category
parameter_list|,
name|Locale
parameter_list|)
end_define

begin_comment
comment|/* empty */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|"gettext.h"
end_include

begin_define
define|#
directive|define
name|_
parameter_list|(
name|msgid
parameter_list|)
value|gettext (msgid)
end_define

begin_define
define|#
directive|define
name|N_
parameter_list|(
name|msgid
parameter_list|)
value|msgid
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_SETLOCALE
end_ifndef

begin_define
define|#
directive|define
name|HAVE_SETLOCALE
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|STREQ
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|(strcmp ((a), (b)) == 0)
end_define

begin_if
if|#
directive|if
operator|!
name|HAVE_DECL_FREE
end_if

begin_function_decl
name|void
name|free
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|!
name|HAVE_DECL_MALLOC
end_if

begin_function_decl
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

begin_if
if|#
directive|if
operator|!
name|HAVE_DECL_MEMCHR
end_if

begin_function_decl
name|char
modifier|*
name|memchr
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|!
name|HAVE_DECL_REALLOC
end_if

begin_function_decl
name|char
modifier|*
name|realloc
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|!
name|HAVE_DECL_STPCPY
end_if

begin_ifndef
ifndef|#
directive|ifndef
name|stpcpy
end_ifndef

begin_function_decl
name|char
modifier|*
name|stpcpy
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

begin_if
if|#
directive|if
operator|!
name|HAVE_DECL_STRNDUP
end_if

begin_function_decl
name|char
modifier|*
name|strndup
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|!
name|HAVE_DECL_STRSTR
end_if

begin_function_decl
name|char
modifier|*
name|strstr
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|!
name|HAVE_DECL_GETENV
end_if

begin_function_decl
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

begin_if
if|#
directive|if
operator|!
name|HAVE_DECL_LSEEK
end_if

begin_function_decl
name|off_t
name|lseek
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* This is needed on some AIX systems.  */
end_comment

begin_if
if|#
directive|if
operator|!
name|HAVE_DECL_STRTOUL
end_if

begin_function_decl
name|unsigned
name|long
name|strtoul
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* This is needed on some AIX systems.  */
end_comment

begin_if
if|#
directive|if
operator|!
name|HAVE_DECL_STRTOULL
operator|&&
name|HAVE_UNSIGNED_LONG_LONG
end_if

begin_function_decl
name|unsigned
name|long
name|long
name|strtoull
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|!
name|HAVE_DECL_GETLOGIN
end_if

begin_function_decl
name|char
modifier|*
name|getlogin
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|!
name|HAVE_DECL_TTYNAME
end_if

begin_function_decl
name|char
modifier|*
name|ttyname
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|!
name|HAVE_DECL_GETEUID
end_if

begin_function_decl
name|uid_t
name|geteuid
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|!
name|HAVE_DECL_GETPWUID
end_if

begin_function_decl
name|struct
name|passwd
modifier|*
name|getpwuid
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|!
name|HAVE_DECL_GETGRGID
end_if

begin_function_decl
name|struct
name|group
modifier|*
name|getgrgid
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|!
name|HAVE_DECL_GETUID
end_if

begin_function_decl
name|uid_t
name|getuid
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|"xalloc.h"
end_include

begin_if
if|#
directive|if
operator|!
name|defined
name|HAVE_MEMPCPY
operator|&&
operator|!
name|defined
name|mempcpy
end_if

begin_comment
comment|/* Be CAREFUL that there are no side effects in N.  */
end_comment

begin_define
define|#
directive|define
name|mempcpy
parameter_list|(
name|D
parameter_list|,
name|S
parameter_list|,
name|N
parameter_list|)
value|((void *) ((char *) memcpy (D, S, N) + (N)))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Include automatically-generated macros for unlocked I/O.  */
end_comment

begin_include
include|#
directive|include
file|"unlocked-io.h"
end_include

begin_define
define|#
directive|define
name|SAME_INODE
parameter_list|(
name|Stat_buf_1
parameter_list|,
name|Stat_buf_2
parameter_list|)
define|\
value|((Stat_buf_1).st_ino == (Stat_buf_2).st_ino \&& (Stat_buf_1).st_dev == (Stat_buf_2).st_dev)
end_define

begin_define
define|#
directive|define
name|DOT_OR_DOTDOT
parameter_list|(
name|Basename
parameter_list|)
define|\
value|(Basename[0] == '.'&& (Basename[1] == '\0' \ 			  || (Basename[1] == '.'&& Basename[2] == '\0')))
end_define

begin_if
if|#
directive|if
name|SETVBUF_REVERSED
end_if

begin_define
define|#
directive|define
name|SETVBUF
parameter_list|(
name|Stream
parameter_list|,
name|Buffer
parameter_list|,
name|Type
parameter_list|,
name|Size
parameter_list|)
define|\
value|setvbuf (Stream, Type, Buffer, Size)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|SETVBUF
parameter_list|(
name|Stream
parameter_list|,
name|Buffer
parameter_list|,
name|Type
parameter_list|,
name|Size
parameter_list|)
define|\
value|setvbuf (Stream, Buffer, Type, Size)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Factor out some of the common --help and --version processing code.  */
end_comment

begin_comment
comment|/* These enum values cannot possibly conflict with the option values    ordinarily used by commands, including CHAR_MAX + 1, etc.  Avoid    CHAR_MIN - 1, as it may equal -1, the getopt end-of-options value.  */
end_comment

begin_enum
enum|enum
block|{
name|GETOPT_HELP_CHAR
init|=
operator|(
name|CHAR_MIN
operator|-
literal|2
operator|)
block|,
name|GETOPT_VERSION_CHAR
init|=
operator|(
name|CHAR_MIN
operator|-
literal|3
operator|)
block|}
enum|;
end_enum

begin_define
define|#
directive|define
name|GETOPT_HELP_OPTION_DECL
define|\
value|"help", no_argument, 0, GETOPT_HELP_CHAR
end_define

begin_define
define|#
directive|define
name|GETOPT_VERSION_OPTION_DECL
define|\
value|"version", no_argument, 0, GETOPT_VERSION_CHAR
end_define

begin_define
define|#
directive|define
name|case_GETOPT_HELP_CHAR
define|\
value|case GETOPT_HELP_CHAR:			\     usage (EXIT_SUCCESS);			\     break;
end_define

begin_define
define|#
directive|define
name|HELP_OPTION_DESCRIPTION
define|\
value|_("      --help     display this help and exit\n")
end_define

begin_define
define|#
directive|define
name|VERSION_OPTION_DESCRIPTION
define|\
value|_("      --version  output version information and exit\n")
end_define

begin_include
include|#
directive|include
file|"closeout.h"
end_include

begin_include
include|#
directive|include
file|"version-etc.h"
end_include

begin_define
define|#
directive|define
name|case_GETOPT_VERSION_CHAR
parameter_list|(
name|Program_name
parameter_list|,
name|Authors
parameter_list|)
define|\
value|case GETOPT_VERSION_CHAR:						\     version_etc (stdout, Program_name, PACKAGE, VERSION, Authors);	\     exit (EXIT_SUCCESS);						\     break;
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|MAX
end_ifndef

begin_define
define|#
directive|define
name|MAX
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|((a)> (b) ? (a) : (b))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|MIN
end_ifndef

begin_define
define|#
directive|define
name|MIN
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|(((a)< (b)) ? (a) : (b))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|CHAR_BIT
end_ifndef

begin_define
define|#
directive|define
name|CHAR_BIT
value|8
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* The extra casts work around common compiler bugs.  */
end_comment

begin_define
define|#
directive|define
name|TYPE_SIGNED
parameter_list|(
name|t
parameter_list|)
value|(! ((t) 0< (t) -1))
end_define

begin_comment
comment|/* The outer cast is needed to work around a bug in Cray C 5.0.3.0.    It is necessary at least when t == time_t.  */
end_comment

begin_define
define|#
directive|define
name|TYPE_MINIMUM
parameter_list|(
name|t
parameter_list|)
value|((t) (TYPE_SIGNED (t) \ 			      ? ~ (t) 0<< (sizeof (t) * CHAR_BIT - 1) : (t) 0))
end_define

begin_define
define|#
directive|define
name|TYPE_MAXIMUM
parameter_list|(
name|t
parameter_list|)
value|((t) (~ (t) 0 - TYPE_MINIMUM (t)))
end_define

begin_comment
comment|/* Upper bound on the string length of an integer converted to string.    302 / 1000 is ceil (log10 (2.0)).  Subtract 1 for the sign bit;    add 1 for integer division truncation; add 1 more for a minus sign.  */
end_comment

begin_define
define|#
directive|define
name|INT_STRLEN_BOUND
parameter_list|(
name|t
parameter_list|)
value|((sizeof (t) * CHAR_BIT - 1) * 302 / 1000 + 2)
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|CHAR_MIN
end_ifndef

begin_define
define|#
directive|define
name|CHAR_MIN
value|TYPE_MINIMUM (char)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|CHAR_MAX
end_ifndef

begin_define
define|#
directive|define
name|CHAR_MAX
value|TYPE_MAXIMUM (char)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|SCHAR_MIN
end_ifndef

begin_define
define|#
directive|define
name|SCHAR_MIN
value|(-1 - SCHAR_MAX)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|SCHAR_MAX
end_ifndef

begin_define
define|#
directive|define
name|SCHAR_MAX
value|(CHAR_MAX == UCHAR_MAX ? CHAR_MAX / 2 : CHAR_MAX)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|UCHAR_MAX
end_ifndef

begin_define
define|#
directive|define
name|UCHAR_MAX
value|TYPE_MAXIMUM (unsigned char)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|SHRT_MIN
end_ifndef

begin_define
define|#
directive|define
name|SHRT_MIN
value|TYPE_MINIMUM (short int)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|SHRT_MAX
end_ifndef

begin_define
define|#
directive|define
name|SHRT_MAX
value|TYPE_MAXIMUM (short int)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|INT_MAX
end_ifndef

begin_define
define|#
directive|define
name|INT_MAX
value|TYPE_MAXIMUM (int)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|UINT_MAX
end_ifndef

begin_define
define|#
directive|define
name|UINT_MAX
value|TYPE_MAXIMUM (unsigned int)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|LONG_MAX
end_ifndef

begin_define
define|#
directive|define
name|LONG_MAX
value|TYPE_MAXIMUM (long)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ULONG_MAX
end_ifndef

begin_define
define|#
directive|define
name|ULONG_MAX
value|TYPE_MAXIMUM (unsigned long)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|SIZE_MAX
end_ifndef

begin_define
define|#
directive|define
name|SIZE_MAX
value|TYPE_MAXIMUM (size_t)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|UINTMAX_MAX
end_ifndef

begin_define
define|#
directive|define
name|UINTMAX_MAX
value|TYPE_MAXIMUM (uintmax_t)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|OFF_T_MIN
end_ifndef

begin_define
define|#
directive|define
name|OFF_T_MIN
value|TYPE_MINIMUM (off_t)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|OFF_T_MAX
end_ifndef

begin_define
define|#
directive|define
name|OFF_T_MAX
value|TYPE_MAXIMUM (off_t)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|UID_T_MAX
end_ifndef

begin_define
define|#
directive|define
name|UID_T_MAX
value|TYPE_MAXIMUM (uid_t)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|GID_T_MAX
end_ifndef

begin_define
define|#
directive|define
name|GID_T_MAX
value|TYPE_MAXIMUM (gid_t)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|PID_T_MAX
end_ifndef

begin_define
define|#
directive|define
name|PID_T_MAX
value|TYPE_MAXIMUM (pid_t)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|CHAR_BIT
end_ifndef

begin_define
define|#
directive|define
name|CHAR_BIT
value|8
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Use this to suppress gcc's `...may be used before initialized' warnings. */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|lint
end_ifdef

begin_define
define|#
directive|define
name|IF_LINT
parameter_list|(
name|Code
parameter_list|)
value|Code
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|IF_LINT
parameter_list|(
name|Code
parameter_list|)
end_define

begin_comment
comment|/* empty */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|__attribute__
end_ifndef

begin_if
if|#
directive|if
name|__GNUC__
operator|<
literal|2
operator|||
operator|(
name|__GNUC__
operator|==
literal|2
operator|&&
name|__GNUC_MINOR__
operator|<
literal|8
operator|)
operator|||
name|__STRICT_ANSI__
end_if

begin_define
define|#
directive|define
name|__attribute__
parameter_list|(
name|x
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

begin_ifndef
ifndef|#
directive|ifndef
name|ATTRIBUTE_NORETURN
end_ifndef

begin_define
define|#
directive|define
name|ATTRIBUTE_NORETURN
value|__attribute__ ((__noreturn__))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ATTRIBUTE_UNUSED
end_ifndef

begin_define
define|#
directive|define
name|ATTRIBUTE_UNUSED
value|__attribute__ ((__unused__))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
name|strdupa
end_if

begin_define
define|#
directive|define
name|ASSIGN_STRDUPA
parameter_list|(
name|DEST
parameter_list|,
name|S
parameter_list|)
define|\
value|do { DEST = strdupa(S); } while (0)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|ASSIGN_STRDUPA
parameter_list|(
name|DEST
parameter_list|,
name|S
parameter_list|)
define|\
value|do						\     {						\       const char *s_ = (S);			\       size_t len_ = strlen (s_) + 1;		\       char *tmp_dest_ = (char *) alloca (len_);	\       DEST = memcpy (tmp_dest_, (s_), len_);	\     }						\   while (0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|EOVERFLOW
end_ifndef

begin_define
define|#
directive|define
name|EOVERFLOW
value|EINVAL
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|!
name|HAVE_FSEEKO
operator|&&
operator|!
name|defined
name|fseeko
end_if

begin_define
define|#
directive|define
name|fseeko
parameter_list|(
name|s
parameter_list|,
name|o
parameter_list|,
name|w
parameter_list|)
value|((o) == (long) (o)		\ 			  ? fseek (s, o, w)		\ 			  : (errno = EOVERFLOW, -1))
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

