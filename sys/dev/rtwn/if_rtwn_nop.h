begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2016 Andriy Voskoboinyk<avos@FreeBSD.org>  *  * Permission to use, copy, modify, and distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES  * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF  * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR  * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES  * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN  * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF  * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|IF_RTWN_NOP_H
end_ifndef

begin_define
define|#
directive|define
name|IF_RTWN_NOP_H
end_define

begin_function
specifier|static
name|__inline
name|void
name|rtwn_nop_softc
parameter_list|(
name|struct
name|rtwn_softc
modifier|*
name|sc
parameter_list|)
block|{ }
end_function

begin_function
specifier|static
name|__inline
name|int
name|rtwn_nop_int_softc
parameter_list|(
name|struct
name|rtwn_softc
modifier|*
name|sc
parameter_list|)
block|{
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|int
name|rtwn_nop_int_softc_mbuf
parameter_list|(
name|struct
name|rtwn_softc
modifier|*
name|sc
parameter_list|,
name|struct
name|mbuf
modifier|*
name|m
parameter_list|)
block|{
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|void
name|rtwn_nop_softc_int
parameter_list|(
name|struct
name|rtwn_softc
modifier|*
name|sc
parameter_list|,
name|int
name|id
parameter_list|)
block|{ }
end_function

begin_function
specifier|static
name|__inline
name|void
name|rtwn_nop_softc_uint32
parameter_list|(
name|struct
name|rtwn_softc
modifier|*
name|sc
parameter_list|,
name|uint32_t
name|reg
parameter_list|)
block|{ }
end_function

begin_function
specifier|static
name|__inline
name|void
name|rtwn_nop_softc_chan
parameter_list|(
name|struct
name|rtwn_softc
modifier|*
name|sc
parameter_list|,
name|struct
name|ieee80211_channel
modifier|*
name|c
parameter_list|)
block|{ }
end_function

begin_function
specifier|static
name|__inline
name|void
name|rtwn_nop_softc_vap
parameter_list|(
name|struct
name|rtwn_softc
modifier|*
name|sc
parameter_list|,
name|struct
name|ieee80211vap
modifier|*
name|vap
parameter_list|)
block|{ }
end_function

begin_function
specifier|static
name|__inline
name|void
name|rtwn_nop_softc_uint8_int
parameter_list|(
name|struct
name|rtwn_softc
modifier|*
name|sc
parameter_list|,
name|uint8_t
modifier|*
name|buf
parameter_list|,
name|int
name|len
parameter_list|)
block|{ }
end_function

begin_function
specifier|static
name|__inline
name|void
name|rtwn_nop_void_int
parameter_list|(
name|void
modifier|*
name|buf
parameter_list|,
name|int
name|is5ghz
parameter_list|)
block|{ }
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* IF_RTWN_NOP_H */
end_comment

end_unit

