begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Copyright (c) University of British Columbia, 1984 */
end_comment

begin_comment
comment|/*  *  *  X.25 Packet Level Definitions:  *  */
end_comment

begin_comment
comment|/* Packet type identifier field defintions. */
end_comment

begin_define
define|#
directive|define
name|X25_CALL
value|11
end_define

begin_define
define|#
directive|define
name|X25_CALL_ACCEPTED
value|15
end_define

begin_define
define|#
directive|define
name|X25_CLEAR
value|19
end_define

begin_define
define|#
directive|define
name|X25_CLEAR_CONFIRM
value|23
end_define

begin_define
define|#
directive|define
name|X25_DATA
value|0
end_define

begin_define
define|#
directive|define
name|X25_INTERRUPT
value|35
end_define

begin_define
define|#
directive|define
name|X25_INTERRUPT_CONFIRM
value|39
end_define

begin_define
define|#
directive|define
name|X25_RR
value|1
end_define

begin_define
define|#
directive|define
name|X25_RNR
value|5
end_define

begin_define
define|#
directive|define
name|X25_RESET
value|27
end_define

begin_define
define|#
directive|define
name|X25_RESET_CONFIRM
value|31
end_define

begin_define
define|#
directive|define
name|X25_RESTART
value|251
end_define

begin_define
define|#
directive|define
name|X25_RESTART_CONFIRM
value|255
end_define

begin_comment
comment|/* Restart cause field definitions. */
end_comment

begin_define
define|#
directive|define
name|X25_RESTART_LOCAL_PROCEDURE_ERROR
value|1
end_define

begin_define
define|#
directive|define
name|X25_RESTART_NETWORK_CONGESTION
value|3
end_define

begin_define
define|#
directive|define
name|X25_RESTART_NETWORK_OPERATIONAL
value|7
end_define

begin_comment
comment|/* Miscellaneous definitions. */
end_comment

begin_define
define|#
directive|define
name|DATA_PACKET_DESIGNATOR
value|0x01
end_define

begin_define
define|#
directive|define
name|RR_OR_RNR_PACKET_DESIGNATOR
value|0x02
end_define

begin_define
define|#
directive|define
name|RR_PACKET_DESIGNATOR
value|0x04
end_define

begin_define
define|#
directive|define
name|DEFAULT_WINDOW_SIZE
value|2
end_define

begin_define
define|#
directive|define
name|MODULUS
value|8
end_define

begin_define
define|#
directive|define
name|ADDRLN
value|1
end_define

begin_define
define|#
directive|define
name|MAXADDRLN
value|15
end_define

begin_define
define|#
directive|define
name|FACILITIESLN
value|1
end_define

begin_define
define|#
directive|define
name|MAXFACILITIESLN
value|10
end_define

begin_define
define|#
directive|define
name|MAXUSERDATA
value|16
end_define

begin_define
define|#
directive|define
name|MAXCALLINFOLN
value|1+15+1+10+16
end_define

begin_define
define|#
directive|define
name|PACKET_OK
value|0
end_define

begin_define
define|#
directive|define
name|IGNORE_PACKET
value|1
end_define

begin_define
define|#
directive|define
name|ERROR_PACKET
value|2
end_define

begin_typedef
typedef|typedef
name|char
name|bool
typedef|;
end_typedef

begin_define
define|#
directive|define
name|FALSE
value|0
end_define

begin_define
define|#
directive|define
name|TRUE
value|1
end_define

begin_comment
comment|/*  *  X.25 Packet format definitions  */
end_comment

begin_typedef
typedef|typedef
name|u_char
name|octet
typedef|;
end_typedef

begin_struct
struct|struct
name|x25_calladdr
block|{
ifdef|#
directive|ifdef
name|vax
name|unsigned
name|called_addrlen
range|:
literal|4
decl_stmt|;
name|unsigned
name|calling_addrlen
range|:
literal|4
decl_stmt|;
endif|#
directive|endif
ifdef|#
directive|ifdef
name|sun
name|unsigned
name|calling_addrlen
range|:
literal|4
decl_stmt|;
name|unsigned
name|called_addrlen
range|:
literal|4
decl_stmt|;
endif|#
directive|endif
name|char
name|address_field
index|[
name|MAXADDRLN
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|FACILITIES_REVERSE_CHARGE
value|0x1
end_define

begin_define
define|#
directive|define
name|FACILITIES_THROUGHPUT
value|0x2
end_define

begin_define
define|#
directive|define
name|FACILITIES_PACKETSIZE
value|0x42
end_define

begin_define
define|#
directive|define
name|FACILITIES_WINDOWSIZE
value|0x43
end_define

begin_define
define|#
directive|define
name|PKHEADERLN
value|3
end_define

begin_struct
struct|struct
name|x25_packet
block|{
ifdef|#
directive|ifdef
name|vax
name|unsigned
name|lc_group_number
range|:
literal|4
decl_stmt|;
name|unsigned
name|fmt_identifier
range|:
literal|3
decl_stmt|;
name|unsigned
name|q_bit
range|:
literal|1
decl_stmt|;
endif|#
directive|endif
ifdef|#
directive|ifdef
name|sun
name|unsigned
name|q_bit
range|:
literal|1
decl_stmt|;
name|unsigned
name|fmt_identifier
range|:
literal|3
decl_stmt|;
name|unsigned
name|lc_group_number
range|:
literal|4
decl_stmt|;
endif|#
directive|endif
name|octet
name|logical_channel_number
decl_stmt|;
name|octet
name|packet_type
decl_stmt|;
name|octet
name|packet_data
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|data_packet
block|{
ifdef|#
directive|ifdef
name|vax
name|unsigned
name|z
range|:
literal|1
decl_stmt|;
name|unsigned
name|ps
range|:
literal|3
decl_stmt|;
name|unsigned
name|m_bit
range|:
literal|1
decl_stmt|;
name|unsigned
name|pr
range|:
literal|3
decl_stmt|;
endif|#
directive|endif
ifdef|#
directive|ifdef
name|sun
name|unsigned
name|pr
range|:
literal|3
decl_stmt|;
name|unsigned
name|m_bit
range|:
literal|1
decl_stmt|;
name|unsigned
name|ps
range|:
literal|3
decl_stmt|;
name|unsigned
name|z
range|:
literal|1
decl_stmt|;
endif|#
directive|endif
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|PR
parameter_list|(
name|xp
parameter_list|)
value|(((struct data_packet *)&xp -> packet_type)->pr)
end_define

begin_define
define|#
directive|define
name|PS
parameter_list|(
name|xp
parameter_list|)
value|(((struct data_packet *)&xp -> packet_type)->ps)
end_define

begin_define
define|#
directive|define
name|MBIT
parameter_list|(
name|xp
parameter_list|)
value|(((struct data_packet *)&xp -> packet_type)->m_bit)
end_define

begin_function_decl
name|struct
name|x25_packet
modifier|*
name|pk_template
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* Define X.25 packet level states. */
end_comment

begin_comment
comment|/* Call setup and clearing substates.  */
end_comment

begin_define
define|#
directive|define
name|LISTEN
value|0
end_define

begin_define
define|#
directive|define
name|READY
value|1
end_define

begin_define
define|#
directive|define
name|RECEIVED_CALL
value|2
end_define

begin_define
define|#
directive|define
name|SENT_CALL
value|3
end_define

begin_define
define|#
directive|define
name|DATA_TRANSFER
value|4
end_define

begin_define
define|#
directive|define
name|RECEIVED_CLEAR
value|5
end_define

begin_define
define|#
directive|define
name|SENT_CLEAR
value|6
end_define

begin_comment
comment|/* DTE states. */
end_comment

begin_define
define|#
directive|define
name|DTE_WAITING
value|7
end_define

begin_define
define|#
directive|define
name|DTE_RECEIVED_RESTART
value|8
end_define

begin_define
define|#
directive|define
name|DTE_SENT_RESTART
value|9
end_define

begin_define
define|#
directive|define
name|DTE_READY
value|0
end_define

begin_define
define|#
directive|define
name|MAXSTATES
value|10
end_define

begin_comment
comment|/*  *  The following definitions are used in a switch statement after  *  determining the packet type.  These values are returned by the  *  pk_decode procedure.   */
end_comment

begin_define
define|#
directive|define
name|CALL
value|0 * MAXSTATES
end_define

begin_define
define|#
directive|define
name|CALL_ACCEPTED
value|1 * MAXSTATES
end_define

begin_define
define|#
directive|define
name|CLEAR
value|2 * MAXSTATES
end_define

begin_define
define|#
directive|define
name|CLEAR_CONF
value|3 * MAXSTATES
end_define

begin_define
define|#
directive|define
name|DATA
value|4 * MAXSTATES
end_define

begin_define
define|#
directive|define
name|INTERRUPT
value|5 * MAXSTATES
end_define

begin_define
define|#
directive|define
name|INTERRUPT_CONF
value|6 * MAXSTATES
end_define

begin_define
define|#
directive|define
name|RR
value|7 * MAXSTATES
end_define

begin_define
define|#
directive|define
name|RNR
value|8 * MAXSTATES
end_define

begin_define
define|#
directive|define
name|RESET
value|9 * MAXSTATES
end_define

begin_define
define|#
directive|define
name|RESET_CONF
value|10 * MAXSTATES
end_define

begin_define
define|#
directive|define
name|RESTART
value|11 * MAXSTATES
end_define

begin_define
define|#
directive|define
name|RESTART_CONF
value|12 * MAXSTATES
end_define

begin_define
define|#
directive|define
name|INVALID_PACKET
value|13 * MAXSTATES
end_define

begin_define
define|#
directive|define
name|DELETE_PACKET
value|INVALID_PACKET
end_define

end_unit

