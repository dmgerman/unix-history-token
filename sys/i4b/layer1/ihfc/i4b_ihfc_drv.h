begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2000 Hans Petter Selasky. All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *---------------------------------------------------------------------------  *  *	i4b_ihfc_drv.h - include file for the HFC-1/S/SP driver  *	-------------------------------------------------------  *  *	last edit-date: [Wed Jul 19 09:40:55 2000]  *  *	$Id: i4b_ihfc_drv.h,v 1.7 2000/09/19 13:50:36 hm Exp $  *  * $FreeBSD$  *  *---------------------------------------------------------------------------*/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|I4B_IHFC_DRV_H_
end_ifndef

begin_define
define|#
directive|define
name|I4B_IHFC_DRV_H_
end_define

begin_comment
comment|/*---------------------------------------------------------------------------*  *	Ramptables related fifo					(HFC-1/S/SP)  *  *	The HFC-SP chip only uses ihfc_xxx[2] values for D-channel!  *	NOTE: These tables are not used anymore.  *---------------------------------------------------------------------------*  *   *             w - write, r - read:   D1_w  D1_r  B1_w  B1_r  B2_w  B2_r  * const u_char ihfc_readtable[6]  = {0xa6, 0xa7, 0xbc, 0xbd, 0xbe, 0xbf};  * const u_char ihfc_writetable[6] = {0x96, 0x97, 0xac, 0xad, 0xae, 0xaf};  * const u_char ihfc_f1inctable[6] = {0x92, 0x93, 0xa8, 0xa9, 0xaa, 0xab};	  * const u_char ihfc_f2inctable[6] = {0xa2, 0xa3, 0xb8, 0xb9, 0xba, 0xbb};  *   * const	struct { u_char z1L, z1H, z2L, z2H, f1, f2, dummy; }   * 	ihfc_countertable[6] = {  * 	{0x90, 0x94, 0x98, 0x9c, 0x9a, 0x9e, 0x00},	D1_w  *	{0x91, 0x95, 0x99, 0x9d, 0x9b, 0x9f, 0x00},	D1_r  * 	{0x80, 0x84, 0x88, 0x8c, 0xb0, 0xb4, 0x00},	B1_w  * 	{0x81, 0x85, 0x89, 0x8d, 0xb1, 0xb5, 0x00},	B1_r  * 	{0x82, 0x86, 0x8a, 0x8e, 0xb2, 0xb6, 0x00},	B2_w  * 	{0x83, 0x87, 0x8b, 0x8f, 0xb3, 0xb7, 0x00}	B2_r  * 	};  *---------------------------------------------------------------------------*/
end_comment

begin_comment
comment|/*---------------------------------------------------------------------------*  *	Ramptables related to configuration			(HFC-1/S/SP)  *  *	NOTE: Write registers only  *---------------------------------------------------------------------------*/
end_comment

begin_decl_stmt
specifier|const
name|u_char
name|ihfc_configtable
index|[
literal|11
index|]
init|=
block|{
literal|0x18
block|,
literal|0x19
block|,
literal|0x1a
block|,
comment|/* cirm, ctmt, int_m1		*/
literal|0x1b
block|,
literal|0x2e
block|,
literal|0x37
block|,
comment|/* int_m2, mst_mode, clkdel	*/
literal|0x31
block|,
literal|0x2f
block|,
literal|0x32
block|,
comment|/* sctrl, connect, test/sctrl_e */
literal|0x33
block|,
literal|0x00
comment|/* sctrl_r			*/
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|u_char
name|isac_configtable
index|[
literal|9
index|]
init|=
block|{
literal|0x39
block|,
literal|0x30
block|,
literal|0x3b
block|,
comment|/* adf2, spcr, sqxr	*/
literal|0x38
block|,
literal|0x37
block|,
literal|0x22
block|,
comment|/* adf1, stcr, mode	*/
literal|0x20
block|,
literal|0x2b
block|,
literal|0x00
comment|/* mask, star2		*/
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*---------------------------------------------------------------------------*  *	Ramptables related to statemachine			(HFC-1/S/SP)  *  * state:  *	0 = deactivated  * 	1 = pending  *	2 = syncronized  *	3 = activated  *	4 = error  *	5 = reset  *     -1 = illegal  *---------------------------------------------------------------------------*/
end_comment

begin_struct
specifier|const
struct|struct
name|ihfc_FSMtable
block|{
name|u_char
name|state
decl_stmt|,
modifier|*
name|string
decl_stmt|;
block|}
name|ihfc_TEtable
index|[
literal|16
index|]
init|=
comment|/* HFC-S/SP	- TE */
block|{
block|{
literal|0x05
block|,
literal|"Reset"
block|}
block|,
block|{
literal|0xff
block|,
literal|0
block|}
block|,
block|{
literal|0x01
block|,
literal|"Sensing"
block|}
block|,
block|{
literal|0x00
block|,
literal|"Deactivated"
block|}
block|,
block|{
literal|0x01
block|,
literal|"Awaiting signal"
block|}
block|,
block|{
literal|0x01
block|,
literal|"Identifying input"
block|}
block|,
block|{
literal|0x02
block|,
literal|"Syncronized"
block|}
block|,
block|{
literal|0x03
block|,
literal|"Activated"
block|}
block|,
block|{
literal|0x04
block|,
literal|"Lost framing"
block|}
block|,
block|{
literal|0xff
block|,
literal|0
block|}
block|,
block|{
literal|0xff
block|,
literal|0
block|}
block|,
block|{
literal|0xff
block|,
literal|0
block|}
block|,
block|{
literal|0xff
block|,
literal|0
block|}
block|,
block|{
literal|0xff
block|,
literal|0
block|}
block|,
block|{
literal|0xff
block|,
literal|0
block|}
block|,
block|{
literal|0xff
block|,
literal|0
block|}
block|}
struct|,
name|ihfc_NTtable
index|[
literal|16
index|]
init|=
comment|/* HFC-S/SP	- NT */
block|{
block|{
literal|0x05
block|,
literal|"Reset"
block|}
block|,
block|{
literal|0x00
block|,
literal|"Deactive"
block|}
block|,
block|{
literal|0x02
block|,
literal|"Pending activation"
block|}
block|,
block|{
literal|0x03
block|,
literal|"Active"
block|}
block|,
block|{
literal|0x01
block|,
literal|"Pending deactivation"
block|}
block|,
block|{
literal|0xff
block|,
literal|0
block|}
block|,
block|{
literal|0xff
block|,
literal|0
block|}
block|,
block|{
literal|0xff
block|,
literal|0
block|}
block|,
block|{
literal|0xff
block|,
literal|0
block|}
block|,
block|{
literal|0xff
block|,
literal|0
block|}
block|,
block|{
literal|0xff
block|,
literal|0
block|}
block|,
block|{
literal|0xff
block|,
literal|0
block|}
block|,
block|{
literal|0xff
block|,
literal|0
block|}
block|,
block|{
literal|0xff
block|,
literal|0
block|}
block|,
block|{
literal|0xff
block|,
literal|0
block|}
block|,
block|{
literal|0xff
block|,
literal|0
block|}
block|}
struct|,
name|ihfc_TEtable2
index|[
literal|16
index|]
init|=
comment|/* HFC-1/ISAC 	- TE */
block|{
block|{
literal|0x00
block|,
literal|"Deactivate request"
block|}
block|,
block|{
literal|0xff
block|,
literal|0
block|}
block|,
block|{
literal|0xff
block|,
literal|0
block|}
block|,
block|{
literal|0xff
block|,
literal|0
block|}
block|,
block|{
literal|0x01
block|,
literal|"Level detected"
block|}
block|,
block|{
literal|0xff
block|,
literal|0
block|}
block|,
block|{
literal|0x04
block|,
literal|"Error indication"
block|}
block|,
block|{
literal|0x00
block|,
literal|"Power-up"
block|}
block|,
block|{
literal|0x02
block|,
literal|"Activate request downstream"
block|}
block|,
block|{
literal|0xff
block|,
literal|0
block|}
block|,
block|{
literal|0x00
block|,
literal|"Test indication"
block|}
block|,
block|{
literal|0x00
block|,
literal|"Awake test indication"
block|}
block|,
block|{
literal|0x03
block|,
literal|"Activate ind. with priority class 8"
block|}
block|,
block|{
literal|0x03
block|,
literal|"Activate ind. with priority class 10"
block|}
block|,
block|{
literal|0xff
block|,
literal|0
block|}
block|,
block|{
literal|0x00
block|,
literal|"Deactivate indication downstream"
block|}
block|}
struct|;
end_struct

begin_comment
comment|/*---------------------------------------------------------------------------*  *	Ramptable related to ISAC EXIR				(HFC-1)  *  *	cmd: command to execute, if any.  *  *---------------------------------------------------------------------------*/
end_comment

begin_struct
specifier|const
struct|struct
name|ihfc_EXIRtable
block|{
name|u_char
name|cmd
decl_stmt|,
modifier|*
name|string
decl_stmt|;
block|}
name|ihfc_EXIRtable
index|[
literal|8
index|]
init|=
block|{
block|{
literal|0x00
block|,
literal|"Watchdog Timer Overflow"
block|}
block|,
block|{
literal|0x00
block|,
literal|"Subscriber Awake"
block|}
block|,
block|{
literal|0x00
block|,
literal|"Monitor Status"
block|}
block|,
block|{
literal|0x00
block|,
literal|"Rx Sync Xfer Overflow"
block|}
block|,
block|{
literal|0xc0
block|,
literal|"Rx Frame Overflow"
block|}
block|,
comment|/* RMC + RRES */
block|{
literal|0x00
block|,
literal|"Protocol Error"
block|}
block|,
block|{
literal|0x01
block|,
literal|"Tx Data Underrun"
block|}
block|,
comment|/* XRES */
block|{
literal|0x01
block|,
literal|"Tx Message Repeat"
block|}
block|,
comment|/* XRES */
block|}
struct|;
end_struct

begin_comment
comment|/*---------------------------------------------------------------------------*  *	Ramptables related to S/Q - channel			(HFC-1/S/SP)  *  *	From TE's viewpoint:  *	Q: commands to NT  *	S: indications from NT  *  *	From NT's viewpoint:  *	Q: indications from TE  *	S: commands to TE  *	  *	cmd: not used  *---------------------------------------------------------------------------*/
end_comment

begin_struct
specifier|const
struct|struct
name|ihfc_SQtable
block|{
name|u_char
name|cmd
decl_stmt|,
modifier|*
name|string
decl_stmt|;
block|}
name|ihfc_Qtable
index|[
literal|16
index|]
init|=
block|{
block|{
literal|0x00
block|,
literal|"Loss of Power indication"
block|}
block|,
block|{
literal|0x00
block|,
literal|"ST request"
block|}
block|,
block|{
literal|0x00
block|,
literal|0
block|}
block|,
block|{
literal|0x00
block|,
literal|"LoopBack request (B1/B2)"
block|}
block|,
block|{
literal|0x00
block|,
literal|0
block|}
block|,
block|{
literal|0x00
block|,
literal|0
block|}
block|,
block|{
literal|0x00
block|,
literal|0
block|}
block|,
block|{
literal|0x00
block|,
literal|"LoopBack request (B1)"
block|}
block|,
block|{
literal|0x00
block|,
literal|0
block|}
block|,
block|{
literal|0x00
block|,
literal|0
block|}
block|,
block|{
literal|0x00
block|,
literal|0
block|}
block|,
block|{
literal|0x00
block|,
literal|"LoopBack request (B2)"
block|}
block|,
block|{
literal|0x00
block|,
literal|"V-DCE slave mode"
block|}
block|,
block|{
literal|0x00
block|,
literal|"V-DTE slave mode"
block|}
block|,
block|{
literal|0x00
block|,
literal|0
block|}
block|,
block|{
literal|0x00
block|,
literal|"Idle"
block|}
block|}
struct|,
name|ihfc_Stable
index|[
literal|16
index|]
init|=
block|{
block|{
literal|0x00
block|,
literal|"Idle"
block|}
block|,
block|{
literal|0x00
block|,
literal|"ST Fail"
block|}
block|,
block|{
literal|0x00
block|,
literal|"ST Pass"
block|}
block|,
block|{
literal|0x00
block|,
literal|"Disruptive Operation Indication"
block|}
block|,
block|{
literal|0x00
block|,
literal|"DTSE-OUT"
block|}
block|,
block|{
literal|0x00
block|,
literal|"V-DCE master mode"
block|}
block|,
block|{
literal|0x00
block|,
literal|"ST Indication"
block|}
block|,
block|{
literal|0x00
block|,
literal|"DTSE-IN"
block|}
block|,
block|{
literal|0x00
block|,
literal|"LoopBack indication (B1/B2)"
block|}
block|,
block|{
literal|0x00
block|,
literal|"Loss of Received Signal indication"
block|}
block|,
block|{
literal|0x00
block|,
literal|"LoopBack indication (B2)"
block|}
block|,
block|{
literal|0x00
block|,
literal|"DTSE-IN and OUT"
block|}
block|,
block|{
literal|0x00
block|,
literal|"LoopBack indication (B1)"
block|}
block|,
block|{
literal|0x00
block|,
literal|"Loss of power indication"
block|}
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* I4B_IHFC_DRV_H_ */
end_comment

end_unit

