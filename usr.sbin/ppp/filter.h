begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  *	    Written by Toshiharu OHNO (tony-o@iij.ad.jp)  *  *   Copyright (C) 1993, Internet Initiative Japan, Inc. All rights reserverd.  *  * Redistribution and use in source and binary forms are permitted  * provided that the above copyright notice and this paragraph are  * duplicated in all such forms and that any documentation,  * advertising materials, and other materials related to such  * distribution and use acknowledge that the software was developed  * by the Internet Initiative Japan.  The name of the  * IIJ may not be used to endorse or promote products derived  * from this software without specific prior written permission.  * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED  * WARRANTIES OF MERCHANTIBILITY AND FITNESS FOR A PARTICULAR PURPOSE.  *  * $Id: filter.h,v 1.10 1997/10/26 01:02:35 brian Exp $  *  *	TODO:  */
end_comment

begin_comment
comment|/*  *   Actions  */
end_comment

begin_define
define|#
directive|define
name|A_NONE
value|0
end_define

begin_define
define|#
directive|define
name|A_PERMIT
value|1
end_define

begin_define
define|#
directive|define
name|A_DENY
value|2
end_define

begin_define
define|#
directive|define
name|A_MASK
value|3
end_define

begin_define
define|#
directive|define
name|A_UHOST
value|4
end_define

begin_define
define|#
directive|define
name|A_UPORT
value|8
end_define

begin_comment
comment|/*  *   Known protocols  */
end_comment

begin_define
define|#
directive|define
name|P_NONE
value|0
end_define

begin_define
define|#
directive|define
name|P_TCP
value|1
end_define

begin_define
define|#
directive|define
name|P_UDP
value|2
end_define

begin_define
define|#
directive|define
name|P_ICMP
value|3
end_define

begin_comment
comment|/*  *   Operations  */
end_comment

begin_define
define|#
directive|define
name|OP_NONE
value|0
end_define

begin_define
define|#
directive|define
name|OP_EQ
value|1
end_define

begin_define
define|#
directive|define
name|OP_GT
value|2
end_define

begin_define
define|#
directive|define
name|OP_LT
value|4
end_define

begin_struct
struct|struct
name|filterent
block|{
name|int
name|action
decl_stmt|;
comment|/* Filtering action */
name|int
name|swidth
decl_stmt|;
comment|/* Effective source address width */
name|struct
name|in_addr
name|saddr
decl_stmt|;
comment|/* Source address */
name|struct
name|in_addr
name|smask
decl_stmt|;
comment|/* Source address mask */
name|int
name|dwidth
decl_stmt|;
comment|/* Effective destination address width */
name|struct
name|in_addr
name|daddr
decl_stmt|;
comment|/* Destination address */
name|struct
name|in_addr
name|dmask
decl_stmt|;
comment|/* Destination address mask */
name|int
name|proto
decl_stmt|;
comment|/* Protocol */
struct|struct
block|{
name|short
name|srcop
decl_stmt|;
name|u_short
name|srcport
decl_stmt|;
name|short
name|dstop
decl_stmt|;
name|u_short
name|dstport
decl_stmt|;
name|int
name|estab
decl_stmt|;
block|}
name|opt
struct|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|MAXFILTERS
value|20
end_define

begin_define
define|#
directive|define
name|FL_IN
value|0
end_define

begin_define
define|#
directive|define
name|FL_OUT
value|1
end_define

begin_define
define|#
directive|define
name|FL_DIAL
value|2
end_define

begin_define
define|#
directive|define
name|FL_KEEP
value|3
end_define

begin_decl_stmt
specifier|extern
name|struct
name|filterent
name|ifilters
index|[
name|MAXFILTERS
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* incoming packet filter */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|filterent
name|ofilters
index|[
name|MAXFILTERS
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* outgoing packet filter */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|filterent
name|dfilters
index|[
name|MAXFILTERS
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* dial-out packet filter */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|filterent
name|afilters
index|[
name|MAXFILTERS
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* keep-alive packet filter */
end_comment

begin_function_decl
specifier|extern
name|int
name|ParseAddr
parameter_list|(
name|int
parameter_list|,
name|char
specifier|const
modifier|*
specifier|const
modifier|*
parameter_list|,
name|struct
name|in_addr
modifier|*
parameter_list|,
name|struct
name|in_addr
modifier|*
parameter_list|,
name|int
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|ShowIfilter
parameter_list|(
name|struct
name|cmdargs
specifier|const
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|ShowOfilter
parameter_list|(
name|struct
name|cmdargs
specifier|const
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|ShowDfilter
parameter_list|(
name|struct
name|cmdargs
specifier|const
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|ShowAfilter
parameter_list|(
name|struct
name|cmdargs
specifier|const
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|SetIfilter
parameter_list|(
name|struct
name|cmdargs
specifier|const
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|SetOfilter
parameter_list|(
name|struct
name|cmdargs
specifier|const
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|SetDfilter
parameter_list|(
name|struct
name|cmdargs
specifier|const
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|SetAfilter
parameter_list|(
name|struct
name|cmdargs
specifier|const
modifier|*
parameter_list|)
function_decl|;
end_function_decl

end_unit

