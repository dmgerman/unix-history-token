begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	va.c	3.5	%G%	*/
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|ERNIE
end_ifdef

begin_include
include|#
directive|include
file|"../h/param.h"
end_include

begin_include
include|#
directive|include
file|"../h/dir.h"
end_include

begin_include
include|#
directive|include
file|"../h/user.h"
end_include

begin_include
include|#
directive|include
file|"../h/buf.h"
end_include

begin_include
include|#
directive|include
file|"../h/systm.h"
end_include

begin_include
include|#
directive|include
file|"../h/map.h"
end_include

begin_include
include|#
directive|include
file|"../h/pte.h"
end_include

begin_include
include|#
directive|include
file|"../h/uba.h"
end_include

begin_include
include|#
directive|include
file|"../h/vcmd.h"
end_include

begin_comment
comment|/*  * Benson-Varian matrix printer/plotter.  Device "va", for "varian".  * dma interface driver  */
end_comment

begin_decl_stmt
name|int
name|vabdp
init|=
literal|1
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Used with ubasetup. */
end_comment

begin_function_decl
name|unsigned
name|minvaph
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* Maximum amount transferred by physio. */
end_comment

begin_define
define|#
directive|define
name|VAPRI
value|(PZERO-1)
end_define

begin_struct
struct|struct
name|varegs
block|{
comment|/* Unibus registers provided by va. */
name|unsigned
name|short
name|vabufaddr
decl_stmt|;
comment|/* DMA buffer address. */
name|short
name|vawcount
decl_stmt|;
comment|/* Negative of number of 16-bit 					   words to transfer by DMA. */
union|union
block|{
name|short
name|vacsrword
decl_stmt|;
comment|/* csr addressed as a word (for R). */
struct|struct
block|{
name|char
name|Vacsrlo
decl_stmt|;
name|char
name|Vacsrhi
decl_stmt|;
comment|/* High byte (command bytes go here). */
block|}
name|vacsrbytes
struct|;
comment|/* csr addressed as bytes (for W). */
block|}
name|vacsr
union|;
comment|/* Control/Status Register (csr). */
name|short
name|vadata
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|vacsrhi
value|vacsr.vacsrbytes.Vacsrhi
end_define

begin_define
define|#
directive|define
name|vacsrlo
value|vacsr.vacsrbytes.Vacsrlo
end_define

begin_define
define|#
directive|define
name|VAADDR
value|((struct varegs *)(UBA0_DEV + 0164000))
end_define

begin_comment
comment|/* vacsr.vacsrword bits: */
end_comment

begin_define
define|#
directive|define
name|ERROR
value|0100000
end_define

begin_comment
comment|/* R	Some error has occurred */
end_comment

begin_define
define|#
directive|define
name|NPRTIMO
value|01000
end_define

begin_comment
comment|/* R    DMA timeout error */
end_comment

begin_define
define|#
directive|define
name|NOTREADY
value|0400
end_define

begin_comment
comment|/* R	Something besides NPRTIMO */
end_comment

begin_define
define|#
directive|define
name|DONE
value|0200
end_define

begin_comment
comment|/* R	*/
end_comment

begin_define
define|#
directive|define
name|IENABLE
value|0100
end_define

begin_comment
comment|/* R/W	Interrupt enable */
end_comment

begin_define
define|#
directive|define
name|SUPPLIESLOW
value|04
end_define

begin_comment
comment|/* R	*/
end_comment

begin_define
define|#
directive|define
name|BOTOFFORM
value|02
end_define

begin_comment
comment|/* R	*/
end_comment

begin_define
define|#
directive|define
name|BYTEREVERSE
value|01
end_define

begin_comment
comment|/* R/W	Reverse byte order in words */
end_comment

begin_comment
comment|/* Command bytes sent to vacsrhi */
end_comment

begin_define
define|#
directive|define
name|VAPLOT
value|0340
end_define

begin_define
define|#
directive|define
name|VAPRINT
value|0100
end_define

begin_define
define|#
directive|define
name|VAPRINTPLOT
value|0160
end_define

begin_define
define|#
directive|define
name|VAAUTOSTEP
value|0244
end_define

begin_comment
comment|/* The following commands are not used in this driver: */
end_comment

begin_define
define|#
directive|define
name|VANOAUTOSTEP
value|0045
end_define

begin_define
define|#
directive|define
name|VAFORMFEED
value|0263
end_define

begin_define
define|#
directive|define
name|VASLEW
value|0265
end_define

begin_define
define|#
directive|define
name|VASTEP
value|0064
end_define

begin_struct
struct|struct
block|{
name|char
name|va_is_open
decl_stmt|;
name|char
name|va_busy
decl_stmt|;
name|int
name|va_state
decl_stmt|;
comment|/* State: bits are commands in vcmd.h. */
name|int
name|va_wcount
decl_stmt|;
name|int
name|va_bufp
decl_stmt|;
block|}
name|vainfo
struct|;
end_struct

begin_decl_stmt
name|int
name|va_ubinfo
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|buf
name|rvabuf
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Used by physio for a buffer. */
end_comment

begin_macro
name|vaopen
argument_list|()
end_macro

begin_block
block|{
if|if
condition|(
name|vainfo
operator|.
name|va_is_open
condition|)
block|{
comment|/* Can't open if it's already open. */
name|u
operator|.
name|u_error
operator|=
name|ENXIO
expr_stmt|;
return|return;
block|}
name|vainfo
operator|.
name|va_is_open
operator|=
literal|1
expr_stmt|;
comment|/* NOW it's open! */
name|VAADDR
operator|->
name|vawcount
operator|=
literal|0
expr_stmt|;
comment|/* Clear residual errors */
name|vainfo
operator|.
name|va_wcount
operator|=
literal|0
expr_stmt|;
comment|/* No DMA to do now. */
name|vainfo
operator|.
name|va_state
operator|=
literal|0
expr_stmt|;
name|VAADDR
operator|->
name|vacsrlo
operator|=
name|IENABLE
expr_stmt|;
comment|/* Enable interrupts. */
name|vatimo
argument_list|()
expr_stmt|;
name|vacmd
argument_list|(
name|VPRINT
argument_list|)
expr_stmt|;
comment|/* Start in print mode. */
if|if
condition|(
name|u
operator|.
name|u_error
condition|)
name|vaclose
argument_list|()
expr_stmt|;
block|}
end_block

begin_expr_stmt
name|vastrategy
argument_list|(
name|bp
argument_list|)
specifier|register
expr|struct
name|buf
operator|*
name|bp
expr_stmt|;
end_expr_stmt

begin_block
block|{
specifier|register
name|int
name|e
decl_stmt|;
operator|(
name|void
operator|)
name|spl4
argument_list|()
expr_stmt|;
while|while
condition|(
name|vainfo
operator|.
name|va_busy
condition|)
comment|/* Wait till not busy. */
name|sleep
argument_list|(
operator|(
name|caddr_t
operator|)
operator|&
name|vainfo
argument_list|,
name|VAPRI
argument_list|)
expr_stmt|;
name|vainfo
operator|.
name|va_busy
operator|=
literal|1
expr_stmt|;
comment|/* Grab it. */
operator|(
name|void
operator|)
name|spl0
argument_list|()
expr_stmt|;
name|va_ubinfo
operator|=
name|ubasetup
argument_list|(
name|bp
argument_list|,
name|vabdp
argument_list|)
expr_stmt|;
comment|/* Set up uba mapper. */
name|vainfo
operator|.
name|va_bufp
operator|=
name|va_ubinfo
operator|&
literal|0x3ffff
expr_stmt|;
operator|(
name|void
operator|)
name|spl4
argument_list|()
expr_stmt|;
if|if
condition|(
name|e
operator|=
name|vaerror
argument_list|(
name|DONE
argument_list|)
condition|)
goto|goto
name|brkout
goto|;
name|vainfo
operator|.
name|va_wcount
operator|=
operator|-
operator|(
name|bp
operator|->
name|b_bcount
operator|/
literal|2
operator|)
expr_stmt|;
comment|/* va uses a word count,  		   so user had better supply an even number of bytes. */
name|vastart
argument_list|()
expr_stmt|;
name|e
operator|=
name|vaerror
argument_list|(
name|DONE
argument_list|)
expr_stmt|;
comment|/* Wait for DMA to complete. */
name|vainfo
operator|.
name|va_wcount
operator|=
literal|0
expr_stmt|;
comment|/* Reset state info. */
name|vainfo
operator|.
name|va_bufp
operator|=
literal|0
expr_stmt|;
comment|/* After printing a line of characters, VPRINTPLOT mode essentially 	   reverts to VPLOT mode, plotting things until a new mode is set. 	   This change is indicated by sending a VAAUTOSTEP command to 	   the va.  We also change va_state to reflect this effective 	   mode change. 	 */
if|if
condition|(
name|vainfo
operator|.
name|va_state
operator|&
name|VPRINTPLOT
condition|)
block|{
name|vainfo
operator|.
name|va_state
operator|=
operator|(
name|vainfo
operator|.
name|va_state
operator|&
operator|~
name|VPRINTPLOT
operator|)
operator||
name|VPLOT
expr_stmt|;
name|VAADDR
operator|->
name|vacsrhi
operator|=
name|VAAUTOSTEP
expr_stmt|;
name|e
operator||=
name|vaerror
argument_list|(
name|DONE
argument_list|)
expr_stmt|;
block|}
operator|(
name|void
operator|)
name|spl0
argument_list|()
expr_stmt|;
name|brkout
label|:
name|ubafree
argument_list|(
name|va_ubinfo
argument_list|)
operator|,
name|va_ubinfo
operator|=
literal|0
expr_stmt|;
name|vainfo
operator|.
name|va_busy
operator|=
literal|0
expr_stmt|;
name|iodone
argument_list|(
name|bp
argument_list|)
expr_stmt|;
if|if
condition|(
name|e
condition|)
name|u
operator|.
name|u_error
operator|=
name|EIO
expr_stmt|;
name|wakeup
argument_list|(
operator|(
name|caddr_t
operator|)
operator|&
name|vainfo
argument_list|)
expr_stmt|;
block|}
end_block

begin_decl_stmt
name|int
name|vablock
init|=
literal|16384
decl_stmt|;
end_decl_stmt

begin_function
name|unsigned
name|minvaph
parameter_list|(
name|bp
parameter_list|)
name|struct
name|buf
modifier|*
name|bp
decl_stmt|;
block|{
if|if
condition|(
name|bp
operator|->
name|b_bcount
operator|>
name|vablock
condition|)
name|bp
operator|->
name|b_bcount
operator|=
name|vablock
expr_stmt|;
block|}
end_function

begin_comment
comment|/*ARGSUSED*/
end_comment

begin_macro
name|vawrite
argument_list|(
argument|dev
argument_list|)
end_macro

begin_block
block|{
name|physio
argument_list|(
name|vastrategy
argument_list|,
operator|&
name|rvabuf
argument_list|,
name|dev
argument_list|,
name|B_WRITE
argument_list|,
name|minvaph
argument_list|)
expr_stmt|;
block|}
end_block

begin_comment
comment|/*  * Vaerror waits until bit or ERROR gets set, then returns non-zero if  * if it was ERROR that was set.  */
end_comment

begin_macro
name|vaerror
argument_list|(
argument|bit
argument_list|)
end_macro

begin_block
block|{
specifier|register
name|int
name|e
decl_stmt|;
while|while
condition|(
operator|(
name|e
operator|=
name|VAADDR
operator|->
name|vacsr
operator|.
name|vacsrword
operator|&
operator|(
name|bit
operator||
name|ERROR
operator|)
operator|)
operator|==
literal|0
condition|)
name|sleep
argument_list|(
operator|(
name|caddr_t
operator|)
operator|&
name|vainfo
argument_list|,
name|VAPRI
argument_list|)
expr_stmt|;
return|return
operator|(
name|e
operator|&
name|ERROR
operator|)
return|;
block|}
end_block

begin_comment
comment|/* vastart starts up the DMA by setting the buffer pointer and the word count. */
end_comment

begin_macro
name|vastart
argument_list|()
end_macro

begin_block
block|{
if|if
condition|(
name|vainfo
operator|.
name|va_wcount
condition|)
block|{
name|VAADDR
operator|->
name|vabufaddr
operator|=
name|vainfo
operator|.
name|va_bufp
expr_stmt|;
name|VAADDR
operator|->
name|vawcount
operator|=
name|vainfo
operator|.
name|va_wcount
expr_stmt|;
return|return;
block|}
block|}
end_block

begin_comment
comment|/*ARGSUSED*/
end_comment

begin_expr_stmt
name|vaioctl
argument_list|(
name|dev
argument_list|,
name|cmd
argument_list|,
name|addr
argument_list|,
name|flag
argument_list|)
specifier|register
name|caddr_t
name|addr
expr_stmt|;
end_expr_stmt

begin_block
block|{
specifier|register
name|int
name|vcmd
decl_stmt|;
switch|switch
condition|(
name|cmd
condition|)
block|{
case|case
name|VGETSTATE
case|:
operator|(
name|void
operator|)
name|suword
argument_list|(
name|addr
argument_list|,
name|vainfo
operator|.
name|va_state
argument_list|)
expr_stmt|;
return|return;
case|case
name|VSETSTATE
case|:
name|vcmd
operator|=
name|fuword
argument_list|(
name|addr
argument_list|)
expr_stmt|;
if|if
condition|(
name|vcmd
operator|==
operator|-
literal|1
condition|)
block|{
name|u
operator|.
name|u_error
operator|=
name|EFAULT
expr_stmt|;
return|return;
block|}
name|vacmd
argument_list|(
name|vcmd
argument_list|)
expr_stmt|;
return|return;
default|default:
name|u
operator|.
name|u_error
operator|=
name|ENOTTY
expr_stmt|;
comment|/* Not a legal ioctl cmd. */
return|return;
block|}
block|}
end_block

begin_comment
comment|/* vacmd sends a command code to the va, and waits for it to complete.    If an error occurs, u.u_error is set to EIO.    vacmd also updates vainfo.va_state.  */
end_comment

begin_macro
name|vacmd
argument_list|(
argument|vcmd
argument_list|)
end_macro

begin_block
block|{
operator|(
name|void
operator|)
name|spl4
argument_list|()
expr_stmt|;
operator|(
name|void
operator|)
name|vaerror
argument_list|(
name|DONE
argument_list|)
expr_stmt|;
comment|/* Wait for va to be ready. */
switch|switch
condition|(
name|vcmd
condition|)
block|{
case|case
name|VPLOT
case|:
comment|/* Must turn on plot AND autostep modes. */
name|VAADDR
operator|->
name|vacsrhi
operator|=
name|VAPLOT
expr_stmt|;
if|if
condition|(
name|vaerror
argument_list|(
name|DONE
argument_list|)
condition|)
name|u
operator|.
name|u_error
operator|=
name|EIO
expr_stmt|;
name|VAADDR
operator|->
name|vacsrhi
operator|=
name|VAAUTOSTEP
expr_stmt|;
break|break;
case|case
name|VPRINT
case|:
name|VAADDR
operator|->
name|vacsrhi
operator|=
name|VAPRINT
expr_stmt|;
break|break;
case|case
name|VPRINTPLOT
case|:
name|VAADDR
operator|->
name|vacsrhi
operator|=
name|VAPRINTPLOT
expr_stmt|;
break|break;
block|}
name|vainfo
operator|.
name|va_state
operator|=
operator|(
name|vainfo
operator|.
name|va_state
operator|&
operator|~
operator|(
name|VPLOT
operator||
name|VPRINT
operator||
name|VPRINTPLOT
operator|)
operator|)
operator||
name|vcmd
expr_stmt|;
if|if
condition|(
name|vaerror
argument_list|(
name|DONE
argument_list|)
condition|)
comment|/* Wait for command to complete. */
name|u
operator|.
name|u_error
operator|=
name|EIO
expr_stmt|;
operator|(
name|void
operator|)
name|spl0
argument_list|()
expr_stmt|;
block|}
end_block

begin_macro
name|vatimo
argument_list|()
end_macro

begin_block
block|{
if|if
condition|(
name|vainfo
operator|.
name|va_is_open
condition|)
name|timeout
argument_list|(
name|vatimo
argument_list|,
operator|(
name|caddr_t
operator|)
literal|0
argument_list|,
name|HZ
operator|/
literal|10
argument_list|)
expr_stmt|;
name|vaintr
argument_list|(
literal|0
argument_list|)
expr_stmt|;
block|}
end_block

begin_comment
comment|/*ARGSUSED*/
end_comment

begin_macro
name|vaintr
argument_list|(
argument|dev
argument_list|)
end_macro

begin_block
block|{
name|wakeup
argument_list|(
operator|(
name|caddr_t
operator|)
operator|&
name|vainfo
argument_list|)
expr_stmt|;
block|}
end_block

begin_macro
name|vaclose
argument_list|()
end_macro

begin_block
block|{
name|vainfo
operator|.
name|va_is_open
operator|=
literal|0
expr_stmt|;
name|vainfo
operator|.
name|va_busy
operator|=
literal|0
expr_stmt|;
name|vainfo
operator|.
name|va_state
operator|=
literal|0
expr_stmt|;
name|vainfo
operator|.
name|va_wcount
operator|=
literal|0
expr_stmt|;
name|vainfo
operator|.
name|va_bufp
operator|=
literal|0
expr_stmt|;
name|VAADDR
operator|->
name|vacsrlo
operator|=
literal|0
expr_stmt|;
block|}
end_block

begin_endif
endif|#
directive|endif
end_endif

end_unit

