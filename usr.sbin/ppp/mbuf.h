begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  *	    Written by Toshiharu OHNO (tony-o@iij.ad.jp)  *  *   Copyright (C) 1993, Internet Initiative Japan, Inc. All rights reserverd.  *  * Redistribution and use in source and binary forms are permitted  * provided that the above copyright notice and this paragraph are  * duplicated in all such forms and that any documentation,  * advertising materials, and other materials related to such  * distribution and use acknowledge that the software was developed  * by the Internet Initiative Japan.  The name of the  * IIJ may not be used to endorse or promote products derived  * from this software without specific prior written permission.  * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED  * WARRANTIES OF MERCHANTIBILITY AND FITNESS FOR A PARTICULAR PURPOSE.  *  * $Id: mbuf.h,v 1.8 1997/10/26 12:42:13 brian Exp $  *  *	TODO:  */
end_comment

begin_struct
struct|struct
name|mbuf
block|{
name|u_char
modifier|*
name|base
decl_stmt|;
comment|/* pointer to top of buffer space */
name|short
name|size
decl_stmt|;
comment|/* size allocated from base */
name|short
name|offset
decl_stmt|;
comment|/* offset to start position */
name|short
name|cnt
decl_stmt|;
comment|/* available byte count in buffer */
name|short
name|type
decl_stmt|;
name|struct
name|mbuf
modifier|*
name|next
decl_stmt|;
comment|/* link to next mbuf */
name|struct
name|mbuf
modifier|*
name|pnext
decl_stmt|;
comment|/* link to next packet */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|mqueue
block|{
name|struct
name|mbuf
modifier|*
name|top
decl_stmt|;
name|struct
name|mbuf
modifier|*
name|last
decl_stmt|;
name|int
name|qlen
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|NULLBUFF
value|((struct mbuf *)0)
end_define

begin_define
define|#
directive|define
name|MBUF_CTOP
parameter_list|(
name|bp
parameter_list|)
value|(bp->base + bp->offset)
end_define

begin_define
define|#
directive|define
name|MB_ASYNC
value|1
end_define

begin_define
define|#
directive|define
name|MB_FSM
value|2
end_define

begin_define
define|#
directive|define
name|MB_HDLCOUT
value|3
end_define

begin_define
define|#
directive|define
name|MB_IPIN
value|4
end_define

begin_define
define|#
directive|define
name|MB_ECHO
value|5
end_define

begin_define
define|#
directive|define
name|MB_LQR
value|6
end_define

begin_define
define|#
directive|define
name|MB_MODEM
value|7
end_define

begin_define
define|#
directive|define
name|MB_VJCOMP
value|8
end_define

begin_define
define|#
directive|define
name|MB_LOG
value|9
end_define

begin_define
define|#
directive|define
name|MB_IPQ
value|10
end_define

begin_define
define|#
directive|define
name|MB_MAX
value|MB_IPQ
end_define

begin_function_decl
specifier|extern
name|int
name|plength
parameter_list|(
name|struct
name|mbuf
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|struct
name|mbuf
modifier|*
name|mballoc
parameter_list|(
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|struct
name|mbuf
modifier|*
name|mbfree
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
name|pfree
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
name|mbwrite
parameter_list|(
name|struct
name|mbuf
modifier|*
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
name|struct
name|mbuf
modifier|*
name|mbread
parameter_list|(
name|struct
name|mbuf
modifier|*
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
name|void
name|DumpBp
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
name|LogMemory
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|ShowMemMap
parameter_list|(
name|struct
name|cmdargs
specifier|const
modifier|*
parameter_list|)
function_decl|;
end_function_decl

end_unit

