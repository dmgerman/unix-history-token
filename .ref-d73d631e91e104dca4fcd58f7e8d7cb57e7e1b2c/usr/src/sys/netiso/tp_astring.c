begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $Header$ */
end_comment

begin_comment
comment|/* $Source$ */
end_comment

begin_comment
comment|/*	@(#)tp_astring.c	7.3 (Berkeley) %G% */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_NFILE
end_ifndef

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_endif
endif|#
directive|endif
endif|_NFILE
end_endif

begin_decl_stmt
name|char
modifier|*
name|tp_sstring
index|[]
init|=
block|{
literal|"ST_ERROR(0x0)"
block|,
literal|"TP_CLOSED(0x1)"
block|,
literal|"TP_CRSENT(0x2)"
block|,
literal|"TP_AKWAIT(0x3)"
block|,
literal|"TP_OPEN(0x4)"
block|,
literal|"TP_CLOSING(0x5)"
block|,
literal|"TP_REFWAIT(0x6)"
block|,
literal|"TP_LISTENING(0x7)"
block|,
literal|"TP_CONFIRMING(0x8)"
block|, }
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|tp_estring
index|[]
init|=
block|{
literal|"TM_inact(0x0)"
block|,
literal|"TM_retrans(0x1)"
block|,
literal|"TM_sendack(0x2)"
block|,
literal|"TM_notused(0x3)"
block|,
literal|"TM_reference(0x4)"
block|,
literal|"TM_data_retrans(0x5)"
block|,
literal|"ER_TPDU(0x6)"
block|,
literal|"CR_TPDU(0x7)"
block|,
literal|"DR_TPDU(0x8)"
block|,
literal|"DC_TPDU(0x9)"
block|,
literal|"CC_TPDU(0xa)"
block|,
literal|"AK_TPDU(0xb)"
block|,
literal|"DT_TPDU(0xc)"
block|,
literal|"XPD_TPDU(0xd)"
block|,
literal|"XAK_TPDU(0xe)"
block|,
literal|"T_CONN_req(0xf)"
block|,
literal|"T_DISC_req(0x10)"
block|,
literal|"T_LISTEN_req(0x11)"
block|,
literal|"T_DATA_req(0x12)"
block|,
literal|"T_XPD_req(0x13)"
block|,
literal|"T_USR_rcvd(0x14)"
block|,
literal|"T_USR_Xrcvd(0x15)"
block|,
literal|"T_DETACH(0x16)"
block|,
literal|"T_NETRESET(0x17)"
block|,
literal|"T_ACPT_req(0x18)"
block|, }
decl_stmt|;
end_decl_stmt

end_unit

