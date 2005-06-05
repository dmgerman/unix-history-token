begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_ifndef
ifndef|#
directive|ifndef
name|L2_PACKET_H
end_ifndef

begin_define
define|#
directive|define
name|L2_PACKET_H
end_define

begin_define
define|#
directive|define
name|MAC2STR
parameter_list|(
name|a
parameter_list|)
value|(a)[0], (a)[1], (a)[2], (a)[3], (a)[4], (a)[5]
end_define

begin_define
define|#
directive|define
name|MACSTR
value|"%02x:%02x:%02x:%02x:%02x:%02x"
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|ETH_P_EAPOL
end_ifndef

begin_define
define|#
directive|define
name|ETH_P_EAPOL
value|0x888e
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ETH_P_RSN_PREAUTH
end_ifndef

begin_define
define|#
directive|define
name|ETH_P_RSN_PREAUTH
value|0x88c7
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_struct_decl
struct_decl|struct
name|l2_packet_data
struct_decl|;
end_struct_decl

begin_struct
struct|struct
name|l2_ethhdr
block|{
name|u8
name|h_dest
index|[
name|ETH_ALEN
index|]
decl_stmt|;
name|u8
name|h_source
index|[
name|ETH_ALEN
index|]
decl_stmt|;
name|u16
name|h_proto
decl_stmt|;
block|}
name|__attribute__
argument_list|(
operator|(
name|packed
operator|)
argument_list|)
struct|;
end_struct

begin_function_decl
name|struct
name|l2_packet_data
modifier|*
name|l2_packet_init
parameter_list|(
specifier|const
name|char
modifier|*
name|ifname
parameter_list|,
specifier|const
name|u8
modifier|*
name|own_addr
parameter_list|,
name|unsigned
name|short
name|protocol
parameter_list|,
name|void
function_decl|(
modifier|*
name|rx_callback
function_decl|)
parameter_list|(
name|void
modifier|*
name|ctx
parameter_list|,
name|unsigned
name|char
modifier|*
name|src_addr
parameter_list|,
name|unsigned
name|char
modifier|*
name|buf
parameter_list|,
name|size_t
name|len
parameter_list|)
parameter_list|,
name|void
modifier|*
name|rx_callback_ctx
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|l2_packet_deinit
parameter_list|(
name|struct
name|l2_packet_data
modifier|*
name|l2
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|l2_packet_get_own_addr
parameter_list|(
name|struct
name|l2_packet_data
modifier|*
name|l2
parameter_list|,
name|u8
modifier|*
name|addr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|l2_packet_send
parameter_list|(
name|struct
name|l2_packet_data
modifier|*
name|l2
parameter_list|,
name|u8
modifier|*
name|buf
parameter_list|,
name|size_t
name|len
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|l2_packet_set_rx_l2_hdr
parameter_list|(
name|struct
name|l2_packet_data
modifier|*
name|l2
parameter_list|,
name|int
name|rx_l2_hdr
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* L2_PACKET_H */
end_comment

end_unit

