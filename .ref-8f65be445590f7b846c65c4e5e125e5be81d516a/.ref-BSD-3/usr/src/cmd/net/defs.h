begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
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
file|<stdio.h>
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

begin_define
define|#
directive|define
name|SUPERUSER
value|0
end_define

begin_comment
comment|/* adjustable parameters, must be same on all machines */
end_comment

begin_comment
comment|/* MAXFILE is the file size limit.  If changed on one machine     but not the others, files bigger than the common minimum will    be flushed with no guarantee of err msgs. Thus if one link    is to be of a different limit than the others, make sure the users    know this. */
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
name|MAXFILELARGE
value|500000L
end_define

begin_comment
comment|/* the version of the protocol the network speaks */
end_comment

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

begin_comment
comment|/* the time constant added to all time stamps sent around the net */
end_comment

begin_define
define|#
directive|define
name|TIMEBASE
value|282098011L
end_define

begin_comment
comment|/* the number of mail forwarding hops allowed before looping is detected */
end_comment

begin_define
define|#
directive|define
name|MAXHOPS
value|30
end_define

begin_comment
comment|/* non-adjustable constants */
end_comment

begin_comment
comment|/* PARMLIST = max size of variable length parm list used in protocol */
end_comment

begin_define
define|#
directive|define
name|PARMLIST
value|2000
end_define

begin_comment
comment|/* FNS = max length of file name string */
end_comment

begin_define
define|#
directive|define
name|FNS
value|50
end_define

begin_comment
comment|/* NS = length of UNIX user name*/
end_comment

begin_define
define|#
directive|define
name|NS
value|10
end_define

begin_comment
comment|/* returned by prot.c */
end_comment

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

begin_define
define|#
directive|define
name|M_OTHER
value|6
end_define

begin_comment
comment|/* codes for cflag, powers of two, max (8 bits - 'a'), others may be added */
end_comment

begin_comment
comment|/* F_QUIET means send back only error messages and output of programs,    don't send back confimation with no data */
end_comment

begin_comment
comment|/* F_NONOTIFY means don't send back anything, ever,     even if there are errors (used for responses, etc.) */
end_comment

begin_define
define|#
directive|define
name|F_QUIET
value|02
end_define

begin_define
define|#
directive|define
name|F_NONOTIFY
value|04
end_define

begin_comment
comment|/*     at this point bring in the locally-dependent definitions.    this way the above parms may be altered. */
end_comment

begin_include
include|#
directive|include
file|"mach.h"
end_include

begin_include
include|#
directive|include
file|"Paths.h"
end_include

begin_comment
comment|/* structure declarations */
end_comment

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
name|SnFromUid
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
decl_stmt|,
modifier|*
name|SnCurrent
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
decl_stmt|,
modifier|*
name|PwdCurrent
argument_list|()
decl_stmt|,
modifier|*
name|getpwent
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

begin_comment
comment|/* variables */
end_comment

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
name|Bsh
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
name|machtype
index|[]
decl_stmt|,
name|remtable
index|[]
decl_stmt|;
end_decl_stmt

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
name|char
name|quiet
decl_stmt|;
comment|/* if true, only send a response back if rc !=0 				   or if there is stdout or stderr */
name|char
name|sTtyname
index|[
literal|20
index|]
decl_stmt|;
comment|/* tty user is on,full name e.g. /dev/tty0 */
name|char
name|sCmdAct
index|[
name|BUFSIZ
index|]
decl_stmt|;
comment|/* the actual command the net will exec */
name|char
name|sCmdVirt
index|[
name|BUFSIZ
index|]
decl_stmt|;
comment|/* the command the user thinks he is getting */
name|long
name|lTtytime
decl_stmt|;
comment|/* the time recorded for tty login in utmp */
block|}
name|status
struct|;
end_struct

end_unit

