begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/*           structures internal to the HMP implementation                */
end_comment

begin_comment
comment|/**************************************************************************/
end_comment

begin_struct
struct|struct
name|hmp_hdr
comment|/* HMP packet header */
block|{
name|u_char
name|hh_systyp
decl_stmt|;
comment|/* system type */
name|u_char
name|hh_msgtyp
decl_stmt|;
comment|/* message type */
name|u_char
name|hh_port
decl_stmt|;
comment|/* application port # */
name|u_char
name|hh_ctlflg
decl_stmt|;
comment|/* control flag */
name|u_short
name|hh_seq
decl_stmt|;
comment|/* sequence # */
name|u_short
name|hh_passwd
decl_stmt|;
comment|/* remote/local passwd */
name|u_short
name|hh_cksum
decl_stmt|;
comment|/* checksum */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|HMPIPHDR
value|(sizeof(struct ip)+sizeof(struct hmp_hdr))
end_define

begin_struct
struct|struct
name|hmpcb
comment|/* HMP pcb */
block|{
name|struct
name|inpcb
modifier|*
name|hp_inpcb
decl_stmt|;
comment|/* pointer to inpcb */
name|u_char
name|hp_flags
decl_stmt|;
comment|/* flags */
name|u_char
name|hp_lsystyp
decl_stmt|;
comment|/* local system type */
name|u_char
name|hp_rsystyp
decl_stmt|;
comment|/* remote system type */
name|u_char
name|hp_lmsgtyp
decl_stmt|;
comment|/* local message type */
name|u_char
name|hp_rmsgtyp
decl_stmt|;
comment|/* remote message type */
name|u_char
name|hp_ctlflg
decl_stmt|;
comment|/* control flags */
name|u_short
name|hp_lseq
decl_stmt|;
comment|/* local sequence number */
name|u_short
name|hp_rseq
decl_stmt|;
comment|/* remote sequence number */
name|u_short
name|hp_lpasswd
decl_stmt|;
comment|/* local password */
name|u_short
name|hp_rpasswd
decl_stmt|;
comment|/* remote password */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|hmp_stat
block|{
name|struct
name|in_stat
name|h_in
decl_stmt|;
define|#
directive|define
name|h_total
value|h_in.in_total
define|#
directive|define
name|h_badsum
value|h_in.in_badsum
define|#
directive|define
name|h_tooshort
value|h_in.in_tooshort
define|#
directive|define
name|h_drops
value|h_in.in_drops
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|intohmpcb
parameter_list|(
name|i
parameter_list|)
value|((struct hmpcb *) ((i)->inp_ppcb))
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|KERNEL
end_ifdef

begin_decl_stmt
specifier|extern
name|struct
name|inpcb
name|hmp
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

