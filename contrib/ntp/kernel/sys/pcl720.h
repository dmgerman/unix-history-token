begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Copyright (c) 1995 Vixie Enterprises  *  * Permission to use, copy, modify, and distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies, and that  * the name of Vixie Enterprises not be used in advertising or publicity  * pertaining to distribution of the document or software without specific,  * written prior permission.  *   * THE SOFTWARE IS PROVIDED "AS IS" AND VIXIE ENTERPRISES DISCLAIMS ALL  * WARRANTIES WITH REGARD TO THIS SOFTWARE, INCLUDING ALL IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS.   IN NO EVENT SHALL VIXIE ENTERPRISES  * BE LIABLE FOR ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES  * OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS,  * WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION,  * ARISING OUT OF OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS  * SOFTWARE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_PCL720_DEFINED
end_ifndef

begin_define
define|#
directive|define
name|_PCL720_DEFINED
end_define

begin_define
define|#
directive|define
name|pcl720_data
parameter_list|(
name|base
parameter_list|,
name|bit
parameter_list|)
value|(base+(bit>>3))
end_define

begin_define
define|#
directive|define
name|pcl720_data_0_7
parameter_list|(
name|base
parameter_list|)
value|(base+0)
end_define

begin_define
define|#
directive|define
name|pcl720_data_8_15
parameter_list|(
name|base
parameter_list|)
value|(base+1)
end_define

begin_define
define|#
directive|define
name|pcl720_data_16_23
parameter_list|(
name|base
parameter_list|)
value|(base+2)
end_define

begin_define
define|#
directive|define
name|pcl720_data_24_31
parameter_list|(
name|base
parameter_list|)
value|(base+3)
end_define

begin_define
define|#
directive|define
name|pcl720_cntr
parameter_list|(
name|base
parameter_list|,
name|cntr
parameter_list|)
value|(base+4+cntr)
end_define

begin_comment
comment|/* cntr: 0..2 */
end_comment

begin_define
define|#
directive|define
name|pcl720_cntr_0
parameter_list|(
name|base
parameter_list|)
value|(base+4)
end_define

begin_define
define|#
directive|define
name|pcl720_cntr_1
parameter_list|(
name|base
parameter_list|)
value|(base+5)
end_define

begin_define
define|#
directive|define
name|pcl720_cntr_2
parameter_list|(
name|base
parameter_list|)
value|(base+6)
end_define

begin_define
define|#
directive|define
name|pcl720_ctrl
parameter_list|(
name|base
parameter_list|)
value|(base+7)
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|DEBUG_PCL720
end_ifndef

begin_define
define|#
directive|define
name|pcl720_inb
parameter_list|(
name|x
parameter_list|)
value|inb(x)
end_define

begin_define
define|#
directive|define
name|pcl720_outb
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|outb(x,y)
end_define

begin_else
else|#
directive|else
end_else

begin_function
specifier|static
name|unsigned
name|char
name|pcl720_inb
parameter_list|(
name|int
name|addr
parameter_list|)
block|{
name|unsigned
name|char
name|x
init|=
name|inb
argument_list|(
name|addr
argument_list|)
decl_stmt|;
name|fprintf
argument_list|(
name|DEBUG_PCL720
argument_list|,
literal|"inb(0x%x) -> 0x%x\n"
argument_list|,
name|addr
argument_list|,
name|x
argument_list|)
expr_stmt|;
return|return
operator|(
name|x
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|void
name|pcl720_outb
parameter_list|(
name|int
name|addr
parameter_list|,
name|unsigned
name|char
name|x
parameter_list|)
block|{
name|outb
argument_list|(
name|addr
argument_list|,
name|x
argument_list|)
expr_stmt|;
name|fprintf
argument_list|(
name|DEBUG_PCL720
argument_list|,
literal|"outb(0x%x, 0x%x)\n"
argument_list|,
name|addr
argument_list|,
name|x
argument_list|)
expr_stmt|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|pcl720_load
parameter_list|(
name|Base
parameter_list|,
name|Cntr
parameter_list|,
name|Mode
parameter_list|,
name|Val
parameter_list|)
define|\
value|({	register unsigned int	b = Base, c = Cntr, v = Val; \ 		i8253_ctrl ctrl; \ 		\ 		ctrl.s.bcd = i8253_binary; \ 		ctrl.s.mode = Mode; \ 		ctrl.s.rl = i8253_lmb; \ 		ctrl.s.cntr = c; \ 		pcl720_outb(pcl720_ctrl(b), ctrl.i); \ 		pcl720_outb(pcl720_cntr(b,c), v); \ 		pcl720_outb(pcl720_cntr(b,c), v>> 8); \ 		v; \ 	})
end_define

begin_define
define|#
directive|define
name|pcl720_read
parameter_list|(
name|Base
parameter_list|,
name|Cntr
parameter_list|)
define|\
value|({	register unsigned int	b = Base, v; \ 		i8253_ctrl ctrl; \ 		\ 		ctrl.s.rl = i8253_latch; \ 		ctrl.s.cntr = i8253_cntr_0; \ 		pcl720_outb(pcl720_ctrl(b), ctrl.i); \ 		v = pcl720_inb(pcl720_cntr_0(b)); \ 		v |= (pcl720_inb(pcl720_cntr_0(b))<< 8); \ 		v; \ 	})
end_define

begin_define
define|#
directive|define
name|pcl720_input
parameter_list|(
name|Base
parameter_list|)
define|\
value|({	register unsigned int	b = Base, v; \ 		\ 		v = pcl720_inb(pcl720_data_0_7(b)); \ 		v |= (pcl720_inb(pcl720_data_8_15(b))<< 8); \ 		v |= (pcl720_inb(pcl720_data_16_23(b))<< 16); \ 		v |= (pcl720_inb(pcl720_data_24_31(b))<< 24); \ 		v; \ 	})
end_define

begin_define
define|#
directive|define
name|pcl720_output
parameter_list|(
name|Base
parameter_list|,
name|Value
parameter_list|)
define|\
value|({	register unsigned int	b = Base, v = Value; \ 		\ 		pcl720_outb(pcl720_data_0_7(b), v); \ 		pcl720_outb(pcl720_data_8_15(b), v<< 8); \ 		pcl720_outb(pcl720_data_16_23(b), v<< 16); \ 		pcl720_outb(pcl720_data_24_31(b), v<< 24); \ 		v; \ 	})
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*_PCL720_DEFINED*/
end_comment

end_unit

