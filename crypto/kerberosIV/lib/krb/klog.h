begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * $Id: klog.h,v 1.5 1997/05/11 11:05:28 assar Exp $  *  * Copyright 1988 by the Massachusetts Institute of Technology.  *  * For copying and distribution information, please see the file  *<mit-copyright.h>.  *  * This file defines the types of log messages logged by klog.  Each  * type of message may be selectively turned on or off.   */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|KLOG_DEFS
end_ifndef

begin_define
define|#
directive|define
name|KLOG_DEFS
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|KRBLOG
end_ifndef

begin_define
define|#
directive|define
name|KRBLOG
value|"/var/log/kerberos.log"
end_define

begin_comment
comment|/* master server  */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|KRBSLAVELOG
end_ifndef

begin_define
define|#
directive|define
name|KRBSLAVELOG
value|"/var/log/kerberos_slave.log"
end_define

begin_comment
comment|/* slave server  */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|NLOGTYPE
value|100
end_define

begin_comment
comment|/* Maximum number of log msg types  */
end_comment

begin_define
define|#
directive|define
name|L_NET_ERR
value|1
end_define

begin_comment
comment|/* Error in network code	    */
end_comment

begin_define
define|#
directive|define
name|L_NET_INFO
value|2
end_define

begin_comment
comment|/* Info on network activity	    */
end_comment

begin_define
define|#
directive|define
name|L_KRB_PERR
value|3
end_define

begin_comment
comment|/* Kerberos protocol errors	    */
end_comment

begin_define
define|#
directive|define
name|L_KRB_PINFO
value|4
end_define

begin_comment
comment|/* Kerberos protocol info	    */
end_comment

begin_define
define|#
directive|define
name|L_INI_REQ
value|5
end_define

begin_comment
comment|/* Request for initial ticket	    */
end_comment

begin_define
define|#
directive|define
name|L_NTGT_INTK
value|6
end_define

begin_comment
comment|/* Initial request not for TGT	    */
end_comment

begin_define
define|#
directive|define
name|L_DEATH_REQ
value|7
end_define

begin_comment
comment|/* Request for server death	    */
end_comment

begin_define
define|#
directive|define
name|L_TKT_REQ
value|8
end_define

begin_comment
comment|/* All ticket requests using a tgt  */
end_comment

begin_define
define|#
directive|define
name|L_ERR_SEXP
value|9
end_define

begin_comment
comment|/* Service expired		    */
end_comment

begin_define
define|#
directive|define
name|L_ERR_MKV
value|10
end_define

begin_comment
comment|/* Master key version incorrect     */
end_comment

begin_define
define|#
directive|define
name|L_ERR_NKY
value|11
end_define

begin_comment
comment|/* User's key is null		    */
end_comment

begin_define
define|#
directive|define
name|L_ERR_NUN
value|12
end_define

begin_comment
comment|/* Principal not unique		    */
end_comment

begin_define
define|#
directive|define
name|L_ERR_UNK
value|13
end_define

begin_comment
comment|/* Principal Unknown		    */
end_comment

begin_define
define|#
directive|define
name|L_ALL_REQ
value|14
end_define

begin_comment
comment|/* All requests			    */
end_comment

begin_define
define|#
directive|define
name|L_APPL_REQ
value|15
end_define

begin_comment
comment|/* Application requests (using tgt) */
end_comment

begin_define
define|#
directive|define
name|L_KRB_PWARN
value|16
end_define

begin_comment
comment|/* Protocol warning messages	    */
end_comment

begin_decl_stmt
name|char
modifier|*
name|klog
name|__P
argument_list|(
operator|(
name|int
name|type
operator|,
specifier|const
name|char
operator|*
name|format
operator|,
operator|...
operator|)
argument_list|)
ifdef|#
directive|ifdef
name|__GNUC__
name|__attribute__
argument_list|(
operator|(
name|format
argument_list|(
name|printf
argument_list|,
literal|2
argument_list|,
literal|3
argument_list|)
operator|)
argument_list|)
endif|#
directive|endif
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* KLOG_DEFS */
end_comment

end_unit

