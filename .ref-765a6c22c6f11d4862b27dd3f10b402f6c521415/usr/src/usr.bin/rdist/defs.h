begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	defs.h	4.1	83/09/07	*/
end_comment

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<ctype.h>
end_include

begin_include
include|#
directive|include
file|<errno.h>
end_include

begin_include
include|#
directive|include
file|<pwd.h>
end_include

begin_include
include|#
directive|include
file|<grp.h>
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
file|<sys/dir.h>
end_include

begin_include
include|#
directive|include
file|<sys/stat.h>
end_include

begin_include
include|#
directive|include
file|<sys/time.h>
end_include

begin_include
include|#
directive|include
file|<netinet/in.h>
end_include

begin_define
define|#
directive|define
name|MAILCMD
value|"/usr/lib/sendmail -i -t"
end_define

begin_comment
comment|/* defines for yacc */
end_comment

begin_define
define|#
directive|define
name|EQUAL
value|1
end_define

begin_define
define|#
directive|define
name|ARROW
value|2
end_define

begin_define
define|#
directive|define
name|LP
value|3
end_define

begin_define
define|#
directive|define
name|RP
value|4
end_define

begin_define
define|#
directive|define
name|NAME
value|5
end_define

begin_define
define|#
directive|define
name|INSTALL
value|6
end_define

begin_define
define|#
directive|define
name|VERIFY
value|7
end_define

begin_define
define|#
directive|define
name|NOTIFY
value|8
end_define

begin_define
define|#
directive|define
name|EXCEPT
value|9
end_define

begin_comment
comment|/* table sizes */
end_comment

begin_define
define|#
directive|define
name|HASHSIZE
value|1021
end_define

begin_define
define|#
directive|define
name|INMAX
value|3500
end_define

begin_define
define|#
directive|define
name|ALLOC
parameter_list|(
name|x
parameter_list|)
value|(struct x *) malloc(sizeof(struct x))
end_define

begin_struct
struct|struct
name|block
block|{
name|int
name|b_type
decl_stmt|;
name|char
modifier|*
name|b_name
decl_stmt|;
name|struct
name|block
modifier|*
name|b_next
decl_stmt|;
name|struct
name|block
modifier|*
name|b_args
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|int
name|debug
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* debugging flag */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|nflag
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* NOP flag, don't execute commands */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|qflag
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Quiet. don't print messages */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|vflag
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* verify only */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|yflag
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* update iff remote younger than master */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|errs
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* number of errors seen */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|rem
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* remote file descriptor */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|iamremote
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* acting as remote server */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|filec
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* number of files to update */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
modifier|*
name|filev
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* list of files/directories to update */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|tmpfile
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* file name for logging changes */
end_comment

begin_decl_stmt
specifier|extern
name|char
name|host
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* host name of master copy */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|rhost
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* host name of remote being updated */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|block
modifier|*
name|except
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* list of files to exclude */
end_comment

begin_decl_stmt
specifier|extern
name|char
name|buf
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* general purpose buffer */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|errno
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* system error number */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|sys_errlist
index|[]
decl_stmt|;
end_decl_stmt

begin_function_decl
name|struct
name|block
modifier|*
name|lookup
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|block
modifier|*
name|expand
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|rindex
parameter_list|()
function_decl|;
end_function_decl

end_unit

