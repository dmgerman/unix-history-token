begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright 2014 Luiz Otavio O Souza<loos@freebsd.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_TI_ADCVAR_H_
end_ifndef

begin_define
define|#
directive|define
name|_TI_ADCVAR_H_
end_define

begin_define
define|#
directive|define
name|TI_ADC_NPINS
value|8
end_define

begin_define
define|#
directive|define
name|ADC_READ4
parameter_list|(
name|_sc
parameter_list|,
name|reg
parameter_list|)
value|bus_read_4((_sc)->sc_mem_res, reg)
end_define

begin_define
define|#
directive|define
name|ADC_WRITE4
parameter_list|(
name|_sc
parameter_list|,
name|reg
parameter_list|,
name|value
parameter_list|)
define|\
value|bus_write_4((_sc)->sc_mem_res, reg, value)
end_define

begin_struct
struct|struct
name|ti_adc_softc
block|{
name|device_t
name|sc_dev
decl_stmt|;
name|int
name|sc_last_state
decl_stmt|;
name|struct
name|mtx
name|sc_mtx
decl_stmt|;
name|struct
name|resource
modifier|*
name|sc_mem_res
decl_stmt|;
name|struct
name|resource
modifier|*
name|sc_irq_res
decl_stmt|;
name|void
modifier|*
name|sc_intrhand
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|ti_adc_input
block|{
name|int32_t
name|enable
decl_stmt|;
comment|/* input enabled */
name|int32_t
name|samples
decl_stmt|;
comment|/* samples average */
name|int32_t
name|input
decl_stmt|;
comment|/* input number */
name|int32_t
name|value
decl_stmt|;
comment|/* raw converted value */
name|uint32_t
name|stepconfig
decl_stmt|;
comment|/* step config register */
name|uint32_t
name|stepdelay
decl_stmt|;
comment|/* step delay register */
name|struct
name|ti_adc_softc
modifier|*
name|sc
decl_stmt|;
comment|/* pointer to adc softc */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|TI_ADC_LOCK
parameter_list|(
name|_sc
parameter_list|)
define|\
value|mtx_lock(&(_sc)->sc_mtx)
end_define

begin_define
define|#
directive|define
name|TI_ADC_UNLOCK
parameter_list|(
name|_sc
parameter_list|)
define|\
value|mtx_unlock(&(_sc)->sc_mtx)
end_define

begin_define
define|#
directive|define
name|TI_ADC_LOCK_INIT
parameter_list|(
name|_sc
parameter_list|)
define|\
value|mtx_init(&_sc->sc_mtx, device_get_nameunit(_sc->sc_dev), \ 	    "ti_adc", MTX_DEF)
end_define

begin_define
define|#
directive|define
name|TI_ADC_LOCK_DESTROY
parameter_list|(
name|_sc
parameter_list|)
define|\
value|mtx_destroy(&_sc->sc_mtx);
end_define

begin_define
define|#
directive|define
name|TI_ADC_LOCK_ASSERT
parameter_list|(
name|_sc
parameter_list|)
define|\
value|mtx_assert(&(_sc)->sc_mtx, MA_OWNED)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _TI_ADCVAR_H_ */
end_comment

end_unit

