begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	if_un.h	4.2	82/03/04	*/
end_comment

begin_comment
comment|/*  * Structure of a Ungermann-Bass datagram header.  */
end_comment

begin_struct
struct|struct
name|un_header
block|{
name|u_short
name|un_length
decl_stmt|;
name|u_char
name|un_type
decl_stmt|;
name|u_char
name|un_control
decl_stmt|;
name|u_short
name|un_dnet
decl_stmt|;
name|u_short
name|un_dniu
decl_stmt|;
name|u_char
name|un_dport
decl_stmt|;
name|u_char
name|un_dtype
decl_stmt|;
name|u_short
name|un_snet
decl_stmt|;
name|u_short
name|un_sniu
decl_stmt|;
name|u_char
name|un_sport
decl_stmt|;
name|u_char
name|un_stype
decl_stmt|;
name|u_char
name|un_option
decl_stmt|;
name|u_char
name|un_bcc
decl_stmt|;
name|u_short
name|un_ptype
decl_stmt|;
comment|/* protocol type */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Protocol types  */
end_comment

begin_define
define|#
directive|define
name|UNTYPE_INQUIRE
value|1
end_define

begin_comment
comment|/* inquire - "Who am I?" */
end_comment

begin_define
define|#
directive|define
name|UNTYPE_IP
value|2
end_define

begin_comment
comment|/* Internet Protocol */
end_comment

end_unit

