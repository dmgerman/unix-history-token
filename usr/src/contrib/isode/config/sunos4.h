begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* sunos4.h - site configuration file for SunOS release 4 */
end_comment

begin_comment
comment|/*   * $Header: /f/osi/config/RCS/sunos4.h,v 7.2 91/02/22 09:17:01 mrose Interim $  *  *  * $Log:	sunos4.h,v $  * Revision 7.2  91/02/22  09:17:01  mrose  * Interim 6.8  *   * Revision 7.1  90/07/09  14:33:01  mrose  * sync  *   * Revision 7.0  89/11/23  21:26:24  mrose  * Release 6.0  *   */
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
name|SUNOS4
end_define

begin_comment
comment|/*   with Sun's enhancements */
end_comment

begin_define
define|#
directive|define
name|WRITEV
end_define

begin_comment
comment|/*   (sort of) real Berkeley UNIX */
end_comment

begin_define
define|#
directive|define
name|BSD43
end_define

begin_comment
comment|/*   4.3BSD or later */
end_comment

begin_define
define|#
directive|define
name|VSPRINTF
end_define

begin_comment
comment|/* has vprintf(3s) routines */
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
name|GETDENTS
end_define

begin_comment
comment|/* has getdirent(2) call */
end_comment

begin_define
define|#
directive|define
name|NFS
end_define

begin_comment
comment|/* network filesystem -- has getdirentries */
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

