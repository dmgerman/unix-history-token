begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	@(#)defs.h	4.1	(Berkeley)	%G%	*/
end_comment

begin_comment
comment|/* sccs id variable */
end_comment

begin_decl_stmt
specifier|static
name|char
modifier|*
name|defs_h_sid
init|=
literal|"@(#)defs.h	1.5"
decl_stmt|;
end_decl_stmt

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
comment|/* the size of routing tables, etc. */
end_comment

begin_define
define|#
directive|define
name|MAXINX
value|26
end_define

begin_comment
comment|/* adjustable parameters, must be same on all machines */
end_comment

begin_comment
comment|/* MAXFILELARGE is the file size limit.  If changed on one machine     but not the others, files bigger than the common minimum will    be flushed with no guarantee of err msgs. Thus if one link    is to be of a different limit than the others, make sure the users    know this.    MAXDAYFILE is the largest file that will be transmitted across the    network during the day on CC machines. */
end_comment

begin_define
define|#
directive|define
name|MAXFILELARGE
value|500000L
end_define

begin_define
define|#
directive|define
name|MAXDAYFILE
value|200000L
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
comment|/* the buffer size used in prot.c */
end_comment

begin_define
define|#
directive|define
name|MAXNBUF
value|1024
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
value|80
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

begin_define
define|#
directive|define
name|TRUE
value|1
end_define

begin_define
define|#
directive|define
name|FALSE
value|0
end_define

begin_comment
comment|/* flags for packet type (pcode) */
end_comment

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
name|M_CC
value|2
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

begin_comment
comment|/* strings for the netsend and netrecieve logins */
end_comment

begin_define
define|#
directive|define
name|RESP
value|"hello hello this is a network"
end_define

begin_define
define|#
directive|define
name|RESPSIZE
value|29
end_define

begin_define
define|#
directive|define
name|QUERY
value|"This login for network use only"
end_define

begin_define
define|#
directive|define
name|QSIZE
value|31
end_define

begin_define
define|#
directive|define
name|WHOAREYOU
value|"who are you?"
end_define

begin_define
define|#
directive|define
name|WHOSIZE
value|12
end_define

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
comment|/* bring in the exit codes */
end_comment

begin_include
include|#
directive|include
file|<sysexits.h>
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
name|short
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

begin_decl_stmt
name|struct
name|packet
modifier|*
name|packptr
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* just used to get the sizeof to work */
end_comment

begin_define
define|#
directive|define
name|ACKLENGTH
value|(sizeof *packptr - 1)
end_define

begin_comment
comment|/* these are the lengths to be read and writ if using high-speed block dev. */
end_comment

begin_comment
comment|/* must be bigger than ACKLENGTH */
end_comment

begin_define
define|#
directive|define
name|SENDLEN
value|256
end_define

begin_comment
comment|/* the chksum is only on a per-perpacket level,    which is not enough.    There should be a checksum on the entire file as well.    */
end_comment

begin_struct
struct|struct
name|dumpstruc
block|{
name|long
name|longtime
decl_stmt|,
name|elaptot
decl_stmt|;
comment|/* in secs */
name|long
name|nbytesent
decl_stmt|,
name|nbytercv
decl_stmt|,
name|bytetot
decl_stmt|;
comment|/* in bytes */
name|long
name|lastndays
decl_stmt|;
comment|/* in days */
name|long
name|braw
decl_stmt|,
name|brawtot
decl_stmt|;
comment|/* raw bytes*/
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
name|fopen
argument_list|()
decl_stmt|,
modifier|*
name|fdopen
argument_list|()
decl_stmt|,
modifier|*
name|popen
argument_list|()
decl_stmt|,
modifier|*
name|mailopen
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

begin_function_decl
name|long
name|atol
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* constant variables */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|sys_errlist
index|[]
decl_stmt|;
end_decl_stmt

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

begin_decl_stmt
name|char
name|local
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* variables which are modified */
end_comment

begin_extern
extern|extern errno;
end_extern

begin_decl_stmt
name|int
name|debugflg
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
name|remote
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* must be global, remote is not initialized*/
end_comment

begin_comment
comment|/* various structure types */
end_comment

begin_comment
comment|/* used to pass around info about user */
end_comment

begin_struct
struct|struct
name|userinfo
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
name|jobno
index|[
literal|10
index|]
decl_stmt|;
comment|/* CC crn, length = 0 if null and not */
comment|/*      CC machine (else MAGICCRN ) */
name|char
name|dir
index|[
name|FNS
index|]
decl_stmt|;
comment|/* login directory */
name|char
name|loginshell
index|[
name|FNS
index|]
decl_stmt|;
comment|/* login shell */
name|char
name|localname
index|[
name|NS
index|]
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
block|}
struct|;
end_struct

begin_comment
comment|/* unique message - id sent with requests */
end_comment

begin_struct
struct|struct
name|messageid
block|{
name|char
name|msg_mch
decl_stmt|;
comment|/* machine it is on */
name|int
name|msg_pid
decl_stmt|;
comment|/* process id */
name|long
name|msg_ltime
decl_stmt|;
comment|/* current time */
block|}
struct|;
end_struct

begin_comment
comment|/* header which describes information transferred across the link */
end_comment

begin_struct
struct|struct
name|header
block|{
name|char
name|hd_mchto
decl_stmt|;
comment|/* 1-letter code for dest. machine */
name|char
name|hd_mchfrom
decl_stmt|;
comment|/* 1-letter code for source machine */
name|char
name|hd_snto
index|[
name|NS
index|]
decl_stmt|;
comment|/* login name on mchto mach */
name|char
name|hd_snfrom
index|[
name|NS
index|]
decl_stmt|;
comment|/* login name on mchfrom mach */
name|char
name|hd_spasswd
index|[
literal|20
index|]
decl_stmt|;
comment|/* password for snto */
name|char
name|hd_code
decl_stmt|;
comment|/* request code in protocol */
name|char
name|hd_fnonotify
decl_stmt|;
comment|/* if true, don't send anything back */
name|char
name|hd_fquiet
decl_stmt|;
comment|/* if true, only send back if error */
name|char
name|hd_vmajor
decl_stmt|;
comment|/* major version number */
name|char
name|hd_vminor
decl_stmt|;
comment|/* minor version number */
name|char
name|hd_sttyname
index|[
literal|20
index|]
decl_stmt|;
comment|/* tty user is on,e.g. /dev/tty0 */
name|char
name|hd_scmdact
index|[
name|BUFSIZ
index|]
decl_stmt|;
comment|/* the actual cmd the net will exec */
name|char
name|hd_scmdvirt
index|[
name|BUFSIZ
index|]
decl_stmt|;
comment|/* the cmd the user thinks he is exec */
name|long
name|hd_lttytime
decl_stmt|;
comment|/* the time for tty login in utmp */
name|long
name|hd_ltimesent
decl_stmt|;
comment|/* the time the request was sent */
name|char
name|hd_srespfile
index|[
name|FNS
index|]
decl_stmt|;
comment|/* response file name, if sepecified */
name|char
name|hd_sinfile
index|[
name|FNS
index|]
decl_stmt|;
comment|/* remote input file, if sepecified */
name|char
name|hd_soutfile
index|[
name|FNS
index|]
decl_stmt|;
comment|/* remote output file, if sepecified */
comment|/* sent but not computed (always MAGICCRN or 0 length) across the net */
name|char
name|hd_ijobno
index|[
literal|10
index|]
decl_stmt|;
comment|/* CC job number, if applicable */
comment|/* computed, not transferred across the net */
name|char
name|hd_addrto
index|[
name|FNS
index|]
decl_stmt|;
comment|/* address of dest. acct */
name|char
name|hd_addrfrom
index|[
name|FNS
index|]
decl_stmt|;
comment|/* address of source acct */
comment|/* not now being sent over, will be someday, don't use now */
name|char
name|hd_sencpasswd
index|[
literal|20
index|]
decl_stmt|;
comment|/* encrypted passwd with nbs 2way enc */
name|int
name|hd_ifilemode
decl_stmt|;
comment|/* file mode for netcp */
name|char
name|hd_sfndefault
index|[
name|FNS
index|]
decl_stmt|;
comment|/* default filename ext, for netcp */
name|int
name|hd_uidfrom
decl_stmt|;
comment|/* userid on the from machine */
name|int
name|hd_gidfrom
decl_stmt|;
comment|/* groupid on the from machine */
name|struct
name|messageid
name|hd_mesgid
decl_stmt|;
comment|/* message id unique to this request */
name|char
name|hd_fcompressed
decl_stmt|;
comment|/* if true, data is compressed */
name|char
name|hd_facctpair
decl_stmt|;
comment|/* if true, is an accnt pair w/o pwds */
name|char
name|hd_addrreplyto
index|[
name|FNS
index|]
decl_stmt|;
comment|/* reply to this address */
block|}
struct|;
end_struct

begin_comment
comment|/*  	this structure defines the various parameters the daemon and testing    	programs use -- most of the info comes from netrc.c 	NOTE-- this structure is initialized in netrc.c 	don't add members without changing that structure */
end_comment

begin_struct
struct|struct
name|daemonparms
block|{
name|int
name|dp_inspeed
decl_stmt|;
comment|/* for stty, 7=300, 9=1200, 13=9600 baud */
name|int
name|dp_outspeed
decl_stmt|;
comment|/* for stty, 7=300, 9=1200, 13=9600 baud */
name|int
name|dp_maxbread
decl_stmt|;
comment|/* number of read time outs allowed */
name|int
name|dp_atime
decl_stmt|;
comment|/* time to set alarm for timeout */
name|int
name|dp_oatime
decl_stmt|;
comment|/* default time alarm for timeout */
name|char
name|dp_device
index|[
literal|20
index|]
decl_stmt|;
comment|/* name of the network file, e.g. /dev/net-A*/
name|int
name|dp_datasize
decl_stmt|;
comment|/* length of data part of packet */
name|int
name|dp_trynetl
decl_stmt|;
comment|/* try to use netl, -l disables */
name|int
name|dp_onlyuid
decl_stmt|;
comment|/* if non-zero, only send this uid's things */
name|int
name|dp_linefd
decl_stmt|;
comment|/* daemon should read and write from this */
name|char
name|dp_usehispeed
decl_stmt|;
comment|/* if true, use high-speed link */
name|char
name|dp_hispeedlink
index|[
literal|20
index|]
decl_stmt|;
comment|/* device name of high speed link */
name|short
name|dp_sndorcv
decl_stmt|;
comment|/* if<0, only send, if> 0, only recieve */
name|int
name|dp_linedis
decl_stmt|;
comment|/* line disc we use, normal is 0 */
name|int
name|dp_pipesim
decl_stmt|;
comment|/* simulate with pipes */
name|FILE
modifier|*
name|dp_rdfile
decl_stmt|;
comment|/* if pipesim then should read from this */
name|int
name|dp_pwritefd
decl_stmt|;
comment|/* if pipesim then should write from this */
name|int
name|dp_use8bit
decl_stmt|;
comment|/* use 8 bit protocol */
name|short
name|dp_timeout
decl_stmt|;
comment|/* timeout deamon (dialup) if> 0 */
block|}
struct|;
end_struct

begin_comment
comment|/* macro implementation of harg due to bugs in Onyx C compiler */
end_comment

begin_define
define|#
directive|define
name|harg
parameter_list|(
name|str
parameter_list|)
value|{\ 	if (argv[0][2]) \ 		strcpy(str, argv[0]+2); \ 	else \ 		{ strcpy(str, argv[1]); argc--; argv++; } \ 	}
end_define

end_unit

