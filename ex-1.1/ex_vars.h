begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Ex - a text editor  * Bill Joy UCB June 1977  */
end_comment

begin_struct
struct|struct
name|varbl
block|{
name|char
modifier|*
name|vname
index|[
literal|2
index|]
decl_stmt|;
name|char
name|vtype
decl_stmt|;
name|int
name|vdefault
decl_stmt|;
name|int
name|vvalue
decl_stmt|;
block|}
name|varbls
index|[]
struct|;
end_struct

begin_define
define|#
directive|define
name|value
parameter_list|(
name|a
parameter_list|)
value|varbls[a].vvalue
end_define

begin_define
define|#
directive|define
name|AUTOINDENT
value|0
end_define

begin_define
define|#
directive|define
name|AUTOPRINT
value|1
end_define

begin_define
define|#
directive|define
name|BEAUTIFY
value|2
end_define

begin_define
define|#
directive|define
name|DIRECTORY
value|3
end_define

begin_define
define|#
directive|define
name|EDITANY
value|4
end_define

begin_define
define|#
directive|define
name|EDITED
value|5
end_define

begin_define
define|#
directive|define
name|ERRBELLS
value|6
end_define

begin_define
define|#
directive|define
name|FORK
value|7
end_define

begin_define
define|#
directive|define
name|HOME
value|8
end_define

begin_define
define|#
directive|define
name|HUSH
value|9
end_define

begin_define
define|#
directive|define
name|IGNORECASE
value|10
end_define

begin_define
define|#
directive|define
name|INDICATEUL
value|11
end_define

begin_define
define|#
directive|define
name|LIST
value|12
end_define

begin_define
define|#
directive|define
name|MAGIC
value|13
end_define

begin_define
define|#
directive|define
name|MODE
value|14
end_define

begin_define
define|#
directive|define
name|NOTIFY
value|15
end_define

begin_define
define|#
directive|define
name|NUMBER
value|16
end_define

begin_define
define|#
directive|define
name|OPEN
value|17
end_define

begin_define
define|#
directive|define
name|OPTIMIZE
value|18
end_define

begin_define
define|#
directive|define
name|PRINTALL
value|19
end_define

begin_define
define|#
directive|define
name|PROMPT
value|20
end_define

begin_define
define|#
directive|define
name|SCROLL
value|21
end_define

begin_define
define|#
directive|define
name|SHELL
value|22
end_define

begin_define
define|#
directive|define
name|SHIFTWIDTH
value|23
end_define

begin_define
define|#
directive|define
name|STICKY
value|24
end_define

begin_define
define|#
directive|define
name|TERMINALTYPE
value|25
end_define

begin_define
define|#
directive|define
name|TERSE
value|26
end_define

begin_define
define|#
directive|define
name|VISUALMESSAGE
value|27
end_define

begin_define
define|#
directive|define
name|WINDOW
value|28
end_define

begin_define
define|#
directive|define
name|WRAP
value|29
end_define

end_unit

