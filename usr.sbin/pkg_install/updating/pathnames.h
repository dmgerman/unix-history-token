begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * ----------------------------------------------------------------------------  * "THE BEER-WARE LICENSE" (Revision 42):  *<beat@chruetertee.ch> wrote this file. As long as you retain this notice you  * can do whatever you want with this stuff. If we meet some day, and you think  * this stuff is worth it, you can buy me a beer in return.          Beat Gätzi  * ----------------------------------------------------------------------------  *  * $FreeBSD$  *  */
end_comment

begin_comment
comment|/* Copy from ../version/version.h */
end_comment

begin_comment
comment|/* Where the ports lives by default */
end_comment

begin_define
define|#
directive|define
name|DEF_PORTS_DIR
value|"/usr/ports/UPDATING"
end_define

begin_comment
comment|/* just in case we change the environment variable name */
end_comment

begin_define
define|#
directive|define
name|PORTSDIR
value|"PORTSDIR"
end_define

begin_comment
comment|/* macro to get name of directory where we put logging information */
end_comment

begin_define
define|#
directive|define
name|UPDATING
value|(getenv(PORTSDIR) ? strcat(getenv(PORTSDIR), \ 	"/UPDATING") : DEF_PORTS_DIR)
end_define

begin_comment
comment|/* Where we put logging information by default, else ${PKG_DBDIR} if set */
end_comment

begin_define
define|#
directive|define
name|DEF_LOG_DIR
value|"/var/db/pkg"
end_define

begin_comment
comment|/* just in case we change the environment variable name */
end_comment

begin_define
define|#
directive|define
name|PKG_DBDIR
value|"PKG_DBDIR"
end_define

begin_comment
comment|/* macro to get name of directory where we put logging information */
end_comment

begin_define
define|#
directive|define
name|LOG_DIR
value|(getenv(PKG_DBDIR) ? getenv(PKG_DBDIR) : DEF_LOG_DIR)
end_define

end_unit

