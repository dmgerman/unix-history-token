begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_decl_stmt
specifier|static
name|char
name|nicregh_id
index|[]
init|=
literal|"@(#)$FreeBSD$"
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*******************************************************************************  *  II - Version 0.1 $Revision: 1.1 $   $State: Exp $  *  * Copyright 1994 Dietmar Friede  *******************************************************************************  * Bug reports, patches, comments, suggestions should be sent to:  *  *	jkr@saarlink.de or jkrause@guug.de  *  *******************************************************************************  * $Log: niccyreg.h,v $  *  ******************************************************************************/
end_comment

begin_comment
comment|/*  * This file defines the NICCY 3008 Interface.  * Copyright Dr. Neuhaus GmbH, Hamburg and Dietmar Friede  * */
end_comment

begin_define
define|#
directive|define
name|MBX_MU
value|0
end_define

begin_define
define|#
directive|define
name|MBX_MD
value|1
end_define

begin_define
define|#
directive|define
name|MBX_DU
value|2
end_define

begin_define
define|#
directive|define
name|MBX_DD
value|3
end_define

begin_define
define|#
directive|define
name|MBX_B1U
value|4
end_define

begin_define
define|#
directive|define
name|MBX_B1D
value|5
end_define

begin_define
define|#
directive|define
name|MBX_B2U
value|6
end_define

begin_define
define|#
directive|define
name|MBX_B2D
value|7
end_define

begin_define
define|#
directive|define
name|MBX_xU
value|0x55
end_define

begin_define
define|#
directive|define
name|MBX_xD
value|0xAA
end_define

begin_comment
comment|/* -------------------------------------------------------------------- */
end_comment

begin_define
define|#
directive|define
name|MU_INIT_CNF
value|0x00
end_define

begin_define
define|#
directive|define
name|MU_INIT_IND
value|0x01
end_define

begin_define
define|#
directive|define
name|MU_RESET_CNF
value|0x02
end_define

begin_define
define|#
directive|define
name|MU_HANDSET_IND
value|0x03
end_define

begin_define
define|#
directive|define
name|MU_DNL_MOD_CNF
value|0x04
end_define

begin_comment
comment|/* reserved: 0x05 */
end_comment

begin_define
define|#
directive|define
name|MU_DNL_MOD_IND
value|0x06
end_define

begin_define
define|#
directive|define
name|MU_DISC_MOD_CNF
value|0x07
end_define

begin_define
define|#
directive|define
name|MU_LIST_MOD_CNF
value|0x08
end_define

begin_define
define|#
directive|define
name|MU_LIST_MOD_DATA
value|0x09
end_define

begin_comment
comment|/* reserved: 0x0A to 0x0B */
end_comment

begin_define
define|#
directive|define
name|MU_HW_CONFIG_CNF
value|0x0C
end_define

begin_define
define|#
directive|define
name|MU_HW_ID_CNF
value|0x0D
end_define

begin_define
define|#
directive|define
name|MU_SET_CLOCK_CNF
value|0x0E
end_define

begin_define
define|#
directive|define
name|MU_GET_CLOCK_CNF
value|0x0F
end_define

begin_define
define|#
directive|define
name|MU_ACT_IA_CNF
value|0x10
end_define

begin_define
define|#
directive|define
name|MU_ACT_IA_IND
value|0x11
end_define

begin_define
define|#
directive|define
name|MU_DEACT_IA_CNF
value|0x12
end_define

begin_define
define|#
directive|define
name|MU_DEACT_IA_IND
value|0x13
end_define

begin_define
define|#
directive|define
name|MU_POLL_CNF
value|0x14
end_define

begin_define
define|#
directive|define
name|MU_POLL_IND
value|0x15
end_define

begin_comment
comment|/* reserved: 0x16 to 0x1D */
end_comment

begin_define
define|#
directive|define
name|MU_MANUFACT_CNF
value|0x1E
end_define

begin_define
define|#
directive|define
name|MU_MANUFACT_IND
value|0x1F
end_define

begin_comment
comment|/*---------------------------------------------------------------------------*/
end_comment

begin_define
define|#
directive|define
name|MD_INIT_REQ
value|0x20
end_define

begin_define
define|#
directive|define
name|MD_INIT_RSP
value|0x21
end_define

begin_define
define|#
directive|define
name|MD_RESET_REQ
value|0x22
end_define

begin_define
define|#
directive|define
name|MD_HANDSET_RSP
value|0x23
end_define

begin_define
define|#
directive|define
name|MD_DNL_MOD_REQ
value|0x24
end_define

begin_define
define|#
directive|define
name|MD_DNL_MOD_DATA
value|0x25
end_define

begin_define
define|#
directive|define
name|MD_DNL_MOD_RSP
value|0x26
end_define

begin_define
define|#
directive|define
name|MD_DISC_MOD_REQ
value|0x27
end_define

begin_define
define|#
directive|define
name|MD_LIST_MOD_REQ
value|0x28
end_define

begin_comment
comment|/* reserved: 0x29 to 0x2B */
end_comment

begin_define
define|#
directive|define
name|MD_HW_CONFIG_REQ
value|0x2C
end_define

begin_define
define|#
directive|define
name|MD_HW_ID_REQ
value|0x2D
end_define

begin_define
define|#
directive|define
name|MD_SET_CLOCK_REQ
value|0x2E
end_define

begin_define
define|#
directive|define
name|MD_GET_CLOCK_REQ
value|0x2F
end_define

begin_define
define|#
directive|define
name|MD_ACT_IA_REQ
value|0x30
end_define

begin_define
define|#
directive|define
name|MD_ACT_IA_RSP
value|0x31
end_define

begin_define
define|#
directive|define
name|MD_DEACT_IA_REQ
value|0x32
end_define

begin_define
define|#
directive|define
name|MD_DEACT_IA_RSP
value|0x33
end_define

begin_define
define|#
directive|define
name|MD_POLL_REQ
value|0x34
end_define

begin_define
define|#
directive|define
name|MD_POLL_RSP
value|0x35
end_define

begin_define
define|#
directive|define
name|MD_STATE_IND
value|0x37
end_define

begin_define
define|#
directive|define
name|MD_MANUFACT_REQ
value|0x3E
end_define

begin_define
define|#
directive|define
name|MD_MANUFACT_RSP
value|0x3F
end_define

begin_comment
comment|/*---------------------------------------------------------------------------*/
end_comment

begin_define
define|#
directive|define
name|DU_CONN_CNF
value|0x40
end_define

begin_define
define|#
directive|define
name|DU_CONN_IND
value|0x41
end_define

begin_define
define|#
directive|define
name|DU_CONN_ACT_IND
value|0x42
end_define

begin_define
define|#
directive|define
name|DU_DISC_CNF
value|0x43
end_define

begin_define
define|#
directive|define
name|DU_DISC_IND
value|0x44
end_define

begin_define
define|#
directive|define
name|DU_DATA_CNF
value|0x45
end_define

begin_define
define|#
directive|define
name|DU_DATA_IND
value|0x46
end_define

begin_define
define|#
directive|define
name|DU_LISTEN_CNF
value|0x47
end_define

begin_define
define|#
directive|define
name|DU_GET_PAR_CNF
value|0x48
end_define

begin_define
define|#
directive|define
name|DU_INFO_CNF
value|0x49
end_define

begin_define
define|#
directive|define
name|DU_INFO_IND
value|0x4A
end_define

begin_define
define|#
directive|define
name|DU_CONN_INFO_CNF
value|0x4B
end_define

begin_define
define|#
directive|define
name|DU_REL_PLCI_CNF
value|0x4C
end_define

begin_comment
comment|/* reserved: 0x4C to 0x5E */
end_comment

begin_define
define|#
directive|define
name|DU_STR_NOT_COMP
value|0x5F
end_define

begin_comment
comment|/*---------------------------------------------------------------------------*/
end_comment

begin_define
define|#
directive|define
name|DD_CONN_REQ
value|0x60
end_define

begin_define
define|#
directive|define
name|DD_CONN_RSP
value|0x61
end_define

begin_define
define|#
directive|define
name|DD_CONN_ACT_RSP
value|0x62
end_define

begin_define
define|#
directive|define
name|DD_DISC_REQ
value|0x63
end_define

begin_define
define|#
directive|define
name|DD_DISC_RSP
value|0x64
end_define

begin_define
define|#
directive|define
name|DD_DATA_REQ
value|0x65
end_define

begin_define
define|#
directive|define
name|DD_DATA_RSP
value|0x66
end_define

begin_define
define|#
directive|define
name|DD_LISTEN_REQ
value|0x67
end_define

begin_define
define|#
directive|define
name|DD_GET_PAR_REQ
value|0x68
end_define

begin_define
define|#
directive|define
name|DD_INFO_REQ
value|0x69
end_define

begin_define
define|#
directive|define
name|DD_INFO_RSP
value|0x6A
end_define

begin_define
define|#
directive|define
name|DD_CONN_INFO_REQ
value|0x6B
end_define

begin_define
define|#
directive|define
name|DD_REL_PLCI_REQ
value|0x6C
end_define

begin_comment
comment|/*---------------------------------------------------------------------------*/
end_comment

begin_define
define|#
directive|define
name|BD_SEL_PROT_REQ
value|0xA0
end_define

begin_define
define|#
directive|define
name|BD_LIST_B3_REQ
value|0xA1
end_define

begin_define
define|#
directive|define
name|BD_CONN_B3_REQ
value|0xA2
end_define

begin_define
define|#
directive|define
name|BD_CONN_B3_RSP
value|0xA3
end_define

begin_define
define|#
directive|define
name|BD_C_B3_ACT_RSP
value|0xA4
end_define

begin_define
define|#
directive|define
name|BD_DISC_B3_REQ
value|0xA5
end_define

begin_define
define|#
directive|define
name|BD_DISC_B3_RSP
value|0xA6
end_define

begin_define
define|#
directive|define
name|BD_GET_P_B3_REQ
value|0xA7
end_define

begin_define
define|#
directive|define
name|BD_DATA_B3_REQ
value|0xA8
end_define

begin_define
define|#
directive|define
name|BD_DATA_B3_RSP
value|0xA9
end_define

begin_define
define|#
directive|define
name|BD_RESET_B3_REQ
value|0xAA
end_define

begin_define
define|#
directive|define
name|BD_RESET_B3_RSP
value|0xAB
end_define

begin_comment
comment|/*---------------------------------------------------------------------------*/
end_comment

begin_define
define|#
directive|define
name|NICCY_DEBUG
value|_IOWR('N',1,dbg_type)
end_define

begin_define
define|#
directive|define
name|NICCY_RESET
value|_IOWR('N',2,int)
end_define

begin_define
define|#
directive|define
name|NICCY_LOAD
value|_IOWR('N',3,struct head)
end_define

begin_define
define|#
directive|define
name|NICCY_SET_CLOCK
value|_IOWR('N',4,time_str_t)
end_define

begin_define
define|#
directive|define
name|NICCY_SPY
value|_IOWR('N',5,int)
end_define

begin_struct
struct|struct
name|head
block|{
name|u_long
name|len
decl_stmt|;
name|u_long
name|sig
decl_stmt|;
name|char
name|nam
index|[
literal|8
index|]
decl_stmt|;
name|char
name|ver
index|[
literal|5
index|]
decl_stmt|;
name|u_char
name|typ
decl_stmt|;
name|u_short
name|status
decl_stmt|;
name|u_long
name|d_len
decl_stmt|;
name|u_char
modifier|*
name|data
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|char
name|time_str_t
index|[
literal|14
index|]
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|u_char
name|dbg_type
index|[
literal|10000
index|]
typedef|;
end_typedef

end_unit

