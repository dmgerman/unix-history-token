begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1999 Kazutaka YOKOTA<yokota@zodiac.mech.utsunomiya-u.ac.jp>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer as  *    the first lines of this file unmodified.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHORS ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHORS BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_DEV_KBD_KBDREG_H_
end_ifndef

begin_define
define|#
directive|define
name|_DEV_KBD_KBDREG_H_
end_define

begin_comment
comment|/* forward declarations */
end_comment

begin_typedef
typedef|typedef
name|struct
name|keyboard
name|keyboard_t
typedef|;
end_typedef

begin_struct_decl
struct_decl|struct
name|keymap
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|accentmap
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|fkeytab
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|cdevsw
struct_decl|;
end_struct_decl

begin_comment
comment|/* call back funcion */
end_comment

begin_typedef
typedef|typedef
name|int
name|kbd_callback_func_t
parameter_list|(
name|keyboard_t
modifier|*
name|kbd
parameter_list|,
name|int
name|event
parameter_list|,
name|void
modifier|*
name|arg
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/* event types */
end_comment

begin_define
define|#
directive|define
name|KBDIO_KEYINPUT
value|0
end_define

begin_define
define|#
directive|define
name|KBDIO_UNLOADING
value|1
end_define

begin_typedef
typedef|typedef
struct|struct
name|keyboard_callback
block|{
name|kbd_callback_func_t
modifier|*
name|kc_func
decl_stmt|;
name|void
modifier|*
name|kc_arg
decl_stmt|;
block|}
name|keyboard_callback_t
typedef|;
end_typedef

begin_comment
comment|/* keyboard */
end_comment

begin_struct
struct|struct
name|keyboard
block|{
comment|/* the following fields are managed by kbdio */
name|int
name|kb_index
decl_stmt|;
comment|/* kbdio index# */
name|int
name|kb_minor
decl_stmt|;
comment|/* minor number of the sub-device */
name|int
name|kb_flags
decl_stmt|;
comment|/* internal flags */
define|#
directive|define
name|KB_VALID
value|(1<< 16)
comment|/* this entry is valid */
define|#
directive|define
name|KB_NO_DEVICE
value|(1<< 17)
comment|/* device not present */
define|#
directive|define
name|KB_PROBED
value|(1<< 18)
comment|/* device probed */
define|#
directive|define
name|KB_INITIALIZED
value|(1<< 19)
comment|/* device initialized */
define|#
directive|define
name|KB_REGISTERED
value|(1<< 20)
comment|/* device registered to kbdio */
define|#
directive|define
name|KB_BUSY
value|(1<< 21)
comment|/* device used by a client */
name|int
name|kb_active
decl_stmt|;
comment|/* 0: inactive */
name|void
modifier|*
name|kb_token
decl_stmt|;
comment|/* id of the current client */
name|keyboard_callback_t
name|kb_callback
decl_stmt|;
comment|/* callback function */
comment|/* 	 * Device configuration flags: 	 * The upper 16 bits are common between various keyboard devices. 	 * The lower 16 bits are device-specific. 	 */
name|int
name|kb_config
decl_stmt|;
define|#
directive|define
name|KB_CONF_PROBE_ONLY
value|(1<< 16)
comment|/* probe only, don't initialize */
comment|/* the following fields are set up by the driver */
name|char
modifier|*
name|kb_name
decl_stmt|;
comment|/* driver name */
name|int
name|kb_unit
decl_stmt|;
comment|/* unit # */
name|int
name|kb_type
decl_stmt|;
comment|/* KB_84, KB_101, KB_OTHER,... */
name|int
name|kb_io_base
decl_stmt|;
comment|/* port# if any */
name|int
name|kb_io_size
decl_stmt|;
comment|/* # of occupied port */
name|int
name|kb_led
decl_stmt|;
comment|/* LED status */
name|struct
name|keymap
modifier|*
name|kb_keymap
decl_stmt|;
comment|/* key map */
name|struct
name|accentmap
modifier|*
name|kb_accentmap
decl_stmt|;
comment|/* accent map */
name|struct
name|fkeytab
modifier|*
name|kb_fkeytab
decl_stmt|;
comment|/* function key strings */
name|int
name|kb_fkeytab_size
decl_stmt|;
comment|/* # of function key strings */
name|void
modifier|*
name|kb_data
decl_stmt|;
comment|/* the driver's private data */
name|int
name|kb_delay1
decl_stmt|;
name|int
name|kb_delay2
decl_stmt|;
define|#
directive|define
name|KB_DELAY1
value|500
define|#
directive|define
name|KB_DELAY2
value|100
name|unsigned
name|long
name|kb_count
decl_stmt|;
comment|/* # of processed key strokes */
name|u_char
name|kb_lastact
index|[
name|NUM_KEYS
operator|/
literal|2
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|KBD_IS_VALID
parameter_list|(
name|k
parameter_list|)
value|((k)->kb_flags& KB_VALID)
end_define

begin_define
define|#
directive|define
name|KBD_VALID
parameter_list|(
name|k
parameter_list|)
value|((k)->kb_flags |= KB_VALID)
end_define

begin_define
define|#
directive|define
name|KBD_INVALID
parameter_list|(
name|k
parameter_list|)
value|((k)->kb_flags&= ~KB_VALID)
end_define

begin_define
define|#
directive|define
name|KBD_HAS_DEVICE
parameter_list|(
name|k
parameter_list|)
value|(!((k)->kb_flags& KB_NO_DEVICE))
end_define

begin_define
define|#
directive|define
name|KBD_FOUND_DEVICE
parameter_list|(
name|k
parameter_list|)
value|((k)->kb_flags&= ~KB_NO_DEVICE)
end_define

begin_define
define|#
directive|define
name|KBD_IS_PROBED
parameter_list|(
name|k
parameter_list|)
value|((k)->kb_flags& KB_PROBED)
end_define

begin_define
define|#
directive|define
name|KBD_PROBE_DONE
parameter_list|(
name|k
parameter_list|)
value|((k)->kb_flags |= KB_PROBED)
end_define

begin_define
define|#
directive|define
name|KBD_IS_INITIALIZED
parameter_list|(
name|k
parameter_list|)
value|((k)->kb_flags& KB_INITIALIZED)
end_define

begin_define
define|#
directive|define
name|KBD_INIT_DONE
parameter_list|(
name|k
parameter_list|)
value|((k)->kb_flags |= KB_INITIALIZED)
end_define

begin_define
define|#
directive|define
name|KBD_IS_CONFIGURED
parameter_list|(
name|k
parameter_list|)
value|((k)->kb_flags& KB_REGISTERED)
end_define

begin_define
define|#
directive|define
name|KBD_CONFIG_DONE
parameter_list|(
name|k
parameter_list|)
value|((k)->kb_flags |= KB_REGISTERED)
end_define

begin_define
define|#
directive|define
name|KBD_IS_BUSY
parameter_list|(
name|k
parameter_list|)
value|((k)->kb_flags& KB_BUSY)
end_define

begin_define
define|#
directive|define
name|KBD_BUSY
parameter_list|(
name|k
parameter_list|)
value|((k)->kb_flags |= KB_BUSY)
end_define

begin_define
define|#
directive|define
name|KBD_UNBUSY
parameter_list|(
name|k
parameter_list|)
value|((k)->kb_flags&= ~KB_BUSY)
end_define

begin_define
define|#
directive|define
name|KBD_IS_ACTIVE
parameter_list|(
name|k
parameter_list|)
value|((k)->kb_active)
end_define

begin_define
define|#
directive|define
name|KBD_ACTIVATE
parameter_list|(
name|k
parameter_list|)
value|(++(k)->kb_active)
end_define

begin_define
define|#
directive|define
name|KBD_DEACTIVATE
parameter_list|(
name|k
parameter_list|)
value|(--(k)->kb_active)
end_define

begin_define
define|#
directive|define
name|KBD_LED_VAL
parameter_list|(
name|k
parameter_list|)
value|((k)->kb_led)
end_define

begin_comment
comment|/* keyboard function table */
end_comment

begin_typedef
typedef|typedef
name|int
name|kbd_probe_t
parameter_list|(
name|int
name|unit
parameter_list|,
name|void
modifier|*
name|arg
parameter_list|,
name|int
name|flags
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|int
name|kbd_init_t
parameter_list|(
name|int
name|unit
parameter_list|,
name|keyboard_t
modifier|*
modifier|*
name|kbdp
parameter_list|,
name|void
modifier|*
name|arg
parameter_list|,
name|int
name|flags
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|int
name|kbd_term_t
parameter_list|(
name|keyboard_t
modifier|*
name|kbd
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|int
name|kbd_intr_t
parameter_list|(
name|keyboard_t
modifier|*
name|kbd
parameter_list|,
name|void
modifier|*
name|arg
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|int
name|kbd_test_if_t
parameter_list|(
name|keyboard_t
modifier|*
name|kbd
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|int
name|kbd_enable_t
parameter_list|(
name|keyboard_t
modifier|*
name|kbd
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|int
name|kbd_disable_t
parameter_list|(
name|keyboard_t
modifier|*
name|kbd
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|int
name|kbd_read_t
parameter_list|(
name|keyboard_t
modifier|*
name|kbd
parameter_list|,
name|int
name|wait
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|int
name|kbd_check_t
parameter_list|(
name|keyboard_t
modifier|*
name|kbd
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|u_int
name|kbd_read_char_t
parameter_list|(
name|keyboard_t
modifier|*
name|kbd
parameter_list|,
name|int
name|wait
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|int
name|kbd_check_char_t
parameter_list|(
name|keyboard_t
modifier|*
name|kbd
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|int
name|kbd_ioctl_t
parameter_list|(
name|keyboard_t
modifier|*
name|kbd
parameter_list|,
name|u_long
name|cmd
parameter_list|,
name|caddr_t
name|data
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|int
name|kbd_lock_t
parameter_list|(
name|keyboard_t
modifier|*
name|kbd
parameter_list|,
name|int
name|lock
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|void
name|kbd_clear_state_t
parameter_list|(
name|keyboard_t
modifier|*
name|kbd
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|int
name|kbd_get_state_t
parameter_list|(
name|keyboard_t
modifier|*
name|kbd
parameter_list|,
name|void
modifier|*
name|buf
parameter_list|,
name|size_t
name|len
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|int
name|kbd_set_state_t
parameter_list|(
name|keyboard_t
modifier|*
name|kbd
parameter_list|,
name|void
modifier|*
name|buf
parameter_list|,
name|size_t
name|len
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|u_char
modifier|*
name|kbd_get_fkeystr_t
parameter_list|(
name|keyboard_t
modifier|*
name|kbd
parameter_list|,
name|int
name|fkey
parameter_list|,
name|size_t
modifier|*
name|len
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|int
name|kbd_poll_mode_t
parameter_list|(
name|keyboard_t
modifier|*
name|kbd
parameter_list|,
name|int
name|on
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|void
name|kbd_diag_t
parameter_list|(
name|keyboard_t
modifier|*
name|kbd
parameter_list|,
name|int
name|level
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|keyboard_switch
block|{
name|kbd_probe_t
modifier|*
name|probe
decl_stmt|;
name|kbd_init_t
modifier|*
name|init
decl_stmt|;
name|kbd_term_t
modifier|*
name|term
decl_stmt|;
name|kbd_intr_t
modifier|*
name|intr
decl_stmt|;
name|kbd_test_if_t
modifier|*
name|test_if
decl_stmt|;
name|kbd_enable_t
modifier|*
name|enable
decl_stmt|;
name|kbd_disable_t
modifier|*
name|disable
decl_stmt|;
name|kbd_read_t
modifier|*
name|read
decl_stmt|;
name|kbd_check_t
modifier|*
name|check
decl_stmt|;
name|kbd_read_char_t
modifier|*
name|read_char
decl_stmt|;
name|kbd_check_char_t
modifier|*
name|check_char
decl_stmt|;
name|kbd_ioctl_t
modifier|*
name|ioctl
decl_stmt|;
name|kbd_lock_t
modifier|*
name|lock
decl_stmt|;
name|kbd_clear_state_t
modifier|*
name|clear_state
decl_stmt|;
name|kbd_get_state_t
modifier|*
name|get_state
decl_stmt|;
name|kbd_set_state_t
modifier|*
name|set_state
decl_stmt|;
name|kbd_get_fkeystr_t
modifier|*
name|get_fkeystr
decl_stmt|;
name|kbd_poll_mode_t
modifier|*
name|poll
decl_stmt|;
name|kbd_diag_t
modifier|*
name|diag
decl_stmt|;
block|}
name|keyboard_switch_t
typedef|;
end_typedef

begin_comment
comment|/* keyboard driver */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|keyboard_driver
block|{
name|SLIST_ENTRY
argument_list|(
argument|keyboard_driver
argument_list|)
name|link
expr_stmt|;
name|char
modifier|*
name|name
decl_stmt|;
name|keyboard_switch_t
modifier|*
name|kbdsw
decl_stmt|;
name|int
function_decl|(
modifier|*
name|configure
function_decl|)
parameter_list|(
name|int
parameter_list|)
function_decl|;
comment|/* backdoor for the console driver */
block|}
name|keyboard_driver_t
typedef|;
end_typedef

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_define
define|#
directive|define
name|KEYBOARD_DRIVER
parameter_list|(
name|name
parameter_list|,
name|sw
parameter_list|,
name|config
parameter_list|)
define|\
value|static struct keyboard_driver name##_kbd_driver = { \ 		{ NULL }, #name,&sw, config		\ 	};						\ 	DATA_SET(kbddriver_set, name##_kbd_driver);
end_define

begin_comment
comment|/* global variables */
end_comment

begin_decl_stmt
specifier|extern
name|keyboard_switch_t
modifier|*
modifier|*
name|kbdsw
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|linker_set
name|kbddriver_set
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* functions for the keyboard driver */
end_comment

begin_function_decl
name|int
name|kbd_add_driver
parameter_list|(
name|keyboard_driver_t
modifier|*
name|driver
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|kbd_delete_driver
parameter_list|(
name|keyboard_driver_t
modifier|*
name|driver
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|kbd_register
parameter_list|(
name|keyboard_t
modifier|*
name|kbd
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|kbd_unregister
parameter_list|(
name|keyboard_t
modifier|*
name|kbd
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|keyboard_switch_t
modifier|*
name|kbd_get_switch
parameter_list|(
name|char
modifier|*
name|driver
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|kbd_init_struct
parameter_list|(
name|keyboard_t
modifier|*
name|kbd
parameter_list|,
name|char
modifier|*
name|name
parameter_list|,
name|int
name|type
parameter_list|,
name|int
name|unit
parameter_list|,
name|int
name|config
parameter_list|,
name|int
name|port
parameter_list|,
name|int
name|port_size
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|kbd_set_maps
parameter_list|(
name|keyboard_t
modifier|*
name|kbd
parameter_list|,
name|struct
name|keymap
modifier|*
name|keymap
parameter_list|,
name|struct
name|accentmap
modifier|*
name|accmap
parameter_list|,
name|struct
name|fkeytab
modifier|*
name|fkeymap
parameter_list|,
name|int
name|fkeymap_size
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* functions for the keyboard client */
end_comment

begin_function_decl
name|int
name|kbd_allocate
parameter_list|(
name|char
modifier|*
name|driver
parameter_list|,
name|int
name|unit
parameter_list|,
name|void
modifier|*
name|id
parameter_list|,
name|kbd_callback_func_t
modifier|*
name|func
parameter_list|,
name|void
modifier|*
name|arg
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|kbd_release
parameter_list|(
name|keyboard_t
modifier|*
name|kbd
parameter_list|,
name|void
modifier|*
name|id
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|kbd_change_callback
parameter_list|(
name|keyboard_t
modifier|*
name|kbd
parameter_list|,
name|void
modifier|*
name|id
parameter_list|,
name|kbd_callback_func_t
modifier|*
name|func
parameter_list|,
name|void
modifier|*
name|arg
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|kbd_find_keyboard
parameter_list|(
name|char
modifier|*
name|driver
parameter_list|,
name|int
name|unit
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|keyboard_t
modifier|*
name|kbd_get_keyboard
parameter_list|(
name|int
name|index
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* a back door for the console driver to tickle the keyboard driver XXX */
end_comment

begin_function_decl
name|int
name|kbd_configure
parameter_list|(
name|int
name|flags
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* see `kb_config' above for flag bit definitions */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|KBD_INSTALL_CDEV
end_ifdef

begin_comment
comment|/* virtual keyboard cdev driver functions */
end_comment

begin_function_decl
name|int
name|kbd_attach
parameter_list|(
name|keyboard_t
modifier|*
name|kbd
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|kbd_detach
parameter_list|(
name|keyboard_t
modifier|*
name|kbd
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* KBD_INSTALL_CDEV */
end_comment

begin_comment
comment|/* generic low-level keyboard functions */
end_comment

begin_comment
comment|/* shift key state */
end_comment

begin_define
define|#
directive|define
name|SHIFTS1
value|(1<< 16)
end_define

begin_define
define|#
directive|define
name|SHIFTS2
value|(1<< 17)
end_define

begin_define
define|#
directive|define
name|SHIFTS
value|(SHIFTS1 | SHIFTS2)
end_define

begin_define
define|#
directive|define
name|CTLS1
value|(1<< 18)
end_define

begin_define
define|#
directive|define
name|CTLS2
value|(1<< 19)
end_define

begin_define
define|#
directive|define
name|CTLS
value|(CTLS1 | CTLS2)
end_define

begin_define
define|#
directive|define
name|ALTS1
value|(1<< 20)
end_define

begin_define
define|#
directive|define
name|ALTS2
value|(1<< 21)
end_define

begin_define
define|#
directive|define
name|ALTS
value|(ALTS1 | ALTS2)
end_define

begin_define
define|#
directive|define
name|AGRS1
value|(1<< 22)
end_define

begin_define
define|#
directive|define
name|AGRS2
value|(1<< 23)
end_define

begin_define
define|#
directive|define
name|AGRS
value|(AGRS1 | AGRS2)
end_define

begin_define
define|#
directive|define
name|METAS1
value|(1<< 24)
end_define

begin_define
define|#
directive|define
name|METAS2
value|(1<< 25)
end_define

begin_define
define|#
directive|define
name|METAS
value|(METAS1 | METAS2)
end_define

begin_define
define|#
directive|define
name|NLKDOWN
value|(1<< 26)
end_define

begin_define
define|#
directive|define
name|SLKDOWN
value|(1<< 27)
end_define

begin_define
define|#
directive|define
name|CLKDOWN
value|(1<< 28)
end_define

begin_define
define|#
directive|define
name|ALKDOWN
value|(1<< 29)
end_define

begin_define
define|#
directive|define
name|SHIFTAON
value|(1<< 30)
end_define

begin_comment
comment|/* lock key state (defined in machine/console.h) */
end_comment

begin_comment
comment|/* #define CLKED		LED_CAP #define NLKED		LED_NUM #define SLKED		LED_SCR #define ALKED		(1<< 3) #define LOCK_MASK	(CLKED | NLKED | SLKED | ALKED) #define LED_CAP		(1<< 0) #define LED_NUM		(1<< 1) #define LED_SCR		(1<< 2) #define LED_MASK	(LED_CAP | LED_NUM | LED_SCR) */
end_comment

begin_decl_stmt
name|kbd_get_fkeystr_t
name|genkbd_get_fkeystr
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|kbd_diag_t
name|genkbd_diag
decl_stmt|;
end_decl_stmt

begin_function_decl
name|int
name|genkbd_commonioctl
parameter_list|(
name|keyboard_t
modifier|*
name|kbd
parameter_list|,
name|u_long
name|cmd
parameter_list|,
name|caddr_t
name|arg
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|genkbd_keyaction
parameter_list|(
name|keyboard_t
modifier|*
name|kbd
parameter_list|,
name|int
name|keycode
parameter_list|,
name|int
name|up
parameter_list|,
name|int
modifier|*
name|shiftstate
parameter_list|,
name|int
modifier|*
name|accents
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
comment|/* !_DEV_KBD_KBDREG_H_ */
end_comment

end_unit

