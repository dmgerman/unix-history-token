begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_define
define|#
directive|define
name|MIN
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|(a<b?a:b)
end_define

begin_define
define|#
directive|define
name|RP6CYL
value|815
end_define

begin_comment
comment|/*  no. RP06 cylinders/pack */
end_comment

begin_define
define|#
directive|define
name|RP6TRK
value|19
end_define

begin_comment
comment|/*  no. tracks/cyl  */
end_comment

begin_define
define|#
directive|define
name|RP6SEC
value|22
end_define

begin_comment
comment|/*  no. sectors/track  */
end_comment

begin_define
define|#
directive|define
name|RP6ST
value|(RP6TRK*RP6SEC)
end_define

begin_comment
comment|/*  no. sectors/cyl  */
end_comment

begin_define
define|#
directive|define
name|MAXSEC
value|(RP6CYL*RP6TRK*RP6SEC)
end_define

begin_comment
comment|/*  sectors/pack  */
end_comment

begin_define
define|#
directive|define
name|M0
value|0x20010000
end_define

begin_comment
comment|/* phys addr MBA 0  */
end_comment

begin_define
define|#
directive|define
name|M1
value|0x20012000
end_define

begin_comment
comment|/*  phys addr MBA 1  */
end_comment

begin_define
define|#
directive|define
name|M0_cr
value|(M0+4)
end_define

begin_comment
comment|/*  MBA 0 control reg addr */
end_comment

begin_define
define|#
directive|define
name|M1_cr
value|(M1+4)
end_define

begin_comment
comment|/*  MBA 1 control reg addr  */
end_comment

begin_define
define|#
directive|define
name|M0_map
value|(M0+0x800)
end_define

begin_comment
comment|/* start MBA 0 map reg's */
end_comment

begin_define
define|#
directive|define
name|M1_map
value|(M1+0x800)
end_define

begin_comment
comment|/* start MBA 1 map reg's  */
end_comment

begin_define
define|#
directive|define
name|M0_var
value|(M0+0xc)
end_define

begin_comment
comment|/* MBA 0 virt addr reg */
end_comment

begin_define
define|#
directive|define
name|M1_var
value|(M1+0xc)
end_define

begin_comment
comment|/*  MBA 1 virt addr reg  */
end_comment

begin_define
define|#
directive|define
name|M0_bc
value|(M0+0x10)
end_define

begin_comment
comment|/*  MBA 0 byte count reg */
end_comment

begin_define
define|#
directive|define
name|M1_bc
value|(M1+0x10)
end_define

begin_comment
comment|/*  MBA 1 byte count reg  */
end_comment

begin_define
define|#
directive|define
name|MBAinit
value|01
end_define

begin_comment
comment|/*  MBA init bit */
end_comment

begin_comment
comment|/*		*/
end_comment

begin_define
define|#
directive|define
name|TM
value|(M1+0x400)
end_define

begin_comment
comment|/*  base for TM02/TE16 reg's */
end_comment

begin_define
define|#
directive|define
name|RP
value|(M0+0x400)
end_define

begin_comment
comment|/*  base for RP06 reg's, drive 0  */
end_comment

begin_comment
comment|/*		*/
end_comment

begin_define
define|#
directive|define
name|TM_tc
value|(TM+0x24)
end_define

begin_comment
comment|/*  TM02 tape control reg */
end_comment

begin_define
define|#
directive|define
name|TM_cs1
value|(TM+0)
end_define

begin_comment
comment|/*  TM02 control 1 reg */
end_comment

begin_define
define|#
directive|define
name|TM_ds
value|(TM+4)
end_define

begin_comment
comment|/*  status reg */
end_comment

begin_define
define|#
directive|define
name|TM_fc
value|(TM+0x14)
end_define

begin_comment
comment|/*  TM02 frame count reg */
end_comment

begin_comment
comment|/*		*/
end_comment

begin_define
define|#
directive|define
name|RP_cr
value|0
end_define

begin_comment
comment|/* RP06 control reg offset, longword */
end_comment

begin_define
define|#
directive|define
name|RP_sr
value|1
end_define

begin_comment
comment|/*  RP06 status reg offset */
end_comment

begin_define
define|#
directive|define
name|RP_stk
value|5
end_define

begin_comment
comment|/*  RP06 sector/track reg offset */
end_comment

begin_define
define|#
directive|define
name|RP_off
value|011
end_define

begin_comment
comment|/*  RP offset reg */
end_comment

begin_define
define|#
directive|define
name|RP_cyl
value|10
end_define

begin_comment
comment|/*  RP06 cylinder reg offset */
end_comment

begin_comment
comment|/*		*/
end_comment

begin_define
define|#
directive|define
name|RP_GO
value|1
end_define

begin_comment
comment|/*  go bit */
end_comment

begin_define
define|#
directive|define
name|RP_RD
value|070
end_define

begin_comment
comment|/* RP06 read function code */
end_comment

begin_define
define|#
directive|define
name|RP_WR
value|060
end_define

begin_comment
comment|/*  RP06 write function code */
end_comment

begin_define
define|#
directive|define
name|RP_DC
value|010
end_define

begin_comment
comment|/*  drive clear function code */
end_comment

begin_define
define|#
directive|define
name|RP_FMT
value|0x1000
end_define

begin_comment
comment|/*  format bit in RP offset reg */
end_comment

begin_define
define|#
directive|define
name|RP_RIP
value|020
end_define

begin_comment
comment|/*  Read-in Preset function code */
end_comment

begin_define
define|#
directive|define
name|RP_MOL
value|0x1000
end_define

begin_comment
comment|/*  medium online bit in status */
end_comment

begin_define
define|#
directive|define
name|RP_DRY
value|0200
end_define

begin_comment
comment|/*  drive ready, status reg */
end_comment

begin_define
define|#
directive|define
name|RP_ERR
value|040000
end_define

begin_comment
comment|/* composite error, status reg */
end_comment

begin_comment
comment|/*		*/
end_comment

begin_define
define|#
directive|define
name|TM_GO
value|1
end_define

begin_comment
comment|/*  TM02 go bit */
end_comment

begin_define
define|#
directive|define
name|TM_DCLR
value|010
end_define

begin_comment
comment|/*  TM02 drive clear function code */
end_comment

begin_define
define|#
directive|define
name|TM_SFWD
value|030
end_define

begin_comment
comment|/*  space forward function code */
end_comment

begin_define
define|#
directive|define
name|TM_WRTF
value|060
end_define

begin_comment
comment|/* write forward function code */
end_comment

begin_define
define|#
directive|define
name|TM_REDF
value|070
end_define

begin_comment
comment|/*  read forward function code */
end_comment

begin_define
define|#
directive|define
name|TM_RWND
value|06
end_define

begin_comment
comment|/*  TM02 Rewind  */
end_comment

begin_define
define|#
directive|define
name|TM_WEOF
value|026
end_define

begin_comment
comment|/* write end of file function */
end_comment

begin_define
define|#
directive|define
name|TCHAR
value|01300
end_define

begin_comment
comment|/*  TM02/TE16 drive 0 ,800 BPI,PDP11,etc. */
end_comment

begin_define
define|#
directive|define
name|TM_DRDY
value|0200
end_define

begin_comment
comment|/*  TM02/drive ready,status reg */
end_comment

begin_define
define|#
directive|define
name|TM_ERR
value|040000
end_define

begin_comment
comment|/*  TM02 composite error, status reg */
end_comment

begin_comment
comment|/*		*/
end_comment

begin_define
define|#
directive|define
name|RXCS
value|32
end_define

begin_comment
comment|/*  receiver control/staus */
end_comment

begin_define
define|#
directive|define
name|RXDB
value|33
end_define

begin_comment
comment|/*  receiver data */
end_comment

begin_define
define|#
directive|define
name|TXCS
value|34
end_define

begin_comment
comment|/*  transmitter control/status */
end_comment

begin_define
define|#
directive|define
name|TXDB
value|35
end_define

begin_comment
comment|/*  transmitter data */
end_comment

begin_define
define|#
directive|define
name|RXCS_DONE
value|0x80
end_define

begin_comment
comment|/*  receiver done */
end_comment

begin_define
define|#
directive|define
name|TXCS_RDY
value|0x80
end_define

begin_comment
comment|/*  transmitter ready */
end_comment

begin_comment
comment|/*		*/
end_comment

begin_define
define|#
directive|define
name|BUFSIZ
value|5120
end_define

begin_comment
comment|/*  max tape block size = input buffer size */
end_comment

begin_define
define|#
directive|define
name|MAXUNI
value|1
end_define

begin_define
define|#
directive|define
name|NL
value|012
end_define

begin_define
define|#
directive|define
name|CR
value|015
end_define

begin_comment
comment|/*		*/
end_comment

begin_decl_stmt
name|char
name|input
index|[
name|BUFSIZ
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  tape input buffer */
end_comment

begin_struct
struct|struct
block|{
name|int
name|reg
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
name|int
name|blksiz
decl_stmt|,
name|tapoff
decl_stmt|,
name|dskoff
decl_stmt|,
name|wsize
decl_stmt|,
name|dblks
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|count
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|unsigned
name|int
name|ins
decl_stmt|,
name|outs
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|unsigned
name|short
name|nread
decl_stmt|,
name|bytoff
decl_stmt|,
name|error
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
modifier|*
name|RPptr
decl_stmt|,
name|dunit
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* ptr to start of RP reg's for desired drive */
end_comment

begin_function
name|main
parameter_list|()
block|{
comment|/* *  Stand-alone program to copy TM02/TE16 drive 0 mag tape to *  RP06 disc. *  User specifies tape block size (must be multiple of 512), tape *  offset (tape blocks), disc unit no., disc offset (512-byte *  blocks) and count of tape blocks to be transferred. */
name|int
name|getcon
argument_list|()
decl_stmt|,
name|putstr
argument_list|()
decl_stmt|,
name|a2l
argument_list|()
decl_stmt|,
name|l2a
argument_list|()
decl_stmt|;
name|putlin
argument_list|(
literal|"d2tcpy : Disk-to-Tape Copy"
argument_list|)
expr_stmt|;
name|putnl
argument_list|()
expr_stmt|;
name|bsize
label|:
if|if
condition|(
name|putstr
argument_list|(
literal|"tape block size : "
argument_list|)
condition|)
goto|goto
name|fini
goto|;
if|if
condition|(
name|getcon
argument_list|(
name|input
argument_list|)
condition|)
goto|goto
name|fini
goto|;
name|putnl
argument_list|()
expr_stmt|;
name|blksiz
operator|=
name|a2l
argument_list|(
name|input
argument_list|)
expr_stmt|;
if|if
condition|(
operator|(
name|blksiz
operator|<=
literal|0
operator|)
operator|||
operator|(
name|blksiz
operator|>
name|BUFSIZ
operator|)
condition|)
goto|goto
name|bsize
goto|;
if|if
condition|(
name|blksiz
operator|%
literal|512
condition|)
goto|goto
name|bsize
goto|;
comment|/*  block size must be 512 multiple */
name|M0_cr
operator|->
name|reg
operator|=
name|MBAinit
expr_stmt|;
comment|/* MBA 0 init */
name|M1_cr
operator|->
name|reg
operator|=
name|MBAinit
expr_stmt|;
comment|/* MBA 1 init */
name|TM_tc
operator|->
name|reg
operator|=
name|TCHAR
expr_stmt|;
comment|/* TE16,drive 0 ,800 BPI, PDP11, odd parity, 			abort on error */
name|TM_cs1
operator|->
name|reg
operator|=
name|TM_DCLR
operator||
name|TM_GO
expr_stmt|;
comment|/* clear tape drive 0 */
if|if
condition|(
name|terror
argument_list|()
condition|)
goto|goto
name|taperr
goto|;
name|toff
label|:
if|if
condition|(
name|putstr
argument_list|(
literal|"tape offset : "
argument_list|)
condition|)
goto|goto
name|fini
goto|;
if|if
condition|(
name|getcon
argument_list|(
name|input
argument_list|)
condition|)
goto|goto
name|fini
goto|;
name|putnl
argument_list|()
expr_stmt|;
name|tapoff
operator|=
name|a2l
argument_list|(
name|input
argument_list|)
expr_stmt|;
if|if
condition|(
name|tapoff
operator|<
literal|0
condition|)
goto|goto
name|toff
goto|;
if|if
condition|(
name|taprew
argument_list|()
condition|)
goto|goto
name|taperr
goto|;
if|if
condition|(
name|tapspc
argument_list|(
name|tapoff
argument_list|)
condition|)
goto|goto
name|taperr
goto|;
name|dun
label|:
if|if
condition|(
name|putstr
argument_list|(
literal|"disk unit : "
argument_list|)
condition|)
goto|goto
name|fini
goto|;
if|if
condition|(
name|getcon
argument_list|(
name|input
argument_list|)
condition|)
goto|goto
name|fini
goto|;
name|putnl
argument_list|()
expr_stmt|;
name|dunit
operator|=
name|a2l
argument_list|(
name|input
argument_list|)
expr_stmt|;
if|if
condition|(
operator|(
name|dunit
operator|>
name|MAXUNI
operator|)
operator|||
operator|(
name|dunit
operator|<
literal|0
operator|)
condition|)
goto|goto
name|dun
goto|;
name|doff
label|:
if|if
condition|(
name|putstr
argument_list|(
literal|"disc offset : "
argument_list|)
condition|)
goto|goto
name|fini
goto|;
if|if
condition|(
name|getcon
argument_list|(
name|input
argument_list|)
condition|)
goto|goto
name|fini
goto|;
name|putnl
argument_list|()
expr_stmt|;
name|dskoff
operator|=
name|a2l
argument_list|(
name|input
argument_list|)
expr_stmt|;
if|if
condition|(
operator|(
name|dskoff
operator|<
literal|0
operator|)
operator|||
operator|(
name|dskoff
operator|>
name|MAXSEC
operator|-
literal|1
operator|)
condition|)
goto|goto
name|doff
goto|;
name|gknt
label|:
if|if
condition|(
name|putstr
argument_list|(
literal|"no. of input blocks : "
argument_list|)
condition|)
goto|goto
name|fini
goto|;
if|if
condition|(
name|getcon
argument_list|(
name|input
argument_list|)
condition|)
goto|goto
name|fini
goto|;
name|putnl
argument_list|()
expr_stmt|;
name|count
operator|=
name|a2l
argument_list|(
name|input
argument_list|)
expr_stmt|;
if|if
condition|(
name|count
operator|<
literal|0
condition|)
goto|goto
name|gknt
goto|;
name|error
operator|=
literal|0
expr_stmt|;
if|if
condition|(
name|init
argument_list|()
condition|)
goto|goto
name|bsize
goto|;
while|while
condition|(
operator|(
name|error
operator|==
literal|0
operator|)
operator|&&
operator|(
name|count
operator|>
literal|0
operator|)
condition|)
block|{
if|if
condition|(
name|dread
argument_list|()
condition|)
block|{
name|putlin
argument_list|(
literal|"disc i/o error"
argument_list|)
expr_stmt|;
goto|goto
name|ioerr
goto|;
block|}
name|ins
operator|++
expr_stmt|;
comment|/*  count of disk blocks input */
if|if
condition|(
name|twrite
argument_list|()
condition|)
block|{
name|taperr
label|:
name|putlin
argument_list|(
literal|"tape i/o error"
argument_list|)
expr_stmt|;
name|ioerr
label|:
name|error
operator|++
expr_stmt|;
continue|continue ;
block|}
name|outs
operator|=
operator|+
name|dblks
expr_stmt|;
comment|/*  count of tape blocks output */
name|count
operator|-=
name|nread
expr_stmt|;
comment|/*  dec no. blocks read */
block|}
name|fini
label|:
name|TM_cs1
operator|->
name|reg
operator|=
name|TM_WEOF
operator||
name|TM_GO
expr_stmt|;
name|twait
argument_list|()
expr_stmt|;
name|TM_cs1
operator|->
name|reg
operator|=
name|TM_RWND
operator||
name|TM_GO
expr_stmt|;
name|twait
argument_list|()
expr_stmt|;
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_function

begin_comment
comment|/*		*/
end_comment

begin_expr_stmt
name|putstr
argument_list|(
name|csp
argument_list|)
specifier|register
name|char
operator|*
name|csp
expr_stmt|;
end_expr_stmt

begin_block
block|{
if|if
condition|(
name|putcon
argument_list|(
name|csp
argument_list|)
condition|)
return|return
operator|(
operator|-
literal|1
operator|)
return|;
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_block

begin_comment
comment|/*		*/
end_comment

begin_expr_stmt
name|putlin
argument_list|(
name|sptr
argument_list|)
specifier|register
name|char
operator|*
name|sptr
expr_stmt|;
end_expr_stmt

begin_block
block|{
if|if
condition|(
name|putcon
argument_list|(
name|sptr
argument_list|)
condition|)
return|return
operator|(
operator|-
literal|1
operator|)
return|;
if|if
condition|(
name|putnl
argument_list|()
condition|)
return|return
operator|(
operator|-
literal|1
operator|)
return|;
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_block

begin_comment
comment|/*		*/
end_comment

begin_macro
name|putnl
argument_list|()
end_macro

begin_block
block|{
if|if
condition|(
name|putcon
argument_list|(
literal|"\r\n"
argument_list|)
condition|)
return|return
operator|(
operator|-
literal|1
operator|)
return|;
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_block

begin_comment
comment|/*		*/
end_comment

begin_expr_stmt
name|putcon
argument_list|(
name|csp
argument_list|)
specifier|register
name|char
operator|*
name|csp
expr_stmt|;
end_expr_stmt

begin_block
block|{
comment|/* *  Function to output null-terminated string pointed to  *  by 'csp' to the VAX LSI terminal. */
specifier|register
name|c
expr_stmt|;
name|c
operator|=
literal|0
expr_stmt|;
while|while
condition|(
name|c
operator|=
operator|(
operator|*
name|csp
operator|++
operator|)
condition|)
name|putc
argument_list|(
name|c
argument_list|)
expr_stmt|;
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_block

begin_comment
comment|/*		*/
end_comment

begin_macro
name|putc
argument_list|(
argument|c
argument_list|)
end_macro

begin_block
block|{
comment|/*  wait for LSI printer to be ready */
while|while
condition|(
operator|(
name|mfpr
argument_list|(
name|TXCS
argument_list|)
operator|&
name|TXCS_RDY
operator|)
operator|==
literal|0
condition|)
empty_stmt|;
comment|/*  output character */
name|mtpr
argument_list|(
name|TXDB
argument_list|,
name|c
operator|&
literal|0177
argument_list|)
expr_stmt|;
block|}
end_block

begin_comment
comment|/*		*/
end_comment

begin_expr_stmt
name|getcon
argument_list|(
name|cs
argument_list|)
specifier|register
name|char
operator|*
name|cs
expr_stmt|;
end_expr_stmt

begin_block
block|{
comment|/* *  Function to return char's from VAX LSI keyboard to *  char array 'cs' - input stops when CR or LF received - *  null char appended to end of input */
specifier|register
name|int
name|c
decl_stmt|,
name|c2
decl_stmt|;
name|int
name|getc
parameter_list|()
function_decl|;
name|inloop
label|:
name|c
operator|=
name|getc
argument_list|()
expr_stmt|;
comment|/* get 1 char from terminal */
name|putc
argument_list|(
name|c
argument_list|)
expr_stmt|;
comment|/*  echo char */
if|if
condition|(
operator|(
name|c
operator|==
name|NL
operator|)
operator|||
operator|(
name|c
operator|==
name|CR
operator|)
condition|)
block|{
name|putc
argument_list|(
name|CR
argument_list|)
expr_stmt|;
name|putc
argument_list|(
literal|0
argument_list|)
expr_stmt|;
name|putc
argument_list|(
name|NL
argument_list|)
expr_stmt|;
operator|(
operator|*
name|cs
operator|++
operator|)
operator|=
literal|'\0'
expr_stmt|;
return|return
operator|(
literal|0
operator|)
return|;
block|}
else|else
block|{
operator|(
operator|*
name|cs
operator|++
operator|)
operator|=
name|c
expr_stmt|;
goto|goto
name|inloop
goto|;
block|}
block|}
end_block

begin_comment
comment|/*		*/
end_comment

begin_macro
name|getc
argument_list|()
end_macro

begin_block
block|{
comment|/* *  Return char from VAX LSI terminal char buffer */
name|int
name|mfpr
parameter_list|()
function_decl|;
comment|/*  Wait for receiver done (user entered char) */
while|while
condition|(
operator|(
name|mfpr
argument_list|(
name|RXCS
argument_list|)
operator|&
name|RXCS_DONE
operator|)
operator|==
literal|0
condition|)
empty_stmt|;
return|return
operator|(
name|mfpr
argument_list|(
name|RXDB
argument_list|)
operator|&
literal|0177
operator|)
return|;
comment|/* return char from receiver buffer */
block|}
end_block

begin_comment
comment|/*		*/
end_comment

begin_macro
name|mtpr
argument_list|(
argument|regno
argument_list|,
argument|value
argument_list|)
end_macro

begin_block
block|{
asm|asm("	mtpr	8(ap),4(ap)") ;
block|}
end_block

begin_comment
comment|/*		*/
end_comment

begin_macro
name|mfpr
argument_list|(
argument|regno
argument_list|)
end_macro

begin_block
block|{
asm|asm("	mfpr	4(ap),r0") ;
block|}
end_block

begin_comment
comment|/*		*/
end_comment

begin_expr_stmt
name|a2l
argument_list|(
name|as
argument_list|)
specifier|register
name|char
operator|*
name|as
expr_stmt|;
end_expr_stmt

begin_block
block|{
comment|/* *  Convert null-terminated ascii string to binary *  and return value. *  1st char in string : *	0 -> octal *	x -> hex *	else decimal */
specifier|register
name|value
operator|,
name|base
operator|,
name|sign
operator|,
name|digit
expr_stmt|;
name|digit
operator|=
name|value
operator|=
name|sign
operator|=
literal|0
expr_stmt|;
name|base
operator|=
literal|10
expr_stmt|;
comment|/* default base */
name|aloop
label|:
if|if
condition|(
operator|(
name|digit
operator|=
operator|(
operator|*
name|as
operator|++
operator|)
operator|)
operator|==
literal|0
condition|)
return|return
operator|(
name|value
operator|)
return|;
comment|/* null */
if|if
condition|(
name|digit
operator|==
literal|'-'
condition|)
block|{
name|sign
operator|++
expr_stmt|;
goto|goto
name|aloop
goto|;
block|}
if|if
condition|(
name|digit
operator|==
literal|'0'
condition|)
name|base
operator|=
literal|8
expr_stmt|;
comment|/* octal base  */
else|else
block|{
if|if
condition|(
name|digit
operator|==
literal|'x'
condition|)
name|base
operator|=
literal|16
expr_stmt|;
comment|/* hex base */
else|else
name|value
operator|=
operator|(
name|digit
operator|-
literal|060
operator|)
expr_stmt|;
comment|/* 060 = '0' */
block|}
while|while
condition|(
name|digit
operator|=
operator|(
operator|*
name|as
operator|++
operator|)
condition|)
block|{
if|if
condition|(
name|digit
operator|<
literal|'0'
condition|)
return|return
operator|(
literal|0
operator|)
return|;
switch|switch
condition|(
name|base
condition|)
block|{
case|case
literal|8
case|:
block|{
if|if
condition|(
name|digit
operator|>
literal|'7'
condition|)
return|return
operator|(
literal|0
operator|)
return|;
name|digit
operator|-=
literal|060
expr_stmt|;
break|break ;
block|}
case|case
literal|10
case|:
block|{
if|if
condition|(
name|digit
operator|>
literal|'9'
condition|)
return|return
operator|(
literal|0
operator|)
return|;
name|digit
operator|-=
literal|060
expr_stmt|;
break|break ;
block|}
case|case
literal|16
case|:
block|{
if|if
condition|(
name|digit
operator|<=
literal|'9'
condition|)
block|{
name|digit
operator|-=
literal|060
expr_stmt|;
break|break ;
block|}
if|if
condition|(
operator|(
name|digit
operator|>=
literal|'A'
operator|)
operator|&&
operator|(
name|digit
operator|<=
literal|'F'
operator|)
condition|)
block|{
name|digit
operator|=
operator|(
name|digit
operator|-
literal|0101
operator|+
literal|10
operator|)
expr_stmt|;
break|break ;
block|}
if|if
condition|(
operator|(
name|digit
operator|>=
literal|'a'
operator|)
operator|&&
operator|(
name|digit
operator|<=
literal|'f'
operator|)
condition|)
block|{
name|digit
operator|=
name|digit
operator|-
literal|0141
operator|+
literal|10
expr_stmt|;
break|break ;
block|}
return|return
operator|(
literal|0
operator|)
return|;
break|break ;
block|}
block|}
name|value
operator|=
operator|(
name|value
operator|*
name|base
operator|)
operator|+
name|digit
expr_stmt|;
block|}
return|return
operator|(
name|sign
condition|?
operator|-
name|value
else|:
name|value
operator|)
return|;
block|}
end_block

begin_comment
comment|/*		*/
end_comment

begin_macro
name|taprew
argument_list|()
end_macro

begin_block
block|{
comment|/* *  Function to rewind TM02/TE16 drive */
name|TM_cs1
operator|->
name|reg
operator|=
name|TM_RWND
operator||
name|TM_GO
expr_stmt|;
name|twait
argument_list|()
expr_stmt|;
if|if
condition|(
name|terror
argument_list|()
condition|)
return|return
operator|(
operator|-
literal|1
operator|)
return|;
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_block

begin_comment
comment|/*		*/
end_comment

begin_macro
name|tapspc
argument_list|(
argument|fblk
argument_list|)
end_macro

begin_block
block|{
comment|/* *  Function to space forward 'fblk' blocks on TM02/TE16 drive */
if|if
condition|(
name|fblk
condition|)
block|{
name|TM_fc
operator|->
name|reg
operator|=
operator|(
operator|-
name|fblk
operator|)
expr_stmt|;
comment|/* no. blocks */
name|TM_cs1
operator|->
name|reg
operator|=
name|TM_SFWD
operator||
name|TM_GO
expr_stmt|;
comment|/* space forward */
name|twait
argument_list|()
expr_stmt|;
if|if
condition|(
name|terror
argument_list|()
condition|)
return|return
operator|(
operator|-
literal|1
operator|)
return|;
block|}
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_block

begin_comment
comment|/*		*/
end_comment

begin_macro
name|twait
argument_list|()
end_macro

begin_block
block|{
comment|/* *  Function to wait until TM02/TE16 is not busy */
while|while
condition|(
operator|(
name|TM_ds
operator|->
name|reg
operator|&
name|TM_DRDY
operator|)
operator|==
literal|0
condition|)
empty_stmt|;
block|}
end_block

begin_comment
comment|/*		*/
end_comment

begin_macro
name|terror
argument_list|()
end_macro

begin_block
block|{
comment|/* *  Function to check for TM02 error *  Return (-1) if error, *	esle return (0). */
if|if
condition|(
name|TM_ds
operator|->
name|reg
operator|&
name|TM_ERR
condition|)
return|return
operator|(
operator|-
literal|1
operator|)
return|;
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_block

begin_comment
comment|/*		*/
end_comment

begin_macro
name|init
argument_list|()
end_macro

begin_block
block|{
comment|/* *  Initialization. *  Initialize MBA 0 (disk) and MBA 1 (tape). *  Initialize TM02/TE16 for drive 0 , 800 BPI, PDP11, etc. *  Set up MBA 0 and MBA 1 map registers to map a max. *    transfer of 'BUFSIZ' bytes. */
specifier|register
name|int
modifier|*
name|mp0
decl_stmt|,
modifier|*
name|mp1
decl_stmt|,
name|i
decl_stmt|,
name|page
decl_stmt|;
name|nread
operator|=
name|BUFSIZ
operator|/
name|blksiz
expr_stmt|;
comment|/* no. of tape reads to fill input buffer */
name|wsize
operator|=
name|nread
operator|*
name|blksiz
expr_stmt|;
comment|/* no. bytes each write to disc */
name|dblks
operator|=
name|wsize
operator|/
literal|512
expr_stmt|;
comment|/* no. of disc blocks on each write */
name|RPptr
operator|=
name|RP
operator|+
operator|(
name|dunit
operator|*
literal|32
operator|*
literal|4
operator|)
expr_stmt|;
comment|/* start of RP reg's for drive */
if|if
condition|(
operator|(
operator|*
operator|(
name|RPptr
operator|+
name|RP_sr
operator|)
operator|&
name|RP_MOL
operator|)
operator|==
literal|0
condition|)
block|{
name|putlin
argument_list|(
literal|"unit not online"
argument_list|)
expr_stmt|;
return|return
operator|(
operator|-
literal|1
operator|)
return|;
block|}
operator|*
operator|(
name|RPptr
operator|+
name|RP_cr
operator|)
operator|=
name|RP_RIP
operator||
name|RP_GO
expr_stmt|;
comment|/* preset :/ *(RPptr+RP_off) = RP_FMT ; /* set format bit */
name|bytoff
operator|=
call|(
name|int
call|)
argument_list|(
operator|&
name|input
index|[
literal|0
index|]
argument_list|)
operator|&
literal|0777
expr_stmt|;
comment|/* byte offset of buffer addr */
name|page
operator|=
operator|(
operator|(
name|int
operator|)
operator|&
name|input
index|[
literal|0
index|]
operator|>>
literal|9
operator|)
operator|&
literal|07777777
expr_stmt|;
comment|/* start page of buffer */
name|mp0
operator|=
name|M0_map
expr_stmt|;
comment|/* phys addr of MBA 0 map reg base */
name|mp1
operator|=
name|M1_map
expr_stmt|;
comment|/*  "	"	"  1	"	" */
name|i
operator|=
operator|(
operator|(
operator|(
name|BUFSIZ
operator|+
literal|511
operator|)
operator|>>
literal|9
operator|)
operator|&
literal|0777
operator|)
operator|+
literal|1
expr_stmt|;
comment|/* max. no. of pages */
while|while
condition|(
name|i
operator|--
condition|)
operator|(
operator|*
name|mp0
operator|++
operator|)
operator|=
operator|(
operator|*
name|mp1
operator|++
operator|)
operator|=
literal|0x80000000
operator||
name|page
operator|++
expr_stmt|;
comment|/* map entry */
block|}
end_block

begin_comment
comment|/*		*/
end_comment

begin_macro
name|twrite
argument_list|()
end_macro

begin_block
block|{
comment|/* *  Function to write TM02/TE16 tape drive, 'blksiz' bytes each *  write, and 'nread' writes. */
specifier|register
name|int
name|i
decl_stmt|,
name|j
decl_stmt|;
name|j
operator|=
literal|0
expr_stmt|;
for|for
control|(
name|i
operator|=
name|MIN
argument_list|(
name|nread
argument_list|,
name|count
argument_list|)
init|;
name|i
condition|;
name|i
operator|--
control|)
block|{
name|M1_var
operator|->
name|reg
operator|=
name|bytoff
operator|+
name|j
operator|++
operator|*
name|blksiz
expr_stmt|;
name|M1_bc
operator|->
name|reg
operator|=
operator|(
operator|-
name|blksiz
operator|)
expr_stmt|;
comment|/* MBA 1 byte count reg */
name|TM_fc
operator|->
name|reg
operator|=
operator|(
operator|-
name|blksiz
operator|)
expr_stmt|;
comment|/* tape frame counter register */
name|TM_cs1
operator|->
name|reg
operator|=
name|TM_WRTF
operator||
name|TM_GO
expr_stmt|;
comment|/* write forward */
name|twait
argument_list|()
expr_stmt|;
comment|/* wait for ready */
if|if
condition|(
name|terror
argument_list|()
condition|)
return|return
operator|(
operator|-
literal|1
operator|)
return|;
comment|/* return on error */
block|}
return|return
operator|(
literal|0
operator|)
return|;
comment|/* normal return */
block|}
end_block

begin_comment
comment|/*		*/
end_comment

begin_macro
name|dread
argument_list|()
end_macro

begin_block
block|{
comment|/* *  Function to read 'wsize' bytes (512 multiple) from disc *  to buffer 'input[]". */
specifier|register
name|int
name|i
decl_stmt|,
name|j
decl_stmt|;
operator|*
operator|(
name|RPptr
operator|+
name|RP_cr
operator|)
operator|=
name|RP_DC
operator||
name|RP_GO
expr_stmt|;
comment|/* drive clear */
operator|*
operator|(
name|RPptr
operator|+
name|RP_cyl
operator|)
operator|=
name|dskoff
operator|/
name|RP6ST
expr_stmt|;
comment|/* cylinder no. */
name|i
operator|=
name|dskoff
operator|%
name|RP6ST
expr_stmt|;
name|j
operator|=
operator|(
name|i
operator|/
name|RP6SEC
operator|)
operator|<<
literal|8
expr_stmt|;
comment|/* track */
operator|*
operator|(
name|RPptr
operator|+
name|RP_stk
operator|)
operator|=
name|j
operator||
operator|(
name|i
operator|%
name|RP6SEC
operator|)
expr_stmt|;
comment|/* sector : track */
name|M0_bc
operator|->
name|reg
operator|=
operator|(
name|count
operator|<
name|nread
condition|?
operator|-
operator|(
name|count
operator|*
literal|512
operator|)
else|:
operator|(
operator|-
name|wsize
operator|)
operator|)
expr_stmt|;
comment|/* byte count */
name|M0_var
operator|->
name|reg
operator|=
name|bytoff
expr_stmt|;
comment|/* virt addr reg = map no. + byte off */
operator|*
operator|(
name|RPptr
operator|+
name|RP_cr
operator|)
operator|=
name|RP_RD
operator||
name|RP_GO
expr_stmt|;
comment|/* write */
name|dskoff
operator|=
operator|+
name|dblks
expr_stmt|;
comment|/*  point to next disc sector */
name|dwait
argument_list|()
expr_stmt|;
comment|/* wait for i/o to finish */
if|if
condition|(
name|derror
argument_list|()
condition|)
return|return
operator|(
operator|-
literal|1
operator|)
return|;
comment|/* error */
return|return
operator|(
literal|0
operator|)
return|;
comment|/* normal return */
block|}
end_block

begin_comment
comment|/*		*/
end_comment

begin_macro
name|dwait
argument_list|()
end_macro

begin_block
block|{
comment|/* * Function to wait MBA 0 RP06 disc unit to be ready. */
while|while
condition|(
operator|(
operator|*
operator|(
name|RPptr
operator|+
name|RP_sr
operator|)
operator|&
name|RP_DRY
operator|)
operator|==
literal|0
condition|)
empty_stmt|;
block|}
end_block

begin_comment
comment|/*		*/
end_comment

begin_macro
name|derror
argument_list|()
end_macro

begin_block
block|{
comment|/* *  Function to check for MBA 0 RP06 error. */
if|if
condition|(
operator|*
operator|(
name|RPptr
operator|+
name|RP_sr
operator|)
operator|&
name|RP_ERR
condition|)
return|return
operator|(
operator|-
literal|1
operator|)
return|;
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_block

begin_comment
comment|/*		*/
end_comment

begin_macro
name|halt
argument_list|()
end_macro

begin_block
block|{
asm|asm("	halt") ;
block|}
end_block

begin_comment
comment|/*		*/
end_comment

begin_expr_stmt
name|l2a
argument_list|(
name|val
argument_list|,
name|rptr
argument_list|)
specifier|register
name|int
name|val
expr_stmt|;
end_expr_stmt

begin_decl_stmt
specifier|register
name|char
modifier|*
name|rptr
decl_stmt|;
end_decl_stmt

begin_block
block|{
specifier|register
name|int
name|i
decl_stmt|;
specifier|register
name|char
modifier|*
name|tp
decl_stmt|;
name|int
name|knt
decl_stmt|;
name|char
name|tmp
index|[
literal|20
index|]
decl_stmt|,
name|sign
decl_stmt|;
name|knt
operator|=
name|sign
operator|=
literal|0
expr_stmt|;
if|if
condition|(
name|val
operator|<
literal|0
condition|)
block|{
name|sign
operator|++
expr_stmt|;
name|val
operator|=
operator|(
operator|-
name|val
operator|)
expr_stmt|;
block|}
name|tp
operator|=
name|tmp
expr_stmt|;
name|loop
label|:
name|knt
operator|++
expr_stmt|;
name|i
operator|=
name|val
operator|/
literal|10
expr_stmt|;
comment|/*  quotient& base 10 */
operator|(
operator|*
name|tp
operator|++
operator|)
operator|=
name|val
operator|%
literal|10
operator|+
literal|'0'
expr_stmt|;
comment|/*  ascii remainder  */
name|val
operator|=
name|i
expr_stmt|;
if|if
condition|(
name|val
operator|==
literal|0
condition|)
block|{
comment|/*  done  dividing  */
if|if
condition|(
name|sign
condition|)
block|{
name|knt
operator|++
expr_stmt|;
operator|(
operator|*
name|tp
operator|++
operator|)
operator|=
literal|'-'
expr_stmt|;
block|}
for|for
control|(
name|i
operator|=
name|knt
init|;
name|i
condition|;
name|i
operator|--
control|)
operator|(
operator|*
name|rptr
operator|++
operator|)
operator|=
name|tmp
index|[
name|i
operator|-
literal|1
index|]
expr_stmt|;
operator|(
operator|*
name|rptr
operator|++
operator|)
operator|=
literal|'\0'
expr_stmt|;
return|return
operator|(
name|knt
operator|)
return|;
block|}
else|else
goto|goto
name|loop
goto|;
block|}
end_block

begin_comment
comment|/*		*/
end_comment

begin_expr_stmt
name|echo
argument_list|(
name|lngword
argument_list|)
specifier|register
name|int
name|lngword
expr_stmt|;
end_expr_stmt

begin_block
block|{
name|char
name|tmp
index|[
literal|30
index|]
decl_stmt|;
name|l2a
argument_list|(
name|lngword
argument_list|,
name|tmp
argument_list|)
expr_stmt|;
name|putlin
argument_list|(
name|tmp
argument_list|)
expr_stmt|;
block|}
end_block

end_unit

