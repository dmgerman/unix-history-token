begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Author: Tatu Ylonen<ylo@cs.hut.fi>  * 	SGTTY stuff contributed by Janne Snabb<snabb@niksula.hut.fi>  * Copyright (c) 1995 Tatu Ylonen<ylo@cs.hut.fi>, Espoo, Finland  *                    All rights reserved  *  * As far as I am concerned, the code I have written for this software  * can be used freely for any purpose.  Any derived versions of this  * software must be clearly marked as such, and if the derived work is  * incompatible with the protocol description in the RFC file, it must be  * called by a name other than "ssh" or "Secure Shell".  */
end_comment

begin_comment
comment|/* RCSID("$OpenBSD: ttymodes.h,v 1.9 2000/09/07 20:27:55 deraadt Exp $"); */
end_comment

begin_comment
comment|/* The tty mode description is a stream of bytes.  The stream consists of  * opcode-arguments pairs.  It is terminated by opcode TTY_OP_END (0).  * Opcodes 1-127 have one-byte arguments.  Opcodes 128-159 have integer  * arguments.  Opcodes 160-255 are not yet defined, and cause parsing to  * stop (they should only be used after any other data).  *  * The client puts in the stream any modes it knows about, and the  * server ignores any modes it does not know about.  This allows some degree  * of machine-independence, at least between systems that use a posix-like  * tty interface.  The protocol can support other systems as well, but might  * require reimplementing as mode names would likely be different.  */
end_comment

begin_comment
comment|/*  * Some constants and prototypes are defined in packet.h; this file  * is only intended for including from ttymodes.c.  */
end_comment

begin_comment
comment|/* termios macro */
end_comment

begin_comment
comment|/* sgtty macro */
end_comment

begin_comment
comment|/* name, op */
end_comment

begin_macro
name|TTYCHAR
argument_list|(
argument|VINTR
argument_list|,
literal|1
argument_list|)
end_macro

begin_macro
name|SGTTYCHAR
argument_list|(
argument|tiotc.t_intrc
argument_list|,
literal|1
argument_list|)
end_macro

begin_macro
name|TTYCHAR
argument_list|(
argument|VQUIT
argument_list|,
literal|2
argument_list|)
end_macro

begin_macro
name|SGTTYCHAR
argument_list|(
argument|tiotc.t_quitc
argument_list|,
literal|2
argument_list|)
end_macro

begin_macro
name|TTYCHAR
argument_list|(
argument|VERASE
argument_list|,
literal|3
argument_list|)
end_macro

begin_macro
name|SGTTYCHAR
argument_list|(
argument|tio.sg_erase
argument_list|,
literal|3
argument_list|)
end_macro

begin_if
if|#
directive|if
name|defined
argument_list|(
name|VKILL
argument_list|)
end_if

begin_macro
name|TTYCHAR
argument_list|(
argument|VKILL
argument_list|,
literal|4
argument_list|)
end_macro

begin_macro
name|SGTTYCHAR
argument_list|(
argument|tio.sg_kill
argument_list|,
literal|4
argument_list|)
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* VKILL */
end_comment

begin_macro
name|TTYCHAR
argument_list|(
argument|VEOF
argument_list|,
literal|5
argument_list|)
end_macro

begin_macro
name|SGTTYCHAR
argument_list|(
argument|tiotc.t_eofc
argument_list|,
literal|5
argument_list|)
end_macro

begin_if
if|#
directive|if
name|defined
argument_list|(
name|VEOL
argument_list|)
end_if

begin_macro
name|TTYCHAR
argument_list|(
argument|VEOL
argument_list|,
literal|6
argument_list|)
end_macro

begin_macro
name|SGTTYCHAR
argument_list|(
argument|tiotc.t_brkc
argument_list|,
literal|6
argument_list|)
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* VEOL */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|VEOL2
end_ifdef

begin_comment
comment|/* n/a */
end_comment

begin_macro
name|TTYCHAR
argument_list|(
argument|VEOL2
argument_list|,
literal|7
argument_list|)
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* VEOL2 */
end_comment

begin_macro
name|TTYCHAR
argument_list|(
argument|VSTART
argument_list|,
literal|8
argument_list|)
end_macro

begin_macro
name|SGTTYCHAR
argument_list|(
argument|tiotc.t_startc
argument_list|,
literal|8
argument_list|)
end_macro

begin_macro
name|TTYCHAR
argument_list|(
argument|VSTOP
argument_list|,
literal|9
argument_list|)
end_macro

begin_macro
name|SGTTYCHAR
argument_list|(
argument|tiotc.t_stopc
argument_list|,
literal|9
argument_list|)
end_macro

begin_if
if|#
directive|if
name|defined
argument_list|(
name|VSUSP
argument_list|)
end_if

begin_macro
name|TTYCHAR
argument_list|(
argument|VSUSP
argument_list|,
literal|10
argument_list|)
end_macro

begin_macro
name|SGTTYCHAR
argument_list|(
argument|tioltc.t_suspc
argument_list|,
literal|10
argument_list|)
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* VSUSP */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|VDSUSP
argument_list|)
end_if

begin_macro
name|TTYCHAR
argument_list|(
argument|VDSUSP
argument_list|,
literal|11
argument_list|)
end_macro

begin_macro
name|SGTTYCHAR
argument_list|(
argument|tioltc.t_dsuspc
argument_list|,
literal|11
argument_list|)
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* VDSUSP */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|VREPRINT
argument_list|)
end_if

begin_macro
name|TTYCHAR
argument_list|(
argument|VREPRINT
argument_list|,
literal|12
argument_list|)
end_macro

begin_macro
name|SGTTYCHAR
argument_list|(
argument|tioltc.t_rprntc
argument_list|,
literal|12
argument_list|)
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* VREPRINT */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|VWERASE
argument_list|)
end_if

begin_macro
name|TTYCHAR
argument_list|(
argument|VWERASE
argument_list|,
literal|13
argument_list|)
end_macro

begin_macro
name|SGTTYCHAR
argument_list|(
argument|tioltc.t_werasc
argument_list|,
literal|13
argument_list|)
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* VWERASE */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|VLNEXT
argument_list|)
end_if

begin_macro
name|TTYCHAR
argument_list|(
argument|VLNEXT
argument_list|,
literal|14
argument_list|)
end_macro

begin_macro
name|SGTTYCHAR
argument_list|(
argument|tioltc.t_lnextc
argument_list|,
literal|14
argument_list|)
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* VLNEXT */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|VFLUSH
argument_list|)
end_if

begin_macro
name|TTYCHAR
argument_list|(
argument|VFLUSH
argument_list|,
literal|15
argument_list|)
end_macro

begin_macro
name|SGTTYCHAR
argument_list|(
argument|tioltc.t_flushc
argument_list|,
literal|15
argument_list|)
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* VFLUSH */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|VSWTCH
end_ifdef

begin_macro
name|TTYCHAR
argument_list|(
argument|VSWTCH
argument_list|,
literal|16
argument_list|)
end_macro

begin_comment
comment|/* n/a */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* VSWTCH */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|VSTATUS
argument_list|)
end_if

begin_macro
name|TTYCHAR
argument_list|(
argument|VSTATUS
argument_list|,
literal|17
argument_list|)
end_macro

begin_macro
name|SGTTYCHAR
argument_list|(
argument|tiots.tc_statusc
argument_list|,
literal|17
argument_list|)
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* VSTATUS */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|VDISCARD
end_ifdef

begin_macro
name|TTYCHAR
argument_list|(
argument|VDISCARD
argument_list|,
literal|18
argument_list|)
end_macro

begin_comment
comment|/* n/a */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* VDISCARD */
end_comment

begin_comment
comment|/* name, field, op */
end_comment

begin_macro
name|TTYMODE
argument_list|(
argument|IGNPAR
argument_list|,
argument|c_iflag
argument_list|,
literal|30
argument_list|)
end_macro

begin_comment
comment|/* n/a */
end_comment

begin_macro
name|TTYMODE
argument_list|(
argument|PARMRK
argument_list|,
argument|c_iflag
argument_list|,
literal|31
argument_list|)
end_macro

begin_comment
comment|/* n/a */
end_comment

begin_macro
name|TTYMODE
argument_list|(
argument|INPCK
argument_list|,
argument|c_iflag
argument_list|,
literal|32
argument_list|)
end_macro

begin_macro
name|SGTTYMODEN
argument_list|(
argument|ANYP
argument_list|,
argument|tio.sg_flags
argument_list|,
literal|32
argument_list|)
end_macro

begin_macro
name|TTYMODE
argument_list|(
argument|ISTRIP
argument_list|,
argument|c_iflag
argument_list|,
literal|33
argument_list|)
end_macro

begin_macro
name|SGTTYMODEN
argument_list|(
argument|LPASS8
argument_list|,
argument|tiolm
argument_list|,
literal|33
argument_list|)
end_macro

begin_macro
name|TTYMODE
argument_list|(
argument|INLCR
argument_list|,
argument|c_iflag
argument_list|,
literal|34
argument_list|)
end_macro

begin_comment
comment|/* n/a */
end_comment

begin_macro
name|TTYMODE
argument_list|(
argument|IGNCR
argument_list|,
argument|c_iflag
argument_list|,
literal|35
argument_list|)
end_macro

begin_comment
comment|/* n/a */
end_comment

begin_macro
name|TTYMODE
argument_list|(
argument|ICRNL
argument_list|,
argument|c_iflag
argument_list|,
literal|36
argument_list|)
end_macro

begin_macro
name|SGTTYMODE
argument_list|(
argument|CRMOD
argument_list|,
argument|tio.sg_flags
argument_list|,
literal|36
argument_list|)
end_macro

begin_if
if|#
directive|if
name|defined
argument_list|(
name|IUCLC
argument_list|)
end_if

begin_macro
name|TTYMODE
argument_list|(
argument|IUCLC
argument_list|,
argument|c_iflag
argument_list|,
literal|37
argument_list|)
end_macro

begin_macro
name|SGTTYMODE
argument_list|(
argument|LCASE
argument_list|,
argument|tio.sg_flags
argument_list|,
literal|37
argument_list|)
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_macro
name|TTYMODE
argument_list|(
argument|IXON
argument_list|,
argument|c_iflag
argument_list|,
literal|38
argument_list|)
end_macro

begin_comment
comment|/* n/a */
end_comment

begin_macro
name|TTYMODE
argument_list|(
argument|IXANY
argument_list|,
argument|c_iflag
argument_list|,
literal|39
argument_list|)
end_macro

begin_macro
name|SGTTYMODEN
argument_list|(
argument|LDECCTQ
argument_list|,
argument|tiolm
argument_list|,
literal|39
argument_list|)
end_macro

begin_macro
name|TTYMODE
argument_list|(
argument|IXOFF
argument_list|,
argument|c_iflag
argument_list|,
literal|40
argument_list|)
end_macro

begin_macro
name|SGTTYMODE
argument_list|(
argument|TANDEM
argument_list|,
argument|tio.sg_flags
argument_list|,
literal|40
argument_list|)
end_macro

begin_ifdef
ifdef|#
directive|ifdef
name|IMAXBEL
end_ifdef

begin_macro
name|TTYMODE
argument_list|(
argument|IMAXBEL
argument_list|,
argument|c_iflag
argument_list|,
literal|41
argument_list|)
end_macro

begin_comment
comment|/* n/a */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* IMAXBEL */
end_comment

begin_macro
name|TTYMODE
argument_list|(
argument|ISIG
argument_list|,
argument|c_lflag
argument_list|,
literal|50
argument_list|)
end_macro

begin_comment
comment|/* n/a */
end_comment

begin_macro
name|TTYMODE
argument_list|(
argument|ICANON
argument_list|,
argument|c_lflag
argument_list|,
literal|51
argument_list|)
end_macro

begin_macro
name|SGTTYMODEN
argument_list|(
argument|CBREAK
argument_list|,
argument|tio.sg_flags
argument_list|,
literal|51
argument_list|)
end_macro

begin_ifdef
ifdef|#
directive|ifdef
name|XCASE
end_ifdef

begin_macro
name|TTYMODE
argument_list|(
argument|XCASE
argument_list|,
argument|c_lflag
argument_list|,
literal|52
argument_list|)
end_macro

begin_comment
comment|/* n/a */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_macro
name|TTYMODE
argument_list|(
argument|ECHO
argument_list|,
argument|c_lflag
argument_list|,
literal|53
argument_list|)
end_macro

begin_macro
name|SGTTYMODE
argument_list|(
argument|ECHO
argument_list|,
argument|tio.sg_flags
argument_list|,
literal|53
argument_list|)
end_macro

begin_macro
name|TTYMODE
argument_list|(
argument|ECHOE
argument_list|,
argument|c_lflag
argument_list|,
literal|54
argument_list|)
end_macro

begin_macro
name|SGTTYMODE
argument_list|(
argument|LCRTERA
argument_list|,
argument|tiolm
argument_list|,
literal|54
argument_list|)
end_macro

begin_macro
name|TTYMODE
argument_list|(
argument|ECHOK
argument_list|,
argument|c_lflag
argument_list|,
literal|55
argument_list|)
end_macro

begin_macro
name|SGTTYMODE
argument_list|(
argument|LCRTKIL
argument_list|,
argument|tiolm
argument_list|,
literal|55
argument_list|)
end_macro

begin_macro
name|TTYMODE
argument_list|(
argument|ECHONL
argument_list|,
argument|c_lflag
argument_list|,
literal|56
argument_list|)
end_macro

begin_comment
comment|/* n/a */
end_comment

begin_macro
name|TTYMODE
argument_list|(
argument|NOFLSH
argument_list|,
argument|c_lflag
argument_list|,
literal|57
argument_list|)
end_macro

begin_macro
name|SGTTYMODE
argument_list|(
argument|LNOFLSH
argument_list|,
argument|tiolm
argument_list|,
literal|57
argument_list|)
end_macro

begin_macro
name|TTYMODE
argument_list|(
argument|TOSTOP
argument_list|,
argument|c_lflag
argument_list|,
literal|58
argument_list|)
end_macro

begin_macro
name|SGTTYMODE
argument_list|(
argument|LTOSTOP
argument_list|,
argument|tiolm
argument_list|,
literal|58
argument_list|)
end_macro

begin_ifdef
ifdef|#
directive|ifdef
name|IEXTEN
end_ifdef

begin_macro
name|TTYMODE
argument_list|(
argument|IEXTEN
argument_list|,
argument|c_lflag
argument_list|,
literal|59
argument_list|)
end_macro

begin_comment
comment|/* n/a */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* IEXTEN */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|ECHOCTL
argument_list|)
end_if

begin_macro
name|TTYMODE
argument_list|(
argument|ECHOCTL
argument_list|,
argument|c_lflag
argument_list|,
literal|60
argument_list|)
end_macro

begin_macro
name|SGTTYMODE
argument_list|(
argument|LCTLECH
argument_list|,
argument|tiolm
argument_list|,
literal|60
argument_list|)
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ECHOCTL */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|ECHOKE
end_ifdef

begin_macro
name|TTYMODE
argument_list|(
argument|ECHOKE
argument_list|,
argument|c_lflag
argument_list|,
literal|61
argument_list|)
end_macro

begin_comment
comment|/* n/a */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ECHOKE */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|PENDIN
argument_list|)
end_if

begin_macro
name|TTYMODE
argument_list|(
argument|PENDIN
argument_list|,
argument|c_lflag
argument_list|,
literal|62
argument_list|)
end_macro

begin_macro
name|SGTTYMODE
argument_list|(
argument|LPENDIN
argument_list|,
argument|tiolm
argument_list|,
literal|62
argument_list|)
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* PENDIN */
end_comment

begin_macro
name|TTYMODE
argument_list|(
argument|OPOST
argument_list|,
argument|c_oflag
argument_list|,
literal|70
argument_list|)
end_macro

begin_comment
comment|/* n/a */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|OLCUC
argument_list|)
end_if

begin_macro
name|TTYMODE
argument_list|(
argument|OLCUC
argument_list|,
argument|c_oflag
argument_list|,
literal|71
argument_list|)
end_macro

begin_macro
name|SGTTYMODE
argument_list|(
argument|LCASE
argument_list|,
argument|tio.sg_flags
argument_list|,
literal|71
argument_list|)
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_macro
name|TTYMODE
argument_list|(
argument|ONLCR
argument_list|,
argument|c_oflag
argument_list|,
literal|72
argument_list|)
end_macro

begin_macro
name|SGTTYMODE
argument_list|(
argument|CRMOD
argument_list|,
argument|tio.sg_flags
argument_list|,
literal|72
argument_list|)
end_macro

begin_ifdef
ifdef|#
directive|ifdef
name|OCRNL
end_ifdef

begin_macro
name|TTYMODE
argument_list|(
argument|OCRNL
argument_list|,
argument|c_oflag
argument_list|,
literal|73
argument_list|)
end_macro

begin_comment
comment|/* n/a */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|ONOCR
end_ifdef

begin_macro
name|TTYMODE
argument_list|(
argument|ONOCR
argument_list|,
argument|c_oflag
argument_list|,
literal|74
argument_list|)
end_macro

begin_comment
comment|/* n/a */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|ONLRET
end_ifdef

begin_macro
name|TTYMODE
argument_list|(
argument|ONLRET
argument_list|,
argument|c_oflag
argument_list|,
literal|75
argument_list|)
end_macro

begin_comment
comment|/* n/a */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_macro
name|TTYMODE
argument_list|(
argument|CS7
argument_list|,
argument|c_cflag
argument_list|,
literal|90
argument_list|)
end_macro

begin_comment
comment|/* n/a */
end_comment

begin_macro
name|TTYMODE
argument_list|(
argument|CS8
argument_list|,
argument|c_cflag
argument_list|,
literal|91
argument_list|)
end_macro

begin_macro
name|SGTTYMODE
argument_list|(
argument|LPASS8
argument_list|,
argument|tiolm
argument_list|,
literal|91
argument_list|)
end_macro

begin_macro
name|TTYMODE
argument_list|(
argument|PARENB
argument_list|,
argument|c_cflag
argument_list|,
literal|92
argument_list|)
end_macro

begin_comment
comment|/* n/a */
end_comment

begin_macro
name|TTYMODE
argument_list|(
argument|PARODD
argument_list|,
argument|c_cflag
argument_list|,
literal|93
argument_list|)
end_macro

begin_macro
name|SGTTYMODE
argument_list|(
argument|ODDP
argument_list|,
argument|tio.sg_flags
argument_list|,
literal|93
argument_list|)
end_macro

end_unit

