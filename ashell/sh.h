begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Shell header file  */
end_comment

begin_define
define|#
directive|define
name|E
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
name|QUOTE
value|0200
end_define

begin_define
define|#
directive|define
name|FAND
value|1
end_define

begin_define
define|#
directive|define
name|FCAT
value|2
end_define

begin_define
define|#
directive|define
name|FPIN
value|4
end_define

begin_define
define|#
directive|define
name|FPOU
value|8
end_define

begin_define
define|#
directive|define
name|FPAR
value|16
end_define

begin_define
define|#
directive|define
name|FINT
value|32
end_define

begin_define
define|#
directive|define
name|FPRS
value|64
end_define

begin_define
define|#
directive|define
name|FDIAG
value|128
end_define

begin_define
define|#
directive|define
name|TCOM
value|1
end_define

begin_define
define|#
directive|define
name|TPAR
value|2
end_define

begin_define
define|#
directive|define
name|TFIL
value|3
end_define

begin_define
define|#
directive|define
name|TLST
value|4
end_define

begin_define
define|#
directive|define
name|DTYP
value|0
end_define

begin_define
define|#
directive|define
name|DLEF
value|1
end_define

begin_define
define|#
directive|define
name|DRIT
value|2
end_define

begin_define
define|#
directive|define
name|DFLG
value|3
end_define

begin_define
define|#
directive|define
name|DSPR
value|4
end_define

begin_define
define|#
directive|define
name|DCOM
value|5
end_define

begin_define
define|#
directive|define
name|ENOENT
value|2
end_define

begin_define
define|#
directive|define
name|ENOEXEC
value|8
end_define

begin_define
define|#
directive|define
name|ENOMEM
value|12
end_define

begin_define
define|#
directive|define
name|EACCES
value|13
end_define

begin_define
define|#
directive|define
name|ENOTDIR
value|20
end_define

begin_struct
struct|struct
name|shvar
block|{
name|char
modifier|*
name|value
decl_stmt|;
name|char
modifier|*
name|name
decl_stmt|;
name|struct
name|shvar
modifier|*
name|next
decl_stmt|;
block|}
name|shvhed
struct|,
name|paraml
struct|,
name|aliases
struct|,
name|interps
struct|;
end_struct

begin_struct
struct|struct
name|shvar2
block|{
name|char
modifier|*
name|value
decl_stmt|;
name|struct
name|shvar
modifier|*
name|prev
decl_stmt|;
name|struct
name|shvar
modifier|*
name|next
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
name|char
name|verbose
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
name|nofile
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|error
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|uid
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
name|loginsh
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
name|doneinp
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
name|setintr
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|arginp
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
name|onelflg
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
name|scratch
index|[
literal|100
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
name|prompt
index|[]
decl_stmt|,
name|shell
index|[]
decl_stmt|,
name|pid
index|[]
decl_stmt|,
name|pcs
index|[]
decl_stmt|,
name|home
index|[]
decl_stmt|,
name|path
index|[]
decl_stmt|,
name|n_args
index|[]
decl_stmt|,
name|tim
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|value
argument_list|()
decl_stmt|,
modifier|*
name|value1
argument_list|()
decl_stmt|;
end_decl_stmt

begin_function_decl
name|char
modifier|*
modifier|*
name|glob
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
name|struct
name|shvar
modifier|*
name|adrof
argument_list|()
decl_stmt|,
modifier|*
name|adrof1
argument_list|()
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|seterr
parameter_list|(
name|s
parameter_list|)
value|if (error == 0) error = s;
end_define

begin_decl_stmt
name|int
name|errno
decl_stmt|;
end_decl_stmt

begin_struct
struct|struct
name|htmp
block|{
name|int
name|uid
decl_stmt|;
name|char
name|home
index|[
literal|28
index|]
decl_stmt|;
name|int
name|ttytype
decl_stmt|;
block|}
name|hentry
struct|;
end_struct

end_unit

