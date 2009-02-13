begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2006-2007 Daniel Roethlisberger<daniel@roe.ch>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_comment
comment|/*#define	CMX_DEBUG*/
end_comment

begin_comment
comment|/*#define	CMX_INTR*/
end_comment

begin_define
define|#
directive|define
name|CMX_MIN_RDLEN
value|10
end_define

begin_comment
comment|/* min read length */
end_comment

begin_define
define|#
directive|define
name|CMX_MIN_WRLEN
value|5
end_define

begin_comment
comment|/* min write length */
end_comment

begin_define
define|#
directive|define
name|CMX_BUFSZ
value|512
end_define

begin_comment
comment|/* I/O block size */
end_comment

begin_struct
struct|struct
name|cmx_softc
block|{
name|device_t
name|dev
decl_stmt|;
comment|/* pccard device */
name|struct
name|cdev
modifier|*
name|cdev
decl_stmt|;
comment|/* character device */
name|struct
name|resource
modifier|*
name|ioport
decl_stmt|;
comment|/* io port resource descriptor */
name|int
name|ioport_rid
decl_stmt|;
comment|/* io port resource identification */
name|bus_space_tag_t
name|bst
decl_stmt|;
comment|/* bus space tag */
name|bus_space_handle_t
name|bsh
decl_stmt|;
comment|/* bus space handle */
ifdef|#
directive|ifdef
name|CMX_INTR
name|struct
name|resource
modifier|*
name|irq
decl_stmt|;
comment|/* irq resource descriptor */
name|int
name|irq_rid
decl_stmt|;
comment|/* irq resource identification */
name|void
modifier|*
name|ih
decl_stmt|;
comment|/* intr handle */
endif|#
directive|endif
name|struct
name|mtx
name|mtx
decl_stmt|;
comment|/* per-unit lock */
name|struct
name|callout
name|ch
decl_stmt|;
comment|/* callout handle */
name|struct
name|selinfo
name|sel
decl_stmt|;
comment|/* select/poll queue handle */
name|int
name|open
decl_stmt|;
comment|/* is chardev open? */
name|int
name|polling
decl_stmt|;
comment|/* are we polling? */
name|int
name|dying
decl_stmt|;
comment|/* are we detaching? */
name|unsigned
name|long
name|timeout
decl_stmt|;
comment|/* response timeout */
name|uint8_t
name|buf
index|[
name|CMX_BUFSZ
index|]
decl_stmt|;
comment|/* read/write buffer */
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|devclass_t
name|cmx_devclass
decl_stmt|;
end_decl_stmt

begin_function_decl
name|void
name|cmx_init_softc
parameter_list|(
name|device_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|cmx_alloc_resources
parameter_list|(
name|device_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|cmx_release_resources
parameter_list|(
name|device_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|cmx_attach
parameter_list|(
name|device_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|cmx_detach
parameter_list|(
name|device_t
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|CMX_READ_1
parameter_list|(
name|sc
parameter_list|,
name|off
parameter_list|)
define|\
value|(bus_space_read_1((sc)->bst, (sc)->bsh, off))
end_define

begin_define
define|#
directive|define
name|CMX_WRITE_1
parameter_list|(
name|sc
parameter_list|,
name|off
parameter_list|,
name|val
parameter_list|)
define|\
value|(bus_space_write_1((sc)->bst, (sc)->bsh, off, val))
end_define

begin_define
define|#
directive|define
name|cmx_read_BSR
parameter_list|(
name|sc
parameter_list|)
define|\
value|CMX_READ_1(sc, REG_OFFSET_BSR)
end_define

begin_define
define|#
directive|define
name|cmx_write_BSR
parameter_list|(
name|sc
parameter_list|,
name|val
parameter_list|)
define|\
value|CMX_WRITE_1(sc, REG_OFFSET_BSR, val)
end_define

begin_define
define|#
directive|define
name|cmx_read_SCR
parameter_list|(
name|sc
parameter_list|)
define|\
value|CMX_READ_1(sc, REG_OFFSET_SCR)
end_define

begin_define
define|#
directive|define
name|cmx_write_SCR
parameter_list|(
name|sc
parameter_list|,
name|val
parameter_list|)
define|\
value|CMX_WRITE_1(sc, REG_OFFSET_SCR, val)
end_define

begin_define
define|#
directive|define
name|cmx_read_DTR
parameter_list|(
name|sc
parameter_list|)
define|\
value|CMX_READ_1(sc, REG_OFFSET_DTR)
end_define

begin_define
define|#
directive|define
name|cmx_write_DTR
parameter_list|(
name|sc
parameter_list|,
name|val
parameter_list|)
define|\
value|CMX_WRITE_1(sc, REG_OFFSET_DTR, val)
end_define

begin_define
define|#
directive|define
name|cmx_test
parameter_list|(
name|byte
parameter_list|,
name|flags
parameter_list|,
name|test
parameter_list|)
define|\
value|(((byte)& (flags)) == ((test) ? (flags) : 0))
end_define

begin_define
define|#
directive|define
name|cmx_test_BSR
parameter_list|(
name|sc
parameter_list|,
name|flags
parameter_list|,
name|test
parameter_list|)
define|\
value|cmx_test(cmx_read_BSR(sc), flags, test)
end_define

begin_define
define|#
directive|define
name|CMX_LOCK
parameter_list|(
name|sc
parameter_list|)
value|mtx_lock(&(sc)->mtx)
end_define

begin_define
define|#
directive|define
name|CMX_UNLOCK
parameter_list|(
name|sc
parameter_list|)
value|mtx_unlock(&(sc)->mtx)
end_define

begin_define
define|#
directive|define
name|CMX_LOCK_ASSERT
parameter_list|(
name|sc
parameter_list|,
name|what
parameter_list|)
value|mtx_assert(&(sc)->mtx, (what))
end_define

end_unit

