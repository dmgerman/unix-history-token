begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1984, 1985, 1986 Regents of the University of California.  * All rights reserved.  The Berkeley software License Agreement  * specifies the terms and conditions for redistribution.  *  *	@(#)ns_error.h	7.1 (Berkeley) %G%  */
end_comment

begin_comment
comment|/*  * Xerox NS error messages  */
end_comment

begin_struct
struct|struct
name|ns_errp
block|{
name|u_short
name|ns_err_num
decl_stmt|;
comment|/* Error Number */
name|u_short
name|ns_err_param
decl_stmt|;
comment|/* Error Parameter */
name|struct
name|idp
name|ns_err_idp
decl_stmt|;
comment|/* Initial segment of offending 						   packet */
name|u_char
name|ns_err_lev2
index|[
literal|12
index|]
decl_stmt|;
comment|/* at least this much higher 						   level protocol */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|ns_epidp
block|{
name|struct
name|idp
name|ns_ep_idp
decl_stmt|;
name|struct
name|ns_errp
name|ns_ep_errp
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|NS_ERR_UNSPEC
value|0
end_define

begin_comment
comment|/* Unspecified Error detected at dest. */
end_comment

begin_define
define|#
directive|define
name|NS_ERR_BADSUM
value|1
end_define

begin_comment
comment|/* Bad Checksum detected at dest */
end_comment

begin_define
define|#
directive|define
name|NS_ERR_NOSOCK
value|2
end_define

begin_comment
comment|/* Specified socket does not exist at dest*/
end_comment

begin_define
define|#
directive|define
name|NS_ERR_FULLUP
value|3
end_define

begin_comment
comment|/* Dest. refuses packet due to resource lim.*/
end_comment

begin_define
define|#
directive|define
name|NS_ERR_UNSPEC_T
value|0x200
end_define

begin_comment
comment|/* Unspec. Error occured before reaching dest*/
end_comment

begin_define
define|#
directive|define
name|NS_ERR_BADSUM_T
value|0x201
end_define

begin_comment
comment|/* Bad Checksum detected in transit */
end_comment

begin_define
define|#
directive|define
name|NS_ERR_UNREACH_HOST
value|0x202
end_define

begin_comment
comment|/* Dest cannot be reached from here*/
end_comment

begin_define
define|#
directive|define
name|NS_ERR_TOO_OLD
value|0x203
end_define

begin_comment
comment|/* Packet x'd 15 routers without delivery*/
end_comment

begin_define
define|#
directive|define
name|NS_ERR_TOO_BIG
value|0x204
end_define

begin_comment
comment|/* Packet too large to be forwarded through 				   some intermediate gateway.  The error 				   parameter field contains the max packet 				   size that can be accommodated */
end_comment

begin_define
define|#
directive|define
name|NS_ERR_ATHOST
value|4
end_define

begin_define
define|#
directive|define
name|NS_ERR_ENROUTE
value|5
end_define

begin_define
define|#
directive|define
name|NS_ERR_MAX
value|(NS_ERR_ATHOST + NS_ERR_ENROUTE + 1)
end_define

begin_define
define|#
directive|define
name|ns_err_x
parameter_list|(
name|c
parameter_list|)
value|(((c)&0x200) ? ((c) - 0x200 + NS_ERR_ATHOST) : c )
end_define

begin_comment
comment|/*  * Variables related to this implementation  * of the network systems error message protocol.  */
end_comment

begin_struct
struct|struct
name|ns_errstat
block|{
comment|/* statistics related to ns_err packets generated */
name|int
name|ns_es_error
decl_stmt|;
comment|/* # of calls to ns_error */
name|int
name|ns_es_oldshort
decl_stmt|;
comment|/* no error 'cuz old ip too short */
name|int
name|ns_es_oldns_err
decl_stmt|;
comment|/* no error 'cuz old was ns_err */
name|int
name|ns_es_outhist
index|[
name|NS_ERR_MAX
index|]
decl_stmt|;
comment|/* statistics related to input messages processed */
name|int
name|ns_es_badcode
decl_stmt|;
comment|/* ns_err_code out of range */
name|int
name|ns_es_tooshort
decl_stmt|;
comment|/* packet< IDP_MINLEN */
name|int
name|ns_es_checksum
decl_stmt|;
comment|/* bad checksum */
name|int
name|ns_es_badlen
decl_stmt|;
comment|/* calculated bound mismatch */
name|int
name|ns_es_reflect
decl_stmt|;
comment|/* number of responses */
name|int
name|ns_es_inhist
index|[
name|NS_ERR_MAX
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_ifdef
ifdef|#
directive|ifdef
name|KERNEL
end_ifdef

begin_decl_stmt
name|struct
name|ns_errstat
name|ns_errstat
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

