begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	defs.h	4.4	85/03/19	*/
end_comment

begin_empty
empty|#
end_empty

begin_comment
comment|/*  *	UNIX shell  */
end_comment

begin_comment
comment|/* error exits from various parts of shell */
end_comment

begin_define
define|#
directive|define
name|ERROR
value|1
end_define

begin_define
define|#
directive|define
name|SYNBAD
value|2
end_define

begin_define
define|#
directive|define
name|SIGFAIL
value|3
end_define

begin_define
define|#
directive|define
name|SIGFLG
value|0200
end_define

begin_comment
comment|/* command tree */
end_comment

begin_define
define|#
directive|define
name|FPRS
value|020
end_define

begin_define
define|#
directive|define
name|FINT
value|040
end_define

begin_define
define|#
directive|define
name|FAMP
value|0100
end_define

begin_define
define|#
directive|define
name|FPIN
value|0400
end_define

begin_define
define|#
directive|define
name|FPOU
value|01000
end_define

begin_define
define|#
directive|define
name|FPCL
value|02000
end_define

begin_define
define|#
directive|define
name|FCMD
value|04000
end_define

begin_define
define|#
directive|define
name|COMMSK
value|017
end_define

begin_define
define|#
directive|define
name|TCOM
value|0
end_define

begin_define
define|#
directive|define
name|TPAR
value|1
end_define

begin_define
define|#
directive|define
name|TFIL
value|2
end_define

begin_define
define|#
directive|define
name|TLST
value|3
end_define

begin_define
define|#
directive|define
name|TIF
value|4
end_define

begin_define
define|#
directive|define
name|TWH
value|5
end_define

begin_define
define|#
directive|define
name|TUN
value|6
end_define

begin_define
define|#
directive|define
name|TSW
value|7
end_define

begin_define
define|#
directive|define
name|TAND
value|8
end_define

begin_define
define|#
directive|define
name|TORF
value|9
end_define

begin_define
define|#
directive|define
name|TFORK
value|10
end_define

begin_define
define|#
directive|define
name|TFOR
value|11
end_define

begin_comment
comment|/* execute table */
end_comment

begin_define
define|#
directive|define
name|SYSSET
value|1
end_define

begin_define
define|#
directive|define
name|SYSCD
value|2
end_define

begin_define
define|#
directive|define
name|SYSEXEC
value|3
end_define

begin_define
define|#
directive|define
name|SYSLOGIN
value|4
end_define

begin_define
define|#
directive|define
name|SYSTRAP
value|5
end_define

begin_define
define|#
directive|define
name|SYSEXIT
value|6
end_define

begin_define
define|#
directive|define
name|SYSSHFT
value|7
end_define

begin_define
define|#
directive|define
name|SYSWAIT
value|8
end_define

begin_define
define|#
directive|define
name|SYSCONT
value|9
end_define

begin_define
define|#
directive|define
name|SYSBREAK
value|10
end_define

begin_define
define|#
directive|define
name|SYSEVAL
value|11
end_define

begin_define
define|#
directive|define
name|SYSDOT
value|12
end_define

begin_define
define|#
directive|define
name|SYSRDONLY
value|13
end_define

begin_define
define|#
directive|define
name|SYSTIMES
value|14
end_define

begin_define
define|#
directive|define
name|SYSXPORT
value|15
end_define

begin_define
define|#
directive|define
name|SYSNULL
value|16
end_define

begin_define
define|#
directive|define
name|SYSREAD
value|17
end_define

begin_define
define|#
directive|define
name|SYSTST
value|18
end_define

begin_define
define|#
directive|define
name|SYSUMASK
value|19
end_define

begin_comment
comment|/* used for input and output of shell */
end_comment

begin_define
define|#
directive|define
name|INIO
value|10
end_define

begin_define
define|#
directive|define
name|OTIO
value|11
end_define

begin_comment
comment|/*io nodes*/
end_comment

begin_define
define|#
directive|define
name|USERIO
value|10
end_define

begin_define
define|#
directive|define
name|IOUFD
value|15
end_define

begin_define
define|#
directive|define
name|IODOC
value|16
end_define

begin_define
define|#
directive|define
name|IOPUT
value|32
end_define

begin_define
define|#
directive|define
name|IOAPP
value|64
end_define

begin_define
define|#
directive|define
name|IOMOV
value|128
end_define

begin_define
define|#
directive|define
name|IORDW
value|256
end_define

begin_define
define|#
directive|define
name|INPIPE
value|0
end_define

begin_define
define|#
directive|define
name|OTPIPE
value|1
end_define

begin_comment
comment|/* arg list terminator */
end_comment

begin_define
define|#
directive|define
name|ENDARGS
value|0
end_define

begin_include
include|#
directive|include
file|"mac.h"
end_include

begin_include
include|#
directive|include
file|"mode.h"
end_include

begin_include
include|#
directive|include
file|"name.h"
end_include

begin_comment
comment|/* result type declarations */
end_comment

begin_define
define|#
directive|define
name|alloc
value|malloc
end_define

begin_function_decl
name|ADDRESS
name|alloc
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|VOID
name|addblok
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|STRING
name|make
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|STRING
name|movstr
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|TREPTR
name|cmd
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|TREPTR
name|makefork
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|NAMPTR
name|lookup
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|VOID
name|setname
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|VOID
name|setargs
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|DOLPTR
name|useargs
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|REAL
name|expr
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|STRING
name|catpath
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|STRING
name|getpath
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|STRING
modifier|*
name|scan
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|STRING
name|mactrim
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|STRING
name|macro
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|STRING
name|execs
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|VOID
name|await
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|VOID
name|post
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|STRING
name|copyto
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|VOID
name|exname
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|STRING
name|staknam
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|VOID
name|printnam
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|VOID
name|printflg
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|VOID
name|prs
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|VOID
name|prc
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|VOID
name|setupenv
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|STRING
modifier|*
name|setenv
parameter_list|()
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|attrib
parameter_list|(
name|n
parameter_list|,
name|f
parameter_list|)
value|(n->namflg |= f)
end_define

begin_define
define|#
directive|define
name|round
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|(((int)((ADR(a)+b)-1))&~((b)-1))
end_define

begin_define
define|#
directive|define
name|closepipe
parameter_list|(
name|x
parameter_list|)
value|(close(x[INPIPE]), close(x[OTPIPE]))
end_define

begin_define
define|#
directive|define
name|eq
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|(cf(a,b)==0)
end_define

begin_define
define|#
directive|define
name|max
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|((a)>(b)?(a):(b))
end_define

begin_define
define|#
directive|define
name|assert
parameter_list|(
name|x
parameter_list|)
value|;
end_define

begin_comment
comment|/* temp files and io */
end_comment

begin_decl_stmt
name|UFD
name|output
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|INT
name|ioset
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|IOPTR
name|iotemp
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* files to be deleted sometime */
end_comment

begin_decl_stmt
name|IOPTR
name|iopend
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* documents waiting to be read at NL */
end_comment

begin_comment
comment|/* substitution */
end_comment

begin_decl_stmt
name|INT
name|dolc
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|STRING
modifier|*
name|dolv
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|DOLPTR
name|argfor
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|ARGPTR
name|gchain
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* stack */
end_comment

begin_define
define|#
directive|define
name|BLK
parameter_list|(
name|x
parameter_list|)
value|((BLKPTR)(x))
end_define

begin_define
define|#
directive|define
name|BYT
parameter_list|(
name|x
parameter_list|)
value|((BYTPTR)(x))
end_define

begin_define
define|#
directive|define
name|STK
parameter_list|(
name|x
parameter_list|)
value|((STKPTR)(x))
end_define

begin_define
define|#
directive|define
name|ADR
parameter_list|(
name|x
parameter_list|)
value|((char*)(x))
end_define

begin_comment
comment|/* stak stuff */
end_comment

begin_include
include|#
directive|include
file|"stak.h"
end_include

begin_comment
comment|/* string constants */
end_comment

begin_decl_stmt
name|MSG
name|atline
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|MSG
name|readmsg
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|MSG
name|colon
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|MSG
name|minus
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|MSG
name|nullstr
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|MSG
name|sptbnl
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|MSG
name|unexpected
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|MSG
name|endoffile
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|MSG
name|synmsg
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* name tree and words */
end_comment

begin_decl_stmt
name|SYSTAB
name|reserved
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|INT
name|wdval
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|INT
name|wdnum
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|ARGPTR
name|wdarg
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|INT
name|wdset
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|BOOL
name|reserv
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* prompting */
end_comment

begin_decl_stmt
name|MSG
name|stdprompt
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|MSG
name|supprompt
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|MSG
name|profile
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* built in names */
end_comment

begin_decl_stmt
name|NAMNOD
name|fngnod
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|NAMNOD
name|ifsnod
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|NAMNOD
name|homenod
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|NAMNOD
name|mailnod
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|NAMNOD
name|pathnod
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|NAMNOD
name|ps1nod
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|NAMNOD
name|ps2nod
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* special names */
end_comment

begin_decl_stmt
name|MSG
name|flagadr
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|STRING
name|cmdadr
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|STRING
name|exitadr
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|STRING
name|dolladr
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|STRING
name|pcsadr
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|STRING
name|pidadr
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|MSG
name|defpath
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* names always present */
end_comment

begin_decl_stmt
name|MSG
name|mailname
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|MSG
name|homename
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|MSG
name|pathname
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|MSG
name|fngname
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|MSG
name|ifsname
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|MSG
name|ps1name
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|MSG
name|ps2name
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* transput */
end_comment

begin_decl_stmt
name|CHAR
name|tmpout
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|STRING
name|tmpnam
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|INT
name|serial
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|TMPNAM
value|7
end_define

begin_decl_stmt
name|FILE
name|standin
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|input
value|(standin->fdes)
end_define

begin_define
define|#
directive|define
name|eof
value|(standin->feof)
end_define

begin_decl_stmt
name|INT
name|peekc
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|STRING
name|comdiv
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|MSG
name|devnull
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* flags */
end_comment

begin_define
define|#
directive|define
name|noexec
value|01
end_define

begin_define
define|#
directive|define
name|intflg
value|02
end_define

begin_define
define|#
directive|define
name|prompt
value|04
end_define

begin_define
define|#
directive|define
name|setflg
value|010
end_define

begin_define
define|#
directive|define
name|errflg
value|020
end_define

begin_define
define|#
directive|define
name|ttyflg
value|040
end_define

begin_define
define|#
directive|define
name|forked
value|0100
end_define

begin_define
define|#
directive|define
name|oneflg
value|0200
end_define

begin_define
define|#
directive|define
name|rshflg
value|0400
end_define

begin_define
define|#
directive|define
name|waiting
value|01000
end_define

begin_define
define|#
directive|define
name|stdflg
value|02000
end_define

begin_define
define|#
directive|define
name|execpr
value|04000
end_define

begin_define
define|#
directive|define
name|readpr
value|010000
end_define

begin_define
define|#
directive|define
name|keyflg
value|020000
end_define

begin_define
define|#
directive|define
name|batchflg
value|040000
end_define

begin_decl_stmt
name|INT
name|flags
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* error exits from various parts of shell */
end_comment

begin_include
include|#
directive|include
file|<setjmp.h>
end_include

begin_decl_stmt
name|jmp_buf
name|subshell
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|jmp_buf
name|errshell
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|jmp_buf
name|INTbuf
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* fault handling */
end_comment

begin_include
include|#
directive|include
file|"brkincr.h"
end_include

begin_decl_stmt
name|POS
name|brkincr
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|MINTRAP
value|0
end_define

begin_define
define|#
directive|define
name|MAXTRAP
value|32
end_define

begin_define
define|#
directive|define
name|INTR
value|2
end_define

begin_define
define|#
directive|define
name|QUIT
value|3
end_define

begin_define
define|#
directive|define
name|MEMF
value|11
end_define

begin_define
define|#
directive|define
name|ALARM
value|14
end_define

begin_define
define|#
directive|define
name|KILL
value|15
end_define

begin_define
define|#
directive|define
name|TRAPSET
value|2
end_define

begin_define
define|#
directive|define
name|SIGSET
value|4
end_define

begin_define
define|#
directive|define
name|SIGMOD
value|8
end_define

begin_function_decl
name|VOID
name|fault
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
name|BOOL
name|trapnote
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|STRING
name|trapcom
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|BOOL
name|trapflg
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|BOOL
name|trapjmp
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* name tree and words */
end_comment

begin_decl_stmt
name|STRING
modifier|*
name|environ
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|CHAR
name|numbuf
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|MSG
name|export
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|MSG
name|readonly
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* execflgs */
end_comment

begin_decl_stmt
name|INT
name|exitval
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|BOOL
name|execbrk
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|INT
name|loopcnt
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|INT
name|breakcnt
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* messages */
end_comment

begin_decl_stmt
name|MSG
name|mailmsg
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|MSG
name|coredump
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|MSG
name|badopt
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|MSG
name|badparam
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|MSG
name|badsub
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|MSG
name|nospace
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|MSG
name|notfound
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|MSG
name|badtrap
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|MSG
name|baddir
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|MSG
name|badshift
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|MSG
name|illegal
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|MSG
name|restricted
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|MSG
name|execpmsg
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|MSG
name|notid
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|MSG
name|wtfailed
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|MSG
name|badcreate
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|MSG
name|piperr
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|MSG
name|badopen
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|MSG
name|badnum
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|MSG
name|arglist
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|MSG
name|txtbsy
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|MSG
name|toobig
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|MSG
name|badexec
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|MSG
name|notfound
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|MSG
name|badfile
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|address
name|end
index|[]
decl_stmt|;
end_decl_stmt

begin_include
include|#
directive|include
file|"ctype.h"
end_include

end_unit

