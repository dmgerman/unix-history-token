begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * EISA bus device definitions  *  * Copyright (c) 1995, 1996 Justin T. Gibbs.  * All rights reserved.  *   * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice immediately at the beginning of the file, without modification,  *    this list of conditions, and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. The name of the author may not be used to endorse or promote products  *    derived from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED. IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE FOR  * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_I386_EISA_EISACONF_H_
end_ifndef

begin_define
define|#
directive|define
name|_I386_EISA_EISACONF_H_
value|1
end_define

begin_define
define|#
directive|define
name|EISA_SLOT_SIZE
value|0x1000
end_define

begin_define
define|#
directive|define
name|EISA_MFCTR_CHAR0
parameter_list|(
name|ID
parameter_list|)
value|(char)(((ID>>26)& 0x1F) | '@')
end_define

begin_comment
comment|/* Bits 26-30 */
end_comment

begin_define
define|#
directive|define
name|EISA_MFCTR_CHAR1
parameter_list|(
name|ID
parameter_list|)
value|(char)(((ID>>21)& 0x1F) | '@')
end_define

begin_comment
comment|/* Bits 21-25 */
end_comment

begin_define
define|#
directive|define
name|EISA_MFCTR_CHAR2
parameter_list|(
name|ID
parameter_list|)
value|(char)(((ID>>16)& 0x1F) | '@')
end_define

begin_comment
comment|/* Bits 16-20 */
end_comment

begin_define
define|#
directive|define
name|EISA_MFCTR_ID
parameter_list|(
name|ID
parameter_list|)
value|(short)((ID>>16)& 0xFF)
end_define

begin_comment
comment|/* Bits 16-31 */
end_comment

begin_define
define|#
directive|define
name|EISA_PRODUCT_ID
parameter_list|(
name|ID
parameter_list|)
value|(short)((ID>>4)& 0xFFF)
end_define

begin_comment
comment|/* Bits  4-15 */
end_comment

begin_define
define|#
directive|define
name|EISA_REVISION_ID
parameter_list|(
name|ID
parameter_list|)
value|(u_char)(ID& 0x0F)
end_define

begin_comment
comment|/* Bits  0-3  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|num_eisa_slots
decl_stmt|;
end_decl_stmt

begin_typedef
typedef|typedef
name|u_int32_t
name|eisa_id_t
typedef|;
end_typedef

begin_enum
enum|enum
name|eisa_device_ivars
block|{
name|EISA_IVAR_SLOT
block|,
name|EISA_IVAR_ID
block|,
name|EISA_IVAR_IRQ
block|}
enum|;
end_enum

begin_define
define|#
directive|define
name|EISA_TRIGGER_EDGE
value|0x0
end_define

begin_define
define|#
directive|define
name|EISA_TRIGGER_LEVEL
value|0x1
end_define

begin_comment
comment|/*  * Simplified accessors for isa devices  */
end_comment

begin_define
define|#
directive|define
name|EISA_ACCESSOR
parameter_list|(
name|A
parameter_list|,
name|B
parameter_list|,
name|T
parameter_list|)
define|\ 									 \
value|static __inline T eisa_get_ ## A(device_t dev)				 \ {									 \ 	uintptr_t v;							 \ 	BUS_READ_IVAR(device_get_parent(dev), dev, EISA_IVAR_ ## B,&v); \ 	return (T) v;							 \ }									 \ 									 \ static __inline void eisa_set_ ## A(device_t dev, T t)			 \ {									 \ 	u_long v = (u_long) t;						 \ 	BUS_WRITE_IVAR(device_get_parent(dev), dev, EISA_IVAR_ ## B, v); \ }
end_define

begin_macro
name|EISA_ACCESSOR
argument_list|(
argument|slot
argument_list|,
argument|SLOT
argument_list|,
argument|int
argument_list|)
end_macro

begin_macro
name|EISA_ACCESSOR
argument_list|(
argument|id
argument_list|,
argument|ID
argument_list|,
argument|eisa_id_t
argument_list|)
end_macro

begin_macro
name|EISA_ACCESSOR
argument_list|(
argument|irq
argument_list|,
argument|IRQ
argument_list|,
argument|eisa_id_t
argument_list|)
end_macro

begin_decl_stmt
name|int
name|eisa_add_intr
name|__P
argument_list|(
operator|(
name|device_t
operator|,
name|int
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|RESVADDR_NONE
value|0x00
end_define

begin_define
define|#
directive|define
name|RESVADDR_BITMASK
value|0x01
end_define

begin_comment
comment|/* size is a mask of reserved  						 * bits at addr 						 */
end_comment

begin_define
define|#
directive|define
name|RESVADDR_RELOCATABLE
value|0x02
end_define

begin_decl_stmt
name|int
name|eisa_add_iospace
name|__P
argument_list|(
operator|(
name|device_t
operator|,
name|u_long
operator|,
name|u_long
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|eisa_add_mspace
name|__P
argument_list|(
operator|(
name|device_t
operator|,
name|u_long
operator|,
name|u_long
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _I386_EISA_EISACONF_H_ */
end_comment

end_unit

