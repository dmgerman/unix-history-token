begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$NetBSD: pcmciavar.h,v 1.12 2000/02/08 12:51:31 enami Exp $	*/
end_comment

begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_comment
comment|/*-  * Copyright (c) 1997 Marc Horowitz.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by Marc Horowitz.  * 4. The name of the author may not be used to endorse or promote products  *    derived from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_comment
comment|/*  * Contains information about mapped/allocated i/o spaces.  */
end_comment

begin_struct
struct|struct
name|pccard_io_handle
block|{
name|bus_space_tag_t
name|iot
decl_stmt|;
comment|/* bus space tag (from chipset) */
name|bus_space_handle_t
name|ioh
decl_stmt|;
comment|/* mapped space handle */
name|bus_addr_t
name|addr
decl_stmt|;
comment|/* resulting address in bus space */
name|bus_size_t
name|size
decl_stmt|;
comment|/* size of i/o space */
name|int
name|flags
decl_stmt|;
comment|/* misc. information */
name|int
name|width
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|PCCARD_IO_ALLOCATED
value|0x01
end_define

begin_comment
comment|/* i/o space was allocated */
end_comment

begin_comment
comment|/*  * Contains information about allocated memory space.  */
end_comment

begin_struct
struct|struct
name|pccard_mem_handle
block|{
name|bus_space_tag_t
name|memt
decl_stmt|;
comment|/* bus space tag (from chipset) */
name|bus_space_handle_t
name|memh
decl_stmt|;
comment|/* mapped space handle */
name|bus_addr_t
name|addr
decl_stmt|;
comment|/* resulting address in bus space */
name|bus_size_t
name|size
decl_stmt|;
comment|/* size of mem space */
name|bus_size_t
name|realsize
decl_stmt|;
comment|/* how much we really allocated */
name|bus_addr_t
name|cardaddr
decl_stmt|;
comment|/* Absolute address on card */
name|int
name|kind
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* Bits for kind */
end_comment

begin_define
define|#
directive|define
name|PCCARD_MEM_16BIT
value|1
end_define

begin_comment
comment|/* 1 -> 16bit 0 -> 8bit */
end_comment

begin_define
define|#
directive|define
name|PCCARD_MEM_ATTR
value|2
end_define

begin_comment
comment|/* 1 -> attribute mem 0 -> common */
end_comment

begin_define
define|#
directive|define
name|PCCARD_WIDTH_AUTO
value|0
end_define

begin_define
define|#
directive|define
name|PCCARD_WIDTH_IO8
value|1
end_define

begin_define
define|#
directive|define
name|PCCARD_WIDTH_IO16
value|2
end_define

begin_struct
struct|struct
name|pccard_tuple
block|{
name|unsigned
name|int
name|code
decl_stmt|;
name|unsigned
name|int
name|length
decl_stmt|;
name|u_long
name|mult
decl_stmt|;
comment|/* dist btn successive bytes */
name|bus_addr_t
name|ptr
decl_stmt|;
name|bus_space_tag_t
name|memt
decl_stmt|;
name|bus_space_handle_t
name|memh
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|int
function_decl|(
modifier|*
name|pccard_scan_t
function_decl|)
parameter_list|(
specifier|const
name|struct
name|pccard_tuple
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_struct
struct|struct
name|pccard_product
block|{
specifier|const
name|char
modifier|*
name|pp_name
decl_stmt|;
define|#
directive|define
name|PCCARD_VENDOR_ANY
value|(0xffffffff)
name|uint32_t
name|pp_vendor
decl_stmt|;
comment|/* 0 == end of table */
define|#
directive|define
name|PCCARD_PRODUCT_ANY
value|(0xffffffff)
name|uint32_t
name|pp_product
decl_stmt|;
specifier|const
name|char
modifier|*
name|pp_cis
index|[
literal|4
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|int
function_decl|(
modifier|*
name|pccard_product_match_fn
function_decl|)
parameter_list|(
name|device_t
name|dev
parameter_list|,
specifier|const
name|struct
name|pccard_product
modifier|*
name|ent
parameter_list|,
name|int
name|vpfmatch
parameter_list|)
function_decl|;
end_typedef

begin_include
include|#
directive|include
file|"card_if.h"
end_include

begin_comment
comment|/*  * make this inline so that we don't have to worry about dangling references  * to it in the modules or the code.  */
end_comment

begin_function
specifier|static
specifier|inline
specifier|const
name|struct
name|pccard_product
modifier|*
name|pccard_product_lookup
parameter_list|(
name|device_t
name|dev
parameter_list|,
specifier|const
name|struct
name|pccard_product
modifier|*
name|tab
parameter_list|,
name|size_t
name|ent_size
parameter_list|,
name|pccard_product_match_fn
name|matchfn
parameter_list|)
block|{
return|return
name|CARD_DO_PRODUCT_LOOKUP
argument_list|(
name|device_get_parent
argument_list|(
name|dev
argument_list|)
argument_list|,
name|dev
argument_list|,
name|tab
argument_list|,
name|ent_size
argument_list|,
name|matchfn
argument_list|)
return|;
block|}
end_function

begin_define
define|#
directive|define
name|pccard_cis_read_1
parameter_list|(
name|tuple
parameter_list|,
name|idx0
parameter_list|)
define|\
value|(bus_space_read_1((tuple)->memt, (tuple)->memh, (tuple)->mult*(idx0)))
end_define

begin_define
define|#
directive|define
name|pccard_tuple_read_1
parameter_list|(
name|tuple
parameter_list|,
name|idx1
parameter_list|)
define|\
value|(pccard_cis_read_1((tuple), ((tuple)->ptr+(2+(idx1)))))
end_define

begin_define
define|#
directive|define
name|pccard_tuple_read_2
parameter_list|(
name|tuple
parameter_list|,
name|idx2
parameter_list|)
define|\
value|(pccard_tuple_read_1((tuple), (idx2)) |				\ 	 (pccard_tuple_read_1((tuple), (idx2)+1)<<8))
end_define

begin_define
define|#
directive|define
name|pccard_tuple_read_3
parameter_list|(
name|tuple
parameter_list|,
name|idx3
parameter_list|)
define|\
value|(pccard_tuple_read_1((tuple), (idx3)) |				\ 	 (pccard_tuple_read_1((tuple), (idx3)+1)<<8) |			\ 	 (pccard_tuple_read_1((tuple), (idx3)+2)<<16))
end_define

begin_define
define|#
directive|define
name|pccard_tuple_read_4
parameter_list|(
name|tuple
parameter_list|,
name|idx4
parameter_list|)
define|\
value|(pccard_tuple_read_1((tuple), (idx4)) |				\ 	 (pccard_tuple_read_1((tuple), (idx4)+1)<<8) |			\ 	 (pccard_tuple_read_1((tuple), (idx4)+2)<<16) |			\ 	 (pccard_tuple_read_1((tuple), (idx4)+3)<<24))
end_define

begin_define
define|#
directive|define
name|pccard_tuple_read_n
parameter_list|(
name|tuple
parameter_list|,
name|n
parameter_list|,
name|idxn
parameter_list|)
define|\
value|(((n)==1)?pccard_tuple_read_1((tuple), (idxn)) :		\ 	 (((n)==2)?pccard_tuple_read_2((tuple), (idxn)) :		\ 	  (((n)==3)?pccard_tuple_read_3((tuple), (idxn)) :		\
comment|/* n == 4 */
value|pccard_tuple_read_4((tuple), (idxn)))))
end_define

begin_define
define|#
directive|define
name|PCCARD_SPACE_MEMORY
value|1
end_define

begin_define
define|#
directive|define
name|PCCARD_SPACE_IO
value|2
end_define

begin_define
define|#
directive|define
name|pccard_mfc
parameter_list|(
name|sc
parameter_list|)
define|\
value|(STAILQ_FIRST(&(sc)->card.pf_head)&&			\ 		 STAILQ_NEXT(STAILQ_FIRST(&(sc)->card.pf_head),pf_list))
end_define

begin_comment
comment|/* Convenience functions */
end_comment

begin_function
specifier|static
specifier|inline
name|int
name|pccard_cis_scan
parameter_list|(
name|device_t
name|dev
parameter_list|,
name|pccard_scan_t
name|fct
parameter_list|,
name|void
modifier|*
name|arg
parameter_list|)
block|{
return|return
operator|(
name|CARD_CIS_SCAN
argument_list|(
name|device_get_parent
argument_list|(
name|dev
argument_list|)
argument_list|,
name|dev
argument_list|,
name|fct
argument_list|,
name|arg
argument_list|)
operator|)
return|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|int
name|pccard_attr_read_1
parameter_list|(
name|device_t
name|dev
parameter_list|,
name|uint32_t
name|offset
parameter_list|,
name|uint8_t
modifier|*
name|val
parameter_list|)
block|{
return|return
operator|(
name|CARD_ATTR_READ
argument_list|(
name|device_get_parent
argument_list|(
name|dev
argument_list|)
argument_list|,
name|dev
argument_list|,
name|offset
argument_list|,
name|val
argument_list|)
operator|)
return|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|int
name|pccard_attr_write_1
parameter_list|(
name|device_t
name|dev
parameter_list|,
name|uint32_t
name|offset
parameter_list|,
name|uint8_t
name|val
parameter_list|)
block|{
return|return
operator|(
name|CARD_ATTR_WRITE
argument_list|(
name|device_get_parent
argument_list|(
name|dev
argument_list|)
argument_list|,
name|dev
argument_list|,
name|offset
argument_list|,
name|val
argument_list|)
operator|)
return|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|int
name|pccard_ccr_read_1
parameter_list|(
name|device_t
name|dev
parameter_list|,
name|uint32_t
name|offset
parameter_list|,
name|uint8_t
modifier|*
name|val
parameter_list|)
block|{
return|return
operator|(
name|CARD_CCR_READ
argument_list|(
name|device_get_parent
argument_list|(
name|dev
argument_list|)
argument_list|,
name|dev
argument_list|,
name|offset
argument_list|,
name|val
argument_list|)
operator|)
return|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|int
name|pccard_ccr_write_1
parameter_list|(
name|device_t
name|dev
parameter_list|,
name|uint32_t
name|offset
parameter_list|,
name|uint8_t
name|val
parameter_list|)
block|{
return|return
operator|(
name|CARD_CCR_WRITE
argument_list|(
name|device_get_parent
argument_list|(
name|dev
argument_list|)
argument_list|,
name|dev
argument_list|,
name|offset
argument_list|,
name|val
argument_list|)
operator|)
return|;
block|}
end_function

begin_comment
comment|/* Hack */
end_comment

begin_function_decl
name|int
name|pccard_select_cfe
parameter_list|(
name|device_t
name|dev
parameter_list|,
name|int
name|entry
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* ivar interface */
end_comment

begin_enum
enum|enum
block|{
name|PCCARD_IVAR_ETHADDR
block|,
comment|/* read ethernet address from CIS tupple */
name|PCCARD_IVAR_VENDOR
block|,
name|PCCARD_IVAR_PRODUCT
block|,
name|PCCARD_IVAR_PRODEXT
block|,
name|PCCARD_IVAR_FUNCTION_NUMBER
block|,
name|PCCARD_IVAR_VENDOR_STR
block|,
comment|/* CIS string for "Manufacturer" */
name|PCCARD_IVAR_PRODUCT_STR
block|,
comment|/* CIS string for "Product" */
name|PCCARD_IVAR_CIS3_STR
block|,
name|PCCARD_IVAR_CIS4_STR
block|,
name|PCCARD_IVAR_FUNCTION
block|,
name|PCCARD_IVAR_FUNCE_DISK
block|}
enum|;
end_enum

begin_define
define|#
directive|define
name|PCCARD_ACCESSOR
parameter_list|(
name|A
parameter_list|,
name|B
parameter_list|,
name|T
parameter_list|)
define|\
value|static inline int							\ pccard_get_ ## A(device_t dev, T *t)					\ {									\ 	return BUS_READ_IVAR(device_get_parent(dev), dev,		\ 	    PCCARD_IVAR_ ## B, (uintptr_t *) t);			\ }
end_define

begin_macro
name|PCCARD_ACCESSOR
argument_list|(
argument|ether
argument_list|,
argument|ETHADDR
argument_list|,
argument|uint8_t
argument_list|)
end_macro

begin_macro
name|PCCARD_ACCESSOR
argument_list|(
argument|vendor
argument_list|,
argument|VENDOR
argument_list|,
argument|uint32_t
argument_list|)
end_macro

begin_macro
name|PCCARD_ACCESSOR
argument_list|(
argument|product
argument_list|,
argument|PRODUCT
argument_list|,
argument|uint32_t
argument_list|)
end_macro

begin_macro
name|PCCARD_ACCESSOR
argument_list|(
argument|prodext
argument_list|,
argument|PRODEXT
argument_list|,
argument|uint16_t
argument_list|)
end_macro

begin_macro
name|PCCARD_ACCESSOR
argument_list|(
argument|function_number
argument_list|,
argument|FUNCTION_NUMBER
argument_list|,
argument|uint32_t
argument_list|)
end_macro

begin_macro
name|PCCARD_ACCESSOR
argument_list|(
argument|function
argument_list|,
argument|FUNCTION
argument_list|,
argument|uint32_t
argument_list|)
end_macro

begin_macro
name|PCCARD_ACCESSOR
argument_list|(
argument|funce_disk
argument_list|,
argument|FUNCE_DISK
argument_list|,
argument|uint16_t
argument_list|)
end_macro

begin_macro
name|PCCARD_ACCESSOR
argument_list|(
argument|vendor_str
argument_list|,
argument|VENDOR_STR
argument_list|,
argument|const char *
argument_list|)
end_macro

begin_macro
name|PCCARD_ACCESSOR
argument_list|(
argument|product_str
argument_list|,
argument|PRODUCT_STR
argument_list|,
argument|const char *
argument_list|)
end_macro

begin_macro
name|PCCARD_ACCESSOR
argument_list|(
argument|cis3_str
argument_list|,
argument|CIS3_STR
argument_list|,
argument|const char *
argument_list|)
end_macro

begin_expr_stmt
name|PCCARD_ACCESSOR
argument_list|(
name|cis4_str
argument_list|,
name|CIS4_STR
argument_list|,
specifier|const
name|char
operator|*
argument_list|)
comment|/* shared memory flags */
expr|enum
block|{
name|PCCARD_A_MEM_COM
block|,
comment|/* common */
name|PCCARD_A_MEM_ATTR
block|,
comment|/* attribute */
name|PCCARD_A_MEM_8BIT
block|,
comment|/* 8 bit */
name|PCCARD_A_MEM_16BIT
comment|/* 16 bit */
block|}
expr_stmt|;
end_expr_stmt

begin_define
define|#
directive|define
name|PCCARD_S
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|PCMCIA_STR_ ## a ## _ ## b
end_define

begin_define
define|#
directive|define
name|PCCARD_P
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|PCMCIA_PRODUCT_ ## a ## _ ## b
end_define

begin_define
define|#
directive|define
name|PCCARD_C
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|PCMCIA_CIS_ ## a ## _ ## b
end_define

begin_define
define|#
directive|define
name|PCMCIA_CARD_D
parameter_list|(
name|v
parameter_list|,
name|p
parameter_list|)
value|{ PCCARD_S(v, p), PCMCIA_VENDOR_ ## v, \ 		PCCARD_P(v, p), PCCARD_C(v, p) }
end_define

begin_define
define|#
directive|define
name|PCMCIA_CARD2_D
parameter_list|(
name|v1
parameter_list|,
name|p1
parameter_list|,
name|p2
parameter_list|)
define|\
value|{ PCMCIA_STR_ ## p2, PCMCIA_VENDOR_ ## v1, PCCARD_P(v1, p1), \ 		  PCMCIA_CIS_ ## p2}
end_define

begin_define
define|#
directive|define
name|PCMCIA_CARD
parameter_list|(
name|v
parameter_list|,
name|p
parameter_list|)
value|{ NULL, PCMCIA_VENDOR_ ## v, \ 		PCCARD_P(v, p), PCCARD_C(v, p) }
end_define

begin_define
define|#
directive|define
name|PCMCIA_CARD2
parameter_list|(
name|v1
parameter_list|,
name|p1
parameter_list|,
name|p2
parameter_list|)
define|\
value|{ NULL, PCMCIA_VENDOR_ ## v1, PCCARD_P(v1, p1), \ 		  PCMCIA_CIS_ ## p2}
end_define

begin_comment
comment|/*  * Defines to decode the get_funce_disk return value.  See the PCMCIA standard  * for all the details of what these bits mean.  */
end_comment

begin_define
define|#
directive|define
name|PFD_I_V_MASK
value|0x3
end_define

begin_define
define|#
directive|define
name|PFD_I_V_NONE_REQUIRED
value|0x0
end_define

begin_define
define|#
directive|define
name|PFD_I_V_REQ_MOD_ACC
value|0x1
end_define

begin_define
define|#
directive|define
name|PFD_I_V_REQ_ACC
value|0x2
end_define

begin_define
define|#
directive|define
name|PFD_I_V_REQ_ALWYS
value|0x1
end_define

begin_define
define|#
directive|define
name|PFD_I_S
value|0x4
end_define

begin_comment
comment|/* 0 rotating, 1 silicon */
end_comment

begin_define
define|#
directive|define
name|PFD_I_U
value|0x8
end_define

begin_comment
comment|/* SN Uniq? */
end_comment

begin_define
define|#
directive|define
name|PFD_I_D
value|0x10
end_define

begin_comment
comment|/* 0 - 1 drive, 1 - 2 drives */
end_comment

begin_define
define|#
directive|define
name|PFD_P_P0
value|0x100
end_define

begin_define
define|#
directive|define
name|PFD_P_P1
value|0x200
end_define

begin_define
define|#
directive|define
name|PFD_P_P2
value|0x400
end_define

begin_define
define|#
directive|define
name|PFD_P_P3
value|0x800
end_define

begin_define
define|#
directive|define
name|PFD_P_N
value|0x1000
end_define

begin_comment
comment|/* 3f7/377 excluded? */
end_comment

begin_define
define|#
directive|define
name|PFD_P_E
value|0x2000
end_define

begin_comment
comment|/* Index bit supported? */
end_comment

begin_define
define|#
directive|define
name|PFD_P_I
value|0x4000
end_define

begin_comment
comment|/* twincard */
end_comment

end_unit

