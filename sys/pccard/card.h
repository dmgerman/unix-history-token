begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  *	Include file for PCMCIA user process interface  *  *-------------------------------------------------------------------------  *  * Copyright (c) 1995 Andrew McRae.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. The name of the author may not be used to endorse or promote products  *    derived from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_PCCARD_CARD_H_
end_ifndef

begin_define
define|#
directive|define
name|_PCCARD_CARD_H_
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|KERNEL
end_ifndef

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<sys/ioccom.h>
end_include

begin_define
define|#
directive|define
name|PIOCGSTATE
value|_IOR('P', 1, struct slotstate)
end_define

begin_comment
comment|/* Get slot state */
end_comment

begin_define
define|#
directive|define
name|PIOCGMEM
value|_IOWR('P', 2, struct mem_desc)
end_define

begin_comment
comment|/* Get memory map */
end_comment

begin_define
define|#
directive|define
name|PIOCSMEM
value|_IOW('P', 3, struct mem_desc)
end_define

begin_comment
comment|/* Set memory map */
end_comment

begin_define
define|#
directive|define
name|PIOCGIO
value|_IOWR('P', 4, struct io_desc)
end_define

begin_comment
comment|/* Get I/O map */
end_comment

begin_define
define|#
directive|define
name|PIOCSIO
value|_IOW('P', 5, struct io_desc)
end_define

begin_comment
comment|/* Set I/O map */
end_comment

begin_define
define|#
directive|define
name|PIOCSDRV
value|_IOW('P', 6, struct dev_desc)
end_define

begin_comment
comment|/* Set driver */
end_comment

begin_define
define|#
directive|define
name|PIOCRWFLAG
value|_IOW('P', 7, int)
end_define

begin_comment
comment|/* Set flags for drv use */
end_comment

begin_define
define|#
directive|define
name|PIOCRWMEM
value|_IOWR('P', 8, unsigned long)
end_define

begin_comment
comment|/* Set mem for drv use */
end_comment

begin_define
define|#
directive|define
name|PIOCSPOW
value|_IOW('P', 9, struct power)
end_define

begin_comment
comment|/* Set power structure */
end_comment

begin_comment
comment|/*  *	Debug codes.  */
end_comment

begin_define
define|#
directive|define
name|PIOCGREG
value|_IOWR('P',100, struct pcic_reg)
end_define

begin_comment
comment|/* get reg */
end_comment

begin_define
define|#
directive|define
name|PIOCSREG
value|_IOW('P', 101, struct pcic_reg)
end_define

begin_comment
comment|/* Set reg */
end_comment

begin_comment
comment|/*  *	Slot states for PIOCGSTATE  */
end_comment

begin_enum
enum|enum
name|cardstate
block|{
name|noslot
block|,
name|empty
block|,
name|suspend
block|,
name|filled
block|}
enum|;
end_enum

begin_comment
comment|/*  *	Descriptor structure for memory map.  */
end_comment

begin_struct
struct|struct
name|mem_desc
block|{
name|int
name|window
decl_stmt|;
comment|/* Memory map window number (0-4) */
name|int
name|flags
decl_stmt|;
comment|/* Flags - see below */
name|caddr_t
name|start
decl_stmt|;
comment|/* System memory start */
name|int
name|size
decl_stmt|;
comment|/* Size of memory area */
name|unsigned
name|long
name|card
decl_stmt|;
comment|/* Card memory address */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|MDF_16BITS
value|0x01
end_define

begin_comment
comment|/* Memory is 16 bits wide */
end_comment

begin_define
define|#
directive|define
name|MDF_ZEROWS
value|0x02
end_define

begin_comment
comment|/* Set no wait states for memory */
end_comment

begin_define
define|#
directive|define
name|MDF_WS0
value|0x04
end_define

begin_comment
comment|/* Wait state flags */
end_comment

begin_define
define|#
directive|define
name|MDF_WS1
value|0x08
end_define

begin_define
define|#
directive|define
name|MDF_ATTR
value|0x10
end_define

begin_comment
comment|/* Memory is attribute memory */
end_comment

begin_define
define|#
directive|define
name|MDF_WP
value|0x20
end_define

begin_comment
comment|/* Write protect memory */
end_comment

begin_define
define|#
directive|define
name|MDF_ACTIVE
value|0x40
end_define

begin_comment
comment|/* Context active (read-only) */
end_comment

begin_comment
comment|/*  *	Descriptor structure for I/O map  */
end_comment

begin_struct
struct|struct
name|io_desc
block|{
name|int
name|window
decl_stmt|;
comment|/* I/O map number (0-1) */
name|int
name|flags
decl_stmt|;
comment|/* Flags - see below */
name|int
name|start
decl_stmt|;
comment|/* I/O port start */
name|int
name|size
decl_stmt|;
comment|/* Number of port addresses */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|IODF_WS
value|0x01
end_define

begin_comment
comment|/* Set wait states for 16 bit I/O access */
end_comment

begin_define
define|#
directive|define
name|IODF_16BIT
value|0x02
end_define

begin_comment
comment|/* I/O access are 16 bit */
end_comment

begin_define
define|#
directive|define
name|IODF_CS16
value|0x04
end_define

begin_comment
comment|/* Allow card selection of 16 bit access */
end_comment

begin_define
define|#
directive|define
name|IODF_ZEROWS
value|0x08
end_define

begin_comment
comment|/* No wait states for 8 bit I/O */
end_comment

begin_define
define|#
directive|define
name|IODF_ACTIVE
value|0x10
end_define

begin_comment
comment|/* Context active (read-only) */
end_comment

begin_comment
comment|/*  *	Device descriptor for allocation of driver.  */
end_comment

begin_struct
struct|struct
name|dev_desc
block|{
name|char
name|name
index|[
literal|16
index|]
decl_stmt|;
comment|/* Driver name */
name|int
name|unit
decl_stmt|;
comment|/* Driver unit number */
name|unsigned
name|long
name|mem
decl_stmt|;
comment|/* Memory address of driver */
name|int
name|memsize
decl_stmt|;
comment|/* Memory size (if used) */
name|int
name|iobase
decl_stmt|;
comment|/* base of I/O ports */
name|int
name|irqmask
decl_stmt|;
comment|/* Interrupt number(s) to allocate */
name|int
name|flags
decl_stmt|;
comment|/* Device flags */
name|u_char
name|misc
index|[
literal|128
index|]
decl_stmt|;
comment|/* For any random info */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|pcic_reg
block|{
name|unsigned
name|char
name|reg
decl_stmt|;
name|unsigned
name|char
name|value
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  *	Slot information. Used to read current status of slot.  */
end_comment

begin_struct
struct|struct
name|slotstate
block|{
name|enum
name|cardstate
name|state
decl_stmt|;
comment|/* Current state of slot */
name|int
name|maxmem
decl_stmt|;
comment|/* Max allowed memory windows */
name|int
name|maxio
decl_stmt|;
comment|/* Max allowed I/O windows */
name|int
name|irqs
decl_stmt|;
comment|/* Bitmap of IRQs allowed */
name|int
name|flags
decl_stmt|;
comment|/* Capability flags */
block|}
struct|;
end_struct

begin_comment
comment|/*  *	The power values are in volts * 10, e.g. 5V is 50, 3.3V is 33.  */
end_comment

begin_struct
struct|struct
name|power
block|{
name|int
name|vcc
decl_stmt|;
name|int
name|vpp
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  *	Other system limits  */
end_comment

begin_define
define|#
directive|define
name|MAXSLOT
value|16
end_define

begin_define
define|#
directive|define
name|NUM_MEM_WINDOWS
value|10
end_define

begin_define
define|#
directive|define
name|NUM_IO_WINDOWS
value|6
end_define

begin_define
define|#
directive|define
name|CARD_DEVICE
value|"/dev/card%d"
end_define

begin_comment
comment|/* String for sprintf */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_PCCARD_CARD_H_ */
end_comment

end_unit

