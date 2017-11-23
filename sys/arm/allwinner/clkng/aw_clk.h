begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2017 Emmanuel Vadot<manu@freebsd.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,  * BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;  * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED  * AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,  * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__AW_CLK_H__
end_ifndef

begin_define
define|#
directive|define
name|__AW_CLK_H__
end_define

begin_comment
comment|/*   Allwinner clocks formula :  PLLs:  (24MHz*N*K)/(M*P) (24MHz*N)/(M*P) (24MHz*N*2)/M (24MHz*N)/M (24MHz*N*K)/M (24MHz*N*K/2) (24MHz*N)/M (24MHz*N*K/2) (24MHz*N)/M  Periph clocks:  Clock Source/Divider N/Divider M Clock Source/Divider N/Divider M/2 Clock Source*N/(Divider M+1)/(Divider P+1)   */
end_comment

begin_struct
struct|struct
name|aw_clk_init
block|{
specifier|const
name|char
modifier|*
name|name
decl_stmt|;
specifier|const
name|char
modifier|*
name|parent_name
decl_stmt|;
name|uint64_t
name|default_freq
decl_stmt|;
name|bool
name|enable
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|AW_CLK_HAS_GATE
value|0x0001
end_define

begin_define
define|#
directive|define
name|AW_CLK_HAS_LOCK
value|0x0002
end_define

begin_define
define|#
directive|define
name|AW_CLK_HAS_MUX
value|0x0004
end_define

begin_define
define|#
directive|define
name|AW_CLK_REPARENT
value|0x0008
end_define

begin_define
define|#
directive|define
name|AW_CLK_SCALE_CHANGE
value|0x0010
end_define

begin_define
define|#
directive|define
name|AW_CLK_HAS_FRAC
value|0x0020
end_define

begin_define
define|#
directive|define
name|AW_CLK_HAS_UPDATE
value|0x0040
end_define

begin_define
define|#
directive|define
name|AW_CLK_FACTOR_POWER_OF_TWO
value|0x0001
end_define

begin_define
define|#
directive|define
name|AW_CLK_FACTOR_ZERO_BASED
value|0x0002
end_define

begin_define
define|#
directive|define
name|AW_CLK_FACTOR_HAS_COND
value|0x0004
end_define

begin_define
define|#
directive|define
name|AW_CLK_FACTOR_FIXED
value|0x0008
end_define

begin_struct
struct|struct
name|aw_clk_factor
block|{
name|uint32_t
name|shift
decl_stmt|;
comment|/* Shift bits for the factor */
name|uint32_t
name|mask
decl_stmt|;
comment|/* Mask to get the factor, will be override by the clk methods */
name|uint32_t
name|width
decl_stmt|;
comment|/* Number of bits for the factor */
name|uint32_t
name|value
decl_stmt|;
comment|/* Fixed value, depends on AW_CLK_FACTOR_FIXED */
name|uint32_t
name|cond_shift
decl_stmt|;
name|uint32_t
name|cond_mask
decl_stmt|;
name|uint32_t
name|cond_width
decl_stmt|;
name|uint32_t
name|cond_value
decl_stmt|;
name|uint32_t
name|flags
decl_stmt|;
comment|/* Flags */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|aw_clk_frac
block|{
name|uint64_t
name|freq0
decl_stmt|;
name|uint64_t
name|freq1
decl_stmt|;
name|uint32_t
name|mode_sel
decl_stmt|;
name|uint32_t
name|freq_sel
decl_stmt|;
block|}
struct|;
end_struct

begin_function
specifier|static
specifier|inline
name|uint32_t
name|aw_clk_get_factor
parameter_list|(
name|uint32_t
name|val
parameter_list|,
name|struct
name|aw_clk_factor
modifier|*
name|factor
parameter_list|)
block|{
name|uint32_t
name|factor_val
decl_stmt|;
name|uint32_t
name|cond
decl_stmt|;
if|if
condition|(
name|factor
operator|->
name|flags
operator|&
name|AW_CLK_FACTOR_HAS_COND
condition|)
block|{
name|cond
operator|=
operator|(
name|val
operator|&
name|factor
operator|->
name|cond_mask
operator|)
operator|>>
name|factor
operator|->
name|cond_shift
expr_stmt|;
if|if
condition|(
name|cond
operator|!=
name|factor
operator|->
name|cond_value
condition|)
return|return
operator|(
literal|1
operator|)
return|;
block|}
if|if
condition|(
name|factor
operator|->
name|flags
operator|&
name|AW_CLK_FACTOR_FIXED
condition|)
return|return
operator|(
name|factor
operator|->
name|value
operator|)
return|;
name|factor_val
operator|=
operator|(
name|val
operator|&
name|factor
operator|->
name|mask
operator|)
operator|>>
name|factor
operator|->
name|shift
expr_stmt|;
if|if
condition|(
operator|!
operator|(
name|factor
operator|->
name|flags
operator|&
name|AW_CLK_FACTOR_ZERO_BASED
operator|)
condition|)
name|factor_val
operator|+=
literal|1
expr_stmt|;
elseif|else
if|if
condition|(
name|factor
operator|->
name|flags
operator|&
name|AW_CLK_FACTOR_POWER_OF_TWO
condition|)
name|factor_val
operator|=
literal|1
operator|<<
name|factor_val
expr_stmt|;
return|return
operator|(
name|factor_val
operator|)
return|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|uint32_t
name|aw_clk_factor_get_max
parameter_list|(
name|struct
name|aw_clk_factor
modifier|*
name|factor
parameter_list|)
block|{
name|uint32_t
name|max
decl_stmt|;
if|if
condition|(
name|factor
operator|->
name|flags
operator|&
name|AW_CLK_FACTOR_FIXED
condition|)
name|max
operator|=
name|factor
operator|->
name|value
expr_stmt|;
elseif|else
if|if
condition|(
name|factor
operator|->
name|flags
operator|&
name|AW_CLK_FACTOR_POWER_OF_TWO
condition|)
name|max
operator|=
literal|1
operator|<<
operator|(
operator|(
literal|1
operator|<<
name|factor
operator|->
name|width
operator|)
operator|-
literal|1
operator|)
expr_stmt|;
else|else
block|{
name|max
operator|=
operator|(
literal|1
operator|<<
name|factor
operator|->
name|width
operator|)
expr_stmt|;
block|}
return|return
operator|(
name|max
operator|)
return|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|uint32_t
name|aw_clk_factor_get_min
parameter_list|(
name|struct
name|aw_clk_factor
modifier|*
name|factor
parameter_list|)
block|{
name|uint32_t
name|min
decl_stmt|;
if|if
condition|(
name|factor
operator|->
name|flags
operator|&
name|AW_CLK_FACTOR_FIXED
condition|)
name|min
operator|=
name|factor
operator|->
name|value
expr_stmt|;
elseif|else
if|if
condition|(
name|factor
operator|->
name|flags
operator|&
name|AW_CLK_FACTOR_ZERO_BASED
condition|)
name|min
operator|=
literal|0
expr_stmt|;
else|else
name|min
operator|=
literal|1
expr_stmt|;
return|return
operator|(
name|min
operator|)
return|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|uint32_t
name|aw_clk_factor_get_value
parameter_list|(
name|struct
name|aw_clk_factor
modifier|*
name|factor
parameter_list|,
name|uint32_t
name|raw
parameter_list|)
block|{
name|uint32_t
name|val
decl_stmt|;
if|if
condition|(
name|factor
operator|->
name|flags
operator|&
name|AW_CLK_FACTOR_FIXED
condition|)
return|return
operator|(
name|factor
operator|->
name|value
operator|)
return|;
if|if
condition|(
name|factor
operator|->
name|flags
operator|&
name|AW_CLK_FACTOR_ZERO_BASED
condition|)
name|val
operator|=
name|raw
expr_stmt|;
elseif|else
if|if
condition|(
name|factor
operator|->
name|flags
operator|&
name|AW_CLK_FACTOR_POWER_OF_TWO
condition|)
block|{
for|for
control|(
name|val
operator|=
literal|0
init|;
name|raw
operator|!=
literal|1
condition|;
name|val
operator|++
control|)
name|raw
operator|>>=
literal|1
expr_stmt|;
block|}
else|else
name|val
operator|=
name|raw
operator|-
literal|1
expr_stmt|;
return|return
operator|(
name|val
operator|)
return|;
block|}
end_function

begin_define
define|#
directive|define
name|CCU_RESET
parameter_list|(
name|idx
parameter_list|,
name|o
parameter_list|,
name|s
parameter_list|)
define|\
value|[idx] = {		\ 		.offset = o,	\ 		.shift = s,	\ 	},
end_define

begin_define
define|#
directive|define
name|CCU_GATE
parameter_list|(
name|idx
parameter_list|,
name|clkname
parameter_list|,
name|pname
parameter_list|,
name|o
parameter_list|,
name|s
parameter_list|)
define|\
value|[idx] = {				\ 		.name = clkname,		\ 		.parent_name = pname,		\ 		.offset = o,			\ 		.shift = s,			\ 	},
end_define

begin_define
define|#
directive|define
name|NKMP_CLK
parameter_list|(
name|_clkname
parameter_list|,
name|_id
parameter_list|,
name|_name
parameter_list|,
name|_pnames
parameter_list|,		\
name|_offset
parameter_list|,						\
name|_n_shift
parameter_list|,
name|_n_width
parameter_list|,
name|_n_value
parameter_list|,
name|_n_flags
parameter_list|,		\
name|_k_shift
parameter_list|,
name|_k_width
parameter_list|,
name|_k_value
parameter_list|,
name|_k_flags
parameter_list|,		\
name|_m_shift
parameter_list|,
name|_m_width
parameter_list|,
name|_m_value
parameter_list|,
name|_m_flags
parameter_list|,		\
name|_p_shift
parameter_list|,
name|_p_width
parameter_list|,
name|_p_value
parameter_list|,
name|_p_flags
parameter_list|,		\
name|_gate
parameter_list|,						\
name|_lock
parameter_list|,
name|_lock_retries
parameter_list|,					\
name|_flags
parameter_list|)
define|\
value|static struct aw_clk_nkmp_def _clkname = {	\ 		.clkdef = {				\ 			.id = _id,			\ 			.name = _name,			\ 			.parent_names = _pnames,	\ 			.parent_cnt = nitems(_pnames),	\ 		},					\ 		.offset = _offset,			\ 		.n.shift = _n_shift,			\ 		.n.width = _n_width,			\ 		.n.value = _n_value,			\ 		.n.flags = _n_flags,			\ 		.k.shift = _k_shift,			\ 		.k.width = _k_width,			\ 		.k.value = _k_value,			\ 		.k.flags = _k_flags,			\ 		.m.shift = _m_shift,			\ 		.m.width = _m_width,			\ 		.m.value = _m_value,			\ 		.m.flags = _m_flags,			\ 		.p.shift = _p_shift,			\ 		.p.width = _p_width,			\ 		.p.value = _p_value,			\ 		.p.flags = _p_flags,			\ 		.gate_shift = _gate,			\ 		.lock_shift = _lock,			\ 		.lock_retries = _lock_retries,		\ 		.flags = _flags,			\ 	}
end_define

begin_define
define|#
directive|define
name|NKMP_CLK_WITH_MUX
parameter_list|(
name|_clkname
parameter_list|,			\
name|_id
parameter_list|,
name|_name
parameter_list|,
name|_pnames
parameter_list|,					\
name|_offset
parameter_list|,						\
name|_n_shift
parameter_list|,
name|_n_width
parameter_list|,
name|_n_value
parameter_list|,
name|_n_flags
parameter_list|,		\
name|_k_shift
parameter_list|,
name|_k_width
parameter_list|,
name|_k_value
parameter_list|,
name|_k_flags
parameter_list|,		\
name|_m_shift
parameter_list|,
name|_m_width
parameter_list|,
name|_m_value
parameter_list|,
name|_m_flags
parameter_list|,		\
name|_p_shift
parameter_list|,
name|_p_width
parameter_list|,
name|_p_value
parameter_list|,
name|_p_flags
parameter_list|,		\
name|_mux_shift
parameter_list|,
name|_mux_width
parameter_list|,
name|_gate
parameter_list|,			\
name|_lock
parameter_list|,
name|_lock_retries
parameter_list|,					\
name|_flags
parameter_list|)
define|\
value|static struct aw_clk_nkmp_def _clkname = {	\ 		.clkdef = {				\ 			.id = _id,			\ 			.name = _name,			\ 			.parent_names = _pnames,	\ 			.parent_cnt = nitems(_pnames),	\ 		},					\ 		.offset = _offset,			\ 		.n.shift = _n_shift,			\ 		.n.width = _n_width,			\ 		.n.value = _n_value,			\ 		.n.flags = _n_flags,			\ 		.k.shift = _k_shift,			\ 		.k.width = _k_width,			\ 		.k.value = _k_value,			\ 		.k.flags = _k_flags,			\ 		.m.shift = _m_shift,			\ 		.m.width = _m_width,			\ 		.m.value = _m_value,			\ 		.m.flags = _m_flags,			\ 		.p.shift = _p_shift,			\ 		.p.width = _p_width,			\ 		.p.value = _p_value,			\ 		.p.flags = _p_flags,			\ 		.mux_shift = _mux_shift,		\ 		.mux_width = _mux_width,		\ 		.gate_shift = _gate,			\ 		.lock_shift = _lock,			\ 		.lock_retries = _lock_retries,		\ 		.flags = _flags,			\ 	}
end_define

begin_define
define|#
directive|define
name|NKMP_CLK_WITH_UPDATE
parameter_list|(
name|_clkname
parameter_list|,			\
name|_id
parameter_list|,
name|_name
parameter_list|,
name|_pnames
parameter_list|,					\
name|_offset
parameter_list|,						\
name|_n_shift
parameter_list|,
name|_n_width
parameter_list|,
name|_n_value
parameter_list|,
name|_n_flags
parameter_list|,		\
name|_k_shift
parameter_list|,
name|_k_width
parameter_list|,
name|_k_value
parameter_list|,
name|_k_flags
parameter_list|,		\
name|_m_shift
parameter_list|,
name|_m_width
parameter_list|,
name|_m_value
parameter_list|,
name|_m_flags
parameter_list|,		\
name|_p_shift
parameter_list|,
name|_p_width
parameter_list|,
name|_p_value
parameter_list|,
name|_p_flags
parameter_list|,		\
name|_gate
parameter_list|,						\
name|_lock
parameter_list|,
name|_lock_retries
parameter_list|,					\
name|_update
parameter_list|,						\
name|_flags
parameter_list|)
define|\
value|static struct aw_clk_nkmp_def _clkname = {	\ 		.clkdef = {				\ 			.id = _id,			\ 			.name = _name,			\ 			.parent_names = _pnames,	\ 			.parent_cnt = nitems(_pnames),	\ 		},					\ 		.offset = _offset,			\ 		.n.shift = _n_shift,			\ 		.n.width = _n_width,			\ 		.n.value = _n_value,			\ 		.n.flags = _n_flags,			\ 		.k.shift = _k_shift,			\ 		.k.width = _k_width,			\ 		.k.value = _k_value,			\ 		.k.flags = _k_flags,			\ 		.m.shift = _m_shift,			\ 		.m.width = _m_width,			\ 		.m.value = _m_value,			\ 		.m.flags = _m_flags,			\ 		.p.shift = _p_shift,			\ 		.p.width = _p_width,			\ 		.p.value = _p_value,			\ 		.p.flags = _p_flags,			\ 		.gate_shift = _gate,			\ 		.lock_shift = _lock,			\ 		.lock_retries = _lock_retries,		\ 		.update_shift = _update,		\ 		.flags = _flags | AW_CLK_HAS_UPDATE,	\ 	}
end_define

begin_define
define|#
directive|define
name|NM_CLK
parameter_list|(
name|_clkname
parameter_list|,
name|_id
parameter_list|,
name|_name
parameter_list|,
name|_pnames
parameter_list|,		\
name|_offset
parameter_list|,						\
name|_nshift
parameter_list|,
name|_nwidth
parameter_list|,
name|_nvalue
parameter_list|,
name|_nflags
parameter_list|,		\
name|_mshift
parameter_list|,
name|_mwidth
parameter_list|,
name|_mvalue
parameter_list|,
name|_mflags
parameter_list|,		\
name|_mux_shift
parameter_list|,
name|_mux_width
parameter_list|,				\
name|_gate_shift
parameter_list|,					\
name|_flags
parameter_list|)
define|\
value|static struct aw_clk_nm_def _clkname = 	{	\ 		.clkdef = {				\ 			.id = _id,			\ 			.name = _name,			\ 			.parent_names = _pnames,	\ 			.parent_cnt = nitems(_pnames),	\ 		},					\ 		.offset = _offset,			\ 		.n.shift = _nshift,			\ 		.n.width = _nwidth,			\ 		.n.value = _nvalue,			\ 		.n.flags = _nflags,			\ 		.mux_shift = _mux_shift,		\ 		.m.shift = _mshift,			\ 		.m.width = _mwidth,			\ 		.m.value = _mvalue,			\ 		.m.flags = _mflags,			\ 		.mux_width = _mux_width,		\ 		.flags = _flags,			\ 	}
end_define

begin_define
define|#
directive|define
name|NM_CLK_WITH_FRAC
parameter_list|(
name|_clkname
parameter_list|,
name|_id
parameter_list|,
name|_name
parameter_list|,
name|_pnames
parameter_list|,	\
name|_offset
parameter_list|,						\
name|_nshift
parameter_list|,
name|_nwidth
parameter_list|,
name|_nvalue
parameter_list|,
name|_nflags
parameter_list|,		\
name|_mshift
parameter_list|,
name|_mwidth
parameter_list|,
name|_mvalue
parameter_list|,
name|_mflags
parameter_list|,		\
name|_gate_shift
parameter_list|,
name|_lock_shift
parameter_list|,
name|_lock_retries
parameter_list|,		\
name|_flags
parameter_list|,
name|_freq0
parameter_list|,
name|_freq1
parameter_list|,
name|_mode_sel
parameter_list|,
name|_freq_sel
parameter_list|)
define|\
value|static struct aw_clk_nm_def _clkname =	{	\ 		.clkdef = {				\ 			.id = _id,			\ 			.name = _name,			\ 			.parent_names = _pnames,	\ 			.parent_cnt = nitems(_pnames),	\ 		},					\ 		.offset = _offset,			\ 		.n.shift = _nshift,			\ 		.n.width = _nwidth,			\ 		.n.value = _nvalue,			\ 		.n.flags = _nflags,			\ 		.m.shift = _mshift,			\ 		.m.width = _mwidth,			\ 		.m.value = _mvalue,			\ 		.m.flags = _mflags,			\ 		.gate_shift = _gate_shift,		\ 		.lock_shift = _lock_shift,		\ 		.lock_retries = _lock_retries,		\ 		.flags = _flags | AW_CLK_HAS_FRAC,	\ 		.frac.freq0 = _freq0,			\ 		.frac.freq1 = _freq1,			\ 		.frac.mode_sel = _mode_sel,		\ 		.frac.freq_sel = _freq_sel,		\ 	}
end_define

begin_define
define|#
directive|define
name|PREDIV_CLK
parameter_list|(
name|_clkname
parameter_list|,
name|_id
parameter_list|,
name|_name
parameter_list|,
name|_pnames
parameter_list|,	\
name|_offset
parameter_list|,	\
name|_mux_shift
parameter_list|,
name|_mux_width
parameter_list|,	\
name|_div_shift
parameter_list|,
name|_div_width
parameter_list|,
name|_div_value
parameter_list|,
name|_div_flags
parameter_list|,	\
name|_prediv_shift
parameter_list|,
name|_prediv_width
parameter_list|,
name|_prediv_value
parameter_list|,
name|_prediv_flags
parameter_list|,	\
name|_prediv_cond_shift
parameter_list|,
name|_prediv_cond_width
parameter_list|,
name|_prediv_cond_value
parameter_list|)
define|\
value|static struct aw_clk_prediv_mux_def _clkname = {	\ 		.clkdef = {					\ 			.id = _id,				\ 			.name = _name,				\ 			.parent_names = _pnames,		\ 			.parent_cnt = nitems(_pnames),		\ 		},						\ 		.offset = _offset,				\ 		.mux_shift = _mux_shift,			\ 		.mux_width = _mux_width,			\ 		.div.shift = _div_shift,			\ 		.div.width = _div_width,			\ 		.div.value = _div_value,			\ 		.div.flags = _div_flags,			\ 		.prediv.shift = _prediv_shift,			\ 		.prediv.width = _prediv_width,			\ 		.prediv.value = _prediv_value,			\ 		.prediv.flags = _prediv_flags,			\ 		.prediv.cond_shift = _prediv_cond_shift,	\ 		.prediv.cond_width = _prediv_cond_width,	\ 		.prediv.cond_value = _prediv_cond_value,	\ 	}
end_define

begin_define
define|#
directive|define
name|PREDIV_CLK_WITH_MASK
parameter_list|(
name|_clkname
parameter_list|,
name|_id
parameter_list|,
name|_name
parameter_list|,
name|_pnames
parameter_list|,	\
name|_offset
parameter_list|,							\
name|_mux_shift
parameter_list|,
name|_mux_width
parameter_list|,					\
name|_div_shift
parameter_list|,
name|_div_width
parameter_list|,
name|_div_value
parameter_list|,
name|_div_flags
parameter_list|,		\
name|_prediv_shift
parameter_list|,
name|_prediv_width
parameter_list|,
name|_prediv_value
parameter_list|,
name|_prediv_flags
parameter_list|,	\
name|_prediv_cond_mask
parameter_list|,
name|_prediv_cond_value
parameter_list|)
define|\
value|static struct aw_clk_prediv_mux_def _clkname = {	\ 		.clkdef = {					\ 			.id = _id,				\ 			.name = _name,				\ 			.parent_names = _pnames,		\ 			.parent_cnt = nitems(_pnames),		\ 		},						\ 		.offset = _offset,				\ 		.mux_shift = _mux_shift,			\ 		.mux_width = _mux_width,			\ 		.div.shift = _div_shift,			\ 		.div.width = _div_width,			\ 		.div.value = _div_value,			\ 		.div.flags = _div_flags,			\ 		.prediv.shift = _prediv_shift,			\ 		.prediv.width = _prediv_width,			\ 		.prediv.value = _prediv_value,			\ 		.prediv.flags = _prediv_flags,			\ 		.prediv.cond_shift = 0,				\ 		.prediv.cond_width = 0,				\ 		.prediv.cond_mask = _prediv_cond_mask,		\ 		.prediv.cond_value = _prediv_cond_value,	\ 	}
end_define

begin_define
define|#
directive|define
name|MUX_CLK
parameter_list|(
name|_clkname
parameter_list|,
name|_id
parameter_list|,
name|_name
parameter_list|,
name|_pnames
parameter_list|,		\
name|_offset
parameter_list|,
name|_shift
parameter_list|,
name|_width
parameter_list|)
define|\
value|static struct clk_mux_def _clkname = {	\ 		.clkdef = {				\ 			.id = _id,			\ 			.name = _name,			\ 			.parent_names = _pnames,	\ 			.parent_cnt = nitems(_pnames)	\ 		},					\ 		.offset = _offset,			\ 		.shift = _shift,			\ 		.width = _width,			\ 	}
end_define

begin_define
define|#
directive|define
name|DIV_CLK
parameter_list|(
name|_clkname
parameter_list|,
name|_id
parameter_list|,
name|_name
parameter_list|,
name|_pnames
parameter_list|,		\
name|_offset
parameter_list|,						\
name|_i_shift
parameter_list|,
name|_i_width
parameter_list|,					\
name|_div_flags
parameter_list|,
name|_div_table
parameter_list|)
define|\
value|static struct clk_div_def _clkname = {		\ 		.clkdef = {				\ 			.id = _id,			\ 			.name = _name,			\ 			.parent_names = _pnames,	\ 			.parent_cnt = nitems(_pnames)	\ 		},					\ 		.offset = _offset,			\ 		.i_shift = _i_shift,			\ 		.i_width = _i_width,			\ 		.div_flags = _div_flags,		\ 		.div_table = _div_table,		\ 	}
end_define

begin_define
define|#
directive|define
name|FIXED_CLK
parameter_list|(
name|_clkname
parameter_list|,
name|_id
parameter_list|,
name|_name
parameter_list|,
name|_pnames
parameter_list|,	\
name|_freq
parameter_list|,
name|_mult
parameter_list|,
name|_div
parameter_list|,
name|_flags
parameter_list|)
define|\
value|static struct clk_fixed_def _clkname = {	\ 		.clkdef = {				\ 			.id = _id,			\ 			.name = _name,			\ 			.parent_names = _pnames,	\ 			.parent_cnt = 1,		\ 		},					\ 		.freq = _freq,				\ 		.mult = _mult,				\ 		.div = _div,				\ 		.fixed_flags = _flags,			\ 	}
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __AW_CLK_H__ */
end_comment

end_unit

