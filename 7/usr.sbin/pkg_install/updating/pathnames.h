begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * ----------------------------------------------------------------------------  * "THE BEER-WARE LICENSE" (Revision 42):  *<beat@chruetertee.ch> wrote this file. As long as you retain this notice you  * can do whatever you want with this stuff. If we meet some day, and you think  * this stuff is worth it, you can buy me a beer in return.          Beat Gätzi  * ----------------------------------------------------------------------------  *  * $FreeBSD$  *  */
end_comment

begin_comment
comment|/* Where the updating file lives by default */
end_comment

begin_define
define|#
directive|define
name|DEF_UPDATING
value|"/usr/ports/UPDATING"
end_define

begin_comment
comment|/* macro to define location of the UPDATING file */
end_comment

begin_define
define|#
directive|define
name|UPDATING
value|(getenv(PORTSDIR) ? strcat(getenv(PORTSDIR), \         "/UPDATING") : DEF_UPDATING)
end_define

end_unit

