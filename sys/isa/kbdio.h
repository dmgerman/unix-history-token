begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1996 Kazutaka YOKOTA (yokota@zodiac.mech.utsunomiya-u.ac.jp)  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. The name of the author may not be used to endorse or promote   *    products derived from this software without specific prior written   *    permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $Id: kbdio.h,v 1.6 1997/02/22 09:36:47 peter Exp $  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_I386_ISA_KBDIO_H_
end_ifndef

begin_define
define|#
directive|define
name|_I386_ISA_KBDIO_H_
end_define

begin_comment
comment|/* constants */
end_comment

begin_comment
comment|/* I/O ports */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|PC98
end_ifdef

begin_define
define|#
directive|define
name|KBD_STATUS_PORT
value|2
end_define

begin_comment
comment|/* status port, read */
end_comment

begin_define
define|#
directive|define
name|KBD_COMMAND_PORT
value|2
end_define

begin_comment
comment|/* controller command port, write */
end_comment

begin_define
define|#
directive|define
name|KBD_DATA_PORT
value|0
end_define

begin_comment
comment|/* data port, read/write  					 * also used as keyboard command 					 * and mouse command port  					 */
end_comment

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|KBD_STATUS_PORT
value|4
end_define

begin_comment
comment|/* status port, read */
end_comment

begin_define
define|#
directive|define
name|KBD_COMMAND_PORT
value|4
end_define

begin_comment
comment|/* controller command port, write */
end_comment

begin_define
define|#
directive|define
name|KBD_DATA_PORT
value|0
end_define

begin_comment
comment|/* data port, read/write  					 * also used as keyboard command 					 * and mouse command port  					 */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* PC98 */
end_comment

begin_comment
comment|/* FIXME: `IO_PSMSIZE' should really be in `isa.h'. */
end_comment

begin_define
define|#
directive|define
name|IO_PSMSIZE
value|(KBD_COMMAND_PORT - KBD_DATA_PORT + 1)
end_define

begin_comment
comment|/* 5 */
end_comment

begin_comment
comment|/* controller commands (sent to KBD_COMMAND_PORT) */
end_comment

begin_define
define|#
directive|define
name|KBDC_SET_COMMAND_BYTE
value|0x0060
end_define

begin_define
define|#
directive|define
name|KBDC_GET_COMMAND_BYTE
value|0x0020
end_define

begin_define
define|#
directive|define
name|KBDC_WRITE_TO_AUX
value|0x00d4
end_define

begin_define
define|#
directive|define
name|KBDC_DISABLE_AUX_PORT
value|0x00a7
end_define

begin_define
define|#
directive|define
name|KBDC_ENABLE_AUX_PORT
value|0x00a8
end_define

begin_define
define|#
directive|define
name|KBDC_TEST_AUX_PORT
value|0x00a9
end_define

begin_define
define|#
directive|define
name|KBDC_DIAGNOSE
value|0x00aa
end_define

begin_define
define|#
directive|define
name|KBDC_TEST_KBD_PORT
value|0x00ab
end_define

begin_define
define|#
directive|define
name|KBDC_DISABLE_KBD_PORT
value|0x00ad
end_define

begin_define
define|#
directive|define
name|KBDC_ENABLE_KBD_PORT
value|0x00ae
end_define

begin_comment
comment|/* controller command byte (set by KBDC_SET_COMMAND_BYTE) */
end_comment

begin_define
define|#
directive|define
name|KBD_TRANSLATION
value|0x0040
end_define

begin_define
define|#
directive|define
name|KBD_RESERVED_BITS
value|0x0004
end_define

begin_define
define|#
directive|define
name|KBD_OVERRIDE_KBD_LOCK
value|0x0008
end_define

begin_define
define|#
directive|define
name|KBD_ENABLE_KBD_PORT
value|0x0000
end_define

begin_define
define|#
directive|define
name|KBD_DISABLE_KBD_PORT
value|0x0010
end_define

begin_define
define|#
directive|define
name|KBD_ENABLE_AUX_PORT
value|0x0000
end_define

begin_define
define|#
directive|define
name|KBD_DISABLE_AUX_PORT
value|0x0020
end_define

begin_define
define|#
directive|define
name|KBD_ENABLE_AUX_INT
value|0x0002
end_define

begin_define
define|#
directive|define
name|KBD_DISABLE_AUX_INT
value|0x0000
end_define

begin_define
define|#
directive|define
name|KBD_ENABLE_KBD_INT
value|0x0001
end_define

begin_define
define|#
directive|define
name|KBD_DISABLE_KBD_INT
value|0x0000
end_define

begin_define
define|#
directive|define
name|KBD_KBD_CONTROL_BITS
value|(KBD_DISABLE_KBD_PORT | KBD_ENABLE_KBD_INT)
end_define

begin_define
define|#
directive|define
name|KBD_AUX_CONTROL_BITS
value|(KBD_DISABLE_AUX_PORT | KBD_ENABLE_AUX_INT)
end_define

begin_comment
comment|/* keyboard device commands (sent to KBD_DATA_PORT) */
end_comment

begin_define
define|#
directive|define
name|KBDC_RESET_KBD
value|0x00ff
end_define

begin_define
define|#
directive|define
name|KBDC_ENABLE_KBD
value|0x00f4
end_define

begin_define
define|#
directive|define
name|KBDC_DISABLE_KBD
value|0x00f5
end_define

begin_define
define|#
directive|define
name|KBDC_SET_DEFAULTS
value|0x00f6
end_define

begin_define
define|#
directive|define
name|KBDC_SEND_DEV_ID
value|0x00f2
end_define

begin_define
define|#
directive|define
name|KBDC_SET_LEDS
value|0x00ed
end_define

begin_define
define|#
directive|define
name|KBDC_ECHO
value|0x00ee
end_define

begin_define
define|#
directive|define
name|KBDC_SET_SCANCODE_SET
value|0x00f0
end_define

begin_define
define|#
directive|define
name|KBDC_SET_TYPEMATIC
value|0x00f3
end_define

begin_comment
comment|/* aux device commands (sent to KBD_DATA_PORT) */
end_comment

begin_define
define|#
directive|define
name|PSMC_RESET_DEV
value|0x00ff
end_define

begin_define
define|#
directive|define
name|PSMC_ENABLE_DEV
value|0x00f4
end_define

begin_define
define|#
directive|define
name|PSMC_DISABLE_DEV
value|0x00f5
end_define

begin_define
define|#
directive|define
name|PSMC_SET_DEFAULTS
value|0x00f6
end_define

begin_define
define|#
directive|define
name|PSMC_SEND_DEV_ID
value|0x00f2
end_define

begin_define
define|#
directive|define
name|PSMC_SEND_DEV_STATUS
value|0x00e9
end_define

begin_define
define|#
directive|define
name|PSMC_SEND_DEV_DATA
value|0x00eb
end_define

begin_define
define|#
directive|define
name|PSMC_SET_SCALING11
value|0x00e6
end_define

begin_define
define|#
directive|define
name|PSMC_SET_SCALING21
value|0x00e7
end_define

begin_define
define|#
directive|define
name|PSMC_SET_RESOLUTION
value|0x00e8
end_define

begin_define
define|#
directive|define
name|PSMC_SET_STREAM_MODE
value|0x00ea
end_define

begin_define
define|#
directive|define
name|PSMC_SET_REMOTE_MODE
value|0x00f0
end_define

begin_define
define|#
directive|define
name|PSMC_SET_SAMPLING_RATE
value|0x00f3
end_define

begin_comment
comment|/* PSMC_SET_RESOLUTION argument */
end_comment

begin_define
define|#
directive|define
name|PSMD_RES_LOW
value|0
end_define

begin_comment
comment|/* typically 25ppi */
end_comment

begin_define
define|#
directive|define
name|PSMD_RES_MEDIUM_LOW
value|1
end_define

begin_comment
comment|/* typically 50ppi */
end_comment

begin_define
define|#
directive|define
name|PSMD_RES_MEDIUM_HIGH
value|2
end_define

begin_comment
comment|/* typically 100ppi (default) */
end_comment

begin_define
define|#
directive|define
name|PSMD_RES_HIGH
value|3
end_define

begin_comment
comment|/* typically 200ppi */
end_comment

begin_define
define|#
directive|define
name|PSMD_MAX_RESOLUTION
value|PSMD_RES_HIGH
end_define

begin_comment
comment|/* PSMC_SET_SAMPLING_RATE */
end_comment

begin_define
define|#
directive|define
name|PSMD_MAX_RATE
value|255
end_define

begin_comment
comment|/* FIXME: not sure if it's possible */
end_comment

begin_comment
comment|/* status bits (KBD_STATUS_PORT) */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|PC98
end_ifdef

begin_define
define|#
directive|define
name|KBDS_BUFFER_FULL
value|0x0002
end_define

begin_define
define|#
directive|define
name|KBDS_ANY_BUFFER_FULL
value|0x0002
end_define

begin_define
define|#
directive|define
name|KBDS_KBD_BUFFER_FULL
value|0x0002
end_define

begin_define
define|#
directive|define
name|KBDS_AUX_BUFFER_FULL
value|0x0002
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|KBDS_BUFFER_FULL
value|0x0021
end_define

begin_define
define|#
directive|define
name|KBDS_ANY_BUFFER_FULL
value|0x0001
end_define

begin_define
define|#
directive|define
name|KBDS_KBD_BUFFER_FULL
value|0x0001
end_define

begin_define
define|#
directive|define
name|KBDS_AUX_BUFFER_FULL
value|0x0021
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|KBDS_INPUT_BUFFER_FULL
value|0x0002
end_define

begin_comment
comment|/* return code */
end_comment

begin_define
define|#
directive|define
name|KBD_ACK
value|0x00fa
end_define

begin_define
define|#
directive|define
name|KBD_RESEND
value|0x00fe
end_define

begin_define
define|#
directive|define
name|KBD_RESET_DONE
value|0x00aa
end_define

begin_define
define|#
directive|define
name|KBD_RESET_FAIL
value|0x00fc
end_define

begin_define
define|#
directive|define
name|KBD_DIAG_DONE
value|0x0055
end_define

begin_define
define|#
directive|define
name|KBD_DIAG_FAIL
value|0x00fd
end_define

begin_define
define|#
directive|define
name|KBD_ECHO
value|0x00ee
end_define

begin_define
define|#
directive|define
name|PSM_ACK
value|0x00fa
end_define

begin_define
define|#
directive|define
name|PSM_RESEND
value|0x00fe
end_define

begin_define
define|#
directive|define
name|PSM_RESET_DONE
value|0x00aa
end_define

begin_define
define|#
directive|define
name|PSM_RESET_FAIL
value|0x00fc
end_define

begin_comment
comment|/* aux device ID */
end_comment

begin_define
define|#
directive|define
name|PSM_MOUSE_ID
value|0
end_define

begin_define
define|#
directive|define
name|PSM_BALLPOINT_ID
value|2
end_define

begin_define
define|#
directive|define
name|PSM_INTELLI_ID
value|3
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|KERNEL
end_ifdef

begin_ifndef
ifndef|#
directive|ifndef
name|TRUE
end_ifndef

begin_define
define|#
directive|define
name|TRUE
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|FALSE
end_ifndef

begin_define
define|#
directive|define
name|FALSE
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* types/structures */
end_comment

begin_typedef
typedef|typedef
name|caddr_t
name|KBDC
typedef|;
end_typedef

begin_comment
comment|/* function prototypes */
end_comment

begin_decl_stmt
name|KBDC
name|kbdc_open
name|__P
argument_list|(
operator|(
name|int
name|port
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|kbdc_lock
name|__P
argument_list|(
operator|(
name|KBDC
name|kbdc
operator|,
name|int
name|lock
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|kbdc_data_ready
name|__P
argument_list|(
operator|(
name|KBDC
name|kbdc
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|write_controller_command
name|__P
argument_list|(
operator|(
name|KBDC
name|kbdc
operator|,
name|int
name|c
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|write_controller_data
name|__P
argument_list|(
operator|(
name|KBDC
name|kbdc
operator|,
name|int
name|c
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|write_kbd_command
name|__P
argument_list|(
operator|(
name|KBDC
name|kbdc
operator|,
name|int
name|c
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|write_aux_command
name|__P
argument_list|(
operator|(
name|KBDC
name|kbdc
operator|,
name|int
name|c
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|send_kbd_command
name|__P
argument_list|(
operator|(
name|KBDC
name|kbdc
operator|,
name|int
name|c
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|send_aux_command
name|__P
argument_list|(
operator|(
name|KBDC
name|kbdc
operator|,
name|int
name|c
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|send_kbd_command_and_data
name|__P
argument_list|(
operator|(
name|KBDC
name|kbdc
operator|,
name|int
name|c
operator|,
name|int
name|d
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|send_aux_command_and_data
name|__P
argument_list|(
operator|(
name|KBDC
name|kbdc
operator|,
name|int
name|c
operator|,
name|int
name|d
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|read_controller_data
name|__P
argument_list|(
operator|(
name|KBDC
name|kbdc
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|read_kbd_data
name|__P
argument_list|(
operator|(
name|KBDC
name|kbdc
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|read_kbd_data_no_wait
name|__P
argument_list|(
operator|(
name|KBDC
name|kbdc
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|read_aux_data
name|__P
argument_list|(
operator|(
name|KBDC
name|kbdc
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|read_aux_data_no_wait
name|__P
argument_list|(
operator|(
name|KBDC
name|kbdc
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|empty_kbd_buffer
name|__P
argument_list|(
operator|(
name|KBDC
name|kbdc
operator|,
name|int
name|t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|empty_aux_buffer
name|__P
argument_list|(
operator|(
name|KBDC
name|kbdc
operator|,
name|int
name|t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|empty_both_buffers
name|__P
argument_list|(
operator|(
name|KBDC
name|kbdc
operator|,
name|int
name|t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|reset_kbd
name|__P
argument_list|(
operator|(
name|KBDC
name|kbdc
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|reset_aux_dev
name|__P
argument_list|(
operator|(
name|KBDC
name|kbdc
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|test_controller
name|__P
argument_list|(
operator|(
name|KBDC
name|kbdc
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|test_kbd_port
name|__P
argument_list|(
operator|(
name|KBDC
name|kbdc
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|test_aux_port
name|__P
argument_list|(
operator|(
name|KBDC
name|kbdc
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|kbdc_get_device_mask
name|__P
argument_list|(
operator|(
name|KBDC
name|kbdc
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|kbdc_set_device_mask
name|__P
argument_list|(
operator|(
name|KBDC
name|kbdc
operator|,
name|int
name|mask
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|get_controller_command_byte
name|__P
argument_list|(
operator|(
name|KBDC
name|kbdc
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|set_controller_command_byte
name|__P
argument_list|(
operator|(
name|KBDC
name|kbdc
operator|,
name|int
name|command
operator|,
name|int
name|flag
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* KERNEL */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_I386_ISA_KBDIO_H_ */
end_comment

end_unit

