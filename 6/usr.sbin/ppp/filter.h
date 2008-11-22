begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1996 - 2001 Brian Somers<brian@Awfulhak.org>  *          based on work by Toshiharu OHNO<tony-o@iij.ad.jp>  *                           Internet Initiative Japan, Inc (IIJ)  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_comment
comment|/* Operations - f_srcop, f_dstop */
end_comment

begin_define
define|#
directive|define
name|OP_NONE
value|0
end_define

begin_define
define|#
directive|define
name|OP_EQ
value|1
end_define

begin_define
define|#
directive|define
name|OP_GT
value|2
end_define

begin_define
define|#
directive|define
name|OP_LT
value|3
end_define

begin_comment
comment|/* srctype or dsttype */
end_comment

begin_define
define|#
directive|define
name|T_ADDR
value|0
end_define

begin_define
define|#
directive|define
name|T_MYADDR
value|1
end_define

begin_define
define|#
directive|define
name|T_MYADDR6
value|2
end_define

begin_define
define|#
directive|define
name|T_HISADDR
value|3
end_define

begin_define
define|#
directive|define
name|T_HISADDR6
value|4
end_define

begin_define
define|#
directive|define
name|T_DNS0
value|5
end_define

begin_define
define|#
directive|define
name|T_DNS1
value|6
end_define

begin_comment
comment|/*  * There's a struct filterent for each possible filter rule.  The  * layout is designed to minimise size (there are 4 * MAXFILTERS of  * them) - which is also conveniently a power of 2 (32 bytes) on  * architectures where sizeof(int)==4 (this makes indexing faster).  *  * Note that there are four free bits in the initial word for future  * extensions.  */
end_comment

begin_struct
struct|struct
name|filterent
block|{
name|int
name|f_proto
decl_stmt|;
comment|/* Protocol: getprotoby*() */
name|unsigned
name|f_action
range|:
literal|8
decl_stmt|;
comment|/* Filtering action: goto or A_... */
name|unsigned
name|f_srcop
range|:
literal|2
decl_stmt|;
comment|/* Source port operation: OP_... */
name|unsigned
name|f_dstop
range|:
literal|2
decl_stmt|;
comment|/* Destination port operation: OP_... */
name|unsigned
name|f_srctype
range|:
literal|3
decl_stmt|;
comment|/* T_ value of src */
name|unsigned
name|f_dsttype
range|:
literal|3
decl_stmt|;
comment|/* T_ value of dst */
name|unsigned
name|f_estab
range|:
literal|1
decl_stmt|;
comment|/* Check TCP ACK bit */
name|unsigned
name|f_syn
range|:
literal|1
decl_stmt|;
comment|/* Check TCP SYN bit */
name|unsigned
name|f_finrst
range|:
literal|1
decl_stmt|;
comment|/* Check TCP FIN/RST bits */
name|unsigned
name|f_invert
range|:
literal|1
decl_stmt|;
comment|/* true to complement match */
name|struct
name|ncprange
name|f_src
decl_stmt|;
comment|/* Source address and mask */
name|struct
name|ncprange
name|f_dst
decl_stmt|;
comment|/* Destination address and mask */
name|u_short
name|f_srcport
decl_stmt|;
comment|/* Source port, compared with f_srcop */
name|u_short
name|f_dstport
decl_stmt|;
comment|/* Destination port, compared with f_dstop */
name|unsigned
name|timeout
decl_stmt|;
comment|/* Keep alive value for passed packet */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|MAXFILTERS
value|40
end_define

begin_comment
comment|/* in each filter set */
end_comment

begin_comment
comment|/* f_action values [0..MAXFILTERS) specify the next filter rule, others are: */
end_comment

begin_define
define|#
directive|define
name|A_NONE
value|(MAXFILTERS)
end_define

begin_define
define|#
directive|define
name|A_PERMIT
value|(A_NONE+1)
end_define

begin_define
define|#
directive|define
name|A_DENY
value|(A_PERMIT+1)
end_define

begin_struct
struct|struct
name|filter
block|{
name|struct
name|filterent
name|rule
index|[
name|MAXFILTERS
index|]
decl_stmt|;
comment|/* incoming packet filter */
specifier|const
name|char
modifier|*
name|name
decl_stmt|;
name|unsigned
name|fragok
range|:
literal|1
decl_stmt|;
name|unsigned
name|logok
range|:
literal|1
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* Which filter set */
end_comment

begin_define
define|#
directive|define
name|FL_IN
value|0
end_define

begin_define
define|#
directive|define
name|FL_OUT
value|1
end_define

begin_define
define|#
directive|define
name|FL_DIAL
value|2
end_define

begin_define
define|#
directive|define
name|FL_KEEP
value|3
end_define

begin_struct_decl
struct_decl|struct
name|ipcp
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|cmdargs
struct_decl|;
end_struct_decl

begin_function_decl
specifier|extern
name|int
name|filter_Show
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
name|filter_Set
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
specifier|const
name|char
modifier|*
name|filter_Action2Nam
parameter_list|(
name|unsigned
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
specifier|const
name|char
modifier|*
name|filter_Op2Nam
parameter_list|(
name|unsigned
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|filter_AdjustAddr
parameter_list|(
name|struct
name|filter
modifier|*
parameter_list|,
name|struct
name|ncpaddr
modifier|*
parameter_list|,
name|struct
name|ncpaddr
modifier|*
parameter_list|,
name|struct
name|in_addr
modifier|*
parameter_list|)
function_decl|;
end_function_decl

end_unit

