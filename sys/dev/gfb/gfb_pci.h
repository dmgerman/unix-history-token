begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1995, 1996 Carnegie-Mellon University.  * All rights reserved.  *  * Author: Chris G. Demetriou  *   * Permission to use, copy, modify and distribute this software and  * its documentation is hereby granted, provided that both the copyright  * notice and this permission notice appear in all copies of the  * software, derivative works or modified versions, and any portions  * thereof, and that both notices appear in supporting documentation.  *   * CARNEGIE MELLON ALLOWS FREE USE OF THIS SOFTWARE IN ITS "AS IS"   * CONDITION.  CARNEGIE MELLON DISCLAIMS ANY LIABILITY OF ANY KIND   * FOR ANY DAMAGES WHATSOEVER RESULTING FROM THE USE OF THIS SOFTWARE.  *   * Carnegie Mellon requests users of this software to return to  *  *  Software Distribution Coordinator  or  Software.Distribution@CS.CMU.EDU  *  School of Computer Science  *  Carnegie Mellon University  *  Pittsburgh PA 15213-3890  *  * any improvements or extensions that they make and grant Carnegie the  * rights to redistribute these changes.  *  * Copyright (c) 2000 Andrew Miklic  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_PCI_GFB_H_
end_ifndef

begin_define
define|#
directive|define
name|_PCI_GFB_H_
end_define

begin_define
define|#
directive|define
name|GFB_MEM_BASE_RID
value|0x10
end_define

begin_typedef
typedef|typedef
name|u_int32_t
name|gfb_reg_t
typedef|;
end_typedef

begin_comment
comment|/* GFB register access macros */
end_comment

begin_define
define|#
directive|define
name|BUFADDR
parameter_list|(
name|adp
parameter_list|,
name|off
parameter_list|)
define|\
comment|/*	(adp)->va_buffer = (adp)->va_mem_base +			\ 			   (((adp)->va_buffer -			\ 			     (adp)->va_mem_base +		\ 			     (adp)->va_buffer_size) %		\ 			    (adp)->va_mem_size),		\ 	(adp)->va_buffer_alias = ((adp)->va_buffer -		\ 				  (adp)->va_mem_base) /		\ 				 (adp)->va_buffer_size,		\ 	(adp)->va_window = (adp)->va_buffer +			\ 			   (((adp)->va_window -			\ 			     (adp)->va_mem_base) /		\ 			    (adp)->va_buffer_alias),		\ */
value|((adp)->va_window + (adp)->va_window_orig +		\ 	 ((vm_offset_t)(off)<< 2L))
end_define

begin_define
define|#
directive|define
name|REGADDR
parameter_list|(
name|adp
parameter_list|,
name|reg
parameter_list|)
define|\
comment|/*	(adp)->va_buffer = (adp)->va_mem_base +			\ 			   (((adp)->va_buffer -			\ 			     (adp)->va_mem_base +		\ 			     (adp)->va_buffer_size) %		\ 			    (adp)->va_mem_size),		\ 	(adp)->va_buffer_alias = ((adp)->va_buffer -		\ 				  (adp)->va_mem_base) /		\ 				 (adp)->va_buffer_size,		\ 	(adp)->va_registers = (adp)->va_buffer +		\ 			      (((adp)->va_registers -		\ 				(adp)->va_mem_base) /		\ 			       (adp)->va_buffer_alias),		\ */
value|((adp)->va_registers + ((vm_offset_t)(reg)<< 2L))
end_define

begin_define
define|#
directive|define
name|READ_GFB_REGISTER
parameter_list|(
name|adp
parameter_list|,
name|reg
parameter_list|)
define|\
value|(*(u_int32_t *)(REGADDR(adp, reg)))
end_define

begin_define
define|#
directive|define
name|WRITE_GFB_REGISTER
parameter_list|(
name|adp
parameter_list|,
name|reg
parameter_list|,
name|val
parameter_list|)
define|\
value|(*(u_int32_t*)(REGADDR(adp, reg)) = (val))
end_define

begin_define
define|#
directive|define
name|GFB_REGISTER_WRITE_BARRIER
parameter_list|(
name|sc
parameter_list|,
name|reg
parameter_list|,
name|nregs
parameter_list|)
define|\
value|bus_space_barrier((sc)->btag, (sc)->regs, ((reg)<< 2),	\ 			  4 * (nregs), BUS_SPACE_BARRIER_WRITE)
end_define

begin_define
define|#
directive|define
name|GFB_REGISTER_READ_BARRIER
parameter_list|(
name|sc
parameter_list|,
name|reg
parameter_list|,
name|nregs
parameter_list|)
define|\
value|bus_space_barrier((sc)->btag, (sc)->regs, ((reg)<< 2), \ 			  4 * (nregs), BUS_SPACE_BARRIER_READ)
end_define

begin_define
define|#
directive|define
name|GFB_REGISTER_READWRITE_BARRIER
parameter_list|(
name|sc
parameter_list|,
name|reg
parameter_list|,
name|nregs
parameter_list|)
define|\
value|bus_space_barrier((sc)->btag, (sc)->regs, ((reg)<< 2),	\ 			  4 * (nregs),				\ 			  BUS_SPACE_BARRIER_READ |		\ 			  BUS_SPACE_BARRIER_WRITE)
end_define

begin_define
define|#
directive|define
name|READ_GFB_BUFFER
parameter_list|(
name|adp
parameter_list|,
name|reg
parameter_list|)
define|\
value|(*(u_int32_t *)(BUFADDR(adp, reg)))
end_define

begin_define
define|#
directive|define
name|WRITE_GFB_BUFFER
parameter_list|(
name|adp
parameter_list|,
name|reg
parameter_list|,
name|val
parameter_list|)
define|\
value|(*(u_int32_t*)(BUFADDR(adp, reg)) = (val))
end_define

begin_comment
comment|/*int pcigfb_probe(device_t);*/
end_comment

begin_function_decl
name|int
name|pcigfb_attach
parameter_list|(
name|device_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|pcigfb_detach
parameter_list|(
name|device_t
parameter_list|)
function_decl|;
end_function_decl

begin_ifdef
ifdef|#
directive|ifdef
name|FB_INSTALL_CDEV
end_ifdef

begin_decl_stmt
name|d_open_t
name|pcigfb_open
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_close_t
name|pcigfb_close
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_read_t
name|pcigfb_read
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_write_t
name|pcigfb_write
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_ioctl_t
name|pcigfb_ioctl
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_mmap_t
name|pcigfb_mmap
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*FB_INSTALL_CDEV*/
end_comment

begin_typedef
typedef|typedef
struct|struct
name|gfb_type
block|{
name|int
name|vendor_id
decl_stmt|;
name|int
name|device_id
decl_stmt|;
name|char
modifier|*
name|name
decl_stmt|;
block|}
typedef|*
name|gfb_type_t
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _PCI_GFB_H_ */
end_comment

end_unit

