begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * EISA bus device definitions  *  * Copyright (c) 1995 Justin T. Gibbs.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice immediately at the beginning of the file, without modification,  *    this list of conditions, and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. Absolutely no warranty of function or purpose is made by the author  *    Justin T. Gibbs.  * 4. Modifications may be freely made to this file if the above conditions  *    are met.  *  * $FreeBSD$  */
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

begin_include
include|#
directive|include
file|<sys/queue.h>
end_include

begin_define
define|#
directive|define
name|EISA_SLOTS
value|10
end_define

begin_comment
comment|/* PCI clashes with higher ones.. fix later */
end_comment

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
name|struct
name|linker_set
name|eisadriver_set
decl_stmt|;
end_decl_stmt

begin_typedef
typedef|typedef
name|u_int32_t
name|eisa_id_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|resvaddr
block|{
name|u_long
name|addr
decl_stmt|;
comment|/* start address */
name|u_long
name|size
decl_stmt|;
comment|/* size of reserved area */
name|int
name|flags
decl_stmt|;
define|#
directive|define
name|RESVADDR_NONE
value|0x00
define|#
directive|define
name|RESVADDR_BITMASK
value|0x01
comment|/* size is a mask of reserved  						 * bits at addr 						 */
define|#
directive|define
name|RESVADDR_RELOCATABLE
value|0x02
name|LIST_ENTRY
argument_list|(
argument|resvaddr
argument_list|)
name|links
expr_stmt|;
comment|/* List links */
block|}
name|resvaddr_t
typedef|;
end_typedef

begin_expr_stmt
name|LIST_HEAD
argument_list|(
name|resvlist
argument_list|,
name|resvaddr
argument_list|)
expr_stmt|;
end_expr_stmt

begin_struct
struct|struct
name|eisa_ioconf
block|{
name|int
name|slot
decl_stmt|;
name|struct
name|resvlist
name|ioaddrs
decl_stmt|;
comment|/* list of reserved I/O ranges */
name|struct
name|resvlist
name|maddrs
decl_stmt|;
comment|/* list of reserved memory ranges */
name|u_short
name|irq
decl_stmt|;
comment|/* bitmask of interrupt */
block|}
struct|;
end_struct

begin_struct_decl
struct_decl|struct
name|kern_devconf
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|eisa_device
struct_decl|;
end_struct_decl

begin_struct
struct|struct
name|eisa_driver
block|{
name|char
modifier|*
name|name
decl_stmt|;
comment|/* device name */
name|int
argument_list|(
argument|*probe
argument_list|)
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
expr_stmt|;
comment|/* test whether device is present */
name|int
argument_list|(
argument|*attach
argument_list|)
name|__P
argument_list|(
operator|(
expr|struct
name|eisa_device
operator|*
operator|)
argument_list|)
expr_stmt|;
comment|/* setup driver for a device */
name|int
argument_list|(
argument|*shutdown
argument_list|)
name|__P
argument_list|(
operator|(
expr|struct
name|kern_devconf
operator|*
operator|,
name|int
operator|)
argument_list|)
expr_stmt|;
comment|/* Return the device to a safe 					 * state before shutdown 					 */
name|u_long
modifier|*
name|unit
decl_stmt|;
comment|/* Next available unit */
block|}
struct|;
end_struct

begin_comment
comment|/* To be replaced by the "super device" generic device structure... */
end_comment

begin_struct
struct|struct
name|eisa_device
block|{
name|eisa_id_t
name|id
decl_stmt|;
name|u_long
name|unit
decl_stmt|;
name|char
modifier|*
name|full_name
decl_stmt|;
comment|/* for use in the probe message */
name|struct
name|eisa_ioconf
name|ioconf
decl_stmt|;
name|struct
name|eisa_driver
modifier|*
name|driver
decl_stmt|;
name|struct
name|kern_devconf
modifier|*
name|kdc
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
name|void
name|eisa_configure
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|eisa_device
modifier|*
name|eisa_match_dev
name|__P
argument_list|(
operator|(
expr|struct
name|eisa_device
operator|*
operator|,
name|char
operator|*
call|(
modifier|*
call|)
argument_list|(
name|eisa_id_t
argument_list|)
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|eisa_reg_start
name|__P
argument_list|(
operator|(
expr|struct
name|eisa_device
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|eisa_reg_end
name|__P
argument_list|(
operator|(
expr|struct
name|eisa_device
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|eisa_add_intr
name|__P
argument_list|(
operator|(
expr|struct
name|eisa_device
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|eisa_reg_intr
name|__P
argument_list|(
operator|(
expr|struct
name|eisa_device
operator|*
operator|,
name|int
operator|,
name|void
argument_list|(
operator|*
argument_list|)
argument_list|(
name|void
operator|*
argument_list|)
operator|,
name|void
operator|*
operator|,
name|u_int
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|eisa_release_intr
name|__P
argument_list|(
operator|(
expr|struct
name|eisa_device
operator|*
operator|,
name|int
operator|,
name|void
argument_list|(
operator|*
argument_list|)
argument_list|(
name|void
operator|*
argument_list|)
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|eisa_enable_intr
name|__P
argument_list|(
operator|(
expr|struct
name|eisa_device
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|eisa_add_iospace
name|__P
argument_list|(
operator|(
expr|struct
name|eisa_device
operator|*
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
name|eisa_reg_iospace
name|__P
argument_list|(
operator|(
expr|struct
name|eisa_device
operator|*
operator|,
name|resvaddr_t
operator|*
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
expr|struct
name|eisa_device
operator|*
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
name|eisa_reg_mspace
name|__P
argument_list|(
operator|(
expr|struct
name|eisa_device
operator|*
operator|,
name|resvaddr_t
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|eisa_registerdev
name|__P
argument_list|(
operator|(
expr|struct
name|eisa_device
operator|*
operator|,
expr|struct
name|eisa_driver
operator|*
operator|,
expr|struct
name|kern_devconf
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_struct_decl
struct_decl|struct
name|sysctl_req
struct_decl|;
end_struct_decl

begin_decl_stmt
specifier|extern
name|int
name|eisa_generic_externalize
name|__P
argument_list|(
operator|(
expr|struct
name|proc
operator|*
name|p
operator|,
expr|struct
name|kern_devconf
operator|*
name|kdc
operator|,
name|void
operator|*
name|userp
operator|,
name|size_t
name|l
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|kern_devconf
name|kdc_eisa0
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|EISA_EXTERNALLEN
value|(sizeof(struct eisa_device))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _I386_EISA_EISACONF_H_ */
end_comment

end_unit

