begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* char id_f_errno[] = "@(#)f_errno.h	1.5";  *  * f77 I/O error definitions  */
end_comment

begin_include
include|#
directive|include
file|<errno.h>
end_include

begin_decl_stmt
specifier|extern
name|int
name|errno
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|f_nerr
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|F_ER
value|100
end_define

begin_comment
comment|/* base offset of f77 error numbers */
end_comment

begin_define
define|#
directive|define
name|F_ERFMT
value|100
end_define

begin_comment
comment|/* error in format */
end_comment

begin_define
define|#
directive|define
name|F_ERUNIT
value|101
end_define

begin_comment
comment|/* illegal unit number */
end_comment

begin_define
define|#
directive|define
name|F_ERNOFIO
value|102
end_define

begin_comment
comment|/* formatted io not allowed */
end_comment

begin_define
define|#
directive|define
name|F_ERNOUIO
value|103
end_define

begin_comment
comment|/* unformatted io not allowed */
end_comment

begin_define
define|#
directive|define
name|F_ERNODIO
value|104
end_define

begin_comment
comment|/* direct io not allowed */
end_comment

begin_define
define|#
directive|define
name|F_ERNOSIO
value|105
end_define

begin_comment
comment|/* sequential io not allowed */
end_comment

begin_define
define|#
directive|define
name|F_ERNOBKSP
value|106
end_define

begin_comment
comment|/* can't backspace file */
end_comment

begin_define
define|#
directive|define
name|F_ERBREC
value|107
end_define

begin_comment
comment|/* off beginning of record */
end_comment

begin_define
define|#
directive|define
name|F_ERSTAT
value|108
end_define

begin_comment
comment|/* can't stat file */
end_comment

begin_define
define|#
directive|define
name|F_ERREPT
value|109
end_define

begin_comment
comment|/* no * after repeat count */
end_comment

begin_define
define|#
directive|define
name|F_EREREC
value|110
end_define

begin_comment
comment|/* off end of record */
end_comment

begin_define
define|#
directive|define
name|F_ERTRUNC
value|111
end_define

begin_comment
comment|/* truncation failed */
end_comment

begin_define
define|#
directive|define
name|F_ERLIO
value|112
end_define

begin_comment
comment|/* incomprehensible list input */
end_comment

begin_define
define|#
directive|define
name|F_ERSPACE
value|113
end_define

begin_comment
comment|/* out of free space */
end_comment

begin_define
define|#
directive|define
name|F_ERNOPEN
value|114
end_define

begin_comment
comment|/* unit not connected */
end_comment

begin_define
define|#
directive|define
name|F_ERRDCHR
value|115
end_define

begin_comment
comment|/* read unexpected character */
end_comment

begin_define
define|#
directive|define
name|F_ERLOGIF
value|116
end_define

begin_comment
comment|/* blank logical input field */
end_comment

begin_define
define|#
directive|define
name|F_ERNEWF
value|117
end_define

begin_comment
comment|/* 'new' file exists */
end_comment

begin_define
define|#
directive|define
name|F_EROLDF
value|118
end_define

begin_comment
comment|/* can't find 'old' file */
end_comment

begin_define
define|#
directive|define
name|F_ERSYS
value|119
end_define

begin_comment
comment|/* unknown system error */
end_comment

begin_define
define|#
directive|define
name|F_ERSEEK
value|120
end_define

begin_comment
comment|/* requires seek ability */
end_comment

begin_define
define|#
directive|define
name|F_ERARG
value|121
end_define

begin_comment
comment|/* illegal argument */
end_comment

begin_define
define|#
directive|define
name|F_ERNREP
value|122
end_define

begin_comment
comment|/* negative repeat count */
end_comment

begin_define
define|#
directive|define
name|F_ERILLOP
value|123
end_define

begin_comment
comment|/* illegal operation for channel or device */
end_comment

begin_define
define|#
directive|define
name|F_MAXERR
value|(f_nerr + F_ER)
end_define

end_unit

