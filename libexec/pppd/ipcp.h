begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * ipcp.h - IP Control Protocol definitions.  *  * Copyright (c) 1989 Carnegie Mellon University.  * All rights reserved.  *  * Redistribution and use in source and binary forms are permitted  * provided that the above copyright notice and this paragraph are  * duplicated in all such forms and that any documentation,  * advertising materials, and other materials related to such  * distribution and use acknowledge that the software was developed  * by Carnegie Mellon University.  The name of the  * University may not be used to endorse or promote products derived  * from this software without specific prior written permission.  * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED  * WARRANTIES OF MERCHANTIBILITY AND FITNESS FOR A PARTICULAR PURPOSE.  */
end_comment

begin_comment
comment|/*  * Options.  */
end_comment

begin_define
define|#
directive|define
name|CI_ADDRS
value|1
end_define

begin_comment
comment|/* IP Addresses */
end_comment

begin_define
define|#
directive|define
name|CI_COMPRESSTYPE
value|2
end_define

begin_comment
comment|/* Compression Type */
end_comment

begin_define
define|#
directive|define
name|CI_ADDR
value|3
end_define

begin_define
define|#
directive|define
name|MAX_STATES
value|16
end_define

begin_comment
comment|/* from slcompress.h */
end_comment

begin_define
define|#
directive|define
name|IPCP_VJMODE_OLD
value|1
end_define

begin_comment
comment|/* "old" mode (option # = 0x0037) */
end_comment

begin_define
define|#
directive|define
name|IPCP_VJMODE_RFC1172
value|2
end_define

begin_comment
comment|/* "old-rfc"mode (option # = 0x002d) */
end_comment

begin_define
define|#
directive|define
name|IPCP_VJMODE_RFC1332
value|3
end_define

begin_comment
comment|/* "new-rfc"mode (option # = 0x002d, */
end_comment

begin_comment
comment|/*  maxslot and slot number */
end_comment

begin_comment
comment|/*  compression from Aug. 1991 */
end_comment

begin_comment
comment|/*  ipcp draft RFC) */
end_comment

begin_define
define|#
directive|define
name|IPCP_VJ_COMP
value|0x002d
end_define

begin_comment
comment|/* current value for VJ compression option*/
end_comment

begin_define
define|#
directive|define
name|IPCP_VJ_COMP_OLD
value|0x0037
end_define

begin_comment
comment|/* "old" (i.e, broken) value for VJ */
end_comment

begin_comment
comment|/* compression option*/
end_comment

begin_typedef
typedef|typedef
struct|struct
name|ipcp_options
block|{
name|int
name|neg_addrs
range|:
literal|1
decl_stmt|;
comment|/* Negotiate IP Addresses? */
name|int
name|neg_addr
range|:
literal|1
decl_stmt|;
comment|/* Negotiate IP Address? */
name|int
name|got_addr
range|:
literal|1
decl_stmt|;
comment|/* Got IP Address? */
name|u_long
name|ouraddr
decl_stmt|,
name|hisaddr
decl_stmt|;
comment|/* Addresses in NETWORK BYTE ORDER */
name|int
name|neg_vj
range|:
literal|1
decl_stmt|;
comment|/* Van Jacobson Compression? */
name|u_char
name|maxslotindex
decl_stmt|,
name|cflag
decl_stmt|;
comment|/* fields for Aug. 1991 Draft VJ */
comment|/* compression negotiation */
block|}
name|ipcp_options
typedef|;
end_typedef

begin_decl_stmt
specifier|extern
name|ipcp_options
name|ipcp_wantoptions
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|ipcp_options
name|ipcp_gotoptions
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|ipcp_options
name|ipcp_allowoptions
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|ipcp_options
name|ipcp_hisoptions
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|ipcp_init
name|__ARGS
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|ipcp_vj_setmode
name|__ARGS
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|ipcp_activeopen
name|__ARGS
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|ipcp_passiveopen
name|__ARGS
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|ipcp_close
name|__ARGS
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|ipcp_lowerup
name|__ARGS
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|ipcp_lowerdown
name|__ARGS
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|ipcp_input
name|__ARGS
argument_list|(
operator|(
name|int
operator|,
name|u_char
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|ipcp_protrej
name|__ARGS
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

end_unit

