begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $Header$ */
end_comment

begin_comment
comment|/*  * phelp definitions  *  * Author: Peter J. Nicklin  */
end_comment

begin_define
define|#
directive|define
name|PHELP
value|EQUAL(*argv, "phelp")
end_define

begin_define
define|#
directive|define
name|PHELP_CMD_FILE
value|"phelp.cmd"
end_define

begin_comment
comment|/* help commands */
end_comment

begin_define
define|#
directive|define
name|PHELP_HELP_FILE
value|"phelp.help"
end_define

begin_comment
comment|/* brief help introduction */
end_comment

begin_define
define|#
directive|define
name|MAXHELPLEVEL
value|50
end_define

begin_comment
comment|/* max depth of help hierarchy */
end_comment

begin_define
define|#
directive|define
name|REQUESTSIZE
value|128
end_define

begin_comment
comment|/* size of help request buffer */
end_comment

begin_define
define|#
directive|define
name|MAXLINE
value|80
end_define

begin_comment
comment|/* maximum width of index */
end_comment

begin_define
define|#
directive|define
name|MINIMUM_GAP
value|2
end_define

begin_comment
comment|/* minimum gap between index columns */
end_comment

begin_define
define|#
directive|define
name|TABSIZE
value|8
end_define

begin_comment
comment|/* number of columns per tab */
end_comment

end_unit

