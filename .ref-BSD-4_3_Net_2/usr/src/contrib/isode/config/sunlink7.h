begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* sunlink7.h - site configuration file for SunLink OSI and X.25 7.0 on 	SunOS 4 */
end_comment

begin_comment
comment|/*   * $Header: /f/osi/config/RCS/sunlink7.h,v 7.1 91/02/22 09:16:57 mrose Interim $  *  *  * $Log:	sunlink7.h,v $  * Revision 7.1  91/02/22  09:16:57  mrose  * Interim 6.8  *   * Revision 7.0  90/11/20  15:39:48  mrose  * *** empty log message ***  *   */
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
comment|/*   real Berkeley UNIX */
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
name|X25
end_define

begin_comment
comment|/* has X.25 */
end_comment

begin_define
define|#
directive|define
name|SUN_X25
end_define

begin_comment
comment|/*   provided by SunLink X.25 */
end_comment

begin_define
define|#
directive|define
name|TP4
end_define

begin_comment
comment|/* has TP4 */
end_comment

begin_define
define|#
directive|define
name|SUN_TP4
end_define

begin_comment
comment|/*   provided by SunLink OSI */
end_comment

begin_define
define|#
directive|define
name|SUNLINK_5_2
end_define

begin_comment
comment|/*     define if using SunLink OSI release 5.2 				       or greater */
end_comment

begin_define
define|#
directive|define
name|SUNLINK_6_0
end_define

begin_comment
comment|/*     define if using SunLink OSI release 6.0 				       or greater */
end_comment

begin_define
define|#
directive|define
name|SUNLINK_7_0
end_define

begin_comment
comment|/*     define if using SunLink OSI release 7.0 				       or greater */
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
comment|/* network filesystem -- has getdirentries() */
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

