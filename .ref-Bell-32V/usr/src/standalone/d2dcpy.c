begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
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
value|(rptrk*rpsec)
end_define

begin_comment
comment|/*  no. sectors/cyl  */
end_comment

begin_define
define|#
directive|define
name|MAXSEC
value|(rpcyl*rptrk*rpsec)
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
name|M_st
value|2
end_define

begin_comment
comment|/*  offset for MBA status reg */
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
name|M0_map
value|(M0+0x800)
end_define

begin_comment
comment|/* start MBA 0 map reg's */
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
name|M0_bc
value|(M0+0x10)
end_define

begin_comment
comment|/*  MBA 0 byte count reg */
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

begin_define
define|#
directive|define
name|M_DTC
value|0x2000
end_define

begin_comment
comment|/* Data Transfer Complete */
end_comment

begin_comment
comment|/*		*/
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
name|RP_er1
value|2
end_define

begin_comment
comment|/*  RP06 error reg 1 */
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
name|RP_typ
value|06
end_define

begin_comment
comment|/*  disk type reg */
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

begin_define
define|#
directive|define
name|RP_Epos
value|016
end_define

begin_comment
comment|/*  RP ECC position reg */
end_comment

begin_define
define|#
directive|define
name|RP_Epat
value|017
end_define

begin_comment
comment|/*  RP ECC pattern reg */
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

begin_define
define|#
directive|define
name|RP_DCK
value|0x8000
end_define

begin_comment
comment|/*  Data Check Error in ERR1 reg */
end_comment

begin_define
define|#
directive|define
name|RP_ECH
value|0x40
end_define

begin_comment
comment|/*  ECC hard error */
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
name|BLKSIZ
value|512
end_define

begin_define
define|#
directive|define
name|NB
value|128
end_define

begin_comment
comment|/*  max. byte transfer = 64K bytes */
end_comment

begin_define
define|#
directive|define
name|BUFSIZ
value|(NB*BLKSIZ)
end_define

begin_define
define|#
directive|define
name|MAXUNI
value|1
end_define

begin_define
define|#
directive|define
name|MAXERR
value|10
end_define

begin_comment
comment|/*  max. no. i/o errors allowed */
end_comment

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

begin_define
define|#
directive|define
name|CDEL
value|0x23
end_define

begin_define
define|#
directive|define
name|LDEL
value|0x40
end_define

begin_comment
comment|/*		*/
end_comment

begin_define
define|#
directive|define
name|RM3CYL
value|823
end_define

begin_comment
comment|/* RM03 */
end_comment

begin_define
define|#
directive|define
name|RM3TRK
value|5
end_define

begin_define
define|#
directive|define
name|RM3SEC
value|32
end_define

begin_define
define|#
directive|define
name|RP6typ
value|022
end_define

begin_define
define|#
directive|define
name|RM3typ
value|024
end_define

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
name|dinoff
decl_stmt|,
name|douoff
decl_stmt|,
name|dblks
decl_stmt|,
name|count
decl_stmt|,
name|ecount
decl_stmt|,
name|daterr
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|bufptr
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|unsigned
name|int
name|page
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
modifier|*
name|RPin
decl_stmt|,
modifier|*
name|RPout
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|rpsec
decl_stmt|,
name|rptrk
decl_stmt|,
name|rpcyl
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
name|input
index|[
literal|132
index|]
decl_stmt|;
end_decl_stmt

begin_function
name|main
parameter_list|()
block|{
comment|/* *  Stand-alone program to copy rp06/RM03 disk to rp06/RM03 disk, same or *  different drives. User specifies input and output disk, no. *  of 512-byte blocks, and disk offsets. */
specifier|register
name|int
name|i
decl_stmt|,
name|error
decl_stmt|;
name|putlin
argument_list|(
literal|"d2dcpy : Disk-to-Disk Copy"
argument_list|)
expr_stmt|;
name|putnl
argument_list|()
expr_stmt|;
name|d1u
label|:
name|putstr
argument_list|(
literal|"input disk unit : "
argument_list|)
expr_stmt|;
name|getcon
argument_list|(
name|input
argument_list|)
expr_stmt|;
name|i
operator|=
name|a2l
argument_list|(
name|input
argument_list|)
expr_stmt|;
if|if
condition|(
name|i
operator|<
literal|0
condition|)
goto|goto
name|fini
goto|;
if|if
condition|(
name|i
operator|>
name|MAXUNI
condition|)
goto|goto
name|d1u
goto|;
name|RPin
operator|=
name|RP
operator|+
operator|(
name|i
operator|*
literal|32
operator|*
literal|4
operator|)
expr_stmt|;
name|dof1
label|:
name|putstr
argument_list|(
literal|"offset : "
argument_list|)
expr_stmt|;
name|getcon
argument_list|(
name|input
argument_list|)
expr_stmt|;
name|dinoff
operator|=
name|a2l
argument_list|(
name|input
argument_list|)
expr_stmt|;
name|d2u
label|:
name|putstr
argument_list|(
literal|"output disk unit : "
argument_list|)
expr_stmt|;
name|getcon
argument_list|(
name|input
argument_list|)
expr_stmt|;
name|i
operator|=
name|a2l
argument_list|(
name|input
argument_list|)
expr_stmt|;
if|if
condition|(
operator|(
name|i
operator|>
name|MAXUNI
operator|)
operator|||
operator|(
name|i
operator|<
literal|0
operator|)
condition|)
goto|goto
name|d2u
goto|;
name|RPout
operator|=
name|RP
operator|+
operator|(
name|i
operator|*
literal|32
operator|*
literal|4
operator|)
expr_stmt|;
name|dof2
label|:
name|putstr
argument_list|(
literal|"offset : "
argument_list|)
expr_stmt|;
name|getcon
argument_list|(
name|input
argument_list|)
expr_stmt|;
name|douoff
operator|=
name|a2l
argument_list|(
name|input
argument_list|)
expr_stmt|;
name|gknt
label|:
name|putstr
argument_list|(
literal|"no. 512-byte blocks : "
argument_list|)
expr_stmt|;
name|getcon
argument_list|(
name|input
argument_list|)
expr_stmt|;
name|count
operator|=
name|a2l
argument_list|(
name|input
argument_list|)
expr_stmt|;
name|error
operator|=
literal|0
expr_stmt|;
if|if
condition|(
name|init
argument_list|()
condition|)
block|{
name|putlin
argument_list|(
literal|"init error"
argument_list|)
expr_stmt|;
goto|goto
name|d1u
goto|;
block|}
if|if
condition|(
operator|(
name|dinoff
operator|<
literal|0
operator|)
operator|||
operator|(
name|dinoff
operator|>
name|MAXSEC
operator|-
literal|1
operator|)
condition|)
goto|goto
name|dof1
goto|;
if|if
condition|(
operator|(
name|douoff
operator|<
literal|0
operator|)
operator|||
operator|(
name|douoff
operator|>
name|MAXSEC
operator|-
literal|1
operator|)
condition|)
goto|goto
name|dof2
goto|;
if|if
condition|(
name|count
operator|<
literal|0
condition|)
goto|goto
name|gknt
goto|;
if|if
condition|(
name|count
operator|==
literal|0
condition|)
name|count
operator|=
name|MAXSEC
expr_stmt|;
name|ecount
operator|=
name|daterr
operator|=
literal|0
expr_stmt|;
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
name|dioerr
label|:
name|putlin
argument_list|(
literal|"disc i/o error"
argument_list|)
expr_stmt|;
name|error
operator|++
expr_stmt|;
continue|continue ;
block|}
if|if
condition|(
name|dwrite
argument_list|()
condition|)
goto|goto
name|dioerr
goto|;
name|count
operator|-=
name|dblks
expr_stmt|;
comment|/*  dec no. blocks read */
block|}
name|fini
label|:
name|putstr
argument_list|(
literal|"# Data Check Errors : "
argument_list|)
expr_stmt|;
name|l2x
argument_list|(
name|daterr
argument_list|,
name|input
argument_list|)
expr_stmt|;
name|putlin
argument_list|(
name|input
argument_list|)
expr_stmt|;
name|putstr
argument_list|(
literal|"# Other errors : "
argument_list|)
expr_stmt|;
name|l2x
argument_list|(
name|ecount
argument_list|,
name|input
argument_list|)
expr_stmt|;
name|putlin
argument_list|(
name|input
argument_list|)
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
name|char
modifier|*
name|ocs
decl_stmt|;
name|ocs
operator|=
name|cs
expr_stmt|;
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
name|c
operator|==
name|CDEL
condition|)
block|{
operator|--
name|cs
expr_stmt|;
goto|goto
name|inloop
goto|;
block|}
if|if
condition|(
name|c
operator|==
name|LDEL
condition|)
block|{
name|putc
argument_list|(
name|NL
argument_list|)
expr_stmt|;
name|putc
argument_list|(
literal|0
argument_list|)
expr_stmt|;
name|putc
argument_list|(
name|CR
argument_list|)
expr_stmt|;
name|cs
operator|=
name|ocs
expr_stmt|;
goto|goto
name|inloop
goto|;
block|}
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
name|init
argument_list|()
end_macro

begin_block
block|{
comment|/* *  Initialization. *  Initialize MBA 0 for disk i/o. *  Set up MBA 0 map registers to map a max. *    transfer of 'BUFSIZ' bytes. */
specifier|register
name|int
modifier|*
name|mp0
decl_stmt|,
name|i
decl_stmt|;
specifier|extern
name|char
modifier|*
name|end
decl_stmt|;
name|M0_cr
operator|->
name|reg
operator|=
name|MBAinit
expr_stmt|;
name|dblks
operator|=
name|BUFSIZ
operator|/
name|BLKSIZ
expr_stmt|;
comment|/* no. of disk blocks / input buffer */
if|if
condition|(
operator|(
operator|*
operator|(
name|RPin
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
literal|"input unit not online"
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
name|RPin
operator|+
name|RP_cr
operator|)
operator|=
name|RP_RIP
operator||
name|RP_GO
expr_stmt|;
comment|/* preset */
operator|*
operator|(
name|RPin
operator|+
name|RP_off
operator|)
operator|=
name|RP_FMT
expr_stmt|;
comment|/* set format bit */
if|if
condition|(
name|RPin
operator|!=
name|RPout
condition|)
block|{
if|if
condition|(
operator|(
operator|*
operator|(
name|RPout
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
literal|"output unit not online"
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
name|RPout
operator|+
name|RP_cr
operator|)
operator|=
name|RP_RIP
operator||
name|RP_GO
expr_stmt|;
operator|*
operator|(
name|RPout
operator|+
name|RP_off
operator|)
operator|=
name|RP_FMT
expr_stmt|;
block|}
name|i
operator|=
operator|*
operator|(
name|RPout
operator|+
name|RP_typ
operator|)
operator|&
literal|0777
expr_stmt|;
comment|/* get disk type */
if|if
condition|(
name|i
operator|==
name|RP6typ
condition|)
block|{
comment|/* RP06 */
name|rpsec
operator|=
name|RP6SEC
expr_stmt|;
name|rpcyl
operator|=
name|RP6CYL
expr_stmt|;
name|rptrk
operator|=
name|RP6TRK
expr_stmt|;
block|}
else|else
block|{
if|if
condition|(
name|i
operator|==
name|RM3typ
condition|)
block|{
name|rpsec
operator|=
name|RM3SEC
expr_stmt|;
name|rpcyl
operator|=
name|RM3CYL
expr_stmt|;
name|rptrk
operator|=
name|RM3TRK
expr_stmt|;
block|}
else|else
return|return
operator|(
operator|-
literal|1
operator|)
return|;
block|}
name|bufptr
operator|=
call|(
name|int
call|)
argument_list|(
operator|&
name|end
operator|+
literal|511
argument_list|)
operator|&
literal|017777777000
expr_stmt|;
name|page
operator|=
call|(
name|int
call|)
argument_list|(
operator|(
name|int
operator|)
name|bufptr
operator|>>
literal|9
argument_list|)
operator|&
literal|017777777
expr_stmt|;
name|mp0
operator|=
name|M0_map
expr_stmt|;
comment|/* phys addr of MBA 0 map reg base */
name|i
operator|=
name|NB
expr_stmt|;
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
literal|0x80000000
operator||
name|page
operator|++
expr_stmt|;
comment|/* map entry */
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
name|dread
argument_list|()
end_macro

begin_block
block|{
comment|/* *  Function to read 'BUFSIZ' bytes (512 multiple) from disc *  to buffer . */
specifier|register
name|int
name|i
decl_stmt|,
name|j
decl_stmt|;
operator|*
operator|(
name|RPin
operator|+
name|RP_cyl
operator|)
operator|=
name|dinoff
operator|/
name|RP6ST
expr_stmt|;
comment|/* cylinder no. */
name|i
operator|=
name|dinoff
operator|%
name|RP6ST
expr_stmt|;
name|j
operator|=
operator|(
name|i
operator|/
name|rpsec
operator|)
operator|<<
literal|8
expr_stmt|;
comment|/* track */
operator|*
operator|(
name|RPin
operator|+
name|RP_stk
operator|)
operator|=
name|j
operator||
operator|(
name|i
operator|%
name|rpsec
operator|)
expr_stmt|;
comment|/* sector : track */
name|dinoff
operator|+=
name|dblks
expr_stmt|;
comment|/*  point to next disc sector */
name|M0_bc
operator|->
name|reg
operator|=
operator|(
name|count
operator|<
name|dblks
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
name|BUFSIZ
operator|)
operator|)
expr_stmt|;
comment|/* byte count */
name|M0_var
operator|->
name|reg
operator|=
literal|0
expr_stmt|;
comment|/* virt addr reg = map no. + byte off */
name|rbit
label|:
operator|*
operator|(
name|RPin
operator|+
name|RP_cr
operator|)
operator|=
name|RP_DC
operator||
name|RP_GO
expr_stmt|;
comment|/* drive clear */
name|dwait
argument_list|(
name|RPin
argument_list|)
expr_stmt|;
operator|*
operator|(
name|RPin
operator|+
name|RP_cr
operator|)
operator|=
name|RP_RD
operator||
name|RP_GO
expr_stmt|;
comment|/* read */
name|dwait
argument_list|(
name|RPin
argument_list|)
expr_stmt|;
comment|/* wait for i/o to finish */
if|if
condition|(
name|i
operator|=
name|mbaerr
argument_list|(
name|M0
argument_list|)
condition|)
block|{
comment|/* don't abort on MBA errors - 'mbaerr()' has cleared 	MBA status reg */
block|}
if|if
condition|(
name|i
operator|=
name|derror
argument_list|(
name|RPin
argument_list|)
condition|)
block|{
comment|/*  error  */
name|putlin
argument_list|(
literal|"- - - - - -"
argument_list|)
expr_stmt|;
name|putstr
argument_list|(
literal|"read error"
argument_list|)
expr_stmt|;
name|stmes
argument_list|(
name|i
argument_list|)
expr_stmt|;
name|dadmes
argument_list|(
name|RPin
argument_list|)
expr_stmt|;
if|if
condition|(
name|i
operator|&
name|RP_DCK
condition|)
block|{
comment|/* Data Check Error */
name|daterr
operator|++
expr_stmt|;
name|putlin
argument_list|(
literal|"Data Check"
argument_list|)
expr_stmt|;
if|if
condition|(
name|i
operator|&
name|RP_ECH
condition|)
block|{
comment|/*  ECC Hard Error */
name|putlin
argument_list|(
literal|"ECC non-recov"
argument_list|)
expr_stmt|;
name|ecount
operator|++
expr_stmt|;
block|}
else|else
block|{
comment|/*  ECC Recoverable */
name|ECCrcv
argument_list|(
name|RPin
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
name|M0_bc
operator|->
name|reg
condition|)
block|{
comment|/* more i-o to finish ? */
name|j
operator|=
operator|(
operator|*
operator|(
name|RPin
operator|+
name|RP_stk
operator|)
operator|)
expr_stmt|;
name|i
operator|=
operator|(
name|j
operator|>>
literal|8
operator|)
operator|&
literal|0x1f
expr_stmt|;
name|j
operator|=
name|j
operator|&
literal|0x1f
expr_stmt|;
if|if
condition|(
name|j
operator|>=
name|rpsec
condition|)
comment|/*sector */
name|j
operator|=
literal|0
expr_stmt|;
if|if
condition|(
name|i
operator|>=
name|rptrk
condition|)
comment|/* track */
name|i
operator|=
literal|0
expr_stmt|;
operator|*
operator|(
name|RPin
operator|+
name|RP_stk
operator|)
operator|=
operator|(
name|i
operator|<<
literal|8
operator|)
operator||
name|j
expr_stmt|;
goto|goto
name|rbit
goto|;
comment|/* staus reg cleared by 'Drive Clear' */
block|}
else|else
block|{
operator|*
operator|(
name|RPin
operator|+
name|RP_cr
operator|)
operator|=
name|RP_DC
operator||
name|RP_GO
expr_stmt|;
name|mbaerr
argument_list|(
name|M0
argument_list|)
expr_stmt|;
block|}
block|}
else|else
block|{
comment|/* non-Data Check error */
name|ecount
operator|++
expr_stmt|;
block|}
if|if
condition|(
name|ecount
operator|>
name|MAXERR
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
comment|/* normal return */
block|}
end_block

begin_comment
comment|/*		*/
end_comment

begin_macro
name|dwrite
argument_list|()
end_macro

begin_block
block|{
comment|/* *  Function to write 'BUFSIZ' bytes (512 multiple) to disc *  from buffer . */
specifier|register
name|int
name|i
decl_stmt|,
name|j
decl_stmt|;
operator|*
operator|(
name|RPout
operator|+
name|RP_cr
operator|)
operator|=
name|RP_DC
operator||
name|RP_GO
expr_stmt|;
operator|*
operator|(
name|RPout
operator|+
name|RP_cyl
operator|)
operator|=
name|douoff
operator|/
name|RP6ST
expr_stmt|;
name|i
operator|=
name|douoff
operator|%
name|RP6ST
expr_stmt|;
name|j
operator|=
operator|(
name|i
operator|/
name|rpsec
operator|)
operator|<<
literal|8
expr_stmt|;
comment|/* track */
operator|*
operator|(
name|RPout
operator|+
name|RP_stk
operator|)
operator|=
name|j
operator||
operator|(
name|i
operator|%
name|rpsec
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
name|dblks
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
name|BUFSIZ
operator|)
operator|)
expr_stmt|;
comment|/* byte count */
name|M0_var
operator|->
name|reg
operator|=
literal|0
expr_stmt|;
comment|/* virt addr reg = map no. + byte off */
operator|*
operator|(
name|RPout
operator|+
name|RP_cr
operator|)
operator|=
name|RP_WR
operator||
name|RP_GO
expr_stmt|;
comment|/* write */
name|douoff
operator|+=
name|dblks
expr_stmt|;
comment|/*  point to next disc sector */
name|dwait
argument_list|(
name|RPout
argument_list|)
expr_stmt|;
comment|/* wait for i/o to finish */
if|if
condition|(
name|i
operator|=
name|mbaerr
argument_list|(
name|M0
argument_list|)
condition|)
block|{
return|return
operator|(
operator|-
literal|1
operator|)
return|;
block|}
if|if
condition|(
name|i
operator|=
name|derror
argument_list|(
name|RPout
argument_list|)
condition|)
block|{
name|putstr
argument_list|(
literal|"write error"
argument_list|)
expr_stmt|;
name|stmes
argument_list|(
name|i
argument_list|)
expr_stmt|;
name|dadmes
argument_list|(
name|RPout
argument_list|)
expr_stmt|;
if|if
condition|(
operator|++
name|ecount
operator|>
name|MAXERR
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
comment|/* normal return */
block|}
end_block

begin_comment
comment|/*		*/
end_comment

begin_expr_stmt
name|dwait
argument_list|(
name|dptr
argument_list|)
specifier|register
name|int
operator|*
name|dptr
expr_stmt|;
end_expr_stmt

begin_block
block|{
comment|/* * Function to wait MBA 0 RP06 disc unit to be ready. */
while|while
condition|(
operator|(
operator|*
operator|(
name|dptr
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

begin_expr_stmt
name|derror
argument_list|(
name|dptr
argument_list|)
specifier|register
name|int
operator|*
name|dptr
expr_stmt|;
end_expr_stmt

begin_block
block|{
comment|/* *  Function to check for MBA 0 RP06 error. */
if|if
condition|(
operator|*
operator|(
name|dptr
operator|+
name|RP_sr
operator|)
operator|&
name|RP_ERR
condition|)
return|return
operator|(
operator|*
operator|(
name|dptr
operator|+
name|RP_er1
operator|)
operator|&
literal|0177777
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

begin_macro
name|stmes
argument_list|(
argument|code
argument_list|)
end_macro

begin_decl_stmt
name|int
name|code
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|putstr
argument_list|(
literal|" : err reg : "
argument_list|)
expr_stmt|;
name|RPE_print
argument_list|(
name|code
argument_list|)
expr_stmt|;
block|}
end_block

begin_comment
comment|/*		*/
end_comment

begin_expr_stmt
name|dadmes
argument_list|(
name|dptr
argument_list|)
specifier|register
name|int
operator|*
name|dptr
expr_stmt|;
end_expr_stmt

begin_block
block|{
specifier|register
name|char
modifier|*
name|mesp
decl_stmt|;
specifier|register
name|int
name|i
decl_stmt|;
name|mesp
operator|=
literal|" cyl     trk     sec    "
expr_stmt|;
name|i
operator|=
name|l2x
argument_list|(
operator|*
operator|(
name|dptr
operator|+
name|RP_cyl
operator|)
operator|&
literal|01777
argument_list|,
operator|&
name|mesp
index|[
literal|5
index|]
argument_list|)
expr_stmt|;
name|blnkit
argument_list|(
operator|&
name|mesp
index|[
literal|5
operator|+
name|i
index|]
argument_list|,
literal|4
operator|-
name|i
argument_list|)
expr_stmt|;
name|i
operator|=
name|l2x
argument_list|(
operator|(
operator|*
operator|(
name|dptr
operator|+
name|RP_stk
operator|)
operator|>>
literal|8
operator|)
operator|&
literal|037
argument_list|,
operator|&
name|mesp
index|[
literal|13
index|]
argument_list|)
expr_stmt|;
name|blnkit
argument_list|(
operator|&
name|mesp
index|[
literal|13
operator|+
name|i
index|]
argument_list|,
literal|3
operator|-
name|i
argument_list|)
expr_stmt|;
name|i
operator|=
name|l2x
argument_list|(
operator|*
operator|(
name|dptr
operator|+
name|RP_stk
operator|)
operator|&
literal|037
argument_list|,
operator|&
name|mesp
index|[
literal|21
index|]
argument_list|)
expr_stmt|;
name|blnkit
argument_list|(
operator|&
name|mesp
index|[
literal|21
operator|+
name|i
index|]
argument_list|,
literal|3
operator|-
name|i
argument_list|)
expr_stmt|;
name|putlin
argument_list|(
name|mesp
argument_list|)
expr_stmt|;
block|}
end_block

begin_comment
comment|/*		*/
end_comment

begin_expr_stmt
name|blnkit
argument_list|(
name|mp
argument_list|,
name|cc
argument_list|)
specifier|register
name|char
operator|*
name|mp
expr_stmt|;
end_expr_stmt

begin_decl_stmt
specifier|register
name|int
name|cc
decl_stmt|;
end_decl_stmt

begin_block
block|{
while|while
condition|(
name|cc
operator|--
condition|)
operator|(
operator|*
name|mp
operator|++
operator|)
operator|=
literal|' '
expr_stmt|;
block|}
end_block

begin_comment
comment|/*		*/
end_comment

begin_expr_stmt
name|mbaerr
argument_list|(
name|mba
argument_list|)
specifier|register
name|int
operator|*
name|mba
expr_stmt|;
end_expr_stmt

begin_block
block|{
specifier|register
name|int
name|i
decl_stmt|;
if|if
condition|(
operator|(
name|i
operator|=
operator|(
operator|*
operator|(
name|mba
operator|+
name|M_st
operator|)
operator|)
operator|)
operator|!=
name|M_DTC
condition|)
block|{
name|putlin
argument_list|(
literal|"- - - - - -"
argument_list|)
expr_stmt|;
name|putstr
argument_list|(
literal|"MBA error : status reg = "
argument_list|)
expr_stmt|;
name|MBAS_print
argument_list|(
name|i
argument_list|)
expr_stmt|;
operator|*
operator|(
name|mba
operator|+
name|M_st
operator|)
operator|=
operator|(
operator|-
literal|1
operator|)
expr_stmt|;
return|return
operator|(
name|i
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

begin_expr_stmt
name|l2x
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
decl_stmt|,
name|j
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
literal|16
expr_stmt|;
comment|/*  quotient& base 16 */
name|j
operator|=
name|val
operator|%
literal|16
expr_stmt|;
operator|(
operator|*
name|tp
operator|++
operator|)
operator|=
name|j
operator|+
operator|(
name|j
operator|<
literal|10
condition|?
literal|0x30
else|:
literal|0x57
operator|)
expr_stmt|;
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
name|ECCrcv
argument_list|(
name|dptr
argument_list|)
specifier|register
name|int
operator|*
name|dptr
expr_stmt|;
end_expr_stmt

begin_block
block|{
comment|/* *  Do ECC error recovery on disk whose register set is pointed *  to by 'dptr'. *  'mbaerr()' has cleared MBA status reg. *  With ECC enabled, disk read has stopped after sector with bad *  data. After correction of data, return to 'dread()' which will *  continue read of track if more sectors to do. *  Return 0. */
specifier|register
name|unsigned
name|int
name|pos
decl_stmt|,
name|pat
decl_stmt|;
specifier|register
name|unsigned
name|short
modifier|*
name|wordp
decl_stmt|;
name|unsigned
name|int
name|ll
decl_stmt|;
struct|struct
block|{
name|short
name|wlo
decl_stmt|,
name|whi
decl_stmt|;
block|}
struct|;
name|char
name|tmp
index|[
literal|50
index|]
decl_stmt|;
name|pat
operator|=
operator|(
operator|*
operator|(
name|dptr
operator|+
name|RP_Epat
operator|)
operator|)
operator|&
literal|0xffff
expr_stmt|;
comment|/* ECC pattern reg */
name|pos
operator|=
operator|(
operator|*
operator|(
name|dptr
operator|+
name|RP_Epos
operator|)
operator|)
operator|&
literal|0xffff
expr_stmt|;
comment|/* ECC position reg */
name|putstr
argument_list|(
literal|"pat : "
argument_list|)
expr_stmt|;
name|ul2x
argument_list|(
name|pat
argument_list|,
name|tmp
argument_list|)
expr_stmt|;
name|putlin
argument_list|(
name|tmp
argument_list|)
expr_stmt|;
name|putstr
argument_list|(
literal|"pos : "
argument_list|)
expr_stmt|;
name|ul2x
argument_list|(
name|pos
argument_list|,
name|tmp
argument_list|)
expr_stmt|;
name|putlin
argument_list|(
name|tmp
argument_list|)
expr_stmt|;
name|wordp
operator|=
name|bufptr
expr_stmt|;
comment|/* ptr to buffer */
comment|/* *  'BUFSIZ' bytes are read on each read into buffer pointed to *  by 'bufptr'. MBA byte count reg has neg. no. of bytes remaining *  in read if this read error was not in the last sector to be *  read. */
comment|/* calculate buffer location of faulty data */
name|wordp
operator|=
operator|(
name|char
operator|*
operator|)
name|wordp
operator|+
operator|(
name|BUFSIZ
operator|+
operator|(
operator|(
name|M0_bc
operator|->
name|reg
operator|)
operator|>>
literal|16
operator|)
operator|-
name|BLKSIZ
operator|)
expr_stmt|;
comment|/* sector in buffer */
name|wordp
operator|=
name|wordp
operator|+
operator|(
operator|(
name|pos
operator|-
literal|1
operator|)
operator|>>
literal|4
operator|)
expr_stmt|;
comment|/* word within sector */
comment|/* burst pattern may be across word boundary */
name|ll
operator|=
operator|(
operator|*
name|wordp
operator|)
operator|+
operator|(
operator|(
operator|*
operator|(
name|wordp
operator|+
literal|1
operator|)
operator|)
operator|<<
literal|16
operator|)
expr_stmt|;
name|putstr
argument_list|(
literal|"bad data  : "
argument_list|)
expr_stmt|;
name|ul2x
argument_list|(
name|ll
argument_list|,
name|tmp
argument_list|)
expr_stmt|;
name|putlin
argument_list|(
name|tmp
argument_list|)
expr_stmt|;
name|pat
operator|=
name|pat
operator|<<
operator|(
operator|(
name|pos
operator|%
literal|16
operator|)
operator|-
literal|1
operator|)
expr_stmt|;
name|ll
operator|=
name|ll
operator|^
name|pat
expr_stmt|;
comment|/* correction */
name|putstr
argument_list|(
literal|"good data : "
argument_list|)
expr_stmt|;
name|ul2x
argument_list|(
name|ll
argument_list|,
name|tmp
argument_list|)
expr_stmt|;
name|putlin
argument_list|(
name|tmp
argument_list|)
expr_stmt|;
comment|/* put good data back in buffer */
operator|*
name|wordp
operator|=
name|ll
operator|.
name|wlo
expr_stmt|;
operator|*
operator|(
name|wordp
operator|+
literal|1
operator|)
operator|=
name|ll
operator|.
name|whi
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

begin_expr_stmt
name|ul2x
argument_list|(
name|val
argument_list|,
name|rptr
argument_list|)
specifier|register
name|unsigned
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
name|unsigned
name|int
name|i
decl_stmt|,
name|j
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
decl_stmt|;
name|unsigned
name|int
name|udiv
argument_list|()
decl_stmt|,
name|urem
argument_list|()
decl_stmt|;
name|knt
operator|=
literal|0
expr_stmt|;
name|tp
operator|=
name|tmp
expr_stmt|;
name|loop
label|:
name|knt
operator|++
expr_stmt|;
comment|/* use unsigned integer divide& remainder routines */
name|i
operator|=
name|udiv
argument_list|(
name|val
argument_list|,
literal|16
argument_list|)
expr_stmt|;
comment|/*  quotient& base 16 */
name|j
operator|=
name|urem
argument_list|(
name|val
argument_list|,
literal|16
argument_list|)
expr_stmt|;
operator|(
operator|*
name|tp
operator|++
operator|)
operator|=
name|j
operator|+
operator|(
name|j
operator|<
literal|10
condition|?
literal|0x30
else|:
literal|0x57
operator|)
expr_stmt|;
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

end_unit

