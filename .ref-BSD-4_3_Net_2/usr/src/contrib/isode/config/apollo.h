begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* apollo.h - site configuration file for Apollo */
end_comment

begin_comment
comment|/*  * $Header: /f/osi/config/RCS/apollo.h,v 7.1 91/02/22 09:16:19 mrose Interim $  *  * Contributed by John Brezak, Apollo Computer, Inc.  *  *  * $Log:	apollo.h,v $  * Revision 7.1  91/02/22  09:16:19  mrose  * Interim 6.8  *   * Revision 7.0  89/11/23  21:25:37  mrose  * Release 6.0  *   */
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

begin_ifdef
ifdef|#
directive|ifdef
name|notdef
end_ifdef

begin_comment
comment|/* Don Preuss at Apollo says no longer needed*/
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__STDC__
end_ifdef

begin_comment
comment|/* thinks it's ANSI C, but it isn't! */
end_comment

begin_undef
undef|#
directive|undef
name|__STDC__
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

end_unit

