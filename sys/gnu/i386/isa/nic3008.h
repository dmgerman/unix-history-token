begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_decl_stmt
specifier|static
name|char
name|nic38hid
index|[]
init|=
literal|"@(#)$FreeBSD$"
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*******************************************************************************  *  II - Version 0.1 $Revision: 1.1 $   $State: Exp $  *  * Copyright 1994 Dietmar Friede  *******************************************************************************  * Bug reports, patches, comments, suggestions should be sent to:  *  *	jkr@saarlink.de or jkrause@guug.de  *  *******************************************************************************  * $Log: nic3008.h,v $  *  ******************************************************************************/
end_comment

begin_comment
comment|/*  * This file defines the NICCY 3008 Interface.  * Copyright Dr. Neuhaus GmbH, Hamburg and Dietmar Friede  * */
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
name|u_short
name|type
decl_stmt|;
comment|/* Message Subtype/Type */
name|u_char
name|source
decl_stmt|;
name|u_char
name|dest
decl_stmt|;
name|u_short
name|number
decl_stmt|;
comment|/* laufende Nachrichten-Nummer */
name|u_short
name|timeoutval
decl_stmt|;
comment|/* Wert fr Timeout */
name|u_char
name|priority
decl_stmt|;
comment|/* Nachrichten-Prioritt */
name|u_char
name|more_data
decl_stmt|;
comment|/* Nachricht vollstndig? */
name|u_short
name|data_len
decl_stmt|;
comment|/* Datenmenge */
name|u_char
name|buf_valid
decl_stmt|;
comment|/* im aux. buf.? */
name|u_char
name|reserved
index|[
literal|1
index|]
decl_stmt|;
name|u_short
name|add_info
decl_stmt|;
comment|/* Maske */
name|u_char
name|data
index|[
literal|0x30
index|]
decl_stmt|;
comment|/* Datenfeld */
block|}
name|mbx_type
typedef|;
end_typedef

begin_comment
comment|/* ------------------------------------------------------------------------ */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
comment|/* Offset 0x0000 ---------------------------------------------------------- */
name|u_char
name|msg_flg
index|[
literal|8
index|]
decl_stmt|;
comment|/* Messages in MBX i */
name|u_char
name|card_number
decl_stmt|;
comment|/* Kartennummer of Applikation */
name|u_char
name|card_state
decl_stmt|;
comment|/* Kartenstatus */
name|u_short
name|mainloop_cnt
decl_stmt|;
comment|/* NICCY's M'loop,68000-Notation*/
name|u_char
name|watchdog_cnt
decl_stmt|;
comment|/* Applikation "lebt"? */
name|u_char
name|hw_config
decl_stmt|;
comment|/* Steckmodule? */
name|u_char
name|jmp_config
decl_stmt|;
comment|/* Karten-Jumper? */
name|u_char
name|ram_config
decl_stmt|;
comment|/* Karten-Speicher? */
comment|/* Offset 0x0010 -----------------------------------------------------------*/
name|char
name|niccy_ver
index|[
literal|0x0E
index|]
decl_stmt|;
comment|/* "NICCY V x.yyy\c" */
name|u_char
name|int_flg_pc
decl_stmt|;
comment|/* Will PC Interrupts? */
name|u_char
name|int_flg_nic
decl_stmt|;
comment|/* Will NICCY Interrupts? */
comment|/* Offset 0x0020 -----------------------------------------------------------*/
name|u_short
name|buf_ptr
index|[
literal|8
index|]
decl_stmt|;
comment|/* Pointer to aux. buf. ... */
comment|/* Offset 0x0030 -----------------------------------------------------------*/
name|u_short
name|buf_len
index|[
literal|8
index|]
decl_stmt|;
comment|/* Size of aux. buf. ... */
comment|/* Offset 0x0040 -----------------------------------------------------------*/
comment|/* 0x40 Bytes fr die */
comment|/* frei verfgbar */
name|u_char
name|old_flg
index|[
literal|8
index|]
decl_stmt|;
comment|/* Messages in MBX i */
name|u_char
name|irq_level
decl_stmt|;
comment|/* welcher IRQ (als Bitmaske */
name|u_char
name|res
index|[
literal|7
index|]
decl_stmt|;
comment|/* FREI */
comment|/* Offset 0x0050 -----------------------------------------------------------*/
name|u_char
name|api_area_int_nr
decl_stmt|;
comment|/*SW-Int des API wenn API_ACTIVE*/
name|u_char
name|api_area_PLCI
index|[
literal|2
index|]
decl_stmt|;
comment|/* PLCI whrend ApiManufacturer */
name|u_char
name|capi_version
index|[
literal|6
index|]
decl_stmt|;
comment|/* Versionsnummer der CAPI */
name|u_char
name|api_area
index|[
literal|0x27
index|]
decl_stmt|;
comment|/* FREI */
comment|/* Offset 0x0080 -----------------------------------------------------------*/
name|u_char
name|api_active
decl_stmt|;
comment|/* Flag ob CAPI aktiv ist */
name|u_char
name|ext_hw_config
decl_stmt|;
comment|/* Bit 0: UART 16550 */
comment|/* Bit 1..7: reserved */
name|u_char
name|dpr_hw_id
index|[
literal|0x0E
index|]
decl_stmt|;
comment|/* Hardware ID */
comment|/* Offset 0x0090 -----------------------------------------------------------*/
name|u_char
name|dpr_listen_req
decl_stmt|;
comment|/* Anzahl Listen Request's */
name|u_char
name|dpr_state_b1
decl_stmt|;
comment|/* state B1 channel */
comment|/* 0x00 : channel ist frei */
comment|/* 0x01 : Verbindungsaufb. Req */
comment|/* 0x02 : Verbindungsaufb. Act */
comment|/* 0x03 : Verbindung besteht */
comment|/* 0x04 : eintreffender Ruf */
comment|/* 0x05 : Verbindung angenommen */
comment|/* 0x06 : Verbindungsabb. Req */
comment|/* 0x07 : Verbindungsabb. laeuft*/
comment|/* 0x08 : Verbindung getrennt */
name|u_char
name|dpr_state_b2
decl_stmt|;
comment|/* state B2 channel (siehe oben)*/
name|u_char
name|dpr_state_ic1
decl_stmt|;
comment|/* state of Intercomm-Channel */
name|u_char
name|dpr_state_ic2
decl_stmt|;
comment|/* ----------- " -------------- */
name|u_char
name|state_res
index|[
literal|0x04
index|]
decl_stmt|;
name|u_char
name|dpr_si_b1
decl_stmt|;
comment|/* Service Indicator auf B1 */
name|u_char
name|dpr_si_b2
decl_stmt|;
comment|/* Service Indicator auf B2 */
name|u_char
name|dpr_state_res_0
index|[
literal|0x05
index|]
decl_stmt|;
comment|/* Offset 0x00A0 -----------------------------------------------------------*/
name|u_char
name|dpr_state_hscx
decl_stmt|;
comment|/* state of HSCX */
name|u_char
name|dpr_state_itac
decl_stmt|;
comment|/* state of ITAC */
name|u_char
name|dpr_state_arcofi
decl_stmt|;
comment|/* state of ARCOFI */
name|u_char
name|dpr_state_modem
decl_stmt|;
comment|/* state of Aufsteckmodem */
name|u_char
name|dpr_state_com
decl_stmt|;
comment|/* state of COM */
name|u_char
name|dpr_state_res
index|[
literal|0x0B
index|]
decl_stmt|;
comment|/* Offset 0x00B0 -----------------------------------------------------------*/
name|u_char
name|dpr_state_ia_tel
decl_stmt|;
comment|/* state of internal Appl. */
name|u_char
name|dpr_state_ia_com
decl_stmt|;
comment|/* state of internal Appl. */
name|u_char
name|dpr_state_ia_mod
decl_stmt|;
comment|/* state of internal Appl. */
name|u_char
name|dpr_state_res_1
index|[
literal|0x0D
index|]
decl_stmt|;
comment|/* Offset 0x00C0 -----------------------------------------------------------*/
name|u_char
name|dpr_state_dcp
index|[
literal|0x10
index|]
decl_stmt|;
comment|/* state of D-channel Prot */
comment|/* Offset 0x00D0 -----------------------------------------------------------*/
name|u_char
name|reserved
index|[
literal|0x130
index|]
decl_stmt|;
comment|/* Offset 0x0200 -----------------------------------------------------------*/
name|mbx_type
name|dpr_mbx
index|[
literal|8
index|]
decl_stmt|;
comment|/* the mailboxes ... */
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

