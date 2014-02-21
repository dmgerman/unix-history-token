begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2010 Aleksandr Rybalko.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_RT305X_GPIO_H_
end_ifndef

begin_define
define|#
directive|define
name|_RT305X_GPIO_H_
end_define

begin_define
define|#
directive|define
name|NGPIO
value|52
end_define

begin_define
define|#
directive|define
name|RGMII_GPIO_MODE_MASK
value|(0x0fffULL<<40)
end_define

begin_define
define|#
directive|define
name|SDRAM_GPIO_MODE_MASK
value|(0xffffULL<<24)
end_define

begin_define
define|#
directive|define
name|MDIO_GPIO_MODE_MASK
value|(0x0003ULL<<22)
end_define

begin_define
define|#
directive|define
name|JTAG_GPIO_MODE_MASK
value|(0x001fULL<<17)
end_define

begin_define
define|#
directive|define
name|UARTL_GPIO_MODE_MASK
value|(0x0003ULL<<15)
end_define

begin_define
define|#
directive|define
name|UARTF_GPIO_MODE_MASK
value|(0x00ffULL<<7)
end_define

begin_define
define|#
directive|define
name|SPI_GPIO_MODE_MASK
value|(0x000fULL<<3)
end_define

begin_define
define|#
directive|define
name|I2C_GPIO_MODE_MASK
value|(0x0003ULL<<1)
end_define

begin_define
define|#
directive|define
name|GPIO23_00_INT
value|0x00
end_define

begin_comment
comment|/* Programmed I/O Int Status */
end_comment

begin_define
define|#
directive|define
name|GPIO23_00_EDGE
value|0x04
end_define

begin_comment
comment|/* Programmed I/O Edge Status */
end_comment

begin_define
define|#
directive|define
name|GPIO23_00_RENA
value|0x08
end_define

begin_comment
comment|/* Programmed I/O Int on Rising */
end_comment

begin_define
define|#
directive|define
name|GPIO23_00_FENA
value|0x0C
end_define

begin_comment
comment|/* Programmed I/O Int on Falling */
end_comment

begin_define
define|#
directive|define
name|GPIO23_00_DATA
value|0x20
end_define

begin_comment
comment|/* Programmed I/O Data */
end_comment

begin_define
define|#
directive|define
name|GPIO23_00_DIR
value|0x24
end_define

begin_comment
comment|/* Programmed I/O Direction */
end_comment

begin_define
define|#
directive|define
name|GPIO23_00_POL
value|0x28
end_define

begin_comment
comment|/* Programmed I/O Pin Polarity */
end_comment

begin_define
define|#
directive|define
name|GPIO23_00_SET
value|0x2C
end_define

begin_comment
comment|/* Set PIO Data Bit */
end_comment

begin_define
define|#
directive|define
name|GPIO23_00_RESET
value|0x30
end_define

begin_comment
comment|/* Clear PIO Data bit */
end_comment

begin_define
define|#
directive|define
name|GPIO23_00_TOG
value|0x34
end_define

begin_comment
comment|/* Toggle PIO Data bit */
end_comment

begin_define
define|#
directive|define
name|GPIO39_24_INT
value|0x38
end_define

begin_define
define|#
directive|define
name|GPIO39_24_EDGE
value|0x3c
end_define

begin_define
define|#
directive|define
name|GPIO39_24_RENA
value|0x40
end_define

begin_define
define|#
directive|define
name|GPIO39_24_FENA
value|0x44
end_define

begin_define
define|#
directive|define
name|GPIO39_24_DATA
value|0x48
end_define

begin_define
define|#
directive|define
name|GPIO39_24_DIR
value|0x4c
end_define

begin_define
define|#
directive|define
name|GPIO39_24_POL
value|0x50
end_define

begin_define
define|#
directive|define
name|GPIO39_24_SET
value|0x54
end_define

begin_define
define|#
directive|define
name|GPIO39_24_RESET
value|0x58
end_define

begin_define
define|#
directive|define
name|GPIO39_24_TOG
value|0x5c
end_define

begin_define
define|#
directive|define
name|GPIO51_40_INT
value|0x60
end_define

begin_define
define|#
directive|define
name|GPIO51_40_EDGE
value|0x64
end_define

begin_define
define|#
directive|define
name|GPIO51_40_RENA
value|0x68
end_define

begin_define
define|#
directive|define
name|GPIO51_40_FENA
value|0x6C
end_define

begin_define
define|#
directive|define
name|GPIO51_40_DATA
value|0x70
end_define

begin_define
define|#
directive|define
name|GPIO51_40_DIR
value|0x74
end_define

begin_define
define|#
directive|define
name|GPIO51_40_POL
value|0x78
end_define

begin_define
define|#
directive|define
name|GPIO51_40_SET
value|0x7C
end_define

begin_define
define|#
directive|define
name|GPIO51_40_RESET
value|0x80
end_define

begin_define
define|#
directive|define
name|GPIO51_40_TOG
value|0x84
end_define

begin_define
define|#
directive|define
name|GPIO_REG
parameter_list|(
name|g
parameter_list|,
name|n
parameter_list|)
define|\
value|((g<24)?(GPIO23_00_##n):(g<40)?(GPIO39_24_##n):(GPIO51_40_##n))
end_define

begin_define
define|#
directive|define
name|GPIO_MASK
parameter_list|(
name|g
parameter_list|)
define|\
value|((g<24)?(1<<g):(g<40)?(1<<(g-24)):(1<<(g-40)))
end_define

begin_define
define|#
directive|define
name|GPIO_BIT_SHIFT
parameter_list|(
name|g
parameter_list|)
value|((g<24)?(g):(g<40)?(g-24):(g-40))
end_define

begin_define
define|#
directive|define
name|GPIO_READ
parameter_list|(
name|r
parameter_list|,
name|g
parameter_list|,
name|n
parameter_list|)
define|\
value|bus_read_4(r->gpio_mem_res, GPIO_REG(g, n))
end_define

begin_define
define|#
directive|define
name|GPIO_WRITE
parameter_list|(
name|r
parameter_list|,
name|g
parameter_list|,
name|n
parameter_list|,
name|v
parameter_list|)
define|\
value|bus_write_4(r->gpio_mem_res, GPIO_REG(g, n), v)
end_define

begin_define
define|#
directive|define
name|GPIO_READ_ALL
parameter_list|(
name|r
parameter_list|,
name|n
parameter_list|)
define|\
value|(((uint64_t)bus_read_4(r->gpio_mem_res, GPIO23_00_##n)) |	\ 	(((uint64_t)bus_read_4(r->gpio_mem_res, GPIO39_24_##n))<< 24) |\ 	(((uint64_t)bus_read_4(r->gpio_mem_res, GPIO51_40_##n))<< 40))
end_define

begin_define
define|#
directive|define
name|GPIO_WRITE_ALL
parameter_list|(
name|r
parameter_list|,
name|n
parameter_list|,
name|v
parameter_list|)
define|\
value|{bus_write_4(r->gpio_mem_res,GPIO23_00_##n, v&0x00ffffff);\ 	bus_write_4(r->gpio_mem_res, GPIO39_24_##n, (v>>24)&0x0000ffff);\ 	bus_write_4(r->gpio_mem_res, GPIO51_40_##n, (v>>40)&0x00000fff);}
end_define

begin_define
define|#
directive|define
name|GPIO_BIT_CLR
parameter_list|(
name|r
parameter_list|,
name|g
parameter_list|,
name|n
parameter_list|)
define|\
value|bus_write_4(r->gpio_mem_res, GPIO_REG(g, n), 			\ 	    bus_read_4(r->gpio_mem_res, GPIO_REG(g, n))& ~GPIO_MASK(g))
end_define

begin_define
define|#
directive|define
name|GPIO_BIT_SET
parameter_list|(
name|r
parameter_list|,
name|g
parameter_list|,
name|n
parameter_list|)
define|\
value|bus_write_4(r->gpio_mem_res, GPIO_REG(g, n), 			\ 	    bus_read_4(r->gpio_mem_res, GPIO_REG(g, n)) | GPIO_MASK(g))
end_define

begin_define
define|#
directive|define
name|GPIO_BIT_GET
parameter_list|(
name|r
parameter_list|,
name|g
parameter_list|,
name|n
parameter_list|)
define|\
value|((bus_read_4(r->gpio_mem_res, GPIO_REG(g, n))>> 		\ 	    GPIO_BIT_SHIFT(g))& 1)
end_define

begin_define
define|#
directive|define
name|GPIO_LOCK
parameter_list|(
name|_sc
parameter_list|)
value|mtx_lock(&(_sc)->gpio_mtx)
end_define

begin_define
define|#
directive|define
name|GPIO_UNLOCK
parameter_list|(
name|_sc
parameter_list|)
value|mtx_unlock(&(_sc)->gpio_mtx)
end_define

begin_define
define|#
directive|define
name|GPIO_LOCK_ASSERT
parameter_list|(
name|_sc
parameter_list|)
value|mtx_assert(&(_sc)->gpio_mtx, MA_OWNED)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _RT305X_GPIO_H_ */
end_comment

end_unit

