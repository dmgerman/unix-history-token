begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	pup.h	1.1	82/02/15	*/
end_comment

begin_comment
comment|/*  * PUP port addressing.  */
end_comment

begin_struct
struct|struct
name|pupport
block|{
name|u_char
name|pp_net
decl_stmt|;
name|u_char
name|pp_host
decl_stmt|;
name|u_long
name|pp_socket
decl_stmt|;
block|}
comment|/*  * PUP header.  */
decl|struct
name|pup_header
block|{
name|u_short
name|pup_length
decl_stmt|;
name|u_char
name|pup_tcontrol
decl_stmt|;
comment|/* transport control */
name|u_char
name|pup_type
decl_stmt|;
comment|/* protocol type */
name|u_long
name|pup_id
decl_stmt|;
comment|/* used by protocols */
name|struct
name|pupport
name|pup_dport
decl_stmt|,
name|pup_sport
decl_stmt|;
define|#
directive|define
name|pup_dnet
value|pup_dport.pp_net
define|#
directive|define
name|pup_dhost
value|pup_dport.pp_dhost
define|#
directive|define
name|pup_dsocket
value|pup_dport.pp_socket
define|#
directive|define
name|pup_snet
value|pup_sport.pp_net
define|#
directive|define
name|pup_shost
value|pup_sport.pp_host
define|#
directive|define
name|pup_ssocket
value|pup_sport.pp_socket
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|PUP_TRACE
value|01
end_define

begin_comment
comment|/* trace pup in network */
end_comment

end_unit

