begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* sys52-sun.h - site configuration file for SUN's SVR2 Compatiblity Package */
end_comment

begin_comment
comment|/*   * $Header: /f/osi/config/RCS/sys52-sun.h,v 7.1 91/02/22 09:17:07 mrose Interim $  *  *  * $Log:	sys52-sun.h,v $  * Revision 7.1  91/02/22  09:17:07  mrose  * Interim 6.8  *   * Revision 7.0  89/11/23  21:26:29  mrose  * Release 6.0  *   */
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
name|SYS5
end_define

begin_comment
comment|/* AT&T UNIX emulation */
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
comment|/* has TCP/IP */
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

