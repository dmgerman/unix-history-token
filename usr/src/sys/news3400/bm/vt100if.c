begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1992 The Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Sony Corp. and Kazumasa Utashiro of Software Research Associates, Inc.  *  * %sccs.include.redist.c%  *  * from: $Hdr: vt100if.c,v 4.300 91/06/09 06:15:02 root Rel41 $ SONY  *  *	@(#)vt100if.c	7.3 (Berkeley) %G%  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|IPC_MRX
end_ifdef

begin_include
include|#
directive|include
file|"types.h"
end_include

begin_include
include|#
directive|include
file|"ioctl.h"
end_include

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* IPC_MRX */
end_comment

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|CPU_SINGLE
end_ifdef

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CPU_SINGLE */
end_comment

begin_include
include|#
directive|include
file|<sys/ioctl.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* IPC_MRX */
end_comment

begin_if
if|#
directive|if
name|CPU_SINGLE
end_if

begin_include
include|#
directive|include
file|<news3400/sio/scc.h>
end_include

begin_include
include|#
directive|include
file|<news3400/sio/sccparam.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CPU_SINGLE */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|IPC_MRX
end_ifdef

begin_include
include|#
directive|include
file|"scc.h"
end_include

begin_include
include|#
directive|include
file|"sccparam.h"
end_include

begin_include
include|#
directive|include
file|"cio.h"
end_include

begin_define
define|#
directive|define
name|SCC_KEYBOARD
value|0
end_define

begin_undef
undef|#
directive|undef
name|MAX_CIO
end_undef

begin_include
include|#
directive|include
file|"object.h"
end_include

begin_include
include|#
directive|include
file|"process.h"
end_include

begin_include
include|#
directive|include
file|"config.h"
end_include

begin_define
define|#
directive|define
name|kbd_ioctl
parameter_list|(
name|chan
parameter_list|,
name|cmd
parameter_list|,
name|argp
parameter_list|)
value|{ \         if (kb_ioctl) \                 (*kb_ioctl)(chan, cmd, argp); \ }
end_define

begin_decl_stmt
specifier|extern
name|int
name|bitmap_use
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* IPC_MRX */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|IPC_MRX
end_ifdef

begin_include
include|#
directive|include
file|"../../iop/kbreg.h"
end_include

begin_include
include|#
directive|include
file|"../../iop/keyboard.h"
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|IPC_3CPU
end_ifdef

begin_include
include|#
directive|include
file|"../../ubdev/msgio.h"
end_include

begin_decl_stmt
specifier|extern
name|int
modifier|*
name|gcpu_semadr
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* IPC_3CPU */
end_comment

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* IPC_MRX */
end_comment

begin_include
include|#
directive|include
file|<news3400/iop/keyboard.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* IPC_MRX */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|CPU_SINGLE
end_ifdef

begin_include
include|#
directive|include
file|<machine/cpu.h>
end_include

begin_define
define|#
directive|define
name|PRE_EMPT
value|need_resched()
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
name|int
name|tmode
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|int
name|char_mask
init|=
literal|0x7f
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|bm_todo
decl_stmt|;
end_decl_stmt

begin_macro
name|vt100_write
argument_list|(
argument|chan
argument_list|,
argument|buf
argument_list|,
argument|count
argument_list|)
end_macro

begin_decl_stmt
name|int
name|chan
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|register
name|char
modifier|*
name|buf
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|register
name|int
name|count
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|bm_todo
operator|=
name|count
expr_stmt|;
name|rst_dimmer_cnt
argument_list|()
expr_stmt|;
ifdef|#
directive|ifdef
name|IPC_MRX
ifdef|#
directive|ifdef
name|IPC_3CPU
operator|*
name|gcpu_semadr
operator|=
literal|1
expr_stmt|;
endif|#
directive|endif
name|sem_wait
argument_list|(
name|bitmap_use
argument_list|)
expr_stmt|;
endif|#
directive|endif
while|while
condition|(
name|bm_todo
operator|--
operator|>
literal|0
condition|)
name|Putchar
argument_list|(
operator|*
name|buf
operator|++
operator|&
name|char_mask
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|Putchar
argument_list|(
literal|0
argument_list|,
literal|1
argument_list|)
expr_stmt|;
ifdef|#
directive|ifdef
name|IPC_MRX
ifdef|#
directive|ifdef
name|IPC_3CPU
operator|*
name|gcpu_semadr
operator|=
literal|0
expr_stmt|;
endif|#
directive|endif
name|sem_signal
argument_list|(
name|bitmap_use
argument_list|)
expr_stmt|;
endif|#
directive|endif
ifdef|#
directive|ifdef
name|CPU_SINGLE
name|PRE_EMPT
expr_stmt|;
endif|#
directive|endif
return|return
operator|(
name|count
operator|)
return|;
block|}
end_block

begin_macro
name|vt100_read
argument_list|(
argument|chan
argument_list|,
argument|buf
argument_list|,
argument|count
argument_list|)
end_macro

begin_decl_stmt
name|int
name|chan
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|buf
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|count
decl_stmt|;
end_decl_stmt

begin_block
block|{
ifdef|#
directive|ifdef
name|IPC_MRX
if|if
condition|(
name|kb_read
condition|)
block|{
return|return
operator|(
call|(
modifier|*
name|kb_read
call|)
argument_list|(
name|chan
argument_list|,
name|buf
argument_list|,
name|count
argument_list|)
operator|)
return|;
block|}
else|else
block|{
return|return
operator|(
operator|-
literal|1
operator|)
return|;
block|}
else|#
directive|else
comment|/* IPC_MRX */
return|return
operator|(
name|kbd_read
argument_list|(
name|chan
argument_list|,
name|buf
argument_list|,
name|count
argument_list|)
operator|)
return|;
endif|#
directive|endif
comment|/* IPC_MRX */
block|}
end_block

begin_ifdef
ifdef|#
directive|ifdef
name|CPU_SINGLE
end_ifdef

begin_decl_stmt
specifier|static
name|int
name|param
decl_stmt|;
end_decl_stmt

begin_macro
name|bitmap_set_param
argument_list|(
argument|c
argument_list|)
end_macro

begin_decl_stmt
name|int
name|c
decl_stmt|;
end_decl_stmt

begin_block
block|{
if|if
condition|(
operator|(
name|c
operator|&
name|CHAR_SIZE
operator|)
operator|==
name|C7BIT
condition|)
block|{
name|char_mask
operator|=
literal|0x7f
expr_stmt|;
block|}
else|else
block|{
name|char_mask
operator|=
literal|0xff
expr_stmt|;
block|}
ifdef|#
directive|ifdef
name|KM_JIS
switch|switch
condition|(
name|c
operator|&
name|TERM_MODE
condition|)
block|{
case|case
name|CJIS
case|:
name|tmode
operator|=
name|KM_JIS
expr_stmt|;
break|break;
case|case
name|CSJIS
case|:
name|tmode
operator|=
name|KM_SJIS
expr_stmt|;
break|break;
case|case
name|CEUC
case|:
name|tmode
operator|=
name|KM_EUC
expr_stmt|;
break|break;
default|default:
name|tmode
operator|=
name|KM_ASCII
expr_stmt|;
break|break;
block|}
endif|#
directive|endif
name|param
operator|=
name|c
expr_stmt|;
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_block

begin_macro
name|bitmap_get_param
argument_list|()
end_macro

begin_block
block|{
return|return
operator|(
name|param
operator|)
return|;
block|}
end_block

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* CPU_SINGLE */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|IPC_MRX
end_ifdef

begin_define
define|#
directive|define
name|SCC_SETPARAMS
value|CIO_SETPARAMS
end_define

begin_define
define|#
directive|define
name|SCC_GETPARAMS
value|CIO_GETPARAMS
end_define

begin_define
define|#
directive|define
name|SCC_LINE_CHG
value|CIO_LINE_CHG
end_define

begin_define
define|#
directive|define
name|SCC_NREAD
value|CIO_NREAD
end_define

begin_define
define|#
directive|define
name|SCC_FLUSH
value|CIO_FLUSH
end_define

begin_define
define|#
directive|define
name|SCC_STOP
value|CIO_STOP
end_define

begin_define
define|#
directive|define
name|SCC_START
value|CIO_START
end_define

begin_define
define|#
directive|define
name|SCC_RESET
value|CIO_RESET
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* IPC_MRX */
end_comment

begin_macro
name|vt100_ioctl
argument_list|(
argument|chan
argument_list|,
argument|cmd
argument_list|,
argument|argp
argument_list|)
end_macro

begin_decl_stmt
name|int
name|chan
decl_stmt|,
name|cmd
decl_stmt|,
modifier|*
name|argp
decl_stmt|;
end_decl_stmt

begin_block
block|{
specifier|static
name|int
name|param
decl_stmt|;
switch|switch
condition|(
name|cmd
condition|)
block|{
case|case
name|SCC_SETPARAMS
case|:
name|param
operator|=
operator|*
name|argp
expr_stmt|;
if|if
condition|(
operator|(
name|param
operator|&
name|CHAR_SIZE
operator|)
operator|==
name|C7BIT
condition|)
name|char_mask
operator|=
literal|0x7f
expr_stmt|;
else|else
name|char_mask
operator|=
literal|0xff
expr_stmt|;
ifdef|#
directive|ifdef
name|KM_JIS
switch|switch
condition|(
name|param
operator|&
name|TERM_MODE
condition|)
block|{
case|case
name|CJIS
case|:
name|tmode
operator|=
name|KM_JIS
expr_stmt|;
break|break;
case|case
name|CSJIS
case|:
name|tmode
operator|=
name|KM_SJIS
expr_stmt|;
break|break;
case|case
name|CEUC
case|:
name|tmode
operator|=
name|KM_EUC
expr_stmt|;
break|break;
default|default:
name|tmode
operator|=
name|KM_ASCII
expr_stmt|;
break|break;
block|}
endif|#
directive|endif
return|return
operator|(
literal|0
operator|)
return|;
case|case
name|SCC_GETPARAMS
case|:
operator|*
name|argp
operator|=
name|param
expr_stmt|;
return|return
operator|(
literal|0
operator|)
return|;
case|case
name|SCC_LINE_CHG
case|:
return|return
operator|(
literal|0
operator|)
return|;
case|case
name|SCC_NREAD
case|:
name|kbd_ioctl
argument_list|(
name|SCC_KEYBOARD
argument_list|,
name|KIOCNREAD
argument_list|,
name|argp
argument_list|)
expr_stmt|;
return|return
operator|(
literal|0
operator|)
return|;
case|case
name|SCC_FLUSH
case|:
case|case
name|SCC_STOP
case|:
case|case
name|SCC_START
case|:
case|case
name|SCC_RESET
case|:
return|return
operator|(
literal|0
operator|)
return|;
default|default:
return|return
operator|(
operator|-
literal|1
operator|)
return|;
block|}
block|}
end_block

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CPU_SINGLE */
end_comment

end_unit

