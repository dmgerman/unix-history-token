begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2000, 2001 Hellmuth Michaelis. All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *---------------------------------------------------------------------------*  *  *	i4b_l1.h - isdn4bsd layer 1 header file  *	---------------------------------------  *  * $FreeBSD$  *  *      last edit-date: [Wed Jan 10 16:42:27 2001]  *  *---------------------------------------------------------------------------*/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_I4B_L1_H_
end_ifndef

begin_define
define|#
directive|define
name|_I4B_L1_H_
end_define

begin_include
include|#
directive|include
file|<i4b/include/i4b_l3l4.h>
end_include

begin_comment
comment|/*---------------------------------------------------------------------------  *	kernel config file flags definition  *---------------------------------------------------------------------------*/
end_comment

begin_define
define|#
directive|define
name|FLAG_TELES_S0_8
value|1
end_define

begin_define
define|#
directive|define
name|FLAG_TELES_S0_16
value|2
end_define

begin_define
define|#
directive|define
name|FLAG_TELES_S0_163
value|3
end_define

begin_define
define|#
directive|define
name|FLAG_AVM_A1
value|4
end_define

begin_define
define|#
directive|define
name|FLAG_TELES_S0_163_PnP
value|5
end_define

begin_define
define|#
directive|define
name|FLAG_CREATIX_S0_PnP
value|6
end_define

begin_define
define|#
directive|define
name|FLAG_USR_ISDN_TA_INT
value|7
end_define

begin_define
define|#
directive|define
name|FLAG_DRN_NGO
value|8
end_define

begin_define
define|#
directive|define
name|FLAG_SWS
value|9
end_define

begin_define
define|#
directive|define
name|FLAG_AVM_A1_PCMCIA
value|10
end_define

begin_define
define|#
directive|define
name|FLAG_DYNALINK
value|11
end_define

begin_define
define|#
directive|define
name|FLAG_BLMASTER
value|12
end_define

begin_define
define|#
directive|define
name|FLAG_ELSA_QS1P_ISA
value|13
end_define

begin_define
define|#
directive|define
name|FLAG_ELSA_QS1P_PCI
value|14
end_define

begin_define
define|#
directive|define
name|FLAG_SIEMENS_ITALK
value|15
end_define

begin_define
define|#
directive|define
name|FLAG_ELSA_MLIMC
value|16
end_define

begin_define
define|#
directive|define
name|FLAG_ELSA_MLMCALL
value|17
end_define

begin_define
define|#
directive|define
name|FLAG_ITK_IX1
value|18
end_define

begin_define
define|#
directive|define
name|FLAG_AVMA1PCI
value|19
end_define

begin_define
define|#
directive|define
name|FLAG_ELSA_PCC16
value|20
end_define

begin_define
define|#
directive|define
name|FLAG_AVM_PNP
value|21
end_define

begin_define
define|#
directive|define
name|FLAG_SIEMENS_ISURF2
value|22
end_define

begin_define
define|#
directive|define
name|FLAG_ASUSCOM_IPAC
value|23
end_define

begin_define
define|#
directive|define
name|FLAG_WINBOND_6692
value|24
end_define

begin_define
define|#
directive|define
name|FLAG_TELES_S0_163C
value|25
end_define

begin_define
define|#
directive|define
name|FLAG_ACER_P10
value|26
end_define

begin_define
define|#
directive|define
name|FLAG_TELEINT_NO_1
value|27
end_define

begin_define
define|#
directive|define
name|FLAG_CCD_HFCS_PCI
value|28
end_define

begin_define
define|#
directive|define
name|FLAG_NETJET_S
value|29
end_define

begin_define
define|#
directive|define
name|SEC_DELAY
value|1000000
end_define

begin_comment
comment|/* one second DELAY for DELAY*/
end_comment

begin_define
define|#
directive|define
name|MAX_DFRAME_LEN
value|264
end_define

begin_comment
comment|/* max length of a D frame */
end_comment

begin_define
define|#
directive|define
name|min
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|((a)<(b)?(a):(b))
end_define

begin_comment
comment|/* L1DRVR_XXXX moved to i4b_ioctl.h */
end_comment

begin_define
define|#
directive|define
name|L0DRVR
parameter_list|(
name|du
parameter_list|)
value|(((du)>> 8)& 0xff)
end_define

begin_define
define|#
directive|define
name|L0UNIT
parameter_list|(
name|du
parameter_list|)
value|((du)& 0xff)
end_define

begin_define
define|#
directive|define
name|L0DRVRUNIT
parameter_list|(
name|d
parameter_list|,
name|u
parameter_list|)
value|( (((d)<< 8)& 0xff00) | ((u)& 0xff))
end_define

begin_define
define|#
directive|define
name|L0ISICUNIT
parameter_list|(
name|u
parameter_list|)
value|( (((L1DRVR_ISIC)<< 8)& 0xff00) | ((u)& 0xff))
end_define

begin_define
define|#
directive|define
name|L0IWICUNIT
parameter_list|(
name|u
parameter_list|)
value|( (((L1DRVR_IWIC)<< 8)& 0xff00) | ((u)& 0xff))
end_define

begin_define
define|#
directive|define
name|L0IFPIUNIT
parameter_list|(
name|u
parameter_list|)
value|( (((L1DRVR_IFPI)<< 8)& 0xff00) | ((u)& 0xff))
end_define

begin_define
define|#
directive|define
name|L0IHFCUNIT
parameter_list|(
name|u
parameter_list|)
value|( (((L1DRVR_IHFC)<< 8)& 0xff00) | ((u)& 0xff))
end_define

begin_define
define|#
directive|define
name|L0IFPNPUNIT
parameter_list|(
name|u
parameter_list|)
value|( (((L1DRVR_IFPNP)<< 8)& 0xff00) | ((u)& 0xff))
end_define

begin_define
define|#
directive|define
name|L0ICCHPUNIT
parameter_list|(
name|u
parameter_list|)
value|( (((L1DRVR_ICCHP)<< 8)& 0xff00) | ((u)& 0xff))
end_define

begin_define
define|#
directive|define
name|L0ITJCUNIT
parameter_list|(
name|u
parameter_list|)
value|( (((L1DRVR_ITJC)<< 8)& 0xff00) | ((u)& 0xff))
end_define

begin_comment
comment|/* jump table for the multiplex functions */
end_comment

begin_struct
struct|struct
name|i4b_l1mux_func
block|{
name|isdn_link_t
modifier|*
function_decl|(
modifier|*
name|ret_linktab
function_decl|)
parameter_list|(
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|set_linktab
function_decl|)
parameter_list|(
name|int
parameter_list|,
name|int
parameter_list|,
name|drvr_link_t
modifier|*
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|mph_command_req
function_decl|)
parameter_list|(
name|int
parameter_list|,
name|int
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|ph_data_req
function_decl|)
parameter_list|(
name|int
parameter_list|,
name|struct
name|mbuf
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|ph_activate_req
function_decl|)
parameter_list|(
name|int
parameter_list|)
function_decl|;
block|}
struct|;
end_struct

begin_function_decl
name|int
name|i4b_l1_ph_data_ind
parameter_list|(
name|int
name|unit
parameter_list|,
name|struct
name|mbuf
modifier|*
name|m
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|i4b_l1_ph_activate_ind
parameter_list|(
name|int
name|unit
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|i4b_l1_ph_deactivate_ind
parameter_list|(
name|int
name|unit
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|i4b_l1_mph_status_ind
parameter_list|(
name|int
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|,
name|struct
name|i4b_l1mux_func
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|isdn_link_t
modifier|*
name|i4b_l1_ret_linktab
parameter_list|(
name|int
name|unit
parameter_list|,
name|int
name|channel
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|i4b_l1_set_linktab
parameter_list|(
name|int
name|unit
parameter_list|,
name|int
name|channel
parameter_list|,
name|drvr_link_t
modifier|*
name|dlt
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|i4b_l1_trace_ind
parameter_list|(
name|i4b_trace_hdr_t
modifier|*
parameter_list|,
name|int
parameter_list|,
name|u_char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* i4b_l1lib.c */
end_comment

begin_function_decl
name|int
name|i4b_l1_bchan_tel_silence
parameter_list|(
name|unsigned
name|char
modifier|*
name|data
parameter_list|,
name|int
name|len
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _I4B_L1_H_ */
end_comment

end_unit

