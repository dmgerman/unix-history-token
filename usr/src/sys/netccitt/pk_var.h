begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Copyright (c) University of British Columbia, 1984 */
end_comment

begin_comment
comment|/*  *  *  X.25 Logical Channel Descriptor  *  */
end_comment

begin_struct
struct|struct
name|pklcd
block|{
name|short
name|lcd_lcn
decl_stmt|;
comment|/* Logical channel number */
name|short
name|lcd_state
decl_stmt|;
comment|/* Logical Channel state */
name|bool
name|lcd_intrconf_pending
decl_stmt|;
comment|/* Interrupt confirmation pending */
name|octet
name|lcd_intrdata
decl_stmt|;
comment|/* Octet of incoming intr data */
name|short
name|lcd_timer
decl_stmt|;
comment|/* Various timer values */
name|char
name|lcd_retry
decl_stmt|;
comment|/* Timer retry count */
name|char
name|lcd_rsn
decl_stmt|;
comment|/* Seq no of last received packet */
name|char
name|lcd_ssn
decl_stmt|;
comment|/* Seq no of next packet to send */
name|char
name|lcd_output_window
decl_stmt|;
comment|/* Output flow control window */
name|char
name|lcd_input_window
decl_stmt|;
comment|/* Input flow control window */
name|char
name|lcd_last_transmitted_pr
decl_stmt|;
comment|/* Last Pr value transmitted */
name|bool
name|lcd_rnr_condition
decl_stmt|;
comment|/* Remote in busy condition */
name|bool
name|lcd_window_condition
decl_stmt|;
comment|/* Output window size exceeded */
name|bool
name|lcd_reset_condition
decl_stmt|;
comment|/* True, if waiting reset confirm */
name|char
name|lcd_packetsize
decl_stmt|;
comment|/* Maximum packet size */
name|char
name|lcd_windowsize
decl_stmt|;
comment|/* Window size - both directions */
name|octet
name|lcd_closed_user_group
decl_stmt|;
comment|/* Closed user group specification */
name|char
name|lcd_flags
decl_stmt|;
comment|/* copy of sockaddr_x25 op_flags */
name|struct
name|x25_packet
modifier|*
name|lcd_template
decl_stmt|;
comment|/* Address of current packet */
name|struct
name|socket
modifier|*
name|lcd_so
decl_stmt|;
comment|/* Socket addr for connection */
name|struct
name|sockaddr_x25
modifier|*
name|lcd_craddr
decl_stmt|;
comment|/* Calling address */
name|struct
name|sockaddr_x25
modifier|*
name|lcd_ceaddr
decl_stmt|;
comment|/* Called address */
name|time_t
name|lcd_stime
decl_stmt|;
comment|/* time circuit established */
name|long
name|lcd_txcnt
decl_stmt|;
comment|/* Data packet transmit count */
name|long
name|lcd_rxcnt
decl_stmt|;
comment|/* Data packet receive count */
name|short
name|lcd_intrcnt
decl_stmt|;
comment|/* Interrupt packet transmit count */
name|struct
name|pklcd
modifier|*
name|lcd_listen
decl_stmt|;
comment|/* Next lcd on listen queue */
name|struct
name|pkcb
modifier|*
name|lcd_pkp
decl_stmt|;
comment|/* network this lcd is attached to */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Per network information, allocated dynamically  * when a new network is configured.  */
end_comment

begin_struct
struct|struct
name|pkcb
block|{
name|struct
name|pkcb
modifier|*
name|pk_next
decl_stmt|;
name|short
name|pk_state
decl_stmt|;
comment|/* packet level status */
name|short
name|pk_maxlcn
decl_stmt|;
comment|/* local copy of xc_maxlcn */
name|int
function_decl|(
modifier|*
name|pk_output
function_decl|)
parameter_list|()
function_decl|;
comment|/* link level output procedure */
name|struct
name|x25config
modifier|*
name|pk_xcp
decl_stmt|;
comment|/* network specific configuration */
name|struct
name|pklcd
modifier|*
name|pk_chan
index|[
literal|1
index|]
decl_stmt|;
comment|/* actual size == xc_maxlcn+1 */
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
name|pkcb
modifier|*
name|pkcbhead
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* head of linked list of networks */
end_comment

begin_decl_stmt
name|struct
name|pklcd
modifier|*
name|pk_listenhead
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|pk_name
index|[]
decl_stmt|,
modifier|*
name|pk_state
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|pk_t20
decl_stmt|,
name|pk_t21
decl_stmt|,
name|pk_t22
decl_stmt|,
name|pk_t23
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

