begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/**************************************************************************  Copyright (c) 2007-2008, Chelsio Inc. All rights reserved.  Redistribution and use in source and binary forms, with or without modification, are permitted provided that the following conditions are met:   1. Redistributions of source code must retain the above copyright notice,     this list of conditions and the following disclaimer.   2. Neither the name of the Chelsio Corporation nor the names of its     contributors may be used to endorse or promote products derived from     this software without specific prior written permission.  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  $FreeBSD$  ***************************************************************************/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_CXGB_OFFLOAD_H
end_ifndef

begin_define
define|#
directive|define
name|_CXGB_OFFLOAD_H
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|TCP_OFFLOAD
end_ifdef

begin_enum
enum|enum
block|{
name|ULD_TOM
init|=
literal|1
block|,
name|ULD_IWARP
init|=
literal|2
block|, }
enum|;
end_enum

begin_struct_decl
struct_decl|struct
name|adapter
struct_decl|;
end_struct_decl

begin_struct
struct|struct
name|uld_info
block|{
name|SLIST_ENTRY
argument_list|(
argument|uld_info
argument_list|)
name|link
expr_stmt|;
name|int
name|refcount
decl_stmt|;
name|int
name|uld_id
decl_stmt|;
name|int
function_decl|(
modifier|*
name|activate
function_decl|)
parameter_list|(
name|struct
name|adapter
modifier|*
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|deactivate
function_decl|)
parameter_list|(
name|struct
name|adapter
modifier|*
parameter_list|)
function_decl|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|tom_tunables
block|{
name|int
name|sndbuf
decl_stmt|;
name|int
name|ddp
decl_stmt|;
name|int
name|indsz
decl_stmt|;
name|int
name|ddp_thres
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* CPL message priority levels */
end_comment

begin_enum
enum|enum
block|{
name|CPL_PRIORITY_DATA
init|=
literal|0
block|,
comment|/* data messages */
name|CPL_PRIORITY_CONTROL
init|=
literal|1
comment|/* offload control messages */
block|}
enum|;
end_enum

begin_define
define|#
directive|define
name|S_HDR_NDESC
value|0
end_define

begin_define
define|#
directive|define
name|M_HDR_NDESC
value|0xf
end_define

begin_define
define|#
directive|define
name|V_HDR_NDESC
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_HDR_NDESC)
end_define

begin_define
define|#
directive|define
name|G_HDR_NDESC
parameter_list|(
name|x
parameter_list|)
value|(((x)>> S_HDR_NDESC)& M_HDR_NDESC)
end_define

begin_define
define|#
directive|define
name|S_HDR_QSET
value|4
end_define

begin_define
define|#
directive|define
name|M_HDR_QSET
value|0xf
end_define

begin_define
define|#
directive|define
name|V_HDR_QSET
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_HDR_QSET)
end_define

begin_define
define|#
directive|define
name|G_HDR_QSET
parameter_list|(
name|x
parameter_list|)
value|(((x)>> S_HDR_QSET)& M_HDR_QSET)
end_define

begin_define
define|#
directive|define
name|S_HDR_CTRL
value|8
end_define

begin_define
define|#
directive|define
name|V_HDR_CTRL
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_HDR_CTRL)
end_define

begin_define
define|#
directive|define
name|F_HDR_CTRL
value|V_HDR_CTRL(1U)
end_define

begin_define
define|#
directive|define
name|S_HDR_DF
value|9
end_define

begin_define
define|#
directive|define
name|V_HDR_DF
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_HDR_DF)
end_define

begin_define
define|#
directive|define
name|F_HDR_DF
value|V_HDR_DF(1U)
end_define

begin_define
define|#
directive|define
name|S_HDR_SGL
value|10
end_define

begin_define
define|#
directive|define
name|V_HDR_SGL
parameter_list|(
name|x
parameter_list|)
value|((x)<< S_HDR_SGL)
end_define

begin_define
define|#
directive|define
name|F_HDR_SGL
value|V_HDR_SGL(1U)
end_define

begin_struct
struct|struct
name|ofld_hdr
block|{
name|void
modifier|*
name|sgl
decl_stmt|;
comment|/* SGL, if F_HDR_SGL set in flags */
name|int
name|plen
decl_stmt|;
comment|/* amount of payload (in bytes) */
name|int
name|flags
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Convenience function for fixed size CPLs that fit in 1 desc.  */
end_comment

begin_define
define|#
directive|define
name|M_GETHDR_OFLD
parameter_list|(
name|qset
parameter_list|,
name|ctrl
parameter_list|,
name|cpl
parameter_list|)
define|\
value|m_gethdr_ofld(qset, ctrl, sizeof(*cpl), (void **)&cpl)
end_define

begin_function
specifier|static
specifier|inline
name|struct
name|mbuf
modifier|*
name|m_gethdr_ofld
parameter_list|(
name|int
name|qset
parameter_list|,
name|int
name|ctrl
parameter_list|,
name|int
name|cpllen
parameter_list|,
name|void
modifier|*
modifier|*
name|cpl
parameter_list|)
block|{
name|struct
name|mbuf
modifier|*
name|m
decl_stmt|;
name|struct
name|ofld_hdr
modifier|*
name|oh
decl_stmt|;
name|m
operator|=
name|m_gethdr
argument_list|(
name|M_NOWAIT
argument_list|,
name|MT_DATA
argument_list|)
expr_stmt|;
if|if
condition|(
name|m
operator|==
name|NULL
condition|)
return|return
operator|(
name|NULL
operator|)
return|;
name|oh
operator|=
name|mtod
argument_list|(
name|m
argument_list|,
expr|struct
name|ofld_hdr
operator|*
argument_list|)
expr_stmt|;
name|oh
operator|->
name|flags
operator|=
name|V_HDR_NDESC
argument_list|(
literal|1
argument_list|)
operator||
name|V_HDR_QSET
argument_list|(
name|qset
argument_list|)
operator||
name|V_HDR_CTRL
argument_list|(
name|ctrl
argument_list|)
expr_stmt|;
operator|*
name|cpl
operator|=
operator|(
name|void
operator|*
operator|)
operator|(
name|oh
operator|+
literal|1
operator|)
expr_stmt|;
name|m
operator|->
name|m_pkthdr
operator|.
name|len
operator|=
name|m
operator|->
name|m_len
operator|=
sizeof|sizeof
argument_list|(
operator|*
name|oh
argument_list|)
operator|+
name|cpllen
expr_stmt|;
return|return
operator|(
name|m
operator|)
return|;
block|}
end_function

begin_function_decl
name|int
name|t3_register_uld
parameter_list|(
name|struct
name|uld_info
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|t3_unregister_uld
parameter_list|(
name|struct
name|uld_info
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|t3_activate_uld
parameter_list|(
name|struct
name|adapter
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|t3_deactivate_uld
parameter_list|(
name|struct
name|adapter
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* TCP_OFFLOAD */
end_comment

begin_define
define|#
directive|define
name|CXGB_UNIMPLEMENTED
parameter_list|()
define|\
value|panic("IMPLEMENT: %s:%s:%d", __FUNCTION__, __FILE__, __LINE__)
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

