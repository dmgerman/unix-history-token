begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1996-1999  * Kazutaka YOKOTA (yokota@zodiac.mech.utsunomiya-u.ac.jp)  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. The name of the author may not be used to endorse or promote   *    products derived from this software without specific prior written   *    permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  * from kbdio.h,v 1.8 1998/09/25 11:55:46 yokota Exp  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_DEV_KBD_ATKBDCREG_H_
end_ifndef

begin_define
define|#
directive|define
name|_DEV_KBD_ATKBDCREG_H_
end_define

begin_comment
comment|/* constants */
end_comment

begin_comment
comment|/* I/O ports */
end_comment

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

begin_define
define|#
directive|define
name|PSM_EXPLORER_ID
value|4
end_define

begin_define
define|#
directive|define
name|PSM_4DMOUSE_ID
value|6
end_define

begin_define
define|#
directive|define
name|PSM_4DPLUS_ID
value|8
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_define
define|#
directive|define
name|ATKBDC_DRIVER_NAME
value|"atkbdc"
end_define

begin_comment
comment|/*   * driver specific options: the following options may be set by  * `options' statements in the kernel configuration file.   */
end_comment

begin_comment
comment|/* retry count */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|KBD_MAXRETRY
end_ifndef

begin_define
define|#
directive|define
name|KBD_MAXRETRY
value|3
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* timing parameters */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|KBD_RESETDELAY
end_ifndef

begin_define
define|#
directive|define
name|KBD_RESETDELAY
value|200
end_define

begin_comment
comment|/* wait 200msec after kbd/mouse reset */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|KBD_MAXWAIT
end_ifndef

begin_define
define|#
directive|define
name|KBD_MAXWAIT
value|5
end_define

begin_comment
comment|/* wait 5 times at most after reset */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* I/O recovery time */
end_comment

begin_define
define|#
directive|define
name|KBDC_DELAYTIME
value|20
end_define

begin_define
define|#
directive|define
name|KBDD_DELAYTIME
value|7
end_define

begin_comment
comment|/* debug option */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|KBDIO_DEBUG
end_ifndef

begin_define
define|#
directive|define
name|KBDIO_DEBUG
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* end of driver specific options */
end_comment

begin_comment
comment|/* types/structures */
end_comment

begin_define
define|#
directive|define
name|KBDQ_BUFSIZE
value|32
end_define

begin_typedef
typedef|typedef
struct|struct
name|_kqueue
block|{
name|int
name|head
decl_stmt|;
name|int
name|tail
decl_stmt|;
name|unsigned
name|char
name|q
index|[
name|KBDQ_BUFSIZE
index|]
decl_stmt|;
if|#
directive|if
name|KBDIO_DEBUG
operator|>=
literal|2
name|int
name|call_count
decl_stmt|;
name|int
name|qcount
decl_stmt|;
name|int
name|max_qcount
decl_stmt|;
endif|#
directive|endif
block|}
name|kqueue
typedef|;
end_typedef

begin_struct_decl
struct_decl|struct
name|resource
struct_decl|;
end_struct_decl

begin_typedef
typedef|typedef
struct|struct
name|atkbdc_softc
block|{
name|struct
name|resource
modifier|*
name|port0
decl_stmt|;
comment|/* data port */
name|struct
name|resource
modifier|*
name|port1
decl_stmt|;
comment|/* status port */
name|bus_space_tag_t
name|iot
decl_stmt|;
name|bus_space_handle_t
name|ioh0
decl_stmt|;
name|bus_space_handle_t
name|ioh1
decl_stmt|;
name|int
name|command_byte
decl_stmt|;
comment|/* current command byte value */
name|int
name|command_mask
decl_stmt|;
comment|/* command byte mask bits for kbd/aux devices */
name|int
name|lock
decl_stmt|;
comment|/* FIXME: XXX not quite a semaphore... */
name|kqueue
name|kbd
decl_stmt|;
comment|/* keyboard data queue */
name|kqueue
name|aux
decl_stmt|;
comment|/* auxiliary data queue */
block|}
name|atkbdc_softc_t
typedef|;
end_typedef

begin_enum
enum|enum
name|kbdc_device_ivar
block|{
name|KBDC_IVAR_IRQ
block|,
name|KBDC_IVAR_FLAGS
block|,
name|KBDC_IVAR_VENDORID
block|,
name|KBDC_IVAR_SERIAL
block|,
name|KBDC_IVAR_LOGICALID
block|,
name|KBDC_IVAR_COMPATID
block|,  }
enum|;
end_enum

begin_typedef
typedef|typedef
name|caddr_t
name|KBDC
typedef|;
end_typedef

begin_comment
comment|/* function prototypes */
end_comment

begin_function_decl
name|atkbdc_softc_t
modifier|*
name|atkbdc_get_softc
parameter_list|(
name|int
name|unit
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|atkbdc_probe_unit
parameter_list|(
name|int
name|unit
parameter_list|,
name|struct
name|resource
modifier|*
name|port0
parameter_list|,
name|struct
name|resource
modifier|*
name|port1
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|atkbdc_attach_unit
parameter_list|(
name|int
name|unit
parameter_list|,
name|atkbdc_softc_t
modifier|*
name|sc
parameter_list|,
name|struct
name|resource
modifier|*
name|port0
parameter_list|,
name|struct
name|resource
modifier|*
name|port1
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|atkbdc_configure
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|KBDC
name|atkbdc_open
parameter_list|(
name|int
name|unit
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|kbdc_lock
parameter_list|(
name|KBDC
name|kbdc
parameter_list|,
name|int
name|lock
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|kbdc_data_ready
parameter_list|(
name|KBDC
name|kbdc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|write_controller_command
parameter_list|(
name|KBDC
name|kbdc
parameter_list|,
name|int
name|c
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|write_controller_data
parameter_list|(
name|KBDC
name|kbdc
parameter_list|,
name|int
name|c
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|write_kbd_command
parameter_list|(
name|KBDC
name|kbdc
parameter_list|,
name|int
name|c
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|write_aux_command
parameter_list|(
name|KBDC
name|kbdc
parameter_list|,
name|int
name|c
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|send_kbd_command
parameter_list|(
name|KBDC
name|kbdc
parameter_list|,
name|int
name|c
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|send_aux_command
parameter_list|(
name|KBDC
name|kbdc
parameter_list|,
name|int
name|c
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|send_kbd_command_and_data
parameter_list|(
name|KBDC
name|kbdc
parameter_list|,
name|int
name|c
parameter_list|,
name|int
name|d
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|send_aux_command_and_data
parameter_list|(
name|KBDC
name|kbdc
parameter_list|,
name|int
name|c
parameter_list|,
name|int
name|d
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|read_controller_data
parameter_list|(
name|KBDC
name|kbdc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|read_kbd_data
parameter_list|(
name|KBDC
name|kbdc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|read_kbd_data_no_wait
parameter_list|(
name|KBDC
name|kbdc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|read_aux_data
parameter_list|(
name|KBDC
name|kbdc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|read_aux_data_no_wait
parameter_list|(
name|KBDC
name|kbdc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|empty_kbd_buffer
parameter_list|(
name|KBDC
name|kbdc
parameter_list|,
name|int
name|t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|empty_aux_buffer
parameter_list|(
name|KBDC
name|kbdc
parameter_list|,
name|int
name|t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|empty_both_buffers
parameter_list|(
name|KBDC
name|kbdc
parameter_list|,
name|int
name|t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|reset_kbd
parameter_list|(
name|KBDC
name|kbdc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|reset_aux_dev
parameter_list|(
name|KBDC
name|kbdc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|test_controller
parameter_list|(
name|KBDC
name|kbdc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|test_kbd_port
parameter_list|(
name|KBDC
name|kbdc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|test_aux_port
parameter_list|(
name|KBDC
name|kbdc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|kbdc_get_device_mask
parameter_list|(
name|KBDC
name|kbdc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|kbdc_set_device_mask
parameter_list|(
name|KBDC
name|kbdc
parameter_list|,
name|int
name|mask
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|get_controller_command_byte
parameter_list|(
name|KBDC
name|kbdc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|set_controller_command_byte
parameter_list|(
name|KBDC
name|kbdc
parameter_list|,
name|int
name|command
parameter_list|,
name|int
name|flag
parameter_list|)
function_decl|;
end_function_decl

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
comment|/* !_DEV_KBD_ATKBDCREG_H_ */
end_comment

end_unit

