begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $Header: /home/ncvs/src/gnu/usr.bin/patch/common.h,v 1.3 1995/05/30 05:02:30 rgrimes Exp $  *  * $Log: common.h,v $  * Revision 1.3  1995/05/30 05:02:30  rgrimes  * Remove trailing whitespace.  *  * Revision 1.2  1993/09/22  16:51:03  rich  * Increaed the fixed static buffer sizes and maximum hunk size that  * otherwise causes the XFree86 1.3 patch set to fail.  *  * Revision 1.1.1.1  1993/06/19  14:21:52  paul  * b-maked patch-2.10  *  * Revision 2.0.1.2  88/06/22  20:44:53  lwall  * patch12: sprintf was declared wrong  *  * Revision 2.0.1.1  88/06/03  15:01:56  lwall  * patch10: support for shorter extensions.  *  * Revision 2.0  86/09/17  15:36:39  lwall  * Baseline for netwide release.  *  */
end_comment

begin_define
define|#
directive|define
name|DEBUGGING
end_define

begin_define
define|#
directive|define
name|VOIDUSED
value|7
end_define

begin_include
include|#
directive|include
file|"config.h"
end_include

begin_comment
comment|/* shut lint up about the following when return value ignored */
end_comment

begin_define
define|#
directive|define
name|Signal
value|(void)signal
end_define

begin_define
define|#
directive|define
name|Unlink
value|(void)unlink
end_define

begin_define
define|#
directive|define
name|Lseek
value|(void)lseek
end_define

begin_define
define|#
directive|define
name|Fseek
value|(void)fseek
end_define

begin_define
define|#
directive|define
name|Fstat
value|(void)fstat
end_define

begin_define
define|#
directive|define
name|Pclose
value|(void)pclose
end_define

begin_define
define|#
directive|define
name|Close
value|(void)close
end_define

begin_define
define|#
directive|define
name|Fclose
value|(void)fclose
end_define

begin_define
define|#
directive|define
name|Fflush
value|(void)fflush
end_define

begin_define
define|#
directive|define
name|Sprintf
value|(void)sprintf
end_define

begin_define
define|#
directive|define
name|Mktemp
value|(void)mktemp
end_define

begin_define
define|#
directive|define
name|Strcpy
value|(void)strcpy
end_define

begin_define
define|#
directive|define
name|Strcat
value|(void)strcat
end_define

begin_comment
comment|/* NeXT declares malloc and realloc incompatibly from us in some of    these files.  Temporarily redefine them to prevent errors.  */
end_comment

begin_define
define|#
directive|define
name|malloc
value|system_malloc
end_define

begin_define
define|#
directive|define
name|realloc
value|system_realloc
end_define

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<assert.h>
end_include

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<sys/stat.h>
end_include

begin_include
include|#
directive|include
file|<ctype.h>
end_include

begin_include
include|#
directive|include
file|<signal.h>
end_include

begin_undef
undef|#
directive|undef
name|malloc
end_undef

begin_undef
undef|#
directive|undef
name|realloc
end_undef

begin_comment
comment|/* constants */
end_comment

begin_comment
comment|/* AIX predefines these.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|TRUE
end_ifdef

begin_undef
undef|#
directive|undef
name|TRUE
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|FALSE
end_ifdef

begin_undef
undef|#
directive|undef
name|FALSE
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|TRUE
value|(1)
end_define

begin_define
define|#
directive|define
name|FALSE
value|(0)
end_define

begin_define
define|#
directive|define
name|MAXHUNKSIZE
value|200000
end_define

begin_comment
comment|/* is this enough lines? */
end_comment

begin_define
define|#
directive|define
name|INITHUNKMAX
value|125
end_define

begin_comment
comment|/* initial dynamic allocation size */
end_comment

begin_define
define|#
directive|define
name|MAXLINELEN
value|4096
end_define

begin_define
define|#
directive|define
name|BUFFERSIZE
value|4096
end_define

begin_define
define|#
directive|define
name|SCCSPREFIX
value|"s."
end_define

begin_define
define|#
directive|define
name|GET
value|"get %s"
end_define

begin_define
define|#
directive|define
name|GET_LOCKED
value|"get -e %s"
end_define

begin_define
define|#
directive|define
name|SCCSDIFF
value|"get -p %s | diff - %s>/dev/null"
end_define

begin_define
define|#
directive|define
name|RCSSUFFIX
value|",v"
end_define

begin_define
define|#
directive|define
name|CHECKOUT
value|"co %s"
end_define

begin_define
define|#
directive|define
name|CHECKOUT_LOCKED
value|"co -l %s"
end_define

begin_define
define|#
directive|define
name|RCSDIFF
value|"rcsdiff %s> /dev/null"
end_define

begin_comment
comment|/* handy definitions */
end_comment

begin_define
define|#
directive|define
name|Null
parameter_list|(
name|t
parameter_list|)
value|((t)0)
end_define

begin_define
define|#
directive|define
name|Nullch
value|Null(char *)
end_define

begin_define
define|#
directive|define
name|Nullfp
value|Null(FILE *)
end_define

begin_define
define|#
directive|define
name|Nulline
value|Null(LINENUM)
end_define

begin_define
define|#
directive|define
name|Ctl
parameter_list|(
name|ch
parameter_list|)
value|((ch)& 037)
end_define

begin_define
define|#
directive|define
name|strNE
parameter_list|(
name|s1
parameter_list|,
name|s2
parameter_list|)
value|(strcmp(s1, s2))
end_define

begin_define
define|#
directive|define
name|strEQ
parameter_list|(
name|s1
parameter_list|,
name|s2
parameter_list|)
value|(!strcmp(s1, s2))
end_define

begin_define
define|#
directive|define
name|strnNE
parameter_list|(
name|s1
parameter_list|,
name|s2
parameter_list|,
name|l
parameter_list|)
value|(strncmp(s1, s2, l))
end_define

begin_define
define|#
directive|define
name|strnEQ
parameter_list|(
name|s1
parameter_list|,
name|s2
parameter_list|,
name|l
parameter_list|)
value|(!strncmp(s1, s2, l))
end_define

begin_comment
comment|/* typedefs */
end_comment

begin_typedef
typedef|typedef
name|char
name|bool
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|long
name|LINENUM
typedef|;
end_typedef

begin_comment
comment|/* must be signed */
end_comment

begin_typedef
typedef|typedef
name|unsigned
name|MEM
typedef|;
end_typedef

begin_comment
comment|/* what to feed malloc */
end_comment

begin_comment
comment|/* globals */
end_comment

begin_decl_stmt
name|EXT
name|int
name|Argc
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* guess */
end_comment

begin_decl_stmt
name|EXT
name|char
modifier|*
modifier|*
name|Argv
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|EXT
name|int
name|optind_last
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* for restarting plan_b */
end_comment

begin_decl_stmt
name|EXT
name|struct
name|stat
name|filestat
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* file statistics area */
end_comment

begin_decl_stmt
name|EXT
name|int
name|filemode
name|INIT
argument_list|(
literal|0644
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|EXT
name|char
name|buf
index|[
name|MAXLINELEN
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* general purpose buffer */
end_comment

begin_function_decl
name|EXT
name|FILE
modifier|*
name|ofp
name|INIT
parameter_list|(
name|Nullfp
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* output file pointer */
end_comment

begin_function_decl
name|EXT
name|FILE
modifier|*
name|rejfp
name|INIT
parameter_list|(
name|Nullfp
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* reject file pointer */
end_comment

begin_decl_stmt
name|EXT
name|int
name|myuid
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* cache getuid return value */
end_comment

begin_function_decl
name|EXT
name|bool
name|using_plan_a
name|INIT
parameter_list|(
name|TRUE
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* try to keep everything in memory */
end_comment

begin_function_decl
name|EXT
name|bool
name|out_of_mem
name|INIT
parameter_list|(
name|FALSE
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* ran out of memory in plan a */
end_comment

begin_define
define|#
directive|define
name|MAXFILEC
value|2
end_define

begin_decl_stmt
name|EXT
name|int
name|filec
name|INIT
argument_list|(
literal|0
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* how many file arguments? */
end_comment

begin_decl_stmt
name|EXT
name|char
modifier|*
name|filearg
index|[
name|MAXFILEC
index|]
decl_stmt|;
end_decl_stmt

begin_function_decl
name|EXT
name|bool
name|ok_to_create_file
name|INIT
parameter_list|(
name|FALSE
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|EXT
name|char
modifier|*
name|bestguess
name|INIT
parameter_list|(
name|Nullch
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* guess at correct filename */
end_comment

begin_function_decl
name|EXT
name|char
modifier|*
name|outname
name|INIT
parameter_list|(
name|Nullch
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
name|EXT
name|char
name|rejname
index|[
literal|128
index|]
decl_stmt|;
end_decl_stmt

begin_function_decl
name|EXT
name|char
modifier|*
name|origprae
name|INIT
parameter_list|(
name|Nullch
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
name|EXT
name|char
modifier|*
name|TMPOUTNAME
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|EXT
name|char
modifier|*
name|TMPINNAME
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|EXT
name|char
modifier|*
name|TMPREJNAME
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|EXT
name|char
modifier|*
name|TMPPATNAME
decl_stmt|;
end_decl_stmt

begin_function_decl
name|EXT
name|bool
name|toutkeep
name|INIT
parameter_list|(
name|FALSE
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|EXT
name|bool
name|trejkeep
name|INIT
parameter_list|(
name|FALSE
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
name|EXT
name|LINENUM
name|last_offset
name|INIT
argument_list|(
literal|0
argument_list|)
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|DEBUGGING
end_ifdef

begin_decl_stmt
name|EXT
name|int
name|debug
name|INIT
argument_list|(
literal|0
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
name|EXT
name|LINENUM
name|maxfuzz
name|INIT
argument_list|(
literal|2
argument_list|)
decl_stmt|;
end_decl_stmt

begin_function_decl
name|EXT
name|bool
name|force
name|INIT
parameter_list|(
name|FALSE
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|EXT
name|bool
name|batch
name|INIT
parameter_list|(
name|FALSE
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|EXT
name|bool
name|verbose
name|INIT
parameter_list|(
name|TRUE
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|EXT
name|bool
name|reverse
name|INIT
parameter_list|(
name|FALSE
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|EXT
name|bool
name|noreverse
name|INIT
parameter_list|(
name|FALSE
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|EXT
name|bool
name|skip_rest_of_patch
name|INIT
parameter_list|(
name|FALSE
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
name|EXT
name|int
name|strippath
name|INIT
argument_list|(
literal|957
argument_list|)
decl_stmt|;
end_decl_stmt

begin_function_decl
name|EXT
name|bool
name|canonicalize
name|INIT
parameter_list|(
name|FALSE
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|CONTEXT_DIFF
value|1
end_define

begin_define
define|#
directive|define
name|NORMAL_DIFF
value|2
end_define

begin_define
define|#
directive|define
name|ED_DIFF
value|3
end_define

begin_define
define|#
directive|define
name|NEW_CONTEXT_DIFF
value|4
end_define

begin_define
define|#
directive|define
name|UNI_DIFF
value|5
end_define

begin_decl_stmt
name|EXT
name|int
name|diff_type
name|INIT
argument_list|(
literal|0
argument_list|)
decl_stmt|;
end_decl_stmt

begin_function_decl
name|EXT
name|bool
name|do_defines
name|INIT
parameter_list|(
name|FALSE
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* patch using ifdef, ifndef, etc. */
end_comment

begin_decl_stmt
name|EXT
name|char
name|if_defined
index|[
literal|128
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* #ifdef xyzzy */
end_comment

begin_decl_stmt
name|EXT
name|char
name|not_defined
index|[
literal|128
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* #ifndef xyzzy */
end_comment

begin_decl_stmt
name|EXT
name|char
name|else_defined
index|[]
name|INIT
argument_list|(
literal|"#else\n"
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* #else */
end_comment

begin_decl_stmt
name|EXT
name|char
name|end_defined
index|[
literal|128
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* #endif xyzzy */
end_comment

begin_function_decl
name|EXT
name|char
modifier|*
name|revision
name|INIT
parameter_list|(
name|Nullch
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* prerequisite revision, if any */
end_comment

begin_include
include|#
directive|include
file|<errno.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|STDC_HEADERS
end_ifdef

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_include
include|#
directive|include
file|<string.h>
end_include

begin_else
else|#
directive|else
end_else

begin_decl_stmt
specifier|extern
name|int
name|errno
decl_stmt|;
end_decl_stmt

begin_function_decl
name|FILE
modifier|*
name|popen
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|malloc
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|realloc
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|long
name|atol
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|getenv
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|strcpy
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|strcat
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
name|char
modifier|*
name|mktemp
parameter_list|()
function_decl|;
end_function_decl

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_UNISTD_H
end_ifdef

begin_include
include|#
directive|include
file|<unistd.h>
end_include

begin_else
else|#
directive|else
end_else

begin_function_decl
name|long
name|lseek
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
name|defined
argument_list|(
name|_POSIX_VERSION
argument_list|)
operator|||
name|defined
argument_list|(
name|HAVE_FCNTL_H
argument_list|)
end_if

begin_include
include|#
directive|include
file|<fcntl.h>
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
name|S_ISDIR
argument_list|)
operator|&&
name|defined
argument_list|(
name|S_IFDIR
argument_list|)
end_if

begin_define
define|#
directive|define
name|S_ISDIR
parameter_list|(
name|m
parameter_list|)
value|(((m)& S_IFMT) == S_IFDIR)
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
name|S_ISREG
argument_list|)
operator|&&
name|defined
argument_list|(
name|S_IFREG
argument_list|)
end_if

begin_define
define|#
directive|define
name|S_ISREG
parameter_list|(
name|m
parameter_list|)
value|(((m)& S_IFMT) == S_IFREG)
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

