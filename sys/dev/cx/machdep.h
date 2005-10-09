begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Cronyx DDK: platform dependent definitions.  *  * Copyright (C) 1998-1999 Cronyx Engineering  * Author: Alexander Kvitchenko,<aak@cronyx.ru>  *  * Copyright (C) 2001-2003 Cronyx Engineering.  * Author: Roman Kurakin,<rik@cronyx.ru>  *  * This software is distributed with NO WARRANTIES, not even the implied  * warranties for MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  *  * Authors grant any other persons or organisations permission to use  * or modify this software as long as this message is kept with the software,  * all derivative works or modified versions.  *  * Cronyx Id: machdep.h,v 1.3.4.3 2003/11/27 14:21:58 rik Exp $  * $FreeBSD$  */
end_comment

begin_comment
comment|/*  * DOS (Borland Turbo C++ 1.0)  */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|MSDOS
argument_list|)
operator|||
name|defined
argument_list|(
name|__MSDOS__
argument_list|)
end_if

begin_include
include|#
directive|include
file|<dos.h>
end_include

begin_include
include|#
directive|include
file|<string.h>
end_include

begin_define
define|#
directive|define
name|inb
parameter_list|(
name|port
parameter_list|)
value|inportb(port)
end_define

begin_define
define|#
directive|define
name|inw
parameter_list|(
name|port
parameter_list|)
value|inport(port)
end_define

begin_define
define|#
directive|define
name|outb
parameter_list|(
name|port
parameter_list|,
name|b
parameter_list|)
value|outportb(port,b)
end_define

begin_define
define|#
directive|define
name|outw
parameter_list|(
name|port
parameter_list|,
name|w
parameter_list|)
value|outport(port,w)
end_define

begin_define
define|#
directive|define
name|GETTICKS
parameter_list|()
value|biostime(0,0L)
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/*  * Windows NT  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|NDIS_MINIPORT_DRIVER
end_ifdef

begin_include
include|#
directive|include
file|<string.h>
end_include

begin_define
define|#
directive|define
name|inb
parameter_list|(
name|port
parameter_list|)
value|inp((unsigned short)(port))
end_define

begin_define
define|#
directive|define
name|inw
parameter_list|(
name|port
parameter_list|)
value|inpw((unsigned short)(port))
end_define

begin_define
define|#
directive|define
name|outb
parameter_list|(
name|port
parameter_list|,
name|b
parameter_list|)
value|outp((unsigned short)(port),b)
end_define

begin_define
define|#
directive|define
name|outw
parameter_list|(
name|port
parameter_list|,
name|w
parameter_list|)
value|outpw((unsigned short)(port),(unsigned short)(w))
end_define

begin_pragma
pragma|#
directive|pragma
name|warning
name|(
name|disable
name|:
name|4761
name|)
end_pragma

begin_pragma
pragma|#
directive|pragma
name|warning
name|(
name|disable
name|:
name|4242
name|)
end_pragma

begin_pragma
pragma|#
directive|pragma
name|warning
name|(
name|disable
name|:
name|4244
name|)
end_pragma

begin_define
define|#
directive|define
name|ulong64
value|unsigned __int64
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/*  * Linux  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__linux__
end_ifdef

begin_undef
undef|#
directive|undef
name|REALLY_SLOW_IO
end_undef

begin_include
include|#
directive|include
file|<asm/io.h>
end_include

begin_comment
comment|/* should swap outb() arguments */
end_comment

begin_include
include|#
directive|include
file|<linux/string.h>
end_include

begin_include
include|#
directive|include
file|<linux/delay.h>
end_include

begin_function
specifier|static
specifier|inline
name|void
name|__ddk_outb
parameter_list|(
name|unsigned
name|port
parameter_list|,
name|unsigned
name|char
name|byte
parameter_list|)
block|{
name|outb
argument_list|(
name|byte
argument_list|,
name|port
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|void
name|__ddk_outw
parameter_list|(
name|unsigned
name|port
parameter_list|,
name|unsigned
name|short
name|word
parameter_list|)
block|{
name|outw
argument_list|(
name|word
argument_list|,
name|port
argument_list|)
expr_stmt|;
block|}
end_function

begin_undef
undef|#
directive|undef
name|outb
end_undef

begin_undef
undef|#
directive|undef
name|outw
end_undef

begin_define
define|#
directive|define
name|outb
parameter_list|(
name|port
parameter_list|,
name|val
parameter_list|)
value|__ddk_outb(port, val)
end_define

begin_define
define|#
directive|define
name|outw
parameter_list|(
name|port
parameter_list|,
name|val
parameter_list|)
value|__ddk_outw(port, val)
end_define

begin_define
define|#
directive|define
name|GETTICKS
parameter_list|()
value|(jiffies * 200 / 11 / HZ)
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/*  * FreeBSD and BSD/OS  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__FreeBSD__
end_ifdef

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<machine/cpufunc.h>
end_include

begin_include
include|#
directive|include
file|<sys/libkern.h>
end_include

begin_include
include|#
directive|include
file|<sys/systm.h>
end_include

begin_define
define|#
directive|define
name|memset
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|)
value|bzero (a,c)
end_define

begin_define
define|#
directive|define
name|port_t
value|int
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|_SYS_CDEFS_H_
end_ifndef

begin_error
error|#
directive|error
error|this file needs sys/cdefs.h as a prerequisite
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|inline
end_ifndef

begin_ifdef
ifdef|#
directive|ifdef
name|__CC_SUPPORTS___INLINE__
end_ifdef

begin_define
define|#
directive|define
name|inline
value|__inline__
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|inline
end_define

begin_comment
comment|/**/
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ulong64
end_ifndef

begin_define
define|#
directive|define
name|ulong64
value|unsigned long long
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

