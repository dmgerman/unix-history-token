begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* bsd43-rt.h - site configuration file for RT PC running 4.3BSD UNIX */
end_comment

begin_comment
comment|/*   * $Header: /f/osi/config/RCS/bsd43-rt.h,v 7.2 91/02/22 09:16:26 mrose Interim $  *  * Contributed by Jacob Rekhter, T.J. Watson Research Center, IBM Corp.  *  *  * $Log:	bsd43-rt.h,v $  * Revision 7.2  91/02/22  09:16:26  mrose  * Interim 6.8  *   * Revision 7.1  90/01/27  10:25:59  mrose  * touch-up  *   * Revision 7.0  89/11/23  21:25:57  mrose  * Release 6.0  *   */
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
name|RT
end_define

begin_comment
comment|/* RT/PC */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__STDC__
argument_list|)
operator|&&
name|defined
argument_list|(
name|__HIGHC__
argument_list|)
end_if

begin_comment
comment|/* hc thinks it's ANSI C, but it isn't! */
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

end_unit

