begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* bsd44.h - site configuration file for 4.4BSD UNIX */
end_comment

begin_comment
comment|/*   * $Header: /f/osi/config/RCS/bsd44.h,v 7.3 91/02/22 09:16:30 mrose Interim $  *  *  * $Log:	bsd44.h,v $  * Revision 7.3  91/02/22  09:16:30  mrose  * Interim 6.8  *   * Revision 7.2  91/01/10  16:13:03  mrose  * x25  *   * Revision 7.1  90/07/09  14:32:41  mrose  * sync  *   * Revision 7.0  89/11/23  21:26:00  mrose  * Release 6.0  *   */
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
name|BSD43
end_define

begin_comment
comment|/*   4.3BSD or later */
end_comment

begin_define
define|#
directive|define
name|BSD44
end_define

begin_comment
comment|/*   4.4BSD to be precise! */
end_comment

begin_define
define|#
directive|define
name|X25
end_define

begin_define
define|#
directive|define
name|UBC_X25
end_define

begin_define
define|#
directive|define
name|UBC_X25_WRITEV
end_define

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
name|TP4
end_define

begin_comment
comment|/* has TP4 */
end_comment

begin_define
define|#
directive|define
name|BSD_TP4
end_define

begin_comment
comment|/*   provided by UCB/UWisc */
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
comment|/* network file system -- has getdirentries */
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

