begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
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
file|"../h/proc.h"
end_include

begin_include
include|#
directive|include
file|"../h/uba.h"
end_include

begin_include
include|#
directive|include
file|"../h/buf.h"
end_include

begin_comment
comment|/*		*/
end_comment

begin_define
define|#
directive|define
name|LNKADR
value|(UBA0_DEV+0172410)
end_define

begin_comment
comment|/* DR11-B devive reg's */
end_comment

begin_comment
comment|/* *  UBA0_DEV = 0x80018000 *  LNKADR = 0x80027508 */
end_comment

begin_comment
comment|/*  DA11-B  DR-11B Status& Command reg */
end_comment

begin_define
define|#
directive|define
name|ERR
value|0x8000
end_define

begin_comment
comment|/*  error bit */
end_comment

begin_define
define|#
directive|define
name|NEX
value|0x4000
end_define

begin_comment
comment|/*  non-existent memory */
end_comment

begin_define
define|#
directive|define
name|IIR
value|0x800
end_define

begin_comment
comment|/*  Input Interrupt Request */
end_comment

begin_define
define|#
directive|define
name|ID
value|0x400
end_define

begin_comment
comment|/*  Input direction */
end_comment

begin_define
define|#
directive|define
name|IM
value|0x200
end_define

begin_comment
comment|/*  Input mode */
end_comment

begin_define
define|#
directive|define
name|CYCLE
value|0x100
end_define

begin_comment
comment|/* Cycle */
end_comment

begin_define
define|#
directive|define
name|RDY
value|0x80
end_define

begin_comment
comment|/* Ready */
end_comment

begin_define
define|#
directive|define
name|IE
value|0x40
end_define

begin_comment
comment|/*  Interrupt Enable */
end_comment

begin_define
define|#
directive|define
name|OIR
value|8
end_define

begin_comment
comment|/*  Output interrupt request */
end_comment

begin_define
define|#
directive|define
name|OD
value|4
end_define

begin_comment
comment|/* Output direction */
end_comment

begin_define
define|#
directive|define
name|OM
value|2
end_define

begin_comment
comment|/* output mode */
end_comment

begin_define
define|#
directive|define
name|GO
value|1
end_define

begin_comment
comment|/* Go bit */
end_comment

begin_comment
comment|/*	states	*/
end_comment

begin_define
define|#
directive|define
name|CLOSED
value|0
end_define

begin_comment
comment|/*  closed */
end_comment

begin_define
define|#
directive|define
name|OPEN
value|1
end_define

begin_comment
comment|/* open  */
end_comment

begin_define
define|#
directive|define
name|S1
value|2
end_define

begin_comment
comment|/* write state 1 */
end_comment

begin_define
define|#
directive|define
name|S2
value|4
end_define

begin_comment
comment|/* write state 2 */
end_comment

begin_define
define|#
directive|define
name|R1
value|8
end_define

begin_comment
comment|/* read state 1 */
end_comment

begin_define
define|#
directive|define
name|R2
value|16
end_define

begin_comment
comment|/* read state 2 */
end_comment

begin_define
define|#
directive|define
name|L_NOT
value|128
end_define

begin_comment
comment|/*  send OIR to other end link */
end_comment

begin_define
define|#
directive|define
name|IPEND
value|256
end_define

begin_define
define|#
directive|define
name|PREread
value|512
end_define

begin_comment
comment|/*  'lnkmon' wait */
end_comment

begin_define
define|#
directive|define
name|L_MON
value|1024
end_define

begin_comment
comment|/* 'lnkmon' decr V11opn */
end_comment

begin_define
define|#
directive|define
name|L_WAKE
value|2048
end_define

begin_define
define|#
directive|define
name|BUSY
value|(S1|S2|R1|R2)
end_define

begin_comment
comment|/* i-o in progress for driver */
end_comment

begin_define
define|#
directive|define
name|S_ERR
value|0x8000
end_define

begin_comment
comment|/*		*/
end_comment

begin_define
define|#
directive|define
name|V11PRI
value|0
end_define

begin_define
define|#
directive|define
name|BUFSIZ
value|512
end_define

begin_define
define|#
directive|define
name|VSPEC
value|0100000
end_define

begin_comment
comment|/*		*/
end_comment

begin_struct
struct|struct
name|lnkreg
block|{
name|short
name|drwc
decl_stmt|,
name|drba
decl_stmt|,
name|drst
decl_stmt|,
name|drdb
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
block|{
name|short
name|state
decl_stmt|;
name|struct
name|buf
modifier|*
name|bp
decl_stmt|;
block|}
name|V11tab
struct|;
end_struct

begin_decl_stmt
name|char
name|V11opn
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*		*/
end_comment

begin_macro
name|V11open
argument_list|(
argument|dev
argument_list|,
argument|flag
argument_list|)
end_macro

begin_block
block|{
name|struct
name|buf
modifier|*
name|geteblk
parameter_list|()
function_decl|;
if|if
condition|(
name|V11opn
condition|)
block|{
name|u
operator|.
name|u_error
operator|=
name|EBUSY
expr_stmt|;
return|return;
block|}
name|V11opn
operator|++
expr_stmt|;
if|if
condition|(
name|V11tab
operator|.
name|bp
operator|==
literal|0
condition|)
comment|/* grab system buffer */
name|V11tab
operator|.
name|bp
operator|=
name|geteblk
argument_list|()
expr_stmt|;
comment|/*  VAX call */
operator|(
operator|(
expr|struct
name|lnkreg
operator|*
operator|)
name|LNKADR
operator|)
operator|->
name|drst
operator||=
name|IE
expr_stmt|;
name|V11tab
operator|.
name|state
operator||=
name|OPEN
expr_stmt|;
block|}
end_block

begin_comment
comment|/*		*/
end_comment

begin_macro
name|V11close
argument_list|(
argument|dev
argument_list|,
argument|flag
argument_list|)
end_macro

begin_comment
comment|/* called on last close only ! ! */
end_comment

begin_block
block|{
name|V11opn
operator|=
literal|0
expr_stmt|;
name|V11tab
operator|.
name|state
operator|=
name|CLOSED
expr_stmt|;
operator|(
operator|(
expr|struct
name|lnkreg
operator|*
operator|)
name|LNKADR
operator|)
operator|->
name|drst
operator|=
literal|0
expr_stmt|;
comment|/* IE off */
if|if
condition|(
name|V11tab
operator|.
name|bp
condition|)
name|brelse
argument_list|(
name|V11tab
operator|.
name|bp
argument_list|)
expr_stmt|;
comment|/* release system buffer */
name|V11tab
operator|.
name|bp
operator|=
literal|0
expr_stmt|;
block|}
end_block

begin_comment
comment|/*		*/
end_comment

begin_macro
name|V11write
argument_list|(
argument|dev
argument_list|)
end_macro

begin_block
block|{
specifier|register
name|int
name|i
decl_stmt|,
name|j
decl_stmt|,
name|k
decl_stmt|;
comment|/*  INIT clears OUTPUT DIR bit = transmitter */
name|spl5
argument_list|()
expr_stmt|;
name|V11tab
operator|.
name|state
operator||=
name|S1
expr_stmt|;
comment|/* setup for transmit */
operator|(
operator|(
expr|struct
name|lnkreg
operator|*
operator|)
name|LNKADR
operator|)
operator|->
name|drst
operator|&=
operator|~
operator|(
name|OD
operator|)
expr_stmt|;
comment|/* 0 -> transmitter */
name|spl0
argument_list|()
expr_stmt|;
name|i
operator|=
name|uballoc
argument_list|(
name|V11tab
operator|.
name|bp
operator|->
name|b_un
operator|.
name|b_addr
argument_list|,
name|BUFSIZ
argument_list|,
literal|1
argument_list|)
expr_stmt|;
comment|/* get UBA map entry for 	system buffer and set valid bit& BDP no.& BO bit& load map */
name|j
operator|=
name|i
operator|&
literal|0x3ffff
expr_stmt|;
comment|/* start map no.& byte offset */
comment|/* write loop, until done or error */
while|while
condition|(
operator|(
name|u
operator|.
name|u_count
operator|>
literal|0
operator|)
operator|&&
operator|(
name|u
operator|.
name|u_error
operator|==
literal|0
operator|)
condition|)
block|{
name|iomove
argument_list|(
name|V11tab
operator|.
name|bp
operator|->
name|b_un
operator|.
name|b_addr
argument_list|,
name|min
argument_list|(
name|BUFSIZ
argument_list|,
name|u
operator|.
name|u_count
argument_list|)
argument_list|,
name|B_WRITE
argument_list|)
expr_stmt|;
comment|/* move 		data from user space to system buffer */
operator|(
operator|(
expr|struct
name|lnkreg
operator|*
operator|)
name|LNKADR
operator|)
operator|->
name|drwc
operator|=
operator|(
operator|-
operator|(
name|BUFSIZ
operator|>>
literal|1
operator|)
operator|)
expr_stmt|;
comment|/* word count */
operator|(
operator|(
expr|struct
name|lnkreg
operator|*
operator|)
name|LNKADR
operator|)
operator|->
name|drba
operator|=
name|j
expr_stmt|;
comment|/* map no. (SBI page)& byte offset */
name|spl5
argument_list|()
expr_stmt|;
operator|(
operator|(
expr|struct
name|lnkreg
operator|*
operator|)
name|LNKADR
operator|)
operator|->
name|drst
operator||=
name|GO
expr_stmt|;
comment|/* setup for transfer */
name|sleep
argument_list|(
name|LNKADR
argument_list|,
name|V11PRI
argument_list|)
expr_stmt|;
comment|/* wait for transfer to finish(interrupt) */
name|spl0
argument_list|()
expr_stmt|;
if|if
condition|(
name|V11tab
operator|.
name|state
operator|&
name|S_ERR
condition|)
block|{
name|u
operator|.
name|u_error
operator|=
name|ENXIO
expr_stmt|;
name|V11tab
operator|.
name|state
operator|&=
operator|(
operator|~
name|S_ERR
operator|)
expr_stmt|;
block|}
block|}
name|ubafree
argument_list|(
name|i
argument_list|)
expr_stmt|;
operator|(
operator|(
expr|struct
name|lnkreg
operator|*
operator|)
name|LNKADR
operator|)
operator|->
name|drst
operator|&=
operator|(
operator|~
name|OM
operator|)
expr_stmt|;
name|V11tab
operator|.
name|state
operator|&=
operator|(
operator|~
name|BUSY
operator|)
expr_stmt|;
block|}
end_block

begin_comment
comment|/*		*/
end_comment

begin_macro
name|V11read
argument_list|(
argument|dev
argument_list|)
end_macro

begin_block
block|{
specifier|register
name|i
operator|,
name|j
expr_stmt|;
name|spl5
argument_list|()
expr_stmt|;
name|V11tab
operator|.
name|state
operator||=
name|R1
expr_stmt|;
operator|(
operator|(
expr|struct
name|lnkreg
operator|*
operator|)
name|LNKADR
operator|)
operator|->
name|drst
operator||=
name|OD
expr_stmt|;
comment|/* receiver */
name|spl0
argument_list|()
expr_stmt|;
name|i
operator|=
name|uballoc
argument_list|(
name|V11tab
operator|.
name|bp
operator|->
name|b_un
operator|.
name|b_addr
argument_list|,
name|BUFSIZ
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|j
operator|=
name|i
operator|&
literal|0x3ffff
expr_stmt|;
comment|/* start map no.& byte offset */
while|while
condition|(
operator|(
name|u
operator|.
name|u_count
operator|>
literal|0
operator|)
operator|&&
operator|(
name|u
operator|.
name|u_error
operator|==
literal|0
operator|)
condition|)
block|{
operator|(
operator|(
expr|struct
name|lnkreg
operator|*
operator|)
name|LNKADR
operator|)
operator|->
name|drwc
operator|=
operator|(
operator|-
operator|(
name|BUFSIZ
operator|>>
literal|1
operator|)
operator|)
expr_stmt|;
operator|(
operator|(
expr|struct
name|lnkreg
operator|*
operator|)
name|LNKADR
operator|)
operator|->
name|drba
operator|=
name|j
expr_stmt|;
name|spl5
argument_list|()
expr_stmt|;
operator|(
operator|(
expr|struct
name|lnkreg
operator|*
operator|)
name|LNKADR
operator|)
operator|->
name|drst
operator||=
name|GO
expr_stmt|;
comment|/* wait for i-o to finish */
name|sleep
argument_list|(
name|LNKADR
argument_list|,
name|V11PRI
argument_list|)
expr_stmt|;
name|spl0
argument_list|()
expr_stmt|;
if|if
condition|(
name|V11tab
operator|.
name|state
operator|&
name|S_ERR
condition|)
block|{
name|u
operator|.
name|u_error
operator|=
name|ENXIO
expr_stmt|;
name|V11tab
operator|.
name|state
operator|&=
operator|(
operator|~
name|S_ERR
operator|)
expr_stmt|;
continue|continue ;
block|}
name|iomove
argument_list|(
name|V11tab
operator|.
name|bp
operator|->
name|b_un
operator|.
name|b_addr
argument_list|,
name|min
argument_list|(
name|BUFSIZ
argument_list|,
name|u
operator|.
name|u_count
argument_list|)
argument_list|,
name|B_READ
argument_list|)
expr_stmt|;
block|}
name|ubafree
argument_list|(
name|i
argument_list|)
expr_stmt|;
name|V11tab
operator|.
name|state
operator|&=
operator|(
operator|~
name|BUSY
operator|)
expr_stmt|;
block|}
end_block

begin_comment
comment|/*		*/
end_comment

begin_macro
name|V11int
argument_list|(
argument|dev
argument_list|)
end_macro

begin_block
block|{
specifier|register
name|unsigned
name|short
name|state
decl_stmt|;
specifier|register
name|int
name|i
decl_stmt|;
specifier|extern
name|int
name|V11ioctl
parameter_list|()
function_decl|;
name|state
operator|=
name|V11tab
operator|.
name|state
expr_stmt|;
if|if
condition|(
operator|(
name|i
operator|=
operator|(
operator|(
expr|struct
name|lnkreg
operator|*
operator|)
name|LNKADR
operator|)
operator|->
name|drst
operator|)
operator|&
name|ERR
condition|)
if|if
condition|(
name|state
operator|&
name|BUSY
condition|)
name|V11tab
operator|.
name|state
operator||=
name|S_ERR
expr_stmt|;
if|if
condition|(
name|state
operator|&
name|BUSY
condition|)
block|{
name|wakeup
argument_list|(
name|LNKADR
argument_list|)
expr_stmt|;
return|return ;
block|}
if|if
condition|(
name|i
operator|&
name|IM
condition|)
block|{
if|if
condition|(
name|state
operator|&
name|PREread
condition|)
block|{
name|wakeup
argument_list|(
name|V11ioctl
argument_list|)
expr_stmt|;
return|return;
block|}
if|if
condition|(
operator|(
operator|(
name|state
operator|&
name|BUSY
operator|)
operator|==
literal|0
operator|)
operator|&&
operator|(
name|state
operator|&
name|OPEN
operator|)
condition|)
name|V11tab
operator|.
name|state
operator||=
name|IPEND
expr_stmt|;
return|return;
block|}
block|}
end_block

begin_comment
comment|/*		*/
end_comment

begin_macro
name|V11ioctl
argument_list|(
argument|dev
argument_list|,
argument|cmd
argument_list|,
argument|addr
argument_list|,
argument|flag
argument_list|)
end_macro

begin_decl_stmt
name|dev_t
name|dev
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|caddr_t
name|addr
decl_stmt|;
end_decl_stmt

begin_block
block|{
if|if
condition|(
name|cmd
operator|&
name|VSPEC
condition|)
block|{
switch|switch
condition|(
name|cmd
operator|&
literal|077777
condition|)
block|{
case|case
name|L_WAKE
case|:
block|{
comment|/* debug wakeup */
name|wakeup
argument_list|(
name|LNKADR
argument_list|)
expr_stmt|;
break|break;
block|}
case|case
name|L_NOT
case|:
block|{
comment|/* send OIR to other end of link */
name|spl5
argument_list|()
expr_stmt|;
operator|(
operator|(
expr|struct
name|lnkreg
operator|*
operator|)
name|LNKADR
operator|)
operator|->
name|drst
operator||=
operator|(
name|OIR
operator||
name|OM
operator|)
expr_stmt|;
operator|(
operator|(
expr|struct
name|lnkreg
operator|*
operator|)
name|LNKADR
operator|)
operator|->
name|drst
operator|&=
operator|(
operator|~
name|OIR
operator|)
expr_stmt|;
name|spl0
argument_list|()
expr_stmt|;
break|break;
block|}
case|case
name|L_MON
case|:
block|{
comment|/* 'lnkmon' decr 'V11opn' */
name|V11opn
operator|--
expr_stmt|;
break|break;
block|}
case|case
name|PREread
case|:
block|{
comment|/* 'lnkmon' wait */
name|spl5
argument_list|()
expr_stmt|;
if|if
condition|(
name|V11tab
operator|.
name|state
operator|&
name|IPEND
condition|)
block|{
name|V11tab
operator|.
name|state
operator|&=
operator|(
operator|~
name|IPEND
operator|)
expr_stmt|;
block|}
else|else
block|{
name|V11tab
operator|.
name|state
operator||=
name|PREread
expr_stmt|;
name|sleep
argument_list|(
name|V11ioctl
argument_list|,
name|PZERO
operator|+
literal|1
argument_list|)
expr_stmt|;
name|V11tab
operator|.
name|state
operator|&=
operator|(
operator|~
name|PREread
operator|)
expr_stmt|;
block|}
name|spl0
argument_list|()
expr_stmt|;
break|break;
block|}
block|}
block|}
else|else
block|{
operator|*
operator|(
operator|(
name|short
operator|*
operator|)
name|addr
operator|)
operator|=
name|V11tab
operator|.
name|state
expr_stmt|;
block|}
block|}
end_block

end_unit

