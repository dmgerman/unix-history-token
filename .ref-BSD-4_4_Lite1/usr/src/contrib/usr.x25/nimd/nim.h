begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_define
define|#
directive|define
name|LOGFILE
value|"/usr/spool/log/nimd_log"
end_define

begin_define
define|#
directive|define
name|HELPFILE
value|"/usr/local/lib/nim/help"
end_define

begin_define
define|#
directive|define
name|NUIFILE
value|"/usr/local/lib/nim/nui"
end_define

begin_define
define|#
directive|define
name|MAXPSIZ
value|(256+1)
end_define

begin_comment
comment|/* maximum packet size + 1 */
end_comment

begin_define
define|#
directive|define
name|DEFAULT_PROFILE
value|0
end_define

begin_comment
comment|/* default profile */
end_comment

begin_define
define|#
directive|define
name|INVALID
value|-1
end_define

begin_comment
comment|/* illegal parameter */
end_comment

begin_define
define|#
directive|define
name|NPROFILES
value|6
end_define

begin_comment
comment|/* number of standard profiles */
end_comment

begin_define
define|#
directive|define
name|C_FORWARD
value|01
end_define

begin_define
define|#
directive|define
name|C_ERASE
value|02
end_define

begin_define
define|#
directive|define
name|C_KILL
value|04
end_define

begin_define
define|#
directive|define
name|C_DISPLAY
value|010
end_define

begin_define
define|#
directive|define
name|C_ESCAPE
value|020
end_define

begin_define
define|#
directive|define
name|C_TYPE
parameter_list|(
name|c
parameter_list|)
value|(chartab[c&0177]& 0176)
end_define

begin_define
define|#
directive|define
name|ISFORWARD
parameter_list|(
name|c
parameter_list|)
value|(chartab[c&0177]& C_FORWARD)
end_define

begin_define
define|#
directive|define
name|ST_COMMAND
value|01
end_define

begin_comment
comment|/* command mode */
end_comment

begin_define
define|#
directive|define
name|ST_DATA
value|02
end_define

begin_comment
comment|/* data mode */
end_comment

begin_define
define|#
directive|define
name|ST_ESCSEEN
value|04
end_define

begin_comment
comment|/* received nim escape character from pty */
end_comment

begin_define
define|#
directive|define
name|ST_ESCCOMM
value|010
end_define

begin_comment
comment|/* escaped to command mode */
end_comment

begin_define
define|#
directive|define
name|ST_UGLY_50_BAUD_BREAK_IN_PROGRESS
value|020
end_define

begin_define
define|#
directive|define
name|FROMPTY
value|0
end_define

begin_define
define|#
directive|define
name|FROMNET
value|1
end_define

begin_define
define|#
directive|define
name|FROMNIM
value|2
end_define

begin_define
define|#
directive|define
name|MAXQSIZ
value|256
end_define

begin_comment
comment|/* maximum number size of any queue */
end_comment

begin_decl_stmt
name|short
name|CurrentX29Parms
index|[
literal|128
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* current x.29 parameter values */
end_comment

begin_decl_stmt
name|short
name|CurrentProfile
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* current profile number (1 - 6) */
end_comment

begin_decl_stmt
name|short
name|pnums
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* list of valid parameter numbers */
end_comment

begin_decl_stmt
name|short
name|State
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* NIM state (command or data) */
end_comment

begin_decl_stmt
name|short
name|OutputBlocked
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* remote host sent ^S */
end_comment

begin_decl_stmt
specifier|extern
name|short
name|NetFd
decl_stmt|,
name|PtyFd
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
name|Banner
index|[]
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|CCITT1978
value|0
end_define

begin_define
define|#
directive|define
name|CCITT1980
value|1
end_define

begin_struct
struct|struct
name|netinfo
block|{
name|short
name|n_type
decl_stmt|;
comment|/* CCITT1978 or CCITT1980 */
name|short
name|n_nparms
decl_stmt|;
comment|/* number of parameters */
name|short
name|n_psize
decl_stmt|;
comment|/* current packet size */
block|}
name|NetInfo
struct|;
end_struct

begin_decl_stmt
name|char
modifier|*
name|rindex
argument_list|()
decl_stmt|,
modifier|*
name|strcat
argument_list|()
decl_stmt|,
modifier|*
name|strcpy
argument_list|()
decl_stmt|,
modifier|*
name|strncpy
argument_list|()
decl_stmt|,
modifier|*
name|rindex
argument_list|()
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|sprint
value|sprintf
end_define

begin_define
define|#
directive|define
name|printf
value|printf
end_define

end_unit

