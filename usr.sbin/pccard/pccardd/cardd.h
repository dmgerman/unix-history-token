begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  *	Common include file for PCMCIA daemon  */
end_comment

begin_include
include|#
directive|include
file|<bitstring.h>
end_include

begin_include
include|#
directive|include
file|<pccard/card.h>
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
name|int
name|ether
decl_stmt|;
comment|/* For net cards, ether at offset */
name|int
name|reset_time
decl_stmt|;
comment|/* Reset time */
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
comment|/*  *	The rest of the structure is allocated dynamically.  *	Once allocated, it stays allocated.  */
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
comment|/*	struct device *device;*/
comment|/* System device info */
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

begin_if
if|#
directive|if
literal|0
end_if

begin_comment
unit|struct device 	{ 	struct device *next;
comment|/* List of devices */
end_comment

begin_comment
unit|int inuse;
comment|/* Driver being used */
end_comment

begin_comment
unit|struct cmd *insert;
comment|/* Insert commands */
end_comment

begin_comment
unit|struct cmd *remove;
comment|/* Remove commands */
end_comment

begin_endif
unit|};
endif|#
directive|endif
end_endif

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
block|}
struct|;
end_struct

begin_decl_stmt
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
name|struct
name|card
modifier|*
name|cards
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*struct device *devlist; */
end_comment

begin_decl_stmt
name|bitstr_t
modifier|*
name|mem_avail
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|bitstr_t
modifier|*
name|io_avail
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|verbose
decl_stmt|,
name|do_log
decl_stmt|;
end_decl_stmt

begin_function_decl
name|char
modifier|*
name|newstr
parameter_list|()
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
modifier|*
name|xmalloc
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|log_1s
parameter_list|(
name|char
modifier|*
parameter_list|,
name|char
modifier|*
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
name|execute
parameter_list|(
name|struct
name|cmd
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|unsigned
name|long
name|alloc_memory
parameter_list|(
name|int
name|size
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|bit_fns
parameter_list|(
name|bitstr_t
modifier|*
name|nm
parameter_list|,
name|int
name|nbits
parameter_list|,
name|int
name|count
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|readfile
parameter_list|(
name|char
modifier|*
name|name
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

end_unit

