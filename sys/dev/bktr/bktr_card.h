begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_comment
comment|/*  * This is part of the Driver for Video Capture Cards (Frame grabbers)  * and TV Tuner cards using the Brooktree Bt848, Bt848A, Bt849A, Bt878, Bt879  * chipset.  * Copyright Roger Hardiman and Amancio Hasty.  *  * bktr_card : This deals with identifying TV cards.  *               trying to find the card make and model of card.  *               trying to find the type of tuner fitted.  *               reading the configuration EEPROM.  *               locating i2c devices.  *  */
end_comment

begin_comment
comment|/*  * 1. Redistributions of source code must retain the  * Copyright (c) 1997 Amancio Hasty, 1999 Roger Hardiman  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *      This product includes software developed by Amancio Hasty and  *      Roger Hardiman  * 4. The name of the author may not be used to endorse or promote products  *    derived from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED  * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE  * DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT,  * INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES  * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR  * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,  * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN  * ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  * POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_comment
comment|/*  * If probeCard() fails to detect the correct card on boot you can  * override it by setting adding the following option to your kernel config  *  options BKTR_OVERRIDE_CARD<card type>  *  eg options BKTR_OVERRIDE CARD=1  *  * or using the sysclt  hw.bt848.card  *  eg sysctl -w hw.bt848.card=1  *  * where<card type> is one of the following card defines.  */
end_comment

begin_define
define|#
directive|define
name|CARD_UNKNOWN
value|0
end_define

begin_define
define|#
directive|define
name|CARD_MIRO
value|1
end_define

begin_define
define|#
directive|define
name|CARD_HAUPPAUGE
value|2
end_define

begin_define
define|#
directive|define
name|CARD_STB
value|3
end_define

begin_define
define|#
directive|define
name|CARD_INTEL
value|4
end_define

begin_comment
comment|/* Also for VideoLogic Captivator PCI */
end_comment

begin_define
define|#
directive|define
name|CARD_IMS_TURBO
value|5
end_define

begin_define
define|#
directive|define
name|CARD_AVER_MEDIA
value|6
end_define

begin_define
define|#
directive|define
name|CARD_OSPREY
value|7
end_define

begin_define
define|#
directive|define
name|CARD_NEC_PK
value|8
end_define

begin_define
define|#
directive|define
name|CARD_IO_GV
value|9
end_define

begin_define
define|#
directive|define
name|CARD_FLYVIDEO
value|10
end_define

begin_define
define|#
directive|define
name|CARD_ZOLTRIX
value|11
end_define

begin_define
define|#
directive|define
name|CARD_KISS
value|12
end_define

begin_define
define|#
directive|define
name|CARD_VIDEO_HIGHWAY_XTREME
value|13
end_define

begin_define
define|#
directive|define
name|CARD_ASKEY_DYNALINK_MAGIC_TVIEW
value|14
end_define

begin_define
define|#
directive|define
name|CARD_LEADTEK
value|15
end_define

begin_define
define|#
directive|define
name|CARD_TERRATVPLUS
value|16
end_define

begin_define
define|#
directive|define
name|Bt848_MAX_CARD
value|17
end_define

begin_function_decl
name|int
name|signCard
parameter_list|(
name|bktr_ptr_t
name|bktr
parameter_list|,
name|int
name|offset
parameter_list|,
name|int
name|count
parameter_list|,
name|u_char
modifier|*
name|sig
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|probeCard
parameter_list|(
name|bktr_ptr_t
name|bktr
parameter_list|,
name|int
name|verbose
parameter_list|,
name|int
name|unit
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|writeEEProm
parameter_list|(
name|bktr_ptr_t
name|bktr
parameter_list|,
name|int
name|offset
parameter_list|,
name|int
name|count
parameter_list|,
name|u_char
modifier|*
name|data
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|readEEProm
parameter_list|(
name|bktr_ptr_t
name|bktr
parameter_list|,
name|int
name|offset
parameter_list|,
name|int
name|count
parameter_list|,
name|u_char
modifier|*
name|data
parameter_list|)
function_decl|;
end_function_decl

end_unit

