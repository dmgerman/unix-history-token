begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * pcap-dag.c: Packet capture interface for Endace DAG card.  *  * The functionality of this code attempts to mimic that of pcap-linux as much  * as possible.  This code is only needed when compiling in the DAG card code  * at the same time as another type of device.  *  * Author: Richard Littin, Sean Irvine ({richard,sean}@reeltwo.com)  */
end_comment

begin_function_decl
name|pcap_t
modifier|*
name|dag_create
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|,
name|int
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|dag_findalldevs
parameter_list|(
name|pcap_if_t
modifier|*
modifier|*
name|devlistp
parameter_list|,
name|char
modifier|*
name|errbuf
parameter_list|)
function_decl|;
end_function_decl

begin_ifndef
ifndef|#
directive|ifndef
name|TYPE_AAL5
end_ifndef

begin_define
define|#
directive|define
name|TYPE_AAL5
value|4
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|TYPE_MC_HDLC
end_ifndef

begin_define
define|#
directive|define
name|TYPE_MC_HDLC
value|5
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|TYPE_MC_RAW
end_ifndef

begin_define
define|#
directive|define
name|TYPE_MC_RAW
value|6
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|TYPE_MC_ATM
end_ifndef

begin_define
define|#
directive|define
name|TYPE_MC_ATM
value|7
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|TYPE_MC_RAW_CHANNEL
end_ifndef

begin_define
define|#
directive|define
name|TYPE_MC_RAW_CHANNEL
value|8
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|TYPE_MC_AAL5
end_ifndef

begin_define
define|#
directive|define
name|TYPE_MC_AAL5
value|9
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|TYPE_COLOR_HDLC_POS
end_ifndef

begin_define
define|#
directive|define
name|TYPE_COLOR_HDLC_POS
value|10
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|TYPE_COLOR_ETH
end_ifndef

begin_define
define|#
directive|define
name|TYPE_COLOR_ETH
value|11
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|TYPE_MC_AAL2
end_ifndef

begin_define
define|#
directive|define
name|TYPE_MC_AAL2
value|12
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|TYPE_IP_COUNTER
end_ifndef

begin_define
define|#
directive|define
name|TYPE_IP_COUNTER
value|13
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|TYPE_TCP_FLOW_COUNTER
end_ifndef

begin_define
define|#
directive|define
name|TYPE_TCP_FLOW_COUNTER
value|14
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|TYPE_DSM_COLOR_HDLC_POS
end_ifndef

begin_define
define|#
directive|define
name|TYPE_DSM_COLOR_HDLC_POS
value|15
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|TYPE_DSM_COLOR_ETH
end_ifndef

begin_define
define|#
directive|define
name|TYPE_DSM_COLOR_ETH
value|16
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|TYPE_COLOR_MC_HDLC_POS
end_ifndef

begin_define
define|#
directive|define
name|TYPE_COLOR_MC_HDLC_POS
value|17
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|TYPE_AAL2
end_ifndef

begin_define
define|#
directive|define
name|TYPE_AAL2
value|18
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|TYPE_COLOR_HASH_POS
end_ifndef

begin_define
define|#
directive|define
name|TYPE_COLOR_HASH_POS
value|19
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|TYPE_COLOR_HASH_ETH
end_ifndef

begin_define
define|#
directive|define
name|TYPE_COLOR_HASH_ETH
value|20
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|TYPE_INFINIBAND
end_ifndef

begin_define
define|#
directive|define
name|TYPE_INFINIBAND
value|21
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|TYPE_IPV4
end_ifndef

begin_define
define|#
directive|define
name|TYPE_IPV4
value|22
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|TYPE_IPV6
end_ifndef

begin_define
define|#
directive|define
name|TYPE_IPV6
value|23
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|TYPE_RAW_LINK
end_ifndef

begin_define
define|#
directive|define
name|TYPE_RAW_LINK
value|24
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|TYPE_INFINIBAND_LINK
end_ifndef

begin_define
define|#
directive|define
name|TYPE_INFINIBAND_LINK
value|25
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|TYPE_PAD
end_ifndef

begin_define
define|#
directive|define
name|TYPE_PAD
value|48
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

