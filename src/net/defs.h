begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Copyright (c) 1979 Regents of the University of California */
end_comment

begin_define
define|#
directive|define
name|THEKEY
value|"hellotherekids"
end_define

begin_comment
comment|/*    get all the machine dependencies, standard I/O, and the    configuration definitions (LOCAL machine, etc.) */
end_comment

begin_include
include|#
directive|include
file|"mach.h"
end_include

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|"Paths.h"
end_include

begin_define
define|#
directive|define
name|min
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|(a> b ? b : a)
end_define

begin_define
define|#
directive|define
name|getremote
parameter_list|(
name|S
parameter_list|)
value|(remtable[(S)-'a'])
end_define

begin_comment
comment|/* adjustable parameters, may differ per machine */
end_comment

begin_define
define|#
directive|define
name|MAXBREAD
value|3
end_define

begin_define
define|#
directive|define
name|ATIME
value|20
end_define

begin_define
define|#
directive|define
name|DBV
value|0
end_define

begin_define
define|#
directive|define
name|BLOCKSIZE
value|500
end_define

begin_define
define|#
directive|define
name|SIZE
value|100
end_define

begin_define
define|#
directive|define
name|INITFILE
value|"/usr/net/initfile"
end_define

begin_define
define|#
directive|define
name|NSEND
value|20
end_define

begin_define
define|#
directive|define
name|SAMPL
value|3600
end_define

begin_comment
comment|/* 1 hour = 3600 */
end_comment

begin_define
define|#
directive|define
name|BIGSAMPL
value|64800L
end_define

begin_comment
comment|/* 18 hours = 64800L */
end_comment

begin_define
define|#
directive|define
name|LINKS
value|9
end_define

begin_comment
comment|/* adjustable parameters, must be same on all machines */
end_comment

begin_define
define|#
directive|define
name|MAXFILE
value|100000L
end_define

begin_define
define|#
directive|define
name|VMAJOR
value|1
end_define

begin_define
define|#
directive|define
name|VMINOR
value|0
end_define

begin_define
define|#
directive|define
name|TIMEBASE
value|282098011L
end_define

begin_comment
comment|/* non-adjustable constants */
end_comment

begin_define
define|#
directive|define
name|FNS
value|40
end_define

begin_define
define|#
directive|define
name|BFS
value|260
end_define

begin_define
define|#
directive|define
name|NS
value|10
end_define

begin_define
define|#
directive|define
name|BROKENREAD
value|-2
end_define

begin_define
define|#
directive|define
name|WRITEFAIL
value|-3
end_define

begin_define
define|#
directive|define
name|INCR
value|040
end_define

begin_define
define|#
directive|define
name|MINSIZE
value|50
end_define

begin_comment
comment|/* flags for packet type (pcode) */
end_comment

begin_define
define|#
directive|define
name|RESET
value|01
end_define

begin_define
define|#
directive|define
name|REQUEST
value|02
end_define

begin_define
define|#
directive|define
name|ACK
value|04
end_define

begin_define
define|#
directive|define
name|PURGE
value|020
end_define

begin_comment
comment|/* flags for mach type */
end_comment

begin_define
define|#
directive|define
name|M_CORY
value|1
end_define

begin_define
define|#
directive|define
name|M_CC
value|2
end_define

begin_define
define|#
directive|define
name|M_VAX
value|3
end_define

begin_define
define|#
directive|define
name|M_INGRES
value|4
end_define

begin_define
define|#
directive|define
name|M_SRC
value|5
end_define

begin_comment
comment|/* codes for cflag, powers of two */
end_comment

begin_define
define|#
directive|define
name|F_NONOTIFY
value|04
end_define

begin_comment
comment|/* tokens, returned by parser */
end_comment

begin_define
define|#
directive|define
name|MACHINE
value|1
end_define

begin_define
define|#
directive|define
name|LOGIN
value|2
end_define

begin_define
define|#
directive|define
name|PASSWORD
value|3
end_define

begin_define
define|#
directive|define
name|NOTIFY
value|5
end_define

begin_define
define|#
directive|define
name|COMMAND
value|7
end_define

begin_define
define|#
directive|define
name|ID
value|8
end_define

begin_define
define|#
directive|define
name|YES
value|9
end_define

begin_define
define|#
directive|define
name|DEFAULT
value|10
end_define

begin_define
define|#
directive|define
name|WRITE
value|11
end_define

begin_define
define|#
directive|define
name|NO
value|12
end_define

begin_define
define|#
directive|define
name|FORCE
value|13
end_define

begin_define
define|#
directive|define
name|LOCALTOK
value|14
end_define

begin_define
define|#
directive|define
name|LINK
value|15
end_define

begin_define
define|#
directive|define
name|SPEED
value|16
end_define

begin_define
define|#
directive|define
name|VAXTOVAX
value|17
end_define

begin_define
define|#
directive|define
name|LENGTH
value|18
end_define

begin_define
define|#
directive|define
name|DEBUGTOK
value|19
end_define

begin_define
define|#
directive|define
name|ALTIME
value|20
end_define

begin_define
define|#
directive|define
name|ALCOUNT
value|21
end_define

begin_decl_stmt
name|int
name|debugflg
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
name|remote
decl_stmt|,
name|local
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* must be global, remote is not initialized*/
end_comment

begin_decl_stmt
name|char
name|netcmd
index|[]
decl_stmt|,
name|senddir
index|[]
decl_stmt|,
name|resfile
index|[]
decl_stmt|,
name|logfile
index|[]
decl_stmt|,
name|writecmd
index|[]
decl_stmt|,
name|mailcmd
index|[]
decl_stmt|,
name|Bsh
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
name|cmd
index|[
name|BFS
operator|*
literal|2
index|]
decl_stmt|,
name|realcmd
index|[
name|BFS
operator|*
literal|2
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
name|device
index|[
literal|20
index|]
decl_stmt|,
name|machtype
index|[]
decl_stmt|,
name|remtable
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|long
name|ltime
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|short
name|masterseqno
decl_stmt|,
name|lastseqno
decl_stmt|;
end_decl_stmt

begin_extern
extern|extern errno;
end_extern

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|sys_errlist
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|datasize
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
name|ttystr
index|[
literal|20
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|FILE
modifier|*
name|readtty
decl_stmt|,
modifier|*
name|writetty
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|readfd
decl_stmt|,
name|writefd
decl_stmt|,
name|pipesim
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|maxbread
decl_stmt|,
name|atime
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* used by parser which reads netrc and initfile */
end_comment

begin_struct
struct|struct
name|tokstruct
block|{
name|char
modifier|*
name|tokstr
decl_stmt|;
name|int
name|tval
decl_stmt|;
block|}
name|toktab
index|[]
struct|;
end_struct

begin_comment
comment|/* used by parser to parse filenames, e.g. mach:file */
end_comment

begin_struct
struct|struct
name|fd
block|{
name|char
name|mach
decl_stmt|;
name|char
modifier|*
name|fn
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* used to pass around info about user */
end_comment

begin_struct
struct|struct
name|info
block|{
name|char
name|login
index|[
name|NS
index|]
decl_stmt|;
name|char
name|mpasswd
index|[
literal|20
index|]
decl_stmt|;
name|int
name|muid
decl_stmt|;
comment|/* combines uid and gid for FUID */
name|int
name|mgid
decl_stmt|;
comment|/* unused for FUID */
name|char
name|dir
index|[
name|FNS
index|]
decl_stmt|;
name|char
name|loginshell
index|[
name|FNS
index|]
decl_stmt|;
name|char
name|localname
index|[
name|NS
index|]
decl_stmt|;
name|int
name|jobno
decl_stmt|;
name|char
name|defcmd
index|[
name|FNS
index|]
decl_stmt|;
name|char
name|force
decl_stmt|;
comment|/* if true, always prompt for login and pass */
name|char
name|nonotify
decl_stmt|;
comment|/* if true, don't send anything back */
name|char
name|nowrite
decl_stmt|;
comment|/* if true, mail rather than write to user */
block|}
name|status
struct|;
end_struct

begin_decl_stmt
name|struct
name|stat
name|statbuf
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|direct
name|dirbuf
decl_stmt|;
end_decl_stmt

begin_struct
struct|struct
name|packet
block|{
name|short
name|seqno
decl_stmt|;
name|char
name|pcode
decl_stmt|;
name|char
name|len
decl_stmt|;
name|char
name|chksum
decl_stmt|;
name|char
name|data
index|[
literal|1
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* the chksum is only on a per-perpacket level,    which is not enough.    There should be a checksum on the entire file as well.    */
end_comment

begin_struct
struct|struct
name|dumpstruc
block|{
name|long
name|shorttime
decl_stmt|,
name|longtime
decl_stmt|,
name|elaptot
decl_stmt|,
name|waittime
decl_stmt|,
name|waittot
decl_stmt|;
comment|/* in secs */
name|long
name|outime
decl_stmt|,
name|ostime
decl_stmt|;
comment|/* in 60ths sec */
name|long
name|nbytesent
decl_stmt|,
name|nbytercv
decl_stmt|,
name|bytetot
decl_stmt|;
comment|/* in bytes */
name|int
name|nretrans
decl_stmt|,
name|nabnormal
decl_stmt|,
name|nloop
decl_stmt|;
name|int
name|ncksum
decl_stmt|,
name|npacksent
decl_stmt|,
name|npackrcv
decl_stmt|;
name|int
name|nnetcp
decl_stmt|,
name|nnetlpr
decl_stmt|,
name|nsmail
decl_stmt|,
name|nnetmail
decl_stmt|,
name|nresp
decl_stmt|,
name|nnet
decl_stmt|;
name|int
name|npass
decl_stmt|,
name|nsend
decl_stmt|,
name|nsendfail
decl_stmt|;
block|}
name|dump
struct|;
end_struct

begin_struct
struct|struct
name|bstruct
block|{
name|char
modifier|*
name|bname
decl_stmt|;
name|char
name|bmach
decl_stmt|;
block|}
name|btable
index|[]
struct|;
end_struct

begin_comment
comment|/* functions */
end_comment

begin_decl_stmt
name|char
modifier|*
name|calloc
argument_list|()
decl_stmt|,
modifier|*
name|crypt
argument_list|()
decl_stmt|,
modifier|*
name|ctime
argument_list|()
decl_stmt|,
modifier|*
name|getenv
argument_list|()
decl_stmt|,
modifier|*
name|longname
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|getun
argument_list|()
decl_stmt|,
modifier|*
name|comptime
argument_list|()
decl_stmt|,
modifier|*
name|getpass
argument_list|()
decl_stmt|,
modifier|*
name|handlesp
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|FILE
modifier|*
name|mopen
argument_list|()
decl_stmt|,
modifier|*
name|fdopen
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|passwd
modifier|*
name|getpwnam
argument_list|()
decl_stmt|,
modifier|*
name|getpwuid
argument_list|()
decl_stmt|;
end_decl_stmt

begin_function_decl
name|struct
name|packet
modifier|*
name|getpacket
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
name|long
name|fixuplong
argument_list|()
decl_stmt|,
name|atol
argument_list|()
decl_stmt|;
end_decl_stmt

end_unit

