begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  *	    Written by Toshiharu OHNO (tony-o@iij.ad.jp)  *  *   Copyright (C) 1993, Internet Initiative Japan, Inc. All rights reserverd.  *  * Redistribution and use in source and binary forms are permitted  * provided that the above copyright notice and this paragraph are  * duplicated in all such forms and that any documentation,  * advertising materials, and other materials related to such  * distribution and use acknowledge that the software was developed  * by the Internet Initiative Japan.  The name of the  * IIJ may not be used to endorse or promote products derived  * from this software without specific prior written permission.  * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED  * WARRANTIES OF MERCHANTIBILITY AND FITNESS FOR A PARTICULAR PURPOSE.  *  * $FreeBSD$  *  *	TODO:  */
end_comment

begin_struct
struct|struct
name|mbuf
block|{
name|short
name|size
decl_stmt|;
comment|/* size allocated (excluding header) */
name|short
name|offset
decl_stmt|;
comment|/* offset from header end to start position */
name|short
name|cnt
decl_stmt|;
comment|/* available byte count in buffer */
name|short
name|type
decl_stmt|;
comment|/* MB_* below */
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
comment|/* buffer space is malloc()d directly after the header */
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
name|MBUF_CTOP
parameter_list|(
name|bp
parameter_list|)
value|((u_char *)((bp)+1) + (bp)->offset)
end_define

begin_define
define|#
directive|define
name|CONST_MBUF_CTOP
parameter_list|(
name|bp
parameter_list|)
value|((const u_char *)((bp)+1) + (bp)->offset)
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
name|MB_CBCP
value|3
end_define

begin_define
define|#
directive|define
name|MB_HDLCOUT
value|4
end_define

begin_define
define|#
directive|define
name|MB_IPIN
value|5
end_define

begin_define
define|#
directive|define
name|MB_ECHO
value|6
end_define

begin_define
define|#
directive|define
name|MB_LQR
value|7
end_define

begin_define
define|#
directive|define
name|MB_LINK
value|8
end_define

begin_define
define|#
directive|define
name|MB_VJCOMP
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
name|MB_MP
value|11
end_define

begin_define
define|#
directive|define
name|MB_MAX
value|MB_MP
end_define

begin_struct_decl
struct_decl|struct
name|cmdargs
struct_decl|;
end_struct_decl

begin_function_decl
specifier|extern
name|int
name|mbuf_Length
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
name|mbuf_Alloc
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
name|mbuf_FreeSeg
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
name|mbuf_Free
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
name|mbuf_Write
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
name|mbuf_Read
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
name|mbuf_Log
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|mbuf_Show
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
name|void
name|mbuf_Enqueue
parameter_list|(
name|struct
name|mqueue
modifier|*
parameter_list|,
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
name|mbuf_Dequeue
parameter_list|(
name|struct
name|mqueue
modifier|*
parameter_list|)
function_decl|;
end_function_decl

end_unit

