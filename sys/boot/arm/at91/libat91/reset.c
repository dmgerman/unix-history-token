begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2006 M. Warner Losh.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_include
include|#
directive|include
file|"at91rm9200.h"
end_include

begin_include
include|#
directive|include
file|"lib.h"
end_include

begin_comment
comment|/*  * void reset()  *   * Forces a reset of the system.  Uses watchdog timer of '1', which  * corresponds to 128 / SLCK seconds (SLCK is 32,768 Hz, so 128/32768 is  * 1 / 256 ~= 5.4ms  */
end_comment

begin_function
name|void
name|reset
parameter_list|(
name|void
parameter_list|)
block|{
comment|// The following should effect a reset.
name|AT91C_BASE_ST
operator|->
name|ST_WDMR
operator|=
literal|1
operator||
name|AT91C_ST_RSTEN
expr_stmt|;
name|AT91C_BASE_ST
operator|->
name|ST_CR
operator|=
name|AT91C_ST_WDRST
expr_stmt|;
block|}
end_function

begin_comment
comment|/*  * void start_wdog()  *  * Starts a watchdog timer.  We force the boot process to get to the point  * it can kick the watch dog part of the ST part for the OS's driver.  */
end_comment

begin_function
name|void
name|start_wdog
parameter_list|(
name|int
name|n
parameter_list|)
block|{
comment|// The following should effect a reset after N seconds.
name|AT91C_BASE_ST
operator|->
name|ST_WDMR
operator|=
operator|(
name|n
operator|*
operator|(
literal|32768
operator|/
literal|128
operator|)
operator|)
operator||
name|AT91C_ST_RSTEN
expr_stmt|;
name|AT91C_BASE_ST
operator|->
name|ST_CR
operator|=
name|AT91C_ST_WDRST
expr_stmt|;
block|}
end_function

end_unit

