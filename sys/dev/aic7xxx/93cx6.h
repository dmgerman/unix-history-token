begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Interface to the 93C46 serial EEPROM that is used to store BIOS  * settings for the aic7xxx based adaptec SCSI controllers.  It can  * also be used for 93C26 and 93C06 serial EEPROMS.  *  * Copyright (c) 1994, 1995 Justin T. Gibbs.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions, and the following disclaimer,  *    without modification, immediately at the beginning of the file.  * 2. The name of the author may not be used to endorse or promote products  *    derived from this software without specific prior written permission.  *  * Where this Software is combined with software released under the terms of   * the GNU Public License ("GPL") and the terms of the GPL would require the   * combined work to also be released under the terms of the GPL, the terms  * and conditions of this License will apply in addition to those of the  * GPL with the exception of any terms or conditions of this License that  * conflict with, or are expressly prohibited by, the GPL.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED. IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE FOR  * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|__NetBSD__
argument_list|)
end_if

begin_include
include|#
directive|include
file|<sys/systm.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|KERNEL
end_ifdef

begin_typedef
typedef|typedef
enum|enum
block|{
name|C46
init|=
literal|6
block|,
name|C56_66
init|=
literal|8
block|}
name|seeprom_chip_t
typedef|;
end_typedef

begin_struct
struct|struct
name|seeprom_descriptor
block|{
name|bus_space_tag_t
name|sd_tag
decl_stmt|;
name|bus_space_handle_t
name|sd_bsh
decl_stmt|;
name|bus_size_t
name|sd_control_offset
decl_stmt|;
name|bus_size_t
name|sd_status_offset
decl_stmt|;
name|bus_size_t
name|sd_dataout_offset
decl_stmt|;
name|seeprom_chip_t
name|sd_chip
decl_stmt|;
name|u_int16_t
name|sd_MS
decl_stmt|;
name|u_int16_t
name|sd_RDY
decl_stmt|;
name|u_int16_t
name|sd_CS
decl_stmt|;
name|u_int16_t
name|sd_CK
decl_stmt|;
name|u_int16_t
name|sd_DO
decl_stmt|;
name|u_int16_t
name|sd_DI
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * This function will read count 16-bit words from the serial EEPROM and  * return their value in buf.  The port address of the aic7xxx serial EEPROM  * control register is passed in as offset.  The following parameters are  * also passed in:  *  *   CS  - Chip select  *   CK  - Clock  *   DO  - Data out  *   DI  - Data in  *   RDY - SEEPROM ready  *   MS  - Memory port mode select  *  *  A failed read attempt returns 0, and a successful read returns 1.  */
end_comment

begin_define
define|#
directive|define
name|SEEPROM_INB
parameter_list|(
name|sd
parameter_list|)
define|\
value|bus_space_read_1(sd->sd_tag, sd->sd_bsh, sd->sd_control_offset)
end_define

begin_define
define|#
directive|define
name|SEEPROM_OUTB
parameter_list|(
name|sd
parameter_list|,
name|value
parameter_list|)
define|\
value|bus_space_write_1(sd->sd_tag, sd->sd_bsh, sd->sd_control_offset, value)
end_define

begin_define
define|#
directive|define
name|SEEPROM_STATUS_INB
parameter_list|(
name|sd
parameter_list|)
define|\
value|bus_space_read_1(sd->sd_tag, sd->sd_bsh, sd->sd_status_offset)
end_define

begin_define
define|#
directive|define
name|SEEPROM_DATA_INB
parameter_list|(
name|sd
parameter_list|)
define|\
value|bus_space_read_1(sd->sd_tag, sd->sd_bsh, sd->sd_dataout_offset)
end_define

begin_function_decl
name|int
name|read_seeprom
parameter_list|(
name|struct
name|seeprom_descriptor
modifier|*
name|sd
parameter_list|,
name|u_int16_t
modifier|*
name|buf
parameter_list|,
name|bus_size_t
name|start_addr
parameter_list|,
name|bus_size_t
name|count
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* KERNEL */
end_comment

end_unit

