begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  *	    Written by Toshiharu OHNO (tony-o@iij.ad.jp)  *  *   Copyright (C) 1993, Internet Initiative Japan, Inc. All rights reserverd.  *  * Redistribution and use in source and binary forms are permitted  * provided that the above copyright notice and this paragraph are  * duplicated in all such forms and that any documentation,  * advertising materials, and other materials related to such  * distribution and use acknowledge that the software was developed  * by the Internet Initiative Japan.  The name of the  * IIJ may not be used to endorse or promote products derived  * from this software without specific prior written permission.  * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED  * WARRANTIES OF MERCHANTIBILITY AND FITNESS FOR A PARTICULAR PURPOSE.  *  * $Id: hdlc.h,v 1.13 1997/12/03 10:23:48 brian Exp $  *  *	TODO:  */
end_comment

begin_comment
comment|/*  *  Definition for Async HDLC  */
end_comment

begin_define
define|#
directive|define
name|HDLC_SYN
value|0x7e
end_define

begin_comment
comment|/* SYNC character */
end_comment

begin_define
define|#
directive|define
name|HDLC_ESC
value|0x7d
end_define

begin_comment
comment|/* Escape character */
end_comment

begin_define
define|#
directive|define
name|HDLC_XOR
value|0x20
end_define

begin_comment
comment|/* Modifier value */
end_comment

begin_define
define|#
directive|define
name|HDLC_ADDR
value|0xff
end_define

begin_define
define|#
directive|define
name|HDLC_UI
value|0x03
end_define

begin_comment
comment|/*  *  Definition for HDLC Frame Check Sequence  */
end_comment

begin_define
define|#
directive|define
name|INITFCS
value|0xffff
end_define

begin_comment
comment|/* Initial value for FCS computation */
end_comment

begin_define
define|#
directive|define
name|GOODFCS
value|0xf0b8
end_define

begin_comment
comment|/* Good FCS value */
end_comment

begin_define
define|#
directive|define
name|DEF_MRU
value|1500
end_define

begin_define
define|#
directive|define
name|MAX_MRU
value|2048
end_define

begin_define
define|#
directive|define
name|MIN_MRU
value|296
end_define

begin_define
define|#
directive|define
name|DEF_MTU
value|0
end_define

begin_comment
comment|/* whatever peer says */
end_comment

begin_define
define|#
directive|define
name|MAX_MTU
value|2048
end_define

begin_define
define|#
directive|define
name|MIN_MTU
value|296
end_define

begin_comment
comment|/*  *  Output priority  */
end_comment

begin_comment
comment|/* PRI_NORMAL and PRI_FAST have meaning only on the IP queue.  * All IP frames have the same priority once they are compressed.  * IP frames stay on the IP queue till they can be sent on the  * link. They are compressed at that time. */
end_comment

begin_define
define|#
directive|define
name|PRI_NORMAL
value|0
end_define

begin_comment
comment|/* Normal priority */
end_comment

begin_define
define|#
directive|define
name|PRI_FAST
value|1
end_define

begin_comment
comment|/* Fast (interractive) */
end_comment

begin_define
define|#
directive|define
name|PRI_LINK
value|1
end_define

begin_comment
comment|/* Urgent (LQR packets) */
end_comment

begin_decl_stmt
specifier|extern
name|u_char
name|EscMap
index|[
literal|33
index|]
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|void
name|HdlcInit
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|HdlcErrorCheck
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|HdlcInput
parameter_list|(
name|struct
name|mbuf
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|HdlcOutput
parameter_list|(
name|int
parameter_list|,
name|u_short
parameter_list|,
name|struct
name|mbuf
modifier|*
name|bp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|u_short
name|HdlcFcs
parameter_list|(
name|u_short
parameter_list|,
name|u_char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|ReportHdlcStatus
parameter_list|(
name|struct
name|cmdargs
specifier|const
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|ReportProtStatus
parameter_list|(
name|struct
name|cmdargs
specifier|const
modifier|*
parameter_list|)
function_decl|;
end_function_decl

end_unit

