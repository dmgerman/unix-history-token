begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2005 Poul-Henning Kamp<phk@FreeBSD.org>  * Copyright (c) 2010 Joerg Wunsch<joerg@FreeBSD.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  *  * Locating an actual µPD7210 data book has proven quite impossible for me.  * There are a fair number of newer chips which are supersets of the µPD7210  * but they are particular eager to comprehensively mark what the extensions  * are and what is in the base set.  Some even give the registers and their  * bits new names.  *  * The following information is based on a description of the µPD7210 found  * in an old manual for a VME board which used the chip.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_DEV_IEEE488_UPD7210_H_
end_ifndef

begin_define
define|#
directive|define
name|_DEV_IEEE488_UPD7210_H_
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_struct_decl
struct_decl|struct
name|upd7210
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|ibfoo
struct_decl|;
end_struct_decl

begin_comment
comment|/* upd7210 interface definitions for HW drivers */
end_comment

begin_typedef
typedef|typedef
name|int
name|upd7210_irq_t
parameter_list|(
name|struct
name|upd7210
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_typedef

begin_struct
struct|struct
name|upd7210
block|{
name|struct
name|resource
modifier|*
name|reg_res
index|[
literal|8
index|]
decl_stmt|;
name|struct
name|resource
modifier|*
name|irq_clear_res
decl_stmt|;
name|int
name|dmachan
decl_stmt|;
name|int
name|unit
decl_stmt|;
comment|/* private stuff */
name|struct
name|mtx
name|mutex
decl_stmt|;
name|uint8_t
name|rreg
index|[
literal|8
index|]
decl_stmt|;
name|uint8_t
name|wreg
index|[
literal|8
operator|+
literal|8
index|]
decl_stmt|;
name|upd7210_irq_t
modifier|*
name|irq
decl_stmt|;
name|int
name|busy
decl_stmt|;
name|u_char
modifier|*
name|buf
decl_stmt|;
name|size_t
name|bufsize
decl_stmt|;
name|u_int
name|buf_wp
decl_stmt|;
name|u_int
name|buf_rp
decl_stmt|;
name|struct
name|cdev
modifier|*
name|cdev
decl_stmt|;
name|struct
name|ibfoo
modifier|*
name|ibfoo
decl_stmt|;
block|}
struct|;
end_struct

begin_ifdef
ifdef|#
directive|ifdef
name|UPD7210_HW_DRIVER
end_ifdef

begin_function_decl
name|void
name|upd7210intr
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|upd7210attach
parameter_list|(
name|struct
name|upd7210
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|upd7210detach
parameter_list|(
name|struct
name|upd7210
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|UPD7210_SW_DRIVER
end_ifdef

begin_comment
comment|/* upd7210 hardware definitions. */
end_comment

begin_comment
comment|/* Write registers */
end_comment

begin_enum
enum|enum
name|upd7210_wreg
block|{
name|CDOR
init|=
literal|0
block|,
comment|/* Command/Data Out Register	*/
name|IMR1
init|=
literal|1
block|,
comment|/* Interrupt Mask Register 1	*/
name|IMR2
init|=
literal|2
block|,
comment|/* Interrupt Mask Register 2	*/
name|SPMR
init|=
literal|3
block|,
comment|/* Serial Poll Mode Register	*/
name|ADMR
init|=
literal|4
block|,
comment|/* ADdress Mode Register	*/
name|AUXMR
init|=
literal|5
block|,
comment|/* AUXilliary Mode Register	*/
name|ICR
init|=
literal|5
block|,
comment|/* Internal Counter Register	*/
name|PPR
init|=
literal|5
block|,
comment|/* Parallel Poll Register	*/
name|AUXRA
init|=
literal|5
block|,
comment|/* AUXilliary Register A	*/
name|AUXRB
init|=
literal|5
block|,
comment|/* AUXilliary Register B	*/
name|AUXRE
init|=
literal|5
block|,
comment|/* AUXilliary Register E	*/
name|ADR
init|=
literal|6
block|,
comment|/* ADdress Register		*/
name|EOSR
init|=
literal|7
block|,
comment|/* End-Of-String Register	*/
block|}
enum|;
end_enum

begin_comment
comment|/* Read registers */
end_comment

begin_enum
enum|enum
name|upd7210_rreg
block|{
name|DIR
init|=
literal|0
block|,
comment|/* Data In Register		*/
name|ISR1
init|=
literal|1
block|,
comment|/* Interrupt Status Register 1	*/
name|ISR2
init|=
literal|2
block|,
comment|/* Interrupt Status Register 2	*/
name|SPSR
init|=
literal|3
block|,
comment|/* Serial Poll Status Register	*/
name|ADSR
init|=
literal|4
block|,
comment|/* ADdress Status Register	*/
name|CPTR
init|=
literal|5
block|,
comment|/* Command Pass Though Register	*/
name|ADR0
init|=
literal|6
block|,
comment|/* ADdress Register 0		*/
name|ADR1
init|=
literal|7
block|,
comment|/* ADdress Register 1		*/
block|}
enum|;
end_enum

begin_comment
comment|/* Bits for ISR1 and IMR1 */
end_comment

begin_define
define|#
directive|define
name|IXR1_DI
value|(1<< 0)
end_define

begin_comment
comment|/* Data In			*/
end_comment

begin_define
define|#
directive|define
name|IXR1_DO
value|(1<< 1)
end_define

begin_comment
comment|/* Data Out			*/
end_comment

begin_define
define|#
directive|define
name|IXR1_ERR
value|(1<< 2)
end_define

begin_comment
comment|/* Error			*/
end_comment

begin_define
define|#
directive|define
name|IXR1_DEC
value|(1<< 3)
end_define

begin_comment
comment|/* Device Clear			*/
end_comment

begin_define
define|#
directive|define
name|IXR1_ENDRX
value|(1<< 4)
end_define

begin_comment
comment|/* End Received			*/
end_comment

begin_define
define|#
directive|define
name|IXR1_DET
value|(1<< 5)
end_define

begin_comment
comment|/* Device Execute Trigger	*/
end_comment

begin_define
define|#
directive|define
name|IXR1_APT
value|(1<< 6)
end_define

begin_comment
comment|/* Address Pass-Through		*/
end_comment

begin_define
define|#
directive|define
name|IXR1_CPT
value|(1<< 7)
end_define

begin_comment
comment|/* Command Pass-Through		*/
end_comment

begin_comment
comment|/* Bits for ISR2 and IMR2 */
end_comment

begin_define
define|#
directive|define
name|IXR2_ADSC
value|(1<< 0)
end_define

begin_comment
comment|/* Addressed Status Change	*/
end_comment

begin_define
define|#
directive|define
name|IXR2_REMC
value|(1<< 1)
end_define

begin_comment
comment|/* Remote Change		*/
end_comment

begin_define
define|#
directive|define
name|IXR2_LOKC
value|(1<< 2)
end_define

begin_comment
comment|/* Lockout Change		*/
end_comment

begin_define
define|#
directive|define
name|IXR2_CO
value|(1<< 3)
end_define

begin_comment
comment|/* Command Out			*/
end_comment

begin_define
define|#
directive|define
name|ISR2_REM
value|(1<< 4)
end_define

begin_comment
comment|/* Remove			*/
end_comment

begin_define
define|#
directive|define
name|IMR2_DMAI
value|(1<< 4)
end_define

begin_comment
comment|/* DMA In Enable		*/
end_comment

begin_define
define|#
directive|define
name|ISR2_LOK
value|(1<< 5)
end_define

begin_comment
comment|/* Lockout			*/
end_comment

begin_define
define|#
directive|define
name|IMR2_DMAO
value|(1<< 5)
end_define

begin_comment
comment|/* DMA Out Enable		*/
end_comment

begin_define
define|#
directive|define
name|IXR2_SRQI
value|(1<< 6)
end_define

begin_comment
comment|/* Service Request Input	*/
end_comment

begin_define
define|#
directive|define
name|ISR2_INT
value|(1<< 7)
end_define

begin_comment
comment|/* Interrupt			*/
end_comment

begin_define
define|#
directive|define
name|SPSR_PEND
value|(1<< 6)
end_define

begin_comment
comment|/* Pending			*/
end_comment

begin_define
define|#
directive|define
name|SPMR_RSV
value|(1<< 6)
end_define

begin_comment
comment|/* Request SerVice		*/
end_comment

begin_define
define|#
directive|define
name|ADSR_MJMN
value|(1<< 0)
end_define

begin_comment
comment|/* MaJor MiNor			*/
end_comment

begin_define
define|#
directive|define
name|ADSR_TA
value|(1<< 1)
end_define

begin_comment
comment|/* Talker Active		*/
end_comment

begin_define
define|#
directive|define
name|ADSR_LA
value|(1<< 2)
end_define

begin_comment
comment|/* Listener Active		*/
end_comment

begin_define
define|#
directive|define
name|ADSR_TPAS
value|(1<< 3)
end_define

begin_comment
comment|/* Talker Primary Addr. State	*/
end_comment

begin_define
define|#
directive|define
name|ADSR_LPAS
value|(1<< 4)
end_define

begin_comment
comment|/* Listener Primary Addr. State	*/
end_comment

begin_define
define|#
directive|define
name|ADSR_SPMS
value|(1<< 5)
end_define

begin_comment
comment|/* Serial Poll Mode State	*/
end_comment

begin_define
define|#
directive|define
name|ADSR_ATN
value|(1<< 6)
end_define

begin_comment
comment|/* Attention			*/
end_comment

begin_define
define|#
directive|define
name|ADSR_CIC
value|(1<< 7)
end_define

begin_comment
comment|/* Controller In Charge		*/
end_comment

begin_define
define|#
directive|define
name|ADMR_ADM0
value|(1<< 0)
end_define

begin_comment
comment|/* Address Mode 0		*/
end_comment

begin_define
define|#
directive|define
name|ADMR_ADM1
value|(1<< 1)
end_define

begin_comment
comment|/* Address Mode 1		*/
end_comment

begin_define
define|#
directive|define
name|ADMR_TRM0
value|(1<< 4)
end_define

begin_comment
comment|/* Transmit/Receive Mode 0	*/
end_comment

begin_define
define|#
directive|define
name|ADMR_TRM1
value|(1<< 5)
end_define

begin_comment
comment|/* Transmit/Receive Mode 1	*/
end_comment

begin_define
define|#
directive|define
name|ADMR_LON
value|(1<< 6)
end_define

begin_comment
comment|/* Listen Only			*/
end_comment

begin_define
define|#
directive|define
name|ADMR_TON
value|(1<< 7)
end_define

begin_comment
comment|/* Talk Only			*/
end_comment

begin_comment
comment|/* Constant part of overloaded write registers */
end_comment

begin_define
define|#
directive|define
name|C_ICR
value|0x20
end_define

begin_define
define|#
directive|define
name|C_PPR
value|0x60
end_define

begin_define
define|#
directive|define
name|C_AUXA
value|0x80
end_define

begin_define
define|#
directive|define
name|C_AUXB
value|0xa0
end_define

begin_define
define|#
directive|define
name|C_AUXE
value|0xc0
end_define

begin_define
define|#
directive|define
name|AUXMR_PON
value|0x00
end_define

begin_comment
comment|/* Immediate Execute pon	*/
end_comment

begin_define
define|#
directive|define
name|AUXMR_CPP
value|0x01
end_define

begin_comment
comment|/* Clear Parallel Poll		*/
end_comment

begin_define
define|#
directive|define
name|AUXMR_CRST
value|0x02
end_define

begin_comment
comment|/* Chip Reset			*/
end_comment

begin_define
define|#
directive|define
name|AUXMR_RFD
value|0x03
end_define

begin_comment
comment|/* Finish Handshake		*/
end_comment

begin_define
define|#
directive|define
name|AUXMR_TRIG
value|0x04
end_define

begin_comment
comment|/* Trigger			*/
end_comment

begin_define
define|#
directive|define
name|AUXMR_RTL
value|0x05
end_define

begin_comment
comment|/* Return to local		*/
end_comment

begin_define
define|#
directive|define
name|AUXMR_SEOI
value|0x06
end_define

begin_comment
comment|/* Send EOI			*/
end_comment

begin_define
define|#
directive|define
name|AUXMR_NVSA
value|0x07
end_define

begin_comment
comment|/* Non-Valid Secondary cmd/addr	*/
end_comment

begin_comment
comment|/* 0x08 undefined/unknown	*/
end_comment

begin_define
define|#
directive|define
name|AUXMR_SPP
value|0x09
end_define

begin_comment
comment|/* Set Parallel Poll		*/
end_comment

begin_comment
comment|/* 0x0a undefined/unknown	*/
end_comment

begin_comment
comment|/* 0x0b undefined/unknown	*/
end_comment

begin_comment
comment|/* 0x0c undefined/unknown	*/
end_comment

begin_comment
comment|/* 0x0d undefined/unknown	*/
end_comment

begin_comment
comment|/* 0x0e undefined/unknown	*/
end_comment

begin_define
define|#
directive|define
name|AUXMR_VSA
value|0x0f
end_define

begin_comment
comment|/* Valid Secondary cmd/addr	*/
end_comment

begin_define
define|#
directive|define
name|AUXMR_GTS
value|0x10
end_define

begin_comment
comment|/* Go to Standby		*/
end_comment

begin_define
define|#
directive|define
name|AUXMR_TCA
value|0x11
end_define

begin_comment
comment|/* Take Control Async (pulsed)	*/
end_comment

begin_define
define|#
directive|define
name|AUXMR_TCS
value|0x12
end_define

begin_comment
comment|/* Take Control Synchronously	*/
end_comment

begin_define
define|#
directive|define
name|AUXMR_LISTEN
value|0x13
end_define

begin_comment
comment|/* Listen			*/
end_comment

begin_define
define|#
directive|define
name|AUXMR_DSC
value|0x14
end_define

begin_comment
comment|/* Disable System Control	*/
end_comment

begin_comment
comment|/* 0x15 undefined/unknown	*/
end_comment

begin_define
define|#
directive|define
name|AUXMR_SIFC
value|0x16
end_define

begin_comment
comment|/* Set IFC			*/
end_comment

begin_define
define|#
directive|define
name|AUXMR_CREN
value|0x17
end_define

begin_comment
comment|/* Clear REN			*/
end_comment

begin_comment
comment|/* 0x18 undefined/unknown	*/
end_comment

begin_comment
comment|/* 0x19 undefined/unknown	*/
end_comment

begin_define
define|#
directive|define
name|AUXMR_TCSE
value|0x1a
end_define

begin_comment
comment|/* Take Control Sync on End	*/
end_comment

begin_define
define|#
directive|define
name|AUXMR_LCM
value|0x1b
end_define

begin_comment
comment|/* Listen Continuously Mode	*/
end_comment

begin_define
define|#
directive|define
name|AUXMR_LUNL
value|0x1c
end_define

begin_comment
comment|/* Local Unlisten		*/
end_comment

begin_define
define|#
directive|define
name|AUXMR_EPP
value|0x1d
end_define

begin_comment
comment|/* Execute Parallel Poll	*/
end_comment

begin_define
define|#
directive|define
name|AUXMR_CIFC
value|0x1e
end_define

begin_comment
comment|/* Clear IFC			*/
end_comment

begin_define
define|#
directive|define
name|AUXMR_SREN
value|0x1f
end_define

begin_comment
comment|/* Set REN			*/
end_comment

begin_define
define|#
directive|define
name|PPR_U
value|(1<< 4)
end_define

begin_comment
comment|/* Unconfigure			*/
end_comment

begin_define
define|#
directive|define
name|PPR_S
value|(1<< 3)
end_define

begin_comment
comment|/* Status Polarity		*/
end_comment

begin_define
define|#
directive|define
name|AUXA_HLDA
value|(1<< 0)
end_define

begin_comment
comment|/* Holdoff on All		*/
end_comment

begin_define
define|#
directive|define
name|AUXA_HLDE
value|(1<< 1)
end_define

begin_comment
comment|/* Holdoff on END		*/
end_comment

begin_define
define|#
directive|define
name|AUXA_REOS
value|(1<< 2)
end_define

begin_comment
comment|/* End on EOS received		*/
end_comment

begin_define
define|#
directive|define
name|AUXA_XEOS
value|(1<< 3)
end_define

begin_comment
comment|/* Transmit END with EOS	*/
end_comment

begin_define
define|#
directive|define
name|AUXA_BIN
value|(1<< 4)
end_define

begin_comment
comment|/* Binary			*/
end_comment

begin_define
define|#
directive|define
name|AUXB_CPTE
value|(1<< 0)
end_define

begin_comment
comment|/* Cmd Pass Through Enable	*/
end_comment

begin_define
define|#
directive|define
name|AUXB_SPEOI
value|(1<< 1)
end_define

begin_comment
comment|/* Send Serial Poll EOI		*/
end_comment

begin_define
define|#
directive|define
name|AUXB_TRI
value|(1<< 2)
end_define

begin_comment
comment|/* Three-State Timing		*/
end_comment

begin_define
define|#
directive|define
name|AUXB_INV
value|(1<< 3)
end_define

begin_comment
comment|/* Invert			*/
end_comment

begin_define
define|#
directive|define
name|AUXB_ISS
value|(1<< 4)
end_define

begin_comment
comment|/* Individual Status Select	*/
end_comment

begin_define
define|#
directive|define
name|AUXE_DHDT
value|(1<< 0)
end_define

begin_comment
comment|/* DAC Holdoff on DTAS		*/
end_comment

begin_define
define|#
directive|define
name|AUXE_DHDC
value|(1<< 1)
end_define

begin_comment
comment|/* DAC Holdoff on DCAS		*/
end_comment

begin_define
define|#
directive|define
name|ADR0_DL0
value|(1<< 5)
end_define

begin_comment
comment|/* Disable Listener 0		*/
end_comment

begin_define
define|#
directive|define
name|ADR0_DT0
value|(1<< 6)
end_define

begin_comment
comment|/* Disable Talker 0		*/
end_comment

begin_define
define|#
directive|define
name|ADR_DL
value|(1<< 5)
end_define

begin_comment
comment|/* Disable Listener		*/
end_comment

begin_define
define|#
directive|define
name|ADR_DT
value|(1<< 6)
end_define

begin_comment
comment|/* Disable Talker		*/
end_comment

begin_define
define|#
directive|define
name|ADR_ARS
value|(1<< 7)
end_define

begin_comment
comment|/* Address Register Select	*/
end_comment

begin_define
define|#
directive|define
name|ADR1_DL1
value|(1<< 5)
end_define

begin_comment
comment|/* Disable Listener 1		*/
end_comment

begin_define
define|#
directive|define
name|ADR1_DT1
value|(1<< 6)
end_define

begin_comment
comment|/* Disable Talker 1		*/
end_comment

begin_define
define|#
directive|define
name|ADR1_EOI
value|(1<< 7)
end_define

begin_comment
comment|/* End or Identify		*/
end_comment

begin_comment
comment|/* Stuff from software drivers */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|cdevsw
name|gpib_ib_cdevsw
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Stuff from upd7210.c */
end_comment

begin_function_decl
name|void
name|upd7210_print_isr
parameter_list|(
name|u_int
name|isr1
parameter_list|,
name|u_int
name|isr2
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|u_int
name|upd7210_rd
parameter_list|(
name|struct
name|upd7210
modifier|*
name|u
parameter_list|,
name|enum
name|upd7210_rreg
name|reg
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|upd7210_wr
parameter_list|(
name|struct
name|upd7210
modifier|*
name|u
parameter_list|,
name|enum
name|upd7210_wreg
name|reg
parameter_list|,
name|u_int
name|val
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|upd7210_take_ctrl_async
parameter_list|(
name|struct
name|upd7210
modifier|*
name|u
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|upd7210_goto_standby
parameter_list|(
name|struct
name|upd7210
modifier|*
name|u
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* UPD7210_SW_DRIVER */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _KERNEL */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _DEV_IEEE488_UPD7210_H_ */
end_comment

end_unit

