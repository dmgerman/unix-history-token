begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* "@(#)head.h 4.3 8/17/82" */
end_comment

begin_include
include|#
directive|include
file|<sys/vm.h>
end_include

begin_define
define|#
directive|define
name|PAGSIZ
value|(CLSIZE*NBPG)
end_define

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<setjmp.h>
end_include

begin_include
include|#
directive|include
file|<sgtty.h>
end_include

begin_include
include|#
directive|include
file|"old.h"
end_include

begin_include
include|#
directive|include
file|"defs.h"
end_include

begin_comment
comment|/* input line decoding */
end_comment

begin_decl_stmt
name|char
name|proc
index|[
literal|30
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* procedure name */
end_comment

begin_decl_stmt
name|int
name|integ
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* count or number in input */
end_comment

begin_decl_stmt
name|char
name|cmd
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* command letter */
end_comment

begin_decl_stmt
name|char
name|re
index|[
literal|128
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* regular expression */
end_comment

begin_decl_stmt
name|char
name|args
index|[
literal|128
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* arguments */
end_comment

begin_decl_stmt
name|char
modifier|*
name|argsp
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* pointer to args */
end_comment

begin_decl_stmt
name|char
name|var
index|[
literal|60
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* variable name */
end_comment

begin_decl_stmt
name|int
name|scallf
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* set to 1 iff procedure call */
end_comment

begin_decl_stmt
name|int
name|reflag
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* set to 1 iff re */
end_comment

begin_decl_stmt
name|int
name|redir
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* set to 1 iff forward search */
end_comment

begin_decl_stmt
name|int
name|colonflag
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* set to 1 iff colon typed */
end_comment

begin_decl_stmt
name|int
name|ncolonflag
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* set to 1 iff colon typed after number */
end_comment

begin_decl_stmt
name|int
name|percentflag
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* set to 1 iff percent symbol typed */
end_comment

begin_comment
comment|/* source file i/o */
end_comment

begin_decl_stmt
name|char
name|curfile
index|[
literal|120
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* name of file being edited */
end_comment

begin_decl_stmt
name|int
name|fline
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* line number in file */
end_comment

begin_decl_stmt
name|char
name|fbuf
index|[
name|BUFSIZ
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* current line from file */
end_comment

begin_decl_stmt
name|char
name|filework
index|[
literal|128
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* place to put filename */
end_comment

begin_decl_stmt
name|char
modifier|*
name|fp
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* pointer to it */
end_comment

begin_decl_stmt
name|int
name|nolines
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* set to 1 iff no lines in file */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|FLEXNAMES
end_ifdef

begin_decl_stmt
name|off_t
name|gstart
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* start of string table in a.out */
end_comment

begin_decl_stmt
name|char
modifier|*
name|strtab
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* string table from a.out * (in core!) */
end_comment

begin_decl_stmt
name|long
name|ssiz
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* size of string table (for range checks) */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* returned by slookup */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|FLEXNAMES
end_ifndef

begin_decl_stmt
name|char
name|sl_name
index|[
literal|8
index|]
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_decl_stmt
name|char
modifier|*
name|sl_name
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
name|u_char
name|sl_class
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|short
name|sl_type
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|sl_size
decl_stmt|,
name|sl_addr
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|subflag
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* procedure call information */
end_comment

begin_decl_stmt
name|int
name|scallx
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* procedure call in progress */
end_comment

begin_decl_stmt
name|ADDR
name|fps
decl_stmt|,
name|aps
decl_stmt|,
name|pcs
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* old stack frame */
end_comment

begin_decl_stmt
name|BKPTR
name|bkpts
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* old breakpoint */
end_comment

begin_decl_stmt
name|int
name|flagss
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  and its flags */
end_comment

begin_decl_stmt
name|char
name|dschar
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* '/' if value should be displayed */
end_comment

begin_comment
comment|/* symbol table info */
end_comment

begin_decl_stmt
name|long
name|ststart
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* offset of symbol table in a.out */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|VMUNIX
end_ifndef

begin_decl_stmt
name|struct
name|brbuf
name|sbuf
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* buffer for symbol table */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
name|long
name|extstart
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* offset of first external in a.out */
end_comment

begin_comment
comment|/* address info */
end_comment

begin_decl_stmt
name|ADDR
name|dot
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* current address */
end_comment

begin_decl_stmt
name|ADDR
name|callpc
decl_stmt|,
name|frame
decl_stmt|,
name|argp
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* current stack frame */
end_comment

begin_comment
comment|/* other */
end_comment

begin_decl_stmt
name|char
name|odesc
index|[
literal|10
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* descriptor of last displayed variable */
end_comment

begin_decl_stmt
name|ADDR
name|oaddr
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* address of last displayed variable */
end_comment

begin_decl_stmt
name|char
name|otype
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* type of last displayed variable */
end_comment

begin_decl_stmt
name|u_char
name|oclass
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* class of last displayed variable */
end_comment

begin_decl_stmt
name|char
name|oincr
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* size of last displayed variable */
end_comment

begin_decl_stmt
name|struct
name|sgttyb
name|sdbttym
decl_stmt|,
name|userttym
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* tty modes for sdb and user */
end_comment

begin_decl_stmt
name|char
name|oldargs
index|[
literal|128
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
name|prname
index|[
literal|50
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* print name used by outvar */
end_comment

begin_decl_stmt
name|jmp_buf
name|env
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* environment for setjmp, longjmp */
end_comment

begin_decl_stmt
name|int
name|debug
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* toggled by Y command */
end_comment

begin_decl_stmt
name|time_t
name|symtime
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* modification time of symfil */
end_comment

begin_decl_stmt
name|char
modifier|*
name|symfil
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|corfil
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|ADDR
name|exactaddr
decl_stmt|,
name|lnfaddr
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* set by adrtolineno() */
end_comment

begin_decl_stmt
name|ADDR
name|firstdata
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* lowest address of data */
end_comment

begin_define
define|#
directive|define
name|STABMASK
value|0376
end_define

begin_define
define|#
directive|define
name|WINDOW
value|10
end_define

begin_comment
comment|/* window size for display commands */
end_comment

begin_define
define|#
directive|define
name|COMMANDS
value|"\004\"+-=!/BCDMQRSTXabcdegklmpqrstwxzVXY"
end_define

begin_comment
comment|/* each sdb command must appear here */
end_comment

begin_define
define|#
directive|define
name|NUMARGS
value|16
end_define

begin_comment
comment|/* number of args allowed in sub call */
end_comment

begin_define
define|#
directive|define
name|SUBSTSP
value|512
end_define

begin_comment
comment|/* length of space for sub args and strings */
end_comment

begin_define
define|#
directive|define
name|WORDSIZE
value|4
end_define

begin_comment
comment|/* wordsize in bytes on this machine */
end_comment

begin_define
define|#
directive|define
name|BIGNUM
value|0x7fffffff
end_define

begin_define
define|#
directive|define
name|MAXADDR
value|1L<<30
end_define

begin_struct
struct|struct
name|filet
block|{
ifndef|#
directive|ifndef
name|FLEXNAMES
name|char
name|sfilename
index|[
literal|31
index|]
decl_stmt|;
comment|/* source file name */
else|#
directive|else
name|char
modifier|*
name|sfilename
decl_stmt|;
endif|#
directive|endif
name|char
name|lineflag
decl_stmt|;
comment|/* set iff this is a '#line' file */
name|ADDR
name|faddr
decl_stmt|;
comment|/* address in core */
name|long
name|stf_offset
decl_stmt|;
comment|/* offset in a.out */
block|}
modifier|*
name|files
struct|,
modifier|*
name|badfile
struct|;
end_struct

begin_struct
struct|struct
name|proct
block|{
ifndef|#
directive|ifndef
name|FLEXNAMES
name|char
name|pname
index|[
literal|8
index|]
decl_stmt|;
comment|/* procedure name */
else|#
directive|else
name|char
modifier|*
name|pname
decl_stmt|;
endif|#
directive|endif
name|ADDR
name|paddr
decl_stmt|;
comment|/* address in core */
name|long
name|st_offset
decl_stmt|;
comment|/* offset in a.out */
name|struct
name|filet
modifier|*
name|sfptr
decl_stmt|;
comment|/* source file name pointer */
name|int
name|lineno
decl_stmt|;
comment|/* line number in source file */
name|char
name|entrypt
decl_stmt|;
comment|/* 1 iff a F77 entry */
block|}
modifier|*
name|procs
struct|,
modifier|*
name|badproc
struct|;
end_struct

begin_define
define|#
directive|define
name|PROCINCR
value|20
end_define

begin_define
define|#
directive|define
name|FILEINCR
value|10
end_define

begin_define
define|#
directive|define
name|varchar
parameter_list|(
name|x
parameter_list|)
value|((x>='A'&& x<='Z') || (x>='a'&&  x<='z') || x == '_' || x == '.' || x == '[' || x == ']' || x == '-' || x == '>' || x == '*' || x == '?')
end_define

begin_define
define|#
directive|define
name|number
parameter_list|(
name|x
parameter_list|)
value|(x>= '0'&& x<= '9')
end_define

begin_decl_stmt
name|char
modifier|*
name|readline
argument_list|()
decl_stmt|,
name|readchar
argument_list|()
decl_stmt|,
name|rdc
argument_list|()
decl_stmt|;
end_decl_stmt

begin_function_decl
name|char
modifier|*
name|cpname
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
name|char
modifier|*
name|cpstr
argument_list|()
decl_stmt|,
modifier|*
name|cpall
argument_list|()
decl_stmt|;
end_decl_stmt

begin_function_decl
name|char
modifier|*
name|sbrk
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|typetodesc
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
name|int
name|octdigit
argument_list|()
decl_stmt|,
name|decdigit
argument_list|()
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|hexdigit
argument_list|()
expr_stmt|;
end_expr_stmt

begin_decl_stmt
name|int
name|octconv
argument_list|()
decl_stmt|,
name|decconv
argument_list|()
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|hexconv
argument_list|()
expr_stmt|;
end_expr_stmt

begin_decl_stmt
name|long
name|readint
argument_list|()
decl_stmt|,
name|rint
argument_list|()
decl_stmt|;
end_decl_stmt

begin_function_decl
name|long
name|adrtostoffset
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
name|long
name|getval
argument_list|()
decl_stmt|,
name|argvalue
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|long
name|slookup
argument_list|()
decl_stmt|,
name|globallookup
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|ADDR
name|varaddr
argument_list|()
decl_stmt|,
name|dispvar
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|ADDR
name|extaddr
argument_list|()
decl_stmt|,
name|formaddr
argument_list|()
decl_stmt|,
name|stackreg
argument_list|()
decl_stmt|;
end_decl_stmt

begin_function_decl
name|struct
name|proct
modifier|*
name|curproc
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|proct
modifier|*
name|findproc
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|proct
modifier|*
name|adrtoprocp
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
name|struct
name|proct
modifier|*
name|initframe
argument_list|()
decl_stmt|,
modifier|*
name|nextframe
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|filet
modifier|*
name|findfile
argument_list|()
decl_stmt|,
modifier|*
name|adrtofilep
argument_list|()
decl_stmt|;
end_decl_stmt

end_unit

