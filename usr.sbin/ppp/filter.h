begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  *	    Written by Toshiharu OHNO (tony-o@iij.ad.jp)  *  *   Copyright (C) 1993, Internet Initiative Japan, Inc. All rights reserverd.  *  * Redistribution and use in source and binary forms are permitted  * provided that the above copyright notice and this paragraph are  * duplicated in all such forms and that any documentation,  * advertising materials, and other materials related to such  * distribution and use acknowledge that the software was developed  * by the Internet Initiative Japan.  The name of the  * IIJ may not be used to endorse or promote products derived  * from this software without specific prior written permission.  * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED  * WARRANTIES OF MERCHANTIBILITY AND FITNESS FOR A PARTICULAR PURPOSE.  *  * $FreeBSD$  *  *	TODO:  */
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
name|unsigned
name|estab
range|:
literal|1
decl_stmt|;
name|unsigned
name|syn
range|:
literal|1
decl_stmt|;
name|unsigned
name|finrst
range|:
literal|1
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
value|40
end_define

begin_comment
comment|/* in each filter set */
end_comment

begin_struct
struct|struct
name|filter
block|{
name|struct
name|filterent
name|rule
index|[
name|MAXFILTERS
index|]
decl_stmt|;
comment|/* incoming packet filter */
specifier|const
name|char
modifier|*
name|name
decl_stmt|;
name|unsigned
name|fragok
range|:
literal|1
decl_stmt|;
name|unsigned
name|logok
range|:
literal|1
decl_stmt|;
block|}
struct|;
end_struct

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

begin_struct_decl
struct_decl|struct
name|ipcp
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|cmdargs
struct_decl|;
end_struct_decl

begin_function_decl
specifier|extern
name|int
name|ParseAddr
parameter_list|(
name|struct
name|ipcp
modifier|*
parameter_list|,
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
name|filter_Show
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
name|filter_Set
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
specifier|const
name|char
modifier|*
name|filter_Action2Nam
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
specifier|const
name|char
modifier|*
name|filter_Proto2Nam
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
specifier|const
name|char
modifier|*
name|filter_Op2Nam
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

end_unit

