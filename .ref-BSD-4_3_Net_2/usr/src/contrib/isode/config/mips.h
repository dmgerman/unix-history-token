begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* mips.h - site configuration file for RISC/OS */
end_comment

begin_comment
comment|/*   * $Header: /f/osi/config/RCS/mips.h,v 7.2 91/02/22 09:16:40 mrose Interim $  *  *  * $Log:	mips.h,v $  * Revision 7.2  91/02/22  09:16:40  mrose  * Interim 6.8  *   * Revision 7.1  90/03/26  09:57:04  mrose  * MIPS  *   * Revision 7.0  89/11/23  21:26:06  mrose  * Release 6.0  *   */
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
name|MIPS
end_define

begin_comment
comment|/* RISC/OS */
end_comment

begin_define
define|#
directive|define
name|NFS
end_define

begin_comment
comment|/* network file system -- has getdirentries */
end_comment

begin_define
define|#
directive|define
name|BIND
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

