begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_decl_stmt
specifier|static
name|char
name|nic39hid
index|[]
init|=
literal|"@(#)$FreeBSD$"
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*******************************************************************************  *  II - Version 0.1 $Revision: 1.1 $   $State: Exp $  *  * Copyright 1994 Dietmar Friede  *******************************************************************************  * Bug reports, patches, comments, suggestions should be sent to:  *  *	jkr@saarlink.de or jkrause@guug.de  *  *******************************************************************************  * $Log: nic3009.h,v $  *  ******************************************************************************/
end_comment

begin_comment
comment|/*  * This file defines the NICCY 3009 Interface. Copyright Dr. Neuhaus GmbH,  * Hamburg and Dietmar Friede  *  */
end_comment

begin_define
define|#
directive|define
name|NO_MORE_DATA
value|0x00
end_define

begin_comment
comment|/* der Message folgen keine Daten    */
end_comment

begin_define
define|#
directive|define
name|MORE_DATA
value|0x01
end_define

begin_comment
comment|/* der Message folgen weitere Daten  */
end_comment

begin_define
define|#
directive|define
name|DPR_LEN
value|0x800
end_define

begin_comment
comment|/* 2 kBytes gross            */
end_comment

begin_define
define|#
directive|define
name|DPR_VAR_AREA_LEN
value|0x100
end_define

begin_comment
comment|/* davon fuer allg. Variablen */
end_comment

begin_define
define|#
directive|define
name|DPR_MBX_LEN
value|(DPR_LEN-DPR_VAR_AREA_LEN)/2
end_define

begin_comment
comment|/* 0x380 lang */
end_comment

begin_define
define|#
directive|define
name|DPR_MBX_FLAG_LEN
value|2
end_define

begin_comment
comment|/* zwei Bytes MBX-Zustand... */
end_comment

begin_define
define|#
directive|define
name|DPR_MSG_HDR_LEN
value|10
end_define

begin_comment
comment|/* Msg-Laenge ohne Datafield */
end_comment

begin_define
define|#
directive|define
name|DATAFIELD_LEN
value|(DPR_MBX_LEN-DPR_MBX_FLAG_LEN-DPR_MSG_HDR_LEN)
end_define

begin_define
define|#
directive|define
name|MAX_B3_LEN
value|(2048+2)
end_define

begin_comment
comment|/* Daten und Network-Header  */
end_comment

begin_pragma
pragma|#
directive|pragma
name|pack
name|(
name|1
name|)
end_pragma

begin_typedef
typedef|typedef
struct|struct
block|{
name|u_char
name|msg_flag
decl_stmt|;
comment|/* Signalisierung NICCY / PC */
name|u_char
name|progress
decl_stmt|;
comment|/* NICCY-interne Verwendung ! */
name|u_char
name|type
decl_stmt|;
name|u_char
name|subtype
decl_stmt|;
name|u_short
name|number
decl_stmt|;
name|u_char
name|more_data
decl_stmt|;
name|u_char
name|reserved
decl_stmt|;
name|u_short
name|data_len
decl_stmt|;
name|u_short
name|plci
decl_stmt|;
name|u_char
name|data
index|[
name|DATAFIELD_LEN
index|]
decl_stmt|;
block|}
name|mbx_type
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|mbx_type
name|up_mbx
decl_stmt|;
comment|/* Offset 0x000-0x37F */
name|mbx_type
name|dn_mbx
decl_stmt|;
comment|/* Offset 0x380-0x6FF */
name|u_char
name|card_number
decl_stmt|;
comment|/* Offset 0x700      */
name|u_char
name|card_state
decl_stmt|;
comment|/* Offset 0x701      */
name|u_short
name|mainloop_cnt
decl_stmt|;
comment|/* Offset 0x702-0x703 */
name|u_char
name|watchdog_cnt
decl_stmt|;
comment|/* Offset 0x704      */
name|u_char
name|hw_config
decl_stmt|;
comment|/* Offset 0x705      */
name|u_char
name|int_flg_pc
decl_stmt|;
comment|/* Offset 0x706      */
name|u_char
name|int_flg_nic
decl_stmt|;
comment|/* Offset 0x707      */
name|u_char
name|api_area
index|[
literal|64
index|]
decl_stmt|;
comment|/* Offset 0x708-0x747 */
name|u_char
name|api_active
decl_stmt|;
comment|/* Offset 0x748      */
name|u_char
name|tei
decl_stmt|;
comment|/* Offset 0x749      */
name|u_char
name|state_b1
decl_stmt|;
comment|/* Offset 0x74A      */
name|u_char
name|state_b2
decl_stmt|;
comment|/* Offset 0x74B      */
name|u_char
name|si_b1
decl_stmt|;
comment|/* Offset 0x74C      */
name|u_char
name|si_b2
decl_stmt|;
comment|/* Offset 0x74D      */
name|u_short
name|calls_in
decl_stmt|;
comment|/* Offset 0x74E-0x74F */
name|u_short
name|calls_out
decl_stmt|;
comment|/* Offset 0x750-0x751 */
name|u_char
name|ram_config
decl_stmt|;
comment|/* Offset 0x752      */
name|u_char
name|spv_request_flag
decl_stmt|;
comment|/* Offset 0x753      */
name|u_char
name|dcp_state_b1
decl_stmt|;
comment|/* Offset 0x754      */
name|u_char
name|dcp_state_b2
decl_stmt|;
comment|/* Offset 0x755      */
name|u_char
name|dc_protocol
decl_stmt|;
comment|/* Offset 0x756      */
name|u_char
name|poll_flag
decl_stmt|;
comment|/* Offset 0x757      */
name|u_char
name|debug
index|[
name|DPR_LEN
operator|-
literal|0x758
operator|-
literal|4
index|]
decl_stmt|;
comment|/* Offset 0x758-0x7FB */
name|u_short
name|signal_niccy_to_pc
decl_stmt|;
comment|/* Offset 0x7FC-0x7FD */
name|u_short
name|signal_pc_to_niccy
decl_stmt|;
comment|/* Offset 0x7FE-0x7FF */
block|}
name|dpr_type
typedef|;
end_typedef

begin_pragma
pragma|#
directive|pragma
name|pack
name|(
name|)
end_pragma

end_unit

