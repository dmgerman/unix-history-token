begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2009 The FreeBSD Foundation  * All rights reserved.  *  * This software was developed by Ed Schouten under sponsorship from the  * FreeBSD Foundation.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SYS_TERMINAL_H_
end_ifndef

begin_define
define|#
directive|define
name|_SYS_TERMINAL_H_
end_define

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<sys/_lock.h>
end_include

begin_include
include|#
directive|include
file|<sys/_mutex.h>
end_include

begin_include
include|#
directive|include
file|<sys/cons.h>
end_include

begin_include
include|#
directive|include
file|<sys/linker_set.h>
end_include

begin_include
include|#
directive|include
file|<sys/ttycom.h>
end_include

begin_include
include|#
directive|include
file|<teken/teken.h>
end_include

begin_struct_decl
struct_decl|struct
name|terminal
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|thread
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|tty
struct_decl|;
end_struct_decl

begin_comment
comment|/*  * The terminal layer is an abstraction on top of the TTY layer and the  * console interface.  It can be used by system console drivers to  * easily interact with the kernel console and TTYs.  *  * Terminals contain terminal emulators, which means console drivers  * don't need to implement their own terminal emulator. The terminal  * emulator deals with UTF-8 exclusively. This means that term_char_t,  * the data type used to store input/output characters will always  * contain Unicode codepoints.  *  * To save memory usage, the top bits of term_char_t will contain other  * attributes, like colors. Right now term_char_t is composed as  * follows:  *  *  Bits  Meaning  *  0-20: Character value  * 21-25: Bold, underline, blink, reverse, right part of CJK fullwidth character  * 26-28: Foreground color  * 29-31: Background color  */
end_comment

begin_typedef
typedef|typedef
name|uint32_t
name|term_char_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|TCHAR_CHARACTER
parameter_list|(
name|c
parameter_list|)
value|((c)& 0x1fffff)
end_define

begin_define
define|#
directive|define
name|TCHAR_FORMAT
parameter_list|(
name|c
parameter_list|)
value|(((c)>> 21)& 0x1f)
end_define

begin_define
define|#
directive|define
name|TCHAR_FGCOLOR
parameter_list|(
name|c
parameter_list|)
value|(((c)>> 26)& 0x7)
end_define

begin_define
define|#
directive|define
name|TCHAR_BGCOLOR
parameter_list|(
name|c
parameter_list|)
value|((c)>> 29)
end_define

begin_typedef
typedef|typedef
name|teken_color_t
name|term_color_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|TCOLOR_LIGHT
parameter_list|(
name|c
parameter_list|)
value|((c) | 0x8)
end_define

begin_define
define|#
directive|define
name|TCOLOR_DARK
parameter_list|(
name|c
parameter_list|)
value|((c)& ~0x8)
end_define

begin_typedef
typedef|typedef
name|teken_pos_t
name|term_pos_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|teken_rect_t
name|term_rect_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|void
name|tc_cursor_t
parameter_list|(
name|struct
name|terminal
modifier|*
name|tm
parameter_list|,
specifier|const
name|term_pos_t
modifier|*
name|p
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|void
name|tc_putchar_t
parameter_list|(
name|struct
name|terminal
modifier|*
name|tm
parameter_list|,
specifier|const
name|term_pos_t
modifier|*
name|p
parameter_list|,
name|term_char_t
name|c
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|void
name|tc_fill_t
parameter_list|(
name|struct
name|terminal
modifier|*
name|tm
parameter_list|,
specifier|const
name|term_rect_t
modifier|*
name|r
parameter_list|,
name|term_char_t
name|c
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|void
name|tc_copy_t
parameter_list|(
name|struct
name|terminal
modifier|*
name|tm
parameter_list|,
specifier|const
name|term_rect_t
modifier|*
name|r
parameter_list|,
specifier|const
name|term_pos_t
modifier|*
name|p
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|void
name|tc_param_t
parameter_list|(
name|struct
name|terminal
modifier|*
name|tm
parameter_list|,
name|int
name|cmd
parameter_list|,
name|unsigned
name|int
name|arg
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|void
name|tc_done_t
parameter_list|(
name|struct
name|terminal
modifier|*
name|tm
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|void
name|tc_cnprobe_t
parameter_list|(
name|struct
name|terminal
modifier|*
name|tm
parameter_list|,
name|struct
name|consdev
modifier|*
name|cd
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|int
name|tc_cngetc_t
parameter_list|(
name|struct
name|terminal
modifier|*
name|tm
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|void
name|tc_opened_t
parameter_list|(
name|struct
name|terminal
modifier|*
name|tm
parameter_list|,
name|int
name|opened
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|int
name|tc_ioctl_t
parameter_list|(
name|struct
name|terminal
modifier|*
name|tm
parameter_list|,
name|u_long
name|cmd
parameter_list|,
name|caddr_t
name|data
parameter_list|,
name|struct
name|thread
modifier|*
name|td
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|int
name|tc_mmap_t
parameter_list|(
name|struct
name|terminal
modifier|*
name|tm
parameter_list|,
name|vm_ooffset_t
name|offset
parameter_list|,
name|vm_paddr_t
modifier|*
name|paddr
parameter_list|,
name|int
name|nprot
parameter_list|,
name|vm_memattr_t
modifier|*
name|memattr
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|void
name|tc_bell_t
parameter_list|(
name|struct
name|terminal
modifier|*
name|tm
parameter_list|)
function_decl|;
end_typedef

begin_struct
struct|struct
name|terminal_class
block|{
comment|/* Terminal emulator. */
name|tc_cursor_t
modifier|*
name|tc_cursor
decl_stmt|;
name|tc_putchar_t
modifier|*
name|tc_putchar
decl_stmt|;
name|tc_fill_t
modifier|*
name|tc_fill
decl_stmt|;
name|tc_copy_t
modifier|*
name|tc_copy
decl_stmt|;
name|tc_param_t
modifier|*
name|tc_param
decl_stmt|;
name|tc_done_t
modifier|*
name|tc_done
decl_stmt|;
comment|/* Low-level console interface. */
name|tc_cnprobe_t
modifier|*
name|tc_cnprobe
decl_stmt|;
name|tc_cngetc_t
modifier|*
name|tc_cngetc
decl_stmt|;
comment|/* Misc. */
name|tc_opened_t
modifier|*
name|tc_opened
decl_stmt|;
name|tc_ioctl_t
modifier|*
name|tc_ioctl
decl_stmt|;
name|tc_mmap_t
modifier|*
name|tc_mmap
decl_stmt|;
name|tc_bell_t
modifier|*
name|tc_bell
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|terminal
block|{
specifier|const
name|struct
name|terminal_class
modifier|*
name|tm_class
decl_stmt|;
name|void
modifier|*
name|tm_softc
decl_stmt|;
name|struct
name|mtx
name|tm_mtx
decl_stmt|;
name|struct
name|tty
modifier|*
name|tm_tty
decl_stmt|;
name|teken_t
name|tm_emulator
decl_stmt|;
name|struct
name|winsize
name|tm_winsize
decl_stmt|;
name|unsigned
name|int
name|tm_flags
decl_stmt|;
define|#
directive|define
name|TF_MUTE
value|0x1
comment|/* Drop incoming data. */
define|#
directive|define
name|TF_BELL
value|0x2
comment|/* Bell needs to be sent. */
define|#
directive|define
name|TF_CONS
value|0x4
comment|/* Console device (needs spinlock). */
name|struct
name|consdev
modifier|*
name|consdev
decl_stmt|;
block|}
struct|;
end_struct

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_function_decl
name|struct
name|terminal
modifier|*
name|terminal_alloc
parameter_list|(
specifier|const
name|struct
name|terminal_class
modifier|*
name|tc
parameter_list|,
name|void
modifier|*
name|softc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|terminal_maketty
parameter_list|(
name|struct
name|terminal
modifier|*
name|tm
parameter_list|,
specifier|const
name|char
modifier|*
name|fmt
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|terminal_set_winsize_blank
parameter_list|(
name|struct
name|terminal
modifier|*
name|tm
parameter_list|,
specifier|const
name|struct
name|winsize
modifier|*
name|size
parameter_list|,
name|int
name|blank
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|terminal_set_winsize
parameter_list|(
name|struct
name|terminal
modifier|*
name|tm
parameter_list|,
specifier|const
name|struct
name|winsize
modifier|*
name|size
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|terminal_mute
parameter_list|(
name|struct
name|terminal
modifier|*
name|tm
parameter_list|,
name|int
name|yes
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|terminal_input_char
parameter_list|(
name|struct
name|terminal
modifier|*
name|tm
parameter_list|,
name|term_char_t
name|c
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|terminal_input_raw
parameter_list|(
name|struct
name|terminal
modifier|*
name|tm
parameter_list|,
name|char
name|c
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|terminal_input_special
parameter_list|(
name|struct
name|terminal
modifier|*
name|tm
parameter_list|,
name|unsigned
name|int
name|k
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|termcn_cnregister
parameter_list|(
name|struct
name|terminal
modifier|*
name|tm
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Kernel console helper interface. */
end_comment

begin_decl_stmt
specifier|extern
specifier|const
name|struct
name|consdev_ops
name|termcn_cnops
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|TERMINAL_DECLARE_EARLY
parameter_list|(
name|name
parameter_list|,
name|class
parameter_list|,
name|softc
parameter_list|)
define|\
value|static struct terminal name = {					\ 		.tm_class =&class,					\ 		.tm_softc = softc,					\ 		.tm_flags = TF_CONS,					\ 	};								\ 	CONSOLE_DEVICE(name ## _consdev, termcn_cnops,&name)
end_define

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
comment|/* !_SYS_TERMINAL_H_ */
end_comment

end_unit

