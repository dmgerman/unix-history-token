begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Interface to the 93C46 serial EEPROM that is used to store BIOS  * settings for the aic7xxx based adaptec SCSI controllers.  It can  * also be used for 93C26 and 93C06 serial EEPROMS.  *  * Copyright (c) 1994, 1995 Justin T. Gibbs.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice immediately at the beginning of the file, without modification,  *    this list of conditions, and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. Absolutely no warranty of function or purpose is made by the author  *    Justin T. Gibbs.  * 4. Modifications may be freely made to this file if the above conditions  *    are met.  *  *      $Id: 93cx6.h,v 1.1 1995/07/04 21:16:12 gibbs Exp $  */
end_comment

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<sys/systm.h>
end_include

begin_comment
comment|/*  * This function will read count 16-bit words from the serial EEPROM and  * return their value in buf.  The port address of the aic7xxx serial EEPROM  * control register is passed in as offset.  The following parameters are  * also passed in:  *  *   CS  - Chip select  *   CK  - Clock  *   DO  - Data out  *   DI  - Data in  *   RDY - SEEPROM ready  *   MS  - Memory port mode select  *  *  A failed read attempt returns 0, and a successful read returns 1.  */
end_comment

begin_function_decl
name|int
name|read_seeprom
parameter_list|(
name|u_long
name|offset
parameter_list|,
name|u_short
modifier|*
name|buf
parameter_list|,
name|u_int
name|start_addr
parameter_list|,
name|int
name|count
parameter_list|,
name|u_short
name|CS
parameter_list|,
name|u_short
name|CK
parameter_list|,
name|u_short
name|DO
parameter_list|,
name|u_short
name|DI
parameter_list|,
name|u_short
name|RDY
parameter_list|,
name|u_short
name|MS
parameter_list|)
function_decl|;
end_function_decl

end_unit

