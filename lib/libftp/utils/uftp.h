begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_include
include|#
directive|include
file|<FtpLibrary.h>
end_include

begin_include
include|#
directive|include
file|<strings.h>
end_include

begin_include
include|#
directive|include
file|<setjmp.h>
end_include

begin_include
include|#
directive|include
file|<signal.h>
end_include

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<sys/wait.h>
end_include

begin_include
include|#
directive|include
file|<sys/file.h>
end_include

begin_include
include|#
directive|include
file|<arpa/telnet.h>
end_include

begin_include
include|#
directive|include
file|<pwd.h>
end_include

begin_include
include|#
directive|include
file|<errno.h>
end_include

begin_include
include|#
directive|include
file|<glob.h>
end_include

begin_define
define|#
directive|define
name|SYSTEMRC
value|"/usr/share/etc/uftprc"
end_define

begin_define
define|#
directive|define
name|LINK
value|ftp[frame]
end_define

begin_define
define|#
directive|define
name|NFRAMES
value|10
end_define

begin_define
define|#
directive|define
name|TIME
parameter_list|(
name|proc
parameter_list|)
value|settimer(), status = proc , showtimer(), status
end_define

begin_define
define|#
directive|define
name|ARGS
value|char *w1,char *w2,char *w3,char *w4,char *w5,char *w6
end_define

begin_define
define|#
directive|define
name|log
parameter_list|(
name|x
parameter_list|)
value|FtpLog("uftp",x)
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|String
name|host
decl_stmt|;
name|String
name|user
decl_stmt|;
name|String
name|pass
decl_stmt|;
name|String
name|pwd
decl_stmt|;
name|int
name|lock
decl_stmt|;
block|}
name|LINKINFO
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|char
modifier|*
name|cmd
decl_stmt|;
name|int
function_decl|(
modifier|*
name|func
function_decl|)
parameter_list|()
function_decl|;
name|int
name|need
decl_stmt|;
name|char
modifier|*
name|help
decl_stmt|;
block|}
name|CMDS
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_alias
block|{
name|String
name|name
decl_stmt|,
name|str
decl_stmt|;
name|struct
name|_alias
modifier|*
name|next
decl_stmt|;
block|}
name|ALIAS
typedef|;
end_typedef

begin_decl_stmt
specifier|extern
name|ALIAS
modifier|*
name|firstalias
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|FTP
modifier|*
name|ftp
index|[
name|NFRAMES
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|LINKINFO
name|iftp
index|[
name|NFRAMES
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|frame
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|lastcmd
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|glassmode
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|trymode
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|hashmode
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|restmode
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|sleeptime
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|time_t
name|noopinterval
decl_stmt|,
name|nooptimeout
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|CMDS
name|cmds
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|status
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|String
name|prompt
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|String
name|defaultuser
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|jmp_buf
name|start
decl_stmt|;
end_decl_stmt

begin_function_decl
name|char
modifier|*
name|word
parameter_list|(
name|char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|readline
parameter_list|(
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|getpass
parameter_list|(
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|getrcname
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|getaliasrcname
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|makestr
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|expandalias
parameter_list|(
name|char
modifier|*
name|str
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|getprompt
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|makefilename
parameter_list|(
name|char
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|intr
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|noop
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|myhash
parameter_list|(
name|FTP
modifier|*
parameter_list|,
name|unsigned
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|STATUS
name|my_error
parameter_list|(
name|FTP
modifier|*
parameter_list|,
name|int
parameter_list|,
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

end_unit

