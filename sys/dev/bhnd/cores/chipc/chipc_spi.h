begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2016 Michael Zhilin<mizhka@gmail.com>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer,  *    without modification.  * 2. Redistributions in binary form must reproduce at minimum a disclaimer  *    similar to the "NO WARRANTY" disclaimer below ("Disclaimer") and any  *    redistribution must be conditioned upon including a substantially  *    similar Disclaimer requirement for further binary redistribution.  *  * NO WARRANTY  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT  * LIMITED TO, THE IMPLIED WARRANTIES OF NONINFRINGEMENT, MERCHANTIBILITY  * AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL  * THE COPYRIGHT HOLDERS OR CONTRIBUTORS BE LIABLE FOR SPECIAL, EXEMPLARY,  * OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER  * IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF  * THE POSSIBILITY OF SUCH DAMAGES.  */
end_comment

begin_comment
comment|/*  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_BHND_CORES_CHIPC_CHIPC_SPI_H_
end_ifndef

begin_define
define|#
directive|define
name|_BHND_CORES_CHIPC_CHIPC_SPI_H_
end_define

begin_define
define|#
directive|define
name|CHIPC_SPI_MAXTRIES
value|1000
end_define

begin_define
define|#
directive|define
name|CHIPC_SPI_ACTION_INPUT
value|1
end_define

begin_define
define|#
directive|define
name|CHIPC_SPI_ACTION_OUTPUT
value|2
end_define

begin_define
define|#
directive|define
name|CHIPC_SPI_FLASHCTL
value|0x00
end_define

begin_define
define|#
directive|define
name|CHIPC_SPI_FLASHCTL_OPCODE
value|0x000000ff
end_define

begin_define
define|#
directive|define
name|CHIPC_SPI_FLASHCTL_ACTION
value|0x00000700
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|/*  * We don't use action at all. Experimentaly found, that  *  action 0 - read current MISO byte to data register (interactive mode)  *  action 1 = read 2nd byte to data register  *  action 2 = read 4th byte to data register (surprise! see action 6)  *  action 3 = read 5th byte to data register  *  action 4 = read bytes 5-8 to data register in swapped order  *  action 5 = read bytes 9-12 to data register in swapped order  *  action 6 = read 3rd byte to data register  *  action 7 = read bytes 6-9 to data register in swapped order  * It may be wrong if CS bit is 1.  * If CS bit is 1, you should write cmd / data to opcode byte-to-byte.  */
end_comment

begin_define
define|#
directive|define
name|CHIPC_SPI_FLASHCTL_CSACTIVE
value|0x00001000
end_define

begin_define
define|#
directive|define
name|CHIPC_SPI_FLASHCTL_START
value|0x80000000
end_define

begin_comment
comment|//same as BUSY
end_comment

begin_define
define|#
directive|define
name|CHIPC_SPI_FLASHCTL_BUSY
value|0x80000000
end_define

begin_comment
comment|//same as BUSY
end_comment

begin_define
define|#
directive|define
name|CHIPC_SPI_FLASHADDR
value|0x04
end_define

begin_define
define|#
directive|define
name|CHIPC_SPI_FLASHDATA
value|0x08
end_define

begin_struct
struct|struct
name|chipc_spi_softc
block|{
name|device_t
name|sc_dev
decl_stmt|;
name|struct
name|resource
modifier|*
name|sc_res
decl_stmt|;
comment|/**< SPI registers */
name|int
name|sc_rid
decl_stmt|;
name|struct
name|resource
modifier|*
name|sc_flash_res
decl_stmt|;
comment|/**< flash shadow */
name|int
name|sc_flash_rid
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* register space access macros */
end_comment

begin_define
define|#
directive|define
name|SPI_BARRIER_WRITE
parameter_list|(
name|sc
parameter_list|)
value|bus_barrier((sc)->sc_res, 0, 0, 	\ 				    BUS_SPACE_BARRIER_WRITE)
end_define

begin_define
define|#
directive|define
name|SPI_BARRIER_READ
parameter_list|(
name|sc
parameter_list|)
value|bus_barrier((sc)->sc_res, 0, 0, 	\ 				    BUS_SPACE_BARRIER_READ)
end_define

begin_define
define|#
directive|define
name|SPI_BARRIER_RW
parameter_list|(
name|sc
parameter_list|)
value|bus_barrier((sc)->sc_res, 0, 0, 	\ 			            BUS_SPACE_BARRIER_READ |		\ 			            BUS_SPACE_BARRIER_WRITE)
end_define

begin_define
define|#
directive|define
name|SPI_WRITE
parameter_list|(
name|sc
parameter_list|,
name|reg
parameter_list|,
name|val
parameter_list|)
value|bus_write_4(sc->sc_res, (reg), (val));
end_define

begin_define
define|#
directive|define
name|SPI_READ
parameter_list|(
name|sc
parameter_list|,
name|reg
parameter_list|)
value|bus_read_4(sc->sc_res, (reg))
end_define

begin_define
define|#
directive|define
name|SPI_SET_BITS
parameter_list|(
name|sc
parameter_list|,
name|reg
parameter_list|,
name|bits
parameter_list|)
define|\
value|SPI_WRITE(sc, reg, SPI_READ(sc, (reg)) | (bits))
end_define

begin_define
define|#
directive|define
name|SPI_CLEAR_BITS
parameter_list|(
name|sc
parameter_list|,
name|reg
parameter_list|,
name|bits
parameter_list|)
define|\
value|SPI_WRITE(sc, reg, SPI_READ(sc, (reg))& ~(bits))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _BHND_CORES_CHIPC_CHIPC_SPI_H_ */
end_comment

end_unit

