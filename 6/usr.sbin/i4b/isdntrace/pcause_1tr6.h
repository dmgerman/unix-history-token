begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1997, 1999 Hellmuth Michaelis. All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *---------------------------------------------------------------------------  *  *	pcause1tr6.h - 1TR6 causes definitions  *	--------------------------------------  *  *	$Id: pcause_1tr6.h,v 1.5 1999/12/13 21:25:26 hm Exp $  *  * $FreeBSD$  *  *	last edit-date: [Mon Dec 13 21:56:10 1999]  *  *---------------------------------------------------------------------------*/
end_comment

begin_function_decl
name|char
modifier|*
name|print_cause_1tr6
parameter_list|(
name|unsigned
name|char
name|code
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* 1TR6 protocol causes */
end_comment

begin_define
define|#
directive|define
name|CAUSE_1TR6_SHUTDN
value|0x00
end_define

begin_comment
comment|/* normal D-channel shutdown */
end_comment

begin_define
define|#
directive|define
name|CAUSE_1TR6_ICRV
value|0x01
end_define

begin_comment
comment|/* invalid call reference value */
end_comment

begin_define
define|#
directive|define
name|CAUSE_1TR6_BSNI
value|0x03
end_define

begin_comment
comment|/* bearer service not implemented */
end_comment

begin_define
define|#
directive|define
name|CAUSE_1TR6_CIDNE
value|0x07
end_define

begin_comment
comment|/* call identity does not exist */
end_comment

begin_define
define|#
directive|define
name|CAUSE_1TR6_CIIU
value|0x08
end_define

begin_comment
comment|/* call identity in use */
end_comment

begin_define
define|#
directive|define
name|CAUSE_1TR6_NCA
value|0x0A
end_define

begin_comment
comment|/* no channel available */
end_comment

begin_define
define|#
directive|define
name|CAUSE_1TR6_RFNI
value|0x10
end_define

begin_comment
comment|/* requested facility not implemented */
end_comment

begin_define
define|#
directive|define
name|CAUSE_1TR6_RFNS
value|0x11
end_define

begin_comment
comment|/* requested facility not subscribed */
end_comment

begin_define
define|#
directive|define
name|CAUSE_1TR6_OCB
value|0x20
end_define

begin_comment
comment|/* outgoing calls barred */
end_comment

begin_define
define|#
directive|define
name|CAUSE_1TR6_UAB
value|0x21
end_define

begin_comment
comment|/* user access busy */
end_comment

begin_define
define|#
directive|define
name|CAUSE_1TR6_NECUG
value|0x22
end_define

begin_comment
comment|/* non existent CUG */
end_comment

begin_define
define|#
directive|define
name|CAUSE_1TR6_NECUG1
value|0x23
end_define

begin_comment
comment|/* non existent CUG */
end_comment

begin_define
define|#
directive|define
name|CAUSE_1TR6_SPV
value|0x25
end_define

begin_comment
comment|/* kommunikationsbeziehung als SPV nicht erlaubt */
end_comment

begin_define
define|#
directive|define
name|CAUSE_1TR6_DNO
value|0x35
end_define

begin_comment
comment|/* destination not obtainable */
end_comment

begin_define
define|#
directive|define
name|CAUSE_1TR6_NC
value|0x38
end_define

begin_comment
comment|/* number changed */
end_comment

begin_define
define|#
directive|define
name|CAUSE_1TR6_OOO
value|0x39
end_define

begin_comment
comment|/* out of order */
end_comment

begin_define
define|#
directive|define
name|CAUSE_1TR6_NUR
value|0x3A
end_define

begin_comment
comment|/* no user responding */
end_comment

begin_define
define|#
directive|define
name|CAUSE_1TR6_UB
value|0x3B
end_define

begin_comment
comment|/* user busy */
end_comment

begin_define
define|#
directive|define
name|CAUSE_1TR6_ICB
value|0x3D
end_define

begin_comment
comment|/* incoming calls barred */
end_comment

begin_define
define|#
directive|define
name|CAUSE_1TR6_CR
value|0x3E
end_define

begin_comment
comment|/* call rejected */
end_comment

begin_define
define|#
directive|define
name|CAUSE_1TR6_NCO
value|0x59
end_define

begin_comment
comment|/* network congestion */
end_comment

begin_define
define|#
directive|define
name|CAUSE_1TR6_RUI
value|0x5A
end_define

begin_comment
comment|/* remote user initiated */
end_comment

begin_define
define|#
directive|define
name|CAUSE_1TR6_LPE
value|0x70
end_define

begin_comment
comment|/* local procedure error */
end_comment

begin_define
define|#
directive|define
name|CAUSE_1TR6_RPE
value|0x71
end_define

begin_comment
comment|/* remote procedure error */
end_comment

begin_define
define|#
directive|define
name|CAUSE_1TR6_RUS
value|0x72
end_define

begin_comment
comment|/* remote user suspended */
end_comment

begin_define
define|#
directive|define
name|CAUSE_1TR6_RUR
value|0x73
end_define

begin_comment
comment|/* remote user resumed */
end_comment

begin_define
define|#
directive|define
name|CAUSE_1TR6_UIDL
value|0x7F
end_define

begin_comment
comment|/* user info discharded locally */
end_comment

begin_comment
comment|/* EOF */
end_comment

end_unit

