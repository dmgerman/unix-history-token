begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* sys52-rt.h - site configuration file for RT PC running AIX */
end_comment

begin_comment
comment|/*  * $Header: /f/osi/config/RCS/sys52-rt.h,v 7.1 91/02/22 09:17:05 mrose Interim $  *  * Contributed by by Jacob Rekhter, T.J. Watson Research Center, IBM Corp.  *  *  * $Log:	sys52-rt.h,v $  * Revision 7.1  91/02/22  09:17:05  mrose  * Interim 6.8  *   * Revision 7.0  89/11/23  21:26:27  mrose  * Release 6.0  *   */
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
comment|/* AT&T UNIX */
end_comment

begin_define
define|#
directive|define
name|AIX
end_define

begin_comment
comment|/*   with IBMs running AIX */
end_comment

begin_define
define|#
directive|define
name|RT
end_define

begin_comment
comment|/*   on the RT/PC */
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

begin_endif
endif|#
directive|endif
end_endif

end_unit

