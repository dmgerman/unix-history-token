begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Interface to the 93C46 serial EEPROM that is used to store BIOS  * settings for the aic7xxx based adaptec SCSI controllers.  It can  * also be used for 93C26 and 93C06 serial EEPROMS.  *  * Copyright (c) 1994, 1995 Justin T. Gibbs.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice immediately at the beginning of the file, without modification,  *    this list of conditions, and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. Absolutely no warranty of function or purpose is made by the author  *    Justin T. Gibbs.  * 4. Modifications may be freely made to this file if the above conditions  *    are met.  *  * $FreeBSD$  */
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
if|#
directive|if
name|defined
argument_list|(
name|__FreeBSD__
argument_list|)
name|u_int32_t
name|sd_iobase
decl_stmt|;
specifier|volatile
name|u_int8_t
modifier|*
name|sd_maddr
decl_stmt|;
elif|#
directive|elif
name|defined
argument_list|(
name|__NetBSD__
argument_list|)
name|bus_chipset_tag_t
name|sd_bc
decl_stmt|;
name|bus_io_handle_t
name|sd_ioh
decl_stmt|;
name|bus_io_size_t
name|sd_offset
decl_stmt|;
endif|#
directive|endif
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

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__FreeBSD__
argument_list|)
end_if

begin_define
define|#
directive|define
name|SEEPROM_INB
parameter_list|(
name|sd
parameter_list|)
define|\
value|(((sd)->sd_maddr != NULL) ?		\ 		*((sd)->sd_maddr) :		\ 		inb((sd)->sd_iobase))
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
value|(((sd)->sd_maddr != NULL) ?		\ 		*((sd)->sd_maddr) = (value) :	\ 		outb((sd)->sd_iobase, (value)))
end_define

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|__NetBSD__
argument_list|)
end_elif

begin_define
define|#
directive|define
name|SEEPROM_INB
parameter_list|(
name|sd
parameter_list|)
define|\
value|bus_io_read_1(sd->sd_bc, sd->sd_ioh, sd->sd_offset)
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
value|bus_io_write_1(sd->sd_bc, sd->sd_ioh, sd->sd_offset, value)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__FreeBSD__
argument_list|)
end_if

begin_decl_stmt
name|int
name|read_seeprom
name|__P
argument_list|(
operator|(
expr|struct
name|seeprom_descriptor
operator|*
name|sd
operator|,
name|u_int16_t
operator|*
name|buf
operator|,
name|u_int
name|start_addr
operator|,
name|u_int
name|count
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|__NetBSD__
argument_list|)
end_elif

begin_decl_stmt
name|int
name|read_seeprom
name|__P
argument_list|(
operator|(
expr|struct
name|seeprom_descriptor
operator|*
name|sd
operator|,
name|u_int16_t
operator|*
name|buf
operator|,
name|bus_io_size_t
name|start_addr
operator|,
name|bus_io_size_t
name|count
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

