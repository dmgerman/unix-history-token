begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	pup.h	6.1	83/07/29	*/
end_comment

begin_struct
struct|struct
name|pupport
block|{
name|u_char
name|pup_net
decl_stmt|;
name|u_char
name|pup_host
decl_stmt|;
name|u_char
name|pup_socket
index|[
literal|4
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * PUP header.  */
end_comment

begin_struct
struct|struct
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
name|u_char
name|pup_dnet
decl_stmt|;
comment|/* destination */
name|u_char
name|pup_dhost
decl_stmt|;
name|u_char
name|pup_dsock
index|[
literal|4
index|]
decl_stmt|;
name|u_char
name|pup_snet
decl_stmt|;
comment|/* source */
name|u_char
name|pup_shost
decl_stmt|;
name|u_char
name|pup_ssock
index|[
literal|4
index|]
decl_stmt|;
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

begin_define
define|#
directive|define
name|MINPUPSIZ
value|(sizeof (struct pup_header) + sizeof (short))
end_define

begin_define
define|#
directive|define
name|MAXPUPDATA
value|532
end_define

begin_define
define|#
directive|define
name|MAXPUPSIZ
value|(MINPUPSIZ + MAXPUPDATA)
end_define

begin_define
define|#
directive|define
name|PUP_NOCKSUM
value|0xffff
end_define

begin_comment
comment|/* no checksum supplied */
end_comment

begin_comment
comment|/*  * A sockaddr, as seen through the eyes of PUP.  */
end_comment

begin_struct
struct|struct
name|sockaddr_pup
block|{
name|short
name|spup_family
decl_stmt|;
name|short
name|spup_zero1
decl_stmt|;
name|u_char
name|spup_net
decl_stmt|;
name|u_char
name|spup_host
decl_stmt|;
name|u_char
name|spup_sock
index|[
literal|4
index|]
decl_stmt|;
name|char
name|spup_zero2
index|[
literal|4
index|]
decl_stmt|;
block|}
struct|;
end_struct

end_unit

