begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  *	    Written by Toshiharu OHNO (tony-o@iij.ad.jp)  *  *   Copyright (C) 1993, Internet Initiative Japan, Inc. All rights reserverd.  *  * Redistribution and use in source and binary forms are permitted  * provided that the above copyright notice and this paragraph are  * duplicated in all such forms and that any documentation,  * advertising materials, and other materials related to such  * distribution and use acknowledge that the software was developed  * by the Internet Initiative Japan.  The name of the  * IIJ may not be used to endorse or promote products derived  * from this software without specific prior written permission.  * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED  * WARRANTIES OF MERCHANTIBILITY AND FITNESS FOR A PARTICULAR PURPOSE.  *  * $Id: mbuf.h,v 1.14.2.2 1999/05/02 08:59:48 brian Exp $  *  *	TODO:  */
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
define|\
value|((bp) ? (u_char *)((bp)+1) + (bp)->offset : NULL)
end_define

begin_define
define|#
directive|define
name|CONST_MBUF_CTOP
parameter_list|(
name|bp
parameter_list|)
define|\
value|((bp) ? (const u_char *)((bp)+1) + (bp)->offset : NULL)
end_define

begin_define
define|#
directive|define
name|MB_IPIN
value|0
end_define

begin_define
define|#
directive|define
name|MB_IPOUT
value|1
end_define

begin_define
define|#
directive|define
name|MB_NATIN
value|2
end_define

begin_define
define|#
directive|define
name|MB_NATOUT
value|3
end_define

begin_define
define|#
directive|define
name|MB_MPIN
value|4
end_define

begin_define
define|#
directive|define
name|MB_MPOUT
value|5
end_define

begin_define
define|#
directive|define
name|MB_VJIN
value|6
end_define

begin_define
define|#
directive|define
name|MB_VJOUT
value|7
end_define

begin_define
define|#
directive|define
name|MB_ICOMPDIN
value|8
end_define

begin_define
define|#
directive|define
name|MB_ICOMPDOUT
value|9
end_define

begin_define
define|#
directive|define
name|MB_COMPDIN
value|10
end_define

begin_define
define|#
directive|define
name|MB_COMPDOUT
value|11
end_define

begin_define
define|#
directive|define
name|MB_LQRIN
value|12
end_define

begin_define
define|#
directive|define
name|MB_LQROUT
value|13
end_define

begin_define
define|#
directive|define
name|MB_ECHOIN
value|14
end_define

begin_define
define|#
directive|define
name|MB_ECHOOUT
value|15
end_define

begin_define
define|#
directive|define
name|MB_PROTOIN
value|16
end_define

begin_define
define|#
directive|define
name|MB_PROTOOUT
value|17
end_define

begin_define
define|#
directive|define
name|MB_ACFIN
value|18
end_define

begin_define
define|#
directive|define
name|MB_ACFOUT
value|19
end_define

begin_define
define|#
directive|define
name|MB_SYNCIN
value|20
end_define

begin_define
define|#
directive|define
name|MB_SYNCOUT
value|21
end_define

begin_define
define|#
directive|define
name|MB_HDLCIN
value|22
end_define

begin_define
define|#
directive|define
name|MB_HDLCOUT
value|23
end_define

begin_define
define|#
directive|define
name|MB_ASYNCIN
value|24
end_define

begin_define
define|#
directive|define
name|MB_ASYNCOUT
value|25
end_define

begin_define
define|#
directive|define
name|MB_CBCPIN
value|26
end_define

begin_define
define|#
directive|define
name|MB_CBCPOUT
value|27
end_define

begin_define
define|#
directive|define
name|MB_CHAPIN
value|28
end_define

begin_define
define|#
directive|define
name|MB_CHAPOUT
value|29
end_define

begin_define
define|#
directive|define
name|MB_PAPIN
value|30
end_define

begin_define
define|#
directive|define
name|MB_PAPOUT
value|31
end_define

begin_define
define|#
directive|define
name|MB_CCPIN
value|32
end_define

begin_define
define|#
directive|define
name|MB_CCPOUT
value|33
end_define

begin_define
define|#
directive|define
name|MB_IPCPIN
value|34
end_define

begin_define
define|#
directive|define
name|MB_IPCPOUT
value|35
end_define

begin_define
define|#
directive|define
name|MB_LCPIN
value|36
end_define

begin_define
define|#
directive|define
name|MB_LCPOUT
value|37
end_define

begin_define
define|#
directive|define
name|MB_UNKNOWN
value|38
end_define

begin_define
define|#
directive|define
name|MB_MAX
value|MB_UNKNOWN
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
specifier|const
name|void
modifier|*
parameter_list|,
name|size_t
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
name|void
modifier|*
parameter_list|,
name|size_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|size_t
name|mbuf_View
parameter_list|(
name|struct
name|mbuf
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|,
name|size_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|struct
name|mbuf
modifier|*
name|mbuf_Prepend
parameter_list|(
name|struct
name|mbuf
modifier|*
parameter_list|,
specifier|const
name|void
modifier|*
parameter_list|,
name|size_t
parameter_list|,
name|size_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|struct
name|mbuf
modifier|*
name|mbuf_Truncate
parameter_list|(
name|struct
name|mbuf
modifier|*
parameter_list|,
name|size_t
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

begin_function_decl
specifier|extern
name|struct
name|mbuf
modifier|*
name|mbuf_Contiguous
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
name|mbuf_SetType
parameter_list|(
name|struct
name|mbuf
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

end_unit

