begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1995 Andrew McRae.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. The name of the author may not be used to endorse or promote products  *    derived from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  *  *	Common include file for PCMCIA daemon  */
end_comment

begin_include
include|#
directive|include
file|<bitstring.h>
end_include

begin_include
include|#
directive|include
file|<pccard/cardinfo.h>
end_include

begin_include
include|#
directive|include
file|<pccard/cis.h>
end_include

begin_include
include|#
directive|include
file|"readcis.h"
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|EXTERN
end_ifndef

begin_define
define|#
directive|define
name|EXTERN
value|extern
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_struct
struct|struct
name|cmd
block|{
name|struct
name|cmd
modifier|*
name|next
decl_stmt|;
name|char
modifier|*
name|line
decl_stmt|;
comment|/* Command line */
name|int
name|macro
decl_stmt|;
comment|/* Contains macros */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|card_config
block|{
name|struct
name|card_config
modifier|*
name|next
decl_stmt|;
name|unsigned
name|char
name|index_type
decl_stmt|;
name|unsigned
name|char
name|index
decl_stmt|;
name|struct
name|driver
modifier|*
name|driver
decl_stmt|;
name|int
name|irq
decl_stmt|;
name|int
name|flags
decl_stmt|;
name|char
name|inuse
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|ether
block|{
name|struct
name|ether
modifier|*
name|next
decl_stmt|;
name|int
name|type
decl_stmt|;
name|int
name|value
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|ETHTYPE_GENERIC
value|0
end_define

begin_define
define|#
directive|define
name|ETHTYPE_ATTR2
value|1
end_define

begin_struct
struct|struct
name|card
block|{
name|struct
name|card
modifier|*
name|next
decl_stmt|;
name|char
modifier|*
name|manuf
decl_stmt|;
name|char
modifier|*
name|version
decl_stmt|;
name|char
modifier|*
name|add_info1
decl_stmt|;
name|char
modifier|*
name|add_info2
decl_stmt|;
name|u_char
name|func_id
decl_stmt|;
name|int
name|deftype
decl_stmt|;
name|struct
name|ether
modifier|*
name|ether
decl_stmt|;
comment|/* For net cards, ether at offset */
name|int
name|reset_time
decl_stmt|;
comment|/* Reset time */
name|int
name|iosize
decl_stmt|;
comment|/* I/O window size (ignore location) */
name|struct
name|card_config
modifier|*
name|config
decl_stmt|;
comment|/* List of configs */
name|struct
name|cmd
modifier|*
name|insert
decl_stmt|;
comment|/* Insert commands */
name|struct
name|cmd
modifier|*
name|remove
decl_stmt|;
comment|/* Remove commands */
name|char
modifier|*
name|logstr
decl_stmt|;
comment|/* String for logger */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|driver
block|{
name|struct
name|driver
modifier|*
name|next
decl_stmt|;
name|char
modifier|*
name|name
decl_stmt|;
name|char
modifier|*
name|kernel
decl_stmt|;
comment|/* Kernel driver base name */
name|int
name|unit
decl_stmt|;
comment|/* Unit of driver */
comment|/* 	 * The rest of the structure is allocated dynamically. 	 * Once allocated, it stays allocated. 	 */
name|struct
name|card
modifier|*
name|card
decl_stmt|;
comment|/* Current card, if any */
name|struct
name|card_config
modifier|*
name|config
decl_stmt|;
comment|/* Config back ptr */
name|unsigned
name|int
name|mem
decl_stmt|;
comment|/* Allocated host address (if any) */
name|int
name|inuse
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  *	Defines one allocation block i.e a starting address  *	and size. Used for either memory or I/O ports  */
end_comment

begin_struct
struct|struct
name|allocblk
block|{
name|struct
name|allocblk
modifier|*
name|next
decl_stmt|;
name|int
name|addr
decl_stmt|;
comment|/* Address */
name|int
name|size
decl_stmt|;
comment|/* Size */
name|int
name|flags
decl_stmt|;
comment|/* Flags for block */
name|int
name|cardaddr
decl_stmt|;
comment|/* Card address */
block|}
struct|;
end_struct

begin_comment
comment|/*  *	Slot structure - data held for each slot.  */
end_comment

begin_struct
struct|struct
name|slot
block|{
name|struct
name|slot
modifier|*
name|next
decl_stmt|;
name|int
name|fd
decl_stmt|;
name|int
name|mask
decl_stmt|;
name|int
name|slot
decl_stmt|;
name|char
modifier|*
name|name
decl_stmt|;
name|enum
name|cardstate
name|state
decl_stmt|;
name|struct
name|cis
modifier|*
name|cis
decl_stmt|;
name|struct
name|card
modifier|*
name|card
decl_stmt|;
comment|/* Current card */
name|struct
name|card_config
modifier|*
name|config
decl_stmt|;
comment|/* Current configuration */
name|struct
name|cis_config
modifier|*
name|card_config
decl_stmt|;
name|char
name|devname
index|[
literal|16
index|]
decl_stmt|;
name|u_int
name|manufacturer
decl_stmt|;
name|u_int
name|product
decl_stmt|;
name|u_int
name|prodext
decl_stmt|;
name|unsigned
name|char
name|eaddr
index|[
literal|6
index|]
decl_stmt|;
comment|/* If any */
name|struct
name|allocblk
name|io
decl_stmt|;
comment|/* I/O block spec */
name|struct
name|allocblk
name|mem
decl_stmt|;
comment|/* Memory block spec */
name|int
name|irq
decl_stmt|;
comment|/* Irq value */
name|int
name|flags
decl_stmt|;
comment|/* Resource assignment flags */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Slot resource assignment/configuration flags  */
end_comment

begin_define
define|#
directive|define
name|IO_ASSIGNED
value|0x1
end_define

begin_define
define|#
directive|define
name|MEM_ASSIGNED
value|0x2
end_define

begin_define
define|#
directive|define
name|IRQ_ASSIGNED
value|0x4
end_define

begin_define
define|#
directive|define
name|EADDR_CONFIGED
value|0x8
end_define

begin_define
define|#
directive|define
name|WL_CONFIGED
value|0x10
end_define

begin_define
define|#
directive|define
name|AFLAGS
value|(IO_ASSIGNED | MEM_ASSIGNED | IRQ_ASSIGNED)
end_define

begin_define
define|#
directive|define
name|CFLAGS
value|(EADDR_CONFIGED | WL_CONFIGED)
end_define

begin_decl_stmt
name|EXTERN
name|struct
name|slot
modifier|*
name|slots
decl_stmt|,
modifier|*
name|current_slot
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|EXTERN
name|int
name|slen
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|EXTERN
name|struct
name|allocblk
modifier|*
name|pool_ioblks
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* I/O blocks in the pool */
end_comment

begin_decl_stmt
name|EXTERN
name|struct
name|allocblk
modifier|*
name|pool_mem
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Memory in the pool */
end_comment

begin_decl_stmt
name|EXTERN
name|int
name|pool_irq
index|[
literal|16
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* IRQ allocations */
end_comment

begin_decl_stmt
name|EXTERN
name|int
name|irq_init
index|[
literal|16
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* initial IRQ allocations */
end_comment

begin_decl_stmt
name|EXTERN
name|struct
name|driver
modifier|*
name|drivers
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* List of drivers */
end_comment

begin_decl_stmt
name|EXTERN
name|struct
name|card
modifier|*
name|cards
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|EXTERN
name|struct
name|card
modifier|*
name|last_card
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|EXTERN
name|bitstr_t
modifier|*
name|mem_avail
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|EXTERN
name|bitstr_t
modifier|*
name|mem_init
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|EXTERN
name|bitstr_t
modifier|*
name|io_avail
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|EXTERN
name|bitstr_t
modifier|*
name|io_init
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|EXTERN
name|int
name|pccard_init_sleep
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Time to sleep on init */
end_comment

begin_decl_stmt
name|EXTERN
name|int
name|use_kern_irq
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|EXTERN
name|int
name|debug_level
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* cardd.c functions */
end_comment

begin_function_decl
name|void
name|dump_config_file
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|slot
modifier|*
name|readslots
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|slot_change
parameter_list|(
name|struct
name|slot
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* util.c functions */
end_comment

begin_function_decl
name|unsigned
name|long
name|alloc_memory
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|bit_fns
parameter_list|(
name|bitstr_t
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|die
parameter_list|(
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|execute
parameter_list|(
name|struct
name|cmd
modifier|*
parameter_list|,
name|struct
name|slot
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|logmsg
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|log_setup
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|logerr
parameter_list|(
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|newstr
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|reset_slot
parameter_list|(
name|struct
name|slot
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
modifier|*
name|xmalloc
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* file.c functions */
end_comment

begin_function_decl
name|void
name|readfile
parameter_list|(
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* server.c functions */
end_comment

begin_function_decl
name|void
name|set_socket
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|stat_changed
parameter_list|(
name|struct
name|slot
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|process_client
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|IOPORTS
value|0x400
end_define

begin_define
define|#
directive|define
name|MEMUNIT
value|0x1000
end_define

begin_define
define|#
directive|define
name|MEMSTART
value|0xA0000
end_define

begin_define
define|#
directive|define
name|MEMEND
value|0x100000
end_define

begin_define
define|#
directive|define
name|MEMBLKS
value|((MEMEND-MEMSTART)/MEMUNIT)
end_define

begin_define
define|#
directive|define
name|MEM2BIT
parameter_list|(
name|x
parameter_list|)
value|(((x)-MEMSTART)/MEMUNIT)
end_define

begin_define
define|#
directive|define
name|BIT2MEM
parameter_list|(
name|x
parameter_list|)
value|(((x)*MEMUNIT)+MEMSTART)
end_define

begin_define
define|#
directive|define
name|MAXINCLUDES
value|10
end_define

begin_define
define|#
directive|define
name|MAXERRORS
value|10
end_define

begin_comment
comment|/*  * Config index types  */
end_comment

begin_define
define|#
directive|define
name|NORMAL_INDEX
value|0
end_define

begin_define
define|#
directive|define
name|DEFAULT_INDEX
value|1
end_define

begin_define
define|#
directive|define
name|AUTO_INDEX
value|2
end_define

begin_define
define|#
directive|define
name|DT_VERS
value|0
end_define

begin_define
define|#
directive|define
name|DT_FUNC
value|1
end_define

end_unit

