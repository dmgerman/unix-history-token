begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* osi.h - site configuration file for osi (SunOS) */
end_comment

begin_comment
comment|/*   * $Header: /f/osi/config/RCS/osi.h,v 7.2 91/02/22 09:16:43 mrose Interim $  *  *  * $Log:	osi.h,v $  * Revision 7.2  91/02/22  09:16:43  mrose  * Interim 6.8  *   * Revision 7.1  90/10/15  18:17:59  mrose  * zap-AET  *   * Revision 7.0  89/11/23  21:26:11  mrose  * Release 6.0  *   */
end_comment

begin_comment
comment|/*  *				  NOTICE  *  *    Acquisition, use, and distribution of this module and related  *    materials are subject to the restrictions of a license agreement.  *    Consult the Preface in the User's Manual for the full terms of  *    this agreement.  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_CONFIG_
end_ifndef

begin_define
define|#
directive|define
name|_CONFIG_
end_define

begin_define
define|#
directive|define
name|BSD42
end_define

begin_comment
comment|/* Berkeley UNIX */
end_comment

begin_define
define|#
directive|define
name|WRITEV
end_define

begin_comment
comment|/*   real Berkeley UNIX */
end_comment

begin_define
define|#
directive|define
name|VSPRINTF
end_define

begin_comment
comment|/* libc has vsprintf */
end_comment

begin_define
define|#
directive|define
name|TCP
end_define

begin_comment
comment|/* has TCP/IP (of course) */
end_comment

begin_define
define|#
directive|define
name|SOCKETS
end_define

begin_comment
comment|/*   provided by sockets */
end_comment

begin_define
define|#
directive|define
name|X25
end_define

begin_comment
comment|/* support for X.25 */
end_comment

begin_define
define|#
directive|define
name|SUN_X25
end_define

begin_comment
comment|/* using SunLink X.25 V5.2 */
end_comment

begin_define
define|#
directive|define
name|NFS
end_define

begin_comment
comment|/* network filesystem -- has getdirentries() */
end_comment

begin_define
define|#
directive|define
name|ANON
value|"anon"
end_define

begin_comment
comment|/* guest login for ftam */
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

