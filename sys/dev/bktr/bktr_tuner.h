begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_comment
comment|/*  * This is part of the Driver for Video Capture Cards (Frame grabbers)  * and TV Tuner cards using the Brooktree Bt848, Bt848A, Bt849A, Bt878, Bt879  * chipset.  * Copyright Roger Hardiman and Amancio Hasty.  *   * bktr_tuner : This deals with controlling the tuner fitted to TV cards.  *  */
end_comment

begin_comment
comment|/*  * 1. Redistributions of source code must retain the  * Copyright (c) 1997 Amancio Hasty, 1999 Roger Hardiman  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *      This product includes software developed by Amancio Hasty and  *      Roger Hardiman  * 4. The name of the author may not be used to endorse or promote products  *    derived from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED  * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE  * DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT,  * INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES  * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR  * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,  * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN  * ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  * POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_comment
comment|/* Definitions for Tuners */
end_comment

begin_define
define|#
directive|define
name|NO_TUNER
value|0
end_define

begin_define
define|#
directive|define
name|TEMIC_NTSC
value|1
end_define

begin_define
define|#
directive|define
name|TEMIC_PAL
value|2
end_define

begin_define
define|#
directive|define
name|TEMIC_SECAM
value|3
end_define

begin_define
define|#
directive|define
name|PHILIPS_NTSC
value|4
end_define

begin_define
define|#
directive|define
name|PHILIPS_PAL
value|5
end_define

begin_define
define|#
directive|define
name|PHILIPS_SECAM
value|6
end_define

begin_define
define|#
directive|define
name|TEMIC_PALI
value|7
end_define

begin_define
define|#
directive|define
name|PHILIPS_PALI
value|8
end_define

begin_define
define|#
directive|define
name|PHILIPS_FR1236_NTSC
value|9
end_define

begin_comment
comment|/* These have FM radio support */
end_comment

begin_define
define|#
directive|define
name|PHILIPS_FR1216_PAL
value|10
end_define

begin_comment
comment|/* These have FM radio support */
end_comment

begin_define
define|#
directive|define
name|PHILIPS_FR1236_SECAM
value|11
end_define

begin_comment
comment|/* These have FM radio support */
end_comment

begin_define
define|#
directive|define
name|ALPS_TSCH5
value|12
end_define

begin_define
define|#
directive|define
name|ALPS_TSBH1
value|13
end_define

begin_define
define|#
directive|define
name|Bt848_MAX_TUNER
value|14
end_define

begin_comment
comment|/* experimental code for Automatic Frequency Control */
end_comment

begin_define
define|#
directive|define
name|TUNER_AFC
end_define

begin_comment
comment|/*  * Fill in the tuner entries in the bktr_softc based on the selected tuner  * type (from the list of tuners above)  */
end_comment

begin_function_decl
name|void
name|select_tuner
parameter_list|(
name|bktr_ptr_t
name|bktr
parameter_list|,
name|int
name|tuner_type
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * The Channel Set maps TV channels eg Ch 36, Ch 51, onto frequencies  * and is country specific.  */
end_comment

begin_function_decl
name|int
name|tuner_getchnlset
parameter_list|(
name|struct
name|bktr_chnlset
modifier|*
name|chnlset
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * tv_channel sets the tuner to channel 'n' using the current Channel Set  * tv_freq sets the tuner to a specific frequency for TV or for FM Radio  * get_tuner_status can be used to get the signal strength.  */
end_comment

begin_define
define|#
directive|define
name|TV_FREQUENCY
value|0
end_define

begin_define
define|#
directive|define
name|FM_RADIO_FREQUENCY
value|1
end_define

begin_function_decl
name|int
name|tv_channel
parameter_list|(
name|bktr_ptr_t
name|bktr
parameter_list|,
name|int
name|channel
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|tv_freq
parameter_list|(
name|bktr_ptr_t
name|bktr
parameter_list|,
name|int
name|frequency
parameter_list|,
name|int
name|type
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|get_tuner_status
parameter_list|(
name|bktr_ptr_t
name|bktr
parameter_list|)
function_decl|;
end_function_decl

begin_if
if|#
directive|if
name|defined
argument_list|(
name|TUNER_AFC
argument_list|)
end_if

begin_function_decl
name|int
name|do_afc
parameter_list|(
name|bktr_ptr_t
name|bktr
parameter_list|,
name|int
name|addr
parameter_list|,
name|int
name|frequency
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* TUNER_AFC */
end_comment

begin_comment
comment|/*   * This is for start-up convenience only, NOT mandatory.  */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|DEFAULT_CHNLSET
argument_list|)
end_if

begin_define
define|#
directive|define
name|DEFAULT_CHNLSET
value|CHNLSET_WEUROPE
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

